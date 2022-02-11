void F_1 ( unsigned long V_1 , T_1 V_2 )
{
T_2 * V_3 ;
T_3 * V_4 ;
T_4 * V_5 ;
T_5 * V_6 ;
T_1 * V_7 ;
V_3 = V_8 + F_2 ( V_1 ) ;
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
if ( F_10 ( * V_6 ) ) {
F_4 () ;
return;
}
V_7 = F_11 ( V_6 , V_1 ) ;
if ( ! F_12 ( V_2 ) )
F_13 ( & V_9 , V_1 , V_7 , V_2 ) ;
else
F_14 ( & V_9 , V_1 , V_7 ) ;
F_15 ( V_1 ) ;
}
static int T_6 F_16 ( char * V_10 )
{
if ( ! V_10 )
return - V_11 ;
V_12 = F_17 ( V_10 , & V_10 ) + V_13 ;
return 0 ;
}
static int T_6 F_18 ( char * V_10 )
{
unsigned long V_14 ;
if ( ! V_10 )
return - V_11 ;
V_14 = F_17 ( V_10 , & V_10 ) ;
F_19 ( V_14 ) ;
F_20 () ;
return 0 ;
}
