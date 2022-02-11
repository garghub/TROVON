static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_7 * V_8 =
& V_9 [ V_10 ] ;
T_1 V_11 = 0 ;
F_2 ( V_2 -> V_6 , 0 , 0 ) ;
F_3 ( V_12 ,
V_13 | V_14 ) ;
F_4 ( V_2 -> V_6 , V_8 , V_4 -> V_15 ,
V_4 -> V_16 . V_17 ) ;
F_5 ( V_18 , V_4 -> V_15 ) ;
F_5 ( V_19 , V_20 ) ;
F_6 ( & V_2 -> V_21 , 0 ) ;
V_11 = F_7 ( V_22 ) ;
F_5 ( V_22 , V_11 | V_23 | V_24 |
V_25 ) ;
F_5 ( V_26 , V_27 | V_28 |
V_29 | V_30 ) ;
F_5 ( V_31 , ~ 0 ) ;
F_8 ( V_32 , V_2 -> V_6 -> V_33 | V_34 ) ;
V_11 = F_7 ( V_12 ) ;
F_8 ( V_12 , V_11 |
( V_13 | V_14 ) ) ;
F_9 ( 100 ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
F_3 ( V_12 ,
V_13 | V_14 ) ;
F_3 ( V_32 , V_34 ) ;
F_3 ( V_26 , V_35 | V_36 |
V_37 | V_38 ) ;
return 0 ;
}
static void F_11 ( struct V_1 * V_2 , T_1 V_39 ,
T_1 V_40 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
if ( 0 == ( V_39 & V_40 ) )
return;
F_5 ( V_31 , V_39 ) ;
if ( V_41 > 1 || ( V_39 & V_40 & ~ 0xff ) )
F_12 ( V_6 -> V_42 , L_1 , V_43 ,
F_13 ( V_43 ) , V_39 , V_40 ) ;
if ( V_39 & V_35 ) {
F_14 ( L_2 , V_6 -> V_42 ) ;
F_3 ( V_12 ,
V_13 | V_14 ) ;
F_15 ( V_6 ,
& V_9 [ V_10 ] ) ;
}
if ( V_39 & V_36 ) {
F_14 ( L_3 , V_6 -> V_42 ) ;
F_5 ( V_19 , V_20 ) ;
return;
}
if ( V_39 & V_38 ) {
F_6 ( & V_2 -> V_21 , F_7 ( V_44 ) ) ;
F_16 ( V_2 -> V_45 ) ;
}
}
static T_2 F_17 ( int V_46 , void * V_47 )
{
struct V_1 * V_2 = V_47 ;
struct V_5 * V_6 = V_2 -> V_6 ;
T_1 V_39 , V_48 ;
T_1 V_49 , V_50 ;
int V_51 , V_52 = 0 ;
V_49 = F_7 ( V_31 ) ;
V_50 = F_7 ( V_26 ) ;
V_39 = F_7 ( V_53 ) ;
for ( V_51 = 0 ; V_51 < 1 ; V_51 ++ ) {
V_39 = F_7 ( V_53 ) ;
if ( 0 == V_39 ) {
V_39 = F_7 ( V_53 ) ;
V_49 = F_7 ( V_31 ) ;
V_50 = F_7 ( V_26 ) ;
if ( V_39 ) {
V_52 = 1 ;
F_5 ( V_53 , V_39 ) ;
F_11 ( V_2 , V_49 ,
V_50 ) ;
break;
} else {
goto V_54;
}
}
V_52 = 1 ;
F_5 ( V_53 , V_39 ) ;
F_11 ( V_2 , V_49 , V_50 ) ;
}
V_48 = F_7 ( V_53 ) ;
if ( V_52 )
F_5 ( V_53 , V_48 ) ;
V_54:
return F_18 ( V_52 ) ;
}
static int F_19 ( struct V_1 * V_2 )
{
F_20 ( ! V_2 -> V_55 ) ;
F_21 ( 2 , L_4 ) ;
F_22 ( & V_2 -> V_56 -> V_6 , V_2 -> V_57 ) ;
F_23 ( V_2 -> V_57 ) ;
F_24 ( V_2 -> V_56 , & V_2 -> V_4 -> V_16 ) ;
F_25 ( V_2 -> V_4 ) ;
V_2 -> V_57 = NULL ;
V_2 -> V_55 = 0 ;
return 0 ;
}
static int F_26 ( struct V_58 * V_45 )
{
struct V_1 * V_2 = F_27 ( V_45 ) ;
struct V_59 * V_60 = V_45 -> V_60 ;
int V_61 ;
unsigned int V_15 = 0 ;
if ( ! V_2 ) {
F_28 ( L_5 ) ;
return - V_62 ;
}
V_61 = F_29 ( V_60 , 0 ,
V_63 ) ;
if ( V_61 < 0 )
goto V_64;
V_2 -> V_45 = V_45 ;
V_60 -> V_65 = V_66 ;
if ( V_9 [ V_10 ] . V_67 !=
V_68 ) {
V_15 = V_9 [ V_10 ] . V_67 / 3 ;
V_15 &= ~ 7 ;
if ( V_15 > V_69 )
V_15 = V_69 ;
V_60 -> V_65 . V_70 = V_15 ;
V_60 -> V_65 . V_71 = V_15 ;
}
return 0 ;
V_64:
F_21 ( 1 , L_6 ) ;
return V_61 ;
}
static int F_30 ( struct V_58 * V_45 )
{
return 0 ;
}
static int F_31 ( struct V_58 * V_45 ,
struct V_72 * V_73 )
{
struct V_1 * V_2 = F_27 ( V_45 ) ;
struct V_74 * V_17 ;
struct V_3 * V_4 ;
int V_75 ;
if ( V_45 -> V_60 -> V_76 ) {
F_19 ( V_2 ) ;
V_45 -> V_60 -> V_76 = NULL ;
}
V_2 -> V_77 = F_32 ( V_73 ) ;
V_2 -> V_78 = F_33 ( V_73 ) ;
V_2 -> V_55 = V_2 -> V_77 * F_33 ( V_73 ) ;
F_20 ( ! V_2 -> V_55 ) ;
F_20 ( V_2 -> V_78 & ( V_2 -> V_78 - 1 ) ) ;
V_4 = F_34 ( sizeof( * V_4 ) , V_79 ) ;
if ( NULL == V_4 )
return - V_80 ;
if ( V_2 -> V_77 > V_69 )
V_2 -> V_77 = V_69 ;
V_4 -> V_15 = V_2 -> V_77 ;
V_17 = & V_4 -> V_17 ;
F_35 ( V_17 ) ;
V_75 = F_36 ( V_17 , V_81 ,
( F_37 ( V_2 -> V_55 ) >> V_82 ) ) ;
if ( V_75 < 0 )
goto error;
V_75 = F_38 ( & V_2 -> V_56 -> V_6 , V_17 ) ;
if ( V_75 < 0 )
goto error;
V_75 = F_39 ( V_2 -> V_56 , & V_4 -> V_16 , V_17 -> V_83 ,
V_2 -> V_77 , V_2 -> V_78 , 1 ) ;
if ( V_75 < 0 ) {
F_40 ( L_7 ) ;
goto error;
}
V_4 -> V_16 . V_84 [ 0 ] = F_41 ( V_85 | V_86 | V_87 ) ;
V_4 -> V_16 . V_84 [ 1 ] = F_41 ( V_4 -> V_16 . V_17 ) ;
V_4 -> V_16 . V_84 [ 2 ] = F_41 ( 0 ) ;
V_2 -> V_4 = V_4 ;
V_2 -> V_57 = V_17 ;
V_45 -> V_60 -> V_76 = V_2 -> V_57 -> V_88 ;
V_45 -> V_60 -> V_89 = V_2 -> V_55 ;
V_45 -> V_60 -> V_90 = 0 ;
return 0 ;
error:
F_25 ( V_4 ) ;
return V_75 ;
}
static int F_42 ( struct V_58 * V_45 )
{
struct V_1 * V_2 = F_27 ( V_45 ) ;
if ( V_45 -> V_60 -> V_76 ) {
F_19 ( V_2 ) ;
V_45 -> V_60 -> V_76 = NULL ;
}
return 0 ;
}
static int F_43 ( struct V_58 * V_45 )
{
return 0 ;
}
static int F_44 ( struct V_58 * V_45 ,
int V_91 )
{
struct V_1 * V_2 = F_27 ( V_45 ) ;
int V_61 = 0 ;
F_45 ( & V_2 -> V_92 ) ;
switch ( V_91 ) {
case V_93 :
V_61 = F_1 ( V_2 ) ;
break;
case V_94 :
V_61 = F_10 ( V_2 ) ;
break;
default:
V_61 = - V_95 ;
break;
}
F_46 ( & V_2 -> V_92 ) ;
return V_61 ;
}
static T_3 F_47 ( struct V_58
* V_45 )
{
struct V_1 * V_2 = F_27 ( V_45 ) ;
struct V_59 * V_60 = V_45 -> V_60 ;
T_4 V_21 ;
V_21 = F_48 ( & V_2 -> V_21 ) ;
return V_60 -> V_77 * ( V_21 & ( V_60 -> V_96 - 1 ) ) ;
}
static struct V_97 * F_49 ( struct V_58 * V_45 ,
unsigned long V_98 )
{
void * V_99 = V_45 -> V_60 -> V_76 + V_98 ;
return F_50 ( V_99 ) ;
}
static int F_51 ( struct V_1 * V_2 , int V_100 ,
char * V_42 )
{
struct V_101 * V_102 ;
int V_61 ;
V_61 = F_52 ( V_2 -> V_103 , V_42 , V_100 , 0 , 1 , & V_102 ) ;
if ( V_61 < 0 ) {
F_40 ( L_8 , V_104 ) ;
return V_61 ;
}
V_102 -> V_105 = V_2 ;
V_102 -> V_106 = 0 ;
strcpy ( V_102 -> V_42 , V_42 ) ;
F_53 ( V_102 , V_107 , & V_108 ) ;
return 0 ;
}
static void F_54 ( struct V_109 * V_103 )
{
struct V_1 * V_2 = V_103 -> V_105 ;
F_55 ( V_2 -> V_103 ) ;
}
static int F_56 ( struct V_5 * V_6 )
{
struct V_109 * V_103 ;
struct V_1 * V_2 ;
int V_61 ;
if ( V_110 >= V_111 ) {
F_40 ( L_9 , V_104 ) ;
return - V_62 ;
}
if ( ! V_112 [ V_110 ] ) {
++ V_110 ;
F_40 ( L_10 , V_104 ) ;
return - V_113 ;
}
V_61 = F_57 ( V_114 [ V_110 ] , V_115 [ V_110 ] , V_116 ,
sizeof( struct V_1 ) , & V_103 ) ;
if ( V_61 < 0 ) {
F_40 ( L_11 ,
V_104 ) ;
return V_61 ;
}
strcpy ( V_103 -> V_117 , L_12 ) ;
V_103 -> V_118 = F_54 ;
V_2 = V_103 -> V_105 ;
F_58 ( & V_2 -> V_92 ) ;
V_2 -> V_6 = V_6 ;
V_2 -> V_103 = V_103 ;
V_2 -> V_56 = V_6 -> V_56 ;
V_2 -> V_119 = F_59 ( V_6 -> V_56 , 0 ) ;
V_2 -> V_46 = V_6 -> V_56 -> V_46 ;
V_61 = F_60 ( V_6 -> V_56 -> V_46 , F_17 ,
V_120 , V_2 -> V_6 -> V_42 , V_2 ) ;
if ( V_61 < 0 ) {
F_28 ( L_13 , V_2 -> V_6 -> V_42 ,
V_6 -> V_56 -> V_46 ) ;
goto error;
}
V_61 = F_51 ( V_2 , 0 , L_14 ) ;
if ( V_61 < 0 ) {
F_40 ( L_15 ,
V_104 ) ;
goto error;
}
F_61 ( V_103 , & V_2 -> V_56 -> V_6 ) ;
strcpy ( V_103 -> V_121 , L_12 ) ;
sprintf ( V_103 -> V_122 , L_16 , V_2 -> V_6 -> V_42 ,
V_2 -> V_119 , V_2 -> V_46 ) ;
strcpy ( V_103 -> V_123 , L_17 ) ;
F_40 ( L_18 , V_103 -> V_117 ,
V_110 ) ;
V_61 = F_62 ( V_103 ) ;
if ( V_61 < 0 ) {
F_40 ( L_19 ,
V_104 ) ;
goto error;
}
V_124 [ V_110 ] = V_103 ;
V_110 ++ ;
return 0 ;
error:
F_55 ( V_103 ) ;
return V_61 ;
}
static void F_63 ( void )
{
F_55 ( V_124 [ 0 ] ) ;
}
static int F_64 ( void )
{
struct V_5 * V_6 = NULL ;
struct V_125 * V_126 ;
F_65 ( & V_127 ) ;
F_66 (list, &cx25821_devlist) {
V_6 = F_67 ( V_126 , struct V_5 , V_128 ) ;
F_56 ( V_6 ) ;
}
F_68 ( & V_127 ) ;
if ( V_6 == NULL )
F_40 ( L_20 ) ;
return 0 ;
}
