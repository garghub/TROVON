int fsl8250_handle_irq(struct uart_port *port)
{
unsigned char lsr, orig_lsr;
unsigned long flags;
unsigned int iir;
struct uart_8250_port *up =
container_of(port, struct uart_8250_port, port);
spin_lock_irqsave(&up->port.lock, flags);
iir = port->serial_in(port, UART_IIR);
if (iir & UART_IIR_NO_INT) {
spin_unlock_irqrestore(&up->port.lock, flags);
return 0;
}
if (unlikely(up->lsr_saved_flags & UART_LSR_BI)) {
up->lsr_saved_flags &= ~UART_LSR_BI;
port->serial_in(port, UART_RX);
spin_unlock_irqrestore(&up->port.lock, flags);
return 1;
}
lsr = orig_lsr = up->port.serial_in(&up->port, UART_LSR);
if (lsr & (UART_LSR_DR | UART_LSR_BI))
lsr = serial8250_rx_chars(up, lsr);
serial8250_modem_status(up);
if (lsr & UART_LSR_THRE)
serial8250_tx_chars(up);
up->lsr_saved_flags = orig_lsr;
spin_unlock_irqrestore(&up->port.lock, flags);
return 1;
}
