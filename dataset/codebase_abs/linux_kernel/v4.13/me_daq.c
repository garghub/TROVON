static inline void F_1 ( unsigned int V_1 )
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
if ( ( V_31 & V_33 ) == 0 )
return 0 ;
return - V_34 ;
}
static int F_11 ( struct V_3 * V_4 ,
struct V_5 * V_6 ,
struct V_7 * V_8 ,
unsigned int * V_9 )
{
struct V_10 * V_11 = V_4 -> V_12 ;
unsigned int V_13 = F_4 ( V_8 -> V_14 ) ;
unsigned int V_35 = F_12 ( V_8 -> V_14 ) ;
unsigned int V_36 = F_13 ( V_8 -> V_14 ) ;
unsigned int V_28 ;
int V_16 = 0 ;
int V_37 ;
if ( V_36 & V_38 ) {
if ( V_13 > 7 || F_14 ( V_6 , V_35 ) )
return - V_39 ;
}
V_11 -> V_18 &= ~ ( V_40 | V_41 ) ;
F_6 ( V_11 -> V_18 , V_4 -> V_21 + V_22 ) ;
F_6 ( 0x00 , V_4 -> V_21 + V_32 ) ;
V_11 -> V_18 |= ( V_40 | V_41 ) ;
F_6 ( V_11 -> V_18 , V_4 -> V_21 + V_22 ) ;
V_28 = F_15 ( V_13 ) | F_16 ( V_35 ) ;
if ( F_14 ( V_6 , V_35 ) )
V_28 |= V_42 ;
if ( V_36 & V_38 )
V_28 |= V_43 ;
F_6 ( V_28 , V_4 -> V_21 + V_44 ) ;
V_11 -> V_45 |= V_46 ;
F_6 ( V_11 -> V_45 , V_4 -> V_21 + V_47 ) ;
for ( V_37 = 0 ; V_37 < V_8 -> V_23 ; V_37 ++ ) {
F_9 ( V_4 -> V_21 + V_47 ) ;
V_16 = F_17 ( V_4 , V_6 , V_8 , F_10 , 0 ) ;
if ( V_16 )
break;
V_28 = F_9 ( V_4 -> V_21 + V_44 ) & V_6 -> V_48 ;
V_9 [ V_37 ] = F_18 ( V_6 , V_28 ) ;
}
V_11 -> V_45 &= ~ V_49 ;
F_6 ( V_11 -> V_45 , V_4 -> V_21 + V_47 ) ;
return V_16 ? V_16 : V_8 -> V_23 ;
}
static int F_19 ( struct V_3 * V_4 ,
struct V_5 * V_6 ,
struct V_7 * V_8 ,
unsigned int * V_9 )
{
struct V_10 * V_11 = V_4 -> V_12 ;
unsigned int V_13 = F_4 ( V_8 -> V_14 ) ;
unsigned int V_35 = F_12 ( V_8 -> V_14 ) ;
unsigned int V_28 = V_6 -> V_50 [ V_13 ] ;
int V_37 ;
V_11 -> V_18 |= V_51 ;
F_6 ( V_11 -> V_18 , V_4 -> V_21 + V_22 ) ;
V_11 -> V_18 |= V_52 ;
F_6 ( V_11 -> V_18 , V_4 -> V_21 + V_22 ) ;
V_11 -> V_53 &= ~ F_20 ( V_13 ) ;
if ( V_35 == 0 )
V_11 -> V_53 |= F_21 ( V_13 ) ;
if ( F_22 ( V_6 , V_35 ) )
V_11 -> V_53 |= F_23 ( V_13 ) ;
F_6 ( V_11 -> V_53 , V_4 -> V_21 + V_54 ) ;
F_9 ( V_4 -> V_21 + V_54 ) ;
for ( V_37 = 0 ; V_37 < V_8 -> V_23 ; V_37 ++ ) {
V_28 = V_9 [ V_37 ] ;
F_6 ( V_28 , V_4 -> V_21 + F_24 ( V_13 ) ) ;
}
V_6 -> V_50 [ V_13 ] = V_28 ;
F_9 ( V_4 -> V_21 + V_22 ) ;
return V_8 -> V_23 ;
}
static int F_25 ( struct V_3 * V_4 ,
const T_2 * V_9 , T_3 V_55 ,
unsigned long V_30 )
{
struct V_10 * V_11 = V_4 -> V_12 ;
unsigned int V_56 ;
unsigned int V_57 ;
unsigned int V_37 ;
F_26 ( 0x00 , V_11 -> V_58 + V_59 ) ;
V_56 = F_9 ( V_4 -> V_21 + V_60 ) ;
F_1 ( 1 ) ;
F_27 ( 0x00 , V_4 -> V_21 + 0x0 ) ;
F_1 ( 1 ) ;
if ( V_55 < 16 )
return - V_39 ;
V_57 = ( ( ( unsigned int ) V_9 [ 0 ] & 0xff ) << 24 ) +
( ( ( unsigned int ) V_9 [ 1 ] & 0xff ) << 16 ) +
( ( ( unsigned int ) V_9 [ 2 ] & 0xff ) << 8 ) +
( ( unsigned int ) V_9 [ 3 ] & 0xff ) ;
for ( V_37 = 0 ; V_37 < V_57 ; V_37 ++ )
F_27 ( ( V_9 [ 16 + V_37 ] & 0xff ) , V_4 -> V_21 + 0x0 ) ;
for ( V_37 = 0 ; V_37 < 5 ; V_37 ++ )
F_27 ( 0x00 , V_4 -> V_21 + 0x0 ) ;
V_56 = F_28 ( V_11 -> V_58 + V_59 ) ;
if ( V_56 & V_61 ) {
F_26 ( 0x00 , V_11 -> V_58 + V_59 ) ;
F_29 ( V_4 -> V_62 , L_1 ) ;
return - V_63 ;
}
F_1 ( 1 ) ;
F_26 ( V_64 |
V_65 |
V_66 ,
V_11 -> V_58 + V_59 ) ;
return 0 ;
}
static int F_30 ( struct V_3 * V_4 )
{
struct V_10 * V_11 = V_4 -> V_12 ;
F_6 ( 0x00 , V_4 -> V_21 + V_47 ) ;
F_6 ( 0x00 , V_4 -> V_21 + V_22 ) ;
F_6 ( 0x00 , V_4 -> V_21 + V_32 ) ;
F_6 ( 0x00 , V_4 -> V_21 + V_54 ) ;
V_11 -> V_53 = 0 ;
V_11 -> V_45 = 0 ;
V_11 -> V_18 = 0 ;
return 0 ;
}
static int F_31 ( struct V_3 * V_4 ,
unsigned long V_30 )
{
struct V_67 * V_68 = F_32 ( V_4 ) ;
const struct V_69 * V_70 = NULL ;
struct V_10 * V_11 ;
struct V_5 * V_6 ;
int V_16 ;
if ( V_30 < F_33 ( V_71 ) )
V_70 = & V_71 [ V_30 ] ;
if ( ! V_70 )
return - V_72 ;
V_4 -> V_73 = V_70 ;
V_4 -> V_74 = V_70 -> V_75 ;
V_11 = F_34 ( V_4 , sizeof( * V_11 ) ) ;
if ( ! V_11 )
return - V_76 ;
V_16 = F_35 ( V_4 ) ;
if ( V_16 )
return V_16 ;
V_11 -> V_58 = F_36 ( V_68 , 0 ) ;
if ( ! V_11 -> V_58 )
return - V_76 ;
V_4 -> V_21 = F_36 ( V_68 , 2 ) ;
if ( ! V_4 -> V_21 )
return - V_76 ;
if ( V_70 -> V_77 ) {
V_16 = F_37 ( V_4 , & F_32 ( V_4 ) -> V_4 ,
V_78 ,
F_25 , 0 ) ;
if ( V_16 < 0 )
return V_16 ;
}
F_30 ( V_4 ) ;
V_16 = F_38 ( V_4 , 3 ) ;
if ( V_16 )
return V_16 ;
V_6 = & V_4 -> V_79 [ 0 ] ;
V_6 -> type = V_80 ;
V_6 -> V_81 = V_82 | V_83 | V_84 ;
V_6 -> V_85 = 16 ;
V_6 -> V_48 = 0x0fff ;
V_6 -> V_86 = 16 ;
V_6 -> V_87 = & V_88 ;
V_6 -> V_89 = F_11 ;
V_6 = & V_4 -> V_79 [ 1 ] ;
if ( V_70 -> V_90 ) {
V_6 -> type = V_91 ;
V_6 -> V_81 = V_92 | V_83 ;
V_6 -> V_85 = 4 ;
V_6 -> V_48 = 0x0fff ;
V_6 -> V_86 = 4 ;
V_6 -> V_87 = & V_93 ;
V_6 -> V_94 = F_19 ;
V_16 = F_39 ( V_6 ) ;
if ( V_16 )
return V_16 ;
} else {
V_6 -> type = V_95 ;
}
V_6 = & V_4 -> V_79 [ 2 ] ;
V_6 -> type = V_96 ;
V_6 -> V_81 = V_82 | V_92 ;
V_6 -> V_85 = 32 ;
V_6 -> V_48 = 1 ;
V_6 -> V_86 = 32 ;
V_6 -> V_87 = & V_97 ;
V_6 -> V_98 = F_7 ;
V_6 -> V_99 = F_3 ;
return 0 ;
}
static void F_40 ( struct V_3 * V_4 )
{
struct V_10 * V_11 = V_4 -> V_12 ;
if ( V_11 ) {
if ( V_4 -> V_21 )
F_30 ( V_4 ) ;
if ( V_11 -> V_58 )
F_41 ( V_11 -> V_58 ) ;
}
F_42 ( V_4 ) ;
}
static int F_43 ( struct V_67 * V_4 ,
const struct V_100 * V_101 )
{
return F_44 ( V_4 , & V_102 , V_101 -> V_103 ) ;
}
