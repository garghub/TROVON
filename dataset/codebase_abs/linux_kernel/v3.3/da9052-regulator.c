static int F_1 ( struct V_1 * V_2 ,
int V_3 , int V_4 )
{
if ( V_3 > V_2 -> V_4 || V_4 < V_2 -> V_3 )
return - V_5 ;
return 0 ;
}
static int F_2 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = F_3 ( V_7 ) ;
struct V_1 * V_2 = V_9 -> V_2 ;
int V_10 = F_4 ( V_7 ) ;
return F_5 ( V_9 -> V_11 ,
V_12 + V_10 ,
1 << V_2 -> V_13 , 1 << V_2 -> V_13 ) ;
}
static int F_6 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = F_3 ( V_7 ) ;
struct V_1 * V_2 = V_9 -> V_2 ;
int V_10 = F_4 ( V_7 ) ;
return F_5 ( V_9 -> V_11 ,
V_12 + V_10 ,
1 << V_2 -> V_13 , 0 ) ;
}
static int F_7 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = F_3 ( V_7 ) ;
struct V_1 * V_2 = V_9 -> V_2 ;
int V_10 = F_4 ( V_7 ) ;
int V_14 ;
V_14 = F_8 ( V_9 -> V_11 , V_12 + V_10 ) ;
if ( V_14 < 0 )
return V_14 ;
return V_14 & ( 1 << V_2 -> V_13 ) ;
}
static int F_9 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = F_3 ( V_7 ) ;
int V_10 = F_4 ( V_7 ) ;
int V_14 , V_15 = 2 ;
V_14 = F_8 ( V_9 -> V_11 , V_16 + V_10 / 2 ) ;
if ( V_14 < 0 )
return V_14 ;
if ( V_10 % 2 == 0 )
V_14 = ( V_14 & V_17 ) >> 2 ;
else
V_14 = ( V_14 & V_18 ) >> 6 ;
if ( V_9 -> V_11 -> V_19 == V_20 )
V_15 = 0 ;
else if ( V_10 == 0 )
V_15 = 1 ;
return V_21 [ V_15 ] [ V_14 ] ;
}
static int F_10 ( struct V_6 * V_7 , int V_22 ,
int V_23 )
{
struct V_8 * V_9 = F_3 ( V_7 ) ;
int V_10 = F_4 ( V_7 ) ;
int V_24 = 0 ;
int V_25 , V_15 = 2 ;
if ( V_9 -> V_11 -> V_19 == V_20 )
V_15 = 0 ;
else if ( V_10 == 0 )
V_15 = 1 ;
if ( V_22 > V_21 [ V_15 ] [ V_26 ] ||
V_23 < V_21 [ V_15 ] [ V_27 ] )
return - V_5 ;
for ( V_25 = 0 ; V_25 < V_28 ; V_25 ++ ) {
if ( V_22 <= V_21 [ V_15 ] [ V_25 ] ) {
V_24 = V_25 ;
break;
}
}
if ( V_10 % 2 == 0 )
return F_5 ( V_9 -> V_11 ,
V_16 + V_10 / 2 ,
V_17 ,
V_24 << 2 ) ;
else
return F_5 ( V_9 -> V_11 ,
V_16 + V_10 / 2 ,
V_18 ,
V_24 << 6 ) ;
}
static int F_11 ( struct V_6 * V_7 ,
unsigned int V_29 )
{
struct V_8 * V_9 = F_3 ( V_7 ) ;
struct V_1 * V_2 = V_9 -> V_2 ;
int V_30 ;
if ( ( V_9 -> V_11 -> V_19 == V_20 ) &&
( V_29 >= V_31 ) ) {
V_30 = ( ( V_31 * V_2 -> V_32 )
+ V_2 -> V_3 ) ;
V_30 += ( V_29 - V_31 )
* ( V_33 ) ;
} else
V_30 = ( V_29 * V_2 -> V_32 ) + V_2 -> V_3 ;
if ( V_30 > V_2 -> V_4 )
return - V_5 ;
return V_30 ;
}
static int F_12 ( struct V_6 * V_7 ,
unsigned int V_29 )
{
struct V_8 * V_9 = F_3 ( V_7 ) ;
struct V_1 * V_2 = V_9 -> V_2 ;
int V_30 ;
V_30 = V_2 -> V_3 + V_2 -> V_32 * V_29 ;
if ( V_30 > V_2 -> V_4 )
return - V_5 ;
return V_30 ;
}
static int F_13 ( struct V_6 * V_7 ,
int V_3 , int V_4 ,
unsigned int * V_29 )
{
struct V_8 * V_9 = F_3 ( V_7 ) ;
struct V_1 * V_2 = V_9 -> V_2 ;
int V_10 = F_4 ( V_7 ) ;
int V_14 ;
V_14 = F_1 ( V_2 , V_3 , V_4 ) ;
if ( V_14 < 0 )
return V_14 ;
if ( V_3 < V_2 -> V_3 )
V_3 = V_2 -> V_3 ;
* V_29 = F_14 ( V_3 - V_2 -> V_3 , V_2 -> V_32 ) ;
V_14 = F_12 ( V_7 , * V_29 ) ;
if ( V_14 < 0 )
return V_14 ;
return F_5 ( V_9 -> V_11 ,
V_12 + V_10 ,
( 1 << V_2 -> V_34 ) - 1 , * V_29 ) ;
}
static int F_15 ( struct V_6 * V_7 ,
int V_3 , int V_4 ,
unsigned int * V_29 )
{
return F_13 ( V_7 , V_3 , V_4 , V_29 ) ;
}
static int F_16 ( struct V_6 * V_7 ,
int V_3 , int V_4 ,
unsigned int * V_29 )
{
struct V_8 * V_9 = F_3 ( V_7 ) ;
struct V_1 * V_2 = V_9 -> V_2 ;
int V_14 ;
V_14 = F_13 ( V_7 , V_3 , V_4 , V_29 ) ;
if ( V_14 < 0 )
return V_14 ;
return F_5 ( V_9 -> V_11 , V_35 ,
V_2 -> V_36 , V_2 -> V_36 ) ;
}
static int F_17 ( struct V_6 * V_7 ,
int V_3 , int V_4 ,
unsigned int * V_29 )
{
struct V_8 * V_9 = F_3 ( V_7 ) ;
struct V_1 * V_2 = V_9 -> V_2 ;
int V_14 ;
V_14 = F_13 ( V_7 , V_3 , V_4 , V_29 ) ;
if ( V_14 < 0 )
return V_14 ;
return F_5 ( V_9 -> V_11 , V_35 ,
V_2 -> V_36 , V_2 -> V_36 ) ;
}
static int F_18 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = F_3 ( V_7 ) ;
struct V_1 * V_2 = V_9 -> V_2 ;
int V_10 = F_4 ( V_7 ) ;
int V_14 ;
V_14 = F_8 ( V_9 -> V_11 , V_12 + V_10 ) ;
if ( V_14 < 0 )
return V_14 ;
V_14 &= ( ( 1 << V_2 -> V_34 ) - 1 ) ;
return V_14 ;
}
static int F_19 ( struct V_6 * V_7 , int V_3 ,
int V_4 , unsigned int * V_29 )
{
struct V_8 * V_9 = F_3 ( V_7 ) ;
struct V_1 * V_2 = V_9 -> V_2 ;
int V_10 = F_4 ( V_7 ) ;
int V_14 ;
V_14 = F_1 ( V_2 , V_3 , V_4 ) ;
if ( V_14 < 0 )
return V_14 ;
if ( V_3 < V_2 -> V_3 )
V_3 = V_2 -> V_3 ;
if ( ( V_9 -> V_11 -> V_19 == V_20 ) &&
( V_3 >= V_37 ) )
* V_29 = V_31 +
F_14 ( V_3 - V_37 ,
V_33 ) ;
else
* V_29 = F_14 ( V_3 - V_2 -> V_3 , V_2 -> V_32 ) ;
V_14 = F_11 ( V_7 , * V_29 ) ;
if ( V_14 < 0 )
return V_14 ;
return F_5 ( V_9 -> V_11 ,
V_12 + V_10 ,
( 1 << V_2 -> V_34 ) - 1 , * V_29 ) ;
}
static int F_20 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = F_3 ( V_7 ) ;
struct V_1 * V_2 = V_9 -> V_2 ;
int V_10 = F_4 ( V_7 ) ;
int V_14 ;
V_14 = F_8 ( V_9 -> V_11 , V_12 + V_10 ) ;
if ( V_14 < 0 )
return V_14 ;
V_14 &= ( ( 1 << V_2 -> V_34 ) - 1 ) ;
return V_14 ;
}
static inline struct V_1 * F_21 ( T_1 V_19 ,
int V_38 )
{
struct V_1 * V_2 ;
int V_25 ;
switch ( V_19 ) {
case V_20 :
for ( V_25 = 0 ; V_25 < F_22 ( V_1 ) ; V_25 ++ ) {
V_2 = & V_1 [ V_25 ] ;
if ( V_2 -> V_39 . V_38 == V_38 )
return V_2 ;
}
break;
case V_40 :
case V_41 :
case V_42 :
for ( V_25 = 0 ; V_25 < F_22 ( V_43 ) ; V_25 ++ ) {
V_2 = & V_43 [ V_25 ] ;
if ( V_2 -> V_39 . V_38 == V_38 )
return V_2 ;
}
break;
}
return NULL ;
}
static int T_2 F_23 ( struct V_44 * V_45 )
{
struct V_8 * V_9 ;
struct V_11 * V_11 ;
struct V_46 * V_47 ;
int V_14 ;
V_9 = F_24 ( & V_45 -> V_48 , sizeof( struct V_8 ) ,
V_49 ) ;
if ( ! V_9 )
return - V_50 ;
V_11 = F_25 ( V_45 -> V_48 . V_51 ) ;
V_47 = V_11 -> V_48 -> V_52 ;
V_9 -> V_11 = V_11 ;
V_9 -> V_2 = F_21 ( V_9 -> V_11 -> V_19 ,
V_45 -> V_38 ) ;
if ( V_9 -> V_2 == NULL ) {
F_26 ( & V_45 -> V_48 , L_1 ) ;
V_14 = - V_5 ;
goto V_53;
}
V_9 -> V_7 = F_27 ( & V_9 -> V_2 -> V_39 ,
& V_45 -> V_48 ,
V_47 -> V_54 [ V_45 -> V_38 ] ,
V_9 , NULL ) ;
if ( F_28 ( V_9 -> V_7 ) ) {
F_26 ( & V_45 -> V_48 , L_2 ,
V_9 -> V_2 -> V_39 . V_55 ) ;
V_14 = F_29 ( V_9 -> V_7 ) ;
goto V_53;
}
F_30 ( V_45 , V_9 ) ;
return 0 ;
V_53:
F_31 ( & V_45 -> V_48 , V_9 ) ;
return V_14 ;
}
static int T_3 F_32 ( struct V_44 * V_45 )
{
struct V_8 * V_9 = F_33 ( V_45 ) ;
F_34 ( V_9 -> V_7 ) ;
F_31 ( & V_45 -> V_48 , V_9 ) ;
return 0 ;
}
static int T_4 F_35 ( void )
{
return F_36 ( & V_56 ) ;
}
static void T_5 F_37 ( void )
{
F_38 ( & V_56 ) ;
}
