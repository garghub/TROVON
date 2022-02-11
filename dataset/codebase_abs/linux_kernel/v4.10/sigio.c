static int F_1 ( void * V_1 )
{
struct V_2 * V_3 , V_4 ;
struct V_5 * V_6 ;
int V_7 , V_8 , V_9 ;
char V_10 ;
F_2 () ;
V_3 = & V_11 ;
while ( 1 ) {
V_8 = F_3 ( V_3 -> F_3 , V_3 -> V_12 , - 1 ) ;
if ( V_8 < 0 ) {
if ( V_13 == V_14 )
continue;
F_4 ( V_15 L_1
L_2 , V_8 , V_13 ) ;
}
for ( V_7 = 0 ; V_7 < V_3 -> V_12 ; V_7 ++ ) {
V_6 = & V_3 -> F_3 [ V_7 ] ;
if ( V_6 -> V_16 == 0 )
continue;
if ( V_6 -> V_17 == V_18 [ 1 ] ) {
F_5 ( V_8 = F_6 ( V_18 [ 1 ] , & V_10 ,
sizeof( V_10 ) ) ) ;
if ( V_8 != sizeof( V_10 ) )
F_4 ( V_15
L_3
L_4
L_5 , V_13 ) ;
V_4 = V_11 ;
V_11 = V_19 ;
V_19 = V_4 ;
V_9 = V_18 [ 1 ] ;
}
else {
V_9 = V_20 [ 1 ] ;
V_3 -> V_12 -- ;
memmove ( & V_3 -> F_3 [ V_7 ] , & V_3 -> F_3 [ V_7 + 1 ] ,
( V_3 -> V_12 - V_7 ) * sizeof( * V_3 -> F_3 ) ) ;
}
F_5 ( V_8 = F_7 ( V_9 , & V_10 , sizeof( V_10 ) ) ) ;
if ( V_8 != sizeof( V_10 ) )
F_4 ( V_15 L_3
L_6 ,
V_13 ) ;
}
}
return 0 ;
}
static int F_8 ( struct V_2 * V_21 , int V_8 )
{
struct V_5 * V_22 ;
if ( V_8 <= V_21 -> V_23 )
return 0 ;
V_22 = F_9 ( V_8 * sizeof( struct V_5 ) , V_24 ) ;
if ( V_22 == NULL ) {
F_4 ( V_15 L_7
L_8 ) ;
return - V_25 ;
}
memcpy ( V_22 , V_21 -> F_3 , V_21 -> V_12 * sizeof( struct V_5 ) ) ;
F_10 ( V_21 -> F_3 ) ;
V_21 -> F_3 = V_22 ;
V_21 -> V_23 = V_8 ;
return 0 ;
}
static void F_11 ( void )
{
unsigned long V_26 ;
int V_8 ;
char V_10 ;
V_26 = F_12 ( 0 ) ;
F_5 ( V_8 = F_7 ( V_18 [ 0 ] , & V_10 , sizeof( V_10 ) ) ) ;
if ( V_8 != sizeof( V_10 ) ) {
F_4 ( V_15 L_9 ,
V_13 ) ;
goto V_27;
}
F_5 ( V_8 = F_6 ( V_18 [ 0 ] , & V_10 , sizeof( V_10 ) ) ) ;
if ( V_8 != sizeof( V_10 ) ) {
F_4 ( V_15 L_10 ,
V_13 ) ;
goto V_27;
}
F_12 ( V_26 ) ;
return;
V_27:
if ( V_28 != - 1 ) {
F_13 ( V_28 , 1 ) ;
F_14 ( V_29 , 0 ) ;
}
V_28 = - 1 ;
F_15 ( V_18 [ 0 ] ) ;
F_15 ( V_18 [ 1 ] ) ;
F_15 ( V_20 [ 0 ] ) ;
F_15 ( V_20 [ 1 ] ) ;
F_12 ( V_26 ) ;
}
int F_16 ( int V_17 )
{
struct V_5 * V_6 ;
int V_30 = 0 , V_7 , V_8 ;
F_17 () ;
for ( V_7 = 0 ; V_7 < V_31 . V_12 ; V_7 ++ ) {
if ( V_31 . F_3 [ V_7 ] . V_17 == V_17 )
break;
}
if ( V_7 == V_31 . V_12 )
goto V_32;
V_6 = & V_31 . F_3 [ V_7 ] ;
for ( V_7 = 0 ; V_7 < V_11 . V_12 ; V_7 ++ ) {
if ( V_11 . F_3 [ V_7 ] . V_17 == V_17 )
goto V_32;
}
V_8 = V_11 . V_12 ;
V_30 = F_8 ( & V_19 , V_8 + 1 ) ;
if ( V_30 )
goto V_32;
memcpy ( V_19 . F_3 , V_11 . F_3 ,
V_11 . V_12 * sizeof( struct V_5 ) ) ;
V_19 . F_3 [ V_8 ] = * V_6 ;
V_19 . V_12 = V_8 + 1 ;
F_11 () ;
V_32:
F_18 () ;
return V_30 ;
}
int F_19 ( int V_17 )
{
struct V_5 * V_6 ;
int V_30 = 0 , V_7 , V_8 = 0 ;
if ( V_28 == - 1 )
return - V_33 ;
F_17 () ;
for ( V_7 = 0 ; V_7 < V_11 . V_12 ; V_7 ++ ) {
if ( V_11 . F_3 [ V_7 ] . V_17 == V_17 )
break;
}
if ( V_7 == V_11 . V_12 )
goto V_32;
V_30 = F_8 ( & V_19 , V_11 . V_12 - 1 ) ;
if ( V_30 )
goto V_32;
for ( V_7 = 0 ; V_7 < V_11 . V_12 ; V_7 ++ ) {
V_6 = & V_11 . F_3 [ V_7 ] ;
if ( V_6 -> V_17 != V_17 )
V_19 . F_3 [ V_8 ++ ] = * V_6 ;
}
V_19 . V_12 = V_11 . V_12 - 1 ;
F_11 () ;
V_32:
F_18 () ;
return V_30 ;
}
static struct V_5 * F_20 ( int V_17 )
{
struct V_5 * V_6 ;
V_6 = F_9 ( sizeof( struct V_5 ) , V_34 ) ;
if ( V_6 == NULL ) {
F_4 ( V_15 L_11
L_12 ) ;
return NULL ;
}
* V_6 = ( (struct V_5 ) { . V_17 = V_17 ,
. V_35 = V_36 ,
. V_16 = 0 } ) ;
return V_6 ;
}
static void F_21 ( void )
{
struct V_5 * V_6 ;
int V_30 ;
int V_37 [ 2 ] ;
int V_38 [ 2 ] ;
int V_39 ;
F_17 () ;
V_39 = V_28 ;
F_18 () ;
if ( V_39 != - 1 )
return;
V_30 = F_22 ( V_37 , 1 , 1 ) ;
if ( V_30 < 0 ) {
F_4 ( V_15 L_13
L_5 , - V_30 ) ;
return;
}
V_30 = F_22 ( V_38 , 1 , 1 ) ;
if ( V_30 < 0 ) {
F_4 ( V_15 L_14
L_5 , - V_30 ) ;
goto V_40;
}
V_6 = F_20 ( V_38 [ 1 ] ) ;
if ( ! V_6 )
goto V_41;
F_17 () ;
if ( V_28 != - 1 )
goto V_42;
V_11 = ( (struct V_2 ) { . F_3 = V_6 ,
. V_12 = 1 ,
. V_23 = 1 } ) ;
if ( F_23 ( V_37 [ 0 ] ) )
goto V_43;
memcpy ( V_20 , V_37 , sizeof( V_37 ) ) ;
memcpy ( V_18 , V_38 , sizeof( V_38 ) ) ;
V_28 = F_24 ( F_1 , NULL ,
V_44 | V_45 ,
& V_29 ) ;
if ( V_28 < 0 )
goto V_46;
F_18 () ;
return;
V_46:
V_28 = - 1 ;
V_20 [ 0 ] = - 1 ;
V_20 [ 1 ] = - 1 ;
V_18 [ 0 ] = - 1 ;
V_18 [ 1 ] = - 1 ;
V_43:
V_11 = ( (struct V_2 ) { . F_3 = NULL ,
. V_23 = 0 ,
. V_12 = 0 } ) ;
V_42:
F_18 () ;
F_10 ( V_6 ) ;
V_41:
F_15 ( V_38 [ 0 ] ) ;
F_15 ( V_38 [ 1 ] ) ;
V_40:
F_15 ( V_37 [ 0 ] ) ;
F_15 ( V_37 [ 1 ] ) ;
}
void F_25 ( int V_17 , int F_6 )
{
int V_30 ;
F_21 () ;
F_17 () ;
V_30 = F_8 ( & V_31 , V_31 . V_12 + 1 ) ;
if ( V_30 ) {
F_4 ( V_15 L_15
L_16 , V_17 ) ;
goto V_32;
}
V_31 . F_3 [ V_31 . V_12 ++ ] =
( (struct V_5 ) { . V_17 = V_17 ,
. V_35 = F_6 ? V_36 : V_47 ,
. V_16 = 0 } ) ;
V_32:
F_18 () ;
}
void F_26 ( int V_17 , int F_6 )
{
if ( ! F_27 ( V_17 ) )
return;
if ( ( F_6 || V_48 ) && ( ! F_6 || V_49 ) )
return;
F_25 ( V_17 , F_6 ) ;
}
static void F_28 ( void )
{
if ( V_28 == - 1 )
return;
F_13 ( V_28 , 1 ) ;
F_14 ( V_29 , 0 ) ;
V_28 = - 1 ;
}
static void T_1 F_29 ( int V_50 )
{
V_51 = 1 ;
}
static void F_30 ( void * V_52 )
{
struct V_53 * V_54 = V_52 ;
V_54 -> V_30 = 0 ;
if ( F_31 ( & V_54 -> V_55 , & V_54 -> V_56 , NULL , NULL , NULL ) )
V_54 -> V_30 = - V_13 ;
}
static int F_32 ( int V_55 , int V_56 )
{
int V_26 ;
V_26 = F_33 ( V_55 , V_57 ) ;
if ( V_26 < 0 )
return - V_13 ;
if ( ( F_33 ( V_55 , V_58 , V_26 | V_59 | V_60 ) < 0 ) ||
( F_33 ( V_55 , V_61 , F_34 () ) < 0 ) )
return - V_13 ;
if ( ( F_33 ( V_56 , V_58 , V_26 | V_59 ) < 0 ) )
return - V_13 ;
return 0 ;
}
static void T_1 F_35 ( void (* F_36)( int , int ) )
{
struct V_62 V_63 , V_22 ;
struct V_53 V_64 = { . V_55 = - 1 , . V_56 = - 1 } ;
int V_55 , V_56 , V_30 ;
F_37 ( F_30 , & V_64 ) ;
if ( V_64 . V_30 ) {
F_4 ( V_15 L_17 ,
- V_64 . V_30 ) ;
return;
}
V_55 = V_64 . V_55 ;
V_56 = V_64 . V_56 ;
if ( ( V_55 == - 1 ) || ( V_56 == - 1 ) ) {
F_4 ( V_15 L_18
L_19 ) ;
return;
}
V_30 = F_38 ( V_55 ) ;
if ( V_30 < 0 ) {
F_4 ( V_15 L_20 ,
- V_30 ) ;
return;
}
V_30 = F_32 ( V_55 , V_56 ) ;
if ( V_30 < 0 ) {
F_4 ( V_15 L_21
L_5 , - V_30 ) ;
return;
}
if ( V_62 ( V_65 , NULL , & V_63 ) < 0 ) {
F_4 ( V_15 L_22
L_23 , V_13 ) ;
return;
}
V_22 = V_63 ;
V_22 . V_66 = F_29 ;
if ( V_62 ( V_65 , & V_22 , NULL ) < 0 ) {
F_4 ( V_15 L_24
L_23 , V_13 ) ;
return;
}
V_51 = 0 ;
(* F_36)( V_55 , V_56 ) ;
F_15 ( V_55 ) ;
F_15 ( V_56 ) ;
if ( V_62 ( V_65 , & V_63 , NULL ) < 0 )
F_4 ( V_15 L_25
L_23 , V_13 ) ;
}
static void F_39 ( int V_55 , int V_56 )
{
int V_8 ;
char V_67 [ 512 ] ;
F_4 ( V_68 L_26 ) ;
memset ( V_67 , 0 , sizeof( V_67 ) ) ;
while ( F_7 ( V_55 , V_67 , sizeof( V_67 ) ) > 0 ) ;
if ( V_13 != V_69 )
F_4 ( V_15 L_27 ,
V_13 ) ;
while ( ( ( V_8 = F_6 ( V_56 , V_67 , sizeof( V_67 ) ) ) > 0 ) &&
! ( { F_40 () ; V_51 ; } )
void F_41 ( int V_55 , int V_56 )
{
F_4 ( V_68 L_28
L_29 ) ;
F_15 ( V_56 ) ;
if ( V_51 ) {
F_4 ( V_70 L_30 ) ;
V_49 = 1 ;
} else
F_4 ( V_70 L_31 ) ;
}
static void T_1 F_42 ( void )
{
if ( ( F_43 ( L_32 , V_71 ) < 0 ) &&
( F_43 ( L_33 , V_71 ) < 0 ) ) {
F_4 ( V_72 L_34
L_35 ) ;
return;
}
F_35 ( F_39 ) ;
F_35 ( F_41 ) ;
}
void T_1 F_44 ( void )
{
F_42 () ;
}
