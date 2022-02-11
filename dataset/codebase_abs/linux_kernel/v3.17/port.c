static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
char * V_8 ;
switch ( V_7 -> V_9 ) {
case V_10 :
V_8 = L_1 ;
break;
case V_11 :
V_8 = L_2 ;
break;
case V_12 :
V_8 = L_3 ;
break;
default:
V_8 = L_4 ;
break;
}
return sprintf ( V_5 , L_5 , V_8 ) ;
}
static void F_3 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
F_4 ( V_7 -> V_13 ) ;
F_4 ( V_7 ) ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_14 * V_15 = F_6 ( V_2 -> V_16 -> V_16 ) ;
struct V_17 * V_18 = F_7 ( V_2 -> V_16 ) ;
struct V_19 * V_20 = F_8 ( V_15 ) ;
struct V_14 * V_21 = V_7 -> V_22 ;
struct V_6 * V_23 = V_7 -> V_23 ;
int V_24 = V_7 -> V_25 ;
int V_26 ;
if ( ! V_20 )
return - V_27 ;
if ( V_20 -> V_28 ) {
F_9 ( V_24 , V_20 -> V_29 ) ;
return 0 ;
}
if ( ! V_7 -> V_30 && V_23 )
F_10 ( & V_23 -> V_2 ) ;
F_11 ( V_18 ) ;
V_26 = F_12 ( V_15 , V_20 , V_24 , true ) ;
F_13 ( F_14 ( V_20 ) ) ;
if ( V_21 && ! V_26 ) {
if ( F_15 ( V_20 , V_24 ) < 0 ) {
F_16 ( & V_7 -> V_2 , L_6 ) ;
if ( F_17 ( V_15 ) )
F_9 ( V_24 , V_20 -> V_31 ) ;
}
if ( ! F_18 ( V_24 , V_20 -> V_32 ) ) {
F_19 ( & V_7 -> V_2 ) ;
F_20 ( & V_21 -> V_2 ) ;
}
}
F_21 ( V_18 ) ;
return V_26 ;
}
static int F_22 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_14 * V_15 = F_6 ( V_2 -> V_16 -> V_16 ) ;
struct V_17 * V_18 = F_7 ( V_2 -> V_16 ) ;
struct V_19 * V_20 = F_8 ( V_15 ) ;
struct V_6 * V_23 = V_7 -> V_23 ;
int V_24 = V_7 -> V_25 ;
int V_26 ;
if ( ! V_20 )
return - V_27 ;
if ( V_20 -> V_28 )
return - V_33 ;
if ( F_23 ( & V_7 -> V_2 , V_34 )
== V_35 )
return - V_36 ;
if ( V_37 )
return - V_33 ;
F_11 ( V_18 ) ;
V_26 = F_12 ( V_15 , V_20 , V_24 , false ) ;
F_24 ( V_15 , V_24 , V_38 ) ;
if ( ! V_7 -> V_30 )
F_24 ( V_15 , V_24 , V_39 ) ;
F_21 ( V_18 ) ;
if ( ! V_7 -> V_30 && V_23 )
F_25 ( & V_23 -> V_2 ) ;
return V_26 ;
}
static int F_26 ( struct V_6 * V_40 , struct V_6 * V_41 )
{
struct V_6 * V_42 , * V_43 ;
int V_44 ;
if ( V_40 -> V_23 == V_41 && V_41 -> V_23 == V_40 )
return 0 ;
if ( V_40 -> V_23 || V_41 -> V_23 ) {
struct V_6 * V_45 = V_40 -> V_23 ;
struct V_6 * V_46 = V_41 -> V_23 ;
char * V_47 ;
if ( V_40 -> V_48 && V_40 -> V_48 == V_41 -> V_48 )
V_47 = L_7 ;
else
V_47 = L_8 ;
F_27 ( L_9 ,
F_28 ( & V_40 -> V_2 ) , F_28 ( & V_41 -> V_2 ) , V_47 ,
F_28 ( & V_40 -> V_2 ) ,
V_45 ? F_28 ( & V_45 -> V_2 ) : L_10 ,
F_28 ( & V_41 -> V_2 ) ,
V_46 ? F_28 ( & V_46 -> V_2 ) : L_10 ) ;
return - V_33 ;
}
V_44 = F_29 ( & V_40 -> V_2 . V_49 , & V_41 -> V_2 . V_49 , L_11 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_29 ( & V_41 -> V_2 . V_49 , & V_40 -> V_2 . V_49 , L_11 ) ;
if ( V_44 ) {
F_30 ( & V_40 -> V_2 . V_49 , L_11 ) ;
return V_44 ;
}
if ( V_40 -> V_30 ) {
V_42 = V_40 ;
F_31 ( V_41 -> V_30 ) ;
V_43 = V_41 ;
} else {
V_42 = V_41 ;
F_31 ( ! V_41 -> V_30 ) ;
V_43 = V_40 ;
}
F_10 ( & V_43 -> V_2 ) ;
V_40 -> V_23 = V_41 ;
V_41 -> V_23 = V_40 ;
F_10 ( & V_42 -> V_2 ) ;
F_25 ( & V_43 -> V_2 ) ;
return 0 ;
}
static void F_32 ( struct V_6 * V_40 , struct V_6 * V_41 )
{
int V_44 ;
V_44 = F_26 ( V_40 , V_41 ) ;
if ( V_44 == 0 ) {
F_16 ( & V_40 -> V_2 , L_12 , F_28 ( & V_41 -> V_2 ) ) ;
} else {
F_33 ( & V_40 -> V_2 , L_13 ,
F_28 ( & V_41 -> V_2 ) , V_44 ) ;
F_34 ( L_14 ) ;
V_37 = 1 ;
}
}
static void F_35 ( struct V_6 * V_40 , struct V_6 * V_41 )
{
struct V_6 * V_42 , * V_43 ;
F_36 ( V_41 -> V_23 != V_40 || V_40 -> V_23 != V_41 ,
L_15 ,
F_28 ( & V_40 -> V_2 ) , F_28 ( & V_41 -> V_2 ) ) ;
if ( V_40 -> V_30 ) {
V_42 = V_40 ;
V_43 = V_41 ;
} else {
V_42 = V_41 ;
V_43 = V_40 ;
}
F_10 ( & V_43 -> V_2 ) ;
F_30 ( & V_40 -> V_2 . V_49 , L_11 ) ;
V_41 -> V_23 = NULL ;
F_30 ( & V_41 -> V_2 . V_49 , L_11 ) ;
V_40 -> V_23 = NULL ;
F_25 ( & V_42 -> V_2 ) ;
F_25 ( & V_43 -> V_2 ) ;
}
static int F_37 ( struct V_14 * V_50 , void * V_51 )
{
int V_24 ;
struct V_52 * V_53 , * V_54 ;
struct V_6 * V_7 = V_51 , * V_23 ;
struct V_19 * V_55 = F_8 ( V_50 ) ;
struct V_14 * V_15 = F_6 ( V_7 -> V_2 . V_16 -> V_16 ) ;
if ( ! V_55 )
return 0 ;
V_53 = F_38 ( V_15 -> V_56 ) ;
V_54 = F_38 ( V_50 -> V_56 ) ;
if ( V_54 != V_53 -> V_57 )
return 0 ;
for ( V_24 = 1 ; V_24 <= V_50 -> V_58 ; V_24 ++ ) {
V_23 = V_55 -> V_59 [ V_24 - 1 ] ;
if ( V_23 && V_23 -> V_48 == V_7 -> V_48 ) {
F_32 ( V_7 , V_23 ) ;
return 1 ;
}
}
return 0 ;
}
static void F_39 ( struct V_19 * V_20 , int V_24 )
{
struct V_6 * V_7 = V_20 -> V_59 [ V_24 - 1 ] , * V_23 ;
struct V_14 * V_15 = V_20 -> V_15 ;
struct V_14 * V_50 ;
struct V_19 * V_55 ;
if ( V_7 -> V_48 ) {
F_40 ( V_7 , F_37 ) ;
return;
} else if ( ! V_15 -> V_16 ) {
struct V_52 * V_53 = F_38 ( V_15 -> V_56 ) ;
struct V_52 * V_54 = V_53 -> V_57 ;
if ( ! V_54 )
return;
V_50 = V_54 -> V_60 . V_61 ;
} else {
struct V_6 * V_62 ;
struct V_14 * V_16 = V_15 -> V_16 ;
struct V_19 * V_63 = F_8 ( V_16 ) ;
if ( ! V_63 )
return;
V_62 = V_63 -> V_59 [ V_15 -> V_25 - 1 ] ;
if ( ! V_62 || ! V_62 -> V_23 )
return;
V_50 = V_62 -> V_23 -> V_22 ;
}
V_55 = F_8 ( V_50 ) ;
if ( ! V_55 || V_24 > V_50 -> V_58 )
return;
V_23 = V_55 -> V_59 [ V_24 - 1 ] ;
if ( V_23 && V_23 -> V_48 == 0 )
F_32 ( V_7 , V_23 ) ;
}
int F_41 ( struct V_19 * V_20 , int V_24 )
{
struct V_6 * V_7 ;
int V_26 ;
V_7 = F_42 ( sizeof( * V_7 ) , V_64 ) ;
if ( ! V_7 )
return - V_65 ;
V_7 -> V_13 = F_42 ( sizeof( * ( V_7 -> V_13 ) ) , V_64 ) ;
if ( ! V_7 -> V_13 ) {
F_4 ( V_7 ) ;
return - V_65 ;
}
V_20 -> V_59 [ V_24 - 1 ] = V_7 ;
V_7 -> V_25 = V_24 ;
F_9 ( V_24 , V_20 -> V_29 ) ;
V_7 -> V_2 . V_16 = V_20 -> V_66 ;
V_7 -> V_2 . V_67 = V_68 ;
V_7 -> V_2 . type = & V_69 ;
V_7 -> V_2 . V_70 = & V_71 ;
if ( F_17 ( V_20 -> V_15 ) )
V_7 -> V_30 = 1 ;
F_43 ( & V_7 -> V_2 , L_16 , F_28 ( & V_20 -> V_15 -> V_2 ) ,
V_24 ) ;
F_44 ( & V_7 -> V_72 ) ;
V_26 = F_45 ( & V_7 -> V_2 ) ;
if ( V_26 ) {
F_46 ( & V_7 -> V_2 ) ;
return V_26 ;
}
V_26 = F_47 ( & V_7 -> V_2 , V_7 -> V_13 ,
V_73 , V_34 ) ;
if ( V_26 < 0 ) {
F_48 ( & V_7 -> V_2 ) ;
return V_26 ;
}
F_39 ( V_20 , V_24 ) ;
F_49 ( & V_7 -> V_2 ) ;
F_19 ( & V_7 -> V_2 ) ;
F_50 ( & V_7 -> V_2 ) ;
F_51 ( & V_7 -> V_2 ) ;
if ( ! F_52 ( V_20 ) )
return 0 ;
V_26 = F_53 ( & V_7 -> V_2 ,
V_34 ) ;
if ( V_26 < 0 ) {
F_33 ( & V_7 -> V_2 , L_17 ) ;
return 0 ;
}
V_26 = F_54 ( V_7 -> V_13 ) ;
if ( V_26 >= 0 ) {
F_4 ( V_7 -> V_13 ) ;
V_7 -> V_13 = NULL ;
}
return 0 ;
}
void F_55 ( struct V_19 * V_20 , int V_24 )
{
struct V_6 * V_7 = V_20 -> V_59 [ V_24 - 1 ] ;
struct V_6 * V_23 ;
V_23 = V_7 -> V_23 ;
if ( V_23 )
F_35 ( V_7 , V_23 ) ;
F_48 ( & V_7 -> V_2 ) ;
}
