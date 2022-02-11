void F_1 ( struct V_1 * V_2 )
{
if ( V_2 ) {
F_2 ( V_2 -> V_3 ) ;
F_3 ( V_2 -> V_4 ) ;
F_3 ( V_2 -> V_5 ) ;
F_3 ( V_2 -> V_6 ) ;
F_3 ( V_2 -> V_7 ) ;
F_3 ( V_2 -> V_8 . V_9 ) ;
F_4 ( V_2 -> V_8 . V_10 . V_11 ) ;
F_3 ( V_2 ) ;
}
}
struct V_1 * F_5 ( const void * V_12 , T_1 V_13 )
{
struct V_1 * V_2 ;
struct V_14 * V_15 ;
long V_16 ;
V_16 = - V_17 ;
V_2 = F_6 ( sizeof( struct V_1 ) , V_18 ) ;
if ( ! V_2 )
goto V_19;
V_2 -> V_3 = F_6 ( sizeof( struct V_20 ) , V_18 ) ;
if ( ! V_2 -> V_3 )
goto V_21;
V_15 = F_6 ( sizeof( struct V_14 ) , V_18 ) ;
if ( ! V_15 )
goto V_21;
V_15 -> V_2 = V_2 ;
V_15 -> V_12 = ( unsigned long ) V_12 ;
V_16 = F_7 ( & V_22 , V_15 , V_12 , V_13 ) ;
if ( V_16 < 0 )
goto V_23;
V_16 = F_7 ( & V_24 , V_15 ,
V_15 -> V_25 , V_15 -> V_26 ) ;
if ( V_16 < 0 )
goto V_23;
F_3 ( V_15 ) ;
return V_2 ;
V_23:
F_3 ( V_15 ) ;
V_21:
F_1 ( V_2 ) ;
V_19:
return F_8 ( V_16 ) ;
}
int F_9 ( void * V_27 , T_1 V_28 ,
unsigned char V_29 ,
const void * V_30 , T_1 V_31 )
{
struct V_14 * V_15 = V_27 ;
V_15 -> V_32 = F_10 ( V_30 , V_31 ) ;
if ( V_15 -> V_32 == V_33 ) {
char V_34 [ 50 ] ;
F_11 ( V_30 , V_31 , V_34 , sizeof( V_34 ) ) ;
F_12 ( L_1 ,
( unsigned long ) V_30 - V_15 -> V_12 , V_34 ) ;
}
return 0 ;
}
int F_13 ( void * V_27 , T_1 V_28 ,
unsigned char V_29 ,
const void * V_30 , T_1 V_31 )
{
struct V_14 * V_15 = V_27 ;
F_12 ( L_2 ,
V_28 , V_29 , ( unsigned long ) V_30 - V_15 -> V_12 , V_31 ) ;
V_15 -> V_2 -> V_35 = V_30 - V_28 ;
V_15 -> V_2 -> V_36 = V_31 + V_28 ;
return 0 ;
}
int F_14 ( void * V_27 , T_1 V_28 ,
unsigned char V_29 ,
const void * V_30 , T_1 V_31 )
{
struct V_14 * V_15 = V_27 ;
F_12 ( L_3 , V_15 -> V_32 ) ;
switch ( V_15 -> V_32 ) {
case V_37 :
case V_38 :
default:
return - V_39 ;
case V_40 :
V_15 -> V_2 -> V_8 . V_41 = V_42 ;
V_15 -> V_2 -> V_8 . V_43 = V_44 ;
break;
case V_45 :
V_15 -> V_2 -> V_8 . V_41 = V_46 ;
V_15 -> V_2 -> V_8 . V_43 = V_44 ;
break;
case V_47 :
V_15 -> V_2 -> V_8 . V_41 = V_48 ;
V_15 -> V_2 -> V_8 . V_43 = V_44 ;
break;
case V_49 :
V_15 -> V_2 -> V_8 . V_41 = V_50 ;
V_15 -> V_2 -> V_8 . V_43 = V_44 ;
break;
case V_51 :
V_15 -> V_2 -> V_8 . V_41 = V_52 ;
V_15 -> V_2 -> V_8 . V_43 = V_44 ;
break;
case V_53 :
V_15 -> V_2 -> V_8 . V_41 = V_54 ;
V_15 -> V_2 -> V_8 . V_43 = V_44 ;
break;
}
V_15 -> V_55 = V_15 -> V_32 ;
return 0 ;
}
int F_15 ( void * V_27 , T_1 V_28 ,
unsigned char V_29 ,
const void * V_30 , T_1 V_31 )
{
struct V_14 * V_15 = V_27 ;
F_12 ( L_4 , V_15 -> V_32 , V_31 ) ;
if ( V_15 -> V_32 != V_15 -> V_55 ) {
F_16 ( L_5 ,
V_15 -> V_55 , V_15 -> V_32 ) ;
return - V_56 ;
}
V_15 -> V_2 -> V_57 = V_30 ;
V_15 -> V_2 -> V_58 = V_31 ;
return 0 ;
}
int F_17 ( void * V_27 , T_1 V_28 ,
unsigned char V_29 ,
const void * V_30 , T_1 V_31 )
{
struct V_14 * V_15 = V_27 ;
V_15 -> V_2 -> V_59 = V_30 ;
V_15 -> V_2 -> V_60 = V_31 ;
return 0 ;
}
int F_18 ( void * V_27 , T_1 V_28 ,
unsigned char V_29 ,
const void * V_30 , T_1 V_31 )
{
struct V_14 * V_15 = V_27 ;
switch ( V_15 -> V_32 ) {
case V_61 :
V_15 -> V_62 = V_31 ;
V_15 -> V_63 = ( unsigned long ) V_30 - V_15 -> V_12 ;
break;
case V_64 :
V_15 -> V_65 = V_31 ;
V_15 -> V_66 = ( unsigned long ) V_30 - V_15 -> V_12 ;
break;
case V_67 :
V_15 -> V_68 = V_31 ;
V_15 -> V_69 = ( unsigned long ) V_30 - V_15 -> V_12 ;
break;
default:
break;
}
return 0 ;
}
static int F_19 ( struct V_14 * V_15 , T_1 V_28 ,
unsigned char V_29 ,
char * * V_70 , T_1 V_31 )
{
const void * V_71 , * V_12 = ( const void * ) V_15 -> V_12 ;
T_1 V_72 ;
char * V_34 ;
if ( * V_70 )
return - V_56 ;
if ( ! V_15 -> V_62 && ! V_15 -> V_65 && ! V_15 -> V_68 ) {
V_34 = F_20 ( 1 , V_18 ) ;
if ( ! V_34 )
return - V_17 ;
V_34 [ 0 ] = 0 ;
goto V_73;
}
if ( V_15 -> V_62 && V_15 -> V_65 ) {
V_72 = V_15 -> V_62 ;
V_71 = V_12 + V_15 -> V_63 ;
if ( V_15 -> V_62 >= V_15 -> V_65 &&
memcmp ( V_12 + V_15 -> V_63 , V_12 + V_15 -> V_66 ,
V_15 -> V_65 ) == 0 )
goto V_74;
if ( V_15 -> V_62 >= 7 &&
V_15 -> V_65 >= 7 &&
memcmp ( V_12 + V_15 -> V_63 , V_12 + V_15 -> V_66 , 7 ) == 0 )
goto V_74;
V_34 = F_20 ( V_15 -> V_65 + 2 + V_15 -> V_62 + 1 ,
V_18 ) ;
if ( ! V_34 )
return - V_17 ;
memcpy ( V_34 ,
V_12 + V_15 -> V_66 , V_15 -> V_65 ) ;
V_34 [ V_15 -> V_65 + 0 ] = ':' ;
V_34 [ V_15 -> V_65 + 1 ] = ' ' ;
memcpy ( V_34 + V_15 -> V_65 + 2 ,
V_12 + V_15 -> V_63 , V_15 -> V_62 ) ;
V_34 [ V_15 -> V_65 + 2 + V_15 -> V_62 ] = 0 ;
goto V_73;
} else if ( V_15 -> V_62 ) {
V_72 = V_15 -> V_62 ;
V_71 = V_12 + V_15 -> V_63 ;
} else if ( V_15 -> V_65 ) {
V_72 = V_15 -> V_65 ;
V_71 = V_12 + V_15 -> V_66 ;
} else {
V_72 = V_15 -> V_68 ;
V_71 = V_12 + V_15 -> V_69 ;
}
V_74:
V_34 = F_20 ( V_72 + 1 , V_18 ) ;
if ( ! V_34 )
return - V_17 ;
memcpy ( V_34 , V_71 , V_72 ) ;
V_34 [ V_72 ] = 0 ;
V_73:
* V_70 = V_34 ;
V_15 -> V_62 = 0 ;
V_15 -> V_65 = 0 ;
V_15 -> V_68 = 0 ;
return 0 ;
}
int F_21 ( void * V_27 , T_1 V_28 ,
unsigned char V_29 ,
const void * V_30 , T_1 V_31 )
{
struct V_14 * V_15 = V_27 ;
V_15 -> V_2 -> V_75 = V_30 ;
V_15 -> V_2 -> V_76 = V_31 ;
return F_19 ( V_15 , V_28 , V_29 , & V_15 -> V_2 -> V_4 , V_31 ) ;
}
int F_22 ( void * V_27 , T_1 V_28 ,
unsigned char V_29 ,
const void * V_30 , T_1 V_31 )
{
struct V_14 * V_15 = V_27 ;
V_15 -> V_2 -> V_77 = V_30 ;
V_15 -> V_2 -> V_78 = V_31 ;
return F_19 ( V_15 , V_28 , V_29 , & V_15 -> V_2 -> V_5 , V_31 ) ;
}
int F_23 ( void * V_27 , T_1 V_28 ,
unsigned char V_29 ,
const void * V_30 , T_1 V_31 )
{
struct V_14 * V_15 = V_27 ;
if ( V_15 -> V_32 != V_79 )
return - V_39 ;
V_15 -> V_2 -> V_3 -> V_43 = V_44 ;
V_15 -> V_25 = V_30 + 1 ;
V_15 -> V_26 = V_31 - 1 ;
return 0 ;
}
int F_24 ( void * V_27 , T_1 V_28 ,
unsigned char V_29 ,
const void * V_30 , T_1 V_31 )
{
struct V_14 * V_15 = V_27 ;
T_2 V_80 ;
if ( V_15 -> V_81 >= F_25 ( V_15 -> V_2 -> V_3 -> V_80 ) ) {
F_26 ( L_6 ) ;
return - V_82 ;
}
V_80 = F_27 ( V_30 , V_31 ) ;
if ( ! V_80 )
return - V_17 ;
V_15 -> V_2 -> V_3 -> V_80 [ V_15 -> V_81 ++ ] = V_80 ;
return 0 ;
}
int F_28 ( void * V_27 , T_1 V_28 ,
unsigned char V_29 ,
const void * V_30 , T_1 V_31 )
{
struct V_14 * V_15 = V_27 ;
const unsigned char * V_83 = V_30 ;
char * V_84 ;
int V_85 ;
F_12 ( L_7 , V_15 -> V_32 ) ;
if ( V_15 -> V_32 == V_86 ) {
if ( V_31 < 3 )
return - V_82 ;
if ( V_83 [ 0 ] != V_87 || V_83 [ 1 ] != V_31 - 2 )
return - V_82 ;
V_83 += 2 ;
V_31 -= 2 ;
V_84 = F_20 ( V_31 * 2 + 1 , V_18 ) ;
if ( ! V_84 )
return - V_17 ;
for ( V_85 = 0 ; V_85 < V_31 ; V_85 ++ )
sprintf ( V_84 + V_85 * 2 , L_8 , V_83 [ V_85 ] ) ;
F_12 ( L_9 , V_84 ) ;
V_15 -> V_2 -> V_6 = V_84 ;
return 0 ;
}
if ( V_15 -> V_32 == V_88 ) {
T_1 V_89 ;
if ( V_31 < 5 )
return - V_82 ;
if ( V_83 [ 0 ] != ( V_90 | ( V_91 << 5 ) ) )
return - V_82 ;
if ( F_29 ( V_31 == V_92 ) )
return - V_82 ;
if ( V_31 < V_92 ) {
if ( V_83 [ 1 ] != V_31 - 2 ||
V_83 [ 2 ] != V_93 ||
V_83 [ 3 ] > V_31 - 4 )
return - V_82 ;
V_89 = V_83 [ 3 ] ;
V_83 += 4 ;
} else {
T_1 V_94 = 0 ;
T_1 V_95 = V_83 [ 1 ] - V_92 ;
if ( V_95 > 2 )
return - V_82 ;
V_83 += 2 ;
for ( V_85 = 0 ; V_85 < V_95 ; V_85 ++ ) {
V_94 <<= 8 ;
V_94 |= V_83 [ V_85 ] ;
}
if ( V_94 != V_31 - 2 - V_95 ||
V_83 [ V_95 ] != V_93 ||
V_83 [ V_95 + 1 ] > V_31 - 4 - V_95 )
return - V_82 ;
V_89 = V_83 [ V_95 + 1 ] ;
V_83 += ( V_95 + 2 ) ;
}
V_84 = F_20 ( V_89 * 2 + 1 , V_18 ) ;
if ( ! V_84 )
return - V_17 ;
for ( V_85 = 0 ; V_85 < V_89 ; V_85 ++ )
sprintf ( V_84 + V_85 * 2 , L_8 , V_83 [ V_85 ] ) ;
F_12 ( L_10 , V_84 ) ;
V_15 -> V_2 -> V_7 = V_84 ;
return 0 ;
}
return 0 ;
}
static int F_30 ( struct V_96 * V_96 , T_1 V_28 ,
unsigned char V_29 ,
const unsigned char * V_30 , T_1 V_31 )
{
const unsigned char * V_97 = V_30 ;
#define F_31 ( T_3 ) ((X) - '0')
#define F_32 ( T_4 ) ({ unsigned x = dec2bin(P[0]) * 10 + dec2bin(P[1]); P += 2; x; })
if ( V_29 == V_98 ) {
if ( V_31 != 13 )
goto V_99;
V_96 -> V_100 = F_32 ( V_97 ) ;
if ( V_96 -> V_100 >= 50 )
V_96 -> V_100 += 1900 ;
else
V_96 -> V_100 += 2000 ;
} else if ( V_29 == V_101 ) {
if ( V_31 != 15 )
goto V_99;
V_96 -> V_100 = F_32 ( V_97 ) * 100 + F_32 ( V_97 ) ;
} else {
goto V_99;
}
V_96 -> V_100 -= 1900 ;
V_96 -> V_102 = F_32 ( V_97 ) - 1 ;
V_96 -> V_103 = F_32 ( V_97 ) ;
V_96 -> V_104 = F_32 ( V_97 ) ;
V_96 -> V_105 = F_32 ( V_97 ) ;
V_96 -> V_106 = F_32 ( V_97 ) ;
if ( * V_97 != 'Z' )
goto V_99;
return 0 ;
V_99:
F_12 ( L_11 ,
V_29 , ( int ) V_31 , ( int ) V_31 , V_30 ) ;
return - V_82 ;
}
int F_33 ( void * V_27 , T_1 V_28 ,
unsigned char V_29 ,
const void * V_30 , T_1 V_31 )
{
struct V_14 * V_15 = V_27 ;
return F_30 ( & V_15 -> V_2 -> V_107 , V_28 , V_29 , V_30 , V_31 ) ;
}
int F_34 ( void * V_27 , T_1 V_28 ,
unsigned char V_29 ,
const void * V_30 , T_1 V_31 )
{
struct V_14 * V_15 = V_27 ;
return F_30 ( & V_15 -> V_2 -> V_108 , V_28 , V_29 , V_30 , V_31 ) ;
}
