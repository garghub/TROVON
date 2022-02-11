static struct V_1 * F_1 ( struct V_2 * V_3 ,
T_1 V_4 )
{
struct V_5 * V_6 = V_3 -> V_7 . V_5 ;
struct V_1 * V_8 ;
while ( V_6 ) {
V_8 = F_2 ( V_6 , struct V_1 , V_9 ) ;
if ( V_8 -> V_4 < V_4 )
V_6 = V_6 -> V_10 ;
else if ( V_8 -> V_4 > V_4 )
V_6 = V_6 -> V_11 ;
else
return V_8 ;
}
return NULL ;
}
static struct V_1 * F_3 ( struct V_2 * V_3 ,
T_1 V_4 )
{
struct V_5 * * V_12 = & V_3 -> V_7 . V_5 ;
struct V_5 * V_13 = NULL ;
struct V_1 * V_8 ;
while ( * V_12 ) {
V_13 = * V_12 ;
V_8 = F_2 ( V_13 , struct V_1 , V_9 ) ;
if ( V_8 -> V_4 < V_4 )
V_12 = & ( * V_12 ) -> V_10 ;
else if ( V_8 -> V_4 > V_4 )
V_12 = & ( * V_12 ) -> V_11 ;
else
return V_8 ;
}
V_8 = F_4 ( sizeof( * V_8 ) , V_14 ) ;
if ( ! V_8 )
return F_5 ( - V_15 ) ;
V_8 -> V_4 = V_4 ;
F_6 ( & V_8 -> V_16 ) ;
F_6 ( & V_8 -> V_17 ) ;
F_6 ( & V_8 -> V_18 ) ;
F_7 ( & V_8 -> V_9 , V_13 , V_12 ) ;
F_8 ( & V_8 -> V_9 , & V_3 -> V_7 ) ;
return V_8 ;
}
static void F_9 ( struct V_1 * V_8 )
{
struct V_19 * V_20 ;
F_10 ( & V_8 -> V_18 ) ;
while ( ! F_11 ( & V_8 -> V_16 ) ) {
V_20 = F_12 ( & V_8 -> V_16 ,
struct V_19 , V_21 ) ;
F_10 ( & V_20 -> V_21 ) ;
F_10 ( & V_20 -> V_22 ) ;
F_13 ( V_20 ) ;
}
while ( ! F_11 ( & V_8 -> V_17 ) ) {
V_20 = F_12 ( & V_8 -> V_17 ,
struct V_19 , V_22 ) ;
F_10 ( & V_20 -> V_21 ) ;
F_10 ( & V_20 -> V_22 ) ;
F_13 ( V_20 ) ;
}
F_13 ( V_8 ) ;
}
static int F_14 ( struct V_2 * V_3 , T_1 V_4 )
{
struct V_1 * V_8 = F_1 ( V_3 , V_4 ) ;
if ( ! V_8 )
return - V_23 ;
F_15 ( & V_8 -> V_9 , & V_3 -> V_7 ) ;
F_9 ( V_8 ) ;
return 0 ;
}
static int F_16 ( struct V_2 * V_3 ,
T_1 V_24 , T_1 V_25 )
{
struct V_1 * V_26 ;
struct V_1 * V_13 ;
struct V_19 * V_20 ;
V_26 = F_1 ( V_3 , V_24 ) ;
V_13 = F_1 ( V_3 , V_25 ) ;
if ( ! V_26 || ! V_13 )
return - V_23 ;
V_20 = F_4 ( sizeof( * V_20 ) , V_14 ) ;
if ( ! V_20 )
return - V_15 ;
V_20 -> V_27 = V_13 ;
V_20 -> V_26 = V_26 ;
F_17 ( & V_20 -> V_21 , & V_26 -> V_16 ) ;
F_17 ( & V_20 -> V_22 , & V_13 -> V_17 ) ;
return 0 ;
}
static int F_18 ( struct V_2 * V_3 ,
T_1 V_24 , T_1 V_25 )
{
struct V_1 * V_26 ;
struct V_1 * V_13 ;
struct V_19 * V_20 ;
V_26 = F_1 ( V_3 , V_24 ) ;
V_13 = F_1 ( V_3 , V_25 ) ;
if ( ! V_26 || ! V_13 )
return - V_23 ;
F_19 (list, &member->groups, next_group) {
if ( V_20 -> V_27 == V_13 ) {
F_10 ( & V_20 -> V_21 ) ;
F_10 ( & V_20 -> V_22 ) ;
F_13 ( V_20 ) ;
return 0 ;
}
}
return - V_23 ;
}
int F_20 ( struct V_2 * V_3 , T_1 V_4 ,
T_1 V_28 , T_1 V_29 )
{
struct V_1 * V_8 ;
V_8 = F_1 ( V_3 , V_4 ) ;
if ( ! V_8 )
return - V_30 ;
if ( V_8 -> V_28 != V_28 || V_8 -> V_29 != V_29 )
return - V_30 ;
return 0 ;
}
int F_21 ( struct V_2 * V_3 )
{
struct V_31 V_32 ;
struct V_31 V_33 ;
struct V_34 * V_35 = V_3 -> V_35 ;
struct V_36 * V_37 = NULL ;
struct V_38 * V_39 ;
int V_40 ;
int V_41 = 0 ;
T_1 V_42 = 0 ;
T_1 V_43 = 0 ;
if ( ! V_3 -> V_44 )
return 0 ;
V_3 -> V_45 = F_22 ( V_46 ) ;
if ( ! V_3 -> V_45 ) {
V_41 = - V_15 ;
goto V_47;
}
V_37 = F_23 () ;
if ( ! V_37 ) {
V_41 = - V_15 ;
goto V_47;
}
V_3 -> V_48 = 0 ;
V_32 . V_49 = 0 ;
V_32 . type = 0 ;
V_32 . V_50 = 0 ;
V_41 = F_24 ( V_35 , & V_32 , V_37 , 1 , 1 ) ;
if ( V_41 )
goto V_47;
while ( 1 ) {
struct V_1 * V_8 ;
V_40 = V_37 -> V_51 [ 0 ] ;
V_39 = V_37 -> V_52 [ 0 ] ;
F_25 ( V_39 , & V_33 , V_40 ) ;
if ( V_33 . type == V_53 ) {
struct V_54 * V_55 ;
V_55 = F_26 ( V_39 , V_40 ,
struct V_54 ) ;
if ( F_27 ( V_39 , V_55 ) !=
V_56 ) {
F_28 ( V_3 ,
L_1 ) ;
goto V_47;
}
if ( F_29 ( V_39 , V_55 ) !=
V_3 -> V_57 ) {
V_42 |= V_58 ;
F_28 ( V_3 ,
L_2
L_3 ) ;
}
V_3 -> V_48 = F_30 ( V_39 ,
V_55 ) ;
V_43 = F_31 ( V_39 , V_55 ) ;
goto V_59;
}
if ( V_33 . type != V_60 &&
V_33 . type != V_61 )
goto V_59;
V_8 = F_1 ( V_3 , V_33 . V_50 ) ;
if ( ( V_8 && V_33 . type == V_60 ) ||
( ! V_8 && V_33 . type == V_61 ) ) {
F_28 ( V_3 , L_4 ) ;
V_42 |= V_58 ;
}
if ( ! V_8 ) {
V_8 = F_3 ( V_3 , V_33 . V_50 ) ;
if ( F_32 ( V_8 ) ) {
V_41 = F_33 ( V_8 ) ;
goto V_47;
}
}
switch ( V_33 . type ) {
case V_60 : {
struct V_62 * V_55 ;
V_55 = F_26 ( V_39 , V_40 ,
struct V_62 ) ;
V_8 -> V_28 = F_34 ( V_39 , V_55 ) ;
V_8 -> V_63 = F_35 ( V_39 , V_55 ) ;
V_8 -> V_29 = F_36 ( V_39 , V_55 ) ;
V_8 -> V_64 = F_37 ( V_39 , V_55 ) ;
break;
}
case V_61 : {
struct V_65 * V_55 ;
V_55 = F_26 ( V_39 , V_40 ,
struct V_65 ) ;
V_8 -> V_66 = F_38 ( V_39 , V_55 ) ;
V_8 -> V_67 = F_39 ( V_39 , V_55 ) ;
V_8 -> V_68 = F_40 ( V_39 , V_55 ) ;
V_8 -> V_69 = F_41 ( V_39 , V_55 ) ;
V_8 -> V_70 = F_42 ( V_39 , V_55 ) ;
break;
}
}
V_59:
V_41 = F_43 ( V_35 , V_37 ) ;
if ( V_41 < 0 )
goto V_47;
if ( V_41 )
break;
}
F_44 ( V_37 ) ;
V_32 . V_49 = 0 ;
V_32 . type = V_71 ;
V_32 . V_50 = 0 ;
V_41 = F_24 ( V_35 , & V_32 , V_37 , 1 , 0 ) ;
if ( V_41 )
goto V_47;
while ( 1 ) {
V_40 = V_37 -> V_51 [ 0 ] ;
V_39 = V_37 -> V_52 [ 0 ] ;
F_25 ( V_39 , & V_33 , V_40 ) ;
if ( V_33 . type != V_71 )
goto V_72;
if ( V_33 . V_49 > V_33 . V_50 ) {
goto V_72;
}
V_41 = F_16 ( V_3 , V_33 . V_49 ,
V_33 . V_50 ) ;
if ( V_41 == - V_23 ) {
F_45 ( V_3 ,
L_5 ,
V_33 . V_49 , V_33 . V_50 ) ;
V_41 = 0 ;
}
if ( V_41 )
goto V_47;
V_72:
V_41 = F_43 ( V_35 , V_37 ) ;
if ( V_41 < 0 )
goto V_47;
if ( V_41 )
break;
}
V_47:
V_3 -> V_48 |= V_42 ;
if ( ! ( V_3 -> V_48 & V_73 ) ) {
V_3 -> V_44 = 0 ;
V_3 -> V_74 = 0 ;
} else if ( V_3 -> V_48 & V_75 &&
V_41 >= 0 ) {
V_41 = F_46 ( V_3 , V_43 , 0 ) ;
}
F_47 ( V_37 ) ;
if ( V_41 < 0 ) {
F_48 ( V_3 -> V_45 ) ;
V_3 -> V_45 = NULL ;
V_3 -> V_48 &= ~ V_75 ;
}
return V_41 < 0 ? V_41 : 0 ;
}
void F_49 ( struct V_2 * V_3 )
{
struct V_5 * V_6 ;
struct V_1 * V_8 ;
while ( ( V_6 = F_50 ( & V_3 -> V_7 ) ) ) {
V_8 = F_2 ( V_6 , struct V_1 , V_9 ) ;
F_15 ( V_6 , & V_3 -> V_7 ) ;
F_9 ( V_8 ) ;
}
F_48 ( V_3 -> V_45 ) ;
V_3 -> V_45 = NULL ;
}
static int F_51 ( struct V_76 * V_77 ,
struct V_34 * V_35 ,
T_1 V_78 , T_1 V_79 )
{
int V_41 ;
struct V_36 * V_37 ;
struct V_31 V_32 ;
V_37 = F_23 () ;
if ( ! V_37 )
return - V_15 ;
V_32 . V_49 = V_78 ;
V_32 . type = V_71 ;
V_32 . V_50 = V_79 ;
V_41 = F_52 ( V_77 , V_35 , V_37 , & V_32 , 0 ) ;
F_53 ( V_37 -> V_52 [ 0 ] ) ;
F_47 ( V_37 ) ;
return V_41 ;
}
static int F_54 ( struct V_76 * V_77 ,
struct V_34 * V_35 ,
T_1 V_78 , T_1 V_79 )
{
int V_41 ;
struct V_36 * V_37 ;
struct V_31 V_32 ;
V_37 = F_23 () ;
if ( ! V_37 )
return - V_15 ;
V_32 . V_49 = V_78 ;
V_32 . type = V_71 ;
V_32 . V_50 = V_79 ;
V_41 = F_55 ( V_77 , V_35 , & V_32 , V_37 , - 1 , 1 ) ;
if ( V_41 < 0 )
goto V_47;
if ( V_41 > 0 ) {
V_41 = - V_23 ;
goto V_47;
}
V_41 = F_56 ( V_77 , V_35 , V_37 ) ;
V_47:
F_47 ( V_37 ) ;
return V_41 ;
}
static int F_57 ( struct V_76 * V_77 ,
struct V_34 * V_35 , T_1 V_4 )
{
int V_41 ;
struct V_36 * V_37 ;
struct V_62 * V_80 ;
struct V_65 * V_81 ;
struct V_38 * V_82 ;
struct V_31 V_32 ;
if ( F_58 ( V_35 ) )
return 0 ;
V_37 = F_23 () ;
if ( ! V_37 )
return - V_15 ;
V_32 . V_49 = 0 ;
V_32 . type = V_60 ;
V_32 . V_50 = V_4 ;
V_41 = F_52 ( V_77 , V_35 , V_37 , & V_32 ,
sizeof( * V_80 ) ) ;
if ( V_41 && V_41 != - V_83 )
goto V_47;
V_82 = V_37 -> V_52 [ 0 ] ;
V_80 = F_26 ( V_82 , V_37 -> V_51 [ 0 ] ,
struct V_62 ) ;
F_59 ( V_82 , V_80 , V_77 -> V_84 ) ;
F_60 ( V_82 , V_80 , 0 ) ;
F_61 ( V_82 , V_80 , 0 ) ;
F_62 ( V_82 , V_80 , 0 ) ;
F_63 ( V_82 , V_80 , 0 ) ;
F_53 ( V_82 ) ;
F_44 ( V_37 ) ;
V_32 . type = V_61 ;
V_41 = F_52 ( V_77 , V_35 , V_37 , & V_32 ,
sizeof( * V_81 ) ) ;
if ( V_41 && V_41 != - V_83 )
goto V_47;
V_82 = V_37 -> V_52 [ 0 ] ;
V_81 = F_26 ( V_82 , V_37 -> V_51 [ 0 ] ,
struct V_65 ) ;
F_64 ( V_82 , V_81 , 0 ) ;
F_65 ( V_82 , V_81 , 0 ) ;
F_66 ( V_82 , V_81 , 0 ) ;
F_67 ( V_82 , V_81 , 0 ) ;
F_68 ( V_82 , V_81 , 0 ) ;
F_53 ( V_82 ) ;
V_41 = 0 ;
V_47:
F_47 ( V_37 ) ;
return V_41 ;
}
static int F_69 ( struct V_76 * V_77 ,
struct V_34 * V_35 , T_1 V_4 )
{
int V_41 ;
struct V_36 * V_37 ;
struct V_31 V_32 ;
V_37 = F_23 () ;
if ( ! V_37 )
return - V_15 ;
V_32 . V_49 = 0 ;
V_32 . type = V_60 ;
V_32 . V_50 = V_4 ;
V_41 = F_55 ( V_77 , V_35 , & V_32 , V_37 , - 1 , 1 ) ;
if ( V_41 < 0 )
goto V_47;
if ( V_41 > 0 ) {
V_41 = - V_23 ;
goto V_47;
}
V_41 = F_56 ( V_77 , V_35 , V_37 ) ;
if ( V_41 )
goto V_47;
F_44 ( V_37 ) ;
V_32 . type = V_61 ;
V_41 = F_55 ( V_77 , V_35 , & V_32 , V_37 , - 1 , 1 ) ;
if ( V_41 < 0 )
goto V_47;
if ( V_41 > 0 ) {
V_41 = - V_23 ;
goto V_47;
}
V_41 = F_56 ( V_77 , V_35 , V_37 ) ;
V_47:
F_47 ( V_37 ) ;
return V_41 ;
}
static int F_70 ( struct V_76 * V_77 ,
struct V_34 * V_85 , T_1 V_4 ,
T_1 V_42 , T_1 V_67 , T_1 V_68 ,
T_1 V_69 , T_1 V_70 )
{
struct V_36 * V_37 ;
struct V_31 V_32 ;
struct V_38 * V_39 ;
struct V_65 * V_81 ;
int V_41 ;
int V_40 ;
V_32 . V_49 = 0 ;
V_32 . type = V_61 ;
V_32 . V_50 = V_4 ;
V_37 = F_23 () ;
if ( ! V_37 )
return - V_15 ;
V_41 = F_55 ( V_77 , V_85 , & V_32 , V_37 , 0 , 1 ) ;
if ( V_41 > 0 )
V_41 = - V_23 ;
if ( V_41 )
goto V_47;
V_39 = V_37 -> V_52 [ 0 ] ;
V_40 = V_37 -> V_51 [ 0 ] ;
V_81 = F_26 ( V_39 , V_40 , struct V_65 ) ;
F_64 ( V_39 , V_81 , V_42 ) ;
F_65 ( V_39 , V_81 , V_67 ) ;
F_66 ( V_39 , V_81 , V_68 ) ;
F_67 ( V_39 , V_81 , V_69 ) ;
F_68 ( V_39 , V_81 , V_70 ) ;
F_53 ( V_39 ) ;
V_47:
F_47 ( V_37 ) ;
return V_41 ;
}
static int F_71 ( struct V_76 * V_77 ,
struct V_34 * V_85 ,
struct V_1 * V_8 )
{
struct V_36 * V_37 ;
struct V_31 V_32 ;
struct V_38 * V_39 ;
struct V_62 * V_80 ;
int V_41 ;
int V_40 ;
if ( F_58 ( V_85 ) )
return 0 ;
V_32 . V_49 = 0 ;
V_32 . type = V_60 ;
V_32 . V_50 = V_8 -> V_4 ;
V_37 = F_23 () ;
if ( ! V_37 )
return - V_15 ;
V_41 = F_55 ( V_77 , V_85 , & V_32 , V_37 , 0 , 1 ) ;
if ( V_41 > 0 )
V_41 = - V_23 ;
if ( V_41 )
goto V_47;
V_39 = V_37 -> V_52 [ 0 ] ;
V_40 = V_37 -> V_51 [ 0 ] ;
V_80 = F_26 ( V_39 , V_40 , struct V_62 ) ;
F_59 ( V_39 , V_80 , V_77 -> V_84 ) ;
F_60 ( V_39 , V_80 , V_8 -> V_28 ) ;
F_61 ( V_39 , V_80 , V_8 -> V_63 ) ;
F_62 ( V_39 , V_80 , V_8 -> V_29 ) ;
F_63 ( V_39 , V_80 , V_8 -> V_64 ) ;
F_53 ( V_39 ) ;
V_47:
F_47 ( V_37 ) ;
return V_41 ;
}
static int F_72 ( struct V_76 * V_77 ,
struct V_2 * V_3 ,
struct V_34 * V_85 )
{
struct V_36 * V_37 ;
struct V_31 V_32 ;
struct V_38 * V_39 ;
struct V_54 * V_55 ;
int V_41 ;
int V_40 ;
V_32 . V_49 = 0 ;
V_32 . type = V_53 ;
V_32 . V_50 = 0 ;
V_37 = F_23 () ;
if ( ! V_37 )
return - V_15 ;
V_41 = F_55 ( V_77 , V_85 , & V_32 , V_37 , 0 , 1 ) ;
if ( V_41 > 0 )
V_41 = - V_23 ;
if ( V_41 )
goto V_47;
V_39 = V_37 -> V_52 [ 0 ] ;
V_40 = V_37 -> V_51 [ 0 ] ;
V_55 = F_26 ( V_39 , V_40 , struct V_54 ) ;
F_73 ( V_39 , V_55 , V_3 -> V_48 ) ;
F_74 ( V_39 , V_55 , V_77 -> V_84 ) ;
F_75 ( V_39 , V_55 ,
V_3 -> V_86 . V_49 ) ;
F_53 ( V_39 ) ;
V_47:
F_47 ( V_37 ) ;
return V_41 ;
}
static int F_76 ( struct V_76 * V_77 ,
struct V_34 * V_85 )
{
struct V_36 * V_37 ;
struct V_31 V_32 ;
struct V_38 * V_82 = NULL ;
int V_41 ;
int V_87 = 0 ;
V_37 = F_23 () ;
if ( ! V_37 )
return - V_15 ;
V_37 -> V_88 = 1 ;
V_32 . V_49 = 0 ;
V_32 . V_50 = 0 ;
V_32 . type = 0 ;
while ( 1 ) {
V_41 = F_55 ( V_77 , V_85 , & V_32 , V_37 , - 1 , 1 ) ;
if ( V_41 < 0 )
goto V_47;
V_82 = V_37 -> V_52 [ 0 ] ;
V_87 = F_77 ( V_82 ) ;
if ( ! V_87 )
break;
V_37 -> V_51 [ 0 ] = 0 ;
V_41 = F_78 ( V_77 , V_85 , V_37 , 0 , V_87 ) ;
if ( V_41 )
goto V_47;
F_44 ( V_37 ) ;
}
V_41 = 0 ;
V_47:
V_85 -> V_3 -> V_74 = 0 ;
F_47 ( V_37 ) ;
return V_41 ;
}
int F_79 ( struct V_76 * V_77 ,
struct V_2 * V_3 )
{
struct V_34 * V_35 ;
struct V_34 * V_89 = V_3 -> V_89 ;
struct V_36 * V_37 = NULL ;
struct V_54 * V_55 ;
struct V_38 * V_82 ;
struct V_31 V_32 ;
struct V_31 V_33 ;
struct V_1 * V_8 = NULL ;
int V_41 = 0 ;
int V_40 ;
F_80 ( & V_3 -> V_90 ) ;
if ( V_3 -> V_35 ) {
V_3 -> V_74 = 1 ;
goto V_47;
}
V_3 -> V_45 = F_22 ( V_46 ) ;
if ( ! V_3 -> V_45 ) {
V_41 = - V_15 ;
goto V_47;
}
V_35 = F_81 ( V_77 , V_3 ,
V_91 ) ;
if ( F_32 ( V_35 ) ) {
V_41 = F_33 ( V_35 ) ;
goto V_47;
}
V_37 = F_23 () ;
if ( ! V_37 ) {
V_41 = - V_15 ;
goto V_92;
}
V_32 . V_49 = 0 ;
V_32 . type = V_53 ;
V_32 . V_50 = 0 ;
V_41 = F_52 ( V_77 , V_35 , V_37 , & V_32 ,
sizeof( * V_55 ) ) ;
if ( V_41 )
goto V_93;
V_82 = V_37 -> V_52 [ 0 ] ;
V_55 = F_26 ( V_82 , V_37 -> V_51 [ 0 ] ,
struct V_54 ) ;
F_74 ( V_82 , V_55 , V_77 -> V_84 ) ;
F_82 ( V_82 , V_55 , V_56 ) ;
V_3 -> V_48 = V_73 |
V_58 ;
F_73 ( V_82 , V_55 , V_3 -> V_48 ) ;
F_75 ( V_82 , V_55 , 0 ) ;
F_53 ( V_82 ) ;
V_32 . V_49 = 0 ;
V_32 . type = V_94 ;
V_32 . V_50 = 0 ;
F_44 ( V_37 ) ;
V_41 = F_24 ( V_89 , & V_32 , V_37 , 1 , 0 ) ;
if ( V_41 > 0 )
goto V_95;
if ( V_41 < 0 )
goto V_93;
while ( 1 ) {
V_40 = V_37 -> V_51 [ 0 ] ;
V_82 = V_37 -> V_52 [ 0 ] ;
F_25 ( V_82 , & V_33 , V_40 ) ;
if ( V_33 . type == V_94 ) {
V_41 = F_57 ( V_77 , V_35 ,
V_33 . V_50 ) ;
if ( V_41 )
goto V_93;
V_8 = F_3 ( V_3 , V_33 . V_50 ) ;
if ( F_32 ( V_8 ) ) {
V_41 = F_33 ( V_8 ) ;
goto V_93;
}
}
V_41 = F_43 ( V_89 , V_37 ) ;
if ( V_41 < 0 )
goto V_93;
if ( V_41 )
break;
}
V_95:
F_44 ( V_37 ) ;
V_41 = F_57 ( V_77 , V_35 , V_96 ) ;
if ( V_41 )
goto V_93;
V_8 = F_3 ( V_3 , V_96 ) ;
if ( F_32 ( V_8 ) ) {
V_41 = F_33 ( V_8 ) ;
goto V_93;
}
F_83 ( & V_3 -> V_97 ) ;
V_3 -> V_35 = V_35 ;
V_3 -> V_74 = 1 ;
F_84 ( & V_3 -> V_97 ) ;
V_93:
F_47 ( V_37 ) ;
V_92:
if ( V_41 ) {
F_85 ( V_35 -> V_9 ) ;
F_85 ( V_35 -> V_98 ) ;
F_13 ( V_35 ) ;
}
V_47:
if ( V_41 ) {
F_48 ( V_3 -> V_45 ) ;
V_3 -> V_45 = NULL ;
}
F_86 ( & V_3 -> V_90 ) ;
return V_41 ;
}
int F_87 ( struct V_76 * V_77 ,
struct V_2 * V_3 )
{
struct V_34 * V_89 = V_3 -> V_89 ;
struct V_34 * V_35 ;
int V_41 = 0 ;
F_80 ( & V_3 -> V_90 ) ;
if ( ! V_3 -> V_35 )
goto V_47;
F_83 ( & V_3 -> V_97 ) ;
V_3 -> V_44 = 0 ;
V_3 -> V_74 = 0 ;
V_35 = V_3 -> V_35 ;
V_3 -> V_35 = NULL ;
F_84 ( & V_3 -> V_97 ) ;
F_49 ( V_3 ) ;
V_41 = F_76 ( V_77 , V_35 ) ;
if ( V_41 )
goto V_47;
V_41 = F_88 ( V_77 , V_89 , & V_35 -> V_99 ) ;
if ( V_41 )
goto V_47;
F_10 ( & V_35 -> V_100 ) ;
F_89 ( V_35 -> V_9 ) ;
F_90 ( V_77 , V_89 , V_35 -> V_9 ) ;
F_91 ( V_35 -> V_9 ) ;
F_92 ( V_77 , V_35 , V_35 -> V_9 , 0 , 1 ) ;
F_85 ( V_35 -> V_9 ) ;
F_85 ( V_35 -> V_98 ) ;
F_13 ( V_35 ) ;
V_47:
F_86 ( & V_3 -> V_90 ) ;
return V_41 ;
}
static void F_93 ( struct V_2 * V_3 ,
struct V_1 * V_8 )
{
if ( F_11 ( & V_8 -> V_18 ) )
F_94 ( & V_8 -> V_18 , & V_3 -> V_101 ) ;
}
int F_95 ( struct V_76 * V_77 ,
struct V_2 * V_3 , T_1 V_78 , T_1 V_79 )
{
struct V_34 * V_35 ;
struct V_1 * V_13 ;
struct V_1 * V_26 ;
struct V_19 * V_20 ;
int V_41 = 0 ;
F_80 ( & V_3 -> V_90 ) ;
V_35 = V_3 -> V_35 ;
if ( ! V_35 ) {
V_41 = - V_30 ;
goto V_47;
}
V_26 = F_1 ( V_3 , V_78 ) ;
V_13 = F_1 ( V_3 , V_79 ) ;
if ( ! V_26 || ! V_13 ) {
V_41 = - V_30 ;
goto V_47;
}
F_19 (list, &member->groups, next_group) {
if ( V_20 -> V_27 == V_13 ) {
V_41 = - V_83 ;
goto V_47;
}
}
V_41 = F_51 ( V_77 , V_35 , V_78 , V_79 ) ;
if ( V_41 )
goto V_47;
V_41 = F_51 ( V_77 , V_35 , V_79 , V_78 ) ;
if ( V_41 ) {
F_54 ( V_77 , V_35 , V_78 , V_79 ) ;
goto V_47;
}
F_83 ( & V_3 -> V_97 ) ;
V_41 = F_16 ( V_35 -> V_3 , V_78 , V_79 ) ;
F_84 ( & V_3 -> V_97 ) ;
V_47:
F_86 ( & V_3 -> V_90 ) ;
return V_41 ;
}
int F_96 ( struct V_76 * V_77 ,
struct V_2 * V_3 , T_1 V_78 , T_1 V_79 )
{
struct V_34 * V_35 ;
struct V_1 * V_13 ;
struct V_1 * V_26 ;
struct V_19 * V_20 ;
int V_41 = 0 ;
int V_102 ;
F_80 ( & V_3 -> V_90 ) ;
V_35 = V_3 -> V_35 ;
if ( ! V_35 ) {
V_41 = - V_30 ;
goto V_47;
}
V_26 = F_1 ( V_3 , V_78 ) ;
V_13 = F_1 ( V_3 , V_79 ) ;
if ( ! V_26 || ! V_13 ) {
V_41 = - V_30 ;
goto V_47;
}
F_19 (list, &member->groups, next_group) {
if ( V_20 -> V_27 == V_13 )
goto V_103;
}
V_41 = - V_23 ;
goto V_47;
V_103:
V_41 = F_54 ( V_77 , V_35 , V_78 , V_79 ) ;
V_102 = F_54 ( V_77 , V_35 , V_79 , V_78 ) ;
if ( V_102 && ! V_41 )
V_41 = V_102 ;
F_83 ( & V_3 -> V_97 ) ;
F_18 ( V_3 , V_78 , V_79 ) ;
F_84 ( & V_3 -> V_97 ) ;
V_47:
F_86 ( & V_3 -> V_90 ) ;
return V_41 ;
}
int F_97 ( struct V_76 * V_77 ,
struct V_2 * V_3 , T_1 V_4 , char * V_104 )
{
struct V_34 * V_35 ;
struct V_1 * V_8 ;
int V_41 = 0 ;
F_80 ( & V_3 -> V_90 ) ;
V_35 = V_3 -> V_35 ;
if ( ! V_35 ) {
V_41 = - V_30 ;
goto V_47;
}
V_8 = F_1 ( V_3 , V_4 ) ;
if ( V_8 ) {
V_41 = - V_83 ;
goto V_47;
}
V_41 = F_57 ( V_77 , V_35 , V_4 ) ;
if ( V_41 )
goto V_47;
F_83 ( & V_3 -> V_97 ) ;
V_8 = F_3 ( V_3 , V_4 ) ;
F_84 ( & V_3 -> V_97 ) ;
if ( F_32 ( V_8 ) )
V_41 = F_33 ( V_8 ) ;
V_47:
F_86 ( & V_3 -> V_90 ) ;
return V_41 ;
}
int F_98 ( struct V_76 * V_77 ,
struct V_2 * V_3 , T_1 V_4 )
{
struct V_34 * V_35 ;
struct V_1 * V_8 ;
int V_41 = 0 ;
F_80 ( & V_3 -> V_90 ) ;
V_35 = V_3 -> V_35 ;
if ( ! V_35 ) {
V_41 = - V_30 ;
goto V_47;
}
V_8 = F_1 ( V_3 , V_4 ) ;
if ( ! V_8 ) {
V_41 = - V_23 ;
goto V_47;
} else {
if ( ! F_11 ( & V_8 -> V_16 ) ||
! F_11 ( & V_8 -> V_17 ) ) {
V_41 = - V_105 ;
goto V_47;
}
}
V_41 = F_69 ( V_77 , V_35 , V_4 ) ;
F_83 ( & V_3 -> V_97 ) ;
F_14 ( V_35 -> V_3 , V_4 ) ;
F_84 ( & V_3 -> V_97 ) ;
V_47:
F_86 ( & V_3 -> V_90 ) ;
return V_41 ;
}
int F_99 ( struct V_76 * V_77 ,
struct V_2 * V_3 , T_1 V_4 ,
struct V_106 * V_107 )
{
struct V_34 * V_35 ;
struct V_1 * V_8 ;
int V_41 = 0 ;
F_80 ( & V_3 -> V_90 ) ;
V_35 = V_3 -> V_35 ;
if ( ! V_35 ) {
V_41 = - V_30 ;
goto V_47;
}
V_8 = F_1 ( V_3 , V_4 ) ;
if ( ! V_8 ) {
V_41 = - V_23 ;
goto V_47;
}
V_41 = F_70 ( V_77 , V_35 , V_4 ,
V_107 -> V_42 , V_107 -> V_67 ,
V_107 -> V_68 , V_107 -> V_69 ,
V_107 -> V_70 ) ;
if ( V_41 ) {
V_3 -> V_48 |= V_58 ;
F_100 ( V_3 , L_6 ,
V_4 ) ;
}
F_83 ( & V_3 -> V_97 ) ;
V_8 -> V_66 = V_107 -> V_42 ;
V_8 -> V_67 = V_107 -> V_67 ;
V_8 -> V_68 = V_107 -> V_68 ;
V_8 -> V_69 = V_107 -> V_69 ;
V_8 -> V_70 = V_107 -> V_70 ;
F_84 ( & V_3 -> V_97 ) ;
V_47:
F_86 ( & V_3 -> V_90 ) ;
return V_41 ;
}
static int F_101 ( struct V_108 * V_109 ,
struct V_108 * V_110 )
{
if ( V_109 -> V_111 < V_110 -> V_111 )
return - 1 ;
if ( V_109 -> V_111 > V_110 -> V_111 )
return 1 ;
if ( V_109 -> V_112 < V_110 -> V_112 )
return - 1 ;
if ( V_109 -> V_112 > V_110 -> V_112 )
return 1 ;
return 0 ;
}
static int F_102 ( struct V_2 * V_3 ,
struct V_108 * V_113 )
{
struct V_5 * V_6 ;
struct V_108 * V_114 ;
int V_115 ;
F_83 ( & V_3 -> V_116 ) ;
V_6 = V_3 -> V_117 . V_5 ;
while ( V_6 ) {
V_114 = F_2 ( V_6 , struct V_108 , V_6 ) ;
V_115 = F_101 ( V_114 , V_113 ) ;
if ( V_115 < 0 ) {
V_6 = V_6 -> V_11 ;
} else if ( V_115 ) {
V_6 = V_6 -> V_10 ;
} else {
F_84 ( & V_3 -> V_116 ) ;
return - V_83 ;
}
}
F_84 ( & V_3 -> V_116 ) ;
return 0 ;
}
static int F_103 ( struct V_108 * V_109 ,
struct V_108 * V_110 )
{
if ( V_109 -> V_111 < V_110 -> V_111 )
return - 1 ;
if ( V_109 -> V_111 > V_110 -> V_111 )
return 1 ;
if ( V_109 -> V_118 < V_110 -> V_118 )
return - 1 ;
if ( V_109 -> V_118 > V_110 -> V_118 )
return 1 ;
if ( V_109 -> V_112 < V_110 -> V_112 )
return - 1 ;
if ( V_109 -> V_112 > V_110 -> V_112 )
return 1 ;
if ( V_109 -> type < V_110 -> type )
return - 1 ;
if ( V_109 -> type > V_110 -> type )
return 1 ;
return 0 ;
}
static int F_104 ( struct V_2 * V_3 ,
struct V_108 * V_113 )
{
struct V_5 * * V_12 ;
struct V_5 * V_13 = NULL ;
struct V_108 * V_114 ;
int V_115 ;
F_83 ( & V_3 -> V_116 ) ;
V_12 = & V_3 -> V_117 . V_5 ;
while ( * V_12 ) {
V_13 = * V_12 ;
V_114 = F_2 ( V_13 , struct V_108 , V_6 ) ;
V_115 = F_103 ( V_114 , V_113 ) ;
if ( V_115 < 0 ) {
V_12 = & ( * V_12 ) -> V_11 ;
} else if ( V_115 ) {
V_12 = & ( * V_12 ) -> V_10 ;
} else {
F_84 ( & V_3 -> V_116 ) ;
return - V_83 ;
}
}
F_7 ( & V_113 -> V_6 , V_13 , V_12 ) ;
F_8 ( & V_113 -> V_6 , & V_3 -> V_117 ) ;
F_84 ( & V_3 -> V_116 ) ;
return 0 ;
}
int F_105 ( struct V_76 * V_77 ,
struct V_2 * V_3 , T_1 V_112 ,
T_1 V_111 , T_1 V_119 ,
enum V_120 type , int V_121 )
{
struct V_108 * V_113 ;
int V_41 ;
if ( ! F_106 ( V_112 ) || ! V_3 -> V_44 )
return 0 ;
V_113 = F_107 ( sizeof( * V_113 ) , V_46 ) ;
if ( ! V_113 )
return - V_15 ;
V_113 -> V_112 = V_112 ;
V_113 -> V_111 = V_111 ;
V_113 -> V_119 = V_119 ;
V_113 -> type = type ;
V_113 -> V_118 = F_108 ( & V_3 -> V_122 ) ;
F_6 ( & V_113 -> V_123 . V_20 ) ;
V_113 -> V_123 . V_118 = 0 ;
F_109 ( V_113 ) ;
if ( type == V_124 ) {
if ( F_102 ( V_3 , V_113 ) ) {
F_13 ( V_113 ) ;
return 0 ;
}
}
V_41 = F_104 ( V_3 , V_113 ) ;
if ( V_41 ) {
ASSERT ( 0 ) ;
F_13 ( V_113 ) ;
return V_41 ;
}
F_17 ( & V_113 -> V_20 , & V_77 -> V_125 ) ;
if ( V_121 )
F_110 ( V_3 , & V_113 -> V_123 ) ;
return 0 ;
}
static int F_111 ( struct V_2 * V_3 ,
struct V_108 * V_113 )
{
struct V_1 * V_8 ;
struct V_126 * V_127 ;
struct V_19 * V_128 ;
struct V_129 * V_130 ;
struct V_131 V_132 ;
int V_133 = 0 ;
int V_41 = 0 ;
V_127 = F_22 ( V_46 ) ;
if ( ! V_127 )
return - V_15 ;
F_83 ( & V_3 -> V_97 ) ;
if ( ! V_3 -> V_35 )
goto V_47;
V_8 = F_1 ( V_3 , V_113 -> V_112 ) ;
if ( ! V_8 )
goto V_47;
switch ( V_113 -> type ) {
case V_134 :
V_133 = 1 ;
break;
case V_135 :
V_133 = - 1 ;
break;
default:
ASSERT ( 0 ) ;
}
V_8 -> V_28 += V_133 * V_113 -> V_119 ;
V_8 -> V_63 += V_133 * V_113 -> V_119 ;
F_112 ( V_133 < 0 && V_8 -> V_29 < V_113 -> V_119 ) ;
V_8 -> V_29 += V_133 * V_113 -> V_119 ;
V_8 -> V_64 += V_133 * V_113 -> V_119 ;
F_93 ( V_3 , V_8 ) ;
F_19 (glist, &qgroup->groups, next_group) {
V_41 = F_113 ( V_127 , V_128 -> V_27 -> V_4 ,
F_114 ( V_128 -> V_27 ) , V_14 ) ;
if ( V_41 < 0 )
goto V_47;
}
F_115 ( & V_132 ) ;
while ( ( V_130 = F_116 ( V_127 , & V_132 ) ) ) {
V_8 = F_117 ( V_130 -> V_136 ) ;
V_8 -> V_28 += V_133 * V_113 -> V_119 ;
V_8 -> V_63 += V_133 * V_113 -> V_119 ;
F_112 ( V_133 < 0 && V_8 -> V_29 < V_113 -> V_119 ) ;
V_8 -> V_29 += V_133 * V_113 -> V_119 ;
V_8 -> V_64 += V_133 * V_113 -> V_119 ;
F_93 ( V_3 , V_8 ) ;
F_19 (glist, &qgroup->groups, next_group) {
V_41 = F_113 ( V_127 , V_128 -> V_27 -> V_4 ,
F_114 ( V_128 -> V_27 ) , V_14 ) ;
if ( V_41 < 0 )
goto V_47;
}
}
V_41 = 0 ;
V_47:
F_84 ( & V_3 -> V_97 ) ;
F_48 ( V_127 ) ;
return V_41 ;
}
static int F_118 ( struct V_2 * V_3 ,
T_1 V_137 , struct V_126 * V_127 ,
struct V_126 * V_138 , struct V_126 * V_139 ,
T_1 V_118 , int * V_140 , int V_141 )
{
struct V_129 * V_130 ;
struct V_131 V_132 ;
struct V_129 * V_142 ;
struct V_131 V_143 ;
struct V_1 * V_144 ;
int V_41 ;
F_115 ( & V_132 ) ;
while ( ( V_130 = F_116 ( V_138 , & V_132 ) ) ) {
if ( V_130 -> V_145 == V_137 )
continue;
V_144 = F_1 ( V_3 , V_130 -> V_145 ) ;
if ( ! V_144 )
continue;
( * V_140 ) ++ ;
F_119 ( V_127 ) ;
V_41 = F_113 ( V_139 , V_144 -> V_4 , F_114 ( V_144 ) ,
V_14 ) ;
if ( V_41 < 0 )
return V_41 ;
V_41 = F_113 ( V_127 , V_144 -> V_4 , F_114 ( V_144 ) , V_14 ) ;
if ( V_41 < 0 )
return V_41 ;
F_115 ( & V_143 ) ;
while ( ( V_142 = F_116 ( V_127 , & V_143 ) ) ) {
struct V_19 * V_128 ;
V_144 = F_117 ( V_142 -> V_136 ) ;
if ( V_141 )
V_144 -> V_146 = V_118 ;
else if ( V_144 -> V_146 < V_118 )
V_144 -> V_146 = V_118 + 1 ;
else
V_144 -> V_146 ++ ;
if ( V_144 -> V_147 < V_118 )
V_144 -> V_147 = V_118 + 1 ;
else
V_144 -> V_147 ++ ;
F_19 (glist, &qg->groups, next_group) {
V_41 = F_113 ( V_139 , V_128 -> V_27 -> V_4 ,
F_114 ( V_128 -> V_27 ) ,
V_14 ) ;
if ( V_41 < 0 )
return V_41 ;
V_41 = F_113 ( V_127 , V_128 -> V_27 -> V_4 ,
F_114 ( V_128 -> V_27 ) ,
V_14 ) ;
if ( V_41 < 0 )
return V_41 ;
}
}
}
return 0 ;
}
static int F_120 ( struct V_2 * V_3 ,
struct V_108 * V_113 ,
struct V_126 * V_127 ,
struct V_126 * V_139 , T_1 V_118 ,
int * V_140 )
{
struct V_129 * V_130 ;
struct V_131 V_132 ;
struct V_1 * V_144 ;
struct V_108 * V_148 ;
struct V_5 * V_6 ;
int V_41 ;
F_119 ( V_127 ) ;
F_83 ( & V_3 -> V_116 ) ;
V_6 = F_121 ( & V_113 -> V_6 ) ;
F_84 ( & V_3 -> V_116 ) ;
if ( ! V_6 )
return 0 ;
V_148 = F_2 ( V_6 , struct V_108 , V_6 ) ;
while ( V_148 -> V_111 == V_113 -> V_111 ) {
if ( V_148 -> type != V_149 &&
V_148 -> type != V_135 )
goto V_150;
V_144 = F_1 ( V_3 , V_148 -> V_112 ) ;
if ( ! V_144 )
goto V_150;
V_41 = F_113 ( V_139 , V_144 -> V_4 , F_114 ( V_144 ) ,
V_14 ) ;
if ( V_41 ) {
if ( V_41 < 0 )
return V_41 ;
( * V_140 ) ++ ;
V_41 = F_113 ( V_127 , V_144 -> V_4 , F_114 ( V_144 ) ,
V_14 ) ;
if ( V_41 < 0 )
return V_41 ;
}
V_150:
F_83 ( & V_3 -> V_116 ) ;
V_6 = F_121 ( & V_148 -> V_6 ) ;
F_84 ( & V_3 -> V_116 ) ;
if ( ! V_6 )
break;
V_148 = F_2 ( V_6 , struct V_108 , V_6 ) ;
}
F_115 ( & V_132 ) ;
while ( ( V_130 = F_116 ( V_127 , & V_132 ) ) ) {
struct V_19 * V_128 ;
V_144 = F_117 ( V_130 -> V_136 ) ;
if ( V_144 -> V_146 < V_118 )
V_144 -> V_146 = V_118 + 1 ;
else
V_144 -> V_146 ++ ;
if ( V_144 -> V_147 < V_118 )
V_144 -> V_147 = V_118 + 1 ;
else
V_144 -> V_147 ++ ;
F_19 (glist, &qg->groups, next_group) {
V_41 = F_113 ( V_139 , V_128 -> V_27 -> V_4 ,
F_114 ( V_128 -> V_27 ) , V_14 ) ;
if ( V_41 < 0 )
return V_41 ;
V_41 = F_113 ( V_127 , V_128 -> V_27 -> V_4 ,
F_114 ( V_128 -> V_27 ) , V_14 ) ;
if ( V_41 < 0 )
return V_41 ;
}
}
return 0 ;
}
static int F_122 ( struct V_2 * V_3 ,
struct V_108 * V_113 ,
struct V_1 * V_8 ,
struct V_126 * V_127 , struct V_126 * V_139 ,
T_1 V_118 )
{
struct V_129 * V_130 ;
struct V_131 V_132 ;
struct V_1 * V_144 ;
int V_41 ;
F_119 ( V_127 ) ;
V_41 = F_113 ( V_139 , V_8 -> V_4 , F_114 ( V_8 ) ,
V_14 ) ;
if ( V_41 < 0 )
return V_41 ;
V_41 = F_113 ( V_127 , V_8 -> V_4 , F_114 ( V_8 ) ,
V_14 ) ;
if ( V_41 < 0 )
return V_41 ;
F_115 ( & V_132 ) ;
while ( ( V_130 = F_116 ( V_127 , & V_132 ) ) ) {
struct V_19 * V_128 ;
V_144 = F_117 ( V_130 -> V_136 ) ;
if ( V_113 -> type == V_151 ) {
if ( V_144 -> V_147 < V_118 )
V_144 -> V_147 = V_118 + 1 ;
else
V_144 -> V_147 ++ ;
} else {
if ( V_144 -> V_146 < V_118 )
V_144 -> V_146 = V_118 + 1 ;
else
V_144 -> V_146 ++ ;
}
F_19 (glist, &qg->groups, next_group) {
V_41 = F_113 ( V_127 , V_128 -> V_27 -> V_4 ,
F_114 ( V_128 -> V_27 ) , V_14 ) ;
if ( V_41 < 0 )
return V_41 ;
V_41 = F_113 ( V_139 , V_128 -> V_27 -> V_4 ,
F_114 ( V_128 -> V_27 ) , V_14 ) ;
if ( V_41 < 0 )
return V_41 ;
}
}
return 0 ;
}
static int F_123 ( struct V_2 * V_3 ,
T_1 V_137 , T_1 V_119 ,
struct V_126 * V_139 , T_1 V_118 ,
int V_140 , int V_152 , int V_141 )
{
struct V_129 * V_130 ;
struct V_131 V_132 ;
struct V_1 * V_144 ;
T_1 V_153 , V_154 ;
F_115 ( & V_132 ) ;
while ( ( V_130 = F_116 ( V_139 , & V_132 ) ) ) {
bool V_18 = false ;
V_144 = F_117 ( V_130 -> V_136 ) ;
if ( V_144 -> V_146 <= V_118 && V_144 -> V_147 > V_118 ) {
V_144 -> V_28 += V_119 ;
V_144 -> V_63 += V_119 ;
V_18 = true ;
}
if ( V_144 -> V_146 > V_118 && V_144 -> V_147 <= V_118 ) {
V_144 -> V_28 -= V_119 ;
V_144 -> V_63 -= V_119 ;
V_18 = true ;
}
if ( V_144 -> V_146 < V_118 )
V_154 = 0 ;
else
V_154 = V_144 -> V_146 - V_118 ;
if ( V_144 -> V_147 < V_118 )
V_153 = 0 ;
else
V_153 = V_144 -> V_147 - V_118 ;
if ( V_140 && V_154 == V_140 &&
( V_153 != V_152 || V_152 == 0 ) ) {
F_112 ( V_153 != V_152 && V_152 == 0 ) ;
V_144 -> V_29 -= V_119 ;
V_144 -> V_64 -= V_119 ;
V_18 = true ;
}
if ( ( ! V_140 || ( V_140 && V_154 != V_140 ) )
&& V_153 == V_152 ) {
V_144 -> V_29 += V_119 ;
V_144 -> V_64 += V_119 ;
V_18 = true ;
}
if ( V_18 )
F_93 ( V_3 , V_144 ) ;
}
return 0 ;
}
static int F_124 ( struct V_76 * V_77 ,
struct V_2 * V_3 ,
struct V_108 * V_113 )
{
struct V_126 * V_138 = NULL ;
struct V_129 * V_130 ;
struct V_131 V_132 ;
int V_41 = 0 ;
V_41 = F_125 ( V_77 , V_3 , V_113 -> V_111 ,
V_113 -> V_123 . V_118 , & V_138 ) ;
if ( V_41 < 0 )
return V_41 ;
V_41 = 0 ;
F_115 ( & V_132 ) ;
while ( ( V_130 = F_116 ( V_138 , & V_132 ) ) ) {
if ( V_130 -> V_145 == V_113 -> V_112 ) {
V_41 = 1 ;
break;
}
}
F_48 ( V_138 ) ;
F_126 ( V_3 , & V_113 -> V_123 ) ;
return V_41 ;
}
static int F_127 ( struct V_76 * V_77 ,
struct V_2 * V_3 ,
struct V_108 * V_113 )
{
struct V_126 * V_138 = NULL ;
struct V_126 * V_139 , * V_127 ;
struct V_1 * V_8 ;
struct V_155 V_123 = {} ;
T_1 V_118 ;
int V_140 = 0 ;
int V_152 = 0 ;
int V_41 = 0 ;
if ( V_113 -> V_123 . V_118 ) {
V_41 = F_124 ( V_77 , V_3 , V_113 ) ;
if ( V_41 < 0 )
return V_41 ;
if ( V_41 )
return 0 ;
}
V_139 = F_22 ( V_46 ) ;
if ( ! V_139 )
return - V_15 ;
V_127 = F_22 ( V_46 ) ;
if ( ! V_127 ) {
F_48 ( V_139 ) ;
return - V_15 ;
}
F_110 ( V_3 , & V_123 ) ;
V_41 = F_125 ( V_77 , V_3 , V_113 -> V_111 , V_123 . V_118 ,
& V_138 ) ;
F_126 ( V_3 , & V_123 ) ;
if ( V_41 < 0 ) {
F_48 ( V_139 ) ;
F_48 ( V_127 ) ;
return V_41 ;
}
F_83 ( & V_3 -> V_97 ) ;
V_8 = F_1 ( V_3 , V_113 -> V_112 ) ;
if ( ! V_8 )
goto V_47;
V_118 = V_3 -> V_156 ;
V_41 = F_118 ( V_3 , V_113 -> V_112 , V_127 , V_138 , V_139 ,
V_118 , & V_140 , 0 ) ;
if ( V_41 < 0 )
goto V_47;
V_41 = F_122 ( V_3 , V_113 , V_8 , V_127 , V_139 ,
V_118 ) ;
if ( V_41 < 0 )
goto V_47;
V_41 = F_120 ( V_3 , V_113 , V_127 , V_139 , V_118 ,
& V_140 ) ;
if ( V_41 < 0 )
goto V_47;
if ( V_113 -> type == V_151 ) {
V_152 = V_140 + 1 ;
} else {
V_152 = V_140 ;
V_140 ++ ;
}
V_3 -> V_156 += V_140 + 1 ;
F_123 ( V_3 , V_113 -> V_112 , V_113 -> V_119 ,
V_139 , V_118 , V_140 , V_152 , 0 ) ;
V_47:
F_84 ( & V_3 -> V_97 ) ;
F_48 ( V_139 ) ;
F_48 ( V_138 ) ;
F_48 ( V_127 ) ;
return V_41 ;
}
static int F_128 ( struct V_76 * V_77 ,
struct V_2 * V_3 ,
struct V_108 * V_113 )
{
struct V_126 * V_138 = NULL ;
struct V_129 * V_130 ;
struct V_131 V_132 ;
struct V_19 * V_128 ;
struct V_126 * V_157 ;
int V_41 = 0 ;
int V_102 ;
struct V_1 * V_144 ;
T_1 V_158 = 0 ;
struct V_155 V_123 = {} ;
V_157 = F_22 ( V_46 ) ;
if ( ! V_157 )
return - V_15 ;
F_110 ( V_3 , & V_123 ) ;
V_41 = F_125 ( V_77 , V_3 , V_113 -> V_111 ,
V_123 . V_118 , & V_138 ) ;
F_126 ( V_3 , & V_123 ) ;
if ( V_41 < 0 )
goto V_47;
if ( V_138 -> V_159 != 1 )
goto V_47;
F_115 ( & V_132 ) ;
V_130 = F_116 ( V_138 , & V_132 ) ;
if ( V_130 -> V_145 == V_113 -> V_112 )
goto V_47;
V_158 = V_130 -> V_145 ;
F_129 ( ! V_158 ) ;
F_83 ( & V_3 -> V_97 ) ;
V_144 = F_1 ( V_3 , V_158 ) ;
if ( ! V_144 )
goto V_160;
V_144 -> V_29 += V_113 -> V_119 ;
V_144 -> V_64 += V_113 -> V_119 ;
F_93 ( V_3 , V_144 ) ;
F_19 (glist, &qg->groups, next_group) {
V_102 = F_113 ( V_157 , V_128 -> V_27 -> V_4 ,
F_114 ( V_128 -> V_27 ) , V_14 ) ;
if ( V_102 < 0 ) {
V_41 = V_102 ;
goto V_160;
}
}
F_115 ( & V_132 ) ;
while ( ( V_130 = F_116 ( V_157 , & V_132 ) ) ) {
V_144 = F_117 ( V_130 -> V_136 ) ;
V_144 -> V_29 += V_113 -> V_119 ;
V_144 -> V_64 += V_113 -> V_119 ;
F_93 ( V_3 , V_144 ) ;
F_19 (glist, &qg->groups, next_group) {
V_102 = F_113 ( V_157 , V_128 -> V_27 -> V_4 ,
F_114 ( V_128 -> V_27 ) , V_14 ) ;
if ( V_102 < 0 ) {
V_41 = V_102 ;
goto V_160;
}
}
}
V_160:
F_84 ( & V_3 -> V_97 ) ;
V_47:
F_48 ( V_138 ) ;
F_48 ( V_157 ) ;
return V_41 ;
}
static int F_130 ( struct V_76 * V_77 ,
struct V_2 * V_3 ,
struct V_108 * V_113 )
{
int V_41 = 0 ;
if ( ! V_3 -> V_44 )
return 0 ;
F_129 ( ! V_3 -> V_35 ) ;
F_80 ( & V_3 -> V_161 ) ;
if ( V_3 -> V_48 & V_75 ) {
if ( V_3 -> V_86 . V_49 <= V_113 -> V_111 ) {
F_86 ( & V_3 -> V_161 ) ;
return 0 ;
}
}
F_86 ( & V_3 -> V_161 ) ;
ASSERT ( F_106 ( V_113 -> V_112 ) ) ;
F_131 ( V_113 ) ;
switch ( V_113 -> type ) {
case V_134 :
case V_135 :
V_41 = F_111 ( V_3 , V_113 ) ;
break;
case V_151 :
case V_149 :
V_41 = F_127 ( V_77 , V_3 , V_113 ) ;
break;
case V_124 :
V_41 = F_128 ( V_77 , V_3 , V_113 ) ;
break;
default:
ASSERT ( 0 ) ;
}
return V_41 ;
}
int F_132 ( struct V_76 * V_77 ,
struct V_2 * V_3 )
{
struct V_108 * V_113 ;
int V_41 = 0 ;
while ( ! F_11 ( & V_77 -> V_125 ) ) {
V_113 = F_12 ( & V_77 -> V_125 ,
struct V_108 , V_20 ) ;
F_133 ( & V_113 -> V_20 ) ;
if ( ! V_41 || ! V_77 -> V_162 )
V_41 = F_130 ( V_77 , V_3 , V_113 ) ;
F_83 ( & V_3 -> V_116 ) ;
F_15 ( & V_113 -> V_6 , & V_3 -> V_117 ) ;
F_84 ( & V_3 -> V_116 ) ;
F_126 ( V_3 , & V_113 -> V_123 ) ;
F_13 ( V_113 ) ;
}
return V_41 ;
}
int F_134 ( struct V_76 * V_77 ,
struct V_2 * V_3 )
{
struct V_34 * V_35 = V_3 -> V_35 ;
int V_41 = 0 ;
int V_163 = 0 ;
if ( ! V_35 )
goto V_47;
if ( ! V_3 -> V_44 && V_3 -> V_74 )
V_163 = 1 ;
V_3 -> V_44 = V_3 -> V_74 ;
F_83 ( & V_3 -> V_97 ) ;
while ( ! F_11 ( & V_3 -> V_101 ) ) {
struct V_1 * V_8 ;
V_8 = F_12 ( & V_3 -> V_101 ,
struct V_1 , V_18 ) ;
F_133 ( & V_8 -> V_18 ) ;
F_84 ( & V_3 -> V_97 ) ;
V_41 = F_71 ( V_77 , V_35 , V_8 ) ;
if ( V_41 )
V_3 -> V_48 |=
V_58 ;
F_83 ( & V_3 -> V_97 ) ;
}
if ( V_3 -> V_44 )
V_3 -> V_48 |= V_73 ;
else
V_3 -> V_48 &= ~ V_73 ;
F_84 ( & V_3 -> V_97 ) ;
V_41 = F_72 ( V_77 , V_3 , V_35 ) ;
if ( V_41 )
V_3 -> V_48 |= V_58 ;
if ( ! V_41 && V_163 ) {
V_41 = F_46 ( V_3 , 0 , 1 ) ;
if ( ! V_41 ) {
F_135 ( V_3 ) ;
F_136 ( V_3 -> V_164 ,
& V_3 -> V_165 ) ;
}
V_41 = 0 ;
}
V_47:
return V_41 ;
}
int F_137 ( struct V_76 * V_77 ,
struct V_2 * V_3 , T_1 V_166 , T_1 V_49 ,
struct F_137 * V_167 )
{
int V_41 = 0 ;
int V_168 ;
T_1 * V_169 ;
struct V_34 * V_35 = V_3 -> V_35 ;
struct V_1 * V_170 ;
struct V_1 * V_171 ;
T_2 V_172 = 0 ;
T_1 V_173 ;
F_80 ( & V_3 -> V_90 ) ;
if ( ! V_3 -> V_44 )
goto V_47;
if ( ! V_35 ) {
V_41 = - V_30 ;
goto V_47;
}
if ( V_167 ) {
V_169 = ( T_1 * ) ( V_167 + 1 ) ;
V_173 = V_167 -> V_174 + 2 * V_167 -> V_175 +
2 * V_167 -> V_176 ;
for ( V_168 = 0 ; V_168 < V_173 ; ++ V_168 ) {
V_170 = F_1 ( V_3 , * V_169 ) ;
if ( ! V_170 ) {
V_41 = - V_30 ;
goto V_47;
}
++ V_169 ;
}
}
V_41 = F_57 ( V_77 , V_35 , V_49 ) ;
if ( V_41 )
goto V_47;
if ( V_167 && V_167 -> V_42 & V_177 ) {
V_41 = F_70 ( V_77 , V_35 , V_49 ,
V_167 -> V_178 . V_42 ,
V_167 -> V_178 . V_67 ,
V_167 -> V_178 . V_68 ,
V_167 -> V_178 . V_69 ,
V_167 -> V_178 . V_70 ) ;
if ( V_41 )
goto V_47;
}
if ( V_166 ) {
struct V_34 * V_179 ;
struct V_31 V_180 ;
V_180 . V_49 = V_166 ;
V_180 . type = V_181 ;
V_180 . V_50 = ( T_1 ) - 1 ;
V_179 = F_138 ( V_3 , & V_180 ) ;
if ( F_32 ( V_179 ) ) {
V_41 = F_33 ( V_179 ) ;
goto V_47;
}
F_139 () ;
V_172 = V_179 -> V_182 ;
F_140 () ;
}
if ( V_167 ) {
V_169 = ( T_1 * ) ( V_167 + 1 ) ;
for ( V_168 = 0 ; V_168 < V_167 -> V_174 ; ++ V_168 ) {
V_41 = F_51 ( V_77 , V_35 ,
V_49 , * V_169 ) ;
if ( V_41 )
goto V_47;
V_41 = F_51 ( V_77 , V_35 ,
* V_169 , V_49 ) ;
if ( V_41 )
goto V_47;
++ V_169 ;
}
}
F_83 ( & V_3 -> V_97 ) ;
V_171 = F_3 ( V_3 , V_49 ) ;
if ( F_32 ( V_171 ) ) {
V_41 = F_33 ( V_171 ) ;
goto V_183;
}
if ( V_166 ) {
V_170 = F_1 ( V_3 , V_166 ) ;
if ( ! V_170 )
goto V_183;
V_171 -> V_28 = V_170 -> V_28 ;
V_171 -> V_63 = V_170 -> V_63 ;
V_171 -> V_29 = V_172 ;
V_171 -> V_64 = V_172 ;
V_170 -> V_29 = V_172 ;
V_170 -> V_64 = V_172 ;
F_93 ( V_3 , V_171 ) ;
F_93 ( V_3 , V_170 ) ;
}
if ( ! V_167 )
goto V_183;
V_169 = ( T_1 * ) ( V_167 + 1 ) ;
for ( V_168 = 0 ; V_168 < V_167 -> V_174 ; ++ V_168 ) {
V_41 = F_16 ( V_35 -> V_3 , V_49 ,
* V_169 ) ;
if ( V_41 )
goto V_183;
++ V_169 ;
}
for ( V_168 = 0 ; V_168 < V_167 -> V_175 ; ++ V_168 ) {
struct V_1 * V_78 ;
struct V_1 * V_79 ;
V_78 = F_1 ( V_3 , V_169 [ 0 ] ) ;
V_79 = F_1 ( V_3 , V_169 [ 1 ] ) ;
if ( ! V_78 || ! V_79 ) {
V_41 = - V_30 ;
goto V_183;
}
V_79 -> V_28 = V_78 -> V_28 - V_172 ;
V_79 -> V_63 = V_78 -> V_63 - V_172 ;
V_169 += 2 ;
}
for ( V_168 = 0 ; V_168 < V_167 -> V_176 ; ++ V_168 ) {
struct V_1 * V_78 ;
struct V_1 * V_79 ;
V_78 = F_1 ( V_3 , V_169 [ 0 ] ) ;
V_79 = F_1 ( V_3 , V_169 [ 1 ] ) ;
if ( ! V_78 || ! V_79 ) {
V_41 = - V_30 ;
goto V_183;
}
V_79 -> V_29 = V_78 -> V_29 + V_172 ;
V_79 -> V_64 = V_78 -> V_64 + V_172 ;
V_169 += 2 ;
}
V_183:
F_84 ( & V_3 -> V_97 ) ;
V_47:
F_86 ( & V_3 -> V_90 ) ;
return V_41 ;
}
int F_141 ( struct V_34 * V_85 , T_1 V_119 )
{
struct V_34 * V_35 ;
struct V_1 * V_8 ;
struct V_2 * V_3 = V_85 -> V_3 ;
T_1 V_112 = V_85 -> V_99 . V_49 ;
int V_41 = 0 ;
struct V_129 * V_130 ;
struct V_131 V_132 ;
if ( ! F_106 ( V_112 ) )
return 0 ;
if ( V_119 == 0 )
return 0 ;
F_83 ( & V_3 -> V_97 ) ;
V_35 = V_3 -> V_35 ;
if ( ! V_35 )
goto V_47;
V_8 = F_1 ( V_3 , V_112 ) ;
if ( ! V_8 )
goto V_47;
F_119 ( V_3 -> V_45 ) ;
V_41 = F_113 ( V_3 -> V_45 , V_8 -> V_4 ,
( V_184 ) V_8 , V_14 ) ;
if ( V_41 < 0 )
goto V_47;
F_115 ( & V_132 ) ;
while ( ( V_130 = F_116 ( V_3 -> V_45 , & V_132 ) ) ) {
struct V_1 * V_144 ;
struct V_19 * V_128 ;
V_144 = F_117 ( V_130 -> V_136 ) ;
if ( ( V_144 -> V_66 & V_185 ) &&
V_144 -> V_186 + ( V_187 ) V_144 -> V_28 + V_119 >
V_144 -> V_67 ) {
V_41 = - V_188 ;
goto V_47;
}
if ( ( V_144 -> V_66 & V_189 ) &&
V_144 -> V_186 + ( V_187 ) V_144 -> V_29 + V_119 >
V_144 -> V_68 ) {
V_41 = - V_188 ;
goto V_47;
}
F_19 (glist, &qg->groups, next_group) {
V_41 = F_113 ( V_3 -> V_45 ,
V_128 -> V_27 -> V_4 ,
( V_184 ) V_128 -> V_27 , V_14 ) ;
if ( V_41 < 0 )
goto V_47;
}
}
V_41 = 0 ;
F_115 ( & V_132 ) ;
while ( ( V_130 = F_116 ( V_3 -> V_45 , & V_132 ) ) ) {
struct V_1 * V_144 ;
V_144 = F_117 ( V_130 -> V_136 ) ;
V_144 -> V_186 += V_119 ;
}
V_47:
F_84 ( & V_3 -> V_97 ) ;
return V_41 ;
}
void F_142 ( struct V_34 * V_85 , T_1 V_119 )
{
struct V_34 * V_35 ;
struct V_1 * V_8 ;
struct V_2 * V_3 = V_85 -> V_3 ;
struct V_129 * V_130 ;
struct V_131 V_132 ;
T_1 V_112 = V_85 -> V_99 . V_49 ;
int V_41 = 0 ;
if ( ! F_106 ( V_112 ) )
return;
if ( V_119 == 0 )
return;
F_83 ( & V_3 -> V_97 ) ;
V_35 = V_3 -> V_35 ;
if ( ! V_35 )
goto V_47;
V_8 = F_1 ( V_3 , V_112 ) ;
if ( ! V_8 )
goto V_47;
F_119 ( V_3 -> V_45 ) ;
V_41 = F_113 ( V_3 -> V_45 , V_8 -> V_4 ,
( V_184 ) V_8 , V_14 ) ;
if ( V_41 < 0 )
goto V_47;
F_115 ( & V_132 ) ;
while ( ( V_130 = F_116 ( V_3 -> V_45 , & V_132 ) ) ) {
struct V_1 * V_144 ;
struct V_19 * V_128 ;
V_144 = F_117 ( V_130 -> V_136 ) ;
V_144 -> V_186 -= V_119 ;
F_19 (glist, &qg->groups, next_group) {
V_41 = F_113 ( V_3 -> V_45 ,
V_128 -> V_27 -> V_4 ,
( V_184 ) V_128 -> V_27 , V_14 ) ;
if ( V_41 < 0 )
goto V_47;
}
}
V_47:
F_84 ( & V_3 -> V_97 ) ;
}
void F_143 ( struct V_76 * V_77 )
{
if ( F_11 ( & V_77 -> V_125 ) && ! V_77 -> V_190 . V_118 )
return;
F_28 ( V_77 -> V_85 -> V_3 ,
L_7
L_8 ,
V_77 , F_11 ( & V_77 -> V_125 ) ? L_9 : L_10 ,
( T_2 ) ( V_77 -> V_190 . V_118 >> 32 ) ,
( T_2 ) V_77 -> V_190 . V_118 ) ;
F_144 () ;
}
static int
F_145 ( struct V_2 * V_3 , struct V_36 * V_37 ,
struct V_76 * V_77 , struct V_126 * V_139 ,
struct V_126 * V_127 , struct V_38 * V_191 )
{
struct V_31 V_192 ;
struct V_126 * V_138 = NULL ;
struct V_155 V_193 = {} ;
T_1 V_119 ;
T_1 V_118 ;
int V_152 ;
int V_40 ;
int V_41 ;
V_37 -> V_88 = 1 ;
F_80 ( & V_3 -> V_161 ) ;
V_41 = F_24 ( V_3 -> V_194 ,
& V_3 -> V_86 ,
V_37 , 1 , 0 ) ;
F_146 ( L_11 ,
V_3 -> V_86 . V_49 ,
V_3 -> V_86 . type ,
V_3 -> V_86 . V_50 , V_41 ) ;
if ( V_41 ) {
V_3 -> V_86 . V_49 = ( T_1 ) - 1 ;
F_44 ( V_37 ) ;
F_86 ( & V_3 -> V_161 ) ;
return V_41 ;
}
F_25 ( V_37 -> V_52 [ 0 ] , & V_192 ,
F_77 ( V_37 -> V_52 [ 0 ] ) - 1 ) ;
V_3 -> V_86 . V_49 = V_192 . V_49 + 1 ;
F_110 ( V_3 , & V_193 ) ;
memcpy ( V_191 , V_37 -> V_52 [ 0 ] , sizeof( * V_191 ) ) ;
V_40 = V_37 -> V_51 [ 0 ] ;
F_44 ( V_37 ) ;
F_86 ( & V_3 -> V_161 ) ;
for (; V_40 < F_77 ( V_191 ) ; ++ V_40 ) {
F_25 ( V_191 , & V_192 , V_40 ) ;
if ( V_192 . type != V_195 &&
V_192 . type != V_196 )
continue;
if ( V_192 . type == V_196 )
V_119 = V_3 -> V_194 -> V_182 ;
else
V_119 = V_192 . V_50 ;
F_119 ( V_139 ) ;
V_41 = F_125 ( NULL , V_3 , V_192 . V_49 , 0 ,
& V_138 ) ;
if ( V_41 < 0 )
goto V_47;
F_83 ( & V_3 -> V_97 ) ;
V_118 = V_3 -> V_156 ;
V_3 -> V_156 += V_138 -> V_159 + 1 ;
V_152 = 0 ;
V_41 = F_118 ( V_3 , 0 , V_127 , V_138 , V_139 ,
V_118 , & V_152 , 1 ) ;
if ( V_41 < 0 ) {
F_84 ( & V_3 -> V_97 ) ;
F_48 ( V_138 ) ;
goto V_47;
}
V_41 = F_123 ( V_3 , 0 , V_119 , V_139 ,
V_118 , 0 , V_152 , 1 ) ;
if ( V_41 < 0 ) {
F_84 ( & V_3 -> V_97 ) ;
F_48 ( V_138 ) ;
goto V_47;
}
F_84 ( & V_3 -> V_97 ) ;
F_48 ( V_138 ) ;
}
V_47:
F_126 ( V_3 , & V_193 ) ;
return V_41 ;
}
static void F_147 ( struct V_197 * V_198 )
{
struct V_2 * V_3 = F_148 ( V_198 , struct V_2 ,
V_165 ) ;
struct V_36 * V_37 ;
struct V_76 * V_77 = NULL ;
struct V_126 * V_127 = NULL , * V_139 = NULL ;
struct V_38 * V_191 = NULL ;
int V_102 = - V_15 ;
V_37 = F_23 () ;
if ( ! V_37 )
goto V_47;
V_139 = F_22 ( V_46 ) ;
if ( ! V_139 )
goto V_47;
V_127 = F_22 ( V_46 ) ;
if ( ! V_127 )
goto V_47;
V_191 = F_107 ( sizeof( * V_191 ) , V_46 ) ;
if ( ! V_191 )
goto V_47;
V_102 = 0 ;
while ( ! V_102 ) {
V_77 = F_149 ( V_3 -> V_199 , 0 ) ;
if ( F_32 ( V_77 ) ) {
V_102 = F_33 ( V_77 ) ;
break;
}
if ( ! V_3 -> V_44 ) {
V_102 = - V_200 ;
} else {
V_102 = F_145 ( V_3 , V_37 , V_77 ,
V_139 , V_127 , V_191 ) ;
}
if ( V_102 > 0 )
F_150 ( V_77 , V_3 -> V_199 ) ;
else
F_151 ( V_77 , V_3 -> V_199 ) ;
}
V_47:
F_13 ( V_191 ) ;
F_48 ( V_139 ) ;
F_48 ( V_127 ) ;
F_47 ( V_37 ) ;
F_80 ( & V_3 -> V_161 ) ;
V_3 -> V_48 &= ~ V_75 ;
if ( V_102 == 2 &&
V_3 -> V_48 & V_58 ) {
V_3 -> V_48 &= ~ V_58 ;
} else if ( V_102 < 0 ) {
V_3 -> V_48 |= V_58 ;
}
F_86 ( & V_3 -> V_161 ) ;
if ( V_102 >= 0 ) {
F_100 ( V_3 , L_12 ,
V_102 == 2 ? L_13 : L_9 ) ;
} else {
F_28 ( V_3 , L_14 , V_102 ) ;
}
F_152 ( & V_3 -> V_201 ) ;
}
static int
F_46 ( struct V_2 * V_3 , T_1 V_202 ,
int V_203 )
{
int V_41 = 0 ;
if ( ! V_203 &&
( ! ( V_3 -> V_48 & V_75 ) ||
! ( V_3 -> V_48 & V_73 ) ) ) {
V_41 = - V_30 ;
goto V_102;
}
F_80 ( & V_3 -> V_161 ) ;
F_83 ( & V_3 -> V_97 ) ;
if ( V_203 ) {
if ( V_3 -> V_48 & V_75 )
V_41 = - V_204 ;
else if ( ! ( V_3 -> V_48 & V_73 ) )
V_41 = - V_30 ;
if ( V_41 ) {
F_84 ( & V_3 -> V_97 ) ;
F_86 ( & V_3 -> V_161 ) ;
goto V_102;
}
V_3 -> V_48 |= V_75 ;
}
memset ( & V_3 -> V_86 , 0 ,
sizeof( V_3 -> V_86 ) ) ;
V_3 -> V_86 . V_49 = V_202 ;
F_84 ( & V_3 -> V_97 ) ;
F_86 ( & V_3 -> V_161 ) ;
F_153 ( & V_3 -> V_201 ) ;
memset ( & V_3 -> V_165 , 0 ,
sizeof( V_3 -> V_165 ) ) ;
F_154 ( & V_3 -> V_165 ,
V_205 ,
F_147 , NULL , NULL ) ;
if ( V_41 ) {
V_102:
F_100 ( V_3 , L_15 , V_41 ) ;
return V_41 ;
}
return 0 ;
}
static void
F_135 ( struct V_2 * V_3 )
{
struct V_5 * V_6 ;
struct V_1 * V_8 ;
F_83 ( & V_3 -> V_97 ) ;
for ( V_6 = F_50 ( & V_3 -> V_7 ) ; V_6 ; V_6 = F_121 ( V_6 ) ) {
V_8 = F_2 ( V_6 , struct V_1 , V_9 ) ;
V_8 -> V_28 = 0 ;
V_8 -> V_63 = 0 ;
V_8 -> V_29 = 0 ;
V_8 -> V_64 = 0 ;
}
F_84 ( & V_3 -> V_97 ) ;
}
int
F_155 ( struct V_2 * V_3 )
{
int V_41 = 0 ;
struct V_76 * V_77 ;
V_41 = F_46 ( V_3 , 0 , 1 ) ;
if ( V_41 )
return V_41 ;
V_77 = F_156 ( V_3 -> V_199 ) ;
if ( F_32 ( V_77 ) ) {
V_3 -> V_48 &= ~ V_75 ;
return F_33 ( V_77 ) ;
}
V_41 = F_150 ( V_77 , V_3 -> V_199 ) ;
if ( V_41 ) {
V_3 -> V_48 &= ~ V_75 ;
return V_41 ;
}
F_135 ( V_3 ) ;
F_136 ( V_3 -> V_164 ,
& V_3 -> V_165 ) ;
return 0 ;
}
int F_157 ( struct V_2 * V_3 )
{
int V_206 ;
int V_41 = 0 ;
F_80 ( & V_3 -> V_161 ) ;
F_83 ( & V_3 -> V_97 ) ;
V_206 = V_3 -> V_48 & V_75 ;
F_84 ( & V_3 -> V_97 ) ;
F_86 ( & V_3 -> V_161 ) ;
if ( V_206 )
V_41 = F_158 (
& V_3 -> V_201 ) ;
return V_41 ;
}
void
F_159 ( struct V_2 * V_3 )
{
if ( V_3 -> V_48 & V_75 )
F_136 ( V_3 -> V_164 ,
& V_3 -> V_165 ) ;
}
