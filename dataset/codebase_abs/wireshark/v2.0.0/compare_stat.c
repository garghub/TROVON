static void
F_1 ( T_1 * V_1 )
{
F_2 ( V_1 -> V_2 , L_1 ) ;
}
static void
F_3 ( void * V_3 )
{
T_1 * V_1 = ( T_1 * ) V_3 ;
F_4 ( & V_1 -> V_4 , V_5 , 0 , NULL ) ;
F_4 ( & V_1 -> V_6 , V_5 , 0 , NULL ) ;
F_5 ( V_1 -> V_7 ) ;
F_1 ( V_1 ) ;
}
static int
F_6 ( void * V_3 , T_2 * V_8 , T_3 * T_4 V_9 , const void * V_10 )
{
T_1 * V_1 = ( T_1 * ) V_3 ;
const T_5 * V_11 = ( const T_5 * ) V_10 ;
T_6 * V_12 , * V_13 ;
T_7 V_14 [ 3 ] ;
T_8 V_15 = 0 ;
if( V_1 -> V_6 . V_16 == 0 ) {
V_1 -> V_6 = V_8 -> V_17 ;
V_1 -> V_4 = V_8 -> V_18 ;
}
V_14 [ 0 ] . V_19 = & V_11 -> V_20 ;
V_14 [ 0 ] . V_16 = V_21 ;
V_14 [ 1 ] . V_19 = & V_11 -> V_22 ;
V_14 [ 1 ] . V_16 = 1 ;
V_14 [ 2 ] . V_19 = ( const V_23 * ) V_11 -> V_24 . V_25 ;
V_14 [ 2 ] . V_19 = V_14 [ 2 ] . V_19 + V_11 -> V_24 . V_16 ;
V_14 [ 2 ] . V_16 = V_11 -> V_26 - 20 ;
V_15 = F_7 ( & V_14 [ 0 ] , 3 ) ;
V_13 = ( T_6 * ) F_8 ( V_1 -> V_27 , F_9 ( V_8 -> V_28 -> V_29 ) ) ;
if( ( V_13 != NULL ) ) {
F_10 ( V_8 -> V_30 , V_31 , & V_13 -> V_32 , L_2 ) ;
}
V_12 = ( T_6 * ) F_11 ( sizeof( T_6 ) ) ;
V_12 -> V_33 = ( V_34 * ) F_11 ( sizeof( V_34 ) ) ;
V_12 -> V_33 -> V_35 = NULL ;
V_12 -> V_33 -> V_36 = 1 ;
V_12 -> V_33 -> V_37 = V_15 ;
V_12 -> V_29 = V_8 -> V_28 -> V_29 ;
V_12 -> V_38 = V_11 -> V_39 ;
V_12 -> V_40 = V_11 -> V_40 ;
V_12 -> V_17 = V_8 -> V_17 ;
V_12 -> V_41 = V_8 -> V_28 -> V_41 ;
F_12 ( & V_12 -> V_32 ) ;
F_12 ( & V_12 -> V_33 -> V_42 ) ;
F_13 ( V_1 -> V_27 , F_9 ( V_8 -> V_28 -> V_29 ) , V_12 ) ;
if( ( V_43 ) F_14 ( & V_44 ) == V_12 -> V_29 ) {
F_15 ( & V_1 -> V_45 ) ;
return 1 ;
} else {
return 0 ;
}
}
static void
F_16 ( T_9 V_25 )
{
T_6 * V_12 = ( T_6 * ) V_25 ;
F_17 ( V_12 -> V_33 ) ;
F_17 ( V_12 ) ;
}
static void
F_18 ( T_9 T_10 V_9 , T_9 V_46 , T_9 V_3 )
{
T_1 * V_1 = ( T_1 * ) V_3 ;
T_6 * V_12 = ( T_6 * ) V_46 , * V_13 ;
T_11 V_47 ;
T_12 V_48 ;
T_2 * V_8 = ( T_2 * ) F_11 ( sizeof( T_2 ) ) ;
V_8 -> V_28 = ( V_49 * ) F_11 ( sizeof( V_49 ) ) ;
V_8 -> V_28 -> V_29 = V_12 -> V_29 ;
V_13 = ( T_6 * ) F_8 ( V_1 -> V_50 , F_9 ( ( V_51 ) V_12 -> V_38 ) ) ;
if( V_13 == NULL ) {
if( ( V_1 -> V_52 == FALSE ) && ( V_1 -> V_53 > V_54 ) && ( V_1 -> V_55 < V_56 ) ) {
V_1 -> V_55 ++ ;
V_1 -> V_57 = V_12 -> V_29 ;
} else if( V_1 -> V_55 < V_56 ) {
V_1 -> V_55 = 0 ;
V_1 -> V_57 = V_58 ;
}
V_1 -> V_52 = FALSE ;
V_12 -> V_33 -> V_36 = 1 ;
F_13 ( V_1 -> V_50 , F_9 ( ( V_51 ) V_12 -> V_38 ) , V_12 ) ;
} else {
if( ( V_1 -> V_52 || ( V_54 == 0 ) ) && ( V_1 -> V_53 < V_54 || ( V_54 == 0 ) ) ) {
if( ( V_54 == 0 ) && ( V_1 -> V_53 != 0 ) ) {
} else {
V_1 -> V_53 ++ ;
V_1 -> V_59 = V_13 -> V_29 ;
V_1 -> V_60 = V_12 -> V_29 ;
}
} else if( V_1 -> V_53 < V_54 ) {
V_1 -> V_53 = 0 ;
V_1 -> V_59 = V_58 ;
}
V_1 -> V_52 = TRUE ;
V_12 -> V_33 -> V_36 = V_13 -> V_33 -> V_36 + 1 ;
if( V_13 -> V_33 -> V_37 != V_12 -> V_33 -> V_37 ) {
V_12 -> V_33 -> V_37 = V_61 ;
V_13 -> V_33 -> V_37 = V_61 ;
}
V_12 -> V_33 -> V_35 = V_13 ;
if( V_12 -> V_33 -> V_36 == V_62 ) {
F_19 ( & V_47 , & V_12 -> V_41 , & V_13 -> V_41 ) ;
F_12 ( & V_13 -> V_47 ) ;
F_20 ( & V_13 -> V_47 , & V_47 ) ;
F_12 ( & V_12 -> V_47 ) ;
F_20 ( & V_12 -> V_47 , & V_47 ) ;
F_21 ( & V_1 -> V_63 , & V_47 , V_8 ) ;
}
F_13 ( V_1 -> V_50 , F_9 ( ( V_51 ) V_12 -> V_38 ) , V_12 ) ;
}
if( V_64 && ( V_12 -> V_29 < V_65 ) ) {
for( V_48 = 0 ; V_48 < V_1 -> V_66 -> V_16 ; V_48 ++ ) {
if( F_22 ( V_1 -> V_66 , V_23 , V_48 ) == V_12 -> V_40 ) {
return;
}
}
F_23 ( V_1 -> V_66 , V_12 -> V_40 ) ;
}
F_17 ( V_8 -> V_28 ) ;
F_17 ( V_8 ) ;
}
static void
F_24 ( T_9 T_10 V_9 , T_9 V_46 , T_9 V_3 )
{
T_1 * V_1 = ( T_1 * ) V_3 ;
T_6 * V_12 = ( T_6 * ) V_46 , * V_13 ;
V_13 = ( T_6 * ) F_8 ( V_1 -> V_67 , F_9 ( ( V_51 ) V_12 -> V_38 ) ) ;
if( V_13 == NULL ) {
if( V_64 == FALSE ) {
if( ( F_25 ( & V_1 -> V_6 , & V_12 -> V_17 ) ) || ( F_25 ( & V_1 -> V_4 , & V_12 -> V_17 ) ) ) {
F_13 ( V_1 -> V_67 , F_9 ( ( V_51 ) V_12 -> V_38 ) , V_12 ) ;
V_12 -> V_32 = V_1 -> V_32 ;
V_1 -> V_32 . V_68 = V_1 -> V_32 . V_68 + V_62 ;
} else {
V_1 -> V_32 . V_68 ++ ;
F_13 ( V_1 -> V_67 , F_9 ( ( V_51 ) V_12 -> V_38 ) , V_12 ) ;
V_12 -> V_32 = V_1 -> V_32 ;
V_1 -> V_32 . V_68 ++ ;
}
} else {
if( ( F_22 ( V_1 -> V_66 , V_23 , 0 ) == V_12 -> V_40 ) || ( F_22 ( V_1 -> V_66 , V_23 , 1 ) == V_12 -> V_40 ) ) {
F_13 ( V_1 -> V_67 , F_9 ( ( V_51 ) V_12 -> V_38 ) , V_12 ) ;
V_12 -> V_32 = V_1 -> V_32 ;
V_1 -> V_32 . V_68 = V_1 -> V_32 . V_68 + V_62 ;
} else {
V_1 -> V_32 . V_68 ++ ;
F_13 ( V_1 -> V_67 , F_9 ( ( V_51 ) V_12 -> V_38 ) , V_12 ) ;
V_12 -> V_32 = V_1 -> V_32 ;
V_1 -> V_32 . V_68 ++ ;
}
}
} else {
if( V_64 == FALSE ) {
if( ( ( F_25 ( & V_1 -> V_6 , & V_12 -> V_17 ) ) || ( F_25 ( & V_1 -> V_4 , & V_12 -> V_17 ) ) ) && ( ! fmod ( V_13 -> V_32 . V_68 , V_62 ) ) ) {
V_12 -> V_32 . V_68 = V_13 -> V_32 . V_68 ;
} else {
V_12 -> V_32 . V_68 = V_13 -> V_32 . V_68 + 1 ;
}
} else {
if( ( ( F_22 ( V_1 -> V_66 , V_23 , 0 ) == V_12 -> V_40 ) || ( F_22 ( V_1 -> V_66 , V_23 , 1 ) == V_12 -> V_40 ) ) && ( ! fmod ( V_13 -> V_32 . V_68 , V_62 ) ) ) {
V_12 -> V_32 . V_68 = V_13 -> V_32 . V_68 ;
} else {
V_12 -> V_32 . V_68 = V_13 -> V_32 . V_68 + 1 ;
}
}
}
if( fmod ( V_12 -> V_32 . V_68 , V_62 ) ) {
V_1 -> V_69 ++ ;
} else {
V_1 -> V_70 ++ ;
}
if( ! F_26 ( & V_1 -> V_45 ) ) {
V_12 -> V_33 -> V_42 . V_68 = V_1 -> V_45 . V_68 ;
}
V_1 -> V_45 . V_68 = V_12 -> V_32 . V_68 ;
}
static void
F_27 ( T_9 T_10 V_9 , T_9 V_46 , T_9 V_3 )
{
T_1 * V_1 = ( T_1 * ) V_3 ;
T_6 * V_12 = ( T_6 * ) V_46 , * V_13 = NULL ;
V_43 V_71 = V_1 -> V_69 + V_1 -> V_70 , V_72 ;
if( ( V_12 -> V_29 == V_71 ) && ( V_1 -> V_57 != V_58 ) ) {
V_72 = V_1 -> V_57 ;
V_1 -> V_57 = V_71 - V_1 -> V_70 ;
V_1 -> V_73 = V_72 ;
}
if( ( V_12 -> V_29 == V_71 ) && ( V_1 -> V_57 == V_58 ) && ( V_1 -> V_59 != V_58 ) ) {
V_13 = ( T_6 * ) F_8 ( V_1 -> V_27 , F_9 ( V_1 -> V_59 ) ) ;
if( V_13 == NULL ) {
fprintf ( V_74 , L_3 ) ;
}
if( V_13 && fmod ( V_13 -> V_32 . V_68 , 2 ) ) {
V_1 -> V_57 = V_1 -> V_59 + ( V_1 -> V_70 - ( V_1 -> V_60 - V_1 -> V_69 ) ) ;
if( V_1 -> V_57 > ( V_71 - V_1 -> V_70 ) ) {
V_1 -> V_57 = V_71 - V_1 -> V_70 ;
}
if( V_1 -> V_57 > V_1 -> V_60 ) {
V_1 -> V_57 = V_1 -> V_60 - 1 ;
}
V_13 = ( T_6 * ) F_8 ( V_1 -> V_27 , F_9 ( V_1 -> V_57 ) ) ;
while( ( V_13 != NULL ) ? fmod ( ! V_13 -> V_32 . V_68 , 2 ) : TRUE ) {
V_1 -> V_57 -- ;
V_13 = ( T_6 * ) F_8 ( V_1 -> V_27 , F_9 ( V_1 -> V_57 ) ) ;
}
} else {
V_1 -> V_57 = V_1 -> V_69 + V_1 -> V_59 ;
if( V_1 -> V_57 > V_71 - V_1 -> V_69 ) {
V_1 -> V_57 = V_71 - V_1 -> V_69 ;
}
V_13 = ( T_6 * ) F_8 ( V_1 -> V_27 , F_9 ( V_1 -> V_57 ) ) ;
while( ( V_13 != NULL ) ? fmod ( V_13 -> V_32 . V_68 , 2 ) : TRUE ) {
V_1 -> V_57 -- ;
V_13 = ( T_6 * ) F_8 ( V_1 -> V_27 , F_9 ( V_1 -> V_57 ) ) ;
}
}
V_1 -> V_73 = V_1 -> V_60 + ( V_1 -> V_57 - V_1 -> V_59 ) ;
if( V_1 -> V_73 > V_71 ) {
V_1 -> V_73 = V_71 ;
}
}
if( V_12 -> V_29 == V_71 && V_54 != 0 && V_56 != 0 ) {
if( V_1 -> V_59 == V_58 ) {
F_28 ( L_4 ) ;
}
}
}
static void
F_29 ( T_9 T_10 V_9 , T_9 V_46 , T_9 V_75 )
{
T_6 * V_12 = ( T_6 * ) V_46 ;
T_1 * V_1 = ( T_1 * ) V_75 ;
T_13 V_47 , V_76 ;
T_14 V_77 = FALSE ;
V_47 = fabs ( F_30 ( & V_12 -> V_47 , 1 ) ) ;
V_76 = fabs ( F_30 ( & V_1 -> V_63 . V_78 , V_1 -> V_63 . V_29 ) ) ;
if( V_54 != 0 && V_56 != 0 ) {
if( ( V_1 -> V_59 < V_12 -> V_29 ) && ( V_1 -> V_57 > V_12 -> V_29 ) ) {
V_77 = TRUE ;
} else {
if( ( V_12 -> V_29 > V_1 -> V_60 ) && ( V_12 -> V_29 < V_1 -> V_73 ) ) {
V_77 = TRUE ;
}
}
} else {
V_77 = TRUE ;
}
if( V_77 ) {
if( ( V_12 -> V_33 -> V_36 < V_62 ) ) {
F_31 ( F_32 ( F_33 ( F_34 ( V_1 -> V_79 ) ) ) , & V_1 -> V_80 , NULL ) ;
F_35 ( F_32 ( F_33 ( F_34 ( V_1 -> V_79 ) ) ) , & V_1 -> V_80 , V_81 , V_12 -> V_38 , V_82 , L_5 , V_83 , V_12 -> V_33 -> V_36 , V_84 , 0.0 , - 1 ) ;
}
if( V_12 -> V_33 -> V_36 > V_62 ) {
F_31 ( F_32 ( F_33 ( F_34 ( V_1 -> V_79 ) ) ) , & V_1 -> V_80 , NULL ) ;
F_35 ( F_32 ( F_33 ( F_34 ( V_1 -> V_79 ) ) ) , & V_1 -> V_80 , V_81 , V_12 -> V_38 , V_82 , L_6 , V_83 , V_12 -> V_33 -> V_36 , V_84 , 0.0 , - 1 ) ;
if( V_12 -> V_33 -> V_37 == V_61 ) {
F_31 ( F_32 ( F_33 ( F_34 ( V_1 -> V_79 ) ) ) , & V_1 -> V_85 , & V_1 -> V_80 ) ;
F_35 ( F_32 ( F_33 ( F_34 ( V_1 -> V_79 ) ) ) , & V_1 -> V_85 , V_81 , V_12 -> V_38 , V_82 , L_7 , V_83 , V_12 -> V_33 -> V_36 , V_84 , 0.0 , - 1 ) ;
}
}
if( V_12 -> V_33 -> V_36 == V_62 ) {
if( V_12 -> V_33 -> V_37 == V_61 ) {
F_31 ( F_32 ( F_33 ( F_34 ( V_1 -> V_79 ) ) ) , & V_1 -> V_80 , NULL ) ;
F_35 ( F_32 ( F_33 ( F_34 ( V_1 -> V_79 ) ) ) , & V_1 -> V_80 , V_81 , V_12 -> V_38 , V_82 , L_7 , V_83 , V_12 -> V_33 -> V_36 , V_84 , V_47 , - 1 ) ;
if( ( ( V_47 < ( V_76 - V_1 -> V_63 . V_86 ) ) || ( V_47 > ( V_76 + V_1 -> V_63 . V_86 ) ) ) && ( V_47 > 0.0 ) && ( V_1 -> V_63 . V_86 != 0 ) ) {
F_31 ( F_32 ( F_33 ( F_34 ( V_1 -> V_79 ) ) ) , & V_1 -> V_85 , & V_1 -> V_80 ) ;
F_35 ( F_32 ( F_33 ( F_34 ( V_1 -> V_79 ) ) ) , & V_1 -> V_85 , V_81 , V_12 -> V_38 , V_82 , L_8 , V_83 , V_12 -> V_33 -> V_36 , V_84 , V_47 , - 1 ) ;
}
if( ( F_36 ( & V_12 -> V_33 -> V_42 , & V_12 -> V_32 ) > 0 || F_36 ( & V_12 -> V_33 -> V_35 -> V_33 -> V_42 , & V_12 -> V_33 -> V_35 -> V_32 ) > 0 ) && ( V_12 -> V_32 . V_68 != V_62 ) && V_87 ) {
F_31 ( F_32 ( F_33 ( F_34 ( V_1 -> V_79 ) ) ) , & V_1 -> V_85 , & V_1 -> V_80 ) ;
F_35 ( F_32 ( F_33 ( F_34 ( V_1 -> V_79 ) ) ) , & V_1 -> V_85 , V_81 , V_12 -> V_38 , V_82 , L_9 , V_83 , V_12 -> V_33 -> V_36 , V_84 , V_47 , - 1 ) ;
}
} else if( ( ( V_47 < ( V_76 - V_1 -> V_63 . V_86 ) ) || ( V_47 > ( V_76 + V_1 -> V_63 . V_86 ) ) ) && ( V_47 > 0.0 ) && ( V_1 -> V_63 . V_86 != 0 ) ) {
F_31 ( F_32 ( F_33 ( F_34 ( V_1 -> V_79 ) ) ) , & V_1 -> V_80 , NULL ) ;
F_35 ( F_32 ( F_33 ( F_34 ( V_1 -> V_79 ) ) ) , & V_1 -> V_80 , V_81 , V_12 -> V_38 , V_82 , L_8 , V_83 , V_12 -> V_33 -> V_36 , V_84 , V_47 , - 1 ) ;
if( ( F_36 ( & V_12 -> V_33 -> V_42 , & V_12 -> V_32 ) > 0 || F_36 ( & V_12 -> V_33 -> V_35 -> V_33 -> V_42 , & V_12 -> V_33 -> V_35 -> V_32 ) > 0 ) && V_12 -> V_32 . V_68 != V_62 && V_87 ) {
F_31 ( F_32 ( F_33 ( F_34 ( V_1 -> V_79 ) ) ) , & V_1 -> V_85 , & V_1 -> V_80 ) ;
F_35 ( F_32 ( F_33 ( F_34 ( V_1 -> V_79 ) ) ) , & V_1 -> V_85 , V_81 , V_12 -> V_38 , V_82 , L_9 , V_83 , V_12 -> V_33 -> V_36 , V_84 , V_47 , - 1 ) ;
}
} else if( ( F_36 ( & V_12 -> V_33 -> V_42 , & V_12 -> V_32 ) > 0 || F_36 ( & V_12 -> V_33 -> V_35 -> V_33 -> V_42 , & V_12 -> V_33 -> V_35 -> V_32 ) > 0 ) && V_12 -> V_32 . V_68 != V_62 && V_87 ) {
F_31 ( F_32 ( F_33 ( F_34 ( V_1 -> V_79 ) ) ) , & V_1 -> V_80 , NULL ) ;
F_35 ( F_32 ( F_33 ( F_34 ( V_1 -> V_79 ) ) ) , & V_1 -> V_80 , V_81 , V_12 -> V_38 , V_82 , L_9 , V_83 , V_12 -> V_33 -> V_36 , V_84 , V_47 , - 1 ) ;
}
}
}
}
static void
F_37 ( T_15 * V_2 V_9 , T_9 V_25 )
{
T_1 * V_1 = ( T_1 * ) V_25 ;
F_38 ( V_1 ) ;
V_88 = TRUE ;
F_5 ( V_1 -> V_7 ) ;
F_39 ( V_1 -> V_27 ) ;
F_39 ( V_1 -> V_67 ) ;
F_39 ( V_1 -> V_50 ) ;
F_17 ( V_1 ) ;
}
static void
F_40 ( void * V_3 )
{
T_1 * V_1 = ( T_1 * ) V_3 ;
T_16 * V_89 = F_41 ( L_10 ) ;
const T_17 * V_90 ;
T_6 * V_12 ;
V_43 V_69 , V_70 ;
char * V_91 ;
V_1 -> V_32 . V_92 = 0 ;
V_1 -> V_32 . V_68 = 1 ;
F_15 ( & V_1 -> V_45 ) ;
V_1 -> V_66 = F_42 ( FALSE , FALSE , sizeof( V_23 ) ) ;
V_1 -> V_52 = FALSE ;
V_1 -> V_53 = 0 ;
V_1 -> V_55 = 0 ;
V_1 -> V_59 = V_58 ;
V_1 -> V_60 = V_58 ;
V_1 -> V_57 = V_58 ;
V_1 -> V_73 = V_58 ;
V_1 -> V_69 = 0 ;
V_1 -> V_70 = 0 ;
F_43 ( & V_1 -> V_63 ) ;
if( F_14 ( & V_44 ) == 0 ) {
V_90 = F_44 ( L_11 ) ;
F_45 ( ( V_93 * ) V_1 -> V_94 , V_90 ) ;
return;
}
F_46 ( V_1 -> V_27 , F_18 , V_1 ) ;
if( V_64 && V_1 -> V_66 -> V_16 == 1 ) {
F_23 ( V_1 -> V_66 , F_22 ( V_1 -> V_66 , V_23 , 1 ) ) ;
}
F_46 ( V_1 -> V_27 , F_24 , V_1 ) ;
F_46 ( V_1 -> V_27 , F_27 , V_1 ) ;
V_69 = V_1 -> V_69 ;
V_70 = V_1 -> V_70 ;
F_47 ( V_1 -> V_67 ) ;
F_15 ( & V_1 -> V_45 ) ;
if( V_64 && V_1 -> V_66 -> V_16 != 0 ) {
F_48 ( V_89 , L_12 , L_13 , F_22 ( V_1 -> V_66 , V_23 , 0 ) , L_14 , F_22 ( V_1 -> V_66 , V_23 , 1 ) ) ;
} else if( V_1 -> V_6 . V_16 != 0 && V_1 -> V_4 . V_16 != 0 ) {
V_91 = ( char * ) F_49 ( NULL , & V_1 -> V_6 ) ;
F_48 ( V_89 , L_15 , L_16 , V_91 , L_17 , V_91 ) ;
F_50 ( NULL , V_91 ) ;
}
F_51 ( V_95 , V_89 -> V_96 , FALSE ) ;
F_52 () ;
V_1 -> V_63 . V_86 = V_97 ;
V_90 = F_44 ( L_18 , F_14 ( & V_44 ) , V_69 , V_70 , V_1 -> V_59 , V_1 -> V_57 , V_1 -> V_60 , V_1 -> V_73 , V_1 -> V_63 . V_29 , V_1 -> V_63 . V_86 , fabs ( F_30 ( & V_1 -> V_63 . V_78 , V_1 -> V_63 . V_29 ) ) ) ;
F_45 ( ( V_93 * ) V_1 -> V_94 , V_90 ) ;
if( V_1 -> V_59 != V_58 && V_54 != 0 && V_56 != 0 ) {
V_12 = ( T_6 * ) F_8 ( V_1 -> V_27 , F_9 ( V_1 -> V_59 ) ) ;
if( V_12 ) {
F_31 ( F_32 ( F_33 ( F_34 ( V_1 -> V_79 ) ) ) , & V_1 -> V_80 , NULL ) ;
F_35 ( F_32 ( F_33 ( F_34 ( V_1 -> V_79 ) ) ) , & V_1 -> V_80 , V_81 , V_12 -> V_38 , V_82 , L_19 , V_83 , 0 , V_84 , 0.0 , - 1 ) ;
}
}
if( V_1 -> V_57 != V_58 && V_54 != 0 && V_56 != 0 ) {
V_12 = ( T_6 * ) F_8 ( V_1 -> V_27 , F_9 ( V_1 -> V_57 ) ) ;
if( V_12 ) {
F_31 ( F_32 ( F_33 ( F_34 ( V_1 -> V_79 ) ) ) , & V_1 -> V_80 , NULL ) ;
F_35 ( F_32 ( F_33 ( F_34 ( V_1 -> V_79 ) ) ) , & V_1 -> V_80 , V_81 , V_12 -> V_38 , V_82 , L_20 , V_83 , 0 , V_84 , 0.0 , - 1 ) ;
}
}
F_46 ( V_1 -> V_50 , F_29 , V_1 ) ;
F_53 ( V_89 , TRUE ) ;
F_54 ( V_1 -> V_66 , TRUE ) ;
}
static void
F_55 ( T_18 * V_98 , T_9 V_75 )
{
T_17 * V_99 ;
T_19 * V_100 ;
T_20 V_80 ;
T_6 * V_12 ;
V_51 V_38 = - 1 ;
T_1 * V_1 = ( T_1 * ) V_75 ;
if( F_56 ( V_98 , & V_100 , & V_80 ) ) {
F_57 ( V_100 , & V_80 , 0 , & V_38 , 1 , & V_99 , - 1 ) ;
if ( V_38 < 0 ) return;
if( strcmp ( L_19 , V_99 ) == 0 ) {
F_58 ( & V_44 , V_1 -> V_59 ) ;
return;
}
if( strcmp ( L_20 , V_99 ) == 0 ) {
F_58 ( & V_44 , V_1 -> V_57 ) ;
return;
}
V_12 = ( T_6 * ) F_8 ( V_1 -> V_50 , F_9 ( V_38 ) ) ;
if( V_12 != NULL ) {
F_58 ( & V_44 , V_12 -> V_29 ) ;
}
}
}
static void
F_59 ( T_21 * V_79 )
{
T_22 * V_101 ;
T_23 * V_102 ;
V_101 = F_60 () ;
V_102 = F_61 ( L_21 , V_101 , L_22 , V_81 , NULL ) ;
F_62 ( F_34 ( V_79 ) , V_102 ) ;
V_101 = F_60 () ;
V_102 = F_61 ( L_23 , V_101 , L_22 , V_82 , NULL ) ;
F_62 ( F_34 ( V_79 ) , V_102 ) ;
V_101 = F_60 () ;
V_102 = F_61 ( L_24 , V_101 , L_22 , V_83 , NULL ) ;
F_62 ( F_34 ( V_79 ) , V_102 ) ;
V_101 = F_60 () ;
V_102 = F_61 ( L_25 , V_101 , L_22 , V_84 , NULL ) ;
F_62 ( F_34 ( V_79 ) , V_102 ) ;
}
static void
F_63 ( const char * V_103 , void * T_24 V_9 )
{
T_1 * V_1 ;
char * V_104 ;
char * V_105 ;
char * V_106 ;
T_21 * V_107 ;
T_21 * V_108 ;
T_21 * V_109 ;
T_21 * V_110 ;
T_21 * V_111 ;
T_21 * V_112 ;
T_13 V_86 ;
V_51 V_113 , V_114 , V_115 , V_116 , V_117 = 0 ;
const char * V_118 = NULL ;
T_16 * V_119 ;
if( sscanf ( V_103 , L_26 , & V_113 , & V_114 , & V_115 , & V_116 , & V_86 , & V_117 ) == 5 ) {
if( * ( V_103 + V_117 ) == ',' )
V_118 = V_103 + V_117 + 1 ;
} else {
fprintf ( V_74 , L_27 ) ;
exit ( 1 ) ;
}
V_97 = V_86 ;
V_54 = V_113 ;
V_56 = V_114 ;
V_64 = V_115 ;
V_87 = V_116 ;
V_1 = ( T_1 * ) F_11 ( sizeof( T_1 ) ) ;
F_15 ( & V_1 -> V_45 ) ;
V_1 -> V_66 = F_42 ( FALSE , FALSE , sizeof( V_23 ) ) ;
V_1 -> V_52 = FALSE ;
V_1 -> V_53 = 0 ;
V_1 -> V_55 = 0 ;
V_1 -> V_59 = V_58 ;
V_1 -> V_60 = V_58 ;
V_1 -> V_57 = V_58 ;
V_1 -> V_73 = V_58 ;
V_1 -> V_69 = 0 ;
V_1 -> V_70 = 0 ;
V_1 -> V_32 . V_92 = 0 ;
V_1 -> V_32 . V_68 = 1 ;
V_1 -> V_67 = F_64 ( NULL , NULL ) ;
V_1 -> V_2 = F_65 ( L_28 ) ;
F_66 ( F_67 ( V_1 -> V_2 ) , TRUE ) ;
F_68 ( F_67 ( V_1 -> V_2 ) , V_120 , V_121 ) ;
F_1 ( V_1 ) ;
V_112 = F_69 ( V_122 , 3 , FALSE ) ;
F_70 ( F_71 ( V_1 -> V_2 ) , V_112 ) ;
F_72 ( F_71 ( V_112 ) , 12 ) ;
V_104 = F_73 ( & V_44 ) ;
V_105 = F_44 ( L_29 , V_104 ) ;
F_17 ( V_104 ) ;
V_107 = F_74 ( V_105 ) ;
F_17 ( V_105 ) ;
F_75 ( F_76 ( V_112 ) , V_107 , FALSE , FALSE , 0 ) ;
V_106 = F_44 ( L_30 , V_118 ? V_118 : L_10 ) ;
V_108 = F_74 ( V_106 ) ;
F_17 ( V_106 ) ;
F_77 ( F_78 ( V_108 ) , TRUE ) ;
F_75 ( F_76 ( V_112 ) , V_108 , FALSE , FALSE , 0 ) ;
V_1 -> V_94 = F_74 ( L_31 ) ;
F_77 ( F_78 ( V_1 -> V_94 ) , TRUE ) ;
F_75 ( F_76 ( V_112 ) , V_1 -> V_94 , FALSE , FALSE , 0 ) ;
F_79 ( V_1 -> V_2 ) ;
V_1 -> V_79 = F_80 () ;
F_59 ( V_1 -> V_79 ) ;
V_1 -> V_7 = F_81 ( V_123 , V_124 , V_125 , V_124 , V_126 ) ;
F_82 ( F_34 ( V_1 -> V_79 ) , F_83 ( V_1 -> V_7 ) ) ;
F_84 ( V_1 -> V_7 ) ;
F_85 ( F_86 ( F_34 ( V_1 -> V_79 ) ) , V_127 ) ;
F_87 ( F_86 ( F_34 ( V_1 -> V_79 ) ) , L_32 , F_88 ( F_55 ) , V_1 ) ;
V_1 -> V_128 = F_89 ( NULL , NULL ) ;
F_90 ( F_91 ( V_1 -> V_128 ) , V_129 , V_129 ) ;
F_70 ( F_71 ( V_1 -> V_128 ) , V_1 -> V_79 ) ;
F_75 ( F_76 ( V_112 ) , V_1 -> V_128 , TRUE , TRUE , 0 ) ;
V_1 -> V_27 = F_92 ( NULL , NULL , NULL , F_16 ) ;
V_1 -> V_50 = F_64 ( NULL , NULL ) ;
V_119 = F_93 ( L_33 , V_1 , V_118 , 0 , F_3 , F_6 , F_40 ) ;
if( V_119 ) {
F_94 ( V_130 , V_131 , L_34 , V_119 -> V_96 ) ;
F_53 ( V_119 , TRUE ) ;
F_5 ( V_1 -> V_7 ) ;
F_39 ( V_1 -> V_27 ) ;
F_39 ( V_1 -> V_50 ) ;
F_17 ( V_1 ) ;
return;
}
V_109 = F_95 ( V_132 , V_133 , NULL ) ;
F_96 ( F_76 ( V_112 ) , V_109 , FALSE , FALSE , 0 ) ;
V_110 = ( T_21 * ) F_97 ( F_98 ( V_109 ) , V_132 ) ;
F_99 ( V_1 -> V_2 , V_110 , V_134 ) ;
V_111 = ( T_21 * ) F_97 ( F_98 ( V_109 ) , V_133 ) ;
F_87 ( V_111 , L_35 , F_88 ( V_135 ) , ( T_9 ) V_136 ) ;
F_87 ( V_1 -> V_2 , L_36 , F_88 ( V_137 ) , NULL ) ;
F_87 ( V_1 -> V_2 , L_37 , F_88 ( F_37 ) , V_1 ) ;
F_79 ( V_1 -> V_2 ) ;
F_100 ( V_1 -> V_2 ) ;
F_101 ( & V_44 ) ;
}
static void
F_102 ( T_21 * T_25 V_9 , T_9 V_25 V_9 )
{
T_16 * V_96 ;
const char * V_118 ;
V_54 = F_103 ( F_104 ( V_138 ) ) ;
V_56 = F_103 ( F_104 ( V_139 ) ) ;
V_97 = F_105 ( F_104 ( V_140 ) ) ;
if( F_106 ( F_107 ( V_141 ) ) ) {
V_64 = TRUE ;
} else {
V_64 = FALSE ;
}
if( F_106 ( F_107 ( V_142 ) ) ) {
V_87 = TRUE ;
} else {
V_87 = FALSE ;
}
V_96 = F_41 ( L_38 ) ;
F_108 ( V_96 , L_39 , V_54 , V_56 , V_64 , V_87 , V_97 ) ;
V_118 = F_109 ( F_110 ( V_143 ) ) ;
if( V_118 [ 0 ] != 0 ) {
F_108 ( V_96 , L_40 , V_118 ) ;
}
if( V_88 ) {
V_88 = FALSE ;
F_63 ( V_96 -> V_96 , NULL ) ;
} else {
F_28 ( L_41 ) ;
}
F_53 ( V_96 , TRUE ) ;
}
static void
F_111 ( T_21 * T_26 V_9 , T_9 V_75 V_9 )
{
V_144 = NULL ;
}
void
F_112 ( T_27 * T_28 V_9 , T_9 V_75 V_9 )
{
T_29 * V_145 , * V_146 , * V_147 ;
T_21 * V_148 ;
T_21 * V_149 , * V_150 , * V_151 , * V_152 ;
T_21 * V_153 , * V_154 ;
T_21 * V_155 , * V_156 , * V_157 ;
T_21 * V_158 , * V_159 , * V_160 ;
T_21 * V_161 , * V_162 ;
T_21 * V_109 , * V_163 , * V_164 ;
const char * V_118 ;
static T_30 args = {
L_42 ,
TRUE ,
FALSE ,
FALSE
} ;
if( V_144 ) {
F_113 ( F_114 ( V_144 ) ) ;
return;
}
V_144 = F_65 ( L_43 ) ;
F_68 ( F_67 ( V_144 ) , 300 , - 1 ) ;
V_148 = F_69 ( V_122 , 10 , FALSE ) ;
F_72 ( F_71 ( V_148 ) , 10 ) ;
F_70 ( F_71 ( V_144 ) , V_148 ) ;
F_115 ( V_148 ) ;
V_151 = F_69 ( V_165 , 10 , FALSE ) ;
V_152 = F_69 ( V_165 , 10 , FALSE ) ;
F_72 ( F_71 ( V_151 ) , 1 ) ;
V_149 = F_74 ( L_44 ) ;
F_75 ( F_76 ( V_151 ) , V_149 , FALSE , FALSE , 0 ) ;
F_115 ( V_149 ) ;
F_72 ( F_71 ( V_152 ) , 1 ) ;
V_150 = F_74 ( L_45 ) ;
F_75 ( F_76 ( V_152 ) , V_150 , FALSE , FALSE , 0 ) ;
F_115 ( V_150 ) ;
V_145 = F_116 ( F_117 ( 0.0 , 0.0 , 100.0 , 1.0 , 5.0 , 0.0 ) ) ;
V_146 = F_116 ( F_117 ( 0.0 , 0.0 , 100.0 , 1.0 , 5.0 , 0.0 ) ) ;
V_138 = F_118 ( V_145 , 1.0 , 0 ) ;
V_139 = F_118 ( V_146 , 1.0 , 0 ) ;
F_75 ( F_76 ( V_151 ) , V_138 , TRUE , TRUE , 0 ) ;
F_75 ( F_76 ( V_152 ) , V_139 , TRUE , TRUE , 0 ) ;
F_75 ( F_76 ( V_148 ) , V_151 , FALSE , FALSE , 0 ) ;
F_115 ( V_151 ) ;
F_75 ( F_76 ( V_148 ) , V_152 , FALSE , FALSE , 0 ) ;
F_115 ( V_152 ) ;
V_158 = F_69 ( V_165 , 10 , FALSE ) ;
F_72 ( F_71 ( V_158 ) , 1 ) ;
V_160 = F_74 ( L_46 ) ;
F_75 ( F_76 ( V_158 ) , V_160 , FALSE , FALSE , 0 ) ;
F_115 ( V_160 ) ;
V_156 = F_119 ( NULL , L_47 ) ;
V_141 = F_120 ( F_121 ( V_156 ) , L_48 ) ;
F_75 ( F_76 ( V_158 ) , V_156 , TRUE , TRUE , 0 ) ;
F_75 ( F_76 ( V_158 ) , V_141 , TRUE , TRUE , 0 ) ;
F_115 ( V_156 ) ;
F_115 ( V_141 ) ;
F_75 ( F_76 ( V_148 ) , V_158 , FALSE , FALSE , 0 ) ;
F_115 ( V_158 ) ;
V_155 = F_69 ( V_165 , 10 , FALSE ) ;
F_72 ( F_71 ( V_155 ) , 1 ) ;
V_157 = F_74 ( L_49 ) ;
F_75 ( F_76 ( V_155 ) , V_157 , FALSE , FALSE , 0 ) ;
F_115 ( V_157 ) ;
V_142 = F_119 ( NULL , L_50 ) ;
V_159 = F_120 ( F_121 ( V_142 ) , L_51 ) ;
F_75 ( F_76 ( V_155 ) , V_142 , TRUE , TRUE , 0 ) ;
F_75 ( F_76 ( V_155 ) , V_159 , TRUE , TRUE , 0 ) ;
F_115 ( V_142 ) ;
F_115 ( V_159 ) ;
F_75 ( F_76 ( V_148 ) , V_155 , FALSE , FALSE , 0 ) ;
F_115 ( V_155 ) ;
V_153 = F_69 ( V_165 , 10 , FALSE ) ;
F_72 ( F_71 ( V_153 ) , 1 ) ;
V_154 = F_74 ( L_52 ) ;
F_75 ( F_76 ( V_153 ) , V_154 , FALSE , FALSE , 0 ) ;
F_115 ( V_154 ) ;
V_147 = F_116 ( F_117 ( 0.0 , 0.0 , 100.0 , 1.0 , 5.0 , 0.0 ) ) ;
V_140 = F_118 ( V_147 , 0.0 , 2 ) ;
F_75 ( F_76 ( V_153 ) , V_140 , TRUE , TRUE , 0 ) ;
F_115 ( V_140 ) ;
F_75 ( F_76 ( V_148 ) , V_153 , FALSE , FALSE , 0 ) ;
F_115 ( V_153 ) ;
V_161 = F_69 ( V_165 , 3 , FALSE ) ;
V_162 = F_122 ( V_166 ) ;
F_87 ( V_162 , L_35 , F_88 ( V_167 ) , & args ) ;
F_75 ( F_76 ( V_161 ) , V_162 , FALSE , TRUE , 0 ) ;
F_115 ( V_162 ) ;
V_143 = F_123 () ;
F_87 ( V_143 , L_32 , F_88 ( V_168 ) , NULL ) ;
F_124 ( F_98 ( V_161 ) , V_169 , NULL ) ;
F_87 ( V_143 , L_53 , F_88 ( V_170 ) , NULL ) ;
F_87 ( V_144 , L_53 , F_88 ( V_171 ) , NULL ) ;
F_124 ( F_98 ( V_162 ) , V_172 , V_143 ) ;
F_75 ( F_76 ( V_161 ) , V_143 , TRUE , TRUE , 0 ) ;
V_118 = F_109 ( F_110 ( V_173 ) ) ;
if( V_118 ) {
F_125 ( F_110 ( V_143 ) , V_118 ) ;
}
F_115 ( V_143 ) ;
F_75 ( F_76 ( V_148 ) , V_161 , TRUE , TRUE , 0 ) ;
F_115 ( V_161 ) ;
V_109 = F_95 ( V_174 , V_175 , NULL ) ;
F_75 ( F_76 ( V_148 ) , V_109 , FALSE , FALSE , 0 ) ;
F_115 ( V_109 ) ;
V_163 = ( T_21 * ) F_97 ( F_98 ( V_109 ) , V_174 ) ;
F_126 ( V_163 , L_35 , F_88 ( F_102 ) , NULL ) ;
V_164 = ( T_21 * ) F_97 ( F_98 ( V_109 ) , V_175 ) ;
F_99 ( V_144 , V_164 , V_134 ) ;
F_127 ( V_143 ) ;
F_128 ( V_163 ) ;
F_87 ( V_144 , L_36 , F_88 ( V_137 ) , NULL ) ;
F_87 ( V_144 , L_37 , F_88 ( F_111 ) , NULL ) ;
F_79 ( V_144 ) ;
F_100 ( V_144 ) ;
}
void
F_129 ( void )
{
F_130 ( & V_176 , NULL ) ;
}
