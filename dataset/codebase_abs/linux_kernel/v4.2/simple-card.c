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
}
return V_11 ;
}
static int F_9 ( struct V_17 * V_21 ,
struct V_22 * V_23 )
{
int V_11 ;
if ( V_23 -> V_24 ) {
V_11 = F_8 ( V_21 , 0 , V_23 -> V_24 , 0 ) ;
if ( V_11 && V_11 != - V_25 ) {
F_10 ( V_21 -> V_26 , L_1 ) ;
goto V_27;
}
}
if ( V_23 -> V_28 ) {
V_11 = F_11 ( V_21 , 0 , 0 ,
V_23 -> V_28 ,
V_23 -> V_29 ) ;
if ( V_11 && V_11 != - V_25 ) {
F_10 ( V_21 -> V_26 , L_2 ) ;
goto V_27;
}
}
V_11 = 0 ;
V_27:
return V_11 ;
}
static int F_12 ( struct V_3 * V_4 )
{
struct V_6 * V_7 = F_2 ( V_4 -> V_8 ) ;
struct V_17 * V_30 = V_4 -> V_14 ;
struct V_17 * V_31 = V_4 -> V_12 ;
struct V_9 * V_10 ;
int V_32 , V_11 ;
V_32 = V_4 - V_4 -> V_8 -> V_4 ;
V_10 = & V_7 -> V_10 [ V_32 ] ;
V_11 = F_9 ( V_30 , & V_10 -> V_14 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_9 ( V_31 , & V_10 -> V_12 ) ;
if ( V_11 < 0 )
return V_11 ;
if ( F_13 ( V_7 -> V_33 ) ) {
F_14 ( V_4 -> V_8 , L_3 ,
V_34 ,
& V_35 ,
V_36 ,
F_15 ( V_36 ) ) ;
V_37 . V_38 = V_7 -> V_33 ;
V_37 . V_39 = V_7 -> V_40 ;
F_16 ( & V_35 , 1 ,
& V_37 ) ;
}
if ( F_13 ( V_7 -> V_41 ) ) {
F_14 ( V_4 -> V_8 , L_4 ,
V_42 ,
& V_43 ,
V_44 ,
F_15 ( V_44 ) ) ;
V_45 . V_38 = V_7 -> V_41 ;
V_45 . V_39 = V_7 -> V_46 ;
F_16 ( & V_43 , 1 ,
& V_45 ) ;
}
return 0 ;
}
static int
F_17 ( struct V_47 * V_48 ,
struct V_22 * V_21 ,
struct V_47 * * V_49 ,
const char * * V_50 ,
int * V_51 )
{
struct V_52 args ;
struct V_13 * V_13 ;
T_1 V_53 ;
int V_11 ;
V_11 = F_18 ( V_48 , L_5 ,
L_6 , 0 , & args ) ;
if ( V_11 )
return V_11 ;
* V_49 = args . V_48 ;
if ( V_51 )
* V_51 = args . V_51 ;
V_11 = F_19 ( V_48 , V_50 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_20 ( V_48 , & V_21 -> V_28 , & V_21 -> V_29 ) ;
if ( V_11 )
return V_11 ;
if ( F_21 ( V_48 , L_7 ) ) {
V_13 = F_22 ( V_48 , 0 ) ;
if ( F_23 ( V_13 ) ) {
V_11 = F_24 ( V_13 ) ;
return V_11 ;
}
V_21 -> V_24 = F_25 ( V_13 ) ;
V_21 -> V_13 = V_13 ;
} else if ( ! F_26 ( V_48 , L_8 , & V_53 ) ) {
V_21 -> V_24 = V_53 ;
} else {
V_13 = F_22 ( args . V_48 , 0 ) ;
if ( ! F_23 ( V_13 ) )
V_21 -> V_24 = F_25 ( V_13 ) ;
}
return 0 ;
}
static int F_27 ( struct V_47 * V_54 ,
struct V_6 * V_7 ,
struct V_47 * V_30 ,
char * V_55 , int V_56 )
{
struct V_57 * V_58 = F_28 ( V_7 , V_56 ) ;
struct V_59 * V_26 = F_29 ( V_7 ) ;
struct V_47 * V_60 = NULL ;
struct V_47 * V_61 = NULL ;
unsigned int V_62 ;
V_62 = F_30 ( V_54 , V_55 ,
& V_60 , & V_61 ) ;
V_62 &= ~ V_63 ;
if ( strlen ( V_55 ) && ! V_60 && ! V_61 ) {
F_31 ( V_26 , L_9 ) ;
V_62 = F_30 ( V_30 , NULL , NULL , NULL ) |
( V_62 & ~ V_64 ) ;
} else {
if ( V_30 == V_60 )
V_62 |= ( V_30 == V_61 ) ?
V_65 : V_66 ;
else
V_62 |= ( V_30 == V_61 ) ?
V_67 : V_68 ;
}
V_58 -> V_69 = V_62 ;
F_32 ( V_60 ) ;
F_32 ( V_61 ) ;
return 0 ;
}
static int F_33 ( struct V_47 * V_54 ,
struct V_6 * V_7 ,
int V_56 ,
bool V_70 )
{
struct V_59 * V_26 = F_29 ( V_7 ) ;
struct V_57 * V_58 = F_28 ( V_7 , V_56 ) ;
struct V_9 * V_10 = F_34 ( V_7 , V_56 ) ;
struct V_47 * V_31 = NULL ;
struct V_47 * V_71 = NULL ;
struct V_47 * V_30 = NULL ;
char * V_50 ;
char V_72 [ 128 ] ;
char * V_55 = L_10 ;
int V_11 , V_73 ;
T_1 V_53 ;
if ( V_70 )
V_55 = L_11 ;
snprintf ( V_72 , sizeof( V_72 ) , L_12 , V_55 ) ;
V_31 = F_35 ( V_54 , V_72 ) ;
snprintf ( V_72 , sizeof( V_72 ) , L_13 , V_55 ) ;
V_71 = F_35 ( V_54 , V_72 ) ;
snprintf ( V_72 , sizeof( V_72 ) , L_14 , V_55 ) ;
V_30 = F_35 ( V_54 , V_72 ) ;
if ( ! V_31 || ! V_30 ) {
V_11 = - V_74 ;
F_10 ( V_26 , L_15 , V_75 , V_72 ) ;
goto V_76;
}
V_11 = F_27 ( V_54 , V_7 ,
V_30 , V_55 , V_56 ) ;
if ( V_11 < 0 )
goto V_76;
if ( ! F_26 ( V_54 , L_16 , & V_53 ) )
V_10 -> V_19 = V_53 ;
V_11 = F_17 ( V_31 , & V_10 -> V_12 ,
& V_58 -> V_77 ,
& V_58 -> V_78 ,
& V_73 ) ;
if ( V_11 < 0 )
goto V_76;
V_11 = F_17 ( V_30 , & V_10 -> V_14 ,
& V_58 -> V_79 ,
& V_58 -> V_80 , NULL ) ;
if ( V_11 < 0 )
goto V_76;
if ( ! V_58 -> V_78 || ! V_58 -> V_80 ) {
V_11 = - V_74 ;
goto V_76;
}
if ( V_71 ) {
struct V_52 args ;
V_11 = F_18 ( V_71 , L_5 ,
L_6 , 0 , & args ) ;
V_58 -> V_81 = args . V_48 ;
} else {
V_58 -> V_81 = V_58 -> V_77 ;
}
V_50 = F_36 ( V_26 ,
strlen ( V_58 -> V_78 ) +
strlen ( V_58 -> V_80 ) + 2 ,
V_82 ) ;
if ( ! V_50 ) {
V_11 = - V_83 ;
goto V_76;
}
sprintf ( V_50 , L_17 , V_58 -> V_78 ,
V_58 -> V_80 ) ;
V_58 -> V_50 = V_58 -> V_84 = V_50 ;
V_58 -> V_85 = & V_86 ;
V_58 -> V_87 = F_12 ;
F_31 ( V_26 , L_18 , V_58 -> V_84 ) ;
F_31 ( V_26 , L_19 , V_58 -> V_69 ) ;
F_31 ( V_26 , L_20 ,
V_58 -> V_78 ,
V_10 -> V_12 . V_24 ) ;
F_31 ( V_26 , L_21 ,
V_58 -> V_80 ,
V_10 -> V_14 . V_24 ) ;
if ( ! V_73 )
V_58 -> V_78 = NULL ;
V_76:
F_32 ( V_31 ) ;
F_32 ( V_30 ) ;
return V_11 ;
}
static int F_37 ( struct V_47 * V_54 ,
struct V_6 * V_7 )
{
struct V_59 * V_26 = F_29 ( V_7 ) ;
enum V_88 V_89 ;
T_1 V_53 ;
int V_11 ;
if ( ! V_54 )
return - V_74 ;
F_38 ( & V_7 -> V_90 , L_22 ) ;
if ( F_21 ( V_54 , L_23 ) ) {
V_11 = F_39 ( & V_7 -> V_90 ,
L_23 ) ;
if ( V_11 )
return V_11 ;
}
if ( F_21 ( V_54 , L_24 ) ) {
V_11 = F_40 ( & V_7 -> V_90 ,
L_24 ) ;
if ( V_11 )
return V_11 ;
}
V_11 = F_26 ( V_54 , L_25 , & V_53 ) ;
if ( V_11 == 0 )
V_7 -> V_19 = V_53 ;
F_31 ( V_26 , L_26 , V_7 -> V_90 . V_50 ?
V_7 -> V_90 . V_50 : L_10 ) ;
if ( F_35 ( V_54 , L_27 ) ) {
struct V_47 * V_48 = NULL ;
int V_91 = 0 ;
F_41 (node, np) {
F_31 ( V_26 , L_28 , V_91 ) ;
V_11 = F_33 ( V_48 , V_7 ,
V_91 , false ) ;
if ( V_11 < 0 ) {
F_32 ( V_48 ) ;
return V_11 ;
}
V_91 ++ ;
}
} else {
V_11 = F_33 ( V_54 , V_7 , 0 , true ) ;
if ( V_11 < 0 )
return V_11 ;
}
V_7 -> V_33 = F_42 ( V_54 ,
L_29 , 0 , & V_89 ) ;
V_7 -> V_40 = ! ! ( V_89 & V_92 ) ;
if ( V_7 -> V_33 == - V_93 )
return - V_93 ;
V_7 -> V_41 = F_42 ( V_54 ,
L_30 , 0 , & V_89 ) ;
V_7 -> V_46 = ! ! ( V_89 & V_92 ) ;
if ( V_7 -> V_41 == - V_93 )
return - V_93 ;
if ( ! V_7 -> V_90 . V_50 )
V_7 -> V_90 . V_50 = V_7 -> V_90 . V_58 -> V_50 ;
return 0 ;
}
static int F_43 ( struct V_94 * V_8 )
{
struct V_57 * V_58 ;
int V_95 ;
for ( V_95 = 0 , V_58 = V_8 -> V_58 ;
V_95 < V_8 -> V_95 ;
V_95 ++ , V_58 ++ ) {
F_32 ( V_58 -> V_77 ) ;
F_32 ( V_58 -> V_79 ) ;
}
return 0 ;
}
static int F_44 ( struct V_96 * V_97 )
{
struct V_6 * V_7 ;
struct V_57 * V_58 ;
struct V_47 * V_48 = V_97 -> V_26 . V_98 ;
struct V_59 * V_26 = & V_97 -> V_26 ;
int V_95 , V_11 ;
if ( V_48 && F_35 ( V_48 , L_27 ) )
V_95 = F_45 ( V_48 ) ;
else
V_95 = 1 ;
V_7 = F_36 ( V_26 ,
sizeof( * V_7 ) + sizeof( * V_58 ) * V_95 ,
V_82 ) ;
if ( ! V_7 )
return - V_83 ;
V_7 -> V_90 . V_99 = V_100 ;
V_7 -> V_90 . V_26 = V_26 ;
V_58 = V_7 -> V_58 ;
V_7 -> V_90 . V_58 = V_58 ;
V_7 -> V_90 . V_95 = V_95 ;
V_7 -> V_33 = - V_101 ;
V_7 -> V_41 = - V_101 ;
V_7 -> V_10 = F_36 ( V_26 ,
sizeof( * V_7 -> V_10 ) * V_95 ,
V_82 ) ;
if ( ! V_7 -> V_10 )
return - V_83 ;
if ( V_48 && F_46 ( V_48 ) ) {
V_11 = F_37 ( V_48 , V_7 ) ;
if ( V_11 < 0 ) {
if ( V_11 != - V_93 )
F_10 ( V_26 , L_31 , V_11 ) ;
goto V_27;
}
} else {
struct V_102 * V_103 ;
V_103 = V_26 -> V_104 ;
if ( ! V_103 ) {
F_10 ( V_26 , L_32 ) ;
return - V_74 ;
}
if ( ! V_103 -> V_50 ||
! V_103 -> V_14 . V_50 ||
! V_103 -> V_30 ||
! V_103 -> V_105 ||
! V_103 -> V_12 . V_50 ) {
F_10 ( V_26 , L_33 ) ;
return - V_74 ;
}
V_7 -> V_90 . V_50 = ( V_103 -> V_8 ) ? V_103 -> V_8 : V_103 -> V_50 ;
V_58 -> V_50 = V_103 -> V_50 ;
V_58 -> V_84 = V_103 -> V_50 ;
V_58 -> V_106 = V_103 -> V_105 ;
V_58 -> V_107 = V_103 -> V_30 ;
V_58 -> V_78 = V_103 -> V_12 . V_50 ;
V_58 -> V_80 = V_103 -> V_14 . V_50 ;
V_58 -> V_69 = V_103 -> V_62 ;
V_58 -> V_87 = F_12 ;
memcpy ( & V_7 -> V_10 -> V_12 , & V_103 -> V_12 ,
sizeof( V_7 -> V_10 -> V_12 ) ) ;
memcpy ( & V_7 -> V_10 -> V_14 , & V_103 -> V_14 ,
sizeof( V_7 -> V_10 -> V_14 ) ) ;
}
F_47 ( & V_7 -> V_90 , V_7 ) ;
V_11 = F_48 ( & V_97 -> V_26 , & V_7 -> V_90 ) ;
if ( V_11 >= 0 )
return V_11 ;
V_27:
F_43 ( & V_7 -> V_90 ) ;
return V_11 ;
}
static int F_49 ( struct V_96 * V_97 )
{
struct V_94 * V_8 = F_50 ( V_97 ) ;
struct V_6 * V_7 = F_2 ( V_8 ) ;
if ( F_13 ( V_7 -> V_33 ) )
F_51 ( & V_35 , 1 ,
& V_37 ) ;
if ( F_13 ( V_7 -> V_41 ) )
F_51 ( & V_43 , 1 ,
& V_45 ) ;
return F_43 ( V_8 ) ;
}
