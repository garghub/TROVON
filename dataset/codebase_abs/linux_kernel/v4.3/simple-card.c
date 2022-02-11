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
V_11 = F_11 ( V_24 , 0 , 0 ,
V_26 -> V_29 ,
V_26 -> V_30 ) ;
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
struct V_17 * V_31 = V_4 -> V_14 ;
struct V_17 * V_32 = V_4 -> V_12 ;
struct V_9 * V_10 ;
int V_33 , V_11 ;
V_33 = V_4 - V_4 -> V_8 -> V_4 ;
V_10 = & V_7 -> V_10 [ V_33 ] ;
V_11 = F_9 ( V_31 , & V_10 -> V_14 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_9 ( V_32 , & V_10 -> V_12 ) ;
if ( V_11 < 0 )
return V_11 ;
if ( F_13 ( V_7 -> V_34 ) ) {
F_14 ( V_4 -> V_8 , L_3 ,
V_35 ,
& V_36 ,
V_37 ,
F_15 ( V_37 ) ) ;
V_38 . V_39 = V_7 -> V_34 ;
V_38 . V_40 = V_7 -> V_41 ;
F_16 ( & V_36 , 1 ,
& V_38 ) ;
}
if ( F_13 ( V_7 -> V_42 ) ) {
F_14 ( V_4 -> V_8 , L_4 ,
V_43 ,
& V_44 ,
V_45 ,
F_15 ( V_45 ) ) ;
V_46 . V_39 = V_7 -> V_42 ;
V_46 . V_40 = V_7 -> V_47 ;
F_16 ( & V_44 , 1 ,
& V_46 ) ;
}
return 0 ;
}
static int
F_17 ( struct V_48 * V_49 ,
struct V_25 * V_24 ,
struct V_48 * * V_50 ,
const char * * V_51 ,
int * V_52 )
{
struct V_53 args ;
struct V_13 * V_13 ;
T_1 V_54 ;
int V_11 ;
V_11 = F_18 ( V_49 , L_5 ,
L_6 , 0 , & args ) ;
if ( V_11 )
return V_11 ;
* V_50 = args . V_49 ;
if ( V_52 )
* V_52 = args . V_52 ;
V_11 = F_19 ( V_49 , V_51 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_20 ( V_49 , & V_24 -> V_29 , & V_24 -> V_30 ) ;
if ( V_11 )
return V_11 ;
if ( F_21 ( V_49 , L_7 ) ) {
V_13 = F_22 ( V_49 , 0 ) ;
if ( F_23 ( V_13 ) ) {
V_11 = F_24 ( V_13 ) ;
return V_11 ;
}
V_24 -> V_27 = F_25 ( V_13 ) ;
V_24 -> V_13 = V_13 ;
} else if ( ! F_26 ( V_49 , L_8 , & V_54 ) ) {
V_24 -> V_27 = V_54 ;
} else {
V_13 = F_22 ( args . V_49 , 0 ) ;
if ( ! F_23 ( V_13 ) )
V_24 -> V_27 = F_25 ( V_13 ) ;
}
return 0 ;
}
static int F_27 ( struct V_48 * V_55 ,
struct V_6 * V_7 ,
struct V_48 * V_31 ,
char * V_56 , int V_57 )
{
struct V_58 * V_59 = F_28 ( V_7 , V_57 ) ;
struct V_60 * V_28 = F_29 ( V_7 ) ;
struct V_48 * V_61 = NULL ;
struct V_48 * V_62 = NULL ;
unsigned int V_63 ;
V_63 = F_30 ( V_55 , V_56 ,
& V_61 , & V_62 ) ;
V_63 &= ~ V_64 ;
if ( strlen ( V_56 ) && ! V_61 && ! V_62 ) {
F_31 ( V_28 , L_9 ) ;
V_63 = F_30 ( V_31 , NULL , NULL , NULL ) |
( V_63 & ~ V_65 ) ;
} else {
if ( V_31 == V_61 )
V_63 |= ( V_31 == V_62 ) ?
V_66 : V_67 ;
else
V_63 |= ( V_31 == V_62 ) ?
V_68 : V_69 ;
}
V_59 -> V_70 = V_63 ;
F_32 ( V_61 ) ;
F_32 ( V_62 ) ;
return 0 ;
}
static int F_33 ( struct V_48 * V_55 ,
struct V_6 * V_7 ,
int V_57 ,
bool V_71 )
{
struct V_60 * V_28 = F_29 ( V_7 ) ;
struct V_58 * V_59 = F_28 ( V_7 , V_57 ) ;
struct V_9 * V_10 = F_34 ( V_7 , V_57 ) ;
struct V_48 * V_32 = NULL ;
struct V_48 * V_72 = NULL ;
struct V_48 * V_31 = NULL ;
char * V_51 ;
char V_73 [ 128 ] ;
char * V_56 = L_10 ;
int V_11 , V_74 ;
T_1 V_54 ;
if ( V_71 )
V_56 = L_11 ;
snprintf ( V_73 , sizeof( V_73 ) , L_12 , V_56 ) ;
V_32 = F_35 ( V_55 , V_73 ) ;
snprintf ( V_73 , sizeof( V_73 ) , L_13 , V_56 ) ;
V_72 = F_35 ( V_55 , V_73 ) ;
snprintf ( V_73 , sizeof( V_73 ) , L_14 , V_56 ) ;
V_31 = F_35 ( V_55 , V_73 ) ;
if ( ! V_32 || ! V_31 ) {
V_11 = - V_75 ;
F_10 ( V_28 , L_15 , V_76 , V_73 ) ;
goto V_77;
}
V_11 = F_27 ( V_55 , V_7 ,
V_31 , V_56 , V_57 ) ;
if ( V_11 < 0 )
goto V_77;
if ( ! F_26 ( V_55 , L_16 , & V_54 ) )
V_10 -> V_19 = V_54 ;
V_11 = F_17 ( V_32 , & V_10 -> V_12 ,
& V_59 -> V_78 ,
& V_59 -> V_79 ,
& V_74 ) ;
if ( V_11 < 0 )
goto V_77;
V_11 = F_17 ( V_31 , & V_10 -> V_14 ,
& V_59 -> V_80 ,
& V_59 -> V_81 , NULL ) ;
if ( V_11 < 0 )
goto V_77;
if ( ! V_59 -> V_79 || ! V_59 -> V_81 ) {
V_11 = - V_75 ;
goto V_77;
}
if ( V_72 ) {
struct V_53 args ;
V_11 = F_18 ( V_72 , L_5 ,
L_6 , 0 , & args ) ;
V_59 -> V_82 = args . V_49 ;
} else {
V_59 -> V_82 = V_59 -> V_78 ;
}
V_51 = F_36 ( V_28 ,
strlen ( V_59 -> V_79 ) +
strlen ( V_59 -> V_81 ) + 2 ,
V_83 ) ;
if ( ! V_51 ) {
V_11 = - V_84 ;
goto V_77;
}
sprintf ( V_51 , L_17 , V_59 -> V_79 ,
V_59 -> V_81 ) ;
V_59 -> V_51 = V_59 -> V_85 = V_51 ;
V_59 -> V_86 = & V_87 ;
V_59 -> V_88 = F_12 ;
F_31 ( V_28 , L_18 , V_59 -> V_85 ) ;
F_31 ( V_28 , L_19 , V_59 -> V_70 ) ;
F_31 ( V_28 , L_20 ,
V_59 -> V_79 ,
V_10 -> V_12 . V_27 ) ;
F_31 ( V_28 , L_21 ,
V_59 -> V_81 ,
V_10 -> V_14 . V_27 ) ;
if ( ! V_74 )
V_59 -> V_79 = NULL ;
V_77:
F_32 ( V_32 ) ;
F_32 ( V_31 ) ;
return V_11 ;
}
static int F_37 ( struct V_48 * V_55 ,
struct V_6 * V_7 )
{
struct V_60 * V_28 = F_29 ( V_7 ) ;
enum V_89 V_90 ;
T_1 V_54 ;
int V_11 ;
if ( ! V_55 )
return - V_75 ;
F_38 ( & V_7 -> V_91 , L_22 ) ;
if ( F_21 ( V_55 , L_23 ) ) {
V_11 = F_39 ( & V_7 -> V_91 ,
L_23 ) ;
if ( V_11 )
return V_11 ;
}
if ( F_21 ( V_55 , L_24 ) ) {
V_11 = F_40 ( & V_7 -> V_91 ,
L_24 ) ;
if ( V_11 )
return V_11 ;
}
V_11 = F_26 ( V_55 , L_25 , & V_54 ) ;
if ( V_11 == 0 )
V_7 -> V_19 = V_54 ;
F_31 ( V_28 , L_26 , V_7 -> V_91 . V_51 ?
V_7 -> V_91 . V_51 : L_10 ) ;
if ( F_35 ( V_55 , L_27 ) ) {
struct V_48 * V_49 = NULL ;
int V_92 = 0 ;
F_41 (node, np) {
F_31 ( V_28 , L_28 , V_92 ) ;
V_11 = F_33 ( V_49 , V_7 ,
V_92 , false ) ;
if ( V_11 < 0 ) {
F_32 ( V_49 ) ;
return V_11 ;
}
V_92 ++ ;
}
} else {
V_11 = F_33 ( V_55 , V_7 , 0 , true ) ;
if ( V_11 < 0 )
return V_11 ;
}
V_7 -> V_34 = F_42 ( V_55 ,
L_29 , 0 , & V_90 ) ;
V_7 -> V_41 = ! ! ( V_90 & V_93 ) ;
if ( V_7 -> V_34 == - V_94 )
return - V_94 ;
V_7 -> V_42 = F_42 ( V_55 ,
L_30 , 0 , & V_90 ) ;
V_7 -> V_47 = ! ! ( V_90 & V_93 ) ;
if ( V_7 -> V_42 == - V_94 )
return - V_94 ;
if ( ! V_7 -> V_91 . V_51 )
V_7 -> V_91 . V_51 = V_7 -> V_91 . V_59 -> V_51 ;
return 0 ;
}
static int F_43 ( struct V_95 * V_8 )
{
struct V_58 * V_59 ;
int V_96 ;
for ( V_96 = 0 , V_59 = V_8 -> V_59 ;
V_96 < V_8 -> V_96 ;
V_96 ++ , V_59 ++ ) {
F_32 ( V_59 -> V_78 ) ;
F_32 ( V_59 -> V_80 ) ;
}
return 0 ;
}
static int F_44 ( struct V_97 * V_98 )
{
struct V_6 * V_7 ;
struct V_58 * V_59 ;
struct V_48 * V_49 = V_98 -> V_28 . V_99 ;
struct V_60 * V_28 = & V_98 -> V_28 ;
int V_96 , V_11 ;
if ( V_49 && F_35 ( V_49 , L_27 ) )
V_96 = F_45 ( V_49 ) ;
else
V_96 = 1 ;
V_7 = F_36 ( V_28 ,
sizeof( * V_7 ) + sizeof( * V_59 ) * V_96 ,
V_83 ) ;
if ( ! V_7 )
return - V_84 ;
V_7 -> V_91 . V_100 = V_101 ;
V_7 -> V_91 . V_28 = V_28 ;
V_59 = V_7 -> V_59 ;
V_7 -> V_91 . V_59 = V_59 ;
V_7 -> V_91 . V_96 = V_96 ;
V_7 -> V_34 = - V_102 ;
V_7 -> V_42 = - V_102 ;
V_7 -> V_10 = F_36 ( V_28 ,
sizeof( * V_7 -> V_10 ) * V_96 ,
V_83 ) ;
if ( ! V_7 -> V_10 )
return - V_84 ;
if ( V_49 && F_46 ( V_49 ) ) {
V_11 = F_37 ( V_49 , V_7 ) ;
if ( V_11 < 0 ) {
if ( V_11 != - V_94 )
F_10 ( V_28 , L_31 , V_11 ) ;
goto V_22;
}
} else {
struct V_103 * V_104 ;
V_104 = V_28 -> V_105 ;
if ( ! V_104 ) {
F_10 ( V_28 , L_32 ) ;
return - V_75 ;
}
if ( ! V_104 -> V_51 ||
! V_104 -> V_14 . V_51 ||
! V_104 -> V_31 ||
! V_104 -> V_106 ||
! V_104 -> V_12 . V_51 ) {
F_10 ( V_28 , L_33 ) ;
return - V_75 ;
}
V_7 -> V_91 . V_51 = ( V_104 -> V_8 ) ? V_104 -> V_8 : V_104 -> V_51 ;
V_59 -> V_51 = V_104 -> V_51 ;
V_59 -> V_85 = V_104 -> V_51 ;
V_59 -> V_107 = V_104 -> V_106 ;
V_59 -> V_108 = V_104 -> V_31 ;
V_59 -> V_79 = V_104 -> V_12 . V_51 ;
V_59 -> V_81 = V_104 -> V_14 . V_51 ;
V_59 -> V_70 = V_104 -> V_63 ;
V_59 -> V_88 = F_12 ;
memcpy ( & V_7 -> V_10 -> V_12 , & V_104 -> V_12 ,
sizeof( V_7 -> V_10 -> V_12 ) ) ;
memcpy ( & V_7 -> V_10 -> V_14 , & V_104 -> V_14 ,
sizeof( V_7 -> V_10 -> V_14 ) ) ;
}
F_47 ( & V_7 -> V_91 , V_7 ) ;
V_11 = F_48 ( & V_98 -> V_28 , & V_7 -> V_91 ) ;
if ( V_11 >= 0 )
return V_11 ;
V_22:
F_43 ( & V_7 -> V_91 ) ;
return V_11 ;
}
static int F_49 ( struct V_97 * V_98 )
{
struct V_95 * V_8 = F_50 ( V_98 ) ;
struct V_6 * V_7 = F_2 ( V_8 ) ;
if ( F_13 ( V_7 -> V_34 ) )
F_51 ( & V_36 , 1 ,
& V_38 ) ;
if ( F_13 ( V_7 -> V_42 ) )
F_51 ( & V_44 , 1 ,
& V_46 ) ;
return F_43 ( V_8 ) ;
}
