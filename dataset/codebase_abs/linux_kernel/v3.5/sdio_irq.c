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
V_7 = 0 ;
for ( V_5 = 1 ; V_5 <= 7 ; V_5 ++ ) {
if ( V_8 & ( 1 << V_5 ) ) {
V_10 = V_4 -> V_9 [ V_5 - 1 ] ;
if ( ! V_10 ) {
F_5 ( L_2
L_3 ,
F_4 ( V_4 ) ) ;
V_6 = - V_15 ;
} else if ( V_10 -> V_13 ) {
V_10 -> V_13 ( V_10 ) ;
V_7 ++ ;
} else {
F_5 ( L_4 ,
F_6 ( V_10 ) ) ;
V_6 = - V_15 ;
}
}
}
if ( V_7 )
return V_7 ;
return V_6 ;
}
static int F_7 ( void * V_16 )
{
struct V_1 * V_2 = V_16 ;
struct V_17 V_18 = { . V_19 = 1 } ;
unsigned long V_20 , V_21 ;
int V_6 ;
F_8 ( V_22 , V_23 , & V_18 ) ;
V_21 = F_9 ( 10 ) ;
V_20 = ( V_2 -> V_24 & V_25 ) ?
V_26 : V_21 ;
F_3 ( L_5 ,
F_10 ( V_2 ) , V_20 ) ;
do {
V_6 = F_11 ( V_2 , & V_2 -> V_27 ) ;
if ( V_6 )
break;
V_6 = F_1 ( V_2 ) ;
V_2 -> V_12 = false ;
F_12 ( V_2 ) ;
if ( V_6 < 0 ) {
F_13 ( V_28 ) ;
if ( ! F_14 () )
F_15 ( V_29 ) ;
F_13 ( V_30 ) ;
}
if ( ! ( V_2 -> V_24 & V_25 ) ) {
if ( V_6 > 0 )
V_20 /= 2 ;
else {
V_20 ++ ;
if ( V_20 > V_21 )
V_20 = V_21 ;
}
}
F_13 ( V_28 ) ;
if ( V_2 -> V_24 & V_25 ) {
F_16 ( V_2 ) ;
V_2 -> V_31 -> V_32 ( V_2 , 1 ) ;
F_17 ( V_2 ) ;
}
if ( ! F_14 () )
F_15 ( V_20 ) ;
F_13 ( V_30 ) ;
} while ( ! F_14 () );
if ( V_2 -> V_24 & V_25 ) {
F_16 ( V_2 ) ;
V_2 -> V_31 -> V_32 ( V_2 , 0 ) ;
F_17 ( V_2 ) ;
}
F_3 ( L_6 ,
F_10 ( V_2 ) , V_6 ) ;
return V_6 ;
}
static int F_18 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
F_19 ( ! V_2 -> V_33 ) ;
if ( ! V_2 -> V_34 ++ ) {
F_20 ( & V_2 -> V_27 , 0 ) ;
V_2 -> F_7 =
F_21 ( F_7 , V_2 , L_7 ,
F_10 ( V_2 ) ) ;
if ( F_22 ( V_2 -> F_7 ) ) {
int V_35 = F_23 ( V_2 -> F_7 ) ;
V_2 -> V_34 -- ;
return V_35 ;
}
}
return 0 ;
}
static int F_24 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
F_19 ( ! V_2 -> V_33 ) ;
F_25 ( V_2 -> V_34 < 1 ) ;
if ( ! -- V_2 -> V_34 ) {
F_20 ( & V_2 -> V_27 , 1 ) ;
F_26 ( V_2 -> F_7 ) ;
}
return 0 ;
}
static void F_27 ( struct V_3 * V_4 )
{
struct V_9 * V_10 ;
int V_5 ;
V_4 -> V_11 = NULL ;
if ( ( V_4 -> V_2 -> V_24 & V_25 ) &&
V_4 -> V_2 -> V_34 == 1 )
for ( V_5 = 0 ; V_5 < V_4 -> V_36 ; V_5 ++ ) {
V_10 = V_4 -> V_9 [ V_5 ] ;
if ( V_10 && V_10 -> V_13 ) {
V_4 -> V_11 = V_10 ;
break;
}
}
}
int F_28 ( struct V_9 * V_10 , T_1 * V_37 )
{
int V_6 ;
unsigned char V_38 ;
F_25 ( ! V_10 ) ;
F_25 ( ! V_10 -> V_4 ) ;
F_3 ( L_8 , F_6 ( V_10 ) ) ;
if ( V_10 -> V_13 ) {
F_3 ( L_9 , F_6 ( V_10 ) ) ;
return - V_39 ;
}
V_6 = F_2 ( V_10 -> V_4 , 0 , 0 , V_40 , 0 , & V_38 ) ;
if ( V_6 )
return V_6 ;
V_38 |= 1 << V_10 -> V_41 ;
V_38 |= 1 ;
V_6 = F_2 ( V_10 -> V_4 , 1 , 0 , V_40 , V_38 , NULL ) ;
if ( V_6 )
return V_6 ;
V_10 -> V_13 = V_37 ;
V_6 = F_18 ( V_10 -> V_4 ) ;
if ( V_6 )
V_10 -> V_13 = NULL ;
F_27 ( V_10 -> V_4 ) ;
return V_6 ;
}
int F_29 ( struct V_9 * V_10 )
{
int V_6 ;
unsigned char V_38 ;
F_25 ( ! V_10 ) ;
F_25 ( ! V_10 -> V_4 ) ;
F_3 ( L_10 , F_6 ( V_10 ) ) ;
if ( V_10 -> V_13 ) {
V_10 -> V_13 = NULL ;
F_24 ( V_10 -> V_4 ) ;
F_27 ( V_10 -> V_4 ) ;
}
V_6 = F_2 ( V_10 -> V_4 , 0 , 0 , V_40 , 0 , & V_38 ) ;
if ( V_6 )
return V_6 ;
V_38 &= ~ ( 1 << V_10 -> V_41 ) ;
if ( ! ( V_38 & 0xFE ) )
V_38 = 0 ;
V_6 = F_2 ( V_10 -> V_4 , 1 , 0 , V_40 , V_38 , NULL ) ;
if ( V_6 )
return V_6 ;
return 0 ;
}
