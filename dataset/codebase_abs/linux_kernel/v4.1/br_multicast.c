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
F_53 ( V_73 -> V_76 , V_27 -> V_51 -> V_77 ) ;
V_73 -> V_78 [ 0 ] = 1 ;
V_73 -> V_78 [ 1 ] = 0 ;
V_73 -> V_78 [ 2 ] = 0x5e ;
V_73 -> V_78 [ 3 ] = 0 ;
V_73 -> V_78 [ 4 ] = 0 ;
V_73 -> V_78 [ 5 ] = 1 ;
V_73 -> V_79 = F_2 ( V_6 ) ;
F_54 ( V_29 , sizeof( * V_73 ) ) ;
F_55 ( V_29 , V_29 -> V_42 ) ;
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
F_56 ( V_27 -> V_51 , 0 , V_91 ) : 0 ;
V_75 -> V_33 = F_57 ( V_92 ) ;
( ( V_93 * ) & V_75 [ 1 ] ) [ 0 ] = V_94 ;
( ( V_93 * ) & V_75 [ 1 ] ) [ 1 ] = 4 ;
( ( V_93 * ) & V_75 [ 1 ] ) [ 2 ] = 0 ;
( ( V_93 * ) & V_75 [ 1 ] ) [ 3 ] = 0 ;
F_58 ( V_75 ) ;
F_54 ( V_29 , 24 ) ;
F_59 ( V_29 , V_29 -> V_42 ) ;
V_71 = F_60 ( V_29 ) ;
V_71 -> type = V_95 ;
V_71 -> V_96 = ( V_69 ? V_27 -> V_97 :
V_27 -> V_98 ) /
( V_99 / V_100 ) ;
V_71 -> V_69 = V_69 ;
V_71 -> V_101 = 0 ;
V_71 -> V_101 = F_61 ( ( void * ) V_71 , sizeof( struct V_70 ) ) ;
F_54 ( V_29 , sizeof( * V_71 ) ) ;
F_62 ( V_29 , sizeof( * V_73 ) ) ;
V_53:
return V_29 ;
}
static struct V_28 * F_63 ( struct V_26 * V_27 ,
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
F_53 ( V_73 -> V_76 , V_27 -> V_51 -> V_77 ) ;
V_73 -> V_79 = F_2 ( V_10 ) ;
F_54 ( V_29 , sizeof( * V_73 ) ) ;
F_55 ( V_29 , V_29 -> V_42 ) ;
V_103 = F_19 ( V_29 ) ;
* ( V_15 T_1 * ) V_103 = F_57 ( 0x60000000 ) ;
V_103 -> V_108 = F_2 ( 8 + sizeof( * V_105 ) ) ;
V_103 -> V_109 = V_110 ;
V_103 -> V_111 = 1 ;
F_64 ( & V_103 -> V_33 , F_57 ( 0xff020000 ) , 0 , 0 , F_57 ( 1 ) ) ;
if ( F_65 ( F_66 ( V_27 -> V_51 ) , V_27 -> V_51 , & V_103 -> V_33 , 0 ,
& V_103 -> V_89 ) ) {
F_67 ( V_29 ) ;
return NULL ;
}
F_68 ( & V_103 -> V_33 , V_73 -> V_78 ) ;
V_106 = ( V_93 * ) ( V_103 + 1 ) ;
V_106 [ 0 ] = V_112 ;
V_106 [ 1 ] = 0 ;
V_106 [ 2 ] = V_113 ;
V_106 [ 3 ] = 2 ;
V_106 [ 4 ] = 0 ;
V_106 [ 5 ] = 0 ;
V_106 [ 6 ] = V_114 ;
V_106 [ 7 ] = V_114 ;
F_54 ( V_29 , sizeof( * V_103 ) + 8 ) ;
F_59 ( V_29 , V_29 -> V_42 ) ;
V_105 = (struct V_104 * ) F_69 ( V_29 ) ;
V_107 = F_70 ( V_69 ) ?
V_27 -> V_98 :
V_27 -> V_97 ;
V_105 -> V_115 = V_116 ;
V_105 -> V_117 = 0 ;
V_105 -> V_118 = 0 ;
V_105 -> V_119 = F_2 ( ( T_3 ) F_71 ( V_107 ) ) ;
V_105 -> V_120 = 0 ;
V_105 -> V_121 = * V_69 ;
V_105 -> V_118 = F_72 ( & V_103 -> V_89 , & V_103 -> V_33 ,
sizeof( * V_105 ) , V_112 ,
F_73 ( V_105 ,
sizeof( * V_105 ) , 0 ) ) ;
F_54 ( V_29 , sizeof( * V_105 ) ) ;
F_62 ( V_29 , sizeof( * V_73 ) ) ;
V_53:
return V_29 ;
}
static struct V_28 * F_74 ( struct V_26 * V_27 ,
struct V_1 * V_24 )
{
switch ( V_24 -> V_4 ) {
case F_2 ( V_6 ) :
return F_49 ( V_27 , V_24 -> V_7 . V_8 ) ;
#if F_3 ( V_9 )
case F_2 ( V_10 ) :
return F_63 ( V_27 , & V_24 -> V_7 . V_11 ) ;
#endif
}
return NULL ;
}
static struct V_20 * F_75 (
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
if ( F_76 ( F_1 ( V_69 , & V_23 -> V_24 ) ) )
return V_23 ;
}
V_40 = 0 ;
V_18 = V_13 -> V_18 ;
if ( F_76 ( V_123 > V_27 -> V_124 && V_123 ) ) {
if ( F_77 () )
F_78 ( V_27 , L_1
L_2 ,
V_61 ? V_61 -> V_51 -> V_125 : V_27 -> V_51 -> V_125 ) ;
V_40 = V_27 -> V_124 ;
}
if ( V_13 -> V_56 >= V_18 ) {
V_18 *= 2 ;
if ( F_76 ( V_18 > V_27 -> V_126 ) ) {
F_79 ( V_27 , L_3
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
if ( F_77 () )
F_78 ( V_27 , L_1
L_5 ,
V_61 ? V_61 -> V_51 -> V_125 : V_27 -> V_51 -> V_125 ) ;
V_65 = - V_129 ;
goto V_65;
}
V_65 = F_44 ( & V_27 -> V_13 , V_18 , V_40 ) ;
if ( V_65 ) {
F_79 ( V_27 , L_6
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
V_23 = F_80 ( V_65 ) ;
return V_23 ;
}
struct V_20 * F_81 ( struct V_26 * V_27 ,
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
return F_80 ( V_65 ) ;
goto V_132;
}
V_22 = F_9 ( V_13 , V_69 ) ;
V_23 = F_75 ( V_27 , V_61 , V_69 , V_22 ) ;
switch ( F_82 ( V_23 ) ) {
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
if ( F_76 ( ! V_23 ) )
return F_80 ( - V_67 ) ;
V_23 -> V_27 = V_27 ;
V_23 -> V_24 = * V_69 ;
F_83 ( & V_23 -> V_52 , F_28 ,
( unsigned long ) V_23 ) ;
F_84 ( & V_23 -> V_44 [ V_13 -> V_45 ] , & V_13 -> V_38 [ V_22 ] ) ;
V_13 -> V_56 ++ ;
V_53:
return V_23 ;
}
struct V_47 * F_85 (
struct V_122 * V_61 ,
struct V_1 * V_69 ,
struct V_47 T_4 * V_59 ,
unsigned char V_62 )
{
struct V_47 * V_48 ;
V_48 = F_47 ( sizeof( * V_48 ) , V_66 ) ;
if ( F_76 ( ! V_48 ) )
return NULL ;
V_48 -> V_24 = * V_69 ;
V_48 -> V_61 = V_61 ;
V_48 -> V_62 = V_62 ;
F_38 ( V_48 -> V_59 , V_59 ) ;
F_25 ( & V_48 -> V_54 , & V_61 -> V_54 ) ;
F_83 ( & V_48 -> V_52 , F_42 ,
( unsigned long ) V_48 ) ;
return V_48 ;
}
static int F_86 ( struct V_26 * V_27 ,
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
V_23 = F_81 ( V_27 , V_61 , V_69 ) ;
V_65 = F_82 ( V_23 ) ;
if ( F_87 ( V_23 ) )
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
V_48 = F_85 ( V_61 , V_69 , * V_58 , V_137 ) ;
if ( F_76 ( ! V_48 ) )
goto V_65;
F_38 ( * V_58 , V_48 ) ;
F_88 ( V_27 -> V_51 , V_61 , V_69 , V_138 ) ;
V_136:
F_41 ( & V_48 -> V_52 , V_133 + V_27 -> V_135 ) ;
V_53:
V_65 = 0 ;
V_65:
F_35 ( & V_27 -> V_50 ) ;
return V_65 ;
}
static int F_89 ( struct V_26 * V_27 ,
struct V_122 * V_61 ,
T_1 V_69 ,
T_2 V_5 )
{
struct V_1 V_139 ;
if ( F_90 ( V_69 ) )
return 0 ;
V_139 . V_7 . V_8 = V_69 ;
V_139 . V_4 = F_2 ( V_6 ) ;
V_139 . V_5 = V_5 ;
return F_86 ( V_27 , V_61 , & V_139 ) ;
}
static int F_91 ( struct V_26 * V_27 ,
struct V_122 * V_61 ,
const struct V_19 * V_69 ,
T_2 V_5 )
{
struct V_1 V_139 ;
if ( F_92 ( V_69 ) )
return 0 ;
V_139 . V_7 . V_11 = * V_69 ;
V_139 . V_4 = F_2 ( V_10 ) ;
V_139 . V_5 = V_5 ;
return F_86 ( V_27 , V_61 , & V_139 ) ;
}
static void F_93 ( unsigned long V_49 )
{
struct V_122 * V_61 = ( void * ) V_49 ;
struct V_26 * V_27 = V_61 -> V_27 ;
F_29 ( & V_27 -> V_50 ) ;
if ( V_61 -> V_140 != 1 ||
F_31 ( & V_61 -> V_141 ) ||
F_43 ( & V_61 -> V_142 ) )
goto V_53;
F_94 ( & V_61 -> V_142 ) ;
V_53:
F_35 ( & V_27 -> V_50 ) ;
}
static void F_95 ( unsigned long V_49 )
{
}
static void F_96 ( struct V_26 * V_27 ,
struct V_143 * V_144 )
{
F_29 ( & V_27 -> V_50 ) ;
if ( ! F_30 ( V_27 -> V_51 ) || V_27 -> V_30 )
goto V_53;
F_97 ( V_27 , V_144 ) ;
V_53:
F_35 ( & V_27 -> V_50 ) ;
}
static void F_98 ( unsigned long V_49 )
{
struct V_26 * V_27 = ( void * ) V_49 ;
F_96 ( V_27 , & V_27 -> V_145 ) ;
}
static void F_99 ( unsigned long V_49 )
{
struct V_26 * V_27 = ( void * ) V_49 ;
F_96 ( V_27 , & V_27 -> V_146 ) ;
}
static void F_100 ( struct V_26 * V_27 ,
struct V_1 * V_14 ,
struct V_28 * V_29 )
{
if ( V_14 -> V_4 == F_2 ( V_6 ) )
V_27 -> V_147 . V_24 . V_7 . V_8 = F_18 ( V_29 ) -> V_89 ;
#if F_3 ( V_9 )
else
V_27 -> V_148 . V_24 . V_7 . V_11 = F_19 ( V_29 ) -> V_89 ;
#endif
}
static void F_101 ( struct V_26 * V_27 ,
struct V_122 * V_61 ,
struct V_1 * V_14 )
{
struct V_28 * V_29 ;
V_29 = F_74 ( V_27 , V_14 ) ;
if ( ! V_29 )
return;
if ( V_61 ) {
V_29 -> V_51 = V_61 -> V_51 ;
F_102 ( V_149 , V_150 , NULL , V_29 ,
NULL , V_29 -> V_51 ,
V_151 ) ;
} else {
F_100 ( V_27 , V_14 , V_29 ) ;
F_103 ( V_29 ) ;
}
}
static void F_104 ( struct V_26 * V_27 ,
struct V_122 * V_61 ,
struct V_143 * V_152 )
{
unsigned long time ;
struct V_1 V_139 ;
struct V_153 * V_154 = NULL ;
if ( ! F_30 ( V_27 -> V_51 ) || V_27 -> V_30 ||
! V_27 -> V_155 )
return;
memset ( & V_139 . V_7 , 0 , sizeof( V_139 . V_7 ) ) ;
if ( V_61 ? ( V_152 == & V_61 -> V_145 ) :
( V_152 == & V_27 -> V_145 ) ) {
V_154 = & V_27 -> V_156 ;
V_139 . V_4 = F_2 ( V_6 ) ;
#if F_3 ( V_9 )
} else {
V_154 = & V_27 -> V_157 ;
V_139 . V_4 = F_2 ( V_10 ) ;
#endif
}
if ( ! V_154 || F_31 ( & V_154 -> V_52 ) )
return;
F_101 ( V_27 , V_61 , & V_139 ) ;
time = V_60 ;
time += V_152 -> V_158 < V_27 -> V_159 ?
V_27 -> V_160 :
V_27 -> V_161 ;
F_41 ( & V_152 -> V_52 , time ) ;
}
static void
F_105 ( struct V_122 * V_61 ,
struct V_143 * V_144 )
{
struct V_26 * V_27 = V_61 -> V_27 ;
F_29 ( & V_27 -> V_50 ) ;
if ( V_61 -> V_62 == V_134 ||
V_61 -> V_62 == V_162 )
goto V_53;
if ( V_144 -> V_158 < V_27 -> V_159 )
V_144 -> V_158 ++ ;
F_104 ( V_61 -> V_27 , V_61 , V_144 ) ;
V_53:
F_35 ( & V_27 -> V_50 ) ;
}
static void F_106 ( unsigned long V_49 )
{
struct V_122 * V_61 = ( void * ) V_49 ;
F_105 ( V_61 , & V_61 -> V_145 ) ;
}
static void F_107 ( unsigned long V_49 )
{
struct V_122 * V_61 = ( void * ) V_49 ;
F_105 ( V_61 , & V_61 -> V_146 ) ;
}
void F_108 ( struct V_122 * V_61 )
{
V_61 -> V_140 = 1 ;
F_83 ( & V_61 -> V_141 , F_93 ,
( unsigned long ) V_61 ) ;
F_83 ( & V_61 -> V_145 . V_52 ,
F_106 , ( unsigned long ) V_61 ) ;
#if F_3 ( V_9 )
F_83 ( & V_61 -> V_146 . V_52 ,
F_107 , ( unsigned long ) V_61 ) ;
#endif
}
void F_109 ( struct V_122 * V_61 )
{
F_110 ( & V_61 -> V_141 ) ;
}
static void F_111 ( struct V_143 * V_144 )
{
V_144 -> V_158 = 0 ;
if ( F_112 ( & V_144 -> V_52 ) >= 0 ||
F_40 ( & V_144 -> V_52 ) )
F_41 ( & V_144 -> V_52 , V_60 ) ;
}
void F_113 ( struct V_122 * V_61 )
{
struct V_26 * V_27 = V_61 -> V_27 ;
F_29 ( & V_27 -> V_50 ) ;
if ( V_27 -> V_30 || ! F_30 ( V_27 -> V_51 ) )
goto V_53;
F_111 ( & V_61 -> V_145 ) ;
#if F_3 ( V_9 )
F_111 ( & V_61 -> V_146 ) ;
#endif
V_53:
F_35 ( & V_27 -> V_50 ) ;
}
void F_114 ( struct V_122 * V_61 )
{
struct V_26 * V_27 = V_61 -> V_27 ;
struct V_47 * V_57 ;
struct V_163 * V_164 ;
F_29 ( & V_27 -> V_50 ) ;
F_115 (pg, n, &port->mglist, mglist)
F_36 ( V_27 , V_57 ) ;
if ( ! F_43 ( & V_61 -> V_142 ) )
F_94 ( & V_61 -> V_142 ) ;
F_40 ( & V_61 -> V_141 ) ;
F_40 ( & V_61 -> V_145 . V_52 ) ;
#if F_3 ( V_9 )
F_40 ( & V_61 -> V_146 . V_52 ) ;
#endif
F_35 ( & V_27 -> V_50 ) ;
}
static int F_116 ( struct V_26 * V_27 ,
struct V_122 * V_61 ,
struct V_28 * V_29 ,
T_3 V_5 )
{
struct V_165 * V_71 ;
struct V_166 * V_167 ;
int V_43 ;
int V_42 ;
int V_168 ;
int type ;
int V_65 = 0 ;
T_1 V_69 ;
if ( ! F_117 ( V_29 , sizeof( * V_71 ) ) )
return - V_46 ;
V_71 = F_118 ( V_29 ) ;
V_168 = F_119 ( V_71 -> V_169 ) ;
V_42 = sizeof( * V_71 ) ;
for ( V_43 = 0 ; V_43 < V_168 ; V_43 ++ ) {
V_42 += sizeof( * V_167 ) ;
if ( ! F_117 ( V_29 , V_42 ) )
return - V_46 ;
V_167 = ( void * ) ( V_29 -> V_49 + V_42 - sizeof( * V_167 ) ) ;
V_69 = V_167 -> V_170 ;
type = V_167 -> V_171 ;
V_42 += F_119 ( V_167 -> V_172 ) * 4 ;
if ( ! F_117 ( V_29 , V_42 ) )
return - V_46 ;
switch ( type ) {
case V_173 :
case V_174 :
case V_175 :
case V_176 :
case V_177 :
case V_178 :
break;
default:
continue;
}
V_65 = F_89 ( V_27 , V_61 , V_69 , V_5 ) ;
if ( V_65 )
break;
}
return V_65 ;
}
static int F_120 ( struct V_26 * V_27 ,
struct V_122 * V_61 ,
struct V_28 * V_29 ,
T_3 V_5 )
{
struct V_179 * V_180 ;
struct V_181 * V_167 ;
int V_43 ;
int V_42 ;
int V_168 ;
int V_65 = 0 ;
if ( ! F_117 ( V_29 , sizeof( * V_180 ) ) )
return - V_46 ;
V_180 = F_69 ( V_29 ) ;
V_168 = F_119 ( V_180 -> V_182 . V_183 [ 1 ] ) ;
V_42 = sizeof( * V_180 ) ;
for ( V_43 = 0 ; V_43 < V_168 ; V_43 ++ ) {
T_5 * V_184 , V_185 ;
V_184 = F_121 ( V_29 ,
V_42 + F_122 ( struct V_181 ,
V_172 ) ,
sizeof( V_185 ) , & V_185 ) ;
if ( ! V_184 )
return - V_46 ;
if ( ! F_117 ( V_29 ,
V_42 + sizeof( * V_167 ) +
sizeof( struct V_19 ) * F_119 ( * V_184 ) ) )
return - V_46 ;
V_167 = (struct V_181 * ) ( V_29 -> V_49 + V_42 ) ;
V_42 += sizeof( * V_167 ) +
sizeof( struct V_19 ) * F_119 ( * V_184 ) ;
switch ( V_167 -> V_171 ) {
case V_186 :
case V_187 :
case V_188 :
case V_189 :
case V_190 :
case V_191 :
break;
default:
continue;
}
V_65 = F_91 ( V_27 , V_61 , & V_167 -> V_170 ,
V_5 ) ;
if ( V_65 )
break;
}
return V_65 ;
}
static bool F_123 ( struct V_26 * V_27 ,
struct V_122 * V_61 ,
T_1 V_89 )
{
if ( ! F_31 ( & V_27 -> V_145 . V_52 ) &&
! F_31 ( & V_27 -> V_156 . V_52 ) )
goto V_192;
if ( ! V_27 -> V_147 . V_24 . V_7 . V_8 )
goto V_192;
if ( F_124 ( V_89 ) <= F_124 ( V_27 -> V_147 . V_24 . V_7 . V_8 ) )
goto V_192;
return false ;
V_192:
V_27 -> V_147 . V_24 . V_7 . V_8 = V_89 ;
F_38 ( V_27 -> V_147 . V_61 , V_61 ) ;
return true ;
}
static bool F_125 ( struct V_26 * V_27 ,
struct V_122 * V_61 ,
struct V_19 * V_89 )
{
if ( ! F_31 ( & V_27 -> V_146 . V_52 ) &&
! F_31 ( & V_27 -> V_157 . V_52 ) )
goto V_192;
if ( F_126 ( V_89 , & V_27 -> V_148 . V_24 . V_7 . V_11 ) <= 0 )
goto V_192;
return false ;
V_192:
V_27 -> V_148 . V_24 . V_7 . V_11 = * V_89 ;
F_38 ( V_27 -> V_148 . V_61 , V_61 ) ;
return true ;
}
static bool F_127 ( struct V_26 * V_27 ,
struct V_122 * V_61 ,
struct V_1 * V_89 )
{
switch ( V_89 -> V_4 ) {
case F_2 ( V_6 ) :
return F_123 ( V_27 , V_61 , V_89 -> V_7 . V_8 ) ;
#if F_3 ( V_9 )
case F_2 ( V_10 ) :
return F_125 ( V_27 , V_61 , & V_89 -> V_7 . V_11 ) ;
#endif
}
return false ;
}
static void
F_128 ( struct V_26 * V_27 ,
struct V_153 * V_144 ,
unsigned long V_193 )
{
if ( ! F_31 ( & V_144 -> V_52 ) )
V_144 -> V_194 = V_60 + V_193 ;
F_41 ( & V_144 -> V_52 , V_60 + V_27 -> V_195 ) ;
}
static void F_129 ( struct V_26 * V_27 ,
struct V_122 * V_61 )
{
struct V_122 * V_48 ;
struct V_163 * V_196 = NULL ;
if ( ! F_43 ( & V_61 -> V_142 ) )
return;
F_24 (p, &br->router_list, rlist) {
if ( ( unsigned long ) V_61 >= ( unsigned long ) V_48 )
break;
V_196 = & V_48 -> V_142 ;
}
if ( V_196 )
F_130 ( & V_61 -> V_142 , V_196 ) ;
else
F_84 ( & V_61 -> V_142 , & V_27 -> V_197 ) ;
}
static void F_131 ( struct V_26 * V_27 ,
struct V_122 * V_61 )
{
unsigned long V_133 = V_60 ;
if ( ! V_61 ) {
if ( V_27 -> V_140 == 1 )
F_41 ( & V_27 -> V_141 ,
V_133 + V_27 -> V_195 ) ;
return;
}
if ( V_61 -> V_140 != 1 )
return;
F_129 ( V_27 , V_61 ) ;
F_41 ( & V_61 -> V_141 ,
V_133 + V_27 -> V_195 ) ;
}
static void F_132 ( struct V_26 * V_27 ,
struct V_122 * V_61 ,
struct V_153 * V_144 ,
struct V_1 * V_89 ,
unsigned long V_193 )
{
if ( ! F_127 ( V_27 , V_61 , V_89 ) )
return;
F_128 ( V_27 , V_144 , V_193 ) ;
F_131 ( V_27 , V_61 ) ;
}
static int F_133 ( struct V_26 * V_27 ,
struct V_122 * V_61 ,
struct V_28 * V_29 ,
T_3 V_5 )
{
const struct V_74 * V_75 = F_18 ( V_29 ) ;
struct V_70 * V_71 = F_60 ( V_29 ) ;
struct V_20 * V_23 ;
struct V_198 * V_199 ;
struct V_47 * V_48 ;
struct V_47 T_4 * * V_58 ;
struct V_1 V_89 ;
unsigned long V_193 ;
unsigned long V_133 = V_60 ;
T_1 V_69 ;
int V_65 = 0 ;
F_29 ( & V_27 -> V_50 ) ;
if ( ! F_30 ( V_27 -> V_51 ) ||
( V_61 && V_61 -> V_62 == V_134 ) )
goto V_53;
V_69 = V_71 -> V_69 ;
if ( V_29 -> V_42 == sizeof( * V_71 ) ) {
V_193 = V_71 -> V_96 * ( V_99 / V_100 ) ;
if ( ! V_193 ) {
V_193 = 10 * V_99 ;
V_69 = 0 ;
}
} else {
if ( ! F_117 ( V_29 , sizeof( struct V_198 ) ) ) {
V_65 = - V_46 ;
goto V_53;
}
V_199 = F_134 ( V_29 ) ;
if ( V_199 -> V_184 )
goto V_53;
V_193 = V_199 -> V_96 ?
F_135 ( V_199 -> V_96 ) * ( V_99 / V_100 ) : 1 ;
}
if ( ! V_69 && V_75 -> V_33 != F_57 ( V_92 ) ) {
V_65 = - V_46 ;
goto V_53;
}
if ( ! V_69 ) {
V_89 . V_4 = F_2 ( V_6 ) ;
V_89 . V_7 . V_8 = V_75 -> V_89 ;
F_132 ( V_27 , V_61 , & V_27 -> V_156 ,
& V_89 , V_193 ) ;
goto V_53;
}
V_23 = F_13 ( F_32 ( V_27 -> V_13 , V_27 ) , V_69 , V_5 ) ;
if ( ! V_23 )
goto V_53;
V_193 *= V_27 -> V_200 ;
if ( V_23 -> V_54 &&
( F_31 ( & V_23 -> V_52 ) ?
F_136 ( V_23 -> V_52 . V_201 , V_133 + V_193 ) :
F_112 ( & V_23 -> V_52 ) >= 0 ) )
F_41 ( & V_23 -> V_52 , V_133 + V_193 ) ;
for ( V_58 = & V_23 -> V_55 ;
( V_48 = F_32 ( * V_58 , V_27 ) ) != NULL ;
V_58 = & V_48 -> V_59 ) {
if ( F_31 ( & V_48 -> V_52 ) ?
F_136 ( V_48 -> V_52 . V_201 , V_133 + V_193 ) :
F_112 ( & V_48 -> V_52 ) >= 0 )
F_41 ( & V_48 -> V_52 , V_133 + V_193 ) ;
}
V_53:
F_35 ( & V_27 -> V_50 ) ;
return V_65 ;
}
static int F_137 ( struct V_26 * V_27 ,
struct V_122 * V_61 ,
struct V_28 * V_29 ,
T_3 V_5 )
{
const struct V_102 * V_103 = F_19 ( V_29 ) ;
struct V_104 * V_202 ;
struct V_20 * V_23 ;
struct V_203 * V_204 ;
struct V_47 * V_48 ;
struct V_47 T_4 * * V_58 ;
struct V_1 V_89 ;
unsigned long V_193 ;
unsigned long V_133 = V_60 ;
const struct V_19 * V_69 = NULL ;
bool V_205 ;
int V_65 = 0 ;
F_29 ( & V_27 -> V_50 ) ;
if ( ! F_30 ( V_27 -> V_51 ) ||
( V_61 && V_61 -> V_62 == V_134 ) )
goto V_53;
if ( ! ( F_138 ( & V_103 -> V_89 ) & V_206 ) ) {
V_65 = - V_46 ;
goto V_53;
}
if ( V_29 -> V_42 == sizeof( * V_202 ) ) {
if ( ! F_117 ( V_29 , sizeof( * V_202 ) ) ) {
V_65 = - V_46 ;
goto V_53;
}
V_202 = (struct V_104 * ) F_69 ( V_29 ) ;
V_193 = F_139 ( F_119 ( V_202 -> V_119 ) ) ;
if ( V_193 )
V_69 = & V_202 -> V_121 ;
} else {
if ( ! F_117 ( V_29 , sizeof( * V_204 ) ) ) {
V_65 = - V_46 ;
goto V_53;
}
V_204 = (struct V_203 * ) F_69 ( V_29 ) ;
if ( ! V_204 -> V_207 )
V_69 = & V_204 -> V_208 ;
V_193 = V_18 ( F_139 ( F_140 ( V_204 ) ) , 1UL ) ;
}
V_205 = V_69 && F_70 ( V_69 ) ;
if ( V_205 && ! F_92 ( & V_103 -> V_33 ) ) {
V_65 = - V_46 ;
goto V_53;
}
if ( V_205 ) {
V_89 . V_4 = F_2 ( V_10 ) ;
V_89 . V_7 . V_11 = V_103 -> V_89 ;
F_132 ( V_27 , V_61 , & V_27 -> V_157 ,
& V_89 , V_193 ) ;
goto V_53;
} else if ( ! V_69 ) {
goto V_53;
}
V_23 = F_14 ( F_32 ( V_27 -> V_13 , V_27 ) , V_69 , V_5 ) ;
if ( ! V_23 )
goto V_53;
V_193 *= V_27 -> V_200 ;
if ( V_23 -> V_54 &&
( F_31 ( & V_23 -> V_52 ) ?
F_136 ( V_23 -> V_52 . V_201 , V_133 + V_193 ) :
F_112 ( & V_23 -> V_52 ) >= 0 ) )
F_41 ( & V_23 -> V_52 , V_133 + V_193 ) ;
for ( V_58 = & V_23 -> V_55 ;
( V_48 = F_32 ( * V_58 , V_27 ) ) != NULL ;
V_58 = & V_48 -> V_59 ) {
if ( F_31 ( & V_48 -> V_52 ) ?
F_136 ( V_48 -> V_52 . V_201 , V_133 + V_193 ) :
F_112 ( & V_48 -> V_52 ) >= 0 )
F_41 ( & V_48 -> V_52 , V_133 + V_193 ) ;
}
V_53:
F_35 ( & V_27 -> V_50 ) ;
return V_65 ;
}
static void
F_141 ( struct V_26 * V_27 ,
struct V_122 * V_61 ,
struct V_1 * V_69 ,
struct V_153 * V_154 ,
struct V_143 * V_152 )
{
struct V_12 * V_13 ;
struct V_20 * V_23 ;
struct V_47 * V_48 ;
unsigned long V_133 ;
unsigned long time ;
F_29 ( & V_27 -> V_50 ) ;
if ( ! F_30 ( V_27 -> V_51 ) ||
( V_61 && V_61 -> V_62 == V_134 ) ||
F_31 ( & V_154 -> V_52 ) )
goto V_53;
V_13 = F_32 ( V_27 -> V_13 , V_27 ) ;
V_23 = F_12 ( V_13 , V_69 ) ;
if ( ! V_23 )
goto V_53;
if ( V_27 -> V_155 ) {
F_101 ( V_27 , V_61 , & V_23 -> V_24 ) ;
time = V_60 + V_27 -> V_200 *
V_27 -> V_97 ;
F_41 ( & V_152 -> V_52 , time ) ;
for ( V_48 = F_32 ( V_23 -> V_55 , V_27 ) ;
V_48 != NULL ;
V_48 = F_32 ( V_48 -> V_59 , V_27 ) ) {
if ( V_48 -> V_61 != V_61 )
continue;
if ( ! F_43 ( & V_48 -> V_54 ) &&
( F_31 ( & V_48 -> V_52 ) ?
F_136 ( V_48 -> V_52 . V_201 , time ) :
F_112 ( & V_48 -> V_52 ) >= 0 ) ) {
F_41 ( & V_48 -> V_52 , time ) ;
}
break;
}
}
if ( V_61 && ( V_61 -> V_209 & V_210 ) ) {
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
F_88 ( V_27 -> V_51 , V_61 , V_69 , V_211 ) ;
if ( ! V_23 -> V_55 && ! V_23 -> V_54 &&
F_30 ( V_27 -> V_51 ) )
F_41 ( & V_23 -> V_52 , V_60 ) ;
}
goto V_53;
}
V_133 = V_60 ;
time = V_133 + V_27 -> V_200 *
V_27 -> V_97 ;
if ( ! V_61 ) {
if ( V_23 -> V_54 &&
( F_31 ( & V_23 -> V_52 ) ?
F_136 ( V_23 -> V_52 . V_201 , time ) :
F_112 ( & V_23 -> V_52 ) >= 0 ) ) {
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
F_136 ( V_48 -> V_52 . V_201 , time ) :
F_112 ( & V_48 -> V_52 ) >= 0 ) ) {
F_41 ( & V_48 -> V_52 , time ) ;
}
break;
}
V_53:
F_35 ( & V_27 -> V_50 ) ;
}
static void F_142 ( struct V_26 * V_27 ,
struct V_122 * V_61 ,
T_1 V_69 ,
T_2 V_5 )
{
struct V_1 V_139 ;
struct V_143 * V_152 ;
if ( F_90 ( V_69 ) )
return;
V_152 = V_61 ? & V_61 -> V_145 : & V_27 -> V_145 ;
V_139 . V_7 . V_8 = V_69 ;
V_139 . V_4 = F_2 ( V_6 ) ;
V_139 . V_5 = V_5 ;
F_141 ( V_27 , V_61 , & V_139 , & V_27 -> V_156 ,
V_152 ) ;
}
static void F_143 ( struct V_26 * V_27 ,
struct V_122 * V_61 ,
const struct V_19 * V_69 ,
T_2 V_5 )
{
struct V_1 V_139 ;
struct V_143 * V_152 ;
if ( F_92 ( V_69 ) )
return;
V_152 = V_61 ? & V_61 -> V_146 : & V_27 -> V_146 ;
V_139 . V_7 . V_11 = * V_69 ;
V_139 . V_4 = F_2 ( V_10 ) ;
V_139 . V_5 = V_5 ;
F_141 ( V_27 , V_61 , & V_139 , & V_27 -> V_157 ,
V_152 ) ;
}
static int F_144 ( struct V_26 * V_27 ,
struct V_122 * V_61 ,
struct V_28 * V_29 ,
T_3 V_5 )
{
struct V_28 * V_212 = V_29 ;
const struct V_74 * V_75 ;
struct V_70 * V_71 ;
unsigned int V_42 ;
unsigned int V_213 ;
int V_65 ;
if ( ! F_117 ( V_29 , sizeof( * V_75 ) ) )
return - V_46 ;
V_75 = F_18 ( V_29 ) ;
if ( V_75 -> V_81 < 5 || V_75 -> V_80 != 4 )
return - V_46 ;
if ( ! F_117 ( V_29 , F_145 ( V_29 ) ) )
return - V_46 ;
V_75 = F_18 ( V_29 ) ;
if ( F_76 ( F_146 ( ( V_93 * ) V_75 , V_75 -> V_81 ) ) )
return - V_46 ;
if ( V_75 -> V_32 != V_88 ) {
if ( ! F_90 ( V_75 -> V_33 ) )
F_17 ( V_29 ) -> V_214 = 1 ;
return 0 ;
}
V_42 = F_119 ( V_75 -> V_83 ) ;
if ( V_29 -> V_42 < V_42 || V_42 < F_145 ( V_29 ) )
return - V_46 ;
if ( V_29 -> V_42 > V_42 ) {
V_212 = F_147 ( V_29 , V_66 ) ;
if ( ! V_212 )
return - V_67 ;
V_65 = F_148 ( V_212 , V_42 ) ;
if ( V_65 )
goto V_215;
}
V_42 -= F_145 ( V_212 ) ;
V_213 = F_149 ( V_212 ) + F_145 ( V_212 ) ;
F_62 ( V_212 , V_213 ) ;
F_150 ( V_212 ) ;
V_65 = - V_46 ;
if ( ! F_117 ( V_212 , sizeof( * V_71 ) ) )
goto V_53;
switch ( V_212 -> V_216 ) {
case V_217 :
if ( ! F_151 ( V_212 -> V_101 ) )
break;
case V_218 :
V_212 -> V_101 = 0 ;
if ( F_152 ( V_212 ) )
goto V_53;
}
V_65 = 0 ;
F_17 ( V_29 ) -> V_31 = 1 ;
V_71 = F_60 ( V_212 ) ;
switch ( V_71 -> type ) {
case V_219 :
case V_220 :
F_17 ( V_29 ) -> V_214 = 1 ;
V_65 = F_89 ( V_27 , V_61 , V_71 -> V_69 , V_5 ) ;
break;
case V_221 :
V_65 = F_116 ( V_27 , V_61 , V_212 , V_5 ) ;
break;
case V_95 :
V_65 = F_133 ( V_27 , V_61 , V_212 , V_5 ) ;
break;
case V_222 :
F_142 ( V_27 , V_61 , V_71 -> V_69 , V_5 ) ;
break;
}
V_53:
F_153 ( V_212 , V_213 ) ;
V_215:
if ( V_212 != V_29 )
F_67 ( V_212 ) ;
return V_65 ;
}
static int F_154 ( struct V_26 * V_27 ,
struct V_122 * V_61 ,
struct V_28 * V_29 ,
T_3 V_5 )
{
struct V_28 * V_212 ;
const struct V_102 * V_103 ;
V_93 V_223 ;
V_93 V_109 ;
T_5 V_85 ;
unsigned int V_42 ;
int V_213 ;
int V_65 ;
if ( ! F_117 ( V_29 , sizeof( * V_103 ) ) )
return - V_46 ;
V_103 = F_19 ( V_29 ) ;
if ( V_103 -> V_80 != 6 )
return 0 ;
if ( ! F_92 ( & V_103 -> V_33 ) )
F_17 ( V_29 ) -> V_214 = 1 ;
if ( V_103 -> V_109 != V_110 ||
V_103 -> V_108 == 0 )
return 0 ;
V_42 = F_119 ( V_103 -> V_108 ) + sizeof( * V_103 ) ;
if ( V_29 -> V_42 < V_42 )
return - V_46 ;
V_109 = V_103 -> V_109 ;
V_213 = F_155 ( V_29 , sizeof( * V_103 ) , & V_109 , & V_85 ) ;
if ( V_213 < 0 || V_109 != V_112 )
return 0 ;
V_212 = F_147 ( V_29 , V_66 ) ;
if ( ! V_212 )
return - V_67 ;
V_65 = - V_46 ;
if ( ! F_117 ( V_212 , V_213 + sizeof( struct V_179 ) ) )
goto V_53;
V_42 -= V_213 - F_149 ( V_212 ) ;
F_62 ( V_212 , V_213 ) ;
F_150 ( V_212 ) ;
F_156 ( V_212 , F_157 ( V_212 ) ,
F_158 ( V_212 ) ) ;
V_223 = F_69 ( V_212 ) -> V_223 ;
switch ( V_223 ) {
case V_116 :
case V_224 :
case V_225 :
case V_226 :
break;
default:
V_65 = 0 ;
goto V_53;
}
if ( V_212 -> V_42 > V_42 ) {
V_65 = F_148 ( V_212 , V_42 ) ;
if ( V_65 )
goto V_53;
V_65 = - V_46 ;
}
V_103 = F_19 ( V_212 ) ;
switch ( V_212 -> V_216 ) {
case V_217 :
if ( ! F_72 ( & V_103 -> V_89 , & V_103 -> V_33 , V_212 -> V_42 ,
V_112 , V_212 -> V_101 ) )
break;
case V_218 :
V_212 -> V_101 = ~ F_159 ( F_72 ( & V_103 -> V_89 ,
& V_103 -> V_33 ,
V_212 -> V_42 ,
V_112 , 0 ) ) ;
if ( F_160 ( V_212 ) )
goto V_53;
}
V_65 = 0 ;
F_17 ( V_29 ) -> V_31 = 1 ;
switch ( V_223 ) {
case V_224 :
{
struct V_104 * V_202 ;
if ( ! F_117 ( V_212 , sizeof( * V_202 ) ) ) {
V_65 = - V_46 ;
goto V_53;
}
V_202 = (struct V_104 * ) F_161 ( V_212 ) ;
F_17 ( V_29 ) -> V_214 = 1 ;
V_65 = F_91 ( V_27 , V_61 , & V_202 -> V_121 , V_5 ) ;
break;
}
case V_226 :
V_65 = F_120 ( V_27 , V_61 , V_212 , V_5 ) ;
break;
case V_116 :
V_65 = F_137 ( V_27 , V_61 , V_212 , V_5 ) ;
break;
case V_225 :
{
struct V_104 * V_202 ;
if ( ! F_117 ( V_212 , sizeof( * V_202 ) ) ) {
V_65 = - V_46 ;
goto V_53;
}
V_202 = (struct V_104 * ) F_161 ( V_212 ) ;
F_143 ( V_27 , V_61 , & V_202 -> V_121 , V_5 ) ;
}
}
V_53:
F_67 ( V_212 ) ;
return V_65 ;
}
int F_162 ( struct V_26 * V_27 , struct V_122 * V_61 ,
struct V_28 * V_29 , T_3 V_5 )
{
F_17 ( V_29 ) -> V_31 = 0 ;
F_17 ( V_29 ) -> V_214 = 0 ;
if ( V_27 -> V_30 )
return 0 ;
switch ( V_29 -> V_32 ) {
case F_2 ( V_6 ) :
return F_144 ( V_27 , V_61 , V_29 , V_5 ) ;
#if F_3 ( V_9 )
case F_2 ( V_10 ) :
return F_154 ( V_27 , V_61 , V_29 , V_5 ) ;
#endif
}
return 0 ;
}
static void F_163 ( struct V_26 * V_27 ,
struct V_143 * V_144 ,
struct V_227 * V_228 )
{
F_29 ( & V_27 -> V_50 ) ;
if ( V_144 -> V_158 < V_27 -> V_159 )
V_144 -> V_158 ++ ;
F_164 ( V_228 -> V_61 , NULL ) ;
F_104 ( V_27 , NULL , V_144 ) ;
F_35 ( & V_27 -> V_50 ) ;
}
static void F_165 ( unsigned long V_49 )
{
struct V_26 * V_27 = ( void * ) V_49 ;
F_163 ( V_27 , & V_27 -> V_145 , & V_27 -> V_147 ) ;
}
static void F_166 ( unsigned long V_49 )
{
struct V_26 * V_27 = ( void * ) V_49 ;
F_163 ( V_27 , & V_27 -> V_146 , & V_27 -> V_148 ) ;
}
void F_167 ( struct V_26 * V_27 )
{
V_27 -> V_124 = 4 ;
V_27 -> V_126 = 512 ;
V_27 -> V_140 = 1 ;
V_27 -> V_155 = 0 ;
V_27 -> V_90 = 0 ;
V_27 -> V_200 = 2 ;
V_27 -> V_159 = 2 ;
V_27 -> V_97 = V_99 ;
V_27 -> V_98 = 10 * V_99 ;
V_27 -> V_160 = 125 * V_99 / 4 ;
V_27 -> V_161 = 125 * V_99 ;
V_27 -> V_195 = 255 * V_99 ;
V_27 -> V_135 = 260 * V_99 ;
V_27 -> V_156 . V_194 = 0 ;
V_27 -> V_147 . V_61 = NULL ;
#if F_3 ( V_9 )
V_27 -> V_157 . V_194 = 0 ;
V_27 -> V_148 . V_61 = NULL ;
#endif
F_168 ( & V_27 -> V_50 ) ;
F_83 ( & V_27 -> V_141 ,
F_95 , 0 ) ;
F_83 ( & V_27 -> V_156 . V_52 ,
F_98 , ( unsigned long ) V_27 ) ;
F_83 ( & V_27 -> V_145 . V_52 , F_165 ,
( unsigned long ) V_27 ) ;
#if F_3 ( V_9 )
F_83 ( & V_27 -> V_157 . V_52 ,
F_99 , ( unsigned long ) V_27 ) ;
F_83 ( & V_27 -> V_146 . V_52 , F_166 ,
( unsigned long ) V_27 ) ;
#endif
}
static void F_169 ( struct V_26 * V_27 ,
struct V_143 * V_144 )
{
V_144 -> V_158 = 0 ;
if ( V_27 -> V_30 )
return;
F_41 ( & V_144 -> V_52 , V_60 ) ;
}
void F_170 ( struct V_26 * V_27 )
{
F_169 ( V_27 , & V_27 -> V_145 ) ;
#if F_3 ( V_9 )
F_169 ( V_27 , & V_27 -> V_146 ) ;
#endif
}
void F_171 ( struct V_26 * V_27 )
{
struct V_12 * V_13 ;
struct V_20 * V_23 ;
struct V_163 * V_164 ;
V_16 V_45 ;
int V_43 ;
F_110 ( & V_27 -> V_141 ) ;
F_110 ( & V_27 -> V_156 . V_52 ) ;
F_110 ( & V_27 -> V_145 . V_52 ) ;
#if F_3 ( V_9 )
F_110 ( & V_27 -> V_157 . V_52 ) ;
F_110 ( & V_27 -> V_146 . V_52 ) ;
#endif
F_172 ( & V_27 -> V_50 ) ;
V_13 = F_32 ( V_27 -> V_13 , V_27 ) ;
if ( ! V_13 )
goto V_53;
V_27 -> V_13 = NULL ;
V_45 = V_13 -> V_45 ;
for ( V_43 = 0 ; V_43 < V_13 -> V_18 ; V_43 ++ ) {
F_115 (mp, n, &mdb->mhash[i],
hlist[ver]) {
F_40 ( & V_23 -> V_52 ) ;
F_34 ( & V_23 -> V_36 , F_27 ) ;
}
}
if ( V_13 -> V_37 ) {
F_173 ( & V_27 -> V_50 ) ;
F_174 () ;
F_172 ( & V_27 -> V_50 ) ;
F_37 ( V_13 -> V_37 ) ;
}
V_13 -> V_37 = V_13 ;
F_34 ( & V_13 -> V_36 , F_20 ) ;
V_53:
F_173 ( & V_27 -> V_50 ) ;
}
int F_175 ( struct V_26 * V_27 , unsigned long V_229 )
{
int V_65 = - V_230 ;
F_172 ( & V_27 -> V_50 ) ;
if ( ! F_30 ( V_27 -> V_51 ) )
goto V_231;
switch ( V_229 ) {
case 0 :
case 2 :
F_40 ( & V_27 -> V_141 ) ;
case 1 :
V_27 -> V_140 = V_229 ;
V_65 = 0 ;
break;
default:
V_65 = - V_46 ;
break;
}
V_231:
F_173 ( & V_27 -> V_50 ) ;
return V_65 ;
}
int F_176 ( struct V_122 * V_48 , unsigned long V_229 )
{
struct V_26 * V_27 = V_48 -> V_27 ;
int V_65 = - V_230 ;
F_29 ( & V_27 -> V_50 ) ;
if ( ! F_30 ( V_27 -> V_51 ) || V_48 -> V_62 == V_134 )
goto V_231;
switch ( V_229 ) {
case 0 :
case 1 :
case 2 :
V_48 -> V_140 = V_229 ;
V_65 = 0 ;
if ( V_229 < 2 && ! F_43 ( & V_48 -> V_142 ) )
F_94 ( & V_48 -> V_142 ) ;
if ( V_229 == 1 )
break;
F_40 ( & V_48 -> V_141 ) ;
if ( V_229 == 0 )
break;
F_129 ( V_27 , V_48 ) ;
break;
default:
V_65 = - V_46 ;
break;
}
V_231:
F_35 ( & V_27 -> V_50 ) ;
return V_65 ;
}
static void F_97 ( struct V_26 * V_27 ,
struct V_143 * V_144 )
{
struct V_122 * V_61 ;
F_169 ( V_27 , V_144 ) ;
F_177 (port, &br->port_list, list) {
if ( V_61 -> V_62 == V_134 ||
V_61 -> V_62 == V_162 )
continue;
if ( V_144 == & V_27 -> V_145 )
F_111 ( & V_61 -> V_145 ) ;
#if F_3 ( V_9 )
else
F_111 ( & V_61 -> V_146 ) ;
#endif
}
}
int F_178 ( struct V_26 * V_27 , unsigned long V_229 )
{
int V_65 = 0 ;
struct V_12 * V_13 ;
F_172 ( & V_27 -> V_50 ) ;
if ( V_27 -> V_30 == ! V_229 )
goto V_231;
V_27 -> V_30 = ! V_229 ;
if ( V_27 -> V_30 )
goto V_231;
if ( ! F_30 ( V_27 -> V_51 ) )
goto V_231;
V_13 = F_32 ( V_27 -> V_13 , V_27 ) ;
if ( V_13 ) {
if ( V_13 -> V_37 ) {
V_65 = - V_129 ;
V_232:
V_27 -> V_30 = ! ! V_229 ;
goto V_231;
}
V_65 = F_44 ( & V_27 -> V_13 , V_13 -> V_18 ,
V_27 -> V_124 ) ;
if ( V_65 )
goto V_232;
}
F_97 ( V_27 , & V_27 -> V_145 ) ;
#if F_3 ( V_9 )
F_97 ( V_27 , & V_27 -> V_146 ) ;
#endif
V_231:
F_173 ( & V_27 -> V_50 ) ;
return V_65 ;
}
int F_179 ( struct V_26 * V_27 , unsigned long V_229 )
{
unsigned long V_193 ;
V_229 = ! ! V_229 ;
F_172 ( & V_27 -> V_50 ) ;
if ( V_27 -> V_155 == V_229 )
goto V_231;
V_27 -> V_155 = V_229 ;
if ( ! V_229 )
goto V_231;
V_193 = V_27 -> V_98 ;
if ( ! F_31 ( & V_27 -> V_156 . V_52 ) )
V_27 -> V_156 . V_194 = V_60 + V_193 ;
F_97 ( V_27 , & V_27 -> V_145 ) ;
#if F_3 ( V_9 )
if ( ! F_31 ( & V_27 -> V_157 . V_52 ) )
V_27 -> V_157 . V_194 = V_60 + V_193 ;
F_97 ( V_27 , & V_27 -> V_146 ) ;
#endif
V_231:
F_173 ( & V_27 -> V_50 ) ;
return 0 ;
}
int F_180 ( struct V_26 * V_27 , unsigned long V_229 )
{
int V_65 = - V_230 ;
V_16 V_37 ;
struct V_12 * V_13 ;
F_172 ( & V_27 -> V_50 ) ;
if ( ! F_30 ( V_27 -> V_51 ) )
goto V_231;
V_65 = - V_46 ;
if ( ! F_181 ( V_229 ) )
goto V_231;
V_13 = F_32 ( V_27 -> V_13 , V_27 ) ;
if ( V_13 && V_229 < V_13 -> V_56 )
goto V_231;
V_65 = 0 ;
V_37 = V_27 -> V_126 ;
V_27 -> V_126 = V_229 ;
if ( V_13 ) {
if ( V_13 -> V_37 ) {
V_65 = - V_129 ;
V_232:
V_27 -> V_126 = V_37 ;
goto V_231;
}
V_65 = F_44 ( & V_27 -> V_13 , V_27 -> V_126 ,
V_27 -> V_124 ) ;
if ( V_65 )
goto V_232;
}
V_231:
F_173 ( & V_27 -> V_50 ) ;
return V_65 ;
}
int F_182 ( struct V_233 * V_51 ,
struct V_234 * V_235 )
{
struct V_26 * V_27 ;
struct V_122 * V_61 ;
struct V_47 * V_69 ;
struct V_235 * V_236 ;
int V_123 = 0 ;
F_183 () ;
if ( ! V_235 || ! F_184 ( V_51 ) )
goto V_231;
V_61 = F_185 ( V_51 ) ;
if ( ! V_61 || ! V_61 -> V_27 )
goto V_231;
V_27 = V_61 -> V_27 ;
F_186 (port, &br->port_list, list) {
if ( ! V_61 -> V_51 || V_61 -> V_51 == V_51 )
continue;
F_11 (group, &port->mglist, mglist) {
V_236 = F_46 ( sizeof( * V_236 ) , V_66 ) ;
if ( ! V_236 )
goto V_231;
V_236 -> V_24 = V_69 -> V_24 ;
F_187 ( & V_236 -> V_237 , V_235 ) ;
V_123 ++ ;
}
}
V_231:
F_188 () ;
return V_123 ;
}
bool F_189 ( struct V_233 * V_51 , int V_4 )
{
struct V_26 * V_27 ;
struct V_122 * V_61 ;
struct V_72 V_73 ;
bool V_238 = false ;
F_183 () ;
if ( ! F_184 ( V_51 ) )
goto V_231;
V_61 = F_185 ( V_51 ) ;
if ( ! V_61 || ! V_61 -> V_27 )
goto V_231;
V_27 = V_61 -> V_27 ;
memset ( & V_73 , 0 , sizeof( V_73 ) ) ;
V_73 . V_79 = F_2 ( V_4 ) ;
V_238 = F_190 ( V_27 , & V_73 ) ;
V_231:
F_188 () ;
return V_238 ;
}
bool F_191 ( struct V_233 * V_51 , int V_4 )
{
struct V_26 * V_27 ;
struct V_122 * V_61 ;
bool V_238 = false ;
F_183 () ;
if ( ! F_184 ( V_51 ) )
goto V_231;
V_61 = F_185 ( V_51 ) ;
if ( ! V_61 || ! V_61 -> V_27 )
goto V_231;
V_27 = V_61 -> V_27 ;
switch ( V_4 ) {
case V_6 :
if ( ! F_31 ( & V_27 -> V_156 . V_52 ) ||
F_16 ( V_27 -> V_147 . V_61 ) == V_61 )
goto V_231;
break;
#if F_3 ( V_9 )
case V_10 :
if ( ! F_31 ( & V_27 -> V_157 . V_52 ) ||
F_16 ( V_27 -> V_148 . V_61 ) == V_61 )
goto V_231;
break;
#endif
default:
goto V_231;
}
V_238 = true ;
V_231:
F_188 () ;
return V_238 ;
}
