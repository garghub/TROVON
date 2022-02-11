static void F_1 ( struct V_1 * V_2 )
{
unsigned int V_3 = V_2 -> V_3 ;
if ( V_3 >= F_2 ( 0 ) ) {
F_3 ( ( F_4 ( V_4 ) |
( 1 << ( V_3 - F_2 ( 0 ) ) ) ) ,
V_4 ) ;
} else if ( V_3 >= F_5 ( 0 ) ) {
F_3 ( ( F_4 ( V_5 ) |
( 1 << ( V_3 - F_5 ( 0 ) ) ) ) ,
V_5 ) ;
} else if ( V_3 >= F_6 ( 0 ) ) {
F_3 ( ( F_4 ( V_6 ) |
( 1 << ( V_3 - F_6 ( 0 ) ) ) ) ,
V_6 ) ;
}
}
static void F_7 ( struct V_1 * V_2 )
{
unsigned int V_3 = V_2 -> V_3 ;
if ( V_3 >= F_2 ( 0 ) ) {
F_3 ( ( F_4 ( V_4 ) &
~ ( 1 << ( V_3 - F_2 ( 0 ) ) ) ) ,
V_4 ) ;
} else if ( V_3 >= F_5 ( 0 ) ) {
F_3 ( ( F_4 ( V_5 ) &
~ ( 1 << ( V_3 - F_5 ( 0 ) ) ) ) ,
V_5 ) ;
} else if ( V_3 >= F_6 ( 0 ) ) {
F_3 ( ( F_4 ( V_6 ) &
~ ( 1 << ( V_3 - F_6 ( 0 ) ) ) ) ,
V_6 ) ;
}
}
void F_8 ( void )
{
int V_3 ;
F_3 ( ( 0xffff ) , V_6 ) ;
F_3 ( ( 0 ) , V_7 ) ;
F_3 ( ( 0xffff ) , V_5 ) ;
F_3 ( ( 0 ) , V_8 ) ;
F_3 ( ( 0xffff ) , V_4 ) ;
F_3 ( ( 0 ) , V_9 ) ;
for ( V_3 = F_9 ( 0 ) ; V_3 <= V_10 ; V_3 ++ ) {
F_10 ( V_3 , & V_11 ,
V_12 ) ;
F_11 ( V_3 , V_13 | V_14 ) ;
}
}
void F_12 ( unsigned int V_3 , struct V_15 * V_16 )
{
int V_17 , V_18 , V_19 ;
int V_20 ;
while ( 1 ) {
V_17 = F_4 ( V_7 ) ;
V_18 = F_4 ( V_8 ) ;
V_19 = F_4 ( V_9 ) ;
F_3 ( ( ~ V_17 ) , V_7 ) ;
F_3 ( ( ~ V_18 ) , V_8 ) ;
F_3 ( ( ~ V_19 ) , V_9 ) ;
if ( ! ( V_19 | V_18 | V_17 ) ) {
V_17 = F_4 ( V_7 ) ;
V_18 = F_4 ( V_8 ) ;
V_19 = F_4 ( V_9 ) ;
if ( ! ( V_19 | V_18 | V_17 ) )
return;
}
V_17 &= ( ( 1 << V_21 ) - 1 ) ;
while ( V_17 ) {
V_20 = F_13 ( V_17 ) ;
F_14 ( F_6 ( V_20 ) ) ;
V_17 &= ~ ( 1 << V_20 ) ;
}
V_18 &= ( ( 1 << V_22 ) - 1 ) ;
while ( V_18 ) {
V_20 = F_13 ( V_18 ) ;
F_14 ( F_5 ( V_20 ) ) ;
V_18 &= ~ ( 1 << V_20 ) ;
}
V_19 &= ( ( 1 << V_23 ) - 1 ) ;
while ( V_19 ) {
V_20 = F_13 ( V_19 ) ;
F_14 ( F_2 ( V_20 ) ) ;
V_19 &= ~ ( 1 << V_20 ) ;
}
}
}
int T_1 F_15 ( const struct V_24 * V_25 , T_2 V_26 , T_2 V_27 )
{
if ( ( V_25 -> V_28 == V_29 ) &&
( V_25 -> V_30 == V_31 ) ) {
if ( ( V_25 -> V_32 >> 8 ) == V_33 )
return V_34 ;
if ( ( V_25 -> V_32 >> 8 ) == V_35 )
return V_36 ;
if ( ( V_25 -> V_32 >> 8 ) == V_37 )
return V_38 ;
}
return 0 ;
}
static unsigned long F_16 ( struct V_39 * V_40 ,
unsigned int V_41 )
{
unsigned long V_42 = 0 ;
if ( V_40 -> V_43 == 0 ) {
if ( V_41 < F_17 ( V_44 , 0 ) )
V_42 = ( V_41 << 8 ) ;
} else
V_42 = ( V_40 -> V_43 << 16 ) | ( V_41 << 8 ) ;
return V_42 ;
}
static int F_18 ( struct V_39 * V_40 ,
unsigned int V_41 , int V_45 ,
int V_46 , T_3 * V_47 )
{
unsigned long V_42 = F_16 ( V_40 , V_41 ) ;
T_3 V_48 ;
int V_49 ;
V_49 = ( V_45 & 3 ) ;
F_3 ( ( V_42 + V_45 ) , V_50 ) ;
V_48 = ( F_4 ( V_51 ) >> ( 8 * ( V_49 ) ) ) ;
* V_47 = V_48 ;
return V_52 ;
}
static int F_19 ( struct V_39 * V_40 ,
unsigned int V_41 , int V_45 ,
int V_46 , T_3 V_47 )
{
unsigned long V_42 = F_16 ( V_40 , V_41 ) ;
T_3 V_48 , V_53 , V_54 = 0 ;
int V_49 ;
if ( V_46 == 1 )
V_54 = 0xff ;
if ( V_46 == 2 )
V_54 = 0xffff ;
V_49 = ( V_45 & 3 ) ;
F_3 ( ( V_42 + V_45 ) , V_50 ) ;
V_53 = F_4 ( V_51 ) ;
if ( V_54 )
V_53 &= ~ ( V_54 << ( 8 * V_49 ) ) ;
else
V_53 = 0 ;
V_48 = ( V_47 << ( 8 * V_49 ) ) ;
F_3 ( ( V_42 + V_45 ) , V_50 ) ;
F_3 ( ( V_48 | V_53 ) , V_51 ) ;
return V_52 ;
}
static int F_20 ( struct V_30 * V_25 , T_4 V_55 , T_5 V_46 )
{
F_21 ( V_25 , L_1 ,
V_56 , V_55 , V_46 ) ;
return ( V_55 + V_46 - V_57 ) >= V_58 ;
}
static int F_22 ( struct V_30 * V_25 )
{
if ( V_25 -> V_40 == & V_59 ) {
if ( V_25 -> V_60 )
* V_25 -> V_60 = ( V_58 - 1 ) | V_57 ;
V_25 -> V_61 = ( V_58 - 1 ) | V_57 ;
F_23 ( V_25 , 2048 , 4096 , F_20 ) ;
}
return 0 ;
}
static int F_24 ( struct V_30 * V_25 )
{
if ( V_25 -> V_40 == & V_59 )
F_25 ( V_25 ) ;
return 0 ;
}
int F_26 ( struct V_30 * V_25 , T_6 V_54 )
{
if ( V_54 >= V_57 + V_58 - 1 )
return 0 ;
return - V_62 ;
}
int T_1 F_27 ( int V_63 , struct V_64 * V_65 )
{
V_66 . V_67 = V_68 + 0x12000 ;
V_66 . V_69 = V_68 + 0x12000 + 0x100000 ;
V_65 -> V_70 = 0x10000000 ;
V_65 -> V_71 = V_68 ;
if ( F_28 ( & V_72 , & V_66 ) ) {
F_29 ( V_73 L_2 ) ;
goto V_74;
}
if ( F_28 ( & V_75 , & V_76 ) ) {
F_29 ( V_73 L_3 ) ;
goto V_77;
}
V_65 -> V_78 [ 0 ] = & V_66 ;
V_65 -> V_78 [ 1 ] = & V_76 ;
if ( V_79 || V_80 ) {
F_29 ( V_73 L_4 ) ;
goto V_81;
}
V_79 = F_22 ;
V_80 = F_24 ;
return 1 ;
V_81:
F_30 ( & V_66 ) ;
V_77:
F_30 ( & V_76 ) ;
V_74:
return - V_82 ;
}
void F_31 ( struct V_24 * V_25 )
{
T_2 V_83 ;
if ( ( V_25 -> V_28 == V_29 ) &&
( V_25 -> V_30 == V_31 ) &&
( ( V_25 -> V_32 >> 8 ) == V_35 ) )
return;
F_32 ( V_25 , V_84 , & V_83 ) ;
if ( V_83 < 16 )
V_83 = ( 64 <= V_85 ) ? 64 : V_85 ;
else if ( V_83 > V_85 )
V_83 = V_85 ;
else
return;
F_29 ( V_86 L_5 ,
F_33 ( V_25 ) , V_83 ) ;
F_34 ( V_25 , V_84 , V_83 ) ;
}
struct V_39 * T_1 F_35 ( int V_63 , struct V_64 * V_65 )
{
return F_36 ( V_63 , & V_87 , V_65 ) ;
}
