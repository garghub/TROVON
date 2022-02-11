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
if ( F_62 ( V_40 -> V_8 ) )
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
if ( F_62 ( V_90 -> V_8 ) )
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
V_8 -> V_49 = 0 ;
V_8 -> V_79 = 0 ;
F_92 ( V_8 , false ) ;
F_87 ( & V_8 -> V_102 ) ;
V_40 = V_8 -> V_40 ;
V_8 -> V_40 = NULL ;
V_8 -> V_53 &= ~ V_78 ;
F_88 ( & V_8 -> V_102 ) ;
F_53 ( V_8 ) ;
V_46 = F_80 ( V_82 , V_40 ) ;
if ( V_46 )
goto V_52;
V_46 = F_93 ( V_82 , V_94 , & V_40 -> V_104 ) ;
if ( V_46 )
goto V_52;
F_14 ( & V_40 -> V_105 ) ;
F_94 ( V_40 -> V_14 ) ;
F_95 ( V_82 , V_94 -> V_8 , V_40 -> V_14 ) ;
F_96 ( V_40 -> V_14 ) ;
F_97 ( V_82 , V_40 , V_40 -> V_14 , 0 , 1 ) ;
F_89 ( V_40 -> V_14 ) ;
F_89 ( V_40 -> V_103 ) ;
F_17 ( V_40 ) ;
V_52:
F_90 ( & V_8 -> V_95 ) ;
return V_46 ;
}
static void F_98 ( struct V_7 * V_8 ,
struct V_1 * V_13 )
{
if ( F_15 ( & V_13 -> V_23 ) )
F_99 ( & V_13 -> V_23 , & V_8 -> V_106 ) ;
}
static int F_100 ( struct V_7 * V_8 ,
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
F_101 ( V_111 < 0 && V_13 -> V_34 < V_110 ) ;
V_13 -> V_34 += V_111 * V_110 ;
V_13 -> V_69 += V_111 * V_110 ;
if ( V_111 > 0 )
V_13 -> V_117 -= V_110 ;
F_98 ( V_8 , V_13 ) ;
F_23 (glist, &qgroup->groups, next_group) {
V_46 = F_102 ( V_108 , V_112 -> V_32 -> V_9 ,
F_103 ( V_112 -> V_32 ) , V_19 ) ;
if ( V_46 < 0 )
goto V_52;
}
F_104 ( & V_116 ) ;
while ( ( V_114 = F_105 ( V_108 , & V_116 ) ) ) {
V_13 = F_106 ( V_114 -> V_118 ) ;
V_13 -> V_33 += V_111 * V_110 ;
V_13 -> V_68 += V_111 * V_110 ;
F_101 ( V_111 < 0 && V_13 -> V_34 < V_110 ) ;
V_13 -> V_34 += V_111 * V_110 ;
if ( V_111 > 0 )
V_13 -> V_117 -= V_110 ;
V_13 -> V_69 += V_111 * V_110 ;
F_98 ( V_8 , V_13 ) ;
F_23 (glist, &qgroup->groups, next_group) {
V_46 = F_102 ( V_108 , V_112 -> V_32 -> V_9 ,
F_103 ( V_112 -> V_32 ) , V_19 ) ;
if ( V_46 < 0 )
goto V_52;
}
}
V_46 = 0 ;
V_52:
return V_46 ;
}
static int F_107 ( struct V_7 * V_8 ,
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
V_119 = F_100 ( V_8 , V_108 , V_84 ,
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
int F_108 ( struct V_81 * V_82 ,
struct V_7 * V_8 , T_1 V_83 , T_1 V_84 )
{
struct V_39 * V_40 ;
struct V_1 * V_18 ;
struct V_1 * V_31 ;
struct V_24 * V_25 ;
struct V_107 * V_108 ;
int V_46 = 0 ;
if ( F_109 ( V_83 ) >= F_109 ( V_84 ) )
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
V_46 = F_107 ( V_8 , V_108 , V_83 , V_84 , 1 ) ;
F_88 ( & V_8 -> V_102 ) ;
V_52:
F_90 ( & V_8 -> V_95 ) ;
F_52 ( V_108 ) ;
return V_46 ;
}
int F_110 ( struct V_81 * V_82 ,
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
V_46 = F_107 ( V_8 , V_108 , V_83 , V_84 , - 1 ) ;
F_88 ( & V_8 -> V_102 ) ;
V_52:
F_52 ( V_108 ) ;
return V_46 ;
}
int F_111 ( struct V_81 * V_82 ,
struct V_7 * V_8 , T_1 V_83 , T_1 V_84 )
{
int V_46 = 0 ;
F_84 ( & V_8 -> V_95 ) ;
V_46 = F_110 ( V_82 , V_8 , V_83 , V_84 ) ;
F_90 ( & V_8 -> V_95 ) ;
return V_46 ;
}
int F_112 ( struct V_81 * V_82 ,
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
int F_113 ( struct V_81 * V_82 ,
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
V_46 = F_110 ( V_82 , V_8 ,
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
int F_114 ( struct V_81 * V_82 ,
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
F_115 ( V_8 , L_6 ,
V_9 ) ;
}
V_52:
F_90 ( & V_8 -> V_95 ) ;
return V_46 ;
}
int F_116 ( struct V_81 * V_82 ,
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
V_46 = F_117 ( NULL , V_8 , V_130 -> V_136 , 0 ,
& V_130 -> V_137 ) ;
if ( V_46 < 0 )
break;
if ( V_133 )
F_118 ( V_130 -> V_137 , V_133 , 0 ) ;
V_14 = F_119 ( V_14 ) ;
}
return V_46 ;
}
int F_120 ( struct V_7 * V_8 ,
struct V_131 * V_132 ,
struct V_129 * V_130 )
{
struct V_10 * * V_17 = & V_132 -> V_135 . V_10 ;
struct V_10 * V_138 = NULL ;
struct V_129 * V_139 ;
T_1 V_136 = V_130 -> V_136 ;
F_121 ( & V_132 -> V_140 ) ;
F_122 ( V_8 , V_130 ) ;
while ( * V_17 ) {
V_138 = * V_17 ;
V_139 = F_6 ( V_138 , struct V_129 ,
V_14 ) ;
if ( V_136 < V_139 -> V_136 )
V_17 = & ( * V_17 ) -> V_15 ;
else if ( V_136 > V_139 -> V_136 )
V_17 = & ( * V_17 ) -> V_16 ;
else
return 1 ;
}
F_11 ( & V_130 -> V_14 , V_138 , V_17 ) ;
F_12 ( & V_130 -> V_14 , & V_132 -> V_135 ) ;
return 0 ;
}
int F_123 ( struct V_81 * V_82 ,
struct V_7 * V_8 , T_1 V_136 , T_1 V_110 ,
T_2 V_141 )
{
struct V_129 * V_130 ;
struct V_131 * V_132 ;
int V_46 ;
if ( ! V_8 -> V_49 || V_136 == 0 || V_110 == 0 )
return 0 ;
if ( F_101 ( V_82 == NULL ) )
return - V_35 ;
V_130 = F_124 ( sizeof( * V_130 ) , V_141 ) ;
if ( ! V_130 )
return - V_20 ;
V_132 = & V_82 -> V_134 -> V_132 ;
V_130 -> V_136 = V_136 ;
V_130 -> V_110 = V_110 ;
V_130 -> V_137 = NULL ;
F_87 ( & V_132 -> V_140 ) ;
V_46 = F_120 ( V_8 , V_132 ,
V_130 ) ;
F_88 ( & V_132 -> V_140 ) ;
if ( V_46 > 0 )
F_17 ( V_130 ) ;
return 0 ;
}
static int F_125 ( struct V_7 * V_8 ,
struct V_107 * V_142 , struct V_107 * V_108 ,
struct V_107 * V_143 , T_1 V_3 , int V_144 )
{
struct V_113 * V_114 ;
struct V_115 V_116 ;
struct V_113 * V_145 ;
struct V_115 V_146 ;
struct V_1 * V_2 ;
int V_46 = 0 ;
if ( ! V_142 )
return 0 ;
F_104 ( & V_116 ) ;
while ( ( V_114 = F_105 ( V_142 , & V_116 ) ) ) {
V_2 = F_5 ( V_8 , V_114 -> V_147 ) ;
if ( ! V_2 )
continue;
F_126 ( V_108 ) ;
V_46 = F_102 ( V_143 , V_2 -> V_9 , F_103 ( V_2 ) ,
V_19 ) ;
if ( V_46 < 0 )
return V_46 ;
V_46 = F_102 ( V_108 , V_2 -> V_9 , F_103 ( V_2 ) , V_19 ) ;
if ( V_46 < 0 )
return V_46 ;
F_104 ( & V_146 ) ;
while ( ( V_145 = F_105 ( V_108 , & V_146 ) ) ) {
struct V_24 * V_112 ;
V_2 = F_106 ( V_145 -> V_118 ) ;
if ( V_144 )
F_1 ( V_2 , V_3 , 1 ) ;
else
F_2 ( V_2 , V_3 , 1 ) ;
F_23 (glist, &qg->groups, next_group) {
V_46 = F_102 ( V_143 , V_112 -> V_32 -> V_9 ,
F_103 ( V_112 -> V_32 ) ,
V_19 ) ;
if ( V_46 < 0 )
return V_46 ;
V_46 = F_102 ( V_108 , V_112 -> V_32 -> V_9 ,
F_103 ( V_112 -> V_32 ) ,
V_19 ) ;
if ( V_46 < 0 )
return V_46 ;
}
}
}
return 0 ;
}
static int F_127 ( struct V_7 * V_8 ,
struct V_107 * V_143 ,
T_1 V_148 ,
T_1 V_149 ,
T_1 V_110 , T_1 V_3 )
{
struct V_113 * V_114 ;
struct V_115 V_116 ;
struct V_1 * V_2 ;
T_1 V_150 , V_151 ;
F_104 ( & V_116 ) ;
while ( ( V_114 = F_105 ( V_143 , & V_116 ) ) ) {
bool V_23 = false ;
V_2 = F_106 ( V_114 -> V_118 ) ;
V_151 = F_3 ( V_2 , V_3 ) ;
V_150 = F_4 ( V_2 , V_3 ) ;
F_128 ( V_8 , V_2 -> V_9 ,
V_151 , V_150 ) ;
if ( V_151 == 0 && V_150 > 0 ) {
V_2 -> V_33 += V_110 ;
V_2 -> V_68 += V_110 ;
V_23 = true ;
}
if ( V_151 > 0 && V_150 == 0 ) {
V_2 -> V_33 -= V_110 ;
V_2 -> V_68 -= V_110 ;
V_23 = true ;
}
if ( V_151 == V_148 &&
V_150 < V_149 ) {
if ( V_151 != 0 ) {
V_2 -> V_34 -= V_110 ;
V_2 -> V_69 -= V_110 ;
V_23 = true ;
}
}
if ( V_151 < V_148 &&
V_150 == V_149 ) {
if ( V_150 != 0 ) {
V_2 -> V_34 += V_110 ;
V_2 -> V_69 += V_110 ;
V_23 = true ;
}
}
if ( V_151 == V_148 &&
V_150 == V_149 ) {
if ( V_151 == 0 ) {
if ( V_150 != 0 ) {
V_2 -> V_34 += V_110 ;
V_2 -> V_69 += V_110 ;
V_23 = true ;
}
} else {
if ( V_150 == 0 ) {
V_2 -> V_34 -= V_110 ;
V_2 -> V_69 -= V_110 ;
V_23 = true ;
}
}
}
if ( V_23 )
F_98 ( V_8 , V_2 ) ;
}
return 0 ;
}
int
F_129 ( struct V_81 * V_82 ,
struct V_7 * V_8 ,
T_1 V_136 , T_1 V_110 ,
struct V_107 * V_137 , struct V_107 * V_152 )
{
struct V_107 * V_143 = NULL ;
struct V_107 * V_108 = NULL ;
T_1 V_3 ;
T_1 V_149 = 0 ;
T_1 V_148 = 0 ;
int V_46 = 0 ;
if ( V_152 )
V_149 = V_152 -> V_153 ;
if ( V_137 )
V_148 = V_137 -> V_153 ;
if ( ! V_8 -> V_49 )
goto V_154;
F_130 ( ! V_8 -> V_40 ) ;
F_131 ( V_8 , V_136 , V_110 ,
V_148 , V_149 ) ;
V_143 = F_26 ( V_51 ) ;
if ( ! V_143 ) {
V_46 = - V_20 ;
goto V_154;
}
V_108 = F_26 ( V_51 ) ;
if ( ! V_108 ) {
V_46 = - V_20 ;
goto V_154;
}
F_84 ( & V_8 -> V_155 ) ;
if ( V_8 -> V_53 & V_80 ) {
if ( V_8 -> V_91 . V_54 <= V_136 ) {
F_90 ( & V_8 -> V_155 ) ;
V_46 = 0 ;
goto V_154;
}
}
F_90 ( & V_8 -> V_155 ) ;
F_87 ( & V_8 -> V_102 ) ;
V_3 = V_8 -> V_156 ;
V_46 = F_125 ( V_8 , V_137 , V_108 , V_143 , V_3 ,
V_157 ) ;
if ( V_46 < 0 )
goto V_52;
V_46 = F_125 ( V_8 , V_152 , V_108 , V_143 , V_3 ,
V_158 ) ;
if ( V_46 < 0 )
goto V_52;
F_127 ( V_8 , V_143 , V_148 , V_149 ,
V_110 , V_3 ) ;
V_8 -> V_156 += F_132 ( V_148 , V_149 ) + 1 ;
V_52:
F_88 ( & V_8 -> V_102 ) ;
V_154:
F_52 ( V_108 ) ;
F_52 ( V_143 ) ;
F_52 ( V_137 ) ;
F_52 ( V_152 ) ;
return V_46 ;
}
int F_133 ( struct V_81 * V_82 ,
struct V_7 * V_8 )
{
struct V_129 * V_130 ;
struct V_131 * V_132 ;
struct V_107 * V_152 = NULL ;
struct V_10 * V_14 ;
T_1 V_133 ;
int V_46 = 0 ;
V_132 = & V_82 -> V_134 -> V_132 ;
V_133 = V_132 -> V_133 ;
while ( ( V_14 = F_54 ( & V_132 -> V_135 ) ) ) {
V_130 = F_6 ( V_14 , struct V_129 ,
V_14 ) ;
F_134 ( V_8 , V_130 ) ;
if ( ! V_46 ) {
V_46 = F_117 ( V_82 , V_8 ,
V_130 -> V_136 , ( T_1 ) - 1 , & V_152 ) ;
if ( V_46 < 0 )
goto V_159;
if ( V_133 )
F_118 ( V_152 , V_133 , 0 ) ;
V_46 = F_129 ( V_82 , V_8 ,
V_130 -> V_136 , V_130 -> V_110 ,
V_130 -> V_137 , V_152 ) ;
V_130 -> V_137 = NULL ;
V_152 = NULL ;
}
V_159:
F_52 ( V_130 -> V_137 ) ;
F_52 ( V_152 ) ;
V_152 = NULL ;
F_19 ( V_14 , & V_132 -> V_135 ) ;
F_17 ( V_130 ) ;
}
return V_46 ;
}
int F_135 ( struct V_81 * V_82 ,
struct V_7 * V_8 )
{
struct V_39 * V_40 = V_8 -> V_40 ;
int V_46 = 0 ;
int V_160 = 0 ;
if ( ! V_40 )
goto V_52;
if ( ! V_8 -> V_49 && V_8 -> V_79 )
V_160 = 1 ;
V_8 -> V_49 = V_8 -> V_79 ;
F_87 ( & V_8 -> V_102 ) ;
while ( ! F_15 ( & V_8 -> V_106 ) ) {
struct V_1 * V_13 ;
V_13 = F_16 ( & V_8 -> V_106 ,
struct V_1 , V_23 ) ;
F_136 ( & V_13 -> V_23 ) ;
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
if ( ! V_46 && V_160 ) {
V_46 = F_50 ( V_8 , 0 , 1 ) ;
if ( ! V_46 ) {
F_137 ( V_8 ) ;
F_138 ( V_8 -> V_161 ,
& V_8 -> V_162 ) ;
}
V_46 = 0 ;
}
V_52:
return V_46 ;
}
int F_139 ( struct V_81 * V_82 ,
struct V_7 * V_8 , T_1 V_163 , T_1 V_54 ,
struct F_139 * V_164 )
{
int V_46 = 0 ;
int V_165 ;
T_1 * V_166 ;
struct V_39 * V_40 = V_8 -> V_40 ;
struct V_1 * V_167 ;
struct V_1 * V_168 ;
T_3 V_169 = 0 ;
T_1 V_170 ;
F_84 ( & V_8 -> V_95 ) ;
if ( ! V_8 -> V_49 )
goto V_52;
if ( ! V_40 ) {
V_46 = - V_35 ;
goto V_52;
}
if ( V_164 ) {
V_166 = ( T_1 * ) ( V_164 + 1 ) ;
V_170 = V_164 -> V_171 + 2 * V_164 -> V_172 +
2 * V_164 -> V_173 ;
for ( V_165 = 0 ; V_165 < V_170 ; ++ V_165 ) {
V_167 = F_5 ( V_8 , * V_166 ) ;
if ( ! V_167 ||
( ( V_167 -> V_9 >> 48 ) <= ( V_54 >> 48 ) ) )
* V_166 = 0ULL ;
++ V_166 ;
}
}
V_46 = F_61 ( V_82 , V_40 , V_54 ) ;
if ( V_46 )
goto V_52;
if ( V_163 ) {
struct V_39 * V_174 ;
struct V_36 V_175 ;
V_175 . V_54 = V_163 ;
V_175 . type = V_176 ;
V_175 . V_55 = ( T_1 ) - 1 ;
V_174 = F_140 ( V_8 , & V_175 ) ;
if ( F_36 ( V_174 ) ) {
V_46 = F_37 ( V_174 ) ;
goto V_52;
}
F_141 () ;
V_169 = V_174 -> V_177 ;
F_142 () ;
}
if ( V_164 ) {
V_166 = ( T_1 * ) ( V_164 + 1 ) ;
for ( V_165 = 0 ; V_165 < V_164 -> V_171 ; ++ V_165 , ++ V_166 ) {
if ( * V_166 == 0 )
continue;
V_46 = F_55 ( V_82 , V_40 ,
V_54 , * V_166 ) ;
if ( V_46 && V_46 != - V_88 )
goto V_52;
V_46 = F_55 ( V_82 , V_40 ,
* V_166 , V_54 ) ;
if ( V_46 && V_46 != - V_88 )
goto V_52;
}
V_46 = 0 ;
}
F_87 ( & V_8 -> V_102 ) ;
V_168 = F_7 ( V_8 , V_54 ) ;
if ( F_36 ( V_168 ) ) {
V_46 = F_37 ( V_168 ) ;
goto V_178;
}
if ( V_164 && V_164 -> V_47 & V_179 ) {
V_168 -> V_71 = V_164 -> V_180 . V_47 ;
V_168 -> V_72 = V_164 -> V_180 . V_72 ;
V_168 -> V_73 = V_164 -> V_180 . V_73 ;
V_168 -> V_74 = V_164 -> V_180 . V_74 ;
V_168 -> V_75 = V_164 -> V_180 . V_75 ;
V_46 = F_74 ( V_82 , V_40 , V_168 ) ;
if ( V_46 ) {
V_8 -> V_53 |= V_63 ;
F_115 ( V_8 , L_6 ,
V_168 -> V_9 ) ;
goto V_178;
}
}
if ( V_163 ) {
V_167 = F_5 ( V_8 , V_163 ) ;
if ( ! V_167 )
goto V_178;
V_168 -> V_33 = V_167 -> V_33 ;
V_168 -> V_68 = V_167 -> V_68 ;
V_168 -> V_34 = V_169 ;
V_168 -> V_69 = V_169 ;
V_167 -> V_34 = V_169 ;
V_167 -> V_69 = V_169 ;
V_168 -> V_71 = V_167 -> V_71 ;
V_168 -> V_72 = V_167 -> V_72 ;
V_168 -> V_73 = V_167 -> V_73 ;
V_168 -> V_74 = V_167 -> V_74 ;
V_168 -> V_75 = V_167 -> V_75 ;
F_98 ( V_8 , V_168 ) ;
F_98 ( V_8 , V_167 ) ;
}
if ( ! V_164 )
goto V_178;
V_166 = ( T_1 * ) ( V_164 + 1 ) ;
for ( V_165 = 0 ; V_165 < V_164 -> V_171 ; ++ V_165 ) {
if ( * V_166 ) {
V_46 = F_20 ( V_40 -> V_8 , V_54 ,
* V_166 ) ;
if ( V_46 )
goto V_178;
}
++ V_166 ;
}
for ( V_165 = 0 ; V_165 < V_164 -> V_172 ; ++ V_165 , V_166 += 2 ) {
struct V_1 * V_83 ;
struct V_1 * V_84 ;
if ( ! V_166 [ 0 ] || ! V_166 [ 1 ] )
continue;
V_83 = F_5 ( V_8 , V_166 [ 0 ] ) ;
V_84 = F_5 ( V_8 , V_166 [ 1 ] ) ;
if ( ! V_83 || ! V_84 ) {
V_46 = - V_35 ;
goto V_178;
}
V_84 -> V_33 = V_83 -> V_33 - V_169 ;
V_84 -> V_68 = V_83 -> V_68 - V_169 ;
}
for ( V_165 = 0 ; V_165 < V_164 -> V_173 ; ++ V_165 , V_166 += 2 ) {
struct V_1 * V_83 ;
struct V_1 * V_84 ;
if ( ! V_166 [ 0 ] || ! V_166 [ 1 ] )
continue;
V_83 = F_5 ( V_8 , V_166 [ 0 ] ) ;
V_84 = F_5 ( V_8 , V_166 [ 1 ] ) ;
if ( ! V_83 || ! V_84 ) {
V_46 = - V_35 ;
goto V_178;
}
V_84 -> V_34 = V_83 -> V_34 + V_169 ;
V_84 -> V_69 = V_83 -> V_69 + V_169 ;
}
V_178:
F_88 ( & V_8 -> V_102 ) ;
V_52:
F_90 ( & V_8 -> V_95 ) ;
return V_46 ;
}
static int F_143 ( struct V_39 * V_90 , T_1 V_110 )
{
struct V_39 * V_40 ;
struct V_1 * V_13 ;
struct V_7 * V_8 = V_90 -> V_8 ;
T_1 V_109 = V_90 -> V_104 . V_54 ;
int V_46 = 0 ;
struct V_113 * V_114 ;
struct V_115 V_116 ;
if ( ! F_144 ( V_109 ) )
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
F_126 ( V_8 -> V_50 ) ;
V_46 = F_102 ( V_8 -> V_50 , V_13 -> V_9 ,
( V_181 ) V_13 , V_19 ) ;
if ( V_46 < 0 )
goto V_52;
F_104 ( & V_116 ) ;
while ( ( V_114 = F_105 ( V_8 -> V_50 , & V_116 ) ) ) {
struct V_1 * V_2 ;
struct V_24 * V_112 ;
V_2 = F_106 ( V_114 -> V_118 ) ;
if ( ( V_2 -> V_71 & V_125 ) &&
V_2 -> V_117 + ( V_182 ) V_2 -> V_33 + V_110 >
V_2 -> V_72 ) {
V_46 = - V_183 ;
goto V_52;
}
if ( ( V_2 -> V_71 & V_126 ) &&
V_2 -> V_117 + ( V_182 ) V_2 -> V_34 + V_110 >
V_2 -> V_73 ) {
V_46 = - V_183 ;
goto V_52;
}
F_23 (glist, &qg->groups, next_group) {
V_46 = F_102 ( V_8 -> V_50 ,
V_112 -> V_32 -> V_9 ,
( V_181 ) V_112 -> V_32 , V_19 ) ;
if ( V_46 < 0 )
goto V_52;
}
}
V_46 = 0 ;
F_104 ( & V_116 ) ;
while ( ( V_114 = F_105 ( V_8 -> V_50 , & V_116 ) ) ) {
struct V_1 * V_2 ;
V_2 = F_106 ( V_114 -> V_118 ) ;
V_2 -> V_117 += V_110 ;
}
V_52:
F_88 ( & V_8 -> V_102 ) ;
return V_46 ;
}
void F_145 ( struct V_7 * V_8 ,
T_1 V_109 , T_1 V_110 )
{
struct V_39 * V_40 ;
struct V_1 * V_13 ;
struct V_113 * V_114 ;
struct V_115 V_116 ;
int V_46 = 0 ;
if ( ! F_144 ( V_109 ) )
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
F_126 ( V_8 -> V_50 ) ;
V_46 = F_102 ( V_8 -> V_50 , V_13 -> V_9 ,
( V_181 ) V_13 , V_19 ) ;
if ( V_46 < 0 )
goto V_52;
F_104 ( & V_116 ) ;
while ( ( V_114 = F_105 ( V_8 -> V_50 , & V_116 ) ) ) {
struct V_1 * V_2 ;
struct V_24 * V_112 ;
V_2 = F_106 ( V_114 -> V_118 ) ;
V_2 -> V_117 -= V_110 ;
F_23 (glist, &qg->groups, next_group) {
V_46 = F_102 ( V_8 -> V_50 ,
V_112 -> V_32 -> V_9 ,
( V_181 ) V_112 -> V_32 , V_19 ) ;
if ( V_46 < 0 )
goto V_52;
}
}
V_52:
F_88 ( & V_8 -> V_102 ) ;
}
static inline void F_146 ( struct V_39 * V_90 , T_1 V_110 )
{
return F_145 ( V_90 -> V_8 , V_90 -> V_54 ,
V_110 ) ;
}
void F_147 ( struct V_81 * V_82 )
{
if ( F_15 ( & V_82 -> V_184 ) && ! V_82 -> V_185 . V_3 )
return;
F_32 ( V_82 -> V_8 ,
L_7
L_8 ,
V_82 , F_15 ( & V_82 -> V_184 ) ? L_9 : L_10 ,
( T_3 ) ( V_82 -> V_185 . V_3 >> 32 ) ,
( T_3 ) V_82 -> V_185 . V_3 ) ;
F_148 () ;
}
static int
F_149 ( struct V_7 * V_8 , struct V_41 * V_42 ,
struct V_81 * V_82 )
{
struct V_36 V_186 ;
struct V_43 * V_187 = NULL ;
struct V_107 * V_142 = NULL ;
struct V_188 V_189 = F_150 ( V_189 ) ;
T_1 V_110 ;
int V_45 ;
int V_46 ;
F_84 ( & V_8 -> V_155 ) ;
V_46 = F_28 ( V_8 -> V_190 ,
& V_8 -> V_91 ,
V_42 , 1 , 0 ) ;
F_151 ( L_11 ,
V_8 -> V_91 . V_54 ,
V_8 -> V_91 . type ,
V_8 -> V_91 . V_55 , V_46 ) ;
if ( V_46 ) {
V_8 -> V_91 . V_54 = ( T_1 ) - 1 ;
F_48 ( V_42 ) ;
F_90 ( & V_8 -> V_155 ) ;
return V_46 ;
}
F_29 ( V_42 -> V_57 [ 0 ] , & V_186 ,
F_81 ( V_42 -> V_57 [ 0 ] ) - 1 ) ;
V_8 -> V_91 . V_54 = V_186 . V_54 + 1 ;
F_152 ( V_8 , & V_189 ) ;
V_187 = F_153 ( V_42 -> V_57 [ 0 ] ) ;
if ( ! V_187 ) {
V_46 = - V_20 ;
F_90 ( & V_8 -> V_155 ) ;
goto V_52;
}
F_154 ( V_187 ) ;
F_155 ( V_187 ) ;
F_156 ( V_187 , V_191 ) ;
V_45 = V_42 -> V_56 [ 0 ] ;
F_48 ( V_42 ) ;
F_90 ( & V_8 -> V_155 ) ;
for (; V_45 < F_81 ( V_187 ) ; ++ V_45 ) {
F_29 ( V_187 , & V_186 , V_45 ) ;
if ( V_186 . type != V_192 &&
V_186 . type != V_193 )
continue;
if ( V_186 . type == V_193 )
V_110 = V_8 -> V_190 -> V_177 ;
else
V_110 = V_186 . V_55 ;
V_46 = F_117 ( NULL , V_8 , V_186 . V_54 , 0 ,
& V_142 ) ;
if ( V_46 < 0 )
goto V_52;
V_46 = F_129 ( V_82 , V_8 ,
V_186 . V_54 , V_110 , NULL , V_142 ) ;
if ( V_46 < 0 )
goto V_52;
}
V_52:
if ( V_187 ) {
F_157 ( V_187 ) ;
F_89 ( V_187 ) ;
}
F_158 ( V_8 , & V_189 ) ;
return V_46 ;
}
static void F_159 ( struct V_194 * V_195 )
{
struct V_7 * V_8 = F_160 ( V_195 , struct V_7 ,
V_162 ) ;
struct V_41 * V_42 ;
struct V_81 * V_82 = NULL ;
int V_119 = - V_20 ;
int V_46 = 0 ;
F_84 ( & V_8 -> V_155 ) ;
V_8 -> V_196 = true ;
F_90 ( & V_8 -> V_155 ) ;
V_42 = F_27 () ;
if ( ! V_42 )
goto V_52;
V_119 = 0 ;
while ( ! V_119 && ! F_161 ( V_8 ) ) {
V_82 = F_162 ( V_8 -> V_197 , 0 ) ;
if ( F_36 ( V_82 ) ) {
V_119 = F_37 ( V_82 ) ;
break;
}
if ( ! V_8 -> V_49 ) {
V_119 = - V_198 ;
} else {
V_119 = F_149 ( V_8 , V_42 , V_82 ) ;
}
if ( V_119 > 0 )
F_163 ( V_82 , V_8 -> V_197 ) ;
else
F_164 ( V_82 , V_8 -> V_197 ) ;
}
V_52:
F_51 ( V_42 ) ;
F_84 ( & V_8 -> V_155 ) ;
if ( ! F_161 ( V_8 ) )
V_8 -> V_53 &= ~ V_80 ;
if ( V_119 > 0 &&
V_8 -> V_53 & V_63 ) {
V_8 -> V_53 &= ~ V_63 ;
} else if ( V_119 < 0 ) {
V_8 -> V_53 |= V_63 ;
}
F_90 ( & V_8 -> V_155 ) ;
V_82 = F_162 ( V_8 -> V_40 , 1 ) ;
if ( F_36 ( V_82 ) ) {
V_119 = F_37 ( V_82 ) ;
F_32 ( V_8 ,
L_12 ,
V_119 ) ;
goto V_199;
}
V_46 = F_76 ( V_82 , V_8 , V_8 -> V_40 ) ;
if ( V_46 < 0 ) {
V_119 = V_46 ;
F_32 ( V_8 , L_13 , V_119 ) ;
}
F_164 ( V_82 , V_8 -> V_40 ) ;
if ( F_161 ( V_8 ) ) {
F_115 ( V_8 , L_14 ) ;
} else if ( V_119 >= 0 ) {
F_115 ( V_8 , L_15 ,
V_119 > 0 ? L_16 : L_9 ) ;
} else {
F_32 ( V_8 , L_17 , V_119 ) ;
}
V_199:
F_84 ( & V_8 -> V_155 ) ;
V_8 -> V_196 = false ;
F_90 ( & V_8 -> V_155 ) ;
F_165 ( & V_8 -> V_200 ) ;
}
static int
F_50 ( struct V_7 * V_8 , T_1 V_201 ,
int V_202 )
{
int V_46 = 0 ;
if ( ! V_202 &&
( ! ( V_8 -> V_53 & V_80 ) ||
! ( V_8 -> V_53 & V_78 ) ) ) {
V_46 = - V_35 ;
goto V_119;
}
F_84 ( & V_8 -> V_155 ) ;
F_87 ( & V_8 -> V_102 ) ;
if ( V_202 ) {
if ( V_8 -> V_53 & V_80 )
V_46 = - V_203 ;
else if ( ! ( V_8 -> V_53 & V_78 ) )
V_46 = - V_35 ;
if ( V_46 ) {
F_88 ( & V_8 -> V_102 ) ;
F_90 ( & V_8 -> V_155 ) ;
goto V_119;
}
V_8 -> V_53 |= V_80 ;
}
memset ( & V_8 -> V_91 , 0 ,
sizeof( V_8 -> V_91 ) ) ;
V_8 -> V_91 . V_54 = V_201 ;
F_166 ( & V_8 -> V_200 ) ;
F_88 ( & V_8 -> V_102 ) ;
F_90 ( & V_8 -> V_155 ) ;
memset ( & V_8 -> V_162 , 0 ,
sizeof( V_8 -> V_162 ) ) ;
F_167 ( & V_8 -> V_162 ,
V_204 ,
F_159 , NULL , NULL ) ;
if ( V_46 ) {
V_119:
F_115 ( V_8 , L_18 , V_46 ) ;
return V_46 ;
}
return 0 ;
}
static void
F_137 ( struct V_7 * V_8 )
{
struct V_10 * V_11 ;
struct V_1 * V_13 ;
F_87 ( & V_8 -> V_102 ) ;
for ( V_11 = F_54 ( & V_8 -> V_12 ) ; V_11 ; V_11 = F_119 ( V_11 ) ) {
V_13 = F_6 ( V_11 , struct V_1 , V_14 ) ;
V_13 -> V_33 = 0 ;
V_13 -> V_68 = 0 ;
V_13 -> V_34 = 0 ;
V_13 -> V_69 = 0 ;
}
F_88 ( & V_8 -> V_102 ) ;
}
int
F_168 ( struct V_7 * V_8 )
{
int V_46 = 0 ;
struct V_81 * V_82 ;
V_46 = F_50 ( V_8 , 0 , 1 ) ;
if ( V_46 )
return V_46 ;
V_82 = F_169 ( V_8 -> V_197 ) ;
if ( F_36 ( V_82 ) ) {
V_8 -> V_53 &= ~ V_80 ;
return F_37 ( V_82 ) ;
}
V_46 = F_163 ( V_82 , V_8 -> V_197 ) ;
if ( V_46 ) {
V_8 -> V_53 &= ~ V_80 ;
return V_46 ;
}
F_137 ( V_8 ) ;
F_138 ( V_8 -> V_161 ,
& V_8 -> V_162 ) ;
return 0 ;
}
int F_92 ( struct V_7 * V_8 ,
bool V_205 )
{
int V_206 ;
int V_46 = 0 ;
F_84 ( & V_8 -> V_155 ) ;
F_87 ( & V_8 -> V_102 ) ;
V_206 = V_8 -> V_196 ;
F_88 ( & V_8 -> V_102 ) ;
F_90 ( & V_8 -> V_155 ) ;
if ( ! V_206 )
return 0 ;
if ( V_205 )
V_46 = F_170 (
& V_8 -> V_200 ) ;
else
F_171 ( & V_8 -> V_200 ) ;
return V_46 ;
}
void
F_172 ( struct V_7 * V_8 )
{
if ( V_8 -> V_53 & V_80 )
F_138 ( V_8 -> V_161 ,
& V_8 -> V_162 ) ;
}
int F_173 ( struct V_207 * V_207 , T_1 V_208 , T_1 V_209 )
{
struct V_39 * V_90 = F_174 ( V_207 ) -> V_90 ;
struct V_210 V_211 ;
struct V_113 * V_114 ;
struct V_115 V_116 ;
int V_46 ;
if ( ! V_90 -> V_8 -> V_49 || ! F_144 ( V_90 -> V_54 ) ||
V_209 == 0 )
return 0 ;
V_211 . V_212 = 0 ;
V_211 . V_213 = F_26 ( V_51 ) ;
V_46 = F_175 ( & F_174 ( V_207 ) -> V_214 , V_208 ,
V_208 + V_209 - 1 , V_215 , & V_211 ) ;
F_176 ( V_207 , V_208 , V_209 ,
V_211 . V_212 ,
V_216 ) ;
if ( V_46 < 0 )
goto V_159;
V_46 = F_143 ( V_90 , V_211 . V_212 ) ;
if ( V_46 < 0 )
goto V_159;
F_52 ( V_211 . V_213 ) ;
return V_46 ;
V_159:
F_104 ( & V_116 ) ;
while ( ( V_114 = F_105 ( V_211 . V_213 , & V_116 ) ) )
F_177 ( & F_174 ( V_207 ) -> V_214 , V_114 -> V_147 ,
V_114 -> V_118 , V_215 , 0 , 0 , NULL ,
V_51 ) ;
F_52 ( V_211 . V_213 ) ;
return V_46 ;
}
static int F_178 ( struct V_207 * V_207 , T_1 V_208 , T_1 V_209 ,
int free )
{
struct V_210 V_211 ;
int V_217 = V_218 ;
int V_46 ;
V_211 . V_212 = 0 ;
V_211 . V_213 = F_26 ( V_51 ) ;
if ( ! V_211 . V_213 )
return - V_20 ;
V_46 = F_179 ( & F_174 ( V_207 ) -> V_214 , V_208 ,
V_208 + V_209 - 1 , V_215 , & V_211 ) ;
if ( V_46 < 0 )
goto V_52;
if ( free ) {
F_146 ( F_174 ( V_207 ) -> V_90 , V_211 . V_212 ) ;
V_217 = V_219 ;
}
F_180 ( V_207 , V_208 , V_209 ,
V_211 . V_212 , V_217 ) ;
V_52:
F_52 ( V_211 . V_213 ) ;
return V_46 ;
}
int F_181 ( struct V_207 * V_207 , T_1 V_208 , T_1 V_209 )
{
return F_178 ( V_207 , V_208 , V_209 , 1 ) ;
}
int F_182 ( struct V_207 * V_207 , T_1 V_208 , T_1 V_209 )
{
return F_178 ( V_207 , V_208 , V_209 , 0 ) ;
}
int F_183 ( struct V_39 * V_90 , int V_110 )
{
int V_46 ;
if ( ! V_90 -> V_8 -> V_49 || ! F_144 ( V_90 -> V_54 ) ||
V_110 == 0 )
return 0 ;
F_130 ( V_110 != F_184 ( V_110 , V_90 -> V_177 ) ) ;
V_46 = F_143 ( V_90 , V_110 ) ;
if ( V_46 < 0 )
return V_46 ;
F_185 ( V_110 , & V_90 -> V_220 ) ;
return V_46 ;
}
void F_186 ( struct V_39 * V_90 )
{
int V_117 ;
if ( ! V_90 -> V_8 -> V_49 || ! F_144 ( V_90 -> V_54 ) )
return;
V_117 = F_187 ( & V_90 -> V_220 , 0 ) ;
if ( V_117 == 0 )
return;
F_146 ( V_90 , V_117 ) ;
}
void F_188 ( struct V_39 * V_90 , int V_110 )
{
if ( ! V_90 -> V_8 -> V_49 || ! F_144 ( V_90 -> V_54 ) )
return;
F_130 ( V_110 != F_184 ( V_110 , V_90 -> V_177 ) ) ;
F_101 ( F_189 ( & V_90 -> V_220 ) < V_110 ) ;
F_190 ( V_110 , & V_90 -> V_220 ) ;
F_146 ( V_90 , V_110 ) ;
}
void F_191 ( struct V_207 * V_207 )
{
struct V_210 V_211 ;
struct V_113 * V_114 ;
struct V_115 V_221 ;
int V_46 ;
V_211 . V_212 = 0 ;
V_211 . V_213 = F_26 ( V_51 ) ;
if ( F_101 ( ! V_211 . V_213 ) )
return;
V_46 = F_179 ( & F_174 ( V_207 ) -> V_214 , 0 , ( T_1 ) - 1 ,
V_215 , & V_211 ) ;
F_101 ( V_46 < 0 ) ;
if ( F_101 ( V_211 . V_212 ) ) {
F_104 ( & V_221 ) ;
while ( ( V_114 = F_105 ( V_211 . V_213 , & V_221 ) ) ) {
F_49 ( F_174 ( V_207 ) -> V_90 -> V_8 ,
L_19 ,
V_207 -> V_222 , V_114 -> V_147 , V_114 -> V_118 ) ;
}
F_146 ( F_174 ( V_207 ) -> V_90 , V_211 . V_212 ) ;
}
F_52 ( V_211 . V_213 ) ;
}
