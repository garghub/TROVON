int F_1 ( struct V_1 * V_2 , const char * V_3 , int type ,
struct V_4 * V_5 )
{
V_5 -> V_2 = V_2 ;
F_2 ( & V_5 -> V_6 ) ;
F_2 ( & V_5 -> V_7 ) ;
F_3 ( & V_5 -> V_8 ) ;
return F_4 ( V_2 -> V_9 -> V_10 , V_3 , type , & V_5 -> V_5 ) ;
}
void F_5 ( struct V_4 * V_5 , int V_11 , int V_12 )
{
struct V_1 * V_2 ;
struct V_13 * V_14 ;
struct V_15 * V_16 ;
int V_17 ;
int V_18 ;
F_6 ( V_5 , V_12 , V_11 ) ;
if ( ! V_5 )
return;
V_2 = V_5 -> V_2 ;
V_14 = & V_2 -> V_14 ;
F_7 ( & V_2 -> V_19 ) ;
V_18 = V_5 -> V_11 ;
V_5 -> V_11 &= ~ V_12 ;
V_5 -> V_11 |= V_11 & V_12 ;
if ( V_12 && ( V_5 -> V_11 == V_18 ) )
goto V_20;
F_8 ( V_5 , V_11 ) ;
F_9 (pin, &jack->pins, list) {
V_17 = V_16 -> V_12 & V_5 -> V_11 ;
if ( V_16 -> V_21 )
V_17 = ! V_17 ;
if ( V_17 )
F_10 ( V_14 , V_16 -> V_16 ) ;
else
F_11 ( V_14 , V_16 -> V_16 ) ;
}
F_12 ( & V_5 -> V_8 , V_11 , V_5 ) ;
F_13 ( V_14 ) ;
F_14 ( V_5 -> V_5 , V_11 ) ;
V_20:
F_15 ( & V_2 -> V_19 ) ;
}
int F_16 ( struct V_4 * V_5 , int V_22 ,
struct V_23 * V_24 )
{
int V_25 ;
for ( V_25 = 0 ; V_25 < V_22 ; V_25 ++ ) {
F_2 ( & V_24 [ V_25 ] . V_26 ) ;
F_17 ( & ( V_24 [ V_25 ] . V_26 ) , & V_5 -> V_7 ) ;
}
return 0 ;
}
int F_18 ( struct V_4 * V_5 , int V_27 )
{
struct V_23 * V_28 ;
F_9 (zone, &jack->jack_zones, list) {
if ( V_27 >= V_28 -> V_29 &&
V_27 < V_28 -> V_30 )
return V_28 -> V_31 ;
}
return 0 ;
}
int F_19 ( struct V_4 * V_5 , int V_22 ,
struct V_15 * V_6 )
{
int V_25 ;
for ( V_25 = 0 ; V_25 < V_22 ; V_25 ++ ) {
if ( ! V_6 [ V_25 ] . V_16 ) {
F_20 ( V_32 L_1 , V_25 ) ;
return - V_33 ;
}
if ( ! V_6 [ V_25 ] . V_12 ) {
F_20 ( V_32 L_2 , V_25 ,
V_6 [ V_25 ] . V_16 ) ;
return - V_33 ;
}
F_2 ( & V_6 [ V_25 ] . V_26 ) ;
F_17 ( & ( V_6 [ V_25 ] . V_26 ) , & V_5 -> V_6 ) ;
}
F_5 ( V_5 , 0 , 0 ) ;
return 0 ;
}
void F_21 ( struct V_4 * V_5 ,
struct V_34 * V_35 )
{
F_22 ( & V_5 -> V_8 , V_35 ) ;
}
void F_23 ( struct V_4 * V_5 ,
struct V_34 * V_35 )
{
F_24 ( & V_5 -> V_8 , V_35 ) ;
}
static void F_25 ( struct V_36 * V_37 )
{
struct V_4 * V_5 = V_37 -> V_5 ;
int V_17 ;
int V_38 ;
V_17 = F_26 ( V_37 -> V_37 ) ;
if ( V_37 -> V_21 )
V_17 = ! V_17 ;
if ( V_17 )
V_38 = V_37 -> V_38 ;
else
V_38 = 0 ;
if ( V_37 -> V_39 )
V_38 = V_37 -> V_39 () ;
F_5 ( V_5 , V_38 , V_37 -> V_38 ) ;
}
static T_1 F_27 ( int V_40 , void * V_41 )
{
struct V_36 * V_37 = V_41 ;
struct V_42 * V_43 = V_37 -> V_5 -> V_2 -> V_9 -> V_43 ;
F_28 ( V_37 -> V_44 ) ;
if ( F_29 ( V_43 ) )
F_30 ( V_43 , V_37 -> V_45 + 50 ) ;
F_31 ( & V_37 -> V_46 ,
F_32 ( V_37 -> V_45 ) ) ;
return V_47 ;
}
static void F_33 ( struct V_48 * V_46 )
{
struct V_36 * V_37 ;
V_37 = F_34 ( V_46 , struct V_36 , V_46 . V_46 ) ;
F_25 ( V_37 ) ;
}
int F_35 ( struct V_4 * V_5 , int V_22 ,
struct V_36 * V_49 )
{
int V_25 , V_50 ;
for ( V_25 = 0 ; V_25 < V_22 ; V_25 ++ ) {
if ( ! F_36 ( V_49 [ V_25 ] . V_37 ) ) {
F_20 ( V_32 L_3 ,
V_49 [ V_25 ] . V_37 ) ;
V_50 = - V_33 ;
goto V_51;
}
if ( ! V_49 [ V_25 ] . V_44 ) {
F_20 ( V_32 L_4 ,
V_49 [ V_25 ] . V_37 ) ;
V_50 = - V_33 ;
goto V_51;
}
V_50 = F_37 ( V_49 [ V_25 ] . V_37 , V_49 [ V_25 ] . V_44 ) ;
if ( V_50 )
goto V_51;
V_50 = F_38 ( V_49 [ V_25 ] . V_37 ) ;
if ( V_50 )
goto V_52;
F_39 ( & V_49 [ V_25 ] . V_46 , F_33 ) ;
V_49 [ V_25 ] . V_5 = V_5 ;
V_50 = F_40 ( F_41 ( V_49 [ V_25 ] . V_37 ) ,
F_27 ,
V_53 |
V_54 ,
V_49 [ V_25 ] . V_44 ,
& V_49 [ V_25 ] ) ;
if ( V_50 )
goto V_52;
if ( V_49 [ V_25 ] . V_55 ) {
V_50 = F_42 ( F_41 ( V_49 [ V_25 ] . V_37 ) , 1 ) ;
if ( V_50 != 0 )
F_20 ( V_32
L_5 ,
V_49 [ V_25 ] . V_37 , V_50 ) ;
}
#ifdef F_43
F_44 ( V_49 [ V_25 ] . V_37 , false ) ;
#endif
F_25 ( & V_49 [ V_25 ] ) ;
}
return 0 ;
V_52:
F_45 ( V_49 [ V_25 ] . V_37 ) ;
V_51:
F_46 ( V_5 , V_25 , V_49 ) ;
return V_50 ;
}
void F_46 ( struct V_4 * V_5 , int V_22 ,
struct V_36 * V_49 )
{
int V_25 ;
for ( V_25 = 0 ; V_25 < V_22 ; V_25 ++ ) {
#ifdef F_43
F_47 ( V_49 [ V_25 ] . V_37 ) ;
#endif
F_48 ( F_41 ( V_49 [ V_25 ] . V_37 ) , & V_49 [ V_25 ] ) ;
F_49 ( & V_49 [ V_25 ] . V_46 ) ;
F_45 ( V_49 [ V_25 ] . V_37 ) ;
V_49 [ V_25 ] . V_5 = NULL ;
}
}
