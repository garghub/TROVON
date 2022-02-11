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
static int F_15 ( struct V_39 * V_39 , void * V_40 ,
struct V_41 * V_42 )
{
struct V_1 * V_2 = F_16 ( V_39 ) ;
struct V_43 * V_44 = & V_2 -> V_45 ;
F_17 ( V_42 -> V_46 , V_44 -> V_44 . V_46 -> V_47 , sizeof( V_42 -> V_46 ) ) ;
F_17 ( V_42 -> V_48 , V_44 -> V_47 , sizeof( V_42 -> V_48 ) ) ;
snprintf ( V_42 -> V_49 , sizeof( V_42 -> V_49 ) ,
L_2 , F_18 ( & V_44 -> V_44 ) ) ;
V_42 -> V_50 = V_51 | V_52 ;
V_42 -> V_53 = V_42 -> V_50 | V_54 ;
return 0 ;
}
static int F_19 ( struct V_39 * V_39 , void * V_40 ,
struct V_55 * V_42 )
{
struct V_1 * V_2 = F_16 ( V_39 ) ;
struct V_16 * V_19 = & V_2 -> V_5 ;
if ( V_42 -> V_56 > 0 )
return - V_57 ;
F_17 ( V_42 -> V_47 , L_3 , sizeof( V_42 -> V_47 ) ) ;
V_42 -> type = V_58 ;
F_1 ( V_2 ) ;
V_42 -> V_59 = V_60 * V_61 ;
V_42 -> V_62 = V_63 * V_61 ;
V_42 -> V_64 = V_65 | V_66 ;
if ( V_19 -> V_67 & V_68 )
V_42 -> V_69 = V_70 ;
else
V_42 -> V_69 = V_71 ;
V_42 -> V_34 = F_13 ( V_2 ) ;
V_42 -> signal = F_20 ( V_19 -> V_67 ) * 0xffff / 0xf ;
V_42 -> V_72 = F_21 ( V_19 -> V_67 ) ;
return 0 ;
}
static int F_22 ( struct V_39 * V_39 , void * V_40 ,
const struct V_55 * V_42 )
{
struct V_1 * V_2 = F_16 ( V_39 ) ;
if ( V_42 -> V_56 > 0 )
return - V_57 ;
F_12 ( V_2 , V_42 -> V_34 ) ;
return 0 ;
}
static int F_23 ( struct V_39 * V_39 , void * V_40 ,
const struct V_73 * V_74 )
{
struct V_1 * V_2 = F_16 ( V_39 ) ;
unsigned V_32 = V_74 -> V_75 ;
if ( V_74 -> V_76 != 0 || V_74 -> type != V_58 )
return - V_57 ;
if ( V_32 == 0 ) {
F_7 ( V_2 ) ;
return - V_57 ;
}
V_32 = F_24 ( V_32 , V_60 * V_61 , V_63 * V_61 ) ;
F_6 ( V_2 ) ;
F_10 ( V_2 , ( V_32 * 125 ) / 2 ) ;
return 0 ;
}
static int F_25 ( struct V_39 * V_39 , void * V_40 ,
struct V_73 * V_74 )
{
struct V_1 * V_2 = F_16 ( V_39 ) ;
struct V_16 * V_19 = & V_2 -> V_5 ;
if ( V_74 -> V_76 != 0 )
return - V_57 ;
F_1 ( V_2 ) ;
V_74 -> type = V_58 ;
if ( V_19 -> V_22 & V_26 )
V_74 -> V_75 = ( F_9 ( V_2 ) * 2 ) / 125 ;
else
V_74 -> V_75 = 0 ;
return 0 ;
}
static int F_26 ( struct V_77 * V_78 )
{
struct V_1 * V_2 =
F_27 ( V_78 -> V_79 , struct V_1 , V_80 ) ;
switch ( V_78 -> V_81 ) {
case V_82 :
F_14 ( V_2 , V_78 -> V_83 ) ;
return 0 ;
}
return - V_57 ;
}
static int F_28 ( struct V_9 * V_84 ,
const struct V_85 * V_81 )
{
struct V_1 * V_2 ;
struct V_86 * V_87 ;
struct V_88 * V_89 ;
struct V_16 * V_19 ;
int V_90 ;
F_29 ( L_4 ) ;
V_2 = F_30 ( sizeof( struct V_1 ) , V_91 ) ;
if ( ! V_2 )
return - V_92 ;
V_87 = & V_2 -> V_87 ;
V_90 = F_31 ( & V_84 -> V_44 , V_87 ) ;
if ( V_90 < 0 ) {
F_32 ( V_87 , L_5 ) ;
goto V_93;
}
V_89 = & V_2 -> V_80 ;
F_33 ( V_89 , 1 ) ;
F_34 ( V_89 , & V_94 ,
V_82 , 0 , 1 , 1 , 1 ) ;
V_87 -> V_80 = V_89 ;
if ( V_89 -> error ) {
V_90 = V_89 -> error ;
F_32 ( V_87 , L_6 ) ;
goto V_95;
}
F_35 ( & V_2 -> V_96 ) ;
V_2 -> V_9 = V_84 ;
V_90 = F_1 ( V_2 ) ;
if ( V_90 )
goto V_95;
V_19 = & V_2 -> V_5 ;
F_29 ( L_7 , V_19 -> V_97 , V_19 -> V_98 ) ;
if ( V_19 -> V_97 != V_99 ||
( V_19 -> V_98 & 0x0fff ) != V_100 ) {
F_11 ( L_8 ) ;
V_90 = - V_57 ;
goto V_95;
}
V_2 -> V_45 = V_101 ;
F_36 ( V_84 , V_2 ) ;
F_37 ( & V_2 -> V_45 , V_2 ) ;
V_2 -> V_45 . V_102 = & V_2 -> V_96 ;
V_2 -> V_45 . V_87 = V_87 ;
F_38 ( V_103 , & V_2 -> V_45 . V_10 ) ;
F_1 ( V_2 ) ;
F_12 ( V_2 , V_37 ) ;
F_14 ( V_2 , 1 ) ;
F_7 ( V_2 ) ;
V_90 = F_39 ( & V_2 -> V_45 , V_104 , V_105 ) ;
if ( V_90 < 0 ) {
F_11 ( L_9 ) ;
goto V_95;
}
F_40 ( L_10 ) ;
return 0 ;
V_95:
F_41 ( V_89 ) ;
F_42 ( V_87 ) ;
V_93:
F_43 ( V_2 ) ;
return V_90 ;
}
static int F_44 ( struct V_9 * V_84 )
{
struct V_1 * V_2 = F_45 ( V_84 ) ;
F_29 ( L_11 ) ;
if ( V_2 ) {
F_7 ( V_2 ) ;
F_46 ( & V_2 -> V_45 ) ;
F_41 ( & V_2 -> V_80 ) ;
F_42 ( & V_2 -> V_87 ) ;
F_43 ( V_2 ) ;
}
return 0 ;
}
