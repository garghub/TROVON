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
}
}
void
F_21 ( T_1 * T_6 V_24 , T_4 V_19 V_24 , T_7 V_25 )
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
F_22 ( V_20 ) ;
} else {
if ( V_25 == 255 ) {
F_23 () ;
} else {
F_24 ( V_25 , V_20 , FALSE ) ;
}
F_25 () ;
}
}
}
static void F_26 ( T_4 T_8 V_24 , T_9 V_26 , T_4 V_19 )
{
T_2 * V_27 ;
T_2 * V_28 = ( T_2 * ) V_19 ;
switch( V_26 ) {
case ( V_7 ) :
if ( V_18 . V_21 ) {
V_27 = F_27 ( L_12 , V_28 ) ;
F_28 ( V_27 ) ;
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
F_29 ( T_1 * T_10 V_24 , T_4 V_19 V_24 )
{
int V_30 ;
const T_2 * V_28 ;
T_4 T_8 ;
if ( V_18 . V_21 ) {
V_30 = V_18 . V_21 -> V_31 -> V_32 ;
if( ! F_30 ( V_30 ) ) {
V_30 = F_31 ( V_18 . V_21 -> V_31 -> V_32 ) ;
}
V_28 = F_32 ( V_30 ) ;
if ( ! F_33 ( V_30 ) ) {
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
F_36 ( T_8 , F_26 , ( T_4 ) V_28 ) ;
} else {
F_2 ( V_35 , V_7 ,
L_25
L_14
L_26
L_14
L_27
L_28
L_14
L_29 ,
F_34 () , V_28 , F_35 () , V_28 ) ;
}
}
}
static void F_37 ( T_4 T_8 V_24 , T_9 V_26 , T_4 V_19 )
{
T_2 * V_27 ;
T_2 * V_28 = ( T_2 * ) V_19 ;
switch( V_26 ) {
case ( V_7 ) :
if ( V_18 . V_21 ) {
V_27 = F_27 ( L_30 , V_28 [ 0 ] , V_28 ) ;
F_28 ( V_27 ) ;
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
if( ! F_30 ( V_30 ) ) {
V_30 = F_31 ( V_18 . V_21 -> V_31 -> V_32 ) ;
}
V_28 = F_32 ( V_30 ) ;
if ( ! F_33 ( V_30 ) ) {
T_8 = F_2 ( V_33 , V_34 ,
L_31
L_14
L_32
L_14 ,
F_34 () , V_28 , F_35 () , V_28 ) ;
F_36 ( T_8 , F_37 , ( T_4 ) V_28 ) ;
} else {
F_2 ( V_35 , V_7 ,
L_33
L_14
L_34
L_14
L_35
L_36
L_14
L_29 ,
F_34 () , V_28 , F_35 () , V_28 ) ;
}
}
}
static T_11
F_39 ( T_9 V_36 )
{
if ( ( ( V_18 . V_37 . V_38 [ V_36 ] == V_39 ) ||
( V_18 . V_37 . V_38 [ V_36 ] == V_40 ) ||
( V_18 . V_37 . V_38 [ V_36 ] == V_41 ) ||
( V_18 . V_37 . V_38 [ V_36 ] == V_42 ) ) &&
strlen ( V_18 . V_37 . V_43 . V_44 [ V_36 ] ) )
{
return TRUE ;
}
return FALSE ;
}
T_12 *
F_40 ( T_4 V_19 )
{
T_9 V_45 = F_41 ( F_19 ( F_20 ( V_19 ) , V_46 ) ) ;
T_9 V_36 = F_42 ( F_41 ( F_19 ( F_20 ( V_19 ) , V_47 ) ) ) ;
T_9 V_48 ;
T_13 * V_49 ;
T_12 * V_50 = NULL ;
V_49 = ( T_13 * ) F_43 ( V_45 ) ;
if ( V_49 != NULL ) {
T_14 V_22 ;
if ( ! F_44 ( & V_18 , V_49 ) )
return NULL ;
F_45 ( & V_22 , V_18 . V_51 , FALSE , FALSE ) ;
F_46 ( & V_22 , & V_18 . V_37 ) ;
F_47 ( & V_22 , & V_18 . V_52 , F_48 ( V_49 , & V_18 . V_53 ) ,
V_49 , & V_18 . V_37 ) ;
F_49 ( & V_22 , TRUE , TRUE ) ;
if ( F_39 ( V_36 ) ) {
V_50 = F_50 ( V_50 , F_51 ( L_37 , V_18 . V_37 . V_43 . V_44 [ V_36 ] ) ) ;
}
for ( V_48 = 0 ; V_48 < V_18 . V_37 . V_54 ; V_48 ++ ) {
if ( ( V_48 != V_36 ) && ( F_39 ( V_48 ) ) ) {
V_50 = F_50 ( V_50 , F_51 ( L_37 , V_18 . V_37 . V_43 . V_44 [ V_48 ] ) ) ;
}
}
F_52 ( & V_22 ) ;
}
return V_50 ;
}
static T_2 *
F_53 ( T_4 V_19 )
{
T_9 V_45 = F_41 ( F_19 ( F_20 ( V_19 ) , V_46 ) ) ;
T_9 V_36 = F_42 ( F_41 ( F_19 ( F_20 ( V_19 ) , V_47 ) ) ) ;
T_13 * V_49 ;
T_2 * V_53 = NULL ;
V_49 = ( T_13 * ) F_43 ( V_45 ) ;
if ( V_49 != NULL ) {
T_14 V_22 ;
if ( ! F_44 ( & V_18 , V_49 ) )
return NULL ;
F_45 ( & V_22 , V_18 . V_51 , F_54 ( & V_18 . V_37 ) , FALSE ) ;
F_46 ( & V_22 , & V_18 . V_37 ) ;
F_47 ( & V_22 , & V_18 . V_52 , F_48 ( V_49 , & V_18 . V_53 ) ,
V_49 , & V_18 . V_37 ) ;
F_49 ( & V_22 , TRUE , TRUE ) ;
if ( ( V_18 . V_37 . V_55 [ V_36 ] ) ||
( strchr ( V_18 . V_37 . V_43 . V_44 [ V_36 ] , ',' ) == NULL ) )
{
if ( strlen ( V_18 . V_37 . V_43 . V_43 [ V_36 ] ) != 0 &&
strlen ( V_18 . V_37 . V_43 . V_44 [ V_36 ] ) != 0 ) {
if ( V_18 . V_37 . V_38 [ V_36 ] == V_56 ) {
T_15 * V_57 = F_55 ( V_18 . V_37 . V_58 [ V_36 ] ) ;
if ( V_57 && V_57 -> V_59 == - 1 ) {
V_53 = F_56 ( V_18 . V_37 . V_43 . V_43 [ V_36 ] ) ;
} else if ( V_57 && V_57 -> type == V_60 ) {
V_53 = F_51 ( L_38 , V_18 . V_37 . V_43 . V_43 [ V_36 ] ,
V_18 . V_37 . V_43 . V_44 [ V_36 ] ) ;
}
}
if ( V_53 == NULL ) {
V_53 = F_51 ( L_39 , V_18 . V_37 . V_43 . V_43 [ V_36 ] ,
V_18 . V_37 . V_43 . V_44 [ V_36 ] ) ;
}
}
}
F_52 ( & V_22 ) ;
}
return V_53 ;
}
void
F_57 ( T_4 V_19 , T_5 V_2 )
{
F_1 ( ( T_1 * ) F_19 ( F_20 ( V_19 ) , V_23 ) ,
V_2 ,
F_53 ( ( T_1 * ) V_19 ) ) ;
}
void
F_58 ( T_1 * T_6 V_24 , T_4 V_19 V_24 , T_16 V_2 )
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
F_11 ( V_16 ,
F_59 ( V_18 . V_21 , V_18 . V_22 ) ) ;
}
break;
default:
break;
}
if ( V_16 -> V_70 == 0 ) {
F_60 ( V_18 . V_21 , V_63 ) ;
F_11 ( V_16 , V_63 ) ;
}
if ( V_16 -> V_70 == 0 ) {
F_2 ( V_6 , V_7 , L_40 ) ;
} else {
F_12 ( V_16 ) ;
}
F_13 ( V_16 , TRUE ) ;
}
void
F_61 ( T_11 V_71 , T_13 * V_72 , T_9 V_45 ) {
if ( V_45 == - 1 )
return;
if ( V_71 ) {
V_72 -> V_73 . V_74 = 1 ;
V_18 . V_75 ++ ;
} else {
V_72 -> V_73 . V_74 = 0 ;
V_18 . V_75 -- ;
}
F_62 ( & V_18 ) ;
if ( ! V_72 -> V_73 . V_74 && ! V_72 -> V_73 . V_76 ) {
F_63 () ;
V_18 . V_77 -- ;
F_64 () ;
F_65 () ;
}
F_66 () ;
}
static void F_67 ( T_4 T_8 V_24 , T_9 V_26 , T_4 V_19 V_24 )
{
switch( V_26 ) {
case ( V_78 ) :
F_68 ( V_79 ) ;
V_80 . V_81 = V_79 ;
F_69 ( & V_18 ) ;
F_66 () ;
break;
case ( V_82 ) :
break;
default:
F_8 () ;
}
if ( V_18 . V_83 ) {
F_61 ( ! V_18 . V_83 -> V_73 . V_74 ,
V_18 . V_83 , V_18 . V_84 ) ;
}
}
void
F_70 ( T_1 * T_6 V_24 , T_4 V_19 V_24 , T_17 V_2 )
{
static T_1 * V_85 = NULL ;
switch( V_2 ) {
case V_86 :
if ( V_18 . V_83 ) {
if( V_80 . V_81 != V_79 && V_18 . V_83 -> V_73 . V_74 == 0 ) {
V_85 = ( T_1 * ) F_2 ( V_33 , V_87 ,
L_41
L_42
L_43 ,
F_34 () , F_35 () ) ;
F_36 ( V_85 , F_67 , NULL ) ;
} else {
F_61 ( ! V_18 . V_83 -> V_73 . V_74 ,
V_18 . V_83 , V_18 . V_84 ) ;
}
}
break;
case V_88 :
F_71 ( & V_18 , V_89 ) ;
break;
case V_90 :
F_71 ( & V_18 , V_91 ) ;
break;
}
}
void
F_72 ( T_1 * T_6 V_24 , T_4 V_19 V_24 , int V_2 V_24 )
{
F_73 ( & V_18 , V_89 ) ;
}
void
F_74 ( T_1 * T_6 V_24 , T_4 V_19 V_24 , int V_2 V_24 )
{
F_73 ( & V_18 , V_91 ) ;
}
static void
F_75 ( T_18 * V_92 , T_4 T_19 V_24 )
{
T_20 * V_93 ;
T_2 V_94 [ 2 + 10 + 1 + 5 + 1 ] ;
T_11 V_95 = FALSE ;
T_21 V_96 = 0 , V_97 ;
T_1 * V_98 ;
const T_7 * V_99 ;
T_9 V_100 ;
T_22 * V_101 ;
T_23 V_102 ;
if ( ! F_76 ( V_92 , & V_101 , & V_102 ) )
{
V_98 = F_77 ( V_103 ) ;
if ( V_98 == NULL )
return;
V_99 = F_78 ( V_98 , & V_97 ) ;
if ( V_99 == NULL )
return;
F_79 ( & V_18 ) ;
F_80 ( V_98 , V_99 ,
V_18 . V_83 , NULL , V_97 ) ;
F_81 ( V_92 , & V_18 ) ;
return;
}
F_82 ( V_101 , & V_102 , 1 , & V_93 , - 1 ) ;
if ( ! V_93 ) return;
F_83 ( V_103 , V_93 -> V_104 ) ;
V_98 = F_77 ( V_103 ) ;
V_99 = F_78 ( V_98 , & V_97 ) ;
F_3 ( V_99 != NULL ) ;
V_18 . V_21 = V_93 ;
F_84 ( & V_18 ) ;
if ( V_93 -> V_31 ) {
if ( V_93 -> V_31 -> V_105 != NULL &&
V_93 -> V_31 -> V_105 [ 0 ] != '\0' ) {
V_95 = TRUE ;
V_96 = ( T_21 ) strlen ( V_93 -> V_31 -> V_105 ) ;
} else {
V_96 = ( T_21 ) strlen ( V_93 -> V_31 -> V_106 ) ;
}
V_100 = V_93 -> V_96 + V_93 -> V_107 ;
if ( V_100 == 0 ) {
V_94 [ 0 ] = '\0' ;
} else if ( V_100 == 1 ) {
F_85 ( V_94 , L_44 , sizeof V_94 ) ;
} else {
F_86 ( V_94 , sizeof V_94 , L_45 , V_100 ) ;
}
F_87 () ;
if ( V_96 ) {
F_88 ( L_46 ,
( V_95 ) ? V_93 -> V_31 -> V_105 : V_93 -> V_31 -> V_106 ,
V_93 -> V_31 -> V_68 , V_94 ) ;
} else {
F_88 ( L_37 , L_9 ) ;
}
}
F_80 ( V_98 , V_99 , V_18 . V_83 , V_93 ,
V_97 ) ;
F_81 ( V_92 , & V_18 ) ;
}
void F_89 ( T_1 * T_10 V_24 , T_4 V_19 V_24 ) {
if ( V_18 . V_22 -> V_108 )
F_90 ( V_18 . V_22 -> V_108 , V_109 ) ;
}
void F_91 ( T_1 * T_10 V_24 , T_4 V_19 V_24 ) {
if ( V_18 . V_22 -> V_108 )
F_92 ( V_18 . V_22 -> V_108 , V_109 ) ;
}
void F_93 ( T_1 * T_10 V_24 , T_4 V_19 V_24 )
{
if ( V_18 . V_21 ) {
F_94 ( V_56 , V_18 . V_21 -> V_31 -> V_106 ,
V_18 . V_21 -> V_31 -> V_68 , 0 ) ;
F_95 () ;
if ( ! V_110 . V_111 ) {
F_96 () ;
}
V_18 . V_112 = FALSE ;
}
}
void F_97 ( T_1 * T_10 V_24 , T_4 V_19 V_24 ) {
T_24 * V_113 ;
V_113 = F_98 ( F_99 ( V_109 ) , V_18 . V_21 ) ;
if( V_113 ) {
F_100 ( F_99 ( V_109 ) , V_113 , TRUE ) ;
F_101 ( V_113 ) ;
}
}
void F_102 ( T_1 * T_10 V_24 , T_4 V_19 V_24 ) {
static const T_25 V_114 = { TRUE , TRUE , TRUE , TRUE , TRUE , FALSE } ;
if ( V_18 . V_22 -> V_108 ) {
F_103 ( V_18 . V_22 -> V_108 , V_109 , & V_114 ) ;
}
}
static void
F_104 ( T_11 V_115 )
{
F_105 ( V_115 ) ;
#ifdef F_106
F_107 ( V_115 ) ;
F_108 ( V_115 ) ;
#endif
}
static void
F_109 ( T_11 V_116 )
{
V_117 = V_116 ;
F_110 () ;
}
static void
F_111 ( T_11 V_118 )
{
F_112 ( V_118 ) ;
F_113 ( V_118 ) ;
}
void
F_114 ( T_11 V_119 , T_11 V_120 )
{
F_115 ( V_119 , V_120 ) ;
F_116 ( V_119 , V_120 ) ;
}
T_11
F_117 ( void )
{
F_118 ( V_121 ) ;
F_119 () ;
F_120 () ;
#ifdef F_106
F_121 ( & V_122 ) ;
#endif
if ( V_18 . V_123 == V_124 ) {
V_18 . V_123 = V_125 ;
return TRUE ;
} else {
F_122 ( & V_18 ) ;
F_123 () ;
return FALSE ;
}
}
static T_11
F_124 ( T_1 * T_10 V_24 , T_26 * T_27 V_24 , T_4 V_19 V_24 )
{
if ( V_126 )
return TRUE ;
if ( F_125 ( & V_18 , TRUE , L_47 ) )
return F_117 () ;
else
return TRUE ;
}
static void
F_126 ( void )
{
if ( V_80 . V_127 && V_80 . V_128 )
F_127 ( F_128 ( V_129 ) , V_80 . V_128 ) ;
if ( V_80 . V_130 && V_80 . V_131 ) {
F_127 ( F_128 ( V_132 ) , V_80 . V_131 ) ;
}
}
static void
F_129 ( T_1 * T_10 )
{
T_28 V_133 ;
V_133 . V_134 = V_110 . V_135 ;
V_133 . V_136 = V_80 . V_137 ;
V_133 . V_138 = V_80 . V_139 ;
V_133 . V_140 = V_110 . V_141 ;
if ( V_80 . V_142 > 0 &&
V_80 . V_143 > 0 ) {
V_133 . V_144 = V_80 . V_142 ;
V_133 . V_145 = V_80 . V_143 ;
V_133 . V_146 = V_110 . V_147 ;
} else {
V_133 . V_140 = FALSE ;
}
V_133 . V_148 = V_80 . V_149 ;
F_130 ( T_10 , & V_133 ) ;
F_126 () ;
F_131 () ;
}
static void
F_118 ( T_1 * T_10 )
{
T_28 V_133 ;
F_132 ( T_10 , & V_133 ) ;
if ( V_110 . V_135 ) {
V_80 . V_137 = V_133 . V_136 ;
V_80 . V_139 = V_133 . V_138 ;
}
if ( V_110 . V_141 ) {
V_80 . V_142 = V_133 . V_144 ;
V_80 . V_143 = V_133 . V_145 ;
}
if( V_110 . V_147 ) {
V_80 . V_149 = V_133 . V_148 ;
}
V_80 . V_128 = F_133 ( F_128 ( V_129 ) ) ;
V_80 . V_131 = F_133 ( F_128 ( V_132 ) ) ;
F_134 () ;
}
void
F_135 ( T_1 * T_10 V_24 , T_4 V_19 V_24 )
{
if ( F_125 ( & V_18 , TRUE , L_47 ) )
F_117 () ;
}
static void
F_136 ( T_11 V_150 ) {
T_29 * V_151 ;
#ifdef F_137
F_138 () ;
#endif
if ( V_150 ) {
V_151 = stdout ;
fprintf ( V_151 , L_48 V_152 L_49
L_50
L_51
L_14
L_37 ,
V_153 , F_139 () ) ;
} else {
V_151 = V_154 ;
}
fprintf ( V_151 , L_14 ) ;
fprintf ( V_151 , L_52 ) ;
fprintf ( V_151 , L_14 ) ;
#ifdef F_106
fprintf ( V_151 , L_53 ) ;
fprintf ( V_151 , L_54 ) ;
fprintf ( V_151 , L_55 ) ;
fprintf ( V_151 , L_56 ) ;
fprintf ( V_151 , L_57 ) ;
fprintf ( V_151 , L_58 ) ;
fprintf ( V_151 , L_59 ) ;
fprintf ( V_151 , L_60 ) ;
#ifdef F_140
fprintf ( V_151 , L_61 ) ;
#endif
#if F_141 ( F_137 ) || F_141 ( F_140 )
fprintf ( V_151 , L_62 , V_155 ) ;
#endif
fprintf ( V_151 , L_63 ) ;
fprintf ( V_151 , L_64 ) ;
fprintf ( V_151 , L_65 ) ;
fprintf ( V_151 , L_14 ) ;
fprintf ( V_151 , L_66 ) ;
fprintf ( V_151 , L_67 ) ;
fprintf ( V_151 , L_68 ) ;
fprintf ( V_151 , L_69 ) ;
fprintf ( V_151 , L_70 ) ;
fprintf ( V_151 , L_71 ) ;
fprintf ( V_151 , L_72 ) ;
fprintf ( V_151 , L_73 ) ;
fprintf ( V_151 , L_74 ) ;
#endif
#ifdef F_142
fprintf ( V_151 , L_75 ) ;
fprintf ( V_151 , L_76 ) ;
#endif
fprintf ( V_151 , L_77 ) ;
fprintf ( V_151 , L_78 ) ;
fprintf ( V_151 , L_14 ) ;
fprintf ( V_151 , L_79 ) ;
fprintf ( V_151 , L_80 ) ;
fprintf ( V_151 , L_81 ) ;
fprintf ( V_151 , L_82 ) ;
fprintf ( V_151 , L_14 ) ;
fprintf ( V_151 , L_83 ) ;
fprintf ( V_151 , L_84 ) ;
fprintf ( V_151 , L_85 ) ;
fprintf ( V_151 , L_86 ) ;
fprintf ( V_151 , L_87 ) ;
fprintf ( V_151 , L_88 ) ;
fprintf ( V_151 , L_89 ) ;
fprintf ( V_151 , L_90 ) ;
fprintf ( V_151 , L_91 ) ;
fprintf ( V_151 , L_92 ) ;
fprintf ( V_151 , L_93 ) ;
fprintf ( V_151 , L_94 ) ;
fprintf ( V_151 , L_14 ) ;
fprintf ( V_151 , L_95 ) ;
fprintf ( V_151 , L_96 ) ;
fprintf ( V_151 , L_14 ) ;
fprintf ( V_151 , L_97 ) ;
fprintf ( V_151 , L_98 ) ;
fprintf ( V_151 , L_99 ) ;
fprintf ( V_151 , L_100 ) ;
fprintf ( V_151 , L_101 ) ;
fprintf ( V_151 , L_102 ) ;
fprintf ( V_151 , L_103 ) ;
#ifndef F_137
fprintf ( V_151 , L_104 ) ;
#endif
#ifdef F_137
F_143 () ;
#endif
}
static void
F_144 ( void )
{
printf ( V_156 L_105 V_152 L_49
L_14
L_37
L_14
L_37
L_14
L_37 ,
V_153 , F_139 () , V_157 -> V_158 ,
V_159 -> V_158 ) ;
}
void
F_145 ( const char * V_160 , ... )
{
T_30 V_161 ;
#ifdef F_137
F_138 () ;
#endif
fprintf ( V_154 , L_106 ) ;
va_start ( V_161 , V_160 ) ;
vfprintf ( V_154 , V_160 , V_161 ) ;
va_end ( V_161 ) ;
fprintf ( V_154 , L_14 ) ;
}
void
F_146 ( const char * V_160 , ... )
{
T_30 V_161 ;
#ifdef F_137
F_138 () ;
#endif
va_start ( V_161 , V_160 ) ;
vfprintf ( V_154 , V_160 , V_161 ) ;
fprintf ( V_154 , L_14 ) ;
va_end ( V_161 ) ;
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
if ( F_151 ( V_162 ) )
F_152 ( F_151 ( V_162 ) , NULL , TRUE ) ;
if ( F_151 ( V_163 ) )
F_152 ( F_151 ( V_163 ) , NULL , TRUE ) ;
}
return TRUE ;
}
void
F_153 ( T_31 * V_164 )
{
F_154 ( V_164 ) ;
F_155 ( V_164 ) ;
F_156 ( V_164 ) ;
}
void
F_157 ( T_11 V_165 )
{
F_158 ( V_165 ) ;
F_159 ( V_165 ) ;
V_166 = V_165 ;
}
void
F_160 ( T_11 V_167 )
{
F_161 ( V_167 ) ;
F_162 ( V_167 ) ;
if( V_167 != V_80 . V_167 ) {
V_80 . V_167 = V_167 ;
F_163 ( V_167 ) ;
F_25 () ;
}
}
static void
F_164 ( T_4 T_8 , T_9 V_26 V_24 , T_4 V_19 V_24 )
{
V_80 . V_168 = ! F_165 ( T_8 ) ;
}
static void
F_166 ( T_4 T_8 , T_9 V_26 V_24 , T_4 V_19 V_24 )
{
V_80 . V_169 = ! F_165 ( T_8 ) ;
}
static void
F_167 ( T_31 * V_164 )
{
if( V_164 -> V_170 > 10000 ) {
V_171 = ( T_1 * ) F_2 ( V_172 , V_173 ,
L_107 ,
F_34 () ,
F_35 () ) ;
F_168 ( F_169 ( V_171 ) , V_174 ) ;
}
F_170 () ;
F_154 ( NULL ) ;
F_155 ( NULL ) ;
F_156 ( NULL ) ;
F_111 ( FALSE ) ;
F_171 ( V_164 ) ;
F_104 ( FALSE ) ;
F_108 ( FALSE ) ;
F_84 ( V_164 ) ;
F_109 ( FALSE ) ;
F_172 () ;
}
static void
F_173 ( T_31 * V_164 V_24 )
{
if( V_171 != NULL ) {
F_174 ( V_171 ) ;
V_171 = NULL ;
}
}
static void
F_175 ( T_31 * V_164 V_24 )
{
F_176 () ;
F_109 ( TRUE ) ;
}
static void
F_177 ( T_31 * V_164 )
{
T_2 * V_175 ;
if ( ! V_164 -> V_176 && V_164 -> V_177 ) {
F_178 ( V_164 -> V_177 ) ;
V_175 = F_179 ( F_6 ( V_164 -> V_177 ) ) ;
F_180 ( V_175 ) ;
F_9 ( V_175 ) ;
}
F_153 ( V_164 ) ;
F_111 ( TRUE ) ;
}
static void
F_181 ( T_31 * V_164 )
{
T_2 * V_175 ;
if ( ! V_164 -> V_176 && V_164 -> V_177 ) {
F_178 ( V_164 -> V_177 ) ;
V_175 = F_179 ( F_6 ( V_164 -> V_177 ) ) ;
F_180 ( V_175 ) ;
F_9 ( V_175 ) ;
}
F_153 ( V_164 ) ;
}
static T_12 * F_182 (
const T_7 * V_178 ,
const T_7 * V_179 ,
const T_7 * V_180 ,
const T_7 * V_181 )
{
T_12 * V_182 = NULL ;
T_32 * V_183 ;
T_32 * V_184 ;
T_32 * V_185 ;
T_32 * V_186 ;
if( V_178 != NULL ) {
V_183 = F_183 ( - 1 , V_178 , FALSE , NULL ) ;
F_3 ( V_183 ) ;
V_182 = F_50 ( V_182 , V_183 ) ;
}
if( V_179 != NULL ) {
V_184 = F_183 ( - 1 , V_179 , FALSE , NULL ) ;
F_3 ( V_184 ) ;
V_182 = F_50 ( V_182 , V_184 ) ;
}
if( V_180 != NULL ) {
V_185 = F_183 ( - 1 , V_180 , FALSE , NULL ) ;
F_3 ( V_185 ) ;
V_182 = F_50 ( V_182 , V_185 ) ;
}
if( V_181 != NULL ) {
V_186 = F_183 ( - 1 , V_181 , FALSE , NULL ) ;
F_3 ( V_186 ) ;
V_182 = F_50 ( V_182 , V_186 ) ;
}
return V_182 ;
}
static void
F_184 ( T_33 * V_187 )
{
static T_12 * V_182 = NULL ;
F_185 ( ( T_31 * ) V_187 -> V_164 ) ;
if( V_182 == NULL ) {
V_182 = F_182 ( V_188 , V_189 , V_190 , V_191 ) ;
}
F_186 ( F_169 ( V_121 ) , V_182 ) ;
F_104 ( TRUE ) ;
F_108 ( TRUE ) ;
F_109 ( FALSE ) ;
}
static void
F_187 ( T_33 * V_187 )
{
F_185 ( ( T_31 * ) V_187 -> V_164 ) ;
F_104 ( TRUE ) ;
F_108 ( TRUE ) ;
F_111 ( TRUE ) ;
F_109 ( TRUE ) ;
}
static void
F_188 ( T_33 * V_187 )
{
T_31 * V_164 = ( T_31 * ) V_187 -> V_164 ;
static T_12 * V_182 = NULL ;
V_126 = FALSE ;
if ( ! V_164 -> V_176 && V_164 -> V_177 ) {
F_178 ( V_164 -> V_177 ) ;
}
F_104 ( FALSE ) ;
F_108 ( FALSE ) ;
F_153 ( V_164 ) ;
F_109 ( TRUE ) ;
if( V_182 == NULL ) {
V_182 = F_182 ( V_192 , V_193 , V_194 , V_195 ) ;
}
F_186 ( F_169 ( V_121 ) , V_182 ) ;
if( V_196 . V_197 ) {
F_117 () ;
}
}
static void
F_189 ( T_33 * V_187 V_24 )
{
F_109 ( FALSE ) ;
}
static void
F_190 ( T_33 * V_187 V_24 )
{
#if 0
capture_file *cf = (capture_file *)cap_session->cf;
#endif
static T_12 * V_182 = NULL ;
V_126 = FALSE ;
F_104 ( FALSE ) ;
F_108 ( FALSE ) ;
F_154 ( NULL ) ;
if( V_182 == NULL ) {
V_182 = F_182 ( V_192 , V_193 , V_194 , V_195 ) ;
}
F_186 ( F_169 ( V_121 ) , V_182 ) ;
if( V_196 . V_197 ) {
F_117 () ;
}
}
static void
F_191 ( T_33 * V_187 V_24 )
{
V_126 = TRUE ;
F_192 () ;
#ifdef F_106
F_193 () ;
F_194 () ;
#endif
}
static void
F_195 ( T_33 * V_187 V_24 )
{
static T_12 * V_182 = NULL ;
V_126 = FALSE ;
F_154 ( NULL ) ;
F_104 ( FALSE ) ;
F_108 ( FALSE ) ;
F_109 ( FALSE ) ;
if( V_182 == NULL ) {
V_182 = F_182 ( V_192 , V_193 , V_194 , V_195 ) ;
}
F_186 ( F_169 ( V_121 ) , V_182 ) ;
if( V_196 . V_197 ) {
F_117 () ;
}
}
static void
F_196 ( T_4 V_19 )
{
T_31 * V_164 = ( T_31 * ) V_19 ;
F_197 ( V_164 -> V_22 , V_109 , V_103 ) ;
F_198 ( V_164 -> V_22 -> V_108 , V_109 ) ;
if( V_164 -> V_198 &&
( V_164 -> V_199 != 0 || ( V_164 -> string && V_164 -> V_200 ) ) ) {
F_199 ( V_164 -> V_22 -> V_201 , V_164 -> V_199 ,
( V_202 * ) V_109 , V_164 -> V_22 -> V_108 ) ;
}
F_171 ( V_164 ) ;
}
static void
F_200 ( T_31 * V_164 )
{
while ( F_201 ( F_202 ( V_103 ) , 0 ) != NULL )
F_203 ( F_202 ( V_103 ) , 0 ) ;
F_204 ( V_103 , L_9 , NULL , NULL , V_109 ) ;
F_198 ( NULL , V_109 ) ;
F_171 ( V_164 ) ;
}
static void
F_205 ( T_31 * V_164 )
{
F_84 ( V_164 ) ;
}
static void
F_206 ( T_9 T_27 , T_4 V_19 , T_4 T_19 V_24 )
{
T_31 * V_164 = ( T_31 * ) V_19 ;
switch( T_27 ) {
case ( V_203 ) :
F_207 ( V_204 , V_205 , L_108 ) ;
F_208 ( V_164 ) ;
break;
case ( V_206 ) :
F_207 ( V_204 , V_205 , L_109 ) ;
F_167 ( V_164 ) ;
break;
case ( V_207 ) :
F_207 ( V_204 , V_205 , L_110 ) ;
F_173 ( V_164 ) ;
F_209 () ;
break;
case ( V_208 ) :
F_207 ( V_204 , V_205 , L_111 ) ;
F_175 ( V_164 ) ;
break;
case ( V_209 ) :
F_207 ( V_204 , V_205 , L_112 ) ;
F_177 ( V_164 ) ;
break;
case ( V_210 ) :
F_207 ( V_204 , V_205 , L_113 ) ;
F_175 ( V_164 ) ;
break;
case ( V_211 ) :
F_207 ( V_204 , V_205 , L_114 ) ;
F_177 ( V_164 ) ;
break;
case ( V_212 ) :
F_207 ( V_204 , V_205 , L_115 ) ;
break;
case ( V_213 ) :
F_207 ( V_204 , V_205 , L_116 ) ;
F_181 ( V_164 ) ;
break;
case ( V_214 ) :
F_207 ( V_204 , V_205 , L_117 ) ;
F_181 ( V_164 ) ;
break;
case ( V_215 ) :
F_196 ( V_164 ) ;
break;
case ( V_216 ) :
F_200 ( V_164 ) ;
break;
case ( V_217 ) :
F_205 ( V_164 ) ;
break;
case ( V_218 ) :
F_207 ( V_204 , V_205 , L_118 ) ;
break;
case ( V_219 ) :
F_207 ( V_204 , V_205 , L_119 ) ;
break;
case ( V_220 ) :
F_207 ( V_204 , V_205 , L_120 ) ;
break;
case ( V_221 ) :
F_207 ( V_204 , V_205 , L_121 ) ;
break;
case ( V_222 ) :
F_207 ( V_204 , V_205 , L_122 ) ;
break;
case ( V_223 ) :
F_207 ( V_204 , V_205 , L_123 ) ;
break;
case ( V_224 ) :
F_207 ( V_204 , V_205 , L_124 ) ;
break;
case ( V_225 ) :
F_207 ( V_204 , V_205 , L_125 ) ;
break;
default:
F_210 ( L_126 , T_27 ) ;
F_8 () ;
}
}
static void
F_211 ( T_9 T_27 , T_33 * V_187 , T_4 T_19 V_24 )
{
#ifdef F_212
T_34 * V_226 ;
#endif
switch( T_27 ) {
case ( V_227 ) :
F_207 ( V_204 , V_205 , L_127 ) ;
F_184 ( V_187 ) ;
break;
case ( V_228 ) :
F_207 ( V_204 , V_205 , L_128 ) ;
F_187 ( V_187 ) ;
#ifdef F_212
V_226 = ( T_34 * ) F_213 ( V_229 , NULL ) ;
F_214 ( V_226 , F_183 ( - 1 , V_190 , FALSE , NULL ) ) ;
#endif
break;
case ( V_230 ) :
break;
case ( V_231 ) :
F_207 ( V_204 , V_205 , L_129 ) ;
F_188 ( V_187 ) ;
break;
case ( V_232 ) :
F_207 ( V_204 , V_205 , L_130 ) ;
F_189 ( V_187 ) ;
break;
case ( V_233 ) :
F_207 ( V_204 , V_205 , L_131 ) ;
break;
case ( V_234 ) :
F_207 ( V_204 , V_205 , L_132 ) ;
F_190 ( V_187 ) ;
break;
case ( V_235 ) :
F_207 ( V_204 , V_205 , L_133 ) ;
#ifdef F_212
V_226 = ( T_34 * ) F_213 ( V_229 , NULL ) ;
F_214 ( V_226 , F_183 ( - 1 , V_195 , FALSE , NULL ) ) ;
#endif
F_191 ( V_187 ) ;
break;
case ( V_236 ) :
F_207 ( V_204 , V_205 , L_134 ) ;
F_195 ( V_187 ) ;
break;
default:
F_210 ( L_135 , T_27 ) ;
F_8 () ;
}
}
static void
F_215 ( T_3 * V_158 )
{
F_11 ( V_158 , L_136 ) ;
F_216 ( V_158 ,
#ifdef F_217
L_137 , F_217 , V_237 ,
V_238 ) ;
#else
L_138 ) ;
void
F_218 ( T_3 * V_158 )
{
F_219 ( V_158 ) ;
F_11 ( V_158 , L_139 ) ;
#ifdef F_220
#ifdef F_221
F_11 ( V_158 , L_140 ) ;
#else
F_11 ( V_158 , L_136 ) ;
F_11 ( V_158 , F_222 () ) ;
#endif
#else
F_11 ( V_158 , L_141 ) ;
#endif
F_11 ( V_158 , L_139 ) ;
#ifdef F_223
F_224 ( V_158 ) ;
#else
F_11 ( V_158 , L_142 ) ;
#endif
}
static void
F_225 ( T_3 * V_158 )
{
F_226 ( V_158 ) ;
#ifdef F_223
F_11 ( V_158 , L_139 ) ;
F_227 ( V_158 ) ;
#endif
if( F_228 () ) {
F_11 ( V_158 , L_139 ) ;
F_229 ( V_158 ) ;
}
}
static T_35 *
F_230 ( char * * V_239 , char * * V_240 )
{
int V_241 , V_242 ;
int V_243 , V_244 ;
int V_245 , V_246 ;
int V_247 , V_248 ;
char * V_249 , * V_250 ;
char * V_251 , * V_252 ;
int V_253 , V_254 ;
T_35 * V_255 ;
F_231 () ;
V_255 = F_232 ( & V_241 , & V_242 , & V_249 ,
& V_253 , & V_254 , & V_250 ) ;
if ( V_249 != NULL ) {
if ( V_241 != 0 ) {
F_2 ( V_35 , V_7 ,
L_143 , V_249 ,
F_233 ( V_241 ) ) ;
}
if ( V_242 != 0 ) {
F_2 ( V_35 , V_7 ,
L_144 , V_249 ,
F_233 ( V_242 ) ) ;
}
}
if ( V_250 != NULL ) {
if ( V_253 != 0 ) {
F_2 ( V_35 , V_7 ,
L_145 , V_250 ,
F_233 ( V_253 ) ) ;
}
if ( V_254 != 0 ) {
F_2 ( V_35 , V_7 ,
L_146 , V_250 ,
F_233 ( V_254 ) ) ;
}
F_9 ( V_250 ) ;
V_250 = NULL ;
}
#ifdef F_137
if ( V_255 -> V_256 == V_257 ) {
F_138 () ;
}
#endif
F_234 ( V_258 , & V_251 , & V_243 ) ;
if ( V_251 != NULL ) {
F_2 ( V_35 , V_7 ,
L_147 , V_251 ,
F_233 ( V_243 ) ) ;
F_9 ( V_251 ) ;
}
F_234 ( V_259 , & V_252 , & V_244 ) ;
if ( V_252 != NULL ) {
F_2 ( V_35 , V_7 ,
L_148 , V_252 ,
F_233 ( V_244 ) ) ;
F_9 ( V_252 ) ;
}
F_235 ( V_239 , & V_245 , & V_246 ,
V_240 , & V_247 , & V_248 ) ;
if ( * V_239 != NULL ) {
if ( V_245 != 0 ) {
F_2 ( V_35 , V_7 ,
L_149 ,
* V_239 , F_233 ( V_245 ) ) ;
}
if ( V_246 != 0 ) {
F_2 ( V_35 , V_7 ,
L_150 ,
* V_239 , F_233 ( V_246 ) ) ;
}
F_9 ( * V_239 ) ;
* V_239 = NULL ;
}
if ( * V_240 != NULL ) {
if ( V_247 != 0 ) {
F_2 ( V_35 , V_7 ,
L_151 , * V_240 ,
F_233 ( V_247 ) ) ;
}
if ( V_248 != 0 ) {
F_2 ( V_35 , V_7 ,
L_152 , * V_240 ,
F_233 ( V_248 ) ) ;
}
F_9 ( * V_240 ) ;
* V_240 = NULL ;
}
return V_255 ;
}
static void
#ifdef F_137
F_236 ( T_2 * V_260 )
#else
check_and_warn_user_startup( T_2 * V_260 V_24 )
#endif
{
T_2 * V_261 , * V_262 ;
T_4 V_263 ;
if ( F_237 () && V_80 . V_168 ) {
V_261 = F_238 () ;
V_262 = F_239 () ;
V_263 = F_2 ( V_35 , V_7 ,
L_153
L_154
L_155
L_156
L_157 , V_261 , V_262 ) ;
F_9 ( V_261 ) ;
F_9 ( V_262 ) ;
F_240 ( V_263 , L_158 ) ;
F_36 ( V_263 , F_164 , NULL ) ;
}
#ifdef F_137
if ( ! F_241 () && ! V_260 && ! F_242 () && V_80 . V_169 && F_243 () >= 6 ) {
V_263 = F_2 ( V_35 , V_7 ,
L_159
L_160 ) ;
F_240 ( V_263 , L_158 ) ;
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
#ifdef F_137
T_36 V_271 ;
#endif
char * V_272 ;
int V_273 ;
char * V_239 , * V_240 ;
int V_274 ;
#ifdef F_106
T_11 V_275 = FALSE ;
T_11 V_276 = FALSE ;
T_12 * V_277 ;
T_2 * V_278 ;
#else
T_11 V_279 = FALSE ;
#ifdef F_137
#ifdef F_223
T_2 * V_278 ;
#endif
#endif
#endif
T_9 V_280 = 280 , V_281 = 95 , V_282 = 75 ;
T_2 * V_283 , * V_260 = NULL , * V_284 = NULL , * V_285 = NULL , * V_286 = NULL ;
T_37 * V_287 = NULL ;
T_11 V_288 = FALSE ;
T_35 * V_255 ;
char V_289 ;
T_1 * V_290 = NULL ;
T_38 V_291 ;
T_21 V_292 = 0 ;
T_39 V_293 = V_89 ;
T_37 * V_294 = NULL ;
int V_295 ;
int V_296 ;
#ifdef F_212
T_34 * V_226 ;
#endif
#ifdef F_106
#if F_141 ( F_137 ) || F_141 ( F_140 )
#define F_244 "B:"
#else
#define F_244 ""
#endif
#else
#define F_244 ""
#endif
#ifdef F_142
#define F_245 "A:"
#else
#define F_245 ""
#endif
#ifdef F_140
#define F_246 "I"
#else
#define F_246 ""
#endif
#define F_247 "a:" OPTSTRING_A "b:" OPTSTRING_B "c:C:Df:g:Hhi:" OPTSTRING_I "jJ:kK:lLm:nN:o:P:pr:R:Ss:t:u:vw:X:y:Y:z:"
static const char V_297 [] = F_247 ;
setlocale ( V_298 , L_9 ) ;
#ifdef F_137
F_248 ( V_264 , V_265 ) ;
F_249 () ;
#endif
F_250 () ;
F_251 () ;
V_266 = F_252 ( V_265 [ 0 ] , main ) ;
F_253 () ;
F_254 ( & V_299 ) ;
#ifdef F_137
F_255 () ;
F_256 () ;
#ifdef F_223
V_300 = F_257 () ;
switch ( V_300 ) {
case V_301 :
V_302 = F_258 ( & V_274 , & V_278 ) ;
if ( V_302 == NULL || F_259 ( V_302 ) == 0 ) {
if ( V_274 == V_303 && V_278 != NULL ) {
F_2 ( V_6 , V_7 , L_37 , L_161 ) ;
F_9 ( V_278 ) ;
}
V_304 = NULL ;
} else {
V_304 = F_260 ( V_302 ) ;
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
V_157 = F_10 ( L_162 ) ;
F_261 ( V_157 , F_215 , F_218 ) ;
V_159 = F_10 ( L_163 ) ;
F_262 ( V_159 , F_225 ) ;
#ifdef F_137
F_263 ( V_156 L_105 V_152 L_49
L_14
L_37
L_14
L_37 ,
V_153 , V_157 -> V_158 , V_159 -> V_158 ) ;
F_264 ( F_265 ( 1 , 1 ) , & V_271 ) ;
#endif
F_266 ( TRUE ) ;
F_267 ( & V_272 , & V_273 ) ;
if ( V_272 != NULL && V_273 != 0 ) {
F_2 ( V_35 , V_7 ,
L_164 ,
V_272 , F_233 ( V_273 ) ) ;
}
V_305 = 0 ;
V_295 = V_306 ;
while ( ( V_268 = F_268 ( V_264 , V_265 , V_297 ) ) != - 1 ) {
switch ( V_268 ) {
case 'C' :
if ( F_269 ( V_307 , FALSE ) ) {
F_270 ( V_307 ) ;
} else {
F_145 ( L_165 , V_307 ) ;
exit ( 1 ) ;
}
break;
case 'D' :
#ifdef F_106
V_277 = F_271 ( & V_274 , & V_278 , F_172 ) ;
if ( V_277 == NULL ) {
switch ( V_274 ) {
case V_308 :
case V_309 :
F_145 ( L_37 , V_278 ) ;
F_9 ( V_278 ) ;
break;
case V_310 :
F_145 ( L_166 ) ;
break;
}
exit ( 2 ) ;
}
#ifdef F_137
F_138 () ;
#endif
F_272 ( V_277 ) ;
F_273 ( V_277 ) ;
#ifdef F_137
F_143 () ;
#endif
exit ( 0 ) ;
#else
V_279 = TRUE ;
V_269 = TRUE ;
#endif
break;
case 'h' :
F_136 ( TRUE ) ;
exit ( 0 ) ;
break;
#ifdef F_137
case 'i' :
if ( strcmp ( V_307 , L_167 ) == 0 )
F_274 ( TRUE ) ;
break;
#endif
case 'P' :
V_296 = F_275 ( V_268 , V_307 ) ;
if( V_296 != 0 ) {
F_145 ( L_168 , V_307 ) ;
exit ( V_296 ) ;
}
break;
case 'v' :
#ifdef F_137
F_138 () ;
#endif
F_144 () ;
#ifdef F_137
F_143 () ;
#endif
exit ( 0 ) ;
break;
case 'X' :
F_276 ( V_307 ) ;
break;
case '?' :
break;
}
}
F_277 ( & V_272 , & V_273 ) ;
if ( V_272 != NULL && V_273 != 0 ) {
F_2 ( V_35 , V_7 ,
L_169 ,
V_272 , F_233 ( V_273 ) ) ;
}
if ( V_80 . V_311 &&
F_278 ( V_80 . V_311 ) == V_312 ) {
F_180 ( V_80 . V_311 ) ;
} else {
F_180 ( F_279 () ) ;
}
V_306 = V_295 ;
V_305 = 1 ;
#if ! F_280 ( 2 , 31 , 0 )
F_281 ( NULL ) ;
#endif
setlocale ( V_298 , L_9 ) ;
F_282 ( & V_264 , & V_265 ) ;
F_283 ( F_206 , NULL ) ;
#ifdef F_106
F_284 ( F_211 , NULL ) ;
#endif
F_283 ( V_313 , NULL ) ;
#ifdef F_106
F_284 ( V_314 , NULL ) ;
#endif
V_291 = ( T_38 )
( V_315 |
V_316 |
V_317 |
V_318 |
V_319 |
V_205 |
V_320 | V_321 ) ;
F_285 ( NULL ,
V_291 ,
V_322 , NULL ) ;
F_285 ( V_204 ,
V_291 ,
V_322 , NULL ) ;
#ifdef F_106
F_285 ( V_323 ,
V_291 ,
V_322 , NULL ) ;
F_285 ( V_324 ,
V_291 ,
V_322 , NULL ) ;
F_286 ( & V_196 ) ;
F_287 ( & V_122 , ( void * ) & V_18 ) ;
#endif
F_288 () ;
V_20 = F_289 () ;
if ( * V_20 != '\0' ) {
V_270 = 1000 ;
}
V_290 = F_290 ( L_170 ) ;
if ( V_266 != NULL ) {
F_2 ( V_35 , V_7 ,
L_171
L_172
L_173 ,
V_266 ) ;
F_9 ( V_266 ) ;
}
F_291 ( V_325 , NULL , ( T_4 ) V_290 ) ;
F_292 ( V_326 , V_327 ,
F_291 , ( T_4 ) V_290 ,
V_328 , V_329 , V_330 ,
V_331 ) ;
F_291 ( V_332 , NULL , ( T_4 ) V_290 ) ;
#ifdef F_293
F_294 () ;
#endif
F_295 () ;
F_291 ( V_333 , NULL , ( T_4 ) V_290 ) ;
V_255 = F_230 ( & V_239 , & V_240 ) ;
V_334 = F_296 ( V_255 -> V_335 , F_147 , NULL ) ;
F_291 ( V_336 , NULL , ( T_4 ) V_290 ) ;
F_297 () ;
F_298 ( & V_18 ) ;
F_299 () ;
while ( ( V_268 = F_268 ( V_264 , V_265 , V_297 ) ) != - 1 ) {
switch ( V_268 ) {
case 'a' :
case 'b' :
case 'c' :
case 'f' :
case 'k' :
case 'H' :
case 'p' :
case 'i' :
#ifdef F_140
case 'I' :
#endif
#ifdef F_142
case 'A' :
#endif
case 's' :
case 'S' :
case 'w' :
case 'y' :
#if F_141 ( F_137 ) || F_141 ( F_140 )
case 'B' :
#endif
#ifdef F_106
V_296 = F_300 ( & V_196 , V_268 , V_307 ,
& V_275 ) ;
if( V_296 != 0 ) {
exit ( V_296 ) ;
}
#else
V_279 = TRUE ;
V_269 = TRUE ;
#endif
break;
#if F_141 ( V_337 ) || F_141 ( V_338 )
case 'K' :
F_301 ( V_307 ) ;
break;
#endif
case 'C' :
break;
case 'j' :
V_293 = V_91 ;
break;
case 'g' :
V_292 = F_302 ( V_307 , L_174 ) ;
break;
case 'J' :
V_286 = V_307 ;
break;
case 'l' :
#ifdef F_106
V_166 = TRUE ;
#else
V_279 = TRUE ;
V_269 = TRUE ;
#endif
break;
case 'L' :
#ifdef F_106
V_276 = TRUE ;
#else
V_279 = TRUE ;
V_269 = TRUE ;
#endif
break;
case 'm' :
F_9 ( V_255 -> V_339 ) ;
V_255 -> V_339 = F_6 ( V_307 ) ;
break;
case 'n' :
V_340 . V_341 = FALSE ;
V_340 . V_342 = FALSE ;
V_340 . V_343 = FALSE ;
V_340 . V_344 = FALSE ;
break;
case 'N' :
V_289 = F_303 ( V_307 , & V_340 ) ;
if ( V_289 != '\0' ) {
F_145 ( L_175 ,
V_289 ) ;
exit ( 1 ) ;
}
break;
case 'o' :
switch ( F_304 ( V_307 ) ) {
case V_345 :
break;
case V_346 :
F_145 ( L_176 , V_307 ) ;
exit ( 1 ) ;
break;
case V_347 :
switch ( F_305 ( V_307 ) ) {
case V_345 :
break;
case V_346 :
F_145 ( L_176 , V_307 ) ;
exit ( 1 ) ;
break;
case V_347 :
case V_348 :
F_145 ( L_177 ,
V_307 ) ;
exit ( 1 ) ;
break;
default:
F_8 () ;
}
break;
case V_348 :
F_145 ( L_178 ,
V_307 ) ;
exit ( 1 ) ;
break;
default:
F_8 () ;
}
break;
case 'P' :
break;
case 'r' :
V_260 = F_6 ( V_307 ) ;
break;
case 'R' :
V_284 = V_307 ;
break;
case 't' :
if ( strcmp ( V_307 , L_179 ) == 0 )
F_68 ( V_79 ) ;
else if ( strcmp ( V_307 , L_180 ) == 0 )
F_68 ( V_349 ) ;
else if ( strcmp ( V_307 , L_181 ) == 0 )
F_68 ( V_350 ) ;
else if ( strcmp ( V_307 , L_182 ) == 0 )
F_68 ( V_351 ) ;
else if ( strcmp ( V_307 , L_183 ) == 0 )
F_68 ( V_352 ) ;
else if ( strcmp ( V_307 , L_184 ) == 0 )
F_68 ( V_353 ) ;
else if ( strcmp ( V_307 , L_185 ) == 0 )
F_68 ( V_354 ) ;
else if ( strcmp ( V_307 , L_186 ) == 0 )
F_68 ( V_355 ) ;
else {
F_145 ( L_187 , V_307 ) ;
F_146 ( L_188 ) ;
F_146 ( L_189 ) ;
F_146 ( L_190 ) ;
exit ( 1 ) ;
}
break;
case 'u' :
if ( strcmp ( V_307 , L_191 ) == 0 )
F_306 ( V_356 ) ;
else if ( strcmp ( V_307 , L_192 ) == 0 )
F_306 ( V_357 ) ;
else {
F_145 ( L_193 , V_307 ) ;
F_146 ( L_194 ) ;
exit ( 1 ) ;
}
break;
case 'X' :
break;
case 'Y' :
V_285 = V_307 ;
break;
case 'z' :
if ( ! F_307 ( V_307 ) ) {
F_145 ( L_195 ) ;
F_146 ( L_196 ) ;
F_308 () ;
exit ( 1 ) ;
}
break;
default:
case '?' :
V_269 = TRUE ;
break;
}
}
if ( ! V_269 ) {
V_264 -= V_306 ;
V_265 += V_306 ;
if ( V_264 >= 1 ) {
if ( V_260 != NULL ) {
F_145 ( L_197 ) ;
V_269 = TRUE ;
} else {
#ifndef F_212
V_260 = F_6 ( V_265 [ 0 ] ) ;
#endif
}
V_264 -- ;
V_265 ++ ;
}
if ( V_264 != 0 ) {
F_145 ( L_198 , V_265 [ 0 ] ) ;
V_269 = TRUE ;
}
}
if ( V_269 ) {
#ifndef F_106
if ( V_279 ) {
F_145 ( L_199 ) ;
}
#endif
F_136 ( FALSE ) ;
exit ( 1 ) ;
}
#ifdef F_106
F_309 ( F_172 ) ;
if ( V_275 && V_276 ) {
F_145 ( L_200 ) ;
exit ( 1 ) ;
}
if ( V_276 ) {
if ( V_260 ) {
F_145 ( L_201 ) ;
exit ( 1 ) ;
}
if ( V_196 . V_358 ) {
F_145 ( L_202 ) ;
exit ( 1 ) ;
}
} else {
if ( V_275 && V_260 ) {
F_145 ( L_203 ) ;
exit ( 1 ) ;
}
if ( V_196 . V_358 ) {
if ( V_196 . V_359 == NULL ) {
F_145 ( L_204 ) ;
V_196 . V_358 = FALSE ;
}
if ( ! V_196 . V_360 && ! V_196 . V_361 ) {
F_145 ( L_205 ) ;
}
}
}
if ( V_275 || V_276 ) {
V_296 = F_310 ( & V_196 ,
( ( V_255 -> V_362 ) && ( * V_255 -> V_362 != '\0' ) ) ? F_311 ( V_255 -> V_362 ) : NULL ) ;
if ( V_296 != 0 ) {
exit ( V_296 ) ;
}
}
if ( V_276 ) {
T_40 * V_363 ;
T_21 V_364 ;
T_41 V_365 ;
for ( V_364 = 0 ; V_364 < V_196 . V_366 -> V_70 ; V_364 ++ ) {
V_365 = F_312 ( V_196 . V_366 , T_41 , V_364 ) ;
if ( V_365 . V_367 ) {
#if F_141 ( F_140 )
V_363 = F_313 ( V_365 . V_106 , V_365 . V_368 , & V_278 , F_172 ) ;
#else
V_363 = F_313 ( V_365 . V_106 , FALSE , & V_278 , F_172 ) ;
#endif
if ( V_363 == NULL ) {
F_145 ( L_37 , V_278 ) ;
F_9 ( V_278 ) ;
exit ( 2 ) ;
}
if ( V_363 -> V_369 == NULL ) {
F_145 ( L_206 , V_365 . V_106 ) ;
exit ( 2 ) ;
}
#ifdef F_137
F_138 () ;
#endif
#if F_141 ( F_140 )
F_314 ( V_363 , V_365 . V_106 , V_365 . V_368 ) ;
#else
F_314 ( V_363 , V_365 . V_106 , FALSE ) ;
#endif
#ifdef F_137
F_143 () ;
#endif
F_315 ( V_363 ) ;
}
}
exit ( 0 ) ;
}
F_316 ( & V_196 , V_370 ) ;
F_317 ( & V_196 ) ;
#endif
F_318 () ;
#ifdef F_106
if ( ( V_196 . V_371 == 0 ) &&
( ( V_110 . V_362 != NULL ) && ( * V_255 -> V_362 != '\0' ) ) ) {
T_21 V_364 ;
T_41 V_365 ;
for ( V_364 = 0 ; V_364 < V_196 . V_366 -> V_70 ; V_364 ++ ) {
V_365 = F_312 ( V_196 . V_366 , T_41 , V_364 ) ;
if ( ! V_365 . V_372 && strstr ( V_110 . V_362 , V_365 . V_106 ) != NULL ) {
V_365 . V_367 = TRUE ;
V_196 . V_371 ++ ;
V_196 . V_366 = F_319 ( V_196 . V_366 , V_364 ) ;
F_320 ( V_196 . V_366 , V_364 , V_365 ) ;
break;
}
}
}
if ( V_196 . V_371 == 0 && V_196 . V_366 -> V_70 == 1 ) {
T_41 V_365 = F_312 ( V_196 . V_366 , T_41 , 0 ) ;
V_365 . V_367 = TRUE ;
V_196 . V_371 ++ ;
V_196 . V_366 = F_319 ( V_196 . V_366 , 0 ) ;
F_320 ( V_196 . V_366 , 0 , V_365 ) ;
}
#endif
if ( V_239 == NULL && V_240 == NULL ) {
F_321 () ;
}
F_322 ( & V_18 . V_37 , V_255 -> V_54 , TRUE ) ;
V_283 = F_323 ( V_373 ) ;
#if F_324 ( 3 , 0 , 0 )
#else
F_325 ( V_283 ) ;
F_9 ( V_283 ) ;
V_283 = F_326 ( V_373 , FALSE ) ;
F_325 ( V_283 ) ;
#endif
F_9 ( V_283 ) ;
F_327 () ;
F_328 () ;
F_329 () ;
F_174 ( V_290 ) ;
F_330 ( V_280 , V_281 , V_282 , V_255 ) ;
F_331 ( & V_272 , & V_273 ) ;
if ( V_272 != NULL && V_273 != 0 ) {
F_2 ( V_35 , V_7 ,
L_169 ,
V_272 , F_233 ( V_273 ) ) ;
}
F_163 ( V_80 . V_167 ) ;
F_332 () ;
F_333 () ;
#ifdef F_106
F_157 ( V_166 ) ;
#endif
switch ( F_334 () ) {
case V_374 :
break;
case V_375 :
case V_376 :
default:
V_80 . V_377 = 0 ;
}
F_335 ( V_121 ) ;
F_336 () ;
F_337 () ;
#ifdef F_106
F_338 () ;
#endif
F_129 ( V_121 ) ;
F_296 ( V_270 , F_149 , NULL ) ;
if ( V_260 ) {
F_339 ( TRUE ) ;
F_236 ( V_260 ) ;
if ( V_284 != NULL ) {
if ( ! F_340 ( V_284 , & V_287 ) ) {
F_341 ( V_121 , V_284 ) ;
V_288 = TRUE ;
}
}
if ( ! V_288 ) {
if ( F_342 ( & V_18 , V_260 , FALSE , & V_274 ) == V_378 ) {
V_18 . V_287 = V_287 ;
F_343 () ;
switch ( F_344 ( & V_18 , FALSE ) ) {
case V_379 :
case V_380 :
if( V_292 != 0 ) {
F_345 ( & V_18 , V_292 ) ;
} else if ( V_286 != NULL ) {
if ( ! F_340 ( V_286 , & V_294 ) ) {
F_341 ( V_121 , V_286 ) ;
} else {
F_346 ( & V_18 , V_294 , V_293 ) ;
}
}
break;
case V_381 :
exit ( 0 ) ;
break;
}
if ( ! F_347 ( V_260 ) ) {
char * V_382 = V_260 ;
char * V_383 = F_348 () ;
V_260 = F_27 ( L_207 , V_383 , V_384 , V_260 ) ;
F_9 ( V_382 ) ;
F_9 ( V_383 ) ;
}
V_267 = F_179 ( V_260 ) ;
F_180 ( V_267 ) ;
F_9 ( V_260 ) ;
V_260 = NULL ;
} else {
if ( V_287 != NULL )
F_349 ( V_287 ) ;
V_18 . V_287 = NULL ;
F_339 ( FALSE ) ;
F_104 ( FALSE ) ;
F_108 ( FALSE ) ;
}
}
} else {
#ifdef F_106
if ( V_275 ) {
if ( V_196 . V_359 != NULL ) {
V_267 = F_179 ( F_6 ( V_196 . V_359 ) ) ;
F_180 ( V_267 ) ;
F_9 ( V_267 ) ;
}
F_339 ( FALSE ) ;
F_236 ( V_260 ) ;
if ( V_196 . V_385 -> V_70 == 0 )
F_350 ( & V_196 ) ;
if ( F_351 ( & V_196 , & V_122 , F_172 ) ) {
F_343 () ;
}
} else {
F_339 ( FALSE ) ;
F_236 ( V_260 ) ;
F_104 ( FALSE ) ;
F_108 ( FALSE ) ;
}
if ( ! V_275 && ! V_196 . V_386 . V_387 ) {
V_196 . V_386 . V_387 = F_6 ( F_289 () ) ;
}
#else
F_339 ( FALSE ) ;
F_236 ( V_260 ) ;
F_104 ( FALSE ) ;
F_108 ( FALSE ) ;
#endif
}
if ( V_285 ) {
T_1 * V_1 ;
V_1 = F_352 ( F_353 ( F_19 ( F_20 ( V_121 ) , V_388 ) ) ) ;
F_14 ( F_15 ( V_1 ) , V_285 ) ;
F_16 ( & V_18 , V_285 , FALSE ) ;
}
F_354 () ;
F_266 ( FALSE ) ;
#ifdef F_212
V_226 = ( T_34 * ) F_213 ( V_229 , NULL ) ;
F_214 ( V_226 , F_183 ( - 1 , V_195 , FALSE , NULL ) ) ;
F_355 ( V_226 ) ;
#endif
F_207 ( V_204 , V_319 , L_208 ) ;
#ifdef F_106
F_356 () ;
#endif
F_357 () ;
F_358 () ;
#ifdef F_106
F_359 () ;
#endif
F_360 () ;
F_361 () ;
F_362 ( & V_299 ) ;
#ifdef F_137
F_363 ( V_121 ) ;
#ifdef F_212
F_364 ( V_226 ) ;
#endif
F_365 () ;
F_366 () ;
F_143 () ;
#endif
exit ( 0 ) ;
}
int T_42
F_367 ( struct V_389 * V_390 ,
struct V_389 * V_391 ,
char * V_392 ,
int V_393 )
{
T_43 V_394 ;
F_368 () ;
memset ( & V_394 , 0 , sizeof( V_394 ) ) ;
V_394 . V_395 = sizeof( V_394 ) ;
V_394 . V_396 = V_397 ;
F_369 ( & V_394 ) ;
F_370 ( L_209 ) ;
F_371 ( FALSE ) ;
F_372 ( FALSE ) ;
return main ( V_398 , V_399 ) ;
}
static void
V_322 ( const char * V_400 , T_38 V_401 ,
const char * V_402 , T_4 T_19 V_24 )
{
T_44 V_403 ;
struct V_404 * V_405 ;
const char * V_406 ;
if( ( V_401 & V_407 & V_110 . V_408 ) == 0 &&
V_110 . V_408 != 0 ) {
return;
}
#ifdef F_137
if ( V_110 . V_256 != V_409 || V_401 & V_315 ) {
F_138 () ;
}
if ( F_373 () ) {
#endif
switch( V_401 & V_407 ) {
case V_315 :
V_406 = L_210 ;
break;
case V_316 :
V_406 = L_211 ;
break;
case V_317 :
V_406 = L_212 ;
break;
case V_318 :
V_406 = L_213 ;
break;
case V_319 :
V_406 = L_214 ;
break;
case V_205 :
V_406 = L_215 ;
break;
default:
fprintf ( V_154 , L_216 , V_401 ) ;
V_406 = NULL ;
F_8 () ;
}
time ( & V_403 ) ;
V_405 = localtime ( & V_403 ) ;
fprintf ( V_154 , L_217 ,
V_405 -> V_410 , V_405 -> V_411 , V_405 -> V_412 ,
V_400 != NULL ? V_400 : L_9 ,
V_406 , V_402 ) ;
#ifdef F_137
if( V_401 & V_315 ) {
printf ( L_218 ) ;
F_374 () ;
}
} else {
F_375 ( V_400 , V_401 , V_402 , T_19 ) ;
}
#endif
}
static void F_376 ( T_1 * T_10 , T_4 V_19 ) {
F_377 ( F_378 ( V_19 ) , T_10 ) ;
}
static T_1 * F_379 ( T_9 V_413 )
{
switch( V_413 ) {
case ( V_414 ) :
return NULL ;
case ( V_415 ) :
return V_162 ;
case ( V_416 ) :
return V_163 ;
case ( V_417 ) :
return V_103 ;
default:
F_8 () ;
return NULL ;
}
}
void F_332 ( void ) {
T_1 * V_418 , * V_419 ;
T_1 * V_420 , * V_421 ;
T_11 V_422 = FALSE ;
F_363 ( V_423 ) ;
F_380 ( F_20 ( V_424 ) ) ;
F_380 ( F_20 ( V_425 ) ) ;
F_380 ( F_20 ( V_426 ) ) ;
F_380 ( F_20 ( V_427 ) ) ;
F_380 ( F_20 ( V_162 ) ) ;
F_380 ( F_20 ( V_163 ) ) ;
F_380 ( F_20 ( V_103 ) ) ;
F_380 ( F_20 ( V_428 ) ) ;
F_380 ( F_20 ( V_429 ) ) ;
F_380 ( F_20 ( V_430 ) ) ;
F_380 ( F_20 ( V_431 ) ) ;
F_380 ( F_20 ( V_432 ) ) ;
F_380 ( F_20 ( V_433 ) ) ;
F_381 ( F_378 ( V_423 ) , F_376 , V_423 ) ;
F_381 ( F_378 ( V_429 ) , F_376 , V_429 ) ;
F_381 ( F_378 ( V_430 ) , F_376 , V_430 ) ;
F_381 ( F_378 ( V_431 ) , F_376 , V_431 ) ;
F_381 ( F_378 ( V_432 ) , F_376 , V_432 ) ;
F_382 ( V_428 ) ;
F_383 ( F_384 ( V_423 ) , V_424 , FALSE , TRUE , 0 ) ;
F_383 ( F_384 ( V_423 ) , V_425 , FALSE , TRUE , 0 ) ;
if ( ! V_110 . V_434 ) {
F_383 ( F_384 ( V_423 ) , V_426 , FALSE , TRUE , 1 ) ;
}
F_383 ( F_384 ( V_423 ) , V_427 , FALSE , TRUE , 1 ) ;
switch( V_110 . V_435 ) {
case ( V_436 ) :
V_129 = V_429 ;
V_132 = V_430 ;
V_422 = FALSE ;
break;
case ( V_437 ) :
V_129 = V_429 ;
V_132 = V_431 ;
V_422 = FALSE ;
break;
case ( V_438 ) :
V_129 = V_429 ;
V_132 = V_431 ;
V_422 = TRUE ;
break;
case ( V_439 ) :
V_129 = V_431 ;
V_132 = V_429 ;
V_422 = FALSE ;
break;
case ( V_440 ) :
V_129 = V_431 ;
V_132 = V_429 ;
V_422 = TRUE ;
break;
case ( V_441 ) :
V_129 = V_431 ;
V_132 = V_432 ;
V_422 = FALSE ;
break;
default:
V_129 = NULL ;
V_132 = NULL ;
F_8 () ;
}
if ( V_422 ) {
V_418 = V_132 ;
V_420 = F_379 ( V_110 . V_442 ) ;
V_421 = F_379 ( V_110 . V_443 ) ;
V_419 = F_379 ( V_110 . V_444 ) ;
} else {
V_418 = F_379 ( V_110 . V_442 ) ;
V_419 = V_132 ;
V_420 = F_379 ( V_110 . V_443 ) ;
V_421 = F_379 ( V_110 . V_444 ) ;
}
if ( V_418 != NULL )
F_385 ( F_128 ( V_129 ) , V_418 ) ;
if ( V_419 != NULL )
F_386 ( F_128 ( V_129 ) , V_419 ) ;
if ( V_420 != NULL )
F_387 ( F_128 ( V_132 ) , V_420 , TRUE , TRUE ) ;
if ( V_421 != NULL )
F_388 ( F_128 ( V_132 ) , V_421 , FALSE , FALSE ) ;
F_383 ( F_384 ( V_423 ) , V_129 , TRUE , TRUE , 0 ) ;
F_383 ( F_384 ( V_423 ) , V_433 , TRUE , TRUE , 0 ) ;
F_383 ( F_384 ( V_423 ) , V_428 , FALSE , TRUE , 0 ) ;
if ( V_110 . V_434 ) {
F_383 ( F_384 ( V_428 ) , V_426 , FALSE , TRUE , 1 ) ;
}
F_389 ( V_428 ) ;
F_110 () ;
F_390 ( V_423 ) ;
}
static void
F_391 ( T_1 * T_10 , T_4 V_19 )
{
T_11 * V_445 = ( T_11 * ) V_19 ;
if ( ! * V_445 ) {
if ( F_392 ( T_10 ) )
* V_445 = TRUE ;
}
}
void
F_110 ( void )
{
T_11 V_446 ;
if ( V_80 . V_447 ) {
F_390 ( V_425 ) ;
} else {
F_363 ( V_425 ) ;
}
F_393 ( V_428 ) ;
if ( V_80 . V_448 ) {
F_390 ( V_426 ) ;
} else {
F_363 ( V_426 ) ;
}
if ( V_80 . V_449 ) {
F_390 ( V_427 ) ;
} else {
F_363 ( V_427 ) ;
}
if ( V_80 . V_450 && V_117 ) {
F_390 ( V_162 ) ;
} else {
F_363 ( V_162 ) ;
}
if ( V_80 . V_451 && V_117 ) {
F_390 ( V_163 ) ;
} else {
F_363 ( V_163 ) ;
}
if ( V_80 . V_452 && V_117 ) {
F_390 ( V_103 ) ;
} else {
F_363 ( V_103 ) ;
}
if ( V_117 ) {
F_390 ( V_129 ) ;
} else {
F_363 ( V_129 ) ;
}
V_446 = FALSE ;
F_381 ( F_378 ( V_132 ) , F_391 ,
& V_446 ) ;
if ( V_446 ) {
F_390 ( V_132 ) ;
} else {
F_363 ( V_132 ) ;
}
if ( ! V_117 ) {
if( V_433 ) {
F_390 ( V_433 ) ;
}
} else {
F_363 ( V_433 ) ;
}
}
static T_11
F_394 ( T_1 * T_10 V_24 ,
T_26 * T_27 ,
T_4 V_19 V_24 )
{
T_45 V_453 = ( ( V_454 * ) T_27 ) -> V_453 ;
if( ( T_27 -> type ) == ( V_455 ) ) {
if( ! ( V_453 & V_456 ) ) {
F_395 () ;
}
}
return FALSE ;
}
static T_11
F_396 ( T_1 * T_6 V_24 , T_46 * T_27 , T_4 T_19 V_24 )
{
if ( T_27 -> V_457 == V_458 ) {
F_397 () ;
return TRUE ;
} else if ( T_27 -> V_457 == V_459 ) {
F_398 () ;
return TRUE ;
} else if ( T_27 -> V_123 & V_460 ) {
return FALSE ;
} else if ( isascii ( T_27 -> V_457 ) && isprint ( T_27 -> V_457 ) ) {
if ( V_461 && ! F_399 ( V_461 ) ) {
F_400 ( F_169 ( V_121 ) , V_461 ) ;
F_401 ( F_5 ( V_461 ) , - 1 ) ;
}
return FALSE ;
}
return FALSE ;
}
static void
F_330 ( T_9 V_280 , T_9 V_281 , T_9 V_282 , T_35 * V_255
#if ! F_141 ( V_462 ) && ! F_141 ( F_212 )
V_24
#endif
)
{
T_47 * V_463 ;
V_121 = F_402 ( V_464 , L_9 ) ;
F_154 ( NULL ) ;
F_403 ( V_121 , L_219 ) ;
F_404 ( V_121 , L_220 , F_405 ( F_124 ) ,
NULL ) ;
F_404 ( F_20 ( V_121 ) , L_221 ,
F_405 ( F_394 ) , NULL ) ;
F_404 ( F_20 ( V_121 ) , L_222 ,
F_405 ( F_396 ) , NULL ) ;
V_423 = F_406 ( V_465 , 1 , FALSE ) ;
F_407 ( F_378 ( V_423 ) , 0 ) ;
F_408 ( F_378 ( V_121 ) , V_423 ) ;
F_390 ( V_423 ) ;
V_424 = F_409 ( & V_463 ) ;
#if F_141 ( V_462 ) || F_141 ( F_212 )
if( ! V_255 -> V_466 ) {
#endif
F_410 ( F_169 ( V_121 ) , V_463 ) ;
F_390 ( V_424 ) ;
#if F_141 ( V_462 ) || F_141 ( F_212 )
} else {
F_363 ( V_424 ) ;
}
#endif
V_425 = F_411 () ;
F_390 ( V_425 ) ;
V_426 = F_412 () ;
V_162 = F_413 () ;
F_414 ( V_162 , - 1 , V_280 ) ;
F_415 ( V_162 ) ;
V_163 = F_416 ( & V_109 ) ;
F_414 ( V_163 , - 1 , V_281 ) ;
F_390 ( V_163 ) ;
F_404 ( F_417 ( F_99 ( V_109 ) ) ,
L_223 , F_405 ( F_75 ) , NULL ) ;
F_404 ( V_109 , L_224 , F_405 ( V_467 ) ,
F_19 ( F_20 ( V_468 ) , V_469 ) ) ;
F_390 ( V_109 ) ;
V_103 = F_418 () ;
F_414 ( V_103 , - 1 , V_282 ) ;
F_390 ( V_103 ) ;
F_404 ( V_103 , L_224 , F_405 ( V_467 ) ,
F_19 ( F_20 ( V_468 ) , V_470 ) ) ;
V_429 = F_419 ( V_465 ) ;
F_390 ( V_429 ) ;
V_430 = F_419 ( V_465 ) ;
F_390 ( V_430 ) ;
V_431 = F_419 ( V_471 ) ;
F_390 ( V_431 ) ;
V_432 = F_419 ( V_471 ) ;
F_390 ( V_432 ) ;
#ifdef F_223
V_427 = F_420 () ;
#else
V_427 = F_421 () ;
#endif
F_390 ( V_427 ) ;
V_428 = F_422 () ;
F_390 ( V_428 ) ;
V_433 = F_423 () ;
F_390 ( V_433 ) ;
}
static void
F_339 ( T_11 V_472 )
{
F_109 ( V_472 ) ;
F_390 ( V_121 ) ;
F_129 ( V_121 ) ;
while ( F_424 () ) F_425 () ;
F_395 () ;
F_426 ( F_151 ( V_121 ) ) ;
#ifdef F_223
F_427 ( V_427 ) ;
#endif
}
static void F_428 ( const T_2 * V_473 )
{
char * V_474 , * V_475 , * V_476 ;
if ( F_429 ( V_473 , & V_474 ) == - 1 ) {
F_2 ( V_6 , V_7 ,
L_225 ,
V_474 , F_233 ( V_477 ) ) ;
F_9 ( V_474 ) ;
}
if ( F_430 ( V_473 , V_473 , TRUE , & V_476 ,
& V_474 , & V_475 ) == - 1 ) {
F_2 ( V_6 , V_7 ,
L_226 ,
V_476 , V_475 , V_474 , F_233 ( V_477 ) ) ;
F_9 ( V_476 ) ;
F_9 ( V_474 ) ;
F_9 ( V_475 ) ;
}
}
void F_431 ( const T_2 * V_473 )
{
char * V_239 , * V_240 ;
char * V_272 ;
int V_273 ;
if ( ! F_269 ( V_473 , FALSE ) ) {
if ( F_269 ( V_473 , TRUE ) ) {
F_428 ( V_473 ) ;
} else {
return;
}
}
if ( V_473 && strcmp ( V_473 , F_432 () ) == 0 ) {
return;
}
F_118 ( V_121 ) ;
if ( F_269 ( F_432 () , FALSE ) ) {
F_119 () ;
}
F_270 ( V_473 ) ;
F_433 () ;
F_434 ( V_478 ) ;
F_435 () ;
F_436 () ;
( void ) F_230 ( & V_239 , & V_240 ) ;
F_277 ( & V_272 , & V_273 ) ;
if ( V_272 != NULL && V_273 != 0 ) {
F_2 ( V_35 , V_7 ,
L_164 ,
V_272 , F_233 ( V_273 ) ) ;
}
if ( V_80 . V_311 &&
F_278 ( V_80 . V_311 ) == V_312 ) {
F_180 ( V_80 . V_311 ) ;
}
F_68 ( V_80 . V_81 ) ;
F_306 ( V_80 . V_479 ) ;
F_163 ( V_80 . V_167 ) ;
F_299 () ;
F_318 () ;
F_437 () ;
F_438 () ;
F_434 ( V_480 ) ;
F_439 () ;
F_440 () ;
if ( V_239 == NULL && V_240 == NULL ) {
F_321 () ;
}
F_441 () ;
F_442 () ;
F_95 () ;
V_18 . V_112 = FALSE ;
F_334 () ;
F_333 () ;
F_126 () ;
}
void F_443 ( void )
{
F_444 ( & V_18 ) ;
F_445 () ;
}
