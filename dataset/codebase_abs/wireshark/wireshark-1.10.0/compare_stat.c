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
const T_5 * V_11 = ( T_5 * ) V_10 ;
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
V_14 [ 2 ] . V_19 = ( V_23 * ) V_11 -> V_24 . V_25 ;
V_14 [ 2 ] . V_19 = V_14 [ 2 ] . V_19 + V_11 -> V_24 . V_16 ;
V_14 [ 2 ] . V_16 = V_8 -> V_26 - 20 ;
V_15 = F_7 ( & V_14 [ 0 ] , 3 ) ;
V_13 = ( T_6 * ) F_8 ( V_1 -> V_27 , V_8 -> V_28 -> V_29 ) ;
if( ( V_13 != NULL ) ) {
F_9 ( V_8 -> V_30 , V_31 , & V_13 -> V_32 , L_2 ) ;
}
V_12 = ( T_6 * ) F_10 ( sizeof( T_6 ) ) ;
V_12 -> V_33 = ( V_34 * ) F_10 ( sizeof( V_34 ) ) ;
V_12 -> V_33 -> V_35 = NULL ;
V_12 -> V_33 -> V_36 = 1 ;
V_12 -> V_33 -> V_37 = V_15 ;
V_12 -> V_29 = V_8 -> V_28 -> V_29 ;
V_12 -> V_38 = V_11 -> V_39 ;
V_12 -> V_40 = V_11 -> V_40 ;
V_12 -> V_17 = V_8 -> V_17 ;
V_12 -> V_41 = V_8 -> V_28 -> V_41 ;
F_11 ( & V_12 -> V_32 ) ;
F_11 ( & V_12 -> V_33 -> V_42 ) ;
F_12 ( V_1 -> V_27 , V_8 -> V_28 -> V_29 , V_12 ) ;
if( F_13 ( & V_43 ) == abs ( V_12 -> V_29 ) ) {
F_14 ( & V_1 -> V_44 ) ;
return 1 ;
} else {
return 0 ;
}
}
static T_9
F_15 ( T_10 V_45 , T_10 V_3 )
{
T_1 * V_1 = ( T_1 * ) V_3 ;
T_6 * V_12 = ( T_6 * ) V_45 , * V_13 ;
T_11 V_46 ;
T_12 V_47 ;
T_2 * V_8 = ( T_2 * ) F_16 ( sizeof( T_2 ) ) ;
V_8 -> V_28 = ( V_48 * ) F_16 ( sizeof( V_48 ) ) ;
V_8 -> V_28 -> V_29 = V_12 -> V_29 ;
V_13 = ( T_6 * ) F_8 ( V_1 -> V_49 , V_12 -> V_38 ) ;
if( V_13 == NULL ) {
if( ( V_1 -> V_50 == FALSE ) && ( V_1 -> V_51 > V_52 ) && ( V_1 -> V_53 < V_54 ) ) {
V_1 -> V_53 ++ ;
V_1 -> V_55 = V_12 -> V_29 ;
} else if( V_1 -> V_53 < V_54 ) {
V_1 -> V_53 = 0 ;
V_1 -> V_55 = V_56 ;
}
V_1 -> V_50 = FALSE ;
V_12 -> V_33 -> V_36 = 1 ;
F_12 ( V_1 -> V_49 , V_12 -> V_38 , V_12 ) ;
} else {
if( ( V_1 -> V_50 || ( V_52 == 0 ) ) && ( V_1 -> V_51 < V_52 || ( V_52 == 0 ) ) ) {
if( ( V_52 == 0 ) && ( V_1 -> V_51 != 0 ) ) {
} else {
V_1 -> V_51 ++ ;
V_1 -> V_57 = V_13 -> V_29 ;
V_1 -> V_58 = V_12 -> V_29 ;
}
} else if( V_1 -> V_51 < V_52 ) {
V_1 -> V_51 = 0 ;
V_1 -> V_57 = V_56 ;
}
V_1 -> V_50 = TRUE ;
V_12 -> V_33 -> V_36 = V_13 -> V_33 -> V_36 + 1 ;
if( V_13 -> V_33 -> V_37 != V_12 -> V_33 -> V_37 ) {
V_12 -> V_33 -> V_37 = V_59 ;
V_13 -> V_33 -> V_37 = V_59 ;
}
V_12 -> V_33 -> V_35 = V_13 ;
if( V_12 -> V_33 -> V_36 == V_60 ) {
F_17 ( & V_46 , & V_12 -> V_41 , & V_13 -> V_41 ) ;
F_11 ( & V_13 -> V_46 ) ;
F_18 ( & V_13 -> V_46 , & V_46 ) ;
F_11 ( & V_12 -> V_46 ) ;
F_18 ( & V_12 -> V_46 , & V_46 ) ;
F_19 ( & V_1 -> V_61 , & V_46 , V_8 ) ;
}
F_12 ( V_1 -> V_49 , V_12 -> V_38 , V_12 ) ;
}
if( V_62 && ( V_12 -> V_29 < V_63 ) ) {
for( V_47 = 0 ; V_47 < V_1 -> V_64 -> V_16 ; V_47 ++ ) {
if( F_20 ( V_1 -> V_64 , V_23 , V_47 ) == V_12 -> V_40 ) {
return FALSE ;
}
}
F_21 ( V_1 -> V_64 , V_12 -> V_40 ) ;
}
return FALSE ;
}
static T_9
F_22 ( T_10 V_45 , T_10 V_3 )
{
T_1 * V_1 = ( T_1 * ) V_3 ;
T_6 * V_12 = ( T_6 * ) V_45 , * V_13 ;
V_13 = ( T_6 * ) F_8 ( V_1 -> V_65 , V_12 -> V_38 ) ;
if( V_13 == NULL ) {
if( V_62 == FALSE ) {
if( ( F_23 ( & V_1 -> V_6 , & V_12 -> V_17 ) ) || ( F_23 ( & V_1 -> V_4 , & V_12 -> V_17 ) ) ) {
F_12 ( V_1 -> V_65 , V_12 -> V_38 , V_12 ) ;
V_12 -> V_32 = V_1 -> V_32 ;
V_1 -> V_32 . V_66 = V_1 -> V_32 . V_66 + V_60 ;
} else {
V_1 -> V_32 . V_66 ++ ;
F_12 ( V_1 -> V_65 , V_12 -> V_38 , V_12 ) ;
V_12 -> V_32 = V_1 -> V_32 ;
V_1 -> V_32 . V_66 ++ ;
}
} else {
if( ( F_20 ( V_1 -> V_64 , V_23 , 0 ) == V_12 -> V_40 ) || ( F_20 ( V_1 -> V_64 , V_23 , 1 ) == V_12 -> V_40 ) ) {
F_12 ( V_1 -> V_65 , V_12 -> V_38 , V_12 ) ;
V_12 -> V_32 = V_1 -> V_32 ;
V_1 -> V_32 . V_66 = V_1 -> V_32 . V_66 + V_60 ;
} else {
V_1 -> V_32 . V_66 ++ ;
F_12 ( V_1 -> V_65 , V_12 -> V_38 , V_12 ) ;
V_12 -> V_32 = V_1 -> V_32 ;
V_1 -> V_32 . V_66 ++ ;
}
}
} else {
if( V_62 == FALSE ) {
if( ( ( F_23 ( & V_1 -> V_6 , & V_12 -> V_17 ) ) || ( F_23 ( & V_1 -> V_4 , & V_12 -> V_17 ) ) ) && ( ! fmod ( V_13 -> V_32 . V_66 , V_60 ) ) ) {
V_12 -> V_32 . V_66 = V_13 -> V_32 . V_66 ;
} else {
V_12 -> V_32 . V_66 = V_13 -> V_32 . V_66 + 1 ;
}
} else {
if( ( ( F_20 ( V_1 -> V_64 , V_23 , 0 ) == V_12 -> V_40 ) || ( F_20 ( V_1 -> V_64 , V_23 , 1 ) == V_12 -> V_40 ) ) && ( ! fmod ( V_13 -> V_32 . V_66 , V_60 ) ) ) {
V_12 -> V_32 . V_66 = V_13 -> V_32 . V_66 ;
} else {
V_12 -> V_32 . V_66 = V_13 -> V_32 . V_66 + 1 ;
}
}
}
if( fmod ( V_12 -> V_32 . V_66 , V_60 ) ) {
V_1 -> V_67 ++ ;
} else {
V_1 -> V_68 ++ ;
}
if( ! F_24 ( & V_1 -> V_44 ) ) {
V_12 -> V_33 -> V_42 . V_66 = V_1 -> V_44 . V_66 ;
}
V_1 -> V_44 . V_66 = V_12 -> V_32 . V_66 ;
return FALSE ;
}
static T_9
F_25 ( T_10 V_45 , T_10 V_3 )
{
T_1 * V_1 = ( T_1 * ) V_3 ;
T_6 * V_12 = ( T_6 * ) V_45 , * V_13 = NULL ;
T_13 V_69 = V_1 -> V_67 + V_1 -> V_68 , V_70 ;
if( ( V_12 -> V_29 == V_69 ) && ( V_1 -> V_55 != V_56 ) ) {
V_70 = V_1 -> V_55 ;
V_1 -> V_55 = V_69 - V_1 -> V_68 ;
V_1 -> V_71 = V_70 ;
}
if( ( V_12 -> V_29 == V_69 ) && ( V_1 -> V_55 == V_56 ) && ( V_1 -> V_57 != V_56 ) ) {
V_13 = ( T_6 * ) F_8 ( V_1 -> V_27 , V_1 -> V_57 ) ;
if( V_13 == NULL ) {
fprintf ( V_72 , L_3 ) ;
}
if( V_13 && fmod ( V_13 -> V_32 . V_66 , 2 ) ) {
V_1 -> V_55 = V_1 -> V_57 + abs ( V_1 -> V_68 - ( V_1 -> V_58 - V_1 -> V_67 ) ) ;
if( V_1 -> V_55 > ( V_69 - V_1 -> V_68 ) ) {
V_1 -> V_55 = V_69 - V_1 -> V_68 ;
}
if( V_1 -> V_55 > V_1 -> V_58 ) {
V_1 -> V_55 = V_1 -> V_58 - 1 ;
}
V_13 = ( T_6 * ) F_8 ( V_1 -> V_27 , V_1 -> V_55 ) ;
while( ( V_13 != NULL ) ? fmod ( ! V_13 -> V_32 . V_66 , 2 ) : TRUE ) {
V_1 -> V_55 -- ;
V_13 = ( T_6 * ) F_8 ( V_1 -> V_27 , V_1 -> V_55 ) ;
}
} else {
V_1 -> V_55 = V_1 -> V_67 + V_1 -> V_57 ;
if( V_1 -> V_55 > V_69 - V_1 -> V_67 ) {
V_1 -> V_55 = V_69 - V_1 -> V_67 ;
}
V_13 = ( T_6 * ) F_8 ( V_1 -> V_27 , V_1 -> V_55 ) ;
while( ( V_13 != NULL ) ? fmod ( V_13 -> V_32 . V_66 , 2 ) : TRUE ) {
V_1 -> V_55 -- ;
V_13 = ( T_6 * ) F_8 ( V_1 -> V_27 , V_1 -> V_55 ) ;
}
}
V_1 -> V_71 = V_1 -> V_58 + abs ( V_1 -> V_55 - V_1 -> V_57 ) ;
if( V_1 -> V_71 > V_69 ) {
V_1 -> V_71 = V_69 ;
}
}
if( V_12 -> V_29 == V_69 && V_52 != 0 && V_54 != 0 ) {
if( V_1 -> V_57 == V_56 ) {
F_26 ( L_4 ) ;
}
}
return FALSE ;
}
static T_9
F_27 ( T_10 V_45 , T_10 V_73 )
{
T_6 * V_12 = ( T_6 * ) V_45 ;
T_1 * V_1 = ( T_1 * ) V_73 ;
T_14 V_46 , V_74 ;
T_9 V_75 = FALSE ;
V_46 = fabs ( F_28 ( & V_12 -> V_46 , 1 ) ) ;
V_74 = fabs ( F_28 ( & V_1 -> V_61 . V_76 , V_1 -> V_61 . V_29 ) ) ;
if( V_52 != 0 && V_54 != 0 ) {
if( ( V_1 -> V_57 < V_12 -> V_29 ) && ( V_1 -> V_55 > V_12 -> V_29 ) ) {
V_75 = TRUE ;
} else {
if( ( V_12 -> V_29 > V_1 -> V_58 ) && ( V_12 -> V_29 < V_1 -> V_71 ) ) {
V_75 = TRUE ;
}
}
} else {
V_75 = TRUE ;
}
if( V_75 ) {
if( ( V_12 -> V_33 -> V_36 < V_60 ) ) {
F_29 ( F_30 ( F_31 ( F_32 ( V_1 -> V_77 ) ) ) , & V_1 -> V_78 , NULL ) ;
F_33 ( F_30 ( F_31 ( F_32 ( V_1 -> V_77 ) ) ) , & V_1 -> V_78 , V_79 , V_12 -> V_38 , V_80 , L_5 , V_81 , V_12 -> V_33 -> V_36 , V_82 , 0.0 , - 1 ) ;
}
if( V_12 -> V_33 -> V_36 > V_60 ) {
F_29 ( F_30 ( F_31 ( F_32 ( V_1 -> V_77 ) ) ) , & V_1 -> V_78 , NULL ) ;
F_33 ( F_30 ( F_31 ( F_32 ( V_1 -> V_77 ) ) ) , & V_1 -> V_78 , V_79 , V_12 -> V_38 , V_80 , L_6 , V_81 , V_12 -> V_33 -> V_36 , V_82 , 0.0 , - 1 ) ;
if( V_12 -> V_33 -> V_37 == V_59 ) {
F_29 ( F_30 ( F_31 ( F_32 ( V_1 -> V_77 ) ) ) , & V_1 -> V_83 , & V_1 -> V_78 ) ;
F_33 ( F_30 ( F_31 ( F_32 ( V_1 -> V_77 ) ) ) , & V_1 -> V_83 , V_79 , V_12 -> V_38 , V_80 , L_7 , V_81 , V_12 -> V_33 -> V_36 , V_82 , 0.0 , - 1 ) ;
}
}
if( V_12 -> V_33 -> V_36 == V_60 ) {
if( V_12 -> V_33 -> V_37 == V_59 ) {
F_29 ( F_30 ( F_31 ( F_32 ( V_1 -> V_77 ) ) ) , & V_1 -> V_78 , NULL ) ;
F_33 ( F_30 ( F_31 ( F_32 ( V_1 -> V_77 ) ) ) , & V_1 -> V_78 , V_79 , V_12 -> V_38 , V_80 , L_7 , V_81 , V_12 -> V_33 -> V_36 , V_82 , V_46 , - 1 ) ;
if( ( ( V_46 < ( V_74 - V_1 -> V_61 . V_84 ) ) || ( V_46 > ( V_74 + V_1 -> V_61 . V_84 ) ) ) && ( V_46 > 0.0 ) && ( V_1 -> V_61 . V_84 != 0 ) ) {
F_29 ( F_30 ( F_31 ( F_32 ( V_1 -> V_77 ) ) ) , & V_1 -> V_83 , & V_1 -> V_78 ) ;
F_33 ( F_30 ( F_31 ( F_32 ( V_1 -> V_77 ) ) ) , & V_1 -> V_83 , V_79 , V_12 -> V_38 , V_80 , L_8 , V_81 , V_12 -> V_33 -> V_36 , V_82 , V_46 , - 1 ) ;
}
if( ( F_34 ( & V_12 -> V_33 -> V_42 , & V_12 -> V_32 ) > 0 || F_34 ( & V_12 -> V_33 -> V_35 -> V_33 -> V_42 , & V_12 -> V_33 -> V_35 -> V_32 ) > 0 ) && ( V_12 -> V_32 . V_66 != V_60 ) && V_85 ) {
F_29 ( F_30 ( F_31 ( F_32 ( V_1 -> V_77 ) ) ) , & V_1 -> V_83 , & V_1 -> V_78 ) ;
F_33 ( F_30 ( F_31 ( F_32 ( V_1 -> V_77 ) ) ) , & V_1 -> V_83 , V_79 , V_12 -> V_38 , V_80 , L_9 , V_81 , V_12 -> V_33 -> V_36 , V_82 , V_46 , - 1 ) ;
}
} else if( ( ( V_46 < ( V_74 - V_1 -> V_61 . V_84 ) ) || ( V_46 > ( V_74 + V_1 -> V_61 . V_84 ) ) ) && ( V_46 > 0.0 ) && ( V_1 -> V_61 . V_84 != 0 ) ) {
F_29 ( F_30 ( F_31 ( F_32 ( V_1 -> V_77 ) ) ) , & V_1 -> V_78 , NULL ) ;
F_33 ( F_30 ( F_31 ( F_32 ( V_1 -> V_77 ) ) ) , & V_1 -> V_78 , V_79 , V_12 -> V_38 , V_80 , L_8 , V_81 , V_12 -> V_33 -> V_36 , V_82 , V_46 , - 1 ) ;
if( ( F_34 ( & V_12 -> V_33 -> V_42 , & V_12 -> V_32 ) > 0 || F_34 ( & V_12 -> V_33 -> V_35 -> V_33 -> V_42 , & V_12 -> V_33 -> V_35 -> V_32 ) > 0 ) && V_12 -> V_32 . V_66 != V_60 && V_85 ) {
F_29 ( F_30 ( F_31 ( F_32 ( V_1 -> V_77 ) ) ) , & V_1 -> V_83 , & V_1 -> V_78 ) ;
F_33 ( F_30 ( F_31 ( F_32 ( V_1 -> V_77 ) ) ) , & V_1 -> V_83 , V_79 , V_12 -> V_38 , V_80 , L_9 , V_81 , V_12 -> V_33 -> V_36 , V_82 , V_46 , - 1 ) ;
}
} else if( ( F_34 ( & V_12 -> V_33 -> V_42 , & V_12 -> V_32 ) > 0 || F_34 ( & V_12 -> V_33 -> V_35 -> V_33 -> V_42 , & V_12 -> V_33 -> V_35 -> V_32 ) > 0 ) && V_12 -> V_32 . V_66 != V_60 && V_85 ) {
F_29 ( F_30 ( F_31 ( F_32 ( V_1 -> V_77 ) ) ) , & V_1 -> V_78 , NULL ) ;
F_33 ( F_30 ( F_31 ( F_32 ( V_1 -> V_77 ) ) ) , & V_1 -> V_78 , V_79 , V_12 -> V_38 , V_80 , L_9 , V_81 , V_12 -> V_33 -> V_36 , V_82 , V_46 , - 1 ) ;
}
}
}
return FALSE ;
}
static void
F_35 ( T_15 * V_2 V_9 , T_10 V_25 )
{
T_1 * V_1 = ( T_1 * ) V_25 ;
F_36 ( V_1 ) ;
V_86 = TRUE ;
F_5 ( V_1 -> V_7 ) ;
F_37 ( V_1 ) ;
}
static void
F_38 ( void * V_3 )
{
T_1 * V_1 = ( T_1 * ) V_3 ;
T_16 * V_87 = F_39 ( L_10 ) ;
const T_17 * V_88 ;
T_6 * V_12 ;
T_13 V_67 , V_68 ;
V_1 -> V_32 . V_89 = 0 ;
V_1 -> V_32 . V_66 = 1 ;
F_14 ( & V_1 -> V_44 ) ;
V_1 -> V_64 = F_40 ( FALSE , FALSE , sizeof( V_23 ) ) ;
V_1 -> V_50 = FALSE ;
V_1 -> V_51 = 0 ;
V_1 -> V_53 = 0 ;
V_1 -> V_57 = V_56 ;
V_1 -> V_58 = V_56 ;
V_1 -> V_55 = V_56 ;
V_1 -> V_71 = V_56 ;
V_1 -> V_67 = 0 ;
V_1 -> V_68 = 0 ;
F_41 ( & V_1 -> V_61 ) ;
if( F_13 ( & V_43 ) == 0 ) {
V_88 = F_42 ( L_11 ) ;
F_43 ( ( V_90 * ) V_1 -> V_91 , V_88 ) ;
return;
}
V_1 -> V_49 = F_44 ( V_92 , L_12 ) ;
F_45 ( V_1 -> V_27 , F_15 , V_1 ) ;
if( V_62 && V_1 -> V_64 -> V_16 == 1 ) {
F_21 ( V_1 -> V_64 , F_20 ( V_1 -> V_64 , V_23 , 1 ) ) ;
}
F_45 ( V_1 -> V_27 , F_22 , V_1 ) ;
F_45 ( V_1 -> V_27 , F_25 , V_1 ) ;
V_67 = V_1 -> V_67 ;
V_68 = V_1 -> V_68 ;
V_1 -> V_65 = F_44 ( V_92 , L_13 ) ;
F_46 ( V_93 ) ;
F_14 ( & V_1 -> V_44 ) ;
if( V_62 && V_1 -> V_64 -> V_16 != 0 ) {
F_47 ( V_87 , L_14 , L_15 , F_20 ( V_1 -> V_64 , V_23 , 0 ) , L_16 , F_20 ( V_1 -> V_64 , V_23 , 1 ) ) ;
} else if( V_1 -> V_6 . V_16 != 0 && V_1 -> V_4 . V_16 != 0 ) {
F_47 ( V_87 , L_17 , L_18 , F_48 ( & V_1 -> V_6 ) , L_19 , F_48 ( & V_1 -> V_4 ) ) ;
}
F_49 ( V_94 , V_87 -> V_95 , FALSE ) ;
F_50 () ;
V_1 -> V_61 . V_84 = V_96 ;
V_88 = F_42 ( L_20 , F_13 ( & V_43 ) , V_67 , V_68 , V_1 -> V_57 , V_1 -> V_55 , V_1 -> V_58 , V_1 -> V_71 , V_1 -> V_61 . V_29 , V_1 -> V_61 . V_84 , fabs ( F_28 ( & V_1 -> V_61 . V_76 , V_1 -> V_61 . V_29 ) ) ) ;
F_43 ( ( V_90 * ) V_1 -> V_91 , V_88 ) ;
if( V_1 -> V_57 != V_56 && V_52 != 0 && V_54 != 0 ) {
V_12 = ( T_6 * ) F_8 ( V_1 -> V_27 , V_1 -> V_57 ) ;
if( V_12 ) {
F_29 ( F_30 ( F_31 ( F_32 ( V_1 -> V_77 ) ) ) , & V_1 -> V_78 , NULL ) ;
F_33 ( F_30 ( F_31 ( F_32 ( V_1 -> V_77 ) ) ) , & V_1 -> V_78 , V_79 , V_12 -> V_38 , V_80 , L_21 , V_81 , 0 , V_82 , 0.0 , - 1 ) ;
}
}
if( V_1 -> V_55 != V_56 && V_52 != 0 && V_54 != 0 ) {
V_12 = ( T_6 * ) F_8 ( V_1 -> V_27 , V_1 -> V_55 ) ;
if( V_12 ) {
F_29 ( F_30 ( F_31 ( F_32 ( V_1 -> V_77 ) ) ) , & V_1 -> V_78 , NULL ) ;
F_33 ( F_30 ( F_31 ( F_32 ( V_1 -> V_77 ) ) ) , & V_1 -> V_78 , V_79 , V_12 -> V_38 , V_80 , L_22 , V_81 , 0 , V_82 , 0.0 , - 1 ) ;
}
}
F_45 ( V_1 -> V_49 , F_27 , V_1 ) ;
F_51 ( V_87 , TRUE ) ;
F_52 ( V_1 -> V_64 , TRUE ) ;
}
static void
F_53 ( T_18 * V_97 , T_10 V_73 )
{
T_17 * V_98 ;
T_19 * V_99 ;
T_20 V_78 ;
T_6 * V_12 ;
T_21 V_38 = - 1 ;
T_1 * V_1 = ( T_1 * ) V_73 ;
if( F_54 ( V_97 , & V_99 , & V_78 ) ) {
F_55 ( V_99 , & V_78 , 0 , & V_38 , 1 , & V_98 , - 1 ) ;
if ( V_38 < 0 ) return;
if( strcmp ( L_21 , V_98 ) == 0 ) {
F_56 ( & V_43 , V_1 -> V_57 ) ;
return;
}
if( strcmp ( L_22 , V_98 ) == 0 ) {
F_56 ( & V_43 , V_1 -> V_55 ) ;
return;
}
V_12 = ( T_6 * ) F_8 ( V_1 -> V_49 , V_38 ) ;
if( V_12 != NULL ) {
F_56 ( & V_43 , V_12 -> V_29 ) ;
}
}
}
static void
F_57 ( T_22 * V_77 )
{
T_23 * V_100 ;
T_24 * V_101 ;
V_100 = F_58 () ;
V_101 = F_59 ( L_23 , V_100 , L_24 , V_79 , NULL ) ;
F_60 ( F_32 ( V_77 ) , V_101 ) ;
V_100 = F_58 () ;
V_101 = F_59 ( L_25 , V_100 , L_24 , V_80 , NULL ) ;
F_60 ( F_32 ( V_77 ) , V_101 ) ;
V_100 = F_58 () ;
V_101 = F_59 ( L_26 , V_100 , L_24 , V_81 , NULL ) ;
F_60 ( F_32 ( V_77 ) , V_101 ) ;
V_100 = F_58 () ;
V_101 = F_59 ( L_27 , V_100 , L_24 , V_82 , NULL ) ;
F_60 ( F_32 ( V_77 ) , V_101 ) ;
}
static void
F_61 ( const char * V_102 , void * T_25 V_9 )
{
T_1 * V_1 ;
char * V_103 ;
char * V_104 ;
char * V_105 ;
T_22 * V_106 ;
T_22 * V_107 ;
T_22 * V_108 ;
T_22 * V_109 ;
T_22 * V_110 ;
T_22 * V_111 ;
T_14 V_84 ;
T_21 V_112 , V_113 , V_114 , V_115 , V_116 = 0 ;
const char * V_117 = NULL ;
T_16 * V_118 ;
if( sscanf ( V_102 , L_28 , & V_112 , & V_113 , & V_114 , & V_115 , & V_84 , & V_116 ) == 5 ) {
if( V_116 ) {
if( * ( V_102 + V_116 ) == ',' )
V_117 = V_102 + V_116 + 1 ;
else
V_117 = V_102 + V_116 ;
} else {
V_117 = NULL ;
}
} else {
fprintf ( V_72 , L_29 ) ;
exit ( 1 ) ;
}
V_96 = V_84 ;
V_52 = V_112 ;
V_54 = V_113 ;
V_62 = V_114 ;
V_85 = V_115 ;
V_1 = ( T_1 * ) F_62 ( sizeof( T_1 ) ) ;
F_14 ( & V_1 -> V_44 ) ;
V_1 -> V_64 = F_40 ( FALSE , FALSE , sizeof( V_23 ) ) ;
V_1 -> V_50 = FALSE ;
V_1 -> V_51 = 0 ;
V_1 -> V_53 = 0 ;
V_1 -> V_57 = V_56 ;
V_1 -> V_58 = V_56 ;
V_1 -> V_55 = V_56 ;
V_1 -> V_71 = V_56 ;
V_1 -> V_67 = 0 ;
V_1 -> V_68 = 0 ;
V_1 -> V_32 . V_89 = 0 ;
V_1 -> V_32 . V_66 = 1 ;
V_1 -> V_65 = F_44 ( V_92 , L_13 ) ;
F_46 ( V_93 ) ;
V_1 -> V_2 = F_63 ( L_30 ) ;
F_64 ( F_65 ( V_1 -> V_2 ) , TRUE ) ;
F_66 ( F_65 ( V_1 -> V_2 ) , 550 , 400 ) ;
F_1 ( V_1 ) ;
V_111 = F_67 ( V_119 , 3 , FALSE ) ;
F_68 ( F_69 ( V_1 -> V_2 ) , V_111 ) ;
F_70 ( F_69 ( V_111 ) , 12 ) ;
V_103 = F_71 ( & V_43 ) ;
V_104 = F_42 ( L_31 , V_103 ) ;
F_37 ( V_103 ) ;
V_106 = F_72 ( V_104 ) ;
F_37 ( V_104 ) ;
F_73 ( F_74 ( V_111 ) , V_106 , FALSE , FALSE , 0 ) ;
V_105 = F_42 ( L_32 , V_117 ? V_117 : L_10 ) ;
V_107 = F_72 ( V_105 ) ;
F_37 ( V_105 ) ;
F_75 ( F_76 ( V_107 ) , TRUE ) ;
F_73 ( F_74 ( V_111 ) , V_107 , FALSE , FALSE , 0 ) ;
V_1 -> V_91 = F_72 ( L_33 ) ;
F_75 ( F_76 ( V_1 -> V_91 ) , TRUE ) ;
F_73 ( F_74 ( V_111 ) , V_1 -> V_91 , FALSE , FALSE , 0 ) ;
F_77 ( V_1 -> V_2 ) ;
V_1 -> V_77 = F_78 () ;
F_57 ( V_1 -> V_77 ) ;
V_1 -> V_7 = F_79 ( V_120 , V_121 , V_122 , V_121 , V_123 ) ;
F_80 ( F_32 ( V_1 -> V_77 ) , F_81 ( V_1 -> V_7 ) ) ;
F_82 ( V_1 -> V_7 ) ;
F_83 ( F_84 ( F_32 ( V_1 -> V_77 ) ) , V_124 ) ;
F_85 ( F_84 ( F_32 ( V_1 -> V_77 ) ) , L_34 , F_86 ( F_53 ) , V_1 ) ;
V_1 -> V_125 = F_87 ( NULL , NULL ) ;
F_88 ( F_89 ( V_1 -> V_125 ) , V_126 , V_126 ) ;
F_68 ( F_69 ( V_1 -> V_125 ) , V_1 -> V_77 ) ;
F_73 ( F_74 ( V_111 ) , V_1 -> V_125 , TRUE , TRUE , 0 ) ;
V_1 -> V_27 = F_44 ( V_92 , L_35 ) ;
V_118 = F_90 ( L_36 , V_1 , V_117 , 0 , F_3 , F_6 , F_38 ) ;
if( V_118 ) {
F_91 ( V_127 , V_128 , L_37 , V_118 -> V_95 ) ;
F_51 ( V_118 , TRUE ) ;
F_5 ( V_1 -> V_7 ) ;
F_37 ( V_1 ) ;
return;
}
V_108 = F_92 ( V_129 , V_130 , NULL ) ;
F_93 ( F_74 ( V_111 ) , V_108 , FALSE , FALSE , 0 ) ;
V_109 = ( T_22 * ) F_94 ( F_95 ( V_108 ) , V_129 ) ;
F_96 ( V_1 -> V_2 , V_109 , V_131 ) ;
V_110 = ( T_22 * ) F_94 ( F_95 ( V_108 ) , V_130 ) ;
F_85 ( V_110 , L_38 , F_86 ( V_132 ) , ( T_10 ) V_133 ) ;
F_85 ( V_1 -> V_2 , L_39 , F_86 ( V_134 ) , NULL ) ;
F_85 ( V_1 -> V_2 , L_40 , F_86 ( F_35 ) , V_1 ) ;
F_77 ( V_1 -> V_2 ) ;
F_97 ( V_1 -> V_2 ) ;
F_98 ( & V_43 ) ;
}
static void
F_99 ( T_22 * T_26 V_9 , T_10 V_25 V_9 )
{
T_16 * V_95 ;
const char * V_117 ;
V_52 = F_100 ( F_101 ( V_135 ) ) ;
V_54 = F_100 ( F_101 ( V_136 ) ) ;
V_96 = F_102 ( F_101 ( V_137 ) ) ;
if( F_103 ( F_104 ( V_138 ) ) ) {
V_62 = TRUE ;
} else {
V_62 = FALSE ;
}
if( F_103 ( F_104 ( V_139 ) ) ) {
V_85 = TRUE ;
} else {
V_85 = FALSE ;
}
V_95 = F_39 ( L_41 ) ;
F_105 ( V_95 , L_42 , V_52 , V_54 , V_62 , V_85 , V_96 ) ;
V_117 = F_106 ( F_107 ( V_140 ) ) ;
if( V_117 [ 0 ] != 0 ) {
F_105 ( V_95 , L_43 , V_117 ) ;
}
if( V_86 ) {
V_86 = FALSE ;
F_61 ( V_95 -> V_95 , NULL ) ;
} else {
F_26 ( L_44 ) ;
}
F_51 ( V_95 , TRUE ) ;
}
static void
F_108 ( T_22 * T_27 V_9 , T_10 V_73 V_9 )
{
V_141 = NULL ;
}
void
F_109 ( T_28 * T_29 V_9 , T_10 V_73 V_9 )
{
T_30 * V_142 , * V_143 , * V_144 ;
T_22 * V_145 ;
T_22 * V_146 , * V_147 , * V_148 , * V_149 ;
T_22 * V_150 , * V_151 ;
T_22 * V_152 , * V_153 , * V_154 ;
T_22 * V_155 , * V_156 , * V_157 ;
T_22 * V_158 , * V_159 ;
T_22 * V_108 , * V_160 , * V_161 ;
const char * V_117 ;
static T_31 args = {
L_45 ,
TRUE ,
FALSE ,
FALSE
} ;
if( V_141 ) {
F_110 ( F_111 ( V_141 ) ) ;
return;
}
V_141 = F_63 ( L_46 ) ;
F_66 ( F_65 ( V_141 ) , 300 , - 1 ) ;
V_145 = F_67 ( V_119 , 10 , FALSE ) ;
F_70 ( F_69 ( V_145 ) , 10 ) ;
F_68 ( F_69 ( V_141 ) , V_145 ) ;
F_112 ( V_145 ) ;
V_148 = F_67 ( V_162 , 10 , FALSE ) ;
V_149 = F_67 ( V_162 , 10 , FALSE ) ;
F_70 ( F_69 ( V_148 ) , 1 ) ;
V_146 = F_72 ( L_47 ) ;
F_73 ( F_74 ( V_148 ) , V_146 , FALSE , FALSE , 0 ) ;
F_112 ( V_146 ) ;
F_70 ( F_69 ( V_149 ) , 1 ) ;
V_147 = F_72 ( L_48 ) ;
F_73 ( F_74 ( V_149 ) , V_147 , FALSE , FALSE , 0 ) ;
F_112 ( V_147 ) ;
V_142 = F_113 ( F_114 ( 0.0 , 0.0 , 100.0 , 1.0 , 5.0 , 0.0 ) ) ;
V_143 = F_113 ( F_114 ( 0.0 , 0.0 , 100.0 , 1.0 , 5.0 , 0.0 ) ) ;
V_135 = F_115 ( V_142 , 1.0 , 0 ) ;
V_136 = F_115 ( V_143 , 1.0 , 0 ) ;
F_73 ( F_74 ( V_148 ) , V_135 , TRUE , TRUE , 0 ) ;
F_73 ( F_74 ( V_149 ) , V_136 , TRUE , TRUE , 0 ) ;
F_73 ( F_74 ( V_145 ) , V_148 , FALSE , FALSE , 0 ) ;
F_112 ( V_148 ) ;
F_73 ( F_74 ( V_145 ) , V_149 , FALSE , FALSE , 0 ) ;
F_112 ( V_149 ) ;
V_155 = F_67 ( V_162 , 10 , FALSE ) ;
F_70 ( F_69 ( V_155 ) , 1 ) ;
V_157 = F_72 ( L_49 ) ;
F_73 ( F_74 ( V_155 ) , V_157 , FALSE , FALSE , 0 ) ;
F_112 ( V_157 ) ;
V_153 = F_116 ( NULL , L_50 ) ;
V_138 = F_117 ( F_118 ( V_153 ) , L_51 ) ;
F_73 ( F_74 ( V_155 ) , V_153 , TRUE , TRUE , 0 ) ;
F_73 ( F_74 ( V_155 ) , V_138 , TRUE , TRUE , 0 ) ;
F_112 ( V_153 ) ;
F_112 ( V_138 ) ;
F_73 ( F_74 ( V_145 ) , V_155 , FALSE , FALSE , 0 ) ;
F_112 ( V_155 ) ;
V_152 = F_67 ( V_162 , 10 , FALSE ) ;
F_70 ( F_69 ( V_152 ) , 1 ) ;
V_154 = F_72 ( L_52 ) ;
F_73 ( F_74 ( V_152 ) , V_154 , FALSE , FALSE , 0 ) ;
F_112 ( V_154 ) ;
V_139 = F_116 ( NULL , L_53 ) ;
V_156 = F_117 ( F_118 ( V_139 ) , L_54 ) ;
F_73 ( F_74 ( V_152 ) , V_139 , TRUE , TRUE , 0 ) ;
F_73 ( F_74 ( V_152 ) , V_156 , TRUE , TRUE , 0 ) ;
F_112 ( V_139 ) ;
F_112 ( V_156 ) ;
F_73 ( F_74 ( V_145 ) , V_152 , FALSE , FALSE , 0 ) ;
F_112 ( V_152 ) ;
V_150 = F_67 ( V_162 , 10 , FALSE ) ;
F_70 ( F_69 ( V_150 ) , 1 ) ;
V_151 = F_72 ( L_55 ) ;
F_73 ( F_74 ( V_150 ) , V_151 , FALSE , FALSE , 0 ) ;
F_112 ( V_151 ) ;
V_144 = F_113 ( F_114 ( 0.0 , 0.0 , 100.0 , 1.0 , 5.0 , 0.0 ) ) ;
V_137 = F_115 ( V_144 , 0.0 , 2 ) ;
F_73 ( F_74 ( V_150 ) , V_137 , TRUE , TRUE , 0 ) ;
F_112 ( V_137 ) ;
F_73 ( F_74 ( V_145 ) , V_150 , FALSE , FALSE , 0 ) ;
F_112 ( V_150 ) ;
V_158 = F_67 ( V_162 , 3 , FALSE ) ;
V_159 = F_119 ( V_163 ) ;
F_85 ( V_159 , L_38 , F_86 ( V_164 ) , & args ) ;
F_73 ( F_74 ( V_158 ) , V_159 , FALSE , TRUE , 0 ) ;
F_112 ( V_159 ) ;
V_140 = F_120 () ;
F_85 ( V_140 , L_34 , F_86 ( V_165 ) , NULL ) ;
F_121 ( F_95 ( V_158 ) , V_166 , NULL ) ;
F_85 ( V_140 , L_56 , F_86 ( V_167 ) , NULL ) ;
F_85 ( V_141 , L_56 , F_86 ( V_168 ) , NULL ) ;
F_121 ( F_95 ( V_159 ) , V_169 , V_140 ) ;
F_73 ( F_74 ( V_158 ) , V_140 , TRUE , TRUE , 0 ) ;
V_117 = F_106 ( F_107 ( V_170 ) ) ;
if( V_117 ) {
F_122 ( F_107 ( V_140 ) , V_117 ) ;
}
F_112 ( V_140 ) ;
F_73 ( F_74 ( V_145 ) , V_158 , TRUE , TRUE , 0 ) ;
F_112 ( V_158 ) ;
V_108 = F_92 ( V_171 , V_172 , NULL ) ;
F_73 ( F_74 ( V_145 ) , V_108 , FALSE , FALSE , 0 ) ;
F_112 ( V_108 ) ;
V_160 = ( T_22 * ) F_94 ( F_95 ( V_108 ) , V_171 ) ;
F_123 ( V_160 , L_38 , F_86 ( F_99 ) , NULL ) ;
V_161 = ( T_22 * ) F_94 ( F_95 ( V_108 ) , V_172 ) ;
F_96 ( V_141 , V_161 , V_131 ) ;
F_124 ( V_140 ) ;
F_125 ( V_160 ) ;
F_85 ( V_141 , L_39 , F_86 ( V_134 ) , NULL ) ;
F_85 ( V_141 , L_40 , F_86 ( F_108 ) , NULL ) ;
F_77 ( V_141 ) ;
F_97 ( V_141 ) ;
}
void
F_126 ( void )
{
F_127 ( L_41 , F_61 , NULL ) ;
}
