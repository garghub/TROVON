void F_1 ( void )
{
T_1 * V_1 ;
char * V_2 , V_3 [ 512 ] ;
F_2 ( & V_4 ) ;
V_5 = V_4 . V_6 ;
V_7 = V_4 . V_8 ;
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
F_9 ( V_16 , V_17 ) ;
int error = 0 ;
memset ( & V_38 , 0 , sizeof( V_38 ) ) ;
V_38 . V_40 = V_28 ;
V_38 . V_41 = V_42 ;
V_38 . V_43 = V_44 ;
error = F_10 ( V_16 , L_9 , & V_38 , & V_39 ) ;
if ( error != 0 ) {
strcpy ( V_16 , L_10 ) ;
error = 1 ;
goto V_45;
}
strcpy ( V_16 , V_39 -> V_46 ) ;
V_45:
F_11 ( V_39 ) ;
return error ;
}
static int
F_12 ( int V_47 , struct V_48 * V_49 )
{
struct V_50 * V_51 ;
unsigned int V_52 ;
struct V_53 V_54 ;
char V_16 [ 64 ] ;
struct V_55 V_56 [ 2 ] ;
V_52 = F_13 ( sizeof( struct V_48 ) + V_49 -> V_57 ) ;
V_51 = (struct V_50 * ) V_16 ;
V_51 -> V_58 = 0 ;
V_51 -> V_59 = F_14 () ;
V_51 -> V_60 = V_61 ;
V_51 -> V_62 = F_15 ( V_52 - sizeof( * V_51 ) ) ;
V_51 -> V_63 = 0 ;
V_56 [ 0 ] . V_64 = V_51 ;
V_56 [ 0 ] . V_65 = sizeof( * V_51 ) ;
V_56 [ 1 ] . V_64 = V_49 ;
V_56 [ 1 ] . V_65 = V_52 ;
memset ( & V_54 , 0 , sizeof( V_54 ) ) ;
V_54 . V_66 = & V_30 ;
V_54 . V_67 = sizeof( V_30 ) ;
V_54 . V_68 = V_56 ;
V_54 . V_69 = 2 ;
return F_16 ( V_47 , & V_54 , 0 ) ;
}
int main ( void )
{
int V_47 , V_57 , V_70 ;
int error ;
struct V_48 * V_54 ;
struct V_71 V_72 ;
struct V_50 * V_73 ;
struct V_48 * V_74 ;
struct V_75 * V_76 ;
char * V_2 ;
char * V_77 ;
char * V_78 ;
F_17 ( 1 , 0 ) ;
F_18 ( L_11 , 0 , V_79 ) ;
F_19 ( V_80 , L_12 , F_14 () ) ;
F_1 () ;
V_47 = F_20 ( V_81 , V_82 , V_83 ) ;
if ( V_47 < 0 ) {
F_19 ( V_84 , L_13 , V_47 ) ;
exit ( - 1 ) ;
}
V_30 . V_85 = V_81 ;
V_30 . V_86 = 0 ;
V_30 . V_87 = 0 ;
V_30 . V_88 = V_89 ;
error = F_21 ( V_47 , (struct V_90 * ) & V_30 , sizeof( V_30 ) ) ;
if ( error < 0 ) {
F_19 ( V_84 , L_14 , error ) ;
F_22 ( V_47 ) ;
exit ( - 1 ) ;
}
V_70 = V_30 . V_88 ;
F_23 ( V_47 , 270 , 1 , & V_70 , sizeof( V_70 ) ) ;
V_54 = (struct V_48 * ) V_91 ;
V_54 -> V_92 . V_93 = V_89 ;
V_54 -> V_92 . V_94 = V_95 ;
V_54 -> V_96 = V_97 ;
V_54 -> V_98 = 0 ;
V_54 -> V_57 = 0 ;
V_57 = F_12 ( V_47 , V_54 ) ;
if ( V_57 < 0 ) {
F_19 ( V_84 , L_15 , V_57 ) ;
F_22 ( V_47 ) ;
exit ( - 1 ) ;
}
V_72 . V_47 = V_47 ;
while ( 1 ) {
V_72 . V_99 = V_100 ;
V_72 . V_101 = 0 ;
F_24 ( & V_72 , 1 , - 1 ) ;
V_57 = F_25 ( V_47 , V_102 , sizeof( V_102 ) , 0 ) ;
if ( V_57 < 0 ) {
F_19 ( V_84 , L_16 , V_57 ) ;
F_22 ( V_47 ) ;
return - 1 ;
}
V_73 = (struct V_50 * ) V_102 ;
V_74 = (struct V_48 * ) F_26 ( V_73 ) ;
switch ( V_74 -> V_96 ) {
case V_97 :
V_2 = ( char * ) V_74 -> V_103 ;
V_104 = malloc ( strlen ( V_2 ) + 1 ) ;
if ( V_104 ) {
strcpy ( V_104 , V_2 ) ;
F_19 ( V_80 , L_17 ,
V_104 ) ;
} else {
F_19 ( V_84 , L_18 ) ;
}
continue;
case V_105 :
break;
default:
continue;
}
V_76 = (struct V_75 * ) V_74 -> V_103 ;
V_78 = ( char * ) V_76 -> V_106 ;
V_77 = ( char * ) V_76 -> V_107 ;
switch ( V_76 -> V_108 ) {
case V_109 :
F_8 ( V_77 ,
V_110 ) ;
strcpy ( V_78 , L_19 ) ;
break;
case V_111 :
strcpy ( V_78 , L_20 ) ;
strcpy ( V_77 , V_104 ) ;
break;
case V_112 :
F_4 ( V_28 , V_77 ,
V_110 ) ;
strcpy ( V_78 , L_21 ) ;
break;
case V_113 :
F_4 ( V_114 , V_77 ,
V_110 ) ;
strcpy ( V_78 , L_22 ) ;
break;
case V_115 :
strcpy ( V_77 , V_5 ) ;
strcpy ( V_78 , L_23 ) ;
break;
case V_116 :
strcpy ( V_77 , V_10 ) ;
strcpy ( V_78 , L_24 ) ;
break;
case V_117 :
strcpy ( V_77 , V_13 ) ;
strcpy ( V_78 , L_25 ) ;
break;
case V_118 :
strcpy ( V_77 , V_14 ) ;
strcpy ( V_78 , L_26 ) ;
break;
case V_119 :
strcpy ( V_77 , V_5 ) ;
strcpy ( V_78 , L_27 ) ;
break;
case V_120 :
strcpy ( V_77 , V_7 ) ;
strcpy ( V_78 , L_28 ) ;
break;
default:
strcpy ( V_77 , L_29 ) ;
strcpy ( V_78 , L_30 ) ;
break;
}
V_74 -> V_92 . V_93 = V_89 ;
V_74 -> V_92 . V_94 = V_95 ;
V_74 -> V_96 = V_121 ;
V_74 -> V_98 = 0 ;
V_74 -> V_57 = sizeof( struct V_75 ) ;
V_57 = F_12 ( V_47 , V_74 ) ;
if ( V_57 < 0 ) {
F_19 ( V_84 , L_31 , V_57 ) ;
exit ( - 1 ) ;
}
}
}
