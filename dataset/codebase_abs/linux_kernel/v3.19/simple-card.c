static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_10 * V_11 = F_2 ( V_6 -> V_12 ) ;
unsigned int V_13 ;
int V_14 = 0 ;
if ( V_11 -> V_15 ) {
V_13 = F_3 ( V_4 ) * V_11 -> V_15 ;
V_14 = F_4 ( V_9 , 0 , V_13 ,
V_16 ) ;
}
return V_14 ;
}
static int F_5 ( struct V_8 * V_17 ,
struct V_18 * V_19 )
{
int V_14 ;
if ( V_19 -> V_20 ) {
V_14 = F_6 ( V_17 , V_19 -> V_20 ) ;
if ( V_14 && V_14 != - V_21 ) {
F_7 ( V_17 -> V_22 , L_1 ) ;
goto V_23;
}
}
if ( V_19 -> V_24 ) {
V_14 = F_4 ( V_17 , 0 , V_19 -> V_24 , 0 ) ;
if ( V_14 && V_14 != - V_21 ) {
F_7 ( V_17 -> V_22 , L_2 ) ;
goto V_23;
}
}
if ( V_19 -> V_25 ) {
V_14 = F_8 ( V_17 , 0 , 0 ,
V_19 -> V_25 ,
V_19 -> V_26 ) ;
if ( V_14 && V_14 != - V_21 ) {
F_7 ( V_17 -> V_22 , L_3 ) ;
goto V_23;
}
}
V_14 = 0 ;
V_23:
return V_14 ;
}
static int F_9 ( struct V_5 * V_6 )
{
struct V_10 * V_11 = F_2 ( V_6 -> V_12 ) ;
struct V_8 * V_27 = V_6 -> V_9 ;
struct V_8 * V_28 = V_6 -> V_29 ;
struct V_30 * V_31 ;
int V_32 , V_14 ;
V_32 = V_6 - V_6 -> V_12 -> V_6 ;
V_31 = & V_11 -> V_31 [ V_32 ] ;
V_14 = F_5 ( V_27 , & V_31 -> V_9 ) ;
if ( V_14 < 0 )
return V_14 ;
V_14 = F_5 ( V_28 , & V_31 -> V_29 ) ;
if ( V_14 < 0 )
return V_14 ;
if ( F_10 ( V_11 -> V_33 ) ) {
F_11 ( V_27 -> V_27 , L_4 , V_34 ,
& V_35 ) ;
F_12 ( & V_35 ,
F_13 ( V_36 ) ,
V_36 ) ;
V_37 . V_38 = V_11 -> V_33 ;
V_37 . V_39 = V_11 -> V_40 ;
F_14 ( & V_35 , 1 ,
& V_37 ) ;
}
if ( F_10 ( V_11 -> V_41 ) ) {
F_11 ( V_27 -> V_27 , L_5 , V_42 ,
& V_43 ) ;
F_12 ( & V_43 ,
F_13 ( V_44 ) ,
V_44 ) ;
V_45 . V_38 = V_11 -> V_41 ;
V_45 . V_39 = V_11 -> V_46 ;
F_14 ( & V_43 , 1 ,
& V_45 ) ;
}
return 0 ;
}
static int
F_15 ( struct V_47 * V_48 ,
struct V_18 * V_17 ,
struct V_47 * * V_49 ,
const char * * V_50 ,
int * V_51 )
{
struct V_52 args ;
struct V_53 * V_53 ;
T_1 V_54 ;
int V_14 ;
V_14 = F_16 ( V_48 , L_6 ,
L_7 , 0 , & args ) ;
if ( V_14 )
return V_14 ;
* V_49 = args . V_48 ;
if ( V_51 )
* V_51 = args . V_51 ;
V_14 = F_17 ( V_48 , V_50 ) ;
if ( V_14 < 0 )
return V_14 ;
V_14 = F_18 ( V_48 , & V_17 -> V_25 , & V_17 -> V_26 ) ;
if ( V_14 )
return V_14 ;
if ( F_19 ( V_48 , L_8 ) ) {
V_53 = F_20 ( V_48 , 0 ) ;
if ( F_21 ( V_53 ) ) {
V_14 = F_22 ( V_53 ) ;
return V_14 ;
}
V_17 -> V_24 = F_23 ( V_53 ) ;
} else if ( ! F_24 ( V_48 , L_9 , & V_54 ) ) {
V_17 -> V_24 = V_54 ;
} else {
V_53 = F_20 ( args . V_48 , 0 ) ;
if ( ! F_21 ( V_53 ) )
V_17 -> V_24 = F_23 ( V_53 ) ;
}
return 0 ;
}
static int F_25 ( struct V_47 * V_55 ,
struct V_10 * V_11 ,
struct V_47 * V_27 ,
char * V_56 , int V_57 )
{
struct V_58 * V_22 = F_26 ( V_11 ) ;
struct V_47 * V_59 = NULL ;
struct V_47 * V_60 = NULL ;
struct V_30 * V_31 = F_27 ( V_11 , V_57 ) ;
struct V_18 * V_29 = & V_31 -> V_29 ;
struct V_18 * V_9 = & V_31 -> V_9 ;
unsigned int V_61 ;
V_61 = F_28 ( V_55 , V_56 ,
& V_59 , & V_60 ) ;
V_61 &= ~ V_62 ;
if ( strlen ( V_56 ) && ! V_59 && ! V_60 ) {
F_29 ( V_22 , L_10 ) ;
V_29 -> V_20 = V_9 -> V_20 =
F_28 ( V_27 , NULL , NULL , NULL ) |
( V_61 & ~ V_63 ) ;
} else {
if ( V_27 == V_59 )
V_61 |= ( V_27 == V_60 ) ?
V_64 : V_65 ;
else
V_61 |= ( V_27 == V_60 ) ?
V_66 : V_67 ;
V_29 -> V_20 = V_61 ;
V_9 -> V_20 = V_61 ;
}
F_30 ( V_59 ) ;
F_30 ( V_60 ) ;
return 0 ;
}
static int F_31 ( struct V_47 * V_55 ,
struct V_10 * V_11 ,
int V_57 ,
bool V_68 )
{
struct V_58 * V_22 = F_26 ( V_11 ) ;
struct V_69 * V_70 = F_32 ( V_11 , V_57 ) ;
struct V_30 * V_31 = F_27 ( V_11 , V_57 ) ;
struct V_47 * V_28 = NULL ;
struct V_47 * V_27 = NULL ;
char * V_50 ;
char V_71 [ 128 ] ;
char * V_56 = L_11 ;
int V_14 , V_72 ;
if ( V_68 )
V_56 = L_12 ;
snprintf ( V_71 , sizeof( V_71 ) , L_13 , V_56 ) ;
V_28 = F_33 ( V_55 , V_71 ) ;
snprintf ( V_71 , sizeof( V_71 ) , L_14 , V_56 ) ;
V_27 = F_33 ( V_55 , V_71 ) ;
if ( ! V_28 || ! V_27 ) {
V_14 = - V_73 ;
F_7 ( V_22 , L_15 , V_74 , V_71 ) ;
goto V_75;
}
V_14 = F_25 ( V_55 , V_11 ,
V_27 , V_56 , V_57 ) ;
if ( V_14 < 0 )
goto V_75;
V_14 = F_15 ( V_28 , & V_31 -> V_29 ,
& V_70 -> V_76 ,
& V_70 -> V_77 ,
& V_72 ) ;
if ( V_14 < 0 )
goto V_75;
V_14 = F_15 ( V_27 , & V_31 -> V_9 ,
& V_70 -> V_78 ,
& V_70 -> V_79 , NULL ) ;
if ( V_14 < 0 )
goto V_75;
if ( ! V_70 -> V_77 || ! V_70 -> V_79 ) {
V_14 = - V_73 ;
goto V_75;
}
V_70 -> V_80 = V_70 -> V_76 ;
V_50 = F_34 ( V_22 ,
strlen ( V_70 -> V_77 ) +
strlen ( V_70 -> V_79 ) + 2 ,
V_81 ) ;
sprintf ( V_50 , L_16 , V_70 -> V_77 ,
V_70 -> V_79 ) ;
V_70 -> V_50 = V_70 -> V_82 = V_50 ;
V_70 -> V_83 = & V_84 ;
V_70 -> V_85 = F_9 ;
F_29 ( V_22 , L_17 , V_70 -> V_82 ) ;
F_29 ( V_22 , L_18 ,
V_70 -> V_77 ,
V_31 -> V_29 . V_20 ,
V_31 -> V_29 . V_24 ) ;
F_29 ( V_22 , L_19 ,
V_70 -> V_79 ,
V_31 -> V_9 . V_20 ,
V_31 -> V_9 . V_24 ) ;
if ( ! V_72 )
V_70 -> V_77 = NULL ;
V_75:
F_30 ( V_28 ) ;
F_30 ( V_27 ) ;
return V_14 ;
}
static int F_35 ( struct V_47 * V_55 ,
struct V_10 * V_11 )
{
struct V_58 * V_22 = F_26 ( V_11 ) ;
enum V_86 V_87 ;
T_1 V_54 ;
int V_14 ;
if ( ! V_55 )
return - V_73 ;
F_36 ( & V_11 -> V_88 , L_20 ) ;
if ( F_19 ( V_55 , L_21 ) ) {
V_14 = F_37 ( & V_11 -> V_88 ,
L_21 ) ;
if ( V_14 )
return V_14 ;
}
if ( F_19 ( V_55 , L_22 ) ) {
V_14 = F_38 ( & V_11 -> V_88 ,
L_22 ) ;
if ( V_14 )
return V_14 ;
}
V_14 = F_24 ( V_55 , L_23 , & V_54 ) ;
if ( V_14 == 0 )
V_11 -> V_15 = V_54 ;
F_29 ( V_22 , L_24 , V_11 -> V_88 . V_50 ?
V_11 -> V_88 . V_50 : L_11 ) ;
if ( F_33 ( V_55 , L_25 ) ) {
struct V_47 * V_48 = NULL ;
int V_89 = 0 ;
F_39 (node, np) {
F_29 ( V_22 , L_26 , V_89 ) ;
V_14 = F_31 ( V_48 , V_11 ,
V_89 , false ) ;
if ( V_14 < 0 ) {
F_30 ( V_48 ) ;
return V_14 ;
}
V_89 ++ ;
}
} else {
V_14 = F_31 ( V_55 , V_11 , 0 , true ) ;
if ( V_14 < 0 )
return V_14 ;
}
V_11 -> V_33 = F_40 ( V_55 ,
L_27 , 0 , & V_87 ) ;
V_11 -> V_40 = ! ! ( V_87 & V_90 ) ;
if ( V_11 -> V_33 == - V_91 )
return - V_91 ;
V_11 -> V_41 = F_40 ( V_55 ,
L_28 , 0 , & V_87 ) ;
V_11 -> V_46 = ! ! ( V_87 & V_90 ) ;
if ( V_11 -> V_41 == - V_91 )
return - V_91 ;
if ( ! V_11 -> V_88 . V_50 )
V_11 -> V_88 . V_50 = V_11 -> V_88 . V_70 -> V_50 ;
return 0 ;
}
static int F_41 ( struct V_92 * V_12 )
{
struct V_69 * V_70 ;
int V_93 ;
for ( V_93 = 0 , V_70 = V_12 -> V_70 ;
V_93 < V_12 -> V_93 ;
V_93 ++ , V_70 ++ ) {
F_30 ( V_70 -> V_76 ) ;
F_30 ( V_70 -> V_78 ) ;
}
return 0 ;
}
static int F_42 ( struct V_94 * V_95 )
{
struct V_10 * V_11 ;
struct V_69 * V_70 ;
struct V_47 * V_48 = V_95 -> V_22 . V_96 ;
struct V_58 * V_22 = & V_95 -> V_22 ;
int V_93 , V_14 ;
if ( V_48 && F_33 ( V_48 , L_25 ) )
V_93 = F_43 ( V_48 ) ;
else
V_93 = 1 ;
V_11 = F_34 ( V_22 ,
sizeof( * V_11 ) + sizeof( * V_70 ) * V_93 ,
V_81 ) ;
if ( ! V_11 )
return - V_97 ;
V_11 -> V_88 . V_98 = V_99 ;
V_11 -> V_88 . V_22 = V_22 ;
V_70 = V_11 -> V_70 ;
V_11 -> V_88 . V_70 = V_70 ;
V_11 -> V_88 . V_93 = V_93 ;
V_11 -> V_33 = - V_100 ;
V_11 -> V_41 = - V_100 ;
V_11 -> V_31 = F_34 ( V_22 ,
sizeof( * V_11 -> V_31 ) * V_93 ,
V_81 ) ;
if ( ! V_11 -> V_31 )
return - V_97 ;
if ( V_48 && F_44 ( V_48 ) ) {
V_14 = F_35 ( V_48 , V_11 ) ;
if ( V_14 < 0 ) {
if ( V_14 != - V_91 )
F_7 ( V_22 , L_29 , V_14 ) ;
goto V_23;
}
} else {
struct V_101 * V_102 ;
V_102 = V_22 -> V_103 ;
if ( ! V_102 ) {
F_7 ( V_22 , L_30 ) ;
return - V_73 ;
}
if ( ! V_102 -> V_50 ||
! V_102 -> V_9 . V_50 ||
! V_102 -> V_27 ||
! V_102 -> V_104 ||
! V_102 -> V_29 . V_50 ) {
F_7 ( V_22 , L_31 ) ;
return - V_73 ;
}
V_11 -> V_88 . V_50 = ( V_102 -> V_12 ) ? V_102 -> V_12 : V_102 -> V_50 ;
V_70 -> V_50 = V_102 -> V_50 ;
V_70 -> V_82 = V_102 -> V_50 ;
V_70 -> V_105 = V_102 -> V_104 ;
V_70 -> V_106 = V_102 -> V_27 ;
V_70 -> V_77 = V_102 -> V_29 . V_50 ;
V_70 -> V_79 = V_102 -> V_9 . V_50 ;
V_70 -> V_85 = F_9 ;
memcpy ( & V_11 -> V_31 -> V_29 , & V_102 -> V_29 ,
sizeof( V_11 -> V_31 -> V_29 ) ) ;
memcpy ( & V_11 -> V_31 -> V_9 , & V_102 -> V_9 ,
sizeof( V_11 -> V_31 -> V_9 ) ) ;
V_11 -> V_31 -> V_29 . V_20 |= V_102 -> V_61 ;
V_11 -> V_31 -> V_9 . V_20 |= V_102 -> V_61 ;
}
F_45 ( & V_11 -> V_88 , V_11 ) ;
V_14 = F_46 ( & V_95 -> V_22 , & V_11 -> V_88 ) ;
if ( V_14 >= 0 )
return V_14 ;
V_23:
F_41 ( & V_11 -> V_88 ) ;
return V_14 ;
}
static int F_47 ( struct V_94 * V_95 )
{
struct V_92 * V_12 = F_48 ( V_95 ) ;
struct V_10 * V_11 = F_2 ( V_12 ) ;
if ( F_10 ( V_11 -> V_33 ) )
F_49 ( & V_35 , 1 ,
& V_37 ) ;
if ( F_10 ( V_11 -> V_41 ) )
F_49 ( & V_43 , 1 ,
& V_45 ) ;
return F_41 ( V_12 ) ;
}
