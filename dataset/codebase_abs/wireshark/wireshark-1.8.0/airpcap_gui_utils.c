void
F_1 ( T_1 * V_1 )
{
T_2 * V_2 ;
T_2 * V_3 ;
T_2 * V_4 ;
T_2 * V_5 ;
T_2 * V_6 ;
T_2 * V_7 ;
T_2 * V_8 ;
T_2 * V_9 ;
T_2 * V_10 ;
T_2 * V_11 ;
T_2 * V_12 ;
T_3 * V_13 ;
V_2 = F_2 ( F_3 ( V_14 ) , V_15 ) ;
V_3 = F_2 ( F_3 ( V_14 ) , V_16 ) ;
V_4 = F_2 ( F_3 ( V_14 ) , V_17 ) ;
V_5 = F_2 ( F_3 ( V_14 ) , V_18 ) ;
V_6 = F_2 ( F_3 ( V_14 ) , V_19 ) ;
V_8 = F_2 ( F_3 ( V_14 ) , V_20 ) ;
V_9 = F_2 ( F_3 ( V_14 ) , V_21 ) ;
V_7 = F_2 ( F_3 ( V_14 ) , V_22 ) ;
V_10 = F_2 ( F_3 ( V_14 ) , V_23 ) ;
V_11 = F_2 ( F_3 ( V_14 ) , V_24 ) ;
V_12 = F_2 ( F_3 ( V_14 ) , V_25 ) ;
if( V_1 != NULL )
{
F_4 ( V_14 , TRUE ) ;
F_4 ( V_2 , TRUE ) ;
F_4 ( V_3 , TRUE ) ;
F_4 ( V_4 , TRUE ) ;
F_4 ( V_5 , TRUE ) ;
F_4 ( V_6 , TRUE ) ;
F_4 ( V_8 , FALSE ) ;
F_4 ( V_9 , FALSE ) ;
F_4 ( V_7 , FALSE ) ;
F_4 ( V_7 , FALSE ) ;
F_4 ( V_10 , FALSE ) ;
F_4 ( V_11 , FALSE ) ;
F_4 ( V_12 , FALSE ) ;
F_5 ( V_10 , V_26 , V_14 ) ;
if( V_1 -> V_27 == V_28 )
F_6 ( F_7 ( V_10 ) , TRUE ) ;
else
F_6 ( F_7 ( V_10 ) , FALSE ) ;
F_8 ( V_10 , V_26 , V_14 ) ;
V_13 = F_9 ( L_1 , F_10 ( V_1 ) ) ;
F_11 ( F_12 ( V_2 ) , V_13 ) ;
F_13 ( V_13 ) ;
V_29 = FALSE ;
if ( V_1 -> V_30 != NULL && V_1 -> V_31 > 0 ) {
T_4 V_32 = 0 ;
for (; V_32 < V_1 -> V_31 ; V_32 ++ ) {
F_14 ( F_15 ( V_3 ) , F_16 ( V_1 -> V_30 [ V_32 ] . V_33 ) ) ;
}
}
F_17 ( F_18 ( V_3 ) , V_1 ) ;
F_19 ( V_1 , V_1 -> V_34 . V_33 , V_5 , TRUE ) ;
V_29 = TRUE ;
}
else
{
F_4 ( V_14 , FALSE ) ;
F_4 ( V_2 , FALSE ) ;
F_4 ( V_3 , FALSE ) ;
F_4 ( V_4 , FALSE ) ;
F_4 ( V_5 , FALSE ) ;
F_4 ( V_6 , FALSE ) ;
F_4 ( V_8 , FALSE ) ;
F_4 ( V_9 , FALSE ) ;
F_4 ( V_7 , FALSE ) ;
F_4 ( V_7 , FALSE ) ;
F_4 ( V_10 , FALSE ) ;
F_4 ( V_11 , FALSE ) ;
F_4 ( V_12 , FALSE ) ;
}
}
void
F_20 ( T_1 * V_1 )
{
T_2 * V_35 ;
T_2 * V_2 ;
T_2 * V_3 ;
T_2 * V_4 ;
T_2 * V_5 ;
T_2 * V_6 ;
T_2 * V_7 ;
T_2 * V_8 ;
T_2 * V_9 ;
T_2 * V_10 ;
T_2 * V_11 ;
T_2 * V_12 ;
T_3 * V_13 ;
V_35 = F_2 ( F_3 ( V_14 ) , V_20 ) ;
V_2 = F_2 ( F_3 ( V_14 ) , V_15 ) ;
V_3 = F_2 ( F_3 ( V_14 ) , V_16 ) ;
V_4 = F_2 ( F_3 ( V_14 ) , V_17 ) ;
V_5 = F_2 ( F_3 ( V_14 ) , V_18 ) ;
V_6 = F_2 ( F_3 ( V_14 ) , V_19 ) ;
V_8 = F_2 ( F_3 ( V_14 ) , V_20 ) ;
V_9 = F_2 ( F_3 ( V_14 ) , V_21 ) ;
V_7 = F_2 ( F_3 ( V_14 ) , V_22 ) ;
V_10 = F_2 ( F_3 ( V_14 ) , V_23 ) ;
V_11 = F_2 ( F_3 ( V_14 ) , V_24 ) ;
V_12 = F_2 ( F_3 ( V_14 ) , V_25 ) ;
if( V_1 != NULL )
{
F_4 ( V_14 , TRUE ) ;
F_4 ( V_2 , TRUE ) ;
F_4 ( V_3 , TRUE ) ;
F_4 ( V_4 , TRUE ) ;
F_4 ( V_5 , TRUE ) ;
F_4 ( V_6 , TRUE ) ;
F_4 ( V_8 , TRUE ) ;
F_4 ( V_9 , TRUE ) ;
F_4 ( V_7 , TRUE ) ;
F_4 ( V_35 , TRUE ) ;
F_4 ( V_10 , TRUE ) ;
F_4 ( V_11 , TRUE ) ;
F_4 ( V_12 , TRUE ) ;
F_21 ( V_35 , V_1 -> V_36 ) ;
F_5 ( V_10 , V_26 , V_14 ) ;
if( V_1 -> V_27 == V_28 )
F_6 ( F_7 ( V_10 ) , TRUE ) ;
else
F_6 ( F_7 ( V_10 ) , FALSE ) ;
F_8 ( V_10 , V_26 , V_14 ) ;
V_13 = F_9 ( L_1 , F_10 ( V_1 ) ) ;
F_11 ( F_12 ( V_2 ) , V_13 ) ;
F_13 ( V_13 ) ;
V_29 = FALSE ;
if ( V_1 -> V_30 != NULL && V_1 -> V_31 > 0 ) {
T_4 V_32 = 0 ;
for (; V_32 < V_1 -> V_31 ; V_32 ++ ) {
F_14 ( F_15 ( V_3 ) , F_16 ( V_1 -> V_30 [ V_32 ] . V_33 ) ) ;
}
}
F_17 ( F_18 ( V_3 ) , V_1 ) ;
F_19 ( V_1 , V_1 -> V_34 . V_33 , V_5 , TRUE ) ;
V_29 = TRUE ;
}
else
{
F_4 ( V_14 , TRUE ) ;
F_4 ( V_2 , FALSE ) ;
F_4 ( V_3 , FALSE ) ;
F_4 ( V_4 , FALSE ) ;
F_4 ( V_5 , FALSE ) ;
F_4 ( V_6 , FALSE ) ;
F_4 ( V_8 , FALSE ) ;
F_4 ( V_9 , FALSE ) ;
F_4 ( V_7 , FALSE ) ;
F_4 ( V_35 , FALSE ) ;
F_4 ( V_10 , TRUE ) ;
F_4 ( V_11 , TRUE ) ;
F_4 ( V_12 , TRUE ) ;
V_29 = FALSE ;
}
}
void
F_22 ( T_5 * V_37 , T_3 * type , T_3 * V_38 , T_3 * V_39 )
{
T_6 V_40 ;
F_23 ( V_37 , & V_40 , V_41 ,
V_42 , type ,
V_43 , V_38 ,
V_44 , V_39 ,
- 1 ) ;
}
void
F_24 ( T_5 * V_37 )
{
T_3 * V_45 = NULL ;
unsigned int V_32 , V_46 ;
T_1 * V_47 ;
T_7 * V_48 = NULL ;
T_8 * V_49 = NULL ;
T_6 V_40 ;
V_47 = F_25 () ;
V_48 = F_26 () ;
V_46 = F_27 ( V_48 ) ;
for( V_32 = 0 ; V_32 < V_46 ; V_32 ++ )
{
V_49 = ( T_8 * ) F_28 ( V_48 , V_32 ) ;
if( V_49 -> type == V_50 )
{
F_23 ( V_37 , & V_40 , V_41 ,
V_42 , V_51 ,
V_43 , V_49 -> V_38 -> V_52 ,
V_44 , L_2 ,
- 1 ) ;
}
else if( V_49 -> type == V_53 )
{
if( V_49 -> V_39 != NULL )
V_45 = F_29 ( V_49 -> V_39 , L_3 ) ;
else
V_45 = L_2 ;
F_23 ( V_37 , & V_40 , V_41 ,
V_42 , V_54 ,
V_43 , V_49 -> V_38 -> V_52 ,
V_44 , V_45 ,
- 1 ) ;
}
else if( V_49 -> type == V_55 )
{
F_23 ( V_37 , & V_40 , V_41 ,
V_42 , V_56 ,
V_43 , V_49 -> V_38 -> V_52 ,
V_44 , L_2 ,
- 1 ) ;
}
}
F_30 ( V_47 ) ;
return;
}
T_9
F_31 ( const T_3 * V_57 )
{
if( ! ( F_32 ( V_58 , V_57 ) ) )
{
return V_59 ;
}
else if( ! ( F_32 ( V_60 , V_57 ) ) )
{
return V_61 ;
}
else if( ! ( F_32 ( V_62 , V_57 ) ) )
{
return V_63 ;
}
return V_64 ;
}
const T_3 *
F_33 ( T_9 V_65 )
{
if( V_65 == V_59 )
{
return V_58 ;
}
else if( V_65 == V_61 )
{
return V_60 ;
}
else if( V_65 == V_63 )
{
return V_62 ;
}
else if( V_65 == V_64 )
{
return V_66 ;
}
return NULL ;
}
T_10
F_34 ( T_9 V_65 )
{
switch ( V_65 ) {
case V_61 :
return 1 ;
break;
case V_63 :
return 2 ;
break;
default:
return 0 ;
break;
}
}
T_11
F_35 ( const T_3 * V_57 )
{
if( ! ( F_32 ( V_67 , V_57 ) ) ) {
return V_68 ;
} else if( ! ( F_32 ( V_69 , V_57 ) ) ) {
return V_70 ;
} else if( ! ( F_32 ( V_71 , V_57 ) ) ) {
return V_72 ;
} else{
return V_73 ;
}
}
T_3 *
F_36 ( T_11 V_74 )
{
if( V_74 == V_68 ) {
return V_67 ;
} else if( V_74 == V_70 ) {
return V_69 ;
} else if( V_74 == V_72 ) {
return V_71 ;
} else if( V_74 == V_73 ) {
return V_75 ;
}
return NULL ;
}
void
F_21 ( T_2 * V_76 , T_9 type )
{
F_37 ( F_38 ( V_76 ) , F_34 ( type ) ) ;
}
T_3 *
F_39 ( T_4 V_46 )
{
return F_9 ( L_4 , V_46 ) ;
}
void
F_40 ( T_2 * V_77 , T_4 V_78 )
{
T_4 V_32 ;
for ( V_32 = 0 ; V_32 < V_79 -> V_31 ; V_32 ++ ) {
if ( V_79 -> V_30 [ V_32 ] . V_33 == V_78 ) {
F_37 ( F_38 ( V_77 ) , V_32 ) ;
break;
}
}
}
static T_12
F_41 ( T_1 * V_1 )
{
T_3 V_80 [ V_81 ] ;
T_13 V_82 ;
T_12 V_83 = FALSE ;
if ( V_1 != NULL ) {
V_82 = F_42 ( V_1 -> V_57 , V_80 ) ;
if( V_82 != NULL ) {
V_83 = F_43 ( V_82 , V_1 -> V_34 ) ;
F_44 ( V_82 ) ;
}
}
return V_83 ;
}
static void
F_45 ( T_2 * V_84 , T_14 V_85 , T_12 V_86 )
{
T_10 V_87 ;
if ( V_84 && V_85 && V_29 && V_88 ) {
V_87 = F_46 ( F_38 ( V_84 ) ) ;
if ( V_87 >= 0 && V_87 < ( T_10 ) V_88 -> V_31 ) {
if ( V_86 ) {
V_88 -> V_34 . V_33 = V_88 -> V_30 [ V_87 ] . V_33 ;
}
F_19 ( V_88 ,
V_88 -> V_34 . V_33 ,
F_18 ( V_85 ) , V_86 ) ;
}
}
}
void
F_47 ( T_2 * V_84 , T_14 V_85 )
{
F_45 ( V_84 , V_85 , TRUE ) ;
}
void
F_48 ( T_2 * V_84 , T_14 V_85 )
{
F_45 ( V_84 , V_85 , FALSE ) ;
}
static int
F_49 ( T_2 * V_85 ) {
int V_89 ;
T_3 * V_90 ;
int V_91 = 0 ;
if ( V_85 == NULL || ! F_50 ( V_85 ) ) {
return 0 ;
}
V_90 = F_51 ( F_15 ( V_85 ) ) ;
if ( V_90 && ( F_32 ( L_2 , V_90 ) ) )
{
if ( V_79 != NULL )
{
sscanf ( V_90 , L_4 , & V_89 ) ;
if ( V_89 >= - 1 && V_89 <= 1 ) {
V_91 = V_89 ;
}
}
}
F_13 ( V_90 ) ;
return V_91 ;
}
void
F_52 ( T_2 * V_85 , T_14 T_15 V_92 )
{
V_79 -> V_34 . V_93 = F_49 ( V_85 ) ;
V_79 -> V_94 = FALSE ;
V_29 = TRUE ;
if ( ! F_41 ( V_79 ) ) {
F_53 ( V_95 , V_96 ,
L_5 ,
V_79 -> V_34 . V_93 ) ;
}
}
void
F_19 ( T_1 * V_1 , T_4 V_78 , T_2 * V_85 , T_12 V_86 )
{
T_10 V_97 ;
T_10 V_98 ;
T_4 V_32 ;
T_10 V_99 = 0 ;
T_10 V_100 = - 1 ;
if ( ! V_1 || F_54 ( V_1 ) || V_1 -> V_30 == NULL || V_1 -> V_31 < 1 ) {
F_4 ( F_18 ( V_85 ) , FALSE ) ;
F_37 ( F_38 ( V_85 ) , - 1 ) ;
return;
}
V_98 = V_97 = V_1 -> V_34 . V_93 ;
while ( F_55 ( F_56 ( F_38 ( V_85 ) ) , NULL ) > 0 ) {
F_57 ( F_15 ( V_85 ) , 0 ) ;
}
F_4 ( F_18 ( V_85 ) , TRUE ) ;
for ( V_32 = 0 ; V_32 < V_1 -> V_31 ; V_32 ++ ) {
if ( V_1 -> V_30 [ V_32 ] . V_33 == V_78 ) {
if ( V_97 == - 1 && ! ( V_1 -> V_30 [ V_32 ] . V_101 & V_102 ) ) {
V_98 = 0 ;
} else if ( V_97 == 1 && ! ( V_1 -> V_30 [ V_32 ] . V_101 & V_103 ) ) {
V_98 = 0 ;
}
if ( ( V_1 -> V_30 [ V_32 ] . V_101 & V_102 ) ) {
F_14 ( F_15 ( V_85 ) , L_6 ) ;
V_100 ++ ;
if ( V_98 == - 1 ) {
V_99 = V_100 ;
}
}
F_14 ( F_15 ( V_85 ) , L_7 ) ;
V_100 ++ ;
if ( V_98 == 0 ) {
V_99 = V_100 ;
}
if ( ( V_1 -> V_30 [ V_32 ] . V_101 & V_103 ) ) {
F_14 ( F_15 ( V_85 ) , L_8 ) ;
V_100 ++ ;
if ( V_98 == 1 ) {
V_99 = V_100 ;
}
}
break;
}
}
F_37 ( F_38 ( V_85 ) , V_99 ) ;
if ( V_86 ) {
V_29 = TRUE ;
V_1 -> V_34 . V_93 = V_98 ;
if ( ! F_41 ( V_1 ) ) {
F_53 ( V_95 , V_96 , L_9 , V_1 -> V_34 . V_33 , V_1 -> V_34 . V_93 ) ;
}
}
if ( V_100 < 1 ) {
F_4 ( V_85 , FALSE ) ;
}
}
int
F_54 ( T_1 * V_1 )
{
if( F_32 ( V_1 -> V_57 , V_104 ) == 0 )
return 1 ;
else
return 0 ;
}
void
F_17 ( T_2 * V_84 , T_1 * V_1 )
{
if( ! V_1 || F_54 ( V_1 ) || ! V_79 )
{
F_37 ( F_38 ( V_84 ) , - 1 ) ;
V_29 = FALSE ;
F_4 ( F_18 ( V_84 ) , FALSE ) ;
}
else
{
while ( F_55 ( F_56 ( F_38 ( V_84 ) ) , NULL ) > 0 ) {
F_57 ( F_15 ( V_84 ) , 0 ) ;
}
if ( V_1 -> V_30 != NULL && V_1 -> V_31 > 0 ) {
T_4 V_32 ;
for ( V_32 = 0 ; V_32 < ( V_1 -> V_31 ) ; V_32 ++ ) {
F_14 ( F_15 ( V_84 ) , F_16 ( V_79 -> V_30 [ V_32 ] . V_33 ) ) ;
}
}
F_40 ( V_84 , V_1 -> V_34 . V_33 ) ;
V_29 = TRUE ;
F_4 ( F_18 ( V_84 ) , TRUE ) ;
}
}
static void
F_58 ( T_5 * V_37 , T_1 * V_47 )
{
T_16 * V_105 ;
T_6 V_40 ;
T_17 * V_106 = F_59 ( V_37 ) ;
T_4 V_32 , V_107 ;
T_3 V_45 [ 3 ] ;
T_18 V_108 ;
T_4 V_109 ;
T_19 V_110 ;
T_4 V_111 = 0 ;
T_3 * V_112 , * V_113 ;
T_20 V_114 ;
if( V_47 == NULL )
return;
V_111 = F_55 ( V_106 , NULL ) ;
V_109 = sizeof( V_115 ) + V_111 * sizeof( V_116 ) ;
V_108 = ( T_18 ) F_60 ( V_109 ) ;
V_108 -> V_117 = V_111 ;
for( V_32 = 0 ; V_32 < V_111 ; V_32 ++ )
{
V_105 = F_61 ( V_32 , - 1 ) ;
F_62 ( V_106 , & V_40 , V_105 ) ;
F_63 ( V_105 ) ;
F_64 ( V_106 , & V_40 ,
V_42 , & V_112 ,
V_43 , & V_113 ,
- 1 ) ;
if( F_32 ( V_112 , V_51 ) == 0 )
V_108 -> V_118 [ V_32 ] . V_119 = V_50 ;
else if( F_32 ( V_112 , V_54 ) == 0 )
V_108 -> V_118 [ V_32 ] . V_119 = V_53 ;
else if( F_32 ( V_112 , V_56 ) == 0 )
V_108 -> V_118 [ V_32 ] . V_119 = V_55 ;
V_114 = strlen ( V_113 ) ;
V_108 -> V_118 [ V_32 ] . V_120 = ( T_4 ) V_114 / 2 ;
memset ( & V_108 -> V_118 [ V_32 ] . V_121 , 0 , sizeof( V_108 -> V_118 [ V_32 ] . V_121 ) ) ;
if( V_108 -> V_118 [ V_32 ] . V_119 == V_50 )
{
for( V_107 = 0 ; V_107 < V_114 ; V_107 += 2 )
{
V_45 [ 0 ] = V_113 [ V_107 ] ;
V_45 [ 1 ] = V_113 [ V_107 + 1 ] ;
V_45 [ 2 ] = '\0' ;
V_110 = ( T_19 ) strtol ( V_45 , NULL , 16 ) ;
V_108 -> V_118 [ V_32 ] . V_121 [ V_107 / 2 ] = V_110 ;
}
}
F_13 ( V_112 ) ;
F_13 ( V_113 ) ;
}
if( V_47 -> V_122 != NULL )
F_13 ( V_47 -> V_122 ) ;
V_47 -> V_122 = V_108 ;
V_47 -> V_123 = V_109 ;
return;
}
void
F_65 ( T_5 * V_37 , T_1 * V_124 , T_7 * V_125 )
{
T_6 V_40 ;
T_17 * V_106 = F_59 ( V_37 ) ;
T_12 V_126 ;
T_10 V_127 = 0 ;
T_10 V_32 = 0 ;
T_1 * V_128 = NULL ;
T_1 * V_129 = NULL ;
T_7 * V_130 = NULL ;
char * V_131 = NULL ;
char * V_132 = NULL ;
char * V_133 = L_2 ;
T_8 * V_134 = NULL ;
for ( V_126 = F_66 ( V_106 , & V_40 ) ;
V_126 ;
V_126 = F_67 ( V_106 , & V_40 ) ) {
F_64 ( V_106 , & V_40 ,
V_42 , & V_131 ,
V_43 , & V_132 ,
V_44 , & V_133 ,
- 1 ) ;
if( F_32 ( V_131 , V_51 ) == 0 )
{
V_134 = ( T_8 * ) F_60 ( sizeof( T_8 ) ) ;
V_134 -> V_38 = F_68 ( V_132 ) ;
V_134 -> V_39 = NULL ;
V_134 -> type = V_50 ;
V_134 -> V_135 = ( T_4 ) V_134 -> V_38 -> V_136 * 4 ;
V_130 = F_69 ( V_130 , V_134 ) ;
}
else if( F_32 ( V_131 , V_54 ) == 0 )
{
V_134 = ( T_8 * ) F_60 ( sizeof( T_8 ) ) ;
V_134 -> V_38 = F_68 ( V_132 ) ;
V_134 -> V_39 = F_70 () ;
F_71 ( V_133 , V_134 -> V_39 ) ;
V_134 -> type = V_53 ;
V_134 -> V_135 = 256 ;
V_130 = F_69 ( V_130 , V_134 ) ;
}
else if( F_32 ( V_131 , V_56 ) == 0 )
{
V_134 = ( T_8 * ) F_60 ( sizeof( T_8 ) ) ;
V_134 -> V_38 = F_68 ( V_132 ) ;
V_134 -> V_39 = NULL ;
V_134 -> type = V_55 ;
V_134 -> V_135 = 256 ;
V_130 = F_69 ( V_130 , V_134 ) ;
}
F_13 ( V_131 ) ;
F_13 ( V_133 ) ;
}
F_72 ( V_130 ) ;
if( ( V_125 == NULL ) || ( V_124 == NULL ) ) return;
V_129 = F_25 () ;
F_58 ( V_37 , V_129 ) ;
F_73 ( V_129 ) ;
F_30 ( V_129 ) ;
V_127 = F_27 ( V_125 ) ;
for( V_32 = 0 ; V_32 < V_127 ; V_32 ++ )
{
V_128 = ( T_1 * ) F_28 ( V_125 , V_32 ) ;
if( V_128 != NULL )
{
F_74 ( V_128 ) ;
F_75 ( V_128 ) ;
}
}
}
T_12
F_76 ( T_7 * V_125 )
{
T_10 V_127 = 0 ;
T_10 V_32 = 0 ;
T_10 V_137 = 0 ;
T_10 V_138 = 0 ;
T_1 * V_128 = NULL ;
T_7 * V_48 ;
T_7 * V_139 ;
T_7 * V_140 ;
T_12 V_141 = TRUE ;
T_12 V_142 = TRUE ;
if( V_125 == NULL )
return TRUE ;
V_127 = F_27 ( V_125 ) ;
V_48 = F_26 () ;
V_139 = F_77 () ;
V_138 = F_27 ( V_139 ) ;
V_141 &= F_78 ( V_48 , V_139 ) ;
for( V_32 = 0 ; V_32 < V_127 ; V_32 ++ )
{
V_128 = ( T_1 * ) F_28 ( V_125 , V_32 ) ;
V_140 = F_79 ( V_128 ) ;
V_137 += F_27 ( V_140 ) ;
V_142 &= F_78 ( V_48 , V_140 ) ;
}
if( V_137 != 0 )
V_141 &= V_142 ;
if( V_138 == 0 )
return TRUE ;
return V_141 ;
}
void
F_80 ( T_7 * V_125 )
{
T_10 V_127 = 0 ;
T_10 V_32 = 0 ;
if( V_125 == NULL ) return;
V_127 = F_27 ( V_125 ) ;
for( V_32 = 0 ; V_32 < V_127 ; V_32 ++ )
{
F_81 () ;
}
}
void
F_82 ( T_7 * V_130 , T_7 * V_143 )
{
T_10 V_127 = 0 ;
T_10 V_32 = 0 ;
T_1 * V_128 = NULL ;
T_7 * V_144 = NULL ;
if( ( V_130 == NULL ) || ( V_143 == NULL ) ) return;
V_127 = F_27 ( V_143 ) ;
F_83 ( V_130 ) ;
for( V_32 = 0 ; V_32 < V_127 ; V_32 ++ )
{
V_128 = ( T_1 * ) F_28 ( V_143 , V_32 ) ;
F_84 ( V_128 , V_144 ) ;
}
F_72 ( V_130 ) ;
}
void
F_85 ( T_2 * V_145 , T_12 V_146 )
{
T_2 * V_147 ,
* V_148 ,
* V_3 ,
* V_149 ,
* V_85 ,
* V_150 ,
* V_151 ,
* V_152 ,
* V_153 ;
if( V_145 == NULL )
return;
V_147 = V_145 ;
V_148 = F_2 ( F_3 ( V_147 ) , V_15 ) ;
V_149 = F_2 ( F_3 ( V_147 ) , V_17 ) ;
V_3 = F_2 ( F_3 ( V_147 ) , V_16 ) ;
V_85 = F_2 ( F_3 ( V_147 ) , V_18 ) ;
V_150 = F_2 ( F_3 ( V_147 ) , V_19 ) ;
V_152 = F_2 ( F_3 ( V_147 ) , V_21 ) ;
V_151 = F_2 ( F_3 ( V_147 ) , V_20 ) ;
V_153 = F_2 ( F_3 ( V_147 ) , V_22 ) ;
if( V_148 != NULL )
F_4 ( V_148 , V_146 ) ;
if( V_149 != NULL )
F_4 ( V_149 , V_146 ) ;
if( V_3 != NULL )
F_4 ( V_3 , V_146 ) ;
if( V_85 != NULL )
F_4 ( V_85 , V_146 ) ;
if( V_150 != NULL )
F_4 ( V_150 , V_146 ) ;
if( V_152 != NULL )
F_4 ( V_152 , V_146 ) ;
if( V_151 != NULL )
F_4 ( V_151 , V_146 ) ;
if( V_153 != NULL )
F_4 ( V_153 , V_146 ) ;
return;
}
