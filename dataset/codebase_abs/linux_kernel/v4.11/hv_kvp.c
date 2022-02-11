static void F_1 ( void * V_1 )
{
V_2 . V_3 = V_4 ;
F_2 ( V_1 ) ;
}
static void F_3 ( void )
{
F_4 ( L_1 ) ;
F_5 ( & V_5 ) ;
F_6 ( V_2 . V_6 , F_1 ) ;
}
static void
F_7 ( int V_7 )
{
struct V_8 * V_9 ;
char * V_10 ;
V_9 = F_8 ( sizeof( * V_9 ) , V_11 ) ;
if ( V_9 ) {
V_10 = V_9 -> V_12 . F_7 . V_10 ;
V_9 -> V_13 . V_14 = V_7 ;
strcpy ( V_10 , V_15 ) ;
F_9 ( V_16 , V_9 , sizeof( * V_9 ) ,
F_3 ) ;
F_10 ( V_9 ) ;
}
}
static void F_11 ( struct V_17 * V_18 )
{
F_12 ( NULL , V_19 ) ;
F_6 ( V_2 . V_6 , F_1 ) ;
}
static void F_13 ( struct V_17 * V_18 )
{
F_6 ( V_2 . V_6 , F_2 ) ;
}
static int F_14 ( struct V_8 * V_20 )
{
switch ( V_20 -> V_13 . V_14 ) {
case V_21 :
V_22 = V_21 ;
F_15 ( L_2 ) ;
F_15 ( L_3 ) ;
break;
case V_23 :
V_22 = V_23 ;
break;
default:
F_15 ( L_4 ) ;
F_15 ( L_5 ,
V_23 , V_20 -> V_13 . V_14 ) ;
return - V_24 ;
}
F_4 ( L_6 ,
V_20 -> V_13 . V_14 ) ;
F_7 ( V_22 ) ;
return 0 ;
}
static int F_16 ( void * V_20 , int V_25 )
{
struct V_8 * V_26 = (struct V_8 * ) V_20 ;
struct V_27 * V_28 ;
int error = 0 ;
if ( V_25 < sizeof( * V_26 ) )
return - V_24 ;
if ( V_2 . V_3 < V_4 ) {
return F_14 ( V_26 ) ;
}
if ( V_2 . V_3 < V_29 )
return - V_24 ;
V_2 . V_3 = V_30 ;
V_28 = & V_26 -> V_12 . V_31 ;
switch ( V_22 ) {
case V_21 :
if ( V_28 -> V_28 . V_32 [ 0 ] == 0 )
error = V_33 ;
break;
case V_23 :
error = V_26 -> error ;
break;
}
if ( F_5 ( & V_34 ) ) {
F_12 ( V_26 , error ) ;
F_6 ( V_2 . V_6 , F_1 ) ;
}
return 0 ;
}
static int F_17 ( void * V_35 , void * V_36 , int V_37 )
{
struct V_8 * V_38 = V_35 ;
struct V_39 * V_40 = V_36 ;
int V_25 ;
switch ( V_37 ) {
case V_41 :
V_25 = F_18 ( ( char * ) V_38 -> V_12 . V_42 . V_43 ,
strlen ( ( char * ) V_38 -> V_12 . V_42 . V_43 ) ,
V_44 ,
( V_45 * ) V_40 -> V_42 . V_43 ,
V_46 ) ;
if ( V_25 < 0 )
return V_25 ;
V_25 = F_18 ( ( char * ) V_38 -> V_12 . V_42 . V_47 ,
strlen ( ( char * ) V_38 -> V_12 . V_42 . V_47 ) ,
V_44 ,
( V_45 * ) V_40 -> V_42 . V_47 ,
V_46 ) ;
if ( V_25 < 0 )
return V_25 ;
V_25 = F_18 ( ( char * ) V_38 -> V_12 . V_42 . V_48 ,
strlen ( ( char * ) V_38 -> V_12 . V_42 . V_48 ) ,
V_44 ,
( V_45 * ) V_40 -> V_42 . V_48 ,
V_49 ) ;
if ( V_25 < 0 )
return V_25 ;
V_25 = F_18 ( ( char * ) V_38 -> V_12 . V_42 . V_50 ,
strlen ( ( char * ) V_38 -> V_12 . V_42 . V_50 ) ,
V_44 ,
( V_45 * ) V_40 -> V_42 . V_50 ,
V_46 ) ;
if ( V_25 < 0 )
return V_25 ;
V_25 = F_18 ( ( char * ) V_38 -> V_12 . V_42 . V_51 ,
strlen ( ( char * ) V_38 -> V_12 . V_42 . V_51 ) ,
V_44 ,
( V_45 * ) V_40 -> V_42 . V_51 ,
V_46 ) ;
if ( V_25 < 0 )
return V_25 ;
V_40 -> V_42 . V_52 =
V_38 -> V_12 . V_42 . V_52 ;
V_40 -> V_42 . V_53 =
V_38 -> V_12 . V_42 . V_53 ;
}
return 0 ;
}
static void F_19 ( void * V_35 , void * V_36 , int V_37 )
{
struct V_39 * V_38 = V_35 ;
struct V_8 * V_40 = V_36 ;
switch ( V_37 ) {
case V_54 :
F_20 ( ( V_45 * ) V_38 -> V_42 . V_43 ,
V_46 ,
V_55 ,
( V_56 * ) V_40 -> V_12 . V_42 . V_43 ,
V_46 ) ;
F_20 ( ( V_45 * ) V_38 -> V_42 . V_47 ,
V_46 ,
V_55 ,
( V_56 * ) V_40 -> V_12 . V_42 . V_47 ,
V_46 ) ;
F_20 ( ( V_45 * ) V_38 -> V_42 . V_48 ,
V_49 ,
V_55 ,
( V_56 * ) V_40 -> V_12 . V_42 . V_48 ,
V_49 ) ;
F_20 ( ( V_45 * ) V_38 -> V_42 . V_50 ,
V_46 ,
V_55 ,
( V_56 * ) V_40 -> V_12 . V_42 . V_50 ,
V_46 ) ;
V_40 -> V_12 . V_42 . V_52 = V_38 -> V_42 . V_52 ;
default:
F_20 ( ( V_45 * ) V_38 -> V_42 . V_51 ,
V_57 ,
V_55 ,
( V_56 * ) V_40 -> V_12 . V_42 . V_51 ,
V_57 ) ;
V_40 -> V_12 . V_42 . V_53 = V_38 -> V_42 . V_53 ;
}
}
static void
F_21 ( struct V_17 * V_18 )
{
struct V_8 * V_26 ;
struct V_8 * V_35 ;
V_56 V_14 = V_2 . V_9 -> V_13 . V_14 ;
V_56 V_58 = V_2 . V_9 -> V_13 . V_58 ;
T_1 V_59 ;
T_2 V_60 ;
int V_61 ;
if ( V_2 . V_3 != V_62 )
return;
V_26 = F_8 ( sizeof( * V_26 ) , V_11 ) ;
if ( ! V_26 )
return;
V_26 -> V_13 . V_14 = V_14 ;
V_26 -> V_13 . V_58 = V_58 ;
V_35 = V_2 . V_9 ;
switch ( V_26 -> V_13 . V_14 ) {
case V_54 :
F_19 ( V_35 , V_26 , V_54 ) ;
break;
case V_41 :
F_19 ( V_35 , V_26 , V_41 ) ;
break;
case V_63 :
switch ( V_35 -> V_12 . V_64 . V_28 . V_65 ) {
case V_66 :
V_26 -> V_12 . V_64 . V_28 . V_67 =
F_20 (
( V_45 * ) V_35 -> V_12 . V_64 . V_28 . V_68 ,
V_35 -> V_12 . V_64 . V_28 . V_67 ,
V_55 ,
V_26 -> V_12 . V_64 . V_28 . V_68 ,
V_69 - 1 ) + 1 ;
break;
case V_70 :
V_59 = V_35 -> V_12 . V_64 . V_28 . V_71 ;
V_26 -> V_12 . V_64 . V_28 . V_67 =
sprintf ( V_26 -> V_12 . V_64 . V_28 . V_68 ,
L_7 , V_59 ) + 1 ;
break;
case V_72 :
V_60 = V_35 -> V_12 . V_64 . V_28 . V_73 ;
V_26 -> V_12 . V_64 . V_28 . V_67 =
sprintf ( V_26 -> V_12 . V_64 . V_28 . V_68 ,
L_8 , V_60 ) + 1 ;
break;
}
case V_74 :
V_26 -> V_12 . V_64 . V_28 . V_75 =
F_20 (
( V_45 * ) V_35 -> V_12 . V_64 . V_28 . V_32 ,
V_35 -> V_12 . V_64 . V_28 . V_75 ,
V_55 ,
V_26 -> V_12 . V_64 . V_28 . V_32 ,
V_76 - 1 ) + 1 ;
break;
case V_77 :
V_26 -> V_12 . V_78 . V_75 =
F_20 (
( V_45 * ) V_35 -> V_12 . V_78 . V_32 ,
V_35 -> V_12 . V_78 . V_75 ,
V_55 ,
V_26 -> V_12 . V_78 . V_32 ,
V_76 - 1 ) + 1 ;
break;
case V_79 :
V_26 -> V_12 . V_31 . V_80 =
V_35 -> V_12 . V_31 . V_80 ;
break;
}
V_2 . V_3 = V_29 ;
V_61 = F_9 ( V_16 , V_26 , sizeof( * V_26 ) , NULL ) ;
if ( V_61 ) {
F_4 ( L_9 , V_61 ) ;
if ( F_5 ( & V_34 ) ) {
F_12 ( V_26 , V_19 ) ;
V_2 . V_3 = V_4 ;
}
}
F_10 ( V_26 ) ;
return;
}
static void
F_12 ( struct V_8 * V_81 , int error )
{
struct V_8 * V_9 ;
struct V_82 * V_83 ;
char * V_84 ;
char * V_68 ;
struct V_85 * V_86 ;
int V_87 = 0 ;
int V_88 = 0 ;
T_3 V_89 ;
struct V_90 * V_1 ;
T_4 V_91 ;
int V_92 ;
V_89 = V_2 . V_93 ;
V_1 = V_2 . V_6 ;
V_91 = V_2 . V_94 ;
V_86 = (struct V_85 * )
& V_95 [ sizeof( struct V_96 ) ] ;
if ( V_1 -> V_97 == NULL )
return;
V_86 -> V_98 = error ;
if ( error ) {
goto V_99;
}
V_9 = (struct V_8 * )
& V_95 [ sizeof( struct V_96 ) +
sizeof( struct V_85 ) ] ;
switch ( V_2 . V_9 -> V_13 . V_14 ) {
case V_41 :
V_92 = F_17 ( V_81 ,
(struct V_39 * ) V_9 ,
V_41 ) ;
if ( V_92 < 0 )
V_86 -> V_98 = V_19 ;
goto V_99;
case V_54 :
goto V_99;
case V_74 :
V_83 = & V_9 -> V_12 . V_100 . V_28 ;
goto V_101;
case V_63 :
case V_77 :
goto V_99;
default:
break;
}
V_83 = & V_9 -> V_12 . V_31 . V_28 ;
V_84 = V_81 -> V_12 . V_31 . V_28 . V_32 ;
V_87 = F_18 ( V_84 , strlen ( V_84 ) , V_44 ,
( V_45 * ) V_83 -> V_32 ,
( V_76 / 2 ) - 2 ) ;
V_83 -> V_75 = 2 * ( V_87 + 1 ) ;
V_101:
V_68 = V_81 -> V_12 . V_31 . V_28 . V_68 ;
V_88 = F_18 ( V_68 , strlen ( V_68 ) , V_44 ,
( V_45 * ) V_83 -> V_68 ,
( V_69 / 2 ) - 2 ) ;
V_83 -> V_67 = 2 * ( V_88 + 1 ) ;
if ( ( V_87 < 0 ) || ( V_88 < 0 ) )
V_86 -> V_98 = V_19 ;
V_83 -> V_65 = V_66 ;
V_99:
V_86 -> V_102 = V_103 | V_104 ;
F_22 ( V_1 , V_95 , V_89 , V_91 ,
V_105 , 0 ) ;
}
void F_2 ( void * V_106 )
{
struct V_90 * V_1 = V_106 ;
T_3 V_107 ;
T_4 V_108 ;
struct V_8 * V_9 ;
struct V_85 * V_86 ;
int V_109 ;
static enum { V_110 ,
V_111 ,
V_112 } V_113 = V_110 ;
if ( V_113 == V_110 &&
V_2 . V_3 < V_4 ) {
V_113 = V_111 ;
F_23 ( & V_5 ,
V_114 * V_115 ) ;
return;
}
if ( V_2 . V_3 > V_4 )
return;
F_24 ( V_1 , V_95 , V_116 * 4 , & V_107 ,
& V_108 ) ;
if ( V_107 > 0 ) {
V_86 = (struct V_85 * ) & V_95 [
sizeof( struct V_96 ) ] ;
if ( V_86 -> V_117 == V_118 ) {
if ( F_25 ( V_86 ,
V_95 , V_119 , V_120 ,
V_121 , V_122 ,
NULL , & V_109 ) ) {
F_15 ( L_10 ,
V_109 >> 16 ,
V_109 & 0xFFFF ) ;
}
} else {
V_9 = (struct V_8 * ) & V_95 [
sizeof( struct V_96 ) +
sizeof( struct V_85 ) ] ;
V_2 . V_93 = V_107 ;
V_2 . V_94 = V_108 ;
V_2 . V_9 = V_9 ;
if ( V_2 . V_3 < V_4 ) {
F_12 ( NULL , V_19 ) ;
return;
}
V_2 . V_3 = V_62 ;
F_26 ( & V_123 ) ;
F_23 ( & V_34 ,
V_124 * V_115 ) ;
return;
}
V_86 -> V_102 = V_103
| V_104 ;
F_22 ( V_1 , V_95 ,
V_107 , V_108 ,
V_105 , 0 ) ;
V_113 = V_112 ;
}
}
static void F_27 ( void )
{
if ( F_5 ( & V_34 ) )
F_12 ( NULL , V_19 ) ;
V_2 . V_3 = V_125 ;
}
int
F_28 ( struct V_126 * V_127 )
{
V_95 = V_127 -> V_95 ;
V_2 . V_6 = V_127 -> V_1 ;
V_2 . V_3 = V_125 ;
V_16 = F_29 ( V_128 , V_129 , V_130 ,
F_16 , F_27 ) ;
if ( ! V_16 )
return - V_131 ;
return 0 ;
}
void F_30 ( void )
{
V_2 . V_3 = V_132 ;
F_5 ( & V_5 ) ;
F_5 ( & V_34 ) ;
F_31 ( & V_123 ) ;
F_32 ( V_16 ) ;
}
