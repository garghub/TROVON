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
memcpy ( V_73 -> V_76 , V_27 -> V_51 -> V_77 , 6 ) ;
V_73 -> V_78 [ 0 ] = 1 ;
V_73 -> V_78 [ 1 ] = 0 ;
V_73 -> V_78 [ 2 ] = 0x5e ;
V_73 -> V_78 [ 3 ] = 0 ;
V_73 -> V_78 [ 4 ] = 0 ;
V_73 -> V_78 [ 5 ] = 1 ;
V_73 -> V_79 = F_2 ( V_6 ) ;
F_53 ( V_29 , sizeof( * V_73 ) ) ;
F_54 ( V_29 , V_29 -> V_42 ) ;
V_75 = F_18 ( V_29 ) ;
V_75 -> V_80 = 4 ;
V_75 -> V_81 = 6 ;
V_75 -> V_82 = 0xc0 ;
V_75 -> V_83 = F_2 ( sizeof( * V_75 ) + sizeof( * V_71 ) + 4 ) ;
V_75 -> V_84 = 0 ;
V_75 -> V_85 = F_2 ( V_86 ) ;
V_75 -> V_87 = 1 ;
V_75 -> V_32 = V_88 ;
V_75 -> V_89 = V_27 -> V_90 ?
F_55 ( V_27 -> V_51 , 0 , V_91 ) : 0 ;
V_75 -> V_33 = F_56 ( V_92 ) ;
( ( V_93 * ) & V_75 [ 1 ] ) [ 0 ] = V_94 ;
( ( V_93 * ) & V_75 [ 1 ] ) [ 1 ] = 4 ;
( ( V_93 * ) & V_75 [ 1 ] ) [ 2 ] = 0 ;
( ( V_93 * ) & V_75 [ 1 ] ) [ 3 ] = 0 ;
F_57 ( V_75 ) ;
F_53 ( V_29 , 24 ) ;
F_58 ( V_29 , V_29 -> V_42 ) ;
V_71 = F_59 ( V_29 ) ;
V_71 -> type = V_95 ;
V_71 -> V_96 = ( V_69 ? V_27 -> V_97 :
V_27 -> V_98 ) /
( V_99 / V_100 ) ;
V_71 -> V_69 = V_69 ;
V_71 -> V_101 = 0 ;
V_71 -> V_101 = F_60 ( ( void * ) V_71 , sizeof( struct V_70 ) ) ;
F_53 ( V_29 , sizeof( * V_71 ) ) ;
F_61 ( V_29 , sizeof( * V_73 ) ) ;
V_53:
return V_29 ;
}
static struct V_28 * F_62 ( struct V_26 * V_27 ,
const struct V_19 * V_69 )
{
struct V_28 * V_29 ;
struct V_102 * V_103 ;
struct V_104 * V_105 ;
struct V_72 * V_73 ;
V_93 * V_106 ;
unsigned long V_107 ;
V_29 = F_50 ( V_27 -> V_51 , sizeof( * V_73 ) + sizeof( * V_103 ) +
8 + sizeof( * V_105 ) ) ;
if ( ! V_29 )
goto V_53;
V_29 -> V_32 = F_2 ( V_10 ) ;
F_51 ( V_29 ) ;
V_73 = F_52 ( V_29 ) ;
memcpy ( V_73 -> V_76 , V_27 -> V_51 -> V_77 , 6 ) ;
V_73 -> V_79 = F_2 ( V_10 ) ;
F_53 ( V_29 , sizeof( * V_73 ) ) ;
F_54 ( V_29 , V_29 -> V_42 ) ;
V_103 = F_19 ( V_29 ) ;
* ( V_15 T_1 * ) V_103 = F_56 ( 0x60000000 ) ;
V_103 -> V_108 = F_2 ( 8 + sizeof( * V_105 ) ) ;
V_103 -> V_109 = V_110 ;
V_103 -> V_111 = 1 ;
F_63 ( & V_103 -> V_33 , F_56 ( 0xff020000 ) , 0 , 0 , F_56 ( 1 ) ) ;
if ( F_64 ( F_65 ( V_27 -> V_51 ) , V_27 -> V_51 , & V_103 -> V_33 , 0 ,
& V_103 -> V_89 ) ) {
F_66 ( V_29 ) ;
return NULL ;
}
F_67 ( & V_103 -> V_33 , V_73 -> V_78 ) ;
V_106 = ( V_93 * ) ( V_103 + 1 ) ;
V_106 [ 0 ] = V_112 ;
V_106 [ 1 ] = 0 ;
V_106 [ 2 ] = V_113 ;
V_106 [ 3 ] = 2 ;
V_106 [ 4 ] = 0 ;
V_106 [ 5 ] = 0 ;
V_106 [ 6 ] = V_114 ;
V_106 [ 7 ] = V_114 ;
F_53 ( V_29 , sizeof( * V_103 ) + 8 ) ;
F_58 ( V_29 , V_29 -> V_42 ) ;
V_105 = (struct V_104 * ) F_68 ( V_29 ) ;
V_107 = F_69 ( V_69 ) ?
V_27 -> V_98 :
V_27 -> V_97 ;
V_105 -> V_115 = V_116 ;
V_105 -> V_117 = 0 ;
V_105 -> V_118 = 0 ;
V_105 -> V_119 = F_2 ( ( T_3 ) F_70 ( V_107 ) ) ;
V_105 -> V_120 = 0 ;
V_105 -> V_121 = * V_69 ;
V_105 -> V_118 = F_71 ( & V_103 -> V_89 , & V_103 -> V_33 ,
sizeof( * V_105 ) , V_112 ,
F_72 ( V_105 ,
sizeof( * V_105 ) , 0 ) ) ;
F_53 ( V_29 , sizeof( * V_105 ) ) ;
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
struct V_26 * V_27 , struct V_122 * V_61 ,
struct V_1 * V_69 , int V_22 )
{
struct V_12 * V_13 ;
struct V_20 * V_23 ;
unsigned int V_123 = 0 ;
unsigned int V_18 ;
int V_40 ;
int V_65 ;
V_13 = F_45 ( V_27 -> V_13 , 1 ) ;
F_24 (mp, &mdb->mhash[hash], hlist[mdb->ver]) {
V_123 ++ ;
if ( F_75 ( F_1 ( V_69 , & V_23 -> V_24 ) ) )
return V_23 ;
}
V_40 = 0 ;
V_18 = V_13 -> V_18 ;
if ( F_75 ( V_123 > V_27 -> V_124 && V_123 ) ) {
if ( F_76 () )
F_77 ( V_27 , L_1
L_2 ,
V_61 ? V_61 -> V_51 -> V_125 : V_27 -> V_51 -> V_125 ) ;
V_40 = V_27 -> V_124 ;
}
if ( V_13 -> V_56 >= V_18 ) {
V_18 *= 2 ;
if ( F_75 ( V_18 > V_27 -> V_126 ) ) {
F_78 ( V_27 , L_3
L_4 ,
V_27 -> V_126 ,
V_61 ? V_61 -> V_51 -> V_125 : V_27 -> V_51 -> V_125 ) ;
V_65 = - V_127 ;
V_128:
V_27 -> V_30 = 1 ;
goto V_65;
}
}
if ( V_18 > V_13 -> V_18 || V_40 ) {
if ( V_13 -> V_37 ) {
if ( F_76 () )
F_77 ( V_27 , L_1
L_5 ,
V_61 ? V_61 -> V_51 -> V_125 : V_27 -> V_51 -> V_125 ) ;
V_65 = - V_129 ;
goto V_65;
}
V_65 = F_44 ( & V_27 -> V_13 , V_18 , V_40 ) ;
if ( V_65 ) {
F_78 ( V_27 , L_6
L_7 ,
V_61 ? V_61 -> V_51 -> V_125 : V_27 -> V_51 -> V_125 ,
V_13 -> V_56 , V_65 ) ;
goto V_128;
}
V_65 = - V_130 ;
goto V_65;
}
return NULL ;
V_65:
V_23 = F_79 ( V_65 ) ;
return V_23 ;
}
struct V_20 * F_80 ( struct V_26 * V_27 ,
struct V_122 * V_61 , struct V_1 * V_69 )
{
struct V_12 * V_13 ;
struct V_20 * V_23 ;
int V_22 ;
int V_65 ;
V_13 = F_45 ( V_27 -> V_13 , 1 ) ;
if ( ! V_13 ) {
V_65 = F_44 ( & V_27 -> V_13 , V_131 , 0 ) ;
if ( V_65 )
return F_79 ( V_65 ) ;
goto V_132;
}
V_22 = F_9 ( V_13 , V_69 ) ;
V_23 = F_74 ( V_27 , V_61 , V_69 , V_22 ) ;
switch ( F_81 ( V_23 ) ) {
case 0 :
break;
case - V_130 :
V_132:
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
struct V_122 * V_61 ,
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
struct V_122 * V_61 ,
struct V_1 * V_69 )
{
struct V_20 * V_23 ;
struct V_47 * V_48 ;
struct V_47 T_4 * * V_58 ;
unsigned long V_133 = V_60 ;
int V_65 ;
F_29 ( & V_27 -> V_50 ) ;
if ( ! F_30 ( V_27 -> V_51 ) ||
( V_61 && V_61 -> V_62 == V_134 ) )
goto V_53;
V_23 = F_80 ( V_27 , V_61 , V_69 ) ;
V_65 = F_81 ( V_23 ) ;
if ( F_86 ( V_23 ) )
goto V_65;
if ( ! V_61 ) {
V_23 -> V_54 = true ;
F_41 ( & V_23 -> V_52 , V_133 + V_27 -> V_135 ) ;
goto V_53;
}
for ( V_58 = & V_23 -> V_55 ;
( V_48 = F_32 ( * V_58 , V_27 ) ) != NULL ;
V_58 = & V_48 -> V_59 ) {
if ( V_48 -> V_61 == V_61 )
goto V_136;
if ( ( unsigned long ) V_48 -> V_61 < ( unsigned long ) V_61 )
break;
}
V_48 = F_84 ( V_61 , V_69 , * V_58 , V_137 ) ;
if ( F_75 ( ! V_48 ) )
goto V_65;
F_38 ( * V_58 , V_48 ) ;
F_87 ( V_27 -> V_51 , V_61 , V_69 , V_138 ) ;
V_136:
F_41 ( & V_48 -> V_52 , V_133 + V_27 -> V_135 ) ;
V_53:
V_65 = 0 ;
V_65:
F_35 ( & V_27 -> V_50 ) ;
return V_65 ;
}
static int F_88 ( struct V_26 * V_27 ,
struct V_122 * V_61 ,
T_1 V_69 ,
T_2 V_5 )
{
struct V_1 V_139 ;
if ( F_89 ( V_69 ) )
return 0 ;
V_139 . V_7 . V_8 = V_69 ;
V_139 . V_4 = F_2 ( V_6 ) ;
V_139 . V_5 = V_5 ;
return F_85 ( V_27 , V_61 , & V_139 ) ;
}
static int F_90 ( struct V_26 * V_27 ,
struct V_122 * V_61 ,
const struct V_19 * V_69 ,
T_2 V_5 )
{
struct V_1 V_139 ;
if ( F_91 ( V_69 ) )
return 0 ;
V_139 . V_7 . V_11 = * V_69 ;
V_139 . V_4 = F_2 ( V_10 ) ;
V_139 . V_5 = V_5 ;
return F_85 ( V_27 , V_61 , & V_139 ) ;
}
static void F_92 ( unsigned long V_49 )
{
struct V_122 * V_61 = ( void * ) V_49 ;
struct V_26 * V_27 = V_61 -> V_27 ;
F_29 ( & V_27 -> V_50 ) ;
if ( V_61 -> V_140 != 1 ||
F_31 ( & V_61 -> V_141 ) ||
F_43 ( & V_61 -> V_142 ) )
goto V_53;
F_93 ( & V_61 -> V_142 ) ;
V_53:
F_35 ( & V_27 -> V_50 ) ;
}
static void F_94 ( unsigned long V_49 )
{
}
static void F_95 ( struct V_26 * V_27 ,
struct V_143 * V_144 )
{
F_29 ( & V_27 -> V_50 ) ;
if ( ! F_30 ( V_27 -> V_51 ) || V_27 -> V_30 )
goto V_53;
F_96 ( V_27 , V_144 ) ;
V_53:
F_35 ( & V_27 -> V_50 ) ;
}
static void F_97 ( unsigned long V_49 )
{
struct V_26 * V_27 = ( void * ) V_49 ;
F_95 ( V_27 , & V_27 -> V_145 ) ;
}
static void F_98 ( unsigned long V_49 )
{
struct V_26 * V_27 = ( void * ) V_49 ;
F_95 ( V_27 , & V_27 -> V_146 ) ;
}
static void F_99 ( struct V_26 * V_27 ,
struct V_122 * V_61 ,
struct V_1 * V_14 )
{
struct V_28 * V_29 ;
V_29 = F_73 ( V_27 , V_14 ) ;
if ( ! V_29 )
return;
if ( V_61 ) {
F_100 ( V_29 , sizeof( struct V_72 ) ) ;
V_29 -> V_51 = V_61 -> V_51 ;
F_101 ( V_147 , V_148 , V_29 , NULL , V_29 -> V_51 ,
V_149 ) ;
} else
F_102 ( V_29 ) ;
}
static void F_103 ( struct V_26 * V_27 ,
struct V_122 * V_61 ,
struct V_143 * V_144 )
{
unsigned long time ;
struct V_1 V_139 ;
struct V_150 * V_151 = NULL ;
if ( ! F_30 ( V_27 -> V_51 ) || V_27 -> V_30 ||
! V_27 -> V_152 )
return;
memset ( & V_139 . V_7 , 0 , sizeof( V_139 . V_7 ) ) ;
if ( V_61 ? ( V_144 == & V_61 -> V_145 ) :
( V_144 == & V_27 -> V_145 ) ) {
V_151 = & V_27 -> V_153 ;
V_139 . V_4 = F_2 ( V_6 ) ;
#if F_3 ( V_9 )
} else {
V_151 = & V_27 -> V_154 ;
V_139 . V_4 = F_2 ( V_10 ) ;
#endif
}
if ( ! V_151 || F_31 ( & V_151 -> V_52 ) )
return;
F_99 ( V_27 , V_61 , & V_139 ) ;
time = V_60 ;
time += V_144 -> V_155 < V_27 -> V_156 ?
V_27 -> V_157 :
V_27 -> V_158 ;
F_41 ( & V_144 -> V_52 , time ) ;
}
static void F_104 ( struct V_122 * V_61 ,
struct V_143 * V_144 )
{
struct V_26 * V_27 = V_61 -> V_27 ;
F_29 ( & V_27 -> V_50 ) ;
if ( V_61 -> V_62 == V_134 ||
V_61 -> V_62 == V_159 )
goto V_53;
if ( V_144 -> V_155 < V_27 -> V_156 )
V_144 -> V_155 ++ ;
F_103 ( V_61 -> V_27 , V_61 , V_144 ) ;
V_53:
F_35 ( & V_27 -> V_50 ) ;
}
static void F_105 ( unsigned long V_49 )
{
struct V_122 * V_61 = ( void * ) V_49 ;
F_104 ( V_61 , & V_61 -> V_145 ) ;
}
static void F_106 ( unsigned long V_49 )
{
struct V_122 * V_61 = ( void * ) V_49 ;
F_104 ( V_61 , & V_61 -> V_146 ) ;
}
void F_107 ( struct V_122 * V_61 )
{
V_61 -> V_140 = 1 ;
F_82 ( & V_61 -> V_141 , F_92 ,
( unsigned long ) V_61 ) ;
F_82 ( & V_61 -> V_145 . V_52 , F_105 ,
( unsigned long ) V_61 ) ;
#if F_3 ( V_9 )
F_82 ( & V_61 -> V_146 . V_52 , F_106 ,
( unsigned long ) V_61 ) ;
#endif
}
void F_108 ( struct V_122 * V_61 )
{
F_109 ( & V_61 -> V_141 ) ;
}
static void F_110 ( struct V_143 * V_144 )
{
V_144 -> V_155 = 0 ;
if ( F_111 ( & V_144 -> V_52 ) >= 0 ||
F_40 ( & V_144 -> V_52 ) )
F_41 ( & V_144 -> V_52 , V_60 ) ;
}
void F_112 ( struct V_122 * V_61 )
{
struct V_26 * V_27 = V_61 -> V_27 ;
F_29 ( & V_27 -> V_50 ) ;
if ( V_27 -> V_30 || ! F_30 ( V_27 -> V_51 ) )
goto V_53;
F_110 ( & V_61 -> V_145 ) ;
#if F_3 ( V_9 )
F_110 ( & V_61 -> V_146 ) ;
#endif
V_53:
F_35 ( & V_27 -> V_50 ) ;
}
void F_113 ( struct V_122 * V_61 )
{
struct V_26 * V_27 = V_61 -> V_27 ;
struct V_47 * V_57 ;
struct V_160 * V_161 ;
F_29 ( & V_27 -> V_50 ) ;
F_114 (pg, n, &port->mglist, mglist)
F_36 ( V_27 , V_57 ) ;
if ( ! F_43 ( & V_61 -> V_142 ) )
F_93 ( & V_61 -> V_142 ) ;
F_40 ( & V_61 -> V_141 ) ;
F_40 ( & V_61 -> V_145 . V_52 ) ;
#if F_3 ( V_9 )
F_40 ( & V_61 -> V_146 . V_52 ) ;
#endif
F_35 ( & V_27 -> V_50 ) ;
}
static int F_115 ( struct V_26 * V_27 ,
struct V_122 * V_61 ,
struct V_28 * V_29 )
{
struct V_162 * V_71 ;
struct V_163 * V_164 ;
int V_43 ;
int V_42 ;
int V_165 ;
int type ;
int V_65 = 0 ;
T_1 V_69 ;
T_3 V_5 = 0 ;
if ( ! F_116 ( V_29 , sizeof( * V_71 ) ) )
return - V_46 ;
F_117 ( V_29 , & V_5 ) ;
V_71 = F_118 ( V_29 ) ;
V_165 = F_119 ( V_71 -> V_166 ) ;
V_42 = sizeof( * V_71 ) ;
for ( V_43 = 0 ; V_43 < V_165 ; V_43 ++ ) {
V_42 += sizeof( * V_164 ) ;
if ( ! F_116 ( V_29 , V_42 ) )
return - V_46 ;
V_164 = ( void * ) ( V_29 -> V_49 + V_42 - sizeof( * V_164 ) ) ;
V_69 = V_164 -> V_167 ;
type = V_164 -> V_168 ;
V_42 += F_119 ( V_164 -> V_169 ) * 4 ;
if ( ! F_116 ( V_29 , V_42 ) )
return - V_46 ;
switch ( type ) {
case V_170 :
case V_171 :
case V_172 :
case V_173 :
case V_174 :
case V_175 :
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
static int F_120 ( struct V_26 * V_27 ,
struct V_122 * V_61 ,
struct V_28 * V_29 )
{
struct V_176 * V_177 ;
struct V_178 * V_164 ;
int V_43 ;
int V_42 ;
int V_165 ;
int V_65 = 0 ;
T_3 V_5 = 0 ;
if ( ! F_116 ( V_29 , sizeof( * V_177 ) ) )
return - V_46 ;
F_117 ( V_29 , & V_5 ) ;
V_177 = F_68 ( V_29 ) ;
V_165 = F_119 ( V_177 -> V_179 . V_180 [ 1 ] ) ;
V_42 = sizeof( * V_177 ) ;
for ( V_43 = 0 ; V_43 < V_165 ; V_43 ++ ) {
T_5 * V_181 , V_182 ;
V_181 = F_121 ( V_29 ,
V_42 + F_122 ( struct V_178 ,
V_169 ) ,
sizeof( V_182 ) , & V_182 ) ;
if ( ! V_181 )
return - V_46 ;
if ( ! F_116 ( V_29 ,
V_42 + sizeof( * V_164 ) +
sizeof( struct V_19 ) * F_119 ( * V_181 ) ) )
return - V_46 ;
V_164 = (struct V_178 * ) ( V_29 -> V_49 + V_42 ) ;
V_42 += sizeof( * V_164 ) +
sizeof( struct V_19 ) * F_119 ( * V_181 ) ;
switch ( V_164 -> V_168 ) {
case V_183 :
case V_184 :
case V_185 :
case V_186 :
case V_187 :
case V_188 :
break;
default:
continue;
}
V_65 = F_90 ( V_27 , V_61 , & V_164 -> V_167 ,
V_5 ) ;
if ( ! V_65 )
break;
}
return V_65 ;
}
static void
F_123 ( struct V_26 * V_27 ,
struct V_150 * V_151 ,
unsigned long V_189 )
{
if ( ! F_31 ( & V_151 -> V_52 ) )
V_151 -> V_190 = V_60 + V_189 ;
F_41 ( & V_151 -> V_52 , V_60 + V_27 -> V_191 ) ;
}
static void F_124 ( struct V_26 * V_27 ,
struct V_122 * V_61 )
{
struct V_122 * V_48 ;
struct V_160 * V_192 = NULL ;
F_24 (p, &br->router_list, rlist) {
if ( ( unsigned long ) V_61 >= ( unsigned long ) V_48 )
break;
V_192 = & V_48 -> V_142 ;
}
if ( V_192 )
F_125 ( V_192 , & V_61 -> V_142 ) ;
else
F_83 ( & V_61 -> V_142 , & V_27 -> V_193 ) ;
}
static void F_126 ( struct V_26 * V_27 ,
struct V_122 * V_61 )
{
unsigned long V_133 = V_60 ;
if ( ! V_61 ) {
if ( V_27 -> V_140 == 1 )
F_41 ( & V_27 -> V_141 ,
V_133 + V_27 -> V_191 ) ;
return;
}
if ( V_61 -> V_140 != 1 )
return;
if ( ! F_43 ( & V_61 -> V_142 ) )
goto V_52;
F_124 ( V_27 , V_61 ) ;
V_52:
F_41 ( & V_61 -> V_141 ,
V_133 + V_27 -> V_191 ) ;
}
static void F_127 ( struct V_26 * V_27 ,
struct V_122 * V_61 ,
struct V_150 * V_151 ,
int V_89 ,
unsigned long V_189 )
{
if ( V_89 )
F_123 ( V_27 , V_151 , V_189 ) ;
else if ( F_31 ( & V_151 -> V_52 ) )
return;
F_126 ( V_27 , V_61 ) ;
}
static int F_128 ( struct V_26 * V_27 ,
struct V_122 * V_61 ,
struct V_28 * V_29 )
{
const struct V_74 * V_75 = F_18 ( V_29 ) ;
struct V_70 * V_71 = F_59 ( V_29 ) ;
struct V_20 * V_23 ;
struct V_194 * V_195 ;
struct V_47 * V_48 ;
struct V_47 T_4 * * V_58 ;
unsigned long V_189 ;
unsigned long V_133 = V_60 ;
T_1 V_69 ;
int V_65 = 0 ;
T_3 V_5 = 0 ;
F_29 ( & V_27 -> V_50 ) ;
if ( ! F_30 ( V_27 -> V_51 ) ||
( V_61 && V_61 -> V_62 == V_134 ) )
goto V_53;
V_69 = V_71 -> V_69 ;
if ( V_29 -> V_42 == sizeof( * V_71 ) ) {
V_189 = V_71 -> V_96 * ( V_99 / V_100 ) ;
if ( ! V_189 ) {
V_189 = 10 * V_99 ;
V_69 = 0 ;
}
} else {
if ( ! F_116 ( V_29 , sizeof( struct V_194 ) ) ) {
V_65 = - V_46 ;
goto V_53;
}
V_195 = F_129 ( V_29 ) ;
if ( V_195 -> V_181 )
goto V_53;
V_189 = V_195 -> V_96 ?
F_130 ( V_195 -> V_96 ) * ( V_99 / V_100 ) : 1 ;
}
F_127 ( V_27 , V_61 , & V_27 -> V_153 , ! ! V_75 -> V_89 ,
V_189 ) ;
if ( ! V_69 )
goto V_53;
F_117 ( V_29 , & V_5 ) ;
V_23 = F_13 ( F_32 ( V_27 -> V_13 , V_27 ) , V_69 , V_5 ) ;
if ( ! V_23 )
goto V_53;
V_189 *= V_27 -> V_196 ;
if ( V_23 -> V_54 &&
( F_31 ( & V_23 -> V_52 ) ?
F_131 ( V_23 -> V_52 . V_197 , V_133 + V_189 ) :
F_111 ( & V_23 -> V_52 ) >= 0 ) )
F_41 ( & V_23 -> V_52 , V_133 + V_189 ) ;
for ( V_58 = & V_23 -> V_55 ;
( V_48 = F_32 ( * V_58 , V_27 ) ) != NULL ;
V_58 = & V_48 -> V_59 ) {
if ( F_31 ( & V_48 -> V_52 ) ?
F_131 ( V_48 -> V_52 . V_197 , V_133 + V_189 ) :
F_111 ( & V_48 -> V_52 ) >= 0 )
F_41 ( & V_48 -> V_52 , V_133 + V_189 ) ;
}
V_53:
F_35 ( & V_27 -> V_50 ) ;
return V_65 ;
}
static int F_132 ( struct V_26 * V_27 ,
struct V_122 * V_61 ,
struct V_28 * V_29 )
{
const struct V_102 * V_103 = F_19 ( V_29 ) ;
struct V_104 * V_198 ;
struct V_20 * V_23 ;
struct V_199 * V_200 ;
struct V_47 * V_48 ;
struct V_47 T_4 * * V_58 ;
unsigned long V_189 ;
unsigned long V_133 = V_60 ;
const struct V_19 * V_69 = NULL ;
int V_65 = 0 ;
T_3 V_5 = 0 ;
F_29 ( & V_27 -> V_50 ) ;
if ( ! F_30 ( V_27 -> V_51 ) ||
( V_61 && V_61 -> V_62 == V_134 ) )
goto V_53;
if ( V_29 -> V_42 == sizeof( * V_198 ) ) {
if ( ! F_116 ( V_29 , sizeof( * V_198 ) ) ) {
V_65 = - V_46 ;
goto V_53;
}
V_198 = (struct V_104 * ) F_68 ( V_29 ) ;
V_189 = F_133 ( F_119 ( V_198 -> V_119 ) ) ;
if ( V_189 )
V_69 = & V_198 -> V_121 ;
} else {
if ( ! F_116 ( V_29 , sizeof( * V_200 ) ) ) {
V_65 = - V_46 ;
goto V_53;
}
V_200 = (struct V_199 * ) F_68 ( V_29 ) ;
if ( ! V_200 -> V_201 )
V_69 = & V_200 -> V_202 ;
V_189 = V_18 ( F_133 ( F_134 ( V_200 ) ) , 1UL ) ;
}
F_127 ( V_27 , V_61 , & V_27 -> V_154 ,
! F_69 ( & V_103 -> V_89 ) , V_189 ) ;
if ( ! V_69 )
goto V_53;
F_117 ( V_29 , & V_5 ) ;
V_23 = F_14 ( F_32 ( V_27 -> V_13 , V_27 ) , V_69 , V_5 ) ;
if ( ! V_23 )
goto V_53;
V_189 *= V_27 -> V_196 ;
if ( V_23 -> V_54 &&
( F_31 ( & V_23 -> V_52 ) ?
F_131 ( V_23 -> V_52 . V_197 , V_133 + V_189 ) :
F_111 ( & V_23 -> V_52 ) >= 0 ) )
F_41 ( & V_23 -> V_52 , V_133 + V_189 ) ;
for ( V_58 = & V_23 -> V_55 ;
( V_48 = F_32 ( * V_58 , V_27 ) ) != NULL ;
V_58 = & V_48 -> V_59 ) {
if ( F_31 ( & V_48 -> V_52 ) ?
F_131 ( V_48 -> V_52 . V_197 , V_133 + V_189 ) :
F_111 ( & V_48 -> V_52 ) >= 0 )
F_41 ( & V_48 -> V_52 , V_133 + V_189 ) ;
}
V_53:
F_35 ( & V_27 -> V_50 ) ;
return V_65 ;
}
static void F_135 ( struct V_26 * V_27 ,
struct V_122 * V_61 ,
struct V_1 * V_69 ,
struct V_150 * V_151 ,
struct V_143 * V_144 )
{
struct V_12 * V_13 ;
struct V_20 * V_23 ;
struct V_47 * V_48 ;
unsigned long V_133 ;
unsigned long time ;
F_29 ( & V_27 -> V_50 ) ;
if ( ! F_30 ( V_27 -> V_51 ) ||
( V_61 && V_61 -> V_62 == V_134 ) ||
F_31 ( & V_151 -> V_52 ) )
goto V_53;
V_13 = F_32 ( V_27 -> V_13 , V_27 ) ;
V_23 = F_12 ( V_13 , V_69 ) ;
if ( ! V_23 )
goto V_53;
if ( V_27 -> V_152 ) {
F_99 ( V_27 , V_61 , & V_23 -> V_24 ) ;
time = V_60 + V_27 -> V_196 *
V_27 -> V_97 ;
F_41 ( & V_144 -> V_52 , time ) ;
for ( V_48 = F_32 ( V_23 -> V_55 , V_27 ) ;
V_48 != NULL ;
V_48 = F_32 ( V_48 -> V_59 , V_27 ) ) {
if ( V_48 -> V_61 != V_61 )
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
if ( V_61 && ( V_61 -> V_203 & V_204 ) ) {
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
F_87 ( V_27 -> V_51 , V_61 , V_69 , V_205 ) ;
if ( ! V_23 -> V_55 && ! V_23 -> V_54 &&
F_30 ( V_27 -> V_51 ) )
F_41 ( & V_23 -> V_52 , V_60 ) ;
}
goto V_53;
}
V_133 = V_60 ;
time = V_133 + V_27 -> V_196 *
V_27 -> V_97 ;
if ( ! V_61 ) {
if ( V_23 -> V_54 &&
( F_31 ( & V_23 -> V_52 ) ?
F_131 ( V_23 -> V_52 . V_197 , time ) :
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
F_131 ( V_48 -> V_52 . V_197 , time ) :
F_111 ( & V_48 -> V_52 ) >= 0 ) ) {
F_41 ( & V_48 -> V_52 , time ) ;
}
break;
}
V_53:
F_35 ( & V_27 -> V_50 ) ;
}
static void F_136 ( struct V_26 * V_27 ,
struct V_122 * V_61 ,
T_1 V_69 ,
T_2 V_5 )
{
struct V_1 V_139 ;
struct V_143 * V_144 = V_61 ? & V_61 -> V_145 :
& V_27 -> V_145 ;
if ( F_89 ( V_69 ) )
return;
V_139 . V_7 . V_8 = V_69 ;
V_139 . V_4 = F_2 ( V_6 ) ;
V_139 . V_5 = V_5 ;
F_135 ( V_27 , V_61 , & V_139 , & V_27 -> V_153 , V_144 ) ;
}
static void F_137 ( struct V_26 * V_27 ,
struct V_122 * V_61 ,
const struct V_19 * V_69 ,
T_2 V_5 )
{
struct V_1 V_139 ;
struct V_143 * V_144 = V_61 ? & V_61 -> V_146 :
& V_27 -> V_146 ;
if ( F_91 ( V_69 ) )
return;
V_139 . V_7 . V_11 = * V_69 ;
V_139 . V_4 = F_2 ( V_10 ) ;
V_139 . V_5 = V_5 ;
F_135 ( V_27 , V_61 , & V_139 , & V_27 -> V_154 , V_144 ) ;
}
static int F_138 ( struct V_26 * V_27 ,
struct V_122 * V_61 ,
struct V_28 * V_29 )
{
struct V_28 * V_206 = V_29 ;
const struct V_74 * V_75 ;
struct V_70 * V_71 ;
unsigned int V_42 ;
unsigned int V_207 ;
int V_65 ;
T_3 V_5 = 0 ;
if ( ! F_116 ( V_29 , sizeof( * V_75 ) ) )
return - V_46 ;
V_75 = F_18 ( V_29 ) ;
if ( V_75 -> V_81 < 5 || V_75 -> V_80 != 4 )
return - V_46 ;
if ( ! F_116 ( V_29 , F_139 ( V_29 ) ) )
return - V_46 ;
V_75 = F_18 ( V_29 ) ;
if ( F_75 ( F_140 ( ( V_93 * ) V_75 , V_75 -> V_81 ) ) )
return - V_46 ;
if ( V_75 -> V_32 != V_88 ) {
if ( ! F_89 ( V_75 -> V_33 ) )
F_17 ( V_29 ) -> V_208 = 1 ;
return 0 ;
}
V_42 = F_119 ( V_75 -> V_83 ) ;
if ( V_29 -> V_42 < V_42 || V_42 < F_139 ( V_29 ) )
return - V_46 ;
if ( V_29 -> V_42 > V_42 ) {
V_206 = F_141 ( V_29 , V_66 ) ;
if ( ! V_206 )
return - V_67 ;
V_65 = F_142 ( V_206 , V_42 ) ;
if ( V_65 )
goto V_209;
}
V_42 -= F_139 ( V_206 ) ;
V_207 = F_143 ( V_206 ) + F_139 ( V_206 ) ;
F_61 ( V_206 , V_207 ) ;
F_144 ( V_206 ) ;
V_65 = - V_46 ;
if ( ! F_116 ( V_206 , sizeof( * V_71 ) ) )
goto V_53;
switch ( V_206 -> V_210 ) {
case V_211 :
if ( ! F_145 ( V_206 -> V_101 ) )
break;
case V_212 :
V_206 -> V_101 = 0 ;
if ( F_146 ( V_206 ) )
goto V_53;
}
V_65 = 0 ;
F_117 ( V_206 , & V_5 ) ;
F_17 ( V_29 ) -> V_31 = 1 ;
V_71 = F_59 ( V_206 ) ;
switch ( V_71 -> type ) {
case V_213 :
case V_214 :
F_17 ( V_29 ) -> V_208 = 1 ;
V_65 = F_88 ( V_27 , V_61 , V_71 -> V_69 , V_5 ) ;
break;
case V_215 :
V_65 = F_115 ( V_27 , V_61 , V_206 ) ;
break;
case V_95 :
V_65 = F_128 ( V_27 , V_61 , V_206 ) ;
break;
case V_216 :
F_136 ( V_27 , V_61 , V_71 -> V_69 , V_5 ) ;
break;
}
V_53:
F_100 ( V_206 , V_207 ) ;
V_209:
if ( V_206 != V_29 )
F_66 ( V_206 ) ;
return V_65 ;
}
static int F_147 ( struct V_26 * V_27 ,
struct V_122 * V_61 ,
struct V_28 * V_29 )
{
struct V_28 * V_206 ;
const struct V_102 * V_103 ;
V_93 V_217 ;
V_93 V_109 ;
T_5 V_85 ;
unsigned int V_42 ;
int V_207 ;
int V_65 ;
T_3 V_5 = 0 ;
if ( ! F_116 ( V_29 , sizeof( * V_103 ) ) )
return - V_46 ;
V_103 = F_19 ( V_29 ) ;
if ( V_103 -> V_80 != 6 )
return 0 ;
if ( ! F_91 ( & V_103 -> V_33 ) )
F_17 ( V_29 ) -> V_208 = 1 ;
if ( V_103 -> V_109 != V_110 ||
V_103 -> V_108 == 0 )
return 0 ;
V_42 = F_119 ( V_103 -> V_108 ) + sizeof( * V_103 ) ;
if ( V_29 -> V_42 < V_42 )
return - V_46 ;
V_109 = V_103 -> V_109 ;
V_207 = F_148 ( V_29 , sizeof( * V_103 ) , & V_109 , & V_85 ) ;
if ( V_207 < 0 || V_109 != V_112 )
return 0 ;
V_206 = F_141 ( V_29 , V_66 ) ;
if ( ! V_206 )
return - V_67 ;
V_65 = - V_46 ;
if ( ! F_116 ( V_206 , V_207 + sizeof( struct V_176 ) ) )
goto V_53;
V_42 -= V_207 - F_143 ( V_206 ) ;
F_61 ( V_206 , V_207 ) ;
F_144 ( V_206 ) ;
F_149 ( V_206 , F_150 ( V_206 ) ,
F_151 ( V_206 ) ) ;
V_217 = F_68 ( V_206 ) -> V_217 ;
switch ( V_217 ) {
case V_116 :
case V_218 :
case V_219 :
case V_220 :
break;
default:
V_65 = 0 ;
goto V_53;
}
if ( V_206 -> V_42 > V_42 ) {
V_65 = F_142 ( V_206 , V_42 ) ;
if ( V_65 )
goto V_53;
V_65 = - V_46 ;
}
V_103 = F_19 ( V_206 ) ;
switch ( V_206 -> V_210 ) {
case V_211 :
if ( ! F_71 ( & V_103 -> V_89 , & V_103 -> V_33 , V_206 -> V_42 ,
V_112 , V_206 -> V_101 ) )
break;
case V_212 :
V_206 -> V_101 = ~ F_152 ( F_71 ( & V_103 -> V_89 ,
& V_103 -> V_33 ,
V_206 -> V_42 ,
V_112 , 0 ) ) ;
if ( F_153 ( V_206 ) )
goto V_53;
}
V_65 = 0 ;
F_117 ( V_29 , & V_5 ) ;
F_17 ( V_29 ) -> V_31 = 1 ;
switch ( V_217 ) {
case V_218 :
{
struct V_104 * V_198 ;
if ( ! F_116 ( V_206 , sizeof( * V_198 ) ) ) {
V_65 = - V_46 ;
goto V_53;
}
V_198 = (struct V_104 * ) F_154 ( V_206 ) ;
F_17 ( V_29 ) -> V_208 = 1 ;
V_65 = F_90 ( V_27 , V_61 , & V_198 -> V_121 , V_5 ) ;
break;
}
case V_220 :
V_65 = F_120 ( V_27 , V_61 , V_206 ) ;
break;
case V_116 :
V_65 = F_132 ( V_27 , V_61 , V_206 ) ;
break;
case V_219 :
{
struct V_104 * V_198 ;
if ( ! F_116 ( V_206 , sizeof( * V_198 ) ) ) {
V_65 = - V_46 ;
goto V_53;
}
V_198 = (struct V_104 * ) F_154 ( V_206 ) ;
F_137 ( V_27 , V_61 , & V_198 -> V_121 , V_5 ) ;
}
}
V_53:
F_66 ( V_206 ) ;
return V_65 ;
}
int F_155 ( struct V_26 * V_27 , struct V_122 * V_61 ,
struct V_28 * V_29 )
{
F_17 ( V_29 ) -> V_31 = 0 ;
F_17 ( V_29 ) -> V_208 = 0 ;
if ( V_27 -> V_30 )
return 0 ;
switch ( V_29 -> V_32 ) {
case F_2 ( V_6 ) :
return F_138 ( V_27 , V_61 , V_29 ) ;
#if F_3 ( V_9 )
case F_2 ( V_10 ) :
return F_147 ( V_27 , V_61 , V_29 ) ;
#endif
}
return 0 ;
}
static void F_156 ( struct V_26 * V_27 ,
struct V_143 * V_144 )
{
F_29 ( & V_27 -> V_50 ) ;
if ( V_144 -> V_155 < V_27 -> V_156 )
V_144 -> V_155 ++ ;
F_103 ( V_27 , NULL , V_144 ) ;
F_35 ( & V_27 -> V_50 ) ;
}
static void F_157 ( unsigned long V_49 )
{
struct V_26 * V_27 = ( void * ) V_49 ;
F_156 ( V_27 , & V_27 -> V_145 ) ;
}
static void F_158 ( unsigned long V_49 )
{
struct V_26 * V_27 = ( void * ) V_49 ;
F_156 ( V_27 , & V_27 -> V_146 ) ;
}
void F_159 ( struct V_26 * V_27 )
{
V_27 -> V_124 = 4 ;
V_27 -> V_126 = 512 ;
V_27 -> V_140 = 1 ;
V_27 -> V_152 = 0 ;
V_27 -> V_90 = 0 ;
V_27 -> V_196 = 2 ;
V_27 -> V_156 = 2 ;
V_27 -> V_97 = V_99 ;
V_27 -> V_98 = 10 * V_99 ;
V_27 -> V_157 = 125 * V_99 / 4 ;
V_27 -> V_158 = 125 * V_99 ;
V_27 -> V_191 = 255 * V_99 ;
V_27 -> V_135 = 260 * V_99 ;
V_27 -> V_153 . V_190 = 0 ;
#if F_3 ( V_9 )
V_27 -> V_154 . V_190 = 0 ;
#endif
F_160 ( & V_27 -> V_50 ) ;
F_82 ( & V_27 -> V_141 ,
F_94 , 0 ) ;
F_82 ( & V_27 -> V_153 . V_52 , F_97 ,
( unsigned long ) V_27 ) ;
F_82 ( & V_27 -> V_145 . V_52 , F_157 ,
( unsigned long ) V_27 ) ;
#if F_3 ( V_9 )
F_82 ( & V_27 -> V_154 . V_52 , F_98 ,
( unsigned long ) V_27 ) ;
F_82 ( & V_27 -> V_146 . V_52 , F_158 ,
( unsigned long ) V_27 ) ;
#endif
}
static void F_161 ( struct V_26 * V_27 ,
struct V_143 * V_144 )
{
V_144 -> V_155 = 0 ;
if ( V_27 -> V_30 )
return;
F_41 ( & V_144 -> V_52 , V_60 ) ;
}
void F_162 ( struct V_26 * V_27 )
{
F_161 ( V_27 , & V_27 -> V_145 ) ;
#if F_3 ( V_9 )
F_161 ( V_27 , & V_27 -> V_146 ) ;
#endif
}
void F_163 ( struct V_26 * V_27 )
{
struct V_12 * V_13 ;
struct V_20 * V_23 ;
struct V_160 * V_161 ;
V_16 V_45 ;
int V_43 ;
F_109 ( & V_27 -> V_141 ) ;
F_109 ( & V_27 -> V_153 . V_52 ) ;
F_109 ( & V_27 -> V_145 . V_52 ) ;
#if F_3 ( V_9 )
F_109 ( & V_27 -> V_154 . V_52 ) ;
F_109 ( & V_27 -> V_146 . V_52 ) ;
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
int F_167 ( struct V_26 * V_27 , unsigned long V_221 )
{
int V_65 = - V_222 ;
F_164 ( & V_27 -> V_50 ) ;
if ( ! F_30 ( V_27 -> V_51 ) )
goto V_223;
switch ( V_221 ) {
case 0 :
case 2 :
F_40 ( & V_27 -> V_141 ) ;
case 1 :
V_27 -> V_140 = V_221 ;
V_65 = 0 ;
break;
default:
V_65 = - V_46 ;
break;
}
V_223:
F_165 ( & V_27 -> V_50 ) ;
return V_65 ;
}
int F_168 ( struct V_122 * V_48 , unsigned long V_221 )
{
struct V_26 * V_27 = V_48 -> V_27 ;
int V_65 = - V_222 ;
F_29 ( & V_27 -> V_50 ) ;
if ( ! F_30 ( V_27 -> V_51 ) || V_48 -> V_62 == V_134 )
goto V_223;
switch ( V_221 ) {
case 0 :
case 1 :
case 2 :
V_48 -> V_140 = V_221 ;
V_65 = 0 ;
if ( V_221 < 2 && ! F_43 ( & V_48 -> V_142 ) )
F_93 ( & V_48 -> V_142 ) ;
if ( V_221 == 1 )
break;
F_40 ( & V_48 -> V_141 ) ;
if ( V_221 == 0 )
break;
F_124 ( V_27 , V_48 ) ;
break;
default:
V_65 = - V_46 ;
break;
}
V_223:
F_35 ( & V_27 -> V_50 ) ;
return V_65 ;
}
static void F_96 ( struct V_26 * V_27 ,
struct V_143 * V_144 )
{
struct V_122 * V_61 ;
F_161 ( V_27 , V_144 ) ;
F_169 (port, &br->port_list, list) {
if ( V_61 -> V_62 == V_134 ||
V_61 -> V_62 == V_159 )
continue;
if ( V_144 == & V_27 -> V_145 )
F_110 ( & V_61 -> V_145 ) ;
#if F_3 ( V_9 )
else
F_110 ( & V_61 -> V_146 ) ;
#endif
}
}
int F_170 ( struct V_26 * V_27 , unsigned long V_221 )
{
int V_65 = 0 ;
struct V_12 * V_13 ;
F_164 ( & V_27 -> V_50 ) ;
if ( V_27 -> V_30 == ! V_221 )
goto V_223;
V_27 -> V_30 = ! V_221 ;
if ( V_27 -> V_30 )
goto V_223;
if ( ! F_30 ( V_27 -> V_51 ) )
goto V_223;
V_13 = F_32 ( V_27 -> V_13 , V_27 ) ;
if ( V_13 ) {
if ( V_13 -> V_37 ) {
V_65 = - V_129 ;
V_224:
V_27 -> V_30 = ! ! V_221 ;
goto V_223;
}
V_65 = F_44 ( & V_27 -> V_13 , V_13 -> V_18 ,
V_27 -> V_124 ) ;
if ( V_65 )
goto V_224;
}
F_96 ( V_27 , & V_27 -> V_145 ) ;
#if F_3 ( V_9 )
F_96 ( V_27 , & V_27 -> V_146 ) ;
#endif
V_223:
F_165 ( & V_27 -> V_50 ) ;
return V_65 ;
}
int F_171 ( struct V_26 * V_27 , unsigned long V_221 )
{
unsigned long V_189 ;
V_221 = ! ! V_221 ;
F_164 ( & V_27 -> V_50 ) ;
if ( V_27 -> V_152 == V_221 )
goto V_223;
V_27 -> V_152 = V_221 ;
if ( ! V_221 )
goto V_223;
V_189 = V_27 -> V_98 ;
if ( ! F_31 ( & V_27 -> V_153 . V_52 ) )
V_27 -> V_153 . V_190 = V_60 + V_189 ;
F_96 ( V_27 , & V_27 -> V_145 ) ;
#if F_3 ( V_9 )
if ( ! F_31 ( & V_27 -> V_154 . V_52 ) )
V_27 -> V_154 . V_190 = V_60 + V_189 ;
F_96 ( V_27 , & V_27 -> V_146 ) ;
#endif
V_223:
F_165 ( & V_27 -> V_50 ) ;
return 0 ;
}
int F_172 ( struct V_26 * V_27 , unsigned long V_221 )
{
int V_65 = - V_222 ;
V_16 V_37 ;
struct V_12 * V_13 ;
F_29 ( & V_27 -> V_50 ) ;
if ( ! F_30 ( V_27 -> V_51 ) )
goto V_223;
V_65 = - V_46 ;
if ( ! F_173 ( V_221 ) )
goto V_223;
V_13 = F_32 ( V_27 -> V_13 , V_27 ) ;
if ( V_13 && V_221 < V_13 -> V_56 )
goto V_223;
V_65 = 0 ;
V_37 = V_27 -> V_126 ;
V_27 -> V_126 = V_221 ;
if ( V_13 ) {
if ( V_13 -> V_37 ) {
V_65 = - V_129 ;
V_224:
V_27 -> V_126 = V_37 ;
goto V_223;
}
V_65 = F_44 ( & V_27 -> V_13 , V_27 -> V_126 ,
V_27 -> V_124 ) ;
if ( V_65 )
goto V_224;
}
V_223:
F_35 ( & V_27 -> V_50 ) ;
return V_65 ;
}
