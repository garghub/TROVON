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
F_40 ( F_37 ( V_30 + 1 ) + V_17 + 4 , V_30 + 1 ) ;
F_40 ( F_37 ( V_30 + 2 ) + V_17 + 8 , V_30 + 2 ) ;
V_17 += sizeof( T_2 ) * 3 ;
}
qsort ( V_28 , V_29 / 12 , 12 , F_38 ) ;
V_17 = 0 ;
while ( V_17 < V_29 ) {
T_2 * V_30 = ( T_2 * ) ( V_28 + V_17 ) ;
F_40 ( F_37 ( V_30 ) - V_17 , V_30 ) ;
F_40 ( F_37 ( V_30 + 1 ) - ( V_17 + 4 ) , V_30 + 1 ) ;
F_40 ( F_37 ( V_30 + 2 ) - ( V_17 + 8 ) , V_30 + 2 ) ;
V_17 += sizeof( T_2 ) * 3 ;
}
}
static void F_41 ( char * V_28 , int V_29 )
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
F_42 ( char const * const V_6 )
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
|| ( V_36 ( & V_32 -> V_43 ) != V_44 && V_36 ( & V_32 -> V_43 ) != V_45 )
|| V_32 -> V_33 [ V_46 ] != V_47 ) {
fprintf ( V_10 , L_4 , V_6 ) ;
F_7 () ;
}
V_31 = NULL ;
switch ( V_36 ( & V_32 -> V_48 ) ) {
default:
fprintf ( V_10 , L_5 ,
V_36 ( & V_32 -> V_48 ) , V_6 ) ;
F_7 () ;
break;
case V_49 :
case V_50 :
V_31 = F_39 ;
break;
case V_51 :
case V_52 :
case V_53 :
V_31 = F_41 ;
break;
case V_54 :
case V_55 :
case V_56 :
case V_57 :
case V_58 :
case V_59 :
break;
}
switch ( V_32 -> V_33 [ V_60 ] ) {
default:
fprintf ( V_10 , L_6 ,
V_32 -> V_33 [ V_60 ] , V_6 ) ;
F_7 () ;
break;
case V_61 :
if ( V_36 ( & V_32 -> V_62 ) != sizeof( T_7 )
|| V_36 ( & V_32 -> V_63 ) != sizeof( V_64 ) ) {
fprintf ( V_10 ,
L_7 , V_6 ) ;
F_7 () ;
}
F_43 ( V_32 , V_6 , V_31 ) ;
break;
case V_65 : {
T_8 * const V_66 = ( T_8 * ) V_32 ;
if ( V_36 ( & V_66 -> V_62 ) != sizeof( T_8 )
|| V_36 ( & V_66 -> V_63 ) != sizeof( V_67 ) ) {
fprintf ( V_10 ,
L_7 , V_6 ) ;
F_7 () ;
}
F_44 ( V_66 , V_6 , V_31 ) ;
break;
}
}
F_1 () ;
}
int
main ( int V_68 , char * V_69 [] )
{
int V_70 = 0 ;
int V_17 ;
if ( V_68 < 2 ) {
fprintf ( V_10 , L_8 ) ;
return 0 ;
}
for ( V_17 = 1 ; V_17 < V_68 ; V_17 ++ ) {
char * V_71 = V_69 [ V_17 ] ;
int const V_72 = setjmp ( V_73 ) ;
switch ( V_72 ) {
default:
fprintf ( V_10 , L_9 , V_71 ) ;
exit ( 1 ) ;
break;
case V_74 :
V_5 = - 1 ;
V_2 = NULL ;
V_1 = 1 ;
F_42 ( V_71 ) ;
break;
case V_75 :
++ V_70 ;
break;
case V_76 :
break;
}
}
return ! ! V_70 ;
}
