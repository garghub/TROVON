static int F_1 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_6 = - V_7 ;
if ( V_5 -> V_8 && ( V_3 < ( 1 << V_5 -> V_9 ) ) ) {
V_6 = V_5 -> V_8 [ V_3 ] ;
if ( V_5 -> V_10 )
V_6 <<= 1 ;
}
return V_6 ;
}
static int F_3 ( struct V_1 * V_2 , int V_11 , int V_12 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_13 , V_6 = - V_14 ;
if ( V_5 -> V_10 ) {
V_11 = V_11 >> 1 ;
V_12 = V_12 >> 1 ;
}
if ( V_5 -> V_8 ) {
for ( V_13 = 0 ; V_13 < ( 1 << V_5 -> V_9 ) ; V_13 ++ ) {
if ( ! V_5 -> V_8 [ V_13 ] )
break;
if ( ( V_11 <= V_5 -> V_8 [ V_13 ] )
&& ( V_12 >= V_5 -> V_8 [ V_13 ] ) ) {
V_6 = V_13 ;
break;
}
}
}
if ( V_6 < 0 )
F_4 ( L_1 , V_11 , V_12 ) ;
return V_6 ;
}
static int F_5 ( struct V_1 * V_2 ,
int V_11 , int V_12 , unsigned * V_15 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_1 V_16 , V_17 ;
int V_6 ;
if ( V_11 > V_12 ) {
F_4 ( L_2 , V_11 , V_12 ) ;
return - V_7 ;
}
V_6 = F_3 ( V_2 , V_11 , V_12 ) ;
if ( V_6 < 0 )
return - V_7 ;
* V_15 = V_6 ;
V_16 = ( T_1 ) ( V_6 << V_5 -> V_18 ) ;
V_17 = ( ( 1 << V_5 -> V_9 ) - 1 ) << V_5 -> V_18 ;
V_6 = F_6 ( V_5 -> V_19 , V_5 -> V_20 , V_17 , V_16 ) ;
if ( V_6 )
return V_6 ;
switch ( V_5 -> V_21 . V_22 ) {
case V_23 :
case V_24 :
V_6 = F_6 ( V_5 -> V_19 , V_5 -> V_25 ,
1 << V_5 -> V_26 ,
1 << V_5 -> V_26 ) ;
break;
}
return V_6 ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_1 V_16 , V_17 ;
int V_6 ;
V_6 = F_8 ( V_5 -> V_19 , V_5 -> V_20 ) ;
if ( V_6 < 0 )
return V_6 ;
V_17 = ( ( 1 << V_5 -> V_9 ) - 1 ) << V_5 -> V_18 ;
V_16 = ( ( unsigned char ) V_6 & V_17 ) >> V_5 -> V_18 ;
return F_1 ( V_2 , V_16 ) ;
}
static int F_9 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
return F_6 ( V_5 -> V_19 , V_5 -> V_27 ,
1 << V_5 -> V_28 ,
1 << V_5 -> V_28 ) ;
}
static int F_10 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
return F_6 ( V_5 -> V_19 , V_5 -> V_27 ,
1 << V_5 -> V_28 , 0 ) ;
}
static int F_11 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_6 ;
V_6 = F_8 ( V_5 -> V_19 , V_5 -> V_27 ) ;
if ( V_6 < 0 )
return V_6 ;
return ! ! ( ( unsigned char ) V_6 & ( 1 << V_5 -> V_28 ) ) ;
}
static int T_2 F_12 ( struct V_29 * V_30 )
{
struct V_31 * V_32 = F_13 ( V_30 -> V_33 . V_34 ) ;
struct V_4 * V_5 = NULL ;
struct V_35 * V_36 = V_30 -> V_33 . V_37 ;
struct V_38 * V_39 ;
int V_13 ;
V_39 = F_14 ( V_30 , V_40 , 0 ) ;
if ( V_39 == NULL ) {
F_15 ( & V_30 -> V_33 , L_3 ) ;
return - V_7 ;
}
for ( V_13 = 0 ; V_13 < F_16 ( V_4 ) ; V_13 ++ ) {
V_5 = & V_4 [ V_13 ] ;
if ( V_5 -> V_21 . V_22 == V_39 -> V_41 )
break;
}
if ( V_13 == F_16 ( V_4 ) ) {
F_15 ( & V_30 -> V_33 , L_4 ,
( unsigned long long ) V_39 -> V_41 ) ;
return - V_7 ;
}
V_5 -> V_19 = ( V_32 -> V_22 == V_42 ) ? V_32 -> V_43 : V_32 -> V_44 ;
V_5 -> V_32 = V_32 ;
if ( ( V_13 == V_24 ) && V_5 -> V_32 -> V_45 )
V_5 -> V_10 = 1 ;
V_5 -> V_46 = F_17 ( & V_5 -> V_21 , & V_30 -> V_33 ,
V_36 , V_5 , NULL ) ;
if ( F_18 ( V_5 -> V_46 ) ) {
F_15 ( & V_30 -> V_33 , L_5 ,
V_5 -> V_21 . V_47 ) ;
return F_19 ( V_5 -> V_46 ) ;
}
F_20 ( V_30 , V_5 ) ;
return 0 ;
}
static int T_3 F_21 ( struct V_29 * V_30 )
{
struct V_4 * V_5 = F_22 ( V_30 ) ;
F_20 ( V_30 , NULL ) ;
F_23 ( V_5 -> V_46 ) ;
return 0 ;
}
static int T_4 F_24 ( void )
{
return F_25 ( & V_48 ) ;
}
static void T_5 F_26 ( void )
{
F_27 ( & V_48 ) ;
}
