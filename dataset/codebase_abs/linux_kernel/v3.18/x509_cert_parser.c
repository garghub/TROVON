void F_1 ( struct V_1 * V_2 )
{
if ( V_2 ) {
F_2 ( V_2 -> V_3 ) ;
F_3 ( V_2 -> V_4 ) ;
F_3 ( V_2 -> V_5 ) ;
F_3 ( V_2 -> V_6 ) ;
F_3 ( V_2 -> V_7 ) ;
F_3 ( V_2 -> V_8 ) ;
F_3 ( V_2 -> V_9 . V_10 ) ;
F_4 ( V_2 -> V_9 . V_11 . V_12 ) ;
F_3 ( V_2 ) ;
}
}
struct V_1 * F_5 ( const void * V_13 , T_1 V_14 )
{
struct V_1 * V_2 ;
struct V_15 * V_16 ;
struct V_17 * V_18 ;
long V_19 ;
V_19 = - V_20 ;
V_2 = F_6 ( sizeof( struct V_1 ) , V_21 ) ;
if ( ! V_2 )
goto V_22;
V_2 -> V_3 = F_6 ( sizeof( struct V_23 ) , V_21 ) ;
if ( ! V_2 -> V_3 )
goto V_24;
V_16 = F_6 ( sizeof( struct V_15 ) , V_21 ) ;
if ( ! V_16 )
goto V_24;
V_16 -> V_2 = V_2 ;
V_16 -> V_13 = ( unsigned long ) V_13 ;
V_19 = F_7 ( & V_25 , V_16 , V_13 , V_14 ) ;
if ( V_19 < 0 )
goto V_26;
V_19 = F_7 ( & V_27 , V_16 ,
V_16 -> V_28 , V_16 -> V_29 ) ;
if ( V_19 < 0 )
goto V_26;
V_18 = F_8 ( V_2 -> V_30 ,
V_2 -> V_31 ,
V_2 -> V_32 ,
V_2 -> V_33 ) ;
if ( F_9 ( V_18 ) ) {
V_19 = F_10 ( V_18 ) ;
goto V_26;
}
V_2 -> V_6 = V_18 ;
F_3 ( V_16 ) ;
return V_2 ;
V_26:
F_3 ( V_16 ) ;
V_24:
F_1 ( V_2 ) ;
V_22:
return F_11 ( V_19 ) ;
}
int F_12 ( void * V_34 , T_1 V_35 ,
unsigned char V_36 ,
const void * V_37 , T_1 V_38 )
{
struct V_15 * V_16 = V_34 ;
V_16 -> V_39 = F_13 ( V_37 , V_38 ) ;
if ( V_16 -> V_39 == V_40 ) {
char V_41 [ 50 ] ;
F_14 ( V_37 , V_38 , V_41 , sizeof( V_41 ) ) ;
F_15 ( L_1 ,
( unsigned long ) V_37 - V_16 -> V_13 , V_41 ) ;
}
return 0 ;
}
int F_16 ( void * V_34 , T_1 V_35 ,
unsigned char V_36 ,
const void * V_37 , T_1 V_38 )
{
struct V_15 * V_16 = V_34 ;
F_15 ( L_2 ,
V_35 , V_36 , ( unsigned long ) V_37 - V_16 -> V_13 , V_38 ) ;
V_16 -> V_2 -> V_42 = V_37 - V_35 ;
V_16 -> V_2 -> V_43 = V_38 + V_35 ;
return 0 ;
}
int F_17 ( void * V_34 , T_1 V_35 ,
unsigned char V_36 ,
const void * V_37 , T_1 V_38 )
{
struct V_15 * V_16 = V_34 ;
F_15 ( L_3 , V_16 -> V_39 ) ;
switch ( V_16 -> V_39 ) {
case V_44 :
case V_45 :
default:
return - V_46 ;
case V_47 :
V_16 -> V_2 -> V_9 . V_48 = V_49 ;
V_16 -> V_2 -> V_9 . V_50 = V_51 ;
break;
case V_52 :
V_16 -> V_2 -> V_9 . V_48 = V_53 ;
V_16 -> V_2 -> V_9 . V_50 = V_51 ;
break;
case V_54 :
V_16 -> V_2 -> V_9 . V_48 = V_55 ;
V_16 -> V_2 -> V_9 . V_50 = V_51 ;
break;
case V_56 :
V_16 -> V_2 -> V_9 . V_48 = V_57 ;
V_16 -> V_2 -> V_9 . V_50 = V_51 ;
break;
case V_58 :
V_16 -> V_2 -> V_9 . V_48 = V_59 ;
V_16 -> V_2 -> V_9 . V_50 = V_51 ;
break;
case V_60 :
V_16 -> V_2 -> V_9 . V_48 = V_61 ;
V_16 -> V_2 -> V_9 . V_50 = V_51 ;
break;
}
V_16 -> V_62 = V_16 -> V_39 ;
return 0 ;
}
int F_18 ( void * V_34 , T_1 V_35 ,
unsigned char V_36 ,
const void * V_37 , T_1 V_38 )
{
struct V_15 * V_16 = V_34 ;
F_15 ( L_4 , V_16 -> V_39 , V_38 ) ;
if ( V_16 -> V_39 != V_16 -> V_62 ) {
F_19 ( L_5 ,
V_16 -> V_62 , V_16 -> V_39 ) ;
return - V_63 ;
}
V_16 -> V_2 -> V_64 = V_37 ;
V_16 -> V_2 -> V_65 = V_38 ;
return 0 ;
}
int F_20 ( void * V_34 , T_1 V_35 ,
unsigned char V_36 ,
const void * V_37 , T_1 V_38 )
{
struct V_15 * V_16 = V_34 ;
V_16 -> V_2 -> V_30 = V_37 ;
V_16 -> V_2 -> V_31 = V_38 ;
return 0 ;
}
int F_21 ( void * V_34 , T_1 V_35 ,
unsigned char V_36 ,
const void * V_37 , T_1 V_38 )
{
struct V_15 * V_16 = V_34 ;
switch ( V_16 -> V_39 ) {
case V_66 :
V_16 -> V_67 = V_38 ;
V_16 -> V_68 = ( unsigned long ) V_37 - V_16 -> V_13 ;
break;
case V_69 :
V_16 -> V_70 = V_38 ;
V_16 -> V_71 = ( unsigned long ) V_37 - V_16 -> V_13 ;
break;
case V_72 :
V_16 -> V_73 = V_38 ;
V_16 -> V_74 = ( unsigned long ) V_37 - V_16 -> V_13 ;
break;
default:
break;
}
return 0 ;
}
static int F_22 ( struct V_15 * V_16 , T_1 V_35 ,
unsigned char V_36 ,
char * * V_75 , T_1 V_38 )
{
const void * V_76 , * V_13 = ( const void * ) V_16 -> V_13 ;
T_1 V_77 ;
char * V_41 ;
if ( * V_75 )
return - V_63 ;
if ( ! V_16 -> V_67 && ! V_16 -> V_70 && ! V_16 -> V_73 ) {
V_41 = F_23 ( 1 , V_21 ) ;
if ( ! V_41 )
return - V_20 ;
V_41 [ 0 ] = 0 ;
goto V_78;
}
if ( V_16 -> V_67 && V_16 -> V_70 ) {
V_77 = V_16 -> V_67 ;
V_76 = V_13 + V_16 -> V_68 ;
if ( V_16 -> V_67 >= V_16 -> V_70 &&
memcmp ( V_13 + V_16 -> V_68 , V_13 + V_16 -> V_71 ,
V_16 -> V_70 ) == 0 )
goto V_79;
if ( V_16 -> V_67 >= 7 &&
V_16 -> V_70 >= 7 &&
memcmp ( V_13 + V_16 -> V_68 , V_13 + V_16 -> V_71 , 7 ) == 0 )
goto V_79;
V_41 = F_23 ( V_16 -> V_70 + 2 + V_16 -> V_67 + 1 ,
V_21 ) ;
if ( ! V_41 )
return - V_20 ;
memcpy ( V_41 ,
V_13 + V_16 -> V_71 , V_16 -> V_70 ) ;
V_41 [ V_16 -> V_70 + 0 ] = ':' ;
V_41 [ V_16 -> V_70 + 1 ] = ' ' ;
memcpy ( V_41 + V_16 -> V_70 + 2 ,
V_13 + V_16 -> V_68 , V_16 -> V_67 ) ;
V_41 [ V_16 -> V_70 + 2 + V_16 -> V_67 ] = 0 ;
goto V_78;
} else if ( V_16 -> V_67 ) {
V_77 = V_16 -> V_67 ;
V_76 = V_13 + V_16 -> V_68 ;
} else if ( V_16 -> V_70 ) {
V_77 = V_16 -> V_70 ;
V_76 = V_13 + V_16 -> V_71 ;
} else {
V_77 = V_16 -> V_73 ;
V_76 = V_13 + V_16 -> V_74 ;
}
V_79:
V_41 = F_23 ( V_77 + 1 , V_21 ) ;
if ( ! V_41 )
return - V_20 ;
memcpy ( V_41 , V_76 , V_77 ) ;
V_41 [ V_77 ] = 0 ;
V_78:
* V_75 = V_41 ;
V_16 -> V_67 = 0 ;
V_16 -> V_70 = 0 ;
V_16 -> V_73 = 0 ;
return 0 ;
}
int F_24 ( void * V_34 , T_1 V_35 ,
unsigned char V_36 ,
const void * V_37 , T_1 V_38 )
{
struct V_15 * V_16 = V_34 ;
V_16 -> V_2 -> V_32 = V_37 ;
V_16 -> V_2 -> V_33 = V_38 ;
return F_22 ( V_16 , V_35 , V_36 , & V_16 -> V_2 -> V_4 , V_38 ) ;
}
int F_25 ( void * V_34 , T_1 V_35 ,
unsigned char V_36 ,
const void * V_37 , T_1 V_38 )
{
struct V_15 * V_16 = V_34 ;
V_16 -> V_2 -> V_80 = V_37 ;
V_16 -> V_2 -> V_81 = V_38 ;
return F_22 ( V_16 , V_35 , V_36 , & V_16 -> V_2 -> V_5 , V_38 ) ;
}
int F_26 ( void * V_34 , T_1 V_35 ,
unsigned char V_36 ,
const void * V_37 , T_1 V_38 )
{
struct V_15 * V_16 = V_34 ;
if ( V_16 -> V_39 != V_82 )
return - V_46 ;
V_16 -> V_2 -> V_3 -> V_50 = V_51 ;
V_16 -> V_28 = V_37 + 1 ;
V_16 -> V_29 = V_38 - 1 ;
return 0 ;
}
int F_27 ( void * V_34 , T_1 V_35 ,
unsigned char V_36 ,
const void * V_37 , T_1 V_38 )
{
struct V_15 * V_16 = V_34 ;
T_2 V_83 ;
if ( V_16 -> V_84 >= F_28 ( V_16 -> V_2 -> V_3 -> V_83 ) ) {
F_29 ( L_6 ) ;
return - V_85 ;
}
V_83 = F_30 ( V_37 , V_38 ) ;
if ( ! V_83 )
return - V_20 ;
V_16 -> V_2 -> V_3 -> V_83 [ V_16 -> V_84 ++ ] = V_83 ;
return 0 ;
}
int F_31 ( void * V_34 , T_1 V_35 ,
unsigned char V_36 ,
const void * V_37 , T_1 V_38 )
{
struct V_15 * V_16 = V_34 ;
struct V_17 * V_18 ;
const unsigned char * V_86 = V_37 ;
int V_87 ;
F_15 ( L_7 , V_16 -> V_39 ) ;
if ( V_16 -> V_39 == V_88 ) {
if ( V_16 -> V_2 -> V_7 || V_38 < 3 )
return - V_85 ;
if ( V_86 [ 0 ] != V_89 || V_86 [ 1 ] != V_38 - 2 )
return - V_85 ;
V_86 += 2 ;
V_38 -= 2 ;
V_16 -> V_2 -> V_90 = V_38 ;
V_16 -> V_2 -> V_91 = V_86 ;
V_18 = F_8 ( V_16 -> V_2 -> V_80 ,
V_16 -> V_2 -> V_81 ,
V_86 , V_38 ) ;
if ( F_9 ( V_18 ) )
return F_10 ( V_18 ) ;
V_16 -> V_2 -> V_7 = V_18 ;
F_15 ( L_8 , V_18 -> V_92 , V_18 -> V_13 ) ;
return 0 ;
}
if ( V_16 -> V_39 == V_93 ) {
if ( V_16 -> V_2 -> V_8 || V_38 < 5 )
return - V_85 ;
if ( V_86 [ 0 ] != ( V_94 | ( V_95 << 5 ) ) )
return - V_85 ;
if ( F_32 ( V_38 == V_96 ) )
return - V_85 ;
if ( V_38 < V_96 ) {
if ( V_86 [ 1 ] != V_38 - 2 ||
V_86 [ 2 ] != V_97 ||
V_86 [ 3 ] > V_38 - 4 )
return - V_85 ;
V_38 = V_86 [ 3 ] ;
V_86 += 4 ;
} else {
T_1 V_98 = 0 ;
T_1 V_99 = V_86 [ 1 ] - V_96 ;
if ( V_99 > 2 )
return - V_85 ;
V_86 += 2 ;
for ( V_87 = 0 ; V_87 < V_99 ; V_87 ++ ) {
V_98 <<= 8 ;
V_98 |= V_86 [ V_87 ] ;
}
if ( V_98 != V_38 - 2 - V_99 ||
V_86 [ V_99 ] != V_97 ||
V_86 [ V_99 + 1 ] > V_38 - 4 - V_99 )
return - V_85 ;
V_38 = V_86 [ V_99 + 1 ] ;
V_86 += ( V_99 + 2 ) ;
}
V_18 = F_8 ( V_16 -> V_2 -> V_32 ,
V_16 -> V_2 -> V_33 ,
V_86 , V_38 ) ;
if ( F_9 ( V_18 ) )
return F_10 ( V_18 ) ;
F_15 ( L_9 , V_18 -> V_92 , V_18 -> V_13 ) ;
V_16 -> V_2 -> V_8 = V_18 ;
return 0 ;
}
return 0 ;
}
static int F_33 ( struct V_100 * V_100 , T_1 V_35 ,
unsigned char V_36 ,
const unsigned char * V_37 , T_1 V_38 )
{
const unsigned char * V_101 = V_37 ;
#define F_34 ( T_3 ) ((X) - '0')
#define F_35 ( T_4 ) ({ unsigned x = dec2bin(P[0]) * 10 + dec2bin(P[1]); P += 2; x; })
if ( V_36 == V_102 ) {
if ( V_38 != 13 )
goto V_103;
V_100 -> V_104 = F_35 ( V_101 ) ;
if ( V_100 -> V_104 >= 50 )
V_100 -> V_104 += 1900 ;
else
V_100 -> V_104 += 2000 ;
} else if ( V_36 == V_105 ) {
if ( V_38 != 15 )
goto V_103;
V_100 -> V_104 = F_35 ( V_101 ) * 100 + F_35 ( V_101 ) ;
} else {
goto V_103;
}
V_100 -> V_104 -= 1900 ;
V_100 -> V_106 = F_35 ( V_101 ) - 1 ;
V_100 -> V_107 = F_35 ( V_101 ) ;
V_100 -> V_108 = F_35 ( V_101 ) ;
V_100 -> V_109 = F_35 ( V_101 ) ;
V_100 -> V_110 = F_35 ( V_101 ) ;
if ( * V_101 != 'Z' )
goto V_103;
return 0 ;
V_103:
F_15 ( L_10 ,
V_36 , ( int ) V_38 , ( int ) V_38 , V_37 ) ;
return - V_85 ;
}
int F_36 ( void * V_34 , T_1 V_35 ,
unsigned char V_36 ,
const void * V_37 , T_1 V_38 )
{
struct V_15 * V_16 = V_34 ;
return F_33 ( & V_16 -> V_2 -> V_111 , V_35 , V_36 , V_37 , V_38 ) ;
}
int F_37 ( void * V_34 , T_1 V_35 ,
unsigned char V_36 ,
const void * V_37 , T_1 V_38 )
{
struct V_15 * V_16 = V_34 ;
return F_33 ( & V_16 -> V_2 -> V_112 , V_35 , V_36 , V_37 , V_38 ) ;
}
