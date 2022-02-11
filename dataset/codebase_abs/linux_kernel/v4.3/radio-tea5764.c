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
V_4 [ V_3 ] = F_3 ( ( V_17 V_18 ) V_4 [ V_3 ] ) ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 )
{
struct V_19 V_20 ;
struct V_16 * V_21 = & V_2 -> V_5 ;
struct V_6 V_7 [ 1 ] = {
{
. V_8 = V_2 -> V_9 -> V_8 ,
. V_12 = sizeof( V_20 ) ,
. V_13 = ( void * ) & V_20
} ,
} ;
V_20 . V_22 = V_21 -> V_22 & 0xff ;
V_20 . V_23 = F_5 ( V_21 -> V_23 ) ;
V_20 . V_24 = F_5 ( V_21 -> V_24 ) ;
V_20 . V_25 = F_5 ( V_21 -> V_25 ) ;
V_20 . V_26 = F_5 ( V_21 -> V_26 ) ;
V_20 . V_27 = F_5 ( V_21 -> V_27 ) ;
if ( F_2 ( V_2 -> V_9 -> V_14 , V_7 , 1 ) != 1 )
return - V_15 ;
return 0 ;
}
static void F_6 ( struct V_1 * V_2 )
{
struct V_16 * V_21 = & V_2 -> V_5 ;
if ( ! ( V_21 -> V_24 & V_28 ) ) {
V_21 -> V_24 &= ~ ( V_29 | V_30 |
V_31 ) ;
if ( ! V_32 )
V_21 -> V_25 |= V_33 ;
else
V_21 -> V_25 &= ~ V_33 ;
V_21 -> V_24 |= V_28 ;
F_4 ( V_2 ) ;
}
}
static void F_7 ( struct V_1 * V_2 )
{
struct V_16 * V_21 = & V_2 -> V_5 ;
if ( V_21 -> V_24 & V_28 ) {
V_21 -> V_24 &= ~ V_28 ;
F_4 ( V_2 ) ;
}
}
static void F_8 ( struct V_1 * V_2 , int V_34 )
{
struct V_16 * V_21 = & V_2 -> V_5 ;
if ( V_21 -> V_24 & V_31 )
V_21 -> V_23 = ( V_34 + 225000 ) / 8192 ;
else
V_21 -> V_23 = ( V_34 - 225000 ) / 8192 ;
}
static int F_9 ( struct V_1 * V_2 )
{
struct V_16 * V_21 = & V_2 -> V_5 ;
if ( V_21 -> V_24 & V_31 )
return ( V_21 -> V_35 * 8192 ) - 225000 ;
else
return ( V_21 -> V_35 * 8192 ) + 225000 ;
}
static void F_10 ( struct V_1 * V_2 , int V_34 )
{
F_8 ( V_2 , V_34 ) ;
if ( F_4 ( V_2 ) )
F_11 ( L_1 ) ;
}
static void F_12 ( struct V_1 * V_2 , int V_36 )
{
struct V_16 * V_21 = & V_2 -> V_5 ;
int V_24 = V_21 -> V_24 ;
if ( V_36 == V_37 )
V_21 -> V_24 |= V_38 ;
else
V_21 -> V_24 &= ~ V_38 ;
if ( V_24 != V_21 -> V_24 )
F_4 ( V_2 ) ;
}
static int F_13 ( struct V_1 * V_2 )
{
struct V_16 * V_21 = & V_2 -> V_5 ;
if ( V_21 -> V_24 & V_38 )
return V_37 ;
else
return V_39 ;
}
static void F_14 ( struct V_1 * V_2 , int V_40 )
{
struct V_16 * V_21 = & V_2 -> V_5 ;
int V_24 = V_21 -> V_24 ;
if ( V_40 )
V_21 -> V_24 |= V_30 ;
else
V_21 -> V_24 &= ~ V_30 ;
if ( V_24 != V_21 -> V_24 )
F_4 ( V_2 ) ;
}
static int F_15 ( struct V_41 * V_41 , void * V_42 ,
struct V_43 * V_44 )
{
struct V_1 * V_2 = F_16 ( V_41 ) ;
struct V_45 * V_46 = & V_2 -> V_47 ;
F_17 ( V_44 -> V_48 , V_46 -> V_46 . V_48 -> V_49 , sizeof( V_44 -> V_48 ) ) ;
F_17 ( V_44 -> V_50 , V_46 -> V_49 , sizeof( V_44 -> V_50 ) ) ;
snprintf ( V_44 -> V_51 , sizeof( V_44 -> V_51 ) ,
L_2 , F_18 ( & V_46 -> V_46 ) ) ;
V_44 -> V_52 = V_53 | V_54 ;
V_44 -> V_55 = V_44 -> V_52 | V_56 ;
return 0 ;
}
static int F_19 ( struct V_41 * V_41 , void * V_42 ,
struct V_57 * V_44 )
{
struct V_1 * V_2 = F_16 ( V_41 ) ;
struct V_16 * V_21 = & V_2 -> V_5 ;
if ( V_44 -> V_58 > 0 )
return - V_59 ;
F_17 ( V_44 -> V_49 , L_3 , sizeof( V_44 -> V_49 ) ) ;
V_44 -> type = V_60 ;
F_1 ( V_2 ) ;
V_44 -> V_61 = V_62 * V_63 ;
V_44 -> V_64 = V_65 * V_63 ;
V_44 -> V_66 = V_67 | V_68 ;
if ( V_21 -> V_69 & V_70 )
V_44 -> V_71 = V_72 ;
else
V_44 -> V_71 = V_73 ;
V_44 -> V_36 = F_13 ( V_2 ) ;
V_44 -> signal = F_20 ( V_21 -> V_69 ) * 0xffff / 0xf ;
V_44 -> V_74 = F_21 ( V_21 -> V_69 ) ;
return 0 ;
}
static int F_22 ( struct V_41 * V_41 , void * V_42 ,
const struct V_57 * V_44 )
{
struct V_1 * V_2 = F_16 ( V_41 ) ;
if ( V_44 -> V_58 > 0 )
return - V_59 ;
F_12 ( V_2 , V_44 -> V_36 ) ;
return 0 ;
}
static int F_23 ( struct V_41 * V_41 , void * V_42 ,
const struct V_75 * V_76 )
{
struct V_1 * V_2 = F_16 ( V_41 ) ;
unsigned V_34 = V_76 -> V_77 ;
if ( V_76 -> V_78 != 0 || V_76 -> type != V_60 )
return - V_59 ;
if ( V_34 == 0 ) {
F_7 ( V_2 ) ;
return - V_59 ;
}
V_34 = F_24 ( V_34 , V_62 * V_63 , V_65 * V_63 ) ;
F_6 ( V_2 ) ;
F_10 ( V_2 , ( V_34 * 125 ) / 2 ) ;
return 0 ;
}
static int F_25 ( struct V_41 * V_41 , void * V_42 ,
struct V_75 * V_76 )
{
struct V_1 * V_2 = F_16 ( V_41 ) ;
struct V_16 * V_21 = & V_2 -> V_5 ;
if ( V_76 -> V_78 != 0 )
return - V_59 ;
F_1 ( V_2 ) ;
V_76 -> type = V_60 ;
if ( V_21 -> V_24 & V_28 )
V_76 -> V_77 = ( F_9 ( V_2 ) * 2 ) / 125 ;
else
V_76 -> V_77 = 0 ;
return 0 ;
}
static int F_26 ( struct V_79 * V_80 )
{
struct V_1 * V_2 =
F_27 ( V_80 -> V_81 , struct V_1 , V_82 ) ;
switch ( V_80 -> V_83 ) {
case V_84 :
F_14 ( V_2 , V_80 -> V_85 ) ;
return 0 ;
}
return - V_59 ;
}
static int F_28 ( struct V_9 * V_86 ,
const struct V_87 * V_83 )
{
struct V_1 * V_2 ;
struct V_88 * V_89 ;
struct V_90 * V_91 ;
struct V_16 * V_21 ;
int V_92 ;
F_29 ( L_4 ) ;
V_2 = F_30 ( sizeof( struct V_1 ) , V_93 ) ;
if ( ! V_2 )
return - V_94 ;
V_89 = & V_2 -> V_89 ;
V_92 = F_31 ( & V_86 -> V_46 , V_89 ) ;
if ( V_92 < 0 ) {
F_32 ( V_89 , L_5 ) ;
goto V_95;
}
V_91 = & V_2 -> V_82 ;
F_33 ( V_91 , 1 ) ;
F_34 ( V_91 , & V_96 ,
V_84 , 0 , 1 , 1 , 1 ) ;
V_89 -> V_82 = V_91 ;
if ( V_91 -> error ) {
V_92 = V_91 -> error ;
F_32 ( V_89 , L_6 ) ;
goto V_97;
}
F_35 ( & V_2 -> V_98 ) ;
V_2 -> V_9 = V_86 ;
V_92 = F_1 ( V_2 ) ;
if ( V_92 )
goto V_97;
V_21 = & V_2 -> V_5 ;
F_29 ( L_7 , V_21 -> V_99 , V_21 -> V_100 ) ;
if ( V_21 -> V_99 != V_101 ||
( V_21 -> V_100 & 0x0fff ) != V_102 ) {
F_11 ( L_8 ) ;
V_92 = - V_59 ;
goto V_97;
}
V_2 -> V_47 = V_103 ;
F_36 ( V_86 , V_2 ) ;
F_37 ( & V_2 -> V_47 , V_2 ) ;
V_2 -> V_47 . V_104 = & V_2 -> V_98 ;
V_2 -> V_47 . V_89 = V_89 ;
F_1 ( V_2 ) ;
F_12 ( V_2 , V_39 ) ;
F_14 ( V_2 , 1 ) ;
F_7 ( V_2 ) ;
V_92 = F_38 ( & V_2 -> V_47 , V_105 , V_106 ) ;
if ( V_92 < 0 ) {
F_11 ( L_9 ) ;
goto V_97;
}
F_39 ( L_10 ) ;
return 0 ;
V_97:
F_40 ( V_91 ) ;
F_41 ( V_89 ) ;
V_95:
F_42 ( V_2 ) ;
return V_92 ;
}
static int F_43 ( struct V_9 * V_86 )
{
struct V_1 * V_2 = F_44 ( V_86 ) ;
F_29 ( L_11 ) ;
if ( V_2 ) {
F_7 ( V_2 ) ;
F_45 ( & V_2 -> V_47 ) ;
F_40 ( & V_2 -> V_82 ) ;
F_41 ( & V_2 -> V_89 ) ;
F_42 ( V_2 ) ;
}
return 0 ;
}
