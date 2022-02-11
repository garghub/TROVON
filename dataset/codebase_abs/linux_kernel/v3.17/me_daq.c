static inline void F_1 ( unsigned V_1 )
{
V_2 -> V_3 = V_4 ;
F_2 ( V_1 * V_5 ) ;
}
static int F_3 ( struct V_6 * V_7 ,
struct V_8 * V_9 ,
struct V_10 * V_11 ,
unsigned int * V_12 )
{
struct V_13 * V_14 = V_7 -> V_15 ;
unsigned int V_16 = F_4 ( V_11 -> V_17 ) ;
unsigned int V_18 ;
int V_19 ;
if ( V_16 < 16 )
V_18 = 0x0000ffff ;
else
V_18 = 0xffff0000 ;
V_19 = F_5 ( V_7 , V_9 , V_11 , V_12 , V_18 ) ;
if ( V_19 )
return V_19 ;
if ( V_9 -> V_20 & 0x0000ffff )
V_14 -> V_21 |= V_22 ;
else
V_14 -> V_21 &= ~ V_22 ;
if ( V_9 -> V_20 & 0xffff0000 )
V_14 -> V_21 |= V_23 ;
else
V_14 -> V_21 &= ~ V_23 ;
F_6 ( V_14 -> V_21 , V_7 -> V_24 + V_25 ) ;
return V_11 -> V_26 ;
}
static int F_7 ( struct V_6 * V_7 ,
struct V_8 * V_9 ,
struct V_10 * V_11 ,
unsigned int * V_12 )
{
void T_1 * V_27 = V_7 -> V_24 + V_28 ;
void T_1 * V_29 = V_7 -> V_24 + V_30 ;
unsigned int V_18 ;
unsigned int V_31 ;
V_18 = F_8 ( V_9 , V_12 ) ;
if ( V_18 ) {
if ( V_18 & 0x0000ffff )
F_6 ( ( V_9 -> V_3 & 0xffff ) , V_27 ) ;
if ( V_18 & 0xffff0000 )
F_6 ( ( ( V_9 -> V_3 >> 16 ) & 0xffff ) , V_29 ) ;
}
if ( V_9 -> V_20 & 0x0000ffff )
V_31 = V_9 -> V_3 & 0xffff ;
else
V_31 = F_9 ( V_27 ) ;
if ( V_9 -> V_20 & 0xffff0000 )
V_31 |= ( V_9 -> V_3 & 0xffff0000 ) ;
else
V_31 |= ( F_9 ( V_29 ) << 16 ) ;
V_12 [ 1 ] = V_31 ;
return V_11 -> V_26 ;
}
static int F_10 ( struct V_6 * V_7 ,
struct V_8 * V_9 ,
struct V_10 * V_11 ,
unsigned long V_32 )
{
unsigned int V_33 ;
V_33 = F_9 ( V_7 -> V_24 + V_34 ) ;
if ( ( V_33 & 0x0004 ) == 0 )
return 0 ;
return - V_35 ;
}
static int F_11 ( struct V_6 * V_7 ,
struct V_8 * V_9 ,
struct V_10 * V_11 ,
unsigned int * V_12 )
{
struct V_13 * V_36 = V_7 -> V_15 ;
unsigned int V_16 = F_4 ( V_11 -> V_17 ) ;
unsigned int V_37 = F_12 ( V_11 -> V_17 ) ;
unsigned int V_38 = F_13 ( V_11 -> V_17 ) ;
unsigned short V_31 ;
int V_19 ;
V_36 -> V_39 &= 0xFFFC ;
F_6 ( V_36 -> V_39 , V_7 -> V_24 + V_40 ) ;
V_36 -> V_21 &= ~ ( V_41 | V_42 ) ;
F_6 ( V_36 -> V_21 , V_7 -> V_24 + V_25 ) ;
F_6 ( 0x00 , V_7 -> V_24 + V_43 ) ;
V_36 -> V_21 |= ( V_41 | V_42 ) ;
F_6 ( V_36 -> V_21 , V_7 -> V_24 + V_25 ) ;
V_31 = V_16 & 0x0f ;
V_31 |= ( V_37 & 0x03 ) << 4 ;
V_31 |= ( V_37 & 0x04 ) << 4 ;
V_31 |= ( ( V_38 & V_44 ) ? 0x80 : 0 ) ;
F_6 ( V_31 & 0xff , V_7 -> V_24 + V_45 ) ;
V_36 -> V_39 |= V_46 ;
F_6 ( V_36 -> V_39 , V_7 -> V_24 + V_40 ) ;
F_9 ( V_7 -> V_24 + V_47 ) ;
V_19 = F_14 ( V_7 , V_9 , V_11 , F_10 , 0 ) ;
if ( V_19 )
return V_19 ;
V_31 = F_9 ( V_7 -> V_24 + V_48 ) ;
V_31 = ( V_31 ^ 0x800 ) & 0x0fff ;
V_12 [ 0 ] = V_31 ;
V_36 -> V_39 &= 0xFFFC ;
F_6 ( V_36 -> V_39 , V_7 -> V_24 + V_40 ) ;
return 1 ;
}
static int F_15 ( struct V_6 * V_7 ,
struct V_8 * V_9 ,
struct V_10 * V_11 ,
unsigned int * V_12 )
{
struct V_13 * V_36 = V_7 -> V_15 ;
unsigned int V_16 = F_4 ( V_11 -> V_17 ) ;
unsigned int V_37 = F_12 ( V_11 -> V_17 ) ;
int V_49 ;
V_36 -> V_21 |= V_50 ;
F_6 ( V_36 -> V_21 , V_7 -> V_24 + V_25 ) ;
V_36 -> V_21 |= V_51 ;
F_6 ( V_36 -> V_21 , V_7 -> V_24 + V_25 ) ;
for ( V_49 = 0 ; V_49 < V_11 -> V_26 ; V_49 ++ ) {
V_36 -> V_52 &= ~ ( 0x0880 >> V_16 ) ;
if ( V_37 == 0 )
V_36 -> V_52 |=
( ( V_53 | V_54 ) >> V_16 ) ;
else if ( V_37 == 1 )
V_36 -> V_52 |=
( ( V_53 | V_55 ) >> V_16 ) ;
}
F_6 ( V_36 -> V_52 , V_7 -> V_24 + V_56 ) ;
F_9 ( V_7 -> V_24 + V_57 ) ;
for ( V_49 = 0 ; V_49 < V_11 -> V_26 ; V_49 ++ ) {
F_6 ( ( V_12 [ 0 ] & V_9 -> V_58 ) ,
V_7 -> V_24 + V_59 + ( V_16 << 1 ) ) ;
V_36 -> V_60 [ V_16 ] = ( V_12 [ 0 ] & V_9 -> V_58 ) ;
}
F_9 ( V_7 -> V_24 + V_61 ) ;
return V_11 -> V_26 ;
}
static int F_16 ( struct V_6 * V_7 ,
struct V_8 * V_9 ,
struct V_10 * V_11 ,
unsigned int * V_12 )
{
struct V_13 * V_36 = V_7 -> V_15 ;
unsigned int V_16 = F_4 ( V_11 -> V_17 ) ;
int V_49 ;
for ( V_49 = 0 ; V_49 < V_11 -> V_26 ; V_49 ++ )
V_12 [ V_49 ] = V_36 -> V_60 [ V_16 ] ;
return V_11 -> V_26 ;
}
static int F_17 ( struct V_6 * V_7 ,
const T_2 * V_12 , T_3 V_62 ,
unsigned long V_32 )
{
struct V_13 * V_36 = V_7 -> V_15 ;
unsigned int V_63 ;
unsigned int V_64 ;
unsigned int V_49 ;
F_18 ( 0x00 , V_36 -> V_65 + V_66 ) ;
V_63 = F_9 ( V_7 -> V_24 + V_67 ) ;
F_1 ( 1 ) ;
F_19 ( 0x00 , V_7 -> V_24 + 0x0 ) ;
F_1 ( 1 ) ;
if ( V_62 < 16 )
return - V_68 ;
V_64 = ( ( ( unsigned int ) V_12 [ 0 ] & 0xff ) << 24 ) +
( ( ( unsigned int ) V_12 [ 1 ] & 0xff ) << 16 ) +
( ( ( unsigned int ) V_12 [ 2 ] & 0xff ) << 8 ) +
( ( unsigned int ) V_12 [ 3 ] & 0xff ) ;
for ( V_49 = 0 ; V_49 < V_64 ; V_49 ++ )
F_19 ( ( V_12 [ 16 + V_49 ] & 0xff ) , V_7 -> V_24 + 0x0 ) ;
for ( V_49 = 0 ; V_49 < 5 ; V_49 ++ )
F_19 ( 0x00 , V_7 -> V_24 + 0x0 ) ;
V_63 = F_20 ( V_36 -> V_65 + V_66 ) ;
if ( V_63 & V_69 ) {
F_18 ( 0x00 , V_36 -> V_65 + V_66 ) ;
F_21 ( V_7 -> V_70 , L_1 ) ;
return - V_71 ;
}
F_1 ( 1 ) ;
F_18 ( V_72 |
V_73 |
V_74 ,
V_36 -> V_65 + V_66 ) ;
return 0 ;
}
static int F_22 ( struct V_6 * V_7 )
{
struct V_13 * V_36 = V_7 -> V_15 ;
F_6 ( 0x00 , V_7 -> V_24 + V_40 ) ;
F_6 ( 0x00 , V_7 -> V_24 + V_25 ) ;
F_6 ( 0x00 , V_7 -> V_24 + V_43 ) ;
F_6 ( 0x00 , V_7 -> V_24 + V_56 ) ;
V_36 -> V_52 = 0 ;
V_36 -> V_39 = 0 ;
V_36 -> V_21 = 0 ;
return 0 ;
}
static int F_23 ( struct V_6 * V_7 ,
unsigned long V_32 )
{
struct V_75 * V_76 = F_24 ( V_7 ) ;
const struct V_77 * V_78 = NULL ;
struct V_13 * V_36 ;
struct V_8 * V_9 ;
int V_19 ;
if ( V_32 < F_25 ( V_79 ) )
V_78 = & V_79 [ V_32 ] ;
if ( ! V_78 )
return - V_80 ;
V_7 -> V_81 = V_78 ;
V_7 -> V_82 = V_78 -> V_83 ;
V_36 = F_26 ( V_7 , sizeof( * V_36 ) ) ;
if ( ! V_36 )
return - V_84 ;
V_19 = F_27 ( V_7 ) ;
if ( V_19 )
return V_19 ;
V_36 -> V_65 = F_28 ( V_76 , 0 ) ;
if ( ! V_36 -> V_65 )
return - V_84 ;
V_7 -> V_24 = F_28 ( V_76 , 2 ) ;
if ( ! V_7 -> V_24 )
return - V_84 ;
if ( V_78 -> V_85 ) {
V_19 = F_29 ( V_7 , & F_24 ( V_7 ) -> V_7 ,
V_86 ,
F_17 , 0 ) ;
if ( V_19 < 0 )
return V_19 ;
}
F_22 ( V_7 ) ;
V_19 = F_30 ( V_7 , 3 ) ;
if ( V_19 )
return V_19 ;
V_9 = & V_7 -> V_87 [ 0 ] ;
V_9 -> type = V_88 ;
V_9 -> V_89 = V_90 | V_91 ;
V_9 -> V_92 = 16 ;
V_9 -> V_58 = 0x0fff ;
V_9 -> V_93 = 16 ;
V_9 -> V_94 = & V_95 ;
V_9 -> V_96 = F_11 ;
V_9 = & V_7 -> V_87 [ 1 ] ;
if ( V_78 -> V_97 ) {
V_9 -> type = V_98 ;
V_9 -> V_89 = V_99 | V_91 ;
V_9 -> V_92 = 4 ;
V_9 -> V_58 = 0x0fff ;
V_9 -> V_93 = 4 ;
V_9 -> V_94 = & V_100 ;
V_9 -> V_96 = F_16 ;
V_9 -> V_101 = F_15 ;
} else {
V_9 -> type = V_102 ;
}
V_9 = & V_7 -> V_87 [ 2 ] ;
V_9 -> type = V_103 ;
V_9 -> V_89 = V_90 | V_99 ;
V_9 -> V_92 = 32 ;
V_9 -> V_58 = 1 ;
V_9 -> V_93 = 32 ;
V_9 -> V_94 = & V_104 ;
V_9 -> V_105 = F_7 ;
V_9 -> V_106 = F_3 ;
return 0 ;
}
static void F_31 ( struct V_6 * V_7 )
{
struct V_13 * V_36 = V_7 -> V_15 ;
if ( V_36 ) {
if ( V_7 -> V_24 ) {
F_22 ( V_7 ) ;
F_32 ( V_7 -> V_24 ) ;
}
if ( V_36 -> V_65 )
F_32 ( V_36 -> V_65 ) ;
}
F_33 ( V_7 ) ;
}
static int F_34 ( struct V_75 * V_7 ,
const struct V_107 * V_108 )
{
return F_35 ( V_7 , & V_109 , V_108 -> V_110 ) ;
}
