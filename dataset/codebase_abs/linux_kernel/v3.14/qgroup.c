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
int F_20 ( struct V_2 * V_3 )
{
struct V_28 V_29 ;
struct V_28 V_30 ;
struct V_31 * V_32 = V_3 -> V_32 ;
struct V_33 * V_34 = NULL ;
struct V_35 * V_36 ;
int V_37 ;
int V_38 = 0 ;
T_1 V_39 = 0 ;
T_1 V_40 = 0 ;
if ( ! V_3 -> V_41 )
return 0 ;
V_3 -> V_42 = F_21 ( V_43 ) ;
if ( ! V_3 -> V_42 ) {
V_38 = - V_15 ;
goto V_44;
}
V_34 = F_22 () ;
if ( ! V_34 ) {
V_38 = - V_15 ;
goto V_44;
}
V_3 -> V_45 = 0 ;
V_29 . V_46 = 0 ;
V_29 . type = 0 ;
V_29 . V_47 = 0 ;
V_38 = F_23 ( V_32 , & V_29 , V_34 , 1 , 1 ) ;
if ( V_38 )
goto V_44;
while ( 1 ) {
struct V_1 * V_8 ;
V_37 = V_34 -> V_48 [ 0 ] ;
V_36 = V_34 -> V_49 [ 0 ] ;
F_24 ( V_36 , & V_30 , V_37 ) ;
if ( V_30 . type == V_50 ) {
struct V_51 * V_52 ;
V_52 = F_25 ( V_36 , V_37 ,
struct V_51 ) ;
if ( F_26 ( V_36 , V_52 ) !=
V_53 ) {
F_27 ( V_3 ,
L_1 ) ;
goto V_44;
}
if ( F_28 ( V_36 , V_52 ) !=
V_3 -> V_54 ) {
V_39 |= V_55 ;
F_27 ( V_3 ,
L_2
L_3 ) ;
}
V_3 -> V_45 = F_29 ( V_36 ,
V_52 ) ;
V_40 = F_30 ( V_36 , V_52 ) ;
goto V_56;
}
if ( V_30 . type != V_57 &&
V_30 . type != V_58 )
goto V_56;
V_8 = F_1 ( V_3 , V_30 . V_47 ) ;
if ( ( V_8 && V_30 . type == V_57 ) ||
( ! V_8 && V_30 . type == V_58 ) ) {
F_27 ( V_3 , L_4 ) ;
V_39 |= V_55 ;
}
if ( ! V_8 ) {
V_8 = F_3 ( V_3 , V_30 . V_47 ) ;
if ( F_31 ( V_8 ) ) {
V_38 = F_32 ( V_8 ) ;
goto V_44;
}
}
switch ( V_30 . type ) {
case V_57 : {
struct V_59 * V_52 ;
V_52 = F_25 ( V_36 , V_37 ,
struct V_59 ) ;
V_8 -> V_60 = F_33 ( V_36 , V_52 ) ;
V_8 -> V_61 = F_34 ( V_36 , V_52 ) ;
V_8 -> V_62 = F_35 ( V_36 , V_52 ) ;
V_8 -> V_63 = F_36 ( V_36 , V_52 ) ;
break;
}
case V_58 : {
struct V_64 * V_52 ;
V_52 = F_25 ( V_36 , V_37 ,
struct V_64 ) ;
V_8 -> V_65 = F_37 ( V_36 , V_52 ) ;
V_8 -> V_66 = F_38 ( V_36 , V_52 ) ;
V_8 -> V_67 = F_39 ( V_36 , V_52 ) ;
V_8 -> V_68 = F_40 ( V_36 , V_52 ) ;
V_8 -> V_69 = F_41 ( V_36 , V_52 ) ;
break;
}
}
V_56:
V_38 = F_42 ( V_32 , V_34 ) ;
if ( V_38 < 0 )
goto V_44;
if ( V_38 )
break;
}
F_43 ( V_34 ) ;
V_29 . V_46 = 0 ;
V_29 . type = V_70 ;
V_29 . V_47 = 0 ;
V_38 = F_23 ( V_32 , & V_29 , V_34 , 1 , 0 ) ;
if ( V_38 )
goto V_44;
while ( 1 ) {
V_37 = V_34 -> V_48 [ 0 ] ;
V_36 = V_34 -> V_49 [ 0 ] ;
F_24 ( V_36 , & V_30 , V_37 ) ;
if ( V_30 . type != V_70 )
goto V_71;
if ( V_30 . V_46 > V_30 . V_47 ) {
goto V_71;
}
V_38 = F_16 ( V_3 , V_30 . V_46 ,
V_30 . V_47 ) ;
if ( V_38 == - V_23 ) {
F_44 ( V_3 ,
L_5 ,
V_30 . V_46 , V_30 . V_47 ) ;
V_38 = 0 ;
}
if ( V_38 )
goto V_44;
V_71:
V_38 = F_42 ( V_32 , V_34 ) ;
if ( V_38 < 0 )
goto V_44;
if ( V_38 )
break;
}
V_44:
V_3 -> V_45 |= V_39 ;
if ( ! ( V_3 -> V_45 & V_72 ) ) {
V_3 -> V_41 = 0 ;
V_3 -> V_73 = 0 ;
} else if ( V_3 -> V_45 & V_74 &&
V_38 >= 0 ) {
V_38 = F_45 ( V_3 , V_40 , 0 ) ;
}
F_46 ( V_34 ) ;
if ( V_38 < 0 ) {
F_47 ( V_3 -> V_42 ) ;
V_3 -> V_42 = NULL ;
V_3 -> V_45 &= ~ V_74 ;
}
return V_38 < 0 ? V_38 : 0 ;
}
void F_48 ( struct V_2 * V_3 )
{
struct V_5 * V_6 ;
struct V_1 * V_8 ;
while ( ( V_6 = F_49 ( & V_3 -> V_7 ) ) ) {
V_8 = F_2 ( V_6 , struct V_1 , V_9 ) ;
F_15 ( V_6 , & V_3 -> V_7 ) ;
F_9 ( V_8 ) ;
}
F_47 ( V_3 -> V_42 ) ;
V_3 -> V_42 = NULL ;
}
static int F_50 ( struct V_75 * V_76 ,
struct V_31 * V_32 ,
T_1 V_77 , T_1 V_78 )
{
int V_38 ;
struct V_33 * V_34 ;
struct V_28 V_29 ;
V_34 = F_22 () ;
if ( ! V_34 )
return - V_15 ;
V_29 . V_46 = V_77 ;
V_29 . type = V_70 ;
V_29 . V_47 = V_78 ;
V_38 = F_51 ( V_76 , V_32 , V_34 , & V_29 , 0 ) ;
F_52 ( V_34 -> V_49 [ 0 ] ) ;
F_46 ( V_34 ) ;
return V_38 ;
}
static int F_53 ( struct V_75 * V_76 ,
struct V_31 * V_32 ,
T_1 V_77 , T_1 V_78 )
{
int V_38 ;
struct V_33 * V_34 ;
struct V_28 V_29 ;
V_34 = F_22 () ;
if ( ! V_34 )
return - V_15 ;
V_29 . V_46 = V_77 ;
V_29 . type = V_70 ;
V_29 . V_47 = V_78 ;
V_38 = F_54 ( V_76 , V_32 , & V_29 , V_34 , - 1 , 1 ) ;
if ( V_38 < 0 )
goto V_44;
if ( V_38 > 0 ) {
V_38 = - V_23 ;
goto V_44;
}
V_38 = F_55 ( V_76 , V_32 , V_34 ) ;
V_44:
F_46 ( V_34 ) ;
return V_38 ;
}
static int F_56 ( struct V_75 * V_76 ,
struct V_31 * V_32 , T_1 V_4 )
{
int V_38 ;
struct V_33 * V_34 ;
struct V_59 * V_79 ;
struct V_64 * V_80 ;
struct V_35 * V_81 ;
struct V_28 V_29 ;
V_34 = F_22 () ;
if ( ! V_34 )
return - V_15 ;
V_29 . V_46 = 0 ;
V_29 . type = V_57 ;
V_29 . V_47 = V_4 ;
V_38 = F_51 ( V_76 , V_32 , V_34 , & V_29 ,
sizeof( * V_79 ) ) ;
if ( V_38 )
goto V_44;
V_81 = V_34 -> V_49 [ 0 ] ;
V_79 = F_25 ( V_81 , V_34 -> V_48 [ 0 ] ,
struct V_59 ) ;
F_57 ( V_81 , V_79 , V_76 -> V_82 ) ;
F_58 ( V_81 , V_79 , 0 ) ;
F_59 ( V_81 , V_79 , 0 ) ;
F_60 ( V_81 , V_79 , 0 ) ;
F_61 ( V_81 , V_79 , 0 ) ;
F_52 ( V_81 ) ;
F_43 ( V_34 ) ;
V_29 . type = V_58 ;
V_38 = F_51 ( V_76 , V_32 , V_34 , & V_29 ,
sizeof( * V_80 ) ) ;
if ( V_38 )
goto V_44;
V_81 = V_34 -> V_49 [ 0 ] ;
V_80 = F_25 ( V_81 , V_34 -> V_48 [ 0 ] ,
struct V_64 ) ;
F_62 ( V_81 , V_80 , 0 ) ;
F_63 ( V_81 , V_80 , 0 ) ;
F_64 ( V_81 , V_80 , 0 ) ;
F_65 ( V_81 , V_80 , 0 ) ;
F_66 ( V_81 , V_80 , 0 ) ;
F_52 ( V_81 ) ;
V_38 = 0 ;
V_44:
F_46 ( V_34 ) ;
return V_38 ;
}
static int F_67 ( struct V_75 * V_76 ,
struct V_31 * V_32 , T_1 V_4 )
{
int V_38 ;
struct V_33 * V_34 ;
struct V_28 V_29 ;
V_34 = F_22 () ;
if ( ! V_34 )
return - V_15 ;
V_29 . V_46 = 0 ;
V_29 . type = V_57 ;
V_29 . V_47 = V_4 ;
V_38 = F_54 ( V_76 , V_32 , & V_29 , V_34 , - 1 , 1 ) ;
if ( V_38 < 0 )
goto V_44;
if ( V_38 > 0 ) {
V_38 = - V_23 ;
goto V_44;
}
V_38 = F_55 ( V_76 , V_32 , V_34 ) ;
if ( V_38 )
goto V_44;
F_43 ( V_34 ) ;
V_29 . type = V_58 ;
V_38 = F_54 ( V_76 , V_32 , & V_29 , V_34 , - 1 , 1 ) ;
if ( V_38 < 0 )
goto V_44;
if ( V_38 > 0 ) {
V_38 = - V_23 ;
goto V_44;
}
V_38 = F_55 ( V_76 , V_32 , V_34 ) ;
V_44:
F_46 ( V_34 ) ;
return V_38 ;
}
static int F_68 ( struct V_75 * V_76 ,
struct V_31 * V_83 , T_1 V_4 ,
T_1 V_39 , T_1 V_66 , T_1 V_67 ,
T_1 V_68 , T_1 V_69 )
{
struct V_33 * V_34 ;
struct V_28 V_29 ;
struct V_35 * V_36 ;
struct V_64 * V_80 ;
int V_38 ;
int V_37 ;
V_29 . V_46 = 0 ;
V_29 . type = V_58 ;
V_29 . V_47 = V_4 ;
V_34 = F_22 () ;
if ( ! V_34 )
return - V_15 ;
V_38 = F_54 ( V_76 , V_83 , & V_29 , V_34 , 0 , 1 ) ;
if ( V_38 > 0 )
V_38 = - V_23 ;
if ( V_38 )
goto V_44;
V_36 = V_34 -> V_49 [ 0 ] ;
V_37 = V_34 -> V_48 [ 0 ] ;
V_80 = F_25 ( V_36 , V_37 , struct V_64 ) ;
F_62 ( V_36 , V_80 , V_39 ) ;
F_63 ( V_36 , V_80 , V_66 ) ;
F_64 ( V_36 , V_80 , V_67 ) ;
F_65 ( V_36 , V_80 , V_68 ) ;
F_66 ( V_36 , V_80 , V_69 ) ;
F_52 ( V_36 ) ;
V_44:
F_46 ( V_34 ) ;
return V_38 ;
}
static int F_69 ( struct V_75 * V_76 ,
struct V_31 * V_83 ,
struct V_1 * V_8 )
{
struct V_33 * V_34 ;
struct V_28 V_29 ;
struct V_35 * V_36 ;
struct V_59 * V_79 ;
int V_38 ;
int V_37 ;
V_29 . V_46 = 0 ;
V_29 . type = V_57 ;
V_29 . V_47 = V_8 -> V_4 ;
V_34 = F_22 () ;
if ( ! V_34 )
return - V_15 ;
V_38 = F_54 ( V_76 , V_83 , & V_29 , V_34 , 0 , 1 ) ;
if ( V_38 > 0 )
V_38 = - V_23 ;
if ( V_38 )
goto V_44;
V_36 = V_34 -> V_49 [ 0 ] ;
V_37 = V_34 -> V_48 [ 0 ] ;
V_79 = F_25 ( V_36 , V_37 , struct V_59 ) ;
F_57 ( V_36 , V_79 , V_76 -> V_82 ) ;
F_58 ( V_36 , V_79 , V_8 -> V_60 ) ;
F_59 ( V_36 , V_79 , V_8 -> V_61 ) ;
F_60 ( V_36 , V_79 , V_8 -> V_62 ) ;
F_61 ( V_36 , V_79 , V_8 -> V_63 ) ;
F_52 ( V_36 ) ;
V_44:
F_46 ( V_34 ) ;
return V_38 ;
}
static int F_70 ( struct V_75 * V_76 ,
struct V_2 * V_3 ,
struct V_31 * V_83 )
{
struct V_33 * V_34 ;
struct V_28 V_29 ;
struct V_35 * V_36 ;
struct V_51 * V_52 ;
int V_38 ;
int V_37 ;
V_29 . V_46 = 0 ;
V_29 . type = V_50 ;
V_29 . V_47 = 0 ;
V_34 = F_22 () ;
if ( ! V_34 )
return - V_15 ;
V_38 = F_54 ( V_76 , V_83 , & V_29 , V_34 , 0 , 1 ) ;
if ( V_38 > 0 )
V_38 = - V_23 ;
if ( V_38 )
goto V_44;
V_36 = V_34 -> V_49 [ 0 ] ;
V_37 = V_34 -> V_48 [ 0 ] ;
V_52 = F_25 ( V_36 , V_37 , struct V_51 ) ;
F_71 ( V_36 , V_52 , V_3 -> V_45 ) ;
F_72 ( V_36 , V_52 , V_76 -> V_82 ) ;
F_73 ( V_36 , V_52 ,
V_3 -> V_84 . V_46 ) ;
F_52 ( V_36 ) ;
V_44:
F_46 ( V_34 ) ;
return V_38 ;
}
static int F_74 ( struct V_75 * V_76 ,
struct V_31 * V_83 )
{
struct V_33 * V_34 ;
struct V_28 V_29 ;
struct V_35 * V_81 = NULL ;
int V_38 ;
int V_85 = 0 ;
V_34 = F_22 () ;
if ( ! V_34 )
return - V_15 ;
V_34 -> V_86 = 1 ;
V_29 . V_46 = 0 ;
V_29 . V_47 = 0 ;
V_29 . type = 0 ;
while ( 1 ) {
V_38 = F_54 ( V_76 , V_83 , & V_29 , V_34 , - 1 , 1 ) ;
if ( V_38 < 0 )
goto V_44;
V_81 = V_34 -> V_49 [ 0 ] ;
V_85 = F_75 ( V_81 ) ;
if ( ! V_85 )
break;
V_34 -> V_48 [ 0 ] = 0 ;
V_38 = F_76 ( V_76 , V_83 , V_34 , 0 , V_85 ) ;
if ( V_38 )
goto V_44;
F_43 ( V_34 ) ;
}
V_38 = 0 ;
V_44:
V_83 -> V_3 -> V_73 = 0 ;
F_46 ( V_34 ) ;
return V_38 ;
}
int F_77 ( struct V_75 * V_76 ,
struct V_2 * V_3 )
{
struct V_31 * V_32 ;
struct V_31 * V_87 = V_3 -> V_87 ;
struct V_33 * V_34 = NULL ;
struct V_51 * V_52 ;
struct V_35 * V_81 ;
struct V_28 V_29 ;
struct V_28 V_30 ;
struct V_1 * V_8 = NULL ;
int V_38 = 0 ;
int V_37 ;
F_78 ( & V_3 -> V_88 ) ;
if ( V_3 -> V_32 ) {
V_3 -> V_73 = 1 ;
goto V_44;
}
V_3 -> V_42 = F_21 ( V_43 ) ;
if ( ! V_3 -> V_42 ) {
V_38 = - V_15 ;
goto V_44;
}
V_32 = F_79 ( V_76 , V_3 ,
V_89 ) ;
if ( F_31 ( V_32 ) ) {
V_38 = F_32 ( V_32 ) ;
goto V_44;
}
V_34 = F_22 () ;
if ( ! V_34 ) {
V_38 = - V_15 ;
goto V_90;
}
V_29 . V_46 = 0 ;
V_29 . type = V_50 ;
V_29 . V_47 = 0 ;
V_38 = F_51 ( V_76 , V_32 , V_34 , & V_29 ,
sizeof( * V_52 ) ) ;
if ( V_38 )
goto V_91;
V_81 = V_34 -> V_49 [ 0 ] ;
V_52 = F_25 ( V_81 , V_34 -> V_48 [ 0 ] ,
struct V_51 ) ;
F_72 ( V_81 , V_52 , V_76 -> V_82 ) ;
F_80 ( V_81 , V_52 , V_53 ) ;
V_3 -> V_45 = V_72 |
V_55 ;
F_71 ( V_81 , V_52 , V_3 -> V_45 ) ;
F_73 ( V_81 , V_52 , 0 ) ;
F_52 ( V_81 ) ;
V_29 . V_46 = 0 ;
V_29 . type = V_92 ;
V_29 . V_47 = 0 ;
F_43 ( V_34 ) ;
V_38 = F_23 ( V_87 , & V_29 , V_34 , 1 , 0 ) ;
if ( V_38 > 0 )
goto V_93;
if ( V_38 < 0 )
goto V_91;
while ( 1 ) {
V_37 = V_34 -> V_48 [ 0 ] ;
V_81 = V_34 -> V_49 [ 0 ] ;
F_24 ( V_81 , & V_30 , V_37 ) ;
if ( V_30 . type == V_92 ) {
V_38 = F_56 ( V_76 , V_32 ,
V_30 . V_47 ) ;
if ( V_38 )
goto V_91;
V_8 = F_3 ( V_3 , V_30 . V_47 ) ;
if ( F_31 ( V_8 ) ) {
V_38 = F_32 ( V_8 ) ;
goto V_91;
}
}
V_38 = F_42 ( V_87 , V_34 ) ;
if ( V_38 < 0 )
goto V_91;
if ( V_38 )
break;
}
V_93:
F_43 ( V_34 ) ;
V_38 = F_56 ( V_76 , V_32 , V_94 ) ;
if ( V_38 )
goto V_91;
V_8 = F_3 ( V_3 , V_94 ) ;
if ( F_31 ( V_8 ) ) {
V_38 = F_32 ( V_8 ) ;
goto V_91;
}
F_81 ( & V_3 -> V_95 ) ;
V_3 -> V_32 = V_32 ;
V_3 -> V_73 = 1 ;
F_82 ( & V_3 -> V_95 ) ;
V_91:
F_46 ( V_34 ) ;
V_90:
if ( V_38 ) {
F_83 ( V_32 -> V_9 ) ;
F_83 ( V_32 -> V_96 ) ;
F_13 ( V_32 ) ;
}
V_44:
if ( V_38 ) {
F_47 ( V_3 -> V_42 ) ;
V_3 -> V_42 = NULL ;
}
F_84 ( & V_3 -> V_88 ) ;
return V_38 ;
}
int F_85 ( struct V_75 * V_76 ,
struct V_2 * V_3 )
{
struct V_31 * V_87 = V_3 -> V_87 ;
struct V_31 * V_32 ;
int V_38 = 0 ;
F_78 ( & V_3 -> V_88 ) ;
if ( ! V_3 -> V_32 )
goto V_44;
F_81 ( & V_3 -> V_95 ) ;
V_3 -> V_41 = 0 ;
V_3 -> V_73 = 0 ;
V_32 = V_3 -> V_32 ;
V_3 -> V_32 = NULL ;
F_82 ( & V_3 -> V_95 ) ;
F_48 ( V_3 ) ;
V_38 = F_74 ( V_76 , V_32 ) ;
if ( V_38 )
goto V_44;
V_38 = F_86 ( V_76 , V_87 , & V_32 -> V_97 ) ;
if ( V_38 )
goto V_44;
F_10 ( & V_32 -> V_98 ) ;
F_87 ( V_32 -> V_9 ) ;
F_88 ( V_76 , V_87 , V_32 -> V_9 ) ;
F_89 ( V_32 -> V_9 ) ;
F_90 ( V_76 , V_32 , V_32 -> V_9 , 0 , 1 ) ;
F_83 ( V_32 -> V_9 ) ;
F_83 ( V_32 -> V_96 ) ;
F_13 ( V_32 ) ;
V_44:
F_84 ( & V_3 -> V_88 ) ;
return V_38 ;
}
static void F_91 ( struct V_2 * V_3 ,
struct V_1 * V_8 )
{
if ( F_11 ( & V_8 -> V_18 ) )
F_92 ( & V_8 -> V_18 , & V_3 -> V_99 ) ;
}
int F_93 ( struct V_75 * V_76 ,
struct V_2 * V_3 , T_1 V_77 , T_1 V_78 )
{
struct V_31 * V_32 ;
struct V_1 * V_13 ;
struct V_1 * V_26 ;
struct V_19 * V_20 ;
int V_38 = 0 ;
F_78 ( & V_3 -> V_88 ) ;
V_32 = V_3 -> V_32 ;
if ( ! V_32 ) {
V_38 = - V_100 ;
goto V_44;
}
V_26 = F_1 ( V_3 , V_77 ) ;
V_13 = F_1 ( V_3 , V_78 ) ;
if ( ! V_26 || ! V_13 ) {
V_38 = - V_100 ;
goto V_44;
}
F_19 (list, &member->groups, next_group) {
if ( V_20 -> V_27 == V_13 ) {
V_38 = - V_101 ;
goto V_44;
}
}
V_38 = F_50 ( V_76 , V_32 , V_77 , V_78 ) ;
if ( V_38 )
goto V_44;
V_38 = F_50 ( V_76 , V_32 , V_78 , V_77 ) ;
if ( V_38 ) {
F_53 ( V_76 , V_32 , V_77 , V_78 ) ;
goto V_44;
}
F_81 ( & V_3 -> V_95 ) ;
V_38 = F_16 ( V_32 -> V_3 , V_77 , V_78 ) ;
F_82 ( & V_3 -> V_95 ) ;
V_44:
F_84 ( & V_3 -> V_88 ) ;
return V_38 ;
}
int F_94 ( struct V_75 * V_76 ,
struct V_2 * V_3 , T_1 V_77 , T_1 V_78 )
{
struct V_31 * V_32 ;
struct V_1 * V_13 ;
struct V_1 * V_26 ;
struct V_19 * V_20 ;
int V_38 = 0 ;
int V_102 ;
F_78 ( & V_3 -> V_88 ) ;
V_32 = V_3 -> V_32 ;
if ( ! V_32 ) {
V_38 = - V_100 ;
goto V_44;
}
V_26 = F_1 ( V_3 , V_77 ) ;
V_13 = F_1 ( V_3 , V_78 ) ;
if ( ! V_26 || ! V_13 ) {
V_38 = - V_100 ;
goto V_44;
}
F_19 (list, &member->groups, next_group) {
if ( V_20 -> V_27 == V_13 )
goto V_103;
}
V_38 = - V_23 ;
goto V_44;
V_103:
V_38 = F_53 ( V_76 , V_32 , V_77 , V_78 ) ;
V_102 = F_53 ( V_76 , V_32 , V_78 , V_77 ) ;
if ( V_102 && ! V_38 )
V_38 = V_102 ;
F_81 ( & V_3 -> V_95 ) ;
F_18 ( V_3 , V_77 , V_78 ) ;
F_82 ( & V_3 -> V_95 ) ;
V_44:
F_84 ( & V_3 -> V_88 ) ;
return V_38 ;
}
int F_95 ( struct V_75 * V_76 ,
struct V_2 * V_3 , T_1 V_4 , char * V_104 )
{
struct V_31 * V_32 ;
struct V_1 * V_8 ;
int V_38 = 0 ;
F_78 ( & V_3 -> V_88 ) ;
V_32 = V_3 -> V_32 ;
if ( ! V_32 ) {
V_38 = - V_100 ;
goto V_44;
}
V_8 = F_1 ( V_3 , V_4 ) ;
if ( V_8 ) {
V_38 = - V_101 ;
goto V_44;
}
V_38 = F_56 ( V_76 , V_32 , V_4 ) ;
if ( V_38 )
goto V_44;
F_81 ( & V_3 -> V_95 ) ;
V_8 = F_3 ( V_3 , V_4 ) ;
F_82 ( & V_3 -> V_95 ) ;
if ( F_31 ( V_8 ) )
V_38 = F_32 ( V_8 ) ;
V_44:
F_84 ( & V_3 -> V_88 ) ;
return V_38 ;
}
int F_96 ( struct V_75 * V_76 ,
struct V_2 * V_3 , T_1 V_4 )
{
struct V_31 * V_32 ;
struct V_1 * V_8 ;
int V_38 = 0 ;
F_78 ( & V_3 -> V_88 ) ;
V_32 = V_3 -> V_32 ;
if ( ! V_32 ) {
V_38 = - V_100 ;
goto V_44;
}
V_8 = F_1 ( V_3 , V_4 ) ;
if ( ! V_8 ) {
V_38 = - V_23 ;
goto V_44;
} else {
if ( ! F_11 ( & V_8 -> V_16 ) ||
! F_11 ( & V_8 -> V_17 ) ) {
V_38 = - V_105 ;
goto V_44;
}
}
V_38 = F_67 ( V_76 , V_32 , V_4 ) ;
F_81 ( & V_3 -> V_95 ) ;
F_14 ( V_32 -> V_3 , V_4 ) ;
F_82 ( & V_3 -> V_95 ) ;
V_44:
F_84 ( & V_3 -> V_88 ) ;
return V_38 ;
}
int F_97 ( struct V_75 * V_76 ,
struct V_2 * V_3 , T_1 V_4 ,
struct V_106 * V_107 )
{
struct V_31 * V_32 ;
struct V_1 * V_8 ;
int V_38 = 0 ;
F_78 ( & V_3 -> V_88 ) ;
V_32 = V_3 -> V_32 ;
if ( ! V_32 ) {
V_38 = - V_100 ;
goto V_44;
}
V_8 = F_1 ( V_3 , V_4 ) ;
if ( ! V_8 ) {
V_38 = - V_23 ;
goto V_44;
}
V_38 = F_68 ( V_76 , V_32 , V_4 ,
V_107 -> V_39 , V_107 -> V_66 ,
V_107 -> V_67 , V_107 -> V_68 ,
V_107 -> V_69 ) ;
if ( V_38 ) {
V_3 -> V_45 |= V_55 ;
F_98 ( V_3 , L_6 ,
V_4 ) ;
}
F_81 ( & V_3 -> V_95 ) ;
V_8 -> V_65 = V_107 -> V_39 ;
V_8 -> V_66 = V_107 -> V_66 ;
V_8 -> V_67 = V_107 -> V_67 ;
V_8 -> V_68 = V_107 -> V_68 ;
V_8 -> V_69 = V_107 -> V_69 ;
F_82 ( & V_3 -> V_95 ) ;
V_44:
F_84 ( & V_3 -> V_88 ) ;
return V_38 ;
}
int F_99 ( struct V_75 * V_76 ,
struct V_108 * V_9 ,
struct V_109 * V_110 )
{
struct V_111 * V_112 ;
F_100 ( ! V_76 -> V_113 . V_114 ) ;
V_112 = F_101 ( sizeof( * V_112 ) , V_43 ) ;
if ( ! V_112 )
return - V_15 ;
V_112 -> V_9 = V_9 ;
V_112 -> V_110 = V_110 ;
F_17 ( & V_112 -> V_20 , & V_76 -> V_115 ) ;
return 0 ;
}
static int F_102 ( struct V_2 * V_3 ,
struct V_116 * V_117 , struct V_116 * V_118 ,
T_1 V_114 )
{
struct V_119 * V_120 ;
struct V_121 V_122 ;
struct V_119 * V_123 ;
struct V_121 V_124 ;
struct V_1 * V_125 ;
int V_38 ;
F_103 ( & V_122 ) ;
while ( ( V_120 = F_104 ( V_117 , & V_122 ) ) ) {
V_125 = F_1 ( V_3 , V_120 -> V_126 ) ;
if ( ! V_125 )
continue;
F_105 ( V_118 ) ;
V_38 = F_106 ( V_118 , V_125 -> V_4 ,
( T_1 ) ( V_127 ) V_125 , V_14 ) ;
if ( V_38 < 0 )
return V_38 ;
F_103 ( & V_124 ) ;
while ( ( V_123 = F_104 ( V_118 , & V_124 ) ) ) {
struct V_19 * V_128 ;
V_125 = (struct V_1 * ) ( V_127 ) V_123 -> V_129 ;
if ( V_125 -> V_130 < V_114 )
V_125 -> V_130 = V_114 + 1 ;
else
++ V_125 -> V_130 ;
F_19 (glist, &qg->groups, next_group) {
V_38 = F_106 ( V_118 , V_128 -> V_27 -> V_4 ,
( T_1 ) ( V_127 ) V_128 -> V_27 ,
V_14 ) ;
if ( V_38 < 0 )
return V_38 ;
}
}
}
return 0 ;
}
static int F_107 ( struct V_2 * V_3 ,
struct V_116 * V_117 , struct V_116 * V_118 ,
T_1 V_114 , int V_131 , T_1 V_132 ,
struct V_1 * V_8 )
{
struct V_119 * V_120 ;
struct V_121 V_122 ;
struct V_1 * V_125 ;
struct V_19 * V_128 ;
int V_38 ;
F_105 ( V_118 ) ;
V_38 = F_106 ( V_118 , V_8 -> V_4 , ( V_127 ) V_8 , V_14 ) ;
if ( V_38 < 0 )
return V_38 ;
F_103 ( & V_122 ) ;
while ( ( V_120 = F_104 ( V_118 , & V_122 ) ) ) {
V_125 = (struct V_1 * ) ( V_127 ) V_120 -> V_129 ;
if ( V_125 -> V_130 < V_114 ) {
V_125 -> V_60 += V_131 * V_132 ;
V_125 -> V_61 += V_131 * V_132 ;
if ( V_117 -> V_133 == 0 ) {
V_125 -> V_62 += V_131 * V_132 ;
V_125 -> V_63 += V_131 * V_132 ;
}
F_91 ( V_3 , V_125 ) ;
}
F_108 ( V_125 -> V_134 >= V_114 ) ;
V_125 -> V_134 = V_114 ;
F_19 (glist, &qg->groups, next_group) {
V_38 = F_106 ( V_118 , V_128 -> V_27 -> V_4 ,
( V_127 ) V_128 -> V_27 , V_14 ) ;
if ( V_38 < 0 )
return V_38 ;
}
}
return 0 ;
}
static int F_109 ( struct V_2 * V_3 ,
struct V_116 * V_117 , struct V_116 * V_118 ,
T_1 V_114 , int V_131 , T_1 V_132 )
{
struct V_119 * V_120 ;
struct V_121 V_122 ;
struct V_1 * V_125 ;
struct V_119 * V_123 ;
struct V_121 V_124 ;
int V_38 ;
F_103 ( & V_122 ) ;
while ( ( V_120 = F_104 ( V_117 , & V_122 ) ) ) {
V_125 = F_1 ( V_3 , V_120 -> V_126 ) ;
if ( ! V_125 )
continue;
F_105 ( V_118 ) ;
V_38 = F_106 ( V_118 , V_125 -> V_4 , ( V_127 ) V_125 , V_14 ) ;
if ( V_38 < 0 )
return V_38 ;
F_103 ( & V_124 ) ;
while ( ( V_123 = F_104 ( V_118 , & V_124 ) ) ) {
struct V_19 * V_128 ;
V_125 = (struct V_1 * ) ( V_127 ) V_123 -> V_129 ;
if ( V_125 -> V_134 == V_114 )
continue;
if ( V_125 -> V_130 - V_114 == V_117 -> V_133 ) {
V_125 -> V_62 -= V_131 * V_132 ;
V_125 -> V_63 -= V_131 * V_132 ;
F_91 ( V_3 , V_125 ) ;
}
F_19 (glist, &qg->groups, next_group) {
V_38 = F_106 ( V_118 , V_128 -> V_27 -> V_4 ,
( V_127 ) V_128 -> V_27 ,
V_14 ) ;
if ( V_38 < 0 )
return V_38 ;
}
}
}
return 0 ;
}
int F_110 ( struct V_75 * V_76 ,
struct V_2 * V_3 ,
struct V_108 * V_9 ,
struct V_109 * V_110 )
{
struct V_31 * V_32 ;
T_1 V_135 ;
struct V_1 * V_8 ;
struct V_116 * V_117 = NULL ;
T_1 V_114 ;
int V_38 = 0 ;
int V_131 ;
if ( ! V_3 -> V_41 )
return 0 ;
F_100 ( ! V_3 -> V_32 ) ;
if ( V_9 -> type == V_136 ||
V_9 -> type == V_137 ) {
struct V_138 * V_139 ;
V_139 = F_111 ( V_9 ) ;
V_135 = V_139 -> V_83 ;
} else if ( V_9 -> type == V_140 ||
V_9 -> type == V_141 ) {
struct V_142 * V_139 ;
V_139 = F_112 ( V_9 ) ;
V_135 = V_139 -> V_83 ;
} else {
F_113 () ;
}
if ( ! F_114 ( V_135 ) ) {
return 0 ;
}
switch ( V_9 -> V_143 ) {
case V_144 :
case V_145 :
V_131 = 1 ;
V_114 = F_115 ( V_9 -> V_114 ) ;
break;
case V_146 :
V_131 = - 1 ;
V_114 = V_9 -> V_114 ;
break;
case V_147 :
return 0 ;
default:
F_113 () ;
}
F_78 ( & V_3 -> V_148 ) ;
if ( V_3 -> V_45 & V_74 ) {
if ( V_3 -> V_84 . V_46 <= V_9 -> V_149 ) {
F_84 ( & V_3 -> V_148 ) ;
return 0 ;
}
}
F_84 ( & V_3 -> V_148 ) ;
V_38 = F_116 ( V_76 , V_3 , V_9 -> V_149 , V_114 , & V_117 ) ;
if ( V_38 < 0 )
return V_38 ;
F_81 ( & V_3 -> V_95 ) ;
V_32 = V_3 -> V_32 ;
if ( ! V_32 )
goto V_150;
V_8 = F_1 ( V_3 , V_135 ) ;
if ( ! V_8 )
goto V_150;
F_105 ( V_3 -> V_42 ) ;
V_114 = V_3 -> V_151 ;
V_3 -> V_151 += V_117 -> V_133 + 1 ;
V_38 = F_102 ( V_3 , V_117 , V_3 -> V_42 ,
V_114 ) ;
if ( V_38 )
goto V_150;
V_38 = F_107 ( V_3 , V_117 , V_3 -> V_42 ,
V_114 , V_131 , V_9 -> V_132 , V_8 ) ;
if ( V_38 )
goto V_150;
V_38 = F_109 ( V_3 , V_117 , V_3 -> V_42 ,
V_114 , V_131 , V_9 -> V_132 ) ;
if ( V_38 )
goto V_150;
V_150:
F_82 ( & V_3 -> V_95 ) ;
F_47 ( V_117 ) ;
return V_38 ;
}
int F_117 ( struct V_75 * V_76 ,
struct V_2 * V_3 )
{
struct V_31 * V_32 = V_3 -> V_32 ;
int V_38 = 0 ;
int V_152 = 0 ;
if ( ! V_32 )
goto V_44;
if ( ! V_3 -> V_41 && V_3 -> V_73 )
V_152 = 1 ;
V_3 -> V_41 = V_3 -> V_73 ;
F_81 ( & V_3 -> V_95 ) ;
while ( ! F_11 ( & V_3 -> V_99 ) ) {
struct V_1 * V_8 ;
V_8 = F_12 ( & V_3 -> V_99 ,
struct V_1 , V_18 ) ;
F_118 ( & V_8 -> V_18 ) ;
F_82 ( & V_3 -> V_95 ) ;
V_38 = F_69 ( V_76 , V_32 , V_8 ) ;
if ( V_38 )
V_3 -> V_45 |=
V_55 ;
F_81 ( & V_3 -> V_95 ) ;
}
if ( V_3 -> V_41 )
V_3 -> V_45 |= V_72 ;
else
V_3 -> V_45 &= ~ V_72 ;
F_82 ( & V_3 -> V_95 ) ;
V_38 = F_70 ( V_76 , V_3 , V_32 ) ;
if ( V_38 )
V_3 -> V_45 |= V_55 ;
if ( ! V_38 && V_152 ) {
V_38 = F_45 ( V_3 , 0 , 1 ) ;
if ( ! V_38 ) {
F_119 ( V_3 ) ;
F_120 ( & V_3 -> V_153 ,
& V_3 -> V_154 ) ;
}
V_38 = 0 ;
}
V_44:
return V_38 ;
}
int F_121 ( struct V_75 * V_76 ,
struct V_2 * V_3 , T_1 V_155 , T_1 V_46 ,
struct F_121 * V_156 )
{
int V_38 = 0 ;
int V_157 ;
T_1 * V_158 ;
struct V_31 * V_32 = V_3 -> V_32 ;
struct V_1 * V_159 ;
struct V_1 * V_160 ;
T_2 V_161 = 0 ;
T_1 V_162 ;
F_78 ( & V_3 -> V_88 ) ;
if ( ! V_3 -> V_41 )
goto V_44;
if ( ! V_32 ) {
V_38 = - V_100 ;
goto V_44;
}
if ( V_156 ) {
V_158 = ( T_1 * ) ( V_156 + 1 ) ;
V_162 = V_156 -> V_163 + 2 * V_156 -> V_164 +
2 * V_156 -> V_165 ;
for ( V_157 = 0 ; V_157 < V_162 ; ++ V_157 ) {
V_159 = F_1 ( V_3 , * V_158 ) ;
if ( ! V_159 ) {
V_38 = - V_100 ;
goto V_44;
}
++ V_158 ;
}
}
V_38 = F_56 ( V_76 , V_32 , V_46 ) ;
if ( V_38 )
goto V_44;
if ( V_156 && V_156 -> V_39 & V_166 ) {
V_38 = F_68 ( V_76 , V_32 , V_46 ,
V_156 -> V_167 . V_39 ,
V_156 -> V_167 . V_66 ,
V_156 -> V_167 . V_67 ,
V_156 -> V_167 . V_68 ,
V_156 -> V_167 . V_69 ) ;
if ( V_38 )
goto V_44;
}
if ( V_155 ) {
struct V_31 * V_168 ;
struct V_28 V_169 ;
int V_170 ;
V_169 . V_46 = V_155 ;
V_169 . type = V_171 ;
V_169 . V_47 = ( T_1 ) - 1 ;
V_168 = F_122 ( V_3 , & V_169 ) ;
if ( F_31 ( V_168 ) ) {
V_38 = F_32 ( V_168 ) ;
goto V_44;
}
F_123 () ;
V_170 = F_124 ( V_168 -> V_9 ) ;
V_161 = F_125 ( V_168 , V_170 ) ;
F_126 () ;
}
if ( V_156 ) {
V_158 = ( T_1 * ) ( V_156 + 1 ) ;
for ( V_157 = 0 ; V_157 < V_156 -> V_163 ; ++ V_157 ) {
V_38 = F_50 ( V_76 , V_32 ,
V_46 , * V_158 ) ;
if ( V_38 )
goto V_44;
V_38 = F_50 ( V_76 , V_32 ,
* V_158 , V_46 ) ;
if ( V_38 )
goto V_44;
++ V_158 ;
}
}
F_81 ( & V_3 -> V_95 ) ;
V_160 = F_3 ( V_3 , V_46 ) ;
if ( F_31 ( V_160 ) ) {
V_38 = F_32 ( V_160 ) ;
goto V_150;
}
if ( V_155 ) {
V_159 = F_1 ( V_3 , V_155 ) ;
if ( ! V_159 )
goto V_150;
V_160 -> V_60 = V_159 -> V_60 - V_161 ;
V_160 -> V_61 = V_159 -> V_61 - V_161 ;
V_159 -> V_62 = V_161 ;
V_159 -> V_63 = V_161 ;
F_91 ( V_3 , V_160 ) ;
F_91 ( V_3 , V_159 ) ;
}
if ( ! V_156 )
goto V_150;
V_158 = ( T_1 * ) ( V_156 + 1 ) ;
for ( V_157 = 0 ; V_157 < V_156 -> V_163 ; ++ V_157 ) {
V_38 = F_16 ( V_32 -> V_3 , V_46 ,
* V_158 ) ;
if ( V_38 )
goto V_150;
++ V_158 ;
}
for ( V_157 = 0 ; V_157 < V_156 -> V_164 ; ++ V_157 ) {
struct V_1 * V_77 ;
struct V_1 * V_78 ;
V_77 = F_1 ( V_3 , V_158 [ 0 ] ) ;
V_78 = F_1 ( V_3 , V_158 [ 1 ] ) ;
if ( ! V_77 || ! V_78 ) {
V_38 = - V_100 ;
goto V_150;
}
V_78 -> V_60 = V_77 -> V_60 - V_161 ;
V_78 -> V_61 = V_77 -> V_61 - V_161 ;
V_158 += 2 ;
}
for ( V_157 = 0 ; V_157 < V_156 -> V_165 ; ++ V_157 ) {
struct V_1 * V_77 ;
struct V_1 * V_78 ;
V_77 = F_1 ( V_3 , V_158 [ 0 ] ) ;
V_78 = F_1 ( V_3 , V_158 [ 1 ] ) ;
if ( ! V_77 || ! V_78 ) {
V_38 = - V_100 ;
goto V_150;
}
V_78 -> V_62 = V_77 -> V_62 + V_161 ;
V_78 -> V_63 = V_77 -> V_63 + V_161 ;
V_158 += 2 ;
}
V_150:
F_82 ( & V_3 -> V_95 ) ;
V_44:
F_84 ( & V_3 -> V_88 ) ;
return V_38 ;
}
int F_127 ( struct V_31 * V_83 , T_1 V_132 )
{
struct V_31 * V_32 ;
struct V_1 * V_8 ;
struct V_2 * V_3 = V_83 -> V_3 ;
T_1 V_135 = V_83 -> V_97 . V_46 ;
int V_38 = 0 ;
struct V_119 * V_120 ;
struct V_121 V_122 ;
if ( ! F_114 ( V_135 ) )
return 0 ;
if ( V_132 == 0 )
return 0 ;
F_81 ( & V_3 -> V_95 ) ;
V_32 = V_3 -> V_32 ;
if ( ! V_32 )
goto V_44;
V_8 = F_1 ( V_3 , V_135 ) ;
if ( ! V_8 )
goto V_44;
F_105 ( V_3 -> V_42 ) ;
V_38 = F_106 ( V_3 -> V_42 , V_8 -> V_4 ,
( V_127 ) V_8 , V_14 ) ;
if ( V_38 < 0 )
goto V_44;
F_103 ( & V_122 ) ;
while ( ( V_120 = F_104 ( V_3 -> V_42 , & V_122 ) ) ) {
struct V_1 * V_125 ;
struct V_19 * V_128 ;
V_125 = (struct V_1 * ) ( V_127 ) V_120 -> V_129 ;
if ( ( V_125 -> V_65 & V_172 ) &&
V_125 -> V_173 + ( V_174 ) V_125 -> V_60 + V_132 >
V_125 -> V_66 ) {
V_38 = - V_175 ;
goto V_44;
}
if ( ( V_125 -> V_65 & V_176 ) &&
V_125 -> V_173 + ( V_174 ) V_125 -> V_62 + V_132 >
V_125 -> V_67 ) {
V_38 = - V_175 ;
goto V_44;
}
F_19 (glist, &qg->groups, next_group) {
V_38 = F_106 ( V_3 -> V_42 ,
V_128 -> V_27 -> V_4 ,
( V_127 ) V_128 -> V_27 , V_14 ) ;
if ( V_38 < 0 )
goto V_44;
}
}
V_38 = 0 ;
F_103 ( & V_122 ) ;
while ( ( V_120 = F_104 ( V_3 -> V_42 , & V_122 ) ) ) {
struct V_1 * V_125 ;
V_125 = (struct V_1 * ) ( V_127 ) V_120 -> V_129 ;
V_125 -> V_173 += V_132 ;
}
V_44:
F_82 ( & V_3 -> V_95 ) ;
return V_38 ;
}
void F_128 ( struct V_31 * V_83 , T_1 V_132 )
{
struct V_31 * V_32 ;
struct V_1 * V_8 ;
struct V_2 * V_3 = V_83 -> V_3 ;
struct V_119 * V_120 ;
struct V_121 V_122 ;
T_1 V_135 = V_83 -> V_97 . V_46 ;
int V_38 = 0 ;
if ( ! F_114 ( V_135 ) )
return;
if ( V_132 == 0 )
return;
F_81 ( & V_3 -> V_95 ) ;
V_32 = V_3 -> V_32 ;
if ( ! V_32 )
goto V_44;
V_8 = F_1 ( V_3 , V_135 ) ;
if ( ! V_8 )
goto V_44;
F_105 ( V_3 -> V_42 ) ;
V_38 = F_106 ( V_3 -> V_42 , V_8 -> V_4 ,
( V_127 ) V_8 , V_14 ) ;
if ( V_38 < 0 )
goto V_44;
F_103 ( & V_122 ) ;
while ( ( V_120 = F_104 ( V_3 -> V_42 , & V_122 ) ) ) {
struct V_1 * V_125 ;
struct V_19 * V_128 ;
V_125 = (struct V_1 * ) ( V_127 ) V_120 -> V_129 ;
V_125 -> V_173 -= V_132 ;
F_19 (glist, &qg->groups, next_group) {
V_38 = F_106 ( V_3 -> V_42 ,
V_128 -> V_27 -> V_4 ,
( V_127 ) V_128 -> V_27 , V_14 ) ;
if ( V_38 < 0 )
goto V_44;
}
}
V_44:
F_82 ( & V_3 -> V_95 ) ;
}
void F_129 ( struct V_75 * V_76 )
{
if ( F_11 ( & V_76 -> V_115 ) && ! V_76 -> V_113 . V_114 )
return;
F_27 ( V_76 -> V_83 -> V_3 ,
L_7
L_8 ,
V_76 , F_11 ( & V_76 -> V_115 ) ? L_9 : L_10 ,
( T_2 ) ( V_76 -> V_113 . V_114 >> 32 ) ,
( T_2 ) V_76 -> V_113 . V_114 ) ;
F_113 () ;
}
static int
F_130 ( struct V_2 * V_3 , struct V_33 * V_34 ,
struct V_75 * V_76 , struct V_116 * V_118 ,
struct V_35 * V_177 )
{
struct V_28 V_178 ;
struct V_116 * V_117 = NULL ;
struct V_119 * V_120 ;
struct V_121 V_122 ;
struct V_179 V_180 = {} ;
T_1 V_114 ;
int V_37 ;
int V_38 ;
V_34 -> V_86 = 1 ;
F_78 ( & V_3 -> V_148 ) ;
V_38 = F_23 ( V_3 -> V_181 ,
& V_3 -> V_84 ,
V_34 , 1 , 0 ) ;
F_131 ( L_11 ,
V_3 -> V_84 . V_46 ,
V_3 -> V_84 . type ,
V_3 -> V_84 . V_47 , V_38 ) ;
if ( V_38 ) {
V_3 -> V_84 . V_46 = ( T_1 ) - 1 ;
F_43 ( V_34 ) ;
F_84 ( & V_3 -> V_148 ) ;
return V_38 ;
}
F_24 ( V_34 -> V_49 [ 0 ] , & V_178 ,
F_75 ( V_34 -> V_49 [ 0 ] ) - 1 ) ;
V_3 -> V_84 . V_46 = V_178 . V_46 + 1 ;
F_132 ( V_3 , & V_180 ) ;
memcpy ( V_177 , V_34 -> V_49 [ 0 ] , sizeof( * V_177 ) ) ;
V_37 = V_34 -> V_48 [ 0 ] ;
F_43 ( V_34 ) ;
F_84 ( & V_3 -> V_148 ) ;
for (; V_37 < F_75 ( V_177 ) ; ++ V_37 ) {
T_1 V_132 ;
F_24 ( V_177 , & V_178 , V_37 ) ;
if ( V_178 . type != V_182 &&
V_178 . type != V_183 )
continue;
if ( V_178 . type == V_183 )
V_132 = V_3 -> V_181 -> V_184 ;
else
V_132 = V_178 . V_47 ;
V_38 = F_116 ( V_76 , V_3 , V_178 . V_46 ,
V_180 . V_114 , & V_117 ) ;
if ( V_38 < 0 )
goto V_44;
F_81 ( & V_3 -> V_95 ) ;
V_114 = V_3 -> V_151 ;
V_3 -> V_151 += V_117 -> V_133 + 1 ;
V_38 = F_102 ( V_3 , V_117 , V_118 , V_114 ) ;
if ( V_38 ) {
F_82 ( & V_3 -> V_95 ) ;
F_47 ( V_117 ) ;
goto V_44;
}
F_105 ( V_118 ) ;
F_103 ( & V_122 ) ;
while ( ( V_120 = F_104 ( V_117 , & V_122 ) ) ) {
struct V_1 * V_125 ;
V_125 = F_1 ( V_3 , V_120 -> V_126 ) ;
if ( ! V_125 )
continue;
V_38 = F_106 ( V_118 , V_125 -> V_4 , ( V_127 ) V_125 ,
V_14 ) ;
if ( V_38 < 0 ) {
F_82 ( & V_3 -> V_95 ) ;
F_47 ( V_117 ) ;
goto V_44;
}
}
F_103 ( & V_122 ) ;
while ( ( V_120 = F_104 ( V_118 , & V_122 ) ) ) {
struct V_1 * V_125 ;
struct V_19 * V_128 ;
V_125 = (struct V_1 * ) ( V_127 ) V_120 -> V_129 ;
V_125 -> V_60 += V_132 ;
V_125 -> V_61 += V_132 ;
F_108 ( V_125 -> V_134 >= V_114 ) ;
if ( V_125 -> V_130 - V_114 == V_117 -> V_133 ) {
V_125 -> V_62 += V_132 ;
V_125 -> V_63 += V_132 ;
}
F_91 ( V_3 , V_125 ) ;
F_19 (glist, &qg->groups, next_group) {
V_38 = F_106 ( V_118 , V_128 -> V_27 -> V_4 ,
( V_127 ) V_128 -> V_27 ,
V_14 ) ;
if ( V_38 < 0 ) {
F_82 ( & V_3 -> V_95 ) ;
F_47 ( V_117 ) ;
goto V_44;
}
}
}
F_82 ( & V_3 -> V_95 ) ;
F_47 ( V_117 ) ;
V_38 = 0 ;
}
V_44:
F_133 ( V_3 , & V_180 ) ;
return V_38 ;
}
static void F_134 ( struct V_185 * V_186 )
{
struct V_2 * V_3 = F_135 ( V_186 , struct V_2 ,
V_154 ) ;
struct V_33 * V_34 ;
struct V_75 * V_76 = NULL ;
struct V_116 * V_118 = NULL ;
struct V_35 * V_177 = NULL ;
int V_102 = - V_15 ;
V_34 = F_22 () ;
if ( ! V_34 )
goto V_44;
V_118 = F_21 ( V_43 ) ;
if ( ! V_118 )
goto V_44;
V_177 = F_101 ( sizeof( * V_177 ) , V_43 ) ;
if ( ! V_177 )
goto V_44;
V_102 = 0 ;
while ( ! V_102 ) {
V_76 = F_136 ( V_3 -> V_187 , 0 ) ;
if ( F_31 ( V_76 ) ) {
V_102 = F_32 ( V_76 ) ;
break;
}
if ( ! V_3 -> V_41 ) {
V_102 = - V_188 ;
} else {
V_102 = F_130 ( V_3 , V_34 , V_76 ,
V_118 , V_177 ) ;
}
if ( V_102 > 0 )
F_137 ( V_76 , V_3 -> V_187 ) ;
else
F_138 ( V_76 , V_3 -> V_187 ) ;
}
V_44:
F_13 ( V_177 ) ;
F_47 ( V_118 ) ;
F_46 ( V_34 ) ;
F_78 ( & V_3 -> V_148 ) ;
V_3 -> V_45 &= ~ V_74 ;
if ( V_102 == 2 &&
V_3 -> V_45 & V_55 ) {
V_3 -> V_45 &= ~ V_55 ;
} else if ( V_102 < 0 ) {
V_3 -> V_45 |= V_55 ;
}
F_84 ( & V_3 -> V_148 ) ;
if ( V_102 >= 0 ) {
F_98 ( V_3 , L_12 ,
V_102 == 2 ? L_13 : L_9 ) ;
} else {
F_27 ( V_3 , L_14 , V_102 ) ;
}
F_139 ( & V_3 -> V_189 ) ;
}
static int
F_45 ( struct V_2 * V_3 , T_1 V_190 ,
int V_191 )
{
int V_38 = 0 ;
if ( ! V_191 &&
( ! ( V_3 -> V_45 & V_74 ) ||
! ( V_3 -> V_45 & V_72 ) ) ) {
V_38 = - V_100 ;
goto V_102;
}
F_78 ( & V_3 -> V_148 ) ;
F_81 ( & V_3 -> V_95 ) ;
if ( V_191 ) {
if ( V_3 -> V_45 & V_74 )
V_38 = - V_192 ;
else if ( ! ( V_3 -> V_45 & V_72 ) )
V_38 = - V_100 ;
if ( V_38 ) {
F_82 ( & V_3 -> V_95 ) ;
F_84 ( & V_3 -> V_148 ) ;
goto V_102;
}
V_3 -> V_45 |= V_74 ;
}
memset ( & V_3 -> V_84 , 0 ,
sizeof( V_3 -> V_84 ) ) ;
V_3 -> V_84 . V_46 = V_190 ;
F_82 ( & V_3 -> V_95 ) ;
F_84 ( & V_3 -> V_148 ) ;
F_140 ( & V_3 -> V_189 ) ;
memset ( & V_3 -> V_154 , 0 ,
sizeof( V_3 -> V_154 ) ) ;
V_3 -> V_154 . V_193 = F_134 ;
if ( V_38 ) {
V_102:
F_98 ( V_3 , L_15 , V_38 ) ;
return V_38 ;
}
return 0 ;
}
static void
F_119 ( struct V_2 * V_3 )
{
struct V_5 * V_6 ;
struct V_1 * V_8 ;
F_81 ( & V_3 -> V_95 ) ;
for ( V_6 = F_49 ( & V_3 -> V_7 ) ; V_6 ; V_6 = F_141 ( V_6 ) ) {
V_8 = F_2 ( V_6 , struct V_1 , V_9 ) ;
V_8 -> V_60 = 0 ;
V_8 -> V_61 = 0 ;
V_8 -> V_62 = 0 ;
V_8 -> V_63 = 0 ;
}
F_82 ( & V_3 -> V_95 ) ;
}
int
F_142 ( struct V_2 * V_3 )
{
int V_38 = 0 ;
struct V_75 * V_76 ;
V_38 = F_45 ( V_3 , 0 , 1 ) ;
if ( V_38 )
return V_38 ;
V_76 = F_143 ( V_3 -> V_187 ) ;
if ( F_31 ( V_76 ) ) {
V_3 -> V_45 &= ~ V_74 ;
return F_32 ( V_76 ) ;
}
V_38 = F_137 ( V_76 , V_3 -> V_187 ) ;
if ( V_38 ) {
V_3 -> V_45 &= ~ V_74 ;
return V_38 ;
}
F_119 ( V_3 ) ;
F_120 ( & V_3 -> V_153 ,
& V_3 -> V_154 ) ;
return 0 ;
}
int F_144 ( struct V_2 * V_3 )
{
int V_194 ;
int V_38 = 0 ;
F_78 ( & V_3 -> V_148 ) ;
F_81 ( & V_3 -> V_95 ) ;
V_194 = V_3 -> V_45 & V_74 ;
F_82 ( & V_3 -> V_95 ) ;
F_84 ( & V_3 -> V_148 ) ;
if ( V_194 )
V_38 = F_145 (
& V_3 -> V_189 ) ;
return V_38 ;
}
void
F_146 ( struct V_2 * V_3 )
{
if ( V_3 -> V_45 & V_74 )
F_120 ( & V_3 -> V_153 ,
& V_3 -> V_154 ) ;
}
