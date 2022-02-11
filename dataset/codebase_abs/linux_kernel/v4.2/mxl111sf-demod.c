static int F_1 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 * V_4 )
{
return ( V_2 -> V_5 -> V_6 ) ?
V_2 -> V_5 -> V_6 ( V_2 -> V_7 , V_3 , V_4 ) :
- V_8 ;
}
static int F_2 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_4 )
{
return ( V_2 -> V_5 -> V_9 ) ?
V_2 -> V_5 -> V_9 ( V_2 -> V_7 , V_3 , V_4 ) :
- V_8 ;
}
static
int F_3 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
return ( V_2 -> V_5 -> V_12 ) ?
V_2 -> V_5 -> V_12 ( V_2 -> V_7 , V_11 ) :
- V_8 ;
}
static
int F_4 ( struct V_1 * V_2 ,
enum V_13 * V_14 )
{
T_1 V_15 ;
int V_16 = F_1 ( V_2 , V_17 , & V_15 ) ;
if ( F_5 ( V_16 ) )
goto V_18;
switch ( V_15 & V_19 ) {
case 0 :
* V_14 = V_20 ;
break;
case 1 :
* V_14 = V_21 ;
break;
case 2 :
* V_14 = V_22 ;
break;
case 3 :
* V_14 = V_23 ;
break;
case 4 :
* V_14 = V_24 ;
break;
}
V_18:
return V_16 ;
}
static
int F_6 ( struct V_1 * V_2 ,
enum V_25 * V_26 )
{
T_1 V_15 ;
int V_16 = F_1 ( V_2 , V_27 , & V_15 ) ;
if ( F_5 ( V_16 ) )
goto V_18;
switch ( ( V_15 & V_28 ) >> 4 ) {
case 0 :
* V_26 = V_29 ;
break;
case 1 :
* V_26 = V_30 ;
break;
case 2 :
* V_26 = V_31 ;
break;
}
V_18:
return V_16 ;
}
static
int F_7 ( struct V_1 * V_2 ,
enum V_32 * V_33 )
{
T_1 V_15 ;
int V_16 = F_1 ( V_2 , V_34 , & V_15 ) ;
if ( F_5 ( V_16 ) )
goto V_18;
switch ( ( V_15 & V_35 ) >> 2 ) {
case 0 :
* V_33 = V_36 ;
break;
case 1 :
* V_33 = V_37 ;
break;
case 2 :
* V_33 = V_38 ;
break;
}
V_18:
return V_16 ;
}
static
int F_8 ( struct V_1 * V_2 ,
enum V_39 * V_40 )
{
T_1 V_15 ;
int V_16 = F_1 ( V_2 , V_41 , & V_15 ) ;
if ( F_5 ( V_16 ) )
goto V_18;
switch ( ( V_15 & V_42 ) >> 4 ) {
case 0 :
* V_40 = V_43 ;
break;
case 1 :
* V_40 = V_44 ;
break;
case 2 :
* V_40 = V_45 ;
break;
case 3 :
* V_40 = V_46 ;
break;
}
V_18:
return V_16 ;
}
static
int F_9 ( struct V_1 * V_2 ,
enum V_47 * V_48 )
{
T_1 V_15 ;
int V_16 = F_1 ( V_2 , V_49 , & V_15 ) ;
if ( F_5 ( V_16 ) )
goto V_18;
switch ( ( V_15 & V_50 ) >> 6 ) {
case 0 :
* V_48 = V_51 ;
break;
case 1 :
* V_48 = V_52 ;
break;
case 2 :
* V_48 = V_53 ;
break;
case 3 :
* V_48 = V_54 ;
break;
}
V_18:
return V_16 ;
}
static
int F_10 ( struct V_1 * V_2 ,
int * V_55 )
{
T_1 V_15 = 0 ;
int V_16 = F_1 ( V_2 , V_56 , & V_15 ) ;
if ( F_5 ( V_16 ) )
goto V_18;
* V_55 = ( V_15 & V_57 ) >> 4 ;
V_18:
return V_16 ;
}
static
int F_11 ( struct V_1 * V_2 ,
int * V_58 )
{
T_1 V_15 = 0 ;
int V_16 = F_1 ( V_2 , V_59 , & V_15 ) ;
if ( F_5 ( V_16 ) )
goto V_18;
* V_58 = ( V_15 & V_60 ) >> 3 ;
V_18:
return V_16 ;
}
static
int F_12 ( struct V_1 * V_2 ,
int * V_61 )
{
T_1 V_15 = 0 ;
int V_16 = F_1 ( V_2 , V_62 , & V_15 ) ;
if ( F_5 ( V_16 ) )
goto V_18;
* V_61 = ( V_15 & V_63 ) >> 6 ;
V_18:
return V_16 ;
}
static
int F_13 ( struct V_1 * V_2 ,
int * V_64 )
{
T_1 V_15 = 0 ;
int V_16 = F_1 ( V_2 , V_65 , & V_15 ) ;
if ( F_5 ( V_16 ) )
goto V_18;
* V_64 = ( V_15 & V_66 ) >> 4 ;
V_18:
return V_16 ;
}
static int F_14 ( struct V_1 * V_2 )
{
return F_2 ( V_2 , 0x0e , 0xff ) ;
}
static int F_15 ( struct V_67 * V_68 )
{
struct V_1 * V_2 = V_68 -> V_69 ;
int V_16 = 0 ;
struct V_10 V_70 [] = {
{ 0x00 , 0xff , 0x01 } ,
{ 0x40 , 0xff , 0x05 } ,
{ 0x40 , 0xff , 0x01 } ,
{ 0x41 , 0xff , 0xca } ,
{ 0x41 , 0xff , 0xc0 } ,
{ 0x00 , 0xff , 0x00 } ,
{ 0 , 0 , 0 }
} ;
F_16 ( L_1 ) ;
if ( V_68 -> V_71 . V_72 . V_73 ) {
V_16 = V_68 -> V_71 . V_72 . V_73 ( V_68 ) ;
if ( F_5 ( V_16 ) )
goto V_18;
F_17 ( 50 ) ;
}
V_16 = F_3 ( V_2 , V_70 ) ;
F_5 ( V_16 ) ;
F_17 ( 50 ) ;
V_16 = F_14 ( V_2 ) ;
F_5 ( V_16 ) ;
F_17 ( 100 ) ;
V_18:
return V_16 ;
}
static int F_18 ( struct V_67 * V_68 , T_2 * V_74 )
{
struct V_1 * V_2 = V_68 -> V_69 ;
T_2 V_75 , V_76 ;
T_1 V_15 ;
int V_16 ;
* V_74 = 0 ;
V_16 = F_1 ( V_2 , V_77 , & V_15 ) ;
if ( F_5 ( V_16 ) )
goto V_18;
V_75 = V_15 ;
V_16 = F_1 ( V_2 , V_78 , & V_15 ) ;
if ( F_5 ( V_16 ) )
goto V_18;
V_15 &= V_79 ;
V_15 *= 4 ;
V_76 = 1 << V_15 ;
V_75 *= V_76 ;
* V_74 = V_75 ;
V_18:
return V_16 ;
}
static int F_19 ( struct V_67 * V_68 , T_2 * V_80 )
{
struct V_1 * V_2 = V_68 -> V_69 ;
T_1 V_81 , V_82 , V_83 ;
int V_16 ;
* V_80 = 0 ;
V_16 = F_1 ( V_2 , V_84 , & V_81 ) ;
if ( F_5 ( V_16 ) )
goto V_18;
V_16 = F_1 ( V_2 , V_85 , & V_82 ) ;
if ( F_5 ( V_16 ) )
goto V_18;
V_16 = F_1 ( V_2 , V_86 , & V_83 ) ;
if ( F_5 ( V_16 ) )
goto V_18;
* V_80 = F_20 ( ( V_81 | ( V_82 << 8 ) ) , V_83 ) ;
V_18:
return V_16 ;
}
static int F_21 ( struct V_1 * V_2 ,
T_3 * V_87 )
{
T_1 V_81 , V_82 ;
int V_16 ;
* V_87 = 0 ;
V_16 = F_1 ( V_2 , V_88 , & V_81 ) ;
if ( F_5 ( V_16 ) )
goto V_18;
V_16 = F_1 ( V_2 , V_89 , & V_82 ) ;
if ( F_5 ( V_16 ) )
goto V_18;
* V_87 = F_22 ( V_81 | ( ( V_82 & 0x03 ) << 8 ) ) ;
V_18:
return V_16 ;
}
static int F_23 ( struct V_67 * V_68 , T_3 * V_87 )
{
struct V_1 * V_2 = V_68 -> V_69 ;
int V_16 = F_21 ( V_2 , V_87 ) ;
if ( F_5 ( V_16 ) )
goto V_18;
* V_87 /= 10 ;
V_18:
return V_16 ;
}
static int F_24 ( struct V_67 * V_68 ,
enum V_90 * V_91 )
{
struct V_1 * V_2 = V_68 -> V_69 ;
int V_16 , V_92 , V_93 , V_55 , V_64 ;
* V_91 = 0 ;
V_16 = F_11 ( V_2 , & V_92 ) ;
if ( F_5 ( V_16 ) )
goto V_18;
V_16 = F_12 ( V_2 , & V_93 ) ;
if ( F_5 ( V_16 ) )
goto V_18;
V_16 = F_10 ( V_2 , & V_55 ) ;
if ( F_5 ( V_16 ) )
goto V_18;
V_16 = F_13 ( V_2 , & V_64 ) ;
if ( F_5 ( V_16 ) )
goto V_18;
if ( V_92 )
* V_91 |= V_94 ;
if ( V_93 )
* V_91 |= V_95 ;
if ( V_55 )
* V_91 |= V_96 ;
if ( V_64 )
* V_91 |= V_97 ;
if ( ( V_92 ) && ( V_93 ) && ( V_55 ) )
* V_91 |= V_98 ;
V_18:
return V_16 ;
}
static int F_25 ( struct V_67 * V_68 ,
T_3 * V_99 )
{
struct V_1 * V_2 = V_68 -> V_69 ;
enum V_25 V_26 ;
T_3 V_87 ;
F_21 ( V_2 , & V_87 ) ;
F_6 ( V_2 , & V_26 ) ;
switch ( V_26 ) {
case V_29 :
* V_99 = ( V_87 >= 1300 ) ?
F_26 ( 65535 , V_87 * 44 ) : V_87 * 38 ;
break;
case V_30 :
* V_99 = ( V_87 >= 1500 ) ?
F_26 ( 65535 , V_87 * 38 ) : V_87 * 33 ;
break;
case V_31 :
* V_99 = ( V_87 >= 2000 ) ?
F_26 ( 65535 , V_87 * 29 ) : V_87 * 25 ;
break;
default:
* V_99 = 0 ;
return - V_8 ;
}
return 0 ;
}
static int F_27 ( struct V_67 * V_68 )
{
struct V_100 * V_101 = & V_68 -> V_102 ;
struct V_1 * V_2 = V_68 -> V_69 ;
F_16 ( L_1 ) ;
#if 0
p->inversion = ? INVERSION_ON : INVERSION_OFF;
#endif
if ( V_68 -> V_71 . V_72 . V_103 )
V_68 -> V_71 . V_72 . V_103 ( V_68 , & V_101 -> V_104 ) ;
if ( V_68 -> V_71 . V_72 . V_105 )
V_68 -> V_71 . V_72 . V_105 ( V_68 , & V_101 -> V_106 ) ;
F_4 ( V_2 , & V_101 -> V_107 ) ;
F_4 ( V_2 , & V_101 -> V_108 ) ;
F_6 ( V_2 , & V_101 -> V_26 ) ;
F_7 ( V_2 ,
& V_101 -> V_109 ) ;
F_8 ( V_2 ,
& V_101 -> V_110 ) ;
F_9 ( V_2 ,
& V_101 -> V_48 ) ;
return 0 ;
}
static
int F_28 ( struct V_67 * V_68 ,
struct V_111 * V_112 )
{
V_112 -> V_113 = 1000 ;
return 0 ;
}
static void F_29 ( struct V_67 * V_68 )
{
struct V_1 * V_2 = V_68 -> V_69 ;
F_16 ( L_1 ) ;
F_30 ( V_2 ) ;
V_68 -> V_69 = NULL ;
}
struct V_67 * F_31 ( struct V_114 * V_7 ,
struct V_115 * V_5 )
{
struct V_1 * V_2 = NULL ;
F_16 ( L_1 ) ;
V_2 = F_32 ( sizeof( struct V_1 ) , V_116 ) ;
if ( V_2 == NULL )
return NULL ;
V_2 -> V_7 = V_7 ;
V_2 -> V_5 = V_5 ;
memcpy ( & V_2 -> V_68 . V_71 , & V_117 ,
sizeof( struct V_118 ) ) ;
V_2 -> V_68 . V_69 = V_2 ;
return & V_2 -> V_68 ;
}
