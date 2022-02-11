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
F_3 ( L_1 ,
F_4 ( V_2 ) , V_4 ) ;
return V_4 ;
}
V_5 = 0 ;
for ( V_3 = 1 ; V_3 <= 7 ; V_3 ++ ) {
if ( V_6 & ( 1 << V_3 ) ) {
V_8 = V_2 -> V_7 [ V_3 - 1 ] ;
if ( ! V_8 ) {
F_5 ( L_2
L_3 ,
F_4 ( V_2 ) ) ;
V_4 = - V_12 ;
} else if ( V_8 -> V_10 ) {
V_8 -> V_10 ( V_8 ) ;
V_5 ++ ;
} else {
F_5 ( L_4 ,
F_6 ( V_8 ) ) ;
V_4 = - V_12 ;
}
}
}
if ( V_5 )
return V_5 ;
return V_4 ;
}
static int F_7 ( void * V_13 )
{
struct V_14 * V_15 = V_13 ;
struct V_16 V_17 = { . V_18 = 1 } ;
unsigned long V_19 , V_20 ;
int V_4 ;
F_8 ( V_21 , V_22 , & V_17 ) ;
V_20 = F_9 ( 10 ) ;
V_19 = ( V_15 -> V_23 & V_24 ) ?
V_25 : V_20 ;
F_3 ( L_5 ,
F_10 ( V_15 ) , V_19 ) ;
do {
V_4 = F_11 ( V_15 , & V_15 -> V_26 ) ;
if ( V_4 )
break;
V_4 = F_1 ( V_15 -> V_2 ) ;
F_12 ( V_15 ) ;
if ( V_4 < 0 ) {
F_13 ( V_27 ) ;
if ( ! F_14 () )
F_15 ( V_28 ) ;
F_13 ( V_29 ) ;
}
if ( ! ( V_15 -> V_23 & V_24 ) ) {
if ( V_4 > 0 )
V_19 /= 2 ;
else {
V_19 ++ ;
if ( V_19 > V_20 )
V_19 = V_20 ;
}
}
F_13 ( V_27 ) ;
if ( V_15 -> V_23 & V_24 )
V_15 -> V_30 -> V_31 ( V_15 , 1 ) ;
if ( ! F_14 () )
F_15 ( V_19 ) ;
F_13 ( V_29 ) ;
} while ( ! F_14 () );
if ( V_15 -> V_23 & V_24 )
V_15 -> V_30 -> V_31 ( V_15 , 0 ) ;
F_3 ( L_6 ,
F_10 ( V_15 ) , V_4 ) ;
return V_4 ;
}
static int F_16 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = V_2 -> V_15 ;
F_17 ( ! V_15 -> V_32 ) ;
if ( ! V_15 -> V_33 ++ ) {
F_18 ( & V_15 -> V_26 , 0 ) ;
V_15 -> F_7 =
F_19 ( F_7 , V_15 , L_7 ,
F_10 ( V_15 ) ) ;
if ( F_20 ( V_15 -> F_7 ) ) {
int V_34 = F_21 ( V_15 -> F_7 ) ;
V_15 -> V_33 -- ;
return V_34 ;
}
}
return 0 ;
}
static int F_22 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = V_2 -> V_15 ;
F_17 ( ! V_15 -> V_32 ) ;
F_23 ( V_15 -> V_33 < 1 ) ;
if ( ! -- V_15 -> V_33 ) {
F_18 ( & V_15 -> V_26 , 1 ) ;
F_24 ( V_15 -> F_7 ) ;
}
return 0 ;
}
static void F_25 ( struct V_1 * V_2 )
{
struct V_7 * V_8 ;
int V_3 ;
V_2 -> V_9 = NULL ;
if ( ( V_2 -> V_15 -> V_23 & V_24 ) &&
V_2 -> V_15 -> V_33 == 1 )
for ( V_3 = 0 ; V_3 < V_2 -> V_35 ; V_3 ++ ) {
V_8 = V_2 -> V_7 [ V_3 ] ;
if ( V_8 && V_8 -> V_10 ) {
V_2 -> V_9 = V_8 ;
break;
}
}
}
int F_26 ( struct V_7 * V_8 , T_1 * V_36 )
{
int V_4 ;
unsigned char V_37 ;
F_23 ( ! V_8 ) ;
F_23 ( ! V_8 -> V_2 ) ;
F_3 ( L_8 , F_6 ( V_8 ) ) ;
if ( V_8 -> V_10 ) {
F_3 ( L_9 , F_6 ( V_8 ) ) ;
return - V_38 ;
}
V_4 = F_2 ( V_8 -> V_2 , 0 , 0 , V_39 , 0 , & V_37 ) ;
if ( V_4 )
return V_4 ;
V_37 |= 1 << V_8 -> V_40 ;
V_37 |= 1 ;
V_4 = F_2 ( V_8 -> V_2 , 1 , 0 , V_39 , V_37 , NULL ) ;
if ( V_4 )
return V_4 ;
V_8 -> V_10 = V_36 ;
V_4 = F_16 ( V_8 -> V_2 ) ;
if ( V_4 )
V_8 -> V_10 = NULL ;
F_25 ( V_8 -> V_2 ) ;
return V_4 ;
}
int F_27 ( struct V_7 * V_8 )
{
int V_4 ;
unsigned char V_37 ;
F_23 ( ! V_8 ) ;
F_23 ( ! V_8 -> V_2 ) ;
F_3 ( L_10 , F_6 ( V_8 ) ) ;
if ( V_8 -> V_10 ) {
V_8 -> V_10 = NULL ;
F_22 ( V_8 -> V_2 ) ;
F_25 ( V_8 -> V_2 ) ;
}
V_4 = F_2 ( V_8 -> V_2 , 0 , 0 , V_39 , 0 , & V_37 ) ;
if ( V_4 )
return V_4 ;
V_37 &= ~ ( 1 << V_8 -> V_40 ) ;
if ( ! ( V_37 & 0xFE ) )
V_37 = 0 ;
V_4 = F_2 ( V_8 -> V_2 , 1 , 0 , V_39 , V_37 , NULL ) ;
if ( V_4 )
return V_4 ;
return 0 ;
}
