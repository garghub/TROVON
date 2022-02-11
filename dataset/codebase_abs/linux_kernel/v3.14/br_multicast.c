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
if ( ! V_23 -> V_55 && ! V_23 -> V_54 &&
F_30 ( V_27 -> V_51 ) )
F_41 ( & V_23 -> V_52 , V_60 ) ;
return;
}
F_37 ( 1 ) ;
}
static void F_42 ( unsigned long V_49 )
{
struct V_47 * V_57 = ( void * ) V_49 ;
struct V_26 * V_27 = V_57 -> V_61 -> V_27 ;
F_29 ( & V_27 -> V_50 ) ;
if ( ! F_30 ( V_27 -> V_51 ) || F_31 ( & V_57 -> V_52 ) ||
F_43 ( & V_57 -> V_54 ) || V_57 -> V_62 & V_63 )
goto V_53;
F_36 ( V_27 , V_57 ) ;
V_53:
F_35 ( & V_27 -> V_50 ) ;
}
static int F_44 ( struct V_12 T_4 * * V_64 , int V_18 ,
int V_40 )
{
struct V_12 * V_37 = F_45 ( * V_64 , 1 ) ;
struct V_12 * V_13 ;
int V_65 ;
V_13 = F_46 ( sizeof( * V_13 ) , V_66 ) ;
if ( ! V_13 )
return - V_67 ;
V_13 -> V_18 = V_18 ;
V_13 -> V_37 = V_37 ;
V_13 -> V_38 = F_47 ( V_18 * sizeof( * V_13 -> V_38 ) , V_66 ) ;
if ( ! V_13 -> V_38 ) {
F_22 ( V_13 ) ;
return - V_67 ;
}
V_13 -> V_56 = V_37 ? V_37 -> V_56 : 0 ;
V_13 -> V_45 = V_37 ? V_37 -> V_45 ^ 1 : 0 ;
if ( ! V_37 || V_40 )
F_48 ( & V_13 -> V_17 , sizeof( V_13 -> V_17 ) ) ;
else
V_13 -> V_17 = V_37 -> V_17 ;
if ( ! V_37 )
goto V_53;
V_65 = F_23 ( V_13 , V_37 , V_40 ) ;
if ( V_65 ) {
F_22 ( V_13 -> V_38 ) ;
F_22 ( V_13 ) ;
return V_65 ;
}
V_68 ++ ;
F_34 ( & V_13 -> V_36 , F_20 ) ;
V_53:
F_38 ( * V_64 , V_13 ) ;
return 0 ;
}
static struct V_28 * F_49 ( struct V_26 * V_27 ,
T_1 V_69 )
{
struct V_28 * V_29 ;
struct V_70 * V_71 ;
struct V_72 * V_73 ;
struct V_74 * V_75 ;
V_29 = F_50 ( V_27 -> V_51 , sizeof( * V_73 ) + sizeof( * V_75 ) +
sizeof( * V_71 ) + 4 ) ;
if ( ! V_29 )
goto V_53;
V_29 -> V_32 = F_2 ( V_6 ) ;
F_51 ( V_29 ) ;
V_73 = F_52 ( V_29 ) ;
memcpy ( V_73 -> V_76 , V_27 -> V_51 -> V_77 , V_78 ) ;
V_73 -> V_79 [ 0 ] = 1 ;
V_73 -> V_79 [ 1 ] = 0 ;
V_73 -> V_79 [ 2 ] = 0x5e ;
V_73 -> V_79 [ 3 ] = 0 ;
V_73 -> V_79 [ 4 ] = 0 ;
V_73 -> V_79 [ 5 ] = 1 ;
V_73 -> V_80 = F_2 ( V_6 ) ;
F_53 ( V_29 , sizeof( * V_73 ) ) ;
F_54 ( V_29 , V_29 -> V_42 ) ;
V_75 = F_18 ( V_29 ) ;
V_75 -> V_81 = 4 ;
V_75 -> V_82 = 6 ;
V_75 -> V_83 = 0xc0 ;
V_75 -> V_84 = F_2 ( sizeof( * V_75 ) + sizeof( * V_71 ) + 4 ) ;
V_75 -> V_85 = 0 ;
V_75 -> V_86 = F_2 ( V_87 ) ;
V_75 -> V_88 = 1 ;
V_75 -> V_32 = V_89 ;
V_75 -> V_90 = V_27 -> V_91 ?
F_55 ( V_27 -> V_51 , 0 , V_92 ) : 0 ;
V_75 -> V_33 = F_56 ( V_93 ) ;
( ( V_94 * ) & V_75 [ 1 ] ) [ 0 ] = V_95 ;
( ( V_94 * ) & V_75 [ 1 ] ) [ 1 ] = 4 ;
( ( V_94 * ) & V_75 [ 1 ] ) [ 2 ] = 0 ;
( ( V_94 * ) & V_75 [ 1 ] ) [ 3 ] = 0 ;
F_57 ( V_75 ) ;
F_53 ( V_29 , 24 ) ;
F_58 ( V_29 , V_29 -> V_42 ) ;
V_71 = F_59 ( V_29 ) ;
V_71 -> type = V_96 ;
V_71 -> V_97 = ( V_69 ? V_27 -> V_98 :
V_27 -> V_99 ) /
( V_100 / V_101 ) ;
V_71 -> V_69 = V_69 ;
V_71 -> V_102 = 0 ;
V_71 -> V_102 = F_60 ( ( void * ) V_71 , sizeof( struct V_70 ) ) ;
F_53 ( V_29 , sizeof( * V_71 ) ) ;
F_61 ( V_29 , sizeof( * V_73 ) ) ;
V_53:
return V_29 ;
}
static struct V_28 * F_62 ( struct V_26 * V_27 ,
const struct V_19 * V_69 )
{
struct V_28 * V_29 ;
struct V_103 * V_104 ;
struct V_105 * V_106 ;
struct V_72 * V_73 ;
V_94 * V_107 ;
unsigned long V_108 ;
V_29 = F_50 ( V_27 -> V_51 , sizeof( * V_73 ) + sizeof( * V_104 ) +
8 + sizeof( * V_106 ) ) ;
if ( ! V_29 )
goto V_53;
V_29 -> V_32 = F_2 ( V_10 ) ;
F_51 ( V_29 ) ;
V_73 = F_52 ( V_29 ) ;
memcpy ( V_73 -> V_76 , V_27 -> V_51 -> V_77 , V_78 ) ;
V_73 -> V_80 = F_2 ( V_10 ) ;
F_53 ( V_29 , sizeof( * V_73 ) ) ;
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
F_67 ( & V_104 -> V_33 , V_73 -> V_79 ) ;
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
V_108 = F_69 ( V_69 ) ?
V_27 -> V_99 :
V_27 -> V_98 ;
V_106 -> V_116 = V_117 ;
V_106 -> V_118 = 0 ;
V_106 -> V_119 = 0 ;
V_106 -> V_120 = F_2 ( ( T_3 ) F_70 ( V_108 ) ) ;
V_106 -> V_121 = 0 ;
V_106 -> V_122 = * V_69 ;
V_106 -> V_119 = F_71 ( & V_104 -> V_90 , & V_104 -> V_33 ,
sizeof( * V_106 ) , V_113 ,
F_72 ( V_106 ,
sizeof( * V_106 ) , 0 ) ) ;
F_53 ( V_29 , sizeof( * V_106 ) ) ;
F_61 ( V_29 , sizeof( * V_73 ) ) ;
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
struct V_26 * V_27 , struct V_123 * V_61 ,
struct V_1 * V_69 , int V_22 )
{
struct V_12 * V_13 ;
struct V_20 * V_23 ;
unsigned int V_124 = 0 ;
unsigned int V_18 ;
int V_40 ;
int V_65 ;
V_13 = F_45 ( V_27 -> V_13 , 1 ) ;
F_24 (mp, &mdb->mhash[hash], hlist[mdb->ver]) {
V_124 ++ ;
if ( F_75 ( F_1 ( V_69 , & V_23 -> V_24 ) ) )
return V_23 ;
}
V_40 = 0 ;
V_18 = V_13 -> V_18 ;
if ( F_75 ( V_124 > V_27 -> V_125 && V_124 ) ) {
if ( F_76 () )
F_77 ( V_27 , L_1
L_2 ,
V_61 ? V_61 -> V_51 -> V_126 : V_27 -> V_51 -> V_126 ) ;
V_40 = V_27 -> V_125 ;
}
if ( V_13 -> V_56 >= V_18 ) {
V_18 *= 2 ;
if ( F_75 ( V_18 > V_27 -> V_127 ) ) {
F_78 ( V_27 , L_3
L_4 ,
V_27 -> V_127 ,
V_61 ? V_61 -> V_51 -> V_126 : V_27 -> V_51 -> V_126 ) ;
V_65 = - V_128 ;
V_129:
V_27 -> V_30 = 1 ;
goto V_65;
}
}
if ( V_18 > V_13 -> V_18 || V_40 ) {
if ( V_13 -> V_37 ) {
if ( F_76 () )
F_77 ( V_27 , L_1
L_5 ,
V_61 ? V_61 -> V_51 -> V_126 : V_27 -> V_51 -> V_126 ) ;
V_65 = - V_130 ;
goto V_65;
}
V_65 = F_44 ( & V_27 -> V_13 , V_18 , V_40 ) ;
if ( V_65 ) {
F_78 ( V_27 , L_6
L_7 ,
V_61 ? V_61 -> V_51 -> V_126 : V_27 -> V_51 -> V_126 ,
V_13 -> V_56 , V_65 ) ;
goto V_129;
}
V_65 = - V_131 ;
goto V_65;
}
return NULL ;
V_65:
V_23 = F_79 ( V_65 ) ;
return V_23 ;
}
struct V_20 * F_80 ( struct V_26 * V_27 ,
struct V_123 * V_61 , struct V_1 * V_69 )
{
struct V_12 * V_13 ;
struct V_20 * V_23 ;
int V_22 ;
int V_65 ;
V_13 = F_45 ( V_27 -> V_13 , 1 ) ;
if ( ! V_13 ) {
V_65 = F_44 ( & V_27 -> V_13 , V_132 , 0 ) ;
if ( V_65 )
return F_79 ( V_65 ) ;
goto V_133;
}
V_22 = F_9 ( V_13 , V_69 ) ;
V_23 = F_74 ( V_27 , V_61 , V_69 , V_22 ) ;
switch ( F_81 ( V_23 ) ) {
case 0 :
break;
case - V_131 :
V_133:
V_13 = F_45 ( V_27 -> V_13 , 1 ) ;
V_22 = F_9 ( V_13 , V_69 ) ;
break;
default:
goto V_53;
}
V_23 = F_47 ( sizeof( * V_23 ) , V_66 ) ;
if ( F_75 ( ! V_23 ) )
return F_79 ( - V_67 ) ;
V_23 -> V_27 = V_27 ;
V_23 -> V_24 = * V_69 ;
F_82 ( & V_23 -> V_52 , F_28 ,
( unsigned long ) V_23 ) ;
F_83 ( & V_23 -> V_44 [ V_13 -> V_45 ] , & V_13 -> V_38 [ V_22 ] ) ;
V_13 -> V_56 ++ ;
V_53:
return V_23 ;
}
struct V_47 * F_84 (
struct V_123 * V_61 ,
struct V_1 * V_69 ,
struct V_47 T_4 * V_59 ,
unsigned char V_62 )
{
struct V_47 * V_48 ;
V_48 = F_47 ( sizeof( * V_48 ) , V_66 ) ;
if ( F_75 ( ! V_48 ) )
return NULL ;
V_48 -> V_24 = * V_69 ;
V_48 -> V_61 = V_61 ;
V_48 -> V_62 = V_62 ;
F_38 ( V_48 -> V_59 , V_59 ) ;
F_25 ( & V_48 -> V_54 , & V_61 -> V_54 ) ;
F_82 ( & V_48 -> V_52 , F_42 ,
( unsigned long ) V_48 ) ;
return V_48 ;
}
static int F_85 ( struct V_26 * V_27 ,
struct V_123 * V_61 ,
struct V_1 * V_69 )
{
struct V_20 * V_23 ;
struct V_47 * V_48 ;
struct V_47 T_4 * * V_58 ;
unsigned long V_134 = V_60 ;
int V_65 ;
F_29 ( & V_27 -> V_50 ) ;
if ( ! F_30 ( V_27 -> V_51 ) ||
( V_61 && V_61 -> V_62 == V_135 ) )
goto V_53;
V_23 = F_80 ( V_27 , V_61 , V_69 ) ;
V_65 = F_81 ( V_23 ) ;
if ( F_86 ( V_23 ) )
goto V_65;
if ( ! V_61 ) {
V_23 -> V_54 = true ;
F_41 ( & V_23 -> V_52 , V_134 + V_27 -> V_136 ) ;
goto V_53;
}
for ( V_58 = & V_23 -> V_55 ;
( V_48 = F_32 ( * V_58 , V_27 ) ) != NULL ;
V_58 = & V_48 -> V_59 ) {
if ( V_48 -> V_61 == V_61 )
goto V_137;
if ( ( unsigned long ) V_48 -> V_61 < ( unsigned long ) V_61 )
break;
}
V_48 = F_84 ( V_61 , V_69 , * V_58 , V_138 ) ;
if ( F_75 ( ! V_48 ) )
goto V_65;
F_38 ( * V_58 , V_48 ) ;
F_87 ( V_27 -> V_51 , V_61 , V_69 , V_139 ) ;
V_137:
F_41 ( & V_48 -> V_52 , V_134 + V_27 -> V_136 ) ;
V_53:
V_65 = 0 ;
V_65:
F_35 ( & V_27 -> V_50 ) ;
return V_65 ;
}
static int F_88 ( struct V_26 * V_27 ,
struct V_123 * V_61 ,
T_1 V_69 ,
T_2 V_5 )
{
struct V_1 V_140 ;
if ( F_89 ( V_69 ) )
return 0 ;
V_140 . V_7 . V_8 = V_69 ;
V_140 . V_4 = F_2 ( V_6 ) ;
V_140 . V_5 = V_5 ;
return F_85 ( V_27 , V_61 , & V_140 ) ;
}
static int F_90 ( struct V_26 * V_27 ,
struct V_123 * V_61 ,
const struct V_19 * V_69 ,
T_2 V_5 )
{
struct V_1 V_140 ;
if ( F_91 ( V_69 ) )
return 0 ;
V_140 . V_7 . V_11 = * V_69 ;
V_140 . V_4 = F_2 ( V_10 ) ;
V_140 . V_5 = V_5 ;
return F_85 ( V_27 , V_61 , & V_140 ) ;
}
static void F_92 ( unsigned long V_49 )
{
struct V_123 * V_61 = ( void * ) V_49 ;
struct V_26 * V_27 = V_61 -> V_27 ;
F_29 ( & V_27 -> V_50 ) ;
if ( V_61 -> V_141 != 1 ||
F_31 ( & V_61 -> V_142 ) ||
F_43 ( & V_61 -> V_143 ) )
goto V_53;
F_93 ( & V_61 -> V_143 ) ;
V_53:
F_35 ( & V_27 -> V_50 ) ;
}
static void F_94 ( unsigned long V_49 )
{
}
static void F_95 ( struct V_26 * V_27 ,
struct V_144 * V_145 )
{
F_29 ( & V_27 -> V_50 ) ;
if ( ! F_30 ( V_27 -> V_51 ) || V_27 -> V_30 )
goto V_53;
F_96 ( V_27 , V_145 ) ;
V_53:
F_35 ( & V_27 -> V_50 ) ;
}
static void F_97 ( unsigned long V_49 )
{
struct V_26 * V_27 = ( void * ) V_49 ;
F_95 ( V_27 , & V_27 -> V_146 ) ;
}
static void F_98 ( unsigned long V_49 )
{
struct V_26 * V_27 = ( void * ) V_49 ;
F_95 ( V_27 , & V_27 -> V_147 ) ;
}
static void F_99 ( struct V_26 * V_27 ,
struct V_123 * V_61 ,
struct V_1 * V_14 )
{
struct V_28 * V_29 ;
V_29 = F_73 ( V_27 , V_14 ) ;
if ( ! V_29 )
return;
if ( V_61 ) {
F_100 ( V_29 , sizeof( struct V_72 ) ) ;
V_29 -> V_51 = V_61 -> V_51 ;
F_101 ( V_148 , V_149 , V_29 , NULL , V_29 -> V_51 ,
V_150 ) ;
} else
F_102 ( V_29 ) ;
}
static void F_103 ( struct V_26 * V_27 ,
struct V_123 * V_61 ,
struct V_144 * V_145 )
{
unsigned long time ;
struct V_1 V_140 ;
struct V_151 * V_152 = NULL ;
if ( ! F_30 ( V_27 -> V_51 ) || V_27 -> V_30 ||
! V_27 -> V_153 )
return;
memset ( & V_140 . V_7 , 0 , sizeof( V_140 . V_7 ) ) ;
if ( V_61 ? ( V_145 == & V_61 -> V_146 ) :
( V_145 == & V_27 -> V_146 ) ) {
V_152 = & V_27 -> V_154 ;
V_140 . V_4 = F_2 ( V_6 ) ;
#if F_3 ( V_9 )
} else {
V_152 = & V_27 -> V_155 ;
V_140 . V_4 = F_2 ( V_10 ) ;
#endif
}
if ( ! V_152 || F_31 ( & V_152 -> V_52 ) )
return;
F_99 ( V_27 , V_61 , & V_140 ) ;
time = V_60 ;
time += V_145 -> V_156 < V_27 -> V_157 ?
V_27 -> V_158 :
V_27 -> V_159 ;
F_41 ( & V_145 -> V_52 , time ) ;
}
static void F_104 ( struct V_123 * V_61 ,
struct V_144 * V_145 )
{
struct V_26 * V_27 = V_61 -> V_27 ;
F_29 ( & V_27 -> V_50 ) ;
if ( V_61 -> V_62 == V_135 ||
V_61 -> V_62 == V_160 )
goto V_53;
if ( V_145 -> V_156 < V_27 -> V_157 )
V_145 -> V_156 ++ ;
F_103 ( V_61 -> V_27 , V_61 , V_145 ) ;
V_53:
F_35 ( & V_27 -> V_50 ) ;
}
static void F_105 ( unsigned long V_49 )
{
struct V_123 * V_61 = ( void * ) V_49 ;
F_104 ( V_61 , & V_61 -> V_146 ) ;
}
static void F_106 ( unsigned long V_49 )
{
struct V_123 * V_61 = ( void * ) V_49 ;
F_104 ( V_61 , & V_61 -> V_147 ) ;
}
void F_107 ( struct V_123 * V_61 )
{
V_61 -> V_141 = 1 ;
F_82 ( & V_61 -> V_142 , F_92 ,
( unsigned long ) V_61 ) ;
F_82 ( & V_61 -> V_146 . V_52 , F_105 ,
( unsigned long ) V_61 ) ;
#if F_3 ( V_9 )
F_82 ( & V_61 -> V_147 . V_52 , F_106 ,
( unsigned long ) V_61 ) ;
#endif
}
void F_108 ( struct V_123 * V_61 )
{
F_109 ( & V_61 -> V_142 ) ;
}
static void F_110 ( struct V_144 * V_145 )
{
V_145 -> V_156 = 0 ;
if ( F_111 ( & V_145 -> V_52 ) >= 0 ||
F_40 ( & V_145 -> V_52 ) )
F_41 ( & V_145 -> V_52 , V_60 ) ;
}
void F_112 ( struct V_123 * V_61 )
{
struct V_26 * V_27 = V_61 -> V_27 ;
F_29 ( & V_27 -> V_50 ) ;
if ( V_27 -> V_30 || ! F_30 ( V_27 -> V_51 ) )
goto V_53;
F_110 ( & V_61 -> V_146 ) ;
#if F_3 ( V_9 )
F_110 ( & V_61 -> V_147 ) ;
#endif
V_53:
F_35 ( & V_27 -> V_50 ) ;
}
void F_113 ( struct V_123 * V_61 )
{
struct V_26 * V_27 = V_61 -> V_27 ;
struct V_47 * V_57 ;
struct V_161 * V_162 ;
F_29 ( & V_27 -> V_50 ) ;
F_114 (pg, n, &port->mglist, mglist)
F_36 ( V_27 , V_57 ) ;
if ( ! F_43 ( & V_61 -> V_143 ) )
F_93 ( & V_61 -> V_143 ) ;
F_40 ( & V_61 -> V_142 ) ;
F_40 ( & V_61 -> V_146 . V_52 ) ;
#if F_3 ( V_9 )
F_40 ( & V_61 -> V_147 . V_52 ) ;
#endif
F_35 ( & V_27 -> V_50 ) ;
}
static int F_115 ( struct V_26 * V_27 ,
struct V_123 * V_61 ,
struct V_28 * V_29 ,
T_3 V_5 )
{
struct V_163 * V_71 ;
struct V_164 * V_165 ;
int V_43 ;
int V_42 ;
int V_166 ;
int type ;
int V_65 = 0 ;
T_1 V_69 ;
if ( ! F_116 ( V_29 , sizeof( * V_71 ) ) )
return - V_46 ;
V_71 = F_117 ( V_29 ) ;
V_166 = F_118 ( V_71 -> V_167 ) ;
V_42 = sizeof( * V_71 ) ;
for ( V_43 = 0 ; V_43 < V_166 ; V_43 ++ ) {
V_42 += sizeof( * V_165 ) ;
if ( ! F_116 ( V_29 , V_42 ) )
return - V_46 ;
V_165 = ( void * ) ( V_29 -> V_49 + V_42 - sizeof( * V_165 ) ) ;
V_69 = V_165 -> V_168 ;
type = V_165 -> V_169 ;
V_42 += F_118 ( V_165 -> V_170 ) * 4 ;
if ( ! F_116 ( V_29 , V_42 ) )
return - V_46 ;
switch ( type ) {
case V_171 :
case V_172 :
case V_173 :
case V_174 :
case V_175 :
case V_176 :
break;
default:
continue;
}
V_65 = F_88 ( V_27 , V_61 , V_69 , V_5 ) ;
if ( V_65 )
break;
}
return V_65 ;
}
static int F_119 ( struct V_26 * V_27 ,
struct V_123 * V_61 ,
struct V_28 * V_29 ,
T_3 V_5 )
{
struct V_177 * V_178 ;
struct V_179 * V_165 ;
int V_43 ;
int V_42 ;
int V_166 ;
int V_65 = 0 ;
if ( ! F_116 ( V_29 , sizeof( * V_178 ) ) )
return - V_46 ;
V_178 = F_68 ( V_29 ) ;
V_166 = F_118 ( V_178 -> V_180 . V_181 [ 1 ] ) ;
V_42 = sizeof( * V_178 ) ;
for ( V_43 = 0 ; V_43 < V_166 ; V_43 ++ ) {
T_5 * V_182 , V_183 ;
V_182 = F_120 ( V_29 ,
V_42 + F_121 ( struct V_179 ,
V_170 ) ,
sizeof( V_183 ) , & V_183 ) ;
if ( ! V_182 )
return - V_46 ;
if ( ! F_116 ( V_29 ,
V_42 + sizeof( * V_165 ) +
sizeof( struct V_19 ) * F_118 ( * V_182 ) ) )
return - V_46 ;
V_165 = (struct V_179 * ) ( V_29 -> V_49 + V_42 ) ;
V_42 += sizeof( * V_165 ) +
sizeof( struct V_19 ) * F_118 ( * V_182 ) ;
switch ( V_165 -> V_169 ) {
case V_184 :
case V_185 :
case V_186 :
case V_187 :
case V_188 :
case V_189 :
break;
default:
continue;
}
V_65 = F_90 ( V_27 , V_61 , & V_165 -> V_168 ,
V_5 ) ;
if ( ! V_65 )
break;
}
return V_65 ;
}
static void
F_122 ( struct V_26 * V_27 ,
struct V_151 * V_152 ,
unsigned long V_190 )
{
if ( ! F_31 ( & V_152 -> V_52 ) )
V_152 -> V_191 = V_60 + V_190 ;
F_41 ( & V_152 -> V_52 , V_60 + V_27 -> V_192 ) ;
}
static void F_123 ( struct V_26 * V_27 ,
struct V_123 * V_61 )
{
struct V_123 * V_48 ;
struct V_161 * V_193 = NULL ;
F_24 (p, &br->router_list, rlist) {
if ( ( unsigned long ) V_61 >= ( unsigned long ) V_48 )
break;
V_193 = & V_48 -> V_143 ;
}
if ( V_193 )
F_124 ( V_193 , & V_61 -> V_143 ) ;
else
F_83 ( & V_61 -> V_143 , & V_27 -> V_194 ) ;
}
static void F_125 ( struct V_26 * V_27 ,
struct V_123 * V_61 )
{
unsigned long V_134 = V_60 ;
if ( ! V_61 ) {
if ( V_27 -> V_141 == 1 )
F_41 ( & V_27 -> V_142 ,
V_134 + V_27 -> V_192 ) ;
return;
}
if ( V_61 -> V_141 != 1 )
return;
if ( ! F_43 ( & V_61 -> V_143 ) )
goto V_52;
F_123 ( V_27 , V_61 ) ;
V_52:
F_41 ( & V_61 -> V_142 ,
V_134 + V_27 -> V_192 ) ;
}
static void F_126 ( struct V_26 * V_27 ,
struct V_123 * V_61 ,
struct V_151 * V_152 ,
int V_90 ,
bool V_195 ,
unsigned long V_190 )
{
if ( V_90 && V_195 )
F_122 ( V_27 , V_152 , V_190 ) ;
else if ( F_31 ( & V_152 -> V_52 ) )
return;
F_125 ( V_27 , V_61 ) ;
}
static int F_127 ( struct V_26 * V_27 ,
struct V_123 * V_61 ,
struct V_28 * V_29 ,
T_3 V_5 )
{
const struct V_74 * V_75 = F_18 ( V_29 ) ;
struct V_70 * V_71 = F_59 ( V_29 ) ;
struct V_20 * V_23 ;
struct V_196 * V_197 ;
struct V_47 * V_48 ;
struct V_47 T_4 * * V_58 ;
unsigned long V_190 ;
unsigned long V_134 = V_60 ;
T_1 V_69 ;
int V_65 = 0 ;
F_29 ( & V_27 -> V_50 ) ;
if ( ! F_30 ( V_27 -> V_51 ) ||
( V_61 && V_61 -> V_62 == V_135 ) )
goto V_53;
V_69 = V_71 -> V_69 ;
if ( V_29 -> V_42 == sizeof( * V_71 ) ) {
V_190 = V_71 -> V_97 * ( V_100 / V_101 ) ;
if ( ! V_190 ) {
V_190 = 10 * V_100 ;
V_69 = 0 ;
}
} else {
if ( ! F_116 ( V_29 , sizeof( struct V_196 ) ) ) {
V_65 = - V_46 ;
goto V_53;
}
V_197 = F_128 ( V_29 ) ;
if ( V_197 -> V_182 )
goto V_53;
V_190 = V_197 -> V_97 ?
F_129 ( V_197 -> V_97 ) * ( V_100 / V_101 ) : 1 ;
}
if ( ! V_69 && V_75 -> V_33 != F_56 ( V_93 ) ) {
V_65 = - V_46 ;
goto V_53;
}
F_126 ( V_27 , V_61 , & V_27 -> V_154 , ! ! V_75 -> V_90 ,
! V_69 , V_190 ) ;
if ( ! V_69 )
goto V_53;
V_23 = F_13 ( F_32 ( V_27 -> V_13 , V_27 ) , V_69 , V_5 ) ;
if ( ! V_23 )
goto V_53;
V_190 *= V_27 -> V_198 ;
if ( V_23 -> V_54 &&
( F_31 ( & V_23 -> V_52 ) ?
F_130 ( V_23 -> V_52 . V_199 , V_134 + V_190 ) :
F_111 ( & V_23 -> V_52 ) >= 0 ) )
F_41 ( & V_23 -> V_52 , V_134 + V_190 ) ;
for ( V_58 = & V_23 -> V_55 ;
( V_48 = F_32 ( * V_58 , V_27 ) ) != NULL ;
V_58 = & V_48 -> V_59 ) {
if ( F_31 ( & V_48 -> V_52 ) ?
F_130 ( V_48 -> V_52 . V_199 , V_134 + V_190 ) :
F_111 ( & V_48 -> V_52 ) >= 0 )
F_41 ( & V_48 -> V_52 , V_134 + V_190 ) ;
}
V_53:
F_35 ( & V_27 -> V_50 ) ;
return V_65 ;
}
static int F_131 ( struct V_26 * V_27 ,
struct V_123 * V_61 ,
struct V_28 * V_29 ,
T_3 V_5 )
{
const struct V_103 * V_104 = F_19 ( V_29 ) ;
struct V_105 * V_200 ;
struct V_20 * V_23 ;
struct V_201 * V_202 ;
struct V_47 * V_48 ;
struct V_47 T_4 * * V_58 ;
unsigned long V_190 ;
unsigned long V_134 = V_60 ;
const struct V_19 * V_69 = NULL ;
bool V_195 ;
int V_65 = 0 ;
F_29 ( & V_27 -> V_50 ) ;
if ( ! F_30 ( V_27 -> V_51 ) ||
( V_61 && V_61 -> V_62 == V_135 ) )
goto V_53;
if ( ! ( F_132 ( & V_104 -> V_90 ) & V_203 ) ) {
V_65 = - V_46 ;
goto V_53;
}
if ( V_29 -> V_42 == sizeof( * V_200 ) ) {
if ( ! F_116 ( V_29 , sizeof( * V_200 ) ) ) {
V_65 = - V_46 ;
goto V_53;
}
V_200 = (struct V_105 * ) F_68 ( V_29 ) ;
V_190 = F_133 ( F_118 ( V_200 -> V_120 ) ) ;
if ( V_190 )
V_69 = & V_200 -> V_122 ;
} else {
if ( ! F_116 ( V_29 , sizeof( * V_202 ) ) ) {
V_65 = - V_46 ;
goto V_53;
}
V_202 = (struct V_201 * ) F_68 ( V_29 ) ;
if ( ! V_202 -> V_204 )
V_69 = & V_202 -> V_205 ;
V_190 = V_18 ( F_133 ( F_134 ( V_202 ) ) , 1UL ) ;
}
V_195 = V_69 && F_69 ( V_69 ) ;
if ( V_195 && ! F_91 ( & V_104 -> V_33 ) ) {
V_65 = - V_46 ;
goto V_53;
}
F_126 ( V_27 , V_61 , & V_27 -> V_155 ,
! F_69 ( & V_104 -> V_90 ) ,
V_195 , V_190 ) ;
if ( ! V_69 )
goto V_53;
V_23 = F_14 ( F_32 ( V_27 -> V_13 , V_27 ) , V_69 , V_5 ) ;
if ( ! V_23 )
goto V_53;
V_190 *= V_27 -> V_198 ;
if ( V_23 -> V_54 &&
( F_31 ( & V_23 -> V_52 ) ?
F_130 ( V_23 -> V_52 . V_199 , V_134 + V_190 ) :
F_111 ( & V_23 -> V_52 ) >= 0 ) )
F_41 ( & V_23 -> V_52 , V_134 + V_190 ) ;
for ( V_58 = & V_23 -> V_55 ;
( V_48 = F_32 ( * V_58 , V_27 ) ) != NULL ;
V_58 = & V_48 -> V_59 ) {
if ( F_31 ( & V_48 -> V_52 ) ?
F_130 ( V_48 -> V_52 . V_199 , V_134 + V_190 ) :
F_111 ( & V_48 -> V_52 ) >= 0 )
F_41 ( & V_48 -> V_52 , V_134 + V_190 ) ;
}
V_53:
F_35 ( & V_27 -> V_50 ) ;
return V_65 ;
}
static void F_135 ( struct V_26 * V_27 ,
struct V_123 * V_61 ,
struct V_1 * V_69 ,
struct V_151 * V_152 ,
struct V_144 * V_145 )
{
struct V_12 * V_13 ;
struct V_20 * V_23 ;
struct V_47 * V_48 ;
unsigned long V_134 ;
unsigned long time ;
F_29 ( & V_27 -> V_50 ) ;
if ( ! F_30 ( V_27 -> V_51 ) ||
( V_61 && V_61 -> V_62 == V_135 ) ||
F_31 ( & V_152 -> V_52 ) )
goto V_53;
V_13 = F_32 ( V_27 -> V_13 , V_27 ) ;
V_23 = F_12 ( V_13 , V_69 ) ;
if ( ! V_23 )
goto V_53;
if ( V_27 -> V_153 ) {
F_99 ( V_27 , V_61 , & V_23 -> V_24 ) ;
time = V_60 + V_27 -> V_198 *
V_27 -> V_98 ;
F_41 ( & V_145 -> V_52 , time ) ;
for ( V_48 = F_32 ( V_23 -> V_55 , V_27 ) ;
V_48 != NULL ;
V_48 = F_32 ( V_48 -> V_59 , V_27 ) ) {
if ( V_48 -> V_61 != V_61 )
continue;
if ( ! F_43 ( & V_48 -> V_54 ) &&
( F_31 ( & V_48 -> V_52 ) ?
F_130 ( V_48 -> V_52 . V_199 , time ) :
F_111 ( & V_48 -> V_52 ) >= 0 ) ) {
F_41 ( & V_48 -> V_52 , time ) ;
}
break;
}
}
if ( V_61 && ( V_61 -> V_206 & V_207 ) ) {
struct V_47 T_4 * * V_58 ;
for ( V_58 = & V_23 -> V_55 ;
( V_48 = F_32 ( * V_58 , V_27 ) ) != NULL ;
V_58 = & V_48 -> V_59 ) {
if ( V_48 -> V_61 != V_61 )
continue;
F_38 ( * V_58 , V_48 -> V_59 ) ;
F_39 ( & V_48 -> V_54 ) ;
F_40 ( & V_48 -> V_52 ) ;
F_34 ( & V_48 -> V_36 , F_26 ) ;
F_87 ( V_27 -> V_51 , V_61 , V_69 , V_208 ) ;
if ( ! V_23 -> V_55 && ! V_23 -> V_54 &&
F_30 ( V_27 -> V_51 ) )
F_41 ( & V_23 -> V_52 , V_60 ) ;
}
goto V_53;
}
V_134 = V_60 ;
time = V_134 + V_27 -> V_198 *
V_27 -> V_98 ;
if ( ! V_61 ) {
if ( V_23 -> V_54 &&
( F_31 ( & V_23 -> V_52 ) ?
F_130 ( V_23 -> V_52 . V_199 , time ) :
F_111 ( & V_23 -> V_52 ) >= 0 ) ) {
F_41 ( & V_23 -> V_52 , time ) ;
}
goto V_53;
}
for ( V_48 = F_32 ( V_23 -> V_55 , V_27 ) ;
V_48 != NULL ;
V_48 = F_32 ( V_48 -> V_59 , V_27 ) ) {
if ( V_48 -> V_61 != V_61 )
continue;
if ( ! F_43 ( & V_48 -> V_54 ) &&
( F_31 ( & V_48 -> V_52 ) ?
F_130 ( V_48 -> V_52 . V_199 , time ) :
F_111 ( & V_48 -> V_52 ) >= 0 ) ) {
F_41 ( & V_48 -> V_52 , time ) ;
}
break;
}
V_53:
F_35 ( & V_27 -> V_50 ) ;
}
static void F_136 ( struct V_26 * V_27 ,
struct V_123 * V_61 ,
T_1 V_69 ,
T_2 V_5 )
{
struct V_1 V_140 ;
struct V_144 * V_145 = V_61 ? & V_61 -> V_146 :
& V_27 -> V_146 ;
if ( F_89 ( V_69 ) )
return;
V_140 . V_7 . V_8 = V_69 ;
V_140 . V_4 = F_2 ( V_6 ) ;
V_140 . V_5 = V_5 ;
F_135 ( V_27 , V_61 , & V_140 , & V_27 -> V_154 , V_145 ) ;
}
static void F_137 ( struct V_26 * V_27 ,
struct V_123 * V_61 ,
const struct V_19 * V_69 ,
T_2 V_5 )
{
struct V_1 V_140 ;
struct V_144 * V_145 = V_61 ? & V_61 -> V_147 :
& V_27 -> V_147 ;
if ( F_91 ( V_69 ) )
return;
V_140 . V_7 . V_11 = * V_69 ;
V_140 . V_4 = F_2 ( V_10 ) ;
V_140 . V_5 = V_5 ;
F_135 ( V_27 , V_61 , & V_140 , & V_27 -> V_155 , V_145 ) ;
}
static int F_138 ( struct V_26 * V_27 ,
struct V_123 * V_61 ,
struct V_28 * V_29 ,
T_3 V_5 )
{
struct V_28 * V_209 = V_29 ;
const struct V_74 * V_75 ;
struct V_70 * V_71 ;
unsigned int V_42 ;
unsigned int V_210 ;
int V_65 ;
if ( ! F_116 ( V_29 , sizeof( * V_75 ) ) )
return - V_46 ;
V_75 = F_18 ( V_29 ) ;
if ( V_75 -> V_82 < 5 || V_75 -> V_81 != 4 )
return - V_46 ;
if ( ! F_116 ( V_29 , F_139 ( V_29 ) ) )
return - V_46 ;
V_75 = F_18 ( V_29 ) ;
if ( F_75 ( F_140 ( ( V_94 * ) V_75 , V_75 -> V_82 ) ) )
return - V_46 ;
if ( V_75 -> V_32 != V_89 ) {
if ( ! F_89 ( V_75 -> V_33 ) )
F_17 ( V_29 ) -> V_211 = 1 ;
return 0 ;
}
V_42 = F_118 ( V_75 -> V_84 ) ;
if ( V_29 -> V_42 < V_42 || V_42 < F_139 ( V_29 ) )
return - V_46 ;
if ( V_29 -> V_42 > V_42 ) {
V_209 = F_141 ( V_29 , V_66 ) ;
if ( ! V_209 )
return - V_67 ;
V_65 = F_142 ( V_209 , V_42 ) ;
if ( V_65 )
goto V_212;
}
V_42 -= F_139 ( V_209 ) ;
V_210 = F_143 ( V_209 ) + F_139 ( V_209 ) ;
F_61 ( V_209 , V_210 ) ;
F_144 ( V_209 ) ;
V_65 = - V_46 ;
if ( ! F_116 ( V_209 , sizeof( * V_71 ) ) )
goto V_53;
switch ( V_209 -> V_213 ) {
case V_214 :
if ( ! F_145 ( V_209 -> V_102 ) )
break;
case V_215 :
V_209 -> V_102 = 0 ;
if ( F_146 ( V_209 ) )
goto V_53;
}
V_65 = 0 ;
F_17 ( V_29 ) -> V_31 = 1 ;
V_71 = F_59 ( V_209 ) ;
switch ( V_71 -> type ) {
case V_216 :
case V_217 :
F_17 ( V_29 ) -> V_211 = 1 ;
V_65 = F_88 ( V_27 , V_61 , V_71 -> V_69 , V_5 ) ;
break;
case V_218 :
V_65 = F_115 ( V_27 , V_61 , V_209 , V_5 ) ;
break;
case V_96 :
V_65 = F_127 ( V_27 , V_61 , V_209 , V_5 ) ;
break;
case V_219 :
F_136 ( V_27 , V_61 , V_71 -> V_69 , V_5 ) ;
break;
}
V_53:
F_100 ( V_209 , V_210 ) ;
V_212:
if ( V_209 != V_29 )
F_66 ( V_209 ) ;
return V_65 ;
}
static int F_147 ( struct V_26 * V_27 ,
struct V_123 * V_61 ,
struct V_28 * V_29 ,
T_3 V_5 )
{
struct V_28 * V_209 ;
const struct V_103 * V_104 ;
V_94 V_220 ;
V_94 V_110 ;
T_5 V_86 ;
unsigned int V_42 ;
int V_210 ;
int V_65 ;
if ( ! F_116 ( V_29 , sizeof( * V_104 ) ) )
return - V_46 ;
V_104 = F_19 ( V_29 ) ;
if ( V_104 -> V_81 != 6 )
return 0 ;
if ( ! F_91 ( & V_104 -> V_33 ) )
F_17 ( V_29 ) -> V_211 = 1 ;
if ( V_104 -> V_110 != V_111 ||
V_104 -> V_109 == 0 )
return 0 ;
V_42 = F_118 ( V_104 -> V_109 ) + sizeof( * V_104 ) ;
if ( V_29 -> V_42 < V_42 )
return - V_46 ;
V_110 = V_104 -> V_110 ;
V_210 = F_148 ( V_29 , sizeof( * V_104 ) , & V_110 , & V_86 ) ;
if ( V_210 < 0 || V_110 != V_113 )
return 0 ;
V_209 = F_141 ( V_29 , V_66 ) ;
if ( ! V_209 )
return - V_67 ;
V_65 = - V_46 ;
if ( ! F_116 ( V_209 , V_210 + sizeof( struct V_177 ) ) )
goto V_53;
V_42 -= V_210 - F_143 ( V_209 ) ;
F_61 ( V_209 , V_210 ) ;
F_144 ( V_209 ) ;
F_149 ( V_209 , F_150 ( V_209 ) ,
F_151 ( V_209 ) ) ;
V_220 = F_68 ( V_209 ) -> V_220 ;
switch ( V_220 ) {
case V_117 :
case V_221 :
case V_222 :
case V_223 :
break;
default:
V_65 = 0 ;
goto V_53;
}
if ( V_209 -> V_42 > V_42 ) {
V_65 = F_142 ( V_209 , V_42 ) ;
if ( V_65 )
goto V_53;
V_65 = - V_46 ;
}
V_104 = F_19 ( V_209 ) ;
switch ( V_209 -> V_213 ) {
case V_214 :
if ( ! F_71 ( & V_104 -> V_90 , & V_104 -> V_33 , V_209 -> V_42 ,
V_113 , V_209 -> V_102 ) )
break;
case V_215 :
V_209 -> V_102 = ~ F_152 ( F_71 ( & V_104 -> V_90 ,
& V_104 -> V_33 ,
V_209 -> V_42 ,
V_113 , 0 ) ) ;
if ( F_153 ( V_209 ) )
goto V_53;
}
V_65 = 0 ;
F_17 ( V_29 ) -> V_31 = 1 ;
switch ( V_220 ) {
case V_221 :
{
struct V_105 * V_200 ;
if ( ! F_116 ( V_209 , sizeof( * V_200 ) ) ) {
V_65 = - V_46 ;
goto V_53;
}
V_200 = (struct V_105 * ) F_154 ( V_209 ) ;
F_17 ( V_29 ) -> V_211 = 1 ;
V_65 = F_90 ( V_27 , V_61 , & V_200 -> V_122 , V_5 ) ;
break;
}
case V_223 :
V_65 = F_119 ( V_27 , V_61 , V_209 , V_5 ) ;
break;
case V_117 :
V_65 = F_131 ( V_27 , V_61 , V_209 , V_5 ) ;
break;
case V_222 :
{
struct V_105 * V_200 ;
if ( ! F_116 ( V_209 , sizeof( * V_200 ) ) ) {
V_65 = - V_46 ;
goto V_53;
}
V_200 = (struct V_105 * ) F_154 ( V_209 ) ;
F_137 ( V_27 , V_61 , & V_200 -> V_122 , V_5 ) ;
}
}
V_53:
F_66 ( V_209 ) ;
return V_65 ;
}
int F_155 ( struct V_26 * V_27 , struct V_123 * V_61 ,
struct V_28 * V_29 , T_3 V_5 )
{
F_17 ( V_29 ) -> V_31 = 0 ;
F_17 ( V_29 ) -> V_211 = 0 ;
if ( V_27 -> V_30 )
return 0 ;
switch ( V_29 -> V_32 ) {
case F_2 ( V_6 ) :
return F_138 ( V_27 , V_61 , V_29 , V_5 ) ;
#if F_3 ( V_9 )
case F_2 ( V_10 ) :
return F_147 ( V_27 , V_61 , V_29 , V_5 ) ;
#endif
}
return 0 ;
}
static void F_156 ( struct V_26 * V_27 ,
struct V_144 * V_145 )
{
F_29 ( & V_27 -> V_50 ) ;
if ( V_145 -> V_156 < V_27 -> V_157 )
V_145 -> V_156 ++ ;
F_103 ( V_27 , NULL , V_145 ) ;
F_35 ( & V_27 -> V_50 ) ;
}
static void F_157 ( unsigned long V_49 )
{
struct V_26 * V_27 = ( void * ) V_49 ;
F_156 ( V_27 , & V_27 -> V_146 ) ;
}
static void F_158 ( unsigned long V_49 )
{
struct V_26 * V_27 = ( void * ) V_49 ;
F_156 ( V_27 , & V_27 -> V_147 ) ;
}
void F_159 ( struct V_26 * V_27 )
{
V_27 -> V_125 = 4 ;
V_27 -> V_127 = 512 ;
V_27 -> V_141 = 1 ;
V_27 -> V_153 = 0 ;
V_27 -> V_91 = 0 ;
V_27 -> V_198 = 2 ;
V_27 -> V_157 = 2 ;
V_27 -> V_98 = V_100 ;
V_27 -> V_99 = 10 * V_100 ;
V_27 -> V_158 = 125 * V_100 / 4 ;
V_27 -> V_159 = 125 * V_100 ;
V_27 -> V_192 = 255 * V_100 ;
V_27 -> V_136 = 260 * V_100 ;
V_27 -> V_154 . V_191 = 0 ;
#if F_3 ( V_9 )
V_27 -> V_155 . V_191 = 0 ;
#endif
F_160 ( & V_27 -> V_50 ) ;
F_82 ( & V_27 -> V_142 ,
F_94 , 0 ) ;
F_82 ( & V_27 -> V_154 . V_52 , F_97 ,
( unsigned long ) V_27 ) ;
F_82 ( & V_27 -> V_146 . V_52 , F_157 ,
( unsigned long ) V_27 ) ;
#if F_3 ( V_9 )
F_82 ( & V_27 -> V_155 . V_52 , F_98 ,
( unsigned long ) V_27 ) ;
F_82 ( & V_27 -> V_147 . V_52 , F_158 ,
( unsigned long ) V_27 ) ;
#endif
}
static void F_161 ( struct V_26 * V_27 ,
struct V_144 * V_145 )
{
V_145 -> V_156 = 0 ;
if ( V_27 -> V_30 )
return;
F_41 ( & V_145 -> V_52 , V_60 ) ;
}
void F_162 ( struct V_26 * V_27 )
{
F_161 ( V_27 , & V_27 -> V_146 ) ;
#if F_3 ( V_9 )
F_161 ( V_27 , & V_27 -> V_147 ) ;
#endif
}
void F_163 ( struct V_26 * V_27 )
{
struct V_12 * V_13 ;
struct V_20 * V_23 ;
struct V_161 * V_162 ;
V_16 V_45 ;
int V_43 ;
F_109 ( & V_27 -> V_142 ) ;
F_109 ( & V_27 -> V_154 . V_52 ) ;
F_109 ( & V_27 -> V_146 . V_52 ) ;
#if F_3 ( V_9 )
F_109 ( & V_27 -> V_155 . V_52 ) ;
F_109 ( & V_27 -> V_147 . V_52 ) ;
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
int F_167 ( struct V_26 * V_27 , unsigned long V_224 )
{
int V_65 = - V_225 ;
F_164 ( & V_27 -> V_50 ) ;
if ( ! F_30 ( V_27 -> V_51 ) )
goto V_226;
switch ( V_224 ) {
case 0 :
case 2 :
F_40 ( & V_27 -> V_142 ) ;
case 1 :
V_27 -> V_141 = V_224 ;
V_65 = 0 ;
break;
default:
V_65 = - V_46 ;
break;
}
V_226:
F_165 ( & V_27 -> V_50 ) ;
return V_65 ;
}
int F_168 ( struct V_123 * V_48 , unsigned long V_224 )
{
struct V_26 * V_27 = V_48 -> V_27 ;
int V_65 = - V_225 ;
F_29 ( & V_27 -> V_50 ) ;
if ( ! F_30 ( V_27 -> V_51 ) || V_48 -> V_62 == V_135 )
goto V_226;
switch ( V_224 ) {
case 0 :
case 1 :
case 2 :
V_48 -> V_141 = V_224 ;
V_65 = 0 ;
if ( V_224 < 2 && ! F_43 ( & V_48 -> V_143 ) )
F_93 ( & V_48 -> V_143 ) ;
if ( V_224 == 1 )
break;
F_40 ( & V_48 -> V_142 ) ;
if ( V_224 == 0 )
break;
F_123 ( V_27 , V_48 ) ;
break;
default:
V_65 = - V_46 ;
break;
}
V_226:
F_35 ( & V_27 -> V_50 ) ;
return V_65 ;
}
static void F_96 ( struct V_26 * V_27 ,
struct V_144 * V_145 )
{
struct V_123 * V_61 ;
F_161 ( V_27 , V_145 ) ;
F_169 (port, &br->port_list, list) {
if ( V_61 -> V_62 == V_135 ||
V_61 -> V_62 == V_160 )
continue;
if ( V_145 == & V_27 -> V_146 )
F_110 ( & V_61 -> V_146 ) ;
#if F_3 ( V_9 )
else
F_110 ( & V_61 -> V_147 ) ;
#endif
}
}
int F_170 ( struct V_26 * V_27 , unsigned long V_224 )
{
int V_65 = 0 ;
struct V_12 * V_13 ;
F_164 ( & V_27 -> V_50 ) ;
if ( V_27 -> V_30 == ! V_224 )
goto V_226;
V_27 -> V_30 = ! V_224 ;
if ( V_27 -> V_30 )
goto V_226;
if ( ! F_30 ( V_27 -> V_51 ) )
goto V_226;
V_13 = F_32 ( V_27 -> V_13 , V_27 ) ;
if ( V_13 ) {
if ( V_13 -> V_37 ) {
V_65 = - V_130 ;
V_227:
V_27 -> V_30 = ! ! V_224 ;
goto V_226;
}
V_65 = F_44 ( & V_27 -> V_13 , V_13 -> V_18 ,
V_27 -> V_125 ) ;
if ( V_65 )
goto V_227;
}
F_96 ( V_27 , & V_27 -> V_146 ) ;
#if F_3 ( V_9 )
F_96 ( V_27 , & V_27 -> V_147 ) ;
#endif
V_226:
F_165 ( & V_27 -> V_50 ) ;
return V_65 ;
}
int F_171 ( struct V_26 * V_27 , unsigned long V_224 )
{
unsigned long V_190 ;
V_224 = ! ! V_224 ;
F_164 ( & V_27 -> V_50 ) ;
if ( V_27 -> V_153 == V_224 )
goto V_226;
V_27 -> V_153 = V_224 ;
if ( ! V_224 )
goto V_226;
V_190 = V_27 -> V_99 ;
if ( ! F_31 ( & V_27 -> V_154 . V_52 ) )
V_27 -> V_154 . V_191 = V_60 + V_190 ;
F_96 ( V_27 , & V_27 -> V_146 ) ;
#if F_3 ( V_9 )
if ( ! F_31 ( & V_27 -> V_155 . V_52 ) )
V_27 -> V_155 . V_191 = V_60 + V_190 ;
F_96 ( V_27 , & V_27 -> V_147 ) ;
#endif
V_226:
F_165 ( & V_27 -> V_50 ) ;
return 0 ;
}
int F_172 ( struct V_26 * V_27 , unsigned long V_224 )
{
int V_65 = - V_225 ;
V_16 V_37 ;
struct V_12 * V_13 ;
F_164 ( & V_27 -> V_50 ) ;
if ( ! F_30 ( V_27 -> V_51 ) )
goto V_226;
V_65 = - V_46 ;
if ( ! F_173 ( V_224 ) )
goto V_226;
V_13 = F_32 ( V_27 -> V_13 , V_27 ) ;
if ( V_13 && V_224 < V_13 -> V_56 )
goto V_226;
V_65 = 0 ;
V_37 = V_27 -> V_127 ;
V_27 -> V_127 = V_224 ;
if ( V_13 ) {
if ( V_13 -> V_37 ) {
V_65 = - V_130 ;
V_227:
V_27 -> V_127 = V_37 ;
goto V_226;
}
V_65 = F_44 ( & V_27 -> V_13 , V_27 -> V_127 ,
V_27 -> V_125 ) ;
if ( V_65 )
goto V_227;
}
V_226:
F_165 ( & V_27 -> V_50 ) ;
return V_65 ;
}
