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
& V_35 -> V_37 [ V_32 -> V_38 ] ;
int V_39 ;
V_39 = F_10 ( V_37 -> V_40 . V_41 ) ;
if ( V_39 )
return V_39 ;
V_39 = F_10 ( V_37 -> V_42 . V_41 ) ;
if ( V_39 )
F_11 ( V_37 -> V_40 . V_41 ) ;
return V_39 ;
}
static void F_12 ( struct V_29 * V_30 )
{
struct V_31 * V_32 = V_30 -> V_33 ;
struct V_34 * V_35 = F_9 ( V_32 -> V_2 ) ;
struct V_36 * V_37 =
& V_35 -> V_37 [ V_32 -> V_38 ] ;
F_11 ( V_37 -> V_40 . V_41 ) ;
F_11 ( V_37 -> V_42 . V_41 ) ;
}
static int F_13 ( struct V_29 * V_30 ,
struct V_43 * V_44 )
{
struct V_31 * V_32 = V_30 -> V_33 ;
struct V_45 * V_42 = V_32 -> V_42 ;
struct V_45 * V_40 = V_32 -> V_40 ;
struct V_34 * V_35 = F_9 ( V_32 -> V_2 ) ;
struct V_36 * V_37 = & V_35 -> V_37 [ V_32 -> V_38 ] ;
unsigned int V_46 , V_47 = 0 ;
int V_39 = 0 ;
if ( V_35 -> V_47 )
V_47 = V_35 -> V_47 ;
else if ( V_37 -> V_47 )
V_47 = V_37 -> V_47 ;
if ( V_47 ) {
V_46 = F_14 ( V_44 ) * V_47 ;
V_39 = F_15 ( V_42 , 0 , V_46 ,
V_48 ) ;
if ( V_39 && V_39 != - V_49 )
goto V_50;
V_39 = F_15 ( V_40 , 0 , V_46 ,
V_51 ) ;
if ( V_39 && V_39 != - V_49 )
goto V_50;
}
return 0 ;
V_50:
return V_39 ;
}
static int F_16 ( struct V_45 * V_52 ,
struct V_53 * V_54 )
{
int V_39 ;
if ( V_54 -> V_55 ) {
V_39 = F_15 ( V_52 , 0 , V_54 -> V_55 , 0 ) ;
if ( V_39 && V_39 != - V_49 ) {
F_17 ( V_52 -> V_8 , L_7 ) ;
goto V_50;
}
}
if ( V_54 -> V_56 ) {
V_39 = F_18 ( V_52 ,
V_54 -> V_57 ,
V_54 -> V_58 ,
V_54 -> V_56 ,
V_54 -> V_59 ) ;
if ( V_39 && V_39 != - V_49 ) {
F_17 ( V_52 -> V_8 , L_8 ) ;
goto V_50;
}
}
V_39 = 0 ;
V_50:
return V_39 ;
}
static int F_19 ( struct V_31 * V_32 )
{
struct V_34 * V_35 = F_9 ( V_32 -> V_2 ) ;
struct V_45 * V_60 = V_32 -> V_42 ;
struct V_45 * V_61 = V_32 -> V_40 ;
struct V_36 * V_37 ;
int V_39 ;
V_37 = & V_35 -> V_37 [ V_32 -> V_38 ] ;
V_39 = F_16 ( V_60 , & V_37 -> V_42 ) ;
if ( V_39 < 0 )
return V_39 ;
V_39 = F_16 ( V_61 , & V_37 -> V_40 ) ;
if ( V_39 < 0 )
return V_39 ;
V_39 = F_20 ( V_32 -> V_2 , & V_35 -> V_62 , V_63 ) ;
if ( V_39 < 0 )
return V_39 ;
V_39 = F_21 ( V_32 -> V_2 , & V_35 -> V_62 , V_63 ) ;
if ( V_39 < 0 )
return V_39 ;
return 0 ;
}
static int
F_22 ( struct V_64 * V_65 ,
struct V_53 * V_52 ,
struct V_64 * * V_66 ,
const char * * V_23 ,
int * V_67 )
{
struct V_68 args ;
struct V_41 * V_41 ;
T_1 V_69 ;
int V_39 ;
if ( ! V_65 )
return 0 ;
V_39 = F_23 ( V_65 , L_9 ,
L_10 , 0 , & args ) ;
if ( V_39 )
return V_39 ;
* V_66 = args . V_65 ;
if ( V_67 )
* V_67 = args . V_67 ;
if ( V_23 ) {
V_39 = F_24 ( V_65 , V_23 ) ;
if ( V_39 < 0 )
return V_39 ;
}
if ( ! V_52 )
return 0 ;
V_39 = F_25 ( V_65 , & V_52 -> V_57 ,
& V_52 -> V_58 ,
& V_52 -> V_56 , & V_52 -> V_59 ) ;
if ( V_39 )
return V_39 ;
if ( F_26 ( V_65 , L_11 ) ) {
V_41 = F_27 ( V_65 , 0 ) ;
if ( F_28 ( V_41 ) ) {
V_39 = F_29 ( V_41 ) ;
return V_39 ;
}
V_52 -> V_55 = F_30 ( V_41 ) ;
V_52 -> V_41 = V_41 ;
} else if ( ! F_31 ( V_65 , L_12 , & V_69 ) ) {
V_52 -> V_55 = V_69 ;
} else {
V_41 = F_27 ( args . V_65 , 0 ) ;
if ( ! F_28 ( V_41 ) )
V_52 -> V_55 = F_30 ( V_41 ) ;
}
return 0 ;
}
static int F_32 ( struct V_64 * V_70 ,
struct V_34 * V_35 ,
int V_71 ,
bool V_72 )
{
struct V_7 * V_8 = F_33 ( V_35 ) ;
struct V_73 * V_74 = F_34 ( V_35 , V_71 ) ;
struct V_36 * V_37 = F_35 ( V_35 , V_71 ) ;
struct V_64 * V_61 = NULL ;
struct V_64 * V_75 = NULL ;
struct V_64 * V_60 = NULL ;
char V_11 [ 128 ] ;
char * V_6 = L_13 ;
int V_39 , V_76 ;
T_1 V_69 ;
if ( V_72 )
V_6 = V_63 ;
snprintf ( V_11 , sizeof( V_11 ) , L_14 , V_6 ) ;
V_61 = F_36 ( V_70 , V_11 ) ;
snprintf ( V_11 , sizeof( V_11 ) , L_15 , V_6 ) ;
V_75 = F_36 ( V_70 , V_11 ) ;
snprintf ( V_11 , sizeof( V_11 ) , L_16 , V_6 ) ;
V_60 = F_36 ( V_70 , V_11 ) ;
if ( ! V_61 || ! V_60 ) {
V_39 = - V_77 ;
F_17 ( V_8 , L_17 , V_78 , V_11 ) ;
goto V_79;
}
V_39 = F_37 ( V_8 , V_70 , V_60 ,
V_6 , & V_74 -> V_80 ) ;
if ( V_39 < 0 )
goto V_79;
if ( ! F_31 ( V_70 , L_18 , & V_69 ) )
V_37 -> V_47 = V_69 ;
V_39 = F_22 ( V_61 , & V_37 -> V_40 ,
& V_74 -> V_81 ,
& V_74 -> V_82 ,
& V_76 ) ;
if ( V_39 < 0 )
goto V_79;
V_39 = F_22 ( V_60 , & V_37 -> V_42 ,
& V_74 -> V_83 ,
& V_74 -> V_84 , NULL ) ;
if ( V_39 < 0 )
goto V_79;
V_39 = F_22 ( V_75 , NULL ,
& V_74 -> V_85 ,
NULL , NULL ) ;
if ( V_39 < 0 )
goto V_79;
if ( ! V_74 -> V_82 || ! V_74 -> V_84 ) {
V_39 = - V_77 ;
goto V_79;
}
if ( ! V_74 -> V_85 )
V_74 -> V_85 = V_74 -> V_81 ;
V_39 = F_38 ( V_8 , V_74 ,
L_19 ,
V_74 -> V_82 ,
V_74 -> V_84 ) ;
if ( V_39 < 0 )
goto V_79;
V_74 -> V_86 = & V_87 ;
V_74 -> V_88 = F_19 ;
F_39 ( V_8 , L_20 , V_74 -> V_89 ) ;
F_39 ( V_8 , L_21 , V_74 -> V_80 ) ;
F_39 ( V_8 , L_22 ,
V_74 -> V_82 ,
V_37 -> V_40 . V_55 ) ;
F_39 ( V_8 , L_23 ,
V_74 -> V_84 ,
V_37 -> V_42 . V_55 ) ;
if ( ! V_76 )
V_74 -> V_82 = NULL ;
V_79:
F_40 ( V_61 ) ;
F_40 ( V_60 ) ;
return V_39 ;
}
static int F_41 ( struct V_64 * V_70 ,
struct V_34 * V_35 )
{
struct V_7 * V_8 = F_33 ( V_35 ) ;
T_1 V_69 ;
int V_39 ;
if ( ! V_70 )
return - V_77 ;
if ( F_26 ( V_70 , V_63 L_24 ) ) {
V_39 = F_42 ( & V_35 -> V_90 ,
V_63 L_24 ) ;
if ( V_39 )
return V_39 ;
}
if ( F_26 ( V_70 , V_63 L_25 ) ) {
V_39 = F_43 ( & V_35 -> V_90 ,
V_63 L_25 ) ;
if ( V_39 )
return V_39 ;
}
V_39 = F_31 ( V_70 , V_63 L_18 , & V_69 ) ;
if ( V_39 == 0 )
V_35 -> V_47 = V_69 ;
if ( F_36 ( V_70 , V_63 L_26 ) ) {
struct V_64 * V_65 = NULL ;
int V_91 = 0 ;
F_44 (node, np) {
F_39 ( V_8 , L_27 , V_91 ) ;
V_39 = F_32 ( V_65 , V_35 ,
V_91 , false ) ;
if ( V_39 < 0 ) {
F_40 ( V_65 ) ;
return V_39 ;
}
V_91 ++ ;
}
} else {
V_39 = F_32 ( V_70 , V_35 , 0 , true ) ;
if ( V_39 < 0 )
return V_39 ;
}
V_39 = F_45 ( & V_35 -> V_90 , V_63 ) ;
if ( V_39 )
return V_39 ;
return 0 ;
}
static int F_46 ( struct V_1 * V_2 )
{
struct V_73 * V_74 ;
int V_92 ;
for ( V_92 = 0 , V_74 = V_2 -> V_74 ;
V_92 < V_2 -> V_92 ;
V_92 ++ , V_74 ++ ) {
F_40 ( V_74 -> V_81 ) ;
F_40 ( V_74 -> V_83 ) ;
}
return 0 ;
}
static int F_47 ( struct V_93 * V_94 )
{
struct V_34 * V_35 ;
struct V_73 * V_74 ;
struct V_64 * V_65 = V_94 -> V_8 . V_20 ;
struct V_7 * V_8 = & V_94 -> V_8 ;
int V_92 , V_39 ;
if ( V_65 && F_36 ( V_65 , V_63 L_26 ) )
V_92 = F_48 ( V_65 ) ;
else
V_92 = 1 ;
V_35 = F_49 ( V_8 ,
sizeof( * V_35 ) + sizeof( * V_74 ) * V_92 ,
V_95 ) ;
if ( ! V_35 )
return - V_96 ;
V_35 -> V_90 . V_97 = V_98 ;
V_35 -> V_90 . V_8 = V_8 ;
V_74 = V_35 -> V_74 ;
V_35 -> V_90 . V_74 = V_74 ;
V_35 -> V_90 . V_92 = V_92 ;
V_35 -> V_37 = F_49 ( V_8 ,
sizeof( * V_35 -> V_37 ) * V_92 ,
V_95 ) ;
if ( ! V_35 -> V_37 )
return - V_96 ;
if ( V_65 && F_50 ( V_65 ) ) {
V_39 = F_41 ( V_65 , V_35 ) ;
if ( V_39 < 0 ) {
if ( V_39 != - V_21 )
F_17 ( V_8 , L_28 , V_39 ) ;
goto V_50;
}
} else {
struct V_99 * V_100 ;
V_100 = V_8 -> V_101 ;
if ( ! V_100 ) {
F_17 ( V_8 , L_29 ) ;
return - V_77 ;
}
if ( ! V_100 -> V_23 ||
! V_100 -> V_42 . V_23 ||
! V_100 -> V_60 ||
! V_100 -> V_102 ||
! V_100 -> V_40 . V_23 ) {
F_17 ( V_8 , L_30 ) ;
return - V_77 ;
}
V_35 -> V_90 . V_23 = ( V_100 -> V_2 ) ? V_100 -> V_2 : V_100 -> V_23 ;
V_74 -> V_23 = V_100 -> V_23 ;
V_74 -> V_89 = V_100 -> V_23 ;
V_74 -> V_103 = V_100 -> V_102 ;
V_74 -> V_104 = V_100 -> V_60 ;
V_74 -> V_82 = V_100 -> V_40 . V_23 ;
V_74 -> V_84 = V_100 -> V_42 . V_23 ;
V_74 -> V_80 = V_100 -> V_105 ;
V_74 -> V_88 = F_19 ;
memcpy ( & V_35 -> V_37 -> V_40 , & V_100 -> V_40 ,
sizeof( V_35 -> V_37 -> V_40 ) ) ;
memcpy ( & V_35 -> V_37 -> V_42 , & V_100 -> V_42 ,
sizeof( V_35 -> V_37 -> V_42 ) ) ;
}
F_51 ( & V_35 -> V_90 , V_35 ) ;
V_39 = F_52 ( & V_94 -> V_8 , & V_35 -> V_90 ) ;
if ( V_39 >= 0 )
return V_39 ;
V_50:
F_46 ( & V_35 -> V_90 ) ;
return V_39 ;
}
static int F_53 ( struct V_93 * V_94 )
{
struct V_1 * V_2 = F_54 ( V_94 ) ;
struct V_34 * V_35 = F_9 ( V_2 ) ;
F_6 ( & V_35 -> V_62 ) ;
F_6 ( & V_35 -> V_106 ) ;
return F_46 ( V_2 ) ;
}
