static T_1
F_1 ( T_2 * V_1 ,
T_3 (* F_2)( char * , T_4 , T_3 , void * ) ,
void * V_2 )
{
switch( V_1 -> V_3 ) {
case V_4 :
return F_3 ( V_1 , F_2 , V_2 ) ;
case V_5 :
return F_4 ( V_1 , F_2 , V_2 ) ;
case V_6 :
return F_5 ( V_1 , F_2 , V_2 ) ;
default :
F_6 () ;
return ( T_1 ) 0 ;
}
}
T_3
F_7 ( char * V_7 , T_4 V_8 , T_3 V_9 ,
void * V_2 )
{
T_5 * V_10 = ( T_5 * ) V_2 ;
T_6 * V_11 = F_8 ( F_9 ( V_10 ) ) ;
T_7 V_12 ;
T_4 V_13 ;
for ( V_13 = 0 ; V_13 < V_8 ; V_13 ++ ) {
if ( V_7 [ V_13 ] == '\n' || V_7 [ V_13 ] == '\r' )
continue;
if ( ! F_10 ( V_7 [ V_13 ] ) ) {
V_7 [ V_13 ] = '.' ;
}
}
F_11 ( V_11 , & V_12 ) ;
if ( V_9 ) {
F_12 ( V_11 , & V_12 , V_7 , ( V_14 ) V_8 ,
V_15 , NULL ) ;
} else {
F_12 ( V_11 , & V_12 , V_7 , ( V_14 ) V_8 ,
V_16 , NULL ) ;
}
return TRUE ;
}
static T_3
F_13 ( char * V_7 , T_4 V_8 , T_3 V_9 V_17 ,
void * V_2 )
{
T_8 * V_18 = ( T_8 * ) V_2 ;
T_4 V_13 ;
char * V_19 ;
for ( V_13 = 0 ; V_13 < V_8 ; V_13 ++ ) {
if ( V_7 [ V_13 ] == '\n' || V_7 [ V_13 ] == '\r' )
continue;
if ( ! F_10 ( V_7 [ V_13 ] ) ) {
V_7 [ V_13 ] = '.' ;
}
}
V_19 = ( char * ) F_14 ( V_8 + 1 ) ;
memcpy ( V_19 , V_7 , V_8 ) ;
V_19 [ V_8 ] = 0 ;
F_15 ( V_18 , 0 , V_19 ) ;
F_16 ( V_19 ) ;
return TRUE ;
}
static T_3
F_17 ( char * V_7 , T_4 V_8 , T_3 V_9 V_17 , void * V_2 )
{
T_9 * V_20 = ( T_9 * ) V_2 ;
T_4 V_21 ;
V_21 = fwrite ( V_7 , 1 , V_8 , V_20 ) ;
if ( V_21 != V_8 )
return FALSE ;
return TRUE ;
}
static void
F_18 ( T_5 * T_10 V_17 , T_11 V_22 )
{
T_2 * V_1 = ( T_2 * ) V_22 ;
if ( F_19 ( F_20 ( T_10 ) ) ) {
if ( T_10 == V_1 -> V_23 )
V_1 -> V_24 = V_25 ;
else if ( T_10 == V_1 -> V_26 )
V_1 -> V_24 = V_27 ;
else if ( T_10 == V_1 -> V_28 )
V_1 -> V_24 = V_29 ;
else if ( T_10 == V_1 -> V_30 )
V_1 -> V_24 = V_31 ;
else if ( T_10 == V_1 -> V_32 )
V_1 -> V_24 = V_33 ;
F_21 ( V_1 ) ;
}
}
void
F_21 ( T_2 * V_1 )
{
T_6 * V_11 ;
V_11 = F_8 ( F_9 ( V_1 -> V_10 ) ) ;
F_22 ( & V_34 , & V_35 . V_36 ) ;
F_22 ( & V_37 , & V_35 . V_38 ) ;
F_22 ( & V_39 , & V_35 . V_40 ) ;
F_22 ( & V_41 , & V_35 . V_42 ) ;
V_15 = F_23 ( V_11 , NULL , L_1 ,
& V_34 , L_2 ,
& V_37 , L_3 ,
F_24 () , NULL ) ;
V_16 = F_23 ( V_11 , NULL , L_1 ,
& V_39 , L_2 ,
& V_41 , L_3 ,
F_24 () , NULL ) ;
F_25 ( V_11 , L_4 , - 1 ) ;
F_1 ( V_1 , F_7 ,
V_1 -> V_10 ) ;
}
void
F_26 ( T_5 * T_10 V_17 , T_11 V_22 )
{
T_2 * V_1 = ( T_2 * ) V_22 ;
F_27 ( V_1 -> V_43 , FALSE ) ;
F_28 ( F_29 ( V_1 -> V_44 ) ,
V_1 -> V_45 ) ;
F_30 ( & V_46 , V_1 -> V_45 , FALSE ) ;
F_31 ( V_1 -> V_43 ) ;
return;
}
static void
F_32 ( T_5 * T_10 V_17 , T_11 V_22 )
{
T_2 * V_1 = ( T_2 * ) V_22 ;
T_5 * V_47 , * V_48 , * V_49 , * V_50 ;
T_5 * V_51 , * V_52 , * V_53 , * V_54 ;
if ( V_1 -> V_47 != NULL ) {
F_33 ( V_1 -> V_47 ) ;
return;
}
V_47 = F_34 ( L_5 ) ;
F_35 ( F_36 ( V_47 ) ,
F_36 ( V_1 -> V_43 ) ) ;
F_37 ( V_47 , 225 , - 1 ) ;
F_38 ( F_36 ( V_47 ) , TRUE ) ;
V_1 -> V_47 = V_47 ;
F_39 ( V_47 , L_6 , F_40 ( V_55 ) ,
V_1 ) ;
F_39 ( V_47 , L_7 , F_40 ( V_56 ) ,
NULL ) ;
V_48 = F_41 ( V_57 , 3 , FALSE ) ;
F_42 ( F_43 ( V_48 ) , 5 ) ;
F_44 ( F_43 ( V_47 ) , V_48 ) ;
V_51 = F_41 ( V_58 , 3 , FALSE ) ;
F_45 ( F_46 ( V_48 ) , V_51 , TRUE , TRUE , 0 ) ;
F_47 ( V_51 ) ;
V_50 = F_48 ( L_8 ) ;
F_45 ( F_46 ( V_51 ) , V_50 , FALSE , FALSE , 0 ) ;
F_47 ( V_50 ) ;
V_52 = F_49 () ;
F_45 ( F_46 ( V_51 ) , V_52 , FALSE , FALSE , 0 ) ;
F_50 ( V_52 , L_9 ) ;
F_47 ( V_52 ) ;
V_49 = F_51 ( V_59 , V_60 ,
NULL ) ;
F_45 ( F_46 ( V_48 ) , V_49 , TRUE , TRUE , 0 ) ;
V_53 = ( T_5 * ) F_52 ( F_53 ( V_49 ) , V_59 ) ;
V_54 = ( T_5 * ) F_52 ( F_53 ( V_49 ) , V_60 ) ;
F_39 ( V_53 , L_10 , F_40 ( V_61 ) , V_1 ) ;
F_54 ( F_53 ( V_53 ) , L_11 , V_52 ) ;
F_55 ( V_47 , V_54 ,
V_62 ) ;
F_56 ( V_52 , V_53 ) ;
F_57 ( V_47 ) ;
F_58 ( V_47 ) ;
}
static void
V_61 ( T_5 * T_10 , T_11 V_22 )
{
T_3 V_63 ;
const T_12 * V_64 ;
T_2 * V_1 = ( T_2 * ) V_22 ;
T_6 * V_7 ;
T_7 V_12 , V_65 , V_66 ;
T_13 * V_67 ;
T_5 * V_68 ;
V_68 = ( T_5 * ) F_52 ( F_53 ( T_10 ) , L_11 ) ;
V_64 = F_59 ( F_29 ( V_68 ) ) ;
V_7 = F_8 ( F_9 ( V_1 -> V_10 ) ) ;
F_60 ( V_7 , & V_12 ) ;
V_67 = F_61 ( V_7 , L_12 ) ;
if( V_67 )
F_62 ( V_7 , & V_12 , V_67 ) ;
V_63 = F_63 ( & V_12 , V_64 , ( V_69 ) 0 ,
& V_65 ,
& V_66 ,
NULL ) ;
if( V_63 ) {
F_64 ( V_7 , & V_65 , & V_66 ) ;
V_67 = F_65 ( V_7 ,
L_12 ,
& V_66 , FALSE ) ;
F_66 ( F_9 ( V_1 -> V_10 ) , V_67 ) ;
} else {
F_67 ( V_70 , V_71 ,
L_13
L_14
L_15 , F_68 () ,
F_69 () ) ;
if( V_67 )
F_70 ( V_7 , V_67 ) ;
}
}
static void
V_55 ( T_5 * T_14 V_17 , T_11 V_22 )
{
T_2 * V_1 = ( T_2 * ) V_22 ;
V_1 -> V_47 = NULL ;
}
static void
F_71 ( T_5 * T_10 V_17 , T_11 V_22 )
{
T_8 * V_18 ;
T_3 V_72 ;
const char * V_73 ;
T_2 * V_1 = ( T_2 * ) V_22 ;
#ifdef F_72
T_3 V_74 = FALSE ;
int V_75 ;
char * V_76 ;
#endif
switch ( V_35 . V_77 ) {
case V_78 :
#ifdef F_72
V_74 = TRUE ;
V_75 = F_73 ( & V_76 , L_16 ) ;
if( V_75 == - 1 ) {
F_67 ( V_79 , V_71 ,
L_17 , V_76 ) ;
return;
}
F_74 ( V_75 ) ;
F_75 ( V_76 ) ;
V_73 = V_76 ;
V_72 = TRUE ;
#else
V_73 = V_35 . V_80 ;
V_72 = FALSE ;
#endif
break;
case V_81 :
V_73 = V_35 . V_82 ;
V_72 = TRUE ;
break;
default:
F_67 ( V_79 , V_71 ,
L_18
L_19 ) ;
return;
}
switch ( V_35 . V_83 ) {
case V_84 :
V_18 = F_76 ( V_72 , V_73 ) ;
break;
case V_85 :
V_18 = F_77 ( V_72 , V_73 ) ;
break;
default:
F_6 () ;
V_18 = NULL ;
}
if ( V_18 == NULL ) {
if ( V_72 ) {
F_78 ( V_73 , V_86 , TRUE ) ;
} else {
F_67 ( V_79 , V_71 ,
L_20 ,
V_35 . V_80 ) ;
}
return;
}
if ( ! F_79 ( V_18 , V_46 . V_87 , F_80 () ) )
goto V_88;
switch ( F_1 ( V_1 , F_13 , V_18 ) ) {
case V_89 :
break;
case V_90 :
case V_91 :
F_81 ( V_18 ) ;
return;
case V_92 :
goto V_88;
}
if ( ! F_82 ( V_18 ) )
goto V_88;
if ( ! F_81 ( V_18 ) ) {
if ( V_72 ) {
F_83 ( V_73 , V_86 ) ;
} else {
F_67 ( V_79 , V_71 ,
L_21 ) ;
}
}
#ifdef F_72
if ( V_74 ) {
F_84 ( V_73 ) ;
F_85 ( V_73 ) ;
}
#endif
return;
V_88:
if ( V_72 ) {
F_83 ( V_73 , V_86 ) ;
} else {
F_67 ( V_79 , V_71 ,
L_22 ,
F_86 ( V_86 ) ) ;
}
F_81 ( V_18 ) ;
#ifdef F_72
if ( V_74 ) {
F_85 ( V_73 ) ;
}
#endif
}
static char *
F_87 ( T_5 * V_93 )
{
T_5 * V_94 ;
char * V_95 ;
V_94 = F_88 ( L_23 ,
F_36 ( V_93 ) ,
V_96 ) ;
V_95 = F_89 ( V_94 ) ;
if ( V_95 == NULL ) {
return NULL ;
}
F_31 ( V_94 ) ;
return V_95 ;
}
static T_3
F_90 ( T_12 * V_97 , T_2 * V_1 )
{
T_9 * V_20 ;
T_8 * V_18 ;
if ( V_1 -> V_24 == V_33 ) {
V_20 = F_91 ( V_97 , L_24 ) ;
} else {
V_20 = F_91 ( V_97 , L_25 ) ;
}
if ( V_20 == NULL ) {
F_78 ( V_97 , V_86 , TRUE ) ;
return FALSE ;
}
if ( V_1 -> V_24 == V_33 ) {
switch ( F_1 ( V_1 , F_17 , V_20 ) ) {
case V_89 :
if ( fclose ( V_20 ) == V_98 ) {
F_83 ( V_97 , V_86 ) ;
return FALSE ;
}
break;
case V_90 :
case V_91 :
fclose ( V_20 ) ;
return FALSE ;
case V_92 :
F_83 ( V_97 , V_86 ) ;
fclose ( V_20 ) ;
return FALSE ;
}
} else {
V_18 = F_92 ( V_20 ) ;
switch ( F_1 ( V_1 , F_13 , V_18 ) ) {
case V_89 :
if ( ! F_81 ( V_18 ) ) {
F_83 ( V_97 , V_86 ) ;
return FALSE ;
}
break;
case V_90 :
case V_91 :
F_81 ( V_18 ) ;
return FALSE ;
case V_92 :
F_83 ( V_97 , V_86 ) ;
F_81 ( V_18 ) ;
return FALSE ;
}
}
return TRUE ;
}
static void
F_93 ( T_5 * T_10 , T_11 V_22 )
{
T_5 * V_93 = F_94 ( T_10 ) ;
T_2 * V_1 = ( T_2 * ) V_22 ;
char * V_95 ;
for (; ; ) {
V_95 = F_87 ( V_93 ) ;
if ( V_95 == NULL ) {
break;
}
if ( F_90 ( V_95 , V_1 ) ) {
F_16 ( V_95 ) ;
break;
}
F_16 ( V_95 ) ;
}
}
static void
F_95 ( T_5 * T_10 , T_11 V_22 )
{
T_2 * V_1 = ( T_2 * ) V_22 ;
switch( F_96 ( F_97 ( T_10 ) ) ) {
case 0 :
V_1 -> V_99 = V_100 ;
F_21 ( V_1 ) ;
break;
case 1 :
V_1 -> V_99 = V_101 ;
F_21 ( V_1 ) ;
break;
case 2 :
V_1 -> V_99 = V_102 ;
F_21 ( V_1 ) ;
break;
}
}
static void
F_98 ( T_2 * V_1 )
{
V_103 = F_99 ( V_103 , V_1 ) ;
}
static void
F_100 ( T_2 * V_1 )
{
V_103 = F_101 ( V_103 , V_1 ) ;
}
void
F_102 ( const T_12 * V_104 , T_2 * V_1 ,
T_12 * V_105 ,
T_12 * V_106 , T_12 * V_107 )
{
T_5 * V_43 , * V_108 , * V_109 , * V_10 ;
T_5 * V_110 , * V_111 , * V_112 , * V_113 ;
T_5 * V_114 , * V_115 , * V_116 ;
T_5 * V_117 ;
T_15 V_118 ;
V_1 -> V_24 = V_33 ;
V_43 = F_34 ( V_104 ) ;
V_1 -> V_43 = V_43 ;
F_103 ( V_43 , V_104 ) ;
F_104 ( F_36 ( V_43 ) , V_119 , V_120 ) ;
F_42 ( F_43 ( V_43 ) , 6 ) ;
V_108 = F_41 ( V_57 , 6 , FALSE ) ;
F_44 ( F_43 ( V_43 ) , V_108 ) ;
if ( V_121 ) {
V_114 = F_105 ( L_26 ) ;
} else {
V_114 = F_105 ( L_27 ) ;
}
F_45 ( F_46 ( V_108 ) , V_114 , TRUE , TRUE , 0 ) ;
F_47 ( V_114 ) ;
V_115 = F_41 ( V_57 , 6 , FALSE ) ;
F_42 ( F_43 ( V_115 ) , 6 ) ;
F_44 ( F_43 ( V_114 ) , V_115 ) ;
V_109 = F_106 ( NULL , NULL ) ;
F_107 ( F_108 ( V_109 ) , V_122 ) ;
F_45 ( F_46 ( V_115 ) , V_109 , TRUE , TRUE , 0 ) ;
V_10 = F_109 () ;
F_110 ( F_9 ( V_10 ) , FALSE ) ;
F_111 ( F_9 ( V_10 ) , V_123 ) ;
F_44 ( F_43 ( V_109 ) , V_10 ) ;
V_1 -> V_10 = V_10 ;
V_116 = F_41 ( V_58 , 1 , FALSE ) ;
F_45 ( F_46 ( V_115 ) , V_116 , FALSE , FALSE , 0 ) ;
V_117 = F_112 () ;
F_113 ( F_114 ( V_117 ) , V_105 ) ;
V_1 -> V_99 = V_100 ;
F_113 ( F_114 ( V_117 ) , V_107 ) ;
F_113 ( F_114 ( V_117 ) , V_106 ) ;
F_115 ( F_97 ( V_117 ) , 0 ) ;
F_39 ( V_117 , L_28 , F_40 ( F_95 ) , V_1 ) ;
F_50 ( V_117 , L_29 ) ;
F_45 ( F_46 ( V_116 ) , V_117 , TRUE , TRUE , 0 ) ;
V_110 = F_41 ( V_58 , 1 , FALSE ) ;
F_45 ( F_46 ( V_115 ) , V_110 , FALSE , FALSE , 0 ) ;
V_112 = F_116 ( V_59 ) ;
F_39 ( V_112 , L_10 , F_40 ( F_32 ) , V_1 ) ;
F_50 ( V_112 , L_30 ) ;
F_45 ( F_46 ( V_110 ) , V_112 , TRUE , TRUE , 0 ) ;
V_112 = F_116 ( V_124 ) ;
F_39 ( V_112 , L_10 , F_40 ( F_93 ) , V_1 ) ;
F_50 ( V_112 , L_31 ) ;
F_45 ( F_46 ( V_110 ) , V_112 , TRUE , TRUE , 0 ) ;
V_112 = F_116 ( V_125 ) ;
F_39 ( V_112 , L_10 , F_40 ( F_71 ) , V_1 ) ;
F_50 ( V_112 , L_32 ) ;
F_45 ( F_46 ( V_110 ) , V_112 , TRUE , TRUE , 0 ) ;
F_117 ( & V_118 ) ;
V_1 -> V_126 = V_118 . V_126 ;
V_113 = F_118 ( NULL , L_33 ) ;
F_50 ( V_113 , L_34 ) ;
F_119 ( F_20 ( V_113 ) , F_120 ( V_31 ) ) ;
F_45 ( F_46 ( V_110 ) , V_113 , TRUE , TRUE , 0 ) ;
F_39 ( V_113 , L_35 , F_40 ( F_18 ) , V_1 ) ;
V_1 -> V_30 = V_113 ;
V_113 = F_118 ( F_121 ( F_122 ( V_113 ) ) ,
L_36 ) ;
F_50 ( V_113 , L_37 ) ;
F_119 ( F_20 ( V_113 ) , F_120 ( V_25 ) ) ;
F_45 ( F_46 ( V_110 ) , V_113 , TRUE , TRUE , 0 ) ;
F_39 ( V_113 , L_35 , F_40 ( F_18 ) , V_1 ) ;
V_1 -> V_23 = V_113 ;
V_113 = F_118 ( F_121 ( F_122 ( V_113 ) ) ,
L_38 ) ;
F_50 ( V_113 , L_39 ) ;
F_119 ( F_20 ( V_113 ) , F_120 ( V_27 ) ) ;
F_45 ( F_46 ( V_110 ) , V_113 , TRUE , TRUE , 0 ) ;
F_39 ( V_113 , L_35 , F_40 ( F_18 ) , V_1 ) ;
V_1 -> V_26 = V_113 ;
V_113 = F_118 ( F_121 ( F_122 ( V_113 ) ) ,
L_40 ) ;
F_50 ( V_113 , L_41 ) ;
F_119 ( F_20 ( V_113 ) , F_120 ( V_29 ) ) ;
F_45 ( F_46 ( V_110 ) , V_113 , TRUE , TRUE , 0 ) ;
F_39 ( V_113 , L_35 , F_40 ( F_18 ) , V_1 ) ;
V_1 -> V_28 = V_113 ;
V_113 = F_118 ( F_121 ( F_122 ( V_113 ) ) ,
L_42 ) ;
F_50 ( V_113 ,
L_43
L_44
L_45 ) ;
F_119 ( F_20 ( V_113 ) , F_120 ( V_33 ) ) ;
F_45 ( F_46 ( V_110 ) , V_113 , TRUE , TRUE , 0 ) ;
F_39 ( V_113 , L_35 , F_40 ( F_18 ) , V_1 ) ;
V_1 -> V_32 = V_113 ;
V_111 = F_51 ( V_127 , V_128 , V_129 ,
NULL ) ;
F_45 ( F_46 ( V_108 ) , V_111 , FALSE , FALSE , 5 ) ;
V_112 = ( T_5 * ) F_52 ( F_53 ( V_111 ) , V_127 ) ;
F_50 ( V_112 , L_46 ) ;
F_39 ( V_112 , L_10 , F_40 ( F_26 ) , V_1 ) ;
V_112 = ( T_5 * ) F_52 ( F_53 ( V_111 ) , V_128 ) ;
F_55 ( V_43 , V_112 , V_62 ) ;
F_50 ( V_112 , L_47 ) ;
F_123 ( V_112 ) ;
V_112 = ( T_5 * ) F_52 ( F_53 ( V_111 ) , V_129 ) ;
F_39 ( V_112 , L_10 , F_40 ( V_130 ) , ( T_11 ) V_131 ) ;
F_54 ( F_53 ( V_43 ) , V_132 , V_1 ) ;
F_21 ( V_1 ) ;
F_98 ( V_1 ) ;
F_39 ( V_43 , L_7 , F_40 ( V_56 ) , NULL ) ;
F_39 ( V_43 , L_6 , F_40 ( V_133 ) , NULL ) ;
F_57 ( V_43 ) ;
F_58 ( V_43 ) ;
}
static void
V_133 ( T_5 * T_10 , T_11 V_22 V_17 )
{
T_2 * V_1 ;
T_16 * V_134 ;
T_17 * V_135 ;
int V_13 ;
V_1 = ( T_2 * ) F_52 ( F_53 ( T_10 ) , V_132 ) ;
switch( V_1 -> V_3 ) {
case V_4 :
V_13 = F_75 ( V_1 -> V_136 ) ;
if( V_13 != 0 ) {
F_124 ( L_48 ,
V_1 -> V_136 , F_86 ( V_86 ) , V_86 ) ;
}
break;
case V_5 :
for( V_135 = V_1 -> V_137 ; V_135 ; V_135 = F_125 ( V_135 ) )
if( V_135 -> V_22 ) {
V_134 = ( T_16 * ) V_135 -> V_22 ;
if( V_134 -> V_22 )
F_126 ( V_134 -> V_22 , TRUE ) ;
F_16 ( V_134 ) ;
}
F_127 ( V_1 -> V_137 ) ;
break;
case V_6 :
for ( V_135 = V_1 -> V_137 ; V_135 ; V_135 = F_125 ( V_135 ) )
if ( V_135 -> V_22 )
{
F_16 ( V_135 -> V_22 ) ;
V_135 -> V_22 = NULL ;
}
F_127 ( V_1 -> V_137 ) ;
break;
}
F_16 ( V_1 -> V_136 ) ;
F_16 ( V_1 -> V_45 ) ;
F_16 ( ( T_11 ) V_1 -> V_138 . V_22 ) ;
F_100 ( V_1 ) ;
F_16 ( V_1 ) ;
F_128 ( T_10 ) ;
}
T_1
F_129 ( T_2 * V_1 ,
T_3 (* F_2)( char * , T_4 , T_3 , void * ) ,
char * V_7 , T_4 V_8 , T_3 V_9 , void * V_2 ,
T_18 * V_139 , T_18 * V_140 ,
T_18 * V_141 )
{
T_12 V_142 [ 256 ] ;
T_18 V_143 ;
static const T_12 V_144 [ 16 ] = { '0' , '1' , '2' , '3' , '4' , '5' , '6' , '7' , '8' , '9' , 'a' , 'b' , 'c' , 'd' , 'e' , 'f' } ;
switch ( V_1 -> V_24 ) {
case V_25 :
F_130 ( V_7 , ( V_145 ) V_8 ) ;
if ( ! (* F_2) ( V_7 , V_8 , V_9 , V_2 ) )
return V_92 ;
break;
case V_31 :
if ( ! (* F_2) ( V_7 , V_8 , V_9 , V_2 ) )
return V_92 ;
break;
case V_33 :
if ( ! (* F_2) ( V_7 , V_8 , V_9 , V_2 ) )
return V_92 ;
break;
case V_27 :
V_143 = 0 ;
while ( V_143 < V_8 ) {
T_12 V_146 [ 256 ] ;
int V_13 ;
T_12 * V_135 = V_146 , * V_147 ;
if ( V_9 && V_1 -> V_99 == V_100 ) {
memset ( V_135 , ' ' , 4 ) ;
V_135 += 4 ;
}
V_135 += F_131 ( V_135 , 20 , L_49 , * V_139 ) ;
V_147 = V_135 + 49 ;
for ( V_13 = 0 ; V_13 < 16 && V_143 + V_13 < V_8 ; V_13 ++ ) {
* V_135 ++ =
V_144 [ ( V_7 [ V_143 + V_13 ] & 0xf0 ) >> 4 ] ;
* V_135 ++ =
V_144 [ V_7 [ V_143 + V_13 ] & 0x0f ] ;
* V_135 ++ = ' ' ;
if ( V_13 == 7 )
* V_135 ++ = ' ' ;
}
while ( V_135 < V_147 )
* V_135 ++ = ' ' ;
for ( V_13 = 0 ; V_13 < 16 && V_143 + V_13 < V_8 ; V_13 ++ ) {
* V_135 ++ =
( F_10 ( V_7 [ V_143 + V_13 ] ) ?
V_7 [ V_143 + V_13 ] : '.' ) ;
if ( V_13 == 7 ) {
* V_135 ++ = ' ' ;
}
}
V_143 += V_13 ;
( * V_139 ) += V_13 ;
* V_135 ++ = '\n' ;
* V_135 = 0 ;
if ( ! (* F_2) ( V_146 , strlen ( V_146 ) , V_9 , V_2 ) )
return V_92 ;
}
break;
case V_29 :
V_143 = 0 ;
F_131 ( V_142 , sizeof( V_142 ) , L_50 ,
V_9 ? 1 : 0 ,
V_9 ? ( * V_140 ) ++ : ( * V_141 ) ++ ) ;
if ( ! (* F_2) ( V_142 , strlen ( V_142 ) , V_9 , V_2 ) )
return V_92 ;
while ( V_143 < V_8 ) {
T_12 V_146 [ 256 ] ;
int V_13 , V_135 ;
V_135 = 0 ;
for ( V_13 = 0 ; V_13 < 8 && V_143 + V_13 < V_8 ; V_13 ++ ) {
V_146 [ V_135 ++ ] = '0' ;
V_146 [ V_135 ++ ] = 'x' ;
V_146 [ V_135 ++ ] = V_144 [ ( V_7 [ V_143 + V_13 ] & 0xf0 ) >> 4 ] ;
V_146 [ V_135 ++ ] = V_144 [ V_7 [ V_143 + V_13 ] & 0x0f ] ;
if ( V_143 + V_13 + 1 < V_8 )
V_146 [ V_135 ++ ] = ',' ;
V_146 [ V_135 ++ ] = ' ' ;
}
if ( V_143 + V_13 == V_8 ) {
V_146 [ V_135 ++ ] = '}' ;
V_146 [ V_135 ++ ] = ';' ;
}
V_143 += V_13 ;
( * V_139 ) += V_13 ;
V_146 [ V_135 ++ ] = '\n' ;
V_146 [ V_135 ] = 0 ;
if ( ! (* F_2) ( V_146 , strlen ( V_146 ) , V_9 , V_2 ) )
return V_92 ;
}
break;
case V_148 :
F_6 () ;
break;
}
return V_89 ;
}
