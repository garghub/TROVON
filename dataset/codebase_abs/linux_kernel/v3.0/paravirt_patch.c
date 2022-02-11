void T_1
F_1 ( const void * V_1 , unsigned long V_2 )
{
extern void V_3 ( const void * V_4 ) ;
unsigned long V_5 ;
for ( V_5 = 0 ; V_5 < V_2 ; V_5 += sizeof( V_6 ) )
V_3 ( V_1 + V_5 ) ;
}
V_6 * T_1
F_2 ( unsigned long V_7 )
{
return ( V_6 * ) ( V_7 & ~ 3UL ) ;
}
unsigned long T_1
F_3 ( unsigned long V_7 )
{
return V_7 & 3UL ;
}
unsigned long T_1
F_4 ( unsigned long V_8 , unsigned long V_9 )
{
V_6 * V_10 = F_2 ( V_8 ) ;
unsigned long V_11 = F_3 ( V_8 ) ;
V_6 * V_12 = F_2 ( V_9 ) ;
unsigned long V_13 = F_3 ( V_9 ) ;
return ( V_12 - V_10 ) * 3 + V_13 - V_11 + 1 ;
}
unsigned long T_1
F_5 ( unsigned long V_7 )
{
unsigned long V_14 = F_3 ( V_7 ) ;
switch ( V_14 ) {
case 0 :
case 1 :
return V_7 + 1 ;
case 2 : {
V_6 * V_15 = F_2 ( V_7 ) ;
return ( unsigned long ) ( V_15 + 1 ) ;
}
default:
F_6 () ;
}
}
T_2 T_1
F_7 ( const V_6 * V_15 )
{
T_2 V_16 ;
V_16 . V_17 = V_15 -> V_18 . V_19 ;
return V_16 ;
}
T_2 T_1
F_8 ( const V_6 * V_15 )
{
T_2 V_16 ;
V_16 . V_17 = V_15 -> V_18 . V_20 |
( ( unsigned long long ) V_15 -> V_21 . V_22 << 18UL ) ;
return V_16 ;
}
T_2 T_1
F_9 ( const V_6 * V_15 )
{
T_2 V_16 ;
V_16 . V_17 = V_15 -> V_21 . V_23 ;
return V_16 ;
}
T_2 T_1
F_10 ( unsigned long V_7 )
{
V_6 * V_15 = F_2 ( V_7 ) ;
unsigned long V_14 = F_3 ( V_7 ) ;
switch ( V_14 ) {
case 0 :
return F_7 ( V_15 ) ;
case 1 :
return F_8 ( V_15 ) ;
case 2 :
return F_9 ( V_15 ) ;
default:
F_6 () ;
}
}
void T_1
F_11 ( V_6 * V_15 , T_2 V_16 )
{
V_15 -> V_18 . V_19 = V_16 . V_17 ;
}
void T_1
F_12 ( V_6 * V_15 , T_2 V_16 )
{
V_15 -> V_18 . V_20 = V_16 . V_17 ;
V_15 -> V_21 . V_22 = V_16 . V_17 >> 18UL ;
}
void T_1
F_13 ( V_6 * V_15 , T_2 V_16 )
{
V_15 -> V_21 . V_23 = V_16 . V_17 ;
}
void T_1
F_14 ( unsigned long V_7 , T_2 V_16 )
{
V_6 * V_15 = F_2 ( V_7 ) ;
unsigned long V_14 = F_3 ( V_7 ) ;
switch ( V_14 ) {
case 0 :
F_11 ( V_15 , V_16 ) ;
break;
case 1 :
F_12 ( V_15 , V_16 ) ;
break;
case 2 :
F_13 ( V_15 , V_16 ) ;
break;
default:
F_6 () ;
break;
}
F_1 ( V_15 , sizeof( * V_15 ) ) ;
}
void
F_15 ( const V_6 * V_15 )
{
const unsigned long * V_24 = ( const unsigned long * ) V_15 ;
T_2 V_19 = F_7 ( V_15 ) ;
T_2 V_25 = F_8 ( V_15 ) ;
T_2 V_23 = F_9 ( V_15 ) ;
F_16 ( V_26
L_1 , V_15 , V_24 [ 0 ] , V_24 [ 1 ] ) ;
F_16 ( V_26
L_2 ,
V_15 -> V_18 . V_27 ) ;
F_16 ( V_26
L_3 ,
( unsigned long ) V_15 -> V_18 . V_19 ,
( unsigned long ) V_15 -> V_18 . V_20 ,
( unsigned long ) V_15 -> V_21 . V_22 ,
( unsigned long ) V_15 -> V_21 . V_23 ) ;
F_16 ( V_26
L_4 ,
V_19 . V_17 , V_25 . V_17 , V_23 . V_17 ) ;
}
static int T_3 F_17 ( char * V_28 )
{
V_29 = 1 ;
return 1 ;
}
static void T_1
F_18 ( void * V_10 , void * V_12 )
{
extern const char V_30 [] ;
extern const unsigned long V_31 ;
void * V_15 = V_10 ;
F_19 ( ( ( ( unsigned long ) V_10 ) % sizeof( V_6 ) ) != 0 ) ;
F_19 ( ( ( ( unsigned long ) V_12 ) % sizeof( V_6 ) ) != 0 ) ;
while ( V_15 < V_12 ) {
memcpy ( V_15 , V_30 , V_31 ) ;
V_15 += V_31 ;
}
}
unsigned long T_1
F_20 ( void * V_10 , void * V_12 , unsigned long type ,
const struct V_32 * V_33 ,
unsigned long V_34 ,
const struct V_32 * * V_35 )
{
unsigned long V_36 = 0 ;
unsigned long V_5 ;
F_19 ( ( ( ( unsigned long ) V_10 ) % sizeof( V_6 ) ) != 0 ) ;
F_19 ( ( ( ( unsigned long ) V_12 ) % sizeof( V_6 ) ) != 0 ) ;
V_35 = NULL ;
for ( V_5 = 0 ; V_5 < V_34 ; V_5 ++ ) {
const struct V_32 * V_37 = & V_33 [ V_5 ] ;
if ( V_37 -> type == type ) {
unsigned long V_38 = V_37 -> V_12 - V_37 -> V_10 ;
unsigned long V_39 = V_12 - V_10 ;
if ( V_35 != NULL )
* V_35 = V_37 ;
if ( V_39 < V_38 ) {
F_16 ( V_26
L_5
L_6 ,
type , V_38 , V_39 ) ;
break;
}
V_36 = V_38 ;
memcpy ( V_10 , V_37 -> V_10 , V_36 ) ;
break;
}
}
return V_36 ;
}
void T_1
F_21 ( const struct V_40 * V_41 ,
const struct V_40 * V_42 )
{
const struct V_40 * V_37 ;
if ( V_29 )
return;
if ( V_43 . V_44 == NULL )
return;
for ( V_37 = V_41 ; V_37 < V_42 ; V_37 ++ ) {
unsigned long V_36 ;
V_36 = (* V_43 . V_44 )( V_37 -> V_10 , V_37 -> V_12 ,
V_37 -> type ) ;
if ( V_36 == 0 )
continue;
F_18 ( V_37 -> V_10 + V_36 , V_37 -> V_12 ) ;
F_1 ( V_37 -> V_10 ,
V_37 -> V_12 - V_37 -> V_10 ) ;
}
F_22 () ;
F_23 () ;
}
static void T_1
F_24 ( unsigned long V_8 , unsigned long V_9 )
{
extern const V_6 V_45 [] ;
unsigned long V_7 ;
const T_2 V_46 =
F_7 ( V_45 ) ;
for ( V_7 = V_8 ; V_7 < V_9 ; V_7 = F_5 ( V_7 ) )
F_14 ( V_7 , V_46 ) ;
}
void T_1
F_25 ( const struct V_47 * V_41 ,
const struct V_47 * V_42 )
{
const struct V_47 * V_37 ;
if ( V_29 )
return;
if ( V_43 . V_48 == NULL )
return;
for ( V_37 = V_41 ; V_37 < V_42 ; V_37 ++ ) {
unsigned long V_7 ;
V_6 * V_10 ;
V_6 * V_12 ;
V_7 = (* V_43 . V_48 )( V_37 -> V_8 , V_37 -> V_9 , V_37 -> type ) ;
if ( V_7 == V_37 -> V_8 )
continue;
F_24 ( V_7 , V_37 -> V_9 ) ;
V_10 = F_2 ( V_37 -> V_8 ) ;
V_12 = F_2 ( V_37 -> V_9 ) + 1 ;
F_1 ( V_10 , ( V_12 - V_10 ) *
sizeof( V_6 ) ) ;
}
F_22 () ;
F_23 () ;
}
void T_1
F_26 ( unsigned long V_7 , const void * V_49 )
{
unsigned long V_50 = F_5 ( V_7 ) ;
unsigned long V_51 = V_7 ;
V_6 * V_15 = F_2 ( V_7 ) ;
T_2 V_52 = F_10 ( V_50 ) ;
T_2 V_53 = F_10 ( V_51 ) ;
T_4 V_54 = { . V_17 = V_52 . V_17 } ;
T_5 V_55 = { . V_17 = V_53 . V_17 } ;
unsigned long V_56 =
( ( unsigned long ) V_49 - ( unsigned long ) V_15 ) >> 4 ;
F_19 ( F_3 ( V_7 ) != 1 ) ;
F_19 ( ( ( unsigned long ) V_49 & ( sizeof( V_6 ) - 1 ) ) != 0 ) ;
V_54 . V_5 = ( V_56 >> 59 ) & 1 ;
V_54 . V_57 = V_56 & ( ( 1UL << 20 ) - 1 ) ;
V_55 . V_58 = ( V_56 >> 20 ) & ( ( 1UL << 39 ) - 1 ) ;
V_52 . V_17 = V_54 . V_17 ;
V_53 . V_17 = V_55 . V_17 ;
F_14 ( V_50 , V_52 ) ;
F_14 ( V_51 , V_53 ) ;
}
void T_3
F_27 ( unsigned long V_7 , const void * V_49 )
{
V_6 * V_15 = F_2 ( V_7 ) ;
T_2 V_16 = F_10 ( V_7 ) ;
unsigned long V_59 = ( unsigned long ) V_49 - ( unsigned long ) V_15 ;
T_6 V_60 ;
F_19 ( ( ( unsigned long ) V_49 & ( sizeof( V_6 ) - 1 ) ) != 0 ) ;
V_60 . V_17 = V_16 . V_17 ;
if ( V_59 & ( 1UL << 63 ) )
V_60 . V_61 = 1 ;
else
V_60 . V_61 = 0 ;
V_60 . V_57 = V_59 >> 4 ;
V_16 . V_17 = V_60 . V_17 ;
F_14 ( V_7 , V_16 ) ;
}
void T_3
F_28 (
unsigned long V_7 , unsigned long type ,
const struct V_62 * V_63 ,
unsigned int V_64 )
{
unsigned int V_5 ;
for ( V_5 = 0 ; V_5 < V_64 ; V_5 ++ ) {
if ( V_63 [ V_5 ] . type == type ) {
F_27 ( V_7 , V_63 [ V_5 ] . V_65 ) ;
break;
}
}
}
static void T_3
F_29 ( const struct V_66 * V_41 ,
const struct V_66 * V_42 )
{
const struct V_66 * V_37 ;
if ( V_29 )
return;
if ( V_43 . V_67 == NULL )
return;
for ( V_37 = V_41 ; V_37 < V_42 ; V_37 ++ )
(* V_43 . V_67 )( V_37 -> V_7 , V_37 -> type ) ;
F_22 () ;
F_23 () ;
}
void T_3
F_30 ( void )
{
extern const char V_68 [] ;
extern const char V_69 [] ;
extern const char V_70 [] ;
extern const char V_71 [] ;
extern const char V_72 [] ;
extern const char V_73 [] ;
F_21 ( ( const struct V_40 * )
V_68 ,
( const struct V_40 * )
V_69 ) ;
F_25 ( ( const struct V_47 * )
V_70 ,
( const struct V_47 * )
V_71 ) ;
F_29 ( ( const struct V_66 * )
V_72 ,
( const struct V_66 * )
V_73 ) ;
}
