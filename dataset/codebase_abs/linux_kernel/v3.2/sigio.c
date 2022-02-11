static int F_1 ( void * V_1 )
{
struct V_2 * V_3 , V_4 ;
struct V_5 * V_6 ;
int V_7 , V_8 , V_9 ;
char V_10 ;
signal ( V_11 , V_12 ) ;
V_3 = & V_13 ;
while ( 1 ) {
V_8 = F_2 ( V_3 -> F_2 , V_3 -> V_14 , - 1 ) ;
if ( V_8 < 0 ) {
if ( V_15 == V_16 )
continue;
F_3 ( V_17 L_1
L_2 , V_8 , V_15 ) ;
}
for ( V_7 = 0 ; V_7 < V_3 -> V_14 ; V_7 ++ ) {
V_6 = & V_3 -> F_2 [ V_7 ] ;
if ( V_6 -> V_18 == 0 )
continue;
if ( V_6 -> V_19 == V_20 [ 1 ] ) {
F_4 ( V_8 = F_5 ( V_20 [ 1 ] , & V_10 ,
sizeof( V_10 ) ) ) ;
if ( V_8 != sizeof( V_10 ) )
F_3 ( V_17
L_3
L_4
L_5 , V_15 ) ;
V_4 = V_13 ;
V_13 = V_21 ;
V_21 = V_4 ;
V_9 = V_20 [ 1 ] ;
}
else {
V_9 = V_22 [ 1 ] ;
V_3 -> V_14 -- ;
memmove ( & V_3 -> F_2 [ V_7 ] , & V_3 -> F_2 [ V_7 + 1 ] ,
( V_3 -> V_14 - V_7 ) * sizeof( * V_3 -> F_2 ) ) ;
}
F_4 ( V_8 = F_6 ( V_9 , & V_10 , sizeof( V_10 ) ) ) ;
if ( V_8 != sizeof( V_10 ) )
F_3 ( V_17 L_3
L_6 ,
V_15 ) ;
}
}
return 0 ;
}
static int F_7 ( struct V_2 * V_23 , int V_8 )
{
struct V_5 * V_24 ;
if ( V_8 <= V_23 -> V_25 )
return 0 ;
V_24 = F_8 ( V_8 * sizeof( struct V_5 ) , V_26 ) ;
if ( V_24 == NULL ) {
F_3 ( V_17 L_7
L_8 ) ;
return - V_27 ;
}
memcpy ( V_24 , V_23 -> F_2 , V_23 -> V_14 * sizeof( struct V_5 ) ) ;
F_9 ( V_23 -> F_2 ) ;
V_23 -> F_2 = V_24 ;
V_23 -> V_25 = V_8 ;
return 0 ;
}
static void F_10 ( void )
{
unsigned long V_28 ;
int V_8 ;
char V_10 ;
V_28 = F_11 ( 0 ) ;
F_4 ( V_8 = F_6 ( V_20 [ 0 ] , & V_10 , sizeof( V_10 ) ) ) ;
if ( V_8 != sizeof( V_10 ) ) {
F_3 ( V_17 L_9 ,
V_15 ) ;
goto V_29;
}
F_4 ( V_8 = F_5 ( V_20 [ 0 ] , & V_10 , sizeof( V_10 ) ) ) ;
if ( V_8 != sizeof( V_10 ) ) {
F_3 ( V_17 L_10 ,
V_15 ) ;
goto V_29;
}
F_11 ( V_28 ) ;
return;
V_29:
if ( V_30 != - 1 ) {
F_12 ( V_30 , 1 ) ;
F_13 ( V_31 , 0 ) ;
}
V_30 = - 1 ;
F_14 ( V_20 [ 0 ] ) ;
F_14 ( V_20 [ 1 ] ) ;
F_14 ( V_22 [ 0 ] ) ;
F_14 ( V_22 [ 1 ] ) ;
F_11 ( V_28 ) ;
}
int F_15 ( int V_19 )
{
struct V_5 * V_6 ;
int V_32 = 0 , V_7 , V_8 ;
F_16 () ;
for ( V_7 = 0 ; V_7 < V_33 . V_14 ; V_7 ++ ) {
if ( V_33 . F_2 [ V_7 ] . V_19 == V_19 )
break;
}
if ( V_7 == V_33 . V_14 )
goto V_34;
V_6 = & V_33 . F_2 [ V_7 ] ;
for ( V_7 = 0 ; V_7 < V_13 . V_14 ; V_7 ++ ) {
if ( V_13 . F_2 [ V_7 ] . V_19 == V_19 )
goto V_34;
}
V_8 = V_13 . V_14 ;
V_32 = F_7 ( & V_21 , V_8 + 1 ) ;
if ( V_32 )
goto V_34;
memcpy ( V_21 . F_2 , V_13 . F_2 ,
V_13 . V_14 * sizeof( struct V_5 ) ) ;
V_21 . F_2 [ V_8 ] = * V_6 ;
V_21 . V_14 = V_8 + 1 ;
F_10 () ;
V_34:
F_17 () ;
return V_32 ;
}
int F_18 ( int V_19 )
{
struct V_5 * V_6 ;
int V_32 = 0 , V_7 , V_8 = 0 ;
if ( V_30 == - 1 )
return - V_35 ;
F_16 () ;
for ( V_7 = 0 ; V_7 < V_13 . V_14 ; V_7 ++ ) {
if ( V_13 . F_2 [ V_7 ] . V_19 == V_19 )
break;
}
if ( V_7 == V_13 . V_14 )
goto V_34;
V_32 = F_7 ( & V_21 , V_13 . V_14 - 1 ) ;
if ( V_32 )
goto V_34;
for ( V_7 = 0 ; V_7 < V_13 . V_14 ; V_7 ++ ) {
V_6 = & V_13 . F_2 [ V_7 ] ;
if ( V_6 -> V_19 != V_19 )
V_21 . F_2 [ V_8 ++ ] = * V_6 ;
}
V_21 . V_14 = V_13 . V_14 - 1 ;
F_10 () ;
V_34:
F_17 () ;
return V_32 ;
}
static struct V_5 * F_19 ( int V_19 )
{
struct V_5 * V_6 ;
V_6 = F_8 ( sizeof( struct V_5 ) , V_36 ) ;
if ( V_6 == NULL ) {
F_3 ( V_17 L_11
L_12 ) ;
return NULL ;
}
* V_6 = ( (struct V_5 ) { . V_19 = V_19 ,
. V_37 = V_38 ,
. V_18 = 0 } ) ;
return V_6 ;
}
static void F_20 ( void )
{
struct V_5 * V_6 ;
int V_32 ;
int V_39 [ 2 ] ;
int V_40 [ 2 ] ;
int V_41 ;
F_16 () ;
V_41 = V_30 ;
F_17 () ;
if ( V_41 != - 1 )
return;
V_32 = F_21 ( V_39 , 1 , 1 ) ;
if ( V_32 < 0 ) {
F_3 ( V_17 L_13
L_5 , - V_32 ) ;
return;
}
V_32 = F_21 ( V_40 , 1 , 1 ) ;
if ( V_32 < 0 ) {
F_3 ( V_17 L_14
L_5 , - V_32 ) ;
goto V_42;
}
V_6 = F_19 ( V_40 [ 1 ] ) ;
if ( ! V_6 )
goto V_43;
F_16 () ;
if ( V_30 != - 1 )
goto V_44;
V_13 = ( (struct V_2 ) { . F_2 = V_6 ,
. V_14 = 1 ,
. V_25 = 1 } ) ;
if ( F_22 ( V_39 [ 0 ] ) )
goto V_45;
memcpy ( V_22 , V_39 , sizeof( V_39 ) ) ;
memcpy ( V_20 , V_40 , sizeof( V_40 ) ) ;
V_30 = F_23 ( F_1 , NULL ,
V_46 | V_47 ,
& V_31 ) ;
if ( V_30 < 0 )
goto V_48;
F_17 () ;
return;
V_48:
V_30 = - 1 ;
V_22 [ 0 ] = - 1 ;
V_22 [ 1 ] = - 1 ;
V_20 [ 0 ] = - 1 ;
V_20 [ 1 ] = - 1 ;
V_45:
V_13 = ( (struct V_2 ) { . F_2 = NULL ,
. V_25 = 0 ,
. V_14 = 0 } ) ;
V_44:
F_17 () ;
F_9 ( V_6 ) ;
V_43:
F_14 ( V_40 [ 0 ] ) ;
F_14 ( V_40 [ 1 ] ) ;
V_42:
F_14 ( V_39 [ 0 ] ) ;
F_14 ( V_39 [ 1 ] ) ;
}
void F_24 ( int V_19 , int F_5 )
{
int V_32 ;
F_20 () ;
F_16 () ;
V_32 = F_7 ( & V_33 , V_33 . V_14 + 1 ) ;
if ( V_32 ) {
F_3 ( V_17 L_15
L_16 , V_19 ) ;
goto V_34;
}
V_33 . F_2 [ V_33 . V_14 ++ ] =
( (struct V_5 ) { . V_19 = V_19 ,
. V_37 = F_5 ? V_38 : V_49 ,
. V_18 = 0 } ) ;
V_34:
F_17 () ;
}
void F_25 ( int V_19 , int F_5 )
{
if ( ! F_26 ( V_19 ) )
return;
if ( ( F_5 || V_50 ) && ( ! F_5 || V_51 ) )
return;
F_24 ( V_19 , F_5 ) ;
}
static void F_27 ( void )
{
if ( V_30 == - 1 )
return;
F_12 ( V_30 , 1 ) ;
F_13 ( V_31 , 0 ) ;
V_30 = - 1 ;
}
static void T_1 F_28 ( int V_52 )
{
V_53 = 1 ;
}
static void F_29 ( void * V_54 )
{
struct V_55 * V_56 = V_54 ;
V_56 -> V_32 = 0 ;
if ( F_30 ( & V_56 -> V_57 , & V_56 -> V_58 , NULL , NULL , NULL ) )
V_56 -> V_32 = - V_15 ;
}
static int F_31 ( int V_57 , int V_58 )
{
int V_28 ;
V_28 = F_32 ( V_57 , V_59 ) ;
if ( V_28 < 0 )
return - V_15 ;
if ( ( F_32 ( V_57 , V_60 , V_28 | V_61 | V_62 ) < 0 ) ||
( F_32 ( V_57 , V_63 , F_33 () ) < 0 ) )
return - V_15 ;
if ( ( F_32 ( V_58 , V_60 , V_28 | V_61 ) < 0 ) )
return - V_15 ;
return 0 ;
}
static void T_1 F_34 ( void (* F_35)( int , int ) )
{
struct V_64 V_65 , V_24 ;
struct V_55 V_66 = { . V_57 = - 1 , . V_58 = - 1 } ;
int V_57 , V_58 , V_32 ;
F_36 ( F_29 , & V_66 ) ;
if ( V_66 . V_32 ) {
F_3 ( V_17 L_17 ,
- V_66 . V_32 ) ;
return;
}
V_57 = V_66 . V_57 ;
V_58 = V_66 . V_58 ;
if ( ( V_57 == - 1 ) || ( V_58 == - 1 ) ) {
F_3 ( V_17 L_18
L_19 ) ;
return;
}
V_32 = F_37 ( V_57 ) ;
if ( V_32 < 0 ) {
F_3 ( V_17 L_20 ,
- V_32 ) ;
return;
}
V_32 = F_31 ( V_57 , V_58 ) ;
if ( V_32 < 0 ) {
F_3 ( V_17 L_21
L_5 , - V_32 ) ;
return;
}
if ( V_64 ( V_67 , NULL , & V_65 ) < 0 ) {
F_3 ( V_17 L_22
L_23 , V_15 ) ;
return;
}
V_24 = V_65 ;
V_24 . V_68 = F_28 ;
if ( V_64 ( V_67 , & V_24 , NULL ) < 0 ) {
F_3 ( V_17 L_24
L_23 , V_15 ) ;
return;
}
V_53 = 0 ;
(* F_35)( V_57 , V_58 ) ;
F_14 ( V_57 ) ;
F_14 ( V_58 ) ;
if ( V_64 ( V_67 , & V_65 , NULL ) < 0 )
F_3 ( V_17 L_25
L_23 , V_15 ) ;
}
static void F_38 ( int V_57 , int V_58 )
{
int V_8 ;
char V_69 [ 512 ] ;
F_3 ( V_70 L_26 ) ;
memset ( V_69 , 0 , sizeof( V_69 ) ) ;
while ( F_6 ( V_57 , V_69 , sizeof( V_69 ) ) > 0 ) ;
if ( V_15 != V_71 )
F_3 ( V_17 L_27 ,
V_15 ) ;
while ( ( ( V_8 = F_5 ( V_58 , V_69 , sizeof( V_69 ) ) ) > 0 ) &&
! ( { F_39 () ; V_53 ; } )
void F_40 ( int V_57 , int V_58 )
{
F_3 ( V_70 L_28
L_29 ) ;
F_14 ( V_58 ) ;
if ( V_53 ) {
F_3 ( V_72 L_30 ) ;
V_51 = 1 ;
} else
F_3 ( V_72 L_31 ) ;
}
static void T_1 F_41 ( void )
{
if ( ( F_42 ( L_32 , V_73 ) < 0 ) &&
( F_42 ( L_33 , V_73 ) < 0 ) ) {
F_3 ( V_74 L_34
L_35 ) ;
return;
}
F_34 ( F_38 ) ;
F_34 ( F_40 ) ;
}
void T_1 F_43 ( void )
{
F_41 () ;
}
