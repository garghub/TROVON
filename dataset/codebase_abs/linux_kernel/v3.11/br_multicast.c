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
F_34 ( & V_48 -> V_36 , F_26 ) ;
if ( ! V_23 -> V_55 && ! V_23 -> V_54 && V_23 -> V_60 &&
F_30 ( V_27 -> V_51 ) )
F_41 ( & V_23 -> V_52 , V_61 ) ;
return;
}
F_37 ( 1 ) ;
}
static void F_42 ( unsigned long V_49 )
{
struct V_47 * V_57 = ( void * ) V_49 ;
struct V_26 * V_27 = V_57 -> V_62 -> V_27 ;
F_29 ( & V_27 -> V_50 ) ;
if ( ! F_30 ( V_27 -> V_51 ) || F_31 ( & V_57 -> V_52 ) ||
F_43 ( & V_57 -> V_54 ) || V_57 -> V_63 & V_64 )
goto V_53;
F_36 ( V_27 , V_57 ) ;
V_53:
F_35 ( & V_27 -> V_50 ) ;
}
static int F_44 ( struct V_12 T_4 * * V_65 , int V_18 ,
int V_40 )
{
struct V_12 * V_37 = F_45 ( * V_65 , 1 ) ;
struct V_12 * V_13 ;
int V_66 ;
V_13 = F_46 ( sizeof( * V_13 ) , V_67 ) ;
if ( ! V_13 )
return - V_68 ;
V_13 -> V_18 = V_18 ;
V_13 -> V_37 = V_37 ;
V_13 -> V_38 = F_47 ( V_18 * sizeof( * V_13 -> V_38 ) , V_67 ) ;
if ( ! V_13 -> V_38 ) {
F_22 ( V_13 ) ;
return - V_68 ;
}
V_13 -> V_56 = V_37 ? V_37 -> V_56 : 0 ;
V_13 -> V_45 = V_37 ? V_37 -> V_45 ^ 1 : 0 ;
if ( ! V_37 || V_40 )
F_48 ( & V_13 -> V_17 , sizeof( V_13 -> V_17 ) ) ;
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
static struct V_28 * F_49 ( struct V_26 * V_27 ,
T_1 V_70 )
{
struct V_28 * V_29 ;
struct V_71 * V_72 ;
struct V_73 * V_74 ;
struct V_75 * V_76 ;
V_29 = F_50 ( V_27 -> V_51 , sizeof( * V_74 ) + sizeof( * V_76 ) +
sizeof( * V_72 ) + 4 ) ;
if ( ! V_29 )
goto V_53;
V_29 -> V_32 = F_2 ( V_6 ) ;
F_51 ( V_29 ) ;
V_74 = F_52 ( V_29 ) ;
memcpy ( V_74 -> V_77 , V_27 -> V_51 -> V_78 , 6 ) ;
V_74 -> V_79 [ 0 ] = 1 ;
V_74 -> V_79 [ 1 ] = 0 ;
V_74 -> V_79 [ 2 ] = 0x5e ;
V_74 -> V_79 [ 3 ] = 0 ;
V_74 -> V_79 [ 4 ] = 0 ;
V_74 -> V_79 [ 5 ] = 1 ;
V_74 -> V_80 = F_2 ( V_6 ) ;
F_53 ( V_29 , sizeof( * V_74 ) ) ;
F_54 ( V_29 , V_29 -> V_42 ) ;
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
F_55 ( V_27 -> V_51 , 0 , V_92 ) : 0 ;
V_76 -> V_33 = F_56 ( V_93 ) ;
( ( V_94 * ) & V_76 [ 1 ] ) [ 0 ] = V_95 ;
( ( V_94 * ) & V_76 [ 1 ] ) [ 1 ] = 4 ;
( ( V_94 * ) & V_76 [ 1 ] ) [ 2 ] = 0 ;
( ( V_94 * ) & V_76 [ 1 ] ) [ 3 ] = 0 ;
F_57 ( V_76 ) ;
F_53 ( V_29 , 24 ) ;
F_58 ( V_29 , V_29 -> V_42 ) ;
V_72 = F_59 ( V_29 ) ;
V_72 -> type = V_96 ;
V_72 -> V_97 = ( V_70 ? V_27 -> V_98 :
V_27 -> V_99 ) /
( V_100 / V_101 ) ;
V_72 -> V_70 = V_70 ;
V_72 -> V_102 = 0 ;
V_72 -> V_102 = F_60 ( ( void * ) V_72 , sizeof( struct V_71 ) ) ;
F_53 ( V_29 , sizeof( * V_72 ) ) ;
F_61 ( V_29 , sizeof( * V_74 ) ) ;
V_53:
return V_29 ;
}
static struct V_28 * F_62 ( struct V_26 * V_27 ,
const struct V_19 * V_70 )
{
struct V_28 * V_29 ;
struct V_103 * V_104 ;
struct V_105 * V_106 ;
struct V_73 * V_74 ;
V_94 * V_107 ;
unsigned long V_108 ;
V_29 = F_50 ( V_27 -> V_51 , sizeof( * V_74 ) + sizeof( * V_104 ) +
8 + sizeof( * V_106 ) ) ;
if ( ! V_29 )
goto V_53;
V_29 -> V_32 = F_2 ( V_10 ) ;
F_51 ( V_29 ) ;
V_74 = F_52 ( V_29 ) ;
memcpy ( V_74 -> V_77 , V_27 -> V_51 -> V_78 , 6 ) ;
V_74 -> V_80 = F_2 ( V_10 ) ;
F_53 ( V_29 , sizeof( * V_74 ) ) ;
F_54 ( V_29 , V_29 -> V_42 ) ;
V_104 = F_19 ( V_29 ) ;
* ( V_15 T_1 * ) V_104 = F_56 ( 0x60000000 ) ;
V_104 -> V_109 = F_2 ( 8 + sizeof( * V_106 ) ) ;
V_104 -> V_110 = V_111 ;
V_104 -> V_112 = 1 ;
F_63 ( & V_104 -> V_33 , F_56 ( 0xff020000 ) , 0 , 0 , F_56 ( 1 ) ) ;
if ( F_64 ( F_65 ( V_27 -> V_51 ) , V_27 -> V_51 , & V_104 -> V_33 , 0 ,
& V_104 -> V_90 ) ) {
F_66 ( V_29 ) ;
return NULL ;
}
F_67 ( & V_104 -> V_33 , V_74 -> V_79 ) ;
V_107 = ( V_94 * ) ( V_104 + 1 ) ;
V_107 [ 0 ] = V_113 ;
V_107 [ 1 ] = 0 ;
V_107 [ 2 ] = V_114 ;
V_107 [ 3 ] = 2 ;
V_107 [ 4 ] = 0 ;
V_107 [ 5 ] = 0 ;
V_107 [ 6 ] = V_115 ;
V_107 [ 7 ] = V_115 ;
F_53 ( V_29 , sizeof( * V_104 ) + 8 ) ;
F_58 ( V_29 , V_29 -> V_42 ) ;
V_106 = (struct V_105 * ) F_68 ( V_29 ) ;
V_108 = F_69 ( V_70 ) ?
V_27 -> V_99 :
V_27 -> V_98 ;
V_106 -> V_116 = V_117 ;
V_106 -> V_118 = 0 ;
V_106 -> V_119 = 0 ;
V_106 -> V_120 = F_2 ( ( T_3 ) F_70 ( V_108 ) ) ;
V_106 -> V_121 = 0 ;
V_106 -> V_122 = * V_70 ;
V_106 -> V_119 = F_71 ( & V_104 -> V_90 , & V_104 -> V_33 ,
sizeof( * V_106 ) , V_113 ,
F_72 ( V_106 ,
sizeof( * V_106 ) , 0 ) ) ;
F_53 ( V_29 , sizeof( * V_106 ) ) ;
F_61 ( V_29 , sizeof( * V_74 ) ) ;
V_53:
return V_29 ;
}
static struct V_28 * F_73 ( struct V_26 * V_27 ,
struct V_1 * V_24 )
{
switch ( V_24 -> V_4 ) {
case F_2 ( V_6 ) :
return F_49 ( V_27 , V_24 -> V_7 . V_8 ) ;
#if F_3 ( V_9 )
case F_2 ( V_10 ) :
return F_62 ( V_27 , & V_24 -> V_7 . V_11 ) ;
#endif
}
return NULL ;
}
static struct V_20 * F_74 (
struct V_26 * V_27 , struct V_123 * V_62 ,
struct V_1 * V_70 , int V_22 )
{
struct V_12 * V_13 ;
struct V_20 * V_23 ;
unsigned int V_124 = 0 ;
unsigned int V_18 ;
int V_40 ;
int V_66 ;
V_13 = F_45 ( V_27 -> V_13 , 1 ) ;
F_24 (mp, &mdb->mhash[hash], hlist[mdb->ver]) {
V_124 ++ ;
if ( F_75 ( F_1 ( V_70 , & V_23 -> V_24 ) ) )
return V_23 ;
}
V_40 = 0 ;
V_18 = V_13 -> V_18 ;
if ( F_75 ( V_124 > V_27 -> V_125 && V_124 ) ) {
if ( F_76 () )
F_77 ( V_27 , L_1
L_2 ,
V_62 ? V_62 -> V_51 -> V_126 : V_27 -> V_51 -> V_126 ) ;
V_40 = V_27 -> V_125 ;
}
if ( V_13 -> V_56 >= V_18 ) {
V_18 *= 2 ;
if ( F_75 ( V_18 > V_27 -> V_127 ) ) {
F_78 ( V_27 , L_3
L_4 ,
V_27 -> V_127 ,
V_62 ? V_62 -> V_51 -> V_126 : V_27 -> V_51 -> V_126 ) ;
V_66 = - V_128 ;
V_129:
V_27 -> V_30 = 1 ;
goto V_66;
}
}
if ( V_18 > V_13 -> V_18 || V_40 ) {
if ( V_13 -> V_37 ) {
if ( F_76 () )
F_77 ( V_27 , L_1
L_5 ,
V_62 ? V_62 -> V_51 -> V_126 : V_27 -> V_51 -> V_126 ) ;
V_66 = - V_130 ;
goto V_66;
}
V_66 = F_44 ( & V_27 -> V_13 , V_18 , V_40 ) ;
if ( V_66 ) {
F_78 ( V_27 , L_6
L_7 ,
V_62 ? V_62 -> V_51 -> V_126 : V_27 -> V_51 -> V_126 ,
V_13 -> V_56 , V_66 ) ;
goto V_129;
}
V_66 = - V_131 ;
goto V_66;
}
return NULL ;
V_66:
V_23 = F_79 ( V_66 ) ;
return V_23 ;
}
struct V_20 * F_80 ( struct V_26 * V_27 ,
struct V_123 * V_62 , struct V_1 * V_70 )
{
struct V_12 * V_13 ;
struct V_20 * V_23 ;
int V_22 ;
int V_66 ;
V_13 = F_45 ( V_27 -> V_13 , 1 ) ;
if ( ! V_13 ) {
V_66 = F_44 ( & V_27 -> V_13 , V_132 , 0 ) ;
if ( V_66 )
return F_79 ( V_66 ) ;
goto V_133;
}
V_22 = F_9 ( V_13 , V_70 ) ;
V_23 = F_74 ( V_27 , V_62 , V_70 , V_22 ) ;
switch ( F_81 ( V_23 ) ) {
case 0 :
break;
case - V_131 :
V_133:
V_13 = F_45 ( V_27 -> V_13 , 1 ) ;
V_22 = F_9 ( V_13 , V_70 ) ;
break;
default:
goto V_53;
}
V_23 = F_47 ( sizeof( * V_23 ) , V_67 ) ;
if ( F_75 ( ! V_23 ) )
return F_79 ( - V_68 ) ;
V_23 -> V_27 = V_27 ;
V_23 -> V_24 = * V_70 ;
F_82 ( & V_23 -> V_52 , F_28 ,
( unsigned long ) V_23 ) ;
F_83 ( & V_23 -> V_44 [ V_13 -> V_45 ] , & V_13 -> V_38 [ V_22 ] ) ;
V_13 -> V_56 ++ ;
V_53:
return V_23 ;
}
struct V_47 * F_84 (
struct V_123 * V_62 ,
struct V_1 * V_70 ,
struct V_47 T_4 * V_59 ,
unsigned char V_63 )
{
struct V_47 * V_48 ;
V_48 = F_47 ( sizeof( * V_48 ) , V_67 ) ;
if ( F_75 ( ! V_48 ) )
return NULL ;
V_48 -> V_24 = * V_70 ;
V_48 -> V_62 = V_62 ;
V_48 -> V_63 = V_63 ;
F_38 ( V_48 -> V_59 , V_59 ) ;
F_25 ( & V_48 -> V_54 , & V_62 -> V_54 ) ;
F_82 ( & V_48 -> V_52 , F_42 ,
( unsigned long ) V_48 ) ;
return V_48 ;
}
static int F_85 ( struct V_26 * V_27 ,
struct V_123 * V_62 ,
struct V_1 * V_70 )
{
struct V_20 * V_23 ;
struct V_47 * V_48 ;
struct V_47 T_4 * * V_58 ;
int V_66 ;
F_29 ( & V_27 -> V_50 ) ;
if ( ! F_30 ( V_27 -> V_51 ) ||
( V_62 && V_62 -> V_63 == V_134 ) )
goto V_53;
V_23 = F_80 ( V_27 , V_62 , V_70 ) ;
V_66 = F_81 ( V_23 ) ;
if ( F_86 ( V_23 ) )
goto V_66;
if ( ! V_62 ) {
V_23 -> V_54 = true ;
goto V_53;
}
for ( V_58 = & V_23 -> V_55 ;
( V_48 = F_32 ( * V_58 , V_27 ) ) != NULL ;
V_58 = & V_48 -> V_59 ) {
if ( V_48 -> V_62 == V_62 )
goto V_53;
if ( ( unsigned long ) V_48 -> V_62 < ( unsigned long ) V_62 )
break;
}
V_48 = F_84 ( V_62 , V_70 , * V_58 , V_135 ) ;
if ( F_75 ( ! V_48 ) )
goto V_66;
F_38 ( * V_58 , V_48 ) ;
F_87 ( V_27 -> V_51 , V_62 , V_70 , V_136 ) ;
V_53:
V_66 = 0 ;
V_66:
F_35 ( & V_27 -> V_50 ) ;
return V_66 ;
}
static int F_88 ( struct V_26 * V_27 ,
struct V_123 * V_62 ,
T_1 V_70 ,
T_2 V_5 )
{
struct V_1 V_137 ;
if ( F_89 ( V_70 ) )
return 0 ;
V_137 . V_7 . V_8 = V_70 ;
V_137 . V_4 = F_2 ( V_6 ) ;
V_137 . V_5 = V_5 ;
return F_85 ( V_27 , V_62 , & V_137 ) ;
}
static int F_90 ( struct V_26 * V_27 ,
struct V_123 * V_62 ,
const struct V_19 * V_70 ,
T_2 V_5 )
{
struct V_1 V_137 ;
if ( ! F_91 ( V_70 ) )
return 0 ;
V_137 . V_7 . V_11 = * V_70 ;
V_137 . V_4 = F_2 ( V_10 ) ;
V_137 . V_5 = V_5 ;
return F_85 ( V_27 , V_62 , & V_137 ) ;
}
static void F_92 ( unsigned long V_49 )
{
struct V_123 * V_62 = ( void * ) V_49 ;
struct V_26 * V_27 = V_62 -> V_27 ;
F_29 ( & V_27 -> V_50 ) ;
if ( V_62 -> V_138 != 1 ||
F_31 ( & V_62 -> V_139 ) ||
F_43 ( & V_62 -> V_140 ) )
goto V_53;
F_93 ( & V_62 -> V_140 ) ;
V_53:
F_35 ( & V_27 -> V_50 ) ;
}
static void F_94 ( unsigned long V_49 )
{
}
static void F_95 ( struct V_26 * V_27 ,
struct V_141 * V_142 )
{
F_29 ( & V_27 -> V_50 ) ;
if ( ! F_30 ( V_27 -> V_51 ) || V_27 -> V_30 )
goto V_53;
F_96 ( V_27 , V_142 ) ;
V_53:
F_35 ( & V_27 -> V_50 ) ;
}
static void F_97 ( unsigned long V_49 )
{
struct V_26 * V_27 = ( void * ) V_49 ;
F_95 ( V_27 , & V_27 -> V_143 ) ;
}
static void F_98 ( unsigned long V_49 )
{
struct V_26 * V_27 = ( void * ) V_49 ;
F_95 ( V_27 , & V_27 -> V_144 ) ;
}
static void F_99 ( struct V_26 * V_27 ,
struct V_123 * V_62 ,
struct V_1 * V_14 )
{
struct V_28 * V_29 ;
V_29 = F_73 ( V_27 , V_14 ) ;
if ( ! V_29 )
return;
if ( V_62 ) {
F_100 ( V_29 , sizeof( struct V_73 ) ) ;
V_29 -> V_51 = V_62 -> V_51 ;
F_101 ( V_145 , V_146 , V_29 , NULL , V_29 -> V_51 ,
V_147 ) ;
} else
F_102 ( V_29 ) ;
}
static void F_103 ( struct V_26 * V_27 ,
struct V_123 * V_62 ,
struct V_141 * V_142 )
{
unsigned long time ;
struct V_1 V_137 ;
struct V_148 * V_149 = NULL ;
if ( ! F_30 ( V_27 -> V_51 ) || V_27 -> V_30 ||
! V_27 -> V_150 )
return;
memset ( & V_137 . V_7 , 0 , sizeof( V_137 . V_7 ) ) ;
if ( V_62 ? ( V_142 == & V_62 -> V_143 ) :
( V_142 == & V_27 -> V_143 ) ) {
V_149 = & V_27 -> V_151 ;
V_137 . V_4 = F_2 ( V_6 ) ;
#if F_3 ( V_9 )
} else {
V_149 = & V_27 -> V_152 ;
V_137 . V_4 = F_2 ( V_10 ) ;
#endif
}
if ( ! V_149 || F_31 ( & V_149 -> V_52 ) )
return;
F_99 ( V_27 , V_62 , & V_137 ) ;
time = V_61 ;
time += V_142 -> V_153 < V_27 -> V_154 ?
V_27 -> V_155 :
V_27 -> V_156 ;
F_41 ( & V_142 -> V_52 , time ) ;
}
static void F_104 ( struct V_123 * V_62 ,
struct V_141 * V_142 )
{
struct V_26 * V_27 = V_62 -> V_27 ;
F_29 ( & V_27 -> V_50 ) ;
if ( V_62 -> V_63 == V_134 ||
V_62 -> V_63 == V_157 )
goto V_53;
if ( V_142 -> V_153 < V_27 -> V_154 )
V_142 -> V_153 ++ ;
F_103 ( V_62 -> V_27 , V_62 , V_142 ) ;
V_53:
F_35 ( & V_27 -> V_50 ) ;
}
static void F_105 ( unsigned long V_49 )
{
struct V_123 * V_62 = ( void * ) V_49 ;
F_104 ( V_62 , & V_62 -> V_143 ) ;
}
static void F_106 ( unsigned long V_49 )
{
struct V_123 * V_62 = ( void * ) V_49 ;
F_104 ( V_62 , & V_62 -> V_144 ) ;
}
void F_107 ( struct V_123 * V_62 )
{
V_62 -> V_138 = 1 ;
F_82 ( & V_62 -> V_139 , F_92 ,
( unsigned long ) V_62 ) ;
F_82 ( & V_62 -> V_143 . V_52 , F_105 ,
( unsigned long ) V_62 ) ;
#if F_3 ( V_9 )
F_82 ( & V_62 -> V_144 . V_52 , F_106 ,
( unsigned long ) V_62 ) ;
#endif
}
void F_108 ( struct V_123 * V_62 )
{
F_109 ( & V_62 -> V_139 ) ;
}
static void F_110 ( struct V_141 * V_142 )
{
V_142 -> V_153 = 0 ;
if ( F_111 ( & V_142 -> V_52 ) >= 0 ||
F_40 ( & V_142 -> V_52 ) )
F_41 ( & V_142 -> V_52 , V_61 ) ;
}
void F_112 ( struct V_123 * V_62 )
{
struct V_26 * V_27 = V_62 -> V_27 ;
F_29 ( & V_27 -> V_50 ) ;
if ( V_27 -> V_30 || ! F_30 ( V_27 -> V_51 ) )
goto V_53;
F_110 ( & V_62 -> V_143 ) ;
#if F_3 ( V_9 )
F_110 ( & V_62 -> V_144 ) ;
#endif
V_53:
F_35 ( & V_27 -> V_50 ) ;
}
void F_113 ( struct V_123 * V_62 )
{
struct V_26 * V_27 = V_62 -> V_27 ;
struct V_47 * V_57 ;
struct V_158 * V_159 ;
F_29 ( & V_27 -> V_50 ) ;
F_114 (pg, n, &port->mglist, mglist)
F_36 ( V_27 , V_57 ) ;
if ( ! F_43 ( & V_62 -> V_140 ) )
F_93 ( & V_62 -> V_140 ) ;
F_40 ( & V_62 -> V_139 ) ;
F_40 ( & V_62 -> V_143 . V_52 ) ;
#if F_3 ( V_9 )
F_40 ( & V_62 -> V_144 . V_52 ) ;
#endif
F_35 ( & V_27 -> V_50 ) ;
}
static int F_115 ( struct V_26 * V_27 ,
struct V_123 * V_62 ,
struct V_28 * V_29 )
{
struct V_160 * V_72 ;
struct V_161 * V_162 ;
int V_43 ;
int V_42 ;
int V_163 ;
int type ;
int V_66 = 0 ;
T_1 V_70 ;
T_3 V_5 = 0 ;
if ( ! F_116 ( V_29 , sizeof( * V_72 ) ) )
return - V_46 ;
F_117 ( V_29 , & V_5 ) ;
V_72 = F_118 ( V_29 ) ;
V_163 = F_119 ( V_72 -> V_164 ) ;
V_42 = sizeof( * V_72 ) ;
for ( V_43 = 0 ; V_43 < V_163 ; V_43 ++ ) {
V_42 += sizeof( * V_162 ) ;
if ( ! F_116 ( V_29 , V_42 ) )
return - V_46 ;
V_162 = ( void * ) ( V_29 -> V_49 + V_42 - sizeof( * V_162 ) ) ;
V_70 = V_162 -> V_165 ;
type = V_162 -> V_166 ;
V_42 += F_119 ( V_162 -> V_167 ) * 4 ;
if ( ! F_116 ( V_29 , V_42 ) )
return - V_46 ;
switch ( type ) {
case V_168 :
case V_169 :
case V_170 :
case V_171 :
case V_172 :
case V_173 :
break;
default:
continue;
}
V_66 = F_88 ( V_27 , V_62 , V_70 , V_5 ) ;
if ( V_66 )
break;
}
return V_66 ;
}
static int F_120 ( struct V_26 * V_27 ,
struct V_123 * V_62 ,
struct V_28 * V_29 )
{
struct V_174 * V_175 ;
struct V_176 * V_162 ;
int V_43 ;
int V_42 ;
int V_163 ;
int V_66 = 0 ;
T_3 V_5 = 0 ;
if ( ! F_116 ( V_29 , sizeof( * V_175 ) ) )
return - V_46 ;
F_117 ( V_29 , & V_5 ) ;
V_175 = F_68 ( V_29 ) ;
V_163 = F_119 ( V_175 -> V_177 . V_178 [ 1 ] ) ;
V_42 = sizeof( * V_175 ) ;
for ( V_43 = 0 ; V_43 < V_163 ; V_43 ++ ) {
T_5 * V_179 , V_180 ;
V_179 = F_121 ( V_29 ,
V_42 + F_122 ( struct V_176 ,
V_167 ) ,
sizeof( V_180 ) , & V_180 ) ;
if ( ! V_179 )
return - V_46 ;
if ( ! F_116 ( V_29 ,
V_42 + sizeof( * V_162 ) +
sizeof( struct V_19 ) * F_119 ( * V_179 ) ) )
return - V_46 ;
V_162 = (struct V_176 * ) ( V_29 -> V_49 + V_42 ) ;
V_42 += sizeof( * V_162 ) +
sizeof( struct V_19 ) * F_119 ( * V_179 ) ;
switch ( V_162 -> V_166 ) {
case V_181 :
case V_182 :
case V_183 :
case V_184 :
case V_185 :
case V_186 :
break;
default:
continue;
}
V_66 = F_90 ( V_27 , V_62 , & V_162 -> V_165 ,
V_5 ) ;
if ( ! V_66 )
break;
}
return V_66 ;
}
static void
F_123 ( struct V_26 * V_27 ,
struct V_148 * V_149 ,
unsigned long V_187 )
{
if ( ! F_31 ( & V_149 -> V_52 ) )
V_149 -> V_188 = V_61 + V_187 ;
F_41 ( & V_149 -> V_52 , V_61 + V_27 -> V_189 ) ;
}
static void F_124 ( struct V_26 * V_27 ,
struct V_123 * V_62 )
{
struct V_123 * V_48 ;
struct V_158 * V_190 = NULL ;
F_24 (p, &br->router_list, rlist) {
if ( ( unsigned long ) V_62 >= ( unsigned long ) V_48 )
break;
V_190 = & V_48 -> V_140 ;
}
if ( V_190 )
F_125 ( V_190 , & V_62 -> V_140 ) ;
else
F_83 ( & V_62 -> V_140 , & V_27 -> V_191 ) ;
}
static void F_126 ( struct V_26 * V_27 ,
struct V_123 * V_62 )
{
unsigned long V_192 = V_61 ;
if ( ! V_62 ) {
if ( V_27 -> V_138 == 1 )
F_41 ( & V_27 -> V_139 ,
V_192 + V_27 -> V_189 ) ;
return;
}
if ( V_62 -> V_138 != 1 )
return;
if ( ! F_43 ( & V_62 -> V_140 ) )
goto V_52;
F_124 ( V_27 , V_62 ) ;
V_52:
F_41 ( & V_62 -> V_139 ,
V_192 + V_27 -> V_189 ) ;
}
static void F_127 ( struct V_26 * V_27 ,
struct V_123 * V_62 ,
struct V_148 * V_149 ,
int V_90 ,
unsigned long V_187 )
{
if ( V_90 )
F_123 ( V_27 , V_149 , V_187 ) ;
else if ( F_31 ( & V_149 -> V_52 ) )
return;
F_126 ( V_27 , V_62 ) ;
}
static int F_128 ( struct V_26 * V_27 ,
struct V_123 * V_62 ,
struct V_28 * V_29 )
{
const struct V_75 * V_76 = F_18 ( V_29 ) ;
struct V_71 * V_72 = F_59 ( V_29 ) ;
struct V_20 * V_23 ;
struct V_193 * V_194 ;
struct V_47 * V_48 ;
struct V_47 T_4 * * V_58 ;
unsigned long V_187 ;
unsigned long V_192 = V_61 ;
T_1 V_70 ;
int V_66 = 0 ;
T_3 V_5 = 0 ;
F_29 ( & V_27 -> V_50 ) ;
if ( ! F_30 ( V_27 -> V_51 ) ||
( V_62 && V_62 -> V_63 == V_134 ) )
goto V_53;
V_70 = V_72 -> V_70 ;
if ( V_29 -> V_42 == sizeof( * V_72 ) ) {
V_187 = V_72 -> V_97 * ( V_100 / V_101 ) ;
if ( ! V_187 ) {
V_187 = 10 * V_100 ;
V_70 = 0 ;
}
} else {
if ( ! F_116 ( V_29 , sizeof( struct V_193 ) ) ) {
V_66 = - V_46 ;
goto V_53;
}
V_194 = F_129 ( V_29 ) ;
if ( V_194 -> V_179 )
goto V_53;
V_187 = V_194 -> V_97 ?
F_130 ( V_194 -> V_97 ) * ( V_100 / V_101 ) : 1 ;
}
F_127 ( V_27 , V_62 , & V_27 -> V_151 , ! ! V_76 -> V_90 ,
V_187 ) ;
if ( ! V_70 )
goto V_53;
F_117 ( V_29 , & V_5 ) ;
V_23 = F_13 ( F_32 ( V_27 -> V_13 , V_27 ) , V_70 , V_5 ) ;
if ( ! V_23 )
goto V_53;
F_41 ( & V_23 -> V_52 , V_192 + V_27 -> V_195 ) ;
V_23 -> V_60 = true ;
V_187 *= V_27 -> V_196 ;
if ( V_23 -> V_54 &&
( F_31 ( & V_23 -> V_52 ) ?
F_131 ( V_23 -> V_52 . V_197 , V_192 + V_187 ) :
F_111 ( & V_23 -> V_52 ) >= 0 ) )
F_41 ( & V_23 -> V_52 , V_192 + V_187 ) ;
for ( V_58 = & V_23 -> V_55 ;
( V_48 = F_32 ( * V_58 , V_27 ) ) != NULL ;
V_58 = & V_48 -> V_59 ) {
if ( F_31 ( & V_48 -> V_52 ) ?
F_131 ( V_48 -> V_52 . V_197 , V_192 + V_187 ) :
F_111 ( & V_48 -> V_52 ) >= 0 )
F_41 ( & V_48 -> V_52 , V_192 + V_187 ) ;
}
V_53:
F_35 ( & V_27 -> V_50 ) ;
return V_66 ;
}
static int F_132 ( struct V_26 * V_27 ,
struct V_123 * V_62 ,
struct V_28 * V_29 )
{
const struct V_103 * V_104 = F_19 ( V_29 ) ;
struct V_105 * V_198 ;
struct V_20 * V_23 ;
struct V_199 * V_200 ;
struct V_47 * V_48 ;
struct V_47 T_4 * * V_58 ;
unsigned long V_187 ;
unsigned long V_192 = V_61 ;
const struct V_19 * V_70 = NULL ;
int V_66 = 0 ;
T_3 V_5 = 0 ;
F_29 ( & V_27 -> V_50 ) ;
if ( ! F_30 ( V_27 -> V_51 ) ||
( V_62 && V_62 -> V_63 == V_134 ) )
goto V_53;
if ( V_29 -> V_42 == sizeof( * V_198 ) ) {
if ( ! F_116 ( V_29 , sizeof( * V_198 ) ) ) {
V_66 = - V_46 ;
goto V_53;
}
V_198 = (struct V_105 * ) F_68 ( V_29 ) ;
V_187 = F_133 ( F_119 ( V_198 -> V_120 ) ) ;
if ( V_187 )
V_70 = & V_198 -> V_122 ;
} else {
if ( ! F_116 ( V_29 , sizeof( * V_200 ) ) ) {
V_66 = - V_46 ;
goto V_53;
}
V_200 = (struct V_199 * ) F_68 ( V_29 ) ;
if ( ! V_200 -> V_201 )
V_70 = & V_200 -> V_202 ;
V_187 = V_18 ( F_133 ( F_134 ( F_119 ( V_200 -> V_203 ) ) ) , 1UL ) ;
}
F_127 ( V_27 , V_62 , & V_27 -> V_152 ,
! F_69 ( & V_104 -> V_90 ) , V_187 ) ;
if ( ! V_70 )
goto V_53;
F_117 ( V_29 , & V_5 ) ;
V_23 = F_14 ( F_32 ( V_27 -> V_13 , V_27 ) , V_70 , V_5 ) ;
if ( ! V_23 )
goto V_53;
F_41 ( & V_23 -> V_52 , V_192 + V_27 -> V_195 ) ;
V_23 -> V_60 = true ;
V_187 *= V_27 -> V_196 ;
if ( V_23 -> V_54 &&
( F_31 ( & V_23 -> V_52 ) ?
F_131 ( V_23 -> V_52 . V_197 , V_192 + V_187 ) :
F_111 ( & V_23 -> V_52 ) >= 0 ) )
F_41 ( & V_23 -> V_52 , V_192 + V_187 ) ;
for ( V_58 = & V_23 -> V_55 ;
( V_48 = F_32 ( * V_58 , V_27 ) ) != NULL ;
V_58 = & V_48 -> V_59 ) {
if ( F_31 ( & V_48 -> V_52 ) ?
F_131 ( V_48 -> V_52 . V_197 , V_192 + V_187 ) :
F_111 ( & V_48 -> V_52 ) >= 0 )
F_41 ( & V_48 -> V_52 , V_192 + V_187 ) ;
}
V_53:
F_35 ( & V_27 -> V_50 ) ;
return V_66 ;
}
static void F_135 ( struct V_26 * V_27 ,
struct V_123 * V_62 ,
struct V_1 * V_70 ,
struct V_148 * V_149 ,
struct V_141 * V_142 )
{
struct V_12 * V_13 ;
struct V_20 * V_23 ;
struct V_47 * V_48 ;
unsigned long V_192 ;
unsigned long time ;
F_29 ( & V_27 -> V_50 ) ;
if ( ! F_30 ( V_27 -> V_51 ) ||
( V_62 && V_62 -> V_63 == V_134 ) ||
F_31 ( & V_149 -> V_52 ) )
goto V_53;
V_13 = F_32 ( V_27 -> V_13 , V_27 ) ;
V_23 = F_12 ( V_13 , V_70 ) ;
if ( ! V_23 )
goto V_53;
if ( V_27 -> V_150 ) {
F_99 ( V_27 , V_62 , & V_23 -> V_24 ) ;
time = V_61 + V_27 -> V_196 *
V_27 -> V_98 ;
F_41 ( & V_142 -> V_52 , time ) ;
for ( V_48 = F_32 ( V_23 -> V_55 , V_27 ) ;
V_48 != NULL ;
V_48 = F_32 ( V_48 -> V_59 , V_27 ) ) {
if ( V_48 -> V_62 != V_62 )
continue;
if ( ! F_43 ( & V_48 -> V_54 ) &&
( F_31 ( & V_48 -> V_52 ) ?
F_131 ( V_48 -> V_52 . V_197 , time ) :
F_111 ( & V_48 -> V_52 ) >= 0 ) ) {
F_41 ( & V_48 -> V_52 , time ) ;
}
break;
}
}
if ( V_62 && ( V_62 -> V_204 & V_205 ) ) {
struct V_47 T_4 * * V_58 ;
for ( V_58 = & V_23 -> V_55 ;
( V_48 = F_32 ( * V_58 , V_27 ) ) != NULL ;
V_58 = & V_48 -> V_59 ) {
if ( V_48 -> V_62 != V_62 )
continue;
F_38 ( * V_58 , V_48 -> V_59 ) ;
F_39 ( & V_48 -> V_54 ) ;
F_40 ( & V_48 -> V_52 ) ;
F_34 ( & V_48 -> V_36 , F_26 ) ;
F_87 ( V_27 -> V_51 , V_62 , V_70 , V_206 ) ;
if ( ! V_23 -> V_55 && ! V_23 -> V_54 && V_23 -> V_60 &&
F_30 ( V_27 -> V_51 ) )
F_41 ( & V_23 -> V_52 , V_61 ) ;
}
goto V_53;
}
V_192 = V_61 ;
time = V_192 + V_27 -> V_196 *
V_27 -> V_98 ;
if ( ! V_62 ) {
if ( V_23 -> V_54 && V_23 -> V_60 &&
( F_31 ( & V_23 -> V_52 ) ?
F_131 ( V_23 -> V_52 . V_197 , time ) :
F_111 ( & V_23 -> V_52 ) >= 0 ) ) {
F_41 ( & V_23 -> V_52 , time ) ;
}
}
V_53:
F_35 ( & V_27 -> V_50 ) ;
}
static void F_136 ( struct V_26 * V_27 ,
struct V_123 * V_62 ,
T_1 V_70 ,
T_2 V_5 )
{
struct V_1 V_137 ;
struct V_141 * V_142 = V_62 ? & V_62 -> V_143 :
& V_27 -> V_143 ;
if ( F_89 ( V_70 ) )
return;
V_137 . V_7 . V_8 = V_70 ;
V_137 . V_4 = F_2 ( V_6 ) ;
V_137 . V_5 = V_5 ;
F_135 ( V_27 , V_62 , & V_137 , & V_27 -> V_151 , V_142 ) ;
}
static void F_137 ( struct V_26 * V_27 ,
struct V_123 * V_62 ,
const struct V_19 * V_70 ,
T_2 V_5 )
{
struct V_1 V_137 ;
struct V_141 * V_142 = V_62 ? & V_62 -> V_144 :
& V_27 -> V_144 ;
if ( ! F_91 ( V_70 ) )
return;
V_137 . V_7 . V_11 = * V_70 ;
V_137 . V_4 = F_2 ( V_10 ) ;
V_137 . V_5 = V_5 ;
F_135 ( V_27 , V_62 , & V_137 , & V_27 -> V_152 , V_142 ) ;
}
static int F_138 ( struct V_26 * V_27 ,
struct V_123 * V_62 ,
struct V_28 * V_29 )
{
struct V_28 * V_207 = V_29 ;
const struct V_75 * V_76 ;
struct V_71 * V_72 ;
unsigned int V_42 ;
unsigned int V_208 ;
int V_66 ;
T_3 V_5 = 0 ;
if ( ! F_116 ( V_29 , sizeof( * V_76 ) ) )
return - V_46 ;
V_76 = F_18 ( V_29 ) ;
if ( V_76 -> V_82 < 5 || V_76 -> V_81 != 4 )
return - V_46 ;
if ( ! F_116 ( V_29 , F_139 ( V_29 ) ) )
return - V_46 ;
V_76 = F_18 ( V_29 ) ;
if ( F_75 ( F_140 ( ( V_94 * ) V_76 , V_76 -> V_82 ) ) )
return - V_46 ;
if ( V_76 -> V_32 != V_89 ) {
if ( ! F_89 ( V_76 -> V_33 ) )
F_17 ( V_29 ) -> V_209 = 1 ;
return 0 ;
}
V_42 = F_119 ( V_76 -> V_84 ) ;
if ( V_29 -> V_42 < V_42 || V_42 < F_139 ( V_29 ) )
return - V_46 ;
if ( V_29 -> V_42 > V_42 ) {
V_207 = F_141 ( V_29 , V_67 ) ;
if ( ! V_207 )
return - V_68 ;
V_66 = F_142 ( V_207 , V_42 ) ;
if ( V_66 )
goto V_210;
}
V_42 -= F_139 ( V_207 ) ;
V_208 = F_143 ( V_207 ) + F_139 ( V_207 ) ;
F_61 ( V_207 , V_208 ) ;
F_144 ( V_207 ) ;
V_66 = - V_46 ;
if ( ! F_116 ( V_207 , sizeof( * V_72 ) ) )
goto V_53;
switch ( V_207 -> V_211 ) {
case V_212 :
if ( ! F_145 ( V_207 -> V_102 ) )
break;
case V_213 :
V_207 -> V_102 = 0 ;
if ( F_146 ( V_207 ) )
goto V_53;
}
V_66 = 0 ;
F_117 ( V_207 , & V_5 ) ;
F_17 ( V_29 ) -> V_31 = 1 ;
V_72 = F_59 ( V_207 ) ;
switch ( V_72 -> type ) {
case V_214 :
case V_215 :
F_17 ( V_29 ) -> V_209 = 1 ;
V_66 = F_88 ( V_27 , V_62 , V_72 -> V_70 , V_5 ) ;
break;
case V_216 :
V_66 = F_115 ( V_27 , V_62 , V_207 ) ;
break;
case V_96 :
V_66 = F_128 ( V_27 , V_62 , V_207 ) ;
break;
case V_217 :
F_136 ( V_27 , V_62 , V_72 -> V_70 , V_5 ) ;
break;
}
V_53:
F_100 ( V_207 , V_208 ) ;
V_210:
if ( V_207 != V_29 )
F_66 ( V_207 ) ;
return V_66 ;
}
static int F_147 ( struct V_26 * V_27 ,
struct V_123 * V_62 ,
struct V_28 * V_29 )
{
struct V_28 * V_207 ;
const struct V_103 * V_104 ;
V_94 V_218 ;
V_94 V_110 ;
T_5 V_86 ;
unsigned int V_42 ;
int V_208 ;
int V_66 ;
T_3 V_5 = 0 ;
if ( ! F_116 ( V_29 , sizeof( * V_104 ) ) )
return - V_46 ;
V_104 = F_19 ( V_29 ) ;
if ( V_104 -> V_81 != 6 ||
V_104 -> V_110 != V_111 ||
V_104 -> V_109 == 0 )
return 0 ;
V_42 = F_119 ( V_104 -> V_109 ) + sizeof( * V_104 ) ;
if ( V_29 -> V_42 < V_42 )
return - V_46 ;
V_110 = V_104 -> V_110 ;
V_208 = F_148 ( V_29 , sizeof( * V_104 ) , & V_110 , & V_86 ) ;
if ( V_208 < 0 || V_110 != V_113 )
return 0 ;
V_207 = F_141 ( V_29 , V_67 ) ;
if ( ! V_207 )
return - V_68 ;
V_66 = - V_46 ;
if ( ! F_116 ( V_207 , V_208 + sizeof( struct V_174 ) ) )
goto V_53;
V_42 -= V_208 - F_143 ( V_207 ) ;
F_61 ( V_207 , V_208 ) ;
F_144 ( V_207 ) ;
F_149 ( V_207 , F_150 ( V_207 ) ,
F_151 ( V_207 ) ) ;
V_218 = F_68 ( V_207 ) -> V_218 ;
switch ( V_218 ) {
case V_117 :
case V_219 :
case V_220 :
case V_221 :
break;
default:
V_66 = 0 ;
goto V_53;
}
if ( V_207 -> V_42 > V_42 ) {
V_66 = F_142 ( V_207 , V_42 ) ;
if ( V_66 )
goto V_53;
V_66 = - V_46 ;
}
V_104 = F_19 ( V_207 ) ;
switch ( V_207 -> V_211 ) {
case V_212 :
if ( ! F_71 ( & V_104 -> V_90 , & V_104 -> V_33 , V_207 -> V_42 ,
V_113 , V_207 -> V_102 ) )
break;
case V_213 :
V_207 -> V_102 = ~ F_152 ( F_71 ( & V_104 -> V_90 ,
& V_104 -> V_33 ,
V_207 -> V_42 ,
V_113 , 0 ) ) ;
if ( F_153 ( V_207 ) )
goto V_53;
}
V_66 = 0 ;
F_117 ( V_29 , & V_5 ) ;
F_17 ( V_29 ) -> V_31 = 1 ;
switch ( V_218 ) {
case V_219 :
{
struct V_105 * V_198 ;
if ( ! F_116 ( V_207 , sizeof( * V_198 ) ) ) {
V_66 = - V_46 ;
goto V_53;
}
V_198 = (struct V_105 * ) F_154 ( V_207 ) ;
F_17 ( V_29 ) -> V_209 = 1 ;
V_66 = F_90 ( V_27 , V_62 , & V_198 -> V_122 , V_5 ) ;
break;
}
case V_221 :
V_66 = F_120 ( V_27 , V_62 , V_207 ) ;
break;
case V_117 :
V_66 = F_132 ( V_27 , V_62 , V_207 ) ;
break;
case V_220 :
{
struct V_105 * V_198 ;
if ( ! F_116 ( V_207 , sizeof( * V_198 ) ) ) {
V_66 = - V_46 ;
goto V_53;
}
V_198 = (struct V_105 * ) F_154 ( V_207 ) ;
F_137 ( V_27 , V_62 , & V_198 -> V_122 , V_5 ) ;
}
}
V_53:
F_66 ( V_207 ) ;
return V_66 ;
}
int F_155 ( struct V_26 * V_27 , struct V_123 * V_62 ,
struct V_28 * V_29 )
{
F_17 ( V_29 ) -> V_31 = 0 ;
F_17 ( V_29 ) -> V_209 = 0 ;
if ( V_27 -> V_30 )
return 0 ;
switch ( V_29 -> V_32 ) {
case F_2 ( V_6 ) :
return F_138 ( V_27 , V_62 , V_29 ) ;
#if F_3 ( V_9 )
case F_2 ( V_10 ) :
return F_147 ( V_27 , V_62 , V_29 ) ;
#endif
}
return 0 ;
}
static void F_156 ( struct V_26 * V_27 ,
struct V_141 * V_142 )
{
F_29 ( & V_27 -> V_50 ) ;
if ( V_142 -> V_153 < V_27 -> V_154 )
V_142 -> V_153 ++ ;
F_103 ( V_27 , NULL , V_142 ) ;
F_35 ( & V_27 -> V_50 ) ;
}
static void F_157 ( unsigned long V_49 )
{
struct V_26 * V_27 = ( void * ) V_49 ;
F_156 ( V_27 , & V_27 -> V_143 ) ;
}
static void F_158 ( unsigned long V_49 )
{
struct V_26 * V_27 = ( void * ) V_49 ;
F_156 ( V_27 , & V_27 -> V_144 ) ;
}
void F_159 ( struct V_26 * V_27 )
{
V_27 -> V_125 = 4 ;
V_27 -> V_127 = 512 ;
V_27 -> V_138 = 1 ;
V_27 -> V_150 = 0 ;
V_27 -> V_91 = 0 ;
V_27 -> V_196 = 2 ;
V_27 -> V_154 = 2 ;
V_27 -> V_98 = V_100 ;
V_27 -> V_99 = 10 * V_100 ;
V_27 -> V_155 = 125 * V_100 / 4 ;
V_27 -> V_156 = 125 * V_100 ;
V_27 -> V_189 = 255 * V_100 ;
V_27 -> V_195 = 260 * V_100 ;
V_27 -> V_151 . V_188 = 0 ;
#if F_3 ( V_9 )
V_27 -> V_152 . V_188 = 0 ;
#endif
F_160 ( & V_27 -> V_50 ) ;
F_82 ( & V_27 -> V_139 ,
F_94 , 0 ) ;
F_82 ( & V_27 -> V_151 . V_52 , F_97 ,
( unsigned long ) V_27 ) ;
F_82 ( & V_27 -> V_143 . V_52 , F_157 ,
( unsigned long ) V_27 ) ;
#if F_3 ( V_9 )
F_82 ( & V_27 -> V_152 . V_52 , F_98 ,
( unsigned long ) V_27 ) ;
F_82 ( & V_27 -> V_144 . V_52 , F_158 ,
( unsigned long ) V_27 ) ;
#endif
}
static void F_161 ( struct V_26 * V_27 ,
struct V_141 * V_142 )
{
V_142 -> V_153 = 0 ;
if ( V_27 -> V_30 )
return;
F_41 ( & V_142 -> V_52 , V_61 ) ;
}
void F_162 ( struct V_26 * V_27 )
{
F_161 ( V_27 , & V_27 -> V_143 ) ;
#if F_3 ( V_9 )
F_161 ( V_27 , & V_27 -> V_144 ) ;
#endif
}
void F_163 ( struct V_26 * V_27 )
{
struct V_12 * V_13 ;
struct V_20 * V_23 ;
struct V_158 * V_159 ;
V_16 V_45 ;
int V_43 ;
F_109 ( & V_27 -> V_139 ) ;
F_109 ( & V_27 -> V_151 . V_52 ) ;
F_109 ( & V_27 -> V_143 . V_52 ) ;
#if F_3 ( V_9 )
F_109 ( & V_27 -> V_152 . V_52 ) ;
F_109 ( & V_27 -> V_144 . V_52 ) ;
#endif
F_164 ( & V_27 -> V_50 ) ;
V_13 = F_32 ( V_27 -> V_13 , V_27 ) ;
if ( ! V_13 )
goto V_53;
V_27 -> V_13 = NULL ;
V_45 = V_13 -> V_45 ;
for ( V_43 = 0 ; V_43 < V_13 -> V_18 ; V_43 ++ ) {
F_114 (mp, n, &mdb->mhash[i],
hlist[ver]) {
F_40 ( & V_23 -> V_52 ) ;
V_23 -> V_60 = false ;
F_34 ( & V_23 -> V_36 , F_27 ) ;
}
}
if ( V_13 -> V_37 ) {
F_165 ( & V_27 -> V_50 ) ;
F_166 () ;
F_164 ( & V_27 -> V_50 ) ;
F_37 ( V_13 -> V_37 ) ;
}
V_13 -> V_37 = V_13 ;
F_34 ( & V_13 -> V_36 , F_20 ) ;
V_53:
F_165 ( & V_27 -> V_50 ) ;
}
int F_167 ( struct V_26 * V_27 , unsigned long V_222 )
{
int V_66 = - V_223 ;
F_164 ( & V_27 -> V_50 ) ;
if ( ! F_30 ( V_27 -> V_51 ) )
goto V_224;
switch ( V_222 ) {
case 0 :
case 2 :
F_40 ( & V_27 -> V_139 ) ;
case 1 :
V_27 -> V_138 = V_222 ;
V_66 = 0 ;
break;
default:
V_66 = - V_46 ;
break;
}
V_224:
F_165 ( & V_27 -> V_50 ) ;
return V_66 ;
}
int F_168 ( struct V_123 * V_48 , unsigned long V_222 )
{
struct V_26 * V_27 = V_48 -> V_27 ;
int V_66 = - V_223 ;
F_29 ( & V_27 -> V_50 ) ;
if ( ! F_30 ( V_27 -> V_51 ) || V_48 -> V_63 == V_134 )
goto V_224;
switch ( V_222 ) {
case 0 :
case 1 :
case 2 :
V_48 -> V_138 = V_222 ;
V_66 = 0 ;
if ( V_222 < 2 && ! F_43 ( & V_48 -> V_140 ) )
F_93 ( & V_48 -> V_140 ) ;
if ( V_222 == 1 )
break;
F_40 ( & V_48 -> V_139 ) ;
if ( V_222 == 0 )
break;
F_124 ( V_27 , V_48 ) ;
break;
default:
V_66 = - V_46 ;
break;
}
V_224:
F_35 ( & V_27 -> V_50 ) ;
return V_66 ;
}
static void F_96 ( struct V_26 * V_27 ,
struct V_141 * V_142 )
{
struct V_123 * V_62 ;
F_161 ( V_27 , V_142 ) ;
F_169 (port, &br->port_list, list) {
if ( V_62 -> V_63 == V_134 ||
V_62 -> V_63 == V_157 )
continue;
if ( V_142 == & V_27 -> V_143 )
F_110 ( & V_62 -> V_143 ) ;
#if F_3 ( V_9 )
else
F_110 ( & V_62 -> V_144 ) ;
#endif
}
}
int F_170 ( struct V_26 * V_27 , unsigned long V_222 )
{
int V_66 = 0 ;
struct V_12 * V_13 ;
F_164 ( & V_27 -> V_50 ) ;
if ( V_27 -> V_30 == ! V_222 )
goto V_224;
V_27 -> V_30 = ! V_222 ;
if ( V_27 -> V_30 )
goto V_224;
if ( ! F_30 ( V_27 -> V_51 ) )
goto V_224;
V_13 = F_32 ( V_27 -> V_13 , V_27 ) ;
if ( V_13 ) {
if ( V_13 -> V_37 ) {
V_66 = - V_130 ;
V_225:
V_27 -> V_30 = ! ! V_222 ;
goto V_224;
}
V_66 = F_44 ( & V_27 -> V_13 , V_13 -> V_18 ,
V_27 -> V_125 ) ;
if ( V_66 )
goto V_225;
}
F_96 ( V_27 , & V_27 -> V_143 ) ;
#if F_3 ( V_9 )
F_96 ( V_27 , & V_27 -> V_144 ) ;
#endif
V_224:
F_165 ( & V_27 -> V_50 ) ;
return V_66 ;
}
int F_171 ( struct V_26 * V_27 , unsigned long V_222 )
{
unsigned long V_187 ;
V_222 = ! ! V_222 ;
F_164 ( & V_27 -> V_50 ) ;
if ( V_27 -> V_150 == V_222 )
goto V_224;
V_27 -> V_150 = V_222 ;
if ( ! V_222 )
goto V_224;
V_187 = V_27 -> V_99 ;
if ( ! F_31 ( & V_27 -> V_151 . V_52 ) )
V_27 -> V_151 . V_188 = V_61 + V_187 ;
F_96 ( V_27 , & V_27 -> V_143 ) ;
#if F_3 ( V_9 )
if ( ! F_31 ( & V_27 -> V_152 . V_52 ) )
V_27 -> V_152 . V_188 = V_61 + V_187 ;
F_96 ( V_27 , & V_27 -> V_144 ) ;
#endif
V_224:
F_165 ( & V_27 -> V_50 ) ;
return 0 ;
}
int F_172 ( struct V_26 * V_27 , unsigned long V_222 )
{
int V_66 = - V_223 ;
V_16 V_37 ;
struct V_12 * V_13 ;
F_29 ( & V_27 -> V_50 ) ;
if ( ! F_30 ( V_27 -> V_51 ) )
goto V_224;
V_66 = - V_46 ;
if ( ! F_173 ( V_222 ) )
goto V_224;
V_13 = F_32 ( V_27 -> V_13 , V_27 ) ;
if ( V_13 && V_222 < V_13 -> V_56 )
goto V_224;
V_66 = 0 ;
V_37 = V_27 -> V_127 ;
V_27 -> V_127 = V_222 ;
if ( V_13 ) {
if ( V_13 -> V_37 ) {
V_66 = - V_130 ;
V_225:
V_27 -> V_127 = V_37 ;
goto V_224;
}
V_66 = F_44 ( & V_27 -> V_13 , V_27 -> V_127 ,
V_27 -> V_125 ) ;
if ( V_66 )
goto V_225;
}
V_224:
F_35 ( & V_27 -> V_50 ) ;
return V_66 ;
}
