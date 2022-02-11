void F_1 ( void )
{
switch ( V_1 ) {
default:
case V_2 :
asm volatile ("outb %al, $0x80");
break;
case V_3 :
asm volatile ("outb %al, $0xed");
break;
case V_4 :
F_2 ( 2 ) ;
case V_5 :
break;
}
}
static int T_1 F_3 ( const struct V_6 * V_7 )
{
if ( V_1 == V_2 ) {
F_4 ( L_1 , V_7 -> V_8 ) ;
V_1 = V_3 ;
}
return 0 ;
}
void T_1 F_5 ( void )
{
if ( ! V_9 )
F_6 ( V_10 ) ;
}
static int T_1 F_7 ( char * V_11 )
{
if ( ! V_11 )
return - V_12 ;
if ( ! strcmp ( V_11 , L_2 ) )
V_1 = V_2 ;
else if ( ! strcmp ( V_11 , L_3 ) )
V_1 = V_3 ;
else if ( ! strcmp ( V_11 , L_4 ) )
V_1 = V_4 ;
else if ( ! strcmp ( V_11 , L_5 ) )
V_1 = V_5 ;
else
return - V_12 ;
V_9 = 1 ;
return 0 ;
}
