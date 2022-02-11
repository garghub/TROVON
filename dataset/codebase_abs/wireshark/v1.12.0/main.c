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
F_47 ( & V_22 , V_18 . V_52 , & V_18 . V_53 ,
F_48 ( V_49 , & V_18 . V_54 ) , V_49 , & V_18 . V_37 ) ;
F_49 ( & V_22 , TRUE , TRUE ) ;
if ( F_39 ( V_36 ) ) {
V_50 = F_50 ( V_50 , F_51 ( L_37 , V_18 . V_37 . V_43 . V_44 [ V_36 ] ) ) ;
}
for ( V_48 = 0 ; V_48 < V_18 . V_37 . V_55 ; V_48 ++ ) {
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
T_2 * V_54 = NULL ;
V_49 = ( T_13 * ) F_43 ( V_45 ) ;
if ( V_49 != NULL ) {
T_14 V_22 ;
if ( ! F_44 ( & V_18 , V_49 ) )
return NULL ;
F_45 ( & V_22 , V_18 . V_51 , F_54 ( & V_18 . V_37 ) , FALSE ) ;
F_46 ( & V_22 , & V_18 . V_37 ) ;
F_47 ( & V_22 , V_18 . V_52 , & V_18 . V_53 ,
F_48 ( V_49 , & V_18 . V_54 ) ,
V_49 , & V_18 . V_37 ) ;
F_49 ( & V_22 , TRUE , TRUE ) ;
if ( ( V_18 . V_37 . V_56 [ V_36 ] ) ||
( strchr ( V_18 . V_37 . V_43 . V_44 [ V_36 ] , ',' ) == NULL ) )
{
if ( strlen ( V_18 . V_37 . V_43 . V_43 [ V_36 ] ) != 0 &&
strlen ( V_18 . V_37 . V_43 . V_44 [ V_36 ] ) != 0 ) {
if ( V_18 . V_37 . V_38 [ V_36 ] == V_57 ) {
T_15 * V_58 = F_55 ( V_18 . V_37 . V_59 [ V_36 ] ) ;
if ( V_58 && V_58 -> V_60 == - 1 ) {
V_54 = F_56 ( V_18 . V_37 . V_43 . V_43 [ V_36 ] ) ;
} else if ( V_58 && F_57 ( V_58 -> type ) ) {
V_54 = F_51 ( L_38 , V_18 . V_37 . V_43 . V_43 [ V_36 ] ,
V_18 . V_37 . V_43 . V_44 [ V_36 ] ) ;
}
}
if ( V_54 == NULL ) {
V_54 = F_51 ( L_39 , V_18 . V_37 . V_43 . V_43 [ V_36 ] ,
V_18 . V_37 . V_43 . V_44 [ V_36 ] ) ;
}
}
}
F_52 ( & V_22 ) ;
}
return V_54 ;
}
void
F_58 ( T_4 V_19 , T_5 V_2 )
{
F_1 ( ( T_1 * ) F_19 ( F_20 ( V_19 ) , V_23 ) ,
V_2 ,
F_53 ( ( T_1 * ) V_19 ) ) ;
}
void
F_59 ( T_1 * T_6 V_24 , T_4 V_19 V_24 , T_16 V_2 )
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
T_2 * V_70 = F_60 ( V_18 . V_21 , V_18 . V_22 ) ;
F_11 ( V_16 , V_70 ) ;
F_9 ( V_70 ) ;
}
break;
default:
break;
}
if ( V_16 -> V_71 == 0 ) {
F_61 ( V_18 . V_21 , V_63 ) ;
F_11 ( V_16 , V_63 ) ;
}
if ( V_16 -> V_71 == 0 ) {
F_2 ( V_6 , V_7 , L_40 ) ;
} else {
F_12 ( V_16 ) ;
}
F_13 ( V_16 , TRUE ) ;
}
void
F_62 ( T_11 V_72 , T_13 * V_73 , T_9 V_45 ) {
if ( V_45 == - 1 )
return;
if ( V_72 ) {
V_73 -> V_74 . V_75 = 1 ;
V_18 . V_76 ++ ;
} else {
V_73 -> V_74 . V_75 = 0 ;
V_18 . V_76 -- ;
}
F_63 ( & V_18 ) ;
if ( ! V_73 -> V_74 . V_75 && ! V_73 -> V_74 . V_77 ) {
F_64 () ;
V_18 . V_78 -- ;
F_65 () ;
F_66 () ;
}
F_67 () ;
}
static void F_68 ( T_4 T_8 V_24 , T_9 V_26 , T_4 V_19 V_24 )
{
switch( V_26 ) {
case ( V_79 ) :
F_69 ( V_80 ) ;
V_81 . V_82 = V_80 ;
F_70 ( & V_18 ) ;
F_67 () ;
break;
case ( V_83 ) :
break;
default:
F_8 () ;
}
if ( V_18 . V_84 ) {
F_62 ( ! V_18 . V_84 -> V_74 . V_75 ,
V_18 . V_84 , V_18 . V_85 ) ;
}
}
void
F_71 ( T_1 * T_6 V_24 , T_4 V_19 V_24 , T_17 V_2 )
{
static T_1 * V_86 = NULL ;
switch( V_2 ) {
case V_87 :
if ( V_18 . V_84 ) {
if( V_81 . V_82 != V_80 && V_18 . V_84 -> V_74 . V_75 == 0 ) {
V_86 = ( T_1 * ) F_2 ( V_33 , V_88 ,
L_41
L_42
L_43 ,
F_34 () , F_35 () ) ;
F_36 ( V_86 , F_68 , NULL ) ;
} else {
F_62 ( ! V_18 . V_84 -> V_74 . V_75 ,
V_18 . V_84 , V_18 . V_85 ) ;
}
}
break;
case V_89 :
F_72 ( & V_18 , V_90 ) ;
break;
case V_91 :
F_72 ( & V_18 , V_92 ) ;
break;
}
}
void
F_73 ( T_1 * T_6 V_24 , T_4 V_19 V_24 , int V_2 V_24 )
{
F_74 ( & V_18 , V_90 ) ;
}
void
F_75 ( T_1 * T_6 V_24 , T_4 V_19 V_24 , int V_2 V_24 )
{
F_74 ( & V_18 , V_92 ) ;
}
static void
F_76 ( T_18 * V_93 , T_4 T_19 V_24 )
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
if ( ! F_77 ( V_93 , & V_102 , & V_103 ) )
{
V_99 = F_78 ( V_104 ) ;
if ( V_99 == NULL )
return;
V_100 = F_79 ( V_99 , & V_98 ) ;
if ( V_100 == NULL )
return;
F_80 ( & V_18 ) ;
F_81 ( V_99 , V_100 ,
V_18 . V_84 , NULL , V_98 ) ;
F_82 ( V_93 , & V_18 ) ;
return;
}
F_83 ( V_102 , & V_103 , 1 , & V_94 , - 1 ) ;
if ( ! V_94 ) return;
F_84 ( V_104 , V_94 -> V_105 ) ;
V_99 = F_78 ( V_104 ) ;
V_100 = F_79 ( V_99 , & V_98 ) ;
F_3 ( V_100 != NULL ) ;
V_18 . V_21 = V_94 ;
F_85 ( & V_18 ) ;
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
F_86 ( V_95 , L_44 , sizeof V_95 ) ;
} else {
F_87 ( V_95 , sizeof V_95 , L_45 , V_101 ) ;
}
F_88 () ;
if ( V_97 ) {
F_89 ( L_46 ,
( V_96 ) ? V_94 -> V_31 -> V_106 : V_94 -> V_31 -> V_107 ,
V_94 -> V_31 -> V_68 , V_95 ) ;
} else {
F_89 ( L_37 , L_9 ) ;
}
}
F_81 ( V_99 , V_100 , V_18 . V_84 , V_94 ,
V_98 ) ;
F_82 ( V_93 , & V_18 ) ;
}
void F_90 ( T_1 * T_10 V_24 , T_4 V_19 V_24 )
{
if ( V_18 . V_22 -> V_109 )
F_91 ( V_18 . V_22 -> V_109 , V_110 ) ;
}
void F_92 ( T_1 * T_10 V_24 , T_4 V_19 V_24 )
{
if ( V_18 . V_22 -> V_109 )
F_93 ( V_18 . V_22 -> V_109 , V_110 ) ;
}
void F_94 ( T_1 * T_10 V_24 , T_4 V_19 V_24 )
{
if ( V_18 . V_21 ) {
F_95 ( V_57 , V_18 . V_21 -> V_31 -> V_107 ,
V_18 . V_21 -> V_31 -> V_68 , 0 ) ;
F_96 () ;
if ( ! V_111 . V_112 ) {
F_97 () ;
}
V_18 . V_113 = FALSE ;
}
}
void F_98 ( T_1 * T_10 V_24 , T_4 V_19 V_24 )
{
T_24 * V_114 ;
V_114 = F_99 ( F_100 ( V_110 ) , V_18 . V_21 ) ;
if( V_114 ) {
F_101 ( F_100 ( V_110 ) , V_114 , TRUE ) ;
F_102 ( V_114 ) ;
}
}
void F_103 ( T_1 * T_10 V_24 , T_4 V_19 V_24 )
{
T_24 * V_114 ;
V_114 = F_99 ( F_100 ( V_110 ) , V_18 . V_21 ) ;
if( V_114 ) {
F_104 ( F_100 ( V_110 ) , V_114 ) ;
F_102 ( V_114 ) ;
}
}
void F_105 ( T_1 * T_10 V_24 , T_4 V_19 V_24 )
{
static const T_25 V_115 = { TRUE , TRUE , TRUE , TRUE , TRUE , FALSE } ;
if ( V_18 . V_22 -> V_109 ) {
F_106 ( V_18 . V_22 -> V_109 , V_110 , & V_115 ) ;
}
}
static void
F_107 ( T_11 V_116 )
{
F_108 ( V_116 ) ;
#ifdef F_109
F_110 ( V_116 ) ;
F_111 ( V_116 ) ;
#endif
}
static void
F_112 ( T_11 V_117 )
{
V_118 = V_117 ;
F_113 () ;
}
static void
F_114 ( T_11 V_119 )
{
F_115 ( V_119 ) ;
F_116 ( V_119 ) ;
}
void
F_117 ( T_11 V_120 , T_11 V_121 )
{
F_118 ( V_120 , V_121 ) ;
F_119 ( V_120 , V_121 ) ;
}
T_11
F_120 ( void )
{
F_121 ( V_122 ) ;
F_122 () ;
F_123 () ;
#ifdef F_109
F_124 ( & V_123 ) ;
#endif
if ( V_18 . V_124 == V_125 ) {
V_18 . V_124 = V_126 ;
return TRUE ;
} else {
F_125 ( & V_18 ) ;
F_126 () ;
return FALSE ;
}
}
static T_11
F_127 ( T_1 * T_10 V_24 , T_26 * T_27 V_24 , T_4 V_19 V_24 )
{
if ( V_127 )
return TRUE ;
if ( F_128 ( & V_18 , TRUE , L_47 ) )
return F_120 () ;
else
return TRUE ;
}
static void
F_129 ( void )
{
if ( V_81 . V_128 && V_81 . V_129 )
F_130 ( F_131 ( V_130 ) , V_81 . V_129 ) ;
if ( V_81 . V_131 && V_81 . V_132 ) {
F_130 ( F_131 ( V_133 ) , V_81 . V_132 ) ;
}
}
static void
F_132 ( T_1 * T_10 )
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
F_133 ( T_10 , & V_134 ) ;
F_129 () ;
F_134 () ;
}
static void
F_121 ( T_1 * T_10 )
{
T_28 V_134 ;
F_135 ( T_10 , & V_134 ) ;
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
V_81 . V_129 = F_136 ( F_131 ( V_130 ) ) ;
V_81 . V_132 = F_136 ( F_131 ( V_133 ) ) ;
F_137 () ;
}
void
F_138 ( T_1 * T_10 V_24 , T_4 V_19 V_24 )
{
if ( F_128 ( & V_18 , TRUE , L_47 ) )
F_120 () ;
}
static void
F_139 ( T_11 V_151 ) {
T_29 * V_152 ;
#ifdef F_140
F_141 () ;
#endif
if ( V_151 ) {
V_152 = stdout ;
fprintf ( V_152 , L_48 V_153 L_49
L_50
L_51
L_14
L_37 ,
V_154 , F_142 () ) ;
} else {
V_152 = V_155 ;
}
fprintf ( V_152 , L_14 ) ;
fprintf ( V_152 , L_52 ) ;
fprintf ( V_152 , L_14 ) ;
#ifdef F_109
fprintf ( V_152 , L_53 ) ;
fprintf ( V_152 , L_54 ) ;
fprintf ( V_152 , L_55 ) ;
fprintf ( V_152 , L_56 ) ;
fprintf ( V_152 , L_57 ) ;
fprintf ( V_152 , L_58 ) ;
fprintf ( V_152 , L_59 ) ;
fprintf ( V_152 , L_60 ) ;
#ifdef F_143
fprintf ( V_152 , L_61 ) ;
#endif
#if F_144 ( F_140 ) || F_144 ( F_143 )
fprintf ( V_152 , L_62 , V_156 ) ;
#endif
fprintf ( V_152 , L_63 ) ;
fprintf ( V_152 , L_64 ) ;
fprintf ( V_152 , L_65 ) ;
fprintf ( V_152 , L_14 ) ;
fprintf ( V_152 , L_66 ) ;
fprintf ( V_152 , L_67 ) ;
fprintf ( V_152 , L_68 ) ;
fprintf ( V_152 , L_69 ) ;
fprintf ( V_152 , L_70 ) ;
fprintf ( V_152 , L_71 ) ;
fprintf ( V_152 , L_72 ) ;
fprintf ( V_152 , L_73 ) ;
fprintf ( V_152 , L_74 ) ;
#endif
#ifdef F_145
fprintf ( V_152 , L_75 ) ;
fprintf ( V_152 , L_76 ) ;
#endif
fprintf ( V_152 , L_77 ) ;
fprintf ( V_152 , L_78 ) ;
fprintf ( V_152 , L_14 ) ;
fprintf ( V_152 , L_79 ) ;
fprintf ( V_152 , L_80 ) ;
fprintf ( V_152 , L_81 ) ;
fprintf ( V_152 , L_82 ) ;
fprintf ( V_152 , L_14 ) ;
fprintf ( V_152 , L_83 ) ;
fprintf ( V_152 , L_84 ) ;
fprintf ( V_152 , L_85 ) ;
fprintf ( V_152 , L_86 ) ;
fprintf ( V_152 , L_87 ) ;
fprintf ( V_152 , L_88 ) ;
fprintf ( V_152 , L_89 ) ;
fprintf ( V_152 , L_90 ) ;
fprintf ( V_152 , L_91 ) ;
fprintf ( V_152 , L_92 ) ;
fprintf ( V_152 , L_93 ) ;
fprintf ( V_152 , L_94 ) ;
fprintf ( V_152 , L_14 ) ;
fprintf ( V_152 , L_95 ) ;
fprintf ( V_152 , L_96 ) ;
fprintf ( V_152 , L_14 ) ;
fprintf ( V_152 , L_97 ) ;
fprintf ( V_152 , L_98 ) ;
fprintf ( V_152 , L_99 ) ;
fprintf ( V_152 , L_100 ) ;
fprintf ( V_152 , L_101 ) ;
fprintf ( V_152 , L_102 ) ;
fprintf ( V_152 , L_103 ) ;
#ifndef F_140
fprintf ( V_152 , L_104 ) ;
#endif
#ifdef F_140
F_146 () ;
#endif
}
static void
F_147 ( void )
{
printf ( V_157 L_105 V_153 L_49
L_14
L_37
L_14
L_37
L_14
L_37 ,
V_154 , F_142 () , V_158 -> V_159 ,
V_160 -> V_159 ) ;
}
void
F_148 ( const char * V_161 , ... )
{
T_30 V_162 ;
#ifdef F_140
F_141 () ;
#endif
fprintf ( V_155 , L_106 ) ;
va_start ( V_162 , V_161 ) ;
vfprintf ( V_155 , V_161 , V_162 ) ;
va_end ( V_162 ) ;
fprintf ( V_155 , L_14 ) ;
}
void
F_149 ( const char * V_161 , ... )
{
T_30 V_162 ;
#ifdef F_140
F_141 () ;
#endif
va_start ( V_162 , V_161 ) ;
vfprintf ( V_155 , V_161 , V_162 ) ;
fprintf ( V_155 , L_14 ) ;
va_end ( V_162 ) ;
}
static T_11
F_150 ( T_4 V_19 V_24 )
{
F_151 ( FALSE ) ;
return TRUE ;
}
static T_11
F_152 ( T_4 V_19 V_24 )
{
if ( F_153 () ) {
if ( F_154 ( V_163 ) )
F_155 ( F_154 ( V_163 ) , NULL , TRUE ) ;
if ( F_154 ( V_164 ) )
F_155 ( F_154 ( V_164 ) , NULL , TRUE ) ;
}
return TRUE ;
}
void
F_156 ( T_31 * V_165 )
{
F_157 ( V_165 ) ;
F_158 ( V_165 ) ;
F_159 ( V_165 ) ;
}
void
F_160 ( T_11 V_166 )
{
F_161 ( V_166 ) ;
F_162 ( V_166 ) ;
V_167 = V_166 ;
}
void
F_163 ( T_11 V_168 )
{
F_164 ( V_168 ) ;
F_165 ( V_168 ) ;
if( V_168 != V_81 . V_168 ) {
V_81 . V_168 = V_168 ;
F_166 ( V_168 ) ;
F_25 () ;
}
}
static void
F_167 ( T_4 T_8 , T_9 V_26 V_24 , T_4 V_19 V_24 )
{
V_81 . V_169 = ! F_168 ( T_8 ) ;
}
static void
F_169 ( T_4 T_8 , T_9 V_26 V_24 , T_4 V_19 V_24 )
{
V_81 . V_170 = ! F_168 ( T_8 ) ;
}
static void
F_170 ( T_31 * V_165 )
{
if( V_165 -> V_171 > 10000 ) {
V_172 = ( T_1 * ) F_2 ( V_173 , V_174 ,
L_107 ,
F_34 () ,
F_35 () ) ;
F_171 ( F_172 ( V_172 ) , V_175 ) ;
}
F_173 () ;
F_174 () ;
F_157 ( NULL ) ;
F_158 ( NULL ) ;
F_159 ( NULL ) ;
F_114 ( FALSE ) ;
F_175 ( V_165 ) ;
F_107 ( FALSE ) ;
F_111 ( FALSE ) ;
F_85 ( V_165 ) ;
F_112 ( FALSE ) ;
F_176 () ;
}
static void
F_177 ( T_31 * V_165 V_24 )
{
if( V_172 != NULL ) {
F_178 ( V_172 ) ;
V_172 = NULL ;
}
}
static void
F_179 ( T_31 * V_165 V_24 )
{
F_180 () ;
F_112 ( TRUE ) ;
}
static void
F_181 ( T_31 * V_165 )
{
T_2 * V_176 ;
if ( ! V_165 -> V_177 && V_165 -> V_178 ) {
F_182 ( V_165 -> V_178 ) ;
V_176 = F_183 ( F_6 ( V_165 -> V_178 ) ) ;
F_184 ( V_176 ) ;
F_9 ( V_176 ) ;
}
F_156 ( V_165 ) ;
F_114 ( TRUE ) ;
}
static void
F_185 ( T_31 * V_165 )
{
T_2 * V_176 ;
if ( ! V_165 -> V_177 && V_165 -> V_178 ) {
F_182 ( V_165 -> V_178 ) ;
V_176 = F_183 ( F_6 ( V_165 -> V_178 ) ) ;
F_184 ( V_176 ) ;
F_9 ( V_176 ) ;
}
F_156 ( V_165 ) ;
}
static T_12 * F_186 (
const T_7 * V_179 ,
const T_7 * V_180 ,
const T_7 * V_181 ,
const T_7 * V_182 )
{
T_12 * V_183 = NULL ;
T_32 * V_184 ;
T_32 * V_185 ;
T_32 * V_186 ;
T_32 * V_187 ;
if( V_179 != NULL ) {
V_184 = F_187 ( - 1 , V_179 , FALSE , NULL ) ;
F_3 ( V_184 ) ;
V_183 = F_50 ( V_183 , V_184 ) ;
}
if( V_180 != NULL ) {
V_185 = F_187 ( - 1 , V_180 , FALSE , NULL ) ;
F_3 ( V_185 ) ;
V_183 = F_50 ( V_183 , V_185 ) ;
}
if( V_181 != NULL ) {
V_186 = F_187 ( - 1 , V_181 , FALSE , NULL ) ;
F_3 ( V_186 ) ;
V_183 = F_50 ( V_183 , V_186 ) ;
}
if( V_182 != NULL ) {
V_187 = F_187 ( - 1 , V_182 , FALSE , NULL ) ;
F_3 ( V_187 ) ;
V_183 = F_50 ( V_183 , V_187 ) ;
}
return V_183 ;
}
static void
F_188 ( T_33 * V_188 )
{
static T_12 * V_183 = NULL ;
F_189 ( ( T_31 * ) V_188 -> V_165 ) ;
if( V_183 == NULL ) {
V_183 = F_186 ( V_189 , V_190 , V_191 , V_192 ) ;
}
F_190 ( F_172 ( V_122 ) , V_183 ) ;
F_107 ( TRUE ) ;
F_111 ( TRUE ) ;
F_112 ( FALSE ) ;
}
static void
F_191 ( T_33 * V_188 )
{
F_189 ( ( T_31 * ) V_188 -> V_165 ) ;
F_107 ( TRUE ) ;
F_111 ( TRUE ) ;
F_114 ( TRUE ) ;
F_112 ( TRUE ) ;
}
static void
F_192 ( T_33 * V_188 )
{
T_31 * V_165 = ( T_31 * ) V_188 -> V_165 ;
static T_12 * V_183 = NULL ;
V_127 = FALSE ;
if ( ! V_165 -> V_177 && V_165 -> V_178 ) {
F_182 ( V_165 -> V_178 ) ;
}
F_107 ( FALSE ) ;
F_111 ( FALSE ) ;
F_156 ( V_165 ) ;
F_112 ( TRUE ) ;
if( V_183 == NULL ) {
V_183 = F_186 ( V_193 , V_194 , V_195 , V_196 ) ;
}
F_190 ( F_172 ( V_122 ) , V_183 ) ;
if( V_197 . V_198 ) {
F_120 () ;
}
}
static void
F_193 ( T_33 * V_188 V_24 )
{
F_112 ( FALSE ) ;
}
static void
F_194 ( T_33 * V_188 V_24 )
{
#if 0
capture_file *cf = (capture_file *)cap_session->cf;
#endif
static T_12 * V_183 = NULL ;
V_127 = FALSE ;
F_107 ( FALSE ) ;
F_111 ( FALSE ) ;
F_157 ( NULL ) ;
if( V_183 == NULL ) {
V_183 = F_186 ( V_193 , V_194 , V_195 , V_196 ) ;
}
F_190 ( F_172 ( V_122 ) , V_183 ) ;
if( V_197 . V_198 ) {
F_120 () ;
}
}
static void
F_195 ( T_33 * V_188 V_24 )
{
V_127 = TRUE ;
F_196 () ;
#ifdef F_109
F_197 () ;
F_198 () ;
#endif
}
static void
F_199 ( T_33 * V_188 V_24 )
{
static T_12 * V_183 = NULL ;
V_127 = FALSE ;
F_157 ( NULL ) ;
F_107 ( FALSE ) ;
F_111 ( FALSE ) ;
F_112 ( FALSE ) ;
if( V_183 == NULL ) {
V_183 = F_186 ( V_193 , V_194 , V_195 , V_196 ) ;
}
F_190 ( F_172 ( V_122 ) , V_183 ) ;
if( V_197 . V_198 ) {
F_120 () ;
}
}
static void
F_200 ( T_4 V_19 )
{
T_31 * V_165 = ( T_31 * ) V_19 ;
F_201 ( V_165 -> V_22 , V_110 , V_104 ) ;
F_202 ( V_165 -> V_22 -> V_109 , V_110 ) ;
if( V_165 -> V_199 &&
( V_165 -> V_200 != 0 || ( V_165 -> string && V_165 -> V_201 ) ) ) {
F_203 ( V_165 -> V_22 -> V_202 , V_165 -> V_200 ,
( V_203 * ) V_110 , V_165 -> V_22 -> V_109 ) ;
}
F_175 ( V_165 ) ;
}
static void
F_204 ( T_31 * V_165 )
{
while ( F_205 ( F_206 ( V_104 ) , 0 ) != NULL )
F_207 ( F_206 ( V_104 ) , 0 ) ;
F_208 ( V_104 , L_9 , NULL , NULL , V_110 ) ;
F_202 ( NULL , V_110 ) ;
F_175 ( V_165 ) ;
}
static void
F_209 ( T_31 * V_165 )
{
F_85 ( V_165 ) ;
}
static void
F_210 ( T_9 T_27 , T_4 V_19 , T_4 T_19 V_24 )
{
T_31 * V_165 = ( T_31 * ) V_19 ;
switch( T_27 ) {
case ( V_204 ) :
F_211 ( V_205 , V_206 , L_108 ) ;
F_212 ( V_165 ) ;
break;
case ( V_207 ) :
F_211 ( V_205 , V_206 , L_109 ) ;
F_170 ( V_165 ) ;
break;
case ( V_208 ) :
F_211 ( V_205 , V_206 , L_110 ) ;
F_177 ( V_165 ) ;
F_213 () ;
break;
case ( V_209 ) :
F_211 ( V_205 , V_206 , L_111 ) ;
F_179 ( V_165 ) ;
break;
case ( V_210 ) :
F_211 ( V_205 , V_206 , L_112 ) ;
F_181 ( V_165 ) ;
break;
case ( V_211 ) :
F_211 ( V_205 , V_206 , L_113 ) ;
F_179 ( V_165 ) ;
break;
case ( V_212 ) :
F_211 ( V_205 , V_206 , L_114 ) ;
F_181 ( V_165 ) ;
break;
case ( V_213 ) :
F_211 ( V_205 , V_206 , L_115 ) ;
break;
case ( V_214 ) :
F_211 ( V_205 , V_206 , L_116 ) ;
F_185 ( V_165 ) ;
break;
case ( V_215 ) :
F_211 ( V_205 , V_206 , L_117 ) ;
F_185 ( V_165 ) ;
break;
case ( V_216 ) :
F_200 ( V_165 ) ;
break;
case ( V_217 ) :
F_204 ( V_165 ) ;
break;
case ( V_218 ) :
F_209 ( V_165 ) ;
break;
case ( V_219 ) :
F_211 ( V_205 , V_206 , L_118 ) ;
break;
case ( V_220 ) :
F_211 ( V_205 , V_206 , L_119 ) ;
break;
case ( V_221 ) :
F_211 ( V_205 , V_206 , L_120 ) ;
break;
case ( V_222 ) :
F_211 ( V_205 , V_206 , L_121 ) ;
break;
case ( V_223 ) :
F_211 ( V_205 , V_206 , L_122 ) ;
break;
case ( V_224 ) :
F_211 ( V_205 , V_206 , L_123 ) ;
break;
case ( V_225 ) :
F_211 ( V_205 , V_206 , L_124 ) ;
break;
case ( V_226 ) :
F_211 ( V_205 , V_206 , L_125 ) ;
break;
default:
F_214 ( L_126 , T_27 ) ;
F_8 () ;
}
}
static void
F_215 ( T_9 T_27 , T_33 * V_188 , T_4 T_19 V_24 )
{
#ifdef F_216
T_34 * V_227 ;
#endif
switch( T_27 ) {
case ( V_228 ) :
F_211 ( V_205 , V_206 , L_127 ) ;
F_188 ( V_188 ) ;
break;
case ( V_229 ) :
F_211 ( V_205 , V_206 , L_128 ) ;
F_191 ( V_188 ) ;
#ifdef F_216
V_227 = ( T_34 * ) F_217 ( V_230 , NULL ) ;
F_218 ( V_227 , F_187 ( - 1 , V_191 , FALSE , NULL ) ) ;
#endif
break;
case ( V_231 ) :
break;
case ( V_232 ) :
F_211 ( V_205 , V_206 , L_129 ) ;
F_192 ( V_188 ) ;
break;
case ( V_233 ) :
F_211 ( V_205 , V_206 , L_130 ) ;
F_193 ( V_188 ) ;
break;
case ( V_234 ) :
F_211 ( V_205 , V_206 , L_131 ) ;
break;
case ( V_235 ) :
F_211 ( V_205 , V_206 , L_132 ) ;
F_194 ( V_188 ) ;
break;
case ( V_236 ) :
F_211 ( V_205 , V_206 , L_133 ) ;
#ifdef F_216
V_227 = ( T_34 * ) F_217 ( V_230 , NULL ) ;
F_218 ( V_227 , F_187 ( - 1 , V_196 , FALSE , NULL ) ) ;
#endif
F_195 ( V_188 ) ;
break;
case ( V_237 ) :
F_211 ( V_205 , V_206 , L_134 ) ;
F_199 ( V_188 ) ;
break;
default:
F_214 ( L_135 , T_27 ) ;
F_8 () ;
}
}
static void
F_219 ( T_3 * V_159 )
{
F_11 ( V_159 , L_136 ) ;
F_220 ( V_159 ,
#ifdef F_221
L_137 , F_221 , V_238 ,
V_239 ) ;
#else
L_138 ) ;
void
F_222 ( T_3 * V_159 )
{
F_223 ( V_159 ) ;
F_11 ( V_159 , L_139 ) ;
#ifdef F_224
#ifdef F_225
F_11 ( V_159 , L_140 ) ;
#else
F_11 ( V_159 , L_136 ) ;
F_11 ( V_159 , F_226 () ) ;
#endif
#else
F_11 ( V_159 , L_141 ) ;
#endif
F_11 ( V_159 , L_139 ) ;
#ifdef F_227
F_228 ( V_159 ) ;
#else
F_11 ( V_159 , L_142 ) ;
#endif
}
static void
F_229 ( T_3 * V_159 )
{
F_230 ( V_159 ) ;
#ifdef F_227
F_11 ( V_159 , L_139 ) ;
F_231 ( V_159 ) ;
#endif
if( F_232 () ) {
F_11 ( V_159 , L_139 ) ;
F_233 ( V_159 ) ;
}
}
static T_35 *
F_234 ( char * * V_240 , char * * V_241 )
{
int V_242 , V_243 ;
int V_244 , V_245 ;
int V_246 , V_247 ;
int V_248 , V_249 ;
char * V_250 , * V_251 ;
char * V_252 , * V_253 ;
int V_254 , V_255 ;
T_35 * V_256 ;
F_235 () ;
V_256 = F_236 ( & V_242 , & V_243 , & V_250 ,
& V_254 , & V_255 , & V_251 ) ;
if ( V_250 != NULL ) {
if ( V_242 != 0 ) {
F_2 ( V_35 , V_7 ,
L_143 ,
V_250 , F_237 ( V_242 ) ) ;
}
if ( V_243 != 0 ) {
F_2 ( V_35 , V_7 ,
L_144 ,
V_250 , F_237 ( V_243 ) ) ;
}
}
if ( V_251 != NULL ) {
if ( V_254 != 0 ) {
F_2 ( V_35 , V_7 ,
L_145 ,
V_251 , F_237 ( V_254 ) ) ;
}
if ( V_255 != 0 ) {
F_2 ( V_35 , V_7 ,
L_146 ,
V_251 , F_237 ( V_255 ) ) ;
}
F_9 ( V_251 ) ;
V_251 = NULL ;
}
#ifdef F_140
if ( V_256 -> V_257 == V_258 ) {
F_141 () ;
}
#endif
F_238 ( V_259 , & V_252 , & V_244 ) ;
if ( V_252 != NULL ) {
F_2 ( V_35 , V_7 ,
L_147 ,
V_252 , F_237 ( V_244 ) ) ;
F_9 ( V_252 ) ;
}
F_238 ( V_260 , & V_253 , & V_245 ) ;
if ( V_253 != NULL ) {
F_2 ( V_35 , V_7 ,
L_148 ,
V_253 , F_237 ( V_245 ) ) ;
F_9 ( V_253 ) ;
}
F_239 ( V_240 , & V_246 , & V_247 ,
V_241 , & V_248 , & V_249 ) ;
if ( * V_240 != NULL ) {
if ( V_246 != 0 ) {
F_2 ( V_35 , V_7 ,
L_149 ,
* V_240 , F_237 ( V_246 ) ) ;
}
if ( V_247 != 0 ) {
F_2 ( V_35 , V_7 ,
L_150 ,
* V_240 , F_237 ( V_247 ) ) ;
}
F_9 ( * V_240 ) ;
* V_240 = NULL ;
}
if ( * V_241 != NULL ) {
if ( V_248 != 0 ) {
F_2 ( V_35 , V_7 ,
L_151 ,
* V_241 , F_237 ( V_248 ) ) ;
}
if ( V_249 != 0 ) {
F_2 ( V_35 , V_7 ,
L_152 ,
* V_241 , F_237 ( V_249 ) ) ;
}
F_9 ( * V_241 ) ;
* V_241 = NULL ;
}
return V_256 ;
}
static void
#ifdef F_140
F_240 ( T_2 * V_261 )
#else
check_and_warn_user_startup( T_2 * V_261 V_24 )
#endif
{
T_2 * V_262 , * V_263 ;
T_4 V_264 ;
if ( F_241 () && V_81 . V_169 ) {
V_262 = F_242 () ;
V_263 = F_243 () ;
V_264 = F_2 ( V_35 , V_7 ,
L_153
L_154
L_155
L_156
L_157 , V_262 , V_263 ) ;
F_9 ( V_262 ) ;
F_9 ( V_263 ) ;
F_244 ( V_264 , L_158 ) ;
F_36 ( V_264 , F_167 , NULL ) ;
}
#ifdef F_140
if ( ! F_245 () && ! V_261 && ! F_246 () && V_81 . V_170 && F_247 () >= 6 ) {
V_264 = F_2 ( V_35 , V_7 ,
L_159
L_160 ) ;
F_244 ( V_264 , L_158 ) ;
F_36 ( V_264 , F_169 , NULL ) ;
}
#endif
}
int
main ( int V_265 , char * V_266 [] )
{
char * V_267 ;
char * V_268 ;
int V_269 ;
T_11 V_270 = FALSE ;
extern int V_271 ;
const T_2 * V_20 ;
#ifdef F_140
T_36 V_272 ;
#endif
char * V_273 ;
int V_274 ;
char * V_240 , * V_241 ;
int V_275 ;
#ifdef F_109
T_11 V_276 = FALSE ;
T_11 V_277 = FALSE ;
T_12 * V_278 ;
T_2 * V_279 ;
int V_280 ;
#else
T_11 V_281 = FALSE ;
#ifdef F_140
#ifdef F_227
T_2 * V_279 ;
#endif
#endif
#endif
T_9 V_282 = 280 , V_283 = 95 , V_284 = 75 ;
T_2 * V_285 , * V_261 = NULL , * V_286 = NULL , * V_287 = NULL , * V_288 = NULL ;
T_37 * V_289 = NULL ;
T_11 V_290 = FALSE ;
T_35 * V_256 ;
char V_291 ;
T_1 * V_292 = NULL ;
T_38 V_293 ;
T_21 V_294 = 0 ;
T_39 V_295 = V_90 ;
T_37 * V_296 = NULL ;
int V_297 ;
unsigned int V_298 = V_299 ;
#ifdef F_216
T_34 * V_227 ;
#endif
#ifdef F_109
#if F_144 ( F_140 ) || F_144 ( F_143 )
#define F_248 "B:"
#else
#define F_248 ""
#endif
#else
#define F_248 ""
#endif
#ifdef F_145
#define F_249 "A:"
#else
#define F_249 ""
#endif
#ifdef F_143
#define F_250 "I"
#else
#define F_250 ""
#endif
#define F_251 "a:" OPTSTRING_A "b:" OPTSTRING_B "c:C:Df:g:Hhi:" OPTSTRING_I "jJ:kK:lLm:nN:o:P:pr:R:Ss:t:u:vw:X:y:Y:z:"
static const char V_300 [] = F_251 ;
setlocale ( V_301 , L_9 ) ;
#ifdef F_140
F_252 ( V_265 , V_266 ) ;
F_253 () ;
#endif
F_254 () ;
F_255 () ;
V_267 = F_256 ( V_266 [ 0 ] , main ) ;
F_257 () ;
F_258 ( & V_302 ) ;
#ifdef F_140
F_259 () ;
F_260 () ;
#ifdef F_227
V_303 = F_261 () ;
switch ( V_303 ) {
case V_304 :
V_305 = F_262 ( & V_275 , & V_279 ) ;
if ( V_305 == NULL || F_263 ( V_305 ) == 0 ) {
if ( V_275 == V_306 && V_279 != NULL ) {
F_2 ( V_6 , V_7 , L_37 , L_161 ) ;
F_9 ( V_279 ) ;
}
V_307 = NULL ;
} else {
V_307 = F_264 ( V_305 ) ;
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
V_158 = F_10 ( L_162 ) ;
F_265 ( V_158 , F_219 , F_222 ) ;
V_160 = F_10 ( L_163 ) ;
F_266 ( V_160 , F_229 ) ;
F_267 ( V_157 L_105 V_153 L_49
L_14
L_37
L_14
L_37 ,
V_154 , V_158 -> V_159 , V_160 -> V_159 ) ;
#ifdef F_140
F_268 ( F_269 ( 1 , 1 ) , & V_272 ) ;
#endif
F_270 ( TRUE ) ;
F_271 ( & V_273 , & V_274 ) ;
if ( V_273 != NULL && V_274 != 0 ) {
F_2 ( V_35 , V_7 ,
L_164 ,
V_273 , F_237 ( V_274 ) ) ;
}
V_308 = 0 ;
V_297 = V_309 ;
while ( ( V_269 = F_272 ( V_265 , V_266 , V_300 ) ) != - 1 ) {
switch ( V_269 ) {
case 'C' :
if ( F_273 ( V_310 , FALSE ) ) {
F_274 ( V_310 ) ;
} else {
F_148 ( L_165 , V_310 ) ;
exit ( 1 ) ;
}
break;
case 'D' :
#ifdef F_109
V_278 = F_275 ( & V_275 , & V_279 , F_176 ) ;
if ( V_278 == NULL ) {
switch ( V_275 ) {
case V_311 :
case V_312 :
F_148 ( L_37 , V_279 ) ;
F_9 ( V_279 ) ;
break;
case V_313 :
F_148 ( L_166 ) ;
break;
}
exit ( 2 ) ;
}
#ifdef F_140
F_141 () ;
#endif
F_276 ( V_278 ) ;
F_277 ( V_278 ) ;
#ifdef F_140
F_146 () ;
#endif
exit ( 0 ) ;
#else
V_281 = TRUE ;
V_270 = TRUE ;
#endif
break;
case 'h' :
F_139 ( TRUE ) ;
exit ( 0 ) ;
break;
#ifdef F_140
case 'i' :
if ( strcmp ( V_310 , L_167 ) == 0 )
F_278 ( TRUE ) ;
break;
#endif
case 'P' :
if ( ! F_279 ( V_269 , V_310 ) ) {
F_148 ( L_168 , V_310 ) ;
exit ( 2 ) ;
}
break;
case 'v' :
#ifdef F_140
F_141 () ;
#endif
F_147 () ;
#ifdef F_140
F_146 () ;
#endif
exit ( 0 ) ;
break;
case 'X' :
F_280 ( V_310 ) ;
break;
case '?' :
break;
}
}
F_281 ( & V_273 , & V_274 ) ;
if ( V_273 != NULL && V_274 != 0 ) {
F_2 ( V_35 , V_7 ,
L_169 ,
V_273 , F_237 ( V_274 ) ) ;
}
if ( V_81 . V_314 &&
F_282 ( V_81 . V_314 ) == V_315 ) {
F_184 ( V_81 . V_314 ) ;
} else {
F_184 ( F_283 () ) ;
}
V_309 = V_297 ;
V_308 = 1 ;
#if ! F_284 ( 2 , 31 , 0 )
F_285 ( NULL ) ;
#endif
setlocale ( V_301 , L_9 ) ;
F_286 ( & V_265 , & V_266 ) ;
F_287 ( F_210 , NULL ) ;
#ifdef F_109
F_288 ( F_215 , NULL ) ;
#endif
F_287 ( V_316 , NULL ) ;
#ifdef F_109
F_288 ( V_317 , NULL ) ;
#endif
V_293 = ( T_38 )
( V_318 |
V_319 |
V_320 |
V_321 |
V_322 |
V_206 |
V_323 |
V_324 ) ;
F_289 ( NULL ,
V_293 ,
V_325 , NULL ) ;
F_289 ( V_205 ,
V_293 ,
V_325 , NULL ) ;
#ifdef F_109
F_289 ( V_326 ,
V_293 ,
V_325 , NULL ) ;
F_289 ( V_327 ,
V_293 ,
V_325 , NULL ) ;
F_290 ( & V_197 ) ;
F_291 ( & V_123 , ( void * ) & V_18 ) ;
#endif
F_292 ( V_328 , V_329 ,
V_330 , V_331 ) ;
F_293 () ;
V_20 = F_294 () ;
if ( * V_20 != '\0' ) {
V_271 = 1000 ;
}
V_292 = F_295 ( L_170 ) ;
if ( V_267 != NULL ) {
F_2 ( V_35 , V_7 ,
L_171
L_172
L_173 ,
V_267 ) ;
F_9 ( V_267 ) ;
}
F_296 () ;
#ifdef F_297
F_298 () ;
F_299 () ;
F_300 () ;
F_301 () ;
F_302 () ;
F_303 () ;
#endif
F_304 ( V_332 , NULL , ( T_4 ) V_292 ) ;
F_305 ( V_333 , V_334 ,
F_304 , ( T_4 ) V_292 ) ;
F_304 ( V_335 , NULL , ( T_4 ) V_292 ) ;
#ifdef F_297
F_306 () ;
#endif
F_307 () ;
F_304 ( V_336 , NULL , ( T_4 ) V_292 ) ;
V_256 = F_234 ( & V_240 , & V_241 ) ;
V_337 = F_308 ( V_256 -> V_338 , F_150 , NULL ) ;
F_304 ( V_339 , NULL , ( T_4 ) V_292 ) ;
F_309 () ;
F_310 ( & V_18 ) ;
F_311 () ;
while ( ( V_269 = F_272 ( V_265 , V_266 , V_300 ) ) != - 1 ) {
switch ( V_269 ) {
case 'a' :
case 'b' :
case 'c' :
case 'f' :
case 'k' :
case 'H' :
case 'p' :
case 'i' :
#ifdef F_143
case 'I' :
#endif
#ifdef F_145
case 'A' :
#endif
case 's' :
case 'S' :
case 'w' :
case 'y' :
#if F_144 ( F_140 ) || F_144 ( F_143 )
case 'B' :
#endif
#ifdef F_109
V_280 = F_312 ( & V_197 , V_269 , V_310 ,
& V_276 ) ;
if( V_280 != 0 ) {
exit ( V_280 ) ;
}
#else
V_281 = TRUE ;
V_270 = TRUE ;
#endif
break;
#if F_144 ( V_340 ) || F_144 ( V_341 )
case 'K' :
F_313 ( V_310 ) ;
break;
#endif
case 'C' :
break;
case 'j' :
V_295 = V_92 ;
break;
case 'g' :
V_294 = F_314 ( V_310 , L_174 ) ;
break;
case 'J' :
V_288 = V_310 ;
break;
case 'l' :
#ifdef F_109
V_167 = TRUE ;
#else
V_281 = TRUE ;
V_270 = TRUE ;
#endif
break;
case 'L' :
#ifdef F_109
V_277 = TRUE ;
#else
V_281 = TRUE ;
V_270 = TRUE ;
#endif
break;
case 'm' :
F_9 ( V_256 -> V_342 ) ;
V_256 -> V_342 = F_6 ( V_310 ) ;
break;
case 'n' :
V_343 . V_344 = FALSE ;
V_343 . V_345 = FALSE ;
V_343 . V_346 = FALSE ;
V_343 . V_347 = FALSE ;
break;
case 'N' :
V_291 = F_315 ( V_310 , & V_343 ) ;
if ( V_291 != '\0' ) {
F_148 ( L_175 ,
V_291 ) ;
exit ( 1 ) ;
}
break;
case 'o' :
switch ( F_316 ( V_310 ) ) {
case V_348 :
break;
case V_349 :
F_148 ( L_176 , V_310 ) ;
exit ( 1 ) ;
break;
case V_350 :
switch ( F_317 ( V_310 ) ) {
case V_348 :
break;
case V_349 :
F_148 ( L_176 , V_310 ) ;
exit ( 1 ) ;
break;
case V_350 :
case V_351 :
F_148 ( L_177 ,
V_310 ) ;
exit ( 1 ) ;
break;
default:
F_8 () ;
}
break;
case V_351 :
F_148 ( L_178 ,
V_310 ) ;
exit ( 1 ) ;
break;
default:
F_8 () ;
}
break;
case 'P' :
break;
case 'r' :
V_261 = F_6 ( V_310 ) ;
break;
case 'R' :
V_286 = V_310 ;
break;
case 't' :
if ( strcmp ( V_310 , L_179 ) == 0 )
F_69 ( V_80 ) ;
else if ( strcmp ( V_310 , L_180 ) == 0 )
F_69 ( V_352 ) ;
else if ( strcmp ( V_310 , L_181 ) == 0 )
F_69 ( V_353 ) ;
else if ( strcmp ( V_310 , L_182 ) == 0 )
F_69 ( V_354 ) ;
else if ( strcmp ( V_310 , L_183 ) == 0 )
F_69 ( V_355 ) ;
else if ( strcmp ( V_310 , L_184 ) == 0 )
F_69 ( V_356 ) ;
else if ( strcmp ( V_310 , L_185 ) == 0 )
F_69 ( V_357 ) ;
else if ( strcmp ( V_310 , L_186 ) == 0 )
F_69 ( V_358 ) ;
else if ( strcmp ( V_310 , L_187 ) == 0 )
F_69 ( V_359 ) ;
else if ( strcmp ( V_310 , L_188 ) == 0 )
F_69 ( V_360 ) ;
else {
F_148 ( L_189 , V_310 ) ;
F_149 (
L_190 ) ;
F_149 (
L_191 ) ;
F_149 (
L_192 ) ;
F_149 (
L_193 ) ;
F_149 (
L_194 ) ;
exit ( 1 ) ;
}
break;
case 'u' :
if ( strcmp ( V_310 , L_195 ) == 0 )
F_318 ( V_361 ) ;
else if ( strcmp ( V_310 , L_196 ) == 0 )
F_318 ( V_362 ) ;
else {
F_148 ( L_197 , V_310 ) ;
F_149 (
L_198 ) ;
exit ( 1 ) ;
}
break;
case 'X' :
break;
case 'Y' :
V_287 = V_310 ;
break;
case 'z' :
if ( ! F_319 ( V_310 ) ) {
F_148 ( L_199 ) ;
F_149 ( L_200 ) ;
F_320 () ;
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
V_265 -= V_309 ;
V_266 += V_309 ;
if ( V_265 >= 1 ) {
if ( V_261 != NULL ) {
F_148 ( L_201 ) ;
V_270 = TRUE ;
} else {
#ifndef F_216
V_261 = F_6 ( V_266 [ 0 ] ) ;
#endif
}
V_265 -- ;
V_266 ++ ;
}
if ( V_265 != 0 ) {
F_148 ( L_202 , V_266 [ 0 ] ) ;
V_270 = TRUE ;
}
}
if ( V_270 ) {
#ifndef F_109
if ( V_281 ) {
F_148 ( L_203 ) ;
}
#endif
F_139 ( FALSE ) ;
exit ( 1 ) ;
}
#ifdef F_109
F_321 ( F_176 ) ;
if ( V_276 && V_277 ) {
F_148 ( L_204 ) ;
exit ( 1 ) ;
}
if ( V_277 ) {
if ( V_261 ) {
F_148 ( L_205 ) ;
exit ( 1 ) ;
}
if ( V_197 . V_363 ) {
F_148 ( L_206 ) ;
exit ( 1 ) ;
}
} else {
if ( V_276 && V_261 ) {
F_148 ( L_207 ) ;
exit ( 1 ) ;
}
if ( V_197 . V_363 ) {
if ( V_197 . V_364 == NULL ) {
F_148 ( L_208 ) ;
V_197 . V_363 = FALSE ;
}
if ( ! V_197 . V_365 && ! V_197 . V_366 ) {
F_148 ( L_209 ) ;
}
}
}
if ( V_276 || V_277 ) {
V_280 = F_322 ( & V_197 ,
( ( V_256 -> V_367 ) && ( * V_256 -> V_367 != '\0' ) ) ? F_323 ( V_256 -> V_367 ) : NULL ) ;
if ( V_280 != 0 ) {
exit ( V_280 ) ;
}
}
if ( V_277 ) {
T_40 * V_368 ;
T_21 V_369 ;
T_41 V_370 ;
for ( V_369 = 0 ; V_369 < V_197 . V_371 -> V_71 ; V_369 ++ ) {
V_370 = F_324 ( V_197 . V_371 , T_41 , V_369 ) ;
if ( V_370 . V_372 ) {
#if F_144 ( F_143 )
V_368 = F_325 ( V_370 . V_107 , V_370 . V_373 , & V_279 , F_176 ) ;
#else
V_368 = F_325 ( V_370 . V_107 , FALSE , & V_279 , F_176 ) ;
#endif
if ( V_368 == NULL ) {
F_148 ( L_37 , V_279 ) ;
F_9 ( V_279 ) ;
exit ( 2 ) ;
}
if ( V_368 -> V_374 == NULL ) {
F_148 ( L_210 , V_370 . V_107 ) ;
exit ( 2 ) ;
}
#ifdef F_140
F_141 () ;
#endif
#if F_144 ( F_143 )
F_326 ( V_368 , V_370 . V_107 , V_370 . V_373 ) ;
#else
F_326 ( V_368 , V_370 . V_107 , FALSE ) ;
#endif
#ifdef F_140
F_146 () ;
#endif
F_327 ( V_368 ) ;
}
}
exit ( 0 ) ;
}
F_328 ( & V_197 , V_375 ) ;
F_329 ( & V_197 ) ;
#endif
F_330 () ;
#ifdef F_109
if ( ( V_197 . V_376 == 0 ) &&
( ( V_111 . V_367 != NULL ) && ( * V_256 -> V_367 != '\0' ) ) ) {
T_21 V_369 ;
T_41 V_370 ;
for ( V_369 = 0 ; V_369 < V_197 . V_371 -> V_71 ; V_369 ++ ) {
V_370 = F_324 ( V_197 . V_371 , T_41 , V_369 ) ;
if ( ! V_370 . V_377 && strstr ( V_111 . V_367 , V_370 . V_107 ) != NULL ) {
V_370 . V_372 = TRUE ;
V_197 . V_376 ++ ;
V_197 . V_371 = F_331 ( V_197 . V_371 , V_369 ) ;
F_332 ( V_197 . V_371 , V_369 , V_370 ) ;
break;
}
}
}
if ( V_197 . V_376 == 0 && V_197 . V_371 -> V_71 == 1 ) {
T_41 V_370 = F_324 ( V_197 . V_371 , T_41 , 0 ) ;
V_370 . V_372 = TRUE ;
V_197 . V_376 ++ ;
V_197 . V_371 = F_331 ( V_197 . V_371 , 0 ) ;
F_332 ( V_197 . V_371 , 0 , V_370 ) ;
}
#endif
if ( V_240 == NULL && V_241 == NULL ) {
F_333 () ;
}
F_334 ( & V_18 . V_37 , V_256 -> V_55 , TRUE ) ;
V_285 = F_335 ( V_378 ) ;
#if F_336 ( 3 , 0 , 0 )
#else
F_337 ( V_285 ) ;
F_9 ( V_285 ) ;
V_285 = F_338 ( V_378 , FALSE ) ;
F_337 ( V_285 ) ;
#endif
F_9 ( V_285 ) ;
F_339 () ;
F_340 () ;
F_341 () ;
F_178 ( V_292 ) ;
F_342 ( V_282 , V_283 , V_284 , V_256 ) ;
F_343 ( & V_273 , & V_274 ) ;
if ( V_273 != NULL && V_274 != 0 ) {
F_2 ( V_35 , V_7 ,
L_169 ,
V_273 , F_237 ( V_274 ) ) ;
}
F_166 ( V_81 . V_168 ) ;
F_344 () ;
F_345 () ;
#ifdef F_109
F_160 ( V_167 ) ;
#endif
switch ( F_346 () ) {
case V_379 :
break;
case V_380 :
case V_381 :
default:
V_81 . V_382 = 0 ;
}
F_347 ( V_122 ) ;
F_348 () ;
#ifdef F_109
F_349 () ;
#endif
F_132 ( V_122 ) ;
F_308 ( V_271 , F_152 , NULL ) ;
if ( V_261 ) {
F_350 ( TRUE ) ;
F_240 ( V_261 ) ;
if ( V_286 != NULL ) {
if ( ! F_351 ( V_286 , & V_289 ) ) {
F_352 ( V_122 , V_286 ) ;
V_290 = TRUE ;
}
}
if ( F_353 ( L_211 ) > 0 ) {
V_298 = F_354 ( F_355 ( L_211 ) ) ;
}
if ( ! V_290 ) {
if ( F_356 ( & V_18 , V_261 , V_298 , FALSE , & V_275 ) == V_383 ) {
V_18 . V_289 = V_289 ;
F_357 () ;
switch ( F_358 ( & V_18 , FALSE ) ) {
case V_384 :
case V_385 :
if( V_294 != 0 ) {
F_359 ( & V_18 , V_294 ) ;
} else if ( V_288 != NULL ) {
if ( ! F_351 ( V_288 , & V_296 ) ) {
F_352 ( V_122 , V_288 ) ;
} else {
F_360 ( & V_18 , V_296 , V_295 ) ;
}
}
break;
case V_386 :
exit ( 0 ) ;
break;
}
if ( ! F_361 ( V_261 ) ) {
char * V_387 = V_261 ;
char * V_388 = F_362 () ;
V_261 = F_27 ( L_212 , V_388 , V_389 , V_261 ) ;
F_9 ( V_387 ) ;
F_9 ( V_388 ) ;
}
V_268 = F_183 ( V_261 ) ;
F_184 ( V_268 ) ;
F_9 ( V_261 ) ;
V_261 = NULL ;
} else {
if ( V_289 != NULL )
F_363 ( V_289 ) ;
V_18 . V_289 = NULL ;
F_350 ( FALSE ) ;
F_107 ( FALSE ) ;
F_111 ( FALSE ) ;
}
}
} else {
#ifdef F_109
if ( V_276 ) {
if ( V_197 . V_364 != NULL ) {
V_268 = F_183 ( F_6 ( V_197 . V_364 ) ) ;
F_184 ( V_268 ) ;
F_9 ( V_268 ) ;
}
F_350 ( FALSE ) ;
F_240 ( V_261 ) ;
if ( V_197 . V_390 -> V_71 == 0 )
F_364 ( & V_197 ) ;
if ( F_365 ( & V_197 , & V_123 , F_176 ) ) {
F_357 () ;
}
} else {
F_350 ( FALSE ) ;
F_240 ( V_261 ) ;
F_107 ( FALSE ) ;
F_111 ( FALSE ) ;
}
if ( ! V_276 && ! V_197 . V_391 . V_392 ) {
V_197 . V_391 . V_392 = F_6 ( F_294 () ) ;
}
#else
F_350 ( FALSE ) ;
F_240 ( V_261 ) ;
F_107 ( FALSE ) ;
F_111 ( FALSE ) ;
#endif
}
if ( V_287 ) {
T_1 * V_1 ;
V_1 = F_366 ( F_367 ( F_19 ( F_20 ( V_122 ) , V_393 ) ) ) ;
F_14 ( F_15 ( V_1 ) , V_287 ) ;
F_16 ( & V_18 , V_287 , FALSE ) ;
}
F_368 () ;
F_270 ( FALSE ) ;
#ifdef F_216
V_227 = ( T_34 * ) F_217 ( V_230 , NULL ) ;
F_218 ( V_227 , F_187 ( - 1 , V_196 , FALSE , NULL ) ) ;
F_369 ( V_227 ) ;
#endif
F_211 ( V_205 , V_322 , L_213 ) ;
#ifdef F_109
F_370 () ;
#endif
F_371 () ;
F_372 () ;
#ifdef F_109
F_373 () ;
#endif
F_374 () ;
F_375 () ;
F_376 ( & V_302 ) ;
#ifdef F_216
F_377 ( V_227 ) ;
#endif
#ifdef F_140
F_378 ( V_122 ) ;
F_379 () ;
F_380 () ;
F_146 () ;
#endif
exit ( 0 ) ;
}
int T_42
F_381 ( struct V_394 * V_395 ,
struct V_394 * V_396 ,
char * V_397 ,
int V_398 )
{
T_43 V_399 ;
F_382 () ;
memset ( & V_399 , 0 , sizeof( V_399 ) ) ;
V_399 . V_400 = sizeof( V_399 ) ;
V_399 . V_401 = V_402 ;
F_383 ( & V_399 ) ;
F_384 ( L_214 ) ;
F_385 ( FALSE ) ;
F_386 ( FALSE ) ;
return main ( V_403 , V_404 ) ;
}
static void
V_325 ( const char * V_405 , T_38 V_406 ,
const char * V_407 , T_4 T_19 V_24 )
{
T_44 V_408 ;
struct V_409 * V_410 ;
const char * V_411 ;
if( ( V_406 & V_412 & V_111 . V_413 ) == 0 &&
V_111 . V_413 != 0 ) {
return;
}
#ifdef F_140
if ( V_111 . V_257 != V_414 || V_406 & V_318 ) {
F_141 () ;
}
if ( F_387 () ) {
#endif
switch( V_406 & V_412 ) {
case V_318 :
V_411 = L_215 ;
break;
case V_319 :
V_411 = L_216 ;
break;
case V_320 :
V_411 = L_217 ;
break;
case V_321 :
V_411 = L_218 ;
break;
case V_322 :
V_411 = L_219 ;
break;
case V_206 :
V_411 = L_220 ;
break;
default:
fprintf ( V_155 , L_221 , V_406 ) ;
V_411 = NULL ;
F_8 () ;
}
time ( & V_408 ) ;
V_410 = localtime ( & V_408 ) ;
fprintf ( V_155 , L_222 ,
V_410 -> V_415 , V_410 -> V_416 , V_410 -> V_417 ,
V_405 != NULL ? V_405 : L_9 ,
V_411 , V_407 ) ;
#ifdef F_140
if( V_406 & V_318 ) {
printf ( L_223 ) ;
F_388 () ;
}
} else {
F_389 ( V_405 , V_406 , V_407 , T_19 ) ;
}
#endif
}
static void F_390 ( T_1 * T_10 , T_4 V_19 ) {
F_391 ( F_392 ( V_19 ) , T_10 ) ;
}
static T_1 * F_393 ( T_9 V_418 )
{
switch( V_418 ) {
case ( V_419 ) :
return NULL ;
case ( V_420 ) :
return V_163 ;
case ( V_421 ) :
return V_164 ;
case ( V_422 ) :
return V_104 ;
default:
F_8 () ;
return NULL ;
}
}
void F_344 ( void ) {
T_1 * V_423 , * V_424 ;
T_1 * V_425 , * V_426 ;
T_11 V_427 = FALSE ;
F_378 ( V_428 ) ;
F_394 ( F_20 ( V_429 ) ) ;
F_394 ( F_20 ( V_430 ) ) ;
F_394 ( F_20 ( V_431 ) ) ;
F_394 ( F_20 ( V_432 ) ) ;
F_394 ( F_20 ( V_163 ) ) ;
F_394 ( F_20 ( V_164 ) ) ;
F_394 ( F_20 ( V_104 ) ) ;
F_394 ( F_20 ( V_433 ) ) ;
F_394 ( F_20 ( V_434 ) ) ;
F_394 ( F_20 ( V_435 ) ) ;
F_394 ( F_20 ( V_436 ) ) ;
F_394 ( F_20 ( V_437 ) ) ;
F_394 ( F_20 ( V_438 ) ) ;
F_395 ( F_392 ( V_428 ) , F_390 , V_428 ) ;
F_395 ( F_392 ( V_434 ) , F_390 , V_434 ) ;
F_395 ( F_392 ( V_435 ) , F_390 , V_435 ) ;
F_395 ( F_392 ( V_436 ) , F_390 , V_436 ) ;
F_395 ( F_392 ( V_437 ) , F_390 , V_437 ) ;
F_396 ( V_433 ) ;
F_397 ( F_398 ( V_428 ) , V_429 , FALSE , TRUE , 0 ) ;
F_397 ( F_398 ( V_428 ) , V_430 , FALSE , TRUE , 0 ) ;
if ( ! V_111 . V_439 ) {
F_397 ( F_398 ( V_428 ) , V_431 , FALSE , TRUE , 1 ) ;
}
F_397 ( F_398 ( V_428 ) , V_432 , FALSE , TRUE , 1 ) ;
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
V_425 = F_393 ( V_111 . V_447 ) ;
V_426 = F_393 ( V_111 . V_448 ) ;
V_424 = F_393 ( V_111 . V_449 ) ;
} else {
V_423 = F_393 ( V_111 . V_447 ) ;
V_424 = V_133 ;
V_425 = F_393 ( V_111 . V_448 ) ;
V_426 = F_393 ( V_111 . V_449 ) ;
}
if ( V_423 != NULL )
F_399 ( F_131 ( V_130 ) , V_423 ) ;
if ( V_424 != NULL )
F_400 ( F_131 ( V_130 ) , V_424 ) ;
if ( V_425 != NULL )
F_401 ( F_131 ( V_133 ) , V_425 , TRUE , TRUE ) ;
if ( V_426 != NULL )
F_402 ( F_131 ( V_133 ) , V_426 , FALSE , FALSE ) ;
F_397 ( F_398 ( V_428 ) , V_130 , TRUE , TRUE , 0 ) ;
F_397 ( F_398 ( V_428 ) , V_438 , TRUE , TRUE , 0 ) ;
F_397 ( F_398 ( V_428 ) , V_433 , FALSE , TRUE , 0 ) ;
if ( V_111 . V_439 ) {
F_397 ( F_398 ( V_433 ) , V_431 , FALSE , TRUE , 1 ) ;
}
F_403 ( V_433 ) ;
F_113 () ;
F_404 ( V_428 ) ;
}
static void
F_405 ( T_1 * T_10 , T_4 V_19 )
{
T_11 * V_450 = ( T_11 * ) V_19 ;
if ( ! * V_450 ) {
if ( F_406 ( T_10 ) )
* V_450 = TRUE ;
}
}
void
F_113 ( void )
{
T_11 V_451 ;
if ( V_81 . V_452 ) {
F_404 ( V_430 ) ;
} else {
F_378 ( V_430 ) ;
}
F_407 ( V_433 ) ;
if ( V_81 . V_453 ) {
F_404 ( V_431 ) ;
} else {
F_378 ( V_431 ) ;
}
if ( V_81 . V_454 ) {
F_404 ( V_432 ) ;
} else {
F_378 ( V_432 ) ;
}
if ( V_81 . V_455 && V_118 ) {
F_404 ( V_163 ) ;
} else {
F_378 ( V_163 ) ;
}
if ( V_81 . V_456 && V_118 ) {
F_404 ( V_164 ) ;
} else {
F_378 ( V_164 ) ;
}
if ( V_81 . V_457 && V_118 ) {
F_404 ( V_104 ) ;
} else {
F_378 ( V_104 ) ;
}
if ( V_118 ) {
F_404 ( V_130 ) ;
} else {
F_378 ( V_130 ) ;
}
V_451 = FALSE ;
F_395 ( F_392 ( V_133 ) , F_405 ,
& V_451 ) ;
if ( V_451 ) {
F_404 ( V_133 ) ;
} else {
F_378 ( V_133 ) ;
}
if ( ! V_118 ) {
if( V_438 ) {
F_404 ( V_438 ) ;
}
} else {
F_378 ( V_438 ) ;
}
}
static T_11
F_408 ( T_1 * T_10 V_24 ,
T_26 * T_27 ,
T_4 V_19 V_24 )
{
T_45 V_458 = ( ( V_459 * ) T_27 ) -> V_458 ;
if( ( T_27 -> type ) == ( V_460 ) ) {
if( ! ( V_458 & V_461 ) ) {
F_409 () ;
}
}
return FALSE ;
}
static T_11
F_410 ( T_1 * T_6 V_24 , T_46 * T_27 , T_4 T_19 V_24 )
{
if ( T_27 -> V_462 == V_463 ) {
F_411 () ;
return TRUE ;
} else if ( T_27 -> V_462 == V_464 ) {
F_412 () ;
return TRUE ;
} else if ( T_27 -> V_124 & V_465 ) {
return FALSE ;
} else if ( T_27 -> V_462 < 256 && F_413 ( T_27 -> V_462 ) ) {
if ( V_466 && ! F_414 ( V_466 ) ) {
F_415 ( F_172 ( V_122 ) , V_466 ) ;
F_416 ( F_5 ( V_466 ) , - 1 ) ;
}
return FALSE ;
}
return FALSE ;
}
static void
F_342 ( T_9 V_282 , T_9 V_283 , T_9 V_284 , T_35 * V_256
#if ! F_144 ( V_467 ) && ! F_144 ( F_216 )
V_24
#endif
)
{
T_47 * V_468 ;
V_122 = F_417 ( V_469 , L_9 ) ;
F_157 ( NULL ) ;
F_418 ( V_122 , L_224 ) ;
F_419 ( V_122 , L_225 , F_420 ( F_127 ) ,
NULL ) ;
F_419 ( F_20 ( V_122 ) , L_226 ,
F_420 ( F_408 ) , NULL ) ;
F_419 ( F_20 ( V_122 ) , L_227 ,
F_420 ( F_410 ) , NULL ) ;
V_428 = F_421 ( V_470 , 1 , FALSE ) ;
F_422 ( F_392 ( V_428 ) , 0 ) ;
F_423 ( F_392 ( V_122 ) , V_428 ) ;
F_404 ( V_428 ) ;
V_429 = F_424 ( & V_468 ) ;
#if F_144 ( V_467 ) || F_144 ( F_216 )
if( ! V_256 -> V_471 ) {
#endif
F_425 ( F_172 ( V_122 ) , V_468 ) ;
F_404 ( V_429 ) ;
#if F_144 ( V_467 ) || F_144 ( F_216 )
} else {
F_378 ( V_429 ) ;
}
#endif
V_430 = F_426 () ;
F_404 ( V_430 ) ;
V_431 = F_427 () ;
V_163 = F_428 () ;
F_429 ( V_163 , - 1 , V_282 ) ;
F_430 ( V_163 ) ;
V_164 = F_431 ( & V_110 ) ;
F_429 ( V_164 , - 1 , V_283 ) ;
F_404 ( V_164 ) ;
F_419 ( F_432 ( F_100 ( V_110 ) ) ,
L_228 , F_420 ( F_76 ) , NULL ) ;
F_419 ( V_110 , L_229 , F_420 ( V_472 ) ,
F_19 ( F_20 ( V_473 ) , V_474 ) ) ;
F_404 ( V_110 ) ;
V_104 = F_433 () ;
F_429 ( V_104 , - 1 , V_284 ) ;
F_404 ( V_104 ) ;
F_419 ( V_104 , L_229 , F_420 ( V_472 ) ,
F_19 ( F_20 ( V_473 ) , V_475 ) ) ;
V_434 = F_434 ( V_470 ) ;
F_404 ( V_434 ) ;
V_435 = F_434 ( V_470 ) ;
F_404 ( V_435 ) ;
V_436 = F_434 ( V_476 ) ;
F_404 ( V_436 ) ;
V_437 = F_434 ( V_476 ) ;
F_404 ( V_437 ) ;
#ifdef F_227
V_432 = F_435 () ;
#else
V_432 = F_436 () ;
#endif
F_404 ( V_432 ) ;
V_433 = F_437 () ;
F_404 ( V_433 ) ;
V_438 = F_438 () ;
F_404 ( V_438 ) ;
}
static void
F_350 ( T_11 V_477 )
{
F_112 ( V_477 ) ;
F_404 ( V_122 ) ;
F_132 ( V_122 ) ;
while ( F_439 () ) F_440 () ;
F_409 () ;
F_441 ( F_154 ( V_122 ) ) ;
#ifdef F_227
F_442 ( V_432 ) ;
#endif
}
static void F_443 ( const T_2 * V_478 )
{
char * V_479 , * V_480 , * V_481 ;
if ( F_444 ( V_478 , & V_479 ) == - 1 ) {
F_2 ( V_6 , V_7 ,
L_230 ,
V_479 , F_237 ( V_482 ) ) ;
F_9 ( V_479 ) ;
}
if ( F_445 ( V_478 , V_478 , TRUE , & V_481 ,
& V_479 , & V_480 ) == - 1 ) {
F_2 ( V_6 , V_7 ,
L_231 ,
V_481 , V_480 , V_479 , F_237 ( V_482 ) ) ;
F_9 ( V_481 ) ;
F_9 ( V_479 ) ;
F_9 ( V_480 ) ;
}
}
void F_446 ( const T_2 * V_478 )
{
char * V_240 , * V_241 ;
char * V_273 ;
int V_274 ;
if ( ! F_273 ( V_478 , FALSE ) ) {
if ( F_273 ( V_478 , TRUE ) ) {
F_443 ( V_478 ) ;
} else {
return;
}
}
if ( V_478 && strcmp ( V_478 , F_447 () ) == 0 ) {
return;
}
F_121 ( V_122 ) ;
if ( F_273 ( F_447 () , FALSE ) ) {
F_122 () ;
}
F_274 ( V_478 ) ;
F_448 () ;
F_449 ( V_483 ) ;
F_450 () ;
F_451 () ;
( void ) F_234 ( & V_240 , & V_241 ) ;
F_281 ( & V_273 , & V_274 ) ;
if ( V_273 != NULL && V_274 != 0 ) {
F_2 ( V_35 , V_7 ,
L_164 ,
V_273 , F_237 ( V_274 ) ) ;
}
if ( V_81 . V_314 &&
F_282 ( V_81 . V_314 ) == V_315 ) {
F_184 ( V_81 . V_314 ) ;
}
F_69 ( V_81 . V_82 ) ;
F_318 ( V_81 . V_484 ) ;
F_166 ( V_81 . V_168 ) ;
F_311 () ;
F_330 () ;
F_452 () ;
F_453 () ;
F_449 ( V_485 ) ;
F_454 () ;
F_455 () ;
if ( V_240 == NULL && V_241 == NULL ) {
F_333 () ;
}
F_456 () ;
F_457 () ;
F_96 () ;
V_18 . V_113 = FALSE ;
F_346 () ;
F_345 () ;
F_129 () ;
}
void F_458 ( void )
{
F_459 ( & V_18 ) ;
F_460 () ;
}
