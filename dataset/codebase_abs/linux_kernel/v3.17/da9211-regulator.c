static unsigned int F_1 ( struct V_1 * V_2 )
{
int V_3 = F_2 ( V_2 ) ;
struct V_4 * V_5 = F_3 ( V_2 ) ;
unsigned int V_6 ;
int V_7 , V_8 = 0 ;
V_7 = F_4 ( V_5 -> V_9 , V_10 + V_3 , & V_6 ) ;
if ( V_7 < 0 )
return V_7 ;
switch ( V_6 & 0x03 ) {
case V_11 :
V_8 = V_12 ;
break;
case V_13 :
V_8 = V_14 ;
break;
case V_15 :
V_8 = V_16 ;
break;
}
return V_8 ;
}
static int F_5 ( struct V_1 * V_2 ,
unsigned int V_8 )
{
int V_3 = F_2 ( V_2 ) ;
struct V_4 * V_5 = F_3 ( V_2 ) ;
int V_17 = 0 ;
switch ( V_8 ) {
case V_12 :
V_17 = V_11 ;
break;
case V_14 :
V_17 = V_13 ;
break;
case V_16 :
V_17 = V_15 ;
break;
}
return F_6 ( V_5 -> V_9 , V_10 + V_3 ,
0x03 , V_17 ) ;
}
static int F_7 ( struct V_1 * V_2 , int V_18 ,
int V_19 )
{
int V_3 = F_2 ( V_2 ) ;
struct V_4 * V_5 = F_3 ( V_2 ) ;
int V_20 ;
for ( V_20 = F_8 ( V_21 ) - 1 ; V_20 >= 0 ; V_20 -- ) {
if ( V_18 <= V_21 [ V_20 ] &&
V_19 >= V_21 [ V_20 ] ) {
return F_6 ( V_5 -> V_9 ,
V_22 ,
( 0x0F << V_3 * 4 ) , ( V_20 << V_3 * 4 ) ) ;
}
}
return - V_23 ;
}
static int F_9 ( struct V_1 * V_2 )
{
int V_3 = F_2 ( V_2 ) ;
struct V_4 * V_5 = F_3 ( V_2 ) ;
unsigned int V_6 ;
int V_7 ;
V_7 = F_4 ( V_5 -> V_9 , V_22 , & V_6 ) ;
if ( V_7 < 0 )
return V_7 ;
V_6 = ( V_6 >> V_3 * 4 ) & 0x0F ;
return V_21 [ V_6 ] ;
}
static T_1 F_10 ( int V_24 , void * V_6 )
{
struct V_4 * V_5 = V_6 ;
int V_25 , V_26 , V_7 = V_27 ;
V_26 = F_4 ( V_5 -> V_9 , V_28 , & V_25 ) ;
if ( V_26 < 0 )
goto V_29;
if ( V_25 & V_30 ) {
F_11 ( V_5 -> V_2 [ 0 ] ,
V_31 ,
F_3 ( V_5 -> V_2 [ 0 ] ) ) ;
V_26 = F_12 ( V_5 -> V_9 , V_28 ,
V_30 ) ;
if ( V_26 < 0 )
goto V_29;
V_7 = V_32 ;
}
if ( V_25 & V_33 ) {
F_11 ( V_5 -> V_2 [ 1 ] ,
V_31 ,
F_3 ( V_5 -> V_2 [ 1 ] ) ) ;
V_26 = F_12 ( V_5 -> V_9 , V_28 ,
V_33 ) ;
if ( V_26 < 0 )
goto V_29;
V_7 = V_32 ;
}
return V_7 ;
V_29:
F_13 ( V_5 -> V_34 , L_1 , V_26 ) ;
return V_27 ;
}
static int F_14 ( struct V_4 * V_5 )
{
struct V_35 V_36 = { } ;
int V_20 , V_7 ;
unsigned int V_6 ;
V_7 = F_4 ( V_5 -> V_9 , V_37 , & V_6 ) ;
if ( V_7 < 0 ) {
F_13 ( V_5 -> V_34 , L_2 , V_7 ) ;
return V_7 ;
}
V_6 &= V_38 ;
if ( ( V_5 -> V_39 -> V_40 == 2 && V_6 == 0x40 )
|| ( V_5 -> V_39 -> V_40 == 1 && V_6 == 0x00 ) ) {
if ( V_6 == 0 )
V_5 -> V_41 = 1 ;
else
V_5 -> V_41 = 2 ;
} else {
F_13 ( V_5 -> V_34 , L_3 ) ;
return - V_23 ;
}
for ( V_20 = 0 ; V_20 < V_5 -> V_41 ; V_20 ++ ) {
if ( V_5 -> V_39 )
V_36 . V_42 =
& ( V_5 -> V_39 -> V_42 [ V_20 ] ) ;
V_36 . V_34 = V_5 -> V_34 ;
V_36 . V_43 = V_5 ;
V_36 . V_9 = V_5 -> V_9 ;
V_5 -> V_2 [ V_20 ] = F_15 ( V_5 -> V_34 ,
& V_44 [ V_20 ] , & V_36 ) ;
if ( F_16 ( V_5 -> V_2 [ V_20 ] ) ) {
F_13 ( V_5 -> V_34 ,
L_4 ) ;
return F_17 ( V_5 -> V_2 [ V_20 ] ) ;
}
if ( V_5 -> V_45 != 0 ) {
V_7 = F_6 ( V_5 -> V_9 ,
V_46 , V_47 << V_20 , 1 ) ;
if ( V_7 < 0 ) {
F_13 ( V_5 -> V_34 ,
L_5 , V_7 ) ;
return V_7 ;
}
}
}
return 0 ;
}
static int F_18 ( struct V_48 * V_49 ,
const struct V_50 * V_3 )
{
struct V_4 * V_5 ;
int error , V_7 ;
V_5 = F_19 ( & V_49 -> V_34 , sizeof( struct V_4 ) , V_51 ) ;
V_5 -> V_34 = & V_49 -> V_34 ;
V_5 -> V_9 = F_20 ( V_49 , & V_52 ) ;
if ( F_16 ( V_5 -> V_9 ) ) {
error = F_17 ( V_5 -> V_9 ) ;
F_13 ( & V_49 -> V_34 , L_6 ,
error ) ;
return error ;
}
F_21 ( V_49 , V_5 ) ;
V_5 -> V_39 = V_49 -> V_34 . V_53 ;
if ( ! V_5 -> V_39 ) {
F_13 ( & V_49 -> V_34 , L_7 ) ;
return - V_54 ;
}
V_5 -> V_45 = V_49 -> V_24 ;
if ( V_5 -> V_45 != 0 ) {
V_7 = F_22 ( V_5 -> V_34 , V_5 -> V_45 , NULL ,
F_10 ,
V_55 | V_56 ,
L_8 , V_5 ) ;
if ( V_7 != 0 ) {
F_13 ( V_5 -> V_34 , L_9 ,
V_5 -> V_45 ) ;
return V_7 ;
}
} else {
F_23 ( V_5 -> V_34 , L_10 ) ;
}
V_7 = F_14 ( V_5 ) ;
if ( V_7 < 0 )
F_13 ( & V_49 -> V_34 , L_11 , V_7 ) ;
return V_7 ;
}
