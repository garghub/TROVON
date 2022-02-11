static void F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = V_1 -> V_4 ;
struct V_5 * V_6 = V_3 -> V_6 ;
if ( ! F_2 ( V_3 -> V_6 ) ) {
F_3 ( & V_3 -> V_7 -> V_8 ,
L_1 ) ;
return;
}
if ( V_1 -> V_9 != 0 ) {
F_3 ( & V_3 -> V_7 -> V_8 ,
L_2 ,
V_1 -> V_9 ) ;
}
F_4 ( V_6 ) ;
}
static T_1 F_5 ( struct V_10 * V_11 ,
struct V_5 * V_6 )
{
struct V_2 * V_3 ;
int V_12 ;
int V_13 = 0 ;
F_6 ( V_6 ) ;
F_7 ( V_11 ) ;
V_3 = F_8 ( V_6 ) ;
F_9 ( & V_3 -> V_14 ) ;
V_12 = F_10 ( V_11 ,
V_3 -> V_15 ,
V_16 ) ;
F_11 ( V_3 -> V_17 , V_3 -> V_7 ,
F_12 ( V_3 -> V_7 , V_3 -> V_18 ) ,
V_3 -> V_15 , V_12 , F_1 ,
V_3 , 1 ) ;
if ( ( V_13 = F_13 ( V_3 -> V_17 , V_19 ) ) ) {
F_3 ( & V_3 -> V_7 -> V_8 ,
L_3 , V_13 ) ;
switch ( V_13 ) {
case - V_20 :
case - V_21 :
break;
default:
V_6 -> V_22 . V_23 ++ ;
F_14 ( V_6 ) ;
}
} else {
V_6 -> V_22 . V_24 ++ ;
V_6 -> V_22 . V_25 += V_11 -> V_26 ;
}
F_15 ( V_11 ) ;
F_16 ( & V_3 -> V_14 ) ;
return V_27 ;
}
static void F_17 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = V_1 -> V_4 ;
int V_13 ;
if ( ! F_2 ( V_3 -> V_6 ) ) {
V_3 -> V_28 = 0 ;
return;
}
if ( V_1 -> V_9 != 0 ) {
F_3 ( & V_3 -> V_7 -> V_8 ,
L_4 ,
V_1 -> V_9 ) ;
V_3 -> V_28 = 0 ;
return;
}
if ( V_1 -> V_29 == V_3 -> V_30 ) {
T_2 * V_31 = V_1 -> V_32 ;
int V_33 ;
if ( V_31 [ 0 ] >= 1 && V_31 [ 0 ] < V_3 -> V_30 ) {
for ( V_33 = 1 ; V_33 <= V_31 [ 0 ] ; V_33 ++ ) {
F_18 ( V_3 -> V_6 ,
& V_3 -> V_6 -> V_22 ,
& V_3 -> V_34 , V_31 [ V_33 ] ) ;
}
V_3 -> V_28 =
( V_3 -> V_34 . V_35 != V_36 )
? 1 : 0 ;
}
} else if ( V_1 -> V_29 > 0 ) {
F_3 ( & V_3 -> V_7 -> V_8 ,
L_5 ,
V_37 , V_3 -> V_30 , V_1 -> V_29 ) ;
}
V_13 = F_13 ( V_1 , V_19 ) ;
}
static int F_19 ( struct V_5 * V_6 )
{
struct V_2 * V_3 = F_8 ( V_6 ) ;
int V_38 = - V_39 ;
char V_40 [ 16 ] ;
V_3 -> V_28 = 0 ;
V_3 -> V_34 . V_41 = FALSE ;
V_3 -> V_34 . V_35 = V_36 ;
V_3 -> V_34 . V_42 = V_43 ;
V_3 -> V_34 . V_11 = F_20 ( V_43 ) ;
if ( ! V_3 -> V_34 . V_11 )
goto V_44;
F_21 ( V_3 -> V_34 . V_11 , 1 ) ;
V_3 -> V_34 . V_45 = V_3 -> V_34 . V_11 -> V_46 ;
V_3 -> V_47 = F_22 ( 0 , V_48 ) ;
if ( ! V_3 -> V_47 )
goto V_44;
V_3 -> V_17 = F_22 ( 0 , V_48 ) ;
if ( ! V_3 -> V_17 )
goto V_44;
sprintf ( V_40 , L_6 , V_3 -> V_7 -> V_49 ) ;
V_3 -> V_50 = F_23 ( V_6 , & V_3 -> V_51 , V_40 ) ;
if ( ! V_3 -> V_50 ) {
F_3 ( & V_3 -> V_7 -> V_8 , L_7 ) ;
goto V_44;
}
F_11 ( V_3 -> V_47 , V_3 -> V_7 ,
F_24 ( V_3 -> V_7 , V_3 -> V_52 ) ,
V_3 -> V_53 , V_3 -> V_30 ,
F_17 , V_3 , 1 ) ;
V_3 -> V_47 -> V_9 = 0 ;
V_38 = F_13 ( V_3 -> V_47 , V_48 ) ;
if ( V_38 ) {
F_3 ( & V_3 -> V_7 -> V_8 ,
L_8 , V_38 ) ;
goto V_54;
}
F_14 ( V_6 ) ;
return 0 ;
V_54:
F_25 ( V_3 -> V_50 ) ;
V_44:
if ( V_3 -> V_17 ) {
F_26 ( V_3 -> V_17 ) ;
V_3 -> V_17 = NULL ;
}
if ( V_3 -> V_47 ) {
F_26 ( V_3 -> V_47 ) ;
V_3 -> V_47 = NULL ;
}
if ( V_3 -> V_34 . V_11 ) {
F_27 ( V_3 -> V_34 . V_11 ) ;
V_3 -> V_34 . V_11 = NULL ;
V_3 -> V_34 . V_45 = NULL ;
}
return V_38 ;
}
static int F_28 ( struct V_5 * V_6 )
{
struct V_2 * V_3 = F_8 ( V_6 ) ;
F_6 ( V_6 ) ;
F_29 ( V_3 -> V_17 ) ;
F_29 ( V_3 -> V_47 ) ;
F_26 ( V_3 -> V_17 ) ;
F_26 ( V_3 -> V_47 ) ;
V_3 -> V_17 = NULL ;
V_3 -> V_47 = NULL ;
F_27 ( V_3 -> V_34 . V_11 ) ;
V_3 -> V_34 . V_11 = NULL ;
V_3 -> V_34 . V_45 = NULL ;
V_3 -> V_34 . V_41 = FALSE ;
V_3 -> V_34 . V_35 = V_36 ;
V_3 -> V_28 = 0 ;
if ( V_3 -> V_50 )
F_25 ( V_3 -> V_50 ) ;
V_3 -> V_50 = NULL ;
return 0 ;
}
static int F_30 ( struct V_5 * V_6 , struct V_55 * V_56 ,
int V_57 )
{
struct V_58 * V_59 = (struct V_58 * ) V_56 ;
struct V_2 * V_3 = F_8 ( V_6 ) ;
int V_13 = 0 ;
switch ( V_57 ) {
case V_60 :
if ( ! F_31 ( V_61 ) )
return - V_62 ;
if ( F_32 ( V_3 -> V_6 ) )
V_13 = - V_63 ;
break;
case V_64 :
if ( ! F_31 ( V_61 ) )
return - V_62 ;
if ( F_2 ( V_3 -> V_6 ) )
F_33 ( V_3 -> V_6 , TRUE ) ;
break;
case V_65 :
V_59 -> V_66 = V_3 -> V_28 ;
break;
default:
V_13 = - V_63 ;
}
return V_13 ;
}
static int F_34 ( struct V_67 * V_68 ,
const struct V_69 * V_70 )
{
struct V_71 * V_72 ;
struct V_73 * V_74 ;
struct V_75 * V_8 = F_35 ( V_68 ) ;
struct V_2 * V_3 = NULL ;
struct V_5 * V_76 = NULL ;
int V_13 = - V_39 ;
int V_77 , V_78 , V_79 ;
T_2 V_52 ;
T_2 V_18 ;
V_72 = V_68 -> V_80 ;
if ( V_72 -> V_81 . V_82 != 2 ) {
F_3 ( & V_68 -> V_8 ,
L_9 ,
V_72 -> V_81 . V_82 ) ;
return - V_20 ;
}
V_74 = & V_72 -> V_74 [ V_83 ] . V_81 ;
if ( ! F_36 ( V_74 ) ) {
F_3 ( & V_68 -> V_8 ,
L_10 ) ;
return - V_20 ;
}
V_52 = V_74 -> V_84 ;
V_77 = F_24 ( V_8 , V_52 ) ;
V_78 = F_37 ( V_8 , V_77 , F_38 ( V_77 ) ) ;
if ( V_78 > 255 || V_78 <= 1 ) {
F_3 ( & V_68 -> V_8 ,
L_11 ,
V_78 ) ;
return - V_20 ;
}
V_74 = & V_72 -> V_74 [ V_85 ] . V_81 ;
if ( ! F_39 ( V_74 ) ) {
F_3 ( & V_68 -> V_8 ,
L_12 ) ;
return - V_20 ;
}
V_18 = V_74 -> V_84 ;
V_77 = F_12 ( V_8 , V_18 ) ;
V_79 = F_37 ( V_8 , V_77 , F_38 ( V_77 ) ) ;
V_76 = F_40 ( sizeof( * V_3 ) ) ;
if( ! V_76 )
goto V_86;
F_41 ( V_76 , & V_68 -> V_8 ) ;
V_3 = F_8 ( V_76 ) ;
V_3 -> V_50 = NULL ;
V_3 -> V_17 = NULL ;
V_3 -> V_47 = NULL ;
V_3 -> V_52 = V_52 ;
V_3 -> V_18 = V_18 ;
V_3 -> V_53 = NULL ;
V_3 -> V_15 = NULL ;
V_3 -> V_30 = ( T_2 ) V_78 ;
V_3 -> V_87 = ( T_2 ) V_79 ;
V_3 -> V_6 = V_76 ;
V_3 -> V_7 = V_8 ;
V_3 -> V_34 . V_41 = FALSE ;
V_3 -> V_34 . V_35 = V_36 ;
V_3 -> V_34 . V_11 = NULL ;
V_3 -> V_28 = 0 ;
F_42 ( & V_3 -> V_14 ) ;
V_3 -> V_53 = F_43 ( V_3 -> V_30 , V_48 ) ;
if ( ! V_3 -> V_53 )
goto V_44;
V_3 -> V_15 = F_43 ( V_16 , V_48 ) ;
if ( ! V_3 -> V_15 )
goto V_44;
F_44 ( V_88 L_13
L_14 ,
V_8 -> V_49 , F_45 ( V_8 -> V_89 . V_90 ) ,
F_45 ( V_8 -> V_89 . V_91 ) ) ;
F_46 ( & V_3 -> V_51 ) ;
V_3 -> V_51 . V_92 . V_93 &= V_94 ;
V_3 -> V_51 . V_95 . V_93 &= V_96 ;
F_47 ( & V_3 -> V_51 ) ;
V_76 -> V_97 = & V_98 ;
V_13 = F_48 ( V_76 ) ;
if ( V_13 != 0 )
goto V_44;
F_49 ( & V_76 -> V_8 , L_15 ,
V_76 -> V_99 ) ;
F_50 ( V_68 , V_3 ) ;
return 0 ;
V_44:
F_51 ( V_3 -> V_15 ) ;
F_51 ( V_3 -> V_53 ) ;
F_52 ( V_76 ) ;
V_86:
return V_13 ;
}
static void F_53 ( struct V_67 * V_68 )
{
struct V_2 * V_3 = F_54 ( V_68 ) ;
if ( ! V_3 )
return;
F_55 ( V_3 -> V_6 ) ;
if ( V_3 -> V_17 != NULL ) {
F_29 ( V_3 -> V_17 ) ;
F_26 ( V_3 -> V_17 ) ;
V_3 -> V_17 = NULL ;
}
if ( V_3 -> V_47 != NULL ) {
F_29 ( V_3 -> V_47 ) ;
F_26 ( V_3 -> V_47 ) ;
V_3 -> V_47 = NULL ;
}
F_51 ( V_3 -> V_15 ) ;
F_51 ( V_3 -> V_53 ) ;
F_52 ( V_3 -> V_6 ) ;
F_50 ( V_68 , NULL ) ;
}
static int F_56 ( struct V_67 * V_68 , T_3 V_100 )
{
struct V_2 * V_3 = F_54 ( V_68 ) ;
F_57 ( V_3 -> V_6 ) ;
if ( V_3 -> V_17 != NULL ) F_29 ( V_3 -> V_17 ) ;
if ( V_3 -> V_47 != NULL ) F_29 ( V_3 -> V_47 ) ;
return 0 ;
}
static int F_58 ( struct V_67 * V_68 )
{
struct V_2 * V_3 = F_54 ( V_68 ) ;
if ( V_3 -> V_47 != NULL )
F_13 ( V_3 -> V_47 , V_48 ) ;
F_59 ( V_3 -> V_6 ) ;
return 0 ;
}
