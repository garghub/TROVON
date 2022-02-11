static inline void F_1 ( struct V_1 * V_2 , int V_3 )
{
return;
}
static int F_2 (
struct V_4 * V_5 ,
struct V_6 * V_6 ,
T_1 V_7
) {
struct V_1 * V_2 = F_3 ( V_5 ) ;
struct V_8 * V_8 ;
T_2 * V_9 ;
unsigned int V_10 = V_6 -> V_10 ;
int V_11 , V_12 = 0 ;
unsigned long V_13 ;
int V_14 = 0 ;
#ifdef F_4
F_5 ( V_6 , L_1 , F_6 ( V_10 ) , - V_15 ) ;
#endif
if ( ! ( V_8 = F_7 ( V_2 , V_6 -> V_16 , V_6 -> V_17 , V_10 , V_6 -> V_18 ) ) )
return - V_19 ;
switch ( V_8 -> type ) {
case V_20 :
if ( V_6 -> V_21 > 4096 )
return - V_22 ;
V_12 = 2 ;
default:
V_12 += V_6 -> V_21 / 4096 ;
if ( ( V_6 -> V_21 % 4096 ) != 0 )
V_12 ++ ;
if ( V_12 == 0 )
V_12 ++ ;
else if ( ( V_6 -> V_23 & V_24 ) != 0
&& ( V_6 -> V_21
% F_8 ( V_6 -> V_17 , V_10 ,
F_9 ( V_10 ) ) ) == 0 )
V_12 ++ ;
break;
case V_25 :
V_12 = V_6 -> V_26 ;
break;
}
V_9 = F_10 ( sizeof ( T_2 ) + V_12 * sizeof ( struct V_27 * ) ,
V_7 ) ;
if ( ! V_9 )
return - V_19 ;
F_11 ( & V_9 -> V_28 ) ;
V_9 -> V_29 = V_12 ;
V_9 -> V_8 = V_8 ;
for ( V_11 = 0 ; V_11 < V_12 ; V_11 ++ ) {
V_9 -> V_27 [ V_11 ] = F_12 ( V_2 , V_7 ) ;
if ( ! V_9 -> V_27 [ V_11 ] ) {
V_9 -> V_29 = V_11 ;
F_13 ( V_2 , V_9 ) ;
return - V_19 ;
}
}
F_14 ( & V_2 -> V_30 , V_13 ) ;
if ( ! F_15 ( V_5 ) ) {
V_14 = - V_31 ;
goto V_32;
}
if ( V_2 -> V_33 != V_34 ) {
V_14 = - V_31 ;
goto V_32;
}
V_14 = F_16 ( V_5 , V_6 ) ;
if ( V_14 )
goto V_32;
if ( V_8 -> V_35 == V_36 ) {
V_14 = F_17 ( V_2 , V_8 ) ;
if ( V_14 < 0 ) {
F_18 ( V_5 , V_6 ) ;
goto V_32;
}
if ( V_8 -> type == V_25 ) {
T_3 V_37 = F_19 ( V_2 ) ;
V_37 += F_20 ( T_3 , 8 , V_8 -> V_18 ) ;
V_37 &= ~ ( V_8 -> V_18 - 1 ) ;
V_37 |= V_8 -> V_38 ;
V_6 -> V_39 = V_37 ;
}
} else if ( V_8 -> type == V_25 )
V_6 -> V_39 = V_8 -> V_40 + V_8 -> V_18 ;
V_6 -> V_41 = V_9 ;
F_21 ( V_2 , V_6 ) ;
V_32:
if ( V_14 )
F_13 ( V_2 , V_9 ) ;
F_22 ( & V_2 -> V_30 , V_13 ) ;
return V_14 ;
}
static int F_23 ( struct V_4 * V_5 , struct V_6 * V_6 , int V_42 )
{
struct V_1 * V_2 = F_3 ( V_5 ) ;
unsigned long V_13 ;
int V_43 ;
#ifdef F_4
F_5 ( V_6 , L_2 , 1 , V_42 ) ;
#endif
F_14 ( & V_2 -> V_30 , V_13 ) ;
V_43 = F_24 ( V_5 , V_6 , V_42 ) ;
if ( V_43 ) {
;
} else if ( V_2 -> V_33 == V_34 ) {
T_2 * V_9 ;
V_9 = V_6 -> V_41 ;
if ( V_9 ) {
if ( V_9 -> V_8 -> V_35 == V_44 )
F_25 ( V_2 , V_9 -> V_8 ) ;
}
} else {
if ( V_6 -> V_41 )
F_26 ( V_2 , V_6 , V_42 ) ;
}
F_22 ( & V_2 -> V_30 , V_13 ) ;
return V_43 ;
}
static void
F_27 ( struct V_4 * V_5 , struct V_45 * V_16 )
{
struct V_1 * V_2 = F_3 ( V_5 ) ;
unsigned long V_13 ;
struct V_8 * V_8 = V_16 -> V_41 ;
unsigned V_46 = 1000 ;
if ( ! V_8 )
return;
V_47:
F_14 ( & V_2 -> V_30 , V_13 ) ;
if ( V_2 -> V_33 != V_34 ) {
V_48:
V_8 -> V_35 = V_36 ;
if ( F_28 ( V_2 ) && V_8 -> type == V_49 )
V_2 -> V_50 -- ;
F_29 ( V_2 , 0 ) ;
}
switch ( V_8 -> V_35 ) {
case V_51 :
if ( V_46 -- == 0 ) {
F_30 ( V_2 , L_3 ) ;
if ( F_28 ( V_2 ) ) {
F_30 ( V_2 , L_4 ) ;
V_2 -> V_52 = V_8 ;
V_2 -> V_53 = 2 ;
}
goto V_48;
}
F_22 ( & V_2 -> V_30 , V_13 ) ;
F_31 ( 1 ) ;
goto V_47;
case V_36 :
if ( F_32 ( & V_8 -> V_54 ) ) {
F_33 ( V_2 , V_8 -> V_55 ) ;
F_34 ( V_2 , V_8 ) ;
break;
}
default:
F_35 ( V_2 , L_5 ,
V_8 , V_16 -> V_56 . V_57 , V_8 -> V_35 ,
F_32 ( & V_8 -> V_54 ) ? L_6 : L_7 ) ;
F_33 ( V_2 , V_8 -> V_55 ) ;
break;
}
V_16 -> V_41 = NULL ;
F_22 ( & V_2 -> V_30 , V_13 ) ;
}
static int F_36 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = F_3 ( V_5 ) ;
return F_19 ( V_2 ) ;
}
static void F_37 ( struct V_1 * V_2 )
{
V_2 -> V_58 = F_38 ( V_2 , & V_2 -> V_59 -> V_60 ) ;
V_2 -> V_58 &= V_61 ;
F_39 ( V_2 , V_2 -> V_58 , & V_2 -> V_59 -> V_60 ) ;
V_2 -> V_33 = V_62 ;
}
static void
F_40 ( struct V_4 * V_5 )
{
struct V_1 * V_2 ;
V_2 = F_3 ( V_5 ) ;
F_39 ( V_2 , ( V_63 ) ~ 0 , & V_2 -> V_59 -> V_64 ) ;
F_39 ( V_2 , V_65 , & V_2 -> V_59 -> V_66 ) ;
F_38 ( V_2 , & V_2 -> V_59 -> V_66 ) ;
F_41 ( 10 ) ;
F_39 ( V_2 , V_2 -> V_67 , & V_2 -> V_59 -> V_67 ) ;
}
static int F_42 ( struct V_1 * V_2 , struct V_8 * V_8 )
{
return ( F_43 ( V_2 , V_8 -> V_68 ) & V_69 ) != 0
&& ( F_43 ( V_2 , V_8 -> V_70 ) & V_71 )
== ( F_43 ( V_2 , V_8 -> V_72 ) & V_71 )
&& ! F_32 ( & V_8 -> V_54 ) ;
}
static void F_44 ( unsigned long V_73 )
{
unsigned long V_13 ;
unsigned V_74 ;
unsigned V_75 = 0 ;
unsigned V_11 ;
struct V_8 * * V_76 = NULL ;
struct V_1 * V_2 = (struct V_1 * ) V_73 ;
F_14 ( & V_2 -> V_30 , V_13 ) ;
V_74 = V_2 -> V_50 ;
if ( ! V_74 )
goto V_77;
if ( V_2 -> V_52 )
goto V_78;
V_76 = F_45 ( V_74 , sizeof *V_76 , V_79 ) ;
if ( ! V_76 )
goto V_78;
for ( V_11 = 0 ; V_11 < V_80 ; V_11 ++ ) {
struct V_8 * V_8 = V_2 -> V_81 [ V_11 ] ;
while ( V_8 ) {
unsigned V_82 ;
for ( V_82 = 0 ; V_82 < V_75 ; V_82 ++ ) {
if ( V_76 [ V_82 ] == V_8 ) {
V_8 = NULL ;
break;
}
}
if ( ! V_8 )
break;
V_76 [ V_75 ++ ] = V_8 ;
if ( ! F_42 ( V_2 , V_8 ) ) {
V_8 = V_8 -> V_83 ;
continue;
}
V_2 -> V_52 = V_8 ;
V_2 -> V_53 = 2 ;
F_39 ( V_2 , V_84 ,
& V_2 -> V_59 -> V_85 ) ;
F_39 ( V_2 , V_84 ,
& V_2 -> V_59 -> V_86 ) ;
( void ) F_38 ( V_2 , & V_2 -> V_59 -> V_60 ) ;
goto V_78;
}
}
V_78:
F_46 ( V_76 ) ;
if ( V_2 -> V_50 )
F_47 ( & V_2 -> V_87 , F_48 ( V_88 + V_89 ) ) ;
V_77:
F_22 ( & V_2 -> V_30 , V_13 ) ;
}
static int F_49 ( struct V_1 * V_2 )
{
int V_90 ;
struct V_4 * V_5 = F_50 ( V_2 ) ;
if ( V_91 )
V_2 -> V_13 |= V_92 ;
V_2 -> V_33 = V_62 ;
V_2 -> V_59 = V_5 -> V_59 ;
#ifndef F_51
if ( ! V_93 && F_38 ( V_2 ,
& V_2 -> V_59 -> V_60 ) & V_94 ) {
V_63 V_82 ;
F_52 ( V_2 , L_8 ) ;
V_82 = 500 ;
F_39 ( V_2 , V_95 , & V_2 -> V_59 -> V_86 ) ;
F_39 ( V_2 , V_96 , & V_2 -> V_59 -> V_66 ) ;
while ( F_38 ( V_2 , & V_2 -> V_59 -> V_60 ) & V_94 ) {
F_53 ( 10 ) ;
if ( -- V_82 == 0 ) {
F_35 ( V_2 , L_9
L_10 ) ;
return - V_97 ;
}
}
F_37 ( V_2 ) ;
}
#endif
F_39 ( V_2 , V_98 , & V_2 -> V_59 -> V_64 ) ;
if ( F_38 ( V_2 , & V_2 -> V_59 -> V_60 ) & V_61 )
V_2 -> V_58 |= V_61 ;
if ( V_2 -> V_99 == 0 )
V_2 -> V_99 = F_54 ( V_2 ) & V_100 ;
if ( V_2 -> V_101 )
return 0 ;
V_2 -> V_101 = F_55 ( V_5 -> V_102 . V_103 ,
sizeof * V_2 -> V_101 , & V_2 -> V_104 , 0 ) ;
if ( ! V_2 -> V_101 )
return - V_19 ;
if ( ( V_90 = F_56 ( V_2 ) ) < 0 )
F_57 ( V_5 ) ;
else {
F_58 ( V_2 ) ;
}
return V_90 ;
}
static int F_59 ( struct V_1 * V_2 )
{
V_63 V_105 , V_106 ;
int V_107 = V_2 -> V_67 == 0 ;
struct V_4 * V_5 = F_50 ( V_2 ) ;
V_2 -> V_33 = V_62 ;
if ( V_107 ) {
V_106 = F_38 ( V_2 , & V_2 -> V_59 -> V_67 ) ;
V_2 -> V_67 = V_106 & 0x3fff ;
if ( V_2 -> V_67 != V_108 )
F_52 ( V_2 , L_11 ,
V_2 -> V_67 - V_108 ) ;
V_2 -> V_67 |= F_60 ( V_2 -> V_67 ) << 16 ;
}
if ( ( V_2 -> V_58 & V_61 ) != 0 )
F_61 ( V_5 -> V_102 . V_103 , 1 ) ;
switch ( V_2 -> V_58 & V_109 ) {
case V_110 :
V_106 = 0 ;
break;
case V_111 :
case V_112 :
V_2 -> V_58 &= V_61 ;
V_2 -> V_58 |= V_112 ;
V_106 = 10 ;
break;
default:
V_2 -> V_58 &= V_61 ;
V_2 -> V_58 |= V_113 ;
V_106 = 50 ;
break;
}
F_39 ( V_2 , V_2 -> V_58 , & V_2 -> V_59 -> V_60 ) ;
( void ) F_38 ( V_2 , & V_2 -> V_59 -> V_60 ) ;
F_53 ( V_106 ) ;
memset ( V_2 -> V_101 , 0 , sizeof ( struct V_114 ) ) ;
F_62 ( & V_2 -> V_30 ) ;
V_115:
F_39 ( V_2 , V_65 , & V_2 -> V_59 -> V_66 ) ;
V_106 = 30 ;
while ( ( F_38 ( V_2 , & V_2 -> V_59 -> V_66 ) & V_65 ) != 0 ) {
if ( -- V_106 == 0 ) {
F_63 ( & V_2 -> V_30 ) ;
F_35 ( V_2 , L_12 ) ;
return - 1 ;
}
F_41 ( 1 ) ;
}
if ( V_2 -> V_13 & V_116 ) {
F_39 ( V_2 , V_2 -> V_58 , & V_2 -> V_59 -> V_60 ) ;
( void ) F_38 ( V_2 , & V_2 -> V_59 -> V_60 ) ;
}
F_39 ( V_2 , 0 , & V_2 -> V_59 -> V_117 ) ;
F_39 ( V_2 , 0 , & V_2 -> V_59 -> V_118 ) ;
F_39 ( V_2 , ( V_63 ) V_2 -> V_104 , & V_2 -> V_59 -> V_101 ) ;
F_64 ( V_2 ) ;
if ( ( F_38 ( V_2 , & V_2 -> V_59 -> V_67 ) & 0x3fff0000 ) == 0
|| ! F_38 ( V_2 , & V_2 -> V_59 -> V_119 ) ) {
if ( ! ( V_2 -> V_13 & V_116 ) ) {
V_2 -> V_13 |= V_116 ;
F_52 ( V_2 , L_13 ) ;
goto V_115;
}
F_63 ( & V_2 -> V_30 ) ;
F_35 ( V_2 , L_14 ,
F_38 ( V_2 , & V_2 -> V_59 -> V_67 ) ,
F_38 ( V_2 , & V_2 -> V_59 -> V_119 ) ) ;
return - V_120 ;
}
F_65 ( V_121 , & V_5 -> V_13 ) ;
V_5 -> V_122 = 1 ;
V_2 -> V_58 &= V_61 ;
V_2 -> V_58 |= V_123 | V_110 ;
F_39 ( V_2 , V_2 -> V_58 , & V_2 -> V_59 -> V_60 ) ;
V_2 -> V_33 = V_34 ;
F_39 ( V_2 , V_124 , & V_2 -> V_59 -> V_125 . V_42 ) ;
V_105 = V_126 ;
F_39 ( V_2 , ~ 0 , & V_2 -> V_59 -> V_85 ) ;
F_39 ( V_2 , V_105 , & V_2 -> V_59 -> V_86 ) ;
V_106 = F_54 ( V_2 ) ;
V_106 &= ~ ( V_127 | V_128 ) ;
if ( V_2 -> V_13 & V_129 ) {
V_106 |= V_130 ;
V_106 &= ~ ( V_131 | V_132 ) ;
F_39 ( V_2 , V_106 , & V_2 -> V_59 -> V_125 . V_133 ) ;
} else if ( ( V_2 -> V_13 & V_134 ) ||
( V_2 -> V_13 & V_92 ) ) {
V_106 |= V_132 ;
F_39 ( V_2 , V_106 , & V_2 -> V_59 -> V_125 . V_133 ) ;
}
F_39 ( V_2 , V_135 , & V_2 -> V_59 -> V_125 . V_42 ) ;
F_39 ( V_2 , ( V_106 & V_132 ) ? 0 : V_136 ,
& V_2 -> V_59 -> V_125 . V_137 ) ;
( void ) F_38 ( V_2 , & V_2 -> V_59 -> V_60 ) ;
V_2 -> V_138 = V_88 + V_139 ;
F_63 ( & V_2 -> V_30 ) ;
F_66 ( ( V_106 >> 23 ) & 0x1fe ) ;
if ( F_28 ( V_2 ) ) {
F_67 ( & V_2 -> V_87 , F_44 ,
( unsigned long ) V_2 ) ;
V_2 -> V_50 = 0 ;
V_2 -> V_52 = NULL ;
}
F_68 ( V_2 , 1 ) ;
return 0 ;
}
static T_4 F_69 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = F_3 ( V_5 ) ;
struct V_140 T_5 * V_59 = V_2 -> V_59 ;
int V_141 ;
V_141 = F_38 ( V_2 , & V_59 -> V_85 ) ;
if ( V_141 == ~ ( V_63 ) 0 ) {
V_2 -> V_33 = V_62 ;
F_52 ( V_2 , L_15 ) ;
F_70 ( V_5 ) ;
return V_142 ;
}
V_141 &= F_38 ( V_2 , & V_59 -> V_86 ) ;
if ( V_141 == 0 || F_71 ( V_2 -> V_33 == V_62 ) )
return V_143 ;
if ( V_141 & V_144 ) {
if ( F_72 ( V_2 ) ) {
F_35 ( V_2 , L_16 ) ;
F_39 ( V_2 , V_144 , & V_59 -> V_64 ) ;
F_73 ( & V_2 -> V_145 ) ;
} else {
F_35 ( V_2 , L_17 ) ;
V_2 -> V_33 = V_62 ;
F_70 ( V_5 ) ;
}
F_68 ( V_2 , 1 ) ;
F_37 ( V_2 ) ;
}
if ( V_141 & V_146 ) {
F_74 ( V_2 , L_18 ) ;
V_2 -> V_138 = V_88 + V_139 ;
F_39 ( V_2 , V_147 | V_146 ,
& V_59 -> V_85 ) ;
F_39 ( V_2 , V_146 , & V_59 -> V_64 ) ;
F_75 ( V_5 ) ;
}
else if ( V_141 & V_147 ) {
F_74 ( V_2 , L_19 ) ;
F_39 ( V_2 , V_147 , & V_59 -> V_85 ) ;
F_65 ( V_121 , & V_5 -> V_13 ) ;
if ( V_2 -> V_148 ) {
F_76 ( & V_2 -> V_30 ) ;
F_77 ( V_2 ) ;
F_78 ( & V_2 -> V_30 ) ;
} else
F_79 ( V_5 ) ;
}
if ( V_141 & V_149 ) {
F_76 ( & V_2 -> V_30 ) ;
F_80 ( V_2 ) ;
F_78 ( & V_2 -> V_30 ) ;
}
if ( F_28 ( V_2 ) && ( V_141 & V_84 ) ) {
F_76 ( & V_2 -> V_30 ) ;
if ( V_2 -> V_52 ) {
struct V_8 * V_8 = V_2 -> V_52 ;
if ( F_42 ( V_2 , V_8 ) ) {
if ( -- V_2 -> V_53 == 0 ) {
struct V_27 * V_27 = F_81 (
V_8 -> V_54 . V_150 ,
struct V_27 , V_54 ) ;
F_30 ( V_2 ,
L_20 ,
V_27 ) ;
F_82 ( V_2 , V_27 ) ;
V_2 -> V_52 = NULL ;
}
} else
V_2 -> V_52 = NULL ;
}
F_78 ( & V_2 -> V_30 ) ;
}
F_76 ( & V_2 -> V_30 ) ;
if ( V_2 -> V_151 )
F_29 ( V_2 , F_19 ( V_2 ) ) ;
if ( ( V_141 & V_84 ) != 0
&& ! V_2 -> V_151
&& ! V_2 -> V_52
&& V_2 -> V_33 == V_34 )
F_39 ( V_2 , V_84 , & V_59 -> V_64 ) ;
F_78 ( & V_2 -> V_30 ) ;
if ( V_2 -> V_33 == V_34 ) {
F_39 ( V_2 , V_141 , & V_59 -> V_85 ) ;
F_39 ( V_2 , V_98 , & V_59 -> V_86 ) ;
( void ) F_38 ( V_2 , & V_2 -> V_59 -> V_60 ) ;
}
return V_142 ;
}
static void F_57 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = F_3 ( V_5 ) ;
F_68 ( V_2 , 1 ) ;
if ( F_72 ( V_2 ) )
F_83 ( & V_2 -> V_145 ) ;
F_37 ( V_2 ) ;
F_39 ( V_2 , V_98 , & V_2 -> V_59 -> V_64 ) ;
F_84 ( V_5 -> V_152 , V_5 ) ;
V_5 -> V_152 = 0 ;
if ( F_28 ( V_2 ) )
F_85 ( & V_2 -> V_87 ) ;
if ( F_86 ( V_2 ) )
F_87 () ;
F_88 ( V_2 ) ;
F_89 ( V_2 ) ;
if ( V_2 -> V_101 ) {
F_90 ( V_5 -> V_102 . V_103 ,
sizeof * V_2 -> V_101 ,
V_2 -> V_101 , V_2 -> V_104 ) ;
V_2 -> V_101 = NULL ;
V_2 -> V_104 = 0 ;
}
}
static int F_91 ( struct V_1 * V_2 )
{
int V_82 ;
int V_11 ;
struct V_9 * V_153 ;
F_62 ( & V_2 -> V_30 ) ;
V_2 -> V_33 = V_62 ;
if ( ! F_32 ( & V_2 -> V_28 ) )
F_52 ( V_2 , L_21 ) ;
F_92 (priv, &ohci->pending, pending) {
struct V_6 * V_6 = V_153 -> V_27 [ 0 ] -> V_6 ;
struct V_8 * V_8 = V_153 -> V_8 ;
switch ( V_8 -> V_35 ) {
case V_44 :
V_8 -> V_35 = V_51 ;
V_8 -> V_68 |= F_93 ( V_2 , V_154 ) ;
F_94 ( V_2 , V_8 ) ;
V_8 -> V_83 = V_2 -> V_151 ;
V_8 -> V_155 = NULL ;
V_2 -> V_151 = V_8 ;
case V_51 :
break;
default:
F_52 ( V_2 , L_22 ,
V_8 , V_8 -> V_35 ) ;
}
if ( ! V_6 -> V_156 )
V_6 -> V_156 = - V_157 ;
}
F_29 ( V_2 , 0 ) ;
F_63 ( & V_2 -> V_30 ) ;
for ( V_11 = 0 ; V_11 < V_80 ; V_11 ++ ) V_2 -> V_158 [ V_11 ] = 0 ;
for ( V_11 = 0 ; V_11 < V_80 ; V_11 ++ ) V_2 -> V_101 -> V_159 [ V_11 ] = 0 ;
V_2 -> V_151 = NULL ;
V_2 -> V_160 = NULL ;
V_2 -> V_161 = NULL ;
if ( ( V_82 = F_59 ( V_2 ) ) < 0 ) {
F_35 ( V_2 , L_23 , V_82 ) ;
return V_82 ;
}
F_52 ( V_2 , L_24 ) ;
return 0 ;
}
static int T_6 F_95 ( void )
{
int V_14 = 0 ;
if ( F_96 () )
return - V_31 ;
F_97 ( V_162 L_25 V_163 L_26 , V_164 ) ;
F_98 ( L_27 , V_164 ,
sizeof ( struct V_8 ) , sizeof ( struct V_27 ) ) ;
F_65 ( V_165 , & V_166 ) ;
#ifdef F_99
V_167 = F_100 ( L_28 , V_168 ) ;
if ( ! V_167 ) {
V_14 = - V_169 ;
goto V_170;
}
#endif
#ifdef F_101
V_14 = F_102 ( & F_101 ) ;
if ( V_14 < 0 )
goto V_171;
#endif
#ifdef F_103
V_14 = F_104 ( & F_103 ) ;
if ( V_14 < 0 )
goto V_172;
#endif
#ifdef F_105
V_14 = F_104 ( & F_105 ) ;
if ( V_14 < 0 )
goto V_173;
#endif
#ifdef F_106
V_14 = F_104 ( & F_106 ) ;
if ( V_14 < 0 )
goto V_174;
#endif
#ifdef F_107
V_14 = F_104 ( & F_107 ) ;
if ( V_14 < 0 )
goto V_175;
#endif
#ifdef F_108
V_14 = F_109 ( & F_108 ) ;
if ( V_14 < 0 )
goto V_176;
#endif
#ifdef F_110
V_14 = F_111 ( & F_110 ) ;
if ( V_14 < 0 )
goto V_177;
#endif
#ifdef F_112
V_14 = F_104 ( & F_112 ) ;
if ( V_14 < 0 )
goto V_178;
#endif
#ifdef F_113
V_14 = F_104 ( & F_113 ) ;
if ( V_14 < 0 )
goto V_179;
#endif
return V_14 ;
#ifdef F_113
F_114 ( & F_113 ) ;
V_179:
#endif
#ifdef F_112
F_114 ( & F_112 ) ;
V_178:
#endif
#ifdef F_110
F_115 ( & F_110 ) ;
V_177:
#endif
#ifdef F_108
F_116 ( & F_108 ) ;
V_176:
#endif
#ifdef F_107
F_114 ( & F_107 ) ;
V_175:
#endif
#ifdef F_103
F_114 ( & F_103 ) ;
V_172:
#endif
#ifdef F_105
F_114 ( & F_105 ) ;
V_173:
#endif
#ifdef F_106
F_114 ( & F_106 ) ;
V_174:
#endif
#ifdef F_101
F_117 ( & F_101 ) ;
V_171:
#endif
#ifdef F_99
F_118 ( V_167 ) ;
V_167 = NULL ;
V_170:
#endif
F_119 ( V_165 , & V_166 ) ;
return V_14 ;
}
static void T_7 F_120 ( void )
{
#ifdef F_113
F_114 ( & F_113 ) ;
#endif
#ifdef F_112
F_114 ( & F_112 ) ;
#endif
#ifdef F_110
F_115 ( & F_110 ) ;
#endif
#ifdef F_108
F_116 ( & F_108 ) ;
#endif
#ifdef F_107
F_114 ( & F_107 ) ;
#endif
#ifdef F_103
F_114 ( & F_103 ) ;
#endif
#ifdef F_106
F_114 ( & F_106 ) ;
#endif
#ifdef F_101
F_117 ( & F_101 ) ;
#endif
#ifdef F_99
F_118 ( V_167 ) ;
#endif
F_119 ( V_165 , & V_166 ) ;
}
