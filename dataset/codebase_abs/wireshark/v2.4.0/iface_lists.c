T_1
F_1 ( const void * V_1 , const void * V_2 )
{
const T_2 * V_3 = ( const T_2 * ) V_1 , * V_4 = ( const T_2 * ) V_2 ;
if ( V_3 != NULL && V_3 -> V_5 != NULL &&
V_4 != NULL && V_4 -> V_5 != NULL ) {
return F_2 ( V_3 -> V_5 , V_4 -> V_5 ) ;
} else {
return 0 ;
}
}
static T_3
F_3 ( T_4 * V_6 )
{
T_5 V_7 ;
T_6 V_8 ;
for ( V_8 = 0 ; V_8 < V_9 . V_10 -> V_11 ; V_8 ++ ) {
V_7 = F_4 ( V_9 . V_10 , T_5 , V_8 ) ;
if ( strcmp ( V_7 . V_12 , V_6 -> V_12 ) != 0 ) {
continue;
}
#if F_5 ( V_13 )
V_6 -> V_14 = V_7 . V_15 ;
V_6 -> V_16 = V_7 . V_17 ;
#endif
V_6 -> V_18 = V_7 . V_19 ;
V_6 -> V_20 = V_7 . V_20 ;
V_6 -> V_21 = V_7 . V_21 ;
F_6 ( V_6 -> V_22 ) ;
V_6 -> V_22 = F_7 ( V_7 . V_22 ) ;
if ( V_7 . V_23 != - 1 ) {
V_6 -> V_24 = V_7 . V_23 ;
}
return TRUE ;
}
return FALSE ;
}
void
F_8 ( void (* F_9)( void ) )
{
T_7 * V_25 , * V_26 , * V_27 ;
T_2 * V_28 , V_29 ;
T_8 * V_30 ;
T_9 * V_31 = NULL ;
T_1 V_32 ;
T_3 V_17 ;
T_10 * V_33 ;
int V_34 = 0 , V_8 ;
T_6 V_35 = 0 , V_36 ;
T_11 * V_37 , * V_38 ;
T_12 * V_39 = NULL ;
T_13 * V_40 ;
T_4 V_6 ;
T_14 * V_41 ;
T_5 V_7 ;
T_3 V_42 = FALSE ;
static T_3 V_43 = FALSE ;
T_15 * V_44 ;
if ( V_43 ) {
return;
}
V_43 = TRUE ;
V_44 = F_10 ( V_45 , V_46 , F_6 , NULL ) ;
if ( V_9 . V_47 -> V_11 > 0 ) {
for ( V_8 = ( int ) V_9 . V_47 -> V_11 - 1 ; V_8 >= 0 ; V_8 -- ) {
V_6 = F_4 ( V_9 . V_47 , T_4 , V_8 ) ;
if ( V_6 . V_48 && V_6 . type != V_49 && V_6 . type != V_50 ) {
V_9 . V_47 = F_11 ( V_9 . V_47 , V_8 ) ;
if ( V_6 . V_51 ) {
T_8 * V_52 = F_7 ( V_6 . V_12 ) ;
F_12 ( V_44 , V_52 , V_52 ) ;
V_9 . V_53 -- ;
}
F_13 ( & V_6 ) ;
}
}
}
F_6 ( V_9 . V_54 ) ;
V_27 = F_14 ( & V_9 . V_55 ,
& V_9 . V_54 ,
F_9 ) ;
V_35 = 0 ;
for ( V_25 = V_27 ; V_25 != NULL ; V_25 = F_15 ( V_25 ) ) {
memset ( & V_6 , 0 , sizeof( V_6 ) ) ;
V_28 = ( T_2 * ) V_25 -> V_56 ;
V_41 = F_16 ( L_1 ) ;
V_34 = 0 ;
if ( strstr ( V_28 -> V_12 , L_2 ) ) {
continue;
}
V_6 . V_12 = F_7 ( V_28 -> V_12 ) ;
if ( V_28 -> V_5 != NULL ) {
V_6 . V_5 = F_7 ( V_28 -> V_5 ) ;
} else {
V_6 . V_5 = NULL ;
}
V_6 . V_57 = FALSE ;
V_6 . V_58 = FALSE ;
memset ( & V_29 , 0 , sizeof( V_29 ) ) ;
V_29 . V_12 = F_7 ( V_28 -> V_12 ) ;
V_29 . V_5 = F_7 ( V_28 -> V_5 ) ;
V_29 . V_59 = F_7 ( V_28 -> V_59 ) ;
V_29 . V_60 = V_28 -> V_60 ;
V_29 . type = V_28 -> type ;
#ifdef F_17
V_29 . V_61 = F_7 ( V_28 -> V_61 ) ;
#endif
V_30 = F_18 ( V_28 -> V_12 ) ;
V_6 . V_62 = F_19 ( V_30 , V_28 ) ;
F_6 ( V_30 ) ;
V_6 . V_51 = FALSE ;
if ( F_20 ( V_28 -> V_12 ) ) {
V_6 . V_57 = TRUE ;
}
V_6 . type = V_28 -> type ;
V_17 = F_21 ( V_28 -> V_12 ) ;
V_31 = F_22 ( V_28 -> V_12 , V_17 , NULL , NULL , F_9 ) ;
for (; ( V_33 = F_23 ( V_28 -> V_63 , V_34 ) ) != NULL ; V_34 ++ ) {
V_38 = ( T_11 * ) F_24 ( sizeof( T_11 ) ) ;
if ( V_34 != 0 ) {
F_25 ( V_41 , L_3 ) ;
}
V_37 = ( T_11 * ) V_33 -> V_56 ;
if ( V_37 ) {
T_16 V_64 ;
char * V_65 = NULL ;
V_38 -> V_66 = V_37 -> V_66 ;
switch ( V_37 -> V_66 ) {
case V_67 :
V_38 -> V_37 . V_68 = V_37 -> V_37 . V_68 ;
F_26 ( & V_64 , V_69 , 4 , & V_37 -> V_37 . V_68 ) ;
V_65 = F_27 ( NULL , & V_64 ) ;
F_25 ( V_41 , V_65 ) ;
break;
case V_70 :
memcpy ( V_38 -> V_37 . V_71 , V_37 -> V_37 . V_71 , sizeof( V_37 -> V_37 ) ) ;
F_26 ( & V_64 , V_72 , 16 , V_37 -> V_37 . V_71 ) ;
V_65 = F_27 ( NULL , & V_64 ) ;
F_25 ( V_41 , V_65 ) ;
break;
default:
break;
}
F_28 ( NULL , V_65 ) ;
} else {
F_6 ( V_38 ) ;
V_38 = NULL ;
}
if ( V_38 ) {
V_29 . V_63 = F_29 ( V_29 . V_63 , V_38 ) ;
}
}
#ifdef F_30
V_6 . V_48 = TRUE ;
V_6 . V_73 . V_74 = V_75 ;
V_6 . V_73 . V_76 . V_77 = F_7 ( V_9 . V_78 . V_77 ) ;
V_6 . V_73 . V_76 . V_79 = F_7 ( V_9 . V_78 . V_79 ) ;
V_6 . V_73 . V_76 . V_80 = V_9 . V_78 . V_80 ;
V_6 . V_73 . V_76 . V_81 = F_7 ( V_9 . V_78 . V_81 ) ;
V_6 . V_73 . V_76 . V_82 = F_7 ( V_9 . V_78 . V_82 ) ;
V_6 . V_73 . V_76 . V_83 = V_9 . V_78 . V_83 ;
V_6 . V_73 . V_76 . V_84 = V_9 . V_78 . V_84 ;
V_6 . V_73 . V_76 . V_85 = V_9 . V_78 . V_85 ;
#endif
#ifdef F_31
V_6 . V_73 . V_86 = V_9 . V_78 . V_86 ;
V_6 . V_73 . V_87 = V_9 . V_78 . V_87 ;
#endif
V_32 = 0 ;
V_6 . V_88 = NULL ;
if ( V_31 != NULL ) {
#if F_5 ( V_13 )
V_6 . V_16 = V_17 ;
V_6 . V_89 = V_31 -> V_90 ;
#endif
for ( V_26 = V_31 -> V_91 ; V_26 != NULL ; V_26 = F_15 ( V_26 ) ) {
V_40 = ( T_13 * ) V_26 -> V_56 ;
V_39 = ( T_12 * ) F_32 ( sizeof( T_12 ) ) ;
if ( V_40 -> V_92 != NULL ) {
V_39 -> V_93 = V_40 -> V_93 ;
V_39 -> V_12 = F_7 ( V_40 -> V_92 ) ;
} else {
V_39 -> V_93 = - 1 ;
V_39 -> V_12 = F_33 ( L_4 , V_40 -> V_12 ) ;
}
V_6 . V_88 = F_34 ( V_6 . V_88 , V_39 ) ;
V_32 ++ ;
}
F_35 ( & V_6 , V_9 . V_78 . V_23 ) ;
} else {
#if F_5 ( V_13 )
V_6 . V_16 = FALSE ;
V_6 . V_89 = FALSE ;
#endif
V_6 . V_24 = - 1 ;
}
V_6 . V_94 = F_7 ( V_41 -> V_95 ) ;
V_6 . V_96 = V_34 ;
V_6 . V_48 = TRUE ;
V_6 . V_28 = V_29 ;
V_6 . V_97 = 0 ;
if ( ! F_36 ( V_28 -> V_12 , & V_6 . V_18 ) ) {
V_6 . V_18 = V_9 . V_78 . V_19 ;
}
if ( ! F_37 ( V_28 -> V_12 , & V_6 . V_20 ,
& V_6 . V_21 ) ) {
V_6 . V_20 = V_9 . V_78 . V_20 ;
V_6 . V_21 = V_9 . V_78 . V_21 ;
}
V_6 . V_22 = F_7 ( V_9 . V_78 . V_22 ) ;
#ifdef F_38
if ( ( V_6 . V_14 = F_39 ( V_28 -> V_12 ) ) == - 1 ) {
V_6 . V_14 = V_9 . V_78 . V_15 ;
}
#endif
T_3 V_51 = F_3 ( & V_6 ) ;
if ( ! V_6 . V_51 && ( V_51 || F_40 ( V_44 , V_6 . V_12 ) ) ) {
V_6 . V_51 = TRUE ;
V_9 . V_53 ++ ;
}
#ifdef F_17
V_6 . V_98 = NULL ;
#endif
if ( V_9 . V_47 -> V_11 <= V_35 ) {
F_41 ( V_9 . V_47 , V_6 ) ;
V_35 = V_9 . V_47 -> V_11 ;
} else {
F_42 ( V_9 . V_47 , V_35 , V_6 ) ;
}
if ( V_31 != NULL ) {
F_43 ( V_31 ) ;
}
F_44 ( V_41 , TRUE ) ;
V_35 ++ ;
}
F_45 ( V_27 ) ;
for ( V_36 = 0 ; V_36 < V_9 . V_10 -> V_11 ; V_36 ++ ) {
V_7 = F_4 ( V_9 . V_10 , T_5 , V_36 ) ;
V_42 = FALSE ;
for ( V_8 = 0 ; V_8 < ( int ) V_9 . V_47 -> V_11 ; V_8 ++ ) {
V_6 = F_4 ( V_9 . V_47 , T_4 , V_8 ) ;
if ( strcmp ( V_6 . V_12 , V_7 . V_12 ) == 0 ) {
V_42 = TRUE ;
break;
}
}
if ( ! V_42 ) {
memset ( & V_6 , 0 , sizeof( V_6 ) ) ;
V_6 . V_12 = F_7 ( V_7 . V_12 ) ;
V_6 . V_62 = V_7 . V_30 ?
F_33 ( L_5 , V_6 . V_12 , V_7 . V_30 ) :
F_7 ( V_6 . V_12 ) ;
V_6 . V_57 = FALSE ;
V_6 . V_51 = TRUE ;
V_6 . type = V_7 . V_99 ;
#ifdef F_38
V_6 . V_14 = V_7 . V_15 ;
#endif
#if F_5 ( V_13 )
V_6 . V_16 = V_7 . V_17 ;
V_6 . V_89 = FALSE ;
#endif
V_6 . V_18 = V_7 . V_19 ;
V_6 . V_20 = V_7 . V_20 ;
V_6 . V_21 = V_7 . V_21 ;
V_6 . V_22 = F_7 ( V_7 . V_22 ) ;
V_6 . V_24 = V_7 . V_23 ;
V_6 . V_94 = NULL ;
V_6 . V_96 = 0 ;
V_6 . V_97 = 0 ;
V_6 . V_88 = NULL ;
V_6 . V_48 = TRUE ;
V_6 . V_58 = FALSE ;
V_6 . V_28 . V_12 = F_7 ( V_7 . V_12 ) ;
V_6 . V_28 . V_5 = NULL ;
V_6 . V_28 . V_59 = F_7 ( V_7 . V_30 ) ;
V_6 . V_28 . V_63 = NULL ;
V_6 . V_28 . V_60 = FALSE ;
#ifdef F_17
V_6 . V_28 . V_61 = F_7 ( V_7 . V_61 ) ;
#endif
F_41 ( V_9 . V_47 , V_6 ) ;
V_9 . V_53 ++ ;
}
}
F_46 ( V_44 ) ;
V_43 = FALSE ;
}
void
F_47 ( void (* F_9)( void ) )
{
T_17 V_100 ;
T_17 V_101 ;
float V_102 ;
static T_3 V_103 = FALSE ;
F_48 ( & V_100 ) ;
F_49 ( V_104 , V_105 , L_6 ) ;
if ( ! V_103 ) {
F_8 ( F_9 ) ;
V_103 = TRUE ;
}
F_48 ( & V_101 ) ;
V_102 = ( float ) ( ( V_101 . V_106 - V_100 . V_106 ) +
( ( V_101 . V_107 - V_100 . V_107 ) / 1e6 ) ) ;
F_49 ( V_104 , V_105 , L_7 , V_102 ) ;
}
void
F_50 ( T_8 * V_108 )
{
T_8 * V_109 ;
T_6 V_8 ;
T_4 V_6 ;
T_3 V_42 = FALSE ;
T_7 * V_110 = NULL , * V_111 ;
if ( V_108 != NULL ) {
for ( V_109 = strtok ( V_108 , L_8 ) ; V_109 ; V_109 = strtok ( NULL , L_8 ) ) {
V_110 = F_34 ( V_110 , V_109 ) ;
}
}
for ( V_8 = 0 ; V_8 < V_9 . V_47 -> V_11 ; V_8 ++ ) {
V_6 = F_4 ( V_9 . V_47 , T_4 , V_8 ) ;
V_42 = FALSE ;
for ( V_111 = V_110 ; V_111 != NULL ; V_111 = F_15 ( V_111 ) ) {
if ( strcmp ( ( char * ) V_111 -> V_56 , V_6 . V_12 ) == 0 ) {
V_6 . V_57 = TRUE ;
if ( V_6 . V_51 ) {
V_6 . V_51 = FALSE ;
V_9 . V_53 -- ;
}
V_42 = TRUE ;
break;
}
}
if ( ! V_42 ) {
V_6 . V_57 = FALSE ;
}
V_9 . V_47 = F_11 ( V_9 . V_47 , V_8 ) ;
F_42 ( V_9 . V_47 , V_8 , V_6 ) ;
}
F_51 ( V_110 ) ;
F_6 ( V_108 ) ;
}
void
F_52 ( void )
{
T_4 V_6 ;
T_8 * V_30 ;
T_6 V_8 ;
for ( V_8 = 0 ; V_8 < V_9 . V_47 -> V_11 ; V_8 ++ ) {
V_6 = F_4 ( V_9 . V_47 , T_4 , V_8 ) ;
V_6 . type = F_53 ( V_6 . V_12 ) ;
F_6 ( V_6 . V_62 ) ;
V_30 = F_18 ( V_6 . V_12 ) ;
V_6 . V_62 = F_19 ( V_30 , & V_6 . V_28 ) ;
F_6 ( V_30 ) ;
V_6 . V_57 = F_20 ( V_6 . V_12 ) ;
F_3 ( & V_6 ) ;
V_9 . V_47 = F_11 ( V_9 . V_47 , V_8 ) ;
F_42 ( V_9 . V_47 , V_8 , V_6 ) ;
}
}
