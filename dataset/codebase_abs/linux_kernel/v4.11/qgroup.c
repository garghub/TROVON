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
F_100 ( V_12 , V_43 -> V_17 ) ;
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
static void F_105 ( struct V_11 * V_12 ,
struct V_1 * V_16 ,
T_1 V_111 )
{
#ifdef F_106
F_107 ( V_16 -> V_112 < V_111 ) ;
F_108 ( V_12 ,
L_5 ,
V_16 -> V_13 , V_16 -> V_112 , V_111 ) ;
#endif
V_16 -> V_112 = 0 ;
}
static int F_109 ( struct V_11 * V_12 ,
struct V_113 * V_114 , T_1 V_115 ,
T_1 V_111 , int V_116 )
{
struct V_1 * V_16 ;
struct V_27 * V_117 ;
struct V_8 * V_118 ;
struct V_119 V_120 ;
int V_49 = 0 ;
V_16 = F_7 ( V_12 , V_115 ) ;
if ( ! V_16 )
goto V_55;
V_16 -> V_36 += V_116 * V_111 ;
V_16 -> V_71 += V_116 * V_111 ;
F_107 ( V_116 < 0 && V_16 -> V_37 < V_111 ) ;
V_16 -> V_37 += V_116 * V_111 ;
V_16 -> V_72 += V_116 * V_111 ;
if ( V_116 > 0 ) {
if ( V_16 -> V_112 < V_111 )
F_105 ( V_12 , V_16 , V_111 ) ;
else
V_16 -> V_112 -= V_111 ;
}
F_103 ( V_12 , V_16 ) ;
F_25 (glist, &qgroup->groups, next_group) {
V_49 = F_110 ( V_114 , V_117 -> V_35 -> V_13 ,
F_5 ( V_117 -> V_35 ) , V_22 ) ;
if ( V_49 < 0 )
goto V_55;
}
F_111 ( & V_120 ) ;
while ( ( V_118 = F_112 ( V_114 , & V_120 ) ) ) {
V_16 = F_6 ( V_118 ) ;
V_16 -> V_36 += V_116 * V_111 ;
V_16 -> V_71 += V_116 * V_111 ;
F_107 ( V_116 < 0 && V_16 -> V_37 < V_111 ) ;
V_16 -> V_37 += V_116 * V_111 ;
if ( V_116 > 0 ) {
if ( V_16 -> V_112 < V_111 )
F_105 ( V_12 , V_16 ,
V_111 ) ;
else
V_16 -> V_112 -= V_111 ;
}
V_16 -> V_72 += V_116 * V_111 ;
F_103 ( V_12 , V_16 ) ;
F_25 (glist, &qgroup->groups, next_group) {
V_49 = F_110 ( V_114 , V_117 -> V_35 -> V_13 ,
F_5 ( V_117 -> V_35 ) , V_22 ) ;
if ( V_49 < 0 )
goto V_55;
}
}
V_49 = 0 ;
V_55:
return V_49 ;
}
static int F_113 ( struct V_11 * V_12 ,
struct V_113 * V_114 , T_1 V_85 , T_1 V_86 ,
int V_116 )
{
struct V_1 * V_16 ;
int V_49 = 1 ;
int V_121 = 0 ;
V_16 = F_7 ( V_12 , V_85 ) ;
if ( ! V_16 )
goto V_55;
if ( V_16 -> V_37 == V_16 -> V_36 ) {
V_49 = 0 ;
V_121 = F_109 ( V_12 , V_114 , V_86 ,
V_16 -> V_37 , V_116 ) ;
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
int F_114 ( struct V_83 * V_84 ,
struct V_11 * V_12 , T_1 V_85 , T_1 V_86 )
{
struct V_42 * V_43 ;
struct V_1 * V_21 ;
struct V_1 * V_34 ;
struct V_27 * V_28 ;
struct V_113 * V_114 ;
int V_49 = 0 ;
if ( F_115 ( V_85 ) >= F_115 ( V_86 ) )
return - V_38 ;
V_114 = F_29 ( V_54 ) ;
if ( ! V_114 )
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
V_49 = F_113 ( V_12 , V_114 , V_85 , V_86 , 1 ) ;
F_93 ( & V_12 -> V_106 ) ;
V_55:
F_95 ( & V_12 -> V_98 ) ;
F_56 ( V_114 ) ;
return V_49 ;
}
static int F_116 ( struct V_83 * V_84 ,
struct V_11 * V_12 , T_1 V_85 , T_1 V_86 )
{
struct V_42 * V_43 ;
struct V_1 * V_21 ;
struct V_1 * V_34 ;
struct V_27 * V_28 ;
struct V_113 * V_114 ;
int V_49 = 0 ;
int V_121 ;
V_114 = F_29 ( V_54 ) ;
if ( ! V_114 )
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
V_49 = F_113 ( V_12 , V_114 , V_85 , V_86 , - 1 ) ;
F_93 ( & V_12 -> V_106 ) ;
V_55:
F_56 ( V_114 ) ;
return V_49 ;
}
int F_117 ( struct V_83 * V_84 ,
struct V_11 * V_12 , T_1 V_85 , T_1 V_86 )
{
int V_49 = 0 ;
F_89 ( & V_12 -> V_98 ) ;
V_49 = F_116 ( V_84 , V_12 , V_85 , V_86 ) ;
F_95 ( & V_12 -> V_98 ) ;
return V_49 ;
}
int F_118 ( struct V_83 * V_84 ,
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
int F_119 ( struct V_83 * V_84 ,
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
V_49 = F_116 ( V_84 , V_12 ,
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
int F_120 ( struct V_83 * V_84 ,
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
F_121 ( V_12 , L_6 ,
V_13 ) ;
}
V_55:
F_95 ( & V_12 -> V_98 ) ;
return V_49 ;
}
int F_122 ( struct V_83 * V_84 ,
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
if ( F_107 ( ! V_132 -> V_138 ) )
V_49 = F_123 ( NULL , V_12 ,
V_132 -> V_139 , 0 , & V_132 -> V_138 ) ;
if ( V_49 < 0 )
break;
if ( V_135 )
F_124 ( V_132 -> V_138 , V_135 , 0 ) ;
V_17 = F_125 ( V_17 ) ;
}
return V_49 ;
}
int F_126 ( struct V_11 * V_12 ,
struct V_133 * V_134 ,
struct V_131 * V_132 )
{
struct V_14 * * V_20 = & V_134 -> V_137 . V_14 ;
struct V_14 * V_140 = NULL ;
struct V_131 * V_141 ;
T_1 V_139 = V_132 -> V_139 ;
F_127 ( & V_134 -> V_142 ) ;
F_128 ( V_12 , V_132 ) ;
while ( * V_20 ) {
V_140 = * V_20 ;
V_141 = F_8 ( V_140 , struct V_131 ,
V_17 ) ;
if ( V_139 < V_141 -> V_139 )
V_20 = & ( * V_20 ) -> V_18 ;
else if ( V_139 > V_141 -> V_139 )
V_20 = & ( * V_20 ) -> V_19 ;
else
return 1 ;
}
F_13 ( & V_132 -> V_17 , V_140 , V_20 ) ;
F_14 ( & V_132 -> V_17 , & V_134 -> V_137 ) ;
return 0 ;
}
int F_129 ( struct V_11 * V_12 ,
struct V_131 * V_143 )
{
struct V_113 * V_144 ;
T_1 V_139 = V_143 -> V_139 ;
int V_49 ;
V_49 = F_123 ( NULL , V_12 , V_139 , 0 , & V_144 ) ;
if ( V_49 < 0 )
return V_49 ;
V_143 -> V_138 = V_144 ;
return 0 ;
}
int F_130 ( struct V_83 * V_84 ,
struct V_11 * V_12 , T_1 V_139 , T_1 V_111 ,
T_2 V_145 )
{
struct V_131 * V_132 ;
struct V_133 * V_134 ;
int V_49 ;
if ( ! F_28 ( V_52 , & V_12 -> V_50 )
|| V_139 == 0 || V_111 == 0 )
return 0 ;
if ( F_107 ( V_84 == NULL ) )
return - V_38 ;
V_132 = F_131 ( sizeof( * V_132 ) , V_145 ) ;
if ( ! V_132 )
return - V_23 ;
V_134 = & V_84 -> V_136 -> V_134 ;
V_132 -> V_139 = V_139 ;
V_132 -> V_111 = V_111 ;
V_132 -> V_138 = NULL ;
F_92 ( & V_134 -> V_142 ) ;
V_49 = F_126 ( V_12 , V_134 , V_132 ) ;
F_93 ( & V_134 -> V_142 ) ;
if ( V_49 > 0 ) {
F_19 ( V_132 ) ;
return 0 ;
}
return F_129 ( V_12 , V_132 ) ;
}
int F_132 ( struct V_83 * V_84 ,
struct V_11 * V_12 ,
struct V_46 * V_146 )
{
int V_94 = F_85 ( V_146 ) ;
int V_147 , V_148 , V_49 ;
struct V_39 V_40 ;
struct V_149 * V_150 ;
T_1 V_139 , V_111 ;
if ( ! F_28 ( V_52 , & V_12 -> V_50 ) )
return 0 ;
for ( V_147 = 0 ; V_147 < V_94 ; V_147 ++ ) {
F_32 ( V_146 , & V_40 , V_147 ) ;
if ( V_40 . type != V_151 )
continue;
V_150 = F_33 ( V_146 , V_147 , struct V_149 ) ;
V_148 = F_133 ( V_146 , V_150 ) ;
if ( V_148 == V_152 )
continue;
V_139 = F_134 ( V_146 , V_150 ) ;
if ( ! V_139 )
continue;
V_111 = F_135 ( V_146 , V_150 ) ;
V_49 = F_130 ( V_84 , V_12 , V_139 ,
V_111 , V_153 ) ;
if ( V_49 )
return V_49 ;
}
return 0 ;
}
static int F_136 ( struct V_44 * V_45 , int V_154 )
{
int V_155 = 0 ;
int V_94 , V_48 ;
struct V_46 * V_146 ;
if ( V_154 == 0 )
return 1 ;
while ( V_155 <= V_154 ) {
V_146 = V_45 -> V_60 [ V_155 ] ;
V_94 = F_85 ( V_146 ) ;
V_45 -> V_59 [ V_155 ] ++ ;
V_48 = V_45 -> V_59 [ V_155 ] ;
if ( V_48 >= V_94 || V_155 == 0 ) {
if ( V_155 != V_154 ) {
F_137 ( V_146 , V_45 -> V_156 [ V_155 ] ) ;
V_45 -> V_156 [ V_155 ] = 0 ;
F_94 ( V_146 ) ;
V_45 -> V_60 [ V_155 ] = NULL ;
V_45 -> V_59 [ V_155 ] = 0 ;
}
} else {
break;
}
V_155 ++ ;
}
V_146 = V_45 -> V_60 [ V_154 ] ;
if ( V_45 -> V_59 [ V_154 ] >= F_85 ( V_146 ) )
return 1 ;
return 0 ;
}
int F_138 ( struct V_83 * V_84 ,
struct V_42 * V_92 ,
struct V_46 * V_157 ,
T_1 V_158 , int V_154 )
{
struct V_11 * V_12 = V_92 -> V_12 ;
int V_49 = 0 ;
int V_155 ;
struct V_46 * V_146 = V_157 ;
struct V_44 * V_45 = NULL ;
F_139 ( V_154 < 0 || V_154 > V_159 ) ;
F_139 ( V_157 == NULL ) ;
if ( ! F_28 ( V_52 , & V_12 -> V_50 ) )
return 0 ;
if ( ! F_140 ( V_157 ) ) {
V_49 = F_141 ( V_157 , V_158 ) ;
if ( V_49 )
goto V_55;
}
if ( V_154 == 0 ) {
V_49 = F_132 ( V_84 , V_12 , V_157 ) ;
goto V_55;
}
V_45 = F_30 () ;
if ( ! V_45 )
return - V_23 ;
F_142 ( V_157 ) ;
V_45 -> V_60 [ V_154 ] = V_157 ;
V_45 -> V_59 [ V_154 ] = 0 ;
V_45 -> V_156 [ V_154 ] = 0 ;
V_160:
V_155 = V_154 ;
while ( V_155 >= 0 ) {
if ( V_45 -> V_60 [ V_155 ] == NULL ) {
int V_161 ;
T_1 V_162 ;
T_1 V_163 ;
V_146 = V_45 -> V_60 [ V_155 + 1 ] ;
V_161 = V_45 -> V_59 [ V_155 + 1 ] ;
V_163 = F_143 ( V_146 , V_161 ) ;
V_162 = F_144 ( V_146 , V_161 ) ;
V_146 = F_145 ( V_12 , V_163 , V_162 ) ;
if ( F_39 ( V_146 ) ) {
V_49 = F_40 ( V_146 ) ;
goto V_55;
} else if ( ! F_140 ( V_146 ) ) {
F_94 ( V_146 ) ;
V_49 = - V_164 ;
goto V_55;
}
V_45 -> V_60 [ V_155 ] = V_146 ;
V_45 -> V_59 [ V_155 ] = 0 ;
F_146 ( V_146 ) ;
F_147 ( V_146 , V_165 ) ;
V_45 -> V_156 [ V_155 ] = V_166 ;
V_49 = F_130 ( V_84 , V_12 ,
V_163 ,
V_12 -> V_167 ,
V_153 ) ;
if ( V_49 )
goto V_55;
}
if ( V_155 == 0 ) {
V_49 = F_132 ( V_84 , V_12 ,
V_45 -> V_60 [ V_155 ] ) ;
if ( V_49 )
goto V_55;
V_49 = F_136 ( V_45 , V_154 ) ;
if ( V_49 )
break;
goto V_160;
}
V_155 -- ;
}
V_49 = 0 ;
V_55:
F_55 ( V_45 ) ;
return V_49 ;
}
static int F_148 ( struct V_11 * V_12 ,
struct V_113 * V_168 , struct V_113 * V_114 ,
struct V_113 * V_169 , T_1 V_3 , int V_170 )
{
struct V_8 * V_118 ;
struct V_119 V_120 ;
struct V_8 * V_171 ;
struct V_119 V_172 ;
struct V_1 * V_2 ;
int V_49 = 0 ;
if ( ! V_168 )
return 0 ;
F_111 ( & V_120 ) ;
while ( ( V_118 = F_112 ( V_168 , & V_120 ) ) ) {
V_2 = F_7 ( V_12 , V_118 -> V_173 ) ;
if ( ! V_2 )
continue;
F_149 ( V_114 ) ;
V_49 = F_110 ( V_169 , V_2 -> V_13 , F_5 ( V_2 ) ,
V_22 ) ;
if ( V_49 < 0 )
return V_49 ;
V_49 = F_110 ( V_114 , V_2 -> V_13 , F_5 ( V_2 ) , V_22 ) ;
if ( V_49 < 0 )
return V_49 ;
F_111 ( & V_172 ) ;
while ( ( V_171 = F_112 ( V_114 , & V_172 ) ) ) {
struct V_27 * V_117 ;
V_2 = F_6 ( V_171 ) ;
if ( V_170 )
F_1 ( V_2 , V_3 , 1 ) ;
else
F_2 ( V_2 , V_3 , 1 ) ;
F_25 (glist, &qg->groups, next_group) {
V_49 = F_110 ( V_169 , V_117 -> V_35 -> V_13 ,
F_5 ( V_117 -> V_35 ) ,
V_22 ) ;
if ( V_49 < 0 )
return V_49 ;
V_49 = F_110 ( V_114 , V_117 -> V_35 -> V_13 ,
F_5 ( V_117 -> V_35 ) ,
V_22 ) ;
if ( V_49 < 0 )
return V_49 ;
}
}
}
return 0 ;
}
static int F_150 ( struct V_11 * V_12 ,
struct V_113 * V_169 ,
T_1 V_174 ,
T_1 V_175 ,
T_1 V_111 , T_1 V_3 )
{
struct V_8 * V_118 ;
struct V_119 V_120 ;
struct V_1 * V_2 ;
T_1 V_176 , V_177 ;
F_111 ( & V_120 ) ;
while ( ( V_118 = F_112 ( V_169 , & V_120 ) ) ) {
bool V_26 = false ;
V_2 = F_6 ( V_118 ) ;
V_177 = F_3 ( V_2 , V_3 ) ;
V_176 = F_4 ( V_2 , V_3 ) ;
F_151 ( V_12 , V_2 -> V_13 ,
V_177 , V_176 ) ;
if ( V_177 == 0 && V_176 > 0 ) {
V_2 -> V_36 += V_111 ;
V_2 -> V_71 += V_111 ;
V_26 = true ;
}
if ( V_177 > 0 && V_176 == 0 ) {
V_2 -> V_36 -= V_111 ;
V_2 -> V_71 -= V_111 ;
V_26 = true ;
}
if ( V_177 == V_174 &&
V_176 < V_175 ) {
if ( V_177 != 0 ) {
V_2 -> V_37 -= V_111 ;
V_2 -> V_72 -= V_111 ;
V_26 = true ;
}
}
if ( V_177 < V_174 &&
V_176 == V_175 ) {
if ( V_176 != 0 ) {
V_2 -> V_37 += V_111 ;
V_2 -> V_72 += V_111 ;
V_26 = true ;
}
}
if ( V_177 == V_174 &&
V_176 == V_175 ) {
if ( V_177 == 0 ) {
if ( V_176 != 0 ) {
V_2 -> V_37 += V_111 ;
V_2 -> V_72 += V_111 ;
V_26 = true ;
}
} else {
if ( V_176 == 0 ) {
V_2 -> V_37 -= V_111 ;
V_2 -> V_72 -= V_111 ;
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
F_152 ( struct V_83 * V_84 ,
struct V_11 * V_12 ,
T_1 V_139 , T_1 V_111 ,
struct V_113 * V_138 , struct V_113 * V_178 )
{
struct V_113 * V_169 = NULL ;
struct V_113 * V_114 = NULL ;
T_1 V_3 ;
T_1 V_175 = 0 ;
T_1 V_174 = 0 ;
int V_49 = 0 ;
if ( ! F_28 ( V_52 , & V_12 -> V_50 ) )
return 0 ;
if ( V_178 )
V_175 = V_178 -> V_179 ;
if ( V_138 )
V_174 = V_138 -> V_179 ;
F_139 ( ! V_12 -> V_43 ) ;
F_153 ( V_12 , V_139 , V_111 ,
V_174 , V_175 ) ;
V_169 = F_29 ( V_153 ) ;
if ( ! V_169 ) {
V_49 = - V_23 ;
goto V_180;
}
V_114 = F_29 ( V_153 ) ;
if ( ! V_114 ) {
V_49 = - V_23 ;
goto V_180;
}
F_89 ( & V_12 -> V_181 ) ;
if ( V_12 -> V_56 & V_82 ) {
if ( V_12 -> V_93 . V_57 <= V_139 ) {
F_95 ( & V_12 -> V_181 ) ;
V_49 = 0 ;
goto V_180;
}
}
F_95 ( & V_12 -> V_181 ) ;
F_92 ( & V_12 -> V_106 ) ;
V_3 = V_12 -> V_182 ;
V_49 = F_148 ( V_12 , V_138 , V_114 , V_169 , V_3 ,
V_183 ) ;
if ( V_49 < 0 )
goto V_55;
V_49 = F_148 ( V_12 , V_178 , V_114 , V_169 , V_3 ,
V_184 ) ;
if ( V_49 < 0 )
goto V_55;
F_150 ( V_12 , V_169 , V_174 , V_175 ,
V_111 , V_3 ) ;
V_12 -> V_182 += F_154 ( V_174 , V_175 ) + 1 ;
V_55:
F_93 ( & V_12 -> V_106 ) ;
V_180:
F_56 ( V_114 ) ;
F_56 ( V_169 ) ;
F_56 ( V_138 ) ;
F_56 ( V_178 ) ;
return V_49 ;
}
int F_155 ( struct V_83 * V_84 ,
struct V_11 * V_12 )
{
struct V_131 * V_132 ;
struct V_133 * V_134 ;
struct V_113 * V_178 = NULL ;
struct V_14 * V_17 ;
T_1 V_135 ;
int V_49 = 0 ;
V_134 = & V_84 -> V_136 -> V_134 ;
V_135 = V_134 -> V_135 ;
while ( ( V_17 = F_58 ( & V_134 -> V_137 ) ) ) {
V_132 = F_8 ( V_17 , struct V_131 ,
V_17 ) ;
F_156 ( V_12 , V_132 ) ;
if ( ! V_49 ) {
V_49 = F_123 ( V_84 , V_12 ,
V_132 -> V_139 , ( T_1 ) - 1 , & V_178 ) ;
if ( V_49 < 0 )
goto V_185;
if ( V_135 )
F_124 ( V_178 , V_135 , 0 ) ;
V_49 = F_152 ( V_84 , V_12 ,
V_132 -> V_139 , V_132 -> V_111 ,
V_132 -> V_138 , V_178 ) ;
V_132 -> V_138 = NULL ;
V_178 = NULL ;
}
V_185:
F_56 ( V_132 -> V_138 ) ;
F_56 ( V_178 ) ;
V_178 = NULL ;
F_21 ( V_17 , & V_134 -> V_137 ) ;
F_19 ( V_132 ) ;
}
return V_49 ;
}
int F_157 ( struct V_83 * V_84 ,
struct V_11 * V_12 )
{
struct V_42 * V_43 = V_12 -> V_43 ;
int V_49 = 0 ;
int V_186 = 0 ;
if ( ! V_43 )
goto V_55;
if ( ! F_28 ( V_52 , & V_12 -> V_50 ) &&
F_28 ( V_99 , & V_12 -> V_50 ) )
V_186 = 1 ;
if ( F_158 ( V_99 , & V_12 -> V_50 ) )
F_87 ( V_52 , & V_12 -> V_50 ) ;
if ( F_158 ( V_96 , & V_12 -> V_50 ) )
F_53 ( V_52 , & V_12 -> V_50 ) ;
F_92 ( & V_12 -> V_106 ) ;
while ( ! F_17 ( & V_12 -> V_110 ) ) {
struct V_1 * V_16 ;
V_16 = F_18 ( & V_12 -> V_110 ,
struct V_1 , V_26 ) ;
F_159 ( & V_16 -> V_26 ) ;
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
if ( ! V_49 && V_186 ) {
V_49 = F_54 ( V_12 , 0 , 1 ) ;
if ( ! V_49 ) {
F_160 ( V_12 ) ;
F_161 ( V_12 -> V_187 ,
& V_12 -> V_188 ) ;
}
V_49 = 0 ;
}
V_55:
return V_49 ;
}
int F_162 ( struct V_83 * V_84 ,
struct V_11 * V_12 , T_1 V_189 , T_1 V_57 ,
struct F_162 * V_190 )
{
int V_49 = 0 ;
int V_147 ;
T_1 * V_191 ;
struct V_42 * V_43 = V_12 -> V_43 ;
struct V_1 * V_192 ;
struct V_1 * V_193 ;
T_3 V_194 = 0 ;
T_1 V_195 ;
F_89 ( & V_12 -> V_98 ) ;
if ( ! F_28 ( V_52 , & V_12 -> V_50 ) )
goto V_55;
if ( ! V_43 ) {
V_49 = - V_38 ;
goto V_55;
}
if ( V_190 ) {
V_191 = ( T_1 * ) ( V_190 + 1 ) ;
V_195 = V_190 -> V_196 + 2 * V_190 -> V_197 +
2 * V_190 -> V_198 ;
for ( V_147 = 0 ; V_147 < V_195 ; ++ V_147 ) {
V_192 = F_7 ( V_12 , * V_191 ) ;
if ( ! V_192 ||
( ( V_192 -> V_13 >> 48 ) <= ( V_57 >> 48 ) ) )
* V_191 = 0ULL ;
++ V_191 ;
}
}
V_49 = F_65 ( V_84 , V_43 , V_57 ) ;
if ( V_49 )
goto V_55;
if ( V_189 ) {
struct V_42 * V_199 ;
struct V_39 V_200 ;
V_200 . V_57 = V_189 ;
V_200 . type = V_201 ;
V_200 . V_58 = ( T_1 ) - 1 ;
V_199 = F_163 ( V_12 , & V_200 ) ;
if ( F_39 ( V_199 ) ) {
V_49 = F_40 ( V_199 ) ;
goto V_55;
}
V_194 = V_12 -> V_167 ;
}
if ( V_190 ) {
V_191 = ( T_1 * ) ( V_190 + 1 ) ;
for ( V_147 = 0 ; V_147 < V_190 -> V_196 ; ++ V_147 , ++ V_191 ) {
if ( * V_191 == 0 )
continue;
V_49 = F_59 ( V_84 , V_43 ,
V_57 , * V_191 ) ;
if ( V_49 && V_49 != - V_90 )
goto V_55;
V_49 = F_59 ( V_84 , V_43 ,
* V_191 , V_57 ) ;
if ( V_49 && V_49 != - V_90 )
goto V_55;
}
V_49 = 0 ;
}
F_92 ( & V_12 -> V_106 ) ;
V_193 = F_9 ( V_12 , V_57 ) ;
if ( F_39 ( V_193 ) ) {
V_49 = F_40 ( V_193 ) ;
goto V_202;
}
if ( V_190 && V_190 -> V_50 & V_203 ) {
V_193 -> V_74 = V_190 -> V_204 . V_50 ;
V_193 -> V_75 = V_190 -> V_204 . V_75 ;
V_193 -> V_76 = V_190 -> V_204 . V_76 ;
V_193 -> V_77 = V_190 -> V_204 . V_77 ;
V_193 -> V_78 = V_190 -> V_204 . V_78 ;
V_49 = F_78 ( V_84 , V_43 , V_193 ) ;
if ( V_49 ) {
V_12 -> V_56 |= V_66 ;
F_121 ( V_12 ,
L_6 ,
V_193 -> V_13 ) ;
goto V_202;
}
}
if ( V_189 ) {
V_192 = F_7 ( V_12 , V_189 ) ;
if ( ! V_192 )
goto V_202;
V_193 -> V_36 = V_192 -> V_36 ;
V_193 -> V_71 = V_192 -> V_71 ;
V_193 -> V_37 = V_194 ;
V_193 -> V_72 = V_194 ;
V_192 -> V_37 = V_194 ;
V_192 -> V_72 = V_194 ;
V_193 -> V_74 = V_192 -> V_74 ;
V_193 -> V_75 = V_192 -> V_75 ;
V_193 -> V_76 = V_192 -> V_76 ;
V_193 -> V_77 = V_192 -> V_77 ;
V_193 -> V_78 = V_192 -> V_78 ;
F_103 ( V_12 , V_193 ) ;
F_103 ( V_12 , V_192 ) ;
}
if ( ! V_190 )
goto V_202;
V_191 = ( T_1 * ) ( V_190 + 1 ) ;
for ( V_147 = 0 ; V_147 < V_190 -> V_196 ; ++ V_147 ) {
if ( * V_191 ) {
V_49 = F_22 ( V_12 , V_57 , * V_191 ) ;
if ( V_49 )
goto V_202;
}
++ V_191 ;
}
for ( V_147 = 0 ; V_147 < V_190 -> V_197 ; ++ V_147 , V_191 += 2 ) {
struct V_1 * V_85 ;
struct V_1 * V_86 ;
if ( ! V_191 [ 0 ] || ! V_191 [ 1 ] )
continue;
V_85 = F_7 ( V_12 , V_191 [ 0 ] ) ;
V_86 = F_7 ( V_12 , V_191 [ 1 ] ) ;
if ( ! V_85 || ! V_86 ) {
V_49 = - V_38 ;
goto V_202;
}
V_86 -> V_36 = V_85 -> V_36 - V_194 ;
V_86 -> V_71 = V_85 -> V_71 - V_194 ;
}
for ( V_147 = 0 ; V_147 < V_190 -> V_198 ; ++ V_147 , V_191 += 2 ) {
struct V_1 * V_85 ;
struct V_1 * V_86 ;
if ( ! V_191 [ 0 ] || ! V_191 [ 1 ] )
continue;
V_85 = F_7 ( V_12 , V_191 [ 0 ] ) ;
V_86 = F_7 ( V_12 , V_191 [ 1 ] ) ;
if ( ! V_85 || ! V_86 ) {
V_49 = - V_38 ;
goto V_202;
}
V_86 -> V_37 = V_85 -> V_37 + V_194 ;
V_86 -> V_72 = V_85 -> V_72 + V_194 ;
}
V_202:
F_93 ( & V_12 -> V_106 ) ;
V_55:
F_95 ( & V_12 -> V_98 ) ;
return V_49 ;
}
static bool F_164 ( const struct V_1 * V_2 , T_1 V_111 )
{
if ( ( V_2 -> V_74 & V_127 ) &&
V_2 -> V_112 + ( V_205 ) V_2 -> V_36 + V_111 > V_2 -> V_75 )
return false ;
if ( ( V_2 -> V_74 & V_128 ) &&
V_2 -> V_112 + ( V_205 ) V_2 -> V_37 + V_111 > V_2 -> V_76 )
return false ;
return true ;
}
static int F_165 ( struct V_42 * V_92 , T_1 V_111 , bool V_206 )
{
struct V_42 * V_43 ;
struct V_1 * V_16 ;
struct V_11 * V_12 = V_92 -> V_12 ;
T_1 V_115 = V_92 -> V_108 . V_57 ;
int V_49 = 0 ;
struct V_8 * V_118 ;
struct V_119 V_120 ;
if ( ! F_166 ( V_115 ) )
return 0 ;
if ( V_111 == 0 )
return 0 ;
F_92 ( & V_12 -> V_106 ) ;
V_43 = V_12 -> V_43 ;
if ( ! V_43 )
goto V_55;
V_16 = F_7 ( V_12 , V_115 ) ;
if ( ! V_16 )
goto V_55;
F_149 ( V_12 -> V_53 ) ;
V_49 = F_110 ( V_12 -> V_53 , V_16 -> V_13 ,
( V_7 ) V_16 , V_22 ) ;
if ( V_49 < 0 )
goto V_55;
F_111 ( & V_120 ) ;
while ( ( V_118 = F_112 ( V_12 -> V_53 , & V_120 ) ) ) {
struct V_1 * V_2 ;
struct V_27 * V_117 ;
V_2 = F_6 ( V_118 ) ;
if ( V_206 && ! F_164 ( V_2 , V_111 ) ) {
V_49 = - V_207 ;
goto V_55;
}
F_25 (glist, &qg->groups, next_group) {
V_49 = F_110 ( V_12 -> V_53 ,
V_117 -> V_35 -> V_13 ,
( V_7 ) V_117 -> V_35 , V_22 ) ;
if ( V_49 < 0 )
goto V_55;
}
}
V_49 = 0 ;
F_111 ( & V_120 ) ;
while ( ( V_118 = F_112 ( V_12 -> V_53 , & V_120 ) ) ) {
struct V_1 * V_2 ;
V_2 = F_6 ( V_118 ) ;
V_2 -> V_112 += V_111 ;
}
V_55:
F_93 ( & V_12 -> V_106 ) ;
return V_49 ;
}
void F_167 ( struct V_11 * V_12 ,
T_1 V_115 , T_1 V_111 )
{
struct V_42 * V_43 ;
struct V_1 * V_16 ;
struct V_8 * V_118 ;
struct V_119 V_120 ;
int V_49 = 0 ;
if ( ! F_166 ( V_115 ) )
return;
if ( V_111 == 0 )
return;
F_92 ( & V_12 -> V_106 ) ;
V_43 = V_12 -> V_43 ;
if ( ! V_43 )
goto V_55;
V_16 = F_7 ( V_12 , V_115 ) ;
if ( ! V_16 )
goto V_55;
F_149 ( V_12 -> V_53 ) ;
V_49 = F_110 ( V_12 -> V_53 , V_16 -> V_13 ,
( V_7 ) V_16 , V_22 ) ;
if ( V_49 < 0 )
goto V_55;
F_111 ( & V_120 ) ;
while ( ( V_118 = F_112 ( V_12 -> V_53 , & V_120 ) ) ) {
struct V_1 * V_2 ;
struct V_27 * V_117 ;
V_2 = F_6 ( V_118 ) ;
if ( V_2 -> V_112 < V_111 )
F_105 ( V_12 , V_2 , V_111 ) ;
else
V_2 -> V_112 -= V_111 ;
F_25 (glist, &qg->groups, next_group) {
V_49 = F_110 ( V_12 -> V_53 ,
V_117 -> V_35 -> V_13 ,
( V_7 ) V_117 -> V_35 , V_22 ) ;
if ( V_49 < 0 )
goto V_55;
}
}
V_55:
F_93 ( & V_12 -> V_106 ) ;
}
void F_168 ( struct V_83 * V_84 )
{
if ( F_17 ( & V_84 -> V_208 ) && ! V_84 -> V_209 . V_3 )
return;
F_35 ( V_84 -> V_12 ,
L_7 ,
V_84 , F_17 ( & V_84 -> V_208 ) ? L_8 : L_9 ,
( T_3 ) ( V_84 -> V_209 . V_3 >> 32 ) ,
( T_3 ) V_84 -> V_209 . V_3 ) ;
F_169 () ;
}
static int
F_170 ( struct V_11 * V_12 , struct V_44 * V_45 ,
struct V_83 * V_84 )
{
struct V_39 V_210 ;
struct V_46 * V_211 = NULL ;
struct V_113 * V_168 = NULL ;
struct V_212 V_213 = F_171 ( V_213 ) ;
T_1 V_111 ;
int V_48 ;
int V_49 ;
F_89 ( & V_12 -> V_181 ) ;
V_49 = F_31 ( V_12 -> V_214 ,
& V_12 -> V_93 ,
V_45 , 1 , 0 ) ;
F_108 ( V_12 ,
L_10 ,
V_12 -> V_93 . V_57 ,
V_12 -> V_93 . type ,
V_12 -> V_93 . V_58 , V_49 ) ;
if ( V_49 ) {
V_12 -> V_93 . V_57 = ( T_1 ) - 1 ;
F_51 ( V_45 ) ;
F_95 ( & V_12 -> V_181 ) ;
return V_49 ;
}
F_32 ( V_45 -> V_60 [ 0 ] , & V_210 ,
F_85 ( V_45 -> V_60 [ 0 ] ) - 1 ) ;
V_12 -> V_93 . V_57 = V_210 . V_57 + 1 ;
F_172 ( V_12 , & V_213 ) ;
V_211 = F_173 ( V_45 -> V_60 [ 0 ] ) ;
if ( ! V_211 ) {
V_49 = - V_23 ;
F_95 ( & V_12 -> V_181 ) ;
goto V_55;
}
F_142 ( V_211 ) ;
F_146 ( V_211 ) ;
F_147 ( V_211 , V_165 ) ;
V_48 = V_45 -> V_59 [ 0 ] ;
F_51 ( V_45 ) ;
F_95 ( & V_12 -> V_181 ) ;
for (; V_48 < F_85 ( V_211 ) ; ++ V_48 ) {
F_32 ( V_211 , & V_210 , V_48 ) ;
if ( V_210 . type != V_215 &&
V_210 . type != V_216 )
continue;
if ( V_210 . type == V_216 )
V_111 = V_12 -> V_167 ;
else
V_111 = V_210 . V_58 ;
V_49 = F_123 ( NULL , V_12 , V_210 . V_57 , 0 ,
& V_168 ) ;
if ( V_49 < 0 )
goto V_55;
V_49 = F_152 ( V_84 , V_12 ,
V_210 . V_57 , V_111 , NULL , V_168 ) ;
if ( V_49 < 0 )
goto V_55;
}
V_55:
if ( V_211 ) {
F_174 ( V_211 ) ;
F_94 ( V_211 ) ;
}
F_175 ( V_12 , & V_213 ) ;
return V_49 ;
}
static void F_176 ( struct V_217 * V_218 )
{
struct V_11 * V_12 = F_177 ( V_218 , struct V_11 ,
V_188 ) ;
struct V_44 * V_45 ;
struct V_83 * V_84 = NULL ;
int V_121 = - V_23 ;
int V_49 = 0 ;
V_45 = F_30 () ;
if ( ! V_45 )
goto V_55;
V_121 = 0 ;
while ( ! V_121 && ! F_178 ( V_12 ) ) {
V_84 = F_179 ( V_12 -> V_219 , 0 ) ;
if ( F_39 ( V_84 ) ) {
V_121 = F_40 ( V_84 ) ;
break;
}
if ( ! F_28 ( V_52 , & V_12 -> V_50 ) ) {
V_121 = - V_220 ;
} else {
V_121 = F_170 ( V_12 , V_45 , V_84 ) ;
}
if ( V_121 > 0 )
F_180 ( V_84 ) ;
else
F_181 ( V_84 ) ;
}
V_55:
F_55 ( V_45 ) ;
F_89 ( & V_12 -> V_181 ) ;
if ( ! F_178 ( V_12 ) )
V_12 -> V_56 &= ~ V_82 ;
if ( V_121 > 0 &&
V_12 -> V_56 & V_66 ) {
V_12 -> V_56 &= ~ V_66 ;
} else if ( V_121 < 0 ) {
V_12 -> V_56 |= V_66 ;
}
F_95 ( & V_12 -> V_181 ) ;
V_84 = F_179 ( V_12 -> V_43 , 1 ) ;
if ( F_39 ( V_84 ) ) {
V_121 = F_40 ( V_84 ) ;
F_35 ( V_12 ,
L_11 ,
V_121 ) ;
goto V_221;
}
V_49 = F_80 ( V_84 , V_12 , V_12 -> V_43 ) ;
if ( V_49 < 0 ) {
V_121 = V_49 ;
F_35 ( V_12 , L_12 , V_121 ) ;
}
F_181 ( V_84 ) ;
if ( F_178 ( V_12 ) ) {
F_121 ( V_12 , L_13 ) ;
} else if ( V_121 >= 0 ) {
F_121 ( V_12 , L_14 ,
V_121 > 0 ? L_15 : L_8 ) ;
} else {
F_35 ( V_12 , L_16 , V_121 ) ;
}
V_221:
F_89 ( & V_12 -> V_181 ) ;
V_12 -> V_222 = false ;
F_95 ( & V_12 -> V_181 ) ;
F_182 ( & V_12 -> V_223 ) ;
}
static int
F_54 ( struct V_11 * V_12 , T_1 V_224 ,
int V_225 )
{
int V_49 = 0 ;
if ( ! V_225 &&
( ! ( V_12 -> V_56 & V_82 ) ||
! ( V_12 -> V_56 & V_81 ) ) ) {
V_49 = - V_38 ;
goto V_121;
}
F_89 ( & V_12 -> V_181 ) ;
F_92 ( & V_12 -> V_106 ) ;
if ( V_225 ) {
if ( V_12 -> V_56 & V_82 )
V_49 = - V_226 ;
else if ( ! ( V_12 -> V_56 & V_81 ) )
V_49 = - V_38 ;
if ( V_49 ) {
F_93 ( & V_12 -> V_106 ) ;
F_95 ( & V_12 -> V_181 ) ;
goto V_121;
}
V_12 -> V_56 |= V_82 ;
}
memset ( & V_12 -> V_93 , 0 ,
sizeof( V_12 -> V_93 ) ) ;
V_12 -> V_93 . V_57 = V_224 ;
F_183 ( & V_12 -> V_223 ) ;
V_12 -> V_222 = true ;
F_93 ( & V_12 -> V_106 ) ;
F_95 ( & V_12 -> V_181 ) ;
memset ( & V_12 -> V_188 , 0 ,
sizeof( V_12 -> V_188 ) ) ;
F_184 ( & V_12 -> V_188 ,
V_227 ,
F_176 , NULL , NULL ) ;
if ( V_49 ) {
V_121:
F_121 ( V_12 , L_17 , V_49 ) ;
return V_49 ;
}
return 0 ;
}
static void
F_160 ( struct V_11 * V_12 )
{
struct V_14 * V_9 ;
struct V_1 * V_16 ;
F_92 ( & V_12 -> V_106 ) ;
for ( V_9 = F_58 ( & V_12 -> V_15 ) ; V_9 ; V_9 = F_125 ( V_9 ) ) {
V_16 = F_8 ( V_9 , struct V_1 , V_17 ) ;
V_16 -> V_36 = 0 ;
V_16 -> V_71 = 0 ;
V_16 -> V_37 = 0 ;
V_16 -> V_72 = 0 ;
}
F_93 ( & V_12 -> V_106 ) ;
}
int
F_185 ( struct V_11 * V_12 )
{
int V_49 = 0 ;
struct V_83 * V_84 ;
V_49 = F_54 ( V_12 , 0 , 1 ) ;
if ( V_49 )
return V_49 ;
V_84 = F_186 ( V_12 -> V_219 ) ;
if ( F_39 ( V_84 ) ) {
V_12 -> V_56 &= ~ V_82 ;
return F_40 ( V_84 ) ;
}
V_49 = F_180 ( V_84 ) ;
if ( V_49 ) {
V_12 -> V_56 &= ~ V_82 ;
return V_49 ;
}
F_160 ( V_12 ) ;
F_161 ( V_12 -> V_187 ,
& V_12 -> V_188 ) ;
return 0 ;
}
int F_97 ( struct V_11 * V_12 ,
bool V_228 )
{
int V_229 ;
int V_49 = 0 ;
F_89 ( & V_12 -> V_181 ) ;
F_92 ( & V_12 -> V_106 ) ;
V_229 = V_12 -> V_222 ;
F_93 ( & V_12 -> V_106 ) ;
F_95 ( & V_12 -> V_181 ) ;
if ( ! V_229 )
return 0 ;
if ( V_228 )
V_49 = F_187 (
& V_12 -> V_223 ) ;
else
F_188 ( & V_12 -> V_223 ) ;
return V_49 ;
}
void
F_189 ( struct V_11 * V_12 )
{
if ( V_12 -> V_56 & V_82 )
F_161 ( V_12 -> V_187 ,
& V_12 -> V_188 ) ;
}
int F_190 ( struct V_230 * V_230 , T_1 V_231 , T_1 V_232 )
{
struct V_42 * V_92 = F_191 ( V_230 ) -> V_92 ;
struct V_233 V_234 ;
struct V_8 * V_118 ;
struct V_119 V_120 ;
int V_49 ;
if ( ! F_28 ( V_52 , & V_92 -> V_12 -> V_50 ) ||
! F_166 ( V_92 -> V_57 ) || V_232 == 0 )
return 0 ;
V_234 . V_235 = 0 ;
F_192 ( & V_234 . V_236 ) ;
V_49 = F_193 ( & F_191 ( V_230 ) -> V_237 , V_231 ,
V_231 + V_232 - 1 , V_238 , & V_234 ) ;
F_194 ( V_230 , V_231 , V_232 ,
V_234 . V_235 ,
V_239 ) ;
if ( V_49 < 0 )
goto V_185;
V_49 = F_165 ( V_92 , V_234 . V_235 , true ) ;
if ( V_49 < 0 )
goto V_185;
F_195 ( & V_234 . V_236 ) ;
return V_49 ;
V_185:
F_111 ( & V_120 ) ;
while ( ( V_118 = F_112 ( & V_234 . V_236 , & V_120 ) ) )
F_196 ( & F_191 ( V_230 ) -> V_237 , V_118 -> V_173 ,
V_118 -> V_10 , V_238 , 0 , 0 , NULL ,
V_153 ) ;
F_195 ( & V_234 . V_236 ) ;
return V_49 ;
}
static int F_197 ( struct V_230 * V_230 , T_1 V_231 , T_1 V_232 ,
int free )
{
struct V_233 V_234 ;
int V_240 = V_241 ;
int V_49 ;
V_234 . V_235 = 0 ;
F_192 ( & V_234 . V_236 ) ;
V_49 = F_198 ( & F_191 ( V_230 ) -> V_237 , V_231 ,
V_231 + V_232 - 1 , V_238 , & V_234 ) ;
if ( V_49 < 0 )
goto V_55;
if ( free ) {
F_167 ( F_191 ( V_230 ) -> V_92 -> V_12 ,
F_191 ( V_230 ) -> V_92 -> V_57 ,
V_234 . V_235 ) ;
V_240 = V_242 ;
}
F_199 ( V_230 , V_231 , V_232 ,
V_234 . V_235 , V_240 ) ;
V_55:
F_195 ( & V_234 . V_236 ) ;
return V_49 ;
}
int F_200 ( struct V_230 * V_230 , T_1 V_231 , T_1 V_232 )
{
return F_197 ( V_230 , V_231 , V_232 , 1 ) ;
}
int F_201 ( struct V_230 * V_230 , T_1 V_231 , T_1 V_232 )
{
return F_197 ( V_230 , V_231 , V_232 , 0 ) ;
}
int F_202 ( struct V_42 * V_92 , int V_111 ,
bool V_206 )
{
struct V_11 * V_12 = V_92 -> V_12 ;
int V_49 ;
if ( ! F_28 ( V_52 , & V_12 -> V_50 ) ||
! F_166 ( V_92 -> V_57 ) || V_111 == 0 )
return 0 ;
F_139 ( V_111 != F_203 ( V_111 , V_12 -> V_167 ) ) ;
V_49 = F_165 ( V_92 , V_111 , V_206 ) ;
if ( V_49 < 0 )
return V_49 ;
F_204 ( V_111 , & V_92 -> V_243 ) ;
return V_49 ;
}
void F_205 ( struct V_42 * V_92 )
{
struct V_11 * V_12 = V_92 -> V_12 ;
T_1 V_112 ;
if ( ! F_28 ( V_52 , & V_12 -> V_50 ) ||
! F_166 ( V_92 -> V_57 ) )
return;
V_112 = F_206 ( & V_92 -> V_243 , 0 ) ;
if ( V_112 == 0 )
return;
F_167 ( V_12 , V_92 -> V_57 , V_112 ) ;
}
void F_207 ( struct V_42 * V_92 , int V_111 )
{
struct V_11 * V_12 = V_92 -> V_12 ;
if ( ! F_28 ( V_52 , & V_12 -> V_50 ) ||
! F_166 ( V_92 -> V_57 ) )
return;
F_139 ( V_111 != F_203 ( V_111 , V_12 -> V_167 ) ) ;
F_107 ( F_208 ( & V_92 -> V_243 ) < V_111 ) ;
F_209 ( V_111 , & V_92 -> V_243 ) ;
F_167 ( V_12 , V_92 -> V_57 , V_111 ) ;
}
void F_210 ( struct V_230 * V_230 )
{
struct V_233 V_234 ;
struct V_8 * V_118 ;
struct V_119 V_244 ;
int V_49 ;
V_234 . V_235 = 0 ;
F_192 ( & V_234 . V_236 ) ;
V_49 = F_198 ( & F_191 ( V_230 ) -> V_237 , 0 , ( T_1 ) - 1 ,
V_238 , & V_234 ) ;
F_107 ( V_49 < 0 ) ;
if ( F_107 ( V_234 . V_235 ) ) {
F_111 ( & V_244 ) ;
while ( ( V_118 = F_112 ( & V_234 . V_236 , & V_244 ) ) ) {
F_52 ( F_191 ( V_230 ) -> V_92 -> V_12 ,
L_18 ,
V_230 -> V_245 , V_118 -> V_173 , V_118 -> V_10 ) ;
}
F_167 ( F_191 ( V_230 ) -> V_92 -> V_12 ,
F_191 ( V_230 ) -> V_92 -> V_57 ,
V_234 . V_235 ) ;
}
F_195 ( & V_234 . V_236 ) ;
}
