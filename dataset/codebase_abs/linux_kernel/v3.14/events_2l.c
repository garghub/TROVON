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
struct V_32 * V_33 ;
struct V_8 * V_9 = V_10 ;
struct V_17 * V_17 = F_24 ( V_18 ) ;
V_24 = F_28 ( V_4 , V_34 ) ;
if ( V_24 != - 1 ) {
unsigned int V_5 = F_29 ( V_24 ) ;
V_29 = V_5 / V_35 ;
V_30 = V_5 % V_35 ;
if ( F_26 ( V_4 , V_9 , V_29 ) & ( 1ULL << V_30 ) ) {
V_33 = F_30 ( V_24 ) ;
if ( V_33 )
F_31 ( V_24 , V_33 ) ;
}
}
V_25 = F_32 ( & V_17 -> V_20 , 0 ) ;
V_27 = F_24 ( V_36 ) ;
V_28 = F_24 ( V_37 ) ;
V_29 = V_27 ;
for ( V_31 = 0 ; V_25 != 0 ; V_31 ++ ) {
T_1 V_38 ;
V_38 = F_33 ( V_25 , V_29 ) ;
if ( V_38 == 0 ) {
V_29 = 0 ;
V_30 = 0 ;
continue;
}
V_29 = F_34 ( V_38 ) ;
V_26 = F_26 ( V_4 , V_9 , V_29 ) ;
V_30 = 0 ;
if ( V_29 == V_27 ) {
if ( V_31 == 0 )
V_30 = V_28 ;
}
do {
T_1 V_39 ;
int V_7 ;
V_39 = F_33 ( V_26 , V_30 ) ;
if ( V_39 == 0 )
break;
V_30 = F_34 ( V_39 ) ;
V_7 = ( V_29 * V_19 ) + V_30 ;
V_24 = F_35 ( V_7 ) ;
if ( V_24 != - 1 ) {
V_33 = F_30 ( V_24 ) ;
if ( V_33 )
F_31 ( V_24 , V_33 ) ;
}
V_30 = ( V_30 + 1 ) % V_19 ;
F_36 ( V_36 ,
V_30 ? V_29 :
( V_29 + 1 ) % V_19 ) ;
F_36 ( V_37 , V_30 ) ;
} while ( V_30 != 0 );
if ( ( V_29 != V_27 ) || ( V_31 != 0 ) )
V_25 &= ~ ( 1UL << V_29 ) ;
V_29 = ( V_29 + 1 ) % V_19 ;
}
}
T_2 F_37 ( int V_24 , void * V_40 )
{
struct V_8 * V_22 = V_10 ;
int V_4 = F_38 () ;
T_1 * V_41 = F_5 ( V_6 , V_4 ) ;
int V_31 ;
unsigned long V_42 ;
static F_39 ( V_43 ) ;
struct V_17 * V_44 ;
F_40 ( & V_43 , V_42 ) ;
F_41 ( L_1 , V_4 ) ;
F_42 (i) {
int V_45 ;
V_44 = F_5 ( V_18 , V_31 ) ;
V_45 = ( F_43 () && V_31 == V_4 )
? F_44 ( F_43 () )
: V_44 -> V_46 ;
F_41 ( L_2 V_47 L_3 , V_31 ,
V_45 , V_44 -> V_21 ,
( int ) ( sizeof( V_44 -> V_20 ) * 2 ) ,
V_44 -> V_20 ) ;
}
V_44 = F_5 ( V_18 , V_4 ) ;
F_41 ( L_4 ) ;
for ( V_31 = F_45 ( V_22 -> V_11 ) - 1 ; V_31 >= 0 ; V_31 -- )
F_41 ( L_5 V_47 L_6 ,
( int ) sizeof( V_22 -> V_11 [ 0 ] ) * 2 ,
V_22 -> V_11 [ V_31 ] ,
V_31 % 8 == 0 ? L_7 : L_8 ) ;
F_41 ( L_9 ) ;
for ( V_31 = F_45 ( V_22 -> V_12 ) - 1 ; V_31 >= 0 ; V_31 -- )
F_41 ( L_5 V_47 L_6 ,
( int ) ( sizeof( V_22 -> V_12 [ 0 ] ) * 2 ) ,
V_22 -> V_12 [ V_31 ] ,
V_31 % 8 == 0 ? L_7 : L_8 ) ;
F_41 ( L_10 ) ;
for ( V_31 = F_45 ( V_22 -> V_12 ) - 1 ; V_31 >= 0 ; V_31 -- )
F_41 ( L_5 V_47 L_6 ,
( int ) ( sizeof( V_22 -> V_12 [ 0 ] ) * 2 ) ,
V_22 -> V_11 [ V_31 ] & ~ V_22 -> V_12 [ V_31 ] ,
V_31 % 8 == 0 ? L_7 : L_8 ) ;
F_41 ( L_11 , V_4 ) ;
for ( V_31 = ( V_1 / V_19 ) - 1 ; V_31 >= 0 ; V_31 -- )
F_41 ( L_5 V_47 L_6 , ( int ) ( sizeof( V_41 [ 0 ] ) * 2 ) ,
V_41 [ V_31 ] ,
V_31 % 8 == 0 ? L_7 : L_8 ) ;
F_41 ( L_12 ) ;
for ( V_31 = F_45 ( V_22 -> V_12 ) - 1 ; V_31 >= 0 ; V_31 -- ) {
T_1 V_45 = V_22 -> V_11 [ V_31 ]
& ~ V_22 -> V_12 [ V_31 ]
& V_41 [ V_31 ] ;
F_41 ( L_5 V_47 L_6 ,
( int ) ( sizeof( V_22 -> V_12 [ 0 ] ) * 2 ) ,
V_45 , V_31 % 8 == 0 ? L_7 : L_8 ) ;
}
F_41 ( L_13 ) ;
for ( V_31 = 0 ; V_31 < V_1 ; V_31 ++ ) {
if ( F_12 ( V_31 , F_4 ( V_22 -> V_11 ) ) ) {
int V_29 = V_31 / V_19 ;
F_41 ( L_14 ,
F_21 ( V_31 ) , V_31 ,
F_35 ( V_31 ) ,
F_12 ( V_29 , F_4 ( & V_44 -> V_20 ) )
? L_15 : L_16 ,
! F_12 ( V_31 , F_4 ( V_22 -> V_12 ) )
? L_15 : L_17 ,
F_12 ( V_31 , F_4 ( V_41 ) )
? L_15 : L_18 ) ;
}
}
F_46 ( & V_43 , V_42 ) ;
return V_48 ;
}
void T_3 F_47 ( void )
{
F_48 ( L_19 ) ;
V_49 = & V_50 ;
}
