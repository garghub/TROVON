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
T_1 V_40 = 0 ;
if ( ! V_3 -> V_41 )
return 0 ;
V_3 -> V_42 = F_20 ( V_43 ) ;
if ( ! V_3 -> V_42 ) {
V_38 = - V_15 ;
goto V_44;
}
V_34 = F_21 () ;
if ( ! V_34 ) {
V_38 = - V_15 ;
goto V_44;
}
V_3 -> V_45 = 0 ;
V_29 . V_46 = 0 ;
V_29 . type = 0 ;
V_29 . V_47 = 0 ;
V_38 = F_22 ( V_32 , & V_29 , V_34 , 1 , 1 ) ;
if ( V_38 )
goto V_44;
while ( 1 ) {
struct V_1 * V_8 ;
V_37 = V_34 -> V_48 [ 0 ] ;
V_36 = V_34 -> V_49 [ 0 ] ;
F_23 ( V_36 , & V_30 , V_37 ) ;
if ( V_30 . type == V_50 ) {
struct V_51 * V_52 ;
V_52 = F_24 ( V_36 , V_37 ,
struct V_51 ) ;
if ( F_25 ( V_36 , V_52 ) !=
V_53 ) {
F_26 ( V_54
L_1 ) ;
goto V_44;
}
if ( F_27 ( V_36 , V_52 ) !=
V_3 -> V_55 ) {
V_39 |= V_56 ;
F_26 ( V_54
L_2
L_3 ) ;
}
V_3 -> V_45 = F_28 ( V_36 ,
V_52 ) ;
V_40 = F_29 ( V_36 , V_52 ) ;
goto V_57;
}
if ( V_30 . type != V_58 &&
V_30 . type != V_59 )
goto V_57;
V_8 = F_1 ( V_3 , V_30 . V_47 ) ;
if ( ( V_8 && V_30 . type == V_58 ) ||
( ! V_8 && V_30 . type == V_59 ) ) {
F_26 ( V_54 L_4 ) ;
V_39 |= V_56 ;
}
if ( ! V_8 ) {
V_8 = F_3 ( V_3 , V_30 . V_47 ) ;
if ( F_30 ( V_8 ) ) {
V_38 = F_31 ( V_8 ) ;
goto V_44;
}
}
switch ( V_30 . type ) {
case V_58 : {
struct V_60 * V_52 ;
V_52 = F_24 ( V_36 , V_37 ,
struct V_60 ) ;
V_8 -> V_61 = F_32 ( V_36 , V_52 ) ;
V_8 -> V_62 = F_33 ( V_36 , V_52 ) ;
V_8 -> V_63 = F_34 ( V_36 , V_52 ) ;
V_8 -> V_64 = F_35 ( V_36 , V_52 ) ;
break;
}
case V_59 : {
struct V_65 * V_52 ;
V_52 = F_24 ( V_36 , V_37 ,
struct V_65 ) ;
V_8 -> V_66 = F_36 ( V_36 , V_52 ) ;
V_8 -> V_67 = F_37 ( V_36 , V_52 ) ;
V_8 -> V_68 = F_38 ( V_36 , V_52 ) ;
V_8 -> V_69 = F_39 ( V_36 , V_52 ) ;
V_8 -> V_70 = F_40 ( V_36 , V_52 ) ;
break;
}
}
V_57:
V_38 = F_41 ( V_32 , V_34 ) ;
if ( V_38 < 0 )
goto V_44;
if ( V_38 )
break;
}
F_42 ( V_34 ) ;
V_29 . V_46 = 0 ;
V_29 . type = V_71 ;
V_29 . V_47 = 0 ;
V_38 = F_22 ( V_32 , & V_29 , V_34 , 1 , 0 ) ;
if ( V_38 )
goto V_44;
while ( 1 ) {
V_37 = V_34 -> V_48 [ 0 ] ;
V_36 = V_34 -> V_49 [ 0 ] ;
F_23 ( V_36 , & V_30 , V_37 ) ;
if ( V_30 . type != V_71 )
goto V_72;
if ( V_30 . V_46 > V_30 . V_47 ) {
goto V_72;
}
V_38 = F_15 ( V_3 , V_30 . V_46 ,
V_30 . V_47 ) ;
if ( V_38 == - V_21 ) {
F_26 ( V_73
L_5 ,
( unsigned long long ) V_30 . V_46 ,
( unsigned long long ) V_30 . V_47 ) ;
V_38 = 0 ;
}
if ( V_38 )
goto V_44;
V_72:
V_38 = F_41 ( V_32 , V_34 ) ;
if ( V_38 < 0 )
goto V_44;
if ( V_38 )
break;
}
V_44:
V_3 -> V_45 |= V_39 ;
if ( ! ( V_3 -> V_45 & V_74 ) ) {
V_3 -> V_41 = 0 ;
V_3 -> V_75 = 0 ;
} else if ( V_3 -> V_45 & V_76 &&
V_38 >= 0 ) {
V_38 = F_43 ( V_3 , V_40 , 0 ) ;
}
F_44 ( V_34 ) ;
if ( V_38 < 0 ) {
F_45 ( V_3 -> V_42 ) ;
V_3 -> V_42 = NULL ;
V_3 -> V_45 &= ~ V_76 ;
}
return V_38 < 0 ? V_38 : 0 ;
}
void F_46 ( struct V_2 * V_3 )
{
struct V_5 * V_6 ;
struct V_1 * V_8 ;
struct V_19 * V_20 ;
while ( ( V_6 = F_47 ( & V_3 -> V_7 ) ) ) {
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
F_45 ( V_3 -> V_42 ) ;
}
static int F_48 ( struct V_77 * V_78 ,
struct V_31 * V_32 ,
T_1 V_79 , T_1 V_80 )
{
int V_38 ;
struct V_33 * V_34 ;
struct V_28 V_29 ;
V_34 = F_21 () ;
if ( ! V_34 )
return - V_15 ;
V_29 . V_46 = V_79 ;
V_29 . type = V_71 ;
V_29 . V_47 = V_80 ;
V_38 = F_49 ( V_78 , V_32 , V_34 , & V_29 , 0 ) ;
F_50 ( V_34 -> V_49 [ 0 ] ) ;
F_44 ( V_34 ) ;
return V_38 ;
}
static int F_51 ( struct V_77 * V_78 ,
struct V_31 * V_32 ,
T_1 V_79 , T_1 V_80 )
{
int V_38 ;
struct V_33 * V_34 ;
struct V_28 V_29 ;
V_34 = F_21 () ;
if ( ! V_34 )
return - V_15 ;
V_29 . V_46 = V_79 ;
V_29 . type = V_71 ;
V_29 . V_47 = V_80 ;
V_38 = F_52 ( V_78 , V_32 , & V_29 , V_34 , - 1 , 1 ) ;
if ( V_38 < 0 )
goto V_44;
if ( V_38 > 0 ) {
V_38 = - V_21 ;
goto V_44;
}
V_38 = F_53 ( V_78 , V_32 , V_34 ) ;
V_44:
F_44 ( V_34 ) ;
return V_38 ;
}
static int F_54 ( struct V_77 * V_78 ,
struct V_31 * V_32 , T_1 V_4 )
{
int V_38 ;
struct V_33 * V_34 ;
struct V_60 * V_81 ;
struct V_65 * V_82 ;
struct V_35 * V_83 ;
struct V_28 V_29 ;
V_34 = F_21 () ;
if ( ! V_34 )
return - V_15 ;
V_29 . V_46 = 0 ;
V_29 . type = V_58 ;
V_29 . V_47 = V_4 ;
V_38 = F_49 ( V_78 , V_32 , V_34 , & V_29 ,
sizeof( * V_81 ) ) ;
if ( V_38 )
goto V_44;
V_83 = V_34 -> V_49 [ 0 ] ;
V_81 = F_24 ( V_83 , V_34 -> V_48 [ 0 ] ,
struct V_60 ) ;
F_55 ( V_83 , V_81 , V_78 -> V_84 ) ;
F_56 ( V_83 , V_81 , 0 ) ;
F_57 ( V_83 , V_81 , 0 ) ;
F_58 ( V_83 , V_81 , 0 ) ;
F_59 ( V_83 , V_81 , 0 ) ;
F_50 ( V_83 ) ;
F_42 ( V_34 ) ;
V_29 . type = V_59 ;
V_38 = F_49 ( V_78 , V_32 , V_34 , & V_29 ,
sizeof( * V_82 ) ) ;
if ( V_38 )
goto V_44;
V_83 = V_34 -> V_49 [ 0 ] ;
V_82 = F_24 ( V_83 , V_34 -> V_48 [ 0 ] ,
struct V_65 ) ;
F_60 ( V_83 , V_82 , 0 ) ;
F_61 ( V_83 , V_82 , 0 ) ;
F_62 ( V_83 , V_82 , 0 ) ;
F_63 ( V_83 , V_82 , 0 ) ;
F_64 ( V_83 , V_82 , 0 ) ;
F_50 ( V_83 ) ;
V_38 = 0 ;
V_44:
F_44 ( V_34 ) ;
return V_38 ;
}
static int F_65 ( struct V_77 * V_78 ,
struct V_31 * V_32 , T_1 V_4 )
{
int V_38 ;
struct V_33 * V_34 ;
struct V_28 V_29 ;
V_34 = F_21 () ;
if ( ! V_34 )
return - V_15 ;
V_29 . V_46 = 0 ;
V_29 . type = V_58 ;
V_29 . V_47 = V_4 ;
V_38 = F_52 ( V_78 , V_32 , & V_29 , V_34 , - 1 , 1 ) ;
if ( V_38 < 0 )
goto V_44;
if ( V_38 > 0 ) {
V_38 = - V_21 ;
goto V_44;
}
V_38 = F_53 ( V_78 , V_32 , V_34 ) ;
if ( V_38 )
goto V_44;
F_42 ( V_34 ) ;
V_29 . type = V_59 ;
V_38 = F_52 ( V_78 , V_32 , & V_29 , V_34 , - 1 , 1 ) ;
if ( V_38 < 0 )
goto V_44;
if ( V_38 > 0 ) {
V_38 = - V_21 ;
goto V_44;
}
V_38 = F_53 ( V_78 , V_32 , V_34 ) ;
V_44:
F_44 ( V_34 ) ;
return V_38 ;
}
static int F_66 ( struct V_77 * V_78 ,
struct V_31 * V_85 , T_1 V_4 ,
T_1 V_39 , T_1 V_67 , T_1 V_68 ,
T_1 V_69 , T_1 V_70 )
{
struct V_33 * V_34 ;
struct V_28 V_29 ;
struct V_35 * V_36 ;
struct V_65 * V_82 ;
int V_38 ;
int V_37 ;
V_29 . V_46 = 0 ;
V_29 . type = V_59 ;
V_29 . V_47 = V_4 ;
V_34 = F_21 () ;
if ( ! V_34 )
return - V_15 ;
V_38 = F_52 ( V_78 , V_85 , & V_29 , V_34 , 0 , 1 ) ;
if ( V_38 > 0 )
V_38 = - V_21 ;
if ( V_38 )
goto V_44;
V_36 = V_34 -> V_49 [ 0 ] ;
V_37 = V_34 -> V_48 [ 0 ] ;
V_82 = F_24 ( V_36 , V_34 -> V_48 [ 0 ] ,
struct V_65 ) ;
F_60 ( V_36 , V_82 , V_39 ) ;
F_61 ( V_36 , V_82 , V_67 ) ;
F_62 ( V_36 , V_82 , V_68 ) ;
F_63 ( V_36 , V_82 , V_69 ) ;
F_64 ( V_36 , V_82 , V_70 ) ;
F_50 ( V_36 ) ;
V_44:
F_44 ( V_34 ) ;
return V_38 ;
}
static int F_67 ( struct V_77 * V_78 ,
struct V_31 * V_85 ,
struct V_1 * V_8 )
{
struct V_33 * V_34 ;
struct V_28 V_29 ;
struct V_35 * V_36 ;
struct V_60 * V_81 ;
int V_38 ;
int V_37 ;
V_29 . V_46 = 0 ;
V_29 . type = V_58 ;
V_29 . V_47 = V_8 -> V_4 ;
V_34 = F_21 () ;
if ( ! V_34 )
return - V_15 ;
V_38 = F_52 ( V_78 , V_85 , & V_29 , V_34 , 0 , 1 ) ;
if ( V_38 > 0 )
V_38 = - V_21 ;
if ( V_38 )
goto V_44;
V_36 = V_34 -> V_49 [ 0 ] ;
V_37 = V_34 -> V_48 [ 0 ] ;
V_81 = F_24 ( V_36 , V_34 -> V_48 [ 0 ] ,
struct V_60 ) ;
F_55 ( V_36 , V_81 , V_78 -> V_84 ) ;
F_56 ( V_36 , V_81 , V_8 -> V_61 ) ;
F_57 ( V_36 , V_81 , V_8 -> V_62 ) ;
F_58 ( V_36 , V_81 , V_8 -> V_63 ) ;
F_59 ( V_36 , V_81 , V_8 -> V_64 ) ;
F_50 ( V_36 ) ;
V_44:
F_44 ( V_34 ) ;
return V_38 ;
}
static int F_68 ( struct V_77 * V_78 ,
struct V_2 * V_3 ,
struct V_31 * V_85 )
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
V_34 = F_21 () ;
if ( ! V_34 )
return - V_15 ;
V_38 = F_52 ( V_78 , V_85 , & V_29 , V_34 , 0 , 1 ) ;
if ( V_38 > 0 )
V_38 = - V_21 ;
if ( V_38 )
goto V_44;
V_36 = V_34 -> V_49 [ 0 ] ;
V_37 = V_34 -> V_48 [ 0 ] ;
V_52 = F_24 ( V_36 , V_37 , struct V_51 ) ;
F_69 ( V_36 , V_52 , V_3 -> V_45 ) ;
F_70 ( V_36 , V_52 , V_78 -> V_84 ) ;
F_71 ( V_36 , V_52 ,
V_3 -> V_86 . V_46 ) ;
F_50 ( V_36 ) ;
V_44:
F_44 ( V_34 ) ;
return V_38 ;
}
static int F_72 ( struct V_77 * V_78 ,
struct V_31 * V_85 )
{
struct V_33 * V_34 ;
struct V_28 V_29 ;
struct V_35 * V_83 = NULL ;
int V_38 ;
int V_87 = 0 ;
V_34 = F_21 () ;
if ( ! V_34 )
return - V_15 ;
V_34 -> V_88 = 1 ;
V_29 . V_46 = 0 ;
V_29 . V_47 = 0 ;
V_29 . type = 0 ;
while ( 1 ) {
V_38 = F_52 ( V_78 , V_85 , & V_29 , V_34 , - 1 , 1 ) ;
if ( V_38 < 0 )
goto V_44;
V_83 = V_34 -> V_49 [ 0 ] ;
V_87 = F_73 ( V_83 ) ;
if ( ! V_87 )
break;
V_34 -> V_48 [ 0 ] = 0 ;
V_38 = F_74 ( V_78 , V_85 , V_34 , 0 , V_87 ) ;
if ( V_38 )
goto V_44;
F_42 ( V_34 ) ;
}
V_38 = 0 ;
V_44:
V_85 -> V_3 -> V_75 = 0 ;
F_44 ( V_34 ) ;
return V_38 ;
}
int F_75 ( struct V_77 * V_78 ,
struct V_2 * V_3 )
{
struct V_31 * V_32 ;
struct V_31 * V_89 = V_3 -> V_89 ;
struct V_33 * V_34 = NULL ;
struct V_51 * V_52 ;
struct V_35 * V_83 ;
struct V_28 V_29 ;
struct V_28 V_30 ;
struct V_1 * V_8 = NULL ;
int V_38 = 0 ;
int V_37 ;
F_76 ( & V_3 -> V_90 ) ;
if ( V_3 -> V_32 ) {
V_3 -> V_75 = 1 ;
goto V_44;
}
V_3 -> V_42 = F_20 ( V_43 ) ;
if ( ! V_3 -> V_42 ) {
V_38 = - V_15 ;
goto V_44;
}
V_32 = F_77 ( V_78 , V_3 ,
V_91 ) ;
if ( F_30 ( V_32 ) ) {
V_38 = F_31 ( V_32 ) ;
goto V_44;
}
V_34 = F_21 () ;
if ( ! V_34 ) {
V_38 = - V_15 ;
goto V_92;
}
V_29 . V_46 = 0 ;
V_29 . type = V_50 ;
V_29 . V_47 = 0 ;
V_38 = F_49 ( V_78 , V_32 , V_34 , & V_29 ,
sizeof( * V_52 ) ) ;
if ( V_38 )
goto V_93;
V_83 = V_34 -> V_49 [ 0 ] ;
V_52 = F_24 ( V_83 , V_34 -> V_48 [ 0 ] ,
struct V_51 ) ;
F_70 ( V_83 , V_52 , V_78 -> V_84 ) ;
F_78 ( V_83 , V_52 , V_53 ) ;
V_3 -> V_45 = V_74 |
V_56 ;
F_69 ( V_83 , V_52 , V_3 -> V_45 ) ;
F_71 ( V_83 , V_52 , 0 ) ;
F_50 ( V_83 ) ;
V_29 . V_46 = 0 ;
V_29 . type = V_94 ;
V_29 . V_47 = 0 ;
F_42 ( V_34 ) ;
V_38 = F_22 ( V_89 , & V_29 , V_34 , 1 , 0 ) ;
if ( V_38 > 0 )
goto V_95;
if ( V_38 < 0 )
goto V_93;
while ( 1 ) {
V_37 = V_34 -> V_48 [ 0 ] ;
V_83 = V_34 -> V_49 [ 0 ] ;
F_23 ( V_83 , & V_30 , V_37 ) ;
if ( V_30 . type == V_94 ) {
V_38 = F_54 ( V_78 , V_32 ,
V_30 . V_47 ) ;
if ( V_38 )
goto V_93;
V_8 = F_3 ( V_3 , V_30 . V_47 ) ;
if ( F_30 ( V_8 ) ) {
V_38 = F_31 ( V_8 ) ;
goto V_93;
}
}
V_38 = F_41 ( V_89 , V_34 ) ;
if ( V_38 < 0 )
goto V_93;
if ( V_38 )
break;
}
V_95:
F_42 ( V_34 ) ;
V_38 = F_54 ( V_78 , V_32 , V_96 ) ;
if ( V_38 )
goto V_93;
V_8 = F_3 ( V_3 , V_96 ) ;
if ( F_30 ( V_8 ) ) {
V_38 = F_31 ( V_8 ) ;
goto V_93;
}
F_79 ( & V_3 -> V_97 ) ;
V_3 -> V_32 = V_32 ;
V_3 -> V_75 = 1 ;
F_80 ( & V_3 -> V_97 ) ;
V_93:
F_44 ( V_34 ) ;
V_92:
if ( V_38 ) {
F_81 ( V_32 -> V_9 ) ;
F_81 ( V_32 -> V_98 ) ;
F_14 ( V_32 ) ;
}
V_44:
if ( V_38 ) {
F_45 ( V_3 -> V_42 ) ;
V_3 -> V_42 = NULL ;
}
F_82 ( & V_3 -> V_90 ) ;
return V_38 ;
}
int F_83 ( struct V_77 * V_78 ,
struct V_2 * V_3 )
{
struct V_31 * V_89 = V_3 -> V_89 ;
struct V_31 * V_32 ;
int V_38 = 0 ;
F_76 ( & V_3 -> V_90 ) ;
if ( ! V_3 -> V_32 )
goto V_44;
F_79 ( & V_3 -> V_97 ) ;
V_3 -> V_41 = 0 ;
V_3 -> V_75 = 0 ;
V_32 = V_3 -> V_32 ;
V_3 -> V_32 = NULL ;
F_46 ( V_3 ) ;
F_80 ( & V_3 -> V_97 ) ;
if ( ! V_32 ) {
V_38 = - V_99 ;
goto V_44;
}
V_38 = F_72 ( V_78 , V_32 ) ;
if ( V_38 )
goto V_44;
V_38 = F_84 ( V_78 , V_89 , & V_32 -> V_100 ) ;
if ( V_38 )
goto V_44;
F_11 ( & V_32 -> V_101 ) ;
F_85 ( V_32 -> V_9 ) ;
F_86 ( V_78 , V_89 , V_32 -> V_9 ) ;
F_87 ( V_32 -> V_9 ) ;
F_88 ( V_78 , V_32 , V_32 -> V_9 , 0 , 1 ) ;
F_81 ( V_32 -> V_9 ) ;
F_81 ( V_32 -> V_98 ) ;
F_14 ( V_32 ) ;
V_44:
F_82 ( & V_3 -> V_90 ) ;
return V_38 ;
}
static void F_89 ( struct V_2 * V_3 ,
struct V_1 * V_8 )
{
if ( F_12 ( & V_8 -> V_18 ) )
F_90 ( & V_8 -> V_18 , & V_3 -> V_102 ) ;
}
int F_91 ( struct V_77 * V_78 ,
struct V_2 * V_3 , T_1 V_79 , T_1 V_80 )
{
struct V_31 * V_32 ;
struct V_1 * V_13 ;
struct V_1 * V_26 ;
struct V_19 * V_20 ;
int V_38 = 0 ;
F_76 ( & V_3 -> V_90 ) ;
V_32 = V_3 -> V_32 ;
if ( ! V_32 ) {
V_38 = - V_99 ;
goto V_44;
}
V_26 = F_1 ( V_3 , V_79 ) ;
V_13 = F_1 ( V_3 , V_80 ) ;
if ( ! V_26 || ! V_13 ) {
V_38 = - V_99 ;
goto V_44;
}
F_18 (list, &member->groups, next_group) {
if ( V_20 -> V_27 == V_13 ) {
V_38 = - V_103 ;
goto V_44;
}
}
V_38 = F_48 ( V_78 , V_32 , V_79 , V_80 ) ;
if ( V_38 )
goto V_44;
V_38 = F_48 ( V_78 , V_32 , V_80 , V_79 ) ;
if ( V_38 ) {
F_51 ( V_78 , V_32 , V_79 , V_80 ) ;
goto V_44;
}
F_79 ( & V_3 -> V_97 ) ;
V_38 = F_15 ( V_32 -> V_3 , V_79 , V_80 ) ;
F_80 ( & V_3 -> V_97 ) ;
V_44:
F_82 ( & V_3 -> V_90 ) ;
return V_38 ;
}
int F_92 ( struct V_77 * V_78 ,
struct V_2 * V_3 , T_1 V_79 , T_1 V_80 )
{
struct V_31 * V_32 ;
struct V_1 * V_13 ;
struct V_1 * V_26 ;
struct V_19 * V_20 ;
int V_38 = 0 ;
int V_104 ;
F_76 ( & V_3 -> V_90 ) ;
V_32 = V_3 -> V_32 ;
if ( ! V_32 ) {
V_38 = - V_99 ;
goto V_44;
}
V_26 = F_1 ( V_3 , V_79 ) ;
V_13 = F_1 ( V_3 , V_80 ) ;
if ( ! V_26 || ! V_13 ) {
V_38 = - V_99 ;
goto V_44;
}
F_18 (list, &member->groups, next_group) {
if ( V_20 -> V_27 == V_13 )
goto V_105;
}
V_38 = - V_21 ;
goto V_44;
V_105:
V_38 = F_51 ( V_78 , V_32 , V_79 , V_80 ) ;
V_104 = F_51 ( V_78 , V_32 , V_80 , V_79 ) ;
if ( V_104 && ! V_38 )
V_38 = V_104 ;
F_79 ( & V_3 -> V_97 ) ;
F_17 ( V_3 , V_79 , V_80 ) ;
F_80 ( & V_3 -> V_97 ) ;
V_44:
F_82 ( & V_3 -> V_90 ) ;
return V_38 ;
}
int F_93 ( struct V_77 * V_78 ,
struct V_2 * V_3 , T_1 V_4 , char * V_106 )
{
struct V_31 * V_32 ;
struct V_1 * V_8 ;
int V_38 = 0 ;
F_76 ( & V_3 -> V_90 ) ;
V_32 = V_3 -> V_32 ;
if ( ! V_32 ) {
V_38 = - V_99 ;
goto V_44;
}
V_8 = F_1 ( V_3 , V_4 ) ;
if ( V_8 ) {
V_38 = - V_103 ;
goto V_44;
}
V_38 = F_54 ( V_78 , V_32 , V_4 ) ;
if ( V_38 )
goto V_44;
F_79 ( & V_3 -> V_97 ) ;
V_8 = F_3 ( V_3 , V_4 ) ;
F_80 ( & V_3 -> V_97 ) ;
if ( F_30 ( V_8 ) )
V_38 = F_31 ( V_8 ) ;
V_44:
F_82 ( & V_3 -> V_90 ) ;
return V_38 ;
}
int F_94 ( struct V_77 * V_78 ,
struct V_2 * V_3 , T_1 V_4 )
{
struct V_31 * V_32 ;
struct V_1 * V_8 ;
int V_38 = 0 ;
F_76 ( & V_3 -> V_90 ) ;
V_32 = V_3 -> V_32 ;
if ( ! V_32 ) {
V_38 = - V_99 ;
goto V_44;
}
V_8 = F_1 ( V_3 , V_4 ) ;
if ( ! V_8 ) {
V_38 = - V_21 ;
goto V_44;
} else {
if ( ! F_12 ( & V_8 -> V_16 ) ||
! F_12 ( & V_8 -> V_17 ) ) {
V_38 = - V_107 ;
goto V_44;
}
}
V_38 = F_65 ( V_78 , V_32 , V_4 ) ;
F_79 ( & V_3 -> V_97 ) ;
F_9 ( V_32 -> V_3 , V_4 ) ;
F_80 ( & V_3 -> V_97 ) ;
V_44:
F_82 ( & V_3 -> V_90 ) ;
return V_38 ;
}
int F_95 ( struct V_77 * V_78 ,
struct V_2 * V_3 , T_1 V_4 ,
struct V_108 * V_109 )
{
struct V_31 * V_32 ;
struct V_1 * V_8 ;
int V_38 = 0 ;
F_76 ( & V_3 -> V_90 ) ;
V_32 = V_3 -> V_32 ;
if ( ! V_32 ) {
V_38 = - V_99 ;
goto V_44;
}
V_8 = F_1 ( V_3 , V_4 ) ;
if ( ! V_8 ) {
V_38 = - V_21 ;
goto V_44;
}
V_38 = F_66 ( V_78 , V_32 , V_4 ,
V_109 -> V_39 , V_109 -> V_67 ,
V_109 -> V_68 , V_109 -> V_69 ,
V_109 -> V_70 ) ;
if ( V_38 ) {
V_3 -> V_45 |= V_56 ;
F_26 ( V_110 L_6 ,
( unsigned long long ) V_4 ) ;
}
F_79 ( & V_3 -> V_97 ) ;
V_8 -> V_66 = V_109 -> V_39 ;
V_8 -> V_67 = V_109 -> V_67 ;
V_8 -> V_68 = V_109 -> V_68 ;
V_8 -> V_69 = V_109 -> V_69 ;
V_8 -> V_70 = V_109 -> V_70 ;
F_80 ( & V_3 -> V_97 ) ;
V_44:
F_82 ( & V_3 -> V_90 ) ;
return V_38 ;
}
int F_96 ( struct V_77 * V_78 ,
struct V_111 * V_9 ,
struct V_112 * V_113 )
{
struct V_114 * V_115 ;
F_97 ( ! V_78 -> V_116 . V_117 ) ;
V_115 = F_98 ( sizeof( * V_115 ) , V_43 ) ;
if ( ! V_115 )
return - V_15 ;
V_115 -> V_9 = V_9 ;
V_115 -> V_113 = V_113 ;
F_16 ( & V_115 -> V_20 , & V_78 -> V_118 ) ;
return 0 ;
}
static int F_99 ( struct V_2 * V_3 ,
struct V_119 * V_120 , struct V_119 * V_121 ,
T_1 V_117 )
{
struct V_122 * V_123 ;
struct V_124 V_125 ;
struct V_122 * V_126 ;
struct V_124 V_127 ;
struct V_1 * V_128 ;
int V_38 ;
F_100 ( & V_125 ) ;
while ( ( V_123 = F_101 ( V_120 , & V_125 ) ) ) {
V_128 = F_1 ( V_3 , V_123 -> V_129 ) ;
if ( ! V_128 )
continue;
F_102 ( V_121 ) ;
V_38 = F_103 ( V_121 , V_128 -> V_4 ,
( T_1 ) ( V_130 ) V_128 , V_14 ) ;
if ( V_38 < 0 )
return V_38 ;
F_100 ( & V_127 ) ;
while ( ( V_126 = F_101 ( V_121 , & V_127 ) ) ) {
struct V_19 * V_131 ;
V_128 = (struct V_1 * ) ( V_130 ) V_126 -> V_132 ;
if ( V_128 -> V_133 < V_117 )
V_128 -> V_133 = V_117 + 1 ;
else
++ V_128 -> V_133 ;
F_18 (glist, &qg->groups, next_group) {
V_38 = F_103 ( V_121 , V_131 -> V_27 -> V_4 ,
( T_1 ) ( V_130 ) V_131 -> V_27 ,
V_14 ) ;
if ( V_38 < 0 )
return V_38 ;
}
}
}
return 0 ;
}
static int F_104 ( struct V_2 * V_3 ,
struct V_119 * V_120 , struct V_119 * V_121 ,
T_1 V_117 , int V_134 , T_1 V_135 ,
struct V_1 * V_8 )
{
struct V_122 * V_123 ;
struct V_124 V_125 ;
struct V_1 * V_128 ;
struct V_19 * V_131 ;
int V_38 ;
F_102 ( V_121 ) ;
V_38 = F_103 ( V_121 , V_8 -> V_4 , ( V_130 ) V_8 , V_14 ) ;
if ( V_38 < 0 )
return V_38 ;
F_100 ( & V_125 ) ;
while ( ( V_123 = F_101 ( V_121 , & V_125 ) ) ) {
V_128 = (struct V_1 * ) ( V_130 ) V_123 -> V_132 ;
if ( V_128 -> V_133 < V_117 ) {
V_128 -> V_61 += V_134 * V_135 ;
V_128 -> V_62 += V_134 * V_135 ;
if ( V_120 -> V_136 == 0 ) {
V_128 -> V_63 += V_134 * V_135 ;
V_128 -> V_64 += V_134 * V_135 ;
}
F_89 ( V_3 , V_128 ) ;
}
F_105 ( V_128 -> V_137 >= V_117 ) ;
V_128 -> V_137 = V_117 ;
F_18 (glist, &qg->groups, next_group) {
V_38 = F_103 ( V_121 , V_131 -> V_27 -> V_4 ,
( V_130 ) V_131 -> V_27 , V_14 ) ;
if ( V_38 < 0 )
return V_38 ;
}
}
return 0 ;
}
static int F_106 ( struct V_2 * V_3 ,
struct V_119 * V_120 , struct V_119 * V_121 ,
T_1 V_117 , int V_134 , T_1 V_135 )
{
struct V_122 * V_123 ;
struct V_124 V_125 ;
struct V_1 * V_128 ;
struct V_122 * V_126 ;
struct V_124 V_127 ;
int V_38 ;
F_100 ( & V_125 ) ;
while ( ( V_123 = F_101 ( V_120 , & V_125 ) ) ) {
V_128 = F_1 ( V_3 , V_123 -> V_129 ) ;
if ( ! V_128 )
continue;
F_102 ( V_121 ) ;
V_38 = F_103 ( V_121 , V_128 -> V_4 , ( V_130 ) V_128 , V_14 ) ;
if ( V_38 < 0 )
return V_38 ;
F_100 ( & V_127 ) ;
while ( ( V_126 = F_101 ( V_121 , & V_127 ) ) ) {
struct V_19 * V_131 ;
V_128 = (struct V_1 * ) ( V_130 ) V_126 -> V_132 ;
if ( V_128 -> V_137 == V_117 )
continue;
if ( V_128 -> V_133 - V_117 == V_120 -> V_136 ) {
V_128 -> V_63 -= V_134 * V_135 ;
V_128 -> V_64 -= V_134 * V_135 ;
F_89 ( V_3 , V_128 ) ;
}
F_18 (glist, &qg->groups, next_group) {
V_38 = F_103 ( V_121 , V_131 -> V_27 -> V_4 ,
( V_130 ) V_131 -> V_27 ,
V_14 ) ;
if ( V_38 < 0 )
return V_38 ;
}
}
}
return 0 ;
}
int F_107 ( struct V_77 * V_78 ,
struct V_2 * V_3 ,
struct V_111 * V_9 ,
struct V_112 * V_113 )
{
struct V_28 V_138 ;
struct V_31 * V_32 ;
T_1 V_139 ;
struct V_1 * V_8 ;
struct V_119 * V_120 = NULL ;
T_1 V_117 ;
int V_38 = 0 ;
int V_134 ;
if ( ! V_3 -> V_41 )
return 0 ;
F_97 ( ! V_3 -> V_32 ) ;
V_138 . V_46 = V_9 -> V_140 ;
V_138 . V_47 = V_9 -> V_135 ;
V_138 . type = V_141 ;
if ( V_9 -> type == V_142 ||
V_9 -> type == V_143 ) {
struct V_144 * V_145 ;
V_145 = F_108 ( V_9 ) ;
V_139 = V_145 -> V_85 ;
} else if ( V_9 -> type == V_146 ||
V_9 -> type == V_147 ) {
struct V_148 * V_145 ;
V_145 = F_109 ( V_9 ) ;
V_139 = V_145 -> V_85 ;
} else {
F_110 () ;
}
if ( ! F_111 ( V_139 ) ) {
return 0 ;
}
switch ( V_9 -> V_149 ) {
case V_150 :
case V_151 :
V_134 = 1 ;
V_117 = F_112 ( V_9 -> V_117 ) ;
break;
case V_152 :
V_134 = - 1 ;
V_117 = V_9 -> V_117 ;
break;
case V_153 :
return 0 ;
default:
F_110 () ;
}
F_76 ( & V_3 -> V_154 ) ;
if ( V_3 -> V_45 & V_76 ) {
if ( V_3 -> V_86 . V_46 <= V_9 -> V_140 ) {
F_82 ( & V_3 -> V_154 ) ;
return 0 ;
}
}
F_82 ( & V_3 -> V_154 ) ;
V_38 = F_113 ( V_78 , V_3 , V_9 -> V_140 , V_117 , & V_120 ) ;
if ( V_38 < 0 )
return V_38 ;
F_79 ( & V_3 -> V_97 ) ;
V_32 = V_3 -> V_32 ;
if ( ! V_32 )
goto V_155;
V_8 = F_1 ( V_3 , V_139 ) ;
if ( ! V_8 )
goto V_155;
F_102 ( V_3 -> V_42 ) ;
V_117 = V_3 -> V_156 ;
V_3 -> V_156 += V_120 -> V_136 + 1 ;
V_38 = F_99 ( V_3 , V_120 , V_3 -> V_42 ,
V_117 ) ;
if ( V_38 )
goto V_155;
V_38 = F_104 ( V_3 , V_120 , V_3 -> V_42 ,
V_117 , V_134 , V_9 -> V_135 , V_8 ) ;
if ( V_38 )
goto V_155;
V_38 = F_106 ( V_3 , V_120 , V_3 -> V_42 ,
V_117 , V_134 , V_9 -> V_135 ) ;
if ( V_38 )
goto V_155;
V_155:
F_80 ( & V_3 -> V_97 ) ;
F_45 ( V_120 ) ;
return V_38 ;
}
int F_114 ( struct V_77 * V_78 ,
struct V_2 * V_3 )
{
struct V_31 * V_32 = V_3 -> V_32 ;
int V_38 = 0 ;
int V_157 = 0 ;
if ( ! V_32 )
goto V_44;
if ( ! V_3 -> V_41 && V_3 -> V_75 )
V_157 = 1 ;
V_3 -> V_41 = V_3 -> V_75 ;
F_79 ( & V_3 -> V_97 ) ;
while ( ! F_12 ( & V_3 -> V_102 ) ) {
struct V_1 * V_8 ;
V_8 = F_13 ( & V_3 -> V_102 ,
struct V_1 , V_18 ) ;
F_115 ( & V_8 -> V_18 ) ;
F_80 ( & V_3 -> V_97 ) ;
V_38 = F_67 ( V_78 , V_32 , V_8 ) ;
if ( V_38 )
V_3 -> V_45 |=
V_56 ;
F_79 ( & V_3 -> V_97 ) ;
}
if ( V_3 -> V_41 )
V_3 -> V_45 |= V_74 ;
else
V_3 -> V_45 &= ~ V_74 ;
F_80 ( & V_3 -> V_97 ) ;
V_38 = F_68 ( V_78 , V_3 , V_32 ) ;
if ( V_38 )
V_3 -> V_45 |= V_56 ;
if ( ! V_38 && V_157 ) {
V_38 = F_43 ( V_3 , 0 , 1 ) ;
if ( ! V_38 ) {
F_116 ( V_3 ) ;
F_117 ( & V_3 -> V_158 ,
& V_3 -> V_159 ) ;
}
V_38 = 0 ;
}
V_44:
return V_38 ;
}
int F_118 ( struct V_77 * V_78 ,
struct V_2 * V_3 , T_1 V_160 , T_1 V_46 ,
struct F_118 * V_161 )
{
int V_38 = 0 ;
int V_162 ;
T_1 * V_163 ;
struct V_31 * V_32 = V_3 -> V_32 ;
struct V_1 * V_164 ;
struct V_1 * V_165 ;
T_2 V_166 = 0 ;
T_1 V_167 ;
F_76 ( & V_3 -> V_90 ) ;
if ( ! V_3 -> V_41 )
goto V_44;
if ( ! V_32 ) {
V_38 = - V_99 ;
goto V_44;
}
if ( V_161 ) {
V_163 = ( T_1 * ) ( V_161 + 1 ) ;
V_167 = V_161 -> V_168 + 2 * V_161 -> V_169 +
2 * V_161 -> V_170 ;
for ( V_162 = 0 ; V_162 < V_167 ; ++ V_162 ) {
V_164 = F_1 ( V_3 , * V_163 ) ;
if ( ! V_164 ) {
V_38 = - V_99 ;
goto V_44;
}
++ V_163 ;
}
}
V_38 = F_54 ( V_78 , V_32 , V_46 ) ;
if ( V_38 )
goto V_44;
if ( V_161 && V_161 -> V_39 & V_171 ) {
V_38 = F_66 ( V_78 , V_32 , V_46 ,
V_161 -> V_172 . V_39 ,
V_161 -> V_172 . V_67 ,
V_161 -> V_172 . V_68 ,
V_161 -> V_172 . V_69 ,
V_161 -> V_172 . V_70 ) ;
if ( V_38 )
goto V_44;
}
if ( V_160 ) {
struct V_31 * V_173 ;
struct V_28 V_174 ;
int V_175 ;
V_174 . V_46 = V_160 ;
V_174 . type = V_176 ;
V_174 . V_47 = ( T_1 ) - 1 ;
V_173 = F_119 ( V_3 , & V_174 ) ;
if ( F_30 ( V_173 ) ) {
V_38 = F_31 ( V_173 ) ;
goto V_44;
}
F_120 () ;
V_175 = F_121 ( V_173 -> V_9 ) ;
V_166 = F_122 ( V_173 , V_175 ) ;
F_123 () ;
}
if ( V_161 ) {
V_163 = ( T_1 * ) ( V_161 + 1 ) ;
for ( V_162 = 0 ; V_162 < V_161 -> V_168 ; ++ V_162 ) {
V_38 = F_48 ( V_78 , V_32 ,
V_46 , * V_163 ) ;
if ( V_38 )
goto V_44;
V_38 = F_48 ( V_78 , V_32 ,
* V_163 , V_46 ) ;
if ( V_38 )
goto V_44;
++ V_163 ;
}
}
F_79 ( & V_3 -> V_97 ) ;
V_165 = F_3 ( V_3 , V_46 ) ;
if ( F_30 ( V_165 ) ) {
V_38 = F_31 ( V_165 ) ;
goto V_155;
}
if ( V_160 ) {
V_164 = F_1 ( V_3 , V_160 ) ;
if ( ! V_164 )
goto V_155;
V_165 -> V_61 = V_164 -> V_61 - V_166 ;
V_165 -> V_62 = V_164 -> V_62 - V_166 ;
V_164 -> V_63 = V_166 ;
V_164 -> V_64 = V_166 ;
F_89 ( V_3 , V_165 ) ;
F_89 ( V_3 , V_164 ) ;
}
if ( ! V_161 )
goto V_155;
V_163 = ( T_1 * ) ( V_161 + 1 ) ;
for ( V_162 = 0 ; V_162 < V_161 -> V_168 ; ++ V_162 ) {
V_38 = F_15 ( V_32 -> V_3 , V_46 ,
* V_163 ) ;
if ( V_38 )
goto V_155;
++ V_163 ;
}
for ( V_162 = 0 ; V_162 < V_161 -> V_169 ; ++ V_162 ) {
struct V_1 * V_79 ;
struct V_1 * V_80 ;
V_79 = F_1 ( V_3 , V_163 [ 0 ] ) ;
V_80 = F_1 ( V_3 , V_163 [ 1 ] ) ;
if ( ! V_79 || ! V_80 ) {
V_38 = - V_99 ;
goto V_155;
}
V_80 -> V_61 = V_79 -> V_61 - V_166 ;
V_80 -> V_62 = V_79 -> V_62 - V_166 ;
V_163 += 2 ;
}
for ( V_162 = 0 ; V_162 < V_161 -> V_170 ; ++ V_162 ) {
struct V_1 * V_79 ;
struct V_1 * V_80 ;
V_79 = F_1 ( V_3 , V_163 [ 0 ] ) ;
V_80 = F_1 ( V_3 , V_163 [ 1 ] ) ;
if ( ! V_79 || ! V_80 ) {
V_38 = - V_99 ;
goto V_155;
}
V_80 -> V_63 = V_79 -> V_63 + V_166 ;
V_80 -> V_64 = V_79 -> V_64 + V_166 ;
V_163 += 2 ;
}
V_155:
F_80 ( & V_3 -> V_97 ) ;
V_44:
F_82 ( & V_3 -> V_90 ) ;
return V_38 ;
}
int F_124 ( struct V_31 * V_85 , T_1 V_135 )
{
struct V_31 * V_32 ;
struct V_1 * V_8 ;
struct V_2 * V_3 = V_85 -> V_3 ;
T_1 V_139 = V_85 -> V_100 . V_46 ;
int V_38 = 0 ;
struct V_122 * V_123 ;
struct V_124 V_125 ;
if ( ! F_111 ( V_139 ) )
return 0 ;
if ( V_135 == 0 )
return 0 ;
F_79 ( & V_3 -> V_97 ) ;
V_32 = V_3 -> V_32 ;
if ( ! V_32 )
goto V_44;
V_8 = F_1 ( V_3 , V_139 ) ;
if ( ! V_8 )
goto V_44;
F_102 ( V_3 -> V_42 ) ;
V_38 = F_103 ( V_3 -> V_42 , V_8 -> V_4 ,
( V_130 ) V_8 , V_14 ) ;
if ( V_38 < 0 )
goto V_44;
F_100 ( & V_125 ) ;
while ( ( V_123 = F_101 ( V_3 -> V_42 , & V_125 ) ) ) {
struct V_1 * V_128 ;
struct V_19 * V_131 ;
V_128 = (struct V_1 * ) ( V_130 ) V_123 -> V_132 ;
if ( ( V_128 -> V_66 & V_177 ) &&
V_128 -> V_178 + ( V_179 ) V_128 -> V_61 + V_135 >
V_128 -> V_67 ) {
V_38 = - V_180 ;
goto V_44;
}
if ( ( V_128 -> V_66 & V_181 ) &&
V_128 -> V_178 + ( V_179 ) V_128 -> V_63 + V_135 >
V_128 -> V_68 ) {
V_38 = - V_180 ;
goto V_44;
}
F_18 (glist, &qg->groups, next_group) {
V_38 = F_103 ( V_3 -> V_42 ,
V_131 -> V_27 -> V_4 ,
( V_130 ) V_131 -> V_27 , V_14 ) ;
if ( V_38 < 0 )
goto V_44;
}
}
V_38 = 0 ;
F_100 ( & V_125 ) ;
while ( ( V_123 = F_101 ( V_3 -> V_42 , & V_125 ) ) ) {
struct V_1 * V_128 ;
V_128 = (struct V_1 * ) ( V_130 ) V_123 -> V_132 ;
V_128 -> V_178 += V_135 ;
}
V_44:
F_80 ( & V_3 -> V_97 ) ;
return V_38 ;
}
void F_125 ( struct V_31 * V_85 , T_1 V_135 )
{
struct V_31 * V_32 ;
struct V_1 * V_8 ;
struct V_2 * V_3 = V_85 -> V_3 ;
struct V_122 * V_123 ;
struct V_124 V_125 ;
T_1 V_139 = V_85 -> V_100 . V_46 ;
int V_38 = 0 ;
if ( ! F_111 ( V_139 ) )
return;
if ( V_135 == 0 )
return;
F_79 ( & V_3 -> V_97 ) ;
V_32 = V_3 -> V_32 ;
if ( ! V_32 )
goto V_44;
V_8 = F_1 ( V_3 , V_139 ) ;
if ( ! V_8 )
goto V_44;
F_102 ( V_3 -> V_42 ) ;
V_38 = F_103 ( V_3 -> V_42 , V_8 -> V_4 ,
( V_130 ) V_8 , V_14 ) ;
if ( V_38 < 0 )
goto V_44;
F_100 ( & V_125 ) ;
while ( ( V_123 = F_101 ( V_3 -> V_42 , & V_125 ) ) ) {
struct V_1 * V_128 ;
struct V_19 * V_131 ;
V_128 = (struct V_1 * ) ( V_130 ) V_123 -> V_132 ;
V_128 -> V_178 -= V_135 ;
F_18 (glist, &qg->groups, next_group) {
V_38 = F_103 ( V_3 -> V_42 ,
V_131 -> V_27 -> V_4 ,
( V_130 ) V_131 -> V_27 , V_14 ) ;
if ( V_38 < 0 )
goto V_44;
}
}
V_44:
F_80 ( & V_3 -> V_97 ) ;
}
void F_126 ( struct V_77 * V_78 )
{
if ( F_12 ( & V_78 -> V_118 ) && ! V_78 -> V_116 . V_117 )
return;
F_127 ( L_7 ,
V_78 , F_12 ( & V_78 -> V_118 ) ? L_8 : L_9 ,
( T_2 ) ( V_78 -> V_116 . V_117 >> 32 ) ,
( T_2 ) V_78 -> V_116 . V_117 ) ;
F_110 () ;
}
static int
F_128 ( struct V_2 * V_3 , struct V_33 * V_34 ,
struct V_77 * V_78 , struct V_119 * V_121 ,
struct V_35 * V_182 )
{
struct V_28 V_183 ;
struct V_119 * V_120 = NULL ;
struct V_122 * V_123 ;
struct V_124 V_125 ;
struct V_184 V_185 = {} ;
T_1 V_117 ;
int V_37 ;
int V_38 ;
V_34 -> V_88 = 1 ;
F_76 ( & V_3 -> V_154 ) ;
V_38 = F_22 ( V_3 -> V_186 ,
& V_3 -> V_86 ,
V_34 , 1 , 0 ) ;
F_129 ( L_10 ,
( unsigned long long ) V_3 -> V_86 . V_46 ,
V_3 -> V_86 . type ,
( unsigned long long ) V_3 -> V_86 . V_47 ,
V_38 ) ;
if ( V_38 ) {
V_3 -> V_86 . V_46 = ( T_1 ) - 1 ;
F_42 ( V_34 ) ;
F_82 ( & V_3 -> V_154 ) ;
return V_38 ;
}
F_23 ( V_34 -> V_49 [ 0 ] , & V_183 ,
F_73 ( V_34 -> V_49 [ 0 ] ) - 1 ) ;
V_3 -> V_86 . V_46 = V_183 . V_46 + 1 ;
F_130 ( V_3 , & V_185 ) ;
memcpy ( V_182 , V_34 -> V_49 [ 0 ] , sizeof( * V_182 ) ) ;
V_37 = V_34 -> V_48 [ 0 ] ;
F_42 ( V_34 ) ;
F_82 ( & V_3 -> V_154 ) ;
for (; V_37 < F_73 ( V_182 ) ; ++ V_37 ) {
F_23 ( V_182 , & V_183 , V_37 ) ;
if ( V_183 . type != V_141 )
continue;
V_38 = F_113 ( V_78 , V_3 , V_183 . V_46 ,
V_185 . V_117 , & V_120 ) ;
if ( V_38 < 0 )
goto V_44;
F_79 ( & V_3 -> V_97 ) ;
V_117 = V_3 -> V_156 ;
V_3 -> V_156 += V_120 -> V_136 + 1 ;
V_38 = F_99 ( V_3 , V_120 , V_121 , V_117 ) ;
if ( V_38 ) {
F_80 ( & V_3 -> V_97 ) ;
F_45 ( V_120 ) ;
goto V_44;
}
F_102 ( V_121 ) ;
F_100 ( & V_125 ) ;
while ( ( V_123 = F_101 ( V_120 , & V_125 ) ) ) {
struct V_1 * V_128 ;
V_128 = F_1 ( V_3 , V_123 -> V_129 ) ;
if ( ! V_128 )
continue;
V_38 = F_103 ( V_121 , V_128 -> V_4 , ( V_130 ) V_128 ,
V_14 ) ;
if ( V_38 < 0 ) {
F_80 ( & V_3 -> V_97 ) ;
F_45 ( V_120 ) ;
goto V_44;
}
}
F_100 ( & V_125 ) ;
while ( ( V_123 = F_101 ( V_121 , & V_125 ) ) ) {
struct V_1 * V_128 ;
struct V_19 * V_131 ;
V_128 = (struct V_1 * ) ( V_130 ) V_123 -> V_132 ;
V_128 -> V_61 += V_183 . V_47 ;
V_128 -> V_62 += V_183 . V_47 ;
F_105 ( V_128 -> V_137 >= V_117 ) ;
if ( V_128 -> V_133 - V_117 == V_120 -> V_136 ) {
V_128 -> V_63 += V_183 . V_47 ;
V_128 -> V_64 += V_183 . V_47 ;
}
F_89 ( V_3 , V_128 ) ;
F_18 (glist, &qg->groups, next_group) {
V_38 = F_103 ( V_121 , V_131 -> V_27 -> V_4 ,
( V_130 ) V_131 -> V_27 ,
V_14 ) ;
if ( V_38 < 0 ) {
F_80 ( & V_3 -> V_97 ) ;
F_45 ( V_120 ) ;
goto V_44;
}
}
}
F_80 ( & V_3 -> V_97 ) ;
F_45 ( V_120 ) ;
V_38 = 0 ;
}
V_44:
F_131 ( V_3 , & V_185 ) ;
return V_38 ;
}
static void F_132 ( struct V_187 * V_188 )
{
struct V_2 * V_3 = F_133 ( V_188 , struct V_2 ,
V_159 ) ;
struct V_33 * V_34 ;
struct V_77 * V_78 = NULL ;
struct V_119 * V_121 = NULL ;
struct V_35 * V_182 = NULL ;
int V_104 = - V_15 ;
V_34 = F_21 () ;
if ( ! V_34 )
goto V_44;
V_121 = F_20 ( V_43 ) ;
if ( ! V_121 )
goto V_44;
V_182 = F_98 ( sizeof( * V_182 ) , V_43 ) ;
if ( ! V_182 )
goto V_44;
V_104 = 0 ;
while ( ! V_104 ) {
V_78 = F_134 ( V_3 -> V_189 , 0 ) ;
if ( F_30 ( V_78 ) ) {
V_104 = F_31 ( V_78 ) ;
break;
}
if ( ! V_3 -> V_41 ) {
V_104 = - V_190 ;
} else {
V_104 = F_128 ( V_3 , V_34 , V_78 ,
V_121 , V_182 ) ;
}
if ( V_104 > 0 )
F_135 ( V_78 , V_3 -> V_189 ) ;
else
F_136 ( V_78 , V_3 -> V_189 ) ;
}
V_44:
F_14 ( V_182 ) ;
F_45 ( V_121 ) ;
F_44 ( V_34 ) ;
F_76 ( & V_3 -> V_154 ) ;
V_3 -> V_45 &= ~ V_76 ;
if ( V_104 == 2 &&
V_3 -> V_45 & V_56 ) {
V_3 -> V_45 &= ~ V_56 ;
} else if ( V_104 < 0 ) {
V_3 -> V_45 |= V_56 ;
}
F_82 ( & V_3 -> V_154 ) ;
if ( V_104 >= 0 ) {
F_137 ( L_11 ,
V_104 == 2 ? L_12 : L_8 ) ;
} else {
F_127 ( L_13 , V_104 ) ;
}
F_138 ( & V_3 -> V_191 ) ;
}
static int
F_43 ( struct V_2 * V_3 , T_1 V_192 ,
int V_193 )
{
int V_38 = 0 ;
if ( ! V_193 &&
( ! ( V_3 -> V_45 & V_76 ) ||
! ( V_3 -> V_45 & V_74 ) ) ) {
V_38 = - V_99 ;
goto V_104;
}
F_76 ( & V_3 -> V_154 ) ;
F_79 ( & V_3 -> V_97 ) ;
if ( V_193 ) {
if ( V_3 -> V_45 & V_76 )
V_38 = - V_194 ;
else if ( ! ( V_3 -> V_45 & V_74 ) )
V_38 = - V_99 ;
if ( V_38 ) {
F_80 ( & V_3 -> V_97 ) ;
F_82 ( & V_3 -> V_154 ) ;
goto V_104;
}
V_3 -> V_45 |= V_76 ;
}
memset ( & V_3 -> V_86 , 0 ,
sizeof( V_3 -> V_86 ) ) ;
V_3 -> V_86 . V_46 = V_192 ;
F_80 ( & V_3 -> V_97 ) ;
F_82 ( & V_3 -> V_154 ) ;
F_139 ( & V_3 -> V_191 ) ;
memset ( & V_3 -> V_159 , 0 ,
sizeof( V_3 -> V_159 ) ) ;
V_3 -> V_159 . V_195 = F_132 ;
if ( V_38 ) {
V_104:
F_137 ( L_14 , V_38 ) ;
return V_38 ;
}
return 0 ;
}
static void
F_116 ( struct V_2 * V_3 )
{
struct V_5 * V_6 ;
struct V_1 * V_8 ;
F_79 ( & V_3 -> V_97 ) ;
for ( V_6 = F_47 ( & V_3 -> V_7 ) ; V_6 ; V_6 = F_140 ( V_6 ) ) {
V_8 = F_2 ( V_6 , struct V_1 , V_9 ) ;
V_8 -> V_61 = 0 ;
V_8 -> V_62 = 0 ;
V_8 -> V_63 = 0 ;
V_8 -> V_64 = 0 ;
}
F_80 ( & V_3 -> V_97 ) ;
}
int
F_141 ( struct V_2 * V_3 )
{
int V_38 = 0 ;
struct V_77 * V_78 ;
V_38 = F_43 ( V_3 , 0 , 1 ) ;
if ( V_38 )
return V_38 ;
V_78 = F_142 ( V_3 -> V_189 ) ;
if ( F_30 ( V_78 ) ) {
V_3 -> V_45 &= ~ V_76 ;
return F_31 ( V_78 ) ;
}
V_38 = F_135 ( V_78 , V_3 -> V_189 ) ;
if ( V_38 ) {
V_3 -> V_45 &= ~ V_76 ;
return V_38 ;
}
F_116 ( V_3 ) ;
F_117 ( & V_3 -> V_158 ,
& V_3 -> V_159 ) ;
return 0 ;
}
int F_143 ( struct V_2 * V_3 )
{
int V_196 ;
int V_38 = 0 ;
F_76 ( & V_3 -> V_154 ) ;
F_79 ( & V_3 -> V_97 ) ;
V_196 = V_3 -> V_45 & V_76 ;
F_80 ( & V_3 -> V_97 ) ;
F_82 ( & V_3 -> V_154 ) ;
if ( V_196 )
V_38 = F_144 (
& V_3 -> V_191 ) ;
return V_38 ;
}
void
F_145 ( struct V_2 * V_3 )
{
if ( V_3 -> V_45 & V_76 )
F_117 ( & V_3 -> V_158 ,
& V_3 -> V_159 ) ;
}
