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
if ( ! ( V_7 = F_3 ( V_6 , V_3 -> V_14 , V_3 -> V_15 , V_9 , V_3 -> V_16 ) ) )
return - V_17 ;
switch ( V_7 -> type ) {
case V_18 :
if ( V_3 -> V_19 > 4096 )
return - V_20 ;
V_11 = 2 ;
default:
V_11 += V_3 -> V_19 / 4096 ;
if ( ( V_3 -> V_19 % 4096 ) != 0 )
V_11 ++ ;
if ( V_11 == 0 )
V_11 ++ ;
else if ( ( V_3 -> V_21 & V_22 ) != 0
&& ( V_3 -> V_19
% F_4 ( V_3 -> V_15 , V_9 ,
F_5 ( V_9 ) ) ) == 0 )
V_11 ++ ;
break;
case V_23 :
V_11 = V_3 -> V_24 ;
break;
}
V_8 = F_6 ( sizeof ( T_2 ) + V_11 * sizeof ( struct V_25 * ) ,
V_4 ) ;
if ( ! V_8 )
return - V_17 ;
F_7 ( & V_8 -> V_26 ) ;
V_8 -> V_27 = V_11 ;
V_8 -> V_7 = V_7 ;
for ( V_10 = 0 ; V_10 < V_11 ; V_10 ++ ) {
V_8 -> V_25 [ V_10 ] = F_8 ( V_6 , V_4 ) ;
if ( ! V_8 -> V_25 [ V_10 ] ) {
V_8 -> V_27 = V_10 ;
F_9 ( V_6 , V_8 ) ;
return - V_17 ;
}
}
F_10 ( & V_6 -> V_28 , V_12 ) ;
if ( ! F_11 ( V_2 ) ) {
V_13 = - V_29 ;
goto V_30;
}
if ( V_6 -> V_31 != V_32 ) {
V_13 = - V_29 ;
goto V_30;
}
V_13 = F_12 ( V_2 , V_3 ) ;
if ( V_13 )
goto V_30;
if ( V_7 -> V_33 == V_34 ) {
V_13 = F_13 ( V_6 , V_7 ) ;
if ( V_13 < 0 ) {
F_14 ( V_2 , V_3 ) ;
goto V_30;
}
if ( V_7 -> type == V_23 ) {
T_3 V_35 = F_15 ( V_6 ) ;
V_35 += F_16 ( T_3 , 8 , V_7 -> V_16 ) ;
V_35 &= ~ ( V_7 -> V_16 - 1 ) ;
V_35 |= V_7 -> V_36 ;
V_3 -> V_37 = V_35 ;
V_7 -> V_38 = V_35 + V_7 -> V_16 * ( V_11 - 1 ) ;
}
} else if ( V_7 -> type == V_23 ) {
T_3 V_39 = F_15 ( V_6 ) + 1 ;
T_3 V_35 = V_7 -> V_38 + V_7 -> V_16 ;
T_3 V_27 = V_7 -> V_16 * ( V_11 - 1 ) ;
if ( F_17 ( F_18 ( V_35 , V_39 ) ) ) {
if ( V_3 -> V_21 & V_40 ) {
V_35 += ( V_39 - V_35 + V_7 -> V_16 - 1 ) &
- V_7 -> V_16 ;
} else {
V_8 -> V_41 = F_19 (
( T_3 ) ( V_39 - V_35 ) ,
V_7 -> V_16 ) ;
if ( V_8 -> V_41 >= V_8 -> V_27 ) {
++ V_8 -> V_41 ;
F_20 ( V_6 , L_1 ,
V_3 , V_35 , V_27 ,
V_39 ) ;
}
}
}
V_3 -> V_37 = V_35 ;
V_7 -> V_38 = V_35 + V_27 ;
}
V_3 -> V_42 = V_8 ;
F_21 ( V_6 , V_3 ) ;
V_30:
if ( V_13 )
F_9 ( V_6 , V_8 ) ;
F_22 ( & V_6 -> V_28 , V_12 ) ;
return V_13 ;
}
static int F_23 ( struct V_1 * V_2 , struct V_3 * V_3 , int V_43 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned long V_12 ;
int V_44 ;
F_10 ( & V_6 -> V_28 , V_12 ) ;
V_44 = F_24 ( V_2 , V_3 , V_43 ) ;
if ( V_44 ) {
;
} else if ( V_6 -> V_31 == V_32 ) {
T_2 * V_8 ;
V_8 = V_3 -> V_42 ;
if ( V_8 ) {
if ( V_8 -> V_7 -> V_33 == V_45 )
F_25 ( V_6 , V_8 -> V_7 ) ;
}
} else {
if ( V_3 -> V_42 )
F_26 ( V_6 , V_3 , V_43 ) ;
}
F_22 ( & V_6 -> V_28 , V_12 ) ;
return V_44 ;
}
static void
F_27 ( struct V_1 * V_2 , struct V_46 * V_14 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned long V_12 ;
struct V_7 * V_7 = V_14 -> V_42 ;
unsigned V_47 = 1000 ;
if ( ! V_7 )
return;
V_48:
F_10 ( & V_6 -> V_28 , V_12 ) ;
if ( V_6 -> V_31 != V_32 ) {
V_49:
V_7 -> V_33 = V_34 ;
if ( F_28 ( V_6 ) && V_7 -> type == V_50 )
V_6 -> V_51 -- ;
F_29 ( V_6 , 0 ) ;
}
switch ( V_7 -> V_33 ) {
case V_52 :
if ( V_47 -- == 0 ) {
F_30 ( V_6 , L_2 ) ;
if ( F_28 ( V_6 ) ) {
F_30 ( V_6 , L_3 ) ;
V_6 -> V_53 = V_7 ;
V_6 -> V_54 = 2 ;
}
goto V_49;
}
F_22 ( & V_6 -> V_28 , V_12 ) ;
F_31 ( 1 ) ;
goto V_48;
case V_34 :
if ( F_32 ( & V_7 -> V_55 ) ) {
F_33 ( V_6 , V_7 -> V_56 ) ;
F_34 ( V_6 , V_7 ) ;
break;
}
default:
F_35 ( V_6 , L_4 ,
V_7 , V_14 -> V_57 . V_58 , V_7 -> V_33 ,
F_32 ( & V_7 -> V_55 ) ? L_5 : L_6 ) ;
F_33 ( V_6 , V_7 -> V_56 ) ;
break;
}
V_14 -> V_42 = NULL ;
F_22 ( & V_6 -> V_28 , V_12 ) ;
}
static int F_36 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return F_15 ( V_6 ) ;
}
static void F_37 ( struct V_5 * V_6 )
{
V_6 -> V_59 = F_38 ( V_6 , & V_6 -> V_60 -> V_61 ) ;
V_6 -> V_59 &= V_62 ;
F_39 ( V_6 , V_6 -> V_59 , & V_6 -> V_60 -> V_61 ) ;
V_6 -> V_31 = V_63 ;
}
static void
F_40 ( struct V_1 * V_2 )
{
struct V_5 * V_6 ;
V_6 = F_2 ( V_2 ) ;
F_39 ( V_6 , ( V_64 ) ~ 0 , & V_6 -> V_60 -> V_65 ) ;
F_39 ( V_6 , V_66 , & V_6 -> V_60 -> V_67 ) ;
F_38 ( V_6 , & V_6 -> V_60 -> V_67 ) ;
F_41 ( 10 ) ;
F_39 ( V_6 , V_6 -> V_68 , & V_6 -> V_60 -> V_68 ) ;
}
static int F_42 ( struct V_5 * V_6 , struct V_7 * V_7 )
{
return ( F_43 ( V_6 , V_7 -> V_69 ) & V_70 ) != 0
&& ( F_43 ( V_6 , V_7 -> V_71 ) & V_72 )
== ( F_43 ( V_6 , V_7 -> V_73 ) & V_72 )
&& ! F_32 ( & V_7 -> V_55 ) ;
}
static void F_44 ( unsigned long V_74 )
{
unsigned long V_12 ;
unsigned V_75 ;
unsigned V_76 = 0 ;
unsigned V_10 ;
struct V_7 * * V_77 = NULL ;
struct V_5 * V_6 = (struct V_5 * ) V_74 ;
F_10 ( & V_6 -> V_28 , V_12 ) ;
V_75 = V_6 -> V_51 ;
if ( ! V_75 )
goto V_78;
if ( V_6 -> V_53 )
goto V_79;
V_77 = F_45 ( V_75 , sizeof *V_77 , V_80 ) ;
if ( ! V_77 )
goto V_79;
for ( V_10 = 0 ; V_10 < V_81 ; V_10 ++ ) {
struct V_7 * V_7 = V_6 -> V_82 [ V_10 ] ;
while ( V_7 ) {
unsigned V_83 ;
for ( V_83 = 0 ; V_83 < V_76 ; V_83 ++ ) {
if ( V_77 [ V_83 ] == V_7 ) {
V_7 = NULL ;
break;
}
}
if ( ! V_7 )
break;
V_77 [ V_76 ++ ] = V_7 ;
if ( ! F_42 ( V_6 , V_7 ) ) {
V_7 = V_7 -> V_84 ;
continue;
}
V_6 -> V_53 = V_7 ;
V_6 -> V_54 = 2 ;
F_39 ( V_6 , V_85 ,
& V_6 -> V_60 -> V_86 ) ;
F_39 ( V_6 , V_85 ,
& V_6 -> V_60 -> V_87 ) ;
( void ) F_38 ( V_6 , & V_6 -> V_60 -> V_61 ) ;
goto V_79;
}
}
V_79:
F_46 ( V_77 ) ;
if ( V_6 -> V_51 )
F_47 ( & V_6 -> V_88 , F_48 ( V_89 + V_90 ) ) ;
V_78:
F_22 ( & V_6 -> V_28 , V_12 ) ;
}
static int F_49 ( struct V_5 * V_6 )
{
int V_91 ;
struct V_1 * V_2 = F_50 ( V_6 ) ;
if ( V_92 )
V_6 -> V_12 |= V_93 ;
V_6 -> V_31 = V_63 ;
V_6 -> V_60 = V_2 -> V_60 ;
#ifndef F_51
if ( ! V_94 && F_38 ( V_6 ,
& V_6 -> V_60 -> V_61 ) & V_95 ) {
V_64 V_83 ;
F_20 ( V_6 , L_7 ) ;
V_83 = 500 ;
F_39 ( V_6 , V_96 , & V_6 -> V_60 -> V_87 ) ;
F_39 ( V_6 , V_97 , & V_6 -> V_60 -> V_67 ) ;
while ( F_38 ( V_6 , & V_6 -> V_60 -> V_61 ) & V_95 ) {
F_52 ( 10 ) ;
if ( -- V_83 == 0 ) {
F_35 ( V_6 , L_8
L_9 ) ;
return - V_98 ;
}
}
F_37 ( V_6 ) ;
}
#endif
F_39 ( V_6 , V_99 , & V_6 -> V_60 -> V_65 ) ;
if ( F_38 ( V_6 , & V_6 -> V_60 -> V_61 ) & V_62 )
V_6 -> V_59 |= V_62 ;
if ( V_6 -> V_100 == 0 )
V_6 -> V_100 = F_53 ( V_6 ) & V_101 ;
if ( V_6 -> V_102 )
return 0 ;
V_6 -> V_102 = F_54 ( V_2 -> V_103 . V_104 ,
sizeof * V_6 -> V_102 , & V_6 -> V_105 , 0 ) ;
if ( ! V_6 -> V_102 )
return - V_17 ;
if ( ( V_91 = F_55 ( V_6 ) ) < 0 )
F_56 ( V_2 ) ;
else {
F_57 ( V_6 ) ;
}
return V_91 ;
}
static int F_58 ( struct V_5 * V_6 )
{
V_64 V_106 , V_107 ;
int V_108 = V_6 -> V_68 == 0 ;
struct V_1 * V_2 = F_50 ( V_6 ) ;
V_6 -> V_31 = V_63 ;
if ( V_108 ) {
V_107 = F_38 ( V_6 , & V_6 -> V_60 -> V_68 ) ;
V_6 -> V_68 = V_107 & 0x3fff ;
if ( V_6 -> V_68 != V_109 )
F_20 ( V_6 , L_10 ,
V_6 -> V_68 - V_109 ) ;
V_6 -> V_68 |= F_59 ( V_6 -> V_68 ) << 16 ;
}
if ( ( V_6 -> V_59 & V_62 ) != 0 )
F_60 ( V_2 -> V_103 . V_104 , 1 ) ;
switch ( V_6 -> V_59 & V_110 ) {
case V_111 :
V_107 = 0 ;
break;
case V_112 :
case V_113 :
V_6 -> V_59 &= V_62 ;
V_6 -> V_59 |= V_113 ;
V_107 = 10 ;
break;
default:
V_6 -> V_59 &= V_62 ;
V_6 -> V_59 |= V_114 ;
V_107 = 50 ;
break;
}
F_39 ( V_6 , V_6 -> V_59 , & V_6 -> V_60 -> V_61 ) ;
( void ) F_38 ( V_6 , & V_6 -> V_60 -> V_61 ) ;
F_52 ( V_107 ) ;
memset ( V_6 -> V_102 , 0 , sizeof ( struct V_115 ) ) ;
F_61 ( & V_6 -> V_28 ) ;
V_116:
F_39 ( V_6 , V_66 , & V_6 -> V_60 -> V_67 ) ;
V_107 = 30 ;
while ( ( F_38 ( V_6 , & V_6 -> V_60 -> V_67 ) & V_66 ) != 0 ) {
if ( -- V_107 == 0 ) {
F_62 ( & V_6 -> V_28 ) ;
F_35 ( V_6 , L_11 ) ;
return - 1 ;
}
F_41 ( 1 ) ;
}
if ( V_6 -> V_12 & V_117 ) {
F_39 ( V_6 , V_6 -> V_59 , & V_6 -> V_60 -> V_61 ) ;
( void ) F_38 ( V_6 , & V_6 -> V_60 -> V_61 ) ;
}
F_39 ( V_6 , 0 , & V_6 -> V_60 -> V_118 ) ;
F_39 ( V_6 , 0 , & V_6 -> V_60 -> V_119 ) ;
F_39 ( V_6 , ( V_64 ) V_6 -> V_105 , & V_6 -> V_60 -> V_102 ) ;
F_63 ( V_6 ) ;
if ( ( F_38 ( V_6 , & V_6 -> V_60 -> V_68 ) & 0x3fff0000 ) == 0
|| ! F_38 ( V_6 , & V_6 -> V_60 -> V_120 ) ) {
if ( ! ( V_6 -> V_12 & V_117 ) ) {
V_6 -> V_12 |= V_117 ;
F_20 ( V_6 , L_12 ) ;
goto V_116;
}
F_62 ( & V_6 -> V_28 ) ;
F_35 ( V_6 , L_13 ,
F_38 ( V_6 , & V_6 -> V_60 -> V_68 ) ,
F_38 ( V_6 , & V_6 -> V_60 -> V_120 ) ) ;
return - V_121 ;
}
F_64 ( V_122 , & V_2 -> V_12 ) ;
V_2 -> V_123 = 1 ;
V_6 -> V_59 &= V_62 ;
V_6 -> V_59 |= V_124 | V_111 ;
F_39 ( V_6 , V_6 -> V_59 , & V_6 -> V_60 -> V_61 ) ;
V_6 -> V_31 = V_32 ;
F_39 ( V_6 , V_125 , & V_6 -> V_60 -> V_126 . V_43 ) ;
V_106 = V_127 ;
F_39 ( V_6 , ~ 0 , & V_6 -> V_60 -> V_86 ) ;
F_39 ( V_6 , V_106 , & V_6 -> V_60 -> V_87 ) ;
V_107 = F_53 ( V_6 ) ;
V_107 &= ~ ( V_128 | V_129 ) ;
if ( V_6 -> V_12 & V_130 ) {
V_107 |= V_131 ;
V_107 &= ~ ( V_132 | V_133 ) ;
F_39 ( V_6 , V_107 , & V_6 -> V_60 -> V_126 . V_134 ) ;
} else if ( ( V_6 -> V_12 & V_135 ) ||
( V_6 -> V_12 & V_93 ) ) {
V_107 |= V_133 ;
F_39 ( V_6 , V_107 , & V_6 -> V_60 -> V_126 . V_134 ) ;
}
F_39 ( V_6 , V_136 , & V_6 -> V_60 -> V_126 . V_43 ) ;
F_39 ( V_6 , ( V_107 & V_133 ) ? 0 : V_137 ,
& V_6 -> V_60 -> V_126 . V_138 ) ;
( void ) F_38 ( V_6 , & V_6 -> V_60 -> V_61 ) ;
V_6 -> V_139 = V_89 + V_140 ;
F_62 ( & V_6 -> V_28 ) ;
F_65 ( ( V_107 >> 23 ) & 0x1fe ) ;
if ( F_28 ( V_6 ) ) {
F_66 ( & V_6 -> V_88 , F_44 ,
( unsigned long ) V_6 ) ;
V_6 -> V_51 = 0 ;
V_6 -> V_53 = NULL ;
}
F_67 ( V_6 , 1 ) ;
return 0 ;
}
int F_68 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_69 ( V_6 ) ;
return F_49 ( V_6 ) ;
}
static int F_70 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_91 ;
V_91 = F_58 ( V_6 ) ;
if ( V_91 < 0 ) {
F_35 ( V_6 , L_14 ) ;
F_56 ( V_2 ) ;
}
return V_91 ;
}
static T_4 F_71 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_141 T_5 * V_60 = V_6 -> V_60 ;
int V_142 ;
V_142 = F_38 ( V_6 , & V_60 -> V_86 ) ;
if ( V_142 == ~ ( V_64 ) 0 ) {
V_6 -> V_31 = V_63 ;
F_20 ( V_6 , L_15 ) ;
F_72 ( V_2 ) ;
return V_143 ;
}
V_142 &= F_38 ( V_6 , & V_60 -> V_87 ) ;
if ( V_142 == 0 || F_17 ( V_6 -> V_31 == V_63 ) )
return V_144 ;
if ( V_142 & V_145 ) {
if ( F_73 ( V_6 ) ) {
F_35 ( V_6 , L_16 ) ;
F_39 ( V_6 , V_145 , & V_60 -> V_65 ) ;
F_74 ( & V_6 -> V_146 ) ;
} else {
F_35 ( V_6 , L_17 ) ;
V_6 -> V_31 = V_63 ;
F_72 ( V_2 ) ;
}
F_67 ( V_6 , 1 ) ;
F_37 ( V_6 ) ;
}
if ( V_142 & V_147 ) {
F_20 ( V_6 , L_18 ) ;
V_6 -> V_139 = V_89 + V_140 ;
F_39 ( V_6 , V_148 | V_147 ,
& V_60 -> V_86 ) ;
F_39 ( V_6 , V_147 , & V_60 -> V_65 ) ;
F_75 ( V_2 ) ;
}
else if ( V_142 & V_148 ) {
F_20 ( V_6 , L_19 ) ;
F_39 ( V_6 , V_148 , & V_60 -> V_86 ) ;
F_64 ( V_122 , & V_2 -> V_12 ) ;
if ( V_6 -> V_149 ) {
F_76 ( & V_6 -> V_28 ) ;
F_77 ( V_6 ) ;
F_78 ( & V_6 -> V_28 ) ;
} else
F_79 ( V_2 ) ;
}
if ( V_142 & V_150 ) {
F_76 ( & V_6 -> V_28 ) ;
F_80 ( V_6 ) ;
F_78 ( & V_6 -> V_28 ) ;
}
if ( F_28 ( V_6 ) && ( V_142 & V_85 ) ) {
F_76 ( & V_6 -> V_28 ) ;
if ( V_6 -> V_53 ) {
struct V_7 * V_7 = V_6 -> V_53 ;
if ( F_42 ( V_6 , V_7 ) ) {
if ( -- V_6 -> V_54 == 0 ) {
struct V_25 * V_25 = F_81 (
V_7 -> V_55 . V_39 ,
struct V_25 , V_55 ) ;
F_30 ( V_6 ,
L_20 ,
V_25 ) ;
F_82 ( V_6 , V_25 ) ;
V_6 -> V_53 = NULL ;
}
} else
V_6 -> V_53 = NULL ;
}
F_78 ( & V_6 -> V_28 ) ;
}
F_76 ( & V_6 -> V_28 ) ;
if ( V_6 -> V_151 )
F_29 ( V_6 , F_15 ( V_6 ) ) ;
if ( ( V_142 & V_85 ) != 0
&& ! V_6 -> V_151
&& ! V_6 -> V_53
&& V_6 -> V_31 == V_32 )
F_39 ( V_6 , V_85 , & V_60 -> V_65 ) ;
F_78 ( & V_6 -> V_28 ) ;
if ( V_6 -> V_31 == V_32 ) {
F_39 ( V_6 , V_142 , & V_60 -> V_86 ) ;
F_39 ( V_6 , V_99 , & V_60 -> V_87 ) ;
( void ) F_38 ( V_6 , & V_6 -> V_60 -> V_61 ) ;
}
return V_143 ;
}
static void F_56 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_67 ( V_6 , 1 ) ;
if ( F_73 ( V_6 ) )
F_83 ( & V_6 -> V_146 ) ;
F_39 ( V_6 , V_99 , & V_6 -> V_60 -> V_65 ) ;
F_37 ( V_6 ) ;
F_84 ( V_2 -> V_152 , V_2 ) ;
V_2 -> V_152 = 0 ;
if ( F_28 ( V_6 ) )
F_85 ( & V_6 -> V_88 ) ;
if ( F_86 ( V_6 ) )
F_87 () ;
F_88 ( V_6 ) ;
F_89 ( V_6 ) ;
if ( V_6 -> V_102 ) {
F_90 ( V_2 -> V_103 . V_104 ,
sizeof * V_6 -> V_102 ,
V_6 -> V_102 , V_6 -> V_105 ) ;
V_6 -> V_102 = NULL ;
V_6 -> V_105 = 0 ;
}
}
int F_91 ( struct V_5 * V_6 )
{
int V_83 ;
int V_10 ;
struct V_8 * V_153 ;
F_49 ( V_6 ) ;
F_61 ( & V_6 -> V_28 ) ;
V_6 -> V_31 = V_63 ;
if ( ! F_32 ( & V_6 -> V_26 ) )
F_20 ( V_6 , L_21 ) ;
F_92 (priv, &ohci->pending, pending) {
struct V_3 * V_3 = V_153 -> V_25 [ 0 ] -> V_3 ;
struct V_7 * V_7 = V_153 -> V_7 ;
switch ( V_7 -> V_33 ) {
case V_45 :
V_7 -> V_33 = V_52 ;
V_7 -> V_69 |= F_93 ( V_6 , V_154 ) ;
F_94 ( V_6 , V_7 ) ;
V_7 -> V_84 = V_6 -> V_151 ;
V_7 -> V_155 = NULL ;
V_6 -> V_151 = V_7 ;
case V_52 :
break;
default:
F_20 ( V_6 , L_22 ,
V_7 , V_7 -> V_33 ) ;
}
if ( ! V_3 -> V_156 )
V_3 -> V_156 = - V_157 ;
}
F_29 ( V_6 , 0 ) ;
F_62 ( & V_6 -> V_28 ) ;
for ( V_10 = 0 ; V_10 < V_81 ; V_10 ++ ) V_6 -> V_158 [ V_10 ] = 0 ;
for ( V_10 = 0 ; V_10 < V_81 ; V_10 ++ ) V_6 -> V_102 -> V_159 [ V_10 ] = 0 ;
V_6 -> V_151 = NULL ;
V_6 -> V_160 = NULL ;
V_6 -> V_161 = NULL ;
if ( ( V_83 = F_58 ( V_6 ) ) < 0 ) {
F_35 ( V_6 , L_23 , V_83 ) ;
return V_83 ;
}
F_20 ( V_6 , L_24 ) ;
return 0 ;
}
int F_95 ( struct V_1 * V_2 , bool V_162 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned long V_12 ;
int V_44 = 0 ;
F_10 ( & V_6 -> V_28 , V_12 ) ;
F_39 ( V_6 , V_99 , & V_6 -> V_60 -> V_65 ) ;
( void ) F_38 ( V_6 , & V_6 -> V_60 -> V_65 ) ;
F_96 ( V_163 , & V_2 -> V_12 ) ;
F_22 ( & V_6 -> V_28 , V_12 ) ;
F_97 ( V_2 -> V_152 ) ;
if ( V_162 && F_98 ( V_2 ) ) {
F_99 ( V_2 , false ) ;
V_44 = - V_98 ;
}
return V_44 ;
}
int F_99 ( struct V_1 * V_2 , bool V_164 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_165 ;
bool V_166 = false ;
F_64 ( V_163 , & V_2 -> V_12 ) ;
if ( V_164 )
F_37 ( V_6 ) ;
V_6 -> V_59 = F_38 ( V_6 , & V_6 -> V_60 -> V_61 ) ;
if ( V_6 -> V_59 & ( V_95 | V_167 ) ) {
V_166 = true ;
} else {
switch ( V_6 -> V_59 & V_110 ) {
case V_111 :
case V_114 :
V_166 = true ;
}
}
if ( V_166 ) {
F_61 ( & V_6 -> V_28 ) ;
F_77 ( V_6 ) ;
F_100 ( V_6 , 0 ) ;
F_62 ( & V_6 -> V_28 ) ;
}
else {
F_20 ( V_6 , L_25 ) ;
for ( V_165 = 0 ; V_165 < V_6 -> V_100 ; V_165 ++ )
F_39 ( V_6 , V_168 ,
& V_6 -> V_60 -> V_126 . V_169 [ V_165 ] ) ;
F_39 ( V_6 , V_99 , & V_6 -> V_60 -> V_87 ) ;
F_38 ( V_6 , & V_6 -> V_60 -> V_87 ) ;
F_52 ( 20 ) ;
}
F_79 ( V_2 ) ;
return 0 ;
}
void F_101 ( struct V_170 * V_171 ,
const struct V_172 * V_173 )
{
* V_171 = V_174 ;
if ( V_173 ) {
V_171 -> V_175 = V_173 -> V_175 ;
V_171 -> V_176 += V_173 -> V_177 ;
if ( V_173 -> V_178 )
V_171 -> V_178 = V_173 -> V_178 ;
}
}
static int T_6 F_102 ( void )
{
int V_13 = 0 ;
if ( F_103 () )
return - V_29 ;
F_104 ( V_179 L_26 V_180 L_27 , V_181 ) ;
F_105 ( L_28 , V_181 ,
sizeof ( struct V_7 ) , sizeof ( struct V_25 ) ) ;
F_64 ( V_182 , & V_183 ) ;
V_184 = F_106 ( L_29 , V_185 ) ;
if ( ! V_184 ) {
V_13 = - V_186 ;
goto V_187;
}
#ifdef F_107
V_13 = F_108 ( & F_107 ) ;
if ( V_13 < 0 )
goto V_188;
#endif
#ifdef F_109
V_13 = F_110 ( & F_109 ) ;
if ( V_13 < 0 )
goto V_189;
#endif
#ifdef F_111
V_13 = F_110 ( & F_111 ) ;
if ( V_13 < 0 )
goto V_190;
#endif
#ifdef F_112
V_13 = F_113 ( & F_112 ) ;
if ( V_13 < 0 )
goto V_191;
#endif
#ifdef F_114
V_13 = F_110 ( & F_114 ) ;
if ( V_13 < 0 )
goto V_192;
#endif
#ifdef F_115
V_13 = F_110 ( & F_115 ) ;
if ( V_13 < 0 )
goto V_193;
#endif
#ifdef F_116
V_13 = F_110 ( & F_116 ) ;
if ( V_13 < 0 )
goto V_194;
#endif
return V_13 ;
#ifdef F_116
F_117 ( & F_116 ) ;
V_194:
#endif
#ifdef F_115
F_117 ( & F_115 ) ;
V_193:
#endif
#ifdef F_114
F_117 ( & F_114 ) ;
V_192:
#endif
#ifdef F_112
F_118 ( & F_112 ) ;
V_191:
#endif
#ifdef F_111
F_117 ( & F_111 ) ;
V_190:
#endif
#ifdef F_109
F_117 ( & F_109 ) ;
V_189:
#endif
#ifdef F_107
F_119 ( & F_107 ) ;
V_188:
#endif
F_120 ( V_184 ) ;
V_184 = NULL ;
V_187:
F_96 ( V_182 , & V_183 ) ;
return V_13 ;
}
static void T_7 F_121 ( void )
{
#ifdef F_116
F_117 ( & F_116 ) ;
#endif
#ifdef F_115
F_117 ( & F_115 ) ;
#endif
#ifdef F_114
F_117 ( & F_114 ) ;
#endif
#ifdef F_112
F_118 ( & F_112 ) ;
#endif
#ifdef F_111
F_117 ( & F_111 ) ;
#endif
#ifdef F_109
F_117 ( & F_109 ) ;
#endif
#ifdef F_107
F_119 ( & F_107 ) ;
#endif
F_120 ( V_184 ) ;
F_96 ( V_182 , & V_183 ) ;
}
