static unsigned char F_1 ( unsigned char V_1 )
{
switch ( V_1 ) {
case 10 : case 20 : case 40 : case 60 : case 80 : case 100 : case 200 :
return ( V_1 >> 4 ) | ( V_1 << 4 ) ;
default:
return V_1 ;
}
}
static unsigned char F_2 ( unsigned char V_1 )
{
switch ( V_1 ) {
case 0xe9 : case 0xee : case 0xf2 : case 0xff :
return ~ V_1 ;
default:
return V_1 ;
}
}
static int F_3 ( struct V_2 * V_2 , int V_3 , int * V_1 )
{
struct V_4 * V_4 = & V_2 -> V_4 ;
unsigned char V_5 [ 3 ] ;
unsigned char V_6 ;
int V_7 = - 1 ;
F_4 ( V_4 , NULL , V_8 ) ;
F_5 ( V_2 , V_9 ) ;
F_6 ( V_4 ) ;
if ( F_7 ( V_4 , 0xf3 , V_10 ) < 0 )
goto V_11;
F_7 ( V_4 , 0x66 , V_12 ) ;
F_7 ( V_4 , 0x88 , V_12 ) ;
if ( F_7 ( V_4 , 0xf3 , V_10 ) < 0 )
goto V_11;
if ( ( V_6 = F_2 ( V_3 ) ) != V_3 ) {
F_7 ( V_4 , 0x68 , V_12 ) ;
} else if ( ( V_6 = F_1 ( V_3 ) ) != V_3 ) {
F_7 ( V_4 , 0xcc , V_12 ) ;
} else {
F_7 ( V_4 , 0x66 , V_12 ) ;
}
F_7 ( V_4 , V_6 , V_10 ) ;
if ( F_8 ( V_4 , V_5 , V_13 ) < 0 )
goto V_11;
* V_1 = V_5 [ 2 ] ;
V_7 = 0 ;
V_11:
F_9 ( V_4 ) ;
F_4 ( V_4 , NULL , V_14 ) ;
F_5 ( V_2 , V_15 ) ;
F_10 ( & V_4 -> V_16 -> V_17 , L_1 ,
V_3 , * V_1 , V_7 ) ;
return V_7 ;
}
static int F_11 ( struct V_2 * V_2 , int V_3 , int V_1 )
{
struct V_4 * V_4 = & V_2 -> V_4 ;
unsigned char V_18 ;
int V_7 = - 1 ;
F_6 ( V_4 ) ;
if ( F_7 ( V_4 , 0xf3 , V_10 ) < 0 )
goto V_11;
if ( ( V_18 = F_2 ( V_3 ) ) != V_3 ) {
F_7 ( V_4 , 0x74 , V_12 ) ;
} else {
if ( ( V_18 = F_1 ( V_3 ) ) != V_3 ) {
F_7 ( V_4 , 0x77 , V_12 ) ;
} else {
F_7 ( V_4 , 0x55 , V_12 ) ;
}
}
F_7 ( V_4 , V_18 , V_12 ) ;
if ( F_7 ( V_4 , 0xf3 , V_10 ) < 0 )
goto V_11;
if ( ( V_18 = F_2 ( V_1 ) ) != V_1 ) {
F_7 ( V_4 , 0x47 , V_12 ) ;
} else if ( ( V_18 = F_1 ( V_1 ) ) != V_1 ) {
F_7 ( V_4 , 0x44 , V_12 ) ;
} else {
F_7 ( V_4 , 0x33 , V_12 ) ;
}
F_7 ( V_4 , V_18 , V_12 ) ;
V_7 = 0 ;
V_11:
F_9 ( V_4 ) ;
F_10 ( & V_4 -> V_16 -> V_17 , L_2 ,
V_3 , V_1 , V_7 ) ;
return V_7 ;
}
static int F_12 ( struct V_2 * V_2 , bool V_19 )
{
int V_18 , V_20 ;
if ( F_3 ( V_2 , V_21 , & V_18 ) == - 1 )
return - 1 ;
if ( V_19 )
V_20 = V_18 | V_22 ;
else
V_20 = V_18 & ~ V_22 ;
if ( V_20 != V_18 )
if ( F_11 ( V_2 , V_21 , V_20 ) == - 1 )
return - 1 ;
return 0 ;
}
static int F_13 ( struct V_2 * V_2 , int * V_1 )
{
struct V_4 * V_4 = & V_2 -> V_4 ;
unsigned char V_5 [ 3 ] ;
int V_7 = - 1 ;
F_4 ( V_4 , NULL , V_8 ) ;
F_5 ( V_2 , V_9 ) ;
F_6 ( V_4 ) ;
if ( F_7 ( V_4 , 0xf3 , V_10 ) < 0 )
goto V_11;
F_7 ( V_4 , 0x66 , V_12 ) ;
F_7 ( V_4 , 0x88 , V_12 ) ;
if ( F_7 ( V_4 , 0xf3 , V_10 ) < 0 )
goto V_11;
F_7 ( V_4 , 0x83 , V_12 ) ;
F_7 ( V_4 , 0x88 , V_12 ) ;
if ( F_8 ( V_4 , V_5 , V_13 ) )
goto V_11;
* V_1 = V_5 [ 2 ] ;
V_7 = 0 ;
V_11:
F_9 ( V_4 ) ;
F_4 ( V_4 , NULL , V_14 ) ;
F_5 ( V_2 , V_15 ) ;
F_10 ( & V_4 -> V_16 -> V_17 , L_3 ,
* V_1 , V_7 ) ;
return V_7 ;
}
static int F_14 ( struct V_2 * V_2 , int V_1 )
{
struct V_4 * V_4 = & V_2 -> V_4 ;
unsigned char V_18 ;
int V_7 = - 1 ;
F_6 ( V_4 ) ;
if ( F_7 ( V_4 , 0xf3 , V_10 ) < 0 )
goto V_11;
F_7 ( V_4 , 0x38 , V_12 ) ;
F_7 ( V_4 , 0x88 , V_12 ) ;
if ( F_7 ( V_4 , 0xf3 , V_10 ) < 0 )
goto V_11;
if ( ( V_18 = F_2 ( V_1 ) ) != V_1 ) {
F_7 ( V_4 , 0x47 , V_12 ) ;
} else if ( ( V_18 = F_1 ( V_1 ) ) != V_1 ) {
F_7 ( V_4 , 0x44 , V_12 ) ;
} else {
F_7 ( V_4 , 0x33 , V_12 ) ;
}
F_7 ( V_4 , V_18 , V_12 ) ;
V_7 = 0 ;
V_11:
F_9 ( V_4 ) ;
F_10 ( & V_4 -> V_16 -> V_17 , L_4 ,
V_1 , V_7 ) ;
return V_7 ;
}
static int F_15 ( struct V_2 * V_2 , int * V_23 )
{
if ( F_3 ( V_2 , V_24 , V_23 ) )
return - V_25 ;
return 0 ;
}
static int F_16 ( struct V_2 * V_2 , int * V_26 )
{
if ( F_3 ( V_2 , V_27 , V_26 ) )
return - V_25 ;
return 0 ;
}
static int F_17 ( struct V_2 * V_2 , int * V_28 )
{
static const int V_29 [] = {
0x16 ,
0x06 ,
0x04 ,
0x02 ,
} ;
int V_30 ;
if ( F_3 ( V_2 , V_31 , & V_30 ) == - 1 )
return - V_25 ;
* V_28 = V_29 [ ( V_30 & 0x30 ) >> 4 ] ;
return 0 ;
}
static int F_18 ( struct V_2 * V_2 , bool V_19 )
{
int V_18 , V_20 ;
int V_32 = 0 ;
if ( F_3 ( V_2 , V_33 , & V_18 ) == - 1 ) {
F_19 ( & V_2 -> V_4 . V_16 -> V_17 , L_5 ) ;
return - V_25 ;
}
if ( V_19 )
V_20 = V_18 | V_34 ;
else
V_20 = V_18 & ~ V_34 ;
if ( V_20 != V_18 ) {
F_12 ( V_2 , true ) ;
V_32 = F_11 ( V_2 , V_33 , V_20 ) ;
F_12 ( V_2 , false ) ;
}
if ( V_32 != 0 ) {
F_19 ( & V_2 -> V_4 . V_16 -> V_17 ,
L_6 ) ;
V_32 = - V_25 ;
}
return V_32 ;
}
static int F_20 ( struct V_2 * V_2 , bool V_19 )
{
struct V_35 * V_36 = V_2 -> V_37 ;
int V_30 ;
if ( F_3 ( V_2 , V_38 , & V_30 ) )
return - V_25 ;
V_36 -> V_39 = V_19 ;
if ( V_19 )
V_30 |= ( V_40 | V_41 ) ;
else
V_30 &= ~ V_40 ;
if ( F_11 ( V_2 , V_38 , V_30 ) )
return - V_25 ;
return 0 ;
}
static int F_21 ( struct V_2 * V_2 , bool V_19 )
{
struct V_35 * V_36 = V_2 -> V_37 ;
int V_30 , V_42 ;
if ( F_3 ( V_2 , V_38 , & V_30 ) )
return - V_25 ;
if ( F_3 ( V_2 , V_43 , & V_42 ) )
return - V_25 ;
V_36 -> V_44 = V_19 ;
if ( V_19 ) {
V_30 |= ( V_45 | V_41 ) ;
V_42 |= V_46 ;
} else {
V_30 &= ~ V_45 ;
V_42 &= ~ ( V_46 | V_47 | V_48 ) ;
}
if ( F_11 ( V_2 , V_38 , V_30 ) )
return - V_25 ;
if ( F_11 ( V_2 , V_43 , V_42 ) )
return - V_25 ;
return 0 ;
}
static T_1 F_22 ( struct V_2 * V_2 , void * V_49 ,
const char * V_50 , T_2 V_51 )
{
int V_52 , V_30 ;
char * V_53 ;
T_1 V_54 ;
V_52 = F_23 ( V_50 , & V_53 , 16 ) ;
if ( V_53 == V_50 || * V_53 != ' ' || V_52 > 0xff )
return - V_55 ;
V_54 = F_24 ( V_53 + 1 , 16 , & V_30 ) ;
if ( V_54 )
return V_54 ;
if ( V_30 > 0xff )
return - V_55 ;
if ( F_12 ( V_2 , true ) )
return - V_25 ;
V_54 = F_11 ( V_2 , V_52 , V_30 ) < 0 ? - V_25 : V_51 ;
F_12 ( V_2 , false ) ;
return V_51 ;
}
static T_1 F_25 ( struct V_2 * V_2 ,
void * V_49 , char * V_50 )
{
struct V_35 * V_36 = V_2 -> V_37 ;
return sprintf ( V_50 , L_7 , V_36 -> V_56 , V_36 -> V_57 ) ;
}
static T_1 F_26 ( struct V_2 * V_2 , void * V_49 ,
const char * V_50 , T_2 V_51 )
{
struct V_35 * V_36 = V_2 -> V_37 ;
int V_52 , V_30 , V_58 ;
V_58 = F_24 ( V_50 , 16 , & V_52 ) ;
if ( V_58 )
return V_58 ;
if ( V_52 > 0xff )
return - V_55 ;
if ( F_3 ( V_2 , V_52 , & V_30 ) )
return - V_25 ;
V_36 -> V_56 = V_52 ;
V_36 -> V_57 = V_30 ;
return V_51 ;
}
static T_1 F_27 ( struct V_2 * V_2 ,
void * V_49 , char * V_50 )
{
int V_30 = 0 ;
if ( F_13 ( V_2 , & V_30 ) )
return - V_25 ;
return sprintf ( V_50 , L_8 , V_30 ) ;
}
static T_1 F_28 ( struct V_2 * V_2 , void * V_49 ,
const char * V_50 , T_2 V_51 )
{
int V_30 , V_58 ;
V_58 = F_24 ( V_50 , 16 , & V_30 ) ;
if ( V_58 )
return V_58 ;
if ( V_30 > 0xff )
return - V_55 ;
if ( F_14 ( V_2 , V_30 ) )
return - V_25 ;
return V_51 ;
}
static T_1 F_29 ( struct V_2 * V_2 ,
void * V_49 , char * V_50 )
{
struct V_35 * V_36 = V_2 -> V_37 ;
return sprintf ( V_50 , L_9 , V_36 -> V_39 ) ;
}
static T_1 F_30 ( struct V_2 * V_2 , void * V_49 ,
const char * V_50 , T_2 V_51 )
{
unsigned int V_30 ;
int V_58 ;
V_58 = F_31 ( V_50 , 10 , & V_30 ) ;
if ( V_58 )
return V_58 ;
if ( V_30 > 1 )
return - V_55 ;
F_20 ( V_2 , V_30 ) ;
return V_51 ;
}
static T_1 F_32 ( struct V_2 * V_2 ,
void * V_49 , char * V_50 )
{
struct V_35 * V_36 = V_2 -> V_37 ;
return sprintf ( V_50 , L_9 , V_36 -> V_44 ) ;
}
static T_1 F_33 ( struct V_2 * V_2 , void * V_49 ,
const char * V_50 , T_2 V_51 )
{
unsigned int V_30 ;
int V_58 ;
V_58 = F_31 ( V_50 , 10 , & V_30 ) ;
if ( V_58 )
return V_58 ;
if ( V_30 > 1 )
return - V_55 ;
F_21 ( V_2 , V_30 ) ;
return V_51 ;
}
static T_1 F_34 ( struct V_2 * V_2 ,
void * V_49 , char * V_50 )
{
struct V_35 * V_36 = V_2 -> V_37 ;
return sprintf ( V_50 , L_10 ,
V_36 -> V_59 & V_60 ? 'C' : 'c' ) ;
}
static T_1 F_35 ( struct V_2 * V_2 , void * V_49 ,
const char * V_50 , T_2 V_51 )
{
struct V_35 * V_36 = V_2 -> V_37 ;
T_2 V_61 ;
for ( V_61 = 0 ; V_61 < V_51 ; V_61 ++ ) {
switch ( V_50 [ V_61 ] ) {
case 'C' :
V_36 -> V_59 |= V_60 ;
break;
case 'c' :
V_36 -> V_59 &= ~ V_60 ;
break;
default:
return - V_55 ;
}
}
return V_51 ;
}
static T_1 F_36 ( struct V_2 * V_2 ,
void * V_49 , char * V_50 )
{
return sprintf ( V_50 , L_11 , V_62 ) ;
}
static void F_37 ( unsigned char V_63 [] )
{
static unsigned int V_64 ;
static unsigned int V_65 ;
unsigned int V_66 ;
V_64 ++ ;
V_66 = F_38 ( V_67 ) ;
F_39 ( V_2 ,
L_12 ,
V_66 , V_63 [ 0 ] , V_63 [ 1 ] , V_63 [ 2 ] , V_63 [ 3 ] ) ;
if ( V_66 - V_65 > 1000 ) {
F_39 ( V_2 , L_13 , V_64 ) ;
V_64 = 0 ;
V_65 = V_66 ;
}
}
static void F_37 ( unsigned char V_63 [] )
{
}
static T_3 F_40 ( struct V_2 * V_2 )
{
struct V_68 * V_17 = V_2 -> V_17 ;
struct V_35 * V_69 = V_2 -> V_37 ;
unsigned char * V_63 = V_2 -> V_63 ;
unsigned char V_70 = 0 , V_71 = 0 , V_72 = 0 ;
int V_73 , V_74 ;
if ( V_2 -> V_75 < 4 )
return V_76 ;
switch ( V_2 -> V_63 [ 0 ] >> V_77 ) {
case V_78 :
F_41 ( & V_2 -> V_4 . V_16 -> V_17 ,
L_14 ) ;
break;
case V_79 :
if ( ( V_69 -> V_59 & V_60 ) != V_60 )
V_63 [ 0 ] &= ~ F_42 ( 0 ) ;
case V_80 :
if ( V_63 [ 3 ] != 0 ) {
if ( V_63 [ 3 ] & F_42 ( 0 ) )
V_70 |= 0x01 ;
if ( V_63 [ 3 ] & F_42 ( 1 ) )
V_70 |= 0x0f ;
if ( V_63 [ 3 ] & F_42 ( 2 ) )
V_70 |= F_42 ( 4 ) ;
if ( V_63 [ 3 ] & F_42 ( 3 ) )
V_70 |= F_42 ( 5 ) ;
if ( V_70 != 0 )
V_63 [ 3 ] = V_70 ;
V_72 = ( V_63 [ 3 ] >> 4 ) & 1 ;
V_71 = ( V_63 [ 3 ] >> 5 ) & 1 ;
}
F_43 ( V_17 , V_81 ,
( int ) ( V_63 [ 3 ] & 8 ) - ( int ) ( V_63 [ 3 ] & 7 ) ) ;
F_43 ( V_17 , V_82 , V_71 - V_72 ) ;
F_44 ( V_17 , V_83 , V_71 ) ;
F_44 ( V_17 , V_84 , V_72 ) ;
F_44 ( V_17 , V_85 , V_63 [ 0 ] & 1 ) ;
F_44 ( V_17 , V_86 , ( V_63 [ 0 ] >> 2 ) & 1 ) ;
F_44 ( V_17 , V_87 , ( V_63 [ 0 ] >> 1 ) & 1 ) ;
V_73 = V_63 [ 1 ] ? ( int ) V_63 [ 1 ] - ( int ) ( ( V_63 [ 0 ] << 4 ) & 0x100 ) : 0 ;
V_74 = V_63 [ 2 ] ? ( int ) ( ( V_63 [ 0 ] << 3 ) & 0x100 ) - ( int ) V_63 [ 2 ] : 0 ;
F_43 ( V_17 , V_88 , V_73 ) ;
F_43 ( V_17 , V_89 , V_74 ) ;
break;
}
F_45 ( V_17 ) ;
F_37 ( V_63 ) ;
return V_90 ;
}
static int F_46 ( struct V_2 * V_2 )
{
struct V_35 * V_36 = V_2 -> V_37 ;
struct V_4 * V_4 = & V_2 -> V_4 ;
unsigned char V_5 [ 2 ] ;
int V_30 ;
V_5 [ 0 ] = 200 ;
F_4 ( V_4 , V_5 , V_91 ) ;
V_5 [ 0 ] = 200 ;
F_4 ( V_4 , V_5 , V_91 ) ;
V_5 [ 0 ] = 80 ;
F_4 ( V_4 , V_5 , V_91 ) ;
F_4 ( V_4 , V_5 , V_92 ) ;
if ( V_5 [ 0 ] != 0x04 ) {
F_19 ( & V_2 -> V_4 . V_16 -> V_17 ,
L_15 ) ;
return - V_25 ;
}
if ( F_3 ( V_2 , V_43 , & V_30 ) ) {
F_19 ( & V_2 -> V_4 . V_16 -> V_17 ,
L_16 ) ;
return - V_25 ;
}
V_30 &= ~ ( V_47 | V_48 | V_93 ) ;
V_30 &= ~ V_94 ;
if ( V_36 -> V_29 == 0x06 ) {
V_30 |= V_46 ;
}
if ( F_11 ( V_2 , V_43 , V_30 ) ) {
F_19 ( & V_2 -> V_4 . V_16 -> V_17 ,
L_17 ) ;
return - V_25 ;
}
if ( F_18 ( V_2 , true ) )
F_41 ( & V_2 -> V_4 . V_16 -> V_17 ,
L_18 ) ;
F_20 ( V_2 , true ) ;
F_21 ( V_2 , true ) ;
return 0 ;
}
int F_47 ( struct V_2 * V_2 , bool V_95 )
{
int V_96 ;
if ( F_3 ( V_2 , V_97 , & V_96 ) )
return - V_25 ;
if ( V_96 != 0x01 )
return - V_98 ;
if ( V_95 ) {
V_2 -> V_99 = L_19 ;
V_2 -> V_100 = L_20 ;
}
return 0 ;
}
static void F_48 ( struct V_2 * V_2 )
{
F_18 ( V_2 , false ) ;
F_20 ( V_2 , false ) ;
F_21 ( V_2 , false ) ;
}
static void F_49 ( struct V_2 * V_2 )
{
F_50 ( & V_2 -> V_4 . V_16 -> V_17 . V_101 ,
& V_102 ) ;
F_48 ( V_2 ) ;
F_51 ( V_2 -> V_37 ) ;
}
static int F_52 ( struct V_2 * V_2 )
{
int V_23 ;
if ( F_47 ( V_2 , 0 ) )
return - V_98 ;
if ( F_15 ( V_2 , & V_23 ) )
return - V_98 ;
if ( F_46 ( V_2 ) )
return - V_25 ;
return 0 ;
}
int F_53 ( struct V_2 * V_2 )
{
struct V_35 * V_103 ;
int V_104 , V_26 , V_29 ;
int error ;
if ( F_15 ( V_2 , & V_104 ) ||
F_16 ( V_2 , & V_26 ) ||
F_17 ( V_2 , & V_29 ) ) {
return - V_98 ;
}
F_54 ( V_2 ,
L_21 ,
V_104 >> 4 , V_104 & 0x0F , V_26 , V_62 , V_29 & 7 ) ;
V_2 -> V_37 = V_103 = F_55 ( sizeof( struct V_35 ) , V_105 ) ;
if ( ! V_103 )
return - V_106 ;
V_103 -> V_104 = V_104 ;
V_103 -> V_26 = V_26 ;
V_103 -> V_29 = V_29 ;
V_103 -> V_59 |= V_60 ;
F_56 ( V_86 , V_2 -> V_17 -> V_107 ) ;
F_56 ( V_83 , V_2 -> V_17 -> V_107 ) ;
F_56 ( V_84 , V_2 -> V_17 -> V_107 ) ;
F_56 ( V_81 , V_2 -> V_17 -> V_108 ) ;
F_56 ( V_82 , V_2 -> V_17 -> V_108 ) ;
V_2 -> V_109 = F_40 ;
V_2 -> V_110 = F_49 ;
V_2 -> V_111 = F_52 ;
V_2 -> V_112 = F_48 ;
V_2 -> V_113 = 4 ;
error = F_46 ( V_2 ) ;
if ( error )
goto V_114;
error = F_57 ( & V_2 -> V_4 . V_16 -> V_17 . V_101 ,
& V_102 ) ;
if ( error ) {
F_19 ( & V_2 -> V_4 . V_16 -> V_17 ,
L_22 , error ) ;
goto V_114;
}
return 0 ;
V_114:
F_51 ( V_2 -> V_37 ) ;
V_2 -> V_37 = NULL ;
return error ;
}
