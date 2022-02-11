static void
F_1 ( void )
{
if ( ! V_1 )
F_2 ( V_2 , V_3 . V_4 ) ;
F_3 ( V_5 ) ;
}
static void * F_4 ( char const * V_6 )
{
void * V_7 ;
V_5 = F_5 ( V_6 , V_8 ) ;
if ( V_5 < 0 || F_6 ( V_5 , & V_3 ) < 0 ) {
perror ( V_6 ) ;
F_7 () ;
}
if ( ! F_8 ( V_3 . V_9 ) ) {
fprintf ( V_10 , L_1 , V_6 ) ;
F_7 () ;
}
V_7 = F_9 ( 0 , V_3 . V_4 , V_11 | V_12 , V_13 ,
V_5 , 0 ) ;
if ( V_7 == V_14 ) {
V_1 = 1 ;
fprintf ( V_10 , L_2 , V_6 ) ;
F_7 () ;
}
return V_7 ;
}
static T_1 F_10 ( const T_1 * V_15 )
{
return F_11 ( V_15 ) ;
}
static T_2 F_12 ( const T_2 * V_15 )
{
return F_13 ( V_15 ) ;
}
static T_3 F_14 ( const T_3 * V_15 )
{
return F_15 ( V_15 ) ;
}
static T_1 F_16 ( const T_1 * V_15 )
{
return F_17 ( V_15 ) ;
}
static T_2 F_18 ( const T_2 * V_15 )
{
return F_19 ( V_15 ) ;
}
static T_3 F_20 ( const T_3 * V_15 )
{
return F_21 ( V_15 ) ;
}
static void F_22 ( T_1 V_16 , T_1 * V_15 )
{
F_23 ( V_16 , V_15 ) ;
}
static void F_24 ( T_2 V_16 , T_2 * V_15 )
{
F_25 ( V_16 , V_15 ) ;
}
static void F_26 ( T_3 V_16 , T_3 * V_15 )
{
F_27 ( V_16 , V_15 ) ;
}
static void F_28 ( T_1 V_16 , T_1 * V_15 )
{
F_29 ( V_16 , V_15 ) ;
}
static void F_30 ( T_2 V_16 , T_2 * V_15 )
{
F_31 ( V_16 , V_15 ) ;
}
static void F_32 ( T_3 V_16 , T_3 * V_15 )
{
F_33 ( V_16 , V_15 ) ;
}
static inline int F_34 ( unsigned int V_17 )
{
return V_17 != V_18 && V_17 >= V_19 && V_17 <= V_20 ;
}
static inline unsigned int F_35 ( unsigned int V_21 ,
unsigned int V_22 ,
const T_4 * V_23 )
{
if ( F_34 ( V_21 ) )
return F_36 ( V_21 ) ;
if ( V_21 != V_18 )
return V_21 ;
return F_37 ( & V_23 [ V_22 ] ) ;
}
static int F_38 ( const void * V_24 , const void * V_25 )
{
T_5 V_26 = ( T_5 ) F_37 ( V_24 ) ;
T_5 V_27 = ( T_5 ) F_37 ( V_25 ) ;
if ( V_26 < V_27 )
return - 1 ;
if ( V_26 > V_27 )
return 1 ;
return 0 ;
}
static void F_39 ( char * V_28 , int V_29 )
{
int V_17 ;
V_17 = 0 ;
while ( V_17 < V_29 ) {
T_2 * V_30 = ( T_2 * ) ( V_28 + V_17 ) ;
F_40 ( F_37 ( V_30 ) + V_17 , V_30 ) ;
V_17 += 4 ;
}
qsort ( V_28 , V_29 / 8 , 8 , F_38 ) ;
V_17 = 0 ;
while ( V_17 < V_29 ) {
T_2 * V_30 = ( T_2 * ) ( V_28 + V_17 ) ;
F_40 ( F_37 ( V_30 ) - V_17 , V_30 ) ;
V_17 += 4 ;
}
}
static void
F_41 ( char const * const V_6 )
{
T_6 V_31 ;
T_7 * V_32 = F_4 ( V_6 ) ;
V_2 = V_32 ;
switch ( V_32 -> V_33 [ V_34 ] ) {
default:
fprintf ( V_10 , L_3 ,
V_32 -> V_33 [ V_34 ] , V_6 ) ;
F_7 () ;
break;
case V_35 :
F_37 = F_18 ;
V_36 = F_20 ;
V_37 = F_16 ;
F_40 = F_30 ;
V_38 = F_32 ;
V_39 = F_28 ;
break;
case V_40 :
F_37 = F_12 ;
V_36 = F_14 ;
V_37 = F_10 ;
F_40 = F_24 ;
V_38 = F_26 ;
V_39 = F_22 ;
break;
}
if ( memcmp ( V_41 , V_32 -> V_33 , V_42 ) != 0
|| V_36 ( & V_32 -> V_43 ) != V_44
|| V_32 -> V_33 [ V_45 ] != V_46 ) {
fprintf ( V_10 , L_4 , V_6 ) ;
F_7 () ;
}
V_31 = NULL ;
switch ( V_36 ( & V_32 -> V_47 ) ) {
default:
fprintf ( V_10 , L_5 ,
V_36 ( & V_32 -> V_47 ) , V_6 ) ;
F_7 () ;
break;
case V_48 :
case V_49 :
case V_50 :
V_31 = F_39 ;
break;
case V_51 :
case V_52 :
case V_53 :
case V_54 :
break;
}
switch ( V_32 -> V_33 [ V_55 ] ) {
default:
fprintf ( V_10 , L_6 ,
V_32 -> V_33 [ V_55 ] , V_6 ) ;
F_7 () ;
break;
case V_56 :
if ( V_36 ( & V_32 -> V_57 ) != sizeof( T_7 )
|| V_36 ( & V_32 -> V_58 ) != sizeof( V_59 ) ) {
fprintf ( V_10 ,
L_7 , V_6 ) ;
F_7 () ;
}
F_42 ( V_32 , V_6 , V_31 ) ;
break;
case V_60 : {
T_8 * const V_61 = ( T_8 * ) V_32 ;
if ( V_36 ( & V_61 -> V_57 ) != sizeof( T_8 )
|| V_36 ( & V_61 -> V_58 ) != sizeof( V_62 ) ) {
fprintf ( V_10 ,
L_7 , V_6 ) ;
F_7 () ;
}
F_43 ( V_61 , V_6 , V_31 ) ;
break;
}
}
F_1 () ;
}
int
main ( int V_63 , char * V_64 [] )
{
int V_65 = 0 ;
int V_17 ;
if ( V_63 < 2 ) {
fprintf ( V_10 , L_8 ) ;
return 0 ;
}
for ( V_17 = 1 ; V_17 < V_63 ; V_17 ++ ) {
char * V_66 = V_64 [ V_17 ] ;
int const V_67 = setjmp ( V_68 ) ;
switch ( V_67 ) {
default:
fprintf ( V_10 , L_9 , V_66 ) ;
exit ( 1 ) ;
break;
case V_69 :
V_5 = - 1 ;
V_2 = NULL ;
V_1 = 1 ;
F_41 ( V_66 ) ;
break;
case V_70 :
++ V_65 ;
break;
case V_71 :
break;
}
}
return ! ! V_65 ;
}
