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
static int F_34 ( const void * V_17 , const void * V_18 )
{
T_4 V_19 = ( T_4 ) F_35 ( V_17 ) ;
T_4 V_20 = ( T_4 ) F_35 ( V_18 ) ;
if ( V_19 < V_20 )
return - 1 ;
if ( V_19 > V_20 )
return 1 ;
return 0 ;
}
static void F_36 ( char * V_21 , int V_22 )
{
int V_23 ;
V_23 = 0 ;
while ( V_23 < V_22 ) {
T_2 * V_24 = ( T_2 * ) ( V_21 + V_23 ) ;
F_37 ( F_35 ( V_24 ) + V_23 , V_24 ) ;
V_23 += 4 ;
}
qsort ( V_21 , V_22 / 8 , 8 , F_34 ) ;
V_23 = 0 ;
while ( V_23 < V_22 ) {
T_2 * V_24 = ( T_2 * ) ( V_21 + V_23 ) ;
F_37 ( F_35 ( V_24 ) - V_23 , V_24 ) ;
V_23 += 4 ;
}
}
static void
F_38 ( char const * const V_6 )
{
T_5 V_25 ;
T_6 * V_26 = F_4 ( V_6 ) ;
V_2 = V_26 ;
switch ( V_26 -> V_27 [ V_28 ] ) {
default:
fprintf ( V_10 , L_3 ,
V_26 -> V_27 [ V_28 ] , V_6 ) ;
F_7 () ;
break;
case V_29 :
F_35 = F_18 ;
V_30 = F_20 ;
V_31 = F_16 ;
F_37 = F_30 ;
V_32 = F_32 ;
V_33 = F_28 ;
break;
case V_34 :
F_35 = F_12 ;
V_30 = F_14 ;
V_31 = F_10 ;
F_37 = F_24 ;
V_32 = F_26 ;
V_33 = F_22 ;
break;
}
if ( memcmp ( V_35 , V_26 -> V_27 , V_36 ) != 0
|| V_30 ( & V_26 -> V_37 ) != V_38
|| V_26 -> V_27 [ V_39 ] != V_40 ) {
fprintf ( V_10 , L_4 , V_6 ) ;
F_7 () ;
}
V_25 = NULL ;
switch ( V_30 ( & V_26 -> V_41 ) ) {
default:
fprintf ( V_10 , L_5 ,
V_30 ( & V_26 -> V_41 ) , V_6 ) ;
F_7 () ;
break;
case V_42 :
case V_43 :
V_25 = F_36 ;
break;
case V_44 :
break;
}
switch ( V_26 -> V_27 [ V_45 ] ) {
default:
fprintf ( V_10 , L_6 ,
V_26 -> V_27 [ V_45 ] , V_6 ) ;
F_7 () ;
break;
case V_46 :
if ( V_30 ( & V_26 -> V_47 ) != sizeof( T_6 )
|| V_30 ( & V_26 -> V_48 ) != sizeof( V_49 ) ) {
fprintf ( V_10 ,
L_7 , V_6 ) ;
F_7 () ;
}
F_39 ( V_26 , V_6 , V_25 ) ;
break;
case V_50 : {
T_7 * const V_51 = ( T_7 * ) V_26 ;
if ( V_30 ( & V_51 -> V_47 ) != sizeof( T_7 )
|| V_30 ( & V_51 -> V_48 ) != sizeof( V_52 ) ) {
fprintf ( V_10 ,
L_7 , V_6 ) ;
F_7 () ;
}
F_40 ( V_51 , V_6 , V_25 ) ;
break;
}
}
F_1 () ;
}
int
main ( int V_53 , char * V_54 [] )
{
int V_55 = 0 ;
int V_23 ;
if ( V_53 < 2 ) {
fprintf ( V_10 , L_8 ) ;
return 0 ;
}
for ( V_23 = 1 ; V_23 < V_53 ; V_23 ++ ) {
char * V_56 = V_54 [ V_23 ] ;
int const V_57 = setjmp ( V_58 ) ;
switch ( V_57 ) {
default:
fprintf ( V_10 , L_9 , V_56 ) ;
exit ( 1 ) ;
break;
case V_59 :
V_5 = - 1 ;
V_2 = NULL ;
V_1 = 1 ;
F_38 ( V_56 ) ;
break;
case V_60 :
++ V_55 ;
break;
case V_61 :
break;
}
}
return ! ! V_55 ;
}
