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
static int F_6 ( struct V_15 * V_16 ,
struct V_17 * V_18 )
{
int V_11 ;
if ( V_18 -> V_19 ) {
V_11 = F_7 ( V_16 , V_18 -> V_19 ) ;
if ( V_11 && V_11 != - V_20 ) {
F_8 ( V_16 -> V_21 , L_1 ) ;
goto V_22;
}
}
if ( V_18 -> V_23 ) {
V_11 = F_9 ( V_16 , 0 , V_18 -> V_23 , 0 ) ;
if ( V_11 && V_11 != - V_20 ) {
F_8 ( V_16 -> V_21 , L_2 ) ;
goto V_22;
}
}
V_11 = 0 ;
V_22:
return V_11 ;
}
static int F_10 ( struct V_3 * V_4 )
{
struct V_6 * V_7 = F_2 ( V_4 -> V_8 ) ;
struct V_15 * V_24 = V_4 -> V_14 ;
struct V_15 * V_25 = V_4 -> V_12 ;
struct V_9 * V_10 ;
int V_26 , V_11 ;
V_26 = V_4 - V_4 -> V_8 -> V_4 ;
V_10 = & V_7 -> V_10 [ V_26 ] ;
V_11 = F_6 ( V_24 , & V_10 -> V_14 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_6 ( V_25 , & V_10 -> V_12 ) ;
if ( V_11 < 0 )
return V_11 ;
return 0 ;
}
static int F_11 ( struct V_3 * V_4 ,
struct V_27 * V_28 )
{
struct V_6 * V_7 = F_2 ( V_4 -> V_8 ) ;
struct V_29 * V_30 = F_12 ( V_28 ,
V_31 ) ;
if ( ! V_7 -> V_32 )
return 0 ;
V_30 -> V_33 = V_30 -> V_34 = V_7 -> V_32 ;
return 0 ;
}
static int
F_13 ( struct V_6 * V_7 ,
struct V_35 * V_36 ,
struct V_17 * V_16 ,
struct V_37 * V_38 ,
int * V_39 )
{
struct V_40 * V_21 = F_14 ( V_7 ) ;
const struct V_41 * V_42 = F_15 ( V_21 ) ;
struct V_43 args ;
struct V_35 * * V_44 ;
struct V_13 * V_13 ;
const char * * V_45 ;
const char * * V_46 ;
T_1 V_47 ;
int V_11 ;
if ( V_39 ) {
V_44 = & V_38 -> V_48 ;
V_45 = & V_38 -> V_49 ;
V_46 = & V_38 -> V_50 ;
} else {
V_44 = & V_38 -> V_51 ;
V_45 = & V_38 -> V_52 ;
V_46 = & V_38 -> V_53 ;
}
if ( ! V_36 ) {
* V_44 = NULL ;
* V_45 = L_3 ;
* V_46 = L_4 ;
return 0 ;
}
V_11 = F_16 ( V_36 , L_5 ,
L_6 , 0 , & args ) ;
if ( V_11 )
return V_11 ;
* V_44 = args . V_36 ;
V_11 = F_17 ( V_36 , V_45 ) ;
if ( V_11 < 0 )
return V_11 ;
V_38 -> V_54 = 1 ;
V_38 -> V_55 = 1 ;
if ( V_39 ) {
* V_39 = args . V_39 ;
V_38 -> V_56 = 1 ;
} else {
V_38 -> V_57 = 1 ;
V_7 -> V_58 . V_59 = ( * V_44 ) ;
V_7 -> V_58 . V_60 = V_42 -> V_61 ;
}
if ( F_18 ( V_36 , L_7 ) ) {
V_13 = F_19 ( V_36 , 0 ) ;
if ( F_20 ( V_13 ) ) {
V_11 = F_21 ( V_13 ) ;
return V_11 ;
}
V_16 -> V_23 = F_22 ( V_13 ) ;
V_16 -> V_13 = V_13 ;
} else if ( ! F_23 ( V_36 , L_8 , & V_47 ) ) {
V_16 -> V_23 = V_47 ;
} else {
V_13 = F_19 ( args . V_36 , 0 ) ;
if ( ! F_20 ( V_13 ) )
V_16 -> V_23 = F_22 ( V_13 ) ;
}
return 0 ;
}
static int F_24 ( struct V_35 * V_62 ,
struct V_6 * V_7 ,
struct V_35 * V_24 ,
int V_63 )
{
struct V_35 * V_64 = NULL ;
struct V_35 * V_65 = NULL ;
struct V_9 * V_10 = F_25 ( V_7 , V_63 ) ;
struct V_17 * V_12 = & V_10 -> V_12 ;
struct V_17 * V_14 = & V_10 -> V_14 ;
unsigned int V_66 ;
V_66 = F_26 ( V_62 , NULL ,
& V_64 , & V_65 ) ;
V_66 &= ~ V_67 ;
if ( ! V_64 && ! V_65 )
return - V_68 ;
if ( V_24 == V_64 )
V_66 |= ( V_24 == V_65 ) ?
V_69 : V_70 ;
else
V_66 |= ( V_24 == V_65 ) ?
V_71 : V_72 ;
V_12 -> V_19 = V_66 ;
V_14 -> V_19 = V_66 ;
F_27 ( V_64 ) ;
F_27 ( V_65 ) ;
return 0 ;
}
static int F_28 ( struct V_35 * V_62 ,
struct V_6 * V_7 ,
int V_63 )
{
struct V_40 * V_21 = F_14 ( V_7 ) ;
struct V_37 * V_38 = F_29 ( V_7 , V_63 ) ;
struct V_9 * V_10 = F_25 ( V_7 , V_63 ) ;
struct V_35 * V_25 = NULL ;
struct V_35 * V_24 = NULL ;
char * V_46 ;
char V_73 [ 128 ] ;
int V_11 , V_74 ;
V_25 = F_30 ( V_62 , L_9 ) ;
V_24 = F_30 ( V_62 , L_10 ) ;
if ( ! V_25 || ! V_24 ) {
V_11 = - V_68 ;
F_8 ( V_21 , L_11 , V_75 , V_73 ) ;
goto V_76;
}
V_11 = F_24 ( V_62 , V_7 , V_24 , V_63 ) ;
if ( V_11 < 0 )
goto V_76;
V_11 = F_13 ( V_7 , ( V_63 == V_77 ) ? V_25 : NULL ,
& V_10 -> V_12 ,
V_38 ,
& V_74 ) ;
if ( V_11 < 0 )
goto V_76;
V_11 = F_13 ( V_7 , ( V_63 == V_78 ) ? V_24 : NULL ,
& V_10 -> V_14 ,
V_38 ,
NULL ) ;
if ( V_11 < 0 )
goto V_76;
if ( ! V_38 -> V_49 || ! V_38 -> V_52 ) {
V_11 = - V_68 ;
goto V_76;
}
V_38 -> V_79 = V_38 -> V_48 ;
V_46 = F_31 ( V_21 ,
strlen ( V_38 -> V_49 ) +
strlen ( V_38 -> V_52 ) + 2 ,
V_80 ) ;
if ( ! V_46 ) {
V_11 = - V_81 ;
goto V_76;
}
sprintf ( V_46 , L_12 , V_38 -> V_49 ,
V_38 -> V_52 ) ;
V_38 -> V_46 = V_38 -> V_82 = V_46 ;
V_38 -> V_83 = & V_84 ;
V_38 -> V_85 = F_10 ;
if ( V_63 == V_78 )
V_38 -> V_86 = F_11 ;
F_32 ( V_21 , L_13 , V_38 -> V_82 ) ;
F_32 ( V_21 , L_14 ,
V_38 -> V_49 ,
V_10 -> V_12 . V_19 ,
V_10 -> V_12 . V_23 ) ;
F_32 ( V_21 , L_15 ,
V_38 -> V_52 ,
V_10 -> V_14 . V_19 ,
V_10 -> V_14 . V_23 ) ;
if ( ! V_74 )
V_38 -> V_49 = NULL ;
V_76:
F_27 ( V_25 ) ;
F_27 ( V_24 ) ;
return V_11 ;
}
static int F_33 ( struct V_35 * V_62 ,
struct V_6 * V_7 )
{
struct V_40 * V_21 = F_14 ( V_7 ) ;
const struct V_41 * V_42 = F_15 ( V_21 ) ;
int V_11 ;
int V_87 ;
if ( ! V_62 )
return - V_68 ;
F_34 ( & V_7 -> V_88 , L_16 ) ;
V_7 -> V_88 . V_89 = V_42 -> V_90 ;
V_7 -> V_88 . V_91 = V_42 -> V_92 ;
F_23 ( V_62 , L_17 , & V_7 -> V_32 ) ;
F_32 ( V_21 , L_18 ,
V_7 -> V_88 . V_46 ? V_7 -> V_88 . V_46 : L_19 ,
V_7 -> V_32 ) ;
for ( V_87 = 0 ; V_87 < V_93 ; V_87 ++ ) {
V_11 = F_28 ( V_62 , V_7 , V_87 ) ;
if ( V_11 < 0 )
return V_11 ;
}
if ( ! V_7 -> V_88 . V_46 )
V_7 -> V_88 . V_46 = V_7 -> V_88 . V_38 -> V_46 ;
return 0 ;
}
static int F_35 ( struct V_94 * V_8 )
{
struct V_37 * V_38 ;
int V_95 ;
for ( V_95 = 0 , V_38 = V_8 -> V_38 ;
V_95 < V_8 -> V_95 ;
V_95 ++ , V_38 ++ ) {
F_27 ( V_38 -> V_48 ) ;
F_27 ( V_38 -> V_51 ) ;
}
return 0 ;
}
static int F_36 ( struct V_96 * V_97 )
{
struct V_6 * V_7 ;
struct V_37 * V_38 ;
struct V_35 * V_36 = V_97 -> V_21 . V_59 ;
struct V_40 * V_21 = & V_97 -> V_21 ;
int V_11 ;
V_7 = F_31 ( V_21 , sizeof( * V_7 ) , V_80 ) ;
if ( ! V_7 )
return - V_81 ;
V_7 -> V_88 . V_98 = V_99 ;
V_7 -> V_88 . V_21 = V_21 ;
V_38 = V_7 -> V_38 ;
V_7 -> V_88 . V_38 = V_38 ;
V_7 -> V_88 . V_95 = V_93 ;
V_7 -> V_88 . V_58 = & V_7 -> V_58 ;
V_7 -> V_88 . V_100 = 1 ;
V_11 = F_33 ( V_36 , V_7 ) ;
if ( V_11 < 0 ) {
if ( V_11 != - V_101 )
F_8 ( V_21 , L_20 , V_11 ) ;
goto V_22;
}
F_37 ( & V_7 -> V_88 , V_7 ) ;
V_11 = F_38 ( & V_97 -> V_21 , & V_7 -> V_88 ) ;
if ( V_11 >= 0 )
return V_11 ;
V_22:
F_35 ( & V_7 -> V_88 ) ;
return V_11 ;
}
static int F_39 ( struct V_96 * V_97 )
{
struct V_94 * V_8 = F_40 ( V_97 ) ;
return F_35 ( V_8 ) ;
}
