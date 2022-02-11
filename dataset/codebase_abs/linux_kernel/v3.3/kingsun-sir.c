static void F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = V_1 -> V_4 ;
struct V_5 * V_6 = V_3 -> V_6 ;
if ( ! F_2 ( V_3 -> V_6 ) ) {
F_3 ( L_1 ) ;
return;
}
if ( V_1 -> V_7 != 0 ) {
F_3 ( L_2 ,
V_1 -> V_7 ) ;
}
F_4 ( V_6 ) ;
}
static T_1 F_5 ( struct V_8 * V_9 ,
struct V_5 * V_6 )
{
struct V_2 * V_3 ;
int V_10 ;
int V_11 = 0 ;
F_6 ( V_6 ) ;
F_7 ( V_9 ) ;
V_3 = F_8 ( V_6 ) ;
F_9 ( & V_3 -> V_12 ) ;
V_10 = F_10 ( V_9 ,
V_3 -> V_13 ,
V_14 ) ;
F_11 ( V_3 -> V_15 , V_3 -> V_16 ,
F_12 ( V_3 -> V_16 , V_3 -> V_17 ) ,
V_3 -> V_13 , V_10 , F_1 ,
V_3 , 1 ) ;
if ( ( V_11 = F_13 ( V_3 -> V_15 , V_18 ) ) ) {
F_3 ( L_3 , V_11 ) ;
switch ( V_11 ) {
case - V_19 :
case - V_20 :
break;
default:
V_6 -> V_21 . V_22 ++ ;
F_14 ( V_6 ) ;
}
} else {
V_6 -> V_21 . V_23 ++ ;
V_6 -> V_21 . V_24 += V_9 -> V_25 ;
}
F_15 ( V_9 ) ;
F_16 ( & V_3 -> V_12 ) ;
return V_26 ;
}
static void F_17 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = V_1 -> V_4 ;
int V_11 ;
if ( ! F_2 ( V_3 -> V_6 ) ) {
V_3 -> V_27 = 0 ;
return;
}
if ( V_1 -> V_7 != 0 ) {
F_3 ( L_4 ,
V_1 -> V_7 ) ;
V_3 -> V_27 = 0 ;
return;
}
if ( V_1 -> V_28 == V_3 -> V_29 ) {
T_2 * V_30 = V_1 -> V_31 ;
int V_32 ;
if ( V_30 [ 0 ] >= 1 && V_30 [ 0 ] < V_3 -> V_29 ) {
for ( V_32 = 1 ; V_32 <= V_30 [ 0 ] ; V_32 ++ ) {
F_18 ( V_3 -> V_6 ,
& V_3 -> V_6 -> V_21 ,
& V_3 -> V_33 , V_30 [ V_32 ] ) ;
}
F_19 ( & V_3 -> V_34 ) ;
V_3 -> V_27 =
( V_3 -> V_33 . V_35 != V_36 )
? 1 : 0 ;
}
} else if ( V_1 -> V_28 > 0 ) {
F_3 ( L_5 ,
V_37 , V_3 -> V_29 , V_1 -> V_28 ) ;
}
V_11 = F_13 ( V_1 , V_18 ) ;
}
static int F_20 ( struct V_5 * V_6 )
{
struct V_2 * V_3 = F_8 ( V_6 ) ;
int F_3 = - V_38 ;
char V_39 [ 16 ] ;
V_3 -> V_27 = 0 ;
V_3 -> V_33 . V_40 = FALSE ;
V_3 -> V_33 . V_35 = V_36 ;
V_3 -> V_33 . V_41 = V_42 ;
V_3 -> V_33 . V_9 = F_21 ( V_42 ) ;
if ( ! V_3 -> V_33 . V_9 )
goto V_43;
F_22 ( V_3 -> V_33 . V_9 , 1 ) ;
V_3 -> V_33 . V_44 = V_3 -> V_33 . V_9 -> V_45 ;
F_19 ( & V_3 -> V_34 ) ;
V_3 -> V_46 = F_23 ( 0 , V_47 ) ;
if ( ! V_3 -> V_46 )
goto V_43;
V_3 -> V_15 = F_23 ( 0 , V_47 ) ;
if ( ! V_3 -> V_15 )
goto V_43;
sprintf ( V_39 , L_6 , V_3 -> V_16 -> V_48 ) ;
V_3 -> V_49 = F_24 ( V_6 , & V_3 -> V_50 , V_39 ) ;
if ( ! V_3 -> V_49 ) {
F_3 ( L_7 ) ;
goto V_43;
}
F_11 ( V_3 -> V_46 , V_3 -> V_16 ,
F_25 ( V_3 -> V_16 , V_3 -> V_51 ) ,
V_3 -> V_52 , V_3 -> V_29 ,
F_17 , V_3 , 1 ) ;
V_3 -> V_46 -> V_7 = 0 ;
F_3 = F_13 ( V_3 -> V_46 , V_47 ) ;
if ( F_3 ) {
F_3 ( L_8 , F_3 ) ;
goto V_53;
}
F_14 ( V_6 ) ;
return 0 ;
V_53:
F_26 ( V_3 -> V_49 ) ;
V_43:
if ( V_3 -> V_15 ) {
F_27 ( V_3 -> V_15 ) ;
V_3 -> V_15 = NULL ;
}
if ( V_3 -> V_46 ) {
F_27 ( V_3 -> V_46 ) ;
V_3 -> V_46 = NULL ;
}
if ( V_3 -> V_33 . V_9 ) {
F_28 ( V_3 -> V_33 . V_9 ) ;
V_3 -> V_33 . V_9 = NULL ;
V_3 -> V_33 . V_44 = NULL ;
}
return F_3 ;
}
static int F_29 ( struct V_5 * V_6 )
{
struct V_2 * V_3 = F_8 ( V_6 ) ;
F_6 ( V_6 ) ;
F_30 ( V_3 -> V_15 ) ;
F_30 ( V_3 -> V_46 ) ;
F_27 ( V_3 -> V_15 ) ;
F_27 ( V_3 -> V_46 ) ;
V_3 -> V_15 = NULL ;
V_3 -> V_46 = NULL ;
F_28 ( V_3 -> V_33 . V_9 ) ;
V_3 -> V_33 . V_9 = NULL ;
V_3 -> V_33 . V_44 = NULL ;
V_3 -> V_33 . V_40 = FALSE ;
V_3 -> V_33 . V_35 = V_36 ;
V_3 -> V_27 = 0 ;
if ( V_3 -> V_49 )
F_26 ( V_3 -> V_49 ) ;
V_3 -> V_49 = NULL ;
return 0 ;
}
static int F_31 ( struct V_5 * V_6 , struct V_54 * V_55 ,
int V_56 )
{
struct V_57 * V_58 = (struct V_57 * ) V_55 ;
struct V_2 * V_3 = F_8 ( V_6 ) ;
int V_11 = 0 ;
switch ( V_56 ) {
case V_59 :
if ( ! F_32 ( V_60 ) )
return - V_61 ;
if ( F_33 ( V_3 -> V_6 ) )
V_11 = - V_62 ;
break;
case V_63 :
if ( ! F_32 ( V_60 ) )
return - V_61 ;
if ( F_2 ( V_3 -> V_6 ) )
F_34 ( V_3 -> V_6 , TRUE ) ;
break;
case V_64 :
V_58 -> V_65 = V_3 -> V_27 ;
break;
default:
V_11 = - V_62 ;
}
return V_11 ;
}
static int F_35 ( struct V_66 * V_67 ,
const struct V_68 * V_69 )
{
struct V_70 * V_71 ;
struct V_72 * V_73 ;
struct V_74 * V_75 = F_36 ( V_67 ) ;
struct V_2 * V_3 = NULL ;
struct V_5 * V_76 = NULL ;
int V_11 = - V_38 ;
int V_77 , V_78 , V_79 ;
T_2 V_51 ;
T_2 V_17 ;
V_71 = V_67 -> V_80 ;
if ( V_71 -> V_81 . V_82 != 2 ) {
F_3 ( L_9 ,
V_71 -> V_81 . V_82 ) ;
return - V_19 ;
}
V_73 = & V_71 -> V_73 [ V_83 ] . V_81 ;
if ( ! F_37 ( V_73 ) ) {
F_3 ( L_10 ) ;
return - V_19 ;
}
V_51 = V_73 -> V_84 ;
V_77 = F_25 ( V_75 , V_51 ) ;
V_78 = F_38 ( V_75 , V_77 , F_39 ( V_77 ) ) ;
if ( V_78 > 255 || V_78 <= 1 ) {
F_3 ( L_11 ,
__FILE__ , V_78 ) ;
return - V_19 ;
}
V_73 = & V_71 -> V_73 [ V_85 ] . V_81 ;
if ( ! F_40 ( V_73 ) ) {
F_3 ( L_12 ) ;
return - V_19 ;
}
V_17 = V_73 -> V_84 ;
V_77 = F_12 ( V_75 , V_17 ) ;
V_79 = F_38 ( V_75 , V_77 , F_39 ( V_77 ) ) ;
V_76 = F_41 ( sizeof( * V_3 ) ) ;
if( ! V_76 )
goto V_86;
F_42 ( V_76 , & V_67 -> V_75 ) ;
V_3 = F_8 ( V_76 ) ;
V_3 -> V_49 = NULL ;
V_3 -> V_15 = NULL ;
V_3 -> V_46 = NULL ;
V_3 -> V_51 = V_51 ;
V_3 -> V_17 = V_17 ;
V_3 -> V_52 = NULL ;
V_3 -> V_13 = NULL ;
V_3 -> V_29 = ( T_2 ) V_78 ;
V_3 -> V_87 = ( T_2 ) V_79 ;
V_3 -> V_6 = V_76 ;
V_3 -> V_16 = V_75 ;
V_3 -> V_33 . V_40 = FALSE ;
V_3 -> V_33 . V_35 = V_36 ;
V_3 -> V_33 . V_9 = NULL ;
V_3 -> V_27 = 0 ;
F_43 ( & V_3 -> V_12 ) ;
V_3 -> V_52 = F_44 ( V_3 -> V_29 , V_47 ) ;
if ( ! V_3 -> V_52 )
goto V_43;
V_3 -> V_13 = F_44 ( V_14 , V_47 ) ;
if ( ! V_3 -> V_13 )
goto V_43;
F_45 ( V_88 L_13
L_14 ,
V_75 -> V_48 , F_46 ( V_75 -> V_89 . V_90 ) ,
F_46 ( V_75 -> V_89 . V_91 ) ) ;
F_47 ( & V_3 -> V_50 ) ;
V_3 -> V_50 . V_92 . V_93 &= V_94 ;
V_3 -> V_50 . V_95 . V_93 &= V_96 ;
F_48 ( & V_3 -> V_50 ) ;
V_76 -> V_97 = & V_98 ;
V_11 = F_49 ( V_76 ) ;
if ( V_11 != 0 )
goto V_43;
F_50 ( & V_76 -> V_75 , L_15 ,
V_76 -> V_99 ) ;
F_51 ( V_67 , V_3 ) ;
return 0 ;
V_43:
if ( V_3 -> V_13 ) F_52 ( V_3 -> V_13 ) ;
if ( V_3 -> V_52 ) F_52 ( V_3 -> V_52 ) ;
F_53 ( V_76 ) ;
V_86:
return V_11 ;
}
static void F_54 ( struct V_66 * V_67 )
{
struct V_2 * V_3 = F_55 ( V_67 ) ;
if ( ! V_3 )
return;
F_56 ( V_3 -> V_6 ) ;
if ( V_3 -> V_15 != NULL ) {
F_30 ( V_3 -> V_15 ) ;
F_27 ( V_3 -> V_15 ) ;
V_3 -> V_15 = NULL ;
}
if ( V_3 -> V_46 != NULL ) {
F_30 ( V_3 -> V_46 ) ;
F_27 ( V_3 -> V_46 ) ;
V_3 -> V_46 = NULL ;
}
F_52 ( V_3 -> V_13 ) ;
F_52 ( V_3 -> V_52 ) ;
F_53 ( V_3 -> V_6 ) ;
F_51 ( V_67 , NULL ) ;
}
static int F_57 ( struct V_66 * V_67 , T_3 V_100 )
{
struct V_2 * V_3 = F_55 ( V_67 ) ;
F_58 ( V_3 -> V_6 ) ;
if ( V_3 -> V_15 != NULL ) F_30 ( V_3 -> V_15 ) ;
if ( V_3 -> V_46 != NULL ) F_30 ( V_3 -> V_46 ) ;
return 0 ;
}
static int F_59 ( struct V_66 * V_67 )
{
struct V_2 * V_3 = F_55 ( V_67 ) ;
if ( V_3 -> V_46 != NULL )
F_13 ( V_3 -> V_46 , V_47 ) ;
F_60 ( V_3 -> V_6 ) ;
return 0 ;
}
