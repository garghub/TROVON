int F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 , struct V_2 , V_1 ) ;
struct V_4 * V_5 ;
struct V_6 * V_7 = NULL ;
struct V_8 * V_9 ;
struct V_10 * V_11 ;
struct V_12 * V_13 ;
T_1 V_14 ;
T_2 V_15 = V_16 | V_17 ;
T_2 V_18 ;
T_2 V_19 = 0 ;
T_2 V_20 = 0 ;
T_1 V_21 = 0 ;
T_1 V_22 ;
T_1 V_23 ;
T_1 V_24 ;
struct V_25 * V_25 ;
int V_26 ;
int error ;
void * V_27 ;
void * V_28 ;
void * V_29 = NULL ;
V_9 = F_3 ( V_3 -> V_30 ) ;
V_11 = V_9 -> V_31 ;
V_3 -> V_30 = V_11 -> V_32 . V_33 ( V_3 -> V_30 ) ;
V_5 = F_4 ( V_1 ) ;
F_5 ( ! V_5 ) ;
V_14 = V_1 -> V_34 ;
if ( V_5 -> V_35 ) {
V_13 = F_6 ( V_5 -> V_36 ,
struct V_12 , V_37 ) ;
V_22 = V_13 -> V_38 ;
V_18 = V_13 -> V_39 ;
V_25 = V_13 -> V_40 ;
} else {
V_13 = NULL ;
V_22 = V_14 ;
V_18 = 0 ;
V_25 = NULL ;
}
V_26 = ! ( V_14 % 4 ) ;
while ( V_14 ) {
if ( ! V_22 ) {
F_5 ( ! V_13 ) ;
V_13 = F_7 ( V_13 -> V_37 . V_41 ,
struct V_12 , V_37 ) ;
V_22 = F_8 ( ( T_1 ) V_13 -> V_38 , V_14 ) ;
V_18 = V_13 -> V_39 ;
V_25 = V_13 -> V_40 ;
}
if ( ! V_21 ) {
V_21 = ( V_11 -> V_42 ) ? V_11 -> V_43 :
V_3 -> V_44 -> V_45 ;
V_21 = F_8 ( V_21 , V_14 ) ;
V_7 = F_9 ( V_11 , V_26 ? 0 : V_21 ) ;
if ( ! V_7 )
return - V_46 ;
V_29 = F_10 ( V_7 , 0 ) ;
V_19 = V_20 ;
V_20 += V_21 ;
F_11 ( V_7 ) = V_3 -> V_44 -> V_45 ;
}
V_23 = F_8 ( V_22 , V_21 ) ;
if ( V_26 ) {
if ( ! V_13 ) {
F_5 ( ! V_5 -> V_47 ) ;
V_27 = V_5 -> V_47 + V_18 ;
V_24 = F_12 ( V_27 ) ;
V_25 = F_13 ( V_27 ) ;
V_23 = F_8 ( V_23 , V_48 - V_24 ) ;
} else
V_24 = V_18 ;
F_5 ( ! V_25 ) ;
F_14 ( V_25 ) ;
F_15 ( F_16 ( V_7 ) ,
F_17 ( F_16 ( V_7 ) ) -> V_49 ,
V_25 , V_24 , V_23 ) ;
F_18 ( V_7 ) += V_23 ;
F_16 ( V_7 ) -> V_50 += V_23 ;
F_16 ( V_7 ) -> V_51 +=
V_48 << F_19 ( V_25 ) ;
} else if ( V_13 ) {
F_5 ( ! V_25 ) ;
V_28 = F_20 ( V_25 + ( V_18 >> V_52 ) ,
V_53 ) ;
V_27 = V_28 ;
V_28 += V_18 & ~ V_54 ;
V_23 = F_8 ( V_23 , ( T_1 ) ( V_48 -
( V_18 & ~ V_54 ) ) ) ;
memcpy ( V_29 , V_28 , V_23 ) ;
F_21 ( V_27 , V_53 ) ;
V_29 += V_23 ;
} else {
V_28 = V_5 -> V_47 + V_18 ;
memcpy ( V_29 , V_28 , V_23 ) ;
V_29 += V_23 ;
}
V_18 += V_23 ;
V_22 -= V_23 ;
V_21 -= V_23 ;
V_14 -= V_23 ;
if ( V_21 &&
( F_17 ( F_16 ( V_7 ) ) -> V_49 < V_55 ) )
continue;
if ( ! V_14 )
V_15 |= V_56 ;
F_22 ( V_7 , V_57 , V_9 -> V_58 , V_9 -> V_59 ,
V_60 , V_15 , V_19 ) ;
error = V_11 -> V_32 . V_61 ( V_11 , V_3 -> V_30 , V_7 ) ;
if ( error ) {
if ( F_23 () )
F_24 ( V_62 L_1
L_2
L_3 ,
V_63 , V_7 , V_9 -> V_64 ,
V_14 , V_11 -> V_43 ) ;
}
}
return F_25 ( V_1 ) ;
}
void F_26 ( struct V_2 * V_3 , struct V_6 * V_7 )
{
struct V_1 * V_1 = & V_3 -> V_1 ;
struct V_65 * V_30 = V_3 -> V_30 ;
struct V_8 * V_9 ;
struct V_10 * V_11 ;
struct V_4 * V_5 ;
struct V_66 * V_67 ;
struct V_12 * V_13 ;
T_2 V_18 ;
T_2 V_68 ;
T_1 V_21 ;
T_1 V_22 ;
T_1 V_23 ;
struct V_25 * V_25 ;
void * V_27 ;
void * V_28 ;
void * V_29 ;
T_2 V_15 ;
void * V_69 ;
V_5 = F_4 ( V_1 ) ;
F_5 ( ! V_5 ) ;
V_67 = F_27 ( V_7 ) ;
if ( ! ( F_28 ( V_67 -> V_70 ) & V_17 ) )
goto V_71;
V_69 = F_10 ( V_7 , 1 ) ;
if ( V_3 -> V_72 && V_69 ) {
F_24 ( V_73 L_4
L_5
L_6
L_7 , V_63 ) ;
F_5 ( V_69 ) ;
}
V_9 = F_3 ( V_30 ) ;
if ( V_3 -> V_72 ) {
F_5 ( ! V_9 ) ;
V_11 = V_9 -> V_31 ;
F_5 ( ! V_11 ) ;
}
if ( V_3 -> V_72 && V_9 -> V_64 != V_74 ) {
V_15 = F_28 ( V_67 -> V_70 ) ;
if ( V_15 & V_75 ) {
V_3 -> V_76 = V_11 -> V_32 . V_77 ( V_11 ,
V_9 -> V_64 ) ;
goto V_78;
} else {
F_24 ( V_62 L_8
L_9
L_10 ,
V_63 , V_3 -> V_79 , V_3 -> V_80 ) ;
V_3 -> V_76 = V_11 -> V_32 . V_77 ( V_11 ,
V_9 -> V_64 ) ;
V_11 -> V_32 . V_81 ( V_3 -> V_30 , 0 ) ;
goto V_71;
}
}
V_68 = F_29 ( V_67 -> V_82 ) ;
V_21 = F_18 ( V_7 ) ;
if ( V_21 <= sizeof( * V_67 ) )
goto V_71;
V_21 -= sizeof( * V_67 ) ;
V_28 = F_10 ( V_7 , 0 ) ;
if ( V_68 >= V_1 -> V_34 )
goto V_71;
if ( V_21 + V_68 > V_1 -> V_34 )
V_21 = V_1 -> V_34 - V_68 ;
if ( V_5 -> V_35 ) {
V_13 = F_6 ( V_5 -> V_36 ,
struct V_12 , V_37 ) ;
V_22 = V_13 -> V_38 ;
V_18 = V_13 -> V_39 ;
V_25 = V_13 -> V_40 ;
} else {
V_13 = NULL ;
V_25 = NULL ;
V_18 = 0 ;
V_22 = V_21 ;
}
while ( V_21 ) {
if ( ! V_22 ) {
F_5 ( ! V_13 ) ;
V_13 = F_7 ( V_13 -> V_37 . V_41 ,
struct V_12 , V_37 ) ;
V_22 = V_13 -> V_38 ;
V_18 = V_13 -> V_39 ;
V_25 = V_13 -> V_40 ;
}
if ( V_68 >= V_22 ) {
V_68 -= V_22 ;
V_22 = 0 ;
continue;
}
V_18 += V_68 ;
V_22 -= V_68 ;
V_68 = 0 ;
V_23 = F_8 ( V_22 , V_21 ) ;
if ( V_13 ) {
V_29 = F_20 ( V_25 + ( V_18 >> V_52 ) ,
V_53 ) ;
V_27 = V_29 ;
V_29 += V_18 & ~ V_54 ;
V_23 = F_8 ( V_23 , ( T_1 ) ( V_48 -
( V_18 & ~ V_54 ) ) ) ;
memcpy ( V_29 , V_28 , V_23 ) ;
F_21 ( V_27 , V_53 ) ;
} else {
V_29 = V_5 -> V_47 + V_18 ;
memcpy ( V_29 , V_28 , V_23 ) ;
}
V_28 += V_23 ;
V_21 -= V_23 ;
V_18 += V_23 ;
V_22 -= V_23 ;
V_3 -> V_76 += V_23 ;
}
V_78:
if ( V_3 -> V_76 == V_1 -> V_34 )
F_30 ( V_1 ) ;
V_71:
F_31 ( V_7 ) ;
}
