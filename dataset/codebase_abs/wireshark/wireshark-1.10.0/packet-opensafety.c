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
void F_4 ( T_1 * V_5 , T_2 * V_6 , int V_7 , int V_8 , const char * V_9 , ... )
{
T_3 V_10 ;
va_start ( V_10 , V_9 ) ;
F_5 ( V_5 , V_6 , V_7 , V_8 , V_9 , V_10 ) ;
va_end ( V_10 ) ;
}
static T_4
F_6 ( T_5 * V_11 , T_4 V_12 , T_6 V_13 , T_7 V_14 )
{
T_4 V_15 = 0 ;
T_4 V_16 , V_17 = 0 ;
T_4 V_18 = 0 , V_19 = 0 , V_20 = 0 ;
T_6 V_21 = 0 ;
T_6 * V_22 = NULL ;
V_15 = V_13 / 2 + 1 ;
V_16 = F_7 ( V_11 , V_12 + V_15 + 2 ) ;
V_17 = V_16 * 2 + 11 + 2 * ( V_16 > V_23 ? 1 : 0 ) ;
if ( V_14 && V_17 == V_13 )
{
V_22 = ( T_6 * ) F_8 ( V_11 , V_12 + V_15 , V_13 + 4 ) ;
if ( V_13 > V_23 )
V_19 = F_9 ( V_22 , V_13 + 4 , 0 ) ;
else
V_19 = F_10 ( V_22 , V_13 + 4 , 0 ) ;
if ( V_13 > V_23 )
V_20 = F_11 ( V_11 , V_12 + V_15 + V_13 + V_24 ) ;
else
V_20 = F_7 ( V_11 , V_12 + V_15 + V_13 + V_24 ) ;
if ( V_20 != V_19 )
V_13 = 0 ;
}
if ( V_17 != V_13 )
{
V_15 = 0 ;
V_18 = V_25 + ( V_13 < ( V_26 + 1 ) ? 0 : 1 ) ;
V_21 = ( F_7 ( V_11 , V_12 + V_18 + 1 ) ) & 0xFC ;
if ( ( ( V_21 ^ V_27 ) == 0 ) ||
( ( V_21 ^ V_28 ) == 0 ) )
{
V_15 = V_18 ;
}
}
return V_15 ;
}
static T_6 F_12 ( T_5 * V_11 , T_8 V_29 , T_7 V_30 , T_8 * V_31 , T_8 * V_32 )
{
T_8 V_33 , V_34 ;
T_4 V_35 , V_36 ;
T_6 V_37 , V_38 ;
T_6 * V_22 ;
T_8 V_39 ;
T_7 V_40 ;
V_40 = 0 ;
V_33 = V_29 ;
V_34 = F_13 ( V_11 , V_33 ) ;
while ( V_34 >= V_41 )
{
if ( V_33 != 0 )
{
* V_32 = 0 ;
* V_31 = 0 ;
V_38 = 0 ;
V_39 = F_7 ( V_11 , V_33 ) ;
if ( V_39 != 0x0 )
{
V_37 = F_7 ( V_11 , V_33 + 1 ) ;
if ( ( V_39 != 0xFF ) && ( V_39 & 0x80 ) )
{
if ( ( V_37 <= ( T_8 ) 8 && ( V_37 <= V_34 ) ) ||
( V_37 > ( T_8 ) 8 && ( ( V_37 + ( T_8 ) 5 ) <= V_34 ) ) )
{
if ( F_14 ( V_11 , V_33 - 1 , V_37 + 5 ) )
{
if ( ( ( V_39 >> 4 ) != 0x09 ) && ( ( V_39 >> 4 ) != 0x0F ) )
{
V_36 = 0 ;
V_35 = F_7 ( V_11 , V_33 + 3 + V_37 ) ;
V_22 = ( T_6 * ) F_8 ( V_11 , V_33 - 1 , V_37 + 5 ) ;
if ( V_37 > 8 ) {
V_35 = F_11 ( V_11 , V_33 + 3 + V_37 ) ;
V_38 = 1 ;
if ( V_35 != 0x00 )
V_36 = F_9 ( V_22 , V_37 + 4 , 0 ) ;
} else {
if ( V_35 != 0x00 )
V_36 = F_10 ( V_22 , V_37 + 4 , 0 ) ;
}
if ( ( V_35 != 0x00 ) && ( V_35 ^ V_36 ) == 0 )
{
if ( ( V_39 >> 3 ) == ( V_42 >> 3 ) )
{
* V_31 = ( V_33 - 1 ) ;
* V_32 = V_37 + 2 * V_38 + 11 ;
V_40 = 1 ;
break;
}
else
{
* V_32 = 2 * V_37 + 2 * V_38 + 11 ;
* V_31 = ( V_33 - 1 ) ;
if ( F_7 ( V_11 , * V_31 + * V_32 - 2 ) != 0x00 ||
F_7 ( V_11 , * V_31 + * V_32 - 1 ) != 0x00 )
{
V_40 = 1 ;
break;
}
}
}
}
}
}
}
}
}
V_33 ++ ;
V_34 = F_13 ( V_11 , V_33 ) ;
}
if ( V_30 && V_40 )
* V_31 = V_29 ;
return ( V_40 ? 1 : 0 ) ;
}
static void
F_15 ( T_5 * V_11 , T_1 * V_5 , T_9 * V_43 ,
T_4 V_44 , T_4 V_45 , T_7 V_46 , T_6 V_47 [ 6 ] )
{
T_2 * V_48 ;
T_9 * V_49 ;
T_4 V_50 ;
T_10 V_51 ;
T_8 V_13 ;
T_6 V_52 , V_39 , V_53 ;
V_13 = F_7 ( V_11 , V_54 + V_44 ) ;
V_39 = F_7 ( V_11 , V_44 + 1 ) & 0xF8 ;
V_53 = ( ( F_7 ( V_11 , V_44 + 1 ) & 0x04 ) == 0x04 ) ;
V_50 = F_7 ( V_11 , V_44 + 3 ) ;
if ( V_46 )
V_50 = ( T_4 ) ( ( F_7 ( V_11 , V_45 + 2 ) ^ V_47 [ 2 ] ) << 8 ) +
( F_7 ( V_11 , V_44 + 3 ) ) ;
V_51 = ( ( F_16 ( V_11 , V_44 ) ) ^ ( F_17 ( V_11 , V_45 , V_47 [ 0 ] , V_47 [ 1 ] ) ) ) ;
if ( ! V_46 )
V_51 = ( - 1 * V_51 ) ;
F_18 ( V_5 , F_16 ( V_11 , V_44 ) , V_55 + V_44 , V_45 , V_51 ) ;
V_48 = F_19 ( V_43 , V_56 , V_11 ,
V_57 + V_44 , 1 , V_58 ,
L_1 , F_20 ( V_58 , V_59 , L_2 ) ) ;
F_21 ( V_48 ) ;
V_49 = F_22 ( V_48 , V_60 ) ;
if ( V_39 == V_61 )
F_23 ( V_49 , V_62 , V_11 ,
V_57 + V_44 , 1 , V_63 ) ;
else if ( V_39 == V_64 || V_39 == V_65 )
F_23 ( V_49 , V_62 , V_11 ,
V_57 + V_44 , 1 , V_66 ) ;
F_19 ( V_49 , V_67 , V_11 , V_57 + V_44 , 1 ,
V_39 , L_1 , F_20 ( V_39 , V_68 , L_2 ) ) ;
F_24 ( V_49 , V_69 , V_11 ,
V_55 + V_44 , 2 , F_16 ( V_11 , V_44 ) ) ;
F_23 ( V_49 , V_70 , V_11 ,
V_57 + V_44 , 1 , V_53 ) ;
V_51 = F_17 ( V_11 , V_45 + 3 , V_47 [ 3 ] , V_47 [ 4 ] ) ;
V_52 = ( F_7 ( V_11 , V_45 + 4 ) ^ V_47 [ 4 ] ) & 0xFC ;
if ( V_39 == V_64 )
{
V_48 = F_19 ( V_49 , V_71 , V_11 , 0 , 0 , V_50 ,
L_3 , V_50 , V_50 ,
( V_46 ? L_4 : L_5 ) ) ;
F_21 ( V_48 ) ;
F_24 ( V_49 , V_72 , V_11 ,
V_55 + V_45 + 4 , 1 , V_52 ) ;
F_24 ( V_49 , V_73 , V_11 ,
V_55 + V_45 + 3 , 2 , V_51 ) ;
}
else
{
V_48 = F_19 ( V_49 , V_74 , V_11 , 0 , 0 , V_50 ,
L_3 , V_50 , V_50 , ( V_46 ? L_4 : L_5 ) ) ;
F_21 ( V_48 ) ;
if ( V_39 == V_61 )
{
F_24 ( V_49 , V_72 , V_11 , V_55 + V_45 + 4 , 1 , V_52 ) ;
F_24 ( V_49 , V_75 , V_11 , V_55 + V_45 + 3 , 2 , V_51 ) ;
}
}
if ( V_13 > 0 )
F_25 ( V_49 , V_76 , V_11 , V_57 + 3 , V_13 , V_77 ) ;
}
static void F_26 ( T_1 * V_5 , T_5 * V_78 , T_9 * V_79 , T_6 V_80 )
{
T_8 V_13 = 0 , V_33 = 0 , V_81 = 0 ;
T_6 V_82 = 0 ;
T_4 V_83 = 0 , V_84 = 0 ;
T_11 V_85 = 0 , V_86 = 0 ;
T_2 * V_48 ;
T_9 * V_87 , * V_88 ;
V_13 = F_27 ( V_78 ) ;
V_83 = F_11 ( V_78 , 0 ) ;
V_85 = F_28 ( V_78 , 4 ) ;
if ( V_13 == 16 || V_85 == ( V_13 - 16 ) || V_83 == 0x0101 )
{
V_48 = F_29 ( V_79 , V_89 ,
V_78 , 0 , V_13 , L_6 , L_7 ,
( V_13 == 16 ? L_8 : L_9 ) ) ;
V_88 = F_22 ( V_48 , V_90 ) ;
F_25 ( V_88 , V_91 , V_78 , 0 , 1 , V_92 ) ;
F_25 ( V_88 , V_93 , V_78 , 1 , 1 , V_92 ) ;
F_25 ( V_88 , V_94 , V_78 , 2 , 2 , V_95 ) ;
F_19 ( V_88 , V_96 ,
V_78 , 4 , 4 , V_85 , L_10 ,
V_85 , V_85 ) ;
F_25 ( V_88 , V_97 , V_78 , 8 , 4 , V_95 ) ;
F_25 ( V_88 , V_98 , V_78 , 12 , 4 , V_95 ) ;
if ( V_13 != 16 )
{
V_48 = F_25 ( V_88 , V_99 , V_78 , 16 , V_13 - 16 , V_77 ) ;
if ( ( V_13 - V_85 ) != 16 )
F_30 ( V_5 , V_48 , L_11 ) ;
}
}
else
{
if ( V_80 == V_100 && ( V_13 % 4 == 0 ) )
{
V_48 = F_19 ( V_79 , V_101 , V_78 ,
0 , 0 , 0x1018 , L_12 , 0x1018 ,
F_20 ( ( ( T_11 ) ( 0x1018 << 16 ) ) ,
V_102 , L_2 ) ) ;
V_87 = F_22 ( V_48 , V_103 ) ;
F_21 ( V_48 ) ;
V_48 = F_19 ( V_87 , V_104 , V_78 , 0 , 0 ,
0x06 , L_13 , 0x06 ,
F_20 ( ( ( T_11 ) ( 0x1018 << 16 ) + 0x06 ) ,
V_102 , L_2 ) ) ;
F_21 ( V_48 ) ;
V_86 = F_28 ( V_78 , 0 ) ;
F_19 ( V_87 , V_105 , V_78 , 0 ,
4 , V_86 , L_14 , V_86 ) ;
for ( V_81 = 4 ; V_81 < V_13 ; V_81 += 4 )
{
V_86 = F_28 ( V_78 , V_81 ) ;
F_19 ( V_87 , V_106 , V_78 , ( V_81 ) ,
4 , V_86 , L_15 , ( V_81 / 4 ) , V_86 ) ;
}
}
else
{
for ( V_33 = 0 ; V_33 < V_13 ; V_33 ++ )
{
V_83 = F_11 ( V_78 , V_33 ) ;
V_82 = F_7 ( V_78 , V_33 + 2 ) ;
V_84 = V_83 ;
if ( V_83 >= 0x1400 && V_83 <= 0x17FE )
V_84 = 0x1400 ;
else if ( V_83 >= 0x1800 && V_83 <= 0x1BFE )
V_84 = 0x1800 ;
else if ( V_83 >= 0x1C00 && V_83 <= 0x1FFE )
V_84 = 0x1C00 ;
else if ( V_83 >= 0xC000 && V_83 <= 0xC3FE )
V_84 = 0xC000 ;
V_48 = F_19 ( V_79 , V_101 , V_78 ,
V_33 , 2 , V_83 , L_12 , V_83 ,
F_20 ( ( ( T_11 ) ( V_84 << 16 ) ) ,
V_102 , L_2 ) ) ;
if ( V_83 < 0x1000 || V_83 > 0xE7FF )
F_30 ( V_5 , V_48 , L_16 ) ;
V_87 = F_22 ( V_48 , V_103 ) ;
if ( V_82 != 0 )
F_19 ( V_87 , V_104 , V_78 , V_33 + 2 , 1 ,
V_82 , L_13 , V_82 ,
F_20 ( ( ( T_11 ) ( V_83 << 16 ) + V_82 ) ,
V_102 , L_2 ) ) ;
else
F_19 ( V_87 , V_104 , V_78 , V_33 + 2 , 1 ,
V_82 , L_17 , V_82 ) ;
V_33 += 2 ;
V_85 = F_28 ( V_78 , V_33 + 1 ) ;
if ( V_85 > ( V_13 - V_33 ) )
V_85 = 0 ;
if ( ( V_85 + 4 + V_33 ) > V_13 )
break;
if ( V_83 == V_107 && V_82 == 0x06 )
{
V_86 = F_28 ( V_78 , V_33 + 5 ) ;
F_19 ( V_87 , V_105 , V_78 , V_33 + 5 ,
4 , V_86 , L_14 , V_86 ) ;
for ( V_81 = 4 ; V_81 < V_85 ; V_81 += 4 )
{
V_86 = F_28 ( V_78 , V_33 + 5 + V_81 ) ;
F_19 ( V_87 , V_106 , V_78 , ( V_33 + 5 + V_81 ) ,
4 , V_86 , L_15 , ( V_81 / 4 ) , V_86 ) ;
}
} else if ( V_83 == V_107 && V_82 == 0x07 ) {
V_86 = F_28 ( V_78 , V_33 + 5 ) ;
F_19 ( V_87 , V_105 , V_78 , V_33 + 5 ,
4 , V_86 , L_14 , V_86 ) ;
} else if ( ( V_84 == V_108 || V_84 == V_109 ) && V_82 != 0x0 ) {
F_24 ( V_87 , V_110 , V_78 , V_33 + 1 , 4 , V_85 ) ;
V_48 = F_25 ( V_87 , V_111 , V_78 , V_33 + 5 , V_85 , V_77 ) ;
V_88 = F_22 ( V_48 , V_112 ) ;
F_25 ( V_88 , V_113 , V_78 , V_33 + 5 , 1 , V_77 ) ;
V_86 = F_28 ( V_78 , V_33 + 7 ) ;
F_25 ( V_88 , V_101 , V_78 , V_33 + 7 , 2 , V_86 ) ;
F_25 ( V_88 , V_104 , V_78 , V_33 + 6 , 1 , V_77 ) ;
} else {
F_24 ( V_87 , V_110 , V_78 , V_33 + 1 , 4 , V_85 ) ;
if ( V_85 > 0 )
F_25 ( V_87 , V_114 , V_78 , V_33 + 5 , V_85 , V_95 ) ;
}
V_33 += V_85 + 4 ;
}
}
}
}
static void
F_31 ( T_5 * V_11 , T_1 * V_5 , T_9 * V_43 ,
T_4 V_44 , T_4 V_45 , T_7 V_46 , T_6 V_47 [ 6 ] )
{
T_2 * V_48 ;
T_9 * V_115 , * V_79 , * V_116 ;
T_4 V_51 = 0 , V_117 = 0 , V_118 = 0 , V_119 = 0 , V_81 = 0 , V_50 = 0 ;
T_11 V_120 , V_83 = 0 , V_82 = 0 , V_121 , V_122 = 0 , V_86 = 0 ;
T_6 V_123 , V_124 , V_80 , V_125 ;
T_8 V_13 ;
T_12 V_126 ;
T_7 V_127 , V_128 , V_129 , V_130 , V_131 ;
T_5 * V_78 = NULL ;
T_13 * V_132 = NULL ;
V_13 = F_7 ( V_11 , V_54 + V_44 ) ;
V_128 = FALSE ;
V_123 = V_44 + V_24 ;
V_124 = F_7 ( V_11 , V_123 ) ;
V_80 = V_124 ;
V_83 = 0 ;
V_82 = 0 ;
if ( ( V_80 & V_133 ) == V_133 )
V_80 = V_80 & ( ~ V_133 ) ;
V_127 = ( ( F_32 ( V_11 , V_44 ) & 0x04 ) == 0x04 ) ;
if ( V_46 )
{
V_51 = F_17 ( V_11 , V_45 + 3 , V_47 [ 3 ] , V_47 [ 4 ] ) ;
V_117 = ( F_16 ( V_11 , V_44 ) ^
( F_17 ( V_11 , V_45 , V_47 [ 0 ] , V_47 [ 1 ] ) ) ) ;
F_33 ( V_5 , V_51 , V_45 + 3 , F_16 ( V_11 , V_44 ) ,
V_44 , V_45 , V_117 ) ;
}
else if ( ! V_127 )
{
F_18 ( V_5 , F_16 ( V_11 , V_44 ) , V_44 , V_45 ,
- 1 * ( ( F_16 ( V_11 , V_44 ) ) ^ ( F_17 ( V_11 , V_45 , V_47 [ 0 ] , V_47 [ 1 ] ) ) ) ) ;
}
else if ( V_127 )
{
F_34 ( V_5 , F_16 ( V_11 , V_44 ) , V_44 , V_45 ,
- 1 * ( ( F_16 ( V_11 , V_44 ) ) ^ ( F_17 ( V_11 , V_45 , V_47 [ 0 ] , V_47 [ 1 ] ) ) ) ) ;
}
if ( ( F_32 ( V_11 , V_44 ) == V_27 ) ||
( F_32 ( V_11 , V_44 ) == V_28 ) )
V_48 = F_19 ( V_43 , V_56 , V_11 ,
V_57 + V_44 , 1 ,
V_42 ,
L_1 , F_20 ( V_42 , V_59 , L_2 ) ) ;
else
V_48 = F_19 ( V_43 , V_56 , V_11 , V_57 + V_44 , 1 ,
V_134 ,
L_1 , F_20 ( V_134 , V_59 , L_2 ) ) ;
F_21 ( V_48 ) ;
V_115 = F_22 ( V_48 , V_135 ) ;
if ( ( F_32 ( V_11 , V_44 ) == V_136 ) ||
( F_32 ( V_11 , V_44 ) == V_28 ) )
F_23 ( V_115 , V_62 , V_11 , V_57 + V_44 , 1 , V_63 ) ;
else
F_23 ( V_115 , V_62 , V_11 , V_57 + V_44 , 1 , V_66 ) ;
F_19 ( V_115 , V_67 , V_11 , V_57 + V_44 , 1 ,
F_32 ( V_11 , V_44 ) ,
L_1 , F_20 ( F_32 ( V_11 , V_44 ) , V_68 , L_2 ) ) ;
if ( V_127 )
{
if ( V_46 )
{
F_24 ( V_115 , V_137 , V_11 , V_44 , 2 , F_16 ( V_11 , V_44 ) ) ;
V_119 = F_16 ( V_11 , V_44 ) ;
F_24 ( V_115 , V_138 , V_11 , V_45 + 3 , 2 , V_51 ) ;
V_118 = V_51 ;
}
else
{
F_24 ( V_115 , V_137 , V_11 , V_44 , 2 , F_16 ( V_11 , V_44 ) ) ;
V_119 = F_16 ( V_11 , V_44 ) ;
}
}
else if ( ! V_127 )
{
if ( V_46 )
{
F_24 ( V_115 , V_138 , V_11 , V_44 , 2 , F_16 ( V_11 , V_44 ) ) ;
V_118 = F_16 ( V_11 , V_44 ) ;
F_24 ( V_115 , V_137 , V_11 , V_45 + 3 , 2 , V_51 ) ;
V_119 = V_51 ;
}
else
{
F_24 ( V_115 , V_138 , V_11 , V_44 , 2 , F_16 ( V_11 , V_44 ) ) ;
V_118 = F_16 ( V_11 , V_44 ) ;
}
}
V_48 = F_24 ( V_115 , V_139 , V_11 , V_123 , 1 , V_80 ) ;
F_35 ( V_5 -> V_140 , V_141 , L_18 , F_20 ( V_80 , V_142 , L_19 ) ) ;
V_116 = F_22 ( V_48 , V_143 ) ;
F_23 ( V_116 , V_144 , V_11 , V_123 , 1 , V_124 ) ;
F_23 ( V_116 , V_145 , V_11 , V_123 , 1 , V_124 ) ;
F_23 ( V_116 , V_146 , V_11 , V_123 , 1 , V_124 ) ;
F_23 ( V_116 , V_147 , V_11 , V_123 , 1 , V_124 ) ;
F_23 ( V_116 , V_148 , V_11 , V_123 , 1 , V_124 ) ;
F_23 ( V_116 , V_149 , V_11 , V_123 , 1 , V_124 ) ;
F_23 ( V_116 , V_150 , V_11 , V_123 , 1 , V_124 ) ;
V_125 = V_123 + 1 ;
V_50 = F_7 ( V_11 , V_44 + 3 ) ;
if ( V_46 )
V_50 = ( T_4 ) ( ( F_7 ( V_11 , V_45 + 2 ) ^ V_47 [ 2 ] ) << 8 ) + ( F_7 ( V_11 , V_44 + 3 ) ) ;
F_24 ( V_115 , V_151 , V_11 , V_44 + 3 , 1 , V_50 ) ;
if ( ( ( V_80 & V_152 ) == V_152 ) ||
( V_80 == V_153 )
)
{
V_83 = F_11 ( V_11 , V_123 + 1 ) ;
V_82 = F_7 ( V_11 , V_123 + 3 ) ;
F_19 ( V_115 , V_101 , V_11 , V_123 + 1 , 2 ,
V_83 , L_12 , V_83 ,
F_20 ( ( ( T_11 ) ( V_83 << 16 ) ) , V_102 , L_2 ) ) ;
F_35 ( V_5 -> V_140 , V_141 , L_20 , F_20 ( ( ( T_11 ) ( V_83 << 16 ) ) , V_102 , L_21 ) ) ;
if ( V_82 != 0x0 )
{
F_19 ( V_115 , V_104 , V_11 , V_123 + 3 , 1 ,
V_82 , L_13 , V_82 ,
F_20 ( ( ( T_11 ) ( V_83 << 16 ) + V_82 ) , V_102 , L_2 ) ) ;
F_35 ( V_5 -> V_140 , V_141 , L_22 ,
F_20 ( ( ( T_11 ) ( V_83 << 16 ) + V_82 ) , V_102 , L_17 ) ) ;
}
F_35 ( V_5 -> V_140 , V_141 , L_1 , L_23 ) ;
V_125 += 3 ;
}
if ( V_80 == V_153 )
{
V_120 = F_36 ( V_11 , V_44 + V_24 + 4 ) ;
F_19 ( V_115 , V_154 , V_11 , V_125 , 4 , V_120 ,
L_24 , ( T_4 ) ( V_120 >> 16 ) , ( T_4 ) ( V_120 ) ,
F_20 ( V_120 , V_155 , L_2 ) ) ;
} else {
if ( ( V_127 && ( V_80 == V_156 ||
V_80 == V_157 ||
V_80 == V_158 ||
V_80 == V_100 ) ) ||
( ! V_127 && ( V_80 == V_159 ||
V_80 == V_160 ||
V_80 == V_161 ||
V_80 == V_162 ) ) )
{
V_128 = TRUE ;
}
if ( V_128 )
{
V_131 = V_5 -> V_163 ;
if ( V_118 != 0 && V_119 != 0 )
V_122 = ( T_11 ) ( ( ( ( T_11 ) V_119 ) << 16 ) + V_118 ) ;
V_130 = ( ( V_124 & V_164 ) == V_164 ) ;
if ( ( V_80 == V_159 ) ||
( V_80 == V_156 )
)
{
V_125 += 4 ;
V_121 = F_28 ( V_11 , V_125 - 4 ) ;
V_126 = V_13 - ( V_125 - V_123 ) ;
V_48 = F_19 ( V_115 , V_165 , V_11 , V_125 - 4 , 4 ,
V_121 , L_25 , V_121 , V_126 ) ;
if ( V_122 != 0 && V_130 )
{
V_5 -> V_163 = TRUE ;
V_132 = F_37 ( & V_3 , V_11 , V_125 , V_5 ,
V_122 , NULL , 0 , V_126 , TRUE ) ;
F_38 ( & V_3 , V_5 , V_122 , NULL , V_50 ) ;
if ( V_132 != NULL )
{
V_48 = F_39 ( V_115 , V_166 , V_11 , 0 , 0 , NULL , L_26 ) ;
F_21 ( V_48 ) ;
V_79 = F_22 ( V_48 , V_167 ) ;
F_40 ( V_11 , 0 , V_5 , L_27 , V_132 , & V_168 , NULL , V_79 ) ;
}
}
if ( ( T_12 ) V_126 >= ( T_12 ) 0 )
{
F_25 ( V_115 , V_166 , V_11 , V_125 , V_126 , V_77 ) ;
} else {
F_41 ( V_5 , V_48 , L_28 , ( T_8 ) V_126 ) ;
}
}
else
{
V_129 = FALSE ;
if ( ( V_80 == V_162 ) || ( V_80 == V_100 ) )
V_129 = TRUE ;
V_121 = V_13 - ( V_125 - V_123 ) ;
if ( V_122 != 0 && V_130 )
{
V_5 -> V_163 = TRUE ;
V_132 = F_37 ( & V_3 , V_11 , V_125 , V_5 ,
V_122 , NULL , V_50 ,
V_121 , V_129 ? FALSE : TRUE ) ;
}
if ( V_132 )
{
V_48 = F_39 ( V_115 , V_166 , V_11 ,
0 , 0 , NULL , L_26 ) ;
F_21 ( V_48 ) ;
V_79 = F_22 ( V_48 , V_167 ) ;
V_78 = F_40 ( V_11 , 0 , V_5 , L_27 , V_132 ,
& V_168 , NULL , V_79 ) ;
if ( V_129 && V_78 )
{
V_48 = F_19 ( V_79 , V_165 , V_11 , 0 , 0 ,
V_121 , L_29 , V_132 -> V_169 ) ;
F_21 ( V_48 ) ;
F_42 ( V_5 -> V_140 , V_141 , L_30 ) ;
F_26 ( V_5 , V_78 , V_79 , V_80 ) ;
}
}
else
{
V_48 = F_19 ( V_115 , V_165 , V_11 , 0 , 0 , V_121 ,
L_31 , V_121 ) ;
F_21 ( V_48 ) ;
if ( V_83 == V_107 && V_82 == 0x06 )
{
V_86 = F_28 ( V_11 , V_125 ) ;
F_19 ( V_115 , V_105 , V_11 , V_125 ,
4 , V_86 , L_14 , V_86 ) ;
for ( V_81 = 4 ; V_81 < V_121 ; V_81 += 4 )
{
V_86 = F_28 ( V_11 , V_125 + V_81 ) ;
F_19 ( V_115 , V_106 , V_11 , ( V_125 + V_81 ) ,
4 , V_86 , L_15 , ( V_81 / 4 ) , V_86 ) ;
}
} else if ( V_83 == V_107 && V_82 == 0x07 ) {
V_86 = F_28 ( V_11 , V_125 ) ;
F_19 ( V_115 , V_105 , V_11 , V_125 ,
4 , V_86 , L_14 , V_86 ) ;
} else
F_25 ( V_115 , V_166 , V_11 , V_125 , V_121 , V_77 ) ;
}
}
V_5 -> V_163 = V_131 ;
}
}
}
static void
F_43 ( T_5 * V_11 , T_1 * V_5 , T_9 * V_43 ,
T_4 V_44 , T_4 V_45 )
{
T_2 * V_48 ;
T_9 * V_170 ;
T_11 V_86 = 0 ;
T_4 V_171 , V_51 , V_117 ;
T_6 V_124 , V_172 ;
T_8 V_13 ;
char * V_173 ;
V_13 = F_44 ( V_11 , V_44 ) ;
V_171 = F_16 ( V_11 , V_44 ) ;
V_51 = F_16 ( V_11 , V_45 + 3 ) ;
V_117 = F_16 ( V_11 , V_45 ) ^ V_171 ;
V_124 = - 1 ;
if ( V_13 > 0 )
V_124 = F_7 ( V_11 , V_44 + V_24 ) ;
if ( ( ( F_32 ( V_11 , V_44 ) ^ V_174 ) == 0 ) &&
( ( V_124 ^ V_175 ) == 0 || ( V_124 ^ V_176 ) == 0 ) )
{
F_34 ( V_5 , V_171 , V_55 + V_44 , V_45 , V_117 ) ;
}
else
{
F_33 ( V_5 , V_51 , V_55 + V_44 , V_171 , V_45 + 3 ,
V_45 , V_117 ) ;
}
V_48 = F_19 ( V_43 , V_56 , V_11 , V_57 + V_44 , 1 ,
V_177 ,
L_1 , F_20 ( V_177 , V_59 , L_2 ) ) ;
F_21 ( V_48 ) ;
V_170 = F_22 ( V_48 , V_178 ) ;
if ( ( F_32 ( V_11 , V_44 ) == V_179 ) ||
( F_32 ( V_11 , V_44 ) == V_180 ) ||
( F_32 ( V_11 , V_44 ) == V_174 ) )
F_23 ( V_170 , V_62 , V_11 , V_57 + V_44 , 1 , V_63 ) ;
else
F_23 ( V_170 , V_62 , V_11 , V_57 + V_44 , 1 , V_66 ) ;
F_19 ( V_170 , V_67 , V_11 , V_57 + V_44 , 1 ,
F_32 ( V_11 , V_44 ) ,
L_1 , F_20 ( F_32 ( V_11 , V_44 ) , V_68 , L_2 ) ) ;
if ( ( F_32 ( V_11 , V_44 ) ^ V_181 ) == 0 )
{
F_24 ( V_170 , V_182 , V_11 , V_55 + V_44 , 2 , V_171 ) ;
F_24 ( V_170 , V_183 , V_11 , V_45 + 3 , 2 , V_51 ) ;
}
else if ( ( F_32 ( V_11 , V_44 ) ^ V_174 ) == 0 )
{
F_24 ( V_170 , V_184 , V_11 , V_24 + V_44 , 1 , V_124 ) ;
F_35 ( V_5 -> V_140 , V_141 , L_32 , F_20 ( V_124 , V_185 , L_2 ) ) ;
F_24 ( V_170 , V_182 , V_11 , V_55 + V_44 , 2 , V_171 ) ;
F_24 ( V_170 , V_183 , V_11 , V_45 + 3 , 2 , V_51 ) ;
if ( ( V_124 ^ V_186 ) == 0 )
{
V_172 = F_7 ( V_11 , V_24 + V_44 + 1 ) ;
F_45 ( V_170 , V_187 , V_11 , V_24 + V_44 + 1 , 1 ,
V_172 , L_1 , ( V_172 == 0 ? L_33 : F_46 ( V_172 , V_188 , L_34 ) ) ) ;
V_172 = F_7 ( V_11 , V_24 + V_44 + 2 ) ;
F_45 ( V_170 , V_189 , V_11 , V_24 + V_44 + 2 , 1 ,
V_172 , L_35 , ( V_172 == 0 ? L_36 : L_37 ) , V_172 ) ;
}
else if ( ( V_124 ^ V_190 ) == 0 )
{
V_48 = F_25 ( V_170 , V_191 , V_11 , V_24 + V_44 + 1 , 6 , V_77 ) ;
if ( V_192 == TRUE )
{
V_173 = ( char * ) F_47 ( 128 * sizeof( char ) ) ;
F_48 ( V_173 , 18 , L_1 , F_49 ( V_11 , V_24 + V_44 + 1 , 6 , ':' ) ) ;
if ( memcmp ( V_193 , V_173 , 17 ) != 0 )
{
V_2 = ( char * ) F_50 ( 18 * sizeof( char ) ) ;
F_48 ( V_2 , 18 , L_1 , V_173 ) ;
F_5 ( V_5 , V_48 , V_194 , V_195 , L_38 , V_173 ) ;
}
}
}
}
else if ( ( F_32 ( V_11 , V_44 ) ^ V_196 ) == 0 )
{
F_24 ( V_170 , V_184 , V_11 , V_24 + V_44 , 1 , V_124 ) ;
F_35 ( V_5 -> V_140 , V_141 , L_32 , F_20 ( V_124 , V_185 , L_2 ) ) ;
if ( ( V_124 ^ V_175 ) == 0 || ( V_124 ^ V_176 ) == 0 )
{
F_24 ( V_170 , V_197 , V_11 , V_55 + V_44 , 2 , V_171 ) ;
F_24 ( V_170 , V_198 , V_11 , V_45 + 3 , 2 , V_51 ) ;
}
else if ( ( V_124 ^ V_199 ) == 0 )
{
F_24 ( V_170 , V_182 , V_11 , V_55 + V_44 , 2 , V_171 ) ;
F_24 ( V_170 , V_183 , V_11 , V_45 + 3 , 2 , V_51 ) ;
V_48 = F_25 ( V_170 , V_191 , V_11 , V_24 + V_44 + 1 , 6 , V_77 ) ;
if ( V_192 == TRUE )
{
V_173 = ( char * ) F_47 ( 18 * sizeof( char ) ) ;
F_48 ( V_173 , 18 , L_1 , F_49 ( V_11 , V_24 + V_44 + 1 , 6 , ':' ) ) ;
if ( memcmp ( V_193 , V_173 , 17 ) != 0 )
{
V_2 = ( char * ) F_50 ( 18 * sizeof( char ) ) ;
F_48 ( V_2 , 18 , L_1 , V_173 ) ;
F_5 ( V_5 , V_48 , V_194 , V_195 , L_38 , V_173 ) ;
}
}
}
else
{
F_24 ( V_170 , V_182 , V_11 , V_45 + 3 , 2 , V_51 ) ;
F_24 ( V_170 , V_183 , V_11 , V_55 + V_44 , 2 , V_171 ) ;
if ( ( V_124 ^ V_200 ) == 0 )
{
V_86 = F_28 ( V_11 , V_44 + V_24 + 1 ) ;
F_19 ( V_170 , V_105 , V_11 ,
V_24 + V_44 + 1 , 4 , V_86 , L_14 , V_86 ) ;
}
}
}
else if ( ( F_32 ( V_11 , V_44 ) ^ V_180 ) == 0 )
{
F_24 ( V_170 , V_182 , V_11 , V_55 + V_44 , 2 , V_171 ) ;
F_24 ( V_170 , V_183 , V_11 , V_45 + 3 , 2 , V_51 ) ;
if ( V_13 > 0 )
F_25 ( V_170 , V_191 , V_11 , V_24 + V_44 , 6 , V_77 ) ;
}
else if ( ( F_32 ( V_11 , V_44 ) ^ V_201 ) == 0 )
{
F_24 ( V_170 , V_182 , V_11 , V_45 + 3 , 2 , V_51 ) ;
F_24 ( V_170 , V_183 , V_11 , V_55 + V_44 , 2 , V_171 ) ;
if ( V_13 > 0 )
F_25 ( V_170 , V_191 , V_11 , V_24 + V_44 , 6 , V_77 ) ;
}
else if ( ( F_32 ( V_11 , V_44 ) ^ V_179 ) == 0 )
{
F_24 ( V_170 , V_182 , V_11 , V_55 + V_44 , 2 , V_171 ) ;
F_24 ( V_170 , V_183 , V_11 , V_45 + 3 , 2 , V_51 ) ;
if ( V_13 > 0 )
F_25 ( V_170 , V_191 , V_11 , V_24 + V_44 , 6 , V_77 ) ;
}
else if ( ( F_32 ( V_11 , V_44 ) ^ V_202 ) == 0 )
{
F_24 ( V_170 , V_182 , V_11 , V_45 + 3 , 2 , V_51 ) ;
F_24 ( V_170 , V_183 , V_11 , V_55 + V_44 , 2 , V_171 ) ;
}
}
static T_7
F_51 ( T_5 * V_11 , T_9 * V_43 ,
T_4 V_44 , T_4 V_45 )
{
T_4 V_203 , V_204 ;
T_4 V_205 ;
T_8 V_13 ;
T_6 * V_22 ;
T_2 * V_48 ;
T_9 * V_206 ;
T_12 V_207 ;
T_12 V_208 ;
T_7 V_209 = FALSE ;
V_13 = F_44 ( V_11 , V_44 ) ;
V_207 = V_24 + V_13 + V_44 ;
if ( F_44 ( V_11 , V_44 ) > V_23 )
V_203 = F_11 ( V_11 , V_207 ) ;
else
V_203 = F_7 ( V_11 , V_207 ) ;
V_208 = ( V_13 > V_23 ? V_210 : V_211 ) ;
V_48 = F_45 ( V_43 , V_212 , V_11 , V_207 , V_208 , V_203 ,
L_39 , V_203 ) ;
V_206 = F_22 ( V_48 , V_213 ) ;
V_22 = ( T_6 * ) F_8 ( V_11 , V_44 , V_13 + 4 ) ;
if ( V_13 > V_23 )
V_205 = F_9 ( & V_22 [ V_44 ] , V_13 + 4 , 0 ) ;
else
V_205 = F_10 ( & V_22 [ V_44 ] , V_13 + 4 , 0 ) ;
V_48 = F_23 ( V_206 , V_214 , V_11 , V_207 , V_208 , ( V_203 == V_205 ) ) ;
F_21 ( V_48 ) ;
F_24 ( V_206 , V_215 , V_11 , V_207 , V_208 ,
( V_13 > V_23 ? V_210 : V_211 ) ) ;
if ( ( F_32 ( V_11 , V_44 ) & V_42 ) == V_42 )
V_209 = TRUE ;
V_207 = V_45 + ( V_209 ? 5 : V_13 + V_24 + 1 ) ;
if ( F_44 ( V_11 , V_44 ) > V_23 )
V_204 = F_11 ( V_11 , V_207 ) ;
else
V_204 = F_7 ( V_11 , V_207 ) ;
F_45 ( V_43 , V_212 , V_11 , V_207 , V_208 , V_204 ,
L_40 , V_204 ) ;
return ( T_7 ) ( V_203 == V_205 ) ;
}
static T_7
F_52 ( T_4 V_44 , T_4 V_45 , T_6 type ,
T_5 * V_11 , T_1 * V_5 ,
T_2 * V_216 , T_9 * V_43 , T_6 V_217 )
{
T_6 V_39 , V_33 ;
T_6 V_47 [ 6 ] ;
T_14 * V_218 = NULL ;
T_7 V_46 ;
T_2 * V_48 ;
T_7 V_219 , V_220 ;
V_219 = FALSE ;
for ( V_33 = 0 ; V_33 < 6 ; V_33 ++ )
V_47 [ V_33 ] = 0 ;
V_39 = F_32 ( V_11 , V_44 ) ;
if ( type == V_58 )
V_39 = V_39 & 0xF8 ;
F_35 ( V_5 -> V_140 , V_141 , ( V_217 > 1 ? L_41 : L_1 ) ,
F_46 ( V_39 , V_68 , L_42 ) ) ;
{
if ( type == V_177 )
{
F_43 ( V_11 , V_5 , V_43 , V_44 , V_45 ) ;
}
else
{
V_46 = FALSE ;
V_218 = F_53 () ;
if ( F_54 ( ( V_2 != NULL ? V_2 : V_193 ) , V_218 , TRUE ) && V_218 -> V_169 == 6 )
{
V_46 = TRUE ;
V_39 = F_32 ( V_11 , V_45 ) ^ ( T_6 ) ( V_218 -> V_221 [ V_57 ] ) ;
if ( ( F_32 ( V_11 , V_44 ) ^ V_39 ) != 0 )
V_46 = FALSE ;
else
for ( V_33 = 0 ; V_33 < 6 ; V_33 ++ )
V_47 [ V_33 ] = V_218 -> V_221 [ V_33 ] ;
}
if ( strlen ( ( V_2 != NULL ? V_2 : V_193 ) ) > 0 && V_218 -> V_169 == 6 )
{
if ( V_2 != NULL )
V_48 = F_55 ( V_43 , V_222 , V_11 , 0 , 0 , V_2 ) ;
else
V_48 = F_55 ( V_43 , V_223 , V_11 , 0 , 0 , V_193 ) ;
F_21 ( V_48 ) ;
}
V_48 = F_23 ( V_43 , V_224 , V_11 , 0 , 0 , V_46 ) ;
if ( V_218 -> V_169 != 6 )
F_56 ( V_5 , V_48 , L_43 ) ;
F_21 ( V_48 ) ;
F_57 ( V_218 , TRUE ) ;
if ( type == V_134 || type == V_42 )
{
F_31 ( V_11 , V_5 , V_43 , V_44 , V_45 , V_46 , V_47 ) ;
}
else if ( type == V_58 )
{
F_15 ( V_11 , V_5 , V_43 , V_44 , V_45 , V_46 , V_47 ) ;
}
else
{
V_219 = TRUE ;
}
}
V_220 = FALSE ;
V_48 = F_24 ( V_43 , V_225 ,
V_11 , V_54 + V_44 , 1 , F_44 ( V_11 , V_44 ) ) ;
if ( V_219 )
{
F_30 ( V_5 , V_48 , L_44 ) ;
}
else
{
V_220 = F_51 ( V_11 , V_43 , V_44 , V_45 ) ;
}
if ( ! V_220 )
{
F_30 ( V_5 , V_216 , L_45 ) ;
}
if ( V_220 && type == V_177 )
{
if ( F_32 ( V_11 , V_44 ) != F_32 ( V_11 , V_45 ) )
F_30 ( V_5 , V_216 , L_46 ) ;
}
}
return TRUE ;
}
static T_7
F_58 ( const T_15 * V_226 , const T_15 * V_227 ,
T_7 V_228 , T_7 V_229 , T_6 V_230 ,
T_5 * V_231 , T_1 * V_5 , T_9 * V_232 )
{
T_5 * V_233 , * V_11 = NULL ;
T_8 V_208 , V_169 , V_234 , V_235 , V_236 ;
T_6 * V_22 ;
T_7 V_237 , V_238 , V_239 , V_240 ;
T_6 type , V_40 , V_241 , V_242 , V_243 ;
T_4 V_44 , V_45 , V_12 ;
T_12 V_244 ;
T_16 V_245 = NULL ;
T_2 * V_216 ;
T_9 * V_43 ;
V_237 = FALSE ;
V_238 = FALSE ;
V_239 = FALSE ;
V_240 = FALSE ;
F_59 ( V_5 , F_1 ) ;
V_208 = F_60 ( V_231 ) ;
if ( V_208 < V_41 )
return FALSE ;
if ( strlen ( V_227 ) > 0 )
{
V_239 = TRUE ;
V_245 = F_61 ( V_227 ) ;
if ( V_245 == NULL )
V_245 = F_61 ( L_47 ) ;
}
V_244 = F_13 ( V_231 , 0 ) ;
V_22 = ( T_6 * ) F_8 ( V_231 , 0 , V_208 ) ;
if ( V_229 == TRUE && V_246 == TRUE )
{
V_169 = ( V_208 / 2 ) ;
for ( V_242 = 0 ; V_242 < V_169 ; V_242 ++ )
{
V_243 = V_22 [ 2 * V_242 ] ; V_22 [ 2 * V_242 ] = V_22 [ 2 * V_242 + 1 ] ; V_22 [ 2 * V_242 + 1 ] = V_243 ;
}
V_11 = F_62 ( V_22 , V_208 , V_244 ) ;
} else {
V_11 = V_231 ;
}
V_234 = 0 ;
V_235 = 0 ;
V_40 = 0 ;
V_241 = 0 ;
while ( V_234 < V_208 )
{
if ( F_63 ( V_11 , V_234 ) < V_41 )
break;
if ( F_12 ( V_11 , V_234 , V_228 , & V_234 , & V_235 ) )
{
if ( ( V_234 + V_235 ) > ( T_8 ) V_244 )
break;
V_40 ++ ;
V_12 = ( V_228 ? 0 : V_234 ) ;
if ( V_228 )
{
V_44 = F_6 ( V_11 , V_12 , V_235 , FALSE ) ;
V_45 = 0 ;
}
else
{
V_44 = 0 ;
V_45 = ( ( F_44 ( V_11 , V_12 + V_44 ) - 1 ) +
( F_44 ( V_11 , V_12 + V_44 ) > V_23 ? V_247 : V_25 ) ) ;
}
if ( V_44 == V_45 )
{
V_40 -- ;
V_234 += V_235 ;
continue;
}
if ( ( F_32 ( V_11 , V_12 + V_44 ) & V_42 ) == V_42 )
type = V_42 ;
else if ( ( F_32 ( V_11 , V_12 + V_44 ) & V_134 ) == V_134 )
type = V_134 ;
else if ( ( F_32 ( V_11 , V_12 + V_44 ) & V_58 ) == V_58 )
type = V_58 ;
else if ( ( F_32 ( V_11 , V_12 + V_44 ) & V_177 ) == V_177 )
type = V_177 ;
else
{
if ( V_228 )
{
V_44 = F_6 ( V_11 , ( V_228 ? 0 : V_234 ) , V_235 , TRUE ) ;
V_45 = 0 ;
if ( ( F_32 ( V_11 , V_12 + V_44 ) & V_42 ) == V_42 )
type = V_42 ;
else if ( ( F_32 ( V_11 , V_12 + V_44 ) & V_134 ) == V_134 )
type = V_134 ;
else if ( ( F_32 ( V_11 , V_12 + V_44 ) & V_58 ) == V_58 )
type = V_58 ;
else if ( ( F_32 ( V_11 , V_12 + V_44 ) & V_177 ) == V_177 )
type = V_177 ;
else {
V_234 += 2 ;
V_40 -- ;
continue;
}
} else {
V_234 += 2 ;
V_40 -- ;
continue;
}
}
if ( type != V_58 )
{
T_12 V_248 = - 1 ;
F_64 ( F_32 ( V_11 , V_12 + V_44 ) , V_68 , & V_248 ) ;
if ( V_248 < 0 )
{
V_234 += 2 ;
V_40 -- ;
continue;
}
else if ( type == V_177 &&
( F_32 ( V_11 , V_12 + V_44 ) != F_32 ( V_11 , V_12 + V_45 ) ) )
{
V_234 += 2 ;
V_40 -- ;
continue;
}
}
if ( type == V_58 )
{
V_236 = F_16 ( V_11 , V_12 + V_44 ) ;
if ( V_236 > 1024 ) {
V_240 = TRUE ;
}
}
if ( ( ( T_12 ) V_235 - ( T_12 ) ( V_45 > V_44 ? V_45 : V_235 - V_44 ) ) < 0 )
return FALSE ;
if ( V_229 == TRUE && V_246 == TRUE )
{
V_233 = F_65 ( V_11 , & V_22 [ V_234 ] , ( V_235 ) , V_244 ) ;
F_66 ( V_5 , V_233 , L_48 ) ;
}
else
{
V_233 = F_67 ( V_11 , V_234 , V_235 , V_244 ) ;
F_66 ( V_5 , V_233 , L_49 ) ;
}
if ( V_230 > 0 )
{
V_40 = V_230 + 1 ;
V_238 = TRUE ;
F_68 ( V_5 -> V_140 , V_249 , V_226 ) ;
}
if ( ! V_238 )
{
if ( V_239 )
F_69 ( V_245 , V_11 , V_5 , V_232 ) ;
V_238 = TRUE ;
F_68 ( V_5 -> V_140 , V_249 , V_226 ) ;
F_70 ( V_5 -> V_140 , V_141 ) ;
}
if ( V_232 )
{
V_216 = F_25 ( V_232 , V_250 , V_11 , V_234 , V_235 , V_92 ) ;
V_43 = F_22 ( V_216 , V_251 ) ;
} else {
V_216 = NULL ;
V_43 = NULL ;
}
if ( F_52 ( V_44 , V_45 , type , V_233 , V_5 , V_216 , V_43 , V_40 ) == TRUE )
V_241 ++ ;
else
V_240 = TRUE ;
if ( V_232 && V_240 )
{
if ( F_16 ( V_11 , V_12 + V_44 ) > 1024 )
F_30 ( V_5 , V_216 , L_50 ) ;
}
V_237 = TRUE ;
}
else
break;
V_234 += V_235 ;
}
if ( V_237 == TRUE && V_241 == 0 )
V_237 = FALSE ;
if ( ! V_237 )
{
if ( V_239 )
F_69 ( V_245 , V_11 , V_5 , V_232 ) ;
V_237 = TRUE ;
}
return ( V_237 ? TRUE : FALSE ) ;
}
static T_7
F_71 ( T_5 * V_11 , T_1 * V_5 , T_9 * V_232 , void * V_221 V_252 )
{
T_7 V_253 = FALSE ;
T_6 V_254 ;
if ( ! V_255 )
return V_253 ;
if ( V_1 == FALSE )
{
V_1 = TRUE ;
V_254 = ( F_7 ( V_11 , 0 ) << 1 ) ;
if ( ( V_254 != 0x02 ) && ( V_254 != 0x0A ) )
{
V_253 = F_58 ( L_51 , L_52 ,
FALSE , FALSE , 0 , V_11 , V_5 , V_232 ) ;
}
V_1 = FALSE ;
}
return V_253 ;
}
static T_7
F_72 ( T_5 * V_11 , T_1 * V_5 , T_9 * V_232 , void * V_221 V_252 )
{
T_7 V_253 = FALSE ;
T_6 V_254 ;
if ( ! V_256 )
return V_253 ;
if ( V_5 -> V_257 == V_258 )
{
return F_58 ( L_53 , L_6 , FALSE , FALSE , 0 , V_11 , V_5 , V_232 ) ;
}
if ( V_1 == FALSE )
{
V_1 = TRUE ;
V_254 = ( F_7 ( V_11 , 0 ) << 1 ) ;
if ( ( V_254 & 0x40 ) == 0x40 )
{
V_253 = F_58 ( L_54 , L_55 ,
FALSE , FALSE , 0 , V_11 , V_5 , V_232 ) ;
}
V_1 = FALSE ;
}
return V_253 ;
}
static T_7
F_73 ( T_5 * V_11 , T_1 * V_5 , T_9 * V_232 , void * V_221 V_252 )
{
T_7 V_253 = FALSE ;
if ( ! V_259 )
return V_253 ;
if ( V_1 == FALSE )
{
V_1 = TRUE ;
V_253 = F_58 ( L_56 , L_57 ,
FALSE , FALSE , 0 , V_11 , V_5 , V_232 ) ;
V_1 = FALSE ;
}
return V_253 ;
}
static T_7
F_74 ( T_5 * V_11 , T_1 * V_5 , T_9 * V_232 , void * V_221 V_252 )
{
if ( ! V_260 )
return FALSE ;
return F_58 ( L_58 , L_6 , FALSE , TRUE , 0 ,
V_11 , V_5 , ( V_232 -> V_261 != NULL ? V_232 -> V_261 : V_232 ) ) ;
}
static T_7
F_75 ( T_5 * V_11 , T_1 * V_5 , T_9 * V_232 , void * V_221 V_252 )
{
T_7 V_253 = FALSE ;
static T_11 V_262 = 0 ;
static T_11 V_263 = 0 ;
if ( ! V_264 )
return V_253 ;
if ( F_27 ( V_11 ) < V_41 )
return V_253 ;
if ( V_5 -> V_265 -> V_266 != V_262 )
{
V_263 = 0 ;
V_262 = V_5 -> V_265 -> V_266 ;
}
V_253 = F_58 ( ( V_5 -> V_267 == V_268 ? L_54 : L_59 ) ,
L_6 , V_5 -> V_267 == V_268 ? V_269 : V_270 ,
FALSE , V_263 , V_11 , V_5 , V_232 ) ;
if ( V_253 )
V_263 ++ ;
return V_253 ;
}
static void
F_76 ( void )
{
static T_7 V_271 = FALSE ;
static T_8 V_272 ;
static T_8 V_273 ;
if ( V_271 )
{
F_77 ( L_60 , V_272 , F_61 ( L_61 ) ) ;
F_77 ( L_60 , V_273 , F_61 ( L_62 ) ) ;
}
V_271 = TRUE ;
V_272 = V_274 ;
V_273 = V_275 ;
F_78 ( L_60 , V_272 , F_61 ( L_61 ) ) ;
F_78 ( L_60 , V_273 , F_61 ( L_62 ) ) ;
}
void
F_79 ( void )
{
static T_17 V_276 [] = {
{ & V_223 ,
{ L_63 , L_64 ,
V_277 , V_278 , NULL , 0x0 , NULL , V_279 } } ,
{ & V_222 ,
{ L_65 , L_66 ,
V_277 , V_278 , NULL , 0x0 , NULL , V_279 } } ,
{ & V_224 ,
{ L_67 , L_68 ,
V_280 , V_278 , NULL , 0x0 , NULL , V_279 } } ,
{ & V_67 ,
{ L_69 , L_70 ,
V_281 , V_282 , F_80 ( V_68 ) , 0x0 , NULL , V_279 } } ,
{ & V_56 ,
{ L_71 , L_72 ,
V_283 , V_282 , F_80 ( V_59 ) , 0x0 , NULL , V_279 } } ,
{ & V_62 ,
{ L_73 , L_74 ,
V_280 , V_278 , F_81 ( & V_284 ) , 0x0 , NULL , V_279 } } ,
{ & V_285 ,
{ L_75 , L_76 ,
V_283 , V_282 , NULL , 0x0 , NULL , V_279 } } ,
{ & V_286 ,
{ L_77 , L_78 ,
V_283 , V_282 , NULL , 0x0 , NULL , V_279 } } ,
{ & V_287 ,
{ L_79 , L_80 ,
V_283 , V_282 , NULL , 0x0 , NULL , V_279 } } ,
{ & V_288 ,
{ L_81 , L_82 ,
V_283 , V_282 , NULL , 0x0 , NULL , V_279 } } ,
{ & V_225 ,
{ L_83 , L_84 ,
V_281 , V_289 , NULL , 0x0 , NULL , V_279 } } ,
{ & V_212 ,
{ L_85 , L_86 ,
V_283 , V_282 , NULL , 0x0 , NULL , V_279 } } ,
{ & V_214 ,
{ L_87 , L_88 ,
V_280 , V_278 , NULL , 0x0 , NULL , V_279 } } ,
{ & V_215 ,
{ L_89 , L_90 ,
V_281 , V_289 , F_80 ( V_290 ) , 0x0 , NULL , V_279 } } ,
{ & V_183 ,
{ L_91 , L_92 ,
V_283 , V_282 , NULL , 0x0 , NULL , V_279 } } ,
{ & V_182 ,
{ L_93 , L_94 ,
V_283 , V_282 , NULL , 0x0 , NULL , V_279 } } ,
{ & V_197 ,
{ L_95 , L_96 ,
V_283 , V_282 , NULL , 0x0 , NULL , V_279 } } ,
{ & V_198 ,
{ L_97 , L_98 ,
V_283 , V_282 , NULL , 0x0 , NULL , V_279 } } ,
{ & V_191 ,
{ L_99 , L_100 ,
V_291 , V_278 , NULL , 0x0 , NULL , V_279 } } ,
{ & V_184 ,
{ L_101 , L_102 ,
V_281 , V_282 , F_80 ( V_185 ) , 0x0 , NULL , V_279 } } ,
{ & V_187 ,
{ L_103 , L_104 ,
V_281 , V_289 , NULL , 0x0 , NULL , V_279 } } ,
{ & V_189 ,
{ L_105 , L_106 ,
V_281 , V_289 , NULL , 0x0 , NULL , V_279 } } ,
{ & V_138 ,
{ L_107 , L_108 ,
V_283 , V_282 , NULL , 0x0 , NULL , V_279 } } ,
{ & V_137 ,
{ L_109 , L_110 ,
V_283 , V_282 , NULL , 0x0 , NULL , V_279 } } ,
{ & V_151 ,
{ L_111 , L_112 ,
V_283 , V_289 , NULL , 0x0 , NULL , V_279 } } ,
{ & V_139 ,
{ L_113 , L_114 ,
V_281 , V_282 , F_80 ( V_142 ) , 0x0 , NULL , V_279 } } ,
{ & V_101 ,
{ L_115 , L_116 ,
V_283 , V_282 , NULL , 0x0 , NULL , V_279 } } ,
{ & V_104 ,
{ L_117 , L_118 ,
V_281 , V_282 , NULL , 0x0 , NULL , V_279 } } ,
{ & V_166 ,
{ L_119 , L_120 ,
V_292 , V_278 , NULL , 0x0 , NULL , V_279 } } ,
{ & V_165 ,
{ L_121 , L_122 ,
V_293 , V_289 , NULL , 0x0 , NULL , V_279 } } ,
{ & V_110 ,
{ L_123 , L_124 ,
V_293 , V_289 , NULL , 0x0 , NULL , V_279 } } ,
{ & V_114 ,
{ L_125 , L_126 ,
V_292 , V_278 , NULL , 0x0 , NULL , V_279 } } ,
{ & V_105 ,
{ L_127 , L_128 ,
V_293 , V_282 , NULL , 0x0 , NULL , V_279 } } ,
{ & V_106 ,
{ L_129 , L_130 ,
V_293 , V_282 , NULL , 0x0 , NULL , V_279 } } ,
{ & V_111 ,
{ L_131 , L_132 ,
V_294 , V_278 , NULL , 0x0 , NULL , V_279 } } ,
{ & V_113 ,
{ L_133 , L_134 ,
V_281 , V_289 , NULL , 0x0 , NULL , V_279 } } ,
{ & V_91 ,
{ L_135 , L_136 ,
V_281 , V_289 , NULL , 0x0 , NULL , V_279 } } ,
{ & V_93 ,
{ L_137 , L_138 ,
V_281 , V_289 , NULL , 0x0 , NULL , V_279 } } ,
{ & V_94 ,
{ L_139 , L_140 ,
V_281 , V_282 , NULL , 0x0 , NULL , V_279 } } ,
{ & V_96 ,
{ L_141 , L_142 ,
V_281 , V_282 , NULL , 0x0 , NULL , V_279 } } ,
{ & V_97 ,
{ L_143 , L_144 ,
V_281 , V_282 , NULL , 0x0 , NULL , V_279 } } ,
{ & V_98 ,
{ L_145 , L_146 ,
V_281 , V_282 , NULL , 0x0 , NULL , V_279 } } ,
{ & V_99 ,
{ L_147 , L_148 ,
V_292 , V_278 , NULL , 0x0 , NULL , V_279 } } ,
{ & V_89 ,
{ L_149 , L_150 ,
V_277 , V_278 , NULL , 0x0 , NULL , V_279 } } ,
{ & V_295 ,
{ L_151 , L_152 ,
V_294 , V_278 , NULL , 0x00 , NULL , V_279 } } ,
{ & V_296 ,
{ L_153 , L_154 ,
V_297 , V_278 , NULL , 0x00 , NULL , V_279 } } ,
{ & V_298 ,
{ L_155 , L_156 ,
V_280 , 0 , NULL , 0x00 , NULL , V_279 } } ,
{ & V_299 ,
{ L_157 ,
L_158 ,
V_280 , 0 , NULL , 0x00 , NULL , V_279 } } ,
{ & V_300 ,
{ L_159 , L_160 ,
V_280 , 0 , NULL , 0x00 , NULL , V_279 } } ,
{ & V_301 ,
{ L_161 , L_162 ,
V_280 , 0 , NULL , 0x00 , NULL , V_279 } } ,
{ & V_302 ,
{ L_163 , L_164 ,
V_297 , V_278 , NULL , 0x00 , NULL , V_279 } } ,
{ & V_303 ,
{ L_165 , L_166 ,
V_293 , V_289 , NULL , 0x00 , NULL , V_279 } } ,
{ & V_304 ,
{ L_167 , L_168 ,
V_297 , V_278 , NULL , 0x00 , NULL , V_279 } } ,
{ & V_305 ,
{ L_169 , L_170 ,
V_293 , V_289 , NULL , 0x00 , NULL , V_279 } } ,
{ & V_306 ,
{ L_171 , L_172 ,
V_292 , V_278 , NULL , 0x00 , NULL , V_279 } } ,
#if 0
{ &hf_oss_ssdo_inhibit_time,
{ "Inhibit Time", "opensafety.ssdo.inhibittime",
FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL } },
#endif
{ & V_154 ,
{ L_173 , L_174 ,
V_293 , V_282 , NULL , 0x0 , NULL , V_279 } } ,
{ & V_150 ,
{ L_175 , L_176 ,
V_280 , 8 , F_81 ( & V_307 ) , V_308 , NULL , V_279 } } ,
#if 0
{ &hf_oss_ssdo_sacmd_reserved,
{ "Reserved", "opensafety.ssdo.sacmd.reserved",
FT_BOOLEAN, 8, TFS(&opensafety_sacmd_res), OPENSAFETY_SSDO_SACMD_RES, NULL, HFILL } },
#endif
{ & V_149 ,
{ L_177 , L_178 ,
V_280 , 8 , F_81 ( & V_309 ) , V_310 , NULL , V_279 } } ,
{ & V_148 ,
{ L_179 , L_180 ,
V_280 , 8 , F_81 ( & V_311 ) , V_164 , NULL , V_279 } } ,
{ & V_147 ,
{ L_181 , L_182 ,
V_280 , 8 , F_81 ( & V_312 ) , V_133 , NULL , V_279 } } ,
{ & V_146 ,
{ L_183 , L_184 ,
V_280 , 8 , F_81 ( & V_313 ) , V_152 , NULL , V_279 } } ,
{ & V_145 ,
{ L_185 , L_186 ,
V_280 , 8 , F_81 ( & V_314 ) , V_315 , NULL , V_279 } } ,
{ & V_144 ,
{ L_187 , L_188 ,
V_280 , 8 , F_81 ( & V_316 ) , V_317 , NULL , V_279 } } ,
{ & V_70 ,
{ L_189 , L_190 ,
V_280 , V_278 , F_81 ( & V_318 ) , 0x0 , NULL , V_279 } } ,
{ & V_76 ,
{ L_191 , L_192 ,
V_292 , V_278 , NULL , 0x0 , NULL , V_279 } } ,
{ & V_69 ,
{ L_193 , L_194 ,
V_283 , V_282 , NULL , 0x0 , NULL , V_279 } } ,
{ & V_74 ,
{ L_195 , L_196 ,
V_283 , V_282 , NULL , 0x0 , NULL , V_279 } } ,
{ & V_71 ,
{ L_197 , L_198 ,
V_283 , V_282 , NULL , 0x0 , NULL , V_279 } } ,
{ & V_72 ,
{ L_199 , L_200 ,
V_281 , V_282 , NULL , 0x0 , NULL , V_279 } } ,
{ & V_75 ,
{ L_201 , L_202 ,
V_283 , V_282 , NULL , 0x0 , NULL , V_279 } } ,
{ & V_73 ,
{ L_203 , L_204 ,
V_283 , V_282 , NULL , 0x0 , NULL , V_279 } } ,
} ;
static T_12 * V_319 [] = {
& V_251 ,
& V_320 ,
& V_321 ,
& V_213 ,
& V_178 ,
& V_135 ,
& V_143 ,
& V_322 ,
& V_323 ,
& V_167 ,
& V_103 ,
& V_112 ,
& V_90 ,
& V_60 ,
} ;
T_18 * V_324 ;
V_250 = F_82 ( L_205 , L_205 , L_206 ) ;
V_324 = F_83 ( V_250 , F_76 ) ;
F_84 ( V_250 , V_276 , F_85 ( V_276 ) ) ;
F_86 ( V_319 , F_85 ( V_319 ) ) ;
F_87 ( V_324 , L_207 ,
L_208 ,
L_209 ,
& V_193 ) ;
F_88 ( V_324 , L_210 ,
L_211 ,
L_212 ,
& V_192 ) ;
F_89 ( V_324 , L_213 ,
L_214 ,
L_215 , 10 ,
& V_274 ) ;
F_89 ( V_324 , L_216 ,
L_217 ,
L_218 , 10 ,
& V_275 ) ;
F_88 ( V_324 , L_219 ,
L_220 ,
L_221 ,
& V_269 ) ;
F_88 ( V_324 , L_222 ,
L_223 ,
L_224 ,
& V_270 ) ;
F_88 ( V_324 , L_225 ,
L_226 ,
L_227 ,
& V_246 ) ;
F_88 ( V_324 , L_228 ,
L_229 , L_229 ,
& V_255 ) ;
F_88 ( V_324 , L_230 ,
L_231 , L_231 ,
& V_264 ) ;
F_88 ( V_324 , L_232 ,
L_233 , L_233 ,
& V_325 ) ;
F_88 ( V_324 , L_234 ,
L_235 , L_235 ,
& V_256 ) ;
F_88 ( V_324 , L_236 ,
L_237 , L_237 ,
& V_259 ) ;
F_88 ( V_324 , L_238 ,
L_239 , L_239 ,
& V_260 ) ;
F_90 ( L_61 , F_75 , V_250 ) ;
F_90 ( L_240 , F_74 , V_250 ) ;
F_90 ( L_62 , F_72 , V_250 ) ;
F_90 ( L_241 , F_73 , V_250 ) ;
}
void
F_91 ( void )
{
static int V_326 = FALSE ;
if ( ! V_326 )
{
F_92 ( L_52 , F_71 , V_250 ) ;
F_92 ( L_55 , F_72 , V_250 ) ;
if ( F_61 ( L_242 ) != NULL )
F_92 ( L_242 , F_75 , V_250 ) ;
F_93 ( L_243 , L_47 , F_61 ( L_240 ) ) ;
if ( F_61 ( L_57 ) != NULL )
{
F_92 ( L_57 , F_73 , V_250 ) ;
}
else
{
F_78 ( L_244 , V_327 , F_61 ( L_241 ) ) ;
}
F_94 ( F_2 ) ;
}
}
