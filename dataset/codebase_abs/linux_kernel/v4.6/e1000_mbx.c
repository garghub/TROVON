T_1 F_1 ( struct V_1 * V_2 , T_2 * V_3 , T_3 V_4 , T_3 V_5 )
{
struct V_6 * V_7 = & V_2 -> V_7 ;
T_1 V_8 = - V_9 ;
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
V_8 = - V_9 ;
else if ( V_7 -> V_10 . V_12 )
V_8 = V_7 -> V_10 . V_12 ( V_2 , V_3 , V_4 , V_5 ) ;
return V_8 ;
}
T_1 F_3 ( struct V_1 * V_2 , T_3 V_5 )
{
struct V_6 * V_7 = & V_2 -> V_7 ;
T_1 V_8 = - V_9 ;
if ( V_7 -> V_10 . V_13 )
V_8 = V_7 -> V_10 . V_13 ( V_2 , V_5 ) ;
return V_8 ;
}
T_1 F_4 ( struct V_1 * V_2 , T_3 V_5 )
{
struct V_6 * V_7 = & V_2 -> V_7 ;
T_1 V_8 = - V_9 ;
if ( V_7 -> V_10 . V_14 )
V_8 = V_7 -> V_10 . V_14 ( V_2 , V_5 ) ;
return V_8 ;
}
T_1 F_5 ( struct V_1 * V_2 , T_3 V_5 )
{
struct V_6 * V_7 = & V_2 -> V_7 ;
T_1 V_8 = - V_9 ;
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
if ( ! V_16 )
V_7 -> V_17 = 0 ;
V_18:
return V_16 ? 0 : - V_9 ;
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
if ( ! V_16 )
V_7 -> V_17 = 0 ;
V_18:
return V_16 ? 0 : - V_9 ;
}
static T_1 F_9 ( struct V_1 * V_2 , T_2 * V_3 , T_3 V_4 ,
T_3 V_5 )
{
struct V_6 * V_7 = & V_2 -> V_7 ;
T_1 V_8 = - V_9 ;
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
T_1 V_8 = - V_9 ;
if ( ! V_7 -> V_10 . V_12 || ! V_7 -> V_17 )
goto V_18;
V_8 = V_7 -> V_10 . V_12 ( V_2 , V_3 , V_4 , V_5 ) ;
if ( ! V_8 )
V_8 = F_8 ( V_2 , V_5 ) ;
V_18:
return V_8 ;
}
static T_1 F_11 ( struct V_1 * V_2 , T_2 V_20 )
{
T_2 V_21 = F_12 ( V_22 ) ;
T_1 V_8 = - V_9 ;
if ( V_21 & V_20 ) {
V_8 = 0 ;
F_13 ( V_22 , V_20 ) ;
}
return V_8 ;
}
static T_1 F_14 ( struct V_1 * V_2 , T_3 V_23 )
{
T_1 V_8 = - V_9 ;
if ( ! F_11 ( V_2 , V_24 << V_23 ) ) {
V_8 = 0 ;
V_2 -> V_7 . V_25 . V_26 ++ ;
}
return V_8 ;
}
static T_1 F_15 ( struct V_1 * V_2 , T_3 V_23 )
{
T_1 V_8 = - V_9 ;
if ( ! F_11 ( V_2 , V_27 << V_23 ) ) {
V_8 = 0 ;
V_2 -> V_7 . V_25 . V_28 ++ ;
}
return V_8 ;
}
static T_1 F_16 ( struct V_1 * V_2 , T_3 V_23 )
{
T_2 V_29 = F_12 ( V_30 ) ;
T_1 V_8 = - V_9 ;
if ( V_29 & ( 1 << V_23 ) ) {
V_8 = 0 ;
F_13 ( V_30 , ( 1 << V_23 ) ) ;
V_2 -> V_7 . V_25 . V_31 ++ ;
}
return V_8 ;
}
static T_1 F_17 ( struct V_1 * V_2 , T_3 V_23 )
{
T_1 V_8 = - V_9 ;
T_2 V_32 ;
int V_33 = 10 ;
do {
F_13 ( F_18 ( V_23 ) , V_34 ) ;
V_32 = F_12 ( F_18 ( V_23 ) ) ;
if ( V_32 & V_34 ) {
V_8 = 0 ;
break;
}
F_7 ( 1000 ) ;
} while ( V_33 -- > 0 );
return V_8 ;
}
static T_1 F_19 ( struct V_1 * V_2 , T_2 * V_3 , T_3 V_4 ,
T_3 V_23 )
{
T_1 V_8 ;
T_3 V_35 ;
V_8 = F_17 ( V_2 , V_23 ) ;
if ( V_8 )
goto V_36;
F_14 ( V_2 , V_23 ) ;
F_15 ( V_2 , V_23 ) ;
for ( V_35 = 0 ; V_35 < V_4 ; V_35 ++ )
F_20 ( F_21 ( V_23 ) , V_35 , V_3 [ V_35 ] ) ;
F_13 ( F_18 ( V_23 ) , V_37 ) ;
V_2 -> V_7 . V_25 . V_38 ++ ;
V_36:
return V_8 ;
}
static T_1 F_22 ( struct V_1 * V_2 , T_2 * V_3 , T_3 V_4 ,
T_3 V_23 )
{
T_1 V_8 ;
T_3 V_35 ;
V_8 = F_17 ( V_2 , V_23 ) ;
if ( V_8 )
goto V_39;
for ( V_35 = 0 ; V_35 < V_4 ; V_35 ++ )
V_3 [ V_35 ] = F_23 ( F_21 ( V_23 ) , V_35 ) ;
F_13 ( F_18 ( V_23 ) , V_40 ) ;
V_2 -> V_7 . V_25 . V_41 ++ ;
V_39:
return V_8 ;
}
T_1 F_24 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = & V_2 -> V_7 ;
V_7 -> V_17 = 0 ;
V_7 -> V_19 = 0 ;
V_7 -> V_4 = V_42 ;
V_7 -> V_10 . V_11 = F_22 ;
V_7 -> V_10 . V_12 = F_19 ;
V_7 -> V_10 . V_43 = F_9 ;
V_7 -> V_10 . V_44 = F_10 ;
V_7 -> V_10 . V_13 = F_14 ;
V_7 -> V_10 . V_14 = F_15 ;
V_7 -> V_10 . V_15 = F_16 ;
V_7 -> V_25 . V_38 = 0 ;
V_7 -> V_25 . V_41 = 0 ;
V_7 -> V_25 . V_26 = 0 ;
V_7 -> V_25 . V_28 = 0 ;
V_7 -> V_25 . V_31 = 0 ;
return 0 ;
}
