static void F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_2 = F_2 ( V_1 ) ;
F_3 ( & V_2 -> V_3 ) ;
}
static void F_4 ( struct V_1 * V_1 )
{
struct V_2 * V_2 = F_2 ( V_1 ) ;
unsigned int V_4 = V_1 -> V_5 - V_2 -> V_6 ;
const struct V_7 * V_8 = & V_9 [ V_4 ] ;
V_2 -> V_10 [ V_8 -> V_11 ] |= 1 << V_8 -> V_11 ;
V_2 -> V_12 |= 1 << V_8 -> V_13 ;
V_2 -> V_14 [ V_8 -> V_15 ] |= 1 << V_8 -> V_16 ;
}
static void F_5 ( struct V_1 * V_1 )
{
struct V_2 * V_2 = F_2 ( V_1 ) ;
unsigned int V_4 = V_1 -> V_5 - V_2 -> V_6 ;
const struct V_7 * V_8 = & V_9 [ V_4 ] ;
V_2 -> V_10 [ V_8 -> V_11 ] &= ~ ( 1 << V_8 -> V_11 ) ;
if ( ! V_2 -> V_10 [ V_8 -> V_11 ] )
V_2 -> V_12 &= ~ ( 1 << V_8 -> V_13 ) ;
V_2 -> V_14 [ V_8 -> V_15 ] &= ~ ( 1 << V_8 -> V_16 ) ;
}
static int F_6 ( struct V_1 * V_1 , unsigned int type )
{
struct V_2 * V_2 = F_2 ( V_1 ) ;
unsigned int V_4 = V_1 -> V_5 - V_2 -> V_6 ;
const struct V_7 * V_8 = & V_9 [ V_4 ] ;
int V_17 = 0 ;
int V_18 ;
int V_19 ;
if ( ( V_8 -> V_20 & V_21 ) && ( type & V_22 ) ) {
V_18 = V_8 -> V_16 / 4 ;
V_19 = V_8 -> V_16 % 4 ;
if ( type & V_23 )
V_17 |= 0x2 ;
if ( type & V_24 )
V_17 |= 0x1 ;
V_2 -> V_25 [ V_18 ] &= ~ ( 3 << V_19 ) ;
V_2 -> V_25 [ V_18 ] |= ( V_17 << V_19 ) ;
F_4 ( V_1 ) ;
return 0 ;
}
return - V_26 ;
}
static void F_7 ( struct V_1 * V_1 )
{
struct V_2 * V_2 = F_2 ( V_1 ) ;
int V_27 ;
int V_28 ;
for ( V_27 = 0 ; V_27 < F_8 ( V_2 -> V_25 ) ; V_27 ++ ) {
V_28 = F_9 ( V_2 -> V_29 , V_30 [ V_27 ] ,
V_2 -> V_25 [ V_27 ] ) ;
if ( V_28 < 0 )
F_10 ( V_2 -> V_29 ,
L_1 ,
V_30 [ V_27 ] , V_28 ) ;
}
for ( V_27 = 0 ; V_27 < F_8 ( V_2 -> V_14 ) ; V_27 ++ ) {
V_28 = F_9 ( V_2 -> V_29 , V_31 [ V_27 ] ,
V_2 -> V_14 [ V_27 ] ) ;
if ( V_28 < 0 )
F_10 ( V_2 -> V_29 ,
L_1 ,
V_31 [ V_27 ] , V_28 ) ;
}
V_28 = F_9 ( V_2 -> V_29 , V_32 ,
V_2 -> V_12 ) ;
if ( V_28 < 0 )
F_10 ( V_2 -> V_29 ,
L_1 ,
V_32 , V_28 ) ;
F_11 ( & V_2 -> V_3 ) ;
}
static int F_12 ( struct V_1 * V_1 , unsigned int V_33 )
{
struct V_2 * V_2 = F_2 ( V_1 ) ;
return F_13 ( V_2 -> V_34 , V_33 ) ;
}
static T_1 F_14 ( int V_5 , void * V_8 )
{
struct V_2 * V_2 = V_8 ;
T_2 V_35 [ V_36 ] ;
T_2 V_37 = 0 ;
int V_27 ;
int V_28 ;
unsigned int V_38 = 0 ;
for ( V_27 = 0 ; V_27 < V_36 ; V_27 ++ )
V_35 [ V_27 ] = 0 ;
V_28 = F_15 ( V_2 -> V_29 , V_39 , & V_37 ) ;
if ( V_28 < 0 ) {
F_16 ( V_2 -> V_29 ,
L_2 ,
V_39 , V_28 ) ;
return V_40 ;
}
for ( V_27 = 0 ; V_27 < V_36 ; ++ V_27 ) {
if ( ! ( V_37 & V_41 [ V_27 ] ) )
continue;
V_28 = F_15 ( V_2 -> V_29 , V_42 [ V_27 ] , & V_35 [ V_27 ] ) ;
if ( V_28 < 0 ) {
F_10 ( V_2 -> V_29 ,
L_2 ,
V_42 [ V_27 ] , V_28 ) ;
V_35 [ V_27 ] = 0 ;
continue;
}
if ( V_41 [ V_27 ] & V_43 ) {
V_38 = 0 ;
if ( V_35 [ V_27 ] & 0x1 )
V_38 |= F_17 ( 6 ) ;
if ( V_35 [ V_27 ] & 0x2 )
V_38 |= F_17 ( 7 ) ;
if ( V_35 [ V_27 ] & 0x4 )
V_38 |= F_17 ( 0 ) ;
if ( V_35 [ V_27 ] & 0x8 )
V_38 |= F_17 ( 5 ) ;
}
V_28 = F_9 ( V_2 -> V_29 , V_44 [ V_27 ] ,
~ V_35 [ V_27 ] ) ;
if ( V_28 < 0 )
F_10 ( V_2 -> V_29 ,
L_2 ,
V_44 [ V_27 ] , V_28 ) ;
if ( V_41 [ V_27 ] & V_43 )
V_35 [ V_27 ] = V_38 ;
}
V_35 [ 7 ] |= V_35 [ 8 ] ;
for ( V_27 = 0 ; V_27 < V_45 ; ++ V_27 ) {
const struct V_7 * V_8 = & V_9 [ V_27 ] ;
if ( ( V_35 [ V_8 -> V_15 ] & ( 1 << V_8 -> V_16 ) ) &&
( V_2 -> V_10 [ V_8 -> V_13 ] &
( 1 << V_8 -> V_11 ) ) )
F_18 ( V_2 -> V_6 + V_27 ) ;
}
return V_40 ;
}
int F_19 ( struct V_2 * V_2 , int V_5 , int V_6 )
{
int V_27 , V_28 ;
if ( ! V_6 ) {
F_10 ( V_2 -> V_29 , L_3 ) ;
return - V_26 ;
}
F_20 ( & V_2 -> V_3 ) ;
for ( V_27 = 0 ; V_27 < V_46 ; V_27 ++ ) {
V_28 = F_9 ( V_2 -> V_29 , V_31 [ V_27 ] ,
V_2 -> V_14 [ V_27 ] ) ;
if ( V_28 < 0 )
F_10 ( V_2 -> V_29 ,
L_1 ,
V_31 [ V_27 ] , V_28 ) ;
}
for ( V_27 = 0 ; V_27 < V_47 ; V_27 ++ ) {
V_28 = F_9 ( V_2 -> V_29 , V_30 [ V_27 ] ,
V_2 -> V_25 [ V_27 ] ) ;
if ( V_28 < 0 )
F_10 ( V_2 -> V_29 ,
L_1 ,
V_30 [ V_27 ] , V_28 ) ;
}
V_28 = F_9 ( V_2 -> V_29 , V_32 , 0x0 ) ;
if ( V_28 < 0 )
F_10 ( V_2 -> V_29 ,
L_1 ,
V_32 , V_28 ) ;
for ( V_27 = 0 ; V_27 < V_36 ; V_27 ++ ) {
V_28 = F_9 ( V_2 -> V_29 , V_44 [ V_27 ] , 0 ) ;
if ( V_28 < 0 )
F_10 ( V_2 -> V_29 ,
L_1 ,
V_44 [ V_27 ] , V_28 ) ;
}
V_2 -> V_6 = V_6 ;
V_2 -> V_34 = V_5 ;
for ( V_27 = 0 ; V_27 < V_45 ; V_27 ++ ) {
int V_4 = V_27 + V_2 -> V_6 ;
F_21 ( V_4 , V_2 ) ;
F_22 ( V_4 , & V_48 ,
V_49 ) ;
F_23 ( V_4 , 1 ) ;
F_24 ( V_4 , V_50 ) ;
}
V_28 = F_25 ( V_5 , NULL , F_14 , V_51 ,
L_4 , V_2 ) ;
if ( V_28 < 0 )
F_16 ( V_2 -> V_29 ,
L_5 , V_28 ) ;
return V_28 ;
}
int F_26 ( struct V_2 * V_2 )
{
if ( V_2 -> V_34 )
F_27 ( V_2 -> V_34 , V_2 ) ;
return 0 ;
}
