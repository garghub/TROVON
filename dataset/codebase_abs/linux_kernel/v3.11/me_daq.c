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
unsigned int V_16 = 1 << F_4 ( V_11 -> V_17 ) ;
unsigned int V_18 ;
unsigned int V_19 ;
if ( V_16 & 0x0000ffff ) {
V_18 = 0x0000ffff ;
V_19 = V_20 ;
} else {
V_18 = 0xffff0000 ;
V_19 = V_21 ;
}
switch ( V_12 [ 0 ] ) {
case V_22 :
V_9 -> V_23 &= ~ V_18 ;
V_14 -> V_24 &= ~ V_19 ;
break;
case V_25 :
V_9 -> V_23 |= V_18 ;
V_14 -> V_24 |= V_19 ;
break;
case V_26 :
V_12 [ 1 ] = ( V_9 -> V_23 & V_18 ) ? V_27 : V_28 ;
return V_11 -> V_29 ;
break;
default:
return - V_30 ;
}
F_5 ( V_14 -> V_24 , V_14 -> V_31 + V_32 ) ;
return V_11 -> V_29 ;
}
static int F_6 ( struct V_6 * V_7 ,
struct V_8 * V_9 ,
struct V_10 * V_11 ,
unsigned int * V_12 )
{
struct V_13 * V_14 = V_7 -> V_15 ;
void T_1 * V_33 = V_14 -> V_31 + V_34 ;
void T_1 * V_35 = V_14 -> V_31 + V_36 ;
unsigned int V_16 = V_12 [ 0 ] ;
unsigned int V_18 = V_12 [ 1 ] ;
unsigned int V_37 ;
V_16 &= V_9 -> V_23 ;
if ( V_16 ) {
V_9 -> V_3 &= ~ V_16 ;
V_9 -> V_3 |= ( V_18 & V_16 ) ;
if ( V_16 & 0x0000ffff )
F_5 ( ( V_9 -> V_3 & 0xffff ) , V_33 ) ;
if ( V_16 & 0xffff0000 )
F_5 ( ( ( V_9 -> V_3 >> 16 ) & 0xffff ) , V_35 ) ;
}
if ( V_9 -> V_23 & 0x0000ffff )
V_37 = V_9 -> V_3 & 0xffff ;
else
V_37 = F_7 ( V_33 ) ;
if ( V_9 -> V_23 & 0xffff0000 )
V_37 |= ( V_9 -> V_3 & 0xffff0000 ) ;
else
V_37 |= ( F_7 ( V_35 ) << 16 ) ;
V_12 [ 1 ] = V_37 ;
return V_11 -> V_29 ;
}
static int F_8 ( struct V_6 * V_7 ,
struct V_8 * V_9 ,
struct V_10 * V_11 ,
unsigned int * V_12 )
{
struct V_13 * V_14 = V_7 -> V_15 ;
unsigned int V_38 = F_4 ( V_11 -> V_17 ) ;
unsigned int V_39 = F_9 ( V_11 -> V_17 ) ;
unsigned int V_40 = F_10 ( V_11 -> V_17 ) ;
unsigned short V_37 ;
int V_41 ;
V_14 -> V_42 &= 0xFFFC ;
F_5 ( V_14 -> V_42 , V_14 -> V_31 + V_43 ) ;
V_14 -> V_24 &= ~ ( V_44 | V_45 ) ;
F_5 ( V_14 -> V_24 , V_14 -> V_31 + V_32 ) ;
F_5 ( 0x00 , V_14 -> V_31 + V_46 ) ;
V_14 -> V_24 |= ( V_44 | V_45 ) ;
F_5 ( V_14 -> V_24 , V_14 -> V_31 + V_32 ) ;
V_37 = V_38 & 0x0f ;
V_37 |= ( V_39 & 0x03 ) << 4 ;
V_37 |= ( V_39 & 0x04 ) << 4 ;
V_37 |= ( ( V_40 & V_47 ) ? 0x80 : 0 ) ;
F_5 ( V_37 & 0xff , V_14 -> V_31 + V_48 ) ;
V_14 -> V_42 |= V_49 ;
F_5 ( V_14 -> V_42 , V_14 -> V_31 + V_43 ) ;
F_7 ( V_14 -> V_31 + V_50 ) ;
for ( V_41 = 100000 ; V_41 > 0 ; V_41 -- )
if ( ! ( F_7 ( V_14 -> V_31 + V_51 ) & 0x0004 ) )
break;
if ( V_41 ) {
V_37 = F_7 ( V_14 -> V_31 + V_52 ) ;
V_37 = ( V_37 ^ 0x800 ) & 0x0fff ;
V_12 [ 0 ] = V_37 ;
} else {
F_11 ( V_7 -> V_53 , L_1 ) ;
return - V_54 ;
}
V_14 -> V_42 &= 0xFFFC ;
F_5 ( V_14 -> V_42 , V_14 -> V_31 + V_43 ) ;
return 1 ;
}
static int F_12 ( struct V_6 * V_7 ,
struct V_8 * V_9 ,
struct V_10 * V_11 ,
unsigned int * V_12 )
{
struct V_13 * V_14 = V_7 -> V_15 ;
unsigned int V_38 = F_4 ( V_11 -> V_17 ) ;
unsigned int V_39 = F_9 ( V_11 -> V_17 ) ;
int V_41 ;
V_14 -> V_24 |= V_55 ;
F_5 ( V_14 -> V_24 , V_14 -> V_31 + V_32 ) ;
V_14 -> V_24 |= V_56 ;
F_5 ( V_14 -> V_24 , V_14 -> V_31 + V_32 ) ;
for ( V_41 = 0 ; V_41 < V_11 -> V_29 ; V_41 ++ ) {
V_14 -> V_57 &= ~ ( 0x0880 >> V_38 ) ;
if ( V_39 == 0 )
V_14 -> V_57 |=
( ( V_58 | V_59 ) >> V_38 ) ;
else if ( V_39 == 1 )
V_14 -> V_57 |=
( ( V_58 | V_60 ) >> V_38 ) ;
}
F_5 ( V_14 -> V_57 ,
V_14 -> V_31 + V_61 ) ;
F_7 ( V_14 -> V_31 + V_62 ) ;
for ( V_41 = 0 ; V_41 < V_11 -> V_29 ; V_41 ++ ) {
F_5 ( ( V_12 [ 0 ] & V_9 -> V_63 ) ,
V_14 -> V_31 + V_64 + ( V_38 << 1 ) ) ;
V_14 -> V_65 [ V_38 ] = ( V_12 [ 0 ] & V_9 -> V_63 ) ;
}
F_7 ( V_14 -> V_31 + V_66 ) ;
return V_11 -> V_29 ;
}
static int F_13 ( struct V_6 * V_7 ,
struct V_8 * V_9 ,
struct V_10 * V_11 ,
unsigned int * V_12 )
{
struct V_13 * V_14 = V_7 -> V_15 ;
unsigned int V_38 = F_4 ( V_11 -> V_17 ) ;
int V_41 ;
for ( V_41 = 0 ; V_41 < V_11 -> V_29 ; V_41 ++ )
V_12 [ V_41 ] = V_14 -> V_65 [ V_38 ] ;
return V_11 -> V_29 ;
}
static int F_14 ( struct V_6 * V_7 ,
const T_2 * V_12 , T_3 V_67 ,
unsigned long V_68 )
{
struct V_13 * V_14 = V_7 -> V_15 ;
unsigned int V_69 ;
unsigned int V_70 ;
unsigned int V_41 ;
F_15 ( 0x00 , V_14 -> V_71 + V_72 ) ;
V_69 = F_7 ( V_14 -> V_31 + V_73 ) ;
F_1 ( 1 ) ;
F_16 ( 0x00 , V_14 -> V_31 + 0x0 ) ;
F_1 ( 1 ) ;
if ( V_67 < 16 )
return - V_30 ;
V_70 = ( ( ( unsigned int ) V_12 [ 0 ] & 0xff ) << 24 ) +
( ( ( unsigned int ) V_12 [ 1 ] & 0xff ) << 16 ) +
( ( ( unsigned int ) V_12 [ 2 ] & 0xff ) << 8 ) +
( ( unsigned int ) V_12 [ 3 ] & 0xff ) ;
for ( V_41 = 0 ; V_41 < V_70 ; V_41 ++ )
F_16 ( ( V_12 [ 16 + V_41 ] & 0xff ) ,
V_14 -> V_31 + 0x0 ) ;
for ( V_41 = 0 ; V_41 < 5 ; V_41 ++ )
F_16 ( 0x00 , V_14 -> V_31 + 0x0 ) ;
V_69 = F_17 ( V_14 -> V_71 + V_72 ) ;
if ( V_69 & V_74 ) {
F_15 ( 0x00 , V_14 -> V_71 + V_72 ) ;
F_11 ( V_7 -> V_53 , L_2 ) ;
return - V_54 ;
}
F_1 ( 1 ) ;
F_15 ( V_75 |
V_76 |
V_77 ,
V_14 -> V_71 + V_72 ) ;
return 0 ;
}
static int F_18 ( struct V_6 * V_7 )
{
struct V_13 * V_14 = V_7 -> V_15 ;
F_5 ( 0x00 , V_14 -> V_31 + V_43 ) ;
F_5 ( 0x00 , V_14 -> V_31 + V_32 ) ;
F_5 ( 0x00 , V_14 -> V_31 + V_46 ) ;
F_5 ( 0x00 , V_14 -> V_31 + V_61 ) ;
V_14 -> V_57 = 0 ;
V_14 -> V_42 = 0 ;
V_14 -> V_24 = 0 ;
return 0 ;
}
static int F_19 ( struct V_6 * V_7 ,
unsigned long V_68 )
{
struct V_78 * V_79 = F_20 ( V_7 ) ;
const struct V_80 * V_81 = NULL ;
struct V_13 * V_14 ;
struct V_8 * V_9 ;
int V_82 ;
if ( V_68 < F_21 ( V_83 ) )
V_81 = & V_83 [ V_68 ] ;
if ( ! V_81 )
return - V_84 ;
V_7 -> V_85 = V_81 ;
V_7 -> V_86 = V_81 -> V_87 ;
V_14 = F_22 ( sizeof( * V_14 ) , V_88 ) ;
if ( ! V_14 )
return - V_89 ;
V_7 -> V_15 = V_14 ;
V_82 = F_23 ( V_7 ) ;
if ( V_82 )
return V_82 ;
V_14 -> V_71 = F_24 ( V_79 , 0 ) ;
if ( ! V_14 -> V_71 )
return - V_89 ;
V_14 -> V_31 = F_24 ( V_79 , 2 ) ;
if ( ! V_14 -> V_31 )
return - V_89 ;
if ( V_81 -> V_90 ) {
V_82 = F_25 ( V_7 , & F_20 ( V_7 ) -> V_7 ,
V_91 ,
F_14 , 0 ) ;
if ( V_82 < 0 )
return V_82 ;
}
F_18 ( V_7 ) ;
V_82 = F_26 ( V_7 , 3 ) ;
if ( V_82 )
return V_82 ;
V_9 = & V_7 -> V_92 [ 0 ] ;
V_9 -> type = V_93 ;
V_9 -> V_94 = V_95 | V_96 ;
V_9 -> V_97 = 16 ;
V_9 -> V_63 = 0x0fff ;
V_9 -> V_98 = 16 ;
V_9 -> V_99 = & V_100 ;
V_9 -> V_101 = F_8 ;
V_9 = & V_7 -> V_92 [ 1 ] ;
if ( V_81 -> V_102 ) {
V_9 -> type = V_103 ;
V_9 -> V_94 = V_104 | V_96 ;
V_9 -> V_97 = 4 ;
V_9 -> V_63 = 0x0fff ;
V_9 -> V_98 = 4 ;
V_9 -> V_99 = & V_105 ;
V_9 -> V_101 = F_13 ;
V_9 -> V_106 = F_12 ;
} else {
V_9 -> type = V_107 ;
}
V_9 = & V_7 -> V_92 [ 2 ] ;
V_9 -> type = V_108 ;
V_9 -> V_94 = V_95 | V_104 ;
V_9 -> V_97 = 32 ;
V_9 -> V_63 = 1 ;
V_9 -> V_98 = 32 ;
V_9 -> V_99 = & V_109 ;
V_9 -> V_110 = F_6 ;
V_9 -> V_111 = F_3 ;
V_9 -> V_23 = 0 ;
F_27 ( V_7 -> V_53 , L_3 ,
V_7 -> V_112 -> V_113 , V_7 -> V_86 ) ;
return 0 ;
}
static void F_28 ( struct V_6 * V_7 )
{
struct V_13 * V_14 = V_7 -> V_15 ;
if ( V_14 ) {
if ( V_14 -> V_31 ) {
F_18 ( V_7 ) ;
F_29 ( V_14 -> V_31 ) ;
}
if ( V_14 -> V_71 )
F_29 ( V_14 -> V_71 ) ;
}
F_30 ( V_7 ) ;
}
static int F_31 ( struct V_78 * V_7 ,
const struct V_114 * V_115 )
{
return F_32 ( V_7 , & V_116 , V_115 -> V_117 ) ;
}
