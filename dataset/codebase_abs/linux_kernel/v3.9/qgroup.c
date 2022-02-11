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
goto V_54;
}
if ( V_30 . type != V_55 &&
V_30 . type != V_56 )
goto V_54;
V_8 = F_1 ( V_3 , V_30 . V_44 ) ;
if ( ( V_8 && V_30 . type == V_55 ) ||
( ! V_8 && V_30 . type == V_56 ) ) {
F_25 ( V_51 L_4 ) ;
V_39 |= V_53 ;
}
if ( ! V_8 ) {
V_8 = F_3 ( V_3 , V_30 . V_44 ) ;
if ( F_28 ( V_8 ) ) {
V_38 = F_29 ( V_8 ) ;
goto V_41;
}
}
switch ( V_30 . type ) {
case V_55 : {
struct V_57 * V_49 ;
V_49 = F_23 ( V_36 , V_37 ,
struct V_57 ) ;
V_8 -> V_58 = F_30 ( V_36 , V_49 ) ;
V_8 -> V_59 = F_31 ( V_36 , V_49 ) ;
V_8 -> V_60 = F_32 ( V_36 , V_49 ) ;
V_8 -> V_61 = F_33 ( V_36 , V_49 ) ;
break;
}
case V_56 : {
struct V_62 * V_49 ;
V_49 = F_23 ( V_36 , V_37 ,
struct V_62 ) ;
V_8 -> V_63 = F_34 ( V_36 , V_49 ) ;
V_8 -> V_64 = F_35 ( V_36 , V_49 ) ;
V_8 -> V_65 = F_36 ( V_36 , V_49 ) ;
V_8 -> V_66 = F_37 ( V_36 , V_49 ) ;
V_8 -> V_67 = F_38 ( V_36 , V_49 ) ;
break;
}
}
V_54:
V_38 = F_39 ( V_32 , V_34 ) ;
if ( V_38 < 0 )
goto V_41;
if ( V_38 )
break;
}
F_40 ( V_34 ) ;
V_29 . V_43 = 0 ;
V_29 . type = V_68 ;
V_29 . V_44 = 0 ;
V_38 = F_21 ( V_32 , & V_29 , V_34 , 1 , 0 ) ;
if ( V_38 )
goto V_41;
while ( 1 ) {
V_37 = V_34 -> V_45 [ 0 ] ;
V_36 = V_34 -> V_46 [ 0 ] ;
F_22 ( V_36 , & V_30 , V_37 ) ;
if ( V_30 . type != V_68 )
goto V_69;
if ( V_30 . V_43 > V_30 . V_44 ) {
goto V_69;
}
V_38 = F_15 ( V_3 , V_30 . V_43 ,
V_30 . V_44 ) ;
if ( V_38 == - V_21 ) {
F_25 ( V_70
L_5 ,
( unsigned long long ) V_30 . V_43 ,
( unsigned long long ) V_30 . V_44 ) ;
V_38 = 0 ;
}
if ( V_38 )
goto V_41;
V_69:
V_38 = F_39 ( V_32 , V_34 ) ;
if ( V_38 < 0 )
goto V_41;
if ( V_38 )
break;
}
V_41:
V_3 -> V_42 |= V_39 ;
if ( ! ( V_3 -> V_42 & V_71 ) ) {
V_3 -> V_40 = 0 ;
V_3 -> V_72 = 0 ;
}
F_41 ( V_34 ) ;
return V_38 < 0 ? V_38 : 0 ;
}
void F_42 ( struct V_2 * V_3 )
{
struct V_5 * V_6 ;
struct V_1 * V_8 ;
struct V_19 * V_20 ;
while ( ( V_6 = F_43 ( & V_3 -> V_7 ) ) ) {
V_8 = F_2 ( V_6 , struct V_1 , V_9 ) ;
F_10 ( V_6 , & V_3 -> V_7 ) ;
F_44 ( ! F_12 ( & V_8 -> V_18 ) ) ;
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
static int F_45 ( struct V_73 * V_74 ,
struct V_31 * V_32 ,
T_1 V_75 , T_1 V_76 )
{
int V_38 ;
struct V_33 * V_34 ;
struct V_28 V_29 ;
V_34 = F_20 () ;
if ( ! V_34 )
return - V_15 ;
V_29 . V_43 = V_75 ;
V_29 . type = V_68 ;
V_29 . V_44 = V_76 ;
V_38 = F_46 ( V_74 , V_32 , V_34 , & V_29 , 0 ) ;
F_47 ( V_34 -> V_46 [ 0 ] ) ;
F_41 ( V_34 ) ;
return V_38 ;
}
static int F_48 ( struct V_73 * V_74 ,
struct V_31 * V_32 ,
T_1 V_75 , T_1 V_76 )
{
int V_38 ;
struct V_33 * V_34 ;
struct V_28 V_29 ;
V_34 = F_20 () ;
if ( ! V_34 )
return - V_15 ;
V_29 . V_43 = V_75 ;
V_29 . type = V_68 ;
V_29 . V_44 = V_76 ;
V_38 = F_49 ( V_74 , V_32 , & V_29 , V_34 , - 1 , 1 ) ;
if ( V_38 < 0 )
goto V_41;
if ( V_38 > 0 ) {
V_38 = - V_21 ;
goto V_41;
}
V_38 = F_50 ( V_74 , V_32 , V_34 ) ;
V_41:
F_41 ( V_34 ) ;
return V_38 ;
}
static int F_51 ( struct V_73 * V_74 ,
struct V_31 * V_32 , T_1 V_4 )
{
int V_38 ;
struct V_33 * V_34 ;
struct V_57 * V_77 ;
struct V_62 * V_78 ;
struct V_35 * V_79 ;
struct V_28 V_29 ;
V_34 = F_20 () ;
if ( ! V_34 )
return - V_15 ;
V_29 . V_43 = 0 ;
V_29 . type = V_55 ;
V_29 . V_44 = V_4 ;
V_38 = F_46 ( V_74 , V_32 , V_34 , & V_29 ,
sizeof( * V_77 ) ) ;
if ( V_38 )
goto V_41;
V_79 = V_34 -> V_46 [ 0 ] ;
V_77 = F_23 ( V_79 , V_34 -> V_45 [ 0 ] ,
struct V_57 ) ;
F_52 ( V_79 , V_77 , V_74 -> V_80 ) ;
F_53 ( V_79 , V_77 , 0 ) ;
F_54 ( V_79 , V_77 , 0 ) ;
F_55 ( V_79 , V_77 , 0 ) ;
F_56 ( V_79 , V_77 , 0 ) ;
F_47 ( V_79 ) ;
F_40 ( V_34 ) ;
V_29 . type = V_56 ;
V_38 = F_46 ( V_74 , V_32 , V_34 , & V_29 ,
sizeof( * V_78 ) ) ;
if ( V_38 )
goto V_41;
V_79 = V_34 -> V_46 [ 0 ] ;
V_78 = F_23 ( V_79 , V_34 -> V_45 [ 0 ] ,
struct V_62 ) ;
F_57 ( V_79 , V_78 , 0 ) ;
F_58 ( V_79 , V_78 , 0 ) ;
F_59 ( V_79 , V_78 , 0 ) ;
F_60 ( V_79 , V_78 , 0 ) ;
F_61 ( V_79 , V_78 , 0 ) ;
F_47 ( V_79 ) ;
V_38 = 0 ;
V_41:
F_41 ( V_34 ) ;
return V_38 ;
}
static int F_62 ( struct V_73 * V_74 ,
struct V_31 * V_32 , T_1 V_4 )
{
int V_38 ;
struct V_33 * V_34 ;
struct V_28 V_29 ;
V_34 = F_20 () ;
if ( ! V_34 )
return - V_15 ;
V_29 . V_43 = 0 ;
V_29 . type = V_55 ;
V_29 . V_44 = V_4 ;
V_38 = F_49 ( V_74 , V_32 , & V_29 , V_34 , - 1 , 1 ) ;
if ( V_38 < 0 )
goto V_41;
if ( V_38 > 0 ) {
V_38 = - V_21 ;
goto V_41;
}
V_38 = F_50 ( V_74 , V_32 , V_34 ) ;
if ( V_38 )
goto V_41;
F_40 ( V_34 ) ;
V_29 . type = V_56 ;
V_38 = F_49 ( V_74 , V_32 , & V_29 , V_34 , - 1 , 1 ) ;
if ( V_38 < 0 )
goto V_41;
if ( V_38 > 0 ) {
V_38 = - V_21 ;
goto V_41;
}
V_38 = F_50 ( V_74 , V_32 , V_34 ) ;
V_41:
F_41 ( V_34 ) ;
return V_38 ;
}
static int F_63 ( struct V_73 * V_74 ,
struct V_31 * V_81 , T_1 V_4 ,
T_1 V_39 , T_1 V_64 , T_1 V_65 ,
T_1 V_66 , T_1 V_67 )
{
struct V_33 * V_34 ;
struct V_28 V_29 ;
struct V_35 * V_36 ;
struct V_62 * V_78 ;
int V_38 ;
int V_37 ;
V_29 . V_43 = 0 ;
V_29 . type = V_56 ;
V_29 . V_44 = V_4 ;
V_34 = F_20 () ;
if ( ! V_34 )
return - V_15 ;
V_38 = F_49 ( V_74 , V_81 , & V_29 , V_34 , 0 , 1 ) ;
if ( V_38 > 0 )
V_38 = - V_21 ;
if ( V_38 )
goto V_41;
V_36 = V_34 -> V_46 [ 0 ] ;
V_37 = V_34 -> V_45 [ 0 ] ;
V_78 = F_23 ( V_36 , V_34 -> V_45 [ 0 ] ,
struct V_62 ) ;
F_57 ( V_36 , V_78 , V_39 ) ;
F_58 ( V_36 , V_78 , V_64 ) ;
F_59 ( V_36 , V_78 , V_65 ) ;
F_60 ( V_36 , V_78 , V_66 ) ;
F_61 ( V_36 , V_78 , V_67 ) ;
F_47 ( V_36 ) ;
V_41:
F_41 ( V_34 ) ;
return V_38 ;
}
static int F_64 ( struct V_73 * V_74 ,
struct V_31 * V_81 ,
struct V_1 * V_8 )
{
struct V_33 * V_34 ;
struct V_28 V_29 ;
struct V_35 * V_36 ;
struct V_57 * V_77 ;
int V_38 ;
int V_37 ;
V_29 . V_43 = 0 ;
V_29 . type = V_55 ;
V_29 . V_44 = V_8 -> V_4 ;
V_34 = F_20 () ;
if ( ! V_34 )
return - V_15 ;
V_38 = F_49 ( V_74 , V_81 , & V_29 , V_34 , 0 , 1 ) ;
if ( V_38 > 0 )
V_38 = - V_21 ;
if ( V_38 )
goto V_41;
V_36 = V_34 -> V_46 [ 0 ] ;
V_37 = V_34 -> V_45 [ 0 ] ;
V_77 = F_23 ( V_36 , V_34 -> V_45 [ 0 ] ,
struct V_57 ) ;
F_52 ( V_36 , V_77 , V_74 -> V_80 ) ;
F_53 ( V_36 , V_77 , V_8 -> V_58 ) ;
F_54 ( V_36 , V_77 , V_8 -> V_59 ) ;
F_55 ( V_36 , V_77 , V_8 -> V_60 ) ;
F_56 ( V_36 , V_77 , V_8 -> V_61 ) ;
F_47 ( V_36 ) ;
V_41:
F_41 ( V_34 ) ;
return V_38 ;
}
static int F_65 ( struct V_73 * V_74 ,
struct V_2 * V_3 ,
struct V_31 * V_81 )
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
V_38 = F_49 ( V_74 , V_81 , & V_29 , V_34 , 0 , 1 ) ;
if ( V_38 > 0 )
V_38 = - V_21 ;
if ( V_38 )
goto V_41;
V_36 = V_34 -> V_46 [ 0 ] ;
V_37 = V_34 -> V_45 [ 0 ] ;
V_49 = F_23 ( V_36 , V_37 , struct V_48 ) ;
F_66 ( V_36 , V_49 , V_3 -> V_42 ) ;
F_67 ( V_36 , V_49 , V_74 -> V_80 ) ;
F_47 ( V_36 ) ;
V_41:
F_41 ( V_34 ) ;
return V_38 ;
}
static int F_68 ( struct V_73 * V_74 ,
struct V_31 * V_81 )
{
struct V_33 * V_34 ;
struct V_28 V_29 ;
struct V_35 * V_79 = NULL ;
int V_38 ;
int V_82 = 0 ;
V_34 = F_20 () ;
if ( ! V_34 )
return - V_15 ;
V_34 -> V_83 = 1 ;
V_29 . V_43 = 0 ;
V_29 . V_44 = 0 ;
V_29 . type = 0 ;
while ( 1 ) {
V_38 = F_49 ( V_74 , V_81 , & V_29 , V_34 , - 1 , 1 ) ;
if ( V_38 < 0 )
goto V_41;
V_79 = V_34 -> V_46 [ 0 ] ;
V_82 = F_69 ( V_79 ) ;
if ( ! V_82 )
break;
V_34 -> V_45 [ 0 ] = 0 ;
V_38 = F_70 ( V_74 , V_81 , V_34 , 0 , V_82 ) ;
if ( V_38 )
goto V_41;
F_40 ( V_34 ) ;
}
V_38 = 0 ;
V_41:
V_81 -> V_3 -> V_72 = 0 ;
F_41 ( V_34 ) ;
return V_38 ;
}
int F_71 ( struct V_73 * V_74 ,
struct V_2 * V_3 )
{
struct V_31 * V_32 ;
struct V_33 * V_34 = NULL ;
struct V_48 * V_49 ;
struct V_35 * V_79 ;
struct V_28 V_29 ;
int V_38 = 0 ;
F_72 ( & V_3 -> V_84 ) ;
if ( V_3 -> V_32 ) {
V_3 -> V_72 = 1 ;
F_73 ( & V_3 -> V_84 ) ;
goto V_41;
}
F_73 ( & V_3 -> V_84 ) ;
V_32 = F_74 ( V_74 , V_3 ,
V_85 ) ;
if ( F_28 ( V_32 ) ) {
V_38 = F_29 ( V_32 ) ;
goto V_41;
}
V_34 = F_20 () ;
if ( ! V_34 ) {
V_38 = - V_15 ;
goto V_86;
}
V_29 . V_43 = 0 ;
V_29 . type = V_47 ;
V_29 . V_44 = 0 ;
V_38 = F_46 ( V_74 , V_32 , V_34 , & V_29 ,
sizeof( * V_49 ) ) ;
if ( V_38 )
goto V_87;
V_79 = V_34 -> V_46 [ 0 ] ;
V_49 = F_23 ( V_79 , V_34 -> V_45 [ 0 ] ,
struct V_48 ) ;
F_67 ( V_79 , V_49 , V_74 -> V_80 ) ;
F_75 ( V_79 , V_49 , V_50 ) ;
V_3 -> V_42 = V_71 |
V_53 ;
F_66 ( V_79 , V_49 , V_3 -> V_42 ) ;
F_76 ( V_79 , V_49 , 0 ) ;
F_47 ( V_79 ) ;
F_72 ( & V_3 -> V_84 ) ;
V_3 -> V_32 = V_32 ;
V_3 -> V_72 = 1 ;
F_73 ( & V_3 -> V_84 ) ;
V_87:
F_41 ( V_34 ) ;
V_86:
if ( V_38 ) {
F_77 ( V_32 -> V_9 ) ;
F_77 ( V_32 -> V_88 ) ;
F_14 ( V_32 ) ;
}
V_41:
return V_38 ;
}
int F_78 ( struct V_73 * V_74 ,
struct V_2 * V_3 )
{
struct V_31 * V_89 = V_3 -> V_89 ;
struct V_31 * V_32 ;
int V_38 = 0 ;
F_72 ( & V_3 -> V_84 ) ;
if ( ! V_3 -> V_32 ) {
F_73 ( & V_3 -> V_84 ) ;
return 0 ;
}
V_3 -> V_40 = 0 ;
V_3 -> V_72 = 0 ;
V_32 = V_3 -> V_32 ;
V_3 -> V_32 = NULL ;
F_42 ( V_3 ) ;
F_73 ( & V_3 -> V_84 ) ;
if ( ! V_32 )
return - V_90 ;
V_38 = F_68 ( V_74 , V_32 ) ;
if ( V_38 )
goto V_41;
V_38 = F_79 ( V_74 , V_89 , & V_32 -> V_91 ) ;
if ( V_38 )
goto V_41;
F_11 ( & V_32 -> V_92 ) ;
F_80 ( V_32 -> V_9 ) ;
F_81 ( V_74 , V_89 , V_32 -> V_9 ) ;
F_82 ( V_32 -> V_9 ) ;
F_83 ( V_74 , V_32 , V_32 -> V_9 , 0 , 1 ) ;
F_77 ( V_32 -> V_9 ) ;
F_77 ( V_32 -> V_88 ) ;
F_14 ( V_32 ) ;
V_41:
return V_38 ;
}
int F_84 ( struct V_2 * V_3 )
{
return 0 ;
}
int F_85 ( struct V_73 * V_74 ,
struct V_2 * V_3 , T_1 V_75 , T_1 V_76 )
{
struct V_31 * V_32 ;
int V_38 = 0 ;
V_32 = V_3 -> V_32 ;
if ( ! V_32 )
return - V_90 ;
V_38 = F_45 ( V_74 , V_32 , V_75 , V_76 ) ;
if ( V_38 )
return V_38 ;
V_38 = F_45 ( V_74 , V_32 , V_76 , V_75 ) ;
if ( V_38 ) {
F_48 ( V_74 , V_32 , V_75 , V_76 ) ;
return V_38 ;
}
F_72 ( & V_3 -> V_84 ) ;
V_38 = F_15 ( V_32 -> V_3 , V_75 , V_76 ) ;
F_73 ( & V_3 -> V_84 ) ;
return V_38 ;
}
int F_86 ( struct V_73 * V_74 ,
struct V_2 * V_3 , T_1 V_75 , T_1 V_76 )
{
struct V_31 * V_32 ;
int V_38 = 0 ;
int V_93 ;
V_32 = V_3 -> V_32 ;
if ( ! V_32 )
return - V_90 ;
V_38 = F_48 ( V_74 , V_32 , V_75 , V_76 ) ;
V_93 = F_48 ( V_74 , V_32 , V_76 , V_75 ) ;
if ( V_93 && ! V_38 )
V_38 = V_93 ;
F_72 ( & V_3 -> V_84 ) ;
F_17 ( V_3 , V_75 , V_76 ) ;
F_73 ( & V_3 -> V_84 ) ;
return V_38 ;
}
int F_87 ( struct V_73 * V_74 ,
struct V_2 * V_3 , T_1 V_4 , char * V_94 )
{
struct V_31 * V_32 ;
struct V_1 * V_8 ;
int V_38 = 0 ;
V_32 = V_3 -> V_32 ;
if ( ! V_32 )
return - V_90 ;
V_38 = F_51 ( V_74 , V_32 , V_4 ) ;
F_72 ( & V_3 -> V_84 ) ;
V_8 = F_3 ( V_3 , V_4 ) ;
F_73 ( & V_3 -> V_84 ) ;
if ( F_28 ( V_8 ) )
V_38 = F_29 ( V_8 ) ;
return V_38 ;
}
int F_88 ( struct V_73 * V_74 ,
struct V_2 * V_3 , T_1 V_4 )
{
struct V_31 * V_32 ;
struct V_1 * V_8 ;
int V_38 = 0 ;
V_32 = V_3 -> V_32 ;
if ( ! V_32 )
return - V_90 ;
F_72 ( & V_3 -> V_84 ) ;
V_8 = F_1 ( V_3 , V_4 ) ;
if ( V_8 ) {
if ( ! F_12 ( & V_8 -> V_16 ) || ! F_12 ( & V_8 -> V_17 ) ) {
F_73 ( & V_3 -> V_84 ) ;
return - V_95 ;
}
}
F_73 ( & V_3 -> V_84 ) ;
V_38 = F_62 ( V_74 , V_32 , V_4 ) ;
F_72 ( & V_3 -> V_84 ) ;
F_9 ( V_32 -> V_3 , V_4 ) ;
F_73 ( & V_3 -> V_84 ) ;
return V_38 ;
}
int F_89 ( struct V_73 * V_74 ,
struct V_2 * V_3 , T_1 V_4 ,
struct V_96 * V_97 )
{
struct V_31 * V_32 = V_3 -> V_32 ;
struct V_1 * V_8 ;
int V_38 = 0 ;
if ( ! V_32 )
return - V_90 ;
V_38 = F_63 ( V_74 , V_32 , V_4 ,
V_97 -> V_39 , V_97 -> V_64 ,
V_97 -> V_65 , V_97 -> V_66 ,
V_97 -> V_67 ) ;
if ( V_38 ) {
V_3 -> V_42 |= V_53 ;
F_25 ( V_98 L_6 ,
( unsigned long long ) V_4 ) ;
}
F_72 ( & V_3 -> V_84 ) ;
V_8 = F_1 ( V_3 , V_4 ) ;
if ( ! V_8 ) {
V_38 = - V_21 ;
goto V_99;
}
V_8 -> V_63 = V_97 -> V_39 ;
V_8 -> V_64 = V_97 -> V_64 ;
V_8 -> V_65 = V_97 -> V_65 ;
V_8 -> V_66 = V_97 -> V_66 ;
V_8 -> V_67 = V_97 -> V_67 ;
V_99:
F_73 ( & V_3 -> V_84 ) ;
return V_38 ;
}
static void F_90 ( struct V_2 * V_3 ,
struct V_1 * V_8 )
{
if ( F_12 ( & V_8 -> V_18 ) )
F_91 ( & V_8 -> V_18 , & V_3 -> V_100 ) ;
}
int F_92 ( struct V_73 * V_74 ,
struct V_101 * V_9 ,
struct V_102 * V_103 )
{
struct V_104 * V_105 ;
F_93 ( ! V_74 -> V_106 . V_107 ) ;
V_105 = F_94 ( sizeof( * V_105 ) , V_108 ) ;
if ( ! V_105 )
return - V_15 ;
V_105 -> V_9 = V_9 ;
V_105 -> V_103 = V_103 ;
F_16 ( & V_105 -> V_20 , & V_74 -> V_109 ) ;
return 0 ;
}
int F_95 ( struct V_73 * V_74 ,
struct V_2 * V_3 ,
struct V_101 * V_9 ,
struct V_102 * V_103 )
{
struct V_28 V_110 ;
struct V_31 * V_32 ;
T_1 V_111 ;
struct V_1 * V_8 ;
struct V_112 * V_113 ;
struct V_114 * V_115 = NULL ;
struct V_114 * V_116 = NULL ;
struct V_117 V_118 ;
T_1 V_107 ;
int V_38 = 0 ;
int V_119 ;
if ( ! V_3 -> V_40 )
return 0 ;
F_93 ( ! V_3 -> V_32 ) ;
V_110 . V_43 = V_9 -> V_120 ;
V_110 . V_44 = V_9 -> V_121 ;
V_110 . type = V_122 ;
if ( V_9 -> type == V_123 ||
V_9 -> type == V_124 ) {
struct V_125 * V_126 ;
V_126 = F_96 ( V_9 ) ;
V_111 = V_126 -> V_81 ;
} else if ( V_9 -> type == V_127 ||
V_9 -> type == V_128 ) {
struct V_129 * V_126 ;
V_126 = F_97 ( V_9 ) ;
V_111 = V_126 -> V_81 ;
} else {
F_98 () ;
}
if ( ! F_99 ( V_111 ) ) {
return 0 ;
}
switch ( V_9 -> V_130 ) {
case V_131 :
case V_132 :
V_119 = 1 ;
break;
case V_133 :
V_119 = - 1 ;
break;
case V_134 :
return 0 ;
default:
F_98 () ;
}
V_38 = F_100 ( V_74 , V_3 , V_9 -> V_120 ,
V_119 > 0 ? V_9 -> V_107 - 1 : V_9 -> V_107 , & V_115 ) ;
if ( V_38 < 0 )
return V_38 ;
F_72 ( & V_3 -> V_84 ) ;
V_32 = V_3 -> V_32 ;
if ( ! V_32 )
goto V_99;
V_8 = F_1 ( V_3 , V_111 ) ;
if ( ! V_8 )
goto V_99;
V_116 = F_101 ( V_14 ) ;
if ( ! V_116 ) {
V_38 = - V_15 ;
goto V_99;
}
V_107 = V_3 -> V_135 ;
V_3 -> V_135 += V_115 -> V_136 + 1 ;
F_102 ( & V_118 ) ;
while ( ( V_113 = F_103 ( V_115 , & V_118 ) ) ) {
struct V_112 * V_137 ;
struct V_117 V_138 ;
struct V_1 * V_139 ;
V_139 = F_1 ( V_3 , V_113 -> V_140 ) ;
if ( ! V_139 )
continue;
F_104 ( V_116 ) ;
F_105 ( V_116 , V_139 -> V_4 , ( T_1 ) ( V_141 ) V_139 , V_14 ) ;
F_102 ( & V_138 ) ;
while ( ( V_137 = F_103 ( V_116 , & V_138 ) ) ) {
struct V_19 * V_142 ;
V_139 = (struct V_1 * ) ( V_141 ) V_137 -> V_143 ;
if ( V_139 -> V_144 < V_107 )
V_139 -> V_144 = V_107 + 1 ;
else
++ V_139 -> V_144 ;
F_18 (glist, &qg->groups, next_group) {
F_105 ( V_116 , V_142 -> V_27 -> V_4 ,
( T_1 ) ( V_141 ) V_142 -> V_27 ,
V_14 ) ;
}
}
}
F_104 ( V_116 ) ;
F_105 ( V_116 , V_8 -> V_4 , ( V_141 ) V_8 , V_14 ) ;
F_102 ( & V_118 ) ;
while ( ( V_113 = F_103 ( V_116 , & V_118 ) ) ) {
struct V_1 * V_139 ;
struct V_19 * V_142 ;
V_139 = (struct V_1 * ) ( V_141 ) V_113 -> V_143 ;
if ( V_139 -> V_144 < V_107 ) {
V_139 -> V_58 += V_119 * V_9 -> V_121 ;
V_139 -> V_59 += V_119 * V_9 -> V_121 ;
if ( V_115 -> V_136 == 0 ) {
V_139 -> V_60 += V_119 * V_9 -> V_121 ;
V_139 -> V_61 += V_119 * V_9 -> V_121 ;
}
F_90 ( V_3 , V_139 ) ;
}
F_44 ( V_139 -> V_145 >= V_107 ) ;
V_139 -> V_145 = V_107 ;
F_18 (glist, &qg->groups, next_group) {
F_105 ( V_116 , V_142 -> V_27 -> V_4 ,
( V_141 ) V_142 -> V_27 , V_14 ) ;
}
}
F_102 ( & V_118 ) ;
while ( ( V_113 = F_103 ( V_115 , & V_118 ) ) ) {
struct V_1 * V_139 ;
struct V_112 * V_137 ;
struct V_117 V_138 ;
V_139 = F_1 ( V_3 , V_113 -> V_140 ) ;
if ( ! V_139 )
continue;
F_104 ( V_116 ) ;
F_105 ( V_116 , V_139 -> V_4 , ( V_141 ) V_139 , V_14 ) ;
F_102 ( & V_138 ) ;
while ( ( V_137 = F_103 ( V_116 , & V_138 ) ) ) {
struct V_19 * V_142 ;
V_139 = (struct V_1 * ) ( V_141 ) V_137 -> V_143 ;
if ( V_139 -> V_145 == V_107 )
continue;
if ( V_139 -> V_144 - V_107 == V_115 -> V_136 ) {
V_139 -> V_60 -= V_119 * V_9 -> V_121 ;
V_139 -> V_61 -= V_119 * V_9 -> V_121 ;
F_90 ( V_3 , V_139 ) ;
}
F_18 (glist, &qg->groups, next_group) {
F_105 ( V_116 , V_142 -> V_27 -> V_4 ,
( V_141 ) V_142 -> V_27 ,
V_14 ) ;
}
}
}
V_38 = 0 ;
V_99:
F_73 ( & V_3 -> V_84 ) ;
F_106 ( V_115 ) ;
F_106 ( V_116 ) ;
return V_38 ;
}
int F_107 ( struct V_73 * V_74 ,
struct V_2 * V_3 )
{
struct V_31 * V_32 = V_3 -> V_32 ;
int V_38 = 0 ;
if ( ! V_32 )
goto V_41;
V_3 -> V_40 = V_3 -> V_72 ;
F_72 ( & V_3 -> V_84 ) ;
while ( ! F_12 ( & V_3 -> V_100 ) ) {
struct V_1 * V_8 ;
V_8 = F_13 ( & V_3 -> V_100 ,
struct V_1 , V_18 ) ;
F_108 ( & V_8 -> V_18 ) ;
F_73 ( & V_3 -> V_84 ) ;
V_38 = F_64 ( V_74 , V_32 , V_8 ) ;
if ( V_38 )
V_3 -> V_42 |=
V_53 ;
F_72 ( & V_3 -> V_84 ) ;
}
if ( V_3 -> V_40 )
V_3 -> V_42 |= V_71 ;
else
V_3 -> V_42 &= ~ V_71 ;
F_73 ( & V_3 -> V_84 ) ;
V_38 = F_65 ( V_74 , V_3 , V_32 ) ;
if ( V_38 )
V_3 -> V_42 |= V_53 ;
V_41:
return V_38 ;
}
int F_109 ( struct V_73 * V_74 ,
struct V_2 * V_3 , T_1 V_146 , T_1 V_43 ,
struct F_109 * V_147 )
{
int V_38 = 0 ;
int V_148 ;
T_1 * V_149 ;
struct V_31 * V_32 = V_3 -> V_32 ;
struct V_1 * V_150 ;
struct V_1 * V_151 ;
T_2 V_152 = 0 ;
if ( ! V_3 -> V_40 )
return 0 ;
if ( ! V_32 )
return - V_90 ;
V_38 = F_51 ( V_74 , V_32 , V_43 ) ;
if ( V_38 )
goto V_41;
if ( V_147 && V_147 -> V_39 & V_153 ) {
V_38 = F_63 ( V_74 , V_32 , V_43 ,
V_147 -> V_154 . V_39 ,
V_147 -> V_154 . V_64 ,
V_147 -> V_154 . V_65 ,
V_147 -> V_154 . V_66 ,
V_147 -> V_154 . V_67 ) ;
if ( V_38 )
goto V_41;
}
if ( V_146 ) {
struct V_31 * V_155 ;
struct V_28 V_156 ;
int V_157 ;
V_156 . V_43 = V_146 ;
V_156 . type = V_158 ;
V_156 . V_44 = ( T_1 ) - 1 ;
V_155 = F_110 ( V_3 , & V_156 ) ;
if ( F_28 ( V_155 ) ) {
V_38 = F_29 ( V_155 ) ;
goto V_41;
}
F_111 () ;
V_157 = F_112 ( V_155 -> V_9 ) ;
V_152 = F_113 ( V_155 , V_157 ) ;
F_114 () ;
}
if ( V_147 ) {
V_149 = ( T_1 * ) ( V_147 + 1 ) ;
for ( V_148 = 0 ; V_148 < V_147 -> V_159 ; ++ V_148 ) {
V_38 = F_45 ( V_74 , V_32 ,
V_43 , * V_149 ) ;
if ( V_38 )
goto V_41;
V_38 = F_45 ( V_74 , V_32 ,
* V_149 , V_43 ) ;
if ( V_38 )
goto V_41;
++ V_149 ;
}
}
F_72 ( & V_3 -> V_84 ) ;
V_151 = F_3 ( V_3 , V_43 ) ;
if ( F_28 ( V_151 ) ) {
V_38 = F_29 ( V_151 ) ;
goto V_99;
}
if ( V_146 ) {
V_150 = F_1 ( V_3 , V_146 ) ;
if ( ! V_150 )
goto V_99;
V_151 -> V_58 = V_150 -> V_58 - V_152 ;
V_151 -> V_59 = V_150 -> V_59 - V_152 ;
V_150 -> V_60 = V_152 ;
V_150 -> V_61 = V_152 ;
F_90 ( V_3 , V_151 ) ;
F_90 ( V_3 , V_150 ) ;
}
if ( ! V_147 )
goto V_99;
V_149 = ( T_1 * ) ( V_147 + 1 ) ;
for ( V_148 = 0 ; V_148 < V_147 -> V_159 ; ++ V_148 ) {
V_38 = F_15 ( V_32 -> V_3 , V_43 ,
* V_149 ) ;
if ( V_38 )
goto V_99;
++ V_149 ;
}
for ( V_148 = 0 ; V_148 < V_147 -> V_160 ; ++ V_148 ) {
struct V_1 * V_75 ;
struct V_1 * V_76 ;
V_75 = F_1 ( V_3 , V_149 [ 0 ] ) ;
V_76 = F_1 ( V_3 , V_149 [ 1 ] ) ;
if ( ! V_75 || ! V_76 ) {
V_38 = - V_90 ;
goto V_99;
}
V_76 -> V_58 = V_75 -> V_58 - V_152 ;
V_76 -> V_59 = V_75 -> V_59 - V_152 ;
V_149 += 2 ;
}
for ( V_148 = 0 ; V_148 < V_147 -> V_161 ; ++ V_148 ) {
struct V_1 * V_75 ;
struct V_1 * V_76 ;
V_75 = F_1 ( V_3 , V_149 [ 0 ] ) ;
V_76 = F_1 ( V_3 , V_149 [ 1 ] ) ;
if ( ! V_75 || ! V_76 ) {
V_38 = - V_90 ;
goto V_99;
}
V_76 -> V_60 = V_75 -> V_60 + V_152 ;
V_76 -> V_61 = V_75 -> V_61 + V_152 ;
V_149 += 2 ;
}
V_99:
F_73 ( & V_3 -> V_84 ) ;
V_41:
return V_38 ;
}
int F_115 ( struct V_31 * V_81 , T_1 V_121 )
{
struct V_31 * V_32 ;
struct V_1 * V_8 ;
struct V_2 * V_3 = V_81 -> V_3 ;
T_1 V_111 = V_81 -> V_91 . V_43 ;
int V_38 = 0 ;
struct V_114 * V_114 = NULL ;
struct V_112 * V_113 ;
struct V_117 V_118 ;
if ( ! F_99 ( V_111 ) )
return 0 ;
if ( V_121 == 0 )
return 0 ;
F_72 ( & V_3 -> V_84 ) ;
V_32 = V_3 -> V_32 ;
if ( ! V_32 )
goto V_41;
V_8 = F_1 ( V_3 , V_111 ) ;
if ( ! V_8 )
goto V_41;
V_114 = F_101 ( V_14 ) ;
if ( ! V_114 ) {
V_38 = - V_15 ;
goto V_41;
}
F_105 ( V_114 , V_8 -> V_4 , ( V_141 ) V_8 , V_14 ) ;
F_102 ( & V_118 ) ;
while ( ( V_113 = F_103 ( V_114 , & V_118 ) ) ) {
struct V_1 * V_139 ;
struct V_19 * V_142 ;
V_139 = (struct V_1 * ) ( V_141 ) V_113 -> V_143 ;
if ( ( V_139 -> V_63 & V_162 ) &&
V_139 -> V_163 + V_139 -> V_58 + V_121 >
V_139 -> V_64 ) {
V_38 = - V_164 ;
goto V_41;
}
if ( ( V_139 -> V_63 & V_165 ) &&
V_139 -> V_163 + V_139 -> V_60 + V_121 >
V_139 -> V_65 ) {
V_38 = - V_164 ;
goto V_41;
}
F_18 (glist, &qg->groups, next_group) {
F_105 ( V_114 , V_142 -> V_27 -> V_4 ,
( V_141 ) V_142 -> V_27 , V_14 ) ;
}
}
F_102 ( & V_118 ) ;
while ( ( V_113 = F_103 ( V_114 , & V_118 ) ) ) {
struct V_1 * V_139 ;
V_139 = (struct V_1 * ) ( V_141 ) V_113 -> V_143 ;
V_139 -> V_163 += V_121 ;
}
V_41:
F_73 ( & V_3 -> V_84 ) ;
F_106 ( V_114 ) ;
return V_38 ;
}
void F_116 ( struct V_31 * V_81 , T_1 V_121 )
{
struct V_31 * V_32 ;
struct V_1 * V_8 ;
struct V_2 * V_3 = V_81 -> V_3 ;
struct V_114 * V_114 = NULL ;
struct V_112 * V_113 ;
struct V_117 V_118 ;
T_1 V_111 = V_81 -> V_91 . V_43 ;
if ( ! F_99 ( V_111 ) )
return;
if ( V_121 == 0 )
return;
F_72 ( & V_3 -> V_84 ) ;
V_32 = V_3 -> V_32 ;
if ( ! V_32 )
goto V_41;
V_8 = F_1 ( V_3 , V_111 ) ;
if ( ! V_8 )
goto V_41;
V_114 = F_101 ( V_14 ) ;
if ( ! V_114 ) {
F_117 ( V_3 , - V_15 ) ;
goto V_41;
}
F_105 ( V_114 , V_8 -> V_4 , ( V_141 ) V_8 , V_14 ) ;
F_102 ( & V_118 ) ;
while ( ( V_113 = F_103 ( V_114 , & V_118 ) ) ) {
struct V_1 * V_139 ;
struct V_19 * V_142 ;
V_139 = (struct V_1 * ) ( V_141 ) V_113 -> V_143 ;
V_139 -> V_163 -= V_121 ;
F_18 (glist, &qg->groups, next_group) {
F_105 ( V_114 , V_142 -> V_27 -> V_4 ,
( V_141 ) V_142 -> V_27 , V_14 ) ;
}
}
V_41:
F_73 ( & V_3 -> V_84 ) ;
F_106 ( V_114 ) ;
}
void F_118 ( struct V_73 * V_74 )
{
if ( F_12 ( & V_74 -> V_109 ) && ! V_74 -> V_106 . V_107 )
return;
F_25 ( V_51 L_7 ,
V_74 , F_12 ( & V_74 -> V_109 ) ? L_8 : L_9 ,
V_74 -> V_106 . V_107 ) ;
F_98 () ;
}
