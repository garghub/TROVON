static void
F_1 ( T_1 V_1 , int V_2 , T_2 * V_3 )
{
T_3 * V_4 ;
char * V_5 , * V_6 ;
if ( ( ! V_3 ) || ( 0 == strlen ( V_3 ) ) ) {
F_2 ( V_7 , V_8 , L_1 ) ;
return;
}
F_3 ( V_1 ) ;
V_4 = F_4 ( F_5 ( V_1 ) , V_9 ) ;
F_3 ( V_4 ) ;
V_5 = F_6 ( F_7 ( V_4 ) , 0 , - 1 ) ;
switch ( V_2 & V_10 ) {
case V_11 :
V_6 = F_8 ( V_3 ) ;
break;
case V_12 :
if ( ( ! V_5 ) || ( 0 == strlen ( V_5 ) ) )
V_6 = F_8 ( V_3 ) ;
else
V_6 = F_9 ( L_2 , V_5 , L_3 , V_3 , L_4 , NULL ) ;
break;
case V_13 :
if ( ( ! V_5 ) || ( 0 == strlen ( V_5 ) ) )
V_6 = F_8 ( V_3 ) ;
else
V_6 = F_9 ( L_2 , V_5 , L_5 , V_3 , L_4 , NULL ) ;
break;
case V_14 :
V_6 = F_9 ( L_6 , V_3 , L_4 , NULL ) ;
break;
case V_15 :
if ( ( ! V_5 ) || ( 0 == strlen ( V_5 ) ) )
V_6 = F_9 ( L_6 , V_3 , L_4 , NULL ) ;
else
V_6 = F_9 ( L_2 , V_5 , L_7 , V_3 , L_4 , NULL ) ;
break;
case V_16 :
if ( ( ! V_5 ) || ( 0 == strlen ( V_5 ) ) )
V_6 = F_9 ( L_6 , V_3 , L_4 , NULL ) ;
else
V_6 = F_9 ( L_2 , V_5 , L_8 , V_3 , L_4 , NULL ) ;
break;
default:
F_10 () ;
V_6 = NULL ;
break;
}
F_11 ( V_5 ) ;
if ( V_2 & V_17 ) {
T_4 * V_18 = F_12 ( L_9 ) ;
F_13 ( V_18 , V_6 ) ;
F_14 ( V_18 ) ;
F_15 ( V_18 , TRUE ) ;
} else {
F_16 ( F_17 ( V_4 ) , V_6 ) ;
if ( V_2 & V_19 )
F_18 ( & V_20 , V_6 , FALSE ) ;
}
F_11 ( V_6 ) ;
}
void
F_19 ( T_3 * V_21 , T_1 V_1 , T_5 V_2 )
{
char * V_22 = NULL ;
if ( V_20 . V_23 ) {
V_22 = F_20 ( V_20 . V_23 ,
V_20 . V_24 ) ;
F_1 ( ( V_1 ? V_1 : V_21 ) , V_2 , V_22 ) ;
}
}
void
F_21 ( T_3 * V_21 V_25 , T_1 V_1 V_25 , T_6 V_26 )
{
char * V_22 = NULL ;
if ( V_20 . V_23 ) {
V_22 = F_20 ( V_20 . V_23 ,
V_20 . V_24 ) ;
if ( ( ! V_22 ) || ( 0 == strlen ( V_22 ) ) ) {
F_2 ( V_7 , V_8 ,
L_10
L_11 ) ;
return;
}
if ( V_26 == 0 ) {
F_22 ( V_22 ) ;
} else {
if ( V_26 == 255 ) {
F_23 () ;
} else {
F_24 ( V_26 , V_22 , FALSE ) ;
}
F_25 () ;
}
}
}
static void F_26 ( T_1 T_7 V_25 , T_8 V_27 , T_1 V_1 )
{
T_2 * V_28 ;
T_2 * V_29 = V_1 ;
switch( V_27 ) {
case ( V_8 ) :
if ( V_20 . V_23 ) {
V_28 = F_27 ( L_12 , V_29 ) ;
F_28 ( V_28 ) ;
F_11 ( V_28 ) ;
}
break;
case ( V_30 ) :
break;
default:
F_10 () ;
}
}
void
F_29 ( T_3 * T_9 V_25 , T_1 V_1 V_25 )
{
int V_31 ;
const T_2 * V_29 ;
T_1 T_7 ;
if ( V_20 . V_23 ) {
V_31 = V_20 . V_23 -> V_32 -> V_33 ;
if( ! F_30 ( V_31 ) ) {
V_31 = F_31 ( V_20 . V_23 -> V_32 -> V_33 ) ;
}
V_29 = F_32 ( V_31 ) ;
if ( ! F_33 ( V_31 ) ) {
T_7 = F_2 ( V_34 , V_35 ,
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
F_34 () , V_29 , F_35 () , V_29 ) ;
F_36 ( T_7 , F_26 , ( T_1 ) V_29 ) ;
} else {
F_2 ( V_36 , V_8 ,
L_25
L_14
L_26
L_14
L_27
L_28
L_14
L_29 ,
F_34 () , V_29 , F_35 () , V_29 ) ;
}
}
}
static void F_37 ( T_1 T_7 V_25 , T_8 V_27 , T_1 V_1 )
{
T_2 * V_28 ;
T_2 * V_29 = V_1 ;
switch( V_27 ) {
case ( V_8 ) :
if ( V_20 . V_23 ) {
V_28 = F_27 ( L_30 , V_29 [ 0 ] , V_29 ) ;
F_28 ( V_28 ) ;
F_11 ( V_28 ) ;
}
break;
case ( V_30 ) :
break;
default:
F_10 () ;
}
}
void
F_38 ( T_3 * T_9 V_25 , T_1 V_1 V_25 )
{
int V_31 ;
const T_2 * V_29 ;
T_1 T_7 ;
if ( V_20 . V_23 ) {
V_31 = V_20 . V_23 -> V_32 -> V_33 ;
if( ! F_30 ( V_31 ) ) {
V_31 = F_31 ( V_20 . V_23 -> V_32 -> V_33 ) ;
}
V_29 = F_32 ( V_31 ) ;
if ( ! F_33 ( V_31 ) ) {
T_7 = F_2 ( V_34 , V_35 ,
L_31
L_14
L_32
L_14 ,
F_34 () , V_29 , F_35 () , V_29 ) ;
F_36 ( T_7 , F_37 , ( T_1 ) V_29 ) ;
} else {
F_2 ( V_36 , V_8 ,
L_33
L_14
L_34
L_14
L_35
L_36
L_14
L_29 ,
F_34 () , V_29 , F_35 () , V_29 ) ;
}
}
}
static T_10
F_39 ( T_8 V_37 )
{
if ( ( ( V_20 . V_38 . V_39 [ V_37 ] == V_40 ) ||
( V_20 . V_38 . V_39 [ V_37 ] == V_41 ) ||
( V_20 . V_38 . V_39 [ V_37 ] == V_42 ) ||
( V_20 . V_38 . V_39 [ V_37 ] == V_43 ) ) &&
strlen ( V_20 . V_38 . V_44 . V_45 [ V_37 ] ) )
{
return TRUE ;
}
return FALSE ;
}
T_11 *
F_40 ( T_1 V_1 )
{
T_8 V_46 = F_41 ( F_4 ( F_5 ( V_1 ) , V_47 ) ) ;
T_8 V_37 = F_42 ( F_41 ( F_4 ( F_5 ( V_1 ) , V_48 ) ) ) ;
T_8 V_49 ;
T_12 * V_50 ;
T_11 * V_51 = NULL ;
V_50 = ( T_12 * ) F_43 ( V_46 ) ;
if ( V_50 != NULL ) {
T_13 V_24 ;
if ( ! F_44 ( & V_20 , V_50 ) )
return NULL ;
F_45 ( & V_24 , FALSE , FALSE ) ;
F_46 ( & V_24 , & V_20 . V_38 ) ;
F_47 ( & V_24 , & V_20 . V_52 , V_20 . V_53 , V_50 , & V_20 . V_38 ) ;
F_48 ( & V_24 , TRUE , TRUE ) ;
if ( F_39 ( V_37 ) ) {
V_51 = F_49 ( V_51 , F_50 ( L_37 , V_20 . V_38 . V_44 . V_45 [ V_37 ] ) ) ;
}
for ( V_49 = 0 ; V_49 < V_20 . V_38 . V_54 ; V_49 ++ ) {
if ( ( V_49 != V_37 ) && ( F_39 ( V_49 ) ) ) {
V_51 = F_49 ( V_51 , F_50 ( L_37 , V_20 . V_38 . V_44 . V_45 [ V_49 ] ) ) ;
}
}
F_51 ( & V_24 ) ;
}
return V_51 ;
}
static T_2 *
F_52 ( T_1 V_1 )
{
T_8 V_46 = F_41 ( F_4 ( F_5 ( V_1 ) , V_47 ) ) ;
T_8 V_37 = F_42 ( F_41 ( F_4 ( F_5 ( V_1 ) , V_48 ) ) ) ;
T_12 * V_50 ;
T_2 * V_55 = NULL ;
V_50 = ( T_12 * ) F_43 ( V_46 ) ;
if ( V_50 != NULL ) {
T_13 V_24 ;
if ( ! F_44 ( & V_20 , V_50 ) )
return NULL ;
F_45 ( & V_24 , F_53 ( & V_20 . V_38 ) , FALSE ) ;
F_46 ( & V_24 , & V_20 . V_38 ) ;
F_47 ( & V_24 , & V_20 . V_52 , V_20 . V_53 , V_50 ,
& V_20 . V_38 ) ;
F_48 ( & V_24 , TRUE , TRUE ) ;
if ( ( V_20 . V_38 . V_56 [ V_37 ] ) ||
( strchr ( V_20 . V_38 . V_44 . V_45 [ V_37 ] , ',' ) == NULL ) )
{
if ( strlen ( V_20 . V_38 . V_44 . V_44 [ V_37 ] ) != 0 &&
strlen ( V_20 . V_38 . V_44 . V_45 [ V_37 ] ) != 0 ) {
if ( V_20 . V_38 . V_39 [ V_37 ] == V_57 ) {
T_14 * V_58 = F_54 ( V_20 . V_38 . V_59 [ V_37 ] ) ;
if ( V_58 -> V_60 == - 1 ) {
V_55 = F_55 ( V_20 . V_38 . V_44 . V_44 [ V_37 ] ) ;
} else if ( V_58 -> type == V_61 ) {
V_55 = F_50 ( L_38 , V_20 . V_38 . V_44 . V_44 [ V_37 ] ,
V_20 . V_38 . V_44 . V_45 [ V_37 ] ) ;
}
}
if ( V_55 == NULL ) {
V_55 = F_50 ( L_39 , V_20 . V_38 . V_44 . V_44 [ V_37 ] ,
V_20 . V_38 . V_44 . V_45 [ V_37 ] ) ;
}
}
}
F_51 ( & V_24 ) ;
}
return V_55 ;
}
void
F_56 ( T_3 * V_21 V_25 , T_1 V_1 , T_5 V_2 )
{
F_1 ( V_1 ,
V_2 ,
F_52 ( V_1 ) ) ;
}
void
F_57 ( T_3 * V_21 V_25 , T_1 V_1 V_25 , T_15 V_2 )
{
T_4 * V_18 = F_12 ( L_9 ) ;
char V_62 [ 256 ] ;
char * V_63 = V_62 ;
switch( V_2 )
{
case V_64 :
if ( V_20 . V_23 -> V_65 &&
strlen ( V_20 . V_23 -> V_65 -> V_66 ) > 0 ) {
F_13 ( V_18 , V_20 . V_23 -> V_65 -> V_66 ) ;
}
break;
case V_67 :
if ( V_20 . V_23 -> V_32 -> V_68 != 0 ) {
F_13 ( V_18 , V_20 . V_23 -> V_32 -> V_68 ) ;
}
break;
case V_69 :
if ( V_20 . V_24 != 0 ) {
F_13 ( V_18 ,
F_58 ( V_20 . V_23 , V_20 . V_24 ) ) ;
}
break;
default:
break;
}
if ( V_18 -> V_70 == 0 ) {
F_59 ( V_20 . V_23 , V_63 ) ;
F_13 ( V_18 , V_63 ) ;
}
if ( V_18 -> V_70 == 0 ) {
F_2 ( V_7 , V_8 , L_40 ) ;
} else {
F_14 ( V_18 ) ;
}
F_15 ( V_18 , TRUE ) ;
}
void
F_60 ( T_10 V_71 , T_12 * V_72 , T_8 V_46 ) {
if ( V_46 == - 1 )
return;
if ( V_71 ) {
V_72 -> V_73 . V_74 = 1 ;
V_20 . V_75 ++ ;
} else {
V_72 -> V_73 . V_74 = 0 ;
V_20 . V_75 -- ;
}
F_61 ( & V_20 ) ;
if ( ! V_72 -> V_73 . V_74 && ! V_72 -> V_73 . V_76 ) {
F_62 () ;
V_20 . V_77 -- ;
F_63 () ;
F_64 () ;
}
F_65 () ;
}
static void F_66 ( T_1 T_7 V_25 , T_8 V_27 , T_1 V_1 V_25 )
{
switch( V_27 ) {
case ( V_78 ) :
F_67 ( V_79 ) ;
V_80 . V_81 = V_79 ;
F_68 ( & V_20 ) ;
F_65 () ;
break;
case ( V_82 ) :
break;
default:
F_10 () ;
}
if ( V_20 . V_83 ) {
F_60 ( ! V_20 . V_83 -> V_73 . V_74 ,
V_20 . V_83 , V_20 . V_84 ) ;
}
}
void
F_69 ( T_3 * V_21 V_25 , T_1 V_1 V_25 , T_16 V_2 )
{
static T_3 * V_85 = NULL ;
switch( V_2 ) {
case V_86 :
if ( V_20 . V_83 ) {
if( V_80 . V_81 != V_79 && V_20 . V_83 -> V_73 . V_74 == 0 ) {
V_85 = F_2 ( V_34 , V_87 ,
L_41
L_42
L_43 ,
F_34 () , F_35 () ) ;
F_36 ( V_85 , F_66 , NULL ) ;
} else {
F_60 ( ! V_20 . V_83 -> V_73 . V_74 ,
V_20 . V_83 , V_20 . V_84 ) ;
}
}
break;
case V_88 :
F_70 ( & V_20 , V_89 ) ;
break;
case V_90 :
F_70 ( & V_20 , V_91 ) ;
break;
}
}
void
F_71 ( T_3 * V_21 V_25 , T_1 V_1 V_25 , int V_2 V_25 )
{
F_72 ( & V_20 , V_89 ) ;
}
void
F_73 ( T_3 * V_21 V_25 , T_1 V_1 V_25 , int V_2 V_25 )
{
F_72 ( & V_20 , V_91 ) ;
}
static void
F_74 ( T_17 * V_92 , T_1 T_18 V_25 )
{
T_19 * V_93 ;
T_2 V_94 [ 2 + 10 + 1 + 5 + 1 ] ;
T_10 V_95 = FALSE ;
T_20 V_96 = 0 , V_97 ;
T_3 * V_98 ;
const T_6 * V_99 ;
T_8 V_100 ;
T_21 * V_101 ;
T_22 V_102 ;
if ( ! F_75 ( V_92 , & V_101 , & V_102 ) )
{
V_98 = F_76 ( V_103 ) ;
if ( V_98 == NULL )
return;
V_99 = F_77 ( V_98 , & V_97 ) ;
if ( V_99 == NULL )
return;
F_78 ( & V_20 ) ;
F_79 ( V_98 , V_99 ,
V_20 . V_83 , NULL , V_97 ) ;
F_80 ( V_92 , & V_20 ) ;
return;
}
F_81 ( V_101 , & V_102 , 1 , & V_93 , - 1 ) ;
if ( ! V_93 ) return;
F_82 ( V_103 , V_93 -> V_104 ) ;
V_98 = F_76 ( V_103 ) ;
V_99 = F_77 ( V_98 , & V_97 ) ;
F_3 ( V_99 != NULL ) ;
V_20 . V_23 = V_93 ;
F_83 ( & V_20 ) ;
if ( V_93 -> V_32 ) {
if ( V_93 -> V_32 -> V_105 != NULL &&
V_93 -> V_32 -> V_105 [ 0 ] != '\0' ) {
V_95 = TRUE ;
V_96 = ( T_20 ) strlen ( V_93 -> V_32 -> V_105 ) ;
} else {
V_96 = ( T_20 ) strlen ( V_93 -> V_32 -> V_106 ) ;
}
V_100 = V_93 -> V_96 + V_93 -> V_107 ;
if ( V_100 == 0 ) {
V_94 [ 0 ] = '\0' ;
} else if ( V_100 == 1 ) {
F_84 ( V_94 , L_44 , sizeof V_94 ) ;
} else {
F_85 ( V_94 , sizeof V_94 , L_45 , V_100 ) ;
}
F_86 () ;
if ( V_96 ) {
F_87 ( L_46 ,
( V_95 ) ? V_93 -> V_32 -> V_105 : V_93 -> V_32 -> V_106 ,
V_93 -> V_32 -> V_68 , V_94 ) ;
} else {
F_87 ( L_37 , L_9 ) ;
}
}
F_79 ( V_98 , V_99 , V_20 . V_83 , V_93 ,
V_97 ) ;
F_80 ( V_92 , & V_20 ) ;
}
void F_88 ( T_3 * T_9 V_25 , T_1 V_1 V_25 ) {
if ( V_20 . V_24 -> V_108 )
F_89 ( V_20 . V_24 -> V_108 , V_109 ) ;
}
void F_90 ( T_3 * T_9 V_25 , T_1 V_1 V_25 ) {
if ( V_20 . V_24 -> V_108 )
F_91 ( V_20 . V_24 -> V_108 , V_109 ) ;
}
void F_92 ( T_3 * T_9 V_25 , T_1 V_1 V_25 )
{
if ( V_20 . V_23 ) {
F_93 ( V_57 , V_20 . V_23 -> V_32 -> V_106 ,
V_20 . V_23 -> V_32 -> V_68 , 0 ) ;
F_94 () ;
if ( ! V_110 . V_111 ) {
F_95 () ;
}
V_20 . V_38 . V_112 = FALSE ;
}
}
void F_96 ( T_3 * T_9 V_25 , T_1 V_1 V_25 ) {
T_23 * V_113 ;
V_113 = F_97 ( F_98 ( V_109 ) , V_20 . V_23 ) ;
if( V_113 ) {
F_99 ( F_98 ( V_109 ) , V_113 , TRUE ) ;
F_100 ( V_113 ) ;
}
}
void F_101 ( T_3 * T_9 V_25 , T_1 V_1 V_25 ) {
if ( V_20 . V_24 -> V_108 ) {
T_24 V_114 = V_115 ;
V_115 = V_116 ;
F_102 ( V_20 . V_24 -> V_108 , V_109 ) ;
V_115 = V_114 ;
}
}
static void
F_103 ( T_10 V_117 )
{
V_118 = V_117 ;
F_104 () ;
}
T_10
F_105 ( void )
{
F_106 ( V_119 ) ;
F_107 () ;
F_108 () ;
#ifdef F_109
F_110 ( & V_120 ) ;
#endif
if ( V_20 . V_121 == V_122 ) {
V_20 . V_121 = V_123 ;
return TRUE ;
} else {
F_111 ( & V_20 ) ;
F_112 () ;
return FALSE ;
}
}
static T_10
F_113 ( T_3 * T_9 V_25 , T_25 * T_26 V_25 , T_1 V_1 V_25 )
{
if ( V_124 )
return TRUE ;
if ( F_114 ( & V_20 , TRUE , L_47 ) )
return F_105 () ;
else
return TRUE ;
}
static void
F_115 ( void )
{
if ( V_80 . V_125 && V_80 . V_126 )
F_116 ( F_117 ( V_127 ) , V_80 . V_126 ) ;
if ( V_80 . V_128 && V_80 . V_129 ) {
F_116 ( F_117 ( V_130 ) , V_80 . V_129 ) ;
}
}
static void
F_118 ( T_3 * T_9 )
{
T_27 V_131 ;
V_131 . V_132 = V_110 . V_133 ;
V_131 . V_134 = V_80 . V_135 ;
V_131 . V_136 = V_80 . V_137 ;
V_131 . V_138 = V_110 . V_139 ;
if ( V_80 . V_140 > 0 &&
V_80 . V_141 > 0 ) {
V_131 . V_142 = V_80 . V_140 ;
V_131 . V_143 = V_80 . V_141 ;
V_131 . V_144 = V_110 . V_145 ;
} else {
V_131 . V_138 = FALSE ;
}
V_131 . V_146 = V_80 . V_147 ;
F_119 ( T_9 , & V_131 ) ;
F_115 () ;
F_120 () ;
}
static void
F_106 ( T_3 * T_9 )
{
T_27 V_131 ;
F_121 ( T_9 , & V_131 ) ;
if ( V_110 . V_133 ) {
V_80 . V_135 = V_131 . V_134 ;
V_80 . V_137 = V_131 . V_136 ;
}
if ( V_110 . V_139 ) {
V_80 . V_140 = V_131 . V_142 ;
V_80 . V_141 = V_131 . V_143 ;
}
if( V_110 . V_145 ) {
V_80 . V_147 = V_131 . V_146 ;
}
V_80 . V_126 = F_122 ( F_117 ( V_127 ) ) ;
V_80 . V_129 = F_122 ( F_117 ( V_130 ) ) ;
F_123 () ;
}
void
F_124 ( T_3 * T_9 V_25 , T_1 V_1 V_25 )
{
if ( F_114 ( & V_20 , TRUE , L_47 ) )
F_105 () ;
}
static void
F_125 ( T_10 V_148 ) {
T_28 * V_149 ;
#ifdef F_126
F_127 () ;
#endif
if ( V_148 ) {
V_149 = stdout ;
fprintf ( V_149 , L_48 V_150 L_49
L_50
L_51
L_14
L_37 ,
V_151 , F_128 () ) ;
} else {
V_149 = V_152 ;
}
fprintf ( V_149 , L_14 ) ;
fprintf ( V_149 , L_52 ) ;
fprintf ( V_149 , L_14 ) ;
#ifdef F_109
fprintf ( V_149 , L_53 ) ;
fprintf ( V_149 , L_54 ) ;
fprintf ( V_149 , L_55 ) ;
fprintf ( V_149 , L_56 ) ;
fprintf ( V_149 , L_57 ) ;
fprintf ( V_149 , L_58 ) ;
fprintf ( V_149 , L_59 ) ;
fprintf ( V_149 , L_60 ) ;
#ifdef F_129
fprintf ( V_149 , L_61 ) ;
#endif
#if F_130 ( F_126 ) || F_130 ( F_129 )
fprintf ( V_149 , L_62 ) ;
#endif
fprintf ( V_149 , L_63 ) ;
fprintf ( V_149 , L_64 ) ;
fprintf ( V_149 , L_65 ) ;
fprintf ( V_149 , L_14 ) ;
fprintf ( V_149 , L_66 ) ;
fprintf ( V_149 , L_67 ) ;
fprintf ( V_149 , L_68 ) ;
fprintf ( V_149 , L_69 ) ;
fprintf ( V_149 , L_70 ) ;
fprintf ( V_149 , L_71 ) ;
fprintf ( V_149 , L_72 ) ;
fprintf ( V_149 , L_73 ) ;
fprintf ( V_149 , L_74 ) ;
#endif
fprintf ( V_149 , L_75 ) ;
fprintf ( V_149 , L_76 ) ;
fprintf ( V_149 , L_14 ) ;
fprintf ( V_149 , L_77 ) ;
fprintf ( V_149 , L_78 ) ;
fprintf ( V_149 , L_79 ) ;
fprintf ( V_149 , L_80 ) ;
fprintf ( V_149 , L_14 ) ;
fprintf ( V_149 , L_81 ) ;
fprintf ( V_149 , L_82 ) ;
fprintf ( V_149 , L_83 ) ;
fprintf ( V_149 , L_84 ) ;
fprintf ( V_149 , L_85 ) ;
fprintf ( V_149 , L_86 ) ;
fprintf ( V_149 , L_87 ) ;
fprintf ( V_149 , L_88 ) ;
fprintf ( V_149 , L_89 ) ;
fprintf ( V_149 , L_90 ) ;
fprintf ( V_149 , L_91 ) ;
fprintf ( V_149 , L_92 ) ;
fprintf ( V_149 , L_14 ) ;
fprintf ( V_149 , L_93 ) ;
fprintf ( V_149 , L_94 ) ;
fprintf ( V_149 , L_14 ) ;
fprintf ( V_149 , L_95 ) ;
fprintf ( V_149 , L_96 ) ;
fprintf ( V_149 , L_97 ) ;
fprintf ( V_149 , L_98 ) ;
fprintf ( V_149 , L_99 ) ;
fprintf ( V_149 , L_100 ) ;
fprintf ( V_149 , L_101 ) ;
#ifndef F_126
fprintf ( V_149 , L_102 ) ;
#endif
#ifdef F_126
F_131 () ;
#endif
}
static void
F_132 ( void )
{
#ifdef F_126
F_127 () ;
#endif
printf ( V_153 L_103 V_150 L_49
L_14
L_37
L_14
L_37
L_14
L_37 ,
V_151 , F_128 () , V_154 -> V_155 ,
V_156 -> V_155 ) ;
#ifdef F_126
F_131 () ;
#endif
}
void
F_133 ( const char * V_157 , T_29 V_158 )
{
#ifdef F_126
F_127 () ;
#endif
vfprintf ( V_152 , V_157 , V_158 ) ;
}
void
F_134 ( const char * V_157 , ... )
{
T_29 V_158 ;
va_start ( V_158 , V_157 ) ;
F_133 ( V_157 , V_158 ) ;
va_end ( V_158 ) ;
}
void
F_135 ( const char * V_157 , ... )
{
T_29 V_158 ;
F_134 ( L_104 ) ;
va_start ( V_158 , V_157 ) ;
F_133 ( V_157 , V_158 ) ;
va_end ( V_158 ) ;
F_134 ( L_14 ) ;
}
void
F_136 ( const char * V_157 , ... )
{
T_29 V_158 ;
va_start ( V_158 , V_157 ) ;
F_133 ( V_157 , V_158 ) ;
F_134 ( L_14 ) ;
va_end ( V_158 ) ;
}
static T_10
F_137 ( T_1 V_1 V_25 )
{
F_138 ( FALSE ) ;
return TRUE ;
}
void F_139 ( void )
{
F_140 ( V_159 ) ;
V_159 = F_141 ( V_110 . V_160 , F_137 , NULL ) ;
}
void
F_142 ( void )
{
}
void
F_143 ( void )
{
}
static T_10
F_144 ( T_1 V_1 V_25 )
{
if ( F_145 ( NULL ) ) {
if ( F_146 ( V_161 ) )
F_147 ( F_146 ( V_161 ) , NULL , TRUE ) ;
if ( F_146 ( V_162 ) )
F_147 ( F_146 ( V_162 ) , NULL , TRUE ) ;
}
return TRUE ;
}
static void
F_148 ( T_30 * V_163 )
{
T_2 * V_164 ;
T_2 * V_165 ;
if ( V_163 -> V_166 ) {
V_164 = F_149 ( V_163 ) ;
V_165 = F_27 ( L_105 , V_163 -> V_167 ? L_106 : L_9 ,
V_164 ) ;
F_11 ( V_164 ) ;
F_150 ( V_165 ) ;
F_11 ( V_165 ) ;
} else {
F_150 ( L_107 ) ;
}
}
void
F_151 ( T_30 * V_163 )
{
F_148 ( V_163 ) ;
F_152 ( V_163 ) ;
F_153 ( V_163 ) ;
}
void
F_154 ( T_10 V_168 )
{
F_155 ( V_168 ) ;
F_156 ( V_168 ) ;
V_169 = V_168 ;
}
void
F_157 ( T_10 V_170 )
{
F_158 ( V_170 ) ;
F_159 ( V_170 ) ;
if( V_170 != V_80 . V_170 ) {
V_80 . V_170 = V_170 ;
F_160 ( V_170 ) ;
F_25 () ;
}
}
static void
F_161 ( T_1 T_7 , T_8 V_27 V_25 , T_1 V_1 V_25 )
{
V_80 . V_171 = ! F_162 ( T_7 ) ;
}
static void
F_163 ( T_1 T_7 , T_8 V_27 V_25 , T_1 V_1 V_25 )
{
V_80 . V_172 = ! F_162 ( T_7 ) ;
}
static void
F_164 ( T_30 * V_163 )
{
if( V_163 -> V_173 > 10000 ) {
V_174 = F_2 ( V_175 , V_176 ,
L_108 ,
F_34 () ,
F_35 () ) ;
F_165 ( F_166 ( V_174 ) , V_177 ) ;
}
F_167 () ;
F_150 ( L_107 ) ;
F_152 ( NULL ) ;
F_153 ( NULL ) ;
F_168 ( FALSE ) ;
F_169 ( V_163 ) ;
F_170 ( FALSE ) ;
F_171 ( FALSE ) ;
F_83 ( V_163 ) ;
F_103 ( FALSE ) ;
F_172 () ;
}
static void
F_173 ( T_30 * V_163 V_25 )
{
if( V_174 != NULL ) {
F_174 ( V_174 ) ;
V_174 = NULL ;
}
}
static void
F_175 ( T_30 * V_163 V_25 )
{
F_176 () ;
F_103 ( TRUE ) ;
}
static void
F_177 ( T_30 * V_163 )
{
T_2 * V_178 ;
if ( ! V_163 -> V_179 && V_163 -> V_166 ) {
F_178 ( V_163 -> V_166 ) ;
V_178 = F_179 ( F_8 ( V_163 -> V_166 ) ) ;
F_180 ( V_178 ) ;
F_11 ( V_178 ) ;
}
F_151 ( V_163 ) ;
F_168 ( TRUE ) ;
}
static void
F_181 ( T_30 * V_163 )
{
T_2 * V_178 ;
if ( ! V_163 -> V_179 && V_163 -> V_166 ) {
F_178 ( V_163 -> V_166 ) ;
V_178 = F_179 ( F_8 ( V_163 -> V_166 ) ) ;
F_180 ( V_178 ) ;
F_11 ( V_178 ) ;
}
F_151 ( V_163 ) ;
}
static T_11 * F_182 (
const char * * V_180 ,
const char * * V_181 ,
const char * * V_182 ,
const char * * V_183 )
{
T_11 * V_184 = NULL ;
T_31 * V_185 ;
T_31 * V_186 ;
T_31 * V_187 ;
T_31 * V_188 ;
if( V_180 != NULL ) {
V_185 = F_183 ( V_180 ) ;
F_3 ( V_185 ) ;
V_184 = F_49 ( V_184 , V_185 ) ;
}
if( V_181 != NULL ) {
V_186 = F_183 ( V_181 ) ;
F_3 ( V_186 ) ;
V_184 = F_49 ( V_184 , V_186 ) ;
}
if( V_182 != NULL ) {
V_187 = F_183 ( V_182 ) ;
F_3 ( V_187 ) ;
V_184 = F_49 ( V_184 , V_187 ) ;
}
if( V_183 != NULL ) {
V_188 = F_183 ( V_183 ) ;
F_3 ( V_188 ) ;
V_184 = F_49 ( V_184 , V_188 ) ;
}
return V_184 ;
}
static void
F_184 ( T_32 * V_189 )
{
T_4 * V_190 = F_12 ( L_9 ) ;
F_13 ( V_190 , L_109 ) ;
F_185 ( V_190 , L_110 , F_186 ( V_189 -> V_163 ) ) ;
F_150 ( V_190 -> V_155 ) ;
F_15 ( V_190 , TRUE ) ;
}
static void
F_187 ( T_32 * V_189 )
{
static T_11 * V_184 = NULL ;
F_184 ( V_189 ) ;
if( V_184 == NULL ) {
V_184 = F_182 ( V_191 , V_192 , V_193 , NULL ) ;
}
F_188 ( F_166 ( V_119 ) , V_184 ) ;
F_170 ( TRUE ) ;
F_171 ( TRUE ) ;
F_103 ( FALSE ) ;
}
static void
F_189 ( T_32 * V_189 )
{
F_184 ( V_189 ) ;
F_170 ( TRUE ) ;
F_171 ( TRUE ) ;
F_168 ( TRUE ) ;
F_103 ( TRUE ) ;
}
static void
F_190 ( T_32 * V_189 )
{
T_30 * V_163 = V_189 -> V_163 ;
static T_11 * V_184 = NULL ;
V_124 = FALSE ;
if ( ! V_163 -> V_179 && V_163 -> V_166 ) {
F_178 ( V_163 -> V_166 ) ;
}
F_151 ( V_163 ) ;
F_170 ( FALSE ) ;
F_171 ( FALSE ) ;
F_103 ( TRUE ) ;
if( V_184 == NULL ) {
V_184 = F_182 ( V_194 , V_195 , V_196 , V_197 ) ;
}
F_188 ( F_166 ( V_119 ) , V_184 ) ;
if( V_120 . V_198 ) {
F_105 () ;
}
}
static void
F_191 ( T_32 * V_189 V_25 )
{
F_103 ( FALSE ) ;
}
static void
F_192 ( T_32 * V_189 V_25 )
{
#if 0
capture_file *cf = capture_opts->cf;
#endif
static T_11 * V_184 = NULL ;
V_124 = FALSE ;
F_170 ( FALSE ) ;
F_171 ( FALSE ) ;
F_150 ( L_107 ) ;
if( V_184 == NULL ) {
V_184 = F_182 ( V_194 , V_195 , V_196 , V_197 ) ;
}
F_188 ( F_166 ( V_119 ) , V_184 ) ;
if( V_120 . V_198 ) {
F_105 () ;
}
}
static void
F_193 ( T_32 * V_189 V_25 )
{
V_124 = TRUE ;
F_194 () ;
}
static void
F_195 ( T_32 * V_189 V_25 )
{
static T_11 * V_184 = NULL ;
V_124 = FALSE ;
F_150 ( L_107 ) ;
F_170 ( FALSE ) ;
F_171 ( FALSE ) ;
F_103 ( FALSE ) ;
if( V_184 == NULL ) {
V_184 = F_182 ( V_194 , V_195 , V_196 , V_197 ) ;
}
F_188 ( F_166 ( V_119 ) , V_184 ) ;
if( V_120 . V_198 ) {
F_105 () ;
}
}
static void
F_196 ( T_1 V_1 )
{
T_30 * V_163 = V_1 ;
F_197 ( V_163 -> V_24 ) ;
F_198 ( V_163 -> V_24 -> V_108 ) ;
if( V_163 -> V_199 &&
( V_163 -> V_200 != 0 || ( V_163 -> string && V_163 -> V_201 ) ) ) {
F_199 ( V_163 -> V_24 -> V_202 , V_163 -> V_200 ,
( V_203 * ) V_109 , V_163 -> V_24 -> V_108 ) ;
}
F_169 ( V_163 ) ;
}
static void
F_200 ( T_30 * V_163 )
{
F_201 () ;
F_169 ( V_163 ) ;
}
static void
F_202 ( T_30 * V_163 )
{
F_83 ( V_163 ) ;
}
static void
F_203 ( T_8 T_26 , T_1 V_1 , T_1 T_18 V_25 )
{
switch( T_26 ) {
case ( V_204 ) :
F_204 ( V_205 , V_206 , L_111 ) ;
F_164 ( V_1 ) ;
break;
case ( V_207 ) :
F_204 ( V_205 , V_206 , L_112 ) ;
F_173 ( V_1 ) ;
break;
case ( V_208 ) :
F_204 ( V_205 , V_206 , L_113 ) ;
F_175 ( V_1 ) ;
break;
case ( V_209 ) :
F_204 ( V_205 , V_206 , L_114 ) ;
F_177 ( V_1 ) ;
break;
case ( V_210 ) :
F_204 ( V_205 , V_206 , L_115 ) ;
F_175 ( V_1 ) ;
break;
case ( V_211 ) :
F_204 ( V_205 , V_206 , L_116 ) ;
F_177 ( V_1 ) ;
break;
case ( V_212 ) :
F_204 ( V_205 , V_206 , L_117 ) ;
break;
case ( V_213 ) :
F_204 ( V_205 , V_206 , L_118 ) ;
F_181 ( V_1 ) ;
break;
case ( V_214 ) :
F_204 ( V_205 , V_206 , L_119 ) ;
F_181 ( V_1 ) ;
break;
case ( V_215 ) :
F_196 ( V_1 ) ;
break;
case ( V_216 ) :
F_200 ( V_1 ) ;
break;
case ( V_217 ) :
F_202 ( V_1 ) ;
break;
case ( V_218 ) :
F_204 ( V_205 , V_206 , L_120 ) ;
break;
case ( V_219 ) :
F_204 ( V_205 , V_206 , L_121 ) ;
break;
case ( V_220 ) :
F_204 ( V_205 , V_206 , L_122 ) ;
break;
case ( V_221 ) :
F_204 ( V_205 , V_206 , L_123 ) ;
break;
case ( V_222 ) :
F_204 ( V_205 , V_206 , L_124 ) ;
break;
case ( V_223 ) :
F_204 ( V_205 , V_206 , L_125 ) ;
break;
case ( V_224 ) :
F_204 ( V_205 , V_206 , L_126 ) ;
break;
case ( V_225 ) :
F_204 ( V_205 , V_206 , L_127 ) ;
break;
default:
F_205 ( L_128 , T_26 ) ;
F_10 () ;
}
}
static void
F_206 ( T_8 T_26 , T_32 * V_189 , T_1 T_18 V_25 )
{
#ifdef F_207
T_33 * V_226 ;
#endif
switch( T_26 ) {
case ( V_227 ) :
F_204 ( V_205 , V_206 , L_129 ) ;
F_187 ( V_189 ) ;
break;
case ( V_228 ) :
F_204 ( V_205 , V_206 , L_130 ) ;
F_189 ( V_189 ) ;
#ifdef F_207
V_226 = F_208 ( V_229 , NULL ) ;
F_209 ( V_226 , F_183 ( V_193 ) ) ;
#endif
break;
case ( V_230 ) :
break;
case ( V_231 ) :
F_204 ( V_205 , V_206 , L_131 ) ;
F_190 ( V_189 ) ;
break;
case ( V_232 ) :
F_204 ( V_205 , V_206 , L_132 ) ;
F_191 ( V_189 ) ;
break;
case ( V_233 ) :
F_204 ( V_205 , V_206 , L_133 ) ;
break;
case ( V_234 ) :
F_204 ( V_205 , V_206 , L_134 ) ;
F_192 ( V_189 ) ;
break;
case ( V_235 ) :
F_204 ( V_205 , V_206 , L_135 ) ;
#ifdef F_207
V_226 = F_208 ( V_229 , NULL ) ;
F_209 ( V_226 , F_183 ( V_197 ) ) ;
#endif
F_193 ( V_189 ) ;
break;
case ( V_236 ) :
F_204 ( V_205 , V_206 , L_136 ) ;
F_195 ( V_189 ) ;
break;
default:
F_205 ( L_137 , T_26 ) ;
F_10 () ;
}
}
static void
F_210 ( T_4 * V_155 )
{
F_13 ( V_155 , L_138 ) ;
F_185 ( V_155 ,
#ifdef F_211
L_139 , F_211 , V_237 ,
V_238 ) ;
#else
L_140 ) ;
void
F_212 ( T_4 * V_155 )
{
F_213 ( V_155 ) ;
F_13 ( V_155 , L_141 ) ;
#ifdef F_214
#ifdef F_215
F_13 ( V_155 , L_142 ) ;
#else
F_13 ( V_155 , L_138 ) ;
F_13 ( V_155 , F_216 () ) ;
#endif
#else
F_13 ( V_155 , L_143 ) ;
#endif
F_13 ( V_155 , L_141 ) ;
#ifdef F_217
F_218 ( V_155 ) ;
#else
F_13 ( V_155 , L_144 ) ;
#endif
}
static void
F_219 ( T_4 * V_155 )
{
F_220 ( V_155 ) ;
#ifdef F_217
F_13 ( V_155 , L_141 ) ;
F_221 ( V_155 ) ;
#endif
if( F_222 () ) {
F_13 ( V_155 , L_141 ) ;
F_223 ( V_155 ) ;
}
}
static T_34 *
F_224 ( char * * V_239 , char * * V_240 )
{
int V_241 , V_242 ;
int V_243 , V_244 ;
int V_245 , V_246 ;
int V_247 , V_248 ;
char * V_249 , * V_250 ;
char * V_251 , * V_252 ;
int V_253 , V_254 ;
T_34 * V_255 ;
F_225 () ;
V_255 = F_226 ( & V_241 , & V_242 , & V_249 ,
& V_253 , & V_254 , & V_250 ) ;
if ( V_249 != NULL ) {
if ( V_241 != 0 ) {
F_2 ( V_36 , V_8 ,
L_145 , V_249 ,
F_227 ( V_241 ) ) ;
}
if ( V_242 != 0 ) {
F_2 ( V_36 , V_8 ,
L_146 , V_249 ,
F_227 ( V_242 ) ) ;
}
}
if ( V_250 != NULL ) {
if ( V_253 != 0 ) {
F_2 ( V_36 , V_8 ,
L_147 , V_250 ,
F_227 ( V_253 ) ) ;
}
if ( V_254 != 0 ) {
F_2 ( V_36 , V_8 ,
L_148 , V_250 ,
F_227 ( V_254 ) ) ;
}
F_11 ( V_250 ) ;
V_250 = NULL ;
}
#ifdef F_126
if ( V_255 -> V_256 == V_257 ) {
F_127 () ;
}
#endif
F_228 ( V_258 , & V_251 , & V_243 ) ;
if ( V_251 != NULL ) {
F_2 ( V_36 , V_8 ,
L_149 , V_251 ,
F_227 ( V_243 ) ) ;
F_11 ( V_251 ) ;
}
F_228 ( V_259 , & V_252 , & V_244 ) ;
if ( V_252 != NULL ) {
F_2 ( V_36 , V_8 ,
L_150 , V_252 ,
F_227 ( V_244 ) ) ;
F_11 ( V_252 ) ;
}
F_229 ( V_239 , & V_245 , & V_246 ,
V_240 , & V_247 , & V_248 ) ;
if ( * V_239 != NULL ) {
if ( V_245 != 0 ) {
F_2 ( V_36 , V_8 ,
L_151 ,
* V_239 , F_227 ( V_245 ) ) ;
}
if ( V_246 != 0 ) {
F_2 ( V_36 , V_8 ,
L_152 ,
* V_239 , F_227 ( V_246 ) ) ;
}
F_11 ( * V_239 ) ;
* V_239 = NULL ;
}
if ( * V_240 != NULL ) {
if ( V_247 != 0 ) {
F_2 ( V_36 , V_8 ,
L_153 , * V_240 ,
F_227 ( V_247 ) ) ;
}
if ( V_248 != 0 ) {
F_2 ( V_36 , V_8 ,
L_154 , * V_240 ,
F_227 ( V_248 ) ) ;
}
F_11 ( * V_240 ) ;
* V_240 = NULL ;
}
return V_255 ;
}
static void
#ifdef F_126
F_230 ( T_2 * V_260 )
#else
check_and_warn_user_startup( T_2 * V_260 V_25 )
#endif
{
T_2 * V_261 , * V_262 ;
T_1 V_263 ;
if ( F_231 () && V_80 . V_171 ) {
V_261 = F_232 () ;
V_262 = F_233 () ;
V_263 = F_2 ( V_36 , V_8 ,
L_155
L_156
L_157
L_158
L_159 , V_261 , V_262 ) ;
F_11 ( V_261 ) ;
F_11 ( V_262 ) ;
F_234 ( V_263 , L_160 ) ;
F_36 ( V_263 , F_161 , NULL ) ;
}
#ifdef F_126
if ( ! V_264 && ! V_260 && ! F_235 () && V_80 . V_172 && F_236 () >= 6 ) {
V_263 = F_2 ( V_36 , V_8 ,
L_161
L_162 ) ;
F_234 ( V_263 , L_160 ) ;
F_36 ( V_263 , F_163 , NULL ) ;
}
#endif
}
int
main ( int V_265 , char * V_266 [] )
{
char * V_267 ;
char * V_268 ;
int V_269 ;
T_10 V_270 = FALSE ;
extern int V_271 ;
const T_2 * V_22 ;
#ifdef F_126
T_35 V_272 ;
#endif
char * V_273 ;
int V_274 ;
char * V_239 , * V_240 ;
int V_275 ;
#ifdef F_109
T_10 V_276 = FALSE ;
T_10 V_277 = FALSE ;
T_11 * V_278 ;
T_2 * V_279 ;
#else
T_10 V_280 = FALSE ;
#ifdef F_126
#ifdef F_217
T_2 * V_279 ;
#endif
#endif
#endif
T_8 V_281 = 280 , V_282 = 95 , V_283 = 75 ;
T_2 * V_284 , * V_260 = NULL , * V_285 = NULL , * V_286 = NULL , * V_287 = NULL ;
T_36 * V_288 = NULL ;
T_10 V_289 = FALSE ;
T_34 * V_255 ;
char V_290 ;
T_3 * V_291 = NULL ;
T_37 V_292 ;
T_20 V_293 = 0 ;
T_10 V_294 = FALSE ;
T_36 * V_295 = NULL ;
int V_296 ;
int V_297 ;
#ifdef F_207
T_33 * V_226 ;
#endif
#ifdef F_109
#if F_130 ( F_126 ) || F_130 ( F_129 )
#define F_237 "B:"
#else
#define F_237 ""
#endif
#else
#define F_237 ""
#endif
#ifdef F_129
#define F_238 "I"
#else
#define F_238 ""
#endif
#define F_239 "a:b:" OPTSTRING_B "c:C:d:Df:g:Hhi:" OPTSTRING_I "jJ:kK:lLm:nN:o:P:pr:R:Ss:t:u:vw:X:y:z:"
static const char V_298 [] = F_239 ;
setlocale ( V_299 , L_9 ) ;
#ifdef F_126
F_240 ( V_265 , V_266 ) ;
#endif
F_241 () ;
F_242 () ;
V_267 = F_243 ( V_266 [ 0 ] , main ) ;
F_244 () ;
F_245 ( & V_300 ) ;
#ifdef F_126
F_246 () ;
F_247 () ;
#ifdef F_217
V_301 = F_248 () ;
switch ( V_301 ) {
case V_302 :
V_303 = F_249 ( & V_275 , & V_279 ) ;
if ( V_303 == NULL || F_250 ( V_303 ) == 0 ) {
if ( V_275 == V_304 && V_279 != NULL ) {
F_2 ( V_7 , V_8 , L_37 , L_163 ) ;
F_11 ( V_279 ) ;
}
V_305 = NULL ;
} else {
V_305 = F_251 ( V_303 ) ;
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
F_252 ( F_253 ( 1 , 1 ) , & V_272 ) ;
#endif
F_254 ( TRUE ) ;
V_154 = F_12 ( L_164 ) ;
F_255 ( V_154 , F_210 , F_212 ) ;
V_156 = F_12 ( L_165 ) ;
F_256 ( V_156 , F_219 ) ;
F_257 ( & V_273 , & V_274 ) ;
if ( V_273 != NULL && V_274 != 0 ) {
F_2 ( V_36 , V_8 ,
L_166 ,
V_273 , F_227 ( V_274 ) ) ;
}
V_306 = 0 ;
V_296 = V_307 ;
while ( ( V_269 = F_258 ( V_265 , V_266 , V_298 ) ) != - 1 ) {
switch ( V_269 ) {
case 'C' :
if ( F_259 ( V_308 , FALSE ) ) {
F_260 ( V_308 ) ;
} else {
F_135 ( L_167 , V_308 ) ;
exit ( 1 ) ;
}
break;
case 'D' :
#ifdef F_109
V_278 = F_261 ( & V_275 , & V_279 ) ;
if ( V_278 == NULL ) {
switch ( V_275 ) {
case V_309 :
case V_310 :
F_135 ( L_37 , V_279 ) ;
F_11 ( V_279 ) ;
break;
case V_311 :
F_135 ( L_168 ) ;
break;
}
exit ( 2 ) ;
}
F_262 ( V_278 ) ;
F_263 ( V_278 ) ;
exit ( 0 ) ;
#else
V_280 = TRUE ;
V_270 = TRUE ;
#endif
break;
case 'h' :
F_125 ( TRUE ) ;
exit ( 0 ) ;
break;
#ifdef F_126
case 'i' :
if ( strcmp ( V_308 , L_169 ) == 0 )
V_264 = TRUE ;
break;
#endif
case 'P' :
V_297 = F_264 ( V_269 , V_308 ) ;
if( V_297 != 0 ) {
F_135 ( L_170 , V_308 ) ;
exit ( V_297 ) ;
}
break;
case 'v' :
F_132 () ;
exit ( 0 ) ;
break;
case 'X' :
F_265 ( V_308 ) ;
break;
case '?' :
break;
}
}
F_266 ( & V_273 , & V_274 ) ;
if ( V_273 != NULL && V_274 != 0 ) {
F_2 ( V_36 , V_8 ,
L_171 ,
V_273 , F_227 ( V_274 ) ) ;
}
if ( V_80 . V_312 &&
F_267 ( V_80 . V_312 ) == V_313 ) {
F_180 ( V_80 . V_312 ) ;
} else {
F_180 ( F_268 () ) ;
}
V_307 = V_296 ;
V_306 = 1 ;
#if ! F_269 ( 2 , 31 , 0 )
F_270 ( NULL ) ;
#endif
setlocale ( V_299 , L_9 ) ;
F_271 ( & V_265 , & V_266 ) ;
F_272 ( F_203 , NULL ) ;
#ifdef F_109
F_273 ( F_206 , NULL ) ;
#endif
F_272 ( V_314 , NULL ) ;
#ifdef F_109
F_273 ( V_315 , NULL ) ;
#endif
V_292 =
V_316 |
V_317 |
V_318 |
V_319 |
V_320 |
V_206 |
V_321 | V_322 ;
F_274 ( NULL ,
V_292 ,
V_323 , NULL ) ;
F_274 ( V_205 ,
V_292 ,
V_323 , NULL ) ;
#ifdef F_109
F_274 ( V_324 ,
V_292 ,
V_323 , NULL ) ;
F_274 ( V_325 ,
V_292 ,
V_323 , NULL ) ;
F_275 ( & V_120 , & V_20 ) ;
#endif
F_276 () ;
V_22 = F_277 () ;
if ( * V_22 != '\0' ) {
V_271 = 1000 ;
}
V_291 = F_278 ( L_172 ) ;
if ( V_267 != NULL ) {
F_2 ( V_36 , V_8 ,
L_173
L_174
L_175 ,
V_267 ) ;
F_11 ( V_267 ) ;
}
F_279 ( V_326 , NULL , ( T_1 ) V_291 ) ;
F_280 ( V_327 , V_328 ,
F_279 , ( T_1 ) V_291 ,
V_329 , V_330 , V_331 ,
V_332 ) ;
F_279 ( V_333 , NULL , ( T_1 ) V_291 ) ;
#ifdef F_281
F_282 () ;
#endif
F_283 () ;
F_279 ( V_334 , NULL , ( T_1 ) V_291 ) ;
F_284 () ;
V_255 = F_224 ( & V_239 , & V_240 ) ;
V_159 = F_141 ( V_255 -> V_160 , F_137 , NULL ) ;
F_279 ( V_335 , NULL , ( T_1 ) V_291 ) ;
F_285 () ;
F_286 ( & V_20 ) ;
F_287 () ;
while ( ( V_269 = F_258 ( V_265 , V_266 , V_298 ) ) != - 1 ) {
switch ( V_269 ) {
case 'a' :
case 'b' :
case 'c' :
case 'f' :
case 'k' :
case 'H' :
case 'p' :
case 'i' :
#ifdef F_129
case 'I' :
#endif
case 's' :
case 'S' :
case 'w' :
case 'y' :
#if F_130 ( F_126 ) || F_130 ( F_129 )
case 'B' :
#endif
#ifdef F_109
V_297 = F_288 ( & V_120 , V_269 , V_308 ,
& V_276 ) ;
if( V_297 != 0 ) {
exit ( V_297 ) ;
}
#else
V_280 = TRUE ;
V_270 = TRUE ;
#endif
break;
#if F_130 ( V_336 ) || F_130 ( V_337 )
case 'K' :
F_289 ( V_308 ) ;
break;
#endif
case 'C' :
break;
case 'd' :
V_286 = V_308 ;
break;
case 'j' :
V_294 = TRUE ;
break;
case 'g' :
V_293 = F_290 ( V_308 , L_176 ) ;
break;
case 'J' :
V_287 = V_308 ;
break;
case 'l' :
#ifdef F_109
V_169 = TRUE ;
#else
V_280 = TRUE ;
V_270 = TRUE ;
#endif
break;
case 'L' :
#ifdef F_109
V_277 = TRUE ;
#else
V_280 = TRUE ;
V_270 = TRUE ;
#endif
break;
case 'm' :
F_11 ( V_255 -> V_338 ) ;
V_255 -> V_338 = F_8 ( V_308 ) ;
break;
case 'n' :
V_115 = V_339 ;
break;
case 'N' :
if ( V_115 == V_116 )
V_115 = V_339 ;
V_290 = F_291 ( V_308 , & V_115 ) ;
if ( V_290 != '\0' ) {
F_135 ( L_177 ,
V_290 ) ;
exit ( 1 ) ;
}
break;
case 'o' :
switch ( F_292 ( V_308 ) ) {
case V_340 :
break;
case V_341 :
F_135 ( L_178 , V_308 ) ;
exit ( 1 ) ;
break;
case V_342 :
switch ( F_293 ( V_308 ) ) {
case V_340 :
break;
case V_341 :
F_135 ( L_178 , V_308 ) ;
exit ( 1 ) ;
break;
case V_342 :
case V_343 :
F_135 ( L_179 ,
V_308 ) ;
exit ( 1 ) ;
break;
default:
F_10 () ;
}
break;
case V_343 :
F_135 ( L_180 ,
V_308 ) ;
exit ( 1 ) ;
break;
default:
F_10 () ;
}
break;
case 'P' :
break;
case 'r' :
V_260 = F_8 ( V_308 ) ;
break;
case 'R' :
V_285 = V_308 ;
break;
case 't' :
if ( strcmp ( V_308 , L_181 ) == 0 )
F_67 ( V_79 ) ;
else if ( strcmp ( V_308 , L_182 ) == 0 )
F_67 ( V_344 ) ;
else if ( strcmp ( V_308 , L_183 ) == 0 )
F_67 ( V_345 ) ;
else if ( strcmp ( V_308 , L_184 ) == 0 )
F_67 ( V_346 ) ;
else if ( strcmp ( V_308 , L_185 ) == 0 )
F_67 ( V_347 ) ;
else if ( strcmp ( V_308 , L_186 ) == 0 )
F_67 ( V_348 ) ;
else if ( strcmp ( V_308 , L_187 ) == 0 )
F_67 ( V_349 ) ;
else if ( strcmp ( V_308 , L_188 ) == 0 )
F_67 ( V_350 ) ;
else {
F_135 ( L_189 , V_308 ) ;
F_136 ( L_190 ) ;
F_136 ( L_191 ) ;
exit ( 1 ) ;
}
break;
case 'u' :
if ( strcmp ( V_308 , L_192 ) == 0 )
F_294 ( V_351 ) ;
else if ( strcmp ( V_308 , L_193 ) == 0 )
F_294 ( V_352 ) ;
else {
F_135 ( L_194 , V_308 ) ;
F_136 ( L_195 ) ;
exit ( 1 ) ;
}
break;
case 'X' :
break;
case 'z' :
if ( ! F_295 ( V_308 ) ) {
F_135 ( L_196 ) ;
F_136 ( L_197 ) ;
F_296 () ;
exit ( 1 ) ;
}
break;
default:
case '?' :
V_270 = TRUE ;
break;
}
}
if ( ! V_270 ) {
V_265 -= V_307 ;
V_266 += V_307 ;
if ( V_265 >= 1 ) {
if ( V_260 != NULL ) {
F_135 ( L_198 ) ;
V_270 = TRUE ;
} else {
V_260 = F_8 ( V_266 [ 0 ] ) ;
}
V_265 -- ;
V_266 ++ ;
}
if ( V_265 != 0 ) {
F_135 ( L_199 , V_266 [ 0 ] ) ;
V_270 = TRUE ;
}
}
if ( V_270 ) {
#ifndef F_109
if ( V_280 ) {
F_135 ( L_200 ) ;
}
#endif
F_125 ( FALSE ) ;
exit ( 1 ) ;
}
#ifdef F_109
if ( V_120 . V_353 -> V_70 == 0 ) {
F_297 ( & V_120 ) ;
}
#endif
#ifdef F_109
if ( V_276 && V_277 ) {
F_135 ( L_201 ) ;
exit ( 1 ) ;
}
if ( V_277 ) {
if ( V_260 ) {
F_135 ( L_202 ) ;
exit ( 1 ) ;
}
if ( V_120 . V_354 ) {
F_135 ( L_203 ) ;
exit ( 1 ) ;
}
} else {
if ( V_276 && V_260 ) {
F_135 ( L_204 ) ;
exit ( 1 ) ;
}
if ( V_120 . V_354 ) {
if ( V_120 . V_355 == NULL ) {
F_135 ( L_205 ) ;
V_120 . V_354 = FALSE ;
}
if ( ! V_120 . V_356 && ! V_120 . V_357 ) {
F_135 ( L_206 ) ;
}
}
}
if ( V_276 || V_277 ) {
if ( ! F_298 ( & V_120 ,
( V_255 -> V_358 ) ? F_299 ( V_255 -> V_358 ) : NULL ) ) {
exit ( 2 ) ;
}
}
if ( V_277 ) {
T_38 * V_359 ;
T_20 V_360 ;
T_39 V_361 ;
for ( V_360 = 0 ; V_360 < V_120 . V_353 -> V_70 ; V_360 ++ ) {
V_361 = F_300 ( V_120 . V_353 , T_39 , V_360 ) ;
if ( V_361 . V_362 ) {
#if F_130 ( F_129 )
V_359 = F_301 ( V_361 . V_106 , V_361 . V_363 , & V_279 ) ;
#else
V_359 = F_301 ( V_361 . V_106 , FALSE , & V_279 ) ;
#endif
if ( V_359 == NULL ) {
F_135 ( L_37 , V_279 ) ;
F_11 ( V_279 ) ;
exit ( 2 ) ;
}
if ( V_359 -> V_364 == NULL ) {
F_135 ( L_207 , V_361 . V_106 ) ;
exit ( 2 ) ;
}
#if F_130 ( F_129 )
F_302 ( V_359 , V_361 . V_106 , V_361 . V_363 ) ;
#else
F_302 ( V_359 , V_361 . V_106 , FALSE ) ;
#endif
F_303 ( V_359 ) ;
}
}
exit ( 0 ) ;
}
F_304 ( & V_120 , V_365 ) ;
F_305 ( & V_120 ) ;
#endif
F_306 () ;
#ifdef F_109
if ( ( V_120 . V_366 == 0 ) &&
( V_110 . V_358 != NULL ) ) {
T_20 V_360 ;
T_39 V_361 ;
for ( V_360 = 0 ; V_360 < V_120 . V_353 -> V_70 ; V_360 ++ ) {
V_361 = F_300 ( V_120 . V_353 , T_39 , V_360 ) ;
if ( ! V_361 . V_367 && strcmp ( V_361 . V_164 , V_110 . V_358 ) == 0 ) {
V_361 . V_362 = TRUE ;
V_120 . V_366 ++ ;
V_120 . V_353 = F_307 ( V_120 . V_353 , V_360 ) ;
F_308 ( V_120 . V_353 , V_360 , V_361 ) ;
break;
}
}
}
#endif
if ( V_239 == NULL && V_240 == NULL ) {
F_309 () ;
}
F_310 ( & V_20 . V_38 , V_255 -> V_54 , TRUE ) ;
V_284 = F_311 ( V_368 ) ;
#if F_312 ( 3 , 0 , 0 )
#else
F_313 ( V_284 ) ;
F_11 ( V_284 ) ;
V_284 = F_314 ( V_368 , FALSE , FALSE ) ;
F_313 ( V_284 ) ;
#endif
F_11 ( V_284 ) ;
F_315 () ;
F_316 () ;
F_317 () ;
F_174 ( V_291 ) ;
F_318 ( V_281 , V_282 , V_283 , V_255 ) ;
F_319 ( & V_273 , & V_274 ) ;
if ( V_273 != NULL && V_274 != 0 ) {
F_2 ( V_36 , V_8 ,
L_171 ,
V_273 , F_227 ( V_274 ) ) ;
}
F_160 ( V_80 . V_170 ) ;
F_320 () ;
F_321 () ;
#ifdef F_109
F_154 ( V_169 ) ;
#endif
switch ( F_322 () ) {
case V_369 :
break;
case V_370 :
case V_371 :
default:
V_80 . V_372 = 0 ;
}
F_323 ( V_119 ) ;
F_324 () ;
F_325 () ;
#ifdef F_109
F_326 () ;
#endif
F_118 ( V_119 ) ;
F_141 ( V_271 , F_144 , NULL ) ;
if ( V_286 ) {
T_3 * V_4 ;
V_4 = F_327 ( F_328 ( F_4 ( F_5 ( V_119 ) , V_373 ) ) ) ;
F_16 ( F_17 ( V_4 ) , V_286 ) ;
F_18 ( & V_20 , V_286 , FALSE ) ;
}
if ( V_260 ) {
F_329 ( TRUE ) ;
F_230 ( V_260 ) ;
if ( V_285 != NULL ) {
if ( ! F_330 ( V_285 , & V_288 ) ) {
F_331 ( V_119 , V_285 ) ;
V_289 = TRUE ;
}
}
if ( ! V_289 ) {
if ( F_332 ( & V_20 , V_260 , FALSE , & V_275 ) == V_374 ) {
V_20 . V_288 = V_288 ;
F_333 () ;
switch ( F_334 ( & V_20 , FALSE ) ) {
case V_375 :
case V_376 :
if( V_293 != 0 ) {
F_335 ( & V_20 , V_293 ) ;
} else if ( V_287 != NULL ) {
if ( ! F_330 ( V_287 , & V_295 ) ) {
F_331 ( V_119 , V_287 ) ;
} else {
F_336 ( & V_20 , V_295 , V_294 ) ;
}
}
break;
case V_377 :
exit ( 0 ) ;
break;
}
if ( ! F_337 ( V_260 ) ) {
char * V_378 = V_260 ;
char * V_379 = F_338 () ;
V_260 = F_27 ( L_208 , V_379 , V_380 , V_260 ) ;
F_11 ( V_378 ) ;
F_11 ( V_379 ) ;
}
V_268 = F_179 ( V_260 ) ;
F_180 ( V_268 ) ;
F_11 ( V_260 ) ;
V_260 = NULL ;
} else {
if ( V_288 != NULL )
F_339 ( V_288 ) ;
V_20 . V_288 = NULL ;
F_329 ( FALSE ) ;
F_170 ( FALSE ) ;
F_171 ( FALSE ) ;
}
}
} else {
#ifdef F_109
if ( V_276 ) {
if ( V_120 . V_355 != NULL ) {
V_268 = F_179 ( F_8 ( V_120 . V_355 ) ) ;
F_180 ( V_268 ) ;
F_11 ( V_268 ) ;
}
F_329 ( FALSE ) ;
F_230 ( V_260 ) ;
if ( V_120 . V_381 -> V_70 == 0 )
F_340 ( & V_120 ) ;
if ( F_341 ( & V_120 ) ) {
F_333 () ;
}
} else {
F_329 ( FALSE ) ;
F_230 ( V_260 ) ;
F_170 ( FALSE ) ;
F_171 ( FALSE ) ;
}
if ( ! V_276 && ! V_120 . V_382 . V_383 ) {
V_120 . V_382 . V_383 = F_8 ( F_277 () ) ;
}
#else
F_329 ( FALSE ) ;
F_230 ( V_260 ) ;
F_170 ( FALSE ) ;
F_171 ( FALSE ) ;
#endif
}
F_342 () ;
F_254 ( FALSE ) ;
#ifdef F_207
V_226 = F_208 ( V_229 , NULL ) ;
F_209 ( V_226 , F_183 ( V_197 ) ) ;
F_343 ( V_226 ) ;
#endif
F_204 ( V_205 , V_320 , L_209 ) ;
F_344 () ;
F_345 () ;
F_346 () ;
F_347 ( & V_300 ) ;
#ifdef F_126
F_348 ( V_119 ) ;
#ifdef F_207
F_349 ( V_226 ) ;
#endif
F_350 () ;
F_131 () ;
#endif
exit ( 0 ) ;
}
int T_40
F_351 ( struct V_384 * V_385 ,
struct V_384 * V_386 ,
char * V_387 ,
int V_388 )
{
T_41 V_389 ;
F_352 () ;
memset ( & V_389 , 0 , sizeof( V_389 ) ) ;
V_389 . V_390 = sizeof( V_389 ) ;
V_389 . V_391 = V_392 ;
F_353 ( & V_389 ) ;
F_354 ( L_210 ) ;
V_393 = FALSE ;
V_394 = FALSE ;
return main ( V_395 , V_396 ) ;
}
void
F_127 ( void )
{
if ( V_264 ) {
return;
}
if ( ! V_393 ) {
if ( ! F_355 ( V_397 ) ) {
if ( F_356 () ) {
V_394 = TRUE ;
F_357 ( F_358 ( L_211 ) ) ;
} else {
return;
}
}
F_359 ( L_212 , L_181 , V_398 ) ;
F_359 ( L_213 , L_214 , stdout ) ;
F_359 ( L_213 , L_214 , V_152 ) ;
fprintf ( stdout , L_14 ) ;
fprintf ( V_152 , L_14 ) ;
atexit ( F_131 ) ;
V_393 = TRUE ;
}
}
static void
F_131 ( void )
{
if ( V_394 ) {
printf ( L_215 ) ;
F_360 () ;
}
F_361 () ;
}
static void
V_323 ( const char * V_399 , T_37 V_400 ,
const char * V_401 , T_1 T_18 V_25 )
{
T_42 V_402 ;
struct V_403 * V_404 ;
const char * V_405 ;
if( ( V_400 & V_406 & V_110 . V_407 ) == 0 &&
V_110 . V_407 != 0 ) {
return;
}
#ifdef F_126
if ( V_110 . V_256 != V_408 || V_400 & V_316 ) {
F_127 () ;
}
if ( V_393 ) {
#endif
switch( V_400 & V_406 ) {
case V_316 :
V_405 = L_216 ;
break;
case V_317 :
V_405 = L_217 ;
break;
case V_318 :
V_405 = L_218 ;
break;
case V_319 :
V_405 = L_219 ;
break;
case V_320 :
V_405 = L_220 ;
break;
case V_206 :
V_405 = L_221 ;
break;
default:
fprintf ( V_152 , L_222 , V_400 ) ;
V_405 = NULL ;
F_10 () ;
}
time ( & V_402 ) ;
V_404 = localtime ( & V_402 ) ;
fprintf ( V_152 , L_223 ,
V_404 -> V_409 , V_404 -> V_410 , V_404 -> V_411 ,
V_399 != NULL ? V_399 : L_9 ,
V_405 , V_401 ) ;
#ifdef F_126
if( V_400 & V_316 ) {
printf ( L_215 ) ;
F_360 () ;
}
} else {
F_362 ( V_399 , V_400 , V_401 , T_18 ) ;
}
#endif
}
static void F_363 ( T_3 * T_9 , T_1 V_1 ) {
F_364 ( F_365 ( V_1 ) , T_9 ) ;
}
static T_3 * F_366 ( T_8 V_412 )
{
switch( V_412 ) {
case ( V_413 ) :
return NULL ;
case ( V_414 ) :
return V_161 ;
case ( V_415 ) :
return V_162 ;
case ( V_416 ) :
return V_103 ;
default:
F_10 () ;
return NULL ;
}
}
void F_320 ( void ) {
T_3 * V_417 , * V_418 ;
T_3 * V_419 , * V_420 ;
T_10 V_421 = FALSE ;
F_348 ( V_422 ) ;
F_367 ( F_5 ( V_423 ) ) ;
F_367 ( F_5 ( V_424 ) ) ;
F_367 ( F_5 ( V_425 ) ) ;
#ifdef F_217
F_367 ( F_5 ( V_426 ) ) ;
#endif
F_367 ( F_5 ( V_161 ) ) ;
F_367 ( F_5 ( V_162 ) ) ;
F_367 ( F_5 ( V_103 ) ) ;
F_367 ( F_5 ( V_427 ) ) ;
F_367 ( F_5 ( V_428 ) ) ;
F_367 ( F_5 ( V_429 ) ) ;
F_367 ( F_5 ( V_430 ) ) ;
F_367 ( F_5 ( V_431 ) ) ;
F_367 ( F_5 ( V_432 ) ) ;
F_368 ( F_365 ( V_422 ) , F_363 , V_422 ) ;
F_368 ( F_365 ( V_428 ) , F_363 , V_428 ) ;
F_368 ( F_365 ( V_429 ) , F_363 , V_429 ) ;
F_368 ( F_365 ( V_430 ) , F_363 , V_430 ) ;
F_368 ( F_365 ( V_431 ) , F_363 , V_431 ) ;
F_369 ( V_427 ) ;
F_370 ( F_371 ( V_422 ) , V_423 , FALSE , TRUE , 0 ) ;
F_370 ( F_371 ( V_422 ) , V_424 , FALSE , TRUE , 0 ) ;
if ( ! V_110 . V_433 ) {
F_370 ( F_371 ( V_422 ) , V_425 , FALSE , TRUE , 1 ) ;
}
#ifdef F_217
F_370 ( F_371 ( V_422 ) , V_426 , FALSE , TRUE , 1 ) ;
#endif
switch( V_110 . V_434 ) {
case ( V_435 ) :
V_127 = V_428 ;
V_130 = V_429 ;
V_421 = FALSE ;
break;
case ( V_436 ) :
V_127 = V_428 ;
V_130 = V_430 ;
V_421 = FALSE ;
break;
case ( V_437 ) :
V_127 = V_428 ;
V_130 = V_430 ;
V_421 = TRUE ;
break;
case ( V_438 ) :
V_127 = V_430 ;
V_130 = V_428 ;
V_421 = FALSE ;
break;
case ( V_439 ) :
V_127 = V_430 ;
V_130 = V_428 ;
V_421 = TRUE ;
break;
case ( V_440 ) :
V_127 = V_430 ;
V_130 = V_431 ;
V_421 = FALSE ;
break;
default:
V_127 = NULL ;
V_130 = NULL ;
F_10 () ;
}
if ( V_421 ) {
V_417 = V_130 ;
V_419 = F_366 ( V_110 . V_441 ) ;
V_420 = F_366 ( V_110 . V_442 ) ;
V_418 = F_366 ( V_110 . V_443 ) ;
} else {
V_417 = F_366 ( V_110 . V_441 ) ;
V_418 = V_130 ;
V_419 = F_366 ( V_110 . V_442 ) ;
V_420 = F_366 ( V_110 . V_443 ) ;
}
if ( V_417 != NULL )
F_372 ( F_117 ( V_127 ) , V_417 ) ;
if ( V_418 != NULL )
F_373 ( F_117 ( V_127 ) , V_418 ) ;
if ( V_419 != NULL )
F_374 ( F_117 ( V_130 ) , V_419 , TRUE , TRUE ) ;
if ( V_420 != NULL )
F_375 ( F_117 ( V_130 ) , V_420 , FALSE , FALSE ) ;
F_376 ( F_365 ( V_422 ) , V_127 ) ;
F_370 ( F_371 ( V_422 ) , V_432 , TRUE , TRUE , 0 ) ;
F_370 ( F_371 ( V_422 ) , V_427 , FALSE , TRUE , 0 ) ;
if ( V_110 . V_433 ) {
F_370 ( F_371 ( V_427 ) , V_425 , FALSE , TRUE , 1 ) ;
}
F_377 ( V_427 ) ;
F_104 () ;
F_378 ( V_422 ) ;
}
static void
F_379 ( T_3 * T_9 , T_1 V_1 )
{
T_10 * V_444 = V_1 ;
if ( ! * V_444 ) {
if ( F_380 ( T_9 ) )
* V_444 = TRUE ;
}
}
void
F_104 ( void )
{
T_10 V_445 ;
if ( V_80 . V_446 ) {
F_378 ( V_424 ) ;
} else {
F_348 ( V_424 ) ;
}
F_381 ( V_427 ) ;
if ( V_80 . V_447 ) {
F_378 ( V_425 ) ;
} else {
F_348 ( V_425 ) ;
}
#ifdef F_217
if ( V_80 . V_448 ) {
F_378 ( V_426 ) ;
} else {
F_348 ( V_426 ) ;
}
#endif
if ( V_80 . V_449 && V_118 ) {
F_378 ( V_161 ) ;
} else {
F_348 ( V_161 ) ;
}
if ( V_80 . V_450 && V_118 ) {
F_378 ( V_162 ) ;
} else {
F_348 ( V_162 ) ;
}
if ( V_80 . V_451 && V_118 ) {
F_378 ( V_103 ) ;
} else {
F_348 ( V_103 ) ;
}
if ( V_118 ) {
F_378 ( V_127 ) ;
} else {
F_348 ( V_127 ) ;
}
V_445 = FALSE ;
F_368 ( F_365 ( V_130 ) , F_379 ,
& V_445 ) ;
if ( V_445 ) {
F_378 ( V_130 ) ;
} else {
F_348 ( V_130 ) ;
}
if ( ! V_118 ) {
if( V_432 ) {
F_378 ( V_432 ) ;
}
} else {
F_348 ( V_432 ) ;
}
}
static T_10
F_382 ( T_3 * T_9 V_25 ,
T_25 * T_26 ,
T_1 V_1 V_25 )
{
T_43 V_452 = ( ( V_453 * ) T_26 ) -> V_452 ;
if( ( T_26 -> type ) == ( V_454 ) ) {
if( ! ( V_452 & V_455 ) ) {
F_383 () ;
}
}
return FALSE ;
}
static T_10
F_384 ( T_3 * V_21 V_25 , T_44 * T_26 , T_1 T_18 V_25 )
{
if ( T_26 -> V_456 == V_457 ) {
F_385 () ;
return TRUE ;
} else if ( T_26 -> V_456 == V_458 ) {
F_386 () ;
return TRUE ;
} else if ( T_26 -> V_121 & V_459 ) {
return FALSE ;
} else if ( isascii ( T_26 -> V_456 ) && isprint ( T_26 -> V_456 ) ) {
if ( V_460 && ! F_387 ( V_460 ) ) {
F_388 ( F_166 ( V_119 ) , V_460 ) ;
F_389 ( F_7 ( V_460 ) , - 1 ) ;
}
return FALSE ;
}
return FALSE ;
}
static void
F_318 ( T_8 V_281 , T_8 V_282 , T_8 V_283 , T_34 * V_255 )
{
T_45 * V_461 ;
V_119 = F_390 ( V_462 , L_9 ) ;
F_150 ( L_107 ) ;
F_391 ( V_119 , L_224 ) ;
F_392 ( V_119 , L_225 , F_393 ( F_113 ) ,
NULL ) ;
F_392 ( F_5 ( V_119 ) , L_226 ,
F_393 ( F_382 ) , NULL ) ;
F_392 ( F_5 ( V_119 ) , L_227 ,
F_393 ( F_384 ) , NULL ) ;
V_422 = F_394 ( V_463 , 1 , FALSE ) ;
F_395 ( F_365 ( V_422 ) , 0 ) ;
F_376 ( F_365 ( V_119 ) , V_422 ) ;
F_378 ( V_422 ) ;
V_423 = F_396 ( & V_461 ) ;
#if F_130 ( V_464 ) || F_130 ( F_207 )
if( ! V_255 -> V_465 ) {
#endif
F_397 ( F_166 ( V_119 ) , V_461 ) ;
F_378 ( V_423 ) ;
#if F_130 ( V_464 ) || F_130 ( F_207 )
}
#endif
V_424 = F_398 () ;
F_378 ( V_424 ) ;
V_425 = F_399 () ;
V_161 = F_400 () ;
F_401 ( V_161 , - 1 , V_281 ) ;
F_402 ( V_161 ) ;
V_162 = F_403 ( V_255 , & V_109 ) ;
F_401 ( V_162 , - 1 , V_282 ) ;
F_378 ( V_162 ) ;
F_392 ( F_404 ( F_98 ( V_109 ) ) ,
L_228 , F_393 ( F_74 ) , NULL ) ;
F_392 ( V_109 , L_229 , F_393 ( V_466 ) ,
F_4 ( F_5 ( V_467 ) , V_468 ) ) ;
F_378 ( V_109 ) ;
V_103 = F_405 () ;
F_401 ( V_103 , - 1 , V_283 ) ;
F_378 ( V_103 ) ;
F_392 ( V_103 , L_229 , F_393 ( V_466 ) ,
F_4 ( F_5 ( V_467 ) , V_469 ) ) ;
V_428 = F_406 ( V_463 ) ;
F_378 ( V_428 ) ;
V_429 = F_406 ( V_463 ) ;
F_378 ( V_429 ) ;
V_430 = F_406 ( V_470 ) ;
F_378 ( V_430 ) ;
V_431 = F_406 ( V_470 ) ;
F_378 ( V_431 ) ;
#ifdef F_217
V_426 = F_407 () ;
F_378 ( V_426 ) ;
#endif
V_427 = F_408 () ;
F_378 ( V_427 ) ;
V_432 = F_409 () ;
F_378 ( V_432 ) ;
}
static void
F_329 ( T_10 V_471 )
{
F_103 ( V_471 ) ;
F_378 ( V_119 ) ;
F_118 ( V_119 ) ;
while ( F_410 () ) F_411 () ;
F_383 () ;
F_412 ( F_146 ( V_119 ) ) ;
#ifdef F_217
V_448 ( V_426 ) ;
#endif
}
void
F_287 ( void )
{
#ifdef F_109
V_120 . V_382 . V_472 = V_110 . V_473 ;
V_120 . V_474 = V_110 . V_475 ;
V_120 . V_476 = V_110 . V_477 ;
V_120 . V_478 = V_110 . V_479 ;
V_169 = V_110 . V_480 ;
#endif
V_115 = V_110 . V_481 ;
}
static void F_413 ( const T_2 * V_482 )
{
char * V_483 , * V_484 , * V_485 ;
if ( F_414 ( V_482 , & V_483 ) == - 1 ) {
F_2 ( V_7 , V_8 ,
L_230 ,
V_483 , F_227 ( V_486 ) ) ;
F_11 ( V_483 ) ;
}
if ( F_415 ( V_482 , V_482 , TRUE , & V_485 ,
& V_483 , & V_484 ) == - 1 ) {
F_2 ( V_7 , V_8 ,
L_231 ,
V_485 , V_484 , V_483 , F_227 ( V_486 ) ) ;
F_11 ( V_485 ) ;
F_11 ( V_483 ) ;
F_11 ( V_484 ) ;
}
}
void F_416 ( const T_2 * V_482 )
{
char * V_239 , * V_240 ;
char * V_273 ;
int V_274 ;
if ( ! F_259 ( V_482 , FALSE ) ) {
if ( F_259 ( V_482 , TRUE ) ) {
F_413 ( V_482 ) ;
} else {
return;
}
}
if ( V_482 && strcmp ( V_482 , F_417 () ) == 0 ) {
return;
}
F_106 ( V_119 ) ;
if ( F_259 ( F_417 () , FALSE ) ) {
F_107 () ;
}
F_260 ( V_482 ) ;
F_418 () ;
F_419 ( V_487 ) ;
F_420 () ;
F_421 () ;
( void ) F_224 ( & V_239 , & V_240 ) ;
F_266 ( & V_273 , & V_274 ) ;
if ( V_273 != NULL && V_274 != 0 ) {
F_2 ( V_36 , V_8 ,
L_166 ,
V_273 , F_227 ( V_274 ) ) ;
}
if ( V_80 . V_312 &&
F_267 ( V_80 . V_312 ) == V_313 ) {
F_180 ( V_80 . V_312 ) ;
}
F_67 ( V_80 . V_81 ) ;
F_294 ( V_80 . V_488 ) ;
F_160 ( V_80 . V_170 ) ;
F_287 () ;
F_306 () ;
F_422 () ;
F_423 () ;
F_419 ( V_489 ) ;
F_424 () ;
F_425 () ;
if ( V_239 == NULL && V_240 == NULL ) {
F_309 () ;
}
F_426 () ;
F_427 () ;
F_94 () ;
V_20 . V_38 . V_112 = FALSE ;
F_322 () ;
F_321 () ;
F_115 () ;
}
void F_428 ( void )
{
F_429 ( & V_20 ) ;
F_430 () ;
}
T_20 F_431 ( T_2 * V_106 , T_2 * V_490 )
{
#if F_130 ( V_491 )
T_46 V_492 ;
char * V_493 ;
#endif
#if F_130 ( F_126 )
if ( V_490 && ( strstr ( V_490 , L_232 ) != NULL ||
strstr ( V_490 , L_233 ) != NULL ) ) {
return V_494 ;
} else if ( V_490 && ( strstr ( V_490 , L_234 ) != NULL ||
strstr ( V_490 , L_235 ) != NULL ) ) {
return V_495 ;
} else if ( V_490 && strstr ( V_490 , L_236 ) != NULL ||
strstr ( V_106 , L_237 ) ) {
return V_496 ;
} else if ( V_490 && strstr ( V_490 , L_238 ) != NULL ) {
return V_497 ;
}
#elif F_130 ( V_498 )
if ( strcmp ( V_106 , L_239 ) == 0 ) {
return V_495 ;
}
#elif F_130 ( V_491 )
V_493 = F_27 ( L_240 , V_106 ) ;
if ( V_493 != NULL ) {
if ( F_432 ( V_493 , & V_492 ) == 0 ) {
F_11 ( V_493 ) ;
return V_495 ;
}
}
if ( strstr ( V_106 , L_241 ) != NULL ) {
return V_497 ;
}
if ( strstr ( V_106 , L_242 ) != NULL ) {
return V_499 ;
}
#endif
if ( F_433 ( V_106 , L_243 , 5 ) == 0 ) {
return V_500 ;
}
if ( F_433 ( V_106 , L_244 , 6 ) == 0 ) {
return V_500 ;
}
if ( V_490 && strstr ( V_490 , L_245 ) != NULL ) {
return V_500 ;
}
return V_501 ;
}
void
F_297 ( T_32 * V_189 )
{
T_11 * V_502 , * V_503 , * V_278 ;
T_47 * V_504 , * V_505 ;
char * V_506 ;
T_2 * V_507 ;
T_38 * V_359 = NULL ;
T_8 V_508 ;
T_48 V_509 ;
T_49 * V_510 ;
int V_511 = 0 , V_360 , V_275 ;
T_20 V_173 = 0 , V_512 ;
T_50 * V_513 , * V_514 ;
T_51 * V_515 = NULL ;
T_52 * V_516 ;
T_39 V_361 ;
T_4 * V_517 ;
T_53 V_518 ;
T_10 V_519 = FALSE ;
if ( V_189 -> V_353 -> V_70 > 0 ) {
for ( V_360 = ( int ) V_189 -> V_353 -> V_70 - 1 ; V_360 >= 0 ; V_360 -- ) {
V_361 = F_300 ( V_189 -> V_353 , T_39 , V_360 ) ;
if ( V_361 . V_520 ) {
V_189 -> V_353 = F_307 ( V_189 -> V_353 , V_360 ) ;
}
}
}
V_278 = F_261 ( & V_275 , NULL ) ;
V_173 = 0 ;
for ( V_502 = V_278 ; V_502 != NULL ; V_502 = F_434 ( V_502 ) ) {
V_504 = V_502 -> V_1 ;
V_517 = F_12 ( L_9 ) ;
V_511 = 0 ;
if ( strstr ( V_504 -> V_106 , L_246 ) ) {
continue;
}
V_361 . V_106 = F_8 ( V_504 -> V_106 ) ;
V_361 . V_367 = FALSE ;
V_361 . V_521 = FALSE ;
V_505 = F_435 ( sizeof( T_47 ) ) ;
V_505 -> V_106 = F_8 ( V_504 -> V_106 ) ;
V_505 -> V_490 = F_8 ( V_504 -> V_490 ) ;
V_505 -> V_522 = V_504 -> V_522 ;
V_507 = F_436 ( V_504 -> V_106 ) ;
if ( V_507 != NULL ) {
V_506 = F_27 ( L_247 , V_507 , V_504 -> V_106 ) ;
F_11 ( V_507 ) ;
} else {
if ( V_504 -> V_490 != NULL ) {
V_506 = F_27 ( L_247 , V_504 -> V_490 , V_504 -> V_106 ) ;
} else {
V_506 = F_8 ( V_504 -> V_106 ) ;
}
}
if ( V_504 -> V_522 ) {
V_361 . V_164 = F_27 ( L_248 , V_506 ) ;
} else {
V_361 . V_164 = F_8 ( V_506 ) ;
}
F_11 ( V_506 ) ;
V_361 . V_362 = FALSE ;
if ( F_437 ( V_504 -> V_106 ) ) {
V_361 . V_367 = TRUE ;
}
V_361 . type = F_431 ( V_504 -> V_106 , V_504 -> V_490 ) ;
V_509 = F_438 ( V_504 -> V_106 ) ;
V_359 = F_301 ( V_504 -> V_106 , V_509 . V_523 , NULL ) ;
for (; ( V_510 = F_439 ( V_504 -> V_524 , V_511 ) ) != NULL ; V_511 ++ ) {
V_514 = F_435 ( sizeof( T_50 ) ) ;
if ( V_511 != 0 ) {
F_13 ( V_517 , L_14 ) ;
}
V_513 = ( T_50 * ) V_510 -> V_1 ;
if ( V_513 ) {
V_514 -> V_525 = V_513 -> V_525 ;
switch ( V_513 -> V_525 ) {
case V_526 :
V_514 -> V_513 . V_527 = V_513 -> V_513 . V_527 ;
F_13 ( V_517 , F_440 ( ( T_6 * ) & V_513 -> V_513 . V_527 ) ) ;
break;
case V_528 :
memcpy ( V_514 -> V_513 . V_529 , V_513 -> V_513 . V_529 , sizeof( V_513 -> V_513 ) ) ;
F_13 ( V_517 , F_441 ( (struct V_530 * ) & V_513 -> V_513 . V_529 ) ) ;
break;
default:
break;
}
} else {
F_11 ( V_514 ) ;
V_514 = NULL ;
}
if ( V_514 ) {
V_505 -> V_524 = F_442 ( V_505 -> V_524 , V_514 ) ;
}
}
#ifdef F_443
V_361 . V_520 = TRUE ;
V_361 . V_531 . V_532 = V_533 ;
V_361 . V_531 . V_534 . V_535 = F_8 ( V_189 -> V_382 . V_535 ) ;
V_361 . V_531 . V_534 . V_536 = F_8 ( V_189 -> V_382 . V_536 ) ;
V_361 . V_531 . V_534 . V_537 = V_189 -> V_382 . V_537 ;
V_361 . V_531 . V_534 . V_538 = F_8 ( V_189 -> V_382 . V_538 ) ;
V_361 . V_531 . V_534 . V_539 = F_8 ( V_189 -> V_382 . V_539 ) ;
V_361 . V_531 . V_534 . V_540 = V_189 -> V_382 . V_540 ;
V_361 . V_531 . V_534 . V_541 = V_189 -> V_382 . V_541 ;
V_361 . V_531 . V_534 . V_542 = V_189 -> V_382 . V_542 ;
#endif
#ifdef F_444
V_361 . V_531 . V_543 = V_189 -> V_382 . V_543 ;
V_361 . V_531 . V_544 = V_189 -> V_382 . V_544 ;
#endif
V_508 = 0 ;
V_361 . V_545 = NULL ;
if ( V_359 != NULL ) {
#if F_130 ( F_129 )
V_361 . V_546 = V_509 . V_523 ;
V_361 . V_363 = V_359 -> V_547 ;
#endif
for ( V_503 = V_359 -> V_364 ; V_503 != NULL ; V_503 = F_434 ( V_503 ) ) {
V_516 = V_503 -> V_1 ;
if ( V_508 == 0 ) {
V_361 . V_548 = V_516 -> V_549 ;
}
V_515 = ( T_51 * ) F_445 ( sizeof( T_51 ) ) ;
if ( V_516 -> V_490 != NULL ) {
V_515 -> V_549 = V_516 -> V_549 ;
V_515 -> V_106 = F_27 ( L_37 , V_516 -> V_490 ) ;
} else {
V_515 -> V_549 = - 1 ;
V_515 -> V_106 = F_27 ( L_249 , V_516 -> V_106 ) ;
}
V_361 . V_545 = F_49 ( V_361 . V_545 , V_515 ) ;
V_508 ++ ;
}
} else {
V_509 . V_523 = FALSE ;
#if F_130 ( F_129 )
V_361 . V_546 = FALSE ;
V_361 . V_363 = FALSE ;
#endif
V_361 . V_548 = - 1 ;
}
V_361 . V_550 = F_8 ( V_517 -> V_155 ) ;
V_361 . V_551 = V_511 ;
V_361 . V_520 = TRUE ;
V_361 . V_504 = * V_505 ;
V_361 . V_552 = 0 ;
V_361 . V_553 = V_189 -> V_382 . V_472 ;
V_361 . V_554 = V_189 -> V_382 . V_554 ;
V_361 . V_555 = V_189 -> V_382 . V_555 ;
V_361 . V_383 = F_8 ( V_189 -> V_382 . V_383 ) ;
#if F_130 ( F_126 ) || F_130 ( F_129 )
V_361 . V_556 = 1 ;
#endif
if ( V_189 -> V_381 -> V_70 > 0 ) {
for ( V_512 = 0 ; V_512 < V_189 -> V_381 -> V_70 ; V_512 ++ ) {
V_518 = F_300 ( V_189 -> V_381 , T_53 , V_512 ) ;
if ( strcmp ( V_518 . V_106 , V_361 . V_106 ) == 0 ) {
#if F_130 ( F_129 )
V_361 . V_556 = V_518 . V_557 ;
V_361 . V_546 = V_518 . V_523 ;
#endif
V_361 . V_553 = V_518 . V_472 ;
V_361 . V_554 = V_518 . V_554 ;
V_361 . V_555 = V_518 . V_555 ;
V_361 . V_383 = F_8 ( V_518 . V_383 ) ;
V_361 . V_548 = V_518 . V_558 ;
V_361 . V_362 = TRUE ;
V_189 -> V_366 ++ ;
break;
}
}
}
if ( V_189 -> V_353 -> V_70 <= V_173 ) {
F_446 ( V_189 -> V_353 , V_361 ) ;
V_173 = V_189 -> V_353 -> V_70 ;
} else {
F_308 ( V_189 -> V_353 , V_173 , V_361 ) ;
}
if ( V_359 != NULL ) {
F_303 ( V_359 ) ;
}
F_15 ( V_517 , TRUE ) ;
V_173 ++ ;
}
F_263 ( V_278 ) ;
for ( V_512 = 0 ; V_512 < V_189 -> V_381 -> V_70 ; V_512 ++ ) {
V_518 = F_300 ( V_189 -> V_381 , T_53 , V_512 ) ;
V_519 = FALSE ;
for ( V_360 = 0 ; V_360 < ( int ) V_189 -> V_353 -> V_70 ; V_360 ++ ) {
V_361 = F_300 ( V_189 -> V_353 , T_39 , V_360 ) ;
if ( strcmp ( V_361 . V_106 , V_518 . V_106 ) == 0 ) {
V_519 = TRUE ;
break;
}
}
if ( ! V_519 ) {
V_361 . V_106 = F_8 ( V_518 . V_106 ) ;
V_361 . V_164 = F_27 ( L_37 , V_361 . V_106 ) ;
V_361 . V_367 = FALSE ;
V_361 . V_362 = TRUE ;
V_361 . type = V_559 ;
#if F_130 ( F_126 ) || F_130 ( F_129 )
V_361 . V_556 = V_518 . V_557 ;
#endif
#if F_130 ( F_129 )
V_361 . V_546 = V_518 . V_523 ;
V_361 . V_363 = FALSE ;
#endif
V_361 . V_553 = V_518 . V_472 ;
V_361 . V_554 = V_518 . V_554 ;
V_361 . V_555 = V_518 . V_555 ;
V_361 . V_383 = F_8 ( V_518 . V_383 ) ;
V_361 . V_548 = V_518 . V_558 ;
V_361 . V_550 = NULL ;
V_361 . V_551 = 0 ;
V_361 . V_552 = 0 ;
V_361 . V_545 = NULL ;
V_361 . V_520 = TRUE ;
V_361 . V_521 = FALSE ;
F_446 ( V_189 -> V_353 , V_361 ) ;
V_189 -> V_366 ++ ;
}
}
}
void F_447 ( T_2 * V_560 )
{
T_2 * V_561 ;
T_20 V_360 ;
T_39 V_361 ;
T_10 V_519 = FALSE ;
T_11 * V_562 = NULL , * V_563 ;
if ( V_560 != NULL ) {
for ( V_561 = strtok ( V_560 , L_250 ) ; V_561 ; V_561 = strtok ( NULL , L_250 ) ) {
V_562 = F_49 ( V_562 , V_561 ) ;
}
}
for ( V_360 = 0 ; V_360 < V_120 . V_353 -> V_70 ; V_360 ++ ) {
V_361 = F_300 ( V_120 . V_353 , T_39 , V_360 ) ;
V_519 = FALSE ;
for ( V_563 = V_562 ; V_563 != NULL ; V_563 = F_434 ( V_563 ) ) {
if ( strcmp ( V_563 -> V_1 , V_361 . V_106 ) == 0 ) {
V_361 . V_367 = TRUE ;
if ( V_361 . V_362 ) {
V_361 . V_362 = FALSE ;
V_120 . V_366 -- ;
}
V_519 = TRUE ;
break;
}
}
if ( ! V_519 ) {
V_361 . V_367 = FALSE ;
}
V_120 . V_353 = F_307 ( V_120 . V_353 , V_360 ) ;
F_308 ( V_120 . V_353 , V_360 , V_361 ) ;
}
}
