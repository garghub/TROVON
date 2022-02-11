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
F_87 ( V_96 , & V_92 -> V_12 -> V_50 ) ;
F_55 ( V_45 ) ;
return V_49 ;
}
int F_88 ( struct V_83 * V_84 ,
struct V_11 * V_12 )
{
struct V_42 * V_43 ;
struct V_42 * V_97 = V_12 -> V_97 ;
struct V_44 * V_45 = NULL ;
struct V_62 * V_63 ;
struct V_46 * V_89 ;
struct V_39 V_40 ;
struct V_39 V_41 ;
struct V_1 * V_16 = NULL ;
int V_49 = 0 ;
int V_48 ;
F_89 ( & V_12 -> V_98 ) ;
if ( V_12 -> V_43 ) {
F_87 ( V_99 , & V_12 -> V_50 ) ;
goto V_55;
}
V_12 -> V_53 = F_29 ( V_54 ) ;
if ( ! V_12 -> V_53 ) {
V_49 = - V_23 ;
goto V_55;
}
V_43 = F_90 ( V_84 , V_12 ,
V_100 ) ;
if ( F_39 ( V_43 ) ) {
V_49 = F_40 ( V_43 ) ;
goto V_55;
}
V_45 = F_30 () ;
if ( ! V_45 ) {
V_49 = - V_23 ;
goto V_101;
}
V_40 . V_57 = 0 ;
V_40 . type = V_61 ;
V_40 . V_58 = 0 ;
V_49 = F_60 ( V_84 , V_43 , V_45 , & V_40 ,
sizeof( * V_63 ) ) ;
if ( V_49 )
goto V_102;
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
V_40 . type = V_103 ;
V_40 . V_58 = 0 ;
F_51 ( V_45 ) ;
V_49 = F_31 ( V_97 , & V_40 , V_45 , 1 , 0 ) ;
if ( V_49 > 0 )
goto V_104;
if ( V_49 < 0 )
goto V_102;
while ( 1 ) {
V_48 = V_45 -> V_59 [ 0 ] ;
V_89 = V_45 -> V_60 [ 0 ] ;
F_32 ( V_89 , & V_41 , V_48 ) ;
if ( V_41 . type == V_103 ) {
V_49 = F_65 ( V_84 , V_43 ,
V_41 . V_58 ) ;
if ( V_49 )
goto V_102;
V_16 = F_9 ( V_12 , V_41 . V_58 ) ;
if ( F_39 ( V_16 ) ) {
V_49 = F_40 ( V_16 ) ;
goto V_102;
}
}
V_49 = F_50 ( V_97 , V_45 ) ;
if ( V_49 < 0 )
goto V_102;
if ( V_49 )
break;
}
V_104:
F_51 ( V_45 ) ;
V_49 = F_65 ( V_84 , V_43 , V_105 ) ;
if ( V_49 )
goto V_102;
V_16 = F_9 ( V_12 , V_105 ) ;
if ( F_39 ( V_16 ) ) {
V_49 = F_40 ( V_16 ) ;
goto V_102;
}
F_92 ( & V_12 -> V_106 ) ;
V_12 -> V_43 = V_43 ;
F_87 ( V_99 , & V_12 -> V_50 ) ;
F_93 ( & V_12 -> V_106 ) ;
V_102:
F_55 ( V_45 ) ;
V_101:
if ( V_49 ) {
F_94 ( V_43 -> V_17 ) ;
F_94 ( V_43 -> V_107 ) ;
F_19 ( V_43 ) ;
}
V_55:
if ( V_49 ) {
F_56 ( V_12 -> V_53 ) ;
V_12 -> V_53 = NULL ;
}
F_95 ( & V_12 -> V_98 ) ;
return V_49 ;
}
int F_96 ( struct V_83 * V_84 ,
struct V_11 * V_12 )
{
struct V_42 * V_97 = V_12 -> V_97 ;
struct V_42 * V_43 ;
int V_49 = 0 ;
F_89 ( & V_12 -> V_98 ) ;
if ( ! V_12 -> V_43 )
goto V_55;
F_53 ( V_52 , & V_12 -> V_50 ) ;
F_87 ( V_96 , & V_12 -> V_50 ) ;
F_97 ( V_12 , false ) ;
F_92 ( & V_12 -> V_106 ) ;
V_43 = V_12 -> V_43 ;
V_12 -> V_43 = NULL ;
V_12 -> V_56 &= ~ V_81 ;
F_93 ( & V_12 -> V_106 ) ;
F_57 ( V_12 ) ;
V_49 = F_84 ( V_84 , V_43 ) ;
if ( V_49 )
goto V_55;
V_49 = F_98 ( V_84 , V_97 , & V_43 -> V_108 ) ;
if ( V_49 )
goto V_55;
F_16 ( & V_43 -> V_109 ) ;
F_99 ( V_43 -> V_17 ) ;
F_100 ( V_84 , V_12 , V_43 -> V_17 ) ;
F_101 ( V_43 -> V_17 ) ;
F_102 ( V_84 , V_43 , V_43 -> V_17 , 0 , 1 ) ;
F_94 ( V_43 -> V_17 ) ;
F_94 ( V_43 -> V_107 ) ;
F_19 ( V_43 ) ;
V_55:
F_95 ( & V_12 -> V_98 ) ;
return V_49 ;
}
static void F_103 ( struct V_11 * V_12 ,
struct V_1 * V_16 )
{
if ( F_17 ( & V_16 -> V_26 ) )
F_104 ( & V_16 -> V_26 , & V_12 -> V_110 ) ;
}
static int F_105 ( struct V_11 * V_12 ,
struct V_111 * V_112 , T_1 V_113 ,
T_1 V_114 , int V_115 )
{
struct V_1 * V_16 ;
struct V_27 * V_116 ;
struct V_8 * V_117 ;
struct V_118 V_119 ;
int V_49 = 0 ;
V_16 = F_7 ( V_12 , V_113 ) ;
if ( ! V_16 )
goto V_55;
V_16 -> V_36 += V_115 * V_114 ;
V_16 -> V_71 += V_115 * V_114 ;
F_106 ( V_115 < 0 && V_16 -> V_37 < V_114 ) ;
V_16 -> V_37 += V_115 * V_114 ;
V_16 -> V_72 += V_115 * V_114 ;
if ( V_115 > 0 )
V_16 -> V_120 -= V_114 ;
F_103 ( V_12 , V_16 ) ;
F_25 (glist, &qgroup->groups, next_group) {
V_49 = F_107 ( V_112 , V_116 -> V_35 -> V_13 ,
F_5 ( V_116 -> V_35 ) , V_22 ) ;
if ( V_49 < 0 )
goto V_55;
}
F_108 ( & V_119 ) ;
while ( ( V_117 = F_109 ( V_112 , & V_119 ) ) ) {
V_16 = F_6 ( V_117 ) ;
V_16 -> V_36 += V_115 * V_114 ;
V_16 -> V_71 += V_115 * V_114 ;
F_106 ( V_115 < 0 && V_16 -> V_37 < V_114 ) ;
V_16 -> V_37 += V_115 * V_114 ;
if ( V_115 > 0 )
V_16 -> V_120 -= V_114 ;
V_16 -> V_72 += V_115 * V_114 ;
F_103 ( V_12 , V_16 ) ;
F_25 (glist, &qgroup->groups, next_group) {
V_49 = F_107 ( V_112 , V_116 -> V_35 -> V_13 ,
F_5 ( V_116 -> V_35 ) , V_22 ) ;
if ( V_49 < 0 )
goto V_55;
}
}
V_49 = 0 ;
V_55:
return V_49 ;
}
static int F_110 ( struct V_11 * V_12 ,
struct V_111 * V_112 , T_1 V_85 , T_1 V_86 ,
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
V_121 = F_105 ( V_12 , V_112 , V_86 ,
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
int F_111 ( struct V_83 * V_84 ,
struct V_11 * V_12 , T_1 V_85 , T_1 V_86 )
{
struct V_42 * V_43 ;
struct V_1 * V_21 ;
struct V_1 * V_34 ;
struct V_27 * V_28 ;
struct V_111 * V_112 ;
int V_49 = 0 ;
if ( F_112 ( V_85 ) >= F_112 ( V_86 ) )
return - V_38 ;
V_112 = F_29 ( V_54 ) ;
if ( ! V_112 )
return - V_23 ;
F_89 ( & V_12 -> V_98 ) ;
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
F_92 ( & V_12 -> V_106 ) ;
V_49 = F_22 ( V_12 , V_85 , V_86 ) ;
if ( V_49 < 0 ) {
F_93 ( & V_12 -> V_106 ) ;
goto V_55;
}
V_49 = F_110 ( V_12 , V_112 , V_85 , V_86 , 1 ) ;
F_93 ( & V_12 -> V_106 ) ;
V_55:
F_95 ( & V_12 -> V_98 ) ;
F_56 ( V_112 ) ;
return V_49 ;
}
int F_113 ( struct V_83 * V_84 ,
struct V_11 * V_12 , T_1 V_85 , T_1 V_86 )
{
struct V_42 * V_43 ;
struct V_1 * V_21 ;
struct V_1 * V_34 ;
struct V_27 * V_28 ;
struct V_111 * V_112 ;
int V_49 = 0 ;
int V_121 ;
V_112 = F_29 ( V_54 ) ;
if ( ! V_112 )
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
F_92 ( & V_12 -> V_106 ) ;
F_24 ( V_12 , V_85 , V_86 ) ;
V_49 = F_110 ( V_12 , V_112 , V_85 , V_86 , - 1 ) ;
F_93 ( & V_12 -> V_106 ) ;
V_55:
F_56 ( V_112 ) ;
return V_49 ;
}
int F_114 ( struct V_83 * V_84 ,
struct V_11 * V_12 , T_1 V_85 , T_1 V_86 )
{
int V_49 = 0 ;
F_89 ( & V_12 -> V_98 ) ;
V_49 = F_113 ( V_84 , V_12 , V_85 , V_86 ) ;
F_95 ( & V_12 -> V_98 ) ;
return V_49 ;
}
int F_115 ( struct V_83 * V_84 ,
struct V_11 * V_12 , T_1 V_13 )
{
struct V_42 * V_43 ;
struct V_1 * V_16 ;
int V_49 = 0 ;
F_89 ( & V_12 -> V_98 ) ;
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
F_92 ( & V_12 -> V_106 ) ;
V_16 = F_9 ( V_12 , V_13 ) ;
F_93 ( & V_12 -> V_106 ) ;
if ( F_39 ( V_16 ) )
V_49 = F_40 ( V_16 ) ;
V_55:
F_95 ( & V_12 -> V_98 ) ;
return V_49 ;
}
int F_116 ( struct V_83 * V_84 ,
struct V_11 * V_12 , T_1 V_13 )
{
struct V_42 * V_43 ;
struct V_1 * V_16 ;
struct V_27 * V_28 ;
int V_49 = 0 ;
F_89 ( & V_12 -> V_98 ) ;
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
while ( ! F_17 ( & V_16 -> V_24 ) ) {
V_28 = F_18 ( & V_16 -> V_24 ,
struct V_27 , V_29 ) ;
V_49 = F_113 ( V_84 , V_12 ,
V_13 ,
V_28 -> V_35 -> V_13 ) ;
if ( V_49 )
goto V_55;
}
F_92 ( & V_12 -> V_106 ) ;
F_20 ( V_12 , V_13 ) ;
F_93 ( & V_12 -> V_106 ) ;
V_55:
F_95 ( & V_12 -> V_98 ) ;
return V_49 ;
}
int F_117 ( struct V_83 * V_84 ,
struct V_11 * V_12 , T_1 V_13 ,
struct V_124 * V_125 )
{
struct V_42 * V_43 ;
struct V_1 * V_16 ;
int V_49 = 0 ;
const T_1 V_126 = - 1 ;
F_89 ( & V_12 -> V_98 ) ;
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
F_92 ( & V_12 -> V_106 ) ;
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
F_93 ( & V_12 -> V_106 ) ;
V_49 = F_78 ( V_84 , V_43 , V_16 ) ;
if ( V_49 ) {
V_12 -> V_56 |= V_66 ;
F_118 ( V_12 , L_5 ,
V_13 ) ;
}
V_55:
F_95 ( & V_12 -> V_98 ) ;
return V_49 ;
}
int F_119 ( struct V_83 * V_84 ,
struct V_11 * V_12 )
{
struct V_131 * V_132 ;
struct V_133 * V_134 ;
struct V_14 * V_17 ;
T_1 V_135 ;
int V_49 = 0 ;
V_134 = & V_84 -> V_136 -> V_134 ;
V_135 = V_134 -> V_135 ;
V_17 = F_58 ( & V_134 -> V_137 ) ;
while ( V_17 ) {
V_132 = F_8 ( V_17 , struct V_131 ,
V_17 ) ;
V_49 = F_120 ( NULL , V_12 , V_132 -> V_138 , 0 ,
& V_132 -> V_139 ) ;
if ( V_49 < 0 )
break;
if ( V_135 )
F_121 ( V_132 -> V_139 , V_135 , 0 ) ;
V_17 = F_122 ( V_17 ) ;
}
return V_49 ;
}
int F_123 ( struct V_11 * V_12 ,
struct V_133 * V_134 ,
struct V_131 * V_132 )
{
struct V_14 * * V_20 = & V_134 -> V_137 . V_14 ;
struct V_14 * V_140 = NULL ;
struct V_131 * V_141 ;
T_1 V_138 = V_132 -> V_138 ;
F_124 ( & V_134 -> V_142 ) ;
F_125 ( V_12 , V_132 ) ;
while ( * V_20 ) {
V_140 = * V_20 ;
V_141 = F_8 ( V_140 , struct V_131 ,
V_17 ) ;
if ( V_138 < V_141 -> V_138 )
V_20 = & ( * V_20 ) -> V_18 ;
else if ( V_138 > V_141 -> V_138 )
V_20 = & ( * V_20 ) -> V_19 ;
else
return 1 ;
}
F_13 ( & V_132 -> V_17 , V_140 , V_20 ) ;
F_14 ( & V_132 -> V_17 , & V_134 -> V_137 ) ;
return 0 ;
}
int F_126 ( struct V_83 * V_84 ,
struct V_11 * V_12 , T_1 V_138 , T_1 V_114 ,
T_2 V_143 )
{
struct V_131 * V_132 ;
struct V_133 * V_134 ;
int V_49 ;
if ( ! F_28 ( V_52 , & V_12 -> V_50 )
|| V_138 == 0 || V_114 == 0 )
return 0 ;
if ( F_106 ( V_84 == NULL ) )
return - V_38 ;
V_132 = F_127 ( sizeof( * V_132 ) , V_143 ) ;
if ( ! V_132 )
return - V_23 ;
V_134 = & V_84 -> V_136 -> V_134 ;
V_132 -> V_138 = V_138 ;
V_132 -> V_114 = V_114 ;
V_132 -> V_139 = NULL ;
F_92 ( & V_134 -> V_142 ) ;
V_49 = F_123 ( V_12 , V_134 , V_132 ) ;
F_93 ( & V_134 -> V_142 ) ;
if ( V_49 > 0 )
F_19 ( V_132 ) ;
return 0 ;
}
int F_128 ( struct V_83 * V_84 ,
struct V_11 * V_12 ,
struct V_46 * V_144 )
{
int V_94 = F_85 ( V_144 ) ;
int V_145 , V_146 , V_49 ;
struct V_39 V_40 ;
struct V_147 * V_148 ;
T_1 V_138 , V_114 ;
if ( ! F_28 ( V_52 , & V_12 -> V_50 ) )
return 0 ;
for ( V_145 = 0 ; V_145 < V_94 ; V_145 ++ ) {
F_32 ( V_144 , & V_40 , V_145 ) ;
if ( V_40 . type != V_149 )
continue;
V_148 = F_33 ( V_144 , V_145 , struct V_147 ) ;
V_146 = F_129 ( V_144 , V_148 ) ;
if ( V_146 == V_150 )
continue;
V_138 = F_130 ( V_144 , V_148 ) ;
if ( ! V_138 )
continue;
V_114 = F_131 ( V_144 , V_148 ) ;
V_49 = F_126 ( V_84 , V_12 , V_138 ,
V_114 , V_54 ) ;
if ( V_49 )
return V_49 ;
}
return 0 ;
}
static int F_132 ( struct V_42 * V_92 ,
struct V_44 * V_45 , int V_151 )
{
int V_152 = 0 ;
int V_94 , V_48 ;
struct V_46 * V_144 ;
if ( V_151 == 0 )
return 1 ;
while ( V_152 <= V_151 ) {
V_144 = V_45 -> V_60 [ V_152 ] ;
V_94 = F_85 ( V_144 ) ;
V_45 -> V_59 [ V_152 ] ++ ;
V_48 = V_45 -> V_59 [ V_152 ] ;
if ( V_48 >= V_94 || V_152 == 0 ) {
if ( V_152 != V_151 ) {
F_133 ( V_144 , V_45 -> V_153 [ V_152 ] ) ;
V_45 -> V_153 [ V_152 ] = 0 ;
F_94 ( V_144 ) ;
V_45 -> V_60 [ V_152 ] = NULL ;
V_45 -> V_59 [ V_152 ] = 0 ;
}
} else {
break;
}
V_152 ++ ;
}
V_144 = V_45 -> V_60 [ V_151 ] ;
if ( V_45 -> V_59 [ V_151 ] >= F_85 ( V_144 ) )
return 1 ;
return 0 ;
}
int F_134 ( struct V_83 * V_84 ,
struct V_42 * V_92 ,
struct V_46 * V_154 ,
T_1 V_155 , int V_151 )
{
struct V_11 * V_12 = V_92 -> V_12 ;
int V_49 = 0 ;
int V_152 ;
struct V_46 * V_144 = V_154 ;
struct V_44 * V_45 = NULL ;
F_135 ( V_151 < 0 || V_151 > V_156 ) ;
F_135 ( V_154 == NULL ) ;
if ( ! F_28 ( V_52 , & V_12 -> V_50 ) )
return 0 ;
if ( ! F_136 ( V_154 ) ) {
V_49 = F_137 ( V_154 , V_155 ) ;
if ( V_49 )
goto V_55;
}
if ( V_151 == 0 ) {
V_49 = F_128 ( V_84 , V_12 , V_154 ) ;
goto V_55;
}
V_45 = F_30 () ;
if ( ! V_45 )
return - V_23 ;
F_138 ( V_154 ) ;
V_45 -> V_60 [ V_151 ] = V_154 ;
V_45 -> V_59 [ V_151 ] = 0 ;
V_45 -> V_153 [ V_151 ] = 0 ;
V_157:
V_152 = V_151 ;
while ( V_152 >= 0 ) {
if ( V_45 -> V_60 [ V_152 ] == NULL ) {
int V_158 ;
T_1 V_159 ;
T_1 V_160 ;
V_144 = V_45 -> V_60 [ V_152 + 1 ] ;
V_158 = V_45 -> V_59 [ V_152 + 1 ] ;
V_160 = F_139 ( V_144 , V_158 ) ;
V_159 = F_140 ( V_144 , V_158 ) ;
V_144 = F_141 ( V_12 , V_160 , V_159 ) ;
if ( F_39 ( V_144 ) ) {
V_49 = F_40 ( V_144 ) ;
goto V_55;
} else if ( ! F_136 ( V_144 ) ) {
F_94 ( V_144 ) ;
V_49 = - V_161 ;
goto V_55;
}
V_45 -> V_60 [ V_152 ] = V_144 ;
V_45 -> V_59 [ V_152 ] = 0 ;
F_142 ( V_144 ) ;
F_143 ( V_144 , V_162 ) ;
V_45 -> V_153 [ V_152 ] = V_163 ;
V_49 = F_126 ( V_84 , V_12 ,
V_160 ,
V_12 -> V_164 ,
V_54 ) ;
if ( V_49 )
goto V_55;
}
if ( V_152 == 0 ) {
V_49 = F_128 ( V_84 , V_12 ,
V_45 -> V_60 [ V_152 ] ) ;
if ( V_49 )
goto V_55;
V_49 = F_132 ( V_92 , V_45 , V_151 ) ;
if ( V_49 )
break;
goto V_157;
}
V_152 -- ;
}
V_49 = 0 ;
V_55:
F_55 ( V_45 ) ;
return V_49 ;
}
static int F_144 ( struct V_11 * V_12 ,
struct V_111 * V_165 , struct V_111 * V_112 ,
struct V_111 * V_166 , T_1 V_3 , int V_167 )
{
struct V_8 * V_117 ;
struct V_118 V_119 ;
struct V_8 * V_168 ;
struct V_118 V_169 ;
struct V_1 * V_2 ;
int V_49 = 0 ;
if ( ! V_165 )
return 0 ;
F_108 ( & V_119 ) ;
while ( ( V_117 = F_109 ( V_165 , & V_119 ) ) ) {
V_2 = F_7 ( V_12 , V_117 -> V_170 ) ;
if ( ! V_2 )
continue;
F_145 ( V_112 ) ;
V_49 = F_107 ( V_166 , V_2 -> V_13 , F_5 ( V_2 ) ,
V_22 ) ;
if ( V_49 < 0 )
return V_49 ;
V_49 = F_107 ( V_112 , V_2 -> V_13 , F_5 ( V_2 ) , V_22 ) ;
if ( V_49 < 0 )
return V_49 ;
F_108 ( & V_169 ) ;
while ( ( V_168 = F_109 ( V_112 , & V_169 ) ) ) {
struct V_27 * V_116 ;
V_2 = F_6 ( V_168 ) ;
if ( V_167 )
F_1 ( V_2 , V_3 , 1 ) ;
else
F_2 ( V_2 , V_3 , 1 ) ;
F_25 (glist, &qg->groups, next_group) {
V_49 = F_107 ( V_166 , V_116 -> V_35 -> V_13 ,
F_5 ( V_116 -> V_35 ) ,
V_22 ) ;
if ( V_49 < 0 )
return V_49 ;
V_49 = F_107 ( V_112 , V_116 -> V_35 -> V_13 ,
F_5 ( V_116 -> V_35 ) ,
V_22 ) ;
if ( V_49 < 0 )
return V_49 ;
}
}
}
return 0 ;
}
static int F_146 ( struct V_11 * V_12 ,
struct V_111 * V_166 ,
T_1 V_171 ,
T_1 V_172 ,
T_1 V_114 , T_1 V_3 )
{
struct V_8 * V_117 ;
struct V_118 V_119 ;
struct V_1 * V_2 ;
T_1 V_173 , V_174 ;
F_108 ( & V_119 ) ;
while ( ( V_117 = F_109 ( V_166 , & V_119 ) ) ) {
bool V_26 = false ;
V_2 = F_6 ( V_117 ) ;
V_174 = F_3 ( V_2 , V_3 ) ;
V_173 = F_4 ( V_2 , V_3 ) ;
F_147 ( V_12 , V_2 -> V_13 ,
V_174 , V_173 ) ;
if ( V_174 == 0 && V_173 > 0 ) {
V_2 -> V_36 += V_114 ;
V_2 -> V_71 += V_114 ;
V_26 = true ;
}
if ( V_174 > 0 && V_173 == 0 ) {
V_2 -> V_36 -= V_114 ;
V_2 -> V_71 -= V_114 ;
V_26 = true ;
}
if ( V_174 == V_171 &&
V_173 < V_172 ) {
if ( V_174 != 0 ) {
V_2 -> V_37 -= V_114 ;
V_2 -> V_72 -= V_114 ;
V_26 = true ;
}
}
if ( V_174 < V_171 &&
V_173 == V_172 ) {
if ( V_173 != 0 ) {
V_2 -> V_37 += V_114 ;
V_2 -> V_72 += V_114 ;
V_26 = true ;
}
}
if ( V_174 == V_171 &&
V_173 == V_172 ) {
if ( V_174 == 0 ) {
if ( V_173 != 0 ) {
V_2 -> V_37 += V_114 ;
V_2 -> V_72 += V_114 ;
V_26 = true ;
}
} else {
if ( V_173 == 0 ) {
V_2 -> V_37 -= V_114 ;
V_2 -> V_72 -= V_114 ;
V_26 = true ;
}
}
}
if ( V_26 )
F_103 ( V_12 , V_2 ) ;
}
return 0 ;
}
int
F_148 ( struct V_83 * V_84 ,
struct V_11 * V_12 ,
T_1 V_138 , T_1 V_114 ,
struct V_111 * V_139 , struct V_111 * V_175 )
{
struct V_111 * V_166 = NULL ;
struct V_111 * V_112 = NULL ;
T_1 V_3 ;
T_1 V_172 = 0 ;
T_1 V_171 = 0 ;
int V_49 = 0 ;
if ( V_175 )
V_172 = V_175 -> V_176 ;
if ( V_139 )
V_171 = V_139 -> V_176 ;
if ( ! F_28 ( V_52 , & V_12 -> V_50 ) )
goto V_177;
F_135 ( ! V_12 -> V_43 ) ;
F_149 ( V_12 , V_138 , V_114 ,
V_171 , V_172 ) ;
V_166 = F_29 ( V_54 ) ;
if ( ! V_166 ) {
V_49 = - V_23 ;
goto V_177;
}
V_112 = F_29 ( V_54 ) ;
if ( ! V_112 ) {
V_49 = - V_23 ;
goto V_177;
}
F_89 ( & V_12 -> V_178 ) ;
if ( V_12 -> V_56 & V_82 ) {
if ( V_12 -> V_93 . V_57 <= V_138 ) {
F_95 ( & V_12 -> V_178 ) ;
V_49 = 0 ;
goto V_177;
}
}
F_95 ( & V_12 -> V_178 ) ;
F_92 ( & V_12 -> V_106 ) ;
V_3 = V_12 -> V_179 ;
V_49 = F_144 ( V_12 , V_139 , V_112 , V_166 , V_3 ,
V_180 ) ;
if ( V_49 < 0 )
goto V_55;
V_49 = F_144 ( V_12 , V_175 , V_112 , V_166 , V_3 ,
V_181 ) ;
if ( V_49 < 0 )
goto V_55;
F_146 ( V_12 , V_166 , V_171 , V_172 ,
V_114 , V_3 ) ;
V_12 -> V_179 += F_150 ( V_171 , V_172 ) + 1 ;
V_55:
F_93 ( & V_12 -> V_106 ) ;
V_177:
F_56 ( V_112 ) ;
F_56 ( V_166 ) ;
F_56 ( V_139 ) ;
F_56 ( V_175 ) ;
return V_49 ;
}
int F_151 ( struct V_83 * V_84 ,
struct V_11 * V_12 )
{
struct V_131 * V_132 ;
struct V_133 * V_134 ;
struct V_111 * V_175 = NULL ;
struct V_14 * V_17 ;
T_1 V_135 ;
int V_49 = 0 ;
V_134 = & V_84 -> V_136 -> V_134 ;
V_135 = V_134 -> V_135 ;
while ( ( V_17 = F_58 ( & V_134 -> V_137 ) ) ) {
V_132 = F_8 ( V_17 , struct V_131 ,
V_17 ) ;
F_152 ( V_12 , V_132 ) ;
if ( ! V_49 ) {
V_49 = F_120 ( V_84 , V_12 ,
V_132 -> V_138 , ( T_1 ) - 1 , & V_175 ) ;
if ( V_49 < 0 )
goto V_182;
if ( V_135 )
F_121 ( V_175 , V_135 , 0 ) ;
V_49 = F_148 ( V_84 , V_12 ,
V_132 -> V_138 , V_132 -> V_114 ,
V_132 -> V_139 , V_175 ) ;
V_132 -> V_139 = NULL ;
V_175 = NULL ;
}
V_182:
F_56 ( V_132 -> V_139 ) ;
F_56 ( V_175 ) ;
V_175 = NULL ;
F_21 ( V_17 , & V_134 -> V_137 ) ;
F_19 ( V_132 ) ;
}
return V_49 ;
}
int F_153 ( struct V_83 * V_84 ,
struct V_11 * V_12 )
{
struct V_42 * V_43 = V_12 -> V_43 ;
int V_49 = 0 ;
int V_183 = 0 ;
if ( ! V_43 )
goto V_55;
if ( ! F_28 ( V_52 , & V_12 -> V_50 ) &&
F_28 ( V_99 , & V_12 -> V_50 ) )
V_183 = 1 ;
if ( F_154 ( V_99 , & V_12 -> V_50 ) )
F_87 ( V_52 , & V_12 -> V_50 ) ;
if ( F_154 ( V_96 , & V_12 -> V_50 ) )
F_53 ( V_52 , & V_12 -> V_50 ) ;
F_92 ( & V_12 -> V_106 ) ;
while ( ! F_17 ( & V_12 -> V_110 ) ) {
struct V_1 * V_16 ;
V_16 = F_18 ( & V_12 -> V_110 ,
struct V_1 , V_26 ) ;
F_155 ( & V_16 -> V_26 ) ;
F_93 ( & V_12 -> V_106 ) ;
V_49 = F_79 ( V_84 , V_43 , V_16 ) ;
if ( V_49 )
V_12 -> V_56 |=
V_66 ;
V_49 = F_78 ( V_84 , V_43 , V_16 ) ;
if ( V_49 )
V_12 -> V_56 |=
V_66 ;
F_92 ( & V_12 -> V_106 ) ;
}
if ( F_28 ( V_52 , & V_12 -> V_50 ) )
V_12 -> V_56 |= V_81 ;
else
V_12 -> V_56 &= ~ V_81 ;
F_93 ( & V_12 -> V_106 ) ;
V_49 = F_80 ( V_84 , V_12 , V_43 ) ;
if ( V_49 )
V_12 -> V_56 |= V_66 ;
if ( ! V_49 && V_183 ) {
V_49 = F_54 ( V_12 , 0 , 1 ) ;
if ( ! V_49 ) {
F_156 ( V_12 ) ;
F_157 ( V_12 -> V_184 ,
& V_12 -> V_185 ) ;
}
V_49 = 0 ;
}
V_55:
return V_49 ;
}
int F_158 ( struct V_83 * V_84 ,
struct V_11 * V_12 , T_1 V_186 , T_1 V_57 ,
struct F_158 * V_187 )
{
int V_49 = 0 ;
int V_145 ;
T_1 * V_188 ;
struct V_42 * V_43 = V_12 -> V_43 ;
struct V_1 * V_189 ;
struct V_1 * V_190 ;
T_3 V_191 = 0 ;
T_1 V_192 ;
F_89 ( & V_12 -> V_98 ) ;
if ( ! F_28 ( V_52 , & V_12 -> V_50 ) )
goto V_55;
if ( ! V_43 ) {
V_49 = - V_38 ;
goto V_55;
}
if ( V_187 ) {
V_188 = ( T_1 * ) ( V_187 + 1 ) ;
V_192 = V_187 -> V_193 + 2 * V_187 -> V_194 +
2 * V_187 -> V_195 ;
for ( V_145 = 0 ; V_145 < V_192 ; ++ V_145 ) {
V_189 = F_7 ( V_12 , * V_188 ) ;
if ( ! V_189 ||
( ( V_189 -> V_13 >> 48 ) <= ( V_57 >> 48 ) ) )
* V_188 = 0ULL ;
++ V_188 ;
}
}
V_49 = F_65 ( V_84 , V_43 , V_57 ) ;
if ( V_49 )
goto V_55;
if ( V_186 ) {
struct V_42 * V_196 ;
struct V_39 V_197 ;
V_197 . V_57 = V_186 ;
V_197 . type = V_198 ;
V_197 . V_58 = ( T_1 ) - 1 ;
V_196 = F_159 ( V_12 , & V_197 ) ;
if ( F_39 ( V_196 ) ) {
V_49 = F_40 ( V_196 ) ;
goto V_55;
}
F_160 () ;
V_191 = V_12 -> V_164 ;
F_161 () ;
}
if ( V_187 ) {
V_188 = ( T_1 * ) ( V_187 + 1 ) ;
for ( V_145 = 0 ; V_145 < V_187 -> V_193 ; ++ V_145 , ++ V_188 ) {
if ( * V_188 == 0 )
continue;
V_49 = F_59 ( V_84 , V_43 ,
V_57 , * V_188 ) ;
if ( V_49 && V_49 != - V_90 )
goto V_55;
V_49 = F_59 ( V_84 , V_43 ,
* V_188 , V_57 ) ;
if ( V_49 && V_49 != - V_90 )
goto V_55;
}
V_49 = 0 ;
}
F_92 ( & V_12 -> V_106 ) ;
V_190 = F_9 ( V_12 , V_57 ) ;
if ( F_39 ( V_190 ) ) {
V_49 = F_40 ( V_190 ) ;
goto V_199;
}
if ( V_187 && V_187 -> V_50 & V_200 ) {
V_190 -> V_74 = V_187 -> V_201 . V_50 ;
V_190 -> V_75 = V_187 -> V_201 . V_75 ;
V_190 -> V_76 = V_187 -> V_201 . V_76 ;
V_190 -> V_77 = V_187 -> V_201 . V_77 ;
V_190 -> V_78 = V_187 -> V_201 . V_78 ;
V_49 = F_78 ( V_84 , V_43 , V_190 ) ;
if ( V_49 ) {
V_12 -> V_56 |= V_66 ;
F_118 ( V_12 ,
L_5 ,
V_190 -> V_13 ) ;
goto V_199;
}
}
if ( V_186 ) {
V_189 = F_7 ( V_12 , V_186 ) ;
if ( ! V_189 )
goto V_199;
V_190 -> V_36 = V_189 -> V_36 ;
V_190 -> V_71 = V_189 -> V_71 ;
V_190 -> V_37 = V_191 ;
V_190 -> V_72 = V_191 ;
V_189 -> V_37 = V_191 ;
V_189 -> V_72 = V_191 ;
V_190 -> V_74 = V_189 -> V_74 ;
V_190 -> V_75 = V_189 -> V_75 ;
V_190 -> V_76 = V_189 -> V_76 ;
V_190 -> V_77 = V_189 -> V_77 ;
V_190 -> V_78 = V_189 -> V_78 ;
F_103 ( V_12 , V_190 ) ;
F_103 ( V_12 , V_189 ) ;
}
if ( ! V_187 )
goto V_199;
V_188 = ( T_1 * ) ( V_187 + 1 ) ;
for ( V_145 = 0 ; V_145 < V_187 -> V_193 ; ++ V_145 ) {
if ( * V_188 ) {
V_49 = F_22 ( V_12 , V_57 , * V_188 ) ;
if ( V_49 )
goto V_199;
}
++ V_188 ;
}
for ( V_145 = 0 ; V_145 < V_187 -> V_194 ; ++ V_145 , V_188 += 2 ) {
struct V_1 * V_85 ;
struct V_1 * V_86 ;
if ( ! V_188 [ 0 ] || ! V_188 [ 1 ] )
continue;
V_85 = F_7 ( V_12 , V_188 [ 0 ] ) ;
V_86 = F_7 ( V_12 , V_188 [ 1 ] ) ;
if ( ! V_85 || ! V_86 ) {
V_49 = - V_38 ;
goto V_199;
}
V_86 -> V_36 = V_85 -> V_36 - V_191 ;
V_86 -> V_71 = V_85 -> V_71 - V_191 ;
}
for ( V_145 = 0 ; V_145 < V_187 -> V_195 ; ++ V_145 , V_188 += 2 ) {
struct V_1 * V_85 ;
struct V_1 * V_86 ;
if ( ! V_188 [ 0 ] || ! V_188 [ 1 ] )
continue;
V_85 = F_7 ( V_12 , V_188 [ 0 ] ) ;
V_86 = F_7 ( V_12 , V_188 [ 1 ] ) ;
if ( ! V_85 || ! V_86 ) {
V_49 = - V_38 ;
goto V_199;
}
V_86 -> V_37 = V_85 -> V_37 + V_191 ;
V_86 -> V_72 = V_85 -> V_72 + V_191 ;
}
V_199:
F_93 ( & V_12 -> V_106 ) ;
V_55:
F_95 ( & V_12 -> V_98 ) ;
return V_49 ;
}
static int F_162 ( struct V_42 * V_92 , T_1 V_114 )
{
struct V_42 * V_43 ;
struct V_1 * V_16 ;
struct V_11 * V_12 = V_92 -> V_12 ;
T_1 V_113 = V_92 -> V_108 . V_57 ;
int V_49 = 0 ;
struct V_8 * V_117 ;
struct V_118 V_119 ;
if ( ! F_163 ( V_113 ) )
return 0 ;
if ( V_114 == 0 )
return 0 ;
F_92 ( & V_12 -> V_106 ) ;
V_43 = V_12 -> V_43 ;
if ( ! V_43 )
goto V_55;
V_16 = F_7 ( V_12 , V_113 ) ;
if ( ! V_16 )
goto V_55;
F_145 ( V_12 -> V_53 ) ;
V_49 = F_107 ( V_12 -> V_53 , V_16 -> V_13 ,
( V_7 ) V_16 , V_22 ) ;
if ( V_49 < 0 )
goto V_55;
F_108 ( & V_119 ) ;
while ( ( V_117 = F_109 ( V_12 -> V_53 , & V_119 ) ) ) {
struct V_1 * V_2 ;
struct V_27 * V_116 ;
V_2 = F_6 ( V_117 ) ;
if ( ( V_2 -> V_74 & V_127 ) &&
V_2 -> V_120 + ( V_202 ) V_2 -> V_36 + V_114 >
V_2 -> V_75 ) {
V_49 = - V_203 ;
goto V_55;
}
if ( ( V_2 -> V_74 & V_128 ) &&
V_2 -> V_120 + ( V_202 ) V_2 -> V_37 + V_114 >
V_2 -> V_76 ) {
V_49 = - V_203 ;
goto V_55;
}
F_25 (glist, &qg->groups, next_group) {
V_49 = F_107 ( V_12 -> V_53 ,
V_116 -> V_35 -> V_13 ,
( V_7 ) V_116 -> V_35 , V_22 ) ;
if ( V_49 < 0 )
goto V_55;
}
}
V_49 = 0 ;
F_108 ( & V_119 ) ;
while ( ( V_117 = F_109 ( V_12 -> V_53 , & V_119 ) ) ) {
struct V_1 * V_2 ;
V_2 = F_6 ( V_117 ) ;
V_2 -> V_120 += V_114 ;
}
V_55:
F_93 ( & V_12 -> V_106 ) ;
return V_49 ;
}
void F_164 ( struct V_11 * V_12 ,
T_1 V_113 , T_1 V_114 )
{
struct V_42 * V_43 ;
struct V_1 * V_16 ;
struct V_8 * V_117 ;
struct V_118 V_119 ;
int V_49 = 0 ;
if ( ! F_163 ( V_113 ) )
return;
if ( V_114 == 0 )
return;
F_92 ( & V_12 -> V_106 ) ;
V_43 = V_12 -> V_43 ;
if ( ! V_43 )
goto V_55;
V_16 = F_7 ( V_12 , V_113 ) ;
if ( ! V_16 )
goto V_55;
F_145 ( V_12 -> V_53 ) ;
V_49 = F_107 ( V_12 -> V_53 , V_16 -> V_13 ,
( V_7 ) V_16 , V_22 ) ;
if ( V_49 < 0 )
goto V_55;
F_108 ( & V_119 ) ;
while ( ( V_117 = F_109 ( V_12 -> V_53 , & V_119 ) ) ) {
struct V_1 * V_2 ;
struct V_27 * V_116 ;
V_2 = F_6 ( V_117 ) ;
V_2 -> V_120 -= V_114 ;
F_25 (glist, &qg->groups, next_group) {
V_49 = F_107 ( V_12 -> V_53 ,
V_116 -> V_35 -> V_13 ,
( V_7 ) V_116 -> V_35 , V_22 ) ;
if ( V_49 < 0 )
goto V_55;
}
}
V_55:
F_93 ( & V_12 -> V_106 ) ;
}
static inline void F_165 ( struct V_42 * V_92 , T_1 V_114 )
{
return F_164 ( V_92 -> V_12 , V_92 -> V_57 ,
V_114 ) ;
}
void F_166 ( struct V_83 * V_84 )
{
if ( F_17 ( & V_84 -> V_204 ) && ! V_84 -> V_205 . V_3 )
return;
F_35 ( V_84 -> V_12 ,
L_6 ,
V_84 , F_17 ( & V_84 -> V_204 ) ? L_7 : L_8 ,
( T_3 ) ( V_84 -> V_205 . V_3 >> 32 ) ,
( T_3 ) V_84 -> V_205 . V_3 ) ;
F_167 () ;
}
static int
F_168 ( struct V_11 * V_12 , struct V_44 * V_45 ,
struct V_83 * V_84 )
{
struct V_39 V_206 ;
struct V_46 * V_207 = NULL ;
struct V_111 * V_165 = NULL ;
struct V_208 V_209 = F_169 ( V_209 ) ;
T_1 V_114 ;
int V_48 ;
int V_49 ;
F_89 ( & V_12 -> V_178 ) ;
V_49 = F_31 ( V_12 -> V_210 ,
& V_12 -> V_93 ,
V_45 , 1 , 0 ) ;
F_170 ( V_12 ,
L_9 ,
V_12 -> V_93 . V_57 ,
V_12 -> V_93 . type ,
V_12 -> V_93 . V_58 , V_49 ) ;
if ( V_49 ) {
V_12 -> V_93 . V_57 = ( T_1 ) - 1 ;
F_51 ( V_45 ) ;
F_95 ( & V_12 -> V_178 ) ;
return V_49 ;
}
F_32 ( V_45 -> V_60 [ 0 ] , & V_206 ,
F_85 ( V_45 -> V_60 [ 0 ] ) - 1 ) ;
V_12 -> V_93 . V_57 = V_206 . V_57 + 1 ;
F_171 ( V_12 , & V_209 ) ;
V_207 = F_172 ( V_45 -> V_60 [ 0 ] ) ;
if ( ! V_207 ) {
V_49 = - V_23 ;
F_95 ( & V_12 -> V_178 ) ;
goto V_55;
}
F_138 ( V_207 ) ;
F_142 ( V_207 ) ;
F_143 ( V_207 , V_162 ) ;
V_48 = V_45 -> V_59 [ 0 ] ;
F_51 ( V_45 ) ;
F_95 ( & V_12 -> V_178 ) ;
for (; V_48 < F_85 ( V_207 ) ; ++ V_48 ) {
F_32 ( V_207 , & V_206 , V_48 ) ;
if ( V_206 . type != V_211 &&
V_206 . type != V_212 )
continue;
if ( V_206 . type == V_212 )
V_114 = V_12 -> V_164 ;
else
V_114 = V_206 . V_58 ;
V_49 = F_120 ( NULL , V_12 , V_206 . V_57 , 0 ,
& V_165 ) ;
if ( V_49 < 0 )
goto V_55;
V_49 = F_148 ( V_84 , V_12 ,
V_206 . V_57 , V_114 , NULL , V_165 ) ;
if ( V_49 < 0 )
goto V_55;
}
V_55:
if ( V_207 ) {
F_173 ( V_207 ) ;
F_94 ( V_207 ) ;
}
F_174 ( V_12 , & V_209 ) ;
return V_49 ;
}
static void F_175 ( struct V_213 * V_214 )
{
struct V_11 * V_12 = F_176 ( V_214 , struct V_11 ,
V_185 ) ;
struct V_44 * V_45 ;
struct V_83 * V_84 = NULL ;
int V_121 = - V_23 ;
int V_49 = 0 ;
V_45 = F_30 () ;
if ( ! V_45 )
goto V_55;
V_121 = 0 ;
while ( ! V_121 && ! F_177 ( V_12 ) ) {
V_84 = F_178 ( V_12 -> V_215 , 0 ) ;
if ( F_39 ( V_84 ) ) {
V_121 = F_40 ( V_84 ) ;
break;
}
if ( ! F_28 ( V_52 , & V_12 -> V_50 ) ) {
V_121 = - V_216 ;
} else {
V_121 = F_168 ( V_12 , V_45 , V_84 ) ;
}
if ( V_121 > 0 )
F_179 ( V_84 ) ;
else
F_180 ( V_84 ) ;
}
V_55:
F_55 ( V_45 ) ;
F_89 ( & V_12 -> V_178 ) ;
if ( ! F_177 ( V_12 ) )
V_12 -> V_56 &= ~ V_82 ;
if ( V_121 > 0 &&
V_12 -> V_56 & V_66 ) {
V_12 -> V_56 &= ~ V_66 ;
} else if ( V_121 < 0 ) {
V_12 -> V_56 |= V_66 ;
}
F_95 ( & V_12 -> V_178 ) ;
V_84 = F_178 ( V_12 -> V_43 , 1 ) ;
if ( F_39 ( V_84 ) ) {
V_121 = F_40 ( V_84 ) ;
F_35 ( V_12 ,
L_10 ,
V_121 ) ;
goto V_217;
}
V_49 = F_80 ( V_84 , V_12 , V_12 -> V_43 ) ;
if ( V_49 < 0 ) {
V_121 = V_49 ;
F_35 ( V_12 , L_11 , V_121 ) ;
}
F_180 ( V_84 ) ;
if ( F_177 ( V_12 ) ) {
F_118 ( V_12 , L_12 ) ;
} else if ( V_121 >= 0 ) {
F_118 ( V_12 , L_13 ,
V_121 > 0 ? L_14 : L_7 ) ;
} else {
F_35 ( V_12 , L_15 , V_121 ) ;
}
V_217:
F_89 ( & V_12 -> V_178 ) ;
V_12 -> V_218 = false ;
F_95 ( & V_12 -> V_178 ) ;
F_181 ( & V_12 -> V_219 ) ;
}
static int
F_54 ( struct V_11 * V_12 , T_1 V_220 ,
int V_221 )
{
int V_49 = 0 ;
if ( ! V_221 &&
( ! ( V_12 -> V_56 & V_82 ) ||
! ( V_12 -> V_56 & V_81 ) ) ) {
V_49 = - V_38 ;
goto V_121;
}
F_89 ( & V_12 -> V_178 ) ;
F_92 ( & V_12 -> V_106 ) ;
if ( V_221 ) {
if ( V_12 -> V_56 & V_82 )
V_49 = - V_222 ;
else if ( ! ( V_12 -> V_56 & V_81 ) )
V_49 = - V_38 ;
if ( V_49 ) {
F_93 ( & V_12 -> V_106 ) ;
F_95 ( & V_12 -> V_178 ) ;
goto V_121;
}
V_12 -> V_56 |= V_82 ;
}
memset ( & V_12 -> V_93 , 0 ,
sizeof( V_12 -> V_93 ) ) ;
V_12 -> V_93 . V_57 = V_220 ;
F_182 ( & V_12 -> V_219 ) ;
V_12 -> V_218 = true ;
F_93 ( & V_12 -> V_106 ) ;
F_95 ( & V_12 -> V_178 ) ;
memset ( & V_12 -> V_185 , 0 ,
sizeof( V_12 -> V_185 ) ) ;
F_183 ( & V_12 -> V_185 ,
V_223 ,
F_175 , NULL , NULL ) ;
if ( V_49 ) {
V_121:
F_118 ( V_12 , L_16 , V_49 ) ;
return V_49 ;
}
return 0 ;
}
static void
F_156 ( struct V_11 * V_12 )
{
struct V_14 * V_9 ;
struct V_1 * V_16 ;
F_92 ( & V_12 -> V_106 ) ;
for ( V_9 = F_58 ( & V_12 -> V_15 ) ; V_9 ; V_9 = F_122 ( V_9 ) ) {
V_16 = F_8 ( V_9 , struct V_1 , V_17 ) ;
V_16 -> V_36 = 0 ;
V_16 -> V_71 = 0 ;
V_16 -> V_37 = 0 ;
V_16 -> V_72 = 0 ;
}
F_93 ( & V_12 -> V_106 ) ;
}
int
F_184 ( struct V_11 * V_12 )
{
int V_49 = 0 ;
struct V_83 * V_84 ;
V_49 = F_54 ( V_12 , 0 , 1 ) ;
if ( V_49 )
return V_49 ;
V_84 = F_185 ( V_12 -> V_215 ) ;
if ( F_39 ( V_84 ) ) {
V_12 -> V_56 &= ~ V_82 ;
return F_40 ( V_84 ) ;
}
V_49 = F_179 ( V_84 ) ;
if ( V_49 ) {
V_12 -> V_56 &= ~ V_82 ;
return V_49 ;
}
F_156 ( V_12 ) ;
F_157 ( V_12 -> V_184 ,
& V_12 -> V_185 ) ;
return 0 ;
}
int F_97 ( struct V_11 * V_12 ,
bool V_224 )
{
int V_225 ;
int V_49 = 0 ;
F_89 ( & V_12 -> V_178 ) ;
F_92 ( & V_12 -> V_106 ) ;
V_225 = V_12 -> V_218 ;
F_93 ( & V_12 -> V_106 ) ;
F_95 ( & V_12 -> V_178 ) ;
if ( ! V_225 )
return 0 ;
if ( V_224 )
V_49 = F_186 (
& V_12 -> V_219 ) ;
else
F_187 ( & V_12 -> V_219 ) ;
return V_49 ;
}
void
F_188 ( struct V_11 * V_12 )
{
if ( V_12 -> V_56 & V_82 )
F_157 ( V_12 -> V_184 ,
& V_12 -> V_185 ) ;
}
int F_189 ( struct V_226 * V_226 , T_1 V_227 , T_1 V_228 )
{
struct V_42 * V_92 = F_190 ( V_226 ) -> V_92 ;
struct V_229 V_230 ;
struct V_8 * V_117 ;
struct V_118 V_119 ;
int V_49 ;
if ( ! F_28 ( V_52 , & V_92 -> V_12 -> V_50 ) ||
! F_163 ( V_92 -> V_57 ) || V_228 == 0 )
return 0 ;
V_230 . V_231 = 0 ;
V_230 . V_232 = F_29 ( V_54 ) ;
V_49 = F_191 ( & F_190 ( V_226 ) -> V_233 , V_227 ,
V_227 + V_228 - 1 , V_234 , & V_230 ) ;
F_192 ( V_226 , V_227 , V_228 ,
V_230 . V_231 ,
V_235 ) ;
if ( V_49 < 0 )
goto V_182;
V_49 = F_162 ( V_92 , V_230 . V_231 ) ;
if ( V_49 < 0 )
goto V_182;
F_56 ( V_230 . V_232 ) ;
return V_49 ;
V_182:
F_108 ( & V_119 ) ;
while ( ( V_117 = F_109 ( V_230 . V_232 , & V_119 ) ) )
F_193 ( & F_190 ( V_226 ) -> V_233 , V_117 -> V_170 ,
V_117 -> V_10 , V_234 , 0 , 0 , NULL ,
V_54 ) ;
F_56 ( V_230 . V_232 ) ;
return V_49 ;
}
static int F_194 ( struct V_226 * V_226 , T_1 V_227 , T_1 V_228 ,
int free )
{
struct V_229 V_230 ;
int V_236 = V_237 ;
int V_49 ;
V_230 . V_231 = 0 ;
V_230 . V_232 = F_29 ( V_54 ) ;
if ( ! V_230 . V_232 )
return - V_23 ;
V_49 = F_195 ( & F_190 ( V_226 ) -> V_233 , V_227 ,
V_227 + V_228 - 1 , V_234 , & V_230 ) ;
if ( V_49 < 0 )
goto V_55;
if ( free ) {
F_165 ( F_190 ( V_226 ) -> V_92 , V_230 . V_231 ) ;
V_236 = V_238 ;
}
F_196 ( V_226 , V_227 , V_228 ,
V_230 . V_231 , V_236 ) ;
V_55:
F_56 ( V_230 . V_232 ) ;
return V_49 ;
}
int F_197 ( struct V_226 * V_226 , T_1 V_227 , T_1 V_228 )
{
return F_194 ( V_226 , V_227 , V_228 , 1 ) ;
}
int F_198 ( struct V_226 * V_226 , T_1 V_227 , T_1 V_228 )
{
return F_194 ( V_226 , V_227 , V_228 , 0 ) ;
}
int F_199 ( struct V_42 * V_92 , int V_114 )
{
struct V_11 * V_12 = V_92 -> V_12 ;
int V_49 ;
if ( ! F_28 ( V_52 , & V_12 -> V_50 ) ||
! F_163 ( V_92 -> V_57 ) || V_114 == 0 )
return 0 ;
F_135 ( V_114 != F_200 ( V_114 , V_12 -> V_164 ) ) ;
V_49 = F_162 ( V_92 , V_114 ) ;
if ( V_49 < 0 )
return V_49 ;
F_201 ( V_114 , & V_92 -> V_239 ) ;
return V_49 ;
}
void F_202 ( struct V_42 * V_92 )
{
struct V_11 * V_12 = V_92 -> V_12 ;
int V_120 ;
if ( ! F_28 ( V_52 , & V_12 -> V_50 ) ||
! F_163 ( V_92 -> V_57 ) )
return;
V_120 = F_203 ( & V_92 -> V_239 , 0 ) ;
if ( V_120 == 0 )
return;
F_165 ( V_92 , V_120 ) ;
}
void F_204 ( struct V_42 * V_92 , int V_114 )
{
struct V_11 * V_12 = V_92 -> V_12 ;
if ( ! F_28 ( V_52 , & V_12 -> V_50 ) ||
! F_163 ( V_92 -> V_57 ) )
return;
F_135 ( V_114 != F_200 ( V_114 , V_12 -> V_164 ) ) ;
F_106 ( F_205 ( & V_92 -> V_239 ) < V_114 ) ;
F_206 ( V_114 , & V_92 -> V_239 ) ;
F_165 ( V_92 , V_114 ) ;
}
void F_207 ( struct V_226 * V_226 )
{
struct V_229 V_230 ;
struct V_8 * V_117 ;
struct V_118 V_240 ;
int V_49 ;
V_230 . V_231 = 0 ;
V_230 . V_232 = F_29 ( V_54 ) ;
if ( F_106 ( ! V_230 . V_232 ) )
return;
V_49 = F_195 ( & F_190 ( V_226 ) -> V_233 , 0 , ( T_1 ) - 1 ,
V_234 , & V_230 ) ;
F_106 ( V_49 < 0 ) ;
if ( F_106 ( V_230 . V_231 ) ) {
F_108 ( & V_240 ) ;
while ( ( V_117 = F_109 ( V_230 . V_232 , & V_240 ) ) ) {
F_52 ( F_190 ( V_226 ) -> V_92 -> V_12 ,
L_17 ,
V_226 -> V_241 , V_117 -> V_170 , V_117 -> V_10 ) ;
}
F_165 ( F_190 ( V_226 ) -> V_92 , V_230 . V_231 ) ;
}
F_56 ( V_230 . V_232 ) ;
}
