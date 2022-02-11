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
F_6 ( L_2 ,
F_4 ( V_4 ) ) ;
V_6 = - V_18 ;
} else if ( V_10 -> V_13 ) {
V_10 -> V_13 ( V_10 ) ;
V_7 ++ ;
} else {
F_6 ( L_3 ,
F_7 ( V_10 ) ) ;
V_6 = - V_18 ;
}
}
}
if ( V_7 )
return V_7 ;
return V_6 ;
}
void F_8 ( struct V_1 * V_2 )
{
F_9 ( V_2 ) ;
V_2 -> V_12 = true ;
F_1 ( V_2 ) ;
F_10 ( V_2 ) ;
}
static int F_11 ( void * V_19 )
{
struct V_1 * V_2 = V_19 ;
struct V_20 V_21 = { . V_22 = 1 } ;
unsigned long V_23 , V_24 ;
int V_6 ;
F_12 ( V_25 , V_26 , & V_21 ) ;
V_24 = F_13 ( 10 ) ;
V_23 = ( V_2 -> V_15 & V_16 ) ?
V_27 : V_24 ;
F_3 ( L_4 ,
F_14 ( V_2 ) , V_23 ) ;
do {
V_6 = F_15 ( V_2 , & V_2 -> V_28 ) ;
if ( V_6 )
break;
V_6 = F_1 ( V_2 ) ;
V_2 -> V_12 = false ;
F_10 ( V_2 ) ;
if ( V_6 < 0 ) {
F_16 ( V_29 ) ;
if ( ! F_17 () )
F_18 ( V_30 ) ;
F_16 ( V_31 ) ;
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
F_16 ( V_29 ) ;
if ( V_2 -> V_15 & V_16 )
V_2 -> V_32 -> V_33 ( V_2 , 1 ) ;
if ( ! F_17 () )
F_18 ( V_23 ) ;
F_16 ( V_31 ) ;
} while ( ! F_17 () );
if ( V_2 -> V_15 & V_16 )
V_2 -> V_32 -> V_33 ( V_2 , 0 ) ;
F_3 ( L_5 ,
F_14 ( V_2 ) , V_6 ) ;
return V_6 ;
}
static int F_19 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
F_20 ( ! V_2 -> V_34 ) ;
if ( ! V_2 -> V_35 ++ ) {
if ( ! ( V_2 -> V_36 & V_37 ) ) {
F_21 ( & V_2 -> V_28 , 0 ) ;
V_2 -> F_11 =
F_22 ( F_11 , V_2 ,
L_6 , F_14 ( V_2 ) ) ;
if ( F_23 ( V_2 -> F_11 ) ) {
int V_38 = F_24 ( V_2 -> F_11 ) ;
V_2 -> V_35 -- ;
return V_38 ;
}
} else if ( V_2 -> V_15 & V_16 ) {
V_2 -> V_32 -> V_33 ( V_2 , 1 ) ;
}
}
return 0 ;
}
static int F_25 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
F_20 ( ! V_2 -> V_34 ) ;
if ( V_2 -> V_35 < 1 )
return - V_18 ;
if ( ! -- V_2 -> V_35 ) {
if ( ! ( V_2 -> V_36 & V_37 ) ) {
F_21 ( & V_2 -> V_28 , 1 ) ;
F_26 ( V_2 -> F_11 ) ;
} else if ( V_2 -> V_15 & V_16 ) {
V_2 -> V_32 -> V_33 ( V_2 , 0 ) ;
}
}
return 0 ;
}
static void F_27 ( struct V_3 * V_4 )
{
struct V_9 * V_10 ;
int V_5 ;
V_4 -> V_11 = NULL ;
if ( ( V_4 -> V_2 -> V_15 & V_16 ) &&
V_4 -> V_2 -> V_35 == 1 )
for ( V_5 = 0 ; V_5 < V_4 -> V_39 ; V_5 ++ ) {
V_10 = V_4 -> V_9 [ V_5 ] ;
if ( V_10 && V_10 -> V_13 ) {
V_4 -> V_11 = V_10 ;
break;
}
}
}
int F_28 ( struct V_9 * V_10 , T_1 * V_40 )
{
int V_6 ;
unsigned char V_41 ;
if ( ! V_10 )
return - V_18 ;
F_3 ( L_7 , F_7 ( V_10 ) ) ;
if ( V_10 -> V_13 ) {
F_3 ( L_8 , F_7 ( V_10 ) ) ;
return - V_42 ;
}
V_6 = F_2 ( V_10 -> V_4 , 0 , 0 , V_43 , 0 , & V_41 ) ;
if ( V_6 )
return V_6 ;
V_41 |= 1 << V_10 -> V_44 ;
V_41 |= 1 ;
V_6 = F_2 ( V_10 -> V_4 , 1 , 0 , V_43 , V_41 , NULL ) ;
if ( V_6 )
return V_6 ;
V_10 -> V_13 = V_40 ;
V_6 = F_19 ( V_10 -> V_4 ) ;
if ( V_6 )
V_10 -> V_13 = NULL ;
F_27 ( V_10 -> V_4 ) ;
return V_6 ;
}
int F_29 ( struct V_9 * V_10 )
{
int V_6 ;
unsigned char V_41 ;
if ( ! V_10 )
return - V_18 ;
F_3 ( L_9 , F_7 ( V_10 ) ) ;
if ( V_10 -> V_13 ) {
V_10 -> V_13 = NULL ;
F_25 ( V_10 -> V_4 ) ;
F_27 ( V_10 -> V_4 ) ;
}
V_6 = F_2 ( V_10 -> V_4 , 0 , 0 , V_43 , 0 , & V_41 ) ;
if ( V_6 )
return V_6 ;
V_41 &= ~ ( 1 << V_10 -> V_44 ) ;
if ( ! ( V_41 & 0xFE ) )
V_41 = 0 ;
V_6 = F_2 ( V_10 -> V_4 , 1 , 0 , V_43 , V_41 , NULL ) ;
if ( V_6 )
return V_6 ;
return 0 ;
}
