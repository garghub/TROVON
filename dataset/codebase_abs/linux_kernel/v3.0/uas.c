static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 V_6 ;
F_2 ( & V_7 ) ;
F_3 ( & V_8 , & V_6 ) ;
F_4 ( & V_7 ) ;
F_5 (cmdinfo, &list, list) {
struct V_9 * V_10 = ( void * ) V_4 ;
struct V_11 * V_12 = F_6 ( V_10 ,
struct V_11 , V_13 ) ;
F_7 ( V_12 , V_12 -> V_14 -> V_15 , V_16 ) ;
}
}
static void F_8 ( struct V_17 * V_17 , struct V_11 * V_12 )
{
struct V_18 * V_18 = V_17 -> V_19 ;
struct V_20 * V_21 = V_12 -> V_14 ;
if ( V_17 -> V_22 > 16 ) {
unsigned V_23 = F_9 ( & V_18 -> V_23 ) ;
if ( V_23 + 16 != V_17 -> V_22 ) {
int V_24 = F_10 ( V_23 + 16 , V_17 -> V_22 ) - 16 ;
if ( V_24 < 0 )
V_24 = 0 ;
F_11 ( V_25 , V_21 , L_1
L_2
L_3 , V_26 ,
V_17 -> V_22 , V_23 , V_24 ) ;
V_23 = V_24 ;
}
memcpy ( V_12 -> V_27 , V_18 -> V_28 , V_23 ) ;
}
V_12 -> V_29 = V_18 -> V_30 ;
if ( V_21 -> V_31 )
V_21 -> V_31 = NULL ;
V_12 -> V_32 ( V_12 ) ;
F_12 ( V_17 ) ;
}
static void F_13 ( struct V_17 * V_17 , struct V_11 * V_12 )
{
struct V_33 * V_18 = V_17 -> V_19 ;
struct V_20 * V_21 = V_12 -> V_14 ;
if ( V_17 -> V_22 > 8 ) {
unsigned V_23 = F_9 ( & V_18 -> V_23 ) - 2 ;
if ( V_23 + 8 != V_17 -> V_22 ) {
int V_24 = F_10 ( V_23 + 8 , V_17 -> V_22 ) - 8 ;
if ( V_24 < 0 )
V_24 = 0 ;
F_11 ( V_25 , V_21 , L_1
L_2
L_3 , V_26 ,
V_17 -> V_22 , V_23 , V_24 ) ;
V_23 = V_24 ;
}
memcpy ( V_12 -> V_27 , V_18 -> V_28 , V_23 ) ;
}
V_12 -> V_29 = V_18 -> V_30 ;
if ( V_21 -> V_31 )
V_21 -> V_31 = NULL ;
V_12 -> V_32 ( V_12 ) ;
F_12 ( V_17 ) ;
}
static void F_14 ( struct V_17 * V_17 , struct V_11 * V_12 ,
unsigned V_34 )
{
struct V_3 * V_4 = ( void * ) & V_12 -> V_13 ;
int V_35 ;
V_4 -> V_36 = V_34 | V_37 ;
V_35 = F_7 ( V_12 , V_12 -> V_14 -> V_15 , V_38 ) ;
if ( V_35 ) {
F_15 ( & V_7 ) ;
F_16 ( & V_4 -> V_6 , & V_8 ) ;
F_17 ( & V_7 ) ;
F_18 ( & V_39 ) ;
}
}
static void F_19 ( struct V_17 * V_17 )
{
struct V_40 * V_40 = V_17 -> V_19 ;
struct V_20 * V_21 = V_17 -> V_41 ;
struct V_42 * V_43 = V_21 -> V_15 ;
struct V_11 * V_12 ;
T_1 V_44 ;
if ( V_17 -> V_30 ) {
F_20 ( & V_17 -> V_45 -> V_45 , L_4 , V_17 -> V_30 ) ;
F_12 ( V_17 ) ;
return;
}
V_44 = F_9 ( & V_40 -> V_44 ) - 1 ;
if ( V_21 -> V_31 )
V_12 = V_21 -> V_31 ;
else
V_12 = F_21 ( V_21 , V_44 ) ;
if ( ! V_12 )
return;
switch ( V_40 -> V_46 ) {
case V_47 :
if ( V_17 -> V_22 < 16 )
V_43 -> F_13 = 1 ;
if ( V_43 -> F_13 )
F_13 ( V_17 , V_12 ) ;
else
F_8 ( V_17 , V_12 ) ;
break;
case V_48 :
F_14 ( V_17 , V_12 , V_49 ) ;
break;
case V_50 :
F_14 ( V_17 , V_12 , V_51 ) ;
break;
default:
F_22 ( V_52 , V_12 ,
L_5 , V_40 -> V_46 ) ;
}
}
static void F_23 ( struct V_17 * V_17 )
{
struct V_53 * V_54 = V_17 -> V_41 ;
V_54 -> V_55 = V_54 -> V_56 - V_17 -> V_22 ;
F_12 ( V_17 ) ;
}
static struct V_17 * F_24 ( struct V_42 * V_43 , T_2 V_57 ,
unsigned int V_58 , T_1 V_59 ,
struct V_53 * V_54 ,
enum V_60 V_61 )
{
struct V_62 * V_63 = V_43 -> V_63 ;
struct V_17 * V_17 = F_25 ( 0 , V_57 ) ;
if ( ! V_17 )
goto V_64;
F_26 ( V_17 , V_63 , V_58 , NULL , V_54 -> V_56 , F_23 ,
V_54 ) ;
if ( V_43 -> V_65 )
V_17 -> V_59 = V_59 ;
V_17 -> V_66 = V_63 -> V_67 -> V_68 ? V_54 -> V_69 . V_70 : 0 ;
V_17 -> V_71 = V_54 -> V_69 . V_72 ;
V_64:
return V_17 ;
}
static struct V_17 * F_27 ( struct V_42 * V_43 , T_2 V_57 ,
struct V_11 * V_12 , T_1 V_59 )
{
struct V_62 * V_63 = V_43 -> V_63 ;
struct V_17 * V_17 = F_25 ( 0 , V_57 ) ;
struct V_18 * V_40 ;
if ( ! V_17 )
goto V_64;
V_40 = F_28 ( sizeof( * V_40 ) , V_57 ) ;
if ( ! V_40 )
goto free;
F_26 ( V_17 , V_63 , V_43 -> V_73 , V_40 , sizeof( * V_40 ) ,
F_19 , V_12 -> V_14 ) ;
V_17 -> V_59 = V_59 ;
V_17 -> V_74 |= V_75 ;
V_64:
return V_17 ;
free:
F_12 ( V_17 ) ;
return NULL ;
}
static struct V_17 * F_29 ( struct V_42 * V_43 , T_2 V_57 ,
struct V_11 * V_12 , T_1 V_59 )
{
struct V_62 * V_63 = V_43 -> V_63 ;
struct V_20 * V_21 = V_12 -> V_14 ;
struct V_17 * V_17 = F_25 ( 0 , V_57 ) ;
struct V_76 * V_40 ;
int V_23 ;
if ( ! V_17 )
goto V_64;
V_23 = V_12 -> V_77 - 16 ;
if ( V_23 < 0 )
V_23 = 0 ;
V_23 = F_30 ( V_23 , 4 ) ;
V_40 = F_28 ( sizeof( * V_40 ) + V_23 , V_57 ) ;
if ( ! V_40 )
goto free;
V_40 -> V_46 = V_78 ;
V_40 -> V_44 = F_31 ( V_59 ) ;
V_40 -> V_79 = V_80 ;
V_40 -> V_23 = V_23 ;
F_32 ( V_21 -> V_81 , & V_40 -> V_81 ) ;
memcpy ( V_40 -> V_82 , V_12 -> V_12 , V_12 -> V_77 ) ;
F_26 ( V_17 , V_63 , V_43 -> V_83 , V_40 , sizeof( * V_40 ) + V_23 ,
F_12 , NULL ) ;
V_17 -> V_74 |= V_75 ;
V_64:
return V_17 ;
free:
F_12 ( V_17 ) ;
return NULL ;
}
static int F_7 ( struct V_11 * V_12 ,
struct V_42 * V_43 , T_2 V_57 )
{
struct V_3 * V_4 = ( void * ) & V_12 -> V_13 ;
if ( V_4 -> V_36 & V_84 ) {
V_4 -> V_85 = F_27 ( V_43 , V_57 , V_12 ,
V_4 -> V_86 ) ;
if ( ! V_4 -> V_85 )
return V_87 ;
V_4 -> V_36 &= ~ V_84 ;
}
if ( V_4 -> V_36 & V_37 ) {
if ( F_33 ( V_4 -> V_85 , V_57 ) ) {
F_22 ( V_25 , V_12 ,
L_6 ) ;
return V_87 ;
}
V_4 -> V_36 &= ~ V_37 ;
}
if ( V_4 -> V_36 & V_88 ) {
V_4 -> V_89 = F_24 ( V_43 , V_57 ,
V_43 -> V_90 , V_4 -> V_86 ,
F_34 ( V_12 ) , V_91 ) ;
if ( ! V_4 -> V_89 )
return V_87 ;
V_4 -> V_36 &= ~ V_88 ;
}
if ( V_4 -> V_36 & V_49 ) {
if ( F_33 ( V_4 -> V_89 , V_57 ) ) {
F_22 ( V_25 , V_12 ,
L_7 ) ;
return V_87 ;
}
V_4 -> V_36 &= ~ V_49 ;
}
if ( V_4 -> V_36 & V_92 ) {
V_4 -> V_93 = F_24 ( V_43 , V_57 ,
V_43 -> V_94 , V_4 -> V_86 ,
F_35 ( V_12 ) , V_95 ) ;
if ( ! V_4 -> V_93 )
return V_87 ;
V_4 -> V_36 &= ~ V_92 ;
}
if ( V_4 -> V_36 & V_51 ) {
if ( F_33 ( V_4 -> V_93 , V_57 ) ) {
F_22 ( V_25 , V_12 ,
L_8 ) ;
return V_87 ;
}
V_4 -> V_36 &= ~ V_51 ;
}
if ( V_4 -> V_36 & V_96 ) {
V_4 -> V_97 = F_29 ( V_43 , V_57 , V_12 ,
V_4 -> V_86 ) ;
if ( ! V_4 -> V_97 )
return V_87 ;
V_4 -> V_36 &= ~ V_96 ;
}
if ( V_4 -> V_36 & V_98 ) {
if ( F_33 ( V_4 -> V_97 , V_57 ) ) {
F_22 ( V_25 , V_12 ,
L_9 ) ;
return V_87 ;
}
V_4 -> V_36 &= ~ V_98 ;
}
return 0 ;
}
static int F_36 ( struct V_11 * V_12 ,
void (* F_37)( struct V_11 * ) )
{
struct V_20 * V_21 = V_12 -> V_14 ;
struct V_42 * V_43 = V_21 -> V_15 ;
struct V_3 * V_4 = ( void * ) & V_12 -> V_13 ;
int V_35 ;
F_38 ( sizeof( struct V_3 ) > sizeof( struct V_9 ) ) ;
if ( ! V_4 -> V_85 && V_21 -> V_31 )
return V_87 ;
if ( F_39 ( V_12 -> V_99 ) ) {
V_4 -> V_86 = V_12 -> V_99 -> V_44 + 1 ;
} else {
V_21 -> V_31 = V_12 ;
V_4 -> V_86 = 1 ;
}
V_12 -> V_32 = F_37 ;
V_4 -> V_36 = V_84 | V_37 |
V_96 | V_98 ;
switch ( V_12 -> V_100 ) {
case V_91 :
V_4 -> V_36 |= V_88 | V_49 ;
break;
case V_101 :
V_4 -> V_36 |= V_88 | V_49 ;
case V_95 :
V_4 -> V_36 |= V_92 | V_51 ;
case V_102 :
break;
}
if ( ! V_43 -> V_65 ) {
V_4 -> V_36 &= ~ ( V_49 | V_51 ) ;
V_4 -> V_86 = 0 ;
}
V_35 = F_7 ( V_12 , V_43 , V_38 ) ;
if ( V_35 ) {
if ( V_4 -> V_36 & V_37 ) {
F_12 ( V_4 -> V_85 ) ;
return V_87 ;
}
F_15 ( & V_7 ) ;
F_16 ( & V_4 -> V_6 , & V_8 ) ;
F_17 ( & V_7 ) ;
F_18 ( & V_39 ) ;
}
return 0 ;
}
static int F_40 ( struct V_11 * V_12 )
{
struct V_20 * V_21 = V_12 -> V_14 ;
F_11 ( V_25 , V_21 , L_10 , V_26 ,
V_12 -> V_99 -> V_44 ) ;
return V_103 ;
}
static int F_41 ( struct V_11 * V_12 )
{
struct V_20 * V_21 = V_12 -> V_14 ;
F_11 ( V_25 , V_21 , L_10 , V_26 ,
V_12 -> V_99 -> V_44 ) ;
return V_103 ;
}
static int F_42 ( struct V_11 * V_12 )
{
struct V_20 * V_21 = V_12 -> V_14 ;
struct V_42 * V_43 = V_21 -> V_15 ;
struct V_62 * V_63 = V_43 -> V_63 ;
F_11 ( V_25 , V_21 , L_10 , V_26 ,
V_12 -> V_99 -> V_44 ) ;
if ( F_43 ( V_63 ) )
return V_104 ;
return V_103 ;
}
static int F_44 ( struct V_20 * V_21 )
{
V_21 -> V_15 = ( void * ) V_21 -> V_105 -> V_15 [ 0 ] ;
return 0 ;
}
static int F_45 ( struct V_20 * V_21 )
{
struct V_42 * V_43 = V_21 -> V_15 ;
F_46 ( V_21 , V_106 ) ;
F_47 ( V_21 , V_43 -> V_107 - 1 ) ;
return 0 ;
}
static int F_48 ( struct V_108 * V_109 )
{
return ( V_109 -> V_110 . V_111 == V_112 &&
V_109 -> V_110 . V_113 == V_114 &&
V_109 -> V_110 . V_115 == V_116 ) ;
}
static int F_49 ( struct V_62 * V_63 ,
struct V_117 * V_109 )
{
int V_118 ;
if ( F_48 ( V_109 -> V_119 ) )
return 0 ;
for ( V_118 = 0 ; V_118 < V_109 -> V_120 ; V_118 ++ ) {
struct V_108 * V_121 = & V_109 -> V_122 [ V_118 ] ;
if ( V_121 == V_109 -> V_119 )
continue;
if ( F_48 ( V_121 ) )
return F_50 ( V_63 ,
V_121 -> V_110 . V_123 ,
V_121 -> V_110 . V_124 ) ;
}
return - V_125 ;
}
static void F_51 ( struct V_42 * V_43 )
{
struct V_126 * V_127 [ 4 ] = { } ;
struct V_117 * V_109 = V_43 -> V_109 ;
struct V_62 * V_63 = V_43 -> V_63 ;
struct V_126 * V_128 = V_109 -> V_119 -> V_128 ;
unsigned V_118 , V_129 = V_109 -> V_119 -> V_110 . V_130 ;
V_43 -> F_13 = 0 ;
for ( V_118 = 0 ; V_118 < V_129 ; V_118 ++ ) {
unsigned char * V_131 = V_128 [ V_118 ] . V_131 ;
int V_23 = V_128 [ V_118 ] . V_132 ;
while ( V_23 > 1 ) {
if ( V_131 [ 1 ] == V_133 ) {
unsigned V_134 = V_131 [ 2 ] ;
if ( V_134 > 0 && V_134 < 5 )
V_127 [ V_134 - 1 ] = & V_128 [ V_118 ] ;
break;
}
V_23 -= V_131 [ 0 ] ;
V_131 += V_131 [ 0 ] ;
}
}
if ( ! V_127 [ 0 ] ) {
V_43 -> V_83 = F_52 ( V_63 , 1 ) ;
V_43 -> V_73 = F_53 ( V_63 , 1 ) ;
V_43 -> V_90 = F_53 ( V_63 , 2 ) ;
V_43 -> V_94 = F_52 ( V_63 , 2 ) ;
V_127 [ 1 ] = F_54 ( V_63 , V_43 -> V_73 ) ;
V_127 [ 2 ] = F_54 ( V_63 , V_43 -> V_90 ) ;
V_127 [ 3 ] = F_54 ( V_63 , V_43 -> V_94 ) ;
} else {
V_43 -> V_83 = F_52 ( V_63 ,
V_127 [ 0 ] -> V_110 . V_135 ) ;
V_43 -> V_73 = F_53 ( V_63 ,
V_127 [ 1 ] -> V_110 . V_135 ) ;
V_43 -> V_90 = F_53 ( V_63 ,
V_127 [ 2 ] -> V_110 . V_135 ) ;
V_43 -> V_94 = F_52 ( V_63 ,
V_127 [ 3 ] -> V_110 . V_135 ) ;
}
V_43 -> V_107 = F_55 ( V_43 -> V_109 , V_127 + 1 , 3 , 256 ,
V_136 ) ;
if ( V_43 -> V_107 < 0 ) {
V_43 -> V_107 = 256 ;
V_43 -> V_65 = 0 ;
} else {
V_43 -> V_65 = 1 ;
}
}
static int F_56 ( struct V_117 * V_109 , const struct V_137 * V_138 )
{
int V_29 ;
struct V_139 * V_140 ;
struct V_42 * V_43 ;
struct V_62 * V_63 = F_57 ( V_109 ) ;
if ( F_49 ( V_63 , V_109 ) )
return - V_125 ;
V_43 = F_58 ( sizeof( struct V_42 ) , V_136 ) ;
if ( ! V_43 )
return - V_141 ;
V_29 = - V_141 ;
V_140 = F_59 ( & V_142 , sizeof( void * ) ) ;
if ( ! V_140 )
goto free;
V_140 -> V_143 = 16 + 252 ;
V_140 -> V_144 = 1 ;
V_140 -> V_68 = V_63 -> V_67 -> V_68 ;
V_29 = F_60 ( V_140 , & V_109 -> V_45 ) ;
if ( V_29 )
goto free;
V_140 -> V_15 [ 0 ] = ( unsigned long ) V_43 ;
V_43 -> V_109 = V_109 ;
V_43 -> V_63 = V_63 ;
F_51 ( V_43 ) ;
F_61 ( V_140 ) ;
F_62 ( V_109 , V_140 ) ;
return V_29 ;
free:
F_63 ( V_43 ) ;
if ( V_140 )
F_64 ( V_140 ) ;
return V_29 ;
}
static int F_65 ( struct V_117 * V_109 )
{
return 0 ;
}
static int F_66 ( struct V_117 * V_109 )
{
return 0 ;
}
static void F_67 ( struct V_117 * V_109 )
{
struct V_62 * V_63 = F_57 ( V_109 ) ;
struct V_126 * V_127 [ 3 ] ;
struct V_139 * V_140 = F_68 ( V_109 ) ;
struct V_42 * V_43 = ( void * ) V_140 -> V_15 [ 0 ] ;
F_69 ( V_140 ) ;
V_127 [ 0 ] = F_54 ( V_63 , V_43 -> V_73 ) ;
V_127 [ 1 ] = F_54 ( V_63 , V_43 -> V_90 ) ;
V_127 [ 2 ] = F_54 ( V_63 , V_43 -> V_94 ) ;
F_70 ( V_109 , V_127 , 3 , V_136 ) ;
F_63 ( V_43 ) ;
}
static int F_71 ( void )
{
return F_72 ( & V_145 ) ;
}
static void F_73 ( void )
{
F_74 ( & V_145 ) ;
}
