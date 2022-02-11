static void F_1 ( void * V_1 )
{
V_2 . V_3 = V_4 ;
F_2 ( & ( (struct V_5 * ) V_1 ) -> V_6 ) ;
}
static void F_3 ( void )
{
F_4 ( L_1 ) ;
F_5 ( & V_7 ) ;
F_6 ( V_2 . V_8 , F_1 ) ;
}
static void
F_7 ( int V_9 )
{
struct V_10 * V_11 ;
char * V_12 ;
V_11 = F_8 ( sizeof( * V_11 ) , V_13 ) ;
if ( V_11 ) {
V_12 = V_11 -> V_14 . F_7 . V_12 ;
V_11 -> V_15 . V_16 = V_9 ;
strcpy ( V_12 , V_17 ) ;
F_9 ( V_18 , V_11 , sizeof( * V_11 ) ,
F_3 ) ;
F_10 ( V_11 ) ;
}
}
static void F_11 ( struct V_19 * V_20 )
{
F_12 ( NULL , V_21 ) ;
F_6 ( V_2 . V_8 , F_1 ) ;
}
static void F_13 ( struct V_19 * V_20 )
{
F_2 ( & V_2 . V_8 -> V_6 ) ;
}
static int F_14 ( struct V_10 * V_22 )
{
switch ( V_22 -> V_15 . V_16 ) {
case V_23 :
V_24 = V_23 ;
F_15 ( L_2 ) ;
F_15 ( L_3 ) ;
break;
case V_25 :
V_24 = V_25 ;
break;
default:
F_15 ( L_4 ) ;
F_15 ( L_5 ,
V_25 , V_22 -> V_15 . V_16 ) ;
return - V_26 ;
}
F_4 ( L_6 ,
V_22 -> V_15 . V_16 ) ;
F_7 ( V_24 ) ;
return 0 ;
}
static int F_16 ( void * V_22 , int V_27 )
{
struct V_10 * V_28 = (struct V_10 * ) V_22 ;
struct V_29 * V_30 ;
int error = 0 ;
if ( V_27 < sizeof( * V_28 ) )
return - V_26 ;
if ( V_2 . V_3 < V_4 ) {
return F_14 ( V_28 ) ;
}
if ( V_2 . V_3 < V_31 )
return - V_26 ;
V_2 . V_3 = V_32 ;
V_30 = & V_28 -> V_14 . V_33 ;
switch ( V_24 ) {
case V_23 :
if ( V_30 -> V_30 . V_34 [ 0 ] == 0 )
error = V_35 ;
break;
case V_25 :
error = V_28 -> error ;
break;
}
if ( F_5 ( & V_36 ) ) {
F_12 ( V_28 , error ) ;
F_6 ( V_2 . V_8 , F_1 ) ;
}
return 0 ;
}
static int F_17 ( void * V_37 , void * V_38 , int V_39 )
{
struct V_10 * V_40 = V_37 ;
struct V_41 * V_42 = V_38 ;
int V_27 ;
switch ( V_39 ) {
case V_43 :
V_27 = F_18 ( ( char * ) V_40 -> V_14 . V_44 . V_45 ,
strlen ( ( char * ) V_40 -> V_14 . V_44 . V_45 ) ,
V_46 ,
( V_47 * ) V_42 -> V_44 . V_45 ,
V_48 ) ;
if ( V_27 < 0 )
return V_27 ;
V_27 = F_18 ( ( char * ) V_40 -> V_14 . V_44 . V_49 ,
strlen ( ( char * ) V_40 -> V_14 . V_44 . V_49 ) ,
V_46 ,
( V_47 * ) V_42 -> V_44 . V_49 ,
V_48 ) ;
if ( V_27 < 0 )
return V_27 ;
V_27 = F_18 ( ( char * ) V_40 -> V_14 . V_44 . V_50 ,
strlen ( ( char * ) V_40 -> V_14 . V_44 . V_50 ) ,
V_46 ,
( V_47 * ) V_42 -> V_44 . V_50 ,
V_51 ) ;
if ( V_27 < 0 )
return V_27 ;
V_27 = F_18 ( ( char * ) V_40 -> V_14 . V_44 . V_52 ,
strlen ( ( char * ) V_40 -> V_14 . V_44 . V_52 ) ,
V_46 ,
( V_47 * ) V_42 -> V_44 . V_52 ,
V_48 ) ;
if ( V_27 < 0 )
return V_27 ;
V_27 = F_18 ( ( char * ) V_40 -> V_14 . V_44 . V_53 ,
strlen ( ( char * ) V_40 -> V_14 . V_44 . V_53 ) ,
V_46 ,
( V_47 * ) V_42 -> V_44 . V_53 ,
V_48 ) ;
if ( V_27 < 0 )
return V_27 ;
V_42 -> V_44 . V_54 =
V_40 -> V_14 . V_44 . V_54 ;
V_42 -> V_44 . V_55 =
V_40 -> V_14 . V_44 . V_55 ;
}
return 0 ;
}
static void F_19 ( void * V_37 , void * V_38 , int V_39 )
{
struct V_41 * V_40 = V_37 ;
struct V_10 * V_42 = V_38 ;
switch ( V_39 ) {
case V_56 :
F_20 ( ( V_47 * ) V_40 -> V_44 . V_45 ,
V_48 ,
V_57 ,
( V_58 * ) V_42 -> V_14 . V_44 . V_45 ,
V_48 ) ;
F_20 ( ( V_47 * ) V_40 -> V_44 . V_49 ,
V_48 ,
V_57 ,
( V_58 * ) V_42 -> V_14 . V_44 . V_49 ,
V_48 ) ;
F_20 ( ( V_47 * ) V_40 -> V_44 . V_50 ,
V_51 ,
V_57 ,
( V_58 * ) V_42 -> V_14 . V_44 . V_50 ,
V_51 ) ;
F_20 ( ( V_47 * ) V_40 -> V_44 . V_52 ,
V_48 ,
V_57 ,
( V_58 * ) V_42 -> V_14 . V_44 . V_52 ,
V_48 ) ;
V_42 -> V_14 . V_44 . V_54 = V_40 -> V_44 . V_54 ;
default:
F_20 ( ( V_47 * ) V_40 -> V_44 . V_53 ,
V_59 ,
V_57 ,
( V_58 * ) V_42 -> V_14 . V_44 . V_53 ,
V_59 ) ;
V_42 -> V_14 . V_44 . V_55 = V_40 -> V_44 . V_55 ;
}
}
static void
F_21 ( struct V_19 * V_20 )
{
struct V_10 * V_28 ;
struct V_10 * V_37 ;
V_58 V_16 = V_2 . V_11 -> V_15 . V_16 ;
V_58 V_60 = V_2 . V_11 -> V_15 . V_60 ;
T_1 V_61 ;
T_2 V_62 ;
int V_63 ;
if ( V_2 . V_3 != V_64 )
return;
V_28 = F_8 ( sizeof( * V_28 ) , V_13 ) ;
if ( ! V_28 )
return;
V_28 -> V_15 . V_16 = V_16 ;
V_28 -> V_15 . V_60 = V_60 ;
V_37 = V_2 . V_11 ;
switch ( V_28 -> V_15 . V_16 ) {
case V_56 :
F_19 ( V_37 , V_28 , V_56 ) ;
break;
case V_43 :
F_19 ( V_37 , V_28 , V_43 ) ;
break;
case V_65 :
switch ( V_37 -> V_14 . V_66 . V_30 . V_67 ) {
case V_68 :
V_28 -> V_14 . V_66 . V_30 . V_69 =
F_20 (
( V_47 * ) V_37 -> V_14 . V_66 . V_30 . V_70 ,
V_37 -> V_14 . V_66 . V_30 . V_69 ,
V_57 ,
V_28 -> V_14 . V_66 . V_30 . V_70 ,
V_71 - 1 ) + 1 ;
break;
case V_72 :
V_61 = V_37 -> V_14 . V_66 . V_30 . V_73 ;
V_28 -> V_14 . V_66 . V_30 . V_69 =
sprintf ( V_28 -> V_14 . V_66 . V_30 . V_70 ,
L_7 , V_61 ) + 1 ;
break;
case V_74 :
V_62 = V_37 -> V_14 . V_66 . V_30 . V_75 ;
V_28 -> V_14 . V_66 . V_30 . V_69 =
sprintf ( V_28 -> V_14 . V_66 . V_30 . V_70 ,
L_8 , V_62 ) + 1 ;
break;
}
case V_76 :
V_28 -> V_14 . V_66 . V_30 . V_77 =
F_20 (
( V_47 * ) V_37 -> V_14 . V_66 . V_30 . V_34 ,
V_37 -> V_14 . V_66 . V_30 . V_77 ,
V_57 ,
V_28 -> V_14 . V_66 . V_30 . V_34 ,
V_78 - 1 ) + 1 ;
break;
case V_79 :
V_28 -> V_14 . V_80 . V_77 =
F_20 (
( V_47 * ) V_37 -> V_14 . V_80 . V_34 ,
V_37 -> V_14 . V_80 . V_77 ,
V_57 ,
V_28 -> V_14 . V_80 . V_34 ,
V_78 - 1 ) + 1 ;
break;
case V_81 :
V_28 -> V_14 . V_33 . V_82 =
V_37 -> V_14 . V_33 . V_82 ;
break;
}
V_2 . V_3 = V_31 ;
V_63 = F_9 ( V_18 , V_28 , sizeof( * V_28 ) , NULL ) ;
if ( V_63 ) {
F_4 ( L_9 , V_63 ) ;
if ( F_5 ( & V_36 ) ) {
F_12 ( V_28 , V_21 ) ;
V_2 . V_3 = V_4 ;
}
}
F_10 ( V_28 ) ;
}
static void
F_12 ( struct V_10 * V_83 , int error )
{
struct V_10 * V_11 ;
struct V_84 * V_85 ;
char * V_86 ;
char * V_70 ;
struct V_87 * V_88 ;
int V_89 = 0 ;
int V_90 = 0 ;
T_3 V_91 ;
struct V_5 * V_1 ;
T_4 V_92 ;
int V_93 ;
V_91 = V_2 . V_94 ;
V_1 = V_2 . V_8 ;
V_92 = V_2 . V_95 ;
V_88 = (struct V_87 * )
& V_96 [ sizeof( struct V_97 ) ] ;
if ( V_1 -> V_98 == NULL )
return;
V_88 -> V_99 = error ;
if ( error ) {
goto V_100;
}
V_11 = (struct V_10 * )
& V_96 [ sizeof( struct V_97 ) +
sizeof( struct V_87 ) ] ;
switch ( V_2 . V_11 -> V_15 . V_16 ) {
case V_43 :
V_93 = F_17 ( V_83 ,
(struct V_41 * ) V_11 ,
V_43 ) ;
if ( V_93 < 0 )
V_88 -> V_99 = V_21 ;
goto V_100;
case V_56 :
goto V_100;
case V_76 :
V_85 = & V_11 -> V_14 . V_101 . V_30 ;
goto V_102;
case V_65 :
case V_79 :
goto V_100;
default:
break;
}
V_85 = & V_11 -> V_14 . V_33 . V_30 ;
V_86 = V_83 -> V_14 . V_33 . V_30 . V_34 ;
V_89 = F_18 ( V_86 , strlen ( V_86 ) , V_46 ,
( V_47 * ) V_85 -> V_34 ,
( V_78 / 2 ) - 2 ) ;
V_85 -> V_77 = 2 * ( V_89 + 1 ) ;
V_102:
V_70 = V_83 -> V_14 . V_33 . V_30 . V_70 ;
V_90 = F_18 ( V_70 , strlen ( V_70 ) , V_46 ,
( V_47 * ) V_85 -> V_70 ,
( V_71 / 2 ) - 2 ) ;
V_85 -> V_69 = 2 * ( V_90 + 1 ) ;
if ( ( V_89 < 0 ) || ( V_90 < 0 ) )
V_88 -> V_99 = V_21 ;
V_85 -> V_67 = V_68 ;
V_100:
V_88 -> V_103 = V_104 | V_105 ;
F_22 ( V_1 , V_96 , V_91 , V_92 ,
V_106 , 0 ) ;
}
void F_23 ( void * V_107 )
{
struct V_5 * V_1 = V_107 ;
T_3 V_108 ;
T_4 V_109 ;
struct V_10 * V_11 ;
struct V_87 * V_88 ;
int V_110 ;
static enum { V_111 ,
V_112 ,
V_113 } V_114 = V_111 ;
if ( V_2 . V_3 < V_4 ) {
if ( V_114 == V_111 ) {
V_114 = V_112 ;
F_24 ( & V_7 ,
V_115 * V_116 ) ;
}
return;
}
if ( V_2 . V_3 > V_4 )
return;
F_25 ( V_1 , V_96 , V_117 * 4 , & V_108 ,
& V_109 ) ;
if ( V_108 > 0 ) {
V_88 = (struct V_87 * ) & V_96 [
sizeof( struct V_97 ) ] ;
if ( V_88 -> V_118 == V_119 ) {
if ( F_26 ( V_88 ,
V_96 , V_120 , V_121 ,
V_122 , V_123 ,
NULL , & V_110 ) ) {
F_15 ( L_10 ,
V_110 >> 16 ,
V_110 & 0xFFFF ) ;
}
} else {
V_11 = (struct V_10 * ) & V_96 [
sizeof( struct V_97 ) +
sizeof( struct V_87 ) ] ;
V_2 . V_94 = V_108 ;
V_2 . V_95 = V_109 ;
V_2 . V_11 = V_11 ;
if ( V_2 . V_3 < V_4 ) {
F_12 ( NULL , V_21 ) ;
return;
}
V_2 . V_3 = V_64 ;
F_27 ( & V_124 ) ;
F_24 ( & V_36 ,
V_125 * V_116 ) ;
return;
}
V_88 -> V_103 = V_104
| V_105 ;
F_22 ( V_1 , V_96 ,
V_108 , V_109 ,
V_106 , 0 ) ;
V_114 = V_113 ;
F_6 ( V_2 . V_8 , F_1 ) ;
}
}
static void F_28 ( void )
{
if ( F_5 ( & V_36 ) )
F_12 ( NULL , V_21 ) ;
V_2 . V_3 = V_126 ;
}
int
F_29 ( struct V_127 * V_128 )
{
V_96 = V_128 -> V_96 ;
V_2 . V_8 = V_128 -> V_1 ;
V_2 . V_3 = V_126 ;
V_18 = F_30 ( V_129 , V_130 , V_131 ,
F_16 , F_28 ) ;
if ( ! V_18 )
return - V_132 ;
return 0 ;
}
void F_31 ( void )
{
V_2 . V_3 = V_133 ;
F_5 ( & V_7 ) ;
F_5 ( & V_36 ) ;
F_32 ( & V_124 ) ;
F_33 ( V_18 ) ;
}
