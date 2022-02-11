void F_1 ( void )
{
T_1 * V_1 ;
char * V_2 , V_3 [ 512 ] ;
F_2 ( & V_4 ) ;
V_5 = V_4 . V_6 ;
V_7 = V_4 . V_8 ;
V_2 = strchr ( V_5 , '-' ) ;
if ( V_2 )
* V_2 = '\0' ;
V_1 = fopen ( L_1 , L_2 ) ;
if ( V_1 != NULL )
goto V_9;
V_1 = fopen ( L_3 , L_2 ) ;
if ( V_1 != NULL )
goto V_9;
V_10 = V_4 . V_11 ;
return;
V_9:
V_2 = fgets ( V_3 , sizeof( V_3 ) , V_1 ) ;
if ( V_2 ) {
V_2 = strchr ( V_3 , '\n' ) ;
if ( V_2 )
* V_2 = '\0' ;
V_2 = F_3 ( V_3 ) ;
if ( ! V_2 )
goto V_12;
V_10 = V_2 ;
V_2 = fgets ( V_3 , sizeof( V_3 ) , V_1 ) ;
if ( V_2 ) {
V_2 = strchr ( V_3 , '\n' ) ;
if ( V_2 )
* V_2 = '\0' ;
V_2 = F_3 ( V_3 ) ;
if ( ! V_2 )
goto V_12;
V_13 = V_2 ;
V_2 = fgets ( V_3 , sizeof( V_3 ) , V_1 ) ;
if ( V_2 ) {
V_2 = strchr ( V_3 , '\n' ) ;
if ( V_2 )
* V_2 = '\0' ;
V_2 = F_3 ( V_3 ) ;
if ( V_2 )
V_14 = V_2 ;
}
}
}
V_12:
fclose ( V_1 ) ;
return;
}
static int
F_4 ( int V_15 , char * V_16 , int V_17 )
{
struct V_18 * V_19 ;
struct V_18 * V_20 ;
int V_21 = strlen ( L_4 ) + 1 ;
int V_22 = strlen ( L_5 ) + 1 ;
int V_23 = 0 ;
const char * V_24 ;
char V_25 [ 50 ] ;
int error = 0 ;
if ( F_5 ( & V_19 ) ) {
strcpy ( V_16 , L_6 ) ;
return 1 ;
}
V_20 = V_19 ;
while ( V_20 != NULL ) {
if ( ( V_20 -> V_26 != NULL ) &&
( V_20 -> V_26 -> V_27 == V_15 ) ) {
if ( V_15 == V_28 ) {
struct V_29 * V_30 =
(struct V_29 * ) V_20 -> V_26 ;
V_24 = F_6 ( V_15 , & V_30 -> V_31 ,
V_25 , 50 ) ;
if ( V_24 == NULL ) {
strcpy ( V_16 , L_7 ) ;
error = 1 ;
goto V_32;
}
if ( V_23 == 0 )
strcpy ( V_16 , V_25 ) ;
else
strcat ( V_16 , V_25 ) ;
strcat ( V_16 , L_8 ) ;
V_23 += strlen ( V_24 ) + 1 ;
if ( ( V_17 - V_23 ) < ( V_21 + 1 ) )
goto V_32;
} else {
struct V_33 * V_30 =
(struct V_33 * ) V_20 -> V_26 ;
V_24 = F_6 ( V_15 ,
& V_30 -> V_34 . V_35 ,
V_25 , 50 ) ;
if ( V_24 == NULL ) {
strcpy ( V_16 , L_7 ) ;
error = 1 ;
goto V_32;
}
if ( V_23 == 0 )
strcpy ( V_16 , V_25 ) ;
else
strcat ( V_16 , V_25 ) ;
strcat ( V_16 , L_8 ) ;
V_23 += strlen ( V_24 ) + 1 ;
if ( ( V_17 - V_23 ) < ( V_22 + 1 ) )
goto V_32;
}
}
V_20 = V_20 -> V_36 ;
}
V_32:
F_7 ( V_19 ) ;
return error ;
}
static int
F_8 ( char * V_16 , int V_17 )
{
struct V_37 V_38 , * V_39 ;
int error = 0 ;
F_9 ( V_16 , V_17 ) ;
memset ( & V_38 , 0 , sizeof( V_38 ) ) ;
V_38 . V_40 = V_28 ;
V_38 . V_41 = V_42 ;
V_38 . V_43 = V_44 ;
error = F_10 ( V_16 , NULL , & V_38 , & V_39 ) ;
if ( error != 0 ) {
strcpy ( V_16 , L_9 ) ;
return error ;
}
strcpy ( V_16 , V_39 -> V_45 ) ;
F_11 ( V_39 ) ;
return error ;
}
static int
F_12 ( int V_46 , struct V_47 * V_48 )
{
struct V_49 * V_50 ;
unsigned int V_51 ;
struct V_52 V_53 ;
char V_16 [ 64 ] ;
struct V_54 V_55 [ 2 ] ;
V_51 = F_13 ( sizeof( struct V_47 ) + V_48 -> V_56 ) ;
V_50 = (struct V_49 * ) V_16 ;
V_50 -> V_57 = 0 ;
V_50 -> V_58 = F_14 () ;
V_50 -> V_59 = V_60 ;
V_50 -> V_61 = F_15 ( V_51 - sizeof( * V_50 ) ) ;
V_50 -> V_62 = 0 ;
V_55 [ 0 ] . V_63 = V_50 ;
V_55 [ 0 ] . V_64 = sizeof( * V_50 ) ;
V_55 [ 1 ] . V_63 = V_48 ;
V_55 [ 1 ] . V_64 = V_51 ;
memset ( & V_53 , 0 , sizeof( V_53 ) ) ;
V_53 . V_65 = & V_30 ;
V_53 . V_66 = sizeof( V_30 ) ;
V_53 . V_67 = V_55 ;
V_53 . V_68 = 2 ;
return F_16 ( V_46 , & V_53 , 0 ) ;
}
int main ( void )
{
int V_46 , V_56 , V_69 ;
int error ;
struct V_47 * V_53 ;
struct V_70 V_71 ;
struct V_49 * V_72 ;
struct V_47 * V_73 ;
struct V_74 * V_75 ;
char * V_2 ;
char * V_76 ;
char * V_77 ;
F_17 ( 1 , 0 ) ;
F_18 ( L_10 , 0 , V_78 ) ;
F_19 ( V_79 , L_11 , F_14 () ) ;
F_1 () ;
V_46 = F_20 ( V_80 , V_81 , V_82 ) ;
if ( V_46 < 0 ) {
F_19 ( V_83 , L_12 , V_46 ) ;
exit ( - 1 ) ;
}
V_30 . V_84 = V_80 ;
V_30 . V_85 = 0 ;
V_30 . V_86 = 0 ;
V_30 . V_87 = V_88 ;
error = F_21 ( V_46 , (struct V_89 * ) & V_30 , sizeof( V_30 ) ) ;
if ( error < 0 ) {
F_19 ( V_83 , L_13 , error ) ;
F_22 ( V_46 ) ;
exit ( - 1 ) ;
}
V_69 = V_30 . V_87 ;
F_23 ( V_46 , 270 , 1 , & V_69 , sizeof( V_69 ) ) ;
V_53 = (struct V_47 * ) V_90 ;
V_53 -> V_91 . V_92 = V_88 ;
V_53 -> V_91 . V_93 = V_94 ;
V_53 -> V_95 = V_96 ;
V_53 -> V_97 = 0 ;
V_53 -> V_56 = 0 ;
V_56 = F_12 ( V_46 , V_53 ) ;
if ( V_56 < 0 ) {
F_19 ( V_83 , L_14 , V_56 ) ;
F_22 ( V_46 ) ;
exit ( - 1 ) ;
}
V_71 . V_46 = V_46 ;
while ( 1 ) {
V_71 . V_98 = V_99 ;
V_71 . V_100 = 0 ;
F_24 ( & V_71 , 1 , - 1 ) ;
V_56 = F_25 ( V_46 , V_101 , sizeof( V_101 ) , 0 ) ;
if ( V_56 < 0 ) {
F_19 ( V_83 , L_15 , V_56 ) ;
F_22 ( V_46 ) ;
return - 1 ;
}
V_72 = (struct V_49 * ) V_101 ;
V_73 = (struct V_47 * ) F_26 ( V_72 ) ;
switch ( V_73 -> V_95 ) {
case V_96 :
V_2 = ( char * ) V_73 -> V_102 ;
V_103 = malloc ( strlen ( V_2 ) + 1 ) ;
if ( V_103 ) {
strcpy ( V_103 , V_2 ) ;
F_19 ( V_79 , L_16 ,
V_103 ) ;
} else {
F_19 ( V_83 , L_17 ) ;
}
continue;
case V_104 :
break;
default:
continue;
}
V_75 = (struct V_74 * ) V_73 -> V_102 ;
V_77 = ( char * ) V_75 -> V_105 ;
V_76 = ( char * ) V_75 -> V_106 ;
switch ( V_75 -> V_107 ) {
case V_108 :
F_8 ( V_76 ,
V_109 ) ;
strcpy ( V_77 , L_18 ) ;
break;
case V_110 :
strcpy ( V_77 , L_19 ) ;
strcpy ( V_76 , V_103 ) ;
break;
case V_111 :
F_4 ( V_28 , V_76 ,
V_109 ) ;
strcpy ( V_77 , L_20 ) ;
break;
case V_112 :
F_4 ( V_113 , V_76 ,
V_109 ) ;
strcpy ( V_77 , L_21 ) ;
break;
case V_114 :
strcpy ( V_76 , V_5 ) ;
strcpy ( V_77 , L_22 ) ;
break;
case V_115 :
strcpy ( V_76 , V_10 ) ;
strcpy ( V_77 , L_23 ) ;
break;
case V_116 :
strcpy ( V_76 , V_13 ) ;
strcpy ( V_77 , L_24 ) ;
break;
case V_117 :
strcpy ( V_76 , V_14 ) ;
strcpy ( V_77 , L_25 ) ;
break;
case V_118 :
strcpy ( V_76 , V_5 ) ;
strcpy ( V_77 , L_26 ) ;
break;
case V_119 :
strcpy ( V_76 , V_7 ) ;
strcpy ( V_77 , L_27 ) ;
break;
default:
strcpy ( V_76 , L_28 ) ;
strcpy ( V_77 , L_29 ) ;
break;
}
V_73 -> V_91 . V_92 = V_88 ;
V_73 -> V_91 . V_93 = V_94 ;
V_73 -> V_95 = V_120 ;
V_73 -> V_97 = 0 ;
V_73 -> V_56 = sizeof( struct V_74 ) ;
V_56 = F_12 ( V_46 , V_73 ) ;
if ( V_56 < 0 ) {
F_19 ( V_83 , L_30 , V_56 ) ;
exit ( - 1 ) ;
}
}
}
