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
V_50 = F_50 ( V_50 , F_27 ( L_37 , V_18 . V_37 . V_43 . V_44 [ V_36 ] ) ) ;
}
for ( V_48 = 0 ; V_48 < V_18 . V_37 . V_55 ; V_48 ++ ) {
if ( ( V_48 != V_36 ) && ( F_39 ( V_48 ) ) ) {
V_50 = F_50 ( V_50 , F_27 ( L_37 , V_18 . V_37 . V_43 . V_44 [ V_48 ] ) ) ;
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
T_9 V_36 = F_42 ( F_41 ( F_19 ( F_20 ( V_19 ) , V_47 ) ) ) ;
T_13 * V_49 ;
T_2 * V_54 = NULL ;
V_49 = ( T_13 * ) F_43 ( V_45 ) ;
if ( V_49 != NULL ) {
T_14 V_22 ;
if ( ! F_44 ( & V_18 , V_49 ) )
return NULL ;
F_45 ( & V_22 , V_18 . V_51 , F_53 ( & V_18 . V_37 ) , FALSE ) ;
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
T_15 * V_58 = F_54 ( V_18 . V_37 . V_59 [ V_36 ] ) ;
if ( V_58 && V_58 -> V_60 == - 1 ) {
V_54 = F_6 ( V_18 . V_37 . V_43 . V_43 [ V_36 ] ) ;
} else if ( V_58 && F_55 ( V_58 -> type ) ) {
V_54 = F_27 ( L_38 , V_18 . V_37 . V_43 . V_43 [ V_36 ] ,
V_18 . V_37 . V_43 . V_44 [ V_36 ] ) ;
}
}
if ( V_54 == NULL ) {
V_54 = F_27 ( L_39 , V_18 . V_37 . V_43 . V_43 [ V_36 ] ,
V_18 . V_37 . V_43 . V_44 [ V_36 ] ) ;
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
F_2 ( V_6 , V_7 , L_40 ) ;
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
L_41
L_42
L_43 ,
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
F_84 ( V_95 , L_44 , sizeof V_95 ) ;
} else {
F_85 ( V_95 , sizeof V_95 , L_45 , V_101 ) ;
}
F_86 () ;
if ( V_97 ) {
F_87 ( L_46 ,
( V_96 ) ? V_94 -> V_31 -> V_106 : V_94 -> V_31 -> V_107 ,
V_94 -> V_31 -> V_68 , V_95 ) ;
} else {
F_87 ( L_37 , L_9 ) ;
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
static const T_25 V_115 = { TRUE , TRUE , TRUE , TRUE , TRUE , FALSE } ;
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
if ( F_126 ( & V_18 , TRUE , L_47 ) )
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
if ( F_126 ( & V_18 , TRUE , L_47 ) )
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
fprintf ( V_152 , L_48
L_49
L_50 ,
F_140 () ) ;
} else {
V_152 = V_153 ;
}
fprintf ( V_152 , L_14 ) ;
fprintf ( V_152 , L_51 ) ;
fprintf ( V_152 , L_14 ) ;
#ifdef F_107
fprintf ( V_152 , L_52 ) ;
fprintf ( V_152 , L_53 ) ;
fprintf ( V_152 , L_54 ) ;
fprintf ( V_152 , L_55 ) ;
fprintf ( V_152 , L_56 ) ;
fprintf ( V_152 , L_57 ) ;
fprintf ( V_152 , L_58 ) ;
fprintf ( V_152 , L_59 ) ;
#ifdef F_141
fprintf ( V_152 , L_60 ) ;
#endif
#if F_142 ( F_138 ) || F_142 ( F_141 )
fprintf ( V_152 , L_61 , V_154 ) ;
#endif
fprintf ( V_152 , L_62 ) ;
fprintf ( V_152 , L_63 ) ;
fprintf ( V_152 , L_64 ) ;
fprintf ( V_152 , L_14 ) ;
fprintf ( V_152 , L_65 ) ;
fprintf ( V_152 , L_66 ) ;
fprintf ( V_152 , L_67 ) ;
fprintf ( V_152 , L_68 ) ;
fprintf ( V_152 , L_69 ) ;
fprintf ( V_152 , L_70 ) ;
fprintf ( V_152 , L_71 ) ;
fprintf ( V_152 , L_72 ) ;
fprintf ( V_152 , L_73 ) ;
#endif
#ifdef F_143
fprintf ( V_152 , L_74 ) ;
fprintf ( V_152 , L_75 ) ;
#endif
fprintf ( V_152 , L_76 ) ;
fprintf ( V_152 , L_77 ) ;
fprintf ( V_152 , L_14 ) ;
fprintf ( V_152 , L_78 ) ;
fprintf ( V_152 , L_79 ) ;
fprintf ( V_152 , L_80 ) ;
fprintf ( V_152 , L_81 ) ;
fprintf ( V_152 , L_14 ) ;
fprintf ( V_152 , L_82 ) ;
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
fprintf ( V_152 , L_14 ) ;
fprintf ( V_152 , L_94 ) ;
fprintf ( V_152 , L_95 ) ;
fprintf ( V_152 , L_14 ) ;
fprintf ( V_152 , L_96 ) ;
fprintf ( V_152 , L_97 ) ;
fprintf ( V_152 , L_98 ) ;
fprintf ( V_152 , L_99 ) ;
fprintf ( V_152 , L_100 ) ;
fprintf ( V_152 , L_101 ) ;
fprintf ( V_152 , L_102 ) ;
#ifndef F_138
fprintf ( V_152 , L_103 ) ;
#endif
#ifdef F_138
F_144 () ;
#endif
}
static void
F_145 ( void )
{
printf ( L_48
L_14
L_37
L_14
L_37
L_14
L_37 ,
F_140 () , F_146 () , V_155 -> V_156 ,
V_157 -> V_156 ) ;
}
static void
F_147 ( const char * V_158 , T_30 V_159 )
{
#ifdef F_138
F_139 () ;
#endif
fprintf ( V_153 , L_104 ) ;
vfprintf ( V_153 , V_158 , V_159 ) ;
fprintf ( V_153 , L_14 ) ;
}
static void
F_148 ( const char * V_158 , T_30 V_159 )
{
#ifdef F_138
F_139 () ;
#endif
vfprintf ( V_153 , V_158 , V_159 ) ;
fprintf ( V_153 , L_14 ) ;
}
static T_11
F_149 ( T_4 V_19 V_24 )
{
F_150 ( FALSE ) ;
return TRUE ;
}
static T_11
F_151 ( T_4 V_19 V_24 )
{
if ( F_152 () ) {
if ( F_153 ( V_160 ) )
F_154 ( F_153 ( V_160 ) , NULL , TRUE ) ;
if ( F_153 ( V_161 ) )
F_154 ( F_153 ( V_161 ) , NULL , TRUE ) ;
}
return TRUE ;
}
void
F_155 ( T_31 * V_162 )
{
F_156 ( V_162 ) ;
F_157 ( V_162 ) ;
F_158 ( V_162 ) ;
}
void
F_159 ( T_11 V_163 )
{
F_160 ( V_163 ) ;
F_161 ( V_163 ) ;
V_164 = V_163 ;
}
void
F_162 ( T_11 V_165 )
{
F_163 ( V_165 ) ;
F_164 ( V_165 ) ;
if( V_165 != V_81 . V_165 ) {
V_81 . V_165 = V_165 ;
F_165 ( V_165 ) ;
F_25 () ;
}
}
static void
F_166 ( T_4 T_8 , T_9 V_26 V_24 , T_4 V_19 V_24 )
{
V_81 . V_166 = ! F_167 ( T_8 ) ;
}
static void
F_168 ( T_4 T_8 , T_9 V_26 V_24 , T_4 V_19 V_24 )
{
V_81 . V_167 = ! F_167 ( T_8 ) ;
}
static void
F_169 ( T_31 * V_162 )
{
if( V_162 -> V_168 > 10000 ) {
V_169 = ( T_1 * ) F_2 ( V_170 , V_171 ,
L_105 ,
F_34 () ,
F_35 () ) ;
F_170 ( F_171 ( V_169 ) , V_172 ) ;
}
F_172 () ;
F_173 () ;
F_156 ( NULL ) ;
F_157 ( NULL ) ;
F_158 ( NULL ) ;
F_112 ( FALSE ) ;
F_174 ( V_162 ) ;
F_105 ( FALSE ) ;
F_109 ( FALSE ) ;
F_83 ( V_162 ) ;
F_110 ( FALSE ) ;
F_175 () ;
}
static void
F_176 ( T_31 * V_162 V_24 )
{
if( V_169 != NULL ) {
F_177 ( V_169 ) ;
V_169 = NULL ;
}
}
static void
F_178 ( T_31 * V_162 V_24 )
{
F_179 () ;
F_110 ( TRUE ) ;
}
static void
F_180 ( T_31 * V_162 )
{
T_2 * V_173 ;
if ( ! V_162 -> V_174 && V_162 -> V_175 ) {
F_181 ( V_162 -> V_175 ) ;
V_173 = F_182 ( F_6 ( V_162 -> V_175 ) ) ;
F_183 ( V_173 ) ;
F_9 ( V_173 ) ;
}
F_155 ( V_162 ) ;
F_112 ( TRUE ) ;
}
static void
F_184 ( T_31 * V_162 )
{
T_2 * V_173 ;
if ( ! V_162 -> V_174 && V_162 -> V_175 ) {
F_181 ( V_162 -> V_175 ) ;
V_173 = F_182 ( F_6 ( V_162 -> V_175 ) ) ;
F_183 ( V_173 ) ;
F_9 ( V_173 ) ;
}
F_155 ( V_162 ) ;
}
static T_12 * F_185 (
const T_7 * V_176 ,
const T_7 * V_177 ,
const T_7 * V_178 ,
const T_7 * V_179 )
{
T_12 * V_180 = NULL ;
T_32 * V_181 ;
T_32 * V_182 ;
T_32 * V_183 ;
T_32 * V_184 ;
if( V_176 != NULL ) {
V_181 = F_186 ( - 1 , V_176 , FALSE , NULL ) ;
F_3 ( V_181 ) ;
V_180 = F_50 ( V_180 , V_181 ) ;
}
if( V_177 != NULL ) {
V_182 = F_186 ( - 1 , V_177 , FALSE , NULL ) ;
F_3 ( V_182 ) ;
V_180 = F_50 ( V_180 , V_182 ) ;
}
if( V_178 != NULL ) {
V_183 = F_186 ( - 1 , V_178 , FALSE , NULL ) ;
F_3 ( V_183 ) ;
V_180 = F_50 ( V_180 , V_183 ) ;
}
if( V_179 != NULL ) {
V_184 = F_186 ( - 1 , V_179 , FALSE , NULL ) ;
F_3 ( V_184 ) ;
V_180 = F_50 ( V_180 , V_184 ) ;
}
return V_180 ;
}
static void
F_187 ( T_33 * V_185 )
{
static T_12 * V_180 = NULL ;
F_188 ( ( T_31 * ) V_185 -> V_162 ) ;
if( V_180 == NULL ) {
V_180 = F_185 ( V_186 , V_187 , V_188 , V_189 ) ;
}
F_189 ( F_171 ( V_122 ) , V_180 ) ;
F_105 ( TRUE ) ;
F_109 ( TRUE ) ;
F_110 ( FALSE ) ;
}
static void
F_190 ( T_33 * V_185 )
{
F_188 ( ( T_31 * ) V_185 -> V_162 ) ;
F_105 ( TRUE ) ;
F_109 ( TRUE ) ;
F_112 ( TRUE ) ;
F_110 ( TRUE ) ;
}
static void
F_191 ( T_33 * V_185 )
{
T_31 * V_162 = ( T_31 * ) V_185 -> V_162 ;
static T_12 * V_180 = NULL ;
V_127 = FALSE ;
if ( ! V_162 -> V_174 && V_162 -> V_175 ) {
F_181 ( V_162 -> V_175 ) ;
}
F_105 ( FALSE ) ;
F_109 ( FALSE ) ;
F_155 ( V_162 ) ;
F_110 ( TRUE ) ;
if( V_180 == NULL ) {
V_180 = F_185 ( V_190 , V_191 , V_192 , V_193 ) ;
}
F_189 ( F_171 ( V_122 ) , V_180 ) ;
if( V_194 . V_195 ) {
F_118 () ;
}
}
static void
F_192 ( T_33 * V_185 V_24 )
{
F_110 ( FALSE ) ;
}
static void
F_193 ( T_33 * V_185 V_24 )
{
#if 0
capture_file *cf = (capture_file *)cap_session->cf;
#endif
static T_12 * V_180 = NULL ;
V_127 = FALSE ;
F_105 ( FALSE ) ;
F_109 ( FALSE ) ;
F_156 ( NULL ) ;
if( V_180 == NULL ) {
V_180 = F_185 ( V_190 , V_191 , V_192 , V_193 ) ;
}
F_189 ( F_171 ( V_122 ) , V_180 ) ;
if( V_194 . V_195 ) {
F_118 () ;
}
}
static void
F_194 ( T_33 * V_185 V_24 )
{
V_127 = TRUE ;
F_195 () ;
#ifdef F_107
F_196 () ;
F_197 () ;
#endif
}
static void
F_198 ( T_33 * V_185 V_24 )
{
static T_12 * V_180 = NULL ;
V_127 = FALSE ;
F_156 ( NULL ) ;
F_105 ( FALSE ) ;
F_109 ( FALSE ) ;
F_110 ( FALSE ) ;
if( V_180 == NULL ) {
V_180 = F_185 ( V_190 , V_191 , V_192 , V_193 ) ;
}
F_189 ( F_171 ( V_122 ) , V_180 ) ;
if( V_194 . V_195 ) {
F_118 () ;
}
}
static void
F_199 ( T_4 V_19 )
{
T_31 * V_162 = ( T_31 * ) V_19 ;
F_200 ( V_162 -> V_22 , V_110 , V_104 ) ;
F_201 ( V_162 -> V_22 -> V_109 , V_110 ) ;
if( V_162 -> V_196 &&
( V_162 -> V_197 != 0 || ( V_162 -> string && V_162 -> V_198 ) ) ) {
F_202 ( V_162 -> V_22 -> V_199 , V_162 -> V_197 ,
( V_200 * ) V_110 , V_162 -> V_22 -> V_109 ) ;
}
F_174 ( V_162 ) ;
}
static void
F_203 ( T_31 * V_162 )
{
while ( F_204 ( F_205 ( V_104 ) , 0 ) != NULL )
F_206 ( F_205 ( V_104 ) , 0 ) ;
F_207 ( V_104 , L_9 , NULL , NULL , V_110 ) ;
F_201 ( NULL , V_110 ) ;
F_174 ( V_162 ) ;
}
static void
F_208 ( T_31 * V_162 )
{
F_83 ( V_162 ) ;
}
static void
F_209 ( T_9 T_27 , T_4 V_19 , T_4 T_19 V_24 )
{
T_31 * V_162 = ( T_31 * ) V_19 ;
switch( T_27 ) {
case ( V_201 ) :
F_210 ( V_202 , V_203 , L_106 ) ;
F_211 ( V_162 ) ;
break;
case ( V_204 ) :
F_210 ( V_202 , V_203 , L_107 ) ;
F_169 ( V_162 ) ;
break;
case ( V_205 ) :
F_210 ( V_202 , V_203 , L_108 ) ;
F_176 ( V_162 ) ;
F_212 () ;
break;
case ( V_206 ) :
F_210 ( V_202 , V_203 , L_109 ) ;
F_178 ( V_162 ) ;
break;
case ( V_207 ) :
F_210 ( V_202 , V_203 , L_110 ) ;
F_180 ( V_162 ) ;
break;
case ( V_208 ) :
F_210 ( V_202 , V_203 , L_111 ) ;
F_178 ( V_162 ) ;
break;
case ( V_209 ) :
F_210 ( V_202 , V_203 , L_112 ) ;
F_180 ( V_162 ) ;
break;
case ( V_210 ) :
F_210 ( V_202 , V_203 , L_113 ) ;
break;
case ( V_211 ) :
F_210 ( V_202 , V_203 , L_114 ) ;
F_184 ( V_162 ) ;
break;
case ( V_212 ) :
F_210 ( V_202 , V_203 , L_115 ) ;
F_184 ( V_162 ) ;
break;
case ( V_213 ) :
F_199 ( V_162 ) ;
break;
case ( V_214 ) :
F_203 ( V_162 ) ;
break;
case ( V_215 ) :
F_208 ( V_162 ) ;
break;
case ( V_216 ) :
F_210 ( V_202 , V_203 , L_116 ) ;
break;
case ( V_217 ) :
F_210 ( V_202 , V_203 , L_117 ) ;
break;
case ( V_218 ) :
F_210 ( V_202 , V_203 , L_118 ) ;
break;
case ( V_219 ) :
F_210 ( V_202 , V_203 , L_119 ) ;
break;
case ( V_220 ) :
F_210 ( V_202 , V_203 , L_120 ) ;
break;
case ( V_221 ) :
F_210 ( V_202 , V_203 , L_121 ) ;
break;
case ( V_222 ) :
F_210 ( V_202 , V_203 , L_122 ) ;
break;
case ( V_223 ) :
F_210 ( V_202 , V_203 , L_123 ) ;
break;
default:
F_213 ( L_124 , T_27 ) ;
F_8 () ;
}
}
static void
F_214 ( T_9 T_27 , T_33 * V_185 , T_4 T_19 V_24 )
{
#ifdef F_215
T_34 * V_224 ;
#endif
switch( T_27 ) {
case ( V_225 ) :
F_210 ( V_202 , V_203 , L_125 ) ;
F_187 ( V_185 ) ;
break;
case ( V_226 ) :
F_210 ( V_202 , V_203 , L_126 ) ;
F_190 ( V_185 ) ;
#ifdef F_215
V_224 = ( T_34 * ) F_216 ( V_227 , NULL ) ;
F_217 ( V_224 , F_186 ( - 1 , V_188 , FALSE , NULL ) ) ;
#endif
break;
case ( V_228 ) :
break;
case ( V_229 ) :
F_210 ( V_202 , V_203 , L_127 ) ;
F_191 ( V_185 ) ;
break;
case ( V_230 ) :
F_210 ( V_202 , V_203 , L_128 ) ;
F_192 ( V_185 ) ;
break;
case ( V_231 ) :
F_210 ( V_202 , V_203 , L_129 ) ;
break;
case ( V_232 ) :
F_210 ( V_202 , V_203 , L_130 ) ;
F_193 ( V_185 ) ;
break;
case ( V_233 ) :
F_210 ( V_202 , V_203 , L_131 ) ;
#ifdef F_215
V_224 = ( T_34 * ) F_216 ( V_227 , NULL ) ;
F_217 ( V_224 , F_186 ( - 1 , V_193 , FALSE , NULL ) ) ;
#endif
F_194 ( V_185 ) ;
break;
case ( V_234 ) :
F_210 ( V_202 , V_203 , L_132 ) ;
F_198 ( V_185 ) ;
break;
default:
F_213 ( L_133 , T_27 ) ;
F_8 () ;
}
}
static void
F_218 ( T_3 * V_156 )
{
F_11 ( V_156 , L_134 ) ;
F_219 ( V_156 ,
#ifdef F_220
L_135 , F_220 , V_235 ,
V_236 ) ;
#else
L_136 ) ;
void
F_221 ( T_3 * V_156 )
{
F_222 ( V_156 ) ;
F_11 ( V_156 , L_137 ) ;
#ifdef F_223
#ifdef F_224
F_11 ( V_156 , L_138 ) ;
#else
F_11 ( V_156 , L_134 ) ;
F_11 ( V_156 , F_225 () ) ;
#endif
#else
F_11 ( V_156 , L_139 ) ;
#endif
F_11 ( V_156 , L_137 ) ;
#ifdef F_226
F_227 ( V_156 ) ;
#else
F_11 ( V_156 , L_140 ) ;
#endif
}
static void
F_228 ( T_3 * V_156 )
{
#ifdef F_107
F_11 ( V_156 , L_137 ) ;
F_229 ( V_156 ) ;
#endif
#if F_142 ( V_237 ) && ! F_142 ( F_138 )
F_219 ( V_156 , L_141 , F_230 () ) ;
#endif
F_231 ( V_156 ) ;
#ifdef F_226
F_11 ( V_156 , L_137 ) ;
F_232 ( V_156 ) ;
#endif
if( F_233 () ) {
F_11 ( V_156 , L_137 ) ;
F_234 ( V_156 ) ;
}
}
static T_35 *
F_235 ( char * * V_238 , char * * V_239 )
{
int V_240 , V_241 ;
int V_242 , V_243 ;
int V_244 , V_245 ;
int V_246 , V_247 ;
char * V_248 , * V_249 ;
char * V_250 , * V_251 ;
int V_252 , V_253 ;
T_35 * V_254 ;
F_236 () ;
V_254 = F_237 ( & V_240 , & V_241 , & V_248 ,
& V_252 , & V_253 , & V_249 ) ;
if ( V_248 != NULL ) {
if ( V_240 != 0 ) {
F_2 ( V_35 , V_7 ,
L_142 ,
V_248 , F_238 ( V_240 ) ) ;
}
if ( V_241 != 0 ) {
F_2 ( V_35 , V_7 ,
L_143 ,
V_248 , F_238 ( V_241 ) ) ;
}
}
if ( V_249 != NULL ) {
if ( V_252 != 0 ) {
F_2 ( V_35 , V_7 ,
L_144 ,
V_249 , F_238 ( V_252 ) ) ;
}
if ( V_253 != 0 ) {
F_2 ( V_35 , V_7 ,
L_145 ,
V_249 , F_238 ( V_253 ) ) ;
}
F_9 ( V_249 ) ;
V_249 = NULL ;
}
#ifdef F_138
if ( V_254 -> V_255 == V_256 ) {
F_139 () ;
}
#endif
F_239 ( V_257 , & V_250 , & V_242 ) ;
if ( V_250 != NULL ) {
F_2 ( V_35 , V_7 ,
L_146 ,
V_250 , F_238 ( V_242 ) ) ;
F_9 ( V_250 ) ;
}
F_239 ( V_258 , & V_251 , & V_243 ) ;
if ( V_251 != NULL ) {
F_2 ( V_35 , V_7 ,
L_147 ,
V_251 , F_238 ( V_243 ) ) ;
F_9 ( V_251 ) ;
}
F_240 ( V_238 , & V_244 , & V_245 ,
V_239 , & V_246 , & V_247 ) ;
if ( * V_238 != NULL ) {
if ( V_244 != 0 ) {
F_2 ( V_35 , V_7 ,
L_148 ,
* V_238 , F_238 ( V_244 ) ) ;
}
if ( V_245 != 0 ) {
F_2 ( V_35 , V_7 ,
L_149 ,
* V_238 , F_238 ( V_245 ) ) ;
}
F_9 ( * V_238 ) ;
* V_238 = NULL ;
}
if ( * V_239 != NULL ) {
if ( V_246 != 0 ) {
F_2 ( V_35 , V_7 ,
L_150 ,
* V_239 , F_238 ( V_246 ) ) ;
}
if ( V_247 != 0 ) {
F_2 ( V_35 , V_7 ,
L_151 ,
* V_239 , F_238 ( V_247 ) ) ;
}
F_9 ( * V_239 ) ;
* V_239 = NULL ;
}
return V_254 ;
}
static void
#ifdef F_138
F_241 ( T_2 * V_259 )
#else
check_and_warn_user_startup( T_2 * V_259 V_24 )
#endif
{
T_2 * V_260 , * V_261 ;
T_4 V_262 ;
if ( F_242 () && V_81 . V_166 ) {
V_260 = F_243 () ;
V_261 = F_244 () ;
V_262 = F_2 ( V_35 , V_7 ,
L_152
L_153
L_154
L_155
L_156 , V_260 , V_261 ) ;
F_9 ( V_260 ) ;
F_9 ( V_261 ) ;
F_245 ( V_262 , L_157 ) ;
F_36 ( V_262 , F_166 , NULL ) ;
}
#ifdef F_138
if ( ! F_246 () && ! V_259 && ! F_247 () && V_81 . V_167 && F_248 () >= 6 ) {
V_262 = F_2 ( V_35 , V_7 ,
L_158
L_159 ) ;
F_245 ( V_262 , L_157 ) ;
F_36 ( V_262 , F_168 , NULL ) ;
}
#endif
}
int
main ( int V_263 , char * V_264 [] )
{
char * V_265 ;
char * V_266 ;
int V_267 ;
T_11 V_268 = FALSE ;
extern int V_269 ;
const T_2 * V_20 ;
#ifdef F_138
T_36 V_270 ;
#endif
char * V_271 ;
int V_272 ;
char * V_238 , * V_239 ;
int V_273 ;
#ifdef F_107
T_11 V_274 = FALSE ;
T_11 V_275 = FALSE ;
T_12 * V_276 ;
T_2 * V_277 ;
int V_278 ;
#else
T_11 V_279 = FALSE ;
#ifdef F_138
#ifdef F_226
T_2 * V_277 ;
#endif
#endif
#endif
T_9 V_280 = 280 , V_281 = 95 , V_282 = 75 ;
T_2 * V_283 , * V_259 = NULL , * V_284 = NULL , * V_285 = NULL , * V_286 = NULL ;
T_37 * V_287 = NULL ;
T_11 V_288 = FALSE ;
T_35 * V_254 ;
char V_289 ;
T_1 * V_290 = NULL ;
T_21 V_291 = 0 ;
T_38 V_292 = V_90 ;
T_37 * V_293 = NULL ;
int V_294 ;
unsigned int V_295 = V_296 ;
#ifdef F_215
T_34 * V_224 ;
#endif
#define F_249 OPTSTRING_CAPTURE_COMMON "C:g:Hh" "jJ:kK:lm:nN:o:P:r:R:St:u:vw:X:Y:z:"
static const char V_297 [] = F_249 ;
F_250 ( F_147 , F_148 ) ;
setlocale ( V_298 , L_9 ) ;
#ifdef F_138
F_251 ( V_263 , V_264 ) ;
F_252 () ;
#endif
F_253 () ;
F_254 () ;
V_265 = F_255 ( V_264 [ 0 ] , main ) ;
F_256 () ;
F_257 ( & V_299 ) ;
#ifdef F_138
F_258 () ;
F_259 () ;
#ifdef F_226
V_300 = F_260 () ;
switch ( V_300 ) {
case V_301 :
V_302 = F_261 ( & V_273 , & V_277 ) ;
if ( V_302 == NULL || F_262 ( V_302 ) == 0 ) {
if ( V_273 == V_303 && V_277 != NULL ) {
F_2 ( V_6 , V_7 , L_37 , L_160 ) ;
F_9 ( V_277 ) ;
}
V_304 = NULL ;
} else {
V_304 = F_263 ( V_302 ) ;
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
V_155 = F_10 ( L_161 ) ;
F_264 ( V_155 , F_218 ,
F_221 ) ;
V_157 = F_10 ( L_162 ) ;
F_265 ( V_157 , F_228 ) ;
F_266 ( L_48
L_14
L_37
L_14
L_37 ,
F_140 () , V_155 -> V_156 , V_157 -> V_156 ) ;
#ifdef F_138
F_267 ( F_268 ( 1 , 1 ) , & V_270 ) ;
#endif
F_269 ( TRUE ) ;
F_270 ( & V_271 , & V_272 ) ;
if ( V_271 != NULL && V_272 != 0 ) {
F_2 ( V_35 , V_7 ,
L_163 ,
V_271 , F_238 ( V_272 ) ) ;
}
V_305 = 0 ;
V_294 = V_306 ;
while ( ( V_267 = F_271 ( V_263 , V_264 , V_297 ) ) != - 1 ) {
switch ( V_267 ) {
case 'C' :
if ( F_272 ( V_307 , FALSE ) ) {
F_273 ( V_307 ) ;
} else {
F_274 ( L_164 , V_307 ) ;
exit ( 1 ) ;
}
break;
case 'D' :
#ifdef F_107
V_276 = F_275 ( & V_273 , & V_277 , F_175 ) ;
if ( V_276 == NULL ) {
if ( V_273 == 0 )
F_274 ( L_165 ) ;
else {
F_274 ( L_37 , V_277 ) ;
F_9 ( V_277 ) ;
}
exit ( 2 ) ;
}
#ifdef F_138
F_139 () ;
#endif
F_276 ( V_276 ) ;
F_277 ( V_276 ) ;
#ifdef F_138
F_144 () ;
#endif
exit ( 0 ) ;
#else
V_279 = TRUE ;
V_268 = TRUE ;
#endif
break;
case 'h' :
F_137 ( TRUE ) ;
exit ( 0 ) ;
break;
#ifdef F_138
case 'i' :
if ( strcmp ( V_307 , L_166 ) == 0 )
F_278 ( TRUE ) ;
break;
#endif
case 'P' :
if ( ! F_279 ( V_267 , V_307 ) ) {
F_274 ( L_167 , V_307 ) ;
exit ( 2 ) ;
}
break;
case 'v' :
#ifdef F_138
F_139 () ;
#endif
F_145 () ;
#ifdef F_138
F_144 () ;
#endif
exit ( 0 ) ;
break;
case 'X' :
F_280 ( V_307 ) ;
break;
case '?' :
break;
}
}
F_281 ( & V_271 , & V_272 ) ;
if ( V_271 != NULL && V_272 != 0 ) {
F_2 ( V_35 , V_7 ,
L_168 ,
V_271 , F_238 ( V_272 ) ) ;
}
if ( V_81 . V_308 &&
F_282 ( V_81 . V_308 ) == V_309 ) {
F_183 ( V_81 . V_308 ) ;
} else {
F_183 ( F_283 () ) ;
}
V_306 = V_294 ;
V_305 = 1 ;
#if ! F_284 ( 2 , 31 , 0 )
F_285 ( NULL ) ;
#endif
setlocale ( V_298 , L_9 ) ;
F_286 ( & V_263 , & V_264 ) ;
F_287 ( F_209 , NULL ) ;
#ifdef F_107
F_288 ( F_214 , NULL ) ;
#endif
F_287 ( V_310 , NULL ) ;
#ifdef F_107
F_288 ( V_311 , NULL ) ;
#endif
F_289 () ;
#ifdef F_107
F_290 ( & V_194 ) ;
F_291 ( & V_123 , ( void * ) & V_18 ) ;
#endif
F_292 ( V_312 , V_313 ,
V_314 , V_315 ) ;
F_293 () ;
V_20 = F_294 () ;
if ( * V_20 != '\0' ) {
V_269 = 1000 ;
}
V_290 = F_295 ( L_169 ) ;
if ( V_265 != NULL ) {
F_2 ( V_35 , V_7 ,
L_170
L_171
L_172 ,
V_265 ) ;
F_9 ( V_265 ) ;
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
F_304 ( V_316 , NULL , ( T_4 ) V_290 ) ;
F_305 ( V_317 , V_318 ,
F_304 , ( T_4 ) V_290 ) ;
F_304 ( V_319 , NULL , ( T_4 ) V_290 ) ;
#ifdef F_297
F_306 () ;
#endif
F_307 () ;
F_308 ( V_320 ) ;
F_309 ( V_321 ) ;
F_304 ( V_322 , NULL , ( T_4 ) V_290 ) ;
V_254 = F_235 ( & V_238 , & V_239 ) ;
V_323 = F_310 ( V_254 -> V_324 , F_149 , NULL ) ;
F_304 ( V_325 , NULL , ( T_4 ) V_290 ) ;
F_311 () ;
F_312 ( & V_18 ) ;
F_313 () ;
while ( ( V_267 = F_271 ( V_263 , V_264 , V_297 ) ) != - 1 ) {
switch ( V_267 ) {
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
#if F_142 ( F_138 ) || F_142 ( F_141 )
case 'B' :
#endif
#ifdef F_107
V_278 = F_314 ( & V_194 , V_267 , V_307 ,
& V_274 ) ;
if( V_278 != 0 ) {
exit ( V_278 ) ;
}
#else
V_279 = TRUE ;
V_268 = TRUE ;
#endif
break;
#if F_142 ( V_326 ) || F_142 ( V_327 )
case 'K' :
F_315 ( V_307 ) ;
break;
#endif
case 'C' :
break;
case 'j' :
V_292 = V_92 ;
break;
case 'g' :
V_291 = F_316 ( V_307 , L_173 ) ;
break;
case 'J' :
V_286 = V_307 ;
break;
case 'l' :
#ifdef F_107
V_164 = TRUE ;
#else
V_279 = TRUE ;
V_268 = TRUE ;
#endif
break;
case 'L' :
#ifdef F_107
V_275 = TRUE ;
#else
V_279 = TRUE ;
V_268 = TRUE ;
#endif
break;
case 'm' :
F_9 ( V_254 -> V_328 ) ;
V_254 -> V_328 = F_6 ( V_307 ) ;
break;
case 'n' :
V_329 . V_330 = FALSE ;
V_329 . V_331 = FALSE ;
V_329 . V_332 = FALSE ;
V_329 . V_333 = FALSE ;
break;
case 'N' :
V_289 = F_317 ( V_307 , & V_329 ) ;
if ( V_289 != '\0' ) {
F_274 ( L_174 ,
V_289 ) ;
exit ( 1 ) ;
}
break;
case 'o' :
switch ( F_318 ( V_307 ) ) {
case V_334 :
break;
case V_335 :
F_274 ( L_175 , V_307 ) ;
exit ( 1 ) ;
break;
case V_336 :
switch ( F_319 ( V_307 ) ) {
case V_334 :
break;
case V_335 :
F_274 ( L_175 , V_307 ) ;
exit ( 1 ) ;
break;
case V_336 :
case V_337 :
F_274 ( L_176 ,
V_307 ) ;
exit ( 1 ) ;
break;
default:
F_8 () ;
}
break;
case V_337 :
F_274 ( L_177 ,
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
V_259 = F_6 ( V_307 ) ;
break;
case 'R' :
V_284 = V_307 ;
break;
case 't' :
if ( strcmp ( V_307 , L_178 ) == 0 )
F_67 ( V_80 ) ;
else if ( strcmp ( V_307 , L_179 ) == 0 )
F_67 ( V_338 ) ;
else if ( strcmp ( V_307 , L_180 ) == 0 )
F_67 ( V_339 ) ;
else if ( strcmp ( V_307 , L_181 ) == 0 )
F_67 ( V_340 ) ;
else if ( strcmp ( V_307 , L_182 ) == 0 )
F_67 ( V_341 ) ;
else if ( strcmp ( V_307 , L_183 ) == 0 )
F_67 ( V_342 ) ;
else if ( strcmp ( V_307 , L_184 ) == 0 )
F_67 ( V_343 ) ;
else if ( strcmp ( V_307 , L_185 ) == 0 )
F_67 ( V_344 ) ;
else if ( strcmp ( V_307 , L_186 ) == 0 )
F_67 ( V_345 ) ;
else if ( strcmp ( V_307 , L_187 ) == 0 )
F_67 ( V_346 ) ;
else {
F_274 ( L_188 , V_307 ) ;
F_320 (
L_189 ) ;
F_320 (
L_190 ) ;
F_320 (
L_191 ) ;
F_320 (
L_192 ) ;
F_320 (
L_193 ) ;
exit ( 1 ) ;
}
break;
case 'u' :
if ( strcmp ( V_307 , L_194 ) == 0 )
F_321 ( V_347 ) ;
else if ( strcmp ( V_307 , L_195 ) == 0 )
F_321 ( V_348 ) ;
else {
F_274 ( L_196 , V_307 ) ;
F_320 (
L_197 ) ;
exit ( 1 ) ;
}
break;
case 'X' :
break;
case 'Y' :
V_285 = V_307 ;
break;
case 'z' :
if ( ! F_322 ( V_307 ) ) {
F_274 ( L_198 ) ;
F_320 ( L_199 ) ;
F_323 () ;
exit ( 1 ) ;
}
break;
default:
case '?' :
V_268 = TRUE ;
break;
}
}
if ( ! V_268 ) {
V_263 -= V_306 ;
V_264 += V_306 ;
if ( V_263 >= 1 ) {
if ( V_259 != NULL ) {
F_274 ( L_200 ) ;
V_268 = TRUE ;
} else {
#ifndef F_215
V_259 = F_6 ( V_264 [ 0 ] ) ;
#endif
}
V_263 -- ;
V_264 ++ ;
}
if ( V_263 != 0 ) {
F_274 ( L_201 , V_264 [ 0 ] ) ;
V_268 = TRUE ;
}
}
if ( V_268 ) {
#ifndef F_107
if ( V_279 ) {
F_274 ( L_202 ) ;
}
#endif
F_137 ( FALSE ) ;
exit ( 1 ) ;
}
#ifdef F_107
F_324 ( F_175 ) ;
if ( V_274 && V_275 ) {
F_274 ( L_203 ) ;
exit ( 1 ) ;
}
if ( V_275 ) {
if ( V_259 ) {
F_274 ( L_204 ) ;
exit ( 1 ) ;
}
if ( V_194 . V_349 ) {
F_274 ( L_205 ) ;
exit ( 1 ) ;
}
} else {
if ( V_274 && V_259 ) {
F_274 ( L_206 ) ;
exit ( 1 ) ;
}
if ( V_194 . V_349 ) {
if ( V_194 . V_350 == NULL ) {
F_274 ( L_207 ) ;
V_194 . V_349 = FALSE ;
}
if ( ! V_194 . V_351 && ! V_194 . V_352 ) {
F_274 ( L_208 ) ;
}
}
}
if ( V_274 || V_275 ) {
V_278 = F_325 ( & V_194 ,
( ( V_254 -> V_353 ) && ( * V_254 -> V_353 != '\0' ) ) ? F_326 ( V_254 -> V_353 ) : NULL ) ;
if ( V_278 != 0 ) {
exit ( V_278 ) ;
}
}
if ( V_275 ) {
T_39 * V_354 ;
T_21 V_355 ;
T_40 V_356 ;
for ( V_355 = 0 ; V_355 < V_194 . V_357 -> V_71 ; V_355 ++ ) {
V_356 = F_327 ( V_194 . V_357 , T_40 , V_355 ) ;
if ( V_356 . V_358 ) {
#if F_142 ( F_141 )
V_354 = F_328 ( V_356 . V_107 , V_356 . V_359 , & V_277 , F_175 ) ;
#else
V_354 = F_328 ( V_356 . V_107 , FALSE , & V_277 , F_175 ) ;
#endif
if ( V_354 == NULL ) {
F_274 ( L_37 , V_277 ) ;
F_9 ( V_277 ) ;
exit ( 2 ) ;
}
if ( V_354 -> V_360 == NULL ) {
F_274 ( L_209 , V_356 . V_107 ) ;
exit ( 2 ) ;
}
#ifdef F_138
F_139 () ;
#endif
#if F_142 ( F_141 )
F_329 ( V_354 , V_356 . V_107 , V_356 . V_359 ) ;
#else
F_329 ( V_354 , V_356 . V_107 , FALSE ) ;
#endif
#ifdef F_138
F_144 () ;
#endif
F_330 ( V_354 ) ;
}
}
exit ( 0 ) ;
}
F_331 ( & V_194 , V_361 ) ;
F_332 ( & V_194 ) ;
#endif
F_333 () ;
#ifdef F_107
if ( ( V_194 . V_362 == 0 ) &&
( ( V_111 . V_353 != NULL ) && ( * V_254 -> V_353 != '\0' ) ) ) {
T_21 V_355 ;
T_40 V_356 ;
for ( V_355 = 0 ; V_355 < V_194 . V_357 -> V_71 ; V_355 ++ ) {
V_356 = F_327 ( V_194 . V_357 , T_40 , V_355 ) ;
if ( ! V_356 . V_363 && strstr ( V_111 . V_353 , V_356 . V_107 ) != NULL ) {
V_356 . V_358 = TRUE ;
V_194 . V_362 ++ ;
V_194 . V_357 = F_334 ( V_194 . V_357 , V_355 ) ;
F_335 ( V_194 . V_357 , V_355 , V_356 ) ;
break;
}
}
}
if ( V_194 . V_362 == 0 && V_194 . V_357 -> V_71 == 1 ) {
T_40 V_356 = F_327 ( V_194 . V_357 , T_40 , 0 ) ;
V_356 . V_358 = TRUE ;
V_194 . V_362 ++ ;
V_194 . V_357 = F_334 ( V_194 . V_357 , 0 ) ;
F_335 ( V_194 . V_357 , 0 , V_356 ) ;
}
#endif
if ( V_238 == NULL && V_239 == NULL ) {
F_336 () ;
}
F_337 ( & V_18 . V_37 , V_254 -> V_55 , TRUE ) ;
V_283 = F_338 ( V_364 ) ;
#if F_339 ( 3 , 0 , 0 )
#else
F_340 ( V_283 ) ;
F_9 ( V_283 ) ;
V_283 = F_341 ( V_364 , FALSE ) ;
F_340 ( V_283 ) ;
#endif
F_9 ( V_283 ) ;
F_342 () ;
F_343 () ;
F_344 () ;
F_177 ( V_290 ) ;
F_345 ( V_280 , V_281 , V_282 , V_254 ) ;
F_346 ( & V_271 , & V_272 ) ;
if ( V_271 != NULL && V_272 != 0 ) {
F_2 ( V_35 , V_7 ,
L_168 ,
V_271 , F_238 ( V_272 ) ) ;
}
F_165 ( V_81 . V_165 ) ;
F_347 () ;
F_348 () ;
#ifdef F_107
F_159 ( V_164 ) ;
#endif
switch ( F_349 () ) {
case V_365 :
break;
case V_366 :
case V_367 :
default:
V_81 . V_368 = 0 ;
}
F_350 ( V_122 ) ;
F_351 () ;
#ifdef F_107
F_352 () ;
#endif
F_130 ( V_122 ) ;
F_310 ( V_269 , F_151 , NULL ) ;
if ( V_259 ) {
F_353 ( TRUE ) ;
F_241 ( V_259 ) ;
if ( V_284 != NULL ) {
if ( ! F_354 ( V_284 , & V_287 ) ) {
F_355 ( V_122 , V_284 ) ;
V_288 = TRUE ;
}
}
if ( F_356 ( L_210 ) > 0 ) {
V_295 = F_357 ( F_358 ( L_210 ) ) ;
}
if ( ! V_288 ) {
if ( F_359 ( & V_18 , V_259 , V_295 , FALSE , & V_273 ) == V_369 ) {
V_18 . V_287 = V_287 ;
F_360 () ;
switch ( F_361 ( & V_18 , FALSE ) ) {
case V_370 :
case V_371 :
if( V_291 != 0 ) {
F_362 ( & V_18 , V_291 ) ;
} else if ( V_286 != NULL ) {
if ( ! F_354 ( V_286 , & V_293 ) ) {
F_355 ( V_122 , V_286 ) ;
} else {
F_363 ( & V_18 , V_293 , V_292 ) ;
}
}
break;
case V_372 :
exit ( 0 ) ;
break;
}
if ( ! F_364 ( V_259 ) ) {
char * V_373 = V_259 ;
char * V_374 = F_365 () ;
V_259 = F_27 ( L_211 , V_374 , V_375 , V_259 ) ;
F_9 ( V_373 ) ;
F_9 ( V_374 ) ;
}
V_266 = F_182 ( V_259 ) ;
F_183 ( V_266 ) ;
F_9 ( V_259 ) ;
V_259 = NULL ;
} else {
if ( V_287 != NULL )
F_366 ( V_287 ) ;
V_18 . V_287 = NULL ;
F_353 ( FALSE ) ;
F_105 ( FALSE ) ;
F_109 ( FALSE ) ;
}
}
} else {
#ifdef F_107
if ( V_274 ) {
if ( V_194 . V_350 != NULL ) {
V_266 = F_182 ( F_6 ( V_194 . V_350 ) ) ;
F_183 ( V_266 ) ;
F_9 ( V_266 ) ;
}
F_353 ( FALSE ) ;
F_241 ( V_259 ) ;
if ( V_194 . V_376 -> V_71 == 0 )
F_367 ( & V_194 ) ;
if ( F_368 ( & V_194 , & V_123 , F_175 ) ) {
F_360 () ;
}
} else {
F_353 ( FALSE ) ;
F_241 ( V_259 ) ;
F_105 ( FALSE ) ;
F_109 ( FALSE ) ;
}
if ( ! V_274 && ! V_194 . V_377 . V_378 ) {
V_194 . V_377 . V_378 = F_6 ( F_294 () ) ;
}
#else
F_353 ( FALSE ) ;
F_241 ( V_259 ) ;
F_105 ( FALSE ) ;
F_109 ( FALSE ) ;
#endif
}
if ( V_285 ) {
T_1 * V_1 ;
V_1 = F_369 ( F_370 ( F_19 ( F_20 ( V_122 ) , V_379 ) ) ) ;
F_14 ( F_15 ( V_1 ) , V_285 ) ;
F_16 ( & V_18 , V_285 , FALSE ) ;
}
F_371 () ;
F_269 ( FALSE ) ;
#ifdef F_215
V_224 = ( T_34 * ) F_216 ( V_227 , NULL ) ;
F_217 ( V_224 , F_186 ( - 1 , V_193 , FALSE , NULL ) ) ;
F_372 ( V_224 ) ;
#endif
F_210 ( V_202 , V_380 , L_212 ) ;
#ifdef F_107
F_373 () ;
#endif
F_374 () ;
F_375 () ;
#ifdef F_107
F_376 () ;
#endif
F_377 () ;
F_378 () ;
F_379 ( & V_299 ) ;
#ifdef F_215
F_380 ( V_224 ) ;
#endif
#ifdef F_138
if ( F_381 ( V_122 ) )
F_382 ( V_122 ) ;
F_383 () ;
F_384 () ;
F_144 () ;
#endif
exit ( 0 ) ;
}
int T_41
F_385 ( struct V_381 * V_382 ,
struct V_381 * V_383 ,
char * V_384 ,
int V_385 )
{
T_42 V_386 ;
F_386 () ;
memset ( & V_386 , 0 , sizeof( V_386 ) ) ;
V_386 . V_387 = sizeof( V_386 ) ;
V_386 . V_388 = V_389 ;
F_387 ( & V_386 ) ;
F_388 ( L_213 ) ;
F_389 ( FALSE ) ;
F_390 ( FALSE ) ;
return main ( V_390 , V_391 ) ;
}
static void F_391 ( T_1 * T_10 , T_4 V_19 ) {
F_392 ( F_393 ( V_19 ) , T_10 ) ;
}
static T_1 * F_394 ( T_9 V_392 )
{
switch( V_392 ) {
case ( V_393 ) :
return NULL ;
case ( V_394 ) :
return V_160 ;
case ( V_395 ) :
return V_161 ;
case ( V_396 ) :
return V_104 ;
default:
F_8 () ;
return NULL ;
}
}
void F_347 ( void ) {
T_1 * V_397 , * V_398 ;
T_1 * V_399 , * V_400 ;
T_11 V_401 = FALSE ;
F_382 ( V_402 ) ;
F_395 ( F_20 ( V_403 ) ) ;
F_395 ( F_20 ( V_404 ) ) ;
F_395 ( F_20 ( V_405 ) ) ;
F_395 ( F_20 ( V_406 ) ) ;
F_395 ( F_20 ( V_160 ) ) ;
F_395 ( F_20 ( V_161 ) ) ;
F_395 ( F_20 ( V_104 ) ) ;
F_395 ( F_20 ( V_407 ) ) ;
F_395 ( F_20 ( V_408 ) ) ;
F_395 ( F_20 ( V_409 ) ) ;
F_395 ( F_20 ( V_410 ) ) ;
F_395 ( F_20 ( V_411 ) ) ;
F_395 ( F_20 ( V_412 ) ) ;
F_396 ( F_393 ( V_402 ) , F_391 , V_402 ) ;
F_396 ( F_393 ( V_408 ) , F_391 , V_408 ) ;
F_396 ( F_393 ( V_409 ) , F_391 , V_409 ) ;
F_396 ( F_393 ( V_410 ) , F_391 , V_410 ) ;
F_396 ( F_393 ( V_411 ) , F_391 , V_411 ) ;
F_397 ( V_407 ) ;
F_398 ( F_399 ( V_402 ) , V_403 , FALSE , TRUE , 0 ) ;
F_398 ( F_399 ( V_402 ) , V_404 , FALSE , TRUE , 0 ) ;
if ( ! V_111 . V_413 ) {
F_398 ( F_399 ( V_402 ) , V_405 , FALSE , TRUE , 1 ) ;
}
F_398 ( F_399 ( V_402 ) , V_406 , FALSE , TRUE , 1 ) ;
switch( V_111 . V_414 ) {
case ( V_415 ) :
V_130 = V_408 ;
V_133 = V_409 ;
V_401 = FALSE ;
break;
case ( V_416 ) :
V_130 = V_408 ;
V_133 = V_410 ;
V_401 = FALSE ;
break;
case ( V_417 ) :
V_130 = V_408 ;
V_133 = V_410 ;
V_401 = TRUE ;
break;
case ( V_418 ) :
V_130 = V_410 ;
V_133 = V_408 ;
V_401 = FALSE ;
break;
case ( V_419 ) :
V_130 = V_410 ;
V_133 = V_408 ;
V_401 = TRUE ;
break;
case ( V_420 ) :
V_130 = V_410 ;
V_133 = V_411 ;
V_401 = FALSE ;
break;
default:
V_130 = NULL ;
V_133 = NULL ;
F_8 () ;
}
if ( V_401 ) {
V_397 = V_133 ;
V_399 = F_394 ( V_111 . V_421 ) ;
V_400 = F_394 ( V_111 . V_422 ) ;
V_398 = F_394 ( V_111 . V_423 ) ;
} else {
V_397 = F_394 ( V_111 . V_421 ) ;
V_398 = V_133 ;
V_399 = F_394 ( V_111 . V_422 ) ;
V_400 = F_394 ( V_111 . V_423 ) ;
}
if ( V_397 != NULL )
F_400 ( F_129 ( V_130 ) , V_397 ) ;
if ( V_398 != NULL )
F_401 ( F_129 ( V_130 ) , V_398 ) ;
if ( V_399 != NULL )
F_402 ( F_129 ( V_133 ) , V_399 , TRUE , TRUE ) ;
if ( V_400 != NULL )
F_403 ( F_129 ( V_133 ) , V_400 , FALSE , FALSE ) ;
F_398 ( F_399 ( V_402 ) , V_130 , TRUE , TRUE , 0 ) ;
F_398 ( F_399 ( V_402 ) , V_412 , TRUE , TRUE , 0 ) ;
F_398 ( F_399 ( V_402 ) , V_407 , FALSE , TRUE , 0 ) ;
if ( V_111 . V_413 ) {
F_398 ( F_399 ( V_407 ) , V_405 , FALSE , TRUE , 1 ) ;
}
F_404 ( V_407 ) ;
F_111 () ;
F_405 ( V_402 ) ;
}
static void
F_406 ( T_1 * T_10 , T_4 V_19 )
{
T_11 * V_424 = ( T_11 * ) V_19 ;
if ( ! * V_424 ) {
if ( F_407 ( T_10 ) )
* V_424 = TRUE ;
}
}
void
F_111 ( void )
{
T_11 V_425 ;
if ( V_81 . V_426 ) {
F_405 ( V_404 ) ;
} else {
F_382 ( V_404 ) ;
}
F_408 ( V_407 ) ;
if ( V_81 . V_427 ) {
F_405 ( V_405 ) ;
} else {
F_382 ( V_405 ) ;
}
if ( V_81 . V_428 ) {
F_405 ( V_406 ) ;
} else {
F_382 ( V_406 ) ;
}
if ( V_81 . V_429 && V_118 ) {
F_405 ( V_160 ) ;
} else {
F_382 ( V_160 ) ;
}
if ( V_81 . V_430 && V_118 ) {
F_405 ( V_161 ) ;
} else {
F_382 ( V_161 ) ;
}
if ( V_81 . V_431 && V_118 ) {
F_405 ( V_104 ) ;
} else {
F_382 ( V_104 ) ;
}
if ( V_118 ) {
F_405 ( V_130 ) ;
} else {
F_382 ( V_130 ) ;
}
V_425 = FALSE ;
F_396 ( F_393 ( V_133 ) , F_406 ,
& V_425 ) ;
if ( V_425 ) {
F_405 ( V_133 ) ;
} else {
F_382 ( V_133 ) ;
}
if ( ! V_118 ) {
if( V_412 ) {
F_405 ( V_412 ) ;
}
} else {
F_382 ( V_412 ) ;
}
}
static T_11
F_409 ( T_1 * T_10 V_24 ,
T_26 * T_27 ,
T_4 V_19 V_24 )
{
T_43 V_432 = ( ( V_433 * ) T_27 ) -> V_432 ;
if( ( T_27 -> type ) == ( V_434 ) ) {
if( ! ( V_432 & V_435 ) ) {
F_410 () ;
}
}
return FALSE ;
}
static T_11
F_411 ( T_1 * T_6 V_24 , T_44 * T_27 , T_4 T_19 V_24 )
{
if ( T_27 -> V_436 == V_437 ) {
F_412 () ;
return TRUE ;
} else if ( T_27 -> V_436 == V_438 ) {
F_413 () ;
return TRUE ;
} else if ( T_27 -> V_124 & V_439 ) {
return FALSE ;
} else if ( T_27 -> V_436 < 256 && F_414 ( T_27 -> V_436 ) ) {
if ( V_440 && ! F_415 ( V_440 ) ) {
F_416 ( F_171 ( V_122 ) , V_440 ) ;
F_417 ( F_5 ( V_440 ) , - 1 ) ;
}
return FALSE ;
}
return FALSE ;
}
static void
F_345 ( T_9 V_280 , T_9 V_281 , T_9 V_282 , T_35 * V_254
#if ! F_142 ( V_441 ) && ! F_142 ( F_215 )
V_24
#endif
)
{
T_45 * V_442 ;
V_122 = F_418 ( V_443 , L_9 ) ;
F_156 ( NULL ) ;
F_419 ( V_122 , L_214 ) ;
F_420 ( V_122 , L_215 , F_421 ( F_125 ) ,
NULL ) ;
F_420 ( F_20 ( V_122 ) , L_216 ,
F_421 ( F_409 ) , NULL ) ;
F_420 ( F_20 ( V_122 ) , L_217 ,
F_421 ( F_411 ) , NULL ) ;
V_402 = F_422 ( V_444 , 1 , FALSE ) ;
F_423 ( F_393 ( V_402 ) , 0 ) ;
F_424 ( F_393 ( V_122 ) , V_402 ) ;
F_405 ( V_402 ) ;
V_403 = F_425 ( & V_442 ) ;
#if F_142 ( V_441 ) || F_142 ( F_215 )
if( ! V_254 -> V_445 ) {
#endif
F_426 ( F_171 ( V_122 ) , V_442 ) ;
F_405 ( V_403 ) ;
#if F_142 ( V_441 ) || F_142 ( F_215 )
} else {
F_382 ( V_403 ) ;
}
#endif
V_404 = F_427 () ;
F_405 ( V_404 ) ;
V_405 = F_428 () ;
V_160 = F_429 () ;
F_430 ( V_160 , - 1 , V_280 ) ;
F_431 ( V_160 ) ;
V_161 = F_432 ( & V_110 ) ;
F_430 ( V_161 , - 1 , V_281 ) ;
F_405 ( V_161 ) ;
F_420 ( F_433 ( F_98 ( V_110 ) ) ,
L_218 , F_421 ( F_74 ) , NULL ) ;
F_420 ( V_110 , L_219 , F_421 ( V_446 ) ,
F_19 ( F_20 ( V_447 ) , V_448 ) ) ;
F_405 ( V_110 ) ;
V_104 = F_434 () ;
F_430 ( V_104 , - 1 , V_282 ) ;
F_405 ( V_104 ) ;
F_420 ( V_104 , L_219 , F_421 ( V_446 ) ,
F_19 ( F_20 ( V_447 ) , V_449 ) ) ;
V_408 = F_435 ( V_444 ) ;
F_405 ( V_408 ) ;
V_409 = F_435 ( V_444 ) ;
F_405 ( V_409 ) ;
V_410 = F_435 ( V_450 ) ;
F_405 ( V_410 ) ;
V_411 = F_435 ( V_450 ) ;
F_405 ( V_411 ) ;
#ifdef F_226
V_406 = F_436 () ;
#else
V_406 = F_437 () ;
#endif
F_405 ( V_406 ) ;
V_407 = F_438 () ;
F_405 ( V_407 ) ;
V_412 = F_439 () ;
F_405 ( V_412 ) ;
}
static void
F_353 ( T_11 V_451 )
{
F_110 ( V_451 ) ;
F_405 ( V_122 ) ;
F_130 ( V_122 ) ;
while ( F_440 () ) F_441 () ;
F_410 () ;
F_442 ( F_153 ( V_122 ) ) ;
#ifdef F_226
F_443 ( V_406 ) ;
#endif
}
static void F_444 ( const T_2 * V_452 )
{
char * V_453 , * V_454 , * V_455 ;
if ( F_445 ( V_452 , & V_453 ) == - 1 ) {
F_2 ( V_6 , V_7 ,
L_220 ,
V_453 , F_238 ( V_456 ) ) ;
F_9 ( V_453 ) ;
}
if ( F_446 ( V_452 , V_452 , TRUE , & V_455 ,
& V_453 , & V_454 ) == - 1 ) {
F_2 ( V_6 , V_7 ,
L_221 ,
V_455 , V_454 , V_453 , F_238 ( V_456 ) ) ;
F_9 ( V_455 ) ;
F_9 ( V_453 ) ;
F_9 ( V_454 ) ;
}
}
void F_447 ( const T_2 * V_452 )
{
char * V_238 , * V_239 ;
char * V_271 ;
int V_272 ;
if ( ! F_272 ( V_452 , FALSE ) ) {
if ( F_272 ( V_452 , TRUE ) ) {
F_444 ( V_452 ) ;
} else {
return;
}
}
if ( V_452 && strcmp ( V_452 , F_448 () ) == 0 ) {
return;
}
F_119 ( V_122 ) ;
if ( F_272 ( F_448 () , FALSE ) ) {
F_120 () ;
}
F_273 ( V_452 ) ;
F_449 () ;
F_450 ( V_457 ) ;
F_451 () ;
F_452 () ;
( void ) F_235 ( & V_238 , & V_239 ) ;
F_281 ( & V_271 , & V_272 ) ;
if ( V_271 != NULL && V_272 != 0 ) {
F_2 ( V_35 , V_7 ,
L_163 ,
V_271 , F_238 ( V_272 ) ) ;
}
if ( V_81 . V_308 &&
F_282 ( V_81 . V_308 ) == V_309 ) {
F_183 ( V_81 . V_308 ) ;
}
F_67 ( V_81 . V_82 ) ;
F_321 ( V_81 . V_458 ) ;
F_165 ( V_81 . V_165 ) ;
F_313 () ;
F_333 () ;
F_453 () ;
F_454 () ;
F_450 ( V_459 ) ;
F_455 () ;
F_456 () ;
if ( V_238 == NULL && V_239 == NULL ) {
F_336 () ;
}
F_457 () ;
F_458 () ;
F_94 () ;
V_18 . V_113 = FALSE ;
F_349 () ;
F_348 () ;
F_127 () ;
}
void F_459 ( void )
{
F_460 ( & V_18 ) ;
F_461 () ;
}
