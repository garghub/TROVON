static inline T_1 F_1 ( T_1 V_1 )
{
T_1 V_2 = V_1 ;
V_2 ^= ( V_1 >> 24 ) ;
return V_2 & ( V_3 - 1 ) ;
}
static unsigned int
F_2 ( void )
{
unsigned int V_4 ;
unsigned long V_5 = V_6 - V_7 ;
V_4 = ( 16 * F_3 ( V_5 ) ) << ( V_8 - 10 ) ;
return F_4 (unsigned int, limit, 256*1024 ) ;
}
static struct V_9 *
F_5 ( void )
{
struct V_9 * V_10 ;
V_10 = F_6 ( V_11 , V_12 ) ;
if ( V_10 ) {
V_10 -> V_13 = V_14 ;
V_10 -> V_15 = V_16 ;
F_7 ( & V_10 -> V_17 ) ;
F_8 ( & V_10 -> V_18 ) ;
}
return V_10 ;
}
static void
F_9 ( struct V_9 * V_10 )
{
if ( V_10 -> V_15 == V_19 )
F_10 ( V_10 -> V_20 . V_21 ) ;
if ( ! F_11 ( & V_10 -> V_18 ) )
F_12 ( & V_10 -> V_18 ) ;
F_13 ( & V_10 -> V_17 ) ;
-- V_22 ;
F_14 ( V_11 , V_10 ) ;
}
static void
F_15 ( struct V_9 * V_10 )
{
F_16 ( & V_23 ) ;
F_9 ( V_10 ) ;
F_17 ( & V_23 ) ;
}
int F_18 ( void )
{
F_7 ( & V_24 ) ;
V_25 = F_2 () ;
V_22 = 0 ;
F_19 ( & V_26 ) ;
V_11 = F_20 ( L_1 , sizeof( struct V_9 ) ,
0 , 0 , NULL ) ;
if ( ! V_11 )
goto V_27;
V_28 = F_21 ( V_3 , sizeof( struct V_29 ) , V_12 ) ;
if ( ! V_28 )
goto V_27;
return 0 ;
V_27:
F_22 ( V_30 L_2 ) ;
F_23 () ;
return - V_31 ;
}
void F_23 ( void )
{
struct V_9 * V_10 ;
F_24 ( & V_26 ) ;
F_25 ( & V_32 ) ;
while ( ! F_26 ( & V_24 ) ) {
V_10 = F_27 ( V_24 . V_33 , struct V_9 , V_17 ) ;
F_9 ( V_10 ) ;
}
F_10 ( V_28 ) ;
V_28 = NULL ;
if ( V_11 ) {
F_28 ( V_11 ) ;
V_11 = NULL ;
}
}
static void
F_29 ( struct V_9 * V_10 )
{
V_10 -> V_34 = V_35 ;
F_30 ( & V_10 -> V_17 , & V_24 ) ;
F_31 ( & V_32 , V_36 ) ;
}
static void
F_32 ( struct V_9 * V_10 )
{
F_33 ( & V_10 -> V_18 ) ;
F_34 ( & V_10 -> V_18 , V_28 + F_1 ( V_10 -> V_37 ) ) ;
}
static inline bool
F_35 ( struct V_9 * V_10 )
{
return V_10 -> V_13 != V_38 &&
F_36 ( V_35 , V_10 -> V_34 + V_36 ) ;
}
static void
F_37 ( void )
{
struct V_9 * V_10 , * V_39 ;
F_38 (rp, tmp, &lru_head, c_lru) {
if ( ! F_35 ( V_10 ) &&
V_22 <= V_25 )
break;
F_9 ( V_10 ) ;
}
if ( F_26 ( & V_24 ) )
F_39 ( & V_32 ) ;
else
F_40 ( V_40 , & V_32 , V_36 ) ;
}
static void
F_41 ( struct V_41 * V_42 )
{
F_16 ( & V_23 ) ;
F_37 () ;
F_17 ( & V_23 ) ;
}
static int
F_42 ( struct V_43 * V_44 , struct V_45 * V_46 )
{
unsigned int V_47 ;
F_16 ( & V_23 ) ;
if ( V_46 -> V_48 )
F_37 () ;
V_47 = V_22 ;
F_17 ( & V_23 ) ;
return V_47 ;
}
static T_2
F_43 ( struct V_49 * V_50 )
{
int V_51 ;
unsigned int V_52 ;
T_2 V_53 ;
struct V_54 * V_55 = & V_50 -> V_56 ;
const unsigned char * V_57 = V_55 -> V_58 [ 0 ] . V_21 ;
T_3 V_59 = F_4 ( T_3 , V_55 -> V_58 [ 0 ] . V_60 + V_55 -> V_61 ,
V_62 ) ;
T_3 V_63 = F_44 ( V_55 -> V_58 [ 0 ] . V_60 , V_59 ) ;
V_53 = F_45 ( V_57 , V_63 , 0 ) ;
V_59 -= V_63 ;
V_51 = V_55 -> V_64 / V_65 ;
V_52 = V_55 -> V_64 & ~ V_66 ;
while ( V_59 ) {
V_57 = F_46 ( V_55 -> V_67 [ V_51 ] ) + V_52 ;
V_63 = F_4 ( T_3 , V_65 - V_52 , V_59 ) ;
V_53 = F_45 ( V_57 , V_63 , V_53 ) ;
V_59 -= V_63 ;
V_52 = 0 ;
++ V_51 ;
}
return V_53 ;
}
static struct V_9 *
F_47 ( struct V_49 * V_50 , T_2 V_53 )
{
struct V_9 * V_10 ;
struct V_29 * V_68 ;
T_4 V_1 = V_50 -> V_69 ;
T_1 V_70 = V_50 -> V_71 ,
V_72 = V_50 -> V_73 ,
V_74 = V_50 -> V_75 ;
V_68 = & V_28 [ F_1 ( V_1 ) ] ;
F_48 (rp, rh, c_hash) {
if ( V_1 == V_10 -> V_37 && V_74 == V_10 -> V_76 &&
V_70 == V_10 -> V_77 && V_72 == V_10 -> V_78 &&
V_50 -> V_56 . V_63 == V_10 -> V_79 && V_53 == V_10 -> V_80 &&
F_49 ( F_50 ( V_50 ) , (struct V_81 * ) & V_10 -> V_82 ) &&
F_51 ( F_50 ( V_50 ) ) == F_51 ( (struct V_81 * ) & V_10 -> V_82 ) )
return V_10 ;
}
return NULL ;
}
int
F_52 ( struct V_49 * V_50 )
{
struct V_9 * V_10 , * V_83 ;
T_4 V_1 = V_50 -> V_69 ;
T_1 V_70 = V_50 -> V_71 ,
V_72 = V_50 -> V_73 ,
V_74 = V_50 -> V_75 ;
T_2 V_53 ;
unsigned long V_84 ;
int type = V_50 -> V_85 ;
int V_86 ;
V_50 -> V_87 = NULL ;
if ( type == V_16 ) {
V_88 . V_89 ++ ;
return V_90 ;
}
V_53 = F_43 ( V_50 ) ;
F_16 ( & V_23 ) ;
V_86 = V_90 ;
V_10 = F_47 ( V_50 , V_53 ) ;
if ( V_10 )
goto V_91;
if ( ! F_26 ( & V_24 ) ) {
V_10 = F_53 ( & V_24 , struct V_9 , V_17 ) ;
if ( F_35 ( V_10 ) ||
V_22 >= V_25 ) {
F_29 ( V_10 ) ;
F_37 () ;
goto V_92;
}
}
F_17 ( & V_23 ) ;
V_10 = F_5 () ;
if ( ! V_10 ) {
F_54 ( L_3 ) ;
return V_90 ;
}
F_16 ( & V_23 ) ;
++ V_22 ;
V_83 = F_47 ( V_50 , V_53 ) ;
if ( V_83 ) {
F_9 ( V_10 ) ;
V_10 = V_83 ;
goto V_91;
}
if ( V_22 >= V_25 )
F_9 ( F_53 ( & V_24 ,
struct V_9 , V_17 ) ) ;
V_92:
V_88 . V_93 ++ ;
V_50 -> V_87 = V_10 ;
V_10 -> V_13 = V_38 ;
V_10 -> V_37 = V_1 ;
V_10 -> V_76 = V_74 ;
F_55 ( (struct V_81 * ) & V_10 -> V_82 , F_50 ( V_50 ) ) ;
F_56 ( (struct V_81 * ) & V_10 -> V_82 , F_51 ( F_50 ( V_50 ) ) ) ;
V_10 -> V_77 = V_70 ;
V_10 -> V_78 = V_72 ;
V_10 -> V_79 = V_50 -> V_56 . V_63 ;
V_10 -> V_80 = V_53 ;
F_32 ( V_10 ) ;
F_29 ( V_10 ) ;
if ( V_10 -> V_15 == V_19 ) {
F_10 ( V_10 -> V_20 . V_21 ) ;
V_10 -> V_20 . V_21 = NULL ;
}
V_10 -> V_15 = V_16 ;
V_94:
F_17 ( & V_23 ) ;
return V_86 ;
V_91:
V_88 . V_95 ++ ;
V_84 = V_35 - V_10 -> V_34 ;
F_29 ( V_10 ) ;
V_86 = V_96 ;
if ( V_10 -> V_13 == V_38 || V_84 < V_97 )
goto V_94;
V_86 = V_90 ;
if ( ! V_50 -> V_98 && V_10 -> V_99 )
goto V_94;
switch ( V_10 -> V_15 ) {
case V_16 :
break;
case V_100 :
F_57 ( & V_50 -> V_101 . V_58 [ 0 ] , V_10 -> V_102 ) ;
V_86 = V_103 ;
break;
case V_19 :
if ( ! F_58 ( V_50 , & V_10 -> V_20 ) )
goto V_94;
V_86 = V_103 ;
break;
default:
F_22 ( V_104 L_4 , V_10 -> V_15 ) ;
F_9 ( V_10 ) ;
}
goto V_94;
}
void
F_59 ( struct V_49 * V_50 , int V_105 , T_4 * V_106 )
{
struct V_9 * V_10 = V_50 -> V_87 ;
struct V_107 * V_108 = & V_50 -> V_101 . V_58 [ 0 ] , * V_109 ;
int V_63 ;
if ( ! V_10 )
return;
V_63 = V_108 -> V_60 - ( ( char * ) V_106 - ( char * ) V_108 -> V_21 ) ;
V_63 >>= 2 ;
if ( ! V_106 || V_63 > ( 256 >> 2 ) ) {
F_15 ( V_10 ) ;
return;
}
switch ( V_105 ) {
case V_100 :
if ( V_63 != 1 )
F_22 ( L_5 , V_63 ) ;
V_10 -> V_102 = * V_106 ;
break;
case V_19 :
V_109 = & V_10 -> V_20 ;
V_109 -> V_21 = F_60 ( V_63 << 2 , V_12 ) ;
if ( ! V_109 -> V_21 ) {
F_15 ( V_10 ) ;
return;
}
V_109 -> V_60 = V_63 << 2 ;
memcpy ( V_109 -> V_21 , V_106 , V_63 << 2 ) ;
break;
case V_16 :
F_15 ( V_10 ) ;
return;
}
F_16 ( & V_23 ) ;
F_29 ( V_10 ) ;
V_10 -> V_99 = V_50 -> V_98 ;
V_10 -> V_15 = V_105 ;
V_10 -> V_13 = V_110 ;
F_17 ( & V_23 ) ;
return;
}
static int
F_58 ( struct V_49 * V_50 , struct V_107 * V_111 )
{
struct V_107 * V_112 = & V_50 -> V_101 . V_58 [ 0 ] ;
if ( V_112 -> V_60 + V_111 -> V_60 > V_65 ) {
F_22 ( V_104 L_6 ,
V_111 -> V_60 ) ;
return 0 ;
}
memcpy ( ( char * ) V_112 -> V_21 + V_112 -> V_60 , V_111 -> V_21 , V_111 -> V_60 ) ;
V_112 -> V_60 += V_111 -> V_60 ;
return 1 ;
}
