static void F_1 ( const void * V_1 , T_1 V_2 , T_2 V_3 )
{
void * V_4 , * V_5 ;
V_4 = F_2 ( V_1 ) ;
V_5 = F_2 ( V_1 + V_2 ) ;
memset ( V_4 , V_3 , V_5 - V_4 ) ;
}
void F_3 ( const void * V_1 , T_1 V_2 )
{
F_1 ( V_1 , V_2 , 0 ) ;
if ( V_2 & V_6 ) {
T_2 * V_7 = ( T_2 * ) F_2 ( V_1 + V_2 ) ;
* V_7 = V_2 & V_6 ;
}
}
static void F_4 ( struct V_8 * V_9 , void * V_10 )
{
void * V_11 = F_5 ( V_9 ) ;
T_1 V_2 = V_10 - V_11 ;
F_3 ( V_11 , V_2 ) ;
}
void F_6 ( struct V_8 * V_9 )
{
F_4 ( V_9 , F_5 ( V_9 ) + V_12 ) ;
}
T_3 void F_7 ( void * V_10 )
{
F_4 ( V_13 , V_10 ) ;
}
static T_4 bool F_8 ( unsigned long V_14 )
{
T_5 V_15 = * ( T_5 * ) F_2 ( ( void * ) V_14 ) ;
if ( F_9 ( V_15 ) ) {
T_5 V_16 = V_14 & V_6 ;
return F_9 ( V_16 >= V_15 ) ;
}
return false ;
}
static T_4 bool F_10 ( unsigned long V_14 )
{
T_6 * V_17 = ( T_6 * ) F_2 ( ( void * ) V_14 ) ;
if ( F_9 ( * V_17 ) ) {
if ( F_8 ( V_14 + 1 ) )
return true ;
if ( F_11 ( ( ( V_14 + 1 ) & V_6 ) != 0 ) )
return false ;
return F_9 ( * ( T_2 * ) V_17 ) ;
}
return false ;
}
static T_4 bool F_12 ( unsigned long V_14 )
{
T_6 * V_17 = ( T_6 * ) F_2 ( ( void * ) V_14 ) ;
if ( F_9 ( * V_17 ) ) {
if ( F_8 ( V_14 + 3 ) )
return true ;
if ( F_11 ( ( ( V_14 + 3 ) & V_6 ) >= 3 ) )
return false ;
return F_9 ( * ( T_2 * ) V_17 ) ;
}
return false ;
}
static T_4 bool F_13 ( unsigned long V_14 )
{
T_6 * V_17 = ( T_6 * ) F_2 ( ( void * ) V_14 ) ;
if ( F_9 ( * V_17 ) ) {
if ( F_8 ( V_14 + 7 ) )
return true ;
if ( F_11 ( F_14 ( V_14 , V_18 ) ) )
return false ;
return F_9 ( * ( T_2 * ) V_17 ) ;
}
return false ;
}
static T_4 bool F_15 ( unsigned long V_14 )
{
T_7 * V_17 = ( T_7 * ) F_2 ( ( void * ) V_14 ) ;
if ( F_9 ( * V_17 ) ) {
T_6 V_19 = * ( T_6 * ) V_17 ;
if ( F_9 ( V_19 ) )
return true ;
if ( F_11 ( F_14 ( V_14 , V_18 ) ) )
return false ;
return F_8 ( V_14 + 15 ) ;
}
return false ;
}
static T_4 unsigned long F_16 ( const T_2 * V_20 ,
T_1 V_2 )
{
while ( V_2 ) {
if ( F_9 ( * V_20 ) )
return ( unsigned long ) V_20 ;
V_20 ++ ;
V_2 -- ;
}
return 0 ;
}
static T_4 unsigned long F_17 ( const void * V_20 ,
const void * V_21 )
{
unsigned int V_22 ;
unsigned long V_23 ;
unsigned int V_24 = ( unsigned long ) V_20 % 8 ;
if ( V_21 - V_20 <= 16 )
return F_16 ( V_20 , V_21 - V_20 ) ;
if ( V_24 ) {
V_24 = 8 - V_24 ;
V_23 = F_16 ( V_20 , V_24 ) ;
if ( F_9 ( V_23 ) )
return V_23 ;
V_20 += V_24 ;
}
V_22 = ( V_21 - V_20 ) / 8 ;
while ( V_22 ) {
if ( F_9 ( * ( V_25 * ) V_20 ) )
return F_16 ( V_20 , 8 ) ;
V_20 += 8 ;
V_22 -- ;
}
return F_16 ( V_20 , ( V_21 - V_20 ) % 8 ) ;
}
static T_4 bool F_18 ( unsigned long V_14 ,
T_1 V_2 )
{
unsigned long V_23 ;
V_23 = F_17 ( F_2 ( ( void * ) V_14 ) ,
F_2 ( ( void * ) V_14 + V_2 - 1 ) + 1 ) ;
if ( F_9 ( V_23 ) ) {
unsigned long V_26 = V_14 + V_2 - 1 ;
T_5 * V_27 = ( T_5 * ) F_2 ( ( void * ) V_26 ) ;
if ( F_9 ( V_23 != ( unsigned long ) V_27 ||
( ( long ) ( V_26 & V_6 ) >= * V_27 ) ) )
return true ;
}
return false ;
}
static T_4 bool F_19 ( unsigned long V_14 , T_1 V_2 )
{
if ( F_20 ( V_2 ) ) {
switch ( V_2 ) {
case 1 :
return F_8 ( V_14 ) ;
case 2 :
return F_10 ( V_14 ) ;
case 4 :
return F_12 ( V_14 ) ;
case 8 :
return F_13 ( V_14 ) ;
case 16 :
return F_15 ( V_14 ) ;
default:
F_21 () ;
}
}
return F_18 ( V_14 , V_2 ) ;
}
static T_4 void F_22 ( unsigned long V_14 ,
T_1 V_2 , bool V_28 )
{
if ( F_9 ( V_2 == 0 ) )
return;
if ( F_9 ( ( void * ) V_14 <
F_23 ( ( void * ) V_29 ) ) ) {
F_24 ( V_14 , V_2 , V_28 , V_30 ) ;
return;
}
if ( F_11 ( ! F_19 ( V_14 , V_2 ) ) )
return;
F_24 ( V_14 , V_2 , V_28 , V_30 ) ;
}
void * memset ( void * V_14 , int V_31 , T_1 V_32 )
{
F_25 ( ( unsigned long ) V_14 , V_32 ) ;
return F_26 ( V_14 , V_31 , V_32 ) ;
}
void * memmove ( void * V_33 , const void * V_34 , T_1 V_32 )
{
F_27 ( ( unsigned long ) V_34 , V_32 ) ;
F_25 ( ( unsigned long ) V_33 , V_32 ) ;
return F_28 ( V_33 , V_34 , V_32 ) ;
}
void * memcpy ( void * V_33 , const void * V_34 , T_1 V_32 )
{
F_27 ( ( unsigned long ) V_34 , V_32 ) ;
F_25 ( ( unsigned long ) V_33 , V_32 ) ;
return F_29 ( V_33 , V_34 , V_32 ) ;
}
void F_30 ( struct V_35 * V_35 , unsigned int V_36 )
{
if ( F_11 ( ! F_31 ( V_35 ) ) )
F_3 ( F_32 ( V_35 ) , V_37 << V_36 ) ;
}
void F_33 ( struct V_35 * V_35 , unsigned int V_36 )
{
if ( F_11 ( ! F_31 ( V_35 ) ) )
F_1 ( F_32 ( V_35 ) ,
V_37 << V_36 ,
V_38 ) ;
}
static T_1 F_34 ( T_1 V_39 )
{
int V_40 =
V_39 <= 64 - 16 ? 16 :
V_39 <= 128 - 32 ? 32 :
V_39 <= 512 - 64 ? 64 :
V_39 <= 4096 - 128 ? 128 :
V_39 <= ( 1 << 14 ) - 256 ? 256 :
V_39 <= ( 1 << 15 ) - 512 ? 512 :
V_39 <= ( 1 << 16 ) - 1024 ? 1024 : 2048 ;
return V_40 ;
}
void F_35 ( struct V_41 * V_42 , T_1 * V_2 ,
unsigned long * V_43 )
{
int V_44 ;
if ( * V_2 > V_45 -
sizeof( struct V_46 ) -
sizeof( struct V_47 ) )
return;
* V_43 |= V_48 ;
V_42 -> V_49 . V_50 = * V_2 ;
* V_2 += sizeof( struct V_46 ) ;
if ( V_42 -> V_43 & V_51 || V_42 -> V_52 ||
V_42 -> V_39 < sizeof( struct V_47 ) ) {
V_42 -> V_49 . V_53 = * V_2 ;
* V_2 += sizeof( struct V_47 ) ;
}
V_44 = F_34 ( V_42 -> V_39 ) -
( * V_2 - V_42 -> V_39 ) ;
if ( V_44 > 0 )
* V_2 += V_44 ;
* V_2 = F_36 ( V_45 ,
F_37 ( * V_2 ,
V_42 -> V_39 +
F_34 ( V_42 -> V_39 ) ) ) ;
}
void F_38 ( struct V_35 * V_35 )
{
F_1 ( F_32 ( V_35 ) ,
V_37 << F_39 ( V_35 ) ,
V_54 ) ;
}
void F_40 ( struct V_41 * V_42 , void * V_55 )
{
F_3 ( V_55 , V_42 -> V_39 ) ;
}
void F_41 ( struct V_41 * V_42 , void * V_55 )
{
F_1 ( V_55 ,
F_42 ( V_42 -> V_39 , V_18 ) ,
V_54 ) ;
#ifdef F_43
if ( V_42 -> V_43 & V_48 ) {
struct V_46 * V_56 =
F_44 ( V_42 , V_55 ) ;
V_56 -> V_57 = V_58 ;
}
#endif
}
static inline int F_45 ( unsigned long V_59 )
{
return ( V_59 >= ( unsigned long ) & V_60 &&
V_59 < ( unsigned long ) & V_61 ) ||
( V_59 >= ( unsigned long ) & V_62 &&
V_59 < ( unsigned long ) & V_63 ) ;
}
static inline void F_46 ( struct V_64 * V_65 )
{
int V_66 ;
if ( ! V_65 -> V_67 )
return;
for ( V_66 = 0 ; V_66 < V_65 -> V_67 ; V_66 ++ )
if ( F_45 ( V_65 -> V_68 [ V_66 ] ) ) {
V_65 -> V_67 = V_66 + 1 ;
break;
}
}
static inline T_8 F_47 ( T_9 V_43 )
{
unsigned long V_68 [ V_69 ] ;
struct V_64 V_65 = {
. V_67 = 0 ,
. V_68 = V_68 ,
. V_70 = V_69 ,
. V_71 = 0
} ;
F_48 ( & V_65 ) ;
F_46 ( & V_65 ) ;
if ( V_65 . V_67 != 0 &&
V_65 . V_68 [ V_65 . V_67 - 1 ] == V_72 )
V_65 . V_67 -- ;
return F_49 ( & V_65 , V_43 ) ;
}
static inline void F_50 ( struct V_73 * V_74 , T_9 V_43 )
{
V_74 -> V_75 = V_13 -> V_75 ;
V_74 -> V_76 = F_47 ( V_43 ) ;
}
struct V_46 * F_44 ( struct V_41 * V_42 ,
const void * V_55 )
{
F_51 ( sizeof( struct V_46 ) > 32 ) ;
return ( void * ) V_55 + V_42 -> V_49 . V_50 ;
}
struct V_47 * F_52 ( struct V_41 * V_42 ,
const void * V_55 )
{
F_51 ( sizeof( struct V_47 ) > 32 ) ;
return ( void * ) V_55 + V_42 -> V_49 . V_53 ;
}
void F_53 ( struct V_41 * V_42 , void * V_55 , T_9 V_43 )
{
F_54 ( V_42 , V_55 , V_42 -> V_39 , V_43 ) ;
}
void F_55 ( struct V_41 * V_42 , void * V_55 )
{
unsigned long V_2 = V_42 -> V_39 ;
unsigned long V_77 = F_42 ( V_2 , V_18 ) ;
if ( F_9 ( V_42 -> V_43 & V_51 ) )
return;
#ifdef F_43
if ( V_42 -> V_43 & V_48 ) {
struct V_47 * V_78 =
F_52 ( V_42 , V_55 ) ;
struct V_46 * V_56 =
F_44 ( V_42 , V_55 ) ;
V_56 -> V_57 = V_79 ;
F_50 ( & V_78 -> V_74 , V_80 ) ;
}
#endif
F_1 ( V_55 , V_77 , V_81 ) ;
}
void F_54 ( struct V_41 * V_42 , const void * V_55 , T_1 V_2 ,
T_9 V_43 )
{
unsigned long V_82 ;
unsigned long V_83 ;
if ( F_9 ( V_55 == NULL ) )
return;
V_82 = F_42 ( ( unsigned long ) ( V_55 + V_2 ) ,
V_18 ) ;
V_83 = F_42 ( ( unsigned long ) V_55 + V_42 -> V_39 ,
V_18 ) ;
F_3 ( V_55 , V_2 ) ;
F_1 ( ( void * ) V_82 , V_83 - V_82 ,
V_54 ) ;
#ifdef F_43
if ( V_42 -> V_43 & V_48 ) {
struct V_46 * V_56 =
F_44 ( V_42 , V_55 ) ;
V_56 -> V_57 = V_84 ;
V_56 -> V_85 = V_2 ;
F_50 ( & V_56 -> V_74 , V_43 ) ;
}
#endif
}
void F_56 ( const void * V_59 , T_1 V_2 , T_9 V_43 )
{
struct V_35 * V_35 ;
unsigned long V_82 ;
unsigned long V_83 ;
if ( F_9 ( V_59 == NULL ) )
return;
V_35 = F_57 ( V_59 ) ;
V_82 = F_42 ( ( unsigned long ) ( V_59 + V_2 ) ,
V_18 ) ;
V_83 = ( unsigned long ) V_59 + ( V_37 << F_39 ( V_35 ) ) ;
F_3 ( V_59 , V_2 ) ;
F_1 ( ( void * ) V_82 , V_83 - V_82 ,
V_86 ) ;
}
void F_58 ( const void * V_55 , T_1 V_2 , T_9 V_43 )
{
struct V_35 * V_35 ;
if ( F_9 ( V_55 == V_87 ) )
return;
V_35 = F_59 ( V_55 ) ;
if ( F_9 ( ! F_60 ( V_35 ) ) )
F_56 ( V_55 , V_2 , V_43 ) ;
else
F_54 ( V_35 -> V_88 , V_55 , V_2 , V_43 ) ;
}
void F_61 ( void * V_59 )
{
struct V_35 * V_35 ;
V_35 = F_59 ( V_59 ) ;
if ( F_9 ( ! F_60 ( V_35 ) ) )
F_1 ( V_59 , V_37 << F_39 ( V_35 ) ,
V_38 ) ;
else
F_55 ( V_35 -> V_88 , V_59 ) ;
}
void F_62 ( const void * V_59 )
{
struct V_35 * V_35 = F_57 ( V_59 ) ;
F_1 ( V_59 , V_37 << F_39 ( V_35 ) ,
V_38 ) ;
}
int F_63 ( void * V_14 , T_1 V_2 )
{
void * V_23 ;
T_1 V_89 ;
unsigned long V_4 ;
V_4 = ( unsigned long ) F_2 ( V_14 ) ;
V_89 = F_42 ( V_2 >> V_90 ,
V_37 ) ;
if ( F_64 ( ! F_65 ( V_4 ) ) )
return - V_91 ;
V_23 = F_66 ( V_89 , 1 , V_4 ,
V_4 + V_89 ,
V_92 | V_93 | V_94 ,
V_95 , V_96 , V_97 ,
F_67 ( 0 ) ) ;
if ( V_23 ) {
F_68 ( V_14 ) -> V_43 |= V_98 ;
F_69 ( V_23 ) ;
return 0 ;
}
return - V_99 ;
}
void F_70 ( const struct V_100 * V_101 )
{
if ( V_101 -> V_43 & V_98 )
F_71 ( F_2 ( V_101 -> V_14 ) ) ;
}
static void F_72 ( struct V_102 * V_103 )
{
T_1 V_104 = F_42 ( V_103 -> V_2 , V_18 ) ;
F_3 ( V_103 -> V_105 , V_103 -> V_2 ) ;
F_1 ( V_103 -> V_105 + V_104 ,
V_103 -> V_106 - V_104 ,
V_107 ) ;
}
void F_73 ( struct V_102 * V_108 , T_1 V_2 )
{
int V_66 ;
for ( V_66 = 0 ; V_66 < V_2 ; V_66 ++ )
F_72 ( & V_108 [ V_66 ] ) ;
}
void F_74 ( struct V_102 * V_108 , T_1 V_2 )
{
}
void F_27 ( unsigned long V_14 , T_1 V_2 )
{
F_22 ( V_14 , V_2 , false ) ;
}
void F_25 ( unsigned long V_14 , T_1 V_2 )
{
F_22 ( V_14 , V_2 , true ) ;
}
void F_75 ( void ) {}
static int F_76 ( struct V_109 * V_110 ,
unsigned long V_111 , void * V_112 )
{
return ( V_111 == V_113 ) ? V_114 : V_115 ;
}
static int T_10 F_77 ( void )
{
F_78 ( L_1 ) ;
F_78 ( L_2 ) ;
F_79 ( F_76 , 0 ) ;
return 0 ;
}
