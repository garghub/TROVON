static void F_1 ( struct V_1 * V_2 , T_1 V_3 ,
int V_4 )
{
if ( V_2 -> V_5 < V_3 )
V_2 -> V_5 = V_3 ;
V_2 -> V_5 += V_4 ;
}
static void F_2 ( struct V_1 * V_2 , T_1 V_3 ,
int V_4 )
{
if ( V_2 -> V_6 < V_3 )
V_2 -> V_6 = V_3 ;
V_2 -> V_6 += V_4 ;
}
static inline T_1 F_3 ( struct V_1 * V_2 , T_1 V_3 )
{
if ( V_2 -> V_5 < V_3 )
return 0 ;
return V_2 -> V_5 - V_3 ;
}
static inline T_1 F_4 ( struct V_1 * V_2 , T_1 V_3 )
{
if ( V_2 -> V_6 < V_3 )
return 0 ;
return V_2 -> V_6 - V_3 ;
}
static struct V_1 * F_5 ( struct V_7 * V_8 ,
T_1 V_9 )
{
struct V_10 * V_11 = V_8 -> V_12 . V_10 ;
struct V_1 * V_13 ;
while ( V_11 ) {
V_13 = F_6 ( V_11 , struct V_1 , V_14 ) ;
if ( V_13 -> V_9 < V_9 )
V_11 = V_11 -> V_15 ;
else if ( V_13 -> V_9 > V_9 )
V_11 = V_11 -> V_16 ;
else
return V_13 ;
}
return NULL ;
}
static struct V_1 * F_7 ( struct V_7 * V_8 ,
T_1 V_9 )
{
struct V_10 * * V_17 = & V_8 -> V_12 . V_10 ;
struct V_10 * V_18 = NULL ;
struct V_1 * V_13 ;
while ( * V_17 ) {
V_18 = * V_17 ;
V_13 = F_6 ( V_18 , struct V_1 , V_14 ) ;
if ( V_13 -> V_9 < V_9 )
V_17 = & ( * V_17 ) -> V_15 ;
else if ( V_13 -> V_9 > V_9 )
V_17 = & ( * V_17 ) -> V_16 ;
else
return V_13 ;
}
V_13 = F_8 ( sizeof( * V_13 ) , V_19 ) ;
if ( ! V_13 )
return F_9 ( - V_20 ) ;
V_13 -> V_9 = V_9 ;
F_10 ( & V_13 -> V_21 ) ;
F_10 ( & V_13 -> V_22 ) ;
F_10 ( & V_13 -> V_23 ) ;
F_11 ( & V_13 -> V_14 , V_18 , V_17 ) ;
F_12 ( & V_13 -> V_14 , & V_8 -> V_12 ) ;
return V_13 ;
}
static void F_13 ( struct V_1 * V_13 )
{
struct V_24 * V_25 ;
F_14 ( & V_13 -> V_23 ) ;
while ( ! F_15 ( & V_13 -> V_21 ) ) {
V_25 = F_16 ( & V_13 -> V_21 ,
struct V_24 , V_26 ) ;
F_14 ( & V_25 -> V_26 ) ;
F_14 ( & V_25 -> V_27 ) ;
F_17 ( V_25 ) ;
}
while ( ! F_15 ( & V_13 -> V_22 ) ) {
V_25 = F_16 ( & V_13 -> V_22 ,
struct V_24 , V_27 ) ;
F_14 ( & V_25 -> V_26 ) ;
F_14 ( & V_25 -> V_27 ) ;
F_17 ( V_25 ) ;
}
F_17 ( V_13 ) ;
}
static int F_18 ( struct V_7 * V_8 , T_1 V_9 )
{
struct V_1 * V_13 = F_5 ( V_8 , V_9 ) ;
if ( ! V_13 )
return - V_28 ;
F_19 ( & V_13 -> V_14 , & V_8 -> V_12 ) ;
F_13 ( V_13 ) ;
return 0 ;
}
static int F_20 ( struct V_7 * V_8 ,
T_1 V_29 , T_1 V_30 )
{
struct V_1 * V_31 ;
struct V_1 * V_18 ;
struct V_24 * V_25 ;
V_31 = F_5 ( V_8 , V_29 ) ;
V_18 = F_5 ( V_8 , V_30 ) ;
if ( ! V_31 || ! V_18 )
return - V_28 ;
V_25 = F_8 ( sizeof( * V_25 ) , V_19 ) ;
if ( ! V_25 )
return - V_20 ;
V_25 -> V_32 = V_18 ;
V_25 -> V_31 = V_31 ;
F_21 ( & V_25 -> V_26 , & V_31 -> V_21 ) ;
F_21 ( & V_25 -> V_27 , & V_18 -> V_22 ) ;
return 0 ;
}
static int F_22 ( struct V_7 * V_8 ,
T_1 V_29 , T_1 V_30 )
{
struct V_1 * V_31 ;
struct V_1 * V_18 ;
struct V_24 * V_25 ;
V_31 = F_5 ( V_8 , V_29 ) ;
V_18 = F_5 ( V_8 , V_30 ) ;
if ( ! V_31 || ! V_18 )
return - V_28 ;
F_23 (list, &member->groups, next_group) {
if ( V_25 -> V_32 == V_18 ) {
F_14 ( & V_25 -> V_26 ) ;
F_14 ( & V_25 -> V_27 ) ;
F_17 ( V_25 ) ;
return 0 ;
}
}
return - V_28 ;
}
int F_24 ( struct V_7 * V_8 , T_1 V_9 ,
T_1 V_33 , T_1 V_34 )
{
struct V_1 * V_13 ;
V_13 = F_5 ( V_8 , V_9 ) ;
if ( ! V_13 )
return - V_35 ;
if ( V_13 -> V_33 != V_33 || V_13 -> V_34 != V_34 )
return - V_35 ;
return 0 ;
}
int F_25 ( struct V_7 * V_8 )
{
struct V_36 V_37 ;
struct V_36 V_38 ;
struct V_39 * V_40 = V_8 -> V_40 ;
struct V_41 * V_42 = NULL ;
struct V_43 * V_44 ;
int V_45 ;
int V_46 = 0 ;
T_1 V_47 = 0 ;
T_1 V_48 = 0 ;
if ( ! F_26 ( V_49 , & V_8 -> V_47 ) )
return 0 ;
V_8 -> V_50 = F_27 ( V_51 ) ;
if ( ! V_8 -> V_50 ) {
V_46 = - V_20 ;
goto V_52;
}
V_42 = F_28 () ;
if ( ! V_42 ) {
V_46 = - V_20 ;
goto V_52;
}
V_8 -> V_53 = 0 ;
V_37 . V_54 = 0 ;
V_37 . type = 0 ;
V_37 . V_55 = 0 ;
V_46 = F_29 ( V_40 , & V_37 , V_42 , 1 , 1 ) ;
if ( V_46 )
goto V_52;
while ( 1 ) {
struct V_1 * V_13 ;
V_45 = V_42 -> V_56 [ 0 ] ;
V_44 = V_42 -> V_57 [ 0 ] ;
F_30 ( V_44 , & V_38 , V_45 ) ;
if ( V_38 . type == V_58 ) {
struct V_59 * V_60 ;
V_60 = F_31 ( V_44 , V_45 ,
struct V_59 ) ;
if ( F_32 ( V_44 , V_60 ) !=
V_61 ) {
F_33 ( V_8 ,
L_1 ) ;
goto V_52;
}
if ( F_34 ( V_44 , V_60 ) !=
V_8 -> V_62 ) {
V_47 |= V_63 ;
F_33 ( V_8 ,
L_2 ) ;
}
V_8 -> V_53 = F_35 ( V_44 ,
V_60 ) ;
V_48 = F_36 ( V_44 , V_60 ) ;
goto V_64;
}
if ( V_38 . type != V_65 &&
V_38 . type != V_66 )
goto V_64;
V_13 = F_5 ( V_8 , V_38 . V_55 ) ;
if ( ( V_13 && V_38 . type == V_65 ) ||
( ! V_13 && V_38 . type == V_66 ) ) {
F_33 ( V_8 , L_3 ) ;
V_47 |= V_63 ;
}
if ( ! V_13 ) {
V_13 = F_7 ( V_8 , V_38 . V_55 ) ;
if ( F_37 ( V_13 ) ) {
V_46 = F_38 ( V_13 ) ;
goto V_52;
}
}
switch ( V_38 . type ) {
case V_65 : {
struct V_67 * V_60 ;
V_60 = F_31 ( V_44 , V_45 ,
struct V_67 ) ;
V_13 -> V_33 = F_39 ( V_44 , V_60 ) ;
V_13 -> V_68 = F_40 ( V_44 , V_60 ) ;
V_13 -> V_34 = F_41 ( V_44 , V_60 ) ;
V_13 -> V_69 = F_42 ( V_44 , V_60 ) ;
break;
}
case V_66 : {
struct V_70 * V_60 ;
V_60 = F_31 ( V_44 , V_45 ,
struct V_70 ) ;
V_13 -> V_71 = F_43 ( V_44 , V_60 ) ;
V_13 -> V_72 = F_44 ( V_44 , V_60 ) ;
V_13 -> V_73 = F_45 ( V_44 , V_60 ) ;
V_13 -> V_74 = F_46 ( V_44 , V_60 ) ;
V_13 -> V_75 = F_47 ( V_44 , V_60 ) ;
break;
}
}
V_64:
V_46 = F_48 ( V_40 , V_42 ) ;
if ( V_46 < 0 )
goto V_52;
if ( V_46 )
break;
}
F_49 ( V_42 ) ;
V_37 . V_54 = 0 ;
V_37 . type = V_76 ;
V_37 . V_55 = 0 ;
V_46 = F_29 ( V_40 , & V_37 , V_42 , 1 , 0 ) ;
if ( V_46 )
goto V_52;
while ( 1 ) {
V_45 = V_42 -> V_56 [ 0 ] ;
V_44 = V_42 -> V_57 [ 0 ] ;
F_30 ( V_44 , & V_38 , V_45 ) ;
if ( V_38 . type != V_76 )
goto V_77;
if ( V_38 . V_54 > V_38 . V_55 ) {
goto V_77;
}
V_46 = F_20 ( V_8 , V_38 . V_54 ,
V_38 . V_55 ) ;
if ( V_46 == - V_28 ) {
F_50 ( V_8 ,
L_4 ,
V_38 . V_54 , V_38 . V_55 ) ;
V_46 = 0 ;
}
if ( V_46 )
goto V_52;
V_77:
V_46 = F_48 ( V_40 , V_42 ) ;
if ( V_46 < 0 )
goto V_52;
if ( V_46 )
break;
}
V_52:
V_8 -> V_53 |= V_47 ;
if ( ! ( V_8 -> V_53 & V_78 ) )
F_51 ( V_49 , & V_8 -> V_47 ) ;
else if ( V_8 -> V_53 & V_79 &&
V_46 >= 0 )
V_46 = F_52 ( V_8 , V_48 , 0 ) ;
F_53 ( V_42 ) ;
if ( V_46 < 0 ) {
F_54 ( V_8 -> V_50 ) ;
V_8 -> V_50 = NULL ;
V_8 -> V_53 &= ~ V_79 ;
}
return V_46 < 0 ? V_46 : 0 ;
}
void F_55 ( struct V_7 * V_8 )
{
struct V_10 * V_11 ;
struct V_1 * V_13 ;
while ( ( V_11 = F_56 ( & V_8 -> V_12 ) ) ) {
V_13 = F_6 ( V_11 , struct V_1 , V_14 ) ;
F_19 ( V_11 , & V_8 -> V_12 ) ;
F_13 ( V_13 ) ;
}
F_54 ( V_8 -> V_50 ) ;
V_8 -> V_50 = NULL ;
}
static int F_57 ( struct V_80 * V_81 ,
struct V_39 * V_40 ,
T_1 V_82 , T_1 V_83 )
{
int V_46 ;
struct V_41 * V_42 ;
struct V_36 V_37 ;
V_42 = F_28 () ;
if ( ! V_42 )
return - V_20 ;
V_37 . V_54 = V_82 ;
V_37 . type = V_76 ;
V_37 . V_55 = V_83 ;
V_46 = F_58 ( V_81 , V_40 , V_42 , & V_37 , 0 ) ;
F_59 ( V_42 -> V_57 [ 0 ] ) ;
F_53 ( V_42 ) ;
return V_46 ;
}
static int F_60 ( struct V_80 * V_81 ,
struct V_39 * V_40 ,
T_1 V_82 , T_1 V_83 )
{
int V_46 ;
struct V_41 * V_42 ;
struct V_36 V_37 ;
V_42 = F_28 () ;
if ( ! V_42 )
return - V_20 ;
V_37 . V_54 = V_82 ;
V_37 . type = V_76 ;
V_37 . V_55 = V_83 ;
V_46 = F_61 ( V_81 , V_40 , & V_37 , V_42 , - 1 , 1 ) ;
if ( V_46 < 0 )
goto V_52;
if ( V_46 > 0 ) {
V_46 = - V_28 ;
goto V_52;
}
V_46 = F_62 ( V_81 , V_40 , V_42 ) ;
V_52:
F_53 ( V_42 ) ;
return V_46 ;
}
static int F_63 ( struct V_80 * V_81 ,
struct V_39 * V_40 , T_1 V_9 )
{
int V_46 ;
struct V_41 * V_42 ;
struct V_67 * V_84 ;
struct V_70 * V_85 ;
struct V_43 * V_86 ;
struct V_36 V_37 ;
if ( F_64 ( V_40 -> V_8 ) )
return 0 ;
V_42 = F_28 () ;
if ( ! V_42 )
return - V_20 ;
V_37 . V_54 = 0 ;
V_37 . type = V_65 ;
V_37 . V_55 = V_9 ;
V_46 = F_58 ( V_81 , V_40 , V_42 , & V_37 ,
sizeof( * V_84 ) ) ;
if ( V_46 && V_46 != - V_87 )
goto V_52;
V_86 = V_42 -> V_57 [ 0 ] ;
V_84 = F_31 ( V_86 , V_42 -> V_56 [ 0 ] ,
struct V_67 ) ;
F_65 ( V_86 , V_84 , V_81 -> V_88 ) ;
F_66 ( V_86 , V_84 , 0 ) ;
F_67 ( V_86 , V_84 , 0 ) ;
F_68 ( V_86 , V_84 , 0 ) ;
F_69 ( V_86 , V_84 , 0 ) ;
F_59 ( V_86 ) ;
F_49 ( V_42 ) ;
V_37 . type = V_66 ;
V_46 = F_58 ( V_81 , V_40 , V_42 , & V_37 ,
sizeof( * V_85 ) ) ;
if ( V_46 && V_46 != - V_87 )
goto V_52;
V_86 = V_42 -> V_57 [ 0 ] ;
V_85 = F_31 ( V_86 , V_42 -> V_56 [ 0 ] ,
struct V_70 ) ;
F_70 ( V_86 , V_85 , 0 ) ;
F_71 ( V_86 , V_85 , 0 ) ;
F_72 ( V_86 , V_85 , 0 ) ;
F_73 ( V_86 , V_85 , 0 ) ;
F_74 ( V_86 , V_85 , 0 ) ;
F_59 ( V_86 ) ;
V_46 = 0 ;
V_52:
F_53 ( V_42 ) ;
return V_46 ;
}
static int F_75 ( struct V_80 * V_81 ,
struct V_39 * V_40 , T_1 V_9 )
{
int V_46 ;
struct V_41 * V_42 ;
struct V_36 V_37 ;
V_42 = F_28 () ;
if ( ! V_42 )
return - V_20 ;
V_37 . V_54 = 0 ;
V_37 . type = V_65 ;
V_37 . V_55 = V_9 ;
V_46 = F_61 ( V_81 , V_40 , & V_37 , V_42 , - 1 , 1 ) ;
if ( V_46 < 0 )
goto V_52;
if ( V_46 > 0 ) {
V_46 = - V_28 ;
goto V_52;
}
V_46 = F_62 ( V_81 , V_40 , V_42 ) ;
if ( V_46 )
goto V_52;
F_49 ( V_42 ) ;
V_37 . type = V_66 ;
V_46 = F_61 ( V_81 , V_40 , & V_37 , V_42 , - 1 , 1 ) ;
if ( V_46 < 0 )
goto V_52;
if ( V_46 > 0 ) {
V_46 = - V_28 ;
goto V_52;
}
V_46 = F_62 ( V_81 , V_40 , V_42 ) ;
V_52:
F_53 ( V_42 ) ;
return V_46 ;
}
static int F_76 ( struct V_80 * V_81 ,
struct V_39 * V_89 ,
struct V_1 * V_13 )
{
struct V_41 * V_42 ;
struct V_36 V_37 ;
struct V_43 * V_44 ;
struct V_70 * V_85 ;
int V_46 ;
int V_45 ;
V_37 . V_54 = 0 ;
V_37 . type = V_66 ;
V_37 . V_55 = V_13 -> V_9 ;
V_42 = F_28 () ;
if ( ! V_42 )
return - V_20 ;
V_46 = F_61 ( V_81 , V_89 , & V_37 , V_42 , 0 , 1 ) ;
if ( V_46 > 0 )
V_46 = - V_28 ;
if ( V_46 )
goto V_52;
V_44 = V_42 -> V_57 [ 0 ] ;
V_45 = V_42 -> V_56 [ 0 ] ;
V_85 = F_31 ( V_44 , V_45 , struct V_70 ) ;
F_70 ( V_44 , V_85 , V_13 -> V_71 ) ;
F_71 ( V_44 , V_85 , V_13 -> V_72 ) ;
F_72 ( V_44 , V_85 , V_13 -> V_73 ) ;
F_73 ( V_44 , V_85 , V_13 -> V_74 ) ;
F_74 ( V_44 , V_85 , V_13 -> V_75 ) ;
F_59 ( V_44 ) ;
V_52:
F_53 ( V_42 ) ;
return V_46 ;
}
static int F_77 ( struct V_80 * V_81 ,
struct V_39 * V_89 ,
struct V_1 * V_13 )
{
struct V_41 * V_42 ;
struct V_36 V_37 ;
struct V_43 * V_44 ;
struct V_67 * V_84 ;
int V_46 ;
int V_45 ;
if ( F_64 ( V_89 -> V_8 ) )
return 0 ;
V_37 . V_54 = 0 ;
V_37 . type = V_65 ;
V_37 . V_55 = V_13 -> V_9 ;
V_42 = F_28 () ;
if ( ! V_42 )
return - V_20 ;
V_46 = F_61 ( V_81 , V_89 , & V_37 , V_42 , 0 , 1 ) ;
if ( V_46 > 0 )
V_46 = - V_28 ;
if ( V_46 )
goto V_52;
V_44 = V_42 -> V_57 [ 0 ] ;
V_45 = V_42 -> V_56 [ 0 ] ;
V_84 = F_31 ( V_44 , V_45 , struct V_67 ) ;
F_65 ( V_44 , V_84 , V_81 -> V_88 ) ;
F_66 ( V_44 , V_84 , V_13 -> V_33 ) ;
F_67 ( V_44 , V_84 , V_13 -> V_68 ) ;
F_68 ( V_44 , V_84 , V_13 -> V_34 ) ;
F_69 ( V_44 , V_84 , V_13 -> V_69 ) ;
F_59 ( V_44 ) ;
V_52:
F_53 ( V_42 ) ;
return V_46 ;
}
static int F_78 ( struct V_80 * V_81 ,
struct V_7 * V_8 ,
struct V_39 * V_89 )
{
struct V_41 * V_42 ;
struct V_36 V_37 ;
struct V_43 * V_44 ;
struct V_59 * V_60 ;
int V_46 ;
int V_45 ;
V_37 . V_54 = 0 ;
V_37 . type = V_58 ;
V_37 . V_55 = 0 ;
V_42 = F_28 () ;
if ( ! V_42 )
return - V_20 ;
V_46 = F_61 ( V_81 , V_89 , & V_37 , V_42 , 0 , 1 ) ;
if ( V_46 > 0 )
V_46 = - V_28 ;
if ( V_46 )
goto V_52;
V_44 = V_42 -> V_57 [ 0 ] ;
V_45 = V_42 -> V_56 [ 0 ] ;
V_60 = F_31 ( V_44 , V_45 , struct V_59 ) ;
F_79 ( V_44 , V_60 , V_8 -> V_53 ) ;
F_80 ( V_44 , V_60 , V_81 -> V_88 ) ;
F_81 ( V_44 , V_60 ,
V_8 -> V_90 . V_54 ) ;
F_59 ( V_44 ) ;
V_52:
F_53 ( V_42 ) ;
return V_46 ;
}
static int F_82 ( struct V_80 * V_81 ,
struct V_39 * V_89 )
{
struct V_41 * V_42 ;
struct V_36 V_37 ;
struct V_43 * V_86 = NULL ;
int V_46 ;
int V_91 = 0 ;
V_42 = F_28 () ;
if ( ! V_42 )
return - V_20 ;
V_42 -> V_92 = 1 ;
V_37 . V_54 = 0 ;
V_37 . V_55 = 0 ;
V_37 . type = 0 ;
while ( 1 ) {
V_46 = F_61 ( V_81 , V_89 , & V_37 , V_42 , - 1 , 1 ) ;
if ( V_46 < 0 )
goto V_52;
V_86 = V_42 -> V_57 [ 0 ] ;
V_91 = F_83 ( V_86 ) ;
if ( ! V_91 )
break;
V_42 -> V_56 [ 0 ] = 0 ;
V_46 = F_84 ( V_81 , V_89 , V_42 , 0 , V_91 ) ;
if ( V_46 )
goto V_52;
F_49 ( V_42 ) ;
}
V_46 = 0 ;
V_52:
F_85 ( V_93 , & V_89 -> V_8 -> V_47 ) ;
F_53 ( V_42 ) ;
return V_46 ;
}
int F_86 ( struct V_80 * V_81 ,
struct V_7 * V_8 )
{
struct V_39 * V_40 ;
struct V_39 * V_94 = V_8 -> V_94 ;
struct V_41 * V_42 = NULL ;
struct V_59 * V_60 ;
struct V_43 * V_86 ;
struct V_36 V_37 ;
struct V_36 V_38 ;
struct V_1 * V_13 = NULL ;
int V_46 = 0 ;
int V_45 ;
F_87 ( & V_8 -> V_95 ) ;
if ( V_8 -> V_40 ) {
F_85 ( V_96 , & V_8 -> V_47 ) ;
goto V_52;
}
V_8 -> V_50 = F_27 ( V_51 ) ;
if ( ! V_8 -> V_50 ) {
V_46 = - V_20 ;
goto V_52;
}
V_40 = F_88 ( V_81 , V_8 ,
V_97 ) ;
if ( F_37 ( V_40 ) ) {
V_46 = F_38 ( V_40 ) ;
goto V_52;
}
V_42 = F_28 () ;
if ( ! V_42 ) {
V_46 = - V_20 ;
goto V_98;
}
V_37 . V_54 = 0 ;
V_37 . type = V_58 ;
V_37 . V_55 = 0 ;
V_46 = F_58 ( V_81 , V_40 , V_42 , & V_37 ,
sizeof( * V_60 ) ) ;
if ( V_46 )
goto V_99;
V_86 = V_42 -> V_57 [ 0 ] ;
V_60 = F_31 ( V_86 , V_42 -> V_56 [ 0 ] ,
struct V_59 ) ;
F_80 ( V_86 , V_60 , V_81 -> V_88 ) ;
F_89 ( V_86 , V_60 , V_61 ) ;
V_8 -> V_53 = V_78 |
V_63 ;
F_79 ( V_86 , V_60 , V_8 -> V_53 ) ;
F_81 ( V_86 , V_60 , 0 ) ;
F_59 ( V_86 ) ;
V_37 . V_54 = 0 ;
V_37 . type = V_100 ;
V_37 . V_55 = 0 ;
F_49 ( V_42 ) ;
V_46 = F_29 ( V_94 , & V_37 , V_42 , 1 , 0 ) ;
if ( V_46 > 0 )
goto V_101;
if ( V_46 < 0 )
goto V_99;
while ( 1 ) {
V_45 = V_42 -> V_56 [ 0 ] ;
V_86 = V_42 -> V_57 [ 0 ] ;
F_30 ( V_86 , & V_38 , V_45 ) ;
if ( V_38 . type == V_100 ) {
V_46 = F_63 ( V_81 , V_40 ,
V_38 . V_55 ) ;
if ( V_46 )
goto V_99;
V_13 = F_7 ( V_8 , V_38 . V_55 ) ;
if ( F_37 ( V_13 ) ) {
V_46 = F_38 ( V_13 ) ;
goto V_99;
}
}
V_46 = F_48 ( V_94 , V_42 ) ;
if ( V_46 < 0 )
goto V_99;
if ( V_46 )
break;
}
V_101:
F_49 ( V_42 ) ;
V_46 = F_63 ( V_81 , V_40 , V_102 ) ;
if ( V_46 )
goto V_99;
V_13 = F_7 ( V_8 , V_102 ) ;
if ( F_37 ( V_13 ) ) {
V_46 = F_38 ( V_13 ) ;
goto V_99;
}
F_90 ( & V_8 -> V_103 ) ;
V_8 -> V_40 = V_40 ;
F_85 ( V_96 , & V_8 -> V_47 ) ;
F_91 ( & V_8 -> V_103 ) ;
V_99:
F_53 ( V_42 ) ;
V_98:
if ( V_46 ) {
F_92 ( V_40 -> V_14 ) ;
F_92 ( V_40 -> V_104 ) ;
F_17 ( V_40 ) ;
}
V_52:
if ( V_46 ) {
F_54 ( V_8 -> V_50 ) ;
V_8 -> V_50 = NULL ;
}
F_93 ( & V_8 -> V_95 ) ;
return V_46 ;
}
int F_94 ( struct V_80 * V_81 ,
struct V_7 * V_8 )
{
struct V_39 * V_94 = V_8 -> V_94 ;
struct V_39 * V_40 ;
int V_46 = 0 ;
F_87 ( & V_8 -> V_95 ) ;
if ( ! V_8 -> V_40 )
goto V_52;
F_51 ( V_49 , & V_8 -> V_47 ) ;
F_85 ( V_93 , & V_8 -> V_47 ) ;
F_95 ( V_8 , false ) ;
F_90 ( & V_8 -> V_103 ) ;
V_40 = V_8 -> V_40 ;
V_8 -> V_40 = NULL ;
V_8 -> V_53 &= ~ V_78 ;
F_91 ( & V_8 -> V_103 ) ;
F_55 ( V_8 ) ;
V_46 = F_82 ( V_81 , V_40 ) ;
if ( V_46 )
goto V_52;
V_46 = F_96 ( V_81 , V_94 , & V_40 -> V_105 ) ;
if ( V_46 )
goto V_52;
F_14 ( & V_40 -> V_106 ) ;
F_97 ( V_40 -> V_14 ) ;
F_98 ( V_81 , V_94 -> V_8 , V_40 -> V_14 ) ;
F_99 ( V_40 -> V_14 ) ;
F_100 ( V_81 , V_40 , V_40 -> V_14 , 0 , 1 ) ;
F_92 ( V_40 -> V_14 ) ;
F_92 ( V_40 -> V_104 ) ;
F_17 ( V_40 ) ;
V_52:
F_93 ( & V_8 -> V_95 ) ;
return V_46 ;
}
static void F_101 ( struct V_7 * V_8 ,
struct V_1 * V_13 )
{
if ( F_15 ( & V_13 -> V_23 ) )
F_102 ( & V_13 -> V_23 , & V_8 -> V_107 ) ;
}
static int F_103 ( struct V_7 * V_8 ,
struct V_108 * V_109 , T_1 V_110 ,
T_1 V_111 , int V_112 )
{
struct V_1 * V_13 ;
struct V_24 * V_113 ;
struct V_114 * V_115 ;
struct V_116 V_117 ;
int V_46 = 0 ;
V_13 = F_5 ( V_8 , V_110 ) ;
if ( ! V_13 )
goto V_52;
V_13 -> V_33 += V_112 * V_111 ;
V_13 -> V_68 += V_112 * V_111 ;
F_104 ( V_112 < 0 && V_13 -> V_34 < V_111 ) ;
V_13 -> V_34 += V_112 * V_111 ;
V_13 -> V_69 += V_112 * V_111 ;
if ( V_112 > 0 )
V_13 -> V_118 -= V_111 ;
F_101 ( V_8 , V_13 ) ;
F_23 (glist, &qgroup->groups, next_group) {
V_46 = F_105 ( V_109 , V_113 -> V_32 -> V_9 ,
F_106 ( V_113 -> V_32 ) , V_19 ) ;
if ( V_46 < 0 )
goto V_52;
}
F_107 ( & V_117 ) ;
while ( ( V_115 = F_108 ( V_109 , & V_117 ) ) ) {
V_13 = F_109 ( V_115 -> V_119 ) ;
V_13 -> V_33 += V_112 * V_111 ;
V_13 -> V_68 += V_112 * V_111 ;
F_104 ( V_112 < 0 && V_13 -> V_34 < V_111 ) ;
V_13 -> V_34 += V_112 * V_111 ;
if ( V_112 > 0 )
V_13 -> V_118 -= V_111 ;
V_13 -> V_69 += V_112 * V_111 ;
F_101 ( V_8 , V_13 ) ;
F_23 (glist, &qgroup->groups, next_group) {
V_46 = F_105 ( V_109 , V_113 -> V_32 -> V_9 ,
F_106 ( V_113 -> V_32 ) , V_19 ) ;
if ( V_46 < 0 )
goto V_52;
}
}
V_46 = 0 ;
V_52:
return V_46 ;
}
static int F_110 ( struct V_7 * V_8 ,
struct V_108 * V_109 , T_1 V_82 , T_1 V_83 ,
int V_112 )
{
struct V_1 * V_13 ;
int V_46 = 1 ;
int V_120 = 0 ;
V_13 = F_5 ( V_8 , V_82 ) ;
if ( ! V_13 )
goto V_52;
if ( V_13 -> V_34 == V_13 -> V_33 ) {
V_46 = 0 ;
V_120 = F_103 ( V_8 , V_109 , V_83 ,
V_13 -> V_34 , V_112 ) ;
if ( V_120 < 0 ) {
V_46 = V_120 ;
goto V_52;
}
}
V_52:
if ( V_46 )
V_8 -> V_53 |= V_63 ;
return V_46 ;
}
int F_111 ( struct V_80 * V_81 ,
struct V_7 * V_8 , T_1 V_82 , T_1 V_83 )
{
struct V_39 * V_40 ;
struct V_1 * V_18 ;
struct V_1 * V_31 ;
struct V_24 * V_25 ;
struct V_108 * V_109 ;
int V_46 = 0 ;
if ( F_112 ( V_82 ) >= F_112 ( V_83 ) )
return - V_35 ;
V_109 = F_27 ( V_51 ) ;
if ( ! V_109 )
return - V_20 ;
F_87 ( & V_8 -> V_95 ) ;
V_40 = V_8 -> V_40 ;
if ( ! V_40 ) {
V_46 = - V_35 ;
goto V_52;
}
V_31 = F_5 ( V_8 , V_82 ) ;
V_18 = F_5 ( V_8 , V_83 ) ;
if ( ! V_31 || ! V_18 ) {
V_46 = - V_35 ;
goto V_52;
}
F_23 (list, &member->groups, next_group) {
if ( V_25 -> V_32 == V_18 ) {
V_46 = - V_87 ;
goto V_52;
}
}
V_46 = F_57 ( V_81 , V_40 , V_82 , V_83 ) ;
if ( V_46 )
goto V_52;
V_46 = F_57 ( V_81 , V_40 , V_83 , V_82 ) ;
if ( V_46 ) {
F_60 ( V_81 , V_40 , V_82 , V_83 ) ;
goto V_52;
}
F_90 ( & V_8 -> V_103 ) ;
V_46 = F_20 ( V_40 -> V_8 , V_82 , V_83 ) ;
if ( V_46 < 0 ) {
F_91 ( & V_8 -> V_103 ) ;
goto V_52;
}
V_46 = F_110 ( V_8 , V_109 , V_82 , V_83 , 1 ) ;
F_91 ( & V_8 -> V_103 ) ;
V_52:
F_93 ( & V_8 -> V_95 ) ;
F_54 ( V_109 ) ;
return V_46 ;
}
int F_113 ( struct V_80 * V_81 ,
struct V_7 * V_8 , T_1 V_82 , T_1 V_83 )
{
struct V_39 * V_40 ;
struct V_1 * V_18 ;
struct V_1 * V_31 ;
struct V_24 * V_25 ;
struct V_108 * V_109 ;
int V_46 = 0 ;
int V_120 ;
V_109 = F_27 ( V_51 ) ;
if ( ! V_109 )
return - V_20 ;
V_40 = V_8 -> V_40 ;
if ( ! V_40 ) {
V_46 = - V_35 ;
goto V_52;
}
V_31 = F_5 ( V_8 , V_82 ) ;
V_18 = F_5 ( V_8 , V_83 ) ;
if ( ! V_31 || ! V_18 ) {
V_46 = - V_35 ;
goto V_52;
}
F_23 (list, &member->groups, next_group) {
if ( V_25 -> V_32 == V_18 )
goto V_121;
}
V_46 = - V_28 ;
goto V_52;
V_121:
V_46 = F_60 ( V_81 , V_40 , V_82 , V_83 ) ;
V_120 = F_60 ( V_81 , V_40 , V_83 , V_82 ) ;
if ( V_120 && ! V_46 )
V_46 = V_120 ;
F_90 ( & V_8 -> V_103 ) ;
F_22 ( V_8 , V_82 , V_83 ) ;
V_46 = F_110 ( V_8 , V_109 , V_82 , V_83 , - 1 ) ;
F_91 ( & V_8 -> V_103 ) ;
V_52:
F_54 ( V_109 ) ;
return V_46 ;
}
int F_114 ( struct V_80 * V_81 ,
struct V_7 * V_8 , T_1 V_82 , T_1 V_83 )
{
int V_46 = 0 ;
F_87 ( & V_8 -> V_95 ) ;
V_46 = F_113 ( V_81 , V_8 , V_82 , V_83 ) ;
F_93 ( & V_8 -> V_95 ) ;
return V_46 ;
}
int F_115 ( struct V_80 * V_81 ,
struct V_7 * V_8 , T_1 V_9 )
{
struct V_39 * V_40 ;
struct V_1 * V_13 ;
int V_46 = 0 ;
F_87 ( & V_8 -> V_95 ) ;
V_40 = V_8 -> V_40 ;
if ( ! V_40 ) {
V_46 = - V_35 ;
goto V_52;
}
V_13 = F_5 ( V_8 , V_9 ) ;
if ( V_13 ) {
V_46 = - V_87 ;
goto V_52;
}
V_46 = F_63 ( V_81 , V_40 , V_9 ) ;
if ( V_46 )
goto V_52;
F_90 ( & V_8 -> V_103 ) ;
V_13 = F_7 ( V_8 , V_9 ) ;
F_91 ( & V_8 -> V_103 ) ;
if ( F_37 ( V_13 ) )
V_46 = F_38 ( V_13 ) ;
V_52:
F_93 ( & V_8 -> V_95 ) ;
return V_46 ;
}
int F_116 ( struct V_80 * V_81 ,
struct V_7 * V_8 , T_1 V_9 )
{
struct V_39 * V_40 ;
struct V_1 * V_13 ;
struct V_24 * V_25 ;
int V_46 = 0 ;
F_87 ( & V_8 -> V_95 ) ;
V_40 = V_8 -> V_40 ;
if ( ! V_40 ) {
V_46 = - V_35 ;
goto V_52;
}
V_13 = F_5 ( V_8 , V_9 ) ;
if ( ! V_13 ) {
V_46 = - V_28 ;
goto V_52;
} else {
if ( ! F_15 ( & V_13 -> V_22 ) ) {
V_46 = - V_122 ;
goto V_52;
}
}
V_46 = F_75 ( V_81 , V_40 , V_9 ) ;
while ( ! F_15 ( & V_13 -> V_21 ) ) {
V_25 = F_16 ( & V_13 -> V_21 ,
struct V_24 , V_26 ) ;
V_46 = F_113 ( V_81 , V_8 ,
V_9 ,
V_25 -> V_32 -> V_9 ) ;
if ( V_46 )
goto V_52;
}
F_90 ( & V_8 -> V_103 ) ;
F_18 ( V_40 -> V_8 , V_9 ) ;
F_91 ( & V_8 -> V_103 ) ;
V_52:
F_93 ( & V_8 -> V_95 ) ;
return V_46 ;
}
int F_117 ( struct V_80 * V_81 ,
struct V_7 * V_8 , T_1 V_9 ,
struct V_123 * V_124 )
{
struct V_39 * V_40 ;
struct V_1 * V_13 ;
int V_46 = 0 ;
const T_1 V_125 = - 1 ;
F_87 ( & V_8 -> V_95 ) ;
V_40 = V_8 -> V_40 ;
if ( ! V_40 ) {
V_46 = - V_35 ;
goto V_52;
}
V_13 = F_5 ( V_8 , V_9 ) ;
if ( ! V_13 ) {
V_46 = - V_28 ;
goto V_52;
}
F_90 ( & V_8 -> V_103 ) ;
if ( V_124 -> V_47 & V_126 ) {
if ( V_124 -> V_72 == V_125 ) {
V_13 -> V_71 &= ~ V_126 ;
V_124 -> V_47 &= ~ V_126 ;
V_13 -> V_72 = 0 ;
} else {
V_13 -> V_72 = V_124 -> V_72 ;
}
}
if ( V_124 -> V_47 & V_127 ) {
if ( V_124 -> V_73 == V_125 ) {
V_13 -> V_71 &= ~ V_127 ;
V_124 -> V_47 &= ~ V_127 ;
V_13 -> V_73 = 0 ;
} else {
V_13 -> V_73 = V_124 -> V_73 ;
}
}
if ( V_124 -> V_47 & V_128 ) {
if ( V_124 -> V_74 == V_125 ) {
V_13 -> V_71 &= ~ V_128 ;
V_124 -> V_47 &= ~ V_128 ;
V_13 -> V_74 = 0 ;
} else {
V_13 -> V_74 = V_124 -> V_74 ;
}
}
if ( V_124 -> V_47 & V_129 ) {
if ( V_124 -> V_75 == V_125 ) {
V_13 -> V_71 &= ~ V_129 ;
V_124 -> V_47 &= ~ V_129 ;
V_13 -> V_75 = 0 ;
} else {
V_13 -> V_75 = V_124 -> V_75 ;
}
}
V_13 -> V_71 |= V_124 -> V_47 ;
F_91 ( & V_8 -> V_103 ) ;
V_46 = F_76 ( V_81 , V_40 , V_13 ) ;
if ( V_46 ) {
V_8 -> V_53 |= V_63 ;
F_118 ( V_8 , L_5 ,
V_9 ) ;
}
V_52:
F_93 ( & V_8 -> V_95 ) ;
return V_46 ;
}
int F_119 ( struct V_80 * V_81 ,
struct V_7 * V_8 )
{
struct V_130 * V_131 ;
struct V_132 * V_133 ;
struct V_10 * V_14 ;
T_1 V_134 ;
int V_46 = 0 ;
V_133 = & V_81 -> V_135 -> V_133 ;
V_134 = V_133 -> V_134 ;
V_14 = F_56 ( & V_133 -> V_136 ) ;
while ( V_14 ) {
V_131 = F_6 ( V_14 , struct V_130 ,
V_14 ) ;
V_46 = F_120 ( NULL , V_8 , V_131 -> V_137 , 0 ,
& V_131 -> V_138 ) ;
if ( V_46 < 0 )
break;
if ( V_134 )
F_121 ( V_131 -> V_138 , V_134 , 0 ) ;
V_14 = F_122 ( V_14 ) ;
}
return V_46 ;
}
int F_123 ( struct V_7 * V_8 ,
struct V_132 * V_133 ,
struct V_130 * V_131 )
{
struct V_10 * * V_17 = & V_133 -> V_136 . V_10 ;
struct V_10 * V_139 = NULL ;
struct V_130 * V_140 ;
T_1 V_137 = V_131 -> V_137 ;
F_124 ( & V_133 -> V_141 ) ;
F_125 ( V_8 , V_131 ) ;
while ( * V_17 ) {
V_139 = * V_17 ;
V_140 = F_6 ( V_139 , struct V_130 ,
V_14 ) ;
if ( V_137 < V_140 -> V_137 )
V_17 = & ( * V_17 ) -> V_15 ;
else if ( V_137 > V_140 -> V_137 )
V_17 = & ( * V_17 ) -> V_16 ;
else
return 1 ;
}
F_11 ( & V_131 -> V_14 , V_139 , V_17 ) ;
F_12 ( & V_131 -> V_14 , & V_133 -> V_136 ) ;
return 0 ;
}
int F_126 ( struct V_80 * V_81 ,
struct V_7 * V_8 , T_1 V_137 , T_1 V_111 ,
T_2 V_142 )
{
struct V_130 * V_131 ;
struct V_132 * V_133 ;
int V_46 ;
if ( ! F_26 ( V_49 , & V_8 -> V_47 )
|| V_137 == 0 || V_111 == 0 )
return 0 ;
if ( F_104 ( V_81 == NULL ) )
return - V_35 ;
V_131 = F_127 ( sizeof( * V_131 ) , V_142 ) ;
if ( ! V_131 )
return - V_20 ;
V_133 = & V_81 -> V_135 -> V_133 ;
V_131 -> V_137 = V_137 ;
V_131 -> V_111 = V_111 ;
V_131 -> V_138 = NULL ;
F_90 ( & V_133 -> V_141 ) ;
V_46 = F_123 ( V_8 , V_133 ,
V_131 ) ;
F_91 ( & V_133 -> V_141 ) ;
if ( V_46 > 0 )
F_17 ( V_131 ) ;
return 0 ;
}
static int F_128 ( struct V_7 * V_8 ,
struct V_108 * V_143 , struct V_108 * V_109 ,
struct V_108 * V_144 , T_1 V_3 , int V_145 )
{
struct V_114 * V_115 ;
struct V_116 V_117 ;
struct V_114 * V_146 ;
struct V_116 V_147 ;
struct V_1 * V_2 ;
int V_46 = 0 ;
if ( ! V_143 )
return 0 ;
F_107 ( & V_117 ) ;
while ( ( V_115 = F_108 ( V_143 , & V_117 ) ) ) {
V_2 = F_5 ( V_8 , V_115 -> V_148 ) ;
if ( ! V_2 )
continue;
F_129 ( V_109 ) ;
V_46 = F_105 ( V_144 , V_2 -> V_9 , F_106 ( V_2 ) ,
V_19 ) ;
if ( V_46 < 0 )
return V_46 ;
V_46 = F_105 ( V_109 , V_2 -> V_9 , F_106 ( V_2 ) , V_19 ) ;
if ( V_46 < 0 )
return V_46 ;
F_107 ( & V_147 ) ;
while ( ( V_146 = F_108 ( V_109 , & V_147 ) ) ) {
struct V_24 * V_113 ;
V_2 = F_109 ( V_146 -> V_119 ) ;
if ( V_145 )
F_1 ( V_2 , V_3 , 1 ) ;
else
F_2 ( V_2 , V_3 , 1 ) ;
F_23 (glist, &qg->groups, next_group) {
V_46 = F_105 ( V_144 , V_113 -> V_32 -> V_9 ,
F_106 ( V_113 -> V_32 ) ,
V_19 ) ;
if ( V_46 < 0 )
return V_46 ;
V_46 = F_105 ( V_109 , V_113 -> V_32 -> V_9 ,
F_106 ( V_113 -> V_32 ) ,
V_19 ) ;
if ( V_46 < 0 )
return V_46 ;
}
}
}
return 0 ;
}
static int F_130 ( struct V_7 * V_8 ,
struct V_108 * V_144 ,
T_1 V_149 ,
T_1 V_150 ,
T_1 V_111 , T_1 V_3 )
{
struct V_114 * V_115 ;
struct V_116 V_117 ;
struct V_1 * V_2 ;
T_1 V_151 , V_152 ;
F_107 ( & V_117 ) ;
while ( ( V_115 = F_108 ( V_144 , & V_117 ) ) ) {
bool V_23 = false ;
V_2 = F_109 ( V_115 -> V_119 ) ;
V_152 = F_3 ( V_2 , V_3 ) ;
V_151 = F_4 ( V_2 , V_3 ) ;
F_131 ( V_8 , V_2 -> V_9 ,
V_152 , V_151 ) ;
if ( V_152 == 0 && V_151 > 0 ) {
V_2 -> V_33 += V_111 ;
V_2 -> V_68 += V_111 ;
V_23 = true ;
}
if ( V_152 > 0 && V_151 == 0 ) {
V_2 -> V_33 -= V_111 ;
V_2 -> V_68 -= V_111 ;
V_23 = true ;
}
if ( V_152 == V_149 &&
V_151 < V_150 ) {
if ( V_152 != 0 ) {
V_2 -> V_34 -= V_111 ;
V_2 -> V_69 -= V_111 ;
V_23 = true ;
}
}
if ( V_152 < V_149 &&
V_151 == V_150 ) {
if ( V_151 != 0 ) {
V_2 -> V_34 += V_111 ;
V_2 -> V_69 += V_111 ;
V_23 = true ;
}
}
if ( V_152 == V_149 &&
V_151 == V_150 ) {
if ( V_152 == 0 ) {
if ( V_151 != 0 ) {
V_2 -> V_34 += V_111 ;
V_2 -> V_69 += V_111 ;
V_23 = true ;
}
} else {
if ( V_151 == 0 ) {
V_2 -> V_34 -= V_111 ;
V_2 -> V_69 -= V_111 ;
V_23 = true ;
}
}
}
if ( V_23 )
F_101 ( V_8 , V_2 ) ;
}
return 0 ;
}
int
F_132 ( struct V_80 * V_81 ,
struct V_7 * V_8 ,
T_1 V_137 , T_1 V_111 ,
struct V_108 * V_138 , struct V_108 * V_153 )
{
struct V_108 * V_144 = NULL ;
struct V_108 * V_109 = NULL ;
T_1 V_3 ;
T_1 V_150 = 0 ;
T_1 V_149 = 0 ;
int V_46 = 0 ;
if ( V_153 )
V_150 = V_153 -> V_154 ;
if ( V_138 )
V_149 = V_138 -> V_154 ;
if ( ! F_26 ( V_49 , & V_8 -> V_47 ) )
goto V_155;
F_133 ( ! V_8 -> V_40 ) ;
F_134 ( V_8 , V_137 , V_111 ,
V_149 , V_150 ) ;
V_144 = F_27 ( V_51 ) ;
if ( ! V_144 ) {
V_46 = - V_20 ;
goto V_155;
}
V_109 = F_27 ( V_51 ) ;
if ( ! V_109 ) {
V_46 = - V_20 ;
goto V_155;
}
F_87 ( & V_8 -> V_156 ) ;
if ( V_8 -> V_53 & V_79 ) {
if ( V_8 -> V_90 . V_54 <= V_137 ) {
F_93 ( & V_8 -> V_156 ) ;
V_46 = 0 ;
goto V_155;
}
}
F_93 ( & V_8 -> V_156 ) ;
F_90 ( & V_8 -> V_103 ) ;
V_3 = V_8 -> V_157 ;
V_46 = F_128 ( V_8 , V_138 , V_109 , V_144 , V_3 ,
V_158 ) ;
if ( V_46 < 0 )
goto V_52;
V_46 = F_128 ( V_8 , V_153 , V_109 , V_144 , V_3 ,
V_159 ) ;
if ( V_46 < 0 )
goto V_52;
F_130 ( V_8 , V_144 , V_149 , V_150 ,
V_111 , V_3 ) ;
V_8 -> V_157 += F_135 ( V_149 , V_150 ) + 1 ;
V_52:
F_91 ( & V_8 -> V_103 ) ;
V_155:
F_54 ( V_109 ) ;
F_54 ( V_144 ) ;
F_54 ( V_138 ) ;
F_54 ( V_153 ) ;
return V_46 ;
}
int F_136 ( struct V_80 * V_81 ,
struct V_7 * V_8 )
{
struct V_130 * V_131 ;
struct V_132 * V_133 ;
struct V_108 * V_153 = NULL ;
struct V_10 * V_14 ;
T_1 V_134 ;
int V_46 = 0 ;
V_133 = & V_81 -> V_135 -> V_133 ;
V_134 = V_133 -> V_134 ;
while ( ( V_14 = F_56 ( & V_133 -> V_136 ) ) ) {
V_131 = F_6 ( V_14 , struct V_130 ,
V_14 ) ;
F_137 ( V_8 , V_131 ) ;
if ( ! V_46 ) {
V_46 = F_120 ( V_81 , V_8 ,
V_131 -> V_137 , ( T_1 ) - 1 , & V_153 ) ;
if ( V_46 < 0 )
goto V_160;
if ( V_134 )
F_121 ( V_153 , V_134 , 0 ) ;
V_46 = F_132 ( V_81 , V_8 ,
V_131 -> V_137 , V_131 -> V_111 ,
V_131 -> V_138 , V_153 ) ;
V_131 -> V_138 = NULL ;
V_153 = NULL ;
}
V_160:
F_54 ( V_131 -> V_138 ) ;
F_54 ( V_153 ) ;
V_153 = NULL ;
F_19 ( V_14 , & V_133 -> V_136 ) ;
F_17 ( V_131 ) ;
}
return V_46 ;
}
int F_138 ( struct V_80 * V_81 ,
struct V_7 * V_8 )
{
struct V_39 * V_40 = V_8 -> V_40 ;
int V_46 = 0 ;
int V_161 = 0 ;
if ( ! V_40 )
goto V_52;
if ( ! F_26 ( V_49 , & V_8 -> V_47 ) &&
F_26 ( V_96 , & V_8 -> V_47 ) )
V_161 = 1 ;
if ( F_139 ( V_96 , & V_8 -> V_47 ) )
F_85 ( V_49 , & V_8 -> V_47 ) ;
if ( F_139 ( V_93 , & V_8 -> V_47 ) )
F_51 ( V_49 , & V_8 -> V_47 ) ;
F_90 ( & V_8 -> V_103 ) ;
while ( ! F_15 ( & V_8 -> V_107 ) ) {
struct V_1 * V_13 ;
V_13 = F_16 ( & V_8 -> V_107 ,
struct V_1 , V_23 ) ;
F_140 ( & V_13 -> V_23 ) ;
F_91 ( & V_8 -> V_103 ) ;
V_46 = F_77 ( V_81 , V_40 , V_13 ) ;
if ( V_46 )
V_8 -> V_53 |=
V_63 ;
V_46 = F_76 ( V_81 , V_40 , V_13 ) ;
if ( V_46 )
V_8 -> V_53 |=
V_63 ;
F_90 ( & V_8 -> V_103 ) ;
}
if ( F_26 ( V_49 , & V_8 -> V_47 ) )
V_8 -> V_53 |= V_78 ;
else
V_8 -> V_53 &= ~ V_78 ;
F_91 ( & V_8 -> V_103 ) ;
V_46 = F_78 ( V_81 , V_8 , V_40 ) ;
if ( V_46 )
V_8 -> V_53 |= V_63 ;
if ( ! V_46 && V_161 ) {
V_46 = F_52 ( V_8 , 0 , 1 ) ;
if ( ! V_46 ) {
F_141 ( V_8 ) ;
F_142 ( V_8 -> V_162 ,
& V_8 -> V_163 ) ;
}
V_46 = 0 ;
}
V_52:
return V_46 ;
}
int F_143 ( struct V_80 * V_81 ,
struct V_7 * V_8 , T_1 V_164 , T_1 V_54 ,
struct F_143 * V_165 )
{
int V_46 = 0 ;
int V_166 ;
T_1 * V_167 ;
struct V_39 * V_40 = V_8 -> V_40 ;
struct V_1 * V_168 ;
struct V_1 * V_169 ;
T_3 V_170 = 0 ;
T_1 V_171 ;
F_87 ( & V_8 -> V_95 ) ;
if ( ! F_26 ( V_49 , & V_8 -> V_47 ) )
goto V_52;
if ( ! V_40 ) {
V_46 = - V_35 ;
goto V_52;
}
if ( V_165 ) {
V_167 = ( T_1 * ) ( V_165 + 1 ) ;
V_171 = V_165 -> V_172 + 2 * V_165 -> V_173 +
2 * V_165 -> V_174 ;
for ( V_166 = 0 ; V_166 < V_171 ; ++ V_166 ) {
V_168 = F_5 ( V_8 , * V_167 ) ;
if ( ! V_168 ||
( ( V_168 -> V_9 >> 48 ) <= ( V_54 >> 48 ) ) )
* V_167 = 0ULL ;
++ V_167 ;
}
}
V_46 = F_63 ( V_81 , V_40 , V_54 ) ;
if ( V_46 )
goto V_52;
if ( V_164 ) {
struct V_39 * V_175 ;
struct V_36 V_176 ;
V_176 . V_54 = V_164 ;
V_176 . type = V_177 ;
V_176 . V_55 = ( T_1 ) - 1 ;
V_175 = F_144 ( V_8 , & V_176 ) ;
if ( F_37 ( V_175 ) ) {
V_46 = F_38 ( V_175 ) ;
goto V_52;
}
F_145 () ;
V_170 = V_175 -> V_178 ;
F_146 () ;
}
if ( V_165 ) {
V_167 = ( T_1 * ) ( V_165 + 1 ) ;
for ( V_166 = 0 ; V_166 < V_165 -> V_172 ; ++ V_166 , ++ V_167 ) {
if ( * V_167 == 0 )
continue;
V_46 = F_57 ( V_81 , V_40 ,
V_54 , * V_167 ) ;
if ( V_46 && V_46 != - V_87 )
goto V_52;
V_46 = F_57 ( V_81 , V_40 ,
* V_167 , V_54 ) ;
if ( V_46 && V_46 != - V_87 )
goto V_52;
}
V_46 = 0 ;
}
F_90 ( & V_8 -> V_103 ) ;
V_169 = F_7 ( V_8 , V_54 ) ;
if ( F_37 ( V_169 ) ) {
V_46 = F_38 ( V_169 ) ;
goto V_179;
}
if ( V_165 && V_165 -> V_47 & V_180 ) {
V_169 -> V_71 = V_165 -> V_181 . V_47 ;
V_169 -> V_72 = V_165 -> V_181 . V_72 ;
V_169 -> V_73 = V_165 -> V_181 . V_73 ;
V_169 -> V_74 = V_165 -> V_181 . V_74 ;
V_169 -> V_75 = V_165 -> V_181 . V_75 ;
V_46 = F_76 ( V_81 , V_40 , V_169 ) ;
if ( V_46 ) {
V_8 -> V_53 |= V_63 ;
F_118 ( V_8 ,
L_5 ,
V_169 -> V_9 ) ;
goto V_179;
}
}
if ( V_164 ) {
V_168 = F_5 ( V_8 , V_164 ) ;
if ( ! V_168 )
goto V_179;
V_169 -> V_33 = V_168 -> V_33 ;
V_169 -> V_68 = V_168 -> V_68 ;
V_169 -> V_34 = V_170 ;
V_169 -> V_69 = V_170 ;
V_168 -> V_34 = V_170 ;
V_168 -> V_69 = V_170 ;
V_169 -> V_71 = V_168 -> V_71 ;
V_169 -> V_72 = V_168 -> V_72 ;
V_169 -> V_73 = V_168 -> V_73 ;
V_169 -> V_74 = V_168 -> V_74 ;
V_169 -> V_75 = V_168 -> V_75 ;
F_101 ( V_8 , V_169 ) ;
F_101 ( V_8 , V_168 ) ;
}
if ( ! V_165 )
goto V_179;
V_167 = ( T_1 * ) ( V_165 + 1 ) ;
for ( V_166 = 0 ; V_166 < V_165 -> V_172 ; ++ V_166 ) {
if ( * V_167 ) {
V_46 = F_20 ( V_40 -> V_8 , V_54 ,
* V_167 ) ;
if ( V_46 )
goto V_179;
}
++ V_167 ;
}
for ( V_166 = 0 ; V_166 < V_165 -> V_173 ; ++ V_166 , V_167 += 2 ) {
struct V_1 * V_82 ;
struct V_1 * V_83 ;
if ( ! V_167 [ 0 ] || ! V_167 [ 1 ] )
continue;
V_82 = F_5 ( V_8 , V_167 [ 0 ] ) ;
V_83 = F_5 ( V_8 , V_167 [ 1 ] ) ;
if ( ! V_82 || ! V_83 ) {
V_46 = - V_35 ;
goto V_179;
}
V_83 -> V_33 = V_82 -> V_33 - V_170 ;
V_83 -> V_68 = V_82 -> V_68 - V_170 ;
}
for ( V_166 = 0 ; V_166 < V_165 -> V_174 ; ++ V_166 , V_167 += 2 ) {
struct V_1 * V_82 ;
struct V_1 * V_83 ;
if ( ! V_167 [ 0 ] || ! V_167 [ 1 ] )
continue;
V_82 = F_5 ( V_8 , V_167 [ 0 ] ) ;
V_83 = F_5 ( V_8 , V_167 [ 1 ] ) ;
if ( ! V_82 || ! V_83 ) {
V_46 = - V_35 ;
goto V_179;
}
V_83 -> V_34 = V_82 -> V_34 + V_170 ;
V_83 -> V_69 = V_82 -> V_69 + V_170 ;
}
V_179:
F_91 ( & V_8 -> V_103 ) ;
V_52:
F_93 ( & V_8 -> V_95 ) ;
return V_46 ;
}
static int F_147 ( struct V_39 * V_89 , T_1 V_111 )
{
struct V_39 * V_40 ;
struct V_1 * V_13 ;
struct V_7 * V_8 = V_89 -> V_8 ;
T_1 V_110 = V_89 -> V_105 . V_54 ;
int V_46 = 0 ;
struct V_114 * V_115 ;
struct V_116 V_117 ;
if ( ! F_148 ( V_110 ) )
return 0 ;
if ( V_111 == 0 )
return 0 ;
F_90 ( & V_8 -> V_103 ) ;
V_40 = V_8 -> V_40 ;
if ( ! V_40 )
goto V_52;
V_13 = F_5 ( V_8 , V_110 ) ;
if ( ! V_13 )
goto V_52;
F_129 ( V_8 -> V_50 ) ;
V_46 = F_105 ( V_8 -> V_50 , V_13 -> V_9 ,
( V_182 ) V_13 , V_19 ) ;
if ( V_46 < 0 )
goto V_52;
F_107 ( & V_117 ) ;
while ( ( V_115 = F_108 ( V_8 -> V_50 , & V_117 ) ) ) {
struct V_1 * V_2 ;
struct V_24 * V_113 ;
V_2 = F_109 ( V_115 -> V_119 ) ;
if ( ( V_2 -> V_71 & V_126 ) &&
V_2 -> V_118 + ( V_183 ) V_2 -> V_33 + V_111 >
V_2 -> V_72 ) {
V_46 = - V_184 ;
goto V_52;
}
if ( ( V_2 -> V_71 & V_127 ) &&
V_2 -> V_118 + ( V_183 ) V_2 -> V_34 + V_111 >
V_2 -> V_73 ) {
V_46 = - V_184 ;
goto V_52;
}
F_23 (glist, &qg->groups, next_group) {
V_46 = F_105 ( V_8 -> V_50 ,
V_113 -> V_32 -> V_9 ,
( V_182 ) V_113 -> V_32 , V_19 ) ;
if ( V_46 < 0 )
goto V_52;
}
}
V_46 = 0 ;
F_107 ( & V_117 ) ;
while ( ( V_115 = F_108 ( V_8 -> V_50 , & V_117 ) ) ) {
struct V_1 * V_2 ;
V_2 = F_109 ( V_115 -> V_119 ) ;
V_2 -> V_118 += V_111 ;
}
V_52:
F_91 ( & V_8 -> V_103 ) ;
return V_46 ;
}
void F_149 ( struct V_7 * V_8 ,
T_1 V_110 , T_1 V_111 )
{
struct V_39 * V_40 ;
struct V_1 * V_13 ;
struct V_114 * V_115 ;
struct V_116 V_117 ;
int V_46 = 0 ;
if ( ! F_148 ( V_110 ) )
return;
if ( V_111 == 0 )
return;
F_90 ( & V_8 -> V_103 ) ;
V_40 = V_8 -> V_40 ;
if ( ! V_40 )
goto V_52;
V_13 = F_5 ( V_8 , V_110 ) ;
if ( ! V_13 )
goto V_52;
F_129 ( V_8 -> V_50 ) ;
V_46 = F_105 ( V_8 -> V_50 , V_13 -> V_9 ,
( V_182 ) V_13 , V_19 ) ;
if ( V_46 < 0 )
goto V_52;
F_107 ( & V_117 ) ;
while ( ( V_115 = F_108 ( V_8 -> V_50 , & V_117 ) ) ) {
struct V_1 * V_2 ;
struct V_24 * V_113 ;
V_2 = F_109 ( V_115 -> V_119 ) ;
V_2 -> V_118 -= V_111 ;
F_23 (glist, &qg->groups, next_group) {
V_46 = F_105 ( V_8 -> V_50 ,
V_113 -> V_32 -> V_9 ,
( V_182 ) V_113 -> V_32 , V_19 ) ;
if ( V_46 < 0 )
goto V_52;
}
}
V_52:
F_91 ( & V_8 -> V_103 ) ;
}
static inline void F_150 ( struct V_39 * V_89 , T_1 V_111 )
{
return F_149 ( V_89 -> V_8 , V_89 -> V_54 ,
V_111 ) ;
}
void F_151 ( struct V_80 * V_81 )
{
if ( F_15 ( & V_81 -> V_185 ) && ! V_81 -> V_186 . V_3 )
return;
F_33 ( V_81 -> V_8 ,
L_6 ,
V_81 , F_15 ( & V_81 -> V_185 ) ? L_7 : L_8 ,
( T_3 ) ( V_81 -> V_186 . V_3 >> 32 ) ,
( T_3 ) V_81 -> V_186 . V_3 ) ;
F_152 () ;
}
static int
F_153 ( struct V_7 * V_8 , struct V_41 * V_42 ,
struct V_80 * V_81 )
{
struct V_36 V_187 ;
struct V_43 * V_188 = NULL ;
struct V_108 * V_143 = NULL ;
struct V_189 V_190 = F_154 ( V_190 ) ;
T_1 V_111 ;
int V_45 ;
int V_46 ;
F_87 ( & V_8 -> V_156 ) ;
V_46 = F_29 ( V_8 -> V_191 ,
& V_8 -> V_90 ,
V_42 , 1 , 0 ) ;
F_155 ( V_8 ,
L_9 ,
V_8 -> V_90 . V_54 ,
V_8 -> V_90 . type ,
V_8 -> V_90 . V_55 , V_46 ) ;
if ( V_46 ) {
V_8 -> V_90 . V_54 = ( T_1 ) - 1 ;
F_49 ( V_42 ) ;
F_93 ( & V_8 -> V_156 ) ;
return V_46 ;
}
F_30 ( V_42 -> V_57 [ 0 ] , & V_187 ,
F_83 ( V_42 -> V_57 [ 0 ] ) - 1 ) ;
V_8 -> V_90 . V_54 = V_187 . V_54 + 1 ;
F_156 ( V_8 , & V_190 ) ;
V_188 = F_157 ( V_42 -> V_57 [ 0 ] ) ;
if ( ! V_188 ) {
V_46 = - V_20 ;
F_93 ( & V_8 -> V_156 ) ;
goto V_52;
}
F_158 ( V_188 ) ;
F_159 ( V_188 ) ;
F_160 ( V_188 , V_192 ) ;
V_45 = V_42 -> V_56 [ 0 ] ;
F_49 ( V_42 ) ;
F_93 ( & V_8 -> V_156 ) ;
for (; V_45 < F_83 ( V_188 ) ; ++ V_45 ) {
F_30 ( V_188 , & V_187 , V_45 ) ;
if ( V_187 . type != V_193 &&
V_187 . type != V_194 )
continue;
if ( V_187 . type == V_194 )
V_111 = V_8 -> V_191 -> V_178 ;
else
V_111 = V_187 . V_55 ;
V_46 = F_120 ( NULL , V_8 , V_187 . V_54 , 0 ,
& V_143 ) ;
if ( V_46 < 0 )
goto V_52;
V_46 = F_132 ( V_81 , V_8 ,
V_187 . V_54 , V_111 , NULL , V_143 ) ;
if ( V_46 < 0 )
goto V_52;
}
V_52:
if ( V_188 ) {
F_161 ( V_188 ) ;
F_92 ( V_188 ) ;
}
F_162 ( V_8 , & V_190 ) ;
return V_46 ;
}
static void F_163 ( struct V_195 * V_196 )
{
struct V_7 * V_8 = F_164 ( V_196 , struct V_7 ,
V_163 ) ;
struct V_41 * V_42 ;
struct V_80 * V_81 = NULL ;
int V_120 = - V_20 ;
int V_46 = 0 ;
F_87 ( & V_8 -> V_156 ) ;
V_8 -> V_197 = true ;
F_93 ( & V_8 -> V_156 ) ;
V_42 = F_28 () ;
if ( ! V_42 )
goto V_52;
V_120 = 0 ;
while ( ! V_120 && ! F_165 ( V_8 ) ) {
V_81 = F_166 ( V_8 -> V_198 , 0 ) ;
if ( F_37 ( V_81 ) ) {
V_120 = F_38 ( V_81 ) ;
break;
}
if ( ! F_26 ( V_49 , & V_8 -> V_47 ) ) {
V_120 = - V_199 ;
} else {
V_120 = F_153 ( V_8 , V_42 , V_81 ) ;
}
if ( V_120 > 0 )
F_167 ( V_81 , V_8 -> V_198 ) ;
else
F_168 ( V_81 , V_8 -> V_198 ) ;
}
V_52:
F_53 ( V_42 ) ;
F_87 ( & V_8 -> V_156 ) ;
if ( ! F_165 ( V_8 ) )
V_8 -> V_53 &= ~ V_79 ;
if ( V_120 > 0 &&
V_8 -> V_53 & V_63 ) {
V_8 -> V_53 &= ~ V_63 ;
} else if ( V_120 < 0 ) {
V_8 -> V_53 |= V_63 ;
}
F_93 ( & V_8 -> V_156 ) ;
V_81 = F_166 ( V_8 -> V_40 , 1 ) ;
if ( F_37 ( V_81 ) ) {
V_120 = F_38 ( V_81 ) ;
F_33 ( V_8 ,
L_10 ,
V_120 ) ;
goto V_200;
}
V_46 = F_78 ( V_81 , V_8 , V_8 -> V_40 ) ;
if ( V_46 < 0 ) {
V_120 = V_46 ;
F_33 ( V_8 , L_11 , V_120 ) ;
}
F_168 ( V_81 , V_8 -> V_40 ) ;
if ( F_165 ( V_8 ) ) {
F_118 ( V_8 , L_12 ) ;
} else if ( V_120 >= 0 ) {
F_118 ( V_8 , L_13 ,
V_120 > 0 ? L_14 : L_7 ) ;
} else {
F_33 ( V_8 , L_15 , V_120 ) ;
}
V_200:
F_87 ( & V_8 -> V_156 ) ;
V_8 -> V_197 = false ;
F_93 ( & V_8 -> V_156 ) ;
F_169 ( & V_8 -> V_201 ) ;
}
static int
F_52 ( struct V_7 * V_8 , T_1 V_202 ,
int V_203 )
{
int V_46 = 0 ;
if ( ! V_203 &&
( ! ( V_8 -> V_53 & V_79 ) ||
! ( V_8 -> V_53 & V_78 ) ) ) {
V_46 = - V_35 ;
goto V_120;
}
F_87 ( & V_8 -> V_156 ) ;
F_90 ( & V_8 -> V_103 ) ;
if ( V_203 ) {
if ( V_8 -> V_53 & V_79 )
V_46 = - V_204 ;
else if ( ! ( V_8 -> V_53 & V_78 ) )
V_46 = - V_35 ;
if ( V_46 ) {
F_91 ( & V_8 -> V_103 ) ;
F_93 ( & V_8 -> V_156 ) ;
goto V_120;
}
V_8 -> V_53 |= V_79 ;
}
memset ( & V_8 -> V_90 , 0 ,
sizeof( V_8 -> V_90 ) ) ;
V_8 -> V_90 . V_54 = V_202 ;
F_170 ( & V_8 -> V_201 ) ;
F_91 ( & V_8 -> V_103 ) ;
F_93 ( & V_8 -> V_156 ) ;
memset ( & V_8 -> V_163 , 0 ,
sizeof( V_8 -> V_163 ) ) ;
F_171 ( & V_8 -> V_163 ,
V_205 ,
F_163 , NULL , NULL ) ;
if ( V_46 ) {
V_120:
F_118 ( V_8 , L_16 , V_46 ) ;
return V_46 ;
}
return 0 ;
}
static void
F_141 ( struct V_7 * V_8 )
{
struct V_10 * V_11 ;
struct V_1 * V_13 ;
F_90 ( & V_8 -> V_103 ) ;
for ( V_11 = F_56 ( & V_8 -> V_12 ) ; V_11 ; V_11 = F_122 ( V_11 ) ) {
V_13 = F_6 ( V_11 , struct V_1 , V_14 ) ;
V_13 -> V_33 = 0 ;
V_13 -> V_68 = 0 ;
V_13 -> V_34 = 0 ;
V_13 -> V_69 = 0 ;
}
F_91 ( & V_8 -> V_103 ) ;
}
int
F_172 ( struct V_7 * V_8 )
{
int V_46 = 0 ;
struct V_80 * V_81 ;
V_46 = F_52 ( V_8 , 0 , 1 ) ;
if ( V_46 )
return V_46 ;
V_81 = F_173 ( V_8 -> V_198 ) ;
if ( F_37 ( V_81 ) ) {
V_8 -> V_53 &= ~ V_79 ;
return F_38 ( V_81 ) ;
}
V_46 = F_167 ( V_81 , V_8 -> V_198 ) ;
if ( V_46 ) {
V_8 -> V_53 &= ~ V_79 ;
return V_46 ;
}
F_141 ( V_8 ) ;
F_142 ( V_8 -> V_162 ,
& V_8 -> V_163 ) ;
return 0 ;
}
int F_95 ( struct V_7 * V_8 ,
bool V_206 )
{
int V_207 ;
int V_46 = 0 ;
F_87 ( & V_8 -> V_156 ) ;
F_90 ( & V_8 -> V_103 ) ;
V_207 = V_8 -> V_197 ;
F_91 ( & V_8 -> V_103 ) ;
F_93 ( & V_8 -> V_156 ) ;
if ( ! V_207 )
return 0 ;
if ( V_206 )
V_46 = F_174 (
& V_8 -> V_201 ) ;
else
F_175 ( & V_8 -> V_201 ) ;
return V_46 ;
}
void
F_176 ( struct V_7 * V_8 )
{
if ( V_8 -> V_53 & V_79 )
F_142 ( V_8 -> V_162 ,
& V_8 -> V_163 ) ;
}
int F_177 ( struct V_208 * V_208 , T_1 V_209 , T_1 V_210 )
{
struct V_39 * V_89 = F_178 ( V_208 ) -> V_89 ;
struct V_211 V_212 ;
struct V_114 * V_115 ;
struct V_116 V_117 ;
int V_46 ;
if ( ! F_26 ( V_49 , & V_89 -> V_8 -> V_47 ) ||
! F_148 ( V_89 -> V_54 ) || V_210 == 0 )
return 0 ;
V_212 . V_213 = 0 ;
V_212 . V_214 = F_27 ( V_51 ) ;
V_46 = F_179 ( & F_178 ( V_208 ) -> V_215 , V_209 ,
V_209 + V_210 - 1 , V_216 , & V_212 ) ;
F_180 ( V_208 , V_209 , V_210 ,
V_212 . V_213 ,
V_217 ) ;
if ( V_46 < 0 )
goto V_160;
V_46 = F_147 ( V_89 , V_212 . V_213 ) ;
if ( V_46 < 0 )
goto V_160;
F_54 ( V_212 . V_214 ) ;
return V_46 ;
V_160:
F_107 ( & V_117 ) ;
while ( ( V_115 = F_108 ( V_212 . V_214 , & V_117 ) ) )
F_181 ( & F_178 ( V_208 ) -> V_215 , V_115 -> V_148 ,
V_115 -> V_119 , V_216 , 0 , 0 , NULL ,
V_51 ) ;
F_54 ( V_212 . V_214 ) ;
return V_46 ;
}
static int F_182 ( struct V_208 * V_208 , T_1 V_209 , T_1 V_210 ,
int free )
{
struct V_211 V_212 ;
int V_218 = V_219 ;
int V_46 ;
V_212 . V_213 = 0 ;
V_212 . V_214 = F_27 ( V_51 ) ;
if ( ! V_212 . V_214 )
return - V_20 ;
V_46 = F_183 ( & F_178 ( V_208 ) -> V_215 , V_209 ,
V_209 + V_210 - 1 , V_216 , & V_212 ) ;
if ( V_46 < 0 )
goto V_52;
if ( free ) {
F_150 ( F_178 ( V_208 ) -> V_89 , V_212 . V_213 ) ;
V_218 = V_220 ;
}
F_184 ( V_208 , V_209 , V_210 ,
V_212 . V_213 , V_218 ) ;
V_52:
F_54 ( V_212 . V_214 ) ;
return V_46 ;
}
int F_185 ( struct V_208 * V_208 , T_1 V_209 , T_1 V_210 )
{
return F_182 ( V_208 , V_209 , V_210 , 1 ) ;
}
int F_186 ( struct V_208 * V_208 , T_1 V_209 , T_1 V_210 )
{
return F_182 ( V_208 , V_209 , V_210 , 0 ) ;
}
int F_187 ( struct V_39 * V_89 , int V_111 )
{
int V_46 ;
if ( ! F_26 ( V_49 , & V_89 -> V_8 -> V_47 ) ||
! F_148 ( V_89 -> V_54 ) || V_111 == 0 )
return 0 ;
F_133 ( V_111 != F_188 ( V_111 , V_89 -> V_178 ) ) ;
V_46 = F_147 ( V_89 , V_111 ) ;
if ( V_46 < 0 )
return V_46 ;
F_189 ( V_111 , & V_89 -> V_221 ) ;
return V_46 ;
}
void F_190 ( struct V_39 * V_89 )
{
int V_118 ;
if ( ! F_26 ( V_49 , & V_89 -> V_8 -> V_47 ) ||
! F_148 ( V_89 -> V_54 ) )
return;
V_118 = F_191 ( & V_89 -> V_221 , 0 ) ;
if ( V_118 == 0 )
return;
F_150 ( V_89 , V_118 ) ;
}
void F_192 ( struct V_39 * V_89 , int V_111 )
{
if ( ! F_26 ( V_49 , & V_89 -> V_8 -> V_47 ) ||
! F_148 ( V_89 -> V_54 ) )
return;
F_133 ( V_111 != F_188 ( V_111 , V_89 -> V_178 ) ) ;
F_104 ( F_193 ( & V_89 -> V_221 ) < V_111 ) ;
F_194 ( V_111 , & V_89 -> V_221 ) ;
F_150 ( V_89 , V_111 ) ;
}
void F_195 ( struct V_208 * V_208 )
{
struct V_211 V_212 ;
struct V_114 * V_115 ;
struct V_116 V_222 ;
int V_46 ;
V_212 . V_213 = 0 ;
V_212 . V_214 = F_27 ( V_51 ) ;
if ( F_104 ( ! V_212 . V_214 ) )
return;
V_46 = F_183 ( & F_178 ( V_208 ) -> V_215 , 0 , ( T_1 ) - 1 ,
V_216 , & V_212 ) ;
F_104 ( V_46 < 0 ) ;
if ( F_104 ( V_212 . V_213 ) ) {
F_107 ( & V_222 ) ;
while ( ( V_115 = F_108 ( V_212 . V_214 , & V_222 ) ) ) {
F_50 ( F_178 ( V_208 ) -> V_89 -> V_8 ,
L_17 ,
V_208 -> V_223 , V_115 -> V_148 , V_115 -> V_119 ) ;
}
F_150 ( F_178 ( V_208 ) -> V_89 , V_212 . V_213 ) ;
}
F_54 ( V_212 . V_214 ) ;
}
