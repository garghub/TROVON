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
unsigned int V_18 = V_12 [ 0 ] ;
unsigned int V_32 = V_12 [ 1 ] ;
unsigned int V_33 ;
V_18 &= V_9 -> V_20 ;
if ( V_18 ) {
V_9 -> V_3 &= ~ V_18 ;
V_9 -> V_3 |= ( V_32 & V_18 ) ;
if ( V_18 & 0x0000ffff )
F_6 ( ( V_9 -> V_3 & 0xffff ) , V_28 ) ;
if ( V_18 & 0xffff0000 )
F_6 ( ( ( V_9 -> V_3 >> 16 ) & 0xffff ) , V_30 ) ;
}
if ( V_9 -> V_20 & 0x0000ffff )
V_33 = V_9 -> V_3 & 0xffff ;
else
V_33 = F_8 ( V_28 ) ;
if ( V_9 -> V_20 & 0xffff0000 )
V_33 |= ( V_9 -> V_3 & 0xffff0000 ) ;
else
V_33 |= ( F_8 ( V_30 ) << 16 ) ;
V_12 [ 1 ] = V_33 ;
return V_11 -> V_26 ;
}
static int F_9 ( struct V_6 * V_7 ,
struct V_8 * V_9 ,
struct V_10 * V_11 ,
unsigned int * V_12 )
{
struct V_13 * V_27 = V_7 -> V_15 ;
unsigned int V_16 = F_4 ( V_11 -> V_17 ) ;
unsigned int V_34 = F_10 ( V_11 -> V_17 ) ;
unsigned int V_35 = F_11 ( V_11 -> V_17 ) ;
unsigned short V_33 ;
int V_36 ;
V_27 -> V_37 &= 0xFFFC ;
F_6 ( V_27 -> V_37 , V_27 -> V_24 + V_38 ) ;
V_27 -> V_21 &= ~ ( V_39 | V_40 ) ;
F_6 ( V_27 -> V_21 , V_27 -> V_24 + V_25 ) ;
F_6 ( 0x00 , V_27 -> V_24 + V_41 ) ;
V_27 -> V_21 |= ( V_39 | V_40 ) ;
F_6 ( V_27 -> V_21 , V_27 -> V_24 + V_25 ) ;
V_33 = V_16 & 0x0f ;
V_33 |= ( V_34 & 0x03 ) << 4 ;
V_33 |= ( V_34 & 0x04 ) << 4 ;
V_33 |= ( ( V_35 & V_42 ) ? 0x80 : 0 ) ;
F_6 ( V_33 & 0xff , V_27 -> V_24 + V_43 ) ;
V_27 -> V_37 |= V_44 ;
F_6 ( V_27 -> V_37 , V_27 -> V_24 + V_38 ) ;
F_8 ( V_27 -> V_24 + V_45 ) ;
for ( V_36 = 100000 ; V_36 > 0 ; V_36 -- )
if ( ! ( F_8 ( V_27 -> V_24 + V_46 ) & 0x0004 ) )
break;
if ( V_36 ) {
V_33 = F_8 ( V_27 -> V_24 + V_47 ) ;
V_33 = ( V_33 ^ 0x800 ) & 0x0fff ;
V_12 [ 0 ] = V_33 ;
} else {
F_12 ( V_7 -> V_48 , L_1 ) ;
return - V_49 ;
}
V_27 -> V_37 &= 0xFFFC ;
F_6 ( V_27 -> V_37 , V_27 -> V_24 + V_38 ) ;
return 1 ;
}
static int F_13 ( struct V_6 * V_7 ,
struct V_8 * V_9 ,
struct V_10 * V_11 ,
unsigned int * V_12 )
{
struct V_13 * V_27 = V_7 -> V_15 ;
unsigned int V_16 = F_4 ( V_11 -> V_17 ) ;
unsigned int V_34 = F_10 ( V_11 -> V_17 ) ;
int V_36 ;
V_27 -> V_21 |= V_50 ;
F_6 ( V_27 -> V_21 , V_27 -> V_24 + V_25 ) ;
V_27 -> V_21 |= V_51 ;
F_6 ( V_27 -> V_21 , V_27 -> V_24 + V_25 ) ;
for ( V_36 = 0 ; V_36 < V_11 -> V_26 ; V_36 ++ ) {
V_27 -> V_52 &= ~ ( 0x0880 >> V_16 ) ;
if ( V_34 == 0 )
V_27 -> V_52 |=
( ( V_53 | V_54 ) >> V_16 ) ;
else if ( V_34 == 1 )
V_27 -> V_52 |=
( ( V_53 | V_55 ) >> V_16 ) ;
}
F_6 ( V_27 -> V_52 ,
V_27 -> V_24 + V_56 ) ;
F_8 ( V_27 -> V_24 + V_57 ) ;
for ( V_36 = 0 ; V_36 < V_11 -> V_26 ; V_36 ++ ) {
F_6 ( ( V_12 [ 0 ] & V_9 -> V_58 ) ,
V_27 -> V_24 + V_59 + ( V_16 << 1 ) ) ;
V_27 -> V_60 [ V_16 ] = ( V_12 [ 0 ] & V_9 -> V_58 ) ;
}
F_8 ( V_27 -> V_24 + V_61 ) ;
return V_11 -> V_26 ;
}
static int F_14 ( struct V_6 * V_7 ,
struct V_8 * V_9 ,
struct V_10 * V_11 ,
unsigned int * V_12 )
{
struct V_13 * V_27 = V_7 -> V_15 ;
unsigned int V_16 = F_4 ( V_11 -> V_17 ) ;
int V_36 ;
for ( V_36 = 0 ; V_36 < V_11 -> V_26 ; V_36 ++ )
V_12 [ V_36 ] = V_27 -> V_60 [ V_16 ] ;
return V_11 -> V_26 ;
}
static int F_15 ( struct V_6 * V_7 ,
const T_2 * V_12 , T_3 V_62 ,
unsigned long V_63 )
{
struct V_13 * V_27 = V_7 -> V_15 ;
unsigned int V_64 ;
unsigned int V_65 ;
unsigned int V_36 ;
F_16 ( 0x00 , V_27 -> V_66 + V_67 ) ;
V_64 = F_8 ( V_27 -> V_24 + V_68 ) ;
F_1 ( 1 ) ;
F_17 ( 0x00 , V_27 -> V_24 + 0x0 ) ;
F_1 ( 1 ) ;
if ( V_62 < 16 )
return - V_69 ;
V_65 = ( ( ( unsigned int ) V_12 [ 0 ] & 0xff ) << 24 ) +
( ( ( unsigned int ) V_12 [ 1 ] & 0xff ) << 16 ) +
( ( ( unsigned int ) V_12 [ 2 ] & 0xff ) << 8 ) +
( ( unsigned int ) V_12 [ 3 ] & 0xff ) ;
for ( V_36 = 0 ; V_36 < V_65 ; V_36 ++ )
F_17 ( ( V_12 [ 16 + V_36 ] & 0xff ) ,
V_27 -> V_24 + 0x0 ) ;
for ( V_36 = 0 ; V_36 < 5 ; V_36 ++ )
F_17 ( 0x00 , V_27 -> V_24 + 0x0 ) ;
V_64 = F_18 ( V_27 -> V_66 + V_67 ) ;
if ( V_64 & V_70 ) {
F_16 ( 0x00 , V_27 -> V_66 + V_67 ) ;
F_12 ( V_7 -> V_48 , L_2 ) ;
return - V_49 ;
}
F_1 ( 1 ) ;
F_16 ( V_71 |
V_72 |
V_73 ,
V_27 -> V_66 + V_67 ) ;
return 0 ;
}
static int F_19 ( struct V_6 * V_7 )
{
struct V_13 * V_27 = V_7 -> V_15 ;
F_6 ( 0x00 , V_27 -> V_24 + V_38 ) ;
F_6 ( 0x00 , V_27 -> V_24 + V_25 ) ;
F_6 ( 0x00 , V_27 -> V_24 + V_41 ) ;
F_6 ( 0x00 , V_27 -> V_24 + V_56 ) ;
V_27 -> V_52 = 0 ;
V_27 -> V_37 = 0 ;
V_27 -> V_21 = 0 ;
return 0 ;
}
static int F_20 ( struct V_6 * V_7 ,
unsigned long V_63 )
{
struct V_74 * V_75 = F_21 ( V_7 ) ;
const struct V_76 * V_77 = NULL ;
struct V_13 * V_27 ;
struct V_8 * V_9 ;
int V_19 ;
if ( V_63 < F_22 ( V_78 ) )
V_77 = & V_78 [ V_63 ] ;
if ( ! V_77 )
return - V_79 ;
V_7 -> V_80 = V_77 ;
V_7 -> V_81 = V_77 -> V_82 ;
V_27 = F_23 ( V_7 , sizeof( * V_27 ) ) ;
if ( ! V_27 )
return - V_83 ;
V_19 = F_24 ( V_7 ) ;
if ( V_19 )
return V_19 ;
V_27 -> V_66 = F_25 ( V_75 , 0 ) ;
if ( ! V_27 -> V_66 )
return - V_83 ;
V_27 -> V_24 = F_25 ( V_75 , 2 ) ;
if ( ! V_27 -> V_24 )
return - V_83 ;
if ( V_77 -> V_84 ) {
V_19 = F_26 ( V_7 , & F_21 ( V_7 ) -> V_7 ,
V_85 ,
F_15 , 0 ) ;
if ( V_19 < 0 )
return V_19 ;
}
F_19 ( V_7 ) ;
V_19 = F_27 ( V_7 , 3 ) ;
if ( V_19 )
return V_19 ;
V_9 = & V_7 -> V_86 [ 0 ] ;
V_9 -> type = V_87 ;
V_9 -> V_88 = V_89 | V_90 ;
V_9 -> V_91 = 16 ;
V_9 -> V_58 = 0x0fff ;
V_9 -> V_92 = 16 ;
V_9 -> V_93 = & V_94 ;
V_9 -> V_95 = F_9 ;
V_9 = & V_7 -> V_86 [ 1 ] ;
if ( V_77 -> V_96 ) {
V_9 -> type = V_97 ;
V_9 -> V_88 = V_98 | V_90 ;
V_9 -> V_91 = 4 ;
V_9 -> V_58 = 0x0fff ;
V_9 -> V_92 = 4 ;
V_9 -> V_93 = & V_99 ;
V_9 -> V_95 = F_14 ;
V_9 -> V_100 = F_13 ;
} else {
V_9 -> type = V_101 ;
}
V_9 = & V_7 -> V_86 [ 2 ] ;
V_9 -> type = V_102 ;
V_9 -> V_88 = V_89 | V_98 ;
V_9 -> V_91 = 32 ;
V_9 -> V_58 = 1 ;
V_9 -> V_92 = 32 ;
V_9 -> V_93 = & V_103 ;
V_9 -> V_104 = F_7 ;
V_9 -> V_105 = F_3 ;
V_9 -> V_20 = 0 ;
F_28 ( V_7 -> V_48 , L_3 ,
V_7 -> V_106 -> V_107 , V_7 -> V_81 ) ;
return 0 ;
}
static void F_29 ( struct V_6 * V_7 )
{
struct V_13 * V_27 = V_7 -> V_15 ;
if ( V_27 ) {
if ( V_27 -> V_24 ) {
F_19 ( V_7 ) ;
F_30 ( V_27 -> V_24 ) ;
}
if ( V_27 -> V_66 )
F_30 ( V_27 -> V_66 ) ;
}
F_31 ( V_7 ) ;
}
static int F_32 ( struct V_74 * V_7 ,
const struct V_108 * V_109 )
{
return F_33 ( V_7 , & V_110 , V_109 -> V_111 ) ;
}
