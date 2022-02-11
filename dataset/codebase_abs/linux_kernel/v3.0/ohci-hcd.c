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
if ( ! F_16 ( V_5 -> V_33 ) ) {
V_14 = - V_31 ;
goto V_32;
}
V_14 = F_17 ( V_5 , V_6 ) ;
if ( V_14 )
goto V_32;
if ( V_8 -> V_33 == V_34 ) {
V_14 = F_18 ( V_2 , V_8 ) ;
if ( V_14 < 0 ) {
F_19 ( V_5 , V_6 ) ;
goto V_32;
}
if ( V_8 -> type == V_25 ) {
T_3 V_35 = F_20 ( V_2 ) ;
V_35 += F_21 ( T_3 , 8 , V_8 -> V_18 ) ;
V_35 &= ~ ( V_8 -> V_18 - 1 ) ;
V_35 |= V_8 -> V_36 ;
V_6 -> V_37 = V_35 ;
}
} else if ( V_8 -> type == V_25 )
V_6 -> V_37 = V_8 -> V_38 + V_8 -> V_18 ;
V_6 -> V_39 = V_9 ;
F_22 ( V_2 , V_6 ) ;
V_32:
if ( V_14 )
F_13 ( V_2 , V_9 ) ;
F_23 ( & V_2 -> V_30 , V_13 ) ;
return V_14 ;
}
static int F_24 ( struct V_4 * V_5 , struct V_6 * V_6 , int V_40 )
{
struct V_1 * V_2 = F_3 ( V_5 ) ;
unsigned long V_13 ;
int V_41 ;
#ifdef F_4
F_5 ( V_6 , L_2 , 1 , V_40 ) ;
#endif
F_14 ( & V_2 -> V_30 , V_13 ) ;
V_41 = F_25 ( V_5 , V_6 , V_40 ) ;
if ( V_41 ) {
;
} else if ( F_16 ( V_5 -> V_33 ) ) {
T_2 * V_9 ;
V_9 = V_6 -> V_39 ;
if ( V_9 ) {
if ( V_9 -> V_8 -> V_33 == V_42 )
F_26 ( V_2 , V_9 -> V_8 ) ;
}
} else {
if ( V_6 -> V_39 )
F_27 ( V_2 , V_6 , V_40 ) ;
}
F_23 ( & V_2 -> V_30 , V_13 ) ;
return V_41 ;
}
static void
F_28 ( struct V_4 * V_5 , struct V_43 * V_16 )
{
struct V_1 * V_2 = F_3 ( V_5 ) ;
unsigned long V_13 ;
struct V_8 * V_8 = V_16 -> V_39 ;
unsigned V_44 = 1000 ;
if ( ! V_8 )
return;
V_45:
F_14 ( & V_2 -> V_30 , V_13 ) ;
if ( ! F_16 ( V_5 -> V_33 ) ) {
V_46:
V_8 -> V_33 = V_34 ;
if ( F_29 ( V_2 ) && V_8 -> type == V_47 )
V_2 -> V_48 -- ;
F_30 ( V_2 , 0 ) ;
}
switch ( V_8 -> V_33 ) {
case V_49 :
if ( V_44 -- == 0 ) {
F_31 ( V_2 , L_3 ) ;
if ( F_29 ( V_2 ) ) {
F_31 ( V_2 , L_4 ) ;
V_2 -> V_50 = V_8 ;
V_2 -> V_51 = 2 ;
}
goto V_46;
}
F_23 ( & V_2 -> V_30 , V_13 ) ;
F_32 ( 1 ) ;
goto V_45;
case V_34 :
if ( F_33 ( & V_8 -> V_52 ) ) {
F_34 ( V_2 , V_8 -> V_53 ) ;
F_35 ( V_2 , V_8 ) ;
break;
}
default:
F_36 ( V_2 , L_5 ,
V_8 , V_16 -> V_54 . V_55 , V_8 -> V_33 ,
F_33 ( & V_8 -> V_52 ) ? L_6 : L_7 ) ;
F_34 ( V_2 , V_8 -> V_53 ) ;
break;
}
V_16 -> V_39 = NULL ;
F_23 ( & V_2 -> V_30 , V_13 ) ;
}
static int F_37 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = F_3 ( V_5 ) ;
return F_20 ( V_2 ) ;
}
static void F_38 ( struct V_1 * V_2 )
{
V_2 -> V_56 = F_39 ( V_2 , & V_2 -> V_57 -> V_58 ) ;
V_2 -> V_56 &= V_59 ;
F_40 ( V_2 , V_2 -> V_56 , & V_2 -> V_57 -> V_58 ) ;
}
static void
F_41 ( struct V_4 * V_5 )
{
struct V_1 * V_2 ;
V_2 = F_3 ( V_5 ) ;
F_40 ( V_2 , V_60 , & V_2 -> V_57 -> V_61 ) ;
V_2 -> V_56 = F_39 ( V_2 , & V_2 -> V_57 -> V_58 ) ;
V_2 -> V_56 &= ( V_2 -> V_13 & V_62 ?
V_59 | V_63 :
V_59 ) ;
F_40 ( V_2 , V_2 -> V_56 , & V_2 -> V_57 -> V_58 ) ;
( void ) F_39 ( V_2 , & V_2 -> V_57 -> V_58 ) ;
}
static int F_42 ( struct V_1 * V_2 , struct V_8 * V_8 )
{
return ( F_43 ( V_2 , V_8 -> V_64 ) & V_65 ) != 0
&& ( F_43 ( V_2 , V_8 -> V_66 ) & V_67 )
== ( F_43 ( V_2 , V_8 -> V_68 ) & V_67 )
&& ! F_33 ( & V_8 -> V_52 ) ;
}
static void F_44 ( unsigned long V_69 )
{
unsigned long V_13 ;
unsigned V_70 ;
unsigned V_71 = 0 ;
unsigned V_11 ;
struct V_8 * * V_72 = NULL ;
struct V_1 * V_2 = (struct V_1 * ) V_69 ;
F_14 ( & V_2 -> V_30 , V_13 ) ;
V_70 = V_2 -> V_48 ;
if ( ! V_70 )
goto V_73;
if ( V_2 -> V_50 )
goto V_74;
V_72 = F_45 ( V_70 , sizeof *V_72 , V_75 ) ;
if ( ! V_72 )
goto V_74;
for ( V_11 = 0 ; V_11 < V_76 ; V_11 ++ ) {
struct V_8 * V_8 = V_2 -> V_77 [ V_11 ] ;
while ( V_8 ) {
unsigned V_78 ;
for ( V_78 = 0 ; V_78 < V_71 ; V_78 ++ ) {
if ( V_72 [ V_78 ] == V_8 ) {
V_8 = NULL ;
break;
}
}
if ( ! V_8 )
break;
V_72 [ V_71 ++ ] = V_8 ;
if ( ! F_42 ( V_2 , V_8 ) ) {
V_8 = V_8 -> V_79 ;
continue;
}
V_2 -> V_50 = V_8 ;
V_2 -> V_51 = 2 ;
F_40 ( V_2 , V_80 ,
& V_2 -> V_57 -> V_81 ) ;
F_40 ( V_2 , V_80 ,
& V_2 -> V_57 -> V_82 ) ;
( void ) F_39 ( V_2 , & V_2 -> V_57 -> V_58 ) ;
goto V_74;
}
}
V_74:
F_46 ( V_72 ) ;
if ( V_2 -> V_48 )
F_47 ( & V_2 -> V_83 , F_48 ( V_84 + V_85 ) ) ;
V_73:
F_23 ( & V_2 -> V_30 , V_13 ) ;
}
static int F_49 ( struct V_1 * V_2 )
{
int V_86 ;
struct V_4 * V_5 = F_50 ( V_2 ) ;
if ( V_87 )
V_2 -> V_13 |= V_88 ;
F_51 ( V_2 ) ;
V_2 -> V_57 = V_5 -> V_57 ;
#ifndef F_52
if ( ! V_89 && F_39 ( V_2 ,
& V_2 -> V_57 -> V_58 ) & V_90 ) {
T_4 V_78 ;
F_53 ( V_2 , L_8 ) ;
V_78 = 500 ;
F_40 ( V_2 , V_91 , & V_2 -> V_57 -> V_82 ) ;
F_40 ( V_2 , V_92 , & V_2 -> V_57 -> V_93 ) ;
while ( F_39 ( V_2 , & V_2 -> V_57 -> V_58 ) & V_90 ) {
F_54 ( 10 ) ;
if ( -- V_78 == 0 ) {
F_36 ( V_2 , L_9
L_10 ) ;
return - V_94 ;
}
}
F_38 ( V_2 ) ;
}
#endif
F_40 ( V_2 , V_60 , & V_2 -> V_57 -> V_61 ) ;
if ( F_39 ( V_2 , & V_2 -> V_57 -> V_58 ) & V_59 )
V_2 -> V_56 |= V_59 ;
if ( V_2 -> V_95 == 0 )
V_2 -> V_95 = F_55 ( V_2 ) & V_96 ;
if ( V_2 -> V_97 )
return 0 ;
V_2 -> V_97 = F_56 ( V_5 -> V_98 . V_99 ,
sizeof * V_2 -> V_97 , & V_2 -> V_100 , 0 ) ;
if ( ! V_2 -> V_97 )
return - V_19 ;
if ( ( V_86 = F_57 ( V_2 ) ) < 0 )
F_58 ( V_5 ) ;
else {
F_59 ( V_2 ) ;
}
return V_86 ;
}
static int F_60 ( struct V_1 * V_2 )
{
T_4 V_101 , V_102 ;
int V_103 = V_2 -> V_104 == 0 ;
struct V_4 * V_5 = F_50 ( V_2 ) ;
F_51 ( V_2 ) ;
if ( V_103 ) {
V_102 = F_39 ( V_2 , & V_2 -> V_57 -> V_104 ) ;
V_2 -> V_104 = V_102 & 0x3fff ;
if ( V_2 -> V_104 != V_105 )
F_53 ( V_2 , L_11 ,
V_2 -> V_104 - V_105 ) ;
V_2 -> V_104 |= F_61 ( V_2 -> V_104 ) << 16 ;
}
if ( ( V_2 -> V_56 & V_59 ) != 0 )
F_62 ( V_5 -> V_98 . V_99 , 1 ) ;
switch ( V_2 -> V_56 & V_63 ) {
case V_106 :
V_102 = 0 ;
break;
case V_107 :
case V_108 :
V_2 -> V_56 &= V_59 ;
V_2 -> V_56 |= V_108 ;
V_102 = 10 ;
break;
default:
V_2 -> V_56 &= V_59 ;
V_2 -> V_56 |= V_109 ;
V_102 = 50 ;
break;
}
F_40 ( V_2 , V_2 -> V_56 , & V_2 -> V_57 -> V_58 ) ;
( void ) F_39 ( V_2 , & V_2 -> V_57 -> V_58 ) ;
F_54 ( V_102 ) ;
memset ( V_2 -> V_97 , 0 , sizeof ( struct V_110 ) ) ;
F_63 ( & V_2 -> V_30 ) ;
V_111:
F_40 ( V_2 , V_112 , & V_2 -> V_57 -> V_93 ) ;
V_102 = 30 ;
while ( ( F_39 ( V_2 , & V_2 -> V_57 -> V_93 ) & V_112 ) != 0 ) {
if ( -- V_102 == 0 ) {
F_64 ( & V_2 -> V_30 ) ;
F_36 ( V_2 , L_12 ) ;
return - 1 ;
}
F_65 ( 1 ) ;
}
if ( V_2 -> V_13 & V_113 ) {
F_40 ( V_2 , V_2 -> V_56 , & V_2 -> V_57 -> V_58 ) ;
( void ) F_39 ( V_2 , & V_2 -> V_57 -> V_58 ) ;
}
F_40 ( V_2 , 0 , & V_2 -> V_57 -> V_114 ) ;
F_40 ( V_2 , 0 , & V_2 -> V_57 -> V_115 ) ;
F_40 ( V_2 , ( T_4 ) V_2 -> V_100 , & V_2 -> V_57 -> V_97 ) ;
F_66 ( V_2 ) ;
if ( ( F_39 ( V_2 , & V_2 -> V_57 -> V_104 ) & 0x3fff0000 ) == 0
|| ! F_39 ( V_2 , & V_2 -> V_57 -> V_116 ) ) {
if ( ! ( V_2 -> V_13 & V_113 ) ) {
V_2 -> V_13 |= V_113 ;
F_53 ( V_2 , L_13 ) ;
goto V_111;
}
F_64 ( & V_2 -> V_30 ) ;
F_36 ( V_2 , L_14 ,
F_39 ( V_2 , & V_2 -> V_57 -> V_104 ) ,
F_39 ( V_2 , & V_2 -> V_57 -> V_116 ) ) ;
return - V_117 ;
}
F_67 ( V_118 , & V_5 -> V_13 ) ;
V_5 -> V_119 = 1 ;
V_2 -> V_56 &= V_59 ;
V_2 -> V_56 |= V_120 | V_106 ;
F_40 ( V_2 , V_2 -> V_56 , & V_2 -> V_57 -> V_58 ) ;
V_5 -> V_33 = V_121 ;
F_40 ( V_2 , V_122 , & V_2 -> V_57 -> V_123 . V_40 ) ;
V_101 = V_124 ;
F_40 ( V_2 , ~ 0 , & V_2 -> V_57 -> V_81 ) ;
F_40 ( V_2 , V_101 , & V_2 -> V_57 -> V_82 ) ;
V_102 = F_55 ( V_2 ) ;
V_102 &= ~ ( V_125 | V_126 ) ;
if ( V_2 -> V_13 & V_127 ) {
V_102 |= V_128 ;
V_102 &= ~ ( V_129 | V_130 ) ;
F_40 ( V_2 , V_102 , & V_2 -> V_57 -> V_123 . V_131 ) ;
} else if ( ( V_2 -> V_13 & V_132 ) ||
( V_2 -> V_13 & V_88 ) ) {
V_102 |= V_130 ;
F_40 ( V_2 , V_102 , & V_2 -> V_57 -> V_123 . V_131 ) ;
}
F_40 ( V_2 , V_133 , & V_2 -> V_57 -> V_123 . V_40 ) ;
F_40 ( V_2 , ( V_102 & V_130 ) ? 0 : V_134 ,
& V_2 -> V_57 -> V_123 . V_135 ) ;
( void ) F_39 ( V_2 , & V_2 -> V_57 -> V_58 ) ;
V_2 -> V_136 = V_84 + V_137 ;
F_64 ( & V_2 -> V_30 ) ;
F_68 ( ( V_102 >> 23 ) & 0x1fe ) ;
V_5 -> V_33 = V_121 ;
if ( F_29 ( V_2 ) ) {
F_69 ( & V_2 -> V_83 , F_44 ,
( unsigned long ) V_2 ) ;
V_2 -> V_48 = 0 ;
V_2 -> V_50 = NULL ;
}
F_70 ( V_2 , 1 ) ;
return 0 ;
}
static T_5 F_71 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = F_3 ( V_5 ) ;
struct V_138 T_6 * V_57 = V_2 -> V_57 ;
int V_139 ;
V_139 = F_39 ( V_2 , & V_57 -> V_81 ) ;
if ( V_139 == ~ ( T_4 ) 0 ) {
F_51 ( V_2 ) ;
F_53 ( V_2 , L_15 ) ;
F_72 ( V_5 ) ;
return V_140 ;
}
V_139 &= F_39 ( V_2 , & V_57 -> V_82 ) ;
if ( V_139 == 0 || F_73 ( V_5 -> V_33 == V_141 ) )
return V_142 ;
if ( V_139 & V_143 ) {
if ( F_74 ( V_2 ) ) {
F_36 ( V_2 , L_16 ) ;
F_40 ( V_2 , V_143 , & V_57 -> V_61 ) ;
F_75 ( & V_2 -> V_144 ) ;
} else {
F_51 ( V_2 ) ;
F_36 ( V_2 , L_17 ) ;
F_72 ( V_5 ) ;
}
F_70 ( V_2 , 1 ) ;
F_38 ( V_2 ) ;
}
if ( V_139 & V_145 ) {
F_76 ( V_2 , L_18 ) ;
V_2 -> V_136 = V_84 + V_137 ;
F_40 ( V_2 , V_146 | V_145 ,
& V_57 -> V_81 ) ;
F_40 ( V_2 , V_145 , & V_57 -> V_61 ) ;
F_77 ( V_5 ) ;
}
else if ( V_139 & V_146 ) {
F_76 ( V_2 , L_19 ) ;
F_40 ( V_2 , V_146 , & V_57 -> V_81 ) ;
F_67 ( V_118 , & V_5 -> V_13 ) ;
if ( V_2 -> V_147 ) {
F_78 ( & V_2 -> V_30 ) ;
F_79 ( V_2 ) ;
F_80 ( & V_2 -> V_30 ) ;
} else
F_81 ( V_5 ) ;
}
if ( V_139 & V_148 ) {
F_78 ( & V_2 -> V_30 ) ;
F_82 ( V_2 ) ;
F_80 ( & V_2 -> V_30 ) ;
}
if ( F_29 ( V_2 ) && ( V_139 & V_80 ) ) {
F_78 ( & V_2 -> V_30 ) ;
if ( V_2 -> V_50 ) {
struct V_8 * V_8 = V_2 -> V_50 ;
if ( F_42 ( V_2 , V_8 ) ) {
if ( -- V_2 -> V_51 == 0 ) {
struct V_27 * V_27 = F_83 (
V_8 -> V_52 . V_149 ,
struct V_27 , V_52 ) ;
F_31 ( V_2 ,
L_20 ,
V_27 ) ;
F_84 ( V_2 , V_27 ) ;
V_2 -> V_50 = NULL ;
}
} else
V_2 -> V_50 = NULL ;
}
F_80 ( & V_2 -> V_30 ) ;
}
F_78 ( & V_2 -> V_30 ) ;
if ( V_2 -> V_150 )
F_30 ( V_2 , F_20 ( V_2 ) ) ;
if ( ( V_139 & V_80 ) != 0
&& ! V_2 -> V_150
&& ! V_2 -> V_50
&& F_16 ( V_5 -> V_33 ) )
F_40 ( V_2 , V_80 , & V_57 -> V_61 ) ;
F_80 ( & V_2 -> V_30 ) ;
if ( F_16 ( V_5 -> V_33 ) ) {
F_40 ( V_2 , V_139 , & V_57 -> V_81 ) ;
F_40 ( V_2 , V_60 , & V_57 -> V_82 ) ;
( void ) F_39 ( V_2 , & V_2 -> V_57 -> V_58 ) ;
}
return V_140 ;
}
static void F_58 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = F_3 ( V_5 ) ;
F_70 ( V_2 , 1 ) ;
if ( F_74 ( V_2 ) )
F_85 ( & V_2 -> V_144 ) ;
F_38 ( V_2 ) ;
F_40 ( V_2 , V_60 , & V_2 -> V_57 -> V_61 ) ;
F_86 ( V_5 -> V_151 , V_5 ) ;
V_5 -> V_151 = - 1 ;
if ( F_29 ( V_2 ) )
F_87 ( & V_2 -> V_83 ) ;
if ( F_88 ( V_2 ) )
F_89 () ;
F_90 ( V_2 ) ;
F_91 ( V_2 ) ;
if ( V_2 -> V_97 ) {
F_92 ( V_5 -> V_98 . V_99 ,
sizeof * V_2 -> V_97 ,
V_2 -> V_97 , V_2 -> V_100 ) ;
V_2 -> V_97 = NULL ;
V_2 -> V_100 = 0 ;
}
}
static int F_93 ( struct V_1 * V_2 )
{
int V_78 ;
int V_11 ;
struct V_9 * V_152 ;
F_63 ( & V_2 -> V_30 ) ;
F_51 ( V_2 ) ;
if ( ! F_33 ( & V_2 -> V_28 ) )
F_53 ( V_2 , L_21 ) ;
F_94 (priv, &ohci->pending, pending) {
struct V_6 * V_6 = V_152 -> V_27 [ 0 ] -> V_6 ;
struct V_8 * V_8 = V_152 -> V_8 ;
switch ( V_8 -> V_33 ) {
case V_42 :
V_8 -> V_33 = V_49 ;
V_8 -> V_64 |= F_95 ( V_2 , V_153 ) ;
F_96 ( V_2 , V_8 ) ;
V_8 -> V_79 = V_2 -> V_150 ;
V_8 -> V_154 = NULL ;
V_2 -> V_150 = V_8 ;
case V_49 :
break;
default:
F_53 ( V_2 , L_22 ,
V_8 , V_8 -> V_33 ) ;
}
if ( ! V_6 -> V_155 )
V_6 -> V_155 = - V_156 ;
}
F_30 ( V_2 , 0 ) ;
F_64 ( & V_2 -> V_30 ) ;
for ( V_11 = 0 ; V_11 < V_76 ; V_11 ++ ) V_2 -> V_157 [ V_11 ] = 0 ;
for ( V_11 = 0 ; V_11 < V_76 ; V_11 ++ ) V_2 -> V_97 -> V_158 [ V_11 ] = 0 ;
V_2 -> V_150 = NULL ;
V_2 -> V_159 = NULL ;
V_2 -> V_160 = NULL ;
if ( ( V_78 = F_60 ( V_2 ) ) < 0 ) {
F_36 ( V_2 , L_23 , V_78 ) ;
return V_78 ;
}
F_53 ( V_2 , L_24 ) ;
return 0 ;
}
static int T_7 F_97 ( void )
{
int V_14 = 0 ;
if ( F_98 () )
return - V_31 ;
F_99 ( V_161 L_25 V_162 L_26 , V_163 ) ;
F_100 ( L_27 , V_163 ,
sizeof ( struct V_8 ) , sizeof ( struct V_27 ) ) ;
F_67 ( V_164 , & V_165 ) ;
#ifdef F_101
V_166 = F_102 ( L_28 , V_167 ) ;
if ( ! V_166 ) {
V_14 = - V_168 ;
goto V_169;
}
#endif
#ifdef F_103
V_14 = F_104 ( & F_103 ) ;
if ( V_14 < 0 )
goto V_170;
#endif
#ifdef F_105
V_14 = F_106 ( & F_105 ) ;
if ( V_14 < 0 )
goto V_171;
#endif
#ifdef F_107
V_14 = F_106 ( & F_107 ) ;
if ( V_14 < 0 )
goto V_172;
#endif
#ifdef F_108
V_14 = F_106 ( & F_108 ) ;
if ( V_14 < 0 )
goto V_173;
#endif
#ifdef F_109
V_14 = F_106 ( & F_109 ) ;
if ( V_14 < 0 )
goto V_174;
#endif
#ifdef F_110
V_14 = F_111 ( & F_110 ) ;
if ( V_14 < 0 )
goto V_175;
#endif
#ifdef F_112
V_14 = F_113 ( & F_112 ) ;
if ( V_14 < 0 )
goto V_176;
#endif
#ifdef F_114
V_14 = F_115 ( & F_114 ) ;
if ( V_14 )
goto V_177;
#endif
#ifdef F_116
V_14 = F_106 ( & F_116 ) ;
if ( V_14 < 0 )
goto V_178;
#endif
#ifdef F_117
V_14 = F_106 ( & F_117 ) ;
if ( V_14 < 0 )
goto V_179;
#endif
return V_14 ;
#ifdef F_117
F_118 ( & F_117 ) ;
V_179:
#endif
#ifdef F_116
F_118 ( & F_116 ) ;
V_178:
#endif
#ifdef F_114
F_119 ( & F_114 ) ;
V_177:
#endif
#ifdef F_112
F_120 ( & F_112 ) ;
V_176:
#endif
#ifdef F_110
F_121 ( & F_110 ) ;
V_175:
#endif
#ifdef F_109
F_118 ( & F_109 ) ;
V_174:
#endif
#ifdef F_105
F_118 ( & F_105 ) ;
V_171:
#endif
#ifdef F_107
F_118 ( & F_107 ) ;
V_172:
#endif
#ifdef F_108
F_118 ( & F_108 ) ;
V_173:
#endif
#ifdef F_103
F_122 ( & F_103 ) ;
V_170:
#endif
#ifdef F_101
F_123 ( V_166 ) ;
V_166 = NULL ;
V_169:
#endif
F_124 ( V_164 , & V_165 ) ;
return V_14 ;
}
static void T_8 F_125 ( void )
{
#ifdef F_117
F_118 ( & F_117 ) ;
#endif
#ifdef F_116
F_118 ( & F_116 ) ;
#endif
#ifdef F_114
F_119 ( & F_114 ) ;
#endif
#ifdef F_112
F_120 ( & F_112 ) ;
#endif
#ifdef F_110
F_121 ( & F_110 ) ;
#endif
#ifdef F_109
F_118 ( & F_109 ) ;
#endif
#ifdef F_105
F_118 ( & F_105 ) ;
#endif
#ifdef F_108
F_118 ( & F_108 ) ;
#endif
#ifdef F_103
F_122 ( & F_103 ) ;
#endif
#ifdef F_101
F_123 ( V_166 ) ;
#endif
F_124 ( V_164 , & V_165 ) ;
}
