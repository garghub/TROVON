int F_1 ( struct V_1 * V_2 , const char * V_3 , int type ,
struct V_4 * V_5 )
{
F_2 ( & V_5 -> V_6 ) ;
V_5 -> V_2 = V_2 ;
F_3 ( & V_5 -> V_7 ) ;
F_3 ( & V_5 -> V_8 ) ;
F_4 ( & V_5 -> V_9 ) ;
return F_5 ( V_2 -> V_10 -> V_11 , V_3 , type , & V_5 -> V_5 ) ;
}
void F_6 ( struct V_4 * V_5 , int V_12 , int V_13 )
{
struct V_1 * V_2 ;
struct V_14 * V_15 ;
struct V_16 * V_17 ;
int V_18 ;
F_7 ( V_5 , V_13 , V_12 ) ;
if ( ! V_5 )
return;
V_2 = V_5 -> V_2 ;
V_15 = & V_2 -> V_15 ;
F_8 ( & V_5 -> V_6 ) ;
V_5 -> V_12 &= ~ V_13 ;
V_5 -> V_12 |= V_12 & V_13 ;
F_9 ( V_5 , V_12 ) ;
F_10 (pin, &jack->pins, list) {
V_18 = V_17 -> V_13 & V_5 -> V_12 ;
if ( V_17 -> V_19 )
V_18 = ! V_18 ;
if ( V_18 )
F_11 ( V_15 , V_17 -> V_17 ) ;
else
F_12 ( V_15 , V_17 -> V_17 ) ;
}
F_13 ( & V_5 -> V_9 , V_5 -> V_12 , V_5 ) ;
F_14 ( V_15 ) ;
F_15 ( V_5 -> V_5 , V_5 -> V_12 ) ;
F_16 ( & V_5 -> V_6 ) ;
}
int F_17 ( struct V_4 * V_5 , int V_20 ,
struct V_21 * V_22 )
{
int V_23 ;
for ( V_23 = 0 ; V_23 < V_20 ; V_23 ++ ) {
F_3 ( & V_22 [ V_23 ] . V_24 ) ;
F_18 ( & ( V_22 [ V_23 ] . V_24 ) , & V_5 -> V_8 ) ;
}
return 0 ;
}
int F_19 ( struct V_4 * V_5 , int V_25 )
{
struct V_21 * V_26 ;
F_10 (zone, &jack->jack_zones, list) {
if ( V_25 >= V_26 -> V_27 &&
V_25 < V_26 -> V_28 )
return V_26 -> V_29 ;
}
return 0 ;
}
int F_20 ( struct V_4 * V_5 , int V_20 ,
struct V_16 * V_7 )
{
int V_23 ;
for ( V_23 = 0 ; V_23 < V_20 ; V_23 ++ ) {
if ( ! V_7 [ V_23 ] . V_17 ) {
F_21 ( V_5 -> V_2 -> V_30 , L_1 ,
V_23 ) ;
return - V_31 ;
}
if ( ! V_7 [ V_23 ] . V_13 ) {
F_21 ( V_5 -> V_2 -> V_30 , L_2
L_3 , V_23 , V_7 [ V_23 ] . V_17 ) ;
return - V_31 ;
}
F_3 ( & V_7 [ V_23 ] . V_24 ) ;
F_18 ( & ( V_7 [ V_23 ] . V_24 ) , & V_5 -> V_7 ) ;
}
F_6 ( V_5 , 0 , 0 ) ;
return 0 ;
}
void F_22 ( struct V_4 * V_5 ,
struct V_32 * V_33 )
{
F_23 ( & V_5 -> V_9 , V_33 ) ;
}
void F_24 ( struct V_4 * V_5 ,
struct V_32 * V_33 )
{
F_25 ( & V_5 -> V_9 , V_33 ) ;
}
static void F_26 ( struct V_34 * V_35 )
{
struct V_4 * V_5 = V_35 -> V_5 ;
int V_18 ;
int V_36 ;
V_18 = F_27 ( V_35 -> V_35 ) ;
if ( V_35 -> V_19 )
V_18 = ! V_18 ;
if ( V_18 )
V_36 = V_35 -> V_36 ;
else
V_36 = 0 ;
if ( V_35 -> V_37 )
V_36 = V_35 -> V_37 () ;
F_6 ( V_5 , V_36 , V_35 -> V_36 ) ;
}
static T_1 F_28 ( int V_38 , void * V_39 )
{
struct V_34 * V_35 = V_39 ;
struct V_40 * V_30 = V_35 -> V_5 -> V_2 -> V_10 -> V_30 ;
F_29 ( V_35 -> V_41 ) ;
if ( F_30 ( V_30 ) )
F_31 ( V_30 , V_35 -> V_42 + 50 ) ;
F_32 ( V_43 , & V_35 -> V_44 ,
F_33 ( V_35 -> V_42 ) ) ;
return V_45 ;
}
static void F_34 ( struct V_46 * V_44 )
{
struct V_34 * V_35 ;
V_35 = F_35 ( V_44 , struct V_34 , V_44 . V_44 ) ;
F_26 ( V_35 ) ;
}
int F_36 ( struct V_4 * V_5 , int V_20 ,
struct V_34 * V_47 )
{
int V_23 , V_48 ;
for ( V_23 = 0 ; V_23 < V_20 ; V_23 ++ ) {
if ( ! F_37 ( V_47 [ V_23 ] . V_35 ) ) {
F_21 ( V_5 -> V_2 -> V_30 , L_4 ,
V_47 [ V_23 ] . V_35 ) ;
V_48 = - V_31 ;
goto V_49;
}
if ( ! V_47 [ V_23 ] . V_41 ) {
F_21 ( V_5 -> V_2 -> V_30 , L_5 ,
V_47 [ V_23 ] . V_35 ) ;
V_48 = - V_31 ;
goto V_49;
}
V_48 = F_38 ( V_47 [ V_23 ] . V_35 , V_47 [ V_23 ] . V_41 ) ;
if ( V_48 )
goto V_49;
V_48 = F_39 ( V_47 [ V_23 ] . V_35 ) ;
if ( V_48 )
goto V_50;
F_40 ( & V_47 [ V_23 ] . V_44 , F_34 ) ;
V_47 [ V_23 ] . V_5 = V_5 ;
V_48 = F_41 ( F_42 ( V_47 [ V_23 ] . V_35 ) ,
F_28 ,
V_51 |
V_52 ,
V_47 [ V_23 ] . V_41 ,
& V_47 [ V_23 ] ) ;
if ( V_48 < 0 )
goto V_50;
if ( V_47 [ V_23 ] . V_53 ) {
V_48 = F_43 ( F_42 ( V_47 [ V_23 ] . V_35 ) , 1 ) ;
if ( V_48 != 0 )
F_21 ( V_5 -> V_2 -> V_30 , L_6
L_7 ,
V_47 [ V_23 ] . V_35 , V_48 ) ;
}
F_44 ( V_47 [ V_23 ] . V_35 , false ) ;
F_26 ( & V_47 [ V_23 ] ) ;
}
return 0 ;
V_50:
F_45 ( V_47 [ V_23 ] . V_35 ) ;
V_49:
F_46 ( V_5 , V_23 , V_47 ) ;
return V_48 ;
}
void F_46 ( struct V_4 * V_5 , int V_20 ,
struct V_34 * V_47 )
{
int V_23 ;
for ( V_23 = 0 ; V_23 < V_20 ; V_23 ++ ) {
F_47 ( V_47 [ V_23 ] . V_35 ) ;
F_48 ( F_42 ( V_47 [ V_23 ] . V_35 ) , & V_47 [ V_23 ] ) ;
F_49 ( & V_47 [ V_23 ] . V_44 ) ;
F_45 ( V_47 [ V_23 ] . V_35 ) ;
V_47 [ V_23 ] . V_5 = NULL ;
}
}
