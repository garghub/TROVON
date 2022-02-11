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
}
} else if ( V_7 -> type == V_24 ) {
T_3 V_39 = F_18 ( V_6 ) + 1 ;
T_3 V_36 = V_7 -> V_40 + V_7 -> V_17 ;
if ( F_20 ( F_21 ( V_36 , V_39 ) ) ) {
if ( V_3 -> V_22 & V_41 ) {
V_36 += ( V_39 - V_36 + V_7 -> V_17 - 1 ) &
- V_7 -> V_17 ;
} else {
if ( F_21 ( V_36 + V_7 -> V_17 *
( V_3 -> V_25 - 1 ) , V_39 ) ) {
V_13 = - V_42 ;
F_17 ( V_2 , V_3 ) ;
goto V_31;
}
V_8 -> V_43 = F_22 (
( T_3 ) ( V_39 - V_36 ) ,
V_7 -> V_17 ) ;
}
}
V_3 -> V_38 = V_36 ;
}
V_3 -> V_44 = V_8 ;
F_23 ( V_6 , V_3 ) ;
V_31:
if ( V_13 )
F_12 ( V_6 , V_8 ) ;
F_24 ( & V_6 -> V_29 , V_12 ) ;
return V_13 ;
}
static int F_25 ( struct V_1 * V_2 , struct V_3 * V_3 , int V_45 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned long V_12 ;
int V_46 ;
#ifdef F_3
F_4 ( V_3 , L_2 , 1 , V_45 ) ;
#endif
F_13 ( & V_6 -> V_29 , V_12 ) ;
V_46 = F_26 ( V_2 , V_3 , V_45 ) ;
if ( V_46 ) {
;
} else if ( V_6 -> V_32 == V_33 ) {
T_2 * V_8 ;
V_8 = V_3 -> V_44 ;
if ( V_8 ) {
if ( V_8 -> V_7 -> V_34 == V_47 )
F_27 ( V_6 , V_8 -> V_7 ) ;
}
} else {
if ( V_3 -> V_44 )
F_28 ( V_6 , V_3 , V_45 ) ;
}
F_24 ( & V_6 -> V_29 , V_12 ) ;
return V_46 ;
}
static void
F_29 ( struct V_1 * V_2 , struct V_48 * V_15 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned long V_12 ;
struct V_7 * V_7 = V_15 -> V_44 ;
unsigned V_49 = 1000 ;
if ( ! V_7 )
return;
V_50:
F_13 ( & V_6 -> V_29 , V_12 ) ;
if ( V_6 -> V_32 != V_33 ) {
V_51:
V_7 -> V_34 = V_35 ;
if ( F_30 ( V_6 ) && V_7 -> type == V_52 )
V_6 -> V_53 -- ;
F_31 ( V_6 , 0 ) ;
}
switch ( V_7 -> V_34 ) {
case V_54 :
if ( V_49 -- == 0 ) {
F_32 ( V_6 , L_3 ) ;
if ( F_30 ( V_6 ) ) {
F_32 ( V_6 , L_4 ) ;
V_6 -> V_55 = V_7 ;
V_6 -> V_56 = 2 ;
}
goto V_51;
}
F_24 ( & V_6 -> V_29 , V_12 ) ;
F_33 ( 1 ) ;
goto V_50;
case V_35 :
if ( F_34 ( & V_7 -> V_57 ) ) {
F_35 ( V_6 , V_7 -> V_58 ) ;
F_36 ( V_6 , V_7 ) ;
break;
}
default:
F_37 ( V_6 , L_5 ,
V_7 , V_15 -> V_59 . V_60 , V_7 -> V_34 ,
F_34 ( & V_7 -> V_57 ) ? L_6 : L_7 ) ;
F_35 ( V_6 , V_7 -> V_58 ) ;
break;
}
V_15 -> V_44 = NULL ;
F_24 ( & V_6 -> V_29 , V_12 ) ;
}
static int F_38 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return F_18 ( V_6 ) ;
}
static void F_39 ( struct V_5 * V_6 )
{
V_6 -> V_61 = F_40 ( V_6 , & V_6 -> V_62 -> V_63 ) ;
V_6 -> V_61 &= V_64 ;
F_41 ( V_6 , V_6 -> V_61 , & V_6 -> V_62 -> V_63 ) ;
V_6 -> V_32 = V_65 ;
}
static void
F_42 ( struct V_1 * V_2 )
{
struct V_5 * V_6 ;
V_6 = F_2 ( V_2 ) ;
F_41 ( V_6 , ( V_66 ) ~ 0 , & V_6 -> V_62 -> V_67 ) ;
F_41 ( V_6 , V_68 , & V_6 -> V_62 -> V_69 ) ;
F_40 ( V_6 , & V_6 -> V_62 -> V_69 ) ;
F_43 ( 10 ) ;
F_41 ( V_6 , V_6 -> V_70 , & V_6 -> V_62 -> V_70 ) ;
}
static int F_44 ( struct V_5 * V_6 , struct V_7 * V_7 )
{
return ( F_45 ( V_6 , V_7 -> V_71 ) & V_72 ) != 0
&& ( F_45 ( V_6 , V_7 -> V_73 ) & V_74 )
== ( F_45 ( V_6 , V_7 -> V_75 ) & V_74 )
&& ! F_34 ( & V_7 -> V_57 ) ;
}
static void F_46 ( unsigned long V_76 )
{
unsigned long V_12 ;
unsigned V_77 ;
unsigned V_78 = 0 ;
unsigned V_10 ;
struct V_7 * * V_79 = NULL ;
struct V_5 * V_6 = (struct V_5 * ) V_76 ;
F_13 ( & V_6 -> V_29 , V_12 ) ;
V_77 = V_6 -> V_53 ;
if ( ! V_77 )
goto V_80;
if ( V_6 -> V_55 )
goto V_81;
V_79 = F_47 ( V_77 , sizeof *V_79 , V_82 ) ;
if ( ! V_79 )
goto V_81;
for ( V_10 = 0 ; V_10 < V_83 ; V_10 ++ ) {
struct V_7 * V_7 = V_6 -> V_84 [ V_10 ] ;
while ( V_7 ) {
unsigned V_85 ;
for ( V_85 = 0 ; V_85 < V_78 ; V_85 ++ ) {
if ( V_79 [ V_85 ] == V_7 ) {
V_7 = NULL ;
break;
}
}
if ( ! V_7 )
break;
V_79 [ V_78 ++ ] = V_7 ;
if ( ! F_44 ( V_6 , V_7 ) ) {
V_7 = V_7 -> V_86 ;
continue;
}
V_6 -> V_55 = V_7 ;
V_6 -> V_56 = 2 ;
F_41 ( V_6 , V_87 ,
& V_6 -> V_62 -> V_88 ) ;
F_41 ( V_6 , V_87 ,
& V_6 -> V_62 -> V_89 ) ;
( void ) F_40 ( V_6 , & V_6 -> V_62 -> V_63 ) ;
goto V_81;
}
}
V_81:
F_48 ( V_79 ) ;
if ( V_6 -> V_53 )
F_49 ( & V_6 -> V_90 , F_50 ( V_91 + V_92 ) ) ;
V_80:
F_24 ( & V_6 -> V_29 , V_12 ) ;
}
static int F_51 ( struct V_5 * V_6 )
{
int V_93 ;
struct V_1 * V_2 = F_52 ( V_6 ) ;
if ( V_94 )
V_6 -> V_12 |= V_95 ;
V_6 -> V_32 = V_65 ;
V_6 -> V_62 = V_2 -> V_62 ;
#ifndef F_53
if ( ! V_96 && F_40 ( V_6 ,
& V_6 -> V_62 -> V_63 ) & V_97 ) {
V_66 V_85 ;
F_54 ( V_6 , L_8 ) ;
V_85 = 500 ;
F_41 ( V_6 , V_98 , & V_6 -> V_62 -> V_89 ) ;
F_41 ( V_6 , V_99 , & V_6 -> V_62 -> V_69 ) ;
while ( F_40 ( V_6 , & V_6 -> V_62 -> V_63 ) & V_97 ) {
F_55 ( 10 ) ;
if ( -- V_85 == 0 ) {
F_37 ( V_6 , L_9
L_10 ) ;
return - V_100 ;
}
}
F_39 ( V_6 ) ;
}
#endif
F_41 ( V_6 , V_101 , & V_6 -> V_62 -> V_67 ) ;
if ( F_40 ( V_6 , & V_6 -> V_62 -> V_63 ) & V_64 )
V_6 -> V_61 |= V_64 ;
if ( V_6 -> V_102 == 0 )
V_6 -> V_102 = F_56 ( V_6 ) & V_103 ;
if ( V_6 -> V_104 )
return 0 ;
V_6 -> V_104 = F_57 ( V_2 -> V_105 . V_106 ,
sizeof * V_6 -> V_104 , & V_6 -> V_107 , 0 ) ;
if ( ! V_6 -> V_104 )
return - V_18 ;
if ( ( V_93 = F_58 ( V_6 ) ) < 0 )
F_59 ( V_2 ) ;
else {
F_60 ( V_6 ) ;
}
return V_93 ;
}
static int F_61 ( struct V_5 * V_6 )
{
V_66 V_108 , V_109 ;
int V_110 = V_6 -> V_70 == 0 ;
struct V_1 * V_2 = F_52 ( V_6 ) ;
V_6 -> V_32 = V_65 ;
if ( V_110 ) {
V_109 = F_40 ( V_6 , & V_6 -> V_62 -> V_70 ) ;
V_6 -> V_70 = V_109 & 0x3fff ;
if ( V_6 -> V_70 != V_111 )
F_54 ( V_6 , L_11 ,
V_6 -> V_70 - V_111 ) ;
V_6 -> V_70 |= F_62 ( V_6 -> V_70 ) << 16 ;
}
if ( ( V_6 -> V_61 & V_64 ) != 0 )
F_63 ( V_2 -> V_105 . V_106 , 1 ) ;
switch ( V_6 -> V_61 & V_112 ) {
case V_113 :
V_109 = 0 ;
break;
case V_114 :
case V_115 :
V_6 -> V_61 &= V_64 ;
V_6 -> V_61 |= V_115 ;
V_109 = 10 ;
break;
default:
V_6 -> V_61 &= V_64 ;
V_6 -> V_61 |= V_116 ;
V_109 = 50 ;
break;
}
F_41 ( V_6 , V_6 -> V_61 , & V_6 -> V_62 -> V_63 ) ;
( void ) F_40 ( V_6 , & V_6 -> V_62 -> V_63 ) ;
F_55 ( V_109 ) ;
memset ( V_6 -> V_104 , 0 , sizeof ( struct V_117 ) ) ;
F_64 ( & V_6 -> V_29 ) ;
V_118:
F_41 ( V_6 , V_68 , & V_6 -> V_62 -> V_69 ) ;
V_109 = 30 ;
while ( ( F_40 ( V_6 , & V_6 -> V_62 -> V_69 ) & V_68 ) != 0 ) {
if ( -- V_109 == 0 ) {
F_65 ( & V_6 -> V_29 ) ;
F_37 ( V_6 , L_12 ) ;
return - 1 ;
}
F_43 ( 1 ) ;
}
if ( V_6 -> V_12 & V_119 ) {
F_41 ( V_6 , V_6 -> V_61 , & V_6 -> V_62 -> V_63 ) ;
( void ) F_40 ( V_6 , & V_6 -> V_62 -> V_63 ) ;
}
F_41 ( V_6 , 0 , & V_6 -> V_62 -> V_120 ) ;
F_41 ( V_6 , 0 , & V_6 -> V_62 -> V_121 ) ;
F_41 ( V_6 , ( V_66 ) V_6 -> V_107 , & V_6 -> V_62 -> V_104 ) ;
F_66 ( V_6 ) ;
if ( ( F_40 ( V_6 , & V_6 -> V_62 -> V_70 ) & 0x3fff0000 ) == 0
|| ! F_40 ( V_6 , & V_6 -> V_62 -> V_122 ) ) {
if ( ! ( V_6 -> V_12 & V_119 ) ) {
V_6 -> V_12 |= V_119 ;
F_54 ( V_6 , L_13 ) ;
goto V_118;
}
F_65 ( & V_6 -> V_29 ) ;
F_37 ( V_6 , L_14 ,
F_40 ( V_6 , & V_6 -> V_62 -> V_70 ) ,
F_40 ( V_6 , & V_6 -> V_62 -> V_122 ) ) ;
return - V_123 ;
}
F_67 ( V_124 , & V_2 -> V_12 ) ;
V_2 -> V_125 = 1 ;
V_6 -> V_61 &= V_64 ;
V_6 -> V_61 |= V_126 | V_113 ;
F_41 ( V_6 , V_6 -> V_61 , & V_6 -> V_62 -> V_63 ) ;
V_6 -> V_32 = V_33 ;
F_41 ( V_6 , V_127 , & V_6 -> V_62 -> V_128 . V_45 ) ;
V_108 = V_129 ;
F_41 ( V_6 , ~ 0 , & V_6 -> V_62 -> V_88 ) ;
F_41 ( V_6 , V_108 , & V_6 -> V_62 -> V_89 ) ;
V_109 = F_56 ( V_6 ) ;
V_109 &= ~ ( V_130 | V_131 ) ;
if ( V_6 -> V_12 & V_132 ) {
V_109 |= V_133 ;
V_109 &= ~ ( V_134 | V_135 ) ;
F_41 ( V_6 , V_109 , & V_6 -> V_62 -> V_128 . V_136 ) ;
} else if ( ( V_6 -> V_12 & V_137 ) ||
( V_6 -> V_12 & V_95 ) ) {
V_109 |= V_135 ;
F_41 ( V_6 , V_109 , & V_6 -> V_62 -> V_128 . V_136 ) ;
}
F_41 ( V_6 , V_138 , & V_6 -> V_62 -> V_128 . V_45 ) ;
F_41 ( V_6 , ( V_109 & V_135 ) ? 0 : V_139 ,
& V_6 -> V_62 -> V_128 . V_140 ) ;
( void ) F_40 ( V_6 , & V_6 -> V_62 -> V_63 ) ;
V_6 -> V_141 = V_91 + V_142 ;
F_65 ( & V_6 -> V_29 ) ;
F_68 ( ( V_109 >> 23 ) & 0x1fe ) ;
if ( F_30 ( V_6 ) ) {
F_69 ( & V_6 -> V_90 , F_46 ,
( unsigned long ) V_6 ) ;
V_6 -> V_53 = 0 ;
V_6 -> V_55 = NULL ;
}
F_70 ( V_6 , 1 ) ;
return 0 ;
}
int F_71 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_72 ( V_6 ) ;
return F_51 ( V_6 ) ;
}
static int F_73 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_93 ;
V_93 = F_61 ( V_6 ) ;
if ( V_93 < 0 ) {
F_37 ( V_6 , L_15 ) ;
F_59 ( V_2 ) ;
}
return V_93 ;
}
static T_4 F_74 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_143 T_5 * V_62 = V_6 -> V_62 ;
int V_144 ;
V_144 = F_40 ( V_6 , & V_62 -> V_88 ) ;
if ( V_144 == ~ ( V_66 ) 0 ) {
V_6 -> V_32 = V_65 ;
F_54 ( V_6 , L_16 ) ;
F_75 ( V_2 ) ;
return V_145 ;
}
V_144 &= F_40 ( V_6 , & V_62 -> V_89 ) ;
if ( V_144 == 0 || F_20 ( V_6 -> V_32 == V_65 ) )
return V_146 ;
if ( V_144 & V_147 ) {
if ( F_76 ( V_6 ) ) {
F_37 ( V_6 , L_17 ) ;
F_41 ( V_6 , V_147 , & V_62 -> V_67 ) ;
F_77 ( & V_6 -> V_148 ) ;
} else {
F_37 ( V_6 , L_18 ) ;
V_6 -> V_32 = V_65 ;
F_75 ( V_2 ) ;
}
F_70 ( V_6 , 1 ) ;
F_39 ( V_6 ) ;
}
if ( V_144 & V_149 ) {
F_78 ( V_6 , L_19 ) ;
V_6 -> V_141 = V_91 + V_142 ;
F_41 ( V_6 , V_150 | V_149 ,
& V_62 -> V_88 ) ;
F_41 ( V_6 , V_149 , & V_62 -> V_67 ) ;
F_79 ( V_2 ) ;
}
else if ( V_144 & V_150 ) {
F_78 ( V_6 , L_20 ) ;
F_41 ( V_6 , V_150 , & V_62 -> V_88 ) ;
F_67 ( V_124 , & V_2 -> V_12 ) ;
if ( V_6 -> V_151 ) {
F_80 ( & V_6 -> V_29 ) ;
F_81 ( V_6 ) ;
F_82 ( & V_6 -> V_29 ) ;
} else
F_83 ( V_2 ) ;
}
if ( V_144 & V_152 ) {
F_80 ( & V_6 -> V_29 ) ;
F_84 ( V_6 ) ;
F_82 ( & V_6 -> V_29 ) ;
}
if ( F_30 ( V_6 ) && ( V_144 & V_87 ) ) {
F_80 ( & V_6 -> V_29 ) ;
if ( V_6 -> V_55 ) {
struct V_7 * V_7 = V_6 -> V_55 ;
if ( F_44 ( V_6 , V_7 ) ) {
if ( -- V_6 -> V_56 == 0 ) {
struct V_26 * V_26 = F_85 (
V_7 -> V_57 . V_39 ,
struct V_26 , V_57 ) ;
F_32 ( V_6 ,
L_21 ,
V_26 ) ;
F_86 ( V_6 , V_26 ) ;
V_6 -> V_55 = NULL ;
}
} else
V_6 -> V_55 = NULL ;
}
F_82 ( & V_6 -> V_29 ) ;
}
F_80 ( & V_6 -> V_29 ) ;
if ( V_6 -> V_153 )
F_31 ( V_6 , F_18 ( V_6 ) ) ;
if ( ( V_144 & V_87 ) != 0
&& ! V_6 -> V_153
&& ! V_6 -> V_55
&& V_6 -> V_32 == V_33 )
F_41 ( V_6 , V_87 , & V_62 -> V_67 ) ;
F_82 ( & V_6 -> V_29 ) ;
if ( V_6 -> V_32 == V_33 ) {
F_41 ( V_6 , V_144 , & V_62 -> V_88 ) ;
F_41 ( V_6 , V_101 , & V_62 -> V_89 ) ;
( void ) F_40 ( V_6 , & V_6 -> V_62 -> V_63 ) ;
}
return V_145 ;
}
static void F_59 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_70 ( V_6 , 1 ) ;
if ( F_76 ( V_6 ) )
F_87 ( & V_6 -> V_148 ) ;
F_39 ( V_6 ) ;
F_41 ( V_6 , V_101 , & V_6 -> V_62 -> V_67 ) ;
F_88 ( V_2 -> V_154 , V_2 ) ;
V_2 -> V_154 = 0 ;
if ( F_30 ( V_6 ) )
F_89 ( & V_6 -> V_90 ) ;
if ( F_90 ( V_6 ) )
F_91 () ;
F_92 ( V_6 ) ;
F_93 ( V_6 ) ;
if ( V_6 -> V_104 ) {
F_94 ( V_2 -> V_105 . V_106 ,
sizeof * V_6 -> V_104 ,
V_6 -> V_104 , V_6 -> V_107 ) ;
V_6 -> V_104 = NULL ;
V_6 -> V_107 = 0 ;
}
}
int F_95 ( struct V_5 * V_6 )
{
int V_85 ;
int V_10 ;
struct V_8 * V_155 ;
F_51 ( V_6 ) ;
F_64 ( & V_6 -> V_29 ) ;
V_6 -> V_32 = V_65 ;
if ( ! F_34 ( & V_6 -> V_27 ) )
F_54 ( V_6 , L_22 ) ;
F_96 (priv, &ohci->pending, pending) {
struct V_3 * V_3 = V_155 -> V_26 [ 0 ] -> V_3 ;
struct V_7 * V_7 = V_155 -> V_7 ;
switch ( V_7 -> V_34 ) {
case V_47 :
V_7 -> V_34 = V_54 ;
V_7 -> V_71 |= F_97 ( V_6 , V_156 ) ;
F_98 ( V_6 , V_7 ) ;
V_7 -> V_86 = V_6 -> V_153 ;
V_7 -> V_157 = NULL ;
V_6 -> V_153 = V_7 ;
case V_54 :
break;
default:
F_54 ( V_6 , L_23 ,
V_7 , V_7 -> V_34 ) ;
}
if ( ! V_3 -> V_158 )
V_3 -> V_158 = - V_159 ;
}
F_31 ( V_6 , 0 ) ;
F_65 ( & V_6 -> V_29 ) ;
for ( V_10 = 0 ; V_10 < V_83 ; V_10 ++ ) V_6 -> V_160 [ V_10 ] = 0 ;
for ( V_10 = 0 ; V_10 < V_83 ; V_10 ++ ) V_6 -> V_104 -> V_161 [ V_10 ] = 0 ;
V_6 -> V_153 = NULL ;
V_6 -> V_162 = NULL ;
V_6 -> V_163 = NULL ;
if ( ( V_85 = F_61 ( V_6 ) ) < 0 ) {
F_37 ( V_6 , L_24 , V_85 ) ;
return V_85 ;
}
F_54 ( V_6 , L_25 ) ;
return 0 ;
}
int F_99 ( struct V_1 * V_2 , bool V_164 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned long V_12 ;
F_13 ( & V_6 -> V_29 , V_12 ) ;
F_41 ( V_6 , V_101 , & V_6 -> V_62 -> V_67 ) ;
( void ) F_40 ( V_6 , & V_6 -> V_62 -> V_67 ) ;
F_100 ( V_165 , & V_2 -> V_12 ) ;
F_24 ( & V_6 -> V_29 , V_12 ) ;
return 0 ;
}
int F_101 ( struct V_1 * V_2 , bool V_166 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_167 ;
bool V_168 = false ;
F_67 ( V_165 , & V_2 -> V_12 ) ;
if ( V_166 )
F_39 ( V_6 ) ;
V_6 -> V_61 = F_40 ( V_6 , & V_6 -> V_62 -> V_63 ) ;
if ( V_6 -> V_61 & ( V_97 | V_169 ) ) {
V_168 = true ;
} else {
switch ( V_6 -> V_61 & V_112 ) {
case V_113 :
case V_116 :
V_168 = true ;
}
}
if ( V_168 ) {
F_64 ( & V_6 -> V_29 ) ;
F_81 ( V_6 ) ;
F_102 ( V_6 , 0 ) ;
F_65 ( & V_6 -> V_29 ) ;
}
else {
F_54 ( V_6 , L_26 ) ;
for ( V_167 = 0 ; V_167 < V_6 -> V_102 ; V_167 ++ )
F_41 ( V_6 , V_170 ,
& V_6 -> V_62 -> V_128 . V_171 [ V_167 ] ) ;
F_41 ( V_6 , V_101 , & V_6 -> V_62 -> V_89 ) ;
F_40 ( V_6 , & V_6 -> V_62 -> V_89 ) ;
F_55 ( 20 ) ;
}
F_83 ( V_2 ) ;
return 0 ;
}
void F_103 ( struct V_172 * V_173 ,
const struct V_174 * V_175 )
{
* V_173 = V_176 ;
V_173 -> V_177 = V_175 -> V_177 ;
V_173 -> V_178 += V_175 -> V_179 ;
if ( V_175 -> V_180 )
V_173 -> V_180 = V_175 -> V_180 ;
}
static int T_6 F_104 ( void )
{
int V_13 = 0 ;
if ( F_105 () )
return - V_30 ;
F_106 ( V_181 L_27 V_182 L_28 , V_183 ) ;
F_107 ( L_29 , V_183 ,
sizeof ( struct V_7 ) , sizeof ( struct V_26 ) ) ;
F_67 ( V_184 , & V_185 ) ;
#ifdef F_108
V_186 = F_109 ( L_30 , V_187 ) ;
if ( ! V_186 ) {
V_13 = - V_188 ;
goto V_189;
}
#endif
#ifdef F_110
V_13 = F_111 ( & F_110 ) ;
if ( V_13 < 0 )
goto V_190;
#endif
#ifdef F_112
V_13 = F_113 ( & F_112 ) ;
if ( V_13 < 0 )
goto V_191;
#endif
#ifdef F_114
V_13 = F_113 ( & F_114 ) ;
if ( V_13 < 0 )
goto V_192;
#endif
#ifdef F_115
V_13 = F_113 ( & F_115 ) ;
if ( V_13 < 0 )
goto V_193;
#endif
#ifdef F_116
V_13 = F_113 ( & F_116 ) ;
if ( V_13 < 0 )
goto V_194;
#endif
#ifdef F_117
V_13 = F_118 ( & F_117 ) ;
if ( V_13 < 0 )
goto V_195;
#endif
#ifdef F_119
V_13 = F_113 ( & F_119 ) ;
if ( V_13 < 0 )
goto V_196;
#endif
#ifdef F_120
V_13 = F_113 ( & F_120 ) ;
if ( V_13 < 0 )
goto V_197;
#endif
#ifdef F_121
V_13 = F_113 ( & F_121 ) ;
if ( V_13 < 0 )
goto V_198;
#endif
#ifdef F_122
V_13 = F_113 ( & F_122 ) ;
if ( V_13 < 0 )
goto V_199;
#endif
#ifdef F_123
V_13 = F_113 ( & F_123 ) ;
if ( V_13 < 0 )
goto V_200;
#endif
#ifdef F_124
V_13 = F_113 ( & F_124 ) ;
if ( V_13 < 0 )
goto V_201;
#endif
#ifdef F_125
V_13 = F_113 ( & F_125 ) ;
if ( V_13 < 0 )
goto V_202;
#endif
#ifdef F_126
V_13 = F_113 ( & F_126 ) ;
if ( V_13 < 0 )
goto V_203;
#endif
#ifdef F_127
V_13 = F_113 ( & F_127 ) ;
if ( V_13 < 0 )
goto V_204;
#endif
return V_13 ;
#ifdef F_127
F_128 ( & F_127 ) ;
V_204:
#endif
#ifdef F_126
F_128 ( & F_126 ) ;
V_203:
#endif
#ifdef F_125
F_128 ( & F_125 ) ;
V_202:
#endif
#ifdef F_124
F_128 ( & F_124 ) ;
V_201:
#endif
#ifdef F_123
F_128 ( & F_123 ) ;
V_200:
#endif
#ifdef F_122
F_128 ( & F_122 ) ;
V_199:
#endif
#ifdef F_121
F_128 ( & F_121 ) ;
V_198:
#endif
#ifdef F_120
F_128 ( & F_120 ) ;
V_197:
#endif
#ifdef F_119
F_128 ( & F_119 ) ;
V_196:
#endif
#ifdef F_117
F_129 ( & F_117 ) ;
V_195:
#endif
#ifdef F_116
F_128 ( & F_116 ) ;
V_194:
#endif
#ifdef F_115
F_128 ( & F_115 ) ;
V_193:
#endif
#ifdef F_114
F_128 ( & F_114 ) ;
V_192:
#endif
#ifdef F_112
F_128 ( & F_112 ) ;
V_191:
#endif
#ifdef F_110
F_130 ( & F_110 ) ;
V_190:
#endif
#ifdef F_108
F_131 ( V_186 ) ;
V_186 = NULL ;
V_189:
#endif
F_100 ( V_184 , & V_185 ) ;
return V_13 ;
}
static void T_7 F_132 ( void )
{
#ifdef F_127
F_128 ( & F_127 ) ;
#endif
#ifdef F_126
F_128 ( & F_126 ) ;
#endif
#ifdef F_125
F_128 ( & F_125 ) ;
#endif
#ifdef F_124
F_128 ( & F_124 ) ;
#endif
#ifdef F_123
F_128 ( & F_123 ) ;
#endif
#ifdef F_122
F_128 ( & F_122 ) ;
#endif
#ifdef F_121
F_128 ( & F_121 ) ;
#endif
#ifdef F_120
F_128 ( & F_120 ) ;
#endif
#ifdef F_119
F_128 ( & F_119 ) ;
#endif
#ifdef F_117
F_129 ( & F_117 ) ;
#endif
#ifdef F_116
F_128 ( & F_116 ) ;
#endif
#ifdef F_115
F_128 ( & F_115 ) ;
#endif
#ifdef F_114
F_128 ( & F_114 ) ;
#endif
#ifdef F_112
F_128 ( & F_112 ) ;
#endif
#ifdef F_110
F_130 ( & F_110 ) ;
#endif
#ifdef F_108
F_131 ( V_186 ) ;
#endif
F_100 ( V_184 , & V_185 ) ;
}
