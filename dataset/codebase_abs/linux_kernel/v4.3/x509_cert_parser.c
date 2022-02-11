void F_1 ( struct V_1 * V_2 )
{
if ( V_2 ) {
F_2 ( V_2 -> V_3 ) ;
F_3 ( V_2 -> V_4 ) ;
F_3 ( V_2 -> V_5 ) ;
F_3 ( V_2 -> V_6 ) ;
F_3 ( V_2 -> V_7 ) ;
F_3 ( V_2 -> V_8 ) ;
F_3 ( V_2 -> V_9 ) ;
F_3 ( V_2 -> V_10 . V_11 ) ;
F_4 ( V_2 -> V_10 . V_12 . V_13 ) ;
F_3 ( V_2 ) ;
}
}
struct V_1 * F_5 ( const void * V_14 , T_1 V_15 )
{
struct V_1 * V_2 ;
struct V_16 * V_17 ;
struct V_18 * V_19 ;
long V_20 ;
V_20 = - V_21 ;
V_2 = F_6 ( sizeof( struct V_1 ) , V_22 ) ;
if ( ! V_2 )
goto V_23;
V_2 -> V_3 = F_6 ( sizeof( struct V_24 ) , V_22 ) ;
if ( ! V_2 -> V_3 )
goto V_25;
V_17 = F_6 ( sizeof( struct V_16 ) , V_22 ) ;
if ( ! V_17 )
goto V_25;
V_17 -> V_2 = V_2 ;
V_17 -> V_14 = ( unsigned long ) V_14 ;
V_20 = F_7 ( & V_26 , V_17 , V_14 , V_15 ) ;
if ( V_20 < 0 )
goto V_27;
if ( V_17 -> V_28 ) {
F_8 ( L_1 ,
V_17 -> V_29 , V_17 -> V_29 , V_17 -> V_28 ) ;
V_20 = F_7 ( & V_30 , V_17 ,
V_17 -> V_28 , V_17 -> V_29 ) ;
if ( V_20 < 0 ) {
F_9 ( L_2 ) ;
goto V_27;
}
}
V_20 = F_7 ( & V_31 , V_17 ,
V_17 -> V_32 , V_17 -> V_33 ) ;
if ( V_20 < 0 )
goto V_27;
V_19 = F_10 ( V_2 -> V_34 ,
V_2 -> V_35 ,
V_2 -> V_36 ,
V_2 -> V_37 ) ;
if ( F_11 ( V_19 ) ) {
V_20 = F_12 ( V_19 ) ;
goto V_27;
}
V_2 -> V_6 = V_19 ;
F_3 ( V_17 ) ;
return V_2 ;
V_27:
F_3 ( V_17 ) ;
V_25:
F_1 ( V_2 ) ;
V_23:
return F_13 ( V_20 ) ;
}
int F_14 ( void * V_38 , T_1 V_39 ,
unsigned char V_40 ,
const void * V_41 , T_1 V_42 )
{
struct V_16 * V_17 = V_38 ;
V_17 -> V_43 = F_15 ( V_41 , V_42 ) ;
if ( V_17 -> V_43 == V_44 ) {
char V_45 [ 50 ] ;
F_16 ( V_41 , V_42 , V_45 , sizeof( V_45 ) ) ;
F_17 ( L_3 ,
( unsigned long ) V_41 - V_17 -> V_14 , V_45 ) ;
}
return 0 ;
}
int F_18 ( void * V_38 , T_1 V_39 ,
unsigned char V_40 ,
const void * V_41 , T_1 V_42 )
{
struct V_16 * V_17 = V_38 ;
F_17 ( L_4 ,
V_39 , V_40 , ( unsigned long ) V_41 - V_17 -> V_14 , V_42 ) ;
V_17 -> V_2 -> V_46 = V_41 - V_39 ;
V_17 -> V_2 -> V_47 = V_42 + V_39 ;
return 0 ;
}
int F_19 ( void * V_38 , T_1 V_39 ,
unsigned char V_40 ,
const void * V_41 , T_1 V_42 )
{
struct V_16 * V_17 = V_38 ;
F_17 ( L_5 , V_17 -> V_43 ) ;
switch ( V_17 -> V_43 ) {
case V_48 :
case V_49 :
default:
return - V_50 ;
case V_51 :
V_17 -> V_2 -> V_10 . V_52 = V_53 ;
V_17 -> V_2 -> V_10 . V_54 = V_55 ;
break;
case V_56 :
V_17 -> V_2 -> V_10 . V_52 = V_57 ;
V_17 -> V_2 -> V_10 . V_54 = V_55 ;
break;
case V_58 :
V_17 -> V_2 -> V_10 . V_52 = V_59 ;
V_17 -> V_2 -> V_10 . V_54 = V_55 ;
break;
case V_60 :
V_17 -> V_2 -> V_10 . V_52 = V_61 ;
V_17 -> V_2 -> V_10 . V_54 = V_55 ;
break;
case V_62 :
V_17 -> V_2 -> V_10 . V_52 = V_63 ;
V_17 -> V_2 -> V_10 . V_54 = V_55 ;
break;
case V_64 :
V_17 -> V_2 -> V_10 . V_52 = V_65 ;
V_17 -> V_2 -> V_10 . V_54 = V_55 ;
break;
}
V_17 -> V_66 = V_17 -> V_43 ;
return 0 ;
}
int F_20 ( void * V_38 , T_1 V_39 ,
unsigned char V_40 ,
const void * V_41 , T_1 V_42 )
{
struct V_16 * V_17 = V_38 ;
F_17 ( L_6 , V_17 -> V_43 , V_42 ) ;
if ( V_17 -> V_43 != V_17 -> V_66 ) {
F_9 ( L_7 ,
V_17 -> V_66 , V_17 -> V_43 ) ;
return - V_67 ;
}
V_17 -> V_2 -> V_68 = V_41 ;
V_17 -> V_2 -> V_69 = V_42 ;
return 0 ;
}
int F_21 ( void * V_38 , T_1 V_39 ,
unsigned char V_40 ,
const void * V_41 , T_1 V_42 )
{
struct V_16 * V_17 = V_38 ;
V_17 -> V_2 -> V_34 = V_41 ;
V_17 -> V_2 -> V_35 = V_42 ;
return 0 ;
}
int F_22 ( void * V_38 , T_1 V_39 ,
unsigned char V_40 ,
const void * V_41 , T_1 V_42 )
{
struct V_16 * V_17 = V_38 ;
switch ( V_17 -> V_43 ) {
case V_70 :
V_17 -> V_71 = V_42 ;
V_17 -> V_72 = ( unsigned long ) V_41 - V_17 -> V_14 ;
break;
case V_73 :
V_17 -> V_74 = V_42 ;
V_17 -> V_75 = ( unsigned long ) V_41 - V_17 -> V_14 ;
break;
case V_76 :
V_17 -> V_77 = V_42 ;
V_17 -> V_78 = ( unsigned long ) V_41 - V_17 -> V_14 ;
break;
default:
break;
}
return 0 ;
}
static int F_23 ( struct V_16 * V_17 , T_1 V_39 ,
unsigned char V_40 ,
char * * V_79 , T_1 V_42 )
{
const void * V_80 , * V_14 = ( const void * ) V_17 -> V_14 ;
T_1 V_81 ;
char * V_45 ;
if ( * V_79 )
return - V_67 ;
if ( ! V_17 -> V_71 && ! V_17 -> V_74 && ! V_17 -> V_77 ) {
V_45 = F_24 ( 1 , V_22 ) ;
if ( ! V_45 )
return - V_21 ;
V_45 [ 0 ] = 0 ;
goto V_82;
}
if ( V_17 -> V_71 && V_17 -> V_74 ) {
V_81 = V_17 -> V_71 ;
V_80 = V_14 + V_17 -> V_72 ;
if ( V_17 -> V_71 >= V_17 -> V_74 &&
memcmp ( V_14 + V_17 -> V_72 , V_14 + V_17 -> V_75 ,
V_17 -> V_74 ) == 0 )
goto V_83;
if ( V_17 -> V_71 >= 7 &&
V_17 -> V_74 >= 7 &&
memcmp ( V_14 + V_17 -> V_72 , V_14 + V_17 -> V_75 , 7 ) == 0 )
goto V_83;
V_45 = F_24 ( V_17 -> V_74 + 2 + V_17 -> V_71 + 1 ,
V_22 ) ;
if ( ! V_45 )
return - V_21 ;
memcpy ( V_45 ,
V_14 + V_17 -> V_75 , V_17 -> V_74 ) ;
V_45 [ V_17 -> V_74 + 0 ] = ':' ;
V_45 [ V_17 -> V_74 + 1 ] = ' ' ;
memcpy ( V_45 + V_17 -> V_74 + 2 ,
V_14 + V_17 -> V_72 , V_17 -> V_71 ) ;
V_45 [ V_17 -> V_74 + 2 + V_17 -> V_71 ] = 0 ;
goto V_82;
} else if ( V_17 -> V_71 ) {
V_81 = V_17 -> V_71 ;
V_80 = V_14 + V_17 -> V_72 ;
} else if ( V_17 -> V_74 ) {
V_81 = V_17 -> V_74 ;
V_80 = V_14 + V_17 -> V_75 ;
} else {
V_81 = V_17 -> V_77 ;
V_80 = V_14 + V_17 -> V_78 ;
}
V_83:
V_45 = F_24 ( V_81 + 1 , V_22 ) ;
if ( ! V_45 )
return - V_21 ;
memcpy ( V_45 , V_80 , V_81 ) ;
V_45 [ V_81 ] = 0 ;
V_82:
* V_79 = V_45 ;
V_17 -> V_71 = 0 ;
V_17 -> V_74 = 0 ;
V_17 -> V_77 = 0 ;
return 0 ;
}
int F_25 ( void * V_38 , T_1 V_39 ,
unsigned char V_40 ,
const void * V_41 , T_1 V_42 )
{
struct V_16 * V_17 = V_38 ;
V_17 -> V_2 -> V_36 = V_41 ;
V_17 -> V_2 -> V_37 = V_42 ;
return F_23 ( V_17 , V_39 , V_40 , & V_17 -> V_2 -> V_4 , V_42 ) ;
}
int F_26 ( void * V_38 , T_1 V_39 ,
unsigned char V_40 ,
const void * V_41 , T_1 V_42 )
{
struct V_16 * V_17 = V_38 ;
V_17 -> V_2 -> V_84 = V_41 ;
V_17 -> V_2 -> V_85 = V_42 ;
return F_23 ( V_17 , V_39 , V_40 , & V_17 -> V_2 -> V_5 , V_42 ) ;
}
int F_27 ( void * V_38 , T_1 V_39 ,
unsigned char V_40 ,
const void * V_41 , T_1 V_42 )
{
struct V_16 * V_17 = V_38 ;
if ( V_17 -> V_43 != V_86 )
return - V_50 ;
V_17 -> V_2 -> V_3 -> V_54 = V_55 ;
V_17 -> V_32 = V_41 + 1 ;
V_17 -> V_33 = V_42 - 1 ;
return 0 ;
}
int F_28 ( void * V_38 , T_1 V_39 ,
unsigned char V_40 ,
const void * V_41 , T_1 V_42 )
{
struct V_16 * V_17 = V_38 ;
T_2 V_87 ;
if ( V_17 -> V_88 >= F_29 ( V_17 -> V_2 -> V_3 -> V_87 ) ) {
F_30 ( L_8 ) ;
return - V_89 ;
}
V_87 = F_31 ( V_41 , V_42 ) ;
if ( ! V_87 )
return - V_21 ;
V_17 -> V_2 -> V_3 -> V_87 [ V_17 -> V_88 ++ ] = V_87 ;
return 0 ;
}
int F_32 ( void * V_38 , T_1 V_39 ,
unsigned char V_40 ,
const void * V_41 , T_1 V_42 )
{
struct V_16 * V_17 = V_38 ;
struct V_18 * V_19 ;
const unsigned char * V_90 = V_41 ;
F_17 ( L_9 , V_17 -> V_43 ) ;
if ( V_17 -> V_43 == V_91 ) {
if ( V_17 -> V_2 -> V_7 || V_42 < 3 )
return - V_89 ;
if ( V_90 [ 0 ] != V_92 || V_90 [ 1 ] != V_42 - 2 )
return - V_89 ;
V_90 += 2 ;
V_42 -= 2 ;
V_17 -> V_2 -> V_93 = V_42 ;
V_17 -> V_2 -> V_94 = V_90 ;
V_19 = F_10 ( V_90 , V_42 , L_10 , 0 ) ;
if ( F_11 ( V_19 ) )
return F_12 ( V_19 ) ;
V_17 -> V_2 -> V_7 = V_19 ;
F_17 ( L_11 , V_19 -> V_95 , V_19 -> V_14 ) ;
return 0 ;
}
if ( V_17 -> V_43 == V_96 ) {
V_17 -> V_28 = V_90 ;
V_17 -> V_29 = V_42 ;
return 0 ;
}
return 0 ;
}
int F_33 ( T_3 * V_97 , T_1 V_39 ,
unsigned char V_40 ,
const unsigned char * V_41 , T_1 V_42 )
{
static const unsigned char V_98 [] = { 31 , 29 , 31 , 30 , 31 , 30 ,
31 , 31 , 30 , 31 , 30 , 31 } ;
const unsigned char * V_99 = V_41 ;
unsigned V_100 , V_101 , V_102 , V_103 , V_104 , V_105 , V_106 ;
#define F_34 ( T_4 ) ({ unsigned char x = (X) - '0'; if (x > 9) goto invalid_time; x; })
#define F_35 ( T_5 ) ({ unsigned x = dec2bin(P[0]) * 10 + dec2bin(P[1]); P += 2; x; })
if ( V_40 == V_107 ) {
if ( V_42 != 13 )
goto V_108;
V_100 = F_35 ( V_99 ) ;
if ( V_100 >= 50 )
V_100 += 1900 ;
else
V_100 += 2000 ;
} else if ( V_40 == V_109 ) {
if ( V_42 != 15 )
goto V_108;
V_100 = F_35 ( V_99 ) * 100 + F_35 ( V_99 ) ;
if ( V_100 >= 1950 && V_100 <= 2049 )
goto V_110;
} else {
goto V_108;
}
V_101 = F_35 ( V_99 ) ;
V_102 = F_35 ( V_99 ) ;
V_103 = F_35 ( V_99 ) ;
V_104 = F_35 ( V_99 ) ;
V_105 = F_35 ( V_99 ) ;
if ( * V_99 != 'Z' )
goto V_108;
V_106 = V_98 [ V_101 ] ;
if ( V_101 == 2 ) {
if ( V_100 % 4 == 0 ) {
V_106 = 29 ;
if ( V_100 % 100 == 0 ) {
V_100 /= 100 ;
if ( V_100 % 4 != 0 )
V_106 = 28 ;
}
}
}
if ( V_100 < 1970 ||
V_101 < 1 || V_101 > 12 ||
V_102 < 1 || V_102 > V_106 ||
V_103 < 0 || V_103 > 23 ||
V_104 < 0 || V_104 > 59 ||
V_105 < 0 || V_105 > 59 )
goto V_110;
* V_97 = mktime64 ( V_100 , V_101 , V_102 , V_103 , V_104 , V_105 ) ;
return 0 ;
V_108:
F_17 ( L_12 ,
V_40 , ( int ) V_42 , V_41 ) ;
return - V_89 ;
V_110:
F_17 ( L_13 ,
V_40 , ( int ) V_42 , V_41 ) ;
return - V_89 ;
}
int F_36 ( void * V_38 , T_1 V_39 ,
unsigned char V_40 ,
const void * V_41 , T_1 V_42 )
{
struct V_16 * V_17 = V_38 ;
return F_33 ( & V_17 -> V_2 -> V_111 , V_39 , V_40 , V_41 , V_42 ) ;
}
int F_37 ( void * V_38 , T_1 V_39 ,
unsigned char V_40 ,
const void * V_41 , T_1 V_42 )
{
struct V_16 * V_17 = V_38 ;
return F_33 ( & V_17 -> V_2 -> V_112 , V_39 , V_40 , V_41 , V_42 ) ;
}
int F_38 ( void * V_38 , T_1 V_39 ,
unsigned char V_40 ,
const void * V_41 , T_1 V_42 )
{
struct V_16 * V_17 = V_38 ;
struct V_18 * V_19 ;
F_17 ( L_14 , ( int ) V_42 , V_41 ) ;
if ( V_17 -> V_2 -> V_9 )
return 0 ;
V_19 = F_10 ( V_41 , V_42 , L_10 , 0 ) ;
if ( F_11 ( V_19 ) )
return F_12 ( V_19 ) ;
F_17 ( L_15 , V_19 -> V_95 , V_19 -> V_14 ) ;
V_17 -> V_2 -> V_9 = V_19 ;
return 0 ;
}
int F_39 ( void * V_38 , T_1 V_39 ,
unsigned char V_40 ,
const void * V_41 , T_1 V_42 )
{
struct V_16 * V_17 = V_38 ;
F_17 ( L_16 , ( int ) V_42 , V_41 ) ;
V_17 -> V_113 = V_41 ;
V_17 -> V_114 = V_42 ;
return 0 ;
}
int F_40 ( void * V_38 , T_1 V_39 ,
unsigned char V_40 ,
const void * V_41 , T_1 V_42 )
{
struct V_16 * V_17 = V_38 ;
struct V_18 * V_19 ;
F_17 ( L_17 , ( int ) V_42 , V_41 ) ;
if ( ! V_17 -> V_113 || V_17 -> V_2 -> V_8 )
return 0 ;
V_19 = F_10 ( V_41 ,
V_42 ,
V_17 -> V_113 ,
V_17 -> V_114 ) ;
if ( F_11 ( V_19 ) )
return F_12 ( V_19 ) ;
F_17 ( L_15 , V_19 -> V_95 , V_19 -> V_14 ) ;
V_17 -> V_2 -> V_8 = V_19 ;
return 0 ;
}
