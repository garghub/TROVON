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
if ( F_10 ( V_2 ) )
F_11 ( & V_8 , V_1 , V_6 , V_2 ) ;
else
F_12 ( & V_8 , V_1 , V_6 ) ;
F_13 ( V_1 ) ;
}
void F_14 ( unsigned long V_1 , unsigned long V_9 , T_5 V_10 )
{
T_2 * V_3 ;
T_3 * V_4 ;
T_4 * V_5 ;
if ( V_1 & ( V_11 - 1 ) ) {
F_15 ( V_12 L_1 ) ;
return;
}
if ( V_9 & ( V_13 - 1 ) ) {
F_15 ( V_12 L_2 ) ;
return;
}
V_3 = V_7 + F_2 ( V_1 ) ;
if ( F_3 ( * V_3 ) ) {
F_15 ( V_12 L_3 ) ;
return;
}
V_4 = F_5 ( V_3 , V_1 ) ;
V_5 = F_7 ( V_4 , V_1 ) ;
F_16 ( V_5 , F_17 ( V_9 , V_10 ) ) ;
F_13 ( V_1 ) ;
}
static int T_6 F_18 ( char * V_14 )
{
if ( ! V_14 )
return - V_15 ;
V_16 = F_19 ( V_14 , & V_14 ) + V_17 ;
return 0 ;
}
static int T_6 F_20 ( char * V_14 )
{
unsigned long V_18 ;
if ( ! V_14 )
return - V_15 ;
V_18 = F_19 ( V_14 , & V_14 ) ;
F_21 ( V_18 ) ;
F_22 () ;
return 0 ;
}
