static inline void F_1 ( unsigned V_1 )
{
F_2 ( V_2 ) ;
F_3 ( V_1 * V_3 ) ;
}
static int F_4 ( struct V_4 * V_5 ,
struct V_6 * V_7 ,
struct V_8 * V_9 ,
unsigned int * V_10 )
{
struct V_11 * V_12 = V_5 -> V_13 ;
unsigned int V_14 = F_5 ( V_9 -> V_15 ) ;
unsigned int V_16 ;
int V_17 ;
if ( V_14 < 16 )
V_16 = 0x0000ffff ;
else
V_16 = 0xffff0000 ;
V_17 = F_6 ( V_5 , V_7 , V_9 , V_10 , V_16 ) ;
if ( V_17 )
return V_17 ;
if ( V_7 -> V_18 & 0x0000ffff )
V_12 -> V_19 |= V_20 ;
else
V_12 -> V_19 &= ~ V_20 ;
if ( V_7 -> V_18 & 0xffff0000 )
V_12 -> V_19 |= V_21 ;
else
V_12 -> V_19 &= ~ V_21 ;
F_7 ( V_12 -> V_19 , V_5 -> V_22 + V_23 ) ;
return V_9 -> V_24 ;
}
static int F_8 ( struct V_4 * V_5 ,
struct V_6 * V_7 ,
struct V_8 * V_9 ,
unsigned int * V_10 )
{
void T_1 * V_25 = V_5 -> V_22 + V_26 ;
void T_1 * V_27 = V_5 -> V_22 + V_28 ;
unsigned int V_16 ;
unsigned int V_29 ;
V_16 = F_9 ( V_7 , V_10 ) ;
if ( V_16 ) {
if ( V_16 & 0x0000ffff )
F_7 ( ( V_7 -> V_30 & 0xffff ) , V_25 ) ;
if ( V_16 & 0xffff0000 )
F_7 ( ( ( V_7 -> V_30 >> 16 ) & 0xffff ) , V_27 ) ;
}
if ( V_7 -> V_18 & 0x0000ffff )
V_29 = V_7 -> V_30 & 0xffff ;
else
V_29 = F_10 ( V_25 ) ;
if ( V_7 -> V_18 & 0xffff0000 )
V_29 |= ( V_7 -> V_30 & 0xffff0000 ) ;
else
V_29 |= ( F_10 ( V_27 ) << 16 ) ;
V_10 [ 1 ] = V_29 ;
return V_9 -> V_24 ;
}
static int F_11 ( struct V_4 * V_5 ,
struct V_6 * V_7 ,
struct V_8 * V_9 ,
unsigned long V_31 )
{
unsigned int V_32 ;
V_32 = F_10 ( V_5 -> V_22 + V_33 ) ;
if ( ( V_32 & 0x0004 ) == 0 )
return 0 ;
return - V_34 ;
}
static int F_12 ( struct V_4 * V_5 ,
struct V_6 * V_7 ,
struct V_8 * V_9 ,
unsigned int * V_10 )
{
struct V_11 * V_35 = V_5 -> V_13 ;
unsigned int V_14 = F_5 ( V_9 -> V_15 ) ;
unsigned int V_36 = F_13 ( V_9 -> V_15 ) ;
unsigned int V_37 = F_14 ( V_9 -> V_15 ) ;
unsigned short V_29 ;
int V_17 ;
V_35 -> V_38 &= 0xFFFC ;
F_7 ( V_35 -> V_38 , V_5 -> V_22 + V_39 ) ;
V_35 -> V_19 &= ~ ( V_40 | V_41 ) ;
F_7 ( V_35 -> V_19 , V_5 -> V_22 + V_23 ) ;
F_7 ( 0x00 , V_5 -> V_22 + V_42 ) ;
V_35 -> V_19 |= ( V_40 | V_41 ) ;
F_7 ( V_35 -> V_19 , V_5 -> V_22 + V_23 ) ;
V_29 = V_14 & 0x0f ;
V_29 |= ( V_36 & 0x03 ) << 4 ;
V_29 |= ( V_36 & 0x04 ) << 4 ;
V_29 |= ( ( V_37 & V_43 ) ? 0x80 : 0 ) ;
F_7 ( V_29 & 0xff , V_5 -> V_22 + V_44 ) ;
V_35 -> V_38 |= V_45 ;
F_7 ( V_35 -> V_38 , V_5 -> V_22 + V_39 ) ;
F_10 ( V_5 -> V_22 + V_46 ) ;
V_17 = F_15 ( V_5 , V_7 , V_9 , F_11 , 0 ) ;
if ( V_17 )
return V_17 ;
V_29 = F_10 ( V_5 -> V_22 + V_47 ) ;
V_29 = ( V_29 ^ 0x800 ) & 0x0fff ;
V_10 [ 0 ] = V_29 ;
V_35 -> V_38 &= 0xFFFC ;
F_7 ( V_35 -> V_38 , V_5 -> V_22 + V_39 ) ;
return 1 ;
}
static int F_16 ( struct V_4 * V_5 ,
struct V_6 * V_7 ,
struct V_8 * V_9 ,
unsigned int * V_10 )
{
struct V_11 * V_35 = V_5 -> V_13 ;
unsigned int V_14 = F_5 ( V_9 -> V_15 ) ;
unsigned int V_36 = F_13 ( V_9 -> V_15 ) ;
unsigned int V_29 = V_7 -> V_48 [ V_14 ] ;
int V_49 ;
V_35 -> V_19 |= V_50 ;
F_7 ( V_35 -> V_19 , V_5 -> V_22 + V_23 ) ;
V_35 -> V_19 |= V_51 ;
F_7 ( V_35 -> V_19 , V_5 -> V_22 + V_23 ) ;
for ( V_49 = 0 ; V_49 < V_9 -> V_24 ; V_49 ++ ) {
V_35 -> V_52 &= ~ ( 0x0880 >> V_14 ) ;
if ( V_36 == 0 )
V_35 -> V_52 |=
( ( V_53 | V_54 ) >> V_14 ) ;
else if ( V_36 == 1 )
V_35 -> V_52 |=
( ( V_53 | V_55 ) >> V_14 ) ;
}
F_7 ( V_35 -> V_52 , V_5 -> V_22 + V_56 ) ;
F_10 ( V_5 -> V_22 + V_57 ) ;
for ( V_49 = 0 ; V_49 < V_9 -> V_24 ; V_49 ++ ) {
V_29 = V_10 [ V_49 ] ;
F_7 ( V_29 , V_5 -> V_22 + V_58 + ( V_14 << 1 ) ) ;
}
V_7 -> V_48 [ V_14 ] = V_29 ;
F_10 ( V_5 -> V_22 + V_59 ) ;
return V_9 -> V_24 ;
}
static int F_17 ( struct V_4 * V_5 ,
const T_2 * V_10 , T_3 V_60 ,
unsigned long V_31 )
{
struct V_11 * V_35 = V_5 -> V_13 ;
unsigned int V_61 ;
unsigned int V_62 ;
unsigned int V_49 ;
F_18 ( 0x00 , V_35 -> V_63 + V_64 ) ;
V_61 = F_10 ( V_5 -> V_22 + V_65 ) ;
F_1 ( 1 ) ;
F_19 ( 0x00 , V_5 -> V_22 + 0x0 ) ;
F_1 ( 1 ) ;
if ( V_60 < 16 )
return - V_66 ;
V_62 = ( ( ( unsigned int ) V_10 [ 0 ] & 0xff ) << 24 ) +
( ( ( unsigned int ) V_10 [ 1 ] & 0xff ) << 16 ) +
( ( ( unsigned int ) V_10 [ 2 ] & 0xff ) << 8 ) +
( ( unsigned int ) V_10 [ 3 ] & 0xff ) ;
for ( V_49 = 0 ; V_49 < V_62 ; V_49 ++ )
F_19 ( ( V_10 [ 16 + V_49 ] & 0xff ) , V_5 -> V_22 + 0x0 ) ;
for ( V_49 = 0 ; V_49 < 5 ; V_49 ++ )
F_19 ( 0x00 , V_5 -> V_22 + 0x0 ) ;
V_61 = F_20 ( V_35 -> V_63 + V_64 ) ;
if ( V_61 & V_67 ) {
F_18 ( 0x00 , V_35 -> V_63 + V_64 ) ;
F_21 ( V_5 -> V_68 , L_1 ) ;
return - V_69 ;
}
F_1 ( 1 ) ;
F_18 ( V_70 |
V_71 |
V_72 ,
V_35 -> V_63 + V_64 ) ;
return 0 ;
}
static int F_22 ( struct V_4 * V_5 )
{
struct V_11 * V_35 = V_5 -> V_13 ;
F_7 ( 0x00 , V_5 -> V_22 + V_39 ) ;
F_7 ( 0x00 , V_5 -> V_22 + V_23 ) ;
F_7 ( 0x00 , V_5 -> V_22 + V_42 ) ;
F_7 ( 0x00 , V_5 -> V_22 + V_56 ) ;
V_35 -> V_52 = 0 ;
V_35 -> V_38 = 0 ;
V_35 -> V_19 = 0 ;
return 0 ;
}
static int F_23 ( struct V_4 * V_5 ,
unsigned long V_31 )
{
struct V_73 * V_74 = F_24 ( V_5 ) ;
const struct V_75 * V_76 = NULL ;
struct V_11 * V_35 ;
struct V_6 * V_7 ;
int V_17 ;
if ( V_31 < F_25 ( V_77 ) )
V_76 = & V_77 [ V_31 ] ;
if ( ! V_76 )
return - V_78 ;
V_5 -> V_79 = V_76 ;
V_5 -> V_80 = V_76 -> V_81 ;
V_35 = F_26 ( V_5 , sizeof( * V_35 ) ) ;
if ( ! V_35 )
return - V_82 ;
V_17 = F_27 ( V_5 ) ;
if ( V_17 )
return V_17 ;
V_35 -> V_63 = F_28 ( V_74 , 0 ) ;
if ( ! V_35 -> V_63 )
return - V_82 ;
V_5 -> V_22 = F_28 ( V_74 , 2 ) ;
if ( ! V_5 -> V_22 )
return - V_82 ;
if ( V_76 -> V_83 ) {
V_17 = F_29 ( V_5 , & F_24 ( V_5 ) -> V_5 ,
V_84 ,
F_17 , 0 ) ;
if ( V_17 < 0 )
return V_17 ;
}
F_22 ( V_5 ) ;
V_17 = F_30 ( V_5 , 3 ) ;
if ( V_17 )
return V_17 ;
V_7 = & V_5 -> V_85 [ 0 ] ;
V_7 -> type = V_86 ;
V_7 -> V_87 = V_88 | V_89 ;
V_7 -> V_90 = 16 ;
V_7 -> V_91 = 0x0fff ;
V_7 -> V_92 = 16 ;
V_7 -> V_93 = & V_94 ;
V_7 -> V_95 = F_12 ;
V_7 = & V_5 -> V_85 [ 1 ] ;
if ( V_76 -> V_96 ) {
V_7 -> type = V_97 ;
V_7 -> V_87 = V_98 | V_89 ;
V_7 -> V_90 = 4 ;
V_7 -> V_91 = 0x0fff ;
V_7 -> V_92 = 4 ;
V_7 -> V_93 = & V_99 ;
V_7 -> V_100 = F_16 ;
V_17 = F_31 ( V_7 ) ;
if ( V_17 )
return V_17 ;
} else {
V_7 -> type = V_101 ;
}
V_7 = & V_5 -> V_85 [ 2 ] ;
V_7 -> type = V_102 ;
V_7 -> V_87 = V_88 | V_98 ;
V_7 -> V_90 = 32 ;
V_7 -> V_91 = 1 ;
V_7 -> V_92 = 32 ;
V_7 -> V_93 = & V_103 ;
V_7 -> V_104 = F_8 ;
V_7 -> V_105 = F_4 ;
return 0 ;
}
static void F_32 ( struct V_4 * V_5 )
{
struct V_11 * V_35 = V_5 -> V_13 ;
if ( V_35 ) {
if ( V_5 -> V_22 )
F_22 ( V_5 ) ;
if ( V_35 -> V_63 )
F_33 ( V_35 -> V_63 ) ;
}
F_34 ( V_5 ) ;
}
static int F_35 ( struct V_73 * V_5 ,
const struct V_106 * V_107 )
{
return F_36 ( V_5 , & V_108 , V_107 -> V_109 ) ;
}
