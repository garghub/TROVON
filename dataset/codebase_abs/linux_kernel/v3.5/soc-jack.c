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
if ( V_13 && ( V_5 -> V_12 == V_19 ) )
goto V_20;
F_9 ( V_5 , V_12 ) ;
F_10 (pin, &jack->pins, list) {
V_18 = V_17 -> V_13 & V_5 -> V_12 ;
if ( V_17 -> V_21 )
V_18 = ! V_18 ;
if ( V_18 )
F_11 ( V_15 , V_17 -> V_17 ) ;
else
F_12 ( V_15 , V_17 -> V_17 ) ;
}
F_13 ( & V_5 -> V_9 , V_12 , V_5 ) ;
F_14 ( V_15 ) ;
F_15 ( V_5 -> V_5 , V_5 -> V_12 ) ;
V_20:
F_16 ( & V_5 -> V_6 ) ;
}
int F_17 ( struct V_4 * V_5 , int V_22 ,
struct V_23 * V_24 )
{
int V_25 ;
for ( V_25 = 0 ; V_25 < V_22 ; V_25 ++ ) {
F_3 ( & V_24 [ V_25 ] . V_26 ) ;
F_18 ( & ( V_24 [ V_25 ] . V_26 ) , & V_5 -> V_8 ) ;
}
return 0 ;
}
int F_19 ( struct V_4 * V_5 , int V_27 )
{
struct V_23 * V_28 ;
F_10 (zone, &jack->jack_zones, list) {
if ( V_27 >= V_28 -> V_29 &&
V_27 < V_28 -> V_30 )
return V_28 -> V_31 ;
}
return 0 ;
}
int F_20 ( struct V_4 * V_5 , int V_22 ,
struct V_16 * V_7 )
{
int V_25 ;
for ( V_25 = 0 ; V_25 < V_22 ; V_25 ++ ) {
if ( ! V_7 [ V_25 ] . V_17 ) {
F_21 ( V_32 L_1 , V_25 ) ;
return - V_33 ;
}
if ( ! V_7 [ V_25 ] . V_13 ) {
F_21 ( V_32 L_2 , V_25 ,
V_7 [ V_25 ] . V_17 ) ;
return - V_33 ;
}
F_3 ( & V_7 [ V_25 ] . V_26 ) ;
F_18 ( & ( V_7 [ V_25 ] . V_26 ) , & V_5 -> V_7 ) ;
}
F_22 ( & V_5 -> V_2 -> V_10 -> V_15 ) ;
F_6 ( V_5 , 0 , 0 ) ;
return 0 ;
}
void F_23 ( struct V_4 * V_5 ,
struct V_34 * V_35 )
{
F_24 ( & V_5 -> V_9 , V_35 ) ;
}
void F_25 ( struct V_4 * V_5 ,
struct V_34 * V_35 )
{
F_26 ( & V_5 -> V_9 , V_35 ) ;
}
static void F_27 ( struct V_36 * V_37 )
{
struct V_4 * V_5 = V_37 -> V_5 ;
int V_18 ;
int V_38 ;
V_18 = F_28 ( V_37 -> V_37 ) ;
if ( V_37 -> V_21 )
V_18 = ! V_18 ;
if ( V_18 )
V_38 = V_37 -> V_38 ;
else
V_38 = 0 ;
if ( V_37 -> V_39 )
V_38 = V_37 -> V_39 () ;
F_6 ( V_5 , V_38 , V_37 -> V_38 ) ;
}
static T_1 F_29 ( int V_40 , void * V_41 )
{
struct V_36 * V_37 = V_41 ;
struct V_42 * V_43 = V_37 -> V_5 -> V_2 -> V_10 -> V_43 ;
F_30 ( V_37 -> V_44 ) ;
if ( F_31 ( V_43 ) )
F_32 ( V_43 , V_37 -> V_45 + 50 ) ;
F_33 ( & V_37 -> V_46 ,
F_34 ( V_37 -> V_45 ) ) ;
return V_47 ;
}
static void F_35 ( struct V_48 * V_46 )
{
struct V_36 * V_37 ;
V_37 = F_36 ( V_46 , struct V_36 , V_46 . V_46 ) ;
F_27 ( V_37 ) ;
}
int F_37 ( struct V_4 * V_5 , int V_22 ,
struct V_36 * V_49 )
{
int V_25 , V_50 ;
for ( V_25 = 0 ; V_25 < V_22 ; V_25 ++ ) {
if ( ! F_38 ( V_49 [ V_25 ] . V_37 ) ) {
F_21 ( V_32 L_3 ,
V_49 [ V_25 ] . V_37 ) ;
V_50 = - V_33 ;
goto V_51;
}
if ( ! V_49 [ V_25 ] . V_44 ) {
F_21 ( V_32 L_4 ,
V_49 [ V_25 ] . V_37 ) ;
V_50 = - V_33 ;
goto V_51;
}
V_50 = F_39 ( V_49 [ V_25 ] . V_37 , V_49 [ V_25 ] . V_44 ) ;
if ( V_50 )
goto V_51;
V_50 = F_40 ( V_49 [ V_25 ] . V_37 ) ;
if ( V_50 )
goto V_52;
F_41 ( & V_49 [ V_25 ] . V_46 , F_35 ) ;
V_49 [ V_25 ] . V_5 = V_5 ;
V_50 = F_42 ( F_43 ( V_49 [ V_25 ] . V_37 ) ,
F_29 ,
V_53 |
V_54 ,
V_49 [ V_25 ] . V_44 ,
& V_49 [ V_25 ] ) ;
if ( V_50 < 0 )
goto V_52;
if ( V_49 [ V_25 ] . V_55 ) {
V_50 = F_44 ( F_43 ( V_49 [ V_25 ] . V_37 ) , 1 ) ;
if ( V_50 != 0 )
F_21 ( V_32
L_5 ,
V_49 [ V_25 ] . V_37 , V_50 ) ;
}
F_45 ( V_49 [ V_25 ] . V_37 , false ) ;
F_27 ( & V_49 [ V_25 ] ) ;
}
return 0 ;
V_52:
F_46 ( V_49 [ V_25 ] . V_37 ) ;
V_51:
F_47 ( V_5 , V_25 , V_49 ) ;
return V_50 ;
}
void F_47 ( struct V_4 * V_5 , int V_22 ,
struct V_36 * V_49 )
{
int V_25 ;
for ( V_25 = 0 ; V_25 < V_22 ; V_25 ++ ) {
F_48 ( V_49 [ V_25 ] . V_37 ) ;
F_49 ( F_43 ( V_49 [ V_25 ] . V_37 ) , & V_49 [ V_25 ] ) ;
F_50 ( & V_49 [ V_25 ] . V_46 ) ;
F_46 ( V_49 [ V_25 ] . V_37 ) ;
V_49 [ V_25 ] . V_5 = NULL ;
}
}
