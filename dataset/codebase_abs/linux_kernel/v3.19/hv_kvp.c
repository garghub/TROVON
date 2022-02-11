static void
F_1 ( int V_1 )
{
struct V_2 * V_3 ;
struct V_4 * V_5 ;
char * V_6 ;
V_3 = F_2 ( sizeof( * V_3 ) + sizeof( struct V_4 ) , V_7 ) ;
if ( V_3 ) {
V_5 = (struct V_4 * ) V_3 -> V_8 ;
V_6 = V_5 -> V_9 . F_1 . V_6 ;
V_3 -> V_10 . V_11 = V_12 ;
V_3 -> V_10 . V_13 = V_14 ;
V_5 -> V_15 . V_16 = V_1 ;
strcpy ( V_6 , V_17 ) ;
V_3 -> V_18 = sizeof( struct V_4 ) ;
F_3 ( V_3 , 0 , 0 , V_7 ) ;
F_4 ( V_3 ) ;
}
}
static void
F_5 ( struct V_19 * V_20 )
{
F_6 ( NULL , V_21 ) ;
}
static void F_7 ( struct V_22 * V_23 )
{
if ( V_23 -> V_24 != F_8 () )
F_9 ( V_23 -> V_24 ,
V_25 ,
V_23 , true ) ;
else
V_25 ( V_23 ) ;
}
static int F_10 ( struct V_4 * V_3 )
{
int V_26 = 1 ;
switch ( V_3 -> V_15 . V_16 ) {
case V_27 :
V_28 = V_27 ;
F_11 ( L_1 ) ;
F_11 ( L_2 ) ;
break;
case V_29 :
V_28 = V_29 ;
break;
default:
F_11 ( L_3 ) ;
F_11 ( L_4 ,
V_29 , V_3 -> V_15 . V_16 ) ;
V_26 = 0 ;
}
if ( V_26 ) {
F_11 ( L_5 ) ;
F_1 ( V_28 ) ;
V_30 . V_31 = false ;
if ( V_30 . V_32 )
F_7 ( V_30 . V_32 ) ;
}
return V_26 ;
}
static void
F_12 ( struct V_2 * V_3 , struct V_33 * V_34 )
{
struct V_4 * V_35 ;
struct V_36 * V_8 ;
int error = 0 ;
V_35 = (struct V_4 * ) V_3 -> V_8 ;
if ( V_37 ) {
if ( F_10 ( V_35 ) )
V_37 = false ;
return;
}
V_8 = & V_35 -> V_9 . V_38 ;
switch ( V_28 ) {
case V_27 :
if ( V_8 -> V_8 . V_39 [ 0 ] == 0 )
error = V_40 ;
break;
case V_29 :
error = V_35 -> error ;
break;
}
if ( F_13 ( & V_41 ) )
F_6 ( V_35 , error ) ;
}
static int F_14 ( void * V_42 , void * V_43 , int V_44 )
{
struct V_4 * V_45 = V_42 ;
struct V_46 * V_47 = V_43 ;
int V_18 ;
switch ( V_44 ) {
case V_48 :
V_18 = F_15 ( ( char * ) V_45 -> V_9 . V_49 . V_50 ,
strlen ( ( char * ) V_45 -> V_9 . V_49 . V_50 ) ,
V_51 ,
( V_52 * ) V_47 -> V_49 . V_50 ,
V_53 ) ;
if ( V_18 < 0 )
return V_18 ;
V_18 = F_15 ( ( char * ) V_45 -> V_9 . V_49 . V_54 ,
strlen ( ( char * ) V_45 -> V_9 . V_49 . V_54 ) ,
V_51 ,
( V_52 * ) V_47 -> V_49 . V_54 ,
V_53 ) ;
if ( V_18 < 0 )
return V_18 ;
V_18 = F_15 ( ( char * ) V_45 -> V_9 . V_49 . V_55 ,
strlen ( ( char * ) V_45 -> V_9 . V_49 . V_55 ) ,
V_51 ,
( V_52 * ) V_47 -> V_49 . V_55 ,
V_56 ) ;
if ( V_18 < 0 )
return V_18 ;
V_18 = F_15 ( ( char * ) V_45 -> V_9 . V_49 . V_57 ,
strlen ( ( char * ) V_45 -> V_9 . V_49 . V_57 ) ,
V_51 ,
( V_52 * ) V_47 -> V_49 . V_57 ,
V_53 ) ;
if ( V_18 < 0 )
return V_18 ;
V_18 = F_15 ( ( char * ) V_45 -> V_9 . V_49 . V_58 ,
strlen ( ( char * ) V_45 -> V_9 . V_49 . V_58 ) ,
V_51 ,
( V_52 * ) V_47 -> V_49 . V_58 ,
V_53 ) ;
if ( V_18 < 0 )
return V_18 ;
V_47 -> V_49 . V_59 =
V_45 -> V_9 . V_49 . V_59 ;
V_47 -> V_49 . V_60 =
V_45 -> V_9 . V_49 . V_60 ;
}
return 0 ;
}
static void F_16 ( void * V_42 , void * V_43 , int V_44 )
{
struct V_46 * V_45 = V_42 ;
struct V_4 * V_47 = V_43 ;
switch ( V_44 ) {
case V_61 :
F_17 ( ( V_52 * ) V_45 -> V_49 . V_50 ,
V_53 ,
V_62 ,
( V_63 * ) V_47 -> V_9 . V_49 . V_50 ,
V_53 ) ;
F_17 ( ( V_52 * ) V_45 -> V_49 . V_54 ,
V_53 ,
V_62 ,
( V_63 * ) V_47 -> V_9 . V_49 . V_54 ,
V_53 ) ;
F_17 ( ( V_52 * ) V_45 -> V_49 . V_55 ,
V_56 ,
V_62 ,
( V_63 * ) V_47 -> V_9 . V_49 . V_55 ,
V_56 ) ;
F_17 ( ( V_52 * ) V_45 -> V_49 . V_57 ,
V_53 ,
V_62 ,
( V_63 * ) V_47 -> V_9 . V_49 . V_57 ,
V_53 ) ;
V_47 -> V_9 . V_49 . V_59 = V_45 -> V_49 . V_59 ;
default:
F_17 ( ( V_52 * ) V_45 -> V_49 . V_58 ,
V_64 ,
V_62 ,
( V_63 * ) V_47 -> V_9 . V_49 . V_58 ,
V_64 ) ;
V_47 -> V_9 . V_49 . V_60 = V_45 -> V_49 . V_60 ;
}
}
static void
F_18 ( struct V_19 * V_20 )
{
struct V_2 * V_3 ;
struct V_4 * V_35 ;
struct V_4 * V_42 ;
V_63 V_16 = V_30 . V_5 -> V_15 . V_16 ;
V_63 V_65 = V_30 . V_5 -> V_15 . V_65 ;
T_1 V_66 ;
T_2 V_67 ;
int V_68 ;
V_3 = F_2 ( sizeof( * V_3 ) + sizeof( struct V_4 ) , V_7 ) ;
if ( ! V_3 )
return;
V_3 -> V_10 . V_11 = V_12 ;
V_3 -> V_10 . V_13 = V_14 ;
V_35 = (struct V_4 * ) V_3 -> V_8 ;
V_35 -> V_15 . V_16 = V_16 ;
V_35 -> V_15 . V_65 = V_65 ;
V_42 = V_30 . V_5 ;
switch ( V_35 -> V_15 . V_16 ) {
case V_61 :
F_16 ( V_42 , V_35 , V_61 ) ;
break;
case V_48 :
F_16 ( V_42 , V_35 , V_48 ) ;
break;
case V_69 :
switch ( V_42 -> V_9 . V_70 . V_8 . V_71 ) {
case V_72 :
V_35 -> V_9 . V_70 . V_8 . V_73 =
F_17 (
( V_52 * ) V_42 -> V_9 . V_70 . V_8 . V_74 ,
V_42 -> V_9 . V_70 . V_8 . V_73 ,
V_62 ,
V_35 -> V_9 . V_70 . V_8 . V_74 ,
V_75 - 1 ) + 1 ;
break;
case V_76 :
V_66 = V_42 -> V_9 . V_70 . V_8 . V_77 ;
V_35 -> V_9 . V_70 . V_8 . V_73 =
sprintf ( V_35 -> V_9 . V_70 . V_8 . V_74 ,
L_6 , V_66 ) + 1 ;
break;
case V_78 :
V_67 = V_42 -> V_9 . V_70 . V_8 . V_79 ;
V_35 -> V_9 . V_70 . V_8 . V_73 =
sprintf ( V_35 -> V_9 . V_70 . V_8 . V_74 ,
L_7 , V_67 ) + 1 ;
break;
}
case V_80 :
V_35 -> V_9 . V_70 . V_8 . V_81 =
F_17 (
( V_52 * ) V_42 -> V_9 . V_70 . V_8 . V_39 ,
V_42 -> V_9 . V_70 . V_8 . V_81 ,
V_62 ,
V_35 -> V_9 . V_70 . V_8 . V_39 ,
V_82 - 1 ) + 1 ;
break;
case V_83 :
V_35 -> V_9 . V_84 . V_81 =
F_17 (
( V_52 * ) V_42 -> V_9 . V_84 . V_39 ,
V_42 -> V_9 . V_84 . V_81 ,
V_62 ,
V_35 -> V_9 . V_84 . V_39 ,
V_82 - 1 ) + 1 ;
break;
case V_85 :
V_35 -> V_9 . V_38 . V_86 =
V_42 -> V_9 . V_38 . V_86 ;
break;
}
V_3 -> V_18 = sizeof( struct V_4 ) ;
V_68 = F_3 ( V_3 , 0 , 0 , V_7 ) ;
if ( V_68 ) {
F_19 ( L_8 , V_68 ) ;
if ( F_13 ( & V_41 ) )
F_6 ( V_35 , V_21 ) ;
}
F_4 ( V_3 ) ;
return;
}
static void
F_6 ( struct V_4 * V_87 , int error )
{
struct V_4 * V_5 ;
struct V_88 * V_89 ;
char * V_90 ;
char * V_74 ;
struct V_91 * V_92 ;
int V_93 = 0 ;
int V_94 = 0 ;
T_3 V_95 ;
struct V_22 * V_23 ;
T_4 V_96 ;
int V_26 ;
if ( ! V_30 . V_31 ) {
F_20 ( L_9 ) ;
return;
}
V_95 = V_30 . V_97 ;
V_23 = V_30 . V_98 ;
V_96 = V_30 . V_99 ;
V_30 . V_31 = false ;
V_92 = (struct V_91 * )
& V_100 [ sizeof( struct V_101 ) ] ;
if ( V_23 -> V_102 == NULL )
return;
V_92 -> V_103 = error ;
if ( error ) {
goto V_104;
}
V_5 = (struct V_4 * )
& V_100 [ sizeof( struct V_101 ) +
sizeof( struct V_91 ) ] ;
switch ( V_30 . V_5 -> V_15 . V_16 ) {
case V_48 :
V_26 = F_14 ( V_87 ,
(struct V_46 * ) V_5 ,
V_48 ) ;
if ( V_26 < 0 )
V_92 -> V_103 = V_21 ;
goto V_104;
case V_61 :
goto V_104;
case V_80 :
V_89 = & V_5 -> V_9 . V_105 . V_8 ;
goto V_106;
case V_69 :
case V_83 :
goto V_104;
default:
break;
}
V_89 = & V_5 -> V_9 . V_38 . V_8 ;
V_90 = V_87 -> V_9 . V_38 . V_8 . V_39 ;
V_93 = F_15 ( V_90 , strlen ( V_90 ) , V_51 ,
( V_52 * ) V_89 -> V_39 ,
( V_82 / 2 ) - 2 ) ;
V_89 -> V_81 = 2 * ( V_93 + 1 ) ;
V_106:
V_74 = V_87 -> V_9 . V_38 . V_8 . V_74 ;
V_94 = F_15 ( V_74 , strlen ( V_74 ) , V_51 ,
( V_52 * ) V_89 -> V_74 ,
( V_75 / 2 ) - 2 ) ;
V_89 -> V_73 = 2 * ( V_94 + 1 ) ;
if ( ( V_93 < 0 ) || ( V_94 < 0 ) )
V_92 -> V_103 = V_21 ;
V_89 -> V_71 = V_72 ;
V_104:
V_92 -> V_107 = V_108 | V_109 ;
F_21 ( V_23 , V_100 , V_95 , V_96 ,
V_110 , 0 ) ;
F_7 ( V_23 ) ;
}
void V_25 ( void * V_111 )
{
struct V_22 * V_23 = V_111 ;
T_3 V_112 ;
T_4 V_113 ;
struct V_4 * V_5 ;
struct V_91 * V_92 ;
struct V_114 * V_115 = NULL ;
int V_116 ;
int V_117 ;
if ( V_30 . V_31 ) {
V_30 . V_32 = V_111 ;
return;
}
F_22 ( V_23 , V_100 , V_118 * 4 , & V_112 ,
& V_113 ) ;
if ( V_112 > 0 ) {
V_92 = (struct V_91 * ) & V_100 [
sizeof( struct V_101 ) ] ;
if ( V_92 -> V_119 == V_120 ) {
switch ( V_121 ) {
case ( V_122 ) :
V_116 = V_123 ;
V_117 = V_124 ;
break;
case ( V_125 ) :
V_116 = V_126 ;
V_117 = V_127 ;
break;
default:
V_116 = V_126 ;
V_117 = V_128 ;
}
F_23 ( V_92 , V_115 ,
V_100 , V_116 ,
V_117 ) ;
} else {
V_5 = (struct V_4 * ) & V_100 [
sizeof( struct V_101 ) +
sizeof( struct V_91 ) ] ;
V_30 . V_97 = V_112 ;
V_30 . V_98 = V_23 ;
V_30 . V_99 = V_113 ;
V_30 . V_31 = true ;
V_30 . V_5 = V_5 ;
F_24 ( & V_129 ) ;
F_25 ( & V_41 , 5 * V_130 ) ;
return;
}
V_92 -> V_107 = V_108
| V_109 ;
F_21 ( V_23 , V_100 ,
V_112 , V_113 ,
V_110 , 0 ) ;
}
}
int
F_26 ( struct V_131 * V_132 )
{
int V_133 ;
V_133 = F_27 ( & V_134 , V_135 , F_12 ) ;
if ( V_133 )
return V_133 ;
V_100 = V_132 -> V_100 ;
V_30 . V_31 = true ;
return 0 ;
}
void F_28 ( void )
{
F_29 ( & V_134 ) ;
F_13 ( & V_41 ) ;
F_30 ( & V_129 ) ;
}
