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
if ( V_10 == 0 )
V_6 -> V_15 = 100 ;
else
V_6 -> V_15 = V_10 ;
break;
default:
V_13 = - V_17 ;
break;
}
return V_13 ;
}
static int F_3 ( struct V_1 * V_2 ,
enum V_3 V_4 ,
union V_5 * V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 , struct V_7 , V_18 ) ;
int V_10 = V_11 [ V_8 -> V_12 ] ;
int V_13 = 0 ;
switch ( V_4 ) {
case V_14 :
case V_19 :
if ( V_10 == 0 )
V_6 -> V_15 = 1 ;
else
V_6 -> V_15 = 0 ;
break;
default:
V_13 = - V_17 ;
break;
}
return V_13 ;
}
static void F_4 ( struct V_20 * V_21 , T_1 V_22 )
{
struct V_7 * V_8 = F_5 ( V_21 ) ;
int V_23 , V_13 ;
char V_24 [ 2 ] ;
V_24 [ 0 ] = 0x03 ; V_24 [ 1 ] = 0x00 ;
V_23 = 3 ;
do {
V_13 = V_21 -> V_25 ( V_21 , V_24 , 2 ,
V_26 ) ;
} while ( V_13 < 0 && V_23 -- > 0 );
if ( V_13 >= 0 ) {
if ( V_22 == 0 )
V_24 [ 0 ] = 0x05 ;
else
V_24 [ 0 ] = 0x06 ;
V_24 [ 1 ] = 0x00 ;
V_23 = 3 ;
do {
V_13 = V_21 -> V_25 ( V_21 , V_24 , 2 ,
V_26 ) ;
} while ( V_13 < 0 && V_23 -- > 0 );
if ( V_13 >= 0 ) {
V_8 -> V_27 = V_22 ;
return;
}
}
F_6 ( V_21 , L_1 ,
V_24 [ 0 ] , V_13 ) ;
return;
}
static T_2 F_7 ( struct V_28 * V_29 ,
struct V_30
* V_31 , char * V_32 )
{
struct V_7 * V_8 = F_8 ( V_29 ) ;
return snprintf ( V_32 , V_33 , L_2 , V_8 -> V_27 ) ;
}
static T_2 F_9 ( struct V_28 * V_29 ,
struct V_30 * V_31 ,
const char * V_32 , T_3 V_34 )
{
struct V_20 * V_21 = F_2 ( V_29 , struct V_20 , V_29 ) ;
int V_35 ;
if ( sscanf ( V_32 , L_3 , & V_35 ) != 1 )
return - V_17 ;
if ( V_35 == 0 || V_35 == 1 ) {
F_4 ( V_21 , V_35 ) ;
return F_10 ( V_32 , V_33 ) ;
} else
return - V_17 ;
}
static int F_11 ( struct V_20 * V_21 , struct V_36 * V_37 ,
T_1 * V_38 , int V_39 )
{
struct V_7 * V_8 = F_5 ( V_21 ) ;
struct V_40 * V_41 ;
struct V_42 * V_43 ;
unsigned char * V_44 = ( unsigned char * ) V_38 ;
int V_45 , V_46 , V_47 , V_48 ;
if ( ! ( V_21 -> V_49 & V_50 ) )
return 0 ;
V_45 = 0 ;
V_41 = F_12 ( V_21 -> V_51 . V_52 , struct V_40 , V_53 ) ;
V_43 = V_41 -> V_43 ;
if ( V_44 [ 0 ] != 0x03 )
return 0 ;
V_46 = F_13 ( * ( V_54 * ) & V_44 [ 2 ] ) ;
V_47 = F_13 ( * ( V_54 * ) & V_44 [ 4 ] ) ;
if ( V_44 [ 1 ] & 0x90 ) {
switch ( ( V_44 [ 1 ] >> 5 ) & 3 ) {
case 0 :
V_45 = V_55 ;
break;
case 1 :
V_45 = V_56 ;
break;
case 2 :
case 3 :
V_45 = V_57 ;
break;
}
if ( ! ( V_44 [ 1 ] & 0x10 ) )
V_45 = 0 ;
}
if ( V_8 -> V_45 != V_45 ) {
if ( V_8 -> V_45 ) {
if ( V_8 -> V_45 == V_57 ) {
F_14 ( V_43 , V_58 , 0 ) ;
F_14 ( V_43 , V_59 , 0 ) ;
F_14 ( V_43 , V_60 , 0 ) ;
F_15 ( V_43 , V_61 ,
F_16 ( V_43 , V_61 ) ) ;
} else {
F_14 ( V_43 , V_62 , 0 ) ;
F_14 ( V_43 , V_63 , 0 ) ;
F_14 ( V_43 , V_64 , 0 ) ;
F_15 ( V_43 , V_65 , 0 ) ;
}
F_14 ( V_43 , V_8 -> V_45 , 0 ) ;
F_17 ( V_43 ) ;
}
V_8 -> V_45 = V_45 ;
if ( V_45 )
F_14 ( V_43 , V_45 , 1 ) ;
}
if ( V_45 ) {
F_15 ( V_43 , V_66 , V_46 ) ;
F_15 ( V_43 , V_67 , V_47 ) ;
switch ( ( V_44 [ 1 ] >> 5 ) & 3 ) {
case 2 :
F_14 ( V_43 , V_60 , V_44 [ 1 ] & 0x04 ) ;
V_48 = ( V_44 [ 6 ] & 0x01 ) ? - 1 :
( V_44 [ 6 ] & 0x02 ) ? 1 : 0 ;
F_18 ( V_43 , V_68 , V_48 ) ;
case 3 :
F_14 ( V_43 , V_58 , V_44 [ 1 ] & 0x01 ) ;
F_14 ( V_43 , V_59 , V_44 [ 1 ] & 0x02 ) ;
V_48 = 44 - ( V_44 [ 6 ] >> 2 ) ;
if ( V_48 < 0 )
V_48 = 0 ;
else if ( V_48 > 31 )
V_48 = 31 ;
F_15 ( V_43 , V_61 , V_48 ) ;
break;
default:
F_15 ( V_43 , V_65 ,
V_44 [ 6 ] | ( ( ( V_69 ) ( V_44 [ 1 ] & 0x08 ) ) << 5 ) ) ;
F_14 ( V_43 , V_62 , V_44 [ 1 ] & 0x01 ) ;
F_14 ( V_43 , V_63 , V_44 [ 1 ] & 0x02 ) ;
F_14 ( V_43 , V_64 , ( V_45 == V_55 ) && V_44 [ 1 ] & 0x04 ) ;
break;
}
F_17 ( V_43 ) ;
}
V_48 = V_44 [ 7 ] & 0x03 ;
if ( V_48 != V_8 -> V_70 ) {
V_8 -> V_70 = V_48 ;
F_14 ( V_43 , V_71 , V_48 & 0x02 ) ;
F_14 ( V_43 , V_72 , V_48 & 0x01 ) ;
F_14 ( V_43 , V_73 , 0xf0 ) ;
F_19 ( V_43 , V_74 , V_75 , 0xf0 ) ;
F_17 ( V_43 ) ;
}
#ifdef F_20
V_48 = ( V_44 [ 7 ] >> 2 & 0x07 ) ;
if ( V_48 != V_8 -> V_12 )
V_8 -> V_12 = V_48 ;
#endif
return 1 ;
}
static int F_21 ( struct V_20 * V_21 , struct V_40 * V_76 ,
struct V_77 * V_78 , struct V_79 * V_80 , unsigned long * * V_81 ,
int * V_82 )
{
struct V_42 * V_43 = V_76 -> V_43 ;
F_22 ( V_83 , V_43 -> V_84 ) ;
V_43 -> V_85 [ 0 ] |= F_23 ( V_86 ) | F_23 ( V_87 ) | F_23 ( V_88 ) ;
F_22 ( V_68 , V_43 -> V_89 ) ;
F_22 ( V_55 , V_43 -> V_90 ) ;
F_22 ( V_62 , V_43 -> V_90 ) ;
F_22 ( V_63 , V_43 -> V_90 ) ;
F_22 ( V_64 , V_43 -> V_90 ) ;
F_22 ( V_58 , V_43 -> V_90 ) ;
F_22 ( V_59 , V_43 -> V_90 ) ;
F_22 ( V_60 , V_43 -> V_90 ) ;
V_43 -> V_85 [ 0 ] |= F_23 ( V_74 ) ;
F_22 ( V_75 , V_43 -> V_91 ) ;
F_22 ( V_71 , V_43 -> V_90 ) ;
F_22 ( V_72 , V_43 -> V_90 ) ;
F_22 ( V_73 , V_43 -> V_90 ) ;
F_22 ( V_56 , V_43 -> V_90 ) ;
F_22 ( V_57 , V_43 -> V_90 ) ;
F_24 ( V_43 , V_66 , 0 , 16704 , 4 , 0 ) ;
F_24 ( V_43 , V_67 , 0 , 12064 , 4 , 0 ) ;
F_24 ( V_43 , V_65 , 0 , 511 , 0 , 0 ) ;
F_24 ( V_43 , V_61 , 0 , 32 , 0 , 0 ) ;
return 0 ;
}
static int F_25 ( struct V_20 * V_21 ,
const struct V_92 * V_93 )
{
struct V_7 * V_8 ;
int V_13 ;
V_8 = F_26 ( sizeof( * V_8 ) , V_94 ) ;
if ( V_8 == NULL ) {
F_27 ( V_21 , L_4 ) ;
return - V_95 ;
}
F_28 ( V_21 , V_8 ) ;
V_13 = F_29 ( V_21 ) ;
if ( V_13 ) {
F_27 ( V_21 , L_5 ) ;
goto V_96;
}
V_13 = F_30 ( V_21 , V_97 ) ;
if ( V_13 ) {
F_27 ( V_21 , L_6 ) ;
goto V_96;
}
V_13 = F_31 ( & V_21 -> V_29 , & V_98 ) ;
if ( V_13 )
F_6 ( V_21 ,
L_7 , V_13 ) ;
F_4 ( V_21 , 1 ) ;
#ifdef F_20
V_8 -> V_9 . V_99 = V_100 ;
V_8 -> V_9 . V_101 = F_32 ( V_100 ) ;
V_8 -> V_9 . V_102 = F_1 ;
V_8 -> V_9 . V_103 = L_8 ;
V_8 -> V_9 . type = V_104 ;
V_8 -> V_9 . V_105 = 0 ;
V_13 = F_33 ( & V_21 -> V_29 , & V_8 -> V_9 ) ;
if ( V_13 ) {
F_6 ( V_21 , L_9 ,
V_13 ) ;
goto V_106;
}
V_8 -> V_18 . V_99 = V_107 ;
V_8 -> V_18 . V_101 = F_32 ( V_107 ) ;
V_8 -> V_18 . V_102 = F_3 ;
V_8 -> V_18 . V_103 = L_10 ;
V_8 -> V_18 . type = V_108 ;
V_8 -> V_18 . V_105 = 0 ;
V_13 = F_33 ( & V_21 -> V_29 , & V_8 -> V_18 ) ;
if ( V_13 ) {
F_6 ( V_21 ,
L_11 , V_13 ) ;
goto V_109;
}
#endif
return 0 ;
#ifdef F_20
V_109:
F_34 ( & V_8 -> V_9 ) ;
V_106:
F_35 ( & V_21 -> V_29 , & V_98 ) ;
F_36 ( V_21 ) ;
#endif
V_96:
F_37 ( V_8 ) ;
return V_13 ;
}
static void F_38 ( struct V_20 * V_21 )
{
#ifdef F_20
struct V_7 * V_8 = F_5 ( V_21 ) ;
#endif
F_35 ( & V_21 -> V_29 , & V_98 ) ;
F_36 ( V_21 ) ;
#ifdef F_20
F_34 ( & V_8 -> V_9 ) ;
F_34 ( & V_8 -> V_18 ) ;
#endif
F_37 ( F_5 ( V_21 ) ) ;
}
static int T_4 F_39 ( void )
{
int V_13 ;
V_13 = F_40 ( & V_110 ) ;
if ( V_13 )
F_41 ( L_12 ) ;
return V_13 ;
}
static void T_5 F_42 ( void )
{
F_43 ( & V_110 ) ;
}
