static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = F_2 ( V_4 -> V_8 ) ;
struct V_9 * V_10 =
& V_7 -> V_10 [ V_4 -> V_11 ] ;
int V_12 ;
V_12 = F_3 ( V_10 -> V_13 . V_14 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_3 ( V_10 -> V_15 . V_14 ) ;
if ( V_12 )
F_4 ( V_10 -> V_13 . V_14 ) ;
return V_12 ;
}
static void F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = F_2 ( V_4 -> V_8 ) ;
struct V_9 * V_10 =
& V_7 -> V_10 [ V_4 -> V_11 ] ;
F_4 ( V_10 -> V_13 . V_14 ) ;
F_4 ( V_10 -> V_15 . V_14 ) ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_16 * V_17 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_18 * V_15 = V_4 -> V_15 ;
struct V_18 * V_13 = V_4 -> V_13 ;
struct V_6 * V_7 = F_2 ( V_4 -> V_8 ) ;
struct V_9 * V_10 = & V_7 -> V_10 [ V_4 -> V_11 ] ;
unsigned int V_19 , V_20 = 0 ;
int V_12 = 0 ;
if ( V_7 -> V_20 )
V_20 = V_7 -> V_20 ;
else if ( V_10 -> V_20 )
V_20 = V_10 -> V_20 ;
if ( V_20 ) {
V_19 = F_7 ( V_17 ) * V_20 ;
V_12 = F_8 ( V_15 , 0 , V_19 ,
V_21 ) ;
if ( V_12 && V_12 != - V_22 )
goto V_23;
V_12 = F_8 ( V_13 , 0 , V_19 ,
V_24 ) ;
if ( V_12 && V_12 != - V_22 )
goto V_23;
}
return 0 ;
V_23:
return V_12 ;
}
static int F_9 ( struct V_18 * V_25 ,
struct V_26 * V_27 )
{
int V_12 ;
if ( V_27 -> V_28 ) {
V_12 = F_8 ( V_25 , 0 , V_27 -> V_28 , 0 ) ;
if ( V_12 && V_12 != - V_22 ) {
F_10 ( V_25 -> V_29 , L_1 ) ;
goto V_23;
}
}
if ( V_27 -> V_30 ) {
V_12 = F_11 ( V_25 ,
V_27 -> V_31 ,
V_27 -> V_32 ,
V_27 -> V_30 ,
V_27 -> V_33 ) ;
if ( V_12 && V_12 != - V_22 ) {
F_10 ( V_25 -> V_29 , L_2 ) ;
goto V_23;
}
}
V_12 = 0 ;
V_23:
return V_12 ;
}
static int F_12 ( struct V_3 * V_4 )
{
struct V_6 * V_7 = F_2 ( V_4 -> V_8 ) ;
struct V_18 * V_34 = V_4 -> V_15 ;
struct V_18 * V_35 = V_4 -> V_13 ;
struct V_9 * V_10 ;
int V_12 ;
V_10 = & V_7 -> V_10 [ V_4 -> V_11 ] ;
V_12 = F_9 ( V_34 , & V_10 -> V_15 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_9 ( V_35 , & V_10 -> V_13 ) ;
if ( V_12 < 0 )
return V_12 ;
if ( F_13 ( V_7 -> V_36 ) ) {
F_14 ( V_4 -> V_8 , L_3 ,
V_37 ,
& V_38 ,
V_39 ,
F_15 ( V_39 ) ) ;
V_40 . V_41 = V_7 -> V_36 ;
V_40 . V_42 = V_7 -> V_43 ;
F_16 ( & V_38 , 1 ,
& V_40 ) ;
}
if ( F_13 ( V_7 -> V_44 ) ) {
F_14 ( V_4 -> V_8 , L_4 ,
V_45 ,
& V_46 ,
V_47 ,
F_15 ( V_47 ) ) ;
V_48 . V_41 = V_7 -> V_44 ;
V_48 . V_42 = V_7 -> V_49 ;
F_16 ( & V_46 , 1 ,
& V_48 ) ;
}
return 0 ;
}
static int
F_17 ( struct V_50 * V_51 ,
struct V_26 * V_25 ,
struct V_50 * * V_52 ,
const char * * V_53 ,
int * V_54 )
{
struct V_55 args ;
struct V_14 * V_14 ;
T_1 V_56 ;
int V_12 ;
V_12 = F_18 ( V_51 , L_5 ,
L_6 , 0 , & args ) ;
if ( V_12 )
return V_12 ;
* V_52 = args . V_51 ;
if ( V_54 )
* V_54 = args . V_54 ;
V_12 = F_19 ( V_51 , V_53 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_20 ( V_51 , & V_25 -> V_31 ,
& V_25 -> V_32 ,
& V_25 -> V_30 , & V_25 -> V_33 ) ;
if ( V_12 )
return V_12 ;
if ( F_21 ( V_51 , L_7 ) ) {
V_14 = F_22 ( V_51 , 0 ) ;
if ( F_23 ( V_14 ) ) {
V_12 = F_24 ( V_14 ) ;
return V_12 ;
}
V_25 -> V_28 = F_25 ( V_14 ) ;
V_25 -> V_14 = V_14 ;
} else if ( ! F_26 ( V_51 , L_8 , & V_56 ) ) {
V_25 -> V_28 = V_56 ;
} else {
V_14 = F_22 ( args . V_51 , 0 ) ;
if ( ! F_23 ( V_14 ) )
V_25 -> V_28 = F_25 ( V_14 ) ;
}
return 0 ;
}
static int F_27 ( struct V_50 * V_57 ,
struct V_6 * V_7 ,
struct V_50 * V_34 ,
char * V_58 , int V_59 )
{
struct V_60 * V_61 = F_28 ( V_7 , V_59 ) ;
struct V_62 * V_29 = F_29 ( V_7 ) ;
struct V_50 * V_63 = NULL ;
struct V_50 * V_64 = NULL ;
unsigned int V_65 ;
V_65 = F_30 ( V_57 , V_58 ,
& V_63 , & V_64 ) ;
V_65 &= ~ V_66 ;
if ( strlen ( V_58 ) && ! V_63 && ! V_64 ) {
F_31 ( V_29 , L_9 ) ;
V_65 = F_30 ( V_34 , NULL , NULL , NULL ) |
( V_65 & ~ V_67 ) ;
} else {
if ( V_34 == V_63 )
V_65 |= ( V_34 == V_64 ) ?
V_68 : V_69 ;
else
V_65 |= ( V_34 == V_64 ) ?
V_70 : V_71 ;
}
V_61 -> V_72 = V_65 ;
F_32 ( V_63 ) ;
F_32 ( V_64 ) ;
return 0 ;
}
static int F_33 ( struct V_50 * V_57 ,
struct V_6 * V_7 ,
int V_59 ,
bool V_73 )
{
struct V_62 * V_29 = F_29 ( V_7 ) ;
struct V_60 * V_61 = F_28 ( V_7 , V_59 ) ;
struct V_9 * V_10 = F_34 ( V_7 , V_59 ) ;
struct V_50 * V_35 = NULL ;
struct V_50 * V_74 = NULL ;
struct V_50 * V_34 = NULL ;
char * V_53 ;
char V_75 [ 128 ] ;
char * V_58 = L_10 ;
int V_12 , V_76 ;
T_1 V_56 ;
if ( V_73 )
V_58 = L_11 ;
snprintf ( V_75 , sizeof( V_75 ) , L_12 , V_58 ) ;
V_35 = F_35 ( V_57 , V_75 ) ;
snprintf ( V_75 , sizeof( V_75 ) , L_13 , V_58 ) ;
V_74 = F_35 ( V_57 , V_75 ) ;
snprintf ( V_75 , sizeof( V_75 ) , L_14 , V_58 ) ;
V_34 = F_35 ( V_57 , V_75 ) ;
if ( ! V_35 || ! V_34 ) {
V_12 = - V_77 ;
F_10 ( V_29 , L_15 , V_78 , V_75 ) ;
goto V_79;
}
V_12 = F_27 ( V_57 , V_7 ,
V_34 , V_58 , V_59 ) ;
if ( V_12 < 0 )
goto V_79;
if ( ! F_26 ( V_57 , L_16 , & V_56 ) )
V_10 -> V_20 = V_56 ;
V_12 = F_17 ( V_35 , & V_10 -> V_13 ,
& V_61 -> V_80 ,
& V_61 -> V_81 ,
& V_76 ) ;
if ( V_12 < 0 )
goto V_79;
V_12 = F_17 ( V_34 , & V_10 -> V_15 ,
& V_61 -> V_82 ,
& V_61 -> V_83 , NULL ) ;
if ( V_12 < 0 )
goto V_79;
if ( ! V_61 -> V_81 || ! V_61 -> V_83 ) {
V_12 = - V_77 ;
goto V_79;
}
if ( V_74 ) {
struct V_55 args ;
V_12 = F_18 ( V_74 , L_5 ,
L_6 , 0 , & args ) ;
V_61 -> V_84 = args . V_51 ;
} else {
V_61 -> V_84 = V_61 -> V_80 ;
}
V_53 = F_36 ( V_29 ,
strlen ( V_61 -> V_81 ) +
strlen ( V_61 -> V_83 ) + 2 ,
V_85 ) ;
if ( ! V_53 ) {
V_12 = - V_86 ;
goto V_79;
}
sprintf ( V_53 , L_17 , V_61 -> V_81 ,
V_61 -> V_83 ) ;
V_61 -> V_53 = V_61 -> V_87 = V_53 ;
V_61 -> V_88 = & V_89 ;
V_61 -> V_90 = F_12 ;
F_31 ( V_29 , L_18 , V_61 -> V_87 ) ;
F_31 ( V_29 , L_19 , V_61 -> V_72 ) ;
F_31 ( V_29 , L_20 ,
V_61 -> V_81 ,
V_10 -> V_13 . V_28 ) ;
F_31 ( V_29 , L_21 ,
V_61 -> V_83 ,
V_10 -> V_15 . V_28 ) ;
if ( ! V_76 )
V_61 -> V_81 = NULL ;
V_79:
F_32 ( V_35 ) ;
F_32 ( V_34 ) ;
return V_12 ;
}
static int F_37 ( struct V_50 * V_57 ,
struct V_6 * V_7 )
{
struct V_62 * V_29 = F_29 ( V_7 ) ;
enum V_91 V_92 ;
T_1 V_56 ;
int V_12 ;
if ( ! V_57 )
return - V_77 ;
F_38 ( & V_7 -> V_93 , L_22 ) ;
if ( F_21 ( V_57 , L_23 ) ) {
V_12 = F_39 ( & V_7 -> V_93 ,
L_23 ) ;
if ( V_12 )
return V_12 ;
}
if ( F_21 ( V_57 , L_24 ) ) {
V_12 = F_40 ( & V_7 -> V_93 ,
L_24 ) ;
if ( V_12 )
return V_12 ;
}
V_12 = F_26 ( V_57 , L_25 , & V_56 ) ;
if ( V_12 == 0 )
V_7 -> V_20 = V_56 ;
F_31 ( V_29 , L_26 , V_7 -> V_93 . V_53 ?
V_7 -> V_93 . V_53 : L_10 ) ;
if ( F_35 ( V_57 , L_27 ) ) {
struct V_50 * V_51 = NULL ;
int V_94 = 0 ;
F_41 (node, np) {
F_31 ( V_29 , L_28 , V_94 ) ;
V_12 = F_33 ( V_51 , V_7 ,
V_94 , false ) ;
if ( V_12 < 0 ) {
F_32 ( V_51 ) ;
return V_12 ;
}
V_94 ++ ;
}
} else {
V_12 = F_33 ( V_57 , V_7 , 0 , true ) ;
if ( V_12 < 0 )
return V_12 ;
}
V_7 -> V_36 = F_42 ( V_57 ,
L_29 , 0 , & V_92 ) ;
V_7 -> V_43 = ! ! ( V_92 & V_95 ) ;
if ( V_7 -> V_36 == - V_96 )
return - V_96 ;
V_7 -> V_44 = F_42 ( V_57 ,
L_30 , 0 , & V_92 ) ;
V_7 -> V_49 = ! ! ( V_92 & V_95 ) ;
if ( V_7 -> V_44 == - V_96 )
return - V_96 ;
if ( ! V_7 -> V_93 . V_53 )
V_7 -> V_93 . V_53 = V_7 -> V_93 . V_61 -> V_53 ;
return 0 ;
}
static int F_43 ( struct V_97 * V_8 )
{
struct V_60 * V_61 ;
int V_98 ;
for ( V_98 = 0 , V_61 = V_8 -> V_61 ;
V_98 < V_8 -> V_98 ;
V_98 ++ , V_61 ++ ) {
F_32 ( V_61 -> V_80 ) ;
F_32 ( V_61 -> V_82 ) ;
}
return 0 ;
}
static int F_44 ( struct V_99 * V_100 )
{
struct V_6 * V_7 ;
struct V_60 * V_61 ;
struct V_50 * V_51 = V_100 -> V_29 . V_101 ;
struct V_62 * V_29 = & V_100 -> V_29 ;
int V_98 , V_12 ;
if ( V_51 && F_35 ( V_51 , L_27 ) )
V_98 = F_45 ( V_51 ) ;
else
V_98 = 1 ;
V_7 = F_36 ( V_29 ,
sizeof( * V_7 ) + sizeof( * V_61 ) * V_98 ,
V_85 ) ;
if ( ! V_7 )
return - V_86 ;
V_7 -> V_93 . V_102 = V_103 ;
V_7 -> V_93 . V_29 = V_29 ;
V_61 = V_7 -> V_61 ;
V_7 -> V_93 . V_61 = V_61 ;
V_7 -> V_93 . V_98 = V_98 ;
V_7 -> V_36 = - V_104 ;
V_7 -> V_44 = - V_104 ;
V_7 -> V_10 = F_36 ( V_29 ,
sizeof( * V_7 -> V_10 ) * V_98 ,
V_85 ) ;
if ( ! V_7 -> V_10 )
return - V_86 ;
if ( V_51 && F_46 ( V_51 ) ) {
V_12 = F_37 ( V_51 , V_7 ) ;
if ( V_12 < 0 ) {
if ( V_12 != - V_96 )
F_10 ( V_29 , L_31 , V_12 ) ;
goto V_23;
}
} else {
struct V_105 * V_106 ;
V_106 = V_29 -> V_107 ;
if ( ! V_106 ) {
F_10 ( V_29 , L_32 ) ;
return - V_77 ;
}
if ( ! V_106 -> V_53 ||
! V_106 -> V_15 . V_53 ||
! V_106 -> V_34 ||
! V_106 -> V_108 ||
! V_106 -> V_13 . V_53 ) {
F_10 ( V_29 , L_33 ) ;
return - V_77 ;
}
V_7 -> V_93 . V_53 = ( V_106 -> V_8 ) ? V_106 -> V_8 : V_106 -> V_53 ;
V_61 -> V_53 = V_106 -> V_53 ;
V_61 -> V_87 = V_106 -> V_53 ;
V_61 -> V_109 = V_106 -> V_108 ;
V_61 -> V_110 = V_106 -> V_34 ;
V_61 -> V_81 = V_106 -> V_13 . V_53 ;
V_61 -> V_83 = V_106 -> V_15 . V_53 ;
V_61 -> V_72 = V_106 -> V_65 ;
V_61 -> V_90 = F_12 ;
memcpy ( & V_7 -> V_10 -> V_13 , & V_106 -> V_13 ,
sizeof( V_7 -> V_10 -> V_13 ) ) ;
memcpy ( & V_7 -> V_10 -> V_15 , & V_106 -> V_15 ,
sizeof( V_7 -> V_10 -> V_15 ) ) ;
}
F_47 ( & V_7 -> V_93 , V_7 ) ;
V_12 = F_48 ( & V_100 -> V_29 , & V_7 -> V_93 ) ;
if ( V_12 >= 0 )
return V_12 ;
V_23:
F_43 ( & V_7 -> V_93 ) ;
return V_12 ;
}
static int F_49 ( struct V_99 * V_100 )
{
struct V_97 * V_8 = F_50 ( V_100 ) ;
struct V_6 * V_7 = F_2 ( V_8 ) ;
if ( F_13 ( V_7 -> V_36 ) )
F_51 ( & V_38 , 1 ,
& V_40 ) ;
if ( F_13 ( V_7 -> V_44 ) )
F_51 ( & V_46 , 1 ,
& V_48 ) ;
return F_43 ( V_8 ) ;
}
