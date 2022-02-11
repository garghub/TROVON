static void
F_1 ( T_1 * V_1 , int V_2 , T_2 * V_3 )
{
char * V_4 , * V_5 ;
if ( ( ! V_3 ) || ( 0 == strlen ( V_3 ) ) ) {
F_2 ( V_6 , V_7 , L_1 ) ;
return;
}
F_3 ( V_1 ) ;
V_4 = F_4 ( F_5 ( V_1 ) , 0 , - 1 ) ;
switch ( V_2 & V_8 ) {
case V_9 :
V_5 = F_6 ( V_3 ) ;
break;
case V_10 :
if ( ( ! V_4 ) || ( 0 == strlen ( V_4 ) ) )
V_5 = F_6 ( V_3 ) ;
else
V_5 = F_7 ( L_2 , V_4 , L_3 , V_3 , L_4 , NULL ) ;
break;
case V_11 :
if ( ( ! V_4 ) || ( 0 == strlen ( V_4 ) ) )
V_5 = F_6 ( V_3 ) ;
else
V_5 = F_7 ( L_2 , V_4 , L_5 , V_3 , L_4 , NULL ) ;
break;
case V_12 :
V_5 = F_7 ( L_6 , V_3 , L_4 , NULL ) ;
break;
case V_13 :
if ( ( ! V_4 ) || ( 0 == strlen ( V_4 ) ) )
V_5 = F_7 ( L_6 , V_3 , L_4 , NULL ) ;
else
V_5 = F_7 ( L_2 , V_4 , L_7 , V_3 , L_4 , NULL ) ;
break;
case V_14 :
if ( ( ! V_4 ) || ( 0 == strlen ( V_4 ) ) )
V_5 = F_7 ( L_6 , V_3 , L_4 , NULL ) ;
else
V_5 = F_7 ( L_2 , V_4 , L_8 , V_3 , L_4 , NULL ) ;
break;
default:
F_8 () ;
V_5 = NULL ;
break;
}
F_9 ( V_4 ) ;
if ( V_2 & V_15 ) {
T_3 * V_16 = F_10 ( L_9 ) ;
F_11 ( V_16 , V_5 ) ;
F_12 ( V_16 ) ;
F_13 ( V_16 , TRUE ) ;
} else {
F_14 ( F_15 ( V_1 ) , V_5 ) ;
if ( V_2 & V_17 )
F_16 ( & V_18 , V_5 , FALSE ) ;
}
F_9 ( V_5 ) ;
}
void
F_17 ( T_4 V_19 , T_5 V_2 )
{
char * V_20 = NULL ;
if ( V_18 . V_21 ) {
V_20 = F_18 ( V_18 . V_21 ,
V_18 . V_22 ) ;
F_1 ( ( T_1 * ) F_19 ( F_20 ( V_19 ) , V_23 ) , V_2 , V_20 ) ;
F_21 ( NULL , V_20 ) ;
}
}
void
F_22 ( T_1 * T_6 V_24 , T_4 V_19 V_24 , T_7 V_25 )
{
char * V_20 = NULL ;
T_2 * V_26 = NULL ;
if ( V_18 . V_21 ) {
V_20 = F_18 ( V_18 . V_21 ,
V_18 . V_22 ) ;
if ( ( ! V_20 ) || ( 0 == strlen ( V_20 ) ) ) {
F_2 ( V_6 , V_7 ,
L_10
L_11 ) ;
return;
}
if ( V_25 == 0 ) {
F_23 ( V_20 ) ;
} else {
if ( V_25 == 255 ) {
if ( ! F_24 ( & V_26 ) ) {
F_2 ( V_6 , V_7 , L_12 , V_26 ) ;
F_9 ( V_26 ) ;
}
} else {
if ( ! F_25 ( V_25 , V_20 , FALSE , & V_26 ) ) {
F_2 ( V_6 , V_7 , L_12 , V_26 ) ;
F_9 ( V_26 ) ;
}
}
F_26 () ;
}
F_21 ( NULL , V_20 ) ;
}
}
static void F_27 ( T_4 T_8 V_24 , T_9 V_27 , T_4 V_19 )
{
T_2 * V_28 ;
T_2 * V_29 = ( T_2 * ) V_19 ;
switch( V_27 ) {
case ( V_7 ) :
if ( V_18 . V_21 ) {
V_28 = F_28 ( L_13 , V_29 ) ;
F_29 ( V_28 ) ;
F_9 ( V_28 ) ;
}
break;
case ( V_30 ) :
break;
default:
F_8 () ;
}
}
void
F_30 ( T_1 * T_10 V_24 , T_4 V_19 V_24 )
{
int V_31 ;
const T_2 * V_29 ;
T_4 T_8 ;
if ( V_18 . V_21 ) {
V_31 = V_18 . V_21 -> V_32 -> V_33 ;
if( ! F_31 ( V_31 ) ) {
V_31 = F_32 ( V_18 . V_21 -> V_32 -> V_33 ) ;
}
V_29 = F_33 ( V_31 ) ;
T_8 = F_2 ( V_34 , V_35 ,
L_14
L_15
L_16
L_15
L_17
L_18
L_15
L_19
L_20
L_15
L_21
L_22
L_15
L_23
L_15
L_24
L_25 ,
F_34 () , V_29 , F_35 () , V_29 ) ;
F_36 ( T_8 , F_27 , ( T_4 ) V_29 ) ;
}
}
static void F_37 ( T_4 T_8 V_24 , T_9 V_27 , T_4 V_19 )
{
T_2 * V_28 ;
T_2 * V_29 = ( T_2 * ) V_19 ;
switch( V_27 ) {
case ( V_7 ) :
if ( V_18 . V_21 ) {
V_28 = F_28 ( L_26 , V_29 [ 0 ] , V_29 ) ;
F_29 ( V_28 ) ;
F_9 ( V_28 ) ;
}
break;
case ( V_30 ) :
break;
default:
F_8 () ;
}
}
void
F_38 ( T_1 * T_10 V_24 , T_4 V_19 V_24 )
{
int V_31 ;
const T_2 * V_29 ;
T_4 T_8 ;
if ( V_18 . V_21 ) {
V_31 = V_18 . V_21 -> V_32 -> V_33 ;
if( ! F_31 ( V_31 ) ) {
V_31 = F_32 ( V_18 . V_21 -> V_32 -> V_33 ) ;
}
V_29 = F_33 ( V_31 ) ;
T_8 = F_2 ( V_34 , V_35 ,
L_27
L_15
L_28
L_15 ,
F_34 () , V_29 , F_35 () , V_29 ) ;
F_36 ( T_8 , F_37 , ( T_4 ) V_29 ) ;
}
}
static T_11
F_39 ( T_9 V_36 )
{
if ( ( ( V_18 . V_37 . V_38 [ V_36 ] . V_39 == V_40 ) ||
( V_18 . V_37 . V_38 [ V_36 ] . V_39 == V_41 ) ||
( V_18 . V_37 . V_38 [ V_36 ] . V_39 == V_42 ) ||
( V_18 . V_37 . V_38 [ V_36 ] . V_39 == V_43 ) ) &&
strlen ( V_18 . V_37 . V_44 . V_45 [ V_36 ] ) )
{
return TRUE ;
}
return FALSE ;
}
T_12 *
F_40 ( T_4 V_19 )
{
T_9 V_46 = F_41 ( F_19 ( F_20 ( V_19 ) , V_47 ) ) ;
T_9 V_36 = F_42 ( F_41 ( F_19 ( F_20 ( V_19 ) , V_48 ) ) ) ;
T_9 V_49 ;
T_13 * V_50 ;
T_12 * V_51 = NULL ;
V_50 = ( T_13 * ) F_43 ( V_46 ) ;
if ( V_50 != NULL ) {
T_14 V_22 ;
if ( ! F_44 ( & V_18 , V_50 ) )
return NULL ;
F_45 ( & V_22 , V_18 . V_52 , FALSE , FALSE ) ;
F_46 ( & V_22 , & V_18 . V_37 ) ;
F_47 ( & V_22 , V_18 . V_53 , & V_18 . V_54 ,
F_48 ( V_50 , & V_18 . V_55 ) , V_50 , & V_18 . V_37 ) ;
F_49 ( & V_22 , TRUE , TRUE ) ;
if ( F_39 ( V_36 ) ) {
V_51 = F_50 ( V_51 , F_6 ( V_18 . V_37 . V_44 . V_45 [ V_36 ] ) ) ;
}
for ( V_49 = 0 ; V_49 < V_18 . V_37 . V_56 ; V_49 ++ ) {
if ( ( V_49 != V_36 ) && ( F_39 ( V_49 ) ) ) {
V_51 = F_50 ( V_51 , F_6 ( V_18 . V_37 . V_44 . V_45 [ V_49 ] ) ) ;
}
}
F_51 ( & V_22 ) ;
}
return V_51 ;
}
static T_2 *
F_52 ( T_4 V_19 )
{
T_9 V_46 = F_41 ( F_19 ( F_20 ( V_19 ) , V_47 ) ) ;
T_9 V_36 = F_42 ( F_41 ( F_19 ( F_20 ( V_19 ) , V_48 ) ) ) ;
T_13 * V_50 ;
T_2 * V_55 = NULL ;
V_50 = ( T_13 * ) F_43 ( V_46 ) ;
if ( V_50 != NULL ) {
T_14 V_22 ;
if ( ! F_44 ( & V_18 , V_50 ) )
return NULL ;
F_45 ( & V_22 , V_18 . V_52 , F_53 ( & V_18 . V_37 ) , FALSE ) ;
F_46 ( & V_22 , & V_18 . V_37 ) ;
F_47 ( & V_22 , V_18 . V_53 , & V_18 . V_54 ,
F_48 ( V_50 , & V_18 . V_55 ) ,
V_50 , & V_18 . V_37 ) ;
F_49 ( & V_22 , TRUE , TRUE ) ;
if ( ( V_18 . V_37 . V_38 [ V_36 ] . V_57 ) ||
( strchr ( V_18 . V_37 . V_44 . V_45 [ V_36 ] , ',' ) == NULL ) )
{
if ( strlen ( V_18 . V_37 . V_44 . V_44 [ V_36 ] ) != 0 &&
strlen ( V_18 . V_37 . V_44 . V_45 [ V_36 ] ) != 0 ) {
if ( V_18 . V_37 . V_38 [ V_36 ] . V_39 == V_58 ) {
T_15 * V_59 = F_54 ( V_18 . V_37 . V_38 [ V_36 ] . V_60 ) ;
if ( V_59 && V_59 -> V_61 == - 1 ) {
V_55 = F_6 ( V_18 . V_37 . V_44 . V_44 [ V_36 ] ) ;
} else if ( V_59 && F_55 ( V_59 -> type ) ) {
V_55 = F_28 ( L_29 , V_18 . V_37 . V_44 . V_44 [ V_36 ] ,
V_18 . V_37 . V_44 . V_45 [ V_36 ] ) ;
}
}
if ( V_55 == NULL ) {
V_55 = F_28 ( L_30 , V_18 . V_37 . V_44 . V_44 [ V_36 ] ,
V_18 . V_37 . V_44 . V_45 [ V_36 ] ) ;
}
}
}
F_51 ( & V_22 ) ;
}
return V_55 ;
}
void
F_56 ( T_4 V_19 , T_5 V_2 )
{
char * V_20 ;
V_20 = F_52 ( ( T_1 * ) V_19 ) ;
F_1 ( ( T_1 * ) F_19 ( F_20 ( V_19 ) , V_23 ) ,
V_2 , V_20 ) ;
F_9 ( V_20 ) ;
}
void
F_57 ( T_1 * T_6 V_24 , T_4 V_19 V_24 , T_16 V_2 )
{
T_3 * V_16 = F_10 ( L_9 ) ;
char V_62 [ V_63 ] ;
char * V_64 = V_62 ;
switch( V_2 )
{
case V_65 :
if ( V_18 . V_21 -> V_66 &&
strlen ( V_18 . V_21 -> V_66 -> V_67 ) > 0 ) {
F_11 ( V_16 , V_18 . V_21 -> V_66 -> V_67 ) ;
}
break;
case V_68 :
if ( V_18 . V_21 -> V_32 -> V_69 != 0 ) {
F_11 ( V_16 , V_18 . V_21 -> V_32 -> V_69 ) ;
}
break;
case V_70 :
if ( V_18 . V_22 != 0 ) {
T_2 * V_71 = F_58 ( V_18 . V_21 , V_18 . V_22 ) ;
F_11 ( V_16 , V_71 ) ;
F_9 ( V_71 ) ;
}
break;
default:
break;
}
if ( V_16 -> V_72 == 0 ) {
F_59 ( V_18 . V_21 , V_64 ) ;
F_11 ( V_16 , V_64 ) ;
}
if ( V_16 -> V_72 == 0 ) {
F_2 ( V_6 , V_7 , L_31 ) ;
} else {
F_12 ( V_16 ) ;
}
F_13 ( V_16 , TRUE ) ;
}
void
F_60 ( T_11 V_73 , T_13 * V_74 , T_9 V_46 ) {
if ( V_46 == - 1 )
return;
if ( V_73 ) {
V_74 -> V_75 . V_76 = 1 ;
V_18 . V_77 ++ ;
} else {
V_74 -> V_75 . V_76 = 0 ;
V_18 . V_77 -- ;
}
F_61 ( & V_18 ) ;
if ( ! V_74 -> V_75 . V_76 && ! V_74 -> V_75 . V_78 ) {
F_62 () ;
V_18 . V_79 -- ;
F_63 () ;
F_64 () ;
}
F_65 () ;
}
static void F_66 ( T_4 T_8 V_24 , T_9 V_27 , T_4 V_19 V_24 )
{
switch( V_27 ) {
case ( V_80 ) :
F_67 ( V_81 ) ;
V_82 . V_83 = V_81 ;
F_68 ( & V_18 ) ;
F_65 () ;
break;
case ( V_84 ) :
break;
default:
F_8 () ;
}
if ( V_18 . V_85 ) {
F_60 ( ! V_18 . V_85 -> V_75 . V_76 ,
V_18 . V_85 , V_18 . V_86 ) ;
}
}
void
F_69 ( T_1 * T_6 V_24 , T_4 V_19 V_24 , T_17 V_2 )
{
static T_1 * V_87 = NULL ;
switch( V_2 ) {
case V_88 :
if ( V_18 . V_85 ) {
if( V_82 . V_83 != V_81 && V_18 . V_85 -> V_75 . V_76 == 0 ) {
V_87 = ( T_1 * ) F_2 ( V_34 , V_89 ,
L_32
L_33
L_34 ,
F_34 () , F_35 () ) ;
F_36 ( V_87 , F_66 , NULL ) ;
} else {
F_60 ( ! V_18 . V_85 -> V_75 . V_76 ,
V_18 . V_85 , V_18 . V_86 ) ;
}
}
break;
case V_90 :
F_70 ( & V_18 , V_91 ) ;
break;
case V_92 :
F_70 ( & V_18 , V_93 ) ;
break;
}
}
void
F_71 ( T_1 * T_6 V_24 , T_4 V_19 V_24 , int V_2 V_24 )
{
F_72 ( & V_18 , V_91 ) ;
}
void
F_73 ( T_1 * T_6 V_24 , T_4 V_19 V_24 , int V_2 V_24 )
{
F_72 ( & V_18 , V_93 ) ;
}
static void
F_74 ( T_18 * V_94 , T_4 T_19 V_24 )
{
T_20 * V_95 ;
T_2 V_96 [ 2 + 10 + 1 + 5 + 1 ] ;
T_11 V_97 = FALSE ;
T_21 V_98 = 0 , V_99 ;
T_1 * V_100 ;
const T_7 * V_101 ;
T_9 V_102 ;
T_22 * V_103 ;
T_23 V_104 ;
if ( ! F_75 ( V_94 , & V_103 , & V_104 ) )
{
V_100 = F_76 ( V_105 ) ;
if ( V_100 == NULL )
return;
V_101 = F_77 ( V_100 , & V_99 ) ;
if ( V_101 == NULL )
return;
F_78 ( & V_18 ) ;
F_79 ( V_100 , V_101 ,
V_18 . V_85 , NULL , V_99 ) ;
F_80 ( V_94 , & V_18 ) ;
return;
}
F_81 ( V_103 , & V_104 , 1 , & V_95 , - 1 ) ;
if ( ! V_95 ) return;
F_82 ( V_105 , V_95 -> V_106 ) ;
V_100 = F_76 ( V_105 ) ;
V_101 = F_77 ( V_100 , & V_99 ) ;
F_3 ( V_101 != NULL ) ;
V_18 . V_21 = V_95 ;
F_83 ( & V_18 ) ;
if ( V_95 -> V_32 ) {
if ( V_95 -> V_32 -> V_107 != NULL &&
V_95 -> V_32 -> V_107 [ 0 ] != '\0' ) {
V_97 = TRUE ;
V_98 = ( T_21 ) strlen ( V_95 -> V_32 -> V_107 ) ;
} else {
V_98 = ( T_21 ) strlen ( V_95 -> V_32 -> V_108 ) ;
}
V_102 = V_95 -> V_98 + V_95 -> V_109 ;
if ( V_102 == 0 ) {
V_96 [ 0 ] = '\0' ;
} else if ( V_102 == 1 ) {
F_84 ( V_96 , L_35 , sizeof V_96 ) ;
} else {
F_85 ( V_96 , sizeof V_96 , L_36 , V_102 ) ;
}
F_86 () ;
if ( V_98 ) {
F_87 ( L_37 ,
( V_97 ) ? V_95 -> V_32 -> V_107 : V_95 -> V_32 -> V_108 ,
V_95 -> V_32 -> V_69 , V_96 ) ;
} else {
F_87 ( L_12 , L_9 ) ;
}
}
F_79 ( V_100 , V_101 , V_18 . V_85 , V_95 ,
V_99 ) ;
F_80 ( V_94 , & V_18 ) ;
}
void F_88 ( T_1 * T_10 V_24 , T_4 V_19 V_24 )
{
if ( V_18 . V_22 -> V_110 )
F_89 ( V_18 . V_22 -> V_110 , V_111 ) ;
}
void F_90 ( T_1 * T_10 V_24 , T_4 V_19 V_24 )
{
if ( V_18 . V_22 -> V_110 )
F_91 ( V_18 . V_22 -> V_110 , V_111 ) ;
}
void F_92 ( T_1 * T_10 V_24 , T_4 V_19 V_24 )
{
if ( V_18 . V_21 ) {
F_93 ( V_58 , V_18 . V_21 -> V_32 -> V_108 ,
V_18 . V_21 -> V_32 -> V_69 , 0 ) ;
F_94 () ;
if ( ! V_112 . V_113 ) {
F_95 () ;
}
V_18 . V_114 = FALSE ;
}
}
void F_96 ( T_1 * T_10 V_24 , T_4 V_19 V_24 )
{
T_24 * V_115 ;
V_115 = F_97 ( F_98 ( V_111 ) , V_18 . V_21 ) ;
if( V_115 ) {
F_99 ( F_98 ( V_111 ) , V_115 , TRUE ) ;
F_100 ( V_115 ) ;
}
}
void F_101 ( T_1 * T_10 V_24 , T_4 V_19 V_24 )
{
T_24 * V_115 ;
V_115 = F_97 ( F_98 ( V_111 ) , V_18 . V_21 ) ;
if( V_115 ) {
F_102 ( F_98 ( V_111 ) , V_115 ) ;
F_100 ( V_115 ) ;
}
}
void F_103 ( T_1 * T_10 V_24 , T_4 V_19 V_24 )
{
static const T_25 V_116 = {
TRUE ,
TRUE ,
TRUE ,
TRUE ,
TRUE ,
FALSE ,
FALSE
} ;
if ( V_18 . V_22 -> V_110 ) {
F_104 ( V_18 . V_22 -> V_110 , V_111 , & V_116 ) ;
}
}
static void
F_105 ( T_11 V_117 )
{
F_106 ( V_117 ) ;
#ifdef F_107
F_108 ( V_117 ) ;
F_109 ( V_117 ) ;
#endif
}
static void
F_110 ( T_11 V_118 )
{
V_119 = V_118 ;
F_111 () ;
}
static void
F_112 ( T_11 V_120 )
{
F_113 ( V_120 ) ;
F_114 ( V_120 ) ;
}
void
F_115 ( T_11 V_121 , T_11 V_122 )
{
F_116 ( V_121 , V_122 ) ;
F_117 ( V_121 , V_122 ) ;
}
T_11
F_118 ( void )
{
F_119 ( V_123 ) ;
F_120 () ;
F_121 () ;
#ifdef F_107
F_122 ( & V_124 ) ;
#endif
if ( V_18 . V_125 == V_126 ) {
V_18 . V_125 = V_127 ;
return TRUE ;
} else {
F_123 ( & V_18 ) ;
F_124 () ;
return FALSE ;
}
}
static T_11
F_125 ( T_1 * T_10 V_24 , T_26 * T_27 V_24 , T_4 V_19 V_24 )
{
if ( V_128 )
return TRUE ;
if ( F_126 ( & V_18 , TRUE , L_38 ) )
return F_118 () ;
else
return TRUE ;
}
static void
F_127 ( void )
{
if ( V_82 . V_129 && V_82 . V_130 )
F_128 ( F_129 ( V_131 ) , V_82 . V_130 ) ;
if ( V_82 . V_132 && V_82 . V_133 ) {
F_128 ( F_129 ( V_134 ) , V_82 . V_133 ) ;
}
}
static void
F_130 ( T_1 * T_10 )
{
T_28 V_135 ;
V_135 . V_136 = V_112 . V_137 ;
V_135 . V_138 = V_82 . V_139 ;
V_135 . V_140 = V_82 . V_141 ;
V_135 . V_142 = V_112 . V_143 ;
if ( V_82 . V_144 > 0 &&
V_82 . V_145 > 0 ) {
V_135 . V_146 = V_82 . V_144 ;
V_135 . V_147 = V_82 . V_145 ;
V_135 . V_148 = V_112 . V_149 ;
} else {
V_135 . V_142 = FALSE ;
}
V_135 . V_150 = V_82 . V_151 ;
F_131 ( T_10 , & V_135 ) ;
F_127 () ;
F_132 () ;
}
static void
F_119 ( T_1 * T_10 )
{
T_28 V_135 ;
F_133 ( T_10 , & V_135 ) ;
if ( V_112 . V_137 ) {
V_82 . V_139 = V_135 . V_138 ;
V_82 . V_141 = V_135 . V_140 ;
}
if ( V_112 . V_143 ) {
V_82 . V_144 = V_135 . V_146 ;
V_82 . V_145 = V_135 . V_147 ;
}
if( V_112 . V_149 ) {
V_82 . V_151 = V_135 . V_150 ;
}
V_82 . V_130 = F_134 ( F_129 ( V_131 ) ) ;
V_82 . V_133 = F_134 ( F_129 ( V_134 ) ) ;
F_135 () ;
}
void
F_136 ( T_1 * T_10 V_24 , T_4 V_19 V_24 )
{
if ( F_126 ( & V_18 , TRUE , L_38 ) )
F_118 () ;
}
static void
F_137 ( T_11 V_152 ) {
T_29 * V_153 ;
#ifdef F_138
F_139 () ;
#endif
if ( V_152 ) {
V_153 = stdout ;
fprintf ( V_153 , L_39
L_40
L_41 ,
F_140 () ) ;
} else {
V_153 = V_154 ;
}
fprintf ( V_153 , L_15 ) ;
fprintf ( V_153 , L_42 ) ;
fprintf ( V_153 , L_15 ) ;
#ifdef F_107
fprintf ( V_153 , L_43 ) ;
fprintf ( V_153 , L_44 ) ;
fprintf ( V_153 , L_45 ) ;
fprintf ( V_153 , L_46 ) ;
fprintf ( V_153 , L_47 ) ;
fprintf ( V_153 , L_48 ) ;
fprintf ( V_153 , L_49 ) ;
fprintf ( V_153 , L_50 ) ;
#ifdef F_141
fprintf ( V_153 , L_51 ) ;
#endif
#ifdef F_142
fprintf ( V_153 , L_52 , V_155 ) ;
#endif
fprintf ( V_153 , L_53 ) ;
fprintf ( V_153 , L_54 ) ;
fprintf ( V_153 , L_55 ) ;
fprintf ( V_153 , L_15 ) ;
fprintf ( V_153 , L_56 ) ;
fprintf ( V_153 , L_57 ) ;
fprintf ( V_153 , L_58 ) ;
fprintf ( V_153 , L_59 ) ;
fprintf ( V_153 , L_60 ) ;
fprintf ( V_153 , L_61 ) ;
fprintf ( V_153 , L_62 ) ;
fprintf ( V_153 , L_63 ) ;
fprintf ( V_153 , L_64 ) ;
#endif
#ifdef F_143
fprintf ( V_153 , L_65 ) ;
fprintf ( V_153 , L_66 ) ;
#endif
fprintf ( V_153 , L_67 ) ;
fprintf ( V_153 , L_68 ) ;
fprintf ( V_153 , L_15 ) ;
fprintf ( V_153 , L_69 ) ;
fprintf ( V_153 , L_70 ) ;
fprintf ( V_153 , L_71 ) ;
fprintf ( V_153 , L_72 ) ;
fprintf ( V_153 , L_73 ) ;
fprintf ( V_153 , L_74 ) ;
fprintf ( V_153 , L_75 ) ;
fprintf ( V_153 , L_76 ) ;
fprintf ( V_153 , L_77 ) ;
fprintf ( V_153 , L_78 ) ;
fprintf ( V_153 , L_15 ) ;
fprintf ( V_153 , L_79 ) ;
fprintf ( V_153 , L_80 ) ;
fprintf ( V_153 , L_81 ) ;
fprintf ( V_153 , L_82 ) ;
fprintf ( V_153 , L_83 ) ;
fprintf ( V_153 , L_84 ) ;
fprintf ( V_153 , L_85 ) ;
fprintf ( V_153 , L_86 ) ;
fprintf ( V_153 , L_87 ) ;
fprintf ( V_153 , L_88 ) ;
fprintf ( V_153 , L_89 ) ;
fprintf ( V_153 , L_90 ) ;
fprintf ( V_153 , L_15 ) ;
fprintf ( V_153 , L_91 ) ;
fprintf ( V_153 , L_92 ) ;
fprintf ( V_153 , L_15 ) ;
fprintf ( V_153 , L_93 ) ;
fprintf ( V_153 , L_94 ) ;
fprintf ( V_153 , L_95 ) ;
fprintf ( V_153 , L_96 ) ;
fprintf ( V_153 , L_97 ) ;
fprintf ( V_153 , L_98 ) ;
fprintf ( V_153 , L_99 ) ;
#ifndef F_138
fprintf ( V_153 , L_100 ) ;
#endif
#ifdef F_138
F_144 () ;
#endif
}
static void
F_145 ( const char * V_156 , T_30 V_157 )
{
#ifdef F_138
F_139 () ;
#endif
fprintf ( V_154 , L_101 ) ;
vfprintf ( V_154 , V_156 , V_157 ) ;
fprintf ( V_154 , L_15 ) ;
}
static void
F_146 ( const char * V_156 , T_30 V_157 )
{
#ifdef F_138
F_139 () ;
#endif
vfprintf ( V_154 , V_156 , V_157 ) ;
fprintf ( V_154 , L_15 ) ;
}
static T_11
F_147 ( T_4 V_19 V_24 )
{
F_148 ( FALSE ) ;
return TRUE ;
}
static T_11
F_149 ( T_4 V_19 V_24 )
{
if ( F_150 () ) {
if ( F_151 ( V_158 ) )
F_152 ( F_151 ( V_158 ) , NULL , TRUE ) ;
if ( F_151 ( V_159 ) )
F_152 ( F_151 ( V_159 ) , NULL , TRUE ) ;
}
return TRUE ;
}
void
F_153 ( T_31 * V_160 )
{
F_154 ( V_160 ) ;
F_155 ( V_160 ) ;
F_156 ( V_160 ) ;
}
void
F_157 ( T_11 V_161 )
{
F_158 ( V_161 ) ;
F_159 ( V_161 ) ;
V_162 = V_161 ;
}
void
F_160 ( T_11 V_163 )
{
F_161 ( V_163 ) ;
F_162 ( V_163 ) ;
if( V_163 != V_82 . V_163 ) {
V_82 . V_163 = V_163 ;
F_163 ( V_163 ) ;
F_26 () ;
}
}
static void
F_164 ( T_4 T_8 , T_9 V_27 V_24 , T_4 V_19 V_24 )
{
V_82 . V_164 = ! F_165 ( T_8 ) ;
}
static void
F_166 ( T_4 T_8 , T_9 V_27 V_24 , T_4 V_19 V_24 )
{
V_82 . V_165 = ! F_165 ( T_8 ) ;
}
static void
F_167 ( T_31 * V_160 )
{
if( V_160 -> V_166 > 10000 ) {
V_167 = ( T_1 * ) F_2 ( V_168 , V_169 ,
L_102 ,
F_34 () ,
F_35 () ) ;
F_168 ( F_169 ( V_167 ) , V_170 ) ;
}
F_170 () ;
F_171 () ;
F_154 ( NULL ) ;
F_155 ( NULL ) ;
F_156 ( NULL ) ;
F_112 ( FALSE ) ;
F_172 ( V_160 ) ;
F_105 ( FALSE ) ;
F_109 ( FALSE ) ;
F_83 ( V_160 ) ;
F_110 ( FALSE ) ;
F_173 () ;
}
static void
F_174 ( T_31 * V_160 V_24 )
{
if( V_167 != NULL ) {
F_175 ( V_167 ) ;
V_167 = NULL ;
}
}
static void
F_176 ( T_31 * V_160 V_24 )
{
F_177 () ;
F_110 ( TRUE ) ;
}
static void
F_178 ( T_31 * V_160 )
{
T_2 * V_171 ;
if ( ! V_160 -> V_172 && V_160 -> V_173 ) {
F_179 ( V_160 -> V_173 ) ;
V_171 = F_6 ( V_160 -> V_173 ) ;
F_180 ( F_181 ( V_171 ) ) ;
F_9 ( V_171 ) ;
}
F_153 ( V_160 ) ;
F_112 ( TRUE ) ;
}
static void
F_182 ( T_31 * V_160 )
{
T_2 * V_171 ;
if ( ! V_160 -> V_172 && V_160 -> V_173 ) {
F_179 ( V_160 -> V_173 ) ;
V_171 = F_6 ( V_160 -> V_173 ) ;
F_180 ( F_181 ( V_171 ) ) ;
F_9 ( V_171 ) ;
}
F_153 ( V_160 ) ;
}
static void
F_183 ( T_32 * V_174 )
{
static T_12 * V_175 = NULL ;
F_184 ( ( T_31 * ) V_174 -> V_160 ) ;
if( V_175 == NULL ) {
#ifdef F_185
V_175 = F_186 ( L_103 ,
L_104 ,
L_105 ,
L_106 ) ;
#else
V_175 = F_186 ( V_176 ,
V_177 ,
V_178 ,
V_179 ) ;
#endif
}
F_187 ( F_169 ( V_123 ) , V_175 ) ;
F_105 ( TRUE ) ;
F_109 ( TRUE ) ;
F_110 ( FALSE ) ;
}
static void
F_188 ( T_32 * V_174 )
{
F_184 ( ( T_31 * ) V_174 -> V_160 ) ;
F_105 ( TRUE ) ;
F_109 ( TRUE ) ;
F_112 ( TRUE ) ;
F_110 ( TRUE ) ;
}
static void
F_189 ( T_32 * V_174 )
{
T_31 * V_160 = ( T_31 * ) V_174 -> V_160 ;
static T_12 * V_175 = NULL ;
V_128 = FALSE ;
if ( ! V_160 -> V_172 && V_160 -> V_173 ) {
F_179 ( V_160 -> V_173 ) ;
}
F_105 ( FALSE ) ;
F_109 ( FALSE ) ;
F_153 ( V_160 ) ;
F_110 ( TRUE ) ;
if( V_175 == NULL ) {
#ifdef F_185
V_175 = F_186 ( L_107 ,
L_108 ,
L_109 ,
L_110 ) ;
#else
V_175 = F_186 ( V_180 ,
V_181 ,
V_182 ,
V_183 ) ;
#endif
}
F_187 ( F_169 ( V_123 ) , V_175 ) ;
if( V_184 . V_185 ) {
F_118 () ;
}
}
static void
F_190 ( T_32 * V_174 V_24 )
{
F_110 ( FALSE ) ;
}
static void
F_191 ( T_32 * V_174 V_24 )
{
#if 0
capture_file *cf = (capture_file *)cap_session->cf;
#endif
static T_12 * V_175 = NULL ;
V_128 = FALSE ;
F_105 ( FALSE ) ;
F_109 ( FALSE ) ;
F_154 ( NULL ) ;
if( V_175 == NULL ) {
#ifdef F_185
V_175 = F_186 ( L_107 ,
L_108 ,
L_109 ,
L_110 ) ;
#else
V_175 = F_186 ( V_180 ,
V_181 ,
V_182 ,
V_183 ) ;
#endif
}
F_187 ( F_169 ( V_123 ) , V_175 ) ;
if( V_184 . V_185 ) {
F_118 () ;
}
}
static void
F_192 ( T_32 * V_174 V_24 )
{
V_128 = TRUE ;
F_193 () ;
#ifdef F_107
F_194 () ;
F_195 () ;
#endif
}
static void
F_196 ( T_32 * V_174 V_24 )
{
static T_12 * V_175 = NULL ;
V_128 = FALSE ;
F_154 ( NULL ) ;
F_105 ( FALSE ) ;
F_109 ( FALSE ) ;
F_110 ( FALSE ) ;
if( V_175 == NULL ) {
#ifdef F_185
V_175 = F_186 ( L_107 ,
L_108 ,
L_109 ,
L_110 ) ;
#else
V_175 = F_186 ( V_180 ,
V_181 ,
V_182 ,
V_183 ) ;
#endif
}
F_187 ( F_169 ( V_123 ) , V_175 ) ;
if( V_184 . V_185 ) {
F_118 () ;
}
}
static void
F_197 ( T_4 V_19 )
{
T_31 * V_160 = ( T_31 * ) V_19 ;
F_198 ( V_160 -> V_22 , V_111 , V_105 ) ;
F_199 ( V_160 -> V_22 -> V_110 , V_111 ) ;
if( V_160 -> V_186 &&
( V_160 -> V_187 != 0 || ( V_160 -> string && V_160 -> V_188 ) ) ) {
F_200 ( V_160 -> V_22 -> V_189 , V_160 -> V_187 ,
( V_190 * ) V_111 , V_160 -> V_22 -> V_110 ) ;
}
F_172 ( V_160 ) ;
}
static void
F_201 ( T_31 * V_160 )
{
while ( F_202 ( F_203 ( V_105 ) , 0 ) != NULL )
F_204 ( F_203 ( V_105 ) , 0 ) ;
F_205 ( V_105 , L_9 , NULL , NULL , V_111 ) ;
F_199 ( NULL , V_111 ) ;
F_172 ( V_160 ) ;
}
static void
F_206 ( T_31 * V_160 )
{
F_83 ( V_160 ) ;
}
static void
F_207 ( T_9 T_27 , T_4 V_19 , T_4 T_19 V_24 )
{
T_31 * V_160 = ( T_31 * ) V_19 ;
switch( T_27 ) {
case ( V_191 ) :
F_208 ( V_192 , V_193 , L_111 ) ;
F_209 ( V_160 ) ;
break;
case ( V_194 ) :
F_208 ( V_192 , V_193 , L_112 ) ;
F_167 ( V_160 ) ;
break;
case ( V_195 ) :
F_208 ( V_192 , V_193 , L_113 ) ;
F_174 ( V_160 ) ;
F_210 () ;
break;
case ( V_196 ) :
F_208 ( V_192 , V_193 , L_114 ) ;
F_176 ( V_160 ) ;
break;
case ( V_197 ) :
F_208 ( V_192 , V_193 , L_115 ) ;
F_178 ( V_160 ) ;
break;
case ( V_198 ) :
F_208 ( V_192 , V_193 , L_116 ) ;
F_176 ( V_160 ) ;
break;
case ( V_199 ) :
F_208 ( V_192 , V_193 , L_117 ) ;
F_178 ( V_160 ) ;
break;
case ( V_200 ) :
F_208 ( V_192 , V_193 , L_118 ) ;
break;
case ( V_201 ) :
F_208 ( V_192 , V_193 , L_119 ) ;
F_182 ( V_160 ) ;
break;
case ( V_202 ) :
F_208 ( V_192 , V_193 , L_120 ) ;
break;
case ( V_203 ) :
F_208 ( V_192 , V_193 , L_121 ) ;
break;
case ( V_204 ) :
F_208 ( V_192 , V_193 , L_122 ) ;
F_182 ( V_160 ) ;
break;
case ( V_205 ) :
F_197 ( V_160 ) ;
break;
case ( V_206 ) :
F_201 ( V_160 ) ;
break;
case ( V_207 ) :
F_206 ( V_160 ) ;
break;
case ( V_208 ) :
F_208 ( V_192 , V_193 , L_123 ) ;
break;
case ( V_209 ) :
F_208 ( V_192 , V_193 , L_124 ) ;
break;
case ( V_210 ) :
F_208 ( V_192 , V_193 , L_125 ) ;
break;
case ( V_211 ) :
F_208 ( V_192 , V_193 , L_126 ) ;
break;
case ( V_212 ) :
F_208 ( V_192 , V_193 , L_127 ) ;
break;
case ( V_213 ) :
F_208 ( V_192 , V_193 , L_128 ) ;
break;
case ( V_214 ) :
F_208 ( V_192 , V_193 , L_129 ) ;
break;
case ( V_215 ) :
F_208 ( V_192 , V_193 , L_130 ) ;
break;
default:
F_211 ( L_131 , T_27 ) ;
F_8 () ;
}
}
static void
F_212 ( T_9 T_27 , T_32 * V_174 , T_4 T_19 V_24 )
{
#ifdef F_213
T_33 * V_216 ;
#endif
switch( T_27 ) {
case ( V_217 ) :
F_208 ( V_192 , V_193 , L_132 ) ;
F_183 ( V_174 ) ;
break;
case ( V_218 ) :
F_208 ( V_192 , V_193 , L_133 ) ;
F_188 ( V_174 ) ;
#ifdef F_213
V_216 = ( T_33 * ) F_214 ( V_219 , NULL ) ;
#ifdef F_185
F_215 ( V_216 , F_216 ( L_109 ) ) ;
#else
F_215 ( V_216 , F_217 ( - 1 , V_182 , FALSE , NULL ) ) ;
#endif
#endif
break;
case ( V_220 ) :
break;
case ( V_221 ) :
F_208 ( V_192 , V_193 , L_134 ) ;
F_189 ( V_174 ) ;
break;
case ( V_222 ) :
F_208 ( V_192 , V_193 , L_135 ) ;
F_190 ( V_174 ) ;
break;
case ( V_223 ) :
F_208 ( V_192 , V_193 , L_136 ) ;
break;
case ( V_224 ) :
F_208 ( V_192 , V_193 , L_137 ) ;
F_191 ( V_174 ) ;
break;
case ( V_225 ) :
F_208 ( V_192 , V_193 , L_138 ) ;
#ifdef F_213
V_216 = ( T_33 * ) F_214 ( V_219 , NULL ) ;
#ifdef F_185
F_215 ( V_216 , F_216 ( L_110 ) ) ;
#else
F_215 ( V_216 , F_217 ( - 1 , V_183 , FALSE , NULL ) ) ;
#endif
#endif
F_192 ( V_174 ) ;
break;
case ( V_226 ) :
F_208 ( V_192 , V_193 , L_139 ) ;
F_196 ( V_174 ) ;
break;
default:
F_211 ( L_140 , T_27 ) ;
F_8 () ;
}
}
static void
F_218 ( T_3 * V_227 )
{
F_11 ( V_227 , L_141 ) ;
F_219 ( V_227 ,
#ifdef F_220
L_142 , F_220 , V_228 ,
V_229 ) ;
#else
L_143 ) ;
void
F_221 ( T_3 * V_227 )
{
F_222 ( V_227 ) ;
F_11 ( V_227 , L_144 ) ;
#ifdef F_223
#ifdef F_224
F_11 ( V_227 , L_145 ) ;
#else
F_11 ( V_227 , L_141 ) ;
F_11 ( V_227 , F_225 () ) ;
#endif
#else
F_11 ( V_227 , L_146 ) ;
#endif
F_11 ( V_227 , L_144 ) ;
#ifdef F_226
F_227 ( V_227 ) ;
#else
F_11 ( V_227 , L_147 ) ;
#endif
}
static void
F_228 ( T_3 * V_227 )
{
#ifdef F_107
F_11 ( V_227 , L_144 ) ;
F_229 ( V_227 ) ;
#endif
F_230 ( V_227 ) ;
#ifdef F_226
F_11 ( V_227 , L_144 ) ;
F_231 ( V_227 ) ;
#endif
}
static T_34 *
F_232 ( char * * V_230 , char * * V_231 )
{
int V_232 , V_233 ;
int V_234 , V_235 ;
int V_236 , V_237 ;
int V_238 , V_239 ;
char * V_240 , * V_241 ;
char * V_242 , * V_243 ;
int V_244 , V_245 ;
T_34 * V_246 ;
F_233 () ;
V_246 = F_234 ( & V_232 , & V_233 , & V_240 ,
& V_244 , & V_245 , & V_241 ) ;
if ( V_240 != NULL ) {
if ( V_232 != 0 ) {
F_2 ( V_247 , V_7 ,
L_148 ,
V_240 , F_235 ( V_232 ) ) ;
}
if ( V_233 != 0 ) {
F_2 ( V_247 , V_7 ,
L_149 ,
V_240 , F_235 ( V_233 ) ) ;
}
}
if ( V_241 != NULL ) {
if ( V_244 != 0 ) {
F_2 ( V_247 , V_7 ,
L_150 ,
V_241 , F_235 ( V_244 ) ) ;
}
if ( V_245 != 0 ) {
F_2 ( V_247 , V_7 ,
L_151 ,
V_241 , F_235 ( V_245 ) ) ;
}
F_9 ( V_241 ) ;
V_241 = NULL ;
}
#ifdef F_138
if ( V_246 -> V_248 == V_249 ) {
F_139 () ;
}
#endif
F_236 ( V_250 , & V_242 , & V_234 ) ;
if ( V_242 != NULL ) {
F_2 ( V_247 , V_7 ,
L_152 ,
V_242 , F_235 ( V_234 ) ) ;
F_9 ( V_242 ) ;
}
F_236 ( V_251 , & V_243 , & V_235 ) ;
if ( V_243 != NULL ) {
F_2 ( V_247 , V_7 ,
L_153 ,
V_243 , F_235 ( V_235 ) ) ;
F_9 ( V_243 ) ;
}
F_237 ( V_230 , & V_236 , & V_237 ,
V_231 , & V_238 , & V_239 ) ;
F_238 ( V_230 , & V_236 , & V_237 ,
V_231 , & V_238 , & V_239 ) ;
if ( * V_230 != NULL ) {
if ( V_236 != 0 ) {
F_2 ( V_247 , V_7 ,
L_154 ,
* V_230 , F_235 ( V_236 ) ) ;
}
if ( V_237 != 0 ) {
F_2 ( V_247 , V_7 ,
L_155 ,
* V_230 , F_235 ( V_237 ) ) ;
}
F_9 ( * V_230 ) ;
* V_230 = NULL ;
}
if ( * V_231 != NULL ) {
if ( V_238 != 0 ) {
F_2 ( V_247 , V_7 ,
L_156 ,
* V_231 , F_235 ( V_238 ) ) ;
}
if ( V_239 != 0 ) {
F_2 ( V_247 , V_7 ,
L_157 ,
* V_231 , F_235 ( V_239 ) ) ;
}
F_9 ( * V_231 ) ;
* V_231 = NULL ;
}
return V_246 ;
}
static void
#ifdef F_138
F_239 ( T_2 * V_252 )
#else
check_and_warn_user_startup( T_2 * V_252 V_24 )
#endif
{
T_2 * V_253 , * V_254 ;
T_4 V_255 ;
if ( F_240 () && V_82 . V_164 ) {
V_253 = F_241 () ;
V_254 = F_242 () ;
V_255 = F_2 ( V_247 , V_7 ,
L_158
L_159
L_160
L_161
L_162 , V_253 , V_254 ) ;
F_9 ( V_253 ) ;
F_9 ( V_254 ) ;
F_243 ( V_255 , L_163 ) ;
F_36 ( V_255 , F_164 , NULL ) ;
}
#ifdef F_138
if ( ! F_244 () && ! V_252 && ! F_245 () && V_82 . V_165 && F_246 () >= 6 ) {
V_255 = F_2 ( V_247 , V_7 ,
L_164
L_165 ) ;
F_243 ( V_255 , L_163 ) ;
F_36 ( V_255 , F_166 , NULL ) ;
}
#endif
}
int
main ( int V_256 , char * V_257 [] )
{
char * V_258 ;
char * V_259 ;
int V_260 ;
T_11 V_261 = FALSE ;
extern int V_262 ;
const T_2 * V_20 ;
#ifdef F_138
T_35 V_263 ;
#endif
char * V_264 ;
int V_265 ;
char * V_230 , * V_231 ;
int V_266 ;
#ifdef F_107
T_11 V_267 = FALSE ;
T_11 V_268 = FALSE ;
T_12 * V_269 ;
T_2 * V_270 ;
int V_271 ;
#else
T_11 V_272 = FALSE ;
#ifdef F_138
#ifdef F_226
T_2 * V_270 ;
#endif
#endif
#endif
T_9 V_273 = 280 , V_274 = 95 , V_275 = 75 ;
T_2 * V_276 , * V_252 = NULL , * V_277 = NULL , * V_278 = NULL , * V_279 = NULL ;
T_36 * V_280 = NULL ;
T_2 * V_26 = NULL ;
T_11 V_281 = FALSE ;
T_34 * V_246 ;
char V_282 ;
T_1 * V_283 = NULL ;
T_21 V_284 = 0 ;
T_37 V_285 = V_91 ;
T_36 * V_286 = NULL ;
unsigned int V_287 = V_288 ;
#ifdef F_213
T_33 * V_216 ;
#endif
T_38 * V_289 = NULL ;
T_38 * V_290 = NULL ;
T_38 * V_291 = NULL ;
#define F_247 OPTSTRING_CAPTURE_COMMON "C:g:Hh" "jJ:kK:lm:nN:o:P:r:R:St:u:vw:X:Y:z:"
static const struct V_292 V_293 [] = {
{ L_166 , V_294 , NULL , 'h' } ,
{ L_167 , V_295 , NULL , 'r' } ,
{ L_168 , V_295 , NULL , 'R' } ,
{ L_169 , V_295 , NULL , 'Y' } ,
{ L_170 , V_294 , NULL , 'v' } ,
V_296
{ 0 , 0 , 0 , 0 }
} ;
static const char V_297 [] = F_247 ;
#ifdef F_185
F_248 () ;
#endif
F_249 ( F_145 , F_146 ) ;
setlocale ( V_298 , L_9 ) ;
#ifdef F_138
F_250 ( V_256 , V_257 ) ;
F_251 () ;
#endif
F_252 () ;
F_253 () ;
V_258 = F_254 ( V_257 [ 0 ] , main ) ;
F_255 () ;
F_256 ( & V_299 ) ;
#ifdef F_138
F_257 () ;
F_258 () ;
#ifdef F_226
V_300 = F_259 () ;
switch ( V_300 ) {
case V_301 :
V_302 = F_260 ( & V_266 , & V_270 ) ;
if ( V_302 == NULL || F_261 ( V_302 ) == 0 ) {
if ( V_266 == V_303 && V_270 != NULL ) {
F_2 ( V_6 , V_7 , L_12 , L_171 ) ;
F_9 ( V_270 ) ;
}
V_304 = NULL ;
} else {
V_304 = F_262 ( V_302 ) ;
}
break;
#if 0
case AIRPCAP_DLL_OLD:
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK, "%s","AIRPCAP_DLL_OLD\n");
break;
case AIRPCAP_DLL_ERROR:
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK, "%s","AIRPCAP_DLL_ERROR\n");
break;
case AIRPCAP_DLL_NOT_FOUND:
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK, "%s","AIRPCAP_DDL_NOT_FOUND\n");
break;
#endif
}
#endif
#endif
V_305 = F_263 ( F_218 ,
F_221 ) ;
V_306 = F_264 ( F_228 ) ;
F_265 ( L_39
L_15
L_12
L_15
L_12 ,
F_140 () , V_305 -> V_227 , V_306 -> V_227 ) ;
#ifdef F_138
F_266 ( F_267 ( 1 , 1 ) , & V_263 ) ;
#endif
F_268 ( TRUE ) ;
F_269 ( & V_264 , & V_265 ) ;
if ( V_264 != NULL && V_265 != 0 ) {
F_2 ( V_247 , V_7 ,
L_172 ,
V_264 , F_235 ( V_265 ) ) ;
}
V_307 = 0 ;
while ( ( V_260 = F_270 ( V_256 , V_257 , V_297 , V_293 , NULL ) ) != - 1 ) {
switch ( V_260 ) {
case 'C' :
if ( F_271 ( V_308 , FALSE ) ) {
F_272 ( V_308 ) ;
} else {
F_273 ( L_173 , V_308 ) ;
exit ( 1 ) ;
}
break;
case 'D' :
#ifdef F_107
V_269 = F_274 ( & V_266 , & V_270 , NULL ) ;
if ( V_269 == NULL ) {
if ( V_266 == 0 )
F_273 ( L_174 ) ;
else {
F_273 ( L_12 , V_270 ) ;
F_9 ( V_270 ) ;
}
exit ( 2 ) ;
}
#ifdef F_138
F_139 () ;
#endif
F_275 ( V_269 ) ;
F_276 ( V_269 ) ;
#ifdef F_138
F_144 () ;
#endif
exit ( 0 ) ;
#else
V_272 = TRUE ;
V_261 = TRUE ;
#endif
break;
case 'h' :
F_137 ( TRUE ) ;
exit ( 0 ) ;
break;
#ifdef F_138
case 'i' :
if ( strcmp ( V_308 , L_175 ) == 0 )
F_277 ( TRUE ) ;
break;
#endif
case 'P' :
if ( ! F_278 ( V_260 , V_308 ) ) {
F_273 ( L_176 , V_308 ) ;
exit ( 2 ) ;
}
break;
case 'v' :
#ifdef F_138
F_139 () ;
#endif
F_279 ( L_177 , V_305 , V_306 ) ;
#ifdef F_138
F_144 () ;
#endif
exit ( 0 ) ;
break;
case 'X' :
F_280 ( V_308 ) ;
break;
case '?' :
break;
}
}
if ( ! F_281 ( & V_264 , & V_265 ) ) {
F_2 ( V_247 , V_7 ,
L_178 ,
V_264 , F_235 ( V_265 ) ) ;
F_9 ( V_264 ) ;
}
if ( V_82 . V_309 &&
F_282 ( V_82 . V_309 ) == V_310 ) {
F_180 ( V_82 . V_309 ) ;
} else {
F_180 ( F_283 () ) ;
}
#if ! F_284 ( 2 , 31 , 0 )
F_285 ( NULL ) ;
#endif
setlocale ( V_298 , L_9 ) ;
F_286 ( & V_256 , & V_257 ) ;
F_287 ( F_207 , NULL ) ;
#ifdef F_107
F_288 ( F_212 , NULL ) ;
#endif
F_287 ( V_311 , NULL ) ;
#ifdef F_107
F_288 ( V_312 , NULL ) ;
#endif
F_287 ( V_313 , NULL ) ;
#ifdef F_107
F_288 ( V_314 , NULL ) ;
#endif
F_289 () ;
#ifdef F_107
F_290 ( & V_184 ) ;
F_291 ( & V_124 , & V_18 ) ;
#endif
F_292 ( V_315 , V_316 ,
V_317 , V_318 ) ;
V_20 = F_293 () ;
if ( * V_20 != '\0' ) {
V_262 = 1000 ;
}
V_283 = F_294 ( L_179 ) ;
if ( V_258 != NULL ) {
F_2 ( V_247 , V_7 ,
L_180
L_181
L_182 ,
V_258 ) ;
F_9 ( V_258 ) ;
}
F_295 () ;
#ifdef F_296
F_297 () ;
F_298 () ;
F_299 () ;
F_300 () ;
F_301 () ;
F_302 () ;
#endif
F_303 ( V_319 , NULL , ( T_4 ) V_283 ) ;
if ( ! F_304 ( V_320 , V_321 ,
F_303 , ( T_4 ) V_283 ) )
return 2 ;
F_303 ( V_322 , NULL , ( T_4 ) V_283 ) ;
#ifdef F_296
F_305 () ;
#endif
#ifdef F_306
F_307 () ;
#endif
F_308 () ;
F_309 ( V_323 ) ;
F_310 ( V_324 ) ;
F_311 ( V_325 , NULL ) ;
F_312 ( V_326 , NULL ) ;
F_313 ( V_327 , NULL ) ;
F_303 ( V_328 , NULL , ( T_4 ) V_283 ) ;
V_246 = F_232 ( & V_230 , & V_231 ) ;
F_303 ( V_329 , NULL , ( T_4 ) V_283 ) ;
F_314 () ;
F_315 ( & V_18 ) ;
F_316 () ;
#ifdef F_317
V_330 = 1 ;
V_331 = 1 ;
#else
V_331 = 0 ;
#endif
V_307 = 1 ;
while ( ( V_260 = F_270 ( V_256 , V_257 , V_297 , V_293 , NULL ) ) != - 1 ) {
switch ( V_260 ) {
case 'a' :
case 'b' :
case 'c' :
case 'f' :
case 'k' :
case 'H' :
case 'p' :
case 'i' :
#ifdef F_141
case 'I' :
#endif
#ifdef F_143
case 'A' :
#endif
case 's' :
case 'S' :
case 'w' :
case 'y' :
#ifdef F_142
case 'B' :
#endif
#ifdef F_107
V_271 = F_318 ( & V_184 , V_260 , V_308 ,
& V_267 ) ;
if( V_271 != 0 ) {
exit ( V_271 ) ;
}
#else
V_272 = TRUE ;
V_261 = TRUE ;
#endif
break;
#if F_319 ( V_332 ) || F_319 ( V_333 )
case 'K' :
F_320 ( V_308 ) ;
break;
#endif
case 'C' :
break;
case 'j' :
V_285 = V_93 ;
break;
case 'g' :
V_284 = F_321 ( V_308 , L_183 ) ;
break;
case 'J' :
V_279 = V_308 ;
break;
case 'l' :
#ifdef F_107
V_162 = TRUE ;
#else
V_272 = TRUE ;
V_261 = TRUE ;
#endif
break;
case 'L' :
#ifdef F_107
V_268 = TRUE ;
#else
V_272 = TRUE ;
V_261 = TRUE ;
#endif
break;
case 'm' :
F_9 ( V_246 -> V_334 ) ;
V_246 -> V_334 = F_6 ( V_308 ) ;
break;
case 'n' :
F_322 () ;
break;
case 'N' :
V_282 = F_323 ( V_308 , & V_335 ) ;
if ( V_282 != '\0' ) {
F_273 ( L_184 ,
V_282 ) ;
exit ( 1 ) ;
}
break;
case 'o' :
switch ( F_324 ( V_308 ) ) {
case V_336 :
break;
case V_337 :
F_273 ( L_185 , V_308 ) ;
exit ( 1 ) ;
break;
case V_338 :
switch ( F_325 ( V_308 ) ) {
case V_336 :
break;
case V_337 :
F_273 ( L_185 , V_308 ) ;
exit ( 1 ) ;
break;
case V_338 :
case V_339 :
F_273 ( L_186 ,
V_308 ) ;
exit ( 1 ) ;
break;
default:
F_8 () ;
}
break;
case V_339 :
F_273 ( L_187 ,
V_308 ) ;
exit ( 1 ) ;
break;
default:
F_8 () ;
}
break;
case 'P' :
break;
case 'r' :
V_252 = F_6 ( V_308 ) ;
break;
case 'R' :
V_277 = V_308 ;
break;
case 't' :
if ( strcmp ( V_308 , L_188 ) == 0 )
F_67 ( V_81 ) ;
else if ( strcmp ( V_308 , L_189 ) == 0 )
F_67 ( V_340 ) ;
else if ( strcmp ( V_308 , L_190 ) == 0 )
F_67 ( V_341 ) ;
else if ( strcmp ( V_308 , L_191 ) == 0 )
F_67 ( V_342 ) ;
else if ( strcmp ( V_308 , L_192 ) == 0 )
F_67 ( V_343 ) ;
else if ( strcmp ( V_308 , L_193 ) == 0 )
F_67 ( V_344 ) ;
else if ( strcmp ( V_308 , L_194 ) == 0 )
F_67 ( V_345 ) ;
else if ( strcmp ( V_308 , L_195 ) == 0 )
F_67 ( V_346 ) ;
else if ( strcmp ( V_308 , L_196 ) == 0 )
F_67 ( V_347 ) ;
else if ( strcmp ( V_308 , L_197 ) == 0 )
F_67 ( V_348 ) ;
else {
F_273 ( L_198 , V_308 ) ;
F_326 (
L_199 ) ;
F_326 (
L_200 ) ;
F_326 (
L_201 ) ;
F_326 (
L_202 ) ;
F_326 (
L_203 ) ;
exit ( 1 ) ;
}
break;
case 'u' :
if ( strcmp ( V_308 , L_204 ) == 0 )
F_327 ( V_349 ) ;
else if ( strcmp ( V_308 , L_205 ) == 0 )
F_327 ( V_350 ) ;
else {
F_273 ( L_206 , V_308 ) ;
F_326 (
L_207 ) ;
exit ( 1 ) ;
}
break;
case 'X' :
break;
case 'Y' :
V_278 = V_308 ;
break;
case 'z' :
if ( strcmp ( L_166 , V_308 ) == 0 ) {
fprintf ( V_154 , L_208 ) ;
F_328 () ;
exit ( 0 ) ;
}
if ( ! F_329 ( V_308 ) ) {
F_273 ( L_209 ) ;
F_326 ( L_210 ) ;
F_328 () ;
exit ( 1 ) ;
}
break;
case V_351 :
V_289 = F_330 ( V_289 , V_308 ) ;
break;
case V_352 :
V_290 = F_330 ( V_290 , V_308 ) ;
break;
case V_353 :
V_291 = F_330 ( V_291 , V_308 ) ;
break;
default:
case '?' :
V_261 = TRUE ;
break;
}
}
if ( ! V_261 ) {
V_256 -= V_331 ;
V_257 += V_331 ;
if ( V_256 >= 1 ) {
if ( V_252 != NULL ) {
F_273 ( L_211 ) ;
V_261 = TRUE ;
} else {
#ifndef F_213
V_252 = F_6 ( V_257 [ 0 ] ) ;
#endif
}
V_256 -- ;
V_257 ++ ;
}
if ( V_256 != 0 ) {
F_273 ( L_212 , V_257 [ 0 ] ) ;
V_261 = TRUE ;
}
}
if ( V_261 ) {
#ifndef F_107
if ( V_272 ) {
F_273 ( L_213 ) ;
}
#endif
F_137 ( FALSE ) ;
exit ( 1 ) ;
}
#ifdef F_107
F_331 ( F_173 ) ;
if ( V_267 && V_268 ) {
F_273 ( L_214 ) ;
exit ( 1 ) ;
}
if ( V_268 ) {
if ( V_252 ) {
F_273 ( L_215 ) ;
exit ( 1 ) ;
}
if ( V_184 . V_354 ) {
F_273 ( L_216 ) ;
exit ( 1 ) ;
}
} else {
if ( V_267 && V_252 ) {
F_273 ( L_217 ) ;
exit ( 1 ) ;
}
if ( V_184 . V_354 ) {
if ( V_184 . V_355 == NULL ) {
F_273 ( L_218 ) ;
V_184 . V_354 = FALSE ;
}
if ( ! V_184 . V_356 && ! V_184 . V_357 ) {
F_273 ( L_219 ) ;
}
}
}
if ( V_267 || V_268 ) {
V_271 = F_332 ( & V_184 ,
( ( V_246 -> V_358 ) && ( * V_246 -> V_358 != '\0' ) ) ? F_333 ( V_246 -> V_358 ) : NULL ) ;
if ( V_271 != 0 ) {
exit ( V_271 ) ;
}
}
if ( V_268 ) {
T_39 * V_359 ;
T_21 V_360 ;
T_40 V_361 ;
for ( V_360 = 0 ; V_360 < V_184 . V_362 -> V_72 ; V_360 ++ ) {
V_361 = F_334 ( V_184 . V_362 , T_40 , V_360 ) ;
if ( V_361 . V_363 ) {
T_2 * V_364 = NULL ;
#ifdef F_143
if ( V_361 . V_365 . V_366 . V_367 == V_368 ) {
V_364 = F_28 ( L_220 , V_361 . V_365 . V_366 . V_369 ,
V_361 . V_365 . V_366 . V_370 ) ;
}
#endif
#if F_319 ( F_141 )
V_359 = F_335 ( V_361 . V_108 , V_361 . V_371 , V_364 , & V_270 , F_173 ) ;
#else
V_359 = F_335 ( V_361 . V_108 , FALSE , V_364 , & V_270 , F_173 ) ;
#endif
F_9 ( V_364 ) ;
if ( V_359 == NULL ) {
F_273 ( L_12 , V_270 ) ;
F_9 ( V_270 ) ;
exit ( 2 ) ;
}
if ( V_359 -> V_372 == NULL ) {
F_273 ( L_221 , V_361 . V_108 ) ;
exit ( 2 ) ;
}
#ifdef F_138
F_139 () ;
#endif
#if F_319 ( F_141 )
F_336 ( V_359 , V_361 . V_108 , V_361 . V_371 ) ;
#else
F_336 ( V_359 , V_361 . V_108 , FALSE ) ;
#endif
#ifdef F_138
F_144 () ;
#endif
F_337 ( V_359 ) ;
}
}
exit ( 0 ) ;
}
F_338 ( & V_184 , V_373 ) ;
F_339 ( & V_184 ) ;
#endif
F_340 () ;
#ifdef F_107
if ( ( V_184 . V_374 == 0 ) &&
( ( V_112 . V_358 != NULL ) && ( * V_246 -> V_358 != '\0' ) ) ) {
T_21 V_360 ;
T_40 V_361 ;
for ( V_360 = 0 ; V_360 < V_184 . V_362 -> V_72 ; V_360 ++ ) {
V_361 = F_334 ( V_184 . V_362 , T_40 , V_360 ) ;
if ( ! V_361 . V_375 && strstr ( V_112 . V_358 , V_361 . V_108 ) != NULL ) {
V_361 . V_363 = TRUE ;
V_184 . V_374 ++ ;
V_184 . V_362 = F_341 ( V_184 . V_362 , V_360 ) ;
F_342 ( V_184 . V_362 , V_360 , V_361 ) ;
break;
}
}
}
if ( V_184 . V_374 == 0 && V_184 . V_362 -> V_72 == 1 ) {
T_40 V_361 = F_334 ( V_184 . V_362 , T_40 , 0 ) ;
V_361 . V_363 = TRUE ;
V_184 . V_374 ++ ;
V_184 . V_362 = F_341 ( V_184 . V_362 , 0 ) ;
F_342 ( V_184 . V_362 , 0 , V_361 ) ;
}
#endif
if ( V_230 == NULL && V_231 == NULL ) {
F_343 () ;
F_344 () ;
}
if( V_289 ) {
T_38 * V_376 ;
for ( V_376 = V_289 ; V_376 != NULL ; V_376 = F_345 ( V_376 ) )
{
F_346 ( ( char * ) V_376 -> V_19 ) ;
}
}
if( V_290 ) {
T_38 * V_377 ;
for ( V_377 = V_290 ; V_377 != NULL ; V_377 = F_345 ( V_377 ) )
{
F_347 ( ( char * ) V_377 -> V_19 , TRUE ) ;
}
}
if( V_291 ) {
T_38 * V_378 ;
for ( V_378 = V_291 ; V_378 != NULL ; V_378 = F_345 ( V_378 ) )
{
F_347 ( ( char * ) V_378 -> V_19 , FALSE ) ;
}
}
F_348 ( & V_18 . V_37 , V_246 -> V_56 , TRUE ) ;
V_276 = F_349 ( V_379 ) ;
#if F_350 ( 3 , 0 , 0 )
#else
F_351 ( V_276 ) ;
F_9 ( V_276 ) ;
V_276 = F_352 ( V_379 , FALSE ) ;
F_351 ( V_276 ) ;
#endif
F_9 ( V_276 ) ;
F_353 () ;
F_354 () ;
F_355 () ;
F_175 ( V_283 ) ;
F_356 ( V_273 , V_274 , V_275 , V_246 ) ;
if ( ! F_357 ( & V_264 , & V_265 ) ) {
F_2 ( V_247 , V_7 ,
L_178 ,
V_264 , F_235 ( V_265 ) ) ;
F_9 ( V_264 ) ;
}
F_163 ( V_82 . V_163 ) ;
F_358 () ;
F_359 () ;
#ifdef F_107
F_157 ( V_162 ) ;
#endif
switch ( F_360 () ) {
case V_380 :
break;
case V_381 :
V_82 . V_382 = 0 ;
break;
case V_383 :
default:
V_82 . V_382 = 0 ;
break;
}
F_361 ( V_123 ) ;
if ( ! F_362 ( & V_26 , V_384 ) ) {
F_2 ( V_6 , V_7 , L_12 , V_26 ) ;
F_9 ( V_26 ) ;
}
#ifdef F_107
F_363 () ;
#endif
F_130 ( V_123 ) ;
F_364 ( V_262 , F_149 , NULL ) ;
V_385 = F_364 ( V_246 -> V_386 , F_147 , NULL ) ;
if ( V_252 ) {
F_365 ( TRUE ) ;
F_239 ( V_252 ) ;
if ( V_277 != NULL ) {
if ( ! F_366 ( V_277 , & V_280 , & V_26 ) ) {
F_367 ( V_123 , V_277 , V_26 ) ;
F_9 ( V_26 ) ;
V_281 = TRUE ;
}
}
if ( F_368 ( L_222 ) > 0 ) {
V_287 = F_369 ( F_370 ( L_222 ) ) ;
}
if ( ! V_281 ) {
if ( F_371 ( & V_18 , V_252 , V_287 , FALSE , & V_266 ) == V_387 ) {
V_18 . V_280 = V_280 ;
F_372 () ;
switch ( F_373 ( & V_18 , FALSE ) ) {
case V_388 :
case V_389 :
if( V_284 != 0 ) {
F_374 ( & V_18 , V_284 ) ;
} else if ( V_279 != NULL ) {
if ( ! F_366 ( V_279 , & V_286 , & V_26 ) ) {
F_367 ( V_123 , V_279 , V_26 ) ;
F_9 ( V_26 ) ;
} else {
F_375 ( & V_18 , V_286 , V_285 ) ;
}
}
break;
case V_390 :
exit ( 0 ) ;
break;
}
if ( ! F_376 ( V_252 ) ) {
char * V_391 = V_252 ;
char * V_392 = F_377 () ;
V_252 = F_28 ( L_223 , V_392 , V_393 , V_252 ) ;
F_9 ( V_391 ) ;
F_9 ( V_392 ) ;
}
V_259 = F_181 ( V_252 ) ;
F_180 ( V_259 ) ;
F_9 ( V_252 ) ;
V_252 = NULL ;
} else {
if ( V_280 != NULL )
F_378 ( V_280 ) ;
V_18 . V_280 = NULL ;
F_365 ( FALSE ) ;
F_105 ( FALSE ) ;
F_109 ( FALSE ) ;
}
}
} else {
#ifdef F_107
if ( V_267 ) {
if ( V_184 . V_355 != NULL ) {
V_259 = F_6 ( V_184 . V_355 ) ;
F_180 ( F_181 ( V_259 ) ) ;
F_9 ( V_259 ) ;
}
F_365 ( FALSE ) ;
F_239 ( V_252 ) ;
if ( V_184 . V_394 -> V_72 == 0 )
F_379 ( & V_184 ) ;
if ( F_380 ( & V_184 , & V_124 , & V_395 , F_173 ) ) {
F_372 () ;
}
} else {
F_365 ( FALSE ) ;
F_239 ( V_252 ) ;
F_105 ( FALSE ) ;
F_109 ( FALSE ) ;
}
if ( ! V_267 && ! V_184 . V_396 . V_397 ) {
V_184 . V_396 . V_397 = F_6 ( F_293 () ) ;
}
#else
F_365 ( FALSE ) ;
F_239 ( V_252 ) ;
F_105 ( FALSE ) ;
F_109 ( FALSE ) ;
#endif
}
if ( V_278 ) {
T_1 * V_1 ;
V_1 = F_381 ( F_382 ( F_19 ( F_20 ( V_123 ) , V_398 ) ) ) ;
F_14 ( F_15 ( V_1 ) , V_278 ) ;
F_16 ( & V_18 , V_278 , FALSE ) ;
}
F_268 ( FALSE ) ;
#ifdef F_213
V_216 = ( T_33 * ) F_214 ( V_219 , NULL ) ;
#ifdef F_185
F_215 ( V_216 , F_216 ( L_110 ) ) ;
#else
F_215 ( V_216 , F_217 ( - 1 , V_183 , FALSE , NULL ) ) ;
#endif
F_383 ( V_216 ) ;
#endif
F_208 ( V_192 , V_399 , L_224 ) ;
#ifdef F_107
F_384 () ;
#endif
F_385 () ;
F_386 () ;
#ifdef F_107
F_387 () ;
#endif
F_388 () ;
F_389 ( & V_299 ) ;
#ifdef F_213
F_390 ( V_216 ) ;
#endif
#ifdef F_138
if ( F_391 ( V_123 ) )
F_392 ( V_123 ) ;
F_393 () ;
F_394 () ;
F_144 () ;
#endif
#ifdef F_185
F_395 () ;
#endif
exit ( 0 ) ;
}
int T_41
F_396 ( struct V_400 * V_401 ,
struct V_400 * V_402 ,
char * V_403 ,
int V_404 )
{
T_42 V_405 ;
F_397 () ;
memset ( & V_405 , 0 , sizeof( V_405 ) ) ;
V_405 . V_406 = sizeof( V_405 ) ;
V_405 . V_407 = V_408 ;
F_398 ( & V_405 ) ;
F_399 ( L_225 ) ;
F_400 ( FALSE ) ;
F_401 ( FALSE ) ;
return main ( V_409 , V_410 ) ;
}
static void F_402 ( T_1 * T_10 , T_4 V_19 ) {
F_403 ( F_404 ( V_19 ) , T_10 ) ;
}
static T_1 * F_405 ( T_9 V_411 )
{
switch( V_411 ) {
case ( V_412 ) :
return NULL ;
case ( V_413 ) :
return V_158 ;
case ( V_414 ) :
return V_159 ;
case ( V_415 ) :
return V_105 ;
default:
F_8 () ;
return NULL ;
}
}
void F_358 ( void ) {
T_1 * V_416 , * V_417 ;
T_1 * V_418 , * V_419 ;
T_11 V_420 = FALSE ;
F_392 ( V_421 ) ;
F_406 ( F_20 ( V_422 ) ) ;
F_406 ( F_20 ( V_423 ) ) ;
F_406 ( F_20 ( V_424 ) ) ;
F_406 ( F_20 ( V_425 ) ) ;
F_406 ( F_20 ( V_158 ) ) ;
F_406 ( F_20 ( V_159 ) ) ;
F_406 ( F_20 ( V_105 ) ) ;
F_406 ( F_20 ( V_426 ) ) ;
F_406 ( F_20 ( V_427 ) ) ;
F_406 ( F_20 ( V_428 ) ) ;
F_406 ( F_20 ( V_429 ) ) ;
F_406 ( F_20 ( V_430 ) ) ;
F_406 ( F_20 ( V_431 ) ) ;
F_407 ( F_404 ( V_421 ) , F_402 , V_421 ) ;
F_407 ( F_404 ( V_427 ) , F_402 , V_427 ) ;
F_407 ( F_404 ( V_428 ) , F_402 , V_428 ) ;
F_407 ( F_404 ( V_429 ) , F_402 , V_429 ) ;
F_407 ( F_404 ( V_430 ) , F_402 , V_430 ) ;
F_408 ( V_426 ) ;
F_409 ( F_410 ( V_421 ) , V_422 , FALSE , TRUE , 0 ) ;
F_409 ( F_410 ( V_421 ) , V_423 , FALSE , TRUE , 0 ) ;
if ( ! V_112 . V_432 ) {
F_409 ( F_410 ( V_421 ) , V_424 , FALSE , TRUE , 1 ) ;
}
F_409 ( F_410 ( V_421 ) , V_425 , FALSE , TRUE , 1 ) ;
switch( V_112 . V_433 ) {
case ( V_434 ) :
V_131 = V_427 ;
V_134 = V_428 ;
V_420 = FALSE ;
break;
case ( V_435 ) :
V_131 = V_427 ;
V_134 = V_429 ;
V_420 = FALSE ;
break;
case ( V_436 ) :
V_131 = V_427 ;
V_134 = V_429 ;
V_420 = TRUE ;
break;
case ( V_437 ) :
V_131 = V_429 ;
V_134 = V_427 ;
V_420 = FALSE ;
break;
case ( V_438 ) :
V_131 = V_429 ;
V_134 = V_427 ;
V_420 = TRUE ;
break;
case ( V_439 ) :
V_131 = V_429 ;
V_134 = V_430 ;
V_420 = FALSE ;
break;
default:
V_131 = NULL ;
V_134 = NULL ;
F_8 () ;
}
if ( V_420 ) {
V_416 = V_134 ;
V_418 = F_405 ( V_112 . V_440 ) ;
V_419 = F_405 ( V_112 . V_441 ) ;
V_417 = F_405 ( V_112 . V_442 ) ;
} else {
V_416 = F_405 ( V_112 . V_440 ) ;
V_417 = V_134 ;
V_418 = F_405 ( V_112 . V_441 ) ;
V_419 = F_405 ( V_112 . V_442 ) ;
}
if ( V_416 != NULL )
F_411 ( F_129 ( V_131 ) , V_416 ) ;
if ( V_417 != NULL )
F_412 ( F_129 ( V_131 ) , V_417 ) ;
if ( V_418 != NULL )
F_413 ( F_129 ( V_134 ) , V_418 , TRUE , TRUE ) ;
if ( V_419 != NULL )
F_414 ( F_129 ( V_134 ) , V_419 , FALSE , FALSE ) ;
F_409 ( F_410 ( V_421 ) , V_131 , TRUE , TRUE , 0 ) ;
F_409 ( F_410 ( V_421 ) , V_431 , TRUE , TRUE , 0 ) ;
F_409 ( F_410 ( V_421 ) , V_426 , FALSE , TRUE , 0 ) ;
if ( V_112 . V_432 ) {
F_409 ( F_410 ( V_426 ) , V_424 , FALSE , TRUE , 1 ) ;
}
F_415 ( V_426 ) ;
F_111 () ;
F_416 ( V_421 ) ;
}
static void
F_417 ( T_1 * T_10 , T_4 V_19 )
{
T_11 * V_443 = ( T_11 * ) V_19 ;
if ( ! * V_443 ) {
if ( F_418 ( T_10 ) )
* V_443 = TRUE ;
}
}
void
F_111 ( void )
{
T_11 V_444 ;
if ( V_82 . V_445 ) {
F_416 ( V_423 ) ;
} else {
F_392 ( V_423 ) ;
}
F_419 ( V_426 ) ;
if ( V_82 . V_446 ) {
F_416 ( V_424 ) ;
} else {
F_392 ( V_424 ) ;
}
if ( V_82 . V_447 ) {
F_416 ( V_425 ) ;
} else {
F_392 ( V_425 ) ;
}
if ( V_82 . V_448 && V_119 ) {
F_416 ( V_158 ) ;
} else {
F_392 ( V_158 ) ;
}
if ( V_82 . V_449 && V_119 ) {
F_416 ( V_159 ) ;
} else {
F_392 ( V_159 ) ;
}
if ( V_82 . V_450 && V_119 ) {
F_416 ( V_105 ) ;
} else {
F_392 ( V_105 ) ;
}
if ( V_119 ) {
F_416 ( V_131 ) ;
} else {
F_392 ( V_131 ) ;
}
V_444 = FALSE ;
F_407 ( F_404 ( V_134 ) , F_417 ,
& V_444 ) ;
if ( V_444 ) {
F_416 ( V_134 ) ;
} else {
F_392 ( V_134 ) ;
}
if ( ! V_119 ) {
if( V_431 ) {
F_416 ( V_431 ) ;
}
} else {
F_392 ( V_431 ) ;
}
}
static T_11
F_420 ( T_1 * T_10 V_24 ,
T_26 * T_27 ,
T_4 V_19 V_24 )
{
T_43 V_451 = ( ( V_452 * ) T_27 ) -> V_451 ;
if( ( T_27 -> type ) == ( V_453 ) ) {
if( ! ( V_451 & V_454 ) ) {
F_421 () ;
}
}
return FALSE ;
}
static T_11
F_422 ( T_1 * T_6 V_24 , T_44 * T_27 , T_4 T_19 V_24 )
{
if ( T_27 -> V_455 == V_456 ) {
F_423 () ;
return TRUE ;
} else if ( T_27 -> V_455 == V_457 ) {
F_424 () ;
return TRUE ;
} else if ( T_27 -> V_125 & V_458 ) {
return FALSE ;
} else if ( T_27 -> V_455 < 256 && F_425 ( T_27 -> V_455 ) ) {
if ( V_459 && ! F_426 ( V_459 ) ) {
F_427 ( F_169 ( V_123 ) , V_459 ) ;
F_428 ( F_5 ( V_459 ) , - 1 ) ;
}
return FALSE ;
}
return FALSE ;
}
static void
F_356 ( T_9 V_273 , T_9 V_274 , T_9 V_275 , T_34 * V_246
#if ! F_319 ( V_460 ) && ! F_319 ( F_213 )
V_24
#endif
)
{
T_45 * V_461 ;
V_123 = F_429 ( V_462 , L_9 ) ;
F_154 ( NULL ) ;
F_430 ( V_123 , L_226 ) ;
F_431 ( V_123 , L_227 , F_432 ( F_125 ) ,
NULL ) ;
F_431 ( F_20 ( V_123 ) , L_228 ,
F_432 ( F_420 ) , NULL ) ;
F_431 ( F_20 ( V_123 ) , L_229 ,
F_432 ( F_422 ) , NULL ) ;
V_421 = F_433 ( V_463 , 1 , FALSE ) ;
F_434 ( F_404 ( V_421 ) , 0 ) ;
F_435 ( F_404 ( V_123 ) , V_421 ) ;
F_416 ( V_421 ) ;
V_422 = F_436 ( & V_461 ) ;
#if F_319 ( V_460 ) || F_319 ( F_213 )
if( ! V_246 -> V_464 ) {
#endif
F_437 ( F_169 ( V_123 ) , V_461 ) ;
F_416 ( V_422 ) ;
#if F_319 ( V_460 ) || F_319 ( F_213 )
} else {
F_392 ( V_422 ) ;
}
#endif
V_423 = F_438 () ;
F_416 ( V_423 ) ;
V_424 = F_439 () ;
V_158 = F_440 () ;
F_441 ( V_158 , - 1 , V_273 ) ;
F_442 ( V_158 ) ;
V_159 = F_443 ( & V_111 ) ;
F_441 ( V_159 , - 1 , V_274 ) ;
F_416 ( V_159 ) ;
F_431 ( F_444 ( F_98 ( V_111 ) ) ,
L_230 , F_432 ( F_74 ) , NULL ) ;
F_431 ( V_111 , L_231 , F_432 ( V_465 ) ,
F_19 ( F_20 ( V_466 ) , V_467 ) ) ;
F_416 ( V_111 ) ;
V_105 = F_445 () ;
F_441 ( V_105 , - 1 , V_275 ) ;
F_416 ( V_105 ) ;
F_431 ( V_105 , L_231 , F_432 ( V_465 ) ,
F_19 ( F_20 ( V_466 ) , V_468 ) ) ;
V_427 = F_446 ( V_463 ) ;
F_416 ( V_427 ) ;
V_428 = F_446 ( V_463 ) ;
F_416 ( V_428 ) ;
V_429 = F_446 ( V_469 ) ;
F_416 ( V_429 ) ;
V_430 = F_446 ( V_469 ) ;
F_416 ( V_430 ) ;
#ifdef F_226
V_425 = F_447 () ;
#else
V_425 = F_448 () ;
#endif
F_416 ( V_425 ) ;
V_426 = F_449 () ;
F_416 ( V_426 ) ;
V_431 = F_450 () ;
F_416 ( V_431 ) ;
}
static void
F_365 ( T_11 V_470 )
{
F_110 ( V_470 ) ;
F_416 ( V_123 ) ;
F_130 ( V_123 ) ;
while ( F_451 () ) F_452 () ;
F_421 () ;
F_453 ( F_151 ( V_123 ) ) ;
#ifdef F_226
F_454 ( V_425 ) ;
#endif
}
static void F_455 ( const T_2 * V_471 )
{
char * V_472 , * V_473 , * V_474 ;
if ( F_456 ( V_471 , & V_472 ) == - 1 ) {
F_2 ( V_6 , V_7 ,
L_232 ,
V_472 , F_235 ( V_475 ) ) ;
F_9 ( V_472 ) ;
}
if ( F_457 ( V_471 , V_471 , TRUE , & V_474 ,
& V_472 , & V_473 ) == - 1 ) {
F_2 ( V_6 , V_7 ,
L_233 ,
V_474 , V_473 , V_472 , F_235 ( V_475 ) ) ;
F_9 ( V_474 ) ;
F_9 ( V_472 ) ;
F_9 ( V_473 ) ;
}
}
void F_458 ( const T_2 * V_471 )
{
char * V_230 , * V_231 ;
char * V_264 ;
int V_265 ;
T_2 * V_26 = NULL ;
if ( ! F_271 ( V_471 , FALSE ) ) {
if ( F_271 ( V_471 , TRUE ) ) {
F_455 ( V_471 ) ;
} else {
return;
}
}
if ( V_471 && strcmp ( V_471 , F_459 () ) == 0 ) {
return;
}
F_119 ( V_123 ) ;
if ( F_271 ( F_459 () , FALSE ) ) {
F_120 () ;
}
F_272 ( V_471 ) ;
F_460 () ;
F_461 () ;
F_462 () ;
( void ) F_232 ( & V_230 , & V_231 ) ;
if ( ! F_281 ( & V_264 , & V_265 ) ) {
F_2 ( V_247 , V_7 ,
L_172 ,
V_264 , F_235 ( V_265 ) ) ;
F_9 ( V_264 ) ;
}
if ( V_82 . V_309 &&
F_282 ( V_82 . V_309 ) == V_310 ) {
F_180 ( V_82 . V_309 ) ;
}
F_67 ( V_82 . V_83 ) ;
F_327 ( V_82 . V_476 ) ;
F_163 ( V_82 . V_163 ) ;
F_316 () ;
F_340 () ;
#ifdef F_107
F_463 () ;
#endif
F_464 () ;
F_465 () ;
F_466 ( V_477 ) ;
F_467 () ;
F_468 () ;
if ( V_230 == NULL && V_231 == NULL ) {
F_343 () ;
F_344 () ;
}
if ( ! F_469 ( & V_26 , V_384 ) ) {
F_2 ( V_6 , V_7 , L_12 , V_26 ) ;
F_9 ( V_26 ) ;
}
F_470 () ;
F_94 () ;
V_18 . V_114 = FALSE ;
F_360 () ;
F_359 () ;
F_127 () ;
}
void
F_471 ( void )
{
T_2 * V_26 = NULL ;
if ( ! F_469 ( & V_26 , V_384 ) ) {
F_2 ( V_6 , V_7 , L_12 , V_26 ) ;
F_9 ( V_26 ) ;
}
F_472 ( V_459 , NULL ) ;
if ( V_18 . V_278 ) {
T_36 * V_478 = NULL ;
if ( ! F_366 ( V_18 . V_278 , & V_478 , NULL ) ) {
F_473 ( F_20 ( V_459 ) , L_230 ) ;
F_9 ( V_18 . V_278 ) ;
V_18 . V_278 = NULL ;
}
F_378 ( V_478 ) ;
}
if ( F_53 ( & V_18 . V_37 ) ) {
F_94 () ;
} else if ( V_18 . V_125 != V_479 ) {
F_474 () ;
}
F_171 () ;
F_475 () ;
}
void F_474 ( void )
{
F_476 ( & V_18 ) ;
F_477 () ;
}
