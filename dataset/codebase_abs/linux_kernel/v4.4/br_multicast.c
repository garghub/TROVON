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
T_1 V_70 )
{
struct V_28 * V_29 ;
struct V_71 * V_72 ;
struct V_73 * V_74 ;
struct V_75 * V_76 ;
V_29 = F_51 ( V_27 -> V_51 , sizeof( * V_74 ) + sizeof( * V_76 ) +
sizeof( * V_72 ) + 4 ) ;
if ( ! V_29 )
goto V_53;
V_29 -> V_32 = F_2 ( V_6 ) ;
F_52 ( V_29 ) ;
V_74 = F_53 ( V_29 ) ;
F_54 ( V_74 -> V_77 , V_27 -> V_51 -> V_78 ) ;
V_74 -> V_79 [ 0 ] = 1 ;
V_74 -> V_79 [ 1 ] = 0 ;
V_74 -> V_79 [ 2 ] = 0x5e ;
V_74 -> V_79 [ 3 ] = 0 ;
V_74 -> V_79 [ 4 ] = 0 ;
V_74 -> V_79 [ 5 ] = 1 ;
V_74 -> V_80 = F_2 ( V_6 ) ;
F_55 ( V_29 , sizeof( * V_74 ) ) ;
F_56 ( V_29 , V_29 -> V_42 ) ;
V_76 = F_18 ( V_29 ) ;
V_76 -> V_81 = 4 ;
V_76 -> V_82 = 6 ;
V_76 -> V_83 = 0xc0 ;
V_76 -> V_84 = F_2 ( sizeof( * V_76 ) + sizeof( * V_72 ) + 4 ) ;
V_76 -> V_85 = 0 ;
V_76 -> V_86 = F_2 ( V_87 ) ;
V_76 -> V_88 = 1 ;
V_76 -> V_32 = V_89 ;
V_76 -> V_90 = V_27 -> V_91 ?
F_57 ( V_27 -> V_51 , 0 , V_92 ) : 0 ;
V_76 -> V_33 = F_58 ( V_93 ) ;
( ( V_94 * ) & V_76 [ 1 ] ) [ 0 ] = V_95 ;
( ( V_94 * ) & V_76 [ 1 ] ) [ 1 ] = 4 ;
( ( V_94 * ) & V_76 [ 1 ] ) [ 2 ] = 0 ;
( ( V_94 * ) & V_76 [ 1 ] ) [ 3 ] = 0 ;
F_59 ( V_76 ) ;
F_55 ( V_29 , 24 ) ;
F_60 ( V_29 , V_29 -> V_42 ) ;
V_72 = F_61 ( V_29 ) ;
V_72 -> type = V_96 ;
V_72 -> V_97 = ( V_70 ? V_27 -> V_98 :
V_27 -> V_99 ) /
( V_100 / V_101 ) ;
V_72 -> V_70 = V_70 ;
V_72 -> V_102 = 0 ;
V_72 -> V_102 = F_62 ( ( void * ) V_72 , sizeof( struct V_71 ) ) ;
F_55 ( V_29 , sizeof( * V_72 ) ) ;
F_63 ( V_29 , sizeof( * V_74 ) ) ;
V_53:
return V_29 ;
}
static struct V_28 * F_64 ( struct V_26 * V_27 ,
const struct V_19 * V_70 )
{
struct V_28 * V_29 ;
struct V_103 * V_104 ;
struct V_105 * V_106 ;
struct V_73 * V_74 ;
V_94 * V_107 ;
unsigned long V_108 ;
V_29 = F_51 ( V_27 -> V_51 , sizeof( * V_74 ) + sizeof( * V_104 ) +
8 + sizeof( * V_106 ) ) ;
if ( ! V_29 )
goto V_53;
V_29 -> V_32 = F_2 ( V_10 ) ;
F_52 ( V_29 ) ;
V_74 = F_53 ( V_29 ) ;
F_54 ( V_74 -> V_77 , V_27 -> V_51 -> V_78 ) ;
V_74 -> V_80 = F_2 ( V_10 ) ;
F_55 ( V_29 , sizeof( * V_74 ) ) ;
F_56 ( V_29 , V_29 -> V_42 ) ;
V_104 = F_19 ( V_29 ) ;
* ( V_15 T_1 * ) V_104 = F_58 ( 0x60000000 ) ;
V_104 -> V_109 = F_2 ( 8 + sizeof( * V_106 ) ) ;
V_104 -> V_110 = V_111 ;
V_104 -> V_112 = 1 ;
F_65 ( & V_104 -> V_33 , F_58 ( 0xff020000 ) , 0 , 0 , F_58 ( 1 ) ) ;
if ( F_66 ( F_67 ( V_27 -> V_51 ) , V_27 -> V_51 , & V_104 -> V_33 , 0 ,
& V_104 -> V_90 ) ) {
F_68 ( V_29 ) ;
return NULL ;
}
F_69 ( & V_104 -> V_33 , V_74 -> V_79 ) ;
V_107 = ( V_94 * ) ( V_104 + 1 ) ;
V_107 [ 0 ] = V_113 ;
V_107 [ 1 ] = 0 ;
V_107 [ 2 ] = V_114 ;
V_107 [ 3 ] = 2 ;
V_107 [ 4 ] = 0 ;
V_107 [ 5 ] = 0 ;
V_107 [ 6 ] = V_115 ;
V_107 [ 7 ] = V_115 ;
F_55 ( V_29 , sizeof( * V_104 ) + 8 ) ;
F_60 ( V_29 , V_29 -> V_42 ) ;
V_106 = (struct V_105 * ) F_70 ( V_29 ) ;
V_108 = F_71 ( V_70 ) ?
V_27 -> V_99 :
V_27 -> V_98 ;
V_106 -> V_116 = V_117 ;
V_106 -> V_118 = 0 ;
V_106 -> V_119 = 0 ;
V_106 -> V_120 = F_2 ( ( T_3 ) F_72 ( V_108 ) ) ;
V_106 -> V_121 = 0 ;
V_106 -> V_122 = * V_70 ;
V_106 -> V_119 = F_73 ( & V_104 -> V_90 , & V_104 -> V_33 ,
sizeof( * V_106 ) , V_113 ,
F_74 ( V_106 ,
sizeof( * V_106 ) , 0 ) ) ;
F_55 ( V_29 , sizeof( * V_106 ) ) ;
F_63 ( V_29 , sizeof( * V_74 ) ) ;
V_53:
return V_29 ;
}
static struct V_28 * F_75 ( struct V_26 * V_27 ,
struct V_1 * V_24 )
{
switch ( V_24 -> V_4 ) {
case F_2 ( V_6 ) :
return F_50 ( V_27 , V_24 -> V_7 . V_8 ) ;
#if F_3 ( V_9 )
case F_2 ( V_10 ) :
return F_64 ( V_27 , & V_24 -> V_7 . V_11 ) ;
#endif
}
return NULL ;
}
static struct V_20 * F_76 (
struct V_26 * V_27 , struct V_123 * V_60 ,
struct V_1 * V_70 , int V_22 )
{
struct V_12 * V_13 ;
struct V_20 * V_23 ;
unsigned int V_124 = 0 ;
unsigned int V_18 ;
int V_40 ;
int V_66 ;
V_13 = F_46 ( V_27 -> V_13 , 1 ) ;
F_24 (mp, &mdb->mhash[hash], hlist[mdb->ver]) {
V_124 ++ ;
if ( F_77 ( F_1 ( V_70 , & V_23 -> V_24 ) ) )
return V_23 ;
}
V_40 = 0 ;
V_18 = V_13 -> V_18 ;
if ( F_77 ( V_124 > V_27 -> V_125 && V_124 ) ) {
if ( F_78 () )
F_79 ( V_27 , L_1
L_2 ,
V_60 ? V_60 -> V_51 -> V_126 : V_27 -> V_51 -> V_126 ) ;
V_40 = V_27 -> V_125 ;
}
if ( V_13 -> V_56 >= V_18 ) {
V_18 *= 2 ;
if ( F_77 ( V_18 > V_27 -> V_127 ) ) {
F_80 ( V_27 , L_3
L_4 ,
V_27 -> V_127 ,
V_60 ? V_60 -> V_51 -> V_126 : V_27 -> V_51 -> V_126 ) ;
V_66 = - V_128 ;
V_129:
V_27 -> V_30 = 1 ;
goto V_66;
}
}
if ( V_18 > V_13 -> V_18 || V_40 ) {
if ( V_13 -> V_37 ) {
if ( F_78 () )
F_79 ( V_27 , L_1
L_5 ,
V_60 ? V_60 -> V_51 -> V_126 : V_27 -> V_51 -> V_126 ) ;
V_66 = - V_130 ;
goto V_66;
}
V_66 = F_45 ( & V_27 -> V_13 , V_18 , V_40 ) ;
if ( V_66 ) {
F_80 ( V_27 , L_6
L_7 ,
V_60 ? V_60 -> V_51 -> V_126 : V_27 -> V_51 -> V_126 ,
V_13 -> V_56 , V_66 ) ;
goto V_129;
}
V_66 = - V_131 ;
goto V_66;
}
return NULL ;
V_66:
V_23 = F_81 ( V_66 ) ;
return V_23 ;
}
struct V_20 * F_82 ( struct V_26 * V_27 ,
struct V_123 * V_60 , struct V_1 * V_70 )
{
struct V_12 * V_13 ;
struct V_20 * V_23 ;
int V_22 ;
int V_66 ;
V_13 = F_46 ( V_27 -> V_13 , 1 ) ;
if ( ! V_13 ) {
V_66 = F_45 ( & V_27 -> V_13 , V_132 , 0 ) ;
if ( V_66 )
return F_81 ( V_66 ) ;
goto V_133;
}
V_22 = F_9 ( V_13 , V_70 ) ;
V_23 = F_76 ( V_27 , V_60 , V_70 , V_22 ) ;
switch ( F_83 ( V_23 ) ) {
case 0 :
break;
case - V_131 :
V_133:
V_13 = F_46 ( V_27 -> V_13 , 1 ) ;
V_22 = F_9 ( V_13 , V_70 ) ;
break;
default:
goto V_53;
}
V_23 = F_48 ( sizeof( * V_23 ) , V_67 ) ;
if ( F_77 ( ! V_23 ) )
return F_81 ( - V_68 ) ;
V_23 -> V_27 = V_27 ;
V_23 -> V_24 = * V_70 ;
F_84 ( & V_23 -> V_52 , F_28 ,
( unsigned long ) V_23 ) ;
F_85 ( & V_23 -> V_44 [ V_13 -> V_45 ] , & V_13 -> V_38 [ V_22 ] ) ;
V_13 -> V_56 ++ ;
V_53:
return V_23 ;
}
struct V_47 * F_86 (
struct V_123 * V_60 ,
struct V_1 * V_70 ,
struct V_47 T_4 * V_59 ,
unsigned char V_62 )
{
struct V_47 * V_48 ;
V_48 = F_48 ( sizeof( * V_48 ) , V_67 ) ;
if ( F_77 ( ! V_48 ) )
return NULL ;
V_48 -> V_24 = * V_70 ;
V_48 -> V_60 = V_60 ;
V_48 -> V_62 = V_62 ;
F_38 ( V_48 -> V_59 , V_59 ) ;
F_25 ( & V_48 -> V_54 , & V_60 -> V_54 ) ;
F_84 ( & V_48 -> V_52 , F_43 ,
( unsigned long ) V_48 ) ;
return V_48 ;
}
static int F_87 ( struct V_26 * V_27 ,
struct V_123 * V_60 ,
struct V_1 * V_70 )
{
struct V_20 * V_23 ;
struct V_47 * V_48 ;
struct V_47 T_4 * * V_58 ;
unsigned long V_134 = V_63 ;
int V_66 ;
F_29 ( & V_27 -> V_50 ) ;
if ( ! F_30 ( V_27 -> V_51 ) ||
( V_60 && V_60 -> V_62 == V_135 ) )
goto V_53;
V_23 = F_82 ( V_27 , V_60 , V_70 ) ;
V_66 = F_83 ( V_23 ) ;
if ( F_88 ( V_23 ) )
goto V_66;
if ( ! V_60 ) {
V_23 -> V_54 = true ;
F_42 ( & V_23 -> V_52 , V_134 + V_27 -> V_136 ) ;
goto V_53;
}
for ( V_58 = & V_23 -> V_55 ;
( V_48 = F_32 ( * V_58 , V_27 ) ) != NULL ;
V_58 = & V_48 -> V_59 ) {
if ( V_48 -> V_60 == V_60 )
goto V_137;
if ( ( unsigned long ) V_48 -> V_60 < ( unsigned long ) V_60 )
break;
}
V_48 = F_86 ( V_60 , V_70 , * V_58 , V_138 ) ;
if ( F_77 ( ! V_48 ) )
goto V_66;
F_38 ( * V_58 , V_48 ) ;
F_41 ( V_27 -> V_51 , V_60 , V_70 , V_139 , V_138 ) ;
V_137:
F_42 ( & V_48 -> V_52 , V_134 + V_27 -> V_136 ) ;
V_53:
V_66 = 0 ;
V_66:
F_35 ( & V_27 -> V_50 ) ;
return V_66 ;
}
static int F_89 ( struct V_26 * V_27 ,
struct V_123 * V_60 ,
T_1 V_70 ,
T_2 V_5 )
{
struct V_1 V_140 ;
if ( F_90 ( V_70 ) )
return 0 ;
V_140 . V_7 . V_8 = V_70 ;
V_140 . V_4 = F_2 ( V_6 ) ;
V_140 . V_5 = V_5 ;
return F_87 ( V_27 , V_60 , & V_140 ) ;
}
static int F_91 ( struct V_26 * V_27 ,
struct V_123 * V_60 ,
const struct V_19 * V_70 ,
T_2 V_5 )
{
struct V_1 V_140 ;
if ( F_92 ( V_70 ) )
return 0 ;
V_140 . V_7 . V_11 = * V_70 ;
V_140 . V_4 = F_2 ( V_10 ) ;
V_140 . V_5 = V_5 ;
return F_87 ( V_27 , V_60 , & V_140 ) ;
}
static void F_93 ( unsigned long V_49 )
{
struct V_123 * V_60 = ( void * ) V_49 ;
struct V_26 * V_27 = V_60 -> V_27 ;
F_29 ( & V_27 -> V_50 ) ;
if ( V_60 -> V_141 != 1 ||
F_31 ( & V_60 -> V_142 ) ||
F_44 ( & V_60 -> V_143 ) )
goto V_53;
F_94 ( & V_60 -> V_143 ) ;
F_95 ( V_27 -> V_51 , V_60 , V_61 ) ;
V_53:
F_35 ( & V_27 -> V_50 ) ;
}
static void F_96 ( unsigned long V_49 )
{
}
static void F_97 ( struct V_26 * V_27 ,
struct V_144 * V_145 )
{
F_29 ( & V_27 -> V_50 ) ;
if ( ! F_30 ( V_27 -> V_51 ) || V_27 -> V_30 )
goto V_53;
F_98 ( V_27 , V_145 ) ;
V_53:
F_35 ( & V_27 -> V_50 ) ;
}
static void F_99 ( unsigned long V_49 )
{
struct V_26 * V_27 = ( void * ) V_49 ;
F_97 ( V_27 , & V_27 -> V_146 ) ;
}
static void F_100 ( unsigned long V_49 )
{
struct V_26 * V_27 = ( void * ) V_49 ;
F_97 ( V_27 , & V_27 -> V_147 ) ;
}
static void F_101 ( struct V_26 * V_27 ,
struct V_1 * V_14 ,
struct V_28 * V_29 )
{
if ( V_14 -> V_4 == F_2 ( V_6 ) )
V_27 -> V_148 . V_24 . V_7 . V_8 = F_18 ( V_29 ) -> V_90 ;
#if F_3 ( V_9 )
else
V_27 -> V_149 . V_24 . V_7 . V_11 = F_19 ( V_29 ) -> V_90 ;
#endif
}
static void F_102 ( struct V_26 * V_27 ,
struct V_123 * V_60 ,
struct V_1 * V_14 )
{
struct V_28 * V_29 ;
V_29 = F_75 ( V_27 , V_14 ) ;
if ( ! V_29 )
return;
if ( V_60 ) {
V_29 -> V_51 = V_60 -> V_51 ;
F_103 ( V_150 , V_151 ,
F_67 ( V_60 -> V_51 ) , NULL , V_29 , NULL , V_29 -> V_51 ,
V_152 ) ;
} else {
F_101 ( V_27 , V_14 , V_29 ) ;
F_104 ( V_29 ) ;
}
}
static void F_105 ( struct V_26 * V_27 ,
struct V_123 * V_60 ,
struct V_144 * V_153 )
{
unsigned long time ;
struct V_1 V_140 ;
struct V_154 * V_155 = NULL ;
if ( ! F_30 ( V_27 -> V_51 ) || V_27 -> V_30 ||
! V_27 -> V_156 )
return;
memset ( & V_140 . V_7 , 0 , sizeof( V_140 . V_7 ) ) ;
if ( V_60 ? ( V_153 == & V_60 -> V_146 ) :
( V_153 == & V_27 -> V_146 ) ) {
V_155 = & V_27 -> V_157 ;
V_140 . V_4 = F_2 ( V_6 ) ;
#if F_3 ( V_9 )
} else {
V_155 = & V_27 -> V_158 ;
V_140 . V_4 = F_2 ( V_10 ) ;
#endif
}
if ( ! V_155 || F_31 ( & V_155 -> V_52 ) )
return;
F_102 ( V_27 , V_60 , & V_140 ) ;
time = V_63 ;
time += V_153 -> V_159 < V_27 -> V_160 ?
V_27 -> V_161 :
V_27 -> V_162 ;
F_42 ( & V_153 -> V_52 , time ) ;
}
static void
F_106 ( struct V_123 * V_60 ,
struct V_144 * V_145 )
{
struct V_26 * V_27 = V_60 -> V_27 ;
F_29 ( & V_27 -> V_50 ) ;
if ( V_60 -> V_62 == V_135 ||
V_60 -> V_62 == V_163 )
goto V_53;
if ( V_145 -> V_159 < V_27 -> V_160 )
V_145 -> V_159 ++ ;
F_105 ( V_60 -> V_27 , V_60 , V_145 ) ;
V_53:
F_35 ( & V_27 -> V_50 ) ;
}
static void F_107 ( unsigned long V_49 )
{
struct V_123 * V_60 = ( void * ) V_49 ;
F_106 ( V_60 , & V_60 -> V_146 ) ;
}
static void F_108 ( unsigned long V_49 )
{
struct V_123 * V_60 = ( void * ) V_49 ;
F_106 ( V_60 , & V_60 -> V_147 ) ;
}
void F_109 ( struct V_123 * V_60 )
{
V_60 -> V_141 = 1 ;
F_84 ( & V_60 -> V_142 , F_93 ,
( unsigned long ) V_60 ) ;
F_84 ( & V_60 -> V_146 . V_52 ,
F_107 , ( unsigned long ) V_60 ) ;
#if F_3 ( V_9 )
F_84 ( & V_60 -> V_147 . V_52 ,
F_108 , ( unsigned long ) V_60 ) ;
#endif
}
void F_110 ( struct V_123 * V_60 )
{
struct V_26 * V_27 = V_60 -> V_27 ;
struct V_47 * V_57 ;
struct V_164 * V_165 ;
F_111 ( & V_27 -> V_50 ) ;
F_112 (pg, n, &port->mglist, mglist)
F_36 ( V_27 , V_57 ) ;
F_113 ( & V_27 -> V_50 ) ;
F_114 ( & V_60 -> V_142 ) ;
}
static void F_115 ( struct V_144 * V_145 )
{
V_145 -> V_159 = 0 ;
if ( F_116 ( & V_145 -> V_52 ) >= 0 ||
F_40 ( & V_145 -> V_52 ) )
F_42 ( & V_145 -> V_52 , V_63 ) ;
}
void F_117 ( struct V_123 * V_60 )
{
struct V_26 * V_27 = V_60 -> V_27 ;
F_29 ( & V_27 -> V_50 ) ;
if ( V_27 -> V_30 || ! F_30 ( V_27 -> V_51 ) )
goto V_53;
F_115 ( & V_60 -> V_146 ) ;
#if F_3 ( V_9 )
F_115 ( & V_60 -> V_147 ) ;
#endif
if ( V_60 -> V_141 == 2 && F_44 ( & V_60 -> V_143 ) )
F_118 ( V_27 , V_60 ) ;
V_53:
F_35 ( & V_27 -> V_50 ) ;
}
void F_119 ( struct V_123 * V_60 )
{
struct V_26 * V_27 = V_60 -> V_27 ;
struct V_47 * V_57 ;
struct V_164 * V_165 ;
F_29 ( & V_27 -> V_50 ) ;
F_112 (pg, n, &port->mglist, mglist)
if ( V_57 -> V_62 == V_138 )
F_36 ( V_27 , V_57 ) ;
if ( ! F_44 ( & V_60 -> V_143 ) ) {
F_94 ( & V_60 -> V_143 ) ;
F_95 ( V_27 -> V_51 , V_60 , V_61 ) ;
}
F_40 ( & V_60 -> V_142 ) ;
F_40 ( & V_60 -> V_146 . V_52 ) ;
#if F_3 ( V_9 )
F_40 ( & V_60 -> V_147 . V_52 ) ;
#endif
F_35 ( & V_27 -> V_50 ) ;
}
static int F_120 ( struct V_26 * V_27 ,
struct V_123 * V_60 ,
struct V_28 * V_29 ,
T_3 V_5 )
{
struct V_166 * V_72 ;
struct V_167 * V_168 ;
int V_43 ;
int V_42 ;
int V_169 ;
int type ;
int V_66 = 0 ;
T_1 V_70 ;
V_72 = F_121 ( V_29 ) ;
V_169 = F_122 ( V_72 -> V_170 ) ;
V_42 = F_123 ( V_29 ) + sizeof( * V_72 ) ;
for ( V_43 = 0 ; V_43 < V_169 ; V_43 ++ ) {
V_42 += sizeof( * V_168 ) ;
if ( ! F_124 ( V_29 , V_42 ) )
return - V_46 ;
V_168 = ( void * ) ( V_29 -> V_49 + V_42 - sizeof( * V_168 ) ) ;
V_70 = V_168 -> V_171 ;
type = V_168 -> V_172 ;
V_42 += F_122 ( V_168 -> V_173 ) * 4 ;
if ( ! F_124 ( V_29 , V_42 ) )
return - V_46 ;
switch ( type ) {
case V_174 :
case V_175 :
case V_176 :
case V_177 :
case V_178 :
case V_179 :
break;
default:
continue;
}
if ( ( type == V_176 ||
type == V_174 ) &&
F_122 ( V_168 -> V_173 ) == 0 ) {
F_125 ( V_27 , V_60 , V_70 , V_5 ) ;
} else {
V_66 = F_89 ( V_27 , V_60 , V_70 , V_5 ) ;
if ( V_66 )
break;
}
}
return V_66 ;
}
static int F_126 ( struct V_26 * V_27 ,
struct V_123 * V_60 ,
struct V_28 * V_29 ,
T_3 V_5 )
{
struct V_180 * V_181 ;
struct V_182 * V_168 ;
int V_43 ;
int V_42 ;
int V_169 ;
int V_66 = 0 ;
if ( ! F_124 ( V_29 , sizeof( * V_181 ) ) )
return - V_46 ;
V_181 = F_70 ( V_29 ) ;
V_169 = F_122 ( V_181 -> V_183 . V_184 [ 1 ] ) ;
V_42 = F_123 ( V_29 ) + sizeof( * V_181 ) ;
for ( V_43 = 0 ; V_43 < V_169 ; V_43 ++ ) {
T_5 * V_185 , V_186 ;
V_185 = F_127 ( V_29 ,
V_42 + F_128 ( struct V_182 ,
V_173 ) ,
sizeof( V_186 ) , & V_186 ) ;
if ( ! V_185 )
return - V_46 ;
if ( ! F_124 ( V_29 ,
V_42 + sizeof( * V_168 ) +
sizeof( struct V_19 ) * F_122 ( * V_185 ) ) )
return - V_46 ;
V_168 = (struct V_182 * ) ( V_29 -> V_49 + V_42 ) ;
V_42 += sizeof( * V_168 ) +
sizeof( struct V_19 ) * F_122 ( * V_185 ) ;
switch ( V_168 -> V_172 ) {
case V_187 :
case V_188 :
case V_189 :
case V_190 :
case V_191 :
case V_192 :
break;
default:
continue;
}
if ( ( V_168 -> V_172 == V_189 ||
V_168 -> V_172 == V_187 ) &&
F_122 ( * V_185 ) == 0 ) {
F_129 ( V_27 , V_60 , & V_168 -> V_171 ,
V_5 ) ;
} else {
V_66 = F_91 ( V_27 , V_60 ,
& V_168 -> V_171 , V_5 ) ;
if ( ! V_66 )
break;
}
}
return V_66 ;
}
static bool F_130 ( struct V_26 * V_27 ,
struct V_123 * V_60 ,
T_1 V_90 )
{
if ( ! F_31 ( & V_27 -> V_146 . V_52 ) &&
! F_31 ( & V_27 -> V_157 . V_52 ) )
goto V_193;
if ( ! V_27 -> V_148 . V_24 . V_7 . V_8 )
goto V_193;
if ( F_131 ( V_90 ) <= F_131 ( V_27 -> V_148 . V_24 . V_7 . V_8 ) )
goto V_193;
return false ;
V_193:
V_27 -> V_148 . V_24 . V_7 . V_8 = V_90 ;
F_38 ( V_27 -> V_148 . V_60 , V_60 ) ;
return true ;
}
static bool F_132 ( struct V_26 * V_27 ,
struct V_123 * V_60 ,
struct V_19 * V_90 )
{
if ( ! F_31 ( & V_27 -> V_147 . V_52 ) &&
! F_31 ( & V_27 -> V_158 . V_52 ) )
goto V_193;
if ( F_133 ( V_90 , & V_27 -> V_149 . V_24 . V_7 . V_11 ) <= 0 )
goto V_193;
return false ;
V_193:
V_27 -> V_149 . V_24 . V_7 . V_11 = * V_90 ;
F_38 ( V_27 -> V_149 . V_60 , V_60 ) ;
return true ;
}
static bool F_134 ( struct V_26 * V_27 ,
struct V_123 * V_60 ,
struct V_1 * V_90 )
{
switch ( V_90 -> V_4 ) {
case F_2 ( V_6 ) :
return F_130 ( V_27 , V_60 , V_90 -> V_7 . V_8 ) ;
#if F_3 ( V_9 )
case F_2 ( V_10 ) :
return F_132 ( V_27 , V_60 , & V_90 -> V_7 . V_11 ) ;
#endif
}
return false ;
}
static void
F_135 ( struct V_26 * V_27 ,
struct V_154 * V_145 ,
unsigned long V_194 )
{
if ( ! F_31 ( & V_145 -> V_52 ) )
V_145 -> V_195 = V_63 + V_194 ;
F_42 ( & V_145 -> V_52 , V_63 + V_27 -> V_196 ) ;
}
static void F_118 ( struct V_26 * V_27 ,
struct V_123 * V_60 )
{
struct V_123 * V_48 ;
struct V_164 * V_197 = NULL ;
if ( ! F_44 ( & V_60 -> V_143 ) )
return;
F_24 (p, &br->router_list, rlist) {
if ( ( unsigned long ) V_60 >= ( unsigned long ) V_48 )
break;
V_197 = & V_48 -> V_143 ;
}
if ( V_197 )
F_136 ( & V_60 -> V_143 , V_197 ) ;
else
F_85 ( & V_60 -> V_143 , & V_27 -> V_198 ) ;
F_95 ( V_27 -> V_51 , V_60 , V_139 ) ;
}
static void F_137 ( struct V_26 * V_27 ,
struct V_123 * V_60 )
{
unsigned long V_134 = V_63 ;
if ( ! V_60 ) {
if ( V_27 -> V_141 == 1 )
F_42 ( & V_27 -> V_142 ,
V_134 + V_27 -> V_196 ) ;
return;
}
if ( V_60 -> V_141 != 1 )
return;
F_118 ( V_27 , V_60 ) ;
F_42 ( & V_60 -> V_142 ,
V_134 + V_27 -> V_196 ) ;
}
static void F_138 ( struct V_26 * V_27 ,
struct V_123 * V_60 ,
struct V_154 * V_145 ,
struct V_1 * V_90 ,
unsigned long V_194 )
{
if ( ! F_134 ( V_27 , V_60 , V_90 ) )
return;
F_135 ( V_27 , V_145 , V_194 ) ;
F_137 ( V_27 , V_60 ) ;
}
static int F_139 ( struct V_26 * V_27 ,
struct V_123 * V_60 ,
struct V_28 * V_29 ,
T_3 V_5 )
{
const struct V_75 * V_76 = F_18 ( V_29 ) ;
struct V_71 * V_72 = F_61 ( V_29 ) ;
struct V_20 * V_23 ;
struct V_199 * V_200 ;
struct V_47 * V_48 ;
struct V_47 T_4 * * V_58 ;
struct V_1 V_90 ;
unsigned long V_194 ;
unsigned long V_134 = V_63 ;
T_1 V_70 ;
int V_66 = 0 ;
F_29 ( & V_27 -> V_50 ) ;
if ( ! F_30 ( V_27 -> V_51 ) ||
( V_60 && V_60 -> V_62 == V_135 ) )
goto V_53;
V_70 = V_72 -> V_70 ;
if ( V_29 -> V_42 == sizeof( * V_72 ) ) {
V_194 = V_72 -> V_97 * ( V_100 / V_101 ) ;
if ( ! V_194 ) {
V_194 = 10 * V_100 ;
V_70 = 0 ;
}
} else if ( V_29 -> V_42 >= sizeof( * V_200 ) ) {
V_200 = F_140 ( V_29 ) ;
if ( V_200 -> V_185 )
goto V_53;
V_194 = V_200 -> V_97 ?
F_141 ( V_200 -> V_97 ) * ( V_100 / V_101 ) : 1 ;
} else {
goto V_53;
}
if ( ! V_70 ) {
V_90 . V_4 = F_2 ( V_6 ) ;
V_90 . V_7 . V_8 = V_76 -> V_90 ;
F_138 ( V_27 , V_60 , & V_27 -> V_157 ,
& V_90 , V_194 ) ;
goto V_53;
}
V_23 = F_13 ( F_32 ( V_27 -> V_13 , V_27 ) , V_70 , V_5 ) ;
if ( ! V_23 )
goto V_53;
V_194 *= V_27 -> V_201 ;
if ( V_23 -> V_54 &&
( F_31 ( & V_23 -> V_52 ) ?
F_142 ( V_23 -> V_52 . V_202 , V_134 + V_194 ) :
F_116 ( & V_23 -> V_52 ) >= 0 ) )
F_42 ( & V_23 -> V_52 , V_134 + V_194 ) ;
for ( V_58 = & V_23 -> V_55 ;
( V_48 = F_32 ( * V_58 , V_27 ) ) != NULL ;
V_58 = & V_48 -> V_59 ) {
if ( F_31 ( & V_48 -> V_52 ) ?
F_142 ( V_48 -> V_52 . V_202 , V_134 + V_194 ) :
F_116 ( & V_48 -> V_52 ) >= 0 )
F_42 ( & V_48 -> V_52 , V_134 + V_194 ) ;
}
V_53:
F_35 ( & V_27 -> V_50 ) ;
return V_66 ;
}
static int F_143 ( struct V_26 * V_27 ,
struct V_123 * V_60 ,
struct V_28 * V_29 ,
T_3 V_5 )
{
const struct V_103 * V_104 = F_19 ( V_29 ) ;
struct V_105 * V_203 ;
struct V_20 * V_23 ;
struct V_204 * V_205 ;
struct V_47 * V_48 ;
struct V_47 T_4 * * V_58 ;
struct V_1 V_90 ;
unsigned long V_194 ;
unsigned long V_134 = V_63 ;
const struct V_19 * V_70 = NULL ;
bool V_206 ;
int V_66 = 0 ;
F_29 ( & V_27 -> V_50 ) ;
if ( ! F_30 ( V_27 -> V_51 ) ||
( V_60 && V_60 -> V_62 == V_135 ) )
goto V_53;
if ( V_29 -> V_42 == sizeof( * V_203 ) ) {
if ( ! F_124 ( V_29 , sizeof( * V_203 ) ) ) {
V_66 = - V_46 ;
goto V_53;
}
V_203 = (struct V_105 * ) F_70 ( V_29 ) ;
V_194 = F_144 ( F_122 ( V_203 -> V_120 ) ) ;
if ( V_194 )
V_70 = & V_203 -> V_122 ;
} else {
if ( ! F_124 ( V_29 , sizeof( * V_205 ) ) ) {
V_66 = - V_46 ;
goto V_53;
}
V_205 = (struct V_204 * ) F_70 ( V_29 ) ;
if ( ! V_205 -> V_207 )
V_70 = & V_205 -> V_208 ;
V_194 = V_18 ( F_144 ( F_145 ( V_205 ) ) , 1UL ) ;
}
V_206 = V_70 && F_71 ( V_70 ) ;
if ( V_206 ) {
V_90 . V_4 = F_2 ( V_10 ) ;
V_90 . V_7 . V_11 = V_104 -> V_90 ;
F_138 ( V_27 , V_60 , & V_27 -> V_158 ,
& V_90 , V_194 ) ;
goto V_53;
} else if ( ! V_70 ) {
goto V_53;
}
V_23 = F_14 ( F_32 ( V_27 -> V_13 , V_27 ) , V_70 , V_5 ) ;
if ( ! V_23 )
goto V_53;
V_194 *= V_27 -> V_201 ;
if ( V_23 -> V_54 &&
( F_31 ( & V_23 -> V_52 ) ?
F_142 ( V_23 -> V_52 . V_202 , V_134 + V_194 ) :
F_116 ( & V_23 -> V_52 ) >= 0 ) )
F_42 ( & V_23 -> V_52 , V_134 + V_194 ) ;
for ( V_58 = & V_23 -> V_55 ;
( V_48 = F_32 ( * V_58 , V_27 ) ) != NULL ;
V_58 = & V_48 -> V_59 ) {
if ( F_31 ( & V_48 -> V_52 ) ?
F_142 ( V_48 -> V_52 . V_202 , V_134 + V_194 ) :
F_116 ( & V_48 -> V_52 ) >= 0 )
F_42 ( & V_48 -> V_52 , V_134 + V_194 ) ;
}
V_53:
F_35 ( & V_27 -> V_50 ) ;
return V_66 ;
}
static void
F_146 ( struct V_26 * V_27 ,
struct V_123 * V_60 ,
struct V_1 * V_70 ,
struct V_154 * V_155 ,
struct V_144 * V_153 )
{
struct V_12 * V_13 ;
struct V_20 * V_23 ;
struct V_47 * V_48 ;
unsigned long V_134 ;
unsigned long time ;
F_29 ( & V_27 -> V_50 ) ;
if ( ! F_30 ( V_27 -> V_51 ) ||
( V_60 && V_60 -> V_62 == V_135 ) )
goto V_53;
V_13 = F_32 ( V_27 -> V_13 , V_27 ) ;
V_23 = F_12 ( V_13 , V_70 ) ;
if ( ! V_23 )
goto V_53;
if ( V_60 && ( V_60 -> V_209 & V_210 ) ) {
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
if ( F_31 ( & V_155 -> V_52 ) )
goto V_53;
if ( V_27 -> V_156 ) {
F_102 ( V_27 , V_60 , & V_23 -> V_24 ) ;
time = V_63 + V_27 -> V_201 *
V_27 -> V_98 ;
F_42 ( & V_153 -> V_52 , time ) ;
for ( V_48 = F_32 ( V_23 -> V_55 , V_27 ) ;
V_48 != NULL ;
V_48 = F_32 ( V_48 -> V_59 , V_27 ) ) {
if ( V_48 -> V_60 != V_60 )
continue;
if ( ! F_44 ( & V_48 -> V_54 ) &&
( F_31 ( & V_48 -> V_52 ) ?
F_142 ( V_48 -> V_52 . V_202 , time ) :
F_116 ( & V_48 -> V_52 ) >= 0 ) ) {
F_42 ( & V_48 -> V_52 , time ) ;
}
break;
}
}
V_134 = V_63 ;
time = V_134 + V_27 -> V_201 *
V_27 -> V_98 ;
if ( ! V_60 ) {
if ( V_23 -> V_54 &&
( F_31 ( & V_23 -> V_52 ) ?
F_142 ( V_23 -> V_52 . V_202 , time ) :
F_116 ( & V_23 -> V_52 ) >= 0 ) ) {
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
F_142 ( V_48 -> V_52 . V_202 , time ) :
F_116 ( & V_48 -> V_52 ) >= 0 ) ) {
F_42 ( & V_48 -> V_52 , time ) ;
}
break;
}
V_53:
F_35 ( & V_27 -> V_50 ) ;
}
static void F_125 ( struct V_26 * V_27 ,
struct V_123 * V_60 ,
T_1 V_70 ,
T_2 V_5 )
{
struct V_1 V_140 ;
struct V_144 * V_153 ;
if ( F_90 ( V_70 ) )
return;
V_153 = V_60 ? & V_60 -> V_146 : & V_27 -> V_146 ;
V_140 . V_7 . V_8 = V_70 ;
V_140 . V_4 = F_2 ( V_6 ) ;
V_140 . V_5 = V_5 ;
F_146 ( V_27 , V_60 , & V_140 , & V_27 -> V_157 ,
V_153 ) ;
}
static void F_129 ( struct V_26 * V_27 ,
struct V_123 * V_60 ,
const struct V_19 * V_70 ,
T_2 V_5 )
{
struct V_1 V_140 ;
struct V_144 * V_153 ;
if ( F_92 ( V_70 ) )
return;
V_153 = V_60 ? & V_60 -> V_147 : & V_27 -> V_147 ;
V_140 . V_7 . V_11 = * V_70 ;
V_140 . V_4 = F_2 ( V_10 ) ;
V_140 . V_5 = V_5 ;
F_146 ( V_27 , V_60 , & V_140 , & V_27 -> V_158 ,
V_153 ) ;
}
static int F_147 ( struct V_26 * V_27 ,
struct V_123 * V_60 ,
struct V_28 * V_29 ,
T_3 V_5 )
{
struct V_28 * V_211 = NULL ;
struct V_71 * V_72 ;
int V_66 ;
V_66 = F_148 ( V_29 , & V_211 ) ;
if ( V_66 == - V_212 ) {
if ( ! F_90 ( F_18 ( V_29 ) -> V_33 ) )
F_17 ( V_29 ) -> V_213 = 1 ;
return 0 ;
} else if ( V_66 < 0 ) {
return V_66 ;
}
F_17 ( V_29 ) -> V_31 = 1 ;
V_72 = F_61 ( V_29 ) ;
switch ( V_72 -> type ) {
case V_214 :
case V_215 :
F_17 ( V_29 ) -> V_213 = 1 ;
V_66 = F_89 ( V_27 , V_60 , V_72 -> V_70 , V_5 ) ;
break;
case V_216 :
V_66 = F_120 ( V_27 , V_60 , V_211 , V_5 ) ;
break;
case V_96 :
V_66 = F_139 ( V_27 , V_60 , V_211 , V_5 ) ;
break;
case V_217 :
F_125 ( V_27 , V_60 , V_72 -> V_70 , V_5 ) ;
break;
}
if ( V_211 && V_211 != V_29 )
F_68 ( V_211 ) ;
return V_66 ;
}
static int F_149 ( struct V_26 * V_27 ,
struct V_123 * V_60 ,
struct V_28 * V_29 ,
T_3 V_5 )
{
struct V_28 * V_211 = NULL ;
struct V_105 * V_203 ;
int V_66 ;
V_66 = F_150 ( V_29 , & V_211 ) ;
if ( V_66 == - V_212 ) {
if ( ! F_92 ( & F_19 ( V_29 ) -> V_33 ) )
F_17 ( V_29 ) -> V_213 = 1 ;
return 0 ;
} else if ( V_66 < 0 ) {
return V_66 ;
}
F_17 ( V_29 ) -> V_31 = 1 ;
V_203 = (struct V_105 * ) F_151 ( V_29 ) ;
switch ( V_203 -> V_116 ) {
case V_218 :
F_17 ( V_29 ) -> V_213 = 1 ;
V_66 = F_91 ( V_27 , V_60 , & V_203 -> V_122 , V_5 ) ;
break;
case V_219 :
V_66 = F_126 ( V_27 , V_60 , V_211 , V_5 ) ;
break;
case V_117 :
V_66 = F_143 ( V_27 , V_60 , V_211 , V_5 ) ;
break;
case V_220 :
F_129 ( V_27 , V_60 , & V_203 -> V_122 , V_5 ) ;
break;
}
if ( V_211 && V_211 != V_29 )
F_68 ( V_211 ) ;
return V_66 ;
}
int F_152 ( struct V_26 * V_27 , struct V_123 * V_60 ,
struct V_28 * V_29 , T_3 V_5 )
{
F_17 ( V_29 ) -> V_31 = 0 ;
F_17 ( V_29 ) -> V_213 = 0 ;
if ( V_27 -> V_30 )
return 0 ;
switch ( V_29 -> V_32 ) {
case F_2 ( V_6 ) :
return F_147 ( V_27 , V_60 , V_29 , V_5 ) ;
#if F_3 ( V_9 )
case F_2 ( V_10 ) :
return F_149 ( V_27 , V_60 , V_29 , V_5 ) ;
#endif
}
return 0 ;
}
static void F_153 ( struct V_26 * V_27 ,
struct V_144 * V_145 ,
struct V_221 * V_222 )
{
F_29 ( & V_27 -> V_50 ) ;
if ( V_145 -> V_159 < V_27 -> V_160 )
V_145 -> V_159 ++ ;
F_154 ( V_222 -> V_60 , NULL ) ;
F_105 ( V_27 , NULL , V_145 ) ;
F_35 ( & V_27 -> V_50 ) ;
}
static void F_155 ( unsigned long V_49 )
{
struct V_26 * V_27 = ( void * ) V_49 ;
F_153 ( V_27 , & V_27 -> V_146 , & V_27 -> V_148 ) ;
}
static void F_156 ( unsigned long V_49 )
{
struct V_26 * V_27 = ( void * ) V_49 ;
F_153 ( V_27 , & V_27 -> V_147 , & V_27 -> V_149 ) ;
}
void F_157 ( struct V_26 * V_27 )
{
V_27 -> V_125 = 4 ;
V_27 -> V_127 = 512 ;
V_27 -> V_141 = 1 ;
V_27 -> V_156 = 0 ;
V_27 -> V_91 = 0 ;
V_27 -> V_201 = 2 ;
V_27 -> V_160 = 2 ;
V_27 -> V_98 = V_100 ;
V_27 -> V_99 = 10 * V_100 ;
V_27 -> V_161 = 125 * V_100 / 4 ;
V_27 -> V_162 = 125 * V_100 ;
V_27 -> V_196 = 255 * V_100 ;
V_27 -> V_136 = 260 * V_100 ;
V_27 -> V_157 . V_195 = 0 ;
V_27 -> V_148 . V_60 = NULL ;
#if F_3 ( V_9 )
V_27 -> V_158 . V_195 = 0 ;
V_27 -> V_149 . V_60 = NULL ;
#endif
F_158 ( & V_27 -> V_50 ) ;
F_84 ( & V_27 -> V_142 ,
F_96 , 0 ) ;
F_84 ( & V_27 -> V_157 . V_52 ,
F_99 , ( unsigned long ) V_27 ) ;
F_84 ( & V_27 -> V_146 . V_52 , F_155 ,
( unsigned long ) V_27 ) ;
#if F_3 ( V_9 )
F_84 ( & V_27 -> V_158 . V_52 ,
F_100 , ( unsigned long ) V_27 ) ;
F_84 ( & V_27 -> V_147 . V_52 , F_156 ,
( unsigned long ) V_27 ) ;
#endif
}
static void F_159 ( struct V_26 * V_27 ,
struct V_144 * V_145 )
{
V_145 -> V_159 = 0 ;
if ( V_27 -> V_30 )
return;
F_42 ( & V_145 -> V_52 , V_63 ) ;
}
void F_160 ( struct V_26 * V_27 )
{
F_159 ( V_27 , & V_27 -> V_146 ) ;
#if F_3 ( V_9 )
F_159 ( V_27 , & V_27 -> V_147 ) ;
#endif
}
void F_161 ( struct V_26 * V_27 )
{
F_114 ( & V_27 -> V_142 ) ;
F_114 ( & V_27 -> V_157 . V_52 ) ;
F_114 ( & V_27 -> V_146 . V_52 ) ;
#if F_3 ( V_9 )
F_114 ( & V_27 -> V_158 . V_52 ) ;
F_114 ( & V_27 -> V_147 . V_52 ) ;
#endif
}
void F_162 ( struct V_26 * V_27 )
{
struct V_12 * V_13 ;
struct V_20 * V_23 ;
struct V_164 * V_165 ;
V_16 V_45 ;
int V_43 ;
F_111 ( & V_27 -> V_50 ) ;
V_13 = F_32 ( V_27 -> V_13 , V_27 ) ;
if ( ! V_13 )
goto V_53;
V_27 -> V_13 = NULL ;
V_45 = V_13 -> V_45 ;
for ( V_43 = 0 ; V_43 < V_13 -> V_18 ; V_43 ++ ) {
F_112 (mp, n, &mdb->mhash[i],
hlist[ver]) {
F_40 ( & V_23 -> V_52 ) ;
F_34 ( & V_23 -> V_36 , F_27 ) ;
}
}
if ( V_13 -> V_37 ) {
F_113 ( & V_27 -> V_50 ) ;
F_163 () ;
F_111 ( & V_27 -> V_50 ) ;
F_37 ( V_13 -> V_37 ) ;
}
V_13 -> V_37 = V_13 ;
F_34 ( & V_13 -> V_36 , F_20 ) ;
V_53:
F_113 ( & V_27 -> V_50 ) ;
}
int F_164 ( struct V_26 * V_27 , unsigned long V_223 )
{
int V_66 = - V_46 ;
F_111 ( & V_27 -> V_50 ) ;
switch ( V_223 ) {
case 0 :
case 2 :
F_40 ( & V_27 -> V_142 ) ;
case 1 :
V_27 -> V_141 = V_223 ;
V_66 = 0 ;
break;
}
F_113 ( & V_27 -> V_50 ) ;
return V_66 ;
}
int F_165 ( struct V_123 * V_48 , unsigned long V_223 )
{
struct V_26 * V_27 = V_48 -> V_27 ;
int V_66 = - V_46 ;
F_29 ( & V_27 -> V_50 ) ;
switch ( V_223 ) {
case 0 :
case 1 :
case 2 :
V_48 -> V_141 = V_223 ;
V_66 = 0 ;
if ( V_223 < 2 && ! F_44 ( & V_48 -> V_143 ) ) {
F_94 ( & V_48 -> V_143 ) ;
F_95 ( V_27 -> V_51 , V_48 , V_61 ) ;
}
if ( V_223 == 1 )
break;
F_40 ( & V_48 -> V_142 ) ;
if ( V_223 == 0 )
break;
F_118 ( V_27 , V_48 ) ;
break;
}
F_35 ( & V_27 -> V_50 ) ;
return V_66 ;
}
static void F_98 ( struct V_26 * V_27 ,
struct V_144 * V_145 )
{
struct V_123 * V_60 ;
F_159 ( V_27 , V_145 ) ;
F_166 (port, &br->port_list, list) {
if ( V_60 -> V_62 == V_135 ||
V_60 -> V_62 == V_163 )
continue;
if ( V_145 == & V_27 -> V_146 )
F_115 ( & V_60 -> V_146 ) ;
#if F_3 ( V_9 )
else
F_115 ( & V_60 -> V_147 ) ;
#endif
}
}
int F_167 ( struct V_26 * V_27 , unsigned long V_223 )
{
int V_66 = 0 ;
struct V_12 * V_13 ;
F_111 ( & V_27 -> V_50 ) ;
if ( V_27 -> V_30 == ! V_223 )
goto V_224;
V_27 -> V_30 = ! V_223 ;
if ( V_27 -> V_30 )
goto V_224;
if ( ! F_30 ( V_27 -> V_51 ) )
goto V_224;
V_13 = F_32 ( V_27 -> V_13 , V_27 ) ;
if ( V_13 ) {
if ( V_13 -> V_37 ) {
V_66 = - V_130 ;
V_225:
V_27 -> V_30 = ! ! V_223 ;
goto V_224;
}
V_66 = F_45 ( & V_27 -> V_13 , V_13 -> V_18 ,
V_27 -> V_125 ) ;
if ( V_66 )
goto V_225;
}
F_98 ( V_27 , & V_27 -> V_146 ) ;
#if F_3 ( V_9 )
F_98 ( V_27 , & V_27 -> V_147 ) ;
#endif
V_224:
F_113 ( & V_27 -> V_50 ) ;
return V_66 ;
}
int F_168 ( struct V_26 * V_27 , unsigned long V_223 )
{
unsigned long V_194 ;
V_223 = ! ! V_223 ;
F_111 ( & V_27 -> V_50 ) ;
if ( V_27 -> V_156 == V_223 )
goto V_224;
V_27 -> V_156 = V_223 ;
if ( ! V_223 )
goto V_224;
V_194 = V_27 -> V_99 ;
if ( ! F_31 ( & V_27 -> V_157 . V_52 ) )
V_27 -> V_157 . V_195 = V_63 + V_194 ;
F_98 ( V_27 , & V_27 -> V_146 ) ;
#if F_3 ( V_9 )
if ( ! F_31 ( & V_27 -> V_158 . V_52 ) )
V_27 -> V_158 . V_195 = V_63 + V_194 ;
F_98 ( V_27 , & V_27 -> V_147 ) ;
#endif
V_224:
F_113 ( & V_27 -> V_50 ) ;
return 0 ;
}
int F_169 ( struct V_26 * V_27 , unsigned long V_223 )
{
int V_66 = - V_46 ;
V_16 V_37 ;
struct V_12 * V_13 ;
F_111 ( & V_27 -> V_50 ) ;
if ( ! F_170 ( V_223 ) )
goto V_224;
V_13 = F_32 ( V_27 -> V_13 , V_27 ) ;
if ( V_13 && V_223 < V_13 -> V_56 )
goto V_224;
V_66 = 0 ;
V_37 = V_27 -> V_127 ;
V_27 -> V_127 = V_223 ;
if ( V_13 ) {
if ( V_13 -> V_37 ) {
V_66 = - V_130 ;
V_225:
V_27 -> V_127 = V_37 ;
goto V_224;
}
V_66 = F_45 ( & V_27 -> V_13 , V_27 -> V_127 ,
V_27 -> V_125 ) ;
if ( V_66 )
goto V_225;
}
V_224:
F_113 ( & V_27 -> V_50 ) ;
return V_66 ;
}
int F_171 ( struct V_226 * V_51 ,
struct V_227 * V_228 )
{
struct V_26 * V_27 ;
struct V_123 * V_60 ;
struct V_47 * V_70 ;
struct V_228 * V_229 ;
int V_124 = 0 ;
F_172 () ;
if ( ! V_228 || ! F_173 ( V_51 ) )
goto V_224;
V_60 = F_174 ( V_51 ) ;
if ( ! V_60 || ! V_60 -> V_27 )
goto V_224;
V_27 = V_60 -> V_27 ;
F_175 (port, &br->port_list, list) {
if ( ! V_60 -> V_51 || V_60 -> V_51 == V_51 )
continue;
F_11 (group, &port->mglist, mglist) {
V_229 = F_47 ( sizeof( * V_229 ) , V_67 ) ;
if ( ! V_229 )
goto V_224;
V_229 -> V_24 = V_70 -> V_24 ;
F_176 ( & V_229 -> V_230 , V_228 ) ;
V_124 ++ ;
}
}
V_224:
F_177 () ;
return V_124 ;
}
bool F_178 ( struct V_226 * V_51 , int V_4 )
{
struct V_26 * V_27 ;
struct V_123 * V_60 ;
struct V_73 V_74 ;
bool V_231 = false ;
F_172 () ;
if ( ! F_173 ( V_51 ) )
goto V_224;
V_60 = F_174 ( V_51 ) ;
if ( ! V_60 || ! V_60 -> V_27 )
goto V_224;
V_27 = V_60 -> V_27 ;
memset ( & V_74 , 0 , sizeof( V_74 ) ) ;
V_74 . V_80 = F_2 ( V_4 ) ;
V_231 = F_179 ( V_27 , & V_74 ) ;
V_224:
F_177 () ;
return V_231 ;
}
bool F_180 ( struct V_226 * V_51 , int V_4 )
{
struct V_26 * V_27 ;
struct V_123 * V_60 ;
bool V_231 = false ;
F_172 () ;
if ( ! F_173 ( V_51 ) )
goto V_224;
V_60 = F_174 ( V_51 ) ;
if ( ! V_60 || ! V_60 -> V_27 )
goto V_224;
V_27 = V_60 -> V_27 ;
switch ( V_4 ) {
case V_6 :
if ( ! F_31 ( & V_27 -> V_157 . V_52 ) ||
F_16 ( V_27 -> V_148 . V_60 ) == V_60 )
goto V_224;
break;
#if F_3 ( V_9 )
case V_10 :
if ( ! F_31 ( & V_27 -> V_158 . V_52 ) ||
F_16 ( V_27 -> V_149 . V_60 ) == V_60 )
goto V_224;
break;
#endif
default:
goto V_224;
}
V_231 = true ;
V_224:
F_177 () ;
return V_231 ;
}
