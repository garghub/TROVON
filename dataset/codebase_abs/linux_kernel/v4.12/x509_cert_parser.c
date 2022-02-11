void F_1 ( struct V_1 * V_2 )
{
if ( V_2 ) {
F_2 ( V_2 -> V_3 ) ;
F_3 ( V_2 -> V_4 ) ;
F_4 ( V_2 -> V_5 ) ;
F_4 ( V_2 -> V_6 ) ;
F_4 ( V_2 -> V_7 ) ;
F_4 ( V_2 -> V_8 ) ;
F_4 ( V_2 ) ;
}
}
struct V_1 * F_5 ( const void * V_9 , T_1 V_10 )
{
struct V_1 * V_2 ;
struct V_11 * V_12 ;
struct V_13 * V_14 ;
long V_15 ;
V_15 = - V_16 ;
V_2 = F_6 ( sizeof( struct V_1 ) , V_17 ) ;
if ( ! V_2 )
goto V_18;
V_2 -> V_3 = F_6 ( sizeof( struct V_19 ) , V_17 ) ;
if ( ! V_2 -> V_3 )
goto V_20;
V_2 -> V_4 = F_6 ( sizeof( struct V_21 ) , V_17 ) ;
if ( ! V_2 -> V_4 )
goto V_20;
V_12 = F_6 ( sizeof( struct V_11 ) , V_17 ) ;
if ( ! V_12 )
goto V_20;
V_12 -> V_2 = V_2 ;
V_12 -> V_9 = ( unsigned long ) V_9 ;
V_15 = F_7 ( & V_22 , V_12 , V_9 , V_10 ) ;
if ( V_15 < 0 )
goto V_23;
if ( V_12 -> V_24 ) {
F_8 ( L_1 ,
V_12 -> V_25 , V_12 -> V_25 , V_12 -> V_24 ) ;
V_15 = F_7 ( & V_26 , V_12 ,
V_12 -> V_24 , V_12 -> V_25 ) ;
if ( V_15 < 0 ) {
F_9 ( L_2 ) ;
goto V_23;
}
}
V_15 = - V_16 ;
V_2 -> V_3 -> V_27 = F_10 ( V_12 -> V_27 , V_12 -> V_28 , V_17 ) ;
if ( ! V_2 -> V_3 -> V_27 )
goto V_23;
V_2 -> V_3 -> V_29 = V_12 -> V_28 ;
V_15 = F_11 ( V_2 ) ;
if ( V_15 < 0 )
goto V_23;
V_14 = F_12 ( V_2 -> V_30 ,
V_2 -> V_31 ,
V_2 -> V_32 ,
V_2 -> V_33 ) ;
if ( F_13 ( V_14 ) ) {
V_15 = F_14 ( V_14 ) ;
goto V_23;
}
V_2 -> V_7 = V_14 ;
V_15 = F_15 ( V_2 ) ;
if ( V_15 < 0 )
goto V_23;
F_4 ( V_12 ) ;
return V_2 ;
V_23:
F_4 ( V_12 ) ;
V_20:
F_1 ( V_2 ) ;
V_18:
return F_16 ( V_15 ) ;
}
int F_17 ( void * V_34 , T_1 V_35 ,
unsigned char V_36 ,
const void * V_37 , T_1 V_38 )
{
struct V_11 * V_12 = V_34 ;
V_12 -> V_39 = F_18 ( V_37 , V_38 ) ;
if ( V_12 -> V_39 == V_40 ) {
char V_41 [ 50 ] ;
F_19 ( V_37 , V_38 , V_41 , sizeof( V_41 ) ) ;
F_20 ( L_3 ,
( unsigned long ) V_37 - V_12 -> V_9 , V_41 ) ;
}
return 0 ;
}
int F_21 ( void * V_34 , T_1 V_35 ,
unsigned char V_36 ,
const void * V_37 , T_1 V_38 )
{
struct V_11 * V_12 = V_34 ;
F_20 ( L_4 ,
V_35 , V_36 , ( unsigned long ) V_37 - V_12 -> V_9 , V_38 ) ;
V_12 -> V_2 -> V_42 = V_37 - V_35 ;
V_12 -> V_2 -> V_43 = V_38 + V_35 ;
return 0 ;
}
int F_22 ( void * V_34 , T_1 V_35 ,
unsigned char V_36 ,
const void * V_37 , T_1 V_38 )
{
struct V_11 * V_12 = V_34 ;
F_20 ( L_5 , V_12 -> V_39 ) ;
switch ( V_12 -> V_39 ) {
case V_44 :
case V_45 :
default:
return - V_46 ;
case V_47 :
V_12 -> V_2 -> V_4 -> V_48 = L_6 ;
V_12 -> V_2 -> V_4 -> V_49 = L_7 ;
break;
case V_50 :
V_12 -> V_2 -> V_4 -> V_48 = L_8 ;
V_12 -> V_2 -> V_4 -> V_49 = L_7 ;
break;
case V_51 :
V_12 -> V_2 -> V_4 -> V_48 = L_9 ;
V_12 -> V_2 -> V_4 -> V_49 = L_7 ;
break;
case V_52 :
V_12 -> V_2 -> V_4 -> V_48 = L_10 ;
V_12 -> V_2 -> V_4 -> V_49 = L_7 ;
break;
case V_53 :
V_12 -> V_2 -> V_4 -> V_48 = L_11 ;
V_12 -> V_2 -> V_4 -> V_49 = L_7 ;
break;
case V_54 :
V_12 -> V_2 -> V_4 -> V_48 = L_12 ;
V_12 -> V_2 -> V_4 -> V_49 = L_7 ;
break;
}
V_12 -> V_55 = V_12 -> V_39 ;
return 0 ;
}
int F_23 ( void * V_34 , T_1 V_35 ,
unsigned char V_36 ,
const void * V_37 , T_1 V_38 )
{
struct V_11 * V_12 = V_34 ;
F_20 ( L_13 , V_12 -> V_39 , V_38 ) ;
if ( V_12 -> V_39 != V_12 -> V_55 ) {
F_9 ( L_14 ,
V_12 -> V_55 , V_12 -> V_39 ) ;
return - V_56 ;
}
V_12 -> V_2 -> V_57 = V_37 ;
V_12 -> V_2 -> V_58 = V_38 ;
return 0 ;
}
int F_24 ( void * V_34 , T_1 V_35 ,
unsigned char V_36 ,
const void * V_37 , T_1 V_38 )
{
struct V_11 * V_12 = V_34 ;
V_12 -> V_2 -> V_30 = V_37 ;
V_12 -> V_2 -> V_31 = V_38 ;
return 0 ;
}
int F_25 ( void * V_34 , T_1 V_35 ,
unsigned char V_36 ,
const void * V_37 , T_1 V_38 )
{
struct V_11 * V_12 = V_34 ;
switch ( V_12 -> V_39 ) {
case V_59 :
V_12 -> V_60 = V_38 ;
V_12 -> V_61 = ( unsigned long ) V_37 - V_12 -> V_9 ;
break;
case V_62 :
V_12 -> V_63 = V_38 ;
V_12 -> V_64 = ( unsigned long ) V_37 - V_12 -> V_9 ;
break;
case V_65 :
V_12 -> V_66 = V_38 ;
V_12 -> V_67 = ( unsigned long ) V_37 - V_12 -> V_9 ;
break;
default:
break;
}
return 0 ;
}
static int F_26 ( struct V_11 * V_12 , T_1 V_35 ,
unsigned char V_36 ,
char * * V_68 , T_1 V_38 )
{
const void * V_69 , * V_9 = ( const void * ) V_12 -> V_9 ;
T_1 V_70 ;
char * V_41 ;
if ( * V_68 )
return - V_56 ;
if ( ! V_12 -> V_60 && ! V_12 -> V_63 && ! V_12 -> V_66 ) {
V_41 = F_27 ( 1 , V_17 ) ;
if ( ! V_41 )
return - V_16 ;
V_41 [ 0 ] = 0 ;
goto V_71;
}
if ( V_12 -> V_60 && V_12 -> V_63 ) {
V_70 = V_12 -> V_60 ;
V_69 = V_9 + V_12 -> V_61 ;
if ( V_12 -> V_60 >= V_12 -> V_63 &&
memcmp ( V_9 + V_12 -> V_61 , V_9 + V_12 -> V_64 ,
V_12 -> V_63 ) == 0 )
goto V_72;
if ( V_12 -> V_60 >= 7 &&
V_12 -> V_63 >= 7 &&
memcmp ( V_9 + V_12 -> V_61 , V_9 + V_12 -> V_64 , 7 ) == 0 )
goto V_72;
V_41 = F_27 ( V_12 -> V_63 + 2 + V_12 -> V_60 + 1 ,
V_17 ) ;
if ( ! V_41 )
return - V_16 ;
memcpy ( V_41 ,
V_9 + V_12 -> V_64 , V_12 -> V_63 ) ;
V_41 [ V_12 -> V_63 + 0 ] = ':' ;
V_41 [ V_12 -> V_63 + 1 ] = ' ' ;
memcpy ( V_41 + V_12 -> V_63 + 2 ,
V_9 + V_12 -> V_61 , V_12 -> V_60 ) ;
V_41 [ V_12 -> V_63 + 2 + V_12 -> V_60 ] = 0 ;
goto V_71;
} else if ( V_12 -> V_60 ) {
V_70 = V_12 -> V_60 ;
V_69 = V_9 + V_12 -> V_61 ;
} else if ( V_12 -> V_63 ) {
V_70 = V_12 -> V_63 ;
V_69 = V_9 + V_12 -> V_64 ;
} else {
V_70 = V_12 -> V_66 ;
V_69 = V_9 + V_12 -> V_67 ;
}
V_72:
V_41 = F_27 ( V_70 + 1 , V_17 ) ;
if ( ! V_41 )
return - V_16 ;
memcpy ( V_41 , V_69 , V_70 ) ;
V_41 [ V_70 ] = 0 ;
V_71:
* V_68 = V_41 ;
V_12 -> V_60 = 0 ;
V_12 -> V_63 = 0 ;
V_12 -> V_66 = 0 ;
return 0 ;
}
int F_28 ( void * V_34 , T_1 V_35 ,
unsigned char V_36 ,
const void * V_37 , T_1 V_38 )
{
struct V_11 * V_12 = V_34 ;
V_12 -> V_2 -> V_32 = V_37 ;
V_12 -> V_2 -> V_33 = V_38 ;
return F_26 ( V_12 , V_35 , V_36 , & V_12 -> V_2 -> V_5 , V_38 ) ;
}
int F_29 ( void * V_34 , T_1 V_35 ,
unsigned char V_36 ,
const void * V_37 , T_1 V_38 )
{
struct V_11 * V_12 = V_34 ;
V_12 -> V_2 -> V_73 = V_37 ;
V_12 -> V_2 -> V_74 = V_38 ;
return F_26 ( V_12 , V_35 , V_36 , & V_12 -> V_2 -> V_6 , V_38 ) ;
}
int F_30 ( void * V_34 , T_1 V_35 ,
unsigned char V_36 ,
const void * V_37 , T_1 V_38 )
{
struct V_11 * V_12 = V_34 ;
if ( V_12 -> V_39 != V_75 )
return - V_46 ;
V_12 -> V_2 -> V_3 -> V_49 = L_7 ;
V_12 -> V_27 = V_37 + 1 ;
V_12 -> V_28 = V_38 - 1 ;
return 0 ;
}
int F_31 ( void * V_34 , T_1 V_35 ,
unsigned char V_36 ,
const void * V_37 , T_1 V_38 )
{
struct V_11 * V_12 = V_34 ;
struct V_13 * V_14 ;
const unsigned char * V_76 = V_37 ;
F_20 ( L_15 , V_12 -> V_39 ) ;
if ( V_12 -> V_39 == V_77 ) {
if ( V_12 -> V_2 -> V_8 || V_38 < 3 )
return - V_78 ;
if ( V_76 [ 0 ] != V_79 || V_76 [ 1 ] != V_38 - 2 )
return - V_78 ;
V_76 += 2 ;
V_38 -= 2 ;
V_12 -> V_2 -> V_80 = V_38 ;
V_12 -> V_2 -> V_81 = V_76 ;
V_14 = F_12 ( V_76 , V_38 , L_16 , 0 ) ;
if ( F_13 ( V_14 ) )
return F_14 ( V_14 ) ;
V_12 -> V_2 -> V_8 = V_14 ;
F_20 ( L_17 , V_14 -> V_82 , V_14 -> V_9 ) ;
return 0 ;
}
if ( V_12 -> V_39 == V_83 ) {
V_12 -> V_24 = V_76 ;
V_12 -> V_25 = V_38 ;
return 0 ;
}
return 0 ;
}
int F_32 ( T_2 * V_84 , T_1 V_35 ,
unsigned char V_36 ,
const unsigned char * V_37 , T_1 V_38 )
{
static const unsigned char V_85 [] = { 31 , 28 , 31 , 30 , 31 , 30 ,
31 , 31 , 30 , 31 , 30 , 31 } ;
const unsigned char * V_86 = V_37 ;
unsigned V_87 , V_88 , V_89 , V_90 , V_91 , V_92 , V_93 ;
#define F_33 ( T_3 ) ({ unsigned char x = (X) - '0'; if (x > 9) goto invalid_time; x; })
#define F_34 ( T_4 ) ({ unsigned x = dec2bin(P[0]) * 10 + dec2bin(P[1]); P += 2; x; })
if ( V_36 == V_94 ) {
if ( V_38 != 13 )
goto V_95;
V_87 = F_34 ( V_86 ) ;
if ( V_87 >= 50 )
V_87 += 1900 ;
else
V_87 += 2000 ;
} else if ( V_36 == V_96 ) {
if ( V_38 != 15 )
goto V_95;
V_87 = F_34 ( V_86 ) * 100 + F_34 ( V_86 ) ;
if ( V_87 >= 1950 && V_87 <= 2049 )
goto V_97;
} else {
goto V_95;
}
V_88 = F_34 ( V_86 ) ;
V_89 = F_34 ( V_86 ) ;
V_90 = F_34 ( V_86 ) ;
V_91 = F_34 ( V_86 ) ;
V_92 = F_34 ( V_86 ) ;
if ( * V_86 != 'Z' )
goto V_95;
if ( V_87 < 1970 ||
V_88 < 1 || V_88 > 12 )
goto V_97;
V_93 = V_85 [ V_88 - 1 ] ;
if ( V_88 == 2 ) {
if ( V_87 % 4 == 0 ) {
V_93 = 29 ;
if ( V_87 % 100 == 0 ) {
V_93 = 28 ;
if ( V_87 % 400 == 0 )
V_93 = 29 ;
}
}
}
if ( V_89 < 1 || V_89 > V_93 ||
V_90 > 24 ||
V_91 > 59 ||
V_92 > 60 )
goto V_97;
* V_84 = mktime64 ( V_87 , V_88 , V_89 , V_90 , V_91 , V_92 ) ;
return 0 ;
V_95:
F_20 ( L_18 ,
V_36 , ( int ) V_38 , V_37 ) ;
return - V_78 ;
V_97:
F_20 ( L_19 ,
V_36 , ( int ) V_38 , V_37 ) ;
return - V_78 ;
}
int F_35 ( void * V_34 , T_1 V_35 ,
unsigned char V_36 ,
const void * V_37 , T_1 V_38 )
{
struct V_11 * V_12 = V_34 ;
return F_32 ( & V_12 -> V_2 -> V_98 , V_35 , V_36 , V_37 , V_38 ) ;
}
int F_36 ( void * V_34 , T_1 V_35 ,
unsigned char V_36 ,
const void * V_37 , T_1 V_38 )
{
struct V_11 * V_12 = V_34 ;
return F_32 ( & V_12 -> V_2 -> V_99 , V_35 , V_36 , V_37 , V_38 ) ;
}
int F_37 ( void * V_34 , T_1 V_35 ,
unsigned char V_36 ,
const void * V_37 , T_1 V_38 )
{
struct V_11 * V_12 = V_34 ;
struct V_13 * V_14 ;
F_20 ( L_20 , ( int ) V_38 , V_37 ) ;
if ( V_12 -> V_2 -> V_4 -> V_100 [ 1 ] )
return 0 ;
V_14 = F_12 ( V_37 , V_38 , L_16 , 0 ) ;
if ( F_13 ( V_14 ) )
return F_14 ( V_14 ) ;
F_20 ( L_21 , V_14 -> V_82 , V_14 -> V_9 ) ;
V_12 -> V_2 -> V_4 -> V_100 [ 1 ] = V_14 ;
return 0 ;
}
int F_38 ( void * V_34 , T_1 V_35 ,
unsigned char V_36 ,
const void * V_37 , T_1 V_38 )
{
struct V_11 * V_12 = V_34 ;
F_20 ( L_22 , ( int ) V_38 , V_37 ) ;
V_12 -> V_101 = V_37 ;
V_12 -> V_102 = V_38 ;
return 0 ;
}
int F_39 ( void * V_34 , T_1 V_35 ,
unsigned char V_36 ,
const void * V_37 , T_1 V_38 )
{
struct V_11 * V_12 = V_34 ;
struct V_13 * V_14 ;
F_20 ( L_23 , ( int ) V_38 , V_37 ) ;
if ( ! V_12 -> V_101 || V_12 -> V_2 -> V_4 -> V_100 [ 0 ] )
return 0 ;
V_14 = F_12 ( V_37 ,
V_38 ,
V_12 -> V_101 ,
V_12 -> V_102 ) ;
if ( F_13 ( V_14 ) )
return F_14 ( V_14 ) ;
F_20 ( L_21 , V_14 -> V_82 , V_14 -> V_9 ) ;
V_12 -> V_2 -> V_4 -> V_100 [ 0 ] = V_14 ;
return 0 ;
}
