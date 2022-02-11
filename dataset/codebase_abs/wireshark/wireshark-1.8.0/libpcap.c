int F_1 ( T_1 * V_1 , int * V_2 , T_2 * * V_3 )
{
int V_4 ;
T_3 V_5 ;
struct V_6 V_7 ;
T_4 V_8 ;
T_4 V_9 ;
T_4 V_10 ;
int V_11 ;
T_5 V_12 ;
T_6 * V_13 ;
V_14 = V_15 ;
V_4 = F_2 ( & V_5 , sizeof V_5 , V_1 -> V_16 ) ;
if ( V_4 != sizeof V_5 ) {
* V_2 = F_3 ( V_1 -> V_16 , V_3 ) ;
if ( * V_2 != 0 )
return - 1 ;
return 0 ;
}
switch ( V_5 ) {
case V_17 :
V_8 = FALSE ;
V_9 = FALSE ;
V_1 -> V_18 = V_19 ;
break;
case V_20 :
V_8 = FALSE ;
V_9 = TRUE ;
V_1 -> V_18 = V_19 ;
break;
case V_21 :
V_8 = TRUE ;
V_9 = FALSE ;
V_1 -> V_18 = V_19 ;
break;
case V_22 :
V_8 = TRUE ;
V_9 = TRUE ;
V_1 -> V_18 = V_19 ;
break;
case V_23 :
V_8 = FALSE ;
V_9 = FALSE ;
V_1 -> V_18 = V_24 ;
break;
case V_25 :
V_8 = TRUE ;
V_9 = FALSE ;
V_1 -> V_18 = V_24 ;
break;
default:
return 0 ;
}
V_14 = V_15 ;
V_4 = F_2 ( & V_7 , sizeof V_7 , V_1 -> V_16 ) ;
if ( V_4 != sizeof V_7 ) {
* V_2 = F_3 ( V_1 -> V_16 , V_3 ) ;
if ( * V_2 != 0 )
return - 1 ;
return 0 ;
}
if ( V_8 ) {
V_7 . V_26 = F_4 ( V_7 . V_26 ) ;
V_7 . V_27 = F_4 ( V_7 . V_27 ) ;
V_7 . V_28 = F_5 ( V_7 . V_28 ) ;
V_7 . V_29 = F_5 ( V_7 . V_29 ) ;
}
if ( V_7 . V_26 < 2 ) {
* V_2 = V_30 ;
* V_3 = F_6 ( L_1 ,
V_7 . V_26 ) ;
return - 1 ;
}
V_10 = FALSE ;
if ( V_7 . V_26 == 2 && V_7 . V_27 == 2 ) {
switch ( V_7 . V_29 ) {
case 6 :
V_7 . V_29 = 1 ;
V_10 = TRUE ;
break;
case 9 :
V_7 . V_29 = 6 ;
V_10 = TRUE ;
break;
case 15 :
V_7 . V_29 = 10 ;
V_10 = TRUE ;
break;
case 24 :
V_7 . V_29 = 0 ;
V_10 = TRUE ;
break;
}
}
V_11 = F_7 ( V_7 . V_29 ) ;
if ( V_11 == V_31 ) {
* V_2 = V_32 ;
* V_3 = F_6 ( L_2 ,
V_7 . V_29 ) ;
return - 1 ;
}
V_13 = ( T_6 * ) F_8 ( sizeof( T_6 ) ) ;
V_13 -> V_8 = V_8 ;
V_13 -> V_26 = V_7 . V_26 ;
V_13 -> V_27 = V_7 . V_27 ;
V_1 -> V_33 = ( void * ) V_13 ;
V_1 -> V_34 = V_35 ;
V_1 -> V_36 = V_37 ;
V_1 -> V_11 = V_11 ;
V_1 -> V_38 = V_7 . V_28 ;
switch ( V_7 . V_26 ) {
case 2 :
if ( V_7 . V_27 < 3 )
V_13 -> V_39 = V_40 ;
else if ( V_7 . V_27 == 3 )
V_13 -> V_39 = V_41 ;
else
V_13 -> V_39 = V_42 ;
break;
case 543 :
V_13 -> V_39 = V_40 ;
break;
default:
V_13 -> V_39 = V_42 ;
break;
}
if ( V_10 ) {
V_1 -> V_43 = V_44 ;
V_1 -> V_18 = V_24 ;
return 1 ;
}
if ( V_9 ) {
V_1 -> V_43 = V_45 ;
V_12 = F_9 ( V_1 -> V_16 ) ;
switch ( F_10 ( V_1 , V_2 ) ) {
case V_46 :
F_11 ( V_1 -> V_33 ) ;
return - 1 ;
case V_47 :
if ( F_12 ( V_1 -> V_16 , V_12 , V_48 , V_2 ) == - 1 ) {
F_11 ( V_1 -> V_33 ) ;
return - 1 ;
}
goto V_49;
case V_50 :
break;
}
V_1 -> V_43 = V_51 ;
if ( F_12 ( V_1 -> V_16 , V_12 , V_48 , V_2 ) == - 1 ) {
F_11 ( V_1 -> V_33 ) ;
return - 1 ;
}
} else {
if( V_1 -> V_18 == V_24 ) {
V_1 -> V_43 = V_52 ;
} else {
V_1 -> V_43 = V_53 ;
}
V_12 = F_9 ( V_1 -> V_16 ) ;
switch ( F_10 ( V_1 , V_2 ) ) {
case V_46 :
F_11 ( V_1 -> V_33 ) ;
return - 1 ;
case V_47 :
if ( F_12 ( V_1 -> V_16 , V_12 , V_48 , V_2 ) == - 1 ) {
F_11 ( V_1 -> V_33 ) ;
return - 1 ;
}
goto V_49;
case V_50 :
break;
}
V_1 -> V_43 = V_54 ;
if ( F_12 ( V_1 -> V_16 , V_12 , V_48 , V_2 ) == - 1 ) {
F_11 ( V_1 -> V_33 ) ;
return - 1 ;
}
switch ( F_10 ( V_1 , V_2 ) ) {
case V_46 :
F_11 ( V_1 -> V_33 ) ;
return - 1 ;
case V_47 :
if ( F_12 ( V_1 -> V_16 , V_12 , V_48 , V_2 ) == - 1 ) {
F_11 ( V_1 -> V_33 ) ;
return - 1 ;
}
goto V_49;
case V_50 :
break;
}
V_1 -> V_43 = V_55 ;
if ( F_12 ( V_1 -> V_16 , V_12 , V_48 , V_2 ) == - 1 ) {
F_11 ( V_1 -> V_33 ) ;
return - 1 ;
}
}
V_49:
if ( V_1 -> V_43 == V_55 && V_7 . V_29 == 13 )
V_1 -> V_11 = V_56 ;
if ( V_1 -> V_11 == V_57 ) {
F_13 ( V_1 ) ;
}
return 1 ;
}
static T_7 F_10 ( T_1 * V_1 , int * V_2 )
{
struct V_58 V_59 , V_60 ;
if ( F_14 ( V_1 , V_2 , NULL , & V_59 ) == - 1 ) {
if ( * V_2 == 0 || * V_2 == V_61 ) {
return V_47 ;
}
if ( * V_2 == V_62 ) {
return V_47 ;
}
return V_46 ;
}
if ( F_12 ( V_1 -> V_16 , V_59 . V_7 . V_63 , V_64 , V_2 ) == - 1 )
return V_46 ;
if ( F_14 ( V_1 , V_2 , NULL , & V_60 ) == - 1 ) {
if ( * V_2 == 0 || * V_2 == V_61 ) {
return V_47 ;
}
if ( * V_2 == V_62 ) {
return V_50 ;
}
return V_46 ;
}
return V_47 ;
}
static T_4 V_35 ( T_1 * V_1 , int * V_2 , T_2 * * V_3 ,
T_5 * V_65 )
{
struct V_58 V_7 ;
T_8 V_66 ;
T_8 V_67 ;
int V_4 ;
T_9 V_68 [ 3 ] ;
int V_69 ;
T_6 * V_13 ;
V_4 = F_14 ( V_1 , V_2 , V_3 , & V_7 ) ;
if ( V_4 == - 1 ) {
return FALSE ;
}
V_66 = V_7 . V_7 . V_63 ;
V_67 = V_7 . V_7 . V_70 ;
if ( V_1 -> V_43 == V_44 &&
( V_1 -> V_11 == V_71 ||
V_1 -> V_11 == V_72 ) ) {
V_66 -= 3 ;
V_67 -= 3 ;
if ( ! F_15 ( V_1 -> V_16 , V_68 , 3 , V_2 ,
V_3 ) )
return FALSE ;
}
* V_65 = F_9 ( V_1 -> V_16 ) ;
V_13 = ( T_6 * ) V_1 -> V_33 ;
V_69 = F_16 ( V_1 -> V_16 , V_1 -> V_43 ,
V_1 -> V_11 , V_66 , TRUE , & V_1 -> V_73 ,
& V_1 -> V_74 , V_2 , V_3 ) ;
if ( V_69 < 0 )
return FALSE ;
V_67 -= V_69 ;
V_66 -= V_69 ;
F_17 ( V_1 -> V_75 , V_66 ) ;
if ( ! F_15 ( V_1 -> V_16 , F_18 ( V_1 -> V_75 ) ,
V_66 , V_2 , V_3 ) )
return FALSE ;
V_1 -> V_73 . V_76 = V_77 | V_78 ;
if ( V_1 -> V_11 != V_57 ) {
V_1 -> V_73 . V_79 . V_80 = V_7 . V_7 . V_81 ;
if( V_1 -> V_18 == V_24 ) {
V_1 -> V_73 . V_79 . V_82 = V_7 . V_7 . V_83 ;
} else {
V_1 -> V_73 . V_79 . V_82 = V_7 . V_7 . V_83 * 1000 ;
}
} else {
V_1 -> V_73 . V_76 |= V_84 ;
V_1 -> V_73 . V_85 = V_1 -> V_74 . erf . V_73 . V_86 & 0x03 ;
}
V_1 -> V_73 . V_87 = V_66 ;
V_1 -> V_73 . V_88 = V_67 ;
F_19 ( V_1 -> V_43 , V_1 -> V_11 ,
& V_1 -> V_74 , F_18 ( V_1 -> V_75 ) ,
V_1 -> V_73 . V_87 , V_13 -> V_8 , - 1 ) ;
return TRUE ;
}
static T_4
V_37 ( T_1 * V_1 , T_5 V_89 ,
union V_90 * V_74 , T_9 * V_91 , int V_92 ,
int * V_2 , T_2 * * V_3 )
{
int V_69 ;
T_6 * V_13 ;
if ( F_12 ( V_1 -> V_93 , V_89 , V_48 , V_2 ) == - 1 )
return FALSE ;
V_13 = ( T_6 * ) V_1 -> V_33 ;
V_69 = F_16 ( V_1 -> V_93 , V_1 -> V_43 ,
V_1 -> V_11 , V_92 , FALSE , NULL , V_74 , V_2 , V_3 ) ;
if ( V_69 < 0 )
return FALSE ;
if ( ! F_15 ( V_1 -> V_93 , V_91 , V_92 , V_2 , V_3 ) )
return FALSE ;
F_19 ( V_1 -> V_43 , V_1 -> V_11 ,
V_74 , V_91 , V_92 , V_13 -> V_8 , - 1 ) ;
return TRUE ;
}
static int F_14 ( T_1 * V_1 , int * V_2 , T_2 * * V_3 ,
struct V_58 * V_7 )
{
int V_94 , V_4 ;
V_14 = V_15 ;
switch ( V_1 -> V_43 ) {
case V_53 :
case V_44 :
case V_52 :
V_94 = sizeof ( struct V_95 ) ;
break;
case V_54 :
case V_45 :
V_94 = sizeof ( struct V_96 ) ;
break;
case V_51 :
V_94 = sizeof ( struct V_58 ) ;
break;
case V_55 :
V_94 = sizeof ( struct V_97 ) ;
break;
default:
F_20 () ;
V_94 = 0 ;
}
V_4 = F_2 ( V_7 , V_94 , V_1 -> V_16 ) ;
if ( V_4 != V_94 ) {
* V_2 = F_3 ( V_1 -> V_16 , V_3 ) ;
if ( * V_2 == 0 && V_4 != 0 ) {
* V_2 = V_61 ;
}
return - 1 ;
}
F_21 ( V_1 , & V_7 -> V_7 ) ;
if ( V_7 -> V_7 . V_63 > V_98 ) {
* V_2 = V_62 ;
if ( V_3 != NULL ) {
* V_3 = F_6 ( L_3 ,
V_7 -> V_7 . V_63 , V_98 ) ;
}
return - 1 ;
}
if ( V_7 -> V_7 . V_70 > V_98 ) {
* V_2 = V_62 ;
if ( V_3 != NULL ) {
* V_3 = F_6 ( L_3 ,
V_7 -> V_7 . V_70 , V_98 ) ;
}
return - 1 ;
}
return V_4 ;
}
static void
F_21 ( T_1 * V_1 , struct V_95 * V_7 )
{
T_3 V_99 ;
T_6 * V_13 ;
V_13 = ( T_6 * ) V_1 -> V_33 ;
if ( V_13 -> V_8 ) {
V_7 -> V_81 = F_5 ( V_7 -> V_81 ) ;
V_7 -> V_83 = F_5 ( V_7 -> V_83 ) ;
V_7 -> V_63 = F_5 ( V_7 -> V_63 ) ;
V_7 -> V_70 = F_5 ( V_7 -> V_70 ) ;
}
switch ( V_13 -> V_39 ) {
case V_42 :
break;
case V_41 :
if ( V_7 -> V_63 <= V_7 -> V_70 ) {
break;
}
case V_40 :
V_99 = V_7 -> V_70 ;
V_7 -> V_70 = V_7 -> V_63 ;
V_7 -> V_63 = V_99 ;
break;
}
}
static T_4
F_15 ( T_10 V_16 , T_9 * V_91 , int V_92 , int * V_2 ,
T_2 * * V_3 )
{
int V_4 ;
V_14 = V_15 ;
V_4 = F_2 ( V_91 , V_92 , V_16 ) ;
if ( V_4 != V_92 ) {
* V_2 = F_3 ( V_16 , V_3 ) ;
if ( * V_2 == 0 )
* V_2 = V_61 ;
return FALSE ;
}
return TRUE ;
}
int F_22 ( int V_100 )
{
if ( V_100 == V_101 )
return V_102 ;
if ( F_23 ( V_100 ) == - 1 )
return V_32 ;
return 0 ;
}
T_4 F_24 ( T_11 * V_103 , int * V_2 )
{
T_3 V_5 ;
struct V_6 V_104 ;
V_103 -> V_105 = V_106 ;
V_103 -> V_107 = NULL ;
switch ( V_103 -> V_43 ) {
case V_53 :
case V_54 :
case V_55 :
V_5 = V_17 ;
V_103 -> V_18 = V_19 ;
break;
case V_51 :
case V_45 :
V_5 = V_20 ;
V_103 -> V_18 = V_19 ;
break;
case V_52 :
V_5 = V_23 ;
V_103 -> V_18 = V_24 ;
break;
default:
* V_2 = V_108 ;
return FALSE ;
}
if ( ! F_25 ( V_103 , & V_5 , sizeof V_5 , V_2 ) )
return FALSE ;
V_103 -> V_109 += sizeof V_5 ;
V_104 . V_26 = 2 ;
V_104 . V_27 = 4 ;
V_104 . V_110 = 0 ;
V_104 . V_111 = 0 ;
V_104 . V_28 = ( V_103 -> V_28 != 0 ) ? V_103 -> V_28 :
V_98 ;
V_104 . V_29 = F_23 ( V_103 -> V_100 ) ;
if ( ! F_25 ( V_103 , & V_104 , sizeof V_104 , V_2 ) )
return FALSE ;
V_103 -> V_109 += sizeof V_104 ;
return TRUE ;
}
static T_4 V_106 ( T_11 * V_103 ,
const struct V_112 * V_73 ,
const union V_90 * V_74 ,
const T_9 * V_91 , int * V_2 )
{
struct V_58 V_113 ;
T_12 V_114 ;
int V_115 ;
V_115 = F_26 ( V_103 -> V_100 , V_74 ) ;
V_113 . V_7 . V_81 = ( T_3 ) V_73 -> V_79 . V_80 ;
if( V_103 -> V_18 == V_24 ) {
V_113 . V_7 . V_83 = V_73 -> V_79 . V_82 ;
} else {
V_113 . V_7 . V_83 = V_73 -> V_79 . V_82 / 1000 ;
}
V_113 . V_7 . V_63 = V_73 -> V_87 + V_115 ;
V_113 . V_7 . V_70 = V_73 -> V_88 + V_115 ;
if ( V_113 . V_7 . V_63 > V_98 || V_113 . V_7 . V_70 > V_98 ) {
* V_2 = V_62 ;
return FALSE ;
}
switch ( V_103 -> V_43 ) {
case V_53 :
case V_52 :
V_114 = sizeof ( struct V_95 ) ;
break;
case V_54 :
case V_45 :
V_113 . V_116 = 0 ;
V_113 . V_117 = 0 ;
V_113 . V_118 = 0 ;
V_114 = sizeof ( struct V_96 ) ;
break;
case V_51 :
V_113 . V_116 = 0 ;
V_113 . V_117 = 0 ;
V_113 . V_118 = 0 ;
V_113 . V_119 = 0 ;
V_113 . V_120 = 0 ;
V_114 = sizeof ( struct V_58 ) ;
break;
case V_55 :
V_113 . V_116 = 0 ;
V_113 . V_117 = 0 ;
V_113 . V_118 = 0 ;
V_113 . V_119 = 0 ;
V_113 . V_120 = 0 ;
V_114 = sizeof ( struct V_97 ) ;
break;
default:
F_20 () ;
* V_2 = V_108 ;
return FALSE ;
}
if ( ! F_25 ( V_103 , & V_113 , V_114 , V_2 ) )
return FALSE ;
V_103 -> V_109 += V_114 ;
if ( ! F_27 ( V_103 , V_103 -> V_100 , V_74 , V_2 ) )
return FALSE ;
if ( ! F_25 ( V_103 , V_91 , V_73 -> V_87 , V_2 ) )
return FALSE ;
V_103 -> V_109 += V_73 -> V_87 ;
return TRUE ;
}
