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
static int F_8 ( struct V_1 * V_2 , const char * V_6 , int V_12 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_7 ;
V_7 = F_9 ( & V_2 -> V_13 ) ;
if ( ! V_7 ) {
F_7 ( & V_5 -> V_8 , L_3 ) ;
return - V_14 ;
}
F_2 ( & V_5 -> V_8 , L_4 ,
V_6 [ 1 ] , V_6 [ 2 ] ) ;
V_2 -> V_15 = V_6 [ 2 ] ;
F_3 ( & V_2 -> V_11 ) ;
V_7 = F_4 ( V_5 , V_6 , V_12 ) ;
F_6 ( & V_2 -> V_11 ) ;
if ( V_7 < 0 ) {
F_7 ( & V_5 -> V_8 , L_2 , V_7 ) ;
goto V_16;
}
F_2 ( & V_5 -> V_8 , L_5 , V_6 [ 2 ] ) ;
if ( F_10 ( & V_2 -> V_17 , V_18 ) == 0 ) {
V_7 = - V_19 ;
goto V_16;
}
V_7 = V_2 -> V_20 ;
V_16:
F_6 ( & V_2 -> V_13 ) ;
return V_7 ;
}
static int F_11 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
char V_6 [ 3 ] ;
int V_7 ;
F_2 ( & V_5 -> V_8 , L_1 , V_9 , V_3 ) ;
V_6 [ 0 ] = V_10 ;
V_6 [ 1 ] = 1 ;
V_6 [ 2 ] = V_3 ;
V_7 = F_8 ( V_2 , & V_6 [ 0 ] , F_5 ( V_6 ) ) ;
if ( V_7 < 0 ) {
F_7 ( & V_5 -> V_8 , L_2 , V_7 ) ;
return V_7 ;
}
return 0 ;
}
static int F_12 ( struct V_1 * V_2 , T_2 V_21 , T_2 V_22 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
char V_6 [ 7 ] = { V_10 , 5 , V_23 ,
( V_21 & 0xff ) , ( ( V_21 >> 8 ) & 0xff ) ,
( V_22 & 0xff ) , ( ( V_22 >> 8 ) & 0xff ) } ;
F_2 ( & V_5 -> V_8 , L_6 , V_21 , V_22 ) ;
return F_8 ( V_2 , & V_6 [ 0 ] , F_5 ( V_6 ) ) ;
}
static int F_13 ( struct V_1 * V_2 , T_2 V_24 , T_2 V_25 ,
T_2 V_26 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
char V_6 [ 9 ] = { V_10 , 7 , V_27 ,
( V_24 & 0xff ) , ( ( V_24 >> 8 ) & 0xff ) ,
( V_25 & 0xff ) , ( ( V_25 >> 8 ) & 0xff ) ,
( V_26 & 0xff ) , ( ( V_26 >> 8 ) & 0xff ) } ;
F_2 ( & V_5 -> V_8 ,
L_7 ,
V_24 , V_25 , V_26 ) ;
return F_8 ( V_2 , & V_6 [ 0 ] , F_5 ( V_6 ) ) ;
}
static int F_14 ( struct V_1 * V_2 , char V_28 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
char V_6 [ 7 ] = { V_10 , 5 , V_29 ,
V_28 , 0 , 0 , 0 } ;
F_2 ( & V_5 -> V_8 , L_8 , V_28 ) ;
return F_8 ( V_2 , & V_6 [ 0 ] , F_5 ( V_6 ) ) ;
}
static int F_15 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
const struct V_30 * V_31 = V_2 -> V_31 ;
int V_7 ;
F_2 ( & V_5 -> V_8 , L_9 ) ;
V_7 = F_11 ( V_2 , V_32 ) ;
if ( V_7 ) {
F_7 ( & V_5 -> V_8 , L_10 , V_7 ) ;
return V_7 ;
}
V_7 = F_12 ( V_2 , V_31 -> V_33 , V_31 -> V_34 ) ;
if ( V_7 ) {
F_7 ( & V_5 -> V_8 , L_11 , V_7 ) ;
goto error;
}
V_7 = F_13 ( V_2 , 10 , 50 , 50 ) ;
if ( V_7 ) {
F_7 ( & V_5 -> V_8 , L_12 ,
V_7 ) ;
goto error;
}
V_7 = F_14 ( V_2 , V_35 ) ;
if ( V_7 ) {
F_7 ( & V_5 -> V_8 , L_13 ) ;
goto error;
}
V_7 = F_1 ( V_2 , V_36 ) ;
if ( V_7 ) {
F_7 ( & V_5 -> V_8 , L_14 ) ;
goto error;
}
F_16 ( 200 ) ;
return 0 ;
error:
F_11 ( V_2 , V_37 ) ;
return V_7 ;
}
static int F_17 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_7 ;
F_2 ( & V_5 -> V_8 , L_15 ) ;
V_7 = F_11 ( V_2 , V_37 ) ;
if ( V_7 != 0 ) {
F_7 ( & V_5 -> V_8 , L_16 ,
V_7 ) ;
return V_7 ;
}
return 0 ;
}
static int F_18 ( struct V_1 * V_2 , T_1 * V_38 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
const struct V_30 * V_31 = V_2 -> V_31 ;
struct V_39 V_40 ;
int V_41 , V_42 , V_43 = 0 ;
V_41 = V_38 [ 0 ] ;
if ( V_41 > V_44 ) {
F_19 ( & V_5 -> V_8 ,
L_17 ,
V_41 , V_44 ) ;
V_41 = V_44 ;
}
for ( V_42 = 0 ; V_42 < V_41 ; V_42 ++ ) {
V_40 . V_45 =
V_38 [ 9 * V_42 + 2 ] << 8 | V_38 [ 9 * V_42 + 1 ] ;
V_40 . V_46 =
V_38 [ 9 * V_42 + 4 ] << 8 | V_38 [ 9 * V_42 + 3 ] ;
if ( V_40 . V_45 > V_31 -> V_33 ||
V_40 . V_46 > V_31 -> V_34 ) {
F_19 ( & V_5 -> V_8 , L_18 ,
V_40 . V_45 , V_40 . V_46 ) ;
V_40 . V_45 = V_40 . V_46 = 0 ;
}
V_40 . V_47 = V_38 [ 9 * V_42 + 5 ] & 0x03 ;
V_40 . V_48 = ( V_38 [ 9 * V_42 + 5 ] & 0xfc ) >> 2 ;
V_40 . V_49 = F_20 ( V_38 [ 9 * V_42 + 6 ] ,
V_38 [ 9 * V_42 + 7 ] ) ;
V_40 . V_50 = F_21 ( V_38 [ 9 * V_42 + 6 ] ,
V_38 [ 9 * V_42 + 7 ] ) ;
V_40 . V_51 = V_38 [ 9 * V_42 + 6 ] > V_38 [ 9 * V_42 + 7 ] ;
V_40 . V_52 = V_38 [ 9 * V_42 + 8 ] ;
V_40 . V_53 = V_38 [ 9 * V_42 + 9 ] ;
F_2 ( & V_5 -> V_8 ,
L_19 ,
V_42 , V_41 , V_40 . V_47 , V_40 . V_48 ,
V_40 . V_52 , V_40 . V_53 ,
V_40 . V_45 , V_40 . V_46 ,
V_40 . V_49 , V_40 . V_50 ,
V_40 . V_51 ) ;
F_22 ( V_2 -> V_54 , V_40 . V_48 - 1 ) ;
F_23 ( V_2 -> V_54 , V_55 ,
V_40 . V_47 != V_56 ) ;
if ( V_40 . V_47 != V_56 ) {
F_24 ( V_2 -> V_54 , V_57 ,
V_40 . V_45 ) ;
F_24 ( V_2 -> V_54 , V_58 ,
V_40 . V_46 ) ;
F_24 ( V_2 -> V_54 , V_59 ,
V_40 . V_49 ) ;
F_24 ( V_2 -> V_54 , V_60 ,
V_40 . V_50 ) ;
F_24 ( V_2 -> V_54 , V_61 ,
V_40 . V_51 ) ;
V_43 ++ ;
}
}
F_25 ( V_2 -> V_54 ) ;
F_26 ( V_2 -> V_54 , V_43 ) ;
F_27 ( V_2 -> V_54 ) ;
return 0 ;
}
static int F_28 ( struct V_1 * V_2 , T_1 * V_6 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_7 ;
F_3 ( & V_2 -> V_11 ) ;
V_7 = F_29 ( V_5 , V_6 , 2 ) ;
if ( V_7 < 0 ) {
F_7 ( & V_5 -> V_8 , L_20 , V_7 ) ;
goto V_16;
}
if ( V_6 [ V_62 ] != V_10 ) {
F_7 ( & V_5 -> V_8 , L_21 , V_6 [ 0 ] ) ;
V_7 = - V_63 ;
goto V_16;
}
if ( V_6 [ V_64 ] == 0 ) {
F_7 ( & V_5 -> V_8 , L_22 ,
V_6 [ V_64 ] ) ;
V_7 = - V_63 ;
goto V_16;
}
V_7 = F_29 ( V_5 , & V_6 [ V_65 ] , V_6 [ V_64 ] ) ;
if ( V_7 < 0 ) {
F_7 ( & V_5 -> V_8 , L_23 , V_7 ) ;
goto V_16;
}
F_2 ( & V_5 -> V_8 , L_24 ,
V_6 [ V_64 ] , V_6 [ V_65 ] ) ;
V_16:
F_6 ( & V_2 -> V_11 ) ;
return V_7 ;
}
static void F_30 ( struct V_1 * V_2 , int V_3 , int V_66 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
if ( V_2 -> V_15 == V_3 ) {
F_2 ( & V_5 -> V_8 , L_25 , V_3 ) ;
V_2 -> V_20 = V_66 ;
F_31 ( & V_2 -> V_17 ) ;
} else {
F_2 ( & V_5 -> V_8 , L_26 , V_3 ) ;
}
}
static T_3 F_32 ( int V_67 , void * V_68 )
{
struct V_1 * V_2 = V_68 ;
struct V_4 * V_5 = V_2 -> V_5 ;
if ( V_2 -> V_69 && F_33 ( & V_5 -> V_8 ) )
F_34 ( & V_5 -> V_8 , 500 ) ;
return V_70 ;
}
static T_3 F_35 ( int V_67 , void * V_68 )
{
struct V_1 * V_2 = V_68 ;
struct V_4 * V_5 = V_2 -> V_5 ;
const struct V_30 * V_31 = V_2 -> V_31 ;
int V_7 ;
T_1 V_71 [ V_72 ] ;
T_1 * V_38 ;
if ( V_2 -> V_69 ) {
F_16 ( 20 ) ;
return V_73 ;
}
F_2 ( & V_5 -> V_8 , L_27 ) ;
if ( ! V_2 -> V_74 && F_33 ( & V_5 -> V_8 ) )
F_36 ( & V_5 -> V_8 ) ;
while ( ! F_37 ( V_31 -> V_75 ) ) {
V_7 = F_28 ( V_2 , V_71 ) ;
if ( V_7 < 0 ) {
F_7 ( & V_5 -> V_8 ,
L_28 , V_7 ) ;
break;
}
V_38 = & V_71 [ V_65 ] ;
switch ( V_38 [ V_76 ] ) {
case V_77 :
if ( V_2 -> V_74 && F_33 ( & V_5 -> V_8 ) )
F_34 ( & V_5 -> V_8 , 500 ) ;
F_18 ( V_2 , & V_38 [ V_78 ] ) ;
break;
case V_79 :
V_2 -> V_80 = V_38 [ V_78 ] ;
F_30 ( V_2 , V_38 [ V_76 ] , 0 ) ;
break;
case V_81 :
case V_82 :
case V_83 :
case V_84 :
case V_85 :
F_30 ( V_2 , V_38 [ V_76 ] ,
V_38 [ V_78 ] ) ;
break;
case V_86 :
V_2 -> V_87 = ( V_38 [ V_78 + 1 ] << 8 ) |
V_38 [ V_78 ] ;
V_2 -> V_88 = ( V_38 [ V_78 + 3 ] << 8 ) |
V_38 [ V_78 + 2 ] ;
V_2 -> V_89 = ( V_38 [ V_78 + 5 ] << 8 ) |
V_38 [ V_78 + 4 ] ;
V_2 -> V_90 = ( V_38 [ V_78 + 7 ] << 8 ) |
V_38 [ V_78 + 6 ] ;
F_2 ( & V_2 -> V_5 -> V_8 ,
L_29 ,
V_2 -> V_87 , V_2 -> V_88 ,
V_2 -> V_89 , V_2 -> V_90 ) ;
F_30 ( V_2 , V_38 [ V_76 ] , 0 ) ;
break;
case V_91 :
F_7 ( & V_2 -> V_5 -> V_8 , L_30 ,
V_38 [ V_78 ] ) ;
break;
default:
F_7 ( & V_2 -> V_5 -> V_8 ,
L_31 ,
V_38 [ V_76 ] ) ;
break;
}
}
if ( ! V_2 -> V_74 && F_33 ( & V_5 -> V_8 ) )
F_38 ( & V_5 -> V_8 ) ;
F_2 ( & V_5 -> V_8 , L_32 ) ;
return V_73 ;
}
static int F_39 ( struct V_92 * V_8 )
{
struct V_1 * V_2 = F_40 ( V_8 ) ;
int V_7 ;
V_7 = F_15 ( V_2 ) ;
if ( V_7 )
return V_7 ;
return 0 ;
}
static void F_41 ( struct V_92 * V_8 )
{
struct V_1 * V_2 = F_40 ( V_8 ) ;
struct V_4 * V_5 = V_2 -> V_5 ;
int V_7 ;
V_7 = F_17 ( V_2 ) ;
if ( V_7 )
F_19 ( & V_5 -> V_8 , L_33 ) ;
return;
}
static int F_42 ( struct V_93 * V_8 )
{
struct V_4 * V_5 = F_43 ( V_8 ) ;
struct V_1 * V_2 = F_44 ( V_5 ) ;
struct V_92 * V_54 = V_2 -> V_54 ;
int V_7 = 0 ;
F_3 ( & V_54 -> V_94 ) ;
V_2 -> V_74 = true ;
if ( F_33 ( & V_5 -> V_8 ) ) {
F_2 ( & V_5 -> V_8 , L_34 ) ;
if ( ! V_54 -> V_95 ) {
V_7 = F_15 ( V_2 ) ;
if ( V_7 )
goto V_16;
}
F_45 ( V_5 -> V_67 ) ;
} else if ( V_54 -> V_95 ) {
F_2 ( & V_5 -> V_8 ,
L_35 ) ;
V_7 = F_17 ( V_2 ) ;
if ( V_7 )
goto V_16;
F_46 ( V_5 -> V_67 ) ;
}
V_2 -> V_69 = true ;
V_16:
V_2 -> V_74 = false ;
F_6 ( & V_54 -> V_94 ) ;
return V_7 ;
}
static int F_47 ( struct V_93 * V_8 )
{
struct V_4 * V_5 = F_43 ( V_8 ) ;
struct V_1 * V_2 = F_44 ( V_5 ) ;
struct V_92 * V_54 = V_2 -> V_54 ;
int V_7 = 0 ;
F_3 ( & V_54 -> V_94 ) ;
V_2 -> V_69 = false ;
if ( F_33 ( & V_5 -> V_8 ) ) {
F_2 ( & V_5 -> V_8 , L_36 ) ;
F_48 ( V_5 -> V_67 ) ;
if ( ! V_54 -> V_95 ) {
V_7 = F_17 ( V_2 ) ;
if ( V_7 )
goto V_16;
}
} else if ( V_54 -> V_95 ) {
F_2 ( & V_5 -> V_8 , L_37 ) ;
F_49 ( V_5 -> V_67 ) ;
V_7 = F_15 ( V_2 ) ;
if ( V_7 < 0 )
goto V_16;
}
V_16:
F_6 ( & V_54 -> V_94 ) ;
return V_7 ;
}
static void F_50 ( void * V_96 )
{
struct V_1 * V_2 = V_96 ;
F_51 ( V_2 -> V_31 -> V_97 , 0 ) ;
F_52 ( 10 ) ;
if ( ! F_53 ( V_2 -> V_98 ) )
F_54 ( V_2 -> V_98 ) ;
}
static struct V_30 * F_55 ( struct V_93 * V_8 )
{
struct V_30 * V_31 ;
struct V_99 * V_100 = V_8 -> V_101 ;
if ( ! V_100 )
return F_56 ( - V_102 ) ;
V_31 = F_57 ( V_8 , sizeof( * V_31 ) , V_103 ) ;
if ( ! V_31 ) {
F_7 ( V_8 , L_38 ) ;
return F_56 ( - V_104 ) ;
}
V_31 -> V_75 = F_58 ( V_100 , 0 ) ;
if ( ! F_59 ( V_31 -> V_75 ) ) {
F_7 ( V_8 , L_39 ) ;
return F_56 ( - V_105 ) ;
}
V_31 -> V_97 = F_58 ( V_100 , 1 ) ;
if ( ! F_59 ( V_31 -> V_97 ) ) {
F_7 ( V_8 , L_40 ) ;
return F_56 ( - V_105 ) ;
}
if ( F_60 ( V_100 , L_41 , & V_31 -> V_33 ) ) {
F_7 ( V_8 , L_42 ) ;
return F_56 ( - V_105 ) ;
}
if ( F_60 ( V_100 , L_43 , & V_31 -> V_34 ) ) {
F_7 ( V_8 , L_44 ) ;
return F_56 ( - V_105 ) ;
}
return V_31 ;
}
static int F_61 ( struct V_4 * V_5 ,
const struct V_106 * V_48 )
{
const struct V_30 * V_31 = F_62 ( & V_5 -> V_8 ) ;
struct V_1 * V_2 ;
struct V_92 * V_92 ;
int V_7 ;
if ( ! V_31 ) {
V_31 = F_55 ( & V_5 -> V_8 ) ;
if ( F_53 ( V_31 ) )
return F_63 ( V_31 ) ;
}
V_2 = F_57 ( & V_5 -> V_8 , sizeof( struct V_1 ) , V_103 ) ;
if ( ! V_2 )
return - V_104 ;
V_7 = F_64 ( & V_5 -> V_8 , V_31 -> V_75 , V_107 ,
L_45 ) ;
if ( V_7 ) {
F_7 ( & V_5 -> V_8 , L_46 ,
V_31 -> V_75 , V_7 ) ;
return V_7 ;
}
V_7 = F_64 ( & V_5 -> V_8 , V_31 -> V_97 ,
V_108 , L_47 ) ;
if ( V_7 ) {
F_7 ( & V_5 -> V_8 , L_46 ,
V_31 -> V_97 , V_7 ) ;
return V_7 ;
}
V_2 -> V_98 = F_65 ( & V_5 -> V_8 , L_48 ) ;
if ( F_53 ( V_2 -> V_98 ) ) {
V_7 = F_63 ( V_2 -> V_98 ) ;
if ( V_7 == - V_109 )
return V_7 ;
} else {
V_7 = F_66 ( V_2 -> V_98 ) ;
if ( V_7 )
return V_7 ;
F_52 ( 100 ) ;
}
V_7 = F_67 ( & V_5 -> V_8 , F_50 , V_2 ) ;
if ( V_7 ) {
F_7 ( & V_5 -> V_8 , L_49 ,
V_7 ) ;
if ( ! F_53 ( V_2 -> V_98 ) )
F_54 ( V_2 -> V_98 ) ;
return V_7 ;
}
snprintf ( V_2 -> V_110 , sizeof( V_2 -> V_110 ) ,
L_50 , F_68 ( & V_5 -> V_8 ) ) ;
V_92 = F_69 ( & V_5 -> V_8 ) ;
if ( ! V_92 ) {
F_7 ( & V_5 -> V_8 , L_51 ) ;
return - V_104 ;
}
F_70 ( & V_2 -> V_11 ) ;
F_70 ( & V_2 -> V_13 ) ;
V_2 -> V_31 = V_31 ;
V_2 -> V_5 = V_5 ;
V_2 -> V_54 = V_92 ;
V_92 -> V_111 = L_52 ;
V_92 -> V_110 = V_2 -> V_110 ;
V_92 -> V_48 . V_112 = V_113 ;
V_92 -> V_114 = F_39 ;
V_92 -> V_115 = F_41 ;
F_71 ( V_116 , V_92 -> V_117 ) ;
F_71 ( V_118 , V_92 -> V_117 ) ;
F_71 ( V_119 , V_92 -> V_117 ) ;
F_72 ( V_92 , V_57 , 0 ,
V_31 -> V_33 , 0 , 0 ) ;
F_72 ( V_92 , V_58 , 0 ,
V_31 -> V_34 , 0 , 0 ) ;
F_72 ( V_92 , V_59 , 0 ,
V_120 , 0 , 0 ) ;
F_72 ( V_92 , V_60 , 0 ,
V_120 , 0 , 0 ) ;
F_72 ( V_92 , V_61 , 0 , 1 , 0 , 0 ) ;
F_73 ( V_92 , V_44 , V_121 ) ;
F_74 ( V_2 -> V_54 , V_2 ) ;
F_75 ( & V_2 -> V_17 ) ;
V_7 = F_76 ( & V_5 -> V_8 , V_5 -> V_67 ,
F_32 , F_35 ,
V_122 | V_123 ,
V_92 -> V_111 , V_2 ) ;
if ( V_7 ) {
F_7 ( & V_5 -> V_8 , L_53 , V_5 -> V_67 ) ;
return V_7 ;
}
F_77 ( V_5 , V_2 ) ;
F_51 ( V_31 -> V_97 , 1 ) ;
V_2 -> V_15 = V_79 ;
if ( F_10 ( & V_2 -> V_17 , V_18 ) == 0 )
F_19 ( & V_5 -> V_8 , L_54 ) ;
V_7 = F_11 ( V_2 , V_32 ) ;
if ( V_7 ) {
F_7 ( & V_5 -> V_8 , L_55 , V_7 ) ;
return V_7 ;
}
V_7 = F_11 ( V_2 , V_124 ) ;
if ( V_7 < 0 ) {
F_7 ( & V_5 -> V_8 , L_56 , V_7 ) ;
F_17 ( V_2 ) ;
return V_7 ;
}
V_7 = F_17 ( V_2 ) ;
if ( V_7 < 0 )
return V_7 ;
F_78 ( & V_5 -> V_8 , true ) ;
V_7 = F_79 ( V_92 ) ;
if ( V_7 ) {
F_7 ( & V_5 -> V_8 , L_57 ,
V_7 ) ;
return V_7 ;
}
return 0 ;
}
