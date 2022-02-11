static int F_1 ( void T_1 * V_1 , void T_2 * V_2 , T_3 V_3 )
{
void * V_4 = F_2 ( V_3 , V_5 ) ;
int V_6 = - V_7 ;
if ( V_4 ) {
F_3 ( V_4 , V_2 , V_3 ) ;
V_6 = F_4 ( V_1 , V_4 , V_3 ) ;
F_5 ( V_4 ) ;
}
return V_6 ;
}
int F_6 ( struct V_8 * V_9 , T_4 V_10 , int V_11 , unsigned long V_12 , int V_13 )
{
T_5 V_14 ;
T_5 V_15 ;
struct V_14 * V_16 ;
T_6 V_17 ;
int V_18 ;
struct V_19 * V_20 ;
struct V_21 T_2 * V_22 ;
int V_23 = 0 ;
unsigned long V_24 ;
void T_1 * V_25 = ( void T_1 * ) V_12 ;
F_7 () ;
V_14 = 0 ;
V_20 = NULL ;
F_8 ( V_26 , L_1 , V_11 , V_25 ) ;
switch ( V_11 ) {
case V_27 :
F_8 ( V_26 , L_2 , V_12 ) ;
{
int V_28 , V_29 ;
V_28 = ( V_12 >> 16 ) & 0x0000FFFF ;
V_29 = V_12 & 0x0000ffff ;
if ( V_28 == - 1 ) {
for ( V_28 = 0 ; V_28 < V_9 -> V_30 ; V_28 ++ ) {
if ( V_9 -> V_31 [ V_28 ] . V_32 == V_33 ) {
F_9 ( V_29 , & V_9 -> V_31 [ V_28 ] . V_34 -> V_35 ) ;
}
}
} else if ( V_28 >= V_9 -> V_30 ) {
return - V_36 ;
} else {
if ( V_9 -> V_31 [ V_28 ] . V_32 == V_33 ) {
F_9 ( V_29 , & V_9 -> V_31 [ V_28 ] . V_34 -> V_35 ) ;
}
}
}
return 0 ;
case V_37 :
F_8 ( V_26 , L_3 ) ;
return F_10 ( V_9 , V_12 , V_38 ) ;
case V_39 :
F_8 ( V_26 , L_4 ) ;
return F_10 ( V_9 , V_12 , V_40 ) ;
case V_41 :
F_8 ( V_26 , L_5 ) ;
return F_11 ( V_9 , V_25 ) ;
case V_42 :
F_8 ( V_26 , L_6 ) ;
return F_12 ( V_9 , V_25 ) ;
case V_43 :
{
struct V_44 * V_45 ;
F_8 ( V_26 , L_7 ) ;
if ( F_13 ( & V_46 , V_25 , sizeof( V_46 ) ) ) {
F_8 ( V_26 , L_8 ) ;
V_9 -> V_47 . Error = V_48 ;
return - V_49 ;
}
V_45 = F_14 () ;
if ( ! V_45 ) {
F_8 ( V_26 , L_9 ) ;
return - V_50 ;
}
V_45 -> V_51 = V_46 . V_51 ;
if ( V_46 . V_14 >= V_9 -> V_30 )
V_46 . V_14 = 0 ;
F_8 ( V_26 , L_10 , V_46 . V_14 , V_46 . V_52 ) ;
if ( F_15 ( & V_9 -> V_31 [ V_46 . V_14 ] , V_46 . V_52 , V_45 ) == V_53 ) {
F_16 ( V_54 L_11 ) ;
}
return 0 ;
}
case V_55 :
return - V_56 ;
case V_57 :
F_8 ( V_26 , L_12 ) ;
V_9 -> V_47 . Error = V_58 ;
return - V_36 ;
case V_59 :
F_8 ( V_26 , L_13 ) ;
if ( ( V_23 = F_17 ( V_9 ) ) != 0 )
return V_23 ;
if ( F_4 ( V_25 , V_9 -> V_60 , V_61 * sizeof( struct V_62 ) ) ) {
F_8 ( V_26 , L_14 ) ;
V_9 -> V_47 . Error = V_63 ;
return - V_49 ;
}
{
int V_64 ;
F_8 ( V_26 , L_15 ) ;
for ( V_64 = 0 ; V_64 < V_61 ; V_64 ++ ) {
if ( ( V_9 -> V_60 [ V_64 ] . V_65 == 0 ) && ( V_9 -> V_60 [ V_64 ] . V_66 == 0 ) && ( V_9 -> V_60 [ V_64 ] . V_67 == 0 ) )
continue;
F_8 ( V_26 , L_16 , V_64 , V_9 -> V_60 [ V_64 ] . V_66 ) ;
F_8 ( V_26 , L_17 , V_64 , V_9 -> V_60 [ V_64 ] . V_67 ) ;
F_8 ( V_26 , L_18 , V_64 , V_9 -> V_60 [ V_64 ] . V_65 ) ;
F_8 ( V_26 , L_19 , V_64 , V_9 -> V_60 [ V_64 ] . V_68 ) ;
F_8 ( V_26 , L_20 , V_64 , ( int ) V_9 -> V_60 [ V_64 ] . V_32 ) ;
F_8 ( V_26 , L_21 , V_64 , ( int ) V_9 -> V_60 [ V_64 ] . V_69 ) ;
F_8 ( V_26 , L_22 , V_64 , V_9 -> V_60 [ V_64 ] . V_70 [ 0 ] . V_71 ) ;
F_8 ( V_26 , L_23 , V_64 , V_9 -> V_60 [ V_64 ] . V_70 [ 0 ] . V_72 ) ;
F_8 ( V_26 , L_24 , V_64 , V_9 -> V_60 [ V_64 ] . V_70 [ 1 ] . V_71 ) ;
F_8 ( V_26 , L_25 , V_64 , V_9 -> V_60 [ V_64 ] . V_70 [ 1 ] . V_72 ) ;
F_8 ( V_26 , L_26 , V_64 , V_9 -> V_60 [ V_64 ] . V_70 [ 2 ] . V_71 ) ;
F_8 ( V_26 , L_27 , V_64 , V_9 -> V_60 [ V_64 ] . V_70 [ 2 ] . V_72 ) ;
F_8 ( V_26 , L_28 , V_64 , V_9 -> V_60 [ V_64 ] . V_70 [ 3 ] . V_71 ) ;
F_8 ( V_26 , L_29 , V_64 , V_9 -> V_60 [ V_64 ] . V_70 [ 3 ] . V_72 ) ;
F_8 ( V_26 , L_30 , V_64 , V_9 -> V_60 [ V_64 ] . V_73 ) ;
}
F_8 ( V_26 , L_31 ) ;
}
V_9 -> V_74 = V_75 ;
return 0 ;
case V_76 :
F_8 ( V_26 , L_32 ) ;
if ( ! V_13 ) {
F_8 ( V_26 , L_33 ) ;
V_9 -> V_47 . Error = V_77 ;
return - V_56 ;
}
if ( F_13 ( & V_9 -> V_60 [ 0 ] , V_25 , V_61 * sizeof( struct V_62 ) ) ) {
F_8 ( V_26 , L_34 ) ;
V_9 -> V_47 . Error = V_48 ;
return - V_49 ;
}
return F_18 ( V_9 ) ;
case V_78 :
F_8 ( V_26 , L_35 ) ;
if ( ! V_13 ) {
F_8 ( V_26 , L_36 ) ;
V_9 -> V_47 . Error = V_77 ;
return - V_56 ;
}
if ( F_4 ( V_25 , V_9 -> V_79 , ( sizeof( V_80 ) * V_81 ) ) ) {
F_8 ( V_26 , L_37 ) ;
V_9 -> V_47 . Error = V_63 ;
return - V_49 ;
}
return 0 ;
case V_82 :
F_8 ( V_26 , L_38 ) ;
if ( ! V_13 ) {
F_8 ( V_26 , L_39 ) ;
V_9 -> V_47 . Error = V_77 ;
return - V_56 ;
}
if ( F_13 ( & V_9 -> V_79 [ 0 ] , V_25 , ( sizeof( V_80 ) * V_81 ) ) ) {
F_8 ( V_26 , L_40 ) ;
V_9 -> V_47 . Error = V_48 ;
return - V_49 ;
}
return 0 ;
case V_83 :
{
int V_84 = - 1 ;
F_8 ( V_26 , L_41 ) ;
if ( ! V_13 ) {
F_8 ( V_26 , L_42 ) ;
V_9 -> V_47 . Error = V_77 ;
return - V_56 ;
}
for ( V_18 = 0 ; V_18 < V_81 ; V_18 ++ ) {
if ( ( V_84 == - 1 ) && ( V_9 -> V_79 [ V_18 ] == 0L ) )
V_84 = V_18 ;
else if ( V_9 -> V_79 [ V_18 ] == V_12 ) {
V_9 -> V_79 [ V_18 ] = 0L ;
F_8 ( V_26 , L_43 , V_12 ) ;
return 0 ;
}
}
if ( V_84 != - 1 ) {
V_9 -> V_79 [ V_84 ] = V_12 ;
F_8 ( V_26 , L_44 , V_12 ) ;
} else {
F_8 ( V_26 , L_45 , V_12 ) ;
return - V_7 ;
}
return 0 ;
}
case V_85 :
F_8 ( V_26 , L_46 ) ;
V_15 = V_12 ;
if ( ( V_15 < 0 ) || ( V_15 > 511 ) ) {
F_8 ( V_26 , L_47 , V_15 ) ;
V_9 -> V_47 . Error = V_86 ;
return - V_36 ;
}
V_20 = V_9 -> V_87 [ V_15 ] ;
if ( ! V_20 -> V_88 ) {
F_8 ( V_26 , L_48 , V_15 ) ;
V_9 -> V_47 . Error = V_89 ;
return - V_36 ;
}
if ( ! ( V_20 -> V_90 & ( V_91 | V_92 ) ) ) {
F_8 ( V_26 , L_49 , V_15 ) ;
return - V_36 ;
}
F_19 ( & V_20 -> V_93 , V_24 ) ;
if ( F_20 ( V_9 , ( V_9 -> V_87 [ V_15 ] ) , V_94 ) ==
V_53 ) {
F_8 ( V_26 , L_50 ) ;
F_21 ( & V_20 -> V_93 , V_24 ) ;
return - V_95 ;
} else {
F_8 ( V_26 , L_51 , V_15 ) ;
V_20 -> V_90 |= V_96 ;
}
F_21 ( & V_20 -> V_93 , V_24 ) ;
return V_23 ;
case V_97 :
F_8 ( V_26 , L_52 ) ;
if ( ! V_13 ) {
F_8 ( V_26 , L_53 ) ;
V_9 -> V_47 . Error = V_77 ;
return - V_56 ;
}
if ( F_13 ( & V_98 , V_25 , sizeof( V_98 ) ) ) {
F_8 ( V_26 , L_54 ) ;
V_9 -> V_47 . Error = V_48 ;
return - V_49 ;
}
return F_22 ( V_9 , & V_98 ) ;
case V_99 :
F_8 ( V_26 , L_55 ) ;
if ( ! V_13 ) {
F_8 ( V_26 , L_56 ) ;
V_9 -> V_47 . Error = V_77 ;
return - V_56 ;
}
if ( F_13 ( & V_98 , V_25 , sizeof( V_98 ) ) ) {
F_8 ( V_26 , L_54 ) ;
V_9 -> V_47 . Error = V_48 ;
return - V_49 ;
}
return F_23 ( V_9 , & V_98 ) ;
case V_100 :
F_8 ( V_26 , L_57 ) ;
if ( ! V_13 ) {
F_8 ( V_26 , L_58 ) ;
V_9 -> V_47 . Error = V_77 ;
return - V_56 ;
}
if ( F_13 ( & V_98 , V_25 , sizeof( V_98 ) ) ) {
F_8 ( V_26 , L_59 ) ;
V_9 -> V_47 . Error = V_48 ;
return - V_49 ;
}
return F_24 ( V_9 , & V_98 ) ;
case V_101 :
if ( F_4 ( V_25 , & V_9 -> V_102 , sizeof( unsigned int ) ) ) {
V_9 -> V_47 . Error = V_63 ;
return - V_49 ;
}
return 0 ;
case V_103 :
if ( F_4 ( V_25 , & V_9 -> V_47 , sizeof( struct Error ) ) )
return - V_49 ;
return 0 ;
case V_104 :
F_8 ( V_26 , L_60 ) ;
return - V_36 ;
case V_105 :
if ( F_13 ( & V_15 , V_25 , sizeof( unsigned int ) ) ) {
V_9 -> V_47 . Error = V_48 ;
return - V_49 ;
}
F_8 ( V_26 , L_61 , V_15 ) ;
if ( V_15 < 0 || V_15 > 511 ) {
F_8 ( V_26 , L_62 , V_15 ) ;
V_9 -> V_47 . Error = V_86 ;
return - V_36 ;
}
V_20 = ( V_9 -> V_87 [ V_15 ] ) ;
if ( ! V_20 -> V_88 ) {
F_8 ( V_26 , L_63 , V_15 ) ;
V_9 -> V_47 . Error = V_89 ;
return - V_36 ;
}
V_15 = V_20 -> V_16 -> V_106 [ V_20 -> V_52 ] . V_107 ;
if ( F_4 ( V_25 , & V_15 , sizeof( unsigned int ) ) ) {
V_9 -> V_47 . Error = V_63 ;
return - V_49 ;
}
return ( 0 ) ;
case V_108 :
F_8 ( V_26 , L_64 ) ;
for ( V_18 = 0 ; V_18 < V_109 ; V_18 ++ ) {
F_19 ( & V_20 -> V_93 , V_24 ) ;
V_9 -> V_87 [ V_18 ] -> V_110 = 1 ;
F_21 ( & V_20 -> V_93 , V_24 ) ;
}
return 0 ;
case V_111 :
F_8 ( V_26 , L_65 ) ;
if ( F_13 ( & V_112 , V_25 , sizeof( V_112 ) ) ) {
V_9 -> V_47 . Error = V_48 ;
F_8 ( V_26 , L_66 ) ;
return - V_49 ;
}
if ( V_112 . V_113 > V_112 . V_114 || V_112 . V_114 >= V_109 ) {
V_9 -> V_47 . Error = V_86 ;
F_8 ( V_26 , L_67 ) ;
return - V_50 ;
}
if ( V_112 . V_115 > V_9 -> V_116 . V_117 || V_112 . V_115 < V_9 -> V_116 . V_118 ) {
V_9 -> V_47 . Error = V_119 ;
F_8 ( V_26 , L_68 ) ;
return - V_36 ;
}
if ( ! V_9 -> V_87 ) {
F_16 ( V_120 L_69 ) ;
F_8 ( V_26 , L_70 ) ;
return - V_121 ;
}
F_8 ( V_26 , L_71 , V_112 . V_113 , V_112 . V_114 ) ;
for ( V_17 = V_112 . V_113 ; V_17 <= V_112 . V_114 ; V_17 ++ ) {
F_8 ( V_26 , L_72 , V_17 ) ;
}
F_8 ( V_26 , L_73 , V_17 ) ;
F_8 ( V_26 , L_74 , V_23 ) ;
return V_23 ;
case V_122 :
F_8 ( V_26 , L_75 ) ;
if ( F_13 ( & V_112 , V_25 , sizeof( V_112 ) ) ) {
V_9 -> V_47 . Error = V_48 ;
return - V_49 ;
}
if ( V_112 . V_113 >= V_109 ) {
V_9 -> V_47 . Error = V_86 ;
return - V_50 ;
}
V_15 = V_112 . V_114 = V_112 . V_113 ;
V_112 . V_123 = ( V_9 -> V_87 [ V_15 ] -> V_124 & V_125 ) ? 1 : 0 ;
V_112 . V_126 = ( V_9 -> V_87 [ V_15 ] -> V_124 & V_127 ) ? 1 : 0 ;
V_112 . V_128 = ( V_9 -> V_87 [ V_15 ] -> V_124 & V_129 ) ? 1 : 0 ;
V_112 . V_130 = V_9 -> V_87 [ V_15 ] -> V_130 ;
V_112 . V_131 = V_9 -> V_87 [ V_15 ] -> V_131 ;
V_112 . V_115 = V_9 -> V_87 [ V_15 ] -> V_132 . V_115 ;
memcpy ( V_112 . V_133 , V_9 -> V_87 [ V_15 ] -> V_132 . V_133 , V_134 ) ;
memcpy ( V_112 . V_135 , V_9 -> V_87 [ V_15 ] -> V_132 . V_135 , V_134 ) ;
V_112 . V_133 [ V_134 - 1 ] = '\0' ;
V_112 . V_135 [ V_134 - 1 ] = '\0' ;
if ( F_4 ( V_25 , & V_112 , sizeof( V_112 ) ) ) {
V_9 -> V_47 . Error = V_63 ;
return - V_49 ;
}
return V_23 ;
case V_136 :
F_8 ( V_26 , L_76 ) ;
if ( F_13 ( & V_137 , V_25 , sizeof( struct V_137 ) ) ) {
V_9 -> V_47 . Error = V_48 ;
return - V_49 ;
}
if ( V_137 . V_19 >= V_109 ) {
V_9 -> V_47 . Error = V_86 ;
return - V_50 ;
}
V_20 = ( V_9 -> V_87 [ V_137 . V_19 ] ) ;
V_137 . V_124 = V_20 -> V_124 ;
V_137 . V_90 = V_20 -> V_90 ;
F_8 ( V_26 , L_77 , V_137 . V_19 ) ;
if ( F_4 ( V_25 , & V_137 , sizeof( struct V_137 ) ) ) {
V_9 -> V_47 . Error = V_63 ;
return - V_49 ;
}
return V_23 ;
case V_138 :
F_8 ( V_26 , L_78 ) ;
if ( F_13 ( & V_139 , V_25 , sizeof( struct V_139 ) ) ) {
V_9 -> V_47 . Error = V_48 ;
return - V_49 ;
}
if ( V_139 . V_15 >= V_109 ) {
V_9 -> V_47 . Error = V_86 ;
return - V_50 ;
}
F_8 ( V_26 , L_77 , V_139 . V_15 ) ;
V_20 = ( V_9 -> V_87 [ V_139 . V_15 ] ) ;
if ( F_4 ( V_25 , & V_139 , sizeof( struct V_139 ) ) ) {
V_9 -> V_47 . Error = V_63 ;
return - V_49 ;
}
return V_23 ;
case V_140 :
if ( F_13 ( & V_139 , V_25 , sizeof( struct V_139 ) ) ) {
V_9 -> V_47 . Error = V_48 ;
return - V_49 ;
}
F_8 ( V_26 , L_79 , V_139 . V_15 ) ;
if ( V_139 . V_15 >= ( T_6 ) V_109 ) {
V_9 -> V_47 . Error = V_86 ;
return - V_50 ;
}
V_20 = ( V_9 -> V_87 [ V_139 . V_15 ] ) ;
F_25 ( V_20 , V_141 , V_20 -> V_90 & V_142 ,
V_143 ) ;
return V_23 ;
case V_144 :
F_8 ( V_26 , L_80 ) ;
if ( F_13 ( & V_137 , V_25 , sizeof( V_137 ) ) ) {
V_9 -> V_47 . Error = V_48 ;
return - V_49 ;
}
if ( V_137 . V_19 >= ( T_6 ) V_109 ) {
V_9 -> V_47 . Error = V_86 ;
return - V_50 ;
}
V_20 = ( V_9 -> V_87 [ V_137 . V_19 ] ) ;
F_19 ( & V_20 -> V_93 , V_24 ) ;
V_20 -> V_124 = V_137 . V_124 ;
F_21 ( & V_20 -> V_93 , V_24 ) ;
return V_23 ;
case V_145 :
F_8 ( V_26 , L_81 ) ;
if ( F_13 ( & V_146 , V_25 , sizeof( struct V_146 ) ) ) {
V_9 -> V_47 . Error = V_48 ;
return - V_49 ;
}
if ( V_146 . V_15 < 0 || V_146 . V_15 >= V_109 ) {
V_9 -> V_47 . Error = V_86 ;
return - V_50 ;
}
V_20 = ( V_9 -> V_87 [ V_146 . V_15 ] ) ;
V_146 . V_147 = V_20 -> V_148 ;
V_146 . V_149 = V_20 -> V_149 ;
V_146 . V_150 = V_20 -> V_150 ;
V_146 . V_151 = V_20 -> V_151 ;
V_146 . V_152 = V_20 -> V_152 ;
V_146 . V_153 = V_20 -> V_153 ;
if ( F_4 ( V_25 , & V_146 , sizeof( struct V_146 ) ) ) {
V_9 -> V_47 . Error = V_63 ;
return - V_49 ;
}
return V_23 ;
case V_154 :
V_15 = V_12 ;
F_8 ( V_26 , L_82 ) ;
if ( V_15 >= V_109 ) {
V_9 -> V_47 . Error = V_86 ;
return - V_50 ;
}
V_20 = ( V_9 -> V_87 [ V_15 ] ) ;
F_19 ( & V_20 -> V_93 , V_24 ) ;
V_20 -> V_149 = 0 ;
V_20 -> V_150 = 0 ;
V_20 -> V_151 = 0 ;
V_20 -> V_152 = 0 ;
V_20 -> V_153 = 0 ;
F_21 ( & V_20 -> V_93 , V_24 ) ;
return V_23 ;
case V_155 :
F_8 ( V_26 , L_83 ) ;
if ( F_13 ( & V_146 , V_25 , sizeof( struct V_146 ) ) ) {
V_9 -> V_47 . Error = V_48 ;
return - V_49 ;
}
if ( V_146 . V_15 < 0 || V_146 . V_15 >= V_109 ) {
V_9 -> V_47 . Error = V_86 ;
return - V_50 ;
}
V_20 = ( V_9 -> V_87 [ V_146 . V_15 ] ) ;
F_19 ( & V_20 -> V_93 , V_24 ) ;
V_20 -> V_148 = V_146 . V_147 ;
F_21 ( & V_20 -> V_93 , V_24 ) ;
return V_23 ;
case V_156 :
F_8 ( V_26 , L_84 ) ;
if ( F_4 ( V_25 , & V_9 -> V_116 , sizeof( struct V_157 ) ) ) {
V_9 -> V_47 . Error = V_63 ;
return - V_49 ;
}
return V_23 ;
case V_158 :
F_8 ( V_26 , L_85 ) ;
if ( ! V_13 ) {
V_9 -> V_47 . Error = V_77 ;
return - V_56 ;
}
if ( F_13 ( & V_9 -> V_116 , V_25 , sizeof( struct V_157 ) ) ) {
V_9 -> V_47 . Error = V_48 ;
return - V_49 ;
}
for ( V_14 = 0 ; V_14 < V_9 -> V_30 ; V_14 ++ )
if ( ( V_9 -> V_31 [ V_14 ] . V_32 & V_159 ) == V_33 )
F_9 ( V_9 -> V_116 . V_160 , & V_9 -> V_31 [ V_14 ] . V_34 -> V_35 ) ;
return V_23 ;
case V_161 :
F_8 ( V_26 , L_86 ) ;
return - V_36 ;
case V_162 :
F_8 ( V_26 , L_87 ) ;
if ( ! V_13 ) {
V_9 -> V_47 . Error = V_77 ;
return - V_56 ;
}
V_9 -> V_163 = V_164 ;
return V_23 ;
case V_165 :
case V_166 :
F_8 ( V_26 , L_88 ) ;
if ( F_13 ( & V_167 , V_25 , sizeof( V_167 ) ) ) {
V_9 -> V_47 . Error = V_48 ;
return - V_49 ;
}
if ( V_167 . V_69 == V_168 ) {
if ( V_11 == V_165 ) {
if ( ! V_13 ) {
V_9 -> V_47 . Error = V_77 ;
return - V_56 ;
}
V_9 -> V_169 = V_167 . V_170 ;
V_9 -> V_171 = V_167 . V_172 ;
F_8 ( V_26 , L_89 , V_9 -> V_169 , V_9 -> V_171 ) ;
} else {
F_8 ( V_26 , L_90 , V_9 -> V_169 , V_9 -> V_171 ) ;
V_167 . V_170 = V_9 -> V_169 ;
V_167 . V_172 = V_9 -> V_171 ;
if ( F_4 ( V_25 , & V_167 , sizeof( V_167 ) ) ) {
F_8 ( V_26 , L_91 , V_167 . V_69 ) ;
V_9 -> V_47 . Error = V_63 ;
return - V_49 ;
}
}
} else if ( V_167 . V_69 >= V_109 && V_167 . V_69 != V_168 ) {
F_8 ( V_26 , L_91 , V_167 . V_69 ) ;
V_9 -> V_47 . Error = V_86 ;
return - V_50 ;
} else if ( V_11 == V_165 ) {
if ( ! V_13 ) {
V_9 -> V_47 . Error = V_77 ;
return - V_56 ;
}
F_19 ( & V_20 -> V_93 , V_24 ) ;
V_9 -> V_87 [ V_167 . V_69 ] -> V_170 = V_167 . V_170 ;
F_21 ( & V_20 -> V_93 , V_24 ) ;
F_8 ( V_26 , L_92 , V_9 -> V_87 [ V_167 . V_69 ] -> V_170 ) ;
} else {
F_8 ( V_26 , L_93 , V_9 -> V_87 [ V_167 . V_69 ] -> V_170 ) ;
V_167 . V_170 = V_9 -> V_87 [ V_167 . V_69 ] -> V_170 ;
if ( F_4 ( V_25 , & V_167 , sizeof( V_167 ) ) ) {
F_8 ( V_26 , L_94 ) ;
V_9 -> V_47 . Error = V_63 ;
return - V_49 ;
}
}
return V_23 ;
case V_173 :
F_8 ( V_26 , L_95 ) ;
if ( F_4 ( V_25 , F_26 () , sizeof( struct V_174 ) ) ) {
F_8 ( V_26 , L_96 , V_14 ) ;
V_9 -> V_47 . Error = V_63 ;
return - V_49 ;
}
return V_23 ;
case V_175 :
F_8 ( V_26 , L_97 ) ;
if ( F_4 ( V_25 , & V_9 -> V_30 , sizeof( V_9 -> V_30 ) ) ) {
F_8 ( V_26 , L_98 ) ;
V_9 -> V_47 . Error = V_63 ;
return - V_49 ;
}
return V_23 ;
case V_176 :
F_8 ( V_26 , L_99 , V_12 ) ;
if ( ! V_13 ) {
F_8 ( V_26 , L_100 ) ;
V_9 -> V_47 . Error = V_77 ;
return - V_56 ;
}
V_9 -> V_177 = 1 ;
V_9 -> V_178 = 0 ;
for ( V_14 = 0 ; V_14 < V_9 -> V_30 ; V_14 ++ ) {
( void ) F_27 ( V_9 -> V_31 [ V_14 ] . V_179 , V_9 -> V_31 [ V_14 ] . V_180 , V_9 -> V_31 [ V_14 ] . Type , V_9 -> V_31 [ V_14 ] . V_181 ) ;
memset ( & V_9 -> V_31 [ V_14 ] . V_32 , 0 , ( ( char * ) & V_9 -> V_31 [ V_14 ] . V_182 ) - ( ( char * ) & V_9 -> V_31 [ V_14 ] . V_32 ) ) ;
V_9 -> V_31 [ V_14 ] . V_32 = V_183 ;
}
F_28 ( V_9 ) ;
V_9 -> V_184 = 0 ;
V_9 -> V_185 = 0 ;
F_16 ( L_101 ) ;
for ( V_17 = 0 ; V_17 < V_109 ; V_17 ++ ) {
F_29 ( & V_9 -> V_87 [ V_17 ] -> V_93 ) ;
V_9 -> V_87 [ V_17 ] -> V_186 = V_187 ;
}
V_9 -> V_178 = 0 ;
return V_23 ;
case V_188 :
F_8 ( V_26 , L_102 ) ;
if ( ! V_13 ) {
F_8 ( V_26 , L_103 ) ;
V_9 -> V_47 . Error = V_77 ;
return - V_56 ;
}
if ( F_13 ( & V_189 , V_25 , sizeof( V_189 ) ) ) {
F_8 ( V_26 , L_104 ) ;
V_9 -> V_47 . Error = V_48 ;
return - V_49 ;
}
F_8 ( V_26 , L_105 , V_189 . V_190 ) ;
if ( V_189 . V_190 >= V_191 ) {
F_8 ( V_26 , L_106 , V_189 . V_190 ) ;
V_9 -> V_47 . Error = V_192 ;
return - V_50 ;
}
V_23 = ( * ( V_193 [ V_189 . V_190 ] ) ) ( V_9 , & V_189 ) ;
V_9 -> V_177 = 0 ;
return V_23 ;
case V_194 :
{
unsigned int V_28 ;
if ( F_13 ( & V_28 , V_25 , sizeof( V_28 ) ) ) {
F_8 ( V_26 , L_107 ) ;
V_9 -> V_47 . Error = V_48 ;
return - V_49 ;
}
F_8 ( V_26 , L_108 ) ;
if ( F_1 ( V_25 , V_9 -> V_31 [ V_28 ] . V_34 , sizeof( V_195 ) ) ) {
V_9 -> V_47 . Error = V_63 ;
F_8 ( V_26 , L_109 ) ;
return - V_49 ;
}
}
return V_23 ;
case V_196 :
F_8 ( V_26 , L_110 ) ;
if ( F_13 ( & V_197 , V_25 , sizeof( V_197 ) ) ) {
F_8 ( V_26 , L_107 ) ;
V_9 -> V_47 . Error = V_48 ;
return - V_49 ;
}
if ( V_197 . V_198 >= V_9 -> V_30 ) {
V_9 -> V_47 . Error = V_199 ;
F_8 ( V_26 , L_111 , V_197 . V_198 ) ;
return - V_50 ;
}
F_8 ( V_26 , L_112 , V_197 . V_198 ) ;
if ( F_4 ( V_197 . V_16 , & V_9 -> V_31 [ V_197 . V_198 ] , sizeof( struct V_14 ) ) ) {
V_9 -> V_47 . Error = V_63 ;
F_8 ( V_26 , L_113 ) ;
return - V_49 ;
}
return V_23 ;
case V_200 :
F_8 ( V_26 , L_114 ) ;
if ( F_13 ( & V_201 , V_25 , sizeof( V_201 ) ) ) {
F_8 ( V_26 , L_115 ) ;
V_9 -> V_47 . Error = V_48 ;
return - V_49 ;
}
if ( V_201 . V_198 >= V_9 -> V_30 ) {
V_9 -> V_47 . Error = V_199 ;
F_8 ( V_26 , L_116 , V_201 . V_198 ) ;
return - V_50 ;
}
F_8 ( V_26 , L_112 , V_201 . V_198 ) ;
if ( V_9 -> V_31 [ V_201 . V_198 ] . Type == V_202 ) {
int V_203 ;
static unsigned char V_204 [ sizeof( struct V_205 ) ] ;
for ( V_203 = 0 ; V_203 < sizeof( struct V_205 ) ; V_203 ++ )
V_204 [ V_203 ] = F_30 ( V_9 -> V_31 [ V_201 . V_198 ] . V_180 + V_203 ) ;
if ( F_4 ( V_201 . V_206 , V_204 , sizeof( struct V_205 ) ) ) {
V_9 -> V_47 . Error = V_63 ;
F_8 ( V_26 , L_117 ) ;
return - V_49 ;
}
} else if ( F_1 ( V_201 . V_206 , V_9 -> V_31 [ V_201 . V_198 ] . V_180 , sizeof( struct V_205 ) ) ) {
V_9 -> V_47 . Error = V_63 ;
F_8 ( V_26 , L_117 ) ;
return - V_49 ;
}
return V_23 ;
case V_207 :
F_8 ( V_26 , L_118 ) ;
if ( V_12 > 511 ) {
F_8 ( V_26 , L_119 , V_12 ) ;
V_9 -> V_47 . Error = V_86 ;
return - V_36 ;
}
F_19 ( & V_20 -> V_93 , V_24 ) ;
V_9 -> V_87 [ V_12 ] -> V_90 |= V_96 ;
F_21 ( & V_20 -> V_93 , V_24 ) ;
return V_23 ;
case V_208 :
F_8 ( V_26 , L_120 ) ;
if ( F_13 ( & V_209 , V_25 , sizeof( V_209 ) ) ) {
F_8 ( V_26 , L_121 ) ;
V_9 -> V_47 . Error = V_48 ;
return - V_49 ;
}
if ( V_209 . V_69 >= V_109 ) {
F_8 ( V_26 , L_122 , V_209 . V_69 ) ;
V_9 -> V_47 . Error = V_86 ;
return - V_50 ;
}
F_8 ( V_26 , L_123 , V_209 . V_69 ) ;
if ( F_4 ( V_209 . V_20 , V_9 -> V_87 [ V_209 . V_69 ] , sizeof( struct V_19 ) ) ) {
V_9 -> V_47 . Error = V_63 ;
F_8 ( V_26 , L_124 ) ;
return - V_49 ;
}
return V_23 ;
case V_210 :
F_8 ( V_26 , L_125 ) ;
if ( F_13 ( & V_211 , V_25 , sizeof( V_211 ) ) ) {
F_8 ( V_26 , L_126 ) ;
V_9 -> V_47 . Error = V_48 ;
return - V_49 ;
}
if ( V_211 . V_198 >= V_9 -> V_30 ) {
F_8 ( V_26 , L_127 , V_211 . V_198 ) ;
V_9 -> V_47 . Error = V_199 ;
return - V_50 ;
}
if ( V_211 . V_52 >= V_212 + V_213 ) {
F_8 ( V_26 , L_128 , V_211 . V_52 ) ;
V_9 -> V_47 . Error = V_214 ;
return - V_36 ;
}
V_16 = & V_9 -> V_31 [ V_211 . V_198 ] ;
if ( ( V_16 -> V_32 & V_159 ) != V_33 ) {
F_8 ( V_26 , L_129 , V_211 . V_198 ) ;
V_9 -> V_47 . Error = V_215 ;
return - V_121 ;
}
F_8 ( V_26 , L_130 , V_211 . V_52 , V_211 . V_198 ) ;
if ( F_1 ( V_211 . V_216 , V_16 -> V_106 [ V_211 . V_52 ] . V_216 , sizeof( struct V_217 ) ) ) {
V_9 -> V_47 . Error = V_63 ;
F_8 ( V_26 , L_131 ) ;
return - V_49 ;
}
return V_23 ;
case V_218 :
F_8 ( V_26 , L_132 ) ;
if ( F_13 ( & V_219 , V_25 , sizeof( V_219 ) ) ) {
F_8 ( V_26 , L_133 ) ;
V_9 -> V_47 . Error = V_48 ;
return - V_49 ;
}
if ( V_219 . V_14 >= V_9 -> V_30 ) {
F_8 ( V_26 , L_134 , V_219 . V_14 ) ;
V_9 -> V_47 . Error = V_199 ;
return - V_50 ;
}
if ( V_219 . V_72 >= V_213 ) {
F_8 ( V_26 , L_135 , V_219 . V_72 ) ;
V_9 -> V_47 . Error = V_220 ;
return - V_36 ;
}
V_16 = & V_9 -> V_31 [ V_219 . V_14 ] ;
if ( ( V_16 -> V_32 & V_159 ) != V_33 ) {
F_8 ( V_26 , L_136 , V_219 . V_14 ) ;
V_9 -> V_47 . Error = V_215 ;
return - V_121 ;
}
F_8 ( V_26 , L_137 , V_219 . V_72 , V_219 . V_14 ) ;
if ( F_1 ( V_219 . V_221 , & V_16 -> V_222 [ V_219 . V_72 ] , sizeof( struct V_223 ) ) ) {
F_8 ( V_26 , L_138 ) ;
V_9 -> V_47 . Error = V_63 ;
return - V_49 ;
}
return V_23 ;
case V_224 :
V_9 -> V_225 = V_226 ;
return 0 ;
case V_227 :
V_9 -> V_225 = V_228 ;
return 0 ;
case V_229 :
V_9 -> V_225 = V_230 ;
return 0 ;
case V_231 :
if ( V_9 -> V_232 ) {
V_9 -> V_47 . Error = V_233 ;
return - V_95 ;
}
V_9 -> V_232 = V_234 -> V_235 ;
V_9 -> V_236 = V_237 ;
return V_23 ;
case V_238 :
if ( V_9 -> V_232 != V_234 -> V_235 ) {
V_9 -> V_47 . Error = V_239 ;
return - V_56 ;
}
F_8 ( V_26 , L_139 ) ;
V_9 -> V_232 = 0 ;
return V_23 ;
case V_240 :
for ( V_14 = 0 ; V_14 < V_9 -> V_30 ; V_14 ++ )
if ( V_9 -> V_31 [ V_14 ] . Type == V_241 )
V_9 -> V_31 [ V_14 ] . V_242 &= ~ V_243 ;
return V_23 ;
case V_244 :
for ( V_14 = 0 ; V_14 < V_9 -> V_30 ; V_14 ++ )
if ( V_9 -> V_31 [ V_14 ] . Type == V_241 )
V_9 -> V_31 [ V_14 ] . V_242 |= V_243 ;
return V_23 ;
case V_245 :
for ( V_14 = 0 ; V_14 < V_9 -> V_30 ; V_14 ++ )
if ( V_9 -> V_31 [ V_14 ] . Type == V_241 )
V_9 -> V_31 [ V_14 ] . V_242 |= V_246 ;
return V_23 ;
case V_247 :
for ( V_14 = 0 ; V_14 < V_9 -> V_30 ; V_14 ++ )
if ( V_9 -> V_31 [ V_14 ] . Type == V_241 )
V_9 -> V_31 [ V_14 ] . V_242 &= ~ V_246 ;
return V_23 ;
case V_248 :
case V_249 :
case V_250 :
case V_251 :
F_8 ( V_26 , L_140 ) ;
V_15 = V_12 ;
if ( V_15 < 0 || V_15 > 511 ) {
F_8 ( V_26 , L_141 , V_15 ) ;
V_9 -> V_47 . Error = V_86 ;
return - V_36 ;
}
F_19 ( & V_20 -> V_93 , V_24 ) ;
switch ( V_11 ) {
case V_248 :
V_9 -> V_87 [ V_15 ] -> V_124 |= V_252 ;
break;
case V_249 :
V_9 -> V_87 [ V_15 ] -> V_124 &= ~ V_252 ;
break;
case V_250 :
V_9 -> V_87 [ V_15 ] -> V_124 |= V_253 ;
break;
case V_251 :
V_9 -> V_87 [ V_15 ] -> V_124 &= ~ V_253 ;
break;
}
F_21 ( & V_20 -> V_93 , V_24 ) ;
return V_23 ;
case V_254 :
F_8 ( V_26 , L_142 ) ;
return - V_36 ;
case V_255 :
F_8 ( V_26 , L_143 ) ;
if ( F_13 ( & V_256 , V_25 , sizeof( V_256 ) ) ) {
F_8 ( V_26 , L_144 ) ;
V_9 -> V_47 . Error = V_48 ;
return - V_49 ;
}
if ( V_256 . V_257 >= 128 ) {
V_9 -> V_47 . Error = V_86 ;
return - V_50 ;
}
V_20 = V_9 -> V_87 [ V_256 . V_257 ] ;
F_19 ( & V_20 -> V_93 , V_24 ) ;
if ( ! F_31 ( & V_22 , V_20 ) ) {
V_9 -> V_47 . Error = V_258 ;
F_21 ( & V_20 -> V_93 , V_24 ) ;
return - V_259 ;
}
for ( V_17 = 0 ; V_17 < ( T_6 ) ( V_256 . V_260 & 127 ) ; V_17 ++ )
F_32 ( V_256 . V_261 [ V_17 ] , & V_22 -> V_262 [ V_17 ] ) ;
F_32 ( V_256 . V_260 , & V_22 -> V_263 ) ;
F_33 ( V_20 ) ;
if ( V_20 -> V_148 )
V_20 -> V_149 += ( V_256 . V_260 & 127 ) ;
F_21 ( & V_20 -> V_93 , V_24 ) ;
return V_23 ;
case V_264 :
if ( V_13 )
V_9 -> V_265 = 1 ;
return V_13 ? 0 : - V_56 ;
case V_266 :
if ( V_13 )
V_9 -> V_265 = 0 ;
return V_13 ? 0 : - V_56 ;
case V_267 :
if ( F_4 ( V_25 , & V_9 -> V_265 , sizeof( V_9 -> V_265 ) ) ) {
F_8 ( V_26 , L_145 ) ;
V_9 -> V_47 . Error = V_63 ;
return - V_49 ;
}
return 0 ;
case V_268 :
if ( F_13 ( & V_269 , V_25 , sizeof( struct V_270 ) ) ) {
V_9 -> V_47 . Error = V_48 ;
return - V_49 ;
}
F_8 ( V_26 , L_146 , V_269 . V_14 , V_269 . V_271 , V_269 . V_272 ) ;
if ( V_269 . V_271 >= V_212 + V_213 ) {
V_9 -> V_47 . Error = V_214 ;
return - V_36 ;
}
if ( V_269 . V_14 >= V_9 -> V_30 ) {
V_9 -> V_47 . Error = V_199 ;
return - V_36 ;
}
V_15 = V_9 -> V_31 [ V_269 . V_14 ] . V_106 [ V_269 . V_271 ] . V_273 ;
V_20 = V_9 -> V_87 [ V_15 ] ;
F_19 ( & V_20 -> V_93 , V_24 ) ;
if ( F_20 ( V_9 , V_20 , V_274 ) == V_53 ) {
F_8 ( V_26 , L_147 ) ;
F_21 ( & V_20 -> V_93 , V_24 ) ;
return - V_95 ;
} else
V_20 -> V_90 |= V_96 ;
F_21 ( & V_20 -> V_93 , V_24 ) ;
if ( F_4 ( V_25 , V_9 -> V_275 , V_276 ) ) {
F_8 ( V_26 , L_148 ) ;
V_9 -> V_47 . Error = V_63 ;
return - V_49 ;
}
return 0 ;
case V_277 :
if ( V_12 >= V_9 -> V_30 )
return - V_36 ;
F_8 ( V_26 , L_149 , V_12 ) ;
F_32 ( 0xFF , & V_9 -> V_31 [ V_12 ] . V_278 ) ;
return 0 ;
case V_279 :
if ( V_12 >= V_9 -> V_30 )
return - V_36 ;
F_8 ( V_26 , L_150 , V_12 ) ;
F_32 ( 0xFF , & V_9 -> V_31 [ V_12 ] . V_280 ) ;
return 0 ;
case V_281 :
V_9 -> V_282 = ! V_9 -> V_282 ;
if ( F_4 ( V_25 , & V_9 -> V_282 , sizeof( unsigned int ) ) ) {
V_9 -> V_47 . Error = V_63 ;
return - V_49 ;
}
return 0 ;
case V_283 :
if ( F_13 ( & V_269 , V_25 , sizeof( struct V_270 ) ) ) {
V_9 -> V_47 . Error = V_48 ;
return - V_49 ;
}
F_8 ( V_26 , L_151 , V_269 . V_14 , V_269 . V_271 , V_269 . V_19 , V_269 . V_272 ) ;
if ( V_269 . V_19 > 511 ) {
F_8 ( V_26 , L_141 , V_269 . V_19 ) ;
V_9 -> V_47 . Error = V_86 ;
return - V_36 ;
}
if ( V_269 . V_271 >= V_212 + V_213 ) {
V_9 -> V_47 . Error = V_214 ;
return - V_36 ;
}
if ( V_269 . V_14 >= V_9 -> V_30 ) {
V_9 -> V_47 . Error = V_199 ;
return - V_36 ;
}
V_15 = V_9 -> V_31 [ V_269 . V_14 ] . V_106 [ V_269 . V_271 ] . V_273 + V_269 . V_19 ;
V_20 = V_9 -> V_87 [ V_15 ] ;
F_19 ( & V_20 -> V_93 , V_24 ) ;
if ( F_20 ( V_9 , V_20 , V_284 ) ==
V_53 ) {
F_8 ( V_26 , L_152 ) ;
F_21 ( & V_20 -> V_93 , V_24 ) ;
return - V_95 ;
} else
V_20 -> V_90 |= V_96 ;
F_21 ( & V_20 -> V_93 , V_24 ) ;
if ( F_4 ( V_25 , & V_9 -> V_285 , sizeof( unsigned int ) ) ) {
F_8 ( V_26 , L_153 ) ;
V_9 -> V_47 . Error = V_63 ;
return - V_49 ;
}
return 0 ;
case V_286 :
{
unsigned int V_15 = V_12 & V_287 ;
unsigned int V_288 ;
switch ( V_12 & V_289 ) {
case V_290 :
V_288 = F_34 ( F_35 ( V_10 ) , V_15 ) ;
F_8 ( V_26 , L_154 , V_15 , V_288 ) ;
return V_288 ;
case V_291 :
V_288 = F_34 ( F_35 ( V_10 ) , ( V_15 | V_292 ) ) ;
F_8 ( V_26 , L_155 , V_15 , V_288 ) ;
return V_288 ;
case V_293 :
V_288 = F_34 ( F_35 ( V_10 ) , V_15 ) ;
F_8 ( V_26 , L_156 , V_15 , V_288 ) ;
return V_288 ;
}
F_8 ( V_26 , L_157 ) ;
return - V_36 ;
}
case V_294 :
{
T_4 V_295 ;
int V_296 ;
unsigned long V_288 ;
V_295 = ( T_4 ) ( V_12 ) ;
V_296 = F_36 ( V_295 ) ;
if ( F_37 ( V_295 ) ) {
F_8 ( V_26 , L_158 , V_295 , V_296 ) ;
V_288 = V_296 | V_291 ;
} else {
F_8 ( V_26 , L_159 , V_295 , V_296 ) ;
V_288 = V_296 | V_290 ;
}
return V_288 ;
}
}
F_8 ( V_26 , L_160 , V_11 ) ;
V_9 -> V_47 . Error = V_58 ;
F_38 () ;
return - V_36 ;
}
int F_20 ( struct V_8 * V_9 , struct V_19 * V_20 , T_7 V_297 )
{
struct V_44 * V_45 ;
struct V_298 * V_299 ;
int V_300 ;
T_6 V_301 ;
int V_15 ;
if ( V_20 -> V_90 & V_302 ) {
F_8 ( V_26 , L_161 ) ;
return V_53 ;
}
if ( ( V_20 -> V_186 == ( F_39 ( V_20 -> V_186 ) ) - 1 ) ||
! ( V_45 = F_14 () ) ) {
F_8 ( V_26 , L_162
L_163 , V_297 , V_20 -> V_257 ) ;
return V_53 ;
}
F_8 ( V_26 , L_164 ,
V_45 , V_20 -> V_186 ) ;
V_299 = (struct V_298 * ) & V_45 -> V_51 . V_262 [ 0 ] ;
V_45 -> V_51 . V_303 = 0 ;
if ( V_20 -> V_304 )
V_301 = V_20 -> V_68 ;
else
V_301 = V_20 -> V_52 ;
V_45 -> V_51 . V_305 = V_301 ;
V_45 -> V_51 . V_306 = V_307 ;
V_45 -> V_51 . V_308 = V_307 ;
V_45 -> V_51 . V_263 = V_309 | 2 ;
V_45 -> V_310 = V_311 ;
V_45 -> V_312 = ( unsigned long ) V_20 ;
V_299 -> V_313 = V_297 ;
V_15 = V_20 -> V_314 % ( T_6 ) V_315 ;
if ( V_20 -> V_304 )
V_15 += ( T_6 ) V_315 ;
V_299 -> V_316 = V_15 ;
switch ( V_297 ) {
case V_274 :
F_8 ( V_26 , L_165
L_166 , V_45 , ( int ) V_269 . V_272 ) ;
V_299 -> V_317 = V_274 ;
V_299 -> V_318 = V_269 . V_272 ;
break;
case V_319 :
F_8 ( V_26 , L_167 ,
V_45 ) ;
break;
case V_284 :
F_8 ( V_26 , L_168
L_169 , ( int ) V_269 . V_272 , V_45 ) ;
V_299 -> V_317 = V_284 ;
V_299 -> V_318 = V_269 . V_272 ;
break;
case V_94 :
F_8 ( V_26 , L_170 ,
V_45 ) ;
break;
case V_320 :
F_8 ( V_26 , L_171 ,
V_45 ) ;
V_45 -> V_310 = V_321 ;
break;
case V_322 :
F_8 ( V_26 , L_172 ,
V_45 ) ;
break;
case V_323 :
F_8 ( V_26 , L_173 ,
V_45 ) ;
break;
case V_324 :
case V_325 :
case V_326 :
V_45 -> V_51 . V_262 [ 4 ] = ( char ) V_20 -> V_327 ;
F_8 ( V_26 , L_174
L_175 , V_45 ) ;
break;
case V_328 :
if ( V_20 -> V_329 == ( F_39 ( V_20 -> V_329 ) ) - 1 ) {
F_8 ( V_26 , L_176
L_177 ) ;
F_40 ( V_45 ) ;
return ( V_53 ) ;
} else {
F_8 ( V_26 , L_178
L_175 , V_45 ) ;
V_45 -> V_310 = V_330 ;
}
break;
}
V_20 -> V_186 ++ ;
V_300 = F_15 ( V_20 -> V_16 , V_301 , V_45 ) ;
return V_300 ;
}
