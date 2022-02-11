void F_1 ( T_1 V_1 , T_1 V_2 )
{
F_2 ( ( V_1 << V_3 ) |
( V_2 << V_4 ) , V_5 + V_6 ) ;
}
void F_3 ( T_1 V_1 , T_1 V_2 )
{
F_2 ( ( V_1 << V_3 ) |
( V_2 << V_4 ) , V_5 + V_7 ) ;
}
void F_4 ( bool V_8 )
{
F_2 ( V_8 , V_5 + V_9 ) ;
}
void F_5 ( bool V_10 )
{
void T_2 * V_11 = V_5 + V_12 ;
int V_13 ;
if ( V_10 )
F_4 ( V_10 ) ;
for ( V_13 = 0 ; V_13 < V_14 ; V_13 ++ ) {
V_15 [ V_13 ] = F_6 ( V_11 + V_13 * 4 ) ;
F_2 ( ~ V_16 [ V_13 ] , V_11 + V_13 * 4 ) ;
}
}
void F_7 ( void )
{
void T_2 * V_11 = V_5 + V_12 ;
int V_13 ;
F_4 ( false ) ;
for ( V_13 = 0 ; V_13 < V_14 ; V_13 ++ )
F_2 ( V_15 [ V_13 ] , V_11 + V_13 * 4 ) ;
}
static int F_8 ( struct V_17 * V_18 , unsigned int V_19 )
{
unsigned int V_20 = V_18 -> V_21 / 32 ;
T_1 V_22 ;
V_22 = 1 << V_18 -> V_21 % 32 ;
V_16 [ V_20 ] = V_19 ? V_16 [ V_20 ] | V_22 :
V_16 [ V_20 ] & ~ V_22 ;
return 0 ;
}
void F_9 ( void )
{
void T_2 * V_11 = V_5 + V_12 ;
int V_13 ;
for ( V_13 = 0 ; V_13 < V_14 ; V_13 ++ ) {
V_15 [ V_13 ] = F_6 ( V_11 + V_13 * 4 ) ;
F_2 ( ~ 0 , V_11 + V_13 * 4 ) ;
}
}
void F_10 ( void )
{
void T_2 * V_11 = V_5 + V_12 ;
int V_13 ;
for ( V_13 = 0 ; V_13 < V_14 ; V_13 ++ )
F_2 ( V_15 [ V_13 ] , V_11 + V_13 * 4 ) ;
}
void F_11 ( unsigned int V_21 )
{
void T_2 * V_23 ;
T_1 V_24 ;
V_23 = V_5 + V_12 + V_21 / 32 * 4 ;
V_24 = F_6 ( V_23 ) ;
V_24 &= ~ ( 1 << V_21 % 32 ) ;
F_2 ( V_24 , V_23 ) ;
}
void F_12 ( unsigned int V_21 )
{
void T_2 * V_23 ;
T_1 V_24 ;
V_23 = V_5 + V_12 + V_21 / 32 * 4 ;
V_24 = F_6 ( V_23 ) ;
V_24 |= 1 << ( V_21 % 32 ) ;
F_2 ( V_24 , V_23 ) ;
}
static void F_13 ( struct V_17 * V_18 )
{
F_11 ( V_18 -> V_21 ) ;
F_14 ( V_18 ) ;
}
static void F_15 ( struct V_17 * V_18 )
{
F_12 ( V_18 -> V_21 ) ;
F_16 ( V_18 ) ;
}
static int F_17 ( struct V_25 * V_18 ,
struct V_26 * V_27 ,
unsigned long * V_21 ,
unsigned int * type )
{
if ( F_18 ( V_27 -> V_28 ) ) {
if ( V_27 -> V_29 != 3 )
return - V_30 ;
if ( V_27 -> V_31 [ 0 ] != 0 )
return - V_30 ;
* V_21 = V_27 -> V_31 [ 1 ] ;
* type = V_27 -> V_31 [ 2 ] ;
return 0 ;
}
return - V_30 ;
}
static int F_19 ( struct V_25 * V_32 ,
unsigned int V_33 ,
unsigned int V_34 , void * V_35 )
{
struct V_26 * V_27 = V_35 ;
struct V_26 V_36 ;
T_3 V_21 ;
int V_13 ;
if ( V_27 -> V_29 != 3 )
return - V_30 ;
if ( V_27 -> V_31 [ 0 ] != 0 )
return - V_30 ;
V_21 = V_27 -> V_31 [ 1 ] ;
if ( V_21 >= V_37 )
return - V_30 ;
for ( V_13 = 0 ; V_13 < V_34 ; V_13 ++ )
F_20 ( V_32 , V_33 + V_13 , V_21 + V_13 ,
& V_38 , NULL ) ;
V_36 = * V_27 ;
V_36 . V_28 = V_32 -> V_39 -> V_28 ;
return F_21 ( V_32 , V_33 , V_34 ,
& V_36 ) ;
}
static int T_4 F_22 ( struct V_40 * V_41 ,
struct V_40 * V_39 )
{
struct V_25 * V_42 , * V_32 ;
int V_13 ;
if ( ! V_39 ) {
F_23 ( L_1 , V_41 -> V_43 ) ;
return - V_44 ;
}
V_42 = F_24 ( V_39 ) ;
if ( ! V_42 ) {
F_23 ( L_2 , V_41 -> V_43 ) ;
return - V_45 ;
}
V_5 = F_25 ( V_41 , 0 ) ;
if ( F_26 ( ! V_5 ) )
return - V_46 ;
V_32 = F_27 ( V_42 , 0 , V_37 ,
V_41 , & V_47 ,
NULL ) ;
if ( ! V_32 ) {
F_28 ( V_5 ) ;
return - V_46 ;
}
for ( V_13 = 0 ; V_13 < V_14 ; V_13 ++ )
F_2 ( ~ 0 , V_5 + V_12 + V_13 * 4 ) ;
F_29 ( V_41 , V_48 ) ;
return 0 ;
}
void T_4 F_30 ( void )
{
struct V_40 * V_49 ;
V_49 = F_31 ( NULL , NULL , L_3 ) ;
if ( F_26 ( ! V_49 ) )
return;
if ( F_26 ( ! F_32 ( V_49 , L_4 , NULL ) ) ) {
F_33 ( L_5 ) ;
V_5 = F_25 ( V_49 , 0 ) ;
}
}
