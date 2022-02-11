static int F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
enum V_7 V_8 ;
int V_9 = 0 ;
switch ( V_5 -> V_8 ) {
case V_10 :
case V_11 :
V_8 = V_5 -> V_8 ;
break;
case V_12 :
default:
switch ( V_5 -> V_13 ) {
case V_14 :
V_8 = V_10 ;
break;
case V_15 :
default:
V_8 = V_11 ;
break;
}
}
switch ( V_8 ) {
case V_11 :
if ( V_2 -> V_16 . V_17 . V_18 )
V_9 = V_2 -> V_16 . V_17 . V_18 ( V_2 , V_3 ) ;
break;
case V_10 :
if ( V_2 -> V_16 . V_18 )
V_9 = V_2 -> V_16 . V_18 ( V_2 , V_3 ) ;
break;
default:
V_9 = - V_19 ;
break;
}
return V_9 ;
}
static void F_2 ( struct V_1 * V_2 , int V_20 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned char * V_21 = V_5 -> V_22 ;
F_3 ( L_1 ) ;
F_3 ( L_2 , 0xff & V_21 [ V_23 ] ) ;
F_3 ( L_3 , 0xff & V_21 [ V_24 ] ) ;
F_3 ( L_4 , 0xff & V_21 [ V_25 ] ) ;
F_3 ( L_5 , 0xff & V_21 [ V_26 ] ) ;
F_3 ( L_6 , 0xff & V_21 [ V_27 ] ) ;
F_3 ( L_7 , 0xff & V_21 [ V_28 ] ) ;
F_3 ( L_8 , 0xff & V_21 [ V_29 ] ) ;
F_3 ( L_9 , 0xff & V_21 [ V_30 ] ) ;
F_3 ( L_10 , 0xff & V_21 [ V_31 ] ) ;
F_3 ( L_11 , 0xff & V_21 [ V_32 ] ) ;
F_3 ( L_12 , 0xff & V_21 [ V_33 ] ) ;
F_3 ( L_13 , 0xff & V_21 [ V_34 ] ) ;
F_3 ( L_14 , 0xff & V_21 [ V_35 ] ) ;
F_3 ( L_15 , 0xff & V_21 [ V_36 ] ) ;
F_3 ( L_16 , 0xff & V_21 [ V_37 ] ) ;
F_3 ( L_17 , 0xff & V_21 [ V_38 ] ) ;
if ( ! ( V_39 & V_40 ) )
return;
F_3 ( L_18 , 0xff & V_21 [ V_41 ] ) ;
F_3 ( L_19 , 0xff & V_21 [ V_42 ] ) ;
F_3 ( L_20 , 0xff & V_21 [ V_43 ] ) ;
F_3 ( L_21 , 0xff & V_21 [ V_44 ] ) ;
F_3 ( L_22 , 0xff & V_21 [ V_45 ] ) ;
F_3 ( L_23 , 0xff & V_21 [ V_46 ] ) ;
F_3 ( L_24 , 0xff & V_21 [ V_47 ] ) ;
F_3 ( L_25 , 0xff & V_21 [ V_48 ] ) ;
F_3 ( L_26 , 0xff & V_21 [ V_49 ] ) ;
F_3 ( L_27 , 0xff & V_21 [ V_50 ] ) ;
F_3 ( L_28 , 0xff & V_21 [ V_51 ] ) ;
F_3 ( L_29 , 0xff & V_21 [ V_52 ] ) ;
F_3 ( L_30 , 0xff & V_21 [ V_53 ] ) ;
F_3 ( L_31 , 0xff & V_21 [ V_54 ] ) ;
F_3 ( L_32 , 0xff & V_21 [ V_55 ] ) ;
F_3 ( L_33 , 0xff & V_21 [ V_56 ] ) ;
F_3 ( L_34 , 0xff & V_21 [ V_57 ] ) ;
F_3 ( L_35 , 0xff & V_21 [ V_58 ] ) ;
F_3 ( L_36 , 0xff & V_21 [ V_59 ] ) ;
F_3 ( L_37 , 0xff & V_21 [ V_60 ] ) ;
F_3 ( L_38 , 0xff & V_21 [ V_61 ] ) ;
F_3 ( L_39 , 0xff & V_21 [ V_62 ] ) ;
F_3 ( L_40 , 0xff & V_21 [ V_63 ] ) ;
}
int F_4 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned char * V_21 = V_5 -> V_22 ;
unsigned char V_64 = 0x00 ;
int V_9 ;
struct V_65 V_66 [] = {
{ . V_67 = V_5 -> V_68 . V_67 , . V_69 = 0 ,
. V_64 = & V_64 , . V_70 = 1 } ,
{ . V_67 = V_5 -> V_68 . V_67 , . V_69 = V_71 ,
. V_64 = V_21 , . V_70 = 16 }
} ;
F_1 ( V_2 , 1 ) ;
V_9 = F_5 ( V_5 -> V_68 . V_72 , V_66 , 2 ) ;
F_1 ( V_2 , 0 ) ;
if ( V_9 != 2 )
F_6 ( L_41 , V_9 ) ;
if ( V_39 & V_73 )
F_2 ( V_2 , 0 ) ;
return ( V_9 == 2 ? 0 : V_9 ) ;
}
int F_7 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned char * V_21 = V_5 -> V_22 ;
unsigned char V_74 [ V_75 ] ;
unsigned char V_64 = 0x00 ;
int V_9 , V_76 ;
struct V_65 V_66 [] = {
{ . V_67 = V_5 -> V_68 . V_67 , . V_69 = 0 ,
. V_64 = & V_64 , . V_70 = 1 } ,
{ . V_67 = V_5 -> V_68 . V_67 , . V_69 = V_71 ,
. V_64 = V_74 , . V_70 = V_75 }
} ;
F_1 ( V_2 , 1 ) ;
V_9 = F_5 ( V_5 -> V_68 . V_72 , V_66 , 2 ) ;
F_1 ( V_2 , 0 ) ;
if ( V_9 != 2 )
F_6 ( L_41 , V_9 ) ;
for ( V_76 = 0 ; V_76 < V_75 ; V_76 ++ ) {
if ( ( V_76 != V_49 ) &&
( V_76 != V_56 ) &&
( V_76 != V_57 ) &&
( V_76 != V_59 ) &&
( V_76 != V_60 ) )
V_21 [ V_76 ] = V_74 [ V_76 ] ;
}
if ( V_39 & V_73 )
F_2 ( V_2 , 1 ) ;
return ( V_9 == 2 ? 0 : V_9 ) ;
}
static int F_8 ( struct V_1 * V_2 , int V_77 , int V_70 ,
bool V_78 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned char * V_21 = V_5 -> V_22 ;
unsigned char V_64 [ V_75 + 1 ] ;
struct V_65 V_66 = { . V_67 = V_5 -> V_68 . V_67 , . V_69 = 0 ,
. V_64 = V_64 } ;
int V_76 , V_9 = 1 , V_79 ;
F_9 ( ( V_70 == 0 ) || ( V_77 + V_70 > sizeof( V_64 ) ) ) ;
switch ( V_5 -> V_80 ) {
case V_81 :
V_79 = 3 ;
break;
case V_82 :
V_79 = 8 ;
break;
case V_83 :
V_79 = 16 ;
break;
case V_84 :
default:
V_79 = 39 ;
}
if ( V_78 ) {
F_1 ( V_2 , 1 ) ;
F_10 ( V_5 -> V_68 . V_72 ) ;
}
while ( V_70 ) {
if ( V_79 > V_70 )
V_79 = V_70 ;
V_64 [ 0 ] = V_77 ;
for ( V_76 = 1 ; V_76 <= V_79 ; V_76 ++ )
V_64 [ V_76 ] = V_21 [ V_77 - 1 + V_76 ] ;
V_66 . V_70 = V_79 + 1 ;
V_9 = F_11 ( V_5 -> V_68 . V_72 , & V_66 , 1 ) ;
if ( V_9 != 1 )
break;
V_77 += V_79 ;
V_70 -= V_79 ;
}
if ( V_78 ) {
F_12 ( V_5 -> V_68 . V_72 ) ;
F_1 ( V_2 , 0 ) ;
}
if ( V_9 != 1 )
F_6 ( L_42
L_43 , V_77 , V_79 , V_9 ) ;
return ( V_9 == 1 ? 0 : V_9 ) ;
}
int F_13 ( struct V_1 * V_2 , int V_77 , int V_70 )
{
return F_8 ( V_2 , V_77 , V_70 , true ) ;
}
static int F_14 ( struct V_1 * V_2 ,
enum V_85 V_86 , int V_87 ,
bool V_78 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned char * V_21 = V_5 -> V_22 ;
int V_88 = ( V_86 == V_89 ) ? V_47 : V_44 ;
V_21 [ V_88 ] &= ~ 0x20 ;
V_21 [ V_88 ] |= ( ( V_87 & 1 ) << 5 ) ;
return F_8 ( V_2 , V_88 , 1 , V_78 ) ;
}
int F_15 ( struct V_1 * V_2 ,
enum V_85 V_86 , int V_87 )
{
return F_14 ( V_2 , V_86 , V_87 , true ) ;
}
int F_16 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned char * V_21 = V_5 -> V_22 ;
F_17 ( L_44 ,
F_18 ( V_5 -> V_68 . V_72 ) ,
V_5 -> V_68 . V_67 ) ;
F_1 ( V_2 , 1 ) ;
F_10 ( V_5 -> V_68 . V_72 ) ;
switch ( V_5 -> V_90 ) {
case V_91 :
V_21 [ V_23 ] = 0x83 ;
break;
case V_92 :
V_21 [ V_23 ] = 0x84 ;
break;
}
V_21 [ V_24 ] = 0x08 ;
V_21 [ V_25 ] = 0x80 ;
V_21 [ V_26 ] = 0xc6 ;
V_21 [ V_27 ] = 0xdf ;
V_21 [ V_28 ] = 0x16 ;
V_21 [ V_29 ] = 0x60 ;
V_21 [ V_30 ] = 0x80 ;
V_21 [ V_31 ] = 0x80 ;
V_21 [ V_32 ] = 0x00 ;
V_21 [ V_33 ] = 0x00 ;
V_21 [ V_34 ] = 0x00 ;
V_21 [ V_35 ] = 0x00 ;
V_21 [ V_36 ] = 0x00 ;
V_21 [ V_37 ] = 0x00 ;
V_21 [ V_38 ] = 0x00 ;
switch ( V_5 -> V_90 ) {
case V_91 :
V_21 [ V_41 ] = 0xff ;
break;
case V_92 :
V_21 [ V_41 ] = 0xfc ;
break;
}
V_21 [ V_42 ] = 0x01 ;
V_21 [ V_43 ] = 0x84 ;
V_21 [ V_44 ] = 0x41 ;
V_21 [ V_45 ] = 0x01 ;
V_21 [ V_46 ] = 0x84 ;
V_21 [ V_47 ] = 0x40 ;
V_21 [ V_48 ] = 0x07 ;
V_21 [ V_49 ] = 0x00 ;
V_21 [ V_50 ] = 0x00 ;
V_21 [ V_51 ] = 0x96 ;
switch ( V_5 -> V_90 ) {
case V_91 :
V_21 [ V_52 ] = 0x0f ;
break;
case V_92 :
V_21 [ V_52 ] = 0x33 ;
break;
}
V_21 [ V_53 ] = 0xc1 ;
V_21 [ V_54 ] = 0x00 ;
V_21 [ V_55 ] = 0x8f ;
V_21 [ V_56 ] = 0x00 ;
V_21 [ V_57 ] = 0x00 ;
switch ( V_5 -> V_90 ) {
case V_91 :
V_21 [ V_58 ] = 0x00 ;
break;
case V_92 :
V_21 [ V_58 ] = 0x8c ;
break;
}
V_21 [ V_59 ] = 0x00 ;
V_21 [ V_60 ] = 0x20 ;
switch ( V_5 -> V_90 ) {
case V_91 :
V_21 [ V_61 ] = 0x33 ;
break;
case V_92 :
V_21 [ V_61 ] = 0xb3 ;
break;
}
V_21 [ V_62 ] = 0x48 ;
V_21 [ V_63 ] = 0xb0 ;
F_8 ( V_2 , 0x00 , V_75 , false ) ;
V_21 [ V_57 ] = 0x00 ;
F_8 ( V_2 , V_57 , 1 , false ) ;
V_21 [ V_57 ] = 0x03 ;
F_8 ( V_2 , V_57 , 1 , false ) ;
V_21 [ V_57 ] = 0x43 ;
F_8 ( V_2 , V_57 , 1 , false ) ;
V_21 [ V_57 ] = 0x4c ;
F_8 ( V_2 , V_57 , 1 , false ) ;
if ( ( V_5 -> V_90 ) == V_91 ) {
V_21 [ V_60 ] = 0xa0 ;
F_8 ( V_2 , V_60 , 1 , false ) ;
V_21 [ V_60 ] = 0xa7 ;
F_8 ( V_2 , V_60 , 1 , false ) ;
V_21 [ V_60 ] = 0xe7 ;
F_8 ( V_2 , V_60 , 1 , false ) ;
V_21 [ V_60 ] = 0xec ;
F_8 ( V_2 , V_60 , 1 , false ) ;
}
V_21 [ V_28 ] = 0x1f ;
V_21 [ V_29 ] = 0x66 ;
V_21 [ V_30 ] = 0x81 ;
V_21 [ V_31 ] = 0xcc ;
V_21 [ V_32 ] = 0x6c ;
V_21 [ V_33 ] = 0x00 ;
V_21 [ V_34 ] = 0x00 ;
V_21 [ V_35 ] = 0xcd ;
V_21 [ V_36 ] = 0x77 ;
V_21 [ V_37 ] = 0x08 ;
V_21 [ V_38 ] = 0x00 ;
F_8 ( V_2 , V_28 , 11 , false ) ;
if ( ( V_5 -> V_90 ) == V_92 ) {
F_14 ( V_2 , V_93 , 1 , false ) ;
F_19 ( 1 ) ;
F_14 ( V_2 , V_93 , 0 , false ) ;
}
F_19 ( 5 ) ;
F_8 ( V_2 , V_26 , 1 , false ) ;
F_19 ( 5 ) ;
V_21 [ V_30 ] = 0x85 ;
V_21 [ V_31 ] = 0xcb ;
V_21 [ V_32 ] = 0x66 ;
V_21 [ V_33 ] = 0x70 ;
F_8 ( V_2 , V_28 , 7 , false ) ;
F_19 ( 5 ) ;
F_8 ( V_2 , V_27 , 1 , false ) ;
F_19 ( 30 ) ;
V_21 [ V_30 ] = 0x82 ;
V_21 [ V_31 ] = 0xa8 ;
V_21 [ V_33 ] = 0x00 ;
V_21 [ V_35 ] = 0xa9 ;
V_21 [ V_36 ] = 0x73 ;
V_21 [ V_37 ] = 0x1a ;
F_8 ( V_2 , V_28 , 11 , false ) ;
F_19 ( 5 ) ;
F_8 ( V_2 , V_26 , 1 , false ) ;
F_19 ( 5 ) ;
V_21 [ V_30 ] = 0x86 ;
V_21 [ V_31 ] = 0xa8 ;
V_21 [ V_32 ] = 0x66 ;
V_21 [ V_33 ] = 0xa0 ;
F_8 ( V_2 , V_28 , 7 , false ) ;
F_19 ( 5 ) ;
F_8 ( V_2 , V_27 , 1 , false ) ;
F_19 ( 30 ) ;
V_21 [ V_30 ] = 0x83 ;
V_21 [ V_31 ] = 0x98 ;
V_21 [ V_32 ] = 0x65 ;
V_21 [ V_33 ] = 0x00 ;
V_21 [ V_35 ] = 0x99 ;
V_21 [ V_36 ] = 0x71 ;
V_21 [ V_37 ] = 0xcd ;
F_8 ( V_2 , V_28 , 11 , false ) ;
F_19 ( 5 ) ;
F_8 ( V_2 , V_26 , 1 , false ) ;
F_19 ( 5 ) ;
V_21 [ V_30 ] = 0x87 ;
V_21 [ V_32 ] = 0x65 ;
V_21 [ V_33 ] = 0x50 ;
F_8 ( V_2 , V_28 , 7 , false ) ;
F_19 ( 5 ) ;
F_8 ( V_2 , V_27 , 1 , false ) ;
F_19 ( 30 ) ;
V_21 [ V_29 ] = 0x64 ;
F_8 ( V_2 , V_29 , 1 , false ) ;
F_8 ( V_2 , V_26 , 1 , false ) ;
F_12 ( V_5 -> V_68 . V_72 ) ;
F_1 ( V_2 , 0 ) ;
return 0 ;
}
int F_20 ( struct V_1 * V_2 ,
int V_94 , int V_95 , int V_96 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned char * V_21 = V_5 -> V_22 ;
if ( V_39 & V_40 )
F_17 ( L_45 , V_94 , V_95 , V_96 ) ;
V_21 [ V_28 ] &= ~ 0xe0 ;
V_21 [ V_28 ] |= ( V_94 ? ( 1 << 7 ) : 0 ) |
( V_95 ? ( 1 << 6 ) : 0 ) |
( V_96 ? ( 1 << 5 ) : 0 ) ;
return F_13 ( V_2 , V_28 , 1 ) ;
}
int F_21 ( struct V_1 * V_2 , T_1 V_97 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned char * V_21 = V_5 -> V_22 ;
T_2 V_98 , V_99 ;
T_1 div ;
int V_9 = F_22 ( V_2 , V_100 , & V_97 , & V_99 , & V_98 ) ;
if ( F_23 ( V_9 ) )
goto V_101;
V_21 [ V_35 ] = ( 0x7f & V_99 ) ;
div = ( ( V_98 * ( V_97 / 1000 ) ) << 7 ) / 125 ;
V_21 [ V_36 ] = 0x7f & ( div >> 16 ) ;
V_21 [ V_37 ] = 0xff & ( div >> 8 ) ;
V_21 [ V_38 ] = 0xff & div ;
V_101:
return V_9 ;
}
int F_24 ( struct V_1 * V_2 , T_1 V_97 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned char * V_21 = V_5 -> V_22 ;
T_2 V_98 , V_99 ;
T_1 div ;
int V_9 = F_22 ( V_2 , V_102 , & V_97 , & V_99 , & V_98 ) ;
if ( F_23 ( V_9 ) )
goto V_101;
V_21 [ V_31 ] = V_99 ;
div = ( ( V_98 * ( V_97 / 1000 ) ) << 7 ) / 125 ;
V_21 [ V_32 ] = 0x7f & ( div >> 16 ) ;
V_21 [ V_33 ] = 0xff & ( div >> 8 ) ;
V_21 [ V_34 ] = 0xff & div ;
V_101:
return V_9 ;
}
int F_25 ( struct V_1 * V_2 , T_1 * V_97 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned char * V_21 = V_5 -> V_22 ;
T_2 V_103 ;
int V_9 = F_26 ( V_2 , V_104 , V_97 , & V_103 ) ;
if ( F_23 ( V_9 ) )
goto V_101;
V_21 [ V_26 ] &= ~ 0x07 ;
V_21 [ V_26 ] |= ( 0x07 & V_103 ) ;
V_101:
return V_9 ;
}
int F_27 ( struct V_1 * V_2 , T_1 * V_97 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned char * V_21 = V_5 -> V_22 ;
T_2 V_103 ;
int V_9 = F_26 ( V_2 , V_105 , V_97 , & V_103 ) ;
if ( F_23 ( V_9 ) )
goto V_101;
V_21 [ V_53 ] &= ~ 0x7c ;
V_21 [ V_53 ] |= ( 0x7c & V_103 ) ;
V_101:
return V_9 ;
}
int F_28 ( struct V_1 * V_2 , T_1 * V_97 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned char * V_21 = V_5 -> V_22 ;
T_2 V_103 ;
int V_9 = F_26 ( V_2 , V_106 , V_97 , & V_103 ) ;
if ( F_23 ( V_9 ) )
goto V_101;
V_21 [ V_27 ] &= ~ 0xe0 ;
V_21 [ V_27 ] |= ( 0xe0 & ( V_103 << 5 ) ) ;
V_101:
return V_9 ;
}
int F_29 ( struct V_1 * V_2 , T_1 * V_97 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned char * V_21 = V_5 -> V_22 ;
T_2 V_103 ;
int V_9 = F_26 ( V_2 , V_107 , V_97 , & V_103 ) ;
if ( F_23 ( V_9 ) )
goto V_101;
V_21 [ V_27 ] &= ~ 0x1f ;
V_21 [ V_27 ] |= ( 0x1f & V_103 ) ;
V_101:
return V_9 ;
}
int F_30 ( struct V_1 * V_2 , T_1 * V_97 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned char * V_21 = V_5 -> V_22 ;
T_2 V_103 ;
int V_9 = F_26 ( V_2 , V_108 , V_97 , & V_103 ) ;
if ( F_23 ( V_9 ) )
goto V_101;
V_21 [ V_30 ] &= ~ 0x07 ;
V_21 [ V_30 ] |= ( 0x07 & V_103 ) ;
V_101:
return V_9 ;
}
int F_31 ( struct V_1 * V_2 , T_1 * V_97 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned char * V_21 = V_5 -> V_22 ;
T_2 V_103 ;
int V_9 = F_26 ( V_2 , V_109 , V_97 , & V_103 ) ;
if ( V_9 < 0 )
goto V_101;
V_21 [ V_54 ] = V_103 ;
V_101:
return V_9 ;
}
void F_32 ( struct V_4 * V_110 , const char * V_111 ,
const char * V_112 , const char * V_113 , ... )
{
struct V_114 V_115 ;
T_3 args ;
va_start ( args , V_113 ) ;
V_115 . V_113 = V_113 ;
V_115 . V_116 = & args ;
if ( V_110 )
F_33 ( L_46 ,
V_111 , V_112 , F_18 ( V_110 -> V_68 . V_72 ) ,
V_110 -> V_68 . V_67 ,
( V_110 -> V_117 == V_118 ) ? 'M' : 'S' ,
& V_115 ) ;
else
F_33 ( L_47 , V_111 , V_112 , & V_115 ) ;
va_end ( args ) ;
}
