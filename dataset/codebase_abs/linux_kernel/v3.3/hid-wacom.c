static int F_1 ( struct V_1 * V_2 ,
enum V_3 V_4 ,
union V_5 * V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 ,
struct V_7 , V_9 ) ;
int V_10 = V_11 [ V_8 -> V_12 ] ;
int V_13 = 0 ;
switch ( V_4 ) {
case V_14 :
V_6 -> V_15 = 1 ;
break;
case V_16 :
V_6 -> V_15 = V_17 ;
break;
case V_18 :
if ( V_10 == 0 )
V_6 -> V_15 = 100 ;
else
V_6 -> V_15 = V_10 ;
break;
default:
V_13 = - V_19 ;
break;
}
return V_13 ;
}
static int F_3 ( struct V_1 * V_2 ,
enum V_3 V_4 ,
union V_5 * V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 , struct V_7 , V_20 ) ;
int V_10 = V_11 [ V_8 -> V_12 ] ;
int V_13 = 0 ;
switch ( V_4 ) {
case V_14 :
case V_21 :
if ( V_10 == 0 )
V_6 -> V_15 = 1 ;
else
V_6 -> V_15 = 0 ;
break;
case V_16 :
V_6 -> V_15 = V_17 ;
break;
default:
V_13 = - V_19 ;
break;
}
return V_13 ;
}
static void F_4 ( struct V_22 * V_23 )
{
int V_13 ;
T_1 V_24 [ 2 ] ;
V_24 [ 0 ] = 0x03 ;
V_24 [ 1 ] = 0x20 ;
V_13 = V_23 -> V_25 ( V_23 , V_24 , 2 ,
V_26 ) ;
return;
}
static void F_5 ( struct V_22 * V_23 , T_2 V_27 )
{
struct V_7 * V_8 = F_6 ( V_23 ) ;
int V_28 , V_13 ;
char V_24 [ 2 ] ;
V_24 [ 0 ] = 0x03 ; V_24 [ 1 ] = 0x00 ;
V_28 = 3 ;
do {
V_13 = V_23 -> V_25 ( V_23 , V_24 , 2 ,
V_26 ) ;
} while ( V_13 < 0 && V_28 -- > 0 );
if ( V_13 >= 0 ) {
if ( V_27 == 0 )
V_24 [ 0 ] = 0x05 ;
else
V_24 [ 0 ] = 0x06 ;
V_24 [ 1 ] = 0x00 ;
V_28 = 3 ;
do {
V_13 = V_23 -> V_25 ( V_23 , V_24 , 2 ,
V_26 ) ;
} while ( V_13 < 0 && V_28 -- > 0 );
if ( V_13 >= 0 ) {
V_8 -> V_29 = V_27 ;
return;
}
}
F_7 ( V_23 , L_1 ,
V_24 [ 0 ] , V_13 ) ;
return;
}
static T_3 F_8 ( struct V_30 * V_31 ,
struct V_32
* V_33 , char * V_34 )
{
struct V_7 * V_8 = F_9 ( V_31 ) ;
return snprintf ( V_34 , V_35 , L_2 , V_8 -> V_29 ) ;
}
static T_3 F_10 ( struct V_30 * V_31 ,
struct V_32 * V_33 ,
const char * V_34 , T_4 V_36 )
{
struct V_22 * V_23 = F_2 ( V_31 , struct V_22 , V_31 ) ;
int V_37 ;
if ( sscanf ( V_34 , L_3 , & V_37 ) != 1 )
return - V_19 ;
if ( V_37 == 0 || V_37 == 1 ) {
F_5 ( V_23 , V_37 ) ;
return F_11 ( V_34 , V_35 ) ;
} else
return - V_19 ;
}
static int F_12 ( struct V_22 * V_23 ,
struct V_7 * V_8 ,
struct V_38 * V_39 , unsigned char * V_40 )
{
int V_41 , V_42 , V_43 , V_44 ;
V_41 = 0 ;
V_42 = F_13 ( * ( V_45 * ) & V_40 [ 2 ] ) ;
V_43 = F_13 ( * ( V_45 * ) & V_40 [ 4 ] ) ;
if ( V_40 [ 1 ] & 0x90 ) {
switch ( ( V_40 [ 1 ] >> 5 ) & 3 ) {
case 0 :
V_41 = V_46 ;
break;
case 1 :
V_41 = V_47 ;
break;
case 2 :
case 3 :
V_41 = V_48 ;
break;
}
if ( ! ( V_40 [ 1 ] & 0x10 ) )
V_41 = 0 ;
}
if ( V_8 -> V_41 != V_41 ) {
if ( V_8 -> V_41 ) {
if ( V_8 -> V_41 == V_48 ) {
F_14 ( V_39 , V_49 , 0 ) ;
F_14 ( V_39 , V_50 , 0 ) ;
F_14 ( V_39 , V_51 , 0 ) ;
F_15 ( V_39 , V_52 ,
F_16 ( V_39 , V_52 ) ) ;
} else {
F_14 ( V_39 , V_53 , 0 ) ;
F_14 ( V_39 , V_54 , 0 ) ;
F_14 ( V_39 , V_55 , 0 ) ;
F_15 ( V_39 , V_56 , 0 ) ;
}
F_14 ( V_39 , V_8 -> V_41 , 0 ) ;
F_17 ( V_39 ) ;
}
V_8 -> V_41 = V_41 ;
if ( V_41 )
F_14 ( V_39 , V_41 , 1 ) ;
}
if ( V_41 ) {
F_15 ( V_39 , V_57 , V_42 ) ;
F_15 ( V_39 , V_58 , V_43 ) ;
switch ( ( V_40 [ 1 ] >> 5 ) & 3 ) {
case 2 :
F_14 ( V_39 , V_51 , V_40 [ 1 ] & 0x04 ) ;
V_44 = ( V_40 [ 6 ] & 0x01 ) ? - 1 :
( V_40 [ 6 ] & 0x02 ) ? 1 : 0 ;
F_18 ( V_39 , V_59 , V_44 ) ;
case 3 :
F_14 ( V_39 , V_49 , V_40 [ 1 ] & 0x01 ) ;
F_14 ( V_39 , V_50 , V_40 [ 1 ] & 0x02 ) ;
V_44 = 44 - ( V_40 [ 6 ] >> 2 ) ;
if ( V_44 < 0 )
V_44 = 0 ;
else if ( V_44 > 31 )
V_44 = 31 ;
F_15 ( V_39 , V_52 , V_44 ) ;
break;
default:
F_15 ( V_39 , V_56 ,
V_40 [ 6 ] | ( ( ( V_60 ) ( V_40 [ 1 ] & 0x08 ) ) << 5 ) ) ;
F_14 ( V_39 , V_53 , V_40 [ 1 ] & 0x01 ) ;
F_14 ( V_39 , V_54 , V_40 [ 1 ] & 0x02 ) ;
F_14 ( V_39 , V_55 , ( V_41 == V_46 ) && V_40 [ 1 ] & 0x04 ) ;
break;
}
F_17 ( V_39 ) ;
}
V_44 = V_40 [ 7 ] & 0x03 ;
if ( V_44 != V_8 -> V_61 ) {
V_8 -> V_61 = V_44 ;
F_14 ( V_39 , V_62 , V_44 & 0x02 ) ;
F_14 ( V_39 , V_63 , V_44 & 0x01 ) ;
F_14 ( V_39 , V_64 , 0xf0 ) ;
F_19 ( V_39 , V_65 , V_66 , 0xf0 ) ;
F_17 ( V_39 ) ;
}
#ifdef F_20
V_44 = ( V_40 [ 7 ] >> 2 & 0x07 ) ;
if ( V_44 != V_8 -> V_12 )
V_8 -> V_12 = V_44 ;
#endif
return 1 ;
}
static void F_21 ( struct V_7 * V_8 ,
struct V_38 * V_39 , unsigned char * V_40 )
{
V_60 V_42 , V_43 , V_67 ;
T_5 V_68 ;
switch ( V_40 [ 1 ] ) {
case 0x80 :
V_8 -> V_41 = 0 ;
F_14 ( V_39 , V_53 , 0 ) ;
F_15 ( V_39 , V_56 , 0 ) ;
F_14 ( V_39 , V_8 -> V_41 , 0 ) ;
F_17 ( V_39 ) ;
break;
case 0xC2 :
V_68 = ( ( V_40 [ 2 ] << 4 ) | ( V_40 [ 3 ] >> 4 ) |
( ( V_40 [ 7 ] & 0x0f ) << 20 ) |
( ( V_40 [ 8 ] & 0xf0 ) << 12 ) ) & 0xfffff ;
switch ( V_68 ) {
case 0x802 :
V_8 -> V_41 = V_46 ;
break;
case 0x80A :
V_8 -> V_41 = V_47 ;
break;
}
break;
default:
V_42 = V_40 [ 2 ] << 9 | V_40 [ 3 ] << 1 | ( ( V_40 [ 9 ] & 0x02 ) >> 1 ) ;
V_43 = V_40 [ 4 ] << 9 | V_40 [ 5 ] << 1 | ( V_40 [ 9 ] & 0x01 ) ;
V_67 = ( V_40 [ 6 ] << 3 ) | ( ( V_40 [ 7 ] & 0xC0 ) >> 5 )
| ( V_40 [ 1 ] & 0x01 ) ;
F_14 ( V_39 , V_53 , V_67 > 1 ) ;
F_14 ( V_39 , V_54 , V_40 [ 1 ] & 0x02 ) ;
F_14 ( V_39 , V_55 , V_40 [ 1 ] & 0x04 ) ;
F_14 ( V_39 , V_8 -> V_41 , 1 ) ;
F_15 ( V_39 , V_57 , V_42 ) ;
F_15 ( V_39 , V_58 , V_43 ) ;
F_15 ( V_39 , V_56 , V_67 ) ;
F_17 ( V_39 ) ;
break;
}
return;
}
static void F_22 ( struct V_22 * V_23 ,
struct V_7 * V_8 ,
struct V_38 * V_39 , unsigned char * V_40 )
{
switch ( V_40 [ 0 ] ) {
case 0x00 :
break;
case 0x02 :
F_21 ( V_8 , V_39 , V_40 ) ;
break;
case 0x03 :
V_8 -> V_69 = V_40 [ 2 ] ;
break;
case 0x0C :
break;
default:
F_23 ( V_23 , L_4 , V_40 [ 0 ] , V_40 [ 1 ] ) ;
break;
}
}
static int F_24 ( struct V_22 * V_23 , struct V_70 * V_71 ,
T_2 * V_72 , int V_73 )
{
struct V_7 * V_8 = F_6 ( V_23 ) ;
struct V_74 * V_75 ;
struct V_38 * V_39 ;
unsigned char * V_40 = ( unsigned char * ) V_72 ;
int V_76 ;
if ( ! ( V_23 -> V_77 & V_78 ) )
return 0 ;
V_75 = F_25 ( V_23 -> V_79 . V_80 , struct V_74 , V_81 ) ;
V_39 = V_75 -> V_39 ;
if ( V_40 [ 0 ] != 0x03 )
return 0 ;
switch ( V_23 -> V_82 ) {
case V_83 :
return F_12 ( V_23 , V_8 , V_39 , V_40 ) ;
break;
case V_84 :
V_76 = 1 ;
switch ( V_40 [ 0 ] ) {
case 0x04 :
F_22 ( V_23 , V_8 , V_39 , V_40 + V_76 ) ;
V_76 += 10 ;
case 0x03 :
F_22 ( V_23 , V_8 , V_39 , V_40 + V_76 ) ;
V_76 += 10 ;
F_22 ( V_23 , V_8 , V_39 , V_40 + V_76 ) ;
break;
default:
F_23 ( V_23 , L_5 ,
V_40 [ 0 ] , V_40 [ 1 ] , V_73 ) ;
return 0 ;
}
}
return 1 ;
}
static int F_26 ( struct V_22 * V_23 , struct V_74 * V_85 ,
struct V_86 * V_87 , struct V_88 * V_89 , unsigned long * * V_90 ,
int * V_91 )
{
struct V_38 * V_39 = V_85 -> V_39 ;
F_27 ( V_92 , V_39 -> V_93 ) ;
V_39 -> V_94 [ 0 ] |= F_28 ( V_95 ) | F_28 ( V_96 ) | F_28 ( V_97 ) ;
F_27 ( V_59 , V_39 -> V_98 ) ;
F_27 ( V_46 , V_39 -> V_99 ) ;
F_27 ( V_53 , V_39 -> V_99 ) ;
F_27 ( V_54 , V_39 -> V_99 ) ;
F_27 ( V_55 , V_39 -> V_99 ) ;
F_27 ( V_49 , V_39 -> V_99 ) ;
F_27 ( V_50 , V_39 -> V_99 ) ;
F_27 ( V_51 , V_39 -> V_99 ) ;
V_39 -> V_94 [ 0 ] |= F_28 ( V_65 ) ;
F_27 ( V_66 , V_39 -> V_100 ) ;
F_27 ( V_62 , V_39 -> V_99 ) ;
F_27 ( V_63 , V_39 -> V_99 ) ;
F_27 ( V_64 , V_39 -> V_99 ) ;
F_27 ( V_47 , V_39 -> V_99 ) ;
F_27 ( V_48 , V_39 -> V_99 ) ;
switch ( V_23 -> V_82 ) {
case V_83 :
F_29 ( V_39 , V_57 , 0 , 16704 , 4 , 0 ) ;
F_29 ( V_39 , V_58 , 0 , 12064 , 4 , 0 ) ;
F_29 ( V_39 , V_56 , 0 , 511 , 0 , 0 ) ;
F_29 ( V_39 , V_52 , 0 , 32 , 0 , 0 ) ;
break;
case V_84 :
F_29 ( V_39 , V_57 , 0 , 40640 , 4 , 0 ) ;
F_29 ( V_39 , V_58 , 0 , 25400 , 4 , 0 ) ;
F_29 ( V_39 , V_56 , 0 , 2047 , 0 , 0 ) ;
break;
}
return 0 ;
}
static int F_30 ( struct V_22 * V_23 ,
const struct V_101 * V_68 )
{
struct V_7 * V_8 ;
int V_13 ;
V_8 = F_31 ( sizeof( * V_8 ) , V_102 ) ;
if ( V_8 == NULL ) {
F_23 ( V_23 , L_6 ) ;
return - V_103 ;
}
F_32 ( V_23 , V_8 ) ;
V_13 = F_33 ( V_23 ) ;
if ( V_13 ) {
F_23 ( V_23 , L_7 ) ;
goto V_104;
}
V_13 = F_34 ( V_23 , V_105 ) ;
if ( V_13 ) {
F_23 ( V_23 , L_8 ) ;
goto V_104;
}
V_13 = F_35 ( & V_23 -> V_31 , & V_106 ) ;
if ( V_13 )
F_7 ( V_23 ,
L_9 , V_13 ) ;
switch ( V_23 -> V_82 ) {
case V_83 :
F_5 ( V_23 , 1 ) ;
break;
case V_84 :
V_8 -> V_69 = 0 ;
F_4 ( V_23 ) ;
break;
}
#ifdef F_20
V_8 -> V_9 . V_107 = V_108 ;
V_8 -> V_9 . V_109 = F_36 ( V_108 ) ;
V_8 -> V_9 . V_110 = F_1 ;
V_8 -> V_9 . V_111 = L_10 ;
V_8 -> V_9 . type = V_112 ;
V_8 -> V_9 . V_113 = 0 ;
V_13 = F_37 ( & V_23 -> V_31 , & V_8 -> V_9 ) ;
if ( V_13 ) {
F_7 ( V_23 , L_11 ,
V_13 ) ;
goto V_114;
}
F_38 ( & V_8 -> V_9 , & V_23 -> V_31 ) ;
V_8 -> V_20 . V_107 = V_115 ;
V_8 -> V_20 . V_109 = F_36 ( V_115 ) ;
V_8 -> V_20 . V_110 = F_3 ;
V_8 -> V_20 . V_111 = L_12 ;
V_8 -> V_20 . type = V_116 ;
V_8 -> V_20 . V_113 = 0 ;
V_13 = F_37 ( & V_23 -> V_31 , & V_8 -> V_20 ) ;
if ( V_13 ) {
F_7 ( V_23 ,
L_13 , V_13 ) ;
goto V_117;
}
F_38 ( & V_8 -> V_20 , & V_23 -> V_31 ) ;
#endif
return 0 ;
#ifdef F_20
V_117:
F_39 ( & V_8 -> V_9 ) ;
V_114:
F_40 ( & V_23 -> V_31 , & V_106 ) ;
F_41 ( V_23 ) ;
#endif
V_104:
F_42 ( V_8 ) ;
return V_13 ;
}
static void F_43 ( struct V_22 * V_23 )
{
#ifdef F_20
struct V_7 * V_8 = F_6 ( V_23 ) ;
#endif
F_40 ( & V_23 -> V_31 , & V_106 ) ;
F_41 ( V_23 ) ;
#ifdef F_20
F_39 ( & V_8 -> V_9 ) ;
F_39 ( & V_8 -> V_20 ) ;
#endif
F_42 ( F_6 ( V_23 ) ) ;
}
static int T_6 F_44 ( void )
{
int V_13 ;
V_13 = F_45 ( & V_118 ) ;
if ( V_13 )
F_46 ( L_14 ) ;
return V_13 ;
}
static void T_7 F_47 ( void )
{
F_48 ( & V_118 ) ;
}
