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
V_39 = F_11 ( & V_37 -> V_40 ) ;
if ( V_39 )
return V_39 ;
V_39 = F_11 ( & V_37 -> V_41 ) ;
if ( V_39 )
F_12 ( & V_37 -> V_40 ) ;
return V_39 ;
}
static void F_13 ( struct V_29 * V_30 )
{
struct V_31 * V_32 = V_30 -> V_33 ;
struct V_34 * V_35 = F_9 ( V_32 -> V_2 ) ;
struct V_36 * V_37 =
F_10 ( V_35 , V_32 -> V_38 ) ;
F_12 ( & V_37 -> V_40 ) ;
F_12 ( & V_37 -> V_41 ) ;
}
static int F_14 ( struct V_29 * V_30 ,
struct V_42 * V_43 )
{
struct V_31 * V_32 = V_30 -> V_33 ;
struct V_44 * V_41 = V_32 -> V_41 ;
struct V_44 * V_40 = V_32 -> V_40 ;
struct V_34 * V_35 = F_9 ( V_32 -> V_2 ) ;
struct V_36 * V_37 =
F_10 ( V_35 , V_32 -> V_38 ) ;
unsigned int V_45 , V_46 = 0 ;
int V_39 = 0 ;
if ( V_35 -> V_46 )
V_46 = V_35 -> V_46 ;
else if ( V_37 -> V_46 )
V_46 = V_37 -> V_46 ;
if ( V_46 ) {
V_45 = F_15 ( V_43 ) * V_46 ;
V_39 = F_16 ( V_41 , 0 , V_45 ,
V_47 ) ;
if ( V_39 && V_39 != - V_48 )
goto V_49;
V_39 = F_16 ( V_40 , 0 , V_45 ,
V_50 ) ;
if ( V_39 && V_39 != - V_48 )
goto V_49;
}
return 0 ;
V_49:
return V_39 ;
}
static int F_17 ( struct V_31 * V_32 )
{
struct V_34 * V_35 = F_9 ( V_32 -> V_2 ) ;
struct V_44 * V_51 = V_32 -> V_41 ;
struct V_44 * V_52 = V_32 -> V_40 ;
struct V_36 * V_37 =
F_10 ( V_35 , V_32 -> V_38 ) ;
int V_39 ;
V_39 = F_18 ( V_51 , & V_37 -> V_41 ) ;
if ( V_39 < 0 )
return V_39 ;
V_39 = F_18 ( V_52 , & V_37 -> V_40 ) ;
if ( V_39 < 0 )
return V_39 ;
V_39 = F_19 ( V_32 -> V_2 , & V_35 -> V_53 , V_54 ) ;
if ( V_39 < 0 )
return V_39 ;
V_39 = F_20 ( V_32 -> V_2 , & V_35 -> V_55 , V_54 ) ;
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
struct V_62 * V_41 = & V_37 -> V_41 ;
struct V_56 * V_52 = NULL ;
struct V_56 * V_63 = NULL ;
struct V_56 * V_51 = NULL ;
char V_11 [ 128 ] ;
char * V_6 = L_7 ;
int V_39 , V_64 ;
if ( V_59 )
V_6 = V_54 ;
snprintf ( V_11 , sizeof( V_11 ) , L_8 , V_6 ) ;
V_52 = F_24 ( V_57 , V_11 ) ;
if ( ! V_52 ) {
V_39 = - V_65 ;
F_25 ( V_8 , L_9 , V_66 , V_11 ) ;
goto V_67;
}
snprintf ( V_11 , sizeof( V_11 ) , L_10 , V_6 ) ;
V_63 = F_24 ( V_57 , V_11 ) ;
snprintf ( V_11 , sizeof( V_11 ) , L_11 , V_6 ) ;
V_51 = F_24 ( V_57 , V_11 ) ;
if ( ! V_51 ) {
V_39 = - V_65 ;
F_25 ( V_8 , L_9 , V_66 , V_11 ) ;
goto V_67;
}
V_39 = F_26 ( V_8 , V_57 , V_51 ,
V_6 , & V_61 -> V_68 ) ;
if ( V_39 < 0 )
goto V_67;
F_27 ( V_57 , L_12 , & V_37 -> V_46 ) ;
V_39 = F_28 ( V_52 , V_61 ,
V_69 , V_70 , & V_64 ) ;
if ( V_39 < 0 )
goto V_67;
V_39 = F_29 ( V_51 , V_61 , V_69 , V_70 ) ;
if ( V_39 < 0 )
goto V_67;
V_39 = F_30 ( V_63 , V_61 , V_69 , V_70 ) ;
if ( V_39 < 0 )
goto V_67;
V_39 = F_31 ( V_52 , V_40 ) ;
if ( V_39 < 0 )
goto V_67;
V_39 = F_31 ( V_51 , V_41 ) ;
if ( V_39 < 0 )
goto V_67;
V_39 = F_32 ( V_8 , V_52 , V_61 , V_40 ) ;
if ( V_39 < 0 )
goto V_67;
V_39 = F_33 ( V_8 , V_51 , V_61 , V_41 ) ;
if ( V_39 < 0 )
goto V_67;
V_39 = F_34 ( V_61 ) ;
if ( V_39 < 0 )
goto V_67;
V_39 = F_35 ( V_8 , V_61 ,
L_13 ,
V_61 -> V_71 ,
V_61 -> V_72 ) ;
if ( V_39 < 0 )
goto V_67;
V_61 -> V_73 = & V_74 ;
V_61 -> V_75 = F_17 ;
F_36 ( V_61 , V_64 ) ;
V_67:
F_37 ( V_52 ) ;
F_37 ( V_51 ) ;
return V_39 ;
}
static int F_38 ( struct V_56 * V_57 ,
struct V_34 * V_35 )
{
struct V_7 * V_8 = F_22 ( V_35 ) ;
struct V_56 * V_76 ;
struct V_1 * V_2 = F_39 ( V_35 ) ;
int V_77 , V_78 , V_79 ;
if ( ! F_40 ( V_57 , V_54 L_14 , & V_79 ) )
return 0 ;
V_78 = V_79 / sizeof( V_80 ) ;
if ( V_78 <= 0 )
return - V_65 ;
V_2 -> V_81 = F_41 ( V_8 ,
V_78 * sizeof( * V_2 -> V_81 ) , V_82 ) ;
if ( ! V_2 -> V_81 )
return - V_83 ;
for ( V_77 = 0 ; V_77 < V_78 ; V_77 ++ ) {
V_76 = F_42 ( V_57 , V_54 L_14 , V_77 ) ;
if ( ! V_76 )
return - V_65 ;
V_2 -> V_81 [ V_77 ] . V_84 = V_76 ;
}
V_2 -> V_85 = V_78 ;
return 0 ;
}
static int F_43 ( struct V_34 * V_35 )
{
struct V_7 * V_8 = F_22 ( V_35 ) ;
struct V_1 * V_2 = F_39 ( V_35 ) ;
struct V_56 * V_61 ;
struct V_56 * V_57 = V_8 -> V_20 ;
int V_39 ;
if ( ! V_57 )
return - V_65 ;
V_61 = F_24 ( V_57 , V_54 L_15 ) ;
V_39 = F_44 ( V_2 , V_54 ) ;
if ( V_39 < 0 )
goto V_86;
V_39 = F_45 ( V_2 , V_54 , 1 ) ;
if ( V_39 < 0 )
goto V_86;
F_27 ( V_57 , V_54 L_12 , & V_35 -> V_46 ) ;
if ( V_61 ) {
struct V_56 * V_87 = NULL ;
int V_77 = 0 ;
F_46 (node, np) {
F_47 ( V_8 , L_16 , V_77 ) ;
V_39 = F_21 ( V_87 , V_35 ,
V_77 , false ) ;
if ( V_39 < 0 ) {
F_37 ( V_87 ) ;
goto V_86;
}
V_77 ++ ;
}
} else {
V_39 = F_21 ( V_57 , V_35 , 0 , true ) ;
if ( V_39 < 0 )
goto V_86;
}
V_39 = F_48 ( V_2 , V_54 ) ;
if ( V_39 < 0 )
goto V_86;
V_39 = F_38 ( V_57 , V_35 ) ;
V_86:
F_37 ( V_61 ) ;
return V_39 ;
}
static int F_49 ( struct V_88 * V_89 )
{
struct V_34 * V_35 ;
struct V_60 * V_61 ;
struct V_36 * V_37 ;
struct V_7 * V_8 = & V_89 -> V_8 ;
struct V_56 * V_87 = V_8 -> V_20 ;
struct V_1 * V_2 ;
int V_38 , V_39 ;
if ( V_87 && F_24 ( V_87 , V_54 L_15 ) )
V_38 = F_50 ( V_87 ) ;
else
V_38 = 1 ;
V_35 = F_41 ( V_8 , sizeof( * V_35 ) , V_82 ) ;
if ( ! V_35 )
return - V_83 ;
V_37 = F_41 ( V_8 , sizeof( * V_37 ) * V_38 , V_82 ) ;
V_61 = F_41 ( V_8 , sizeof( * V_61 ) * V_38 , V_82 ) ;
if ( ! V_37 || ! V_61 )
return - V_83 ;
V_35 -> V_37 = V_37 ;
V_35 -> V_61 = V_61 ;
V_2 = F_39 ( V_35 ) ;
V_2 -> V_90 = V_91 ;
V_2 -> V_8 = V_8 ;
V_2 -> V_61 = V_35 -> V_61 ;
V_2 -> V_92 = V_38 ;
if ( V_87 && F_51 ( V_87 ) ) {
V_39 = F_43 ( V_35 ) ;
if ( V_39 < 0 ) {
if ( V_39 != - V_21 )
F_25 ( V_8 , L_17 , V_39 ) ;
goto V_49;
}
} else {
struct V_93 * V_94 ;
V_94 = V_8 -> V_95 ;
if ( ! V_94 ) {
F_25 ( V_8 , L_18 ) ;
return - V_65 ;
}
if ( ! V_94 -> V_23 ||
! V_94 -> V_41 . V_23 ||
! V_94 -> V_51 ||
! V_94 -> V_96 ||
! V_94 -> V_40 . V_23 ) {
F_25 ( V_8 , L_19 ) ;
return - V_65 ;
}
V_2 -> V_23 = ( V_94 -> V_2 ) ? V_94 -> V_2 : V_94 -> V_23 ;
V_61 -> V_23 = V_94 -> V_23 ;
V_61 -> V_97 = V_94 -> V_23 ;
V_61 -> V_98 = V_94 -> V_96 ;
V_61 -> V_99 = V_94 -> V_51 ;
V_61 -> V_71 = V_94 -> V_40 . V_23 ;
V_61 -> V_72 = V_94 -> V_41 . V_23 ;
V_61 -> V_68 = V_94 -> V_100 ;
V_61 -> V_75 = F_17 ;
memcpy ( & V_35 -> V_37 -> V_40 , & V_94 -> V_40 ,
sizeof( V_35 -> V_37 -> V_40 ) ) ;
memcpy ( & V_35 -> V_37 -> V_41 , & V_94 -> V_41 ,
sizeof( V_35 -> V_37 -> V_41 ) ) ;
}
F_52 ( V_2 , V_35 ) ;
V_39 = F_53 ( V_8 , V_2 ) ;
if ( V_39 < 0 )
goto V_49;
return 0 ;
V_49:
F_54 ( V_2 ) ;
return V_39 ;
}
static int F_55 ( struct V_88 * V_89 )
{
struct V_1 * V_2 = F_56 ( V_89 ) ;
struct V_34 * V_35 = F_9 ( V_2 ) ;
F_6 ( & V_35 -> V_53 ) ;
F_6 ( & V_35 -> V_55 ) ;
return F_54 ( V_2 ) ;
}
