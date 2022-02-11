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
if ( * V_2 > V_47 -
sizeof( struct V_48 ) -
sizeof( struct V_49 ) )
return;
* V_45 |= V_50 ;
V_44 -> V_51 . V_52 = * V_2 ;
* V_2 += sizeof( struct V_48 ) ;
if ( V_44 -> V_45 & V_53 || V_44 -> V_54 ||
V_44 -> V_41 < sizeof( struct V_49 ) ) {
V_44 -> V_51 . V_55 = * V_2 ;
* V_2 += sizeof( struct V_49 ) ;
}
V_46 = F_35 ( V_44 -> V_41 ) -
( * V_2 - V_44 -> V_41 ) ;
if ( V_46 > 0 )
* V_2 += V_46 ;
* V_2 = F_37 ( V_47 ,
F_38 ( * V_2 ,
V_44 -> V_41 +
F_35 ( V_44 -> V_41 ) ) ) ;
}
void F_39 ( struct V_43 * V_44 )
{
F_40 ( V_44 ) ;
}
void F_41 ( struct V_43 * V_44 )
{
F_40 ( V_44 ) ;
}
void F_42 ( struct V_37 * V_37 )
{
F_1 ( F_33 ( V_37 ) ,
V_39 << F_43 ( V_37 ) ,
V_56 ) ;
}
void F_44 ( struct V_43 * V_44 , void * V_57 )
{
F_3 ( V_57 , V_44 -> V_41 ) ;
}
void F_45 ( struct V_43 * V_44 , void * V_57 )
{
F_1 ( V_57 ,
F_46 ( V_44 -> V_41 , V_18 ) ,
V_56 ) ;
#ifdef F_47
if ( V_44 -> V_45 & V_50 ) {
struct V_48 * V_58 =
F_48 ( V_44 , V_57 ) ;
V_58 -> V_59 = V_60 ;
}
#endif
}
static inline int F_49 ( unsigned long V_61 )
{
return ( V_61 >= ( unsigned long ) & V_62 &&
V_61 < ( unsigned long ) & V_63 ) ||
( V_61 >= ( unsigned long ) & V_64 &&
V_61 < ( unsigned long ) & V_65 ) ;
}
static inline void F_50 ( struct V_66 * V_67 )
{
int V_68 ;
if ( ! V_67 -> V_69 )
return;
for ( V_68 = 0 ; V_68 < V_67 -> V_69 ; V_68 ++ )
if ( F_49 ( V_67 -> V_70 [ V_68 ] ) ) {
V_67 -> V_69 = V_68 + 1 ;
break;
}
}
static inline T_8 F_51 ( T_9 V_45 )
{
unsigned long V_70 [ V_71 ] ;
struct V_66 V_67 = {
. V_69 = 0 ,
. V_70 = V_70 ,
. V_72 = V_71 ,
. V_73 = 0
} ;
F_52 ( & V_67 ) ;
F_50 ( & V_67 ) ;
if ( V_67 . V_69 != 0 &&
V_67 . V_70 [ V_67 . V_69 - 1 ] == V_74 )
V_67 . V_69 -- ;
return F_53 ( & V_67 , V_45 ) ;
}
static inline void F_54 ( struct V_75 * V_76 , T_9 V_45 )
{
V_76 -> V_77 = V_13 -> V_77 ;
V_76 -> V_78 = F_51 ( V_45 ) ;
}
struct V_48 * F_48 ( struct V_43 * V_44 ,
const void * V_57 )
{
F_55 ( sizeof( struct V_48 ) > 32 ) ;
return ( void * ) V_57 + V_44 -> V_51 . V_52 ;
}
struct V_49 * F_56 ( struct V_43 * V_44 ,
const void * V_57 )
{
F_55 ( sizeof( struct V_49 ) > 32 ) ;
return ( void * ) V_57 + V_44 -> V_51 . V_55 ;
}
void F_57 ( struct V_43 * V_44 , void * V_57 , T_9 V_45 )
{
F_58 ( V_44 , V_57 , V_44 -> V_41 , V_45 ) ;
}
static void F_59 ( struct V_43 * V_44 , void * V_57 )
{
unsigned long V_2 = V_44 -> V_41 ;
unsigned long V_79 = F_46 ( V_2 , V_18 ) ;
if ( F_9 ( V_44 -> V_45 & V_53 ) )
return;
F_1 ( V_57 , V_79 , V_80 ) ;
}
bool F_60 ( struct V_43 * V_44 , void * V_57 )
{
#ifdef F_47
if ( F_9 ( V_44 -> V_45 & V_53 ) )
return false ;
if ( F_11 ( V_44 -> V_45 & V_50 ) ) {
struct V_48 * V_58 =
F_48 ( V_44 , V_57 ) ;
struct V_49 * V_81 =
F_56 ( V_44 , V_57 ) ;
switch ( V_58 -> V_59 ) {
case V_82 :
V_58 -> V_59 = V_83 ;
F_61 ( V_81 , V_44 ) ;
F_54 ( & V_81 -> V_76 , V_84 ) ;
F_59 ( V_44 , V_57 ) ;
return true ;
case V_83 :
case V_85 :
F_62 ( L_1 ) ;
F_63 () ;
break;
default:
break;
}
}
return false ;
#else
F_59 ( V_44 , V_57 ) ;
return false ;
#endif
}
void F_58 ( struct V_43 * V_44 , const void * V_57 , T_1 V_2 ,
T_9 V_45 )
{
unsigned long V_86 ;
unsigned long V_87 ;
if ( V_45 & V_88 )
F_64 () ;
if ( F_9 ( V_57 == NULL ) )
return;
V_86 = F_46 ( ( unsigned long ) ( V_57 + V_2 ) ,
V_18 ) ;
V_87 = F_46 ( ( unsigned long ) V_57 + V_44 -> V_41 ,
V_18 ) ;
F_3 ( V_57 , V_2 ) ;
F_1 ( ( void * ) V_86 , V_87 - V_86 ,
V_56 ) ;
#ifdef F_47
if ( V_44 -> V_45 & V_50 ) {
struct V_48 * V_58 =
F_48 ( V_44 , V_57 ) ;
V_58 -> V_59 = V_82 ;
V_58 -> V_89 = V_2 ;
F_54 ( & V_58 -> V_76 , V_45 ) ;
}
#endif
}
void F_65 ( const void * V_61 , T_1 V_2 , T_9 V_45 )
{
struct V_37 * V_37 ;
unsigned long V_86 ;
unsigned long V_87 ;
if ( V_45 & V_88 )
F_64 () ;
if ( F_9 ( V_61 == NULL ) )
return;
V_37 = F_66 ( V_61 ) ;
V_86 = F_46 ( ( unsigned long ) ( V_61 + V_2 ) ,
V_18 ) ;
V_87 = ( unsigned long ) V_61 + ( V_39 << F_43 ( V_37 ) ) ;
F_3 ( V_61 , V_2 ) ;
F_1 ( ( void * ) V_86 , V_87 - V_86 ,
V_90 ) ;
}
void F_67 ( const void * V_57 , T_1 V_2 , T_9 V_45 )
{
struct V_37 * V_37 ;
if ( F_9 ( V_57 == V_91 ) )
return;
V_37 = F_68 ( V_57 ) ;
if ( F_9 ( ! F_69 ( V_37 ) ) )
F_65 ( V_57 , V_2 , V_45 ) ;
else
F_58 ( V_37 -> V_92 , V_57 , V_2 , V_45 ) ;
}
void F_70 ( void * V_61 )
{
struct V_37 * V_37 ;
V_37 = F_68 ( V_61 ) ;
if ( F_9 ( ! F_69 ( V_37 ) ) )
F_1 ( V_61 , V_39 << F_43 ( V_37 ) ,
V_40 ) ;
else
F_59 ( V_37 -> V_92 , V_61 ) ;
}
void F_71 ( const void * V_61 )
{
struct V_37 * V_37 = F_66 ( V_61 ) ;
F_1 ( V_61 , V_39 << F_43 ( V_37 ) ,
V_40 ) ;
}
int F_72 ( void * V_14 , T_1 V_2 )
{
void * V_23 ;
T_1 V_93 ;
unsigned long V_4 ;
V_4 = ( unsigned long ) F_2 ( V_14 ) ;
V_93 = F_46 ( V_2 >> V_94 ,
V_39 ) ;
if ( F_73 ( ! F_74 ( V_4 ) ) )
return - V_95 ;
V_23 = F_75 ( V_93 , 1 , V_4 ,
V_4 + V_93 ,
V_96 | V_97 | V_98 ,
V_99 , V_100 , V_101 ,
F_76 ( 0 ) ) ;
if ( V_23 ) {
F_77 ( V_14 ) -> V_45 |= V_102 ;
F_78 ( V_23 ) ;
return 0 ;
}
return - V_103 ;
}
void F_79 ( const struct V_104 * V_105 )
{
if ( V_105 -> V_45 & V_102 )
F_80 ( F_2 ( V_105 -> V_14 ) ) ;
}
static void F_81 ( struct V_106 * V_107 )
{
T_1 V_108 = F_46 ( V_107 -> V_2 , V_18 ) ;
F_3 ( V_107 -> V_109 , V_107 -> V_2 ) ;
F_1 ( V_107 -> V_109 + V_108 ,
V_107 -> V_110 - V_108 ,
V_111 ) ;
}
void F_82 ( struct V_106 * V_112 , T_1 V_2 )
{
int V_68 ;
for ( V_68 = 0 ; V_68 < V_2 ; V_68 ++ )
F_81 ( & V_112 [ V_68 ] ) ;
}
void F_83 ( struct V_106 * V_112 , T_1 V_2 )
{
}
void F_84 ( unsigned long V_14 , T_1 V_2 )
{
F_25 ( V_14 , V_2 , false , V_32 ) ;
}
void F_85 ( unsigned long V_14 , T_1 V_2 )
{
F_25 ( V_14 , V_2 , true , V_32 ) ;
}
void F_86 ( void ) {}
static int F_87 ( struct V_113 * V_114 ,
unsigned long V_115 , void * V_116 )
{
return ( V_115 == V_117 ) ? V_118 : V_119 ;
}
static int T_10 F_88 ( void )
{
F_89 ( L_2 ) ;
F_89 ( L_3 ) ;
F_90 ( F_87 , 0 ) ;
return 0 ;
}
