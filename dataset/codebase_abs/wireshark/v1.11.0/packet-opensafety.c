static void
F_1 ( void )
{
V_1 = FALSE ;
}
static void
F_2 ( void )
{
if ( V_2 != NULL )
V_2 = NULL ;
F_3 ( & V_3 , & V_4 ) ;
}
static T_1
F_4 ( T_2 * V_5 , T_1 V_6 , T_3 V_7 , T_4 V_8 )
{
T_1 V_9 = 0 ;
T_1 V_10 , V_11 = 0 ;
T_1 V_12 = 0 , V_13 = 0 , V_14 = 0 ;
T_3 V_15 = 0 ;
T_3 * V_16 = NULL ;
V_9 = V_7 / 2 + 1 ;
V_10 = F_5 ( V_5 , V_6 + V_9 + 2 ) ;
V_11 = V_10 * 2 + 11 + 2 * ( V_10 > V_17 ? 1 : 0 ) ;
if ( V_8 && V_11 == V_7 )
{
if ( V_7 > V_17 )
V_14 = F_6 ( V_5 , V_6 + V_9 + V_7 + V_18 ) ;
else
V_14 = F_5 ( V_5 , V_6 + V_9 + V_7 + V_18 ) ;
V_16 = ( T_3 * ) F_7 ( F_8 () , V_5 , V_6 + V_9 , V_7 + 4 ) ;
if ( V_7 > V_17 )
{
V_13 = F_9 ( V_16 , V_7 + 4 , 0 ) ;
if ( V_14 != V_13 )
V_13 = F_10 ( V_16 , V_7 + 4 , 0 ) ;
}
else
V_13 = F_11 ( V_16 , V_7 + 4 , 0 ) ;
if ( V_14 != V_13 )
V_7 = 0 ;
}
if ( V_11 != V_7 )
{
V_9 = 0 ;
V_12 = V_19 + ( V_7 < ( V_20 + 1 ) ? 0 : 1 ) ;
V_15 = ( F_5 ( V_5 , V_6 + V_12 + 1 ) ) & 0xFC ;
if ( ( ( V_15 ^ V_21 ) == 0 ) ||
( ( V_15 ^ V_22 ) == 0 ) )
{
V_9 = V_12 ;
}
}
return V_9 ;
}
static T_3 F_12 ( T_2 * V_5 , T_5 V_23 , T_4 V_24 , T_5 * V_25 , T_5 * V_26 )
{
T_5 V_27 , V_28 ;
T_1 V_29 , V_30 , V_31 ;
T_3 V_32 , V_33 ;
T_3 * V_16 ;
T_5 V_34 ;
T_4 V_35 ;
V_35 = 0 ;
V_27 = V_23 ;
V_28 = F_13 ( V_5 , V_27 ) ;
while ( V_28 >= V_36 )
{
if ( V_27 != 0 )
{
* V_26 = 0 ;
* V_25 = 0 ;
V_33 = 0 ;
V_34 = F_5 ( V_5 , V_27 ) ;
if ( V_34 != 0x0 )
{
V_32 = F_5 ( V_5 , V_27 + 1 ) ;
if ( ( V_34 != 0xFF ) && ( V_34 & 0x80 ) )
{
V_28 = F_13 ( V_5 , V_27 ) ;
if ( ( V_32 <= ( T_5 ) 8 && ( V_32 <= V_28 ) ) ||
( V_32 > ( T_5 ) 8 && ( ( V_32 + ( T_5 ) 5 ) <= V_28 ) ) )
{
if ( F_14 ( V_5 , V_27 - 1 , V_32 + 5 ) )
{
if ( ( ( V_34 >> 4 ) != 0x09 ) && ( ( V_34 >> 4 ) != 0x0F ) )
{
V_29 = F_5 ( V_5 , V_27 + 3 + V_32 ) ;
V_16 = ( T_3 * ) F_7 ( F_8 () , V_5 , V_27 - 1 , V_32 + 5 ) ;
if ( V_32 > 8 ) {
V_29 = F_6 ( V_5 , V_27 + 3 + V_32 ) ;
V_33 = 1 ;
V_31 = F_9 ( V_16 , V_32 + 4 , 0 ) ;
if ( ( V_29 ^ V_31 ) != 0 )
V_31 = F_10 ( V_16 , V_32 + 4 , 0 ) ;
} else {
V_31 = F_11 ( V_16 , V_32 + 4 , 0 ) ;
}
if ( ( V_29 ^ V_31 ) == 0 )
{
if ( ( V_34 >> 3 ) == ( V_37 >> 3 ) )
{
if ( V_32 > 0 )
{
* V_25 = ( V_27 - 1 ) ;
* V_26 = V_32 + 2 * V_33 + 11 ;
V_30 = F_5 ( V_5 , V_27 + 3 + 5 + V_32 ) ;
if ( V_32 > 8 )
V_30 = F_6 ( V_5 , V_27 + 3 + 5 + V_32 ) ;
if ( V_29 != V_30 )
{
V_35 = 1 ;
break;
}
}
}
else
{
* V_26 = 2 * V_32 + 2 * V_33 + 11 ;
* V_25 = ( V_27 - 1 ) ;
if ( F_5 ( V_5 , * V_25 + * V_26 - 2 ) != 0x00 ||
F_5 ( V_5 , * V_25 + * V_26 - 1 ) != 0x00 )
{
V_35 = 1 ;
break;
}
}
}
}
}
}
}
else
{
if ( V_28 == V_36 )
{
V_34 = F_5 ( V_5 , V_27 ) ;
V_32 = F_5 ( V_5 , V_27 + 2 ) ;
if ( ( V_34 >> 3 ) == ( V_37 >> 3 ) )
V_32 = ( 11 + ( V_32 > 8 ? 2 : 0 ) + V_32 ) ;
else
V_32 = ( 11 + ( V_32 > 8 ? 2 : 0 ) + 2 * V_32 ) ;
if ( V_28 == V_32 )
{
V_27 ++ ;
V_28 ++ ;
continue;
}
}
}
}
}
V_27 ++ ;
V_28 = F_13 ( V_5 , V_27 ) ;
}
if ( V_24 && V_35 )
* V_25 = V_23 ;
return ( V_35 ? 1 : 0 ) ;
}
static void
F_15 ( T_2 * V_5 , T_6 * V_38 , T_7 * V_39 ,
T_1 V_40 , T_1 V_41 , T_4 V_42 , T_3 V_43 [ 6 ] )
{
T_8 * V_44 ;
T_7 * V_45 ;
T_1 V_46 ;
T_9 V_47 ;
T_5 V_7 ;
T_3 V_48 , V_34 , V_49 ;
V_7 = F_5 ( V_5 , V_50 + V_40 ) ;
V_34 = F_5 ( V_5 , V_40 + 1 ) & 0xF8 ;
V_49 = ( ( F_5 ( V_5 , V_40 + 1 ) & 0x04 ) == 0x04 ) ;
V_46 = F_5 ( V_5 , V_40 + 3 ) ;
if ( V_42 )
V_46 = ( T_1 ) ( ( F_5 ( V_5 , V_41 + 2 ) ^ V_43 [ 2 ] ) << 8 ) +
( F_5 ( V_5 , V_40 + 3 ) ) ;
V_47 = ( ( F_16 ( V_5 , V_40 ) ) ^ ( F_17 ( V_5 , V_41 , V_43 [ 0 ] , V_43 [ 1 ] ) ) ) ;
if ( ! V_42 )
V_47 = ( - 1 * V_47 ) ;
F_18 ( V_38 , F_16 ( V_5 , V_40 ) , V_51 + V_40 , V_41 , V_47 ) ;
V_44 = F_19 ( V_39 , V_52 , V_5 ,
V_53 + V_40 , 1 , V_54 ,
L_1 , F_20 ( V_54 , V_55 , L_2 ) ) ;
F_21 ( V_44 ) ;
V_45 = F_22 ( V_44 , V_56 ) ;
if ( V_34 == V_57 )
F_23 ( V_45 , V_58 , V_5 ,
V_53 + V_40 , 1 , V_59 ) ;
else if ( V_34 == V_60 || V_34 == V_61 )
F_23 ( V_45 , V_58 , V_5 ,
V_53 + V_40 , 1 , V_62 ) ;
F_19 ( V_45 , V_63 , V_5 , V_53 + V_40 , 1 ,
V_34 , L_1 , F_20 ( V_34 , V_64 , L_2 ) ) ;
F_24 ( V_45 , V_65 , V_5 ,
V_51 + V_40 , 2 , F_16 ( V_5 , V_40 ) ) ;
F_23 ( V_45 , V_66 , V_5 ,
V_53 + V_40 , 1 , V_49 ) ;
V_47 = F_17 ( V_5 , V_41 + 3 , V_43 [ 3 ] , V_43 [ 4 ] ) ;
V_48 = ( F_5 ( V_5 , V_41 + 4 ) ^ V_43 [ 4 ] ) & 0xFC ;
if ( V_34 == V_60 )
{
V_44 = F_19 ( V_45 , V_67 , V_5 , 0 , 0 , V_46 ,
L_3 , V_46 , V_46 ,
( V_42 ? L_4 : L_5 ) ) ;
F_21 ( V_44 ) ;
F_24 ( V_45 , V_68 , V_5 ,
V_51 + V_41 + 4 , 1 , V_48 ) ;
F_24 ( V_45 , V_69 , V_5 ,
V_51 + V_41 + 3 , 2 , V_47 ) ;
}
else
{
V_44 = F_19 ( V_45 , V_70 , V_5 , 0 , 0 , V_46 ,
L_3 , V_46 , V_46 , ( V_42 ? L_4 : L_5 ) ) ;
F_21 ( V_44 ) ;
if ( V_34 == V_57 )
{
F_24 ( V_45 , V_68 , V_5 , V_51 + V_41 + 4 , 1 , V_48 ) ;
F_24 ( V_45 , V_71 , V_5 , V_51 + V_41 + 3 , 2 , V_47 ) ;
}
}
if ( V_7 > 0 )
F_25 ( V_45 , V_72 , V_5 , V_53 + 3 , V_7 , V_73 ) ;
}
static void F_26 ( T_6 * V_38 , T_2 * V_74 , T_7 * V_75 , T_3 V_76 )
{
T_5 V_7 = 0 , V_27 = 0 , V_77 = 0 ;
T_3 V_78 = 0 ;
T_1 V_79 = 0 , V_80 = 0 ;
T_10 V_81 = 0 , V_82 = 0 ;
T_8 * V_44 ;
T_7 * V_83 , * V_84 ;
V_7 = F_27 ( V_74 ) ;
V_79 = F_6 ( V_74 , 0 ) ;
V_81 = F_28 ( V_74 , 4 ) ;
if ( V_7 == 16 || V_81 == ( V_7 - 16 ) || V_79 == 0x0101 )
{
V_44 = F_29 ( V_75 , V_85 ,
V_74 , 0 , V_7 , L_6 , L_7 ,
( V_7 == 16 ? L_8 : L_9 ) ) ;
V_84 = F_22 ( V_44 , V_86 ) ;
F_25 ( V_84 , V_87 , V_74 , 0 , 1 , V_88 ) ;
F_25 ( V_84 , V_89 , V_74 , 1 , 1 , V_88 ) ;
F_25 ( V_84 , V_90 , V_74 , 2 , 2 , V_91 ) ;
F_19 ( V_84 , V_92 ,
V_74 , 4 , 4 , V_81 , L_10 ,
V_81 , V_81 ) ;
F_25 ( V_84 , V_93 , V_74 , 8 , 4 , V_91 ) ;
F_25 ( V_84 , V_94 , V_74 , 12 , 4 , V_91 ) ;
if ( V_7 != 16 )
{
V_44 = F_25 ( V_84 , V_95 , V_74 , 16 , V_7 - 16 , V_73 ) ;
if ( ( V_7 - V_81 ) != 16 )
F_30 ( V_38 , V_44 , & V_96 ) ;
}
}
else
{
if ( V_76 == V_97 && ( V_7 % 4 == 0 ) )
{
V_44 = F_19 ( V_75 , V_98 , V_74 ,
0 , 0 , 0x1018 , L_11 , 0x1018 ,
F_20 ( ( ( T_10 ) ( 0x1018 << 16 ) ) ,
V_99 , L_2 ) ) ;
V_83 = F_22 ( V_44 , V_100 ) ;
F_21 ( V_44 ) ;
V_44 = F_19 ( V_83 , V_101 , V_74 , 0 , 0 ,
0x06 , L_12 , 0x06 ,
F_20 ( ( ( T_10 ) ( 0x1018 << 16 ) + 0x06 ) ,
V_99 , L_2 ) ) ;
F_21 ( V_44 ) ;
V_82 = F_28 ( V_74 , 0 ) ;
F_19 ( V_83 , V_102 , V_74 , 0 ,
4 , V_82 , L_13 , V_82 ) ;
for ( V_77 = 4 ; V_77 < V_7 ; V_77 += 4 )
{
V_82 = F_28 ( V_74 , V_77 ) ;
F_19 ( V_83 , V_103 , V_74 , ( V_77 ) ,
4 , V_82 , L_14 , ( V_77 / 4 ) , V_82 ) ;
}
}
else
{
for ( V_27 = 0 ; V_27 < V_7 ; V_27 ++ )
{
V_79 = F_6 ( V_74 , V_27 ) ;
V_78 = F_5 ( V_74 , V_27 + 2 ) ;
V_80 = V_79 ;
if ( V_79 >= 0x1400 && V_79 <= 0x17FE )
V_80 = 0x1400 ;
else if ( V_79 >= 0x1800 && V_79 <= 0x1BFE )
V_80 = 0x1800 ;
else if ( V_79 >= 0x1C00 && V_79 <= 0x1FFE )
V_80 = 0x1C00 ;
else if ( V_79 >= 0xC000 && V_79 <= 0xC3FE )
V_80 = 0xC000 ;
V_44 = F_19 ( V_75 , V_98 , V_74 ,
V_27 , 2 , V_79 , L_11 , V_79 ,
F_20 ( ( ( T_10 ) ( V_80 << 16 ) ) ,
V_99 , L_2 ) ) ;
if ( V_79 != V_80 )
F_21 ( V_44 ) ;
if ( V_79 < 0x1000 || V_79 > 0xE7FF )
F_30 ( V_38 , V_44 , & V_104 ) ;
V_83 = F_22 ( V_44 , V_100 ) ;
if ( V_78 != 0 )
{
F_19 ( V_83 , V_101 , V_74 , V_27 + 2 , 1 ,
V_78 , L_12 , V_78 ,
F_20 ( ( ( T_10 ) ( V_79 << 16 ) + V_78 ) ,
V_99 , L_2 ) ) ;
}
else
F_19 ( V_83 , V_101 , V_74 , V_27 + 2 , 1 ,
V_78 , L_15 , V_78 ) ;
V_27 += 2 ;
V_81 = F_28 ( V_74 , V_27 + 1 ) ;
if ( V_81 > ( V_7 - V_27 ) )
V_81 = 0 ;
if ( ( V_81 + 4 + V_27 ) > V_7 )
break;
if ( V_79 == V_105 && V_78 == 0x06 )
{
V_82 = F_28 ( V_74 , V_27 + 5 ) ;
F_19 ( V_83 , V_102 , V_74 , V_27 + 5 ,
4 , V_82 , L_13 , V_82 ) ;
for ( V_77 = 4 ; V_77 < V_81 ; V_77 += 4 )
{
V_82 = F_28 ( V_74 , V_27 + 5 + V_77 ) ;
F_19 ( V_83 , V_103 , V_74 , ( V_27 + 5 + V_77 ) ,
4 , V_82 , L_14 , ( V_77 / 4 ) , V_82 ) ;
}
} else if ( V_79 == V_105 && V_78 == 0x07 ) {
V_82 = F_28 ( V_74 , V_27 + 5 ) ;
F_19 ( V_83 , V_102 , V_74 , V_27 + 5 ,
4 , V_82 , L_13 , V_82 ) ;
} else if ( ( V_80 == V_106 || V_80 == V_107 ) && V_78 != 0x0 ) {
F_24 ( V_83 , V_108 , V_74 , V_27 + 1 , 4 , V_81 ) ;
V_44 = F_25 ( V_83 , V_109 , V_74 , V_27 + 5 , V_81 , V_73 ) ;
V_84 = F_22 ( V_44 , V_110 ) ;
F_25 ( V_84 , V_111 , V_74 , V_27 + 5 , 1 , V_73 ) ;
V_82 = F_28 ( V_74 , V_27 + 7 ) ;
F_25 ( V_84 , V_98 , V_74 , V_27 + 7 , 2 , V_82 ) ;
F_25 ( V_84 , V_101 , V_74 , V_27 + 6 , 1 , V_73 ) ;
} else {
F_24 ( V_83 , V_108 , V_74 , V_27 + 1 , 4 , V_81 ) ;
if ( V_81 > 0 )
F_25 ( V_83 , V_112 , V_74 , V_27 + 5 , V_81 , V_73 ) ;
}
V_27 += V_81 + 4 ;
}
}
}
}
static void
F_31 ( T_2 * V_5 , T_6 * V_38 , T_7 * V_39 ,
T_1 V_40 , T_1 V_41 , T_4 V_42 , T_3 V_43 [ 6 ] )
{
T_8 * V_44 ;
T_7 * V_113 , * V_75 , * V_114 ;
T_1 V_47 = 0 , V_115 = 0 , V_116 = 0 , V_117 = 0 , V_77 = 0 , V_46 = 0 ;
T_10 V_118 , V_79 = 0 , V_78 = 0 , V_119 , V_120 = 0 , V_82 = 0 ;
T_3 V_121 , V_122 , V_76 , V_123 ;
T_5 V_7 ;
T_11 V_124 ;
T_4 V_125 , V_126 , V_127 , V_128 , V_129 ;
T_2 * V_74 = NULL ;
T_12 * V_130 = NULL ;
V_7 = F_5 ( V_5 , V_50 + V_40 ) ;
V_126 = FALSE ;
V_121 = V_40 + V_18 ;
V_122 = F_5 ( V_5 , V_121 ) ;
V_76 = V_122 ;
V_79 = 0 ;
V_78 = 0 ;
if ( ( V_76 & V_131 ) == V_131 )
V_76 = V_76 & ( ~ V_131 ) ;
V_125 = ( ( F_32 ( V_5 , V_40 ) & 0x04 ) == 0x04 ) ;
if ( V_42 )
{
V_47 = F_17 ( V_5 , V_41 + 3 , V_43 [ 3 ] , V_43 [ 4 ] ) ;
V_115 = ( F_16 ( V_5 , V_40 ) ^
( F_17 ( V_5 , V_41 , V_43 [ 0 ] , V_43 [ 1 ] ) ) ) ;
F_33 ( V_38 , V_47 , V_41 + 3 , F_16 ( V_5 , V_40 ) ,
V_40 , V_41 , V_115 ) ;
}
else if ( ! V_125 )
{
F_18 ( V_38 , F_16 ( V_5 , V_40 ) , V_40 , V_41 ,
- 1 * ( ( F_16 ( V_5 , V_40 ) ) ^ ( F_17 ( V_5 , V_41 , V_43 [ 0 ] , V_43 [ 1 ] ) ) ) ) ;
}
else if ( V_125 )
{
F_34 ( V_38 , F_16 ( V_5 , V_40 ) , V_40 , V_41 ,
- 1 * ( ( F_16 ( V_5 , V_40 ) ) ^ ( F_17 ( V_5 , V_41 , V_43 [ 0 ] , V_43 [ 1 ] ) ) ) ) ;
}
if ( ( F_32 ( V_5 , V_40 ) == V_21 ) ||
( F_32 ( V_5 , V_40 ) == V_22 ) )
V_44 = F_19 ( V_39 , V_52 , V_5 ,
V_53 + V_40 , 1 ,
V_37 ,
L_1 , F_20 ( V_37 , V_55 , L_2 ) ) ;
else
V_44 = F_19 ( V_39 , V_52 , V_5 , V_53 + V_40 , 1 ,
V_132 ,
L_1 , F_20 ( V_132 , V_55 , L_2 ) ) ;
F_21 ( V_44 ) ;
V_113 = F_22 ( V_44 , V_133 ) ;
if ( ( F_32 ( V_5 , V_40 ) == V_134 ) ||
( F_32 ( V_5 , V_40 ) == V_22 ) )
F_23 ( V_113 , V_58 , V_5 , V_53 + V_40 , 1 , V_59 ) ;
else
F_23 ( V_113 , V_58 , V_5 , V_53 + V_40 , 1 , V_62 ) ;
F_19 ( V_113 , V_63 , V_5 , V_53 + V_40 , 1 ,
F_32 ( V_5 , V_40 ) ,
L_1 , F_20 ( F_32 ( V_5 , V_40 ) , V_64 , L_2 ) ) ;
if ( V_125 )
{
if ( V_42 )
{
F_24 ( V_113 , V_135 , V_5 , V_40 , 2 , F_16 ( V_5 , V_40 ) ) ;
V_117 = F_16 ( V_5 , V_40 ) ;
F_24 ( V_113 , V_136 , V_5 , V_41 + 3 , 2 , V_47 ) ;
V_116 = V_47 ;
}
else
{
F_24 ( V_113 , V_135 , V_5 , V_40 , 2 , F_16 ( V_5 , V_40 ) ) ;
V_117 = F_16 ( V_5 , V_40 ) ;
}
}
else if ( ! V_125 )
{
if ( V_42 )
{
F_24 ( V_113 , V_136 , V_5 , V_40 , 2 , F_16 ( V_5 , V_40 ) ) ;
V_116 = F_16 ( V_5 , V_40 ) ;
F_24 ( V_113 , V_135 , V_5 , V_41 + 3 , 2 , V_47 ) ;
V_117 = V_47 ;
}
else
{
F_24 ( V_113 , V_136 , V_5 , V_40 , 2 , F_16 ( V_5 , V_40 ) ) ;
V_116 = F_16 ( V_5 , V_40 ) ;
}
}
V_44 = F_24 ( V_113 , V_137 , V_5 , V_121 , 1 , V_76 ) ;
F_35 ( V_38 -> V_138 , V_139 , L_16 , F_20 ( V_76 , V_140 , L_17 ) ) ;
V_114 = F_22 ( V_44 , V_141 ) ;
F_23 ( V_114 , V_142 , V_5 , V_121 , 1 , V_122 ) ;
F_23 ( V_114 , V_143 , V_5 , V_121 , 1 , V_122 ) ;
F_23 ( V_114 , V_144 , V_5 , V_121 , 1 , V_122 ) ;
F_23 ( V_114 , V_145 , V_5 , V_121 , 1 , V_122 ) ;
F_23 ( V_114 , V_146 , V_5 , V_121 , 1 , V_122 ) ;
F_23 ( V_114 , V_147 , V_5 , V_121 , 1 , V_122 ) ;
F_23 ( V_114 , V_148 , V_5 , V_121 , 1 , V_122 ) ;
V_123 = V_121 + 1 ;
V_46 = F_5 ( V_5 , V_40 + 3 ) ;
if ( V_42 )
V_46 = ( T_1 ) ( ( F_5 ( V_5 , V_41 + 2 ) ^ V_43 [ 2 ] ) << 8 ) + ( F_5 ( V_5 , V_40 + 3 ) ) ;
F_24 ( V_113 , V_149 , V_5 , V_40 + 3 , 1 , V_46 ) ;
if ( ( ( V_76 & V_150 ) == V_150 ) &&
( V_76 != V_151 )
)
{
V_79 = F_6 ( V_5 , V_121 + 1 ) ;
V_78 = F_5 ( V_5 , V_121 + 3 ) ;
F_19 ( V_113 , V_98 , V_5 , V_121 + 1 , 2 ,
V_79 , L_11 , V_79 ,
F_20 ( ( ( T_10 ) ( V_79 << 16 ) ) , V_99 , L_2 ) ) ;
F_35 ( V_38 -> V_138 , V_139 , L_18 , F_20 ( ( ( T_10 ) ( V_79 << 16 ) ) , V_99 , L_2 ) ) ;
if ( V_78 != 0x0 )
{
F_19 ( V_113 , V_101 , V_5 , V_121 + 3 , 1 ,
V_78 , L_12 , V_78 ,
F_20 ( ( ( T_10 ) ( V_79 << 16 ) + V_78 ) , V_99 , L_2 ) ) ;
F_35 ( V_38 -> V_138 , V_139 , L_19 ,
F_20 ( ( ( T_10 ) ( V_79 << 16 ) + V_78 ) , V_99 , L_2 ) ) ;
}
F_35 ( V_38 -> V_138 , V_139 , L_1 , L_20 ) ;
V_123 += 3 ;
}
if ( V_76 == V_151 )
{
V_118 = F_28 ( V_5 , V_40 + V_18 + 4 ) ;
F_19 ( V_113 , V_152 , V_5 , V_40 + V_18 + 4 , 4 , V_118 ,
L_21 , ( T_1 ) ( V_118 >> 16 ) , ( T_1 ) ( V_118 ) ,
F_20 ( V_118 , V_153 , L_2 ) ) ;
F_35 ( V_38 -> V_138 , V_139 , L_19 , F_20 ( V_118 , V_153 , L_2 ) ) ;
} else {
if ( ( V_125 && ( V_76 == V_154 ||
V_76 == V_155 ||
V_76 == V_156 ||
V_76 == V_97 ) ) ||
( ! V_125 && ( V_76 == V_157 ||
V_76 == V_158 ||
V_76 == V_159 ||
V_76 == V_160 ) ) )
{
V_126 = TRUE ;
}
if ( V_126 )
{
V_129 = V_38 -> V_161 ;
if ( V_116 != 0 && V_117 != 0 )
V_120 = ( T_10 ) ( ( ( ( T_10 ) V_117 ) << 16 ) + V_116 ) ;
V_128 = ( ( V_122 & V_162 ) == V_162 ) ;
if ( ( V_76 == V_157 ) ||
( V_76 == V_154 )
)
{
V_123 += 4 ;
V_119 = F_28 ( V_5 , V_123 - 4 ) ;
V_124 = V_7 - ( V_123 - V_121 ) ;
V_44 = F_19 ( V_113 , V_163 , V_5 , V_123 - 4 , 4 ,
V_119 , L_22 , V_119 , V_124 ) ;
if ( V_120 != 0 && V_128 )
{
V_38 -> V_161 = TRUE ;
V_130 = F_36 ( & V_3 , V_5 , V_123 , V_38 ,
V_120 , NULL , 0 , V_124 , TRUE ) ;
F_37 ( & V_3 , V_38 , V_120 , NULL , V_46 ) ;
if ( V_130 != NULL )
{
V_44 = F_38 ( V_113 , V_164 , V_5 , 0 , 0 , NULL , L_23 ) ;
F_21 ( V_44 ) ;
V_75 = F_22 ( V_44 , V_165 ) ;
F_39 ( V_5 , 0 , V_38 , L_24 , V_130 , & V_166 , NULL , V_75 ) ;
}
}
if ( ( T_11 ) V_124 >= ( T_11 ) 0 )
{
F_25 ( V_113 , V_164 , V_5 , V_123 , V_124 , V_73 ) ;
} else {
F_40 ( V_38 , V_44 , & V_167 ,
L_25 , ( T_5 ) V_124 ) ;
}
}
else
{
V_127 = FALSE ;
if ( ( V_76 == V_160 ) || ( V_76 == V_97 ) )
V_127 = TRUE ;
V_119 = V_7 - ( V_123 - V_121 ) ;
if ( V_120 != 0 && V_128 )
{
V_38 -> V_161 = TRUE ;
V_130 = F_36 ( & V_3 , V_5 , V_123 , V_38 ,
V_120 , NULL , V_46 ,
V_119 , V_127 ? FALSE : TRUE ) ;
}
if ( V_130 )
{
V_44 = F_38 ( V_113 , V_164 , V_5 ,
0 , 0 , NULL , L_23 ) ;
F_21 ( V_44 ) ;
V_75 = F_22 ( V_44 , V_165 ) ;
V_74 = F_39 ( V_5 , 0 , V_38 , L_24 , V_130 ,
& V_166 , NULL , V_75 ) ;
if ( V_127 && V_74 )
{
V_44 = F_19 ( V_75 , V_163 , V_5 , 0 , 0 ,
V_119 , L_26 , V_130 -> V_168 ) ;
F_21 ( V_44 ) ;
F_41 ( V_38 -> V_138 , V_139 , L_27 ) ;
F_26 ( V_38 , V_74 , V_75 , V_76 ) ;
}
}
else
{
V_44 = F_19 ( V_113 , V_163 , V_5 , 0 , 0 , V_119 ,
L_28 , V_119 ) ;
F_21 ( V_44 ) ;
if ( V_79 == V_105 && V_78 == 0x06 )
{
V_82 = F_28 ( V_5 , V_123 ) ;
F_19 ( V_113 , V_102 , V_5 , V_123 ,
4 , V_82 , L_13 , V_82 ) ;
for ( V_77 = 4 ; V_77 < V_119 ; V_77 += 4 )
{
V_82 = F_28 ( V_5 , V_123 + V_77 ) ;
F_19 ( V_113 , V_103 , V_5 , ( V_123 + V_77 ) ,
4 , V_82 , L_14 , ( V_77 / 4 ) , V_82 ) ;
}
} else if ( V_79 == V_105 && V_78 == 0x07 ) {
V_82 = F_28 ( V_5 , V_123 ) ;
F_19 ( V_113 , V_102 , V_5 , V_123 ,
4 , V_82 , L_13 , V_82 ) ;
} else
F_25 ( V_113 , V_164 , V_5 , V_123 , V_119 , V_73 ) ;
}
}
V_38 -> V_161 = V_129 ;
}
}
}
static void
F_42 ( T_2 * V_5 , T_6 * V_38 , T_7 * V_39 ,
T_1 V_40 , T_1 V_41 )
{
T_8 * V_44 ;
T_7 * V_169 ;
T_10 V_82 = 0 ;
T_1 V_170 , V_47 , V_115 ;
T_3 V_122 , V_171 ;
T_5 V_7 ;
char * V_172 ;
V_7 = F_43 ( V_5 , V_40 ) ;
V_170 = F_16 ( V_5 , V_40 ) ;
V_47 = F_16 ( V_5 , V_41 + 3 ) ;
V_115 = F_16 ( V_5 , V_41 ) ^ V_170 ;
V_122 = - 1 ;
if ( V_7 > 0 )
V_122 = F_5 ( V_5 , V_40 + V_18 ) ;
if ( ( ( F_32 ( V_5 , V_40 ) ^ V_173 ) == 0 ) &&
( ( V_122 ^ V_174 ) == 0 || ( V_122 ^ V_175 ) == 0 ) )
{
F_34 ( V_38 , V_170 , V_51 + V_40 , V_41 , V_115 ) ;
}
else
{
F_33 ( V_38 , V_47 , V_51 + V_40 , V_170 , V_41 + 3 ,
V_41 , V_115 ) ;
}
V_44 = F_19 ( V_39 , V_52 , V_5 , V_53 + V_40 , 1 ,
V_176 ,
L_1 , F_20 ( V_176 , V_55 , L_2 ) ) ;
F_21 ( V_44 ) ;
V_169 = F_22 ( V_44 , V_177 ) ;
if ( ( F_32 ( V_5 , V_40 ) == V_178 ) ||
( F_32 ( V_5 , V_40 ) == V_179 ) ||
( F_32 ( V_5 , V_40 ) == V_173 ) )
F_23 ( V_169 , V_58 , V_5 , V_53 + V_40 , 1 , V_59 ) ;
else
F_23 ( V_169 , V_58 , V_5 , V_53 + V_40 , 1 , V_62 ) ;
F_19 ( V_169 , V_63 , V_5 , V_53 + V_40 , 1 ,
F_32 ( V_5 , V_40 ) ,
L_1 , F_20 ( F_32 ( V_5 , V_40 ) , V_64 , L_2 ) ) ;
if ( ( F_32 ( V_5 , V_40 ) ^ V_180 ) == 0 )
{
F_24 ( V_169 , V_181 , V_5 , V_51 + V_40 , 2 , V_170 ) ;
F_24 ( V_169 , V_182 , V_5 , V_41 + 3 , 2 , V_47 ) ;
}
else if ( ( F_32 ( V_5 , V_40 ) ^ V_173 ) == 0 )
{
F_24 ( V_169 , V_183 , V_5 , V_18 + V_40 , 1 , V_122 ) ;
F_35 ( V_38 -> V_138 , V_139 , L_29 , F_20 ( V_122 , V_184 , L_2 ) ) ;
F_24 ( V_169 , V_181 , V_5 , V_51 + V_40 , 2 , V_170 ) ;
F_24 ( V_169 , V_182 , V_5 , V_41 + 3 , 2 , V_47 ) ;
if ( ( V_122 ^ V_185 ) == 0 )
{
V_171 = F_5 ( V_5 , V_18 + V_40 + 1 ) ;
F_19 ( V_169 , V_186 , V_5 , V_18 + V_40 + 1 , 1 ,
V_171 , L_1 , ( V_171 == 0 ? L_30 : F_44 ( V_171 , V_187 , L_31 ) ) ) ;
V_171 = F_5 ( V_5 , V_18 + V_40 + 2 ) ;
F_19 ( V_169 , V_188 , V_5 , V_18 + V_40 + 2 , 1 ,
V_171 , L_32 , ( V_171 == 0 ? L_33 : L_34 ) , V_171 ) ;
F_35 ( V_38 -> V_138 , V_139 , L_35 ,
( V_171 == 0 ? L_30 : F_44 ( V_171 , V_187 , L_31 ) ) ,
( V_171 == 0 ? L_33 : L_34 )
) ;
}
else if ( ( V_122 ^ V_189 ) == 0 )
{
V_44 = F_25 ( V_169 , V_190 , V_5 , V_18 + V_40 + 1 , 6 , V_73 ) ;
if ( V_191 == TRUE )
{
V_172 = ( char * ) F_45 ( F_8 () , 128 * sizeof( char ) ) ;
F_46 ( V_172 , 18 , L_1 , F_47 ( V_5 , V_18 + V_40 + 1 , 6 , ':' ) ) ;
if ( memcmp ( V_192 , V_172 , 17 ) != 0 )
{
V_2 = ( char * ) F_45 ( F_48 () , 18 * sizeof( char ) ) ;
F_46 ( V_2 , 18 , L_1 , V_172 ) ;
F_40 ( V_38 , V_44 , & V_193 , L_36 , V_172 ) ;
}
}
}
}
else if ( ( F_32 ( V_5 , V_40 ) ^ V_194 ) == 0 )
{
F_24 ( V_169 , V_183 , V_5 , V_18 + V_40 , 1 , V_122 ) ;
F_35 ( V_38 -> V_138 , V_139 , L_29 , F_20 ( V_122 , V_184 , L_2 ) ) ;
if ( ( V_122 ^ V_174 ) == 0 || ( V_122 ^ V_175 ) == 0 )
{
F_24 ( V_169 , V_195 , V_5 , V_51 + V_40 , 2 , V_170 ) ;
F_24 ( V_169 , V_196 , V_5 , V_41 + 3 , 2 , V_47 ) ;
}
else if ( ( V_122 ^ V_197 ) == 0 )
{
F_24 ( V_169 , V_181 , V_5 , V_51 + V_40 , 2 , V_170 ) ;
F_24 ( V_169 , V_182 , V_5 , V_41 + 3 , 2 , V_47 ) ;
V_44 = F_25 ( V_169 , V_190 , V_5 , V_18 + V_40 + 1 , 6 , V_73 ) ;
if ( V_191 == TRUE )
{
V_172 = ( char * ) F_45 ( F_8 () , 18 * sizeof( char ) ) ;
F_46 ( V_172 , 18 , L_1 , F_47 ( V_5 , V_18 + V_40 + 1 , 6 , ':' ) ) ;
if ( memcmp ( V_192 , V_172 , 17 ) != 0 )
{
V_2 = ( char * ) F_45 ( F_48 () , 18 * sizeof( char ) ) ;
F_46 ( V_2 , 18 , L_1 , V_172 ) ;
F_40 ( V_38 , V_44 , & V_193 , L_36 , V_172 ) ;
}
}
}
else
{
F_24 ( V_169 , V_181 , V_5 , V_41 + 3 , 2 , V_47 ) ;
F_24 ( V_169 , V_182 , V_5 , V_51 + V_40 , 2 , V_170 ) ;
if ( ( V_122 ^ V_198 ) == 0 )
{
V_82 = F_28 ( V_5 , V_40 + V_18 + 1 ) ;
F_19 ( V_169 , V_102 , V_5 ,
V_18 + V_40 + 1 , 4 , V_82 , L_13 , V_82 ) ;
}
}
}
else if ( ( F_32 ( V_5 , V_40 ) ^ V_179 ) == 0 )
{
F_24 ( V_169 , V_181 , V_5 , V_51 + V_40 , 2 , V_170 ) ;
F_24 ( V_169 , V_182 , V_5 , V_41 + 3 , 2 , V_47 ) ;
if ( V_7 > 0 )
F_25 ( V_169 , V_190 , V_5 , V_18 + V_40 , 6 , V_73 ) ;
}
else if ( ( F_32 ( V_5 , V_40 ) ^ V_199 ) == 0 )
{
F_24 ( V_169 , V_181 , V_5 , V_41 + 3 , 2 , V_47 ) ;
F_24 ( V_169 , V_182 , V_5 , V_51 + V_40 , 2 , V_170 ) ;
if ( V_7 > 0 )
F_25 ( V_169 , V_190 , V_5 , V_18 + V_40 , 6 , V_73 ) ;
}
else if ( ( F_32 ( V_5 , V_40 ) ^ V_178 ) == 0 )
{
F_24 ( V_169 , V_181 , V_5 , V_51 + V_40 , 2 , V_170 ) ;
F_24 ( V_169 , V_182 , V_5 , V_41 + 3 , 2 , V_47 ) ;
if ( V_7 > 0 )
F_25 ( V_169 , V_190 , V_5 , V_18 + V_40 , 6 , V_73 ) ;
}
else if ( ( F_32 ( V_5 , V_40 ) ^ V_200 ) == 0 )
{
F_24 ( V_169 , V_181 , V_5 , V_41 + 3 , 2 , V_47 ) ;
F_24 ( V_169 , V_182 , V_5 , V_51 + V_40 , 2 , V_170 ) ;
}
}
static T_4
F_49 ( T_2 * V_5 , T_6 * V_38 , T_7 * V_39 ,
T_3 type , T_1 V_40 , T_1 V_41 )
{
T_1 V_201 , V_202 ;
T_1 V_203 , V_204 ;
T_5 V_7 , V_205 ;
T_3 * V_16 , V_27 = 0 , V_206 = V_207 ;
T_8 * V_44 ;
T_7 * V_208 ;
T_11 V_209 ;
T_11 V_210 ;
T_4 V_211 = FALSE ;
T_13 * V_212 = NULL ;
V_7 = F_43 ( V_5 , V_40 ) ;
V_209 = V_18 + V_7 + V_40 ;
if ( F_43 ( V_5 , V_40 ) > V_17 )
V_201 = F_6 ( V_5 , V_209 ) ;
else
V_201 = F_5 ( V_5 , V_209 ) ;
if ( type == V_37 )
V_211 = TRUE ;
V_205 = ( V_211 ? 0 : V_7 ) + 5 ;
V_210 = ( V_7 > V_17 ? V_213 : V_207 ) ;
V_44 = F_50 ( V_39 , V_214 , V_5 , V_209 , V_210 , V_201 ,
L_37 , V_201 ) ;
V_208 = F_22 ( V_44 , V_215 ) ;
V_16 = ( T_3 * ) F_7 ( F_8 () , V_5 , V_40 , V_7 + 4 ) ;
if ( V_7 > V_17 )
{
V_203 = F_9 ( V_16 , V_7 + 4 , 0 ) ;
if ( V_201 == V_203 )
V_206 = V_213 ;
if ( V_201 != V_203 )
{
V_203 = F_10 ( V_16 , V_7 + 4 , 0 ) ;
if ( V_201 == V_203 )
{
V_206 = V_216 ;
if ( ! V_211 )
F_30 ( V_38 , V_44 , & V_217 ) ;
}
}
}
else
V_203 = F_11 ( V_16 , V_7 + 4 , 0 ) ;
V_44 = F_23 ( V_208 , V_218 , V_5 ,
V_40 , V_7 + 4 , ( V_201 == V_203 ) ) ;
F_21 ( V_44 ) ;
F_24 ( V_208 , V_219 , V_5 , V_209 , V_210 , V_206 ) ;
V_209 = V_41 + ( V_211 ? 5 : V_7 + V_18 + 1 ) ;
if ( F_43 ( V_5 , V_40 ) > V_17 )
V_202 = F_6 ( V_5 , V_209 ) ;
else
V_202 = F_5 ( V_5 , V_209 ) ;
if ( V_220 )
{
V_16 = ( T_3 * ) F_7 ( F_8 () , V_5 , V_41 , V_205 + V_210 ) ;
if ( V_211 == TRUE )
V_7 = 0 ;
V_212 = F_51 () ;
if ( F_52 ( ( V_2 != NULL ? V_2 : V_192 ) , V_212 , TRUE ) && V_212 -> V_168 == 6 )
{
if ( type != V_176 )
{
for ( V_27 = 0 ; V_27 < 6 ; V_27 ++ )
V_16 [ V_27 ] = V_16 [ V_27 ] ^ ( T_3 ) ( V_212 -> V_221 [ V_27 ] ) ;
if ( V_7 == 0 )
V_202 = ( ( V_211 && V_210 == 2 ) ? ( ( V_16 [ 6 ] << 8 ) + V_16 [ 5 ] ) : V_16 [ 5 ] ) ;
}
V_44 = F_50 ( V_39 , V_214 , V_5 , V_209 , V_210 , V_202 ,
L_38 , V_202 ) ;
V_208 = F_22 ( V_44 , V_215 ) ;
if ( F_43 ( V_5 , V_40 ) > V_17 )
{
V_204 = F_9 ( V_16 , V_205 , 0 ) ;
if ( V_202 != V_204 )
V_204 = F_10 ( V_16 , V_205 , 0 ) ;
}
else
V_204 = F_11 ( V_16 , V_205 , 0 ) ;
V_44 = F_23 ( V_208 , V_222 , V_5 ,
V_41 , V_205 , ( V_202 == V_204 ) ) ;
F_21 ( V_44 ) ;
if ( V_202 != V_204 )
{
V_44 = F_50 ( V_208 , V_214 , V_5 ,
V_41 , V_205 , V_204 , L_39 , V_204 ) ;
F_21 ( V_44 ) ;
F_30 ( V_38 , V_44 , & V_223 ) ;
}
}
else
F_30 ( V_38 , V_44 , & V_224 ) ;
}
return ( T_4 ) ( V_201 == V_203 ) ;
}
static T_4
F_53 ( T_1 V_40 , T_1 V_41 , T_3 type ,
T_2 * V_5 , T_6 * V_38 ,
T_8 * V_225 , T_7 * V_39 , T_3 V_226 )
{
T_3 V_34 , V_27 ;
T_3 V_43 [ 6 ] ;
T_13 * V_212 = NULL ;
T_4 V_42 ;
T_8 * V_44 ;
T_4 V_227 , V_228 ;
V_227 = FALSE ;
for ( V_27 = 0 ; V_27 < 6 ; V_27 ++ )
V_43 [ V_27 ] = 0 ;
V_34 = F_32 ( V_5 , V_40 ) ;
if ( type == V_54 )
V_34 = V_34 & 0xF8 ;
F_35 ( V_38 -> V_138 , V_139 , ( V_226 > 1 ? L_40 : L_1 ) ,
F_44 ( V_34 , V_64 , L_41 ) ) ;
{
if ( type == V_176 )
{
F_42 ( V_5 , V_38 , V_39 , V_40 , V_41 ) ;
}
else
{
V_42 = FALSE ;
V_212 = F_51 () ;
if ( F_52 ( ( V_2 != NULL ? V_2 : V_192 ) , V_212 , TRUE ) && V_212 -> V_168 == 6 )
{
V_42 = TRUE ;
V_34 = F_32 ( V_5 , V_41 ) ^ ( T_3 ) ( V_212 -> V_221 [ V_53 ] ) ;
if ( ( F_32 ( V_5 , V_40 ) ^ V_34 ) != 0 )
V_42 = FALSE ;
else
for ( V_27 = 0 ; V_27 < 6 ; V_27 ++ )
V_43 [ V_27 ] = V_212 -> V_221 [ V_27 ] ;
}
if ( strlen ( ( V_2 != NULL ? V_2 : V_192 ) ) > 0 && V_212 -> V_168 == 6 )
{
if ( V_2 != NULL )
V_44 = F_54 ( V_39 , V_229 , V_5 , 0 , 0 , V_2 ) ;
else
V_44 = F_54 ( V_39 , V_230 , V_5 , 0 , 0 , V_192 ) ;
F_21 ( V_44 ) ;
}
V_44 = F_23 ( V_39 , V_231 , V_5 , 0 , 0 , V_42 ) ;
if ( V_212 -> V_168 != 6 )
F_30 ( V_38 , V_44 , & V_232 ) ;
F_21 ( V_44 ) ;
F_55 ( V_212 , TRUE ) ;
if ( type == V_132 || type == V_37 )
{
F_31 ( V_5 , V_38 , V_39 , V_40 , V_41 , V_42 , V_43 ) ;
}
else if ( type == V_54 )
{
F_15 ( V_5 , V_38 , V_39 , V_40 , V_41 , V_42 , V_43 ) ;
}
else
{
V_227 = TRUE ;
}
}
V_228 = FALSE ;
V_44 = F_24 ( V_39 , V_233 ,
V_5 , V_50 + V_40 , 1 , F_43 ( V_5 , V_40 ) ) ;
if ( V_227 )
{
F_30 ( V_38 , V_44 , & V_234 ) ;
}
else
{
V_228 = F_49 ( V_5 , V_38 , V_39 , type , V_40 , V_41 ) ;
}
if ( ! V_228 )
{
F_30 ( V_38 , V_225 , & V_235 ) ;
}
if ( V_228 && type == V_176 )
{
if ( F_32 ( V_5 , V_40 ) != F_32 ( V_5 , V_41 ) )
F_30 ( V_38 , V_225 , & V_236 ) ;
}
}
return TRUE ;
}
static T_4
F_56 ( const T_14 * V_237 , const T_14 * V_238 ,
T_4 V_239 , T_4 V_240 , T_3 V_241 ,
T_2 * V_242 , T_6 * V_38 , T_7 * V_243 )
{
T_2 * V_244 , * V_5 = NULL ;
T_5 V_210 , V_168 , V_245 , V_246 , V_247 ;
T_3 * V_16 ;
T_4 V_248 , V_249 , V_250 , V_251 ;
T_3 type , V_35 , V_252 , V_253 , V_254 ;
T_1 V_40 , V_41 , V_6 ;
T_11 V_255 ;
T_15 V_256 = NULL ;
T_8 * V_225 ;
T_7 * V_39 ;
V_248 = FALSE ;
V_249 = FALSE ;
V_250 = FALSE ;
V_251 = FALSE ;
F_57 ( V_38 , F_1 ) ;
V_210 = F_58 ( V_242 ) ;
if ( V_210 < V_36 )
return FALSE ;
if ( strlen ( V_238 ) > 0 )
{
V_250 = TRUE ;
V_256 = F_59 ( V_238 ) ;
if ( V_256 == NULL )
V_256 = F_59 ( L_42 ) ;
}
V_255 = F_13 ( V_242 , 0 ) ;
V_16 = ( T_3 * ) F_60 ( V_38 -> V_257 , V_210 ) ;
F_61 ( V_242 , V_16 , 0 , V_210 ) ;
if ( V_240 == TRUE && V_258 == TRUE )
{
V_168 = ( V_210 / 2 ) ;
for ( V_253 = 0 ; V_253 < V_168 ; V_253 ++ )
{
V_254 = V_16 [ 2 * V_253 ] ; V_16 [ 2 * V_253 ] = V_16 [ 2 * V_253 + 1 ] ; V_16 [ 2 * V_253 + 1 ] = V_254 ;
}
V_5 = F_62 ( V_16 , V_210 , V_255 ) ;
} else {
V_5 = V_242 ;
}
V_245 = 0 ;
V_246 = 0 ;
V_35 = 0 ;
V_252 = 0 ;
while ( V_245 < V_210 )
{
if ( F_63 ( V_5 , V_245 ) < V_36 )
break;
if ( F_12 ( V_5 , V_245 , V_239 , & V_245 , & V_246 ) )
{
if ( ( V_245 + V_246 ) > ( T_5 ) V_255 )
break;
V_35 ++ ;
V_6 = ( V_239 ? 0 : V_245 ) ;
if ( V_239 )
{
V_40 = F_4 ( V_5 , V_6 , V_246 , FALSE ) ;
V_41 = 0 ;
}
else
{
V_40 = 0 ;
V_41 = ( ( F_43 ( V_5 , V_6 + V_40 ) - 1 ) +
( F_43 ( V_5 , V_6 + V_40 ) > V_17 ? V_259 : V_19 ) ) ;
}
if ( V_40 == V_41 )
{
V_35 -- ;
V_245 += V_246 ;
continue;
}
if ( ( F_32 ( V_5 , V_6 + V_40 ) & V_37 ) == V_37 )
type = V_37 ;
else if ( ( F_32 ( V_5 , V_6 + V_40 ) & V_132 ) == V_132 )
type = V_132 ;
else if ( ( F_32 ( V_5 , V_6 + V_40 ) & V_54 ) == V_54 )
type = V_54 ;
else if ( ( F_32 ( V_5 , V_6 + V_40 ) & V_176 ) == V_176 )
type = V_176 ;
else
{
if ( V_239 )
{
V_40 = F_4 ( V_5 , ( V_239 ? 0 : V_245 ) , V_246 , TRUE ) ;
V_41 = 0 ;
if ( ( F_32 ( V_5 , V_6 + V_40 ) & V_37 ) == V_37 )
type = V_37 ;
else if ( ( F_32 ( V_5 , V_6 + V_40 ) & V_132 ) == V_132 )
type = V_132 ;
else if ( ( F_32 ( V_5 , V_6 + V_40 ) & V_54 ) == V_54 )
type = V_54 ;
else if ( ( F_32 ( V_5 , V_6 + V_40 ) & V_176 ) == V_176 )
type = V_176 ;
else {
V_245 += 2 ;
V_35 -- ;
continue;
}
} else {
V_245 += 2 ;
V_35 -- ;
continue;
}
}
if ( type != V_54 )
{
T_11 V_260 = - 1 ;
F_64 ( F_32 ( V_5 , V_6 + V_40 ) , V_64 , & V_260 ) ;
if ( V_260 < 0 )
{
V_245 += 2 ;
V_35 -- ;
continue;
}
else if ( type == V_176 &&
( F_32 ( V_5 , V_6 + V_40 ) != F_32 ( V_5 , V_6 + V_41 ) ) )
{
V_245 += 2 ;
V_35 -- ;
continue;
}
}
if ( type == V_54 )
{
V_247 = F_16 ( V_5 , V_6 + V_40 ) ;
if ( V_247 > 1024 ) {
V_251 = TRUE ;
}
}
if ( ( ( T_11 ) V_246 - ( T_11 ) ( V_41 > V_40 ? V_41 : V_246 - V_40 ) ) < 0 )
return FALSE ;
if ( V_240 == TRUE && V_258 == TRUE )
{
V_244 = F_65 ( V_5 , & V_16 [ V_245 ] , ( V_246 ) , V_255 ) ;
F_66 ( V_38 , V_244 , L_43 ) ;
}
else
{
V_244 = F_67 ( V_5 , V_245 , V_246 , V_255 ) ;
F_66 ( V_38 , V_244 , L_44 ) ;
}
if ( V_241 > 0 )
{
V_35 = V_241 + 1 ;
V_249 = TRUE ;
F_68 ( V_38 -> V_138 , V_261 , V_237 ) ;
}
if ( ! V_249 )
{
if ( V_250 )
F_69 ( V_256 , V_5 , V_38 , V_243 ) ;
V_249 = TRUE ;
F_68 ( V_38 -> V_138 , V_261 , V_237 ) ;
F_70 ( V_38 -> V_138 , V_139 ) ;
}
if ( V_243 )
{
V_225 = F_25 ( V_243 , V_262 , V_5 , V_245 , V_246 , V_73 ) ;
V_39 = F_22 ( V_225 , V_263 ) ;
} else {
V_225 = NULL ;
V_39 = NULL ;
}
if ( F_53 ( V_40 , V_41 , type , V_244 , V_38 , V_225 , V_39 , V_35 ) == TRUE )
V_252 ++ ;
else
V_251 = TRUE ;
if ( V_243 && V_251 )
{
if ( F_16 ( V_5 , V_6 + V_40 ) > 1024 )
F_30 ( V_38 , V_225 , & V_264 ) ;
}
V_248 = TRUE ;
}
else
break;
V_245 += V_246 ;
}
if ( V_248 == TRUE && V_252 == 0 )
V_248 = FALSE ;
if ( ! V_248 )
{
if ( V_250 )
F_69 ( V_256 , V_5 , V_38 , V_243 ) ;
V_248 = TRUE ;
}
return ( V_248 ? TRUE : FALSE ) ;
}
static T_4
F_71 ( T_2 * V_5 , T_6 * V_38 , T_7 * V_243 , void * V_221 V_265 )
{
T_4 V_266 = FALSE ;
T_3 V_267 ;
if ( ! V_268 )
return V_266 ;
if ( V_1 == FALSE )
{
V_1 = TRUE ;
V_267 = ( F_5 ( V_5 , 0 ) << 1 ) ;
if ( ( V_267 != 0x02 ) && ( V_267 != 0x0A ) )
{
V_266 = F_56 ( L_45 , L_46 ,
FALSE , FALSE , 0 , V_5 , V_38 , V_243 ) ;
}
V_1 = FALSE ;
}
return V_266 ;
}
static T_4
F_72 ( T_2 * V_5 , T_6 * V_38 , T_7 * V_243 , void * V_221 V_265 )
{
T_4 V_266 = FALSE ;
T_3 V_267 ;
if ( ! V_269 )
return V_266 ;
if ( V_38 -> V_270 == V_271 )
{
return F_56 ( L_47 , L_6 , FALSE , FALSE , 0 , V_5 , V_38 , V_243 ) ;
}
if ( V_1 == FALSE )
{
V_1 = TRUE ;
V_267 = ( F_5 ( V_5 , 0 ) << 1 ) ;
if ( ( V_267 & 0x40 ) == 0x40 )
{
V_266 = F_56 ( L_48 , L_49 ,
FALSE , FALSE , 0 , V_5 , V_38 , V_243 ) ;
}
V_1 = FALSE ;
}
return V_266 ;
}
static T_4
F_73 ( T_2 * V_5 , T_6 * V_38 , T_7 * V_243 , void * V_221 V_265 )
{
T_4 V_266 = FALSE ;
if ( ! V_272 )
return V_266 ;
if ( V_1 == FALSE )
{
V_1 = TRUE ;
V_266 = F_56 ( L_50 , L_51 ,
FALSE , FALSE , 0 , V_5 , V_38 , V_243 ) ;
V_1 = FALSE ;
}
return V_266 ;
}
static T_4
F_74 ( T_2 * V_5 , T_6 * V_38 , T_7 * V_243 , void * V_221 V_265 )
{
if ( ! V_273 )
return FALSE ;
return F_56 ( L_52 , L_6 , FALSE , TRUE , 0 ,
V_5 , V_38 , ( V_243 -> V_274 != NULL ? V_243 -> V_274 : V_243 ) ) ;
}
static T_4
F_75 ( T_2 * V_5 , T_6 * V_38 , T_7 * V_243 , void * V_221 V_265 )
{
T_4 V_266 = FALSE ;
static T_10 V_275 = 0 ;
static T_10 V_276 = 0 ;
if ( ! V_277 )
return V_266 ;
if ( F_27 ( V_5 ) < V_36 )
return V_266 ;
if ( V_38 -> V_278 -> V_279 != V_275 )
{
V_276 = 0 ;
V_275 = V_38 -> V_278 -> V_279 ;
}
V_266 = F_56 ( ( V_38 -> V_280 == V_281 ? L_48 : L_53 ) ,
L_6 , V_38 -> V_280 == V_281 ? V_282 : V_283 ,
FALSE , V_276 , V_5 , V_38 , V_243 ) ;
if ( V_266 )
V_276 ++ ;
return V_266 ;
}
static void
F_76 ( void )
{
static T_4 V_284 = FALSE ;
static T_5 V_285 ;
static T_5 V_286 ;
if ( V_284 )
{
F_77 ( L_54 , V_285 , F_59 ( L_55 ) ) ;
F_77 ( L_54 , V_286 , F_59 ( L_56 ) ) ;
}
V_284 = TRUE ;
V_285 = V_287 ;
V_286 = V_288 ;
F_78 ( L_54 , V_285 , F_59 ( L_55 ) ) ;
F_78 ( L_54 , V_286 , F_59 ( L_56 ) ) ;
}
void
F_79 ( void )
{
static T_16 V_289 [] = {
{ & V_230 ,
{ L_57 , L_58 ,
V_290 , V_291 , NULL , 0x0 , NULL , V_292 } } ,
{ & V_229 ,
{ L_59 , L_60 ,
V_290 , V_291 , NULL , 0x0 , NULL , V_292 } } ,
{ & V_231 ,
{ L_61 , L_62 ,
V_293 , V_291 , NULL , 0x0 , NULL , V_292 } } ,
{ & V_63 ,
{ L_63 , L_64 ,
V_294 , V_295 , F_80 ( V_64 ) , 0x0 , NULL , V_292 } } ,
{ & V_52 ,
{ L_65 , L_66 ,
V_296 , V_295 , F_80 ( V_55 ) , 0x0 , NULL , V_292 } } ,
{ & V_58 ,
{ L_67 , L_68 ,
V_293 , V_291 , F_81 ( & V_297 ) , 0x0 , NULL , V_292 } } ,
{ & V_298 ,
{ L_69 , L_70 ,
V_296 , V_295 , NULL , 0x0 , NULL , V_292 } } ,
{ & V_299 ,
{ L_71 , L_72 ,
V_296 , V_295 , NULL , 0x0 , NULL , V_292 } } ,
{ & V_300 ,
{ L_73 , L_74 ,
V_296 , V_295 , NULL , 0x0 , NULL , V_292 } } ,
{ & V_301 ,
{ L_75 , L_76 ,
V_296 , V_295 , NULL , 0x0 , NULL , V_292 } } ,
{ & V_233 ,
{ L_77 , L_78 ,
V_294 , V_302 , NULL , 0x0 , NULL , V_292 } } ,
{ & V_214 ,
{ L_79 , L_80 ,
V_296 , V_295 , NULL , 0x0 , NULL , V_292 } } ,
{ & V_218 ,
{ L_81 , L_82 ,
V_293 , V_291 , NULL , 0x0 , NULL , V_292 } } ,
{ & V_219 ,
{ L_83 , L_84 ,
V_294 , V_302 , F_80 ( V_303 ) , 0x0 , NULL , V_292 } } ,
{ & V_222 ,
{ L_81 , L_85 ,
V_293 , V_291 , NULL , 0x0 , NULL , V_292 } } ,
{ & V_182 ,
{ L_86 , L_87 ,
V_296 , V_295 , NULL , 0x0 , NULL , V_292 } } ,
{ & V_181 ,
{ L_88 , L_89 ,
V_296 , V_295 , NULL , 0x0 , NULL , V_292 } } ,
{ & V_195 ,
{ L_90 , L_91 ,
V_296 , V_295 , NULL , 0x0 , NULL , V_292 } } ,
{ & V_196 ,
{ L_92 , L_93 ,
V_296 , V_295 , NULL , 0x0 , NULL , V_292 } } ,
{ & V_190 ,
{ L_94 , L_95 ,
V_304 , V_291 , NULL , 0x0 , NULL , V_292 } } ,
{ & V_183 ,
{ L_96 , L_97 ,
V_294 , V_295 , F_80 ( V_184 ) , 0x0 , NULL , V_292 } } ,
{ & V_186 ,
{ L_98 , L_99 ,
V_294 , V_302 , NULL , 0x0 , NULL , V_292 } } ,
{ & V_188 ,
{ L_100 , L_101 ,
V_294 , V_302 , NULL , 0x0 , NULL , V_292 } } ,
{ & V_136 ,
{ L_102 , L_103 ,
V_296 , V_295 , NULL , 0x0 , NULL , V_292 } } ,
{ & V_135 ,
{ L_104 , L_105 ,
V_296 , V_295 , NULL , 0x0 , NULL , V_292 } } ,
{ & V_149 ,
{ L_106 , L_107 ,
V_296 , V_302 , NULL , 0x0 , NULL , V_292 } } ,
{ & V_137 ,
{ L_108 , L_109 ,
V_294 , V_295 , F_80 ( V_140 ) , 0x0 , NULL , V_292 } } ,
{ & V_98 ,
{ L_110 , L_111 ,
V_296 , V_295 , NULL , 0x0 , NULL , V_292 } } ,
{ & V_101 ,
{ L_112 , L_113 ,
V_294 , V_295 , NULL , 0x0 , NULL , V_292 } } ,
{ & V_164 ,
{ L_114 , L_115 ,
V_305 , V_291 , NULL , 0x0 , NULL , V_292 } } ,
{ & V_163 ,
{ L_116 , L_117 ,
V_306 , V_302 , NULL , 0x0 , NULL , V_292 } } ,
{ & V_108 ,
{ L_118 , L_119 ,
V_306 , V_302 , NULL , 0x0 , NULL , V_292 } } ,
{ & V_112 ,
{ L_120 , L_121 ,
V_305 , V_291 , NULL , 0x0 , NULL , V_292 } } ,
{ & V_102 ,
{ L_122 , L_123 ,
V_306 , V_295 , NULL , 0x0 , NULL , V_292 } } ,
{ & V_103 ,
{ L_124 , L_125 ,
V_306 , V_295 , NULL , 0x0 , NULL , V_292 } } ,
{ & V_109 ,
{ L_126 , L_127 ,
V_307 , V_291 , NULL , 0x0 , NULL , V_292 } } ,
{ & V_111 ,
{ L_128 , L_129 ,
V_294 , V_302 , NULL , 0x0 , NULL , V_292 } } ,
{ & V_87 ,
{ L_130 , L_131 ,
V_294 , V_302 , NULL , 0x0 , NULL , V_292 } } ,
{ & V_89 ,
{ L_132 , L_133 ,
V_294 , V_302 , NULL , 0x0 , NULL , V_292 } } ,
{ & V_90 ,
{ L_134 , L_135 ,
V_294 , V_295 , NULL , 0x0 , NULL , V_292 } } ,
{ & V_92 ,
{ L_136 , L_137 ,
V_294 , V_295 , NULL , 0x0 , NULL , V_292 } } ,
{ & V_93 ,
{ L_138 , L_139 ,
V_294 , V_295 , NULL , 0x0 , NULL , V_292 } } ,
{ & V_94 ,
{ L_140 , L_141 ,
V_294 , V_295 , NULL , 0x0 , NULL , V_292 } } ,
{ & V_95 ,
{ L_142 , L_143 ,
V_305 , V_291 , NULL , 0x0 , NULL , V_292 } } ,
{ & V_85 ,
{ L_144 , L_145 ,
V_290 , V_291 , NULL , 0x0 , NULL , V_292 } } ,
{ & V_308 ,
{ L_146 , L_147 ,
V_307 , V_291 , NULL , 0x00 , NULL , V_292 } } ,
{ & V_309 ,
{ L_148 , L_149 ,
V_310 , V_291 , NULL , 0x00 , NULL , V_292 } } ,
{ & V_311 ,
{ L_150 , L_151 ,
V_293 , 0 , NULL , 0x00 , NULL , V_292 } } ,
{ & V_312 ,
{ L_152 ,
L_153 ,
V_293 , 0 , NULL , 0x00 , NULL , V_292 } } ,
{ & V_313 ,
{ L_154 , L_155 ,
V_293 , 0 , NULL , 0x00 , NULL , V_292 } } ,
{ & V_314 ,
{ L_156 , L_157 ,
V_293 , 0 , NULL , 0x00 , NULL , V_292 } } ,
{ & V_315 ,
{ L_158 , L_159 ,
V_310 , V_291 , NULL , 0x00 , NULL , V_292 } } ,
{ & V_316 ,
{ L_160 , L_161 ,
V_306 , V_302 , NULL , 0x00 , NULL , V_292 } } ,
{ & V_317 ,
{ L_162 , L_163 ,
V_310 , V_291 , NULL , 0x00 , NULL , V_292 } } ,
{ & V_318 ,
{ L_164 , L_165 ,
V_306 , V_302 , NULL , 0x00 , NULL , V_292 } } ,
{ & V_319 ,
{ L_166 , L_167 ,
V_305 , V_291 , NULL , 0x00 , NULL , V_292 } } ,
#if 0
{ &hf_oss_ssdo_inhibit_time,
{ "Inhibit Time", "opensafety.ssdo.inhibittime",
FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL } },
#endif
{ & V_152 ,
{ L_168 , L_169 ,
V_306 , V_295 , NULL , 0x0 , NULL , V_292 } } ,
{ & V_148 ,
{ L_170 , L_171 ,
V_293 , 8 , F_81 ( & V_320 ) , V_321 , NULL , V_292 } } ,
#if 0
{ &hf_oss_ssdo_sacmd_reserved,
{ "Reserved", "opensafety.ssdo.sacmd.reserved",
FT_BOOLEAN, 8, TFS(&opensafety_sacmd_res), OPENSAFETY_SSDO_SACMD_RES, NULL, HFILL } },
#endif
{ & V_147 ,
{ L_172 , L_173 ,
V_293 , 8 , F_81 ( & V_322 ) , V_323 , NULL , V_292 } } ,
{ & V_146 ,
{ L_174 , L_175 ,
V_293 , 8 , F_81 ( & V_324 ) , V_162 , NULL , V_292 } } ,
{ & V_145 ,
{ L_176 , L_177 ,
V_293 , 8 , F_81 ( & V_325 ) , V_131 , NULL , V_292 } } ,
{ & V_144 ,
{ L_178 , L_179 ,
V_293 , 8 , F_81 ( & V_326 ) , V_150 , NULL , V_292 } } ,
{ & V_143 ,
{ L_180 , L_181 ,
V_293 , 8 , F_81 ( & V_327 ) , V_328 , NULL , V_292 } } ,
{ & V_142 ,
{ L_182 , L_183 ,
V_293 , 8 , F_81 ( & V_329 ) , V_330 , NULL , V_292 } } ,
{ & V_66 ,
{ L_184 , L_185 ,
V_293 , V_291 , F_81 ( & V_331 ) , 0x0 , NULL , V_292 } } ,
{ & V_72 ,
{ L_186 , L_187 ,
V_305 , V_291 , NULL , 0x0 , NULL , V_292 } } ,
{ & V_65 ,
{ L_188 , L_189 ,
V_296 , V_295 , NULL , 0x0 , NULL , V_292 } } ,
{ & V_70 ,
{ L_190 , L_191 ,
V_296 , V_295 , NULL , 0x0 , NULL , V_292 } } ,
{ & V_67 ,
{ L_192 , L_193 ,
V_296 , V_295 , NULL , 0x0 , NULL , V_292 } } ,
{ & V_68 ,
{ L_194 , L_195 ,
V_294 , V_295 , NULL , 0x0 , NULL , V_292 } } ,
{ & V_71 ,
{ L_196 , L_197 ,
V_296 , V_295 , NULL , 0x0 , NULL , V_292 } } ,
{ & V_69 ,
{ L_198 , L_199 ,
V_296 , V_295 , NULL , 0x0 , NULL , V_292 } } ,
} ;
static T_11 * V_332 [] = {
& V_263 ,
& V_333 ,
& V_334 ,
& V_215 ,
& V_177 ,
& V_133 ,
& V_141 ,
& V_335 ,
& V_336 ,
& V_165 ,
& V_100 ,
& V_110 ,
& V_86 ,
& V_56 ,
} ;
static T_17 V_337 [] = {
{ & V_235 ,
{ L_200 , V_338 , V_339 ,
L_201 , V_340 } } ,
{ & V_236 ,
{ L_202 , V_338 , V_339 ,
L_203 , V_340 } } ,
{ & V_217 ,
{ L_204 , V_338 , V_341 ,
L_205 , V_340 } } ,
{ & V_223 ,
{ L_206 , V_338 , V_339 ,
L_207 , V_340 } } ,
{ & V_224 ,
{ L_208 , V_338 , V_341 ,
L_209 , V_340 } } ,
{ & V_96 ,
{ L_210 , V_338 , V_341 ,
L_211 , V_340 } } ,
{ & V_234 ,
{ L_212 , V_342 , V_339 ,
L_213 , V_340 } } ,
{ & V_264 ,
{ L_214 , V_342 , V_339 ,
L_215 , V_340 } } ,
{ & V_193 ,
{ L_216 , V_338 , V_343 ,
L_217 , V_340 } } ,
{ & V_232 ,
{ L_218 , V_338 , V_341 ,
L_219 , V_340 } } ,
{ & V_344 ,
{ L_220 , V_338 , V_341 ,
L_221 , V_340 } } ,
{ & V_104 ,
{ L_222 , V_338 , V_341 ,
L_223 , V_340 } } ,
{ & V_167 ,
{ L_224 , V_338 , V_343 ,
L_225 , V_340 } } ,
} ;
T_18 * V_345 ;
T_19 * V_346 ;
V_262 = F_82 ( L_226 , L_226 , L_227 ) ;
V_345 = F_83 ( V_262 , F_76 ) ;
F_84 ( V_262 , V_289 , F_85 ( V_289 ) ) ;
F_86 ( V_332 , F_85 ( V_332 ) ) ;
V_346 = F_87 ( V_262 ) ;
F_88 ( V_346 , V_337 , F_85 ( V_337 ) ) ;
F_89 ( V_345 , L_228 ,
L_229 ,
L_230 ,
& V_192 ) ;
F_90 ( V_345 , L_231 ,
L_232 ,
L_233 ,
& V_191 ) ;
F_90 ( V_345 , L_234 ,
L_235 ,
L_236 ,
& V_220 ) ;
F_91 ( V_345 , L_237 ,
L_238 ,
L_239 , 10 ,
& V_287 ) ;
F_91 ( V_345 , L_240 ,
L_241 ,
L_242 , 10 ,
& V_288 ) ;
F_90 ( V_345 , L_243 ,
L_244 ,
L_245 ,
& V_282 ) ;
F_90 ( V_345 , L_246 ,
L_247 ,
L_248 ,
& V_283 ) ;
F_90 ( V_345 , L_249 ,
L_250 ,
L_251 ,
& V_258 ) ;
F_90 ( V_345 , L_252 ,
L_253 , L_253 ,
& V_268 ) ;
F_90 ( V_345 , L_254 ,
L_255 , L_255 ,
& V_277 ) ;
F_90 ( V_345 , L_256 ,
L_257 , L_257 ,
& V_347 ) ;
F_90 ( V_345 , L_258 ,
L_259 , L_259 ,
& V_269 ) ;
F_90 ( V_345 , L_260 ,
L_261 , L_261 ,
& V_272 ) ;
F_90 ( V_345 , L_262 ,
L_263 , L_263 ,
& V_273 ) ;
F_92 ( L_55 , F_75 , V_262 ) ;
F_92 ( L_264 , F_74 , V_262 ) ;
F_92 ( L_56 , F_72 , V_262 ) ;
F_92 ( L_265 , F_73 , V_262 ) ;
}
void
F_93 ( void )
{
static int V_348 = FALSE ;
if ( ! V_348 )
{
F_94 ( L_46 , F_71 , V_262 ) ;
F_94 ( L_49 , F_72 , V_262 ) ;
if ( F_59 ( L_266 ) != NULL )
F_94 ( L_266 , F_75 , V_262 ) ;
F_95 ( L_267 , L_42 , F_59 ( L_264 ) ) ;
if ( F_59 ( L_51 ) != NULL )
{
F_94 ( L_51 , F_73 , V_262 ) ;
}
else
{
F_78 ( L_268 , V_349 , F_59 ( L_265 ) ) ;
}
F_96 ( F_2 ) ;
}
}
