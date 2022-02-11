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
static void F_4 ( struct V_8 * V_9 , const void * V_10 )
{
void * V_11 = F_5 ( V_9 ) ;
T_1 V_2 = V_10 - V_11 ;
F_3 ( V_11 , V_2 ) ;
}
void F_6 ( struct V_8 * V_9 )
{
F_4 ( V_9 , F_5 ( V_9 ) + V_12 ) ;
}
T_3 void F_7 ( const void * V_13 )
{
void * V_11 = ( void * ) ( ( unsigned long ) V_13 & ~ ( V_12 - 1 ) ) ;
F_3 ( V_11 , V_13 - V_11 ) ;
}
void F_8 ( const void * V_13 )
{
const void * V_10 = F_9 ( 0 ) ;
T_1 V_2 = V_13 - V_10 ;
if ( F_10 ( V_10 > V_13 ) )
return;
F_3 ( V_10 , V_2 ) ;
}
static T_4 bool F_11 ( unsigned long V_14 )
{
T_5 V_15 = * ( T_5 * ) F_2 ( ( void * ) V_14 ) ;
if ( F_12 ( V_15 ) ) {
T_5 V_16 = V_14 & V_6 ;
return F_12 ( V_16 >= V_15 ) ;
}
return false ;
}
static T_4 bool F_13 ( unsigned long V_14 )
{
T_6 * V_17 = ( T_6 * ) F_2 ( ( void * ) V_14 ) ;
if ( F_12 ( * V_17 ) ) {
if ( F_11 ( V_14 + 1 ) )
return true ;
if ( F_14 ( ( ( V_14 + 1 ) & V_6 ) != 0 ) )
return false ;
return F_12 ( * ( T_2 * ) V_17 ) ;
}
return false ;
}
static T_4 bool F_15 ( unsigned long V_14 )
{
T_6 * V_17 = ( T_6 * ) F_2 ( ( void * ) V_14 ) ;
if ( F_12 ( * V_17 ) ) {
if ( F_11 ( V_14 + 3 ) )
return true ;
if ( F_14 ( ( ( V_14 + 3 ) & V_6 ) >= 3 ) )
return false ;
return F_12 ( * ( T_2 * ) V_17 ) ;
}
return false ;
}
static T_4 bool F_16 ( unsigned long V_14 )
{
T_6 * V_17 = ( T_6 * ) F_2 ( ( void * ) V_14 ) ;
if ( F_12 ( * V_17 ) ) {
if ( F_11 ( V_14 + 7 ) )
return true ;
if ( F_14 ( F_17 ( V_14 , V_18 ) ) )
return false ;
return F_12 ( * ( T_2 * ) V_17 ) ;
}
return false ;
}
static T_4 bool F_18 ( unsigned long V_14 )
{
T_7 * V_17 = ( T_7 * ) F_2 ( ( void * ) V_14 ) ;
if ( F_12 ( * V_17 ) ) {
T_6 V_19 = * ( T_6 * ) V_17 ;
if ( F_12 ( V_19 ) )
return true ;
if ( F_14 ( F_17 ( V_14 , V_18 ) ) )
return false ;
return F_11 ( V_14 + 15 ) ;
}
return false ;
}
static T_4 unsigned long F_19 ( const T_2 * V_20 ,
T_1 V_2 )
{
while ( V_2 ) {
if ( F_12 ( * V_20 ) )
return ( unsigned long ) V_20 ;
V_20 ++ ;
V_2 -- ;
}
return 0 ;
}
static T_4 unsigned long F_20 ( const void * V_20 ,
const void * V_21 )
{
unsigned int V_22 ;
unsigned long V_23 ;
unsigned int V_24 = ( unsigned long ) V_20 % 8 ;
if ( V_21 - V_20 <= 16 )
return F_19 ( V_20 , V_21 - V_20 ) ;
if ( V_24 ) {
V_24 = 8 - V_24 ;
V_23 = F_19 ( V_20 , V_24 ) ;
if ( F_12 ( V_23 ) )
return V_23 ;
V_20 += V_24 ;
}
V_22 = ( V_21 - V_20 ) / 8 ;
while ( V_22 ) {
if ( F_12 ( * ( V_25 * ) V_20 ) )
return F_19 ( V_20 , 8 ) ;
V_20 += 8 ;
V_22 -- ;
}
return F_19 ( V_20 , ( V_21 - V_20 ) % 8 ) ;
}
static T_4 bool F_21 ( unsigned long V_14 ,
T_1 V_2 )
{
unsigned long V_23 ;
V_23 = F_20 ( F_2 ( ( void * ) V_14 ) ,
F_2 ( ( void * ) V_14 + V_2 - 1 ) + 1 ) ;
if ( F_12 ( V_23 ) ) {
unsigned long V_26 = V_14 + V_2 - 1 ;
T_5 * V_27 = ( T_5 * ) F_2 ( ( void * ) V_26 ) ;
if ( F_12 ( V_23 != ( unsigned long ) V_27 ||
( ( long ) ( V_26 & V_6 ) >= * V_27 ) ) )
return true ;
}
return false ;
}
static T_4 bool F_22 ( unsigned long V_14 , T_1 V_2 )
{
if ( F_23 ( V_2 ) ) {
switch ( V_2 ) {
case 1 :
return F_11 ( V_14 ) ;
case 2 :
return F_13 ( V_14 ) ;
case 4 :
return F_15 ( V_14 ) ;
case 8 :
return F_16 ( V_14 ) ;
case 16 :
return F_18 ( V_14 ) ;
default:
F_24 () ;
}
}
return F_21 ( V_14 , V_2 ) ;
}
static T_4 void F_25 ( unsigned long V_14 ,
T_1 V_2 , bool V_28 ,
unsigned long V_29 )
{
if ( F_12 ( V_2 == 0 ) )
return;
if ( F_12 ( ( void * ) V_14 <
F_26 ( ( void * ) V_30 ) ) ) {
F_27 ( V_14 , V_2 , V_28 , V_29 ) ;
return;
}
if ( F_14 ( ! F_22 ( V_14 , V_2 ) ) )
return;
F_27 ( V_14 , V_2 , V_28 , V_29 ) ;
}
static void F_28 ( unsigned long V_14 ,
T_1 V_2 , bool V_28 ,
unsigned long V_29 )
{
F_25 ( V_14 , V_2 , V_28 , V_29 ) ;
}
void F_29 ( const void * V_31 , unsigned int V_2 )
{
F_28 ( ( unsigned long ) V_31 , V_2 , false , V_32 ) ;
}
void F_30 ( const void * V_31 , unsigned int V_2 )
{
F_28 ( ( unsigned long ) V_31 , V_2 , true , V_32 ) ;
}
void * memset ( void * V_14 , int V_33 , T_1 V_34 )
{
F_28 ( ( unsigned long ) V_14 , V_34 , true , V_32 ) ;
return F_31 ( V_14 , V_33 , V_34 ) ;
}
void * memmove ( void * V_35 , const void * V_36 , T_1 V_34 )
{
F_28 ( ( unsigned long ) V_36 , V_34 , false , V_32 ) ;
F_28 ( ( unsigned long ) V_35 , V_34 , true , V_32 ) ;
return F_32 ( V_35 , V_36 , V_34 ) ;
}
void * memcpy ( void * V_35 , const void * V_36 , T_1 V_34 )
{
F_28 ( ( unsigned long ) V_36 , V_34 , false , V_32 ) ;
F_28 ( ( unsigned long ) V_35 , V_34 , true , V_32 ) ;
return F_33 ( V_35 , V_36 , V_34 ) ;
}
void F_34 ( struct V_37 * V_37 , unsigned int V_38 )
{
if ( F_14 ( ! F_35 ( V_37 ) ) )
F_3 ( F_36 ( V_37 ) , V_39 << V_38 ) ;
}
void F_37 ( struct V_37 * V_37 , unsigned int V_38 )
{
if ( F_14 ( ! F_35 ( V_37 ) ) )
F_1 ( F_36 ( V_37 ) ,
V_39 << V_38 ,
V_40 ) ;
}
static T_1 F_38 ( T_1 V_41 )
{
int V_42 =
V_41 <= 64 - 16 ? 16 :
V_41 <= 128 - 32 ? 32 :
V_41 <= 512 - 64 ? 64 :
V_41 <= 4096 - 128 ? 128 :
V_41 <= ( 1 << 14 ) - 256 ? 256 :
V_41 <= ( 1 << 15 ) - 512 ? 512 :
V_41 <= ( 1 << 16 ) - 1024 ? 1024 : 2048 ;
return V_42 ;
}
void F_39 ( struct V_43 * V_44 , T_1 * V_2 ,
unsigned long * V_45 )
{
int V_46 ;
int V_47 = * V_2 ;
V_44 -> V_48 . V_49 = * V_2 ;
* V_2 += sizeof( struct V_50 ) ;
if ( V_44 -> V_45 & V_51 || V_44 -> V_52 ||
V_44 -> V_41 < sizeof( struct V_53 ) ) {
V_44 -> V_48 . V_54 = * V_2 ;
* V_2 += sizeof( struct V_53 ) ;
}
V_46 = F_38 ( V_44 -> V_41 ) -
( * V_2 - V_44 -> V_41 ) ;
if ( V_46 > 0 )
* V_2 += V_46 ;
* V_2 = F_40 ( V_55 , F_41 ( * V_2 , V_44 -> V_41 +
F_38 ( V_44 -> V_41 ) ) ) ;
if ( * V_2 <= V_44 -> V_48 . V_49 ||
* V_2 <= V_44 -> V_48 . V_54 ) {
V_44 -> V_48 . V_49 = 0 ;
V_44 -> V_48 . V_54 = 0 ;
* V_2 = V_47 ;
return;
}
* V_45 |= V_56 ;
}
void F_42 ( struct V_43 * V_44 )
{
F_43 ( V_44 ) ;
}
void F_44 ( struct V_43 * V_44 )
{
F_43 ( V_44 ) ;
}
T_1 F_45 ( struct V_43 * V_44 )
{
return ( V_44 -> V_48 . V_49 ?
sizeof( struct V_50 ) : 0 ) +
( V_44 -> V_48 . V_54 ?
sizeof( struct V_53 ) : 0 ) ;
}
void F_46 ( struct V_37 * V_37 )
{
F_1 ( F_36 ( V_37 ) ,
V_39 << F_47 ( V_37 ) ,
V_57 ) ;
}
void F_48 ( struct V_43 * V_44 , void * V_58 )
{
F_3 ( V_58 , V_44 -> V_41 ) ;
}
void F_49 ( struct V_43 * V_44 , void * V_58 )
{
F_1 ( V_58 ,
F_50 ( V_44 -> V_41 , V_18 ) ,
V_57 ) ;
}
static inline int F_51 ( unsigned long V_59 )
{
return ( V_59 >= ( unsigned long ) & V_60 &&
V_59 < ( unsigned long ) & V_61 ) ||
( V_59 >= ( unsigned long ) & V_62 &&
V_59 < ( unsigned long ) & V_63 ) ;
}
static inline void F_52 ( struct V_64 * V_65 )
{
int V_66 ;
if ( ! V_65 -> V_67 )
return;
for ( V_66 = 0 ; V_66 < V_65 -> V_67 ; V_66 ++ )
if ( F_51 ( V_65 -> V_68 [ V_66 ] ) ) {
V_65 -> V_67 = V_66 + 1 ;
break;
}
}
static inline T_8 F_53 ( T_9 V_45 )
{
unsigned long V_68 [ V_69 ] ;
struct V_64 V_65 = {
. V_67 = 0 ,
. V_68 = V_68 ,
. V_70 = V_69 ,
. V_71 = 0
} ;
F_54 ( & V_65 ) ;
F_52 ( & V_65 ) ;
if ( V_65 . V_67 != 0 &&
V_65 . V_68 [ V_65 . V_67 - 1 ] == V_72 )
V_65 . V_67 -- ;
return F_55 ( & V_65 , V_45 ) ;
}
static inline void F_56 ( struct V_73 * V_74 , T_9 V_45 )
{
V_74 -> V_75 = V_76 -> V_75 ;
V_74 -> V_77 = F_53 ( V_45 ) ;
}
struct V_50 * F_57 ( struct V_43 * V_44 ,
const void * V_58 )
{
F_58 ( sizeof( struct V_50 ) > 32 ) ;
return ( void * ) V_58 + V_44 -> V_48 . V_49 ;
}
struct V_53 * F_59 ( struct V_43 * V_44 ,
const void * V_58 )
{
F_58 ( sizeof( struct V_53 ) > 32 ) ;
return ( void * ) V_58 + V_44 -> V_48 . V_54 ;
}
void F_60 ( struct V_43 * V_44 , const void * V_58 )
{
struct V_50 * V_78 ;
if ( ! ( V_44 -> V_45 & V_56 ) )
return;
V_78 = F_57 ( V_44 , V_58 ) ;
F_31 ( V_78 , 0 , sizeof( * V_78 ) ) ;
}
void F_61 ( struct V_43 * V_44 , void * V_58 , T_9 V_45 )
{
F_62 ( V_44 , V_58 , V_44 -> V_41 , V_45 ) ;
}
static void F_63 ( struct V_43 * V_44 , void * V_58 )
{
unsigned long V_2 = V_44 -> V_41 ;
unsigned long V_79 = F_50 ( V_2 , V_18 ) ;
if ( F_12 ( V_44 -> V_45 & V_51 ) )
return;
F_1 ( V_58 , V_79 , V_80 ) ;
}
bool F_64 ( struct V_43 * V_44 , void * V_58 )
{
T_5 V_81 ;
if ( F_12 ( V_44 -> V_45 & V_51 ) )
return false ;
V_81 = F_65 ( * ( T_5 * ) F_2 ( V_58 ) ) ;
if ( V_81 < 0 || V_81 >= V_18 ) {
F_66 ( V_44 , V_58 , V_81 ) ;
return true ;
}
F_63 ( V_44 , V_58 ) ;
if ( F_12 ( ! ( V_44 -> V_45 & V_56 ) ) )
return false ;
F_56 ( & F_57 ( V_44 , V_58 ) -> V_82 , V_83 ) ;
F_67 ( F_59 ( V_44 , V_58 ) , V_44 ) ;
return true ;
}
void F_62 ( struct V_43 * V_44 , const void * V_58 , T_1 V_2 ,
T_9 V_45 )
{
unsigned long V_84 ;
unsigned long V_85 ;
if ( F_68 ( V_45 ) )
F_69 () ;
if ( F_12 ( V_58 == NULL ) )
return;
V_84 = F_50 ( ( unsigned long ) ( V_58 + V_2 ) ,
V_18 ) ;
V_85 = F_50 ( ( unsigned long ) V_58 + V_44 -> V_41 ,
V_18 ) ;
F_3 ( V_58 , V_2 ) ;
F_1 ( ( void * ) V_84 , V_85 - V_84 ,
V_57 ) ;
if ( V_44 -> V_45 & V_56 )
F_56 ( & F_57 ( V_44 , V_58 ) -> V_86 , V_45 ) ;
}
void F_70 ( const void * V_59 , T_1 V_2 , T_9 V_45 )
{
struct V_37 * V_37 ;
unsigned long V_84 ;
unsigned long V_85 ;
if ( F_68 ( V_45 ) )
F_69 () ;
if ( F_12 ( V_59 == NULL ) )
return;
V_37 = F_71 ( V_59 ) ;
V_84 = F_50 ( ( unsigned long ) ( V_59 + V_2 ) ,
V_18 ) ;
V_85 = ( unsigned long ) V_59 + ( V_39 << F_47 ( V_37 ) ) ;
F_3 ( V_59 , V_2 ) ;
F_1 ( ( void * ) V_84 , V_85 - V_84 ,
V_87 ) ;
}
void F_72 ( const void * V_58 , T_1 V_2 , T_9 V_45 )
{
struct V_37 * V_37 ;
if ( F_12 ( V_58 == V_88 ) )
return;
V_37 = F_73 ( V_58 ) ;
if ( F_12 ( ! F_74 ( V_37 ) ) )
F_70 ( V_58 , V_2 , V_45 ) ;
else
F_62 ( V_37 -> V_89 , V_58 , V_2 , V_45 ) ;
}
void F_75 ( void * V_59 )
{
struct V_37 * V_37 ;
V_37 = F_73 ( V_59 ) ;
if ( F_12 ( ! F_74 ( V_37 ) ) )
F_1 ( V_59 , V_39 << F_47 ( V_37 ) ,
V_40 ) ;
else
F_63 ( V_37 -> V_89 , V_59 ) ;
}
void F_76 ( const void * V_59 )
{
struct V_37 * V_37 = F_71 ( V_59 ) ;
F_1 ( V_59 , V_39 << F_47 ( V_37 ) ,
V_40 ) ;
}
int F_77 ( void * V_14 , T_1 V_2 )
{
void * V_23 ;
T_1 V_90 ;
unsigned long V_4 ;
V_4 = ( unsigned long ) F_2 ( V_14 ) ;
V_90 = F_50 ( V_2 >> V_91 ,
V_39 ) ;
if ( F_10 ( ! F_78 ( V_4 ) ) )
return - V_92 ;
V_23 = F_79 ( V_90 , 1 , V_4 ,
V_4 + V_90 ,
V_93 | V_94 | V_95 ,
V_96 , V_97 , V_98 ,
F_80 ( 0 ) ) ;
if ( V_23 ) {
F_81 ( V_14 ) -> V_45 |= V_99 ;
F_82 ( V_23 ) ;
return 0 ;
}
return - V_100 ;
}
void F_83 ( const struct V_101 * V_102 )
{
if ( V_102 -> V_45 & V_99 )
F_84 ( F_2 ( V_102 -> V_14 ) ) ;
}
static void F_85 ( struct V_103 * V_104 )
{
T_1 V_105 = F_50 ( V_104 -> V_2 , V_18 ) ;
F_3 ( V_104 -> V_106 , V_104 -> V_2 ) ;
F_1 ( V_104 -> V_106 + V_105 ,
V_104 -> V_107 - V_105 ,
V_108 ) ;
}
void F_86 ( struct V_103 * V_109 , T_1 V_2 )
{
int V_66 ;
for ( V_66 = 0 ; V_66 < V_2 ; V_66 ++ )
F_85 ( & V_109 [ V_66 ] ) ;
}
void F_87 ( struct V_103 * V_109 , T_1 V_2 )
{
}
void F_88 ( unsigned long V_14 , T_1 V_2 )
{
F_28 ( V_14 , V_2 , false , V_32 ) ;
}
void F_89 ( unsigned long V_14 , T_1 V_2 )
{
F_28 ( V_14 , V_2 , true , V_32 ) ;
}
void F_90 ( void ) {}
void F_91 ( const void * V_14 , T_1 V_2 )
{
F_1 ( V_14 , F_50 ( V_2 , V_18 ) ,
V_110 ) ;
}
void F_92 ( const void * V_14 , T_1 V_2 )
{
F_3 ( V_14 , V_2 ) ;
}
static int F_93 ( struct V_111 * V_112 ,
unsigned long V_113 , void * V_114 )
{
return ( V_113 == V_115 ) ? V_116 : V_117 ;
}
static int T_10 F_94 ( void )
{
F_95 ( L_1 ) ;
F_95 ( L_2 ) ;
F_96 ( F_93 , 0 ) ;
return 0 ;
}
