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
T_2 * V_13 )
{
T_1 V_14 ;
int V_15 = F_1 ( V_2 , V_16 , & V_14 ) ;
if ( F_5 ( V_15 ) )
goto V_17;
switch ( V_14 & V_18 ) {
case 0 :
* V_13 = V_19 ;
break;
case 1 :
* V_13 = V_20 ;
break;
case 2 :
* V_13 = V_21 ;
break;
case 3 :
* V_13 = V_22 ;
break;
case 4 :
* V_13 = V_23 ;
break;
}
V_17:
return V_15 ;
}
static
int F_6 ( struct V_1 * V_2 ,
T_3 * V_24 )
{
T_1 V_14 ;
int V_15 = F_1 ( V_2 , V_25 , & V_14 ) ;
if ( F_5 ( V_15 ) )
goto V_17;
switch ( ( V_14 & V_26 ) >> 4 ) {
case 0 :
* V_24 = V_27 ;
break;
case 1 :
* V_24 = V_28 ;
break;
case 2 :
* V_24 = V_29 ;
break;
}
V_17:
return V_15 ;
}
static
int F_7 ( struct V_1 * V_2 ,
T_4 * V_30 )
{
T_1 V_14 ;
int V_15 = F_1 ( V_2 , V_31 , & V_14 ) ;
if ( F_5 ( V_15 ) )
goto V_17;
switch ( ( V_14 & V_32 ) >> 2 ) {
case 0 :
* V_30 = V_33 ;
break;
case 1 :
* V_30 = V_34 ;
break;
case 2 :
* V_30 = V_35 ;
break;
}
V_17:
return V_15 ;
}
static
int F_8 ( struct V_1 * V_2 ,
T_5 * V_36 )
{
T_1 V_14 ;
int V_15 = F_1 ( V_2 , V_37 , & V_14 ) ;
if ( F_5 ( V_15 ) )
goto V_17;
switch ( ( V_14 & V_38 ) >> 4 ) {
case 0 :
* V_36 = V_39 ;
break;
case 1 :
* V_36 = V_40 ;
break;
case 2 :
* V_36 = V_41 ;
break;
case 3 :
* V_36 = V_42 ;
break;
}
V_17:
return V_15 ;
}
static
int F_9 ( struct V_1 * V_2 ,
T_6 * V_43 )
{
T_1 V_14 ;
int V_15 = F_1 ( V_2 , V_44 , & V_14 ) ;
if ( F_5 ( V_15 ) )
goto V_17;
switch ( ( V_14 & V_45 ) >> 6 ) {
case 0 :
* V_43 = V_46 ;
break;
case 1 :
* V_43 = V_47 ;
break;
case 2 :
* V_43 = V_48 ;
break;
case 3 :
* V_43 = V_49 ;
break;
}
V_17:
return V_15 ;
}
static
int F_10 ( struct V_1 * V_2 ,
int * V_50 )
{
T_1 V_14 = 0 ;
int V_15 = F_1 ( V_2 , V_51 , & V_14 ) ;
if ( F_5 ( V_15 ) )
goto V_17;
* V_50 = ( V_14 & V_52 ) >> 4 ;
V_17:
return V_15 ;
}
static
int F_11 ( struct V_1 * V_2 ,
int * V_53 )
{
T_1 V_14 = 0 ;
int V_15 = F_1 ( V_2 , V_54 , & V_14 ) ;
if ( F_5 ( V_15 ) )
goto V_17;
* V_53 = ( V_14 & V_55 ) >> 3 ;
V_17:
return V_15 ;
}
static
int F_12 ( struct V_1 * V_2 ,
int * V_56 )
{
T_1 V_14 = 0 ;
int V_15 = F_1 ( V_2 , V_57 , & V_14 ) ;
if ( F_5 ( V_15 ) )
goto V_17;
* V_56 = ( V_14 & V_58 ) >> 6 ;
V_17:
return V_15 ;
}
static
int F_13 ( struct V_1 * V_2 ,
int * V_59 )
{
T_1 V_14 = 0 ;
int V_15 = F_1 ( V_2 , V_60 , & V_14 ) ;
if ( F_5 ( V_15 ) )
goto V_17;
* V_59 = ( V_14 & V_61 ) >> 4 ;
V_17:
return V_15 ;
}
static int F_14 ( struct V_1 * V_2 )
{
return F_2 ( V_2 , 0x0e , 0xff ) ;
}
static int F_15 ( struct V_62 * V_63 ,
struct V_64 * V_65 )
{
struct V_1 * V_2 = V_63 -> V_66 ;
int V_15 = 0 ;
struct V_10 V_67 [] = {
{ 0x00 , 0xff , 0x01 } ,
{ 0x40 , 0xff , 0x05 } ,
{ 0x40 , 0xff , 0x01 } ,
{ 0x41 , 0xff , 0xca } ,
{ 0x41 , 0xff , 0xc0 } ,
{ 0x00 , 0xff , 0x00 } ,
{ 0 , 0 , 0 }
} ;
F_16 ( L_1 ) ;
if ( V_63 -> V_68 . V_69 . V_70 ) {
V_15 = V_63 -> V_68 . V_69 . V_70 ( V_63 , V_65 ) ;
if ( F_5 ( V_15 ) )
goto V_17;
F_17 ( 50 ) ;
}
V_15 = F_3 ( V_2 , V_67 ) ;
F_5 ( V_15 ) ;
F_17 ( 50 ) ;
V_15 = F_14 ( V_2 ) ;
F_5 ( V_15 ) ;
F_17 ( 100 ) ;
V_17:
return V_15 ;
}
static int F_18 ( struct V_62 * V_63 , T_7 * V_71 )
{
struct V_1 * V_2 = V_63 -> V_66 ;
T_7 V_72 , V_73 ;
T_1 V_14 ;
int V_15 ;
* V_71 = 0 ;
V_15 = F_1 ( V_2 , V_74 , & V_14 ) ;
if ( F_5 ( V_15 ) )
goto V_17;
V_72 = V_14 ;
V_15 = F_1 ( V_2 , V_75 , & V_14 ) ;
if ( F_5 ( V_15 ) )
goto V_17;
V_14 &= V_76 ;
V_14 *= 4 ;
V_73 = 1 << V_14 ;
V_72 *= V_73 ;
* V_71 = V_72 ;
V_17:
return V_15 ;
}
static int F_19 ( struct V_62 * V_63 , T_7 * V_77 )
{
struct V_1 * V_2 = V_63 -> V_66 ;
T_1 V_78 , V_79 , V_80 ;
int V_15 ;
* V_77 = 0 ;
V_15 = F_1 ( V_2 , V_81 , & V_78 ) ;
if ( F_5 ( V_15 ) )
goto V_17;
V_15 = F_1 ( V_2 , V_82 , & V_79 ) ;
if ( F_5 ( V_15 ) )
goto V_17;
V_15 = F_1 ( V_2 , V_83 , & V_80 ) ;
if ( F_5 ( V_15 ) )
goto V_17;
* V_77 = F_20 ( ( V_78 | ( V_79 << 8 ) ) , V_80 ) ;
V_17:
return V_15 ;
}
static int F_21 ( struct V_1 * V_2 ,
T_8 * V_84 )
{
T_1 V_78 , V_79 ;
int V_15 ;
* V_84 = 0 ;
V_15 = F_1 ( V_2 , V_85 , & V_78 ) ;
if ( F_5 ( V_15 ) )
goto V_17;
V_15 = F_1 ( V_2 , V_86 , & V_79 ) ;
if ( F_5 ( V_15 ) )
goto V_17;
* V_84 = F_22 ( V_78 | ( ( V_79 & 0x03 ) << 8 ) ) ;
V_17:
return V_15 ;
}
static int F_23 ( struct V_62 * V_63 , T_8 * V_84 )
{
struct V_1 * V_2 = V_63 -> V_66 ;
int V_15 = F_21 ( V_2 , V_84 ) ;
if ( F_5 ( V_15 ) )
goto V_17;
* V_84 /= 10 ;
V_17:
return V_15 ;
}
static int F_24 ( struct V_62 * V_63 ,
T_9 * V_87 )
{
struct V_1 * V_2 = V_63 -> V_66 ;
int V_15 , V_88 , V_89 , V_50 , V_59 ;
* V_87 = 0 ;
V_15 = F_11 ( V_2 , & V_88 ) ;
if ( F_5 ( V_15 ) )
goto V_17;
V_15 = F_12 ( V_2 , & V_89 ) ;
if ( F_5 ( V_15 ) )
goto V_17;
V_15 = F_10 ( V_2 , & V_50 ) ;
if ( F_5 ( V_15 ) )
goto V_17;
V_15 = F_13 ( V_2 , & V_59 ) ;
if ( F_5 ( V_15 ) )
goto V_17;
if ( V_88 )
* V_87 |= V_90 ;
if ( V_89 )
* V_87 |= V_91 ;
if ( V_50 )
* V_87 |= V_92 ;
if ( V_59 )
* V_87 |= V_93 ;
if ( ( V_88 ) && ( V_89 ) && ( V_50 ) )
* V_87 |= V_94 ;
V_17:
return V_15 ;
}
static int F_25 ( struct V_62 * V_63 ,
T_8 * V_95 )
{
struct V_1 * V_2 = V_63 -> V_66 ;
T_3 V_24 ;
T_8 V_84 ;
F_21 ( V_2 , & V_84 ) ;
F_6 ( V_2 , & V_24 ) ;
switch ( V_24 ) {
case V_27 :
* V_95 = ( V_84 >= 1300 ) ?
F_26 ( 65535 , V_84 * 44 ) : V_84 * 38 ;
break;
case V_28 :
* V_95 = ( V_84 >= 1500 ) ?
F_26 ( 65535 , V_84 * 38 ) : V_84 * 33 ;
break;
case V_29 :
* V_95 = ( V_84 >= 2000 ) ?
F_26 ( 65535 , V_84 * 29 ) : V_84 * 25 ;
break;
default:
* V_95 = 0 ;
return - V_8 ;
}
return 0 ;
}
static int F_27 ( struct V_62 * V_63 ,
struct V_64 * V_96 )
{
struct V_1 * V_2 = V_63 -> V_66 ;
F_16 ( L_1 ) ;
#if 0
p->inversion = ? INVERSION_ON : INVERSION_OFF;
#endif
if ( V_63 -> V_68 . V_69 . V_97 )
V_63 -> V_68 . V_69 . V_97 ( V_63 , & V_96 -> V_98 . V_99 . V_100 ) ;
if ( V_63 -> V_68 . V_69 . V_101 )
V_63 -> V_68 . V_69 . V_101 ( V_63 , & V_96 -> V_102 ) ;
F_4 ( V_2 , & V_96 -> V_98 . V_99 . V_103 ) ;
F_4 ( V_2 , & V_96 -> V_98 . V_99 . V_104 ) ;
F_6 ( V_2 , & V_96 -> V_98 . V_99 . V_24 ) ;
F_7 ( V_2 ,
& V_96 -> V_98 . V_99 . V_105 ) ;
F_8 ( V_2 ,
& V_96 -> V_98 . V_99 . V_106 ) ;
F_9 ( V_2 ,
& V_96 -> V_98 . V_99 . V_107 ) ;
return 0 ;
}
static
int F_28 ( struct V_62 * V_63 ,
struct V_108 * V_109 )
{
V_109 -> V_110 = 1000 ;
return 0 ;
}
static void F_29 ( struct V_62 * V_63 )
{
struct V_1 * V_2 = V_63 -> V_66 ;
F_16 ( L_1 ) ;
F_30 ( V_2 ) ;
V_63 -> V_66 = NULL ;
}
struct V_62 * F_31 ( struct V_111 * V_7 ,
struct V_112 * V_5 )
{
struct V_1 * V_2 = NULL ;
F_16 ( L_1 ) ;
V_2 = F_32 ( sizeof( struct V_1 ) , V_113 ) ;
if ( V_2 == NULL )
return NULL ;
V_2 -> V_7 = V_7 ;
V_2 -> V_5 = V_5 ;
memcpy ( & V_2 -> V_63 . V_68 , & V_114 ,
sizeof( struct V_115 ) ) ;
V_2 -> V_63 . V_66 = V_2 ;
return & V_2 -> V_63 ;
}
