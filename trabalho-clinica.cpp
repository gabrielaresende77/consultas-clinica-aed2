#include <iostream>
#include <locale.h>
#include <string>
#include <fstream>

using namespace std;

const int MAX_PACIENTES = 100;
const int MAX_CONSULTAS = 200;

struct Paciente {
    string nome;
    string cpf;
    string dataNasc;
    string telefone;
    string convenio;
};

struct Consulta {
    string cpfPaciente;
    string data;
    string hora;
    string medico;
    string especialidade;
    string status;
};

Paciente pacientes[MAX_PACIENTES];
int qtdPacientes = 0;

Consulta consultas[MAX_CONSULTAS];
int qtdConsultas = 0;

void carregarDados();
void salvarDados();
void cadastrarPaciente();
void cadastrarConsulta();
void listarConsultasPorData();
void listarConsultasPorCPF();
void atualizarStatusConsulta();

int main() {
    setlocale(LC_ALL, "Portuguese"); 

    carregarDados(); 

    int opcao;
    do {
        cout << "\n--- SISTEMA DE AGENDAMENTO DE CONSULTAS ---\n";
        cout << "1. Cadastrar Paciente\n";
        cout << "2. Agendar Consulta\n";
        cout << "3. Listar Consultas por Data\n";
        cout << "4. Listar Consultas por Paciente (CPF)\n";
        cout << "5. Atualizar Status de Consulta\n";
        cout << "0. Sair e Salvar\n";
        cout << "Escolha uma opção: ";
        cin >> opcao;
        
        cin.ignore();

        switch (opcao) {
            case 1: cadastrarPaciente(); break;
            case 2: cadastrarConsulta(); break;
            case 3: listarConsultasPorData(); break;
            case 4: listarConsultasPorCPF(); break;
            case 5: atualizarStatusConsulta(); break;
            case 0: 
                salvarDados(); 
                cout << "Dados salvos. Sistema encerrado!\n";
                break;
            default: cout << "Opção inválida!\n";
        }
    } while (opcao != 0);

    return 0;
}

void cadastrarPaciente() {
    if (qtdPacientes >= MAX_PACIENTES) {
        cout << "ERRO! Limite de pacientes atingido.\n";
        return;
    }

    cout << "\n--- Cadastro de Paciente ---\n";
    cout << "Nome Completo: ";
    getline(cin, pacientes[qtdPacientes].nome);
    cout << "CPF: ";
    getline(cin, pacientes[qtdPacientes].cpf);
    
    bool pacienteExiste = false;
    for (int i = 0; i < qtdPacientes; i++) {
        if (pacientes[i].cpf == pacientes[qtdPacientes].cpf) {
            pacienteExiste = true;
            break;
        }
    }

    if (pacienteExiste) {
        cout << "ERRO! Este CPF já consta no sistema.\n";
        return;
    }

    cout << "Data de Nascimento (DD/MM/AAAA): ";
    getline(cin, pacientes[qtdPacientes].dataNasc);
    cout << "Telefone: ";
    getline(cin, pacientes[qtdPacientes].telefone);
    cout << "Convênio: ";
    getline(cin, pacientes[qtdPacientes].convenio);

    qtdPacientes++; 
    cout << "Paciente cadastrado!\n";
}

void cadastrarConsulta() {
    if (qtdConsultas >= MAX_CONSULTAS) {
        cout << "ERRO! Limite de consultas atingido.\n";
        return;
    }

    cout << "\n--- Agendar Consulta ---\n";
    cout << "CPF do Paciente: ";
    getline(cin, consultas[qtdConsultas].cpfPaciente);

    bool pacienteEncontrado = false;
    for (int i = 0; i < qtdPacientes; i++) {
        if (pacientes[i].cpf == consultas[qtdConsultas].cpfPaciente) {
            pacienteEncontrado = true;
            break;
        }
    }

    if (!pacienteEncontrado) {
        cout << "ERRO! Paciente não encontrado.\n";
        return;
    }
    
    cout << "Data (DD/MM/AAAA): ";
    getline(cin, consultas[qtdConsultas].data);
    cout << "Horário: ";
    getline(cin, consultas[qtdConsultas].hora);
    cout << "Nome do Médico: ";
    getline(cin, consultas[qtdConsultas].medico);
    cout << "Especialidade: ";
    getline(cin, consultas[qtdConsultas].especialidade);
    
    consultas[qtdConsultas].status = "Agendada"; 

    qtdConsultas++; 
    cout << "Consulta agendada!\n";
}

void listarConsultasPorData() {
    string buscaData;
    cout << "\nDigite a data para busca (DD/MM/AAAA): ";
    getline(cin, buscaData);

    bool encontrou = false;
    cout << "\n--- Consultas em " << buscaData << " ---\n";
    
    for (int i = 0; i < qtdConsultas; i++) {
        if (consultas[i].data == buscaData) {
            cout << "Hora: " << consultas[i].hora 
                 << " | Médico: " << consultas[i].medico 
                 << " | Especialidade: " << consultas[i].especialidade 
                 << " | CPF do paciente: " << consultas[i].cpfPaciente 
                 << " | Status: " << consultas[i].status << endl;
            encontrou = true;
        }
    }
    if (!encontrou) cout << "Nenhuma consulta encontrada nesta data.\n";
}

void listarConsultasPorCPF() {
    string buscaCPF;
    cout << "\nDigite o CPF do paciente: ";
    getline(cin, buscaCPF);

    bool encontrou = false;
    cout << "\n--- Histórico de Consultas do CPF " << buscaCPF << " ---\n";
    
    for (int i = 0; i < qtdConsultas; i++) {
        if (consultas[i].cpfPaciente == buscaCPF) {
            cout << "Data: " << consultas[i].data 
                 << " | Hora: " << consultas[i].hora 
                 << " | Médico: " << consultas[i].medico 
                 << " | Status: " << consultas[i].status << endl;
            encontrou = true;
        }
    }
    if (!encontrou) cout << "Nenhuma consulta encontrada para este CPF.\n";
}

void atualizarStatusConsulta() {
    string buscaCPF;
    cout << "\nDigite o CPF do paciente: ";
    getline(cin, buscaCPF);

    bool encontrou = false;
    cout << "\n--- Consultas Encontradas ---\n";
    
    for (int i = 0; i < qtdConsultas; i++) {
        if (consultas[i].cpfPaciente == buscaCPF) {
            cout << i << " - Data: " << consultas[i].data 
                 << " | Médico: " << consultas[i].medico 
                 << " | Status Atual: " << consultas[i].status << endl;
            encontrou = true;
        }
    }

    if (!encontrou) {
        cout << "Nenhuma consulta encontrada para este CPF.\n";
        return;
    }

    int indiceEscolhido;
    cout << "Digite o número (índice) da consulta que deseja alterar: ";
    cin >> indiceEscolhido;
    
    cin.ignore();

    if (indiceEscolhido >= 0 && indiceEscolhido < qtdConsultas && consultas[indiceEscolhido].cpfPaciente == buscaCPF) {
        cout << "Novo Status (Agendada / Realizada / Cancelada): ";
        getline(cin, consultas[indiceEscolhido].status);
        cout << "Status atualizado com sucesso!\n";
    } else {
        cout << "Número inválido ou não pertence a este paciente.\n";
    }
}

void salvarDados() {
    ofstream arqPaciente("pacientes.txt");
    if (arqPaciente.is_open()) {
        for (int i = 0; i < qtdPacientes; i++) {
            arqPaciente << pacientes[i].nome << endl;
            arqPaciente << pacientes[i].cpf << endl;
            arqPaciente << pacientes[i].dataNasc << endl;
            arqPaciente << pacientes[i].telefone << endl;
            arqPaciente << pacientes[i].convenio << endl;
        }
        arqPaciente.close();
    } else {
        cout << "Erro ao salvar pacientes.txt\n";
    }

    ofstream arqConsulta("consultas.txt");
    if (arqConsulta.is_open()) {
        for (int i = 0; i < qtdConsultas; i++) {
            arqConsulta << consultas[i].cpfPaciente << endl;
            arqConsulta << consultas[i].data << endl;
            arqConsulta << consultas[i].hora << endl;
            arqConsulta << consultas[i].medico << endl;
            arqConsulta << consultas[i].especialidade << endl;
            arqConsulta << consultas[i].status << endl;
        }
        arqConsulta.close();
    } else {
        cout << "Erro ao salvar consultas.txt\n";
    }
}

void carregarDados() {
    qtdPacientes = 0;
    qtdConsultas = 0;

    ifstream arqPaciente("pacientes.txt");
    if (arqPaciente.is_open()) {
        while (qtdPacientes < MAX_PACIENTES && getline(arqPaciente, pacientes[qtdPacientes].nome)) {
            getline(arqPaciente, pacientes[qtdPacientes].cpf);
            getline(arqPaciente, pacientes[qtdPacientes].dataNasc);
            getline(arqPaciente, pacientes[qtdPacientes].telefone);
            getline(arqPaciente, pacientes[qtdPacientes].convenio);
            qtdPacientes++; 
        }
        arqPaciente.close();
    }

    ifstream arqConsulta("consultas.txt");
    if (arqConsulta.is_open()) {
        while (qtdConsultas < MAX_CONSULTAS && getline(arqConsulta, consultas[qtdConsultas].cpfPaciente)) {
            getline(arqConsulta, consultas[qtdConsultas].data);
            getline(arqConsulta, consultas[qtdConsultas].hora);
            getline(arqConsulta, consultas[qtdConsultas].medico);
            getline(arqConsulta, consultas[qtdConsultas].especialidade);
            getline(arqConsulta, consultas[qtdConsultas].status);
            qtdConsultas++; 
        }
        arqConsulta.close();
    }
}