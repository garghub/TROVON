static int
F_1 ( T_1 * V_1 )
{
T_2 V_2 = strlen ( V_1 ) ;
int V_3 = 0 ;
while ( V_2 -- ) {
if ( * V_1 ++ == ':' )
V_3 ++ ;
}
return V_3 > 1 ? 1 : 0 ;
}
static void
F_2 ( T_3 * V_4 , T_4 * T_5 V_5 , T_6 * V_6 , T_7 V_7 , T_7 V_8 , int V_9 , int V_10 )
{
T_1 * V_11 = NULL ;
F_3 ( V_6 , V_9 , V_4 , V_7 , V_8 , V_12 | V_13 ) ;
switch ( V_10 ) {
case V_14 :
F_4 ( V_15 , L_1 , sizeof( V_15 ) ) ;
V_11 = F_5 ( V_4 , V_7 , V_8 ) ;
if ( F_1 ( V_11 ) ) {
F_4 ( V_15 , L_2 , sizeof( V_15 ) ) ;
F_4 ( V_15 , V_11 , sizeof( V_15 ) ) ;
F_4 ( V_15 , L_3 , sizeof( V_15 ) ) ;
} else
F_4 ( V_15 , V_11 , sizeof( V_15 ) ) ;
break;
case V_16 :
F_4 ( V_15 , L_4 , sizeof( V_15 ) ) ;
F_4 ( V_15 , F_5 ( V_4 , V_7 , V_8 ) , sizeof( V_15 ) ) ;
break;
case V_17 :
F_4 ( V_15 , L_5 , sizeof( V_15 ) ) ;
F_4 ( V_15 , F_5 ( V_4 , V_7 , V_8 ) , sizeof( V_15 ) ) ;
break;
}
}
static void
F_6 ( T_3 * V_4 , T_4 * T_5 , T_6 * V_6 , T_7 V_7 , T_7 V_8 , int V_9 )
{
T_8 V_18 = 0 ;
if ( V_8 != 1 ) {
F_7 ( T_5 , V_6 , V_19 , V_20 , L_6 , V_8 ) ;
return;
}
V_18 = F_8 ( V_4 , V_7 ) ;
V_21 = ( T_7 ) V_18 ;
V_22 = F_9 ( V_18 , V_23 , L_7 ) ;
F_3 ( V_6 , V_9 , V_4 , V_7 , 1 , V_24 ) ;
}
static void
F_10 ( T_3 * V_4 , T_4 * T_5 , T_6 * V_6 , T_7 V_7 , T_7 V_8 , int V_9 )
{
T_9 * V_25 = NULL ;
if ( V_8 <= 0 || V_8 > 4 ) {
F_7 ( T_5 , V_6 , V_19 , V_20 , L_6 , V_8 ) ;
return;
}
V_25 = F_3 ( V_6 , V_9 , V_4 , V_7 , V_8 , V_24 ) ;
F_11 ( V_25 , L_8 ) ;
return;
}
static void
F_12 ( T_3 * V_4 , T_4 * T_5 , T_6 * V_6 , T_7 V_7 , T_7 V_8 , int V_9 )
{
T_1 V_26 = 0 ;
T_10 V_27 = 0 ;
T_10 V_28 ;
T_9 * V_25 = NULL ;
switch ( V_8 ) {
case 1 :
V_29 = ( T_10 ) ( F_8 ( V_4 , V_7 ) >> 4 ) ;
break;
case 2 :
V_29 = ( T_10 ) ( F_13 ( V_4 , V_7 ) >> 4 ) ;
break;
case 3 :
V_29 = ( T_10 ) ( F_14 ( V_4 , V_7 ) >> 4 ) ;
break;
default:
F_7 ( T_5 , V_6 , V_19 , V_20 , L_6 , V_8 ) ;
return;
}
V_26 = F_8 ( V_4 , V_7 + V_8 - 1 ) & 0x0f ;
V_27 = V_26 & 0x07 ;
V_30 = V_26 & 0x08 ;
F_15 ( V_6 , V_31 , V_4 , V_7 , V_8 , V_29 ) ;
F_3 ( V_6 , V_9 , V_4 , V_7 + V_8 - 1 , 1 , V_24 ) ;
V_28 = 1 << ( V_27 + 4 ) ;
V_25 = F_3 ( V_6 , V_32 , V_4 , V_7 + V_8 - 1 , 1 , V_24 ) ;
F_11 ( V_25 , L_9 , V_28 ) ;
}
static void
F_16 ( T_3 * V_4 , T_4 * T_5 , T_6 * V_6 , T_7 V_7 , T_7 V_8 , int V_9 )
{
T_9 * V_25 = NULL ;
char V_33 [ 6 ] ;
memset ( V_33 , '\0' , sizeof( V_33 ) ) ;
switch ( V_8 ) {
case 0 :
V_25 = F_17 ( V_6 , V_9 , V_4 , V_7 , V_8 , T_5 -> V_34 ) ;
F_11 ( V_25 , L_10 ) ;
return;
case 1 :
F_18 ( V_33 , sizeof( V_33 ) , L_11 , F_8 ( V_4 , V_7 ) ) ;
break;
case 2 :
F_18 ( V_33 , sizeof( V_33 ) , L_11 , F_13 ( V_4 , V_7 ) ) ;
break;
default:
F_7 ( T_5 , V_6 , V_19 , V_20 , L_6 , V_8 ) ;
return;
}
( void ) F_3 ( V_6 , V_9 , V_4 , V_7 , V_8 , V_24 ) ;
if ( V_15 [ 0 ] == '\0' )
F_4 ( V_15 , F_19 ( & T_5 -> V_35 ) , sizeof( V_15 ) ) ;
F_4 ( V_15 , L_12 , sizeof( V_15 ) ) ;
F_4 ( V_15 , V_33 , sizeof( V_15 ) ) ;
return;
}
static int
F_20 ( T_3 * V_4 , T_4 * T_5 , T_6 * V_36 , T_7 V_7 , T_1 V_37 , T_1 * V_10 )
{
T_1 V_38 ;
T_7 V_8 ;
T_6 * V_6 = NULL ;
T_9 * V_25 = NULL ;
T_7 V_39 = 0 ;
T_3 * V_40 = NULL ;
V_38 = ( F_8 ( V_4 , V_7 ) & 0xf0 ) >> 4 ;
* V_10 += V_38 ;
V_8 = ( F_8 ( V_4 , V_7 ) & 0x0f ) ;
V_39 = 1 ;
if ( V_8 == 0x0f ) {
V_8 += F_8 ( V_4 , V_7 + 1 ) ;
V_39 = 2 ;
}
V_25 = F_21 ( V_36 , V_4 , V_7 , V_39 + V_8 ,
L_13 ,
V_37 , F_9 ( * V_10 , V_41 , * V_10 % 14 == 0 ? L_14 : L_15 ) , * V_10 ) ;
V_6 = F_22 ( V_25 , V_42 ) ;
F_3 ( V_6 , V_43 , V_4 , V_7 , 1 , V_24 ) ;
V_40 = F_23 ( V_4 , V_7 , V_39 , V_39 ) ;
F_24 ( V_6 , V_44 , V_40 , 4 , V_39 == 1 ? 4 : 12 , V_8 , L_16 , V_8 ) ;
V_7 += V_39 ;
switch ( * V_10 ) {
case V_45 :
F_6 ( V_4 , T_5 , V_6 , V_7 , V_8 , V_46 ) ;
break;
case V_47 :
F_10 ( V_4 , T_5 , V_6 , V_7 , V_8 , V_48 ) ;
break;
case V_49 :
F_2 ( V_4 , T_5 , V_6 , V_7 , V_8 , V_50 , V_49 ) ;
break;
case V_51 :
F_2 ( V_4 , T_5 , V_6 , V_7 , V_8 , V_52 , V_51 ) ;
break;
case V_14 :
F_2 ( V_4 , T_5 , V_6 , V_7 , V_8 , V_53 , V_14 ) ;
break;
case V_54 :
F_2 ( V_4 , T_5 , V_6 , V_7 , V_8 , V_55 , V_54 ) ;
break;
case V_56 :
F_16 ( V_4 , T_5 , V_6 , V_7 , V_8 , V_57 ) ;
break;
case V_58 :
F_2 ( V_4 , T_5 , V_6 , V_7 , V_8 , V_59 , V_58 ) ;
break;
case V_16 :
F_2 ( V_4 , T_5 , V_6 , V_7 , V_8 , V_60 , V_16 ) ;
break;
case V_61 :
F_10 ( V_4 , T_5 , V_6 , V_7 , V_8 , V_62 ) ;
break;
case V_63 :
F_2 ( V_4 , T_5 , V_6 , V_7 , V_8 , V_64 , V_63 ) ;
break;
case V_65 :
F_6 ( V_4 , T_5 , V_6 , V_7 , V_8 , V_66 ) ;
break;
case V_67 :
F_2 ( V_4 , T_5 , V_6 , V_7 , V_8 , V_68 , V_67 ) ;
break;
case V_17 :
F_2 ( V_4 , T_5 , V_6 , V_7 , V_8 , V_69 , V_17 ) ;
break;
case V_70 :
F_12 ( V_4 , T_5 , V_6 , V_7 , V_8 , V_71 ) ;
break;
case V_72 :
F_12 ( V_4 , T_5 , V_6 , V_7 , V_8 , V_71 ) ;
break;
case V_73 :
F_2 ( V_4 , T_5 , V_6 , V_7 , V_8 , V_74 , V_73 ) ;
break;
default:
break;
}
return V_7 + V_8 ;
}
static void
F_25 ( T_3 * V_4 , T_4 * T_5 , T_6 * V_75 )
{
T_10 V_7 = 0 ;
T_9 * V_76 = NULL ;
T_6 * V_36 = NULL ;
T_1 V_77 = 0 ;
T_1 V_37 = 0 ;
T_1 V_78 = 0 ;
T_11 V_79 = 0 ;
T_10 V_80 = 0 ;
T_1 V_10 = 0 ;
int V_81 ;
F_26 ( T_5 -> V_82 , V_83 , L_17 ) ;
F_27 ( T_5 -> V_82 , V_84 ) ;
if ( ! V_75 )
return;
V_80 = F_28 ( V_4 ) ;
V_22 = NULL ;
V_21 = ~ 0 ;
V_76 = F_3 ( V_75 , V_85 , V_4 , V_7 , - 1 , V_13 ) ;
V_36 = F_22 ( V_76 , V_86 ) ;
F_3 ( V_36 , V_87 , V_4 , V_7 , 1 , V_24 ) ;
F_3 ( V_36 , V_88 , V_4 , V_7 , 1 , V_24 ) ;
V_77 = ( F_8 ( V_4 , V_7 ) & 0x30 ) >> 4 ;
F_29 ( T_5 -> V_82 , V_84 , L_18 , F_9 ( V_77 , V_89 , L_7 ) ) ;
F_3 ( V_36 , V_90 , V_4 , V_7 , 1 , V_24 ) ;
V_37 = F_8 ( V_4 , V_7 ) & 0x0f ;
V_7 += 1 ;
F_3 ( V_36 , V_91 , V_4 , V_7 , 1 , V_24 ) ;
V_78 = F_8 ( V_4 , V_7 ) ;
F_30 ( T_5 -> V_82 , V_84 , L_19 , F_9 ( V_78 , V_92 , L_7 ) ) ;
V_7 += 1 ;
F_3 ( V_36 , V_93 , V_4 , V_7 , 2 , V_24 ) ;
V_79 = F_13 ( V_4 , V_7 ) ;
V_7 += 2 ;
F_11 ( V_36 , L_20 , V_79 , V_80 ) ;
V_29 = ~ 0 ;
V_30 = 0 ;
V_15 [ 0 ] = 0 ;
for ( V_81 = 1 ; V_81 <= V_37 ; V_81 ++ ) {
V_7 = F_20 ( V_4 , T_5 , V_36 , V_7 , V_81 , & V_10 ) ;
if ( V_80 < V_7 ) {
F_21 ( V_36 , V_4 , 0 , 0 , L_21 , V_80 , V_7 ) ;
return;
}
}
if ( V_29 != ~ 0 ) {
F_30 ( T_5 -> V_82 , V_84 , L_22 , V_30 ? L_23 : L_24 , V_29 ) ;
}
if ( V_15 [ 0 ] != '\0' ) {
F_30 ( T_5 -> V_82 , V_84 , L_19 , V_15 ) ;
}
if ( V_80 > V_7 ) {
T_6 * V_94 = NULL ;
T_9 * V_95 = NULL ;
T_3 * V_96 ;
T_10 V_97 = V_80 - V_7 ;
const char * V_98 = L_23 ;
if ( V_21 == ~ 0 ) {
V_22 = L_25 ;
V_98 = L_10 ;
}
V_95 = F_21 ( V_36 , V_4 , V_7 , - 1 , L_26 ,
V_22 , V_98 , V_97 , V_7 ) ;
V_94 = F_22 ( V_95 , V_99 ) ;
V_96 = F_23 ( V_4 , V_7 , V_97 , V_97 ) ;
F_31 ( V_100 , V_22 , V_96 , T_5 , V_94 ) ;
}
}
void
F_32 ( void )
{
static T_12 V_101 [] = {
{ & V_87 , { L_27 , L_28 , V_102 , V_103 , NULL , 0xc0 , L_29 , V_104 } } ,
{ & V_88 , { L_30 , L_31 , V_102 , V_103 , F_33 ( V_89 ) , 0x30 , L_32 , V_104 } } ,
{ & V_90 , { L_33 , L_34 , V_102 , V_103 , NULL , 0x0f , L_35 , V_104 } } ,
{ & V_91 , { L_36 , L_37 , V_102 , V_103 , F_33 ( V_92 ) , 0x0 , L_38 , V_104 } } ,
{ & V_93 , { L_39 , L_40 , V_105 , V_103 , NULL , 0x0 , L_41 , V_104 } } ,
{ & V_43 , { L_42 , L_43 , V_102 , V_103 , NULL , 0xf0 , L_44 , V_104 } } ,
{ & V_44 , { L_45 , L_46 , V_105 , V_103 , NULL , 0x0 , L_47 , V_104 } } ,
{ & V_46 , { L_48 , L_49 , V_102 , V_103 , F_33 ( V_23 ) , 0x0 , L_50 , V_104 } } ,
{ & V_48 , { L_51 , L_52 , V_106 , V_103 , NULL , 0x0 , L_53 , V_104 } } ,
{ & V_50 , { L_54 , L_55 , V_107 , V_108 , NULL , 0x0 , L_56 , V_104 } } ,
{ & V_52 , { L_57 , L_58 , V_109 , V_108 , NULL , 0x0 , L_59 , V_104 } } ,
{ & V_53 , { L_60 , L_61 , V_107 , V_108 , NULL , 0x0 , L_62 , V_104 } } ,
{ & V_55 , { L_63 , L_64 , V_107 , V_108 , NULL , 0x0 , L_65 , V_104 } } ,
{ & V_57 , { L_66 , L_67 , V_105 , V_103 , NULL , 0x0 , L_68 , V_104 } } ,
{ & V_59 , { L_69 , L_70 , V_107 , V_108 , NULL , 0x0 , L_71 , V_104 } } ,
{ & V_60 , { L_72 , L_73 , V_107 , V_108 , NULL , 0x0 , L_74 , V_104 } } ,
{ & V_62 , { L_75 , L_76 , V_110 , V_103 , NULL , 0x0 , L_77 , V_104 } } ,
{ & V_64 , { L_78 , L_79 , V_109 , V_108 , NULL , 0x0 , L_80 , V_104 } } ,
{ & V_66 , { L_81 , L_82 , V_102 , V_103 , F_33 ( V_23 ) , 0x0 , L_83 , V_104 } } ,
{ & V_68 , { L_84 , L_85 , V_109 , V_108 , NULL , 0x0 , L_86 , V_104 } } ,
{ & V_31 , { L_87 , L_88 , V_110 , V_103 , NULL , 0x0 , L_89 , V_104 } } ,
{ & V_71 , { L_90 , L_91 , V_102 , V_103 , NULL , 0x08 , L_92 , V_104 } } ,
{ & V_32 , { L_93 , L_94 , V_102 , V_103 , NULL , 0x07 , L_95 , V_104 } } ,
{ & V_69 , { L_96 , L_97 , V_107 , V_108 , NULL , 0x0 , L_98 , V_104 } } ,
{ & V_74 , { L_99 , L_100 , V_109 , V_108 , NULL , 0x0 , L_101 , V_104 } } ,
} ;
static T_7 * V_111 [] = {
& V_86 ,
& V_42 ,
& V_99 ,
} ;
T_13 * V_112 ;
V_85 = F_34 ( L_102 , L_17 , L_103 ) ;
F_35 ( V_85 , V_101 , F_36 ( V_101 ) ) ;
F_37 ( V_111 , F_36 ( V_111 ) ) ;
F_38 ( L_103 , F_25 , V_85 ) ;
V_112 = F_39 ( V_85 , V_113 ) ;
F_40 ( V_112 , L_104 ,
L_105 ,
L_106 ,
10 , & V_114 ) ;
}
void
V_113 ( void )
{
static T_14 V_115 = FALSE ;
static T_15 V_116 ;
static T_10 V_117 ;
if ( ! V_115 ) {
V_116 = F_41 ( L_103 ) ;
V_100 = F_42 ( L_107 ) ;
V_115 = TRUE ;
} else {
F_43 ( L_108 , V_117 , V_116 ) ;
F_43 ( L_109 , V_117 , V_116 ) ;
}
V_117 = V_114 ;
F_44 ( L_108 , V_117 , V_116 ) ;
F_44 ( L_109 , V_117 , V_116 ) ;
}
