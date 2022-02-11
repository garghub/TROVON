static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
T_1 * V_4 = ( T_1 * ) & V_2 -> V_5 ;
struct V_6 V_7 [ 1 ] = {
{ . V_8 = V_2 -> V_9 -> V_8 ,
. V_10 = V_11 ,
. V_12 = sizeof( V_2 -> V_5 ) ,
. V_13 = ( void * ) & V_2 -> V_5
} ,
} ;
if ( F_2 ( V_2 -> V_9 -> V_14 , V_7 , 1 ) != 1 )
return - V_15 ;
for ( V_3 = 0 ; V_3 < sizeof( struct V_16 ) / sizeof( T_1 ) ; V_3 ++ )
V_4 [ V_3 ] = F_3 ( V_4 [ V_3 ] ) ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 )
{
struct V_17 V_18 ;
struct V_16 * V_19 = & V_2 -> V_5 ;
struct V_6 V_7 [ 1 ] = {
{
. V_8 = V_2 -> V_9 -> V_8 ,
. V_12 = sizeof( V_18 ) ,
. V_13 = ( void * ) & V_18
} ,
} ;
V_18 . V_20 = V_19 -> V_20 & 0xff ;
V_18 . V_21 = F_5 ( V_19 -> V_21 ) ;
V_18 . V_22 = F_5 ( V_19 -> V_22 ) ;
V_18 . V_23 = F_5 ( V_19 -> V_23 ) ;
V_18 . V_24 = F_5 ( V_19 -> V_24 ) ;
V_18 . V_25 = F_5 ( V_19 -> V_25 ) ;
if ( F_2 ( V_2 -> V_9 -> V_14 , V_7 , 1 ) != 1 )
return - V_15 ;
return 0 ;
}
static void F_6 ( struct V_1 * V_2 )
{
struct V_16 * V_19 = & V_2 -> V_5 ;
if ( ! ( V_19 -> V_22 & V_26 ) ) {
V_19 -> V_22 &= ~ ( V_27 | V_28 |
V_29 ) ;
if ( ! V_30 )
V_19 -> V_23 |= V_31 ;
else
V_19 -> V_23 &= ~ V_31 ;
V_19 -> V_22 |= V_26 ;
F_4 ( V_2 ) ;
}
}
static void F_7 ( struct V_1 * V_2 )
{
struct V_16 * V_19 = & V_2 -> V_5 ;
if ( V_19 -> V_22 & V_26 ) {
V_19 -> V_22 &= ~ V_26 ;
F_4 ( V_2 ) ;
}
}
static void F_8 ( struct V_1 * V_2 , int V_32 )
{
struct V_16 * V_19 = & V_2 -> V_5 ;
if ( V_19 -> V_22 & V_29 )
V_19 -> V_21 = ( V_32 + 225000 ) / 8192 ;
else
V_19 -> V_21 = ( V_32 - 225000 ) / 8192 ;
}
static int F_9 ( struct V_1 * V_2 )
{
struct V_16 * V_19 = & V_2 -> V_5 ;
if ( V_19 -> V_22 & V_29 )
return ( V_19 -> V_33 * 8192 ) - 225000 ;
else
return ( V_19 -> V_33 * 8192 ) + 225000 ;
}
static void F_10 ( struct V_1 * V_2 , int V_32 )
{
F_8 ( V_2 , V_32 ) ;
if ( F_4 ( V_2 ) )
F_11 ( L_1 ) ;
}
static void F_12 ( struct V_1 * V_2 , int V_34 )
{
struct V_16 * V_19 = & V_2 -> V_5 ;
int V_22 = V_19 -> V_22 ;
if ( V_34 == V_35 )
V_19 -> V_22 |= V_36 ;
else
V_19 -> V_22 &= ~ V_36 ;
if ( V_22 != V_19 -> V_22 )
F_4 ( V_2 ) ;
}
static int F_13 ( struct V_1 * V_2 )
{
struct V_16 * V_19 = & V_2 -> V_5 ;
if ( V_19 -> V_22 & V_36 )
return V_35 ;
else
return V_37 ;
}
static void F_14 ( struct V_1 * V_2 , int V_38 )
{
struct V_16 * V_19 = & V_2 -> V_5 ;
int V_22 = V_19 -> V_22 ;
if ( V_38 )
V_19 -> V_22 |= V_28 ;
else
V_19 -> V_22 &= ~ V_28 ;
if ( V_22 != V_19 -> V_22 )
F_4 ( V_2 ) ;
}
static int F_15 ( struct V_1 * V_2 )
{
return V_2 -> V_5 . V_22 & V_28 ;
}
static int F_16 ( struct V_39 * V_39 , void * V_40 ,
struct V_41 * V_42 )
{
struct V_1 * V_2 = F_17 ( V_39 ) ;
struct V_43 * V_44 = V_2 -> V_45 ;
F_18 ( V_42 -> V_46 , V_44 -> V_44 . V_46 -> V_47 , sizeof( V_42 -> V_46 ) ) ;
F_18 ( V_42 -> V_48 , V_44 -> V_47 , sizeof( V_42 -> V_48 ) ) ;
snprintf ( V_42 -> V_49 , sizeof( V_42 -> V_49 ) ,
L_2 , F_19 ( & V_44 -> V_44 ) ) ;
V_42 -> V_50 = V_51 | V_52 ;
return 0 ;
}
static int F_20 ( struct V_39 * V_39 , void * V_40 ,
struct V_53 * V_42 )
{
struct V_1 * V_2 = F_17 ( V_39 ) ;
struct V_16 * V_19 = & V_2 -> V_5 ;
if ( V_42 -> V_54 > 0 )
return - V_55 ;
memset ( V_42 , 0 , sizeof( * V_42 ) ) ;
strcpy ( V_42 -> V_47 , L_3 ) ;
V_42 -> type = V_56 ;
F_1 ( V_2 ) ;
V_42 -> V_57 = V_58 * V_59 ;
V_42 -> V_60 = V_61 * V_59 ;
V_42 -> V_62 = V_63 | V_64 ;
if ( V_19 -> V_65 & V_66 )
V_42 -> V_67 = V_68 ;
else
V_42 -> V_67 = V_69 ;
V_42 -> V_34 = F_13 ( V_2 ) ;
V_42 -> signal = F_21 ( V_19 -> V_65 ) * 0xffff / 0xf ;
V_42 -> V_70 = F_22 ( V_19 -> V_65 ) ;
return 0 ;
}
static int F_23 ( struct V_39 * V_39 , void * V_40 ,
struct V_53 * V_42 )
{
struct V_1 * V_2 = F_17 ( V_39 ) ;
if ( V_42 -> V_54 > 0 )
return - V_55 ;
F_12 ( V_2 , V_42 -> V_34 ) ;
return 0 ;
}
static int F_24 ( struct V_39 * V_39 , void * V_40 ,
struct V_71 * V_72 )
{
struct V_1 * V_2 = F_17 ( V_39 ) ;
if ( V_72 -> V_73 != 0 || V_72 -> type != V_56 )
return - V_55 ;
if ( V_72 -> V_74 == 0 ) {
F_7 ( V_2 ) ;
}
if ( V_72 -> V_74 < ( V_58 * V_59 ) )
return - V_55 ;
if ( V_72 -> V_74 > ( V_61 * V_59 ) )
return - V_55 ;
F_6 ( V_2 ) ;
F_10 ( V_2 , ( V_72 -> V_74 * 125 ) / 2 ) ;
return 0 ;
}
static int F_25 ( struct V_39 * V_39 , void * V_40 ,
struct V_71 * V_72 )
{
struct V_1 * V_2 = F_17 ( V_39 ) ;
struct V_16 * V_19 = & V_2 -> V_5 ;
if ( V_72 -> V_73 != 0 )
return - V_55 ;
F_1 ( V_2 ) ;
memset ( V_72 , 0 , sizeof( * V_72 ) ) ;
V_72 -> type = V_56 ;
if ( V_19 -> V_22 & V_26 )
V_72 -> V_74 = ( F_9 ( V_2 ) * 2 ) / 125 ;
else
V_72 -> V_74 = 0 ;
return 0 ;
}
static int F_26 ( struct V_39 * V_39 , void * V_40 ,
struct V_75 * V_76 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < F_27 ( V_77 ) ; V_3 ++ ) {
if ( V_76 -> V_78 && V_76 -> V_78 == V_77 [ V_3 ] . V_78 ) {
memcpy ( V_76 , & ( V_77 [ V_3 ] ) , sizeof( * V_76 ) ) ;
return 0 ;
}
}
return - V_55 ;
}
static int F_28 ( struct V_39 * V_39 , void * V_40 ,
struct V_79 * V_80 )
{
struct V_1 * V_2 = F_17 ( V_39 ) ;
switch ( V_80 -> V_78 ) {
case V_81 :
F_1 ( V_2 ) ;
V_80 -> V_82 = F_15 ( V_2 ) ? 1 : 0 ;
return 0 ;
}
return - V_55 ;
}
static int F_29 ( struct V_39 * V_39 , void * V_40 ,
struct V_79 * V_80 )
{
struct V_1 * V_2 = F_17 ( V_39 ) ;
switch ( V_80 -> V_78 ) {
case V_81 :
F_14 ( V_2 , V_80 -> V_82 ) ;
return 0 ;
}
return - V_55 ;
}
static int F_30 ( struct V_39 * V_83 , void * V_40 , unsigned int * V_3 )
{
* V_3 = 0 ;
return 0 ;
}
static int F_31 ( struct V_39 * V_83 , void * V_40 , unsigned int V_3 )
{
if ( V_3 != 0 )
return - V_55 ;
return 0 ;
}
static int F_32 ( struct V_39 * V_39 , void * V_40 ,
struct V_84 * V_85 )
{
if ( V_85 -> V_54 > 1 )
return - V_55 ;
strcpy ( V_85 -> V_47 , L_4 ) ;
V_85 -> V_62 = V_86 ;
return 0 ;
}
static int F_33 ( struct V_39 * V_39 , void * V_40 ,
const struct V_84 * V_85 )
{
if ( V_85 -> V_54 != 0 )
return - V_55 ;
return 0 ;
}
static int F_34 ( struct V_9 * V_87 ,
const struct V_88 * V_78 )
{
struct V_1 * V_2 ;
struct V_16 * V_19 ;
int V_89 ;
F_35 ( L_5 ) ;
V_2 = F_36 ( sizeof( struct V_1 ) , V_90 ) ;
if ( ! V_2 )
return - V_91 ;
F_37 ( & V_2 -> V_92 ) ;
V_2 -> V_9 = V_87 ;
V_89 = F_1 ( V_2 ) ;
if ( V_89 )
goto V_93;
V_19 = & V_2 -> V_5 ;
F_35 ( L_6 , V_19 -> V_94 , V_19 -> V_95 ) ;
if ( V_19 -> V_94 != V_96 ||
( V_19 -> V_95 & 0x0fff ) != V_97 ) {
F_11 ( L_7 ) ;
V_89 = - V_55 ;
goto V_93;
}
V_2 -> V_45 = F_38 () ;
if ( ! ( V_2 -> V_45 ) ) {
V_89 = - V_91 ;
goto V_93;
}
memcpy ( V_2 -> V_45 , & V_98 ,
sizeof( V_98 ) ) ;
F_39 ( V_87 , V_2 ) ;
F_40 ( V_2 -> V_45 , V_2 ) ;
V_2 -> V_45 -> V_99 = & V_2 -> V_92 ;
F_1 ( V_2 ) ;
F_12 ( V_2 , V_37 ) ;
F_14 ( V_2 , 1 ) ;
F_7 ( V_2 ) ;
V_89 = F_41 ( V_2 -> V_45 , V_100 , V_101 ) ;
if ( V_89 < 0 ) {
F_11 ( L_8 ) ;
goto V_102;
}
F_42 ( L_9 ) ;
return 0 ;
V_102:
F_43 ( V_2 -> V_45 ) ;
V_93:
F_44 ( V_2 ) ;
return V_89 ;
}
static int F_45 ( struct V_9 * V_87 )
{
struct V_1 * V_2 = F_46 ( V_87 ) ;
F_35 ( L_10 ) ;
if ( V_2 ) {
F_7 ( V_2 ) ;
F_47 ( V_2 -> V_45 ) ;
F_44 ( V_2 ) ;
}
return 0 ;
}
