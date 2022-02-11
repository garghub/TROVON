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
if ( ! ( V_3 -> V_42 & V_70 ) ) {
V_3 -> V_40 = 0 ;
V_3 -> V_71 = 0 ;
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
static int F_45 ( struct V_72 * V_73 ,
struct V_31 * V_32 ,
T_1 V_74 , T_1 V_75 )
{
int V_38 ;
struct V_33 * V_34 ;
struct V_28 V_29 ;
V_34 = F_20 () ;
if ( ! V_34 )
return - V_15 ;
V_29 . V_43 = V_74 ;
V_29 . type = V_68 ;
V_29 . V_44 = V_75 ;
V_38 = F_46 ( V_73 , V_32 , V_34 , & V_29 , 0 ) ;
F_47 ( V_34 -> V_46 [ 0 ] ) ;
F_41 ( V_34 ) ;
return V_38 ;
}
static int F_48 ( struct V_72 * V_73 ,
struct V_31 * V_32 ,
T_1 V_74 , T_1 V_75 )
{
int V_38 ;
struct V_33 * V_34 ;
struct V_28 V_29 ;
V_34 = F_20 () ;
if ( ! V_34 )
return - V_15 ;
V_29 . V_43 = V_74 ;
V_29 . type = V_68 ;
V_29 . V_44 = V_75 ;
V_38 = F_49 ( V_73 , V_32 , & V_29 , V_34 , - 1 , 1 ) ;
if ( V_38 < 0 )
goto V_41;
if ( V_38 > 0 ) {
V_38 = - V_21 ;
goto V_41;
}
V_38 = F_50 ( V_73 , V_32 , V_34 ) ;
V_41:
F_41 ( V_34 ) ;
return V_38 ;
}
static int F_51 ( struct V_72 * V_73 ,
struct V_31 * V_32 , T_1 V_4 )
{
int V_38 ;
struct V_33 * V_34 ;
struct V_57 * V_76 ;
struct V_62 * V_77 ;
struct V_35 * V_78 ;
struct V_28 V_29 ;
V_34 = F_20 () ;
if ( ! V_34 )
return - V_15 ;
V_29 . V_43 = 0 ;
V_29 . type = V_55 ;
V_29 . V_44 = V_4 ;
V_38 = F_46 ( V_73 , V_32 , V_34 , & V_29 ,
sizeof( * V_76 ) ) ;
if ( V_38 )
goto V_41;
V_78 = V_34 -> V_46 [ 0 ] ;
V_76 = F_23 ( V_78 , V_34 -> V_45 [ 0 ] ,
struct V_57 ) ;
F_52 ( V_78 , V_76 , V_73 -> V_79 ) ;
F_53 ( V_78 , V_76 , 0 ) ;
F_54 ( V_78 , V_76 , 0 ) ;
F_55 ( V_78 , V_76 , 0 ) ;
F_56 ( V_78 , V_76 , 0 ) ;
F_47 ( V_78 ) ;
F_40 ( V_34 ) ;
V_29 . type = V_56 ;
V_38 = F_46 ( V_73 , V_32 , V_34 , & V_29 ,
sizeof( * V_77 ) ) ;
if ( V_38 )
goto V_41;
V_78 = V_34 -> V_46 [ 0 ] ;
V_77 = F_23 ( V_78 , V_34 -> V_45 [ 0 ] ,
struct V_62 ) ;
F_57 ( V_78 , V_77 , 0 ) ;
F_58 ( V_78 , V_77 , 0 ) ;
F_59 ( V_78 , V_77 , 0 ) ;
F_60 ( V_78 , V_77 , 0 ) ;
F_61 ( V_78 , V_77 , 0 ) ;
F_47 ( V_78 ) ;
V_38 = 0 ;
V_41:
F_41 ( V_34 ) ;
return V_38 ;
}
static int F_62 ( struct V_72 * V_73 ,
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
V_38 = F_49 ( V_73 , V_32 , & V_29 , V_34 , - 1 , 1 ) ;
if ( V_38 < 0 )
goto V_41;
if ( V_38 > 0 ) {
V_38 = - V_21 ;
goto V_41;
}
V_38 = F_50 ( V_73 , V_32 , V_34 ) ;
if ( V_38 )
goto V_41;
F_40 ( V_34 ) ;
V_29 . type = V_56 ;
V_38 = F_49 ( V_73 , V_32 , & V_29 , V_34 , - 1 , 1 ) ;
if ( V_38 < 0 )
goto V_41;
if ( V_38 > 0 ) {
V_38 = - V_21 ;
goto V_41;
}
V_38 = F_50 ( V_73 , V_32 , V_34 ) ;
V_41:
F_41 ( V_34 ) ;
return V_38 ;
}
static int F_63 ( struct V_72 * V_73 ,
struct V_31 * V_80 , T_1 V_4 ,
T_1 V_39 , T_1 V_64 , T_1 V_65 ,
T_1 V_66 , T_1 V_67 )
{
struct V_33 * V_34 ;
struct V_28 V_29 ;
struct V_35 * V_36 ;
struct V_62 * V_77 ;
int V_38 ;
int V_37 ;
V_29 . V_43 = 0 ;
V_29 . type = V_56 ;
V_29 . V_44 = V_4 ;
V_34 = F_20 () ;
F_64 ( ! V_34 ) ;
V_38 = F_49 ( V_73 , V_80 , & V_29 , V_34 , 0 , 1 ) ;
if ( V_38 > 0 )
V_38 = - V_21 ;
if ( V_38 )
goto V_41;
V_36 = V_34 -> V_46 [ 0 ] ;
V_37 = V_34 -> V_45 [ 0 ] ;
V_77 = F_23 ( V_36 , V_34 -> V_45 [ 0 ] ,
struct V_62 ) ;
F_57 ( V_36 , V_77 , V_39 ) ;
F_58 ( V_36 , V_77 , V_64 ) ;
F_59 ( V_36 , V_77 , V_65 ) ;
F_60 ( V_36 , V_77 , V_66 ) ;
F_61 ( V_36 , V_77 , V_67 ) ;
F_47 ( V_36 ) ;
V_41:
F_41 ( V_34 ) ;
return V_38 ;
}
static int F_65 ( struct V_72 * V_73 ,
struct V_31 * V_80 ,
struct V_1 * V_8 )
{
struct V_33 * V_34 ;
struct V_28 V_29 ;
struct V_35 * V_36 ;
struct V_57 * V_76 ;
int V_38 ;
int V_37 ;
V_29 . V_43 = 0 ;
V_29 . type = V_55 ;
V_29 . V_44 = V_8 -> V_4 ;
V_34 = F_20 () ;
F_64 ( ! V_34 ) ;
V_38 = F_49 ( V_73 , V_80 , & V_29 , V_34 , 0 , 1 ) ;
if ( V_38 > 0 )
V_38 = - V_21 ;
if ( V_38 )
goto V_41;
V_36 = V_34 -> V_46 [ 0 ] ;
V_37 = V_34 -> V_45 [ 0 ] ;
V_76 = F_23 ( V_36 , V_34 -> V_45 [ 0 ] ,
struct V_57 ) ;
F_52 ( V_36 , V_76 , V_73 -> V_79 ) ;
F_53 ( V_36 , V_76 , V_8 -> V_58 ) ;
F_54 ( V_36 , V_76 , V_8 -> V_59 ) ;
F_55 ( V_36 , V_76 , V_8 -> V_60 ) ;
F_56 ( V_36 , V_76 , V_8 -> V_61 ) ;
F_47 ( V_36 ) ;
V_41:
F_41 ( V_34 ) ;
return V_38 ;
}
static int F_66 ( struct V_72 * V_73 ,
struct V_2 * V_3 ,
struct V_31 * V_80 )
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
F_64 ( ! V_34 ) ;
V_38 = F_49 ( V_73 , V_80 , & V_29 , V_34 , 0 , 1 ) ;
if ( V_38 > 0 )
V_38 = - V_21 ;
if ( V_38 )
goto V_41;
V_36 = V_34 -> V_46 [ 0 ] ;
V_37 = V_34 -> V_45 [ 0 ] ;
V_49 = F_23 ( V_36 , V_37 , struct V_48 ) ;
F_67 ( V_36 , V_49 , V_3 -> V_42 ) ;
F_68 ( V_36 , V_49 , V_73 -> V_79 ) ;
F_47 ( V_36 ) ;
V_41:
F_41 ( V_34 ) ;
return V_38 ;
}
static int F_69 ( struct V_72 * V_73 ,
struct V_31 * V_80 )
{
struct V_33 * V_34 ;
struct V_28 V_29 ;
int V_38 ;
if ( ! V_80 )
return - V_81 ;
V_34 = F_20 () ;
if ( ! V_34 )
return - V_15 ;
while ( 1 ) {
V_29 . V_43 = 0 ;
V_29 . V_44 = 0 ;
V_29 . type = 0 ;
V_34 -> V_82 = 1 ;
V_38 = F_49 ( V_73 , V_80 , & V_29 , V_34 , - 1 , 1 ) ;
if ( V_38 > 0 ) {
if ( V_34 -> V_45 [ 0 ] == 0 )
break;
V_34 -> V_45 [ 0 ] -- ;
} else if ( V_38 < 0 ) {
break;
}
V_38 = F_50 ( V_73 , V_80 , V_34 ) ;
if ( V_38 )
goto V_41;
F_40 ( V_34 ) ;
}
V_38 = 0 ;
V_41:
V_80 -> V_3 -> V_71 = 0 ;
F_41 ( V_34 ) ;
return V_38 ;
}
int F_70 ( struct V_72 * V_73 ,
struct V_2 * V_3 )
{
struct V_31 * V_32 ;
struct V_33 * V_34 = NULL ;
struct V_48 * V_49 ;
struct V_35 * V_78 ;
struct V_28 V_29 ;
int V_38 = 0 ;
F_71 ( & V_3 -> V_83 ) ;
if ( V_3 -> V_32 ) {
V_3 -> V_71 = 1 ;
F_72 ( & V_3 -> V_83 ) ;
goto V_41;
}
F_72 ( & V_3 -> V_83 ) ;
V_32 = F_73 ( V_73 , V_3 ,
V_84 ) ;
if ( F_28 ( V_32 ) ) {
V_38 = F_29 ( V_32 ) ;
goto V_41;
}
V_34 = F_20 () ;
if ( ! V_34 )
return - V_15 ;
V_29 . V_43 = 0 ;
V_29 . type = V_47 ;
V_29 . V_44 = 0 ;
V_38 = F_46 ( V_73 , V_32 , V_34 , & V_29 ,
sizeof( * V_49 ) ) ;
if ( V_38 )
goto V_41;
V_78 = V_34 -> V_46 [ 0 ] ;
V_49 = F_23 ( V_78 , V_34 -> V_45 [ 0 ] ,
struct V_48 ) ;
F_68 ( V_78 , V_49 , V_73 -> V_79 ) ;
F_74 ( V_78 , V_49 , V_50 ) ;
V_3 -> V_42 = V_70 |
V_53 ;
F_67 ( V_78 , V_49 , V_3 -> V_42 ) ;
F_75 ( V_78 , V_49 , 0 ) ;
F_47 ( V_78 ) ;
F_71 ( & V_3 -> V_83 ) ;
V_3 -> V_32 = V_32 ;
V_3 -> V_71 = 1 ;
F_72 ( & V_3 -> V_83 ) ;
V_41:
F_41 ( V_34 ) ;
return V_38 ;
}
int F_76 ( struct V_72 * V_73 ,
struct V_2 * V_3 )
{
struct V_31 * V_85 = V_3 -> V_85 ;
struct V_31 * V_32 ;
int V_38 = 0 ;
F_71 ( & V_3 -> V_83 ) ;
V_3 -> V_40 = 0 ;
V_3 -> V_71 = 0 ;
V_32 = V_3 -> V_32 ;
V_3 -> V_32 = NULL ;
F_42 ( V_3 ) ;
F_72 ( & V_3 -> V_83 ) ;
if ( ! V_32 )
return - V_81 ;
V_38 = F_69 ( V_73 , V_32 ) ;
if ( V_38 )
goto V_41;
V_38 = F_77 ( V_73 , V_85 , & V_32 -> V_86 ) ;
if ( V_38 )
goto V_41;
F_11 ( & V_32 -> V_87 ) ;
F_78 ( V_32 -> V_9 ) ;
F_79 ( V_73 , V_85 , V_32 -> V_9 ) ;
F_80 ( V_32 -> V_9 ) ;
F_81 ( V_73 , V_32 , V_32 -> V_9 , 0 , 1 ) ;
F_82 ( V_32 -> V_9 ) ;
F_82 ( V_32 -> V_88 ) ;
F_14 ( V_32 ) ;
V_41:
return V_38 ;
}
int F_83 ( struct V_2 * V_3 )
{
return 0 ;
}
int F_84 ( struct V_72 * V_73 ,
struct V_2 * V_3 , T_1 V_74 , T_1 V_75 )
{
struct V_31 * V_32 ;
int V_38 = 0 ;
V_32 = V_3 -> V_32 ;
if ( ! V_32 )
return - V_81 ;
V_38 = F_45 ( V_73 , V_32 , V_74 , V_75 ) ;
if ( V_38 )
return V_38 ;
V_38 = F_45 ( V_73 , V_32 , V_75 , V_74 ) ;
if ( V_38 ) {
F_48 ( V_73 , V_32 , V_74 , V_75 ) ;
return V_38 ;
}
F_71 ( & V_3 -> V_83 ) ;
V_38 = F_15 ( V_32 -> V_3 , V_74 , V_75 ) ;
F_72 ( & V_3 -> V_83 ) ;
return V_38 ;
}
int F_85 ( struct V_72 * V_73 ,
struct V_2 * V_3 , T_1 V_74 , T_1 V_75 )
{
struct V_31 * V_32 ;
int V_38 = 0 ;
int V_89 ;
V_32 = V_3 -> V_32 ;
if ( ! V_32 )
return - V_81 ;
V_38 = F_48 ( V_73 , V_32 , V_74 , V_75 ) ;
V_89 = F_48 ( V_73 , V_32 , V_75 , V_74 ) ;
if ( V_89 && ! V_38 )
V_38 = V_89 ;
F_71 ( & V_3 -> V_83 ) ;
F_17 ( V_3 , V_74 , V_75 ) ;
F_72 ( & V_3 -> V_83 ) ;
return V_38 ;
}
int F_86 ( struct V_72 * V_73 ,
struct V_2 * V_3 , T_1 V_4 , char * V_90 )
{
struct V_31 * V_32 ;
struct V_1 * V_8 ;
int V_38 = 0 ;
V_32 = V_3 -> V_32 ;
if ( ! V_32 )
return - V_81 ;
V_38 = F_51 ( V_73 , V_32 , V_4 ) ;
F_71 ( & V_3 -> V_83 ) ;
V_8 = F_3 ( V_3 , V_4 ) ;
F_72 ( & V_3 -> V_83 ) ;
if ( F_28 ( V_8 ) )
V_38 = F_29 ( V_8 ) ;
return V_38 ;
}
int F_87 ( struct V_72 * V_73 ,
struct V_2 * V_3 , T_1 V_4 )
{
struct V_31 * V_32 ;
int V_38 = 0 ;
V_32 = V_3 -> V_32 ;
if ( ! V_32 )
return - V_81 ;
V_38 = F_62 ( V_73 , V_32 , V_4 ) ;
F_71 ( & V_3 -> V_83 ) ;
F_9 ( V_32 -> V_3 , V_4 ) ;
F_72 ( & V_3 -> V_83 ) ;
return V_38 ;
}
int F_88 ( struct V_72 * V_73 ,
struct V_2 * V_3 , T_1 V_4 ,
struct V_91 * V_92 )
{
struct V_31 * V_32 = V_3 -> V_32 ;
struct V_1 * V_8 ;
int V_38 = 0 ;
if ( ! V_32 )
return - V_81 ;
V_38 = F_63 ( V_73 , V_32 , V_4 ,
V_92 -> V_39 , V_92 -> V_64 ,
V_92 -> V_65 , V_92 -> V_66 ,
V_92 -> V_67 ) ;
if ( V_38 ) {
V_3 -> V_42 |= V_53 ;
F_25 ( V_93 L_5 ,
( unsigned long long ) V_4 ) ;
}
F_71 ( & V_3 -> V_83 ) ;
V_8 = F_1 ( V_3 , V_4 ) ;
if ( ! V_8 ) {
V_38 = - V_21 ;
goto V_94;
}
V_8 -> V_63 = V_92 -> V_39 ;
V_8 -> V_64 = V_92 -> V_64 ;
V_8 -> V_65 = V_92 -> V_65 ;
V_8 -> V_66 = V_92 -> V_66 ;
V_8 -> V_67 = V_92 -> V_67 ;
V_94:
F_72 ( & V_3 -> V_83 ) ;
return V_38 ;
}
static void F_89 ( struct V_2 * V_3 ,
struct V_1 * V_8 )
{
if ( F_12 ( & V_8 -> V_18 ) )
F_90 ( & V_8 -> V_18 , & V_3 -> V_95 ) ;
}
int F_91 ( struct V_72 * V_73 ,
struct V_96 * V_9 ,
struct V_97 * V_98 )
{
struct V_99 * V_100 ;
F_64 ( ! V_73 -> V_101 . V_102 ) ;
V_100 = F_92 ( sizeof( * V_100 ) , V_103 ) ;
if ( ! V_100 )
return - V_15 ;
V_100 -> V_9 = V_9 ;
V_100 -> V_98 = V_98 ;
F_16 ( & V_100 -> V_20 , & V_73 -> V_104 ) ;
return 0 ;
}
int F_93 ( struct V_72 * V_73 ,
struct V_2 * V_3 ,
struct V_96 * V_9 ,
struct V_97 * V_98 )
{
struct V_28 V_105 ;
struct V_31 * V_32 ;
T_1 V_106 ;
struct V_1 * V_8 ;
struct V_107 * V_108 ;
struct V_109 * V_110 = NULL ;
struct V_109 * V_111 = NULL ;
struct V_112 V_113 ;
T_1 V_102 ;
int V_38 = 0 ;
int V_114 ;
if ( ! V_3 -> V_40 )
return 0 ;
F_64 ( ! V_3 -> V_32 ) ;
V_105 . V_43 = V_9 -> V_115 ;
V_105 . V_44 = V_9 -> V_116 ;
V_105 . type = V_117 ;
if ( V_9 -> type == V_118 ||
V_9 -> type == V_119 ) {
struct V_120 * V_121 ;
V_121 = F_94 ( V_9 ) ;
V_106 = V_121 -> V_80 ;
} else if ( V_9 -> type == V_122 ||
V_9 -> type == V_123 ) {
struct V_124 * V_121 ;
V_121 = F_95 ( V_9 ) ;
V_106 = V_121 -> V_80 ;
} else {
F_96 () ;
}
if ( ! F_97 ( V_106 ) ) {
return 0 ;
}
switch ( V_9 -> V_125 ) {
case V_126 :
case V_127 :
V_114 = 1 ;
break;
case V_128 :
V_114 = - 1 ;
break;
case V_129 :
return 0 ;
default:
F_96 () ;
}
V_38 = F_98 ( V_73 , V_3 , V_9 -> V_115 ,
V_114 > 0 ? V_9 -> V_102 - 1 : V_9 -> V_102 , & V_110 ) ;
if ( V_38 < 0 )
goto V_41;
F_71 ( & V_3 -> V_83 ) ;
V_32 = V_3 -> V_32 ;
if ( ! V_32 )
goto V_94;
V_8 = F_1 ( V_3 , V_106 ) ;
if ( ! V_8 )
goto V_94;
V_111 = F_99 ( V_14 ) ;
if ( ! V_111 ) {
V_38 = - V_15 ;
goto V_94;
}
V_102 = V_3 -> V_130 ;
V_3 -> V_130 += V_110 -> V_131 + 1 ;
F_100 ( & V_113 ) ;
while ( ( V_108 = F_101 ( V_110 , & V_113 ) ) ) {
struct V_107 * V_132 ;
struct V_112 V_133 ;
struct V_1 * V_134 ;
V_134 = F_1 ( V_3 , V_108 -> V_135 ) ;
if ( ! V_134 )
continue;
F_102 ( V_111 ) ;
F_103 ( V_111 , V_134 -> V_4 , ( unsigned long ) V_134 , V_14 ) ;
F_100 ( & V_133 ) ;
while ( ( V_132 = F_101 ( V_111 , & V_133 ) ) ) {
struct V_19 * V_136 ;
V_134 = (struct V_1 * ) V_132 -> V_137 ;
if ( V_134 -> V_138 < V_102 )
V_134 -> V_138 = V_102 + 1 ;
else
++ V_134 -> V_138 ;
F_18 (glist, &qg->groups, next_group) {
F_103 ( V_111 , V_136 -> V_27 -> V_4 ,
( unsigned long ) V_136 -> V_27 ,
V_14 ) ;
}
}
}
F_102 ( V_111 ) ;
F_103 ( V_111 , V_8 -> V_4 , ( unsigned long ) V_8 , V_14 ) ;
F_100 ( & V_113 ) ;
while ( ( V_108 = F_101 ( V_111 , & V_113 ) ) ) {
struct V_1 * V_134 ;
struct V_19 * V_136 ;
V_134 = (struct V_1 * ) V_108 -> V_137 ;
if ( V_134 -> V_138 < V_102 ) {
V_134 -> V_58 += V_114 * V_9 -> V_116 ;
V_134 -> V_59 += V_114 * V_9 -> V_116 ;
if ( V_110 -> V_131 == 0 ) {
V_134 -> V_60 += V_114 * V_9 -> V_116 ;
V_134 -> V_61 += V_114 * V_9 -> V_116 ;
}
F_89 ( V_3 , V_134 ) ;
}
F_44 ( V_134 -> V_139 >= V_102 ) ;
V_134 -> V_139 = V_102 ;
F_18 (glist, &qg->groups, next_group) {
F_103 ( V_111 , V_136 -> V_27 -> V_4 ,
( unsigned long ) V_136 -> V_27 , V_14 ) ;
}
}
F_100 ( & V_113 ) ;
while ( ( V_108 = F_101 ( V_110 , & V_113 ) ) ) {
struct V_1 * V_134 ;
struct V_107 * V_132 ;
struct V_112 V_133 ;
V_134 = F_1 ( V_3 , V_108 -> V_135 ) ;
if ( ! V_134 )
continue;
F_102 ( V_111 ) ;
F_103 ( V_111 , V_134 -> V_4 , ( unsigned long ) V_134 , V_14 ) ;
F_100 ( & V_133 ) ;
while ( ( V_132 = F_101 ( V_111 , & V_133 ) ) ) {
struct V_19 * V_136 ;
V_134 = (struct V_1 * ) V_132 -> V_137 ;
if ( V_134 -> V_139 == V_102 )
continue;
if ( V_134 -> V_138 - V_102 == V_110 -> V_131 ) {
V_134 -> V_60 -= V_114 * V_9 -> V_116 ;
V_134 -> V_61 -= V_114 * V_9 -> V_116 ;
F_89 ( V_3 , V_134 ) ;
}
F_18 (glist, &qg->groups, next_group) {
F_103 ( V_111 , V_136 -> V_27 -> V_4 ,
( unsigned long ) V_136 -> V_27 ,
V_14 ) ;
}
}
}
V_38 = 0 ;
V_94:
F_72 ( & V_3 -> V_83 ) ;
V_41:
F_104 ( V_110 ) ;
F_104 ( V_111 ) ;
return V_38 ;
}
int F_105 ( struct V_72 * V_73 ,
struct V_2 * V_3 )
{
struct V_31 * V_32 = V_3 -> V_32 ;
int V_38 = 0 ;
if ( ! V_32 )
goto V_41;
V_3 -> V_40 = V_3 -> V_71 ;
F_71 ( & V_3 -> V_83 ) ;
while ( ! F_12 ( & V_3 -> V_95 ) ) {
struct V_1 * V_8 ;
V_8 = F_13 ( & V_3 -> V_95 ,
struct V_1 , V_18 ) ;
F_106 ( & V_8 -> V_18 ) ;
F_72 ( & V_3 -> V_83 ) ;
V_38 = F_65 ( V_73 , V_32 , V_8 ) ;
if ( V_38 )
V_3 -> V_42 |=
V_53 ;
F_71 ( & V_3 -> V_83 ) ;
}
if ( V_3 -> V_40 )
V_3 -> V_42 |= V_70 ;
else
V_3 -> V_42 &= ~ V_70 ;
F_72 ( & V_3 -> V_83 ) ;
V_38 = F_66 ( V_73 , V_3 , V_32 ) ;
if ( V_38 )
V_3 -> V_42 |= V_53 ;
V_41:
return V_38 ;
}
int F_107 ( struct V_72 * V_73 ,
struct V_2 * V_3 , T_1 V_140 , T_1 V_43 ,
struct F_107 * V_141 )
{
int V_38 = 0 ;
int V_142 ;
T_1 * V_143 ;
struct V_31 * V_32 = V_3 -> V_32 ;
struct V_1 * V_144 ;
struct V_1 * V_145 ;
T_2 V_146 = 0 ;
if ( ! V_3 -> V_40 )
return 0 ;
if ( ! V_32 )
return - V_81 ;
V_38 = F_51 ( V_73 , V_32 , V_43 ) ;
if ( V_38 )
goto V_41;
if ( V_141 && V_141 -> V_39 & V_147 ) {
V_38 = F_63 ( V_73 , V_32 , V_43 ,
V_141 -> V_148 . V_39 ,
V_141 -> V_148 . V_64 ,
V_141 -> V_148 . V_65 ,
V_141 -> V_148 . V_66 ,
V_141 -> V_148 . V_67 ) ;
if ( V_38 )
goto V_41;
}
if ( V_140 ) {
struct V_31 * V_149 ;
struct V_28 V_150 ;
int V_151 ;
V_150 . V_43 = V_140 ;
V_150 . type = V_152 ;
V_150 . V_44 = ( T_1 ) - 1 ;
V_149 = F_108 ( V_3 , & V_150 ) ;
if ( F_28 ( V_149 ) ) {
V_38 = F_29 ( V_149 ) ;
goto V_41;
}
F_109 () ;
V_151 = F_110 ( V_149 -> V_9 ) ;
V_146 = F_111 ( V_149 , V_151 ) ;
F_112 () ;
}
if ( V_141 ) {
V_143 = ( T_1 * ) ( V_141 + 1 ) ;
for ( V_142 = 0 ; V_142 < V_141 -> V_153 ; ++ V_142 ) {
V_38 = F_45 ( V_73 , V_32 ,
V_43 , * V_143 ) ;
if ( V_38 )
goto V_41;
V_38 = F_45 ( V_73 , V_32 ,
* V_143 , V_43 ) ;
if ( V_38 )
goto V_41;
++ V_143 ;
}
}
F_71 ( & V_3 -> V_83 ) ;
V_145 = F_3 ( V_3 , V_43 ) ;
if ( F_28 ( V_145 ) ) {
V_38 = F_29 ( V_145 ) ;
goto V_94;
}
if ( V_140 ) {
V_144 = F_1 ( V_3 , V_140 ) ;
if ( ! V_144 )
goto V_94;
V_145 -> V_58 = V_144 -> V_58 - V_146 ;
V_145 -> V_59 = V_144 -> V_59 - V_146 ;
V_144 -> V_60 = V_146 ;
V_144 -> V_61 = V_146 ;
F_89 ( V_3 , V_145 ) ;
F_89 ( V_3 , V_144 ) ;
}
if ( ! V_141 )
goto V_94;
V_143 = ( T_1 * ) ( V_141 + 1 ) ;
for ( V_142 = 0 ; V_142 < V_141 -> V_153 ; ++ V_142 ) {
V_38 = F_15 ( V_32 -> V_3 , V_43 ,
* V_143 ) ;
if ( V_38 )
goto V_94;
++ V_143 ;
}
for ( V_142 = 0 ; V_142 < V_141 -> V_154 ; ++ V_142 ) {
struct V_1 * V_74 ;
struct V_1 * V_75 ;
V_74 = F_1 ( V_3 , V_143 [ 0 ] ) ;
V_75 = F_1 ( V_3 , V_143 [ 1 ] ) ;
if ( ! V_74 || ! V_75 ) {
V_38 = - V_81 ;
goto V_94;
}
V_75 -> V_58 = V_74 -> V_58 - V_146 ;
V_75 -> V_59 = V_74 -> V_59 - V_146 ;
V_143 += 2 ;
}
for ( V_142 = 0 ; V_142 < V_141 -> V_155 ; ++ V_142 ) {
struct V_1 * V_74 ;
struct V_1 * V_75 ;
V_74 = F_1 ( V_3 , V_143 [ 0 ] ) ;
V_75 = F_1 ( V_3 , V_143 [ 1 ] ) ;
if ( ! V_74 || ! V_75 ) {
V_38 = - V_81 ;
goto V_94;
}
V_75 -> V_60 = V_74 -> V_60 + V_146 ;
V_75 -> V_61 = V_74 -> V_61 + V_146 ;
V_143 += 2 ;
}
V_94:
F_72 ( & V_3 -> V_83 ) ;
V_41:
return V_38 ;
}
int F_113 ( struct V_31 * V_80 , T_1 V_116 )
{
struct V_31 * V_32 ;
struct V_1 * V_8 ;
struct V_2 * V_3 = V_80 -> V_3 ;
T_1 V_106 = V_80 -> V_86 . V_43 ;
int V_38 = 0 ;
struct V_109 * V_109 = NULL ;
struct V_107 * V_108 ;
struct V_112 V_113 ;
if ( ! F_97 ( V_106 ) )
return 0 ;
if ( V_116 == 0 )
return 0 ;
F_71 ( & V_3 -> V_83 ) ;
V_32 = V_3 -> V_32 ;
if ( ! V_32 )
goto V_41;
V_8 = F_1 ( V_3 , V_106 ) ;
if ( ! V_8 )
goto V_41;
V_109 = F_99 ( V_14 ) ;
F_103 ( V_109 , V_8 -> V_4 , ( unsigned long ) V_8 , V_14 ) ;
F_100 ( & V_113 ) ;
while ( ( V_108 = F_101 ( V_109 , & V_113 ) ) ) {
struct V_1 * V_134 ;
struct V_19 * V_136 ;
V_134 = (struct V_1 * ) V_108 -> V_137 ;
if ( ( V_134 -> V_63 & V_156 ) &&
V_134 -> V_157 + V_134 -> V_58 + V_116 >
V_134 -> V_64 )
V_38 = - V_158 ;
if ( ( V_134 -> V_63 & V_159 ) &&
V_134 -> V_157 + V_134 -> V_60 + V_116 >
V_134 -> V_65 )
V_38 = - V_158 ;
F_18 (glist, &qg->groups, next_group) {
F_103 ( V_109 , V_136 -> V_27 -> V_4 ,
( unsigned long ) V_136 -> V_27 , V_14 ) ;
}
}
if ( V_38 )
goto V_41;
F_100 ( & V_113 ) ;
while ( ( V_108 = F_101 ( V_109 , & V_113 ) ) ) {
struct V_1 * V_134 ;
V_134 = (struct V_1 * ) V_108 -> V_137 ;
V_134 -> V_157 += V_116 ;
}
V_41:
F_72 ( & V_3 -> V_83 ) ;
F_104 ( V_109 ) ;
return V_38 ;
}
void F_114 ( struct V_31 * V_80 , T_1 V_116 )
{
struct V_31 * V_32 ;
struct V_1 * V_8 ;
struct V_2 * V_3 = V_80 -> V_3 ;
struct V_109 * V_109 = NULL ;
struct V_107 * V_108 ;
struct V_112 V_113 ;
T_1 V_106 = V_80 -> V_86 . V_43 ;
if ( ! F_97 ( V_106 ) )
return;
if ( V_116 == 0 )
return;
F_71 ( & V_3 -> V_83 ) ;
V_32 = V_3 -> V_32 ;
if ( ! V_32 )
goto V_41;
V_8 = F_1 ( V_3 , V_106 ) ;
if ( ! V_8 )
goto V_41;
V_109 = F_99 ( V_14 ) ;
F_103 ( V_109 , V_8 -> V_4 , ( unsigned long ) V_8 , V_14 ) ;
F_100 ( & V_113 ) ;
while ( ( V_108 = F_101 ( V_109 , & V_113 ) ) ) {
struct V_1 * V_134 ;
struct V_19 * V_136 ;
V_134 = (struct V_1 * ) V_108 -> V_137 ;
V_134 -> V_157 -= V_116 ;
F_18 (glist, &qg->groups, next_group) {
F_103 ( V_109 , V_136 -> V_27 -> V_4 ,
( unsigned long ) V_136 -> V_27 , V_14 ) ;
}
}
V_41:
F_72 ( & V_3 -> V_83 ) ;
F_104 ( V_109 ) ;
}
void F_115 ( struct V_72 * V_73 )
{
if ( F_12 ( & V_73 -> V_104 ) && ! V_73 -> V_101 . V_102 )
return;
F_25 ( V_51 L_6 ,
V_73 , F_12 ( & V_73 -> V_104 ) ? L_7 : L_8 ,
V_73 -> V_101 . V_102 ) ;
F_96 () ;
}
