int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , void * V_5 )
{
if ( V_2 -> V_6 -> V_7 )
return V_2 -> V_6 -> V_7 ( V_2 , V_4 , V_5 ) ;
else
return - V_8 ;
}
int F_2 ( struct V_9 * V_10 , const char * V_11 , int type ,
struct V_3 * V_4 , struct V_12 * V_13 ,
unsigned int V_14 )
{
int V_15 ;
F_3 ( & V_4 -> V_16 ) ;
V_4 -> V_10 = V_10 ;
F_4 ( & V_4 -> V_13 ) ;
F_4 ( & V_4 -> V_17 ) ;
F_5 ( & V_4 -> V_18 ) ;
V_15 = F_6 ( V_10 -> V_19 , V_11 , type , & V_4 -> V_4 , false , false ) ;
if ( V_15 )
return V_15 ;
if ( V_14 )
return F_7 ( V_4 , V_14 , V_13 ) ;
return 0 ;
}
void F_8 ( struct V_3 * V_4 , int V_20 , int V_21 )
{
struct V_22 * V_23 ;
struct V_12 * V_24 ;
unsigned int V_25 = 0 ;
int V_26 ;
F_9 ( V_4 , V_21 , V_20 ) ;
if ( ! V_4 )
return;
V_23 = & V_4 -> V_10 -> V_23 ;
F_10 ( & V_4 -> V_16 ) ;
V_4 -> V_20 &= ~ V_21 ;
V_4 -> V_20 |= V_20 & V_21 ;
F_11 ( V_4 , V_20 ) ;
F_12 (pin, &jack->pins, list) {
V_26 = V_24 -> V_21 & V_4 -> V_20 ;
if ( V_24 -> V_27 )
V_26 = ! V_26 ;
if ( V_26 )
F_13 ( V_23 , V_24 -> V_24 ) ;
else
F_14 ( V_23 , V_24 -> V_24 ) ;
V_25 = 1 ;
}
F_15 ( & V_4 -> V_18 , V_4 -> V_20 , V_4 ) ;
if ( V_25 )
F_16 ( V_23 ) ;
F_17 ( V_4 -> V_4 , V_4 -> V_20 ) ;
F_18 ( & V_4 -> V_16 ) ;
}
int F_19 ( struct V_3 * V_4 , int V_28 ,
struct V_29 * V_30 )
{
int V_31 ;
for ( V_31 = 0 ; V_31 < V_28 ; V_31 ++ ) {
F_4 ( & V_30 [ V_31 ] . V_32 ) ;
F_20 ( & ( V_30 [ V_31 ] . V_32 ) , & V_4 -> V_17 ) ;
}
return 0 ;
}
int F_21 ( struct V_3 * V_4 , int V_33 )
{
struct V_29 * V_34 ;
F_12 (zone, &jack->jack_zones, list) {
if ( V_33 >= V_34 -> V_35 &&
V_33 < V_34 -> V_36 )
return V_34 -> V_37 ;
}
return 0 ;
}
int F_7 ( struct V_3 * V_4 , int V_28 ,
struct V_12 * V_13 )
{
int V_31 ;
for ( V_31 = 0 ; V_31 < V_28 ; V_31 ++ ) {
if ( ! V_13 [ V_31 ] . V_24 ) {
F_22 ( V_4 -> V_10 -> V_38 , L_1 ,
V_31 ) ;
return - V_8 ;
}
if ( ! V_13 [ V_31 ] . V_21 ) {
F_22 ( V_4 -> V_10 -> V_38 , L_2
L_3 , V_31 , V_13 [ V_31 ] . V_24 ) ;
return - V_8 ;
}
F_4 ( & V_13 [ V_31 ] . V_32 ) ;
F_20 ( & ( V_13 [ V_31 ] . V_32 ) , & V_4 -> V_13 ) ;
F_23 ( V_4 -> V_4 , V_13 [ V_31 ] . V_24 , V_13 [ V_31 ] . V_21 ) ;
}
F_8 ( V_4 , 0 , 0 ) ;
return 0 ;
}
void F_24 ( struct V_3 * V_4 ,
struct V_39 * V_40 )
{
F_25 ( & V_4 -> V_18 , V_40 ) ;
}
void F_26 ( struct V_3 * V_4 ,
struct V_39 * V_40 )
{
F_27 ( & V_4 -> V_18 , V_40 ) ;
}
static void F_28 ( struct V_41 * V_42 )
{
struct V_3 * V_4 = V_42 -> V_4 ;
int V_26 ;
int V_43 ;
V_26 = F_29 ( V_42 -> V_44 ) ;
if ( V_42 -> V_27 )
V_26 = ! V_26 ;
if ( V_26 )
V_43 = V_42 -> V_43 ;
else
V_43 = 0 ;
if ( V_42 -> V_45 )
V_43 = V_42 -> V_45 ( V_42 -> V_5 ) ;
F_8 ( V_4 , V_43 , V_42 -> V_43 ) ;
}
static T_1 F_30 ( int V_46 , void * V_5 )
{
struct V_41 * V_42 = V_5 ;
struct V_47 * V_38 = V_42 -> V_4 -> V_10 -> V_38 ;
F_31 ( V_42 -> V_48 ) ;
if ( F_32 ( V_38 ) )
F_33 ( V_38 , V_42 -> V_49 + 50 ) ;
F_34 ( V_50 , & V_42 -> V_51 ,
F_35 ( V_42 -> V_49 ) ) ;
return V_52 ;
}
static void F_36 ( struct V_53 * V_51 )
{
struct V_41 * V_42 ;
V_42 = F_37 ( V_51 , struct V_41 , V_51 . V_51 ) ;
F_28 ( V_42 ) ;
}
static int F_38 ( struct V_39 * V_40 ,
unsigned long V_54 , void * V_5 )
{
struct V_41 * V_42 =
F_37 ( V_40 , struct V_41 , V_55 ) ;
switch ( V_54 ) {
case V_56 :
case V_57 :
case V_58 :
F_34 ( V_50 , & V_42 -> V_51 , 0 ) ;
break;
}
return V_59 ;
}
int F_39 ( struct V_3 * V_4 , int V_28 ,
struct V_41 * V_60 )
{
int V_31 , V_15 ;
for ( V_31 = 0 ; V_31 < V_28 ; V_31 ++ ) {
if ( ! V_60 [ V_31 ] . V_48 ) {
F_22 ( V_4 -> V_10 -> V_38 ,
L_4 , V_31 ) ;
V_15 = - V_8 ;
goto V_61;
}
if ( V_60 [ V_31 ] . V_44 ) {
goto V_62;
} else if ( V_60 [ V_31 ] . V_63 ) {
V_60 [ V_31 ] . V_44 = F_40 ( V_60 [ V_31 ] . V_63 ,
V_60 [ V_31 ] . V_48 ,
V_60 [ V_31 ] . V_64 , V_65 ) ;
if ( F_41 ( V_60 [ V_31 ] . V_44 ) ) {
V_15 = F_42 ( V_60 [ V_31 ] . V_44 ) ;
F_22 ( V_60 [ V_31 ] . V_63 ,
L_5 ,
V_31 , V_15 ) ;
goto V_61;
}
} else {
if ( ! F_43 ( V_60 [ V_31 ] . V_42 ) ) {
F_22 ( V_4 -> V_10 -> V_38 ,
L_6 ,
V_60 [ V_31 ] . V_42 ) ;
V_15 = - V_8 ;
goto V_61;
}
V_15 = F_44 ( V_60 [ V_31 ] . V_42 , V_66 ,
V_60 [ V_31 ] . V_48 ) ;
if ( V_15 )
goto V_61;
V_60 [ V_31 ] . V_44 = F_45 ( V_60 [ V_31 ] . V_42 ) ;
}
V_62:
F_46 ( & V_60 [ V_31 ] . V_51 , F_36 ) ;
V_60 [ V_31 ] . V_4 = V_4 ;
V_15 = F_47 ( F_48 ( V_60 [ V_31 ] . V_44 ) ,
F_30 ,
V_67 |
V_68 ,
V_60 [ V_31 ] . V_48 ,
& V_60 [ V_31 ] ) ;
if ( V_15 < 0 )
goto V_69;
if ( V_60 [ V_31 ] . V_70 ) {
V_15 = F_49 ( F_48 ( V_60 [ V_31 ] . V_44 ) , 1 ) ;
if ( V_15 != 0 )
F_22 ( V_4 -> V_10 -> V_38 ,
L_7 ,
V_31 , V_15 ) ;
}
V_60 [ V_31 ] . V_55 . V_71 = F_38 ;
F_50 ( & V_60 [ V_31 ] . V_55 ) ;
F_51 ( V_60 [ V_31 ] . V_44 , false ) ;
F_52 ( & V_60 [ V_31 ] . V_51 ,
F_35 ( V_60 [ V_31 ] . V_49 ) ) ;
}
return 0 ;
V_69:
F_53 ( V_60 [ V_31 ] . V_42 ) ;
V_61:
F_54 ( V_4 , V_31 , V_60 ) ;
return V_15 ;
}
int F_55 ( struct V_47 * V_63 ,
struct V_3 * V_4 ,
int V_28 , struct V_41 * V_60 )
{
int V_31 ;
for ( V_31 = 0 ; V_31 < V_28 ; V_31 ++ )
V_60 [ V_31 ] . V_63 = V_63 ;
return F_39 ( V_4 , V_28 , V_60 ) ;
}
void F_54 ( struct V_3 * V_4 , int V_28 ,
struct V_41 * V_60 )
{
int V_31 ;
for ( V_31 = 0 ; V_31 < V_28 ; V_31 ++ ) {
F_56 ( V_60 [ V_31 ] . V_44 ) ;
F_57 ( & V_60 [ V_31 ] . V_55 ) ;
F_58 ( F_48 ( V_60 [ V_31 ] . V_44 ) , & V_60 [ V_31 ] ) ;
F_59 ( & V_60 [ V_31 ] . V_51 ) ;
F_60 ( V_60 [ V_31 ] . V_44 ) ;
V_60 [ V_31 ] . V_4 = NULL ;
}
}
