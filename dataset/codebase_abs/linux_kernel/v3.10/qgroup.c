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
static int F_9 ( struct V_2 * V_3 , T_1 V_4 )
{
struct V_1 * V_8 = F_1 ( V_3 , V_4 ) ;
struct V_19 * V_20 ;
if ( ! V_8 )
return - V_21 ;
F_10 ( & V_8 -> V_9 , & V_3 -> V_7 ) ;
F_11 ( & V_8 -> V_18 ) ;
while ( ! F_12 ( & V_8 -> V_16 ) ) {
V_20 = F_13 ( & V_8 -> V_16 ,
struct V_19 , V_22 ) ;
F_11 ( & V_20 -> V_22 ) ;
F_11 ( & V_20 -> V_23 ) ;
F_14 ( V_20 ) ;
}
while ( ! F_12 ( & V_8 -> V_17 ) ) {
V_20 = F_13 ( & V_8 -> V_17 ,
struct V_19 , V_23 ) ;
F_11 ( & V_20 -> V_22 ) ;
F_11 ( & V_20 -> V_23 ) ;
F_14 ( V_20 ) ;
}
F_14 ( V_8 ) ;
return 0 ;
}
static int F_15 ( struct V_2 * V_3 ,
T_1 V_24 , T_1 V_25 )
{
struct V_1 * V_26 ;
struct V_1 * V_13 ;
struct V_19 * V_20 ;
V_26 = F_1 ( V_3 , V_24 ) ;
V_13 = F_1 ( V_3 , V_25 ) ;
if ( ! V_26 || ! V_13 )
return - V_21 ;
V_20 = F_4 ( sizeof( * V_20 ) , V_14 ) ;
if ( ! V_20 )
return - V_15 ;
V_20 -> V_27 = V_13 ;
V_20 -> V_26 = V_26 ;
F_16 ( & V_20 -> V_22 , & V_26 -> V_16 ) ;
F_16 ( & V_20 -> V_23 , & V_13 -> V_17 ) ;
return 0 ;
}
static int F_17 ( struct V_2 * V_3 ,
T_1 V_24 , T_1 V_25 )
{
struct V_1 * V_26 ;
struct V_1 * V_13 ;
struct V_19 * V_20 ;
V_26 = F_1 ( V_3 , V_24 ) ;
V_13 = F_1 ( V_3 , V_25 ) ;
if ( ! V_26 || ! V_13 )
return - V_21 ;
F_18 (list, &member->groups, next_group) {
if ( V_20 -> V_27 == V_13 ) {
F_11 ( & V_20 -> V_22 ) ;
F_11 ( & V_20 -> V_23 ) ;
F_14 ( V_20 ) ;
return 0 ;
}
}
return - V_21 ;
}
int F_19 ( struct V_2 * V_3 )
{
struct V_28 V_29 ;
struct V_28 V_30 ;
struct V_31 * V_32 = V_3 -> V_32 ;
struct V_33 * V_34 = NULL ;
struct V_35 * V_36 ;
int V_37 ;
int V_38 = 0 ;
T_1 V_39 = 0 ;
if ( ! V_3 -> V_40 )
return 0 ;
V_34 = F_20 () ;
if ( ! V_34 ) {
V_38 = - V_15 ;
goto V_41;
}
V_3 -> V_42 = 0 ;
V_29 . V_43 = 0 ;
V_29 . type = 0 ;
V_29 . V_44 = 0 ;
V_38 = F_21 ( V_32 , & V_29 , V_34 , 1 , 1 ) ;
if ( V_38 )
goto V_41;
while ( 1 ) {
struct V_1 * V_8 ;
V_37 = V_34 -> V_45 [ 0 ] ;
V_36 = V_34 -> V_46 [ 0 ] ;
F_22 ( V_36 , & V_30 , V_37 ) ;
if ( V_30 . type == V_47 ) {
struct V_48 * V_49 ;
V_49 = F_23 ( V_36 , V_37 ,
struct V_48 ) ;
if ( F_24 ( V_36 , V_49 ) !=
V_50 ) {
F_25 ( V_51
L_1 ) ;
goto V_41;
}
if ( F_26 ( V_36 , V_49 ) !=
V_3 -> V_52 ) {
V_39 |= V_53 ;
F_25 ( V_51
L_2
L_3 ) ;
}
V_3 -> V_42 = F_27 ( V_36 ,
V_49 ) ;
V_3 -> V_54 . V_43 =
F_28 ( V_36 , V_49 ) ;
if ( V_3 -> V_42 &
V_55 ) {
struct V_56 * V_57 =
F_29 ( sizeof( * V_57 ) , V_58 ) ;
if ( ! V_57 ) {
V_38 = - V_15 ;
goto V_41;
}
V_3 -> V_54 . type = 0 ;
V_3 -> V_54 . V_44 = 0 ;
F_30 ( V_3 , V_57 ) ;
}
goto V_59;
}
if ( V_30 . type != V_60 &&
V_30 . type != V_61 )
goto V_59;
V_8 = F_1 ( V_3 , V_30 . V_44 ) ;
if ( ( V_8 && V_30 . type == V_60 ) ||
( ! V_8 && V_30 . type == V_61 ) ) {
F_25 ( V_51 L_4 ) ;
V_39 |= V_53 ;
}
if ( ! V_8 ) {
V_8 = F_3 ( V_3 , V_30 . V_44 ) ;
if ( F_31 ( V_8 ) ) {
V_38 = F_32 ( V_8 ) ;
goto V_41;
}
}
switch ( V_30 . type ) {
case V_60 : {
struct V_62 * V_49 ;
V_49 = F_23 ( V_36 , V_37 ,
struct V_62 ) ;
V_8 -> V_63 = F_33 ( V_36 , V_49 ) ;
V_8 -> V_64 = F_34 ( V_36 , V_49 ) ;
V_8 -> V_65 = F_35 ( V_36 , V_49 ) ;
V_8 -> V_66 = F_36 ( V_36 , V_49 ) ;
break;
}
case V_61 : {
struct V_67 * V_49 ;
V_49 = F_23 ( V_36 , V_37 ,
struct V_67 ) ;
V_8 -> V_68 = F_37 ( V_36 , V_49 ) ;
V_8 -> V_69 = F_38 ( V_36 , V_49 ) ;
V_8 -> V_70 = F_39 ( V_36 , V_49 ) ;
V_8 -> V_71 = F_40 ( V_36 , V_49 ) ;
V_8 -> V_72 = F_41 ( V_36 , V_49 ) ;
break;
}
}
V_59:
V_38 = F_42 ( V_32 , V_34 ) ;
if ( V_38 < 0 )
goto V_41;
if ( V_38 )
break;
}
F_43 ( V_34 ) ;
V_29 . V_43 = 0 ;
V_29 . type = V_73 ;
V_29 . V_44 = 0 ;
V_38 = F_21 ( V_32 , & V_29 , V_34 , 1 , 0 ) ;
if ( V_38 )
goto V_41;
while ( 1 ) {
V_37 = V_34 -> V_45 [ 0 ] ;
V_36 = V_34 -> V_46 [ 0 ] ;
F_22 ( V_36 , & V_30 , V_37 ) ;
if ( V_30 . type != V_73 )
goto V_74;
if ( V_30 . V_43 > V_30 . V_44 ) {
goto V_74;
}
V_38 = F_15 ( V_3 , V_30 . V_43 ,
V_30 . V_44 ) ;
if ( V_38 == - V_21 ) {
F_25 ( V_75
L_5 ,
( unsigned long long ) V_30 . V_43 ,
( unsigned long long ) V_30 . V_44 ) ;
V_38 = 0 ;
}
if ( V_38 )
goto V_41;
V_74:
V_38 = F_42 ( V_32 , V_34 ) ;
if ( V_38 < 0 )
goto V_41;
if ( V_38 )
break;
}
V_41:
V_3 -> V_42 |= V_39 ;
if ( ! ( V_3 -> V_42 & V_76 ) ) {
V_3 -> V_40 = 0 ;
V_3 -> V_77 = 0 ;
}
F_44 ( V_34 ) ;
return V_38 < 0 ? V_38 : 0 ;
}
void F_45 ( struct V_2 * V_3 )
{
struct V_5 * V_6 ;
struct V_1 * V_8 ;
struct V_19 * V_20 ;
while ( ( V_6 = F_46 ( & V_3 -> V_7 ) ) ) {
V_8 = F_2 ( V_6 , struct V_1 , V_9 ) ;
F_10 ( V_6 , & V_3 -> V_7 ) ;
while ( ! F_12 ( & V_8 -> V_16 ) ) {
V_20 = F_13 ( & V_8 -> V_16 ,
struct V_19 ,
V_22 ) ;
F_11 ( & V_20 -> V_22 ) ;
F_11 ( & V_20 -> V_23 ) ;
F_14 ( V_20 ) ;
}
while ( ! F_12 ( & V_8 -> V_17 ) ) {
V_20 = F_13 ( & V_8 -> V_17 ,
struct V_19 ,
V_23 ) ;
F_11 ( & V_20 -> V_22 ) ;
F_11 ( & V_20 -> V_23 ) ;
F_14 ( V_20 ) ;
}
F_14 ( V_8 ) ;
}
}
static int F_47 ( struct V_78 * V_79 ,
struct V_31 * V_32 ,
T_1 V_80 , T_1 V_81 )
{
int V_38 ;
struct V_33 * V_34 ;
struct V_28 V_29 ;
V_34 = F_20 () ;
if ( ! V_34 )
return - V_15 ;
V_29 . V_43 = V_80 ;
V_29 . type = V_73 ;
V_29 . V_44 = V_81 ;
V_38 = F_48 ( V_79 , V_32 , V_34 , & V_29 , 0 ) ;
F_49 ( V_34 -> V_46 [ 0 ] ) ;
F_44 ( V_34 ) ;
return V_38 ;
}
static int F_50 ( struct V_78 * V_79 ,
struct V_31 * V_32 ,
T_1 V_80 , T_1 V_81 )
{
int V_38 ;
struct V_33 * V_34 ;
struct V_28 V_29 ;
V_34 = F_20 () ;
if ( ! V_34 )
return - V_15 ;
V_29 . V_43 = V_80 ;
V_29 . type = V_73 ;
V_29 . V_44 = V_81 ;
V_38 = F_51 ( V_79 , V_32 , & V_29 , V_34 , - 1 , 1 ) ;
if ( V_38 < 0 )
goto V_41;
if ( V_38 > 0 ) {
V_38 = - V_21 ;
goto V_41;
}
V_38 = F_52 ( V_79 , V_32 , V_34 ) ;
V_41:
F_44 ( V_34 ) ;
return V_38 ;
}
static int F_53 ( struct V_78 * V_79 ,
struct V_31 * V_32 , T_1 V_4 )
{
int V_38 ;
struct V_33 * V_34 ;
struct V_62 * V_82 ;
struct V_67 * V_83 ;
struct V_35 * V_84 ;
struct V_28 V_29 ;
V_34 = F_20 () ;
if ( ! V_34 )
return - V_15 ;
V_29 . V_43 = 0 ;
V_29 . type = V_60 ;
V_29 . V_44 = V_4 ;
V_38 = F_48 ( V_79 , V_32 , V_34 , & V_29 ,
sizeof( * V_82 ) ) ;
if ( V_38 )
goto V_41;
V_84 = V_34 -> V_46 [ 0 ] ;
V_82 = F_23 ( V_84 , V_34 -> V_45 [ 0 ] ,
struct V_62 ) ;
F_54 ( V_84 , V_82 , V_79 -> V_85 ) ;
F_55 ( V_84 , V_82 , 0 ) ;
F_56 ( V_84 , V_82 , 0 ) ;
F_57 ( V_84 , V_82 , 0 ) ;
F_58 ( V_84 , V_82 , 0 ) ;
F_49 ( V_84 ) ;
F_43 ( V_34 ) ;
V_29 . type = V_61 ;
V_38 = F_48 ( V_79 , V_32 , V_34 , & V_29 ,
sizeof( * V_83 ) ) ;
if ( V_38 )
goto V_41;
V_84 = V_34 -> V_46 [ 0 ] ;
V_83 = F_23 ( V_84 , V_34 -> V_45 [ 0 ] ,
struct V_67 ) ;
F_59 ( V_84 , V_83 , 0 ) ;
F_60 ( V_84 , V_83 , 0 ) ;
F_61 ( V_84 , V_83 , 0 ) ;
F_62 ( V_84 , V_83 , 0 ) ;
F_63 ( V_84 , V_83 , 0 ) ;
F_49 ( V_84 ) ;
V_38 = 0 ;
V_41:
F_44 ( V_34 ) ;
return V_38 ;
}
static int F_64 ( struct V_78 * V_79 ,
struct V_31 * V_32 , T_1 V_4 )
{
int V_38 ;
struct V_33 * V_34 ;
struct V_28 V_29 ;
V_34 = F_20 () ;
if ( ! V_34 )
return - V_15 ;
V_29 . V_43 = 0 ;
V_29 . type = V_60 ;
V_29 . V_44 = V_4 ;
V_38 = F_51 ( V_79 , V_32 , & V_29 , V_34 , - 1 , 1 ) ;
if ( V_38 < 0 )
goto V_41;
if ( V_38 > 0 ) {
V_38 = - V_21 ;
goto V_41;
}
V_38 = F_52 ( V_79 , V_32 , V_34 ) ;
if ( V_38 )
goto V_41;
F_43 ( V_34 ) ;
V_29 . type = V_61 ;
V_38 = F_51 ( V_79 , V_32 , & V_29 , V_34 , - 1 , 1 ) ;
if ( V_38 < 0 )
goto V_41;
if ( V_38 > 0 ) {
V_38 = - V_21 ;
goto V_41;
}
V_38 = F_52 ( V_79 , V_32 , V_34 ) ;
V_41:
F_44 ( V_34 ) ;
return V_38 ;
}
static int F_65 ( struct V_78 * V_79 ,
struct V_31 * V_86 , T_1 V_4 ,
T_1 V_39 , T_1 V_69 , T_1 V_70 ,
T_1 V_71 , T_1 V_72 )
{
struct V_33 * V_34 ;
struct V_28 V_29 ;
struct V_35 * V_36 ;
struct V_67 * V_83 ;
int V_38 ;
int V_37 ;
V_29 . V_43 = 0 ;
V_29 . type = V_61 ;
V_29 . V_44 = V_4 ;
V_34 = F_20 () ;
if ( ! V_34 )
return - V_15 ;
V_38 = F_51 ( V_79 , V_86 , & V_29 , V_34 , 0 , 1 ) ;
if ( V_38 > 0 )
V_38 = - V_21 ;
if ( V_38 )
goto V_41;
V_36 = V_34 -> V_46 [ 0 ] ;
V_37 = V_34 -> V_45 [ 0 ] ;
V_83 = F_23 ( V_36 , V_34 -> V_45 [ 0 ] ,
struct V_67 ) ;
F_59 ( V_36 , V_83 , V_39 ) ;
F_60 ( V_36 , V_83 , V_69 ) ;
F_61 ( V_36 , V_83 , V_70 ) ;
F_62 ( V_36 , V_83 , V_71 ) ;
F_63 ( V_36 , V_83 , V_72 ) ;
F_49 ( V_36 ) ;
V_41:
F_44 ( V_34 ) ;
return V_38 ;
}
static int F_66 ( struct V_78 * V_79 ,
struct V_31 * V_86 ,
struct V_1 * V_8 )
{
struct V_33 * V_34 ;
struct V_28 V_29 ;
struct V_35 * V_36 ;
struct V_62 * V_82 ;
int V_38 ;
int V_37 ;
V_29 . V_43 = 0 ;
V_29 . type = V_60 ;
V_29 . V_44 = V_8 -> V_4 ;
V_34 = F_20 () ;
if ( ! V_34 )
return - V_15 ;
V_38 = F_51 ( V_79 , V_86 , & V_29 , V_34 , 0 , 1 ) ;
if ( V_38 > 0 )
V_38 = - V_21 ;
if ( V_38 )
goto V_41;
V_36 = V_34 -> V_46 [ 0 ] ;
V_37 = V_34 -> V_45 [ 0 ] ;
V_82 = F_23 ( V_36 , V_34 -> V_45 [ 0 ] ,
struct V_62 ) ;
F_54 ( V_36 , V_82 , V_79 -> V_85 ) ;
F_55 ( V_36 , V_82 , V_8 -> V_63 ) ;
F_56 ( V_36 , V_82 , V_8 -> V_64 ) ;
F_57 ( V_36 , V_82 , V_8 -> V_65 ) ;
F_58 ( V_36 , V_82 , V_8 -> V_66 ) ;
F_49 ( V_36 ) ;
V_41:
F_44 ( V_34 ) ;
return V_38 ;
}
static int F_67 ( struct V_78 * V_79 ,
struct V_2 * V_3 ,
struct V_31 * V_86 )
{
struct V_33 * V_34 ;
struct V_28 V_29 ;
struct V_35 * V_36 ;
struct V_48 * V_49 ;
int V_38 ;
int V_37 ;
V_29 . V_43 = 0 ;
V_29 . type = V_47 ;
V_29 . V_44 = 0 ;
V_34 = F_20 () ;
if ( ! V_34 )
return - V_15 ;
V_38 = F_51 ( V_79 , V_86 , & V_29 , V_34 , 0 , 1 ) ;
if ( V_38 > 0 )
V_38 = - V_21 ;
if ( V_38 )
goto V_41;
V_36 = V_34 -> V_46 [ 0 ] ;
V_37 = V_34 -> V_45 [ 0 ] ;
V_49 = F_23 ( V_36 , V_37 , struct V_48 ) ;
F_68 ( V_36 , V_49 , V_3 -> V_42 ) ;
F_69 ( V_36 , V_49 , V_79 -> V_85 ) ;
F_70 ( V_36 , V_49 ,
V_3 -> V_54 . V_43 ) ;
F_49 ( V_36 ) ;
V_41:
F_44 ( V_34 ) ;
return V_38 ;
}
static int F_71 ( struct V_78 * V_79 ,
struct V_31 * V_86 )
{
struct V_33 * V_34 ;
struct V_28 V_29 ;
struct V_35 * V_84 = NULL ;
int V_38 ;
int V_87 = 0 ;
V_34 = F_20 () ;
if ( ! V_34 )
return - V_15 ;
V_34 -> V_88 = 1 ;
V_29 . V_43 = 0 ;
V_29 . V_44 = 0 ;
V_29 . type = 0 ;
while ( 1 ) {
V_38 = F_51 ( V_79 , V_86 , & V_29 , V_34 , - 1 , 1 ) ;
if ( V_38 < 0 )
goto V_41;
V_84 = V_34 -> V_46 [ 0 ] ;
V_87 = F_72 ( V_84 ) ;
if ( ! V_87 )
break;
V_34 -> V_45 [ 0 ] = 0 ;
V_38 = F_73 ( V_79 , V_86 , V_34 , 0 , V_87 ) ;
if ( V_38 )
goto V_41;
F_43 ( V_34 ) ;
}
V_38 = 0 ;
V_41:
V_86 -> V_3 -> V_77 = 0 ;
F_44 ( V_34 ) ;
return V_38 ;
}
int F_74 ( struct V_78 * V_79 ,
struct V_2 * V_3 )
{
struct V_31 * V_32 ;
struct V_31 * V_89 = V_3 -> V_89 ;
struct V_33 * V_34 = NULL ;
struct V_48 * V_49 ;
struct V_35 * V_84 ;
struct V_28 V_29 ;
struct V_28 V_30 ;
struct V_1 * V_8 = NULL ;
int V_38 = 0 ;
int V_37 ;
F_75 ( & V_3 -> V_90 ) ;
if ( V_3 -> V_32 ) {
V_3 -> V_77 = 1 ;
goto V_41;
}
V_32 = F_76 ( V_79 , V_3 ,
V_91 ) ;
if ( F_31 ( V_32 ) ) {
V_38 = F_32 ( V_32 ) ;
goto V_41;
}
V_34 = F_20 () ;
if ( ! V_34 ) {
V_38 = - V_15 ;
goto V_92;
}
V_29 . V_43 = 0 ;
V_29 . type = V_47 ;
V_29 . V_44 = 0 ;
V_38 = F_48 ( V_79 , V_32 , V_34 , & V_29 ,
sizeof( * V_49 ) ) ;
if ( V_38 )
goto V_93;
V_84 = V_34 -> V_46 [ 0 ] ;
V_49 = F_23 ( V_84 , V_34 -> V_45 [ 0 ] ,
struct V_48 ) ;
F_69 ( V_84 , V_49 , V_79 -> V_85 ) ;
F_77 ( V_84 , V_49 , V_50 ) ;
V_3 -> V_42 = V_76 |
V_53 ;
F_68 ( V_84 , V_49 , V_3 -> V_42 ) ;
F_70 ( V_84 , V_49 , 0 ) ;
F_49 ( V_84 ) ;
V_29 . V_43 = 0 ;
V_29 . type = V_94 ;
V_29 . V_44 = 0 ;
F_43 ( V_34 ) ;
V_38 = F_21 ( V_89 , & V_29 , V_34 , 1 , 0 ) ;
if ( V_38 > 0 )
goto V_95;
if ( V_38 < 0 )
goto V_93;
while ( 1 ) {
V_37 = V_34 -> V_45 [ 0 ] ;
V_84 = V_34 -> V_46 [ 0 ] ;
F_22 ( V_84 , & V_30 , V_37 ) ;
if ( V_30 . type == V_94 ) {
V_38 = F_53 ( V_79 , V_32 ,
V_30 . V_44 ) ;
if ( V_38 )
goto V_93;
V_8 = F_3 ( V_3 , V_30 . V_44 ) ;
if ( F_31 ( V_8 ) ) {
V_38 = F_32 ( V_8 ) ;
goto V_93;
}
}
V_38 = F_42 ( V_89 , V_34 ) ;
if ( V_38 < 0 )
goto V_93;
if ( V_38 )
break;
}
V_95:
F_43 ( V_34 ) ;
V_38 = F_53 ( V_79 , V_32 , V_96 ) ;
if ( V_38 )
goto V_93;
V_8 = F_3 ( V_3 , V_96 ) ;
if ( F_31 ( V_8 ) ) {
V_38 = F_32 ( V_8 ) ;
goto V_93;
}
F_78 ( & V_3 -> V_97 ) ;
V_3 -> V_32 = V_32 ;
V_3 -> V_77 = 1 ;
F_79 ( & V_3 -> V_97 ) ;
V_93:
F_44 ( V_34 ) ;
V_92:
if ( V_38 ) {
F_80 ( V_32 -> V_9 ) ;
F_80 ( V_32 -> V_98 ) ;
F_14 ( V_32 ) ;
}
V_41:
F_81 ( & V_3 -> V_90 ) ;
return V_38 ;
}
int F_82 ( struct V_78 * V_79 ,
struct V_2 * V_3 )
{
struct V_31 * V_89 = V_3 -> V_89 ;
struct V_31 * V_32 ;
int V_38 = 0 ;
F_75 ( & V_3 -> V_90 ) ;
if ( ! V_3 -> V_32 )
goto V_41;
F_78 ( & V_3 -> V_97 ) ;
V_3 -> V_40 = 0 ;
V_3 -> V_77 = 0 ;
V_32 = V_3 -> V_32 ;
V_3 -> V_32 = NULL ;
F_45 ( V_3 ) ;
F_79 ( & V_3 -> V_97 ) ;
if ( ! V_32 ) {
V_38 = - V_99 ;
goto V_41;
}
V_38 = F_71 ( V_79 , V_32 ) ;
if ( V_38 )
goto V_41;
V_38 = F_83 ( V_79 , V_89 , & V_32 -> V_100 ) ;
if ( V_38 )
goto V_41;
F_11 ( & V_32 -> V_101 ) ;
F_84 ( V_32 -> V_9 ) ;
F_85 ( V_79 , V_89 , V_32 -> V_9 ) ;
F_86 ( V_32 -> V_9 ) ;
F_87 ( V_79 , V_32 , V_32 -> V_9 , 0 , 1 ) ;
F_80 ( V_32 -> V_9 ) ;
F_80 ( V_32 -> V_98 ) ;
F_14 ( V_32 ) ;
V_41:
F_81 ( & V_3 -> V_90 ) ;
return V_38 ;
}
static void F_88 ( struct V_2 * V_3 ,
struct V_1 * V_8 )
{
if ( F_12 ( & V_8 -> V_18 ) )
F_89 ( & V_8 -> V_18 , & V_3 -> V_102 ) ;
}
int F_90 ( struct V_78 * V_79 ,
struct V_2 * V_3 , T_1 V_80 , T_1 V_81 )
{
struct V_31 * V_32 ;
struct V_1 * V_13 ;
struct V_1 * V_26 ;
struct V_19 * V_20 ;
int V_38 = 0 ;
F_75 ( & V_3 -> V_90 ) ;
V_32 = V_3 -> V_32 ;
if ( ! V_32 ) {
V_38 = - V_99 ;
goto V_41;
}
V_26 = F_1 ( V_3 , V_80 ) ;
V_13 = F_1 ( V_3 , V_81 ) ;
if ( ! V_26 || ! V_13 ) {
V_38 = - V_99 ;
goto V_41;
}
F_18 (list, &member->groups, next_group) {
if ( V_20 -> V_27 == V_13 ) {
V_38 = - V_103 ;
goto V_41;
}
}
V_38 = F_47 ( V_79 , V_32 , V_80 , V_81 ) ;
if ( V_38 )
goto V_41;
V_38 = F_47 ( V_79 , V_32 , V_81 , V_80 ) ;
if ( V_38 ) {
F_50 ( V_79 , V_32 , V_80 , V_81 ) ;
goto V_41;
}
F_78 ( & V_3 -> V_97 ) ;
V_38 = F_15 ( V_32 -> V_3 , V_80 , V_81 ) ;
F_79 ( & V_3 -> V_97 ) ;
V_41:
F_81 ( & V_3 -> V_90 ) ;
return V_38 ;
}
int F_91 ( struct V_78 * V_79 ,
struct V_2 * V_3 , T_1 V_80 , T_1 V_81 )
{
struct V_31 * V_32 ;
struct V_1 * V_13 ;
struct V_1 * V_26 ;
struct V_19 * V_20 ;
int V_38 = 0 ;
int V_104 ;
F_75 ( & V_3 -> V_90 ) ;
V_32 = V_3 -> V_32 ;
if ( ! V_32 ) {
V_38 = - V_99 ;
goto V_41;
}
V_26 = F_1 ( V_3 , V_80 ) ;
V_13 = F_1 ( V_3 , V_81 ) ;
if ( ! V_26 || ! V_13 ) {
V_38 = - V_99 ;
goto V_41;
}
F_18 (list, &member->groups, next_group) {
if ( V_20 -> V_27 == V_13 )
goto V_105;
}
V_38 = - V_21 ;
goto V_41;
V_105:
V_38 = F_50 ( V_79 , V_32 , V_80 , V_81 ) ;
V_104 = F_50 ( V_79 , V_32 , V_81 , V_80 ) ;
if ( V_104 && ! V_38 )
V_38 = V_104 ;
F_78 ( & V_3 -> V_97 ) ;
F_17 ( V_3 , V_80 , V_81 ) ;
F_79 ( & V_3 -> V_97 ) ;
V_41:
F_81 ( & V_3 -> V_90 ) ;
return V_38 ;
}
int F_92 ( struct V_78 * V_79 ,
struct V_2 * V_3 , T_1 V_4 , char * V_106 )
{
struct V_31 * V_32 ;
struct V_1 * V_8 ;
int V_38 = 0 ;
F_75 ( & V_3 -> V_90 ) ;
V_32 = V_3 -> V_32 ;
if ( ! V_32 ) {
V_38 = - V_99 ;
goto V_41;
}
V_8 = F_1 ( V_3 , V_4 ) ;
if ( V_8 ) {
V_38 = - V_103 ;
goto V_41;
}
V_38 = F_53 ( V_79 , V_32 , V_4 ) ;
if ( V_38 )
goto V_41;
F_78 ( & V_3 -> V_97 ) ;
V_8 = F_3 ( V_3 , V_4 ) ;
F_79 ( & V_3 -> V_97 ) ;
if ( F_31 ( V_8 ) )
V_38 = F_32 ( V_8 ) ;
V_41:
F_81 ( & V_3 -> V_90 ) ;
return V_38 ;
}
int F_93 ( struct V_78 * V_79 ,
struct V_2 * V_3 , T_1 V_4 )
{
struct V_31 * V_32 ;
struct V_1 * V_8 ;
int V_38 = 0 ;
F_75 ( & V_3 -> V_90 ) ;
V_32 = V_3 -> V_32 ;
if ( ! V_32 ) {
V_38 = - V_99 ;
goto V_41;
}
V_8 = F_1 ( V_3 , V_4 ) ;
if ( ! V_8 ) {
V_38 = - V_21 ;
goto V_41;
} else {
if ( ! F_12 ( & V_8 -> V_16 ) ||
! F_12 ( & V_8 -> V_17 ) ) {
V_38 = - V_107 ;
goto V_41;
}
}
V_38 = F_64 ( V_79 , V_32 , V_4 ) ;
F_78 ( & V_3 -> V_97 ) ;
F_9 ( V_32 -> V_3 , V_4 ) ;
F_79 ( & V_3 -> V_97 ) ;
V_41:
F_81 ( & V_3 -> V_90 ) ;
return V_38 ;
}
int F_94 ( struct V_78 * V_79 ,
struct V_2 * V_3 , T_1 V_4 ,
struct V_108 * V_109 )
{
struct V_31 * V_32 ;
struct V_1 * V_8 ;
int V_38 = 0 ;
F_75 ( & V_3 -> V_90 ) ;
V_32 = V_3 -> V_32 ;
if ( ! V_32 ) {
V_38 = - V_99 ;
goto V_41;
}
V_8 = F_1 ( V_3 , V_4 ) ;
if ( ! V_8 ) {
V_38 = - V_21 ;
goto V_41;
}
V_38 = F_65 ( V_79 , V_32 , V_4 ,
V_109 -> V_39 , V_109 -> V_69 ,
V_109 -> V_70 , V_109 -> V_71 ,
V_109 -> V_72 ) ;
if ( V_38 ) {
V_3 -> V_42 |= V_53 ;
F_25 ( V_110 L_6 ,
( unsigned long long ) V_4 ) ;
}
F_78 ( & V_3 -> V_97 ) ;
V_8 -> V_68 = V_109 -> V_39 ;
V_8 -> V_69 = V_109 -> V_69 ;
V_8 -> V_70 = V_109 -> V_70 ;
V_8 -> V_71 = V_109 -> V_71 ;
V_8 -> V_72 = V_109 -> V_72 ;
F_79 ( & V_3 -> V_97 ) ;
V_41:
F_81 ( & V_3 -> V_90 ) ;
return V_38 ;
}
int F_95 ( struct V_78 * V_79 ,
struct V_111 * V_9 ,
struct V_112 * V_113 )
{
struct V_114 * V_115 ;
F_96 ( ! V_79 -> V_116 . V_117 ) ;
V_115 = F_29 ( sizeof( * V_115 ) , V_58 ) ;
if ( ! V_115 )
return - V_15 ;
V_115 -> V_9 = V_9 ;
V_115 -> V_113 = V_113 ;
F_16 ( & V_115 -> V_20 , & V_79 -> V_118 ) ;
return 0 ;
}
static int F_97 ( struct V_2 * V_3 ,
struct V_119 * V_120 , struct V_119 * V_121 ,
T_1 V_117 )
{
struct V_122 * V_123 ;
struct V_124 V_125 ;
struct V_122 * V_126 ;
struct V_124 V_127 ;
struct V_1 * V_128 ;
int V_38 ;
F_98 ( & V_125 ) ;
while ( ( V_123 = F_99 ( V_120 , & V_125 ) ) ) {
V_128 = F_1 ( V_3 , V_123 -> V_129 ) ;
if ( ! V_128 )
continue;
F_100 ( V_121 ) ;
V_38 = F_101 ( V_121 , V_128 -> V_4 ,
( T_1 ) ( V_130 ) V_128 , V_14 ) ;
if ( V_38 < 0 )
return V_38 ;
F_98 ( & V_127 ) ;
while ( ( V_126 = F_99 ( V_121 , & V_127 ) ) ) {
struct V_19 * V_131 ;
V_128 = (struct V_1 * ) ( V_130 ) V_126 -> V_132 ;
if ( V_128 -> V_133 < V_117 )
V_128 -> V_133 = V_117 + 1 ;
else
++ V_128 -> V_133 ;
F_18 (glist, &qg->groups, next_group) {
V_38 = F_101 ( V_121 , V_131 -> V_27 -> V_4 ,
( T_1 ) ( V_130 ) V_131 -> V_27 ,
V_14 ) ;
if ( V_38 < 0 )
return V_38 ;
}
}
}
return 0 ;
}
static int F_102 ( struct V_2 * V_3 ,
struct V_119 * V_120 , struct V_119 * V_121 ,
T_1 V_117 , int V_134 , T_1 V_135 ,
struct V_1 * V_8 )
{
struct V_122 * V_123 ;
struct V_124 V_125 ;
struct V_1 * V_128 ;
struct V_19 * V_131 ;
int V_38 ;
F_100 ( V_121 ) ;
V_38 = F_101 ( V_121 , V_8 -> V_4 , ( V_130 ) V_8 , V_14 ) ;
if ( V_38 < 0 )
return V_38 ;
F_98 ( & V_125 ) ;
while ( ( V_123 = F_99 ( V_121 , & V_125 ) ) ) {
V_128 = (struct V_1 * ) ( V_130 ) V_123 -> V_132 ;
if ( V_128 -> V_133 < V_117 ) {
V_128 -> V_63 += V_134 * V_135 ;
V_128 -> V_64 += V_134 * V_135 ;
if ( V_120 -> V_136 == 0 ) {
V_128 -> V_65 += V_134 * V_135 ;
V_128 -> V_66 += V_134 * V_135 ;
}
F_88 ( V_3 , V_128 ) ;
}
F_103 ( V_128 -> V_137 >= V_117 ) ;
V_128 -> V_137 = V_117 ;
F_18 (glist, &qg->groups, next_group) {
V_38 = F_101 ( V_121 , V_131 -> V_27 -> V_4 ,
( V_130 ) V_131 -> V_27 , V_14 ) ;
if ( V_38 < 0 )
return V_38 ;
}
}
return 0 ;
}
static int F_104 ( struct V_2 * V_3 ,
struct V_119 * V_120 , struct V_119 * V_121 ,
T_1 V_117 , int V_134 , T_1 V_135 )
{
struct V_122 * V_123 ;
struct V_124 V_125 ;
struct V_1 * V_128 ;
struct V_122 * V_126 ;
struct V_124 V_127 ;
int V_38 ;
F_98 ( & V_125 ) ;
while ( ( V_123 = F_99 ( V_120 , & V_125 ) ) ) {
V_128 = F_1 ( V_3 , V_123 -> V_129 ) ;
if ( ! V_128 )
continue;
F_100 ( V_121 ) ;
V_38 = F_101 ( V_121 , V_128 -> V_4 , ( V_130 ) V_128 , V_14 ) ;
if ( V_38 < 0 )
return V_38 ;
F_98 ( & V_127 ) ;
while ( ( V_126 = F_99 ( V_121 , & V_127 ) ) ) {
struct V_19 * V_131 ;
V_128 = (struct V_1 * ) ( V_130 ) V_126 -> V_132 ;
if ( V_128 -> V_137 == V_117 )
continue;
if ( V_128 -> V_133 - V_117 == V_120 -> V_136 ) {
V_128 -> V_65 -= V_134 * V_135 ;
V_128 -> V_66 -= V_134 * V_135 ;
F_88 ( V_3 , V_128 ) ;
}
F_18 (glist, &qg->groups, next_group) {
V_38 = F_101 ( V_121 , V_131 -> V_27 -> V_4 ,
( V_130 ) V_131 -> V_27 ,
V_14 ) ;
if ( V_38 < 0 )
return V_38 ;
}
}
}
return 0 ;
}
int F_105 ( struct V_78 * V_79 ,
struct V_2 * V_3 ,
struct V_111 * V_9 ,
struct V_112 * V_113 )
{
struct V_28 V_138 ;
struct V_31 * V_32 ;
T_1 V_139 ;
struct V_1 * V_8 ;
struct V_119 * V_120 = NULL ;
struct V_119 * V_121 = NULL ;
T_1 V_117 ;
int V_38 = 0 ;
int V_134 ;
if ( ! V_3 -> V_40 )
return 0 ;
F_96 ( ! V_3 -> V_32 ) ;
V_138 . V_43 = V_9 -> V_140 ;
V_138 . V_44 = V_9 -> V_135 ;
V_138 . type = V_141 ;
if ( V_9 -> type == V_142 ||
V_9 -> type == V_143 ) {
struct V_144 * V_145 ;
V_145 = F_106 ( V_9 ) ;
V_139 = V_145 -> V_86 ;
} else if ( V_9 -> type == V_146 ||
V_9 -> type == V_147 ) {
struct V_148 * V_145 ;
V_145 = F_107 ( V_9 ) ;
V_139 = V_145 -> V_86 ;
} else {
F_108 () ;
}
if ( ! F_109 ( V_139 ) ) {
return 0 ;
}
switch ( V_9 -> V_149 ) {
case V_150 :
case V_151 :
V_134 = 1 ;
V_117 = F_110 ( V_9 -> V_117 ) ;
break;
case V_152 :
V_134 = - 1 ;
V_117 = V_9 -> V_117 ;
break;
case V_153 :
return 0 ;
default:
F_108 () ;
}
F_75 ( & V_3 -> V_154 ) ;
if ( V_3 -> V_42 & V_55 ) {
if ( V_3 -> V_54 . V_43 <= V_9 -> V_140 ) {
F_81 ( & V_3 -> V_154 ) ;
return 0 ;
}
}
F_81 ( & V_3 -> V_154 ) ;
V_38 = F_111 ( V_79 , V_3 , V_9 -> V_140 , V_117 , & V_120 ) ;
if ( V_38 < 0 )
return V_38 ;
F_75 ( & V_3 -> V_154 ) ;
F_78 ( & V_3 -> V_97 ) ;
if ( V_3 -> V_42 & V_55 ) {
if ( V_3 -> V_54 . V_43 <= V_9 -> V_140 ) {
V_38 = 0 ;
goto V_155;
}
}
V_32 = V_3 -> V_32 ;
if ( ! V_32 )
goto V_155;
V_8 = F_1 ( V_3 , V_139 ) ;
if ( ! V_8 )
goto V_155;
V_121 = F_112 ( V_14 ) ;
if ( ! V_121 ) {
V_38 = - V_15 ;
goto V_155;
}
V_117 = V_3 -> V_156 ;
V_3 -> V_156 += V_120 -> V_136 + 1 ;
V_38 = F_97 ( V_3 , V_120 , V_121 , V_117 ) ;
if ( V_38 )
goto V_155;
V_38 = F_102 ( V_3 , V_120 , V_121 , V_117 , V_134 ,
V_9 -> V_135 , V_8 ) ;
if ( V_38 )
goto V_155;
V_38 = F_104 ( V_3 , V_120 , V_121 , V_117 , V_134 ,
V_9 -> V_135 ) ;
if ( V_38 )
goto V_155;
V_155:
F_79 ( & V_3 -> V_97 ) ;
F_81 ( & V_3 -> V_154 ) ;
F_113 ( V_120 ) ;
F_113 ( V_121 ) ;
return V_38 ;
}
int F_114 ( struct V_78 * V_79 ,
struct V_2 * V_3 )
{
struct V_31 * V_32 = V_3 -> V_32 ;
int V_38 = 0 ;
int V_157 = 0 ;
if ( ! V_32 )
goto V_41;
if ( ! V_3 -> V_40 && V_3 -> V_77 )
V_157 = 1 ;
V_3 -> V_40 = V_3 -> V_77 ;
F_78 ( & V_3 -> V_97 ) ;
while ( ! F_12 ( & V_3 -> V_102 ) ) {
struct V_1 * V_8 ;
V_8 = F_13 ( & V_3 -> V_102 ,
struct V_1 , V_18 ) ;
F_115 ( & V_8 -> V_18 ) ;
F_79 ( & V_3 -> V_97 ) ;
V_38 = F_66 ( V_79 , V_32 , V_8 ) ;
if ( V_38 )
V_3 -> V_42 |=
V_53 ;
F_78 ( & V_3 -> V_97 ) ;
}
if ( V_3 -> V_40 )
V_3 -> V_42 |= V_76 ;
else
V_3 -> V_42 &= ~ V_76 ;
F_79 ( & V_3 -> V_97 ) ;
V_38 = F_67 ( V_79 , V_3 , V_32 ) ;
if ( V_38 )
V_3 -> V_42 |= V_53 ;
if ( ! V_38 && V_157 ) {
V_38 = F_116 ( V_3 ) ;
if ( V_38 )
F_117 ( L_7 , V_38 ) ;
V_38 = 0 ;
}
V_41:
return V_38 ;
}
int F_118 ( struct V_78 * V_79 ,
struct V_2 * V_3 , T_1 V_158 , T_1 V_43 ,
struct F_118 * V_159 )
{
int V_38 = 0 ;
int V_160 ;
T_1 * V_161 ;
struct V_31 * V_32 = V_3 -> V_32 ;
struct V_1 * V_162 ;
struct V_1 * V_163 ;
T_2 V_164 = 0 ;
T_1 V_165 ;
F_75 ( & V_3 -> V_90 ) ;
if ( ! V_3 -> V_40 )
goto V_41;
if ( ! V_32 ) {
V_38 = - V_99 ;
goto V_41;
}
if ( V_159 ) {
V_161 = ( T_1 * ) ( V_159 + 1 ) ;
V_165 = V_159 -> V_166 + 2 * V_159 -> V_167 +
2 * V_159 -> V_168 ;
for ( V_160 = 0 ; V_160 < V_165 ; ++ V_160 ) {
V_162 = F_1 ( V_3 , * V_161 ) ;
if ( ! V_162 ) {
V_38 = - V_99 ;
goto V_41;
}
++ V_161 ;
}
}
V_38 = F_53 ( V_79 , V_32 , V_43 ) ;
if ( V_38 )
goto V_41;
if ( V_159 && V_159 -> V_39 & V_169 ) {
V_38 = F_65 ( V_79 , V_32 , V_43 ,
V_159 -> V_170 . V_39 ,
V_159 -> V_170 . V_69 ,
V_159 -> V_170 . V_70 ,
V_159 -> V_170 . V_71 ,
V_159 -> V_170 . V_72 ) ;
if ( V_38 )
goto V_41;
}
if ( V_158 ) {
struct V_31 * V_171 ;
struct V_28 V_172 ;
int V_173 ;
V_172 . V_43 = V_158 ;
V_172 . type = V_174 ;
V_172 . V_44 = ( T_1 ) - 1 ;
V_171 = F_119 ( V_3 , & V_172 ) ;
if ( F_31 ( V_171 ) ) {
V_38 = F_32 ( V_171 ) ;
goto V_41;
}
F_120 () ;
V_173 = F_121 ( V_171 -> V_9 ) ;
V_164 = F_122 ( V_171 , V_173 ) ;
F_123 () ;
}
if ( V_159 ) {
V_161 = ( T_1 * ) ( V_159 + 1 ) ;
for ( V_160 = 0 ; V_160 < V_159 -> V_166 ; ++ V_160 ) {
V_38 = F_47 ( V_79 , V_32 ,
V_43 , * V_161 ) ;
if ( V_38 )
goto V_41;
V_38 = F_47 ( V_79 , V_32 ,
* V_161 , V_43 ) ;
if ( V_38 )
goto V_41;
++ V_161 ;
}
}
F_78 ( & V_3 -> V_97 ) ;
V_163 = F_3 ( V_3 , V_43 ) ;
if ( F_31 ( V_163 ) ) {
V_38 = F_32 ( V_163 ) ;
goto V_155;
}
if ( V_158 ) {
V_162 = F_1 ( V_3 , V_158 ) ;
if ( ! V_162 )
goto V_155;
V_163 -> V_63 = V_162 -> V_63 - V_164 ;
V_163 -> V_64 = V_162 -> V_64 - V_164 ;
V_162 -> V_65 = V_164 ;
V_162 -> V_66 = V_164 ;
F_88 ( V_3 , V_163 ) ;
F_88 ( V_3 , V_162 ) ;
}
if ( ! V_159 )
goto V_155;
V_161 = ( T_1 * ) ( V_159 + 1 ) ;
for ( V_160 = 0 ; V_160 < V_159 -> V_166 ; ++ V_160 ) {
V_38 = F_15 ( V_32 -> V_3 , V_43 ,
* V_161 ) ;
if ( V_38 )
goto V_155;
++ V_161 ;
}
for ( V_160 = 0 ; V_160 < V_159 -> V_167 ; ++ V_160 ) {
struct V_1 * V_80 ;
struct V_1 * V_81 ;
V_80 = F_1 ( V_3 , V_161 [ 0 ] ) ;
V_81 = F_1 ( V_3 , V_161 [ 1 ] ) ;
if ( ! V_80 || ! V_81 ) {
V_38 = - V_99 ;
goto V_155;
}
V_81 -> V_63 = V_80 -> V_63 - V_164 ;
V_81 -> V_64 = V_80 -> V_64 - V_164 ;
V_161 += 2 ;
}
for ( V_160 = 0 ; V_160 < V_159 -> V_168 ; ++ V_160 ) {
struct V_1 * V_80 ;
struct V_1 * V_81 ;
V_80 = F_1 ( V_3 , V_161 [ 0 ] ) ;
V_81 = F_1 ( V_3 , V_161 [ 1 ] ) ;
if ( ! V_80 || ! V_81 ) {
V_38 = - V_99 ;
goto V_155;
}
V_81 -> V_65 = V_80 -> V_65 + V_164 ;
V_81 -> V_66 = V_80 -> V_66 + V_164 ;
V_161 += 2 ;
}
V_155:
F_79 ( & V_3 -> V_97 ) ;
V_41:
F_81 ( & V_3 -> V_90 ) ;
return V_38 ;
}
int F_124 ( struct V_31 * V_86 , T_1 V_135 )
{
struct V_31 * V_32 ;
struct V_1 * V_8 ;
struct V_2 * V_3 = V_86 -> V_3 ;
T_1 V_139 = V_86 -> V_100 . V_43 ;
int V_38 = 0 ;
struct V_119 * V_119 = NULL ;
struct V_122 * V_123 ;
struct V_124 V_125 ;
if ( ! F_109 ( V_139 ) )
return 0 ;
if ( V_135 == 0 )
return 0 ;
F_78 ( & V_3 -> V_97 ) ;
V_32 = V_3 -> V_32 ;
if ( ! V_32 )
goto V_41;
V_8 = F_1 ( V_3 , V_139 ) ;
if ( ! V_8 )
goto V_41;
V_119 = F_112 ( V_14 ) ;
if ( ! V_119 ) {
V_38 = - V_15 ;
goto V_41;
}
V_38 = F_101 ( V_119 , V_8 -> V_4 ,
( V_130 ) V_8 , V_14 ) ;
if ( V_38 < 0 )
goto V_41;
F_98 ( & V_125 ) ;
while ( ( V_123 = F_99 ( V_119 , & V_125 ) ) ) {
struct V_1 * V_128 ;
struct V_19 * V_131 ;
V_128 = (struct V_1 * ) ( V_130 ) V_123 -> V_132 ;
if ( ( V_128 -> V_68 & V_175 ) &&
V_128 -> V_176 + ( V_177 ) V_128 -> V_63 + V_135 >
V_128 -> V_69 ) {
V_38 = - V_178 ;
goto V_41;
}
if ( ( V_128 -> V_68 & V_179 ) &&
V_128 -> V_176 + ( V_177 ) V_128 -> V_65 + V_135 >
V_128 -> V_70 ) {
V_38 = - V_178 ;
goto V_41;
}
F_18 (glist, &qg->groups, next_group) {
V_38 = F_101 ( V_119 , V_131 -> V_27 -> V_4 ,
( V_130 ) V_131 -> V_27 , V_14 ) ;
if ( V_38 < 0 )
goto V_41;
}
}
V_38 = 0 ;
F_98 ( & V_125 ) ;
while ( ( V_123 = F_99 ( V_119 , & V_125 ) ) ) {
struct V_1 * V_128 ;
V_128 = (struct V_1 * ) ( V_130 ) V_123 -> V_132 ;
V_128 -> V_176 += V_135 ;
}
V_41:
F_79 ( & V_3 -> V_97 ) ;
F_113 ( V_119 ) ;
return V_38 ;
}
void F_125 ( struct V_31 * V_86 , T_1 V_135 )
{
struct V_31 * V_32 ;
struct V_1 * V_8 ;
struct V_2 * V_3 = V_86 -> V_3 ;
struct V_119 * V_119 = NULL ;
struct V_122 * V_123 ;
struct V_124 V_125 ;
T_1 V_139 = V_86 -> V_100 . V_43 ;
int V_38 = 0 ;
if ( ! F_109 ( V_139 ) )
return;
if ( V_135 == 0 )
return;
F_78 ( & V_3 -> V_97 ) ;
V_32 = V_3 -> V_32 ;
if ( ! V_32 )
goto V_41;
V_8 = F_1 ( V_3 , V_139 ) ;
if ( ! V_8 )
goto V_41;
V_119 = F_112 ( V_14 ) ;
if ( ! V_119 ) {
F_126 ( V_3 , - V_15 ) ;
goto V_41;
}
V_38 = F_101 ( V_119 , V_8 -> V_4 ,
( V_130 ) V_8 , V_14 ) ;
if ( V_38 < 0 )
goto V_41;
F_98 ( & V_125 ) ;
while ( ( V_123 = F_99 ( V_119 , & V_125 ) ) ) {
struct V_1 * V_128 ;
struct V_19 * V_131 ;
V_128 = (struct V_1 * ) ( V_130 ) V_123 -> V_132 ;
V_128 -> V_176 -= V_135 ;
F_18 (glist, &qg->groups, next_group) {
V_38 = F_101 ( V_119 , V_131 -> V_27 -> V_4 ,
( V_130 ) V_131 -> V_27 , V_14 ) ;
if ( V_38 < 0 )
goto V_41;
}
}
V_41:
F_79 ( & V_3 -> V_97 ) ;
F_113 ( V_119 ) ;
}
void F_127 ( struct V_78 * V_79 )
{
if ( F_12 ( & V_79 -> V_118 ) && ! V_79 -> V_116 . V_117 )
return;
F_117 ( L_8 ,
V_79 , F_12 ( & V_79 -> V_118 ) ? L_9 : L_10 ,
( T_2 ) ( V_79 -> V_116 . V_117 >> 32 ) ,
( T_2 ) V_79 -> V_116 . V_117 ) ;
F_108 () ;
}
static int
F_128 ( struct V_56 * V_57 , struct V_33 * V_34 ,
struct V_78 * V_79 , struct V_119 * V_121 ,
struct V_35 * V_180 )
{
struct V_28 V_181 ;
struct V_2 * V_3 = V_57 -> V_3 ;
struct V_119 * V_120 = NULL ;
struct V_122 * V_123 ;
struct V_124 V_125 ;
struct V_182 V_183 = {} ;
T_1 V_117 ;
int V_37 ;
int V_38 ;
V_34 -> V_88 = 1 ;
F_75 ( & V_3 -> V_154 ) ;
V_38 = F_21 ( V_3 -> V_184 ,
& V_3 -> V_54 ,
V_34 , 1 , 0 ) ;
F_129 ( L_11 ,
( unsigned long long ) V_3 -> V_54 . V_43 ,
V_3 -> V_54 . type ,
( unsigned long long ) V_3 -> V_54 . V_44 ,
V_38 ) ;
if ( V_38 ) {
V_3 -> V_54 . V_43 = ( T_1 ) - 1 ;
F_43 ( V_34 ) ;
F_81 ( & V_3 -> V_154 ) ;
return V_38 ;
}
F_22 ( V_34 -> V_46 [ 0 ] , & V_181 ,
F_72 ( V_34 -> V_46 [ 0 ] ) - 1 ) ;
V_3 -> V_54 . V_43 = V_181 . V_43 + 1 ;
F_130 ( V_3 , & V_183 ) ;
memcpy ( V_180 , V_34 -> V_46 [ 0 ] , sizeof( * V_180 ) ) ;
V_37 = V_34 -> V_45 [ 0 ] ;
F_43 ( V_34 ) ;
F_81 ( & V_3 -> V_154 ) ;
for (; V_37 < F_72 ( V_180 ) ; ++ V_37 ) {
F_22 ( V_180 , & V_181 , V_37 ) ;
if ( V_181 . type != V_141 )
continue;
V_38 = F_111 ( V_79 , V_3 , V_181 . V_43 ,
V_183 . V_117 , & V_120 ) ;
if ( V_38 < 0 )
goto V_41;
F_78 ( & V_3 -> V_97 ) ;
V_117 = V_3 -> V_156 ;
V_3 -> V_156 += V_120 -> V_136 + 1 ;
V_38 = F_97 ( V_3 , V_120 , V_121 , V_117 ) ;
if ( V_38 ) {
F_79 ( & V_3 -> V_97 ) ;
F_113 ( V_120 ) ;
goto V_41;
}
F_100 ( V_121 ) ;
F_98 ( & V_125 ) ;
while ( ( V_123 = F_99 ( V_120 , & V_125 ) ) ) {
struct V_1 * V_128 ;
V_128 = F_1 ( V_3 , V_123 -> V_129 ) ;
if ( ! V_128 )
continue;
V_38 = F_101 ( V_121 , V_128 -> V_4 , ( V_130 ) V_128 ,
V_14 ) ;
if ( V_38 < 0 ) {
F_79 ( & V_3 -> V_97 ) ;
F_113 ( V_120 ) ;
goto V_41;
}
}
F_98 ( & V_125 ) ;
while ( ( V_123 = F_99 ( V_121 , & V_125 ) ) ) {
struct V_1 * V_128 ;
struct V_19 * V_131 ;
V_128 = (struct V_1 * ) ( V_130 ) V_123 -> V_132 ;
V_128 -> V_63 += V_181 . V_44 ;
V_128 -> V_64 += V_181 . V_44 ;
F_103 ( V_128 -> V_137 >= V_117 ) ;
if ( V_128 -> V_133 - V_117 == V_120 -> V_136 ) {
V_128 -> V_65 += V_181 . V_44 ;
V_128 -> V_66 += V_181 . V_44 ;
}
F_88 ( V_3 , V_128 ) ;
F_18 (glist, &qg->groups, next_group) {
V_38 = F_101 ( V_121 , V_131 -> V_27 -> V_4 ,
( V_130 ) V_131 -> V_27 ,
V_14 ) ;
if ( V_38 < 0 ) {
F_79 ( & V_3 -> V_97 ) ;
F_113 ( V_120 ) ;
goto V_41;
}
}
}
F_79 ( & V_3 -> V_97 ) ;
F_113 ( V_120 ) ;
V_38 = 0 ;
}
V_41:
F_131 ( V_3 , & V_183 ) ;
return V_38 ;
}
static void F_132 ( struct V_185 * V_186 )
{
struct V_56 * V_57 = F_133 ( V_186 , struct V_56 ,
V_186 ) ;
struct V_33 * V_34 ;
struct V_78 * V_79 = NULL ;
struct V_2 * V_3 = V_57 -> V_3 ;
struct V_119 * V_121 = NULL ;
struct V_35 * V_180 = NULL ;
int V_104 = - V_15 ;
V_34 = F_20 () ;
if ( ! V_34 )
goto V_41;
V_121 = F_112 ( V_58 ) ;
if ( ! V_121 )
goto V_41;
V_180 = F_29 ( sizeof( * V_180 ) , V_58 ) ;
if ( ! V_180 )
goto V_41;
V_104 = 0 ;
while ( ! V_104 ) {
V_79 = F_134 ( V_3 -> V_187 , 0 ) ;
if ( F_31 ( V_79 ) ) {
V_104 = F_32 ( V_79 ) ;
break;
}
if ( ! V_3 -> V_40 ) {
V_104 = - V_188 ;
} else {
V_104 = F_128 ( V_57 , V_34 , V_79 ,
V_121 , V_180 ) ;
}
if ( V_104 > 0 )
F_135 ( V_79 , V_3 -> V_187 ) ;
else
F_136 ( V_79 , V_3 -> V_187 ) ;
}
V_41:
F_14 ( V_180 ) ;
F_113 ( V_121 ) ;
F_44 ( V_34 ) ;
F_14 ( V_57 ) ;
F_75 ( & V_3 -> V_154 ) ;
V_3 -> V_42 &= ~ V_55 ;
if ( V_104 == 2 &&
V_3 -> V_42 & V_53 ) {
V_3 -> V_42 &= ~ V_53 ;
} else if ( V_104 < 0 ) {
V_3 -> V_42 |= V_53 ;
}
F_81 ( & V_3 -> V_154 ) ;
if ( V_104 >= 0 ) {
F_137 ( L_12 ,
V_104 == 2 ? L_13 : L_9 ) ;
} else {
F_117 ( L_14 , V_104 ) ;
}
}
static void
F_30 ( struct V_2 * V_3 , struct V_56 * V_57 )
{
memset ( & V_57 -> V_186 , 0 , sizeof( V_57 -> V_186 ) ) ;
V_57 -> V_186 . V_189 = F_132 ;
V_57 -> V_3 = V_3 ;
F_137 ( L_15 ) ;
F_138 ( & V_3 -> V_190 , & V_57 -> V_186 ) ;
}
int
F_116 ( struct V_2 * V_3 )
{
int V_38 = 0 ;
struct V_5 * V_6 ;
struct V_1 * V_8 ;
struct V_56 * V_57 = F_29 ( sizeof( * V_57 ) , V_58 ) ;
if ( ! V_57 )
return - V_15 ;
F_75 ( & V_3 -> V_154 ) ;
F_78 ( & V_3 -> V_97 ) ;
if ( V_3 -> V_42 & V_55 )
V_38 = - V_191 ;
else if ( ! ( V_3 -> V_42 & V_76 ) )
V_38 = - V_99 ;
if ( V_38 ) {
F_79 ( & V_3 -> V_97 ) ;
F_81 ( & V_3 -> V_154 ) ;
F_14 ( V_57 ) ;
return V_38 ;
}
V_3 -> V_42 |= V_55 ;
memset ( & V_3 -> V_54 , 0 ,
sizeof( V_3 -> V_54 ) ) ;
for ( V_6 = F_46 ( & V_3 -> V_7 ) ; V_6 ; V_6 = F_139 ( V_6 ) ) {
V_8 = F_2 ( V_6 , struct V_1 , V_9 ) ;
V_8 -> V_63 = 0 ;
V_8 -> V_64 = 0 ;
V_8 -> V_65 = 0 ;
V_8 -> V_66 = 0 ;
}
F_79 ( & V_3 -> V_97 ) ;
F_81 ( & V_3 -> V_154 ) ;
F_30 ( V_3 , V_57 ) ;
return 0 ;
}
