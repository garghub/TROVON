static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 , T_1 V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 -> V_8 -> V_7 ) ;
int V_9 = 2 * V_2 -> V_10 + V_4 -> V_11 ;
int V_12 = 0x44 + 2 * V_9 ;
unsigned long V_13 = 1000000000 / 33333 ;
struct V_14 V_15 ;
T_2 V_16 ;
T_1 V_17 ;
T_1 V_18 ;
F_3 ( V_4 , V_4 -> V_19 , & V_15 , V_13 , 0 ) ;
V_16 = 17 - F_4 ( V_15 . V_20 , 2 , 17 ) ;
V_16 |= ( 16 - F_4 ( V_15 . V_21 , 1 , 16 ) ) << 4 ;
V_16 |= ( V_16 << 8 ) ;
F_5 ( V_7 , V_12 , V_16 ) ;
F_6 ( V_7 , 0x42 , & V_17 ) ;
V_17 &= ~ ( 1 << ( 4 + V_9 ) ) ;
if ( V_5 >= V_22 || ! F_7 ( V_4 ) )
V_17 |= ( 1 << ( 4 + V_9 ) ) ;
F_6 ( V_7 , 0x43 , & V_18 ) ;
while ( V_18 & 0x03 ) {
F_8 ( 1 ) ;
F_6 ( V_7 , 0x43 , & V_18 ) ;
}
F_9 ( V_7 , 0x42 , V_17 ) ;
}
static void F_10 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_1 ( V_2 , V_4 , V_4 -> V_19 ) ;
}
static void F_11 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = V_24 -> V_2 ;
unsigned int V_25 = ( V_24 -> V_26 . V_27 & V_28 ) ;
T_1 V_29 ;
F_12 () ;
F_13 ( V_2 -> V_30 , V_2 -> V_31 . V_32 + V_33 ) ;
V_29 = F_14 ( V_2 -> V_31 . V_32 + V_34 ) ;
V_29 &= ~ ( V_35 | V_36 ) ;
V_29 |= V_37 | V_38 ;
if ( ! V_25 )
V_29 |= V_35 ;
F_15 ( V_29 , V_2 -> V_31 . V_32 + V_34 ) ;
V_2 -> V_39 -> V_40 ( V_2 , & V_24 -> V_26 ) ;
}
static void F_16 ( struct V_23 * V_24 )
{
F_1 ( V_24 -> V_2 , V_24 -> V_7 , V_24 -> V_7 -> V_41 ) ;
F_17 ( V_24 ) ;
}
static void F_18 ( struct V_23 * V_24 )
{
F_19 ( V_24 ) ;
F_1 ( V_24 -> V_2 , V_24 -> V_7 , V_24 -> V_7 -> V_19 ) ;
}
static void F_20 ( struct V_1 * V_2 )
{
void T_3 * V_42 = V_2 -> V_31 . V_32 ;
if ( ! V_42 )
return;
F_15 ( ( F_14 ( V_42 + V_34 ) | V_37 | V_38 ) ,
V_42 + V_34 ) ;
}
static int F_21 ( struct V_23 * V_24 )
{
return - V_43 ;
}
static T_1 F_22 ( void T_3 * V_44 )
{
T_1 V_45 ;
int V_46 = V_47 ;
do {
V_45 = F_14 ( V_44 ) ;
if ( V_45 != 0 )
return V_45 ;
F_8 ( 50 ) ;
} while( V_46 -- > 0 );
return V_45 ;
}
static T_1 F_23 ( struct V_1 * V_2 )
{
return F_22 ( V_2 -> V_31 . V_48 ) ;
}
void F_24 ( struct V_1 * V_2 , struct V_49 * V_26 )
{
struct V_50 * V_31 = & V_2 -> V_31 ;
V_26 -> V_51 = F_23 ( V_2 ) ;
V_26 -> V_52 = F_14 ( V_31 -> V_53 ) ;
V_26 -> V_54 = F_14 ( V_31 -> V_55 ) ;
V_26 -> V_56 = F_14 ( V_31 -> V_57 ) ;
V_26 -> V_58 = F_14 ( V_31 -> V_59 ) ;
V_26 -> V_60 = F_14 ( V_31 -> V_61 ) ;
V_26 -> V_62 = F_22 ( V_31 -> V_63 ) ;
if ( V_26 -> V_27 & V_64 ) {
F_15 ( V_26 -> V_65 | V_66 , V_31 -> V_67 ) ;
V_26 -> V_68 = F_14 ( V_31 -> V_53 ) ;
V_26 -> V_69 = F_14 ( V_31 -> V_55 ) ;
V_26 -> V_70 = F_14 ( V_31 -> V_57 ) ;
V_26 -> V_71 = F_14 ( V_31 -> V_59 ) ;
V_26 -> V_72 = F_14 ( V_31 -> V_61 ) ;
F_15 ( V_26 -> V_65 , V_31 -> V_67 ) ;
V_2 -> V_73 = V_26 -> V_65 ;
}
}
static T_1 F_25 ( struct V_1 * V_2 )
{
return F_22 ( V_2 -> V_31 . V_32 + V_74 ) ;
}
static void F_26 ( struct V_6 * V_75 )
{
F_9 ( V_75 , 0x55 , 0xEE ) ;
F_9 ( V_75 , 0x54 , 0xB7 ) ;
}
static int F_27 ( struct V_6 * V_75 , const struct V_76 * V_77 )
{
static const struct V_78 V_79 = {
. V_27 = V_80 ,
. V_81 = V_82 ,
. V_83 = V_84 ,
. V_85 = & V_86 ,
} ;
const struct V_78 * V_87 [] = { & V_79 , NULL } ;
int V_88 ;
#if F_28 ( V_89 )
static const struct V_78 V_90 = {
. V_27 = V_80 ,
. V_81 = V_82 ,
. V_83 = V_84 ,
. V_85 = & V_91 ,
} ;
if ( F_29 ( V_75 -> V_92 ) == 0x0E )
V_87 [ 0 ] = & V_90 ;
#endif
F_30 ( & V_75 -> V_7 , V_93 ) ;
V_88 = F_31 ( V_75 ) ;
if ( V_88 )
return V_88 ;
F_26 ( V_75 ) ;
return F_32 ( V_75 , V_87 , & V_94 , NULL , 0 ) ;
}
static int F_33 ( struct V_6 * V_75 )
{
struct V_95 * V_8 = F_34 ( & V_75 -> V_7 ) ;
int V_88 ;
V_88 = F_35 ( V_75 ) ;
if ( V_88 )
return V_88 ;
F_26 ( V_75 ) ;
F_36 ( V_8 ) ;
return 0 ;
}
static int T_4 F_37 ( void )
{
return F_38 ( & V_96 ) ;
}
static void T_5 F_39 ( void )
{
F_40 ( & V_96 ) ;
}
