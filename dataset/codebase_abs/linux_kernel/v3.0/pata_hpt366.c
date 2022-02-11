static int F_1 ( const struct V_1 * V_2 , char * V_3 ,
const char * const V_4 [] )
{
unsigned char V_5 [ V_6 + 1 ] ;
int V_7 = 0 ;
F_2 ( V_2 -> V_8 , V_5 , V_9 , sizeof( V_5 ) ) ;
while ( V_4 [ V_7 ] != NULL ) {
if ( ! strcmp ( V_4 [ V_7 ] , V_5 ) ) {
F_3 ( L_1 ,
V_3 , V_4 [ V_7 ] ) ;
return 1 ;
}
V_7 ++ ;
}
return 0 ;
}
static unsigned long F_4 ( struct V_1 * V_10 , unsigned long V_11 )
{
if ( V_10 -> V_12 == V_13 ) {
if ( F_1 ( V_10 , L_2 , V_14 ) )
V_11 &= ~ V_15 ;
if ( F_1 ( V_10 , L_3 , V_16 ) )
V_11 &= ~ ( 0xF8 << V_17 ) ;
if ( F_1 ( V_10 , L_4 , V_18 ) )
V_11 &= ~ ( 0xF0 << V_17 ) ;
} else if ( V_10 -> V_12 == V_19 )
V_11 &= ~ ( V_20 | V_15 ) ;
return V_11 ;
}
static int F_5 ( struct V_21 * V_22 )
{
struct V_23 * V_24 = F_6 ( V_22 -> V_25 -> V_2 ) ;
T_1 V_26 ;
F_7 ( V_24 , 0x5A , & V_26 ) ;
if ( V_26 & 2 )
return V_27 ;
return V_28 ;
}
static void F_8 ( struct V_21 * V_22 , struct V_1 * V_10 ,
T_1 V_29 )
{
struct V_30 * V_31 = V_22 -> V_25 -> V_32 ;
struct V_23 * V_24 = F_6 ( V_22 -> V_25 -> V_2 ) ;
T_2 V_33 = 0x40 + 4 * V_10 -> V_34 ;
T_2 V_11 , V_35 ;
if ( V_29 < V_36 )
V_11 = 0xc1f8ffff ;
else if ( V_29 < V_37 )
V_11 = 0x303800ff ;
else
V_11 = 0x30070000 ;
while ( V_31 -> V_38 ) {
if ( V_31 -> V_38 == V_29 )
break;
V_31 ++ ;
}
if ( ! V_31 -> V_38 )
F_9 () ;
F_10 ( V_24 , V_33 , & V_35 ) ;
V_35 = ( ( V_35 & ~ V_11 ) | ( V_31 -> V_39 & V_11 ) ) & ~ 0xc0000000 ;
F_11 ( V_24 , V_33 , V_35 ) ;
}
static void F_12 ( struct V_21 * V_22 , struct V_1 * V_10 )
{
F_8 ( V_22 , V_10 , V_10 -> V_40 ) ;
}
static void F_13 ( struct V_21 * V_22 , struct V_1 * V_10 )
{
F_8 ( V_22 , V_10 , V_10 -> V_41 ) ;
}
static void F_14 ( struct V_23 * V_2 )
{
T_1 V_42 ;
F_15 ( V_2 , V_43 , ( V_44 / 4 ) ) ;
F_15 ( V_2 , V_45 , 0x78 ) ;
F_15 ( V_2 , V_46 , 0x08 ) ;
F_15 ( V_2 , V_47 , 0x08 ) ;
F_7 ( V_2 , 0x51 , & V_42 ) ;
if ( V_42 & 0x80 )
F_15 ( V_2 , 0x51 , V_42 & ~ 0x80 ) ;
}
static int F_16 ( struct V_23 * V_2 , const struct V_48 * V_8 )
{
static const struct V_49 V_50 = {
. V_51 = V_52 ,
. V_53 = V_54 ,
. V_55 = V_56 ,
. V_57 = V_58 ,
. V_59 = & V_60
} ;
const struct V_49 * V_61 [] = { & V_50 , NULL } ;
void * V_62 = NULL ;
T_2 V_63 ;
int V_64 ;
V_64 = F_17 ( V_2 ) ;
if ( V_64 )
return V_64 ;
if ( V_2 -> V_65 > 2 )
return - V_66 ;
F_14 ( V_2 ) ;
F_10 ( V_2 , 0x40 , & V_63 ) ;
switch ( ( V_63 & 0x700 ) >> 8 ) {
case 9 :
V_62 = & V_67 ;
break;
case 5 :
V_62 = & V_68 ;
break;
default:
V_62 = & V_69 ;
break;
}
return F_18 ( V_2 , V_61 , & V_70 , V_62 , 0 ) ;
}
static int F_19 ( struct V_23 * V_2 )
{
struct V_71 * V_25 = F_20 ( & V_2 -> V_2 ) ;
int V_64 ;
V_64 = F_21 ( V_2 ) ;
if ( V_64 )
return V_64 ;
F_14 ( V_2 ) ;
F_22 ( V_25 ) ;
return 0 ;
}
static int T_3 F_23 ( void )
{
return F_24 ( & V_72 ) ;
}
static void T_4 F_25 ( void )
{
F_26 ( & V_72 ) ;
}
