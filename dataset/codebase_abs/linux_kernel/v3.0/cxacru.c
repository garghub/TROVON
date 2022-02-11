static T_1 F_1 ( T_2 V_1 , char * V_2 )
{
return snprintf ( V_2 , V_3 , L_1 , V_1 ) ;
}
static T_1 F_2 ( T_3 V_1 , char * V_2 )
{
return snprintf ( V_2 , V_3 , L_2 , V_1 ) ;
}
static T_1 F_3 ( T_4 V_1 , char * V_2 )
{
if ( F_4 ( V_1 >= 0 ) ) {
return snprintf ( V_2 , V_3 , L_3 ,
V_1 / 100 , V_1 % 100 ) ;
} else {
V_1 = - V_1 ;
return snprintf ( V_2 , V_3 , L_4 ,
V_1 / 100 , V_1 % 100 ) ;
}
}
static T_1 F_5 ( T_2 V_1 , char * V_2 )
{
static char * V_4 [] = { L_5 , L_6 } ;
if ( F_6 ( V_1 >= F_7 ( V_4 ) ) )
return snprintf ( V_2 , V_3 , L_1 , V_1 ) ;
return snprintf ( V_2 , V_3 , L_7 , V_4 [ V_1 ] ) ;
}
static T_1 F_8 ( T_2 V_1 , char * V_2 )
{
static char * V_4 [] = { NULL , L_8 , L_9 , L_10 } ;
if ( F_6 ( V_1 >= F_7 ( V_4 ) || V_4 [ V_1 ] == NULL ) )
return snprintf ( V_2 , V_3 , L_1 , V_1 ) ;
return snprintf ( V_2 , V_3 , L_7 , V_4 [ V_1 ] ) ;
}
static T_1 F_9 ( T_2 V_1 , char * V_2 )
{
static char * V_4 [] = { L_11 , L_12 ,
L_13 , L_14 , L_15 , L_16 ,
L_17 , L_18
} ;
if ( F_6 ( V_1 >= F_7 ( V_4 ) ) )
return snprintf ( V_2 , V_3 , L_1 , V_1 ) ;
return snprintf ( V_2 , V_3 , L_7 , V_4 [ V_1 ] ) ;
}
static T_1 F_10 ( T_2 V_1 , char * V_2 )
{
static char * V_4 [] = {
L_19 ,
L_20 ,
L_21 ,
L_22
} ;
if ( F_6 ( V_1 >= F_7 ( V_4 ) ) )
return snprintf ( V_2 , V_3 , L_1 , V_1 ) ;
return snprintf ( V_2 , V_3 , L_7 , V_4 [ V_1 ] ) ;
}
static T_1 F_11 ( struct V_5 * V_6 ,
struct V_7 * V_8 , char * V_2 )
{
struct V_9 * V_10 = F_12 (
F_13 ( V_6 ) ) ;
if ( V_10 == NULL || V_10 -> V_11 -> V_12 == NULL )
return - V_13 ;
return snprintf ( V_2 , V_3 , L_23 ,
V_10 -> V_11 -> V_12 -> V_14 ) ;
}
static T_1 F_14 ( struct V_5 * V_6 ,
struct V_7 * V_8 , char * V_2 )
{
static char * V_4 [] = { L_24 , L_25 } ;
struct V_9 * V_10 = F_12 (
F_13 ( V_6 ) ) ;
T_2 V_1 ;
if ( V_10 == NULL )
return - V_13 ;
V_1 = V_10 -> V_15 [ V_16 ] ;
if ( F_6 ( V_1 >= F_7 ( V_4 ) ) )
return snprintf ( V_2 , V_3 , L_1 , V_1 ) ;
return snprintf ( V_2 , V_3 , L_7 , V_4 [ V_1 ] ) ;
}
static T_1 F_15 ( struct V_5 * V_6 ,
struct V_7 * V_8 , const char * V_2 , T_5 V_17 )
{
struct V_9 * V_10 = F_12 (
F_13 ( V_6 ) ) ;
int V_18 ;
int V_19 = - 1 ;
char V_20 [ 8 ] ;
int V_21 = strlen ( V_2 ) ;
if ( ! F_16 ( V_22 ) )
return - V_23 ;
V_18 = sscanf ( V_2 , L_26 , V_20 ) ;
if ( V_18 != 1 )
return - V_24 ;
V_18 = 0 ;
if ( V_10 == NULL )
return - V_13 ;
if ( F_17 ( & V_10 -> V_25 ) )
return - V_26 ;
if ( ! strcmp ( V_20 , L_27 ) || ! strcmp ( V_20 , L_28 ) ) {
V_18 = F_18 ( V_10 , V_27 , NULL , 0 , NULL , 0 ) ;
if ( V_18 < 0 ) {
F_19 ( V_10 -> V_11 , L_29
L_30 , V_18 ) ;
V_18 = - V_28 ;
} else {
V_18 = V_21 ;
V_19 = V_29 ;
}
}
if ( ! strcmp ( V_20 , L_28 ) )
F_20 ( 1500 ) ;
if ( ! strcmp ( V_20 , L_31 ) || ! strcmp ( V_20 , L_28 ) ) {
V_18 = F_18 ( V_10 , V_30 , NULL , 0 , NULL , 0 ) ;
if ( V_18 < 0 ) {
F_19 ( V_10 -> V_11 , L_29
L_32 , V_18 ) ;
V_18 = - V_28 ;
} else {
V_18 = V_21 ;
V_19 = V_31 ;
}
}
if ( ! strcmp ( V_20 , L_33 ) ) {
V_18 = V_21 ;
V_19 = V_31 ;
}
if ( V_18 == 0 ) {
V_18 = - V_24 ;
V_19 = - 1 ;
}
if ( V_19 == V_31 ) {
F_21 ( & V_10 -> V_32 ) ;
switch ( V_10 -> V_33 ) {
case V_29 :
V_10 -> V_33 = V_31 ;
break;
case V_34 :
V_10 -> V_33 = V_31 ;
case V_31 :
case V_35 :
V_19 = - 1 ;
}
F_22 ( & V_10 -> V_32 ) ;
} else if ( V_19 == V_29 ) {
F_21 ( & V_10 -> V_32 ) ;
if ( V_10 -> V_33 == V_31 )
V_10 -> V_33 = V_34 ;
F_22 ( & V_10 -> V_32 ) ;
}
F_22 ( & V_10 -> V_25 ) ;
if ( V_19 == V_31 )
F_23 ( & V_10 -> V_36 . V_37 ) ;
return V_18 ;
}
static T_1 F_24 ( struct V_5 * V_6 ,
struct V_7 * V_8 , const char * V_2 , T_5 V_17 )
{
struct V_9 * V_10 = F_12 (
F_13 ( V_6 ) ) ;
int V_21 = strlen ( V_2 ) ;
int V_18 , V_38 , V_39 ;
T_6 V_40 [ V_41 / 4 ] ;
if ( ! F_16 ( V_22 ) )
return - V_23 ;
if ( V_10 == NULL )
return - V_13 ;
V_38 = 0 ;
V_39 = 0 ;
while ( V_38 < V_21 ) {
int V_42 ;
T_2 V_43 ;
T_2 V_1 ;
V_18 = sscanf ( V_2 + V_38 , L_34 , & V_43 , & V_1 , & V_42 ) ;
if ( V_18 < 2 )
return - V_24 ;
if ( V_43 < 0 || V_43 > 0x7f )
return - V_24 ;
V_38 += V_42 ;
if ( V_2 [ V_38 ] == '\n' && V_38 == V_21 - 1 )
V_38 ++ ;
V_40 [ V_39 * 2 + 1 ] = F_25 ( V_43 ) ;
V_40 [ V_39 * 2 + 2 ] = F_25 ( V_1 ) ;
V_39 ++ ;
if ( V_38 >= V_21 || V_39 >= V_44 ) {
char log [ V_44 * 12 + 1 ] ;
V_40 [ 0 ] = F_25 ( V_39 ) ;
V_18 = F_18 ( V_10 , V_45 ,
( V_46 * ) V_40 , 4 + V_39 * 8 , NULL , 0 ) ;
if ( V_18 < 0 ) {
F_19 ( V_10 -> V_11 ,
L_35 , V_18 ) ;
return - V_28 ;
}
for ( V_42 = 0 ; V_42 < V_39 ; V_42 ++ )
snprintf ( log + V_42 * 12 , 13 , L_36 ,
F_26 ( V_40 [ V_42 * 2 + 1 ] ) ,
F_26 ( V_40 [ V_42 * 2 + 2 ] ) ) ;
F_27 ( V_10 -> V_11 , L_37 , log ) ;
V_39 = 0 ;
}
}
return V_21 ;
}
static void F_28 ( struct V_47 * V_47 )
{
F_29 ( V_47 -> V_48 ) ;
}
static void F_30 ( unsigned long V_40 )
{
F_31 ( (struct V_47 * ) V_40 ) ;
}
static int F_32 ( struct V_47 * V_47 , struct V_49 * V_50 ,
int * V_51 )
{
struct V_52 V_53 ;
F_33 ( & V_53 ) ;
V_53 . V_54 = V_55 + F_34 ( V_56 ) ;
V_53 . V_40 = ( unsigned long ) V_47 ;
V_53 . V_57 = F_30 ;
F_35 ( & V_53 ) ;
F_36 ( V_50 ) ;
F_37 ( & V_53 ) ;
if ( V_51 )
* V_51 = V_47 -> V_51 ;
return V_47 -> V_58 ;
}
static int F_18 ( struct V_9 * V_10 , enum V_59 V_60 ,
V_46 * V_61 , int V_62 , V_46 * V_63 , int V_64 )
{
int V_18 , V_65 ;
int V_66 , V_67 ;
const int V_68 = V_41 - 4 ;
V_46 * V_69 = V_10 -> V_70 ;
V_46 * V_71 = V_10 -> V_72 ;
int V_73 = ( ( V_62 - 1 ) / V_68 + 1 ) * V_41 ;
int V_74 = ( ( V_64 - 1 ) / V_68 + 1 ) * V_41 ;
if ( V_73 > V_3 || V_74 > V_3 ) {
if ( F_38 () )
F_39 ( V_10 -> V_11 , L_38 ,
V_73 , V_74 ) ;
V_18 = - V_75 ;
goto V_76;
}
F_21 ( & V_10 -> V_77 ) ;
F_40 ( & V_10 -> V_78 ) ;
V_18 = F_41 ( V_10 -> V_79 , V_80 ) ;
if ( V_18 < 0 ) {
if ( F_38 () )
F_39 ( V_10 -> V_11 , L_39 ,
V_60 , V_18 ) ;
goto V_81;
}
memset ( V_69 , 0 , V_73 ) ;
V_69 [ 0 ] = V_60 ;
for ( V_66 = V_67 = 0 ; V_67 < V_62 ; V_67 += V_68 , V_66 += V_41 ) {
V_69 [ V_66 ] = V_60 ;
memcpy ( V_69 + V_66 + 4 , V_61 + V_67 , F_42 ( int , V_68 , V_62 - V_67 ) ) ;
}
V_10 -> V_82 -> V_83 = V_73 ;
F_40 ( & V_10 -> V_84 ) ;
V_18 = F_41 ( V_10 -> V_82 , V_80 ) ;
if ( V_18 < 0 ) {
if ( F_38 () )
F_39 ( V_10 -> V_11 , L_40 ,
V_60 , V_18 ) ;
goto V_81;
}
V_18 = F_32 ( V_10 -> V_82 , & V_10 -> V_84 , NULL ) ;
if ( V_18 < 0 ) {
if ( F_38 () )
F_39 ( V_10 -> V_11 , L_41 , V_60 , V_18 ) ;
goto V_81;
}
V_18 = F_32 ( V_10 -> V_79 , & V_10 -> V_78 , & V_65 ) ;
if ( V_18 < 0 ) {
if ( F_38 () )
F_39 ( V_10 -> V_11 , L_42 , V_60 , V_18 ) ;
goto V_81;
}
if ( V_65 % V_41 || ! V_65 ) {
if ( F_38 () )
F_39 ( V_10 -> V_11 , L_43 ,
V_60 , V_65 ) ;
V_18 = - V_28 ;
goto V_81;
}
for ( V_66 = V_67 = 0 ; V_67 < V_64 && V_66 < V_65 ; V_66 += V_41 ) {
if ( V_71 [ V_66 ] != V_60 ) {
if ( F_38 () )
F_39 ( V_10 -> V_11 , L_44 ,
V_71 [ V_66 ] , V_60 ) ;
V_18 = - V_28 ;
goto V_81;
}
if ( V_71 [ V_66 + 1 ] != V_85 ) {
if ( F_38 () )
F_39 ( V_10 -> V_11 , L_45 ,
V_60 , V_71 [ V_66 + 1 ] ) ;
V_18 = - V_28 ;
goto V_81;
}
if ( V_67 >= V_64 )
break;
memcpy ( V_63 + V_67 , V_71 + V_66 + 4 , F_42 ( int , V_68 , V_64 - V_67 ) ) ;
V_67 += V_68 ;
}
V_18 = V_67 ;
F_43 ( L_46 , V_60 ) ;
V_81:
F_22 ( & V_10 -> V_77 ) ;
V_76:
return V_18 ;
}
static int F_44 ( struct V_9 * V_10 , enum V_59 V_60 ,
T_2 * V_40 , int V_86 )
{
int V_18 , V_21 ;
T_6 * V_2 ;
int V_66 , V_67 ;
const int V_68 = V_41 / ( 4 * 2 ) - 1 ;
int V_87 = ( ( V_86 - 1 ) / V_68 + 1 + V_86 * 2 ) * 4 ;
V_2 = F_45 ( V_87 , V_80 ) ;
if ( ! V_2 )
return - V_75 ;
V_18 = F_18 ( V_10 , V_60 , NULL , 0 , ( V_46 * ) V_2 , V_87 ) ;
if ( V_18 < 0 )
goto V_88;
V_21 = V_18 / 4 ;
for ( V_66 = 0 ; V_66 < V_21 ; ) {
int V_89 = F_26 ( V_2 [ V_66 ++ ] ) ;
if ( V_89 < 0 || V_89 > V_68 || V_89 > ( V_21 - V_66 ) / 2 ) {
if ( F_38 () )
F_39 ( V_10 -> V_11 , L_47 ,
V_60 , V_89 ) ;
V_18 = - V_28 ;
goto V_88;
}
while ( V_89 -- ) {
V_67 = F_26 ( V_2 [ V_66 ++ ] ) ;
if ( V_67 >= V_86 ) {
if ( F_38 () )
F_39 ( V_10 -> V_11 , L_48 ,
V_67 , V_60 ) ;
V_18 = - V_28 ;
goto V_88;
}
V_40 [ V_67 ] = F_26 ( V_2 [ V_66 ++ ] ) ;
}
}
V_18 = 0 ;
V_88:
F_46 ( V_2 ) ;
return V_18 ;
}
static int F_47 ( struct V_9 * V_10 )
{
int V_18 = F_18 ( V_10 , V_90 , NULL , 0 , NULL , 0 ) ;
if ( V_18 < 0 ) {
F_43 ( L_49 , V_18 ) ;
return V_18 ;
}
return 0 ;
}
static void F_48 ( struct V_91 * V_92 ,
struct V_12 * V_12 )
{
struct V_93 * V_94 = V_92 -> V_95 ;
#define F_49 ( T_7 ) \
device_remove_file(&intf->dev, &dev_attr_##_name);
F_50 ( REMOVE ) ;
#undef F_49
}
static int F_51 ( struct V_91 * V_92 ,
struct V_12 * V_12 )
{
struct V_9 * V_10 = V_92 -> V_96 ;
struct V_93 * V_94 = V_92 -> V_95 ;
int V_18 ;
int V_97 = 1 ;
F_43 ( L_50 ) ;
V_18 = F_18 ( V_10 , V_98 , NULL , 0 ,
V_12 -> V_14 , sizeof( V_12 -> V_14 ) ) ;
if ( V_18 < 0 ) {
F_19 ( V_92 , L_51 , V_18 ) ;
return V_18 ;
}
#define F_52 ( T_7 ) \
ret = device_create_file(&intf->dev, &dev_attr_##_name); \
if (unlikely(ret)) \
goto fail_sysfs;
F_50 ( V_99 ) ;
#undef F_52
F_21 ( & V_10 -> V_25 ) ;
V_18 = F_18 ( V_10 , V_30 , NULL , 0 , NULL , 0 ) ;
if ( V_18 < 0 )
F_19 ( V_92 , L_52 , V_18 ) ;
F_21 ( & V_10 -> V_32 ) ;
switch ( V_10 -> V_33 ) {
case V_29 :
V_10 -> V_33 = V_31 ;
break;
case V_34 :
V_10 -> V_33 = V_31 ;
case V_31 :
case V_35 :
V_97 = 0 ;
}
F_22 ( & V_10 -> V_32 ) ;
F_22 ( & V_10 -> V_25 ) ;
F_53 ( V_100 L_53 , V_12 -> type , V_12 -> V_101 ,
V_92 -> V_102 , V_12 -> V_14 ) ;
if ( V_97 )
F_23 ( & V_10 -> V_36 . V_37 ) ;
return 0 ;
V_103:
F_39 ( V_92 , L_54 , V_18 ) ;
F_48 ( V_92 , V_12 ) ;
return V_18 ;
}
static void F_23 ( struct V_104 * V_37 )
{
struct V_9 * V_10 =
F_54 ( V_37 , struct V_9 , V_36 . V_37 ) ;
T_2 V_2 [ V_105 ] = {} ;
struct V_91 * V_11 = V_10 -> V_11 ;
struct V_12 * V_12 = V_11 -> V_12 ;
int V_106 = 1 ;
int V_18 ;
V_18 = F_44 ( V_10 , V_107 , V_2 , V_105 ) ;
if ( V_18 < 0 ) {
if ( V_18 != - V_108 )
F_55 ( V_11 , L_55 , V_18 ) ;
F_21 ( & V_10 -> V_32 ) ;
if ( V_10 -> V_33 != V_35 ) {
V_10 -> V_33 = V_29 ;
if ( V_18 != - V_108 )
F_55 ( V_11 , L_56
L_57 ) ;
}
F_22 ( & V_10 -> V_32 ) ;
goto V_109;
}
memcpy ( V_10 -> V_15 , V_2 , sizeof( V_10 -> V_15 ) ) ;
if ( V_10 -> V_110 != V_2 [ V_16 ] ) {
V_10 -> V_110 = V_2 [ V_16 ] ;
switch ( V_10 -> V_110 ) {
case 0 :
F_56 ( V_100 , V_11 , L_58 ) ;
break;
case 1 :
F_56 ( V_100 , V_11 , L_59 ) ;
break;
default:
F_56 ( V_100 , V_11 , L_60 , V_10 -> V_110 ) ;
break;
}
}
if ( V_10 -> V_111 == V_2 [ V_112 ] )
goto V_109;
V_10 -> V_111 = V_2 [ V_112 ] ;
switch ( V_10 -> V_111 ) {
case 0 :
F_57 ( V_12 , V_113 ) ;
F_27 ( V_11 , L_61 ) ;
break;
case 1 :
F_57 ( V_12 , V_113 ) ;
F_27 ( V_11 , L_62 ) ;
break;
case 2 :
F_57 ( V_12 , V_113 ) ;
F_27 ( V_11 , L_63 ) ;
break;
case 3 :
F_57 ( V_12 , V_113 ) ;
F_27 ( V_11 , L_64 ) ;
break;
case 4 :
F_57 ( V_12 , V_113 ) ;
F_27 ( V_11 , L_65 ) ;
break;
case 5 :
V_12 -> V_114 = V_2 [ V_115 ] * 1000 / 424 ;
F_57 ( V_12 , V_116 ) ;
F_27 ( V_11 , L_66 ,
V_2 [ V_115 ] , V_2 [ V_117 ] ) ;
break;
case 6 :
F_57 ( V_12 , V_113 ) ;
F_27 ( V_11 , L_67 ) ;
break;
case 7 :
F_57 ( V_12 , V_113 ) ;
F_27 ( V_11 , L_68 ) ;
break;
default:
F_57 ( V_12 , V_118 ) ;
F_27 ( V_11 , L_69 , V_10 -> V_111 ) ;
break;
}
V_109:
F_21 ( & V_10 -> V_32 ) ;
if ( V_10 -> V_33 == V_34 &&
V_10 -> V_110 == 1 &&
V_10 -> V_111 == 0 )
V_10 -> V_33 = V_29 ;
if ( V_10 -> V_33 == V_29 )
V_106 = 0 ;
F_22 ( & V_10 -> V_32 ) ;
if ( V_106 )
F_58 ( & V_10 -> V_36 ,
F_59 ( V_119 * V_120 ) ) ;
}
static int F_60 ( struct V_121 * V_122 , enum V_123 V_124 ,
V_46 V_125 , V_46 V_126 , T_2 V_127 , const V_46 * V_40 , int V_86 )
{
int V_18 ;
V_46 * V_2 ;
int V_67 , V_66 ;
const int V_68 = V_41 - 8 ;
V_2 = ( V_46 * ) F_61 ( V_80 ) ;
if ( ! V_2 )
return - V_75 ;
V_66 = V_67 = 0 ;
do {
int V_89 = F_42 ( int , V_68 , V_86 - V_67 ) ;
V_2 [ V_66 ++ ] = V_124 ;
V_2 [ V_66 ++ ] = V_89 ;
V_2 [ V_66 ++ ] = V_125 ;
V_2 [ V_66 ++ ] = V_126 ;
F_62 ( F_25 ( V_127 ) , ( T_6 * ) ( V_2 + V_66 ) ) ;
V_66 += 4 ;
V_127 += V_89 ;
if ( V_89 )
memcpy ( V_2 + V_66 , V_40 + V_67 , V_89 ) ;
if ( V_89 < V_68 )
memset ( V_2 + V_66 + V_89 , 0 , V_68 - V_89 ) ;
V_66 += V_68 ;
V_67 += V_68 ;
if ( ( V_66 >= V_3 ) || ( V_67 >= V_86 ) ) {
V_18 = F_63 ( V_122 , F_64 ( V_122 , V_128 ) ,
V_2 , V_66 , NULL , V_56 ) ;
if ( V_18 < 0 ) {
F_43 ( L_70 , V_124 ) ;
goto V_88;
}
V_66 = 0 ;
}
} while ( V_67 < V_86 );
F_43 ( L_71 , V_124 ) ;
V_18 = 0 ;
V_88:
F_65 ( ( unsigned long ) V_2 ) ;
return V_18 ;
}
static void F_66 ( struct V_9 * V_10 ,
const struct V_129 * V_124 ,
const struct V_129 * V_130 )
{
int V_18 ;
struct V_91 * V_11 = V_10 -> V_11 ;
struct V_121 * V_122 = V_11 -> V_122 ;
T_8 V_131 [] = { V_122 -> V_132 . V_133 ,
V_122 -> V_132 . V_134 } ;
T_6 V_135 ;
F_43 ( L_72 ) ;
V_135 = F_25 ( V_10 -> V_136 -> V_137 ) ;
V_18 = F_60 ( V_122 , V_138 , 0x2 , 0x0 , V_139 , ( V_46 * ) & V_135 , 4 ) ;
if ( V_18 ) {
F_39 ( V_11 , L_73 , V_18 ) ;
return;
}
V_135 = F_25 ( V_10 -> V_136 -> V_140 ) ;
V_18 = F_60 ( V_122 , V_138 , 0x2 , 0x0 , V_141 , ( V_46 * ) & V_135 , 4 ) ;
if ( V_18 ) {
F_39 ( V_11 , L_74 , V_18 ) ;
return;
}
V_135 = F_25 ( V_142 ) ;
V_18 = F_60 ( V_122 , V_138 , 0x2 , 0x0 , V_143 , ( V_46 * ) & V_135 , 4 ) ;
if ( V_18 ) {
F_39 ( V_11 , L_75 , V_18 ) ;
return;
}
F_67 ( V_11 , L_76 ) ;
V_18 = F_60 ( V_122 , V_138 , 0x2 , 0x0 , V_144 , V_124 -> V_40 , V_124 -> V_86 ) ;
if ( V_18 ) {
F_39 ( V_11 , L_77 , V_18 ) ;
return;
}
if ( V_10 -> V_136 -> V_145 ) {
F_67 ( V_11 , L_78 ) ;
V_18 = F_60 ( V_122 , V_138 , 0x2 , 0x0 , V_146 , V_130 -> V_40 , V_130 -> V_86 ) ;
if ( V_18 ) {
F_39 ( V_11 , L_79 , V_18 ) ;
return;
}
}
V_18 = F_60 ( V_122 , V_138 , 0x2 , 0x0 , V_147 , ( V_46 * ) V_131 , 4 ) ;
if ( V_18 ) {
F_39 ( V_11 , L_80 , V_18 ) ;
return;
}
F_67 ( V_11 , L_81 ) ;
if ( V_10 -> V_136 -> V_145 ) {
V_135 = F_25 ( V_146 ) ;
V_18 = F_60 ( V_122 , V_138 , 0x2 , 0x0 , V_148 , ( V_46 * ) & V_135 , 4 ) ;
} else {
V_18 = F_60 ( V_122 , V_149 , 0x0 , 0x0 , V_144 , NULL , 0 ) ;
}
if ( V_18 ) {
F_39 ( V_11 , L_82 , V_18 ) ;
return;
}
F_68 ( 1000 ) ;
F_69 ( V_122 , F_64 ( V_122 , V_128 ) ) ;
F_69 ( V_122 , F_70 ( V_122 , V_128 ) ) ;
F_69 ( V_122 , F_64 ( V_122 , V_150 ) ) ;
F_69 ( V_122 , F_70 ( V_122 , V_150 ) ) ;
V_18 = F_18 ( V_10 , V_90 , NULL , 0 , NULL , 0 ) ;
if ( V_18 < 0 ) {
F_39 ( V_11 , L_83 , V_18 ) ;
return;
}
}
static int F_71 ( struct V_9 * V_10 ,
char * V_151 , const struct V_129 * * V_152 )
{
struct V_91 * V_11 = V_10 -> V_11 ;
struct V_5 * V_6 = & V_11 -> V_95 -> V_6 ;
char V_2 [ 16 ] ;
sprintf ( V_2 , L_84 , V_151 ) ;
F_43 ( L_85 , V_2 ) ;
if ( F_72 ( V_152 , V_2 , V_6 ) ) {
F_73 ( V_11 , L_86 , V_151 ) ;
return - V_153 ;
}
F_67 ( V_11 , L_87 , V_2 ) ;
return 0 ;
}
static int F_74 ( struct V_91 * V_92 ,
struct V_93 * V_95 )
{
const struct V_129 * V_124 , * V_130 ;
struct V_9 * V_10 = V_92 -> V_96 ;
int V_18 = F_71 ( V_10 , L_88 , & V_124 ) ;
if ( V_18 ) {
F_75 ( V_92 , L_89 ) ;
return V_18 ;
}
if ( V_10 -> V_136 -> V_145 ) {
V_18 = F_71 ( V_10 , L_90 , & V_130 ) ;
if ( V_18 ) {
F_75 ( V_92 , L_91 ) ;
F_76 ( V_124 ) ;
return V_18 ;
}
}
F_66 ( V_10 , V_124 , V_130 ) ;
if ( V_10 -> V_136 -> V_145 )
F_76 ( V_130 ) ;
F_76 ( V_124 ) ;
V_18 = F_47 ( V_10 ) ;
if ( V_18 )
F_43 ( L_92 ) ;
else
F_43 ( L_93 ) ;
return V_18 ;
}
static int F_77 ( struct V_91 * V_92 ,
struct V_93 * V_94 , const struct V_154 * V_155 )
{
struct V_9 * V_10 ;
struct V_121 * V_122 = F_78 ( V_94 ) ;
struct V_156 * V_157 = V_122 -> V_158 [ V_128 ] ;
int V_18 ;
V_10 = F_79 ( sizeof( * V_10 ) , V_80 ) ;
if ( ! V_10 ) {
F_43 ( L_94 ) ;
return - V_75 ;
}
V_10 -> V_11 = V_92 ;
V_10 -> V_136 = (struct V_159 * ) V_155 -> V_160 ;
F_80 ( & V_10 -> V_32 ) ;
V_10 -> V_33 = V_29 ;
V_10 -> V_111 = - 1 ;
V_10 -> V_110 = - 1 ;
F_80 ( & V_10 -> V_25 ) ;
V_10 -> V_72 = ( V_46 * ) F_61 ( V_80 ) ;
if ( ! V_10 -> V_72 ) {
F_43 ( L_95 ) ;
V_18 = - V_75 ;
goto V_81;
}
V_10 -> V_70 = ( V_46 * ) F_61 ( V_80 ) ;
if ( ! V_10 -> V_70 ) {
F_43 ( L_96 ) ;
V_18 = - V_75 ;
goto V_81;
}
V_10 -> V_79 = F_81 ( 0 , V_80 ) ;
if ( ! V_10 -> V_79 ) {
F_43 ( L_97 ) ;
V_18 = - V_75 ;
goto V_81;
}
V_10 -> V_82 = F_81 ( 0 , V_80 ) ;
if ( ! V_10 -> V_82 ) {
F_43 ( L_98 ) ;
V_18 = - V_75 ;
goto V_81;
}
if ( ! V_157 ) {
F_43 ( L_99 ) ;
V_18 = - V_13 ;
goto V_81;
}
if ( ( V_157 -> V_161 . V_162 & V_163 )
== V_164 ) {
F_82 ( V_10 -> V_79 ,
V_122 , F_83 ( V_122 , V_128 ) ,
V_10 -> V_72 , V_3 ,
F_28 , & V_10 -> V_78 , 1 ) ;
F_82 ( V_10 -> V_82 ,
V_122 , F_84 ( V_122 , V_128 ) ,
V_10 -> V_70 , V_3 ,
F_28 , & V_10 -> V_84 , 4 ) ;
} else {
F_85 ( V_10 -> V_79 ,
V_122 , F_70 ( V_122 , V_128 ) ,
V_10 -> V_72 , V_3 ,
F_28 , & V_10 -> V_78 ) ;
F_85 ( V_10 -> V_82 ,
V_122 , F_64 ( V_122 , V_128 ) ,
V_10 -> V_70 , V_3 ,
F_28 , & V_10 -> V_84 ) ;
}
F_80 ( & V_10 -> V_77 ) ;
F_86 ( & V_10 -> V_36 , F_23 ) ;
V_92 -> V_96 = V_10 ;
V_92 -> V_165 = ( F_47 ( V_10 ) ? 0 : V_166 ) ;
return 0 ;
V_81:
F_65 ( ( unsigned long ) V_10 -> V_70 ) ;
F_65 ( ( unsigned long ) V_10 -> V_72 ) ;
F_87 ( V_10 -> V_82 ) ;
F_87 ( V_10 -> V_79 ) ;
F_46 ( V_10 ) ;
return V_18 ;
}
static void F_88 ( struct V_91 * V_92 ,
struct V_93 * V_94 )
{
struct V_9 * V_10 = V_92 -> V_96 ;
int V_167 = 1 ;
F_43 ( L_100 ) ;
if ( ! V_10 ) {
F_43 ( L_101 ) ;
return;
}
F_21 ( & V_10 -> V_32 ) ;
F_89 ( V_10 -> V_33 == V_35 ) ;
if ( V_10 -> V_33 == V_29 )
V_167 = 0 ;
V_10 -> V_33 = V_35 ;
F_22 ( & V_10 -> V_32 ) ;
if ( V_167 )
F_90 ( & V_10 -> V_36 ) ;
F_91 ( V_10 -> V_82 ) ;
F_91 ( V_10 -> V_79 ) ;
F_87 ( V_10 -> V_82 ) ;
F_87 ( V_10 -> V_79 ) ;
F_65 ( ( unsigned long ) V_10 -> V_70 ) ;
F_65 ( ( unsigned long ) V_10 -> V_72 ) ;
F_46 ( V_10 ) ;
V_92 -> V_96 = NULL ;
}
static int F_92 ( struct V_93 * V_94 ,
const struct V_154 * V_155 )
{
struct V_121 * V_122 = F_78 ( V_94 ) ;
char V_2 [ 15 ] ;
if ( V_122 -> V_132 . V_168 == V_169
&& F_93 ( V_122 , V_122 -> V_132 . V_170 ,
V_2 , sizeof( V_2 ) ) > 0 ) {
if ( ! strcmp ( V_2 , L_102 ) ) {
F_94 ( & V_94 -> V_6 , L_103 ) ;
return - V_13 ;
}
}
return F_95 ( V_94 , V_155 , & V_171 ) ;
}
static int T_9 F_96 ( void )
{
return F_97 ( & V_172 ) ;
}
static void T_10 F_98 ( void )
{
F_99 ( & V_172 ) ;
}
