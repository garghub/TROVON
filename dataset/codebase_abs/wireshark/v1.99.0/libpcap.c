int F_1 ( T_1 * V_1 , int * V_2 , T_2 * * V_3 )
{
T_3 V_4 ;
struct V_5 V_6 ;
T_4 V_7 ;
T_4 V_8 ;
T_4 V_9 ;
int V_10 ;
T_5 V_11 ;
T_6 * V_12 ;
static const int V_13 [] = {
V_14 ,
V_15
} ;
#define F_2 G_N_ELEMENTS(subtypes_modified)
static const int V_16 [] = {
V_17 ,
V_18 ,
V_19
} ;
#define F_3 G_N_ELEMENTS(subtypes_standard)
static const int V_20 [] = {
V_21
} ;
#define F_4 G_N_ELEMENTS(subtypes_nsec)
#define F_5 \
MAX(MAX(N_SUBTYPES_MODIFIED, N_SUBTYPES_STANDARD), N_SUBTYPES_NSEC)
int V_22 [ F_5 ] ;
const int * V_23 ;
int V_24 ;
int V_25 ;
int V_26 ;
V_27 = V_28 ;
if ( ! F_6 ( V_1 -> V_29 , & V_4 , sizeof V_4 , V_2 , V_3 ) ) {
if ( * V_2 != V_30 )
return - 1 ;
return 0 ;
}
switch ( V_4 ) {
case V_31 :
V_7 = FALSE ;
V_8 = FALSE ;
V_1 -> V_32 = V_33 ;
break;
case V_34 :
V_7 = FALSE ;
V_8 = TRUE ;
V_1 -> V_32 = V_33 ;
break;
case V_35 :
V_7 = TRUE ;
V_8 = FALSE ;
V_1 -> V_32 = V_33 ;
break;
case V_36 :
V_7 = TRUE ;
V_8 = TRUE ;
V_1 -> V_32 = V_33 ;
break;
case V_37 :
V_7 = FALSE ;
V_8 = FALSE ;
V_1 -> V_32 = V_38 ;
break;
case V_39 :
V_7 = TRUE ;
V_8 = FALSE ;
V_1 -> V_32 = V_38 ;
break;
default:
return 0 ;
}
V_27 = V_28 ;
if ( ! F_6 ( V_1 -> V_29 , & V_6 , sizeof V_6 , V_2 , V_3 ) )
return - 1 ;
if ( V_7 ) {
V_6 . V_40 = F_7 ( V_6 . V_40 ) ;
V_6 . V_41 = F_7 ( V_6 . V_41 ) ;
V_6 . V_42 = F_8 ( V_6 . V_42 ) ;
V_6 . V_43 = F_8 ( V_6 . V_43 ) ;
}
if ( V_6 . V_40 < 2 ) {
* V_2 = V_44 ;
* V_3 = F_9 ( L_1 ,
V_6 . V_40 ) ;
return - 1 ;
}
V_9 = FALSE ;
if ( V_6 . V_40 == 2 && V_6 . V_41 == 2 ) {
switch ( V_6 . V_43 ) {
case 6 :
V_6 . V_43 = 1 ;
V_9 = TRUE ;
break;
case 9 :
V_6 . V_43 = 6 ;
V_9 = TRUE ;
break;
case 15 :
V_6 . V_43 = 10 ;
V_9 = TRUE ;
break;
case 24 :
V_6 . V_43 = 0 ;
V_9 = TRUE ;
break;
}
}
V_10 = F_10 ( V_6 . V_43 ) ;
if ( V_10 == V_45 ) {
* V_2 = V_46 ;
* V_3 = F_9 ( L_2 ,
V_6 . V_43 ) ;
return - 1 ;
}
V_12 = ( T_6 * ) F_11 ( sizeof( T_6 ) ) ;
V_12 -> V_7 = V_7 ;
V_12 -> V_40 = V_6 . V_40 ;
V_12 -> V_41 = V_6 . V_41 ;
V_1 -> V_47 = ( void * ) V_12 ;
V_1 -> V_48 = V_49 ;
V_1 -> V_50 = V_51 ;
V_1 -> V_10 = V_10 ;
V_1 -> V_52 = V_6 . V_42 ;
switch ( V_6 . V_40 ) {
case 2 :
if ( V_6 . V_41 < 3 )
V_12 -> V_53 = V_54 ;
else if ( V_6 . V_41 == 3 )
V_12 -> V_53 = V_55 ;
else
V_12 -> V_53 = V_56 ;
break;
case 543 :
V_12 -> V_53 = V_54 ;
break;
default:
V_12 -> V_53 = V_56 ;
break;
}
if ( V_9 ) {
V_1 -> V_57 = V_58 ;
V_1 -> V_32 = V_38 ;
return 1 ;
}
if ( V_8 ) {
V_23 = V_13 ;
V_24 = F_2 ;
} else {
if ( V_1 -> V_32 == V_38 ) {
V_23 = V_20 ;
V_24 = F_4 ;
} else {
V_23 = V_16 ;
V_24 = F_3 ;
}
}
V_11 = F_12 ( V_1 -> V_29 ) ;
for ( V_26 = 0 ; V_26 < V_24 ; V_26 ++ ) {
V_1 -> V_57 = V_23 [ V_26 ] ;
V_22 [ V_26 ] = F_13 ( V_1 , V_2 , V_3 ) ;
if ( V_22 [ V_26 ] == - 1 ) {
return - 1 ;
}
if ( V_22 [ V_26 ] == 0 ) {
if ( F_14 ( V_1 -> V_29 , V_11 , V_59 , V_2 ) == - 1 ) {
return - 1 ;
}
goto V_60;
}
if ( F_14 ( V_1 -> V_29 , V_11 , V_59 , V_2 ) == - 1 ) {
return - 1 ;
}
}
V_25 = V_61 ;
for ( V_26 = 0 ; V_26 < V_24 ; V_26 ++ ) {
if ( V_22 [ V_26 ] < V_25 ) {
V_1 -> V_57 = V_23 [ V_26 ] ;
V_25 = V_22 [ V_26 ] ;
}
}
V_60:
if ( V_1 -> V_57 == V_19 &&
V_6 . V_43 == 13 )
V_1 -> V_10 = V_62 ;
if ( V_1 -> V_10 == V_63 ) {
F_15 ( V_1 ) ;
}
return 1 ;
}
static int F_13 ( T_1 * V_1 , int * V_2 , T_2 * * V_3 )
{
int V_64 ;
struct V_65 V_66 , V_67 ;
V_64 = F_16 ( V_1 , V_1 -> V_29 , V_2 , V_3 , & V_66 ) ;
if ( V_64 == - 1 ) {
if ( * V_2 == 0 || * V_2 == V_30 ) {
return 0 ;
}
return V_64 ;
}
if ( V_64 != 0 ) {
return V_64 ;
}
if ( F_14 ( V_1 -> V_29 , V_66 . V_6 . V_68 , V_69 , V_2 ) == - 1 )
return - 1 ;
V_64 = F_16 ( V_1 , V_1 -> V_29 , V_2 , V_3 , & V_67 ) ;
if ( V_64 == - 1 ) {
if ( * V_2 == 0 || * V_2 == V_30 ) {
return 0 ;
}
return V_64 ;
}
return V_64 ;
}
static int F_16 ( T_1 * V_1 , T_7 V_29 , int * V_2 , T_2 * * V_3 ,
struct V_65 * V_6 )
{
int V_64 ;
if ( ! F_17 ( V_1 , V_29 , V_2 , V_3 , V_6 ) )
return - 1 ;
V_64 = 0 ;
switch ( V_1 -> V_57 ) {
case V_21 :
case V_58 :
if ( V_6 -> V_6 . V_70 >= 1000000000 )
V_64 ++ ;
break;
default:
if ( V_6 -> V_6 . V_70 >= 1000000 )
V_64 ++ ;
break;
}
if ( V_6 -> V_6 . V_68 > V_71 ) {
V_64 ++ ;
}
if ( V_6 -> V_6 . V_72 > 64 * 1024 * 1024 ) {
V_64 ++ ;
}
if ( V_6 -> V_6 . V_68 > V_1 -> V_52 ) {
V_64 ++ ;
}
if ( V_6 -> V_6 . V_68 > V_6 -> V_6 . V_72 ) {
V_64 ++ ;
}
return V_64 ;
}
static T_4 V_49 ( T_1 * V_1 , int * V_2 , T_2 * * V_3 ,
T_5 * V_73 )
{
* V_73 = F_12 ( V_1 -> V_29 ) ;
return F_18 ( V_1 , V_1 -> V_29 , & V_1 -> V_74 ,
V_1 -> V_75 , V_2 , V_3 ) ;
}
static T_4
V_51 ( T_1 * V_1 , T_5 V_76 , struct V_77 * V_74 ,
T_8 * V_78 , int * V_2 , T_2 * * V_3 )
{
if ( F_14 ( V_1 -> V_79 , V_76 , V_59 , V_2 ) == - 1 )
return FALSE ;
if ( ! F_18 ( V_1 , V_1 -> V_79 , V_74 , V_78 , V_2 ,
V_3 ) ) {
if ( * V_2 == 0 )
* V_2 = V_30 ;
return FALSE ;
}
return TRUE ;
}
static T_4
F_18 ( T_1 * V_1 , T_7 V_29 , struct V_77 * V_74 ,
T_8 * V_78 , int * V_2 , T_2 * * V_3 )
{
struct V_65 V_6 ;
T_9 V_80 ;
T_9 V_81 ;
int V_82 ;
T_6 * V_12 ;
if ( ! F_17 ( V_1 , V_29 , V_2 , V_3 , & V_6 ) )
return FALSE ;
if ( V_6 . V_6 . V_68 > V_71 ) {
* V_2 = V_83 ;
if ( V_3 != NULL ) {
* V_3 = F_9 ( L_3 ,
V_6 . V_6 . V_68 , V_71 ) ;
}
return FALSE ;
}
V_80 = V_6 . V_6 . V_68 ;
V_81 = V_6 . V_6 . V_72 ;
if ( V_1 -> V_57 == V_58 &&
( V_1 -> V_10 == V_84 ||
V_1 -> V_10 == V_85 ) ) {
V_80 -= 3 ;
V_81 -= 3 ;
if ( ! F_19 ( V_29 , 3 , V_2 ) )
return FALSE ;
}
V_82 = F_20 ( V_29 , V_1 -> V_57 ,
V_1 -> V_10 , V_80 , TRUE , V_74 , V_2 , V_3 ) ;
if ( V_82 < 0 )
return FALSE ;
V_81 -= V_82 ;
V_80 -= V_82 ;
V_74 -> V_86 = V_87 ;
V_74 -> V_88 = V_89 | V_90 ;
if ( V_1 -> V_10 != V_63 ) {
V_74 -> V_91 . V_92 = V_6 . V_6 . V_93 ;
if ( V_1 -> V_32 == V_38 )
V_74 -> V_91 . V_94 = V_6 . V_6 . V_70 ;
else
V_74 -> V_91 . V_94 = V_6 . V_6 . V_70 * 1000 ;
} else {
V_74 -> V_88 |= V_95 ;
V_74 -> V_96 = V_74 -> V_97 . erf . V_74 . V_98 & 0x03 ;
}
V_74 -> V_99 = V_80 ;
V_74 -> V_100 = V_81 ;
if ( ! F_21 ( V_29 , V_78 , V_80 , V_2 , V_3 ) )
return FALSE ;
V_12 = ( T_6 * ) V_1 -> V_47 ;
F_22 ( V_1 -> V_57 , V_1 -> V_10 ,
V_74 , F_23 ( V_78 ) , V_12 -> V_7 , - 1 ) ;
return TRUE ;
}
static int F_17 ( T_1 * V_1 , T_7 V_29 , int * V_2 , T_2 * * V_3 ,
struct V_65 * V_6 )
{
int V_101 ;
T_3 V_102 ;
T_6 * V_12 ;
V_27 = V_28 ;
switch ( V_1 -> V_57 ) {
case V_17 :
case V_58 :
case V_21 :
V_101 = sizeof ( struct V_103 ) ;
break;
case V_18 :
case V_14 :
V_101 = sizeof ( struct V_104 ) ;
break;
case V_15 :
V_101 = sizeof ( struct V_65 ) ;
break;
case V_19 :
V_101 = sizeof ( struct V_105 ) ;
break;
default:
F_24 () ;
V_101 = 0 ;
}
if ( ! F_25 ( V_29 , V_6 , V_101 , V_2 , V_3 ) )
return FALSE ;
V_12 = ( T_6 * ) V_1 -> V_47 ;
if ( V_12 -> V_7 ) {
V_6 -> V_6 . V_93 = F_8 ( V_6 -> V_6 . V_93 ) ;
V_6 -> V_6 . V_70 = F_8 ( V_6 -> V_6 . V_70 ) ;
V_6 -> V_6 . V_68 = F_8 ( V_6 -> V_6 . V_68 ) ;
V_6 -> V_6 . V_72 = F_8 ( V_6 -> V_6 . V_72 ) ;
}
switch ( V_12 -> V_53 ) {
case V_56 :
break;
case V_55 :
if ( V_6 -> V_6 . V_68 <= V_6 -> V_6 . V_72 ) {
break;
}
case V_54 :
V_102 = V_6 -> V_6 . V_72 ;
V_6 -> V_6 . V_72 = V_6 -> V_6 . V_68 ;
V_6 -> V_6 . V_68 = V_102 ;
break;
}
return TRUE ;
}
int F_26 ( int V_106 )
{
if ( V_106 == V_107 )
return V_108 ;
if ( F_27 ( V_106 ) == - 1 )
return V_46 ;
return 0 ;
}
T_4 F_28 ( T_10 * V_109 , int * V_2 )
{
T_3 V_4 ;
struct V_5 V_110 ;
V_109 -> V_111 = V_112 ;
V_109 -> V_113 = NULL ;
switch ( V_109 -> V_57 ) {
case V_17 :
case V_18 :
case V_19 :
V_4 = V_31 ;
V_109 -> V_114 = V_33 ;
break;
case V_15 :
case V_14 :
V_4 = V_34 ;
V_109 -> V_114 = V_33 ;
break;
case V_21 :
V_4 = V_37 ;
V_109 -> V_114 = V_38 ;
break;
default:
* V_2 = V_115 ;
return FALSE ;
}
if ( ! F_29 ( V_109 , & V_4 , sizeof V_4 , V_2 ) )
return FALSE ;
V_109 -> V_116 += sizeof V_4 ;
V_110 . V_40 = 2 ;
V_110 . V_41 = 4 ;
V_110 . V_117 = 0 ;
V_110 . V_118 = 0 ;
V_110 . V_42 = ( V_109 -> V_42 != 0 ) ? V_109 -> V_42 :
V_71 ;
V_110 . V_43 = F_27 ( V_109 -> V_106 ) ;
if ( ! F_29 ( V_109 , & V_110 , sizeof V_110 , V_2 ) )
return FALSE ;
V_109 -> V_116 += sizeof V_110 ;
return TRUE ;
}
static T_4 V_112 ( T_10 * V_109 ,
const struct V_77 * V_74 ,
const T_11 * V_119 , int * V_2 )
{
const union V_120 * V_97 = & V_74 -> V_97 ;
struct V_65 V_121 ;
T_12 V_122 ;
int V_123 ;
V_123 = F_30 ( V_109 -> V_106 , V_97 ) ;
if ( V_74 -> V_86 != V_87 ) {
* V_2 = V_124 ;
return FALSE ;
}
if ( V_74 -> V_99 + V_123 > V_71 ) {
* V_2 = V_125 ;
return FALSE ;
}
V_121 . V_6 . V_93 = ( T_3 ) V_74 -> V_91 . V_92 ;
if( V_109 -> V_114 == V_38 ) {
V_121 . V_6 . V_70 = V_74 -> V_91 . V_94 ;
} else {
V_121 . V_6 . V_70 = V_74 -> V_91 . V_94 / 1000 ;
}
V_121 . V_6 . V_68 = V_74 -> V_99 + V_123 ;
V_121 . V_6 . V_72 = V_74 -> V_100 + V_123 ;
if ( V_121 . V_6 . V_68 > V_71 ) {
* V_2 = V_83 ;
return FALSE ;
}
switch ( V_109 -> V_57 ) {
case V_17 :
case V_21 :
V_122 = sizeof ( struct V_103 ) ;
break;
case V_18 :
case V_14 :
V_121 . V_126 = 0 ;
V_121 . V_127 = 0 ;
V_121 . V_128 = 0 ;
V_122 = sizeof ( struct V_104 ) ;
break;
case V_15 :
V_121 . V_126 = 0 ;
V_121 . V_127 = 0 ;
V_121 . V_128 = 0 ;
V_121 . V_129 = 0 ;
V_121 . V_130 = 0 ;
V_122 = sizeof ( struct V_65 ) ;
break;
case V_19 :
memcpy ( & V_121 . V_126 , V_97 -> V_131 . V_132 , 4 ) ;
V_121 . V_127 = 0 ;
V_121 . V_128 = 0 ;
V_121 . V_129 = 0 ;
V_121 . V_130 = 0 ;
V_122 = sizeof ( struct V_105 ) ;
break;
default:
F_24 () ;
* V_2 = V_115 ;
return FALSE ;
}
if ( ! F_29 ( V_109 , & V_121 , V_122 , V_2 ) )
return FALSE ;
V_109 -> V_116 += V_122 ;
if ( ! F_31 ( V_109 , V_109 -> V_106 , V_97 , V_2 ) )
return FALSE ;
if ( ! F_29 ( V_109 , V_119 , V_74 -> V_99 , V_2 ) )
return FALSE ;
V_109 -> V_116 += V_74 -> V_99 ;
return TRUE ;
}
