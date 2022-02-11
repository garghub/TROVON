static T_1 F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 & V_4 )
return V_5 ;
else
return V_6 ;
}
static int F_2 ( struct V_1 * V_2 , T_1 * V_7 )
{
T_1 V_8 = F_1 ( V_2 ) ;
T_1 V_9 ;
int V_10 ;
V_10 = F_3 ( V_11 , V_12 , V_8 , & V_9 ) ;
if ( V_10 ) {
F_4 ( V_2 -> V_2 , L_1 ) ;
return V_10 ;
}
* V_7 = V_9 & V_13 ;
return 0 ;
}
static void F_5 ( struct V_1 * V_2 )
{
if ( F_6 ( V_11 , V_12 , F_1 ( V_2 ) ,
0 , V_13 ) )
F_4 ( V_2 -> V_2 , L_2 ) ;
F_7 ( & V_2 -> V_14 , V_15 ) ;
F_8 ( V_16 ,
NULL ) ;
F_9 () ;
}
static int F_10 ( struct V_1 * V_2 )
{
T_1 V_8 ;
T_1 V_7 = V_17 ;
int V_10 ;
unsigned long V_18 , V_19 ;
F_11 () ;
if ( ! V_2 || ! V_2 -> V_2 )
return - V_20 ;
if ( ! V_2 -> V_21 )
return 0 ;
F_12 () ;
F_8 ( V_22 ,
NULL ) ;
F_7 ( & V_2 -> V_14 , 0 ) ;
V_8 = F_1 ( V_2 ) ;
V_10 = F_13 ( V_11 , V_23 , V_8 , V_7 ) ;
if ( V_10 ) {
F_4 ( V_2 -> V_2 , L_3 ) ;
goto V_24;
}
V_18 = V_25 ;
V_19 = V_18 + F_14 ( V_26 ) ;
do {
V_10 = F_2 ( V_2 , & V_7 ) ;
if ( ! V_10 && V_7 ) {
V_27 = V_25 ;
F_15 ( V_2 -> V_2 , L_4 ,
F_16 ( V_25 - V_18 ) ) ;
return 0 ;
}
F_17 ( 1000 , 2000 ) ;
} while ( F_18 ( V_25 , V_19 ) );
F_4 ( V_2 -> V_2 , L_5 ) ;
V_24:
F_5 ( V_2 ) ;
V_10 = F_3 ( V_11 , V_12 , V_8 , & V_7 ) ;
if ( V_10 )
F_4 ( V_2 -> V_2 , L_1 ) ;
else
F_4 ( V_2 -> V_2 , L_6 , V_7 ) ;
F_19 ( 1 ) ;
return - V_28 ;
}
static void F_20 ( struct V_1 * V_2 )
{
if ( ! V_2 || ! V_2 -> V_2 )
return;
if ( ! V_2 -> V_29 )
return;
F_5 ( V_2 ) ;
F_15 ( V_2 -> V_2 , L_7 ,
F_16 ( V_25 - V_27 ) ) ;
}
int F_21 ( struct V_1 * V_2 )
{
T_2 V_30 ;
unsigned long long V_31 = 0 ;
T_3 V_32 ;
if ( ! V_2 || ! V_2 -> V_2 )
return 0 ;
V_32 = F_22 ( V_2 -> V_2 ) ;
if ( ! V_32 )
return 0 ;
V_30 = F_23 ( V_32 , L_8 , NULL , & V_31 ) ;
if ( F_24 ( V_30 ) )
return 0 ;
if ( ! V_31 )
return 0 ;
if ( ! F_25 () )
return - V_33 ;
F_26 ( V_2 -> V_2 , L_9 ) ;
V_2 -> V_29 = F_10 ;
V_2 -> V_21 = F_20 ;
V_2 -> V_34 = true ;
F_27 ( & V_2 -> V_14 , V_35 ,
V_15 ) ;
return 0 ;
}
void F_28 ( struct V_1 * V_2 )
{
if ( V_2 -> V_29 )
F_29 ( & V_2 -> V_14 ) ;
}
