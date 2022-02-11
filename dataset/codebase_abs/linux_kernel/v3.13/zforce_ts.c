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
F_2 ( & V_5 -> V_8 , L_7 ,
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
const struct V_30 * V_31 = F_16 ( & V_5 -> V_8 ) ;
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
if ( F_14 ( V_2 , V_35 ) ) {
F_7 ( & V_5 -> V_8 , L_13 ) ;
goto error;
}
V_7 = F_1 ( V_2 , V_36 ) ;
if ( V_7 ) {
F_7 ( & V_5 -> V_8 , L_14 ) ;
goto error;
}
F_17 ( 200 ) ;
return 0 ;
error:
F_11 ( V_2 , V_37 ) ;
return V_7 ;
}
static int F_18 ( struct V_1 * V_2 )
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
static int F_19 ( struct V_1 * V_2 , T_1 * V_38 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
const struct V_30 * V_31 = F_16 ( & V_5 -> V_8 ) ;
struct V_39 V_40 ;
int V_41 , V_42 , V_43 = 0 ;
V_41 = V_38 [ 0 ] ;
if ( V_41 > V_44 ) {
F_20 ( & V_5 -> V_8 , L_17 ,
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
F_20 ( & V_5 -> V_8 , L_18 ,
V_40 . V_45 , V_40 . V_46 ) ;
V_40 . V_45 = V_40 . V_46 = 0 ;
}
V_40 . V_47 = V_38 [ 9 * V_42 + 5 ] & 0x03 ;
V_40 . V_48 = ( V_38 [ 9 * V_42 + 5 ] & 0xfc ) >> 2 ;
V_40 . V_49 = F_21 ( V_38 [ 9 * V_42 + 6 ] ,
V_38 [ 9 * V_42 + 7 ] ) ;
V_40 . V_50 = F_22 ( V_38 [ 9 * V_42 + 6 ] ,
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
F_23 ( V_2 -> V_54 , V_40 . V_48 - 1 ) ;
F_24 ( V_2 -> V_54 , V_55 ,
V_40 . V_47 != V_56 ) ;
if ( V_40 . V_47 != V_56 ) {
F_25 ( V_2 -> V_54 , V_57 ,
V_40 . V_45 ) ;
F_25 ( V_2 -> V_54 , V_58 ,
V_40 . V_46 ) ;
F_25 ( V_2 -> V_54 , V_59 ,
V_40 . V_49 ) ;
F_25 ( V_2 -> V_54 , V_60 ,
V_40 . V_50 ) ;
F_25 ( V_2 -> V_54 , V_61 ,
V_40 . V_51 ) ;
V_43 ++ ;
}
}
F_26 ( V_2 -> V_54 ) ;
F_27 ( V_2 -> V_54 , V_43 ) ;
F_28 ( V_2 -> V_54 ) ;
return 0 ;
}
static int F_29 ( struct V_1 * V_2 , T_1 * V_6 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_7 ;
F_3 ( & V_2 -> V_11 ) ;
V_7 = F_30 ( V_5 , V_6 , 2 ) ;
if ( V_7 < 0 ) {
F_7 ( & V_5 -> V_8 , L_20 , V_7 ) ;
goto V_16;
}
if ( V_6 [ V_62 ] != V_10 ) {
F_7 ( & V_5 -> V_8 , L_21 , V_6 [ 0 ] ) ;
V_7 = - V_63 ;
goto V_16;
}
if ( V_6 [ V_64 ] <= 0 || V_6 [ V_64 ] > 255 ) {
F_7 ( & V_5 -> V_8 , L_22 ,
V_6 [ V_64 ] ) ;
V_7 = - V_63 ;
goto V_16;
}
V_7 = F_30 ( V_5 , & V_6 [ V_65 ] , V_6 [ V_64 ] ) ;
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
static void F_31 ( struct V_1 * V_2 , int V_3 , int V_66 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
if ( V_2 -> V_15 == V_3 ) {
F_2 ( & V_5 -> V_8 , L_25 , V_3 ) ;
V_2 -> V_20 = V_66 ;
F_32 ( & V_2 -> V_17 ) ;
} else {
F_2 ( & V_5 -> V_8 , L_26 , V_3 ) ;
}
}
static T_3 F_33 ( int V_67 , void * V_68 )
{
struct V_1 * V_2 = V_68 ;
struct V_4 * V_5 = V_2 -> V_5 ;
if ( V_2 -> V_69 && F_34 ( & V_5 -> V_8 ) )
F_35 ( & V_5 -> V_8 , 500 ) ;
return V_70 ;
}
static T_3 F_36 ( int V_67 , void * V_68 )
{
struct V_1 * V_2 = V_68 ;
struct V_4 * V_5 = V_2 -> V_5 ;
const struct V_30 * V_31 = F_16 ( & V_5 -> V_8 ) ;
int V_7 ;
T_1 V_71 [ 512 ] ;
T_1 * V_38 ;
if ( V_2 -> V_69 ) {
F_17 ( 20 ) ;
return V_72 ;
}
F_2 ( & V_5 -> V_8 , L_27 ) ;
if ( ! V_2 -> V_73 && F_34 ( & V_5 -> V_8 ) )
F_37 ( & V_5 -> V_8 ) ;
while ( ! F_38 ( V_31 -> V_74 ) ) {
V_7 = F_29 ( V_2 , V_71 ) ;
if ( V_7 < 0 ) {
F_7 ( & V_5 -> V_8 , L_28 ,
V_7 ) ;
break;
}
V_38 = & V_71 [ V_65 ] ;
switch ( V_38 [ V_75 ] ) {
case V_76 :
if ( V_2 -> V_73 && F_34 ( & V_5 -> V_8 ) )
F_35 ( & V_5 -> V_8 , 500 ) ;
F_19 ( V_2 , & V_38 [ V_77 ] ) ;
break;
case V_78 :
V_2 -> V_79 = V_38 [ V_77 ] ;
F_31 ( V_2 , V_38 [ V_75 ] , 0 ) ;
break;
case V_80 :
case V_81 :
case V_82 :
case V_83 :
case V_84 :
F_31 ( V_2 , V_38 [ V_75 ] ,
V_38 [ V_77 ] ) ;
break;
case V_85 :
V_2 -> V_86 = ( V_38 [ V_77 + 1 ] << 8 ) |
V_38 [ V_77 ] ;
V_2 -> V_87 = ( V_38 [ V_77 + 3 ] << 8 ) |
V_38 [ V_77 + 2 ] ;
V_2 -> V_88 = ( V_38 [ V_77 + 5 ] << 8 ) |
V_38 [ V_77 + 4 ] ;
V_2 -> V_89 = ( V_38 [ V_77 + 7 ] << 8 ) |
V_38 [ V_77 + 6 ] ;
F_2 ( & V_2 -> V_5 -> V_8 , L_29 ,
V_2 -> V_86 , V_2 -> V_87 ,
V_2 -> V_88 , V_2 -> V_89 ) ;
F_31 ( V_2 , V_38 [ V_75 ] , 0 ) ;
break;
case V_90 :
F_7 ( & V_2 -> V_5 -> V_8 , L_30 ,
V_38 [ V_77 ] ) ;
break;
default:
F_7 ( & V_2 -> V_5 -> V_8 , L_31 ,
V_38 [ V_75 ] ) ;
break;
}
}
if ( ! V_2 -> V_73 && F_34 ( & V_5 -> V_8 ) )
F_39 ( & V_5 -> V_8 ) ;
F_2 ( & V_5 -> V_8 , L_32 ) ;
return V_72 ;
}
static int F_40 ( struct V_91 * V_8 )
{
struct V_1 * V_2 = F_41 ( V_8 ) ;
int V_7 ;
V_7 = F_15 ( V_2 ) ;
if ( V_7 )
return V_7 ;
return 0 ;
}
static void F_42 ( struct V_91 * V_8 )
{
struct V_1 * V_2 = F_41 ( V_8 ) ;
struct V_4 * V_5 = V_2 -> V_5 ;
int V_7 ;
V_7 = F_18 ( V_2 ) ;
if ( V_7 )
F_20 ( & V_5 -> V_8 , L_33 ) ;
return;
}
static int F_43 ( struct V_92 * V_8 )
{
struct V_4 * V_5 = F_44 ( V_8 ) ;
struct V_1 * V_2 = F_45 ( V_5 ) ;
struct V_91 * V_54 = V_2 -> V_54 ;
int V_7 = 0 ;
F_3 ( & V_54 -> V_93 ) ;
V_2 -> V_73 = true ;
if ( F_34 ( & V_5 -> V_8 ) ) {
F_2 ( & V_5 -> V_8 , L_34 ) ;
if ( ! V_54 -> V_94 ) {
V_7 = F_15 ( V_2 ) ;
if ( V_7 )
goto V_16;
}
F_46 ( V_5 -> V_67 ) ;
} else if ( V_54 -> V_94 ) {
F_2 ( & V_5 -> V_8 , L_35 ) ;
V_7 = F_18 ( V_2 ) ;
if ( V_7 )
goto V_16;
F_47 ( V_5 -> V_67 ) ;
}
V_2 -> V_69 = true ;
V_16:
V_2 -> V_73 = false ;
F_6 ( & V_54 -> V_93 ) ;
return V_7 ;
}
static int F_48 ( struct V_92 * V_8 )
{
struct V_4 * V_5 = F_44 ( V_8 ) ;
struct V_1 * V_2 = F_45 ( V_5 ) ;
struct V_91 * V_54 = V_2 -> V_54 ;
int V_7 = 0 ;
F_3 ( & V_54 -> V_93 ) ;
V_2 -> V_69 = false ;
if ( F_34 ( & V_5 -> V_8 ) ) {
F_2 ( & V_5 -> V_8 , L_36 ) ;
F_49 ( V_5 -> V_67 ) ;
if ( ! V_54 -> V_94 ) {
V_7 = F_18 ( V_2 ) ;
if ( V_7 )
goto V_16;
}
} else if ( V_54 -> V_94 ) {
F_2 ( & V_5 -> V_8 , L_37 ) ;
F_50 ( V_5 -> V_67 ) ;
V_7 = F_15 ( V_2 ) ;
if ( V_7 < 0 )
goto V_16;
}
V_16:
F_6 ( & V_54 -> V_93 ) ;
return V_7 ;
}
static void F_51 ( void * V_95 )
{
struct V_1 * V_2 = V_95 ;
F_52 ( V_2 -> V_31 -> V_96 , 0 ) ;
}
static int F_53 ( struct V_4 * V_5 ,
const struct V_97 * V_48 )
{
const struct V_30 * V_31 = F_16 ( & V_5 -> V_8 ) ;
struct V_1 * V_2 ;
struct V_91 * V_91 ;
int V_7 ;
if ( ! V_31 )
return - V_98 ;
V_2 = F_54 ( & V_5 -> V_8 , sizeof( struct V_1 ) , V_99 ) ;
if ( ! V_2 )
return - V_100 ;
V_7 = F_55 ( & V_5 -> V_8 , V_31 -> V_74 , V_101 ,
L_38 ) ;
if ( V_7 ) {
F_7 ( & V_5 -> V_8 , L_39 ,
V_31 -> V_74 , V_7 ) ;
return V_7 ;
}
V_7 = F_55 ( & V_5 -> V_8 , V_31 -> V_96 ,
V_102 , L_40 ) ;
if ( V_7 ) {
F_7 ( & V_5 -> V_8 , L_39 ,
V_31 -> V_96 , V_7 ) ;
return V_7 ;
}
V_7 = F_56 ( & V_5 -> V_8 , F_51 , V_2 ) ;
if ( V_7 ) {
F_7 ( & V_5 -> V_8 , L_41 ,
V_7 ) ;
return V_7 ;
}
snprintf ( V_2 -> V_103 , sizeof( V_2 -> V_103 ) ,
L_42 , F_57 ( & V_5 -> V_8 ) ) ;
V_91 = F_58 ( & V_5 -> V_8 ) ;
if ( ! V_91 ) {
F_7 ( & V_5 -> V_8 , L_43 ) ;
return - V_100 ;
}
F_59 ( & V_2 -> V_11 ) ;
F_59 ( & V_2 -> V_13 ) ;
V_2 -> V_31 = V_31 ;
V_2 -> V_5 = V_5 ;
V_2 -> V_54 = V_91 ;
V_91 -> V_104 = L_44 ;
V_91 -> V_103 = V_2 -> V_103 ;
V_91 -> V_48 . V_105 = V_106 ;
V_91 -> V_107 = F_40 ;
V_91 -> V_108 = F_42 ;
F_60 ( V_109 , V_91 -> V_110 ) ;
F_60 ( V_111 , V_91 -> V_110 ) ;
F_60 ( V_112 , V_91 -> V_110 ) ;
F_61 ( V_91 , V_57 , 0 ,
V_31 -> V_33 , 0 , 0 ) ;
F_61 ( V_91 , V_58 , 0 ,
V_31 -> V_34 , 0 , 0 ) ;
F_61 ( V_91 , V_59 , 0 ,
V_113 , 0 , 0 ) ;
F_61 ( V_91 , V_60 , 0 ,
V_113 , 0 , 0 ) ;
F_61 ( V_91 , V_61 , 0 , 1 , 0 , 0 ) ;
F_62 ( V_91 , V_44 , V_114 ) ;
F_63 ( V_2 -> V_54 , V_2 ) ;
F_64 ( & V_2 -> V_17 ) ;
V_7 = F_65 ( & V_5 -> V_8 , V_5 -> V_67 ,
F_33 , F_36 ,
V_115 | V_116 ,
V_91 -> V_104 , V_2 ) ;
if ( V_7 ) {
F_7 ( & V_5 -> V_8 , L_45 , V_5 -> V_67 ) ;
return V_7 ;
}
F_66 ( V_5 , V_2 ) ;
F_52 ( V_31 -> V_96 , 1 ) ;
V_2 -> V_15 = V_78 ;
if ( F_10 ( & V_2 -> V_17 , V_18 ) == 0 )
F_20 ( & V_5 -> V_8 , L_46 ) ;
V_7 = F_11 ( V_2 , V_32 ) ;
if ( V_7 ) {
F_7 ( & V_5 -> V_8 , L_47 , V_7 ) ;
return V_7 ;
}
V_7 = F_11 ( V_2 , V_117 ) ;
if ( V_7 < 0 ) {
F_7 ( & V_5 -> V_8 , L_48 , V_7 ) ;
F_18 ( V_2 ) ;
return V_7 ;
}
V_7 = F_18 ( V_2 ) ;
if ( V_7 < 0 )
return V_7 ;
F_67 ( & V_5 -> V_8 , true ) ;
V_7 = F_68 ( V_91 ) ;
if ( V_7 ) {
F_7 ( & V_5 -> V_8 , L_49 ,
V_7 ) ;
return V_7 ;
}
return 0 ;
}
