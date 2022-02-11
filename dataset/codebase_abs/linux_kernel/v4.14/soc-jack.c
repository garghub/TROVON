int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , void * V_5 )
{
if ( V_2 -> V_6 -> V_7 )
return V_2 -> V_6 -> V_7 ( V_2 , V_4 , V_5 ) ;
else
return - V_8 ;
}
int F_2 ( struct V_9 * V_10 ,
struct V_3 * V_4 , void * V_5 )
{
if ( V_10 -> V_7 )
return V_10 -> V_7 ( V_10 , V_4 , V_5 ) ;
if ( V_10 -> V_6 -> V_7 )
return V_10 -> V_6 -> V_7 ( V_10 , V_4 , V_5 ) ;
return - V_8 ;
}
int F_3 ( struct V_11 * V_12 , const char * V_13 , int type ,
struct V_3 * V_4 , struct V_14 * V_15 ,
unsigned int V_16 )
{
int V_17 ;
F_4 ( & V_4 -> V_18 ) ;
V_4 -> V_12 = V_12 ;
F_5 ( & V_4 -> V_15 ) ;
F_5 ( & V_4 -> V_19 ) ;
F_6 ( & V_4 -> V_20 ) ;
V_17 = F_7 ( V_12 -> V_21 , V_13 , type , & V_4 -> V_4 , false , false ) ;
if ( V_17 )
return V_17 ;
if ( V_16 )
return F_8 ( V_4 , V_16 , V_15 ) ;
return 0 ;
}
void F_9 ( struct V_3 * V_4 , int V_22 , int V_23 )
{
struct V_24 * V_25 ;
struct V_14 * V_26 ;
unsigned int V_27 = 0 ;
int V_28 ;
F_10 ( V_4 , V_23 , V_22 ) ;
if ( ! V_4 )
return;
V_25 = & V_4 -> V_12 -> V_25 ;
F_11 ( & V_4 -> V_18 ) ;
V_4 -> V_22 &= ~ V_23 ;
V_4 -> V_22 |= V_22 & V_23 ;
F_12 ( V_4 , V_22 ) ;
F_13 (pin, &jack->pins, list) {
V_28 = V_26 -> V_23 & V_4 -> V_22 ;
if ( V_26 -> V_29 )
V_28 = ! V_28 ;
if ( V_28 )
F_14 ( V_25 , V_26 -> V_26 ) ;
else
F_15 ( V_25 , V_26 -> V_26 ) ;
V_27 = 1 ;
}
F_16 ( & V_4 -> V_20 , V_4 -> V_22 , V_4 ) ;
if ( V_27 )
F_17 ( V_25 ) ;
F_18 ( V_4 -> V_4 , V_4 -> V_22 ) ;
F_19 ( & V_4 -> V_18 ) ;
}
int F_20 ( struct V_3 * V_4 , int V_30 ,
struct V_31 * V_32 )
{
int V_33 ;
for ( V_33 = 0 ; V_33 < V_30 ; V_33 ++ ) {
F_5 ( & V_32 [ V_33 ] . V_34 ) ;
F_21 ( & ( V_32 [ V_33 ] . V_34 ) , & V_4 -> V_19 ) ;
}
return 0 ;
}
int F_22 ( struct V_3 * V_4 , int V_35 )
{
struct V_31 * V_36 ;
F_13 (zone, &jack->jack_zones, list) {
if ( V_35 >= V_36 -> V_37 &&
V_35 < V_36 -> V_38 )
return V_36 -> V_39 ;
}
return 0 ;
}
int F_8 ( struct V_3 * V_4 , int V_30 ,
struct V_14 * V_15 )
{
int V_33 ;
for ( V_33 = 0 ; V_33 < V_30 ; V_33 ++ ) {
if ( ! V_15 [ V_33 ] . V_26 ) {
F_23 ( V_4 -> V_12 -> V_40 , L_1 ,
V_33 ) ;
return - V_41 ;
}
if ( ! V_15 [ V_33 ] . V_23 ) {
F_23 ( V_4 -> V_12 -> V_40 , L_2
L_3 , V_33 , V_15 [ V_33 ] . V_26 ) ;
return - V_41 ;
}
F_5 ( & V_15 [ V_33 ] . V_34 ) ;
F_21 ( & ( V_15 [ V_33 ] . V_34 ) , & V_4 -> V_15 ) ;
F_24 ( V_4 -> V_4 , V_15 [ V_33 ] . V_26 , V_15 [ V_33 ] . V_23 ) ;
}
F_9 ( V_4 , 0 , 0 ) ;
return 0 ;
}
void F_25 ( struct V_3 * V_4 ,
struct V_42 * V_43 )
{
F_26 ( & V_4 -> V_20 , V_43 ) ;
}
void F_27 ( struct V_3 * V_4 ,
struct V_42 * V_43 )
{
F_28 ( & V_4 -> V_20 , V_43 ) ;
}
static void F_29 ( struct V_44 * V_45 )
{
struct V_3 * V_4 = V_45 -> V_4 ;
int V_28 ;
int V_46 ;
V_28 = F_30 ( V_45 -> V_47 ) ;
if ( V_45 -> V_29 )
V_28 = ! V_28 ;
if ( V_28 )
V_46 = V_45 -> V_46 ;
else
V_46 = 0 ;
if ( V_45 -> V_48 )
V_46 = V_45 -> V_48 ( V_45 -> V_5 ) ;
F_9 ( V_4 , V_46 , V_45 -> V_46 ) ;
}
static T_1 F_31 ( int V_49 , void * V_5 )
{
struct V_44 * V_45 = V_5 ;
struct V_50 * V_40 = V_45 -> V_4 -> V_12 -> V_40 ;
F_32 ( V_45 -> V_51 ) ;
if ( F_33 ( V_40 ) )
F_34 ( V_40 , V_45 -> V_52 + 50 ) ;
F_35 ( V_53 , & V_45 -> V_54 ,
F_36 ( V_45 -> V_52 ) ) ;
return V_55 ;
}
static void F_37 ( struct V_56 * V_54 )
{
struct V_44 * V_45 ;
V_45 = F_38 ( V_54 , struct V_44 , V_54 . V_54 ) ;
F_29 ( V_45 ) ;
}
static int F_39 ( struct V_42 * V_43 ,
unsigned long V_57 , void * V_5 )
{
struct V_44 * V_45 =
F_38 ( V_43 , struct V_44 , V_58 ) ;
switch ( V_57 ) {
case V_59 :
case V_60 :
case V_61 :
F_35 ( V_53 , & V_45 -> V_54 , 0 ) ;
break;
}
return V_62 ;
}
static void F_40 ( struct V_3 * V_4 , int V_30 ,
struct V_44 * V_63 )
{
int V_33 ;
for ( V_33 = 0 ; V_33 < V_30 ; V_33 ++ ) {
F_41 ( V_63 [ V_33 ] . V_47 ) ;
F_42 ( & V_63 [ V_33 ] . V_58 ) ;
F_43 ( F_44 ( V_63 [ V_33 ] . V_47 ) , & V_63 [ V_33 ] ) ;
F_45 ( & V_63 [ V_33 ] . V_54 ) ;
F_46 ( V_63 [ V_33 ] . V_47 ) ;
V_63 [ V_33 ] . V_4 = NULL ;
}
}
static void F_47 ( struct V_50 * V_40 , void * V_64 )
{
struct V_65 * V_66 = V_64 ;
F_40 ( V_66 -> V_4 , V_66 -> V_30 , V_66 -> V_63 ) ;
}
int F_48 ( struct V_3 * V_4 , int V_30 ,
struct V_44 * V_63 )
{
int V_33 , V_17 ;
struct V_65 * V_66 ;
V_66 = F_49 ( F_47 , sizeof( * V_66 ) , V_67 ) ;
if ( ! V_66 )
return - V_68 ;
V_66 -> V_4 = V_4 ;
V_66 -> V_30 = V_30 ;
V_66 -> V_63 = V_63 ;
for ( V_33 = 0 ; V_33 < V_30 ; V_33 ++ ) {
if ( ! V_63 [ V_33 ] . V_51 ) {
F_23 ( V_4 -> V_12 -> V_40 ,
L_4 , V_33 ) ;
V_17 = - V_41 ;
goto V_69;
}
if ( V_63 [ V_33 ] . V_47 ) {
goto V_70;
} else if ( V_63 [ V_33 ] . V_71 ) {
V_63 [ V_33 ] . V_47 = F_50 ( V_63 [ V_33 ] . V_71 ,
V_63 [ V_33 ] . V_51 ,
V_63 [ V_33 ] . V_72 , V_73 ) ;
if ( F_51 ( V_63 [ V_33 ] . V_47 ) ) {
V_17 = F_52 ( V_63 [ V_33 ] . V_47 ) ;
F_23 ( V_63 [ V_33 ] . V_71 ,
L_5 ,
V_33 , V_17 ) ;
goto V_69;
}
} else {
if ( ! F_53 ( V_63 [ V_33 ] . V_45 ) ) {
F_23 ( V_4 -> V_12 -> V_40 ,
L_6 ,
V_63 [ V_33 ] . V_45 ) ;
V_17 = - V_41 ;
goto V_69;
}
V_17 = F_54 ( V_63 [ V_33 ] . V_45 , V_74 ,
V_63 [ V_33 ] . V_51 ) ;
if ( V_17 )
goto V_69;
V_63 [ V_33 ] . V_47 = F_55 ( V_63 [ V_33 ] . V_45 ) ;
}
V_70:
F_56 ( & V_63 [ V_33 ] . V_54 , F_37 ) ;
V_63 [ V_33 ] . V_4 = V_4 ;
V_17 = F_57 ( F_44 ( V_63 [ V_33 ] . V_47 ) ,
F_31 ,
V_75 |
V_76 ,
V_63 [ V_33 ] . V_51 ,
& V_63 [ V_33 ] ) ;
if ( V_17 < 0 )
goto V_77;
if ( V_63 [ V_33 ] . V_78 ) {
V_17 = F_58 ( F_44 ( V_63 [ V_33 ] . V_47 ) , 1 ) ;
if ( V_17 != 0 )
F_23 ( V_4 -> V_12 -> V_40 ,
L_7 ,
V_33 , V_17 ) ;
}
V_63 [ V_33 ] . V_58 . V_79 = F_39 ;
F_59 ( & V_63 [ V_33 ] . V_58 ) ;
F_60 ( V_63 [ V_33 ] . V_47 , false ) ;
F_61 ( & V_63 [ V_33 ] . V_54 ,
F_36 ( V_63 [ V_33 ] . V_52 ) ) ;
}
F_62 ( V_4 -> V_12 -> V_40 , V_66 ) ;
return 0 ;
V_77:
F_63 ( V_63 [ V_33 ] . V_45 ) ;
V_69:
F_40 ( V_4 , V_33 , V_63 ) ;
F_64 ( V_66 ) ;
return V_17 ;
}
int F_65 ( struct V_50 * V_71 ,
struct V_3 * V_4 ,
int V_30 , struct V_44 * V_63 )
{
int V_33 ;
for ( V_33 = 0 ; V_33 < V_30 ; V_33 ++ )
V_63 [ V_33 ] . V_71 = V_71 ;
return F_48 ( V_4 , V_30 , V_63 ) ;
}
void F_66 ( struct V_3 * V_4 , int V_30 ,
struct V_44 * V_63 )
{
F_40 ( V_4 , V_30 , V_63 ) ;
F_67 ( V_4 -> V_12 -> V_40 , F_47 , NULL , NULL ) ;
}
