T_1 F_1 ( struct V_1 * V_2 , T_2 V_3 )
{
T_3 V_4 , V_5 = 0 ;
T_1 V_6 ;
unsigned long V_7 , V_8 ;
T_1 V_9 ;
V_7 = V_10 ;
if ( ! ( V_2 -> V_11 & V_12 ) &&
( V_3 == V_2 -> V_13 -> V_14 ||
V_3 == V_2 -> V_13 -> V_15 ||
V_3 == V_2 -> V_13 -> V_16 ||
V_3 == V_2 -> V_13 -> V_17 ) ) {
V_6 = F_2 ( V_2 , V_3 ) ;
V_4 = V_6 == ~ 0ULL ? ~ 0U : 0 ;
V_5 = 1 ;
} else
V_6 = V_4 = F_3 ( V_2 , V_3 ) ;
V_8 = V_10 ;
if ( F_4 ( V_7 + V_18 , V_8 ) && V_4 == - 1 ) {
F_5 ( V_2 , L_1 ,
V_3 ) ;
V_9 = 0ULL ;
goto V_19;
}
if ( V_5 ) {
V_9 = V_6 ;
goto V_19;
}
if ( V_3 == V_2 -> V_13 -> V_14 ) {
if ( V_4 != V_2 -> V_20 ) {
V_2 -> V_21 += V_4 - V_2 -> V_20 ;
V_2 -> V_20 = V_4 ;
}
V_6 = V_2 -> V_21 ;
} else if ( V_3 == V_2 -> V_13 -> V_15 ) {
if ( V_4 != V_2 -> V_22 ) {
V_2 -> V_23 += V_4 - V_2 -> V_22 ;
V_2 -> V_22 = V_4 ;
}
V_6 = V_2 -> V_23 ;
} else if ( V_3 == V_2 -> V_13 -> V_16 ) {
if ( V_4 != V_2 -> V_24 ) {
V_2 -> V_25 += V_4 - V_2 -> V_24 ;
V_2 -> V_24 = V_4 ;
}
V_6 = V_2 -> V_25 ;
} else if ( V_3 == V_2 -> V_13 -> V_17 ) {
if ( V_4 != V_2 -> V_26 ) {
V_2 -> V_27 += V_4 - V_2 -> V_26 ;
V_2 -> V_26 = V_4 ;
}
V_6 = V_2 -> V_27 ;
} else if ( V_3 == V_2 -> V_13 -> V_28 ) {
if ( V_2 -> V_29 )
V_6 -= V_6 - V_2 -> V_30 ;
V_6 -= V_2 -> V_31 ;
} else if ( V_3 == V_2 -> V_13 -> V_32 ) {
if ( V_2 -> V_29 )
V_6 -= V_6 - V_2 -> V_33 ;
V_6 -= V_2 -> V_34 ;
} else
V_6 = ( T_1 ) V_4 ;
V_9 = V_6 ;
V_19:
return V_9 ;
}
static void F_6 ( struct V_1 * V_2 )
{
static T_1 V_35 ;
struct V_36 * V_37 = V_2 -> V_38 [ 0 ] ;
T_4 V_39 = 0 ;
char V_40 [ 128 ] ;
T_3 V_41 ;
* V_40 = 0 ;
if ( V_37 -> V_42 != V_2 -> V_43 ) {
V_39 = snprintf ( V_40 , sizeof V_40 , L_2 ,
V_37 -> V_42 -
V_2 -> V_43 ) ;
V_2 -> V_43 = V_37 -> V_42 ;
}
if ( V_44 . V_45 != V_2 -> V_46 ) {
V_39 += snprintf ( V_40 + V_39 , sizeof V_40 - V_39 ,
L_3 ,
V_39 ? L_4 : L_5 ,
( unsigned long long )
( V_44 . V_45 -
V_2 -> V_46 ) ) ;
V_2 -> V_46 = V_44 . V_45 ;
}
if ( ( V_47 & ( V_48 | V_49 ) ) &&
V_44 . V_50 != V_35 ) {
V_39 += snprintf ( V_40 + V_39 , sizeof V_40 - V_39 ,
L_6 ,
V_39 ? L_4 : L_5 ,
( unsigned long long )
( V_44 . V_50 -
V_35 ) ) ;
V_35 = V_44 . V_50 ;
}
if ( V_39 )
F_7 ( L_7 , V_40 ) ;
V_41 = F_8 ( V_37 ) ;
if ( V_37 -> V_51 != V_41 ) {
if ( V_2 -> V_52 ==
V_44 . V_53 ) {
F_9 ( V_54 , L_8
L_9
L_10 ,
V_37 -> V_51 , V_41 ,
( unsigned long long )
V_44 . V_53 ) ;
F_10 ( V_2 , V_55 , V_41 |
V_2 -> V_56 , V_37 -> V_57 ) ;
}
V_2 -> V_52 = V_44 . V_53 ;
}
}
static void F_11 ( struct V_1 * V_2 )
{
static T_3 V_58 ;
T_3 V_59 ;
unsigned long V_60 ;
unsigned long V_61 ;
if ( ! V_2 -> V_62 || ! ( V_2 -> V_11 & V_63 ) )
return;
V_60 = F_12 ( V_2 , V_2 -> V_64 -> V_65 ) ;
if ( V_60 == V_2 -> V_62 )
return;
V_58 ++ ;
V_61 = F_12 ( V_2 , V_2 -> V_64 -> V_66 ) ;
V_59 = F_13 ( V_2 , V_2 -> V_64 -> V_67 ) ;
F_14 ( V_2 , V_2 -> V_64 -> V_65 ,
V_2 -> V_62 ) ;
if ( ( V_61 & V_2 -> V_68 ) ||
( V_59 & V_69 ) ) {
F_14 ( V_2 , V_2 -> V_64 -> V_70 , 0ULL ) ;
F_14 ( V_2 , V_2 -> V_64 -> V_71 , 0ULL ) ;
F_14 ( V_2 , V_2 -> V_64 -> V_72 , 0ULL ) ;
F_15 ( & V_2 -> V_73 -> V_74 ,
L_11 ,
V_58 , V_60 , ( unsigned long ) V_2 -> V_62 ,
V_59 , V_61 ) ;
} else
F_7 ( L_12 ,
V_58 , V_60 ,
( unsigned long ) V_2 -> V_62 ) ;
}
void F_16 ( unsigned long V_75 )
{
struct V_1 * V_2 = (struct V_1 * ) V_75 ;
int V_76 ;
static unsigned V_77 ;
unsigned long V_78 ;
T_1 V_79 ;
if ( ! V_2 -> V_80 || ! ( V_2 -> V_11 & V_63 ) ||
V_81 )
goto V_82;
V_79 = F_1 ( V_2 , V_2 -> V_13 -> V_14 ) +
F_1 ( V_2 , V_2 -> V_13 -> V_15 ) ;
F_17 ( & V_2 -> V_83 , V_78 ) ;
V_79 -= V_2 -> V_84 ;
V_2 -> V_84 += V_79 ;
if ( V_79 >= V_85 )
F_18 ( 5 , & V_2 -> V_86 ) ;
F_19 ( & V_2 -> V_83 , V_78 ) ;
if ( V_2 -> V_11 & V_12 ) {
F_1 ( V_2 , V_2 -> V_13 -> V_16 ) ;
F_1 ( V_2 , V_2 -> V_13 -> V_17 ) ;
}
F_6 ( V_2 ) ;
if ( V_2 -> V_87 )
V_2 -> V_87 = 0 ;
if ( V_2 -> V_88 )
V_2 -> V_88 = 0 ;
if ( V_2 -> V_89
&& F_20 ( V_10 , V_2 -> V_90 ) ) {
char V_91 [ 256 ] ;
int V_92 ;
V_92 = F_21 ( V_2 , V_91 , sizeof V_91 ,
V_2 -> V_89 ) ;
if ( V_2 -> V_89 &
~ ( V_93 | V_94 |
V_95 ) )
F_5 ( V_2 , L_13
L_14 , V_91 ) ;
else {
if ( V_92 )
F_7 (
L_15 ,
V_91 ) ;
else
F_9 ( V_96 , L_16
L_17 , V_91 ) ;
}
V_2 -> V_62 |= V_2 -> V_89 ;
F_14 ( V_2 , V_2 -> V_64 -> V_65 ,
V_2 -> V_62 ) ;
V_2 -> V_89 = 0 ;
}
if ( ( ++ V_77 & 0x10 ) ) {
for ( V_76 = ( int ) V_2 -> V_97 ; -- V_76 >= 0 ; ) {
struct V_36 * V_37 = V_2 -> V_38 [ V_76 ] ;
if ( V_37 && V_37 -> V_98 != - 1 )
V_37 -> V_98 = - 1 ;
}
}
F_11 ( V_2 ) ;
V_82:
F_22 ( & V_2 -> V_99 , V_10 + V_18 * 5 ) ;
}
