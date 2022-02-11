T_1 F_1 ( struct V_1 * V_2 , T_2 * V_3 , T_3 V_4 , T_3 V_5 )
{
struct V_6 * V_7 = & V_2 -> V_7 ;
T_1 V_8 = V_9 ;
if ( V_4 > V_7 -> V_4 )
V_4 = V_7 -> V_4 ;
if ( V_7 -> V_10 . V_11 )
V_8 = V_7 -> V_10 . V_11 ( V_2 , V_3 , V_4 , V_5 ) ;
return V_8 ;
}
T_1 F_2 ( struct V_1 * V_2 , T_2 * V_3 , T_3 V_4 , T_3 V_5 )
{
struct V_6 * V_7 = & V_2 -> V_7 ;
T_1 V_8 = 0 ;
if ( V_4 > V_7 -> V_4 )
V_8 = V_9 ;
else if ( V_7 -> V_10 . V_12 )
V_8 = V_7 -> V_10 . V_12 ( V_2 , V_3 , V_4 , V_5 ) ;
return V_8 ;
}
T_1 F_3 ( struct V_1 * V_2 , T_3 V_5 )
{
struct V_6 * V_7 = & V_2 -> V_7 ;
T_1 V_8 = V_9 ;
if ( V_7 -> V_10 . V_13 )
V_8 = V_7 -> V_10 . V_13 ( V_2 , V_5 ) ;
return V_8 ;
}
T_1 F_4 ( struct V_1 * V_2 , T_3 V_5 )
{
struct V_6 * V_7 = & V_2 -> V_7 ;
T_1 V_8 = V_9 ;
if ( V_7 -> V_10 . V_14 )
V_8 = V_7 -> V_10 . V_14 ( V_2 , V_5 ) ;
return V_8 ;
}
T_1 F_5 ( struct V_1 * V_2 , T_3 V_5 )
{
struct V_6 * V_7 = & V_2 -> V_7 ;
T_1 V_8 = V_9 ;
if ( V_7 -> V_10 . V_15 )
V_8 = V_7 -> V_10 . V_15 ( V_2 , V_5 ) ;
return V_8 ;
}
static T_1 F_6 ( struct V_1 * V_2 , T_3 V_5 )
{
struct V_6 * V_7 = & V_2 -> V_7 ;
int V_16 = V_7 -> V_17 ;
if ( ! V_16 || ! V_7 -> V_10 . V_13 )
goto V_18;
while ( V_16 && V_7 -> V_10 . V_13 ( V_2 , V_5 ) ) {
V_16 -- ;
if ( ! V_16 )
break;
F_7 ( V_7 -> V_19 ) ;
}
V_18:
return V_16 ? 0 : V_9 ;
}
static T_1 F_8 ( struct V_1 * V_2 , T_3 V_5 )
{
struct V_6 * V_7 = & V_2 -> V_7 ;
int V_16 = V_7 -> V_17 ;
if ( ! V_16 || ! V_7 -> V_10 . V_14 )
goto V_18;
while ( V_16 && V_7 -> V_10 . V_14 ( V_2 , V_5 ) ) {
V_16 -- ;
if ( ! V_16 )
break;
F_7 ( V_7 -> V_19 ) ;
}
V_18:
return V_16 ? 0 : V_9 ;
}
static T_1 F_9 ( struct V_1 * V_2 , T_2 * V_3 , T_3 V_4 ,
T_3 V_5 )
{
struct V_6 * V_7 = & V_2 -> V_7 ;
T_1 V_8 = V_9 ;
if ( ! V_7 -> V_10 . V_11 )
goto V_18;
V_8 = F_6 ( V_2 , V_5 ) ;
if ( ! V_8 )
V_8 = V_7 -> V_10 . V_11 ( V_2 , V_3 , V_4 , V_5 ) ;
V_18:
return V_8 ;
}
static T_1 F_10 ( struct V_1 * V_2 , T_2 * V_3 , T_3 V_4 ,
T_3 V_5 )
{
struct V_6 * V_7 = & V_2 -> V_7 ;
T_1 V_8 = V_9 ;
if ( ! V_7 -> V_10 . V_12 || ! V_7 -> V_17 )
goto V_18;
V_8 = V_7 -> V_10 . V_12 ( V_2 , V_3 , V_4 , V_5 ) ;
if ( ! V_8 )
V_8 = F_8 ( V_2 , V_5 ) ;
V_18:
return V_8 ;
}
static T_1 F_11 ( struct V_1 * V_2 , T_2 V_20 , T_1 V_21 )
{
T_2 V_22 = F_12 ( V_2 , F_13 ( V_21 ) ) ;
T_1 V_8 = V_9 ;
if ( V_22 & V_20 ) {
V_8 = 0 ;
F_14 ( V_2 , F_13 ( V_21 ) , V_20 ) ;
}
return V_8 ;
}
static T_1 F_15 ( struct V_1 * V_2 , T_3 V_23 )
{
T_1 V_8 = V_9 ;
T_1 V_21 = F_16 ( V_23 ) ;
T_2 V_24 = V_23 % 16 ;
if ( ! F_11 ( V_2 , V_25 << V_24 ,
V_21 ) ) {
V_8 = 0 ;
V_2 -> V_7 . V_26 . V_27 ++ ;
}
return V_8 ;
}
static T_1 F_17 ( struct V_1 * V_2 , T_3 V_23 )
{
T_1 V_8 = V_9 ;
T_1 V_21 = F_16 ( V_23 ) ;
T_2 V_24 = V_23 % 16 ;
if ( ! F_11 ( V_2 , V_28 << V_24 ,
V_21 ) ) {
V_8 = 0 ;
V_2 -> V_7 . V_26 . V_29 ++ ;
}
return V_8 ;
}
static T_1 F_18 ( struct V_1 * V_2 , T_3 V_23 )
{
T_2 V_30 = ( V_23 < 32 ) ? 0 : 1 ;
T_2 V_31 = V_23 % 32 ;
T_2 V_32 = 0 ;
T_1 V_8 = V_9 ;
switch ( V_2 -> V_33 . type ) {
case V_34 :
V_32 = F_12 ( V_2 , F_19 ( V_30 ) ) ;
break;
case V_35 :
V_32 = F_12 ( V_2 , F_20 ( V_30 ) ) ;
break;
default:
break;
}
if ( V_32 & ( 1 << V_31 ) ) {
V_8 = 0 ;
F_14 ( V_2 , F_20 ( V_30 ) , ( 1 << V_31 ) ) ;
V_2 -> V_7 . V_26 . V_36 ++ ;
}
return V_8 ;
}
static T_1 F_21 ( struct V_1 * V_2 , T_3 V_23 )
{
T_1 V_8 = V_9 ;
T_2 V_37 ;
F_14 ( V_2 , F_22 ( V_23 ) , V_38 ) ;
V_37 = F_12 ( V_2 , F_22 ( V_23 ) ) ;
if ( V_37 & V_38 )
V_8 = 0 ;
return V_8 ;
}
static T_1 F_23 ( struct V_1 * V_2 , T_2 * V_3 , T_3 V_4 ,
T_3 V_23 )
{
T_1 V_8 ;
T_3 V_39 ;
V_8 = F_21 ( V_2 , V_23 ) ;
if ( V_8 )
goto V_40;
F_15 ( V_2 , V_23 ) ;
F_17 ( V_2 , V_23 ) ;
for ( V_39 = 0 ; V_39 < V_4 ; V_39 ++ )
F_24 ( V_2 , F_25 ( V_23 ) , V_39 , V_3 [ V_39 ] ) ;
F_14 ( V_2 , F_22 ( V_23 ) , V_41 ) ;
V_2 -> V_7 . V_26 . V_42 ++ ;
V_40:
return V_8 ;
}
static T_1 F_26 ( struct V_1 * V_2 , T_2 * V_3 , T_3 V_4 ,
T_3 V_23 )
{
T_1 V_8 ;
T_3 V_39 ;
V_8 = F_21 ( V_2 , V_23 ) ;
if ( V_8 )
goto V_43;
for ( V_39 = 0 ; V_39 < V_4 ; V_39 ++ )
V_3 [ V_39 ] = F_27 ( V_2 , F_25 ( V_23 ) , V_39 ) ;
F_14 ( V_2 , F_22 ( V_23 ) , V_44 ) ;
V_2 -> V_7 . V_26 . V_45 ++ ;
V_43:
return V_8 ;
}
void F_28 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = & V_2 -> V_7 ;
if ( V_2 -> V_33 . type != V_34 &&
V_2 -> V_33 . type != V_35 )
return;
V_7 -> V_17 = 0 ;
V_7 -> V_19 = 0 ;
V_7 -> V_26 . V_42 = 0 ;
V_7 -> V_26 . V_45 = 0 ;
V_7 -> V_26 . V_27 = 0 ;
V_7 -> V_26 . V_29 = 0 ;
V_7 -> V_26 . V_36 = 0 ;
V_7 -> V_4 = V_46 ;
}
