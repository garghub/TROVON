T_1 F_1 ( struct V_1 * V_2 , T_2 * V_3 , T_3 V_4 , T_3 V_5 )
{
struct V_6 * V_7 = & V_2 -> V_7 ;
if ( V_4 > V_7 -> V_4 )
V_4 = V_7 -> V_4 ;
if ( ! V_7 -> V_8 . V_9 )
return V_10 ;
return V_7 -> V_8 . V_9 ( V_2 , V_3 , V_4 , V_5 ) ;
}
T_1 F_2 ( struct V_1 * V_2 , T_2 * V_3 , T_3 V_4 , T_3 V_5 )
{
struct V_6 * V_7 = & V_2 -> V_7 ;
if ( V_4 > V_7 -> V_4 )
return V_10 ;
if ( ! V_7 -> V_8 . V_11 )
return V_10 ;
return V_7 -> V_8 . V_11 ( V_2 , V_3 , V_4 , V_5 ) ;
}
T_1 F_3 ( struct V_1 * V_2 , T_3 V_5 )
{
struct V_6 * V_7 = & V_2 -> V_7 ;
if ( ! V_7 -> V_8 . V_12 )
return V_10 ;
return V_7 -> V_8 . V_12 ( V_2 , V_5 ) ;
}
T_1 F_4 ( struct V_1 * V_2 , T_3 V_5 )
{
struct V_6 * V_7 = & V_2 -> V_7 ;
if ( ! V_7 -> V_8 . V_13 )
return V_10 ;
return V_7 -> V_8 . V_13 ( V_2 , V_5 ) ;
}
T_1 F_5 ( struct V_1 * V_2 , T_3 V_5 )
{
struct V_6 * V_7 = & V_2 -> V_7 ;
if ( ! V_7 -> V_8 . V_14 )
return V_10 ;
return V_7 -> V_8 . V_14 ( V_2 , V_5 ) ;
}
static T_1 F_6 ( struct V_1 * V_2 , T_3 V_5 )
{
struct V_6 * V_7 = & V_2 -> V_7 ;
int V_15 = V_7 -> V_16 ;
if ( ! V_15 || ! V_7 -> V_8 . V_12 )
return V_10 ;
while ( V_7 -> V_8 . V_12 ( V_2 , V_5 ) ) {
V_15 -- ;
if ( ! V_15 )
return V_10 ;
F_7 ( V_7 -> V_17 ) ;
}
return 0 ;
}
static T_1 F_8 ( struct V_1 * V_2 , T_3 V_5 )
{
struct V_6 * V_7 = & V_2 -> V_7 ;
int V_15 = V_7 -> V_16 ;
if ( ! V_15 || ! V_7 -> V_8 . V_13 )
return V_10 ;
while ( V_7 -> V_8 . V_13 ( V_2 , V_5 ) ) {
V_15 -- ;
if ( ! V_15 )
return V_10 ;
F_7 ( V_7 -> V_17 ) ;
}
return 0 ;
}
static T_1 F_9 ( struct V_1 * V_2 , T_2 * V_3 , T_3 V_4 ,
T_3 V_5 )
{
struct V_6 * V_7 = & V_2 -> V_7 ;
T_1 V_18 ;
if ( ! V_7 -> V_8 . V_9 )
return V_10 ;
V_18 = F_6 ( V_2 , V_5 ) ;
if ( V_18 )
return V_18 ;
return V_7 -> V_8 . V_9 ( V_2 , V_3 , V_4 , V_5 ) ;
}
static T_1 F_10 ( struct V_1 * V_2 , T_2 * V_3 , T_3 V_4 ,
T_3 V_5 )
{
struct V_6 * V_7 = & V_2 -> V_7 ;
T_1 V_18 ;
if ( ! V_7 -> V_8 . V_11 || ! V_7 -> V_16 )
return V_10 ;
V_18 = V_7 -> V_8 . V_11 ( V_2 , V_3 , V_4 , V_5 ) ;
if ( V_18 )
return V_18 ;
return F_8 ( V_2 , V_5 ) ;
}
static T_1 F_11 ( struct V_1 * V_2 , T_2 V_19 , T_1 V_20 )
{
T_2 V_21 = F_12 ( V_2 , F_13 ( V_20 ) ) ;
if ( V_21 & V_19 ) {
F_14 ( V_2 , F_13 ( V_20 ) , V_19 ) ;
return 0 ;
}
return V_10 ;
}
static T_1 F_15 ( struct V_1 * V_2 , T_3 V_22 )
{
T_1 V_20 = F_16 ( V_22 ) ;
T_2 V_23 = V_22 % 16 ;
if ( ! F_11 ( V_2 , V_24 << V_23 ,
V_20 ) ) {
V_2 -> V_7 . V_25 . V_26 ++ ;
return 0 ;
}
return V_10 ;
}
static T_1 F_17 ( struct V_1 * V_2 , T_3 V_22 )
{
T_1 V_20 = F_16 ( V_22 ) ;
T_2 V_23 = V_22 % 16 ;
if ( ! F_11 ( V_2 , V_27 << V_23 ,
V_20 ) ) {
V_2 -> V_7 . V_25 . V_28 ++ ;
return 0 ;
}
return V_10 ;
}
static T_1 F_18 ( struct V_1 * V_2 , T_3 V_22 )
{
T_2 V_29 = ( V_22 < 32 ) ? 0 : 1 ;
T_2 V_30 = V_22 % 32 ;
T_2 V_31 = 0 ;
switch ( V_2 -> V_32 . type ) {
case V_33 :
V_31 = F_12 ( V_2 , F_19 ( V_29 ) ) ;
break;
case V_34 :
case V_35 :
case V_36 :
V_31 = F_12 ( V_2 , F_20 ( V_29 ) ) ;
break;
default:
break;
}
if ( V_31 & ( 1 << V_30 ) ) {
F_14 ( V_2 , F_20 ( V_29 ) , ( 1 << V_30 ) ) ;
V_2 -> V_7 . V_25 . V_37 ++ ;
return 0 ;
}
return V_10 ;
}
static T_1 F_21 ( struct V_1 * V_2 , T_3 V_22 )
{
T_2 V_38 ;
F_14 ( V_2 , F_22 ( V_22 ) , V_39 ) ;
V_38 = F_12 ( V_2 , F_22 ( V_22 ) ) ;
if ( V_38 & V_39 )
return 0 ;
return V_10 ;
}
static T_1 F_23 ( struct V_1 * V_2 , T_2 * V_3 , T_3 V_4 ,
T_3 V_22 )
{
T_1 V_18 ;
T_3 V_40 ;
V_18 = F_21 ( V_2 , V_22 ) ;
if ( V_18 )
return V_18 ;
F_15 ( V_2 , V_22 ) ;
F_17 ( V_2 , V_22 ) ;
for ( V_40 = 0 ; V_40 < V_4 ; V_40 ++ )
F_24 ( V_2 , F_25 ( V_22 ) , V_40 , V_3 [ V_40 ] ) ;
F_14 ( V_2 , F_22 ( V_22 ) , V_41 ) ;
V_2 -> V_7 . V_25 . V_42 ++ ;
return 0 ;
}
static T_1 F_26 ( struct V_1 * V_2 , T_2 * V_3 , T_3 V_4 ,
T_3 V_22 )
{
T_1 V_18 ;
T_3 V_40 ;
V_18 = F_21 ( V_2 , V_22 ) ;
if ( V_18 )
return V_18 ;
for ( V_40 = 0 ; V_40 < V_4 ; V_40 ++ )
V_3 [ V_40 ] = F_27 ( V_2 , F_25 ( V_22 ) , V_40 ) ;
F_14 ( V_2 , F_22 ( V_22 ) , V_43 ) ;
V_2 -> V_7 . V_25 . V_44 ++ ;
return 0 ;
}
void F_28 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = & V_2 -> V_7 ;
if ( V_2 -> V_32 . type != V_33 &&
V_2 -> V_32 . type != V_35 &&
V_2 -> V_32 . type != V_36 &&
V_2 -> V_32 . type != V_34 )
return;
V_7 -> V_16 = 0 ;
V_7 -> V_17 = 0 ;
V_7 -> V_25 . V_42 = 0 ;
V_7 -> V_25 . V_44 = 0 ;
V_7 -> V_25 . V_26 = 0 ;
V_7 -> V_25 . V_28 = 0 ;
V_7 -> V_25 . V_37 = 0 ;
V_7 -> V_4 = V_45 ;
}
