static inline T_1 F_1 ( int V_1 )
{
return F_2 ( V_2 + V_1 ) ;
}
static inline void F_3 ( int V_1 , T_1 V_3 )
{
F_4 ( V_2 + V_1 , V_3 ) ;
}
static inline unsigned int F_5 ( unsigned int V_4 )
{
T_1 V_5 ;
unsigned long V_6 ;
int V_7 ;
for ( V_7 = 0 ; V_7 < 3 ; V_7 ++ ) {
if ( V_4 == V_8 [ V_7 ] )
break;
}
if ( V_7 == 3 )
return V_9 ;
F_6 ( & V_10 , V_6 ) ;
V_5 = F_1 ( F_7 ( V_7 ) ) ;
F_8 ( & V_10 , V_6 ) ;
for ( V_7 = V_11 - 1 ; V_7 >= 0 ; V_7 -- ) {
if ( V_5 >> ( V_7 + 16 ) )
break;
}
return F_9 ( V_12 ,
( V_13 ) V_7 ) ;
}
void F_10 ( unsigned int V_4 , struct V_14 * V_15 )
{
struct V_16 * V_17 = F_11 ( V_15 ) ;
unsigned int V_18 ;
V_18 = F_5 ( V_4 ) ;
if ( V_18 != V_9 )
F_12 ( V_18 ) ;
V_17 -> V_19 ( & V_15 -> V_20 ) ;
}
static void F_13 ( struct V_20 * V_21 )
{
unsigned long V_6 ;
unsigned int V_22 , V_23 = F_14 ( V_21 ) ;
T_1 V_24 ;
V_22 = V_25 [ V_23 ] . V_22 ;
F_6 ( & V_10 , V_6 ) ;
V_24 = F_1 ( F_7 ( V_22 ) )
& V_26 ;
V_24 |= ( 1 << ( V_23 + 16 ) ) ;
F_3 ( F_7 ( V_22 ) , V_24 ) ;
F_8 ( & V_10 , V_6 ) ;
}
static void F_15 ( struct V_20 * V_21 )
{
unsigned long V_6 ;
unsigned int V_23 = F_14 ( V_21 ) ;
int V_22 ;
T_2 V_24 ;
V_22 = V_25 [ V_23 ] . V_22 ;
F_6 ( & V_10 , V_6 ) ;
V_24 = F_1 ( F_7 ( V_22 ) )
& V_26 ;
V_24 &= ~ ( 1 << V_23 ) ;
F_3 ( F_7 ( V_22 ) , V_24 ) ;
F_8 ( & V_10 , V_6 ) ;
}
static void F_16 ( struct V_20 * V_21 )
{
unsigned long V_6 ;
unsigned int V_23 = F_14 ( V_21 ) ;
int V_22 ;
T_2 V_24 ;
V_22 = V_25 [ V_23 ] . V_22 ;
F_6 ( & V_10 , V_6 ) ;
V_24 = F_1 ( F_7 ( V_22 ) )
& V_26 ;
V_24 &= ~ ( 1 << V_23 ) ;
V_24 |= ( 1 << ( V_23 + 16 ) ) ;
F_3 ( F_7 ( V_22 ) , V_24 ) ;
F_8 ( & V_10 , V_6 ) ;
}
static void F_17 ( struct V_20 * V_21 )
{
unsigned long V_6 ;
unsigned int V_23 = F_14 ( V_21 ) ;
int V_22 ;
T_2 V_24 ;
V_22 = V_25 [ V_23 ] . V_22 ;
F_6 ( & V_10 , V_6 ) ;
V_24 = F_1 ( F_7 ( V_22 ) )
& V_26 ;
V_24 |= ( 1 << V_23 ) ;
F_3 ( F_7 ( V_22 ) , V_24 ) ;
F_8 ( & V_10 , V_6 ) ;
}
static void F_18 ( struct V_20 * V_21 )
{
unsigned long V_6 ;
unsigned int V_23 = F_14 ( V_21 ) ;
int V_22 ;
T_2 V_24 ;
V_22 = V_25 [ V_23 ] . V_22 ;
F_6 ( & V_10 , V_6 ) ;
V_24 = F_1 ( F_7 ( V_22 ) )
& V_26 ;
V_24 |= ( 1 << ( V_23 + 16 ) ) ;
F_3 ( F_7 ( V_22 ) , V_24 ) ;
F_8 ( & V_10 , V_6 ) ;
}
static int F_19 ( struct V_20 * V_21 ,
unsigned int V_27 )
{
unsigned long V_6 ;
unsigned int V_23 = F_14 ( V_21 ) ;
int V_28 ;
T_2 V_24 ;
if ( V_25 [ V_23 ] . type != V_29 )
return - V_30 ;
switch ( V_27 & V_31 ) {
case V_32 :
V_28 = 1 ;
break;
case V_33 :
V_28 = 0 ;
break;
default:
return - V_30 ;
}
F_6 ( & V_10 , V_6 ) ;
V_24 = F_1 ( V_34 ) ;
if ( V_28 )
V_24 |= ( 1 << V_23 ) ;
else
V_24 &= ~ ( 1 << V_23 ) ;
F_3 ( V_34 , V_24 ) ;
F_8 ( & V_10 , V_6 ) ;
return 0 ;
}
static int F_20 ( struct V_35 * V_36 , unsigned int V_37 ,
V_13 V_23 )
{
F_21 ( V_37 , V_38 ) ;
F_22 ( V_37 , & V_39 ,
V_40 ) ;
return 0 ;
}
static int F_23 ( struct V_35 * V_36 ,
struct V_41 * V_42 , const T_2 * V_43 , unsigned int V_44 ,
V_13 * V_45 , unsigned int * V_46 )
{
struct V_47 * V_48 = & V_25 [ V_43 [ 0 ] ] ;
* V_45 = V_43 [ 0 ] ;
if ( V_48 -> type == V_29 ) {
if ( V_43 [ 1 ] != V_33 &&
V_43 [ 1 ] != V_32 ) {
F_24 ( L_1
L_2 ) ;
* V_46 = V_33 ;
} else {
* V_46 = V_43 [ 1 ] ;
}
} else {
* V_46 = V_48 -> type ;
}
if ( V_43 [ 2 ] <= 2 )
V_48 -> V_22 = V_43 [ 2 ] ;
else
F_24 ( L_3 ) ;
return 0 ;
}
void F_25 ( struct V_41 * V_49 )
{
unsigned long V_6 ;
int V_7 ;
V_12 = F_26 ( V_49 , V_50 ,
V_11 , & V_51 ,
V_11 ) ;
if ( V_12 == NULL ) {
F_27 ( L_4 ) ;
return;
}
for ( V_7 = 0 ; V_7 < 3 ; V_7 ++ ) {
V_8 [ V_7 ] = F_28 ( V_49 , V_7 ) ;
if ( V_8 [ V_7 ] == V_9 ) {
F_24 ( L_5 , V_7 ) ;
continue;
}
F_29 ( V_8 [ V_7 ] ,
F_10 ) ;
}
V_2 = F_30 ( V_49 , 0 ) ;
F_6 ( & V_10 , V_6 ) ;
F_3 ( F_7 ( 0 ) ,
V_26 << 16 ) ;
F_3 ( F_7 ( 1 ) ,
V_26 << 16 ) ;
F_3 ( F_7 ( 2 ) ,
V_26 << 16 ) ;
F_8 ( & V_10 , V_6 ) ;
F_31 ( L_6 ) ;
}
