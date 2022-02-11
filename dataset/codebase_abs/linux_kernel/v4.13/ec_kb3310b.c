unsigned char F_1 ( unsigned short V_1 )
{
unsigned char V_2 ;
unsigned long V_3 ;
F_2 ( & V_4 , V_3 ) ;
F_3 ( ( V_1 & 0xff00 ) >> 8 , V_5 ) ;
F_3 ( ( V_1 & 0x00ff ) , V_6 ) ;
V_2 = F_4 ( V_7 ) ;
F_5 ( & V_4 , V_3 ) ;
return V_2 ;
}
void F_6 ( unsigned short V_1 , unsigned char V_8 )
{
unsigned long V_3 ;
F_2 ( & V_4 , V_3 ) ;
F_3 ( ( V_1 & 0xff00 ) >> 8 , V_5 ) ;
F_3 ( ( V_1 & 0x00ff ) , V_6 ) ;
F_3 ( V_8 , V_7 ) ;
F_4 ( V_7 ) ;
F_5 ( & V_4 , V_3 ) ;
}
int F_7 ( unsigned char V_9 )
{
int V_10 ;
unsigned char V_11 ;
unsigned long V_3 ;
int V_12 = 0 ;
F_2 ( & V_13 , V_3 ) ;
F_8 ( V_14 ) ;
F_3 ( V_9 , V_15 ) ;
F_8 ( V_14 ) ;
V_10 = V_16 ;
V_11 = F_4 ( V_17 ) ;
while ( V_10 -- && ( V_11 & ( 1 << 1 ) ) ) {
V_11 = F_4 ( V_17 ) ;
F_8 ( V_14 ) ;
}
F_5 ( & V_13 , V_3 ) ;
if ( V_10 <= 0 ) {
F_9 ( V_18 L_1 , V_19 ) ;
V_12 = - V_20 ;
} else
F_9 ( V_21
L_2 ,
V_10 , V_16 - V_10 , V_9 , V_11 ) ;
return V_12 ;
}
int F_10 ( void )
{
return F_7 ( V_22 ) ;
}
int F_11 ( void )
{
int V_10 = 100 ;
unsigned char V_2 ;
unsigned char V_11 ;
F_8 ( V_14 ) ;
V_11 = F_4 ( V_17 ) ;
F_8 ( V_14 ) ;
while ( V_10 -- && ! ( V_11 & ( 1 << 0 ) ) ) {
V_11 = F_4 ( V_17 ) ;
F_8 ( V_14 ) ;
}
if ( V_10 <= 0 ) {
F_12 ( L_3 , V_19 ) ;
return - V_20 ;
}
V_2 = F_4 ( V_23 ) ;
F_8 ( V_14 ) ;
return V_2 ;
}
