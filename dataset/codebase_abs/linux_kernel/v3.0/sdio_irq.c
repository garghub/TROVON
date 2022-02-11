static int F_1 ( struct V_1 * V_2 )
{
int V_3 , V_4 , V_5 ;
unsigned char V_6 ;
struct V_7 * V_8 ;
V_8 = V_2 -> V_9 ;
if ( V_8 ) {
V_8 -> V_10 ( V_8 ) ;
return 1 ;
}
V_4 = F_2 ( V_2 , 0 , 0 , V_11 , 0 , & V_6 ) ;
if ( V_4 ) {
F_3 ( V_12 L_1 ,
F_4 ( V_2 ) , V_4 ) ;
return V_4 ;
}
V_5 = 0 ;
for ( V_3 = 1 ; V_3 <= 7 ; V_3 ++ ) {
if ( V_6 & ( 1 << V_3 ) ) {
V_8 = V_2 -> V_7 [ V_3 - 1 ] ;
if ( ! V_8 ) {
F_3 ( V_13 L_2
L_3 ,
F_4 ( V_2 ) ) ;
V_4 = - V_14 ;
} else if ( V_8 -> V_10 ) {
V_8 -> V_10 ( V_8 ) ;
V_5 ++ ;
} else {
F_3 ( V_13 L_4 ,
F_5 ( V_8 ) ) ;
V_4 = - V_14 ;
}
}
}
if ( V_5 )
return V_5 ;
return V_4 ;
}
static int F_6 ( void * V_15 )
{
struct V_16 * V_17 = V_15 ;
struct V_18 V_19 = { . V_20 = 1 } ;
unsigned long V_21 , V_22 ;
int V_4 ;
F_7 ( V_23 , V_24 , & V_19 ) ;
V_22 = F_8 ( 10 ) ;
V_21 = ( V_17 -> V_25 & V_26 ) ?
V_27 : V_22 ;
F_9 ( L_5 ,
F_10 ( V_17 ) , V_21 ) ;
do {
V_4 = F_11 ( V_17 , & V_17 -> V_28 ) ;
if ( V_4 )
break;
V_4 = F_1 ( V_17 -> V_2 ) ;
F_12 ( V_17 ) ;
if ( V_4 < 0 ) {
F_13 ( V_29 ) ;
if ( ! F_14 () )
F_15 ( V_30 ) ;
F_13 ( V_31 ) ;
}
if ( ! ( V_17 -> V_25 & V_26 ) ) {
if ( V_4 > 0 )
V_21 /= 2 ;
else {
V_21 ++ ;
if ( V_21 > V_22 )
V_21 = V_22 ;
}
}
F_13 ( V_29 ) ;
if ( V_17 -> V_25 & V_26 )
V_17 -> V_32 -> V_33 ( V_17 , 1 ) ;
if ( ! F_14 () )
F_15 ( V_21 ) ;
F_13 ( V_31 ) ;
} while ( ! F_14 () );
if ( V_17 -> V_25 & V_26 )
V_17 -> V_32 -> V_33 ( V_17 , 0 ) ;
F_9 ( L_6 ,
F_10 ( V_17 ) , V_4 ) ;
return V_4 ;
}
static int F_16 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = V_2 -> V_17 ;
F_17 ( ! V_17 -> V_34 ) ;
if ( ! V_17 -> V_35 ++ ) {
F_18 ( & V_17 -> V_28 , 0 ) ;
V_17 -> F_6 =
F_19 ( F_6 , V_17 , L_7 ,
F_10 ( V_17 ) ) ;
if ( F_20 ( V_17 -> F_6 ) ) {
int V_36 = F_21 ( V_17 -> F_6 ) ;
V_17 -> V_35 -- ;
return V_36 ;
}
}
return 0 ;
}
static int F_22 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = V_2 -> V_17 ;
F_17 ( ! V_17 -> V_34 ) ;
F_23 ( V_17 -> V_35 < 1 ) ;
if ( ! -- V_17 -> V_35 ) {
F_18 ( & V_17 -> V_28 , 1 ) ;
F_24 ( V_17 -> F_6 ) ;
}
return 0 ;
}
static void F_25 ( struct V_1 * V_2 )
{
struct V_7 * V_8 ;
int V_3 ;
V_2 -> V_9 = NULL ;
if ( ( V_2 -> V_17 -> V_25 & V_26 ) &&
V_2 -> V_17 -> V_35 == 1 )
for ( V_3 = 0 ; V_3 < V_2 -> V_37 ; V_3 ++ ) {
V_8 = V_2 -> V_7 [ V_3 ] ;
if ( V_8 && V_8 -> V_10 ) {
V_2 -> V_9 = V_8 ;
break;
}
}
}
int F_26 ( struct V_7 * V_8 , T_1 * V_38 )
{
int V_4 ;
unsigned char V_39 ;
F_23 ( ! V_8 ) ;
F_23 ( ! V_8 -> V_2 ) ;
F_9 ( L_8 , F_5 ( V_8 ) ) ;
if ( V_8 -> V_10 ) {
F_9 ( L_9 , F_5 ( V_8 ) ) ;
return - V_40 ;
}
V_4 = F_2 ( V_8 -> V_2 , 0 , 0 , V_41 , 0 , & V_39 ) ;
if ( V_4 )
return V_4 ;
V_39 |= 1 << V_8 -> V_42 ;
V_39 |= 1 ;
V_4 = F_2 ( V_8 -> V_2 , 1 , 0 , V_41 , V_39 , NULL ) ;
if ( V_4 )
return V_4 ;
V_8 -> V_10 = V_38 ;
V_4 = F_16 ( V_8 -> V_2 ) ;
if ( V_4 )
V_8 -> V_10 = NULL ;
F_25 ( V_8 -> V_2 ) ;
return V_4 ;
}
int F_27 ( struct V_7 * V_8 )
{
int V_4 ;
unsigned char V_39 ;
F_23 ( ! V_8 ) ;
F_23 ( ! V_8 -> V_2 ) ;
F_9 ( L_10 , F_5 ( V_8 ) ) ;
if ( V_8 -> V_10 ) {
V_8 -> V_10 = NULL ;
F_22 ( V_8 -> V_2 ) ;
F_25 ( V_8 -> V_2 ) ;
}
V_4 = F_2 ( V_8 -> V_2 , 0 , 0 , V_41 , 0 , & V_39 ) ;
if ( V_4 )
return V_4 ;
V_39 &= ~ ( 1 << V_8 -> V_42 ) ;
if ( ! ( V_39 & 0xFE ) )
V_39 = 0 ;
V_4 = F_2 ( V_8 -> V_2 , 1 , 0 , V_41 , V_39 , NULL ) ;
if ( V_4 )
return V_4 ;
return 0 ;
}
