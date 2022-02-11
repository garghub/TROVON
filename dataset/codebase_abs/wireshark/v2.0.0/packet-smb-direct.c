static void
F_1 ( void )
{
F_2 ( & V_1 ,
& V_2 ) ;
}
static void
F_3 ( void )
{
F_4 ( & V_1 ) ;
}
static void
F_5 ( T_1 * V_3 , T_2 * V_4 ,
T_3 * V_5 , T_4 V_6 )
{
T_5 V_7 = V_4 -> V_8 ;
int V_9 = V_4 -> V_10 -> V_11 . V_12 ;
T_6 * V_13 = NULL ;
T_7 * V_14 = NULL ;
T_1 * V_15 = NULL ;
T_5 V_16 = FALSE ;
T_5 V_17 = FALSE ;
T_8 * V_18 ;
if ( ! V_19 ) {
V_15 = V_3 ;
goto V_20;
}
V_13 = F_6 ( V_4 ) ;
if ( V_6 > 0 ) {
V_16 = TRUE ;
}
V_14 = ( T_7 * ) F_7 ( F_8 () , V_4 , V_21 , 0 ) ;
if ( V_14 == NULL ) {
V_17 = TRUE ;
V_4 -> V_10 -> V_11 . V_12 = 0 ;
V_14 = F_9 ( & V_1 ,
V_3 , 0 , V_4 ,
V_13 -> V_22 ,
NULL , F_10 ( V_3 ) ,
V_16 ) ;
}
if ( V_14 == NULL ) {
V_14 = F_11 ( & V_1 ,
V_4 ,
V_13 -> V_22 ) ;
}
if ( V_14 == NULL ) {
goto V_23;
}
if ( V_17 ) {
F_12 ( F_8 () , V_4 ,
V_21 , 0 , V_14 ) ;
}
V_15 = F_13 ( V_3 , 0 , V_4 ,
L_1 ,
V_14 ,
& V_24 ,
NULL ,
V_5 ) ;
if ( V_15 == NULL ) {
goto V_23;
}
V_20:
V_4 -> V_8 = FALSE ;
if ( ! F_14 ( V_25 ,
V_15 , V_4 , V_5 , & V_18 , NULL ) ) {
F_15 ( V_26 , V_15 , V_4 , V_5 ) ;
}
V_23:
V_4 -> V_8 = V_7 ;
V_4 -> V_10 -> V_11 . V_12 = V_9 ;
return;
}
static void
F_16 ( T_1 * V_3 , T_2 * V_4 , T_3 * V_27 ,
enum V_28 V_29 )
{
T_3 * V_5 = NULL ;
T_9 * V_30 = NULL ;
T_3 * V_31 = NULL ;
T_3 * V_32 = NULL ;
T_3 * V_33 = NULL ;
int V_34 = 0 ;
T_4 V_35 = 0 ;
T_4 V_6 = 0 ;
T_4 V_36 = 0 ;
T_4 V_37 = 0 ;
T_10 V_38 = F_17 ( V_3 ) ;
T_11 V_39 = 0 ;
T_1 * V_40 = NULL ;
static const int * V_11 [] = {
& V_41 ,
NULL
} ;
F_18 ( V_4 -> V_42 , V_43 , L_2 ) ;
F_19 ( V_4 -> V_42 , V_44 ) ;
if ( V_27 != NULL ) {
V_30 = F_20 ( V_27 , V_21 , V_3 , 0 , - 1 , V_45 ) ;
V_5 = F_21 ( V_30 , V_46 ) ;
}
switch ( V_29 ) {
case V_47 :
break;
case V_48 :
F_22 ( V_4 -> V_42 , V_44 , L_3 ) ;
if ( V_5 == NULL ) {
break;
}
V_30 = F_20 ( V_5 , V_49 , V_3 , 0 , - 1 , V_45 ) ;
V_31 = F_21 ( V_30 , V_50 ) ;
F_20 ( V_31 , V_51 ,
V_3 , V_34 , 2 , V_52 ) ;
V_34 += 2 ;
F_20 ( V_31 , V_53 ,
V_3 , V_34 , 2 , V_52 ) ;
V_34 += 2 ;
V_34 += 2 ;
F_20 ( V_31 , V_54 ,
V_3 , V_34 , 2 , V_52 ) ;
V_34 += 2 ;
F_20 ( V_31 , V_55 ,
V_3 , V_34 , 4 , V_52 ) ;
V_34 += 4 ;
F_20 ( V_31 , V_56 ,
V_3 , V_34 , 4 , V_52 ) ;
V_34 += 4 ;
F_20 ( V_31 , V_57 ,
V_3 , V_34 , 4 , V_52 ) ;
break;
case V_58 :
F_22 ( V_4 -> V_42 , V_44 , L_4 ) ;
V_35 = F_23 ( V_3 , 12 ) ;
if ( V_35 != 0 ) {
F_24 (
V_4 -> V_42 , V_44 , L_5 ,
F_25 ( V_35 , V_59 , L_6 ) ) ;
}
if ( V_5 == NULL ) {
break;
}
V_30 = F_20 ( V_5 , V_60 , V_3 , 0 , - 1 , V_45 ) ;
V_32 = F_21 ( V_30 , V_50 ) ;
F_20 ( V_32 , V_51 ,
V_3 , V_34 , 2 , V_52 ) ;
V_34 += 2 ;
F_20 ( V_32 , V_53 ,
V_3 , V_34 , 2 , V_52 ) ;
V_34 += 2 ;
F_20 ( V_32 , V_61 ,
V_3 , V_34 , 2 , V_52 ) ;
V_34 += 2 ;
V_34 += 2 ;
F_20 ( V_32 , V_54 ,
V_3 , V_34 , 2 , V_52 ) ;
V_34 += 2 ;
F_20 ( V_32 , V_62 ,
V_3 , V_34 , 2 , V_52 ) ;
V_34 += 2 ;
F_20 ( V_32 , V_63 ,
V_3 , V_34 , 4 , V_52 ) ;
V_34 += 4 ;
F_20 ( V_32 , V_64 ,
V_3 , V_34 , 4 , V_52 ) ;
V_34 += 4 ;
F_20 ( V_32 , V_55 ,
V_3 , V_34 , 4 , V_52 ) ;
V_34 += 4 ;
F_20 ( V_32 , V_56 ,
V_3 , V_34 , 4 , V_52 ) ;
V_34 += 4 ;
F_20 ( V_32 , V_57 ,
V_3 , V_34 , 4 , V_52 ) ;
break;
case V_65 :
F_22 ( V_4 -> V_42 , V_44 , L_7 ) ;
if ( V_5 == NULL ) {
break;
}
V_38 = F_26 ( V_38 , 24 ) ;
V_30 = F_20 ( V_5 , V_66 , V_3 , 0 , V_38 , V_45 ) ;
V_33 = F_21 ( V_30 , V_50 ) ;
F_20 ( V_33 , V_54 ,
V_3 , V_34 , 2 , V_52 ) ;
V_34 += 2 ;
F_20 ( V_33 , V_62 ,
V_3 , V_34 , 2 , V_52 ) ;
V_34 += 2 ;
F_27 ( V_5 , V_3 , V_34 , V_67 ,
V_68 , V_11 , V_52 ) ;
V_34 += 2 ;
V_34 += 2 ;
V_6 = F_23 ( V_3 , V_34 ) ;
F_20 ( V_33 , V_69 ,
V_3 , V_34 , 4 , V_52 ) ;
V_34 += 4 ;
V_36 = F_23 ( V_3 , V_34 ) ;
F_20 ( V_33 , V_70 ,
V_3 , V_34 , 4 , V_52 ) ;
V_34 += 4 ;
V_37 = F_23 ( V_3 , V_34 ) ;
F_20 ( V_33 , V_71 ,
V_3 , V_34 , 4 , V_52 ) ;
V_34 += 4 ;
if ( V_37 > 0 && V_36 > ( T_4 ) V_34 ) {
V_39 = F_28 ( V_3 , V_36 ) ;
}
if ( V_37 <= ( T_4 ) V_39 ) {
V_40 = F_29 ( V_3 , V_36 ,
V_37 ) ;
}
if ( V_40 != NULL ) {
F_5 ( V_40 , V_4 ,
V_27 , V_6 ) ;
}
break;
}
return;
}
static enum V_28
F_30 ( T_1 * V_3 , T_2 * V_4 V_72 )
{
T_5 V_73 = FALSE ;
T_5 V_74 = FALSE ;
T_10 V_39 = F_17 ( V_3 ) ;
if ( V_39 < 20 ) {
return V_47 ;
}
if ( V_39 == 32 &&
F_31 ( V_3 , 0 ) == 0x0100 &&
F_31 ( V_3 , 2 ) == 0x0100 &&
F_31 ( V_3 , 4 ) == 0x0100 &&
F_31 ( V_3 , 6 ) == 0x0000 )
{
return V_58 ;
}
if ( F_31 ( V_3 , 0 ) == 0x0100 &&
F_31 ( V_3 , 2 ) == 0x0100 &&
F_31 ( V_3 , 4 ) == 0x0000 )
{
V_73 = TRUE ;
}
if ( F_31 ( V_3 , 0 ) <= 255 &&
F_31 ( V_3 , 2 ) <= 255 &&
F_31 ( V_3 , 4 ) <= 1 &&
F_31 ( V_3 , 6 ) == 0 )
{
V_74 = TRUE ;
}
if ( V_39 == 20 ) {
if ( F_23 ( V_3 , 8 ) != 0 ) {
V_74 = FALSE ;
}
if ( F_23 ( V_3 , 12 ) != 0 ) {
V_74 = FALSE ;
}
if ( F_23 ( V_3 , 16 ) != 0 ) {
V_74 = FALSE ;
}
if ( V_73 && ! V_74 ) {
return V_48 ;
}
if ( V_74 ) {
return V_65 ;
}
}
if ( V_39 <= 24 ) {
return V_47 ;
}
if ( F_23 ( V_3 , 12 ) != 24 ) {
return V_47 ;
}
if ( F_23 ( V_3 , 16 ) == 0 ) {
return V_47 ;
}
if ( F_23 ( V_3 , 20 ) != 0 ) {
return V_47 ;
}
if ( V_74 ) {
return V_65 ;
}
return V_47 ;
}
static T_5
F_32 ( T_1 * V_3 , T_2 * V_4 ,
T_3 * V_27 , void * V_75 )
{
struct V_76 * V_77 = (struct V_76 * ) V_75 ;
enum V_28 V_29 ;
if ( V_77 == NULL ) {
return FALSE ;
}
switch ( V_77 -> V_78 ) {
case V_79 :
case V_80 :
case V_81 :
case V_82 :
break;
default:
return FALSE ;
}
V_29 = F_30 ( V_3 , V_4 ) ;
if ( V_29 == V_47 ) {
return FALSE ;
}
F_16 ( V_3 , V_4 , V_27 , V_29 ) ;
return TRUE ;
}
static T_5
F_33 ( T_1 * V_3 , T_2 * V_4 ,
T_3 * V_27 , void * V_75 )
{
struct V_83 * V_77 = (struct V_83 * ) V_75 ;
enum V_28 V_29 ;
if ( V_77 == NULL ) {
return FALSE ;
}
switch ( V_77 -> V_84 ) {
case V_85 :
case V_86 :
case V_87 :
case V_88 :
case V_89 :
case V_90 :
case V_91 :
case V_92 :
break;
default:
return FALSE ;
}
V_29 = F_30 ( V_3 , V_4 ) ;
if ( V_29 == V_47 ) {
return FALSE ;
}
F_16 ( V_3 , V_4 , V_27 , V_29 ) ;
return TRUE ;
}
void F_34 ( void )
{
static T_11 * V_93 [] = {
& V_46 ,
& V_50 ,
& V_68 ,
& V_94 ,
& V_95 ,
} ;
static T_12 V_96 [] = {
{ & V_49 ,
{ L_3 , L_8 ,
V_97 , V_98 , NULL , 0x0 , NULL , V_99 } } ,
{ & V_60 ,
{ L_4 , L_9 ,
V_97 , V_98 , NULL , 0x0 , NULL , V_99 } } ,
{ & V_66 ,
{ L_7 , L_10 ,
V_97 , V_98 , NULL , 0x0 , NULL , V_99 } } ,
{ & V_51 ,
{ L_11 , L_12 ,
V_100 , V_101 , NULL , 0 , NULL , V_99 } } ,
{ & V_53 ,
{ L_13 , L_14 ,
V_100 , V_101 , NULL , 0 , NULL , V_99 } } ,
{ & V_61 ,
{ L_15 , L_16 ,
V_100 , V_101 , NULL , 0 , NULL , V_99 } } ,
{ & V_54 ,
{ L_17 , L_18 ,
V_100 , V_102 , NULL , 0 , NULL , V_99 } } ,
{ & V_62 ,
{ L_19 , L_20 ,
V_100 , V_102 , NULL , 0 , NULL , V_99 } } ,
{ & V_63 ,
{ L_21 , L_22 ,
V_103 , V_101 , F_35 ( V_59 ) , 0 ,
L_23 , V_99 } } ,
{ & V_64 ,
{ L_24 , L_25 ,
V_103 , V_102 , NULL , 0 , NULL , V_99 } } ,
{ & V_55 ,
{ L_26 , L_27 ,
V_103 , V_102 , NULL , 0 , NULL , V_99 } } ,
{ & V_56 ,
{ L_28 , L_29 ,
V_103 , V_102 , NULL , 0 , NULL , V_99 } } ,
{ & V_57 ,
{ L_30 , L_31 ,
V_103 , V_102 , NULL , 0 , NULL , V_99 } } ,
{ & V_67 ,
{ L_32 , L_33 ,
V_100 , V_101 , NULL , 0 , NULL , V_99 } } ,
{ & V_41 ,
{ L_34 , L_35 ,
V_104 , 16 , NULL , V_105 ,
NULL , V_99 } } ,
{ & V_69 ,
{ L_36 , L_37 ,
V_103 , V_102 , NULL , 0 , NULL , V_99 } } ,
{ & V_70 ,
{ L_38 , L_39 ,
V_103 , V_102 , NULL , 0 , NULL , V_99 } } ,
{ & V_71 ,
{ L_40 , L_41 ,
V_103 , V_102 , NULL , 0 , NULL , V_99 } } ,
{ & V_106 ,
{ L_42 , L_43 ,
V_97 , V_98 , NULL , 0 , NULL , V_99 } } ,
{ & V_107 ,
{ L_44 , L_45 ,
V_108 , V_98 , NULL , 0 , NULL , V_99 } } ,
{ & V_109 ,
{ L_46 , L_47 ,
V_104 , V_98 , NULL , 0 , NULL , V_99 } } ,
{ & V_110 ,
{ L_48 , L_49 ,
V_104 , V_98 , NULL , 0 , NULL , V_99 } } ,
{ & V_111 ,
{ L_50 , L_51 ,
V_104 , V_98 , NULL , 0 , NULL , V_99 } } ,
{ & V_112 ,
{ L_52 , L_53 ,
V_104 , V_98 , NULL , 0 , NULL , V_99 } } ,
{ & V_113 ,
{ L_54 , L_55 ,
V_108 , V_98 , NULL , 0 , NULL , V_99 } } ,
{ & V_114 ,
{ L_56 , L_57 ,
V_103 , V_102 , NULL , 0x0 , NULL , V_99 } } ,
{ & V_115 ,
{ L_58 , L_59 ,
V_108 , V_98 , NULL , 0 , NULL , V_99 } } ,
{ & V_116 ,
{ L_60 , L_61 ,
V_103 , V_102 , NULL , 0 , NULL , V_99 } } ,
{ & V_117 ,
{ L_62 , L_63 ,
V_118 , V_98 , NULL , 0 , NULL , V_99 } } ,
} ;
T_13 * V_119 ;
V_21 = F_36 ( L_64 ,
L_2 , L_65 ) ;
F_37 ( V_93 , F_38 ( V_93 ) ) ;
F_39 ( V_21 , V_96 , F_38 ( V_96 ) ) ;
V_25 = F_40 ( L_65 ) ;
V_119 = F_41 ( V_21 , NULL ) ;
F_42 ( V_119 ,
L_66 ,
L_67 ,
L_68 ,
& V_19 ) ;
F_43 ( F_1 ) ;
F_44 ( F_3 ) ;
}
void
F_45 ( void )
{
V_26 = F_46 ( L_69 ) ;
F_47 ( L_70 ,
F_32 ,
L_71 , L_72 ,
V_21 , V_120 ) ;
F_47 ( L_73 ,
F_33 ,
L_74 , L_75 ,
V_21 , V_120 ) ;
}
