static int F_1 ( T_1 V_1 , int V_2 )
{
struct V_3 V_4 = { V_5 , NULL } ;
struct V_6 V_7 ;
union V_8 V_9 [ 4 ] ;
union V_8 * V_10 ;
T_2 V_11 ;
int V_12 = 0 ;
V_7 . V_13 = 4 ;
V_7 . V_14 = V_9 ;
V_9 [ 0 ] . type = V_15 ;
V_9 [ 0 ] . V_16 . V_17 = sizeof( V_18 ) ;
V_9 [ 0 ] . V_16 . V_14 = ( char * ) V_18 ;
V_9 [ 1 ] . type = V_19 ;
V_9 [ 1 ] . integer . V_20 = V_21 ;
V_9 [ 2 ] . type = V_19 ;
V_9 [ 2 ] . integer . V_20 = V_2 ;
V_9 [ 3 ] . type = V_22 ;
V_9 [ 3 ] . V_23 . V_13 = 0 ;
V_9 [ 3 ] . V_23 . V_24 = NULL ;
V_12 = F_2 ( V_1 , L_1 , & V_7 , & V_4 ) ;
if ( V_12 ) {
F_3 ( L_2 , V_12 ) ;
return V_12 ;
}
V_10 = (union V_8 * ) V_4 . V_14 ;
V_11 = 0 ;
switch ( V_10 -> type ) {
case V_19 :
V_11 = V_10 -> integer . V_20 ;
break;
case V_15 :
if ( V_10 -> V_16 . V_17 == 4 ) {
V_11 = ( V_10 -> V_16 . V_14 [ 0 ] |
( V_10 -> V_16 . V_14 [ 1 ] << 8 ) |
( V_10 -> V_16 . V_14 [ 2 ] << 16 ) |
( V_10 -> V_16 . V_14 [ 3 ] << 24 ) ) ;
break;
}
default:
V_12 = - V_25 ;
break;
}
if ( V_11 == 0x80000002 )
V_12 = - V_26 ;
F_4 ( V_4 . V_14 ) ;
return V_12 ;
}
static char * F_5 ( T_3 V_27 )
{
switch ( V_27 ) {
case 0 :
return L_3 ;
case 1 :
return L_4 ;
case 2 :
return L_5 ;
case 3 :
return L_3 ;
case 4 :
return L_6 ;
case 5 :
return L_7 ;
case 6 :
return L_8 ;
case 7 :
return L_9 ;
case 8 :
return L_10 ;
case 9 :
return L_11 ;
case 0xa :
return L_12 ;
case 0xb :
case 0xc :
case 0xd :
return L_3 ;
case 0xe :
return L_13 ;
default:
return L_14 ;
}
}
static char * F_6 ( T_3 type )
{
switch ( type ) {
case 0 :
return L_15 ;
case 1 :
return L_16 ;
case 2 :
return L_17 ;
case 3 :
return L_18 ;
default:
return L_14 ;
}
}
static void F_7 ( void )
{
struct V_3 V_4 = { V_5 , NULL } ;
struct V_6 V_7 ;
union V_8 V_9 [ 4 ] ;
union V_8 * V_28 ;
int V_29 , V_12 ;
V_7 . V_13 = 4 ;
V_7 . V_14 = V_9 ;
V_9 [ 0 ] . type = V_15 ;
V_9 [ 0 ] . V_16 . V_17 = sizeof( V_18 ) ;
V_9 [ 0 ] . V_16 . V_14 = ( char * ) V_18 ;
V_9 [ 1 ] . type = V_19 ;
V_9 [ 1 ] . integer . V_20 = V_21 ;
V_9 [ 2 ] . type = V_19 ;
V_9 [ 2 ] . integer . V_20 = V_30 ;
V_9 [ 3 ] . type = V_22 ;
V_9 [ 3 ] . V_23 . V_13 = 0 ;
V_9 [ 3 ] . V_23 . V_24 = NULL ;
V_12 = F_2 ( V_31 . V_32 , L_1 , & V_7 ,
& V_4 ) ;
if ( V_12 ) {
F_3 ( L_2 , V_12 ) ;
goto V_33;
}
V_28 = (union V_8 * ) V_4 . V_14 ;
if ( V_28 -> type == V_22 ) {
union V_8 * V_34 = & V_28 -> V_23 . V_24 [ 0 ] ;
F_3 ( L_19 ,
( unsigned long long ) V_34 -> integer . V_20 ) ;
for ( V_29 = 1 ; V_29 < V_28 -> V_23 . V_13 ; V_29 ++ ) {
union V_8 * V_10 = & V_28 -> V_23 . V_24 [ V_29 ] ;
union V_8 * V_35 =
& V_10 -> V_23 . V_24 [ 0 ] ;
union V_8 * V_36 = & V_10 -> V_23 . V_24 [ 1 ] ;
F_3 ( L_20 ,
( unsigned long long ) V_35 -> integer . V_20 ) ;
F_3 ( L_21 ,
F_5 ( V_36 -> V_16 . V_14 [ 0 ] ) ) ;
F_3 ( L_22 ,
F_6 ( V_36 -> V_16 . V_14 [ 1 ] ) ) ;
F_3 ( L_23 ,
F_6 ( V_36 -> V_16 . V_14 [ 2 ] ) ) ;
F_3 ( L_24 ,
F_6 ( V_36 -> V_16 . V_14 [ 3 ] ) ) ;
}
}
V_33:
F_4 ( V_4 . V_14 ) ;
}
static bool F_8 ( struct V_37 * V_38 )
{
T_1 V_32 ;
int V_12 ;
V_32 = F_9 ( & V_38 -> V_39 ) ;
if ( ! V_32 )
return false ;
if ( ! F_10 ( V_32 , L_1 ) ) {
F_11 ( L_25 ) ;
return false ;
}
V_12 = F_1 ( V_32 , V_40 ) ;
if ( V_12 < 0 ) {
F_11 ( L_26 ) ;
return false ;
}
V_31 . V_32 = V_32 ;
F_7 () ;
return true ;
}
static bool F_12 ( void )
{
char V_41 [ 255 ] = { 0 } ;
struct V_3 V_16 = { sizeof( V_41 ) , V_41 } ;
struct V_37 * V_38 = NULL ;
bool V_42 = false ;
int V_43 = 0 ;
while ( ( V_38 = F_13 ( V_44 << 8 , V_38 ) ) != NULL ) {
V_43 ++ ;
V_42 |= F_8 ( V_38 ) ;
}
if ( V_43 == 2 && V_42 ) {
F_14 ( V_31 . V_32 , V_45 , & V_16 ) ;
F_3 ( L_27 ,
V_41 ) ;
return true ;
}
return false ;
}
void F_15 ( void )
{
if ( ! F_12 () )
return;
}
void F_16 ( void )
{
}
