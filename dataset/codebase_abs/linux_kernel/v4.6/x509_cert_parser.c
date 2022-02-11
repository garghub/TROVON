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
F_3 ( V_2 -> V_10 . V_12 ) ;
F_3 ( V_2 ) ;
}
}
struct V_1 * F_4 ( const void * V_13 , T_1 V_14 )
{
struct V_1 * V_2 ;
struct V_15 * V_16 ;
struct V_17 * V_18 ;
long V_19 ;
V_19 = - V_20 ;
V_2 = F_5 ( sizeof( struct V_1 ) , V_21 ) ;
if ( ! V_2 )
goto V_22;
V_2 -> V_3 = F_5 ( sizeof( struct V_23 ) , V_21 ) ;
if ( ! V_2 -> V_3 )
goto V_24;
V_16 = F_5 ( sizeof( struct V_15 ) , V_21 ) ;
if ( ! V_16 )
goto V_24;
V_16 -> V_2 = V_2 ;
V_16 -> V_13 = ( unsigned long ) V_13 ;
V_19 = F_6 ( & V_25 , V_16 , V_13 , V_14 ) ;
if ( V_19 < 0 )
goto V_26;
if ( V_16 -> V_27 ) {
F_7 ( L_1 ,
V_16 -> V_28 , V_16 -> V_28 , V_16 -> V_27 ) ;
V_19 = F_6 ( & V_29 , V_16 ,
V_16 -> V_27 , V_16 -> V_28 ) ;
if ( V_19 < 0 ) {
F_8 ( L_2 ) ;
goto V_26;
}
}
V_2 -> V_3 -> V_30 = F_9 ( V_16 -> V_30 , V_16 -> V_31 , V_21 ) ;
if ( ! V_2 -> V_3 -> V_30 )
goto V_26;
V_2 -> V_3 -> V_32 = V_16 -> V_31 ;
V_18 = F_10 ( V_2 -> V_33 ,
V_2 -> V_34 ,
V_2 -> V_35 ,
V_2 -> V_36 ) ;
if ( F_11 ( V_18 ) ) {
V_19 = F_12 ( V_18 ) ;
goto V_26;
}
V_2 -> V_6 = V_18 ;
F_3 ( V_16 ) ;
return V_2 ;
V_26:
F_3 ( V_2 -> V_3 -> V_30 ) ;
F_3 ( V_16 ) ;
V_24:
F_1 ( V_2 ) ;
V_22:
return F_13 ( V_19 ) ;
}
int F_14 ( void * V_37 , T_1 V_38 ,
unsigned char V_39 ,
const void * V_40 , T_1 V_41 )
{
struct V_15 * V_16 = V_37 ;
V_16 -> V_42 = F_15 ( V_40 , V_41 ) ;
if ( V_16 -> V_42 == V_43 ) {
char V_44 [ 50 ] ;
F_16 ( V_40 , V_41 , V_44 , sizeof( V_44 ) ) ;
F_17 ( L_3 ,
( unsigned long ) V_40 - V_16 -> V_13 , V_44 ) ;
}
return 0 ;
}
int F_18 ( void * V_37 , T_1 V_38 ,
unsigned char V_39 ,
const void * V_40 , T_1 V_41 )
{
struct V_15 * V_16 = V_37 ;
F_17 ( L_4 ,
V_38 , V_39 , ( unsigned long ) V_40 - V_16 -> V_13 , V_41 ) ;
V_16 -> V_2 -> V_45 = V_40 - V_38 ;
V_16 -> V_2 -> V_46 = V_41 + V_38 ;
return 0 ;
}
int F_19 ( void * V_37 , T_1 V_38 ,
unsigned char V_39 ,
const void * V_40 , T_1 V_41 )
{
struct V_15 * V_16 = V_37 ;
F_17 ( L_5 , V_16 -> V_42 ) ;
switch ( V_16 -> V_42 ) {
case V_47 :
case V_48 :
default:
return - V_49 ;
case V_50 :
V_16 -> V_2 -> V_10 . V_51 = L_6 ;
V_16 -> V_2 -> V_10 . V_52 = L_7 ;
break;
case V_53 :
V_16 -> V_2 -> V_10 . V_51 = L_8 ;
V_16 -> V_2 -> V_10 . V_52 = L_7 ;
break;
case V_54 :
V_16 -> V_2 -> V_10 . V_51 = L_9 ;
V_16 -> V_2 -> V_10 . V_52 = L_7 ;
break;
case V_55 :
V_16 -> V_2 -> V_10 . V_51 = L_10 ;
V_16 -> V_2 -> V_10 . V_52 = L_7 ;
break;
case V_56 :
V_16 -> V_2 -> V_10 . V_51 = L_11 ;
V_16 -> V_2 -> V_10 . V_52 = L_7 ;
break;
case V_57 :
V_16 -> V_2 -> V_10 . V_51 = L_12 ;
V_16 -> V_2 -> V_10 . V_52 = L_7 ;
break;
}
V_16 -> V_58 = V_16 -> V_42 ;
return 0 ;
}
int F_20 ( void * V_37 , T_1 V_38 ,
unsigned char V_39 ,
const void * V_40 , T_1 V_41 )
{
struct V_15 * V_16 = V_37 ;
F_17 ( L_13 , V_16 -> V_42 , V_41 ) ;
if ( V_16 -> V_42 != V_16 -> V_58 ) {
F_8 ( L_14 ,
V_16 -> V_58 , V_16 -> V_42 ) ;
return - V_59 ;
}
V_16 -> V_2 -> V_60 = V_40 ;
V_16 -> V_2 -> V_61 = V_41 ;
return 0 ;
}
int F_21 ( void * V_37 , T_1 V_38 ,
unsigned char V_39 ,
const void * V_40 , T_1 V_41 )
{
struct V_15 * V_16 = V_37 ;
V_16 -> V_2 -> V_33 = V_40 ;
V_16 -> V_2 -> V_34 = V_41 ;
return 0 ;
}
int F_22 ( void * V_37 , T_1 V_38 ,
unsigned char V_39 ,
const void * V_40 , T_1 V_41 )
{
struct V_15 * V_16 = V_37 ;
switch ( V_16 -> V_42 ) {
case V_62 :
V_16 -> V_63 = V_41 ;
V_16 -> V_64 = ( unsigned long ) V_40 - V_16 -> V_13 ;
break;
case V_65 :
V_16 -> V_66 = V_41 ;
V_16 -> V_67 = ( unsigned long ) V_40 - V_16 -> V_13 ;
break;
case V_68 :
V_16 -> V_69 = V_41 ;
V_16 -> V_70 = ( unsigned long ) V_40 - V_16 -> V_13 ;
break;
default:
break;
}
return 0 ;
}
static int F_23 ( struct V_15 * V_16 , T_1 V_38 ,
unsigned char V_39 ,
char * * V_71 , T_1 V_41 )
{
const void * V_72 , * V_13 = ( const void * ) V_16 -> V_13 ;
T_1 V_73 ;
char * V_44 ;
if ( * V_71 )
return - V_59 ;
if ( ! V_16 -> V_63 && ! V_16 -> V_66 && ! V_16 -> V_69 ) {
V_44 = F_24 ( 1 , V_21 ) ;
if ( ! V_44 )
return - V_20 ;
V_44 [ 0 ] = 0 ;
goto V_74;
}
if ( V_16 -> V_63 && V_16 -> V_66 ) {
V_73 = V_16 -> V_63 ;
V_72 = V_13 + V_16 -> V_64 ;
if ( V_16 -> V_63 >= V_16 -> V_66 &&
memcmp ( V_13 + V_16 -> V_64 , V_13 + V_16 -> V_67 ,
V_16 -> V_66 ) == 0 )
goto V_75;
if ( V_16 -> V_63 >= 7 &&
V_16 -> V_66 >= 7 &&
memcmp ( V_13 + V_16 -> V_64 , V_13 + V_16 -> V_67 , 7 ) == 0 )
goto V_75;
V_44 = F_24 ( V_16 -> V_66 + 2 + V_16 -> V_63 + 1 ,
V_21 ) ;
if ( ! V_44 )
return - V_20 ;
memcpy ( V_44 ,
V_13 + V_16 -> V_67 , V_16 -> V_66 ) ;
V_44 [ V_16 -> V_66 + 0 ] = ':' ;
V_44 [ V_16 -> V_66 + 1 ] = ' ' ;
memcpy ( V_44 + V_16 -> V_66 + 2 ,
V_13 + V_16 -> V_64 , V_16 -> V_63 ) ;
V_44 [ V_16 -> V_66 + 2 + V_16 -> V_63 ] = 0 ;
goto V_74;
} else if ( V_16 -> V_63 ) {
V_73 = V_16 -> V_63 ;
V_72 = V_13 + V_16 -> V_64 ;
} else if ( V_16 -> V_66 ) {
V_73 = V_16 -> V_66 ;
V_72 = V_13 + V_16 -> V_67 ;
} else {
V_73 = V_16 -> V_69 ;
V_72 = V_13 + V_16 -> V_70 ;
}
V_75:
V_44 = F_24 ( V_73 + 1 , V_21 ) ;
if ( ! V_44 )
return - V_20 ;
memcpy ( V_44 , V_72 , V_73 ) ;
V_44 [ V_73 ] = 0 ;
V_74:
* V_71 = V_44 ;
V_16 -> V_63 = 0 ;
V_16 -> V_66 = 0 ;
V_16 -> V_69 = 0 ;
return 0 ;
}
int F_25 ( void * V_37 , T_1 V_38 ,
unsigned char V_39 ,
const void * V_40 , T_1 V_41 )
{
struct V_15 * V_16 = V_37 ;
V_16 -> V_2 -> V_35 = V_40 ;
V_16 -> V_2 -> V_36 = V_41 ;
return F_23 ( V_16 , V_38 , V_39 , & V_16 -> V_2 -> V_4 , V_41 ) ;
}
int F_26 ( void * V_37 , T_1 V_38 ,
unsigned char V_39 ,
const void * V_40 , T_1 V_41 )
{
struct V_15 * V_16 = V_37 ;
V_16 -> V_2 -> V_76 = V_40 ;
V_16 -> V_2 -> V_77 = V_41 ;
return F_23 ( V_16 , V_38 , V_39 , & V_16 -> V_2 -> V_5 , V_41 ) ;
}
int F_27 ( void * V_37 , T_1 V_38 ,
unsigned char V_39 ,
const void * V_40 , T_1 V_41 )
{
struct V_15 * V_16 = V_37 ;
if ( V_16 -> V_42 != V_78 )
return - V_49 ;
V_16 -> V_2 -> V_3 -> V_52 = L_7 ;
V_16 -> V_30 = V_40 + 1 ;
V_16 -> V_31 = V_41 - 1 ;
return 0 ;
}
int F_28 ( void * V_37 , T_1 V_38 ,
unsigned char V_39 ,
const void * V_40 , T_1 V_41 )
{
struct V_15 * V_16 = V_37 ;
struct V_17 * V_18 ;
const unsigned char * V_79 = V_40 ;
F_17 ( L_15 , V_16 -> V_42 ) ;
if ( V_16 -> V_42 == V_80 ) {
if ( V_16 -> V_2 -> V_7 || V_41 < 3 )
return - V_81 ;
if ( V_79 [ 0 ] != V_82 || V_79 [ 1 ] != V_41 - 2 )
return - V_81 ;
V_79 += 2 ;
V_41 -= 2 ;
V_16 -> V_2 -> V_83 = V_41 ;
V_16 -> V_2 -> V_84 = V_79 ;
V_18 = F_10 ( V_79 , V_41 , L_16 , 0 ) ;
if ( F_11 ( V_18 ) )
return F_12 ( V_18 ) ;
V_16 -> V_2 -> V_7 = V_18 ;
F_17 ( L_17 , V_18 -> V_85 , V_18 -> V_13 ) ;
return 0 ;
}
if ( V_16 -> V_42 == V_86 ) {
V_16 -> V_27 = V_79 ;
V_16 -> V_28 = V_41 ;
return 0 ;
}
return 0 ;
}
int F_29 ( T_2 * V_87 , T_1 V_38 ,
unsigned char V_39 ,
const unsigned char * V_40 , T_1 V_41 )
{
static const unsigned char V_88 [] = { 31 , 28 , 31 , 30 , 31 , 30 ,
31 , 31 , 30 , 31 , 30 , 31 } ;
const unsigned char * V_89 = V_40 ;
unsigned V_90 , V_91 , V_92 , V_93 , V_94 , V_95 , V_96 ;
#define F_30 ( T_3 ) ({ unsigned char x = (X) - '0'; if (x > 9) goto invalid_time; x; })
#define F_31 ( T_4 ) ({ unsigned x = dec2bin(P[0]) * 10 + dec2bin(P[1]); P += 2; x; })
if ( V_39 == V_97 ) {
if ( V_41 != 13 )
goto V_98;
V_90 = F_31 ( V_89 ) ;
if ( V_90 >= 50 )
V_90 += 1900 ;
else
V_90 += 2000 ;
} else if ( V_39 == V_99 ) {
if ( V_41 != 15 )
goto V_98;
V_90 = F_31 ( V_89 ) * 100 + F_31 ( V_89 ) ;
if ( V_90 >= 1950 && V_90 <= 2049 )
goto V_100;
} else {
goto V_98;
}
V_91 = F_31 ( V_89 ) ;
V_92 = F_31 ( V_89 ) ;
V_93 = F_31 ( V_89 ) ;
V_94 = F_31 ( V_89 ) ;
V_95 = F_31 ( V_89 ) ;
if ( * V_89 != 'Z' )
goto V_98;
if ( V_90 < 1970 ||
V_91 < 1 || V_91 > 12 )
goto V_100;
V_96 = V_88 [ V_91 - 1 ] ;
if ( V_91 == 2 ) {
if ( V_90 % 4 == 0 ) {
V_96 = 29 ;
if ( V_90 % 100 == 0 ) {
V_96 = 28 ;
if ( V_90 % 400 == 0 )
V_96 = 29 ;
}
}
}
if ( V_92 < 1 || V_92 > V_96 ||
V_93 > 24 ||
V_94 > 59 ||
V_95 > 60 )
goto V_100;
* V_87 = mktime64 ( V_90 , V_91 , V_92 , V_93 , V_94 , V_95 ) ;
return 0 ;
V_98:
F_17 ( L_18 ,
V_39 , ( int ) V_41 , V_40 ) ;
return - V_81 ;
V_100:
F_17 ( L_19 ,
V_39 , ( int ) V_41 , V_40 ) ;
return - V_81 ;
}
int F_32 ( void * V_37 , T_1 V_38 ,
unsigned char V_39 ,
const void * V_40 , T_1 V_41 )
{
struct V_15 * V_16 = V_37 ;
return F_29 ( & V_16 -> V_2 -> V_101 , V_38 , V_39 , V_40 , V_41 ) ;
}
int F_33 ( void * V_37 , T_1 V_38 ,
unsigned char V_39 ,
const void * V_40 , T_1 V_41 )
{
struct V_15 * V_16 = V_37 ;
return F_29 ( & V_16 -> V_2 -> V_102 , V_38 , V_39 , V_40 , V_41 ) ;
}
int F_34 ( void * V_37 , T_1 V_38 ,
unsigned char V_39 ,
const void * V_40 , T_1 V_41 )
{
struct V_15 * V_16 = V_37 ;
struct V_17 * V_18 ;
F_17 ( L_20 , ( int ) V_41 , V_40 ) ;
if ( V_16 -> V_2 -> V_9 )
return 0 ;
V_18 = F_10 ( V_40 , V_41 , L_16 , 0 ) ;
if ( F_11 ( V_18 ) )
return F_12 ( V_18 ) ;
F_17 ( L_21 , V_18 -> V_85 , V_18 -> V_13 ) ;
V_16 -> V_2 -> V_9 = V_18 ;
return 0 ;
}
int F_35 ( void * V_37 , T_1 V_38 ,
unsigned char V_39 ,
const void * V_40 , T_1 V_41 )
{
struct V_15 * V_16 = V_37 ;
F_17 ( L_22 , ( int ) V_41 , V_40 ) ;
V_16 -> V_103 = V_40 ;
V_16 -> V_104 = V_41 ;
return 0 ;
}
int F_36 ( void * V_37 , T_1 V_38 ,
unsigned char V_39 ,
const void * V_40 , T_1 V_41 )
{
struct V_15 * V_16 = V_37 ;
struct V_17 * V_18 ;
F_17 ( L_23 , ( int ) V_41 , V_40 ) ;
if ( ! V_16 -> V_103 || V_16 -> V_2 -> V_8 )
return 0 ;
V_18 = F_10 ( V_40 ,
V_41 ,
V_16 -> V_103 ,
V_16 -> V_104 ) ;
if ( F_11 ( V_18 ) )
return F_12 ( V_18 ) ;
F_17 ( L_21 , V_18 -> V_85 , V_18 -> V_13 ) ;
V_16 -> V_2 -> V_8 = V_18 ;
return 0 ;
}
