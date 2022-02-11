static void F_1 ( const char * V_1 , unsigned int V_2 )
{
unsigned int V_3 , V_4 ;
V_3 = F_2 ( V_5 ) ;
if ( strcmp ( V_1 , L_1 ) == 0 )
V_4 = V_6 ;
else if ( strcmp ( V_1 , L_2 ) == 0 )
V_4 = V_7 ;
else if ( strcmp ( V_1 , L_3 ) == 0 )
V_4 = V_8 ;
else if ( strcmp ( V_1 , L_4 ) == 0 )
V_4 = V_9 ;
else
V_4 = V_10 ;
V_3 &= ~ ( 0x03 << V_4 ) ;
V_3 |= ( V_2 << V_4 ) ;
F_3 ( V_3 , V_5 ) ;
}
void F_4 ( struct V_11 * V_12 , unsigned char * V_13 )
{
unsigned int V_2 ;
const char * V_1 ;
F_5 ( ! V_13 ) ;
V_2 = 0 ;
F_6 ( & V_14 ) ;
if ( V_12 )
V_1 = F_7 ( V_12 ) ;
else
V_1 = L_5 ;
if ( strcmp ( V_13 , L_6 ) == 0 )
V_2 = V_15 ;
else if ( strcmp ( V_13 , L_7 ) == 0 )
V_2 = V_16 ;
else if ( strcmp ( V_13 , L_8 ) == 0 )
V_2 = V_17 ;
else if ( strcmp ( V_13 , L_9 ) == 0 )
V_2 = V_18 ;
F_1 ( V_1 , V_2 ) ;
F_8 ( & V_14 ) ;
}
