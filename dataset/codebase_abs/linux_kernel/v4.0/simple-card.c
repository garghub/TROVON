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
struct V_6 * V_7 = F_2 ( V_4 -> V_8 ) ;
unsigned int V_18 ;
int V_11 = 0 ;
if ( V_7 -> V_19 ) {
V_18 = F_7 ( V_16 ) * V_7 -> V_19 ;
V_11 = F_8 ( V_14 , 0 , V_18 ,
V_20 ) ;
}
return V_11 ;
}
static int F_9 ( struct V_17 * V_21 ,
struct V_22 * V_23 )
{
int V_11 ;
if ( V_23 -> V_24 ) {
V_11 = F_10 ( V_21 , V_23 -> V_24 ) ;
if ( V_11 && V_11 != - V_25 ) {
F_11 ( V_21 -> V_26 , L_1 ) ;
goto V_27;
}
}
if ( V_23 -> V_28 ) {
V_11 = F_8 ( V_21 , 0 , V_23 -> V_28 , 0 ) ;
if ( V_11 && V_11 != - V_25 ) {
F_11 ( V_21 -> V_26 , L_2 ) ;
goto V_27;
}
}
if ( V_23 -> V_29 ) {
V_11 = F_12 ( V_21 , 0 , 0 ,
V_23 -> V_29 ,
V_23 -> V_30 ) ;
if ( V_11 && V_11 != - V_25 ) {
F_11 ( V_21 -> V_26 , L_3 ) ;
goto V_27;
}
}
V_11 = 0 ;
V_27:
return V_11 ;
}
static int F_13 ( struct V_3 * V_4 )
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
if ( F_14 ( V_7 -> V_34 ) ) {
F_15 ( V_31 -> V_31 , L_4 , V_35 ,
& V_36 ) ;
F_16 ( & V_36 ,
F_17 ( V_37 ) ,
V_37 ) ;
V_38 . V_39 = V_7 -> V_34 ;
V_38 . V_40 = V_7 -> V_41 ;
F_18 ( & V_36 , 1 ,
& V_38 ) ;
}
if ( F_14 ( V_7 -> V_42 ) ) {
F_15 ( V_31 -> V_31 , L_5 , V_43 ,
& V_44 ) ;
F_16 ( & V_44 ,
F_17 ( V_45 ) ,
V_45 ) ;
V_46 . V_39 = V_7 -> V_42 ;
V_46 . V_40 = V_7 -> V_47 ;
F_18 ( & V_44 , 1 ,
& V_46 ) ;
}
return 0 ;
}
static int
F_19 ( struct V_48 * V_49 ,
struct V_22 * V_21 ,
struct V_48 * * V_50 ,
const char * * V_51 ,
int * V_52 )
{
struct V_53 args ;
struct V_13 * V_13 ;
T_1 V_54 ;
int V_11 ;
V_11 = F_20 ( V_49 , L_6 ,
L_7 , 0 , & args ) ;
if ( V_11 )
return V_11 ;
* V_50 = args . V_49 ;
if ( V_52 )
* V_52 = args . V_52 ;
V_11 = F_21 ( V_49 , V_51 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_22 ( V_49 , & V_21 -> V_29 , & V_21 -> V_30 ) ;
if ( V_11 )
return V_11 ;
if ( F_23 ( V_49 , L_8 ) ) {
V_13 = F_24 ( V_49 , 0 ) ;
if ( F_25 ( V_13 ) ) {
V_11 = F_26 ( V_13 ) ;
return V_11 ;
}
V_21 -> V_28 = F_27 ( V_13 ) ;
V_21 -> V_13 = V_13 ;
} else if ( ! F_28 ( V_49 , L_9 , & V_54 ) ) {
V_21 -> V_28 = V_54 ;
} else {
V_13 = F_24 ( args . V_49 , 0 ) ;
if ( ! F_25 ( V_13 ) )
V_21 -> V_28 = F_27 ( V_13 ) ;
}
return 0 ;
}
static int F_29 ( struct V_48 * V_55 ,
struct V_6 * V_7 ,
struct V_48 * V_31 ,
char * V_56 , int V_57 )
{
struct V_58 * V_26 = F_30 ( V_7 ) ;
struct V_48 * V_59 = NULL ;
struct V_48 * V_60 = NULL ;
struct V_9 * V_10 = F_31 ( V_7 , V_57 ) ;
struct V_22 * V_12 = & V_10 -> V_12 ;
struct V_22 * V_14 = & V_10 -> V_14 ;
unsigned int V_61 ;
V_61 = F_32 ( V_55 , V_56 ,
& V_59 , & V_60 ) ;
V_61 &= ~ V_62 ;
if ( strlen ( V_56 ) && ! V_59 && ! V_60 ) {
F_33 ( V_26 , L_10 ) ;
V_12 -> V_24 = V_14 -> V_24 =
F_32 ( V_31 , NULL , NULL , NULL ) |
( V_61 & ~ V_63 ) ;
} else {
if ( V_31 == V_59 )
V_61 |= ( V_31 == V_60 ) ?
V_64 : V_65 ;
else
V_61 |= ( V_31 == V_60 ) ?
V_66 : V_67 ;
V_12 -> V_24 = V_61 ;
V_14 -> V_24 = V_61 ;
}
F_34 ( V_59 ) ;
F_34 ( V_60 ) ;
return 0 ;
}
static int F_35 ( struct V_48 * V_55 ,
struct V_6 * V_7 ,
int V_57 ,
bool V_68 )
{
struct V_58 * V_26 = F_30 ( V_7 ) ;
struct V_69 * V_70 = F_36 ( V_7 , V_57 ) ;
struct V_9 * V_10 = F_31 ( V_7 , V_57 ) ;
struct V_48 * V_32 = NULL ;
struct V_48 * V_31 = NULL ;
char * V_51 ;
char V_71 [ 128 ] ;
char * V_56 = L_11 ;
int V_11 , V_72 ;
if ( V_68 )
V_56 = L_12 ;
snprintf ( V_71 , sizeof( V_71 ) , L_13 , V_56 ) ;
V_32 = F_37 ( V_55 , V_71 ) ;
snprintf ( V_71 , sizeof( V_71 ) , L_14 , V_56 ) ;
V_31 = F_37 ( V_55 , V_71 ) ;
if ( ! V_32 || ! V_31 ) {
V_11 = - V_73 ;
F_11 ( V_26 , L_15 , V_74 , V_71 ) ;
goto V_75;
}
V_11 = F_29 ( V_55 , V_7 ,
V_31 , V_56 , V_57 ) ;
if ( V_11 < 0 )
goto V_75;
V_11 = F_19 ( V_32 , & V_10 -> V_12 ,
& V_70 -> V_76 ,
& V_70 -> V_77 ,
& V_72 ) ;
if ( V_11 < 0 )
goto V_75;
V_11 = F_19 ( V_31 , & V_10 -> V_14 ,
& V_70 -> V_78 ,
& V_70 -> V_79 , NULL ) ;
if ( V_11 < 0 )
goto V_75;
if ( ! V_70 -> V_77 || ! V_70 -> V_79 ) {
V_11 = - V_73 ;
goto V_75;
}
V_70 -> V_80 = V_70 -> V_76 ;
V_51 = F_38 ( V_26 ,
strlen ( V_70 -> V_77 ) +
strlen ( V_70 -> V_79 ) + 2 ,
V_81 ) ;
if ( ! V_51 ) {
V_11 = - V_82 ;
goto V_75;
}
sprintf ( V_51 , L_16 , V_70 -> V_77 ,
V_70 -> V_79 ) ;
V_70 -> V_51 = V_70 -> V_83 = V_51 ;
V_70 -> V_84 = & V_85 ;
V_70 -> V_86 = F_13 ;
F_33 ( V_26 , L_17 , V_70 -> V_83 ) ;
F_33 ( V_26 , L_18 ,
V_70 -> V_77 ,
V_10 -> V_12 . V_24 ,
V_10 -> V_12 . V_28 ) ;
F_33 ( V_26 , L_19 ,
V_70 -> V_79 ,
V_10 -> V_14 . V_24 ,
V_10 -> V_14 . V_28 ) ;
if ( ! V_72 )
V_70 -> V_77 = NULL ;
V_75:
F_34 ( V_32 ) ;
F_34 ( V_31 ) ;
return V_11 ;
}
static int F_39 ( struct V_48 * V_55 ,
struct V_6 * V_7 )
{
struct V_58 * V_26 = F_30 ( V_7 ) ;
enum V_87 V_88 ;
T_1 V_54 ;
int V_11 ;
if ( ! V_55 )
return - V_73 ;
F_40 ( & V_7 -> V_89 , L_20 ) ;
if ( F_23 ( V_55 , L_21 ) ) {
V_11 = F_41 ( & V_7 -> V_89 ,
L_21 ) ;
if ( V_11 )
return V_11 ;
}
if ( F_23 ( V_55 , L_22 ) ) {
V_11 = F_42 ( & V_7 -> V_89 ,
L_22 ) ;
if ( V_11 )
return V_11 ;
}
V_11 = F_28 ( V_55 , L_23 , & V_54 ) ;
if ( V_11 == 0 )
V_7 -> V_19 = V_54 ;
F_33 ( V_26 , L_24 , V_7 -> V_89 . V_51 ?
V_7 -> V_89 . V_51 : L_11 ) ;
if ( F_37 ( V_55 , L_25 ) ) {
struct V_48 * V_49 = NULL ;
int V_90 = 0 ;
F_43 (node, np) {
F_33 ( V_26 , L_26 , V_90 ) ;
V_11 = F_35 ( V_49 , V_7 ,
V_90 , false ) ;
if ( V_11 < 0 ) {
F_34 ( V_49 ) ;
return V_11 ;
}
V_90 ++ ;
}
} else {
V_11 = F_35 ( V_55 , V_7 , 0 , true ) ;
if ( V_11 < 0 )
return V_11 ;
}
V_7 -> V_34 = F_44 ( V_55 ,
L_27 , 0 , & V_88 ) ;
V_7 -> V_41 = ! ! ( V_88 & V_91 ) ;
if ( V_7 -> V_34 == - V_92 )
return - V_92 ;
V_7 -> V_42 = F_44 ( V_55 ,
L_28 , 0 , & V_88 ) ;
V_7 -> V_47 = ! ! ( V_88 & V_91 ) ;
if ( V_7 -> V_42 == - V_92 )
return - V_92 ;
if ( ! V_7 -> V_89 . V_51 )
V_7 -> V_89 . V_51 = V_7 -> V_89 . V_70 -> V_51 ;
return 0 ;
}
static int F_45 ( struct V_93 * V_8 )
{
struct V_69 * V_70 ;
int V_94 ;
for ( V_94 = 0 , V_70 = V_8 -> V_70 ;
V_94 < V_8 -> V_94 ;
V_94 ++ , V_70 ++ ) {
F_34 ( V_70 -> V_76 ) ;
F_34 ( V_70 -> V_78 ) ;
}
return 0 ;
}
static int F_46 ( struct V_95 * V_96 )
{
struct V_6 * V_7 ;
struct V_69 * V_70 ;
struct V_48 * V_49 = V_96 -> V_26 . V_97 ;
struct V_58 * V_26 = & V_96 -> V_26 ;
int V_94 , V_11 ;
if ( V_49 && F_37 ( V_49 , L_25 ) )
V_94 = F_47 ( V_49 ) ;
else
V_94 = 1 ;
V_7 = F_38 ( V_26 ,
sizeof( * V_7 ) + sizeof( * V_70 ) * V_94 ,
V_81 ) ;
if ( ! V_7 )
return - V_82 ;
V_7 -> V_89 . V_98 = V_99 ;
V_7 -> V_89 . V_26 = V_26 ;
V_70 = V_7 -> V_70 ;
V_7 -> V_89 . V_70 = V_70 ;
V_7 -> V_89 . V_94 = V_94 ;
V_7 -> V_34 = - V_100 ;
V_7 -> V_42 = - V_100 ;
V_7 -> V_10 = F_38 ( V_26 ,
sizeof( * V_7 -> V_10 ) * V_94 ,
V_81 ) ;
if ( ! V_7 -> V_10 )
return - V_82 ;
if ( V_49 && F_48 ( V_49 ) ) {
V_11 = F_39 ( V_49 , V_7 ) ;
if ( V_11 < 0 ) {
if ( V_11 != - V_92 )
F_11 ( V_26 , L_29 , V_11 ) ;
goto V_27;
}
} else {
struct V_101 * V_102 ;
V_102 = V_26 -> V_103 ;
if ( ! V_102 ) {
F_11 ( V_26 , L_30 ) ;
return - V_73 ;
}
if ( ! V_102 -> V_51 ||
! V_102 -> V_14 . V_51 ||
! V_102 -> V_31 ||
! V_102 -> V_104 ||
! V_102 -> V_12 . V_51 ) {
F_11 ( V_26 , L_31 ) ;
return - V_73 ;
}
V_7 -> V_89 . V_51 = ( V_102 -> V_8 ) ? V_102 -> V_8 : V_102 -> V_51 ;
V_70 -> V_51 = V_102 -> V_51 ;
V_70 -> V_83 = V_102 -> V_51 ;
V_70 -> V_105 = V_102 -> V_104 ;
V_70 -> V_106 = V_102 -> V_31 ;
V_70 -> V_77 = V_102 -> V_12 . V_51 ;
V_70 -> V_79 = V_102 -> V_14 . V_51 ;
V_70 -> V_86 = F_13 ;
memcpy ( & V_7 -> V_10 -> V_12 , & V_102 -> V_12 ,
sizeof( V_7 -> V_10 -> V_12 ) ) ;
memcpy ( & V_7 -> V_10 -> V_14 , & V_102 -> V_14 ,
sizeof( V_7 -> V_10 -> V_14 ) ) ;
V_7 -> V_10 -> V_12 . V_24 |= V_102 -> V_61 ;
V_7 -> V_10 -> V_14 . V_24 |= V_102 -> V_61 ;
}
F_49 ( & V_7 -> V_89 , V_7 ) ;
V_11 = F_50 ( & V_96 -> V_26 , & V_7 -> V_89 ) ;
if ( V_11 >= 0 )
return V_11 ;
V_27:
F_45 ( & V_7 -> V_89 ) ;
return V_11 ;
}
static int F_51 ( struct V_95 * V_96 )
{
struct V_93 * V_8 = F_52 ( V_96 ) ;
struct V_6 * V_7 = F_2 ( V_8 ) ;
if ( F_14 ( V_7 -> V_34 ) )
F_53 ( & V_36 , 1 ,
& V_38 ) ;
if ( F_14 ( V_7 -> V_42 ) )
F_53 ( & V_44 , 1 ,
& V_46 ) ;
return F_45 ( V_8 ) ;
}
