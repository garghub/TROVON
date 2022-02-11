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
#ifdef F_58
if ( F_59 ( F_60 ( V_83 , & V_35 -> V_84 ) ) )
return 0 ;
#endif
V_37 = F_23 () ;
if ( ! V_37 )
return - V_15 ;
V_32 . V_49 = 0 ;
V_32 . type = V_60 ;
V_32 . V_50 = V_4 ;
V_41 = F_52 ( V_77 , V_35 , V_37 , & V_32 ,
sizeof( * V_80 ) ) ;
if ( V_41 )
goto V_47;
V_82 = V_37 -> V_52 [ 0 ] ;
V_80 = F_26 ( V_82 , V_37 -> V_51 [ 0 ] ,
struct V_62 ) ;
F_61 ( V_82 , V_80 , V_77 -> V_85 ) ;
F_62 ( V_82 , V_80 , 0 ) ;
F_63 ( V_82 , V_80 , 0 ) ;
F_64 ( V_82 , V_80 , 0 ) ;
F_65 ( V_82 , V_80 , 0 ) ;
F_53 ( V_82 ) ;
F_44 ( V_37 ) ;
V_32 . type = V_61 ;
V_41 = F_52 ( V_77 , V_35 , V_37 , & V_32 ,
sizeof( * V_81 ) ) ;
if ( V_41 )
goto V_47;
V_82 = V_37 -> V_52 [ 0 ] ;
V_81 = F_26 ( V_82 , V_37 -> V_51 [ 0 ] ,
struct V_65 ) ;
F_66 ( V_82 , V_81 , 0 ) ;
F_67 ( V_82 , V_81 , 0 ) ;
F_68 ( V_82 , V_81 , 0 ) ;
F_69 ( V_82 , V_81 , 0 ) ;
F_70 ( V_82 , V_81 , 0 ) ;
F_53 ( V_82 ) ;
V_41 = 0 ;
V_47:
F_47 ( V_37 ) ;
return V_41 ;
}
static int F_71 ( struct V_76 * V_77 ,
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
static int F_72 ( struct V_76 * V_77 ,
struct V_34 * V_86 , T_1 V_4 ,
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
V_41 = F_55 ( V_77 , V_86 , & V_32 , V_37 , 0 , 1 ) ;
if ( V_41 > 0 )
V_41 = - V_23 ;
if ( V_41 )
goto V_47;
V_39 = V_37 -> V_52 [ 0 ] ;
V_40 = V_37 -> V_51 [ 0 ] ;
V_81 = F_26 ( V_39 , V_40 , struct V_65 ) ;
F_66 ( V_39 , V_81 , V_42 ) ;
F_67 ( V_39 , V_81 , V_67 ) ;
F_68 ( V_39 , V_81 , V_68 ) ;
F_69 ( V_39 , V_81 , V_69 ) ;
F_70 ( V_39 , V_81 , V_70 ) ;
F_53 ( V_39 ) ;
V_47:
F_47 ( V_37 ) ;
return V_41 ;
}
static int F_73 ( struct V_76 * V_77 ,
struct V_34 * V_86 ,
struct V_1 * V_8 )
{
struct V_36 * V_37 ;
struct V_31 V_32 ;
struct V_38 * V_39 ;
struct V_62 * V_80 ;
int V_41 ;
int V_40 ;
#ifdef F_58
if ( F_59 ( F_60 ( V_83 , & V_86 -> V_84 ) ) )
return 0 ;
#endif
V_32 . V_49 = 0 ;
V_32 . type = V_60 ;
V_32 . V_50 = V_8 -> V_4 ;
V_37 = F_23 () ;
if ( ! V_37 )
return - V_15 ;
V_41 = F_55 ( V_77 , V_86 , & V_32 , V_37 , 0 , 1 ) ;
if ( V_41 > 0 )
V_41 = - V_23 ;
if ( V_41 )
goto V_47;
V_39 = V_37 -> V_52 [ 0 ] ;
V_40 = V_37 -> V_51 [ 0 ] ;
V_80 = F_26 ( V_39 , V_40 , struct V_62 ) ;
F_61 ( V_39 , V_80 , V_77 -> V_85 ) ;
F_62 ( V_39 , V_80 , V_8 -> V_28 ) ;
F_63 ( V_39 , V_80 , V_8 -> V_63 ) ;
F_64 ( V_39 , V_80 , V_8 -> V_29 ) ;
F_65 ( V_39 , V_80 , V_8 -> V_64 ) ;
F_53 ( V_39 ) ;
V_47:
F_47 ( V_37 ) ;
return V_41 ;
}
static int F_74 ( struct V_76 * V_77 ,
struct V_2 * V_3 ,
struct V_34 * V_86 )
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
V_41 = F_55 ( V_77 , V_86 , & V_32 , V_37 , 0 , 1 ) ;
if ( V_41 > 0 )
V_41 = - V_23 ;
if ( V_41 )
goto V_47;
V_39 = V_37 -> V_52 [ 0 ] ;
V_40 = V_37 -> V_51 [ 0 ] ;
V_55 = F_26 ( V_39 , V_40 , struct V_54 ) ;
F_75 ( V_39 , V_55 , V_3 -> V_48 ) ;
F_76 ( V_39 , V_55 , V_77 -> V_85 ) ;
F_77 ( V_39 , V_55 ,
V_3 -> V_87 . V_49 ) ;
F_53 ( V_39 ) ;
V_47:
F_47 ( V_37 ) ;
return V_41 ;
}
static int F_78 ( struct V_76 * V_77 ,
struct V_34 * V_86 )
{
struct V_36 * V_37 ;
struct V_31 V_32 ;
struct V_38 * V_82 = NULL ;
int V_41 ;
int V_88 = 0 ;
V_37 = F_23 () ;
if ( ! V_37 )
return - V_15 ;
V_37 -> V_89 = 1 ;
V_32 . V_49 = 0 ;
V_32 . V_50 = 0 ;
V_32 . type = 0 ;
while ( 1 ) {
V_41 = F_55 ( V_77 , V_86 , & V_32 , V_37 , - 1 , 1 ) ;
if ( V_41 < 0 )
goto V_47;
V_82 = V_37 -> V_52 [ 0 ] ;
V_88 = F_79 ( V_82 ) ;
if ( ! V_88 )
break;
V_37 -> V_51 [ 0 ] = 0 ;
V_41 = F_80 ( V_77 , V_86 , V_37 , 0 , V_88 ) ;
if ( V_41 )
goto V_47;
F_44 ( V_37 ) ;
}
V_41 = 0 ;
V_47:
V_86 -> V_3 -> V_74 = 0 ;
F_47 ( V_37 ) ;
return V_41 ;
}
int F_81 ( struct V_76 * V_77 ,
struct V_2 * V_3 )
{
struct V_34 * V_35 ;
struct V_34 * V_90 = V_3 -> V_90 ;
struct V_36 * V_37 = NULL ;
struct V_54 * V_55 ;
struct V_38 * V_82 ;
struct V_31 V_32 ;
struct V_31 V_33 ;
struct V_1 * V_8 = NULL ;
int V_41 = 0 ;
int V_40 ;
F_82 ( & V_3 -> V_91 ) ;
if ( V_3 -> V_35 ) {
V_3 -> V_74 = 1 ;
goto V_47;
}
V_3 -> V_45 = F_22 ( V_46 ) ;
if ( ! V_3 -> V_45 ) {
V_41 = - V_15 ;
goto V_47;
}
V_35 = F_83 ( V_77 , V_3 ,
V_92 ) ;
if ( F_32 ( V_35 ) ) {
V_41 = F_33 ( V_35 ) ;
goto V_47;
}
V_37 = F_23 () ;
if ( ! V_37 ) {
V_41 = - V_15 ;
goto V_93;
}
V_32 . V_49 = 0 ;
V_32 . type = V_53 ;
V_32 . V_50 = 0 ;
V_41 = F_52 ( V_77 , V_35 , V_37 , & V_32 ,
sizeof( * V_55 ) ) ;
if ( V_41 )
goto V_94;
V_82 = V_37 -> V_52 [ 0 ] ;
V_55 = F_26 ( V_82 , V_37 -> V_51 [ 0 ] ,
struct V_54 ) ;
F_76 ( V_82 , V_55 , V_77 -> V_85 ) ;
F_84 ( V_82 , V_55 , V_56 ) ;
V_3 -> V_48 = V_73 |
V_58 ;
F_75 ( V_82 , V_55 , V_3 -> V_48 ) ;
F_77 ( V_82 , V_55 , 0 ) ;
F_53 ( V_82 ) ;
V_32 . V_49 = 0 ;
V_32 . type = V_95 ;
V_32 . V_50 = 0 ;
F_44 ( V_37 ) ;
V_41 = F_24 ( V_90 , & V_32 , V_37 , 1 , 0 ) ;
if ( V_41 > 0 )
goto V_96;
if ( V_41 < 0 )
goto V_94;
while ( 1 ) {
V_40 = V_37 -> V_51 [ 0 ] ;
V_82 = V_37 -> V_52 [ 0 ] ;
F_25 ( V_82 , & V_33 , V_40 ) ;
if ( V_33 . type == V_95 ) {
V_41 = F_57 ( V_77 , V_35 ,
V_33 . V_50 ) ;
if ( V_41 )
goto V_94;
V_8 = F_3 ( V_3 , V_33 . V_50 ) ;
if ( F_32 ( V_8 ) ) {
V_41 = F_33 ( V_8 ) ;
goto V_94;
}
}
V_41 = F_43 ( V_90 , V_37 ) ;
if ( V_41 < 0 )
goto V_94;
if ( V_41 )
break;
}
V_96:
F_44 ( V_37 ) ;
V_41 = F_57 ( V_77 , V_35 , V_97 ) ;
if ( V_41 )
goto V_94;
V_8 = F_3 ( V_3 , V_97 ) ;
if ( F_32 ( V_8 ) ) {
V_41 = F_33 ( V_8 ) ;
goto V_94;
}
F_85 ( & V_3 -> V_98 ) ;
V_3 -> V_35 = V_35 ;
V_3 -> V_74 = 1 ;
F_86 ( & V_3 -> V_98 ) ;
V_94:
F_47 ( V_37 ) ;
V_93:
if ( V_41 ) {
F_87 ( V_35 -> V_9 ) ;
F_87 ( V_35 -> V_99 ) ;
F_13 ( V_35 ) ;
}
V_47:
if ( V_41 ) {
F_48 ( V_3 -> V_45 ) ;
V_3 -> V_45 = NULL ;
}
F_88 ( & V_3 -> V_91 ) ;
return V_41 ;
}
int F_89 ( struct V_76 * V_77 ,
struct V_2 * V_3 )
{
struct V_34 * V_90 = V_3 -> V_90 ;
struct V_34 * V_35 ;
int V_41 = 0 ;
F_82 ( & V_3 -> V_91 ) ;
if ( ! V_3 -> V_35 )
goto V_47;
F_85 ( & V_3 -> V_98 ) ;
V_3 -> V_44 = 0 ;
V_3 -> V_74 = 0 ;
V_35 = V_3 -> V_35 ;
V_3 -> V_35 = NULL ;
F_86 ( & V_3 -> V_98 ) ;
F_49 ( V_3 ) ;
V_41 = F_78 ( V_77 , V_35 ) ;
if ( V_41 )
goto V_47;
V_41 = F_90 ( V_77 , V_90 , & V_35 -> V_100 ) ;
if ( V_41 )
goto V_47;
F_10 ( & V_35 -> V_101 ) ;
F_91 ( V_35 -> V_9 ) ;
F_92 ( V_77 , V_90 , V_35 -> V_9 ) ;
F_93 ( V_35 -> V_9 ) ;
F_94 ( V_77 , V_35 , V_35 -> V_9 , 0 , 1 ) ;
F_87 ( V_35 -> V_9 ) ;
F_87 ( V_35 -> V_99 ) ;
F_13 ( V_35 ) ;
V_47:
F_88 ( & V_3 -> V_91 ) ;
return V_41 ;
}
static void F_95 ( struct V_2 * V_3 ,
struct V_1 * V_8 )
{
if ( F_11 ( & V_8 -> V_18 ) )
F_96 ( & V_8 -> V_18 , & V_3 -> V_102 ) ;
}
int F_97 ( struct V_76 * V_77 ,
struct V_2 * V_3 , T_1 V_78 , T_1 V_79 )
{
struct V_34 * V_35 ;
struct V_1 * V_13 ;
struct V_1 * V_26 ;
struct V_19 * V_20 ;
int V_41 = 0 ;
F_82 ( & V_3 -> V_91 ) ;
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
V_41 = - V_103 ;
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
F_85 ( & V_3 -> V_98 ) ;
V_41 = F_16 ( V_35 -> V_3 , V_78 , V_79 ) ;
F_86 ( & V_3 -> V_98 ) ;
V_47:
F_88 ( & V_3 -> V_91 ) ;
return V_41 ;
}
int F_98 ( struct V_76 * V_77 ,
struct V_2 * V_3 , T_1 V_78 , T_1 V_79 )
{
struct V_34 * V_35 ;
struct V_1 * V_13 ;
struct V_1 * V_26 ;
struct V_19 * V_20 ;
int V_41 = 0 ;
int V_104 ;
F_82 ( & V_3 -> V_91 ) ;
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
goto V_105;
}
V_41 = - V_23 ;
goto V_47;
V_105:
V_41 = F_54 ( V_77 , V_35 , V_78 , V_79 ) ;
V_104 = F_54 ( V_77 , V_35 , V_79 , V_78 ) ;
if ( V_104 && ! V_41 )
V_41 = V_104 ;
F_85 ( & V_3 -> V_98 ) ;
F_18 ( V_3 , V_78 , V_79 ) ;
F_86 ( & V_3 -> V_98 ) ;
V_47:
F_88 ( & V_3 -> V_91 ) ;
return V_41 ;
}
int F_99 ( struct V_76 * V_77 ,
struct V_2 * V_3 , T_1 V_4 , char * V_106 )
{
struct V_34 * V_35 ;
struct V_1 * V_8 ;
int V_41 = 0 ;
F_82 ( & V_3 -> V_91 ) ;
V_35 = V_3 -> V_35 ;
if ( ! V_35 ) {
V_41 = - V_30 ;
goto V_47;
}
V_8 = F_1 ( V_3 , V_4 ) ;
if ( V_8 ) {
V_41 = - V_103 ;
goto V_47;
}
V_41 = F_57 ( V_77 , V_35 , V_4 ) ;
if ( V_41 )
goto V_47;
F_85 ( & V_3 -> V_98 ) ;
V_8 = F_3 ( V_3 , V_4 ) ;
F_86 ( & V_3 -> V_98 ) ;
if ( F_32 ( V_8 ) )
V_41 = F_33 ( V_8 ) ;
V_47:
F_88 ( & V_3 -> V_91 ) ;
return V_41 ;
}
int F_100 ( struct V_76 * V_77 ,
struct V_2 * V_3 , T_1 V_4 )
{
struct V_34 * V_35 ;
struct V_1 * V_8 ;
int V_41 = 0 ;
F_82 ( & V_3 -> V_91 ) ;
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
V_41 = - V_107 ;
goto V_47;
}
}
V_41 = F_71 ( V_77 , V_35 , V_4 ) ;
F_85 ( & V_3 -> V_98 ) ;
F_14 ( V_35 -> V_3 , V_4 ) ;
F_86 ( & V_3 -> V_98 ) ;
V_47:
F_88 ( & V_3 -> V_91 ) ;
return V_41 ;
}
int F_101 ( struct V_76 * V_77 ,
struct V_2 * V_3 , T_1 V_4 ,
struct V_108 * V_109 )
{
struct V_34 * V_35 ;
struct V_1 * V_8 ;
int V_41 = 0 ;
F_82 ( & V_3 -> V_91 ) ;
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
V_41 = F_72 ( V_77 , V_35 , V_4 ,
V_109 -> V_42 , V_109 -> V_67 ,
V_109 -> V_68 , V_109 -> V_69 ,
V_109 -> V_70 ) ;
if ( V_41 ) {
V_3 -> V_48 |= V_58 ;
F_102 ( V_3 , L_6 ,
V_4 ) ;
}
F_85 ( & V_3 -> V_98 ) ;
V_8 -> V_66 = V_109 -> V_42 ;
V_8 -> V_67 = V_109 -> V_67 ;
V_8 -> V_68 = V_109 -> V_68 ;
V_8 -> V_69 = V_109 -> V_69 ;
V_8 -> V_70 = V_109 -> V_70 ;
F_86 ( & V_3 -> V_98 ) ;
V_47:
F_88 ( & V_3 -> V_91 ) ;
return V_41 ;
}
static int F_103 ( struct V_110 * V_111 ,
struct V_110 * V_112 )
{
if ( V_111 -> V_113 < V_112 -> V_113 )
return - 1 ;
if ( V_111 -> V_113 > V_112 -> V_113 )
return 1 ;
if ( V_111 -> V_114 < V_112 -> V_114 )
return - 1 ;
if ( V_111 -> V_114 > V_112 -> V_114 )
return - 1 ;
if ( V_111 -> V_115 < V_112 -> V_115 )
return - 1 ;
if ( V_111 -> V_115 > V_112 -> V_115 )
return 1 ;
if ( V_111 -> type < V_112 -> type )
return - 1 ;
if ( V_111 -> type > V_112 -> type )
return 1 ;
return 0 ;
}
static int F_104 ( struct V_2 * V_3 ,
struct V_110 * V_116 )
{
struct V_5 * * V_12 ;
struct V_5 * V_13 = NULL ;
struct V_110 * V_117 ;
int V_118 ;
F_85 ( & V_3 -> V_119 ) ;
V_12 = & V_3 -> V_120 . V_5 ;
while ( * V_12 ) {
V_13 = * V_12 ;
V_117 = F_2 ( V_13 , struct V_110 , V_6 ) ;
V_118 = F_103 ( V_117 , V_116 ) ;
if ( V_118 < 0 ) {
V_12 = & ( * V_12 ) -> V_11 ;
} else if ( V_118 ) {
V_12 = & ( * V_12 ) -> V_10 ;
} else {
F_86 ( & V_3 -> V_119 ) ;
return - V_103 ;
}
}
F_7 ( & V_116 -> V_6 , V_13 , V_12 ) ;
F_8 ( & V_116 -> V_6 , & V_3 -> V_120 ) ;
F_86 ( & V_3 -> V_119 ) ;
return 0 ;
}
int F_105 ( struct V_76 * V_77 ,
struct V_2 * V_3 , T_1 V_115 ,
T_1 V_113 , T_1 V_121 ,
enum V_122 type , int V_123 )
{
struct V_110 * V_116 ;
int V_41 ;
if ( ! F_106 ( V_115 ) || ! V_3 -> V_44 )
return 0 ;
V_116 = F_107 ( sizeof( * V_116 ) , V_46 ) ;
if ( ! V_116 )
return - V_15 ;
V_116 -> V_115 = V_115 ;
V_116 -> V_113 = V_113 ;
V_116 -> V_121 = V_121 ;
V_116 -> type = type ;
V_116 -> V_114 = F_108 ( & V_3 -> V_124 ) ;
F_6 ( & V_116 -> V_125 . V_20 ) ;
V_116 -> V_125 . V_114 = 0 ;
V_41 = F_104 ( V_3 , V_116 ) ;
if ( V_41 ) {
ASSERT ( 0 ) ;
F_13 ( V_116 ) ;
return V_41 ;
}
F_17 ( & V_116 -> V_20 , & V_77 -> V_126 ) ;
if ( V_123 )
F_109 ( V_3 , & V_116 -> V_125 ) ;
return 0 ;
}
static int F_110 ( struct V_2 * V_3 ,
struct V_110 * V_116 )
{
struct V_1 * V_8 ;
struct V_127 * V_128 ;
struct V_19 * V_129 ;
struct V_130 * V_131 ;
struct V_132 V_133 ;
int V_134 = 0 ;
int V_41 = 0 ;
V_128 = F_22 ( V_46 ) ;
if ( ! V_128 )
return - V_15 ;
F_85 ( & V_3 -> V_98 ) ;
if ( ! V_3 -> V_35 )
goto V_47;
V_8 = F_1 ( V_3 , V_116 -> V_115 ) ;
if ( ! V_8 )
goto V_47;
switch ( V_116 -> type ) {
case V_135 :
V_134 = 1 ;
break;
case V_136 :
V_134 = - 1 ;
break;
default:
ASSERT ( 0 ) ;
}
V_8 -> V_28 += V_134 * V_116 -> V_121 ;
V_8 -> V_63 += V_134 * V_116 -> V_121 ;
F_111 ( V_134 < 0 && V_8 -> V_29 < V_116 -> V_121 ) ;
V_8 -> V_29 += V_134 * V_116 -> V_121 ;
V_8 -> V_64 += V_134 * V_116 -> V_121 ;
F_95 ( V_3 , V_8 ) ;
F_19 (glist, &qgroup->groups, next_group) {
V_41 = F_112 ( V_128 , V_129 -> V_27 -> V_4 ,
F_113 ( V_129 -> V_27 ) , V_14 ) ;
if ( V_41 < 0 )
goto V_47;
}
F_114 ( & V_133 ) ;
while ( ( V_131 = F_115 ( V_128 , & V_133 ) ) ) {
V_8 = F_116 ( V_131 -> V_137 ) ;
V_8 -> V_28 += V_134 * V_116 -> V_121 ;
V_8 -> V_63 += V_134 * V_116 -> V_121 ;
V_8 -> V_29 += V_134 * V_116 -> V_121 ;
if ( V_134 < 0 )
F_111 ( V_8 -> V_29 < V_116 -> V_121 ) ;
V_8 -> V_64 += V_134 * V_116 -> V_121 ;
F_95 ( V_3 , V_8 ) ;
F_19 (glist, &qgroup->groups, next_group) {
V_41 = F_112 ( V_128 , V_129 -> V_27 -> V_4 ,
F_113 ( V_129 -> V_27 ) , V_14 ) ;
if ( V_41 < 0 )
goto V_47;
}
}
V_41 = 0 ;
V_47:
F_86 ( & V_3 -> V_98 ) ;
F_48 ( V_128 ) ;
return V_41 ;
}
static int F_117 ( struct V_2 * V_3 ,
T_1 V_138 , struct V_127 * V_128 ,
struct V_127 * V_139 , struct V_127 * V_140 ,
T_1 V_114 , int * V_141 , int V_142 )
{
struct V_130 * V_131 ;
struct V_132 V_133 ;
struct V_130 * V_143 ;
struct V_132 V_144 ;
struct V_1 * V_145 ;
int V_41 ;
F_114 ( & V_133 ) ;
while ( ( V_131 = F_115 ( V_139 , & V_133 ) ) ) {
if ( V_131 -> V_146 == V_138 )
continue;
V_145 = F_1 ( V_3 , V_131 -> V_146 ) ;
if ( ! V_145 )
continue;
( * V_141 ) ++ ;
F_118 ( V_128 ) ;
V_41 = F_112 ( V_140 , V_145 -> V_4 , F_113 ( V_145 ) ,
V_14 ) ;
if ( V_41 < 0 )
return V_41 ;
V_41 = F_112 ( V_128 , V_145 -> V_4 , F_113 ( V_145 ) , V_14 ) ;
if ( V_41 < 0 )
return V_41 ;
F_114 ( & V_144 ) ;
while ( ( V_143 = F_115 ( V_128 , & V_144 ) ) ) {
struct V_19 * V_129 ;
V_145 = F_116 ( V_143 -> V_137 ) ;
if ( V_142 )
V_145 -> V_147 = V_114 ;
else if ( V_145 -> V_147 < V_114 )
V_145 -> V_147 = V_114 + 1 ;
else
V_145 -> V_147 ++ ;
if ( V_145 -> V_148 < V_114 )
V_145 -> V_148 = V_114 + 1 ;
else
V_145 -> V_148 ++ ;
F_19 (glist, &qg->groups, next_group) {
V_41 = F_112 ( V_140 , V_129 -> V_27 -> V_4 ,
F_113 ( V_129 -> V_27 ) ,
V_14 ) ;
if ( V_41 < 0 )
return V_41 ;
V_41 = F_112 ( V_128 , V_129 -> V_27 -> V_4 ,
F_113 ( V_129 -> V_27 ) ,
V_14 ) ;
if ( V_41 < 0 )
return V_41 ;
}
}
}
return 0 ;
}
static int F_119 ( struct V_2 * V_3 ,
struct V_110 * V_116 ,
struct V_127 * V_128 ,
struct V_127 * V_140 , T_1 V_114 ,
int * V_141 )
{
struct V_130 * V_131 ;
struct V_132 V_133 ;
struct V_1 * V_145 ;
struct V_110 * V_149 ;
struct V_5 * V_6 ;
int V_41 ;
F_118 ( V_128 ) ;
F_85 ( & V_3 -> V_119 ) ;
V_6 = F_120 ( & V_116 -> V_6 ) ;
F_86 ( & V_3 -> V_119 ) ;
if ( ! V_6 )
return 0 ;
V_149 = F_2 ( V_6 , struct V_110 , V_6 ) ;
while ( V_149 -> V_113 == V_116 -> V_113 ) {
if ( V_149 -> type != V_150 &&
V_149 -> type != V_136 )
goto V_151;
V_145 = F_1 ( V_3 , V_149 -> V_115 ) ;
if ( ! V_145 )
goto V_151;
V_41 = F_112 ( V_140 , V_145 -> V_4 , F_113 ( V_145 ) ,
V_14 ) ;
if ( V_41 ) {
if ( V_41 < 0 )
return V_41 ;
( * V_141 ) ++ ;
V_41 = F_112 ( V_128 , V_145 -> V_4 , F_113 ( V_145 ) ,
V_14 ) ;
if ( V_41 < 0 )
return V_41 ;
}
V_151:
F_85 ( & V_3 -> V_119 ) ;
V_6 = F_120 ( & V_149 -> V_6 ) ;
F_86 ( & V_3 -> V_119 ) ;
if ( ! V_6 )
break;
V_149 = F_2 ( V_6 , struct V_110 , V_6 ) ;
}
F_114 ( & V_133 ) ;
while ( ( V_131 = F_115 ( V_128 , & V_133 ) ) ) {
struct V_19 * V_129 ;
V_145 = F_116 ( V_131 -> V_137 ) ;
if ( V_145 -> V_147 < V_114 )
V_145 -> V_147 = V_114 + 1 ;
else
V_145 -> V_147 ++ ;
if ( V_145 -> V_148 < V_114 )
V_145 -> V_148 = V_114 + 1 ;
else
V_145 -> V_148 ++ ;
F_19 (glist, &qg->groups, next_group) {
V_41 = F_112 ( V_140 , V_129 -> V_27 -> V_4 ,
F_113 ( V_129 -> V_27 ) , V_14 ) ;
if ( V_41 < 0 )
return V_41 ;
V_41 = F_112 ( V_128 , V_129 -> V_27 -> V_4 ,
F_113 ( V_129 -> V_27 ) , V_14 ) ;
if ( V_41 < 0 )
return V_41 ;
}
}
return 0 ;
}
static int F_121 ( struct V_2 * V_3 ,
struct V_110 * V_116 ,
struct V_1 * V_8 ,
struct V_127 * V_128 , struct V_127 * V_140 ,
T_1 V_114 )
{
struct V_130 * V_131 ;
struct V_132 V_133 ;
struct V_1 * V_145 ;
int V_41 ;
F_118 ( V_128 ) ;
V_41 = F_112 ( V_140 , V_8 -> V_4 , F_113 ( V_8 ) ,
V_14 ) ;
if ( V_41 < 0 )
return V_41 ;
V_41 = F_112 ( V_128 , V_8 -> V_4 , F_113 ( V_8 ) ,
V_14 ) ;
if ( V_41 < 0 )
return V_41 ;
F_114 ( & V_133 ) ;
while ( ( V_131 = F_115 ( V_128 , & V_133 ) ) ) {
struct V_19 * V_129 ;
V_145 = F_116 ( V_131 -> V_137 ) ;
if ( V_116 -> type == V_152 ) {
if ( V_145 -> V_148 < V_114 )
V_145 -> V_148 = V_114 + 1 ;
else
V_145 -> V_148 ++ ;
} else {
if ( V_145 -> V_147 < V_114 )
V_145 -> V_147 = V_114 + 1 ;
else
V_145 -> V_147 ++ ;
}
F_19 (glist, &qg->groups, next_group) {
V_41 = F_112 ( V_128 , V_129 -> V_27 -> V_4 ,
F_113 ( V_129 -> V_27 ) , V_14 ) ;
if ( V_41 < 0 )
return V_41 ;
V_41 = F_112 ( V_140 , V_129 -> V_27 -> V_4 ,
F_113 ( V_129 -> V_27 ) , V_14 ) ;
if ( V_41 < 0 )
return V_41 ;
}
}
return 0 ;
}
static int F_122 ( struct V_2 * V_3 ,
T_1 V_138 , T_1 V_121 ,
struct V_127 * V_140 , T_1 V_114 ,
int V_141 , int V_153 , int V_142 )
{
struct V_130 * V_131 ;
struct V_132 V_133 ;
struct V_1 * V_145 ;
T_1 V_154 , V_155 ;
F_114 ( & V_133 ) ;
while ( ( V_131 = F_115 ( V_140 , & V_133 ) ) ) {
bool V_18 = false ;
V_145 = F_116 ( V_131 -> V_137 ) ;
if ( V_145 -> V_147 <= V_114 && V_145 -> V_148 > V_114 ) {
V_145 -> V_28 += V_121 ;
V_145 -> V_63 += V_121 ;
V_18 = true ;
}
if ( V_145 -> V_147 > V_114 && V_145 -> V_148 <= V_114 ) {
V_145 -> V_28 -= V_121 ;
V_145 -> V_63 -= V_121 ;
V_18 = true ;
}
if ( V_145 -> V_147 < V_114 )
V_155 = 0 ;
else
V_155 = V_145 -> V_147 - V_114 ;
if ( V_145 -> V_148 < V_114 )
V_154 = 0 ;
else
V_154 = V_145 -> V_148 - V_114 ;
if ( V_141 && V_155 == V_141 &&
( V_154 != V_153 || V_153 == 0 ) ) {
F_111 ( V_154 != V_153 && V_153 == 0 ) ;
V_145 -> V_29 -= V_121 ;
V_145 -> V_64 -= V_121 ;
V_18 = true ;
}
if ( ( ! V_141 || ( V_141 && V_155 != V_141 ) )
&& V_154 == V_153 ) {
V_145 -> V_29 += V_121 ;
V_145 -> V_64 += V_121 ;
V_18 = true ;
}
if ( V_18 )
F_95 ( V_3 , V_145 ) ;
}
return 0 ;
}
static int F_123 ( struct V_76 * V_77 ,
struct V_2 * V_3 ,
struct V_110 * V_116 )
{
struct V_127 * V_139 = NULL ;
struct V_130 * V_131 ;
struct V_132 V_133 ;
int V_41 = 0 ;
V_41 = F_124 ( V_77 , V_3 , V_116 -> V_113 ,
V_116 -> V_125 . V_114 , & V_139 ) ;
if ( V_41 < 0 )
return V_41 ;
V_41 = 0 ;
F_114 ( & V_133 ) ;
while ( ( V_131 = F_115 ( V_139 , & V_133 ) ) ) {
if ( V_131 -> V_146 == V_116 -> V_115 ) {
V_41 = 1 ;
break;
}
}
F_48 ( V_139 ) ;
F_125 ( V_3 , & V_116 -> V_125 ) ;
return V_41 ;
}
static int F_126 ( struct V_76 * V_77 ,
struct V_2 * V_3 ,
struct V_110 * V_116 )
{
struct V_127 * V_139 = NULL ;
struct V_127 * V_140 , * V_128 ;
struct V_1 * V_8 ;
struct V_156 V_125 = {} ;
T_1 V_114 ;
int V_141 = 0 ;
int V_153 = 0 ;
int V_41 = 0 ;
if ( V_116 -> V_125 . V_114 ) {
V_41 = F_123 ( V_77 , V_3 , V_116 ) ;
if ( V_41 < 0 )
return V_41 ;
if ( V_41 )
return 0 ;
}
V_140 = F_22 ( V_46 ) ;
if ( ! V_140 )
return - V_15 ;
V_128 = F_22 ( V_46 ) ;
if ( ! V_128 ) {
F_48 ( V_140 ) ;
return - V_15 ;
}
F_109 ( V_3 , & V_125 ) ;
V_41 = F_124 ( V_77 , V_3 , V_116 -> V_113 , V_125 . V_114 ,
& V_139 ) ;
F_125 ( V_3 , & V_125 ) ;
if ( V_41 < 0 ) {
F_48 ( V_140 ) ;
F_48 ( V_128 ) ;
return V_41 ;
}
F_85 ( & V_3 -> V_98 ) ;
V_8 = F_1 ( V_3 , V_116 -> V_115 ) ;
if ( ! V_8 )
goto V_47;
V_114 = V_3 -> V_157 ;
V_41 = F_117 ( V_3 , V_116 -> V_115 , V_128 , V_139 , V_140 ,
V_114 , & V_141 , 0 ) ;
if ( V_41 < 0 )
goto V_47;
V_41 = F_121 ( V_3 , V_116 , V_8 , V_128 , V_140 ,
V_114 ) ;
if ( V_41 < 0 )
goto V_47;
V_41 = F_119 ( V_3 , V_116 , V_128 , V_140 , V_114 ,
& V_141 ) ;
if ( V_41 < 0 )
goto V_47;
if ( V_116 -> type == V_152 ) {
V_153 = V_141 + 1 ;
} else {
V_153 = V_141 ;
V_141 ++ ;
}
V_3 -> V_157 += V_141 + 1 ;
F_122 ( V_3 , V_116 -> V_115 , V_116 -> V_121 ,
V_140 , V_114 , V_141 , V_153 , 0 ) ;
V_47:
F_86 ( & V_3 -> V_98 ) ;
F_48 ( V_140 ) ;
F_48 ( V_139 ) ;
F_48 ( V_128 ) ;
return V_41 ;
}
static int F_127 ( struct V_76 * V_77 ,
struct V_2 * V_3 ,
struct V_110 * V_116 )
{
int V_41 = 0 ;
if ( ! V_3 -> V_44 )
return 0 ;
F_128 ( ! V_3 -> V_35 ) ;
F_82 ( & V_3 -> V_158 ) ;
if ( V_3 -> V_48 & V_75 ) {
if ( V_3 -> V_87 . V_49 <= V_116 -> V_113 ) {
F_88 ( & V_3 -> V_158 ) ;
return 0 ;
}
}
F_88 ( & V_3 -> V_158 ) ;
ASSERT ( F_106 ( V_116 -> V_115 ) ) ;
switch ( V_116 -> type ) {
case V_135 :
case V_136 :
V_41 = F_110 ( V_3 , V_116 ) ;
break;
case V_152 :
case V_150 :
V_41 = F_126 ( V_77 , V_3 , V_116 ) ;
break;
default:
ASSERT ( 0 ) ;
}
return V_41 ;
}
int F_129 ( struct V_76 * V_77 ,
struct V_2 * V_3 )
{
struct V_110 * V_116 ;
int V_41 = 0 ;
while ( ! F_11 ( & V_77 -> V_126 ) ) {
V_116 = F_12 ( & V_77 -> V_126 ,
struct V_110 , V_20 ) ;
F_130 ( & V_116 -> V_20 ) ;
if ( ! V_41 || ! V_77 -> V_159 )
V_41 = F_127 ( V_77 , V_3 , V_116 ) ;
F_85 ( & V_3 -> V_119 ) ;
F_15 ( & V_116 -> V_6 , & V_3 -> V_120 ) ;
F_86 ( & V_3 -> V_119 ) ;
F_125 ( V_3 , & V_116 -> V_125 ) ;
F_13 ( V_116 ) ;
}
return V_41 ;
}
int F_131 ( struct V_76 * V_77 ,
struct V_2 * V_3 )
{
struct V_34 * V_35 = V_3 -> V_35 ;
int V_41 = 0 ;
int V_160 = 0 ;
if ( ! V_35 )
goto V_47;
if ( ! V_3 -> V_44 && V_3 -> V_74 )
V_160 = 1 ;
V_3 -> V_44 = V_3 -> V_74 ;
F_85 ( & V_3 -> V_98 ) ;
while ( ! F_11 ( & V_3 -> V_102 ) ) {
struct V_1 * V_8 ;
V_8 = F_12 ( & V_3 -> V_102 ,
struct V_1 , V_18 ) ;
F_130 ( & V_8 -> V_18 ) ;
F_86 ( & V_3 -> V_98 ) ;
V_41 = F_73 ( V_77 , V_35 , V_8 ) ;
if ( V_41 )
V_3 -> V_48 |=
V_58 ;
F_85 ( & V_3 -> V_98 ) ;
}
if ( V_3 -> V_44 )
V_3 -> V_48 |= V_73 ;
else
V_3 -> V_48 &= ~ V_73 ;
F_86 ( & V_3 -> V_98 ) ;
V_41 = F_74 ( V_77 , V_3 , V_35 ) ;
if ( V_41 )
V_3 -> V_48 |= V_58 ;
if ( ! V_41 && V_160 ) {
V_41 = F_46 ( V_3 , 0 , 1 ) ;
if ( ! V_41 ) {
F_132 ( V_3 ) ;
F_133 ( V_3 -> V_161 ,
& V_3 -> V_162 ) ;
}
V_41 = 0 ;
}
V_47:
return V_41 ;
}
int F_134 ( struct V_76 * V_77 ,
struct V_2 * V_3 , T_1 V_163 , T_1 V_49 ,
struct F_134 * V_164 )
{
int V_41 = 0 ;
int V_165 ;
T_1 * V_166 ;
struct V_34 * V_35 = V_3 -> V_35 ;
struct V_1 * V_167 ;
struct V_1 * V_168 ;
T_2 V_169 = 0 ;
T_1 V_170 ;
F_82 ( & V_3 -> V_91 ) ;
if ( ! V_3 -> V_44 )
goto V_47;
if ( ! V_35 ) {
V_41 = - V_30 ;
goto V_47;
}
if ( V_164 ) {
V_166 = ( T_1 * ) ( V_164 + 1 ) ;
V_170 = V_164 -> V_171 + 2 * V_164 -> V_172 +
2 * V_164 -> V_173 ;
for ( V_165 = 0 ; V_165 < V_170 ; ++ V_165 ) {
V_167 = F_1 ( V_3 , * V_166 ) ;
if ( ! V_167 ) {
V_41 = - V_30 ;
goto V_47;
}
++ V_166 ;
}
}
V_41 = F_57 ( V_77 , V_35 , V_49 ) ;
if ( V_41 )
goto V_47;
if ( V_164 && V_164 -> V_42 & V_174 ) {
V_41 = F_72 ( V_77 , V_35 , V_49 ,
V_164 -> V_175 . V_42 ,
V_164 -> V_175 . V_67 ,
V_164 -> V_175 . V_68 ,
V_164 -> V_175 . V_69 ,
V_164 -> V_175 . V_70 ) ;
if ( V_41 )
goto V_47;
}
if ( V_163 ) {
struct V_34 * V_176 ;
struct V_31 V_177 ;
int V_178 ;
V_177 . V_49 = V_163 ;
V_177 . type = V_179 ;
V_177 . V_50 = ( T_1 ) - 1 ;
V_176 = F_135 ( V_3 , & V_177 ) ;
if ( F_32 ( V_176 ) ) {
V_41 = F_33 ( V_176 ) ;
goto V_47;
}
F_136 () ;
V_178 = F_137 ( V_176 -> V_9 ) ;
V_169 = F_138 ( V_176 , V_178 ) ;
F_139 () ;
}
if ( V_164 ) {
V_166 = ( T_1 * ) ( V_164 + 1 ) ;
for ( V_165 = 0 ; V_165 < V_164 -> V_171 ; ++ V_165 ) {
V_41 = F_51 ( V_77 , V_35 ,
V_49 , * V_166 ) ;
if ( V_41 )
goto V_47;
V_41 = F_51 ( V_77 , V_35 ,
* V_166 , V_49 ) ;
if ( V_41 )
goto V_47;
++ V_166 ;
}
}
F_85 ( & V_3 -> V_98 ) ;
V_168 = F_3 ( V_3 , V_49 ) ;
if ( F_32 ( V_168 ) ) {
V_41 = F_33 ( V_168 ) ;
goto V_180;
}
if ( V_163 ) {
V_167 = F_1 ( V_3 , V_163 ) ;
if ( ! V_167 )
goto V_180;
V_168 -> V_28 = V_167 -> V_28 ;
V_168 -> V_63 = V_167 -> V_63 ;
V_168 -> V_29 = V_169 ;
V_168 -> V_64 = V_169 ;
V_167 -> V_29 = V_169 ;
V_167 -> V_64 = V_169 ;
F_95 ( V_3 , V_168 ) ;
F_95 ( V_3 , V_167 ) ;
}
if ( ! V_164 )
goto V_180;
V_166 = ( T_1 * ) ( V_164 + 1 ) ;
for ( V_165 = 0 ; V_165 < V_164 -> V_171 ; ++ V_165 ) {
V_41 = F_16 ( V_35 -> V_3 , V_49 ,
* V_166 ) ;
if ( V_41 )
goto V_180;
++ V_166 ;
}
for ( V_165 = 0 ; V_165 < V_164 -> V_172 ; ++ V_165 ) {
struct V_1 * V_78 ;
struct V_1 * V_79 ;
V_78 = F_1 ( V_3 , V_166 [ 0 ] ) ;
V_79 = F_1 ( V_3 , V_166 [ 1 ] ) ;
if ( ! V_78 || ! V_79 ) {
V_41 = - V_30 ;
goto V_180;
}
V_79 -> V_28 = V_78 -> V_28 - V_169 ;
V_79 -> V_63 = V_78 -> V_63 - V_169 ;
V_166 += 2 ;
}
for ( V_165 = 0 ; V_165 < V_164 -> V_173 ; ++ V_165 ) {
struct V_1 * V_78 ;
struct V_1 * V_79 ;
V_78 = F_1 ( V_3 , V_166 [ 0 ] ) ;
V_79 = F_1 ( V_3 , V_166 [ 1 ] ) ;
if ( ! V_78 || ! V_79 ) {
V_41 = - V_30 ;
goto V_180;
}
V_79 -> V_29 = V_78 -> V_29 + V_169 ;
V_79 -> V_64 = V_78 -> V_64 + V_169 ;
V_166 += 2 ;
}
V_180:
F_86 ( & V_3 -> V_98 ) ;
V_47:
F_88 ( & V_3 -> V_91 ) ;
return V_41 ;
}
int F_140 ( struct V_34 * V_86 , T_1 V_121 )
{
struct V_34 * V_35 ;
struct V_1 * V_8 ;
struct V_2 * V_3 = V_86 -> V_3 ;
T_1 V_115 = V_86 -> V_100 . V_49 ;
int V_41 = 0 ;
struct V_130 * V_131 ;
struct V_132 V_133 ;
if ( ! F_106 ( V_115 ) )
return 0 ;
if ( V_121 == 0 )
return 0 ;
F_85 ( & V_3 -> V_98 ) ;
V_35 = V_3 -> V_35 ;
if ( ! V_35 )
goto V_47;
V_8 = F_1 ( V_3 , V_115 ) ;
if ( ! V_8 )
goto V_47;
F_118 ( V_3 -> V_45 ) ;
V_41 = F_112 ( V_3 -> V_45 , V_8 -> V_4 ,
( V_181 ) V_8 , V_14 ) ;
if ( V_41 < 0 )
goto V_47;
F_114 ( & V_133 ) ;
while ( ( V_131 = F_115 ( V_3 -> V_45 , & V_133 ) ) ) {
struct V_1 * V_145 ;
struct V_19 * V_129 ;
V_145 = F_116 ( V_131 -> V_137 ) ;
if ( ( V_145 -> V_66 & V_182 ) &&
V_145 -> V_183 + ( V_184 ) V_145 -> V_28 + V_121 >
V_145 -> V_67 ) {
V_41 = - V_185 ;
goto V_47;
}
if ( ( V_145 -> V_66 & V_186 ) &&
V_145 -> V_183 + ( V_184 ) V_145 -> V_29 + V_121 >
V_145 -> V_68 ) {
V_41 = - V_185 ;
goto V_47;
}
F_19 (glist, &qg->groups, next_group) {
V_41 = F_112 ( V_3 -> V_45 ,
V_129 -> V_27 -> V_4 ,
( V_181 ) V_129 -> V_27 , V_14 ) ;
if ( V_41 < 0 )
goto V_47;
}
}
V_41 = 0 ;
F_114 ( & V_133 ) ;
while ( ( V_131 = F_115 ( V_3 -> V_45 , & V_133 ) ) ) {
struct V_1 * V_145 ;
V_145 = F_116 ( V_131 -> V_137 ) ;
V_145 -> V_183 += V_121 ;
}
V_47:
F_86 ( & V_3 -> V_98 ) ;
return V_41 ;
}
void F_141 ( struct V_34 * V_86 , T_1 V_121 )
{
struct V_34 * V_35 ;
struct V_1 * V_8 ;
struct V_2 * V_3 = V_86 -> V_3 ;
struct V_130 * V_131 ;
struct V_132 V_133 ;
T_1 V_115 = V_86 -> V_100 . V_49 ;
int V_41 = 0 ;
if ( ! F_106 ( V_115 ) )
return;
if ( V_121 == 0 )
return;
F_85 ( & V_3 -> V_98 ) ;
V_35 = V_3 -> V_35 ;
if ( ! V_35 )
goto V_47;
V_8 = F_1 ( V_3 , V_115 ) ;
if ( ! V_8 )
goto V_47;
F_118 ( V_3 -> V_45 ) ;
V_41 = F_112 ( V_3 -> V_45 , V_8 -> V_4 ,
( V_181 ) V_8 , V_14 ) ;
if ( V_41 < 0 )
goto V_47;
F_114 ( & V_133 ) ;
while ( ( V_131 = F_115 ( V_3 -> V_45 , & V_133 ) ) ) {
struct V_1 * V_145 ;
struct V_19 * V_129 ;
V_145 = F_116 ( V_131 -> V_137 ) ;
V_145 -> V_183 -= V_121 ;
F_19 (glist, &qg->groups, next_group) {
V_41 = F_112 ( V_3 -> V_45 ,
V_129 -> V_27 -> V_4 ,
( V_181 ) V_129 -> V_27 , V_14 ) ;
if ( V_41 < 0 )
goto V_47;
}
}
V_47:
F_86 ( & V_3 -> V_98 ) ;
}
void F_142 ( struct V_76 * V_77 )
{
if ( F_11 ( & V_77 -> V_126 ) && ! V_77 -> V_187 . V_114 )
return;
F_28 ( V_77 -> V_86 -> V_3 ,
L_7
L_8 ,
V_77 , F_11 ( & V_77 -> V_126 ) ? L_9 : L_10 ,
( T_2 ) ( V_77 -> V_187 . V_114 >> 32 ) ,
( T_2 ) V_77 -> V_187 . V_114 ) ;
F_143 () ;
}
static int
F_144 ( struct V_2 * V_3 , struct V_36 * V_37 ,
struct V_76 * V_77 , struct V_127 * V_140 ,
struct V_127 * V_128 , struct V_38 * V_188 )
{
struct V_31 V_189 ;
struct V_127 * V_139 = NULL ;
struct V_156 V_190 = {} ;
T_1 V_121 ;
T_1 V_114 ;
int V_153 ;
int V_40 ;
int V_41 ;
V_37 -> V_89 = 1 ;
F_82 ( & V_3 -> V_158 ) ;
V_41 = F_24 ( V_3 -> V_191 ,
& V_3 -> V_87 ,
V_37 , 1 , 0 ) ;
F_145 ( L_11 ,
V_3 -> V_87 . V_49 ,
V_3 -> V_87 . type ,
V_3 -> V_87 . V_50 , V_41 ) ;
if ( V_41 ) {
V_3 -> V_87 . V_49 = ( T_1 ) - 1 ;
F_44 ( V_37 ) ;
F_88 ( & V_3 -> V_158 ) ;
return V_41 ;
}
F_25 ( V_37 -> V_52 [ 0 ] , & V_189 ,
F_79 ( V_37 -> V_52 [ 0 ] ) - 1 ) ;
V_3 -> V_87 . V_49 = V_189 . V_49 + 1 ;
F_109 ( V_3 , & V_190 ) ;
memcpy ( V_188 , V_37 -> V_52 [ 0 ] , sizeof( * V_188 ) ) ;
V_40 = V_37 -> V_51 [ 0 ] ;
F_44 ( V_37 ) ;
F_88 ( & V_3 -> V_158 ) ;
for (; V_40 < F_79 ( V_188 ) ; ++ V_40 ) {
F_25 ( V_188 , & V_189 , V_40 ) ;
if ( V_189 . type != V_192 &&
V_189 . type != V_193 )
continue;
if ( V_189 . type == V_193 )
V_121 = V_3 -> V_191 -> V_194 ;
else
V_121 = V_189 . V_50 ;
F_118 ( V_140 ) ;
V_41 = F_124 ( NULL , V_3 , V_189 . V_49 , 0 ,
& V_139 ) ;
if ( V_41 < 0 )
goto V_47;
F_85 ( & V_3 -> V_98 ) ;
V_114 = V_3 -> V_157 ;
V_3 -> V_157 += V_139 -> V_195 + 1 ;
V_153 = 0 ;
V_41 = F_117 ( V_3 , 0 , V_128 , V_139 , V_140 ,
V_114 , & V_153 , 1 ) ;
if ( V_41 < 0 ) {
F_86 ( & V_3 -> V_98 ) ;
F_48 ( V_139 ) ;
goto V_47;
}
V_41 = F_122 ( V_3 , 0 , V_121 , V_140 ,
V_114 , 0 , V_153 , 1 ) ;
if ( V_41 < 0 ) {
F_86 ( & V_3 -> V_98 ) ;
F_48 ( V_139 ) ;
goto V_47;
}
F_86 ( & V_3 -> V_98 ) ;
F_48 ( V_139 ) ;
}
V_47:
F_125 ( V_3 , & V_190 ) ;
return V_41 ;
}
static void F_146 ( struct V_196 * V_197 )
{
struct V_2 * V_3 = F_147 ( V_197 , struct V_2 ,
V_162 ) ;
struct V_36 * V_37 ;
struct V_76 * V_77 = NULL ;
struct V_127 * V_128 = NULL , * V_140 = NULL ;
struct V_38 * V_188 = NULL ;
int V_104 = - V_15 ;
V_37 = F_23 () ;
if ( ! V_37 )
goto V_47;
V_140 = F_22 ( V_46 ) ;
if ( ! V_140 )
goto V_47;
V_128 = F_22 ( V_46 ) ;
if ( ! V_128 )
goto V_47;
V_188 = F_107 ( sizeof( * V_188 ) , V_46 ) ;
if ( ! V_188 )
goto V_47;
V_104 = 0 ;
while ( ! V_104 ) {
V_77 = F_148 ( V_3 -> V_198 , 0 ) ;
if ( F_32 ( V_77 ) ) {
V_104 = F_33 ( V_77 ) ;
break;
}
if ( ! V_3 -> V_44 ) {
V_104 = - V_199 ;
} else {
V_104 = F_144 ( V_3 , V_37 , V_77 ,
V_140 , V_128 , V_188 ) ;
}
if ( V_104 > 0 )
F_149 ( V_77 , V_3 -> V_198 ) ;
else
F_150 ( V_77 , V_3 -> V_198 ) ;
}
V_47:
F_13 ( V_188 ) ;
F_48 ( V_140 ) ;
F_48 ( V_128 ) ;
F_47 ( V_37 ) ;
F_82 ( & V_3 -> V_158 ) ;
V_3 -> V_48 &= ~ V_75 ;
if ( V_104 == 2 &&
V_3 -> V_48 & V_58 ) {
V_3 -> V_48 &= ~ V_58 ;
} else if ( V_104 < 0 ) {
V_3 -> V_48 |= V_58 ;
}
F_88 ( & V_3 -> V_158 ) ;
if ( V_104 >= 0 ) {
F_102 ( V_3 , L_12 ,
V_104 == 2 ? L_13 : L_9 ) ;
} else {
F_28 ( V_3 , L_14 , V_104 ) ;
}
F_151 ( & V_3 -> V_200 ) ;
}
static int
F_46 ( struct V_2 * V_3 , T_1 V_201 ,
int V_202 )
{
int V_41 = 0 ;
if ( ! V_202 &&
( ! ( V_3 -> V_48 & V_75 ) ||
! ( V_3 -> V_48 & V_73 ) ) ) {
V_41 = - V_30 ;
goto V_104;
}
F_82 ( & V_3 -> V_158 ) ;
F_85 ( & V_3 -> V_98 ) ;
if ( V_202 ) {
if ( V_3 -> V_48 & V_75 )
V_41 = - V_203 ;
else if ( ! ( V_3 -> V_48 & V_73 ) )
V_41 = - V_30 ;
if ( V_41 ) {
F_86 ( & V_3 -> V_98 ) ;
F_88 ( & V_3 -> V_158 ) ;
goto V_104;
}
V_3 -> V_48 |= V_75 ;
}
memset ( & V_3 -> V_87 , 0 ,
sizeof( V_3 -> V_87 ) ) ;
V_3 -> V_87 . V_49 = V_201 ;
F_86 ( & V_3 -> V_98 ) ;
F_88 ( & V_3 -> V_158 ) ;
F_152 ( & V_3 -> V_200 ) ;
memset ( & V_3 -> V_162 , 0 ,
sizeof( V_3 -> V_162 ) ) ;
F_153 ( & V_3 -> V_162 ,
F_146 , NULL , NULL ) ;
if ( V_41 ) {
V_104:
F_102 ( V_3 , L_15 , V_41 ) ;
return V_41 ;
}
return 0 ;
}
static void
F_132 ( struct V_2 * V_3 )
{
struct V_5 * V_6 ;
struct V_1 * V_8 ;
F_85 ( & V_3 -> V_98 ) ;
for ( V_6 = F_50 ( & V_3 -> V_7 ) ; V_6 ; V_6 = F_120 ( V_6 ) ) {
V_8 = F_2 ( V_6 , struct V_1 , V_9 ) ;
V_8 -> V_28 = 0 ;
V_8 -> V_63 = 0 ;
V_8 -> V_29 = 0 ;
V_8 -> V_64 = 0 ;
}
F_86 ( & V_3 -> V_98 ) ;
}
int
F_154 ( struct V_2 * V_3 )
{
int V_41 = 0 ;
struct V_76 * V_77 ;
V_41 = F_46 ( V_3 , 0 , 1 ) ;
if ( V_41 )
return V_41 ;
V_77 = F_155 ( V_3 -> V_198 ) ;
if ( F_32 ( V_77 ) ) {
V_3 -> V_48 &= ~ V_75 ;
return F_33 ( V_77 ) ;
}
V_41 = F_149 ( V_77 , V_3 -> V_198 ) ;
if ( V_41 ) {
V_3 -> V_48 &= ~ V_75 ;
return V_41 ;
}
F_132 ( V_3 ) ;
F_133 ( V_3 -> V_161 ,
& V_3 -> V_162 ) ;
return 0 ;
}
int F_156 ( struct V_2 * V_3 )
{
int V_204 ;
int V_41 = 0 ;
F_82 ( & V_3 -> V_158 ) ;
F_85 ( & V_3 -> V_98 ) ;
V_204 = V_3 -> V_48 & V_75 ;
F_86 ( & V_3 -> V_98 ) ;
F_88 ( & V_3 -> V_158 ) ;
if ( V_204 )
V_41 = F_157 (
& V_3 -> V_200 ) ;
return V_41 ;
}
void
F_158 ( struct V_2 * V_3 )
{
if ( V_3 -> V_48 & V_75 )
F_133 ( V_3 -> V_161 ,
& V_3 -> V_162 ) ;
}
