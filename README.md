# Sistema de Agendamento de Consultas em uma Clínica

## Descrição

Este projeto é um sistema para auxiliar no gerenciamento de uma clínica médica, desenvolvido como trabalho da disciplina **AED2**. Ele permite o cadastro de pacientes, o agendamento de consultas e o controle de status (Agendada, Realizada ou Cancelada). O sistema funciona por meio de um menu simples no terminal.

## Tecnologias Utilizadas

- **Linguagem**: C++
- **Armazenamento:** Arquivos de texto (.txt)
- **IDEs recomendadas**: Dev C++, Falcon C++, Code::Blocks

## Funcionalidades

1. **Cadastrar Paciente:**
   - Registra: Nome, CPF, Data de Nascimento, Telefone e Convênio.
   - Validação: Não permite cadastrar pacientes com CPF duplicado.

2. **Agendar Consulta:**
   - Associa uma consulta a um paciente existente (busca pelo CPF).
   - Registra: Data, Hora, Médico e Especialidade.
   - Status padrão: "Agendada".

3. **Listar Consultas por Data:**
   - Exibe todas as consultas marcadas para uma data específica.

4. **Listar Consultas por Paciente (CPF):**
   - Exibe todo o histórico de consultas de um paciente.

5. **Atualizar Status de Consulta:**
   - Permite buscar as consultas de um paciente e alterar o status (Agendada / Realizada / Cancelada).
   - A atualização é feita selecionando o índice da consulta exibido na tela.

6. **Salvar e Sair:**
   - Salva todos os dados nos arquivos 'pacientes.txt' e  'consultas.txt'.

## Limites do Sistema

- Máximo de Pacientes: 100
- Máximo de Consultas: 200

## Instruções de Uso

Ao iniciar o programa, um menu será exibido com as seguintes opções:

1. **Cadastrar Paciente:** Insira os dados pessoais. O CPF é verificado para evitar duplicidades.
2. **Agendar Consulta:** Digite o CPF de um paciente já cadastrado e informe os dados da consulta.
3. **Listar Consultas por Data:** Digite uma data (DD/MM/AAAA) para visualizar todas as consultas daquele dia.
4. **Listar Consultas por Paciente:** Digite o CPF para ver o histórico completo do paciente.
5. **Atualizar Status:** O sistema lista as consultas do paciente e permite alterar o status.
0. **Sair e Salvar:** Encerra o programa e grava todos os dados nos arquivos de texto.

## Estrutura dos Arquivos de Dados

**pacientes.txt** (Cada paciente ocupa 5 linhas):
```
1: Nome
2: CPF
3: Data de Nascimento
4: Telefone
5: Convênio
```

**consultas.txt** (Cada consulta ocupa 6 linhas):
```
1: CPF do Paciente
2: Data
3: Hora
4: Médico
5: Especialidade
6: Status
```
