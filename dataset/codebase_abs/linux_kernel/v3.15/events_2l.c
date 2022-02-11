static unsigned F_1 ( void )
{
return V_1 ;
}
static void F_2 ( struct V_2 * V_3 , unsigned V_4 )
{
F_3 ( V_3 -> V_5 , F_4 ( F_5 ( V_6 , V_3 -> V_4 ) ) ) ;
F_6 ( V_3 -> V_5 , F_4 ( F_5 ( V_6 , V_4 ) ) ) ;
}
static void F_7 ( unsigned V_7 )
{
struct V_8 * V_9 = V_10 ;
F_8 ( V_7 , F_4 ( & V_9 -> V_11 [ 0 ] ) ) ;
}
static void F_9 ( unsigned V_7 )
{
struct V_8 * V_9 = V_10 ;
F_10 ( V_7 , F_4 ( & V_9 -> V_11 [ 0 ] ) ) ;
}
static bool F_11 ( unsigned V_7 )
{
struct V_8 * V_9 = V_10 ;
return F_12 ( V_7 , F_4 ( & V_9 -> V_11 [ 0 ] ) ) ;
}
static bool F_13 ( unsigned V_7 )
{
struct V_8 * V_9 = V_10 ;
return F_14 ( V_7 , F_4 ( & V_9 -> V_12 [ 0 ] ) ) ;
}
static void F_15 ( unsigned V_7 )
{
struct V_8 * V_9 = V_10 ;
F_10 ( V_7 , F_4 ( & V_9 -> V_12 [ 0 ] ) ) ;
}
static void F_16 ( unsigned V_7 )
{
struct V_8 * V_9 = V_10 ;
unsigned int V_4 = F_17 () ;
int V_13 = 0 , V_11 = 0 ;
F_18 ( ! F_19 () ) ;
if ( F_20 ( ( V_4 != F_21 ( V_7 ) ) ) )
V_13 = 1 ;
else {
F_8 ( V_7 , F_4 ( & V_9 -> V_12 [ 0 ] ) ) ;
V_11 = F_12 ( V_7 , F_4 ( & V_9 -> V_11 [ 0 ] ) ) ;
if ( F_20 ( V_11 && F_22 () ) ) {
F_10 ( V_7 , F_4 ( & V_9 -> V_12 [ 0 ] ) ) ;
V_13 = 1 ;
}
}
if ( V_13 ) {
struct V_14 V_15 = { . V_7 = V_7 } ;
( void ) F_23 ( V_16 , & V_15 ) ;
} else {
struct V_17 * V_17 = F_24 ( V_18 ) ;
if ( V_11 &&
! F_14 ( V_7 / V_19 ,
F_4 ( & V_17 -> V_20 ) ) )
V_17 -> V_21 = 1 ;
}
F_25 () ;
}
static inline T_1 F_26 ( unsigned int V_4 ,
struct V_8 * V_22 ,
unsigned int V_23 )
{
return V_22 -> V_11 [ V_23 ] &
F_5 ( V_6 , V_4 ) [ V_23 ] &
~ V_22 -> V_12 [ V_23 ] ;
}
static void F_27 ( unsigned V_4 )
{
int V_24 ;
T_1 V_25 ;
T_1 V_26 ;
int V_27 , V_28 ;
int V_29 , V_30 ;
int V_31 ;
struct V_8 * V_9 = V_10 ;
struct V_17 * V_17 = F_24 ( V_18 ) ;
V_24 = F_28 ( V_4 , V_32 ) ;
if ( V_24 != - 1 ) {
unsigned int V_5 = F_29 ( V_24 ) ;
V_29 = V_5 / V_33 ;
V_30 = V_5 % V_33 ;
if ( F_26 ( V_4 , V_9 , V_29 ) & ( 1ULL << V_30 ) )
F_30 ( V_24 ) ;
}
V_25 = F_31 ( & V_17 -> V_20 , 0 ) ;
V_27 = F_24 ( V_34 ) ;
V_28 = F_24 ( V_35 ) ;
V_29 = V_27 ;
for ( V_31 = 0 ; V_25 != 0 ; V_31 ++ ) {
T_1 V_36 ;
V_36 = F_32 ( V_25 , V_29 ) ;
if ( V_36 == 0 ) {
V_29 = 0 ;
V_30 = 0 ;
continue;
}
V_29 = F_33 ( V_36 ) ;
V_26 = F_26 ( V_4 , V_9 , V_29 ) ;
V_30 = 0 ;
if ( V_29 == V_27 ) {
if ( V_31 == 0 )
V_30 = V_28 ;
}
do {
T_1 V_37 ;
int V_7 ;
V_37 = F_32 ( V_26 , V_30 ) ;
if ( V_37 == 0 )
break;
V_30 = F_33 ( V_37 ) ;
V_7 = ( V_29 * V_19 ) + V_30 ;
V_24 = F_34 ( V_7 ) ;
if ( V_24 != - 1 )
F_30 ( V_24 ) ;
V_30 = ( V_30 + 1 ) % V_19 ;
F_35 ( V_34 ,
V_30 ? V_29 :
( V_29 + 1 ) % V_19 ) ;
F_35 ( V_35 , V_30 ) ;
} while ( V_30 != 0 );
if ( ( V_29 != V_27 ) || ( V_31 != 0 ) )
V_25 &= ~ ( 1UL << V_29 ) ;
V_29 = ( V_29 + 1 ) % V_19 ;
}
}
T_2 F_36 ( int V_24 , void * V_38 )
{
struct V_8 * V_22 = V_10 ;
int V_4 = F_37 () ;
T_1 * V_39 = F_5 ( V_6 , V_4 ) ;
int V_31 ;
unsigned long V_40 ;
static F_38 ( V_41 ) ;
struct V_17 * V_42 ;
F_39 ( & V_41 , V_40 ) ;
F_40 ( L_1 , V_4 ) ;
F_41 (i) {
int V_43 ;
V_42 = F_5 ( V_18 , V_31 ) ;
V_43 = ( F_42 () && V_31 == V_4 )
? F_43 ( F_42 () )
: V_42 -> V_44 ;
F_40 ( L_2 V_45 L_3 , V_31 ,
V_43 , V_42 -> V_21 ,
( int ) ( sizeof( V_42 -> V_20 ) * 2 ) ,
V_42 -> V_20 ) ;
}
V_42 = F_5 ( V_18 , V_4 ) ;
F_40 ( L_4 ) ;
for ( V_31 = F_44 ( V_22 -> V_11 ) - 1 ; V_31 >= 0 ; V_31 -- )
F_40 ( L_5 V_45 L_6 ,
( int ) sizeof( V_22 -> V_11 [ 0 ] ) * 2 ,
V_22 -> V_11 [ V_31 ] ,
V_31 % 8 == 0 ? L_7 : L_8 ) ;
F_40 ( L_9 ) ;
for ( V_31 = F_44 ( V_22 -> V_12 ) - 1 ; V_31 >= 0 ; V_31 -- )
F_40 ( L_5 V_45 L_6 ,
( int ) ( sizeof( V_22 -> V_12 [ 0 ] ) * 2 ) ,
V_22 -> V_12 [ V_31 ] ,
V_31 % 8 == 0 ? L_7 : L_8 ) ;
F_40 ( L_10 ) ;
for ( V_31 = F_44 ( V_22 -> V_12 ) - 1 ; V_31 >= 0 ; V_31 -- )
F_40 ( L_5 V_45 L_6 ,
( int ) ( sizeof( V_22 -> V_12 [ 0 ] ) * 2 ) ,
V_22 -> V_11 [ V_31 ] & ~ V_22 -> V_12 [ V_31 ] ,
V_31 % 8 == 0 ? L_7 : L_8 ) ;
F_40 ( L_11 , V_4 ) ;
for ( V_31 = ( V_1 / V_19 ) - 1 ; V_31 >= 0 ; V_31 -- )
F_40 ( L_5 V_45 L_6 , ( int ) ( sizeof( V_39 [ 0 ] ) * 2 ) ,
V_39 [ V_31 ] ,
V_31 % 8 == 0 ? L_7 : L_8 ) ;
F_40 ( L_12 ) ;
for ( V_31 = F_44 ( V_22 -> V_12 ) - 1 ; V_31 >= 0 ; V_31 -- ) {
T_1 V_43 = V_22 -> V_11 [ V_31 ]
& ~ V_22 -> V_12 [ V_31 ]
& V_39 [ V_31 ] ;
F_40 ( L_5 V_45 L_6 ,
( int ) ( sizeof( V_22 -> V_12 [ 0 ] ) * 2 ) ,
V_43 , V_31 % 8 == 0 ? L_7 : L_8 ) ;
}
F_40 ( L_13 ) ;
for ( V_31 = 0 ; V_31 < V_1 ; V_31 ++ ) {
if ( F_12 ( V_31 , F_4 ( V_22 -> V_11 ) ) ) {
int V_29 = V_31 / V_19 ;
F_40 ( L_14 ,
F_21 ( V_31 ) , V_31 ,
F_34 ( V_31 ) ,
F_12 ( V_29 , F_4 ( & V_42 -> V_20 ) )
? L_15 : L_16 ,
! F_12 ( V_31 , F_4 ( V_22 -> V_12 ) )
? L_15 : L_17 ,
F_12 ( V_31 , F_4 ( V_39 ) )
? L_15 : L_18 ) ;
}
}
F_45 ( & V_41 , V_40 ) ;
return V_46 ;
}
void T_3 F_46 ( void )
{
F_47 ( L_19 ) ;
V_47 = & V_48 ;
}
