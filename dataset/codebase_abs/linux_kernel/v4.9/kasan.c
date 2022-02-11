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
F_4 ( V_14 , V_13 ) ;
}
void F_8 ( const void * V_13 )
{
const void * V_10 = F_9 ( 0 ) ;
T_1 V_2 = V_13 - V_10 ;
if ( F_10 ( V_10 > V_13 ) )
return;
F_3 ( V_10 , V_2 ) ;
}
static T_4 bool F_11 ( unsigned long V_15 )
{
T_5 V_16 = * ( T_5 * ) F_2 ( ( void * ) V_15 ) ;
if ( F_12 ( V_16 ) ) {
T_5 V_17 = V_15 & V_6 ;
return F_12 ( V_17 >= V_16 ) ;
}
return false ;
}
static T_4 bool F_13 ( unsigned long V_15 )
{
T_6 * V_18 = ( T_6 * ) F_2 ( ( void * ) V_15 ) ;
if ( F_12 ( * V_18 ) ) {
if ( F_11 ( V_15 + 1 ) )
return true ;
if ( F_14 ( ( ( V_15 + 1 ) & V_6 ) != 0 ) )
return false ;
return F_12 ( * ( T_2 * ) V_18 ) ;
}
return false ;
}
static T_4 bool F_15 ( unsigned long V_15 )
{
T_6 * V_18 = ( T_6 * ) F_2 ( ( void * ) V_15 ) ;
if ( F_12 ( * V_18 ) ) {
if ( F_11 ( V_15 + 3 ) )
return true ;
if ( F_14 ( ( ( V_15 + 3 ) & V_6 ) >= 3 ) )
return false ;
return F_12 ( * ( T_2 * ) V_18 ) ;
}
return false ;
}
static T_4 bool F_16 ( unsigned long V_15 )
{
T_6 * V_18 = ( T_6 * ) F_2 ( ( void * ) V_15 ) ;
if ( F_12 ( * V_18 ) ) {
if ( F_11 ( V_15 + 7 ) )
return true ;
if ( F_14 ( F_17 ( V_15 , V_19 ) ) )
return false ;
return F_12 ( * ( T_2 * ) V_18 ) ;
}
return false ;
}
static T_4 bool F_18 ( unsigned long V_15 )
{
T_7 * V_18 = ( T_7 * ) F_2 ( ( void * ) V_15 ) ;
if ( F_12 ( * V_18 ) ) {
T_6 V_20 = * ( T_6 * ) V_18 ;
if ( F_12 ( V_20 ) )
return true ;
if ( F_14 ( F_17 ( V_15 , V_19 ) ) )
return false ;
return F_11 ( V_15 + 15 ) ;
}
return false ;
}
static T_4 unsigned long F_19 ( const T_2 * V_21 ,
T_1 V_2 )
{
while ( V_2 ) {
if ( F_12 ( * V_21 ) )
return ( unsigned long ) V_21 ;
V_21 ++ ;
V_2 -- ;
}
return 0 ;
}
static T_4 unsigned long F_20 ( const void * V_21 ,
const void * V_22 )
{
unsigned int V_23 ;
unsigned long V_24 ;
unsigned int V_25 = ( unsigned long ) V_21 % 8 ;
if ( V_22 - V_21 <= 16 )
return F_19 ( V_21 , V_22 - V_21 ) ;
if ( V_25 ) {
V_25 = 8 - V_25 ;
V_24 = F_19 ( V_21 , V_25 ) ;
if ( F_12 ( V_24 ) )
return V_24 ;
V_21 += V_25 ;
}
V_23 = ( V_22 - V_21 ) / 8 ;
while ( V_23 ) {
if ( F_12 ( * ( V_26 * ) V_21 ) )
return F_19 ( V_21 , 8 ) ;
V_21 += 8 ;
V_23 -- ;
}
return F_19 ( V_21 , ( V_22 - V_21 ) % 8 ) ;
}
static T_4 bool F_21 ( unsigned long V_15 ,
T_1 V_2 )
{
unsigned long V_24 ;
V_24 = F_20 ( F_2 ( ( void * ) V_15 ) ,
F_2 ( ( void * ) V_15 + V_2 - 1 ) + 1 ) ;
if ( F_12 ( V_24 ) ) {
unsigned long V_27 = V_15 + V_2 - 1 ;
T_5 * V_28 = ( T_5 * ) F_2 ( ( void * ) V_27 ) ;
if ( F_12 ( V_24 != ( unsigned long ) V_28 ||
( ( long ) ( V_27 & V_6 ) >= * V_28 ) ) )
return true ;
}
return false ;
}
static T_4 bool F_22 ( unsigned long V_15 , T_1 V_2 )
{
if ( F_23 ( V_2 ) ) {
switch ( V_2 ) {
case 1 :
return F_11 ( V_15 ) ;
case 2 :
return F_13 ( V_15 ) ;
case 4 :
return F_15 ( V_15 ) ;
case 8 :
return F_16 ( V_15 ) ;
case 16 :
return F_18 ( V_15 ) ;
default:
F_24 () ;
}
}
return F_21 ( V_15 , V_2 ) ;
}
static T_4 void F_25 ( unsigned long V_15 ,
T_1 V_2 , bool V_29 ,
unsigned long V_30 )
{
if ( F_12 ( V_2 == 0 ) )
return;
if ( F_12 ( ( void * ) V_15 <
F_26 ( ( void * ) V_31 ) ) ) {
F_27 ( V_15 , V_2 , V_29 , V_30 ) ;
return;
}
if ( F_14 ( ! F_22 ( V_15 , V_2 ) ) )
return;
F_27 ( V_15 , V_2 , V_29 , V_30 ) ;
}
static void F_28 ( unsigned long V_15 ,
T_1 V_2 , bool V_29 ,
unsigned long V_30 )
{
F_25 ( V_15 , V_2 , V_29 , V_30 ) ;
}
void F_29 ( const void * V_32 , unsigned int V_2 )
{
F_28 ( ( unsigned long ) V_32 , V_2 , false , V_33 ) ;
}
void F_30 ( const void * V_32 , unsigned int V_2 )
{
F_28 ( ( unsigned long ) V_32 , V_2 , true , V_33 ) ;
}
void * memset ( void * V_15 , int V_34 , T_1 V_35 )
{
F_28 ( ( unsigned long ) V_15 , V_35 , true , V_33 ) ;
return F_31 ( V_15 , V_34 , V_35 ) ;
}
void * memmove ( void * V_36 , const void * V_37 , T_1 V_35 )
{
F_28 ( ( unsigned long ) V_37 , V_35 , false , V_33 ) ;
F_28 ( ( unsigned long ) V_36 , V_35 , true , V_33 ) ;
return F_32 ( V_36 , V_37 , V_35 ) ;
}
void * memcpy ( void * V_36 , const void * V_37 , T_1 V_35 )
{
F_28 ( ( unsigned long ) V_37 , V_35 , false , V_33 ) ;
F_28 ( ( unsigned long ) V_36 , V_35 , true , V_33 ) ;
return F_33 ( V_36 , V_37 , V_35 ) ;
}
void F_34 ( struct V_38 * V_38 , unsigned int V_39 )
{
if ( F_14 ( ! F_35 ( V_38 ) ) )
F_3 ( F_36 ( V_38 ) , V_40 << V_39 ) ;
}
void F_37 ( struct V_38 * V_38 , unsigned int V_39 )
{
if ( F_14 ( ! F_35 ( V_38 ) ) )
F_1 ( F_36 ( V_38 ) ,
V_40 << V_39 ,
V_41 ) ;
}
static T_1 F_38 ( T_1 V_42 )
{
int V_43 =
V_42 <= 64 - 16 ? 16 :
V_42 <= 128 - 32 ? 32 :
V_42 <= 512 - 64 ? 64 :
V_42 <= 4096 - 128 ? 128 :
V_42 <= ( 1 << 14 ) - 256 ? 256 :
V_42 <= ( 1 << 15 ) - 512 ? 512 :
V_42 <= ( 1 << 16 ) - 1024 ? 1024 : 2048 ;
return V_43 ;
}
void F_39 ( struct V_44 * V_45 , T_1 * V_2 ,
unsigned long * V_46 )
{
int V_47 ;
int V_48 = * V_2 ;
V_45 -> V_49 . V_50 = * V_2 ;
* V_2 += sizeof( struct V_51 ) ;
if ( V_45 -> V_46 & V_52 || V_45 -> V_53 ||
V_45 -> V_42 < sizeof( struct V_54 ) ) {
V_45 -> V_49 . V_55 = * V_2 ;
* V_2 += sizeof( struct V_54 ) ;
}
V_47 = F_38 ( V_45 -> V_42 ) -
( * V_2 - V_45 -> V_42 ) ;
if ( V_47 > 0 )
* V_2 += V_47 ;
* V_2 = F_40 ( V_56 , F_41 ( * V_2 , V_45 -> V_42 +
F_38 ( V_45 -> V_42 ) ) ) ;
if ( * V_2 <= V_45 -> V_49 . V_50 ||
* V_2 <= V_45 -> V_49 . V_55 ) {
V_45 -> V_49 . V_50 = 0 ;
V_45 -> V_49 . V_55 = 0 ;
* V_2 = V_48 ;
return;
}
* V_46 |= V_57 ;
}
void F_42 ( struct V_44 * V_45 )
{
F_43 ( V_45 ) ;
}
void F_44 ( struct V_44 * V_45 )
{
F_43 ( V_45 ) ;
}
T_1 F_45 ( struct V_44 * V_45 )
{
return ( V_45 -> V_49 . V_50 ?
sizeof( struct V_51 ) : 0 ) +
( V_45 -> V_49 . V_55 ?
sizeof( struct V_54 ) : 0 ) ;
}
void F_46 ( struct V_38 * V_38 )
{
F_1 ( F_36 ( V_38 ) ,
V_40 << F_47 ( V_38 ) ,
V_58 ) ;
}
void F_48 ( struct V_44 * V_45 , void * V_59 )
{
F_3 ( V_59 , V_45 -> V_42 ) ;
}
void F_49 ( struct V_44 * V_45 , void * V_59 )
{
F_1 ( V_59 ,
F_50 ( V_45 -> V_42 , V_19 ) ,
V_58 ) ;
}
static inline int F_51 ( unsigned long V_60 )
{
return ( V_60 >= ( unsigned long ) & V_61 &&
V_60 < ( unsigned long ) & V_62 ) ||
( V_60 >= ( unsigned long ) & V_63 &&
V_60 < ( unsigned long ) & V_64 ) ;
}
static inline void F_52 ( struct V_65 * V_66 )
{
int V_67 ;
if ( ! V_66 -> V_68 )
return;
for ( V_67 = 0 ; V_67 < V_66 -> V_68 ; V_67 ++ )
if ( F_51 ( V_66 -> V_69 [ V_67 ] ) ) {
V_66 -> V_68 = V_67 + 1 ;
break;
}
}
static inline T_8 F_53 ( T_9 V_46 )
{
unsigned long V_69 [ V_70 ] ;
struct V_65 V_66 = {
. V_68 = 0 ,
. V_69 = V_69 ,
. V_71 = V_70 ,
. V_72 = 0
} ;
F_54 ( & V_66 ) ;
F_52 ( & V_66 ) ;
if ( V_66 . V_68 != 0 &&
V_66 . V_69 [ V_66 . V_68 - 1 ] == V_73 )
V_66 . V_68 -- ;
return F_55 ( & V_66 , V_46 ) ;
}
static inline void F_56 ( struct V_74 * V_75 , T_9 V_46 )
{
V_75 -> V_76 = V_14 -> V_76 ;
V_75 -> V_77 = F_53 ( V_46 ) ;
}
struct V_51 * F_57 ( struct V_44 * V_45 ,
const void * V_59 )
{
F_58 ( sizeof( struct V_51 ) > 32 ) ;
return ( void * ) V_59 + V_45 -> V_49 . V_50 ;
}
struct V_54 * F_59 ( struct V_44 * V_45 ,
const void * V_59 )
{
F_58 ( sizeof( struct V_54 ) > 32 ) ;
return ( void * ) V_59 + V_45 -> V_49 . V_55 ;
}
void F_60 ( struct V_44 * V_45 , const void * V_59 )
{
struct V_51 * V_78 ;
if ( ! ( V_45 -> V_46 & V_57 ) )
return;
V_78 = F_57 ( V_45 , V_59 ) ;
F_31 ( V_78 , 0 , sizeof( * V_78 ) ) ;
}
void F_61 ( struct V_44 * V_45 , void * V_59 , T_9 V_46 )
{
F_62 ( V_45 , V_59 , V_45 -> V_42 , V_46 ) ;
}
static void F_63 ( struct V_44 * V_45 , void * V_59 )
{
unsigned long V_2 = V_45 -> V_42 ;
unsigned long V_79 = F_50 ( V_2 , V_19 ) ;
if ( F_12 ( V_45 -> V_46 & V_52 ) )
return;
F_1 ( V_59 , V_79 , V_80 ) ;
}
bool F_64 ( struct V_44 * V_45 , void * V_59 )
{
T_5 V_81 ;
if ( F_12 ( V_45 -> V_46 & V_52 ) )
return false ;
V_81 = F_65 ( * ( T_5 * ) F_2 ( V_59 ) ) ;
if ( V_81 < 0 || V_81 >= V_19 ) {
F_66 ( V_45 , V_59 , V_81 ) ;
return true ;
}
F_63 ( V_45 , V_59 ) ;
if ( F_12 ( ! ( V_45 -> V_46 & V_57 ) ) )
return false ;
F_56 ( & F_57 ( V_45 , V_59 ) -> V_82 , V_83 ) ;
F_67 ( F_59 ( V_45 , V_59 ) , V_45 ) ;
return true ;
}
void F_62 ( struct V_44 * V_45 , const void * V_59 , T_1 V_2 ,
T_9 V_46 )
{
unsigned long V_84 ;
unsigned long V_85 ;
if ( F_68 ( V_46 ) )
F_69 () ;
if ( F_12 ( V_59 == NULL ) )
return;
V_84 = F_50 ( ( unsigned long ) ( V_59 + V_2 ) ,
V_19 ) ;
V_85 = F_50 ( ( unsigned long ) V_59 + V_45 -> V_42 ,
V_19 ) ;
F_3 ( V_59 , V_2 ) ;
F_1 ( ( void * ) V_84 , V_85 - V_84 ,
V_58 ) ;
if ( V_45 -> V_46 & V_57 )
F_56 ( & F_57 ( V_45 , V_59 ) -> V_86 , V_46 ) ;
}
void F_70 ( const void * V_60 , T_1 V_2 , T_9 V_46 )
{
struct V_38 * V_38 ;
unsigned long V_84 ;
unsigned long V_85 ;
if ( F_68 ( V_46 ) )
F_69 () ;
if ( F_12 ( V_60 == NULL ) )
return;
V_38 = F_71 ( V_60 ) ;
V_84 = F_50 ( ( unsigned long ) ( V_60 + V_2 ) ,
V_19 ) ;
V_85 = ( unsigned long ) V_60 + ( V_40 << F_47 ( V_38 ) ) ;
F_3 ( V_60 , V_2 ) ;
F_1 ( ( void * ) V_84 , V_85 - V_84 ,
V_87 ) ;
}
void F_72 ( const void * V_59 , T_1 V_2 , T_9 V_46 )
{
struct V_38 * V_38 ;
if ( F_12 ( V_59 == V_88 ) )
return;
V_38 = F_73 ( V_59 ) ;
if ( F_12 ( ! F_74 ( V_38 ) ) )
F_70 ( V_59 , V_2 , V_46 ) ;
else
F_62 ( V_38 -> V_89 , V_59 , V_2 , V_46 ) ;
}
void F_75 ( void * V_60 )
{
struct V_38 * V_38 ;
V_38 = F_73 ( V_60 ) ;
if ( F_12 ( ! F_74 ( V_38 ) ) )
F_1 ( V_60 , V_40 << F_47 ( V_38 ) ,
V_41 ) ;
else
F_63 ( V_38 -> V_89 , V_60 ) ;
}
void F_76 ( const void * V_60 )
{
struct V_38 * V_38 = F_71 ( V_60 ) ;
F_1 ( V_60 , V_40 << F_47 ( V_38 ) ,
V_41 ) ;
}
int F_77 ( void * V_15 , T_1 V_2 )
{
void * V_24 ;
T_1 V_90 ;
unsigned long V_4 ;
V_4 = ( unsigned long ) F_2 ( V_15 ) ;
V_90 = F_50 ( V_2 >> V_91 ,
V_40 ) ;
if ( F_10 ( ! F_78 ( V_4 ) ) )
return - V_92 ;
V_24 = F_79 ( V_90 , 1 , V_4 ,
V_4 + V_90 ,
V_93 | V_94 | V_95 ,
V_96 , V_97 , V_98 ,
F_80 ( 0 ) ) ;
if ( V_24 ) {
F_81 ( V_15 ) -> V_46 |= V_99 ;
F_82 ( V_24 ) ;
return 0 ;
}
return - V_100 ;
}
void F_83 ( const struct V_101 * V_102 )
{
if ( V_102 -> V_46 & V_99 )
F_84 ( F_2 ( V_102 -> V_15 ) ) ;
}
static void F_85 ( struct V_103 * V_104 )
{
T_1 V_105 = F_50 ( V_104 -> V_2 , V_19 ) ;
F_3 ( V_104 -> V_106 , V_104 -> V_2 ) ;
F_1 ( V_104 -> V_106 + V_105 ,
V_104 -> V_107 - V_105 ,
V_108 ) ;
}
void F_86 ( struct V_103 * V_109 , T_1 V_2 )
{
int V_67 ;
for ( V_67 = 0 ; V_67 < V_2 ; V_67 ++ )
F_85 ( & V_109 [ V_67 ] ) ;
}
void F_87 ( struct V_103 * V_109 , T_1 V_2 )
{
}
void F_88 ( unsigned long V_15 , T_1 V_2 )
{
F_28 ( V_15 , V_2 , false , V_33 ) ;
}
void F_89 ( unsigned long V_15 , T_1 V_2 )
{
F_28 ( V_15 , V_2 , true , V_33 ) ;
}
void F_90 ( void ) {}
void F_91 ( const void * V_15 , T_1 V_2 )
{
F_1 ( V_15 , F_50 ( V_2 , V_19 ) ,
V_110 ) ;
}
void F_92 ( const void * V_15 , T_1 V_2 )
{
F_3 ( V_15 , V_2 ) ;
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
