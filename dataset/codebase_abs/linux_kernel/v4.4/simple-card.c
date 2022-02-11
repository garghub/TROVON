static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = F_2 ( V_4 -> V_8 ) ;
struct V_9 * V_10 =
& V_7 -> V_10 [ V_4 - V_4 -> V_8 -> V_4 ] ;
int V_11 ;
V_11 = F_3 ( V_10 -> V_12 . V_13 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_3 ( V_10 -> V_14 . V_13 ) ;
if ( V_11 )
F_4 ( V_10 -> V_12 . V_13 ) ;
return V_11 ;
}
static void F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = F_2 ( V_4 -> V_8 ) ;
struct V_9 * V_10 =
& V_7 -> V_10 [ V_4 - V_4 -> V_8 -> V_4 ] ;
F_4 ( V_10 -> V_12 . V_13 ) ;
F_4 ( V_10 -> V_14 . V_13 ) ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_15 * V_16 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_17 * V_14 = V_4 -> V_14 ;
struct V_17 * V_12 = V_4 -> V_12 ;
struct V_6 * V_7 = F_2 ( V_4 -> V_8 ) ;
struct V_9 * V_10 =
& V_7 -> V_10 [ V_4 - V_4 -> V_8 -> V_4 ] ;
unsigned int V_18 , V_19 = 0 ;
int V_11 = 0 ;
if ( V_7 -> V_19 )
V_19 = V_7 -> V_19 ;
else if ( V_10 -> V_19 )
V_19 = V_10 -> V_19 ;
if ( V_19 ) {
V_18 = F_7 ( V_16 ) * V_19 ;
V_11 = F_8 ( V_14 , 0 , V_18 ,
V_20 ) ;
if ( V_11 && V_11 != - V_21 )
goto V_22;
V_11 = F_8 ( V_12 , 0 , V_18 ,
V_23 ) ;
if ( V_11 && V_11 != - V_21 )
goto V_22;
}
V_22:
return V_11 ;
}
static int F_9 ( struct V_17 * V_24 ,
struct V_25 * V_26 )
{
int V_11 ;
if ( V_26 -> V_27 ) {
V_11 = F_8 ( V_24 , 0 , V_26 -> V_27 , 0 ) ;
if ( V_11 && V_11 != - V_21 ) {
F_10 ( V_24 -> V_28 , L_1 ) ;
goto V_22;
}
}
if ( V_26 -> V_29 ) {
V_11 = F_11 ( V_24 ,
V_26 -> V_30 ,
V_26 -> V_31 ,
V_26 -> V_29 ,
V_26 -> V_32 ) ;
if ( V_11 && V_11 != - V_21 ) {
F_10 ( V_24 -> V_28 , L_2 ) ;
goto V_22;
}
}
V_11 = 0 ;
V_22:
return V_11 ;
}
static int F_12 ( struct V_3 * V_4 )
{
struct V_6 * V_7 = F_2 ( V_4 -> V_8 ) ;
struct V_17 * V_33 = V_4 -> V_14 ;
struct V_17 * V_34 = V_4 -> V_12 ;
struct V_9 * V_10 ;
int V_35 , V_11 ;
V_35 = V_4 - V_4 -> V_8 -> V_4 ;
V_10 = & V_7 -> V_10 [ V_35 ] ;
V_11 = F_9 ( V_33 , & V_10 -> V_14 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_9 ( V_34 , & V_10 -> V_12 ) ;
if ( V_11 < 0 )
return V_11 ;
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
struct V_25 * V_24 ,
struct V_50 * * V_52 ,
const char * * V_53 ,
int * V_54 )
{
struct V_55 args ;
struct V_13 * V_13 ;
T_1 V_56 ;
int V_11 ;
V_11 = F_18 ( V_51 , L_5 ,
L_6 , 0 , & args ) ;
if ( V_11 )
return V_11 ;
* V_52 = args . V_51 ;
if ( V_54 )
* V_54 = args . V_54 ;
V_11 = F_19 ( V_51 , V_53 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_20 ( V_51 , & V_24 -> V_30 ,
& V_24 -> V_31 ,
& V_24 -> V_29 , & V_24 -> V_32 ) ;
if ( V_11 )
return V_11 ;
if ( F_21 ( V_51 , L_7 ) ) {
V_13 = F_22 ( V_51 , 0 ) ;
if ( F_23 ( V_13 ) ) {
V_11 = F_24 ( V_13 ) ;
return V_11 ;
}
V_24 -> V_27 = F_25 ( V_13 ) ;
V_24 -> V_13 = V_13 ;
} else if ( ! F_26 ( V_51 , L_8 , & V_56 ) ) {
V_24 -> V_27 = V_56 ;
} else {
V_13 = F_22 ( args . V_51 , 0 ) ;
if ( ! F_23 ( V_13 ) )
V_24 -> V_27 = F_25 ( V_13 ) ;
}
return 0 ;
}
static int F_27 ( struct V_50 * V_57 ,
struct V_6 * V_7 ,
struct V_50 * V_33 ,
char * V_58 , int V_59 )
{
struct V_60 * V_61 = F_28 ( V_7 , V_59 ) ;
struct V_62 * V_28 = F_29 ( V_7 ) ;
struct V_50 * V_63 = NULL ;
struct V_50 * V_64 = NULL ;
unsigned int V_65 ;
V_65 = F_30 ( V_57 , V_58 ,
& V_63 , & V_64 ) ;
V_65 &= ~ V_66 ;
if ( strlen ( V_58 ) && ! V_63 && ! V_64 ) {
F_31 ( V_28 , L_9 ) ;
V_65 = F_30 ( V_33 , NULL , NULL , NULL ) |
( V_65 & ~ V_67 ) ;
} else {
if ( V_33 == V_63 )
V_65 |= ( V_33 == V_64 ) ?
V_68 : V_69 ;
else
V_65 |= ( V_33 == V_64 ) ?
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
struct V_62 * V_28 = F_29 ( V_7 ) ;
struct V_60 * V_61 = F_28 ( V_7 , V_59 ) ;
struct V_9 * V_10 = F_34 ( V_7 , V_59 ) ;
struct V_50 * V_34 = NULL ;
struct V_50 * V_74 = NULL ;
struct V_50 * V_33 = NULL ;
char * V_53 ;
char V_75 [ 128 ] ;
char * V_58 = L_10 ;
int V_11 , V_76 ;
T_1 V_56 ;
if ( V_73 )
V_58 = L_11 ;
snprintf ( V_75 , sizeof( V_75 ) , L_12 , V_58 ) ;
V_34 = F_35 ( V_57 , V_75 ) ;
snprintf ( V_75 , sizeof( V_75 ) , L_13 , V_58 ) ;
V_74 = F_35 ( V_57 , V_75 ) ;
snprintf ( V_75 , sizeof( V_75 ) , L_14 , V_58 ) ;
V_33 = F_35 ( V_57 , V_75 ) ;
if ( ! V_34 || ! V_33 ) {
V_11 = - V_77 ;
F_10 ( V_28 , L_15 , V_78 , V_75 ) ;
goto V_79;
}
V_11 = F_27 ( V_57 , V_7 ,
V_33 , V_58 , V_59 ) ;
if ( V_11 < 0 )
goto V_79;
if ( ! F_26 ( V_57 , L_16 , & V_56 ) )
V_10 -> V_19 = V_56 ;
V_11 = F_17 ( V_34 , & V_10 -> V_12 ,
& V_61 -> V_80 ,
& V_61 -> V_81 ,
& V_76 ) ;
if ( V_11 < 0 )
goto V_79;
V_11 = F_17 ( V_33 , & V_10 -> V_14 ,
& V_61 -> V_82 ,
& V_61 -> V_83 , NULL ) ;
if ( V_11 < 0 )
goto V_79;
if ( ! V_61 -> V_81 || ! V_61 -> V_83 ) {
V_11 = - V_77 ;
goto V_79;
}
if ( V_74 ) {
struct V_55 args ;
V_11 = F_18 ( V_74 , L_5 ,
L_6 , 0 , & args ) ;
V_61 -> V_84 = args . V_51 ;
} else {
V_61 -> V_84 = V_61 -> V_80 ;
}
V_53 = F_36 ( V_28 ,
strlen ( V_61 -> V_81 ) +
strlen ( V_61 -> V_83 ) + 2 ,
V_85 ) ;
if ( ! V_53 ) {
V_11 = - V_86 ;
goto V_79;
}
sprintf ( V_53 , L_17 , V_61 -> V_81 ,
V_61 -> V_83 ) ;
V_61 -> V_53 = V_61 -> V_87 = V_53 ;
V_61 -> V_88 = & V_89 ;
V_61 -> V_90 = F_12 ;
F_31 ( V_28 , L_18 , V_61 -> V_87 ) ;
F_31 ( V_28 , L_19 , V_61 -> V_72 ) ;
F_31 ( V_28 , L_20 ,
V_61 -> V_81 ,
V_10 -> V_12 . V_27 ) ;
F_31 ( V_28 , L_21 ,
V_61 -> V_83 ,
V_10 -> V_14 . V_27 ) ;
if ( ! V_76 )
V_61 -> V_81 = NULL ;
V_79:
F_32 ( V_34 ) ;
F_32 ( V_33 ) ;
return V_11 ;
}
static int F_37 ( struct V_50 * V_57 ,
struct V_6 * V_7 )
{
struct V_62 * V_28 = F_29 ( V_7 ) ;
enum V_91 V_92 ;
T_1 V_56 ;
int V_11 ;
if ( ! V_57 )
return - V_77 ;
F_38 ( & V_7 -> V_93 , L_22 ) ;
if ( F_21 ( V_57 , L_23 ) ) {
V_11 = F_39 ( & V_7 -> V_93 ,
L_23 ) ;
if ( V_11 )
return V_11 ;
}
if ( F_21 ( V_57 , L_24 ) ) {
V_11 = F_40 ( & V_7 -> V_93 ,
L_24 ) ;
if ( V_11 )
return V_11 ;
}
V_11 = F_26 ( V_57 , L_25 , & V_56 ) ;
if ( V_11 == 0 )
V_7 -> V_19 = V_56 ;
F_31 ( V_28 , L_26 , V_7 -> V_93 . V_53 ?
V_7 -> V_93 . V_53 : L_10 ) ;
if ( F_35 ( V_57 , L_27 ) ) {
struct V_50 * V_51 = NULL ;
int V_94 = 0 ;
F_41 (node, np) {
F_31 ( V_28 , L_28 , V_94 ) ;
V_11 = F_33 ( V_51 , V_7 ,
V_94 , false ) ;
if ( V_11 < 0 ) {
F_32 ( V_51 ) ;
return V_11 ;
}
V_94 ++ ;
}
} else {
V_11 = F_33 ( V_57 , V_7 , 0 , true ) ;
if ( V_11 < 0 )
return V_11 ;
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
struct V_50 * V_51 = V_100 -> V_28 . V_101 ;
struct V_62 * V_28 = & V_100 -> V_28 ;
int V_98 , V_11 ;
if ( V_51 && F_35 ( V_51 , L_27 ) )
V_98 = F_45 ( V_51 ) ;
else
V_98 = 1 ;
V_7 = F_36 ( V_28 ,
sizeof( * V_7 ) + sizeof( * V_61 ) * V_98 ,
V_85 ) ;
if ( ! V_7 )
return - V_86 ;
V_7 -> V_93 . V_102 = V_103 ;
V_7 -> V_93 . V_28 = V_28 ;
V_61 = V_7 -> V_61 ;
V_7 -> V_93 . V_61 = V_61 ;
V_7 -> V_93 . V_98 = V_98 ;
V_7 -> V_36 = - V_104 ;
V_7 -> V_44 = - V_104 ;
V_7 -> V_10 = F_36 ( V_28 ,
sizeof( * V_7 -> V_10 ) * V_98 ,
V_85 ) ;
if ( ! V_7 -> V_10 )
return - V_86 ;
if ( V_51 && F_46 ( V_51 ) ) {
V_11 = F_37 ( V_51 , V_7 ) ;
if ( V_11 < 0 ) {
if ( V_11 != - V_96 )
F_10 ( V_28 , L_31 , V_11 ) ;
goto V_22;
}
} else {
struct V_105 * V_106 ;
V_106 = V_28 -> V_107 ;
if ( ! V_106 ) {
F_10 ( V_28 , L_32 ) ;
return - V_77 ;
}
if ( ! V_106 -> V_53 ||
! V_106 -> V_14 . V_53 ||
! V_106 -> V_33 ||
! V_106 -> V_108 ||
! V_106 -> V_12 . V_53 ) {
F_10 ( V_28 , L_33 ) ;
return - V_77 ;
}
V_7 -> V_93 . V_53 = ( V_106 -> V_8 ) ? V_106 -> V_8 : V_106 -> V_53 ;
V_61 -> V_53 = V_106 -> V_53 ;
V_61 -> V_87 = V_106 -> V_53 ;
V_61 -> V_109 = V_106 -> V_108 ;
V_61 -> V_110 = V_106 -> V_33 ;
V_61 -> V_81 = V_106 -> V_12 . V_53 ;
V_61 -> V_83 = V_106 -> V_14 . V_53 ;
V_61 -> V_72 = V_106 -> V_65 ;
V_61 -> V_90 = F_12 ;
memcpy ( & V_7 -> V_10 -> V_12 , & V_106 -> V_12 ,
sizeof( V_7 -> V_10 -> V_12 ) ) ;
memcpy ( & V_7 -> V_10 -> V_14 , & V_106 -> V_14 ,
sizeof( V_7 -> V_10 -> V_14 ) ) ;
}
F_47 ( & V_7 -> V_93 , V_7 ) ;
V_11 = F_48 ( & V_100 -> V_28 , & V_7 -> V_93 ) ;
if ( V_11 >= 0 )
return V_11 ;
V_22:
F_43 ( & V_7 -> V_93 ) ;
return V_11 ;
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
