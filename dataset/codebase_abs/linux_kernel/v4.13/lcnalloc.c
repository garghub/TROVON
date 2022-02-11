int F_1 ( T_1 * V_1 ,
const T_2 * V_2 )
{
struct V_3 * V_4 = V_1 -> V_5 ;
int V_6 = 0 ;
F_2 ( L_1 ) ;
if ( ! V_2 )
return 0 ;
for (; V_2 -> V_7 ; V_2 ++ ) {
int V_8 ;
if ( V_2 -> V_9 < 0 )
continue;
V_8 = F_3 ( V_4 , V_2 -> V_9 , V_2 -> V_7 ) ;
if ( F_4 ( V_8 && ( ! V_6 || V_6 == - V_10 ) && V_6 != V_8 ) )
V_6 = V_8 ;
}
F_2 ( L_2 ) ;
return V_6 ;
}
T_2 * F_5 ( T_1 * V_1 , const T_3 V_11 ,
const T_4 V_12 , const T_5 V_13 ,
const T_6 V_14 ,
const bool V_15 )
{
T_5 V_16 , V_17 , V_18 , V_19 , V_20 , V_9 ;
T_5 V_21 = 0 , V_22 = 0 , V_23 ;
T_4 V_24 ;
T_7 V_25 ;
struct V_3 * V_4 ;
T_2 * V_2 = NULL ;
struct V_26 * V_27 ;
struct V_28 * V_28 = NULL ;
T_8 * V_29 , * V_30 ;
int V_8 = 0 , V_31 , V_32 , V_33 ;
T_8 V_34 , V_35 , V_36 , V_37 = 0 , V_38 ;
F_2 ( L_3
L_4 , ( unsigned long long ) V_11 ,
( unsigned long long ) V_12 ,
( unsigned long long ) V_13 ,
V_14 == V_39 ? L_5 : L_6 ) ;
F_6 ( ! V_1 ) ;
V_4 = V_1 -> V_5 ;
F_6 ( ! V_4 ) ;
F_6 ( V_11 < 0 ) ;
F_6 ( V_12 < 0 ) ;
F_6 ( V_13 < - 1 ) ;
F_6 ( V_14 < V_40 ) ;
F_6 ( V_14 > V_41 ) ;
if ( ! V_12 )
return NULL ;
F_7 ( & V_1 -> V_42 ) ;
V_35 = 0 ;
V_34 = 1 ;
V_16 = V_13 ;
if ( V_16 < 0 ) {
if ( V_14 == V_43 )
V_16 = V_1 -> V_44 ;
else
V_16 = V_1 -> V_45 ;
if ( ! V_16 ) {
V_34 = 2 ;
}
} else if ( V_14 == V_43 && V_16 >= V_1 -> V_46 &&
V_16 < V_1 -> V_47 ) {
V_16 = V_1 -> V_47 ;
V_34 = 2 ;
} else if ( V_14 == V_39 && ( V_16 < V_1 -> V_46 ||
V_16 >= V_1 -> V_47 ) ) {
V_16 = V_1 -> V_48 ;
if ( ! V_1 -> V_47 )
V_16 = 0 ;
V_34 = 2 ;
}
if ( V_14 == V_39 ) {
V_17 = V_1 -> V_47 ;
V_36 = 1 ;
} else {
V_35 |= 1 ;
if ( V_16 >= V_1 -> V_47 ) {
V_17 = V_1 -> V_49 ;
V_36 = 2 ;
} else {
V_17 = V_1 -> V_46 ;
V_36 = 4 ;
}
}
V_18 = V_19 = V_16 ;
V_24 = V_12 ;
V_31 = V_32 = 0 ;
V_27 = V_4 -> V_50 ;
V_25 = F_8 ( V_4 ) ;
while ( 1 ) {
F_2 ( L_7
L_8
L_9
L_10 ,
V_35 , V_36 , V_34 ,
( unsigned long long ) V_16 ,
( unsigned long long ) V_17 ,
( unsigned long long ) V_19 ,
( unsigned long long ) V_18 , V_31 , V_32 ) ;
V_20 = V_18 >> 3 ;
F_2 ( L_11 ,
( unsigned long long ) V_20 ) ;
if ( V_20 > V_25 ) {
F_2 ( L_12
L_13 ) ;
goto V_51;
}
if ( F_9 ( V_28 ) ) {
if ( V_37 ) {
F_2 ( L_14 ) ;
F_10 ( V_28 ) ;
F_11 ( V_28 ) ;
V_37 = 0 ;
}
F_12 ( V_28 ) ;
}
V_28 = F_13 ( V_27 , V_20 >>
V_52 ) ;
if ( F_14 ( V_28 ) ) {
V_8 = F_15 ( V_28 ) ;
F_16 ( V_1 -> V_53 , L_15 ) ;
goto V_54;
}
V_33 = V_20 & ~ V_55 ;
V_29 = F_17 ( V_28 ) + V_33 ;
V_33 = V_56 - V_33 ;
if ( F_4 ( V_20 + V_33 > V_25 ) )
V_33 = V_25 - V_20 ;
V_33 <<= 3 ;
V_9 = V_18 & 7 ;
V_18 &= ~ ( T_5 ) 7 ;
F_2 ( L_16
L_17 , V_33 ,
( unsigned long long ) V_9 ,
( unsigned long long ) V_18 , V_37 ) ;
while ( V_9 < V_33 && V_9 + V_18 < V_17 ) {
V_30 = V_29 + ( V_9 >> 3 ) ;
F_2 ( L_18
L_19
L_20
L_21 , V_33 ,
( unsigned long long ) V_9 ,
( unsigned long long ) V_18 ,
V_37 ,
( unsigned int ) ( V_9 >> 3 ) ,
( unsigned int ) * V_30 ) ;
if ( * V_30 == 0xff ) {
V_9 = ( V_9 + 8 ) & ~ ( T_5 ) 7 ;
F_2 ( L_22 ) ;
continue;
}
V_38 = 1 << ( V_9 & 7 ) ;
F_2 ( L_23 , V_38 ) ;
if ( * V_30 & V_38 ) {
V_9 ++ ;
F_2 ( L_24 ) ;
continue;
}
if ( ( V_31 + 2 ) * sizeof( * V_2 ) > V_32 ) {
T_2 * V_57 ;
F_2 ( L_25 ) ;
if ( ! V_2 )
F_2 ( L_26
L_27 ,
( unsigned long long )
( V_9 + V_18 ) ) ;
V_57 = F_18 ( V_32 + ( int ) V_56 ) ;
if ( F_4 ( ! V_57 ) ) {
V_8 = - V_10 ;
F_16 ( V_1 -> V_53 , L_28
L_29 ) ;
goto V_54;
}
memcpy ( V_57 , V_2 , V_32 ) ;
F_19 ( V_2 ) ;
V_2 = V_57 ;
V_32 += V_56 ;
F_2 ( L_30 ,
V_32 ) ;
}
* V_30 |= V_38 ;
V_37 = 1 ;
F_2 ( L_31 ,
( unsigned int ) * V_30 ) ;
F_2 ( L_32
L_33
L_34
L_35 ,
( unsigned long long ) ( V_9 + V_18 ) ,
1ULL , ( unsigned long long ) V_21 ,
( unsigned long long ) V_9 ,
( unsigned long long ) V_18 ,
( unsigned long long ) V_22 ,
V_31 ) ;
if ( V_21 == V_9 + V_18 - V_22 && V_31 ) {
F_2 ( L_36
L_37 ,
( unsigned long long )
V_2 [ V_31 - 1 ] . V_9 ,
( unsigned long long )
V_2 [ V_31 - 1 ] . V_7 ) ;
V_2 [ V_31 - 1 ] . V_7 = ++ V_22 ;
F_2 ( L_38
L_39 ,
( unsigned long long )
V_2 [ V_31 - 1 ] . V_9 ,
( unsigned long long )
V_2 [ V_31 - 1 ] . V_7 ,
( unsigned long long )
V_22 ) ;
} else {
if ( F_9 ( V_31 ) ) {
F_2 ( L_40
L_41
L_37 ,
( unsigned long long )
V_2 [ V_31 - 1 ] . V_9 ,
( unsigned long long )
V_2 [ V_31 - 1 ] . V_7 ) ;
V_2 [ V_31 ] . V_58 = V_2 [ V_31 - 1 ] . V_58 +
V_22 ;
} else {
F_2 ( L_42
L_43 ) ;
V_2 [ V_31 ] . V_58 = V_11 ;
}
V_2 [ V_31 ] . V_9 = V_21 = V_9 + V_18 ;
V_2 [ V_31 ] . V_7 = V_22 = 1 ;
V_31 ++ ;
}
if ( ! -- V_24 ) {
T_5 V_59 ;
V_59 = V_9 + V_18 + 1 ;
F_2 ( L_44
L_45
L_46 ,
( unsigned long long ) V_59 ,
V_36 ) ;
switch ( V_36 ) {
case 1 :
F_2 ( L_47
L_48
L_27 ,
( unsigned long long )
V_1 -> V_45 ) ;
if ( V_59 >= V_1 -> V_47 ) {
V_1 -> V_45 =
V_1 -> V_48 ;
if ( ! V_1 -> V_47 )
V_1 -> V_45 = 0 ;
} else if ( ( V_19 >=
V_1 -> V_45 ||
V_59 > V_1 -> V_45 )
&& V_59 >= V_1 -> V_48 )
V_1 -> V_45 = V_59 ;
F_2 ( L_49
L_48
L_27 ,
( unsigned long long )
V_1 -> V_45 ) ;
break;
case 2 :
F_2 ( L_47
L_50
L_27 ,
( unsigned long long )
V_1 -> V_44 ) ;
if ( V_59 >= V_1 -> V_49 )
V_1 -> V_44 =
V_1 -> V_47 ;
else if ( ( V_19 >=
V_1 -> V_44 ||
V_59 > V_1 -> V_44 )
&& V_59 >= V_1 -> V_47 )
V_1 -> V_44 = V_59 ;
F_2 ( L_49
L_50
L_27 ,
( unsigned long long )
V_1 -> V_44 ) ;
break;
case 4 :
F_2 ( L_47
L_51
L_27 ,
( unsigned long long )
V_1 -> V_60 ) ;
if ( V_59 >= V_1 -> V_46 )
V_1 -> V_60 = 0 ;
else if ( V_19 >=
V_1 -> V_60 ||
V_59 > V_1 -> V_60 )
V_1 -> V_60 = V_59 ;
F_2 ( L_49
L_51
L_27 ,
( unsigned long long )
V_1 -> V_60 ) ;
break;
default:
F_20 () ;
}
F_2 ( L_52 ) ;
goto V_54;
}
V_9 ++ ;
}
V_18 += V_33 ;
F_2 ( L_53
L_54 ,
V_33 , ( unsigned long long ) V_9 ,
( unsigned long long ) V_18 , V_37 ) ;
if ( V_18 < V_17 ) {
F_2 ( L_55
L_56 ,
( unsigned long long ) V_18 ,
( unsigned long long ) V_17 ) ;
continue;
}
V_51:
F_2 ( L_57 , V_34 ) ;
if ( V_34 == 1 ) {
V_34 = 2 ;
V_17 = V_16 ;
switch ( V_36 ) {
case 1 :
V_16 = V_1 -> V_46 ;
break;
case 2 :
V_16 = V_1 -> V_47 ;
break;
case 4 :
V_16 = 0 ;
break;
default:
F_20 () ;
}
if ( V_17 < V_16 )
V_17 = V_16 ;
V_18 = V_16 ;
F_2 ( L_58
L_59
L_60 ,
( unsigned long long ) V_16 ,
( unsigned long long ) V_17 ,
( unsigned long long ) V_18 ) ;
continue;
}
V_61:
F_2 ( L_61
L_62 ,
V_36 , V_35 ,
V_35 | V_36 ) ;
V_35 |= V_36 ;
if ( V_35 < 7 ) {
F_2 ( L_63 ) ;
V_34 = 1 ;
switch ( V_36 ) {
case 1 :
F_2 ( L_64
L_65 ) ;
if ( V_31 ) {
T_5 V_59 ;
F_2 ( L_47
L_48
L_27 ,
( unsigned long long )
V_1 -> V_45 ) ;
V_59 = V_2 [ V_31 - 1 ] . V_9 +
V_2 [ V_31 - 1 ] . V_7 ;
if ( V_59 >= V_1 -> V_47 ) {
V_1 -> V_45 =
V_1 -> V_48 ;
if ( ! V_1 -> V_47 )
V_1 -> V_45 = 0 ;
} else if ( ( V_19 >=
V_1 -> V_45 ||
V_59 > V_1 -> V_45 )
&& V_59 >= V_1 -> V_48 )
V_1 -> V_45 = V_59 ;
F_2 ( L_49
L_48
L_27 ,
( unsigned long long )
V_1 -> V_45 ) ;
}
V_62: V_36 = 2 ;
V_16 = V_19 =
V_1 -> V_44 ;
V_17 = V_1 -> V_49 ;
if ( V_16 == V_1 -> V_47 )
V_34 = 2 ;
if ( V_16 >= V_17 ) {
V_1 -> V_44 = V_16 =
V_1 -> V_47 ;
V_34 = 2 ;
}
break;
case 2 :
F_2 ( L_66
L_67 ) ;
if ( V_31 ) {
T_5 V_59 ;
F_2 ( L_47
L_50
L_27 ,
( unsigned long long )
V_1 -> V_44 ) ;
V_59 = V_2 [ V_31 - 1 ] . V_9 +
V_2 [ V_31 - 1 ] . V_7 ;
if ( V_59 >= V_1 -> V_49 )
V_1 -> V_44 =
V_1 -> V_47 ;
else if ( ( V_19 >=
V_1 -> V_44 ||
V_59 > V_1 -> V_44 )
&& V_59 >= V_1 -> V_47 )
V_1 -> V_44 = V_59 ;
F_2 ( L_49
L_50
L_27 ,
( unsigned long long )
V_1 -> V_44 ) ;
}
V_36 = 4 ;
V_16 = V_19 =
V_1 -> V_60 ;
V_17 = V_1 -> V_46 ;
if ( ! V_16 )
V_34 = 2 ;
if ( V_16 >= V_17 ) {
V_1 -> V_60 = V_16 =
V_19 = 0 ;
V_34 = 2 ;
}
break;
case 4 :
F_2 ( L_68
L_69 ) ;
if ( V_31 ) {
T_5 V_59 ;
F_2 ( L_47
L_51
L_27 ,
( unsigned long long )
V_1 -> V_60 ) ;
V_59 = V_2 [ V_31 - 1 ] . V_9 +
V_2 [ V_31 - 1 ] . V_7 ;
if ( V_59 >= V_1 -> V_46 )
V_1 -> V_60 = 0 ;
else if ( V_19 >=
V_1 -> V_60 ||
V_59 > V_1 -> V_60 )
V_1 -> V_60 = V_59 ;
F_2 ( L_49
L_51
L_27 ,
( unsigned long long )
V_1 -> V_60 ) ;
}
goto V_62;
default:
F_20 () ;
}
F_2 ( L_70
L_71
L_72 ,
V_36 , V_34 ,
( unsigned long long ) V_19 ,
( unsigned long long ) V_16 ,
( unsigned long long ) V_17 ) ;
V_18 = V_16 ;
if ( V_16 == V_17 ) {
F_2 ( L_73
L_74 ) ;
goto V_61;
}
F_2 ( L_75 ) ;
continue;
}
F_2 ( L_76 ) ;
V_23 = V_1 -> V_47 - V_1 -> V_46 ;
F_2 ( L_77
L_78 ,
( unsigned long long ) V_1 -> V_46 ,
( unsigned long long ) V_1 -> V_47 ,
( unsigned long long ) V_23 ) ;
if ( V_14 == V_39 || V_23 <= 0 ) {
F_2 ( L_79 ) ;
V_8 = - V_63 ;
goto V_54;
}
F_2 ( L_80 ) ;
V_17 = V_1 -> V_47 ;
V_23 >>= 1 ;
if ( V_23 > 0 )
V_1 -> V_47 = V_1 -> V_46 + V_23 ;
else
V_1 -> V_60 = V_1 -> V_46 =
V_1 -> V_47 = 0 ;
if ( V_1 -> V_45 >= V_1 -> V_47 ) {
V_1 -> V_45 = V_1 -> V_48 ;
if ( ! V_1 -> V_47 )
V_1 -> V_45 = 0 ;
}
V_18 = V_16 = V_19 =
V_1 -> V_44 = V_1 -> V_47 ;
V_36 = 2 ;
V_34 = 2 ;
V_35 &= ~ 2 ;
F_2 ( L_81
L_82
L_83
L_84
L_85
L_86
L_87 ,
( unsigned long long ) V_23 ,
( unsigned long long ) V_1 -> V_46 ,
( unsigned long long ) V_1 -> V_47 ,
( unsigned long long ) V_1 -> V_45 ,
V_35 , ( unsigned long long ) V_16 ,
( unsigned long long ) V_17 ,
( unsigned long long ) V_1 -> V_44 ) ;
}
F_2 ( L_88 ) ;
V_54:
F_2 ( L_89 ) ;
if ( F_9 ( V_2 ) ) {
V_2 [ V_31 ] . V_58 = V_2 [ V_31 - 1 ] . V_58 + V_2 [ V_31 - 1 ] . V_7 ;
V_2 [ V_31 ] . V_9 = V_15 ? V_64 : V_65 ;
V_2 [ V_31 ] . V_7 = 0 ;
}
if ( F_9 ( V_28 && ! F_14 ( V_28 ) ) ) {
if ( V_37 ) {
F_2 ( L_14 ) ;
F_10 ( V_28 ) ;
F_11 ( V_28 ) ;
V_37 = 0 ;
}
F_12 ( V_28 ) ;
}
if ( F_9 ( ! V_8 ) ) {
F_21 ( & V_1 -> V_42 ) ;
F_2 ( L_2 ) ;
return V_2 ;
}
F_16 ( V_1 -> V_53 , L_90
L_91 , V_8 ) ;
if ( V_2 ) {
int V_66 ;
if ( V_8 == - V_63 )
F_2 ( L_92
L_93
L_94
L_95 ,
( unsigned long long ) V_2 [ 0 ] . V_9 ,
( unsigned long long ) ( V_12 - V_24 ) ) ;
F_2 ( L_96 ) ;
V_66 = F_1 ( V_1 , V_2 ) ;
if ( V_66 ) {
F_16 ( V_1 -> V_53 , L_97
L_98
L_99 , V_66 ) ;
F_22 ( V_1 ) ;
}
F_19 ( V_2 ) ;
} else if ( V_8 == - V_63 )
F_2 ( L_100
L_101 ,
( long long ) V_1 -> V_44 ) ;
F_21 ( & V_1 -> V_42 ) ;
return F_23 ( V_8 ) ;
}
T_4 F_24 ( T_9 * V_67 , const T_3 V_11 , T_4 V_12 ,
T_10 * V_68 , const bool V_69 )
{
T_4 V_70 , V_71 , V_72 , V_73 ;
T_1 * V_1 ;
struct V_3 * V_4 ;
T_2 * V_2 ;
int V_8 ;
F_6 ( ! V_67 ) ;
F_2 ( L_102
L_103 , V_67 -> V_74 , ( unsigned long long ) V_11 ,
( unsigned long long ) V_12 ,
V_69 ? L_104 : L_105 ) ;
V_1 = V_67 -> V_1 ;
V_4 = V_1 -> V_5 ;
F_6 ( ! V_4 ) ;
F_6 ( V_11 < 0 ) ;
F_6 ( V_12 < - 1 ) ;
if ( F_9 ( ! V_69 ) )
F_7 ( & V_1 -> V_42 ) ;
V_72 = V_73 = 0 ;
V_2 = F_25 ( V_67 , V_11 , V_68 ) ;
if ( F_14 ( V_2 ) ) {
if ( ! V_69 )
F_16 ( V_1 -> V_53 , L_106
L_107 ,
F_15 ( V_2 ) ) ;
V_8 = F_15 ( V_2 ) ;
goto V_75;
}
if ( F_4 ( V_2 -> V_9 < V_76 ) ) {
if ( ! V_69 )
F_16 ( V_1 -> V_53 , L_108
L_109 ) ;
V_8 = - V_77 ;
goto V_75;
}
V_70 = V_11 - V_2 -> V_58 ;
V_71 = V_2 -> V_7 - V_70 ;
if ( V_12 >= 0 && V_71 > V_12 )
V_71 = V_12 ;
if ( F_9 ( V_2 -> V_9 >= 0 ) ) {
V_8 = F_26 ( V_4 , V_2 -> V_9 + V_70 ,
V_71 , F_9 ( ! V_69 ) ? 0 : 1 ) ;
if ( F_4 ( V_8 ) ) {
if ( ! V_69 )
F_16 ( V_1 -> V_53 , L_110
L_111 , V_8 ) ;
goto V_75;
}
V_73 = V_71 ;
} ;
++ V_2 ;
if ( V_12 >= 0 )
V_12 -= V_71 ;
V_72 = V_71 ;
for (; V_2 -> V_7 && V_12 != 0 ; ++ V_2 ) {
if ( F_4 ( V_2 -> V_9 < V_76 ) ) {
T_3 V_58 ;
V_58 = V_2 -> V_58 ;
V_2 = F_25 ( V_67 , V_58 , V_68 ) ;
if ( F_14 ( V_2 ) ) {
V_8 = F_15 ( V_2 ) ;
if ( ! V_69 )
F_16 ( V_1 -> V_53 , L_112
L_113
L_114
L_115
L_116 ) ;
goto V_75;
}
if ( F_4 ( V_2 -> V_9 < V_76 ) ) {
if ( ! V_69 )
F_16 ( V_1 -> V_53 , L_117
L_118
L_119 ,
( unsigned long long )
V_2 -> V_9 ) ;
V_8 = - V_77 ;
goto V_75;
}
}
V_71 = V_2 -> V_7 ;
if ( V_12 >= 0 && V_71 > V_12 )
V_71 = V_12 ;
if ( F_9 ( V_2 -> V_9 >= 0 ) ) {
V_8 = F_26 ( V_4 , V_2 -> V_9 ,
V_71 , F_9 ( ! V_69 ) ? 0 : 1 ) ;
if ( F_4 ( V_8 ) ) {
if ( ! V_69 )
F_16 ( V_1 -> V_53 , L_120
L_121 ) ;
goto V_75;
}
V_73 += V_71 ;
}
if ( V_12 >= 0 )
V_12 -= V_71 ;
V_72 += V_71 ;
}
if ( F_9 ( ! V_69 ) )
F_21 ( & V_1 -> V_42 ) ;
F_6 ( V_12 > 0 ) ;
F_2 ( L_2 ) ;
return V_73 ;
V_75:
if ( V_69 )
return V_8 ;
if ( ! V_73 ) {
F_21 ( & V_1 -> V_42 ) ;
return V_8 ;
}
V_70 = F_24 ( V_67 , V_11 , V_72 , V_68 , true ) ;
if ( V_70 < 0 ) {
F_16 ( V_1 -> V_53 , L_122
L_123
L_124 , ( int ) V_70 ) ;
F_22 ( V_1 ) ;
}
F_21 ( & V_1 -> V_42 ) ;
F_16 ( V_1 -> V_53 , L_125 , V_8 ) ;
return V_8 ;
}
