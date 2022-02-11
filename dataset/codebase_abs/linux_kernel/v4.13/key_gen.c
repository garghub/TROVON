static inline T_1 F_1 ( T_1 V_1 )
{
static const T_2 V_2 [] = { 16 , 20 , 32 , 32 , 64 , 64 } ;
T_1 V_3 ;
V_3 = ( V_1 & V_4 ) >> V_5 ;
return ( T_1 ) ( V_2 [ V_3 ] * 2 ) ;
}
static inline T_1 F_2 ( T_1 V_1 )
{
return F_3 ( F_1 ( V_1 ) , 16 ) ;
}
void F_4 ( struct V_6 * V_7 , T_1 * V_8 , T_1 V_9 ,
void * V_10 )
{
struct V_11 * V_12 = V_10 ;
#ifdef F_5
F_6 ( V_7 , L_1 , V_13 , __LINE__ , V_9 ) ;
#endif
if ( V_9 )
F_7 ( V_7 , V_9 ) ;
V_12 -> V_9 = V_9 ;
F_8 ( & V_12 -> V_14 ) ;
}
int F_9 ( struct V_6 * V_15 , T_2 * V_16 ,
struct V_17 * const V_18 , const T_2 * V_19 , T_1 V_20 ,
int V_21 )
{
T_1 * V_8 ;
struct V_11 V_22 ;
T_3 V_23 , V_24 ;
int V_25 = - V_26 ;
V_18 -> V_20 = F_1 ( V_18 -> V_27 & V_28 ) ;
V_18 -> V_29 = F_2 ( V_18 -> V_27 &
V_28 ) ;
#ifdef F_5
F_6 ( V_15 , L_2 ,
V_18 -> V_20 , V_18 -> V_29 ) ;
F_10 ( V_30 , L_3 F_11 ( __LINE__ ) L_4 ,
V_31 , 16 , 4 , V_19 , V_20 , 1 ) ;
#endif
if ( V_18 -> V_29 > V_21 )
return - V_32 ;
V_8 = F_12 ( V_33 * 6 + V_34 * 2 , V_35 | V_36 ) ;
if ( ! V_8 ) {
F_6 ( V_15 , L_5 ) ;
return V_25 ;
}
V_23 = F_13 ( V_15 , ( void * ) V_19 , V_20 ,
V_37 ) ;
if ( F_14 ( V_15 , V_23 ) ) {
F_6 ( V_15 , L_6 ) ;
goto V_38;
}
V_24 = F_13 ( V_15 , V_16 , V_18 -> V_29 ,
V_39 ) ;
if ( F_14 ( V_15 , V_24 ) ) {
F_6 ( V_15 , L_7 ) ;
goto V_40;
}
F_15 ( V_8 , 0 ) ;
F_16 ( V_8 , V_23 , V_20 , V_41 | V_42 ) ;
F_17 ( V_8 , ( V_18 -> V_27 & V_28 ) |
V_43 | V_44 | V_45 |
V_46 ) ;
F_18 ( V_8 , NULL , 0 , V_47 |
V_48 | V_49 ) ;
F_19 ( V_8 , V_24 , V_18 -> V_20 ,
V_47 | V_50 ) ;
#ifdef F_5
F_10 ( V_30 , L_3 F_11 ( __LINE__ ) L_4 ,
V_31 , 16 , 4 , V_19 , V_20 , 1 ) ;
F_10 ( V_30 , L_8 F_11 ( __LINE__ ) L_4 ,
V_31 , 16 , 4 , V_8 , F_20 ( V_8 ) , 1 ) ;
#endif
V_22 . V_9 = 0 ;
F_21 ( & V_22 . V_14 ) ;
V_25 = F_22 ( V_15 , V_8 , F_4 , & V_22 ) ;
if ( ! V_25 ) {
F_23 ( & V_22 . V_14 ) ;
V_25 = V_22 . V_9 ;
#ifdef F_5
F_10 ( V_30 , L_3 F_11 ( __LINE__ ) L_4 ,
V_31 , 16 , 4 , V_16 ,
V_18 -> V_29 , 1 ) ;
#endif
}
F_24 ( V_15 , V_24 , V_18 -> V_29 ,
V_39 ) ;
V_40:
F_24 ( V_15 , V_23 , V_20 , V_37 ) ;
V_38:
F_25 ( V_8 ) ;
return V_25 ;
}
