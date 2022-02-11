static int F_1 ( struct V_1 * V_2 , T_1 * V_3 )
{
T_1 V_4 ;
int V_5 ;
V_5 = F_2 ( V_6 , V_7 , V_8 , & V_4 ) ;
if ( V_5 ) {
F_3 ( V_2 , L_1 ) ;
return V_5 ;
}
* V_3 = V_4 & V_9 ;
return 0 ;
}
static void F_4 ( struct V_1 * V_2 )
{
T_1 V_4 ;
if ( F_2 ( V_6 , V_7 , V_8 , & V_4 ) ) {
F_3 ( V_2 , L_2 ) ;
return;
}
V_4 &= ~ V_9 ;
if ( F_5 ( V_6 , V_10 , V_8 , V_4 ) )
F_3 ( V_2 , L_3 ) ;
}
static int F_6 ( struct V_11 * V_2 )
{
T_1 V_3 = V_12 ;
int V_5 ;
unsigned long V_13 , V_14 ;
F_7 () ;
if ( ! V_2 || ! V_2 -> V_2 )
return - V_15 ;
if ( ! V_2 -> V_16 )
return 0 ;
V_5 = F_5 ( V_6 , V_10 , V_8 , V_3 ) ;
if ( V_5 ) {
F_3 ( V_2 -> V_2 , L_4 ) ;
return V_5 ;
}
V_13 = V_17 ;
V_14 = V_13 + F_8 ( V_18 ) ;
do {
V_5 = F_1 ( V_2 -> V_2 , & V_3 ) ;
if ( ! V_5 && V_3 ) {
V_19 = V_17 ;
F_9 ( V_2 -> V_2 , L_5 ,
F_10 ( V_17 - V_13 ) ) ;
return 0 ;
}
F_11 ( 1000 , 2000 ) ;
} while ( F_12 ( V_17 , V_14 ) );
F_3 ( V_2 -> V_2 , L_6 ) ;
F_4 ( V_2 -> V_2 ) ;
V_5 = F_2 ( V_6 , V_7 , V_8 , & V_3 ) ;
if ( V_5 )
F_3 ( V_2 -> V_2 , L_1 ) ;
else
F_3 ( V_2 -> V_2 , L_7 , V_3 ) ;
F_13 ( 1 ) ;
return - V_20 ;
}
static void F_14 ( struct V_11 * V_2 )
{
if ( ! V_2 || ! V_2 -> V_2 )
return;
if ( ! V_2 -> V_21 )
return;
F_4 ( V_2 -> V_2 ) ;
F_9 ( V_2 -> V_2 , L_8 ,
F_10 ( V_17 - V_19 ) ) ;
}
int F_15 ( struct V_11 * V_2 )
{
T_2 V_22 ;
unsigned long long V_23 = 0 ;
T_3 V_24 ;
if ( ! V_2 || ! V_2 -> V_2 )
return 0 ;
V_24 = F_16 ( V_2 -> V_2 ) ;
if ( ! V_24 )
return 0 ;
V_22 = F_17 ( V_24 , L_9 , NULL , & V_23 ) ;
if ( F_18 ( V_22 ) )
return 0 ;
if ( V_23 ) {
F_19 ( V_2 -> V_2 , L_10 ) ;
V_2 -> V_21 = F_6 ;
V_2 -> V_16 = F_14 ;
V_2 -> V_25 = true ;
}
if ( ! F_20 () )
return - V_26 ;
return 0 ;
}
