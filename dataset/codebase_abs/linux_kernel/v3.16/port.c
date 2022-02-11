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
V_26 = F_15 ( V_20 , V_24 ) ;
if ( V_26 < 0 )
F_16 ( & V_7 -> V_2 , L_6 ,
V_26 ) ;
V_26 = 0 ;
if ( ! F_17 ( V_24 , V_20 -> V_31 ) ) {
F_18 ( & V_7 -> V_2 ) ;
F_19 ( & V_21 -> V_2 ) ;
}
}
F_20 ( V_18 ) ;
return V_26 ;
}
static int F_21 ( struct V_1 * V_2 )
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
return - V_32 ;
if ( F_22 ( & V_7 -> V_2 , V_33 )
== V_34 )
return - V_35 ;
if ( V_36 )
return - V_32 ;
F_11 ( V_18 ) ;
V_26 = F_12 ( V_15 , V_20 , V_24 , false ) ;
F_23 ( V_15 , V_24 , V_37 ) ;
if ( ! V_7 -> V_30 )
F_23 ( V_15 , V_24 , V_38 ) ;
F_20 ( V_18 ) ;
if ( ! V_7 -> V_30 && V_23 )
F_24 ( & V_23 -> V_2 ) ;
return V_26 ;
}
static int F_25 ( struct V_6 * V_39 , struct V_6 * V_40 )
{
struct V_6 * V_41 , * V_42 ;
int V_43 ;
if ( V_39 -> V_23 == V_40 && V_40 -> V_23 == V_39 )
return 0 ;
if ( V_39 -> V_23 || V_40 -> V_23 ) {
struct V_6 * V_44 = V_39 -> V_23 ;
struct V_6 * V_45 = V_40 -> V_23 ;
char * V_46 ;
if ( V_39 -> V_47 && V_39 -> V_47 == V_40 -> V_47 )
V_46 = L_7 ;
else
V_46 = L_8 ;
F_26 ( L_9 ,
F_27 ( & V_39 -> V_2 ) , F_27 ( & V_40 -> V_2 ) , V_46 ,
F_27 ( & V_39 -> V_2 ) ,
V_44 ? F_27 ( & V_44 -> V_2 ) : L_10 ,
F_27 ( & V_40 -> V_2 ) ,
V_45 ? F_27 ( & V_45 -> V_2 ) : L_10 ) ;
return - V_32 ;
}
V_43 = F_28 ( & V_39 -> V_2 . V_48 , & V_40 -> V_2 . V_48 , L_11 ) ;
if ( V_43 )
return V_43 ;
V_43 = F_28 ( & V_40 -> V_2 . V_48 , & V_39 -> V_2 . V_48 , L_11 ) ;
if ( V_43 ) {
F_29 ( & V_39 -> V_2 . V_48 , L_11 ) ;
return V_43 ;
}
if ( V_39 -> V_30 ) {
V_41 = V_39 ;
F_30 ( V_40 -> V_30 ) ;
V_42 = V_40 ;
} else {
V_41 = V_40 ;
F_30 ( ! V_40 -> V_30 ) ;
V_42 = V_39 ;
}
F_10 ( & V_42 -> V_2 ) ;
V_39 -> V_23 = V_40 ;
V_40 -> V_23 = V_39 ;
F_10 ( & V_41 -> V_2 ) ;
F_24 ( & V_42 -> V_2 ) ;
return 0 ;
}
static void F_31 ( struct V_6 * V_39 , struct V_6 * V_40 )
{
int V_43 ;
V_43 = F_25 ( V_39 , V_40 ) ;
if ( V_43 == 0 ) {
F_16 ( & V_39 -> V_2 , L_12 , F_27 ( & V_40 -> V_2 ) ) ;
} else {
F_32 ( & V_39 -> V_2 , L_13 ,
F_27 ( & V_40 -> V_2 ) , V_43 ) ;
F_33 ( L_14 ) ;
V_36 = 1 ;
}
}
static void F_34 ( struct V_6 * V_39 , struct V_6 * V_40 )
{
struct V_6 * V_41 , * V_42 ;
F_35 ( V_40 -> V_23 != V_39 || V_39 -> V_23 != V_40 ,
L_15 ,
F_27 ( & V_39 -> V_2 ) , F_27 ( & V_40 -> V_2 ) ) ;
if ( V_39 -> V_30 ) {
V_41 = V_39 ;
V_42 = V_40 ;
} else {
V_41 = V_40 ;
V_42 = V_39 ;
}
F_10 ( & V_42 -> V_2 ) ;
F_29 ( & V_39 -> V_2 . V_48 , L_11 ) ;
V_40 -> V_23 = NULL ;
F_29 ( & V_40 -> V_2 . V_48 , L_11 ) ;
V_39 -> V_23 = NULL ;
F_24 ( & V_41 -> V_2 ) ;
F_24 ( & V_42 -> V_2 ) ;
}
static int F_36 ( struct V_14 * V_49 , void * V_50 )
{
int V_24 ;
struct V_51 * V_52 , * V_53 ;
struct V_6 * V_7 = V_50 , * V_23 ;
struct V_19 * V_54 = F_8 ( V_49 ) ;
struct V_14 * V_15 = F_6 ( V_7 -> V_2 . V_16 -> V_16 ) ;
if ( ! V_54 )
return 0 ;
V_52 = F_37 ( V_15 -> V_55 ) ;
V_53 = F_37 ( V_49 -> V_55 ) ;
if ( V_53 != V_52 -> V_56 )
return 0 ;
for ( V_24 = 1 ; V_24 <= V_49 -> V_57 ; V_24 ++ ) {
V_23 = V_54 -> V_58 [ V_24 - 1 ] ;
if ( V_23 && V_23 -> V_47 == V_7 -> V_47 ) {
F_31 ( V_7 , V_23 ) ;
return 1 ;
}
}
return 0 ;
}
static void F_38 ( struct V_19 * V_20 , int V_24 )
{
struct V_6 * V_7 = V_20 -> V_58 [ V_24 - 1 ] , * V_23 ;
struct V_14 * V_15 = V_20 -> V_15 ;
struct V_14 * V_49 ;
struct V_19 * V_54 ;
if ( V_7 -> V_47 ) {
F_39 ( V_7 , F_36 ) ;
return;
} else if ( ! V_15 -> V_16 ) {
struct V_51 * V_52 = F_37 ( V_15 -> V_55 ) ;
struct V_51 * V_53 = V_52 -> V_56 ;
if ( ! V_53 )
return;
V_49 = V_53 -> V_59 . V_60 ;
} else {
struct V_6 * V_61 ;
struct V_14 * V_16 = V_15 -> V_16 ;
struct V_19 * V_62 = F_8 ( V_16 ) ;
if ( ! V_62 )
return;
V_61 = V_62 -> V_58 [ V_15 -> V_25 - 1 ] ;
if ( ! V_61 || ! V_61 -> V_23 )
return;
V_49 = V_61 -> V_23 -> V_22 ;
}
V_54 = F_8 ( V_49 ) ;
if ( ! V_54 || V_24 > V_49 -> V_57 )
return;
V_23 = V_54 -> V_58 [ V_24 - 1 ] ;
if ( V_23 && V_23 -> V_47 == 0 )
F_31 ( V_7 , V_23 ) ;
}
int F_40 ( struct V_19 * V_20 , int V_24 )
{
struct V_6 * V_7 ;
int V_26 ;
V_7 = F_41 ( sizeof( * V_7 ) , V_63 ) ;
if ( ! V_7 )
return - V_64 ;
V_7 -> V_13 = F_41 ( sizeof( * ( V_7 -> V_13 ) ) , V_63 ) ;
if ( ! V_7 -> V_13 ) {
F_4 ( V_7 ) ;
return - V_64 ;
}
V_20 -> V_58 [ V_24 - 1 ] = V_7 ;
V_7 -> V_25 = V_24 ;
F_9 ( V_24 , V_20 -> V_29 ) ;
V_7 -> V_2 . V_16 = V_20 -> V_65 ;
V_7 -> V_2 . V_66 = V_67 ;
V_7 -> V_2 . type = & V_68 ;
V_7 -> V_2 . V_69 = & V_70 ;
if ( F_42 ( V_20 -> V_15 ) )
V_7 -> V_30 = 1 ;
F_43 ( & V_7 -> V_2 , L_16 , F_27 ( & V_20 -> V_15 -> V_2 ) ,
V_24 ) ;
F_44 ( & V_7 -> V_71 ) ;
V_26 = F_45 ( & V_7 -> V_2 ) ;
if ( V_26 ) {
F_46 ( & V_7 -> V_2 ) ;
return V_26 ;
}
V_26 = F_47 ( & V_7 -> V_2 , V_7 -> V_13 ,
V_72 , V_33 ) ;
if ( V_26 < 0 ) {
F_48 ( & V_7 -> V_2 ) ;
return V_26 ;
}
F_38 ( V_20 , V_24 ) ;
F_49 ( & V_7 -> V_2 ) ;
F_18 ( & V_7 -> V_2 ) ;
F_50 ( & V_7 -> V_2 ) ;
F_51 ( & V_7 -> V_2 ) ;
if ( ! F_52 ( V_20 ) )
return 0 ;
V_26 = F_53 ( & V_7 -> V_2 ,
V_33 ) ;
if ( V_26 < 0 ) {
F_32 ( & V_7 -> V_2 , L_17 ) ;
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
struct V_6 * V_7 = V_20 -> V_58 [ V_24 - 1 ] ;
struct V_6 * V_23 ;
V_23 = V_7 -> V_23 ;
if ( V_23 )
F_34 ( V_7 , V_23 ) ;
F_48 ( & V_7 -> V_2 ) ;
}
