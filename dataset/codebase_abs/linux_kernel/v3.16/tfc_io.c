int F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 , struct V_2 , V_1 ) ;
struct V_4 * V_5 = NULL ;
struct V_6 * V_7 ;
struct V_8 * V_9 ;
struct V_10 * V_11 = NULL ;
T_1 V_12 ;
T_2 V_13 = V_14 | V_15 ;
T_2 V_16 = 0 ;
T_2 V_17 = 0 ;
T_2 V_18 = 0 ;
T_1 V_19 = 0 ;
T_1 V_20 = 0 ;
T_1 V_21 ;
T_1 V_22 ;
struct V_23 * V_23 = NULL ;
int V_24 ;
int error ;
void * V_25 ;
void * V_26 ;
void * V_27 = NULL ;
if ( V_3 -> V_28 )
return 0 ;
if ( V_1 -> V_29 == V_30 )
goto V_31;
V_7 = F_3 ( V_3 -> V_32 ) ;
V_9 = V_7 -> V_33 ;
V_3 -> V_32 = V_9 -> V_34 . V_35 ( V_3 -> V_32 ) ;
V_12 = V_1 -> V_36 ;
F_4 ( V_12 && ! V_1 -> V_37 ) ;
if ( V_12 ) {
V_11 = V_1 -> V_37 ;
V_20 = V_11 -> V_38 ;
V_16 = V_11 -> V_39 ;
V_23 = F_5 ( V_11 ) ;
}
V_24 = ! ( V_12 % 4 ) ;
while ( V_12 ) {
struct V_40 * V_32 = V_3 -> V_32 ;
if ( ! V_32 ) {
F_6 ( L_1 ,
V_41 , V_7 -> V_42 ) ;
break;
}
if ( ! V_20 ) {
V_11 = F_7 ( V_11 ) ;
V_20 = F_8 ( ( T_1 ) V_11 -> V_38 , V_12 ) ;
V_16 = V_11 -> V_39 ;
V_23 = F_5 ( V_11 ) ;
}
if ( ! V_19 ) {
V_19 = ( V_9 -> V_43 ) ? V_9 -> V_44 :
V_3 -> V_45 -> V_46 ;
V_19 = F_8 ( V_19 , V_12 ) ;
V_5 = F_9 ( V_9 , V_24 ? 0 : V_19 ) ;
if ( ! V_5 )
return - V_47 ;
V_27 = F_10 ( V_5 , 0 ) ;
V_17 = V_18 ;
V_18 += V_19 ;
F_11 ( V_5 ) = V_3 -> V_45 -> V_46 ;
}
V_21 = F_8 ( V_20 , V_19 ) ;
if ( V_24 ) {
V_22 = V_16 ;
F_4 ( ! V_23 ) ;
F_12 ( V_23 ) ;
F_13 ( F_14 ( V_5 ) ,
F_15 ( F_14 ( V_5 ) ) -> V_48 ,
V_23 , V_22 , V_21 ) ;
F_16 ( V_5 ) += V_21 ;
F_14 ( V_5 ) -> V_49 += V_21 ;
F_14 ( V_5 ) -> V_50 +=
V_51 << F_17 ( V_23 ) ;
} else {
F_4 ( ! V_23 ) ;
V_26 = F_18 ( V_23 + ( V_16 >> V_52 ) ) ;
V_25 = V_26 ;
V_26 += V_16 & ~ V_53 ;
V_21 = F_8 ( V_21 , ( T_1 ) ( V_51 -
( V_16 & ~ V_53 ) ) ) ;
memcpy ( V_27 , V_26 , V_21 ) ;
F_19 ( V_25 ) ;
V_27 += V_21 ;
}
V_16 += V_21 ;
V_20 -= V_21 ;
V_19 -= V_21 ;
V_12 -= V_21 ;
if ( V_19 &&
( F_15 ( F_14 ( V_5 ) ) -> V_48 < V_54 ) )
continue;
if ( ! V_12 )
V_13 |= V_55 ;
F_20 ( V_5 , V_56 , V_7 -> V_57 , V_7 -> V_58 ,
V_59 , V_13 , V_17 ) ;
error = V_9 -> V_34 . V_60 ( V_9 , V_32 , V_5 ) ;
if ( error ) {
F_21 ( L_2
L_3
L_4 ,
V_41 , V_5 , V_7 -> V_42 ,
V_12 , V_9 -> V_44 ) ;
V_1 -> V_29 = V_30 ;
break;
}
}
V_31:
return F_22 ( V_1 ) ;
}
static void F_23 ( struct V_61 * V_62 )
{
struct V_2 * V_3 = F_2 ( V_62 , struct V_2 , V_62 ) ;
F_24 ( & V_3 -> V_1 ) ;
}
void F_25 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
struct V_1 * V_1 = & V_3 -> V_1 ;
struct V_40 * V_32 = V_3 -> V_32 ;
struct V_6 * V_7 ;
struct V_8 * V_9 ;
struct V_63 * V_64 ;
struct V_10 * V_11 = NULL ;
T_2 V_16 = 0 ;
T_2 V_65 ;
T_1 V_19 ;
T_1 V_20 = 0 ;
T_1 V_21 ;
struct V_23 * V_23 = NULL ;
void * V_25 ;
void * V_26 ;
void * V_27 ;
T_2 V_13 ;
void * V_66 ;
V_64 = F_26 ( V_5 ) ;
if ( ! ( F_27 ( V_64 -> V_67 ) & V_15 ) )
goto V_68;
V_13 = F_27 ( V_64 -> V_67 ) ;
V_7 = F_3 ( V_32 ) ;
V_9 = V_7 -> V_33 ;
if ( V_3 -> V_69 ) {
F_4 ( ! V_7 ) ;
F_4 ( ! V_9 ) ;
V_66 = F_10 ( V_5 , 1 ) ;
if ( V_66 )
F_28 ( L_5
L_6
L_7
L_8
L_9
L_10 , V_41 , V_7 -> V_42 , V_13 ,
V_1 -> V_37 , V_1 -> V_70 ) ;
F_29 ( V_3 ) ;
if ( V_13 & V_71 )
goto V_72;
else
goto V_68;
}
V_65 = F_30 ( V_64 -> V_73 ) ;
V_19 = F_16 ( V_5 ) ;
if ( V_19 <= sizeof( * V_64 ) )
goto V_68;
V_19 -= sizeof( * V_64 ) ;
V_26 = F_10 ( V_5 , 0 ) ;
if ( V_65 >= V_1 -> V_36 )
goto V_68;
if ( V_19 + V_65 > V_1 -> V_36 )
V_19 = V_1 -> V_36 - V_65 ;
F_4 ( V_19 && ! V_1 -> V_37 ) ;
if ( V_19 ) {
V_11 = V_1 -> V_37 ;
V_20 = V_11 -> V_38 ;
V_16 = V_11 -> V_39 ;
V_23 = F_5 ( V_11 ) ;
}
while ( V_19 ) {
if ( ! V_20 ) {
V_11 = F_7 ( V_11 ) ;
V_20 = V_11 -> V_38 ;
V_16 = V_11 -> V_39 ;
V_23 = F_5 ( V_11 ) ;
}
if ( V_65 >= V_20 ) {
V_65 -= V_20 ;
V_20 = 0 ;
continue;
}
V_16 += V_65 ;
V_20 -= V_65 ;
V_65 = 0 ;
V_21 = F_8 ( V_20 , V_19 ) ;
V_27 = F_18 ( V_23 + ( V_16 >> V_52 ) ) ;
V_25 = V_27 ;
V_27 += V_16 & ~ V_53 ;
V_21 = F_8 ( V_21 , ( T_1 ) ( V_51 -
( V_16 & ~ V_53 ) ) ) ;
memcpy ( V_27 , V_26 , V_21 ) ;
F_19 ( V_25 ) ;
V_26 += V_21 ;
V_19 -= V_21 ;
V_16 += V_21 ;
V_20 -= V_21 ;
V_3 -> V_74 += V_21 ;
}
V_72:
if ( V_3 -> V_74 == V_1 -> V_36 ) {
F_31 ( & V_3 -> V_62 , F_23 ) ;
F_32 ( V_3 -> V_45 -> V_75 -> V_76 -> V_77 , & V_3 -> V_62 ) ;
}
V_68:
F_33 ( V_5 ) ;
}
void F_29 ( struct V_2 * V_3 )
{
struct V_40 * V_32 ;
struct V_6 * V_7 = NULL ;
struct V_8 * V_9 = NULL ;
F_4 ( ! V_3 ) ;
V_32 = V_3 -> V_32 ;
if ( V_3 -> V_69 && V_32 ) {
V_7 = F_3 ( V_32 ) ;
if ( V_7 ) {
V_9 = V_7 -> V_33 ;
if ( V_9 && ( V_7 -> V_42 <= V_9 -> V_78 ) )
V_3 -> V_74 = V_9 -> V_34 . V_79 ( V_9 ,
V_7 -> V_42 ) ;
V_3 -> V_69 = 0 ;
}
}
}
