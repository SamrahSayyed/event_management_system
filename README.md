### Event Management System
This is a console-based C application to manage event records. It dynamically handles multiple events and their attributes, simulates real-world processing using queues.
Core C concepts applied: pointers, structures, linked lists, memory management.

## Project Goals
- Design a flexible system to store event details dynamically.
- Prevent scheduling conflicts via date clash detection.
- Enable attribute-based cost estimation for each event.
- Use a queue to simulate a real-world order of event processing.
- Ensure efficient memory management and program flow.

## Data Structures
# Event Linked List
Stores events with date, base cost, and attributes.
# Attribute Linked List
Stores attribute name and cost for each event.
# Queue
Maintains order of events for processing.
# Event Linked List:
A chain of Event nodes.
Each event contains event info (name, date, cost) and a pointer to the next event.
# Attribute Linked List inside each Event:
Each Event has its own sub-linked list of Attribute nodes.
Attributes have a name, cost, and a pointer to the next attribute.
# Queue Nodes:
Separate from the event list.
Point to the event nodes for processing order.
