T_1 F_1 ( struct V_1 * V_2 , T_2 * V_3 , T_3 V_4 , T_3 V_5 ,
bool V_6 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
T_1 V_9 = - V_10 ;
if ( V_4 > V_8 -> V_4 )
V_4 = V_8 -> V_4 ;
if ( V_8 -> V_11 . V_12 )
V_9 = V_8 -> V_11 . V_12 ( V_2 , V_3 , V_4 , V_5 , V_6 ) ;
return V_9 ;
}
T_1 F_2 ( struct V_1 * V_2 , T_2 * V_3 , T_3 V_4 , T_3 V_5 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
T_1 V_9 = 0 ;
if ( V_4 > V_8 -> V_4 )
V_9 = - V_10 ;
else if ( V_8 -> V_11 . V_13 )
V_9 = V_8 -> V_11 . V_13 ( V_2 , V_3 , V_4 , V_5 ) ;
return V_9 ;
}
T_1 F_3 ( struct V_1 * V_2 , T_3 V_5 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
T_1 V_9 = - V_10 ;
if ( V_8 -> V_11 . V_14 )
V_9 = V_8 -> V_11 . V_14 ( V_2 , V_5 ) ;
return V_9 ;
}
T_1 F_4 ( struct V_1 * V_2 , T_3 V_5 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
T_1 V_9 = - V_10 ;
if ( V_8 -> V_11 . V_15 )
V_9 = V_8 -> V_11 . V_15 ( V_2 , V_5 ) ;
return V_9 ;
}
T_1 F_5 ( struct V_1 * V_2 , T_3 V_5 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
T_1 V_9 = - V_10 ;
if ( V_8 -> V_11 . V_16 )
V_9 = V_8 -> V_11 . V_16 ( V_2 , V_5 ) ;
return V_9 ;
}
T_1 F_6 ( struct V_1 * V_2 , T_3 V_5 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
T_1 V_9 = - V_10 ;
if ( V_8 -> V_11 . V_6 )
V_9 = V_8 -> V_11 . V_6 ( V_2 , V_5 ) ;
return V_9 ;
}
static T_1 F_7 ( struct V_1 * V_2 , T_3 V_5 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
int V_17 = V_8 -> V_18 ;
if ( ! V_17 || ! V_8 -> V_11 . V_14 )
goto V_19;
while ( V_17 && V_8 -> V_11 . V_14 ( V_2 , V_5 ) ) {
V_17 -- ;
if ( ! V_17 )
break;
F_8 ( V_8 -> V_20 ) ;
}
if ( ! V_17 )
V_8 -> V_18 = 0 ;
V_19:
return V_17 ? 0 : - V_10 ;
}
static T_1 F_9 ( struct V_1 * V_2 , T_3 V_5 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
int V_17 = V_8 -> V_18 ;
if ( ! V_17 || ! V_8 -> V_11 . V_15 )
goto V_19;
while ( V_17 && V_8 -> V_11 . V_15 ( V_2 , V_5 ) ) {
V_17 -- ;
if ( ! V_17 )
break;
F_8 ( V_8 -> V_20 ) ;
}
if ( ! V_17 )
V_8 -> V_18 = 0 ;
V_19:
return V_17 ? 0 : - V_10 ;
}
static T_1 F_10 ( struct V_1 * V_2 , T_2 * V_3 , T_3 V_4 ,
T_3 V_5 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
T_1 V_9 = - V_10 ;
if ( ! V_8 -> V_11 . V_12 )
goto V_19;
V_9 = F_7 ( V_2 , V_5 ) ;
if ( ! V_9 )
V_9 = V_8 -> V_11 . V_12 ( V_2 , V_3 , V_4 , V_5 , true ) ;
V_19:
return V_9 ;
}
static T_1 F_11 ( struct V_1 * V_2 , T_2 * V_3 , T_3 V_4 ,
T_3 V_5 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
T_1 V_9 = - V_10 ;
if ( ! V_8 -> V_11 . V_13 || ! V_8 -> V_18 )
goto V_19;
V_9 = V_8 -> V_11 . V_13 ( V_2 , V_3 , V_4 , V_5 ) ;
if ( ! V_9 )
V_9 = F_9 ( V_2 , V_5 ) ;
V_19:
return V_9 ;
}
static T_1 F_12 ( struct V_1 * V_2 , T_2 V_21 )
{
T_2 V_22 = F_13 ( V_23 ) ;
T_1 V_9 = - V_10 ;
if ( V_22 & V_21 ) {
V_9 = 0 ;
F_14 ( V_23 , V_21 ) ;
}
return V_9 ;
}
static T_1 F_15 ( struct V_1 * V_2 , T_3 V_24 )
{
T_1 V_9 = - V_10 ;
if ( ! F_12 ( V_2 , V_25 << V_24 ) ) {
V_9 = 0 ;
V_2 -> V_8 . V_26 . V_27 ++ ;
}
return V_9 ;
}
static T_1 F_16 ( struct V_1 * V_2 , T_3 V_24 )
{
T_1 V_9 = - V_10 ;
if ( ! F_12 ( V_2 , V_28 << V_24 ) ) {
V_9 = 0 ;
V_2 -> V_8 . V_26 . V_29 ++ ;
}
return V_9 ;
}
static T_1 F_17 ( struct V_1 * V_2 , T_3 V_24 )
{
T_2 V_30 = F_13 ( V_31 ) ;
T_1 V_9 = - V_10 ;
if ( V_30 & F_18 ( V_24 ) ) {
V_9 = 0 ;
F_14 ( V_31 , F_18 ( V_24 ) ) ;
V_2 -> V_8 . V_26 . V_32 ++ ;
}
return V_9 ;
}
static T_1 F_19 ( struct V_1 * V_2 , T_3 V_24 )
{
T_1 V_9 = - V_10 ;
T_2 V_33 ;
int V_34 = 10 ;
do {
F_14 ( F_20 ( V_24 ) , V_35 ) ;
V_33 = F_13 ( F_20 ( V_24 ) ) ;
if ( V_33 & V_35 ) {
V_9 = 0 ;
break;
}
F_8 ( 1000 ) ;
} while ( V_34 -- > 0 );
return V_9 ;
}
static T_1 F_21 ( struct V_1 * V_2 , T_3 V_24 )
{
T_2 V_33 ;
V_33 = F_13 ( F_20 ( V_24 ) ) ;
if ( V_33 & V_35 )
F_14 ( F_20 ( V_24 ) ,
V_33 & ~ V_35 ) ;
return 0 ;
}
static T_1 F_22 ( struct V_1 * V_2 , T_2 * V_3 , T_3 V_4 ,
T_3 V_24 )
{
T_1 V_9 ;
T_3 V_36 ;
V_9 = F_19 ( V_2 , V_24 ) ;
if ( V_9 )
goto V_37;
F_15 ( V_2 , V_24 ) ;
F_16 ( V_2 , V_24 ) ;
for ( V_36 = 0 ; V_36 < V_4 ; V_36 ++ )
F_23 ( F_24 ( V_24 ) , V_36 , V_3 [ V_36 ] ) ;
F_14 ( F_20 ( V_24 ) , V_38 ) ;
V_2 -> V_8 . V_26 . V_39 ++ ;
V_37:
return V_9 ;
}
static T_1 F_25 ( struct V_1 * V_2 , T_2 * V_3 , T_3 V_4 ,
T_3 V_24 , bool V_6 )
{
T_1 V_9 ;
T_3 V_36 ;
V_9 = F_19 ( V_2 , V_24 ) ;
if ( V_9 )
goto V_40;
for ( V_36 = 0 ; V_36 < V_4 ; V_36 ++ )
V_3 [ V_36 ] = F_26 ( F_24 ( V_24 ) , V_36 ) ;
if ( V_6 )
F_14 ( F_20 ( V_24 ) , V_41 ) ;
else
F_14 ( F_20 ( V_24 ) ,
V_41 | V_35 ) ;
V_2 -> V_8 . V_26 . V_42 ++ ;
V_40:
return V_9 ;
}
T_1 F_27 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
V_8 -> V_18 = 0 ;
V_8 -> V_20 = 0 ;
V_8 -> V_4 = V_43 ;
V_8 -> V_11 . V_12 = F_25 ;
V_8 -> V_11 . V_13 = F_22 ;
V_8 -> V_11 . V_44 = F_10 ;
V_8 -> V_11 . V_45 = F_11 ;
V_8 -> V_11 . V_14 = F_15 ;
V_8 -> V_11 . V_15 = F_16 ;
V_8 -> V_11 . V_16 = F_17 ;
V_8 -> V_11 . V_6 = F_21 ;
V_8 -> V_26 . V_39 = 0 ;
V_8 -> V_26 . V_42 = 0 ;
V_8 -> V_26 . V_27 = 0 ;
V_8 -> V_26 . V_29 = 0 ;
V_8 -> V_26 . V_32 = 0 ;
return 0 ;
}
