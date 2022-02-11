static void F_1 ( void * V_1 )
{
V_2 . V_3 = V_4 ;
F_2 ( V_1 ) ;
}
static void
F_3 ( int V_5 )
{
struct V_6 * V_7 ;
char * V_8 ;
V_7 = F_4 ( sizeof( * V_7 ) , V_9 ) ;
if ( V_7 ) {
V_8 = V_7 -> V_10 . F_3 . V_8 ;
V_7 -> V_11 . V_12 = V_5 ;
strcpy ( V_8 , V_13 ) ;
F_5 ( V_14 , V_7 , sizeof( * V_7 ) ) ;
F_6 ( V_7 ) ;
}
}
static void F_7 ( struct V_15 * V_16 )
{
F_8 ( NULL , V_17 ) ;
F_9 ( V_2 . V_18 , F_1 ) ;
}
static int F_10 ( struct V_6 * V_19 )
{
switch ( V_19 -> V_11 . V_12 ) {
case V_20 :
V_21 = V_20 ;
F_11 ( L_1 ) ;
F_11 ( L_2 ) ;
break;
case V_22 :
V_21 = V_22 ;
break;
default:
F_11 ( L_3 ) ;
F_11 ( L_4 ,
V_22 , V_19 -> V_11 . V_12 ) ;
return - V_23 ;
}
F_12 ( L_5 ,
V_20 ) ;
F_3 ( V_21 ) ;
F_9 ( V_2 . V_18 , F_1 ) ;
return 0 ;
}
static int F_13 ( void * V_19 , int V_24 )
{
struct V_6 * V_25 = (struct V_6 * ) V_19 ;
struct V_26 * V_27 ;
int error = 0 ;
if ( V_24 < sizeof( * V_25 ) )
return - V_23 ;
if ( V_2 . V_3 < V_4 ) {
return F_10 ( V_25 ) ;
}
if ( V_2 . V_3 < V_28 )
return - V_23 ;
V_2 . V_3 = V_29 ;
V_27 = & V_25 -> V_10 . V_30 ;
switch ( V_21 ) {
case V_20 :
if ( V_27 -> V_27 . V_31 [ 0 ] == 0 )
error = V_32 ;
break;
case V_22 :
error = V_25 -> error ;
break;
}
if ( F_14 ( & V_33 ) ) {
F_8 ( V_25 , error ) ;
F_9 ( V_2 . V_18 , F_1 ) ;
}
return 0 ;
}
static int F_15 ( void * V_34 , void * V_35 , int V_36 )
{
struct V_6 * V_37 = V_34 ;
struct V_38 * V_39 = V_35 ;
int V_24 ;
switch ( V_36 ) {
case V_40 :
V_24 = F_16 ( ( char * ) V_37 -> V_10 . V_41 . V_42 ,
strlen ( ( char * ) V_37 -> V_10 . V_41 . V_42 ) ,
V_43 ,
( V_44 * ) V_39 -> V_41 . V_42 ,
V_45 ) ;
if ( V_24 < 0 )
return V_24 ;
V_24 = F_16 ( ( char * ) V_37 -> V_10 . V_41 . V_46 ,
strlen ( ( char * ) V_37 -> V_10 . V_41 . V_46 ) ,
V_43 ,
( V_44 * ) V_39 -> V_41 . V_46 ,
V_45 ) ;
if ( V_24 < 0 )
return V_24 ;
V_24 = F_16 ( ( char * ) V_37 -> V_10 . V_41 . V_47 ,
strlen ( ( char * ) V_37 -> V_10 . V_41 . V_47 ) ,
V_43 ,
( V_44 * ) V_39 -> V_41 . V_47 ,
V_48 ) ;
if ( V_24 < 0 )
return V_24 ;
V_24 = F_16 ( ( char * ) V_37 -> V_10 . V_41 . V_49 ,
strlen ( ( char * ) V_37 -> V_10 . V_41 . V_49 ) ,
V_43 ,
( V_44 * ) V_39 -> V_41 . V_49 ,
V_45 ) ;
if ( V_24 < 0 )
return V_24 ;
V_24 = F_16 ( ( char * ) V_37 -> V_10 . V_41 . V_50 ,
strlen ( ( char * ) V_37 -> V_10 . V_41 . V_50 ) ,
V_43 ,
( V_44 * ) V_39 -> V_41 . V_50 ,
V_45 ) ;
if ( V_24 < 0 )
return V_24 ;
V_39 -> V_41 . V_51 =
V_37 -> V_10 . V_41 . V_51 ;
V_39 -> V_41 . V_52 =
V_37 -> V_10 . V_41 . V_52 ;
}
return 0 ;
}
static void F_17 ( void * V_34 , void * V_35 , int V_36 )
{
struct V_38 * V_37 = V_34 ;
struct V_6 * V_39 = V_35 ;
switch ( V_36 ) {
case V_53 :
F_18 ( ( V_44 * ) V_37 -> V_41 . V_42 ,
V_45 ,
V_54 ,
( V_55 * ) V_39 -> V_10 . V_41 . V_42 ,
V_45 ) ;
F_18 ( ( V_44 * ) V_37 -> V_41 . V_46 ,
V_45 ,
V_54 ,
( V_55 * ) V_39 -> V_10 . V_41 . V_46 ,
V_45 ) ;
F_18 ( ( V_44 * ) V_37 -> V_41 . V_47 ,
V_48 ,
V_54 ,
( V_55 * ) V_39 -> V_10 . V_41 . V_47 ,
V_48 ) ;
F_18 ( ( V_44 * ) V_37 -> V_41 . V_49 ,
V_45 ,
V_54 ,
( V_55 * ) V_39 -> V_10 . V_41 . V_49 ,
V_45 ) ;
V_39 -> V_10 . V_41 . V_51 = V_37 -> V_41 . V_51 ;
default:
F_18 ( ( V_44 * ) V_37 -> V_41 . V_50 ,
V_56 ,
V_54 ,
( V_55 * ) V_39 -> V_10 . V_41 . V_50 ,
V_56 ) ;
V_39 -> V_10 . V_41 . V_52 = V_37 -> V_41 . V_52 ;
}
}
static void
F_19 ( struct V_15 * V_16 )
{
struct V_6 * V_25 ;
struct V_6 * V_34 ;
V_55 V_12 = V_2 . V_7 -> V_11 . V_12 ;
V_55 V_57 = V_2 . V_7 -> V_11 . V_57 ;
T_1 V_58 ;
T_2 V_59 ;
int V_60 ;
if ( V_2 . V_3 != V_61 )
return;
V_25 = F_4 ( sizeof( * V_25 ) , V_9 ) ;
if ( ! V_25 )
return;
V_25 -> V_11 . V_12 = V_12 ;
V_25 -> V_11 . V_57 = V_57 ;
V_34 = V_2 . V_7 ;
switch ( V_25 -> V_11 . V_12 ) {
case V_53 :
F_17 ( V_34 , V_25 , V_53 ) ;
break;
case V_40 :
F_17 ( V_34 , V_25 , V_40 ) ;
break;
case V_62 :
switch ( V_34 -> V_10 . V_63 . V_27 . V_64 ) {
case V_65 :
V_25 -> V_10 . V_63 . V_27 . V_66 =
F_18 (
( V_44 * ) V_34 -> V_10 . V_63 . V_27 . V_67 ,
V_34 -> V_10 . V_63 . V_27 . V_66 ,
V_54 ,
V_25 -> V_10 . V_63 . V_27 . V_67 ,
V_68 - 1 ) + 1 ;
break;
case V_69 :
V_58 = V_34 -> V_10 . V_63 . V_27 . V_70 ;
V_25 -> V_10 . V_63 . V_27 . V_66 =
sprintf ( V_25 -> V_10 . V_63 . V_27 . V_67 ,
L_6 , V_58 ) + 1 ;
break;
case V_71 :
V_59 = V_34 -> V_10 . V_63 . V_27 . V_72 ;
V_25 -> V_10 . V_63 . V_27 . V_66 =
sprintf ( V_25 -> V_10 . V_63 . V_27 . V_67 ,
L_7 , V_59 ) + 1 ;
break;
}
case V_73 :
V_25 -> V_10 . V_63 . V_27 . V_74 =
F_18 (
( V_44 * ) V_34 -> V_10 . V_63 . V_27 . V_31 ,
V_34 -> V_10 . V_63 . V_27 . V_74 ,
V_54 ,
V_25 -> V_10 . V_63 . V_27 . V_31 ,
V_75 - 1 ) + 1 ;
break;
case V_76 :
V_25 -> V_10 . V_77 . V_74 =
F_18 (
( V_44 * ) V_34 -> V_10 . V_77 . V_31 ,
V_34 -> V_10 . V_77 . V_74 ,
V_54 ,
V_25 -> V_10 . V_77 . V_31 ,
V_75 - 1 ) + 1 ;
break;
case V_78 :
V_25 -> V_10 . V_30 . V_79 =
V_34 -> V_10 . V_30 . V_79 ;
break;
}
V_2 . V_3 = V_28 ;
V_60 = F_5 ( V_14 , V_25 , sizeof( * V_25 ) ) ;
if ( V_60 ) {
F_12 ( L_8 , V_60 ) ;
if ( F_14 ( & V_33 ) ) {
F_8 ( V_25 , V_17 ) ;
V_2 . V_3 = V_4 ;
}
}
F_6 ( V_25 ) ;
return;
}
static void
F_8 ( struct V_6 * V_80 , int error )
{
struct V_6 * V_7 ;
struct V_81 * V_82 ;
char * V_83 ;
char * V_67 ;
struct V_84 * V_85 ;
int V_86 = 0 ;
int V_87 = 0 ;
T_3 V_88 ;
struct V_89 * V_1 ;
T_4 V_90 ;
int V_91 ;
V_88 = V_2 . V_92 ;
V_1 = V_2 . V_18 ;
V_90 = V_2 . V_93 ;
V_85 = (struct V_84 * )
& V_94 [ sizeof( struct V_95 ) ] ;
if ( V_1 -> V_96 == NULL )
return;
V_85 -> V_97 = error ;
if ( error ) {
goto V_98;
}
V_7 = (struct V_6 * )
& V_94 [ sizeof( struct V_95 ) +
sizeof( struct V_84 ) ] ;
switch ( V_2 . V_7 -> V_11 . V_12 ) {
case V_40 :
V_91 = F_15 ( V_80 ,
(struct V_38 * ) V_7 ,
V_40 ) ;
if ( V_91 < 0 )
V_85 -> V_97 = V_17 ;
goto V_98;
case V_53 :
goto V_98;
case V_73 :
V_82 = & V_7 -> V_10 . V_99 . V_27 ;
goto V_100;
case V_62 :
case V_76 :
goto V_98;
default:
break;
}
V_82 = & V_7 -> V_10 . V_30 . V_27 ;
V_83 = V_80 -> V_10 . V_30 . V_27 . V_31 ;
V_86 = F_16 ( V_83 , strlen ( V_83 ) , V_43 ,
( V_44 * ) V_82 -> V_31 ,
( V_75 / 2 ) - 2 ) ;
V_82 -> V_74 = 2 * ( V_86 + 1 ) ;
V_100:
V_67 = V_80 -> V_10 . V_30 . V_27 . V_67 ;
V_87 = F_16 ( V_67 , strlen ( V_67 ) , V_43 ,
( V_44 * ) V_82 -> V_67 ,
( V_68 / 2 ) - 2 ) ;
V_82 -> V_66 = 2 * ( V_87 + 1 ) ;
if ( ( V_86 < 0 ) || ( V_87 < 0 ) )
V_85 -> V_97 = V_17 ;
V_82 -> V_64 = V_65 ;
V_98:
V_85 -> V_101 = V_102 | V_103 ;
F_20 ( V_1 , V_94 , V_88 , V_90 ,
V_104 , 0 ) ;
}
void F_2 ( void * V_105 )
{
struct V_89 * V_1 = V_105 ;
T_3 V_106 ;
T_4 V_107 ;
struct V_6 * V_7 ;
struct V_84 * V_85 ;
struct V_108 * V_109 = NULL ;
int V_110 ;
int V_111 ;
if ( V_2 . V_3 > V_4 )
return;
F_21 ( V_1 , V_94 , V_112 * 4 , & V_106 ,
& V_107 ) ;
if ( V_106 > 0 ) {
V_85 = (struct V_84 * ) & V_94 [
sizeof( struct V_95 ) ] ;
if ( V_85 -> V_113 == V_114 ) {
switch ( V_115 ) {
case ( V_116 ) :
V_110 = V_117 ;
V_111 = V_118 ;
break;
case ( V_119 ) :
V_110 = V_120 ;
V_111 = V_121 ;
break;
default:
V_110 = V_120 ;
V_111 = V_122 ;
}
F_22 ( V_85 , V_109 ,
V_94 , V_110 ,
V_111 ) ;
} else {
V_7 = (struct V_6 * ) & V_94 [
sizeof( struct V_95 ) +
sizeof( struct V_84 ) ] ;
V_2 . V_92 = V_106 ;
V_2 . V_93 = V_107 ;
V_2 . V_7 = V_7 ;
if ( V_2 . V_3 < V_4 ) {
F_8 ( NULL , V_17 ) ;
return;
}
V_2 . V_3 = V_61 ;
F_23 ( & V_123 ) ;
F_24 ( & V_33 ,
V_124 * V_125 ) ;
return;
}
V_85 -> V_101 = V_102
| V_103 ;
F_20 ( V_1 , V_94 ,
V_106 , V_107 ,
V_104 , 0 ) ;
}
}
static void F_25 ( void )
{
if ( F_14 ( & V_33 ) )
F_8 ( NULL , V_17 ) ;
V_2 . V_3 = V_126 ;
}
int
F_26 ( struct V_127 * V_128 )
{
V_94 = V_128 -> V_94 ;
V_2 . V_18 = V_128 -> V_1 ;
V_2 . V_3 = V_126 ;
V_14 = F_27 ( V_129 , V_130 , V_131 ,
F_13 , F_25 ) ;
if ( ! V_14 )
return - V_132 ;
return 0 ;
}
void F_28 ( void )
{
V_2 . V_3 = V_133 ;
F_14 ( & V_33 ) ;
F_29 ( & V_123 ) ;
F_30 ( V_14 ) ;
}
