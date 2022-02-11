static T_1 * F_1 ( T_2 * V_1 , T_3 V_2 ) {
T_1 V_3 = ( T_1 ) F_2 ( sizeof( struct V_4 ) ) ;
V_3 -> V_5 = V_2 ;
V_3 -> V_6 = NULL ;
V_3 -> V_7 = FALSE ;
return F_3 ( V_1 , V_3 ) ;
}
static T_1 * F_4 ( T_2 * V_1 , T_4 * V_6 ) {
T_1 V_3 = ( T_1 ) F_2 ( sizeof( struct V_4 ) ) ;
V_3 -> V_5 = ( T_3 ) V_6 -> V_8 ;
V_3 -> V_6 = V_6 ;
V_3 -> V_7 = FALSE ;
return F_3 ( V_1 , V_3 ) ;
}
static T_5 F_5 ( T_1 V_3 ) {
return ( V_3 -> V_6 == NULL ) ;
}
static int F_6 ( T_2 * V_1 , T_3 V_2 ) {
T_6 V_9 ;
T_7 V_10 [ V_11 ] ;
int V_12 = 0 ;
int V_13 = - 1 ;
int V_14 = 0 ;
T_5 V_15 = FALSE ;
V_13 = F_7 ( V_2 ) ;
if ( V_13 == '+' || V_13 == '-' ) {
V_10 [ V_12 ++ ] = ( T_7 ) V_13 ;
V_13 = F_7 ( V_2 ) ;
if ( V_13 < '0' || V_13 > '9' ) {
F_8 ( V_1 ) ;
return 0 ;
}
F_9 ( V_2 ) ;
}
while( ( V_13 = F_7 ( V_2 ) ) > 0 && V_12 < ( V_11 - 1 ) ) {
if ( V_13 >= '0' && V_13 <= '9' ) {
V_10 [ V_12 ++ ] = ( T_7 ) V_13 ;
V_14 ++ ;
F_9 ( V_2 ) ;
}
else if ( ! V_15 && V_13 == '.' ) {
V_15 = TRUE ;
V_10 [ V_12 ++ ] = ( T_7 ) V_13 ;
F_9 ( V_2 ) ;
}
else break;
}
V_10 [ V_12 ] = '\0' ;
if ( V_12 > 0 && V_14 > 0 && sscanf ( V_10 , L_1 , & V_9 ) == 1 ) {
F_10 ( V_1 , V_9 ) ;
return 1 ;
}
else {
F_8 ( V_1 ) ;
return 0 ;
}
}
static int F_11 ( T_2 * V_1 , T_3 V_2 ) {
static T_7 V_16 [ V_17 ] ;
T_8 V_18 = F_12 ( V_2 ) ;
T_9 V_19 = 0 ;
if ( F_13 ( V_16 , V_17 , V_2 ) == NULL ) {
return 0 ;
}
V_19 = ( T_9 ) ( F_12 ( V_2 ) - V_18 ) ;
if ( V_16 [ V_19 - 1 ] == '\n' ) {
V_19 -- ;
if ( V_19 > 0 && V_16 [ V_19 - 1 ] == '\r' ) {
V_19 -- ;
}
V_16 [ V_19 ] = '\0' ;
}
F_14 ( V_1 , V_16 , V_19 ) ;
return 1 ;
}
static int F_15 ( T_2 * V_1 , T_3 V_2 , T_10 V_20 ) {
T_10 V_21 ;
T_10 V_22 ;
int V_23 ;
T_7 V_10 [ V_24 ] ;
T_11 V_25 ;
V_21 = V_24 ;
F_16 ( V_1 , & V_25 ) ;
do {
if ( V_21 > V_20 ) V_21 = V_20 ;
V_23 = F_17 ( V_10 , ( unsigned int ) V_21 , V_2 ) ;
if ( V_23 < 1 ) break;
V_22 = ( T_10 ) V_23 ;
F_18 ( & V_25 , V_10 , V_22 ) ;
V_20 -= V_22 ;
} while ( V_20 > 0 && V_22 == V_21 );
F_19 ( & V_25 ) ;
return ( V_20 == 0 || F_20 ( V_1 , - 1 ) > 0 ) ;
}
static int F_21 ( T_2 * V_1 , T_3 V_2 ) {
if ( F_22 ( V_2 ) ) {
F_8 ( V_1 ) ;
}
else {
F_14 ( V_1 , L_2 , 0 ) ;
}
return 1 ;
}
static int F_23 ( T_2 * V_1 , int V_26 , const char * V_27 ) {
int V_28 = V_29 ;
if ( V_26 ) {
F_24 ( V_1 , 1 ) ;
return 1 ;
}
else {
F_8 ( V_1 ) ;
if ( V_27 )
F_25 ( V_1 , L_3 , V_27 , F_26 ( V_28 ) ) ;
else
F_25 ( V_1 , L_4 , F_26 ( V_28 ) ) ;
F_27 ( V_1 , V_28 ) ;
return 3 ;
}
}
T_12 F_28 ( T_2 * V_1 ) {
T_1 V_3 = F_29 ( V_1 , 1 ) ;
int V_30 = F_30 ( V_1 ) ;
int V_31 ;
int V_20 = 1 ;
T_3 V_2 = NULL ;
if ( ! V_3 || ! V_3 -> V_5 ) {
return 0 ;
}
if ( V_3 -> V_7 ) {
F_31 ( L_5 ) ;
return 0 ;
}
if ( ! F_5 ( V_3 ) ) {
F_31 ( L_6 ) ;
return 0 ;
}
V_2 = V_3 -> V_5 ;
if ( V_30 == 0 ) {
V_31 = F_11 ( V_1 , V_2 ) ;
V_20 = 2 ;
}
else {
F_32 ( V_1 , V_30 + V_32 , L_7 ) ;
V_31 = 1 ;
for ( V_20 = 1 ; V_30 -- && V_31 ; V_20 ++ ) {
if ( F_33 ( V_1 , V_20 ) == V_33 ) {
T_10 V_34 = ( T_10 ) F_34 ( V_1 , V_20 ) ;
V_31 = ( V_34 == 0 ) ? F_21 ( V_1 , V_2 ) : F_15 ( V_1 , V_2 , V_34 ) ;
}
else {
const char * V_35 = F_35 ( V_1 , V_20 ) ;
if ( ! V_35 ) return F_36 ( V_1 , V_20 , L_8 ) ;
F_37 ( V_1 , V_35 [ 0 ] == '*' , V_20 , L_9 ) ;
switch ( V_35 [ 1 ] ) {
case 'n' :
V_31 = F_6 ( V_1 , V_2 ) ;
break;
case 'l' :
V_31 = F_11 ( V_1 , V_2 ) ;
break;
case 'a' :
F_15 ( V_1 , V_2 , ~ ( ( T_10 ) 0 ) ) ;
V_31 = 1 ;
break;
default:
return F_36 ( V_1 , V_20 , L_10 ) ;
}
}
}
}
if ( F_38 ( V_2 , NULL ) )
return F_23 ( V_1 , 0 , NULL ) ;
if ( ! V_31 ) {
F_39 ( V_1 , 1 ) ;
F_8 ( V_1 ) ;
}
return V_20 - 1 ;
}
T_12 F_40 ( T_2 * V_1 ) {
static const int V_36 [] = { V_37 , V_38 , V_39 } ;
static const char * const V_40 [] = { L_11 , L_12 , L_13 , NULL } ;
T_1 V_3 = F_41 ( V_1 , 1 ) ;
int V_41 = F_42 ( V_1 , 2 , L_12 , V_40 ) ;
T_8 V_42 = ( T_8 ) F_43 ( V_1 , 3 , 0 ) ;
int V_43 = V_44 ;
if ( F_5 ( V_3 ) ) {
V_42 = F_44 ( V_3 -> V_5 , V_42 , V_36 [ V_41 ] , & V_43 ) ;
if ( V_42 < 0 ) {
F_8 ( V_1 ) ;
F_45 ( V_1 , F_46 ( V_43 ) ) ;
return 2 ;
}
F_10 ( V_1 , ( T_6 ) ( F_12 ( V_3 -> V_5 ) ) ) ;
}
else {
V_42 = F_47 ( V_3 -> V_6 , V_42 , V_36 [ V_41 ] , & V_43 ) ;
if ( V_42 < 0 ) {
F_8 ( V_1 ) ;
F_45 ( V_1 , F_46 ( V_43 ) ) ;
return 2 ;
}
V_42 = F_48 ( V_3 -> V_6 , & V_43 ) ;
if ( V_42 < 0 ) {
F_8 ( V_1 ) ;
F_45 ( V_1 , F_46 ( V_43 ) ) ;
return 2 ;
}
F_10 ( V_1 , ( T_6 ) ( V_42 ) ) ;
}
F_49 ( 1 ) ;
}
static int F_50 ( T_2 * V_1 ) {
T_3 V_2 = * ( T_3 * ) F_51 ( V_1 , F_52 ( 1 ) ) ;
int V_31 ;
if ( V_2 == NULL )
return F_53 ( V_1 , L_14 ) ;
V_31 = F_11 ( V_1 , V_2 ) ;
return V_31 ;
}
T_12 F_54 ( T_2 * V_1 ) {
T_1 V_3 = F_41 ( V_1 , 1 ) ;
T_3 V_2 = NULL ;
if ( ! V_3 -> V_5 )
return F_53 ( V_1 , L_15 ) ;
if ( ! F_5 ( V_3 ) ) {
F_31 ( L_6 ) ;
return 0 ;
}
V_2 = V_3 -> V_5 ;
F_55 ( V_1 , V_2 ) ;
F_56 ( V_1 , F_50 , 1 ) ;
return 1 ;
}
T_12 F_57 ( T_2 * V_1 ) {
T_1 V_3 = F_41 ( V_1 , 1 ) ;
int V_45 = 2 ;
int V_30 = F_30 ( V_1 ) - 1 ;
int V_46 = TRUE ;
int V_43 = 0 ;
if ( ! V_3 -> V_6 ) {
F_31 ( L_16 ) ;
return 0 ;
}
F_58 ( V_1 , 1 ) ;
for (; V_30 -- ; V_45 ++ ) {
T_10 V_47 ;
const char * V_48 = F_59 ( V_1 , V_45 , & V_47 ) ;
V_46 = F_60 ( V_3 -> V_6 , V_48 , V_47 , & V_43 ) ;
if ( ! V_46 ) break;
V_3 -> V_6 -> V_49 += V_47 ;
}
if ( ! V_46 ) {
F_39 ( V_1 , 1 ) ;
F_8 ( V_1 ) ;
F_25 ( V_1 , L_17 , F_26 ( V_43 ) ) ;
F_27 ( V_1 , V_43 ) ;
return 3 ;
}
return 1 ;
}
T_13 F_61 ( T_2 * V_1 ) {
T_1 V_3 = F_62 ( V_1 , 1 ) ;
if ( ! V_3 ) {
F_45 ( V_1 , L_18 ) ;
} else {
F_25 ( V_1 , L_19 , V_3 -> V_7 ? L_20 : L_21 , V_3 -> V_5 ? L_22 : L_23 ,
V_3 -> V_6 ? L_24 : L_25 ) ;
}
F_49 ( 1 ) ;
}
static int F_63 ( T_2 * V_1 V_50 ) {
T_1 V_3 = F_62 ( V_1 , 1 ) ;
if ( V_3 )
F_64 ( V_3 ) ;
return 0 ;
}
static int F_65 ( T_2 * V_1 ) {
T_1 V_3 = F_41 ( V_1 , 1 ) ;
if ( F_5 ( V_3 ) ) {
F_24 ( V_1 , F_66 ( V_3 -> V_5 ) ) ;
} else {
F_24 ( V_1 , V_3 -> V_6 -> V_51 ) ;
}
return 1 ;
}
int F_67 ( T_2 * V_1 ) {
F_68 ( T_1 ) ;
F_69 ( T_1 ) ;
return 0 ;
}
static void F_70 ( T_2 * V_1 , T_14 * V_52 ) {
T_15 * V_53 = ( T_15 * ) F_2 ( sizeof( T_15 ) ) ;
if ( V_52 -> V_53 != NULL ) {
F_53 ( V_1 , L_26 ) ;
return;
}
V_53 -> V_54 = V_55 ;
V_52 -> V_53 = ( void * ) V_53 ;
}
static int F_71 ( T_2 * V_1 , T_14 * V_52 ) {
T_15 * V_53 = ( T_15 * ) V_52 -> V_53 ;
if ( ! V_53 ) {
F_53 ( V_1 , L_27 ) ;
return V_55 ;
}
F_72 ( V_1 , V_56 , V_53 -> V_54 ) ;
return 1 ;
}
static int F_73 ( T_2 * V_1 , T_14 * V_52 ) {
T_15 * V_53 = ( T_15 * ) V_52 -> V_53 ;
if ( ! V_53 ) {
F_53 ( V_1 , L_27 ) ;
return 0 ;
}
if ( F_74 ( V_1 , - 1 ) ) {
F_75 ( V_1 , V_56 , V_53 -> V_54 ) ;
V_53 -> V_54 = V_55 ;
return 0 ;
}
if ( ! F_76 ( V_1 , - 1 ) ) {
F_53 ( V_1 , L_28 ) ;
return 0 ;
}
if ( V_53 -> V_54 != V_55 ) {
F_75 ( V_1 , V_56 , V_53 -> V_54 ) ;
}
V_53 -> V_54 = F_77 ( V_1 , V_56 ) ;
return 0 ;
}
static void F_78 ( T_2 * V_1 , T_14 * V_52 ) {
T_15 * V_53 = ( T_15 * ) V_52 -> V_53 ;
if ( ! V_53 ) {
F_53 ( V_1 , L_29 ) ;
return;
}
F_75 ( V_1 , V_56 , V_53 -> V_54 ) ;
F_64 ( V_52 -> V_53 ) ;
V_52 -> V_53 = NULL ;
}
static void F_79 ( T_2 * V_1 , T_4 * V_6 ) {
T_15 * V_53 = ( T_15 * ) F_2 ( sizeof( T_15 ) ) ;
if ( V_6 -> V_53 != NULL ) {
F_53 ( V_1 , L_30 ) ;
return;
}
V_53 -> V_54 = V_55 ;
V_6 -> V_53 = ( void * ) V_53 ;
}
static int F_80 ( T_2 * V_1 , T_4 * V_6 ) {
T_15 * V_53 = ( T_15 * ) V_6 -> V_53 ;
if ( ! V_53 ) {
F_53 ( V_1 , L_31 ) ;
return V_55 ;
}
F_72 ( V_1 , V_56 , V_53 -> V_54 ) ;
return 1 ;
}
static int F_81 ( T_2 * V_1 , T_4 * V_6 ) {
T_15 * V_53 = ( T_15 * ) V_6 -> V_53 ;
if ( ! V_53 ) {
F_53 ( V_1 , L_27 ) ;
return 0 ;
}
if ( F_74 ( V_1 , - 1 ) ) {
F_75 ( V_1 , V_56 , V_53 -> V_54 ) ;
V_53 -> V_54 = V_55 ;
return 0 ;
}
if ( ! F_76 ( V_1 , - 1 ) ) {
F_53 ( V_1 , L_28 ) ;
return 0 ;
}
if ( V_53 -> V_54 != V_55 ) {
F_75 ( V_1 , V_56 , V_53 -> V_54 ) ;
}
V_53 -> V_54 = F_77 ( V_1 , V_56 ) ;
return 0 ;
}
static void F_82 ( T_2 * V_1 , T_4 * V_6 ) {
T_15 * V_53 = ( T_15 * ) V_6 -> V_53 ;
if ( ! V_53 ) {
F_53 ( V_1 , L_32 ) ;
return;
}
F_75 ( V_1 , V_56 , V_53 -> V_54 ) ;
}
static T_16 * F_83 ( T_2 * V_1 , T_14 * V_52 , const T_5 V_57 ) {
T_16 V_3 = ( T_16 ) F_84 ( sizeof( struct V_58 ) ) ;
V_3 -> V_52 = V_52 ;
V_3 -> V_6 = NULL ;
V_3 -> V_7 = FALSE ;
if ( V_57 ) {
V_52 -> V_59 = V_60 ;
V_52 -> V_61 = V_62 ;
V_52 -> V_63 = 0 ;
}
return F_85 ( V_1 , V_3 ) ;
}
T_13 F_86 ( T_2 * V_1 ) {
T_16 V_64 = F_87 ( V_1 , 1 ) ;
if ( ! V_64 || ! V_64 -> V_52 ) {
F_45 ( V_1 , L_33 ) ;
} else {
T_14 * V_52 = V_64 -> V_52 ;
F_25 ( V_1 , L_34 ,
V_52 -> V_65 , V_52 -> V_63 , V_52 -> V_66 . V_67 , V_52 -> V_61 ) ;
}
F_49 ( 1 ) ;
}
static int F_88 ( T_2 * V_1 V_50 ) {
T_16 V_68 = F_87 ( V_1 , 1 ) ;
if ( V_68 )
F_64 ( V_68 ) ;
return 0 ;
}
static int F_89 ( T_2 * V_1 ) {
T_16 V_64 = F_90 ( V_1 , 1 ) ;
T_14 * V_52 = V_64 -> V_52 ;
const char * V_69 = NULL ;
const char * V_70 = NULL ;
T_10 V_71 = 0 ;
T_10 V_72 = 0 ;
T_17 V_73 = 0 ;
struct V_74 V_75 = { { 0 } } ;
if ( ! V_52 -> V_76 || ! V_52 -> V_77 ) {
return F_53 ( V_1 , L_35 ) ;
}
if ( ! F_76 ( V_1 , - 1 ) ) {
return F_53 ( V_1 , L_36 ) ;
}
F_91 ( V_1 , - 1 , L_37 ) ;
if ( F_76 ( V_1 , - 1 ) ) {
F_8 ( V_1 ) ;
while ( F_92 ( V_1 , - 2 ) != 0 ) {
if ( ! F_76 ( V_1 , - 1 ) ) {
F_39 ( V_1 , 3 ) ;
return F_53 ( V_1 , L_38 ) ;
}
F_91 ( V_1 , - 1 , L_39 ) ;
if ( ! F_93 ( V_1 , - 1 ) ) {
F_39 ( V_1 , 3 ) ;
return F_53 ( V_1 , L_40 ) ;
}
V_69 = F_59 ( V_1 , - 1 , & V_71 ) ;
if ( V_71 != 4 ) {
F_39 ( V_1 , 3 ) ;
return F_53 ( V_1 , L_41 ) ;
}
memcpy ( & V_73 , V_69 , 4 ) ;
F_91 ( V_1 , - 1 , L_42 ) ;
if ( ! F_93 ( V_1 , - 1 ) ) {
F_39 ( V_1 , 3 ) ;
return F_53 ( V_1 , L_40 ) ;
}
V_70 = F_59 ( V_1 , - 1 , & V_72 ) ;
V_52 -> V_76 ( V_73 , V_70 ) ;
F_39 ( V_1 , 1 ) ;
}
}
F_39 ( V_1 , 1 ) ;
F_91 ( V_1 , - 1 , L_43 ) ;
if ( F_76 ( V_1 , - 1 ) ) {
F_8 ( V_1 ) ;
while ( F_92 ( V_1 , - 2 ) != 0 ) {
if ( ! F_76 ( V_1 , - 1 ) ) {
F_39 ( V_1 , 3 ) ;
return F_53 ( V_1 , L_44 ) ;
}
F_91 ( V_1 , - 1 , L_39 ) ;
if ( ! F_93 ( V_1 , - 1 ) ) {
F_39 ( V_1 , 3 ) ;
return F_53 ( V_1 , L_45 ) ;
}
V_69 = F_59 ( V_1 , - 1 , & V_71 ) ;
if ( V_71 != 16 ) {
F_39 ( V_1 , 3 ) ;
return F_53 ( V_1 , L_46 ) ;
}
memcpy ( & V_75 , V_69 , 16 ) ;
F_91 ( V_1 , - 1 , L_42 ) ;
if ( ! F_93 ( V_1 , - 1 ) ) {
F_39 ( V_1 , 3 ) ;
return F_53 ( V_1 , L_45 ) ;
}
V_70 = F_59 ( V_1 , - 1 , & V_72 ) ;
V_52 -> V_77 ( ( const void * ) ( & V_75 ) , V_70 ) ;
F_39 ( V_1 , 1 ) ;
}
}
F_39 ( V_1 , 1 ) ;
return 0 ;
}
static int F_94 ( T_2 * V_1 ) {
T_16 V_64 = F_90 ( V_1 , 1 ) ;
return F_71 ( V_1 , V_64 -> V_52 ) ;
}
static int F_95 ( T_2 * V_1 ) {
T_16 V_64 = F_90 ( V_1 , 1 ) ;
return F_73 ( V_1 , V_64 -> V_52 ) ;
}
int F_96 ( T_2 * V_1 ) {
F_97 ( T_16 ) ;
F_69 ( T_16 ) ;
return 0 ;
}
static T_18 * F_98 ( T_2 * V_1 , T_4 * V_6 ) {
T_18 V_3 = ( T_18 ) F_84 ( sizeof( struct V_58 ) ) ;
V_3 -> V_52 = NULL ;
V_3 -> V_6 = V_6 ;
V_3 -> V_7 = FALSE ;
return F_99 ( V_1 , V_3 ) ;
}
T_13 F_100 ( T_2 * V_1 ) {
T_18 V_64 = F_101 ( V_1 , 1 ) ;
if ( ! V_64 || ! V_64 -> V_6 ) {
F_45 ( V_1 , L_47 ) ;
} else {
T_4 * V_6 = V_64 -> V_6 ;
F_25 ( V_1 , L_48 ,
V_6 -> V_65 , V_6 -> V_78 , V_6 -> V_79 , V_6 -> V_51 , V_6 -> V_61 ) ;
}
F_49 ( 1 ) ;
}
static int F_102 ( T_2 * V_1 ) {
T_18 V_64 = F_103 ( V_1 , 1 ) ;
T_4 * V_6 = V_64 -> V_6 ;
F_104 ( V_1 ) ;
F_104 ( V_1 ) ;
if ( V_6 -> V_80 && V_6 -> V_80 -> V_81 ) {
T_19 * V_82 = ( T_19 * ) F_105 ( V_6 -> V_80 -> V_81 , 0 ) ;
int V_26 , V_83 ;
for ( V_26 = 1 , V_83 = 1 ; V_82 != NULL ; V_26 ++ ) {
if ( ( V_82 -> V_84 & V_85 ) == V_86 ) {
F_10 ( V_1 , V_83 ) ;
F_104 ( V_1 ) ;
F_14 ( V_1 , ( char * ) ( & V_82 -> V_87 ) , 4 ) ;
F_106 ( V_1 , - 2 , L_39 ) ;
F_45 ( V_1 , V_82 -> V_70 ) ;
F_106 ( V_1 , - 2 , L_42 ) ;
F_107 ( V_1 , - 3 ) ;
V_83 ++ ;
}
V_82 = ( T_19 * ) F_105 ( V_6 -> V_80 -> V_81 , V_26 ) ;
}
}
F_106 ( V_1 , - 2 , L_37 ) ;
F_104 ( V_1 ) ;
if ( V_6 -> V_80 && V_6 -> V_80 -> V_88 ) {
T_20 * V_89 = ( T_20 * ) F_105 ( V_6 -> V_80 -> V_88 , 0 ) ;
int V_26 , V_83 ;
for ( V_26 = 1 , V_83 = 1 ; V_89 != NULL ; V_26 ++ ) {
if ( ( V_89 -> V_84 & V_85 ) == V_86 ) {
F_10 ( V_1 , V_83 ) ;
F_104 ( V_1 ) ;
F_14 ( V_1 , ( char * ) ( & V_89 -> V_69 . V_90 [ 0 ] ) , 16 ) ;
F_106 ( V_1 , - 2 , L_39 ) ;
F_45 ( V_1 , V_89 -> V_70 ) ;
F_106 ( V_1 , - 2 , L_42 ) ;
F_107 ( V_1 , - 3 ) ;
V_83 ++ ;
}
V_89 = ( T_20 * ) F_105 ( V_6 -> V_80 -> V_88 , V_26 ) ;
}
}
F_106 ( V_1 , - 2 , L_43 ) ;
return 1 ;
}
static int F_108 ( T_2 * V_1 ) {
T_18 V_64 = F_103 ( V_1 , 1 ) ;
return F_80 ( V_1 , V_64 -> V_6 ) ;
}
static int F_109 ( T_2 * V_1 ) {
T_18 V_64 = F_103 ( V_1 , 1 ) ;
return F_81 ( V_1 , V_64 -> V_6 ) ;
}
static int F_110 ( T_2 * V_1 V_50 ) {
T_18 V_64 = F_101 ( V_1 , 1 ) ;
if ( V_64 )
F_64 ( V_64 ) ;
return 0 ;
}
int F_111 ( T_2 * V_1 ) {
F_97 ( T_18 ) ;
F_69 ( T_18 ) ;
return 0 ;
}
static T_21 * F_112 ( T_2 * V_1 , struct V_91 * V_66 , T_22 * V_92 ) {
T_21 V_3 = ( T_21 ) F_84 ( sizeof( struct V_93 ) ) ;
V_3 -> V_66 = V_66 ;
V_3 -> V_92 = V_92 ;
V_3 -> V_7 = FALSE ;
return F_113 ( V_1 , V_3 ) ;
}
T_13 F_114 ( T_2 * V_1 ) {
T_21 V_64 = F_115 ( V_1 , 1 ) ;
if ( ! V_64 ) {
F_45 ( V_1 , L_49 ) ;
} else {
if ( V_64 -> V_66 )
F_25 ( V_1 , L_50 ,
V_64 -> V_66 -> V_94 , V_64 -> V_66 -> V_95 , V_64 -> V_66 -> V_96 , V_64 -> V_66 -> V_47 , V_64 -> V_66 -> V_67 , V_64 -> V_66 -> V_97 ) ;
else
F_45 ( V_1 , L_51 ) ;
}
F_49 ( 1 ) ;
}
T_12 F_116 ( T_2 * V_1 ) {
#define F_117 2
#define F_118 3
T_21 V_64 = F_119 ( V_1 , 1 ) ;
T_1 V_8 = F_41 ( V_1 , F_117 ) ;
T_17 V_47 = F_120 ( V_1 , F_118 ) ;
int V_43 = 0 ;
T_7 * V_98 = NULL ;
if ( ! V_64 -> V_92 || ! V_8 -> V_5 ) {
F_53 ( V_1 , L_52 ) ;
return 0 ;
}
if ( ! F_121 ( V_8 -> V_5 , V_64 -> V_92 , V_47 , & V_43 , & V_98 ) ) {
F_24 ( V_1 , FALSE ) ;
if ( V_98 ) {
F_45 ( V_1 , V_98 ) ;
F_64 ( V_98 ) ;
}
else F_8 ( V_1 ) ;
F_10 ( V_1 , V_43 ) ;
return 3 ;
}
F_24 ( V_1 , TRUE ) ;
F_49 ( 1 ) ;
}
static int F_122 ( T_2 * V_1 V_50 ) {
T_21 V_64 = F_115 ( V_1 , 1 ) ;
if ( V_64 )
F_64 ( V_64 ) ;
return 0 ;
}
static int F_123 ( T_2 * V_1 ) {
T_21 V_64 = F_119 ( V_1 , 1 ) ;
T_23 V_99 = F_124 ( V_1 , 2 ) ;
if ( ! V_64 -> V_66 ) return 0 ;
V_64 -> V_66 -> V_100 . V_101 = V_99 -> V_101 ;
V_64 -> V_66 -> V_100 . V_102 = V_99 -> V_102 ;
return 0 ;
}
static int F_125 ( T_2 * V_1 ) {
T_21 V_64 = F_119 ( V_1 , 1 ) ;
T_23 V_99 = ( T_23 ) F_2 ( sizeof( V_103 ) ) ;
if ( ! V_99 ) return 0 ;
V_99 -> V_101 = V_64 -> V_66 -> V_100 . V_101 ;
V_99 -> V_102 = V_64 -> V_66 -> V_100 . V_102 ;
F_126 ( V_1 , V_99 ) ;
return 1 ;
}
static int F_127 ( T_2 * V_1 ) {
T_21 V_64 = F_119 ( V_1 , 1 ) ;
if ( ! V_64 -> V_66 ) {
F_31 ( L_53 ) ;
return 0 ;
}
if ( ! V_64 -> V_92 ) {
F_31 ( L_54 ) ;
return 0 ;
}
if ( F_93 ( V_1 , 2 ) ) {
T_10 V_47 = 0 ;
const T_7 * V_48 = F_59 ( V_1 , 2 , & V_47 ) ;
if ( V_48 ) {
F_128 ( V_64 -> V_92 , V_47 ) ;
memcpy ( F_129 ( V_64 -> V_92 ) , V_48 , V_47 ) ;
V_64 -> V_66 -> V_96 = ( T_17 ) V_47 ;
V_64 -> V_66 -> V_47 = ( T_17 ) V_47 ;
} else {
F_53 ( V_1 , L_55 ) ;
}
}
else
F_53 ( V_1 , L_56 ) ;
return 0 ;
}
static int F_130 ( T_2 * V_1 ) {
T_21 V_64 = F_119 ( V_1 , 1 ) ;
if ( ! V_64 -> V_92 ) return 0 ;
F_14 ( V_1 , F_129 ( V_64 -> V_92 ) , F_131 ( V_64 -> V_92 ) ) ;
F_49 ( 1 ) ;
}
int F_132 ( T_2 * V_1 ) {
F_68 ( T_21 ) ;
F_69 ( T_21 ) ;
return 0 ;
}
static T_24 * F_133 ( T_2 * V_1 , const struct V_91 * V_66 , const T_25 * V_104 ) {
T_24 V_3 = ( T_24 ) F_2 ( sizeof( struct V_105 ) ) ;
V_3 -> V_66 = V_66 ;
V_3 -> V_104 = V_104 ;
V_3 -> V_7 = FALSE ;
return F_134 ( V_1 , V_3 ) ;
}
T_13 F_135 ( T_2 * V_1 ) {
T_24 V_64 = F_136 ( V_1 , 1 ) ;
if ( ! V_64 ) {
F_45 ( V_1 , L_49 ) ;
} else {
if ( V_64 -> V_66 && ! V_64 -> V_7 )
F_25 ( V_1 , L_50 ,
V_64 -> V_66 -> V_94 , V_64 -> V_66 -> V_95 , V_64 -> V_66 -> V_96 , V_64 -> V_66 -> V_47 , V_64 -> V_66 -> V_67 , V_64 -> V_66 -> V_97 ) ;
else
F_25 ( V_1 , L_57 , V_64 -> V_66 ? L_58 : L_59 ) ;
}
F_49 ( 1 ) ;
}
T_12 F_137 ( T_2 * V_1 ) {
#define F_138 2
#define F_139 3
T_24 V_64 = F_140 ( V_1 , 1 ) ;
T_1 V_8 = F_41 ( V_1 , F_138 ) ;
T_17 V_47 = F_141 ( V_1 , F_139 , V_64 -> V_66 ? V_64 -> V_66 -> V_96 : 0 ) ;
int V_43 = 0 ;
if ( ! V_64 -> V_104 || ! V_64 -> V_66 || ! V_8 -> V_6 ) {
F_53 ( V_1 , L_60 ) ;
return 0 ;
}
if ( V_47 > V_64 -> V_66 -> V_96 )
V_47 = V_64 -> V_66 -> V_96 ;
if ( ! F_60 ( V_8 -> V_6 , V_64 -> V_104 , ( T_10 ) ( V_47 ) , & V_43 ) ) {
F_24 ( V_1 , FALSE ) ;
F_25 ( V_1 , L_61 , F_26 ( V_43 ) ) ;
F_10 ( V_1 , V_43 ) ;
return 3 ;
}
F_24 ( V_1 , TRUE ) ;
F_49 ( 1 ) ;
}
static int F_142 ( T_2 * V_1 V_50 ) {
T_24 V_64 = F_136 ( V_1 , 1 ) ;
if ( V_64 )
F_64 ( V_64 ) ;
return 0 ;
}
static int F_143 ( T_2 * V_1 ) {
T_24 V_64 = F_140 ( V_1 , 1 ) ;
T_23 V_99 = ( T_23 ) F_2 ( sizeof( V_103 ) ) ;
if ( ! V_99 ) return 0 ;
V_99 -> V_101 = V_64 -> V_66 -> V_100 . V_101 ;
V_99 -> V_102 = V_64 -> V_66 -> V_100 . V_102 ;
F_126 ( V_1 , V_99 ) ;
return 1 ;
}
static int F_144 ( T_2 * V_1 ) {
T_24 V_64 = F_140 ( V_1 , 1 ) ;
if ( ! V_64 -> V_104 || ! V_64 -> V_66 ) return 0 ;
F_14 ( V_1 , V_64 -> V_104 , V_64 -> V_66 -> V_96 ) ;
return 1 ;
}
int F_145 ( T_2 * V_1 ) {
F_68 ( T_24 ) ;
F_69 ( T_24 ) ;
return 0 ;
}
static int F_146 ( T_2 * V_1 ) {
const T_7 * error = F_35 ( V_1 , 1 ) ;
const T_7 * V_106 = F_147 ( V_1 , F_52 ( 1 ) , L_62 ) ;
F_148 ( L_63 , V_106 , error ) ;
F_39 ( V_1 , 1 ) ;
return 0 ;
}
static int F_149 ( T_2 * V_1 , const T_7 * V_107 ) {
F_45 ( V_1 , V_107 ) ;
F_56 ( V_1 , F_146 , 1 ) ;
return 1 ;
}
static int
F_150 ( T_14 * V_52 , int * V_43 V_50 , T_7 * * V_98 )
{
T_26 V_8 = ( T_26 ) ( V_52 -> V_108 ) ;
int V_109 = 0 ;
T_2 * V_1 = NULL ;
T_1 * V_110 = NULL ;
T_16 * V_68 = NULL ;
F_151 ( V_111 , 0 ) ;
F_70 ( V_1 , V_52 ) ;
V_110 = F_1 ( V_1 , V_52 -> V_8 ) ;
V_68 = F_83 ( V_1 , V_52 , TRUE ) ;
V_29 = V_112 ;
switch ( F_152 ( V_1 , 2 , 1 , 1 ) ) {
case 0 :
V_109 = F_153 ( V_1 , - 1 , 0 ) ;
break;
F_154 ( L_64 )
}
F_155 () ;
( * V_110 ) -> V_7 = TRUE ;
( * V_68 ) -> V_7 = TRUE ;
if ( V_109 == 1 ) {
if ( V_8 -> V_113 != V_55 ) {
V_52 -> V_114 = V_115 ;
}
else return 0 ;
if ( V_8 -> V_116 != V_55 ) {
V_52 -> V_117 = V_118 ;
}
else return 0 ;
if ( V_8 -> V_119 != V_55 )
V_52 -> V_120 = V_121 ;
else
V_52 -> V_120 = NULL ;
if ( V_8 -> V_122 != V_55 )
V_52 -> V_123 = V_124 ;
else
V_52 -> V_123 = NULL ;
V_52 -> V_65 = V_8 -> V_125 ;
}
else {
F_78 ( V_1 , V_52 ) ;
}
F_156 ( V_1 , 0 ) ;
return V_109 ;
}
static T_5
V_115 ( T_14 * V_52 , int * V_43 , T_7 * * V_98 ,
T_8 * V_126 )
{
T_26 V_8 = ( T_26 ) ( V_52 -> V_108 ) ;
int V_109 = - 1 ;
T_2 * V_1 = NULL ;
T_1 * V_110 = NULL ;
T_16 * V_68 = NULL ;
T_21 * V_64 = NULL ;
F_151 ( V_127 , FALSE ) ;
* V_43 = V_29 = 0 ;
V_52 -> V_66 . V_97 = NULL ;
V_110 = F_1 ( V_1 , V_52 -> V_8 ) ;
V_68 = F_83 ( V_1 , V_52 , FALSE ) ;
V_64 = F_112 ( V_1 , & V_52 -> V_66 , V_52 -> V_128 ) ;
V_29 = V_112 ;
switch ( F_152 ( V_1 , 3 , 1 , 1 ) ) {
case 0 :
if ( F_157 ( V_1 , - 1 ) ) {
* V_126 = F_158 ( V_1 , - 1 ) ;
V_109 = 1 ;
break;
}
V_109 = F_153 ( V_1 , - 1 , 0 ) ;
break;
F_154 ( L_65 )
}
F_155 () ;
( * V_110 ) -> V_7 = TRUE ;
( * V_68 ) -> V_7 = TRUE ;
( * V_64 ) -> V_7 = TRUE ;
F_156 ( V_1 , 0 ) ;
return ( V_109 == 1 ) ;
}
static T_5
V_118 ( T_14 * V_52 , T_8 V_129 ,
struct V_91 * V_66 , T_22 * V_92 ,
int * V_43 , T_7 * * V_98 )
{
T_26 V_8 = ( T_26 ) ( V_52 -> V_108 ) ;
int V_109 = - 1 ;
T_2 * V_1 = NULL ;
T_1 * V_110 = NULL ;
T_16 * V_68 = NULL ;
T_21 * V_64 = NULL ;
F_151 ( V_130 , FALSE ) ;
* V_43 = V_29 = 0 ;
V_66 -> V_97 = NULL ;
V_110 = F_1 ( V_1 , V_52 -> V_131 ) ;
V_68 = F_83 ( V_1 , V_52 , FALSE ) ;
V_64 = F_112 ( V_1 , V_66 , V_92 ) ;
F_10 ( V_1 , ( T_6 ) V_129 ) ;
* V_43 = V_112 ;
switch ( F_152 ( V_1 , 4 , 1 , 1 ) ) {
case 0 :
if ( F_93 ( V_1 , - 1 ) ) {
T_10 V_47 = 0 ;
const T_7 * V_132 = F_159 ( V_1 , - 1 , & V_47 ) ;
if ( V_47 < V_133 )
memcpy ( F_129 ( V_92 ) , V_132 , V_47 ) ;
V_109 = 1 ;
break;
}
V_109 = F_153 ( V_1 , - 1 , 0 ) ;
break;
F_154 ( L_66 )
}
F_155 () ;
( * V_110 ) -> V_7 = TRUE ;
( * V_68 ) -> V_7 = TRUE ;
( * V_64 ) -> V_7 = TRUE ;
F_156 ( V_1 , 0 ) ;
return ( V_109 == 1 ) ;
}
static void
V_121 ( T_14 * V_52 )
{
T_26 V_8 = ( T_26 ) ( V_52 -> V_108 ) ;
T_2 * V_1 = NULL ;
T_1 * V_110 = NULL ;
T_16 * V_68 = NULL ;
F_151 ( V_134 ,) ;
V_110 = F_1 ( V_1 , V_52 -> V_8 ) ;
V_68 = F_83 ( V_1 , V_52 , FALSE ) ;
switch ( F_152 ( V_1 , 2 , 1 , 1 ) ) {
case 0 :
break;
F_160 ( L_67 )
}
F_155 () ;
F_78 ( V_1 , V_52 ) ;
( * V_110 ) -> V_7 = TRUE ;
( * V_68 ) -> V_7 = TRUE ;
F_156 ( V_1 , 0 ) ;
return;
}
static void
V_124 ( T_14 * V_52 )
{
T_26 V_8 = ( T_26 ) ( V_52 -> V_108 ) ;
T_2 * V_1 = NULL ;
T_1 * V_110 = NULL ;
T_16 * V_68 = NULL ;
F_151 ( V_135 ,) ;
V_110 = F_1 ( V_1 , V_52 -> V_8 ) ;
V_68 = F_83 ( V_1 , V_52 , FALSE ) ;
switch ( F_152 ( V_1 , 2 , 1 , 1 ) ) {
case 0 :
break;
F_160 ( L_68 )
}
F_155 () ;
( * V_110 ) -> V_7 = TRUE ;
( * V_68 ) -> V_7 = TRUE ;
F_156 ( V_1 , 0 ) ;
return;
}
static int
F_161 ( int V_79 V_50 )
{
return V_136 ;
}
static int
F_162 ( int V_79 , void * V_137 )
{
T_26 V_8 = ( T_26 ) ( V_137 ) ;
int V_109 = V_138 ;
T_2 * V_1 = NULL ;
F_151 ( V_139 , V_44 ) ;
F_10 ( V_1 , V_79 ) ;
V_29 = V_112 ;
switch ( F_152 ( V_1 , 1 , 1 , 1 ) ) {
case 0 :
V_109 = F_153 ( V_1 , - 1 , V_138 ) ;
break;
F_160 ( L_69 )
}
F_155 () ;
if ( V_109 == 1 ) {
V_109 = 0 ;
} else if ( V_109 == 0 ) {
V_109 = V_138 ;
}
return V_109 ;
}
static int
F_163 ( T_4 * V_6 , int * V_43 )
{
T_26 V_8 = ( T_26 ) ( V_6 -> V_108 ) ;
int V_109 = 0 ;
T_2 * V_1 = NULL ;
T_1 * V_110 = NULL ;
T_18 * V_68 = NULL ;
F_151 ( V_140 , 0 ) ;
F_79 ( V_1 , V_6 ) ;
V_110 = F_4 ( V_1 , V_6 ) ;
V_68 = F_98 ( V_1 , V_6 ) ;
* V_43 = 0 ;
switch ( F_152 ( V_1 , 2 , 1 , 1 ) ) {
case 0 :
V_109 = F_153 ( V_1 , - 1 , 0 ) ;
break;
F_160 ( L_70 )
}
F_155 () ;
( * V_110 ) -> V_7 = TRUE ;
( * V_68 ) -> V_7 = TRUE ;
if ( V_109 == 1 ) {
if ( V_8 -> V_141 != V_55 ) {
V_6 -> V_142 = V_143 ;
}
else {
F_31 ( L_71 ) ;
return 0 ;
}
if ( V_8 -> V_144 != V_55 )
V_6 -> V_120 = V_145 ;
else
V_6 -> V_120 = NULL ;
}
else {
F_82 ( V_1 , V_6 ) ;
}
return V_109 ;
}
static T_5
V_143 ( T_4 * V_6 , const struct V_91 * V_66 ,
const T_25 * V_104 , int * V_43 )
{
T_26 V_8 = ( T_26 ) ( V_6 -> V_108 ) ;
int V_109 = - 1 ;
T_2 * V_1 = NULL ;
T_1 * V_110 = NULL ;
T_18 * V_68 = NULL ;
T_24 * V_64 = NULL ;
F_151 ( V_146 , FALSE ) ;
* V_43 = V_29 = 0 ;
V_110 = F_4 ( V_1 , V_6 ) ;
V_68 = F_98 ( V_1 , V_6 ) ;
V_64 = F_133 ( V_1 , V_66 , V_104 ) ;
V_29 = V_112 ;
switch ( F_152 ( V_1 , 3 , 1 , 1 ) ) {
case 0 :
V_109 = F_153 ( V_1 , - 1 , 0 ) ;
break;
F_160 ( L_72 )
}
F_155 () ;
( * V_110 ) -> V_7 = TRUE ;
( * V_68 ) -> V_7 = TRUE ;
( * V_64 ) -> V_7 = TRUE ;
return ( V_109 == 1 ) ;
}
static T_5
V_145 ( T_4 * V_6 , int * V_43 )
{
T_26 V_8 = ( T_26 ) ( V_6 -> V_108 ) ;
int V_109 = - 1 ;
T_2 * V_1 = NULL ;
T_1 * V_110 = NULL ;
T_18 * V_68 = NULL ;
F_151 ( V_147 , FALSE ) ;
* V_43 = V_29 = 0 ;
V_110 = F_4 ( V_1 , V_6 ) ;
V_68 = F_98 ( V_1 , V_6 ) ;
V_29 = V_112 ;
switch ( F_152 ( V_1 , 2 , 1 , 1 ) ) {
case 0 :
V_109 = F_153 ( V_1 , - 1 , 0 ) ;
break;
F_160 ( L_73 )
}
F_155 () ;
F_82 ( V_1 , V_6 ) ;
( * V_110 ) -> V_7 = TRUE ;
( * V_68 ) -> V_7 = TRUE ;
return ( V_109 == 1 ) ;
}
T_27 F_164 ( T_2 * V_1 ) {
#define F_165 1
#define F_166 2
#define F_167 3
#define F_168 4
const T_7 * V_70 = F_169 ( V_1 , F_165 ) ;
const T_7 * V_148 = F_169 ( V_1 , F_166 ) ;
const T_7 * V_149 = F_169 ( V_1 , F_167 ) ;
const T_7 * type = F_169 ( V_1 , F_168 ) ;
T_26 V_8 = ( T_26 ) F_84 ( sizeof( struct V_150 ) ) ;
V_8 -> V_151 = ( strchr ( type , 'r' ) != NULL ) ? TRUE : FALSE ;
V_8 -> V_152 = ( strchr ( type , 'w' ) != NULL ) ? TRUE : FALSE ;
if ( V_8 -> V_151 && F_170 ( V_148 ) ) {
return F_53 ( V_1 , L_74 , V_148 ) ;
}
if ( V_8 -> V_152 && F_171 ( V_148 ) > - 1 ) {
return F_53 ( V_1 , L_75 , V_148 ) ;
}
V_8 -> type = F_172 ( type ) ;
V_8 -> V_153 . V_70 = F_172 ( V_70 ) ;
V_8 -> V_153 . V_148 = F_172 ( V_148 ) ;
V_8 -> V_153 . V_154 = NULL ;
V_8 -> V_153 . V_155 = NULL ;
V_8 -> V_153 . V_156 = FALSE ;
V_8 -> V_153 . V_157 = FALSE ;
V_8 -> V_153 . V_139 = NULL ;
V_8 -> V_153 . V_158 = NULL ;
V_8 -> V_125 = V_159 ;
V_8 -> V_160 = F_172 ( V_149 ) ;
V_8 -> V_1 = V_1 ;
V_8 -> V_161 = V_55 ;
V_8 -> V_113 = V_55 ;
V_8 -> V_116 = V_55 ;
V_8 -> V_119 = V_55 ;
V_8 -> V_122 = V_55 ;
V_8 -> V_162 = V_55 ;
V_8 -> V_141 = V_55 ;
V_8 -> V_144 = V_55 ;
V_8 -> V_163 = V_55 ;
V_8 -> V_164 = FALSE ;
F_173 ( V_1 , V_8 ) ;
F_49 ( 1 ) ;
}
T_13 F_174 ( T_2 * V_1 ) {
T_26 V_8 = F_175 ( V_1 , 1 ) ;
if ( ! V_8 ) {
F_45 ( V_1 , L_76 ) ;
} else {
F_25 ( V_1 , L_77 ,
V_8 -> V_153 . V_70 , V_8 -> V_153 . V_148 , V_8 -> V_160 , V_8 -> V_161 , V_8 -> V_113 , V_8 -> V_141 ) ;
}
F_49 ( 1 ) ;
}
static int F_176 ( T_2 * V_1 V_50 ) {
return 0 ;
}
static T_5 F_177 ( T_26 V_8 ) {
return ( ( V_8 -> V_151 || V_8 -> V_152 ) &&
( ! V_8 -> V_151 ||
( V_8 -> V_151 &&
V_8 -> V_161 != V_55 &&
V_8 -> V_113 != V_55 &&
V_8 -> V_116 != V_55 ) ) &&
( ! V_8 -> V_152 ||
( V_8 -> V_152 &&
V_8 -> V_163 != V_55 &&
V_8 -> V_162 != V_55 &&
V_8 -> V_141 != V_55 ) ) ) ;
}
T_28 F_178 ( T_2 * V_1 ) {
#define F_179 1
T_26 V_8 = F_180 ( V_1 , F_179 ) ;
if ( V_165 )
return F_53 ( V_1 , L_78 ) ;
if ( V_8 -> V_164 )
return F_53 ( V_1 , L_79 ) ;
if ( ! F_177 ( V_8 ) )
return F_53 ( V_1 , L_80 ) ;
if ( V_8 -> V_152 ) {
V_8 -> V_153 . V_139 = F_161 ;
V_8 -> V_153 . V_166 = ( V_167 * ) F_84 ( sizeof( V_167 ) ) ;
V_8 -> V_153 . V_166 -> V_168 = F_162 ;
V_8 -> V_153 . V_166 -> V_108 = ( void * ) ( V_8 ) ;
V_8 -> V_153 . V_158 = F_163 ;
}
V_8 -> V_125 = F_181 ( & ( V_8 -> V_153 ) , V_8 -> V_125 ) ;
if ( V_8 -> V_151 ) {
struct V_169 V_170 = { NULL , V_171 , NULL , NULL , NULL , NULL } ;
V_170 . V_70 = V_8 -> V_153 . V_148 ;
V_170 . V_172 = F_150 ;
V_170 . V_173 = V_8 -> V_153 . V_155 ;
V_170 . V_108 = ( void * ) ( V_8 ) ;
if ( strchr ( V_8 -> type , 'm' ) != NULL ) {
V_170 . type = V_174 ;
} else {
V_170 . type = V_171 ;
}
F_182 ( & V_170 , ( strchr ( V_8 -> type , 's' ) != NULL ) ) ;
}
V_8 -> V_164 = TRUE ;
F_10 ( V_1 , V_8 -> V_125 ) ;
F_49 ( 1 ) ;
}
T_28 F_183 ( T_2 * V_1 ) {
#define F_179 1
T_26 V_8 = F_180 ( V_1 , F_179 ) ;
if ( V_165 )
return F_53 ( V_1 , L_81 ) ;
if ( ! V_8 -> V_164 )
return 0 ;
V_8 -> V_153 . V_139 = NULL ;
if ( V_8 -> V_153 . V_166 ) {
V_8 -> V_153 . V_166 -> V_168 = NULL ;
V_8 -> V_153 . V_166 -> V_108 = NULL ;
F_64 ( V_8 -> V_153 . V_166 ) ;
V_8 -> V_153 . V_166 = NULL ;
}
V_8 -> V_153 . V_158 = NULL ;
if ( V_8 -> V_125 != V_159 )
F_184 ( V_8 -> V_125 ) ;
if ( V_8 -> V_151 && F_170 ( V_8 -> V_153 . V_148 ) ) {
F_185 ( V_8 -> V_153 . V_148 ) ;
}
V_8 -> V_164 = FALSE ;
return 0 ;
}
int F_186 ( T_2 * V_1 ) {
F_68 ( T_26 ) ;
F_69 ( T_26 ) ;
return 0 ;
}
