static void
F_1 ( void * T_1 V_1 )
{
}
static int
F_2 ( void * V_2 , T_2 * V_3 , T_3 * T_4 V_1 , const void * V_4 )
{
T_5 * V_5 = ( T_5 * ) V_2 ;
const T_6 * V_6 = ( const T_6 * ) V_4 ;
T_7 * V_7 ;
T_8 V_8 [ 3 ] ;
T_9 V_9 = 0 ;
if ( V_5 -> V_10 . V_11 == 0 ) {
F_3 ( & V_5 -> V_10 , & V_3 -> V_12 ) ;
F_3 ( & V_5 -> V_13 , & V_3 -> V_14 ) ;
}
V_8 [ 0 ] . V_15 = ( const V_16 * ) & V_6 ;
V_8 [ 0 ] . V_11 = V_17 ;
V_8 [ 1 ] . V_15 = & V_6 -> V_18 ;
V_8 [ 1 ] . V_11 = 1 ;
V_8 [ 2 ] . V_15 = ( const V_16 * ) V_6 -> V_19 . V_20 ;
V_8 [ 2 ] . V_15 = V_8 [ 2 ] . V_15 + V_6 -> V_19 . V_11 ;
V_8 [ 2 ] . V_11 = V_6 -> V_21 - 20 ;
V_9 = F_4 ( & V_8 [ 0 ] , 3 ) ;
V_7 = ( T_7 * ) F_5 ( sizeof( T_7 ) ) ;
V_7 -> V_22 = ( V_23 * ) F_5 ( sizeof( V_23 ) ) ;
V_7 -> V_22 -> V_24 = NULL ;
V_7 -> V_22 -> V_25 = 1 ;
V_7 -> V_22 -> V_26 = V_9 ;
V_7 -> V_27 = V_3 -> V_27 ;
V_7 -> V_28 = V_6 -> V_29 ;
V_7 -> V_30 = V_6 -> V_30 ;
F_3 ( & V_7 -> V_12 , & V_3 -> V_12 ) ;
V_7 -> V_31 = V_3 -> V_31 ;
F_6 ( & V_7 -> V_32 ) ;
F_6 ( & V_7 -> V_22 -> V_33 ) ;
F_7 ( V_5 -> V_34 , F_8 ( V_3 -> V_27 ) , V_7 ) ;
return 1 ;
}
static void
F_9 ( T_10 V_20 )
{
T_7 * V_7 = ( T_7 * ) V_20 ;
F_10 ( V_7 -> V_22 ) ;
F_10 ( V_7 ) ;
}
static void
F_11 ( T_10 T_11 V_1 , T_10 V_35 , T_10 V_2 )
{
T_5 * V_5 = ( T_5 * ) V_2 ;
T_7 * V_7 = ( T_7 * ) V_35 , * V_36 ;
T_12 V_37 ;
T_13 V_38 ;
T_2 * V_3 = ( T_2 * ) F_5 ( sizeof( T_2 ) ) ;
V_3 -> V_39 = ( V_40 * ) F_5 ( sizeof( V_40 ) ) ;
V_3 -> V_27 = V_7 -> V_27 ;
V_36 = ( T_7 * ) F_12 ( V_5 -> V_41 , F_8 ( ( V_42 ) V_7 -> V_28 ) ) ;
if ( V_36 == NULL ) {
if ( ( V_5 -> V_43 == FALSE ) && ( V_5 -> V_44 > V_45 ) && ( V_5 -> V_46 < V_47 ) ) {
V_5 -> V_46 ++ ;
V_5 -> V_48 = V_7 -> V_27 ;
} else if ( V_5 -> V_46 < V_47 ) {
V_5 -> V_46 = 0 ;
V_5 -> V_48 = V_49 ;
}
V_5 -> V_43 = FALSE ;
V_7 -> V_22 -> V_25 = 1 ;
F_7 ( V_5 -> V_41 , F_8 ( ( V_42 ) V_7 -> V_28 ) , V_7 ) ;
} else {
if ( ( V_5 -> V_43 || ( V_45 == 0 ) ) && ( V_5 -> V_44 < V_45 || ( V_45 == 0 ) ) ) {
if ( ( V_45 == 0 ) && ( V_5 -> V_44 != 0 ) ) {
} else {
V_5 -> V_44 ++ ;
V_5 -> V_50 = V_36 -> V_27 ;
V_5 -> V_51 = V_7 -> V_27 ;
}
} else if ( V_5 -> V_44 < V_45 ) {
V_5 -> V_44 = 0 ;
V_5 -> V_50 = V_49 ;
}
V_5 -> V_43 = TRUE ;
V_7 -> V_22 -> V_25 = V_36 -> V_22 -> V_25 + 1 ;
if ( V_36 -> V_22 -> V_26 != V_7 -> V_22 -> V_26 ) {
V_7 -> V_22 -> V_26 = V_52 ;
V_36 -> V_22 -> V_26 = V_52 ;
}
V_7 -> V_22 -> V_24 = V_36 ;
if ( V_7 -> V_22 -> V_25 == V_53 ) {
F_13 ( & V_37 , & V_7 -> V_31 , & V_36 -> V_31 ) ;
F_6 ( & V_36 -> V_37 ) ;
F_14 ( & V_36 -> V_37 , & V_37 ) ;
F_6 ( & V_7 -> V_37 ) ;
F_14 ( & V_7 -> V_37 , & V_37 ) ;
F_15 ( & V_5 -> V_54 , & V_37 , V_3 ) ;
}
F_7 ( V_5 -> V_41 , F_8 ( ( V_42 ) V_7 -> V_28 ) , V_7 ) ;
}
if ( V_55 && ( V_7 -> V_27 < V_56 ) ) {
for ( V_38 = 0 ; V_38 < V_5 -> V_57 -> V_11 ; V_38 ++ ) {
if ( F_16 ( V_5 -> V_57 , V_16 , V_38 ) == V_7 -> V_30 ) {
return;
}
}
F_17 ( V_5 -> V_57 , V_7 -> V_30 ) ;
}
F_10 ( V_3 -> V_39 ) ;
F_10 ( V_3 ) ;
}
static void
F_18 ( T_10 T_11 V_1 , T_10 V_35 , T_10 V_2 )
{
T_5 * V_5 = ( T_5 * ) V_2 ;
T_7 * V_7 = ( T_7 * ) V_35 , * V_36 ;
V_36 = ( T_7 * ) F_12 ( V_5 -> V_58 , F_8 ( ( V_42 ) V_7 -> V_28 ) ) ;
if ( V_36 == NULL ) {
if ( V_55 == FALSE ) {
if ( ( F_19 ( & V_5 -> V_10 , & V_7 -> V_12 ) ) || ( F_19 ( & V_5 -> V_13 , & V_7 -> V_12 ) ) ) {
F_7 ( V_5 -> V_58 , F_8 ( ( V_42 ) V_7 -> V_28 ) , V_7 ) ;
V_7 -> V_32 = V_5 -> V_32 ;
V_5 -> V_32 . V_59 = V_5 -> V_32 . V_59 + V_53 ;
} else {
V_5 -> V_32 . V_59 ++ ;
F_7 ( V_5 -> V_58 , F_8 ( ( V_42 ) V_7 -> V_28 ) , V_7 ) ;
V_7 -> V_32 = V_5 -> V_32 ;
V_5 -> V_32 . V_59 ++ ;
}
} else {
if ( ( F_16 ( V_5 -> V_57 , V_16 , 0 ) == V_7 -> V_30 ) || ( F_16 ( V_5 -> V_57 , V_16 , 1 ) == V_7 -> V_30 ) ) {
F_7 ( V_5 -> V_58 , F_8 ( ( V_42 ) V_7 -> V_28 ) , V_7 ) ;
V_7 -> V_32 = V_5 -> V_32 ;
V_5 -> V_32 . V_59 = V_5 -> V_32 . V_59 + V_53 ;
} else {
V_5 -> V_32 . V_59 ++ ;
F_7 ( V_5 -> V_58 , F_8 ( ( V_42 ) V_7 -> V_28 ) , V_7 ) ;
V_7 -> V_32 = V_5 -> V_32 ;
V_5 -> V_32 . V_59 ++ ;
}
}
} else {
if ( V_55 == FALSE ) {
if ( ( ( F_19 ( & V_5 -> V_10 , & V_7 -> V_12 ) ) || ( F_19 ( & V_5 -> V_13 , & V_7 -> V_12 ) ) ) && ( ! fmod ( V_36 -> V_32 . V_59 , V_53 ) ) ) {
V_7 -> V_32 . V_59 = V_36 -> V_32 . V_59 ;
} else {
V_7 -> V_32 . V_59 = V_36 -> V_32 . V_59 + 1 ;
}
} else {
if ( ( ( F_16 ( V_5 -> V_57 , V_16 , 0 ) == V_7 -> V_30 ) || ( F_16 ( V_5 -> V_57 , V_16 , 1 ) == V_7 -> V_30 ) ) && ( ! fmod ( V_36 -> V_32 . V_59 , V_53 ) ) ) {
V_7 -> V_32 . V_59 = V_36 -> V_32 . V_59 ;
} else {
V_7 -> V_32 . V_59 = V_36 -> V_32 . V_59 + 1 ;
}
}
}
if ( fmod ( V_7 -> V_32 . V_59 , V_53 ) ) {
V_5 -> V_60 ++ ;
} else {
V_5 -> V_61 ++ ;
}
if ( ! F_20 ( & V_5 -> V_62 ) ) {
V_7 -> V_22 -> V_33 . V_59 = V_5 -> V_62 . V_59 ;
}
V_5 -> V_62 . V_59 = V_7 -> V_32 . V_59 ;
}
static void
F_21 ( T_10 T_11 V_1 , T_10 V_35 , T_10 V_2 )
{
T_5 * V_5 = ( T_5 * ) V_2 ;
T_7 * V_7 = ( T_7 * ) V_35 , * V_36 = NULL ;
T_14 V_63 = V_5 -> V_60 + V_5 -> V_61 , V_64 ;
if ( ( V_7 -> V_27 == V_63 ) && ( V_5 -> V_48 != V_49 ) ) {
V_64 = V_5 -> V_48 ;
V_5 -> V_48 = V_63 - V_5 -> V_61 ;
V_5 -> V_65 = V_64 ;
}
if ( ( V_7 -> V_27 == V_63 ) && ( V_5 -> V_48 == V_49 ) && ( V_5 -> V_50 != V_49 ) ) {
V_36 = ( T_7 * ) F_12 ( V_5 -> V_34 , F_8 ( V_5 -> V_50 ) ) ;
if ( V_36 == NULL ) {
printf ( L_1 ) ;
return;
}
if ( fmod ( V_36 -> V_32 . V_59 , 2 ) ) {
V_5 -> V_48 = V_5 -> V_50 + ( V_5 -> V_61 - ( V_5 -> V_51 - V_5 -> V_60 ) ) ;
if ( V_5 -> V_48 > ( V_63 - V_5 -> V_61 ) ) {
V_5 -> V_48 = V_63 - V_5 -> V_61 ;
}
if ( V_5 -> V_48 > V_5 -> V_51 ) {
V_5 -> V_48 = V_5 -> V_51 - 1 ;
}
V_36 = ( T_7 * ) F_12 ( V_5 -> V_34 , F_8 ( V_5 -> V_48 ) ) ;
while ( ( V_36 != NULL ) ? fmod ( ! V_36 -> V_32 . V_59 , 2 ) : TRUE ) {
V_5 -> V_48 -- ;
V_36 = ( T_7 * ) F_12 ( V_5 -> V_34 , F_8 ( V_5 -> V_48 ) ) ;
}
} else {
V_5 -> V_48 = V_5 -> V_60 + V_5 -> V_50 ;
if ( V_5 -> V_48 > V_63 - V_5 -> V_60 ) {
V_5 -> V_48 = V_63 - V_5 -> V_60 ;
}
V_36 = ( T_7 * ) F_12 ( V_5 -> V_34 , F_8 ( V_5 -> V_48 ) ) ;
while ( ( V_36 != NULL ) ? fmod ( V_36 -> V_32 . V_59 , 2 ) : TRUE ) {
V_5 -> V_48 -- ;
V_36 = ( T_7 * ) F_12 ( V_5 -> V_34 , F_8 ( V_5 -> V_48 ) ) ;
}
}
V_5 -> V_65 = V_5 -> V_51 + ( V_5 -> V_48 - V_5 -> V_50 ) ;
if ( V_5 -> V_65 > V_63 ) {
V_5 -> V_65 = V_63 ;
}
}
if ( V_7 -> V_27 == V_63 && V_45 != 0 && V_47 != 0 ) {
if ( V_5 -> V_50 == V_49 ) {
printf ( L_2 ) ;
}
}
}
static void
F_22 ( T_10 T_11 V_1 , T_10 V_35 , T_10 V_66 )
{
T_7 * V_7 = ( T_7 * ) V_35 ;
T_5 * V_5 = ( T_5 * ) V_66 ;
T_15 V_37 , V_67 ;
T_16 V_68 = FALSE ;
T_16 V_69 = FALSE ;
T_16 V_70 = FALSE ;
T_16 V_71 = FALSE ;
V_37 = fabs ( F_23 ( & V_7 -> V_37 , 1 ) ) ;
V_67 = fabs ( F_23 ( & V_5 -> V_54 . V_72 , V_5 -> V_54 . V_27 ) ) ;
if ( V_45 != 0 && V_47 != 0 ) {
if ( ( V_5 -> V_50 < V_7 -> V_27 ) && ( V_5 -> V_48 > V_7 -> V_27 ) ) {
V_68 = TRUE ;
} else {
if ( ( V_7 -> V_27 > V_5 -> V_51 ) && ( V_7 -> V_27 < V_5 -> V_65 ) ) {
V_68 = TRUE ;
}
}
} else {
V_68 = TRUE ;
}
if ( V_68 ) {
if ( V_7 -> V_22 -> V_25 < V_53 ) {
printf ( L_3 , V_7 -> V_28 , V_7 -> V_22 -> V_25 ) ;
}
if ( V_7 -> V_22 -> V_25 > V_53 ) {
if ( V_7 -> V_22 -> V_26 == V_52 ) {
V_69 = TRUE ;
}
printf ( L_4 , V_7 -> V_28 , V_7 -> V_22 -> V_25 ,
V_69 ? L_5 : L_6 ) ;
}
if ( V_7 -> V_22 -> V_25 == V_53 ) {
if ( V_7 -> V_22 -> V_26 == V_52 ) {
printf ( L_7 , V_7 -> V_28 , V_7 -> V_22 -> V_25 ) ;
if ( ( ( V_37 < ( V_67 - V_5 -> V_54 . V_73 ) ) || ( V_37 > ( V_67 + V_5 -> V_54 . V_73 ) ) ) && ( V_37 > 0.0 ) && ( V_5 -> V_54 . V_73 != 0 ) ) {
V_70 = TRUE ;
}
if ( ( F_24 ( & V_7 -> V_22 -> V_33 , & V_7 -> V_32 ) > 0 || F_24 ( & V_7 -> V_22 -> V_24 -> V_22 -> V_33 , & V_7 -> V_22 -> V_24 -> V_32 ) > 0 ) && ( V_7 -> V_32 . V_59 != V_53 ) && V_74 ) {
V_71 = TRUE ;
}
printf ( L_8 , V_7 -> V_28 , V_7 -> V_22 -> V_25 ,
V_70 ? L_9 : L_6 , V_71 ? L_10 : L_6 ) ;
} else if ( ( ( V_37 < ( V_67 - V_5 -> V_54 . V_73 ) ) || ( V_37 > ( V_67 + V_5 -> V_54 . V_73 ) ) ) && ( V_37 > 0.0 ) && ( V_5 -> V_54 . V_73 != 0 ) ) {
printf ( L_11 , V_7 -> V_28 , V_7 -> V_22 -> V_25 ) ;
if ( ( F_24 ( & V_7 -> V_22 -> V_33 , & V_7 -> V_32 ) > 0 || F_24 ( & V_7 -> V_22 -> V_24 -> V_22 -> V_33 , & V_7 -> V_22 -> V_24 -> V_32 ) > 0 ) && V_7 -> V_32 . V_59 != V_53 && V_74 ) {
V_71 = TRUE ;
}
printf ( L_12 , V_7 -> V_28 , V_7 -> V_22 -> V_25 ,
V_71 ? L_10 : L_6 ) ;
} else if ( ( F_24 ( & V_7 -> V_22 -> V_33 , & V_7 -> V_32 ) > 0 || F_24 ( & V_7 -> V_22 -> V_24 -> V_22 -> V_33 , & V_7 -> V_22 -> V_24 -> V_32 ) > 0 ) && V_7 -> V_32 . V_59 != V_53 && V_74 ) {
printf ( L_13 , V_7 -> V_28 , V_7 -> V_22 -> V_25 ) ;
}
}
}
}
static void
F_25 ( void * V_75 )
{
T_5 * V_5 = ( T_5 * ) V_75 ;
T_17 * V_76 = F_26 ( L_6 ) ;
const T_18 * V_77 ;
T_14 V_60 , V_61 ;
V_5 -> V_32 . V_78 = 0 ;
V_5 -> V_32 . V_59 = 1 ;
F_27 ( & V_5 -> V_62 ) ;
V_5 -> V_57 = F_28 ( FALSE , FALSE , sizeof( V_16 ) ) ;
V_5 -> V_43 = FALSE ;
V_5 -> V_44 = 0 ;
V_5 -> V_46 = 0 ;
V_5 -> V_50 = V_49 ;
V_5 -> V_51 = V_49 ;
V_5 -> V_48 = V_49 ;
V_5 -> V_65 = V_49 ;
V_5 -> V_60 = 0 ;
V_5 -> V_61 = 0 ;
F_29 ( & V_5 -> V_54 ) ;
V_5 -> V_41 = F_30 ( NULL , NULL ) ;
F_31 ( V_5 -> V_34 , F_11 , V_5 ) ;
if ( V_55 && V_5 -> V_57 -> V_11 == 1 ) {
F_17 ( V_5 -> V_57 , F_16 ( V_5 -> V_57 , V_16 , 1 ) ) ;
}
F_31 ( V_5 -> V_34 , F_18 , V_5 ) ;
F_31 ( V_5 -> V_34 , F_21 , V_5 ) ;
V_60 = V_5 -> V_60 ;
V_61 = V_5 -> V_61 ;
F_32 ( V_5 -> V_58 ) ;
V_5 -> V_54 . V_73 = V_79 ;
V_77 = F_33 (
L_14
L_15
L_16
L_17
L_18
L_19
L_20
L_21 ,
V_5 -> V_80 ? V_5 -> V_80 : L_22 , ( V_60 + V_61 ) ,
V_60 , V_61 , V_5 -> V_50 ,
V_5 -> V_48 , V_5 -> V_51 , V_5 -> V_65 ,
V_5 -> V_54 . V_27 , V_5 -> V_54 . V_73 , fabs ( F_23 ( & V_5 -> V_54 . V_72 , V_5 -> V_54 . V_27 ) ) ) ;
printf ( L_23 ) ;
printf ( L_21 ) ;
printf ( L_24 ) ;
printf ( L_21 ) ;
printf ( L_25 , V_77 ) ;
F_31 ( V_5 -> V_41 , F_22 , V_5 ) ;
F_34 ( V_76 , TRUE ) ;
F_35 ( V_5 -> V_41 ) ;
F_36 ( V_5 -> V_57 , TRUE ) ;
}
static void
F_37 ( const char * V_81 , void * T_19 V_1 )
{
T_5 * V_5 ;
const char * V_80 = NULL ;
T_17 * V_82 ;
V_42 V_83 , V_84 , V_85 , V_86 , V_87 = 0 ;
T_15 V_73 ;
if ( sscanf ( V_81 , L_26 , & V_83 , & V_84 , & V_85 , & V_86 , & V_73 , & V_87 ) == 5 ) {
if ( * ( V_81 + V_87 ) == ',' )
V_80 = V_81 + V_87 + 1 ;
} else {
fprintf ( V_88 , L_27 ) ;
exit ( 1 ) ;
}
V_79 = V_73 ;
V_45 = V_83 ;
V_47 = V_84 ;
V_55 = V_85 ;
V_74 = V_86 ;
V_5 = F_38 ( T_5 , 1 ) ;
F_27 ( & V_5 -> V_62 ) ;
V_5 -> V_57 = F_28 ( FALSE , FALSE , sizeof( V_16 ) ) ;
V_5 -> V_43 = FALSE ;
V_5 -> V_44 = 0 ;
V_5 -> V_46 = 0 ;
V_5 -> V_50 = V_49 ;
V_5 -> V_51 = V_49 ;
V_5 -> V_48 = V_49 ;
V_5 -> V_65 = V_49 ;
V_5 -> V_60 = 0 ;
V_5 -> V_61 = 0 ;
V_5 -> V_32 . V_78 = 0 ;
V_5 -> V_32 . V_59 = 1 ;
V_5 -> V_58 = F_30 ( NULL , NULL ) ;
if ( V_80 ) {
V_5 -> V_80 = F_39 ( V_80 ) ;
} else {
V_5 -> V_80 = NULL ;
}
V_5 -> V_34 = F_40 ( NULL , NULL , NULL , F_9 ) ;
V_82 = F_41 ( L_28 , V_5 , V_80 , 0 , F_1 , F_2 , F_25 ) ;
if ( V_82 ) {
F_10 ( V_5 -> V_80 ) ;
F_35 ( V_5 -> V_34 ) ;
F_10 ( V_5 ) ;
fprintf ( V_88 , L_29 , V_82 -> V_89 ) ;
F_34 ( V_82 , TRUE ) ;
exit ( 1 ) ;
}
}
void
F_42 ( void )
{
F_43 ( & V_90 , NULL ) ;
}
