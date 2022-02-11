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
static inline T_1 F_5 ( struct V_1 * V_2 )
{
return ( T_1 ) ( V_7 ) V_2 ;
}
static inline struct V_1 * F_6 ( struct V_8 * V_9 )
{
return (struct V_1 * ) ( V_7 ) V_9 -> V_10 ;
}
static struct V_1 * F_7 ( struct V_11 * V_12 ,
T_1 V_13 )
{
struct V_14 * V_9 = V_12 -> V_15 . V_14 ;
struct V_1 * V_16 ;
while ( V_9 ) {
V_16 = F_8 ( V_9 , struct V_1 , V_17 ) ;
if ( V_16 -> V_13 < V_13 )
V_9 = V_9 -> V_18 ;
else if ( V_16 -> V_13 > V_13 )
V_9 = V_9 -> V_19 ;
else
return V_16 ;
}
return NULL ;
}
static struct V_1 * F_9 ( struct V_11 * V_12 ,
T_1 V_13 )
{
struct V_14 * * V_20 = & V_12 -> V_15 . V_14 ;
struct V_14 * V_21 = NULL ;
struct V_1 * V_16 ;
while ( * V_20 ) {
V_21 = * V_20 ;
V_16 = F_8 ( V_21 , struct V_1 , V_17 ) ;
if ( V_16 -> V_13 < V_13 )
V_20 = & ( * V_20 ) -> V_18 ;
else if ( V_16 -> V_13 > V_13 )
V_20 = & ( * V_20 ) -> V_19 ;
else
return V_16 ;
}
V_16 = F_10 ( sizeof( * V_16 ) , V_22 ) ;
if ( ! V_16 )
return F_11 ( - V_23 ) ;
V_16 -> V_13 = V_13 ;
F_12 ( & V_16 -> V_24 ) ;
F_12 ( & V_16 -> V_25 ) ;
F_12 ( & V_16 -> V_26 ) ;
F_13 ( & V_16 -> V_17 , V_21 , V_20 ) ;
F_14 ( & V_16 -> V_17 , & V_12 -> V_15 ) ;
return V_16 ;
}
static void F_15 ( struct V_1 * V_16 )
{
struct V_27 * V_28 ;
F_16 ( & V_16 -> V_26 ) ;
while ( ! F_17 ( & V_16 -> V_24 ) ) {
V_28 = F_18 ( & V_16 -> V_24 ,
struct V_27 , V_29 ) ;
F_16 ( & V_28 -> V_29 ) ;
F_16 ( & V_28 -> V_30 ) ;
F_19 ( V_28 ) ;
}
while ( ! F_17 ( & V_16 -> V_25 ) ) {
V_28 = F_18 ( & V_16 -> V_25 ,
struct V_27 , V_30 ) ;
F_16 ( & V_28 -> V_29 ) ;
F_16 ( & V_28 -> V_30 ) ;
F_19 ( V_28 ) ;
}
F_19 ( V_16 ) ;
}
static int F_20 ( struct V_11 * V_12 , T_1 V_13 )
{
struct V_1 * V_16 = F_7 ( V_12 , V_13 ) ;
if ( ! V_16 )
return - V_31 ;
F_21 ( & V_16 -> V_17 , & V_12 -> V_15 ) ;
F_15 ( V_16 ) ;
return 0 ;
}
static int F_22 ( struct V_11 * V_12 ,
T_1 V_32 , T_1 V_33 )
{
struct V_1 * V_34 ;
struct V_1 * V_21 ;
struct V_27 * V_28 ;
V_34 = F_7 ( V_12 , V_32 ) ;
V_21 = F_7 ( V_12 , V_33 ) ;
if ( ! V_34 || ! V_21 )
return - V_31 ;
V_28 = F_10 ( sizeof( * V_28 ) , V_22 ) ;
if ( ! V_28 )
return - V_23 ;
V_28 -> V_35 = V_21 ;
V_28 -> V_34 = V_34 ;
F_23 ( & V_28 -> V_29 , & V_34 -> V_24 ) ;
F_23 ( & V_28 -> V_30 , & V_21 -> V_25 ) ;
return 0 ;
}
static int F_24 ( struct V_11 * V_12 ,
T_1 V_32 , T_1 V_33 )
{
struct V_1 * V_34 ;
struct V_1 * V_21 ;
struct V_27 * V_28 ;
V_34 = F_7 ( V_12 , V_32 ) ;
V_21 = F_7 ( V_12 , V_33 ) ;
if ( ! V_34 || ! V_21 )
return - V_31 ;
F_25 (list, &member->groups, next_group) {
if ( V_28 -> V_35 == V_21 ) {
F_16 ( & V_28 -> V_29 ) ;
F_16 ( & V_28 -> V_30 ) ;
F_19 ( V_28 ) ;
return 0 ;
}
}
return - V_31 ;
}
int F_26 ( struct V_11 * V_12 , T_1 V_13 ,
T_1 V_36 , T_1 V_37 )
{
struct V_1 * V_16 ;
V_16 = F_7 ( V_12 , V_13 ) ;
if ( ! V_16 )
return - V_38 ;
if ( V_16 -> V_36 != V_36 || V_16 -> V_37 != V_37 )
return - V_38 ;
return 0 ;
}
int F_27 ( struct V_11 * V_12 )
{
struct V_39 V_40 ;
struct V_39 V_41 ;
struct V_42 * V_43 = V_12 -> V_43 ;
struct V_44 * V_45 = NULL ;
struct V_46 * V_47 ;
int V_48 ;
int V_49 = 0 ;
T_1 V_50 = 0 ;
T_1 V_51 = 0 ;
if ( ! F_28 ( V_52 , & V_12 -> V_50 ) )
return 0 ;
V_12 -> V_53 = F_29 ( V_54 ) ;
if ( ! V_12 -> V_53 ) {
V_49 = - V_23 ;
goto V_55;
}
V_45 = F_30 () ;
if ( ! V_45 ) {
V_49 = - V_23 ;
goto V_55;
}
V_12 -> V_56 = 0 ;
V_40 . V_57 = 0 ;
V_40 . type = 0 ;
V_40 . V_58 = 0 ;
V_49 = F_31 ( V_43 , & V_40 , V_45 , 1 , 1 ) ;
if ( V_49 )
goto V_55;
while ( 1 ) {
struct V_1 * V_16 ;
V_48 = V_45 -> V_59 [ 0 ] ;
V_47 = V_45 -> V_60 [ 0 ] ;
F_32 ( V_47 , & V_41 , V_48 ) ;
if ( V_41 . type == V_61 ) {
struct V_62 * V_63 ;
V_63 = F_33 ( V_47 , V_48 ,
struct V_62 ) ;
if ( F_34 ( V_47 , V_63 ) !=
V_64 ) {
F_35 ( V_12 ,
L_1 ) ;
goto V_55;
}
if ( F_36 ( V_47 , V_63 ) !=
V_12 -> V_65 ) {
V_50 |= V_66 ;
F_35 ( V_12 ,
L_2 ) ;
}
V_12 -> V_56 = F_37 ( V_47 ,
V_63 ) ;
V_51 = F_38 ( V_47 , V_63 ) ;
goto V_67;
}
if ( V_41 . type != V_68 &&
V_41 . type != V_69 )
goto V_67;
V_16 = F_7 ( V_12 , V_41 . V_58 ) ;
if ( ( V_16 && V_41 . type == V_68 ) ||
( ! V_16 && V_41 . type == V_69 ) ) {
F_35 ( V_12 , L_3 ) ;
V_50 |= V_66 ;
}
if ( ! V_16 ) {
V_16 = F_9 ( V_12 , V_41 . V_58 ) ;
if ( F_39 ( V_16 ) ) {
V_49 = F_40 ( V_16 ) ;
goto V_55;
}
}
switch ( V_41 . type ) {
case V_68 : {
struct V_70 * V_63 ;
V_63 = F_33 ( V_47 , V_48 ,
struct V_70 ) ;
V_16 -> V_36 = F_41 ( V_47 , V_63 ) ;
V_16 -> V_71 = F_42 ( V_47 , V_63 ) ;
V_16 -> V_37 = F_43 ( V_47 , V_63 ) ;
V_16 -> V_72 = F_44 ( V_47 , V_63 ) ;
break;
}
case V_69 : {
struct V_73 * V_63 ;
V_63 = F_33 ( V_47 , V_48 ,
struct V_73 ) ;
V_16 -> V_74 = F_45 ( V_47 , V_63 ) ;
V_16 -> V_75 = F_46 ( V_47 , V_63 ) ;
V_16 -> V_76 = F_47 ( V_47 , V_63 ) ;
V_16 -> V_77 = F_48 ( V_47 , V_63 ) ;
V_16 -> V_78 = F_49 ( V_47 , V_63 ) ;
break;
}
}
V_67:
V_49 = F_50 ( V_43 , V_45 ) ;
if ( V_49 < 0 )
goto V_55;
if ( V_49 )
break;
}
F_51 ( V_45 ) ;
V_40 . V_57 = 0 ;
V_40 . type = V_79 ;
V_40 . V_58 = 0 ;
V_49 = F_31 ( V_43 , & V_40 , V_45 , 1 , 0 ) ;
if ( V_49 )
goto V_55;
while ( 1 ) {
V_48 = V_45 -> V_59 [ 0 ] ;
V_47 = V_45 -> V_60 [ 0 ] ;
F_32 ( V_47 , & V_41 , V_48 ) ;
if ( V_41 . type != V_79 )
goto V_80;
if ( V_41 . V_57 > V_41 . V_58 ) {
goto V_80;
}
V_49 = F_22 ( V_12 , V_41 . V_57 ,
V_41 . V_58 ) ;
if ( V_49 == - V_31 ) {
F_52 ( V_12 ,
L_4 ,
V_41 . V_57 , V_41 . V_58 ) ;
V_49 = 0 ;
}
if ( V_49 )
goto V_55;
V_80:
V_49 = F_50 ( V_43 , V_45 ) ;
if ( V_49 < 0 )
goto V_55;
if ( V_49 )
break;
}
V_55:
V_12 -> V_56 |= V_50 ;
if ( ! ( V_12 -> V_56 & V_81 ) )
F_53 ( V_52 , & V_12 -> V_50 ) ;
else if ( V_12 -> V_56 & V_82 &&
V_49 >= 0 )
V_49 = F_54 ( V_12 , V_51 , 0 ) ;
F_55 ( V_45 ) ;
if ( V_49 < 0 ) {
F_56 ( V_12 -> V_53 ) ;
V_12 -> V_53 = NULL ;
V_12 -> V_56 &= ~ V_82 ;
}
return V_49 < 0 ? V_49 : 0 ;
}
void F_57 ( struct V_11 * V_12 )
{
struct V_14 * V_9 ;
struct V_1 * V_16 ;
while ( ( V_9 = F_58 ( & V_12 -> V_15 ) ) ) {
V_16 = F_8 ( V_9 , struct V_1 , V_17 ) ;
F_21 ( V_9 , & V_12 -> V_15 ) ;
F_15 ( V_16 ) ;
}
F_56 ( V_12 -> V_53 ) ;
V_12 -> V_53 = NULL ;
}
static int F_59 ( struct V_83 * V_84 ,
struct V_42 * V_43 ,
T_1 V_85 , T_1 V_86 )
{
int V_49 ;
struct V_44 * V_45 ;
struct V_39 V_40 ;
V_45 = F_30 () ;
if ( ! V_45 )
return - V_23 ;
V_40 . V_57 = V_85 ;
V_40 . type = V_79 ;
V_40 . V_58 = V_86 ;
V_49 = F_60 ( V_84 , V_43 , V_45 , & V_40 , 0 ) ;
F_61 ( V_45 -> V_60 [ 0 ] ) ;
F_55 ( V_45 ) ;
return V_49 ;
}
static int F_62 ( struct V_83 * V_84 ,
struct V_42 * V_43 ,
T_1 V_85 , T_1 V_86 )
{
int V_49 ;
struct V_44 * V_45 ;
struct V_39 V_40 ;
V_45 = F_30 () ;
if ( ! V_45 )
return - V_23 ;
V_40 . V_57 = V_85 ;
V_40 . type = V_79 ;
V_40 . V_58 = V_86 ;
V_49 = F_63 ( V_84 , V_43 , & V_40 , V_45 , - 1 , 1 ) ;
if ( V_49 < 0 )
goto V_55;
if ( V_49 > 0 ) {
V_49 = - V_31 ;
goto V_55;
}
V_49 = F_64 ( V_84 , V_43 , V_45 ) ;
V_55:
F_55 ( V_45 ) ;
return V_49 ;
}
static int F_65 ( struct V_83 * V_84 ,
struct V_42 * V_43 , T_1 V_13 )
{
int V_49 ;
struct V_44 * V_45 ;
struct V_70 * V_87 ;
struct V_73 * V_88 ;
struct V_46 * V_89 ;
struct V_39 V_40 ;
if ( F_66 ( V_43 -> V_12 ) )
return 0 ;
V_45 = F_30 () ;
if ( ! V_45 )
return - V_23 ;
V_40 . V_57 = 0 ;
V_40 . type = V_68 ;
V_40 . V_58 = V_13 ;
V_49 = F_60 ( V_84 , V_43 , V_45 , & V_40 ,
sizeof( * V_87 ) ) ;
if ( V_49 && V_49 != - V_90 )
goto V_55;
V_89 = V_45 -> V_60 [ 0 ] ;
V_87 = F_33 ( V_89 , V_45 -> V_59 [ 0 ] ,
struct V_70 ) ;
F_67 ( V_89 , V_87 , V_84 -> V_91 ) ;
F_68 ( V_89 , V_87 , 0 ) ;
F_69 ( V_89 , V_87 , 0 ) ;
F_70 ( V_89 , V_87 , 0 ) ;
F_71 ( V_89 , V_87 , 0 ) ;
F_61 ( V_89 ) ;
F_51 ( V_45 ) ;
V_40 . type = V_69 ;
V_49 = F_60 ( V_84 , V_43 , V_45 , & V_40 ,
sizeof( * V_88 ) ) ;
if ( V_49 && V_49 != - V_90 )
goto V_55;
V_89 = V_45 -> V_60 [ 0 ] ;
V_88 = F_33 ( V_89 , V_45 -> V_59 [ 0 ] ,
struct V_73 ) ;
F_72 ( V_89 , V_88 , 0 ) ;
F_73 ( V_89 , V_88 , 0 ) ;
F_74 ( V_89 , V_88 , 0 ) ;
F_75 ( V_89 , V_88 , 0 ) ;
F_76 ( V_89 , V_88 , 0 ) ;
F_61 ( V_89 ) ;
V_49 = 0 ;
V_55:
F_55 ( V_45 ) ;
return V_49 ;
}
static int F_77 ( struct V_83 * V_84 ,
struct V_42 * V_43 , T_1 V_13 )
{
int V_49 ;
struct V_44 * V_45 ;
struct V_39 V_40 ;
V_45 = F_30 () ;
if ( ! V_45 )
return - V_23 ;
V_40 . V_57 = 0 ;
V_40 . type = V_68 ;
V_40 . V_58 = V_13 ;
V_49 = F_63 ( V_84 , V_43 , & V_40 , V_45 , - 1 , 1 ) ;
if ( V_49 < 0 )
goto V_55;
if ( V_49 > 0 ) {
V_49 = - V_31 ;
goto V_55;
}
V_49 = F_64 ( V_84 , V_43 , V_45 ) ;
if ( V_49 )
goto V_55;
F_51 ( V_45 ) ;
V_40 . type = V_69 ;
V_49 = F_63 ( V_84 , V_43 , & V_40 , V_45 , - 1 , 1 ) ;
if ( V_49 < 0 )
goto V_55;
if ( V_49 > 0 ) {
V_49 = - V_31 ;
goto V_55;
}
V_49 = F_64 ( V_84 , V_43 , V_45 ) ;
V_55:
F_55 ( V_45 ) ;
return V_49 ;
}
static int F_78 ( struct V_83 * V_84 ,
struct V_42 * V_92 ,
struct V_1 * V_16 )
{
struct V_44 * V_45 ;
struct V_39 V_40 ;
struct V_46 * V_47 ;
struct V_73 * V_88 ;
int V_49 ;
int V_48 ;
V_40 . V_57 = 0 ;
V_40 . type = V_69 ;
V_40 . V_58 = V_16 -> V_13 ;
V_45 = F_30 () ;
if ( ! V_45 )
return - V_23 ;
V_49 = F_63 ( V_84 , V_92 , & V_40 , V_45 , 0 , 1 ) ;
if ( V_49 > 0 )
V_49 = - V_31 ;
if ( V_49 )
goto V_55;
V_47 = V_45 -> V_60 [ 0 ] ;
V_48 = V_45 -> V_59 [ 0 ] ;
V_88 = F_33 ( V_47 , V_48 , struct V_73 ) ;
F_72 ( V_47 , V_88 , V_16 -> V_74 ) ;
F_73 ( V_47 , V_88 , V_16 -> V_75 ) ;
F_74 ( V_47 , V_88 , V_16 -> V_76 ) ;
F_75 ( V_47 , V_88 , V_16 -> V_77 ) ;
F_76 ( V_47 , V_88 , V_16 -> V_78 ) ;
F_61 ( V_47 ) ;
V_55:
F_55 ( V_45 ) ;
return V_49 ;
}
static int F_79 ( struct V_83 * V_84 ,
struct V_42 * V_92 ,
struct V_1 * V_16 )
{
struct V_44 * V_45 ;
struct V_39 V_40 ;
struct V_46 * V_47 ;
struct V_70 * V_87 ;
int V_49 ;
int V_48 ;
if ( F_66 ( V_92 -> V_12 ) )
return 0 ;
V_40 . V_57 = 0 ;
V_40 . type = V_68 ;
V_40 . V_58 = V_16 -> V_13 ;
V_45 = F_30 () ;
if ( ! V_45 )
return - V_23 ;
V_49 = F_63 ( V_84 , V_92 , & V_40 , V_45 , 0 , 1 ) ;
if ( V_49 > 0 )
V_49 = - V_31 ;
if ( V_49 )
goto V_55;
V_47 = V_45 -> V_60 [ 0 ] ;
V_48 = V_45 -> V_59 [ 0 ] ;
V_87 = F_33 ( V_47 , V_48 , struct V_70 ) ;
F_67 ( V_47 , V_87 , V_84 -> V_91 ) ;
F_68 ( V_47 , V_87 , V_16 -> V_36 ) ;
F_69 ( V_47 , V_87 , V_16 -> V_71 ) ;
F_70 ( V_47 , V_87 , V_16 -> V_37 ) ;
F_71 ( V_47 , V_87 , V_16 -> V_72 ) ;
F_61 ( V_47 ) ;
V_55:
F_55 ( V_45 ) ;
return V_49 ;
}
static int F_80 ( struct V_83 * V_84 ,
struct V_11 * V_12 ,
struct V_42 * V_92 )
{
struct V_44 * V_45 ;
struct V_39 V_40 ;
struct V_46 * V_47 ;
struct V_62 * V_63 ;
int V_49 ;
int V_48 ;
V_40 . V_57 = 0 ;
V_40 . type = V_61 ;
V_40 . V_58 = 0 ;
V_45 = F_30 () ;
if ( ! V_45 )
return - V_23 ;
V_49 = F_63 ( V_84 , V_92 , & V_40 , V_45 , 0 , 1 ) ;
if ( V_49 > 0 )
V_49 = - V_31 ;
if ( V_49 )
goto V_55;
V_47 = V_45 -> V_60 [ 0 ] ;
V_48 = V_45 -> V_59 [ 0 ] ;
V_63 = F_33 ( V_47 , V_48 , struct V_62 ) ;
F_81 ( V_47 , V_63 , V_12 -> V_56 ) ;
F_82 ( V_47 , V_63 , V_84 -> V_91 ) ;
F_83 ( V_47 , V_63 ,
V_12 -> V_93 . V_57 ) ;
F_61 ( V_47 ) ;
V_55:
F_55 ( V_45 ) ;
return V_49 ;
}
static int F_84 ( struct V_83 * V_84 ,
struct V_42 * V_92 )
{
struct V_44 * V_45 ;
struct V_39 V_40 ;
struct V_46 * V_89 = NULL ;
int V_49 ;
int V_94 = 0 ;
V_45 = F_30 () ;
if ( ! V_45 )
return - V_23 ;
V_45 -> V_95 = 1 ;
V_40 . V_57 = 0 ;
V_40 . V_58 = 0 ;
V_40 . type = 0 ;
while ( 1 ) {
V_49 = F_63 ( V_84 , V_92 , & V_40 , V_45 , - 1 , 1 ) ;
if ( V_49 < 0 )
goto V_55;
V_89 = V_45 -> V_60 [ 0 ] ;
V_94 = F_85 ( V_89 ) ;
if ( ! V_94 )
break;
V_45 -> V_59 [ 0 ] = 0 ;
V_49 = F_86 ( V_84 , V_92 , V_45 , 0 , V_94 ) ;
if ( V_49 )
goto V_55;
F_51 ( V_45 ) ;
}
V_49 = 0 ;
V_55:
F_55 ( V_45 ) ;
return V_49 ;
}
int F_87 ( struct V_83 * V_84 ,
struct V_11 * V_12 )
{
struct V_42 * V_43 ;
struct V_42 * V_96 = V_12 -> V_96 ;
struct V_44 * V_45 = NULL ;
struct V_62 * V_63 ;
struct V_46 * V_89 ;
struct V_39 V_40 ;
struct V_39 V_41 ;
struct V_1 * V_16 = NULL ;
int V_49 = 0 ;
int V_48 ;
F_88 ( & V_12 -> V_97 ) ;
if ( V_12 -> V_43 ) {
F_89 ( V_98 , & V_12 -> V_50 ) ;
goto V_55;
}
V_12 -> V_53 = F_29 ( V_54 ) ;
if ( ! V_12 -> V_53 ) {
V_49 = - V_23 ;
goto V_55;
}
V_43 = F_90 ( V_84 , V_12 ,
V_99 ) ;
if ( F_39 ( V_43 ) ) {
V_49 = F_40 ( V_43 ) ;
goto V_55;
}
V_45 = F_30 () ;
if ( ! V_45 ) {
V_49 = - V_23 ;
goto V_100;
}
V_40 . V_57 = 0 ;
V_40 . type = V_61 ;
V_40 . V_58 = 0 ;
V_49 = F_60 ( V_84 , V_43 , V_45 , & V_40 ,
sizeof( * V_63 ) ) ;
if ( V_49 )
goto V_101;
V_89 = V_45 -> V_60 [ 0 ] ;
V_63 = F_33 ( V_89 , V_45 -> V_59 [ 0 ] ,
struct V_62 ) ;
F_82 ( V_89 , V_63 , V_84 -> V_91 ) ;
F_91 ( V_89 , V_63 , V_64 ) ;
V_12 -> V_56 = V_81 |
V_66 ;
F_81 ( V_89 , V_63 , V_12 -> V_56 ) ;
F_83 ( V_89 , V_63 , 0 ) ;
F_61 ( V_89 ) ;
V_40 . V_57 = 0 ;
V_40 . type = V_102 ;
V_40 . V_58 = 0 ;
F_51 ( V_45 ) ;
V_49 = F_31 ( V_96 , & V_40 , V_45 , 1 , 0 ) ;
if ( V_49 > 0 )
goto V_103;
if ( V_49 < 0 )
goto V_101;
while ( 1 ) {
V_48 = V_45 -> V_59 [ 0 ] ;
V_89 = V_45 -> V_60 [ 0 ] ;
F_32 ( V_89 , & V_41 , V_48 ) ;
if ( V_41 . type == V_102 ) {
V_49 = F_65 ( V_84 , V_43 ,
V_41 . V_58 ) ;
if ( V_49 )
goto V_101;
V_16 = F_9 ( V_12 , V_41 . V_58 ) ;
if ( F_39 ( V_16 ) ) {
V_49 = F_40 ( V_16 ) ;
goto V_101;
}
}
V_49 = F_50 ( V_96 , V_45 ) ;
if ( V_49 < 0 )
goto V_101;
if ( V_49 )
break;
}
V_103:
F_51 ( V_45 ) ;
V_49 = F_65 ( V_84 , V_43 , V_104 ) ;
if ( V_49 )
goto V_101;
V_16 = F_9 ( V_12 , V_104 ) ;
if ( F_39 ( V_16 ) ) {
V_49 = F_40 ( V_16 ) ;
goto V_101;
}
F_92 ( & V_12 -> V_105 ) ;
V_12 -> V_43 = V_43 ;
F_89 ( V_98 , & V_12 -> V_50 ) ;
F_93 ( & V_12 -> V_105 ) ;
V_101:
F_55 ( V_45 ) ;
V_100:
if ( V_49 ) {
F_94 ( V_43 -> V_17 ) ;
F_94 ( V_43 -> V_106 ) ;
F_19 ( V_43 ) ;
}
V_55:
if ( V_49 ) {
F_56 ( V_12 -> V_53 ) ;
V_12 -> V_53 = NULL ;
}
F_95 ( & V_12 -> V_97 ) ;
return V_49 ;
}
int F_96 ( struct V_83 * V_84 ,
struct V_11 * V_12 )
{
struct V_42 * V_43 ;
int V_49 = 0 ;
F_88 ( & V_12 -> V_97 ) ;
if ( ! V_12 -> V_43 )
goto V_55;
F_53 ( V_52 , & V_12 -> V_50 ) ;
F_97 ( V_12 , false ) ;
F_92 ( & V_12 -> V_105 ) ;
V_43 = V_12 -> V_43 ;
V_12 -> V_43 = NULL ;
V_12 -> V_56 &= ~ V_81 ;
F_93 ( & V_12 -> V_105 ) ;
F_57 ( V_12 ) ;
V_49 = F_84 ( V_84 , V_43 ) ;
if ( V_49 )
goto V_55;
V_49 = F_98 ( V_84 , V_12 , & V_43 -> V_107 ) ;
if ( V_49 )
goto V_55;
F_16 ( & V_43 -> V_108 ) ;
F_99 ( V_43 -> V_17 ) ;
F_100 ( V_12 , V_43 -> V_17 ) ;
F_101 ( V_43 -> V_17 ) ;
F_102 ( V_84 , V_43 , V_43 -> V_17 , 0 , 1 ) ;
F_94 ( V_43 -> V_17 ) ;
F_94 ( V_43 -> V_106 ) ;
F_19 ( V_43 ) ;
V_55:
F_95 ( & V_12 -> V_97 ) ;
return V_49 ;
}
static void F_103 ( struct V_11 * V_12 ,
struct V_1 * V_16 )
{
if ( F_17 ( & V_16 -> V_26 ) )
F_104 ( & V_16 -> V_26 , & V_12 -> V_109 ) ;
}
static void F_105 ( struct V_11 * V_12 ,
struct V_1 * V_16 ,
T_1 V_110 )
{
#ifdef F_106
F_107 ( V_16 -> V_111 < V_110 ) ;
F_108 ( V_12 ,
L_5 ,
V_16 -> V_13 , V_16 -> V_111 , V_110 ) ;
#endif
V_16 -> V_111 = 0 ;
}
static int F_109 ( struct V_11 * V_12 ,
struct V_112 * V_113 , T_1 V_114 ,
T_1 V_110 , int V_115 )
{
struct V_1 * V_16 ;
struct V_27 * V_116 ;
struct V_8 * V_117 ;
struct V_118 V_119 ;
int V_49 = 0 ;
V_16 = F_7 ( V_12 , V_114 ) ;
if ( ! V_16 )
goto V_55;
V_16 -> V_36 += V_115 * V_110 ;
V_16 -> V_71 += V_115 * V_110 ;
F_107 ( V_115 < 0 && V_16 -> V_37 < V_110 ) ;
V_16 -> V_37 += V_115 * V_110 ;
V_16 -> V_72 += V_115 * V_110 ;
if ( V_115 > 0 ) {
F_110 ( V_12 , V_16 , - ( V_120 ) V_110 ) ;
if ( V_16 -> V_111 < V_110 )
F_105 ( V_12 , V_16 , V_110 ) ;
else
V_16 -> V_111 -= V_110 ;
}
F_103 ( V_12 , V_16 ) ;
F_25 (glist, &qgroup->groups, next_group) {
V_49 = F_111 ( V_113 , V_116 -> V_35 -> V_13 ,
F_5 ( V_116 -> V_35 ) , V_22 ) ;
if ( V_49 < 0 )
goto V_55;
}
F_112 ( & V_119 ) ;
while ( ( V_117 = F_113 ( V_113 , & V_119 ) ) ) {
V_16 = F_6 ( V_117 ) ;
V_16 -> V_36 += V_115 * V_110 ;
V_16 -> V_71 += V_115 * V_110 ;
F_107 ( V_115 < 0 && V_16 -> V_37 < V_110 ) ;
V_16 -> V_37 += V_115 * V_110 ;
if ( V_115 > 0 ) {
F_110 ( V_12 , V_16 ,
- ( V_120 ) V_110 ) ;
if ( V_16 -> V_111 < V_110 )
F_105 ( V_12 , V_16 ,
V_110 ) ;
else
V_16 -> V_111 -= V_110 ;
}
V_16 -> V_72 += V_115 * V_110 ;
F_103 ( V_12 , V_16 ) ;
F_25 (glist, &qgroup->groups, next_group) {
V_49 = F_111 ( V_113 , V_116 -> V_35 -> V_13 ,
F_5 ( V_116 -> V_35 ) , V_22 ) ;
if ( V_49 < 0 )
goto V_55;
}
}
V_49 = 0 ;
V_55:
return V_49 ;
}
static int F_114 ( struct V_11 * V_12 ,
struct V_112 * V_113 , T_1 V_85 , T_1 V_86 ,
int V_115 )
{
struct V_1 * V_16 ;
int V_49 = 1 ;
int V_121 = 0 ;
V_16 = F_7 ( V_12 , V_85 ) ;
if ( ! V_16 )
goto V_55;
if ( V_16 -> V_37 == V_16 -> V_36 ) {
V_49 = 0 ;
V_121 = F_109 ( V_12 , V_113 , V_86 ,
V_16 -> V_37 , V_115 ) ;
if ( V_121 < 0 ) {
V_49 = V_121 ;
goto V_55;
}
}
V_55:
if ( V_49 )
V_12 -> V_56 |= V_66 ;
return V_49 ;
}
int F_115 ( struct V_83 * V_84 ,
struct V_11 * V_12 , T_1 V_85 , T_1 V_86 )
{
struct V_42 * V_43 ;
struct V_1 * V_21 ;
struct V_1 * V_34 ;
struct V_27 * V_28 ;
struct V_112 * V_113 ;
int V_49 = 0 ;
if ( F_116 ( V_85 ) >= F_116 ( V_86 ) )
return - V_38 ;
V_113 = F_29 ( V_54 ) ;
if ( ! V_113 )
return - V_23 ;
F_88 ( & V_12 -> V_97 ) ;
V_43 = V_12 -> V_43 ;
if ( ! V_43 ) {
V_49 = - V_38 ;
goto V_55;
}
V_34 = F_7 ( V_12 , V_85 ) ;
V_21 = F_7 ( V_12 , V_86 ) ;
if ( ! V_34 || ! V_21 ) {
V_49 = - V_38 ;
goto V_55;
}
F_25 (list, &member->groups, next_group) {
if ( V_28 -> V_35 == V_21 ) {
V_49 = - V_90 ;
goto V_55;
}
}
V_49 = F_59 ( V_84 , V_43 , V_85 , V_86 ) ;
if ( V_49 )
goto V_55;
V_49 = F_59 ( V_84 , V_43 , V_86 , V_85 ) ;
if ( V_49 ) {
F_62 ( V_84 , V_43 , V_85 , V_86 ) ;
goto V_55;
}
F_92 ( & V_12 -> V_105 ) ;
V_49 = F_22 ( V_12 , V_85 , V_86 ) ;
if ( V_49 < 0 ) {
F_93 ( & V_12 -> V_105 ) ;
goto V_55;
}
V_49 = F_114 ( V_12 , V_113 , V_85 , V_86 , 1 ) ;
F_93 ( & V_12 -> V_105 ) ;
V_55:
F_95 ( & V_12 -> V_97 ) ;
F_56 ( V_113 ) ;
return V_49 ;
}
static int F_117 ( struct V_83 * V_84 ,
struct V_11 * V_12 , T_1 V_85 , T_1 V_86 )
{
struct V_42 * V_43 ;
struct V_1 * V_21 ;
struct V_1 * V_34 ;
struct V_27 * V_28 ;
struct V_112 * V_113 ;
int V_49 = 0 ;
int V_121 ;
V_113 = F_29 ( V_54 ) ;
if ( ! V_113 )
return - V_23 ;
V_43 = V_12 -> V_43 ;
if ( ! V_43 ) {
V_49 = - V_38 ;
goto V_55;
}
V_34 = F_7 ( V_12 , V_85 ) ;
V_21 = F_7 ( V_12 , V_86 ) ;
if ( ! V_34 || ! V_21 ) {
V_49 = - V_38 ;
goto V_55;
}
F_25 (list, &member->groups, next_group) {
if ( V_28 -> V_35 == V_21 )
goto V_122;
}
V_49 = - V_31 ;
goto V_55;
V_122:
V_49 = F_62 ( V_84 , V_43 , V_85 , V_86 ) ;
V_121 = F_62 ( V_84 , V_43 , V_86 , V_85 ) ;
if ( V_121 && ! V_49 )
V_49 = V_121 ;
F_92 ( & V_12 -> V_105 ) ;
F_24 ( V_12 , V_85 , V_86 ) ;
V_49 = F_114 ( V_12 , V_113 , V_85 , V_86 , - 1 ) ;
F_93 ( & V_12 -> V_105 ) ;
V_55:
F_56 ( V_113 ) ;
return V_49 ;
}
int F_118 ( struct V_83 * V_84 ,
struct V_11 * V_12 , T_1 V_85 , T_1 V_86 )
{
int V_49 = 0 ;
F_88 ( & V_12 -> V_97 ) ;
V_49 = F_117 ( V_84 , V_12 , V_85 , V_86 ) ;
F_95 ( & V_12 -> V_97 ) ;
return V_49 ;
}
int F_119 ( struct V_83 * V_84 ,
struct V_11 * V_12 , T_1 V_13 )
{
struct V_42 * V_43 ;
struct V_1 * V_16 ;
int V_49 = 0 ;
F_88 ( & V_12 -> V_97 ) ;
V_43 = V_12 -> V_43 ;
if ( ! V_43 ) {
V_49 = - V_38 ;
goto V_55;
}
V_16 = F_7 ( V_12 , V_13 ) ;
if ( V_16 ) {
V_49 = - V_90 ;
goto V_55;
}
V_49 = F_65 ( V_84 , V_43 , V_13 ) ;
if ( V_49 )
goto V_55;
F_92 ( & V_12 -> V_105 ) ;
V_16 = F_9 ( V_12 , V_13 ) ;
F_93 ( & V_12 -> V_105 ) ;
if ( F_39 ( V_16 ) )
V_49 = F_40 ( V_16 ) ;
V_55:
F_95 ( & V_12 -> V_97 ) ;
return V_49 ;
}
int F_120 ( struct V_83 * V_84 ,
struct V_11 * V_12 , T_1 V_13 )
{
struct V_42 * V_43 ;
struct V_1 * V_16 ;
struct V_27 * V_28 ;
int V_49 = 0 ;
F_88 ( & V_12 -> V_97 ) ;
V_43 = V_12 -> V_43 ;
if ( ! V_43 ) {
V_49 = - V_38 ;
goto V_55;
}
V_16 = F_7 ( V_12 , V_13 ) ;
if ( ! V_16 ) {
V_49 = - V_31 ;
goto V_55;
} else {
if ( ! F_17 ( & V_16 -> V_25 ) ) {
V_49 = - V_123 ;
goto V_55;
}
}
V_49 = F_77 ( V_84 , V_43 , V_13 ) ;
if ( V_49 && V_49 != - V_31 )
goto V_55;
while ( ! F_17 ( & V_16 -> V_24 ) ) {
V_28 = F_18 ( & V_16 -> V_24 ,
struct V_27 , V_29 ) ;
V_49 = F_117 ( V_84 , V_12 ,
V_13 ,
V_28 -> V_35 -> V_13 ) ;
if ( V_49 )
goto V_55;
}
F_92 ( & V_12 -> V_105 ) ;
F_20 ( V_12 , V_13 ) ;
F_93 ( & V_12 -> V_105 ) ;
V_55:
F_95 ( & V_12 -> V_97 ) ;
return V_49 ;
}
int F_121 ( struct V_83 * V_84 ,
struct V_11 * V_12 , T_1 V_13 ,
struct V_124 * V_125 )
{
struct V_42 * V_43 ;
struct V_1 * V_16 ;
int V_49 = 0 ;
const T_1 V_126 = - 1 ;
F_88 ( & V_12 -> V_97 ) ;
V_43 = V_12 -> V_43 ;
if ( ! V_43 ) {
V_49 = - V_38 ;
goto V_55;
}
V_16 = F_7 ( V_12 , V_13 ) ;
if ( ! V_16 ) {
V_49 = - V_31 ;
goto V_55;
}
F_92 ( & V_12 -> V_105 ) ;
if ( V_125 -> V_50 & V_127 ) {
if ( V_125 -> V_75 == V_126 ) {
V_16 -> V_74 &= ~ V_127 ;
V_125 -> V_50 &= ~ V_127 ;
V_16 -> V_75 = 0 ;
} else {
V_16 -> V_75 = V_125 -> V_75 ;
}
}
if ( V_125 -> V_50 & V_128 ) {
if ( V_125 -> V_76 == V_126 ) {
V_16 -> V_74 &= ~ V_128 ;
V_125 -> V_50 &= ~ V_128 ;
V_16 -> V_76 = 0 ;
} else {
V_16 -> V_76 = V_125 -> V_76 ;
}
}
if ( V_125 -> V_50 & V_129 ) {
if ( V_125 -> V_77 == V_126 ) {
V_16 -> V_74 &= ~ V_129 ;
V_125 -> V_50 &= ~ V_129 ;
V_16 -> V_77 = 0 ;
} else {
V_16 -> V_77 = V_125 -> V_77 ;
}
}
if ( V_125 -> V_50 & V_130 ) {
if ( V_125 -> V_78 == V_126 ) {
V_16 -> V_74 &= ~ V_130 ;
V_125 -> V_50 &= ~ V_130 ;
V_16 -> V_78 = 0 ;
} else {
V_16 -> V_78 = V_125 -> V_78 ;
}
}
V_16 -> V_74 |= V_125 -> V_50 ;
F_93 ( & V_12 -> V_105 ) ;
V_49 = F_78 ( V_84 , V_43 , V_16 ) ;
if ( V_49 ) {
V_12 -> V_56 |= V_66 ;
F_122 ( V_12 , L_6 ,
V_13 ) ;
}
V_55:
F_95 ( & V_12 -> V_97 ) ;
return V_49 ;
}
int F_123 ( struct V_11 * V_12 ,
struct V_131 * V_132 ,
struct V_133 * V_134 )
{
struct V_14 * * V_20 = & V_132 -> V_135 . V_14 ;
struct V_14 * V_136 = NULL ;
struct V_133 * V_137 ;
T_1 V_138 = V_134 -> V_138 ;
F_124 ( & V_132 -> V_139 ) ;
F_125 ( V_12 , V_134 ) ;
while ( * V_20 ) {
V_136 = * V_20 ;
V_137 = F_8 ( V_136 , struct V_133 ,
V_17 ) ;
if ( V_138 < V_137 -> V_138 )
V_20 = & ( * V_20 ) -> V_18 ;
else if ( V_138 > V_137 -> V_138 )
V_20 = & ( * V_20 ) -> V_19 ;
else
return 1 ;
}
F_13 ( & V_134 -> V_17 , V_136 , V_20 ) ;
F_14 ( & V_134 -> V_17 , & V_132 -> V_135 ) ;
return 0 ;
}
int F_126 ( struct V_11 * V_12 ,
struct V_133 * V_140 )
{
struct V_112 * V_141 ;
T_1 V_138 = V_140 -> V_138 ;
int V_49 ;
V_49 = F_127 ( NULL , V_12 , V_138 , 0 , & V_141 ) ;
if ( V_49 < 0 )
return V_49 ;
V_140 -> V_142 = V_141 ;
return 0 ;
}
int F_128 ( struct V_83 * V_84 ,
struct V_11 * V_12 , T_1 V_138 , T_1 V_110 ,
T_2 V_143 )
{
struct V_133 * V_134 ;
struct V_131 * V_132 ;
int V_49 ;
if ( ! F_28 ( V_52 , & V_12 -> V_50 )
|| V_138 == 0 || V_110 == 0 )
return 0 ;
if ( F_107 ( V_84 == NULL ) )
return - V_38 ;
V_134 = F_129 ( sizeof( * V_134 ) , V_143 ) ;
if ( ! V_134 )
return - V_23 ;
V_132 = & V_84 -> V_144 -> V_132 ;
V_134 -> V_138 = V_138 ;
V_134 -> V_110 = V_110 ;
V_134 -> V_142 = NULL ;
F_92 ( & V_132 -> V_139 ) ;
V_49 = F_123 ( V_12 , V_132 , V_134 ) ;
F_93 ( & V_132 -> V_139 ) ;
if ( V_49 > 0 ) {
F_19 ( V_134 ) ;
return 0 ;
}
return F_126 ( V_12 , V_134 ) ;
}
int F_130 ( struct V_83 * V_84 ,
struct V_11 * V_12 ,
struct V_46 * V_145 )
{
int V_94 = F_85 ( V_145 ) ;
int V_146 , V_147 , V_49 ;
struct V_39 V_40 ;
struct V_148 * V_149 ;
T_1 V_138 , V_110 ;
if ( ! F_28 ( V_52 , & V_12 -> V_50 ) )
return 0 ;
for ( V_146 = 0 ; V_146 < V_94 ; V_146 ++ ) {
F_32 ( V_145 , & V_40 , V_146 ) ;
if ( V_40 . type != V_150 )
continue;
V_149 = F_33 ( V_145 , V_146 , struct V_148 ) ;
V_147 = F_131 ( V_145 , V_149 ) ;
if ( V_147 == V_151 )
continue;
V_138 = F_132 ( V_145 , V_149 ) ;
if ( ! V_138 )
continue;
V_110 = F_133 ( V_145 , V_149 ) ;
V_49 = F_128 ( V_84 , V_12 , V_138 ,
V_110 , V_152 ) ;
if ( V_49 )
return V_49 ;
}
F_134 () ;
return 0 ;
}
static int F_135 ( struct V_44 * V_45 , int V_153 )
{
int V_154 = 0 ;
int V_94 , V_48 ;
struct V_46 * V_145 ;
if ( V_153 == 0 )
return 1 ;
while ( V_154 <= V_153 ) {
V_145 = V_45 -> V_60 [ V_154 ] ;
V_94 = F_85 ( V_145 ) ;
V_45 -> V_59 [ V_154 ] ++ ;
V_48 = V_45 -> V_59 [ V_154 ] ;
if ( V_48 >= V_94 || V_154 == 0 ) {
if ( V_154 != V_153 ) {
F_136 ( V_145 , V_45 -> V_155 [ V_154 ] ) ;
V_45 -> V_155 [ V_154 ] = 0 ;
F_94 ( V_145 ) ;
V_45 -> V_60 [ V_154 ] = NULL ;
V_45 -> V_59 [ V_154 ] = 0 ;
}
} else {
break;
}
V_154 ++ ;
}
V_145 = V_45 -> V_60 [ V_153 ] ;
if ( V_45 -> V_59 [ V_153 ] >= F_85 ( V_145 ) )
return 1 ;
return 0 ;
}
int F_137 ( struct V_83 * V_84 ,
struct V_42 * V_92 ,
struct V_46 * V_156 ,
T_1 V_157 , int V_153 )
{
struct V_11 * V_12 = V_92 -> V_12 ;
int V_49 = 0 ;
int V_154 ;
struct V_46 * V_145 = V_156 ;
struct V_44 * V_45 = NULL ;
F_138 ( V_153 < 0 || V_153 >= V_158 ) ;
F_138 ( V_156 == NULL ) ;
if ( ! F_28 ( V_52 , & V_12 -> V_50 ) )
return 0 ;
if ( ! F_139 ( V_156 ) ) {
V_49 = F_140 ( V_156 , V_157 ) ;
if ( V_49 )
goto V_55;
}
if ( V_153 == 0 ) {
V_49 = F_130 ( V_84 , V_12 , V_156 ) ;
goto V_55;
}
V_45 = F_30 () ;
if ( ! V_45 )
return - V_23 ;
F_141 ( V_156 ) ;
V_45 -> V_60 [ V_153 ] = V_156 ;
V_45 -> V_59 [ V_153 ] = 0 ;
V_45 -> V_155 [ V_153 ] = 0 ;
V_159:
V_154 = V_153 ;
while ( V_154 >= 0 ) {
if ( V_45 -> V_60 [ V_154 ] == NULL ) {
int V_160 ;
T_1 V_161 ;
T_1 V_162 ;
V_145 = V_45 -> V_60 [ V_154 + 1 ] ;
V_160 = V_45 -> V_59 [ V_154 + 1 ] ;
V_162 = F_142 ( V_145 , V_160 ) ;
V_161 = F_143 ( V_145 , V_160 ) ;
V_145 = F_144 ( V_12 , V_162 , V_161 ) ;
if ( F_39 ( V_145 ) ) {
V_49 = F_40 ( V_145 ) ;
goto V_55;
} else if ( ! F_139 ( V_145 ) ) {
F_94 ( V_145 ) ;
V_49 = - V_163 ;
goto V_55;
}
V_45 -> V_60 [ V_154 ] = V_145 ;
V_45 -> V_59 [ V_154 ] = 0 ;
F_145 ( V_145 ) ;
F_146 ( V_145 , V_164 ) ;
V_45 -> V_155 [ V_154 ] = V_165 ;
V_49 = F_128 ( V_84 , V_12 ,
V_162 ,
V_12 -> V_166 ,
V_152 ) ;
if ( V_49 )
goto V_55;
}
if ( V_154 == 0 ) {
V_49 = F_130 ( V_84 , V_12 ,
V_45 -> V_60 [ V_154 ] ) ;
if ( V_49 )
goto V_55;
V_49 = F_135 ( V_45 , V_153 ) ;
if ( V_49 )
break;
goto V_159;
}
V_154 -- ;
}
V_49 = 0 ;
V_55:
F_55 ( V_45 ) ;
return V_49 ;
}
static int F_147 ( struct V_11 * V_12 ,
struct V_112 * V_167 , struct V_112 * V_113 ,
struct V_112 * V_168 , T_1 V_3 , int V_169 )
{
struct V_8 * V_117 ;
struct V_118 V_119 ;
struct V_8 * V_170 ;
struct V_118 V_171 ;
struct V_1 * V_2 ;
int V_49 = 0 ;
if ( ! V_167 )
return 0 ;
F_112 ( & V_119 ) ;
while ( ( V_117 = F_113 ( V_167 , & V_119 ) ) ) {
V_2 = F_7 ( V_12 , V_117 -> V_172 ) ;
if ( ! V_2 )
continue;
F_148 ( V_113 ) ;
V_49 = F_111 ( V_168 , V_2 -> V_13 , F_5 ( V_2 ) ,
V_22 ) ;
if ( V_49 < 0 )
return V_49 ;
V_49 = F_111 ( V_113 , V_2 -> V_13 , F_5 ( V_2 ) , V_22 ) ;
if ( V_49 < 0 )
return V_49 ;
F_112 ( & V_171 ) ;
while ( ( V_170 = F_113 ( V_113 , & V_171 ) ) ) {
struct V_27 * V_116 ;
V_2 = F_6 ( V_170 ) ;
if ( V_169 )
F_1 ( V_2 , V_3 , 1 ) ;
else
F_2 ( V_2 , V_3 , 1 ) ;
F_25 (glist, &qg->groups, next_group) {
V_49 = F_111 ( V_168 , V_116 -> V_35 -> V_13 ,
F_5 ( V_116 -> V_35 ) ,
V_22 ) ;
if ( V_49 < 0 )
return V_49 ;
V_49 = F_111 ( V_113 , V_116 -> V_35 -> V_13 ,
F_5 ( V_116 -> V_35 ) ,
V_22 ) ;
if ( V_49 < 0 )
return V_49 ;
}
}
}
return 0 ;
}
static int F_149 ( struct V_11 * V_12 ,
struct V_112 * V_168 ,
T_1 V_173 ,
T_1 V_174 ,
T_1 V_110 , T_1 V_3 )
{
struct V_8 * V_117 ;
struct V_118 V_119 ;
struct V_1 * V_2 ;
T_1 V_175 , V_176 ;
F_112 ( & V_119 ) ;
while ( ( V_117 = F_113 ( V_168 , & V_119 ) ) ) {
bool V_26 = false ;
V_2 = F_6 ( V_117 ) ;
V_176 = F_3 ( V_2 , V_3 ) ;
V_175 = F_4 ( V_2 , V_3 ) ;
F_150 ( V_12 , V_2 -> V_13 ,
V_176 , V_175 ) ;
if ( V_176 == 0 && V_175 > 0 ) {
V_2 -> V_36 += V_110 ;
V_2 -> V_71 += V_110 ;
V_26 = true ;
}
if ( V_176 > 0 && V_175 == 0 ) {
V_2 -> V_36 -= V_110 ;
V_2 -> V_71 -= V_110 ;
V_26 = true ;
}
if ( V_176 == V_173 &&
V_175 < V_174 ) {
if ( V_176 != 0 ) {
V_2 -> V_37 -= V_110 ;
V_2 -> V_72 -= V_110 ;
V_26 = true ;
}
}
if ( V_176 < V_173 &&
V_175 == V_174 ) {
if ( V_175 != 0 ) {
V_2 -> V_37 += V_110 ;
V_2 -> V_72 += V_110 ;
V_26 = true ;
}
}
if ( V_176 == V_173 &&
V_175 == V_174 ) {
if ( V_176 == 0 ) {
if ( V_175 != 0 ) {
V_2 -> V_37 += V_110 ;
V_2 -> V_72 += V_110 ;
V_26 = true ;
}
} else {
if ( V_175 == 0 ) {
V_2 -> V_37 -= V_110 ;
V_2 -> V_72 -= V_110 ;
V_26 = true ;
}
}
}
if ( V_26 )
F_103 ( V_12 , V_2 ) ;
}
return 0 ;
}
static int F_151 ( struct V_112 * V_167 )
{
struct V_8 * V_117 ;
struct V_118 V_119 ;
if ( ! V_167 || V_167 -> V_177 == 0 )
return 1 ;
F_112 ( & V_119 ) ;
V_117 = F_113 ( V_167 , & V_119 ) ;
if ( ! V_117 )
return 1 ;
return F_152 ( V_117 -> V_172 ) ;
}
int
F_153 ( struct V_83 * V_84 ,
struct V_11 * V_12 ,
T_1 V_138 , T_1 V_110 ,
struct V_112 * V_142 , struct V_112 * V_178 )
{
struct V_112 * V_168 = NULL ;
struct V_112 * V_113 = NULL ;
T_1 V_3 ;
T_1 V_174 = 0 ;
T_1 V_173 = 0 ;
int V_49 = 0 ;
if ( ! F_28 ( V_52 , & V_12 -> V_50 ) )
return 0 ;
if ( V_178 ) {
if ( ! F_151 ( V_178 ) )
goto V_179;
V_174 = V_178 -> V_177 ;
}
if ( V_142 ) {
if ( ! F_151 ( V_142 ) )
goto V_179;
V_173 = V_142 -> V_177 ;
}
if ( V_173 == 0 && V_174 == 0 )
goto V_179;
F_138 ( ! V_12 -> V_43 ) ;
F_154 ( V_12 , V_138 , V_110 ,
V_173 , V_174 ) ;
V_168 = F_29 ( V_152 ) ;
if ( ! V_168 ) {
V_49 = - V_23 ;
goto V_179;
}
V_113 = F_29 ( V_152 ) ;
if ( ! V_113 ) {
V_49 = - V_23 ;
goto V_179;
}
F_88 ( & V_12 -> V_180 ) ;
if ( V_12 -> V_56 & V_82 ) {
if ( V_12 -> V_93 . V_57 <= V_138 ) {
F_95 ( & V_12 -> V_180 ) ;
V_49 = 0 ;
goto V_179;
}
}
F_95 ( & V_12 -> V_180 ) ;
F_92 ( & V_12 -> V_105 ) ;
V_3 = V_12 -> V_181 ;
V_49 = F_147 ( V_12 , V_142 , V_113 , V_168 , V_3 ,
V_182 ) ;
if ( V_49 < 0 )
goto V_55;
V_49 = F_147 ( V_12 , V_178 , V_113 , V_168 , V_3 ,
V_183 ) ;
if ( V_49 < 0 )
goto V_55;
F_149 ( V_12 , V_168 , V_173 , V_174 ,
V_110 , V_3 ) ;
V_12 -> V_181 += F_155 ( V_173 , V_174 ) + 1 ;
V_55:
F_93 ( & V_12 -> V_105 ) ;
V_179:
F_56 ( V_113 ) ;
F_56 ( V_168 ) ;
F_56 ( V_142 ) ;
F_56 ( V_178 ) ;
return V_49 ;
}
int F_156 ( struct V_83 * V_84 ,
struct V_11 * V_12 )
{
struct V_133 * V_134 ;
struct V_131 * V_132 ;
struct V_112 * V_178 = NULL ;
struct V_14 * V_17 ;
T_1 V_184 ;
int V_49 = 0 ;
V_132 = & V_84 -> V_144 -> V_132 ;
V_184 = V_132 -> V_184 ;
while ( ( V_17 = F_58 ( & V_132 -> V_135 ) ) ) {
V_134 = F_8 ( V_17 , struct V_133 ,
V_17 ) ;
F_157 ( V_12 , V_134 ) ;
if ( ! V_49 ) {
if ( F_107 ( ! V_134 -> V_142 ) ) {
V_49 = F_127 ( NULL , V_12 ,
V_134 -> V_138 , 0 ,
& V_134 -> V_142 ) ;
if ( V_49 < 0 )
goto V_185;
}
V_49 = F_127 ( V_84 , V_12 ,
V_134 -> V_138 , V_186 , & V_178 ) ;
if ( V_49 < 0 )
goto V_185;
if ( V_184 ) {
F_158 ( V_178 , V_184 , 0 ) ;
F_158 ( V_134 -> V_142 , V_184 ,
0 ) ;
}
V_49 = F_153 ( V_84 , V_12 ,
V_134 -> V_138 , V_134 -> V_110 ,
V_134 -> V_142 , V_178 ) ;
V_134 -> V_142 = NULL ;
V_178 = NULL ;
}
V_185:
F_56 ( V_134 -> V_142 ) ;
F_56 ( V_178 ) ;
V_178 = NULL ;
F_21 ( V_17 , & V_132 -> V_135 ) ;
F_19 ( V_134 ) ;
}
return V_49 ;
}
int F_159 ( struct V_83 * V_84 ,
struct V_11 * V_12 )
{
struct V_42 * V_43 = V_12 -> V_43 ;
int V_49 = 0 ;
int V_187 = 0 ;
if ( ! V_43 )
goto V_55;
if ( ! F_28 ( V_52 , & V_12 -> V_50 ) &&
F_28 ( V_98 , & V_12 -> V_50 ) )
V_187 = 1 ;
if ( F_160 ( V_98 , & V_12 -> V_50 ) )
F_89 ( V_52 , & V_12 -> V_50 ) ;
F_92 ( & V_12 -> V_105 ) ;
while ( ! F_17 ( & V_12 -> V_109 ) ) {
struct V_1 * V_16 ;
V_16 = F_18 ( & V_12 -> V_109 ,
struct V_1 , V_26 ) ;
F_161 ( & V_16 -> V_26 ) ;
F_93 ( & V_12 -> V_105 ) ;
V_49 = F_79 ( V_84 , V_43 , V_16 ) ;
if ( V_49 )
V_12 -> V_56 |=
V_66 ;
V_49 = F_78 ( V_84 , V_43 , V_16 ) ;
if ( V_49 )
V_12 -> V_56 |=
V_66 ;
F_92 ( & V_12 -> V_105 ) ;
}
if ( F_28 ( V_52 , & V_12 -> V_50 ) )
V_12 -> V_56 |= V_81 ;
else
V_12 -> V_56 &= ~ V_81 ;
F_93 ( & V_12 -> V_105 ) ;
V_49 = F_80 ( V_84 , V_12 , V_43 ) ;
if ( V_49 )
V_12 -> V_56 |= V_66 ;
if ( ! V_49 && V_187 ) {
V_49 = F_54 ( V_12 , 0 , 1 ) ;
if ( ! V_49 ) {
F_162 ( V_12 ) ;
F_163 ( V_12 -> V_188 ,
& V_12 -> V_189 ) ;
}
V_49 = 0 ;
}
V_55:
return V_49 ;
}
int F_164 ( struct V_83 * V_84 ,
struct V_11 * V_12 , T_1 V_190 , T_1 V_57 ,
struct F_164 * V_191 )
{
int V_49 = 0 ;
int V_146 ;
T_1 * V_192 ;
struct V_42 * V_43 = V_12 -> V_43 ;
struct V_1 * V_193 ;
struct V_1 * V_194 ;
T_3 V_195 = 0 ;
T_1 V_196 ;
F_88 ( & V_12 -> V_97 ) ;
if ( ! F_28 ( V_52 , & V_12 -> V_50 ) )
goto V_55;
if ( ! V_43 ) {
V_49 = - V_38 ;
goto V_55;
}
if ( V_191 ) {
V_192 = ( T_1 * ) ( V_191 + 1 ) ;
V_196 = V_191 -> V_197 + 2 * V_191 -> V_198 +
2 * V_191 -> V_199 ;
for ( V_146 = 0 ; V_146 < V_196 ; ++ V_146 ) {
V_193 = F_7 ( V_12 , * V_192 ) ;
if ( ! V_193 ||
( ( V_193 -> V_13 >> 48 ) <= ( V_57 >> 48 ) ) )
* V_192 = 0ULL ;
++ V_192 ;
}
}
V_49 = F_65 ( V_84 , V_43 , V_57 ) ;
if ( V_49 )
goto V_55;
if ( V_190 ) {
struct V_42 * V_200 ;
struct V_39 V_201 ;
V_201 . V_57 = V_190 ;
V_201 . type = V_202 ;
V_201 . V_58 = ( T_1 ) - 1 ;
V_200 = F_165 ( V_12 , & V_201 ) ;
if ( F_39 ( V_200 ) ) {
V_49 = F_40 ( V_200 ) ;
goto V_55;
}
V_195 = V_12 -> V_166 ;
}
if ( V_191 ) {
V_192 = ( T_1 * ) ( V_191 + 1 ) ;
for ( V_146 = 0 ; V_146 < V_191 -> V_197 ; ++ V_146 , ++ V_192 ) {
if ( * V_192 == 0 )
continue;
V_49 = F_59 ( V_84 , V_43 ,
V_57 , * V_192 ) ;
if ( V_49 && V_49 != - V_90 )
goto V_55;
V_49 = F_59 ( V_84 , V_43 ,
* V_192 , V_57 ) ;
if ( V_49 && V_49 != - V_90 )
goto V_55;
}
V_49 = 0 ;
}
F_92 ( & V_12 -> V_105 ) ;
V_194 = F_9 ( V_12 , V_57 ) ;
if ( F_39 ( V_194 ) ) {
V_49 = F_40 ( V_194 ) ;
goto V_203;
}
if ( V_191 && V_191 -> V_50 & V_204 ) {
V_194 -> V_74 = V_191 -> V_205 . V_50 ;
V_194 -> V_75 = V_191 -> V_205 . V_75 ;
V_194 -> V_76 = V_191 -> V_205 . V_76 ;
V_194 -> V_77 = V_191 -> V_205 . V_77 ;
V_194 -> V_78 = V_191 -> V_205 . V_78 ;
V_49 = F_78 ( V_84 , V_43 , V_194 ) ;
if ( V_49 ) {
V_12 -> V_56 |= V_66 ;
F_122 ( V_12 ,
L_6 ,
V_194 -> V_13 ) ;
goto V_203;
}
}
if ( V_190 ) {
V_193 = F_7 ( V_12 , V_190 ) ;
if ( ! V_193 )
goto V_203;
V_194 -> V_36 = V_193 -> V_36 ;
V_194 -> V_71 = V_193 -> V_71 ;
V_194 -> V_37 = V_195 ;
V_194 -> V_72 = V_195 ;
V_193 -> V_37 = V_195 ;
V_193 -> V_72 = V_195 ;
V_194 -> V_74 = V_193 -> V_74 ;
V_194 -> V_75 = V_193 -> V_75 ;
V_194 -> V_76 = V_193 -> V_76 ;
V_194 -> V_77 = V_193 -> V_77 ;
V_194 -> V_78 = V_193 -> V_78 ;
F_103 ( V_12 , V_194 ) ;
F_103 ( V_12 , V_193 ) ;
}
if ( ! V_191 )
goto V_203;
V_192 = ( T_1 * ) ( V_191 + 1 ) ;
for ( V_146 = 0 ; V_146 < V_191 -> V_197 ; ++ V_146 ) {
if ( * V_192 ) {
V_49 = F_22 ( V_12 , V_57 , * V_192 ) ;
if ( V_49 )
goto V_203;
}
++ V_192 ;
}
for ( V_146 = 0 ; V_146 < V_191 -> V_198 ; ++ V_146 , V_192 += 2 ) {
struct V_1 * V_85 ;
struct V_1 * V_86 ;
if ( ! V_192 [ 0 ] || ! V_192 [ 1 ] )
continue;
V_85 = F_7 ( V_12 , V_192 [ 0 ] ) ;
V_86 = F_7 ( V_12 , V_192 [ 1 ] ) ;
if ( ! V_85 || ! V_86 ) {
V_49 = - V_38 ;
goto V_203;
}
V_86 -> V_36 = V_85 -> V_36 - V_195 ;
V_86 -> V_71 = V_85 -> V_71 - V_195 ;
}
for ( V_146 = 0 ; V_146 < V_191 -> V_199 ; ++ V_146 , V_192 += 2 ) {
struct V_1 * V_85 ;
struct V_1 * V_86 ;
if ( ! V_192 [ 0 ] || ! V_192 [ 1 ] )
continue;
V_85 = F_7 ( V_12 , V_192 [ 0 ] ) ;
V_86 = F_7 ( V_12 , V_192 [ 1 ] ) ;
if ( ! V_85 || ! V_86 ) {
V_49 = - V_38 ;
goto V_203;
}
V_86 -> V_37 = V_85 -> V_37 + V_195 ;
V_86 -> V_72 = V_85 -> V_72 + V_195 ;
}
V_203:
F_93 ( & V_12 -> V_105 ) ;
V_55:
F_95 ( & V_12 -> V_97 ) ;
return V_49 ;
}
static bool F_166 ( const struct V_1 * V_2 , T_1 V_110 )
{
if ( ( V_2 -> V_74 & V_127 ) &&
V_2 -> V_111 + ( V_120 ) V_2 -> V_36 + V_110 > V_2 -> V_75 )
return false ;
if ( ( V_2 -> V_74 & V_128 ) &&
V_2 -> V_111 + ( V_120 ) V_2 -> V_37 + V_110 > V_2 -> V_76 )
return false ;
return true ;
}
static int F_167 ( struct V_42 * V_92 , T_1 V_110 , bool V_206 )
{
struct V_42 * V_43 ;
struct V_1 * V_16 ;
struct V_11 * V_12 = V_92 -> V_12 ;
T_1 V_114 = V_92 -> V_107 . V_57 ;
int V_49 = 0 ;
int V_207 = 0 ;
struct V_8 * V_117 ;
struct V_118 V_119 ;
if ( ! F_152 ( V_114 ) )
return 0 ;
if ( V_110 == 0 )
return 0 ;
if ( F_28 ( V_208 , & V_12 -> V_50 ) &&
F_168 ( V_209 ) )
V_206 = false ;
V_210:
F_92 ( & V_12 -> V_105 ) ;
V_43 = V_12 -> V_43 ;
if ( ! V_43 )
goto V_55;
V_16 = F_7 ( V_12 , V_114 ) ;
if ( ! V_16 )
goto V_55;
F_148 ( V_12 -> V_53 ) ;
V_49 = F_111 ( V_12 -> V_53 , V_16 -> V_13 ,
( V_7 ) V_16 , V_22 ) ;
if ( V_49 < 0 )
goto V_55;
F_112 ( & V_119 ) ;
while ( ( V_117 = F_113 ( V_12 -> V_53 , & V_119 ) ) ) {
struct V_1 * V_2 ;
struct V_27 * V_116 ;
V_2 = F_6 ( V_117 ) ;
if ( V_206 && ! F_166 ( V_2 , V_110 ) ) {
if ( ! V_207 && V_2 -> V_111 > 0 ) {
struct V_83 * V_84 ;
F_93 ( & V_12 -> V_105 ) ;
V_49 = F_169 ( V_92 , 0 ) ;
if ( V_49 )
return V_49 ;
F_170 ( V_92 , V_211 , 0 , ( T_1 ) - 1 ) ;
V_84 = F_171 ( V_92 ) ;
if ( F_39 ( V_84 ) )
return F_40 ( V_84 ) ;
V_49 = F_172 ( V_84 ) ;
if ( V_49 )
return V_49 ;
V_207 ++ ;
goto V_210;
}
V_49 = - V_212 ;
goto V_55;
}
F_25 (glist, &qg->groups, next_group) {
V_49 = F_111 ( V_12 -> V_53 ,
V_116 -> V_35 -> V_13 ,
( V_7 ) V_116 -> V_35 , V_22 ) ;
if ( V_49 < 0 )
goto V_55;
}
}
V_49 = 0 ;
F_112 ( & V_119 ) ;
while ( ( V_117 = F_113 ( V_12 -> V_53 , & V_119 ) ) ) {
struct V_1 * V_2 ;
V_2 = F_6 ( V_117 ) ;
F_110 ( V_12 , V_2 , V_110 ) ;
V_2 -> V_111 += V_110 ;
}
V_55:
F_93 ( & V_12 -> V_105 ) ;
return V_49 ;
}
void F_173 ( struct V_11 * V_12 ,
T_1 V_114 , T_1 V_110 )
{
struct V_42 * V_43 ;
struct V_1 * V_16 ;
struct V_8 * V_117 ;
struct V_118 V_119 ;
int V_49 = 0 ;
if ( ! F_152 ( V_114 ) )
return;
if ( V_110 == 0 )
return;
F_92 ( & V_12 -> V_105 ) ;
V_43 = V_12 -> V_43 ;
if ( ! V_43 )
goto V_55;
V_16 = F_7 ( V_12 , V_114 ) ;
if ( ! V_16 )
goto V_55;
F_148 ( V_12 -> V_53 ) ;
V_49 = F_111 ( V_12 -> V_53 , V_16 -> V_13 ,
( V_7 ) V_16 , V_22 ) ;
if ( V_49 < 0 )
goto V_55;
F_112 ( & V_119 ) ;
while ( ( V_117 = F_113 ( V_12 -> V_53 , & V_119 ) ) ) {
struct V_1 * V_2 ;
struct V_27 * V_116 ;
V_2 = F_6 ( V_117 ) ;
F_110 ( V_12 , V_2 , - ( V_120 ) V_110 ) ;
if ( V_2 -> V_111 < V_110 )
F_105 ( V_12 , V_2 , V_110 ) ;
else
V_2 -> V_111 -= V_110 ;
F_25 (glist, &qg->groups, next_group) {
V_49 = F_111 ( V_12 -> V_53 ,
V_116 -> V_35 -> V_13 ,
( V_7 ) V_116 -> V_35 , V_22 ) ;
if ( V_49 < 0 )
goto V_55;
}
}
V_55:
F_93 ( & V_12 -> V_105 ) ;
}
static int
F_174 ( struct V_11 * V_12 , struct V_44 * V_45 ,
struct V_83 * V_84 )
{
struct V_39 V_213 ;
struct V_46 * V_214 = NULL ;
struct V_112 * V_167 = NULL ;
struct V_215 V_216 = F_175 ( V_216 ) ;
T_1 V_110 ;
int V_48 ;
int V_49 ;
F_88 ( & V_12 -> V_180 ) ;
V_49 = F_31 ( V_12 -> V_217 ,
& V_12 -> V_93 ,
V_45 , 1 , 0 ) ;
F_108 ( V_12 ,
L_7 ,
V_12 -> V_93 . V_57 ,
V_12 -> V_93 . type ,
V_12 -> V_93 . V_58 , V_49 ) ;
if ( V_49 ) {
V_12 -> V_93 . V_57 = ( T_1 ) - 1 ;
F_51 ( V_45 ) ;
F_95 ( & V_12 -> V_180 ) ;
return V_49 ;
}
F_32 ( V_45 -> V_60 [ 0 ] , & V_213 ,
F_85 ( V_45 -> V_60 [ 0 ] ) - 1 ) ;
V_12 -> V_93 . V_57 = V_213 . V_57 + 1 ;
F_176 ( V_12 , & V_216 ) ;
V_214 = F_177 ( V_45 -> V_60 [ 0 ] ) ;
if ( ! V_214 ) {
V_49 = - V_23 ;
F_95 ( & V_12 -> V_180 ) ;
goto V_55;
}
F_141 ( V_214 ) ;
F_145 ( V_214 ) ;
F_146 ( V_214 , V_164 ) ;
V_48 = V_45 -> V_59 [ 0 ] ;
F_51 ( V_45 ) ;
F_95 ( & V_12 -> V_180 ) ;
for (; V_48 < F_85 ( V_214 ) ; ++ V_48 ) {
F_32 ( V_214 , & V_213 , V_48 ) ;
if ( V_213 . type != V_218 &&
V_213 . type != V_219 )
continue;
if ( V_213 . type == V_219 )
V_110 = V_12 -> V_166 ;
else
V_110 = V_213 . V_58 ;
V_49 = F_127 ( NULL , V_12 , V_213 . V_57 , 0 ,
& V_167 ) ;
if ( V_49 < 0 )
goto V_55;
V_49 = F_153 ( V_84 , V_12 ,
V_213 . V_57 , V_110 , NULL , V_167 ) ;
if ( V_49 < 0 )
goto V_55;
}
V_55:
if ( V_214 ) {
F_178 ( V_214 ) ;
F_94 ( V_214 ) ;
}
F_179 ( V_12 , & V_216 ) ;
return V_49 ;
}
static void F_180 ( struct V_220 * V_221 )
{
struct V_11 * V_12 = F_181 ( V_221 , struct V_11 ,
V_189 ) ;
struct V_44 * V_45 ;
struct V_83 * V_84 = NULL ;
int V_121 = - V_23 ;
int V_49 = 0 ;
V_45 = F_30 () ;
if ( ! V_45 )
goto V_55;
V_121 = 0 ;
while ( ! V_121 && ! F_182 ( V_12 ) ) {
V_84 = F_183 ( V_12 -> V_222 , 0 ) ;
if ( F_39 ( V_84 ) ) {
V_121 = F_40 ( V_84 ) ;
break;
}
if ( ! F_28 ( V_52 , & V_12 -> V_50 ) ) {
V_121 = - V_223 ;
} else {
V_121 = F_174 ( V_12 , V_45 , V_84 ) ;
}
if ( V_121 > 0 )
F_172 ( V_84 ) ;
else
F_184 ( V_84 ) ;
}
V_55:
F_55 ( V_45 ) ;
F_88 ( & V_12 -> V_180 ) ;
if ( ! F_182 ( V_12 ) )
V_12 -> V_56 &= ~ V_82 ;
if ( V_121 > 0 &&
V_12 -> V_56 & V_66 ) {
V_12 -> V_56 &= ~ V_66 ;
} else if ( V_121 < 0 ) {
V_12 -> V_56 |= V_66 ;
}
F_95 ( & V_12 -> V_180 ) ;
V_84 = F_183 ( V_12 -> V_43 , 1 ) ;
if ( F_39 ( V_84 ) ) {
V_121 = F_40 ( V_84 ) ;
F_35 ( V_12 ,
L_8 ,
V_121 ) ;
goto V_224;
}
V_49 = F_80 ( V_84 , V_12 , V_12 -> V_43 ) ;
if ( V_49 < 0 ) {
V_121 = V_49 ;
F_35 ( V_12 , L_9 , V_121 ) ;
}
F_184 ( V_84 ) ;
if ( F_182 ( V_12 ) ) {
F_122 ( V_12 , L_10 ) ;
} else if ( V_121 >= 0 ) {
F_122 ( V_12 , L_11 ,
V_121 > 0 ? L_12 : L_13 ) ;
} else {
F_35 ( V_12 , L_14 , V_121 ) ;
}
V_224:
F_88 ( & V_12 -> V_180 ) ;
V_12 -> V_225 = false ;
F_95 ( & V_12 -> V_180 ) ;
F_185 ( & V_12 -> V_226 ) ;
}
static int
F_54 ( struct V_11 * V_12 , T_1 V_227 ,
int V_228 )
{
int V_49 = 0 ;
if ( ! V_228 &&
( ! ( V_12 -> V_56 & V_82 ) ||
! ( V_12 -> V_56 & V_81 ) ) ) {
V_49 = - V_38 ;
goto V_121;
}
F_88 ( & V_12 -> V_180 ) ;
F_92 ( & V_12 -> V_105 ) ;
if ( V_228 ) {
if ( V_12 -> V_56 & V_82 )
V_49 = - V_229 ;
else if ( ! ( V_12 -> V_56 & V_81 ) )
V_49 = - V_38 ;
if ( V_49 ) {
F_93 ( & V_12 -> V_105 ) ;
F_95 ( & V_12 -> V_180 ) ;
goto V_121;
}
V_12 -> V_56 |= V_82 ;
}
memset ( & V_12 -> V_93 , 0 ,
sizeof( V_12 -> V_93 ) ) ;
V_12 -> V_93 . V_57 = V_227 ;
F_186 ( & V_12 -> V_226 ) ;
V_12 -> V_225 = true ;
F_93 ( & V_12 -> V_105 ) ;
F_95 ( & V_12 -> V_180 ) ;
memset ( & V_12 -> V_189 , 0 ,
sizeof( V_12 -> V_189 ) ) ;
F_187 ( & V_12 -> V_189 ,
V_230 ,
F_180 , NULL , NULL ) ;
if ( V_49 ) {
V_121:
F_122 ( V_12 , L_15 , V_49 ) ;
return V_49 ;
}
return 0 ;
}
static void
F_162 ( struct V_11 * V_12 )
{
struct V_14 * V_9 ;
struct V_1 * V_16 ;
F_92 ( & V_12 -> V_105 ) ;
for ( V_9 = F_58 ( & V_12 -> V_15 ) ; V_9 ; V_9 = F_188 ( V_9 ) ) {
V_16 = F_8 ( V_9 , struct V_1 , V_17 ) ;
V_16 -> V_36 = 0 ;
V_16 -> V_71 = 0 ;
V_16 -> V_37 = 0 ;
V_16 -> V_72 = 0 ;
}
F_93 ( & V_12 -> V_105 ) ;
}
int
F_189 ( struct V_11 * V_12 )
{
int V_49 = 0 ;
struct V_83 * V_84 ;
V_49 = F_54 ( V_12 , 0 , 1 ) ;
if ( V_49 )
return V_49 ;
V_84 = F_171 ( V_12 -> V_222 ) ;
if ( F_39 ( V_84 ) ) {
V_12 -> V_56 &= ~ V_82 ;
return F_40 ( V_84 ) ;
}
V_49 = F_172 ( V_84 ) ;
if ( V_49 ) {
V_12 -> V_56 &= ~ V_82 ;
return V_49 ;
}
F_162 ( V_12 ) ;
F_163 ( V_12 -> V_188 ,
& V_12 -> V_189 ) ;
return 0 ;
}
int F_97 ( struct V_11 * V_12 ,
bool V_231 )
{
int V_232 ;
int V_49 = 0 ;
F_88 ( & V_12 -> V_180 ) ;
F_92 ( & V_12 -> V_105 ) ;
V_232 = V_12 -> V_225 ;
F_93 ( & V_12 -> V_105 ) ;
F_95 ( & V_12 -> V_180 ) ;
if ( ! V_232 )
return 0 ;
if ( V_231 )
V_49 = F_190 (
& V_12 -> V_226 ) ;
else
F_191 ( & V_12 -> V_226 ) ;
return V_49 ;
}
void
F_192 ( struct V_11 * V_12 )
{
if ( V_12 -> V_56 & V_82 )
F_163 ( V_12 -> V_188 ,
& V_12 -> V_189 ) ;
}
int F_193 ( struct V_233 * V_233 ,
struct V_234 * * V_235 , T_1 V_236 ,
T_1 V_237 )
{
struct V_42 * V_92 = F_194 ( V_233 ) -> V_92 ;
struct V_8 * V_117 ;
struct V_118 V_119 ;
struct V_234 * V_111 ;
T_1 V_238 ;
T_1 V_239 ;
int V_49 ;
if ( ! F_28 ( V_52 , & V_92 -> V_12 -> V_50 ) ||
! F_152 ( V_92 -> V_57 ) || V_237 == 0 )
return 0 ;
if ( F_107 ( ! V_235 ) )
return - V_38 ;
if ( ! * V_235 ) {
* V_235 = F_195 () ;
if ( ! * V_235 )
return - V_23 ;
}
V_111 = * V_235 ;
V_238 = V_111 -> V_240 ;
V_49 = F_196 ( & F_194 ( V_233 ) -> V_241 , V_236 ,
V_236 + V_237 - 1 , V_242 , V_111 ) ;
V_239 = V_111 -> V_240 - V_238 ;
F_197 ( V_233 , V_236 , V_237 ,
V_239 , V_243 ) ;
if ( V_49 < 0 )
goto V_185;
V_49 = F_167 ( V_92 , V_239 , true ) ;
if ( V_49 < 0 )
goto V_185;
return V_49 ;
V_185:
F_112 ( & V_119 ) ;
while ( ( V_117 = F_113 ( & V_111 -> V_244 , & V_119 ) ) )
F_198 ( & F_194 ( V_233 ) -> V_241 , V_117 -> V_172 ,
V_117 -> V_10 , V_242 , 0 , 0 , NULL ,
V_152 ) ;
F_199 ( V_111 ) ;
return V_49 ;
}
static int F_200 ( struct V_233 * V_233 ,
struct V_234 * V_111 , T_1 V_236 , T_1 V_237 )
{
struct V_42 * V_92 = F_194 ( V_233 ) -> V_92 ;
struct V_8 * V_117 ;
struct V_118 V_119 ;
struct V_234 V_245 ;
int V_246 = 0 ;
int V_49 ;
F_201 ( & V_245 ) ;
V_237 = F_202 ( V_236 + V_237 , V_92 -> V_12 -> V_247 ) ;
V_236 = F_203 ( V_236 , V_92 -> V_12 -> V_247 ) ;
F_112 ( & V_119 ) ;
while ( ( V_117 = F_113 ( & V_111 -> V_244 , & V_119 ) ) ) {
T_1 V_248 = V_117 -> V_172 ;
T_1 V_249 = V_117 -> V_10 - V_248 + 1 ;
T_1 V_250 ;
T_1 V_251 ;
F_199 ( & V_245 ) ;
if ( V_248 >= V_236 + V_237 ||
V_248 + V_249 <= V_236 )
continue;
V_250 = F_155 ( V_248 , V_236 ) ;
V_251 = F_204 ( V_236 + V_237 , V_248 + V_249 ) -
V_250 ;
V_49 = F_205 ( & F_194 ( V_233 ) -> V_252 ,
V_250 , V_250 + V_251 - 1 ,
V_242 , & V_245 ) ;
if ( V_49 < 0 )
goto V_55;
V_246 += V_245 . V_240 ;
}
F_173 ( V_92 -> V_12 , V_92 -> V_57 , V_246 ) ;
V_49 = V_246 ;
V_55:
F_199 ( & V_245 ) ;
return V_49 ;
}
static int F_206 ( struct V_233 * V_233 ,
struct V_234 * V_111 , T_1 V_236 , T_1 V_237 ,
int free )
{
struct V_234 V_245 ;
int V_253 = V_254 ;
int V_49 ;
F_107 ( ! free && V_111 ) ;
if ( free && V_111 )
return F_200 ( V_233 , V_111 , V_236 , V_237 ) ;
F_201 ( & V_245 ) ;
V_49 = F_205 ( & F_194 ( V_233 ) -> V_241 , V_236 ,
V_236 + V_237 - 1 , V_242 , & V_245 ) ;
if ( V_49 < 0 )
goto V_55;
if ( free )
V_253 = V_255 ;
F_207 ( V_233 , V_236 , V_237 ,
V_245 . V_240 , V_253 ) ;
if ( free )
F_173 ( F_194 ( V_233 ) -> V_92 -> V_12 ,
F_194 ( V_233 ) -> V_92 -> V_57 ,
V_245 . V_240 ) ;
V_49 = V_245 . V_240 ;
V_55:
F_199 ( & V_245 ) ;
return V_49 ;
}
int F_208 ( struct V_233 * V_233 ,
struct V_234 * V_111 , T_1 V_236 , T_1 V_237 )
{
return F_206 ( V_233 , V_111 , V_236 , V_237 , 1 ) ;
}
int F_209 ( struct V_233 * V_233 , T_1 V_236 , T_1 V_237 )
{
return F_206 ( V_233 , NULL , V_236 , V_237 , 0 ) ;
}
int F_210 ( struct V_42 * V_92 , int V_110 ,
bool V_206 )
{
struct V_11 * V_12 = V_92 -> V_12 ;
int V_49 ;
if ( ! F_28 ( V_52 , & V_12 -> V_50 ) ||
! F_152 ( V_92 -> V_57 ) || V_110 == 0 )
return 0 ;
F_138 ( V_110 != F_203 ( V_110 , V_12 -> V_166 ) ) ;
F_211 ( V_92 , ( V_120 ) V_110 ) ;
V_49 = F_167 ( V_92 , V_110 , V_206 ) ;
if ( V_49 < 0 )
return V_49 ;
F_212 ( V_110 , & V_92 -> V_256 ) ;
return V_49 ;
}
void F_213 ( struct V_42 * V_92 )
{
struct V_11 * V_12 = V_92 -> V_12 ;
T_1 V_111 ;
if ( ! F_28 ( V_52 , & V_12 -> V_50 ) ||
! F_152 ( V_92 -> V_57 ) )
return;
V_111 = F_214 ( & V_92 -> V_256 , 0 ) ;
if ( V_111 == 0 )
return;
F_211 ( V_92 , - ( V_120 ) V_111 ) ;
F_173 ( V_12 , V_92 -> V_57 , V_111 ) ;
}
void F_215 ( struct V_42 * V_92 , int V_110 )
{
struct V_11 * V_12 = V_92 -> V_12 ;
if ( ! F_28 ( V_52 , & V_12 -> V_50 ) ||
! F_152 ( V_92 -> V_57 ) )
return;
F_138 ( V_110 != F_203 ( V_110 , V_12 -> V_166 ) ) ;
F_107 ( F_216 ( & V_92 -> V_256 ) < V_110 ) ;
F_217 ( V_110 , & V_92 -> V_256 ) ;
F_211 ( V_92 , - ( V_120 ) V_110 ) ;
F_173 ( V_12 , V_92 -> V_57 , V_110 ) ;
}
void F_218 ( struct V_233 * V_233 )
{
struct V_234 V_245 ;
struct V_8 * V_117 ;
struct V_118 V_257 ;
int V_49 ;
F_201 ( & V_245 ) ;
V_49 = F_205 ( & F_194 ( V_233 ) -> V_241 , 0 , ( T_1 ) - 1 ,
V_242 , & V_245 ) ;
F_107 ( V_49 < 0 ) ;
if ( F_107 ( V_245 . V_240 ) ) {
F_112 ( & V_257 ) ;
while ( ( V_117 = F_113 ( & V_245 . V_244 , & V_257 ) ) ) {
F_52 ( F_194 ( V_233 ) -> V_92 -> V_12 ,
L_16 ,
V_233 -> V_258 , V_117 -> V_172 , V_117 -> V_10 ) ;
}
F_173 ( F_194 ( V_233 ) -> V_92 -> V_12 ,
F_194 ( V_233 ) -> V_92 -> V_57 ,
V_245 . V_240 ) ;
}
F_199 ( & V_245 ) ;
}
