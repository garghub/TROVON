void F_1 ( struct V_1 * V_2 )
{
if ( V_2 ) {
F_2 ( V_2 -> V_3 ) ;
F_3 ( V_2 -> V_4 ) ;
F_3 ( V_2 -> V_5 ) ;
F_3 ( V_2 -> V_6 ) ;
F_3 ( V_2 -> V_7 ) ;
F_3 ( V_2 ) ;
}
}
struct V_1 * F_4 ( const void * V_8 , T_1 V_9 )
{
struct V_1 * V_2 ;
struct V_10 * V_11 ;
long V_12 ;
V_12 = - V_13 ;
V_2 = F_5 ( sizeof( struct V_1 ) , V_14 ) ;
if ( ! V_2 )
goto V_15;
V_2 -> V_3 = F_5 ( sizeof( struct V_16 ) , V_14 ) ;
if ( ! V_2 -> V_3 )
goto V_17;
V_11 = F_5 ( sizeof( struct V_10 ) , V_14 ) ;
if ( ! V_11 )
goto V_17;
V_11 -> V_2 = V_2 ;
V_11 -> V_8 = ( unsigned long ) V_8 ;
V_12 = F_6 ( & V_18 , V_11 , V_8 , V_9 ) ;
if ( V_12 < 0 )
goto V_19;
V_12 = F_6 ( & V_20 , V_11 ,
V_11 -> V_21 , V_11 -> V_22 ) ;
if ( V_12 < 0 )
goto V_19;
F_3 ( V_11 ) ;
return V_2 ;
V_19:
F_3 ( V_11 ) ;
V_17:
F_1 ( V_2 ) ;
V_15:
return F_7 ( V_12 ) ;
}
int F_8 ( void * V_23 , T_1 V_24 ,
unsigned char V_25 ,
const void * V_26 , T_1 V_27 )
{
struct V_10 * V_11 = V_23 ;
V_11 -> V_28 = F_9 ( V_26 , V_27 ) ;
if ( V_11 -> V_28 == V_29 ) {
char V_30 [ 50 ] ;
F_10 ( V_26 , V_27 , V_30 , sizeof( V_30 ) ) ;
F_11 ( L_1 ,
( unsigned long ) V_26 - V_11 -> V_8 , V_30 ) ;
}
return 0 ;
}
int F_12 ( void * V_23 , T_1 V_24 ,
unsigned char V_25 ,
const void * V_26 , T_1 V_27 )
{
struct V_10 * V_11 = V_23 ;
F_11 ( L_2 ,
V_24 , V_25 , ( unsigned long ) V_26 - V_11 -> V_8 , V_27 ) ;
V_11 -> V_2 -> V_31 = V_26 - V_24 ;
V_11 -> V_2 -> V_32 = V_27 + V_24 ;
return 0 ;
}
int F_13 ( void * V_23 , T_1 V_24 ,
unsigned char V_25 ,
const void * V_26 , T_1 V_27 )
{
struct V_10 * V_11 = V_23 ;
F_11 ( L_3 , V_11 -> V_28 ) ;
switch ( V_11 -> V_28 ) {
case V_33 :
case V_34 :
default:
return - V_35 ;
case V_36 :
V_11 -> V_2 -> V_37 = V_38 ;
V_11 -> V_2 -> V_39 = V_40 ;
break;
case V_41 :
V_11 -> V_2 -> V_37 = V_42 ;
V_11 -> V_2 -> V_39 = V_40 ;
break;
case V_43 :
V_11 -> V_2 -> V_37 = V_44 ;
V_11 -> V_2 -> V_39 = V_40 ;
break;
case V_45 :
V_11 -> V_2 -> V_37 = V_46 ;
V_11 -> V_2 -> V_39 = V_40 ;
break;
case V_47 :
V_11 -> V_2 -> V_37 = V_48 ;
V_11 -> V_2 -> V_39 = V_40 ;
break;
case V_49 :
V_11 -> V_2 -> V_37 = V_50 ;
V_11 -> V_2 -> V_39 = V_40 ;
break;
}
V_11 -> V_51 = V_11 -> V_28 ;
return 0 ;
}
int F_14 ( void * V_23 , T_1 V_24 ,
unsigned char V_25 ,
const void * V_26 , T_1 V_27 )
{
struct V_10 * V_11 = V_23 ;
F_11 ( L_4 , V_11 -> V_28 , V_27 ) ;
if ( V_11 -> V_28 != V_11 -> V_51 ) {
F_15 ( L_5 ,
V_11 -> V_51 , V_11 -> V_28 ) ;
return - V_52 ;
}
V_11 -> V_2 -> V_53 = V_26 ;
V_11 -> V_2 -> V_54 = V_27 ;
return 0 ;
}
int F_16 ( void * V_23 , T_1 V_24 ,
unsigned char V_25 ,
const void * V_26 , T_1 V_27 )
{
struct V_10 * V_11 = V_23 ;
switch ( V_11 -> V_28 ) {
case V_55 :
V_11 -> V_56 = V_27 ;
V_11 -> V_57 = ( unsigned long ) V_26 - V_11 -> V_8 ;
break;
case V_58 :
V_11 -> V_59 = V_27 ;
V_11 -> V_60 = ( unsigned long ) V_26 - V_11 -> V_8 ;
break;
case V_61 :
V_11 -> V_62 = V_27 ;
V_11 -> V_63 = ( unsigned long ) V_26 - V_11 -> V_8 ;
break;
default:
break;
}
return 0 ;
}
static int F_17 ( struct V_10 * V_11 , T_1 V_24 ,
unsigned char V_25 ,
char * * V_64 , T_1 V_27 )
{
const void * V_65 , * V_8 = ( const void * ) V_11 -> V_8 ;
T_1 V_66 ;
char * V_30 ;
if ( * V_64 )
return - V_52 ;
if ( ! V_11 -> V_56 && ! V_11 -> V_59 && ! V_11 -> V_62 ) {
V_30 = F_18 ( 1 , V_14 ) ;
if ( ! V_30 )
return - V_13 ;
V_30 [ 0 ] = 0 ;
goto V_67;
}
if ( V_11 -> V_56 && V_11 -> V_59 ) {
V_66 = V_11 -> V_56 ;
V_65 = V_8 + V_11 -> V_57 ;
if ( V_11 -> V_56 >= V_11 -> V_59 &&
memcmp ( V_8 + V_11 -> V_57 , V_8 + V_11 -> V_60 ,
V_11 -> V_59 ) == 0 )
goto V_68;
if ( V_11 -> V_56 >= 7 &&
V_11 -> V_59 >= 7 &&
memcmp ( V_8 + V_11 -> V_57 , V_8 + V_11 -> V_60 , 7 ) == 0 )
goto V_68;
V_30 = F_18 ( V_11 -> V_59 + 2 + V_11 -> V_56 + 1 ,
V_14 ) ;
if ( ! V_30 )
return - V_13 ;
memcpy ( V_30 ,
V_8 + V_11 -> V_60 , V_11 -> V_59 ) ;
V_30 [ V_11 -> V_59 + 0 ] = ':' ;
V_30 [ V_11 -> V_59 + 1 ] = ' ' ;
memcpy ( V_30 + V_11 -> V_59 + 2 ,
V_8 + V_11 -> V_57 , V_11 -> V_56 ) ;
V_30 [ V_11 -> V_59 + 2 + V_11 -> V_56 ] = 0 ;
goto V_67;
} else if ( V_11 -> V_56 ) {
V_66 = V_11 -> V_56 ;
V_65 = V_8 + V_11 -> V_57 ;
} else if ( V_11 -> V_59 ) {
V_66 = V_11 -> V_59 ;
V_65 = V_8 + V_11 -> V_60 ;
} else {
V_66 = V_11 -> V_62 ;
V_65 = V_8 + V_11 -> V_63 ;
}
V_68:
V_30 = F_18 ( V_66 + 1 , V_14 ) ;
if ( ! V_30 )
return - V_13 ;
memcpy ( V_30 , V_65 , V_66 ) ;
V_30 [ V_66 ] = 0 ;
V_67:
* V_64 = V_30 ;
V_11 -> V_56 = 0 ;
V_11 -> V_59 = 0 ;
V_11 -> V_62 = 0 ;
return 0 ;
}
int F_19 ( void * V_23 , T_1 V_24 ,
unsigned char V_25 ,
const void * V_26 , T_1 V_27 )
{
struct V_10 * V_11 = V_23 ;
return F_17 ( V_11 , V_24 , V_25 , & V_11 -> V_2 -> V_4 , V_27 ) ;
}
int F_20 ( void * V_23 , T_1 V_24 ,
unsigned char V_25 ,
const void * V_26 , T_1 V_27 )
{
struct V_10 * V_11 = V_23 ;
return F_17 ( V_11 , V_24 , V_25 , & V_11 -> V_2 -> V_5 , V_27 ) ;
}
int F_21 ( void * V_23 , T_1 V_24 ,
unsigned char V_25 ,
const void * V_26 , T_1 V_27 )
{
struct V_10 * V_11 = V_23 ;
if ( V_11 -> V_28 != V_69 )
return - V_35 ;
V_11 -> V_2 -> V_70 = V_40 ;
V_11 -> V_21 = V_26 + 1 ;
V_11 -> V_22 = V_27 - 1 ;
return 0 ;
}
int F_22 ( void * V_23 , T_1 V_24 ,
unsigned char V_25 ,
const void * V_26 , T_1 V_27 )
{
struct V_10 * V_11 = V_23 ;
T_2 V_71 ;
if ( V_11 -> V_72 >= F_23 ( V_11 -> V_2 -> V_3 -> V_71 ) ) {
F_24 ( L_6 ) ;
return - V_73 ;
}
V_71 = F_25 ( V_26 , V_27 ) ;
if ( ! V_71 )
return - V_13 ;
V_11 -> V_2 -> V_3 -> V_71 [ V_11 -> V_72 ++ ] = V_71 ;
return 0 ;
}
int F_26 ( void * V_23 , T_1 V_24 ,
unsigned char V_25 ,
const void * V_26 , T_1 V_27 )
{
struct V_10 * V_11 = V_23 ;
const unsigned char * V_74 = V_26 ;
char * V_75 ;
int V_76 ;
F_11 ( L_7 , V_11 -> V_28 ) ;
if ( V_11 -> V_28 == V_77 ) {
if ( V_27 < 3 )
return - V_73 ;
if ( V_74 [ 0 ] != V_78 || V_74 [ 1 ] != V_27 - 2 )
return - V_73 ;
V_74 += 2 ;
V_27 -= 2 ;
V_75 = F_18 ( V_27 * 2 + 1 , V_14 ) ;
if ( ! V_75 )
return - V_13 ;
for ( V_76 = 0 ; V_76 < V_27 ; V_76 ++ )
sprintf ( V_75 + V_76 * 2 , L_8 , V_74 [ V_76 ] ) ;
F_11 ( L_9 , V_75 ) ;
V_11 -> V_2 -> V_6 = V_75 ;
return 0 ;
}
if ( V_11 -> V_28 == V_79 ) {
if ( V_27 < 5 )
return - V_73 ;
if ( V_74 [ 0 ] != ( V_80 | ( V_81 << 5 ) ) ||
V_74 [ 1 ] != V_27 - 2 ||
V_74 [ 2 ] != ( V_82 << 6 ) ||
V_74 [ 3 ] != V_27 - 4 )
return - V_73 ;
V_74 += 4 ;
V_27 -= 4 ;
V_75 = F_18 ( V_27 * 2 + 1 , V_14 ) ;
if ( ! V_75 )
return - V_13 ;
for ( V_76 = 0 ; V_76 < V_27 ; V_76 ++ )
sprintf ( V_75 + V_76 * 2 , L_8 , V_74 [ V_76 ] ) ;
F_11 ( L_10 , V_75 ) ;
V_11 -> V_2 -> V_7 = V_75 ;
return 0 ;
}
return 0 ;
}
static int F_27 ( struct V_83 * V_83 , T_1 V_24 ,
unsigned char V_25 ,
const unsigned char * V_26 , T_1 V_27 )
{
const unsigned char * V_84 = V_26 ;
#define F_28 ( T_3 ) ((X) - '0')
#define F_29 ( T_4 ) ({ unsigned x = dec2bin(P[0]) * 10 + dec2bin(P[1]); P += 2; x; })
if ( V_25 == V_85 ) {
if ( V_27 != 13 )
goto V_86;
V_83 -> V_87 = F_29 ( V_84 ) ;
if ( V_83 -> V_87 >= 50 )
V_83 -> V_87 += 1900 ;
else
V_83 -> V_87 += 2000 ;
} else if ( V_25 == V_88 ) {
if ( V_27 != 15 )
goto V_86;
V_83 -> V_87 = F_29 ( V_84 ) * 100 + F_29 ( V_84 ) ;
} else {
goto V_86;
}
V_83 -> V_87 -= 1900 ;
V_83 -> V_89 = F_29 ( V_84 ) - 1 ;
V_83 -> V_90 = F_29 ( V_84 ) ;
V_83 -> V_91 = F_29 ( V_84 ) ;
V_83 -> V_92 = F_29 ( V_84 ) ;
V_83 -> V_93 = F_29 ( V_84 ) ;
if ( * V_84 != 'Z' )
goto V_86;
return 0 ;
V_86:
F_11 ( L_11 ,
V_25 , ( int ) V_27 , ( int ) V_27 , V_26 ) ;
return - V_73 ;
}
int F_30 ( void * V_23 , T_1 V_24 ,
unsigned char V_25 ,
const void * V_26 , T_1 V_27 )
{
struct V_10 * V_11 = V_23 ;
return F_27 ( & V_11 -> V_2 -> V_94 , V_24 , V_25 , V_26 , V_27 ) ;
}
int F_31 ( void * V_23 , T_1 V_24 ,
unsigned char V_25 ,
const void * V_26 , T_1 V_27 )
{
struct V_10 * V_11 = V_23 ;
return F_27 ( & V_11 -> V_2 -> V_95 , V_24 , V_25 , V_26 , V_27 ) ;
}
