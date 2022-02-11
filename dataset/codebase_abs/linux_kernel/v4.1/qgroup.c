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
struct V_34 * V_85 ,
struct V_1 * V_8 )
{
struct V_36 * V_37 ;
struct V_31 V_32 ;
struct V_38 * V_39 ;
struct V_65 * V_81 ;
int V_41 ;
int V_40 ;
V_32 . V_49 = 0 ;
V_32 . type = V_61 ;
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
V_81 = F_26 ( V_39 , V_40 , struct V_65 ) ;
F_64 ( V_39 , V_81 , V_8 -> V_66 ) ;
F_65 ( V_39 , V_81 , V_8 -> V_67 ) ;
F_66 ( V_39 , V_81 , V_8 -> V_68 ) ;
F_67 ( V_39 , V_81 , V_8 -> V_69 ) ;
F_68 ( V_39 , V_81 , V_8 -> V_70 ) ;
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
V_3 -> V_48 &= ~ V_73 ;
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
F_90 ( V_77 , V_89 -> V_3 , V_35 -> V_9 ) ;
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
static int F_95 ( struct V_2 * V_3 ,
struct V_102 * V_103 , T_1 V_104 ,
T_1 V_105 , int V_106 )
{
struct V_1 * V_8 ;
struct V_19 * V_107 ;
struct V_108 * V_109 ;
struct V_110 V_111 ;
int V_41 = 0 ;
V_8 = F_1 ( V_3 , V_104 ) ;
if ( ! V_8 )
goto V_47;
V_8 -> V_28 += V_106 * V_105 ;
V_8 -> V_63 += V_106 * V_105 ;
F_96 ( V_106 < 0 && V_8 -> V_29 < V_105 ) ;
V_8 -> V_29 += V_106 * V_105 ;
V_8 -> V_64 += V_106 * V_105 ;
if ( V_106 > 0 )
V_8 -> V_112 -= V_105 ;
F_93 ( V_3 , V_8 ) ;
F_19 (glist, &qgroup->groups, next_group) {
V_41 = F_97 ( V_103 , V_107 -> V_27 -> V_4 ,
F_98 ( V_107 -> V_27 ) , V_14 ) ;
if ( V_41 < 0 )
goto V_47;
}
F_99 ( & V_111 ) ;
while ( ( V_109 = F_100 ( V_103 , & V_111 ) ) ) {
V_8 = F_101 ( V_109 -> V_113 ) ;
V_8 -> V_28 += V_106 * V_105 ;
V_8 -> V_63 += V_106 * V_105 ;
F_96 ( V_106 < 0 && V_8 -> V_29 < V_105 ) ;
V_8 -> V_29 += V_106 * V_105 ;
if ( V_106 > 0 )
V_8 -> V_112 -= V_105 ;
V_8 -> V_64 += V_106 * V_105 ;
F_93 ( V_3 , V_8 ) ;
F_19 (glist, &qgroup->groups, next_group) {
V_41 = F_97 ( V_103 , V_107 -> V_27 -> V_4 ,
F_98 ( V_107 -> V_27 ) , V_14 ) ;
if ( V_41 < 0 )
goto V_47;
}
}
V_41 = 0 ;
V_47:
return V_41 ;
}
static int F_102 ( struct V_2 * V_3 ,
struct V_102 * V_103 , T_1 V_78 , T_1 V_79 ,
int V_106 )
{
struct V_1 * V_8 ;
int V_41 = 1 ;
int V_114 = 0 ;
V_8 = F_1 ( V_3 , V_78 ) ;
if ( ! V_8 )
goto V_47;
if ( V_8 -> V_29 == V_8 -> V_28 ) {
V_41 = 0 ;
V_114 = F_95 ( V_3 , V_103 , V_79 ,
V_8 -> V_29 , V_106 ) ;
if ( V_114 < 0 ) {
V_41 = V_114 ;
goto V_47;
}
}
V_47:
if ( V_41 )
V_3 -> V_48 |= V_58 ;
return V_41 ;
}
int F_103 ( struct V_76 * V_77 ,
struct V_2 * V_3 , T_1 V_78 , T_1 V_79 )
{
struct V_34 * V_35 ;
struct V_1 * V_13 ;
struct V_1 * V_26 ;
struct V_19 * V_20 ;
struct V_102 * V_103 ;
int V_41 = 0 ;
V_103 = F_22 ( V_46 ) ;
if ( ! V_103 )
return - V_15 ;
if ( F_104 ( V_78 ) >= F_104 ( V_79 ) )
return - V_30 ;
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
if ( V_41 < 0 ) {
F_84 ( & V_3 -> V_97 ) ;
goto V_47;
}
V_41 = F_102 ( V_3 , V_103 , V_78 , V_79 , 1 ) ;
F_84 ( & V_3 -> V_97 ) ;
V_47:
F_86 ( & V_3 -> V_90 ) ;
F_48 ( V_103 ) ;
return V_41 ;
}
int F_105 ( struct V_76 * V_77 ,
struct V_2 * V_3 , T_1 V_78 , T_1 V_79 )
{
struct V_34 * V_35 ;
struct V_1 * V_13 ;
struct V_1 * V_26 ;
struct V_19 * V_20 ;
struct V_102 * V_103 ;
int V_41 = 0 ;
int V_114 ;
V_103 = F_22 ( V_46 ) ;
if ( ! V_103 )
return - V_15 ;
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
goto V_115;
}
V_41 = - V_23 ;
goto V_47;
V_115:
V_41 = F_54 ( V_77 , V_35 , V_78 , V_79 ) ;
V_114 = F_54 ( V_77 , V_35 , V_79 , V_78 ) ;
if ( V_114 && ! V_41 )
V_41 = V_114 ;
F_83 ( & V_3 -> V_97 ) ;
F_18 ( V_3 , V_78 , V_79 ) ;
V_41 = F_102 ( V_3 , V_103 , V_78 , V_79 , - 1 ) ;
F_84 ( & V_3 -> V_97 ) ;
V_47:
F_48 ( V_103 ) ;
return V_41 ;
}
int F_106 ( struct V_76 * V_77 ,
struct V_2 * V_3 , T_1 V_78 , T_1 V_79 )
{
int V_41 = 0 ;
F_80 ( & V_3 -> V_90 ) ;
V_41 = F_105 ( V_77 , V_3 , V_78 , V_79 ) ;
F_86 ( & V_3 -> V_90 ) ;
return V_41 ;
}
int F_107 ( struct V_76 * V_77 ,
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
int F_108 ( struct V_76 * V_77 ,
struct V_2 * V_3 , T_1 V_4 )
{
struct V_34 * V_35 ;
struct V_1 * V_8 ;
struct V_19 * V_20 ;
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
if ( ! F_11 ( & V_8 -> V_17 ) ) {
V_41 = - V_116 ;
goto V_47;
}
}
V_41 = F_69 ( V_77 , V_35 , V_4 ) ;
while ( ! F_11 ( & V_8 -> V_16 ) ) {
V_20 = F_12 ( & V_8 -> V_16 ,
struct V_19 , V_21 ) ;
V_41 = F_105 ( V_77 , V_3 ,
V_4 ,
V_20 -> V_27 -> V_4 ) ;
if ( V_41 )
goto V_47;
}
F_83 ( & V_3 -> V_97 ) ;
F_14 ( V_35 -> V_3 , V_4 ) ;
F_84 ( & V_3 -> V_97 ) ;
V_47:
F_86 ( & V_3 -> V_90 ) ;
return V_41 ;
}
int F_109 ( struct V_76 * V_77 ,
struct V_2 * V_3 , T_1 V_4 ,
struct V_117 * V_118 )
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
F_83 ( & V_3 -> V_97 ) ;
if ( V_118 -> V_42 & V_119 )
V_8 -> V_67 = V_118 -> V_67 ;
if ( V_118 -> V_42 & V_120 )
V_8 -> V_68 = V_118 -> V_68 ;
if ( V_118 -> V_42 & V_121 )
V_8 -> V_69 = V_118 -> V_69 ;
if ( V_118 -> V_42 & V_122 )
V_8 -> V_70 = V_118 -> V_70 ;
V_8 -> V_66 |= V_118 -> V_42 ;
F_84 ( & V_3 -> V_97 ) ;
V_41 = F_70 ( V_77 , V_35 , V_8 ) ;
if ( V_41 ) {
V_3 -> V_48 |= V_58 ;
F_110 ( V_3 , L_6 ,
V_4 ) ;
}
V_47:
F_86 ( & V_3 -> V_90 ) ;
return V_41 ;
}
static int F_111 ( struct V_123 * V_124 ,
struct V_123 * V_125 )
{
if ( V_124 -> V_126 < V_125 -> V_126 )
return - 1 ;
if ( V_124 -> V_126 > V_125 -> V_126 )
return 1 ;
if ( V_124 -> V_104 < V_125 -> V_104 )
return - 1 ;
if ( V_124 -> V_104 > V_125 -> V_104 )
return 1 ;
return 0 ;
}
static int F_112 ( struct V_2 * V_3 ,
struct V_123 * V_127 )
{
struct V_5 * V_6 ;
struct V_123 * V_128 ;
int V_129 ;
F_83 ( & V_3 -> V_130 ) ;
V_6 = V_3 -> V_131 . V_5 ;
while ( V_6 ) {
V_128 = F_2 ( V_6 , struct V_123 , V_6 ) ;
V_129 = F_111 ( V_128 , V_127 ) ;
if ( V_129 < 0 ) {
V_6 = V_6 -> V_11 ;
} else if ( V_129 ) {
V_6 = V_6 -> V_10 ;
} else {
F_84 ( & V_3 -> V_130 ) ;
return - V_83 ;
}
}
F_84 ( & V_3 -> V_130 ) ;
return 0 ;
}
static int F_113 ( struct V_123 * V_124 ,
struct V_123 * V_125 )
{
if ( V_124 -> V_126 < V_125 -> V_126 )
return - 1 ;
if ( V_124 -> V_126 > V_125 -> V_126 )
return 1 ;
if ( V_124 -> V_104 < V_125 -> V_104 )
return - 1 ;
if ( V_124 -> V_104 > V_125 -> V_104 )
return 1 ;
if ( V_124 -> V_132 < V_125 -> V_132 )
return - 1 ;
if ( V_124 -> V_132 > V_125 -> V_132 )
return 1 ;
if ( V_124 -> type < V_125 -> type )
return - 1 ;
if ( V_124 -> type > V_125 -> type )
return 1 ;
return 0 ;
}
static int F_114 ( struct V_2 * V_3 ,
struct V_123 * V_127 )
{
struct V_5 * * V_12 ;
struct V_5 * V_13 = NULL ;
struct V_123 * V_128 ;
int V_129 ;
F_83 ( & V_3 -> V_130 ) ;
V_12 = & V_3 -> V_131 . V_5 ;
while ( * V_12 ) {
V_13 = * V_12 ;
V_128 = F_2 ( V_13 , struct V_123 , V_6 ) ;
V_129 = F_113 ( V_128 , V_127 ) ;
if ( V_129 < 0 ) {
V_12 = & ( * V_12 ) -> V_11 ;
} else if ( V_129 ) {
V_12 = & ( * V_12 ) -> V_10 ;
} else {
F_84 ( & V_3 -> V_130 ) ;
return - V_83 ;
}
}
F_7 ( & V_127 -> V_6 , V_13 , V_12 ) ;
F_8 ( & V_127 -> V_6 , & V_3 -> V_131 ) ;
F_84 ( & V_3 -> V_130 ) ;
return 0 ;
}
int F_115 ( struct V_76 * V_77 ,
struct V_2 * V_3 , T_1 V_104 ,
T_1 V_126 , T_1 V_105 ,
enum V_133 type , int V_134 )
{
struct V_123 * V_127 ;
int V_41 ;
if ( ! F_116 ( V_104 ) || ! V_3 -> V_44 )
return 0 ;
V_127 = F_117 ( sizeof( * V_127 ) , V_46 ) ;
if ( ! V_127 )
return - V_15 ;
V_127 -> V_104 = V_104 ;
V_127 -> V_126 = V_126 ;
V_127 -> V_105 = V_105 ;
V_127 -> type = type ;
V_127 -> V_132 = F_118 ( & V_3 -> V_135 ) ;
F_6 ( & V_127 -> V_136 . V_20 ) ;
V_127 -> V_136 . V_132 = 0 ;
F_119 ( V_127 ) ;
if ( type == V_137 ) {
if ( F_112 ( V_3 , V_127 ) ) {
F_13 ( V_127 ) ;
return 0 ;
}
}
V_41 = F_114 ( V_3 , V_127 ) ;
if ( V_41 ) {
ASSERT ( 0 ) ;
F_13 ( V_127 ) ;
return V_41 ;
}
F_17 ( & V_127 -> V_20 , & V_77 -> V_138 ) ;
if ( V_134 )
F_120 ( V_3 , & V_127 -> V_136 ) ;
return 0 ;
}
static int F_121 ( struct V_2 * V_3 ,
struct V_123 * V_127 )
{
struct V_102 * V_103 ;
int V_106 = 0 ;
int V_41 = 0 ;
V_103 = F_22 ( V_46 ) ;
if ( ! V_103 )
return - V_15 ;
F_83 ( & V_3 -> V_97 ) ;
if ( ! V_3 -> V_35 )
goto V_47;
switch ( V_127 -> type ) {
case V_139 :
V_106 = 1 ;
break;
case V_140 :
V_106 = - 1 ;
break;
default:
ASSERT ( 0 ) ;
}
V_41 = F_95 ( V_3 , V_103 , V_127 -> V_104 ,
V_127 -> V_105 , V_106 ) ;
V_47:
F_84 ( & V_3 -> V_97 ) ;
F_48 ( V_103 ) ;
return V_41 ;
}
static int F_122 ( struct V_2 * V_3 ,
T_1 V_141 , struct V_102 * V_103 ,
struct V_102 * V_142 , struct V_102 * V_143 ,
T_1 V_132 , int * V_144 , int V_145 )
{
struct V_108 * V_109 ;
struct V_110 V_111 ;
struct V_108 * V_146 ;
struct V_110 V_147 ;
struct V_1 * V_148 ;
int V_41 ;
F_99 ( & V_111 ) ;
while ( ( V_109 = F_100 ( V_142 , & V_111 ) ) ) {
if ( V_109 -> V_149 == V_141 )
continue;
V_148 = F_1 ( V_3 , V_109 -> V_149 ) ;
if ( ! V_148 )
continue;
( * V_144 ) ++ ;
F_123 ( V_103 ) ;
V_41 = F_97 ( V_143 , V_148 -> V_4 , F_98 ( V_148 ) ,
V_14 ) ;
if ( V_41 < 0 )
return V_41 ;
V_41 = F_97 ( V_103 , V_148 -> V_4 , F_98 ( V_148 ) , V_14 ) ;
if ( V_41 < 0 )
return V_41 ;
F_99 ( & V_147 ) ;
while ( ( V_146 = F_100 ( V_103 , & V_147 ) ) ) {
struct V_19 * V_107 ;
V_148 = F_101 ( V_146 -> V_113 ) ;
if ( V_145 )
V_148 -> V_150 = V_132 ;
else if ( V_148 -> V_150 < V_132 )
V_148 -> V_150 = V_132 + 1 ;
else
V_148 -> V_150 ++ ;
if ( V_148 -> V_151 < V_132 )
V_148 -> V_151 = V_132 + 1 ;
else
V_148 -> V_151 ++ ;
F_19 (glist, &qg->groups, next_group) {
V_41 = F_97 ( V_143 , V_107 -> V_27 -> V_4 ,
F_98 ( V_107 -> V_27 ) ,
V_14 ) ;
if ( V_41 < 0 )
return V_41 ;
V_41 = F_97 ( V_103 , V_107 -> V_27 -> V_4 ,
F_98 ( V_107 -> V_27 ) ,
V_14 ) ;
if ( V_41 < 0 )
return V_41 ;
}
}
}
return 0 ;
}
static int F_124 ( struct V_2 * V_3 ,
struct V_123 * V_127 ,
struct V_102 * V_103 ,
struct V_102 * V_143 , T_1 V_132 ,
int * V_144 )
{
struct V_108 * V_109 ;
struct V_110 V_111 ;
struct V_1 * V_148 ;
struct V_123 * V_152 ;
struct V_5 * V_6 ;
int V_41 ;
F_123 ( V_103 ) ;
F_83 ( & V_3 -> V_130 ) ;
V_6 = F_125 ( & V_127 -> V_6 ) ;
F_84 ( & V_3 -> V_130 ) ;
if ( ! V_6 )
return 0 ;
V_152 = F_2 ( V_6 , struct V_123 , V_6 ) ;
while ( V_152 -> V_126 == V_127 -> V_126 ) {
if ( V_152 -> type != V_153 &&
V_152 -> type != V_140 )
goto V_154;
V_148 = F_1 ( V_3 , V_152 -> V_104 ) ;
if ( ! V_148 )
goto V_154;
V_41 = F_97 ( V_143 , V_148 -> V_4 , F_98 ( V_148 ) ,
V_14 ) ;
if ( V_41 ) {
if ( V_41 < 0 )
return V_41 ;
( * V_144 ) ++ ;
V_41 = F_97 ( V_103 , V_148 -> V_4 , F_98 ( V_148 ) ,
V_14 ) ;
if ( V_41 < 0 )
return V_41 ;
}
V_154:
F_83 ( & V_3 -> V_130 ) ;
V_6 = F_125 ( & V_152 -> V_6 ) ;
F_84 ( & V_3 -> V_130 ) ;
if ( ! V_6 )
break;
V_152 = F_2 ( V_6 , struct V_123 , V_6 ) ;
}
F_99 ( & V_111 ) ;
while ( ( V_109 = F_100 ( V_103 , & V_111 ) ) ) {
struct V_19 * V_107 ;
V_148 = F_101 ( V_109 -> V_113 ) ;
if ( V_148 -> V_150 < V_132 )
V_148 -> V_150 = V_132 + 1 ;
else
V_148 -> V_150 ++ ;
if ( V_148 -> V_151 < V_132 )
V_148 -> V_151 = V_132 + 1 ;
else
V_148 -> V_151 ++ ;
F_19 (glist, &qg->groups, next_group) {
V_41 = F_97 ( V_143 , V_107 -> V_27 -> V_4 ,
F_98 ( V_107 -> V_27 ) , V_14 ) ;
if ( V_41 < 0 )
return V_41 ;
V_41 = F_97 ( V_103 , V_107 -> V_27 -> V_4 ,
F_98 ( V_107 -> V_27 ) , V_14 ) ;
if ( V_41 < 0 )
return V_41 ;
}
}
return 0 ;
}
static int F_126 ( struct V_2 * V_3 ,
struct V_123 * V_127 ,
struct V_1 * V_8 ,
struct V_102 * V_103 , struct V_102 * V_143 ,
T_1 V_132 )
{
struct V_108 * V_109 ;
struct V_110 V_111 ;
struct V_1 * V_148 ;
int V_41 ;
F_123 ( V_103 ) ;
V_41 = F_97 ( V_143 , V_8 -> V_4 , F_98 ( V_8 ) ,
V_14 ) ;
if ( V_41 < 0 )
return V_41 ;
V_41 = F_97 ( V_103 , V_8 -> V_4 , F_98 ( V_8 ) ,
V_14 ) ;
if ( V_41 < 0 )
return V_41 ;
F_99 ( & V_111 ) ;
while ( ( V_109 = F_100 ( V_103 , & V_111 ) ) ) {
struct V_19 * V_107 ;
V_148 = F_101 ( V_109 -> V_113 ) ;
if ( V_127 -> type == V_155 ) {
if ( V_148 -> V_151 < V_132 )
V_148 -> V_151 = V_132 + 1 ;
else
V_148 -> V_151 ++ ;
} else {
if ( V_148 -> V_150 < V_132 )
V_148 -> V_150 = V_132 + 1 ;
else
V_148 -> V_150 ++ ;
}
F_19 (glist, &qg->groups, next_group) {
V_41 = F_97 ( V_103 , V_107 -> V_27 -> V_4 ,
F_98 ( V_107 -> V_27 ) , V_14 ) ;
if ( V_41 < 0 )
return V_41 ;
V_41 = F_97 ( V_143 , V_107 -> V_27 -> V_4 ,
F_98 ( V_107 -> V_27 ) , V_14 ) ;
if ( V_41 < 0 )
return V_41 ;
}
}
return 0 ;
}
static int F_127 ( struct V_2 * V_3 ,
T_1 V_141 , T_1 V_105 ,
struct V_102 * V_143 , T_1 V_132 ,
int V_144 , int V_156 , int V_145 )
{
struct V_108 * V_109 ;
struct V_110 V_111 ;
struct V_1 * V_148 ;
T_1 V_157 , V_158 ;
F_99 ( & V_111 ) ;
while ( ( V_109 = F_100 ( V_143 , & V_111 ) ) ) {
bool V_18 = false ;
V_148 = F_101 ( V_109 -> V_113 ) ;
if ( V_148 -> V_150 <= V_132 && V_148 -> V_151 > V_132 ) {
V_148 -> V_28 += V_105 ;
V_148 -> V_63 += V_105 ;
V_18 = true ;
}
if ( V_148 -> V_150 > V_132 && V_148 -> V_151 <= V_132 ) {
V_148 -> V_28 -= V_105 ;
V_148 -> V_63 -= V_105 ;
V_18 = true ;
}
if ( V_148 -> V_150 < V_132 )
V_158 = 0 ;
else
V_158 = V_148 -> V_150 - V_132 ;
if ( V_148 -> V_151 < V_132 )
V_157 = 0 ;
else
V_157 = V_148 -> V_151 - V_132 ;
if ( V_144 && V_158 == V_144 &&
( V_157 != V_156 || V_156 == 0 ) ) {
F_96 ( V_157 != V_156 && V_156 == 0 ) ;
V_148 -> V_29 -= V_105 ;
V_148 -> V_64 -= V_105 ;
V_18 = true ;
}
if ( ( ! V_144 || ( V_144 && V_158 != V_144 ) )
&& V_157 == V_156 ) {
V_148 -> V_29 += V_105 ;
V_148 -> V_64 += V_105 ;
V_18 = true ;
}
if ( V_18 )
F_93 ( V_3 , V_148 ) ;
}
return 0 ;
}
static int F_128 ( struct V_76 * V_77 ,
struct V_2 * V_3 ,
struct V_123 * V_127 )
{
struct V_102 * V_142 = NULL ;
struct V_108 * V_109 ;
struct V_110 V_111 ;
int V_41 = 0 ;
V_41 = F_129 ( V_77 , V_3 , V_127 -> V_126 ,
V_127 -> V_136 . V_132 , & V_142 ) ;
if ( V_41 < 0 )
return V_41 ;
V_41 = 0 ;
F_99 ( & V_111 ) ;
while ( ( V_109 = F_100 ( V_142 , & V_111 ) ) ) {
if ( V_109 -> V_149 == V_127 -> V_104 ) {
V_41 = 1 ;
break;
}
}
F_48 ( V_142 ) ;
F_130 ( V_3 , & V_127 -> V_136 ) ;
return V_41 ;
}
static int F_131 ( struct V_76 * V_77 ,
struct V_2 * V_3 ,
struct V_123 * V_127 )
{
struct V_102 * V_142 = NULL ;
struct V_102 * V_143 , * V_103 ;
struct V_1 * V_8 ;
struct V_159 V_136 = F_132 ( V_136 ) ;
T_1 V_132 ;
int V_144 = 0 ;
int V_156 = 0 ;
int V_41 = 0 ;
if ( V_127 -> V_136 . V_132 ) {
V_41 = F_128 ( V_77 , V_3 , V_127 ) ;
if ( V_41 < 0 )
return V_41 ;
if ( V_41 )
return 0 ;
}
V_143 = F_22 ( V_46 ) ;
if ( ! V_143 )
return - V_15 ;
V_103 = F_22 ( V_46 ) ;
if ( ! V_103 ) {
F_48 ( V_143 ) ;
return - V_15 ;
}
F_120 ( V_3 , & V_136 ) ;
V_41 = F_129 ( V_77 , V_3 , V_127 -> V_126 , V_136 . V_132 ,
& V_142 ) ;
F_130 ( V_3 , & V_136 ) ;
if ( V_41 < 0 ) {
F_48 ( V_143 ) ;
F_48 ( V_103 ) ;
return V_41 ;
}
F_83 ( & V_3 -> V_97 ) ;
V_8 = F_1 ( V_3 , V_127 -> V_104 ) ;
if ( ! V_8 )
goto V_47;
V_132 = V_3 -> V_160 ;
V_41 = F_122 ( V_3 , V_127 -> V_104 , V_103 , V_142 , V_143 ,
V_132 , & V_144 , 0 ) ;
if ( V_41 < 0 )
goto V_47;
V_41 = F_126 ( V_3 , V_127 , V_8 , V_103 , V_143 ,
V_132 ) ;
if ( V_41 < 0 )
goto V_47;
V_41 = F_124 ( V_3 , V_127 , V_103 , V_143 , V_132 ,
& V_144 ) ;
if ( V_41 < 0 )
goto V_47;
if ( V_127 -> type == V_155 ) {
V_156 = V_144 + 1 ;
} else {
V_156 = V_144 ;
V_144 ++ ;
}
V_3 -> V_160 += V_144 + 1 ;
F_127 ( V_3 , V_127 -> V_104 , V_127 -> V_105 ,
V_143 , V_132 , V_144 , V_156 , 0 ) ;
V_47:
F_84 ( & V_3 -> V_97 ) ;
F_48 ( V_143 ) ;
F_48 ( V_142 ) ;
F_48 ( V_103 ) ;
return V_41 ;
}
static int F_133 ( struct V_76 * V_77 ,
struct V_2 * V_3 ,
struct V_123 * V_127 )
{
struct V_102 * V_142 = NULL ;
struct V_108 * V_109 ;
struct V_110 V_111 ;
struct V_19 * V_107 ;
struct V_102 * V_161 ;
int V_41 = 0 ;
int V_114 ;
struct V_1 * V_148 ;
T_1 V_162 = 0 ;
struct V_159 V_136 = F_132 ( V_136 ) ;
V_161 = F_22 ( V_46 ) ;
if ( ! V_161 )
return - V_15 ;
F_120 ( V_3 , & V_136 ) ;
V_41 = F_129 ( V_77 , V_3 , V_127 -> V_126 ,
V_136 . V_132 , & V_142 ) ;
F_130 ( V_3 , & V_136 ) ;
if ( V_41 < 0 )
goto V_47;
if ( V_142 -> V_163 != 1 )
goto V_47;
F_99 ( & V_111 ) ;
V_109 = F_100 ( V_142 , & V_111 ) ;
if ( V_109 -> V_149 == V_127 -> V_104 )
goto V_47;
V_162 = V_109 -> V_149 ;
F_134 ( ! V_162 ) ;
F_83 ( & V_3 -> V_97 ) ;
V_148 = F_1 ( V_3 , V_162 ) ;
if ( ! V_148 )
goto V_164;
V_148 -> V_29 += V_127 -> V_105 ;
V_148 -> V_64 += V_127 -> V_105 ;
F_93 ( V_3 , V_148 ) ;
F_19 (glist, &qg->groups, next_group) {
V_114 = F_97 ( V_161 , V_107 -> V_27 -> V_4 ,
F_98 ( V_107 -> V_27 ) , V_14 ) ;
if ( V_114 < 0 ) {
V_41 = V_114 ;
goto V_164;
}
}
F_99 ( & V_111 ) ;
while ( ( V_109 = F_100 ( V_161 , & V_111 ) ) ) {
V_148 = F_101 ( V_109 -> V_113 ) ;
V_148 -> V_29 += V_127 -> V_105 ;
V_148 -> V_64 += V_127 -> V_105 ;
F_93 ( V_3 , V_148 ) ;
F_19 (glist, &qg->groups, next_group) {
V_114 = F_97 ( V_161 , V_107 -> V_27 -> V_4 ,
F_98 ( V_107 -> V_27 ) , V_14 ) ;
if ( V_114 < 0 ) {
V_41 = V_114 ;
goto V_164;
}
}
}
V_164:
F_84 ( & V_3 -> V_97 ) ;
V_47:
F_48 ( V_142 ) ;
F_48 ( V_161 ) ;
return V_41 ;
}
static int F_135 ( struct V_76 * V_77 ,
struct V_2 * V_3 ,
struct V_123 * V_127 )
{
int V_41 = 0 ;
if ( ! V_3 -> V_44 )
return 0 ;
F_134 ( ! V_3 -> V_35 ) ;
F_80 ( & V_3 -> V_165 ) ;
if ( V_3 -> V_48 & V_75 ) {
if ( V_3 -> V_86 . V_49 <= V_127 -> V_126 ) {
F_86 ( & V_3 -> V_165 ) ;
return 0 ;
}
}
F_86 ( & V_3 -> V_165 ) ;
ASSERT ( F_116 ( V_127 -> V_104 ) ) ;
F_136 ( V_127 ) ;
switch ( V_127 -> type ) {
case V_139 :
case V_140 :
V_41 = F_121 ( V_3 , V_127 ) ;
break;
case V_155 :
case V_153 :
V_41 = F_131 ( V_77 , V_3 , V_127 ) ;
break;
case V_137 :
V_41 = F_133 ( V_77 , V_3 , V_127 ) ;
break;
default:
ASSERT ( 0 ) ;
}
return V_41 ;
}
int F_137 ( struct V_76 * V_77 ,
struct V_2 * V_3 )
{
struct V_123 * V_127 ;
int V_41 = 0 ;
while ( ! F_11 ( & V_77 -> V_138 ) ) {
V_127 = F_12 ( & V_77 -> V_138 ,
struct V_123 , V_20 ) ;
F_138 ( & V_127 -> V_20 ) ;
if ( ! V_41 || ! V_77 -> V_166 )
V_41 = F_135 ( V_77 , V_3 , V_127 ) ;
F_83 ( & V_3 -> V_130 ) ;
F_15 ( & V_127 -> V_6 , & V_3 -> V_131 ) ;
F_84 ( & V_3 -> V_130 ) ;
F_130 ( V_3 , & V_127 -> V_136 ) ;
F_13 ( V_127 ) ;
}
return V_41 ;
}
int F_139 ( struct V_76 * V_77 ,
struct V_2 * V_3 )
{
struct V_34 * V_35 = V_3 -> V_35 ;
int V_41 = 0 ;
int V_167 = 0 ;
if ( ! V_35 )
goto V_47;
if ( ! V_3 -> V_44 && V_3 -> V_74 )
V_167 = 1 ;
V_3 -> V_44 = V_3 -> V_74 ;
F_83 ( & V_3 -> V_97 ) ;
while ( ! F_11 ( & V_3 -> V_101 ) ) {
struct V_1 * V_8 ;
V_8 = F_12 ( & V_3 -> V_101 ,
struct V_1 , V_18 ) ;
F_138 ( & V_8 -> V_18 ) ;
F_84 ( & V_3 -> V_97 ) ;
V_41 = F_71 ( V_77 , V_35 , V_8 ) ;
if ( V_41 )
V_3 -> V_48 |=
V_58 ;
V_41 = F_70 ( V_77 , V_35 , V_8 ) ;
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
if ( ! V_41 && V_167 ) {
V_41 = F_46 ( V_3 , 0 , 1 ) ;
if ( ! V_41 ) {
F_140 ( V_3 ) ;
F_141 ( V_3 -> V_168 ,
& V_3 -> V_169 ) ;
}
V_41 = 0 ;
}
V_47:
return V_41 ;
}
int F_142 ( struct V_76 * V_77 ,
struct V_2 * V_3 , T_1 V_170 , T_1 V_49 ,
struct F_142 * V_171 )
{
int V_41 = 0 ;
int V_172 ;
T_1 * V_173 ;
struct V_34 * V_35 = V_3 -> V_35 ;
struct V_1 * V_174 ;
struct V_1 * V_175 ;
T_2 V_176 = 0 ;
T_1 V_177 ;
F_80 ( & V_3 -> V_90 ) ;
if ( ! V_3 -> V_44 )
goto V_47;
if ( ! V_35 ) {
V_41 = - V_30 ;
goto V_47;
}
if ( V_171 ) {
V_173 = ( T_1 * ) ( V_171 + 1 ) ;
V_177 = V_171 -> V_178 + 2 * V_171 -> V_179 +
2 * V_171 -> V_180 ;
for ( V_172 = 0 ; V_172 < V_177 ; ++ V_172 ) {
V_174 = F_1 ( V_3 , * V_173 ) ;
if ( ! V_174 ) {
V_41 = - V_30 ;
goto V_47;
}
if ( ( V_174 -> V_4 >> 48 ) <= ( V_49 >> 48 ) ) {
V_41 = - V_30 ;
goto V_47;
}
++ V_173 ;
}
}
V_41 = F_57 ( V_77 , V_35 , V_49 ) ;
if ( V_41 )
goto V_47;
if ( V_170 ) {
struct V_34 * V_181 ;
struct V_31 V_182 ;
V_182 . V_49 = V_170 ;
V_182 . type = V_183 ;
V_182 . V_50 = ( T_1 ) - 1 ;
V_181 = F_143 ( V_3 , & V_182 ) ;
if ( F_32 ( V_181 ) ) {
V_41 = F_33 ( V_181 ) ;
goto V_47;
}
F_144 () ;
V_176 = V_181 -> V_184 ;
F_145 () ;
}
if ( V_171 ) {
V_173 = ( T_1 * ) ( V_171 + 1 ) ;
for ( V_172 = 0 ; V_172 < V_171 -> V_178 ; ++ V_172 ) {
V_41 = F_51 ( V_77 , V_35 ,
V_49 , * V_173 ) ;
if ( V_41 )
goto V_47;
V_41 = F_51 ( V_77 , V_35 ,
* V_173 , V_49 ) ;
if ( V_41 )
goto V_47;
++ V_173 ;
}
}
F_83 ( & V_3 -> V_97 ) ;
V_175 = F_3 ( V_3 , V_49 ) ;
if ( F_32 ( V_175 ) ) {
V_41 = F_33 ( V_175 ) ;
goto V_185;
}
if ( V_171 && V_171 -> V_42 & V_186 ) {
V_175 -> V_66 = V_171 -> V_187 . V_42 ;
V_175 -> V_67 = V_171 -> V_187 . V_67 ;
V_175 -> V_68 = V_171 -> V_187 . V_68 ;
V_175 -> V_69 = V_171 -> V_187 . V_69 ;
V_175 -> V_70 = V_171 -> V_187 . V_70 ;
V_41 = F_70 ( V_77 , V_35 , V_175 ) ;
if ( V_41 ) {
V_3 -> V_48 |= V_58 ;
F_110 ( V_3 , L_6 ,
V_175 -> V_4 ) ;
goto V_185;
}
}
if ( V_170 ) {
V_174 = F_1 ( V_3 , V_170 ) ;
if ( ! V_174 )
goto V_185;
V_175 -> V_28 = V_174 -> V_28 ;
V_175 -> V_63 = V_174 -> V_63 ;
V_175 -> V_29 = V_176 ;
V_175 -> V_64 = V_176 ;
V_174 -> V_29 = V_176 ;
V_174 -> V_64 = V_176 ;
V_175 -> V_66 = V_174 -> V_66 ;
V_175 -> V_67 = V_174 -> V_67 ;
V_175 -> V_68 = V_174 -> V_68 ;
V_175 -> V_69 = V_174 -> V_69 ;
V_175 -> V_70 = V_174 -> V_70 ;
F_93 ( V_3 , V_175 ) ;
F_93 ( V_3 , V_174 ) ;
}
if ( ! V_171 )
goto V_185;
V_173 = ( T_1 * ) ( V_171 + 1 ) ;
for ( V_172 = 0 ; V_172 < V_171 -> V_178 ; ++ V_172 ) {
V_41 = F_16 ( V_35 -> V_3 , V_49 ,
* V_173 ) ;
if ( V_41 )
goto V_185;
++ V_173 ;
}
for ( V_172 = 0 ; V_172 < V_171 -> V_179 ; ++ V_172 ) {
struct V_1 * V_78 ;
struct V_1 * V_79 ;
V_78 = F_1 ( V_3 , V_173 [ 0 ] ) ;
V_79 = F_1 ( V_3 , V_173 [ 1 ] ) ;
if ( ! V_78 || ! V_79 ) {
V_41 = - V_30 ;
goto V_185;
}
V_79 -> V_28 = V_78 -> V_28 - V_176 ;
V_79 -> V_63 = V_78 -> V_63 - V_176 ;
V_173 += 2 ;
}
for ( V_172 = 0 ; V_172 < V_171 -> V_180 ; ++ V_172 ) {
struct V_1 * V_78 ;
struct V_1 * V_79 ;
V_78 = F_1 ( V_3 , V_173 [ 0 ] ) ;
V_79 = F_1 ( V_3 , V_173 [ 1 ] ) ;
if ( ! V_78 || ! V_79 ) {
V_41 = - V_30 ;
goto V_185;
}
V_79 -> V_29 = V_78 -> V_29 + V_176 ;
V_79 -> V_64 = V_78 -> V_64 + V_176 ;
V_173 += 2 ;
}
V_185:
F_84 ( & V_3 -> V_97 ) ;
V_47:
F_86 ( & V_3 -> V_90 ) ;
return V_41 ;
}
int F_146 ( struct V_34 * V_85 , T_1 V_105 )
{
struct V_34 * V_35 ;
struct V_1 * V_8 ;
struct V_2 * V_3 = V_85 -> V_3 ;
T_1 V_104 = V_85 -> V_99 . V_49 ;
int V_41 = 0 ;
struct V_108 * V_109 ;
struct V_110 V_111 ;
if ( ! F_116 ( V_104 ) )
return 0 ;
if ( V_105 == 0 )
return 0 ;
F_83 ( & V_3 -> V_97 ) ;
V_35 = V_3 -> V_35 ;
if ( ! V_35 )
goto V_47;
V_8 = F_1 ( V_3 , V_104 ) ;
if ( ! V_8 )
goto V_47;
F_123 ( V_3 -> V_45 ) ;
V_41 = F_97 ( V_3 -> V_45 , V_8 -> V_4 ,
( V_188 ) V_8 , V_14 ) ;
if ( V_41 < 0 )
goto V_47;
F_99 ( & V_111 ) ;
while ( ( V_109 = F_100 ( V_3 -> V_45 , & V_111 ) ) ) {
struct V_1 * V_148 ;
struct V_19 * V_107 ;
V_148 = F_101 ( V_109 -> V_113 ) ;
if ( ( V_148 -> V_66 & V_119 ) &&
V_148 -> V_112 + ( V_189 ) V_148 -> V_28 + V_105 >
V_148 -> V_67 ) {
V_41 = - V_190 ;
goto V_47;
}
if ( ( V_148 -> V_66 & V_120 ) &&
V_148 -> V_112 + ( V_189 ) V_148 -> V_29 + V_105 >
V_148 -> V_68 ) {
V_41 = - V_190 ;
goto V_47;
}
F_19 (glist, &qg->groups, next_group) {
V_41 = F_97 ( V_3 -> V_45 ,
V_107 -> V_27 -> V_4 ,
( V_188 ) V_107 -> V_27 , V_14 ) ;
if ( V_41 < 0 )
goto V_47;
}
}
V_41 = 0 ;
F_99 ( & V_111 ) ;
while ( ( V_109 = F_100 ( V_3 -> V_45 , & V_111 ) ) ) {
struct V_1 * V_148 ;
V_148 = F_101 ( V_109 -> V_113 ) ;
V_148 -> V_112 += V_105 ;
}
V_47:
F_84 ( & V_3 -> V_97 ) ;
return V_41 ;
}
void F_147 ( struct V_34 * V_85 , T_1 V_105 )
{
struct V_34 * V_35 ;
struct V_1 * V_8 ;
struct V_2 * V_3 = V_85 -> V_3 ;
struct V_108 * V_109 ;
struct V_110 V_111 ;
T_1 V_104 = V_85 -> V_99 . V_49 ;
int V_41 = 0 ;
if ( ! F_116 ( V_104 ) )
return;
if ( V_105 == 0 )
return;
F_83 ( & V_3 -> V_97 ) ;
V_35 = V_3 -> V_35 ;
if ( ! V_35 )
goto V_47;
V_8 = F_1 ( V_3 , V_104 ) ;
if ( ! V_8 )
goto V_47;
F_123 ( V_3 -> V_45 ) ;
V_41 = F_97 ( V_3 -> V_45 , V_8 -> V_4 ,
( V_188 ) V_8 , V_14 ) ;
if ( V_41 < 0 )
goto V_47;
F_99 ( & V_111 ) ;
while ( ( V_109 = F_100 ( V_3 -> V_45 , & V_111 ) ) ) {
struct V_1 * V_148 ;
struct V_19 * V_107 ;
V_148 = F_101 ( V_109 -> V_113 ) ;
V_148 -> V_112 -= V_105 ;
F_19 (glist, &qg->groups, next_group) {
V_41 = F_97 ( V_3 -> V_45 ,
V_107 -> V_27 -> V_4 ,
( V_188 ) V_107 -> V_27 , V_14 ) ;
if ( V_41 < 0 )
goto V_47;
}
}
V_47:
F_84 ( & V_3 -> V_97 ) ;
}
void F_148 ( struct V_76 * V_77 )
{
if ( F_11 ( & V_77 -> V_138 ) && ! V_77 -> V_191 . V_132 )
return;
F_28 ( V_77 -> V_85 -> V_3 ,
L_7
L_8 ,
V_77 , F_11 ( & V_77 -> V_138 ) ? L_9 : L_10 ,
( T_2 ) ( V_77 -> V_191 . V_132 >> 32 ) ,
( T_2 ) V_77 -> V_191 . V_132 ) ;
F_149 () ;
}
static int
F_150 ( struct V_2 * V_3 , struct V_36 * V_37 ,
struct V_76 * V_77 , struct V_102 * V_143 ,
struct V_102 * V_103 , struct V_38 * V_192 )
{
struct V_31 V_193 ;
struct V_102 * V_142 = NULL ;
struct V_159 V_194 = F_132 ( V_194 ) ;
T_1 V_105 ;
T_1 V_132 ;
int V_156 ;
int V_40 ;
int V_41 ;
V_37 -> V_88 = 1 ;
F_80 ( & V_3 -> V_165 ) ;
V_41 = F_24 ( V_3 -> V_195 ,
& V_3 -> V_86 ,
V_37 , 1 , 0 ) ;
F_151 ( L_11 ,
V_3 -> V_86 . V_49 ,
V_3 -> V_86 . type ,
V_3 -> V_86 . V_50 , V_41 ) ;
if ( V_41 ) {
V_3 -> V_86 . V_49 = ( T_1 ) - 1 ;
F_44 ( V_37 ) ;
F_86 ( & V_3 -> V_165 ) ;
return V_41 ;
}
F_25 ( V_37 -> V_52 [ 0 ] , & V_193 ,
F_77 ( V_37 -> V_52 [ 0 ] ) - 1 ) ;
V_3 -> V_86 . V_49 = V_193 . V_49 + 1 ;
F_120 ( V_3 , & V_194 ) ;
memcpy ( V_192 , V_37 -> V_52 [ 0 ] , sizeof( * V_192 ) ) ;
V_40 = V_37 -> V_51 [ 0 ] ;
F_44 ( V_37 ) ;
F_86 ( & V_3 -> V_165 ) ;
for (; V_40 < F_77 ( V_192 ) ; ++ V_40 ) {
F_25 ( V_192 , & V_193 , V_40 ) ;
if ( V_193 . type != V_196 &&
V_193 . type != V_197 )
continue;
if ( V_193 . type == V_197 )
V_105 = V_3 -> V_195 -> V_184 ;
else
V_105 = V_193 . V_50 ;
F_123 ( V_143 ) ;
V_41 = F_129 ( NULL , V_3 , V_193 . V_49 , 0 ,
& V_142 ) ;
if ( V_41 < 0 )
goto V_47;
F_83 ( & V_3 -> V_97 ) ;
V_132 = V_3 -> V_160 ;
V_3 -> V_160 += V_142 -> V_163 + 1 ;
V_156 = 0 ;
V_41 = F_122 ( V_3 , 0 , V_103 , V_142 , V_143 ,
V_132 , & V_156 , 1 ) ;
if ( V_41 < 0 ) {
F_84 ( & V_3 -> V_97 ) ;
F_48 ( V_142 ) ;
goto V_47;
}
V_41 = F_127 ( V_3 , 0 , V_105 , V_143 ,
V_132 , 0 , V_156 , 1 ) ;
if ( V_41 < 0 ) {
F_84 ( & V_3 -> V_97 ) ;
F_48 ( V_142 ) ;
goto V_47;
}
F_84 ( & V_3 -> V_97 ) ;
F_48 ( V_142 ) ;
}
V_47:
F_130 ( V_3 , & V_194 ) ;
return V_41 ;
}
static void F_152 ( struct V_198 * V_199 )
{
struct V_2 * V_3 = F_153 ( V_199 , struct V_2 ,
V_169 ) ;
struct V_36 * V_37 ;
struct V_76 * V_77 = NULL ;
struct V_102 * V_103 = NULL , * V_143 = NULL ;
struct V_38 * V_192 = NULL ;
int V_114 = - V_15 ;
int V_41 = 0 ;
V_37 = F_23 () ;
if ( ! V_37 )
goto V_47;
V_143 = F_22 ( V_46 ) ;
if ( ! V_143 )
goto V_47;
V_103 = F_22 ( V_46 ) ;
if ( ! V_103 )
goto V_47;
V_192 = F_117 ( sizeof( * V_192 ) , V_46 ) ;
if ( ! V_192 )
goto V_47;
V_114 = 0 ;
while ( ! V_114 ) {
V_77 = F_154 ( V_3 -> V_200 , 0 ) ;
if ( F_32 ( V_77 ) ) {
V_114 = F_33 ( V_77 ) ;
break;
}
if ( ! V_3 -> V_44 ) {
V_114 = - V_201 ;
} else {
V_114 = F_150 ( V_3 , V_37 , V_77 ,
V_143 , V_103 , V_192 ) ;
}
if ( V_114 > 0 )
F_155 ( V_77 , V_3 -> V_200 ) ;
else
F_156 ( V_77 , V_3 -> V_200 ) ;
}
V_47:
F_13 ( V_192 ) ;
F_48 ( V_143 ) ;
F_48 ( V_103 ) ;
F_47 ( V_37 ) ;
F_80 ( & V_3 -> V_165 ) ;
V_3 -> V_48 &= ~ V_75 ;
if ( V_114 > 0 &&
V_3 -> V_48 & V_58 ) {
V_3 -> V_48 &= ~ V_58 ;
} else if ( V_114 < 0 ) {
V_3 -> V_48 |= V_58 ;
}
F_86 ( & V_3 -> V_165 ) ;
V_77 = F_154 ( V_3 -> V_35 , 1 ) ;
if ( F_32 ( V_77 ) ) {
V_114 = F_33 ( V_77 ) ;
F_28 ( V_3 ,
L_12 ,
V_114 ) ;
goto V_202;
}
V_41 = F_72 ( V_77 , V_3 , V_3 -> V_35 ) ;
if ( V_41 < 0 ) {
V_114 = V_41 ;
F_28 ( V_3 , L_13 , V_114 ) ;
}
F_156 ( V_77 , V_3 -> V_35 ) ;
if ( V_114 >= 0 ) {
F_110 ( V_3 , L_14 ,
V_114 > 0 ? L_15 : L_9 ) ;
} else {
F_28 ( V_3 , L_16 , V_114 ) ;
}
V_202:
F_157 ( & V_3 -> V_203 ) ;
}
static int
F_46 ( struct V_2 * V_3 , T_1 V_204 ,
int V_205 )
{
int V_41 = 0 ;
if ( ! V_205 &&
( ! ( V_3 -> V_48 & V_75 ) ||
! ( V_3 -> V_48 & V_73 ) ) ) {
V_41 = - V_30 ;
goto V_114;
}
F_80 ( & V_3 -> V_165 ) ;
F_83 ( & V_3 -> V_97 ) ;
if ( V_205 ) {
if ( V_3 -> V_48 & V_75 )
V_41 = - V_206 ;
else if ( ! ( V_3 -> V_48 & V_73 ) )
V_41 = - V_30 ;
if ( V_41 ) {
F_84 ( & V_3 -> V_97 ) ;
F_86 ( & V_3 -> V_165 ) ;
goto V_114;
}
V_3 -> V_48 |= V_75 ;
}
memset ( & V_3 -> V_86 , 0 ,
sizeof( V_3 -> V_86 ) ) ;
V_3 -> V_86 . V_49 = V_204 ;
F_84 ( & V_3 -> V_97 ) ;
F_86 ( & V_3 -> V_165 ) ;
F_158 ( & V_3 -> V_203 ) ;
memset ( & V_3 -> V_169 , 0 ,
sizeof( V_3 -> V_169 ) ) ;
F_159 ( & V_3 -> V_169 ,
V_207 ,
F_152 , NULL , NULL ) ;
if ( V_41 ) {
V_114:
F_110 ( V_3 , L_17 , V_41 ) ;
return V_41 ;
}
return 0 ;
}
static void
F_140 ( struct V_2 * V_3 )
{
struct V_5 * V_6 ;
struct V_1 * V_8 ;
F_83 ( & V_3 -> V_97 ) ;
for ( V_6 = F_50 ( & V_3 -> V_7 ) ; V_6 ; V_6 = F_125 ( V_6 ) ) {
V_8 = F_2 ( V_6 , struct V_1 , V_9 ) ;
V_8 -> V_28 = 0 ;
V_8 -> V_63 = 0 ;
V_8 -> V_29 = 0 ;
V_8 -> V_64 = 0 ;
}
F_84 ( & V_3 -> V_97 ) ;
}
int
F_160 ( struct V_2 * V_3 )
{
int V_41 = 0 ;
struct V_76 * V_77 ;
V_41 = F_46 ( V_3 , 0 , 1 ) ;
if ( V_41 )
return V_41 ;
V_77 = F_161 ( V_3 -> V_200 ) ;
if ( F_32 ( V_77 ) ) {
V_3 -> V_48 &= ~ V_75 ;
return F_33 ( V_77 ) ;
}
V_41 = F_155 ( V_77 , V_3 -> V_200 ) ;
if ( V_41 ) {
V_3 -> V_48 &= ~ V_75 ;
return V_41 ;
}
F_140 ( V_3 ) ;
F_141 ( V_3 -> V_168 ,
& V_3 -> V_169 ) ;
return 0 ;
}
int F_162 ( struct V_2 * V_3 )
{
int V_208 ;
int V_41 = 0 ;
F_80 ( & V_3 -> V_165 ) ;
F_83 ( & V_3 -> V_97 ) ;
V_208 = V_3 -> V_48 & V_75 ;
F_84 ( & V_3 -> V_97 ) ;
F_86 ( & V_3 -> V_165 ) ;
if ( V_208 )
V_41 = F_163 (
& V_3 -> V_203 ) ;
return V_41 ;
}
void
F_164 ( struct V_2 * V_3 )
{
if ( V_3 -> V_48 & V_75 )
F_141 ( V_3 -> V_168 ,
& V_3 -> V_169 ) ;
}
