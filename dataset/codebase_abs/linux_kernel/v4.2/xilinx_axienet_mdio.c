int F_1 ( struct V_1 * V_2 )
{
unsigned long V_3 = V_4 + 2 ;
while ( ! ( F_2 ( V_2 , V_5 ) &
V_6 ) ) {
if ( F_3 ( V_3 , V_4 ) ) {
F_4 ( 1 ) ;
return - V_7 ;
}
F_5 ( 1 ) ;
}
return 0 ;
}
static int F_6 ( struct V_8 * V_9 , int V_10 , int V_11 )
{
T_1 V_12 ;
int V_13 ;
struct V_1 * V_2 = V_9 -> V_14 ;
V_13 = F_1 ( V_2 ) ;
if ( V_13 < 0 )
return V_13 ;
F_7 ( V_2 , V_5 ,
( ( ( V_10 << V_15 ) &
V_16 ) |
( ( V_11 << V_17 ) &
V_18 ) |
V_19 |
V_20 ) ) ;
V_13 = F_1 ( V_2 ) ;
if ( V_13 < 0 )
return V_13 ;
V_12 = F_2 ( V_2 , V_21 ) & 0x0000FFFF ;
F_8 ( V_2 -> V_22 , L_1 ,
V_10 , V_11 , V_12 ) ;
return V_12 ;
}
static int F_9 ( struct V_8 * V_9 , int V_10 , int V_11 ,
T_2 V_23 )
{
int V_13 ;
struct V_1 * V_2 = V_9 -> V_14 ;
F_8 ( V_2 -> V_22 , L_2 ,
V_10 , V_11 , V_23 ) ;
V_13 = F_1 ( V_2 ) ;
if ( V_13 < 0 )
return V_13 ;
F_7 ( V_2 , V_24 , ( T_1 ) V_23 ) ;
F_7 ( V_2 , V_5 ,
( ( ( V_10 << V_15 ) &
V_16 ) |
( ( V_11 << V_17 ) &
V_18 ) |
V_19 |
V_25 ) ) ;
V_13 = F_1 ( V_2 ) ;
if ( V_13 < 0 )
return V_13 ;
return 0 ;
}
int F_10 ( struct V_1 * V_2 , struct V_26 * V_27 )
{
int V_13 ;
T_1 V_28 , V_29 ;
T_1 * V_30 ;
struct V_8 * V_9 ;
struct V_31 V_32 ;
struct V_26 * V_33 ;
V_33 = F_11 ( NULL , L_3 ) ;
if ( ! V_33 ) {
F_12 ( V_2 -> V_34 , L_4 ) ;
F_12 ( V_2 -> V_34 ,
L_5 ,
V_35 ) ;
V_28 = V_35 ;
goto V_36;
}
V_30 = ( T_1 * ) F_13 ( V_33 , L_6 , NULL ) ;
if ( ! V_30 ) {
F_12 ( V_2 -> V_34 , L_7 ) ;
F_12 ( V_2 -> V_34 ,
L_5 ,
V_35 ) ;
V_28 = V_35 ;
F_14 ( V_33 ) ;
goto V_36;
}
V_29 = F_15 ( V_30 ) ;
V_28 = ( V_29 / ( V_37 * 2 ) ) - 1 ;
if ( V_29 % ( V_37 * 2 ) )
V_28 ++ ;
F_16 ( V_2 -> V_34 ,
L_8 ,
V_28 , V_29 ) ;
F_14 ( V_33 ) ;
V_36:
F_7 ( V_2 , V_38 ,
( ( ( T_1 ) V_28 ) | V_39 ) ) ;
V_13 = F_1 ( V_2 ) ;
if ( V_13 < 0 )
return V_13 ;
V_9 = F_17 () ;
if ( ! V_9 )
return - V_40 ;
V_33 = F_18 ( V_2 -> V_41 ) ;
F_19 ( V_33 , 0 , & V_32 ) ;
snprintf ( V_9 -> V_42 , V_43 , L_9 ,
( unsigned long long ) V_32 . V_44 ) ;
V_9 -> V_14 = V_2 ;
V_9 -> V_45 = L_10 ;
V_9 -> V_46 = F_6 ;
V_9 -> V_47 = F_9 ;
V_9 -> V_48 = V_2 -> V_22 ;
V_9 -> V_49 = V_2 -> V_50 ;
V_2 -> V_8 = V_9 ;
V_13 = F_20 ( V_9 , V_33 ) ;
if ( V_13 ) {
F_21 ( V_9 ) ;
return V_13 ;
}
return 0 ;
}
void F_22 ( struct V_1 * V_2 )
{
F_23 ( V_2 -> V_8 ) ;
F_24 ( V_2 -> V_8 -> V_49 ) ;
F_21 ( V_2 -> V_8 ) ;
V_2 -> V_8 = NULL ;
}
