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
if ( ! V_8 -> V_49 )
return 0 ;
V_8 -> V_50 = F_26 ( V_51 ) ;
if ( ! V_8 -> V_50 ) {
V_46 = - V_20 ;
goto V_52;
}
V_42 = F_27 () ;
if ( ! V_42 ) {
V_46 = - V_20 ;
goto V_52;
}
V_8 -> V_53 = 0 ;
V_37 . V_54 = 0 ;
V_37 . type = 0 ;
V_37 . V_55 = 0 ;
V_46 = F_28 ( V_40 , & V_37 , V_42 , 1 , 1 ) ;
if ( V_46 )
goto V_52;
while ( 1 ) {
struct V_1 * V_13 ;
V_45 = V_42 -> V_56 [ 0 ] ;
V_44 = V_42 -> V_57 [ 0 ] ;
F_29 ( V_44 , & V_38 , V_45 ) ;
if ( V_38 . type == V_58 ) {
struct V_59 * V_60 ;
V_60 = F_30 ( V_44 , V_45 ,
struct V_59 ) ;
if ( F_31 ( V_44 , V_60 ) !=
V_61 ) {
F_32 ( V_8 ,
L_1 ) ;
goto V_52;
}
if ( F_33 ( V_44 , V_60 ) !=
V_8 -> V_62 ) {
V_47 |= V_63 ;
F_32 ( V_8 ,
L_2
L_3 ) ;
}
V_8 -> V_53 = F_34 ( V_44 ,
V_60 ) ;
V_48 = F_35 ( V_44 , V_60 ) ;
goto V_64;
}
if ( V_38 . type != V_65 &&
V_38 . type != V_66 )
goto V_64;
V_13 = F_5 ( V_8 , V_38 . V_55 ) ;
if ( ( V_13 && V_38 . type == V_65 ) ||
( ! V_13 && V_38 . type == V_66 ) ) {
F_32 ( V_8 , L_4 ) ;
V_47 |= V_63 ;
}
if ( ! V_13 ) {
V_13 = F_7 ( V_8 , V_38 . V_55 ) ;
if ( F_36 ( V_13 ) ) {
V_46 = F_37 ( V_13 ) ;
goto V_52;
}
}
switch ( V_38 . type ) {
case V_65 : {
struct V_67 * V_60 ;
V_60 = F_30 ( V_44 , V_45 ,
struct V_67 ) ;
V_13 -> V_33 = F_38 ( V_44 , V_60 ) ;
V_13 -> V_68 = F_39 ( V_44 , V_60 ) ;
V_13 -> V_34 = F_40 ( V_44 , V_60 ) ;
V_13 -> V_69 = F_41 ( V_44 , V_60 ) ;
break;
}
case V_66 : {
struct V_70 * V_60 ;
V_60 = F_30 ( V_44 , V_45 ,
struct V_70 ) ;
V_13 -> V_71 = F_42 ( V_44 , V_60 ) ;
V_13 -> V_72 = F_43 ( V_44 , V_60 ) ;
V_13 -> V_73 = F_44 ( V_44 , V_60 ) ;
V_13 -> V_74 = F_45 ( V_44 , V_60 ) ;
V_13 -> V_75 = F_46 ( V_44 , V_60 ) ;
break;
}
}
V_64:
V_46 = F_47 ( V_40 , V_42 ) ;
if ( V_46 < 0 )
goto V_52;
if ( V_46 )
break;
}
F_48 ( V_42 ) ;
V_37 . V_54 = 0 ;
V_37 . type = V_76 ;
V_37 . V_55 = 0 ;
V_46 = F_28 ( V_40 , & V_37 , V_42 , 1 , 0 ) ;
if ( V_46 )
goto V_52;
while ( 1 ) {
V_45 = V_42 -> V_56 [ 0 ] ;
V_44 = V_42 -> V_57 [ 0 ] ;
F_29 ( V_44 , & V_38 , V_45 ) ;
if ( V_38 . type != V_76 )
goto V_77;
if ( V_38 . V_54 > V_38 . V_55 ) {
goto V_77;
}
V_46 = F_20 ( V_8 , V_38 . V_54 ,
V_38 . V_55 ) ;
if ( V_46 == - V_28 ) {
F_49 ( V_8 ,
L_5 ,
V_38 . V_54 , V_38 . V_55 ) ;
V_46 = 0 ;
}
if ( V_46 )
goto V_52;
V_77:
V_46 = F_47 ( V_40 , V_42 ) ;
if ( V_46 < 0 )
goto V_52;
if ( V_46 )
break;
}
V_52:
V_8 -> V_53 |= V_47 ;
if ( ! ( V_8 -> V_53 & V_78 ) ) {
V_8 -> V_49 = 0 ;
V_8 -> V_79 = 0 ;
} else if ( V_8 -> V_53 & V_80 &&
V_46 >= 0 ) {
V_46 = F_50 ( V_8 , V_48 , 0 ) ;
}
F_51 ( V_42 ) ;
if ( V_46 < 0 ) {
F_52 ( V_8 -> V_50 ) ;
V_8 -> V_50 = NULL ;
V_8 -> V_53 &= ~ V_80 ;
}
return V_46 < 0 ? V_46 : 0 ;
}
void F_53 ( struct V_7 * V_8 )
{
struct V_10 * V_11 ;
struct V_1 * V_13 ;
while ( ( V_11 = F_54 ( & V_8 -> V_12 ) ) ) {
V_13 = F_6 ( V_11 , struct V_1 , V_14 ) ;
F_19 ( V_11 , & V_8 -> V_12 ) ;
F_13 ( V_13 ) ;
}
F_52 ( V_8 -> V_50 ) ;
V_8 -> V_50 = NULL ;
}
static int F_55 ( struct V_81 * V_82 ,
struct V_39 * V_40 ,
T_1 V_83 , T_1 V_84 )
{
int V_46 ;
struct V_41 * V_42 ;
struct V_36 V_37 ;
V_42 = F_27 () ;
if ( ! V_42 )
return - V_20 ;
V_37 . V_54 = V_83 ;
V_37 . type = V_76 ;
V_37 . V_55 = V_84 ;
V_46 = F_56 ( V_82 , V_40 , V_42 , & V_37 , 0 ) ;
F_57 ( V_42 -> V_57 [ 0 ] ) ;
F_51 ( V_42 ) ;
return V_46 ;
}
static int F_58 ( struct V_81 * V_82 ,
struct V_39 * V_40 ,
T_1 V_83 , T_1 V_84 )
{
int V_46 ;
struct V_41 * V_42 ;
struct V_36 V_37 ;
V_42 = F_27 () ;
if ( ! V_42 )
return - V_20 ;
V_37 . V_54 = V_83 ;
V_37 . type = V_76 ;
V_37 . V_55 = V_84 ;
V_46 = F_59 ( V_82 , V_40 , & V_37 , V_42 , - 1 , 1 ) ;
if ( V_46 < 0 )
goto V_52;
if ( V_46 > 0 ) {
V_46 = - V_28 ;
goto V_52;
}
V_46 = F_60 ( V_82 , V_40 , V_42 ) ;
V_52:
F_51 ( V_42 ) ;
return V_46 ;
}
static int F_61 ( struct V_81 * V_82 ,
struct V_39 * V_40 , T_1 V_9 )
{
int V_46 ;
struct V_41 * V_42 ;
struct V_67 * V_85 ;
struct V_70 * V_86 ;
struct V_43 * V_87 ;
struct V_36 V_37 ;
if ( F_62 ( V_40 ) )
return 0 ;
V_42 = F_27 () ;
if ( ! V_42 )
return - V_20 ;
V_37 . V_54 = 0 ;
V_37 . type = V_65 ;
V_37 . V_55 = V_9 ;
V_46 = F_56 ( V_82 , V_40 , V_42 , & V_37 ,
sizeof( * V_85 ) ) ;
if ( V_46 && V_46 != - V_88 )
goto V_52;
V_87 = V_42 -> V_57 [ 0 ] ;
V_85 = F_30 ( V_87 , V_42 -> V_56 [ 0 ] ,
struct V_67 ) ;
F_63 ( V_87 , V_85 , V_82 -> V_89 ) ;
F_64 ( V_87 , V_85 , 0 ) ;
F_65 ( V_87 , V_85 , 0 ) ;
F_66 ( V_87 , V_85 , 0 ) ;
F_67 ( V_87 , V_85 , 0 ) ;
F_57 ( V_87 ) ;
F_48 ( V_42 ) ;
V_37 . type = V_66 ;
V_46 = F_56 ( V_82 , V_40 , V_42 , & V_37 ,
sizeof( * V_86 ) ) ;
if ( V_46 && V_46 != - V_88 )
goto V_52;
V_87 = V_42 -> V_57 [ 0 ] ;
V_86 = F_30 ( V_87 , V_42 -> V_56 [ 0 ] ,
struct V_70 ) ;
F_68 ( V_87 , V_86 , 0 ) ;
F_69 ( V_87 , V_86 , 0 ) ;
F_70 ( V_87 , V_86 , 0 ) ;
F_71 ( V_87 , V_86 , 0 ) ;
F_72 ( V_87 , V_86 , 0 ) ;
F_57 ( V_87 ) ;
V_46 = 0 ;
V_52:
F_51 ( V_42 ) ;
return V_46 ;
}
static int F_73 ( struct V_81 * V_82 ,
struct V_39 * V_40 , T_1 V_9 )
{
int V_46 ;
struct V_41 * V_42 ;
struct V_36 V_37 ;
V_42 = F_27 () ;
if ( ! V_42 )
return - V_20 ;
V_37 . V_54 = 0 ;
V_37 . type = V_65 ;
V_37 . V_55 = V_9 ;
V_46 = F_59 ( V_82 , V_40 , & V_37 , V_42 , - 1 , 1 ) ;
if ( V_46 < 0 )
goto V_52;
if ( V_46 > 0 ) {
V_46 = - V_28 ;
goto V_52;
}
V_46 = F_60 ( V_82 , V_40 , V_42 ) ;
if ( V_46 )
goto V_52;
F_48 ( V_42 ) ;
V_37 . type = V_66 ;
V_46 = F_59 ( V_82 , V_40 , & V_37 , V_42 , - 1 , 1 ) ;
if ( V_46 < 0 )
goto V_52;
if ( V_46 > 0 ) {
V_46 = - V_28 ;
goto V_52;
}
V_46 = F_60 ( V_82 , V_40 , V_42 ) ;
V_52:
F_51 ( V_42 ) ;
return V_46 ;
}
static int F_74 ( struct V_81 * V_82 ,
struct V_39 * V_90 ,
struct V_1 * V_13 )
{
struct V_41 * V_42 ;
struct V_36 V_37 ;
struct V_43 * V_44 ;
struct V_70 * V_86 ;
int V_46 ;
int V_45 ;
V_37 . V_54 = 0 ;
V_37 . type = V_66 ;
V_37 . V_55 = V_13 -> V_9 ;
V_42 = F_27 () ;
if ( ! V_42 )
return - V_20 ;
V_46 = F_59 ( V_82 , V_90 , & V_37 , V_42 , 0 , 1 ) ;
if ( V_46 > 0 )
V_46 = - V_28 ;
if ( V_46 )
goto V_52;
V_44 = V_42 -> V_57 [ 0 ] ;
V_45 = V_42 -> V_56 [ 0 ] ;
V_86 = F_30 ( V_44 , V_45 , struct V_70 ) ;
F_68 ( V_44 , V_86 , V_13 -> V_71 ) ;
F_69 ( V_44 , V_86 , V_13 -> V_72 ) ;
F_70 ( V_44 , V_86 , V_13 -> V_73 ) ;
F_71 ( V_44 , V_86 , V_13 -> V_74 ) ;
F_72 ( V_44 , V_86 , V_13 -> V_75 ) ;
F_57 ( V_44 ) ;
V_52:
F_51 ( V_42 ) ;
return V_46 ;
}
static int F_75 ( struct V_81 * V_82 ,
struct V_39 * V_90 ,
struct V_1 * V_13 )
{
struct V_41 * V_42 ;
struct V_36 V_37 ;
struct V_43 * V_44 ;
struct V_67 * V_85 ;
int V_46 ;
int V_45 ;
if ( F_62 ( V_90 ) )
return 0 ;
V_37 . V_54 = 0 ;
V_37 . type = V_65 ;
V_37 . V_55 = V_13 -> V_9 ;
V_42 = F_27 () ;
if ( ! V_42 )
return - V_20 ;
V_46 = F_59 ( V_82 , V_90 , & V_37 , V_42 , 0 , 1 ) ;
if ( V_46 > 0 )
V_46 = - V_28 ;
if ( V_46 )
goto V_52;
V_44 = V_42 -> V_57 [ 0 ] ;
V_45 = V_42 -> V_56 [ 0 ] ;
V_85 = F_30 ( V_44 , V_45 , struct V_67 ) ;
F_63 ( V_44 , V_85 , V_82 -> V_89 ) ;
F_64 ( V_44 , V_85 , V_13 -> V_33 ) ;
F_65 ( V_44 , V_85 , V_13 -> V_68 ) ;
F_66 ( V_44 , V_85 , V_13 -> V_34 ) ;
F_67 ( V_44 , V_85 , V_13 -> V_69 ) ;
F_57 ( V_44 ) ;
V_52:
F_51 ( V_42 ) ;
return V_46 ;
}
static int F_76 ( struct V_81 * V_82 ,
struct V_7 * V_8 ,
struct V_39 * V_90 )
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
V_42 = F_27 () ;
if ( ! V_42 )
return - V_20 ;
V_46 = F_59 ( V_82 , V_90 , & V_37 , V_42 , 0 , 1 ) ;
if ( V_46 > 0 )
V_46 = - V_28 ;
if ( V_46 )
goto V_52;
V_44 = V_42 -> V_57 [ 0 ] ;
V_45 = V_42 -> V_56 [ 0 ] ;
V_60 = F_30 ( V_44 , V_45 , struct V_59 ) ;
F_77 ( V_44 , V_60 , V_8 -> V_53 ) ;
F_78 ( V_44 , V_60 , V_82 -> V_89 ) ;
F_79 ( V_44 , V_60 ,
V_8 -> V_91 . V_54 ) ;
F_57 ( V_44 ) ;
V_52:
F_51 ( V_42 ) ;
return V_46 ;
}
static int F_80 ( struct V_81 * V_82 ,
struct V_39 * V_90 )
{
struct V_41 * V_42 ;
struct V_36 V_37 ;
struct V_43 * V_87 = NULL ;
int V_46 ;
int V_92 = 0 ;
V_42 = F_27 () ;
if ( ! V_42 )
return - V_20 ;
V_42 -> V_93 = 1 ;
V_37 . V_54 = 0 ;
V_37 . V_55 = 0 ;
V_37 . type = 0 ;
while ( 1 ) {
V_46 = F_59 ( V_82 , V_90 , & V_37 , V_42 , - 1 , 1 ) ;
if ( V_46 < 0 )
goto V_52;
V_87 = V_42 -> V_57 [ 0 ] ;
V_92 = F_81 ( V_87 ) ;
if ( ! V_92 )
break;
V_42 -> V_56 [ 0 ] = 0 ;
V_46 = F_82 ( V_82 , V_90 , V_42 , 0 , V_92 ) ;
if ( V_46 )
goto V_52;
F_48 ( V_42 ) ;
}
V_46 = 0 ;
V_52:
V_90 -> V_8 -> V_79 = 0 ;
F_51 ( V_42 ) ;
return V_46 ;
}
int F_83 ( struct V_81 * V_82 ,
struct V_7 * V_8 )
{
struct V_39 * V_40 ;
struct V_39 * V_94 = V_8 -> V_94 ;
struct V_41 * V_42 = NULL ;
struct V_59 * V_60 ;
struct V_43 * V_87 ;
struct V_36 V_37 ;
struct V_36 V_38 ;
struct V_1 * V_13 = NULL ;
int V_46 = 0 ;
int V_45 ;
F_84 ( & V_8 -> V_95 ) ;
if ( V_8 -> V_40 ) {
V_8 -> V_79 = 1 ;
goto V_52;
}
V_8 -> V_50 = F_26 ( V_51 ) ;
if ( ! V_8 -> V_50 ) {
V_46 = - V_20 ;
goto V_52;
}
V_40 = F_85 ( V_82 , V_8 ,
V_96 ) ;
if ( F_36 ( V_40 ) ) {
V_46 = F_37 ( V_40 ) ;
goto V_52;
}
V_42 = F_27 () ;
if ( ! V_42 ) {
V_46 = - V_20 ;
goto V_97;
}
V_37 . V_54 = 0 ;
V_37 . type = V_58 ;
V_37 . V_55 = 0 ;
V_46 = F_56 ( V_82 , V_40 , V_42 , & V_37 ,
sizeof( * V_60 ) ) ;
if ( V_46 )
goto V_98;
V_87 = V_42 -> V_57 [ 0 ] ;
V_60 = F_30 ( V_87 , V_42 -> V_56 [ 0 ] ,
struct V_59 ) ;
F_78 ( V_87 , V_60 , V_82 -> V_89 ) ;
F_86 ( V_87 , V_60 , V_61 ) ;
V_8 -> V_53 = V_78 |
V_63 ;
F_77 ( V_87 , V_60 , V_8 -> V_53 ) ;
F_79 ( V_87 , V_60 , 0 ) ;
F_57 ( V_87 ) ;
V_37 . V_54 = 0 ;
V_37 . type = V_99 ;
V_37 . V_55 = 0 ;
F_48 ( V_42 ) ;
V_46 = F_28 ( V_94 , & V_37 , V_42 , 1 , 0 ) ;
if ( V_46 > 0 )
goto V_100;
if ( V_46 < 0 )
goto V_98;
while ( 1 ) {
V_45 = V_42 -> V_56 [ 0 ] ;
V_87 = V_42 -> V_57 [ 0 ] ;
F_29 ( V_87 , & V_38 , V_45 ) ;
if ( V_38 . type == V_99 ) {
V_46 = F_61 ( V_82 , V_40 ,
V_38 . V_55 ) ;
if ( V_46 )
goto V_98;
V_13 = F_7 ( V_8 , V_38 . V_55 ) ;
if ( F_36 ( V_13 ) ) {
V_46 = F_37 ( V_13 ) ;
goto V_98;
}
}
V_46 = F_47 ( V_94 , V_42 ) ;
if ( V_46 < 0 )
goto V_98;
if ( V_46 )
break;
}
V_100:
F_48 ( V_42 ) ;
V_46 = F_61 ( V_82 , V_40 , V_101 ) ;
if ( V_46 )
goto V_98;
V_13 = F_7 ( V_8 , V_101 ) ;
if ( F_36 ( V_13 ) ) {
V_46 = F_37 ( V_13 ) ;
goto V_98;
}
F_87 ( & V_8 -> V_102 ) ;
V_8 -> V_40 = V_40 ;
V_8 -> V_79 = 1 ;
F_88 ( & V_8 -> V_102 ) ;
V_98:
F_51 ( V_42 ) ;
V_97:
if ( V_46 ) {
F_89 ( V_40 -> V_14 ) ;
F_89 ( V_40 -> V_103 ) ;
F_17 ( V_40 ) ;
}
V_52:
if ( V_46 ) {
F_52 ( V_8 -> V_50 ) ;
V_8 -> V_50 = NULL ;
}
F_90 ( & V_8 -> V_95 ) ;
return V_46 ;
}
int F_91 ( struct V_81 * V_82 ,
struct V_7 * V_8 )
{
struct V_39 * V_94 = V_8 -> V_94 ;
struct V_39 * V_40 ;
int V_46 = 0 ;
F_84 ( & V_8 -> V_95 ) ;
if ( ! V_8 -> V_40 )
goto V_52;
F_87 ( & V_8 -> V_102 ) ;
V_8 -> V_49 = 0 ;
V_8 -> V_79 = 0 ;
V_40 = V_8 -> V_40 ;
V_8 -> V_40 = NULL ;
V_8 -> V_53 &= ~ V_78 ;
F_88 ( & V_8 -> V_102 ) ;
F_53 ( V_8 ) ;
V_46 = F_80 ( V_82 , V_40 ) ;
if ( V_46 )
goto V_52;
V_46 = F_92 ( V_82 , V_94 , & V_40 -> V_104 ) ;
if ( V_46 )
goto V_52;
F_14 ( & V_40 -> V_105 ) ;
F_93 ( V_40 -> V_14 ) ;
F_94 ( V_82 , V_94 -> V_8 , V_40 -> V_14 ) ;
F_95 ( V_40 -> V_14 ) ;
F_96 ( V_82 , V_40 , V_40 -> V_14 , 0 , 1 ) ;
F_89 ( V_40 -> V_14 ) ;
F_89 ( V_40 -> V_103 ) ;
F_17 ( V_40 ) ;
V_52:
F_90 ( & V_8 -> V_95 ) ;
return V_46 ;
}
static void F_97 ( struct V_7 * V_8 ,
struct V_1 * V_13 )
{
if ( F_15 ( & V_13 -> V_23 ) )
F_98 ( & V_13 -> V_23 , & V_8 -> V_106 ) ;
}
static int F_99 ( struct V_7 * V_8 ,
struct V_107 * V_108 , T_1 V_109 ,
T_1 V_110 , int V_111 )
{
struct V_1 * V_13 ;
struct V_24 * V_112 ;
struct V_113 * V_114 ;
struct V_115 V_116 ;
int V_46 = 0 ;
V_13 = F_5 ( V_8 , V_109 ) ;
if ( ! V_13 )
goto V_52;
V_13 -> V_33 += V_111 * V_110 ;
V_13 -> V_68 += V_111 * V_110 ;
F_100 ( V_111 < 0 && V_13 -> V_34 < V_110 ) ;
V_13 -> V_34 += V_111 * V_110 ;
V_13 -> V_69 += V_111 * V_110 ;
if ( V_111 > 0 )
V_13 -> V_117 -= V_110 ;
F_97 ( V_8 , V_13 ) ;
F_23 (glist, &qgroup->groups, next_group) {
V_46 = F_101 ( V_108 , V_112 -> V_32 -> V_9 ,
F_102 ( V_112 -> V_32 ) , V_19 ) ;
if ( V_46 < 0 )
goto V_52;
}
F_103 ( & V_116 ) ;
while ( ( V_114 = F_104 ( V_108 , & V_116 ) ) ) {
V_13 = F_105 ( V_114 -> V_118 ) ;
V_13 -> V_33 += V_111 * V_110 ;
V_13 -> V_68 += V_111 * V_110 ;
F_100 ( V_111 < 0 && V_13 -> V_34 < V_110 ) ;
V_13 -> V_34 += V_111 * V_110 ;
if ( V_111 > 0 )
V_13 -> V_117 -= V_110 ;
V_13 -> V_69 += V_111 * V_110 ;
F_97 ( V_8 , V_13 ) ;
F_23 (glist, &qgroup->groups, next_group) {
V_46 = F_101 ( V_108 , V_112 -> V_32 -> V_9 ,
F_102 ( V_112 -> V_32 ) , V_19 ) ;
if ( V_46 < 0 )
goto V_52;
}
}
V_46 = 0 ;
V_52:
return V_46 ;
}
static int F_106 ( struct V_7 * V_8 ,
struct V_107 * V_108 , T_1 V_83 , T_1 V_84 ,
int V_111 )
{
struct V_1 * V_13 ;
int V_46 = 1 ;
int V_119 = 0 ;
V_13 = F_5 ( V_8 , V_83 ) ;
if ( ! V_13 )
goto V_52;
if ( V_13 -> V_34 == V_13 -> V_33 ) {
V_46 = 0 ;
V_119 = F_99 ( V_8 , V_108 , V_84 ,
V_13 -> V_34 , V_111 ) ;
if ( V_119 < 0 ) {
V_46 = V_119 ;
goto V_52;
}
}
V_52:
if ( V_46 )
V_8 -> V_53 |= V_63 ;
return V_46 ;
}
int F_107 ( struct V_81 * V_82 ,
struct V_7 * V_8 , T_1 V_83 , T_1 V_84 )
{
struct V_39 * V_40 ;
struct V_1 * V_18 ;
struct V_1 * V_31 ;
struct V_24 * V_25 ;
struct V_107 * V_108 ;
int V_46 = 0 ;
if ( F_108 ( V_83 ) >= F_108 ( V_84 ) )
return - V_35 ;
V_108 = F_26 ( V_51 ) ;
if ( ! V_108 )
return - V_20 ;
F_84 ( & V_8 -> V_95 ) ;
V_40 = V_8 -> V_40 ;
if ( ! V_40 ) {
V_46 = - V_35 ;
goto V_52;
}
V_31 = F_5 ( V_8 , V_83 ) ;
V_18 = F_5 ( V_8 , V_84 ) ;
if ( ! V_31 || ! V_18 ) {
V_46 = - V_35 ;
goto V_52;
}
F_23 (list, &member->groups, next_group) {
if ( V_25 -> V_32 == V_18 ) {
V_46 = - V_88 ;
goto V_52;
}
}
V_46 = F_55 ( V_82 , V_40 , V_83 , V_84 ) ;
if ( V_46 )
goto V_52;
V_46 = F_55 ( V_82 , V_40 , V_84 , V_83 ) ;
if ( V_46 ) {
F_58 ( V_82 , V_40 , V_83 , V_84 ) ;
goto V_52;
}
F_87 ( & V_8 -> V_102 ) ;
V_46 = F_20 ( V_40 -> V_8 , V_83 , V_84 ) ;
if ( V_46 < 0 ) {
F_88 ( & V_8 -> V_102 ) ;
goto V_52;
}
V_46 = F_106 ( V_8 , V_108 , V_83 , V_84 , 1 ) ;
F_88 ( & V_8 -> V_102 ) ;
V_52:
F_90 ( & V_8 -> V_95 ) ;
F_52 ( V_108 ) ;
return V_46 ;
}
int F_109 ( struct V_81 * V_82 ,
struct V_7 * V_8 , T_1 V_83 , T_1 V_84 )
{
struct V_39 * V_40 ;
struct V_1 * V_18 ;
struct V_1 * V_31 ;
struct V_24 * V_25 ;
struct V_107 * V_108 ;
int V_46 = 0 ;
int V_119 ;
V_108 = F_26 ( V_51 ) ;
if ( ! V_108 )
return - V_20 ;
V_40 = V_8 -> V_40 ;
if ( ! V_40 ) {
V_46 = - V_35 ;
goto V_52;
}
V_31 = F_5 ( V_8 , V_83 ) ;
V_18 = F_5 ( V_8 , V_84 ) ;
if ( ! V_31 || ! V_18 ) {
V_46 = - V_35 ;
goto V_52;
}
F_23 (list, &member->groups, next_group) {
if ( V_25 -> V_32 == V_18 )
goto V_120;
}
V_46 = - V_28 ;
goto V_52;
V_120:
V_46 = F_58 ( V_82 , V_40 , V_83 , V_84 ) ;
V_119 = F_58 ( V_82 , V_40 , V_84 , V_83 ) ;
if ( V_119 && ! V_46 )
V_46 = V_119 ;
F_87 ( & V_8 -> V_102 ) ;
F_22 ( V_8 , V_83 , V_84 ) ;
V_46 = F_106 ( V_8 , V_108 , V_83 , V_84 , - 1 ) ;
F_88 ( & V_8 -> V_102 ) ;
V_52:
F_52 ( V_108 ) ;
return V_46 ;
}
int F_110 ( struct V_81 * V_82 ,
struct V_7 * V_8 , T_1 V_83 , T_1 V_84 )
{
int V_46 = 0 ;
F_84 ( & V_8 -> V_95 ) ;
V_46 = F_109 ( V_82 , V_8 , V_83 , V_84 ) ;
F_90 ( & V_8 -> V_95 ) ;
return V_46 ;
}
int F_111 ( struct V_81 * V_82 ,
struct V_7 * V_8 , T_1 V_9 )
{
struct V_39 * V_40 ;
struct V_1 * V_13 ;
int V_46 = 0 ;
F_84 ( & V_8 -> V_95 ) ;
V_40 = V_8 -> V_40 ;
if ( ! V_40 ) {
V_46 = - V_35 ;
goto V_52;
}
V_13 = F_5 ( V_8 , V_9 ) ;
if ( V_13 ) {
V_46 = - V_88 ;
goto V_52;
}
V_46 = F_61 ( V_82 , V_40 , V_9 ) ;
if ( V_46 )
goto V_52;
F_87 ( & V_8 -> V_102 ) ;
V_13 = F_7 ( V_8 , V_9 ) ;
F_88 ( & V_8 -> V_102 ) ;
if ( F_36 ( V_13 ) )
V_46 = F_37 ( V_13 ) ;
V_52:
F_90 ( & V_8 -> V_95 ) ;
return V_46 ;
}
int F_112 ( struct V_81 * V_82 ,
struct V_7 * V_8 , T_1 V_9 )
{
struct V_39 * V_40 ;
struct V_1 * V_13 ;
struct V_24 * V_25 ;
int V_46 = 0 ;
F_84 ( & V_8 -> V_95 ) ;
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
V_46 = - V_121 ;
goto V_52;
}
}
V_46 = F_73 ( V_82 , V_40 , V_9 ) ;
while ( ! F_15 ( & V_13 -> V_21 ) ) {
V_25 = F_16 ( & V_13 -> V_21 ,
struct V_24 , V_26 ) ;
V_46 = F_109 ( V_82 , V_8 ,
V_9 ,
V_25 -> V_32 -> V_9 ) ;
if ( V_46 )
goto V_52;
}
F_87 ( & V_8 -> V_102 ) ;
F_18 ( V_40 -> V_8 , V_9 ) ;
F_88 ( & V_8 -> V_102 ) ;
V_52:
F_90 ( & V_8 -> V_95 ) ;
return V_46 ;
}
int F_113 ( struct V_81 * V_82 ,
struct V_7 * V_8 , T_1 V_9 ,
struct V_122 * V_123 )
{
struct V_39 * V_40 ;
struct V_1 * V_13 ;
int V_46 = 0 ;
const T_1 V_124 = - 1 ;
F_84 ( & V_8 -> V_95 ) ;
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
F_87 ( & V_8 -> V_102 ) ;
if ( V_123 -> V_47 & V_125 ) {
if ( V_123 -> V_72 == V_124 ) {
V_13 -> V_71 &= ~ V_125 ;
V_123 -> V_47 &= ~ V_125 ;
V_13 -> V_72 = 0 ;
} else {
V_13 -> V_72 = V_123 -> V_72 ;
}
}
if ( V_123 -> V_47 & V_126 ) {
if ( V_123 -> V_73 == V_124 ) {
V_13 -> V_71 &= ~ V_126 ;
V_123 -> V_47 &= ~ V_126 ;
V_13 -> V_73 = 0 ;
} else {
V_13 -> V_73 = V_123 -> V_73 ;
}
}
if ( V_123 -> V_47 & V_127 ) {
if ( V_123 -> V_74 == V_124 ) {
V_13 -> V_71 &= ~ V_127 ;
V_123 -> V_47 &= ~ V_127 ;
V_13 -> V_74 = 0 ;
} else {
V_13 -> V_74 = V_123 -> V_74 ;
}
}
if ( V_123 -> V_47 & V_128 ) {
if ( V_123 -> V_75 == V_124 ) {
V_13 -> V_71 &= ~ V_128 ;
V_123 -> V_47 &= ~ V_128 ;
V_13 -> V_75 = 0 ;
} else {
V_13 -> V_75 = V_123 -> V_75 ;
}
}
V_13 -> V_71 |= V_123 -> V_47 ;
F_88 ( & V_8 -> V_102 ) ;
V_46 = F_74 ( V_82 , V_40 , V_13 ) ;
if ( V_46 ) {
V_8 -> V_53 |= V_63 ;
F_114 ( V_8 , L_6 ,
V_9 ) ;
}
V_52:
F_90 ( & V_8 -> V_95 ) ;
return V_46 ;
}
int F_115 ( struct V_81 * V_82 ,
struct V_7 * V_8 )
{
struct V_129 * V_130 ;
struct V_131 * V_132 ;
struct V_10 * V_14 ;
T_1 V_133 ;
int V_46 = 0 ;
V_132 = & V_82 -> V_134 -> V_132 ;
V_133 = V_132 -> V_133 ;
V_14 = F_54 ( & V_132 -> V_135 ) ;
while ( V_14 ) {
V_130 = F_6 ( V_14 , struct V_129 ,
V_14 ) ;
V_46 = F_116 ( NULL , V_8 , V_130 -> V_136 , 0 ,
& V_130 -> V_137 ) ;
if ( V_46 < 0 )
break;
if ( V_133 )
F_117 ( V_130 -> V_137 , V_133 , 0 ) ;
V_14 = F_118 ( V_14 ) ;
}
return V_46 ;
}
struct V_129
* F_119 ( struct V_131 * V_132 ,
struct V_129 * V_130 )
{
struct V_10 * * V_17 = & V_132 -> V_135 . V_10 ;
struct V_10 * V_138 = NULL ;
struct V_129 * V_139 ;
T_1 V_136 = V_130 -> V_136 ;
while ( * V_17 ) {
V_138 = * V_17 ;
V_139 = F_6 ( V_138 , struct V_129 ,
V_14 ) ;
if ( V_136 < V_139 -> V_136 )
V_17 = & ( * V_17 ) -> V_15 ;
else if ( V_136 > V_139 -> V_136 )
V_17 = & ( * V_17 ) -> V_16 ;
else
return V_139 ;
}
F_11 ( & V_130 -> V_14 , V_138 , V_17 ) ;
F_12 ( & V_130 -> V_14 , & V_132 -> V_135 ) ;
return NULL ;
}
static int F_120 ( struct V_7 * V_8 ,
struct V_107 * V_140 , struct V_107 * V_108 ,
struct V_107 * V_141 , T_1 V_3 , int V_142 )
{
struct V_113 * V_114 ;
struct V_115 V_116 ;
struct V_113 * V_143 ;
struct V_115 V_144 ;
struct V_1 * V_2 ;
int V_46 = 0 ;
if ( ! V_140 )
return 0 ;
F_103 ( & V_116 ) ;
while ( ( V_114 = F_104 ( V_140 , & V_116 ) ) ) {
V_2 = F_5 ( V_8 , V_114 -> V_145 ) ;
if ( ! V_2 )
continue;
F_121 ( V_108 ) ;
V_46 = F_101 ( V_141 , V_2 -> V_9 , F_102 ( V_2 ) ,
V_19 ) ;
if ( V_46 < 0 )
return V_46 ;
V_46 = F_101 ( V_108 , V_2 -> V_9 , F_102 ( V_2 ) , V_19 ) ;
if ( V_46 < 0 )
return V_46 ;
F_103 ( & V_144 ) ;
while ( ( V_143 = F_104 ( V_108 , & V_144 ) ) ) {
struct V_24 * V_112 ;
V_2 = F_105 ( V_143 -> V_118 ) ;
if ( V_142 )
F_1 ( V_2 , V_3 , 1 ) ;
else
F_2 ( V_2 , V_3 , 1 ) ;
F_23 (glist, &qg->groups, next_group) {
V_46 = F_101 ( V_141 , V_112 -> V_32 -> V_9 ,
F_102 ( V_112 -> V_32 ) ,
V_19 ) ;
if ( V_46 < 0 )
return V_46 ;
V_46 = F_101 ( V_108 , V_112 -> V_32 -> V_9 ,
F_102 ( V_112 -> V_32 ) ,
V_19 ) ;
if ( V_46 < 0 )
return V_46 ;
}
}
}
return 0 ;
}
static int F_122 ( struct V_7 * V_8 ,
struct V_107 * V_141 ,
T_1 V_146 ,
T_1 V_147 ,
T_1 V_110 , T_1 V_3 )
{
struct V_113 * V_114 ;
struct V_115 V_116 ;
struct V_1 * V_2 ;
T_1 V_148 , V_149 ;
F_103 ( & V_116 ) ;
while ( ( V_114 = F_104 ( V_141 , & V_116 ) ) ) {
bool V_23 = false ;
V_2 = F_105 ( V_114 -> V_118 ) ;
V_149 = F_3 ( V_2 , V_3 ) ;
V_148 = F_4 ( V_2 , V_3 ) ;
if ( V_149 == 0 && V_148 > 0 ) {
V_2 -> V_33 += V_110 ;
V_2 -> V_68 += V_110 ;
V_23 = true ;
}
if ( V_149 > 0 && V_148 == 0 ) {
V_2 -> V_33 -= V_110 ;
V_2 -> V_68 -= V_110 ;
V_23 = true ;
}
if ( V_149 == V_146 &&
V_148 < V_147 ) {
if ( V_149 != 0 ) {
V_2 -> V_34 -= V_110 ;
V_2 -> V_69 -= V_110 ;
V_23 = true ;
}
}
if ( V_149 < V_146 &&
V_148 == V_147 ) {
if ( V_148 != 0 ) {
V_2 -> V_34 += V_110 ;
V_2 -> V_69 += V_110 ;
V_23 = true ;
}
}
if ( V_149 == V_146 &&
V_148 == V_147 ) {
if ( V_149 == 0 ) {
if ( V_148 != 0 ) {
V_2 -> V_34 += V_110 ;
V_2 -> V_69 += V_110 ;
V_23 = true ;
}
} else {
if ( V_148 == 0 ) {
V_2 -> V_34 -= V_110 ;
V_2 -> V_69 -= V_110 ;
V_23 = true ;
}
}
}
if ( V_146 == 0 && V_147 == 1 &&
V_148 == V_147 )
V_2 -> V_117 -= V_110 ;
if ( V_23 )
F_97 ( V_8 , V_2 ) ;
}
return 0 ;
}
int
F_123 ( struct V_81 * V_82 ,
struct V_7 * V_8 ,
T_1 V_136 , T_1 V_110 ,
struct V_107 * V_137 , struct V_107 * V_150 )
{
struct V_107 * V_141 = NULL ;
struct V_107 * V_108 = NULL ;
T_1 V_3 ;
T_1 V_147 = 0 ;
T_1 V_146 = 0 ;
int V_46 = 0 ;
if ( V_150 )
V_147 = V_150 -> V_151 ;
if ( V_137 )
V_146 = V_137 -> V_151 ;
if ( ! V_8 -> V_49 )
goto V_152;
F_124 ( ! V_8 -> V_40 ) ;
V_141 = F_26 ( V_51 ) ;
if ( ! V_141 ) {
V_46 = - V_20 ;
goto V_152;
}
V_108 = F_26 ( V_51 ) ;
if ( ! V_108 ) {
V_46 = - V_20 ;
goto V_152;
}
F_84 ( & V_8 -> V_153 ) ;
if ( V_8 -> V_53 & V_80 ) {
if ( V_8 -> V_91 . V_54 <= V_136 ) {
F_90 ( & V_8 -> V_153 ) ;
V_46 = 0 ;
goto V_152;
}
}
F_90 ( & V_8 -> V_153 ) ;
F_87 ( & V_8 -> V_102 ) ;
V_3 = V_8 -> V_154 ;
V_46 = F_120 ( V_8 , V_137 , V_108 , V_141 , V_3 ,
V_155 ) ;
if ( V_46 < 0 )
goto V_52;
V_46 = F_120 ( V_8 , V_150 , V_108 , V_141 , V_3 ,
V_156 ) ;
if ( V_46 < 0 )
goto V_52;
F_122 ( V_8 , V_141 , V_146 , V_147 ,
V_110 , V_3 ) ;
V_8 -> V_154 += F_125 ( V_146 , V_147 ) + 1 ;
V_52:
F_88 ( & V_8 -> V_102 ) ;
V_152:
F_52 ( V_108 ) ;
F_52 ( V_141 ) ;
F_52 ( V_137 ) ;
F_52 ( V_150 ) ;
return V_46 ;
}
int F_126 ( struct V_81 * V_82 ,
struct V_7 * V_8 )
{
struct V_129 * V_130 ;
struct V_131 * V_132 ;
struct V_107 * V_150 = NULL ;
struct V_10 * V_14 ;
T_1 V_133 ;
int V_46 = 0 ;
V_132 = & V_82 -> V_134 -> V_132 ;
V_133 = V_132 -> V_133 ;
while ( ( V_14 = F_54 ( & V_132 -> V_135 ) ) ) {
V_130 = F_6 ( V_14 , struct V_129 ,
V_14 ) ;
if ( ! V_46 ) {
V_46 = F_116 ( V_82 , V_8 ,
V_130 -> V_136 , ( T_1 ) - 1 , & V_150 ) ;
if ( V_46 < 0 )
goto V_157;
if ( V_133 )
F_117 ( V_150 , V_133 , 0 ) ;
V_46 = F_123 ( V_82 , V_8 ,
V_130 -> V_136 , V_130 -> V_110 ,
V_130 -> V_137 , V_150 ) ;
V_130 -> V_137 = NULL ;
V_150 = NULL ;
}
V_157:
F_52 ( V_130 -> V_137 ) ;
F_52 ( V_150 ) ;
V_150 = NULL ;
F_19 ( V_14 , & V_132 -> V_135 ) ;
F_17 ( V_130 ) ;
}
return V_46 ;
}
int F_127 ( struct V_81 * V_82 ,
struct V_7 * V_8 )
{
struct V_39 * V_40 = V_8 -> V_40 ;
int V_46 = 0 ;
int V_158 = 0 ;
if ( ! V_40 )
goto V_52;
if ( ! V_8 -> V_49 && V_8 -> V_79 )
V_158 = 1 ;
V_8 -> V_49 = V_8 -> V_79 ;
F_87 ( & V_8 -> V_102 ) ;
while ( ! F_15 ( & V_8 -> V_106 ) ) {
struct V_1 * V_13 ;
V_13 = F_16 ( & V_8 -> V_106 ,
struct V_1 , V_23 ) ;
F_128 ( & V_13 -> V_23 ) ;
F_88 ( & V_8 -> V_102 ) ;
V_46 = F_75 ( V_82 , V_40 , V_13 ) ;
if ( V_46 )
V_8 -> V_53 |=
V_63 ;
V_46 = F_74 ( V_82 , V_40 , V_13 ) ;
if ( V_46 )
V_8 -> V_53 |=
V_63 ;
F_87 ( & V_8 -> V_102 ) ;
}
if ( V_8 -> V_49 )
V_8 -> V_53 |= V_78 ;
else
V_8 -> V_53 &= ~ V_78 ;
F_88 ( & V_8 -> V_102 ) ;
V_46 = F_76 ( V_82 , V_8 , V_40 ) ;
if ( V_46 )
V_8 -> V_53 |= V_63 ;
if ( ! V_46 && V_158 ) {
V_46 = F_50 ( V_8 , 0 , 1 ) ;
if ( ! V_46 ) {
F_129 ( V_8 ) ;
F_130 ( V_8 -> V_159 ,
& V_8 -> V_160 ) ;
}
V_46 = 0 ;
}
V_52:
return V_46 ;
}
int F_131 ( struct V_81 * V_82 ,
struct V_7 * V_8 , T_1 V_161 , T_1 V_54 ,
struct F_131 * V_162 )
{
int V_46 = 0 ;
int V_163 ;
T_1 * V_164 ;
struct V_39 * V_40 = V_8 -> V_40 ;
struct V_1 * V_165 ;
struct V_1 * V_166 ;
T_2 V_167 = 0 ;
T_1 V_168 ;
F_84 ( & V_8 -> V_95 ) ;
if ( ! V_8 -> V_49 )
goto V_52;
if ( ! V_40 ) {
V_46 = - V_35 ;
goto V_52;
}
if ( V_162 ) {
V_164 = ( T_1 * ) ( V_162 + 1 ) ;
V_168 = V_162 -> V_169 + 2 * V_162 -> V_170 +
2 * V_162 -> V_171 ;
for ( V_163 = 0 ; V_163 < V_168 ; ++ V_163 ) {
V_165 = F_5 ( V_8 , * V_164 ) ;
if ( ! V_165 ) {
V_46 = - V_35 ;
goto V_52;
}
if ( ( V_165 -> V_9 >> 48 ) <= ( V_54 >> 48 ) ) {
V_46 = - V_35 ;
goto V_52;
}
++ V_164 ;
}
}
V_46 = F_61 ( V_82 , V_40 , V_54 ) ;
if ( V_46 )
goto V_52;
if ( V_161 ) {
struct V_39 * V_172 ;
struct V_36 V_173 ;
V_173 . V_54 = V_161 ;
V_173 . type = V_174 ;
V_173 . V_55 = ( T_1 ) - 1 ;
V_172 = F_132 ( V_8 , & V_173 ) ;
if ( F_36 ( V_172 ) ) {
V_46 = F_37 ( V_172 ) ;
goto V_52;
}
F_133 () ;
V_167 = V_172 -> V_175 ;
F_134 () ;
}
if ( V_162 ) {
V_164 = ( T_1 * ) ( V_162 + 1 ) ;
for ( V_163 = 0 ; V_163 < V_162 -> V_169 ; ++ V_163 ) {
V_46 = F_55 ( V_82 , V_40 ,
V_54 , * V_164 ) ;
if ( V_46 )
goto V_52;
V_46 = F_55 ( V_82 , V_40 ,
* V_164 , V_54 ) ;
if ( V_46 )
goto V_52;
++ V_164 ;
}
}
F_87 ( & V_8 -> V_102 ) ;
V_166 = F_7 ( V_8 , V_54 ) ;
if ( F_36 ( V_166 ) ) {
V_46 = F_37 ( V_166 ) ;
goto V_176;
}
if ( V_162 && V_162 -> V_47 & V_177 ) {
V_166 -> V_71 = V_162 -> V_178 . V_47 ;
V_166 -> V_72 = V_162 -> V_178 . V_72 ;
V_166 -> V_73 = V_162 -> V_178 . V_73 ;
V_166 -> V_74 = V_162 -> V_178 . V_74 ;
V_166 -> V_75 = V_162 -> V_178 . V_75 ;
V_46 = F_74 ( V_82 , V_40 , V_166 ) ;
if ( V_46 ) {
V_8 -> V_53 |= V_63 ;
F_114 ( V_8 , L_6 ,
V_166 -> V_9 ) ;
goto V_176;
}
}
if ( V_161 ) {
V_165 = F_5 ( V_8 , V_161 ) ;
if ( ! V_165 )
goto V_176;
V_166 -> V_33 = V_165 -> V_33 ;
V_166 -> V_68 = V_165 -> V_68 ;
V_166 -> V_34 = V_167 ;
V_166 -> V_69 = V_167 ;
V_165 -> V_34 = V_167 ;
V_165 -> V_69 = V_167 ;
V_166 -> V_71 = V_165 -> V_71 ;
V_166 -> V_72 = V_165 -> V_72 ;
V_166 -> V_73 = V_165 -> V_73 ;
V_166 -> V_74 = V_165 -> V_74 ;
V_166 -> V_75 = V_165 -> V_75 ;
F_97 ( V_8 , V_166 ) ;
F_97 ( V_8 , V_165 ) ;
}
if ( ! V_162 )
goto V_176;
V_164 = ( T_1 * ) ( V_162 + 1 ) ;
for ( V_163 = 0 ; V_163 < V_162 -> V_169 ; ++ V_163 ) {
V_46 = F_20 ( V_40 -> V_8 , V_54 ,
* V_164 ) ;
if ( V_46 )
goto V_176;
++ V_164 ;
}
for ( V_163 = 0 ; V_163 < V_162 -> V_170 ; ++ V_163 ) {
struct V_1 * V_83 ;
struct V_1 * V_84 ;
V_83 = F_5 ( V_8 , V_164 [ 0 ] ) ;
V_84 = F_5 ( V_8 , V_164 [ 1 ] ) ;
if ( ! V_83 || ! V_84 ) {
V_46 = - V_35 ;
goto V_176;
}
V_84 -> V_33 = V_83 -> V_33 - V_167 ;
V_84 -> V_68 = V_83 -> V_68 - V_167 ;
V_164 += 2 ;
}
for ( V_163 = 0 ; V_163 < V_162 -> V_171 ; ++ V_163 ) {
struct V_1 * V_83 ;
struct V_1 * V_84 ;
V_83 = F_5 ( V_8 , V_164 [ 0 ] ) ;
V_84 = F_5 ( V_8 , V_164 [ 1 ] ) ;
if ( ! V_83 || ! V_84 ) {
V_46 = - V_35 ;
goto V_176;
}
V_84 -> V_34 = V_83 -> V_34 + V_167 ;
V_84 -> V_69 = V_83 -> V_69 + V_167 ;
V_164 += 2 ;
}
V_176:
F_88 ( & V_8 -> V_102 ) ;
V_52:
F_90 ( & V_8 -> V_95 ) ;
return V_46 ;
}
int F_135 ( struct V_39 * V_90 , T_1 V_110 )
{
struct V_39 * V_40 ;
struct V_1 * V_13 ;
struct V_7 * V_8 = V_90 -> V_8 ;
T_1 V_109 = V_90 -> V_104 . V_54 ;
int V_46 = 0 ;
struct V_113 * V_114 ;
struct V_115 V_116 ;
if ( ! F_136 ( V_109 ) )
return 0 ;
if ( V_110 == 0 )
return 0 ;
F_87 ( & V_8 -> V_102 ) ;
V_40 = V_8 -> V_40 ;
if ( ! V_40 )
goto V_52;
V_13 = F_5 ( V_8 , V_109 ) ;
if ( ! V_13 )
goto V_52;
F_121 ( V_8 -> V_50 ) ;
V_46 = F_101 ( V_8 -> V_50 , V_13 -> V_9 ,
( V_179 ) V_13 , V_19 ) ;
if ( V_46 < 0 )
goto V_52;
F_103 ( & V_116 ) ;
while ( ( V_114 = F_104 ( V_8 -> V_50 , & V_116 ) ) ) {
struct V_1 * V_2 ;
struct V_24 * V_112 ;
V_2 = F_105 ( V_114 -> V_118 ) ;
if ( ( V_2 -> V_71 & V_125 ) &&
V_2 -> V_117 + ( V_180 ) V_2 -> V_33 + V_110 >
V_2 -> V_72 ) {
V_46 = - V_181 ;
goto V_52;
}
if ( ( V_2 -> V_71 & V_126 ) &&
V_2 -> V_117 + ( V_180 ) V_2 -> V_34 + V_110 >
V_2 -> V_73 ) {
V_46 = - V_181 ;
goto V_52;
}
F_23 (glist, &qg->groups, next_group) {
V_46 = F_101 ( V_8 -> V_50 ,
V_112 -> V_32 -> V_9 ,
( V_179 ) V_112 -> V_32 , V_19 ) ;
if ( V_46 < 0 )
goto V_52;
}
}
V_46 = 0 ;
F_103 ( & V_116 ) ;
while ( ( V_114 = F_104 ( V_8 -> V_50 , & V_116 ) ) ) {
struct V_1 * V_2 ;
V_2 = F_105 ( V_114 -> V_118 ) ;
V_2 -> V_117 += V_110 ;
}
V_52:
F_88 ( & V_8 -> V_102 ) ;
return V_46 ;
}
void F_137 ( struct V_39 * V_90 , T_1 V_110 )
{
struct V_39 * V_40 ;
struct V_1 * V_13 ;
struct V_7 * V_8 = V_90 -> V_8 ;
struct V_113 * V_114 ;
struct V_115 V_116 ;
T_1 V_109 = V_90 -> V_104 . V_54 ;
int V_46 = 0 ;
if ( ! F_136 ( V_109 ) )
return;
if ( V_110 == 0 )
return;
F_87 ( & V_8 -> V_102 ) ;
V_40 = V_8 -> V_40 ;
if ( ! V_40 )
goto V_52;
V_13 = F_5 ( V_8 , V_109 ) ;
if ( ! V_13 )
goto V_52;
F_121 ( V_8 -> V_50 ) ;
V_46 = F_101 ( V_8 -> V_50 , V_13 -> V_9 ,
( V_179 ) V_13 , V_19 ) ;
if ( V_46 < 0 )
goto V_52;
F_103 ( & V_116 ) ;
while ( ( V_114 = F_104 ( V_8 -> V_50 , & V_116 ) ) ) {
struct V_1 * V_2 ;
struct V_24 * V_112 ;
V_2 = F_105 ( V_114 -> V_118 ) ;
V_2 -> V_117 -= V_110 ;
F_23 (glist, &qg->groups, next_group) {
V_46 = F_101 ( V_8 -> V_50 ,
V_112 -> V_32 -> V_9 ,
( V_179 ) V_112 -> V_32 , V_19 ) ;
if ( V_46 < 0 )
goto V_52;
}
}
V_52:
F_88 ( & V_8 -> V_102 ) ;
}
void F_138 ( struct V_81 * V_82 )
{
if ( F_15 ( & V_82 -> V_182 ) && ! V_82 -> V_183 . V_3 )
return;
F_32 ( V_82 -> V_90 -> V_8 ,
L_7
L_8 ,
V_82 , F_15 ( & V_82 -> V_182 ) ? L_9 : L_10 ,
( T_2 ) ( V_82 -> V_183 . V_3 >> 32 ) ,
( T_2 ) V_82 -> V_183 . V_3 ) ;
F_139 () ;
}
static int
F_140 ( struct V_7 * V_8 , struct V_41 * V_42 ,
struct V_81 * V_82 ,
struct V_43 * V_184 )
{
struct V_36 V_185 ;
struct V_107 * V_140 = NULL ;
struct V_186 V_187 = F_141 ( V_187 ) ;
T_1 V_110 ;
int V_45 ;
int V_46 ;
V_42 -> V_93 = 1 ;
F_84 ( & V_8 -> V_153 ) ;
V_46 = F_28 ( V_8 -> V_188 ,
& V_8 -> V_91 ,
V_42 , 1 , 0 ) ;
F_142 ( L_11 ,
V_8 -> V_91 . V_54 ,
V_8 -> V_91 . type ,
V_8 -> V_91 . V_55 , V_46 ) ;
if ( V_46 ) {
V_8 -> V_91 . V_54 = ( T_1 ) - 1 ;
F_48 ( V_42 ) ;
F_90 ( & V_8 -> V_153 ) ;
return V_46 ;
}
F_29 ( V_42 -> V_57 [ 0 ] , & V_185 ,
F_81 ( V_42 -> V_57 [ 0 ] ) - 1 ) ;
V_8 -> V_91 . V_54 = V_185 . V_54 + 1 ;
F_143 ( V_8 , & V_187 ) ;
memcpy ( V_184 , V_42 -> V_57 [ 0 ] , sizeof( * V_184 ) ) ;
V_45 = V_42 -> V_56 [ 0 ] ;
F_48 ( V_42 ) ;
F_90 ( & V_8 -> V_153 ) ;
for (; V_45 < F_81 ( V_184 ) ; ++ V_45 ) {
F_29 ( V_184 , & V_185 , V_45 ) ;
if ( V_185 . type != V_189 &&
V_185 . type != V_190 )
continue;
if ( V_185 . type == V_190 )
V_110 = V_8 -> V_188 -> V_175 ;
else
V_110 = V_185 . V_55 ;
V_46 = F_116 ( NULL , V_8 , V_185 . V_54 , 0 ,
& V_140 ) ;
if ( V_46 < 0 )
goto V_52;
V_46 = F_123 ( V_82 , V_8 ,
V_185 . V_54 , V_110 , NULL , V_140 ) ;
if ( V_46 < 0 )
goto V_52;
}
V_52:
F_144 ( V_8 , & V_187 ) ;
return V_46 ;
}
static void F_145 ( struct V_191 * V_192 )
{
struct V_7 * V_8 = F_146 ( V_192 , struct V_7 ,
V_160 ) ;
struct V_41 * V_42 ;
struct V_81 * V_82 = NULL ;
struct V_43 * V_184 = NULL ;
int V_119 = - V_20 ;
int V_46 = 0 ;
V_42 = F_27 () ;
if ( ! V_42 )
goto V_52;
V_184 = F_147 ( sizeof( * V_184 ) , V_51 ) ;
if ( ! V_184 )
goto V_52;
V_119 = 0 ;
while ( ! V_119 ) {
V_82 = F_148 ( V_8 -> V_193 , 0 ) ;
if ( F_36 ( V_82 ) ) {
V_119 = F_37 ( V_82 ) ;
break;
}
if ( ! V_8 -> V_49 ) {
V_119 = - V_194 ;
} else {
V_119 = F_140 ( V_8 , V_42 , V_82 ,
V_184 ) ;
}
if ( V_119 > 0 )
F_149 ( V_82 , V_8 -> V_193 ) ;
else
F_150 ( V_82 , V_8 -> V_193 ) ;
}
V_52:
F_17 ( V_184 ) ;
F_51 ( V_42 ) ;
F_84 ( & V_8 -> V_153 ) ;
V_8 -> V_53 &= ~ V_80 ;
if ( V_119 > 0 &&
V_8 -> V_53 & V_63 ) {
V_8 -> V_53 &= ~ V_63 ;
} else if ( V_119 < 0 ) {
V_8 -> V_53 |= V_63 ;
}
F_90 ( & V_8 -> V_153 ) ;
V_82 = F_148 ( V_8 -> V_40 , 1 ) ;
if ( F_36 ( V_82 ) ) {
V_119 = F_37 ( V_82 ) ;
F_32 ( V_8 ,
L_12 ,
V_119 ) ;
goto V_195;
}
V_46 = F_76 ( V_82 , V_8 , V_8 -> V_40 ) ;
if ( V_46 < 0 ) {
V_119 = V_46 ;
F_32 ( V_8 , L_13 , V_119 ) ;
}
F_150 ( V_82 , V_8 -> V_40 ) ;
if ( V_119 >= 0 ) {
F_114 ( V_8 , L_14 ,
V_119 > 0 ? L_15 : L_9 ) ;
} else {
F_32 ( V_8 , L_16 , V_119 ) ;
}
V_195:
F_151 ( & V_8 -> V_196 ) ;
}
static int
F_50 ( struct V_7 * V_8 , T_1 V_197 ,
int V_198 )
{
int V_46 = 0 ;
if ( ! V_198 &&
( ! ( V_8 -> V_53 & V_80 ) ||
! ( V_8 -> V_53 & V_78 ) ) ) {
V_46 = - V_35 ;
goto V_119;
}
F_84 ( & V_8 -> V_153 ) ;
F_87 ( & V_8 -> V_102 ) ;
if ( V_198 ) {
if ( V_8 -> V_53 & V_80 )
V_46 = - V_199 ;
else if ( ! ( V_8 -> V_53 & V_78 ) )
V_46 = - V_35 ;
if ( V_46 ) {
F_88 ( & V_8 -> V_102 ) ;
F_90 ( & V_8 -> V_153 ) ;
goto V_119;
}
V_8 -> V_53 |= V_80 ;
}
memset ( & V_8 -> V_91 , 0 ,
sizeof( V_8 -> V_91 ) ) ;
V_8 -> V_91 . V_54 = V_197 ;
F_88 ( & V_8 -> V_102 ) ;
F_90 ( & V_8 -> V_153 ) ;
F_152 ( & V_8 -> V_196 ) ;
memset ( & V_8 -> V_160 , 0 ,
sizeof( V_8 -> V_160 ) ) ;
F_153 ( & V_8 -> V_160 ,
V_200 ,
F_145 , NULL , NULL ) ;
if ( V_46 ) {
V_119:
F_114 ( V_8 , L_17 , V_46 ) ;
return V_46 ;
}
return 0 ;
}
static void
F_129 ( struct V_7 * V_8 )
{
struct V_10 * V_11 ;
struct V_1 * V_13 ;
F_87 ( & V_8 -> V_102 ) ;
for ( V_11 = F_54 ( & V_8 -> V_12 ) ; V_11 ; V_11 = F_118 ( V_11 ) ) {
V_13 = F_6 ( V_11 , struct V_1 , V_14 ) ;
V_13 -> V_33 = 0 ;
V_13 -> V_68 = 0 ;
V_13 -> V_34 = 0 ;
V_13 -> V_69 = 0 ;
}
F_88 ( & V_8 -> V_102 ) ;
}
int
F_154 ( struct V_7 * V_8 )
{
int V_46 = 0 ;
struct V_81 * V_82 ;
V_46 = F_50 ( V_8 , 0 , 1 ) ;
if ( V_46 )
return V_46 ;
V_82 = F_155 ( V_8 -> V_193 ) ;
if ( F_36 ( V_82 ) ) {
V_8 -> V_53 &= ~ V_80 ;
return F_37 ( V_82 ) ;
}
V_46 = F_149 ( V_82 , V_8 -> V_193 ) ;
if ( V_46 ) {
V_8 -> V_53 &= ~ V_80 ;
return V_46 ;
}
F_129 ( V_8 ) ;
F_130 ( V_8 -> V_159 ,
& V_8 -> V_160 ) ;
return 0 ;
}
int F_156 ( struct V_7 * V_8 )
{
int V_201 ;
int V_46 = 0 ;
F_84 ( & V_8 -> V_153 ) ;
F_87 ( & V_8 -> V_102 ) ;
V_201 = V_8 -> V_53 & V_80 ;
F_88 ( & V_8 -> V_102 ) ;
F_90 ( & V_8 -> V_153 ) ;
if ( V_201 )
V_46 = F_157 (
& V_8 -> V_196 ) ;
return V_46 ;
}
void
F_158 ( struct V_7 * V_8 )
{
if ( V_8 -> V_53 & V_80 )
F_130 ( V_8 -> V_159 ,
& V_8 -> V_160 ) ;
}
