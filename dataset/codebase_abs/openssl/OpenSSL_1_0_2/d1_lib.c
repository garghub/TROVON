long F_1 ( void )
{
return ( 60 * 60 * 2 ) ;
}
int F_2 ( T_1 * V_1 )
{
T_2 * V_2 ;
if ( ! F_3 ( V_1 ) )
return ( 0 ) ;
if ( ( V_2 = F_4 ( sizeof *V_2 ) ) == NULL )
return ( 0 ) ;
memset ( V_2 , 0 , sizeof *V_2 ) ;
V_2 -> V_3 . V_4 = F_5 () ;
V_2 -> V_5 . V_4 = F_5 () ;
V_2 -> V_6 = F_5 () ;
V_2 -> V_7 = F_5 () ;
V_2 -> V_8 . V_4 = F_5 () ;
if ( V_1 -> V_9 ) {
V_2 -> V_10 = sizeof( V_1 -> V_2 -> V_11 ) ;
}
V_2 -> V_12 = 0 ;
V_2 -> V_13 = 0 ;
if ( ! V_2 -> V_3 . V_4 || ! V_2 -> V_5 . V_4
|| ! V_2 -> V_6 || ! V_2 -> V_7
|| ! V_2 -> V_8 . V_4 ) {
if ( V_2 -> V_3 . V_4 )
F_6 ( V_2 -> V_3 . V_4 ) ;
if ( V_2 -> V_5 . V_4 )
F_6 ( V_2 -> V_5 . V_4 ) ;
if ( V_2 -> V_6 )
F_6 ( V_2 -> V_6 ) ;
if ( V_2 -> V_7 )
F_6 ( V_2 -> V_7 ) ;
if ( V_2 -> V_8 . V_4 )
F_6 ( V_2 -> V_8 . V_4 ) ;
F_7 ( V_2 ) ;
return ( 0 ) ;
}
V_1 -> V_2 = V_2 ;
V_1 -> V_14 -> V_15 ( V_1 ) ;
return ( 1 ) ;
}
static void F_8 ( T_1 * V_1 )
{
T_3 * V_16 = NULL ;
T_4 * V_17 = NULL ;
T_5 * V_18 ;
while ( ( V_16 = F_9 ( V_1 -> V_2 -> V_3 . V_4 ) ) != NULL ) {
V_18 = ( T_5 * ) V_16 -> V_19 ;
if ( V_18 -> V_20 . V_21 ) {
F_7 ( V_18 -> V_20 . V_21 ) ;
}
F_7 ( V_16 -> V_19 ) ;
F_10 ( V_16 ) ;
}
while ( ( V_16 = F_9 ( V_1 -> V_2 -> V_5 . V_4 ) ) != NULL ) {
V_18 = ( T_5 * ) V_16 -> V_19 ;
if ( V_18 -> V_20 . V_21 ) {
F_7 ( V_18 -> V_20 . V_21 ) ;
}
F_7 ( V_16 -> V_19 ) ;
F_10 ( V_16 ) ;
}
while ( ( V_16 = F_9 ( V_1 -> V_2 -> V_6 ) ) != NULL ) {
V_17 = ( T_4 * ) V_16 -> V_19 ;
F_11 ( V_17 ) ;
F_10 ( V_16 ) ;
}
while ( ( V_16 = F_9 ( V_1 -> V_2 -> V_7 ) ) != NULL ) {
V_17 = ( T_4 * ) V_16 -> V_19 ;
F_11 ( V_17 ) ;
F_10 ( V_16 ) ;
}
while ( ( V_16 = F_9 ( V_1 -> V_2 -> V_8 . V_4 ) ) != NULL ) {
V_18 = ( T_5 * ) V_16 -> V_19 ;
if ( V_18 -> V_20 . V_21 ) {
F_7 ( V_18 -> V_20 . V_21 ) ;
}
F_7 ( V_16 -> V_19 ) ;
F_10 ( V_16 ) ;
}
}
void F_12 ( T_1 * V_1 )
{
F_13 ( V_1 ) ;
F_8 ( V_1 ) ;
F_6 ( V_1 -> V_2 -> V_3 . V_4 ) ;
F_6 ( V_1 -> V_2 -> V_5 . V_4 ) ;
F_6 ( V_1 -> V_2 -> V_6 ) ;
F_6 ( V_1 -> V_2 -> V_7 ) ;
F_6 ( V_1 -> V_2 -> V_8 . V_4 ) ;
F_7 ( V_1 -> V_2 ) ;
V_1 -> V_2 = NULL ;
}
void F_14 ( T_1 * V_1 )
{
T_6 V_3 ;
T_6 V_5 ;
T_6 V_6 ;
T_6 V_7 ;
T_6 V_8 ;
unsigned int V_13 ;
unsigned int V_12 ;
if ( V_1 -> V_2 ) {
V_3 = V_1 -> V_2 -> V_3 . V_4 ;
V_5 = V_1 -> V_2 -> V_5 . V_4 ;
V_6 = V_1 -> V_2 -> V_6 ;
V_7 = V_1 -> V_2 -> V_7 ;
V_8 = V_1 -> V_2 -> V_8 . V_4 ;
V_13 = V_1 -> V_2 -> V_13 ;
V_12 = V_1 -> V_2 -> V_12 ;
F_8 ( V_1 ) ;
memset ( V_1 -> V_2 , 0 , sizeof( * ( V_1 -> V_2 ) ) ) ;
if ( V_1 -> V_9 ) {
V_1 -> V_2 -> V_10 = sizeof( V_1 -> V_2 -> V_11 ) ;
}
if ( F_15 ( V_1 ) & V_22 ) {
V_1 -> V_2 -> V_13 = V_13 ;
V_1 -> V_2 -> V_12 = V_12 ;
}
V_1 -> V_2 -> V_3 . V_4 = V_3 ;
V_1 -> V_2 -> V_5 . V_4 = V_5 ;
V_1 -> V_2 -> V_6 = V_6 ;
V_1 -> V_2 -> V_7 = V_7 ;
V_1 -> V_2 -> V_8 . V_4 = V_8 ;
}
F_16 ( V_1 ) ;
if ( V_1 -> V_23 & V_24 )
V_1 -> V_25 = V_26 ;
else if ( V_1 -> V_14 -> V_25 == V_27 )
V_1 -> V_25 = V_28 ;
else
V_1 -> V_25 = V_1 -> V_14 -> V_25 ;
}
long F_17 ( T_1 * V_1 , int V_29 , long V_30 , void * V_31 )
{
int V_32 = 0 ;
switch ( V_29 ) {
case V_33 :
if ( F_18 ( V_1 , (struct V_34 * ) V_31 ) != NULL ) {
V_32 = 1 ;
}
break;
case V_35 :
V_32 = F_19 ( V_1 ) ;
break;
case V_36 :
V_32 = F_20 ( V_1 , V_31 ) ;
break;
case V_37 :
if ( V_1 -> V_25 == V_1 -> V_38 -> V_14 -> V_25 )
return 1 ;
if ( V_1 -> V_38 -> V_14 -> V_25 == F_21 () -> V_25 ) {
#if V_39 != V_28
# error Code needs update for DTLS_method() support beyond DTLS1_2_VERSION.
#endif
if ( ! ( V_1 -> V_23 & V_40 ) )
return V_1 -> V_25 == V_28 ;
if ( ! ( V_1 -> V_23 & V_41 ) )
return V_1 -> V_25 == V_42 ;
}
return 0 ;
case V_43 :
if ( V_30 < ( long ) F_22 () )
return 0 ;
V_1 -> V_2 -> V_12 = V_30 ;
return 1 ;
case V_44 :
return ( long ) F_22 () ;
case V_45 :
if ( V_30 < ( long ) F_22 () - V_46 )
return 0 ;
V_1 -> V_2 -> V_13 = V_30 ;
return V_30 ;
default:
V_32 = F_23 ( V_1 , V_29 , V_30 , V_31 ) ;
break;
}
return ( V_32 ) ;
}
const T_7 * F_24 ( unsigned int V_47 )
{
const T_7 * V_48 = F_25 ( V_47 ) ;
if ( V_48 != NULL ) {
if ( V_48 -> V_49 == V_50 )
return NULL ;
}
return V_48 ;
}
void F_26 ( T_1 * V_1 )
{
#ifndef F_27
if ( F_28 ( F_29 ( V_1 ) ) ) {
memset ( & ( V_1 -> V_2 -> V_51 ) , 0 , sizeof( struct V_34 ) ) ;
return;
}
#endif
if ( V_1 -> V_2 -> V_51 . V_52 == 0 && V_1 -> V_2 -> V_51 . V_53 == 0 ) {
V_1 -> V_2 -> V_54 = 1 ;
}
F_30 ( & ( V_1 -> V_2 -> V_51 ) ) ;
V_1 -> V_2 -> V_51 . V_52 += V_1 -> V_2 -> V_54 ;
F_31 ( F_32 ( V_1 ) , V_55 , 0 ,
& ( V_1 -> V_2 -> V_51 ) ) ;
}
struct V_34 * F_18 ( T_1 * V_1 , struct V_34 * V_56 )
{
struct V_34 V_57 ;
if ( V_1 -> V_2 -> V_51 . V_52 == 0 && V_1 -> V_2 -> V_51 . V_53 == 0 ) {
return NULL ;
}
F_30 ( & V_57 ) ;
if ( V_1 -> V_2 -> V_51 . V_52 < V_57 . V_52 ||
( V_1 -> V_2 -> V_51 . V_52 == V_57 . V_52 &&
V_1 -> V_2 -> V_51 . V_53 <= V_57 . V_53 ) ) {
memset ( V_56 , 0 , sizeof( struct V_34 ) ) ;
return V_56 ;
}
memcpy ( V_56 , & ( V_1 -> V_2 -> V_51 ) , sizeof( struct V_34 ) ) ;
V_56 -> V_52 -= V_57 . V_52 ;
V_56 -> V_53 -= V_57 . V_53 ;
if ( V_56 -> V_53 < 0 ) {
V_56 -> V_52 -- ;
V_56 -> V_53 += 1000000 ;
}
if ( V_56 -> V_52 == 0 && V_56 -> V_53 < 15000 ) {
memset ( V_56 , 0 , sizeof( struct V_34 ) ) ;
}
return V_56 ;
}
int F_33 ( T_1 * V_1 )
{
struct V_34 V_56 ;
if ( F_18 ( V_1 , & V_56 ) == NULL ) {
return 0 ;
}
if ( V_56 . V_52 > 0 || V_56 . V_53 > 0 ) {
return 0 ;
}
return 1 ;
}
void F_34 ( T_1 * V_1 )
{
V_1 -> V_2 -> V_54 *= 2 ;
if ( V_1 -> V_2 -> V_54 > 60 )
V_1 -> V_2 -> V_54 = 60 ;
F_26 ( V_1 ) ;
}
void F_35 ( T_1 * V_1 )
{
memset ( & ( V_1 -> V_2 -> V_58 ) , 0 , sizeof( struct V_59 ) ) ;
memset ( & ( V_1 -> V_2 -> V_51 ) , 0 , sizeof( struct V_34 ) ) ;
V_1 -> V_2 -> V_54 = 1 ;
F_31 ( F_32 ( V_1 ) , V_55 , 0 ,
& ( V_1 -> V_2 -> V_51 ) ) ;
F_36 ( V_1 ) ;
}
int F_37 ( T_1 * V_1 )
{
unsigned int V_13 ;
V_1 -> V_2 -> V_58 . V_60 ++ ;
if ( V_1 -> V_2 -> V_58 . V_60 > 2
&& ! ( F_15 ( V_1 ) & V_22 ) ) {
V_13 =
F_31 ( F_29 ( V_1 ) , V_61 , 0 ,
NULL ) ;
if ( V_13 < V_1 -> V_2 -> V_13 )
V_1 -> V_2 -> V_13 = V_13 ;
}
if ( V_1 -> V_2 -> V_58 . V_60 > V_62 ) {
F_38 ( V_63 , V_64 ) ;
return - 1 ;
}
return 0 ;
}
int F_19 ( T_1 * V_1 )
{
if ( ! F_33 ( V_1 ) ) {
return 0 ;
}
F_34 ( V_1 ) ;
if ( F_37 ( V_1 ) < 0 )
return - 1 ;
V_1 -> V_2 -> V_58 . V_65 ++ ;
if ( V_1 -> V_2 -> V_58 . V_65 > V_66 ) {
V_1 -> V_2 -> V_58 . V_65 = 1 ;
}
#ifndef F_39
if ( V_1 -> V_67 ) {
V_1 -> V_67 = 0 ;
return F_40 ( V_1 ) ;
}
#endif
F_26 ( V_1 ) ;
return F_41 ( V_1 ) ;
}
static void F_30 ( struct V_34 * V_68 )
{
#if F_42 ( V_69 )
T_8 V_70 ;
union {
unsigned T_9 V_71 ;
T_10 V_72 ;
} V_73 ;
F_43 ( & V_70 ) ;
F_44 ( & V_70 , & V_73 . V_72 ) ;
# ifdef F_45
V_73 . V_71 -= 116444736000000000ULL ;
# else
V_73 . V_71 -= 116444736000000000UI64 ;
# endif
V_68 -> V_52 = ( long ) ( V_73 . V_71 / 10000000 ) ;
V_68 -> V_53 = ( ( int ) ( V_73 . V_71 % 10000000 ) ) / 10 ;
#elif F_42 ( V_74 )
struct V_75 V_76 ;
F_46 ( & V_76 ) ;
V_68 -> V_52 = ( long ) V_76 . time ;
V_68 -> V_53 = ( long ) V_76 . V_77 * 1000 ;
#else
F_47 ( V_68 , NULL ) ;
#endif
}
int F_20 ( T_1 * V_1 , struct V_78 * V_79 )
{
int V_32 ;
F_48 ( V_1 , V_80 ) ;
V_1 -> V_2 -> V_81 = 1 ;
V_32 = F_49 ( V_1 ) ;
if ( V_32 <= 0 )
return V_32 ;
( void ) F_50 ( F_32 ( V_1 ) , V_79 ) ;
return 1 ;
}
static void F_51 ( T_1 * V_1 , int V_82 , unsigned long V_83 )
{
unsigned char * V_84 = ( unsigned char * ) V_1 -> V_85 -> V_19 ;
F_52 ( V_1 , V_84 , V_82 , V_83 , 0 , V_83 ) ;
V_1 -> V_86 = ( int ) V_83 + V_87 ;
V_1 -> V_88 = 0 ;
F_53 ( V_1 , 0 ) ;
}
static int F_54 ( T_1 * V_1 )
{
return F_55 ( V_1 , V_89 ) ;
}
