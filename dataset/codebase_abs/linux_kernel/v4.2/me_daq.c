static inline void F_1 ( unsigned V_1 )
{
F_2 ( V_1 * V_2 ) ;
}
static int F_3 ( struct V_3 * V_4 ,
struct V_5 * V_6 ,
struct V_7 * V_8 ,
unsigned int * V_9 )
{
struct V_10 * V_11 = V_4 -> V_12 ;
unsigned int V_13 = F_4 ( V_8 -> V_14 ) ;
unsigned int V_15 ;
int V_16 ;
if ( V_13 < 16 )
V_15 = 0x0000ffff ;
else
V_15 = 0xffff0000 ;
V_16 = F_5 ( V_4 , V_6 , V_8 , V_9 , V_15 ) ;
if ( V_16 )
return V_16 ;
if ( V_6 -> V_17 & 0x0000ffff )
V_11 -> V_18 |= V_19 ;
else
V_11 -> V_18 &= ~ V_19 ;
if ( V_6 -> V_17 & 0xffff0000 )
V_11 -> V_18 |= V_20 ;
else
V_11 -> V_18 &= ~ V_20 ;
F_6 ( V_11 -> V_18 , V_4 -> V_21 + V_22 ) ;
return V_8 -> V_23 ;
}
static int F_7 ( struct V_3 * V_4 ,
struct V_5 * V_6 ,
struct V_7 * V_8 ,
unsigned int * V_9 )
{
void T_1 * V_24 = V_4 -> V_21 + V_25 ;
void T_1 * V_26 = V_4 -> V_21 + V_27 ;
unsigned int V_15 ;
unsigned int V_28 ;
V_15 = F_8 ( V_6 , V_9 ) ;
if ( V_15 ) {
if ( V_15 & 0x0000ffff )
F_6 ( ( V_6 -> V_29 & 0xffff ) , V_24 ) ;
if ( V_15 & 0xffff0000 )
F_6 ( ( ( V_6 -> V_29 >> 16 ) & 0xffff ) , V_26 ) ;
}
if ( V_6 -> V_17 & 0x0000ffff )
V_28 = V_6 -> V_29 & 0xffff ;
else
V_28 = F_9 ( V_24 ) ;
if ( V_6 -> V_17 & 0xffff0000 )
V_28 |= ( V_6 -> V_29 & 0xffff0000 ) ;
else
V_28 |= ( F_9 ( V_26 ) << 16 ) ;
V_9 [ 1 ] = V_28 ;
return V_8 -> V_23 ;
}
static int F_10 ( struct V_3 * V_4 ,
struct V_5 * V_6 ,
struct V_7 * V_8 ,
unsigned long V_30 )
{
unsigned int V_31 ;
V_31 = F_9 ( V_4 -> V_21 + V_32 ) ;
if ( ( V_31 & 0x0004 ) == 0 )
return 0 ;
return - V_33 ;
}
static int F_11 ( struct V_3 * V_4 ,
struct V_5 * V_6 ,
struct V_7 * V_8 ,
unsigned int * V_9 )
{
struct V_10 * V_34 = V_4 -> V_12 ;
unsigned int V_13 = F_4 ( V_8 -> V_14 ) ;
unsigned int V_35 = F_12 ( V_8 -> V_14 ) ;
unsigned int V_36 = F_13 ( V_8 -> V_14 ) ;
unsigned short V_28 ;
int V_16 ;
V_34 -> V_37 &= 0xFFFC ;
F_6 ( V_34 -> V_37 , V_4 -> V_21 + V_38 ) ;
V_34 -> V_18 &= ~ ( V_39 | V_40 ) ;
F_6 ( V_34 -> V_18 , V_4 -> V_21 + V_22 ) ;
F_6 ( 0x00 , V_4 -> V_21 + V_41 ) ;
V_34 -> V_18 |= ( V_39 | V_40 ) ;
F_6 ( V_34 -> V_18 , V_4 -> V_21 + V_22 ) ;
V_28 = V_13 & 0x0f ;
V_28 |= ( V_35 & 0x03 ) << 4 ;
V_28 |= ( V_35 & 0x04 ) << 4 ;
V_28 |= ( ( V_36 & V_42 ) ? 0x80 : 0 ) ;
F_6 ( V_28 & 0xff , V_4 -> V_21 + V_43 ) ;
V_34 -> V_37 |= V_44 ;
F_6 ( V_34 -> V_37 , V_4 -> V_21 + V_38 ) ;
F_9 ( V_4 -> V_21 + V_45 ) ;
V_16 = F_14 ( V_4 , V_6 , V_8 , F_10 , 0 ) ;
if ( V_16 )
return V_16 ;
V_28 = F_9 ( V_4 -> V_21 + V_46 ) ;
V_28 = ( V_28 ^ 0x800 ) & 0x0fff ;
V_9 [ 0 ] = V_28 ;
V_34 -> V_37 &= 0xFFFC ;
F_6 ( V_34 -> V_37 , V_4 -> V_21 + V_38 ) ;
return 1 ;
}
static int F_15 ( struct V_3 * V_4 ,
struct V_5 * V_6 ,
struct V_7 * V_8 ,
unsigned int * V_9 )
{
struct V_10 * V_34 = V_4 -> V_12 ;
unsigned int V_13 = F_4 ( V_8 -> V_14 ) ;
unsigned int V_35 = F_12 ( V_8 -> V_14 ) ;
unsigned int V_28 = V_6 -> V_47 [ V_13 ] ;
int V_48 ;
V_34 -> V_18 |= V_49 ;
F_6 ( V_34 -> V_18 , V_4 -> V_21 + V_22 ) ;
V_34 -> V_18 |= V_50 ;
F_6 ( V_34 -> V_18 , V_4 -> V_21 + V_22 ) ;
for ( V_48 = 0 ; V_48 < V_8 -> V_23 ; V_48 ++ ) {
V_34 -> V_51 &= ~ ( 0x0880 >> V_13 ) ;
if ( V_35 == 0 )
V_34 -> V_51 |=
( ( V_52 | V_53 ) >> V_13 ) ;
else if ( V_35 == 1 )
V_34 -> V_51 |=
( ( V_52 | V_54 ) >> V_13 ) ;
}
F_6 ( V_34 -> V_51 , V_4 -> V_21 + V_55 ) ;
F_9 ( V_4 -> V_21 + V_56 ) ;
for ( V_48 = 0 ; V_48 < V_8 -> V_23 ; V_48 ++ ) {
V_28 = V_9 [ V_48 ] ;
F_6 ( V_28 , V_4 -> V_21 + V_57 + ( V_13 << 1 ) ) ;
}
V_6 -> V_47 [ V_13 ] = V_28 ;
F_9 ( V_4 -> V_21 + V_58 ) ;
return V_8 -> V_23 ;
}
static int F_16 ( struct V_3 * V_4 ,
const T_2 * V_9 , T_3 V_59 ,
unsigned long V_30 )
{
struct V_10 * V_34 = V_4 -> V_12 ;
unsigned int V_60 ;
unsigned int V_61 ;
unsigned int V_48 ;
F_17 ( 0x00 , V_34 -> V_62 + V_63 ) ;
V_60 = F_9 ( V_4 -> V_21 + V_64 ) ;
F_1 ( 1 ) ;
F_18 ( 0x00 , V_4 -> V_21 + 0x0 ) ;
F_1 ( 1 ) ;
if ( V_59 < 16 )
return - V_65 ;
V_61 = ( ( ( unsigned int ) V_9 [ 0 ] & 0xff ) << 24 ) +
( ( ( unsigned int ) V_9 [ 1 ] & 0xff ) << 16 ) +
( ( ( unsigned int ) V_9 [ 2 ] & 0xff ) << 8 ) +
( ( unsigned int ) V_9 [ 3 ] & 0xff ) ;
for ( V_48 = 0 ; V_48 < V_61 ; V_48 ++ )
F_18 ( ( V_9 [ 16 + V_48 ] & 0xff ) , V_4 -> V_21 + 0x0 ) ;
for ( V_48 = 0 ; V_48 < 5 ; V_48 ++ )
F_18 ( 0x00 , V_4 -> V_21 + 0x0 ) ;
V_60 = F_19 ( V_34 -> V_62 + V_63 ) ;
if ( V_60 & V_66 ) {
F_17 ( 0x00 , V_34 -> V_62 + V_63 ) ;
F_20 ( V_4 -> V_67 , L_1 ) ;
return - V_68 ;
}
F_1 ( 1 ) ;
F_17 ( V_69 |
V_70 |
V_71 ,
V_34 -> V_62 + V_63 ) ;
return 0 ;
}
static int F_21 ( struct V_3 * V_4 )
{
struct V_10 * V_34 = V_4 -> V_12 ;
F_6 ( 0x00 , V_4 -> V_21 + V_38 ) ;
F_6 ( 0x00 , V_4 -> V_21 + V_22 ) ;
F_6 ( 0x00 , V_4 -> V_21 + V_41 ) ;
F_6 ( 0x00 , V_4 -> V_21 + V_55 ) ;
V_34 -> V_51 = 0 ;
V_34 -> V_37 = 0 ;
V_34 -> V_18 = 0 ;
return 0 ;
}
static int F_22 ( struct V_3 * V_4 ,
unsigned long V_30 )
{
struct V_72 * V_73 = F_23 ( V_4 ) ;
const struct V_74 * V_75 = NULL ;
struct V_10 * V_34 ;
struct V_5 * V_6 ;
int V_16 ;
if ( V_30 < F_24 ( V_76 ) )
V_75 = & V_76 [ V_30 ] ;
if ( ! V_75 )
return - V_77 ;
V_4 -> V_78 = V_75 ;
V_4 -> V_79 = V_75 -> V_80 ;
V_34 = F_25 ( V_4 , sizeof( * V_34 ) ) ;
if ( ! V_34 )
return - V_81 ;
V_16 = F_26 ( V_4 ) ;
if ( V_16 )
return V_16 ;
V_34 -> V_62 = F_27 ( V_73 , 0 ) ;
if ( ! V_34 -> V_62 )
return - V_81 ;
V_4 -> V_21 = F_27 ( V_73 , 2 ) ;
if ( ! V_4 -> V_21 )
return - V_81 ;
if ( V_75 -> V_82 ) {
V_16 = F_28 ( V_4 , & F_23 ( V_4 ) -> V_4 ,
V_83 ,
F_16 , 0 ) ;
if ( V_16 < 0 )
return V_16 ;
}
F_21 ( V_4 ) ;
V_16 = F_29 ( V_4 , 3 ) ;
if ( V_16 )
return V_16 ;
V_6 = & V_4 -> V_84 [ 0 ] ;
V_6 -> type = V_85 ;
V_6 -> V_86 = V_87 | V_88 ;
V_6 -> V_89 = 16 ;
V_6 -> V_90 = 0x0fff ;
V_6 -> V_91 = 16 ;
V_6 -> V_92 = & V_93 ;
V_6 -> V_94 = F_11 ;
V_6 = & V_4 -> V_84 [ 1 ] ;
if ( V_75 -> V_95 ) {
V_6 -> type = V_96 ;
V_6 -> V_86 = V_97 | V_88 ;
V_6 -> V_89 = 4 ;
V_6 -> V_90 = 0x0fff ;
V_6 -> V_91 = 4 ;
V_6 -> V_92 = & V_98 ;
V_6 -> V_99 = F_15 ;
V_16 = F_30 ( V_6 ) ;
if ( V_16 )
return V_16 ;
} else {
V_6 -> type = V_100 ;
}
V_6 = & V_4 -> V_84 [ 2 ] ;
V_6 -> type = V_101 ;
V_6 -> V_86 = V_87 | V_97 ;
V_6 -> V_89 = 32 ;
V_6 -> V_90 = 1 ;
V_6 -> V_91 = 32 ;
V_6 -> V_92 = & V_102 ;
V_6 -> V_103 = F_7 ;
V_6 -> V_104 = F_3 ;
return 0 ;
}
static void F_31 ( struct V_3 * V_4 )
{
struct V_10 * V_34 = V_4 -> V_12 ;
if ( V_34 ) {
if ( V_4 -> V_21 )
F_21 ( V_4 ) ;
if ( V_34 -> V_62 )
F_32 ( V_34 -> V_62 ) ;
}
F_33 ( V_4 ) ;
}
static int F_34 ( struct V_72 * V_4 ,
const struct V_105 * V_106 )
{
return F_35 ( V_4 , & V_107 , V_106 -> V_108 ) ;
}
