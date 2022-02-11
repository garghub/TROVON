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
static T_1 F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
const char * V_13 ;
if ( V_7 -> V_14 ) {
if ( V_7 -> V_15 )
V_13 = L_6 ;
else
V_13 = L_7 ;
} else {
if ( V_7 -> V_15 )
V_13 = L_8 ;
else
V_13 = L_9 ;
}
return sprintf ( V_5 , L_5 , V_13 ) ;
}
static T_1 F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 , T_2 V_16 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_17 * V_18 = V_7 -> V_19 ;
struct V_20 * V_21 ;
if ( ! strncmp ( V_5 , L_6 , 5 ) ) {
V_7 -> V_14 = 1 ;
V_7 -> V_15 = 1 ;
} else if ( ! strncmp ( V_5 , L_7 , 2 ) ) {
V_7 -> V_14 = 1 ;
V_7 -> V_15 = 0 ;
} else if ( ! strncmp ( V_5 , L_8 , 2 ) ) {
V_7 -> V_14 = 0 ;
V_7 -> V_15 = 1 ;
} else if ( ! strncmp ( V_5 , L_9 , 1 ) ) {
V_7 -> V_14 = 0 ;
V_7 -> V_15 = 0 ;
} else
return - V_22 ;
if ( V_18 ) {
V_21 = F_5 ( V_18 -> V_23 ) ;
if ( ! V_21 )
return - V_22 ;
F_6 ( V_18 ) ;
F_7 ( V_21 -> V_24 ) ;
if ( ! F_8 ( V_18 ) )
F_9 ( V_18 ) ;
F_10 ( V_21 -> V_24 ) ;
F_11 ( V_18 ) ;
}
return V_16 ;
}
static void F_12 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
F_13 ( V_7 -> V_25 ) ;
F_13 ( V_7 ) ;
}
static int F_14 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_17 * V_26 = F_15 ( V_2 -> V_27 -> V_27 ) ;
struct V_28 * V_29 = F_16 ( V_2 -> V_27 ) ;
struct V_30 * V_31 = F_17 ( V_26 ) ;
struct V_17 * V_18 = V_7 -> V_19 ;
struct V_6 * V_32 = V_7 -> V_32 ;
int V_33 = V_7 -> V_34 ;
int V_35 ;
if ( ! V_31 )
return - V_22 ;
if ( V_31 -> V_36 ) {
F_18 ( V_33 , V_31 -> V_37 ) ;
return 0 ;
}
if ( ! V_7 -> V_38 && V_32 )
F_19 ( & V_32 -> V_2 ) ;
F_20 ( V_29 ) ;
V_35 = F_21 ( V_26 , V_31 , V_33 , true ) ;
F_22 ( F_23 ( V_31 ) ) ;
if ( V_18 && ! V_35 ) {
if ( F_24 ( V_31 , V_33 ) < 0 ) {
F_25 ( & V_7 -> V_2 , L_10 ) ;
if ( F_26 ( V_26 ) )
F_18 ( V_33 , V_31 -> V_39 ) ;
}
if ( ! F_27 ( V_33 , V_31 -> V_40 ) ) {
F_28 ( & V_7 -> V_2 ) ;
F_29 ( & V_18 -> V_2 ) ;
}
}
F_30 ( V_29 ) ;
return V_35 ;
}
static int F_31 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_17 * V_26 = F_15 ( V_2 -> V_27 -> V_27 ) ;
struct V_28 * V_29 = F_16 ( V_2 -> V_27 ) ;
struct V_30 * V_31 = F_17 ( V_26 ) ;
struct V_6 * V_32 = V_7 -> V_32 ;
int V_33 = V_7 -> V_34 ;
int V_35 ;
if ( ! V_31 )
return - V_22 ;
if ( V_31 -> V_36 )
return - V_41 ;
if ( F_32 ( & V_7 -> V_2 , V_42 )
== V_43 )
return - V_44 ;
if ( V_45 )
return - V_41 ;
F_20 ( V_29 ) ;
V_35 = F_21 ( V_26 , V_31 , V_33 , false ) ;
F_33 ( V_26 , V_33 , V_46 ) ;
if ( ! V_7 -> V_38 )
F_33 ( V_26 , V_33 , V_47 ) ;
F_30 ( V_29 ) ;
if ( ! V_7 -> V_38 && V_32 )
F_34 ( & V_32 -> V_2 ) ;
return V_35 ;
}
static int F_35 ( struct V_1 * V_2 )
{
return 1 ;
}
static int F_36 ( struct V_6 * V_48 , struct V_6 * V_49 )
{
struct V_6 * V_50 , * V_51 ;
int V_52 ;
if ( V_48 -> V_32 == V_49 && V_49 -> V_32 == V_48 )
return 0 ;
if ( V_48 -> V_32 || V_49 -> V_32 ) {
struct V_6 * V_53 = V_48 -> V_32 ;
struct V_6 * V_54 = V_49 -> V_32 ;
char * V_55 ;
if ( V_48 -> V_56 && V_48 -> V_56 == V_49 -> V_56 )
V_55 = L_11 ;
else
V_55 = L_12 ;
F_37 ( L_13 ,
F_38 ( & V_48 -> V_2 ) , F_38 ( & V_49 -> V_2 ) , V_55 ,
F_38 ( & V_48 -> V_2 ) ,
V_53 ? F_38 ( & V_53 -> V_2 ) : L_14 ,
F_38 ( & V_49 -> V_2 ) ,
V_54 ? F_38 ( & V_54 -> V_2 ) : L_14 ) ;
return - V_41 ;
}
V_52 = F_39 ( & V_48 -> V_2 . V_57 , & V_49 -> V_2 . V_57 , L_15 ) ;
if ( V_52 )
return V_52 ;
V_52 = F_39 ( & V_49 -> V_2 . V_57 , & V_48 -> V_2 . V_57 , L_15 ) ;
if ( V_52 ) {
F_40 ( & V_48 -> V_2 . V_57 , L_15 ) ;
return V_52 ;
}
if ( V_48 -> V_38 ) {
V_50 = V_48 ;
F_41 ( V_49 -> V_38 ) ;
V_51 = V_49 ;
} else {
V_50 = V_49 ;
F_41 ( ! V_49 -> V_38 ) ;
V_51 = V_48 ;
}
F_19 ( & V_51 -> V_2 ) ;
V_48 -> V_32 = V_49 ;
V_49 -> V_32 = V_48 ;
F_19 ( & V_50 -> V_2 ) ;
F_34 ( & V_51 -> V_2 ) ;
return 0 ;
}
static void F_42 ( struct V_6 * V_48 , struct V_6 * V_49 )
{
int V_52 ;
V_52 = F_36 ( V_48 , V_49 ) ;
if ( V_52 == 0 ) {
F_25 ( & V_48 -> V_2 , L_16 , F_38 ( & V_49 -> V_2 ) ) ;
} else {
F_25 ( & V_48 -> V_2 , L_17 ,
F_38 ( & V_49 -> V_2 ) , V_52 ) ;
F_43 ( L_18 ) ;
V_45 = 1 ;
}
}
static void F_44 ( struct V_6 * V_48 , struct V_6 * V_49 )
{
struct V_6 * V_50 , * V_51 ;
F_45 ( V_49 -> V_32 != V_48 || V_48 -> V_32 != V_49 ,
L_19 ,
F_38 ( & V_48 -> V_2 ) , F_38 ( & V_49 -> V_2 ) ) ;
if ( V_48 -> V_38 ) {
V_50 = V_48 ;
V_51 = V_49 ;
} else {
V_50 = V_49 ;
V_51 = V_48 ;
}
F_19 ( & V_51 -> V_2 ) ;
F_40 ( & V_48 -> V_2 . V_57 , L_15 ) ;
V_49 -> V_32 = NULL ;
F_40 ( & V_49 -> V_2 . V_57 , L_15 ) ;
V_48 -> V_32 = NULL ;
F_34 ( & V_50 -> V_2 ) ;
F_34 ( & V_51 -> V_2 ) ;
}
static int F_46 ( struct V_17 * V_58 , void * V_13 )
{
int V_33 ;
struct V_20 * V_21 , * V_59 ;
struct V_6 * V_7 = V_13 , * V_32 ;
struct V_30 * V_60 = F_17 ( V_58 ) ;
struct V_17 * V_26 = F_15 ( V_7 -> V_2 . V_27 -> V_27 ) ;
if ( ! V_60 )
return 0 ;
V_21 = F_5 ( V_26 -> V_23 ) ;
V_59 = F_5 ( V_58 -> V_23 ) ;
if ( V_59 != V_21 -> V_61 )
return 0 ;
for ( V_33 = 1 ; V_33 <= V_58 -> V_62 ; V_33 ++ ) {
V_32 = V_60 -> V_63 [ V_33 - 1 ] ;
if ( V_32 && V_32 -> V_56 == V_7 -> V_56 ) {
F_42 ( V_7 , V_32 ) ;
return 1 ;
}
}
return 0 ;
}
static void F_47 ( struct V_30 * V_31 , int V_33 )
{
struct V_6 * V_7 = V_31 -> V_63 [ V_33 - 1 ] , * V_32 ;
struct V_17 * V_26 = V_31 -> V_26 ;
struct V_17 * V_58 ;
struct V_30 * V_60 ;
if ( V_7 -> V_56 ) {
F_48 ( V_7 , F_46 ) ;
return;
} else if ( ! V_26 -> V_27 ) {
struct V_20 * V_21 = F_5 ( V_26 -> V_23 ) ;
struct V_20 * V_59 = V_21 -> V_61 ;
if ( ! V_59 )
return;
V_58 = V_59 -> V_64 . V_65 ;
} else {
struct V_6 * V_66 ;
struct V_17 * V_27 = V_26 -> V_27 ;
struct V_30 * V_67 = F_17 ( V_27 ) ;
if ( ! V_67 )
return;
V_66 = V_67 -> V_63 [ V_26 -> V_34 - 1 ] ;
if ( ! V_66 || ! V_66 -> V_32 )
return;
V_58 = V_66 -> V_32 -> V_19 ;
}
V_60 = F_17 ( V_58 ) ;
if ( ! V_60 || V_33 > V_58 -> V_62 )
return;
V_32 = V_60 -> V_63 [ V_33 - 1 ] ;
if ( V_32 && V_32 -> V_56 == 0 )
F_42 ( V_7 , V_32 ) ;
}
int F_49 ( struct V_30 * V_31 , int V_33 )
{
struct V_6 * V_7 ;
struct V_17 * V_26 = V_31 -> V_26 ;
int V_35 ;
V_7 = F_50 ( sizeof( * V_7 ) , V_68 ) ;
if ( ! V_7 )
return - V_69 ;
V_7 -> V_25 = F_50 ( sizeof( * ( V_7 -> V_25 ) ) , V_68 ) ;
if ( ! V_7 -> V_25 ) {
F_13 ( V_7 ) ;
return - V_69 ;
}
V_31 -> V_63 [ V_33 - 1 ] = V_7 ;
V_7 -> V_34 = V_33 ;
F_18 ( V_33 , V_31 -> V_37 ) ;
V_7 -> V_2 . V_27 = V_31 -> V_70 ;
if ( F_26 ( V_26 ) ) {
V_7 -> V_14 = 1 ;
V_7 -> V_15 = 1 ;
V_7 -> V_2 . V_71 = V_72 ;
} else
V_7 -> V_2 . V_71 = V_73 ;
V_7 -> V_2 . type = & V_74 ;
V_7 -> V_2 . V_75 = & V_76 ;
if ( F_26 ( V_31 -> V_26 ) )
V_7 -> V_38 = 1 ;
F_51 ( & V_7 -> V_2 , L_20 , F_38 ( & V_31 -> V_26 -> V_2 ) ,
V_33 ) ;
F_52 ( & V_7 -> V_77 ) ;
V_35 = F_53 ( & V_7 -> V_2 ) ;
if ( V_35 ) {
F_54 ( & V_7 -> V_2 ) ;
return V_35 ;
}
V_35 = F_55 ( & V_7 -> V_2 , V_7 -> V_25 ,
V_78 , V_42 ) ;
if ( V_35 < 0 ) {
F_56 ( & V_7 -> V_2 ) ;
return V_35 ;
}
F_47 ( V_31 , V_33 ) ;
F_57 ( & V_7 -> V_2 ) ;
F_28 ( & V_7 -> V_2 ) ;
F_58 ( & V_7 -> V_2 ) ;
F_59 ( & V_7 -> V_2 ) ;
if ( ! F_60 ( V_31 ) )
return 0 ;
V_35 = F_61 ( & V_7 -> V_2 ,
V_42 ) ;
if ( V_35 < 0 ) {
F_62 ( & V_7 -> V_2 , L_21 ) ;
return 0 ;
}
V_35 = F_63 ( V_7 -> V_25 ) ;
if ( V_35 >= 0 ) {
F_13 ( V_7 -> V_25 ) ;
V_7 -> V_25 = NULL ;
}
return 0 ;
}
void F_64 ( struct V_30 * V_31 , int V_33 )
{
struct V_6 * V_7 = V_31 -> V_63 [ V_33 - 1 ] ;
struct V_6 * V_32 ;
V_32 = V_7 -> V_32 ;
if ( V_32 )
F_44 ( V_7 , V_32 ) ;
F_56 ( & V_7 -> V_2 ) ;
}
