static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_5 , char * V_6 )
{
struct V_7 * V_8 = V_2 -> V_8 ;
enum V_9 V_10 ;
char V_11 [ 128 ] ;
char * V_12 ;
char * V_13 ;
int V_14 ;
int V_15 ;
V_4 -> V_16 . V_16 = - V_17 ;
if ( V_5 ) {
snprintf ( V_11 , sizeof( V_11 ) , L_1 , V_6 ) ;
V_12 = L_2 ;
V_13 = L_3 ;
V_14 = V_18 ;
} else {
snprintf ( V_11 , sizeof( V_11 ) , L_4 , V_6 ) ;
V_12 = L_5 ;
V_13 = L_6 ;
V_14 = V_19 ;
}
V_15 = F_2 ( V_8 -> V_20 , V_11 , 0 , & V_10 ) ;
if ( V_15 == - V_21 )
return - V_21 ;
if ( F_3 ( V_15 ) ) {
V_4 -> V_22 . V_22 = V_12 ;
V_4 -> V_22 . V_14 = V_14 ;
V_4 -> V_16 . V_23 = V_13 ;
V_4 -> V_16 . V_24 = V_14 ;
V_4 -> V_16 . V_16 = V_15 ;
V_4 -> V_16 . V_25 = ! ! ( V_10 & V_26 ) ;
V_4 -> V_16 . V_27 = 150 ;
F_4 ( V_2 , V_12 , V_14 ,
& V_4 -> V_28 ,
& V_4 -> V_22 , 1 ) ;
F_5 ( & V_4 -> V_28 , 1 ,
& V_4 -> V_16 ) ;
}
return 0 ;
}
static void F_6 ( struct V_3 * V_4 )
{
if ( F_3 ( V_4 -> V_16 . V_16 ) )
F_7 ( & V_4 -> V_28 , 1 , & V_4 -> V_16 ) ;
}
static int F_8 ( struct V_29 * V_30 )
{
struct V_31 * V_32 = V_30 -> V_33 ;
struct V_34 * V_35 = F_9 ( V_32 -> V_2 ) ;
struct V_36 * V_37 =
F_10 ( V_35 , V_32 -> V_38 ) ;
int V_39 ;
V_39 = F_11 ( V_37 -> V_40 . V_41 ) ;
if ( V_39 )
return V_39 ;
V_39 = F_11 ( V_37 -> V_42 . V_41 ) ;
if ( V_39 )
F_12 ( V_37 -> V_40 . V_41 ) ;
return V_39 ;
}
static void F_13 ( struct V_29 * V_30 )
{
struct V_31 * V_32 = V_30 -> V_33 ;
struct V_34 * V_35 = F_9 ( V_32 -> V_2 ) ;
struct V_36 * V_37 =
F_10 ( V_35 , V_32 -> V_38 ) ;
F_12 ( V_37 -> V_40 . V_41 ) ;
F_12 ( V_37 -> V_42 . V_41 ) ;
}
static int F_14 ( struct V_29 * V_30 ,
struct V_43 * V_44 )
{
struct V_31 * V_32 = V_30 -> V_33 ;
struct V_45 * V_42 = V_32 -> V_42 ;
struct V_45 * V_40 = V_32 -> V_40 ;
struct V_34 * V_35 = F_9 ( V_32 -> V_2 ) ;
struct V_36 * V_37 =
F_10 ( V_35 , V_32 -> V_38 ) ;
unsigned int V_46 , V_47 = 0 ;
int V_39 = 0 ;
if ( V_35 -> V_47 )
V_47 = V_35 -> V_47 ;
else if ( V_37 -> V_47 )
V_47 = V_37 -> V_47 ;
if ( V_47 ) {
V_46 = F_15 ( V_44 ) * V_47 ;
V_39 = F_16 ( V_42 , 0 , V_46 ,
V_48 ) ;
if ( V_39 && V_39 != - V_49 )
goto V_50;
V_39 = F_16 ( V_40 , 0 , V_46 ,
V_51 ) ;
if ( V_39 && V_39 != - V_49 )
goto V_50;
}
return 0 ;
V_50:
return V_39 ;
}
static int F_17 ( struct V_31 * V_32 )
{
struct V_34 * V_35 = F_9 ( V_32 -> V_2 ) ;
struct V_45 * V_52 = V_32 -> V_42 ;
struct V_45 * V_53 = V_32 -> V_40 ;
struct V_36 * V_37 =
F_10 ( V_35 , V_32 -> V_38 ) ;
int V_39 ;
V_39 = F_18 ( V_52 , & V_37 -> V_42 ) ;
if ( V_39 < 0 )
return V_39 ;
V_39 = F_18 ( V_53 , & V_37 -> V_40 ) ;
if ( V_39 < 0 )
return V_39 ;
V_39 = F_19 ( V_32 -> V_2 , & V_35 -> V_54 , V_55 ) ;
if ( V_39 < 0 )
return V_39 ;
V_39 = F_20 ( V_32 -> V_2 , & V_35 -> V_54 , V_55 ) ;
if ( V_39 < 0 )
return V_39 ;
return 0 ;
}
static int F_21 ( struct V_56 * V_57 ,
struct V_34 * V_35 ,
int V_58 ,
bool V_59 )
{
struct V_7 * V_8 = F_22 ( V_35 ) ;
struct V_60 * V_61 = F_23 ( V_35 , V_58 ) ;
struct V_36 * V_37 = F_10 ( V_35 , V_58 ) ;
struct V_62 * V_40 = & V_37 -> V_40 ;
struct V_62 * V_42 = & V_37 -> V_42 ;
struct V_56 * V_53 = NULL ;
struct V_56 * V_63 = NULL ;
struct V_56 * V_52 = NULL ;
char V_11 [ 128 ] ;
char * V_6 = L_7 ;
int V_39 , V_64 ;
if ( V_59 )
V_6 = V_55 ;
snprintf ( V_11 , sizeof( V_11 ) , L_8 , V_6 ) ;
V_53 = F_24 ( V_57 , V_11 ) ;
snprintf ( V_11 , sizeof( V_11 ) , L_9 , V_6 ) ;
V_63 = F_24 ( V_57 , V_11 ) ;
snprintf ( V_11 , sizeof( V_11 ) , L_10 , V_6 ) ;
V_52 = F_24 ( V_57 , V_11 ) ;
if ( ! V_53 || ! V_52 ) {
V_39 = - V_65 ;
F_25 ( V_8 , L_11 , V_66 , V_11 ) ;
goto V_67;
}
V_39 = F_26 ( V_8 , V_57 , V_52 ,
V_6 , & V_61 -> V_68 ) ;
if ( V_39 < 0 )
goto V_67;
F_27 ( V_57 , L_12 , & V_37 -> V_47 ) ;
V_39 = F_28 ( V_53 , V_61 ,
V_69 , V_70 , & V_64 ) ;
if ( V_39 < 0 )
goto V_67;
V_39 = F_29 ( V_52 , V_61 , V_69 , V_70 ) ;
if ( V_39 < 0 )
goto V_67;
V_39 = F_30 ( V_63 , V_61 , V_69 , V_70 ) ;
if ( V_39 < 0 )
goto V_67;
V_39 = F_31 ( V_53 , & V_40 -> V_71 ,
& V_40 -> V_72 ,
& V_40 -> V_73 ,
& V_40 -> V_74 ) ;
if ( V_39 < 0 )
goto V_67;
V_39 = F_31 ( V_52 , & V_42 -> V_71 ,
& V_42 -> V_72 ,
& V_42 -> V_73 ,
& V_42 -> V_74 ) ;
if ( V_39 < 0 )
goto V_67;
V_39 = F_32 ( V_53 , V_61 , V_40 ) ;
if ( V_39 < 0 )
goto V_67;
V_39 = F_33 ( V_52 , V_61 , V_42 ) ;
if ( V_39 < 0 )
goto V_67;
V_39 = F_34 ( V_61 ) ;
if ( V_39 < 0 )
goto V_67;
V_39 = F_35 ( V_8 , V_61 ,
L_13 ,
V_61 -> V_75 ,
V_61 -> V_76 ) ;
if ( V_39 < 0 )
goto V_67;
V_61 -> V_77 = & V_78 ;
V_61 -> V_79 = F_17 ;
F_36 ( V_8 , L_14 , V_61 -> V_80 ) ;
F_36 ( V_8 , L_15 , V_61 -> V_68 ) ;
F_36 ( V_8 , L_16 ,
V_61 -> V_75 ,
V_37 -> V_40 . V_81 ) ;
F_36 ( V_8 , L_17 ,
V_61 -> V_76 ,
V_37 -> V_42 . V_81 ) ;
F_37 ( V_61 , V_64 ) ;
V_67:
F_38 ( V_53 ) ;
F_38 ( V_52 ) ;
return V_39 ;
}
static int F_39 ( struct V_56 * V_57 ,
struct V_34 * V_35 )
{
struct V_7 * V_8 = F_22 ( V_35 ) ;
struct V_56 * V_82 ;
int V_83 , V_84 , V_85 ;
if ( ! F_40 ( V_57 , V_55 L_18 , & V_85 ) )
return 0 ;
V_84 = V_85 / sizeof( V_86 ) ;
if ( V_84 <= 0 )
return - V_65 ;
V_35 -> V_87 . V_88 = F_41 ( V_8 ,
V_84 * sizeof( * V_35 -> V_87 . V_88 ) , V_89 ) ;
if ( ! V_35 -> V_87 . V_88 )
return - V_90 ;
for ( V_83 = 0 ; V_83 < V_84 ; V_83 ++ ) {
V_82 = F_42 ( V_57 , V_55 L_18 , V_83 ) ;
if ( ! V_82 )
return - V_65 ;
V_35 -> V_87 . V_88 [ V_83 ] . V_91 = V_82 ;
}
V_35 -> V_87 . V_92 = V_84 ;
return 0 ;
}
static int F_43 ( struct V_56 * V_57 ,
struct V_34 * V_35 )
{
struct V_7 * V_8 = F_22 ( V_35 ) ;
struct V_56 * V_61 ;
int V_39 ;
if ( ! V_57 )
return - V_65 ;
V_61 = F_24 ( V_57 , V_55 L_19 ) ;
if ( F_44 ( V_57 , V_55 L_20 ) ) {
V_39 = F_45 ( & V_35 -> V_87 ,
V_55 L_20 ) ;
if ( V_39 )
goto V_93;
}
if ( F_44 ( V_57 , V_55 L_21 ) ) {
V_39 = F_46 ( & V_35 -> V_87 ,
V_55 L_21 ) ;
if ( V_39 )
goto V_93;
}
F_27 ( V_57 , V_55 L_12 , & V_35 -> V_47 ) ;
if ( V_61 ) {
struct V_56 * V_94 = NULL ;
int V_83 = 0 ;
F_47 (node, np) {
F_36 ( V_8 , L_22 , V_83 ) ;
V_39 = F_21 ( V_94 , V_35 ,
V_83 , false ) ;
if ( V_39 < 0 ) {
F_38 ( V_94 ) ;
goto V_93;
}
V_83 ++ ;
}
} else {
V_39 = F_21 ( V_57 , V_35 , 0 , true ) ;
if ( V_39 < 0 )
goto V_93;
}
V_39 = F_48 ( & V_35 -> V_87 , V_55 ) ;
if ( V_39 < 0 )
goto V_93;
V_39 = F_39 ( V_57 , V_35 ) ;
V_93:
F_38 ( V_61 ) ;
return V_39 ;
}
static int F_49 ( struct V_95 * V_96 )
{
struct V_34 * V_35 ;
struct V_60 * V_61 ;
struct V_36 * V_37 ;
struct V_56 * V_94 = V_96 -> V_8 . V_20 ;
struct V_7 * V_8 = & V_96 -> V_8 ;
int V_38 , V_39 ;
if ( V_94 && F_24 ( V_94 , V_55 L_19 ) )
V_38 = F_50 ( V_94 ) ;
else
V_38 = 1 ;
V_35 = F_41 ( V_8 , sizeof( * V_35 ) , V_89 ) ;
if ( ! V_35 )
return - V_90 ;
V_37 = F_41 ( V_8 , sizeof( * V_37 ) * V_38 , V_89 ) ;
V_61 = F_41 ( V_8 , sizeof( * V_61 ) * V_38 , V_89 ) ;
if ( ! V_37 || ! V_61 )
return - V_90 ;
V_35 -> V_37 = V_37 ;
V_35 -> V_61 = V_61 ;
V_35 -> V_87 . V_97 = V_98 ;
V_35 -> V_87 . V_8 = V_8 ;
V_35 -> V_87 . V_61 = V_35 -> V_61 ;
V_35 -> V_87 . V_99 = V_38 ;
if ( V_94 && F_51 ( V_94 ) ) {
V_39 = F_43 ( V_94 , V_35 ) ;
if ( V_39 < 0 ) {
if ( V_39 != - V_21 )
F_25 ( V_8 , L_23 , V_39 ) ;
goto V_50;
}
} else {
struct V_100 * V_101 ;
V_101 = V_8 -> V_102 ;
if ( ! V_101 ) {
F_25 ( V_8 , L_24 ) ;
return - V_65 ;
}
if ( ! V_101 -> V_23 ||
! V_101 -> V_42 . V_23 ||
! V_101 -> V_52 ||
! V_101 -> V_103 ||
! V_101 -> V_40 . V_23 ) {
F_25 ( V_8 , L_25 ) ;
return - V_65 ;
}
V_35 -> V_87 . V_23 = ( V_101 -> V_2 ) ? V_101 -> V_2 : V_101 -> V_23 ;
V_61 -> V_23 = V_101 -> V_23 ;
V_61 -> V_80 = V_101 -> V_23 ;
V_61 -> V_104 = V_101 -> V_103 ;
V_61 -> V_105 = V_101 -> V_52 ;
V_61 -> V_75 = V_101 -> V_40 . V_23 ;
V_61 -> V_76 = V_101 -> V_42 . V_23 ;
V_61 -> V_68 = V_101 -> V_106 ;
V_61 -> V_79 = F_17 ;
memcpy ( & V_35 -> V_37 -> V_40 , & V_101 -> V_40 ,
sizeof( V_35 -> V_37 -> V_40 ) ) ;
memcpy ( & V_35 -> V_37 -> V_42 , & V_101 -> V_42 ,
sizeof( V_35 -> V_37 -> V_42 ) ) ;
}
F_52 ( & V_35 -> V_87 , V_35 ) ;
V_39 = F_53 ( & V_96 -> V_8 , & V_35 -> V_87 ) ;
if ( V_39 >= 0 )
return V_39 ;
V_50:
F_54 ( & V_35 -> V_87 ) ;
return V_39 ;
}
static int F_55 ( struct V_95 * V_96 )
{
struct V_1 * V_2 = F_56 ( V_96 ) ;
struct V_34 * V_35 = F_9 ( V_2 ) ;
F_6 ( & V_35 -> V_54 ) ;
F_6 ( & V_35 -> V_107 ) ;
return F_54 ( V_2 ) ;
}
