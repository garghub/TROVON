static inline int F_1 ( const struct V_1 * V_2 , const struct V_1 * V_3 )
{
if ( V_2 -> V_4 != V_3 -> V_4 )
return 0 ;
if ( V_2 -> V_5 != V_3 -> V_5 )
return 0 ;
switch ( V_2 -> V_4 ) {
case F_2 ( V_6 ) :
return V_2 -> V_7 . V_8 == V_3 -> V_7 . V_8 ;
#if F_3 ( V_9 )
case F_2 ( V_10 ) :
return F_4 ( & V_2 -> V_7 . V_11 , & V_3 -> V_7 . V_11 ) ;
#endif
}
return 0 ;
}
static inline int F_5 ( struct V_12 * V_13 , T_1 V_14 ,
T_2 V_5 )
{
return F_6 ( ( V_15 V_16 ) V_14 , V_5 , V_13 -> V_17 ) & ( V_13 -> V_18 - 1 ) ;
}
static inline int F_7 ( struct V_12 * V_13 ,
const struct V_19 * V_14 ,
T_2 V_5 )
{
return F_6 ( F_8 ( V_14 ) , V_5 ,
V_13 -> V_17 ) & ( V_13 -> V_18 - 1 ) ;
}
static inline int F_9 ( struct V_12 * V_13 ,
struct V_1 * V_14 )
{
switch ( V_14 -> V_4 ) {
case F_2 ( V_6 ) :
return F_5 ( V_13 , V_14 -> V_7 . V_8 , V_14 -> V_5 ) ;
#if F_3 ( V_9 )
case F_2 ( V_10 ) :
return F_7 ( V_13 , & V_14 -> V_7 . V_11 , V_14 -> V_5 ) ;
#endif
}
return 0 ;
}
static struct V_20 * F_10 (
struct V_12 * V_13 , struct V_1 * V_21 , int V_22 )
{
struct V_20 * V_23 ;
F_11 (mp, &mdb->mhash[hash], hlist[mdb->ver]) {
if ( F_1 ( & V_23 -> V_24 , V_21 ) )
return V_23 ;
}
return NULL ;
}
struct V_20 * F_12 ( struct V_12 * V_13 ,
struct V_1 * V_21 )
{
if ( ! V_13 )
return NULL ;
return F_10 ( V_13 , V_21 , F_9 ( V_13 , V_21 ) ) ;
}
static struct V_20 * F_13 (
struct V_12 * V_13 , T_1 V_21 , T_2 V_5 )
{
struct V_1 V_25 ;
V_25 . V_7 . V_8 = V_21 ;
V_25 . V_4 = F_2 ( V_6 ) ;
V_25 . V_5 = V_5 ;
return F_12 ( V_13 , & V_25 ) ;
}
static struct V_20 * F_14 (
struct V_12 * V_13 , const struct V_19 * V_21 ,
T_2 V_5 )
{
struct V_1 V_25 ;
V_25 . V_7 . V_11 = * V_21 ;
V_25 . V_4 = F_2 ( V_10 ) ;
V_25 . V_5 = V_5 ;
return F_12 ( V_13 , & V_25 ) ;
}
struct V_20 * F_15 ( struct V_26 * V_27 ,
struct V_28 * V_29 , T_3 V_5 )
{
struct V_12 * V_13 = F_16 ( V_27 -> V_13 ) ;
struct V_1 V_14 ;
if ( V_27 -> V_30 )
return NULL ;
if ( F_17 ( V_29 ) -> V_31 )
return NULL ;
V_14 . V_4 = V_29 -> V_32 ;
V_14 . V_5 = V_5 ;
switch ( V_29 -> V_32 ) {
case F_2 ( V_6 ) :
V_14 . V_7 . V_8 = F_18 ( V_29 ) -> V_33 ;
break;
#if F_3 ( V_9 )
case F_2 ( V_10 ) :
V_14 . V_7 . V_11 = F_19 ( V_29 ) -> V_33 ;
break;
#endif
default:
return NULL ;
}
return F_12 ( V_13 , & V_14 ) ;
}
static void F_20 ( struct V_34 * V_35 )
{
struct V_12 * V_13 =
F_21 ( V_35 , struct V_12 , V_36 ) ;
struct V_12 * V_37 = V_13 -> V_37 ;
V_13 -> V_37 = NULL ;
F_22 ( V_37 -> V_38 ) ;
F_22 ( V_37 ) ;
}
static int F_23 ( struct V_12 * V_39 ,
struct V_12 * V_37 ,
int V_40 )
{
struct V_20 * V_23 ;
int V_41 ;
int V_42 ;
int V_43 ;
for ( V_43 = 0 ; V_43 < V_37 -> V_18 ; V_43 ++ )
F_24 (mp, &old->mhash[i], hlist[old->ver])
F_25 ( & V_23 -> V_44 [ V_39 -> V_45 ] ,
& V_39 -> V_38 [ F_9 ( V_39 , & V_23 -> V_24 ) ] ) ;
if ( ! V_40 )
return 0 ;
V_41 = 0 ;
for ( V_43 = 0 ; V_43 < V_39 -> V_18 ; V_43 ++ ) {
V_42 = 0 ;
F_24 (mp, &new->mhash[i], hlist[new->ver])
V_42 ++ ;
if ( V_42 > V_41 )
V_41 = V_42 ;
}
return V_41 > V_40 ? - V_46 : 0 ;
}
void F_26 ( struct V_34 * V_35 )
{
struct V_47 * V_48 =
F_21 ( V_35 , struct V_47 , V_36 ) ;
F_22 ( V_48 ) ;
}
static void F_27 ( struct V_34 * V_35 )
{
struct V_20 * V_23 =
F_21 ( V_35 , struct V_20 , V_36 ) ;
F_22 ( V_23 ) ;
}
static void F_28 ( unsigned long V_49 )
{
struct V_20 * V_23 = ( void * ) V_49 ;
struct V_26 * V_27 = V_23 -> V_27 ;
struct V_12 * V_13 ;
F_29 ( & V_27 -> V_50 ) ;
if ( ! F_30 ( V_27 -> V_51 ) || F_31 ( & V_23 -> V_52 ) )
goto V_53;
V_23 -> V_54 = false ;
if ( V_23 -> V_55 )
goto V_53;
V_13 = F_32 ( V_27 -> V_13 , V_27 ) ;
F_33 ( & V_23 -> V_44 [ V_13 -> V_45 ] ) ;
V_13 -> V_56 -- ;
F_34 ( & V_23 -> V_36 , F_27 ) ;
V_53:
F_35 ( & V_27 -> V_50 ) ;
}
static void F_36 ( struct V_26 * V_27 ,
struct V_47 * V_57 )
{
struct V_12 * V_13 ;
struct V_20 * V_23 ;
struct V_47 * V_48 ;
struct V_47 T_4 * * V_58 ;
V_13 = F_32 ( V_27 -> V_13 , V_27 ) ;
V_23 = F_12 ( V_13 , & V_57 -> V_24 ) ;
if ( F_37 ( ! V_23 ) )
return;
for ( V_58 = & V_23 -> V_55 ;
( V_48 = F_32 ( * V_58 , V_27 ) ) != NULL ;
V_58 = & V_48 -> V_59 ) {
if ( V_48 != V_57 )
continue;
F_38 ( * V_58 , V_48 -> V_59 ) ;
F_39 ( & V_48 -> V_54 ) ;
F_40 ( & V_48 -> V_52 ) ;
F_41 ( V_27 -> V_51 , V_48 -> V_60 , & V_57 -> V_24 , V_61 ,
V_48 -> V_62 ) ;
F_34 ( & V_48 -> V_36 , F_26 ) ;
if ( ! V_23 -> V_55 && ! V_23 -> V_54 &&
F_30 ( V_27 -> V_51 ) )
F_42 ( & V_23 -> V_52 , V_63 ) ;
return;
}
F_37 ( 1 ) ;
}
static void F_43 ( unsigned long V_49 )
{
struct V_47 * V_57 = ( void * ) V_49 ;
struct V_26 * V_27 = V_57 -> V_60 -> V_27 ;
F_29 ( & V_27 -> V_50 ) ;
if ( ! F_30 ( V_27 -> V_51 ) || F_31 ( & V_57 -> V_52 ) ||
F_44 ( & V_57 -> V_54 ) || V_57 -> V_62 & V_64 )
goto V_53;
F_36 ( V_27 , V_57 ) ;
V_53:
F_35 ( & V_27 -> V_50 ) ;
}
static int F_45 ( struct V_12 T_4 * * V_65 , int V_18 ,
int V_40 )
{
struct V_12 * V_37 = F_46 ( * V_65 , 1 ) ;
struct V_12 * V_13 ;
int V_66 ;
V_13 = F_47 ( sizeof( * V_13 ) , V_67 ) ;
if ( ! V_13 )
return - V_68 ;
V_13 -> V_18 = V_18 ;
V_13 -> V_37 = V_37 ;
V_13 -> V_38 = F_48 ( V_18 * sizeof( * V_13 -> V_38 ) , V_67 ) ;
if ( ! V_13 -> V_38 ) {
F_22 ( V_13 ) ;
return - V_68 ;
}
V_13 -> V_56 = V_37 ? V_37 -> V_56 : 0 ;
V_13 -> V_45 = V_37 ? V_37 -> V_45 ^ 1 : 0 ;
if ( ! V_37 || V_40 )
F_49 ( & V_13 -> V_17 , sizeof( V_13 -> V_17 ) ) ;
else
V_13 -> V_17 = V_37 -> V_17 ;
if ( ! V_37 )
goto V_53;
V_66 = F_23 ( V_13 , V_37 , V_40 ) ;
if ( V_66 ) {
F_22 ( V_13 -> V_38 ) ;
F_22 ( V_13 ) ;
return V_66 ;
}
V_69 ++ ;
F_34 ( & V_13 -> V_36 , F_20 ) ;
V_53:
F_38 ( * V_65 , V_13 ) ;
return 0 ;
}
static struct V_28 * F_50 ( struct V_26 * V_27 ,
T_1 V_70 ,
T_5 * V_71 )
{
struct V_72 * V_73 ;
T_6 V_74 ;
struct V_28 * V_29 ;
struct V_75 * V_76 ;
struct V_77 * V_78 ;
struct V_79 * V_80 ;
V_74 = sizeof( * V_76 ) ;
if ( V_27 -> V_81 == 3 )
V_74 = sizeof( * V_73 ) ;
V_29 = F_51 ( V_27 -> V_51 , sizeof( * V_78 ) + sizeof( * V_80 ) +
V_74 + 4 ) ;
if ( ! V_29 )
goto V_53;
V_29 -> V_32 = F_2 ( V_6 ) ;
F_52 ( V_29 ) ;
V_78 = F_53 ( V_29 ) ;
F_54 ( V_78 -> V_82 , V_27 -> V_51 -> V_83 ) ;
V_78 -> V_84 [ 0 ] = 1 ;
V_78 -> V_84 [ 1 ] = 0 ;
V_78 -> V_84 [ 2 ] = 0x5e ;
V_78 -> V_84 [ 3 ] = 0 ;
V_78 -> V_84 [ 4 ] = 0 ;
V_78 -> V_84 [ 5 ] = 1 ;
V_78 -> V_85 = F_2 ( V_6 ) ;
F_55 ( V_29 , sizeof( * V_78 ) ) ;
F_56 ( V_29 , V_29 -> V_42 ) ;
V_80 = F_18 ( V_29 ) ;
V_80 -> V_86 = 4 ;
V_80 -> V_87 = 6 ;
V_80 -> V_88 = 0xc0 ;
V_80 -> V_89 = F_2 ( sizeof( * V_80 ) + V_74 + 4 ) ;
V_80 -> V_90 = 0 ;
V_80 -> V_91 = F_2 ( V_92 ) ;
V_80 -> V_93 = 1 ;
V_80 -> V_32 = V_94 ;
V_80 -> V_95 = V_27 -> V_96 ?
F_57 ( V_27 -> V_51 , 0 , V_97 ) : 0 ;
V_80 -> V_33 = F_58 ( V_98 ) ;
( ( T_5 * ) & V_80 [ 1 ] ) [ 0 ] = V_99 ;
( ( T_5 * ) & V_80 [ 1 ] ) [ 1 ] = 4 ;
( ( T_5 * ) & V_80 [ 1 ] ) [ 2 ] = 0 ;
( ( T_5 * ) & V_80 [ 1 ] ) [ 3 ] = 0 ;
F_59 ( V_80 ) ;
F_55 ( V_29 , 24 ) ;
F_60 ( V_29 , V_29 -> V_42 ) ;
* V_71 = V_100 ;
switch ( V_27 -> V_81 ) {
case 2 :
V_76 = F_61 ( V_29 ) ;
V_76 -> type = V_100 ;
V_76 -> V_101 = ( V_70 ? V_27 -> V_102 :
V_27 -> V_103 ) /
( V_104 / V_105 ) ;
V_76 -> V_70 = V_70 ;
V_76 -> V_106 = 0 ;
V_76 -> V_106 = F_62 ( ( void * ) V_76 , sizeof( * V_76 ) ) ;
break;
case 3 :
V_73 = F_63 ( V_29 ) ;
V_73 -> type = V_100 ;
V_73 -> V_101 = ( V_70 ? V_27 -> V_102 :
V_27 -> V_103 ) /
( V_104 / V_105 ) ;
V_73 -> V_70 = V_70 ;
V_73 -> V_107 = V_27 -> V_108 / V_104 ;
V_73 -> V_109 = 0 ;
V_73 -> V_110 = 0 ;
V_73 -> V_111 = 0 ;
V_73 -> V_112 = 2 ;
V_73 -> V_106 = 0 ;
V_73 -> V_106 = F_62 ( ( void * ) V_73 , sizeof( * V_73 ) ) ;
break;
}
F_55 ( V_29 , V_74 ) ;
F_64 ( V_29 , sizeof( * V_78 ) ) ;
V_53:
return V_29 ;
}
static struct V_28 * F_65 ( struct V_26 * V_27 ,
const struct V_19 * V_113 ,
T_5 * V_71 )
{
struct V_114 * V_115 ;
unsigned long V_116 ;
struct V_117 * V_118 ;
struct V_119 * V_120 ;
T_6 V_121 ;
struct V_28 * V_29 ;
struct V_77 * V_78 ;
T_5 * V_122 ;
V_121 = sizeof( * V_120 ) ;
if ( V_27 -> V_123 == 2 )
V_121 = sizeof( * V_115 ) ;
V_29 = F_51 ( V_27 -> V_51 , sizeof( * V_78 ) + sizeof( * V_118 ) +
8 + V_121 ) ;
if ( ! V_29 )
goto V_53;
V_29 -> V_32 = F_2 ( V_10 ) ;
F_52 ( V_29 ) ;
V_78 = F_53 ( V_29 ) ;
F_54 ( V_78 -> V_82 , V_27 -> V_51 -> V_83 ) ;
V_78 -> V_85 = F_2 ( V_10 ) ;
F_55 ( V_29 , sizeof( * V_78 ) ) ;
F_56 ( V_29 , V_29 -> V_42 ) ;
V_118 = F_19 ( V_29 ) ;
* ( V_15 T_1 * ) V_118 = F_58 ( 0x60000000 ) ;
V_118 -> V_124 = F_2 ( 8 + V_121 ) ;
V_118 -> V_125 = V_126 ;
V_118 -> V_127 = 1 ;
F_66 ( & V_118 -> V_33 , F_58 ( 0xff020000 ) , 0 , 0 , F_58 ( 1 ) ) ;
if ( F_67 ( F_68 ( V_27 -> V_51 ) , V_27 -> V_51 , & V_118 -> V_33 , 0 ,
& V_118 -> V_95 ) ) {
F_69 ( V_29 ) ;
V_27 -> V_128 = 0 ;
return NULL ;
}
V_27 -> V_128 = 1 ;
F_70 ( & V_118 -> V_33 , V_78 -> V_84 ) ;
V_122 = ( T_5 * ) ( V_118 + 1 ) ;
V_122 [ 0 ] = V_129 ;
V_122 [ 1 ] = 0 ;
V_122 [ 2 ] = V_130 ;
V_122 [ 3 ] = 2 ;
V_122 [ 4 ] = 0 ;
V_122 [ 5 ] = 0 ;
V_122 [ 6 ] = V_131 ;
V_122 [ 7 ] = V_131 ;
F_55 ( V_29 , sizeof( * V_118 ) + 8 ) ;
F_60 ( V_29 , V_29 -> V_42 ) ;
V_116 = F_71 ( V_113 ) ?
V_27 -> V_103 :
V_27 -> V_102 ;
* V_71 = V_132 ;
switch ( V_27 -> V_123 ) {
case 1 :
V_120 = (struct V_119 * ) F_72 ( V_29 ) ;
V_120 -> V_133 = V_132 ;
V_120 -> V_134 = 0 ;
V_120 -> V_135 = 0 ;
V_120 -> V_136 = F_2 ( ( T_3 ) F_73 ( V_116 ) ) ;
V_120 -> V_137 = 0 ;
V_120 -> V_138 = * V_113 ;
V_120 -> V_135 = F_74 ( & V_118 -> V_95 , & V_118 -> V_33 ,
sizeof( * V_120 ) , V_129 ,
F_75 ( V_120 ,
sizeof( * V_120 ) ,
0 ) ) ;
break;
case 2 :
V_115 = (struct V_114 * ) F_72 ( V_29 ) ;
V_115 -> V_139 = F_76 ( ( T_3 ) F_73 ( V_116 ) ) ;
V_115 -> V_140 = V_132 ;
V_115 -> V_141 = 0 ;
V_115 -> V_142 = 0 ;
V_115 -> V_143 = 0 ;
V_115 -> V_144 = 0 ;
V_115 -> V_145 = 0 ;
V_115 -> V_146 = 2 ;
V_115 -> V_147 = 0 ;
V_115 -> V_148 = V_27 -> V_108 / V_104 ;
V_115 -> V_149 = * V_113 ;
V_115 -> V_142 = F_74 ( & V_118 -> V_95 , & V_118 -> V_33 ,
sizeof( * V_115 ) ,
V_129 ,
F_75 ( V_115 ,
sizeof( * V_115 ) ,
0 ) ) ;
break;
}
F_55 ( V_29 , V_121 ) ;
F_64 ( V_29 , sizeof( * V_78 ) ) ;
V_53:
return V_29 ;
}
static struct V_28 * F_77 ( struct V_26 * V_27 ,
struct V_1 * V_24 ,
T_5 * V_71 )
{
switch ( V_24 -> V_4 ) {
case F_2 ( V_6 ) :
return F_50 ( V_27 , V_24 -> V_7 . V_8 , V_71 ) ;
#if F_3 ( V_9 )
case F_2 ( V_10 ) :
return F_65 ( V_27 , & V_24 -> V_7 . V_11 ,
V_71 ) ;
#endif
}
return NULL ;
}
static struct V_20 * F_78 (
struct V_26 * V_27 , struct V_150 * V_60 ,
struct V_1 * V_70 , int V_22 )
{
struct V_12 * V_13 ;
struct V_20 * V_23 ;
unsigned int V_151 = 0 ;
unsigned int V_18 ;
int V_40 ;
int V_66 ;
V_13 = F_46 ( V_27 -> V_13 , 1 ) ;
F_24 (mp, &mdb->mhash[hash], hlist[mdb->ver]) {
V_151 ++ ;
if ( F_79 ( F_1 ( V_70 , & V_23 -> V_24 ) ) )
return V_23 ;
}
V_40 = 0 ;
V_18 = V_13 -> V_18 ;
if ( F_79 ( V_151 > V_27 -> V_152 && V_151 ) ) {
if ( F_80 () )
F_81 ( V_27 , L_1
L_2 ,
V_60 ? V_60 -> V_51 -> V_153 : V_27 -> V_51 -> V_153 ) ;
V_40 = V_27 -> V_152 ;
}
if ( V_13 -> V_56 >= V_18 ) {
V_18 *= 2 ;
if ( F_79 ( V_18 > V_27 -> V_154 ) ) {
F_82 ( V_27 , L_3
L_4 ,
V_27 -> V_154 ,
V_60 ? V_60 -> V_51 -> V_153 : V_27 -> V_51 -> V_153 ) ;
V_66 = - V_155 ;
V_156:
V_27 -> V_30 = 1 ;
goto V_66;
}
}
if ( V_18 > V_13 -> V_18 || V_40 ) {
if ( V_13 -> V_37 ) {
if ( F_80 () )
F_81 ( V_27 , L_1
L_5 ,
V_60 ? V_60 -> V_51 -> V_153 : V_27 -> V_51 -> V_153 ) ;
V_66 = - V_157 ;
goto V_66;
}
V_66 = F_45 ( & V_27 -> V_13 , V_18 , V_40 ) ;
if ( V_66 ) {
F_82 ( V_27 , L_6
L_7 ,
V_60 ? V_60 -> V_51 -> V_153 : V_27 -> V_51 -> V_153 ,
V_13 -> V_56 , V_66 ) ;
goto V_156;
}
V_66 = - V_158 ;
goto V_66;
}
return NULL ;
V_66:
V_23 = F_83 ( V_66 ) ;
return V_23 ;
}
struct V_20 * F_84 ( struct V_26 * V_27 ,
struct V_150 * V_48 ,
struct V_1 * V_70 )
{
struct V_12 * V_13 ;
struct V_20 * V_23 ;
int V_22 ;
int V_66 ;
V_13 = F_46 ( V_27 -> V_13 , 1 ) ;
if ( ! V_13 ) {
V_66 = F_45 ( & V_27 -> V_13 , V_159 , 0 ) ;
if ( V_66 )
return F_83 ( V_66 ) ;
goto V_160;
}
V_22 = F_9 ( V_13 , V_70 ) ;
V_23 = F_78 ( V_27 , V_48 , V_70 , V_22 ) ;
switch ( F_85 ( V_23 ) ) {
case 0 :
break;
case - V_158 :
V_160:
V_13 = F_46 ( V_27 -> V_13 , 1 ) ;
V_22 = F_9 ( V_13 , V_70 ) ;
break;
default:
goto V_53;
}
V_23 = F_48 ( sizeof( * V_23 ) , V_67 ) ;
if ( F_79 ( ! V_23 ) )
return F_83 ( - V_68 ) ;
V_23 -> V_27 = V_27 ;
V_23 -> V_24 = * V_70 ;
F_86 ( & V_23 -> V_52 , F_28 ,
( unsigned long ) V_23 ) ;
F_87 ( & V_23 -> V_44 [ V_13 -> V_45 ] , & V_13 -> V_38 [ V_22 ] ) ;
V_13 -> V_56 ++ ;
V_53:
return V_23 ;
}
struct V_47 * F_88 (
struct V_150 * V_60 ,
struct V_1 * V_70 ,
struct V_47 T_4 * V_59 ,
unsigned char V_62 )
{
struct V_47 * V_48 ;
V_48 = F_48 ( sizeof( * V_48 ) , V_67 ) ;
if ( F_79 ( ! V_48 ) )
return NULL ;
V_48 -> V_24 = * V_70 ;
V_48 -> V_60 = V_60 ;
V_48 -> V_62 = V_62 ;
F_38 ( V_48 -> V_59 , V_59 ) ;
F_25 ( & V_48 -> V_54 , & V_60 -> V_54 ) ;
F_86 ( & V_48 -> V_52 , F_43 ,
( unsigned long ) V_48 ) ;
return V_48 ;
}
static int F_89 ( struct V_26 * V_27 ,
struct V_150 * V_60 ,
struct V_1 * V_70 )
{
struct V_47 T_4 * * V_58 ;
struct V_47 * V_48 ;
struct V_20 * V_23 ;
unsigned long V_161 = V_63 ;
int V_66 ;
F_29 ( & V_27 -> V_50 ) ;
if ( ! F_30 ( V_27 -> V_51 ) ||
( V_60 && V_60 -> V_162 == V_163 ) )
goto V_53;
V_23 = F_84 ( V_27 , V_60 , V_70 ) ;
V_66 = F_85 ( V_23 ) ;
if ( F_90 ( V_23 ) )
goto V_66;
if ( ! V_60 ) {
V_23 -> V_54 = true ;
F_42 ( & V_23 -> V_52 , V_161 + V_27 -> V_164 ) ;
goto V_53;
}
for ( V_58 = & V_23 -> V_55 ;
( V_48 = F_32 ( * V_58 , V_27 ) ) != NULL ;
V_58 = & V_48 -> V_59 ) {
if ( V_48 -> V_60 == V_60 )
goto V_165;
if ( ( unsigned long ) V_48 -> V_60 < ( unsigned long ) V_60 )
break;
}
V_48 = F_88 ( V_60 , V_70 , * V_58 , 0 ) ;
if ( F_79 ( ! V_48 ) )
goto V_66;
F_38 ( * V_58 , V_48 ) ;
F_41 ( V_27 -> V_51 , V_60 , V_70 , V_166 , 0 ) ;
V_165:
F_42 ( & V_48 -> V_52 , V_161 + V_27 -> V_164 ) ;
V_53:
V_66 = 0 ;
V_66:
F_35 ( & V_27 -> V_50 ) ;
return V_66 ;
}
static int F_91 ( struct V_26 * V_27 ,
struct V_150 * V_60 ,
T_1 V_70 ,
T_2 V_5 )
{
struct V_1 V_167 ;
if ( F_92 ( V_70 ) )
return 0 ;
V_167 . V_7 . V_8 = V_70 ;
V_167 . V_4 = F_2 ( V_6 ) ;
V_167 . V_5 = V_5 ;
return F_89 ( V_27 , V_60 , & V_167 ) ;
}
static int F_93 ( struct V_26 * V_27 ,
struct V_150 * V_60 ,
const struct V_19 * V_70 ,
T_2 V_5 )
{
struct V_1 V_167 ;
if ( F_94 ( V_70 ) )
return 0 ;
V_167 . V_7 . V_11 = * V_70 ;
V_167 . V_4 = F_2 ( V_10 ) ;
V_167 . V_5 = V_5 ;
return F_89 ( V_27 , V_60 , & V_167 ) ;
}
static void F_95 ( unsigned long V_49 )
{
struct V_150 * V_60 = ( void * ) V_49 ;
struct V_26 * V_27 = V_60 -> V_27 ;
F_29 ( & V_27 -> V_50 ) ;
if ( V_60 -> V_168 == V_169 ||
V_60 -> V_168 == V_170 ||
F_31 ( & V_60 -> V_171 ) ||
F_44 ( & V_60 -> V_172 ) )
goto V_53;
F_96 ( & V_60 -> V_172 ) ;
F_97 ( V_27 -> V_51 , V_60 , V_61 ) ;
if ( V_60 -> V_168 == V_173 )
V_60 -> V_168 = V_174 ;
V_53:
F_35 ( & V_27 -> V_50 ) ;
}
static void F_98 ( unsigned long V_49 )
{
}
static void F_99 ( struct V_26 * V_27 ,
struct V_175 * V_176 )
{
F_29 ( & V_27 -> V_50 ) ;
if ( ! F_30 ( V_27 -> V_51 ) || V_27 -> V_30 )
goto V_53;
F_100 ( V_27 , V_176 ) ;
V_53:
F_35 ( & V_27 -> V_50 ) ;
}
static void F_101 ( unsigned long V_49 )
{
struct V_26 * V_27 = ( void * ) V_49 ;
F_99 ( V_27 , & V_27 -> V_177 ) ;
}
static void F_102 ( unsigned long V_49 )
{
struct V_26 * V_27 = ( void * ) V_49 ;
F_99 ( V_27 , & V_27 -> V_178 ) ;
}
static void F_103 ( struct V_26 * V_27 ,
struct V_1 * V_14 ,
struct V_28 * V_29 )
{
if ( V_14 -> V_4 == F_2 ( V_6 ) )
V_27 -> V_179 . V_24 . V_7 . V_8 = F_18 ( V_29 ) -> V_95 ;
#if F_3 ( V_9 )
else
V_27 -> V_180 . V_24 . V_7 . V_11 = F_19 ( V_29 ) -> V_95 ;
#endif
}
static void F_104 ( struct V_26 * V_27 ,
struct V_150 * V_60 ,
struct V_1 * V_14 )
{
struct V_28 * V_29 ;
T_5 V_71 ;
V_29 = F_77 ( V_27 , V_14 , & V_71 ) ;
if ( ! V_29 )
return;
if ( V_60 ) {
V_29 -> V_51 = V_60 -> V_51 ;
F_105 ( V_27 , V_60 , V_29 , V_71 ,
V_181 ) ;
F_106 ( V_182 , V_183 ,
F_68 ( V_60 -> V_51 ) , NULL , V_29 , NULL , V_29 -> V_51 ,
V_184 ) ;
} else {
F_103 ( V_27 , V_14 , V_29 ) ;
F_105 ( V_27 , V_60 , V_29 , V_71 ,
V_185 ) ;
F_107 ( V_29 ) ;
}
}
static void F_108 ( struct V_26 * V_27 ,
struct V_150 * V_60 ,
struct V_175 * V_186 )
{
struct V_187 * V_188 = NULL ;
struct V_1 V_167 ;
unsigned long time ;
if ( ! F_30 ( V_27 -> V_51 ) || V_27 -> V_30 ||
! V_27 -> V_189 )
return;
memset ( & V_167 . V_7 , 0 , sizeof( V_167 . V_7 ) ) ;
if ( V_60 ? ( V_186 == & V_60 -> V_177 ) :
( V_186 == & V_27 -> V_177 ) ) {
V_188 = & V_27 -> V_190 ;
V_167 . V_4 = F_2 ( V_6 ) ;
#if F_3 ( V_9 )
} else {
V_188 = & V_27 -> V_191 ;
V_167 . V_4 = F_2 ( V_10 ) ;
#endif
}
if ( ! V_188 || F_31 ( & V_188 -> V_52 ) )
return;
F_104 ( V_27 , V_60 , & V_167 ) ;
time = V_63 ;
time += V_186 -> V_192 < V_27 -> V_193 ?
V_27 -> V_194 :
V_27 -> V_108 ;
F_42 ( & V_186 -> V_52 , time ) ;
}
static void
F_109 ( struct V_150 * V_60 ,
struct V_175 * V_176 )
{
struct V_26 * V_27 = V_60 -> V_27 ;
F_29 ( & V_27 -> V_50 ) ;
if ( V_60 -> V_162 == V_163 ||
V_60 -> V_162 == V_195 )
goto V_53;
if ( V_176 -> V_192 < V_27 -> V_193 )
V_176 -> V_192 ++ ;
F_108 ( V_60 -> V_27 , V_60 , V_176 ) ;
V_53:
F_35 ( & V_27 -> V_50 ) ;
}
static void F_110 ( unsigned long V_49 )
{
struct V_150 * V_60 = ( void * ) V_49 ;
F_109 ( V_60 , & V_60 -> V_177 ) ;
}
static void F_111 ( unsigned long V_49 )
{
struct V_150 * V_60 = ( void * ) V_49 ;
F_109 ( V_60 , & V_60 -> V_178 ) ;
}
int F_112 ( struct V_150 * V_60 )
{
V_60 -> V_168 = V_174 ;
F_86 ( & V_60 -> V_171 , F_95 ,
( unsigned long ) V_60 ) ;
F_86 ( & V_60 -> V_177 . V_52 ,
F_110 , ( unsigned long ) V_60 ) ;
#if F_3 ( V_9 )
F_86 ( & V_60 -> V_178 . V_52 ,
F_111 , ( unsigned long ) V_60 ) ;
#endif
V_60 -> V_196 = F_113 ( struct V_197 ) ;
if ( ! V_60 -> V_196 )
return - V_68 ;
return 0 ;
}
void F_114 ( struct V_150 * V_60 )
{
struct V_26 * V_27 = V_60 -> V_27 ;
struct V_47 * V_57 ;
struct V_198 * V_199 ;
F_115 ( & V_27 -> V_50 ) ;
F_116 (pg, n, &port->mglist, mglist)
F_36 ( V_27 , V_57 ) ;
F_117 ( & V_27 -> V_50 ) ;
F_118 ( & V_60 -> V_171 ) ;
F_119 ( V_60 -> V_196 ) ;
}
static void F_120 ( struct V_175 * V_176 )
{
V_176 -> V_192 = 0 ;
if ( F_121 ( & V_176 -> V_52 ) >= 0 ||
F_40 ( & V_176 -> V_52 ) )
F_42 ( & V_176 -> V_52 , V_63 ) ;
}
static void F_122 ( struct V_150 * V_60 )
{
struct V_26 * V_27 = V_60 -> V_27 ;
if ( V_27 -> V_30 || ! F_30 ( V_27 -> V_51 ) )
return;
F_120 ( & V_60 -> V_177 ) ;
#if F_3 ( V_9 )
F_120 ( & V_60 -> V_178 ) ;
#endif
if ( V_60 -> V_168 == V_170 &&
F_44 ( & V_60 -> V_172 ) )
F_123 ( V_27 , V_60 ) ;
}
void F_124 ( struct V_150 * V_60 )
{
struct V_26 * V_27 = V_60 -> V_27 ;
F_29 ( & V_27 -> V_50 ) ;
F_122 ( V_60 ) ;
F_35 ( & V_27 -> V_50 ) ;
}
void F_125 ( struct V_150 * V_60 )
{
struct V_26 * V_27 = V_60 -> V_27 ;
struct V_47 * V_57 ;
struct V_198 * V_199 ;
F_29 ( & V_27 -> V_50 ) ;
F_116 (pg, n, &port->mglist, mglist)
if ( ! ( V_57 -> V_62 & V_64 ) )
F_36 ( V_27 , V_57 ) ;
if ( ! F_44 ( & V_60 -> V_172 ) ) {
F_96 ( & V_60 -> V_172 ) ;
F_97 ( V_27 -> V_51 , V_60 , V_61 ) ;
if ( V_60 -> V_168 == V_173 )
V_60 -> V_168 = V_174 ;
}
F_40 ( & V_60 -> V_171 ) ;
F_40 ( & V_60 -> V_177 . V_52 ) ;
#if F_3 ( V_9 )
F_40 ( & V_60 -> V_178 . V_52 ) ;
#endif
F_35 ( & V_27 -> V_50 ) ;
}
static int F_126 ( struct V_26 * V_27 ,
struct V_150 * V_60 ,
struct V_28 * V_29 ,
T_3 V_5 )
{
struct V_200 * V_76 ;
struct V_201 * V_202 ;
int V_43 ;
int V_42 ;
int V_203 ;
int type ;
int V_66 = 0 ;
T_1 V_70 ;
V_76 = F_127 ( V_29 ) ;
V_203 = F_76 ( V_76 -> V_204 ) ;
V_42 = F_128 ( V_29 ) + sizeof( * V_76 ) ;
for ( V_43 = 0 ; V_43 < V_203 ; V_43 ++ ) {
V_42 += sizeof( * V_202 ) ;
if ( ! F_129 ( V_29 , V_42 ) )
return - V_46 ;
V_202 = ( void * ) ( V_29 -> V_49 + V_42 - sizeof( * V_202 ) ) ;
V_70 = V_202 -> V_205 ;
type = V_202 -> V_206 ;
V_42 += F_76 ( V_202 -> V_207 ) * 4 ;
if ( ! F_129 ( V_29 , V_42 ) )
return - V_46 ;
switch ( type ) {
case V_208 :
case V_209 :
case V_210 :
case V_211 :
case V_212 :
case V_213 :
break;
default:
continue;
}
if ( ( type == V_210 ||
type == V_208 ) &&
F_76 ( V_202 -> V_207 ) == 0 ) {
F_130 ( V_27 , V_60 , V_70 , V_5 ) ;
} else {
V_66 = F_91 ( V_27 , V_60 , V_70 , V_5 ) ;
if ( V_66 )
break;
}
}
return V_66 ;
}
static int F_131 ( struct V_26 * V_27 ,
struct V_150 * V_60 ,
struct V_28 * V_29 ,
T_3 V_5 )
{
struct V_214 * V_215 ;
struct V_216 * V_202 ;
int V_43 ;
int V_42 ;
int V_203 ;
int V_66 = 0 ;
if ( ! F_129 ( V_29 , sizeof( * V_215 ) ) )
return - V_46 ;
V_215 = F_72 ( V_29 ) ;
V_203 = F_76 ( V_215 -> V_217 . V_218 [ 1 ] ) ;
V_42 = F_128 ( V_29 ) + sizeof( * V_215 ) ;
for ( V_43 = 0 ; V_43 < V_203 ; V_43 ++ ) {
T_7 * V_109 , V_219 ;
V_109 = F_132 ( V_29 ,
V_42 + F_133 ( struct V_216 ,
V_207 ) ,
sizeof( V_219 ) , & V_219 ) ;
if ( ! V_109 )
return - V_46 ;
if ( ! F_129 ( V_29 ,
V_42 + sizeof( * V_202 ) +
sizeof( struct V_19 ) * F_76 ( * V_109 ) ) )
return - V_46 ;
V_202 = (struct V_216 * ) ( V_29 -> V_49 + V_42 ) ;
V_42 += sizeof( * V_202 ) +
sizeof( struct V_19 ) * F_76 ( * V_109 ) ;
switch ( V_202 -> V_206 ) {
case V_220 :
case V_221 :
case V_222 :
case V_223 :
case V_224 :
case V_225 :
break;
default:
continue;
}
if ( ( V_202 -> V_206 == V_222 ||
V_202 -> V_206 == V_220 ) &&
F_76 ( * V_109 ) == 0 ) {
F_134 ( V_27 , V_60 , & V_202 -> V_205 ,
V_5 ) ;
} else {
V_66 = F_93 ( V_27 , V_60 ,
& V_202 -> V_205 , V_5 ) ;
if ( V_66 )
break;
}
}
return V_66 ;
}
static bool F_135 ( struct V_26 * V_27 ,
struct V_150 * V_60 ,
T_1 V_95 )
{
if ( ! F_31 ( & V_27 -> V_177 . V_52 ) &&
! F_31 ( & V_27 -> V_190 . V_52 ) )
goto V_226;
if ( ! V_27 -> V_179 . V_24 . V_7 . V_8 )
goto V_226;
if ( F_136 ( V_95 ) <= F_136 ( V_27 -> V_179 . V_24 . V_7 . V_8 ) )
goto V_226;
return false ;
V_226:
V_27 -> V_179 . V_24 . V_7 . V_8 = V_95 ;
F_38 ( V_27 -> V_179 . V_60 , V_60 ) ;
return true ;
}
static bool F_137 ( struct V_26 * V_27 ,
struct V_150 * V_60 ,
struct V_19 * V_95 )
{
if ( ! F_31 ( & V_27 -> V_178 . V_52 ) &&
! F_31 ( & V_27 -> V_191 . V_52 ) )
goto V_226;
if ( F_138 ( V_95 , & V_27 -> V_180 . V_24 . V_7 . V_11 ) <= 0 )
goto V_226;
return false ;
V_226:
V_27 -> V_180 . V_24 . V_7 . V_11 = * V_95 ;
F_38 ( V_27 -> V_180 . V_60 , V_60 ) ;
return true ;
}
static bool F_139 ( struct V_26 * V_27 ,
struct V_150 * V_60 ,
struct V_1 * V_95 )
{
switch ( V_95 -> V_4 ) {
case F_2 ( V_6 ) :
return F_135 ( V_27 , V_60 , V_95 -> V_7 . V_8 ) ;
#if F_3 ( V_9 )
case F_2 ( V_10 ) :
return F_137 ( V_27 , V_60 , & V_95 -> V_7 . V_11 ) ;
#endif
}
return false ;
}
static void
F_140 ( struct V_26 * V_27 ,
struct V_187 * V_176 ,
unsigned long V_227 )
{
if ( ! F_31 ( & V_176 -> V_52 ) )
V_176 -> V_228 = V_63 + V_227 ;
F_42 ( & V_176 -> V_52 , V_63 + V_27 -> V_229 ) ;
}
static void F_123 ( struct V_26 * V_27 ,
struct V_150 * V_60 )
{
struct V_150 * V_48 ;
struct V_198 * V_230 = NULL ;
if ( ! F_44 ( & V_60 -> V_172 ) )
return;
F_24 (p, &br->router_list, rlist) {
if ( ( unsigned long ) V_60 >= ( unsigned long ) V_48 )
break;
V_230 = & V_48 -> V_172 ;
}
if ( V_230 )
F_141 ( & V_60 -> V_172 , V_230 ) ;
else
F_87 ( & V_60 -> V_172 , & V_27 -> V_231 ) ;
F_97 ( V_27 -> V_51 , V_60 , V_166 ) ;
}
static void F_142 ( struct V_26 * V_27 ,
struct V_150 * V_60 )
{
unsigned long V_161 = V_63 ;
if ( ! V_60 ) {
if ( V_27 -> V_168 == V_174 )
F_42 ( & V_27 -> V_171 ,
V_161 + V_27 -> V_229 ) ;
return;
}
if ( V_60 -> V_168 == V_169 ||
V_60 -> V_168 == V_170 )
return;
F_123 ( V_27 , V_60 ) ;
F_42 ( & V_60 -> V_171 ,
V_161 + V_27 -> V_229 ) ;
}
static void F_143 ( struct V_26 * V_27 ,
struct V_150 * V_60 ,
struct V_187 * V_176 ,
struct V_1 * V_95 ,
unsigned long V_227 )
{
if ( ! F_139 ( V_27 , V_60 , V_95 ) )
return;
F_140 ( V_27 , V_176 , V_227 ) ;
F_142 ( V_27 , V_60 ) ;
}
static int F_144 ( struct V_26 * V_27 ,
struct V_150 * V_60 ,
struct V_28 * V_29 ,
T_3 V_5 )
{
const struct V_79 * V_80 = F_18 ( V_29 ) ;
struct V_75 * V_76 = F_61 ( V_29 ) ;
struct V_20 * V_23 ;
struct V_72 * V_232 ;
struct V_47 * V_48 ;
struct V_47 T_4 * * V_58 ;
struct V_1 V_95 ;
unsigned long V_227 ;
unsigned long V_161 = V_63 ;
unsigned int V_233 = F_128 ( V_29 ) ;
T_1 V_70 ;
int V_66 = 0 ;
F_29 ( & V_27 -> V_50 ) ;
if ( ! F_30 ( V_27 -> V_51 ) ||
( V_60 && V_60 -> V_162 == V_163 ) )
goto V_53;
V_70 = V_76 -> V_70 ;
if ( V_29 -> V_42 == V_233 + sizeof( * V_76 ) ) {
V_227 = V_76 -> V_101 * ( V_104 / V_105 ) ;
if ( ! V_227 ) {
V_227 = 10 * V_104 ;
V_70 = 0 ;
}
} else if ( V_29 -> V_42 >= V_233 + sizeof( * V_232 ) ) {
V_232 = F_63 ( V_29 ) ;
if ( V_232 -> V_109 )
goto V_53;
V_227 = V_232 -> V_101 ?
F_145 ( V_232 -> V_101 ) * ( V_104 / V_105 ) : 1 ;
} else {
goto V_53;
}
if ( ! V_70 ) {
V_95 . V_4 = F_2 ( V_6 ) ;
V_95 . V_7 . V_8 = V_80 -> V_95 ;
F_143 ( V_27 , V_60 , & V_27 -> V_190 ,
& V_95 , V_227 ) ;
goto V_53;
}
V_23 = F_13 ( F_32 ( V_27 -> V_13 , V_27 ) , V_70 , V_5 ) ;
if ( ! V_23 )
goto V_53;
V_227 *= V_27 -> V_234 ;
if ( V_23 -> V_54 &&
( F_31 ( & V_23 -> V_52 ) ?
F_146 ( V_23 -> V_52 . V_235 , V_161 + V_227 ) :
F_121 ( & V_23 -> V_52 ) >= 0 ) )
F_42 ( & V_23 -> V_52 , V_161 + V_227 ) ;
for ( V_58 = & V_23 -> V_55 ;
( V_48 = F_32 ( * V_58 , V_27 ) ) != NULL ;
V_58 = & V_48 -> V_59 ) {
if ( F_31 ( & V_48 -> V_52 ) ?
F_146 ( V_48 -> V_52 . V_235 , V_161 + V_227 ) :
F_121 ( & V_48 -> V_52 ) >= 0 )
F_42 ( & V_48 -> V_52 , V_161 + V_227 ) ;
}
V_53:
F_35 ( & V_27 -> V_50 ) ;
return V_66 ;
}
static int F_147 ( struct V_26 * V_27 ,
struct V_150 * V_60 ,
struct V_28 * V_29 ,
T_3 V_5 )
{
const struct V_117 * V_118 = F_19 ( V_29 ) ;
struct V_119 * V_236 ;
struct V_20 * V_23 ;
struct V_114 * V_115 ;
struct V_47 * V_48 ;
struct V_47 T_4 * * V_58 ;
struct V_1 V_95 ;
unsigned long V_227 ;
unsigned long V_161 = V_63 ;
unsigned int V_233 = F_128 ( V_29 ) ;
const struct V_19 * V_70 = NULL ;
bool V_237 ;
int V_66 = 0 ;
F_29 ( & V_27 -> V_50 ) ;
if ( ! F_30 ( V_27 -> V_51 ) ||
( V_60 && V_60 -> V_162 == V_163 ) )
goto V_53;
if ( V_29 -> V_42 == V_233 + sizeof( * V_236 ) ) {
if ( ! F_129 ( V_29 , V_233 + sizeof( * V_236 ) ) ) {
V_66 = - V_46 ;
goto V_53;
}
V_236 = (struct V_119 * ) F_72 ( V_29 ) ;
V_227 = F_148 ( F_76 ( V_236 -> V_136 ) ) ;
if ( V_227 )
V_70 = & V_236 -> V_138 ;
} else {
if ( ! F_129 ( V_29 , V_233 + sizeof( * V_115 ) ) ) {
V_66 = - V_46 ;
goto V_53;
}
V_115 = (struct V_114 * ) F_72 ( V_29 ) ;
if ( ! V_115 -> V_147 )
V_70 = & V_115 -> V_149 ;
V_227 = V_18 ( F_148 ( F_149 ( V_115 ) ) , 1UL ) ;
}
V_237 = V_70 && F_71 ( V_70 ) ;
if ( V_237 ) {
V_95 . V_4 = F_2 ( V_10 ) ;
V_95 . V_7 . V_11 = V_118 -> V_95 ;
F_143 ( V_27 , V_60 , & V_27 -> V_191 ,
& V_95 , V_227 ) ;
goto V_53;
} else if ( ! V_70 ) {
goto V_53;
}
V_23 = F_14 ( F_32 ( V_27 -> V_13 , V_27 ) , V_70 , V_5 ) ;
if ( ! V_23 )
goto V_53;
V_227 *= V_27 -> V_234 ;
if ( V_23 -> V_54 &&
( F_31 ( & V_23 -> V_52 ) ?
F_146 ( V_23 -> V_52 . V_235 , V_161 + V_227 ) :
F_121 ( & V_23 -> V_52 ) >= 0 ) )
F_42 ( & V_23 -> V_52 , V_161 + V_227 ) ;
for ( V_58 = & V_23 -> V_55 ;
( V_48 = F_32 ( * V_58 , V_27 ) ) != NULL ;
V_58 = & V_48 -> V_59 ) {
if ( F_31 ( & V_48 -> V_52 ) ?
F_146 ( V_48 -> V_52 . V_235 , V_161 + V_227 ) :
F_121 ( & V_48 -> V_52 ) >= 0 )
F_42 ( & V_48 -> V_52 , V_161 + V_227 ) ;
}
V_53:
F_35 ( & V_27 -> V_50 ) ;
return V_66 ;
}
static void
F_150 ( struct V_26 * V_27 ,
struct V_150 * V_60 ,
struct V_1 * V_70 ,
struct V_187 * V_188 ,
struct V_175 * V_186 )
{
struct V_12 * V_13 ;
struct V_20 * V_23 ;
struct V_47 * V_48 ;
unsigned long V_161 ;
unsigned long time ;
F_29 ( & V_27 -> V_50 ) ;
if ( ! F_30 ( V_27 -> V_51 ) ||
( V_60 && V_60 -> V_162 == V_163 ) )
goto V_53;
V_13 = F_32 ( V_27 -> V_13 , V_27 ) ;
V_23 = F_12 ( V_13 , V_70 ) ;
if ( ! V_23 )
goto V_53;
if ( V_60 && ( V_60 -> V_62 & V_238 ) ) {
struct V_47 T_4 * * V_58 ;
for ( V_58 = & V_23 -> V_55 ;
( V_48 = F_32 ( * V_58 , V_27 ) ) != NULL ;
V_58 = & V_48 -> V_59 ) {
if ( V_48 -> V_60 != V_60 )
continue;
F_38 ( * V_58 , V_48 -> V_59 ) ;
F_39 ( & V_48 -> V_54 ) ;
F_40 ( & V_48 -> V_52 ) ;
F_34 ( & V_48 -> V_36 , F_26 ) ;
F_41 ( V_27 -> V_51 , V_60 , V_70 , V_61 ,
V_48 -> V_62 ) ;
if ( ! V_23 -> V_55 && ! V_23 -> V_54 &&
F_30 ( V_27 -> V_51 ) )
F_42 ( & V_23 -> V_52 , V_63 ) ;
}
goto V_53;
}
if ( F_31 ( & V_188 -> V_52 ) )
goto V_53;
if ( V_27 -> V_189 ) {
F_104 ( V_27 , V_60 , & V_23 -> V_24 ) ;
time = V_63 + V_27 -> V_234 *
V_27 -> V_102 ;
F_42 ( & V_186 -> V_52 , time ) ;
for ( V_48 = F_32 ( V_23 -> V_55 , V_27 ) ;
V_48 != NULL ;
V_48 = F_32 ( V_48 -> V_59 , V_27 ) ) {
if ( V_48 -> V_60 != V_60 )
continue;
if ( ! F_44 ( & V_48 -> V_54 ) &&
( F_31 ( & V_48 -> V_52 ) ?
F_146 ( V_48 -> V_52 . V_235 , time ) :
F_121 ( & V_48 -> V_52 ) >= 0 ) ) {
F_42 ( & V_48 -> V_52 , time ) ;
}
break;
}
}
V_161 = V_63 ;
time = V_161 + V_27 -> V_234 *
V_27 -> V_102 ;
if ( ! V_60 ) {
if ( V_23 -> V_54 &&
( F_31 ( & V_23 -> V_52 ) ?
F_146 ( V_23 -> V_52 . V_235 , time ) :
F_121 ( & V_23 -> V_52 ) >= 0 ) ) {
F_42 ( & V_23 -> V_52 , time ) ;
}
goto V_53;
}
for ( V_48 = F_32 ( V_23 -> V_55 , V_27 ) ;
V_48 != NULL ;
V_48 = F_32 ( V_48 -> V_59 , V_27 ) ) {
if ( V_48 -> V_60 != V_60 )
continue;
if ( ! F_44 ( & V_48 -> V_54 ) &&
( F_31 ( & V_48 -> V_52 ) ?
F_146 ( V_48 -> V_52 . V_235 , time ) :
F_121 ( & V_48 -> V_52 ) >= 0 ) ) {
F_42 ( & V_48 -> V_52 , time ) ;
}
break;
}
V_53:
F_35 ( & V_27 -> V_50 ) ;
}
static void F_130 ( struct V_26 * V_27 ,
struct V_150 * V_60 ,
T_1 V_70 ,
T_2 V_5 )
{
struct V_1 V_167 ;
struct V_175 * V_186 ;
if ( F_92 ( V_70 ) )
return;
V_186 = V_60 ? & V_60 -> V_177 : & V_27 -> V_177 ;
V_167 . V_7 . V_8 = V_70 ;
V_167 . V_4 = F_2 ( V_6 ) ;
V_167 . V_5 = V_5 ;
F_150 ( V_27 , V_60 , & V_167 , & V_27 -> V_190 ,
V_186 ) ;
}
static void F_134 ( struct V_26 * V_27 ,
struct V_150 * V_60 ,
const struct V_19 * V_70 ,
T_2 V_5 )
{
struct V_1 V_167 ;
struct V_175 * V_186 ;
if ( F_94 ( V_70 ) )
return;
V_186 = V_60 ? & V_60 -> V_178 : & V_27 -> V_178 ;
V_167 . V_7 . V_11 = * V_70 ;
V_167 . V_4 = F_2 ( V_10 ) ;
V_167 . V_5 = V_5 ;
F_150 ( V_27 , V_60 , & V_167 , & V_27 -> V_191 ,
V_186 ) ;
}
static void F_151 ( const struct V_26 * V_27 ,
const struct V_150 * V_48 ,
T_7 V_4 )
{
struct V_197 T_8 * V_239 ;
struct V_197 * V_240 ;
if ( ! V_27 -> V_241 )
return;
if ( V_48 )
V_239 = V_48 -> V_196 ;
else
V_239 = V_27 -> V_196 ;
if ( F_37 ( ! V_239 ) )
return;
V_240 = F_152 ( V_239 ) ;
F_153 ( & V_240 -> V_242 ) ;
switch ( V_4 ) {
case F_2 ( V_6 ) :
V_240 -> V_243 . V_244 ++ ;
break;
#if F_3 ( V_9 )
case F_2 ( V_10 ) :
V_240 -> V_243 . V_245 ++ ;
break;
#endif
}
F_154 ( & V_240 -> V_242 ) ;
}
static void F_155 ( struct V_26 * V_27 ,
struct V_150 * V_60 ,
const struct V_28 * V_29 )
{
unsigned int V_233 = F_128 ( V_29 ) ;
struct V_246 * V_246 , V_247 ;
V_246 = F_132 ( V_29 , V_233 , sizeof( V_247 ) , & V_247 ) ;
if ( ! V_246 || F_156 ( V_246 ) != V_248 ||
F_157 ( V_246 ) != V_249 )
return;
F_142 ( V_27 , V_60 ) ;
}
static int F_158 ( struct V_26 * V_27 ,
struct V_150 * V_60 ,
struct V_28 * V_29 ,
T_3 V_5 )
{
struct V_28 * V_250 = NULL ;
struct V_75 * V_76 ;
int V_66 ;
V_66 = F_159 ( V_29 , & V_250 ) ;
if ( V_66 == - V_251 ) {
if ( ! F_92 ( F_18 ( V_29 ) -> V_33 ) ) {
F_17 ( V_29 ) -> V_252 = 1 ;
} else if ( F_160 ( F_18 ( V_29 ) -> V_33 ) ) {
if ( F_18 ( V_29 ) -> V_32 == V_253 )
F_155 ( V_27 , V_60 , V_29 ) ;
}
return 0 ;
} else if ( V_66 < 0 ) {
F_151 ( V_27 , V_60 , V_29 -> V_32 ) ;
return V_66 ;
}
V_76 = F_61 ( V_29 ) ;
F_17 ( V_29 ) -> V_31 = V_76 -> type ;
switch ( V_76 -> type ) {
case V_254 :
case V_255 :
F_17 ( V_29 ) -> V_252 = 1 ;
V_66 = F_91 ( V_27 , V_60 , V_76 -> V_70 , V_5 ) ;
break;
case V_256 :
V_66 = F_126 ( V_27 , V_60 , V_250 , V_5 ) ;
break;
case V_100 :
V_66 = F_144 ( V_27 , V_60 , V_250 , V_5 ) ;
break;
case V_257 :
F_130 ( V_27 , V_60 , V_76 -> V_70 , V_5 ) ;
break;
}
if ( V_250 && V_250 != V_29 )
F_69 ( V_250 ) ;
F_105 ( V_27 , V_60 , V_29 , F_17 ( V_29 ) -> V_31 ,
V_185 ) ;
return V_66 ;
}
static int F_161 ( struct V_26 * V_27 ,
struct V_150 * V_60 ,
struct V_28 * V_29 ,
T_3 V_5 )
{
struct V_28 * V_250 = NULL ;
struct V_119 * V_236 ;
int V_66 ;
V_66 = F_162 ( V_29 , & V_250 ) ;
if ( V_66 == - V_251 ) {
if ( ! F_94 ( & F_19 ( V_29 ) -> V_33 ) )
F_17 ( V_29 ) -> V_252 = 1 ;
return 0 ;
} else if ( V_66 < 0 ) {
F_151 ( V_27 , V_60 , V_29 -> V_32 ) ;
return V_66 ;
}
V_236 = (struct V_119 * ) F_163 ( V_29 ) ;
F_17 ( V_29 ) -> V_31 = V_236 -> V_133 ;
switch ( V_236 -> V_133 ) {
case V_258 :
F_17 ( V_29 ) -> V_252 = 1 ;
V_66 = F_93 ( V_27 , V_60 , & V_236 -> V_138 , V_5 ) ;
break;
case V_259 :
V_66 = F_131 ( V_27 , V_60 , V_250 , V_5 ) ;
break;
case V_132 :
V_66 = F_147 ( V_27 , V_60 , V_250 , V_5 ) ;
break;
case V_260 :
F_134 ( V_27 , V_60 , & V_236 -> V_138 , V_5 ) ;
break;
}
if ( V_250 && V_250 != V_29 )
F_69 ( V_250 ) ;
F_105 ( V_27 , V_60 , V_29 , F_17 ( V_29 ) -> V_31 ,
V_185 ) ;
return V_66 ;
}
int F_164 ( struct V_26 * V_27 , struct V_150 * V_60 ,
struct V_28 * V_29 , T_3 V_5 )
{
int V_261 = 0 ;
F_17 ( V_29 ) -> V_31 = 0 ;
F_17 ( V_29 ) -> V_252 = 0 ;
if ( V_27 -> V_30 )
return 0 ;
switch ( V_29 -> V_32 ) {
case F_2 ( V_6 ) :
V_261 = F_158 ( V_27 , V_60 , V_29 , V_5 ) ;
break;
#if F_3 ( V_9 )
case F_2 ( V_10 ) :
V_261 = F_161 ( V_27 , V_60 , V_29 , V_5 ) ;
break;
#endif
}
return V_261 ;
}
static void F_165 ( struct V_26 * V_27 ,
struct V_175 * V_176 ,
struct V_262 * V_263 )
{
F_29 ( & V_27 -> V_50 ) ;
if ( V_176 -> V_192 < V_27 -> V_193 )
V_176 -> V_192 ++ ;
F_166 ( V_263 -> V_60 , NULL ) ;
F_108 ( V_27 , NULL , V_176 ) ;
F_35 ( & V_27 -> V_50 ) ;
}
static void F_167 ( unsigned long V_49 )
{
struct V_26 * V_27 = ( void * ) V_49 ;
F_165 ( V_27 , & V_27 -> V_177 , & V_27 -> V_179 ) ;
}
static void F_168 ( unsigned long V_49 )
{
struct V_26 * V_27 = ( void * ) V_49 ;
F_165 ( V_27 , & V_27 -> V_178 , & V_27 -> V_180 ) ;
}
void F_169 ( struct V_26 * V_27 )
{
V_27 -> V_152 = 4 ;
V_27 -> V_154 = 512 ;
V_27 -> V_168 = V_174 ;
V_27 -> V_189 = 0 ;
V_27 -> V_96 = 0 ;
V_27 -> V_234 = 2 ;
V_27 -> V_193 = 2 ;
V_27 -> V_102 = V_104 ;
V_27 -> V_103 = 10 * V_104 ;
V_27 -> V_194 = 125 * V_104 / 4 ;
V_27 -> V_108 = 125 * V_104 ;
V_27 -> V_229 = 255 * V_104 ;
V_27 -> V_164 = 260 * V_104 ;
V_27 -> V_190 . V_228 = 0 ;
V_27 -> V_179 . V_60 = NULL ;
V_27 -> V_81 = 2 ;
#if F_3 ( V_9 )
V_27 -> V_123 = 1 ;
V_27 -> V_191 . V_228 = 0 ;
V_27 -> V_180 . V_60 = NULL ;
#endif
V_27 -> V_128 = 1 ;
F_170 ( & V_27 -> V_50 ) ;
F_86 ( & V_27 -> V_171 ,
F_98 , 0 ) ;
F_86 ( & V_27 -> V_190 . V_52 ,
F_101 , ( unsigned long ) V_27 ) ;
F_86 ( & V_27 -> V_177 . V_52 , F_167 ,
( unsigned long ) V_27 ) ;
#if F_3 ( V_9 )
F_86 ( & V_27 -> V_191 . V_52 ,
F_102 , ( unsigned long ) V_27 ) ;
F_86 ( & V_27 -> V_178 . V_52 , F_168 ,
( unsigned long ) V_27 ) ;
#endif
}
static void F_171 ( struct V_26 * V_27 ,
struct V_175 * V_176 )
{
V_176 -> V_192 = 0 ;
if ( V_27 -> V_30 )
return;
F_42 ( & V_176 -> V_52 , V_63 ) ;
}
void F_172 ( struct V_26 * V_27 )
{
F_171 ( V_27 , & V_27 -> V_177 ) ;
#if F_3 ( V_9 )
F_171 ( V_27 , & V_27 -> V_178 ) ;
#endif
}
void F_173 ( struct V_26 * V_27 )
{
F_118 ( & V_27 -> V_171 ) ;
F_118 ( & V_27 -> V_190 . V_52 ) ;
F_118 ( & V_27 -> V_177 . V_52 ) ;
#if F_3 ( V_9 )
F_118 ( & V_27 -> V_191 . V_52 ) ;
F_118 ( & V_27 -> V_178 . V_52 ) ;
#endif
}
void F_174 ( struct V_26 * V_27 )
{
struct V_12 * V_13 ;
struct V_20 * V_23 ;
struct V_198 * V_199 ;
V_16 V_45 ;
int V_43 ;
F_115 ( & V_27 -> V_50 ) ;
V_13 = F_32 ( V_27 -> V_13 , V_27 ) ;
if ( ! V_13 )
goto V_53;
V_27 -> V_13 = NULL ;
V_45 = V_13 -> V_45 ;
for ( V_43 = 0 ; V_43 < V_13 -> V_18 ; V_43 ++ ) {
F_116 (mp, n, &mdb->mhash[i],
hlist[ver]) {
F_40 ( & V_23 -> V_52 ) ;
F_34 ( & V_23 -> V_36 , F_27 ) ;
}
}
if ( V_13 -> V_37 ) {
F_117 ( & V_27 -> V_50 ) ;
F_175 () ;
F_115 ( & V_27 -> V_50 ) ;
F_37 ( V_13 -> V_37 ) ;
}
V_13 -> V_37 = V_13 ;
F_34 ( & V_13 -> V_36 , F_20 ) ;
V_53:
F_117 ( & V_27 -> V_50 ) ;
F_119 ( V_27 -> V_196 ) ;
}
int F_176 ( struct V_26 * V_27 , unsigned long V_264 )
{
int V_66 = - V_46 ;
F_115 ( & V_27 -> V_50 ) ;
switch ( V_264 ) {
case V_169 :
case V_170 :
F_40 ( & V_27 -> V_171 ) ;
case V_174 :
V_27 -> V_168 = V_264 ;
V_66 = 0 ;
break;
}
F_117 ( & V_27 -> V_50 ) ;
return V_66 ;
}
static void F_177 ( struct V_150 * V_48 )
{
if ( F_44 ( & V_48 -> V_172 ) )
return;
F_96 ( & V_48 -> V_172 ) ;
F_97 ( V_48 -> V_27 -> V_51 , V_48 , V_61 ) ;
}
int F_178 ( struct V_150 * V_48 , unsigned long V_264 )
{
struct V_26 * V_27 = V_48 -> V_27 ;
unsigned long V_161 = V_63 ;
int V_66 = - V_46 ;
F_29 ( & V_27 -> V_50 ) ;
if ( V_48 -> V_168 == V_264 ) {
if ( V_48 -> V_168 == V_173 )
F_42 ( & V_48 -> V_171 ,
V_161 + V_27 -> V_229 ) ;
V_66 = 0 ;
goto V_265;
}
switch ( V_264 ) {
case V_169 :
V_48 -> V_168 = V_169 ;
F_177 ( V_48 ) ;
F_40 ( & V_48 -> V_171 ) ;
break;
case V_174 :
V_48 -> V_168 = V_174 ;
F_177 ( V_48 ) ;
break;
case V_170 :
V_48 -> V_168 = V_170 ;
F_40 ( & V_48 -> V_171 ) ;
F_123 ( V_27 , V_48 ) ;
break;
case V_173 :
V_48 -> V_168 = V_173 ;
F_142 ( V_27 , V_48 ) ;
break;
default:
goto V_265;
}
V_66 = 0 ;
V_265:
F_35 ( & V_27 -> V_50 ) ;
return V_66 ;
}
static void F_100 ( struct V_26 * V_27 ,
struct V_175 * V_176 )
{
struct V_150 * V_60 ;
F_171 ( V_27 , V_176 ) ;
F_179 (port, &br->port_list, list) {
if ( V_60 -> V_162 == V_163 ||
V_60 -> V_162 == V_195 )
continue;
if ( V_176 == & V_27 -> V_177 )
F_120 ( & V_60 -> V_177 ) ;
#if F_3 ( V_9 )
else
F_120 ( & V_60 -> V_178 ) ;
#endif
}
}
int F_180 ( struct V_26 * V_27 , unsigned long V_264 )
{
struct V_12 * V_13 ;
struct V_150 * V_60 ;
int V_66 = 0 ;
F_115 ( & V_27 -> V_50 ) ;
if ( V_27 -> V_30 == ! V_264 )
goto V_265;
V_27 -> V_30 = ! V_264 ;
if ( V_27 -> V_30 )
goto V_265;
if ( ! F_30 ( V_27 -> V_51 ) )
goto V_265;
V_13 = F_32 ( V_27 -> V_13 , V_27 ) ;
if ( V_13 ) {
if ( V_13 -> V_37 ) {
V_66 = - V_157 ;
V_266:
V_27 -> V_30 = ! ! V_264 ;
goto V_265;
}
V_66 = F_45 ( & V_27 -> V_13 , V_13 -> V_18 ,
V_27 -> V_152 ) ;
if ( V_66 )
goto V_266;
}
F_172 ( V_27 ) ;
F_179 (port, &br->port_list, list)
F_122 ( V_60 ) ;
V_265:
F_117 ( & V_27 -> V_50 ) ;
return V_66 ;
}
int F_181 ( struct V_26 * V_27 , unsigned long V_264 )
{
unsigned long V_227 ;
V_264 = ! ! V_264 ;
F_115 ( & V_27 -> V_50 ) ;
if ( V_27 -> V_189 == V_264 )
goto V_265;
V_27 -> V_189 = V_264 ;
if ( ! V_264 )
goto V_265;
V_227 = V_27 -> V_103 ;
if ( ! F_31 ( & V_27 -> V_190 . V_52 ) )
V_27 -> V_190 . V_228 = V_63 + V_227 ;
F_100 ( V_27 , & V_27 -> V_177 ) ;
#if F_3 ( V_9 )
if ( ! F_31 ( & V_27 -> V_191 . V_52 ) )
V_27 -> V_191 . V_228 = V_63 + V_227 ;
F_100 ( V_27 , & V_27 -> V_178 ) ;
#endif
V_265:
F_117 ( & V_27 -> V_50 ) ;
return 0 ;
}
int F_182 ( struct V_26 * V_27 , unsigned long V_264 )
{
int V_66 = - V_46 ;
V_16 V_37 ;
struct V_12 * V_13 ;
F_115 ( & V_27 -> V_50 ) ;
if ( ! F_183 ( V_264 ) )
goto V_265;
V_13 = F_32 ( V_27 -> V_13 , V_27 ) ;
if ( V_13 && V_264 < V_13 -> V_56 )
goto V_265;
V_66 = 0 ;
V_37 = V_27 -> V_154 ;
V_27 -> V_154 = V_264 ;
if ( V_13 ) {
if ( V_13 -> V_37 ) {
V_66 = - V_157 ;
V_266:
V_27 -> V_154 = V_37 ;
goto V_265;
}
V_66 = F_45 ( & V_27 -> V_13 , V_27 -> V_154 ,
V_27 -> V_152 ) ;
if ( V_66 )
goto V_266;
}
V_265:
F_117 ( & V_27 -> V_50 ) ;
return V_66 ;
}
int F_184 ( struct V_26 * V_27 , unsigned long V_264 )
{
switch ( V_264 ) {
case 2 :
case 3 :
break;
default:
return - V_46 ;
}
F_115 ( & V_27 -> V_50 ) ;
V_27 -> V_81 = V_264 ;
F_117 ( & V_27 -> V_50 ) ;
return 0 ;
}
int F_185 ( struct V_26 * V_27 , unsigned long V_264 )
{
switch ( V_264 ) {
case 1 :
case 2 :
break;
default:
return - V_46 ;
}
F_115 ( & V_27 -> V_50 ) ;
V_27 -> V_123 = V_264 ;
F_117 ( & V_27 -> V_50 ) ;
return 0 ;
}
int F_186 ( struct V_267 * V_51 ,
struct V_268 * V_269 )
{
struct V_26 * V_27 ;
struct V_150 * V_60 ;
struct V_47 * V_70 ;
struct V_269 * V_270 ;
int V_151 = 0 ;
F_187 () ;
if ( ! V_269 || ! F_188 ( V_51 ) )
goto V_265;
V_60 = F_189 ( V_51 ) ;
if ( ! V_60 || ! V_60 -> V_27 )
goto V_265;
V_27 = V_60 -> V_27 ;
F_190 (port, &br->port_list, list) {
if ( ! V_60 -> V_51 || V_60 -> V_51 == V_51 )
continue;
F_11 (group, &port->mglist, mglist) {
V_270 = F_47 ( sizeof( * V_270 ) , V_67 ) ;
if ( ! V_270 )
goto V_265;
V_270 -> V_24 = V_70 -> V_24 ;
F_191 ( & V_270 -> V_271 , V_269 ) ;
V_151 ++ ;
}
}
V_265:
F_192 () ;
return V_151 ;
}
bool F_193 ( struct V_267 * V_51 , int V_4 )
{
struct V_26 * V_27 ;
struct V_150 * V_60 ;
struct V_77 V_78 ;
bool V_261 = false ;
F_187 () ;
if ( ! F_188 ( V_51 ) )
goto V_265;
V_60 = F_189 ( V_51 ) ;
if ( ! V_60 || ! V_60 -> V_27 )
goto V_265;
V_27 = V_60 -> V_27 ;
memset ( & V_78 , 0 , sizeof( V_78 ) ) ;
V_78 . V_85 = F_2 ( V_4 ) ;
V_261 = F_194 ( V_27 , & V_78 ) ;
V_265:
F_192 () ;
return V_261 ;
}
bool F_195 ( struct V_267 * V_51 , int V_4 )
{
struct V_26 * V_27 ;
struct V_150 * V_60 ;
bool V_261 = false ;
F_187 () ;
if ( ! F_188 ( V_51 ) )
goto V_265;
V_60 = F_189 ( V_51 ) ;
if ( ! V_60 || ! V_60 -> V_27 )
goto V_265;
V_27 = V_60 -> V_27 ;
switch ( V_4 ) {
case V_6 :
if ( ! F_31 ( & V_27 -> V_190 . V_52 ) ||
F_16 ( V_27 -> V_179 . V_60 ) == V_60 )
goto V_265;
break;
#if F_3 ( V_9 )
case V_10 :
if ( ! F_31 ( & V_27 -> V_191 . V_52 ) ||
F_16 ( V_27 -> V_180 . V_60 ) == V_60 )
goto V_265;
break;
#endif
default:
goto V_265;
}
V_261 = true ;
V_265:
F_192 () ;
return V_261 ;
}
static void F_196 ( struct V_197 T_8 * V_239 ,
const struct V_28 * V_29 , T_5 type , T_5 V_272 )
{
struct V_197 * V_240 = F_152 ( V_239 ) ;
T_7 V_4 = V_29 -> V_32 ;
unsigned int V_273 ;
F_153 ( & V_240 -> V_242 ) ;
switch ( V_4 ) {
case F_2 ( V_6 ) :
V_273 = F_76 ( F_18 ( V_29 ) -> V_89 ) - F_197 ( V_29 ) ;
switch ( type ) {
case V_254 :
V_240 -> V_243 . V_274 [ V_272 ] ++ ;
break;
case V_255 :
V_240 -> V_243 . V_275 [ V_272 ] ++ ;
break;
case V_256 :
V_240 -> V_243 . V_276 [ V_272 ] ++ ;
break;
case V_100 :
if ( V_273 != sizeof( struct V_75 ) ) {
V_240 -> V_243 . V_277 [ V_272 ] ++ ;
} else {
unsigned int V_233 = F_128 ( V_29 ) ;
struct V_75 * V_76 , V_278 ;
V_76 = F_132 ( V_29 , V_233 ,
sizeof( V_278 ) , & V_278 ) ;
if ( ! V_76 )
break;
if ( ! V_76 -> V_101 )
V_240 -> V_243 . V_279 [ V_272 ] ++ ;
else
V_240 -> V_243 . V_280 [ V_272 ] ++ ;
}
break;
case V_257 :
V_240 -> V_243 . V_281 [ V_272 ] ++ ;
break;
}
break;
#if F_3 ( V_9 )
case F_2 ( V_10 ) :
V_273 = F_76 ( F_19 ( V_29 ) -> V_124 ) +
sizeof( struct V_117 ) ;
V_273 -= F_198 ( V_29 ) ;
switch ( type ) {
case V_258 :
V_240 -> V_243 . V_282 [ V_272 ] ++ ;
break;
case V_259 :
V_240 -> V_243 . V_283 [ V_272 ] ++ ;
break;
case V_132 :
if ( V_273 != sizeof( struct V_119 ) )
V_240 -> V_243 . V_284 [ V_272 ] ++ ;
else
V_240 -> V_243 . V_285 [ V_272 ] ++ ;
break;
case V_260 :
V_240 -> V_243 . V_286 [ V_272 ] ++ ;
break;
}
break;
#endif
}
F_154 ( & V_240 -> V_242 ) ;
}
void F_105 ( struct V_26 * V_27 , const struct V_150 * V_48 ,
const struct V_28 * V_29 , T_5 type , T_5 V_272 )
{
struct V_197 T_8 * V_239 ;
if ( ! type || ! V_27 -> V_241 )
return;
if ( V_48 )
V_239 = V_48 -> V_196 ;
else
V_239 = V_27 -> V_196 ;
if ( F_37 ( ! V_239 ) )
return;
F_196 ( V_239 , V_29 , type , V_272 ) ;
}
int F_199 ( struct V_26 * V_27 )
{
V_27 -> V_196 = F_113 ( struct V_197 ) ;
if ( ! V_27 -> V_196 )
return - V_68 ;
return 0 ;
}
static void F_200 ( T_9 * V_21 , T_9 * V_287 )
{
V_21 [ V_185 ] += V_287 [ V_185 ] ;
V_21 [ V_181 ] += V_287 [ V_181 ] ;
}
void F_201 ( const struct V_26 * V_27 ,
const struct V_150 * V_48 ,
struct V_288 * V_289 )
{
struct V_197 T_8 * V_239 ;
struct V_288 V_290 ;
int V_43 ;
memset ( V_289 , 0 , sizeof( * V_289 ) ) ;
if ( V_48 )
V_239 = V_48 -> V_196 ;
else
V_239 = V_27 -> V_196 ;
if ( F_37 ( ! V_239 ) )
return;
memset ( & V_290 , 0 , sizeof( V_290 ) ) ;
F_202 (i) {
struct V_197 * V_291 = F_203 ( V_239 , V_43 ) ;
struct V_288 V_292 ;
unsigned int V_293 ;
do {
V_293 = F_204 ( & V_291 -> V_242 ) ;
memcpy ( & V_292 , & V_291 -> V_243 , sizeof( V_292 ) ) ;
} while ( F_205 ( & V_291 -> V_242 , V_293 ) );
F_200 ( V_290 . V_279 , V_292 . V_279 ) ;
F_200 ( V_290 . V_280 , V_292 . V_280 ) ;
F_200 ( V_290 . V_277 , V_292 . V_277 ) ;
F_200 ( V_290 . V_281 , V_292 . V_281 ) ;
F_200 ( V_290 . V_274 , V_292 . V_274 ) ;
F_200 ( V_290 . V_275 , V_292 . V_275 ) ;
F_200 ( V_290 . V_276 , V_292 . V_276 ) ;
V_290 . V_244 += V_292 . V_244 ;
F_200 ( V_290 . V_285 , V_292 . V_285 ) ;
F_200 ( V_290 . V_284 , V_292 . V_284 ) ;
F_200 ( V_290 . V_286 , V_292 . V_286 ) ;
F_200 ( V_290 . V_282 , V_292 . V_282 ) ;
F_200 ( V_290 . V_283 , V_292 . V_283 ) ;
V_290 . V_245 += V_292 . V_245 ;
}
memcpy ( V_289 , & V_290 , sizeof( * V_289 ) ) ;
}
