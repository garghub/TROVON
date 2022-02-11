static T_1 F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
int V_5 = V_4 -> V_6 ;
if ( ! V_4 -> V_7 . V_8 )
goto V_9;
while ( V_5 && V_4 -> V_7 . V_8 ( V_2 ) ) {
V_5 -- ;
F_2 ( V_4 -> V_10 ) ;
}
if ( ! V_5 )
V_4 -> V_6 = 0 ;
V_9:
return V_5 ? V_11 : - V_12 ;
}
static T_1 F_3 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
int V_5 = V_4 -> V_6 ;
if ( ! V_4 -> V_7 . V_13 )
goto V_9;
while ( V_5 && V_4 -> V_7 . V_13 ( V_2 ) ) {
V_5 -- ;
F_2 ( V_4 -> V_10 ) ;
}
if ( ! V_5 )
V_4 -> V_6 = 0 ;
V_9:
return V_5 ? V_11 : - V_12 ;
}
static T_1 F_4 ( struct V_1 * V_2 , T_2 * V_14 , T_3 V_15 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
T_1 V_16 = - V_12 ;
if ( ! V_4 -> V_7 . V_17 )
goto V_9;
V_16 = F_1 ( V_2 ) ;
if ( ! V_16 )
V_16 = V_4 -> V_7 . V_17 ( V_2 , V_14 , V_15 ) ;
V_9:
return V_16 ;
}
static T_1 F_5 ( struct V_1 * V_2 , T_2 * V_14 , T_3 V_15 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
T_1 V_16 = - V_12 ;
if ( ! V_4 -> V_7 . V_18 || ! V_4 -> V_6 )
goto V_9;
V_16 = V_4 -> V_7 . V_18 ( V_2 , V_14 , V_15 ) ;
if ( ! V_16 )
V_16 = F_3 ( V_2 ) ;
V_9:
return V_16 ;
}
static T_2 F_6 ( struct V_1 * V_2 )
{
T_2 V_19 = F_7 ( F_8 ( 0 ) ) ;
V_19 |= V_2 -> V_20 . V_21 . V_19 ;
V_2 -> V_20 . V_21 . V_19 |= V_19 & V_22 ;
return V_19 ;
}
static T_1 F_9 ( struct V_1 * V_2 , T_2 V_23 )
{
T_2 V_19 = F_6 ( V_2 ) ;
T_1 V_16 = - V_12 ;
if ( V_19 & V_23 )
V_16 = V_11 ;
V_2 -> V_20 . V_21 . V_19 &= ~ V_23 ;
return V_16 ;
}
static T_1 F_10 ( struct V_1 * V_2 )
{
T_1 V_16 = - V_12 ;
if ( ! F_9 ( V_2 , V_24 ) ) {
V_16 = V_11 ;
V_2 -> V_4 . V_25 . V_26 ++ ;
}
return V_16 ;
}
static T_1 F_11 ( struct V_1 * V_2 )
{
T_1 V_16 = - V_12 ;
if ( ! F_9 ( V_2 , V_27 ) ) {
V_16 = V_11 ;
V_2 -> V_4 . V_25 . V_28 ++ ;
}
return V_16 ;
}
static T_1 F_12 ( struct V_1 * V_2 )
{
T_1 V_16 = - V_12 ;
if ( ! F_9 ( V_2 , ( V_29 |
V_30 ) ) ) {
V_16 = V_11 ;
V_2 -> V_4 . V_25 . V_31 ++ ;
}
return V_16 ;
}
static T_1 F_13 ( struct V_1 * V_2 )
{
T_1 V_16 = - V_12 ;
int V_32 = 10 ;
do {
F_14 ( F_8 ( 0 ) , V_33 ) ;
if ( F_6 ( V_2 ) & V_33 ) {
V_16 = 0 ;
break;
}
F_2 ( 1000 ) ;
} while ( V_32 -- > 0 );
return V_16 ;
}
static T_1 F_15 ( struct V_1 * V_2 , T_2 * V_14 , T_3 V_15 )
{
T_1 V_34 ;
T_3 V_35 ;
F_16 ( ! F_17 ( & V_2 -> V_36 ) ) ;
V_34 = F_13 ( V_2 ) ;
if ( V_34 )
goto V_37;
F_11 ( V_2 ) ;
F_10 ( V_2 ) ;
for ( V_35 = 0 ; V_35 < V_15 ; V_35 ++ )
F_18 ( F_19 ( 0 ) , V_35 , V_14 [ V_35 ] ) ;
V_2 -> V_4 . V_25 . V_38 ++ ;
F_14 ( F_8 ( 0 ) , V_39 ) ;
V_37:
return V_34 ;
}
static T_1 F_20 ( struct V_1 * V_2 , T_2 * V_14 , T_3 V_15 )
{
T_1 V_34 ;
T_3 V_35 ;
F_16 ( ! F_17 ( & V_2 -> V_36 ) ) ;
V_34 = F_13 ( V_2 ) ;
if ( V_34 )
goto V_40;
for ( V_35 = 0 ; V_35 < V_15 ; V_35 ++ )
V_14 [ V_35 ] = F_21 ( F_19 ( 0 ) , V_35 ) ;
F_14 ( F_8 ( 0 ) , V_41 ) ;
V_2 -> V_4 . V_25 . V_42 ++ ;
V_40:
return V_34 ;
}
T_1 F_22 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
V_4 -> V_6 = 0 ;
V_4 -> V_10 = V_43 ;
V_4 -> V_15 = V_44 ;
V_4 -> V_7 . V_17 = F_20 ;
V_4 -> V_7 . V_18 = F_15 ;
V_4 -> V_7 . V_45 = F_4 ;
V_4 -> V_7 . V_46 = F_5 ;
V_4 -> V_7 . V_8 = F_10 ;
V_4 -> V_7 . V_13 = F_11 ;
V_4 -> V_7 . V_47 = F_12 ;
V_4 -> V_25 . V_38 = 0 ;
V_4 -> V_25 . V_42 = 0 ;
V_4 -> V_25 . V_26 = 0 ;
V_4 -> V_25 . V_28 = 0 ;
V_4 -> V_25 . V_31 = 0 ;
return V_11 ;
}
