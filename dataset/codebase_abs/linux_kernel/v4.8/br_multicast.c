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
struct V_28 * V_29 ;
struct V_72 * V_73 ;
struct V_74 * V_75 ;
struct V_76 * V_77 ;
V_29 = F_51 ( V_27 -> V_51 , sizeof( * V_75 ) + sizeof( * V_77 ) +
sizeof( * V_73 ) + 4 ) ;
if ( ! V_29 )
goto V_53;
V_29 -> V_32 = F_2 ( V_6 ) ;
F_52 ( V_29 ) ;
V_75 = F_53 ( V_29 ) ;
F_54 ( V_75 -> V_78 , V_27 -> V_51 -> V_79 ) ;
V_75 -> V_80 [ 0 ] = 1 ;
V_75 -> V_80 [ 1 ] = 0 ;
V_75 -> V_80 [ 2 ] = 0x5e ;
V_75 -> V_80 [ 3 ] = 0 ;
V_75 -> V_80 [ 4 ] = 0 ;
V_75 -> V_80 [ 5 ] = 1 ;
V_75 -> V_81 = F_2 ( V_6 ) ;
F_55 ( V_29 , sizeof( * V_75 ) ) ;
F_56 ( V_29 , V_29 -> V_42 ) ;
V_77 = F_18 ( V_29 ) ;
V_77 -> V_82 = 4 ;
V_77 -> V_83 = 6 ;
V_77 -> V_84 = 0xc0 ;
V_77 -> V_85 = F_2 ( sizeof( * V_77 ) + sizeof( * V_73 ) + 4 ) ;
V_77 -> V_86 = 0 ;
V_77 -> V_87 = F_2 ( V_88 ) ;
V_77 -> V_89 = 1 ;
V_77 -> V_32 = V_90 ;
V_77 -> V_91 = V_27 -> V_92 ?
F_57 ( V_27 -> V_51 , 0 , V_93 ) : 0 ;
V_77 -> V_33 = F_58 ( V_94 ) ;
( ( T_5 * ) & V_77 [ 1 ] ) [ 0 ] = V_95 ;
( ( T_5 * ) & V_77 [ 1 ] ) [ 1 ] = 4 ;
( ( T_5 * ) & V_77 [ 1 ] ) [ 2 ] = 0 ;
( ( T_5 * ) & V_77 [ 1 ] ) [ 3 ] = 0 ;
F_59 ( V_77 ) ;
F_55 ( V_29 , 24 ) ;
F_60 ( V_29 , V_29 -> V_42 ) ;
V_73 = F_61 ( V_29 ) ;
* V_71 = V_96 ;
V_73 -> type = V_96 ;
V_73 -> V_97 = ( V_70 ? V_27 -> V_98 :
V_27 -> V_99 ) /
( V_100 / V_101 ) ;
V_73 -> V_70 = V_70 ;
V_73 -> V_102 = 0 ;
V_73 -> V_102 = F_62 ( ( void * ) V_73 , sizeof( struct V_72 ) ) ;
F_55 ( V_29 , sizeof( * V_73 ) ) ;
F_63 ( V_29 , sizeof( * V_75 ) ) ;
V_53:
return V_29 ;
}
static struct V_28 * F_64 ( struct V_26 * V_27 ,
const struct V_19 * V_103 ,
T_5 * V_71 )
{
struct V_28 * V_29 ;
struct V_104 * V_105 ;
struct V_106 * V_107 ;
struct V_74 * V_75 ;
T_5 * V_108 ;
unsigned long V_109 ;
V_29 = F_51 ( V_27 -> V_51 , sizeof( * V_75 ) + sizeof( * V_105 ) +
8 + sizeof( * V_107 ) ) ;
if ( ! V_29 )
goto V_53;
V_29 -> V_32 = F_2 ( V_10 ) ;
F_52 ( V_29 ) ;
V_75 = F_53 ( V_29 ) ;
F_54 ( V_75 -> V_78 , V_27 -> V_51 -> V_79 ) ;
V_75 -> V_81 = F_2 ( V_10 ) ;
F_55 ( V_29 , sizeof( * V_75 ) ) ;
F_56 ( V_29 , V_29 -> V_42 ) ;
V_105 = F_19 ( V_29 ) ;
* ( V_15 T_1 * ) V_105 = F_58 ( 0x60000000 ) ;
V_105 -> V_110 = F_2 ( 8 + sizeof( * V_107 ) ) ;
V_105 -> V_111 = V_112 ;
V_105 -> V_113 = 1 ;
F_65 ( & V_105 -> V_33 , F_58 ( 0xff020000 ) , 0 , 0 , F_58 ( 1 ) ) ;
if ( F_66 ( F_67 ( V_27 -> V_51 ) , V_27 -> V_51 , & V_105 -> V_33 , 0 ,
& V_105 -> V_91 ) ) {
F_68 ( V_29 ) ;
V_27 -> V_114 = 0 ;
return NULL ;
}
V_27 -> V_114 = 1 ;
F_69 ( & V_105 -> V_33 , V_75 -> V_80 ) ;
V_108 = ( T_5 * ) ( V_105 + 1 ) ;
V_108 [ 0 ] = V_115 ;
V_108 [ 1 ] = 0 ;
V_108 [ 2 ] = V_116 ;
V_108 [ 3 ] = 2 ;
V_108 [ 4 ] = 0 ;
V_108 [ 5 ] = 0 ;
V_108 [ 6 ] = V_117 ;
V_108 [ 7 ] = V_117 ;
F_55 ( V_29 , sizeof( * V_105 ) + 8 ) ;
F_60 ( V_29 , V_29 -> V_42 ) ;
V_107 = (struct V_106 * ) F_70 ( V_29 ) ;
V_109 = F_71 ( V_103 ) ?
V_27 -> V_99 :
V_27 -> V_98 ;
* V_71 = V_118 ;
V_107 -> V_119 = V_118 ;
V_107 -> V_120 = 0 ;
V_107 -> V_121 = 0 ;
V_107 -> V_122 = F_2 ( ( T_3 ) F_72 ( V_109 ) ) ;
V_107 -> V_123 = 0 ;
V_107 -> V_124 = * V_103 ;
V_107 -> V_121 = F_73 ( & V_105 -> V_91 , & V_105 -> V_33 ,
sizeof( * V_107 ) , V_115 ,
F_74 ( V_107 ,
sizeof( * V_107 ) , 0 ) ) ;
F_55 ( V_29 , sizeof( * V_107 ) ) ;
F_63 ( V_29 , sizeof( * V_75 ) ) ;
V_53:
return V_29 ;
}
static struct V_28 * F_75 ( struct V_26 * V_27 ,
struct V_1 * V_24 ,
T_5 * V_71 )
{
switch ( V_24 -> V_4 ) {
case F_2 ( V_6 ) :
return F_50 ( V_27 , V_24 -> V_7 . V_8 , V_71 ) ;
#if F_3 ( V_9 )
case F_2 ( V_10 ) :
return F_64 ( V_27 , & V_24 -> V_7 . V_11 ,
V_71 ) ;
#endif
}
return NULL ;
}
static struct V_20 * F_76 (
struct V_26 * V_27 , struct V_125 * V_60 ,
struct V_1 * V_70 , int V_22 )
{
struct V_12 * V_13 ;
struct V_20 * V_23 ;
unsigned int V_126 = 0 ;
unsigned int V_18 ;
int V_40 ;
int V_66 ;
V_13 = F_46 ( V_27 -> V_13 , 1 ) ;
F_24 (mp, &mdb->mhash[hash], hlist[mdb->ver]) {
V_126 ++ ;
if ( F_77 ( F_1 ( V_70 , & V_23 -> V_24 ) ) )
return V_23 ;
}
V_40 = 0 ;
V_18 = V_13 -> V_18 ;
if ( F_77 ( V_126 > V_27 -> V_127 && V_126 ) ) {
if ( F_78 () )
F_79 ( V_27 , L_1
L_2 ,
V_60 ? V_60 -> V_51 -> V_128 : V_27 -> V_51 -> V_128 ) ;
V_40 = V_27 -> V_127 ;
}
if ( V_13 -> V_56 >= V_18 ) {
V_18 *= 2 ;
if ( F_77 ( V_18 > V_27 -> V_129 ) ) {
F_80 ( V_27 , L_3
L_4 ,
V_27 -> V_129 ,
V_60 ? V_60 -> V_51 -> V_128 : V_27 -> V_51 -> V_128 ) ;
V_66 = - V_130 ;
V_131:
V_27 -> V_30 = 1 ;
goto V_66;
}
}
if ( V_18 > V_13 -> V_18 || V_40 ) {
if ( V_13 -> V_37 ) {
if ( F_78 () )
F_79 ( V_27 , L_1
L_5 ,
V_60 ? V_60 -> V_51 -> V_128 : V_27 -> V_51 -> V_128 ) ;
V_66 = - V_132 ;
goto V_66;
}
V_66 = F_45 ( & V_27 -> V_13 , V_18 , V_40 ) ;
if ( V_66 ) {
F_80 ( V_27 , L_6
L_7 ,
V_60 ? V_60 -> V_51 -> V_128 : V_27 -> V_51 -> V_128 ,
V_13 -> V_56 , V_66 ) ;
goto V_131;
}
V_66 = - V_133 ;
goto V_66;
}
return NULL ;
V_66:
V_23 = F_81 ( V_66 ) ;
return V_23 ;
}
struct V_20 * F_82 ( struct V_26 * V_27 ,
struct V_125 * V_60 , struct V_1 * V_70 )
{
struct V_12 * V_13 ;
struct V_20 * V_23 ;
int V_22 ;
int V_66 ;
V_13 = F_46 ( V_27 -> V_13 , 1 ) ;
if ( ! V_13 ) {
V_66 = F_45 ( & V_27 -> V_13 , V_134 , 0 ) ;
if ( V_66 )
return F_81 ( V_66 ) ;
goto V_135;
}
V_22 = F_9 ( V_13 , V_70 ) ;
V_23 = F_76 ( V_27 , V_60 , V_70 , V_22 ) ;
switch ( F_83 ( V_23 ) ) {
case 0 :
break;
case - V_133 :
V_135:
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
struct V_125 * V_60 ,
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
struct V_125 * V_60 ,
struct V_1 * V_70 )
{
struct V_20 * V_23 ;
struct V_47 * V_48 ;
struct V_47 T_4 * * V_58 ;
unsigned long V_136 = V_63 ;
int V_66 ;
F_29 ( & V_27 -> V_50 ) ;
if ( ! F_30 ( V_27 -> V_51 ) ||
( V_60 && V_60 -> V_137 == V_138 ) )
goto V_53;
V_23 = F_82 ( V_27 , V_60 , V_70 ) ;
V_66 = F_83 ( V_23 ) ;
if ( F_88 ( V_23 ) )
goto V_66;
if ( ! V_60 ) {
V_23 -> V_54 = true ;
F_42 ( & V_23 -> V_52 , V_136 + V_27 -> V_139 ) ;
goto V_53;
}
for ( V_58 = & V_23 -> V_55 ;
( V_48 = F_32 ( * V_58 , V_27 ) ) != NULL ;
V_58 = & V_48 -> V_59 ) {
if ( V_48 -> V_60 == V_60 )
goto V_140;
if ( ( unsigned long ) V_48 -> V_60 < ( unsigned long ) V_60 )
break;
}
V_48 = F_86 ( V_60 , V_70 , * V_58 , 0 ) ;
if ( F_77 ( ! V_48 ) )
goto V_66;
F_38 ( * V_58 , V_48 ) ;
F_41 ( V_27 -> V_51 , V_60 , V_70 , V_141 , 0 ) ;
V_140:
F_42 ( & V_48 -> V_52 , V_136 + V_27 -> V_139 ) ;
V_53:
V_66 = 0 ;
V_66:
F_35 ( & V_27 -> V_50 ) ;
return V_66 ;
}
static int F_89 ( struct V_26 * V_27 ,
struct V_125 * V_60 ,
T_1 V_70 ,
T_2 V_5 )
{
struct V_1 V_142 ;
if ( F_90 ( V_70 ) )
return 0 ;
V_142 . V_7 . V_8 = V_70 ;
V_142 . V_4 = F_2 ( V_6 ) ;
V_142 . V_5 = V_5 ;
return F_87 ( V_27 , V_60 , & V_142 ) ;
}
static int F_91 ( struct V_26 * V_27 ,
struct V_125 * V_60 ,
const struct V_19 * V_70 ,
T_2 V_5 )
{
struct V_1 V_142 ;
if ( F_92 ( V_70 ) )
return 0 ;
V_142 . V_7 . V_11 = * V_70 ;
V_142 . V_4 = F_2 ( V_10 ) ;
V_142 . V_5 = V_5 ;
return F_87 ( V_27 , V_60 , & V_142 ) ;
}
static void F_93 ( unsigned long V_49 )
{
struct V_125 * V_60 = ( void * ) V_49 ;
struct V_26 * V_27 = V_60 -> V_27 ;
F_29 ( & V_27 -> V_50 ) ;
if ( V_60 -> V_143 == V_144 ||
V_60 -> V_143 == V_145 ||
F_31 ( & V_60 -> V_146 ) ||
F_44 ( & V_60 -> V_147 ) )
goto V_53;
F_94 ( & V_60 -> V_147 ) ;
F_95 ( V_27 -> V_51 , V_60 , V_61 ) ;
if ( V_60 -> V_143 == V_148 )
V_60 -> V_143 = V_149 ;
V_53:
F_35 ( & V_27 -> V_50 ) ;
}
static void F_96 ( unsigned long V_49 )
{
}
static void F_97 ( struct V_26 * V_27 ,
struct V_150 * V_151 )
{
F_29 ( & V_27 -> V_50 ) ;
if ( ! F_30 ( V_27 -> V_51 ) || V_27 -> V_30 )
goto V_53;
F_98 ( V_27 , V_151 ) ;
V_53:
F_35 ( & V_27 -> V_50 ) ;
}
static void F_99 ( unsigned long V_49 )
{
struct V_26 * V_27 = ( void * ) V_49 ;
F_97 ( V_27 , & V_27 -> V_152 ) ;
}
static void F_100 ( unsigned long V_49 )
{
struct V_26 * V_27 = ( void * ) V_49 ;
F_97 ( V_27 , & V_27 -> V_153 ) ;
}
static void F_101 ( struct V_26 * V_27 ,
struct V_1 * V_14 ,
struct V_28 * V_29 )
{
if ( V_14 -> V_4 == F_2 ( V_6 ) )
V_27 -> V_154 . V_24 . V_7 . V_8 = F_18 ( V_29 ) -> V_91 ;
#if F_3 ( V_9 )
else
V_27 -> V_155 . V_24 . V_7 . V_11 = F_19 ( V_29 ) -> V_91 ;
#endif
}
static void F_102 ( struct V_26 * V_27 ,
struct V_125 * V_60 ,
struct V_1 * V_14 )
{
struct V_28 * V_29 ;
T_5 V_71 ;
V_29 = F_75 ( V_27 , V_14 , & V_71 ) ;
if ( ! V_29 )
return;
if ( V_60 ) {
V_29 -> V_51 = V_60 -> V_51 ;
F_103 ( V_27 , V_60 , V_29 , V_71 ,
V_156 ) ;
F_104 ( V_157 , V_158 ,
F_67 ( V_60 -> V_51 ) , NULL , V_29 , NULL , V_29 -> V_51 ,
V_159 ) ;
} else {
F_101 ( V_27 , V_14 , V_29 ) ;
F_103 ( V_27 , V_60 , V_29 , V_71 ,
V_160 ) ;
F_105 ( V_29 ) ;
}
}
static void F_106 ( struct V_26 * V_27 ,
struct V_125 * V_60 ,
struct V_150 * V_161 )
{
unsigned long time ;
struct V_1 V_142 ;
struct V_162 * V_163 = NULL ;
if ( ! F_30 ( V_27 -> V_51 ) || V_27 -> V_30 ||
! V_27 -> V_164 )
return;
memset ( & V_142 . V_7 , 0 , sizeof( V_142 . V_7 ) ) ;
if ( V_60 ? ( V_161 == & V_60 -> V_152 ) :
( V_161 == & V_27 -> V_152 ) ) {
V_163 = & V_27 -> V_165 ;
V_142 . V_4 = F_2 ( V_6 ) ;
#if F_3 ( V_9 )
} else {
V_163 = & V_27 -> V_166 ;
V_142 . V_4 = F_2 ( V_10 ) ;
#endif
}
if ( ! V_163 || F_31 ( & V_163 -> V_52 ) )
return;
F_102 ( V_27 , V_60 , & V_142 ) ;
time = V_63 ;
time += V_161 -> V_167 < V_27 -> V_168 ?
V_27 -> V_169 :
V_27 -> V_170 ;
F_42 ( & V_161 -> V_52 , time ) ;
}
static void
F_107 ( struct V_125 * V_60 ,
struct V_150 * V_151 )
{
struct V_26 * V_27 = V_60 -> V_27 ;
F_29 ( & V_27 -> V_50 ) ;
if ( V_60 -> V_137 == V_138 ||
V_60 -> V_137 == V_171 )
goto V_53;
if ( V_151 -> V_167 < V_27 -> V_168 )
V_151 -> V_167 ++ ;
F_106 ( V_60 -> V_27 , V_60 , V_151 ) ;
V_53:
F_35 ( & V_27 -> V_50 ) ;
}
static void F_108 ( unsigned long V_49 )
{
struct V_125 * V_60 = ( void * ) V_49 ;
F_107 ( V_60 , & V_60 -> V_152 ) ;
}
static void F_109 ( unsigned long V_49 )
{
struct V_125 * V_60 = ( void * ) V_49 ;
F_107 ( V_60 , & V_60 -> V_153 ) ;
}
int F_110 ( struct V_125 * V_60 )
{
V_60 -> V_143 = V_149 ;
F_84 ( & V_60 -> V_146 , F_93 ,
( unsigned long ) V_60 ) ;
F_84 ( & V_60 -> V_152 . V_52 ,
F_108 , ( unsigned long ) V_60 ) ;
#if F_3 ( V_9 )
F_84 ( & V_60 -> V_153 . V_52 ,
F_109 , ( unsigned long ) V_60 ) ;
#endif
V_60 -> V_172 = F_111 ( struct V_173 ) ;
if ( ! V_60 -> V_172 )
return - V_68 ;
return 0 ;
}
void F_112 ( struct V_125 * V_60 )
{
struct V_26 * V_27 = V_60 -> V_27 ;
struct V_47 * V_57 ;
struct V_174 * V_175 ;
F_113 ( & V_27 -> V_50 ) ;
F_114 (pg, n, &port->mglist, mglist)
F_36 ( V_27 , V_57 ) ;
F_115 ( & V_27 -> V_50 ) ;
F_116 ( & V_60 -> V_146 ) ;
F_117 ( V_60 -> V_172 ) ;
}
static void F_118 ( struct V_150 * V_151 )
{
V_151 -> V_167 = 0 ;
if ( F_119 ( & V_151 -> V_52 ) >= 0 ||
F_40 ( & V_151 -> V_52 ) )
F_42 ( & V_151 -> V_52 , V_63 ) ;
}
void F_120 ( struct V_125 * V_60 )
{
struct V_26 * V_27 = V_60 -> V_27 ;
F_29 ( & V_27 -> V_50 ) ;
if ( V_27 -> V_30 || ! F_30 ( V_27 -> V_51 ) )
goto V_53;
F_118 ( & V_60 -> V_152 ) ;
#if F_3 ( V_9 )
F_118 ( & V_60 -> V_153 ) ;
#endif
if ( V_60 -> V_143 == V_145 &&
F_44 ( & V_60 -> V_147 ) )
F_121 ( V_27 , V_60 ) ;
V_53:
F_35 ( & V_27 -> V_50 ) ;
}
void F_122 ( struct V_125 * V_60 )
{
struct V_26 * V_27 = V_60 -> V_27 ;
struct V_47 * V_57 ;
struct V_174 * V_175 ;
F_29 ( & V_27 -> V_50 ) ;
F_114 (pg, n, &port->mglist, mglist)
if ( ! ( V_57 -> V_62 & V_64 ) )
F_36 ( V_27 , V_57 ) ;
if ( ! F_44 ( & V_60 -> V_147 ) ) {
F_94 ( & V_60 -> V_147 ) ;
F_95 ( V_27 -> V_51 , V_60 , V_61 ) ;
if ( V_60 -> V_143 == V_148 )
V_60 -> V_143 = V_149 ;
}
F_40 ( & V_60 -> V_146 ) ;
F_40 ( & V_60 -> V_152 . V_52 ) ;
#if F_3 ( V_9 )
F_40 ( & V_60 -> V_153 . V_52 ) ;
#endif
F_35 ( & V_27 -> V_50 ) ;
}
static int F_123 ( struct V_26 * V_27 ,
struct V_125 * V_60 ,
struct V_28 * V_29 ,
T_3 V_5 )
{
struct V_176 * V_73 ;
struct V_177 * V_178 ;
int V_43 ;
int V_42 ;
int V_179 ;
int type ;
int V_66 = 0 ;
T_1 V_70 ;
V_73 = F_124 ( V_29 ) ;
V_179 = F_125 ( V_73 -> V_180 ) ;
V_42 = F_126 ( V_29 ) + sizeof( * V_73 ) ;
for ( V_43 = 0 ; V_43 < V_179 ; V_43 ++ ) {
V_42 += sizeof( * V_178 ) ;
if ( ! F_127 ( V_29 , V_42 ) )
return - V_46 ;
V_178 = ( void * ) ( V_29 -> V_49 + V_42 - sizeof( * V_178 ) ) ;
V_70 = V_178 -> V_181 ;
type = V_178 -> V_182 ;
V_42 += F_125 ( V_178 -> V_183 ) * 4 ;
if ( ! F_127 ( V_29 , V_42 ) )
return - V_46 ;
switch ( type ) {
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
if ( ( type == V_186 ||
type == V_184 ) &&
F_125 ( V_178 -> V_183 ) == 0 ) {
F_128 ( V_27 , V_60 , V_70 , V_5 ) ;
} else {
V_66 = F_89 ( V_27 , V_60 , V_70 , V_5 ) ;
if ( V_66 )
break;
}
}
return V_66 ;
}
static int F_129 ( struct V_26 * V_27 ,
struct V_125 * V_60 ,
struct V_28 * V_29 ,
T_3 V_5 )
{
struct V_190 * V_191 ;
struct V_192 * V_178 ;
int V_43 ;
int V_42 ;
int V_179 ;
int V_66 = 0 ;
if ( ! F_127 ( V_29 , sizeof( * V_191 ) ) )
return - V_46 ;
V_191 = F_70 ( V_29 ) ;
V_179 = F_125 ( V_191 -> V_193 . V_194 [ 1 ] ) ;
V_42 = F_126 ( V_29 ) + sizeof( * V_191 ) ;
for ( V_43 = 0 ; V_43 < V_179 ; V_43 ++ ) {
T_6 * V_195 , V_196 ;
V_195 = F_130 ( V_29 ,
V_42 + F_131 ( struct V_192 ,
V_183 ) ,
sizeof( V_196 ) , & V_196 ) ;
if ( ! V_195 )
return - V_46 ;
if ( ! F_127 ( V_29 ,
V_42 + sizeof( * V_178 ) +
sizeof( struct V_19 ) * F_125 ( * V_195 ) ) )
return - V_46 ;
V_178 = (struct V_192 * ) ( V_29 -> V_49 + V_42 ) ;
V_42 += sizeof( * V_178 ) +
sizeof( struct V_19 ) * F_125 ( * V_195 ) ;
switch ( V_178 -> V_182 ) {
case V_197 :
case V_198 :
case V_199 :
case V_200 :
case V_201 :
case V_202 :
break;
default:
continue;
}
if ( ( V_178 -> V_182 == V_199 ||
V_178 -> V_182 == V_197 ) &&
F_125 ( * V_195 ) == 0 ) {
F_132 ( V_27 , V_60 , & V_178 -> V_181 ,
V_5 ) ;
} else {
V_66 = F_91 ( V_27 , V_60 ,
& V_178 -> V_181 , V_5 ) ;
if ( V_66 )
break;
}
}
return V_66 ;
}
static bool F_133 ( struct V_26 * V_27 ,
struct V_125 * V_60 ,
T_1 V_91 )
{
if ( ! F_31 ( & V_27 -> V_152 . V_52 ) &&
! F_31 ( & V_27 -> V_165 . V_52 ) )
goto V_203;
if ( ! V_27 -> V_154 . V_24 . V_7 . V_8 )
goto V_203;
if ( F_134 ( V_91 ) <= F_134 ( V_27 -> V_154 . V_24 . V_7 . V_8 ) )
goto V_203;
return false ;
V_203:
V_27 -> V_154 . V_24 . V_7 . V_8 = V_91 ;
F_38 ( V_27 -> V_154 . V_60 , V_60 ) ;
return true ;
}
static bool F_135 ( struct V_26 * V_27 ,
struct V_125 * V_60 ,
struct V_19 * V_91 )
{
if ( ! F_31 ( & V_27 -> V_153 . V_52 ) &&
! F_31 ( & V_27 -> V_166 . V_52 ) )
goto V_203;
if ( F_136 ( V_91 , & V_27 -> V_155 . V_24 . V_7 . V_11 ) <= 0 )
goto V_203;
return false ;
V_203:
V_27 -> V_155 . V_24 . V_7 . V_11 = * V_91 ;
F_38 ( V_27 -> V_155 . V_60 , V_60 ) ;
return true ;
}
static bool F_137 ( struct V_26 * V_27 ,
struct V_125 * V_60 ,
struct V_1 * V_91 )
{
switch ( V_91 -> V_4 ) {
case F_2 ( V_6 ) :
return F_133 ( V_27 , V_60 , V_91 -> V_7 . V_8 ) ;
#if F_3 ( V_9 )
case F_2 ( V_10 ) :
return F_135 ( V_27 , V_60 , & V_91 -> V_7 . V_11 ) ;
#endif
}
return false ;
}
static void
F_138 ( struct V_26 * V_27 ,
struct V_162 * V_151 ,
unsigned long V_204 )
{
if ( ! F_31 ( & V_151 -> V_52 ) )
V_151 -> V_205 = V_63 + V_204 ;
F_42 ( & V_151 -> V_52 , V_63 + V_27 -> V_206 ) ;
}
static void F_121 ( struct V_26 * V_27 ,
struct V_125 * V_60 )
{
struct V_125 * V_48 ;
struct V_174 * V_207 = NULL ;
if ( ! F_44 ( & V_60 -> V_147 ) )
return;
F_24 (p, &br->router_list, rlist) {
if ( ( unsigned long ) V_60 >= ( unsigned long ) V_48 )
break;
V_207 = & V_48 -> V_147 ;
}
if ( V_207 )
F_139 ( & V_60 -> V_147 , V_207 ) ;
else
F_85 ( & V_60 -> V_147 , & V_27 -> V_208 ) ;
F_95 ( V_27 -> V_51 , V_60 , V_141 ) ;
}
static void F_140 ( struct V_26 * V_27 ,
struct V_125 * V_60 )
{
unsigned long V_136 = V_63 ;
if ( ! V_60 ) {
if ( V_27 -> V_143 == V_149 )
F_42 ( & V_27 -> V_146 ,
V_136 + V_27 -> V_206 ) ;
return;
}
if ( V_60 -> V_143 == V_144 ||
V_60 -> V_143 == V_145 )
return;
F_121 ( V_27 , V_60 ) ;
F_42 ( & V_60 -> V_146 ,
V_136 + V_27 -> V_206 ) ;
}
static void F_141 ( struct V_26 * V_27 ,
struct V_125 * V_60 ,
struct V_162 * V_151 ,
struct V_1 * V_91 ,
unsigned long V_204 )
{
if ( ! F_137 ( V_27 , V_60 , V_91 ) )
return;
F_138 ( V_27 , V_151 , V_204 ) ;
F_140 ( V_27 , V_60 ) ;
}
static int F_142 ( struct V_26 * V_27 ,
struct V_125 * V_60 ,
struct V_28 * V_29 ,
T_3 V_5 )
{
const struct V_76 * V_77 = F_18 ( V_29 ) ;
struct V_72 * V_73 = F_61 ( V_29 ) ;
struct V_20 * V_23 ;
struct V_209 * V_210 ;
struct V_47 * V_48 ;
struct V_47 T_4 * * V_58 ;
struct V_1 V_91 ;
unsigned long V_204 ;
unsigned long V_136 = V_63 ;
unsigned int V_211 = F_126 ( V_29 ) ;
T_1 V_70 ;
int V_66 = 0 ;
F_29 ( & V_27 -> V_50 ) ;
if ( ! F_30 ( V_27 -> V_51 ) ||
( V_60 && V_60 -> V_137 == V_138 ) )
goto V_53;
V_70 = V_73 -> V_70 ;
if ( V_29 -> V_42 == V_211 + sizeof( * V_73 ) ) {
V_204 = V_73 -> V_97 * ( V_100 / V_101 ) ;
if ( ! V_204 ) {
V_204 = 10 * V_100 ;
V_70 = 0 ;
}
} else if ( V_29 -> V_42 >= V_211 + sizeof( * V_210 ) ) {
V_210 = F_143 ( V_29 ) ;
if ( V_210 -> V_195 )
goto V_53;
V_204 = V_210 -> V_97 ?
F_144 ( V_210 -> V_97 ) * ( V_100 / V_101 ) : 1 ;
} else {
goto V_53;
}
if ( ! V_70 ) {
V_91 . V_4 = F_2 ( V_6 ) ;
V_91 . V_7 . V_8 = V_77 -> V_91 ;
F_141 ( V_27 , V_60 , & V_27 -> V_165 ,
& V_91 , V_204 ) ;
goto V_53;
}
V_23 = F_13 ( F_32 ( V_27 -> V_13 , V_27 ) , V_70 , V_5 ) ;
if ( ! V_23 )
goto V_53;
V_204 *= V_27 -> V_212 ;
if ( V_23 -> V_54 &&
( F_31 ( & V_23 -> V_52 ) ?
F_145 ( V_23 -> V_52 . V_213 , V_136 + V_204 ) :
F_119 ( & V_23 -> V_52 ) >= 0 ) )
F_42 ( & V_23 -> V_52 , V_136 + V_204 ) ;
for ( V_58 = & V_23 -> V_55 ;
( V_48 = F_32 ( * V_58 , V_27 ) ) != NULL ;
V_58 = & V_48 -> V_59 ) {
if ( F_31 ( & V_48 -> V_52 ) ?
F_145 ( V_48 -> V_52 . V_213 , V_136 + V_204 ) :
F_119 ( & V_48 -> V_52 ) >= 0 )
F_42 ( & V_48 -> V_52 , V_136 + V_204 ) ;
}
V_53:
F_35 ( & V_27 -> V_50 ) ;
return V_66 ;
}
static int F_146 ( struct V_26 * V_27 ,
struct V_125 * V_60 ,
struct V_28 * V_29 ,
T_3 V_5 )
{
const struct V_104 * V_105 = F_19 ( V_29 ) ;
struct V_106 * V_214 ;
struct V_20 * V_23 ;
struct V_215 * V_216 ;
struct V_47 * V_48 ;
struct V_47 T_4 * * V_58 ;
struct V_1 V_91 ;
unsigned long V_204 ;
unsigned long V_136 = V_63 ;
unsigned int V_211 = F_126 ( V_29 ) ;
const struct V_19 * V_70 = NULL ;
bool V_217 ;
int V_66 = 0 ;
F_29 ( & V_27 -> V_50 ) ;
if ( ! F_30 ( V_27 -> V_51 ) ||
( V_60 && V_60 -> V_137 == V_138 ) )
goto V_53;
if ( V_29 -> V_42 == V_211 + sizeof( * V_214 ) ) {
if ( ! F_127 ( V_29 , V_211 + sizeof( * V_214 ) ) ) {
V_66 = - V_46 ;
goto V_53;
}
V_214 = (struct V_106 * ) F_70 ( V_29 ) ;
V_204 = F_147 ( F_125 ( V_214 -> V_122 ) ) ;
if ( V_204 )
V_70 = & V_214 -> V_124 ;
} else {
if ( ! F_127 ( V_29 , V_211 + sizeof( * V_216 ) ) ) {
V_66 = - V_46 ;
goto V_53;
}
V_216 = (struct V_215 * ) F_70 ( V_29 ) ;
if ( ! V_216 -> V_218 )
V_70 = & V_216 -> V_219 ;
V_204 = V_18 ( F_147 ( F_148 ( V_216 ) ) , 1UL ) ;
}
V_217 = V_70 && F_71 ( V_70 ) ;
if ( V_217 ) {
V_91 . V_4 = F_2 ( V_10 ) ;
V_91 . V_7 . V_11 = V_105 -> V_91 ;
F_141 ( V_27 , V_60 , & V_27 -> V_166 ,
& V_91 , V_204 ) ;
goto V_53;
} else if ( ! V_70 ) {
goto V_53;
}
V_23 = F_14 ( F_32 ( V_27 -> V_13 , V_27 ) , V_70 , V_5 ) ;
if ( ! V_23 )
goto V_53;
V_204 *= V_27 -> V_212 ;
if ( V_23 -> V_54 &&
( F_31 ( & V_23 -> V_52 ) ?
F_145 ( V_23 -> V_52 . V_213 , V_136 + V_204 ) :
F_119 ( & V_23 -> V_52 ) >= 0 ) )
F_42 ( & V_23 -> V_52 , V_136 + V_204 ) ;
for ( V_58 = & V_23 -> V_55 ;
( V_48 = F_32 ( * V_58 , V_27 ) ) != NULL ;
V_58 = & V_48 -> V_59 ) {
if ( F_31 ( & V_48 -> V_52 ) ?
F_145 ( V_48 -> V_52 . V_213 , V_136 + V_204 ) :
F_119 ( & V_48 -> V_52 ) >= 0 )
F_42 ( & V_48 -> V_52 , V_136 + V_204 ) ;
}
V_53:
F_35 ( & V_27 -> V_50 ) ;
return V_66 ;
}
static void
F_149 ( struct V_26 * V_27 ,
struct V_125 * V_60 ,
struct V_1 * V_70 ,
struct V_162 * V_163 ,
struct V_150 * V_161 )
{
struct V_12 * V_13 ;
struct V_20 * V_23 ;
struct V_47 * V_48 ;
unsigned long V_136 ;
unsigned long time ;
F_29 ( & V_27 -> V_50 ) ;
if ( ! F_30 ( V_27 -> V_51 ) ||
( V_60 && V_60 -> V_137 == V_138 ) )
goto V_53;
V_13 = F_32 ( V_27 -> V_13 , V_27 ) ;
V_23 = F_12 ( V_13 , V_70 ) ;
if ( ! V_23 )
goto V_53;
if ( V_60 && ( V_60 -> V_62 & V_220 ) ) {
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
if ( F_31 ( & V_163 -> V_52 ) )
goto V_53;
if ( V_27 -> V_164 ) {
F_102 ( V_27 , V_60 , & V_23 -> V_24 ) ;
time = V_63 + V_27 -> V_212 *
V_27 -> V_98 ;
F_42 ( & V_161 -> V_52 , time ) ;
for ( V_48 = F_32 ( V_23 -> V_55 , V_27 ) ;
V_48 != NULL ;
V_48 = F_32 ( V_48 -> V_59 , V_27 ) ) {
if ( V_48 -> V_60 != V_60 )
continue;
if ( ! F_44 ( & V_48 -> V_54 ) &&
( F_31 ( & V_48 -> V_52 ) ?
F_145 ( V_48 -> V_52 . V_213 , time ) :
F_119 ( & V_48 -> V_52 ) >= 0 ) ) {
F_42 ( & V_48 -> V_52 , time ) ;
}
break;
}
}
V_136 = V_63 ;
time = V_136 + V_27 -> V_212 *
V_27 -> V_98 ;
if ( ! V_60 ) {
if ( V_23 -> V_54 &&
( F_31 ( & V_23 -> V_52 ) ?
F_145 ( V_23 -> V_52 . V_213 , time ) :
F_119 ( & V_23 -> V_52 ) >= 0 ) ) {
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
F_145 ( V_48 -> V_52 . V_213 , time ) :
F_119 ( & V_48 -> V_52 ) >= 0 ) ) {
F_42 ( & V_48 -> V_52 , time ) ;
}
break;
}
V_53:
F_35 ( & V_27 -> V_50 ) ;
}
static void F_128 ( struct V_26 * V_27 ,
struct V_125 * V_60 ,
T_1 V_70 ,
T_2 V_5 )
{
struct V_1 V_142 ;
struct V_150 * V_161 ;
if ( F_90 ( V_70 ) )
return;
V_161 = V_60 ? & V_60 -> V_152 : & V_27 -> V_152 ;
V_142 . V_7 . V_8 = V_70 ;
V_142 . V_4 = F_2 ( V_6 ) ;
V_142 . V_5 = V_5 ;
F_149 ( V_27 , V_60 , & V_142 , & V_27 -> V_165 ,
V_161 ) ;
}
static void F_132 ( struct V_26 * V_27 ,
struct V_125 * V_60 ,
const struct V_19 * V_70 ,
T_2 V_5 )
{
struct V_1 V_142 ;
struct V_150 * V_161 ;
if ( F_92 ( V_70 ) )
return;
V_161 = V_60 ? & V_60 -> V_153 : & V_27 -> V_153 ;
V_142 . V_7 . V_11 = * V_70 ;
V_142 . V_4 = F_2 ( V_10 ) ;
V_142 . V_5 = V_5 ;
F_149 ( V_27 , V_60 , & V_142 , & V_27 -> V_166 ,
V_161 ) ;
}
static void F_150 ( const struct V_26 * V_27 ,
const struct V_125 * V_48 ,
T_6 V_4 )
{
struct V_173 T_7 * V_221 ;
struct V_173 * V_222 ;
if ( ! V_27 -> V_223 )
return;
if ( V_48 )
V_221 = V_48 -> V_172 ;
else
V_221 = V_27 -> V_172 ;
if ( F_37 ( ! V_221 ) )
return;
V_222 = F_151 ( V_221 ) ;
F_152 ( & V_222 -> V_224 ) ;
switch ( V_4 ) {
case F_2 ( V_6 ) :
V_222 -> V_225 . V_226 ++ ;
break;
#if F_3 ( V_9 )
case F_2 ( V_10 ) :
V_222 -> V_225 . V_227 ++ ;
break;
#endif
}
F_153 ( & V_222 -> V_224 ) ;
}
static int F_154 ( struct V_26 * V_27 ,
struct V_125 * V_60 ,
struct V_28 * V_29 ,
T_3 V_5 )
{
struct V_28 * V_228 = NULL ;
struct V_72 * V_73 ;
int V_66 ;
V_66 = F_155 ( V_29 , & V_228 ) ;
if ( V_66 == - V_229 ) {
if ( ! F_90 ( F_18 ( V_29 ) -> V_33 ) )
F_17 ( V_29 ) -> V_230 = 1 ;
return 0 ;
} else if ( V_66 < 0 ) {
F_150 ( V_27 , V_60 , V_29 -> V_32 ) ;
return V_66 ;
}
V_73 = F_61 ( V_29 ) ;
F_17 ( V_29 ) -> V_31 = V_73 -> type ;
switch ( V_73 -> type ) {
case V_231 :
case V_232 :
F_17 ( V_29 ) -> V_230 = 1 ;
V_66 = F_89 ( V_27 , V_60 , V_73 -> V_70 , V_5 ) ;
break;
case V_233 :
V_66 = F_123 ( V_27 , V_60 , V_228 , V_5 ) ;
break;
case V_96 :
V_66 = F_142 ( V_27 , V_60 , V_228 , V_5 ) ;
break;
case V_234 :
F_128 ( V_27 , V_60 , V_73 -> V_70 , V_5 ) ;
break;
}
if ( V_228 && V_228 != V_29 )
F_68 ( V_228 ) ;
F_103 ( V_27 , V_60 , V_29 , F_17 ( V_29 ) -> V_31 ,
V_160 ) ;
return V_66 ;
}
static int F_156 ( struct V_26 * V_27 ,
struct V_125 * V_60 ,
struct V_28 * V_29 ,
T_3 V_5 )
{
struct V_28 * V_228 = NULL ;
struct V_106 * V_214 ;
int V_66 ;
V_66 = F_157 ( V_29 , & V_228 ) ;
if ( V_66 == - V_229 ) {
if ( ! F_92 ( & F_19 ( V_29 ) -> V_33 ) )
F_17 ( V_29 ) -> V_230 = 1 ;
return 0 ;
} else if ( V_66 < 0 ) {
F_150 ( V_27 , V_60 , V_29 -> V_32 ) ;
return V_66 ;
}
V_214 = (struct V_106 * ) F_158 ( V_29 ) ;
F_17 ( V_29 ) -> V_31 = V_214 -> V_119 ;
switch ( V_214 -> V_119 ) {
case V_235 :
F_17 ( V_29 ) -> V_230 = 1 ;
V_66 = F_91 ( V_27 , V_60 , & V_214 -> V_124 , V_5 ) ;
break;
case V_236 :
V_66 = F_129 ( V_27 , V_60 , V_228 , V_5 ) ;
break;
case V_118 :
V_66 = F_146 ( V_27 , V_60 , V_228 , V_5 ) ;
break;
case V_237 :
F_132 ( V_27 , V_60 , & V_214 -> V_124 , V_5 ) ;
break;
}
if ( V_228 && V_228 != V_29 )
F_68 ( V_228 ) ;
F_103 ( V_27 , V_60 , V_29 , F_17 ( V_29 ) -> V_31 ,
V_160 ) ;
return V_66 ;
}
int F_159 ( struct V_26 * V_27 , struct V_125 * V_60 ,
struct V_28 * V_29 , T_3 V_5 )
{
int V_238 = 0 ;
F_17 ( V_29 ) -> V_31 = 0 ;
F_17 ( V_29 ) -> V_230 = 0 ;
if ( V_27 -> V_30 )
return 0 ;
switch ( V_29 -> V_32 ) {
case F_2 ( V_6 ) :
V_238 = F_154 ( V_27 , V_60 , V_29 , V_5 ) ;
break;
#if F_3 ( V_9 )
case F_2 ( V_10 ) :
V_238 = F_156 ( V_27 , V_60 , V_29 , V_5 ) ;
break;
#endif
}
return V_238 ;
}
static void F_160 ( struct V_26 * V_27 ,
struct V_150 * V_151 ,
struct V_239 * V_240 )
{
F_29 ( & V_27 -> V_50 ) ;
if ( V_151 -> V_167 < V_27 -> V_168 )
V_151 -> V_167 ++ ;
F_161 ( V_240 -> V_60 , NULL ) ;
F_106 ( V_27 , NULL , V_151 ) ;
F_35 ( & V_27 -> V_50 ) ;
}
static void F_162 ( unsigned long V_49 )
{
struct V_26 * V_27 = ( void * ) V_49 ;
F_160 ( V_27 , & V_27 -> V_152 , & V_27 -> V_154 ) ;
}
static void F_163 ( unsigned long V_49 )
{
struct V_26 * V_27 = ( void * ) V_49 ;
F_160 ( V_27 , & V_27 -> V_153 , & V_27 -> V_155 ) ;
}
void F_164 ( struct V_26 * V_27 )
{
V_27 -> V_127 = 4 ;
V_27 -> V_129 = 512 ;
V_27 -> V_143 = V_149 ;
V_27 -> V_164 = 0 ;
V_27 -> V_92 = 0 ;
V_27 -> V_212 = 2 ;
V_27 -> V_168 = 2 ;
V_27 -> V_98 = V_100 ;
V_27 -> V_99 = 10 * V_100 ;
V_27 -> V_169 = 125 * V_100 / 4 ;
V_27 -> V_170 = 125 * V_100 ;
V_27 -> V_206 = 255 * V_100 ;
V_27 -> V_139 = 260 * V_100 ;
V_27 -> V_165 . V_205 = 0 ;
V_27 -> V_154 . V_60 = NULL ;
#if F_3 ( V_9 )
V_27 -> V_166 . V_205 = 0 ;
V_27 -> V_155 . V_60 = NULL ;
#endif
V_27 -> V_114 = 1 ;
F_165 ( & V_27 -> V_50 ) ;
F_84 ( & V_27 -> V_146 ,
F_96 , 0 ) ;
F_84 ( & V_27 -> V_165 . V_52 ,
F_99 , ( unsigned long ) V_27 ) ;
F_84 ( & V_27 -> V_152 . V_52 , F_162 ,
( unsigned long ) V_27 ) ;
#if F_3 ( V_9 )
F_84 ( & V_27 -> V_166 . V_52 ,
F_100 , ( unsigned long ) V_27 ) ;
F_84 ( & V_27 -> V_153 . V_52 , F_163 ,
( unsigned long ) V_27 ) ;
#endif
}
static void F_166 ( struct V_26 * V_27 ,
struct V_150 * V_151 )
{
V_151 -> V_167 = 0 ;
if ( V_27 -> V_30 )
return;
F_42 ( & V_151 -> V_52 , V_63 ) ;
}
void F_167 ( struct V_26 * V_27 )
{
F_166 ( V_27 , & V_27 -> V_152 ) ;
#if F_3 ( V_9 )
F_166 ( V_27 , & V_27 -> V_153 ) ;
#endif
}
void F_168 ( struct V_26 * V_27 )
{
F_116 ( & V_27 -> V_146 ) ;
F_116 ( & V_27 -> V_165 . V_52 ) ;
F_116 ( & V_27 -> V_152 . V_52 ) ;
#if F_3 ( V_9 )
F_116 ( & V_27 -> V_166 . V_52 ) ;
F_116 ( & V_27 -> V_153 . V_52 ) ;
#endif
}
void F_169 ( struct V_26 * V_27 )
{
struct V_12 * V_13 ;
struct V_20 * V_23 ;
struct V_174 * V_175 ;
V_16 V_45 ;
int V_43 ;
F_113 ( & V_27 -> V_50 ) ;
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
F_115 ( & V_27 -> V_50 ) ;
F_170 () ;
F_113 ( & V_27 -> V_50 ) ;
F_37 ( V_13 -> V_37 ) ;
}
V_13 -> V_37 = V_13 ;
F_34 ( & V_13 -> V_36 , F_20 ) ;
V_53:
F_115 ( & V_27 -> V_50 ) ;
F_117 ( V_27 -> V_172 ) ;
}
int F_171 ( struct V_26 * V_27 , unsigned long V_241 )
{
int V_66 = - V_46 ;
F_113 ( & V_27 -> V_50 ) ;
switch ( V_241 ) {
case V_144 :
case V_145 :
F_40 ( & V_27 -> V_146 ) ;
case V_149 :
V_27 -> V_143 = V_241 ;
V_66 = 0 ;
break;
}
F_115 ( & V_27 -> V_50 ) ;
return V_66 ;
}
static void F_172 ( struct V_125 * V_48 )
{
if ( F_44 ( & V_48 -> V_147 ) )
return;
F_94 ( & V_48 -> V_147 ) ;
F_95 ( V_48 -> V_27 -> V_51 , V_48 , V_61 ) ;
}
int F_173 ( struct V_125 * V_48 , unsigned long V_241 )
{
struct V_26 * V_27 = V_48 -> V_27 ;
unsigned long V_136 = V_63 ;
int V_66 = - V_46 ;
F_29 ( & V_27 -> V_50 ) ;
if ( V_48 -> V_143 == V_241 ) {
if ( V_48 -> V_143 == V_148 )
F_42 ( & V_48 -> V_146 ,
V_136 + V_27 -> V_206 ) ;
V_66 = 0 ;
goto V_242;
}
switch ( V_241 ) {
case V_144 :
V_48 -> V_143 = V_144 ;
F_172 ( V_48 ) ;
F_40 ( & V_48 -> V_146 ) ;
break;
case V_149 :
V_48 -> V_143 = V_149 ;
F_172 ( V_48 ) ;
break;
case V_145 :
V_48 -> V_143 = V_145 ;
F_40 ( & V_48 -> V_146 ) ;
F_121 ( V_27 , V_48 ) ;
break;
case V_148 :
V_48 -> V_143 = V_148 ;
F_140 ( V_27 , V_48 ) ;
break;
default:
goto V_242;
}
V_66 = 0 ;
V_242:
F_35 ( & V_27 -> V_50 ) ;
return V_66 ;
}
static void F_98 ( struct V_26 * V_27 ,
struct V_150 * V_151 )
{
struct V_125 * V_60 ;
F_166 ( V_27 , V_151 ) ;
F_174 (port, &br->port_list, list) {
if ( V_60 -> V_137 == V_138 ||
V_60 -> V_137 == V_171 )
continue;
if ( V_151 == & V_27 -> V_152 )
F_118 ( & V_60 -> V_152 ) ;
#if F_3 ( V_9 )
else
F_118 ( & V_60 -> V_153 ) ;
#endif
}
}
int F_175 ( struct V_26 * V_27 , unsigned long V_241 )
{
int V_66 = 0 ;
struct V_12 * V_13 ;
F_113 ( & V_27 -> V_50 ) ;
if ( V_27 -> V_30 == ! V_241 )
goto V_242;
V_27 -> V_30 = ! V_241 ;
if ( V_27 -> V_30 )
goto V_242;
if ( ! F_30 ( V_27 -> V_51 ) )
goto V_242;
V_13 = F_32 ( V_27 -> V_13 , V_27 ) ;
if ( V_13 ) {
if ( V_13 -> V_37 ) {
V_66 = - V_132 ;
V_243:
V_27 -> V_30 = ! ! V_241 ;
goto V_242;
}
V_66 = F_45 ( & V_27 -> V_13 , V_13 -> V_18 ,
V_27 -> V_127 ) ;
if ( V_66 )
goto V_243;
}
F_98 ( V_27 , & V_27 -> V_152 ) ;
#if F_3 ( V_9 )
F_98 ( V_27 , & V_27 -> V_153 ) ;
#endif
V_242:
F_115 ( & V_27 -> V_50 ) ;
return V_66 ;
}
int F_176 ( struct V_26 * V_27 , unsigned long V_241 )
{
unsigned long V_204 ;
V_241 = ! ! V_241 ;
F_113 ( & V_27 -> V_50 ) ;
if ( V_27 -> V_164 == V_241 )
goto V_242;
V_27 -> V_164 = V_241 ;
if ( ! V_241 )
goto V_242;
V_204 = V_27 -> V_99 ;
if ( ! F_31 ( & V_27 -> V_165 . V_52 ) )
V_27 -> V_165 . V_205 = V_63 + V_204 ;
F_98 ( V_27 , & V_27 -> V_152 ) ;
#if F_3 ( V_9 )
if ( ! F_31 ( & V_27 -> V_166 . V_52 ) )
V_27 -> V_166 . V_205 = V_63 + V_204 ;
F_98 ( V_27 , & V_27 -> V_153 ) ;
#endif
V_242:
F_115 ( & V_27 -> V_50 ) ;
return 0 ;
}
int F_177 ( struct V_26 * V_27 , unsigned long V_241 )
{
int V_66 = - V_46 ;
V_16 V_37 ;
struct V_12 * V_13 ;
F_113 ( & V_27 -> V_50 ) ;
if ( ! F_178 ( V_241 ) )
goto V_242;
V_13 = F_32 ( V_27 -> V_13 , V_27 ) ;
if ( V_13 && V_241 < V_13 -> V_56 )
goto V_242;
V_66 = 0 ;
V_37 = V_27 -> V_129 ;
V_27 -> V_129 = V_241 ;
if ( V_13 ) {
if ( V_13 -> V_37 ) {
V_66 = - V_132 ;
V_243:
V_27 -> V_129 = V_37 ;
goto V_242;
}
V_66 = F_45 ( & V_27 -> V_13 , V_27 -> V_129 ,
V_27 -> V_127 ) ;
if ( V_66 )
goto V_243;
}
V_242:
F_115 ( & V_27 -> V_50 ) ;
return V_66 ;
}
int F_179 ( struct V_244 * V_51 ,
struct V_245 * V_246 )
{
struct V_26 * V_27 ;
struct V_125 * V_60 ;
struct V_47 * V_70 ;
struct V_246 * V_247 ;
int V_126 = 0 ;
F_180 () ;
if ( ! V_246 || ! F_181 ( V_51 ) )
goto V_242;
V_60 = F_182 ( V_51 ) ;
if ( ! V_60 || ! V_60 -> V_27 )
goto V_242;
V_27 = V_60 -> V_27 ;
F_183 (port, &br->port_list, list) {
if ( ! V_60 -> V_51 || V_60 -> V_51 == V_51 )
continue;
F_11 (group, &port->mglist, mglist) {
V_247 = F_47 ( sizeof( * V_247 ) , V_67 ) ;
if ( ! V_247 )
goto V_242;
V_247 -> V_24 = V_70 -> V_24 ;
F_184 ( & V_247 -> V_248 , V_246 ) ;
V_126 ++ ;
}
}
V_242:
F_185 () ;
return V_126 ;
}
bool F_186 ( struct V_244 * V_51 , int V_4 )
{
struct V_26 * V_27 ;
struct V_125 * V_60 ;
struct V_74 V_75 ;
bool V_238 = false ;
F_180 () ;
if ( ! F_181 ( V_51 ) )
goto V_242;
V_60 = F_182 ( V_51 ) ;
if ( ! V_60 || ! V_60 -> V_27 )
goto V_242;
V_27 = V_60 -> V_27 ;
memset ( & V_75 , 0 , sizeof( V_75 ) ) ;
V_75 . V_81 = F_2 ( V_4 ) ;
V_238 = F_187 ( V_27 , & V_75 ) ;
V_242:
F_185 () ;
return V_238 ;
}
bool F_188 ( struct V_244 * V_51 , int V_4 )
{
struct V_26 * V_27 ;
struct V_125 * V_60 ;
bool V_238 = false ;
F_180 () ;
if ( ! F_181 ( V_51 ) )
goto V_242;
V_60 = F_182 ( V_51 ) ;
if ( ! V_60 || ! V_60 -> V_27 )
goto V_242;
V_27 = V_60 -> V_27 ;
switch ( V_4 ) {
case V_6 :
if ( ! F_31 ( & V_27 -> V_165 . V_52 ) ||
F_16 ( V_27 -> V_154 . V_60 ) == V_60 )
goto V_242;
break;
#if F_3 ( V_9 )
case V_10 :
if ( ! F_31 ( & V_27 -> V_166 . V_52 ) ||
F_16 ( V_27 -> V_155 . V_60 ) == V_60 )
goto V_242;
break;
#endif
default:
goto V_242;
}
V_238 = true ;
V_242:
F_185 () ;
return V_238 ;
}
static void F_189 ( struct V_173 T_7 * V_221 ,
const struct V_28 * V_29 , T_5 type , T_5 V_249 )
{
struct V_173 * V_222 = F_151 ( V_221 ) ;
T_6 V_4 = V_29 -> V_32 ;
unsigned int V_250 ;
F_152 ( & V_222 -> V_224 ) ;
switch ( V_4 ) {
case F_2 ( V_6 ) :
V_250 = F_125 ( F_18 ( V_29 ) -> V_85 ) - F_190 ( V_29 ) ;
switch ( type ) {
case V_231 :
V_222 -> V_225 . V_251 [ V_249 ] ++ ;
break;
case V_232 :
V_222 -> V_225 . V_252 [ V_249 ] ++ ;
break;
case V_233 :
V_222 -> V_225 . V_253 [ V_249 ] ++ ;
break;
case V_96 :
if ( V_250 != sizeof( struct V_72 ) ) {
V_222 -> V_225 . V_254 [ V_249 ] ++ ;
} else {
unsigned int V_211 = F_126 ( V_29 ) ;
struct V_72 * V_73 , V_255 ;
V_73 = F_130 ( V_29 , V_211 ,
sizeof( V_255 ) , & V_255 ) ;
if ( ! V_73 )
break;
if ( ! V_73 -> V_97 )
V_222 -> V_225 . V_256 [ V_249 ] ++ ;
else
V_222 -> V_225 . V_257 [ V_249 ] ++ ;
}
break;
case V_234 :
V_222 -> V_225 . V_258 [ V_249 ] ++ ;
break;
}
break;
#if F_3 ( V_9 )
case F_2 ( V_10 ) :
V_250 = F_125 ( F_19 ( V_29 ) -> V_110 ) +
sizeof( struct V_104 ) ;
V_250 -= F_191 ( V_29 ) ;
switch ( type ) {
case V_235 :
V_222 -> V_225 . V_259 [ V_249 ] ++ ;
break;
case V_236 :
V_222 -> V_225 . V_260 [ V_249 ] ++ ;
break;
case V_118 :
if ( V_250 != sizeof( struct V_106 ) )
V_222 -> V_225 . V_261 [ V_249 ] ++ ;
else
V_222 -> V_225 . V_262 [ V_249 ] ++ ;
break;
case V_237 :
V_222 -> V_225 . V_263 [ V_249 ] ++ ;
break;
}
break;
#endif
}
F_153 ( & V_222 -> V_224 ) ;
}
void F_103 ( struct V_26 * V_27 , const struct V_125 * V_48 ,
const struct V_28 * V_29 , T_5 type , T_5 V_249 )
{
struct V_173 T_7 * V_221 ;
if ( ! type || ! V_27 -> V_223 )
return;
if ( V_48 )
V_221 = V_48 -> V_172 ;
else
V_221 = V_27 -> V_172 ;
if ( F_37 ( ! V_221 ) )
return;
F_189 ( V_221 , V_29 , type , V_249 ) ;
}
int F_192 ( struct V_26 * V_27 )
{
V_27 -> V_172 = F_111 ( struct V_173 ) ;
if ( ! V_27 -> V_172 )
return - V_68 ;
return 0 ;
}
static void F_193 ( T_8 * V_21 , T_8 * V_264 )
{
V_21 [ V_160 ] += V_264 [ V_160 ] ;
V_21 [ V_156 ] += V_264 [ V_156 ] ;
}
void F_194 ( const struct V_26 * V_27 ,
const struct V_125 * V_48 ,
struct V_265 * V_266 )
{
struct V_173 T_7 * V_221 ;
struct V_265 V_267 ;
int V_43 ;
memset ( V_266 , 0 , sizeof( * V_266 ) ) ;
if ( V_48 )
V_221 = V_48 -> V_172 ;
else
V_221 = V_27 -> V_172 ;
if ( F_37 ( ! V_221 ) )
return;
memset ( & V_267 , 0 , sizeof( V_267 ) ) ;
F_195 (i) {
struct V_173 * V_268 = F_196 ( V_221 , V_43 ) ;
struct V_265 V_269 ;
unsigned int V_270 ;
do {
V_270 = F_197 ( & V_268 -> V_224 ) ;
memcpy ( & V_269 , & V_268 -> V_225 , sizeof( V_269 ) ) ;
} while ( F_198 ( & V_268 -> V_224 , V_270 ) );
F_193 ( V_267 . V_256 , V_269 . V_256 ) ;
F_193 ( V_267 . V_257 , V_269 . V_257 ) ;
F_193 ( V_267 . V_254 , V_269 . V_254 ) ;
F_193 ( V_267 . V_258 , V_269 . V_258 ) ;
F_193 ( V_267 . V_251 , V_269 . V_251 ) ;
F_193 ( V_267 . V_252 , V_269 . V_252 ) ;
F_193 ( V_267 . V_253 , V_269 . V_253 ) ;
V_267 . V_226 += V_269 . V_226 ;
F_193 ( V_267 . V_262 , V_269 . V_262 ) ;
F_193 ( V_267 . V_261 , V_269 . V_261 ) ;
F_193 ( V_267 . V_263 , V_269 . V_263 ) ;
F_193 ( V_267 . V_259 , V_269 . V_259 ) ;
F_193 ( V_267 . V_260 , V_269 . V_260 ) ;
V_267 . V_227 += V_269 . V_227 ;
}
memcpy ( V_266 , & V_267 , sizeof( * V_266 ) ) ;
}
