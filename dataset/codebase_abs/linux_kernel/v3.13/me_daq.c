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
F_6 ( V_14 -> V_21 , V_14 -> V_24 + V_25 ) ;
return V_11 -> V_26 ;
}
static int F_7 ( struct V_6 * V_7 ,
struct V_8 * V_9 ,
struct V_10 * V_11 ,
unsigned int * V_12 )
{
struct V_13 * V_27 = V_7 -> V_15 ;
void T_1 * V_28 = V_27 -> V_24 + V_29 ;
void T_1 * V_30 = V_27 -> V_24 + V_31 ;
unsigned int V_18 ;
unsigned int V_32 ;
V_18 = F_8 ( V_9 , V_12 ) ;
if ( V_18 ) {
if ( V_18 & 0x0000ffff )
F_6 ( ( V_9 -> V_3 & 0xffff ) , V_28 ) ;
if ( V_18 & 0xffff0000 )
F_6 ( ( ( V_9 -> V_3 >> 16 ) & 0xffff ) , V_30 ) ;
}
if ( V_9 -> V_20 & 0x0000ffff )
V_32 = V_9 -> V_3 & 0xffff ;
else
V_32 = F_9 ( V_28 ) ;
if ( V_9 -> V_20 & 0xffff0000 )
V_32 |= ( V_9 -> V_3 & 0xffff0000 ) ;
else
V_32 |= ( F_9 ( V_30 ) << 16 ) ;
V_12 [ 1 ] = V_32 ;
return V_11 -> V_26 ;
}
static int F_10 ( struct V_6 * V_7 ,
struct V_8 * V_9 ,
struct V_10 * V_11 ,
unsigned int * V_12 )
{
struct V_13 * V_27 = V_7 -> V_15 ;
unsigned int V_16 = F_4 ( V_11 -> V_17 ) ;
unsigned int V_33 = F_11 ( V_11 -> V_17 ) ;
unsigned int V_34 = F_12 ( V_11 -> V_17 ) ;
unsigned short V_32 ;
int V_35 ;
V_27 -> V_36 &= 0xFFFC ;
F_6 ( V_27 -> V_36 , V_27 -> V_24 + V_37 ) ;
V_27 -> V_21 &= ~ ( V_38 | V_39 ) ;
F_6 ( V_27 -> V_21 , V_27 -> V_24 + V_25 ) ;
F_6 ( 0x00 , V_27 -> V_24 + V_40 ) ;
V_27 -> V_21 |= ( V_38 | V_39 ) ;
F_6 ( V_27 -> V_21 , V_27 -> V_24 + V_25 ) ;
V_32 = V_16 & 0x0f ;
V_32 |= ( V_33 & 0x03 ) << 4 ;
V_32 |= ( V_33 & 0x04 ) << 4 ;
V_32 |= ( ( V_34 & V_41 ) ? 0x80 : 0 ) ;
F_6 ( V_32 & 0xff , V_27 -> V_24 + V_42 ) ;
V_27 -> V_36 |= V_43 ;
F_6 ( V_27 -> V_36 , V_27 -> V_24 + V_37 ) ;
F_9 ( V_27 -> V_24 + V_44 ) ;
for ( V_35 = 100000 ; V_35 > 0 ; V_35 -- )
if ( ! ( F_9 ( V_27 -> V_24 + V_45 ) & 0x0004 ) )
break;
if ( V_35 ) {
V_32 = F_9 ( V_27 -> V_24 + V_46 ) ;
V_32 = ( V_32 ^ 0x800 ) & 0x0fff ;
V_12 [ 0 ] = V_32 ;
} else {
F_13 ( V_7 -> V_47 , L_1 ) ;
return - V_48 ;
}
V_27 -> V_36 &= 0xFFFC ;
F_6 ( V_27 -> V_36 , V_27 -> V_24 + V_37 ) ;
return 1 ;
}
static int F_14 ( struct V_6 * V_7 ,
struct V_8 * V_9 ,
struct V_10 * V_11 ,
unsigned int * V_12 )
{
struct V_13 * V_27 = V_7 -> V_15 ;
unsigned int V_16 = F_4 ( V_11 -> V_17 ) ;
unsigned int V_33 = F_11 ( V_11 -> V_17 ) ;
int V_35 ;
V_27 -> V_21 |= V_49 ;
F_6 ( V_27 -> V_21 , V_27 -> V_24 + V_25 ) ;
V_27 -> V_21 |= V_50 ;
F_6 ( V_27 -> V_21 , V_27 -> V_24 + V_25 ) ;
for ( V_35 = 0 ; V_35 < V_11 -> V_26 ; V_35 ++ ) {
V_27 -> V_51 &= ~ ( 0x0880 >> V_16 ) ;
if ( V_33 == 0 )
V_27 -> V_51 |=
( ( V_52 | V_53 ) >> V_16 ) ;
else if ( V_33 == 1 )
V_27 -> V_51 |=
( ( V_52 | V_54 ) >> V_16 ) ;
}
F_6 ( V_27 -> V_51 ,
V_27 -> V_24 + V_55 ) ;
F_9 ( V_27 -> V_24 + V_56 ) ;
for ( V_35 = 0 ; V_35 < V_11 -> V_26 ; V_35 ++ ) {
F_6 ( ( V_12 [ 0 ] & V_9 -> V_57 ) ,
V_27 -> V_24 + V_58 + ( V_16 << 1 ) ) ;
V_27 -> V_59 [ V_16 ] = ( V_12 [ 0 ] & V_9 -> V_57 ) ;
}
F_9 ( V_27 -> V_24 + V_60 ) ;
return V_11 -> V_26 ;
}
static int F_15 ( struct V_6 * V_7 ,
struct V_8 * V_9 ,
struct V_10 * V_11 ,
unsigned int * V_12 )
{
struct V_13 * V_27 = V_7 -> V_15 ;
unsigned int V_16 = F_4 ( V_11 -> V_17 ) ;
int V_35 ;
for ( V_35 = 0 ; V_35 < V_11 -> V_26 ; V_35 ++ )
V_12 [ V_35 ] = V_27 -> V_59 [ V_16 ] ;
return V_11 -> V_26 ;
}
static int F_16 ( struct V_6 * V_7 ,
const T_2 * V_12 , T_3 V_61 ,
unsigned long V_62 )
{
struct V_13 * V_27 = V_7 -> V_15 ;
unsigned int V_63 ;
unsigned int V_64 ;
unsigned int V_35 ;
F_17 ( 0x00 , V_27 -> V_65 + V_66 ) ;
V_63 = F_9 ( V_27 -> V_24 + V_67 ) ;
F_1 ( 1 ) ;
F_18 ( 0x00 , V_27 -> V_24 + 0x0 ) ;
F_1 ( 1 ) ;
if ( V_61 < 16 )
return - V_68 ;
V_64 = ( ( ( unsigned int ) V_12 [ 0 ] & 0xff ) << 24 ) +
( ( ( unsigned int ) V_12 [ 1 ] & 0xff ) << 16 ) +
( ( ( unsigned int ) V_12 [ 2 ] & 0xff ) << 8 ) +
( ( unsigned int ) V_12 [ 3 ] & 0xff ) ;
for ( V_35 = 0 ; V_35 < V_64 ; V_35 ++ )
F_18 ( ( V_12 [ 16 + V_35 ] & 0xff ) ,
V_27 -> V_24 + 0x0 ) ;
for ( V_35 = 0 ; V_35 < 5 ; V_35 ++ )
F_18 ( 0x00 , V_27 -> V_24 + 0x0 ) ;
V_63 = F_19 ( V_27 -> V_65 + V_66 ) ;
if ( V_63 & V_69 ) {
F_17 ( 0x00 , V_27 -> V_65 + V_66 ) ;
F_13 ( V_7 -> V_47 , L_2 ) ;
return - V_48 ;
}
F_1 ( 1 ) ;
F_17 ( V_70 |
V_71 |
V_72 ,
V_27 -> V_65 + V_66 ) ;
return 0 ;
}
static int F_20 ( struct V_6 * V_7 )
{
struct V_13 * V_27 = V_7 -> V_15 ;
F_6 ( 0x00 , V_27 -> V_24 + V_37 ) ;
F_6 ( 0x00 , V_27 -> V_24 + V_25 ) ;
F_6 ( 0x00 , V_27 -> V_24 + V_40 ) ;
F_6 ( 0x00 , V_27 -> V_24 + V_55 ) ;
V_27 -> V_51 = 0 ;
V_27 -> V_36 = 0 ;
V_27 -> V_21 = 0 ;
return 0 ;
}
static int F_21 ( struct V_6 * V_7 ,
unsigned long V_62 )
{
struct V_73 * V_74 = F_22 ( V_7 ) ;
const struct V_75 * V_76 = NULL ;
struct V_13 * V_27 ;
struct V_8 * V_9 ;
int V_19 ;
if ( V_62 < F_23 ( V_77 ) )
V_76 = & V_77 [ V_62 ] ;
if ( ! V_76 )
return - V_78 ;
V_7 -> V_79 = V_76 ;
V_7 -> V_80 = V_76 -> V_81 ;
V_27 = F_24 ( V_7 , sizeof( * V_27 ) ) ;
if ( ! V_27 )
return - V_82 ;
V_19 = F_25 ( V_7 ) ;
if ( V_19 )
return V_19 ;
V_27 -> V_65 = F_26 ( V_74 , 0 ) ;
if ( ! V_27 -> V_65 )
return - V_82 ;
V_27 -> V_24 = F_26 ( V_74 , 2 ) ;
if ( ! V_27 -> V_24 )
return - V_82 ;
if ( V_76 -> V_83 ) {
V_19 = F_27 ( V_7 , & F_22 ( V_7 ) -> V_7 ,
V_84 ,
F_16 , 0 ) ;
if ( V_19 < 0 )
return V_19 ;
}
F_20 ( V_7 ) ;
V_19 = F_28 ( V_7 , 3 ) ;
if ( V_19 )
return V_19 ;
V_9 = & V_7 -> V_85 [ 0 ] ;
V_9 -> type = V_86 ;
V_9 -> V_87 = V_88 | V_89 ;
V_9 -> V_90 = 16 ;
V_9 -> V_57 = 0x0fff ;
V_9 -> V_91 = 16 ;
V_9 -> V_92 = & V_93 ;
V_9 -> V_94 = F_10 ;
V_9 = & V_7 -> V_85 [ 1 ] ;
if ( V_76 -> V_95 ) {
V_9 -> type = V_96 ;
V_9 -> V_87 = V_97 | V_89 ;
V_9 -> V_90 = 4 ;
V_9 -> V_57 = 0x0fff ;
V_9 -> V_91 = 4 ;
V_9 -> V_92 = & V_98 ;
V_9 -> V_94 = F_15 ;
V_9 -> V_99 = F_14 ;
} else {
V_9 -> type = V_100 ;
}
V_9 = & V_7 -> V_85 [ 2 ] ;
V_9 -> type = V_101 ;
V_9 -> V_87 = V_88 | V_97 ;
V_9 -> V_90 = 32 ;
V_9 -> V_57 = 1 ;
V_9 -> V_91 = 32 ;
V_9 -> V_92 = & V_102 ;
V_9 -> V_103 = F_7 ;
V_9 -> V_104 = F_3 ;
F_29 ( V_7 -> V_47 , L_3 ,
V_7 -> V_105 -> V_106 , V_7 -> V_80 ) ;
return 0 ;
}
static void F_30 ( struct V_6 * V_7 )
{
struct V_13 * V_27 = V_7 -> V_15 ;
if ( V_27 ) {
if ( V_27 -> V_24 ) {
F_20 ( V_7 ) ;
F_31 ( V_27 -> V_24 ) ;
}
if ( V_27 -> V_65 )
F_31 ( V_27 -> V_65 ) ;
}
F_32 ( V_7 ) ;
}
static int F_33 ( struct V_73 * V_7 ,
const struct V_107 * V_108 )
{
return F_34 ( V_7 , & V_109 , V_108 -> V_110 ) ;
}
