static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
char V_6 [ 3 ] ;
int V_7 ;
F_2 ( & V_5 -> V_8 , L_1 , V_9 , V_3 ) ;
V_6 [ 0 ] = V_10 ;
V_6 [ 1 ] = 1 ;
V_6 [ 2 ] = V_3 ;
F_3 ( & V_2 -> V_11 ) ;
V_7 = F_4 ( V_5 , & V_6 [ 0 ] , F_5 ( V_6 ) ) ;
F_6 ( & V_2 -> V_11 ) ;
if ( V_7 < 0 ) {
F_7 ( & V_5 -> V_8 , L_2 , V_7 ) ;
return V_7 ;
}
return 0 ;
}
static void F_8 ( struct V_1 * V_2 )
{
F_9 ( V_2 -> V_12 , 1 ) ;
}
static void F_10 ( struct V_1 * V_2 )
{
F_9 ( V_2 -> V_12 , 0 ) ;
}
static int F_11 ( struct V_1 * V_2 , const char * V_6 , int V_13 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_7 ;
V_7 = F_12 ( & V_2 -> V_14 ) ;
if ( ! V_7 ) {
F_7 ( & V_5 -> V_8 , L_3 ) ;
return - V_15 ;
}
F_2 ( & V_5 -> V_8 , L_4 ,
V_6 [ 1 ] , V_6 [ 2 ] ) ;
V_2 -> V_16 = V_6 [ 2 ] ;
F_3 ( & V_2 -> V_11 ) ;
V_7 = F_4 ( V_5 , V_6 , V_13 ) ;
F_6 ( & V_2 -> V_11 ) ;
if ( V_7 < 0 ) {
F_7 ( & V_5 -> V_8 , L_2 , V_7 ) ;
goto V_17;
}
F_2 ( & V_5 -> V_8 , L_5 , V_6 [ 2 ] ) ;
if ( F_13 ( & V_2 -> V_18 , V_19 ) == 0 ) {
V_7 = - V_20 ;
goto V_17;
}
V_7 = V_2 -> V_21 ;
V_17:
F_6 ( & V_2 -> V_14 ) ;
return V_7 ;
}
static int F_14 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
char V_6 [ 3 ] ;
int V_7 ;
F_2 ( & V_5 -> V_8 , L_1 , V_9 , V_3 ) ;
V_6 [ 0 ] = V_10 ;
V_6 [ 1 ] = 1 ;
V_6 [ 2 ] = V_3 ;
V_7 = F_11 ( V_2 , & V_6 [ 0 ] , F_5 ( V_6 ) ) ;
if ( V_7 < 0 ) {
F_7 ( & V_5 -> V_8 , L_2 , V_7 ) ;
return V_7 ;
}
return 0 ;
}
static int F_15 ( struct V_1 * V_2 , T_2 V_22 , T_2 V_23 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
char V_6 [ 7 ] = { V_10 , 5 , V_24 ,
( V_22 & 0xff ) , ( ( V_22 >> 8 ) & 0xff ) ,
( V_23 & 0xff ) , ( ( V_23 >> 8 ) & 0xff ) } ;
F_2 ( & V_5 -> V_8 , L_6 , V_22 , V_23 ) ;
return F_11 ( V_2 , & V_6 [ 0 ] , F_5 ( V_6 ) ) ;
}
static int F_16 ( struct V_1 * V_2 , T_2 V_25 , T_2 V_26 ,
T_2 V_27 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
char V_6 [ 9 ] = { V_10 , 7 , V_28 ,
( V_25 & 0xff ) , ( ( V_25 >> 8 ) & 0xff ) ,
( V_26 & 0xff ) , ( ( V_26 >> 8 ) & 0xff ) ,
( V_27 & 0xff ) , ( ( V_27 >> 8 ) & 0xff ) } ;
F_2 ( & V_5 -> V_8 ,
L_7 ,
V_25 , V_26 , V_27 ) ;
return F_11 ( V_2 , & V_6 [ 0 ] , F_5 ( V_6 ) ) ;
}
static int F_17 ( struct V_1 * V_2 , char V_29 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
char V_6 [ 7 ] = { V_10 , 5 , V_30 ,
V_29 , 0 , 0 , 0 } ;
F_2 ( & V_5 -> V_8 , L_8 , V_29 ) ;
return F_11 ( V_2 , & V_6 [ 0 ] , F_5 ( V_6 ) ) ;
}
static int F_18 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
const struct V_31 * V_32 = V_2 -> V_32 ;
int V_7 ;
F_2 ( & V_5 -> V_8 , L_9 ) ;
V_7 = F_14 ( V_2 , V_33 ) ;
if ( V_7 ) {
F_7 ( & V_5 -> V_8 , L_10 , V_7 ) ;
return V_7 ;
}
V_7 = F_15 ( V_2 , V_32 -> V_34 , V_32 -> V_35 ) ;
if ( V_7 ) {
F_7 ( & V_5 -> V_8 , L_11 , V_7 ) ;
goto error;
}
V_7 = F_16 ( V_2 , 10 , 50 , 50 ) ;
if ( V_7 ) {
F_7 ( & V_5 -> V_8 , L_12 ,
V_7 ) ;
goto error;
}
V_7 = F_17 ( V_2 , V_36 ) ;
if ( V_7 ) {
F_7 ( & V_5 -> V_8 , L_13 ) ;
goto error;
}
V_7 = F_1 ( V_2 , V_37 ) ;
if ( V_7 ) {
F_7 ( & V_5 -> V_8 , L_14 ) ;
goto error;
}
F_19 ( 200 ) ;
return 0 ;
error:
F_14 ( V_2 , V_38 ) ;
return V_7 ;
}
static int F_20 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_7 ;
F_2 ( & V_5 -> V_8 , L_15 ) ;
V_7 = F_14 ( V_2 , V_38 ) ;
if ( V_7 != 0 ) {
F_7 ( & V_5 -> V_8 , L_16 ,
V_7 ) ;
return V_7 ;
}
return 0 ;
}
static int F_21 ( struct V_1 * V_2 , T_1 * V_39 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
const struct V_31 * V_32 = V_2 -> V_32 ;
struct V_40 V_41 ;
int V_42 , V_43 , V_44 = 0 ;
V_42 = V_39 [ 0 ] ;
if ( V_42 > V_45 ) {
F_22 ( & V_5 -> V_8 ,
L_17 ,
V_42 , V_45 ) ;
V_42 = V_45 ;
}
for ( V_43 = 0 ; V_43 < V_42 ; V_43 ++ ) {
V_41 . V_46 =
V_39 [ 9 * V_43 + 2 ] << 8 | V_39 [ 9 * V_43 + 1 ] ;
V_41 . V_47 =
V_39 [ 9 * V_43 + 4 ] << 8 | V_39 [ 9 * V_43 + 3 ] ;
if ( V_41 . V_46 > V_32 -> V_34 ||
V_41 . V_47 > V_32 -> V_35 ) {
F_22 ( & V_5 -> V_8 , L_18 ,
V_41 . V_46 , V_41 . V_47 ) ;
V_41 . V_46 = V_41 . V_47 = 0 ;
}
V_41 . V_48 = V_39 [ 9 * V_43 + 5 ] & 0x03 ;
V_41 . V_49 = ( V_39 [ 9 * V_43 + 5 ] & 0xfc ) >> 2 ;
V_41 . V_50 = F_23 ( V_39 [ 9 * V_43 + 6 ] ,
V_39 [ 9 * V_43 + 7 ] ) ;
V_41 . V_51 = F_24 ( V_39 [ 9 * V_43 + 6 ] ,
V_39 [ 9 * V_43 + 7 ] ) ;
V_41 . V_52 = V_39 [ 9 * V_43 + 6 ] > V_39 [ 9 * V_43 + 7 ] ;
V_41 . V_53 = V_39 [ 9 * V_43 + 8 ] ;
V_41 . V_54 = V_39 [ 9 * V_43 + 9 ] ;
F_2 ( & V_5 -> V_8 ,
L_19 ,
V_43 , V_42 , V_41 . V_48 , V_41 . V_49 ,
V_41 . V_53 , V_41 . V_54 ,
V_41 . V_46 , V_41 . V_47 ,
V_41 . V_50 , V_41 . V_51 ,
V_41 . V_52 ) ;
F_25 ( V_2 -> V_55 , V_41 . V_49 - 1 ) ;
F_26 ( V_2 -> V_55 , V_56 ,
V_41 . V_48 != V_57 ) ;
if ( V_41 . V_48 != V_57 ) {
F_27 ( V_2 -> V_55 , V_58 ,
V_41 . V_46 ) ;
F_27 ( V_2 -> V_55 , V_59 ,
V_41 . V_47 ) ;
F_27 ( V_2 -> V_55 , V_60 ,
V_41 . V_50 ) ;
F_27 ( V_2 -> V_55 , V_61 ,
V_41 . V_51 ) ;
F_27 ( V_2 -> V_55 , V_62 ,
V_41 . V_52 ) ;
V_44 ++ ;
}
}
F_28 ( V_2 -> V_55 ) ;
F_29 ( V_2 -> V_55 , V_44 ) ;
F_30 ( V_2 -> V_55 ) ;
return 0 ;
}
static int F_31 ( struct V_1 * V_2 , T_1 * V_6 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_7 ;
F_3 ( & V_2 -> V_11 ) ;
V_7 = F_32 ( V_5 , V_6 , 2 ) ;
if ( V_7 < 0 ) {
F_7 ( & V_5 -> V_8 , L_20 , V_7 ) ;
goto V_17;
}
if ( V_6 [ V_63 ] != V_10 ) {
F_7 ( & V_5 -> V_8 , L_21 , V_6 [ 0 ] ) ;
V_7 = - V_64 ;
goto V_17;
}
if ( V_6 [ V_65 ] == 0 ) {
F_7 ( & V_5 -> V_8 , L_22 ,
V_6 [ V_65 ] ) ;
V_7 = - V_64 ;
goto V_17;
}
V_7 = F_32 ( V_5 , & V_6 [ V_66 ] , V_6 [ V_65 ] ) ;
if ( V_7 < 0 ) {
F_7 ( & V_5 -> V_8 , L_23 , V_7 ) ;
goto V_17;
}
F_2 ( & V_5 -> V_8 , L_24 ,
V_6 [ V_65 ] , V_6 [ V_66 ] ) ;
V_17:
F_6 ( & V_2 -> V_11 ) ;
return V_7 ;
}
static void F_33 ( struct V_1 * V_2 , int V_3 , int V_67 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
if ( V_2 -> V_16 == V_3 ) {
F_2 ( & V_5 -> V_8 , L_25 , V_3 ) ;
V_2 -> V_21 = V_67 ;
F_34 ( & V_2 -> V_18 ) ;
} else {
F_2 ( & V_5 -> V_8 , L_26 , V_3 ) ;
}
}
static T_3 F_35 ( int V_68 , void * V_69 )
{
struct V_1 * V_2 = V_69 ;
struct V_4 * V_5 = V_2 -> V_5 ;
if ( V_2 -> V_70 && F_36 ( & V_5 -> V_8 ) )
F_37 ( & V_5 -> V_8 , 500 ) ;
return V_71 ;
}
static T_3 F_38 ( int V_68 , void * V_69 )
{
struct V_1 * V_2 = V_69 ;
struct V_4 * V_5 = V_2 -> V_5 ;
int V_7 ;
T_1 V_72 [ V_73 ] ;
T_1 * V_39 ;
if ( V_2 -> V_70 ) {
F_19 ( 20 ) ;
return V_74 ;
}
F_2 ( & V_5 -> V_8 , L_27 ) ;
if ( ! V_2 -> V_75 && F_36 ( & V_5 -> V_8 ) )
F_39 ( & V_5 -> V_8 ) ;
do {
V_7 = F_31 ( V_2 , V_72 ) ;
if ( V_7 < 0 ) {
F_7 ( & V_5 -> V_8 ,
L_28 , V_7 ) ;
break;
}
V_39 = & V_72 [ V_66 ] ;
switch ( V_39 [ V_76 ] ) {
case V_77 :
if ( V_2 -> V_75 && F_36 ( & V_5 -> V_8 ) )
F_37 ( & V_5 -> V_8 , 500 ) ;
F_21 ( V_2 , & V_39 [ V_78 ] ) ;
break;
case V_79 :
V_2 -> V_80 = V_39 [ V_78 ] ;
F_33 ( V_2 , V_39 [ V_76 ] , 0 ) ;
break;
case V_81 :
case V_82 :
case V_83 :
case V_84 :
case V_85 :
F_33 ( V_2 , V_39 [ V_76 ] ,
V_39 [ V_78 ] ) ;
break;
case V_86 :
V_2 -> V_87 = ( V_39 [ V_78 + 1 ] << 8 ) |
V_39 [ V_78 ] ;
V_2 -> V_88 = ( V_39 [ V_78 + 3 ] << 8 ) |
V_39 [ V_78 + 2 ] ;
V_2 -> V_89 = ( V_39 [ V_78 + 5 ] << 8 ) |
V_39 [ V_78 + 4 ] ;
V_2 -> V_90 = ( V_39 [ V_78 + 7 ] << 8 ) |
V_39 [ V_78 + 6 ] ;
F_2 ( & V_2 -> V_5 -> V_8 ,
L_29 ,
V_2 -> V_87 , V_2 -> V_88 ,
V_2 -> V_89 , V_2 -> V_90 ) ;
F_33 ( V_2 , V_39 [ V_76 ] , 0 ) ;
break;
case V_91 :
F_7 ( & V_2 -> V_5 -> V_8 , L_30 ,
V_39 [ V_78 ] ) ;
break;
default:
F_7 ( & V_2 -> V_5 -> V_8 ,
L_31 ,
V_39 [ V_76 ] ) ;
break;
}
} while ( F_40 ( V_2 -> V_92 ) );
if ( ! V_2 -> V_75 && F_36 ( & V_5 -> V_8 ) )
F_41 ( & V_5 -> V_8 ) ;
F_2 ( & V_5 -> V_8 , L_32 ) ;
return V_74 ;
}
static int F_42 ( struct V_93 * V_8 )
{
struct V_1 * V_2 = F_43 ( V_8 ) ;
return F_18 ( V_2 ) ;
}
static void F_44 ( struct V_93 * V_8 )
{
struct V_1 * V_2 = F_43 ( V_8 ) ;
struct V_4 * V_5 = V_2 -> V_5 ;
int V_7 ;
V_7 = F_20 ( V_2 ) ;
if ( V_7 )
F_22 ( & V_5 -> V_8 , L_33 ) ;
return;
}
static int T_4 F_45 ( struct V_94 * V_8 )
{
struct V_4 * V_5 = F_46 ( V_8 ) ;
struct V_1 * V_2 = F_47 ( V_5 ) ;
struct V_93 * V_55 = V_2 -> V_55 ;
int V_7 = 0 ;
F_3 ( & V_55 -> V_95 ) ;
V_2 -> V_75 = true ;
if ( F_36 ( & V_5 -> V_8 ) ) {
F_2 ( & V_5 -> V_8 , L_34 ) ;
if ( ! V_55 -> V_96 ) {
V_7 = F_18 ( V_2 ) ;
if ( V_7 )
goto V_17;
}
F_48 ( V_5 -> V_68 ) ;
} else if ( V_55 -> V_96 ) {
F_2 ( & V_5 -> V_8 ,
L_35 ) ;
V_7 = F_20 ( V_2 ) ;
if ( V_7 )
goto V_17;
F_49 ( V_5 -> V_68 ) ;
}
V_2 -> V_70 = true ;
V_17:
V_2 -> V_75 = false ;
F_6 ( & V_55 -> V_95 ) ;
return V_7 ;
}
static int T_4 F_50 ( struct V_94 * V_8 )
{
struct V_4 * V_5 = F_46 ( V_8 ) ;
struct V_1 * V_2 = F_47 ( V_5 ) ;
struct V_93 * V_55 = V_2 -> V_55 ;
int V_7 = 0 ;
F_3 ( & V_55 -> V_95 ) ;
V_2 -> V_70 = false ;
if ( F_36 ( & V_5 -> V_8 ) ) {
F_2 ( & V_5 -> V_8 , L_36 ) ;
F_51 ( V_5 -> V_68 ) ;
if ( ! V_55 -> V_96 ) {
V_7 = F_20 ( V_2 ) ;
if ( V_7 )
goto V_17;
}
} else if ( V_55 -> V_96 ) {
F_2 ( & V_5 -> V_8 , L_37 ) ;
F_52 ( V_5 -> V_68 ) ;
V_7 = F_18 ( V_2 ) ;
if ( V_7 < 0 )
goto V_17;
}
V_17:
F_6 ( & V_55 -> V_95 ) ;
return V_7 ;
}
static void F_53 ( void * V_97 )
{
struct V_1 * V_2 = V_97 ;
F_8 ( V_2 ) ;
F_54 ( 10 ) ;
if ( ! F_55 ( V_2 -> V_98 ) )
F_56 ( V_2 -> V_98 ) ;
}
static struct V_31 * F_57 ( struct V_94 * V_8 )
{
struct V_31 * V_32 ;
struct V_99 * V_100 = V_8 -> V_101 ;
if ( ! V_100 )
return F_58 ( - V_102 ) ;
V_32 = F_59 ( V_8 , sizeof( * V_32 ) , V_103 ) ;
if ( ! V_32 ) {
F_7 ( V_8 , L_38 ) ;
return F_58 ( - V_104 ) ;
}
if ( F_60 ( V_100 , L_39 , & V_32 -> V_34 ) ) {
F_7 ( V_8 , L_40 ) ;
return F_58 ( - V_105 ) ;
}
if ( F_60 ( V_100 , L_41 , & V_32 -> V_35 ) ) {
F_7 ( V_8 , L_42 ) ;
return F_58 ( - V_105 ) ;
}
return V_32 ;
}
static int F_61 ( struct V_4 * V_5 ,
const struct V_106 * V_49 )
{
const struct V_31 * V_32 = F_62 ( & V_5 -> V_8 ) ;
struct V_1 * V_2 ;
struct V_93 * V_93 ;
int V_7 ;
if ( ! V_32 ) {
V_32 = F_57 ( & V_5 -> V_8 ) ;
if ( F_55 ( V_32 ) )
return F_63 ( V_32 ) ;
}
V_2 = F_59 ( & V_5 -> V_8 , sizeof( struct V_1 ) , V_103 ) ;
if ( ! V_2 )
return - V_104 ;
V_2 -> V_12 = F_64 ( & V_5 -> V_8 , L_43 ,
V_107 ) ;
if ( F_55 ( V_2 -> V_12 ) ) {
V_7 = F_63 ( V_2 -> V_12 ) ;
F_7 ( & V_5 -> V_8 ,
L_44 , V_7 ) ;
return V_7 ;
}
if ( V_2 -> V_12 ) {
V_2 -> V_92 = F_64 ( & V_5 -> V_8 , L_45 ,
V_108 ) ;
if ( F_55 ( V_2 -> V_92 ) ) {
V_7 = F_63 ( V_2 -> V_92 ) ;
F_7 ( & V_5 -> V_8 ,
L_46 , V_7 ) ;
return V_7 ;
}
} else {
V_2 -> V_92 = F_65 ( & V_5 -> V_8 , NULL , 0 ,
V_108 ) ;
if ( F_55 ( V_2 -> V_92 ) ) {
V_7 = F_63 ( V_2 -> V_92 ) ;
F_7 ( & V_5 -> V_8 ,
L_46 , V_7 ) ;
return V_7 ;
}
V_2 -> V_12 = F_65 ( & V_5 -> V_8 , NULL , 1 ,
V_107 ) ;
if ( F_55 ( V_2 -> V_12 ) ) {
V_7 = F_63 ( V_2 -> V_12 ) ;
F_7 ( & V_5 -> V_8 ,
L_44 , V_7 ) ;
return V_7 ;
}
}
V_2 -> V_98 = F_66 ( & V_5 -> V_8 , L_47 ) ;
if ( F_55 ( V_2 -> V_98 ) ) {
V_7 = F_63 ( V_2 -> V_98 ) ;
if ( V_7 == - V_109 )
return V_7 ;
} else {
V_7 = F_67 ( V_2 -> V_98 ) ;
if ( V_7 )
return V_7 ;
F_54 ( 100 ) ;
}
V_7 = F_68 ( & V_5 -> V_8 , F_53 , V_2 ) ;
if ( V_7 ) {
F_7 ( & V_5 -> V_8 , L_48 ,
V_7 ) ;
if ( ! F_55 ( V_2 -> V_98 ) )
F_56 ( V_2 -> V_98 ) ;
return V_7 ;
}
snprintf ( V_2 -> V_110 , sizeof( V_2 -> V_110 ) ,
L_49 , F_69 ( & V_5 -> V_8 ) ) ;
V_93 = F_70 ( & V_5 -> V_8 ) ;
if ( ! V_93 ) {
F_7 ( & V_5 -> V_8 , L_50 ) ;
return - V_104 ;
}
F_71 ( & V_2 -> V_11 ) ;
F_71 ( & V_2 -> V_14 ) ;
V_2 -> V_32 = V_32 ;
V_2 -> V_5 = V_5 ;
V_2 -> V_55 = V_93 ;
V_93 -> V_111 = L_51 ;
V_93 -> V_110 = V_2 -> V_110 ;
V_93 -> V_49 . V_112 = V_113 ;
V_93 -> V_114 = F_42 ;
V_93 -> V_115 = F_44 ;
F_72 ( V_116 , V_93 -> V_117 ) ;
F_72 ( V_118 , V_93 -> V_117 ) ;
F_72 ( V_119 , V_93 -> V_117 ) ;
F_73 ( V_93 , V_58 , 0 ,
V_32 -> V_34 , 0 , 0 ) ;
F_73 ( V_93 , V_59 , 0 ,
V_32 -> V_35 , 0 , 0 ) ;
F_73 ( V_93 , V_60 , 0 ,
V_120 , 0 , 0 ) ;
F_73 ( V_93 , V_61 , 0 ,
V_120 , 0 , 0 ) ;
F_73 ( V_93 , V_62 , 0 , 1 , 0 , 0 ) ;
F_74 ( V_93 , V_45 , V_121 ) ;
F_75 ( V_2 -> V_55 , V_2 ) ;
F_76 ( & V_2 -> V_18 ) ;
V_7 = F_77 ( & V_5 -> V_8 , V_5 -> V_68 ,
F_35 , F_38 ,
V_122 | V_123 ,
V_93 -> V_111 , V_2 ) ;
if ( V_7 ) {
F_7 ( & V_5 -> V_8 , L_52 , V_5 -> V_68 ) ;
return V_7 ;
}
F_78 ( V_5 , V_2 ) ;
F_10 ( V_2 ) ;
V_2 -> V_16 = V_79 ;
if ( F_13 ( & V_2 -> V_18 , V_19 ) == 0 )
F_22 ( & V_5 -> V_8 , L_53 ) ;
V_7 = F_14 ( V_2 , V_33 ) ;
if ( V_7 ) {
F_7 ( & V_5 -> V_8 , L_54 , V_7 ) ;
return V_7 ;
}
V_7 = F_14 ( V_2 , V_124 ) ;
if ( V_7 < 0 ) {
F_7 ( & V_5 -> V_8 , L_55 , V_7 ) ;
F_20 ( V_2 ) ;
return V_7 ;
}
V_7 = F_20 ( V_2 ) ;
if ( V_7 < 0 )
return V_7 ;
F_79 ( & V_5 -> V_8 , true ) ;
V_7 = F_80 ( V_93 ) ;
if ( V_7 ) {
F_7 ( & V_5 -> V_8 , L_56 ,
V_7 ) ;
return V_7 ;
}
return 0 ;
}
