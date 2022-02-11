int F_1 ( struct V_1 * V_2 , const char * V_3 , int type ,
struct V_4 * V_5 , struct V_6 * V_7 ,
unsigned int V_8 )
{
int V_9 ;
F_2 ( & V_5 -> V_10 ) ;
V_5 -> V_2 = V_2 ;
F_3 ( & V_5 -> V_7 ) ;
F_3 ( & V_5 -> V_11 ) ;
F_4 ( & V_5 -> V_12 ) ;
V_9 = F_5 ( V_2 -> V_13 , V_3 , type , & V_5 -> V_5 ) ;
if ( V_9 )
return V_9 ;
if ( V_8 )
return F_6 ( V_5 , V_8 , V_7 ) ;
return 0 ;
}
void F_7 ( struct V_4 * V_5 , int V_14 , int V_15 )
{
struct V_16 * V_17 ;
struct V_6 * V_18 ;
unsigned int V_19 = 0 ;
int V_20 ;
F_8 ( V_5 , V_15 , V_14 ) ;
if ( ! V_5 )
return;
V_17 = & V_5 -> V_2 -> V_17 ;
F_9 ( & V_5 -> V_10 ) ;
V_5 -> V_14 &= ~ V_15 ;
V_5 -> V_14 |= V_14 & V_15 ;
F_10 ( V_5 , V_14 ) ;
F_11 (pin, &jack->pins, list) {
V_20 = V_18 -> V_15 & V_5 -> V_14 ;
if ( V_18 -> V_21 )
V_20 = ! V_20 ;
if ( V_20 )
F_12 ( V_17 , V_18 -> V_18 ) ;
else
F_13 ( V_17 , V_18 -> V_18 ) ;
V_19 = 1 ;
}
F_14 ( & V_5 -> V_12 , V_5 -> V_14 , V_5 ) ;
if ( V_19 )
F_15 ( V_17 ) ;
F_16 ( V_5 -> V_5 , V_5 -> V_14 ) ;
F_17 ( & V_5 -> V_10 ) ;
}
int F_18 ( struct V_4 * V_5 , int V_22 ,
struct V_23 * V_24 )
{
int V_25 ;
for ( V_25 = 0 ; V_25 < V_22 ; V_25 ++ ) {
F_3 ( & V_24 [ V_25 ] . V_26 ) ;
F_19 ( & ( V_24 [ V_25 ] . V_26 ) , & V_5 -> V_11 ) ;
}
return 0 ;
}
int F_20 ( struct V_4 * V_5 , int V_27 )
{
struct V_23 * V_28 ;
F_11 (zone, &jack->jack_zones, list) {
if ( V_27 >= V_28 -> V_29 &&
V_27 < V_28 -> V_30 )
return V_28 -> V_31 ;
}
return 0 ;
}
int F_6 ( struct V_4 * V_5 , int V_22 ,
struct V_6 * V_7 )
{
int V_25 ;
for ( V_25 = 0 ; V_25 < V_22 ; V_25 ++ ) {
if ( ! V_7 [ V_25 ] . V_18 ) {
F_21 ( V_5 -> V_2 -> V_32 , L_1 ,
V_25 ) ;
return - V_33 ;
}
if ( ! V_7 [ V_25 ] . V_15 ) {
F_21 ( V_5 -> V_2 -> V_32 , L_2
L_3 , V_25 , V_7 [ V_25 ] . V_18 ) ;
return - V_33 ;
}
F_3 ( & V_7 [ V_25 ] . V_26 ) ;
F_19 ( & ( V_7 [ V_25 ] . V_26 ) , & V_5 -> V_7 ) ;
}
F_7 ( V_5 , 0 , 0 ) ;
return 0 ;
}
void F_22 ( struct V_4 * V_5 ,
struct V_34 * V_35 )
{
F_23 ( & V_5 -> V_12 , V_35 ) ;
}
void F_24 ( struct V_4 * V_5 ,
struct V_34 * V_35 )
{
F_25 ( & V_5 -> V_12 , V_35 ) ;
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
F_7 ( V_5 , V_38 , V_37 -> V_38 ) ;
}
static T_1 F_28 ( int V_42 , void * V_41 )
{
struct V_36 * V_37 = V_41 ;
struct V_43 * V_32 = V_37 -> V_5 -> V_2 -> V_32 ;
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
int V_25 , V_9 ;
for ( V_25 = 0 ; V_25 < V_22 ; V_25 ++ ) {
if ( ! V_50 [ V_25 ] . V_44 ) {
F_21 ( V_5 -> V_2 -> V_32 ,
L_4 , V_25 ) ;
V_9 = - V_33 ;
goto V_51;
}
if ( V_50 [ V_25 ] . V_52 ) {
V_50 [ V_25 ] . V_39 = F_37 ( V_50 [ V_25 ] . V_52 ,
V_50 [ V_25 ] . V_44 ,
V_50 [ V_25 ] . V_53 , V_54 ) ;
if ( F_38 ( V_50 [ V_25 ] . V_39 ) ) {
V_9 = F_39 ( V_50 [ V_25 ] . V_39 ) ;
F_21 ( V_50 [ V_25 ] . V_52 ,
L_5 ,
V_25 , V_9 ) ;
goto V_51;
}
} else {
if ( ! F_40 ( V_50 [ V_25 ] . V_37 ) ) {
F_21 ( V_5 -> V_2 -> V_32 ,
L_6 ,
V_50 [ V_25 ] . V_37 ) ;
V_9 = - V_33 ;
goto V_51;
}
V_9 = F_41 ( V_50 [ V_25 ] . V_37 , V_55 ,
V_50 [ V_25 ] . V_44 ) ;
if ( V_9 )
goto V_51;
V_50 [ V_25 ] . V_39 = F_42 ( V_50 [ V_25 ] . V_37 ) ;
}
F_43 ( & V_50 [ V_25 ] . V_47 , F_34 ) ;
V_50 [ V_25 ] . V_5 = V_5 ;
V_9 = F_44 ( F_45 ( V_50 [ V_25 ] . V_39 ) ,
F_28 ,
V_56 |
V_57 ,
V_50 [ V_25 ] . V_44 ,
& V_50 [ V_25 ] ) ;
if ( V_9 < 0 )
goto V_58;
if ( V_50 [ V_25 ] . V_59 ) {
V_9 = F_46 ( F_45 ( V_50 [ V_25 ] . V_39 ) , 1 ) ;
if ( V_9 != 0 )
F_21 ( V_5 -> V_2 -> V_32 ,
L_7 ,
V_25 , V_9 ) ;
}
F_47 ( V_50 [ V_25 ] . V_39 , false ) ;
F_48 ( & V_50 [ V_25 ] . V_47 ,
F_33 ( V_50 [ V_25 ] . V_45 ) ) ;
}
return 0 ;
V_58:
F_49 ( V_50 [ V_25 ] . V_37 ) ;
V_51:
F_50 ( V_5 , V_25 , V_50 ) ;
return V_9 ;
}
int F_51 ( struct V_43 * V_52 ,
struct V_4 * V_5 ,
int V_22 , struct V_36 * V_50 )
{
int V_25 ;
for ( V_25 = 0 ; V_25 < V_22 ; V_25 ++ )
V_50 [ V_25 ] . V_52 = V_52 ;
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
