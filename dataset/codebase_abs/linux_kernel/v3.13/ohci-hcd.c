static int F_1 (
struct V_1 * V_2 ,
struct V_3 * V_3 ,
T_1 V_4
) {
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_7 ;
T_2 * V_8 ;
unsigned int V_9 = V_3 -> V_9 ;
int V_10 , V_11 = 0 ;
unsigned long V_12 ;
int V_13 = 0 ;
#ifdef F_3
F_4 ( V_3 , L_1 , F_5 ( V_9 ) , - V_14 ) ;
#endif
if ( ! ( V_7 = F_6 ( V_6 , V_3 -> V_15 , V_3 -> V_16 , V_9 , V_3 -> V_17 ) ) )
return - V_18 ;
switch ( V_7 -> type ) {
case V_19 :
if ( V_3 -> V_20 > 4096 )
return - V_21 ;
V_11 = 2 ;
default:
V_11 += V_3 -> V_20 / 4096 ;
if ( ( V_3 -> V_20 % 4096 ) != 0 )
V_11 ++ ;
if ( V_11 == 0 )
V_11 ++ ;
else if ( ( V_3 -> V_22 & V_23 ) != 0
&& ( V_3 -> V_20
% F_7 ( V_3 -> V_16 , V_9 ,
F_8 ( V_9 ) ) ) == 0 )
V_11 ++ ;
break;
case V_24 :
V_11 = V_3 -> V_25 ;
break;
}
V_8 = F_9 ( sizeof ( T_2 ) + V_11 * sizeof ( struct V_26 * ) ,
V_4 ) ;
if ( ! V_8 )
return - V_18 ;
F_10 ( & V_8 -> V_27 ) ;
V_8 -> V_28 = V_11 ;
V_8 -> V_7 = V_7 ;
for ( V_10 = 0 ; V_10 < V_11 ; V_10 ++ ) {
V_8 -> V_26 [ V_10 ] = F_11 ( V_6 , V_4 ) ;
if ( ! V_8 -> V_26 [ V_10 ] ) {
V_8 -> V_28 = V_10 ;
F_12 ( V_6 , V_8 ) ;
return - V_18 ;
}
}
F_13 ( & V_6 -> V_29 , V_12 ) ;
if ( ! F_14 ( V_2 ) ) {
V_13 = - V_30 ;
goto V_31;
}
if ( V_6 -> V_32 != V_33 ) {
V_13 = - V_30 ;
goto V_31;
}
V_13 = F_15 ( V_2 , V_3 ) ;
if ( V_13 )
goto V_31;
if ( V_7 -> V_34 == V_35 ) {
V_13 = F_16 ( V_6 , V_7 ) ;
if ( V_13 < 0 ) {
F_17 ( V_2 , V_3 ) ;
goto V_31;
}
if ( V_7 -> type == V_24 ) {
T_3 V_36 = F_18 ( V_6 ) ;
V_36 += F_19 ( T_3 , 8 , V_7 -> V_17 ) ;
V_36 &= ~ ( V_7 -> V_17 - 1 ) ;
V_36 |= V_7 -> V_37 ;
V_3 -> V_38 = V_36 ;
V_7 -> V_39 = V_36 + V_7 -> V_17 * ( V_11 - 1 ) ;
}
} else if ( V_7 -> type == V_24 ) {
T_3 V_40 = F_18 ( V_6 ) + 1 ;
T_3 V_36 = V_7 -> V_39 + V_7 -> V_17 ;
T_3 V_28 = V_7 -> V_17 * ( V_11 - 1 ) ;
if ( F_20 ( F_21 ( V_36 , V_40 ) ) ) {
if ( V_3 -> V_22 & V_41 ) {
V_36 += ( V_40 - V_36 + V_7 -> V_17 - 1 ) &
- V_7 -> V_17 ;
} else {
V_8 -> V_42 = F_22 (
( T_3 ) ( V_40 - V_36 ) ,
V_7 -> V_17 ) ;
if ( V_8 -> V_42 >= V_8 -> V_28 ) {
++ V_8 -> V_42 ;
F_23 ( V_6 , L_2 ,
V_3 , V_36 , V_28 ,
V_40 ) ;
}
}
}
V_3 -> V_38 = V_36 ;
V_7 -> V_39 = V_36 + V_28 ;
}
V_3 -> V_43 = V_8 ;
F_24 ( V_6 , V_3 ) ;
V_31:
if ( V_13 )
F_12 ( V_6 , V_8 ) ;
F_25 ( & V_6 -> V_29 , V_12 ) ;
return V_13 ;
}
static int F_26 ( struct V_1 * V_2 , struct V_3 * V_3 , int V_44 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned long V_12 ;
int V_45 ;
#ifdef F_3
F_4 ( V_3 , L_3 , 1 , V_44 ) ;
#endif
F_13 ( & V_6 -> V_29 , V_12 ) ;
V_45 = F_27 ( V_2 , V_3 , V_44 ) ;
if ( V_45 ) {
;
} else if ( V_6 -> V_32 == V_33 ) {
T_2 * V_8 ;
V_8 = V_3 -> V_43 ;
if ( V_8 ) {
if ( V_8 -> V_7 -> V_34 == V_46 )
F_28 ( V_6 , V_8 -> V_7 ) ;
}
} else {
if ( V_3 -> V_43 )
F_29 ( V_6 , V_3 , V_44 ) ;
}
F_25 ( & V_6 -> V_29 , V_12 ) ;
return V_45 ;
}
static void
F_30 ( struct V_1 * V_2 , struct V_47 * V_15 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned long V_12 ;
struct V_7 * V_7 = V_15 -> V_43 ;
unsigned V_48 = 1000 ;
if ( ! V_7 )
return;
V_49:
F_13 ( & V_6 -> V_29 , V_12 ) ;
if ( V_6 -> V_32 != V_33 ) {
V_50:
V_7 -> V_34 = V_35 ;
if ( F_31 ( V_6 ) && V_7 -> type == V_51 )
V_6 -> V_52 -- ;
F_32 ( V_6 , 0 ) ;
}
switch ( V_7 -> V_34 ) {
case V_53 :
if ( V_48 -- == 0 ) {
F_33 ( V_6 , L_4 ) ;
if ( F_31 ( V_6 ) ) {
F_33 ( V_6 , L_5 ) ;
V_6 -> V_54 = V_7 ;
V_6 -> V_55 = 2 ;
}
goto V_50;
}
F_25 ( & V_6 -> V_29 , V_12 ) ;
F_34 ( 1 ) ;
goto V_49;
case V_35 :
if ( F_35 ( & V_7 -> V_56 ) ) {
F_36 ( V_6 , V_7 -> V_57 ) ;
F_37 ( V_6 , V_7 ) ;
break;
}
default:
F_38 ( V_6 , L_6 ,
V_7 , V_15 -> V_58 . V_59 , V_7 -> V_34 ,
F_35 ( & V_7 -> V_56 ) ? L_7 : L_8 ) ;
F_36 ( V_6 , V_7 -> V_57 ) ;
break;
}
V_15 -> V_43 = NULL ;
F_25 ( & V_6 -> V_29 , V_12 ) ;
}
static int F_39 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return F_18 ( V_6 ) ;
}
static void F_40 ( struct V_5 * V_6 )
{
V_6 -> V_60 = F_41 ( V_6 , & V_6 -> V_61 -> V_62 ) ;
V_6 -> V_60 &= V_63 ;
F_42 ( V_6 , V_6 -> V_60 , & V_6 -> V_61 -> V_62 ) ;
V_6 -> V_32 = V_64 ;
}
static void
F_43 ( struct V_1 * V_2 )
{
struct V_5 * V_6 ;
V_6 = F_2 ( V_2 ) ;
F_42 ( V_6 , ( V_65 ) ~ 0 , & V_6 -> V_61 -> V_66 ) ;
F_42 ( V_6 , V_67 , & V_6 -> V_61 -> V_68 ) ;
F_41 ( V_6 , & V_6 -> V_61 -> V_68 ) ;
F_44 ( 10 ) ;
F_42 ( V_6 , V_6 -> V_69 , & V_6 -> V_61 -> V_69 ) ;
}
static int F_45 ( struct V_5 * V_6 , struct V_7 * V_7 )
{
return ( F_46 ( V_6 , V_7 -> V_70 ) & V_71 ) != 0
&& ( F_46 ( V_6 , V_7 -> V_72 ) & V_73 )
== ( F_46 ( V_6 , V_7 -> V_74 ) & V_73 )
&& ! F_35 ( & V_7 -> V_56 ) ;
}
static void F_47 ( unsigned long V_75 )
{
unsigned long V_12 ;
unsigned V_76 ;
unsigned V_77 = 0 ;
unsigned V_10 ;
struct V_7 * * V_78 = NULL ;
struct V_5 * V_6 = (struct V_5 * ) V_75 ;
F_13 ( & V_6 -> V_29 , V_12 ) ;
V_76 = V_6 -> V_52 ;
if ( ! V_76 )
goto V_79;
if ( V_6 -> V_54 )
goto V_80;
V_78 = F_48 ( V_76 , sizeof *V_78 , V_81 ) ;
if ( ! V_78 )
goto V_80;
for ( V_10 = 0 ; V_10 < V_82 ; V_10 ++ ) {
struct V_7 * V_7 = V_6 -> V_83 [ V_10 ] ;
while ( V_7 ) {
unsigned V_84 ;
for ( V_84 = 0 ; V_84 < V_77 ; V_84 ++ ) {
if ( V_78 [ V_84 ] == V_7 ) {
V_7 = NULL ;
break;
}
}
if ( ! V_7 )
break;
V_78 [ V_77 ++ ] = V_7 ;
if ( ! F_45 ( V_6 , V_7 ) ) {
V_7 = V_7 -> V_85 ;
continue;
}
V_6 -> V_54 = V_7 ;
V_6 -> V_55 = 2 ;
F_42 ( V_6 , V_86 ,
& V_6 -> V_61 -> V_87 ) ;
F_42 ( V_6 , V_86 ,
& V_6 -> V_61 -> V_88 ) ;
( void ) F_41 ( V_6 , & V_6 -> V_61 -> V_62 ) ;
goto V_80;
}
}
V_80:
F_49 ( V_78 ) ;
if ( V_6 -> V_52 )
F_50 ( & V_6 -> V_89 , F_51 ( V_90 + V_91 ) ) ;
V_79:
F_25 ( & V_6 -> V_29 , V_12 ) ;
}
static int F_52 ( struct V_5 * V_6 )
{
int V_92 ;
struct V_1 * V_2 = F_53 ( V_6 ) ;
if ( V_93 )
V_6 -> V_12 |= V_94 ;
V_6 -> V_32 = V_64 ;
V_6 -> V_61 = V_2 -> V_61 ;
#ifndef F_54
if ( ! V_95 && F_41 ( V_6 ,
& V_6 -> V_61 -> V_62 ) & V_96 ) {
V_65 V_84 ;
F_23 ( V_6 , L_9 ) ;
V_84 = 500 ;
F_42 ( V_6 , V_97 , & V_6 -> V_61 -> V_88 ) ;
F_42 ( V_6 , V_98 , & V_6 -> V_61 -> V_68 ) ;
while ( F_41 ( V_6 , & V_6 -> V_61 -> V_62 ) & V_96 ) {
F_55 ( 10 ) ;
if ( -- V_84 == 0 ) {
F_38 ( V_6 , L_10
L_11 ) ;
return - V_99 ;
}
}
F_40 ( V_6 ) ;
}
#endif
F_42 ( V_6 , V_100 , & V_6 -> V_61 -> V_66 ) ;
if ( F_41 ( V_6 , & V_6 -> V_61 -> V_62 ) & V_63 )
V_6 -> V_60 |= V_63 ;
if ( V_6 -> V_101 == 0 )
V_6 -> V_101 = F_56 ( V_6 ) & V_102 ;
if ( V_6 -> V_103 )
return 0 ;
V_6 -> V_103 = F_57 ( V_2 -> V_104 . V_105 ,
sizeof * V_6 -> V_103 , & V_6 -> V_106 , 0 ) ;
if ( ! V_6 -> V_103 )
return - V_18 ;
if ( ( V_92 = F_58 ( V_6 ) ) < 0 )
F_59 ( V_2 ) ;
else {
F_60 ( V_6 ) ;
}
return V_92 ;
}
static int F_61 ( struct V_5 * V_6 )
{
V_65 V_107 , V_108 ;
int V_109 = V_6 -> V_69 == 0 ;
struct V_1 * V_2 = F_53 ( V_6 ) ;
V_6 -> V_32 = V_64 ;
if ( V_109 ) {
V_108 = F_41 ( V_6 , & V_6 -> V_61 -> V_69 ) ;
V_6 -> V_69 = V_108 & 0x3fff ;
if ( V_6 -> V_69 != V_110 )
F_23 ( V_6 , L_12 ,
V_6 -> V_69 - V_110 ) ;
V_6 -> V_69 |= F_62 ( V_6 -> V_69 ) << 16 ;
}
if ( ( V_6 -> V_60 & V_63 ) != 0 )
F_63 ( V_2 -> V_104 . V_105 , 1 ) ;
switch ( V_6 -> V_60 & V_111 ) {
case V_112 :
V_108 = 0 ;
break;
case V_113 :
case V_114 :
V_6 -> V_60 &= V_63 ;
V_6 -> V_60 |= V_114 ;
V_108 = 10 ;
break;
default:
V_6 -> V_60 &= V_63 ;
V_6 -> V_60 |= V_115 ;
V_108 = 50 ;
break;
}
F_42 ( V_6 , V_6 -> V_60 , & V_6 -> V_61 -> V_62 ) ;
( void ) F_41 ( V_6 , & V_6 -> V_61 -> V_62 ) ;
F_55 ( V_108 ) ;
memset ( V_6 -> V_103 , 0 , sizeof ( struct V_116 ) ) ;
F_64 ( & V_6 -> V_29 ) ;
V_117:
F_42 ( V_6 , V_67 , & V_6 -> V_61 -> V_68 ) ;
V_108 = 30 ;
while ( ( F_41 ( V_6 , & V_6 -> V_61 -> V_68 ) & V_67 ) != 0 ) {
if ( -- V_108 == 0 ) {
F_65 ( & V_6 -> V_29 ) ;
F_38 ( V_6 , L_13 ) ;
return - 1 ;
}
F_44 ( 1 ) ;
}
if ( V_6 -> V_12 & V_118 ) {
F_42 ( V_6 , V_6 -> V_60 , & V_6 -> V_61 -> V_62 ) ;
( void ) F_41 ( V_6 , & V_6 -> V_61 -> V_62 ) ;
}
F_42 ( V_6 , 0 , & V_6 -> V_61 -> V_119 ) ;
F_42 ( V_6 , 0 , & V_6 -> V_61 -> V_120 ) ;
F_42 ( V_6 , ( V_65 ) V_6 -> V_106 , & V_6 -> V_61 -> V_103 ) ;
F_66 ( V_6 ) ;
if ( ( F_41 ( V_6 , & V_6 -> V_61 -> V_69 ) & 0x3fff0000 ) == 0
|| ! F_41 ( V_6 , & V_6 -> V_61 -> V_121 ) ) {
if ( ! ( V_6 -> V_12 & V_118 ) ) {
V_6 -> V_12 |= V_118 ;
F_23 ( V_6 , L_14 ) ;
goto V_117;
}
F_65 ( & V_6 -> V_29 ) ;
F_38 ( V_6 , L_15 ,
F_41 ( V_6 , & V_6 -> V_61 -> V_69 ) ,
F_41 ( V_6 , & V_6 -> V_61 -> V_121 ) ) ;
return - V_122 ;
}
F_67 ( V_123 , & V_2 -> V_12 ) ;
V_2 -> V_124 = 1 ;
V_6 -> V_60 &= V_63 ;
V_6 -> V_60 |= V_125 | V_112 ;
F_42 ( V_6 , V_6 -> V_60 , & V_6 -> V_61 -> V_62 ) ;
V_6 -> V_32 = V_33 ;
F_42 ( V_6 , V_126 , & V_6 -> V_61 -> V_127 . V_44 ) ;
V_107 = V_128 ;
F_42 ( V_6 , ~ 0 , & V_6 -> V_61 -> V_87 ) ;
F_42 ( V_6 , V_107 , & V_6 -> V_61 -> V_88 ) ;
V_108 = F_56 ( V_6 ) ;
V_108 &= ~ ( V_129 | V_130 ) ;
if ( V_6 -> V_12 & V_131 ) {
V_108 |= V_132 ;
V_108 &= ~ ( V_133 | V_134 ) ;
F_42 ( V_6 , V_108 , & V_6 -> V_61 -> V_127 . V_135 ) ;
} else if ( ( V_6 -> V_12 & V_136 ) ||
( V_6 -> V_12 & V_94 ) ) {
V_108 |= V_134 ;
F_42 ( V_6 , V_108 , & V_6 -> V_61 -> V_127 . V_135 ) ;
}
F_42 ( V_6 , V_137 , & V_6 -> V_61 -> V_127 . V_44 ) ;
F_42 ( V_6 , ( V_108 & V_134 ) ? 0 : V_138 ,
& V_6 -> V_61 -> V_127 . V_139 ) ;
( void ) F_41 ( V_6 , & V_6 -> V_61 -> V_62 ) ;
V_6 -> V_140 = V_90 + V_141 ;
F_65 ( & V_6 -> V_29 ) ;
F_68 ( ( V_108 >> 23 ) & 0x1fe ) ;
if ( F_31 ( V_6 ) ) {
F_69 ( & V_6 -> V_89 , F_47 ,
( unsigned long ) V_6 ) ;
V_6 -> V_52 = 0 ;
V_6 -> V_54 = NULL ;
}
F_70 ( V_6 , 1 ) ;
return 0 ;
}
int F_71 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_72 ( V_6 ) ;
return F_52 ( V_6 ) ;
}
static int F_73 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_92 ;
V_92 = F_61 ( V_6 ) ;
if ( V_92 < 0 ) {
F_38 ( V_6 , L_16 ) ;
F_59 ( V_2 ) ;
}
return V_92 ;
}
static T_4 F_74 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_142 T_5 * V_61 = V_6 -> V_61 ;
int V_143 ;
V_143 = F_41 ( V_6 , & V_61 -> V_87 ) ;
if ( V_143 == ~ ( V_65 ) 0 ) {
V_6 -> V_32 = V_64 ;
F_23 ( V_6 , L_17 ) ;
F_75 ( V_2 ) ;
return V_144 ;
}
V_143 &= F_41 ( V_6 , & V_61 -> V_88 ) ;
if ( V_143 == 0 || F_20 ( V_6 -> V_32 == V_64 ) )
return V_145 ;
if ( V_143 & V_146 ) {
if ( F_76 ( V_6 ) ) {
F_38 ( V_6 , L_18 ) ;
F_42 ( V_6 , V_146 , & V_61 -> V_66 ) ;
F_77 ( & V_6 -> V_147 ) ;
} else {
F_38 ( V_6 , L_19 ) ;
V_6 -> V_32 = V_64 ;
F_75 ( V_2 ) ;
}
F_70 ( V_6 , 1 ) ;
F_40 ( V_6 ) ;
}
if ( V_143 & V_148 ) {
F_78 ( V_6 , L_20 ) ;
V_6 -> V_140 = V_90 + V_141 ;
F_42 ( V_6 , V_149 | V_148 ,
& V_61 -> V_87 ) ;
F_42 ( V_6 , V_148 , & V_61 -> V_66 ) ;
F_79 ( V_2 ) ;
}
else if ( V_143 & V_149 ) {
F_78 ( V_6 , L_21 ) ;
F_42 ( V_6 , V_149 , & V_61 -> V_87 ) ;
F_67 ( V_123 , & V_2 -> V_12 ) ;
if ( V_6 -> V_150 ) {
F_80 ( & V_6 -> V_29 ) ;
F_81 ( V_6 ) ;
F_82 ( & V_6 -> V_29 ) ;
} else
F_83 ( V_2 ) ;
}
if ( V_143 & V_151 ) {
F_80 ( & V_6 -> V_29 ) ;
F_84 ( V_6 ) ;
F_82 ( & V_6 -> V_29 ) ;
}
if ( F_31 ( V_6 ) && ( V_143 & V_86 ) ) {
F_80 ( & V_6 -> V_29 ) ;
if ( V_6 -> V_54 ) {
struct V_7 * V_7 = V_6 -> V_54 ;
if ( F_45 ( V_6 , V_7 ) ) {
if ( -- V_6 -> V_55 == 0 ) {
struct V_26 * V_26 = F_85 (
V_7 -> V_56 . V_40 ,
struct V_26 , V_56 ) ;
F_33 ( V_6 ,
L_22 ,
V_26 ) ;
F_86 ( V_6 , V_26 ) ;
V_6 -> V_54 = NULL ;
}
} else
V_6 -> V_54 = NULL ;
}
F_82 ( & V_6 -> V_29 ) ;
}
F_80 ( & V_6 -> V_29 ) ;
if ( V_6 -> V_152 )
F_32 ( V_6 , F_18 ( V_6 ) ) ;
if ( ( V_143 & V_86 ) != 0
&& ! V_6 -> V_152
&& ! V_6 -> V_54
&& V_6 -> V_32 == V_33 )
F_42 ( V_6 , V_86 , & V_61 -> V_66 ) ;
F_82 ( & V_6 -> V_29 ) ;
if ( V_6 -> V_32 == V_33 ) {
F_42 ( V_6 , V_143 , & V_61 -> V_87 ) ;
F_42 ( V_6 , V_100 , & V_61 -> V_88 ) ;
( void ) F_41 ( V_6 , & V_6 -> V_61 -> V_62 ) ;
}
return V_144 ;
}
static void F_59 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_70 ( V_6 , 1 ) ;
if ( F_76 ( V_6 ) )
F_87 ( & V_6 -> V_147 ) ;
F_42 ( V_6 , V_100 , & V_6 -> V_61 -> V_66 ) ;
F_40 ( V_6 ) ;
F_88 ( V_2 -> V_153 , V_2 ) ;
V_2 -> V_153 = 0 ;
if ( F_31 ( V_6 ) )
F_89 ( & V_6 -> V_89 ) ;
if ( F_90 ( V_6 ) )
F_91 () ;
F_92 ( V_6 ) ;
F_93 ( V_6 ) ;
if ( V_6 -> V_103 ) {
F_94 ( V_2 -> V_104 . V_105 ,
sizeof * V_6 -> V_103 ,
V_6 -> V_103 , V_6 -> V_106 ) ;
V_6 -> V_103 = NULL ;
V_6 -> V_106 = 0 ;
}
}
int F_95 ( struct V_5 * V_6 )
{
int V_84 ;
int V_10 ;
struct V_8 * V_154 ;
F_52 ( V_6 ) ;
F_64 ( & V_6 -> V_29 ) ;
V_6 -> V_32 = V_64 ;
if ( ! F_35 ( & V_6 -> V_27 ) )
F_23 ( V_6 , L_23 ) ;
F_96 (priv, &ohci->pending, pending) {
struct V_3 * V_3 = V_154 -> V_26 [ 0 ] -> V_3 ;
struct V_7 * V_7 = V_154 -> V_7 ;
switch ( V_7 -> V_34 ) {
case V_46 :
V_7 -> V_34 = V_53 ;
V_7 -> V_70 |= F_97 ( V_6 , V_155 ) ;
F_98 ( V_6 , V_7 ) ;
V_7 -> V_85 = V_6 -> V_152 ;
V_7 -> V_156 = NULL ;
V_6 -> V_152 = V_7 ;
case V_53 :
break;
default:
F_23 ( V_6 , L_24 ,
V_7 , V_7 -> V_34 ) ;
}
if ( ! V_3 -> V_157 )
V_3 -> V_157 = - V_158 ;
}
F_32 ( V_6 , 0 ) ;
F_65 ( & V_6 -> V_29 ) ;
for ( V_10 = 0 ; V_10 < V_82 ; V_10 ++ ) V_6 -> V_159 [ V_10 ] = 0 ;
for ( V_10 = 0 ; V_10 < V_82 ; V_10 ++ ) V_6 -> V_103 -> V_160 [ V_10 ] = 0 ;
V_6 -> V_152 = NULL ;
V_6 -> V_161 = NULL ;
V_6 -> V_162 = NULL ;
if ( ( V_84 = F_61 ( V_6 ) ) < 0 ) {
F_38 ( V_6 , L_25 , V_84 ) ;
return V_84 ;
}
F_23 ( V_6 , L_26 ) ;
return 0 ;
}
int F_99 ( struct V_1 * V_2 , bool V_163 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned long V_12 ;
F_13 ( & V_6 -> V_29 , V_12 ) ;
F_42 ( V_6 , V_100 , & V_6 -> V_61 -> V_66 ) ;
( void ) F_41 ( V_6 , & V_6 -> V_61 -> V_66 ) ;
F_100 ( V_164 , & V_2 -> V_12 ) ;
F_25 ( & V_6 -> V_29 , V_12 ) ;
return 0 ;
}
int F_101 ( struct V_1 * V_2 , bool V_165 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_166 ;
bool V_167 = false ;
F_67 ( V_164 , & V_2 -> V_12 ) ;
if ( V_165 )
F_40 ( V_6 ) ;
V_6 -> V_60 = F_41 ( V_6 , & V_6 -> V_61 -> V_62 ) ;
if ( V_6 -> V_60 & ( V_96 | V_168 ) ) {
V_167 = true ;
} else {
switch ( V_6 -> V_60 & V_111 ) {
case V_112 :
case V_115 :
V_167 = true ;
}
}
if ( V_167 ) {
F_64 ( & V_6 -> V_29 ) ;
F_81 ( V_6 ) ;
F_102 ( V_6 , 0 ) ;
F_65 ( & V_6 -> V_29 ) ;
}
else {
F_23 ( V_6 , L_27 ) ;
for ( V_166 = 0 ; V_166 < V_6 -> V_101 ; V_166 ++ )
F_42 ( V_6 , V_169 ,
& V_6 -> V_61 -> V_127 . V_170 [ V_166 ] ) ;
F_42 ( V_6 , V_100 , & V_6 -> V_61 -> V_88 ) ;
F_41 ( V_6 , & V_6 -> V_61 -> V_88 ) ;
F_55 ( 20 ) ;
}
F_83 ( V_2 ) ;
return 0 ;
}
void F_103 ( struct V_171 * V_172 ,
const struct V_173 * V_174 )
{
* V_172 = V_175 ;
if ( V_174 ) {
V_172 -> V_176 = V_174 -> V_176 ;
V_172 -> V_177 += V_174 -> V_178 ;
if ( V_174 -> V_179 )
V_172 -> V_179 = V_174 -> V_179 ;
}
}
static int T_6 F_104 ( void )
{
int V_13 = 0 ;
if ( F_105 () )
return - V_30 ;
F_106 ( V_180 L_28 V_181 L_29 , V_182 ) ;
F_107 ( L_30 , V_182 ,
sizeof ( struct V_7 ) , sizeof ( struct V_26 ) ) ;
F_67 ( V_183 , & V_184 ) ;
#ifdef F_108
V_185 = F_109 ( L_31 , V_186 ) ;
if ( ! V_185 ) {
V_13 = - V_187 ;
goto V_188;
}
#endif
#ifdef F_110
V_13 = F_111 ( & F_110 ) ;
if ( V_13 < 0 )
goto V_189;
#endif
#ifdef F_112
V_13 = F_113 ( & F_112 ) ;
if ( V_13 < 0 )
goto V_190;
#endif
#ifdef F_114
V_13 = F_113 ( & F_114 ) ;
if ( V_13 < 0 )
goto V_191;
#endif
#ifdef F_115
V_13 = F_116 ( & F_115 ) ;
if ( V_13 < 0 )
goto V_192;
#endif
#ifdef F_117
V_13 = F_113 ( & F_117 ) ;
if ( V_13 < 0 )
goto V_193;
#endif
#ifdef F_118
V_13 = F_113 ( & F_118 ) ;
if ( V_13 < 0 )
goto V_194;
#endif
#ifdef F_119
V_13 = F_113 ( & F_119 ) ;
if ( V_13 < 0 )
goto V_195;
#endif
return V_13 ;
#ifdef F_119
F_120 ( & F_119 ) ;
V_195:
#endif
#ifdef F_118
F_120 ( & F_118 ) ;
V_194:
#endif
#ifdef F_117
F_120 ( & F_117 ) ;
V_193:
#endif
#ifdef F_115
F_121 ( & F_115 ) ;
V_192:
#endif
#ifdef F_114
F_120 ( & F_114 ) ;
V_191:
#endif
#ifdef F_112
F_120 ( & F_112 ) ;
V_190:
#endif
#ifdef F_110
F_122 ( & F_110 ) ;
V_189:
#endif
#ifdef F_108
F_123 ( V_185 ) ;
V_185 = NULL ;
V_188:
#endif
F_100 ( V_183 , & V_184 ) ;
return V_13 ;
}
static void T_7 F_124 ( void )
{
#ifdef F_119
F_120 ( & F_119 ) ;
#endif
#ifdef F_118
F_120 ( & F_118 ) ;
#endif
#ifdef F_117
F_120 ( & F_117 ) ;
#endif
#ifdef F_115
F_121 ( & F_115 ) ;
#endif
#ifdef F_114
F_120 ( & F_114 ) ;
#endif
#ifdef F_112
F_120 ( & F_112 ) ;
#endif
#ifdef F_110
F_122 ( & F_110 ) ;
#endif
#ifdef F_108
F_123 ( V_185 ) ;
#endif
F_100 ( V_183 , & V_184 ) ;
}
