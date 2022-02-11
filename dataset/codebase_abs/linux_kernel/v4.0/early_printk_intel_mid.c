void F_1 ( const char * V_1 )
{
unsigned long V_2 , V_3 = 0 ;
T_1 V_4 ;
if ( * V_1 && ! F_2 ( V_1 , 10 , & V_3 ) )
V_3 = F_3 ( V_3 , 0 , 2 ) ;
V_2 = V_5 + V_3 * 0x80 ;
V_6 = ( void V_7 * ) F_4 ( V_8 , V_2 ) ;
F_5 ( 0x0 , V_6 + V_9 ) ;
V_4 = F_6 ( V_6 + V_10 ) ;
F_5 ( ( 0x80 | V_4 ) , V_6 + V_10 ) ;
F_5 ( 0x18 , V_6 + V_11 ) ;
F_5 ( V_4 , V_6 + V_10 ) ;
F_7 ( 0x3600 , V_6 + V_12 * 4 ) ;
F_5 ( 0x8 , V_6 + V_13 ) ;
F_5 ( 0x7 , V_6 + V_9 ) ;
F_5 ( 0x3 , V_6 + V_10 ) ;
F_6 ( V_6 + V_14 ) ;
F_6 ( V_6 + V_15 ) ;
F_6 ( V_6 + V_16 ) ;
F_6 ( V_6 + V_17 ) ;
F_5 ( 0x7 , V_6 + V_9 ) ;
}
static void F_8 ( char V_18 )
{
unsigned int V_19 = 10000 ;
T_1 V_20 ;
while ( -- V_19 ) {
V_20 = F_6 ( V_6 + V_14 ) ;
if ( V_20 & V_21 )
break;
F_9 ( 1 ) ;
}
if ( V_19 )
F_5 ( V_18 , V_6 + V_22 ) ;
}
static void F_10 ( struct V_23 * V_24 , const char * V_25 , unsigned V_26 )
{
int V_27 ;
for ( V_27 = 0 ; V_27 < V_26 && * V_25 ; V_27 ++ ) {
if ( * V_25 == '\n' )
F_8 ( '\r' ) ;
F_8 ( * V_25 ) ;
V_25 ++ ;
}
}
