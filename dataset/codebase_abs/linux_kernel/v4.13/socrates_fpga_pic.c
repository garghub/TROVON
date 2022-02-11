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
return 0 ;
F_6 ( & V_9 , V_6 ) ;
V_5 = F_1 ( F_7 ( V_7 ) ) ;
F_8 ( & V_9 , V_6 ) ;
for ( V_7 = V_10 - 1 ; V_7 >= 0 ; V_7 -- ) {
if ( V_5 >> ( V_7 + 16 ) )
break;
}
return F_9 ( V_11 ,
( V_12 ) V_7 ) ;
}
static void F_10 ( struct V_13 * V_14 )
{
struct V_15 * V_16 = F_11 ( V_14 ) ;
unsigned int V_4 = F_12 ( V_14 ) ;
unsigned int V_17 ;
V_17 = F_5 ( V_4 ) ;
if ( V_17 )
F_13 ( V_17 ) ;
V_16 -> V_18 ( & V_14 -> V_19 ) ;
}
static void F_14 ( struct V_19 * V_20 )
{
unsigned long V_6 ;
unsigned int V_21 , V_22 = F_15 ( V_20 ) ;
T_1 V_23 ;
V_21 = V_24 [ V_22 ] . V_21 ;
F_6 ( & V_9 , V_6 ) ;
V_23 = F_1 ( F_7 ( V_21 ) )
& V_25 ;
V_23 |= ( 1 << ( V_22 + 16 ) ) ;
F_3 ( F_7 ( V_21 ) , V_23 ) ;
F_8 ( & V_9 , V_6 ) ;
}
static void F_16 ( struct V_19 * V_20 )
{
unsigned long V_6 ;
unsigned int V_22 = F_15 ( V_20 ) ;
int V_21 ;
T_2 V_23 ;
V_21 = V_24 [ V_22 ] . V_21 ;
F_6 ( & V_9 , V_6 ) ;
V_23 = F_1 ( F_7 ( V_21 ) )
& V_25 ;
V_23 &= ~ ( 1 << V_22 ) ;
F_3 ( F_7 ( V_21 ) , V_23 ) ;
F_8 ( & V_9 , V_6 ) ;
}
static void F_17 ( struct V_19 * V_20 )
{
unsigned long V_6 ;
unsigned int V_22 = F_15 ( V_20 ) ;
int V_21 ;
T_2 V_23 ;
V_21 = V_24 [ V_22 ] . V_21 ;
F_6 ( & V_9 , V_6 ) ;
V_23 = F_1 ( F_7 ( V_21 ) )
& V_25 ;
V_23 &= ~ ( 1 << V_22 ) ;
V_23 |= ( 1 << ( V_22 + 16 ) ) ;
F_3 ( F_7 ( V_21 ) , V_23 ) ;
F_8 ( & V_9 , V_6 ) ;
}
static void F_18 ( struct V_19 * V_20 )
{
unsigned long V_6 ;
unsigned int V_22 = F_15 ( V_20 ) ;
int V_21 ;
T_2 V_23 ;
V_21 = V_24 [ V_22 ] . V_21 ;
F_6 ( & V_9 , V_6 ) ;
V_23 = F_1 ( F_7 ( V_21 ) )
& V_25 ;
V_23 |= ( 1 << V_22 ) ;
F_3 ( F_7 ( V_21 ) , V_23 ) ;
F_8 ( & V_9 , V_6 ) ;
}
static void F_19 ( struct V_19 * V_20 )
{
unsigned long V_6 ;
unsigned int V_22 = F_15 ( V_20 ) ;
int V_21 ;
T_2 V_23 ;
V_21 = V_24 [ V_22 ] . V_21 ;
F_6 ( & V_9 , V_6 ) ;
V_23 = F_1 ( F_7 ( V_21 ) )
& V_25 ;
V_23 |= ( 1 << ( V_22 + 16 ) ) ;
F_3 ( F_7 ( V_21 ) , V_23 ) ;
F_8 ( & V_9 , V_6 ) ;
}
static int F_20 ( struct V_19 * V_20 ,
unsigned int V_26 )
{
unsigned long V_6 ;
unsigned int V_22 = F_15 ( V_20 ) ;
int V_27 ;
T_2 V_23 ;
if ( V_24 [ V_22 ] . type != V_28 )
return - V_29 ;
switch ( V_26 & V_30 ) {
case V_31 :
V_27 = 1 ;
break;
case V_32 :
V_27 = 0 ;
break;
default:
return - V_29 ;
}
F_6 ( & V_9 , V_6 ) ;
V_23 = F_1 ( V_33 ) ;
if ( V_27 )
V_23 |= ( 1 << V_22 ) ;
else
V_23 &= ~ ( 1 << V_22 ) ;
F_3 ( V_33 , V_23 ) ;
F_8 ( & V_9 , V_6 ) ;
return 0 ;
}
static int F_21 ( struct V_34 * V_35 , unsigned int V_36 ,
V_12 V_22 )
{
F_22 ( V_36 , V_37 ) ;
F_23 ( V_36 , & V_38 ,
V_39 ) ;
return 0 ;
}
static int F_24 ( struct V_34 * V_35 ,
struct V_40 * V_41 , const T_2 * V_42 , unsigned int V_43 ,
V_12 * V_44 , unsigned int * V_45 )
{
struct V_46 * V_47 = & V_24 [ V_42 [ 0 ] ] ;
* V_44 = V_42 [ 0 ] ;
if ( V_47 -> type == V_28 ) {
if ( V_42 [ 1 ] != V_32 &&
V_42 [ 1 ] != V_31 ) {
F_25 ( L_1
L_2 ) ;
* V_45 = V_32 ;
} else {
* V_45 = V_42 [ 1 ] ;
}
} else {
* V_45 = V_47 -> type ;
}
if ( V_42 [ 2 ] <= 2 )
V_47 -> V_21 = V_42 [ 2 ] ;
else
F_25 ( L_3 ) ;
return 0 ;
}
void F_26 ( struct V_40 * V_48 )
{
unsigned long V_6 ;
int V_7 ;
V_11 = F_27 ( V_48 ,
V_10 , & V_49 , NULL ) ;
if ( V_11 == NULL ) {
F_28 ( L_4 ) ;
return;
}
for ( V_7 = 0 ; V_7 < 3 ; V_7 ++ ) {
V_8 [ V_7 ] = F_29 ( V_48 , V_7 ) ;
if ( ! V_8 [ V_7 ] ) {
F_25 ( L_5 , V_7 ) ;
continue;
}
F_30 ( V_8 [ V_7 ] ,
F_10 ) ;
}
V_2 = F_31 ( V_48 , 0 ) ;
F_6 ( & V_9 , V_6 ) ;
F_3 ( F_7 ( 0 ) ,
V_25 << 16 ) ;
F_3 ( F_7 ( 1 ) ,
V_25 << 16 ) ;
F_3 ( F_7 ( 2 ) ,
V_25 << 16 ) ;
F_8 ( & V_9 , V_6 ) ;
F_32 ( L_6 ) ;
}
