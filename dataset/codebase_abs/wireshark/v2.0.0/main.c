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
F_24 () ;
} else {
F_25 ( V_25 , V_20 , FALSE ) ;
}
F_26 () ;
}
F_21 ( NULL , V_20 ) ;
}
}
static void F_27 ( T_4 T_8 V_24 , T_9 V_26 , T_4 V_19 )
{
T_2 * V_27 ;
T_2 * V_28 = ( T_2 * ) V_19 ;
switch( V_26 ) {
case ( V_7 ) :
if ( V_18 . V_21 ) {
V_27 = F_28 ( L_12 , V_28 ) ;
F_29 ( V_27 ) ;
F_9 ( V_27 ) ;
}
break;
case ( V_29 ) :
break;
default:
F_8 () ;
}
}
void
F_30 ( T_1 * T_10 V_24 , T_4 V_19 V_24 )
{
int V_30 ;
const T_2 * V_28 ;
T_4 T_8 ;
if ( V_18 . V_21 ) {
V_30 = V_18 . V_21 -> V_31 -> V_32 ;
if( ! F_31 ( V_30 ) ) {
V_30 = F_32 ( V_18 . V_21 -> V_31 -> V_32 ) ;
}
V_28 = F_33 ( V_30 ) ;
T_8 = F_2 ( V_33 , V_34 ,
L_13
L_14
L_15
L_14
L_16
L_17
L_14
L_18
L_19
L_14
L_20
L_21
L_14
L_22
L_14
L_23
L_24 ,
F_34 () , V_28 , F_35 () , V_28 ) ;
F_36 ( T_8 , F_27 , ( T_4 ) V_28 ) ;
}
}
static void F_37 ( T_4 T_8 V_24 , T_9 V_26 , T_4 V_19 )
{
T_2 * V_27 ;
T_2 * V_28 = ( T_2 * ) V_19 ;
switch( V_26 ) {
case ( V_7 ) :
if ( V_18 . V_21 ) {
V_27 = F_28 ( L_25 , V_28 [ 0 ] , V_28 ) ;
F_29 ( V_27 ) ;
F_9 ( V_27 ) ;
}
break;
case ( V_29 ) :
break;
default:
F_8 () ;
}
}
void
F_38 ( T_1 * T_10 V_24 , T_4 V_19 V_24 )
{
int V_30 ;
const T_2 * V_28 ;
T_4 T_8 ;
if ( V_18 . V_21 ) {
V_30 = V_18 . V_21 -> V_31 -> V_32 ;
if( ! F_31 ( V_30 ) ) {
V_30 = F_32 ( V_18 . V_21 -> V_31 -> V_32 ) ;
}
V_28 = F_33 ( V_30 ) ;
T_8 = F_2 ( V_33 , V_34 ,
L_26
L_14
L_27
L_14 ,
F_34 () , V_28 , F_35 () , V_28 ) ;
F_36 ( T_8 , F_37 , ( T_4 ) V_28 ) ;
}
}
static T_11
F_39 ( T_9 V_35 )
{
if ( ( ( V_18 . V_36 . V_37 [ V_35 ] . V_38 == V_39 ) ||
( V_18 . V_36 . V_37 [ V_35 ] . V_38 == V_40 ) ||
( V_18 . V_36 . V_37 [ V_35 ] . V_38 == V_41 ) ||
( V_18 . V_36 . V_37 [ V_35 ] . V_38 == V_42 ) ) &&
strlen ( V_18 . V_36 . V_43 . V_44 [ V_35 ] ) )
{
return TRUE ;
}
return FALSE ;
}
T_12 *
F_40 ( T_4 V_19 )
{
T_9 V_45 = F_41 ( F_19 ( F_20 ( V_19 ) , V_46 ) ) ;
T_9 V_35 = F_42 ( F_41 ( F_19 ( F_20 ( V_19 ) , V_47 ) ) ) ;
T_9 V_48 ;
T_13 * V_49 ;
T_12 * V_50 = NULL ;
V_49 = ( T_13 * ) F_43 ( V_45 ) ;
if ( V_49 != NULL ) {
T_14 V_22 ;
if ( ! F_44 ( & V_18 , V_49 ) )
return NULL ;
F_45 ( & V_22 , V_18 . V_51 , FALSE , FALSE ) ;
F_46 ( & V_22 , & V_18 . V_36 ) ;
F_47 ( & V_22 , V_18 . V_52 , & V_18 . V_53 ,
F_48 ( V_49 , & V_18 . V_54 ) , V_49 , & V_18 . V_36 ) ;
F_49 ( & V_22 , TRUE , TRUE ) ;
if ( F_39 ( V_35 ) ) {
V_50 = F_50 ( V_50 , F_28 ( L_28 , V_18 . V_36 . V_43 . V_44 [ V_35 ] ) ) ;
}
for ( V_48 = 0 ; V_48 < V_18 . V_36 . V_55 ; V_48 ++ ) {
if ( ( V_48 != V_35 ) && ( F_39 ( V_48 ) ) ) {
V_50 = F_50 ( V_50 , F_28 ( L_28 , V_18 . V_36 . V_43 . V_44 [ V_48 ] ) ) ;
}
}
F_51 ( & V_22 ) ;
}
return V_50 ;
}
static T_2 *
F_52 ( T_4 V_19 )
{
T_9 V_45 = F_41 ( F_19 ( F_20 ( V_19 ) , V_46 ) ) ;
T_9 V_35 = F_42 ( F_41 ( F_19 ( F_20 ( V_19 ) , V_47 ) ) ) ;
T_13 * V_49 ;
T_2 * V_54 = NULL ;
V_49 = ( T_13 * ) F_43 ( V_45 ) ;
if ( V_49 != NULL ) {
T_14 V_22 ;
if ( ! F_44 ( & V_18 , V_49 ) )
return NULL ;
F_45 ( & V_22 , V_18 . V_51 , F_53 ( & V_18 . V_36 ) , FALSE ) ;
F_46 ( & V_22 , & V_18 . V_36 ) ;
F_47 ( & V_22 , V_18 . V_52 , & V_18 . V_53 ,
F_48 ( V_49 , & V_18 . V_54 ) ,
V_49 , & V_18 . V_36 ) ;
F_49 ( & V_22 , TRUE , TRUE ) ;
if ( ( V_18 . V_36 . V_37 [ V_35 ] . V_56 ) ||
( strchr ( V_18 . V_36 . V_43 . V_44 [ V_35 ] , ',' ) == NULL ) )
{
if ( strlen ( V_18 . V_36 . V_43 . V_43 [ V_35 ] ) != 0 &&
strlen ( V_18 . V_36 . V_43 . V_44 [ V_35 ] ) != 0 ) {
if ( V_18 . V_36 . V_37 [ V_35 ] . V_38 == V_57 ) {
T_15 * V_58 = F_54 ( V_18 . V_36 . V_37 [ V_35 ] . V_59 ) ;
if ( V_58 && V_58 -> V_60 == - 1 ) {
V_54 = F_6 ( V_18 . V_36 . V_43 . V_43 [ V_35 ] ) ;
} else if ( V_58 && F_55 ( V_58 -> type ) ) {
V_54 = F_28 ( L_29 , V_18 . V_36 . V_43 . V_43 [ V_35 ] ,
V_18 . V_36 . V_43 . V_44 [ V_35 ] ) ;
}
}
if ( V_54 == NULL ) {
V_54 = F_28 ( L_30 , V_18 . V_36 . V_43 . V_43 [ V_35 ] ,
V_18 . V_36 . V_43 . V_44 [ V_35 ] ) ;
}
}
}
F_51 ( & V_22 ) ;
}
return V_54 ;
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
char V_61 [ V_62 ] ;
char * V_63 = V_61 ;
switch( V_2 )
{
case V_64 :
if ( V_18 . V_21 -> V_65 &&
strlen ( V_18 . V_21 -> V_65 -> V_66 ) > 0 ) {
F_11 ( V_16 , V_18 . V_21 -> V_65 -> V_66 ) ;
}
break;
case V_67 :
if ( V_18 . V_21 -> V_31 -> V_68 != 0 ) {
F_11 ( V_16 , V_18 . V_21 -> V_31 -> V_68 ) ;
}
break;
case V_69 :
if ( V_18 . V_22 != 0 ) {
T_2 * V_70 = F_58 ( V_18 . V_21 , V_18 . V_22 ) ;
F_11 ( V_16 , V_70 ) ;
F_9 ( V_70 ) ;
}
break;
default:
break;
}
if ( V_16 -> V_71 == 0 ) {
F_59 ( V_18 . V_21 , V_63 ) ;
F_11 ( V_16 , V_63 ) ;
}
if ( V_16 -> V_71 == 0 ) {
F_2 ( V_6 , V_7 , L_31 ) ;
} else {
F_12 ( V_16 ) ;
}
F_13 ( V_16 , TRUE ) ;
}
void
F_60 ( T_11 V_72 , T_13 * V_73 , T_9 V_45 ) {
if ( V_45 == - 1 )
return;
if ( V_72 ) {
V_73 -> V_74 . V_75 = 1 ;
V_18 . V_76 ++ ;
} else {
V_73 -> V_74 . V_75 = 0 ;
V_18 . V_76 -- ;
}
F_61 ( & V_18 ) ;
if ( ! V_73 -> V_74 . V_75 && ! V_73 -> V_74 . V_77 ) {
F_62 () ;
V_18 . V_78 -- ;
F_63 () ;
F_64 () ;
}
F_65 () ;
}
static void F_66 ( T_4 T_8 V_24 , T_9 V_26 , T_4 V_19 V_24 )
{
switch( V_26 ) {
case ( V_79 ) :
F_67 ( V_80 ) ;
V_81 . V_82 = V_80 ;
F_68 ( & V_18 ) ;
F_65 () ;
break;
case ( V_83 ) :
break;
default:
F_8 () ;
}
if ( V_18 . V_84 ) {
F_60 ( ! V_18 . V_84 -> V_74 . V_75 ,
V_18 . V_84 , V_18 . V_85 ) ;
}
}
void
F_69 ( T_1 * T_6 V_24 , T_4 V_19 V_24 , T_17 V_2 )
{
static T_1 * V_86 = NULL ;
switch( V_2 ) {
case V_87 :
if ( V_18 . V_84 ) {
if( V_81 . V_82 != V_80 && V_18 . V_84 -> V_74 . V_75 == 0 ) {
V_86 = ( T_1 * ) F_2 ( V_33 , V_88 ,
L_32
L_33
L_34 ,
F_34 () , F_35 () ) ;
F_36 ( V_86 , F_66 , NULL ) ;
} else {
F_60 ( ! V_18 . V_84 -> V_74 . V_75 ,
V_18 . V_84 , V_18 . V_85 ) ;
}
}
break;
case V_89 :
F_70 ( & V_18 , V_90 ) ;
break;
case V_91 :
F_70 ( & V_18 , V_92 ) ;
break;
}
}
void
F_71 ( T_1 * T_6 V_24 , T_4 V_19 V_24 , int V_2 V_24 )
{
F_72 ( & V_18 , V_90 ) ;
}
void
F_73 ( T_1 * T_6 V_24 , T_4 V_19 V_24 , int V_2 V_24 )
{
F_72 ( & V_18 , V_92 ) ;
}
static void
F_74 ( T_18 * V_93 , T_4 T_19 V_24 )
{
T_20 * V_94 ;
T_2 V_95 [ 2 + 10 + 1 + 5 + 1 ] ;
T_11 V_96 = FALSE ;
T_21 V_97 = 0 , V_98 ;
T_1 * V_99 ;
const T_7 * V_100 ;
T_9 V_101 ;
T_22 * V_102 ;
T_23 V_103 ;
if ( ! F_75 ( V_93 , & V_102 , & V_103 ) )
{
V_99 = F_76 ( V_104 ) ;
if ( V_99 == NULL )
return;
V_100 = F_77 ( V_99 , & V_98 ) ;
if ( V_100 == NULL )
return;
F_78 ( & V_18 ) ;
F_79 ( V_99 , V_100 ,
V_18 . V_84 , NULL , V_98 ) ;
F_80 ( V_93 , & V_18 ) ;
return;
}
F_81 ( V_102 , & V_103 , 1 , & V_94 , - 1 ) ;
if ( ! V_94 ) return;
F_82 ( V_104 , V_94 -> V_105 ) ;
V_99 = F_76 ( V_104 ) ;
V_100 = F_77 ( V_99 , & V_98 ) ;
F_3 ( V_100 != NULL ) ;
V_18 . V_21 = V_94 ;
F_83 ( & V_18 ) ;
if ( V_94 -> V_31 ) {
if ( V_94 -> V_31 -> V_106 != NULL &&
V_94 -> V_31 -> V_106 [ 0 ] != '\0' ) {
V_96 = TRUE ;
V_97 = ( T_21 ) strlen ( V_94 -> V_31 -> V_106 ) ;
} else {
V_97 = ( T_21 ) strlen ( V_94 -> V_31 -> V_107 ) ;
}
V_101 = V_94 -> V_97 + V_94 -> V_108 ;
if ( V_101 == 0 ) {
V_95 [ 0 ] = '\0' ;
} else if ( V_101 == 1 ) {
F_84 ( V_95 , L_35 , sizeof V_95 ) ;
} else {
F_85 ( V_95 , sizeof V_95 , L_36 , V_101 ) ;
}
F_86 () ;
if ( V_97 ) {
F_87 ( L_37 ,
( V_96 ) ? V_94 -> V_31 -> V_106 : V_94 -> V_31 -> V_107 ,
V_94 -> V_31 -> V_68 , V_95 ) ;
} else {
F_87 ( L_28 , L_9 ) ;
}
}
F_79 ( V_99 , V_100 , V_18 . V_84 , V_94 ,
V_98 ) ;
F_80 ( V_93 , & V_18 ) ;
}
void F_88 ( T_1 * T_10 V_24 , T_4 V_19 V_24 )
{
if ( V_18 . V_22 -> V_109 )
F_89 ( V_18 . V_22 -> V_109 , V_110 ) ;
}
void F_90 ( T_1 * T_10 V_24 , T_4 V_19 V_24 )
{
if ( V_18 . V_22 -> V_109 )
F_91 ( V_18 . V_22 -> V_109 , V_110 ) ;
}
void F_92 ( T_1 * T_10 V_24 , T_4 V_19 V_24 )
{
if ( V_18 . V_21 ) {
F_93 ( V_57 , V_18 . V_21 -> V_31 -> V_107 ,
V_18 . V_21 -> V_31 -> V_68 , 0 ) ;
F_94 () ;
if ( ! V_111 . V_112 ) {
F_95 () ;
}
V_18 . V_113 = FALSE ;
}
}
void F_96 ( T_1 * T_10 V_24 , T_4 V_19 V_24 )
{
T_24 * V_114 ;
V_114 = F_97 ( F_98 ( V_110 ) , V_18 . V_21 ) ;
if( V_114 ) {
F_99 ( F_98 ( V_110 ) , V_114 , TRUE ) ;
F_100 ( V_114 ) ;
}
}
void F_101 ( T_1 * T_10 V_24 , T_4 V_19 V_24 )
{
T_24 * V_114 ;
V_114 = F_97 ( F_98 ( V_110 ) , V_18 . V_21 ) ;
if( V_114 ) {
F_102 ( F_98 ( V_110 ) , V_114 ) ;
F_100 ( V_114 ) ;
}
}
void F_103 ( T_1 * T_10 V_24 , T_4 V_19 V_24 )
{
static const T_25 V_115 = {
TRUE ,
TRUE ,
TRUE ,
TRUE ,
TRUE ,
TRUE ,
FALSE
} ;
if ( V_18 . V_22 -> V_109 ) {
F_104 ( V_18 . V_22 -> V_109 , V_110 , & V_115 ) ;
}
}
static void
F_105 ( T_11 V_116 )
{
F_106 ( V_116 ) ;
#ifdef F_107
F_108 ( V_116 ) ;
F_109 ( V_116 ) ;
#endif
}
static void
F_110 ( T_11 V_117 )
{
V_118 = V_117 ;
F_111 () ;
}
static void
F_112 ( T_11 V_119 )
{
F_113 ( V_119 ) ;
F_114 ( V_119 ) ;
}
void
F_115 ( T_11 V_120 , T_11 V_121 )
{
F_116 ( V_120 , V_121 ) ;
F_117 ( V_120 , V_121 ) ;
}
T_11
F_118 ( void )
{
F_119 ( V_122 ) ;
F_120 () ;
F_121 () ;
#ifdef F_107
F_122 ( & V_123 ) ;
#endif
if ( V_18 . V_124 == V_125 ) {
V_18 . V_124 = V_126 ;
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
if ( V_127 )
return TRUE ;
if ( F_126 ( & V_18 , TRUE , L_38 ) )
return F_118 () ;
else
return TRUE ;
}
static void
F_127 ( void )
{
if ( V_81 . V_128 && V_81 . V_129 )
F_128 ( F_129 ( V_130 ) , V_81 . V_129 ) ;
if ( V_81 . V_131 && V_81 . V_132 ) {
F_128 ( F_129 ( V_133 ) , V_81 . V_132 ) ;
}
}
static void
F_130 ( T_1 * T_10 )
{
T_28 V_134 ;
V_134 . V_135 = V_111 . V_136 ;
V_134 . V_137 = V_81 . V_138 ;
V_134 . V_139 = V_81 . V_140 ;
V_134 . V_141 = V_111 . V_142 ;
if ( V_81 . V_143 > 0 &&
V_81 . V_144 > 0 ) {
V_134 . V_145 = V_81 . V_143 ;
V_134 . V_146 = V_81 . V_144 ;
V_134 . V_147 = V_111 . V_148 ;
} else {
V_134 . V_141 = FALSE ;
}
V_134 . V_149 = V_81 . V_150 ;
F_131 ( T_10 , & V_134 ) ;
F_127 () ;
F_132 () ;
}
static void
F_119 ( T_1 * T_10 )
{
T_28 V_134 ;
F_133 ( T_10 , & V_134 ) ;
if ( V_111 . V_136 ) {
V_81 . V_138 = V_134 . V_137 ;
V_81 . V_140 = V_134 . V_139 ;
}
if ( V_111 . V_142 ) {
V_81 . V_143 = V_134 . V_145 ;
V_81 . V_144 = V_134 . V_146 ;
}
if( V_111 . V_148 ) {
V_81 . V_150 = V_134 . V_149 ;
}
V_81 . V_129 = F_134 ( F_129 ( V_130 ) ) ;
V_81 . V_132 = F_134 ( F_129 ( V_133 ) ) ;
F_135 () ;
}
void
F_136 ( T_1 * T_10 V_24 , T_4 V_19 V_24 )
{
if ( F_126 ( & V_18 , TRUE , L_38 ) )
F_118 () ;
}
static void
F_137 ( T_11 V_151 ) {
T_29 * V_152 ;
#ifdef F_138
F_139 () ;
#endif
if ( V_151 ) {
V_152 = stdout ;
fprintf ( V_152 , L_39
L_40
L_41 ,
F_140 () ) ;
} else {
V_152 = V_153 ;
}
fprintf ( V_152 , L_14 ) ;
fprintf ( V_152 , L_42 ) ;
fprintf ( V_152 , L_14 ) ;
#ifdef F_107
fprintf ( V_152 , L_43 ) ;
fprintf ( V_152 , L_44 ) ;
fprintf ( V_152 , L_45 ) ;
fprintf ( V_152 , L_46 ) ;
fprintf ( V_152 , L_47 ) ;
fprintf ( V_152 , L_48 ) ;
fprintf ( V_152 , L_49 ) ;
fprintf ( V_152 , L_50 ) ;
#ifdef F_141
fprintf ( V_152 , L_51 ) ;
#endif
#ifdef F_142
fprintf ( V_152 , L_52 , V_154 ) ;
#endif
fprintf ( V_152 , L_53 ) ;
fprintf ( V_152 , L_54 ) ;
fprintf ( V_152 , L_55 ) ;
fprintf ( V_152 , L_14 ) ;
fprintf ( V_152 , L_56 ) ;
fprintf ( V_152 , L_57 ) ;
fprintf ( V_152 , L_58 ) ;
fprintf ( V_152 , L_59 ) ;
fprintf ( V_152 , L_60 ) ;
fprintf ( V_152 , L_61 ) ;
fprintf ( V_152 , L_62 ) ;
fprintf ( V_152 , L_63 ) ;
fprintf ( V_152 , L_64 ) ;
#endif
#ifdef F_143
fprintf ( V_152 , L_65 ) ;
fprintf ( V_152 , L_66 ) ;
#endif
fprintf ( V_152 , L_67 ) ;
fprintf ( V_152 , L_68 ) ;
fprintf ( V_152 , L_14 ) ;
fprintf ( V_152 , L_69 ) ;
fprintf ( V_152 , L_70 ) ;
fprintf ( V_152 , L_71 ) ;
fprintf ( V_152 , L_72 ) ;
fprintf ( V_152 , L_73 ) ;
fprintf ( V_152 , L_74 ) ;
fprintf ( V_152 , L_75 ) ;
fprintf ( V_152 , L_76 ) ;
fprintf ( V_152 , L_77 ) ;
fprintf ( V_152 , L_78 ) ;
fprintf ( V_152 , L_14 ) ;
fprintf ( V_152 , L_79 ) ;
fprintf ( V_152 , L_80 ) ;
fprintf ( V_152 , L_81 ) ;
fprintf ( V_152 , L_82 ) ;
fprintf ( V_152 , L_83 ) ;
fprintf ( V_152 , L_84 ) ;
fprintf ( V_152 , L_85 ) ;
fprintf ( V_152 , L_86 ) ;
fprintf ( V_152 , L_87 ) ;
fprintf ( V_152 , L_88 ) ;
fprintf ( V_152 , L_89 ) ;
fprintf ( V_152 , L_90 ) ;
fprintf ( V_152 , L_14 ) ;
fprintf ( V_152 , L_91 ) ;
fprintf ( V_152 , L_92 ) ;
fprintf ( V_152 , L_14 ) ;
fprintf ( V_152 , L_93 ) ;
fprintf ( V_152 , L_94 ) ;
fprintf ( V_152 , L_95 ) ;
fprintf ( V_152 , L_96 ) ;
fprintf ( V_152 , L_97 ) ;
fprintf ( V_152 , L_98 ) ;
fprintf ( V_152 , L_99 ) ;
#ifndef F_138
fprintf ( V_152 , L_100 ) ;
#endif
#ifdef F_138
F_144 () ;
#endif
}
static void
F_145 ( const char * V_155 , T_30 V_156 )
{
#ifdef F_138
F_139 () ;
#endif
fprintf ( V_153 , L_101 ) ;
vfprintf ( V_153 , V_155 , V_156 ) ;
fprintf ( V_153 , L_14 ) ;
}
static void
F_146 ( const char * V_155 , T_30 V_156 )
{
#ifdef F_138
F_139 () ;
#endif
vfprintf ( V_153 , V_155 , V_156 ) ;
fprintf ( V_153 , L_14 ) ;
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
if ( F_151 ( V_157 ) )
F_152 ( F_151 ( V_157 ) , NULL , TRUE ) ;
if ( F_151 ( V_158 ) )
F_152 ( F_151 ( V_158 ) , NULL , TRUE ) ;
}
return TRUE ;
}
void
F_153 ( T_31 * V_159 )
{
F_154 ( V_159 ) ;
F_155 ( V_159 ) ;
F_156 ( V_159 ) ;
}
void
F_157 ( T_11 V_160 )
{
F_158 ( V_160 ) ;
F_159 ( V_160 ) ;
V_161 = V_160 ;
}
void
F_160 ( T_11 V_162 )
{
F_161 ( V_162 ) ;
F_162 ( V_162 ) ;
if( V_162 != V_81 . V_162 ) {
V_81 . V_162 = V_162 ;
F_163 ( V_162 ) ;
F_26 () ;
}
}
static void
F_164 ( T_4 T_8 , T_9 V_26 V_24 , T_4 V_19 V_24 )
{
V_81 . V_163 = ! F_165 ( T_8 ) ;
}
static void
F_166 ( T_4 T_8 , T_9 V_26 V_24 , T_4 V_19 V_24 )
{
V_81 . V_164 = ! F_165 ( T_8 ) ;
}
static void
F_167 ( T_31 * V_159 )
{
if( V_159 -> V_165 > 10000 ) {
V_166 = ( T_1 * ) F_2 ( V_167 , V_168 ,
L_102 ,
F_34 () ,
F_35 () ) ;
F_168 ( F_169 ( V_166 ) , V_169 ) ;
}
F_170 () ;
F_171 () ;
F_154 ( NULL ) ;
F_155 ( NULL ) ;
F_156 ( NULL ) ;
F_112 ( FALSE ) ;
F_172 ( V_159 ) ;
F_105 ( FALSE ) ;
F_109 ( FALSE ) ;
F_83 ( V_159 ) ;
F_110 ( FALSE ) ;
F_173 () ;
}
static void
F_174 ( T_31 * V_159 V_24 )
{
if( V_166 != NULL ) {
F_175 ( V_166 ) ;
V_166 = NULL ;
}
}
static void
F_176 ( T_31 * V_159 V_24 )
{
F_177 () ;
F_110 ( TRUE ) ;
}
static void
F_178 ( T_31 * V_159 )
{
T_2 * V_170 ;
if ( ! V_159 -> V_171 && V_159 -> V_172 ) {
F_179 ( V_159 -> V_172 ) ;
V_170 = F_180 ( F_6 ( V_159 -> V_172 ) ) ;
F_181 ( V_170 ) ;
F_9 ( V_170 ) ;
}
F_153 ( V_159 ) ;
F_112 ( TRUE ) ;
}
static void
F_182 ( T_31 * V_159 )
{
T_2 * V_170 ;
if ( ! V_159 -> V_171 && V_159 -> V_172 ) {
F_179 ( V_159 -> V_172 ) ;
V_170 = F_180 ( F_6 ( V_159 -> V_172 ) ) ;
F_181 ( V_170 ) ;
F_9 ( V_170 ) ;
}
F_153 ( V_159 ) ;
}
static T_12 * F_183 (
const T_7 * V_173 ,
const T_7 * V_174 ,
const T_7 * V_175 ,
const T_7 * V_176 )
{
T_12 * V_177 = NULL ;
T_32 * V_178 ;
T_32 * V_179 ;
T_32 * V_180 ;
T_32 * V_181 ;
if( V_173 != NULL ) {
V_178 = F_184 ( - 1 , V_173 , FALSE , NULL ) ;
F_3 ( V_178 ) ;
V_177 = F_50 ( V_177 , V_178 ) ;
}
if( V_174 != NULL ) {
V_179 = F_184 ( - 1 , V_174 , FALSE , NULL ) ;
F_3 ( V_179 ) ;
V_177 = F_50 ( V_177 , V_179 ) ;
}
if( V_175 != NULL ) {
V_180 = F_184 ( - 1 , V_175 , FALSE , NULL ) ;
F_3 ( V_180 ) ;
V_177 = F_50 ( V_177 , V_180 ) ;
}
if( V_176 != NULL ) {
V_181 = F_184 ( - 1 , V_176 , FALSE , NULL ) ;
F_3 ( V_181 ) ;
V_177 = F_50 ( V_177 , V_181 ) ;
}
return V_177 ;
}
static void
F_185 ( T_33 * V_182 )
{
static T_12 * V_177 = NULL ;
F_186 ( ( T_31 * ) V_182 -> V_159 ) ;
if( V_177 == NULL ) {
V_177 = F_183 ( V_183 , V_184 , V_185 , V_186 ) ;
}
F_187 ( F_169 ( V_122 ) , V_177 ) ;
F_105 ( TRUE ) ;
F_109 ( TRUE ) ;
F_110 ( FALSE ) ;
}
static void
F_188 ( T_33 * V_182 )
{
F_186 ( ( T_31 * ) V_182 -> V_159 ) ;
F_105 ( TRUE ) ;
F_109 ( TRUE ) ;
F_112 ( TRUE ) ;
F_110 ( TRUE ) ;
}
static void
F_189 ( T_33 * V_182 )
{
T_31 * V_159 = ( T_31 * ) V_182 -> V_159 ;
static T_12 * V_177 = NULL ;
V_127 = FALSE ;
if ( ! V_159 -> V_171 && V_159 -> V_172 ) {
F_179 ( V_159 -> V_172 ) ;
}
F_105 ( FALSE ) ;
F_109 ( FALSE ) ;
F_153 ( V_159 ) ;
F_110 ( TRUE ) ;
if( V_177 == NULL ) {
V_177 = F_183 ( V_187 , V_188 , V_189 , V_190 ) ;
}
F_187 ( F_169 ( V_122 ) , V_177 ) ;
if( V_191 . V_192 ) {
F_118 () ;
}
}
static void
F_190 ( T_33 * V_182 V_24 )
{
F_110 ( FALSE ) ;
}
static void
F_191 ( T_33 * V_182 V_24 )
{
#if 0
capture_file *cf = (capture_file *)cap_session->cf;
#endif
static T_12 * V_177 = NULL ;
V_127 = FALSE ;
F_105 ( FALSE ) ;
F_109 ( FALSE ) ;
F_154 ( NULL ) ;
if( V_177 == NULL ) {
V_177 = F_183 ( V_187 , V_188 , V_189 , V_190 ) ;
}
F_187 ( F_169 ( V_122 ) , V_177 ) ;
if( V_191 . V_192 ) {
F_118 () ;
}
}
static void
F_192 ( T_33 * V_182 V_24 )
{
V_127 = TRUE ;
F_193 () ;
#ifdef F_107
F_194 () ;
F_195 () ;
#endif
}
static void
F_196 ( T_33 * V_182 V_24 )
{
static T_12 * V_177 = NULL ;
V_127 = FALSE ;
F_154 ( NULL ) ;
F_105 ( FALSE ) ;
F_109 ( FALSE ) ;
F_110 ( FALSE ) ;
if( V_177 == NULL ) {
V_177 = F_183 ( V_187 , V_188 , V_189 , V_190 ) ;
}
F_187 ( F_169 ( V_122 ) , V_177 ) ;
if( V_191 . V_192 ) {
F_118 () ;
}
}
static void
F_197 ( T_4 V_19 )
{
T_31 * V_159 = ( T_31 * ) V_19 ;
F_198 ( V_159 -> V_22 , V_110 , V_104 ) ;
F_199 ( V_159 -> V_22 -> V_109 , V_110 ) ;
if( V_159 -> V_193 &&
( V_159 -> V_194 != 0 || ( V_159 -> string && V_159 -> V_195 ) ) ) {
F_200 ( V_159 -> V_22 -> V_196 , V_159 -> V_194 ,
( V_197 * ) V_110 , V_159 -> V_22 -> V_109 ) ;
}
F_172 ( V_159 ) ;
}
static void
F_201 ( T_31 * V_159 )
{
while ( F_202 ( F_203 ( V_104 ) , 0 ) != NULL )
F_204 ( F_203 ( V_104 ) , 0 ) ;
F_205 ( V_104 , L_9 , NULL , NULL , V_110 ) ;
F_199 ( NULL , V_110 ) ;
F_172 ( V_159 ) ;
}
static void
F_206 ( T_31 * V_159 )
{
F_83 ( V_159 ) ;
}
static void
F_207 ( T_9 T_27 , T_4 V_19 , T_4 T_19 V_24 )
{
T_31 * V_159 = ( T_31 * ) V_19 ;
switch( T_27 ) {
case ( V_198 ) :
F_208 ( V_199 , V_200 , L_103 ) ;
F_209 ( V_159 ) ;
break;
case ( V_201 ) :
F_208 ( V_199 , V_200 , L_104 ) ;
F_167 ( V_159 ) ;
break;
case ( V_202 ) :
F_208 ( V_199 , V_200 , L_105 ) ;
F_174 ( V_159 ) ;
F_210 () ;
break;
case ( V_203 ) :
F_208 ( V_199 , V_200 , L_106 ) ;
F_176 ( V_159 ) ;
break;
case ( V_204 ) :
F_208 ( V_199 , V_200 , L_107 ) ;
F_178 ( V_159 ) ;
break;
case ( V_205 ) :
F_208 ( V_199 , V_200 , L_108 ) ;
F_176 ( V_159 ) ;
break;
case ( V_206 ) :
F_208 ( V_199 , V_200 , L_109 ) ;
F_178 ( V_159 ) ;
break;
case ( V_207 ) :
F_208 ( V_199 , V_200 , L_110 ) ;
break;
case ( V_208 ) :
F_208 ( V_199 , V_200 , L_111 ) ;
F_182 ( V_159 ) ;
break;
case ( V_209 ) :
F_208 ( V_199 , V_200 , L_112 ) ;
break;
case ( V_210 ) :
F_208 ( V_199 , V_200 , L_113 ) ;
break;
case ( V_211 ) :
F_208 ( V_199 , V_200 , L_114 ) ;
F_182 ( V_159 ) ;
break;
case ( V_212 ) :
F_197 ( V_159 ) ;
break;
case ( V_213 ) :
F_201 ( V_159 ) ;
break;
case ( V_214 ) :
F_206 ( V_159 ) ;
break;
case ( V_215 ) :
F_208 ( V_199 , V_200 , L_115 ) ;
break;
case ( V_216 ) :
F_208 ( V_199 , V_200 , L_116 ) ;
break;
case ( V_217 ) :
F_208 ( V_199 , V_200 , L_117 ) ;
break;
case ( V_218 ) :
F_208 ( V_199 , V_200 , L_118 ) ;
break;
case ( V_219 ) :
F_208 ( V_199 , V_200 , L_119 ) ;
break;
case ( V_220 ) :
F_208 ( V_199 , V_200 , L_120 ) ;
break;
case ( V_221 ) :
F_208 ( V_199 , V_200 , L_121 ) ;
break;
case ( V_222 ) :
F_208 ( V_199 , V_200 , L_122 ) ;
break;
default:
F_211 ( L_123 , T_27 ) ;
F_8 () ;
}
}
static void
F_212 ( T_9 T_27 , T_33 * V_182 , T_4 T_19 V_24 )
{
#ifdef F_213
T_34 * V_223 ;
#endif
switch( T_27 ) {
case ( V_224 ) :
F_208 ( V_199 , V_200 , L_124 ) ;
F_185 ( V_182 ) ;
break;
case ( V_225 ) :
F_208 ( V_199 , V_200 , L_125 ) ;
F_188 ( V_182 ) ;
#ifdef F_213
V_223 = ( T_34 * ) F_214 ( V_226 , NULL ) ;
F_215 ( V_223 , F_184 ( - 1 , V_185 , FALSE , NULL ) ) ;
#endif
break;
case ( V_227 ) :
break;
case ( V_228 ) :
F_208 ( V_199 , V_200 , L_126 ) ;
F_189 ( V_182 ) ;
break;
case ( V_229 ) :
F_208 ( V_199 , V_200 , L_127 ) ;
F_190 ( V_182 ) ;
break;
case ( V_230 ) :
F_208 ( V_199 , V_200 , L_128 ) ;
break;
case ( V_231 ) :
F_208 ( V_199 , V_200 , L_129 ) ;
F_191 ( V_182 ) ;
break;
case ( V_232 ) :
F_208 ( V_199 , V_200 , L_130 ) ;
#ifdef F_213
V_223 = ( T_34 * ) F_214 ( V_226 , NULL ) ;
F_215 ( V_223 , F_184 ( - 1 , V_190 , FALSE , NULL ) ) ;
#endif
F_192 ( V_182 ) ;
break;
case ( V_233 ) :
F_208 ( V_199 , V_200 , L_131 ) ;
F_196 ( V_182 ) ;
break;
default:
F_211 ( L_132 , T_27 ) ;
F_8 () ;
}
}
static void
F_216 ( T_3 * V_234 )
{
F_11 ( V_234 , L_133 ) ;
F_217 ( V_234 ,
#ifdef F_218
L_134 , F_218 , V_235 ,
V_236 ) ;
#else
L_135 ) ;
void
F_219 ( T_3 * V_234 )
{
F_220 ( V_234 ) ;
F_11 ( V_234 , L_136 ) ;
#ifdef F_221
#ifdef F_222
F_11 ( V_234 , L_137 ) ;
#else
F_11 ( V_234 , L_133 ) ;
F_11 ( V_234 , F_223 () ) ;
#endif
#else
F_11 ( V_234 , L_138 ) ;
#endif
F_11 ( V_234 , L_136 ) ;
#ifdef F_224
F_225 ( V_234 ) ;
#else
F_11 ( V_234 , L_139 ) ;
#endif
}
static void
F_226 ( T_3 * V_234 )
{
#ifdef F_107
F_11 ( V_234 , L_136 ) ;
F_227 ( V_234 ) ;
#endif
#if F_228 ( V_237 ) && ! F_228 ( F_138 )
F_217 ( V_234 , L_140 , F_229 () ) ;
#endif
F_230 ( V_234 ) ;
#ifdef F_224
F_11 ( V_234 , L_136 ) ;
F_231 ( V_234 ) ;
#endif
if( F_232 () ) {
F_11 ( V_234 , L_136 ) ;
F_233 ( V_234 ) ;
}
}
static T_35 *
F_234 ( char * * V_238 , char * * V_239 )
{
int V_240 , V_241 ;
int V_242 , V_243 ;
int V_244 , V_245 ;
int V_246 , V_247 ;
char * V_248 , * V_249 ;
char * V_250 , * V_251 ;
int V_252 , V_253 ;
T_35 * V_254 ;
F_235 () ;
V_254 = F_236 ( & V_240 , & V_241 , & V_248 ,
& V_252 , & V_253 , & V_249 ) ;
if ( V_248 != NULL ) {
if ( V_240 != 0 ) {
F_2 ( V_255 , V_7 ,
L_141 ,
V_248 , F_237 ( V_240 ) ) ;
}
if ( V_241 != 0 ) {
F_2 ( V_255 , V_7 ,
L_142 ,
V_248 , F_237 ( V_241 ) ) ;
}
}
if ( V_249 != NULL ) {
if ( V_252 != 0 ) {
F_2 ( V_255 , V_7 ,
L_143 ,
V_249 , F_237 ( V_252 ) ) ;
}
if ( V_253 != 0 ) {
F_2 ( V_255 , V_7 ,
L_144 ,
V_249 , F_237 ( V_253 ) ) ;
}
F_9 ( V_249 ) ;
V_249 = NULL ;
}
#ifdef F_138
if ( V_254 -> V_256 == V_257 ) {
F_139 () ;
}
#endif
F_238 ( V_258 , & V_250 , & V_242 ) ;
if ( V_250 != NULL ) {
F_2 ( V_255 , V_7 ,
L_145 ,
V_250 , F_237 ( V_242 ) ) ;
F_9 ( V_250 ) ;
}
F_238 ( V_259 , & V_251 , & V_243 ) ;
if ( V_251 != NULL ) {
F_2 ( V_255 , V_7 ,
L_146 ,
V_251 , F_237 ( V_243 ) ) ;
F_9 ( V_251 ) ;
}
F_239 ( V_238 , & V_244 , & V_245 ,
V_239 , & V_246 , & V_247 ) ;
F_240 ( V_238 , & V_244 , & V_245 ,
V_239 , & V_246 , & V_247 ) ;
if ( * V_238 != NULL ) {
if ( V_244 != 0 ) {
F_2 ( V_255 , V_7 ,
L_147 ,
* V_238 , F_237 ( V_244 ) ) ;
}
if ( V_245 != 0 ) {
F_2 ( V_255 , V_7 ,
L_148 ,
* V_238 , F_237 ( V_245 ) ) ;
}
F_9 ( * V_238 ) ;
* V_238 = NULL ;
}
if ( * V_239 != NULL ) {
if ( V_246 != 0 ) {
F_2 ( V_255 , V_7 ,
L_149 ,
* V_239 , F_237 ( V_246 ) ) ;
}
if ( V_247 != 0 ) {
F_2 ( V_255 , V_7 ,
L_150 ,
* V_239 , F_237 ( V_247 ) ) ;
}
F_9 ( * V_239 ) ;
* V_239 = NULL ;
}
return V_254 ;
}
static void
#ifdef F_138
F_241 ( T_2 * V_260 )
#else
check_and_warn_user_startup( T_2 * V_260 V_24 )
#endif
{
T_2 * V_261 , * V_262 ;
T_4 V_263 ;
if ( F_242 () && V_81 . V_163 ) {
V_261 = F_243 () ;
V_262 = F_244 () ;
V_263 = F_2 ( V_255 , V_7 ,
L_151
L_152
L_153
L_154
L_155 , V_261 , V_262 ) ;
F_9 ( V_261 ) ;
F_9 ( V_262 ) ;
F_245 ( V_263 , L_156 ) ;
F_36 ( V_263 , F_164 , NULL ) ;
}
#ifdef F_138
if ( ! F_246 () && ! V_260 && ! F_247 () && V_81 . V_164 && F_248 () >= 6 ) {
V_263 = F_2 ( V_255 , V_7 ,
L_157
L_158 ) ;
F_245 ( V_263 , L_156 ) ;
F_36 ( V_263 , F_166 , NULL ) ;
}
#endif
}
int
main ( int V_264 , char * V_265 [] )
{
char * V_266 ;
char * V_267 ;
int V_268 ;
T_11 V_269 = FALSE ;
extern int V_270 ;
const T_2 * V_20 ;
#ifdef F_138
T_36 V_271 ;
#endif
char * V_272 ;
int V_273 ;
char * V_238 , * V_239 ;
int V_274 ;
#ifdef F_107
T_11 V_275 = FALSE ;
T_11 V_276 = FALSE ;
T_12 * V_277 ;
T_2 * V_278 ;
int V_279 ;
#else
T_11 V_280 = FALSE ;
#ifdef F_138
#ifdef F_224
T_2 * V_278 ;
#endif
#endif
#endif
T_9 V_281 = 280 , V_282 = 95 , V_283 = 75 ;
T_2 * V_284 , * V_260 = NULL , * V_285 = NULL , * V_286 = NULL , * V_287 = NULL ;
T_37 * V_288 = NULL ;
T_2 * V_289 ;
T_11 V_290 = FALSE ;
T_35 * V_254 ;
char V_291 ;
T_1 * V_292 = NULL ;
T_21 V_293 = 0 ;
T_38 V_294 = V_90 ;
T_37 * V_295 = NULL ;
unsigned int V_296 = V_297 ;
#ifdef F_213
T_34 * V_223 ;
#endif
T_39 * V_298 = NULL ;
T_39 * V_299 = NULL ;
T_39 * V_300 = NULL ;
#define F_249 OPTSTRING_CAPTURE_COMMON "C:g:Hh" "jJ:kK:lm:nN:o:P:r:R:St:u:vw:X:Y:z:"
F_250 (cast-qual)
static const struct V_301 V_302 [] = {
{ ( char * ) L_159 , V_303 , NULL , 'h' } ,
{ ( char * ) L_160 , V_304 , NULL , 'r' } ,
{ ( char * ) L_161 , V_304 , NULL , 'R' } ,
{ ( char * ) L_162 , V_304 , NULL , 'Y' } ,
{ ( char * ) L_163 , V_303 , NULL , 'v' } ,
V_305
{ 0 , 0 , 0 , 0 }
} ;
F_251 (cast-qual)
static const char V_306 [] = F_249 ;
F_252 ( F_145 , F_146 ) ;
setlocale ( V_307 , L_9 ) ;
#ifdef F_138
F_253 ( V_264 , V_265 ) ;
F_254 () ;
#endif
F_255 () ;
F_256 () ;
V_266 = F_257 ( V_265 [ 0 ] , ( void * )main ) ;
F_258 () ;
F_259 ( & V_308 ) ;
#ifdef F_138
F_260 () ;
F_261 () ;
#ifdef F_224
V_309 = F_262 () ;
switch ( V_309 ) {
case V_310 :
V_311 = F_263 ( & V_274 , & V_278 ) ;
if ( V_311 == NULL || F_264 ( V_311 ) == 0 ) {
if ( V_274 == V_312 && V_278 != NULL ) {
F_2 ( V_6 , V_7 , L_28 , L_164 ) ;
F_9 ( V_278 ) ;
}
V_313 = NULL ;
} else {
V_313 = F_265 ( V_311 ) ;
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
V_314 = F_266 ( F_216 ,
F_219 ) ;
V_315 = F_267 ( F_226 ) ;
F_268 ( L_39
L_14
L_28
L_14
L_28 ,
F_140 () , V_314 -> V_234 , V_315 -> V_234 ) ;
#ifdef F_138
F_269 ( F_270 ( 1 , 1 ) , & V_271 ) ;
#endif
F_271 ( TRUE ) ;
F_272 ( & V_272 , & V_273 ) ;
if ( V_272 != NULL && V_273 != 0 ) {
F_2 ( V_255 , V_7 ,
L_165 ,
V_272 , F_237 ( V_273 ) ) ;
}
V_316 = 0 ;
while ( ( V_268 = F_273 ( V_264 , V_265 , V_306 , V_302 , NULL ) ) != - 1 ) {
switch ( V_268 ) {
case 'C' :
if ( F_274 ( V_317 , FALSE ) ) {
F_275 ( V_317 ) ;
} else {
F_276 ( L_166 , V_317 ) ;
exit ( 1 ) ;
}
break;
case 'D' :
#ifdef F_107
V_277 = F_277 ( & V_274 , & V_278 , NULL ) ;
if ( V_277 == NULL ) {
if ( V_274 == 0 )
F_276 ( L_167 ) ;
else {
F_276 ( L_28 , V_278 ) ;
F_9 ( V_278 ) ;
}
exit ( 2 ) ;
}
#ifdef F_138
F_139 () ;
#endif
F_278 ( V_277 ) ;
F_279 ( V_277 ) ;
#ifdef F_138
F_144 () ;
#endif
exit ( 0 ) ;
#else
V_280 = TRUE ;
V_269 = TRUE ;
#endif
break;
case 'h' :
F_137 ( TRUE ) ;
exit ( 0 ) ;
break;
#ifdef F_138
case 'i' :
if ( strcmp ( V_317 , L_168 ) == 0 )
F_280 ( TRUE ) ;
break;
#endif
case 'P' :
if ( ! F_281 ( V_268 , V_317 ) ) {
F_276 ( L_169 , V_317 ) ;
exit ( 2 ) ;
}
break;
case 'v' :
#ifdef F_138
F_139 () ;
#endif
F_282 ( L_170 , V_314 , V_315 ) ;
#ifdef F_138
F_144 () ;
#endif
exit ( 0 ) ;
break;
case 'X' :
F_283 ( V_317 ) ;
break;
case '?' :
break;
}
}
if ( ! F_284 ( & V_272 , & V_273 ) ) {
F_2 ( V_255 , V_7 ,
L_171 ,
V_272 , F_237 ( V_273 ) ) ;
F_9 ( V_272 ) ;
}
if ( V_81 . V_318 &&
F_285 ( V_81 . V_318 ) == V_319 ) {
F_181 ( V_81 . V_318 ) ;
} else {
F_181 ( F_286 () ) ;
}
#if ! F_287 ( 2 , 31 , 0 )
F_288 ( NULL ) ;
#endif
setlocale ( V_307 , L_9 ) ;
F_289 ( & V_264 , & V_265 ) ;
F_290 ( F_207 , NULL ) ;
#ifdef F_107
F_291 ( F_212 , NULL ) ;
#endif
F_290 ( V_320 , NULL ) ;
#ifdef F_107
F_291 ( V_321 , NULL ) ;
#endif
F_290 ( V_322 , NULL ) ;
#ifdef F_107
F_291 ( V_323 , NULL ) ;
#endif
F_292 () ;
#ifdef F_107
F_293 ( & V_191 ) ;
F_294 ( & V_123 , & V_18 ) ;
#endif
F_295 ( V_324 , V_325 ,
V_326 , V_327 ) ;
F_296 () ;
V_20 = F_297 () ;
if ( * V_20 != '\0' ) {
V_270 = 1000 ;
}
V_292 = F_298 ( L_172 ) ;
if ( V_266 != NULL ) {
F_2 ( V_255 , V_7 ,
L_173
L_174
L_175 ,
V_266 ) ;
F_9 ( V_266 ) ;
}
F_299 () ;
#ifdef F_300
F_301 () ;
F_302 () ;
F_303 () ;
F_304 () ;
F_305 () ;
F_306 () ;
#endif
F_307 ( V_328 , NULL , ( T_4 ) V_292 ) ;
F_308 ( V_329 , V_330 ,
F_307 , ( T_4 ) V_292 ) ;
F_307 ( V_331 , NULL , ( T_4 ) V_292 ) ;
#ifdef F_300
F_309 () ;
#endif
F_310 () ;
F_311 ( V_332 ) ;
F_312 ( V_333 ) ;
F_313 ( V_334 , NULL ) ;
F_314 ( V_335 , NULL ) ;
F_315 ( V_336 , NULL ) ;
F_307 ( V_337 , NULL , ( T_4 ) V_292 ) ;
V_254 = F_234 ( & V_238 , & V_239 ) ;
V_338 = F_316 ( V_254 -> V_339 , F_147 , NULL ) ;
F_307 ( V_340 , NULL , ( T_4 ) V_292 ) ;
F_317 () ;
F_318 ( & V_18 ) ;
F_319 () ;
#ifdef F_320
V_341 = 1 ;
V_342 = 1 ;
#else
V_342 = 0 ;
#endif
V_316 = 1 ;
while ( ( V_268 = F_273 ( V_264 , V_265 , V_306 , V_302 , NULL ) ) != - 1 ) {
switch ( V_268 ) {
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
V_279 = F_321 ( & V_191 , V_268 , V_317 ,
& V_275 ) ;
if( V_279 != 0 ) {
exit ( V_279 ) ;
}
#else
V_280 = TRUE ;
V_269 = TRUE ;
#endif
break;
#if F_228 ( V_343 ) || F_228 ( V_344 )
case 'K' :
F_322 ( V_317 ) ;
break;
#endif
case 'C' :
break;
case 'j' :
V_294 = V_92 ;
break;
case 'g' :
V_293 = F_323 ( V_317 , L_176 ) ;
break;
case 'J' :
V_287 = V_317 ;
break;
case 'l' :
#ifdef F_107
V_161 = TRUE ;
#else
V_280 = TRUE ;
V_269 = TRUE ;
#endif
break;
case 'L' :
#ifdef F_107
V_276 = TRUE ;
#else
V_280 = TRUE ;
V_269 = TRUE ;
#endif
break;
case 'm' :
F_9 ( V_254 -> V_345 ) ;
V_254 -> V_345 = F_6 ( V_317 ) ;
break;
case 'n' :
F_324 () ;
break;
case 'N' :
V_291 = F_325 ( V_317 , & V_346 ) ;
if ( V_291 != '\0' ) {
F_276 ( L_177 ,
V_291 ) ;
exit ( 1 ) ;
}
break;
case 'o' :
switch ( F_326 ( V_317 ) ) {
case V_347 :
break;
case V_348 :
F_276 ( L_178 , V_317 ) ;
exit ( 1 ) ;
break;
case V_349 :
switch ( F_327 ( V_317 ) ) {
case V_347 :
break;
case V_348 :
F_276 ( L_178 , V_317 ) ;
exit ( 1 ) ;
break;
case V_349 :
case V_350 :
F_276 ( L_179 ,
V_317 ) ;
exit ( 1 ) ;
break;
default:
F_8 () ;
}
break;
case V_350 :
F_276 ( L_180 ,
V_317 ) ;
exit ( 1 ) ;
break;
default:
F_8 () ;
}
break;
case 'P' :
break;
case 'r' :
V_260 = F_6 ( V_317 ) ;
break;
case 'R' :
V_285 = V_317 ;
break;
case 't' :
if ( strcmp ( V_317 , L_181 ) == 0 )
F_67 ( V_80 ) ;
else if ( strcmp ( V_317 , L_182 ) == 0 )
F_67 ( V_351 ) ;
else if ( strcmp ( V_317 , L_183 ) == 0 )
F_67 ( V_352 ) ;
else if ( strcmp ( V_317 , L_184 ) == 0 )
F_67 ( V_353 ) ;
else if ( strcmp ( V_317 , L_185 ) == 0 )
F_67 ( V_354 ) ;
else if ( strcmp ( V_317 , L_186 ) == 0 )
F_67 ( V_355 ) ;
else if ( strcmp ( V_317 , L_187 ) == 0 )
F_67 ( V_356 ) ;
else if ( strcmp ( V_317 , L_188 ) == 0 )
F_67 ( V_357 ) ;
else if ( strcmp ( V_317 , L_189 ) == 0 )
F_67 ( V_358 ) ;
else if ( strcmp ( V_317 , L_190 ) == 0 )
F_67 ( V_359 ) ;
else {
F_276 ( L_191 , V_317 ) ;
F_328 (
L_192 ) ;
F_328 (
L_193 ) ;
F_328 (
L_194 ) ;
F_328 (
L_195 ) ;
F_328 (
L_196 ) ;
exit ( 1 ) ;
}
break;
case 'u' :
if ( strcmp ( V_317 , L_197 ) == 0 )
F_329 ( V_360 ) ;
else if ( strcmp ( V_317 , L_198 ) == 0 )
F_329 ( V_361 ) ;
else {
F_276 ( L_199 , V_317 ) ;
F_328 (
L_200 ) ;
exit ( 1 ) ;
}
break;
case 'X' :
break;
case 'Y' :
V_286 = V_317 ;
break;
case 'z' :
if ( strcmp ( L_159 , V_317 ) == 0 ) {
fprintf ( V_153 , L_201 ) ;
F_330 () ;
exit ( 0 ) ;
}
if ( ! F_331 ( V_317 ) ) {
F_276 ( L_202 ) ;
F_328 ( L_203 ) ;
F_330 () ;
exit ( 1 ) ;
}
break;
case V_362 :
V_298 = F_332 ( V_298 , V_317 ) ;
break;
case V_363 :
V_299 = F_332 ( V_299 , V_317 ) ;
break;
case V_364 :
V_300 = F_332 ( V_300 , V_317 ) ;
break;
default:
case '?' :
V_269 = TRUE ;
break;
}
}
if ( ! V_269 ) {
V_264 -= V_342 ;
V_265 += V_342 ;
if ( V_264 >= 1 ) {
if ( V_260 != NULL ) {
F_276 ( L_204 ) ;
V_269 = TRUE ;
} else {
#ifndef F_213
V_260 = F_6 ( V_265 [ 0 ] ) ;
#endif
}
V_264 -- ;
V_265 ++ ;
}
if ( V_264 != 0 ) {
F_276 ( L_205 , V_265 [ 0 ] ) ;
V_269 = TRUE ;
}
}
if ( V_269 ) {
#ifndef F_107
if ( V_280 ) {
F_276 ( L_206 ) ;
}
#endif
F_137 ( FALSE ) ;
exit ( 1 ) ;
}
#ifdef F_107
F_333 ( F_173 ) ;
if ( V_275 && V_276 ) {
F_276 ( L_207 ) ;
exit ( 1 ) ;
}
if ( V_276 ) {
if ( V_260 ) {
F_276 ( L_208 ) ;
exit ( 1 ) ;
}
if ( V_191 . V_365 ) {
F_276 ( L_209 ) ;
exit ( 1 ) ;
}
} else {
if ( V_275 && V_260 ) {
F_276 ( L_210 ) ;
exit ( 1 ) ;
}
if ( V_191 . V_365 ) {
if ( V_191 . V_366 == NULL ) {
F_276 ( L_211 ) ;
V_191 . V_365 = FALSE ;
}
if ( ! V_191 . V_367 && ! V_191 . V_368 ) {
F_276 ( L_212 ) ;
}
}
}
if ( V_275 || V_276 ) {
V_279 = F_334 ( & V_191 ,
( ( V_254 -> V_369 ) && ( * V_254 -> V_369 != '\0' ) ) ? F_335 ( V_254 -> V_369 ) : NULL ) ;
if ( V_279 != 0 ) {
exit ( V_279 ) ;
}
}
if ( V_276 ) {
T_40 * V_370 ;
T_21 V_371 ;
T_41 V_372 ;
for ( V_371 = 0 ; V_371 < V_191 . V_373 -> V_71 ; V_371 ++ ) {
V_372 = F_336 ( V_191 . V_373 , T_41 , V_371 ) ;
if ( V_372 . V_374 ) {
T_2 * V_375 = NULL ;
#ifdef F_143
if ( V_372 . V_376 . V_377 . V_378 == V_379 ) {
V_375 = F_28 ( L_213 , V_372 . V_376 . V_377 . V_380 ,
V_372 . V_376 . V_377 . V_381 ) ;
}
#endif
#if F_228 ( F_141 )
V_370 = F_337 ( V_372 . V_107 , V_372 . V_382 , V_375 , & V_278 , F_173 ) ;
#else
V_370 = F_337 ( V_372 . V_107 , FALSE , V_375 , & V_278 , F_173 ) ;
#endif
F_9 ( V_375 ) ;
if ( V_370 == NULL ) {
F_276 ( L_28 , V_278 ) ;
F_9 ( V_278 ) ;
exit ( 2 ) ;
}
if ( V_370 -> V_383 == NULL ) {
F_276 ( L_214 , V_372 . V_107 ) ;
exit ( 2 ) ;
}
#ifdef F_138
F_139 () ;
#endif
#if F_228 ( F_141 )
F_338 ( V_370 , V_372 . V_107 , V_372 . V_382 ) ;
#else
F_338 ( V_370 , V_372 . V_107 , FALSE ) ;
#endif
#ifdef F_138
F_144 () ;
#endif
F_339 ( V_370 ) ;
}
}
exit ( 0 ) ;
}
F_340 ( & V_191 , V_384 ) ;
F_341 ( & V_191 ) ;
#endif
F_342 () ;
#ifdef F_107
if ( ( V_191 . V_385 == 0 ) &&
( ( V_111 . V_369 != NULL ) && ( * V_254 -> V_369 != '\0' ) ) ) {
T_21 V_371 ;
T_41 V_372 ;
for ( V_371 = 0 ; V_371 < V_191 . V_373 -> V_71 ; V_371 ++ ) {
V_372 = F_336 ( V_191 . V_373 , T_41 , V_371 ) ;
if ( ! V_372 . V_386 && strstr ( V_111 . V_369 , V_372 . V_107 ) != NULL ) {
V_372 . V_374 = TRUE ;
V_191 . V_385 ++ ;
V_191 . V_373 = F_343 ( V_191 . V_373 , V_371 ) ;
F_344 ( V_191 . V_373 , V_371 , V_372 ) ;
break;
}
}
}
if ( V_191 . V_385 == 0 && V_191 . V_373 -> V_71 == 1 ) {
T_41 V_372 = F_336 ( V_191 . V_373 , T_41 , 0 ) ;
V_372 . V_374 = TRUE ;
V_191 . V_385 ++ ;
V_191 . V_373 = F_343 ( V_191 . V_373 , 0 ) ;
F_344 ( V_191 . V_373 , 0 , V_372 ) ;
}
#endif
if ( V_238 == NULL && V_239 == NULL ) {
F_345 () ;
F_346 () ;
}
if( V_298 ) {
T_39 * V_387 ;
for ( V_387 = V_298 ; V_387 != NULL ; V_387 = F_347 ( V_387 ) )
{
F_348 ( ( char * ) V_387 -> V_19 ) ;
}
}
if( V_299 ) {
T_39 * V_388 ;
for ( V_388 = V_299 ; V_388 != NULL ; V_388 = F_347 ( V_388 ) )
{
F_349 ( ( char * ) V_388 -> V_19 , TRUE ) ;
}
}
if( V_300 ) {
T_39 * V_389 ;
for ( V_389 = V_300 ; V_389 != NULL ; V_389 = F_347 ( V_389 ) )
{
F_349 ( ( char * ) V_389 -> V_19 , FALSE ) ;
}
}
F_350 ( & V_18 . V_36 , V_254 -> V_55 , TRUE ) ;
V_284 = F_351 ( V_390 ) ;
#if F_352 ( 3 , 0 , 0 )
#else
F_353 ( V_284 ) ;
F_9 ( V_284 ) ;
V_284 = F_354 ( V_390 , FALSE ) ;
F_353 ( V_284 ) ;
#endif
F_9 ( V_284 ) ;
F_355 () ;
F_356 () ;
F_357 () ;
F_175 ( V_292 ) ;
F_358 ( V_281 , V_282 , V_283 , V_254 ) ;
if ( ! F_359 ( & V_272 , & V_273 ) ) {
F_2 ( V_255 , V_7 ,
L_171 ,
V_272 , F_237 ( V_273 ) ) ;
F_9 ( V_272 ) ;
}
F_163 ( V_81 . V_162 ) ;
F_360 () ;
F_361 () ;
#ifdef F_107
F_157 ( V_161 ) ;
#endif
switch ( F_362 () ) {
case V_391 :
break;
case V_392 :
case V_393 :
default:
V_81 . V_394 = 0 ;
}
F_363 ( V_122 ) ;
F_364 () ;
#ifdef F_107
F_365 () ;
#endif
F_130 ( V_122 ) ;
F_316 ( V_270 , F_149 , NULL ) ;
if ( V_260 ) {
F_366 ( TRUE ) ;
F_241 ( V_260 ) ;
if ( V_285 != NULL ) {
if ( ! F_367 ( V_285 , & V_288 , & V_289 ) ) {
F_368 ( V_122 , V_285 , V_289 ) ;
F_9 ( V_289 ) ;
V_290 = TRUE ;
}
}
if ( F_369 ( L_215 ) > 0 ) {
V_296 = F_370 ( F_371 ( L_215 ) ) ;
}
if ( ! V_290 ) {
if ( F_372 ( & V_18 , V_260 , V_296 , FALSE , & V_274 ) == V_395 ) {
V_18 . V_288 = V_288 ;
F_373 () ;
switch ( F_374 ( & V_18 , FALSE ) ) {
case V_396 :
case V_397 :
if( V_293 != 0 ) {
F_375 ( & V_18 , V_293 ) ;
} else if ( V_287 != NULL ) {
if ( ! F_367 ( V_287 , & V_295 , & V_289 ) ) {
F_368 ( V_122 , V_287 , V_289 ) ;
F_9 ( V_289 ) ;
} else {
F_376 ( & V_18 , V_295 , V_294 ) ;
}
}
break;
case V_398 :
exit ( 0 ) ;
break;
}
if ( ! F_377 ( V_260 ) ) {
char * V_399 = V_260 ;
char * V_400 = F_378 () ;
V_260 = F_28 ( L_216 , V_400 , V_401 , V_260 ) ;
F_9 ( V_399 ) ;
F_9 ( V_400 ) ;
}
V_267 = F_180 ( V_260 ) ;
F_181 ( V_267 ) ;
F_9 ( V_260 ) ;
V_260 = NULL ;
} else {
if ( V_288 != NULL )
F_379 ( V_288 ) ;
V_18 . V_288 = NULL ;
F_366 ( FALSE ) ;
F_105 ( FALSE ) ;
F_109 ( FALSE ) ;
}
}
} else {
#ifdef F_107
if ( V_275 ) {
if ( V_191 . V_366 != NULL ) {
V_267 = F_180 ( F_6 ( V_191 . V_366 ) ) ;
F_181 ( V_267 ) ;
F_9 ( V_267 ) ;
}
F_366 ( FALSE ) ;
F_241 ( V_260 ) ;
if ( V_191 . V_402 -> V_71 == 0 )
F_380 ( & V_191 ) ;
if ( F_381 ( & V_191 , & V_123 , F_173 ) ) {
F_373 () ;
}
} else {
F_366 ( FALSE ) ;
F_241 ( V_260 ) ;
F_105 ( FALSE ) ;
F_109 ( FALSE ) ;
}
if ( ! V_275 && ! V_191 . V_403 . V_404 ) {
V_191 . V_403 . V_404 = F_6 ( F_297 () ) ;
}
#else
F_366 ( FALSE ) ;
F_241 ( V_260 ) ;
F_105 ( FALSE ) ;
F_109 ( FALSE ) ;
#endif
}
if ( V_286 ) {
T_1 * V_1 ;
V_1 = F_382 ( F_383 ( F_19 ( F_20 ( V_122 ) , V_405 ) ) ) ;
F_14 ( F_15 ( V_1 ) , V_286 ) ;
F_16 ( & V_18 , V_286 , FALSE ) ;
}
F_384 () ;
F_271 ( FALSE ) ;
#ifdef F_213
V_223 = ( T_34 * ) F_214 ( V_226 , NULL ) ;
F_215 ( V_223 , F_184 ( - 1 , V_190 , FALSE , NULL ) ) ;
F_385 ( V_223 ) ;
#endif
F_208 ( V_199 , V_406 , L_217 ) ;
#ifdef F_107
F_386 () ;
#endif
F_387 () ;
F_388 () ;
#ifdef F_107
F_389 () ;
#endif
F_390 () ;
F_391 () ;
F_392 ( & V_308 ) ;
#ifdef F_213
F_393 ( V_223 ) ;
#endif
#ifdef F_138
if ( F_394 ( V_122 ) )
F_395 ( V_122 ) ;
F_396 () ;
F_397 () ;
F_144 () ;
#endif
exit ( 0 ) ;
}
int T_42
F_398 ( struct V_407 * V_408 ,
struct V_407 * V_409 ,
char * V_410 ,
int V_411 )
{
T_43 V_412 ;
F_399 () ;
memset ( & V_412 , 0 , sizeof( V_412 ) ) ;
V_412 . V_413 = sizeof( V_412 ) ;
V_412 . V_414 = V_415 ;
F_400 ( & V_412 ) ;
F_401 ( L_218 ) ;
F_402 ( FALSE ) ;
F_403 ( FALSE ) ;
return main ( V_416 , V_417 ) ;
}
static void F_404 ( T_1 * T_10 , T_4 V_19 ) {
F_405 ( F_406 ( V_19 ) , T_10 ) ;
}
static T_1 * F_407 ( T_9 V_418 )
{
switch( V_418 ) {
case ( V_419 ) :
return NULL ;
case ( V_420 ) :
return V_157 ;
case ( V_421 ) :
return V_158 ;
case ( V_422 ) :
return V_104 ;
default:
F_8 () ;
return NULL ;
}
}
void F_360 ( void ) {
T_1 * V_423 , * V_424 ;
T_1 * V_425 , * V_426 ;
T_11 V_427 = FALSE ;
F_395 ( V_428 ) ;
F_408 ( F_20 ( V_429 ) ) ;
F_408 ( F_20 ( V_430 ) ) ;
F_408 ( F_20 ( V_431 ) ) ;
F_408 ( F_20 ( V_432 ) ) ;
F_408 ( F_20 ( V_157 ) ) ;
F_408 ( F_20 ( V_158 ) ) ;
F_408 ( F_20 ( V_104 ) ) ;
F_408 ( F_20 ( V_433 ) ) ;
F_408 ( F_20 ( V_434 ) ) ;
F_408 ( F_20 ( V_435 ) ) ;
F_408 ( F_20 ( V_436 ) ) ;
F_408 ( F_20 ( V_437 ) ) ;
F_408 ( F_20 ( V_438 ) ) ;
F_409 ( F_406 ( V_428 ) , F_404 , V_428 ) ;
F_409 ( F_406 ( V_434 ) , F_404 , V_434 ) ;
F_409 ( F_406 ( V_435 ) , F_404 , V_435 ) ;
F_409 ( F_406 ( V_436 ) , F_404 , V_436 ) ;
F_409 ( F_406 ( V_437 ) , F_404 , V_437 ) ;
F_410 ( V_433 ) ;
F_411 ( F_412 ( V_428 ) , V_429 , FALSE , TRUE , 0 ) ;
F_411 ( F_412 ( V_428 ) , V_430 , FALSE , TRUE , 0 ) ;
if ( ! V_111 . V_439 ) {
F_411 ( F_412 ( V_428 ) , V_431 , FALSE , TRUE , 1 ) ;
}
F_411 ( F_412 ( V_428 ) , V_432 , FALSE , TRUE , 1 ) ;
switch( V_111 . V_440 ) {
case ( V_441 ) :
V_130 = V_434 ;
V_133 = V_435 ;
V_427 = FALSE ;
break;
case ( V_442 ) :
V_130 = V_434 ;
V_133 = V_436 ;
V_427 = FALSE ;
break;
case ( V_443 ) :
V_130 = V_434 ;
V_133 = V_436 ;
V_427 = TRUE ;
break;
case ( V_444 ) :
V_130 = V_436 ;
V_133 = V_434 ;
V_427 = FALSE ;
break;
case ( V_445 ) :
V_130 = V_436 ;
V_133 = V_434 ;
V_427 = TRUE ;
break;
case ( V_446 ) :
V_130 = V_436 ;
V_133 = V_437 ;
V_427 = FALSE ;
break;
default:
V_130 = NULL ;
V_133 = NULL ;
F_8 () ;
}
if ( V_427 ) {
V_423 = V_133 ;
V_425 = F_407 ( V_111 . V_447 ) ;
V_426 = F_407 ( V_111 . V_448 ) ;
V_424 = F_407 ( V_111 . V_449 ) ;
} else {
V_423 = F_407 ( V_111 . V_447 ) ;
V_424 = V_133 ;
V_425 = F_407 ( V_111 . V_448 ) ;
V_426 = F_407 ( V_111 . V_449 ) ;
}
if ( V_423 != NULL )
F_413 ( F_129 ( V_130 ) , V_423 ) ;
if ( V_424 != NULL )
F_414 ( F_129 ( V_130 ) , V_424 ) ;
if ( V_425 != NULL )
F_415 ( F_129 ( V_133 ) , V_425 , TRUE , TRUE ) ;
if ( V_426 != NULL )
F_416 ( F_129 ( V_133 ) , V_426 , FALSE , FALSE ) ;
F_411 ( F_412 ( V_428 ) , V_130 , TRUE , TRUE , 0 ) ;
F_411 ( F_412 ( V_428 ) , V_438 , TRUE , TRUE , 0 ) ;
F_411 ( F_412 ( V_428 ) , V_433 , FALSE , TRUE , 0 ) ;
if ( V_111 . V_439 ) {
F_411 ( F_412 ( V_433 ) , V_431 , FALSE , TRUE , 1 ) ;
}
F_417 ( V_433 ) ;
F_111 () ;
F_418 ( V_428 ) ;
}
static void
F_419 ( T_1 * T_10 , T_4 V_19 )
{
T_11 * V_450 = ( T_11 * ) V_19 ;
if ( ! * V_450 ) {
if ( F_420 ( T_10 ) )
* V_450 = TRUE ;
}
}
void
F_111 ( void )
{
T_11 V_451 ;
if ( V_81 . V_452 ) {
F_418 ( V_430 ) ;
} else {
F_395 ( V_430 ) ;
}
F_421 ( V_433 ) ;
if ( V_81 . V_453 ) {
F_418 ( V_431 ) ;
} else {
F_395 ( V_431 ) ;
}
if ( V_81 . V_454 ) {
F_418 ( V_432 ) ;
} else {
F_395 ( V_432 ) ;
}
if ( V_81 . V_455 && V_118 ) {
F_418 ( V_157 ) ;
} else {
F_395 ( V_157 ) ;
}
if ( V_81 . V_456 && V_118 ) {
F_418 ( V_158 ) ;
} else {
F_395 ( V_158 ) ;
}
if ( V_81 . V_457 && V_118 ) {
F_418 ( V_104 ) ;
} else {
F_395 ( V_104 ) ;
}
if ( V_118 ) {
F_418 ( V_130 ) ;
} else {
F_395 ( V_130 ) ;
}
V_451 = FALSE ;
F_409 ( F_406 ( V_133 ) , F_419 ,
& V_451 ) ;
if ( V_451 ) {
F_418 ( V_133 ) ;
} else {
F_395 ( V_133 ) ;
}
if ( ! V_118 ) {
if( V_438 ) {
F_418 ( V_438 ) ;
}
} else {
F_395 ( V_438 ) ;
}
}
static T_11
F_422 ( T_1 * T_10 V_24 ,
T_26 * T_27 ,
T_4 V_19 V_24 )
{
T_44 V_458 = ( ( V_459 * ) T_27 ) -> V_458 ;
if( ( T_27 -> type ) == ( V_460 ) ) {
if( ! ( V_458 & V_461 ) ) {
F_423 () ;
}
}
return FALSE ;
}
static T_11
F_424 ( T_1 * T_6 V_24 , T_45 * T_27 , T_4 T_19 V_24 )
{
if ( T_27 -> V_462 == V_463 ) {
F_425 () ;
return TRUE ;
} else if ( T_27 -> V_462 == V_464 ) {
F_426 () ;
return TRUE ;
} else if ( T_27 -> V_124 & V_465 ) {
return FALSE ;
} else if ( T_27 -> V_462 < 256 && F_427 ( T_27 -> V_462 ) ) {
if ( V_466 && ! F_428 ( V_466 ) ) {
F_429 ( F_169 ( V_122 ) , V_466 ) ;
F_430 ( F_5 ( V_466 ) , - 1 ) ;
}
return FALSE ;
}
return FALSE ;
}
static void
F_358 ( T_9 V_281 , T_9 V_282 , T_9 V_283 , T_35 * V_254
#if ! F_228 ( V_467 ) && ! F_228 ( F_213 )
V_24
#endif
)
{
T_46 * V_468 ;
V_122 = F_431 ( V_469 , L_9 ) ;
F_154 ( NULL ) ;
F_432 ( V_122 , L_219 ) ;
F_433 ( V_122 , L_220 , F_434 ( F_125 ) ,
NULL ) ;
F_433 ( F_20 ( V_122 ) , L_221 ,
F_434 ( F_422 ) , NULL ) ;
F_433 ( F_20 ( V_122 ) , L_222 ,
F_434 ( F_424 ) , NULL ) ;
V_428 = F_435 ( V_470 , 1 , FALSE ) ;
F_436 ( F_406 ( V_428 ) , 0 ) ;
F_437 ( F_406 ( V_122 ) , V_428 ) ;
F_418 ( V_428 ) ;
V_429 = F_438 ( & V_468 ) ;
#if F_228 ( V_467 ) || F_228 ( F_213 )
if( ! V_254 -> V_471 ) {
#endif
F_439 ( F_169 ( V_122 ) , V_468 ) ;
F_418 ( V_429 ) ;
#if F_228 ( V_467 ) || F_228 ( F_213 )
} else {
F_395 ( V_429 ) ;
}
#endif
V_430 = F_440 () ;
F_418 ( V_430 ) ;
V_431 = F_441 () ;
V_157 = F_442 () ;
F_443 ( V_157 , - 1 , V_281 ) ;
F_444 ( V_157 ) ;
V_158 = F_445 ( & V_110 ) ;
F_443 ( V_158 , - 1 , V_282 ) ;
F_418 ( V_158 ) ;
F_433 ( F_446 ( F_98 ( V_110 ) ) ,
L_223 , F_434 ( F_74 ) , NULL ) ;
F_433 ( V_110 , L_224 , F_434 ( V_472 ) ,
F_19 ( F_20 ( V_473 ) , V_474 ) ) ;
F_418 ( V_110 ) ;
V_104 = F_447 () ;
F_443 ( V_104 , - 1 , V_283 ) ;
F_418 ( V_104 ) ;
F_433 ( V_104 , L_224 , F_434 ( V_472 ) ,
F_19 ( F_20 ( V_473 ) , V_475 ) ) ;
V_434 = F_448 ( V_470 ) ;
F_418 ( V_434 ) ;
V_435 = F_448 ( V_470 ) ;
F_418 ( V_435 ) ;
V_436 = F_448 ( V_476 ) ;
F_418 ( V_436 ) ;
V_437 = F_448 ( V_476 ) ;
F_418 ( V_437 ) ;
#ifdef F_224
V_432 = F_449 () ;
#else
V_432 = F_450 () ;
#endif
F_418 ( V_432 ) ;
V_433 = F_451 () ;
F_418 ( V_433 ) ;
V_438 = F_452 () ;
F_418 ( V_438 ) ;
}
static void
F_366 ( T_11 V_477 )
{
F_110 ( V_477 ) ;
F_418 ( V_122 ) ;
F_130 ( V_122 ) ;
while ( F_453 () ) F_454 () ;
F_423 () ;
F_455 ( F_151 ( V_122 ) ) ;
#ifdef F_224
F_456 ( V_432 ) ;
#endif
}
static void F_457 ( const T_2 * V_478 )
{
char * V_479 , * V_480 , * V_481 ;
if ( F_458 ( V_478 , & V_479 ) == - 1 ) {
F_2 ( V_6 , V_7 ,
L_225 ,
V_479 , F_237 ( V_482 ) ) ;
F_9 ( V_479 ) ;
}
if ( F_459 ( V_478 , V_478 , TRUE , & V_481 ,
& V_479 , & V_480 ) == - 1 ) {
F_2 ( V_6 , V_7 ,
L_226 ,
V_481 , V_480 , V_479 , F_237 ( V_482 ) ) ;
F_9 ( V_481 ) ;
F_9 ( V_479 ) ;
F_9 ( V_480 ) ;
}
}
void F_460 ( const T_2 * V_478 )
{
char * V_238 , * V_239 ;
char * V_272 ;
int V_273 ;
if ( ! F_274 ( V_478 , FALSE ) ) {
if ( F_274 ( V_478 , TRUE ) ) {
F_457 ( V_478 ) ;
} else {
return;
}
}
if ( V_478 && strcmp ( V_478 , F_461 () ) == 0 ) {
return;
}
F_119 ( V_122 ) ;
if ( F_274 ( F_461 () , FALSE ) ) {
F_120 () ;
}
F_275 ( V_478 ) ;
F_462 () ;
F_463 () ;
F_464 () ;
( void ) F_234 ( & V_238 , & V_239 ) ;
if ( ! F_284 ( & V_272 , & V_273 ) ) {
F_2 ( V_255 , V_7 ,
L_165 ,
V_272 , F_237 ( V_273 ) ) ;
F_9 ( V_272 ) ;
}
if ( V_81 . V_318 &&
F_285 ( V_81 . V_318 ) == V_319 ) {
F_181 ( V_81 . V_318 ) ;
}
F_67 ( V_81 . V_82 ) ;
F_329 ( V_81 . V_483 ) ;
F_163 ( V_81 . V_162 ) ;
F_319 () ;
F_342 () ;
F_465 () ;
F_466 () ;
F_467 ( V_484 ) ;
F_468 () ;
F_469 () ;
if ( V_238 == NULL && V_239 == NULL ) {
F_345 () ;
F_346 () ;
}
F_470 () ;
F_471 () ;
F_94 () ;
V_18 . V_113 = FALSE ;
F_362 () ;
F_361 () ;
F_127 () ;
}
void
F_472 ( void )
{
F_470 () ;
F_473 ( V_466 , NULL ) ;
if ( V_18 . V_286 ) {
T_37 * V_485 = NULL ;
if ( ! F_367 ( V_18 . V_286 , & V_485 , NULL ) ) {
F_474 ( F_20 ( V_466 ) , L_223 ) ;
F_9 ( V_18 . V_286 ) ;
V_18 . V_286 = NULL ;
}
F_379 ( V_485 ) ;
}
if ( F_53 ( & V_18 . V_36 ) ) {
F_94 () ;
} else if ( V_18 . V_124 != V_486 ) {
F_475 () ;
}
F_171 () ;
F_476 () ;
}
void F_475 ( void )
{
F_477 ( & V_18 ) ;
F_478 () ;
}
