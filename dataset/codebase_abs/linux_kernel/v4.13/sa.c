static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
unsigned short V_5 , V_6 ;
V_5 = F_2 ( V_4 , V_7 ) ;
V_6 = ~ ( F_2 ( V_4 , V_8 . V_9 ) ) ;
if ( V_5 & V_6 ) {
if ( V_5 & V_10 ) {
F_3 ( V_4 , F_4 ( V_4 , V_11 ) ) ;
F_5 ( V_4 , V_12 , V_10 ) ;
F_5 ( V_4 , V_13 , V_14 ) ;
} else if ( V_5 & V_15 ) {
F_5 ( V_4 , V_12 , V_15 ) ;
F_6 ( & V_4 -> V_16 -> V_17 [ V_18 ] ) ;
} else if ( V_5 & V_19 ) {
F_5 ( V_4 , V_12 , V_19 ) ;
F_7 ( & V_4 -> V_16 -> V_17 [ V_20 ] ) ;
} else if ( V_5 & V_21 ) {
F_5 ( V_4 , V_12 , V_21 ) ;
} else if ( V_5 & V_22 ) {
F_5 ( V_4 , V_12 , V_22 ) ;
}
return V_23 ;
}
return V_24 ;
}
static void F_8 ( struct V_3 * V_4 )
{
F_5 ( V_4 , V_8 . V_9 , 0xffff ) ;
}
static void F_9 ( struct V_3 * V_4 )
{
F_5 ( V_4 , V_8 . V_25 , ( V_10 | V_15 |
V_19 | V_21 | V_22 ) ) ;
}
static void F_10 ( struct V_3 * V_4 , T_2 V_26 )
{
switch ( V_26 ) {
case V_27 :
F_5 ( V_4 , V_13 , V_15 ) ;
break;
case V_28 :
F_5 ( V_4 , V_13 , V_22 ) ;
break;
case V_29 :
F_5 ( V_4 , V_13 , V_19 ) ;
break;
case V_30 :
F_5 ( V_4 , V_13 , V_21 ) ;
break;
case V_31 :
break;
case V_32 :
F_5 ( V_4 , V_13 , V_33 ) ;
break;
case V_34 :
F_5 ( V_4 , V_13 , V_35 ) ;
break;
default:
F_11 () ;
break;
}
}
static int F_12 ( struct V_3 * V_4 , T_2 V_36 ,
T_2 V_37 , T_2 V_38 , T_2 V_39 , T_2 V_40 , T_2 V_41 , T_2 V_42 ,
T_2 * V_43 , T_2 * V_44 , T_2 * V_45 , T_2 * V_46 , T_2 * V_47 )
{
unsigned long V_48 ;
int V_49 ;
F_13 ( V_4 , V_50 , V_36 ) ;
F_13 ( V_4 , V_51 , V_37 ) ;
F_13 ( V_4 , V_52 , V_38 ) ;
F_13 ( V_4 , V_53 , V_39 ) ;
F_13 ( V_4 , V_54 , V_40 ) ;
F_5 ( V_4 , V_12 , V_55 ) ;
F_5 ( V_4 , V_13 , V_55 ) ;
V_49 = 0 ;
V_48 = V_56 ;
while( F_14 ( V_56 , V_48 + 30 * V_57 ) )
{
F_15 ( 5 ) ;
if( F_2 ( V_4 , V_7 ) & V_55 ) {
V_49 = 1 ;
break;
}
F_16 ( 1 ) ;
}
if ( V_49 != 1 )
return - V_58 ;
F_5 ( V_4 , V_12 , V_55 ) ;
if ( V_43 )
* V_43 = F_4 ( V_4 , V_50 ) ;
if ( V_44 )
* V_44 = F_4 ( V_4 , V_51 ) ;
if ( V_45 )
* V_45 = F_4 ( V_4 , V_52 ) ;
if ( V_46 )
* V_46 = F_4 ( V_4 , V_53 ) ;
if ( V_47 )
* V_47 = F_4 ( V_4 , V_54 ) ;
return 0 ;
}
static void F_17 ( struct V_3 * V_4 )
{
F_12 ( V_4 , V_59 , 0 , 0 , 0 , 0 , 0 , 0 ,
NULL , NULL , NULL , NULL , NULL ) ;
}
static void F_18 ( struct V_3 * V_4 )
{
union V_60 * V_61 ;
V_61 = V_4 -> V_61 ;
V_61 -> V_62 . V_63 = F_19 ( F_20 () ) ;
F_12 ( V_4 , V_64 ,
( T_2 ) ( V_65 ) V_4 -> V_66 , 0 , 0 , 0 , 0 , 0 ,
NULL , NULL , NULL , NULL , NULL ) ;
}
static int F_21 ( struct V_3 * V_4 , int V_67 , T_3 V_68 )
{
return - V_69 ;
}
static int F_22 ( struct V_3 * V_4 )
{
long V_70 = F_4 ( V_4 , V_71 ) ;
if ( V_70 & V_72 )
return - 1 ;
if ( V_70 & V_73 )
return - 2 ;
if ( ! ( V_70 & V_74 ) )
return - 3 ;
return 0 ;
}
static int F_23 ( struct V_3 * V_4 , T_2 V_75 )
{
if ( ! V_75 ) {
F_24 ( V_4 -> V_76 . V_77 ) ;
return 0 ;
}
V_4 -> V_78 = V_4 -> V_76 . V_77 = F_25 ( V_4 -> V_79 , V_75 ) ;
return ( V_4 -> V_78 == NULL ) ? - 1 : 0 ;
}
int F_26 ( struct V_3 * V_4 )
{
unsigned long V_48 ;
unsigned long V_70 ;
int V_80 ;
const char * V_81 ;
V_80 = V_4 -> V_82 ;
V_81 = V_4 -> V_81 ;
if ( F_23 ( V_4 , V_4 -> V_83 ) ) {
F_27 ( V_84 L_1 , V_81 ) ;
goto V_85;
}
if ( F_4 ( V_4 , V_71 ) & V_72 ) {
F_27 ( V_84 L_2 , V_81 , V_80 ) ;
goto V_85;
}
if ( F_4 ( V_4 , V_71 ) & V_73 ) {
F_27 ( V_84 L_3 , V_81 , V_80 ) ;
goto V_85;
}
V_48 = V_56 ;
while ( ! ( F_4 ( V_4 , V_71 ) & V_74 ) ) {
if ( F_28 ( V_56 , V_48 + V_86 * V_57 ) ) {
V_70 = F_4 ( V_4 , V_71 ) ;
F_27 ( V_84 L_4 ,
V_81 , V_80 , V_70 ) ;
goto V_85;
}
F_16 ( 1 ) ;
}
V_4 -> V_87 . V_88 = F_17 ;
V_4 -> V_87 . V_89 = F_8 ;
V_4 -> V_87 . V_90 = F_9 ;
V_4 -> V_87 . V_91 = F_10 ;
V_4 -> V_87 . V_92 = F_12 ;
V_4 -> V_87 . V_93 = F_22 ;
V_4 -> V_87 . V_94 = F_21 ;
V_4 -> V_87 . V_95 = F_18 ;
V_4 -> V_87 . V_96 = F_1 ;
V_4 -> V_87 . V_97 = V_98 ;
V_4 -> V_87 . V_99 = F_23 ;
F_29 ( V_4 ) ;
F_30 ( V_4 ) ;
if( F_31 ( V_4 ) == NULL )
goto V_100;
V_4 -> V_101 = 0 ;
if ( F_32 ( V_4 -> V_102 -> V_1 , V_4 -> V_87 . V_96 ,
V_103 , L_5 , ( void * ) V_4 ) < 0 ) {
F_27 ( V_84 L_6 ,
V_81 , V_80 ) ;
goto V_85;
}
V_4 -> V_104 = V_4 -> V_79 ;
V_4 -> V_105 = V_4 -> V_78 ;
V_4 -> V_106 = V_4 -> V_83 ;
F_30 ( V_4 ) ;
F_18 ( V_4 ) ;
return 0 ;
V_100:
F_8 ( V_4 ) ;
F_33 ( V_4 -> V_102 -> V_1 , ( void * ) V_4 ) ;
V_85:
return - 1 ;
}
