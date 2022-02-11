int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
T_1 * V_4 = ( T_1 * ) & V_2 -> V_5 ;
struct V_6 V_7 [ 1 ] = {
{ V_2 -> V_8 -> V_9 , V_10 , sizeof( V_2 -> V_5 ) ,
( void * ) & V_2 -> V_5 } ,
} ;
if ( F_2 ( V_2 -> V_8 -> V_11 , V_7 , 1 ) != 1 )
return - V_12 ;
for ( V_3 = 0 ; V_3 < sizeof( struct V_13 ) / sizeof( T_1 ) ; V_3 ++ )
V_4 [ V_3 ] = F_3 ( V_4 [ V_3 ] ) ;
return 0 ;
}
int F_4 ( struct V_1 * V_2 )
{
struct V_14 V_15 ;
struct V_13 * V_16 = & V_2 -> V_5 ;
struct V_6 V_7 [ 1 ] = {
{ V_2 -> V_8 -> V_9 , 0 , sizeof( V_15 ) , ( void * ) & V_15 } ,
} ;
V_15 . V_17 = V_16 -> V_17 & 0xff ;
V_15 . V_18 = F_5 ( V_16 -> V_18 ) ;
V_15 . V_19 = F_5 ( V_16 -> V_19 ) ;
V_15 . V_20 = F_5 ( V_16 -> V_20 ) ;
V_15 . V_21 = F_5 ( V_16 -> V_21 ) ;
V_15 . V_22 = F_5 ( V_16 -> V_22 ) ;
if ( F_2 ( V_2 -> V_8 -> V_11 , V_7 , 1 ) != 1 )
return - V_12 ;
return 0 ;
}
static void F_6 ( struct V_1 * V_2 )
{
struct V_13 * V_16 = & V_2 -> V_5 ;
if ( ! ( V_16 -> V_19 & V_23 ) ) {
V_16 -> V_19 &= ~ ( V_24 | V_25 |
V_26 ) ;
if ( ! V_27 )
V_16 -> V_20 |= V_28 ;
else
V_16 -> V_20 &= ~ V_28 ;
V_16 -> V_19 |= V_23 ;
F_4 ( V_2 ) ;
}
}
static void F_7 ( struct V_1 * V_2 )
{
struct V_13 * V_16 = & V_2 -> V_5 ;
if ( V_16 -> V_19 & V_23 ) {
V_16 -> V_19 &= ~ V_23 ;
F_4 ( V_2 ) ;
}
}
static void F_8 ( struct V_1 * V_2 , int V_29 )
{
struct V_13 * V_16 = & V_2 -> V_5 ;
if ( V_16 -> V_19 & V_26 )
V_16 -> V_18 = ( V_29 + 225000 ) / 8192 ;
else
V_16 -> V_18 = ( V_29 - 225000 ) / 8192 ;
}
static int F_9 ( struct V_1 * V_2 )
{
struct V_13 * V_16 = & V_2 -> V_5 ;
if ( V_16 -> V_19 & V_26 )
return ( V_16 -> V_30 * 8192 ) - 225000 ;
else
return ( V_16 -> V_30 * 8192 ) + 225000 ;
}
static void F_10 ( struct V_1 * V_2 , int V_29 )
{
F_8 ( V_2 , V_29 ) ;
if ( F_4 ( V_2 ) )
F_11 ( L_1 ) ;
}
static void F_12 ( struct V_1 * V_2 , int V_31 )
{
struct V_13 * V_16 = & V_2 -> V_5 ;
int V_19 = V_16 -> V_19 ;
if ( V_31 == V_32 )
V_16 -> V_19 |= V_33 ;
else
V_16 -> V_19 &= ~ V_33 ;
if ( V_19 != V_16 -> V_19 )
F_4 ( V_2 ) ;
}
static int F_13 ( struct V_1 * V_2 )
{
struct V_13 * V_16 = & V_2 -> V_5 ;
if ( V_16 -> V_19 & V_33 )
return V_32 ;
else
return V_34 ;
}
static void F_14 ( struct V_1 * V_2 , int V_35 )
{
struct V_13 * V_16 = & V_2 -> V_5 ;
int V_19 = V_16 -> V_19 ;
if ( V_35 )
V_16 -> V_19 |= V_25 ;
else
V_16 -> V_19 &= ~ V_25 ;
if ( V_19 != V_16 -> V_19 )
F_4 ( V_2 ) ;
}
static int F_15 ( struct V_1 * V_2 )
{
return V_2 -> V_5 . V_19 & V_25 ;
}
static int F_16 ( struct V_36 * V_36 , void * V_37 ,
struct V_38 * V_39 )
{
struct V_1 * V_2 = F_17 ( V_36 ) ;
struct V_40 * V_41 = V_2 -> V_42 ;
F_18 ( V_39 -> V_43 , V_41 -> V_41 . V_43 -> V_44 , sizeof( V_39 -> V_43 ) ) ;
F_18 ( V_39 -> V_45 , V_41 -> V_44 , sizeof( V_39 -> V_45 ) ) ;
snprintf ( V_39 -> V_46 , sizeof( V_39 -> V_46 ) ,
L_2 , F_19 ( & V_41 -> V_41 ) ) ;
V_39 -> V_47 = V_48 | V_49 ;
return 0 ;
}
static int F_20 ( struct V_36 * V_36 , void * V_37 ,
struct V_50 * V_39 )
{
struct V_1 * V_2 = F_17 ( V_36 ) ;
struct V_13 * V_16 = & V_2 -> V_5 ;
if ( V_39 -> V_51 > 0 )
return - V_52 ;
memset ( V_39 , 0 , sizeof( * V_39 ) ) ;
strcpy ( V_39 -> V_44 , L_3 ) ;
V_39 -> type = V_53 ;
F_1 ( V_2 ) ;
V_39 -> V_54 = V_55 * V_56 ;
V_39 -> V_57 = V_58 * V_56 ;
V_39 -> V_59 = V_60 | V_61 ;
if ( V_16 -> V_62 & V_63 )
V_39 -> V_64 = V_65 ;
else
V_39 -> V_64 = V_66 ;
V_39 -> V_31 = F_13 ( V_2 ) ;
V_39 -> signal = F_21 ( V_16 -> V_62 ) * 0xffff / 0xf ;
V_39 -> V_67 = F_22 ( V_16 -> V_62 ) ;
return 0 ;
}
static int F_23 ( struct V_36 * V_36 , void * V_37 ,
struct V_50 * V_39 )
{
struct V_1 * V_2 = F_17 ( V_36 ) ;
if ( V_39 -> V_51 > 0 )
return - V_52 ;
F_12 ( V_2 , V_39 -> V_31 ) ;
return 0 ;
}
static int F_24 ( struct V_36 * V_36 , void * V_37 ,
struct V_68 * V_69 )
{
struct V_1 * V_2 = F_17 ( V_36 ) ;
if ( V_69 -> V_70 != 0 || V_69 -> type != V_53 )
return - V_52 ;
if ( V_69 -> V_71 == 0 ) {
F_7 ( V_2 ) ;
}
if ( V_69 -> V_71 < ( V_55 * V_56 ) )
return - V_52 ;
if ( V_69 -> V_71 > ( V_58 * V_56 ) )
return - V_52 ;
F_6 ( V_2 ) ;
F_10 ( V_2 , ( V_69 -> V_71 * 125 ) / 2 ) ;
return 0 ;
}
static int F_25 ( struct V_36 * V_36 , void * V_37 ,
struct V_68 * V_69 )
{
struct V_1 * V_2 = F_17 ( V_36 ) ;
struct V_13 * V_16 = & V_2 -> V_5 ;
if ( V_69 -> V_70 != 0 )
return - V_52 ;
F_1 ( V_2 ) ;
memset ( V_69 , 0 , sizeof( * V_69 ) ) ;
V_69 -> type = V_53 ;
if ( V_16 -> V_19 & V_23 )
V_69 -> V_71 = ( F_9 ( V_2 ) * 2 ) / 125 ;
else
V_69 -> V_71 = 0 ;
return 0 ;
}
static int F_26 ( struct V_36 * V_36 , void * V_37 ,
struct V_72 * V_73 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < F_27 ( V_74 ) ; V_3 ++ ) {
if ( V_73 -> V_75 && V_73 -> V_75 == V_74 [ V_3 ] . V_75 ) {
memcpy ( V_73 , & ( V_74 [ V_3 ] ) , sizeof( * V_73 ) ) ;
return 0 ;
}
}
return - V_52 ;
}
static int F_28 ( struct V_36 * V_36 , void * V_37 ,
struct V_76 * V_77 )
{
struct V_1 * V_2 = F_17 ( V_36 ) ;
switch ( V_77 -> V_75 ) {
case V_78 :
F_1 ( V_2 ) ;
V_77 -> V_79 = F_15 ( V_2 ) ? 1 : 0 ;
return 0 ;
}
return - V_52 ;
}
static int F_29 ( struct V_36 * V_36 , void * V_37 ,
struct V_76 * V_77 )
{
struct V_1 * V_2 = F_17 ( V_36 ) ;
switch ( V_77 -> V_75 ) {
case V_78 :
F_14 ( V_2 , V_77 -> V_79 ) ;
return 0 ;
}
return - V_52 ;
}
static int F_30 ( struct V_36 * V_80 , void * V_37 , unsigned int * V_3 )
{
* V_3 = 0 ;
return 0 ;
}
static int F_31 ( struct V_36 * V_80 , void * V_37 , unsigned int V_3 )
{
if ( V_3 != 0 )
return - V_52 ;
return 0 ;
}
static int F_32 ( struct V_36 * V_36 , void * V_37 ,
struct V_81 * V_82 )
{
if ( V_82 -> V_51 > 1 )
return - V_52 ;
strcpy ( V_82 -> V_44 , L_4 ) ;
V_82 -> V_59 = V_83 ;
return 0 ;
}
static int F_33 ( struct V_36 * V_36 , void * V_37 ,
struct V_81 * V_82 )
{
if ( V_82 -> V_51 != 0 )
return - V_52 ;
return 0 ;
}
static int T_2 F_34 ( struct V_8 * V_84 ,
const struct V_85 * V_75 )
{
struct V_1 * V_2 ;
struct V_13 * V_16 ;
int V_86 ;
F_35 ( L_5 ) ;
V_2 = F_36 ( sizeof( struct V_1 ) , V_87 ) ;
if ( ! V_2 )
return - V_88 ;
F_37 ( & V_2 -> V_89 ) ;
V_2 -> V_8 = V_84 ;
V_86 = F_1 ( V_2 ) ;
if ( V_86 )
goto V_90;
V_16 = & V_2 -> V_5 ;
F_35 ( L_6 , V_16 -> V_91 , V_16 -> V_92 ) ;
if ( V_16 -> V_91 != V_93 ||
( V_16 -> V_92 & 0x0fff ) != V_94 ) {
F_11 ( L_7 ) ;
V_86 = - V_52 ;
goto V_90;
}
V_2 -> V_42 = F_38 () ;
if ( ! ( V_2 -> V_42 ) ) {
V_86 = - V_88 ;
goto V_90;
}
memcpy ( V_2 -> V_42 , & V_95 ,
sizeof( V_95 ) ) ;
F_39 ( V_84 , V_2 ) ;
F_40 ( V_2 -> V_42 , V_2 ) ;
V_2 -> V_42 -> V_96 = & V_2 -> V_89 ;
F_1 ( V_2 ) ;
F_12 ( V_2 , V_34 ) ;
F_14 ( V_2 , 1 ) ;
F_7 ( V_2 ) ;
V_86 = F_41 ( V_2 -> V_42 , V_97 , V_98 ) ;
if ( V_86 < 0 ) {
F_11 ( L_8 ) ;
goto V_99;
}
F_42 ( L_9 ) ;
return 0 ;
V_99:
F_43 ( V_2 -> V_42 ) ;
V_90:
F_44 ( V_2 ) ;
return V_86 ;
}
static int T_3 F_45 ( struct V_8 * V_84 )
{
struct V_1 * V_2 = F_46 ( V_84 ) ;
F_35 ( L_10 ) ;
if ( V_2 ) {
F_7 ( V_2 ) ;
F_47 ( V_2 -> V_42 ) ;
F_44 ( V_2 ) ;
}
return 0 ;
}
