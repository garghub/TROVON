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
F_19 ( & V_3 -> V_35 ) ;
V_3 -> V_28 =
( V_3 -> V_34 . V_36 != V_37 )
? 1 : 0 ;
}
} else if ( V_1 -> V_29 > 0 ) {
F_3 ( & V_3 -> V_7 -> V_8 ,
L_5 ,
V_38 , V_3 -> V_30 , V_1 -> V_29 ) ;
}
V_13 = F_13 ( V_1 , V_19 ) ;
}
static int F_20 ( struct V_5 * V_6 )
{
struct V_2 * V_3 = F_8 ( V_6 ) ;
int V_39 = - V_40 ;
char V_41 [ 16 ] ;
V_3 -> V_28 = 0 ;
V_3 -> V_34 . V_42 = FALSE ;
V_3 -> V_34 . V_36 = V_37 ;
V_3 -> V_34 . V_43 = V_44 ;
V_3 -> V_34 . V_11 = F_21 ( V_44 ) ;
if ( ! V_3 -> V_34 . V_11 )
goto V_45;
F_22 ( V_3 -> V_34 . V_11 , 1 ) ;
V_3 -> V_34 . V_46 = V_3 -> V_34 . V_11 -> V_47 ;
F_19 ( & V_3 -> V_35 ) ;
V_3 -> V_48 = F_23 ( 0 , V_49 ) ;
if ( ! V_3 -> V_48 )
goto V_45;
V_3 -> V_17 = F_23 ( 0 , V_49 ) ;
if ( ! V_3 -> V_17 )
goto V_45;
sprintf ( V_41 , L_6 , V_3 -> V_7 -> V_50 ) ;
V_3 -> V_51 = F_24 ( V_6 , & V_3 -> V_52 , V_41 ) ;
if ( ! V_3 -> V_51 ) {
F_3 ( & V_3 -> V_7 -> V_8 , L_7 ) ;
goto V_45;
}
F_11 ( V_3 -> V_48 , V_3 -> V_7 ,
F_25 ( V_3 -> V_7 , V_3 -> V_53 ) ,
V_3 -> V_54 , V_3 -> V_30 ,
F_17 , V_3 , 1 ) ;
V_3 -> V_48 -> V_9 = 0 ;
V_39 = F_13 ( V_3 -> V_48 , V_49 ) ;
if ( V_39 ) {
F_3 ( & V_3 -> V_7 -> V_8 ,
L_8 , V_39 ) ;
goto V_55;
}
F_14 ( V_6 ) ;
return 0 ;
V_55:
F_26 ( V_3 -> V_51 ) ;
V_45:
if ( V_3 -> V_17 ) {
F_27 ( V_3 -> V_17 ) ;
V_3 -> V_17 = NULL ;
}
if ( V_3 -> V_48 ) {
F_27 ( V_3 -> V_48 ) ;
V_3 -> V_48 = NULL ;
}
if ( V_3 -> V_34 . V_11 ) {
F_28 ( V_3 -> V_34 . V_11 ) ;
V_3 -> V_34 . V_11 = NULL ;
V_3 -> V_34 . V_46 = NULL ;
}
return V_39 ;
}
static int F_29 ( struct V_5 * V_6 )
{
struct V_2 * V_3 = F_8 ( V_6 ) ;
F_6 ( V_6 ) ;
F_30 ( V_3 -> V_17 ) ;
F_30 ( V_3 -> V_48 ) ;
F_27 ( V_3 -> V_17 ) ;
F_27 ( V_3 -> V_48 ) ;
V_3 -> V_17 = NULL ;
V_3 -> V_48 = NULL ;
F_28 ( V_3 -> V_34 . V_11 ) ;
V_3 -> V_34 . V_11 = NULL ;
V_3 -> V_34 . V_46 = NULL ;
V_3 -> V_34 . V_42 = FALSE ;
V_3 -> V_34 . V_36 = V_37 ;
V_3 -> V_28 = 0 ;
if ( V_3 -> V_51 )
F_26 ( V_3 -> V_51 ) ;
V_3 -> V_51 = NULL ;
return 0 ;
}
static int F_31 ( struct V_5 * V_6 , struct V_56 * V_57 ,
int V_58 )
{
struct V_59 * V_60 = (struct V_59 * ) V_57 ;
struct V_2 * V_3 = F_8 ( V_6 ) ;
int V_13 = 0 ;
switch ( V_58 ) {
case V_61 :
if ( ! F_32 ( V_62 ) )
return - V_63 ;
if ( F_33 ( V_3 -> V_6 ) )
V_13 = - V_64 ;
break;
case V_65 :
if ( ! F_32 ( V_62 ) )
return - V_63 ;
if ( F_2 ( V_3 -> V_6 ) )
F_34 ( V_3 -> V_6 , TRUE ) ;
break;
case V_66 :
V_60 -> V_67 = V_3 -> V_28 ;
break;
default:
V_13 = - V_64 ;
}
return V_13 ;
}
static int F_35 ( struct V_68 * V_69 ,
const struct V_70 * V_71 )
{
struct V_72 * V_73 ;
struct V_74 * V_75 ;
struct V_76 * V_8 = F_36 ( V_69 ) ;
struct V_2 * V_3 = NULL ;
struct V_5 * V_77 = NULL ;
int V_13 = - V_40 ;
int V_78 , V_79 , V_80 ;
T_2 V_53 ;
T_2 V_18 ;
V_73 = V_69 -> V_81 ;
if ( V_73 -> V_82 . V_83 != 2 ) {
F_3 ( & V_69 -> V_8 ,
L_9 ,
V_73 -> V_82 . V_83 ) ;
return - V_20 ;
}
V_75 = & V_73 -> V_75 [ V_84 ] . V_82 ;
if ( ! F_37 ( V_75 ) ) {
F_3 ( & V_69 -> V_8 ,
L_10 ) ;
return - V_20 ;
}
V_53 = V_75 -> V_85 ;
V_78 = F_25 ( V_8 , V_53 ) ;
V_79 = F_38 ( V_8 , V_78 , F_39 ( V_78 ) ) ;
if ( V_79 > 255 || V_79 <= 1 ) {
F_3 ( & V_69 -> V_8 ,
L_11 ,
V_79 ) ;
return - V_20 ;
}
V_75 = & V_73 -> V_75 [ V_86 ] . V_82 ;
if ( ! F_40 ( V_75 ) ) {
F_3 ( & V_69 -> V_8 ,
L_12 ) ;
return - V_20 ;
}
V_18 = V_75 -> V_85 ;
V_78 = F_12 ( V_8 , V_18 ) ;
V_80 = F_38 ( V_8 , V_78 , F_39 ( V_78 ) ) ;
V_77 = F_41 ( sizeof( * V_3 ) ) ;
if( ! V_77 )
goto V_87;
F_42 ( V_77 , & V_69 -> V_8 ) ;
V_3 = F_8 ( V_77 ) ;
V_3 -> V_51 = NULL ;
V_3 -> V_17 = NULL ;
V_3 -> V_48 = NULL ;
V_3 -> V_53 = V_53 ;
V_3 -> V_18 = V_18 ;
V_3 -> V_54 = NULL ;
V_3 -> V_15 = NULL ;
V_3 -> V_30 = ( T_2 ) V_79 ;
V_3 -> V_88 = ( T_2 ) V_80 ;
V_3 -> V_6 = V_77 ;
V_3 -> V_7 = V_8 ;
V_3 -> V_34 . V_42 = FALSE ;
V_3 -> V_34 . V_36 = V_37 ;
V_3 -> V_34 . V_11 = NULL ;
V_3 -> V_28 = 0 ;
F_43 ( & V_3 -> V_14 ) ;
V_3 -> V_54 = F_44 ( V_3 -> V_30 , V_49 ) ;
if ( ! V_3 -> V_54 )
goto V_45;
V_3 -> V_15 = F_44 ( V_16 , V_49 ) ;
if ( ! V_3 -> V_15 )
goto V_45;
F_45 ( V_89 L_13
L_14 ,
V_8 -> V_50 , F_46 ( V_8 -> V_90 . V_91 ) ,
F_46 ( V_8 -> V_90 . V_92 ) ) ;
F_47 ( & V_3 -> V_52 ) ;
V_3 -> V_52 . V_93 . V_94 &= V_95 ;
V_3 -> V_52 . V_96 . V_94 &= V_97 ;
F_48 ( & V_3 -> V_52 ) ;
V_77 -> V_98 = & V_99 ;
V_13 = F_49 ( V_77 ) ;
if ( V_13 != 0 )
goto V_45;
F_50 ( & V_77 -> V_8 , L_15 ,
V_77 -> V_100 ) ;
F_51 ( V_69 , V_3 ) ;
return 0 ;
V_45:
if ( V_3 -> V_15 ) F_52 ( V_3 -> V_15 ) ;
if ( V_3 -> V_54 ) F_52 ( V_3 -> V_54 ) ;
F_53 ( V_77 ) ;
V_87:
return V_13 ;
}
static void F_54 ( struct V_68 * V_69 )
{
struct V_2 * V_3 = F_55 ( V_69 ) ;
if ( ! V_3 )
return;
F_56 ( V_3 -> V_6 ) ;
if ( V_3 -> V_17 != NULL ) {
F_30 ( V_3 -> V_17 ) ;
F_27 ( V_3 -> V_17 ) ;
V_3 -> V_17 = NULL ;
}
if ( V_3 -> V_48 != NULL ) {
F_30 ( V_3 -> V_48 ) ;
F_27 ( V_3 -> V_48 ) ;
V_3 -> V_48 = NULL ;
}
F_52 ( V_3 -> V_15 ) ;
F_52 ( V_3 -> V_54 ) ;
F_53 ( V_3 -> V_6 ) ;
F_51 ( V_69 , NULL ) ;
}
static int F_57 ( struct V_68 * V_69 , T_3 V_101 )
{
struct V_2 * V_3 = F_55 ( V_69 ) ;
F_58 ( V_3 -> V_6 ) ;
if ( V_3 -> V_17 != NULL ) F_30 ( V_3 -> V_17 ) ;
if ( V_3 -> V_48 != NULL ) F_30 ( V_3 -> V_48 ) ;
return 0 ;
}
static int F_59 ( struct V_68 * V_69 )
{
struct V_2 * V_3 = F_55 ( V_69 ) ;
if ( V_3 -> V_48 != NULL )
F_13 ( V_3 -> V_48 , V_49 ) ;
F_60 ( V_3 -> V_6 ) ;
return 0 ;
}
