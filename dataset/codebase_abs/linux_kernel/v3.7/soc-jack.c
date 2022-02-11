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
int V_19 ;
F_7 ( V_5 , V_13 , V_12 ) ;
if ( ! V_5 )
return;
V_2 = V_5 -> V_2 ;
V_15 = & V_2 -> V_15 ;
F_8 ( & V_5 -> V_6 ) ;
V_19 = V_5 -> V_12 ;
V_5 -> V_12 &= ~ V_13 ;
V_5 -> V_12 |= V_12 & V_13 ;
F_9 ( V_5 , V_12 ) ;
F_10 (pin, &jack->pins, list) {
V_18 = V_17 -> V_13 & V_5 -> V_12 ;
if ( V_17 -> V_20 )
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
int F_17 ( struct V_4 * V_5 , int V_21 ,
struct V_22 * V_23 )
{
int V_24 ;
for ( V_24 = 0 ; V_24 < V_21 ; V_24 ++ ) {
F_3 ( & V_23 [ V_24 ] . V_25 ) ;
F_18 ( & ( V_23 [ V_24 ] . V_25 ) , & V_5 -> V_8 ) ;
}
return 0 ;
}
int F_19 ( struct V_4 * V_5 , int V_26 )
{
struct V_22 * V_27 ;
F_10 (zone, &jack->jack_zones, list) {
if ( V_26 >= V_27 -> V_28 &&
V_26 < V_27 -> V_29 )
return V_27 -> V_30 ;
}
return 0 ;
}
int F_20 ( struct V_4 * V_5 , int V_21 ,
struct V_16 * V_7 )
{
int V_24 ;
for ( V_24 = 0 ; V_24 < V_21 ; V_24 ++ ) {
if ( ! V_7 [ V_24 ] . V_17 ) {
F_21 ( V_31 L_1 , V_24 ) ;
return - V_32 ;
}
if ( ! V_7 [ V_24 ] . V_13 ) {
F_21 ( V_31 L_2 , V_24 ,
V_7 [ V_24 ] . V_17 ) ;
return - V_32 ;
}
F_3 ( & V_7 [ V_24 ] . V_25 ) ;
F_18 ( & ( V_7 [ V_24 ] . V_25 ) , & V_5 -> V_7 ) ;
}
F_22 ( & V_5 -> V_2 -> V_10 -> V_15 ) ;
F_6 ( V_5 , 0 , 0 ) ;
return 0 ;
}
void F_23 ( struct V_4 * V_5 ,
struct V_33 * V_34 )
{
F_24 ( & V_5 -> V_9 , V_34 ) ;
}
void F_25 ( struct V_4 * V_5 ,
struct V_33 * V_34 )
{
F_26 ( & V_5 -> V_9 , V_34 ) ;
}
static void F_27 ( struct V_35 * V_36 )
{
struct V_4 * V_5 = V_36 -> V_5 ;
int V_18 ;
int V_37 ;
V_18 = F_28 ( V_36 -> V_36 ) ;
if ( V_36 -> V_20 )
V_18 = ! V_18 ;
if ( V_18 )
V_37 = V_36 -> V_37 ;
else
V_37 = 0 ;
if ( V_36 -> V_38 )
V_37 = V_36 -> V_38 () ;
F_6 ( V_5 , V_37 , V_36 -> V_37 ) ;
}
static T_1 F_29 ( int V_39 , void * V_40 )
{
struct V_35 * V_36 = V_40 ;
struct V_41 * V_42 = V_36 -> V_5 -> V_2 -> V_10 -> V_42 ;
F_30 ( V_36 -> V_43 ) ;
if ( F_31 ( V_42 ) )
F_32 ( V_42 , V_36 -> V_44 + 50 ) ;
F_33 ( & V_36 -> V_45 ,
F_34 ( V_36 -> V_44 ) ) ;
return V_46 ;
}
static void F_35 ( struct V_47 * V_45 )
{
struct V_35 * V_36 ;
V_36 = F_36 ( V_45 , struct V_35 , V_45 . V_45 ) ;
F_27 ( V_36 ) ;
}
int F_37 ( struct V_4 * V_5 , int V_21 ,
struct V_35 * V_48 )
{
int V_24 , V_49 ;
for ( V_24 = 0 ; V_24 < V_21 ; V_24 ++ ) {
if ( ! F_38 ( V_48 [ V_24 ] . V_36 ) ) {
F_21 ( V_31 L_3 ,
V_48 [ V_24 ] . V_36 ) ;
V_49 = - V_32 ;
goto V_50;
}
if ( ! V_48 [ V_24 ] . V_43 ) {
F_21 ( V_31 L_4 ,
V_48 [ V_24 ] . V_36 ) ;
V_49 = - V_32 ;
goto V_50;
}
V_49 = F_39 ( V_48 [ V_24 ] . V_36 , V_48 [ V_24 ] . V_43 ) ;
if ( V_49 )
goto V_50;
V_49 = F_40 ( V_48 [ V_24 ] . V_36 ) ;
if ( V_49 )
goto V_51;
F_41 ( & V_48 [ V_24 ] . V_45 , F_35 ) ;
V_48 [ V_24 ] . V_5 = V_5 ;
V_49 = F_42 ( F_43 ( V_48 [ V_24 ] . V_36 ) ,
F_29 ,
V_52 |
V_53 ,
V_48 [ V_24 ] . V_43 ,
& V_48 [ V_24 ] ) ;
if ( V_49 < 0 )
goto V_51;
if ( V_48 [ V_24 ] . V_54 ) {
V_49 = F_44 ( F_43 ( V_48 [ V_24 ] . V_36 ) , 1 ) ;
if ( V_49 != 0 )
F_21 ( V_31
L_5 ,
V_48 [ V_24 ] . V_36 , V_49 ) ;
}
F_45 ( V_48 [ V_24 ] . V_36 , false ) ;
F_27 ( & V_48 [ V_24 ] ) ;
}
return 0 ;
V_51:
F_46 ( V_48 [ V_24 ] . V_36 ) ;
V_50:
F_47 ( V_5 , V_24 , V_48 ) ;
return V_49 ;
}
void F_47 ( struct V_4 * V_5 , int V_21 ,
struct V_35 * V_48 )
{
int V_24 ;
for ( V_24 = 0 ; V_24 < V_21 ; V_24 ++ ) {
F_48 ( V_48 [ V_24 ] . V_36 ) ;
F_49 ( F_43 ( V_48 [ V_24 ] . V_36 ) , & V_48 [ V_24 ] ) ;
F_50 ( & V_48 [ V_24 ] . V_45 ) ;
F_46 ( V_48 [ V_24 ] . V_36 ) ;
V_48 [ V_24 ] . V_5 = NULL ;
}
}
