void F_1 ( void )
{
V_1 -> V_2 ++ ;
}
void F_2 ( void )
{
V_1 -> V_2 -- ;
}
static void F_3 ( const void * V_3 , T_1 V_4 , T_2 V_5 )
{
void * V_6 , * V_7 ;
V_6 = F_4 ( V_3 ) ;
V_7 = F_4 ( V_3 + V_4 ) ;
memset ( V_6 , V_5 , V_7 - V_6 ) ;
}
void F_5 ( const void * V_3 , T_1 V_4 )
{
F_3 ( V_3 , V_4 , 0 ) ;
if ( V_4 & V_8 ) {
T_2 * V_9 = ( T_2 * ) F_4 ( V_3 + V_4 ) ;
* V_9 = V_4 & V_8 ;
}
}
static void F_6 ( struct V_10 * V_11 , const void * V_12 )
{
void * V_13 = F_7 ( V_11 ) ;
T_1 V_4 = V_12 - V_13 ;
F_5 ( V_13 , V_4 ) ;
}
void F_8 ( struct V_10 * V_11 )
{
F_6 ( V_11 , F_7 ( V_11 ) + V_14 ) ;
}
T_3 void F_9 ( const void * V_15 )
{
void * V_13 = ( void * ) ( ( unsigned long ) V_15 & ~ ( V_14 - 1 ) ) ;
F_5 ( V_13 , V_15 - V_13 ) ;
}
void F_10 ( const void * V_15 )
{
const void * V_12 = F_11 ( 0 ) ;
T_1 V_4 = V_15 - V_12 ;
if ( F_12 ( V_12 > V_15 ) )
return;
F_5 ( V_12 , V_4 ) ;
}
static T_4 bool F_13 ( unsigned long V_16 )
{
T_5 V_17 = * ( T_5 * ) F_4 ( ( void * ) V_16 ) ;
if ( F_14 ( V_17 ) ) {
T_5 V_18 = V_16 & V_8 ;
return F_14 ( V_18 >= V_17 ) ;
}
return false ;
}
static T_4 bool F_15 ( unsigned long V_16 )
{
T_6 * V_19 = ( T_6 * ) F_4 ( ( void * ) V_16 ) ;
if ( F_14 ( * V_19 ) ) {
if ( F_13 ( V_16 + 1 ) )
return true ;
if ( F_16 ( ( ( V_16 + 1 ) & V_8 ) != 0 ) )
return false ;
return F_14 ( * ( T_2 * ) V_19 ) ;
}
return false ;
}
static T_4 bool F_17 ( unsigned long V_16 )
{
T_6 * V_19 = ( T_6 * ) F_4 ( ( void * ) V_16 ) ;
if ( F_14 ( * V_19 ) ) {
if ( F_13 ( V_16 + 3 ) )
return true ;
if ( F_16 ( ( ( V_16 + 3 ) & V_8 ) >= 3 ) )
return false ;
return F_14 ( * ( T_2 * ) V_19 ) ;
}
return false ;
}
static T_4 bool F_18 ( unsigned long V_16 )
{
T_6 * V_19 = ( T_6 * ) F_4 ( ( void * ) V_16 ) ;
if ( F_14 ( * V_19 ) ) {
if ( F_13 ( V_16 + 7 ) )
return true ;
if ( F_16 ( F_19 ( V_16 , V_20 ) ) )
return false ;
return F_14 ( * ( T_2 * ) V_19 ) ;
}
return false ;
}
static T_4 bool F_20 ( unsigned long V_16 )
{
T_7 * V_19 = ( T_7 * ) F_4 ( ( void * ) V_16 ) ;
if ( F_14 ( * V_19 ) ) {
T_6 V_21 = * ( T_6 * ) V_19 ;
if ( F_14 ( V_21 ) )
return true ;
if ( F_16 ( F_19 ( V_16 , V_20 ) ) )
return false ;
return F_13 ( V_16 + 15 ) ;
}
return false ;
}
static T_4 unsigned long F_21 ( const T_2 * V_22 ,
T_1 V_4 )
{
while ( V_4 ) {
if ( F_14 ( * V_22 ) )
return ( unsigned long ) V_22 ;
V_22 ++ ;
V_4 -- ;
}
return 0 ;
}
static T_4 unsigned long F_22 ( const void * V_22 ,
const void * V_23 )
{
unsigned int V_24 ;
unsigned long V_25 ;
unsigned int V_26 = ( unsigned long ) V_22 % 8 ;
if ( V_23 - V_22 <= 16 )
return F_21 ( V_22 , V_23 - V_22 ) ;
if ( V_26 ) {
V_26 = 8 - V_26 ;
V_25 = F_21 ( V_22 , V_26 ) ;
if ( F_14 ( V_25 ) )
return V_25 ;
V_22 += V_26 ;
}
V_24 = ( V_23 - V_22 ) / 8 ;
while ( V_24 ) {
if ( F_14 ( * ( V_27 * ) V_22 ) )
return F_21 ( V_22 , 8 ) ;
V_22 += 8 ;
V_24 -- ;
}
return F_21 ( V_22 , ( V_23 - V_22 ) % 8 ) ;
}
static T_4 bool F_23 ( unsigned long V_16 ,
T_1 V_4 )
{
unsigned long V_25 ;
V_25 = F_22 ( F_4 ( ( void * ) V_16 ) ,
F_4 ( ( void * ) V_16 + V_4 - 1 ) + 1 ) ;
if ( F_14 ( V_25 ) ) {
unsigned long V_28 = V_16 + V_4 - 1 ;
T_5 * V_29 = ( T_5 * ) F_4 ( ( void * ) V_28 ) ;
if ( F_14 ( V_25 != ( unsigned long ) V_29 ||
( ( long ) ( V_28 & V_8 ) >= * V_29 ) ) )
return true ;
}
return false ;
}
static T_4 bool F_24 ( unsigned long V_16 , T_1 V_4 )
{
if ( F_25 ( V_4 ) ) {
switch ( V_4 ) {
case 1 :
return F_13 ( V_16 ) ;
case 2 :
return F_15 ( V_16 ) ;
case 4 :
return F_17 ( V_16 ) ;
case 8 :
return F_18 ( V_16 ) ;
case 16 :
return F_20 ( V_16 ) ;
default:
F_26 () ;
}
}
return F_23 ( V_16 , V_4 ) ;
}
static T_4 void F_27 ( unsigned long V_16 ,
T_1 V_4 , bool V_30 ,
unsigned long V_31 )
{
if ( F_14 ( V_4 == 0 ) )
return;
if ( F_14 ( ( void * ) V_16 <
F_28 ( ( void * ) V_32 ) ) ) {
F_29 ( V_16 , V_4 , V_30 , V_31 ) ;
return;
}
if ( F_16 ( ! F_24 ( V_16 , V_4 ) ) )
return;
F_29 ( V_16 , V_4 , V_30 , V_31 ) ;
}
static void F_30 ( unsigned long V_16 ,
T_1 V_4 , bool V_30 ,
unsigned long V_31 )
{
F_27 ( V_16 , V_4 , V_30 , V_31 ) ;
}
void F_31 ( const void * V_33 , unsigned int V_4 )
{
F_30 ( ( unsigned long ) V_33 , V_4 , false , V_34 ) ;
}
void F_32 ( const void * V_33 , unsigned int V_4 )
{
F_30 ( ( unsigned long ) V_33 , V_4 , true , V_34 ) ;
}
void * memset ( void * V_16 , int V_35 , T_1 V_36 )
{
F_30 ( ( unsigned long ) V_16 , V_36 , true , V_34 ) ;
return F_33 ( V_16 , V_35 , V_36 ) ;
}
void * memmove ( void * V_37 , const void * V_38 , T_1 V_36 )
{
F_30 ( ( unsigned long ) V_38 , V_36 , false , V_34 ) ;
F_30 ( ( unsigned long ) V_37 , V_36 , true , V_34 ) ;
return F_34 ( V_37 , V_38 , V_36 ) ;
}
void * memcpy ( void * V_37 , const void * V_38 , T_1 V_36 )
{
F_30 ( ( unsigned long ) V_38 , V_36 , false , V_34 ) ;
F_30 ( ( unsigned long ) V_37 , V_36 , true , V_34 ) ;
return F_35 ( V_37 , V_38 , V_36 ) ;
}
void F_36 ( struct V_39 * V_39 , unsigned int V_40 )
{
if ( F_16 ( ! F_37 ( V_39 ) ) )
F_5 ( F_38 ( V_39 ) , V_41 << V_40 ) ;
}
void F_39 ( struct V_39 * V_39 , unsigned int V_40 )
{
if ( F_16 ( ! F_37 ( V_39 ) ) )
F_3 ( F_38 ( V_39 ) ,
V_41 << V_40 ,
V_42 ) ;
}
static T_1 F_40 ( T_1 V_43 )
{
int V_44 =
V_43 <= 64 - 16 ? 16 :
V_43 <= 128 - 32 ? 32 :
V_43 <= 512 - 64 ? 64 :
V_43 <= 4096 - 128 ? 128 :
V_43 <= ( 1 << 14 ) - 256 ? 256 :
V_43 <= ( 1 << 15 ) - 512 ? 512 :
V_43 <= ( 1 << 16 ) - 1024 ? 1024 : 2048 ;
return V_44 ;
}
void F_41 ( struct V_45 * V_46 , T_1 * V_4 ,
unsigned long * V_47 )
{
int V_48 ;
int V_49 = * V_4 ;
V_46 -> V_50 . V_51 = * V_4 ;
* V_4 += sizeof( struct V_52 ) ;
if ( V_46 -> V_47 & V_53 || V_46 -> V_54 ||
V_46 -> V_43 < sizeof( struct V_55 ) ) {
V_46 -> V_50 . V_56 = * V_4 ;
* V_4 += sizeof( struct V_55 ) ;
}
V_48 = F_40 ( V_46 -> V_43 ) -
( * V_4 - V_46 -> V_43 ) ;
if ( V_48 > 0 )
* V_4 += V_48 ;
* V_4 = F_42 ( V_57 , F_43 ( * V_4 , V_46 -> V_43 +
F_40 ( V_46 -> V_43 ) ) ) ;
if ( * V_4 <= V_46 -> V_50 . V_51 ||
* V_4 <= V_46 -> V_50 . V_56 ) {
V_46 -> V_50 . V_51 = 0 ;
V_46 -> V_50 . V_56 = 0 ;
* V_4 = V_49 ;
return;
}
* V_47 |= V_58 ;
}
void F_44 ( struct V_45 * V_46 )
{
F_45 ( V_46 ) ;
}
void F_46 ( struct V_45 * V_46 )
{
F_45 ( V_46 ) ;
}
T_1 F_47 ( struct V_45 * V_46 )
{
return ( V_46 -> V_50 . V_51 ?
sizeof( struct V_52 ) : 0 ) +
( V_46 -> V_50 . V_56 ?
sizeof( struct V_55 ) : 0 ) ;
}
void F_48 ( struct V_39 * V_39 )
{
F_3 ( F_38 ( V_39 ) ,
V_41 << F_49 ( V_39 ) ,
V_59 ) ;
}
void F_50 ( struct V_45 * V_46 , void * V_60 )
{
F_5 ( V_60 , V_46 -> V_43 ) ;
}
void F_51 ( struct V_45 * V_46 , void * V_60 )
{
F_3 ( V_60 ,
F_52 ( V_46 -> V_43 , V_20 ) ,
V_59 ) ;
}
static inline int F_53 ( unsigned long V_61 )
{
return ( V_61 >= ( unsigned long ) & V_62 &&
V_61 < ( unsigned long ) & V_63 ) ||
( V_61 >= ( unsigned long ) & V_64 &&
V_61 < ( unsigned long ) & V_65 ) ;
}
static inline void F_54 ( struct V_66 * V_67 )
{
int V_68 ;
if ( ! V_67 -> V_69 )
return;
for ( V_68 = 0 ; V_68 < V_67 -> V_69 ; V_68 ++ )
if ( F_53 ( V_67 -> V_70 [ V_68 ] ) ) {
V_67 -> V_69 = V_68 + 1 ;
break;
}
}
static inline T_8 F_55 ( T_9 V_47 )
{
unsigned long V_70 [ V_71 ] ;
struct V_66 V_67 = {
. V_69 = 0 ,
. V_70 = V_70 ,
. V_72 = V_71 ,
. V_73 = 0
} ;
F_56 ( & V_67 ) ;
F_54 ( & V_67 ) ;
if ( V_67 . V_69 != 0 &&
V_67 . V_70 [ V_67 . V_69 - 1 ] == V_74 )
V_67 . V_69 -- ;
return F_57 ( & V_67 , V_47 ) ;
}
static inline void F_58 ( struct V_75 * V_76 , T_9 V_47 )
{
V_76 -> V_77 = V_1 -> V_77 ;
V_76 -> V_78 = F_55 ( V_47 ) ;
}
struct V_52 * F_59 ( struct V_45 * V_46 ,
const void * V_60 )
{
F_60 ( sizeof( struct V_52 ) > 32 ) ;
return ( void * ) V_60 + V_46 -> V_50 . V_51 ;
}
struct V_55 * F_61 ( struct V_45 * V_46 ,
const void * V_60 )
{
F_60 ( sizeof( struct V_55 ) > 32 ) ;
return ( void * ) V_60 + V_46 -> V_50 . V_56 ;
}
void F_62 ( struct V_45 * V_46 , const void * V_60 )
{
struct V_52 * V_79 ;
if ( ! ( V_46 -> V_47 & V_58 ) )
return;
V_79 = F_59 ( V_46 , V_60 ) ;
F_33 ( V_79 , 0 , sizeof( * V_79 ) ) ;
}
void F_63 ( struct V_45 * V_46 , void * V_60 , T_9 V_47 )
{
F_64 ( V_46 , V_60 , V_46 -> V_43 , V_47 ) ;
}
static void F_65 ( struct V_45 * V_46 , void * V_60 )
{
unsigned long V_4 = V_46 -> V_43 ;
unsigned long V_80 = F_52 ( V_4 , V_20 ) ;
if ( F_14 ( V_46 -> V_47 & V_53 ) )
return;
F_3 ( V_60 , V_80 , V_81 ) ;
}
bool F_66 ( struct V_45 * V_46 , void * V_60 )
{
T_5 V_82 ;
if ( F_14 ( V_46 -> V_47 & V_53 ) )
return false ;
V_82 = F_67 ( * ( T_5 * ) F_4 ( V_60 ) ) ;
if ( V_82 < 0 || V_82 >= V_20 ) {
F_68 ( V_46 , V_60 , V_82 ) ;
return true ;
}
F_65 ( V_46 , V_60 ) ;
if ( F_14 ( ! ( V_46 -> V_47 & V_58 ) ) )
return false ;
F_58 ( & F_59 ( V_46 , V_60 ) -> V_83 , V_84 ) ;
F_69 ( F_61 ( V_46 , V_60 ) , V_46 ) ;
return true ;
}
void F_64 ( struct V_45 * V_46 , const void * V_60 , T_1 V_4 ,
T_9 V_47 )
{
unsigned long V_85 ;
unsigned long V_86 ;
if ( F_70 ( V_47 ) )
F_71 () ;
if ( F_14 ( V_60 == NULL ) )
return;
V_85 = F_52 ( ( unsigned long ) ( V_60 + V_4 ) ,
V_20 ) ;
V_86 = F_52 ( ( unsigned long ) V_60 + V_46 -> V_43 ,
V_20 ) ;
F_5 ( V_60 , V_4 ) ;
F_3 ( ( void * ) V_85 , V_86 - V_85 ,
V_59 ) ;
if ( V_46 -> V_47 & V_58 )
F_58 ( & F_59 ( V_46 , V_60 ) -> V_87 , V_47 ) ;
}
void F_72 ( const void * V_61 , T_1 V_4 , T_9 V_47 )
{
struct V_39 * V_39 ;
unsigned long V_85 ;
unsigned long V_86 ;
if ( F_70 ( V_47 ) )
F_71 () ;
if ( F_14 ( V_61 == NULL ) )
return;
V_39 = F_73 ( V_61 ) ;
V_85 = F_52 ( ( unsigned long ) ( V_61 + V_4 ) ,
V_20 ) ;
V_86 = ( unsigned long ) V_61 + ( V_41 << F_49 ( V_39 ) ) ;
F_5 ( V_61 , V_4 ) ;
F_3 ( ( void * ) V_85 , V_86 - V_85 ,
V_88 ) ;
}
void F_74 ( const void * V_60 , T_1 V_4 , T_9 V_47 )
{
struct V_39 * V_39 ;
if ( F_14 ( V_60 == V_89 ) )
return;
V_39 = F_75 ( V_60 ) ;
if ( F_14 ( ! F_76 ( V_39 ) ) )
F_72 ( V_60 , V_4 , V_47 ) ;
else
F_64 ( V_39 -> V_90 , V_60 , V_4 , V_47 ) ;
}
void F_77 ( void * V_61 )
{
struct V_39 * V_39 ;
V_39 = F_75 ( V_61 ) ;
if ( F_14 ( ! F_76 ( V_39 ) ) )
F_3 ( V_61 , V_41 << F_49 ( V_39 ) ,
V_42 ) ;
else
F_65 ( V_39 -> V_90 , V_61 ) ;
}
void F_78 ( const void * V_61 )
{
struct V_39 * V_39 = F_73 ( V_61 ) ;
F_3 ( V_61 , V_41 << F_49 ( V_39 ) ,
V_42 ) ;
}
int F_79 ( void * V_16 , T_1 V_4 )
{
void * V_25 ;
T_1 V_91 ;
unsigned long V_6 ;
V_6 = ( unsigned long ) F_4 ( V_16 ) ;
V_91 = F_52 ( V_4 >> V_92 ,
V_41 ) ;
if ( F_12 ( ! F_80 ( V_6 ) ) )
return - V_93 ;
V_25 = F_81 ( V_91 , 1 , V_6 ,
V_6 + V_91 ,
V_94 | V_95 | V_96 ,
V_97 , V_98 , V_99 ,
F_82 ( 0 ) ) ;
if ( V_25 ) {
F_83 ( V_16 ) -> V_47 |= V_100 ;
F_84 ( V_25 ) ;
return 0 ;
}
return - V_101 ;
}
void F_85 ( const struct V_102 * V_103 )
{
if ( V_103 -> V_47 & V_100 )
F_86 ( F_4 ( V_103 -> V_16 ) ) ;
}
static void F_87 ( struct V_104 * V_105 )
{
T_1 V_106 = F_52 ( V_105 -> V_4 , V_20 ) ;
F_5 ( V_105 -> V_107 , V_105 -> V_4 ) ;
F_3 ( V_105 -> V_107 + V_106 ,
V_105 -> V_108 - V_106 ,
V_109 ) ;
}
void F_88 ( struct V_104 * V_110 , T_1 V_4 )
{
int V_68 ;
for ( V_68 = 0 ; V_68 < V_4 ; V_68 ++ )
F_87 ( & V_110 [ V_68 ] ) ;
}
void F_89 ( struct V_104 * V_110 , T_1 V_4 )
{
}
void F_90 ( unsigned long V_16 , T_1 V_4 )
{
F_30 ( V_16 , V_4 , false , V_34 ) ;
}
void F_91 ( unsigned long V_16 , T_1 V_4 )
{
F_30 ( V_16 , V_4 , true , V_34 ) ;
}
void F_92 ( void ) {}
void F_93 ( const void * V_16 , T_1 V_4 )
{
F_3 ( V_16 , F_52 ( V_4 , V_20 ) ,
V_111 ) ;
}
void F_94 ( const void * V_16 , T_1 V_4 )
{
F_5 ( V_16 , V_4 ) ;
}
static int F_95 ( struct V_112 * V_113 ,
unsigned long V_114 , void * V_115 )
{
return ( V_114 == V_116 ) ? V_117 : V_118 ;
}
static int T_10 F_96 ( void )
{
F_97 ( L_1 ) ;
F_97 ( L_2 ) ;
F_98 ( F_95 , 0 ) ;
return 0 ;
}
