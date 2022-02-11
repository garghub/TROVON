static int F_1 ( struct V_1 * V_2 ,
T_1 V_3 , int V_4 , int V_5 )
{
T_1 V_6 [] = { V_4 , V_5 } ;
struct V_7 V_8 = {
. V_9 = V_3 , . V_10 = 0 , . V_6 = V_6 , . V_11 = 2
} ;
int V_12 ;
V_12 = F_2 ( V_2 -> V_13 , & V_8 , 1 ) ;
if ( V_12 != 1 ) {
F_3 ( L_1
L_2 , V_14 , V_12 , V_4 , V_5 ) ;
return V_12 ;
}
return 0 ;
}
static int F_4 ( struct V_1 * V_2 ,
T_1 V_3 , struct V_15 * V_16 , int V_17 )
{
int V_18 , V_12 ;
for ( V_18 = 0 ; V_18 < V_17 ; V_18 ++ ) {
V_12 = F_1 ( V_2 , V_3 , V_16 [ V_18 ] . V_4 ,
V_16 [ V_18 ] . V_5 ) ;
if ( V_12 < 0 )
return V_12 ;
}
return 0 ;
}
static int F_5 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_4 )
{
T_1 V_19 ;
int V_12 ;
struct V_7 V_8 [] = {
{ . V_9 = V_3 , . V_10 = 0 , . V_6 = & V_4 , . V_11 = 1 } ,
{ . V_9 = V_3 , . V_10 = V_20 , . V_6 = & V_19 , . V_11 = 1 }
} ;
V_12 = F_2 ( V_2 -> V_13 , V_8 , 2 ) ;
if ( V_12 != 2 ) {
V_12 ( L_3 , V_14 , V_4 , V_12 ) ;
return V_12 ;
}
return V_19 ;
}
static int F_6 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
int V_12 ;
T_1 V_24 = 1 ;
F_7 ( L_4 ) ;
if ( V_22 -> V_25 . V_26 )
V_22 -> V_25 . V_26 ( V_22 , 0 ) ;
V_12 = F_8 ( V_2 , V_27 ) ;
if ( V_12 < 0 )
goto V_28;
if ( ! V_2 -> V_29 -> V_30 ) {
V_24 &= ~ 1 ;
V_12 = F_9 ( V_2 , 0x50 , 0xd5 ) ;
if ( V_12 < 0 )
goto V_28;
V_12 = F_9 ( V_2 , 0x51 , V_24 ) ;
if ( V_12 < 0 )
goto V_28;
}
if ( V_22 -> V_25 . V_26 )
V_22 -> V_25 . V_26 ( V_22 , 1 ) ;
V_28:
if ( V_12 < 0 ) {
V_2 -> V_31 = true ;
F_3 ( V_32 L_5 ) ;
} else {
V_2 -> V_31 = false ;
F_7 ( L_6 ) ;
}
return V_12 ;
}
static int F_10 ( struct V_21 * V_22 , T_2 * V_33 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
unsigned V_34 , V_35 , V_36 ;
T_1 V_19 ;
F_7 ( L_4 ) ;
if ( V_22 -> V_25 . V_26 )
V_22 -> V_25 . V_26 ( V_22 , 0 ) ;
V_34 = 0xfff ;
V_35 = 0 ;
do {
V_36 = ( V_34 + V_35 ) / 2 ;
F_9 ( V_2 , 0x04 , 0x1f ) ;
F_9 ( V_2 , 0x05 , V_36 >> 8 ) ;
F_9 ( V_2 , 0x04 , 0x20 ) ;
F_9 ( V_2 , 0x04 , V_36 ) ;
V_19 = F_11 ( V_2 , 0x02 ) ;
if ( V_19 & 0x08 )
V_35 = ( V_34 + V_35 ) / 2 ;
else
V_34 = ( V_34 + V_35 ) / 2 ;
if ( V_34 - V_35 < 4 ) {
* V_33 = ( ( ( V_34 + V_35 ) / 2 ) * 65535 ) / 4095 ;
break;
}
} while ( 1 );
F_7 ( L_7 , * V_33 ) ;
if ( V_22 -> V_25 . V_26 )
V_22 -> V_25 . V_26 ( V_22 , 1 ) ;
return 0 ;
}
static int F_12 ( struct V_21 * V_22 , T_3 * V_37 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
T_1 V_19 ;
F_7 ( L_4 ) ;
* V_37 = 0 ;
if ( V_22 -> V_25 . V_26 )
V_22 -> V_25 . V_26 ( V_22 , 0 ) ;
V_19 = F_11 ( V_2 , 0x0a ) & 0xf ;
if ( V_22 -> V_25 . V_26 )
V_22 -> V_25 . V_26 ( V_22 , 1 ) ;
if ( V_19 >= 2 )
* V_37 |= V_38 ;
if ( V_19 >= 4 )
* V_37 |= V_39 ;
if ( V_19 >= 5 )
* V_37 |= V_40 ;
if ( V_19 >= 7 )
* V_37 |= V_41 ;
if ( V_19 >= 8 )
* V_37 |= V_42 ;
F_7 ( L_8 , V_19 , * V_37 ) ;
return 0 ;
}
static int F_13 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
int V_12 ;
#if 0
struct dtv_frontend_properties *p = &fe->dtv_property_cache;
#endif
F_7 ( L_4 ) ;
if ( V_22 -> V_25 . V_26 )
V_22 -> V_25 . V_26 ( V_22 , 1 ) ;
F_7 ( L_9 ) ;
V_22 -> V_25 . V_43 . V_44 ( V_22 ) ;
if ( V_2 -> V_31 )
F_6 ( V_22 ) ;
if ( V_22 -> V_25 . V_26 )
V_22 -> V_25 . V_26 ( V_22 , 0 ) ;
V_12 = F_8 ( V_2 , V_45 ) ;
if ( V_22 -> V_25 . V_26 )
V_22 -> V_25 . V_26 ( V_22 , 1 ) ;
return V_12 ;
}
static int F_14 ( struct V_1 * V_2 ,
unsigned V_46 )
{
int V_12 ;
static unsigned char V_4 [] = {
[ 0 ] = 0x86 ,
[ 1 ] = 0x8a ,
[ 2 ] = 0x8e ,
} ;
if ( V_46 >= F_15 ( V_4 ) )
return - V_47 ;
V_12 = F_9 ( V_2 , 0x6d , V_4 [ V_46 ] ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_11 ( V_2 , 0x6e ) ;
if ( V_12 < 0 )
return V_12 ;
switch ( ( V_12 & 0x70 ) >> 4 ) {
case 0 :
return V_48 ;
case 1 :
return V_49 ;
case 2 :
return V_50 ;
case 3 :
return V_51 ;
default:
return V_52 ;
}
}
static int F_16 ( struct V_1 * V_2 ,
unsigned V_46 )
{
int V_12 ;
static unsigned char V_4 [] = {
[ 0 ] = 0x87 ,
[ 1 ] = 0x8b ,
[ 2 ] = 0x8f ,
} ;
if ( V_46 >= F_15 ( V_4 ) )
return - V_47 ;
V_12 = F_9 ( V_2 , 0x6d , V_4 [ V_46 ] ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_11 ( V_2 , 0x6e ) ;
if ( V_12 < 0 )
return V_12 ;
switch ( V_12 ) {
case 0 :
return V_53 ;
case 1 :
return V_54 ;
case 2 :
return V_55 ;
case 3 :
return V_56 ;
case 4 :
return V_57 ;
default:
return V_58 ;
}
}
static int F_17 ( struct V_1 * V_2 ,
unsigned V_46 )
{
int V_12 ;
static unsigned char V_4 [] = {
[ 0 ] = 0x88 ,
[ 1 ] = 0x8c ,
[ 2 ] = 0x90 ,
} ;
if ( V_46 >= F_15 ( V_4 ) )
return - V_47 ;
V_12 = F_9 ( V_2 , 0x6d , V_4 [ V_46 ] ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_11 ( V_2 , 0x6e ) ;
if ( V_12 < 0 )
return V_12 ;
if ( V_12 > 3 )
return - V_47 ;
return V_12 ;
}
static int F_18 ( struct V_1 * V_2 ,
unsigned V_46 )
{
int V_12 , V_59 ;
static unsigned char V_4 [] = {
[ 0 ] = 0x89 ,
[ 1 ] = 0x8d ,
[ 2 ] = 0x91 ,
} ;
if ( V_46 >= F_15 ( V_4 ) )
return - V_47 ;
V_12 = F_9 ( V_2 , 0x6d , V_4 [ V_46 ] ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_11 ( V_2 , 0x6e ) ;
if ( V_12 < 0 )
return V_12 ;
V_59 = ( V_12 >> 4 ) & 0x0f ;
return V_59 ;
}
static int F_19 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
struct V_60 * V_61 = & V_22 -> V_62 ;
int V_18 , V_12 ;
V_61 -> V_63 = V_64 ;
V_61 -> V_65 = 6000000 ;
if ( V_22 -> V_25 . V_26 )
V_22 -> V_25 . V_26 ( V_22 , 0 ) ;
V_12 = F_9 ( V_2 , 0x6d , 0x85 ) ;
if ( V_12 >= 0 )
V_12 = F_11 ( V_2 , 0x6e ) ;
if ( V_12 >= 0 )
V_61 -> V_66 = ( V_12 & 0x10 ) ? 1 : 0 ;
V_61 -> V_67 = 0 ;
for ( V_18 = 0 ; V_18 < 3 ; V_18 ++ ) {
V_12 = F_18 ( V_2 , V_18 ) ;
if ( V_12 >= 0 && V_12 < 14 )
V_61 -> V_46 [ V_18 ] . V_68 = V_12 ;
if ( V_12 == 0x0f )
continue;
V_61 -> V_67 |= 1 << V_18 ;
V_12 = F_14 ( V_2 , V_18 ) ;
if ( V_12 >= 0 )
V_61 -> V_46 [ V_18 ] . V_69 = V_12 ;
V_12 = F_16 ( V_2 , V_18 ) ;
if ( V_12 >= 0 )
V_61 -> V_46 [ V_18 ] . V_70 = V_12 ;
V_12 = F_17 ( V_2 , V_18 ) ;
if ( V_12 >= 0 )
V_61 -> V_46 [ V_18 ] . V_71 = V_12 ;
}
V_61 -> V_72 = 0 ;
V_12 = F_9 ( V_2 , 0x6d , 0x84 ) ;
if ( ( V_12 >= 0 ) && ( ( V_12 & 0x60 ) == 0x20 ) ) {
V_61 -> V_72 = 1 ;
if ( ! V_61 -> V_73 )
V_61 -> V_73 = 1 ;
} else
V_61 -> V_73 = 0 ;
V_61 -> V_74 = V_75 ;
V_61 -> V_76 = V_77 ;
V_12 = F_11 ( V_2 , 0x07 ) ;
if ( V_12 >= 0 ) {
if ( ( V_12 & 0x60 ) == 0x20 ) {
switch ( V_12 & 0x0c >> 2 ) {
case 0 :
V_61 -> V_74 = V_78 ;
break;
case 1 :
V_61 -> V_74 = V_79 ;
break;
case 2 :
V_61 -> V_74 = V_80 ;
break;
}
}
if ( ! ( V_12 & 0x10 ) ) {
switch ( V_12 & 0x3 ) {
case 0 :
V_61 -> V_76 = V_81 ;
break;
case 1 :
V_61 -> V_76 = V_82 ;
break;
case 2 :
V_61 -> V_76 = V_83 ;
break;
}
}
}
if ( V_22 -> V_25 . V_26 )
V_22 -> V_25 . V_26 ( V_22 , 1 ) ;
return 0 ;
}
static int F_20 ( struct V_21 * V_22 ,
bool V_84 ,
unsigned int V_85 ,
unsigned int * V_86 ,
T_3 * V_37 )
{
int V_12 = 0 ;
F_7 ( L_4 ) ;
if ( V_84 )
V_12 = F_13 ( V_22 ) ;
if ( ! ( V_85 & V_87 ) )
F_12 ( V_22 , V_37 ) ;
return V_12 ;
}
static void F_21 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
F_7 ( L_4 ) ;
F_22 ( V_2 ) ;
}
struct V_21 * F_23 ( const struct V_88 * V_29 ,
struct V_89 * V_13 )
{
T_1 V_90 ;
struct V_1 * V_2 =
F_24 ( sizeof( struct V_1 ) , V_91 ) ;
F_7 ( L_4 ) ;
if ( V_2 == NULL ) {
V_12 ( L_10 ) ;
goto error;
}
V_2 -> V_29 = V_29 ;
V_2 -> V_13 = V_13 ;
memcpy ( & V_2 -> V_92 . V_25 , & V_93 ,
sizeof( struct V_94 ) ) ;
V_2 -> V_92 . V_23 = V_2 ;
V_90 = F_11 ( V_2 , 0 ) ;
if ( V_90 == 0x13 ) {
F_3 ( V_32 L_11 ) ;
} else {
F_3 ( V_95 L_12 ,
V_90 ) ;
goto error;
}
return & V_2 -> V_92 ;
error:
F_22 ( V_2 ) ;
return NULL ;
}
