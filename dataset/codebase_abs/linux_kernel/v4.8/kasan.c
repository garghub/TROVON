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
T_1 V_2 , bool V_28 ,
unsigned long V_29 )
{
if ( F_9 ( V_2 == 0 ) )
return;
if ( F_9 ( ( void * ) V_14 <
F_23 ( ( void * ) V_30 ) ) ) {
F_24 ( V_14 , V_2 , V_28 , V_29 ) ;
return;
}
if ( F_11 ( ! F_19 ( V_14 , V_2 ) ) )
return;
F_24 ( V_14 , V_2 , V_28 , V_29 ) ;
}
static void F_25 ( unsigned long V_14 ,
T_1 V_2 , bool V_28 ,
unsigned long V_29 )
{
F_22 ( V_14 , V_2 , V_28 , V_29 ) ;
}
void F_26 ( const void * V_31 , unsigned int V_2 )
{
F_25 ( ( unsigned long ) V_31 , V_2 , false , V_32 ) ;
}
void F_27 ( const void * V_31 , unsigned int V_2 )
{
F_25 ( ( unsigned long ) V_31 , V_2 , true , V_32 ) ;
}
void * memset ( void * V_14 , int V_33 , T_1 V_34 )
{
F_25 ( ( unsigned long ) V_14 , V_34 , true , V_32 ) ;
return F_28 ( V_14 , V_33 , V_34 ) ;
}
void * memmove ( void * V_35 , const void * V_36 , T_1 V_34 )
{
F_25 ( ( unsigned long ) V_36 , V_34 , false , V_32 ) ;
F_25 ( ( unsigned long ) V_35 , V_34 , true , V_32 ) ;
return F_29 ( V_35 , V_36 , V_34 ) ;
}
void * memcpy ( void * V_35 , const void * V_36 , T_1 V_34 )
{
F_25 ( ( unsigned long ) V_36 , V_34 , false , V_32 ) ;
F_25 ( ( unsigned long ) V_35 , V_34 , true , V_32 ) ;
return F_30 ( V_35 , V_36 , V_34 ) ;
}
void F_31 ( struct V_37 * V_37 , unsigned int V_38 )
{
if ( F_11 ( ! F_32 ( V_37 ) ) )
F_3 ( F_33 ( V_37 ) , V_39 << V_38 ) ;
}
void F_34 ( struct V_37 * V_37 , unsigned int V_38 )
{
if ( F_11 ( ! F_32 ( V_37 ) ) )
F_1 ( F_33 ( V_37 ) ,
V_39 << V_38 ,
V_40 ) ;
}
static T_1 F_35 ( T_1 V_41 )
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
void F_36 ( struct V_43 * V_44 , T_1 * V_2 ,
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
V_46 = F_35 ( V_44 -> V_41 ) -
( * V_2 - V_44 -> V_41 ) ;
if ( V_46 > 0 )
* V_2 += V_46 ;
* V_2 = F_37 ( V_55 , F_38 ( * V_2 , V_44 -> V_41 +
F_35 ( V_44 -> V_41 ) ) ) ;
if ( * V_2 <= V_44 -> V_48 . V_49 ||
* V_2 <= V_44 -> V_48 . V_54 ) {
V_44 -> V_48 . V_49 = 0 ;
V_44 -> V_48 . V_54 = 0 ;
* V_2 = V_47 ;
return;
}
* V_45 |= V_56 ;
}
void F_39 ( struct V_43 * V_44 )
{
F_40 ( V_44 ) ;
}
void F_41 ( struct V_43 * V_44 )
{
F_40 ( V_44 ) ;
}
T_1 F_42 ( struct V_43 * V_44 )
{
return ( V_44 -> V_48 . V_49 ?
sizeof( struct V_50 ) : 0 ) +
( V_44 -> V_48 . V_54 ?
sizeof( struct V_53 ) : 0 ) ;
}
void F_43 ( struct V_37 * V_37 )
{
F_1 ( F_33 ( V_37 ) ,
V_39 << F_44 ( V_37 ) ,
V_57 ) ;
}
void F_45 ( struct V_43 * V_44 , void * V_58 )
{
F_3 ( V_58 , V_44 -> V_41 ) ;
}
void F_46 ( struct V_43 * V_44 , void * V_58 )
{
F_1 ( V_58 ,
F_47 ( V_44 -> V_41 , V_18 ) ,
V_57 ) ;
}
static inline int F_48 ( unsigned long V_59 )
{
return ( V_59 >= ( unsigned long ) & V_60 &&
V_59 < ( unsigned long ) & V_61 ) ||
( V_59 >= ( unsigned long ) & V_62 &&
V_59 < ( unsigned long ) & V_63 ) ;
}
static inline void F_49 ( struct V_64 * V_65 )
{
int V_66 ;
if ( ! V_65 -> V_67 )
return;
for ( V_66 = 0 ; V_66 < V_65 -> V_67 ; V_66 ++ )
if ( F_48 ( V_65 -> V_68 [ V_66 ] ) ) {
V_65 -> V_67 = V_66 + 1 ;
break;
}
}
static inline T_8 F_50 ( T_9 V_45 )
{
unsigned long V_68 [ V_69 ] ;
struct V_64 V_65 = {
. V_67 = 0 ,
. V_68 = V_68 ,
. V_70 = V_69 ,
. V_71 = 0
} ;
F_51 ( & V_65 ) ;
F_49 ( & V_65 ) ;
if ( V_65 . V_67 != 0 &&
V_65 . V_68 [ V_65 . V_67 - 1 ] == V_72 )
V_65 . V_67 -- ;
return F_52 ( & V_65 , V_45 ) ;
}
static inline void F_53 ( struct V_73 * V_74 , T_9 V_45 )
{
V_74 -> V_75 = V_13 -> V_75 ;
V_74 -> V_76 = F_50 ( V_45 ) ;
}
struct V_50 * F_54 ( struct V_43 * V_44 ,
const void * V_58 )
{
F_55 ( sizeof( struct V_50 ) > 32 ) ;
return ( void * ) V_58 + V_44 -> V_48 . V_49 ;
}
struct V_53 * F_56 ( struct V_43 * V_44 ,
const void * V_58 )
{
F_55 ( sizeof( struct V_53 ) > 32 ) ;
return ( void * ) V_58 + V_44 -> V_48 . V_54 ;
}
void F_57 ( struct V_43 * V_44 , const void * V_58 )
{
struct V_50 * V_77 ;
if ( ! ( V_44 -> V_45 & V_56 ) )
return;
V_77 = F_54 ( V_44 , V_58 ) ;
F_28 ( V_77 , 0 , sizeof( * V_77 ) ) ;
}
void F_58 ( struct V_43 * V_44 , void * V_58 , T_9 V_45 )
{
F_59 ( V_44 , V_58 , V_44 -> V_41 , V_45 ) ;
}
static void F_60 ( struct V_43 * V_44 , void * V_58 )
{
unsigned long V_2 = V_44 -> V_41 ;
unsigned long V_78 = F_47 ( V_2 , V_18 ) ;
if ( F_9 ( V_44 -> V_45 & V_51 ) )
return;
F_1 ( V_58 , V_78 , V_79 ) ;
}
bool F_61 ( struct V_43 * V_44 , void * V_58 )
{
T_5 V_80 ;
if ( F_9 ( V_44 -> V_45 & V_51 ) )
return false ;
V_80 = F_62 ( * ( T_5 * ) F_2 ( V_58 ) ) ;
if ( V_80 < 0 || V_80 >= V_18 ) {
F_63 ( V_44 , V_58 , V_80 ) ;
return true ;
}
F_60 ( V_44 , V_58 ) ;
if ( F_9 ( ! ( V_44 -> V_45 & V_56 ) ) )
return false ;
F_53 ( & F_54 ( V_44 , V_58 ) -> V_81 , V_82 ) ;
F_64 ( F_56 ( V_44 , V_58 ) , V_44 ) ;
return true ;
}
void F_59 ( struct V_43 * V_44 , const void * V_58 , T_1 V_2 ,
T_9 V_45 )
{
unsigned long V_83 ;
unsigned long V_84 ;
if ( F_65 ( V_45 ) )
F_66 () ;
if ( F_9 ( V_58 == NULL ) )
return;
V_83 = F_47 ( ( unsigned long ) ( V_58 + V_2 ) ,
V_18 ) ;
V_84 = F_47 ( ( unsigned long ) V_58 + V_44 -> V_41 ,
V_18 ) ;
F_3 ( V_58 , V_2 ) ;
F_1 ( ( void * ) V_83 , V_84 - V_83 ,
V_57 ) ;
if ( V_44 -> V_45 & V_56 )
F_53 ( & F_54 ( V_44 , V_58 ) -> V_85 , V_45 ) ;
}
void F_67 ( const void * V_59 , T_1 V_2 , T_9 V_45 )
{
struct V_37 * V_37 ;
unsigned long V_83 ;
unsigned long V_84 ;
if ( F_65 ( V_45 ) )
F_66 () ;
if ( F_9 ( V_59 == NULL ) )
return;
V_37 = F_68 ( V_59 ) ;
V_83 = F_47 ( ( unsigned long ) ( V_59 + V_2 ) ,
V_18 ) ;
V_84 = ( unsigned long ) V_59 + ( V_39 << F_44 ( V_37 ) ) ;
F_3 ( V_59 , V_2 ) ;
F_1 ( ( void * ) V_83 , V_84 - V_83 ,
V_86 ) ;
}
void F_69 ( const void * V_58 , T_1 V_2 , T_9 V_45 )
{
struct V_37 * V_37 ;
if ( F_9 ( V_58 == V_87 ) )
return;
V_37 = F_70 ( V_58 ) ;
if ( F_9 ( ! F_71 ( V_37 ) ) )
F_67 ( V_58 , V_2 , V_45 ) ;
else
F_59 ( V_37 -> V_88 , V_58 , V_2 , V_45 ) ;
}
void F_72 ( void * V_59 )
{
struct V_37 * V_37 ;
V_37 = F_70 ( V_59 ) ;
if ( F_9 ( ! F_71 ( V_37 ) ) )
F_1 ( V_59 , V_39 << F_44 ( V_37 ) ,
V_40 ) ;
else
F_60 ( V_37 -> V_88 , V_59 ) ;
}
void F_73 ( const void * V_59 )
{
struct V_37 * V_37 = F_68 ( V_59 ) ;
F_1 ( V_59 , V_39 << F_44 ( V_37 ) ,
V_40 ) ;
}
int F_74 ( void * V_14 , T_1 V_2 )
{
void * V_23 ;
T_1 V_89 ;
unsigned long V_4 ;
V_4 = ( unsigned long ) F_2 ( V_14 ) ;
V_89 = F_47 ( V_2 >> V_90 ,
V_39 ) ;
if ( F_75 ( ! F_76 ( V_4 ) ) )
return - V_91 ;
V_23 = F_77 ( V_89 , 1 , V_4 ,
V_4 + V_89 ,
V_92 | V_93 | V_94 ,
V_95 , V_96 , V_97 ,
F_78 ( 0 ) ) ;
if ( V_23 ) {
F_79 ( V_14 ) -> V_45 |= V_98 ;
F_80 ( V_23 ) ;
return 0 ;
}
return - V_99 ;
}
void F_81 ( const struct V_100 * V_101 )
{
if ( V_101 -> V_45 & V_98 )
F_82 ( F_2 ( V_101 -> V_14 ) ) ;
}
static void F_83 ( struct V_102 * V_103 )
{
T_1 V_104 = F_47 ( V_103 -> V_2 , V_18 ) ;
F_3 ( V_103 -> V_105 , V_103 -> V_2 ) ;
F_1 ( V_103 -> V_105 + V_104 ,
V_103 -> V_106 - V_104 ,
V_107 ) ;
}
void F_84 ( struct V_102 * V_108 , T_1 V_2 )
{
int V_66 ;
for ( V_66 = 0 ; V_66 < V_2 ; V_66 ++ )
F_83 ( & V_108 [ V_66 ] ) ;
}
void F_85 ( struct V_102 * V_108 , T_1 V_2 )
{
}
void F_86 ( unsigned long V_14 , T_1 V_2 )
{
F_25 ( V_14 , V_2 , false , V_32 ) ;
}
void F_87 ( unsigned long V_14 , T_1 V_2 )
{
F_25 ( V_14 , V_2 , true , V_32 ) ;
}
void F_88 ( void ) {}
static int F_89 ( struct V_109 * V_110 ,
unsigned long V_111 , void * V_112 )
{
return ( V_111 == V_113 ) ? V_114 : V_115 ;
}
static int T_10 F_90 ( void )
{
F_91 ( L_1 ) ;
F_91 ( L_2 ) ;
F_92 ( F_89 , 0 ) ;
return 0 ;
}
