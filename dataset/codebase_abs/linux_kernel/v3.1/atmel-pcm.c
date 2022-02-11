static int F_1 ( struct V_1 * V_2 ,
int V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 [ V_3 ] . V_5 ;
struct V_7 * V_8 = & V_5 -> V_9 ;
T_1 V_10 = V_11 . V_12 ;
V_8 -> V_13 . type = V_14 ;
V_8 -> V_13 . V_13 = V_2 -> V_15 -> V_13 ;
V_8 -> V_16 = NULL ;
V_8 -> V_17 = F_2 ( V_2 -> V_15 -> V_13 , V_10 ,
& V_8 -> V_18 , V_19 ) ;
F_3 ( L_1
L_2 ,
( void * ) V_8 -> V_17 ,
( void * ) V_8 -> V_18 ,
V_10 ) ;
if ( ! V_8 -> V_17 )
return - V_20 ;
V_8 -> V_21 = V_10 ;
return 0 ;
}
static void F_4 ( T_2 V_22 ,
struct V_4 * V_5 )
{
struct V_23 * V_24 = V_5 -> V_25 -> V_16 ;
struct V_26 * V_27 = V_24 -> V_27 ;
static int V_28 ;
V_28 ++ ;
if ( V_22 & V_27 -> V_29 -> V_30 ) {
F_5 ( L_3
L_4 ,
V_5 -> V_3 == V_31
? L_5 : L_6 ,
V_27 -> V_32 , V_22 , V_28 ) ;
F_6 ( V_27 -> V_33 -> V_34 , V_35 ,
V_27 -> V_29 -> V_36 ) ;
V_24 -> V_37 += V_24 -> V_38 ;
if ( V_24 -> V_37 >= V_24 -> V_39 )
V_24 -> V_37 = V_24 -> V_9 ;
F_6 ( V_27 -> V_33 -> V_34 , V_27 -> V_40 -> V_41 ,
V_24 -> V_37 ) ;
F_6 ( V_27 -> V_33 -> V_34 , V_27 -> V_40 -> V_42 ,
V_24 -> V_38 / V_27 -> V_43 ) ;
F_6 ( V_27 -> V_33 -> V_34 , V_35 ,
V_27 -> V_29 -> V_44 ) ;
}
if ( V_22 & V_27 -> V_29 -> V_45 ) {
V_24 -> V_37 += V_24 -> V_38 ;
if ( V_24 -> V_37 >= V_24 -> V_39 )
V_24 -> V_37 = V_24 -> V_9 ;
F_6 ( V_27 -> V_33 -> V_34 , V_27 -> V_40 -> V_46 ,
V_24 -> V_37 ) ;
F_6 ( V_27 -> V_33 -> V_34 , V_27 -> V_40 -> V_47 ,
V_24 -> V_38 / V_27 -> V_43 ) ;
}
F_7 ( V_5 ) ;
}
static int F_8 ( struct V_4 * V_5 ,
struct V_48 * V_27 )
{
struct V_49 * V_25 = V_5 -> V_25 ;
struct V_23 * V_24 = V_25 -> V_16 ;
struct V_50 * V_51 = V_5 -> V_16 ;
F_9 ( V_5 , & V_5 -> V_9 ) ;
V_25 -> V_52 = F_10 ( V_27 ) ;
V_24 -> V_27 = F_11 ( V_51 -> V_53 , V_5 ) ;
V_24 -> V_27 -> V_54 = F_4 ;
V_24 -> V_9 = V_25 -> V_55 ;
V_24 -> V_39 = V_25 -> V_55 + V_25 -> V_52 ;
V_24 -> V_38 = F_12 ( V_27 ) ;
F_3 ( L_7
L_8
L_9 ,
V_24 -> V_27 -> V_32 ,
V_25 -> V_52 ,
V_24 -> V_38 ) ;
return 0 ;
}
static int F_13 ( struct V_4 * V_5 )
{
struct V_23 * V_24 = V_5 -> V_25 -> V_16 ;
struct V_26 * V_27 = V_24 -> V_27 ;
if ( V_27 != NULL ) {
F_6 ( V_27 -> V_33 -> V_34 , V_56 ,
V_27 -> V_29 -> V_36 ) ;
V_24 -> V_27 -> V_54 = NULL ;
}
return 0 ;
}
static int F_14 ( struct V_4 * V_5 )
{
struct V_23 * V_24 = V_5 -> V_25 -> V_16 ;
struct V_26 * V_27 = V_24 -> V_27 ;
F_6 ( V_27 -> V_33 -> V_34 , V_57 ,
V_27 -> V_29 -> V_45 | V_27 -> V_29 -> V_30 ) ;
F_6 ( V_27 -> V_33 -> V_34 , V_35 ,
V_27 -> V_29 -> V_36 ) ;
return 0 ;
}
static int F_15 ( struct V_4 * V_5 ,
int V_58 )
{
struct V_49 * V_51 = V_5 -> V_25 ;
struct V_23 * V_24 = V_51 -> V_16 ;
struct V_26 * V_27 = V_24 -> V_27 ;
int V_59 = 0 ;
F_3 ( L_10
L_11 ,
V_51 -> V_60 , V_51 -> V_61 , V_51 -> V_52 ) ;
switch ( V_58 ) {
case V_62 :
V_24 -> V_37 = V_24 -> V_9 ;
F_6 ( V_27 -> V_33 -> V_34 , V_27 -> V_40 -> V_41 ,
V_24 -> V_37 ) ;
F_6 ( V_27 -> V_33 -> V_34 , V_27 -> V_40 -> V_42 ,
V_24 -> V_38 / V_27 -> V_43 ) ;
V_24 -> V_37 += V_24 -> V_38 ;
F_6 ( V_27 -> V_33 -> V_34 , V_27 -> V_40 -> V_46 ,
V_24 -> V_37 ) ;
F_6 ( V_27 -> V_33 -> V_34 , V_27 -> V_40 -> V_47 ,
V_24 -> V_38 / V_27 -> V_43 ) ;
F_3 ( L_12
L_13
L_14 ,
( unsigned long ) V_24 -> V_37 ,
F_16 ( V_27 -> V_33 -> V_34 , V_27 -> V_40 -> V_41 ) ,
F_16 ( V_27 -> V_33 -> V_34 , V_27 -> V_40 -> V_42 ) ,
F_16 ( V_27 -> V_33 -> V_34 , V_27 -> V_40 -> V_46 ) ,
F_16 ( V_27 -> V_33 -> V_34 , V_27 -> V_40 -> V_47 ) ) ;
F_6 ( V_27 -> V_33 -> V_34 , V_63 ,
V_27 -> V_29 -> V_45 | V_27 -> V_29 -> V_30 ) ;
F_6 ( V_27 -> V_33 -> V_34 , V_56 ,
V_27 -> V_29 -> V_44 ) ;
F_3 ( L_15 ,
F_16 ( V_27 -> V_33 -> V_34 , V_64 ) ,
F_16 ( V_27 -> V_33 -> V_34 , V_63 ) ) ;
break;
case V_65 :
case V_66 :
case V_67 :
F_6 ( V_27 -> V_33 -> V_34 , V_35 ,
V_27 -> V_29 -> V_36 ) ;
break;
case V_68 :
case V_69 :
F_6 ( V_27 -> V_33 -> V_34 , V_35 ,
V_27 -> V_29 -> V_44 ) ;
break;
default:
V_59 = - V_70 ;
}
return V_59 ;
}
static T_3 F_17 (
struct V_4 * V_5 )
{
struct V_49 * V_25 = V_5 -> V_25 ;
struct V_23 * V_24 = V_25 -> V_16 ;
struct V_26 * V_27 = V_24 -> V_27 ;
T_4 V_71 ;
T_3 V_72 ;
V_71 = ( T_4 ) F_16 ( V_27 -> V_33 -> V_34 , V_27 -> V_40 -> V_41 ) ;
V_72 = F_18 ( V_25 , V_71 - V_24 -> V_9 ) ;
if ( V_72 == V_25 -> V_60 )
V_72 = 0 ;
return V_72 ;
}
static int F_19 ( struct V_4 * V_5 )
{
struct V_49 * V_25 = V_5 -> V_25 ;
struct V_23 * V_24 ;
int V_59 = 0 ;
F_20 ( V_5 , & V_11 ) ;
V_59 = F_21 ( V_25 ,
V_73 ) ;
if ( V_59 < 0 )
goto V_74;
V_24 = F_22 ( sizeof( struct V_23 ) , V_19 ) ;
if ( V_24 == NULL ) {
V_59 = - V_20 ;
goto V_74;
}
V_25 -> V_16 = V_24 ;
V_74:
return V_59 ;
}
static int F_23 ( struct V_4 * V_5 )
{
struct V_23 * V_24 = V_5 -> V_25 -> V_16 ;
F_24 ( V_24 ) ;
return 0 ;
}
static int F_25 ( struct V_4 * V_5 ,
struct V_75 * V_76 )
{
return F_26 ( V_76 , V_76 -> V_77 ,
V_5 -> V_9 . V_18 >> V_78 ,
V_76 -> V_79 - V_76 -> V_77 , V_76 -> V_80 ) ;
}
static int F_27 ( struct V_50 * V_51 )
{
struct V_81 * V_15 = V_51 -> V_15 -> V_81 ;
struct V_82 * V_83 = V_51 -> V_53 ;
struct V_1 * V_2 = V_51 -> V_2 ;
int V_59 = 0 ;
if ( ! V_15 -> V_13 -> V_84 )
V_15 -> V_13 -> V_84 = & V_85 ;
if ( ! V_15 -> V_13 -> V_86 )
V_15 -> V_13 -> V_86 = 0xffffffff ;
if ( V_83 -> V_87 -> V_88 . V_89 ) {
V_59 = F_1 ( V_2 ,
V_31 ) ;
if ( V_59 )
goto V_74;
}
if ( V_83 -> V_87 -> V_90 . V_89 ) {
F_3 ( L_1
L_16 ) ;
V_59 = F_1 ( V_2 ,
V_91 ) ;
if ( V_59 )
goto V_74;
}
V_74:
return V_59 ;
}
static void F_28 ( struct V_1 * V_2 )
{
struct V_4 * V_5 ;
struct V_7 * V_8 ;
int V_3 ;
for ( V_3 = 0 ; V_3 < 2 ; V_3 ++ ) {
V_5 = V_2 -> V_6 [ V_3 ] . V_5 ;
if ( ! V_5 )
continue;
V_8 = & V_5 -> V_9 ;
if ( ! V_8 -> V_17 )
continue;
F_29 ( V_2 -> V_15 -> V_13 , V_8 -> V_21 ,
V_8 -> V_17 , V_8 -> V_18 ) ;
V_8 -> V_17 = NULL ;
}
}
static int F_30 ( struct V_82 * V_83 )
{
struct V_49 * V_25 = V_83 -> V_25 ;
struct V_23 * V_24 ;
struct V_26 * V_27 ;
if ( ! V_25 )
return 0 ;
V_24 = V_25 -> V_16 ;
V_27 = V_24 -> V_27 ;
F_31 ( V_27 -> V_33 -> V_34 , V_92 , V_27 -> V_29 -> V_36 ) ;
V_24 -> V_93 = F_16 ( V_27 -> V_33 -> V_34 , V_27 -> V_40 -> V_41 ) ;
V_24 -> V_94 = F_16 ( V_27 -> V_33 -> V_34 , V_27 -> V_40 -> V_42 ) ;
V_24 -> V_95 = F_16 ( V_27 -> V_33 -> V_34 , V_27 -> V_40 -> V_46 ) ;
V_24 -> V_96 = F_16 ( V_27 -> V_33 -> V_34 , V_27 -> V_40 -> V_47 ) ;
return 0 ;
}
static int F_32 ( struct V_82 * V_83 )
{
struct V_49 * V_25 = V_83 -> V_25 ;
struct V_23 * V_24 ;
struct V_26 * V_27 ;
if ( ! V_25 )
return 0 ;
V_24 = V_25 -> V_16 ;
V_27 = V_24 -> V_27 ;
F_6 ( V_27 -> V_33 -> V_34 , V_27 -> V_40 -> V_41 , V_24 -> V_93 ) ;
F_6 ( V_27 -> V_33 -> V_34 , V_27 -> V_40 -> V_42 , V_24 -> V_94 ) ;
F_6 ( V_27 -> V_33 -> V_34 , V_27 -> V_40 -> V_46 , V_24 -> V_95 ) ;
F_6 ( V_27 -> V_33 -> V_34 , V_27 -> V_40 -> V_47 , V_24 -> V_96 ) ;
F_31 ( V_27 -> V_33 -> V_34 , V_92 , V_27 -> V_29 -> V_44 ) ;
return 0 ;
}
static int T_5 F_33 ( struct V_97 * V_98 )
{
return F_34 ( & V_98 -> V_13 , & V_99 ) ;
}
static int T_6 F_35 ( struct V_97 * V_98 )
{
F_36 ( & V_98 -> V_13 ) ;
return 0 ;
}
static int T_7 F_37 ( void )
{
return F_38 ( & V_100 ) ;
}
static void T_8 F_39 ( void )
{
F_40 ( & V_100 ) ;
}
