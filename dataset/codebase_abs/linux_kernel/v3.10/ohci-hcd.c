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
} else if ( V_8 -> type == V_25 ) {
T_3 V_40 = F_19 ( V_2 ) + 1 ;
T_3 V_37 = V_8 -> V_41 + V_8 -> V_18 ;
if ( F_21 ( F_22 ( V_37 , V_40 ) ) ) {
if ( V_6 -> V_23 & V_42 ) {
V_37 += ( V_40 - V_37 + V_8 -> V_18 - 1 ) &
- V_8 -> V_18 ;
} else {
if ( F_22 ( V_37 + V_8 -> V_18 *
( V_6 -> V_26 - 1 ) , V_40 ) ) {
V_14 = - V_43 ;
F_18 ( V_5 , V_6 ) ;
goto V_32;
}
V_9 -> V_44 = F_23 (
( T_3 ) ( V_40 - V_37 ) ,
V_8 -> V_18 ) ;
}
}
V_6 -> V_39 = V_37 ;
}
V_6 -> V_45 = V_9 ;
F_24 ( V_2 , V_6 ) ;
V_32:
if ( V_14 )
F_13 ( V_2 , V_9 ) ;
F_25 ( & V_2 -> V_30 , V_13 ) ;
return V_14 ;
}
static int F_26 ( struct V_4 * V_5 , struct V_6 * V_6 , int V_46 )
{
struct V_1 * V_2 = F_3 ( V_5 ) ;
unsigned long V_13 ;
int V_47 ;
#ifdef F_4
F_5 ( V_6 , L_2 , 1 , V_46 ) ;
#endif
F_14 ( & V_2 -> V_30 , V_13 ) ;
V_47 = F_27 ( V_5 , V_6 , V_46 ) ;
if ( V_47 ) {
;
} else if ( V_2 -> V_33 == V_34 ) {
T_2 * V_9 ;
V_9 = V_6 -> V_45 ;
if ( V_9 ) {
if ( V_9 -> V_8 -> V_35 == V_48 )
F_28 ( V_2 , V_9 -> V_8 ) ;
}
} else {
if ( V_6 -> V_45 )
F_29 ( V_2 , V_6 , V_46 ) ;
}
F_25 ( & V_2 -> V_30 , V_13 ) ;
return V_47 ;
}
static void
F_30 ( struct V_4 * V_5 , struct V_49 * V_16 )
{
struct V_1 * V_2 = F_3 ( V_5 ) ;
unsigned long V_13 ;
struct V_8 * V_8 = V_16 -> V_45 ;
unsigned V_50 = 1000 ;
if ( ! V_8 )
return;
V_51:
F_14 ( & V_2 -> V_30 , V_13 ) ;
if ( V_2 -> V_33 != V_34 ) {
V_52:
V_8 -> V_35 = V_36 ;
if ( F_31 ( V_2 ) && V_8 -> type == V_53 )
V_2 -> V_54 -- ;
F_32 ( V_2 , 0 ) ;
}
switch ( V_8 -> V_35 ) {
case V_55 :
if ( V_50 -- == 0 ) {
F_33 ( V_2 , L_3 ) ;
if ( F_31 ( V_2 ) ) {
F_33 ( V_2 , L_4 ) ;
V_2 -> V_56 = V_8 ;
V_2 -> V_57 = 2 ;
}
goto V_52;
}
F_25 ( & V_2 -> V_30 , V_13 ) ;
F_34 ( 1 ) ;
goto V_51;
case V_36 :
if ( F_35 ( & V_8 -> V_58 ) ) {
F_36 ( V_2 , V_8 -> V_59 ) ;
F_37 ( V_2 , V_8 ) ;
break;
}
default:
F_38 ( V_2 , L_5 ,
V_8 , V_16 -> V_60 . V_61 , V_8 -> V_35 ,
F_35 ( & V_8 -> V_58 ) ? L_6 : L_7 ) ;
F_36 ( V_2 , V_8 -> V_59 ) ;
break;
}
V_16 -> V_45 = NULL ;
F_25 ( & V_2 -> V_30 , V_13 ) ;
}
static int F_39 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = F_3 ( V_5 ) ;
return F_19 ( V_2 ) ;
}
static void F_40 ( struct V_1 * V_2 )
{
V_2 -> V_62 = F_41 ( V_2 , & V_2 -> V_63 -> V_64 ) ;
V_2 -> V_62 &= V_65 ;
F_42 ( V_2 , V_2 -> V_62 , & V_2 -> V_63 -> V_64 ) ;
V_2 -> V_33 = V_66 ;
}
static void
F_43 ( struct V_4 * V_5 )
{
struct V_1 * V_2 ;
V_2 = F_3 ( V_5 ) ;
F_42 ( V_2 , ( V_67 ) ~ 0 , & V_2 -> V_63 -> V_68 ) ;
F_42 ( V_2 , V_69 , & V_2 -> V_63 -> V_70 ) ;
F_41 ( V_2 , & V_2 -> V_63 -> V_70 ) ;
F_44 ( 10 ) ;
F_42 ( V_2 , V_2 -> V_71 , & V_2 -> V_63 -> V_71 ) ;
}
static int F_45 ( struct V_1 * V_2 , struct V_8 * V_8 )
{
return ( F_46 ( V_2 , V_8 -> V_72 ) & V_73 ) != 0
&& ( F_46 ( V_2 , V_8 -> V_74 ) & V_75 )
== ( F_46 ( V_2 , V_8 -> V_76 ) & V_75 )
&& ! F_35 ( & V_8 -> V_58 ) ;
}
static void F_47 ( unsigned long V_77 )
{
unsigned long V_13 ;
unsigned V_78 ;
unsigned V_79 = 0 ;
unsigned V_11 ;
struct V_8 * * V_80 = NULL ;
struct V_1 * V_2 = (struct V_1 * ) V_77 ;
F_14 ( & V_2 -> V_30 , V_13 ) ;
V_78 = V_2 -> V_54 ;
if ( ! V_78 )
goto V_81;
if ( V_2 -> V_56 )
goto V_82;
V_80 = F_48 ( V_78 , sizeof *V_80 , V_83 ) ;
if ( ! V_80 )
goto V_82;
for ( V_11 = 0 ; V_11 < V_84 ; V_11 ++ ) {
struct V_8 * V_8 = V_2 -> V_85 [ V_11 ] ;
while ( V_8 ) {
unsigned V_86 ;
for ( V_86 = 0 ; V_86 < V_79 ; V_86 ++ ) {
if ( V_80 [ V_86 ] == V_8 ) {
V_8 = NULL ;
break;
}
}
if ( ! V_8 )
break;
V_80 [ V_79 ++ ] = V_8 ;
if ( ! F_45 ( V_2 , V_8 ) ) {
V_8 = V_8 -> V_87 ;
continue;
}
V_2 -> V_56 = V_8 ;
V_2 -> V_57 = 2 ;
F_42 ( V_2 , V_88 ,
& V_2 -> V_63 -> V_89 ) ;
F_42 ( V_2 , V_88 ,
& V_2 -> V_63 -> V_90 ) ;
( void ) F_41 ( V_2 , & V_2 -> V_63 -> V_64 ) ;
goto V_82;
}
}
V_82:
F_49 ( V_80 ) ;
if ( V_2 -> V_54 )
F_50 ( & V_2 -> V_91 , F_51 ( V_92 + V_93 ) ) ;
V_81:
F_25 ( & V_2 -> V_30 , V_13 ) ;
}
static int F_52 ( struct V_1 * V_2 )
{
int V_94 ;
struct V_4 * V_5 = F_53 ( V_2 ) ;
if ( V_95 )
V_2 -> V_13 |= V_96 ;
V_2 -> V_33 = V_66 ;
V_2 -> V_63 = V_5 -> V_63 ;
#ifndef F_54
if ( ! V_97 && F_41 ( V_2 ,
& V_2 -> V_63 -> V_64 ) & V_98 ) {
V_67 V_86 ;
F_55 ( V_2 , L_8 ) ;
V_86 = 500 ;
F_42 ( V_2 , V_99 , & V_2 -> V_63 -> V_90 ) ;
F_42 ( V_2 , V_100 , & V_2 -> V_63 -> V_70 ) ;
while ( F_41 ( V_2 , & V_2 -> V_63 -> V_64 ) & V_98 ) {
F_56 ( 10 ) ;
if ( -- V_86 == 0 ) {
F_38 ( V_2 , L_9
L_10 ) ;
return - V_101 ;
}
}
F_40 ( V_2 ) ;
}
#endif
F_42 ( V_2 , V_102 , & V_2 -> V_63 -> V_68 ) ;
if ( F_41 ( V_2 , & V_2 -> V_63 -> V_64 ) & V_65 )
V_2 -> V_62 |= V_65 ;
if ( V_2 -> V_103 == 0 )
V_2 -> V_103 = F_57 ( V_2 ) & V_104 ;
if ( V_2 -> V_105 )
return 0 ;
V_2 -> V_105 = F_58 ( V_5 -> V_106 . V_107 ,
sizeof * V_2 -> V_105 , & V_2 -> V_108 , 0 ) ;
if ( ! V_2 -> V_105 )
return - V_19 ;
if ( ( V_94 = F_59 ( V_2 ) ) < 0 )
F_60 ( V_5 ) ;
else {
F_61 ( V_2 ) ;
}
return V_94 ;
}
static int F_62 ( struct V_1 * V_2 )
{
V_67 V_109 , V_110 ;
int V_111 = V_2 -> V_71 == 0 ;
struct V_4 * V_5 = F_53 ( V_2 ) ;
V_2 -> V_33 = V_66 ;
if ( V_111 ) {
V_110 = F_41 ( V_2 , & V_2 -> V_63 -> V_71 ) ;
V_2 -> V_71 = V_110 & 0x3fff ;
if ( V_2 -> V_71 != V_112 )
F_55 ( V_2 , L_11 ,
V_2 -> V_71 - V_112 ) ;
V_2 -> V_71 |= F_63 ( V_2 -> V_71 ) << 16 ;
}
if ( ( V_2 -> V_62 & V_65 ) != 0 )
F_64 ( V_5 -> V_106 . V_107 , 1 ) ;
switch ( V_2 -> V_62 & V_113 ) {
case V_114 :
V_110 = 0 ;
break;
case V_115 :
case V_116 :
V_2 -> V_62 &= V_65 ;
V_2 -> V_62 |= V_116 ;
V_110 = 10 ;
break;
default:
V_2 -> V_62 &= V_65 ;
V_2 -> V_62 |= V_117 ;
V_110 = 50 ;
break;
}
F_42 ( V_2 , V_2 -> V_62 , & V_2 -> V_63 -> V_64 ) ;
( void ) F_41 ( V_2 , & V_2 -> V_63 -> V_64 ) ;
F_56 ( V_110 ) ;
memset ( V_2 -> V_105 , 0 , sizeof ( struct V_118 ) ) ;
F_65 ( & V_2 -> V_30 ) ;
V_119:
F_42 ( V_2 , V_69 , & V_2 -> V_63 -> V_70 ) ;
V_110 = 30 ;
while ( ( F_41 ( V_2 , & V_2 -> V_63 -> V_70 ) & V_69 ) != 0 ) {
if ( -- V_110 == 0 ) {
F_66 ( & V_2 -> V_30 ) ;
F_38 ( V_2 , L_12 ) ;
return - 1 ;
}
F_44 ( 1 ) ;
}
if ( V_2 -> V_13 & V_120 ) {
F_42 ( V_2 , V_2 -> V_62 , & V_2 -> V_63 -> V_64 ) ;
( void ) F_41 ( V_2 , & V_2 -> V_63 -> V_64 ) ;
}
F_42 ( V_2 , 0 , & V_2 -> V_63 -> V_121 ) ;
F_42 ( V_2 , 0 , & V_2 -> V_63 -> V_122 ) ;
F_42 ( V_2 , ( V_67 ) V_2 -> V_108 , & V_2 -> V_63 -> V_105 ) ;
F_67 ( V_2 ) ;
if ( ( F_41 ( V_2 , & V_2 -> V_63 -> V_71 ) & 0x3fff0000 ) == 0
|| ! F_41 ( V_2 , & V_2 -> V_63 -> V_123 ) ) {
if ( ! ( V_2 -> V_13 & V_120 ) ) {
V_2 -> V_13 |= V_120 ;
F_55 ( V_2 , L_13 ) ;
goto V_119;
}
F_66 ( & V_2 -> V_30 ) ;
F_38 ( V_2 , L_14 ,
F_41 ( V_2 , & V_2 -> V_63 -> V_71 ) ,
F_41 ( V_2 , & V_2 -> V_63 -> V_123 ) ) ;
return - V_124 ;
}
F_68 ( V_125 , & V_5 -> V_13 ) ;
V_5 -> V_126 = 1 ;
V_2 -> V_62 &= V_65 ;
V_2 -> V_62 |= V_127 | V_114 ;
F_42 ( V_2 , V_2 -> V_62 , & V_2 -> V_63 -> V_64 ) ;
V_2 -> V_33 = V_34 ;
F_42 ( V_2 , V_128 , & V_2 -> V_63 -> V_129 . V_46 ) ;
V_109 = V_130 ;
F_42 ( V_2 , ~ 0 , & V_2 -> V_63 -> V_89 ) ;
F_42 ( V_2 , V_109 , & V_2 -> V_63 -> V_90 ) ;
V_110 = F_57 ( V_2 ) ;
V_110 &= ~ ( V_131 | V_132 ) ;
if ( V_2 -> V_13 & V_133 ) {
V_110 |= V_134 ;
V_110 &= ~ ( V_135 | V_136 ) ;
F_42 ( V_2 , V_110 , & V_2 -> V_63 -> V_129 . V_137 ) ;
} else if ( ( V_2 -> V_13 & V_138 ) ||
( V_2 -> V_13 & V_96 ) ) {
V_110 |= V_136 ;
F_42 ( V_2 , V_110 , & V_2 -> V_63 -> V_129 . V_137 ) ;
}
F_42 ( V_2 , V_139 , & V_2 -> V_63 -> V_129 . V_46 ) ;
F_42 ( V_2 , ( V_110 & V_136 ) ? 0 : V_140 ,
& V_2 -> V_63 -> V_129 . V_141 ) ;
( void ) F_41 ( V_2 , & V_2 -> V_63 -> V_64 ) ;
V_2 -> V_142 = V_92 + V_143 ;
F_66 ( & V_2 -> V_30 ) ;
F_69 ( ( V_110 >> 23 ) & 0x1fe ) ;
if ( F_31 ( V_2 ) ) {
F_70 ( & V_2 -> V_91 , F_47 ,
( unsigned long ) V_2 ) ;
V_2 -> V_54 = 0 ;
V_2 -> V_56 = NULL ;
}
F_71 ( V_2 , 1 ) ;
return 0 ;
}
static T_4 F_72 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = F_3 ( V_5 ) ;
struct V_144 T_5 * V_63 = V_2 -> V_63 ;
int V_145 ;
V_145 = F_41 ( V_2 , & V_63 -> V_89 ) ;
if ( V_145 == ~ ( V_67 ) 0 ) {
V_2 -> V_33 = V_66 ;
F_55 ( V_2 , L_15 ) ;
F_73 ( V_5 ) ;
return V_146 ;
}
V_145 &= F_41 ( V_2 , & V_63 -> V_90 ) ;
if ( V_145 == 0 || F_21 ( V_2 -> V_33 == V_66 ) )
return V_147 ;
if ( V_145 & V_148 ) {
if ( F_74 ( V_2 ) ) {
F_38 ( V_2 , L_16 ) ;
F_42 ( V_2 , V_148 , & V_63 -> V_68 ) ;
F_75 ( & V_2 -> V_149 ) ;
} else {
F_38 ( V_2 , L_17 ) ;
V_2 -> V_33 = V_66 ;
F_73 ( V_5 ) ;
}
F_71 ( V_2 , 1 ) ;
F_40 ( V_2 ) ;
}
if ( V_145 & V_150 ) {
F_76 ( V_2 , L_18 ) ;
V_2 -> V_142 = V_92 + V_143 ;
F_42 ( V_2 , V_151 | V_150 ,
& V_63 -> V_89 ) ;
F_42 ( V_2 , V_150 , & V_63 -> V_68 ) ;
F_77 ( V_5 ) ;
}
else if ( V_145 & V_151 ) {
F_76 ( V_2 , L_19 ) ;
F_42 ( V_2 , V_151 , & V_63 -> V_89 ) ;
F_68 ( V_125 , & V_5 -> V_13 ) ;
if ( V_2 -> V_152 ) {
F_78 ( & V_2 -> V_30 ) ;
F_79 ( V_2 ) ;
F_80 ( & V_2 -> V_30 ) ;
} else
F_81 ( V_5 ) ;
}
if ( V_145 & V_153 ) {
F_78 ( & V_2 -> V_30 ) ;
F_82 ( V_2 ) ;
F_80 ( & V_2 -> V_30 ) ;
}
if ( F_31 ( V_2 ) && ( V_145 & V_88 ) ) {
F_78 ( & V_2 -> V_30 ) ;
if ( V_2 -> V_56 ) {
struct V_8 * V_8 = V_2 -> V_56 ;
if ( F_45 ( V_2 , V_8 ) ) {
if ( -- V_2 -> V_57 == 0 ) {
struct V_27 * V_27 = F_83 (
V_8 -> V_58 . V_40 ,
struct V_27 , V_58 ) ;
F_33 ( V_2 ,
L_20 ,
V_27 ) ;
F_84 ( V_2 , V_27 ) ;
V_2 -> V_56 = NULL ;
}
} else
V_2 -> V_56 = NULL ;
}
F_80 ( & V_2 -> V_30 ) ;
}
F_78 ( & V_2 -> V_30 ) ;
if ( V_2 -> V_154 )
F_32 ( V_2 , F_19 ( V_2 ) ) ;
if ( ( V_145 & V_88 ) != 0
&& ! V_2 -> V_154
&& ! V_2 -> V_56
&& V_2 -> V_33 == V_34 )
F_42 ( V_2 , V_88 , & V_63 -> V_68 ) ;
F_80 ( & V_2 -> V_30 ) ;
if ( V_2 -> V_33 == V_34 ) {
F_42 ( V_2 , V_145 , & V_63 -> V_89 ) ;
F_42 ( V_2 , V_102 , & V_63 -> V_90 ) ;
( void ) F_41 ( V_2 , & V_2 -> V_63 -> V_64 ) ;
}
return V_146 ;
}
static void F_60 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = F_3 ( V_5 ) ;
F_71 ( V_2 , 1 ) ;
if ( F_74 ( V_2 ) )
F_85 ( & V_2 -> V_149 ) ;
F_40 ( V_2 ) ;
F_42 ( V_2 , V_102 , & V_2 -> V_63 -> V_68 ) ;
F_86 ( V_5 -> V_155 , V_5 ) ;
V_5 -> V_155 = 0 ;
if ( F_31 ( V_2 ) )
F_87 ( & V_2 -> V_91 ) ;
if ( F_88 ( V_2 ) )
F_89 () ;
F_90 ( V_2 ) ;
F_91 ( V_2 ) ;
if ( V_2 -> V_105 ) {
F_92 ( V_5 -> V_106 . V_107 ,
sizeof * V_2 -> V_105 ,
V_2 -> V_105 , V_2 -> V_108 ) ;
V_2 -> V_105 = NULL ;
V_2 -> V_108 = 0 ;
}
}
static int F_93 ( struct V_1 * V_2 )
{
int V_86 ;
int V_11 ;
struct V_9 * V_156 ;
F_65 ( & V_2 -> V_30 ) ;
V_2 -> V_33 = V_66 ;
if ( ! F_35 ( & V_2 -> V_28 ) )
F_55 ( V_2 , L_21 ) ;
F_94 (priv, &ohci->pending, pending) {
struct V_6 * V_6 = V_156 -> V_27 [ 0 ] -> V_6 ;
struct V_8 * V_8 = V_156 -> V_8 ;
switch ( V_8 -> V_35 ) {
case V_48 :
V_8 -> V_35 = V_55 ;
V_8 -> V_72 |= F_95 ( V_2 , V_157 ) ;
F_96 ( V_2 , V_8 ) ;
V_8 -> V_87 = V_2 -> V_154 ;
V_8 -> V_158 = NULL ;
V_2 -> V_154 = V_8 ;
case V_55 :
break;
default:
F_55 ( V_2 , L_22 ,
V_8 , V_8 -> V_35 ) ;
}
if ( ! V_6 -> V_159 )
V_6 -> V_159 = - V_160 ;
}
F_32 ( V_2 , 0 ) ;
F_66 ( & V_2 -> V_30 ) ;
for ( V_11 = 0 ; V_11 < V_84 ; V_11 ++ ) V_2 -> V_161 [ V_11 ] = 0 ;
for ( V_11 = 0 ; V_11 < V_84 ; V_11 ++ ) V_2 -> V_105 -> V_162 [ V_11 ] = 0 ;
V_2 -> V_154 = NULL ;
V_2 -> V_163 = NULL ;
V_2 -> V_164 = NULL ;
if ( ( V_86 = F_62 ( V_2 ) ) < 0 ) {
F_38 ( V_2 , L_23 , V_86 ) ;
return V_86 ;
}
F_55 ( V_2 , L_24 ) ;
return 0 ;
}
static int T_6 F_97 ( struct V_4 * V_5 , bool V_165 )
{
struct V_1 * V_2 = F_3 ( V_5 ) ;
unsigned long V_13 ;
F_14 ( & V_2 -> V_30 , V_13 ) ;
F_42 ( V_2 , V_102 , & V_2 -> V_63 -> V_68 ) ;
( void ) F_41 ( V_2 , & V_2 -> V_63 -> V_68 ) ;
F_98 ( V_166 , & V_5 -> V_13 ) ;
F_25 ( & V_2 -> V_30 , V_13 ) ;
return 0 ;
}
static int T_6 F_99 ( struct V_4 * V_5 , bool V_167 )
{
struct V_1 * V_2 = F_3 ( V_5 ) ;
int V_168 ;
bool V_169 = false ;
F_68 ( V_166 , & V_5 -> V_13 ) ;
if ( V_167 )
F_40 ( V_2 ) ;
V_2 -> V_62 = F_41 ( V_2 , & V_2 -> V_63 -> V_64 ) ;
if ( V_2 -> V_62 & ( V_98 | V_170 ) ) {
V_169 = true ;
} else {
switch ( V_2 -> V_62 & V_113 ) {
case V_114 :
case V_117 :
V_169 = true ;
}
}
if ( V_169 ) {
F_65 ( & V_2 -> V_30 ) ;
F_79 ( V_2 ) ;
F_100 ( V_2 , 0 ) ;
F_66 ( & V_2 -> V_30 ) ;
}
else {
F_55 ( V_2 , L_25 ) ;
for ( V_168 = 0 ; V_168 < V_2 -> V_103 ; V_168 ++ )
F_42 ( V_2 , V_171 ,
& V_2 -> V_63 -> V_129 . V_172 [ V_168 ] ) ;
F_42 ( V_2 , V_102 , & V_2 -> V_63 -> V_90 ) ;
F_41 ( V_2 , & V_2 -> V_63 -> V_90 ) ;
F_56 ( 20 ) ;
}
F_81 ( V_5 ) ;
return 0 ;
}
static int T_7 F_101 ( void )
{
int V_14 = 0 ;
if ( F_102 () )
return - V_31 ;
F_103 ( V_173 L_26 V_174 L_27 , V_175 ) ;
F_104 ( L_28 , V_175 ,
sizeof ( struct V_8 ) , sizeof ( struct V_27 ) ) ;
F_68 ( V_176 , & V_177 ) ;
#ifdef F_105
V_178 = F_106 ( L_29 , V_179 ) ;
if ( ! V_178 ) {
V_14 = - V_180 ;
goto V_181;
}
#endif
#ifdef F_107
V_14 = F_108 ( & F_107 ) ;
if ( V_14 < 0 )
goto V_182;
#endif
#ifdef F_109
V_14 = F_110 ( & F_109 ) ;
if ( V_14 < 0 )
goto V_183;
#endif
#ifdef F_111
V_14 = F_110 ( & F_111 ) ;
if ( V_14 < 0 )
goto V_184;
#endif
#ifdef F_112
V_14 = F_110 ( & F_112 ) ;
if ( V_14 < 0 )
goto V_185;
#endif
#ifdef F_113
V_14 = F_110 ( & F_113 ) ;
if ( V_14 < 0 )
goto V_186;
#endif
#ifdef F_114
V_14 = F_115 ( & F_114 ) ;
if ( V_14 < 0 )
goto V_187;
#endif
#ifdef F_116
V_14 = F_117 ( & F_116 ) ;
if ( V_14 < 0 )
goto V_188;
#endif
#ifdef F_118
V_14 = F_110 ( & F_118 ) ;
if ( V_14 < 0 )
goto V_189;
#endif
#ifdef F_119
V_14 = F_110 ( & F_119 ) ;
if ( V_14 < 0 )
goto V_190;
#endif
#ifdef F_120
V_14 = F_110 ( & F_120 ) ;
if ( V_14 < 0 )
goto V_191;
#endif
#ifdef F_121
V_14 = F_110 ( & F_121 ) ;
if ( V_14 < 0 )
goto V_192;
#endif
#ifdef F_122
V_14 = F_110 ( & F_122 ) ;
if ( V_14 < 0 )
goto V_193;
#endif
#ifdef F_123
V_14 = F_110 ( & F_123 ) ;
if ( V_14 < 0 )
goto V_194;
#endif
#ifdef F_124
V_14 = F_110 ( & F_124 ) ;
if ( V_14 < 0 )
goto V_195;
#endif
#ifdef F_125
V_14 = F_110 ( & F_125 ) ;
if ( V_14 < 0 )
goto V_196;
#endif
#ifdef F_126
V_14 = F_110 ( & F_126 ) ;
if ( V_14 < 0 )
goto V_197;
#endif
return V_14 ;
#ifdef F_126
F_127 ( & F_126 ) ;
V_197:
#endif
#ifdef F_125
F_127 ( & F_125 ) ;
V_196:
#endif
#ifdef F_124
F_127 ( & F_124 ) ;
V_195:
#endif
#ifdef F_123
F_127 ( & F_123 ) ;
V_194:
#endif
#ifdef F_122
F_127 ( & F_122 ) ;
V_193:
#endif
#ifdef F_121
F_127 ( & F_121 ) ;
V_192:
#endif
#ifdef F_120
F_127 ( & F_120 ) ;
V_191:
#endif
#ifdef F_119
F_127 ( & F_119 ) ;
V_190:
#endif
#ifdef F_118
F_127 ( & F_118 ) ;
V_189:
#endif
#ifdef F_116
F_128 ( & F_116 ) ;
V_188:
#endif
#ifdef F_114
F_129 ( & F_114 ) ;
V_187:
#endif
#ifdef F_113
F_127 ( & F_113 ) ;
V_186:
#endif
#ifdef F_112
F_127 ( & F_112 ) ;
V_185:
#endif
#ifdef F_111
F_127 ( & F_111 ) ;
V_184:
#endif
#ifdef F_109
F_127 ( & F_109 ) ;
V_183:
#endif
#ifdef F_107
F_130 ( & F_107 ) ;
V_182:
#endif
#ifdef F_105
F_131 ( V_178 ) ;
V_178 = NULL ;
V_181:
#endif
F_98 ( V_176 , & V_177 ) ;
return V_14 ;
}
static void T_8 F_132 ( void )
{
#ifdef F_126
F_127 ( & F_126 ) ;
#endif
#ifdef F_125
F_127 ( & F_125 ) ;
#endif
#ifdef F_124
F_127 ( & F_124 ) ;
#endif
#ifdef F_123
F_127 ( & F_123 ) ;
#endif
#ifdef F_122
F_127 ( & F_122 ) ;
#endif
#ifdef F_121
F_127 ( & F_121 ) ;
#endif
#ifdef F_120
F_127 ( & F_120 ) ;
#endif
#ifdef F_119
F_127 ( & F_119 ) ;
#endif
#ifdef F_118
F_127 ( & F_118 ) ;
#endif
#ifdef F_116
F_128 ( & F_116 ) ;
#endif
#ifdef F_114
F_129 ( & F_114 ) ;
#endif
#ifdef F_113
F_127 ( & F_113 ) ;
#endif
#ifdef F_112
F_127 ( & F_112 ) ;
#endif
#ifdef F_111
F_127 ( & F_111 ) ;
#endif
#ifdef F_109
F_127 ( & F_109 ) ;
#endif
#ifdef F_107
F_130 ( & F_107 ) ;
#endif
#ifdef F_105
F_131 ( V_178 ) ;
#endif
F_98 ( V_176 , & V_177 ) ;
}
