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
V_115 -> V_139 = F_2 ( ( T_3 ) F_73 ( V_116 ) ) ;
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
static struct V_28 * F_76 ( struct V_26 * V_27 ,
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
static struct V_20 * F_77 (
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
if ( F_78 ( F_1 ( V_70 , & V_23 -> V_24 ) ) )
return V_23 ;
}
V_40 = 0 ;
V_18 = V_13 -> V_18 ;
if ( F_78 ( V_151 > V_27 -> V_152 && V_151 ) ) {
if ( F_79 () )
F_80 ( V_27 , L_1
L_2 ,
V_60 ? V_60 -> V_51 -> V_153 : V_27 -> V_51 -> V_153 ) ;
V_40 = V_27 -> V_152 ;
}
if ( V_13 -> V_56 >= V_18 ) {
V_18 *= 2 ;
if ( F_78 ( V_18 > V_27 -> V_154 ) ) {
F_81 ( V_27 , L_3
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
if ( F_79 () )
F_80 ( V_27 , L_1
L_5 ,
V_60 ? V_60 -> V_51 -> V_153 : V_27 -> V_51 -> V_153 ) ;
V_66 = - V_157 ;
goto V_66;
}
V_66 = F_45 ( & V_27 -> V_13 , V_18 , V_40 ) ;
if ( V_66 ) {
F_81 ( V_27 , L_6
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
V_23 = F_82 ( V_66 ) ;
return V_23 ;
}
struct V_20 * F_83 ( struct V_26 * V_27 ,
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
return F_82 ( V_66 ) ;
goto V_160;
}
V_22 = F_9 ( V_13 , V_70 ) ;
V_23 = F_77 ( V_27 , V_48 , V_70 , V_22 ) ;
switch ( F_84 ( V_23 ) ) {
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
if ( F_78 ( ! V_23 ) )
return F_82 ( - V_68 ) ;
V_23 -> V_27 = V_27 ;
V_23 -> V_24 = * V_70 ;
F_85 ( & V_23 -> V_52 , F_28 ,
( unsigned long ) V_23 ) ;
F_86 ( & V_23 -> V_44 [ V_13 -> V_45 ] , & V_13 -> V_38 [ V_22 ] ) ;
V_13 -> V_56 ++ ;
V_53:
return V_23 ;
}
struct V_47 * F_87 (
struct V_150 * V_60 ,
struct V_1 * V_70 ,
struct V_47 T_4 * V_59 ,
unsigned char V_62 ,
const unsigned char * V_161 )
{
struct V_47 * V_48 ;
V_48 = F_48 ( sizeof( * V_48 ) , V_67 ) ;
if ( F_78 ( ! V_48 ) )
return NULL ;
V_48 -> V_24 = * V_70 ;
V_48 -> V_60 = V_60 ;
V_48 -> V_62 = V_62 ;
F_38 ( V_48 -> V_59 , V_59 ) ;
F_25 ( & V_48 -> V_54 , & V_60 -> V_54 ) ;
F_85 ( & V_48 -> V_52 , F_43 ,
( unsigned long ) V_48 ) ;
if ( V_161 )
memcpy ( V_48 -> V_162 , V_161 , V_163 ) ;
else
memset ( V_48 -> V_162 , 0xff , V_163 ) ;
return V_48 ;
}
static bool F_88 ( struct V_47 * V_48 ,
struct V_150 * V_60 ,
const unsigned char * V_161 )
{
if ( V_48 -> V_60 != V_60 )
return false ;
if ( ! ( V_60 -> V_62 & V_164 ) )
return true ;
return F_89 ( V_161 , V_48 -> V_162 ) ;
}
static int F_90 ( struct V_26 * V_27 ,
struct V_150 * V_60 ,
struct V_1 * V_70 ,
const unsigned char * V_161 )
{
struct V_47 T_4 * * V_58 ;
struct V_47 * V_48 ;
struct V_20 * V_23 ;
unsigned long V_165 = V_63 ;
int V_66 ;
F_29 ( & V_27 -> V_50 ) ;
if ( ! F_30 ( V_27 -> V_51 ) ||
( V_60 && V_60 -> V_166 == V_167 ) )
goto V_53;
V_23 = F_83 ( V_27 , V_60 , V_70 ) ;
V_66 = F_84 ( V_23 ) ;
if ( F_91 ( V_23 ) )
goto V_66;
if ( ! V_60 ) {
V_23 -> V_54 = true ;
F_42 ( & V_23 -> V_52 , V_165 + V_27 -> V_168 ) ;
goto V_53;
}
for ( V_58 = & V_23 -> V_55 ;
( V_48 = F_32 ( * V_58 , V_27 ) ) != NULL ;
V_58 = & V_48 -> V_59 ) {
if ( F_88 ( V_48 , V_60 , V_161 ) )
goto V_169;
if ( ( unsigned long ) V_48 -> V_60 < ( unsigned long ) V_60 )
break;
}
V_48 = F_87 ( V_60 , V_70 , * V_58 , 0 , V_161 ) ;
if ( F_78 ( ! V_48 ) )
goto V_66;
F_38 ( * V_58 , V_48 ) ;
F_41 ( V_27 -> V_51 , V_60 , V_70 , V_170 , 0 ) ;
V_169:
F_42 ( & V_48 -> V_52 , V_165 + V_27 -> V_168 ) ;
V_53:
V_66 = 0 ;
V_66:
F_35 ( & V_27 -> V_50 ) ;
return V_66 ;
}
static int F_92 ( struct V_26 * V_27 ,
struct V_150 * V_60 ,
T_1 V_70 ,
T_2 V_5 ,
const unsigned char * V_161 )
{
struct V_1 V_171 ;
if ( F_93 ( V_70 ) )
return 0 ;
V_171 . V_7 . V_8 = V_70 ;
V_171 . V_4 = F_2 ( V_6 ) ;
V_171 . V_5 = V_5 ;
return F_90 ( V_27 , V_60 , & V_171 , V_161 ) ;
}
static int F_94 ( struct V_26 * V_27 ,
struct V_150 * V_60 ,
const struct V_19 * V_70 ,
T_2 V_5 ,
const unsigned char * V_161 )
{
struct V_1 V_171 ;
if ( F_95 ( V_70 ) )
return 0 ;
V_171 . V_7 . V_11 = * V_70 ;
V_171 . V_4 = F_2 ( V_10 ) ;
V_171 . V_5 = V_5 ;
return F_90 ( V_27 , V_60 , & V_171 , V_161 ) ;
}
static void F_96 ( unsigned long V_49 )
{
struct V_150 * V_60 = ( void * ) V_49 ;
struct V_26 * V_27 = V_60 -> V_27 ;
F_29 ( & V_27 -> V_50 ) ;
if ( V_60 -> V_172 == V_173 ||
V_60 -> V_172 == V_174 ||
F_31 ( & V_60 -> V_175 ) )
goto V_53;
F_97 ( V_60 ) ;
V_53:
F_35 ( & V_27 -> V_50 ) ;
}
static void F_98 ( unsigned long V_49 )
{
}
static void F_99 ( struct V_26 * V_27 ,
struct V_176 * V_177 )
{
F_29 ( & V_27 -> V_50 ) ;
if ( ! F_30 ( V_27 -> V_51 ) || V_27 -> V_30 )
goto V_53;
F_100 ( V_27 , V_177 ) ;
V_53:
F_35 ( & V_27 -> V_50 ) ;
}
static void F_101 ( unsigned long V_49 )
{
struct V_26 * V_27 = ( void * ) V_49 ;
F_99 ( V_27 , & V_27 -> V_178 ) ;
}
static void F_102 ( unsigned long V_49 )
{
struct V_26 * V_27 = ( void * ) V_49 ;
F_99 ( V_27 , & V_27 -> V_179 ) ;
}
static void F_103 ( struct V_26 * V_27 ,
struct V_1 * V_14 ,
struct V_28 * V_29 )
{
if ( V_14 -> V_4 == F_2 ( V_6 ) )
V_27 -> V_180 . V_24 . V_7 . V_8 = F_18 ( V_29 ) -> V_95 ;
#if F_3 ( V_9 )
else
V_27 -> V_181 . V_24 . V_7 . V_11 = F_19 ( V_29 ) -> V_95 ;
#endif
}
static void F_104 ( struct V_26 * V_27 ,
struct V_150 * V_60 ,
struct V_1 * V_14 )
{
struct V_28 * V_29 ;
T_5 V_71 ;
V_29 = F_76 ( V_27 , V_14 , & V_71 ) ;
if ( ! V_29 )
return;
if ( V_60 ) {
V_29 -> V_51 = V_60 -> V_51 ;
F_105 ( V_27 , V_60 , V_29 , V_71 ,
V_182 ) ;
F_106 ( V_183 , V_184 ,
F_68 ( V_60 -> V_51 ) , NULL , V_29 , NULL , V_29 -> V_51 ,
V_185 ) ;
} else {
F_103 ( V_27 , V_14 , V_29 ) ;
F_105 ( V_27 , V_60 , V_29 , V_71 ,
V_186 ) ;
F_107 ( V_29 ) ;
}
}
static void F_108 ( struct V_26 * V_27 ,
struct V_150 * V_60 ,
struct V_176 * V_187 )
{
struct V_188 * V_189 = NULL ;
struct V_1 V_171 ;
unsigned long time ;
if ( ! F_30 ( V_27 -> V_51 ) || V_27 -> V_30 ||
! V_27 -> V_190 )
return;
memset ( & V_171 . V_7 , 0 , sizeof( V_171 . V_7 ) ) ;
if ( V_60 ? ( V_187 == & V_60 -> V_178 ) :
( V_187 == & V_27 -> V_178 ) ) {
V_189 = & V_27 -> V_191 ;
V_171 . V_4 = F_2 ( V_6 ) ;
#if F_3 ( V_9 )
} else {
V_189 = & V_27 -> V_192 ;
V_171 . V_4 = F_2 ( V_10 ) ;
#endif
}
if ( ! V_189 || F_31 ( & V_189 -> V_52 ) )
return;
F_104 ( V_27 , V_60 , & V_171 ) ;
time = V_63 ;
time += V_187 -> V_193 < V_27 -> V_194 ?
V_27 -> V_195 :
V_27 -> V_108 ;
F_42 ( & V_187 -> V_52 , time ) ;
}
static void
F_109 ( struct V_150 * V_60 ,
struct V_176 * V_177 )
{
struct V_26 * V_27 = V_60 -> V_27 ;
F_29 ( & V_27 -> V_50 ) ;
if ( V_60 -> V_166 == V_167 ||
V_60 -> V_166 == V_196 )
goto V_53;
if ( V_177 -> V_193 < V_27 -> V_194 )
V_177 -> V_193 ++ ;
F_108 ( V_60 -> V_27 , V_60 , V_177 ) ;
V_53:
F_35 ( & V_27 -> V_50 ) ;
}
static void F_110 ( unsigned long V_49 )
{
struct V_150 * V_60 = ( void * ) V_49 ;
F_109 ( V_60 , & V_60 -> V_178 ) ;
}
static void F_111 ( unsigned long V_49 )
{
struct V_150 * V_60 = ( void * ) V_49 ;
F_109 ( V_60 , & V_60 -> V_179 ) ;
}
static void F_112 ( struct V_197 * V_51 , bool V_198 )
{
struct V_199 V_200 = {
. V_201 = V_51 ,
. V_90 = V_202 ,
. V_62 = V_203 ,
. V_7 . V_204 = V_198 ,
} ;
F_113 ( V_51 , & V_200 ) ;
}
int F_114 ( struct V_150 * V_60 )
{
V_60 -> V_172 = V_205 ;
F_85 ( & V_60 -> V_175 , F_96 ,
( unsigned long ) V_60 ) ;
F_85 ( & V_60 -> V_178 . V_52 ,
F_110 , ( unsigned long ) V_60 ) ;
#if F_3 ( V_9 )
F_85 ( & V_60 -> V_179 . V_52 ,
F_111 , ( unsigned long ) V_60 ) ;
#endif
F_112 ( V_60 -> V_51 , V_60 -> V_27 -> V_30 ) ;
V_60 -> V_206 = F_115 ( struct V_207 ) ;
if ( ! V_60 -> V_206 )
return - V_68 ;
return 0 ;
}
void F_116 ( struct V_150 * V_60 )
{
struct V_26 * V_27 = V_60 -> V_27 ;
struct V_47 * V_57 ;
struct V_208 * V_209 ;
F_117 ( & V_27 -> V_50 ) ;
F_118 (pg, n, &port->mglist, mglist)
F_36 ( V_27 , V_57 ) ;
F_119 ( & V_27 -> V_50 ) ;
F_120 ( & V_60 -> V_175 ) ;
F_121 ( V_60 -> V_206 ) ;
}
static void F_122 ( struct V_176 * V_177 )
{
V_177 -> V_193 = 0 ;
if ( F_123 ( & V_177 -> V_52 ) >= 0 ||
F_40 ( & V_177 -> V_52 ) )
F_42 ( & V_177 -> V_52 , V_63 ) ;
}
static void F_124 ( struct V_150 * V_60 )
{
struct V_26 * V_27 = V_60 -> V_27 ;
if ( V_27 -> V_30 || ! F_30 ( V_27 -> V_51 ) )
return;
F_122 ( & V_60 -> V_178 ) ;
#if F_3 ( V_9 )
F_122 ( & V_60 -> V_179 ) ;
#endif
if ( V_60 -> V_172 == V_174 &&
F_44 ( & V_60 -> V_210 ) )
F_125 ( V_27 , V_60 ) ;
}
void F_126 ( struct V_150 * V_60 )
{
struct V_26 * V_27 = V_60 -> V_27 ;
F_29 ( & V_27 -> V_50 ) ;
F_124 ( V_60 ) ;
F_35 ( & V_27 -> V_50 ) ;
}
void F_127 ( struct V_150 * V_60 )
{
struct V_26 * V_27 = V_60 -> V_27 ;
struct V_47 * V_57 ;
struct V_208 * V_209 ;
F_29 ( & V_27 -> V_50 ) ;
F_118 (pg, n, &port->mglist, mglist)
if ( ! ( V_57 -> V_62 & V_64 ) )
F_36 ( V_27 , V_57 ) ;
F_97 ( V_60 ) ;
F_40 ( & V_60 -> V_175 ) ;
F_40 ( & V_60 -> V_178 . V_52 ) ;
#if F_3 ( V_9 )
F_40 ( & V_60 -> V_179 . V_52 ) ;
#endif
F_35 ( & V_27 -> V_50 ) ;
}
static int F_128 ( struct V_26 * V_27 ,
struct V_150 * V_60 ,
struct V_28 * V_29 ,
T_3 V_5 )
{
const unsigned char * V_161 ;
struct V_211 * V_76 ;
struct V_212 * V_213 ;
int V_43 ;
int V_42 ;
int V_214 ;
int type ;
int V_66 = 0 ;
T_1 V_70 ;
V_76 = F_129 ( V_29 ) ;
V_214 = F_130 ( V_76 -> V_215 ) ;
V_42 = F_131 ( V_29 ) + sizeof( * V_76 ) ;
for ( V_43 = 0 ; V_43 < V_214 ; V_43 ++ ) {
V_42 += sizeof( * V_213 ) ;
if ( ! F_132 ( V_29 , V_42 ) )
return - V_46 ;
V_213 = ( void * ) ( V_29 -> V_49 + V_42 - sizeof( * V_213 ) ) ;
V_70 = V_213 -> V_216 ;
type = V_213 -> V_217 ;
V_42 += F_130 ( V_213 -> V_218 ) * 4 ;
if ( ! F_132 ( V_29 , V_42 ) )
return - V_46 ;
switch ( type ) {
case V_219 :
case V_220 :
case V_221 :
case V_222 :
case V_223 :
case V_224 :
break;
default:
continue;
}
V_161 = F_53 ( V_29 ) -> V_82 ;
if ( ( type == V_221 ||
type == V_219 ) &&
F_130 ( V_213 -> V_218 ) == 0 ) {
F_133 ( V_27 , V_60 , V_70 , V_5 , V_161 ) ;
} else {
V_66 = F_92 ( V_27 , V_60 , V_70 , V_5 ,
V_161 ) ;
if ( V_66 )
break;
}
}
return V_66 ;
}
static int F_134 ( struct V_26 * V_27 ,
struct V_150 * V_60 ,
struct V_28 * V_29 ,
T_3 V_5 )
{
const unsigned char * V_161 ;
struct V_225 * V_226 ;
struct V_227 * V_213 ;
int V_43 ;
int V_42 ;
int V_214 ;
int V_66 = 0 ;
if ( ! F_132 ( V_29 , sizeof( * V_226 ) ) )
return - V_46 ;
V_226 = F_72 ( V_29 ) ;
V_214 = F_130 ( V_226 -> V_228 . V_229 [ 1 ] ) ;
V_42 = F_131 ( V_29 ) + sizeof( * V_226 ) ;
for ( V_43 = 0 ; V_43 < V_214 ; V_43 ++ ) {
T_7 * V_109 , V_230 ;
V_109 = F_135 ( V_29 ,
V_42 + F_136 ( struct V_227 ,
V_218 ) ,
sizeof( V_230 ) , & V_230 ) ;
if ( ! V_109 )
return - V_46 ;
if ( ! F_132 ( V_29 ,
V_42 + sizeof( * V_213 ) +
sizeof( struct V_19 ) * F_130 ( * V_109 ) ) )
return - V_46 ;
V_213 = (struct V_227 * ) ( V_29 -> V_49 + V_42 ) ;
V_42 += sizeof( * V_213 ) +
sizeof( struct V_19 ) * F_130 ( * V_109 ) ;
switch ( V_213 -> V_217 ) {
case V_231 :
case V_232 :
case V_233 :
case V_234 :
case V_235 :
case V_236 :
break;
default:
continue;
}
V_161 = F_53 ( V_29 ) -> V_82 ;
if ( ( V_213 -> V_217 == V_233 ||
V_213 -> V_217 == V_231 ) &&
F_130 ( * V_109 ) == 0 ) {
F_137 ( V_27 , V_60 , & V_213 -> V_216 ,
V_5 , V_161 ) ;
} else {
V_66 = F_94 ( V_27 , V_60 ,
& V_213 -> V_216 , V_5 ,
V_161 ) ;
if ( V_66 )
break;
}
}
return V_66 ;
}
static bool F_138 ( struct V_26 * V_27 ,
struct V_150 * V_60 ,
T_1 V_95 )
{
if ( ! F_31 ( & V_27 -> V_178 . V_52 ) &&
! F_31 ( & V_27 -> V_191 . V_52 ) )
goto V_237;
if ( ! V_27 -> V_180 . V_24 . V_7 . V_8 )
goto V_237;
if ( F_139 ( V_95 ) <= F_139 ( V_27 -> V_180 . V_24 . V_7 . V_8 ) )
goto V_237;
return false ;
V_237:
V_27 -> V_180 . V_24 . V_7 . V_8 = V_95 ;
F_38 ( V_27 -> V_180 . V_60 , V_60 ) ;
return true ;
}
static bool F_140 ( struct V_26 * V_27 ,
struct V_150 * V_60 ,
struct V_19 * V_95 )
{
if ( ! F_31 ( & V_27 -> V_179 . V_52 ) &&
! F_31 ( & V_27 -> V_192 . V_52 ) )
goto V_237;
if ( F_141 ( V_95 , & V_27 -> V_181 . V_24 . V_7 . V_11 ) <= 0 )
goto V_237;
return false ;
V_237:
V_27 -> V_181 . V_24 . V_7 . V_11 = * V_95 ;
F_38 ( V_27 -> V_181 . V_60 , V_60 ) ;
return true ;
}
static bool F_142 ( struct V_26 * V_27 ,
struct V_150 * V_60 ,
struct V_1 * V_95 )
{
switch ( V_95 -> V_4 ) {
case F_2 ( V_6 ) :
return F_138 ( V_27 , V_60 , V_95 -> V_7 . V_8 ) ;
#if F_3 ( V_9 )
case F_2 ( V_10 ) :
return F_140 ( V_27 , V_60 , & V_95 -> V_7 . V_11 ) ;
#endif
}
return false ;
}
static void
F_143 ( struct V_26 * V_27 ,
struct V_188 * V_177 ,
unsigned long V_238 )
{
if ( ! F_31 ( & V_177 -> V_52 ) )
V_177 -> V_239 = V_63 + V_238 ;
F_42 ( & V_177 -> V_52 , V_63 + V_27 -> V_240 ) ;
}
static void F_144 ( struct V_150 * V_48 ,
bool V_241 )
{
struct V_199 V_200 = {
. V_201 = V_48 -> V_51 ,
. V_90 = V_242 ,
. V_62 = V_203 ,
. V_7 . V_243 = V_241 ,
} ;
F_113 ( V_48 -> V_51 , & V_200 ) ;
}
static void F_125 ( struct V_26 * V_27 ,
struct V_150 * V_60 )
{
struct V_150 * V_48 ;
struct V_208 * V_244 = NULL ;
if ( ! F_44 ( & V_60 -> V_210 ) )
return;
F_24 (p, &br->router_list, rlist) {
if ( ( unsigned long ) V_60 >= ( unsigned long ) V_48 )
break;
V_244 = & V_48 -> V_210 ;
}
if ( V_244 )
F_145 ( & V_60 -> V_210 , V_244 ) ;
else
F_86 ( & V_60 -> V_210 , & V_27 -> V_245 ) ;
F_146 ( V_27 -> V_51 , V_60 , V_170 ) ;
F_144 ( V_60 , true ) ;
}
static void F_147 ( struct V_26 * V_27 ,
struct V_150 * V_60 )
{
unsigned long V_165 = V_63 ;
if ( ! V_60 ) {
if ( V_27 -> V_172 == V_205 )
F_42 ( & V_27 -> V_175 ,
V_165 + V_27 -> V_240 ) ;
return;
}
if ( V_60 -> V_172 == V_173 ||
V_60 -> V_172 == V_174 )
return;
F_125 ( V_27 , V_60 ) ;
F_42 ( & V_60 -> V_175 ,
V_165 + V_27 -> V_240 ) ;
}
static void F_148 ( struct V_26 * V_27 ,
struct V_150 * V_60 ,
struct V_188 * V_177 ,
struct V_1 * V_95 ,
unsigned long V_238 )
{
if ( ! F_142 ( V_27 , V_60 , V_95 ) )
return;
F_143 ( V_27 , V_177 , V_238 ) ;
F_147 ( V_27 , V_60 ) ;
}
static int F_149 ( struct V_26 * V_27 ,
struct V_150 * V_60 ,
struct V_28 * V_29 ,
T_3 V_5 )
{
const struct V_79 * V_80 = F_18 ( V_29 ) ;
struct V_75 * V_76 = F_61 ( V_29 ) ;
struct V_20 * V_23 ;
struct V_72 * V_246 ;
struct V_47 * V_48 ;
struct V_47 T_4 * * V_58 ;
struct V_1 V_95 ;
unsigned long V_238 ;
unsigned long V_165 = V_63 ;
unsigned int V_247 = F_131 ( V_29 ) ;
T_1 V_70 ;
int V_66 = 0 ;
F_29 ( & V_27 -> V_50 ) ;
if ( ! F_30 ( V_27 -> V_51 ) ||
( V_60 && V_60 -> V_166 == V_167 ) )
goto V_53;
V_70 = V_76 -> V_70 ;
if ( V_29 -> V_42 == V_247 + sizeof( * V_76 ) ) {
V_238 = V_76 -> V_101 * ( V_104 / V_105 ) ;
if ( ! V_238 ) {
V_238 = 10 * V_104 ;
V_70 = 0 ;
}
} else if ( V_29 -> V_42 >= V_247 + sizeof( * V_246 ) ) {
V_246 = F_63 ( V_29 ) ;
if ( V_246 -> V_109 )
goto V_53;
V_238 = V_246 -> V_101 ?
F_150 ( V_246 -> V_101 ) * ( V_104 / V_105 ) : 1 ;
} else {
goto V_53;
}
if ( ! V_70 ) {
V_95 . V_4 = F_2 ( V_6 ) ;
V_95 . V_7 . V_8 = V_80 -> V_95 ;
F_148 ( V_27 , V_60 , & V_27 -> V_191 ,
& V_95 , V_238 ) ;
goto V_53;
}
V_23 = F_13 ( F_32 ( V_27 -> V_13 , V_27 ) , V_70 , V_5 ) ;
if ( ! V_23 )
goto V_53;
V_238 *= V_27 -> V_248 ;
if ( V_23 -> V_54 &&
( F_31 ( & V_23 -> V_52 ) ?
F_151 ( V_23 -> V_52 . V_249 , V_165 + V_238 ) :
F_123 ( & V_23 -> V_52 ) >= 0 ) )
F_42 ( & V_23 -> V_52 , V_165 + V_238 ) ;
for ( V_58 = & V_23 -> V_55 ;
( V_48 = F_32 ( * V_58 , V_27 ) ) != NULL ;
V_58 = & V_48 -> V_59 ) {
if ( F_31 ( & V_48 -> V_52 ) ?
F_151 ( V_48 -> V_52 . V_249 , V_165 + V_238 ) :
F_123 ( & V_48 -> V_52 ) >= 0 )
F_42 ( & V_48 -> V_52 , V_165 + V_238 ) ;
}
V_53:
F_35 ( & V_27 -> V_50 ) ;
return V_66 ;
}
static int F_152 ( struct V_26 * V_27 ,
struct V_150 * V_60 ,
struct V_28 * V_29 ,
T_3 V_5 )
{
const struct V_117 * V_118 = F_19 ( V_29 ) ;
struct V_119 * V_250 ;
struct V_20 * V_23 ;
struct V_114 * V_115 ;
struct V_47 * V_48 ;
struct V_47 T_4 * * V_58 ;
struct V_1 V_95 ;
unsigned long V_238 ;
unsigned long V_165 = V_63 ;
unsigned int V_247 = F_131 ( V_29 ) ;
const struct V_19 * V_70 = NULL ;
bool V_251 ;
int V_66 = 0 ;
F_29 ( & V_27 -> V_50 ) ;
if ( ! F_30 ( V_27 -> V_51 ) ||
( V_60 && V_60 -> V_166 == V_167 ) )
goto V_53;
if ( V_29 -> V_42 == V_247 + sizeof( * V_250 ) ) {
if ( ! F_132 ( V_29 , V_247 + sizeof( * V_250 ) ) ) {
V_66 = - V_46 ;
goto V_53;
}
V_250 = (struct V_119 * ) F_72 ( V_29 ) ;
V_238 = F_153 ( F_130 ( V_250 -> V_136 ) ) ;
if ( V_238 )
V_70 = & V_250 -> V_138 ;
} else {
if ( ! F_132 ( V_29 , V_247 + sizeof( * V_115 ) ) ) {
V_66 = - V_46 ;
goto V_53;
}
V_115 = (struct V_114 * ) F_72 ( V_29 ) ;
if ( ! V_115 -> V_147 )
V_70 = & V_115 -> V_149 ;
V_238 = V_18 ( F_153 ( F_154 ( V_115 ) ) , 1UL ) ;
}
V_251 = V_70 && F_71 ( V_70 ) ;
if ( V_251 ) {
V_95 . V_4 = F_2 ( V_10 ) ;
V_95 . V_7 . V_11 = V_118 -> V_95 ;
F_148 ( V_27 , V_60 , & V_27 -> V_192 ,
& V_95 , V_238 ) ;
goto V_53;
} else if ( ! V_70 ) {
goto V_53;
}
V_23 = F_14 ( F_32 ( V_27 -> V_13 , V_27 ) , V_70 , V_5 ) ;
if ( ! V_23 )
goto V_53;
V_238 *= V_27 -> V_248 ;
if ( V_23 -> V_54 &&
( F_31 ( & V_23 -> V_52 ) ?
F_151 ( V_23 -> V_52 . V_249 , V_165 + V_238 ) :
F_123 ( & V_23 -> V_52 ) >= 0 ) )
F_42 ( & V_23 -> V_52 , V_165 + V_238 ) ;
for ( V_58 = & V_23 -> V_55 ;
( V_48 = F_32 ( * V_58 , V_27 ) ) != NULL ;
V_58 = & V_48 -> V_59 ) {
if ( F_31 ( & V_48 -> V_52 ) ?
F_151 ( V_48 -> V_52 . V_249 , V_165 + V_238 ) :
F_123 ( & V_48 -> V_52 ) >= 0 )
F_42 ( & V_48 -> V_52 , V_165 + V_238 ) ;
}
V_53:
F_35 ( & V_27 -> V_50 ) ;
return V_66 ;
}
static void
F_155 ( struct V_26 * V_27 ,
struct V_150 * V_60 ,
struct V_1 * V_70 ,
struct V_188 * V_189 ,
struct V_176 * V_187 ,
const unsigned char * V_161 )
{
struct V_12 * V_13 ;
struct V_20 * V_23 ;
struct V_47 * V_48 ;
unsigned long V_165 ;
unsigned long time ;
F_29 ( & V_27 -> V_50 ) ;
if ( ! F_30 ( V_27 -> V_51 ) ||
( V_60 && V_60 -> V_166 == V_167 ) )
goto V_53;
V_13 = F_32 ( V_27 -> V_13 , V_27 ) ;
V_23 = F_12 ( V_13 , V_70 ) ;
if ( ! V_23 )
goto V_53;
if ( V_60 && ( V_60 -> V_62 & V_252 ) ) {
struct V_47 T_4 * * V_58 ;
for ( V_58 = & V_23 -> V_55 ;
( V_48 = F_32 ( * V_58 , V_27 ) ) != NULL ;
V_58 = & V_48 -> V_59 ) {
if ( ! F_88 ( V_48 , V_60 , V_161 ) )
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
if ( F_31 ( & V_189 -> V_52 ) )
goto V_53;
if ( V_27 -> V_190 ) {
F_104 ( V_27 , V_60 , & V_23 -> V_24 ) ;
time = V_63 + V_27 -> V_248 *
V_27 -> V_102 ;
F_42 ( & V_187 -> V_52 , time ) ;
for ( V_48 = F_32 ( V_23 -> V_55 , V_27 ) ;
V_48 != NULL ;
V_48 = F_32 ( V_48 -> V_59 , V_27 ) ) {
if ( ! F_88 ( V_48 , V_60 , V_161 ) )
continue;
if ( ! F_44 ( & V_48 -> V_54 ) &&
( F_31 ( & V_48 -> V_52 ) ?
F_151 ( V_48 -> V_52 . V_249 , time ) :
F_123 ( & V_48 -> V_52 ) >= 0 ) ) {
F_42 ( & V_48 -> V_52 , time ) ;
}
break;
}
}
V_165 = V_63 ;
time = V_165 + V_27 -> V_248 *
V_27 -> V_102 ;
if ( ! V_60 ) {
if ( V_23 -> V_54 &&
( F_31 ( & V_23 -> V_52 ) ?
F_151 ( V_23 -> V_52 . V_249 , time ) :
F_123 ( & V_23 -> V_52 ) >= 0 ) ) {
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
F_151 ( V_48 -> V_52 . V_249 , time ) :
F_123 ( & V_48 -> V_52 ) >= 0 ) ) {
F_42 ( & V_48 -> V_52 , time ) ;
}
break;
}
V_53:
F_35 ( & V_27 -> V_50 ) ;
}
static void F_133 ( struct V_26 * V_27 ,
struct V_150 * V_60 ,
T_1 V_70 ,
T_2 V_5 ,
const unsigned char * V_161 )
{
struct V_1 V_171 ;
struct V_176 * V_187 ;
if ( F_93 ( V_70 ) )
return;
V_187 = V_60 ? & V_60 -> V_178 : & V_27 -> V_178 ;
V_171 . V_7 . V_8 = V_70 ;
V_171 . V_4 = F_2 ( V_6 ) ;
V_171 . V_5 = V_5 ;
F_155 ( V_27 , V_60 , & V_171 , & V_27 -> V_191 ,
V_187 , V_161 ) ;
}
static void F_137 ( struct V_26 * V_27 ,
struct V_150 * V_60 ,
const struct V_19 * V_70 ,
T_2 V_5 ,
const unsigned char * V_161 )
{
struct V_1 V_171 ;
struct V_176 * V_187 ;
if ( F_95 ( V_70 ) )
return;
V_187 = V_60 ? & V_60 -> V_179 : & V_27 -> V_179 ;
V_171 . V_7 . V_11 = * V_70 ;
V_171 . V_4 = F_2 ( V_10 ) ;
V_171 . V_5 = V_5 ;
F_155 ( V_27 , V_60 , & V_171 , & V_27 -> V_192 ,
V_187 , V_161 ) ;
}
static void F_156 ( const struct V_26 * V_27 ,
const struct V_150 * V_48 ,
T_7 V_4 )
{
struct V_207 T_8 * V_253 ;
struct V_207 * V_254 ;
if ( ! V_27 -> V_255 )
return;
if ( V_48 )
V_253 = V_48 -> V_206 ;
else
V_253 = V_27 -> V_206 ;
if ( F_37 ( ! V_253 ) )
return;
V_254 = F_157 ( V_253 ) ;
F_158 ( & V_254 -> V_256 ) ;
switch ( V_4 ) {
case F_2 ( V_6 ) :
V_254 -> V_257 . V_258 ++ ;
break;
#if F_3 ( V_9 )
case F_2 ( V_10 ) :
V_254 -> V_257 . V_259 ++ ;
break;
#endif
}
F_159 ( & V_254 -> V_256 ) ;
}
static void F_160 ( struct V_26 * V_27 ,
struct V_150 * V_60 ,
const struct V_28 * V_29 )
{
unsigned int V_247 = F_131 ( V_29 ) ;
struct V_260 * V_260 , V_261 ;
V_260 = F_135 ( V_29 , V_247 , sizeof( V_261 ) , & V_261 ) ;
if ( ! V_260 || F_161 ( V_260 ) != V_262 ||
F_162 ( V_260 ) != V_263 )
return;
F_147 ( V_27 , V_60 ) ;
}
static int F_163 ( struct V_26 * V_27 ,
struct V_150 * V_60 ,
struct V_28 * V_29 ,
T_3 V_5 )
{
struct V_28 * V_264 = NULL ;
const unsigned char * V_161 ;
struct V_75 * V_76 ;
int V_66 ;
V_66 = F_164 ( V_29 , & V_264 ) ;
if ( V_66 == - V_265 ) {
if ( ! F_93 ( F_18 ( V_29 ) -> V_33 ) ) {
F_17 ( V_29 ) -> V_266 = 1 ;
} else if ( F_165 ( F_18 ( V_29 ) -> V_33 ) ) {
if ( F_18 ( V_29 ) -> V_32 == V_267 )
F_160 ( V_27 , V_60 , V_29 ) ;
}
return 0 ;
} else if ( V_66 < 0 ) {
F_156 ( V_27 , V_60 , V_29 -> V_32 ) ;
return V_66 ;
}
V_76 = F_61 ( V_29 ) ;
V_161 = F_53 ( V_29 ) -> V_82 ;
F_17 ( V_29 ) -> V_31 = V_76 -> type ;
switch ( V_76 -> type ) {
case V_268 :
case V_269 :
F_17 ( V_29 ) -> V_266 = 1 ;
V_66 = F_92 ( V_27 , V_60 , V_76 -> V_70 , V_5 , V_161 ) ;
break;
case V_270 :
V_66 = F_128 ( V_27 , V_60 , V_264 , V_5 ) ;
break;
case V_100 :
V_66 = F_149 ( V_27 , V_60 , V_264 , V_5 ) ;
break;
case V_271 :
F_133 ( V_27 , V_60 , V_76 -> V_70 , V_5 , V_161 ) ;
break;
}
if ( V_264 && V_264 != V_29 )
F_69 ( V_264 ) ;
F_105 ( V_27 , V_60 , V_29 , F_17 ( V_29 ) -> V_31 ,
V_186 ) ;
return V_66 ;
}
static int F_166 ( struct V_26 * V_27 ,
struct V_150 * V_60 ,
struct V_28 * V_29 ,
T_3 V_5 )
{
struct V_28 * V_264 = NULL ;
const unsigned char * V_161 ;
struct V_119 * V_250 ;
int V_66 ;
V_66 = F_167 ( V_29 , & V_264 ) ;
if ( V_66 == - V_265 ) {
if ( ! F_95 ( & F_19 ( V_29 ) -> V_33 ) )
F_17 ( V_29 ) -> V_266 = 1 ;
return 0 ;
} else if ( V_66 < 0 ) {
F_156 ( V_27 , V_60 , V_29 -> V_32 ) ;
return V_66 ;
}
V_250 = (struct V_119 * ) F_168 ( V_29 ) ;
F_17 ( V_29 ) -> V_31 = V_250 -> V_133 ;
switch ( V_250 -> V_133 ) {
case V_272 :
V_161 = F_53 ( V_29 ) -> V_82 ;
F_17 ( V_29 ) -> V_266 = 1 ;
V_66 = F_94 ( V_27 , V_60 , & V_250 -> V_138 , V_5 ,
V_161 ) ;
break;
case V_273 :
V_66 = F_134 ( V_27 , V_60 , V_264 , V_5 ) ;
break;
case V_132 :
V_66 = F_152 ( V_27 , V_60 , V_264 , V_5 ) ;
break;
case V_274 :
V_161 = F_53 ( V_29 ) -> V_82 ;
F_137 ( V_27 , V_60 , & V_250 -> V_138 , V_5 , V_161 ) ;
break;
}
if ( V_264 && V_264 != V_29 )
F_69 ( V_264 ) ;
F_105 ( V_27 , V_60 , V_29 , F_17 ( V_29 ) -> V_31 ,
V_186 ) ;
return V_66 ;
}
int F_169 ( struct V_26 * V_27 , struct V_150 * V_60 ,
struct V_28 * V_29 , T_3 V_5 )
{
int V_275 = 0 ;
F_17 ( V_29 ) -> V_31 = 0 ;
F_17 ( V_29 ) -> V_266 = 0 ;
if ( V_27 -> V_30 )
return 0 ;
switch ( V_29 -> V_32 ) {
case F_2 ( V_6 ) :
V_275 = F_163 ( V_27 , V_60 , V_29 , V_5 ) ;
break;
#if F_3 ( V_9 )
case F_2 ( V_10 ) :
V_275 = F_166 ( V_27 , V_60 , V_29 , V_5 ) ;
break;
#endif
}
return V_275 ;
}
static void F_170 ( struct V_26 * V_27 ,
struct V_176 * V_177 ,
struct V_276 * V_277 )
{
F_29 ( & V_27 -> V_50 ) ;
if ( V_177 -> V_193 < V_27 -> V_194 )
V_177 -> V_193 ++ ;
F_171 ( V_277 -> V_60 , NULL ) ;
F_108 ( V_27 , NULL , V_177 ) ;
F_35 ( & V_27 -> V_50 ) ;
}
static void F_172 ( unsigned long V_49 )
{
struct V_26 * V_27 = ( void * ) V_49 ;
F_170 ( V_27 , & V_27 -> V_178 , & V_27 -> V_180 ) ;
}
static void F_173 ( unsigned long V_49 )
{
struct V_26 * V_27 = ( void * ) V_49 ;
F_170 ( V_27 , & V_27 -> V_179 , & V_27 -> V_181 ) ;
}
void F_174 ( struct V_26 * V_27 )
{
V_27 -> V_152 = 4 ;
V_27 -> V_154 = 512 ;
V_27 -> V_172 = V_205 ;
V_27 -> V_190 = 0 ;
V_27 -> V_96 = 0 ;
V_27 -> V_248 = 2 ;
V_27 -> V_194 = 2 ;
V_27 -> V_102 = V_104 ;
V_27 -> V_103 = 10 * V_104 ;
V_27 -> V_195 = 125 * V_104 / 4 ;
V_27 -> V_108 = 125 * V_104 ;
V_27 -> V_240 = 255 * V_104 ;
V_27 -> V_168 = 260 * V_104 ;
V_27 -> V_191 . V_239 = 0 ;
V_27 -> V_180 . V_60 = NULL ;
V_27 -> V_81 = 2 ;
#if F_3 ( V_9 )
V_27 -> V_123 = 1 ;
V_27 -> V_192 . V_239 = 0 ;
V_27 -> V_181 . V_60 = NULL ;
#endif
V_27 -> V_128 = 1 ;
F_175 ( & V_27 -> V_50 ) ;
F_85 ( & V_27 -> V_175 ,
F_98 , 0 ) ;
F_85 ( & V_27 -> V_191 . V_52 ,
F_101 , ( unsigned long ) V_27 ) ;
F_85 ( & V_27 -> V_178 . V_52 , F_172 ,
( unsigned long ) V_27 ) ;
#if F_3 ( V_9 )
F_85 ( & V_27 -> V_192 . V_52 ,
F_102 , ( unsigned long ) V_27 ) ;
F_85 ( & V_27 -> V_179 . V_52 , F_173 ,
( unsigned long ) V_27 ) ;
#endif
}
static void F_176 ( struct V_26 * V_27 ,
struct V_176 * V_177 )
{
V_177 -> V_193 = 0 ;
if ( V_27 -> V_30 )
return;
F_42 ( & V_177 -> V_52 , V_63 ) ;
}
void F_177 ( struct V_26 * V_27 )
{
F_176 ( V_27 , & V_27 -> V_178 ) ;
#if F_3 ( V_9 )
F_176 ( V_27 , & V_27 -> V_179 ) ;
#endif
}
void F_178 ( struct V_26 * V_27 )
{
F_120 ( & V_27 -> V_175 ) ;
F_120 ( & V_27 -> V_191 . V_52 ) ;
F_120 ( & V_27 -> V_178 . V_52 ) ;
#if F_3 ( V_9 )
F_120 ( & V_27 -> V_192 . V_52 ) ;
F_120 ( & V_27 -> V_179 . V_52 ) ;
#endif
}
void F_179 ( struct V_26 * V_27 )
{
struct V_12 * V_13 ;
struct V_20 * V_23 ;
struct V_208 * V_209 ;
V_16 V_45 ;
int V_43 ;
F_117 ( & V_27 -> V_50 ) ;
V_13 = F_32 ( V_27 -> V_13 , V_27 ) ;
if ( ! V_13 )
goto V_53;
V_27 -> V_13 = NULL ;
V_45 = V_13 -> V_45 ;
for ( V_43 = 0 ; V_43 < V_13 -> V_18 ; V_43 ++ ) {
F_118 (mp, n, &mdb->mhash[i],
hlist[ver]) {
F_40 ( & V_23 -> V_52 ) ;
F_34 ( & V_23 -> V_36 , F_27 ) ;
}
}
if ( V_13 -> V_37 ) {
F_119 ( & V_27 -> V_50 ) ;
F_180 () ;
F_117 ( & V_27 -> V_50 ) ;
F_37 ( V_13 -> V_37 ) ;
}
V_13 -> V_37 = V_13 ;
F_34 ( & V_13 -> V_36 , F_20 ) ;
V_53:
F_119 ( & V_27 -> V_50 ) ;
}
int F_181 ( struct V_26 * V_27 , unsigned long V_278 )
{
int V_66 = - V_46 ;
F_117 ( & V_27 -> V_50 ) ;
switch ( V_278 ) {
case V_173 :
case V_174 :
F_40 ( & V_27 -> V_175 ) ;
case V_205 :
V_27 -> V_172 = V_278 ;
V_66 = 0 ;
break;
}
F_119 ( & V_27 -> V_50 ) ;
return V_66 ;
}
static void F_97 ( struct V_150 * V_48 )
{
if ( F_44 ( & V_48 -> V_210 ) )
return;
F_182 ( & V_48 -> V_210 ) ;
F_146 ( V_48 -> V_27 -> V_51 , V_48 , V_61 ) ;
F_144 ( V_48 , false ) ;
if ( V_48 -> V_172 == V_279 )
V_48 -> V_172 = V_205 ;
}
int F_183 ( struct V_150 * V_48 , unsigned long V_278 )
{
struct V_26 * V_27 = V_48 -> V_27 ;
unsigned long V_165 = V_63 ;
int V_66 = - V_46 ;
F_29 ( & V_27 -> V_50 ) ;
if ( V_48 -> V_172 == V_278 ) {
if ( V_48 -> V_172 == V_279 )
F_42 ( & V_48 -> V_175 ,
V_165 + V_27 -> V_240 ) ;
V_66 = 0 ;
goto V_280;
}
switch ( V_278 ) {
case V_173 :
V_48 -> V_172 = V_173 ;
F_97 ( V_48 ) ;
F_40 ( & V_48 -> V_175 ) ;
break;
case V_205 :
V_48 -> V_172 = V_205 ;
F_97 ( V_48 ) ;
break;
case V_174 :
V_48 -> V_172 = V_174 ;
F_40 ( & V_48 -> V_175 ) ;
F_125 ( V_27 , V_48 ) ;
break;
case V_279 :
V_48 -> V_172 = V_279 ;
F_147 ( V_27 , V_48 ) ;
break;
default:
goto V_280;
}
V_66 = 0 ;
V_280:
F_35 ( & V_27 -> V_50 ) ;
return V_66 ;
}
static void F_100 ( struct V_26 * V_27 ,
struct V_176 * V_177 )
{
struct V_150 * V_60 ;
F_176 ( V_27 , V_177 ) ;
F_184 (port, &br->port_list, list) {
if ( V_60 -> V_166 == V_167 ||
V_60 -> V_166 == V_196 )
continue;
if ( V_177 == & V_27 -> V_178 )
F_122 ( & V_60 -> V_178 ) ;
#if F_3 ( V_9 )
else
F_122 ( & V_60 -> V_179 ) ;
#endif
}
}
int F_185 ( struct V_26 * V_27 , unsigned long V_278 )
{
struct V_12 * V_13 ;
struct V_150 * V_60 ;
int V_66 = 0 ;
F_117 ( & V_27 -> V_50 ) ;
if ( V_27 -> V_30 == ! V_278 )
goto V_280;
F_112 ( V_27 -> V_51 , ! V_278 ) ;
V_27 -> V_30 = ! V_278 ;
if ( V_27 -> V_30 )
goto V_280;
if ( ! F_30 ( V_27 -> V_51 ) )
goto V_280;
V_13 = F_32 ( V_27 -> V_13 , V_27 ) ;
if ( V_13 ) {
if ( V_13 -> V_37 ) {
V_66 = - V_157 ;
V_281:
V_27 -> V_30 = ! ! V_278 ;
goto V_280;
}
V_66 = F_45 ( & V_27 -> V_13 , V_13 -> V_18 ,
V_27 -> V_152 ) ;
if ( V_66 )
goto V_281;
}
F_177 ( V_27 ) ;
F_184 (port, &br->port_list, list)
F_124 ( V_60 ) ;
V_280:
F_119 ( & V_27 -> V_50 ) ;
return V_66 ;
}
int F_186 ( struct V_26 * V_27 , unsigned long V_278 )
{
unsigned long V_238 ;
V_278 = ! ! V_278 ;
F_117 ( & V_27 -> V_50 ) ;
if ( V_27 -> V_190 == V_278 )
goto V_280;
V_27 -> V_190 = V_278 ;
if ( ! V_278 )
goto V_280;
V_238 = V_27 -> V_103 ;
if ( ! F_31 ( & V_27 -> V_191 . V_52 ) )
V_27 -> V_191 . V_239 = V_63 + V_238 ;
F_100 ( V_27 , & V_27 -> V_178 ) ;
#if F_3 ( V_9 )
if ( ! F_31 ( & V_27 -> V_192 . V_52 ) )
V_27 -> V_192 . V_239 = V_63 + V_238 ;
F_100 ( V_27 , & V_27 -> V_179 ) ;
#endif
V_280:
F_119 ( & V_27 -> V_50 ) ;
return 0 ;
}
int F_187 ( struct V_26 * V_27 , unsigned long V_278 )
{
int V_66 = - V_46 ;
V_16 V_37 ;
struct V_12 * V_13 ;
F_117 ( & V_27 -> V_50 ) ;
if ( ! F_188 ( V_278 ) )
goto V_280;
V_13 = F_32 ( V_27 -> V_13 , V_27 ) ;
if ( V_13 && V_278 < V_13 -> V_56 )
goto V_280;
V_66 = 0 ;
V_37 = V_27 -> V_154 ;
V_27 -> V_154 = V_278 ;
if ( V_13 ) {
if ( V_13 -> V_37 ) {
V_66 = - V_157 ;
V_281:
V_27 -> V_154 = V_37 ;
goto V_280;
}
V_66 = F_45 ( & V_27 -> V_13 , V_27 -> V_154 ,
V_27 -> V_152 ) ;
if ( V_66 )
goto V_281;
}
V_280:
F_119 ( & V_27 -> V_50 ) ;
return V_66 ;
}
int F_189 ( struct V_26 * V_27 , unsigned long V_278 )
{
switch ( V_278 ) {
case 2 :
case 3 :
break;
default:
return - V_46 ;
}
F_117 ( & V_27 -> V_50 ) ;
V_27 -> V_81 = V_278 ;
F_119 ( & V_27 -> V_50 ) ;
return 0 ;
}
int F_190 ( struct V_26 * V_27 , unsigned long V_278 )
{
switch ( V_278 ) {
case 1 :
case 2 :
break;
default:
return - V_46 ;
}
F_117 ( & V_27 -> V_50 ) ;
V_27 -> V_123 = V_278 ;
F_119 ( & V_27 -> V_50 ) ;
return 0 ;
}
int F_191 ( struct V_197 * V_51 ,
struct V_282 * V_283 )
{
struct V_26 * V_27 ;
struct V_150 * V_60 ;
struct V_47 * V_70 ;
struct V_283 * V_284 ;
int V_151 = 0 ;
F_192 () ;
if ( ! V_283 || ! F_193 ( V_51 ) )
goto V_280;
V_60 = F_194 ( V_51 ) ;
if ( ! V_60 || ! V_60 -> V_27 )
goto V_280;
V_27 = V_60 -> V_27 ;
F_195 (port, &br->port_list, list) {
if ( ! V_60 -> V_51 || V_60 -> V_51 == V_51 )
continue;
F_11 (group, &port->mglist, mglist) {
V_284 = F_47 ( sizeof( * V_284 ) , V_67 ) ;
if ( ! V_284 )
goto V_280;
V_284 -> V_24 = V_70 -> V_24 ;
F_196 ( & V_284 -> V_285 , V_283 ) ;
V_151 ++ ;
}
}
V_280:
F_197 () ;
return V_151 ;
}
bool F_198 ( struct V_197 * V_51 , int V_4 )
{
struct V_26 * V_27 ;
struct V_150 * V_60 ;
struct V_77 V_78 ;
bool V_275 = false ;
F_192 () ;
if ( ! F_193 ( V_51 ) )
goto V_280;
V_60 = F_194 ( V_51 ) ;
if ( ! V_60 || ! V_60 -> V_27 )
goto V_280;
V_27 = V_60 -> V_27 ;
memset ( & V_78 , 0 , sizeof( V_78 ) ) ;
V_78 . V_85 = F_2 ( V_4 ) ;
V_275 = F_199 ( V_27 , & V_78 ) ;
V_280:
F_197 () ;
return V_275 ;
}
bool F_200 ( struct V_197 * V_51 , int V_4 )
{
struct V_26 * V_27 ;
struct V_150 * V_60 ;
bool V_275 = false ;
F_192 () ;
if ( ! F_193 ( V_51 ) )
goto V_280;
V_60 = F_194 ( V_51 ) ;
if ( ! V_60 || ! V_60 -> V_27 )
goto V_280;
V_27 = V_60 -> V_27 ;
switch ( V_4 ) {
case V_6 :
if ( ! F_31 ( & V_27 -> V_191 . V_52 ) ||
F_16 ( V_27 -> V_180 . V_60 ) == V_60 )
goto V_280;
break;
#if F_3 ( V_9 )
case V_10 :
if ( ! F_31 ( & V_27 -> V_192 . V_52 ) ||
F_16 ( V_27 -> V_181 . V_60 ) == V_60 )
goto V_280;
break;
#endif
default:
goto V_280;
}
V_275 = true ;
V_280:
F_197 () ;
return V_275 ;
}
static void F_201 ( struct V_207 T_8 * V_253 ,
const struct V_28 * V_29 , T_5 type , T_5 V_286 )
{
struct V_207 * V_254 = F_157 ( V_253 ) ;
T_7 V_4 = V_29 -> V_32 ;
unsigned int V_287 ;
F_158 ( & V_254 -> V_256 ) ;
switch ( V_4 ) {
case F_2 ( V_6 ) :
V_287 = F_130 ( F_18 ( V_29 ) -> V_89 ) - F_202 ( V_29 ) ;
switch ( type ) {
case V_268 :
V_254 -> V_257 . V_288 [ V_286 ] ++ ;
break;
case V_269 :
V_254 -> V_257 . V_289 [ V_286 ] ++ ;
break;
case V_270 :
V_254 -> V_257 . V_290 [ V_286 ] ++ ;
break;
case V_100 :
if ( V_287 != sizeof( struct V_75 ) ) {
V_254 -> V_257 . V_291 [ V_286 ] ++ ;
} else {
unsigned int V_247 = F_131 ( V_29 ) ;
struct V_75 * V_76 , V_292 ;
V_76 = F_135 ( V_29 , V_247 ,
sizeof( V_292 ) , & V_292 ) ;
if ( ! V_76 )
break;
if ( ! V_76 -> V_101 )
V_254 -> V_257 . V_293 [ V_286 ] ++ ;
else
V_254 -> V_257 . V_294 [ V_286 ] ++ ;
}
break;
case V_271 :
V_254 -> V_257 . V_295 [ V_286 ] ++ ;
break;
}
break;
#if F_3 ( V_9 )
case F_2 ( V_10 ) :
V_287 = F_130 ( F_19 ( V_29 ) -> V_124 ) +
sizeof( struct V_117 ) ;
V_287 -= F_203 ( V_29 ) ;
switch ( type ) {
case V_272 :
V_254 -> V_257 . V_296 [ V_286 ] ++ ;
break;
case V_273 :
V_254 -> V_257 . V_297 [ V_286 ] ++ ;
break;
case V_132 :
if ( V_287 != sizeof( struct V_119 ) )
V_254 -> V_257 . V_298 [ V_286 ] ++ ;
else
V_254 -> V_257 . V_299 [ V_286 ] ++ ;
break;
case V_274 :
V_254 -> V_257 . V_300 [ V_286 ] ++ ;
break;
}
break;
#endif
}
F_159 ( & V_254 -> V_256 ) ;
}
void F_105 ( struct V_26 * V_27 , const struct V_150 * V_48 ,
const struct V_28 * V_29 , T_5 type , T_5 V_286 )
{
struct V_207 T_8 * V_253 ;
if ( ! type || ! V_27 -> V_255 )
return;
if ( V_48 )
V_253 = V_48 -> V_206 ;
else
V_253 = V_27 -> V_206 ;
if ( F_37 ( ! V_253 ) )
return;
F_201 ( V_253 , V_29 , type , V_286 ) ;
}
int F_204 ( struct V_26 * V_27 )
{
V_27 -> V_206 = F_115 ( struct V_207 ) ;
if ( ! V_27 -> V_206 )
return - V_68 ;
return 0 ;
}
void F_205 ( struct V_26 * V_27 )
{
F_121 ( V_27 -> V_206 ) ;
}
static void F_206 ( T_9 * V_21 , T_9 * V_161 )
{
V_21 [ V_186 ] += V_161 [ V_186 ] ;
V_21 [ V_182 ] += V_161 [ V_182 ] ;
}
void F_207 ( const struct V_26 * V_27 ,
const struct V_150 * V_48 ,
struct V_301 * V_302 )
{
struct V_207 T_8 * V_253 ;
struct V_301 V_303 ;
int V_43 ;
memset ( V_302 , 0 , sizeof( * V_302 ) ) ;
if ( V_48 )
V_253 = V_48 -> V_206 ;
else
V_253 = V_27 -> V_206 ;
if ( F_37 ( ! V_253 ) )
return;
memset ( & V_303 , 0 , sizeof( V_303 ) ) ;
F_208 (i) {
struct V_207 * V_304 = F_209 ( V_253 , V_43 ) ;
struct V_301 V_305 ;
unsigned int V_306 ;
do {
V_306 = F_210 ( & V_304 -> V_256 ) ;
memcpy ( & V_305 , & V_304 -> V_257 , sizeof( V_305 ) ) ;
} while ( F_211 ( & V_304 -> V_256 , V_306 ) );
F_206 ( V_303 . V_293 , V_305 . V_293 ) ;
F_206 ( V_303 . V_294 , V_305 . V_294 ) ;
F_206 ( V_303 . V_291 , V_305 . V_291 ) ;
F_206 ( V_303 . V_295 , V_305 . V_295 ) ;
F_206 ( V_303 . V_288 , V_305 . V_288 ) ;
F_206 ( V_303 . V_289 , V_305 . V_289 ) ;
F_206 ( V_303 . V_290 , V_305 . V_290 ) ;
V_303 . V_258 += V_305 . V_258 ;
F_206 ( V_303 . V_299 , V_305 . V_299 ) ;
F_206 ( V_303 . V_298 , V_305 . V_298 ) ;
F_206 ( V_303 . V_300 , V_305 . V_300 ) ;
F_206 ( V_303 . V_296 , V_305 . V_296 ) ;
F_206 ( V_303 . V_297 , V_305 . V_297 ) ;
V_303 . V_259 += V_305 . V_259 ;
}
memcpy ( V_302 , & V_303 , sizeof( * V_302 ) ) ;
}
