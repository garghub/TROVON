int F_1 ( struct V_1 * V_2 , const char * V_3 , int type ,
struct V_4 * V_5 )
{
F_2 ( & V_5 -> V_6 ) ;
V_5 -> V_2 = V_2 ;
F_3 ( & V_5 -> V_7 ) ;
F_3 ( & V_5 -> V_8 ) ;
F_4 ( & V_5 -> V_9 ) ;
return F_5 ( V_2 -> V_10 . V_11 -> V_12 , V_3 , type , & V_5 -> V_5 ) ;
}
void F_6 ( struct V_4 * V_5 , int V_13 , int V_14 )
{
struct V_1 * V_2 ;
struct V_15 * V_16 ;
struct V_17 * V_18 ;
unsigned int V_19 = 0 ;
int V_20 ;
F_7 ( V_5 , V_14 , V_13 ) ;
if ( ! V_5 )
return;
V_2 = V_5 -> V_2 ;
V_16 = & V_2 -> V_16 ;
F_8 ( & V_5 -> V_6 ) ;
V_5 -> V_13 &= ~ V_14 ;
V_5 -> V_13 |= V_13 & V_14 ;
F_9 ( V_5 , V_13 ) ;
F_10 (pin, &jack->pins, list) {
V_20 = V_18 -> V_14 & V_5 -> V_13 ;
if ( V_18 -> V_21 )
V_20 = ! V_20 ;
if ( V_20 )
F_11 ( V_16 , V_18 -> V_18 ) ;
else
F_12 ( V_16 , V_18 -> V_18 ) ;
V_19 = 1 ;
}
F_13 ( & V_5 -> V_9 , V_5 -> V_13 , V_5 ) ;
if ( V_19 )
F_14 ( V_16 ) ;
F_15 ( V_5 -> V_5 , V_5 -> V_13 ) ;
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
struct V_17 * V_7 )
{
int V_25 ;
for ( V_25 = 0 ; V_25 < V_22 ; V_25 ++ ) {
if ( ! V_7 [ V_25 ] . V_18 ) {
F_21 ( V_5 -> V_2 -> V_32 , L_1 ,
V_25 ) ;
return - V_33 ;
}
if ( ! V_7 [ V_25 ] . V_14 ) {
F_21 ( V_5 -> V_2 -> V_32 , L_2
L_3 , V_25 , V_7 [ V_25 ] . V_18 ) ;
return - V_33 ;
}
F_3 ( & V_7 [ V_25 ] . V_26 ) ;
F_18 ( & ( V_7 [ V_25 ] . V_26 ) , & V_5 -> V_7 ) ;
}
F_6 ( V_5 , 0 , 0 ) ;
return 0 ;
}
void F_22 ( struct V_4 * V_5 ,
struct V_34 * V_35 )
{
F_23 ( & V_5 -> V_9 , V_35 ) ;
}
void F_24 ( struct V_4 * V_5 ,
struct V_34 * V_35 )
{
F_25 ( & V_5 -> V_9 , V_35 ) ;
}
static void F_26 ( struct V_36 * V_37 )
{
struct V_4 * V_5 = V_37 -> V_5 ;
int V_20 ;
int V_38 ;
V_20 = F_27 ( V_37 -> V_39 ) ;
if ( V_37 -> V_21 )
V_20 = ! V_20 ;
if ( V_20 )
V_38 = V_37 -> V_38 ;
else
V_38 = 0 ;
if ( V_37 -> V_40 )
V_38 = V_37 -> V_40 ( V_37 -> V_41 ) ;
F_6 ( V_5 , V_38 , V_37 -> V_38 ) ;
}
static T_1 F_28 ( int V_42 , void * V_41 )
{
struct V_36 * V_37 = V_41 ;
struct V_43 * V_32 = V_37 -> V_5 -> V_2 -> V_10 . V_11 -> V_32 ;
F_29 ( V_37 -> V_44 ) ;
if ( F_30 ( V_32 ) )
F_31 ( V_32 , V_37 -> V_45 + 50 ) ;
F_32 ( V_46 , & V_37 -> V_47 ,
F_33 ( V_37 -> V_45 ) ) ;
return V_48 ;
}
static void F_34 ( struct V_49 * V_47 )
{
struct V_36 * V_37 ;
V_37 = F_35 ( V_47 , struct V_36 , V_47 . V_47 ) ;
F_26 ( V_37 ) ;
}
int F_36 ( struct V_4 * V_5 , int V_22 ,
struct V_36 * V_50 )
{
int V_25 , V_51 ;
for ( V_25 = 0 ; V_25 < V_22 ; V_25 ++ ) {
if ( ! V_50 [ V_25 ] . V_44 ) {
F_21 ( V_5 -> V_2 -> V_32 ,
L_4 , V_25 ) ;
V_51 = - V_33 ;
goto V_52;
}
if ( V_50 [ V_25 ] . V_53 ) {
V_50 [ V_25 ] . V_39 = F_37 ( V_50 [ V_25 ] . V_53 ,
V_50 [ V_25 ] . V_44 ,
V_50 [ V_25 ] . V_54 , V_55 ) ;
if ( F_38 ( V_50 [ V_25 ] . V_39 ) ) {
V_51 = F_39 ( V_50 [ V_25 ] . V_39 ) ;
F_21 ( V_50 [ V_25 ] . V_53 ,
L_5 ,
V_25 , V_51 ) ;
goto V_52;
}
} else {
if ( ! F_40 ( V_50 [ V_25 ] . V_37 ) ) {
F_21 ( V_5 -> V_2 -> V_32 ,
L_6 ,
V_50 [ V_25 ] . V_37 ) ;
V_51 = - V_33 ;
goto V_52;
}
V_51 = F_41 ( V_50 [ V_25 ] . V_37 , V_56 ,
V_50 [ V_25 ] . V_44 ) ;
if ( V_51 )
goto V_52;
V_50 [ V_25 ] . V_39 = F_42 ( V_50 [ V_25 ] . V_37 ) ;
}
F_43 ( & V_50 [ V_25 ] . V_47 , F_34 ) ;
V_50 [ V_25 ] . V_5 = V_5 ;
V_51 = F_44 ( F_45 ( V_50 [ V_25 ] . V_39 ) ,
F_28 ,
V_57 |
V_58 ,
V_50 [ V_25 ] . V_44 ,
& V_50 [ V_25 ] ) ;
if ( V_51 < 0 )
goto V_59;
if ( V_50 [ V_25 ] . V_60 ) {
V_51 = F_46 ( F_45 ( V_50 [ V_25 ] . V_39 ) , 1 ) ;
if ( V_51 != 0 )
F_21 ( V_5 -> V_2 -> V_32 ,
L_7 ,
V_25 , V_51 ) ;
}
F_47 ( V_50 [ V_25 ] . V_39 , false ) ;
F_48 ( & V_50 [ V_25 ] . V_47 ,
F_33 ( V_50 [ V_25 ] . V_45 ) ) ;
}
return 0 ;
V_59:
F_49 ( V_50 [ V_25 ] . V_37 ) ;
V_52:
F_50 ( V_5 , V_25 , V_50 ) ;
return V_51 ;
}
int F_51 ( struct V_43 * V_53 ,
struct V_4 * V_5 ,
int V_22 , struct V_36 * V_50 )
{
int V_25 ;
for ( V_25 = 0 ; V_25 < V_22 ; V_25 ++ )
V_50 [ V_25 ] . V_53 = V_53 ;
return F_36 ( V_5 , V_22 , V_50 ) ;
}
void F_50 ( struct V_4 * V_5 , int V_22 ,
struct V_36 * V_50 )
{
int V_25 ;
for ( V_25 = 0 ; V_25 < V_22 ; V_25 ++ ) {
F_52 ( V_50 [ V_25 ] . V_39 ) ;
F_53 ( F_45 ( V_50 [ V_25 ] . V_39 ) , & V_50 [ V_25 ] ) ;
F_54 ( & V_50 [ V_25 ] . V_47 ) ;
F_55 ( V_50 [ V_25 ] . V_39 ) ;
V_50 [ V_25 ] . V_5 = NULL ;
}
}
