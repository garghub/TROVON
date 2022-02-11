unsigned int T_1 F_1 ()
{
return V_1 ;
}
char * T_1 F_2 ()
{
return V_2 [ V_3 ] ;
}
static unsigned char T_1 F_3 ( unsigned int V_1 , int V_4 )
{
F_4 ( V_4 , V_1 ) ;
return F_5 ( V_1 + 1 ) ;
}
static void T_1 F_6 ( unsigned int V_1 , int V_4 , unsigned char V_5 )
{
unsigned long V_6 ;
F_7 ( V_6 ) ;
F_4 ( V_4 , V_1 ) ;
F_4 ( V_5 , V_1 + 1 ) ;
F_4 ( V_5 , V_1 + 1 ) ;
F_8 ( V_6 ) ;
}
int T_1 F_9 ( void )
{
int V_7 , V_8 = 0 ;
while ( ( V_1 = V_9 [ V_8 ++ ] ) ) {
if ( F_10 ( V_1 , 2 , L_1 ) == NULL )
continue;
V_7 = F_3 ( V_1 , V_10 ) ;
if ( ( V_7 & 0xf0 ) == 0x10 ) {
V_3 = V_11 ;
break;
} else if ( ( V_7 & 0xf8 ) == 0x70 ) {
V_3 = V_12 ;
break;
} else if ( ( V_7 & 0xf8 ) == 0x50 ) {
V_3 = V_13 ;
break;
} else if ( ( V_7 & 0xf8 ) == 0x40 ) {
V_3 = V_14 ;
break;
}
F_11 ( V_1 , 2 ) ;
}
return ( V_1 == 0 ) ? - 1 : 1 ;
}
void T_1 F_12 ( void )
{
unsigned char V_5 ;
F_13 ( V_15 L_2 ) ;
V_5 = F_3 ( V_1 , V_16 ) ;
F_6 ( V_1 , V_16 , ( V_5 & 0xFC ) | 0x02 ) ;
}
void T_1 F_14 ( void )
{
unsigned char V_5 ;
F_13 ( V_15 L_3 ) ;
V_5 = F_3 ( V_1 , V_17 ) ;
F_6 ( V_1 , V_17 , V_5 | 0x40 ) ;
}
