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
return 1 ;
return 0 ;
}
static int F_104 ( struct V_2 * V_3 ,
struct V_110 * V_115 )
{
struct V_5 * V_6 ;
struct V_110 * V_116 ;
int V_117 ;
F_85 ( & V_3 -> V_118 ) ;
V_6 = V_3 -> V_119 . V_5 ;
while ( V_6 ) {
V_116 = F_2 ( V_6 , struct V_110 , V_6 ) ;
V_117 = F_103 ( V_116 , V_115 ) ;
if ( V_117 < 0 ) {
V_6 = V_6 -> V_11 ;
} else if ( V_117 ) {
V_6 = V_6 -> V_10 ;
} else {
F_86 ( & V_3 -> V_118 ) ;
return - V_103 ;
}
}
F_86 ( & V_3 -> V_118 ) ;
return 0 ;
}
static int F_105 ( struct V_110 * V_111 ,
struct V_110 * V_112 )
{
if ( V_111 -> V_113 < V_112 -> V_113 )
return - 1 ;
if ( V_111 -> V_113 > V_112 -> V_113 )
return 1 ;
if ( V_111 -> V_120 < V_112 -> V_120 )
return - 1 ;
if ( V_111 -> V_120 > V_112 -> V_120 )
return - 1 ;
if ( V_111 -> V_114 < V_112 -> V_114 )
return - 1 ;
if ( V_111 -> V_114 > V_112 -> V_114 )
return 1 ;
if ( V_111 -> type < V_112 -> type )
return - 1 ;
if ( V_111 -> type > V_112 -> type )
return 1 ;
return 0 ;
}
static int F_106 ( struct V_2 * V_3 ,
struct V_110 * V_115 )
{
struct V_5 * * V_12 ;
struct V_5 * V_13 = NULL ;
struct V_110 * V_116 ;
int V_117 ;
F_85 ( & V_3 -> V_118 ) ;
V_12 = & V_3 -> V_119 . V_5 ;
while ( * V_12 ) {
V_13 = * V_12 ;
V_116 = F_2 ( V_13 , struct V_110 , V_6 ) ;
V_117 = F_105 ( V_116 , V_115 ) ;
if ( V_117 < 0 ) {
V_12 = & ( * V_12 ) -> V_11 ;
} else if ( V_117 ) {
V_12 = & ( * V_12 ) -> V_10 ;
} else {
F_86 ( & V_3 -> V_118 ) ;
return - V_103 ;
}
}
F_7 ( & V_115 -> V_6 , V_13 , V_12 ) ;
F_8 ( & V_115 -> V_6 , & V_3 -> V_119 ) ;
F_86 ( & V_3 -> V_118 ) ;
return 0 ;
}
int F_107 ( struct V_76 * V_77 ,
struct V_2 * V_3 , T_1 V_114 ,
T_1 V_113 , T_1 V_121 ,
enum V_122 type , int V_123 )
{
struct V_110 * V_115 ;
int V_41 ;
if ( ! F_108 ( V_114 ) || ! V_3 -> V_44 )
return 0 ;
V_115 = F_109 ( sizeof( * V_115 ) , V_46 ) ;
if ( ! V_115 )
return - V_15 ;
V_115 -> V_114 = V_114 ;
V_115 -> V_113 = V_113 ;
V_115 -> V_121 = V_121 ;
V_115 -> type = type ;
V_115 -> V_120 = F_110 ( & V_3 -> V_124 ) ;
F_6 ( & V_115 -> V_125 . V_20 ) ;
V_115 -> V_125 . V_120 = 0 ;
if ( type == V_126 ) {
if ( F_104 ( V_3 , V_115 ) ) {
F_13 ( V_115 ) ;
return 0 ;
}
}
V_41 = F_106 ( V_3 , V_115 ) ;
if ( V_41 ) {
ASSERT ( 0 ) ;
F_13 ( V_115 ) ;
return V_41 ;
}
F_17 ( & V_115 -> V_20 , & V_77 -> V_127 ) ;
if ( V_123 )
F_111 ( V_3 , & V_115 -> V_125 ) ;
return 0 ;
}
static int F_112 ( struct V_2 * V_3 ,
struct V_110 * V_115 )
{
struct V_1 * V_8 ;
struct V_128 * V_129 ;
struct V_19 * V_130 ;
struct V_131 * V_132 ;
struct V_133 V_134 ;
int V_135 = 0 ;
int V_41 = 0 ;
V_129 = F_22 ( V_46 ) ;
if ( ! V_129 )
return - V_15 ;
F_85 ( & V_3 -> V_98 ) ;
if ( ! V_3 -> V_35 )
goto V_47;
V_8 = F_1 ( V_3 , V_115 -> V_114 ) ;
if ( ! V_8 )
goto V_47;
switch ( V_115 -> type ) {
case V_136 :
V_135 = 1 ;
break;
case V_137 :
V_135 = - 1 ;
break;
default:
ASSERT ( 0 ) ;
}
V_8 -> V_28 += V_135 * V_115 -> V_121 ;
V_8 -> V_63 += V_135 * V_115 -> V_121 ;
F_113 ( V_135 < 0 && V_8 -> V_29 < V_115 -> V_121 ) ;
V_8 -> V_29 += V_135 * V_115 -> V_121 ;
V_8 -> V_64 += V_135 * V_115 -> V_121 ;
F_95 ( V_3 , V_8 ) ;
F_19 (glist, &qgroup->groups, next_group) {
V_41 = F_114 ( V_129 , V_130 -> V_27 -> V_4 ,
F_115 ( V_130 -> V_27 ) , V_14 ) ;
if ( V_41 < 0 )
goto V_47;
}
F_116 ( & V_134 ) ;
while ( ( V_132 = F_117 ( V_129 , & V_134 ) ) ) {
V_8 = F_118 ( V_132 -> V_138 ) ;
V_8 -> V_28 += V_135 * V_115 -> V_121 ;
V_8 -> V_63 += V_135 * V_115 -> V_121 ;
V_8 -> V_29 += V_135 * V_115 -> V_121 ;
if ( V_135 < 0 )
F_113 ( V_8 -> V_29 < V_115 -> V_121 ) ;
V_8 -> V_64 += V_135 * V_115 -> V_121 ;
F_95 ( V_3 , V_8 ) ;
F_19 (glist, &qgroup->groups, next_group) {
V_41 = F_114 ( V_129 , V_130 -> V_27 -> V_4 ,
F_115 ( V_130 -> V_27 ) , V_14 ) ;
if ( V_41 < 0 )
goto V_47;
}
}
V_41 = 0 ;
V_47:
F_86 ( & V_3 -> V_98 ) ;
F_48 ( V_129 ) ;
return V_41 ;
}
static int F_119 ( struct V_2 * V_3 ,
T_1 V_139 , struct V_128 * V_129 ,
struct V_128 * V_140 , struct V_128 * V_141 ,
T_1 V_120 , int * V_142 , int V_143 )
{
struct V_131 * V_132 ;
struct V_133 V_134 ;
struct V_131 * V_144 ;
struct V_133 V_145 ;
struct V_1 * V_146 ;
int V_41 ;
F_116 ( & V_134 ) ;
while ( ( V_132 = F_117 ( V_140 , & V_134 ) ) ) {
if ( V_132 -> V_147 == V_139 )
continue;
V_146 = F_1 ( V_3 , V_132 -> V_147 ) ;
if ( ! V_146 )
continue;
( * V_142 ) ++ ;
F_120 ( V_129 ) ;
V_41 = F_114 ( V_141 , V_146 -> V_4 , F_115 ( V_146 ) ,
V_14 ) ;
if ( V_41 < 0 )
return V_41 ;
V_41 = F_114 ( V_129 , V_146 -> V_4 , F_115 ( V_146 ) , V_14 ) ;
if ( V_41 < 0 )
return V_41 ;
F_116 ( & V_145 ) ;
while ( ( V_144 = F_117 ( V_129 , & V_145 ) ) ) {
struct V_19 * V_130 ;
V_146 = F_118 ( V_144 -> V_138 ) ;
if ( V_143 )
V_146 -> V_148 = V_120 ;
else if ( V_146 -> V_148 < V_120 )
V_146 -> V_148 = V_120 + 1 ;
else
V_146 -> V_148 ++ ;
if ( V_146 -> V_149 < V_120 )
V_146 -> V_149 = V_120 + 1 ;
else
V_146 -> V_149 ++ ;
F_19 (glist, &qg->groups, next_group) {
V_41 = F_114 ( V_141 , V_130 -> V_27 -> V_4 ,
F_115 ( V_130 -> V_27 ) ,
V_14 ) ;
if ( V_41 < 0 )
return V_41 ;
V_41 = F_114 ( V_129 , V_130 -> V_27 -> V_4 ,
F_115 ( V_130 -> V_27 ) ,
V_14 ) ;
if ( V_41 < 0 )
return V_41 ;
}
}
}
return 0 ;
}
static int F_121 ( struct V_2 * V_3 ,
struct V_110 * V_115 ,
struct V_128 * V_129 ,
struct V_128 * V_141 , T_1 V_120 ,
int * V_142 )
{
struct V_131 * V_132 ;
struct V_133 V_134 ;
struct V_1 * V_146 ;
struct V_110 * V_150 ;
struct V_5 * V_6 ;
int V_41 ;
F_120 ( V_129 ) ;
F_85 ( & V_3 -> V_118 ) ;
V_6 = F_122 ( & V_115 -> V_6 ) ;
F_86 ( & V_3 -> V_118 ) ;
if ( ! V_6 )
return 0 ;
V_150 = F_2 ( V_6 , struct V_110 , V_6 ) ;
while ( V_150 -> V_113 == V_115 -> V_113 ) {
if ( V_150 -> type != V_151 &&
V_150 -> type != V_137 )
goto V_152;
V_146 = F_1 ( V_3 , V_150 -> V_114 ) ;
if ( ! V_146 )
goto V_152;
V_41 = F_114 ( V_141 , V_146 -> V_4 , F_115 ( V_146 ) ,
V_14 ) ;
if ( V_41 ) {
if ( V_41 < 0 )
return V_41 ;
( * V_142 ) ++ ;
V_41 = F_114 ( V_129 , V_146 -> V_4 , F_115 ( V_146 ) ,
V_14 ) ;
if ( V_41 < 0 )
return V_41 ;
}
V_152:
F_85 ( & V_3 -> V_118 ) ;
V_6 = F_122 ( & V_150 -> V_6 ) ;
F_86 ( & V_3 -> V_118 ) ;
if ( ! V_6 )
break;
V_150 = F_2 ( V_6 , struct V_110 , V_6 ) ;
}
F_116 ( & V_134 ) ;
while ( ( V_132 = F_117 ( V_129 , & V_134 ) ) ) {
struct V_19 * V_130 ;
V_146 = F_118 ( V_132 -> V_138 ) ;
if ( V_146 -> V_148 < V_120 )
V_146 -> V_148 = V_120 + 1 ;
else
V_146 -> V_148 ++ ;
if ( V_146 -> V_149 < V_120 )
V_146 -> V_149 = V_120 + 1 ;
else
V_146 -> V_149 ++ ;
F_19 (glist, &qg->groups, next_group) {
V_41 = F_114 ( V_141 , V_130 -> V_27 -> V_4 ,
F_115 ( V_130 -> V_27 ) , V_14 ) ;
if ( V_41 < 0 )
return V_41 ;
V_41 = F_114 ( V_129 , V_130 -> V_27 -> V_4 ,
F_115 ( V_130 -> V_27 ) , V_14 ) ;
if ( V_41 < 0 )
return V_41 ;
}
}
return 0 ;
}
static int F_123 ( struct V_2 * V_3 ,
struct V_110 * V_115 ,
struct V_1 * V_8 ,
struct V_128 * V_129 , struct V_128 * V_141 ,
T_1 V_120 )
{
struct V_131 * V_132 ;
struct V_133 V_134 ;
struct V_1 * V_146 ;
int V_41 ;
F_120 ( V_129 ) ;
V_41 = F_114 ( V_141 , V_8 -> V_4 , F_115 ( V_8 ) ,
V_14 ) ;
if ( V_41 < 0 )
return V_41 ;
V_41 = F_114 ( V_129 , V_8 -> V_4 , F_115 ( V_8 ) ,
V_14 ) ;
if ( V_41 < 0 )
return V_41 ;
F_116 ( & V_134 ) ;
while ( ( V_132 = F_117 ( V_129 , & V_134 ) ) ) {
struct V_19 * V_130 ;
V_146 = F_118 ( V_132 -> V_138 ) ;
if ( V_115 -> type == V_153 ) {
if ( V_146 -> V_149 < V_120 )
V_146 -> V_149 = V_120 + 1 ;
else
V_146 -> V_149 ++ ;
} else {
if ( V_146 -> V_148 < V_120 )
V_146 -> V_148 = V_120 + 1 ;
else
V_146 -> V_148 ++ ;
}
F_19 (glist, &qg->groups, next_group) {
V_41 = F_114 ( V_129 , V_130 -> V_27 -> V_4 ,
F_115 ( V_130 -> V_27 ) , V_14 ) ;
if ( V_41 < 0 )
return V_41 ;
V_41 = F_114 ( V_141 , V_130 -> V_27 -> V_4 ,
F_115 ( V_130 -> V_27 ) , V_14 ) ;
if ( V_41 < 0 )
return V_41 ;
}
}
return 0 ;
}
static int F_124 ( struct V_2 * V_3 ,
T_1 V_139 , T_1 V_121 ,
struct V_128 * V_141 , T_1 V_120 ,
int V_142 , int V_154 , int V_143 )
{
struct V_131 * V_132 ;
struct V_133 V_134 ;
struct V_1 * V_146 ;
T_1 V_155 , V_156 ;
F_116 ( & V_134 ) ;
while ( ( V_132 = F_117 ( V_141 , & V_134 ) ) ) {
bool V_18 = false ;
V_146 = F_118 ( V_132 -> V_138 ) ;
if ( V_146 -> V_148 <= V_120 && V_146 -> V_149 > V_120 ) {
V_146 -> V_28 += V_121 ;
V_146 -> V_63 += V_121 ;
V_18 = true ;
}
if ( V_146 -> V_148 > V_120 && V_146 -> V_149 <= V_120 ) {
V_146 -> V_28 -= V_121 ;
V_146 -> V_63 -= V_121 ;
V_18 = true ;
}
if ( V_146 -> V_148 < V_120 )
V_156 = 0 ;
else
V_156 = V_146 -> V_148 - V_120 ;
if ( V_146 -> V_149 < V_120 )
V_155 = 0 ;
else
V_155 = V_146 -> V_149 - V_120 ;
if ( V_142 && V_156 == V_142 &&
( V_155 != V_154 || V_154 == 0 ) ) {
F_113 ( V_155 != V_154 && V_154 == 0 ) ;
V_146 -> V_29 -= V_121 ;
V_146 -> V_64 -= V_121 ;
V_18 = true ;
}
if ( ( ! V_142 || ( V_142 && V_156 != V_142 ) )
&& V_155 == V_154 ) {
V_146 -> V_29 += V_121 ;
V_146 -> V_64 += V_121 ;
V_18 = true ;
}
if ( V_18 )
F_95 ( V_3 , V_146 ) ;
}
return 0 ;
}
static int F_125 ( struct V_76 * V_77 ,
struct V_2 * V_3 ,
struct V_110 * V_115 )
{
struct V_128 * V_140 = NULL ;
struct V_131 * V_132 ;
struct V_133 V_134 ;
int V_41 = 0 ;
V_41 = F_126 ( V_77 , V_3 , V_115 -> V_113 ,
V_115 -> V_125 . V_120 , & V_140 ) ;
if ( V_41 < 0 )
return V_41 ;
V_41 = 0 ;
F_116 ( & V_134 ) ;
while ( ( V_132 = F_117 ( V_140 , & V_134 ) ) ) {
if ( V_132 -> V_147 == V_115 -> V_114 ) {
V_41 = 1 ;
break;
}
}
F_48 ( V_140 ) ;
F_127 ( V_3 , & V_115 -> V_125 ) ;
return V_41 ;
}
static int F_128 ( struct V_76 * V_77 ,
struct V_2 * V_3 ,
struct V_110 * V_115 )
{
struct V_128 * V_140 = NULL ;
struct V_128 * V_141 , * V_129 ;
struct V_1 * V_8 ;
struct V_157 V_125 = {} ;
T_1 V_120 ;
int V_142 = 0 ;
int V_154 = 0 ;
int V_41 = 0 ;
if ( V_115 -> V_125 . V_120 ) {
V_41 = F_125 ( V_77 , V_3 , V_115 ) ;
if ( V_41 < 0 )
return V_41 ;
if ( V_41 )
return 0 ;
}
V_141 = F_22 ( V_46 ) ;
if ( ! V_141 )
return - V_15 ;
V_129 = F_22 ( V_46 ) ;
if ( ! V_129 ) {
F_48 ( V_141 ) ;
return - V_15 ;
}
F_111 ( V_3 , & V_125 ) ;
V_41 = F_126 ( V_77 , V_3 , V_115 -> V_113 , V_125 . V_120 ,
& V_140 ) ;
F_127 ( V_3 , & V_125 ) ;
if ( V_41 < 0 ) {
F_48 ( V_141 ) ;
F_48 ( V_129 ) ;
return V_41 ;
}
F_85 ( & V_3 -> V_98 ) ;
V_8 = F_1 ( V_3 , V_115 -> V_114 ) ;
if ( ! V_8 )
goto V_47;
V_120 = V_3 -> V_158 ;
V_41 = F_119 ( V_3 , V_115 -> V_114 , V_129 , V_140 , V_141 ,
V_120 , & V_142 , 0 ) ;
if ( V_41 < 0 )
goto V_47;
V_41 = F_123 ( V_3 , V_115 , V_8 , V_129 , V_141 ,
V_120 ) ;
if ( V_41 < 0 )
goto V_47;
V_41 = F_121 ( V_3 , V_115 , V_129 , V_141 , V_120 ,
& V_142 ) ;
if ( V_41 < 0 )
goto V_47;
if ( V_115 -> type == V_153 ) {
V_154 = V_142 + 1 ;
} else {
V_154 = V_142 ;
V_142 ++ ;
}
V_3 -> V_158 += V_142 + 1 ;
F_124 ( V_3 , V_115 -> V_114 , V_115 -> V_121 ,
V_141 , V_120 , V_142 , V_154 , 0 ) ;
V_47:
F_86 ( & V_3 -> V_98 ) ;
F_48 ( V_141 ) ;
F_48 ( V_140 ) ;
F_48 ( V_129 ) ;
return V_41 ;
}
static int F_129 ( struct V_76 * V_77 ,
struct V_2 * V_3 ,
struct V_110 * V_115 )
{
struct V_128 * V_140 = NULL ;
struct V_131 * V_132 ;
struct V_133 V_134 ;
struct V_19 * V_130 ;
struct V_128 * V_159 ;
int V_41 = 0 ;
int V_104 ;
struct V_1 * V_146 ;
T_1 V_160 = 0 ;
struct V_157 V_125 = {} ;
V_159 = F_22 ( V_46 ) ;
if ( ! V_159 )
return - V_15 ;
F_111 ( V_3 , & V_125 ) ;
V_41 = F_126 ( V_77 , V_3 , V_115 -> V_113 ,
V_125 . V_120 , & V_140 ) ;
F_127 ( V_3 , & V_125 ) ;
if ( V_41 < 0 )
goto V_47;
if ( V_140 -> V_161 != 1 )
goto V_47;
F_116 ( & V_134 ) ;
V_132 = F_117 ( V_140 , & V_134 ) ;
if ( V_132 -> V_147 == V_115 -> V_114 )
goto V_47;
V_160 = V_132 -> V_147 ;
F_130 ( ! V_160 ) ;
F_85 ( & V_3 -> V_98 ) ;
V_146 = F_1 ( V_3 , V_160 ) ;
if ( ! V_146 )
goto V_162;
V_146 -> V_29 += V_115 -> V_121 ;
V_146 -> V_64 += V_115 -> V_121 ;
F_95 ( V_3 , V_146 ) ;
F_19 (glist, &qg->groups, next_group) {
V_104 = F_114 ( V_159 , V_130 -> V_27 -> V_4 ,
F_115 ( V_130 -> V_27 ) , V_14 ) ;
if ( V_104 < 0 ) {
V_41 = V_104 ;
goto V_162;
}
}
F_116 ( & V_134 ) ;
while ( ( V_132 = F_117 ( V_159 , & V_134 ) ) ) {
V_146 = F_118 ( V_132 -> V_138 ) ;
V_146 -> V_29 += V_115 -> V_121 ;
V_146 -> V_64 += V_115 -> V_121 ;
F_95 ( V_3 , V_146 ) ;
F_19 (glist, &qg->groups, next_group) {
V_104 = F_114 ( V_159 , V_130 -> V_27 -> V_4 ,
F_115 ( V_130 -> V_27 ) , V_14 ) ;
if ( V_104 < 0 ) {
V_41 = V_104 ;
goto V_162;
}
}
}
V_162:
F_86 ( & V_3 -> V_98 ) ;
V_47:
F_48 ( V_140 ) ;
F_48 ( V_159 ) ;
return V_41 ;
}
static int F_131 ( struct V_76 * V_77 ,
struct V_2 * V_3 ,
struct V_110 * V_115 )
{
int V_41 = 0 ;
if ( ! V_3 -> V_44 )
return 0 ;
F_130 ( ! V_3 -> V_35 ) ;
F_82 ( & V_3 -> V_163 ) ;
if ( V_3 -> V_48 & V_75 ) {
if ( V_3 -> V_87 . V_49 <= V_115 -> V_113 ) {
F_88 ( & V_3 -> V_163 ) ;
return 0 ;
}
}
F_88 ( & V_3 -> V_163 ) ;
ASSERT ( F_108 ( V_115 -> V_114 ) ) ;
switch ( V_115 -> type ) {
case V_136 :
case V_137 :
V_41 = F_112 ( V_3 , V_115 ) ;
break;
case V_153 :
case V_151 :
V_41 = F_128 ( V_77 , V_3 , V_115 ) ;
break;
case V_126 :
V_41 = F_129 ( V_77 , V_3 , V_115 ) ;
break;
default:
ASSERT ( 0 ) ;
}
return V_41 ;
}
int F_132 ( struct V_76 * V_77 ,
struct V_2 * V_3 )
{
struct V_110 * V_115 ;
int V_41 = 0 ;
while ( ! F_11 ( & V_77 -> V_127 ) ) {
V_115 = F_12 ( & V_77 -> V_127 ,
struct V_110 , V_20 ) ;
F_133 ( & V_115 -> V_20 ) ;
if ( ! V_41 || ! V_77 -> V_164 )
V_41 = F_131 ( V_77 , V_3 , V_115 ) ;
F_85 ( & V_3 -> V_118 ) ;
F_15 ( & V_115 -> V_6 , & V_3 -> V_119 ) ;
F_86 ( & V_3 -> V_118 ) ;
F_127 ( V_3 , & V_115 -> V_125 ) ;
F_13 ( V_115 ) ;
}
return V_41 ;
}
int F_134 ( struct V_76 * V_77 ,
struct V_2 * V_3 )
{
struct V_34 * V_35 = V_3 -> V_35 ;
int V_41 = 0 ;
int V_165 = 0 ;
if ( ! V_35 )
goto V_47;
if ( ! V_3 -> V_44 && V_3 -> V_74 )
V_165 = 1 ;
V_3 -> V_44 = V_3 -> V_74 ;
F_85 ( & V_3 -> V_98 ) ;
while ( ! F_11 ( & V_3 -> V_102 ) ) {
struct V_1 * V_8 ;
V_8 = F_12 ( & V_3 -> V_102 ,
struct V_1 , V_18 ) ;
F_133 ( & V_8 -> V_18 ) ;
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
if ( ! V_41 && V_165 ) {
V_41 = F_46 ( V_3 , 0 , 1 ) ;
if ( ! V_41 ) {
F_135 ( V_3 ) ;
F_136 ( V_3 -> V_166 ,
& V_3 -> V_167 ) ;
}
V_41 = 0 ;
}
V_47:
return V_41 ;
}
int F_137 ( struct V_76 * V_77 ,
struct V_2 * V_3 , T_1 V_168 , T_1 V_49 ,
struct F_137 * V_169 )
{
int V_41 = 0 ;
int V_170 ;
T_1 * V_171 ;
struct V_34 * V_35 = V_3 -> V_35 ;
struct V_1 * V_172 ;
struct V_1 * V_173 ;
T_2 V_174 = 0 ;
T_1 V_175 ;
F_82 ( & V_3 -> V_91 ) ;
if ( ! V_3 -> V_44 )
goto V_47;
if ( ! V_35 ) {
V_41 = - V_30 ;
goto V_47;
}
if ( V_169 ) {
V_171 = ( T_1 * ) ( V_169 + 1 ) ;
V_175 = V_169 -> V_176 + 2 * V_169 -> V_177 +
2 * V_169 -> V_178 ;
for ( V_170 = 0 ; V_170 < V_175 ; ++ V_170 ) {
V_172 = F_1 ( V_3 , * V_171 ) ;
if ( ! V_172 ) {
V_41 = - V_30 ;
goto V_47;
}
++ V_171 ;
}
}
V_41 = F_57 ( V_77 , V_35 , V_49 ) ;
if ( V_41 )
goto V_47;
if ( V_169 && V_169 -> V_42 & V_179 ) {
V_41 = F_72 ( V_77 , V_35 , V_49 ,
V_169 -> V_180 . V_42 ,
V_169 -> V_180 . V_67 ,
V_169 -> V_180 . V_68 ,
V_169 -> V_180 . V_69 ,
V_169 -> V_180 . V_70 ) ;
if ( V_41 )
goto V_47;
}
if ( V_168 ) {
struct V_34 * V_181 ;
struct V_31 V_182 ;
int V_183 ;
V_182 . V_49 = V_168 ;
V_182 . type = V_184 ;
V_182 . V_50 = ( T_1 ) - 1 ;
V_181 = F_138 ( V_3 , & V_182 ) ;
if ( F_32 ( V_181 ) ) {
V_41 = F_33 ( V_181 ) ;
goto V_47;
}
F_139 () ;
V_183 = F_140 ( V_181 -> V_9 ) ;
V_174 = F_141 ( V_181 , V_183 ) ;
F_142 () ;
}
if ( V_169 ) {
V_171 = ( T_1 * ) ( V_169 + 1 ) ;
for ( V_170 = 0 ; V_170 < V_169 -> V_176 ; ++ V_170 ) {
V_41 = F_51 ( V_77 , V_35 ,
V_49 , * V_171 ) ;
if ( V_41 )
goto V_47;
V_41 = F_51 ( V_77 , V_35 ,
* V_171 , V_49 ) ;
if ( V_41 )
goto V_47;
++ V_171 ;
}
}
F_85 ( & V_3 -> V_98 ) ;
V_173 = F_3 ( V_3 , V_49 ) ;
if ( F_32 ( V_173 ) ) {
V_41 = F_33 ( V_173 ) ;
goto V_185;
}
if ( V_168 ) {
V_172 = F_1 ( V_3 , V_168 ) ;
if ( ! V_172 )
goto V_185;
V_173 -> V_28 = V_172 -> V_28 ;
V_173 -> V_63 = V_172 -> V_63 ;
V_173 -> V_29 = V_174 ;
V_173 -> V_64 = V_174 ;
V_172 -> V_29 = V_174 ;
V_172 -> V_64 = V_174 ;
F_95 ( V_3 , V_173 ) ;
F_95 ( V_3 , V_172 ) ;
}
if ( ! V_169 )
goto V_185;
V_171 = ( T_1 * ) ( V_169 + 1 ) ;
for ( V_170 = 0 ; V_170 < V_169 -> V_176 ; ++ V_170 ) {
V_41 = F_16 ( V_35 -> V_3 , V_49 ,
* V_171 ) ;
if ( V_41 )
goto V_185;
++ V_171 ;
}
for ( V_170 = 0 ; V_170 < V_169 -> V_177 ; ++ V_170 ) {
struct V_1 * V_78 ;
struct V_1 * V_79 ;
V_78 = F_1 ( V_3 , V_171 [ 0 ] ) ;
V_79 = F_1 ( V_3 , V_171 [ 1 ] ) ;
if ( ! V_78 || ! V_79 ) {
V_41 = - V_30 ;
goto V_185;
}
V_79 -> V_28 = V_78 -> V_28 - V_174 ;
V_79 -> V_63 = V_78 -> V_63 - V_174 ;
V_171 += 2 ;
}
for ( V_170 = 0 ; V_170 < V_169 -> V_178 ; ++ V_170 ) {
struct V_1 * V_78 ;
struct V_1 * V_79 ;
V_78 = F_1 ( V_3 , V_171 [ 0 ] ) ;
V_79 = F_1 ( V_3 , V_171 [ 1 ] ) ;
if ( ! V_78 || ! V_79 ) {
V_41 = - V_30 ;
goto V_185;
}
V_79 -> V_29 = V_78 -> V_29 + V_174 ;
V_79 -> V_64 = V_78 -> V_64 + V_174 ;
V_171 += 2 ;
}
V_185:
F_86 ( & V_3 -> V_98 ) ;
V_47:
F_88 ( & V_3 -> V_91 ) ;
return V_41 ;
}
int F_143 ( struct V_34 * V_86 , T_1 V_121 )
{
struct V_34 * V_35 ;
struct V_1 * V_8 ;
struct V_2 * V_3 = V_86 -> V_3 ;
T_1 V_114 = V_86 -> V_100 . V_49 ;
int V_41 = 0 ;
struct V_131 * V_132 ;
struct V_133 V_134 ;
if ( ! F_108 ( V_114 ) )
return 0 ;
if ( V_121 == 0 )
return 0 ;
F_85 ( & V_3 -> V_98 ) ;
V_35 = V_3 -> V_35 ;
if ( ! V_35 )
goto V_47;
V_8 = F_1 ( V_3 , V_114 ) ;
if ( ! V_8 )
goto V_47;
F_120 ( V_3 -> V_45 ) ;
V_41 = F_114 ( V_3 -> V_45 , V_8 -> V_4 ,
( V_186 ) V_8 , V_14 ) ;
if ( V_41 < 0 )
goto V_47;
F_116 ( & V_134 ) ;
while ( ( V_132 = F_117 ( V_3 -> V_45 , & V_134 ) ) ) {
struct V_1 * V_146 ;
struct V_19 * V_130 ;
V_146 = F_118 ( V_132 -> V_138 ) ;
if ( ( V_146 -> V_66 & V_187 ) &&
V_146 -> V_188 + ( V_189 ) V_146 -> V_28 + V_121 >
V_146 -> V_67 ) {
V_41 = - V_190 ;
goto V_47;
}
if ( ( V_146 -> V_66 & V_191 ) &&
V_146 -> V_188 + ( V_189 ) V_146 -> V_29 + V_121 >
V_146 -> V_68 ) {
V_41 = - V_190 ;
goto V_47;
}
F_19 (glist, &qg->groups, next_group) {
V_41 = F_114 ( V_3 -> V_45 ,
V_130 -> V_27 -> V_4 ,
( V_186 ) V_130 -> V_27 , V_14 ) ;
if ( V_41 < 0 )
goto V_47;
}
}
V_41 = 0 ;
F_116 ( & V_134 ) ;
while ( ( V_132 = F_117 ( V_3 -> V_45 , & V_134 ) ) ) {
struct V_1 * V_146 ;
V_146 = F_118 ( V_132 -> V_138 ) ;
V_146 -> V_188 += V_121 ;
}
V_47:
F_86 ( & V_3 -> V_98 ) ;
return V_41 ;
}
void F_144 ( struct V_34 * V_86 , T_1 V_121 )
{
struct V_34 * V_35 ;
struct V_1 * V_8 ;
struct V_2 * V_3 = V_86 -> V_3 ;
struct V_131 * V_132 ;
struct V_133 V_134 ;
T_1 V_114 = V_86 -> V_100 . V_49 ;
int V_41 = 0 ;
if ( ! F_108 ( V_114 ) )
return;
if ( V_121 == 0 )
return;
F_85 ( & V_3 -> V_98 ) ;
V_35 = V_3 -> V_35 ;
if ( ! V_35 )
goto V_47;
V_8 = F_1 ( V_3 , V_114 ) ;
if ( ! V_8 )
goto V_47;
F_120 ( V_3 -> V_45 ) ;
V_41 = F_114 ( V_3 -> V_45 , V_8 -> V_4 ,
( V_186 ) V_8 , V_14 ) ;
if ( V_41 < 0 )
goto V_47;
F_116 ( & V_134 ) ;
while ( ( V_132 = F_117 ( V_3 -> V_45 , & V_134 ) ) ) {
struct V_1 * V_146 ;
struct V_19 * V_130 ;
V_146 = F_118 ( V_132 -> V_138 ) ;
V_146 -> V_188 -= V_121 ;
F_19 (glist, &qg->groups, next_group) {
V_41 = F_114 ( V_3 -> V_45 ,
V_130 -> V_27 -> V_4 ,
( V_186 ) V_130 -> V_27 , V_14 ) ;
if ( V_41 < 0 )
goto V_47;
}
}
V_47:
F_86 ( & V_3 -> V_98 ) ;
}
void F_145 ( struct V_76 * V_77 )
{
if ( F_11 ( & V_77 -> V_127 ) && ! V_77 -> V_192 . V_120 )
return;
F_28 ( V_77 -> V_86 -> V_3 ,
L_7
L_8 ,
V_77 , F_11 ( & V_77 -> V_127 ) ? L_9 : L_10 ,
( T_2 ) ( V_77 -> V_192 . V_120 >> 32 ) ,
( T_2 ) V_77 -> V_192 . V_120 ) ;
F_146 () ;
}
static int
F_147 ( struct V_2 * V_3 , struct V_36 * V_37 ,
struct V_76 * V_77 , struct V_128 * V_141 ,
struct V_128 * V_129 , struct V_38 * V_193 )
{
struct V_31 V_194 ;
struct V_128 * V_140 = NULL ;
struct V_157 V_195 = {} ;
T_1 V_121 ;
T_1 V_120 ;
int V_154 ;
int V_40 ;
int V_41 ;
V_37 -> V_89 = 1 ;
F_82 ( & V_3 -> V_163 ) ;
V_41 = F_24 ( V_3 -> V_196 ,
& V_3 -> V_87 ,
V_37 , 1 , 0 ) ;
F_148 ( L_11 ,
V_3 -> V_87 . V_49 ,
V_3 -> V_87 . type ,
V_3 -> V_87 . V_50 , V_41 ) ;
if ( V_41 ) {
V_3 -> V_87 . V_49 = ( T_1 ) - 1 ;
F_44 ( V_37 ) ;
F_88 ( & V_3 -> V_163 ) ;
return V_41 ;
}
F_25 ( V_37 -> V_52 [ 0 ] , & V_194 ,
F_79 ( V_37 -> V_52 [ 0 ] ) - 1 ) ;
V_3 -> V_87 . V_49 = V_194 . V_49 + 1 ;
F_111 ( V_3 , & V_195 ) ;
memcpy ( V_193 , V_37 -> V_52 [ 0 ] , sizeof( * V_193 ) ) ;
V_40 = V_37 -> V_51 [ 0 ] ;
F_44 ( V_37 ) ;
F_88 ( & V_3 -> V_163 ) ;
for (; V_40 < F_79 ( V_193 ) ; ++ V_40 ) {
F_25 ( V_193 , & V_194 , V_40 ) ;
if ( V_194 . type != V_197 &&
V_194 . type != V_198 )
continue;
if ( V_194 . type == V_198 )
V_121 = V_3 -> V_196 -> V_199 ;
else
V_121 = V_194 . V_50 ;
F_120 ( V_141 ) ;
V_41 = F_126 ( NULL , V_3 , V_194 . V_49 , 0 ,
& V_140 ) ;
if ( V_41 < 0 )
goto V_47;
F_85 ( & V_3 -> V_98 ) ;
V_120 = V_3 -> V_158 ;
V_3 -> V_158 += V_140 -> V_161 + 1 ;
V_154 = 0 ;
V_41 = F_119 ( V_3 , 0 , V_129 , V_140 , V_141 ,
V_120 , & V_154 , 1 ) ;
if ( V_41 < 0 ) {
F_86 ( & V_3 -> V_98 ) ;
F_48 ( V_140 ) ;
goto V_47;
}
V_41 = F_124 ( V_3 , 0 , V_121 , V_141 ,
V_120 , 0 , V_154 , 1 ) ;
if ( V_41 < 0 ) {
F_86 ( & V_3 -> V_98 ) ;
F_48 ( V_140 ) ;
goto V_47;
}
F_86 ( & V_3 -> V_98 ) ;
F_48 ( V_140 ) ;
}
V_47:
F_127 ( V_3 , & V_195 ) ;
return V_41 ;
}
static void F_149 ( struct V_200 * V_201 )
{
struct V_2 * V_3 = F_150 ( V_201 , struct V_2 ,
V_167 ) ;
struct V_36 * V_37 ;
struct V_76 * V_77 = NULL ;
struct V_128 * V_129 = NULL , * V_141 = NULL ;
struct V_38 * V_193 = NULL ;
int V_104 = - V_15 ;
V_37 = F_23 () ;
if ( ! V_37 )
goto V_47;
V_141 = F_22 ( V_46 ) ;
if ( ! V_141 )
goto V_47;
V_129 = F_22 ( V_46 ) ;
if ( ! V_129 )
goto V_47;
V_193 = F_109 ( sizeof( * V_193 ) , V_46 ) ;
if ( ! V_193 )
goto V_47;
V_104 = 0 ;
while ( ! V_104 ) {
V_77 = F_151 ( V_3 -> V_202 , 0 ) ;
if ( F_32 ( V_77 ) ) {
V_104 = F_33 ( V_77 ) ;
break;
}
if ( ! V_3 -> V_44 ) {
V_104 = - V_203 ;
} else {
V_104 = F_147 ( V_3 , V_37 , V_77 ,
V_141 , V_129 , V_193 ) ;
}
if ( V_104 > 0 )
F_152 ( V_77 , V_3 -> V_202 ) ;
else
F_153 ( V_77 , V_3 -> V_202 ) ;
}
V_47:
F_13 ( V_193 ) ;
F_48 ( V_141 ) ;
F_48 ( V_129 ) ;
F_47 ( V_37 ) ;
F_82 ( & V_3 -> V_163 ) ;
V_3 -> V_48 &= ~ V_75 ;
if ( V_104 == 2 &&
V_3 -> V_48 & V_58 ) {
V_3 -> V_48 &= ~ V_58 ;
} else if ( V_104 < 0 ) {
V_3 -> V_48 |= V_58 ;
}
F_88 ( & V_3 -> V_163 ) ;
if ( V_104 >= 0 ) {
F_102 ( V_3 , L_12 ,
V_104 == 2 ? L_13 : L_9 ) ;
} else {
F_28 ( V_3 , L_14 , V_104 ) ;
}
F_154 ( & V_3 -> V_204 ) ;
}
static int
F_46 ( struct V_2 * V_3 , T_1 V_205 ,
int V_206 )
{
int V_41 = 0 ;
if ( ! V_206 &&
( ! ( V_3 -> V_48 & V_75 ) ||
! ( V_3 -> V_48 & V_73 ) ) ) {
V_41 = - V_30 ;
goto V_104;
}
F_82 ( & V_3 -> V_163 ) ;
F_85 ( & V_3 -> V_98 ) ;
if ( V_206 ) {
if ( V_3 -> V_48 & V_75 )
V_41 = - V_207 ;
else if ( ! ( V_3 -> V_48 & V_73 ) )
V_41 = - V_30 ;
if ( V_41 ) {
F_86 ( & V_3 -> V_98 ) ;
F_88 ( & V_3 -> V_163 ) ;
goto V_104;
}
V_3 -> V_48 |= V_75 ;
}
memset ( & V_3 -> V_87 , 0 ,
sizeof( V_3 -> V_87 ) ) ;
V_3 -> V_87 . V_49 = V_205 ;
F_86 ( & V_3 -> V_98 ) ;
F_88 ( & V_3 -> V_163 ) ;
F_155 ( & V_3 -> V_204 ) ;
memset ( & V_3 -> V_167 , 0 ,
sizeof( V_3 -> V_167 ) ) ;
F_156 ( & V_3 -> V_167 ,
V_208 ,
F_149 , NULL , NULL ) ;
if ( V_41 ) {
V_104:
F_102 ( V_3 , L_15 , V_41 ) ;
return V_41 ;
}
return 0 ;
}
static void
F_135 ( struct V_2 * V_3 )
{
struct V_5 * V_6 ;
struct V_1 * V_8 ;
F_85 ( & V_3 -> V_98 ) ;
for ( V_6 = F_50 ( & V_3 -> V_7 ) ; V_6 ; V_6 = F_122 ( V_6 ) ) {
V_8 = F_2 ( V_6 , struct V_1 , V_9 ) ;
V_8 -> V_28 = 0 ;
V_8 -> V_63 = 0 ;
V_8 -> V_29 = 0 ;
V_8 -> V_64 = 0 ;
}
F_86 ( & V_3 -> V_98 ) ;
}
int
F_157 ( struct V_2 * V_3 )
{
int V_41 = 0 ;
struct V_76 * V_77 ;
V_41 = F_46 ( V_3 , 0 , 1 ) ;
if ( V_41 )
return V_41 ;
V_77 = F_158 ( V_3 -> V_202 ) ;
if ( F_32 ( V_77 ) ) {
V_3 -> V_48 &= ~ V_75 ;
return F_33 ( V_77 ) ;
}
V_41 = F_152 ( V_77 , V_3 -> V_202 ) ;
if ( V_41 ) {
V_3 -> V_48 &= ~ V_75 ;
return V_41 ;
}
F_135 ( V_3 ) ;
F_136 ( V_3 -> V_166 ,
& V_3 -> V_167 ) ;
return 0 ;
}
int F_159 ( struct V_2 * V_3 )
{
int V_209 ;
int V_41 = 0 ;
F_82 ( & V_3 -> V_163 ) ;
F_85 ( & V_3 -> V_98 ) ;
V_209 = V_3 -> V_48 & V_75 ;
F_86 ( & V_3 -> V_98 ) ;
F_88 ( & V_3 -> V_163 ) ;
if ( V_209 )
V_41 = F_160 (
& V_3 -> V_204 ) ;
return V_41 ;
}
void
F_161 ( struct V_2 * V_3 )
{
if ( V_3 -> V_48 & V_75 )
F_136 ( V_3 -> V_166 ,
& V_3 -> V_167 ) ;
}
