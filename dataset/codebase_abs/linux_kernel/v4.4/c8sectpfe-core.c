static void F_1 ( unsigned long V_1 )
{
struct V_2 * V_3 = (struct V_2 * ) V_1 ;
struct V_4 * V_5 ;
int V_6 ;
for ( V_6 = 0 ; V_6 < V_3 -> V_7 ; V_6 ++ ) {
V_5 = V_3 -> V_8 [ V_6 ] ;
if ( V_5 -> V_9 && F_2 ( V_5 -> V_9 + V_10 ) )
F_3 ( & V_5 -> V_11 ) ;
}
V_3 -> V_12 . V_13 = V_14 + F_4 ( V_15 ) ;
F_5 ( & V_3 -> V_12 ) ;
}
static void F_6 ( unsigned long V_16 )
{
struct V_4 * V_5 = (struct V_4 * ) V_16 ;
struct V_2 * V_3 = V_5 -> V_3 ;
unsigned long V_17 , V_18 ;
int V_19 , V_20 , V_21 , V_22 ;
T_1 * V_23 ;
if ( F_7 ( ! V_5 || ! V_5 -> V_9 ) )
return;
V_17 = F_2 ( V_5 -> V_9 + F_8 ( 0 ) ) ;
V_18 = F_2 ( V_5 -> V_9 + F_9 ( 0 ) ) ;
V_19 = V_18 - V_5 -> V_24 ;
if ( V_17 < V_18 )
V_17 = V_5 -> V_24 + V_25 ;
V_22 = V_17 - V_18 ;
V_20 = V_22 / V_26 ;
F_10 ( V_3 -> V_27 ,
V_18 ,
V_22 ,
V_28 ) ;
V_23 = ( T_1 * ) V_5 -> V_29 ;
F_11 ( V_3 -> V_27 ,
L_1
L_2 ,
V_5 -> V_30 , V_5 , V_20 , V_23 , V_19 , V_18 , V_17 ) ;
for ( V_21 = 0 ; V_21 < V_20 ; V_21 ++ ) {
F_12 (
& V_3 -> V_31 [ 0 ] ->
V_32 [ V_5 -> V_33 ] . V_34 ,
& V_23 [ V_19 ] , 1 ) ;
V_19 += V_26 ;
}
if ( V_17 == ( V_5 -> V_24 + V_25 ) )
F_13 ( V_5 -> V_24 , V_5 -> V_9 +
F_9 ( 0 ) ) ;
else
F_13 ( V_17 , V_5 -> V_9 + F_8 ( 0 ) ) ;
}
static int F_14 ( struct V_35 * V_36 )
{
struct V_34 * V_32 = V_36 -> V_32 ;
struct V_37 * V_37 = (struct V_37 * ) V_32 -> V_38 ;
struct V_2 * V_3 = V_37 -> V_2 ;
struct V_4 * V_5 ;
T_2 V_39 ;
unsigned long * V_40 ;
switch ( V_36 -> type ) {
case V_41 :
break;
case V_42 :
break;
default:
F_15 ( V_3 -> V_27 , L_3
, V_43 , __LINE__ ) ;
return - V_44 ;
}
if ( V_36 -> type == V_41 ) {
switch ( V_36 -> V_45 ) {
case V_46 :
case V_47 :
case V_48 :
case V_49 :
case V_50 :
break;
default:
F_15 ( V_3 -> V_27 , L_3
, V_43 , __LINE__ ) ;
return - V_44 ;
}
}
if ( ! F_16 ( & V_3 -> V_51 ) ) {
F_15 ( V_3 -> V_27 , L_4 , V_43 ) ;
return - V_44 ;
}
F_17 ( & V_3 -> V_52 ) ;
V_5 = V_3 -> V_8 [ V_37 -> V_53 ] ;
V_40 = ( unsigned long * ) V_5 -> V_54 ;
if ( V_36 -> V_55 == 8192 ) {
V_39 = F_2 ( V_3 -> V_56 + F_18 ( V_5 -> V_30 ) ) ;
V_39 &= ~ V_57 ;
F_13 ( V_39 , V_3 -> V_56 + F_18 ( V_5 -> V_30 ) ) ;
} else {
F_19 ( V_40 , V_36 -> V_55 , 1 ) ;
}
F_20 ( V_3 -> V_27 ,
V_5 -> V_58 ,
V_59 ,
V_60 ) ;
V_5 -> V_61 = 1 ;
if ( V_3 -> V_62 == 0 ) {
V_3 -> V_12 . V_13 = V_14 +
F_4 ( F_4 ( V_15 ) ) ;
F_5 ( & V_3 -> V_12 ) ;
}
if ( V_37 -> V_63 == 0 ) {
F_11 ( V_3 -> V_27 , L_5 , V_5 ) ;
F_21 ( & V_5 -> V_11 , F_6 ,
( unsigned long ) V_5 ) ;
F_13 ( V_5 -> V_64 ,
V_3 -> V_56 + F_22 ( V_5 -> V_30 ) ) ;
F_13 ( V_5 -> V_64 + V_65 - 1 ,
V_3 -> V_56 + F_23 ( V_5 -> V_30 ) ) ;
F_13 ( V_5 -> V_64 ,
V_3 -> V_56 + F_24 ( V_5 -> V_30 ) ) ;
F_13 ( V_5 -> V_64 ,
V_3 -> V_56 + F_25 ( V_5 -> V_30 ) ) ;
F_13 ( V_5 -> V_24 , V_5 -> V_9 +
F_26 ( 0 ) ) ;
V_39 = V_5 -> V_24 + V_25 - 1 ;
F_13 ( V_39 , V_5 -> V_9 + F_27 ( 0 ) ) ;
F_13 ( V_5 -> V_24 , V_5 -> V_9 +
F_8 ( 0 ) ) ;
F_13 ( V_66 | V_67
, V_3 -> V_56 + F_28 ( V_5 -> V_30 ) ) ;
F_13 ( 0x1 , V_5 -> V_9 + V_10 ) ;
F_11 ( V_3 -> V_27 , L_6
, V_43 , __LINE__ , V_37 ) ;
}
V_37 -> V_63 ++ ;
V_3 -> V_62 ++ ;
F_29 ( & V_3 -> V_52 ) ;
return 0 ;
}
static int F_30 ( struct V_35 * V_36 )
{
struct V_34 * V_32 = V_36 -> V_32 ;
struct V_37 * V_37 = (struct V_37 * ) V_32 -> V_38 ;
struct V_2 * V_3 = V_37 -> V_2 ;
struct V_4 * V_5 ;
int V_68 ;
T_2 V_39 ;
int V_69 ;
unsigned long * V_40 ;
if ( ! F_16 ( & V_3 -> V_51 ) ) {
F_15 ( V_3 -> V_27 , L_4 , V_43 ) ;
return - V_44 ;
}
F_17 ( & V_3 -> V_52 ) ;
V_5 = V_3 -> V_8 [ V_37 -> V_53 ] ;
V_40 = ( unsigned long * ) V_5 -> V_54 ;
if ( V_36 -> V_55 == 8192 ) {
V_39 = F_2 ( V_3 -> V_56 + F_18 ( V_5 -> V_30 ) ) ;
V_39 |= V_57 ;
F_13 ( V_39 , V_3 -> V_56 + F_18 ( V_5 -> V_30 ) ) ;
} else {
F_31 ( V_40 , V_36 -> V_55 , 1 ) ;
}
F_20 ( V_3 -> V_27 ,
V_5 -> V_58 ,
V_59 ,
V_60 ) ;
if ( -- V_37 -> V_63 == 0 ) {
V_5 = V_3 -> V_8 [ V_37 -> V_53 ] ;
F_13 ( 0 , V_3 -> V_56 + F_28 ( V_5 -> V_30 ) ) ;
F_13 ( 0 , V_5 -> V_9 + V_10 ) ;
F_32 ( & V_5 -> V_11 ) ;
V_68 = ( 1 << V_5 -> V_30 ) | V_70 ;
F_13 ( V_68 , V_3 -> V_56 + V_71 ) ;
V_69 = F_33 ( & V_5 -> V_72 ,
F_4 ( 100 ) ) ;
if ( V_69 == 0 )
F_34 ( V_3 -> V_27 ,
L_7 ,
V_5 -> V_30 ) ;
F_35 ( & V_5 -> V_72 ) ;
F_13 ( V_5 -> V_24 ,
V_5 -> V_9 + F_26 ( 0 ) ) ;
V_39 = V_5 -> V_24 + V_25 - 1 ;
F_13 ( V_39 , V_5 -> V_9 + F_27 ( 0 ) ) ;
F_13 ( V_5 -> V_24 ,
V_5 -> V_9 + F_8 ( 0 ) ) ;
F_11 ( V_3 -> V_27 ,
L_8 ,
V_43 , __LINE__ , V_37 , V_5 -> V_30 ) ;
memset ( ( void * ) V_5 -> V_54
, 0x00 , V_59 ) ;
F_20 ( V_3 -> V_27 ,
V_5 -> V_58 ,
V_59 ,
V_60 ) ;
V_5 -> V_61 = 0 ;
}
if ( -- V_3 -> V_62 == 0 ) {
F_11 ( V_3 -> V_27 , L_9
, V_43 , __LINE__ , V_3 -> V_62 ) ;
F_36 ( & V_3 -> V_12 ) ;
}
F_29 ( & V_3 -> V_52 ) ;
return 0 ;
}
static struct V_4 * F_37 ( struct V_2 * V_3 , int V_73 )
{
int V_74 ;
for ( V_74 = 0 ; V_74 < V_75 ; V_74 ++ ) {
if ( ! V_3 -> V_8 [ V_74 ] )
continue;
if ( V_3 -> V_8 [ V_74 ] -> V_30 == V_73 )
return V_3 -> V_8 [ V_74 ] ;
}
return NULL ;
}
static void F_38 ( struct V_2 * V_3 )
{
struct V_76 * V_77 = & V_3 -> V_78 ;
V_77 -> V_79 = F_2 ( V_3 -> V_56 + V_80 ) ;
V_77 -> V_81 = F_2 ( V_3 -> V_56 + V_82 ) ;
V_77 -> V_83 = F_2 ( V_3 -> V_56 + V_84 ) ;
V_77 -> V_85 = F_2 ( V_3 -> V_56 + V_86 ) ;
V_77 -> V_87 = F_2 ( V_3 -> V_56 + V_88 ) ;
V_77 -> V_89 = F_2 ( V_3 -> V_56 + V_90 ) ;
V_77 -> V_91 = F_2 ( V_3 -> V_56 + V_92 ) ;
F_39 ( V_3 -> V_27 , L_10 ) ;
F_39 ( V_3 -> V_27 , L_11 , V_77 -> V_79 ) ;
F_39 ( V_3 -> V_27 , L_12 , V_77 -> V_81 ) ;
F_39 ( V_3 -> V_27 , L_13
, V_77 -> V_83 ) ;
F_39 ( V_3 -> V_27 , L_14 , V_77 -> V_85 ) ;
F_39 ( V_3 -> V_27 , L_15 , V_77 -> V_87 ) ;
F_39 ( V_3 -> V_27 , L_16 , V_77 -> V_89 ) ;
F_39 ( V_3 -> V_27 , L_17
, V_77 -> V_91 ) ;
}
static T_3 F_40 ( int V_93 , void * V_38 )
{
struct V_2 * V_3 = V_38 ;
struct V_4 * V_94 ;
int V_95 ;
unsigned long V_39 = F_2 ( V_3 -> V_56 + V_71 ) ;
F_41 (bit, &tmp, fei->hw_stats.num_ib) {
V_94 = F_37 ( V_3 , V_95 ) ;
if ( V_94 )
F_42 ( & V_94 -> V_72 ) ;
}
F_13 ( 0 , V_3 -> V_56 + V_71 ) ;
return V_96 ;
}
static void F_43 ( struct V_2 * V_3 , struct V_4 * V_97 )
{
if ( ! V_3 || ! V_97 )
return;
if ( V_97 -> V_24 )
if ( ! F_44 ( V_3 -> V_27 , V_97 -> V_24 ) )
F_45 ( V_3 -> V_27 , V_97 -> V_24 ,
V_25 , V_98 ) ;
F_46 ( V_97 -> V_99 ) ;
if ( V_97 -> V_58 )
if ( ! F_44 ( V_3 -> V_27 , V_97 -> V_58 ) )
F_45 ( V_3 -> V_27 , V_97 -> V_58 ,
V_59 , V_98 ) ;
F_46 ( V_97 -> V_100 ) ;
}
static int F_47 ( struct V_2 * V_3 ,
struct V_4 * V_97 )
{
int V_69 ;
T_2 V_39 ;
char V_101 [ V_102 ] ;
if ( ! V_3 || ! V_97 )
return - V_44 ;
F_11 ( V_3 -> V_27 , L_18
, V_43 , __LINE__ , V_97 , V_97 -> V_30 ) ;
F_48 ( & V_97 -> V_72 ) ;
V_97 -> V_99 = F_49 ( V_25 +
V_103 , V_104 ) ;
if ( ! V_97 -> V_99 ) {
V_69 = - V_105 ;
goto V_106;
}
V_97 -> V_29 = V_97 -> V_99
+ V_103 ;
V_97 -> V_29 = ( void * )
( ( ( V_107 ) V_97 -> V_29 ) & ~ 0x1F ) ;
V_97 -> V_24 = F_50 ( V_3 -> V_27 ,
( void * ) V_97 -> V_29 ,
V_25 ,
V_98 ) ;
if ( F_44 ( V_3 -> V_27 , V_97 -> V_24 ) ) {
F_15 ( V_3 -> V_27 , L_19 ) ;
V_69 = - V_108 ;
goto V_106;
}
V_97 -> V_100 = F_49 ( 2048 , V_104 ) ;
if ( ! V_97 -> V_100 ) {
V_69 = - V_105 ;
goto V_106;
}
V_97 -> V_54 = V_97 -> V_100 +
V_59 ;
V_97 -> V_54 = ( void * )
( ( ( V_107 ) V_97 -> V_54 ) & ~ 0x3ff ) ;
V_97 -> V_58 = F_50 ( V_3 -> V_27 ,
V_97 -> V_54 ,
V_59 ,
V_98 ) ;
if ( F_44 ( V_3 -> V_27 , V_97 -> V_58 ) ) {
F_15 ( V_3 -> V_27 , L_20 ) ;
V_69 = - V_108 ;
goto V_106;
}
F_20 ( V_3 -> V_27 ,
V_97 -> V_58 ,
V_59 ,
V_60 ) ;
snprintf ( V_101 , V_102 , L_21 , V_97 -> V_30 ,
( V_97 -> V_109 ? L_22 : L_23 ) ) ;
V_97 -> V_110 = F_51 ( V_3 -> V_111 , V_101 ) ;
if ( F_52 ( V_97 -> V_110 ) ) {
F_15 ( V_3 -> V_27 , L_24
, V_43 , V_101 ) ;
V_69 = F_53 ( V_97 -> V_110 ) ;
goto V_106;
}
V_69 = F_54 ( V_3 -> V_111 , V_97 -> V_110 ) ;
if ( V_69 ) {
F_15 ( V_3 -> V_27 , L_25
, V_43 ) ;
goto V_106;
}
V_39 = F_2 ( V_3 -> V_56 + V_112 ) ;
V_39 |= F_55 ( V_97 -> V_30 ) ;
F_13 ( V_39 , V_3 -> V_56 + V_112 ) ;
if ( V_97 -> V_109 )
V_39 |= V_113 ;
if ( V_97 -> V_114 )
V_39 |= V_115 ;
if ( V_97 -> V_116 )
V_39 |= V_117 ;
V_39 |= V_118 | V_119 ;
F_13 ( V_39 , V_3 -> V_56 + F_56 ( V_97 -> V_30 ) ) ;
F_13 ( F_57 ( 0x9 ) |
F_58 ( 0x9 ) |
F_59 ( 0x47 ) ,
V_3 -> V_56 + F_60 ( V_97 -> V_30 ) ) ;
F_13 ( V_120 , V_3 -> V_56 + F_61 ( V_97 -> V_30 ) ) ;
V_97 -> V_64 = ( V_97 -> V_30 * V_65 ) ;
F_13 ( V_97 -> V_64 , V_3 -> V_56 + F_22 ( V_97 -> V_30 ) ) ;
F_13 ( V_97 -> V_64 + V_65 - 1 ,
V_3 -> V_56 + F_23 ( V_97 -> V_30 ) ) ;
F_13 ( V_97 -> V_64 , V_3 -> V_56 + F_24 ( V_97 -> V_30 ) ) ;
F_13 ( V_97 -> V_64 , V_3 -> V_56 + F_25 ( V_97 -> V_30 ) ) ;
F_13 ( V_97 -> V_58 ,
V_3 -> V_56 + F_62 ( V_97 -> V_30 ) ) ;
F_39 ( V_3 -> V_27 , L_26 ,
V_97 -> V_30 , F_2 ( V_3 -> V_56 + F_62 ( V_97 -> V_30 ) ) ,
& V_97 -> V_58 ) ;
V_39 = ( V_57 | F_63 ( 13 )
| F_64 ( 40 ) ) ;
F_13 ( V_39 , V_3 -> V_56 + F_18 ( V_97 -> V_30 ) ) ;
F_11 ( V_3 -> V_27 , L_27 ,
V_97 -> V_30 ,
F_2 ( V_3 -> V_56 + F_25 ( V_97 -> V_30 ) ) ,
F_2 ( V_3 -> V_56 + F_24 ( V_97 -> V_30 ) ) ,
F_2 ( V_3 -> V_56 + F_22 ( V_97 -> V_30 ) ) ,
F_2 ( V_3 -> V_56 + F_23 ( V_97 -> V_30 ) ) ) ;
V_97 -> V_9 = V_3 -> V_56 + V_121 + V_122 +
F_2 ( V_3 -> V_56 + V_123 ) ;
V_97 -> V_9 += ( V_97 -> V_30 * V_124 ) ;
F_13 ( V_97 -> V_64 , V_97 -> V_9 + V_125 ) ;
F_13 ( V_97 -> V_64 + V_65 - 1 , V_97 -> V_9 + V_126 ) ;
F_13 ( ( 188 + 7 ) & ~ 7 , V_97 -> V_9 + V_127 ) ;
F_13 ( 0x1 , V_97 -> V_9 + V_10 ) ;
F_13 ( V_97 -> V_24 , V_97 -> V_9 + F_26 ( 0 ) ) ;
V_39 = V_97 -> V_24 + V_25 - 1 ;
F_13 ( V_39 , V_97 -> V_9 + F_27 ( 0 ) ) ;
F_13 ( V_97 -> V_24 , V_97 -> V_9 + F_8 ( 0 ) ) ;
F_13 ( V_97 -> V_24 , V_97 -> V_9 + F_9 ( 0 ) ) ;
F_21 ( & V_97 -> V_11 , F_6 ,
( unsigned long ) V_97 ) ;
return 0 ;
V_106:
F_43 ( V_3 , V_97 ) ;
return V_69 ;
}
static T_3 F_65 ( int V_93 , void * V_38 )
{
struct V_2 * V_3 = V_38 ;
F_15 ( V_3 -> V_27 , L_28
, V_43 ) ;
return V_96 ;
}
static int F_66 ( struct V_128 * V_129 )
{
struct V_130 * V_27 = & V_129 -> V_27 ;
struct V_131 * V_132 , * V_133 = V_27 -> V_134 ;
struct V_2 * V_3 ;
struct V_135 * V_136 ;
int V_69 , V_137 = 0 ;
struct V_4 * V_97 ;
V_3 = F_67 ( V_27 , sizeof( struct V_2 ) , V_104 ) ;
if ( ! V_3 )
return - V_105 ;
V_3 -> V_27 = V_27 ;
V_136 = F_68 ( V_129 , V_138 , L_29 ) ;
V_3 -> V_56 = F_69 ( V_27 , V_136 ) ;
if ( F_52 ( V_3 -> V_56 ) )
return F_53 ( V_3 -> V_56 ) ;
V_136 = F_68 ( V_129 , V_138 ,
L_30 ) ;
V_3 -> V_139 = F_69 ( V_27 , V_136 ) ;
if ( F_52 ( V_3 -> V_139 ) )
return F_53 ( V_3 -> V_139 ) ;
V_3 -> V_140 = V_136 -> V_141 - V_136 -> V_142 ;
V_3 -> V_143 = F_70 ( V_129 , L_31 ) ;
if ( V_3 -> V_143 < 0 ) {
F_15 ( V_27 , L_32 ) ;
return V_3 -> V_143 ;
}
V_3 -> V_144 = F_70 ( V_129 , L_33 ) ;
if ( V_3 -> V_144 < 0 ) {
F_15 ( V_27 , L_34 ) ;
return V_3 -> V_144 ;
}
F_71 ( V_129 , V_3 ) ;
V_3 -> V_145 = F_72 ( V_27 , L_29 ) ;
if ( F_52 ( V_3 -> V_145 ) ) {
F_15 ( V_27 , L_35 ) ;
return F_53 ( V_3 -> V_145 ) ;
}
V_69 = F_73 ( V_3 -> V_145 ) ;
if ( V_69 ) {
F_15 ( V_27 , L_36 ) ;
return V_69 ;
}
F_13 ( 0 , V_3 -> V_56 + V_112 ) ;
F_13 ( V_146 , V_3 -> V_56 + V_147 ) ;
F_74 ( V_3 -> V_139 , 0x0 , V_3 -> V_140 ) ;
F_38 ( V_3 ) ;
V_69 = F_75 ( V_27 , V_3 -> V_143 , F_40 ,
0 , L_31 , V_3 ) ;
if ( V_69 ) {
F_15 ( V_27 , L_37 ) ;
goto V_148;
}
V_69 = F_75 ( V_27 , V_3 -> V_144 ,
F_65 , 0 ,
L_33 , V_3 ) ;
if ( V_69 ) {
F_15 ( V_27 , L_38 ) ;
goto V_148;
}
V_3 -> V_7 = F_76 ( V_133 ) ;
if ( V_3 -> V_7 > V_75 ||
V_3 -> V_7 > V_3 -> V_78 . V_79 ) {
F_15 ( V_27 , L_39 ) ;
V_69 = - V_44 ;
goto V_148;
}
V_3 -> V_111 = F_77 ( V_27 ) ;
if ( F_52 ( V_3 -> V_111 ) ) {
F_15 ( V_27 , L_40 ) ;
V_69 = F_53 ( V_3 -> V_111 ) ;
goto V_148;
}
F_78 (np, child) {
struct V_131 * V_149 ;
V_3 -> V_8 [ V_137 ] = F_67 ( V_27 ,
sizeof( struct V_4 ) ,
V_104 ) ;
if ( ! V_3 -> V_8 [ V_137 ] ) {
V_69 = - V_105 ;
goto V_148;
}
V_97 = V_3 -> V_8 [ V_137 ] ;
V_97 -> V_3 = V_3 ;
V_69 = F_79 ( V_132 , L_41 , & V_97 -> V_30 ) ;
if ( V_69 ) {
F_15 ( & V_129 -> V_27 , L_42 ) ;
goto V_148;
}
if ( V_97 -> V_30 > V_3 -> V_78 . V_79 ) {
F_15 ( & V_129 -> V_27 ,
L_43
L_44 ,
V_97 -> V_30 , V_3 -> V_78 . V_79 ) ;
V_69 = - V_44 ;
goto V_148;
}
V_97 -> V_114 = F_80 ( V_132 ,
L_45 ) ;
V_97 -> V_109 = F_80 ( V_132 ,
L_46 ) ;
V_97 -> V_116 = F_80 ( V_132 ,
L_47 ) ;
V_69 = F_79 ( V_132 , L_48 ,
& V_97 -> V_150 ) ;
if ( V_69 ) {
F_15 ( & V_129 -> V_27 , L_49 ) ;
goto V_148;
}
V_149 = F_81 ( V_132 , L_50 , 0 ) ;
if ( ! V_149 ) {
F_15 ( & V_129 -> V_27 , L_51 ) ;
goto V_148;
}
V_97 -> V_151 =
F_82 ( V_149 ) ;
if ( ! V_97 -> V_151 ) {
F_15 ( & V_129 -> V_27 , L_52 ) ;
F_83 ( V_149 ) ;
goto V_148;
}
F_83 ( V_149 ) ;
V_97 -> V_152 = F_84 ( V_132 , L_53 , 0 ) ;
V_69 = F_85 ( V_97 -> V_152 ) ;
if ( ! V_69 ) {
F_15 ( V_27 ,
L_54 ,
V_97 -> V_30 , V_97 -> V_152 ) ;
goto V_148;
}
V_69 = F_86 ( V_27 , V_97 -> V_152 ,
V_153 , L_55 ) ;
if ( V_69 && V_69 != - V_154 ) {
F_15 ( V_27 , L_56
, V_3 -> V_8 [ V_137 ] -> V_30 ) ;
goto V_148;
}
if ( ! V_69 ) {
F_87 ( V_97 -> V_152 , 0 ) ;
F_88 ( 3500 , 5000 ) ;
F_87 ( V_97 -> V_152 , 1 ) ;
F_88 ( 3000 , 5000 ) ;
}
V_97 -> V_33 = V_137 ;
F_11 ( V_3 -> V_27 ,
L_57
L_58 ,
V_3 -> V_8 [ V_137 ] , V_137 ,
V_97 -> V_30 , V_97 -> V_114 ,
V_97 -> V_109 , V_97 -> V_116 ,
V_97 -> V_150 ) ;
V_137 ++ ;
}
F_89 ( & V_3 -> V_12 ) ;
V_3 -> V_12 . V_155 = F_1 ;
V_3 -> V_12 . V_16 = ( unsigned long ) V_3 ;
F_90 ( & V_3 -> V_52 ) ;
V_69 = F_91 ( & V_3 -> V_31 [ 0 ] ,
( void * ) V_3 ,
F_14 ,
F_30 ) ;
if ( V_69 ) {
F_15 ( V_27 , L_59 ,
V_69 ) ;
goto V_148;
}
V_69 = F_92 ( V_3 ) ;
if ( V_69 ) {
F_15 ( V_27 , L_60 ) ;
goto V_148;
}
F_93 ( V_3 ) ;
return 0 ;
V_148:
return V_69 ;
}
static int F_94 ( struct V_128 * V_129 )
{
struct V_2 * V_3 = F_95 ( V_129 ) ;
struct V_4 * V_5 ;
int V_74 ;
F_96 ( & V_3 -> V_156 ) ;
F_97 ( V_3 -> V_31 [ 0 ] , V_3 ) ;
for ( V_74 = 0 ; V_74 < V_3 -> V_7 ; V_74 ++ ) {
V_5 = V_3 -> V_8 [ V_74 ] ;
F_43 ( V_3 , V_5 ) ;
}
F_98 ( V_3 ) ;
F_39 ( V_3 -> V_27 , L_61 ) ;
if ( F_2 ( V_3 -> V_56 + V_157 ) )
F_13 ( 0x0 , V_3 -> V_56 + V_157 ) ;
if ( F_2 ( V_3 -> V_56 + V_112 ) )
F_13 ( 0 , V_3 -> V_56 + V_112 ) ;
if ( F_2 ( V_3 -> V_56 + V_147 ) )
F_13 ( 0 , V_3 -> V_56 + V_147 ) ;
return 0 ;
}
static int F_99 ( struct V_2 * V_3 )
{
int V_137 = 0 , V_69 ;
struct V_4 * V_97 ;
struct V_131 * V_132 , * V_133 = V_3 -> V_27 -> V_134 ;
F_78 (np, child) {
V_97 = V_3 -> V_8 [ V_137 ] ;
V_69 = F_47 ( V_3 ,
V_3 -> V_8 [ V_137 ] ) ;
if ( V_69 ) {
F_15 ( V_3 -> V_27 ,
L_62 ) ;
goto V_106;
}
V_137 ++ ;
}
return 0 ;
V_106:
for ( V_137 = 0 ; V_137 < V_3 -> V_7 ; V_137 ++ ) {
V_97 = V_3 -> V_8 [ V_137 ] ;
F_43 ( V_3 , V_97 ) ;
}
return V_69 ;
}
static int
F_100 ( struct V_2 * V_3 , const struct V_158 * V_159 )
{
struct V_160 * V_161 ;
char V_162 ;
if ( ! V_159 ) {
F_15 ( V_3 -> V_27 , L_63 , V_163 ) ;
return - V_44 ;
}
if ( V_159 -> V_22 < sizeof( struct V_160 ) ) {
F_15 ( V_3 -> V_27 , L_64 ) ;
return - V_44 ;
}
V_161 = (struct V_160 * ) V_159 -> V_16 ;
V_162 = V_161 -> V_164 [ V_165 ] ;
if ( V_162 != V_166 ) {
F_15 ( V_3 -> V_27 , L_65 , V_162 ) ;
return - V_44 ;
}
if ( V_161 -> V_164 [ V_167 ] != V_168 ) {
F_15 ( V_3 -> V_27 , L_66 ) ;
return - V_44 ;
}
if ( V_159 -> V_22 < V_161 -> V_169 + sizeof( struct V_170 ) ) {
F_15 ( V_3 -> V_27 , L_64 ) ;
return - V_44 ;
}
if ( memcmp ( V_161 -> V_164 , V_171 , V_172 ) ) {
F_15 ( V_3 -> V_27 , L_67 ) ;
return - V_44 ;
}
V_161 = ( V_173 * ) V_159 -> V_16 ;
if ( V_161 -> V_164 [ V_174 ] != V_175 ||
V_161 -> V_164 [ V_176 ] != V_177 ||
V_161 -> V_164 [ V_178 ] != V_179 ||
V_161 -> V_164 [ V_180 ] != V_181 ) {
F_15 ( V_3 -> V_27 , L_68 ) ;
return - V_44 ;
}
if ( V_161 -> V_182 != V_183 ) {
F_15 ( V_3 -> V_27 , L_69 ) ;
return - V_44 ;
}
if ( V_161 -> V_184 > V_159 -> V_22 ) {
F_15 ( V_3 -> V_27 , L_70 ) ;
return - V_44 ;
}
return 0 ;
}
static void F_101 ( struct V_2 * V_3 , T_4 * V_185 ,
const struct V_158 * V_159 , T_1 T_5 * V_186 ,
int V_187 )
{
const T_1 * V_188 = V_159 -> V_16 + V_185 -> V_189 ;
int V_74 ;
F_11 ( V_3 -> V_27 ,
L_71
L_72 , V_187 ,
V_185 -> V_190 , V_185 -> V_191 ,
V_186 , V_185 -> V_192 + V_185 -> V_192 / 3 ) ;
for ( V_74 = 0 ; V_74 < V_185 -> V_191 ; V_74 ++ ) {
F_102 ( F_103 ( ( void T_5 * ) V_188 ) , ( void T_5 * ) V_186 ) ;
if ( V_74 % 3 == 2 ) {
V_186 ++ ;
F_102 ( 0x00 , ( void T_5 * ) V_186 ) ;
}
V_186 ++ ;
V_188 ++ ;
}
}
static void F_104 ( struct V_2 * V_3 , T_4 * V_185 ,
const struct V_158 * V_159 , T_1 T_5 * V_193 , int V_187 )
{
F_11 ( V_3 -> V_27 ,
L_73
L_74 ,
V_187 , V_185 -> V_190 , V_185 -> V_191 ,
V_193 , V_185 -> V_192 ) ;
memcpy ( ( void V_194 * ) V_193 , ( void * ) V_159 -> V_16 + V_185 -> V_189 ,
V_185 -> V_191 ) ;
memset ( ( void V_194 * ) V_193 + V_185 -> V_191 , 0 ,
V_185 -> V_192 - V_185 -> V_191 ) ;
}
static int F_105 ( const struct V_158 * V_159 , void * V_195 )
{
struct V_2 * V_3 = V_195 ;
V_173 * V_161 ;
T_4 * V_185 ;
T_1 T_5 * V_193 ;
int V_196 = 0 , V_74 ;
if ( ! V_159 || ! V_195 )
return - V_44 ;
V_161 = ( V_173 * ) V_159 -> V_16 ;
V_185 = ( T_4 * ) ( V_159 -> V_16 + V_161 -> V_184 ) ;
for ( V_74 = 0 ; V_74 < V_161 -> V_197 ; V_74 ++ , V_185 ++ ) {
if ( V_185 -> V_198 != V_199 )
continue;
if ( V_185 -> V_189 + V_185 -> V_191 > V_159 -> V_22 ) {
F_15 ( V_3 -> V_27 ,
L_75 , V_74 ) ;
V_196 = - V_44 ;
break;
}
if ( V_185 -> V_200 & V_201 ) {
V_193 = ( T_1 T_5 * ) V_3 -> V_56 + V_202 ;
V_193 += ( V_185 -> V_190 & 0xFFFFF ) * sizeof( unsigned int ) ;
F_101 ( V_3 , V_185 , V_159 , V_193 , V_74 ) ;
} else {
V_193 = ( T_1 T_5 * ) V_3 -> V_56 + V_203 ;
V_193 += ( V_185 -> V_190 & 0xFFFFF ) * sizeof( unsigned int ) ;
F_104 ( V_3 , V_185 , V_159 , V_193 , V_74 ) ;
}
}
F_106 ( V_159 ) ;
return V_196 ;
}
static void F_107 ( const struct V_158 * V_159 , void * V_195 )
{
struct V_2 * V_3 = V_195 ;
int V_196 ;
V_196 = F_100 ( V_3 , V_159 ) ;
if ( V_196 ) {
F_15 ( V_3 -> V_27 , L_76
, V_196 ) ;
goto V_196;
}
V_196 = F_105 ( V_159 , V_195 ) ;
if ( V_196 ) {
F_15 ( V_3 -> V_27 , L_77 , V_196 ) ;
goto V_196;
}
V_196 = F_99 ( V_3 ) ;
if ( V_196 ) {
F_15 ( V_3 -> V_27 , L_78 , V_196 ) ;
goto V_196;
}
F_13 ( 0x1 , V_3 -> V_56 + V_204 ) ;
F_39 ( V_3 -> V_27 , L_79 ) ;
F_13 ( 0x1 , V_3 -> V_56 + V_157 ) ;
F_108 ( & V_3 -> V_51 , 1 ) ;
V_196:
F_109 ( & V_3 -> V_156 ) ;
}
static int F_92 ( struct V_2 * V_3 )
{
int V_196 ;
F_39 ( V_3 -> V_27 , L_80 , V_163 ) ;
F_48 ( & V_3 -> V_156 ) ;
F_108 ( & V_3 -> V_51 , 0 ) ;
V_196 = F_110 ( V_205 , V_206 ,
V_163 , V_3 -> V_27 , V_104 , V_3 ,
F_107 ) ;
if ( V_196 ) {
F_15 ( V_3 -> V_27 , L_81 , V_196 ) ;
F_109 ( & V_3 -> V_156 ) ;
return V_196 ;
}
return 0 ;
}
