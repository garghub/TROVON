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
void
F_3 ( void )
{
T_3 * V_6 , * V_7 , * V_8 ;
T_2 * V_9 , * V_10 ;
char * V_11 ;
T_4 * V_12 ;
T_5 * V_13 = NULL ;
T_1 V_14 ;
T_6 V_15 ;
T_7 * V_16 ;
int V_17 = 0 , V_18 , V_19 ;
T_8 V_20 = 0 , V_21 ;
T_9 * V_22 , * V_23 ;
T_10 * V_24 = NULL ;
T_11 * V_25 ;
T_12 V_26 ;
T_13 * V_27 ;
T_14 V_28 ;
T_6 V_29 = FALSE ;
if ( V_30 . V_31 -> V_32 > 0 ) {
for ( V_18 = ( int ) V_30 . V_31 -> V_32 - 1 ; V_18 >= 0 ; V_18 -- ) {
V_26 = F_4 ( V_30 . V_31 , T_12 , V_18 ) ;
if ( V_26 . V_33 && V_26 . type != V_34 && V_26 . type != V_35 ) {
V_30 . V_31 = F_5 ( V_30 . V_31 , V_18 ) ;
}
}
}
V_8 = F_6 ( & V_19 , NULL ) ;
V_20 = 0 ;
for ( V_6 = V_8 ; V_6 != NULL ; V_6 = F_7 ( V_6 ) ) {
V_9 = ( T_2 * ) V_6 -> V_36 ;
V_27 = F_8 ( L_1 ) ;
V_17 = 0 ;
if ( strstr ( V_9 -> V_37 , L_2 ) ) {
continue;
}
V_26 . V_37 = F_9 ( V_9 -> V_37 ) ;
if ( V_9 -> V_5 != NULL ) {
V_26 . V_5 = F_9 ( V_9 -> V_5 ) ;
} else {
V_26 . V_5 = NULL ;
}
V_26 . V_38 = FALSE ;
V_26 . V_39 = FALSE ;
V_10 = ( T_2 * ) F_10 ( sizeof( T_2 ) ) ;
V_10 -> V_37 = F_9 ( V_9 -> V_37 ) ;
V_10 -> V_5 = F_9 ( V_9 -> V_5 ) ;
V_10 -> V_40 = F_9 ( V_9 -> V_40 ) ;
V_10 -> V_41 = V_9 -> V_41 ;
V_12 = F_11 ( V_9 -> V_37 ) ;
if ( V_12 != NULL ) {
V_11 = F_12 ( L_3 , V_12 , V_9 -> V_37 ) ;
F_13 ( V_12 ) ;
} else {
if ( V_9 -> V_5 != NULL ) {
#ifdef F_14
V_11 = F_12 ( L_4 , V_9 -> V_5 ) ;
#else
V_11 = F_12 ( L_3 , V_9 -> V_5 , V_9 -> V_37 ) ;
#endif
} else if ( V_9 -> V_40 != NULL ) {
V_11 = F_12 ( L_3 , V_9 -> V_40 , V_9 -> V_37 ) ;
} else {
V_11 = F_9 ( V_9 -> V_37 ) ;
}
}
V_26 . V_42 = V_11 ;
V_26 . V_43 = FALSE ;
if ( F_15 ( V_9 -> V_37 ) ) {
V_26 . V_38 = TRUE ;
}
V_26 . type = V_9 -> type ;
V_15 = F_16 ( V_9 -> V_37 ) ;
V_13 = F_17 ( V_9 -> V_37 , V_15 , NULL ) ;
for (; ( V_16 = F_18 ( V_9 -> V_44 , V_17 ) ) != NULL ; V_17 ++ ) {
V_23 = ( T_9 * ) F_10 ( sizeof( T_9 ) ) ;
if ( V_17 != 0 ) {
F_19 ( V_27 , L_5 ) ;
}
V_22 = ( T_9 * ) V_16 -> V_36 ;
if ( V_22 ) {
V_23 -> V_45 = V_22 -> V_45 ;
switch ( V_22 -> V_45 ) {
case V_46 :
V_23 -> V_22 . V_47 = V_22 -> V_22 . V_47 ;
F_19 ( V_27 , F_20 ( ( V_48 * ) & V_22 -> V_22 . V_47 ) ) ;
break;
case V_49 :
memcpy ( V_23 -> V_22 . V_50 , V_22 -> V_22 . V_50 , sizeof( V_22 -> V_22 ) ) ;
F_19 ( V_27 , F_21 ( (struct V_51 * ) & V_22 -> V_22 . V_50 ) ) ;
break;
default:
break;
}
} else {
F_13 ( V_23 ) ;
V_23 = NULL ;
}
if ( V_23 ) {
V_10 -> V_44 = F_22 ( V_10 -> V_44 , V_23 ) ;
}
}
#ifdef F_23
V_26 . V_33 = TRUE ;
V_26 . V_52 . V_53 = V_54 ;
V_26 . V_52 . V_55 . V_56 = F_9 ( V_30 . V_57 . V_56 ) ;
V_26 . V_52 . V_55 . V_58 = F_9 ( V_30 . V_57 . V_58 ) ;
V_26 . V_52 . V_55 . V_59 = V_30 . V_57 . V_59 ;
V_26 . V_52 . V_55 . V_60 = F_9 ( V_30 . V_57 . V_60 ) ;
V_26 . V_52 . V_55 . V_61 = F_9 ( V_30 . V_57 . V_61 ) ;
V_26 . V_52 . V_55 . V_62 = V_30 . V_57 . V_62 ;
V_26 . V_52 . V_55 . V_63 = V_30 . V_57 . V_63 ;
V_26 . V_52 . V_55 . V_64 = V_30 . V_57 . V_64 ;
#endif
#ifdef F_24
V_26 . V_52 . V_65 = V_30 . V_57 . V_65 ;
V_26 . V_52 . V_66 = V_30 . V_57 . V_66 ;
#endif
V_14 = 0 ;
V_26 . V_67 = NULL ;
if ( V_13 != NULL ) {
#if F_25 ( V_68 )
V_26 . V_69 = V_15 ;
V_26 . V_70 = V_13 -> V_71 ;
#endif
for ( V_7 = V_13 -> V_72 ; V_7 != NULL ; V_7 = F_7 ( V_7 ) ) {
V_25 = ( T_11 * ) V_7 -> V_36 ;
if ( V_14 == 0 ) {
V_26 . V_73 = V_25 -> V_74 ;
}
V_24 = ( T_10 * ) F_26 ( sizeof( T_10 ) ) ;
if ( V_25 -> V_75 != NULL ) {
V_24 -> V_74 = V_25 -> V_74 ;
V_24 -> V_37 = F_12 ( L_4 , V_25 -> V_75 ) ;
} else {
V_24 -> V_74 = - 1 ;
V_24 -> V_37 = F_12 ( L_6 , V_25 -> V_37 ) ;
}
V_26 . V_67 = F_27 ( V_26 . V_67 , V_24 ) ;
V_14 ++ ;
}
} else {
#if F_25 ( V_68 )
V_26 . V_69 = FALSE ;
V_26 . V_70 = FALSE ;
#endif
V_26 . V_73 = - 1 ;
}
V_26 . V_76 = F_9 ( V_27 -> V_77 ) ;
V_26 . V_78 = V_17 ;
V_26 . V_33 = TRUE ;
V_26 . V_9 = * V_10 ;
V_26 . V_79 = 0 ;
if ( ( V_26 . V_80 = F_28 ( V_9 -> V_37 ) ) == - 1 ) {
V_26 . V_80 = V_30 . V_57 . V_81 ;
}
if ( ( V_26 . V_82 = F_29 ( V_9 -> V_37 ) ) == - 1 ) {
V_26 . V_82 = V_30 . V_57 . V_82 ;
}
if ( F_30 ( V_9 -> V_37 ) == - 1 ) {
V_26 . V_83 = V_30 . V_57 . V_83 ;
} else {
V_26 . V_83 = ( T_8 ) F_30 ( V_9 -> V_37 ) ;
}
V_26 . V_84 = F_9 ( V_30 . V_57 . V_84 ) ;
#if F_25 ( F_14 ) || F_25 ( V_68 )
if ( ( V_26 . V_85 = F_31 ( V_9 -> V_37 ) ) == - 1 ) {
V_26 . V_85 = V_30 . V_57 . V_86 ;
}
#endif
if ( V_30 . V_87 -> V_32 > 0 ) {
for ( V_21 = 0 ; V_21 < V_30 . V_87 -> V_32 ; V_21 ++ ) {
V_28 = F_4 ( V_30 . V_87 , T_14 , V_21 ) ;
if ( strcmp ( V_28 . V_37 , V_26 . V_37 ) == 0 ) {
#if F_25 ( V_68 )
V_26 . V_85 = V_28 . V_86 ;
V_26 . V_69 = V_28 . V_15 ;
#endif
V_26 . V_80 = V_28 . V_81 ;
V_26 . V_82 = V_28 . V_82 ;
V_26 . V_83 = V_28 . V_83 ;
V_26 . V_84 = F_9 ( V_28 . V_84 ) ;
if ( V_28 . V_88 != - 1 ) {
V_26 . V_73 = V_28 . V_88 ;
}
V_26 . V_43 = TRUE ;
V_30 . V_89 ++ ;
break;
}
}
}
if ( V_30 . V_31 -> V_32 <= V_20 ) {
F_32 ( V_30 . V_31 , V_26 ) ;
V_20 = V_30 . V_31 -> V_32 ;
} else {
F_33 ( V_30 . V_31 , V_20 , V_26 ) ;
}
if ( V_13 != NULL ) {
F_34 ( V_13 ) ;
}
F_35 ( V_27 , TRUE ) ;
V_20 ++ ;
}
F_36 ( V_8 ) ;
for ( V_21 = 0 ; V_21 < V_30 . V_87 -> V_32 ; V_21 ++ ) {
V_28 = F_4 ( V_30 . V_87 , T_14 , V_21 ) ;
V_29 = FALSE ;
for ( V_18 = 0 ; V_18 < ( int ) V_30 . V_31 -> V_32 ; V_18 ++ ) {
V_26 = F_4 ( V_30 . V_31 , T_12 , V_18 ) ;
if ( strcmp ( V_26 . V_37 , V_28 . V_37 ) == 0 ) {
V_29 = TRUE ;
break;
}
}
if ( ! V_29 ) {
V_26 . V_37 = F_9 ( V_28 . V_37 ) ;
V_26 . V_42 = F_12 ( L_3 , V_26 . V_37 , V_28 . V_12 ) ;
V_26 . V_38 = FALSE ;
V_26 . V_43 = TRUE ;
V_26 . type = V_34 ;
#if F_25 ( F_14 ) || F_25 ( V_68 )
V_26 . V_85 = V_28 . V_86 ;
#endif
#if F_25 ( V_68 )
V_26 . V_69 = V_28 . V_15 ;
V_26 . V_70 = FALSE ;
#endif
V_26 . V_80 = V_28 . V_81 ;
V_26 . V_82 = V_28 . V_82 ;
V_26 . V_83 = V_28 . V_83 ;
V_26 . V_84 = F_9 ( V_28 . V_84 ) ;
V_26 . V_73 = V_28 . V_88 ;
V_26 . V_76 = NULL ;
V_26 . V_78 = 0 ;
V_26 . V_79 = 0 ;
V_26 . V_67 = NULL ;
V_26 . V_33 = TRUE ;
V_26 . V_39 = FALSE ;
V_26 . V_9 . V_37 = F_9 ( V_28 . V_37 ) ;
V_26 . V_9 . V_5 = NULL ;
V_26 . V_9 . V_40 = F_9 ( V_28 . V_12 ) ;
V_26 . V_9 . V_44 = NULL ;
V_26 . V_9 . V_41 = FALSE ;
F_32 ( V_30 . V_31 , V_26 ) ;
V_30 . V_89 ++ ;
}
}
}
void
F_37 ( void )
{
T_15 V_90 ;
T_15 V_91 ;
float V_92 ;
static T_6 V_93 = FALSE ;
F_38 ( & V_90 ) ;
F_39 ( V_94 , V_95 , L_7 ) ;
if ( ! V_93 ) {
F_3 () ;
V_93 = TRUE ;
}
F_38 ( & V_91 ) ;
V_92 = ( float ) ( ( V_91 . V_96 - V_90 . V_96 ) +
( ( V_91 . V_97 - V_90 . V_97 ) / 1e6 ) ) ;
F_39 ( V_94 , V_95 , L_8 , V_92 ) ;
}
void
F_40 ( T_4 * V_98 )
{
T_4 * V_99 ;
T_8 V_18 ;
T_12 V_26 ;
T_6 V_29 = FALSE ;
T_3 * V_100 = NULL , * V_101 ;
if ( V_98 != NULL ) {
for ( V_99 = strtok ( V_98 , L_9 ) ; V_99 ; V_99 = strtok ( NULL , L_9 ) ) {
V_100 = F_27 ( V_100 , V_99 ) ;
}
}
for ( V_18 = 0 ; V_18 < V_30 . V_31 -> V_32 ; V_18 ++ ) {
V_26 = F_4 ( V_30 . V_31 , T_12 , V_18 ) ;
V_29 = FALSE ;
for ( V_101 = V_100 ; V_101 != NULL ; V_101 = F_7 ( V_101 ) ) {
if ( strcmp ( ( char * ) V_101 -> V_36 , V_26 . V_37 ) == 0 ) {
V_26 . V_38 = TRUE ;
if ( V_26 . V_43 ) {
V_26 . V_43 = FALSE ;
V_30 . V_89 -- ;
}
V_29 = TRUE ;
break;
}
}
if ( ! V_29 ) {
V_26 . V_38 = FALSE ;
}
V_30 . V_31 = F_5 ( V_30 . V_31 , V_18 ) ;
F_33 ( V_30 . V_31 , V_18 , V_26 ) ;
}
}
