int F_1 ( struct V_1 * V_2 )
{
void T_1 * V_3 ;
if ( ! V_2 ) {
F_2 ( L_1 , V_4 ) ;
return - V_5 ;
}
V_3 = F_3 ( V_2 ) ;
if ( ! V_3 ) {
F_2 ( L_2 ,
V_2 -> V_6 , V_4 ) ;
return - V_5 ;
}
F_4 ( 0xAAAA , V_3 + V_7 ) ;
while ( F_5 ( V_3 + V_8 ) & 0x10 )
F_6 () ;
F_4 ( 0x5555 , V_3 + V_7 ) ;
while ( F_5 ( V_3 + V_8 ) & 0x10 )
F_6 () ;
return 0 ;
}
int F_7 ( struct V_1 * V_2 )
{
int V_9 = 0 ;
F_8 ( V_2 ) ;
F_9 ( ( F_10 ( V_2 ,
V_2 -> V_10 -> V_11 -> V_12 )
& V_13 ) ,
V_14 , V_9 ) ;
if ( V_2 -> V_10 -> V_11 -> V_15 )
F_11 ( V_2 -> V_10 -> V_11 -> V_15 ) ;
if ( V_9 == V_14 )
F_12 ( L_3 ,
V_4 , V_2 -> V_6 , V_14 ) ;
else
F_13 ( L_4 , V_4 ,
V_2 -> V_6 , V_9 ) ;
return ( V_9 == V_14 ) ? - V_16 :
F_1 ( V_2 ) ;
}
static int T_2 F_14 ( void )
{
int V_17 = - 1 ;
struct V_18 * V_19 ;
struct V_1 * V_2 ;
char * V_20 = L_5 ;
char * V_21 = L_6 ;
struct V_22 V_23 ;
if ( ! F_15 () || F_16 () )
return 0 ;
V_2 = F_17 ( V_20 ) ;
if ( ! V_2 ) {
F_2 ( L_7 , V_17 ) ;
return - V_5 ;
}
V_23 . V_24 = V_25 ;
V_19 = F_18 ( V_21 , V_17 , V_2 , & V_23 ,
sizeof( struct V_22 ) ) ;
F_19 ( F_20 ( V_19 ) , L_8 ,
V_21 , V_2 -> V_6 ) ;
return 0 ;
}
