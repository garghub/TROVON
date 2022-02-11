static T_1 F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 -> V_7 ;
while ( V_5 -> V_8 ) {
if ( V_5 -> V_8 == V_3 )
return V_5 -> V_9 ;
V_5 ++ ;
}
F_2 () ;
return 0xffffffffU ;
}
static int F_3 ( const struct V_10 * V_11 , char * V_12 ,
const char * const V_13 [] )
{
unsigned char V_14 [ V_15 + 1 ] ;
int V_16 = 0 ;
F_4 ( V_11 -> V_17 , V_14 , V_18 , sizeof( V_14 ) ) ;
while ( V_13 [ V_16 ] != NULL ) {
if ( ! strcmp ( V_13 [ V_16 ] , V_14 ) ) {
F_5 ( L_1 ,
V_12 , V_13 [ V_16 ] ) ;
return 1 ;
}
V_16 ++ ;
}
return 0 ;
}
static unsigned long F_6 ( struct V_10 * V_19 , unsigned long V_20 )
{
if ( V_19 -> V_21 == V_22 ) {
if ( F_3 ( V_19 , L_2 , V_23 ) )
V_20 &= ~ V_24 ;
if ( F_3 ( V_19 , L_3 , V_25 ) )
V_20 &= ~ ( 0xF8 << V_26 ) ;
if ( F_3 ( V_19 , L_4 , V_27 ) )
V_20 &= ~ ( 0xF0 << V_26 ) ;
} else if ( V_19 -> V_21 == V_28 )
V_20 &= ~ ( V_29 | V_24 ) ;
return V_20 ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_30 * V_31 = F_8 ( V_2 -> V_6 -> V_11 ) ;
T_2 V_32 ;
F_9 ( V_31 , 0x5A , & V_32 ) ;
if ( V_32 & 2 )
return V_33 ;
return V_34 ;
}
static void F_10 ( struct V_1 * V_2 , struct V_10 * V_19 ,
T_2 V_35 )
{
struct V_30 * V_31 = F_8 ( V_2 -> V_6 -> V_11 ) ;
T_1 V_36 = 0x40 + 4 * V_19 -> V_37 ;
T_1 V_20 , V_38 , V_39 ;
if ( V_35 < V_40 )
V_20 = 0xc1f8ffff ;
else if ( V_35 < V_41 )
V_20 = 0x303800ff ;
else
V_20 = 0x30070000 ;
V_39 = F_1 ( V_2 , V_35 ) ;
F_11 ( V_31 , V_36 , & V_38 ) ;
V_38 = ( ( V_38 & ~ V_20 ) | ( V_39 & V_20 ) ) & ~ 0xc0000000 ;
F_12 ( V_31 , V_36 , V_38 ) ;
}
static void F_13 ( struct V_1 * V_2 , struct V_10 * V_19 )
{
F_10 ( V_2 , V_19 , V_19 -> V_42 ) ;
}
static void F_14 ( struct V_1 * V_2 , struct V_10 * V_19 )
{
F_10 ( V_2 , V_19 , V_19 -> V_43 ) ;
}
static void F_15 ( struct V_30 * V_11 )
{
T_2 V_44 ;
F_16 ( V_11 , V_45 , ( V_46 / 4 ) ) ;
F_16 ( V_11 , V_47 , 0x78 ) ;
F_16 ( V_11 , V_48 , 0x08 ) ;
F_16 ( V_11 , V_49 , 0x08 ) ;
F_9 ( V_11 , 0x51 , & V_44 ) ;
if ( V_44 & 0x80 )
F_16 ( V_11 , 0x51 , V_44 & ~ 0x80 ) ;
}
static int F_17 ( struct V_30 * V_11 , const struct V_50 * V_17 )
{
static const struct V_51 V_52 = {
. V_53 = V_54 ,
. V_55 = V_56 ,
. V_57 = V_58 ,
. V_59 = V_60 ,
. V_61 = & V_62
} ;
const struct V_51 * V_63 [] = { & V_52 , NULL } ;
void * V_64 = NULL ;
T_1 V_65 ;
int V_66 ;
V_66 = F_18 ( V_11 ) ;
if ( V_66 )
return V_66 ;
if ( V_11 -> V_67 > 2 )
return - V_68 ;
F_15 ( V_11 ) ;
F_11 ( V_11 , 0x40 , & V_65 ) ;
switch ( ( V_65 & 0x700 ) >> 8 ) {
case 9 :
V_64 = & V_69 ;
break;
case 5 :
V_64 = & V_70 ;
break;
default:
V_64 = & V_71 ;
break;
}
return F_19 ( V_11 , V_63 , & V_72 , V_64 , 0 ) ;
}
static int F_20 ( struct V_30 * V_11 )
{
struct V_73 * V_6 = F_21 ( V_11 ) ;
int V_66 ;
V_66 = F_22 ( V_11 ) ;
if ( V_66 )
return V_66 ;
F_15 ( V_11 ) ;
F_23 ( V_6 ) ;
return 0 ;
}
