T_1 F_1 ( T_2 * V_1 , int * V_2 , T_3 * * V_3 )
{
T_4 V_4 ;
struct V_5 V_6 ;
T_5 V_7 ;
T_5 V_8 ;
T_5 V_9 ;
int V_10 ;
T_6 V_11 ;
T_7 * V_12 ;
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
if ( ! F_6 ( V_1 -> V_27 , & V_4 , sizeof V_4 , V_2 , V_3 ) ) {
if ( * V_2 != V_28 )
return V_29 ;
return V_30 ;
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
return V_30 ;
}
if ( ! F_6 ( V_1 -> V_27 , & V_6 , sizeof V_6 , V_2 , V_3 ) )
return V_29 ;
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
return V_29 ;
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
* V_2 = V_44 ;
* V_3 = F_9 ( L_2 ,
V_6 . V_43 ) ;
return V_29 ;
}
V_12 = ( T_7 * ) F_11 ( sizeof( T_7 ) ) ;
V_12 -> V_7 = V_7 ;
V_12 -> V_40 = V_6 . V_40 ;
V_12 -> V_41 = V_6 . V_41 ;
V_12 -> V_46 = NULL ;
V_1 -> V_47 = ( void * ) V_12 ;
V_1 -> V_48 = V_49 ;
V_1 -> V_50 = V_51 ;
V_1 -> V_52 = V_53 ;
V_1 -> V_10 = V_10 ;
V_1 -> V_54 = V_6 . V_42 ;
switch ( V_6 . V_40 ) {
case 2 :
if ( V_6 . V_41 < 3 )
V_12 -> V_55 = V_56 ;
else if ( V_6 . V_41 == 3 )
V_12 -> V_55 = V_57 ;
else
V_12 -> V_55 = V_58 ;
break;
case 543 :
V_12 -> V_55 = V_56 ;
break;
default:
V_12 -> V_55 = V_58 ;
break;
}
if ( V_9 ) {
V_1 -> V_59 = V_60 ;
V_1 -> V_32 = V_38 ;
return V_61 ;
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
V_11 = F_12 ( V_1 -> V_27 ) ;
for ( V_26 = 0 ; V_26 < V_24 ; V_26 ++ ) {
V_1 -> V_59 = V_23 [ V_26 ] ;
V_22 [ V_26 ] = F_13 ( V_1 , V_2 , V_3 ) ;
if ( V_22 [ V_26 ] == - 1 ) {
return V_29 ;
}
if ( V_22 [ V_26 ] == 0 ) {
if ( F_14 ( V_1 -> V_27 , V_11 , V_62 , V_2 ) == - 1 ) {
return V_29 ;
}
goto V_63;
}
if ( F_14 ( V_1 -> V_27 , V_11 , V_62 , V_2 ) == - 1 ) {
return V_29 ;
}
}
V_25 = V_64 ;
for ( V_26 = 0 ; V_26 < V_24 ; V_26 ++ ) {
if ( V_22 [ V_26 ] < V_25 ) {
V_1 -> V_59 = V_23 [ V_26 ] ;
V_25 = V_22 [ V_26 ] ;
}
}
V_63:
if ( V_1 -> V_59 == V_19 &&
V_6 . V_43 == 13 )
V_1 -> V_10 = V_65 ;
if ( V_1 -> V_10 == V_66 ) {
V_12 -> V_46 = F_15 () ;
}
return V_61 ;
}
static int F_13 ( T_2 * V_1 , int * V_2 , T_3 * * V_3 )
{
int V_67 ;
struct V_68 V_69 , V_70 ;
V_67 = F_16 ( V_1 , V_1 -> V_27 , V_2 , V_3 , & V_69 ) ;
if ( V_67 == - 1 ) {
if ( * V_2 == 0 || * V_2 == V_28 ) {
return 0 ;
}
return V_67 ;
}
if ( V_67 != 0 ) {
return V_67 ;
}
if ( ! F_6 ( V_1 -> V_27 , NULL , V_69 . V_6 . V_71 , V_2 , V_3 ) )
return - 1 ;
V_67 = F_16 ( V_1 , V_1 -> V_27 , V_2 , V_3 , & V_70 ) ;
if ( V_67 == - 1 ) {
if ( * V_2 == 0 || * V_2 == V_28 ) {
return 0 ;
}
return V_67 ;
}
return V_67 ;
}
static int F_16 ( T_2 * V_1 , T_8 V_27 , int * V_2 , T_3 * * V_3 ,
struct V_68 * V_6 )
{
int V_67 ;
if ( ! F_17 ( V_1 , V_27 , V_2 , V_3 , V_6 ) )
return - 1 ;
V_67 = 0 ;
switch ( V_1 -> V_59 ) {
case V_21 :
case V_60 :
if ( V_6 -> V_6 . V_72 >= 1000000000 )
V_67 ++ ;
break;
default:
if ( V_6 -> V_6 . V_72 >= 1000000 )
V_67 ++ ;
break;
}
if ( V_6 -> V_6 . V_71 > F_18 ( V_1 -> V_10 ) ) {
V_67 ++ ;
}
if ( V_6 -> V_6 . V_73 > 128 * 1024 * 1024 ) {
V_67 ++ ;
}
if ( V_6 -> V_6 . V_71 > V_1 -> V_54 ) {
V_67 ++ ;
}
if ( V_6 -> V_6 . V_71 > V_6 -> V_6 . V_73 ) {
V_67 ++ ;
}
return V_67 ;
}
static T_5 V_49 ( T_2 * V_1 , int * V_2 , T_3 * * V_3 ,
T_6 * V_74 )
{
* V_74 = F_12 ( V_1 -> V_27 ) ;
return F_19 ( V_1 , V_1 -> V_27 , & V_1 -> V_75 ,
V_1 -> V_76 , V_2 , V_3 ) ;
}
static T_5
V_51 ( T_2 * V_1 , T_6 V_77 , struct V_78 * V_75 ,
T_9 * V_79 , int * V_2 , T_3 * * V_3 )
{
if ( F_14 ( V_1 -> V_80 , V_77 , V_62 , V_2 ) == - 1 )
return FALSE ;
if ( ! F_19 ( V_1 , V_1 -> V_80 , V_75 , V_79 , V_2 ,
V_3 ) ) {
if ( * V_2 == 0 )
* V_2 = V_28 ;
return FALSE ;
}
return TRUE ;
}
static T_5
F_19 ( T_2 * V_1 , T_8 V_27 , struct V_78 * V_75 ,
T_9 * V_79 , int * V_2 , T_3 * * V_3 )
{
struct V_68 V_6 ;
T_10 V_81 ;
T_10 V_82 ;
int V_83 ;
T_7 * V_12 ;
V_12 = ( T_7 * ) V_1 -> V_47 ;
if ( ! F_17 ( V_1 , V_27 , V_2 , V_3 , & V_6 ) )
return FALSE ;
if ( V_6 . V_6 . V_71 > F_18 ( V_1 -> V_10 ) ) {
* V_2 = V_84 ;
if ( V_3 != NULL ) {
* V_3 = F_9 ( L_3 ,
V_6 . V_6 . V_71 ,
F_18 ( V_1 -> V_10 ) ) ;
}
return FALSE ;
}
V_81 = V_6 . V_6 . V_71 ;
V_82 = V_6 . V_6 . V_73 ;
if ( V_1 -> V_59 == V_60 &&
( V_1 -> V_10 == V_85 ||
V_1 -> V_10 == V_86 ) ) {
V_81 -= 3 ;
V_82 -= 3 ;
if ( ! F_6 ( V_27 , NULL , 3 , V_2 , V_3 ) )
return FALSE ;
}
V_83 = F_20 ( V_27 , V_1 -> V_59 ,
V_1 -> V_10 , V_81 , TRUE , V_75 , V_2 , V_3 ) ;
if ( V_83 < 0 )
return FALSE ;
V_82 -= V_83 ;
V_81 -= V_83 ;
V_75 -> V_87 = V_88 ;
V_75 -> V_89 = V_90 | V_91 ;
if ( V_1 -> V_10 != V_66 ) {
V_75 -> V_92 . V_93 = V_6 . V_6 . V_94 ;
if ( V_1 -> V_32 == V_38 )
V_75 -> V_92 . V_95 = V_6 . V_6 . V_72 ;
else
V_75 -> V_92 . V_95 = V_6 . V_6 . V_72 * 1000 ;
} else {
int V_96 ;
V_75 -> V_89 |= V_97 ;
if ( ( V_96 = F_21 ( ( V_98 * ) V_12 -> V_46 , V_1 , & V_75 -> V_99 ) ) < 0 )
return FALSE ;
V_75 -> V_96 = ( T_10 ) V_96 ;
}
V_75 -> V_100 = V_81 ;
V_75 -> V_101 = V_82 ;
if ( ! F_22 ( V_27 , V_79 , V_81 , V_2 , V_3 ) )
return FALSE ;
F_23 ( V_1 -> V_59 , V_1 -> V_10 ,
V_75 , F_24 ( V_79 ) , V_12 -> V_7 , - 1 ) ;
return TRUE ;
}
static int F_17 ( T_2 * V_1 , T_8 V_27 , int * V_2 , T_3 * * V_3 ,
struct V_68 * V_6 )
{
int V_102 ;
T_4 V_103 ;
T_7 * V_12 ;
switch ( V_1 -> V_59 ) {
case V_17 :
case V_60 :
case V_21 :
V_102 = sizeof ( struct V_104 ) ;
break;
case V_18 :
case V_14 :
V_102 = sizeof ( struct V_105 ) ;
break;
case V_15 :
V_102 = sizeof ( struct V_68 ) ;
break;
case V_19 :
V_102 = sizeof ( struct V_106 ) ;
break;
default:
F_25 () ;
V_102 = 0 ;
}
if ( ! F_26 ( V_27 , V_6 , V_102 , V_2 , V_3 ) )
return FALSE ;
V_12 = ( T_7 * ) V_1 -> V_47 ;
if ( V_12 -> V_7 ) {
V_6 -> V_6 . V_94 = F_8 ( V_6 -> V_6 . V_94 ) ;
V_6 -> V_6 . V_72 = F_8 ( V_6 -> V_6 . V_72 ) ;
V_6 -> V_6 . V_71 = F_8 ( V_6 -> V_6 . V_71 ) ;
V_6 -> V_6 . V_73 = F_8 ( V_6 -> V_6 . V_73 ) ;
}
switch ( V_12 -> V_55 ) {
case V_58 :
break;
case V_57 :
if ( V_6 -> V_6 . V_71 <= V_6 -> V_6 . V_73 ) {
break;
}
case V_56 :
V_103 = V_6 -> V_6 . V_73 ;
V_6 -> V_6 . V_73 = V_6 -> V_6 . V_71 ;
V_6 -> V_6 . V_71 = V_103 ;
break;
}
return TRUE ;
}
int F_27 ( int V_107 )
{
if ( V_107 == V_108 )
return V_109 ;
if ( F_28 ( V_107 ) == - 1 )
return V_110 ;
return 0 ;
}
T_5 F_29 ( T_11 * V_111 , int * V_2 )
{
T_4 V_4 ;
struct V_5 V_112 ;
V_111 -> V_113 = V_114 ;
switch ( V_111 -> V_59 ) {
case V_17 :
case V_18 :
case V_19 :
V_4 = V_31 ;
break;
case V_15 :
case V_14 :
V_4 = V_34 ;
break;
case V_21 :
V_4 = V_37 ;
break;
default:
* V_2 = V_115 ;
return FALSE ;
}
if ( ! F_30 ( V_111 , & V_4 , sizeof V_4 , V_2 ) )
return FALSE ;
V_111 -> V_116 += sizeof V_4 ;
V_112 . V_40 = 2 ;
V_112 . V_41 = 4 ;
V_112 . V_117 = 0 ;
V_112 . V_118 = 0 ;
V_112 . V_42 = ( V_111 -> V_42 != 0 ) ? ( T_10 ) V_111 -> V_42 :
F_18 ( V_111 -> V_107 ) ;
V_112 . V_43 = F_28 ( V_111 -> V_107 ) ;
if ( ! F_30 ( V_111 , & V_112 , sizeof V_112 , V_2 ) )
return FALSE ;
V_111 -> V_116 += sizeof V_112 ;
return TRUE ;
}
static T_5 V_114 ( T_11 * V_111 ,
const struct V_78 * V_75 ,
const T_12 * V_119 , int * V_2 , T_3 * * V_3 V_120 )
{
const union V_121 * V_99 = & V_75 -> V_99 ;
struct V_68 V_122 ;
T_13 V_123 ;
int V_124 ;
V_124 = F_31 ( V_111 -> V_107 , V_99 ) ;
if ( V_75 -> V_87 != V_88 ) {
* V_2 = V_125 ;
return FALSE ;
}
if ( ( V_126 ) V_75 -> V_100 + V_124 > F_18 ( V_111 -> V_107 ) ) {
* V_2 = V_127 ;
return FALSE ;
}
V_122 . V_6 . V_71 = V_75 -> V_100 + V_124 ;
V_122 . V_6 . V_73 = V_75 -> V_101 + V_124 ;
switch ( V_111 -> V_59 ) {
case V_17 :
V_122 . V_6 . V_94 = ( T_4 ) V_75 -> V_92 . V_93 ;
V_122 . V_6 . V_72 = V_75 -> V_92 . V_95 / 1000 ;
V_123 = sizeof ( struct V_104 ) ;
break;
case V_21 :
V_122 . V_6 . V_94 = ( T_4 ) V_75 -> V_92 . V_93 ;
V_122 . V_6 . V_72 = V_75 -> V_92 . V_95 ;
V_123 = sizeof ( struct V_104 ) ;
break;
case V_18 :
case V_14 :
V_122 . V_6 . V_94 = ( T_4 ) V_75 -> V_92 . V_93 ;
V_122 . V_6 . V_72 = V_75 -> V_92 . V_95 / 1000 ;
V_122 . V_128 = 0 ;
V_122 . V_129 = 0 ;
V_122 . V_130 = 0 ;
V_123 = sizeof ( struct V_105 ) ;
break;
case V_15 :
V_122 . V_6 . V_94 = ( T_4 ) V_75 -> V_92 . V_93 ;
V_122 . V_6 . V_72 = V_75 -> V_92 . V_95 / 1000 ;
V_122 . V_128 = 0 ;
V_122 . V_129 = 0 ;
V_122 . V_130 = 0 ;
V_122 . V_131 = 0 ;
V_122 . V_132 = 0 ;
V_123 = sizeof ( struct V_68 ) ;
break;
case V_19 :
V_122 . V_6 . V_94 = ( T_4 ) V_75 -> V_92 . V_93 ;
V_122 . V_6 . V_72 = V_75 -> V_92 . V_95 / 1000 ;
memcpy ( & V_122 . V_128 , V_99 -> V_133 . V_134 , 4 ) ;
V_122 . V_129 = 0 ;
V_122 . V_130 = 0 ;
V_122 . V_131 = 0 ;
V_122 . V_132 = 0 ;
V_123 = sizeof ( struct V_106 ) ;
break;
default:
F_25 () ;
* V_2 = V_115 ;
return FALSE ;
}
if ( ! F_30 ( V_111 , & V_122 , V_123 , V_2 ) )
return FALSE ;
V_111 -> V_116 += V_123 ;
if ( ! F_32 ( V_111 , V_111 -> V_107 , V_99 , V_2 ) )
return FALSE ;
if ( ! F_30 ( V_111 , V_119 , V_75 -> V_100 , V_2 ) )
return FALSE ;
V_111 -> V_116 += V_75 -> V_100 ;
return TRUE ;
}
static void V_53 ( T_2 * V_1 )
{
T_7 * V_12 = ( T_7 * ) V_1 -> V_47 ;
if ( V_12 -> V_46 ) {
switch ( V_1 -> V_10 ) {
case V_66 :
F_33 ( ( V_98 * ) V_12 -> V_46 ) ;
break;
default:
F_34 ( V_12 -> V_46 ) ;
break;
}
}
}
