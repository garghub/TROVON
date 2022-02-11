void F_1 ( unsigned long V_1 , T_1 V_2 )
{
T_2 * V_3 ;
T_3 * V_4 ;
T_4 * V_5 ;
T_1 * V_6 ;
V_3 = V_7 + F_2 ( V_1 ) ;
if ( F_3 ( * V_3 ) ) {
F_4 () ;
return;
}
V_4 = F_5 ( V_3 , V_1 ) ;
if ( F_6 ( * V_4 ) ) {
F_4 () ;
return;
}
V_5 = F_7 ( V_4 , V_1 ) ;
if ( F_8 ( * V_5 ) ) {
F_4 () ;
return;
}
V_6 = F_9 ( V_5 , V_1 ) ;
if ( ! F_10 ( V_2 ) )
F_11 ( & V_8 , V_1 , V_6 , V_2 ) ;
else
F_12 ( & V_8 , V_1 , V_6 ) ;
F_13 ( V_1 ) ;
}
static int T_5 F_14 ( char * V_9 )
{
if ( ! V_9 )
return - V_10 ;
V_11 = F_15 ( V_9 , & V_9 ) + V_12 ;
return 0 ;
}
static int T_5 F_16 ( char * V_9 )
{
unsigned long V_13 ;
if ( ! V_9 )
return - V_10 ;
V_13 = F_15 ( V_9 , & V_9 ) ;
F_17 ( V_13 ) ;
F_18 () ;
return 0 ;
}
