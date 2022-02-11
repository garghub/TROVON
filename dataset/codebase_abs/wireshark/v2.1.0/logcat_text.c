static T_1 F_1 ( const T_2 V_1 ) {
static T_1 V_2 [] = L_1 ;
if ( V_1 >= ( T_2 ) sizeof( V_2 ) )
return '?' ;
return V_2 [ V_1 ] ;
}
static T_3 F_2 ( const T_2 * V_3 )
{
const struct V_4 * V_5 ;
const struct V_6 * V_7 ;
T_3 V_8 ;
const T_2 * V_9 = NULL ;
T_2 * V_10 ;
T_2 * V_11 ;
T_4 V_12 ;
V_5 = ( const struct V_4 * ) ( const void * ) V_3 ;
V_7 = ( const struct V_6 * ) ( const void * ) V_3 ;
if ( V_5 -> V_13 < 3 )
return - 1 ;
if ( V_5 -> V_13 > V_14 )
return - 1 ;
for ( V_8 = 1 ; V_8 <= 2 ; ++ V_8 ) {
if ( V_8 == 1 ) {
V_9 = ( const T_2 * ) ( V_5 + 1 ) ;
} else if ( V_8 == 2 ) {
V_9 = ( const T_2 * ) ( V_7 + 1 ) ;
if ( V_7 -> V_15 != sizeof( * V_7 ) )
continue;
}
if ( F_1 ( V_9 [ 0 ] ) == '?' )
continue;
V_10 = ( T_2 * ) memchr ( V_9 , '\0' , V_5 -> V_13 - 1 ) ;
if ( V_10 == NULL )
continue;
++ V_10 ;
V_12 = ( T_4 ) ( V_5 -> V_13 - ( V_10 - V_9 ) ) ;
V_11 = ( T_2 * ) memchr ( V_10 , '\0' , V_12 ) ;
if ( V_11 && ( V_9 + V_5 -> V_13 - 1 != V_11 ) )
continue;
return V_8 ;
}
return - 1 ;
}
static T_1 * F_3 ( const struct V_16 * V_17 , T_5 V_18 ,
T_3 V_19 , T_3 V_20 , T_3 V_21 , T_1 V_1 , const T_1 * V_22 ,
const T_1 * log )
{
T_1 V_23 [ 15 ] ;
T_6 V_24 ;
V_24 = ( T_6 ) V_18 ;
switch ( V_17 -> type ) {
case V_25 :
return F_4 ( L_2 ,
V_1 , V_22 , V_20 , log ) ;
case V_26 :
return F_4 ( L_3 ,
V_1 , V_20 , log , L_4 ) ;
case V_27 :
return F_4 ( L_5 ,
V_1 , V_22 , log ) ;
case V_28 :
return F_4 ( L_6 ,
V_1 , V_20 , V_21 , log ) ;
case V_29 :
strftime ( V_23 , sizeof( V_23 ) , L_7 ,
gmtime ( & V_24 ) ) ;
return F_4 ( L_8 ,
V_23 , V_19 , V_1 , V_22 , V_20 , log ) ;
case V_30 :
strftime ( V_23 , sizeof( V_23 ) , L_7 ,
gmtime ( & V_24 ) ) ;
return F_4 ( L_9 ,
V_23 , V_19 , V_20 , V_21 , V_1 , V_22 , log ) ;
case V_31 :
strftime ( V_23 , sizeof( V_23 ) , L_7 ,
gmtime ( & V_24 ) ) ;
return F_4 ( L_10 ,
V_23 , V_19 , V_20 , V_21 , V_1 , V_22 , log ) ;
default:
return NULL ;
}
}
static void F_5 ( T_1 * string , struct V_32 * V_33 ) {
T_3 V_34 ;
struct V_35 V_36 ;
T_6 V_18 ;
if ( 6 == sscanf ( string , L_11 , & V_36 . V_37 , & V_36 . V_38 , & V_36 . V_39 ,
& V_36 . V_40 , & V_36 . V_41 , & V_34 ) ) {
V_36 . V_42 = 70 ;
V_36 . V_37 -= 1 ;
V_18 = mktime ( & V_36 ) ;
V_33 -> V_43 . V_44 = ( T_6 ) V_18 ;
V_33 -> V_43 . V_45 = ( int ) ( V_34 * 1e6 ) ;
V_33 -> V_46 = V_47 ;
} else {
V_33 -> V_46 = 0 ;
V_33 -> V_43 . V_44 = ( T_6 ) 0 ;
V_33 -> V_43 . V_45 = ( int ) 0 ;
}
}
static T_7 F_6 ( T_8 V_48 , struct V_32 * V_33 ,
T_9 * V_49 , T_3 V_50 ) {
T_10 * V_3 ;
T_1 V_51 [ V_52 ] ;
T_1 * V_53 = NULL ;
do {
V_53 = F_7 ( V_51 , V_52 , V_48 ) ;
} while ( NULL != V_53 && 3 > strlen ( V_51 ) && ! F_8 ( V_48 ) );
if ( NULL == V_53 || 3 > strlen ( V_51 ) ) {
return FALSE ;
}
if ( V_54 == V_50 &&
! F_9 ( V_55 , V_51 , ( V_56 ) ( ( T_3 ) V_57 | ( T_3 ) V_58 ) , V_59 ) ) {
T_11 V_60 = 0 ;
T_1 V_61 [ V_52 ] ;
int V_62 ;
T_1 * V_63 = NULL ;
V_60 = F_10 ( V_48 ) ;
V_63 = F_7 ( V_61 , V_52 , V_48 ) ;
while ( NULL != V_63 && 2 < strlen ( V_61 ) && ! F_8 ( V_48 ) ) {
F_11 ( V_51 , V_61 , V_52 ) ;
V_60 = F_10 ( V_48 ) ;
V_63 = F_7 ( V_61 , V_52 , V_48 ) ;
}
if( NULL == V_63 || 2 < strlen ( V_61 ) ) {
return FALSE ;
}
F_12 ( V_48 , V_60 , V_64 , & V_62 ) ;
}
V_33 -> V_65 = V_66 ;
V_33 -> V_67 = ( T_5 ) strlen ( V_51 ) ;
V_33 -> V_13 = V_33 -> V_67 ;
F_13 ( V_49 , V_33 -> V_67 + 1 ) ;
V_3 = F_14 ( V_49 ) ;
if ( ( V_68 == V_50
|| V_69 == V_50
|| V_54 == V_50 )
&& '-' != V_51 [ 0 ] ) {
if ( V_54 == V_50 ) {
F_5 ( V_51 + 2 , V_33 ) ;
} else {
F_5 ( V_51 , V_33 ) ;
}
} else {
V_33 -> V_46 = 0 ;
V_33 -> V_43 . V_44 = ( T_6 ) 0 ;
V_33 -> V_43 . V_45 = ( int ) 0 ;
}
memcpy ( V_3 , V_51 , V_33 -> V_67 + 1 ) ;
return TRUE ;
}
static T_7 F_15 ( T_12 * V_70 , int * V_62 V_71 , T_1 * * T_13 V_71 ,
T_11 * V_72 ) {
* V_72 = F_10 ( V_70 -> V_48 ) ;
return F_6 ( V_70 -> V_48 , & V_70 -> V_33 , V_70 -> V_73 ,
V_70 -> V_74 ) ;
}
static T_7 F_16 ( T_12 * V_70 , T_11 V_75 ,
struct V_32 * V_33 , T_9 * V_49 , int * V_62 , T_1 * * T_13 V_71 ) {
if ( F_12 ( V_70 -> V_76 , V_75 , V_64 , V_62 ) == - 1 )
return FALSE ;
if ( ! F_6 ( V_70 -> V_76 , V_33 , V_49 ,
V_70 -> V_74 ) ) {
if ( * V_62 == 0 )
* V_62 = V_77 ;
return FALSE ;
}
return TRUE ;
}
T_14 F_17 ( T_12 * V_70 , int * V_62 , T_1 * * T_13 V_71 ) {
T_1 V_51 [ V_52 ] ;
T_1 * V_53 = NULL ;
if ( F_12 ( V_70 -> V_48 , 0 , V_64 , V_62 ) == - 1 )
return V_78 ;
do {
V_53 = F_7 ( V_51 , V_52 , V_70 -> V_48 ) ;
} while ( NULL != V_53 && ! F_8 ( V_70 -> V_48 )
&& ( ( 3 > strlen ( V_51 ) )
|| F_9 ( V_55 , V_51 , ( V_56 ) ( ( T_3 ) V_57 | ( T_3 ) V_58 ) ,
V_59 ) ) );
if ( F_9 ( V_79 , V_51 , ( V_56 ) ( ( T_3 ) V_57 | ( T_3 ) V_58 ) ,
V_59 ) ) {
V_70 -> V_74 = V_80 ;
V_70 -> V_81 = V_25 ;
} else if ( F_9 ( V_82 , V_51 , ( V_56 ) ( ( T_3 ) V_57 | ( T_3 ) V_58 ) ,
V_59 ) ) {
V_70 -> V_74 = V_83 ;
V_70 -> V_81 = V_27 ;
} else if ( F_9 ( V_84 , V_51 , ( V_56 ) ( ( T_3 ) V_57 | ( T_3 ) V_58 ) ,
V_59 ) ) {
V_70 -> V_74 = V_85 ;
V_70 -> V_81 = V_26 ;
} else if ( F_9 ( V_86 , V_51 , ( V_56 ) ( ( T_3 ) V_57 | ( T_3 ) V_58 ) ,
V_59 ) ) {
V_70 -> V_74 = V_68 ;
V_70 -> V_81 = V_29 ;
} else if ( F_9 ( V_87 , V_51 , ( V_56 ) ( ( T_3 ) V_57 | ( T_3 ) V_58 ) ,
V_59 ) ) {
V_70 -> V_74 = V_88 ;
V_70 -> V_81 = V_28 ;
} else if ( F_9 ( V_89 , V_51 , ( V_56 ) ( ( T_3 ) V_57 | ( T_3 ) V_58 ) ,
V_59 ) ) {
V_70 -> V_74 = V_69 ;
V_70 -> V_81 = V_30 ;
} else if ( F_9 ( V_90 , V_51 , ( V_56 ) ( ( T_3 ) V_57 | ( T_3 ) V_58 ) ,
V_59 ) ) {
V_70 -> V_74 = V_54 ;
V_70 -> V_81 = V_31 ;
} else {
return V_91 ;
}
if ( F_12 ( V_70 -> V_48 , 0 , V_64 , V_62 ) == - 1 )
return V_78 ;
V_70 -> V_92 = 0 ;
V_70 -> V_93 = F_15 ;
V_70 -> V_94 = F_16 ;
V_70 -> V_95 = V_96 ;
return V_97 ;
}
int F_18 ( int V_98 ) {
if ( V_98 == V_99 )
return V_100 ;
switch ( V_98 ) {
case V_101 :
case V_25 :
case V_102 :
return 0 ;
default:
return V_103 ;
}
}
int F_19 ( int V_98 ) {
if ( V_98 == V_99 )
return V_100 ;
switch ( V_98 ) {
case V_101 :
case V_26 :
case V_102 :
return 0 ;
default:
return V_103 ;
}
}
int F_20 ( int V_98 ) {
if ( V_98 == V_99 )
return V_100 ;
switch ( V_98 ) {
case V_101 :
case V_27 :
case V_102 :
return 0 ;
default:
return V_103 ;
}
}
int F_21 ( int V_98 ) {
if ( V_98 == V_99 )
return V_100 ;
switch ( V_98 ) {
case V_101 :
case V_29 :
case V_102 :
return 0 ;
default:
return V_103 ;
}
}
int F_22 ( int V_98 ) {
if ( V_98 == V_99 )
return V_100 ;
switch ( V_98 ) {
case V_101 :
case V_28 :
case V_102 :
return 0 ;
default:
return V_103 ;
}
}
int F_23 ( int V_98 ) {
if ( V_98 == V_99 )
return V_100 ;
switch ( V_98 ) {
case V_101 :
case V_30 :
case V_102 :
return 0 ;
default:
return V_103 ;
}
}
int F_24 ( int V_98 ) {
if ( V_98 == V_99 )
return V_100 ;
switch ( V_98 ) {
case V_101 :
case V_31 :
case V_102 :
return 0 ;
default:
return V_103 ;
}
}
static T_7 F_25 ( T_15 * V_104 ,
const struct V_32 * V_33 ,
const T_2 * V_3 , int * V_62 , T_1 * * T_13 )
{
T_1 * V_49 ;
T_3 V_105 ;
T_1 V_1 ;
const struct V_4 * V_5 ;
const struct V_6 * V_7 ;
T_3 V_106 ;
const T_1 * V_22 ;
T_16 V_20 ;
T_16 V_21 ;
T_16 V_18 ;
T_16 V_19 ;
const T_2 * V_9 = NULL ;
const T_1 * V_107 ;
T_3 V_108 ;
T_1 * log ;
T_1 * V_109 ;
T_1 * V_110 ;
T_3 V_111 ;
const struct V_16 * V_17 = ( const struct V_16 * ) V_104 -> V_112 ;
if ( V_33 -> V_65 != V_66 ) {
* V_62 = V_113 ;
return FALSE ;
}
switch ( V_104 -> V_98 ) {
case V_102 :
{
T_3 V_114 ;
V_114 = F_26 ( V_3 ) ;
V_3 += V_114 ;
if ( ! F_27 ( V_104 , ( const T_1 * ) V_3 , V_33 -> V_67 - V_114 , V_62 ) ) {
return FALSE ;
}
}
break;
case V_101 :
if ( V_104 -> V_98 == V_102 ) {
T_3 V_114 ;
V_114 = F_26 ( V_3 ) ;
V_3 += V_114 ;
V_111 = F_2 ( V_3 ) ;
} else {
const union V_115 * V_116 = & V_33 -> V_116 ;
V_111 = V_116 -> V_117 . V_8 ;
}
V_5 = ( const struct V_4 * ) ( const void * ) V_3 ;
V_7 = ( const struct V_6 * ) ( const void * ) V_3 ;
V_106 = F_28 ( V_5 -> V_13 ) ;
V_20 = F_28 ( V_5 -> V_20 ) ;
V_21 = F_28 ( V_5 -> V_21 ) ;
V_18 = F_28 ( V_5 -> V_118 ) ;
V_19 = F_28 ( V_5 -> V_119 ) / 1000000 ;
if ( V_111 == 1 ) {
V_9 = ( const T_2 * ) ( V_5 + 1 ) ;
V_1 = F_1 ( V_9 [ 0 ] ) ;
V_22 = V_9 + 1 ;
V_108 = 1 + ( T_3 ) strlen ( V_22 ) + 1 ;
V_107 = V_9 + V_108 ;
} else if ( V_111 == 2 ) {
V_9 = ( const T_2 * ) ( V_7 + 1 ) ;
V_1 = F_1 ( V_9 [ 0 ] ) ;
V_22 = V_9 + 1 ;
V_108 = 1 + ( T_3 ) strlen ( V_22 ) + 1 ;
V_107 = V_9 + V_108 ;
} else {
* V_62 = V_120 ;
* T_13 = F_4 ( L_12 ,
V_111 ) ;
return FALSE ;
}
log = F_29 ( V_107 , V_106 - V_108 ) ;
V_110 = log ;
do {
V_109 = V_110 ;
if ( V_17 -> type == V_31 ) {
V_110 = NULL ;
} else {
V_110 = strchr ( V_109 , '\n' ) ;
if ( V_110 != NULL ) {
* V_110 = '\0' ;
++ V_110 ;
if ( * V_110 == '\0' ) {
V_110 = NULL ;
}
}
}
V_49 = F_3 ( V_17 , V_18 , V_19 , V_20 , V_21 , V_1 , V_22 , V_109 ) ;
if ( ! V_49 ) {
F_30 ( log ) ;
return FALSE ;
}
V_105 = ( T_5 ) strlen ( V_49 ) ;
if ( ! F_27 ( V_104 , V_49 , V_105 , V_62 ) ) {
F_30 ( log ) ;
return FALSE ;
}
V_104 -> V_121 += V_105 ;
} while ( V_110 != NULL );
F_30 ( log ) ;
break;
case V_25 :
case V_27 :
case V_26 :
case V_29 :
case V_28 :
case V_30 :
case V_31 :
if ( V_17 -> type == V_104 -> V_98 ) {
if ( ! F_27 ( V_104 , ( const T_1 * ) V_3 , V_33 -> V_67 , V_62 ) ) {
return FALSE ;
}
} else {
* V_62 = V_122 ;
return FALSE ;
}
}
return TRUE ;
}
static T_7 F_31 ( T_15 * V_104 , T_17 V_123 , int * V_62 V_71 ) {
struct V_16 * V_17 ;
V_17 = (struct V_16 * ) F_32 ( sizeof( struct V_16 ) ) ;
V_17 -> type = V_123 ;
V_104 -> V_112 = V_17 ;
V_104 -> V_124 = F_25 ;
return TRUE ;
}
T_7 F_33 ( T_15 * V_104 , int * V_62 ) {
return F_31 ( V_104 , V_25 , V_62 ) ;
}
T_7 F_34 ( T_15 * V_104 , int * V_62 ) {
return F_31 ( V_104 , V_26 , V_62 ) ;
}
T_7 F_35 ( T_15 * V_104 , int * V_62 ) {
return F_31 ( V_104 , V_27 , V_62 ) ;
}
T_7 F_36 ( T_15 * V_104 , int * V_62 ) {
return F_31 ( V_104 , V_29 , V_62 ) ;
}
T_7 F_37 ( T_15 * V_104 , int * V_62 ) {
return F_31 ( V_104 , V_28 , V_62 ) ;
}
T_7 F_38 ( T_15 * V_104 , int * V_62 ) {
return F_31 ( V_104 , V_30 , V_62 ) ;
}
T_7 F_39 ( T_15 * V_104 , int * V_62 ) {
return F_31 ( V_104 , V_31 , V_62 ) ;
}
