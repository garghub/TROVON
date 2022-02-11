static inline bool F_1 ( int V_1 , int V_2 )
{
return ( V_1 & V_2 ) == V_2 ;
}
static int F_2 ( struct V_3 * V_4 ,
int V_5 )
{
int V_6 = 0 ;
int V_7 = F_3 ( V_5 ) ;
V_6 = F_4 ( V_4 -> V_8 , & V_7 , 1 ) ;
if ( V_6 == 0 )
V_4 -> V_5 = V_5 ;
return V_6 ;
}
static int F_5 ( struct V_3 * V_4 , T_1 V_9 ,
const void * V_10 , T_2 V_11 )
{
struct V_12 V_13 ;
struct V_14 V_15 [ 2 ] = { { . V_16 = & V_9 , . V_11 = 1 , } ,
{ . V_16 = V_10 , . V_11 = V_11 } , } ;
F_6 ( & V_13 ) ;
F_7 ( & V_15 [ 0 ] , & V_13 ) ;
F_7 ( & V_15 [ 1 ] , & V_13 ) ;
return F_8 ( V_4 -> V_8 , & V_13 ) ;
}
static void F_9 ( void * V_17 )
{
struct V_3 * V_4 = V_17 ;
F_10 ( & V_4 -> V_18 ) ;
}
static void F_11 ( void * V_17 )
{
struct V_3 * V_4 = V_17 ;
F_12 ( & V_4 -> V_18 ) ;
}
static int F_13 ( void * V_17 , T_1 V_19 , T_1 * V_20 ,
T_2 V_11 )
{
struct V_3 * V_4 = V_17 ;
T_1 V_21 = V_19 & V_22 ;
T_1 V_5 = ( ( V_19 & V_23 ) >> V_24 ) ;
T_1 V_25 = V_26 ;
int V_6 = 0 ;
int V_27 = 0 ;
T_1 V_16 [ 2 ] ;
if ( V_19 < 0x80 ) {
V_25 = V_28 | V_21 ;
if ( ( V_21 < 0x16 ) && ( V_4 -> V_5 != V_5 ) )
V_6 = F_2 ( V_4 , V_5 ) ;
if ( F_14 ( V_6 ) )
return V_6 ;
} else {
switch ( V_19 ) {
case V_29 :
V_25 = V_30 ; break;
case V_31 :
V_25 = V_32 ; break;
case V_33 :
V_25 = V_34 ; break;
case V_35 :
V_25 = V_36 ; break;
case V_37 :
V_25 = V_38 ; break;
case V_39 :
V_25 = V_40 ; break;
case V_41 :
case V_42 :
case V_43 :
default:
return - V_44 ;
}
}
V_16 [ V_27 ++ ] = V_25 ;
if ( V_25 == V_26 )
V_16 [ V_27 ++ ] = V_19 ;
V_6 = F_15 ( V_4 -> V_8 , V_16 , V_27 , V_20 , V_11 ) ;
return V_6 ;
}
static int F_16 ( struct V_3 * V_4 ,
T_1 V_19 , T_1 * V_20 , T_2 V_11 ,
T_1 V_45 , T_1 V_46 )
{
T_1 V_21 = V_19 & V_22 ;
T_1 V_5 = ( ( V_19 & V_23 ) >> V_24 ) ;
T_1 V_25 = V_45 ;
struct V_12 V_13 ;
struct V_14 V_15 [ 3 ] = { { . V_16 = & V_25 , . V_11 = sizeof( V_25 ) , } ,
{ . V_16 = & V_19 , . V_11 = sizeof( V_19 ) , } ,
{ . V_16 = V_20 , . V_11 = V_11 } , } ;
if ( V_19 < 0x80 ) {
int V_6 = 0 ;
V_25 = V_46 | V_21 ;
if ( ( V_21 < 0x16 ) && ( V_4 -> V_5 != V_5 ) )
V_6 = F_2 ( V_4 , V_5 ) ;
if ( F_14 ( V_6 ) )
return V_6 ;
} else {
switch ( V_19 ) {
case V_29 :
V_25 = V_47 ; break;
case V_31 :
V_25 = V_48 ; break;
case V_33 :
V_25 = V_49 ; break;
case V_35 :
V_25 = V_50 ; break;
case V_37 :
V_25 = V_51 ; break;
case V_39 :
V_25 = V_52 ; break;
case V_41 :
case V_42 :
case V_43 :
default:
return - V_44 ;
}
}
F_6 ( & V_13 ) ;
F_7 ( & V_15 [ 0 ] , & V_13 ) ;
if ( V_25 == V_45 ) {
V_15 [ 1 ] . V_16 = & V_19 ;
F_7 ( & V_15 [ 1 ] , & V_13 ) ;
}
F_7 ( & V_15 [ 2 ] , & V_13 ) ;
return F_8 ( V_4 -> V_8 , & V_13 ) ;
}
static int F_17 ( void * V_17 , T_1 V_19 , T_1 * V_20 ,
T_2 V_11 )
{
struct V_3 * V_4 = V_17 ;
return F_16 ( V_4 , V_19 , V_20 , V_11 , V_53 , V_54 ) ;
}
static int F_18 ( struct V_3 * V_4 ,
T_1 V_19 , T_1 V_20 )
{
return F_16 ( V_4 , V_19 , & V_20 , 1 , V_55 , V_56 ) ;
}
static int F_19 ( struct V_3 * V_4 ,
T_1 V_19 , T_1 V_20 )
{
return F_16 ( V_4 , V_19 , & V_20 , 1 , V_57 , V_58 ) ;
}
static int F_20 ( void * V_17 , unsigned int V_19 ,
unsigned int V_2 ,
unsigned int V_20 )
{
struct V_3 * V_4 = V_17 ;
int V_6 = 0 ;
unsigned int V_59 = V_2 & V_20 ;
unsigned int V_60 = V_2 & ~ V_20 ;
if ( ( V_19 >= 0x40 && V_19 < 0x6c ) || V_19 >= 0x80 )
return - V_44 ;
if ( V_59 & 0xff )
V_6 = F_18 ( V_4 , V_19 , V_59 ) ;
V_59 = ( V_59 & 0xff00 ) >> 8 ;
if ( ( V_59 & 0xff ) && ( V_6 == 0 ) )
V_6 = F_18 ( V_4 , V_19 + 1 , V_59 ) ;
if ( ( V_60 & 0xff ) && ( V_6 == 0 ) )
V_6 = F_19 ( V_4 , V_19 , V_60 ) ;
V_60 = ( V_60 & 0xff00 ) >> 8 ;
if ( ( V_60 & 0xff ) && ( V_6 == 0 ) )
V_6 = F_19 ( V_4 , V_19 + 1 , V_60 ) ;
return V_6 ;
}
int F_21 ( void * V_17 , T_1 V_19 , const T_1 * V_61 ,
T_2 V_62 )
{
struct V_3 * V_4 = V_17 ;
if ( V_19 < 0xc0 )
return F_5 ( V_4 , V_19 , V_61 , V_62 ) ;
else
return F_4 ( V_4 -> V_8 , & V_19 , 1 ) ;
}
int F_22 ( void * V_17 , T_1 V_19 , T_1 * V_61 , T_2 V_62 )
{
struct V_3 * V_4 = V_17 ;
if ( V_19 == V_63 && V_62 > 1 )
V_62 = 1 ;
return F_15 ( V_4 -> V_8 , & V_19 , sizeof( V_19 ) , V_61 , V_62 ) ;
}
static int F_23 ( void * V_17 , const void * V_61 ,
T_2 V_11 )
{
T_1 * V_64 = ( T_1 * ) V_61 ;
T_1 V_19 = V_64 [ 0 ] ;
++ V_64 ;
-- V_11 ;
if ( V_19 > 0xa0 )
return F_21 ( V_17 , V_19 , V_64 , V_11 ) ;
if ( V_11 > 2 )
return - V_44 ;
return F_17 ( V_17 , V_19 , V_64 , V_11 ) ;
}
static int F_24 ( void * V_17 ,
const void * V_65 , T_2 V_66 ,
void * V_20 , T_2 V_67 )
{
T_1 V_19 = * ( const T_1 * ) V_65 ;
if ( V_66 != 1 ) {
F_25 ( L_1 , V_68 , V_19 , V_66 ) ;
return - V_44 ;
}
if ( V_19 > 0xa0 )
return F_22 ( V_17 , V_19 , V_20 , V_67 ) ;
if ( V_67 > 2 ) {
F_25 ( L_2 , V_68 , V_19 , V_67 ) ;
return - V_44 ;
}
return F_13 ( V_17 , V_19 , V_20 , V_67 ) ;
}
static bool F_26 ( struct V_69 * V_70 , unsigned int V_19 )
{
if ( ( V_19 < 0x36 ) ||
( ( V_19 >= 0x40 ) && ( V_19 < 0x4c ) ) ||
( ( V_19 >= 0x52 ) && ( V_19 < 0x56 ) ) ||
( ( V_19 >= 0x60 ) && ( V_19 < 0x66 ) ) ||
( ( V_19 >= 0x68 ) && ( V_19 < 0x80 ) ) ||
( ( V_19 >= 0x86 ) && ( V_19 < 0x92 ) ) ||
( V_19 == 0xc8 ) )
return true ;
else
return false ;
}
static bool F_27 ( struct V_69 * V_70 , unsigned int V_19 )
{
if ( ( V_19 < 0x12 ) ||
( ( V_19 >= 0x14 ) && ( V_19 < 0x1a ) ) ||
( ( V_19 >= 0x1c ) && ( V_19 < 0x36 ) ) ||
( ( V_19 >= 0x40 ) && ( V_19 < 0x4c ) ) ||
( ( V_19 >= 0x52 ) && ( V_19 < 0x56 ) ) ||
( ( V_19 >= 0x60 ) && ( V_19 < 0x68 ) ) ||
( ( V_19 >= 0x6c ) && ( V_19 < 0x80 ) ) ||
( ( V_19 >= 0x86 ) && ( V_19 < 0x92 ) ) ||
( ( V_19 >= 0xc0 ) && ( V_19 < 0xc8 ) ) ||
( ( V_19 >= 0xca ) && ( V_19 < 0xf0 ) ) )
return true ;
else
return false ;
}
static bool F_28 ( struct V_69 * V_70 , unsigned int V_19 )
{
switch ( V_19 ) {
case V_71 :
case V_72 :
case V_73 :
case V_74 :
case V_75 :
case V_76 :
case V_77 :
case V_78 :
case V_79 :
case V_80 :
return true ;
default:
break;
}
return false ;
}
static bool F_29 ( struct V_69 * V_70 , unsigned int V_19 )
{
if ( ( ( V_19 >= 0xc0 ) && ( V_19 < 0xc8 ) ) ||
( ( V_19 >= 0xca ) && ( V_19 < 0xf0 ) ) )
return true ;
else
return false ;
}
static int F_30 ( void * V_17 , unsigned int V_19 ,
unsigned int * V_20 )
{
struct V_3 * V_4 = V_17 ;
int V_6 ;
unsigned int V_81 ;
V_19 = V_82 | ( V_19 & V_83 ) ;
V_6 = F_31 ( V_4 -> V_84 , V_85 , V_19 ) ;
if ( F_14 ( V_6 ) )
goto V_86;
V_6 = F_31 ( V_4 -> V_84 , V_87 , V_88 ) ;
if ( F_14 ( V_6 ) )
goto V_86;
F_32 ( 26 , 100 ) ;
while ( ( V_6 = F_33 ( V_4 -> V_84 , V_80 , & V_81 ) != 0 ) &&
( V_81 & V_89 ) )
F_34 () ;
if ( F_14 ( V_6 ) )
goto V_86;
V_6 = F_31 ( V_4 -> V_84 , V_87 , 0 ) ;
if ( F_14 ( V_6 ) )
goto V_86;
V_6 = F_33 ( V_4 -> V_84 , V_79 , V_20 ) ;
V_86:
if ( V_6 )
F_25 ( L_3 , V_68 , V_6 ,
V_19 & V_83 ) ;
return V_6 ;
}
static int F_35 ( void * V_17 , unsigned int V_19 ,
unsigned int V_20 )
{
struct V_3 * V_4 = V_17 ;
int V_6 ;
unsigned int V_81 ;
V_19 = V_82 | ( V_19 & V_83 ) ;
V_6 = F_31 ( V_4 -> V_84 , V_85 , V_19 ) ;
if ( F_14 ( V_6 ) )
goto V_86;
V_6 = F_31 ( V_4 -> V_84 , V_90 , V_20 ) ;
if ( F_14 ( V_6 ) )
goto V_86;
F_32 ( 26 , 100 ) ;
while ( ( V_6 = F_33 ( V_4 -> V_84 , V_80 , & V_81 ) != 0 ) &&
( V_81 & V_89 ) )
F_34 () ;
V_86:
if ( V_6 )
F_25 ( L_4 , V_68 , V_6 ,
V_19 & V_83 , V_20 ) ;
return V_6 ;
}
static bool F_36 ( struct V_69 * V_70 , unsigned int V_19 )
{
switch ( V_19 ) {
case V_91 :
case V_92 :
case V_93 :
case V_94 :
case V_95 :
case V_96 :
case V_97 :
case V_98 :
return true ;
default:
return false ;
}
}
static bool F_37 ( struct V_69 * V_70 , unsigned int V_19 )
{
switch ( V_19 ) {
case V_91 :
case V_96 :
case V_93 :
return true ;
case V_92 :
case V_97 :
case V_98 :
case V_94 :
case V_95 :
default:
return false ;
}
}
static bool F_38 ( struct V_69 * V_70 , unsigned int V_19 )
{
switch ( V_19 ) {
case V_92 :
case V_97 :
case V_98 :
case V_94 :
case V_95 :
case V_96 :
return true ;
default:
return false ;
}
}
void F_39 ( struct V_69 * V_70 ,
struct V_3 * V_4 )
{
F_40 ( & V_4 -> V_18 ) ;
V_99 . V_100 = V_4 ;
V_4 -> V_84 = F_41 ( V_70 , & V_101 , V_4 , & V_99 ) ;
V_4 -> V_102 = F_41 ( V_70 , & V_103 , V_4 , & V_104 ) ;
}
