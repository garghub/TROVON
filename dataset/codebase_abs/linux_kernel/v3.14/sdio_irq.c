static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_5 , V_6 , V_7 ;
unsigned char V_8 ;
struct V_9 * V_10 ;
V_10 = V_4 -> V_11 ;
if ( V_10 && V_2 -> V_12 ) {
V_10 -> V_13 ( V_10 ) ;
return 1 ;
}
V_6 = F_2 ( V_4 , 0 , 0 , V_14 , 0 , & V_8 ) ;
if ( V_6 ) {
F_3 ( L_1 ,
F_4 ( V_4 ) , V_6 ) ;
return V_6 ;
}
if ( V_8 && F_5 ( V_4 ) &&
! ( V_2 -> V_15 & V_16 ) ) {
unsigned char V_17 ;
F_2 ( V_4 , 0 , 0 , 0xff , 0 , & V_17 ) ;
}
V_7 = 0 ;
for ( V_5 = 1 ; V_5 <= 7 ; V_5 ++ ) {
if ( V_8 & ( 1 << V_5 ) ) {
V_10 = V_4 -> V_9 [ V_5 - 1 ] ;
if ( ! V_10 ) {
F_6 ( L_2
L_3 ,
F_4 ( V_4 ) ) ;
V_6 = - V_18 ;
} else if ( V_10 -> V_13 ) {
V_10 -> V_13 ( V_10 ) ;
V_7 ++ ;
} else {
F_6 ( L_4 ,
F_7 ( V_10 ) ) ;
V_6 = - V_18 ;
}
}
}
if ( V_7 )
return V_7 ;
return V_6 ;
}
static int F_8 ( void * V_19 )
{
struct V_1 * V_2 = V_19 ;
struct V_20 V_21 = { . V_22 = 1 } ;
unsigned long V_23 , V_24 ;
int V_6 ;
F_9 ( V_25 , V_26 , & V_21 ) ;
V_24 = F_10 ( 10 ) ;
V_23 = ( V_2 -> V_15 & V_16 ) ?
V_27 : V_24 ;
F_3 ( L_5 ,
F_11 ( V_2 ) , V_23 ) ;
do {
V_6 = F_12 ( V_2 , & V_2 -> V_28 ) ;
if ( V_6 )
break;
V_6 = F_1 ( V_2 ) ;
V_2 -> V_12 = false ;
F_13 ( V_2 ) ;
if ( V_6 < 0 ) {
F_14 ( V_29 ) ;
if ( ! F_15 () )
F_16 ( V_30 ) ;
F_14 ( V_31 ) ;
}
if ( ! ( V_2 -> V_15 & V_16 ) ) {
if ( V_6 > 0 )
V_23 /= 2 ;
else {
V_23 ++ ;
if ( V_23 > V_24 )
V_23 = V_24 ;
}
}
F_14 ( V_29 ) ;
if ( V_2 -> V_15 & V_16 ) {
F_17 ( V_2 ) ;
V_2 -> V_32 -> V_33 ( V_2 , 1 ) ;
F_18 ( V_2 ) ;
}
if ( ! F_15 () )
F_16 ( V_23 ) ;
F_14 ( V_31 ) ;
} while ( ! F_15 () );
if ( V_2 -> V_15 & V_16 ) {
F_17 ( V_2 ) ;
V_2 -> V_32 -> V_33 ( V_2 , 0 ) ;
F_18 ( V_2 ) ;
}
F_3 ( L_6 ,
F_11 ( V_2 ) , V_6 ) ;
return V_6 ;
}
static int F_19 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
F_20 ( ! V_2 -> V_34 ) ;
if ( ! V_2 -> V_35 ++ ) {
F_21 ( & V_2 -> V_28 , 0 ) ;
V_2 -> F_8 =
F_22 ( F_8 , V_2 , L_7 ,
F_11 ( V_2 ) ) ;
if ( F_23 ( V_2 -> F_8 ) ) {
int V_36 = F_24 ( V_2 -> F_8 ) ;
V_2 -> V_35 -- ;
return V_36 ;
}
}
return 0 ;
}
static int F_25 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
F_20 ( ! V_2 -> V_34 ) ;
F_26 ( V_2 -> V_35 < 1 ) ;
if ( ! -- V_2 -> V_35 ) {
F_21 ( & V_2 -> V_28 , 1 ) ;
F_27 ( V_2 -> F_8 ) ;
}
return 0 ;
}
static void F_28 ( struct V_3 * V_4 )
{
struct V_9 * V_10 ;
int V_5 ;
V_4 -> V_11 = NULL ;
if ( ( V_4 -> V_2 -> V_15 & V_16 ) &&
V_4 -> V_2 -> V_35 == 1 )
for ( V_5 = 0 ; V_5 < V_4 -> V_37 ; V_5 ++ ) {
V_10 = V_4 -> V_9 [ V_5 ] ;
if ( V_10 && V_10 -> V_13 ) {
V_4 -> V_11 = V_10 ;
break;
}
}
}
int F_29 ( struct V_9 * V_10 , T_1 * V_38 )
{
int V_6 ;
unsigned char V_39 ;
F_26 ( ! V_10 ) ;
F_26 ( ! V_10 -> V_4 ) ;
F_3 ( L_8 , F_7 ( V_10 ) ) ;
if ( V_10 -> V_13 ) {
F_3 ( L_9 , F_7 ( V_10 ) ) ;
return - V_40 ;
}
V_6 = F_2 ( V_10 -> V_4 , 0 , 0 , V_41 , 0 , & V_39 ) ;
if ( V_6 )
return V_6 ;
V_39 |= 1 << V_10 -> V_42 ;
V_39 |= 1 ;
V_6 = F_2 ( V_10 -> V_4 , 1 , 0 , V_41 , V_39 , NULL ) ;
if ( V_6 )
return V_6 ;
V_10 -> V_13 = V_38 ;
V_6 = F_19 ( V_10 -> V_4 ) ;
if ( V_6 )
V_10 -> V_13 = NULL ;
F_28 ( V_10 -> V_4 ) ;
return V_6 ;
}
int F_30 ( struct V_9 * V_10 )
{
int V_6 ;
unsigned char V_39 ;
F_26 ( ! V_10 ) ;
F_26 ( ! V_10 -> V_4 ) ;
F_3 ( L_10 , F_7 ( V_10 ) ) ;
if ( V_10 -> V_13 ) {
V_10 -> V_13 = NULL ;
F_25 ( V_10 -> V_4 ) ;
F_28 ( V_10 -> V_4 ) ;
}
V_6 = F_2 ( V_10 -> V_4 , 0 , 0 , V_41 , 0 , & V_39 ) ;
if ( V_6 )
return V_6 ;
V_39 &= ~ ( 1 << V_10 -> V_42 ) ;
if ( ! ( V_39 & 0xFE ) )
V_39 = 0 ;
V_6 = F_2 ( V_10 -> V_4 , 1 , 0 , V_41 , V_39 , NULL ) ;
if ( V_6 )
return V_6 ;
return 0 ;
}
