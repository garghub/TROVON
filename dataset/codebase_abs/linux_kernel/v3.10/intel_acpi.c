static int F_1 ( T_1 V_1 , int V_2 , int V_3 )
{
struct V_4 V_5 = { V_6 , NULL } ;
struct V_7 V_8 ;
union V_9 V_10 [ 4 ] ;
union V_9 * V_11 ;
T_2 V_12 ;
int V_13 = 0 ;
V_8 . V_14 = 4 ;
V_8 . V_15 = V_10 ;
V_10 [ 0 ] . type = V_16 ;
V_10 [ 0 ] . V_17 . V_18 = sizeof( V_19 ) ;
V_10 [ 0 ] . V_17 . V_15 = ( char * ) V_19 ;
V_10 [ 1 ] . type = V_20 ;
V_10 [ 1 ] . integer . V_21 = V_22 ;
V_10 [ 2 ] . type = V_20 ;
V_10 [ 2 ] . integer . V_21 = V_2 ;
V_10 [ 3 ] . type = V_20 ;
V_10 [ 3 ] . integer . V_21 = V_3 ;
V_13 = F_2 ( V_1 , L_1 , & V_8 , & V_5 ) ;
if ( V_13 ) {
F_3 ( L_2 , V_13 ) ;
return V_13 ;
}
V_11 = (union V_9 * ) V_5 . V_15 ;
V_12 = 0 ;
switch ( V_11 -> type ) {
case V_20 :
V_12 = V_11 -> integer . V_21 ;
break;
case V_16 :
if ( V_11 -> V_17 . V_18 == 4 ) {
V_12 = ( V_11 -> V_17 . V_15 [ 0 ] |
( V_11 -> V_17 . V_15 [ 1 ] << 8 ) |
( V_11 -> V_17 . V_15 [ 2 ] << 16 ) |
( V_11 -> V_17 . V_15 [ 3 ] << 24 ) ) ;
break;
}
default:
V_13 = - V_23 ;
break;
}
if ( V_12 == 0x80000002 )
V_13 = - V_24 ;
F_4 ( V_5 . V_15 ) ;
return V_13 ;
}
static char * F_5 ( T_3 V_25 )
{
switch ( V_25 ) {
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
struct V_4 V_5 = { V_6 , NULL } ;
struct V_7 V_8 ;
union V_9 V_10 [ 4 ] ;
union V_9 * V_26 ;
int V_27 , V_13 ;
V_8 . V_14 = 4 ;
V_8 . V_15 = V_10 ;
V_10 [ 0 ] . type = V_16 ;
V_10 [ 0 ] . V_17 . V_18 = sizeof( V_19 ) ;
V_10 [ 0 ] . V_17 . V_15 = ( char * ) V_19 ;
V_10 [ 1 ] . type = V_20 ;
V_10 [ 1 ] . integer . V_21 = V_22 ;
V_10 [ 2 ] . type = V_20 ;
V_10 [ 2 ] . integer . V_21 = V_28 ;
V_10 [ 3 ] . type = V_20 ;
V_10 [ 3 ] . integer . V_21 = 0 ;
V_13 = F_2 ( V_29 . V_30 , L_1 , & V_8 ,
& V_5 ) ;
if ( V_13 ) {
F_3 ( L_2 , V_13 ) ;
goto V_31;
}
V_26 = (union V_9 * ) V_5 . V_15 ;
if ( V_26 -> type == V_32 ) {
union V_9 * V_33 = & V_26 -> V_34 . V_35 [ 0 ] ;
F_3 ( L_19 ,
( unsigned long long ) V_33 -> integer . V_21 ) ;
for ( V_27 = 1 ; V_27 < V_26 -> V_34 . V_14 ; V_27 ++ ) {
union V_9 * V_11 = & V_26 -> V_34 . V_35 [ V_27 ] ;
union V_9 * V_36 =
& V_11 -> V_34 . V_35 [ 0 ] ;
union V_9 * V_37 = & V_11 -> V_34 . V_35 [ 1 ] ;
F_3 ( L_20 ,
( unsigned long long ) V_36 -> integer . V_21 ) ;
F_3 ( L_21 ,
F_5 ( V_37 -> V_17 . V_15 [ 0 ] ) ) ;
F_3 ( L_22 ,
F_6 ( V_37 -> V_17 . V_15 [ 1 ] ) ) ;
F_3 ( L_23 ,
F_6 ( V_37 -> V_17 . V_15 [ 2 ] ) ) ;
F_3 ( L_24 ,
F_6 ( V_37 -> V_17 . V_15 [ 3 ] ) ) ;
}
}
V_31:
F_4 ( V_5 . V_15 ) ;
}
static bool F_8 ( struct V_38 * V_39 )
{
T_1 V_30 , V_40 ;
T_4 V_41 ;
int V_13 ;
V_30 = F_9 ( & V_39 -> V_42 ) ;
if ( ! V_30 )
return false ;
V_41 = F_10 ( V_30 , L_1 , & V_40 ) ;
if ( F_11 ( V_41 ) ) {
F_12 ( L_25 ) ;
return false ;
}
V_13 = F_1 ( V_30 , V_43 , 0 ) ;
if ( V_13 < 0 ) {
F_12 ( L_26 ) ;
return false ;
}
V_29 . V_30 = V_30 ;
F_7 () ;
return true ;
}
static bool F_13 ( void )
{
char V_44 [ 255 ] = { 0 } ;
struct V_4 V_17 = { sizeof( V_44 ) , V_44 } ;
struct V_38 * V_39 = NULL ;
bool V_45 = false ;
int V_46 = 0 ;
while ( ( V_39 = F_14 ( V_47 << 8 , V_39 ) ) != NULL ) {
V_46 ++ ;
V_45 |= F_8 ( V_39 ) ;
}
if ( V_46 == 2 && V_45 ) {
F_15 ( V_29 . V_30 , V_48 , & V_17 ) ;
F_3 ( L_27 ,
V_44 ) ;
return true ;
}
return false ;
}
void F_16 ( void )
{
if ( ! F_13 () )
return;
}
void F_17 ( void )
{
}
