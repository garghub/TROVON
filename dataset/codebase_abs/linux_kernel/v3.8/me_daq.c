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
const T_2 * V_12 , T_3 V_67 )
{
struct V_13 * V_14 = V_7 -> V_15 ;
unsigned int V_68 ;
unsigned int V_69 ;
unsigned int V_41 ;
F_15 ( 0x00 , V_14 -> V_70 + V_71 ) ;
V_68 = F_7 ( V_14 -> V_31 + V_72 ) ;
F_1 ( 1 ) ;
F_16 ( 0x00 , V_14 -> V_31 + 0x0 ) ;
F_1 ( 1 ) ;
if ( V_67 < 16 )
return - V_30 ;
V_69 = ( ( ( unsigned int ) V_12 [ 0 ] & 0xff ) << 24 ) +
( ( ( unsigned int ) V_12 [ 1 ] & 0xff ) << 16 ) +
( ( ( unsigned int ) V_12 [ 2 ] & 0xff ) << 8 ) +
( ( unsigned int ) V_12 [ 3 ] & 0xff ) ;
for ( V_41 = 0 ; V_41 < V_69 ; V_41 ++ )
F_16 ( ( V_12 [ 16 + V_41 ] & 0xff ) ,
V_14 -> V_31 + 0x0 ) ;
for ( V_41 = 0 ; V_41 < 5 ; V_41 ++ )
F_16 ( 0x00 , V_14 -> V_31 + 0x0 ) ;
V_68 = F_17 ( V_14 -> V_70 + V_71 ) ;
if ( V_68 & 0x20 ) {
F_15 ( 0x00 , V_14 -> V_70 + V_71 ) ;
F_11 ( V_7 -> V_53 , L_2 ) ;
return - V_54 ;
}
F_1 ( 1 ) ;
F_15 ( 0x43 , V_14 -> V_70 + V_71 ) ;
return 0 ;
}
static int F_18 ( struct V_6 * V_7 )
{
struct V_73 * V_74 = F_19 ( V_7 ) ;
const struct V_75 * V_76 ;
int V_77 ;
V_77 = F_20 ( & V_76 , V_78 , & V_74 -> V_7 ) ;
if ( V_77 )
return V_77 ;
V_77 = F_14 ( V_7 , V_76 -> V_12 , V_76 -> V_67 ) ;
F_21 ( V_76 ) ;
return V_77 ;
}
static int F_22 ( struct V_6 * V_7 )
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
static const void * F_23 ( struct V_6 * V_7 ,
struct V_73 * V_74 )
{
const struct V_79 * V_80 ;
int V_41 ;
for ( V_41 = 0 ; V_41 < F_24 ( V_81 ) ; V_41 ++ ) {
V_80 = & V_81 [ V_41 ] ;
if ( V_80 -> V_82 == V_74 -> V_83 )
return V_80 ;
}
return NULL ;
}
static int F_25 ( struct V_6 * V_7 ,
unsigned long V_84 )
{
struct V_73 * V_74 = F_19 ( V_7 ) ;
const struct V_79 * V_80 ;
struct V_13 * V_14 ;
struct V_8 * V_9 ;
int V_77 ;
V_80 = F_23 ( V_7 , V_74 ) ;
if ( ! V_80 )
return - V_85 ;
V_7 -> V_86 = V_80 ;
V_7 -> V_87 = V_80 -> V_88 ;
V_14 = F_26 ( sizeof( * V_14 ) , V_89 ) ;
if ( ! V_14 )
return - V_90 ;
V_7 -> V_15 = V_14 ;
V_77 = F_27 ( V_74 , V_7 -> V_87 ) ;
if ( V_77 )
return V_77 ;
V_7 -> V_91 = 1 ;
V_14 -> V_70 = F_28 ( F_29 ( V_74 , 0 ) ,
F_30 ( V_74 , 0 ) ) ;
if ( ! V_14 -> V_70 )
return - V_90 ;
V_14 -> V_31 = F_28 ( F_29 ( V_74 , 2 ) ,
F_30 ( V_74 , 2 ) ) ;
if ( ! V_14 -> V_31 )
return - V_90 ;
if ( V_80 -> V_82 == V_92 ) {
V_77 = F_18 ( V_7 ) ;
if ( V_77 < 0 )
return V_77 ;
}
F_22 ( V_7 ) ;
V_77 = F_31 ( V_7 , 3 ) ;
if ( V_77 )
return V_77 ;
V_9 = & V_7 -> V_93 [ 0 ] ;
V_9 -> type = V_94 ;
V_9 -> V_95 = V_96 | V_97 ;
V_9 -> V_98 = 16 ;
V_9 -> V_63 = 0x0fff ;
V_9 -> V_99 = 16 ;
V_9 -> V_100 = & V_101 ;
V_9 -> V_102 = F_8 ;
V_9 = & V_7 -> V_93 [ 1 ] ;
if ( V_80 -> V_103 ) {
V_9 -> type = V_104 ;
V_9 -> V_95 = V_105 | V_97 ;
V_9 -> V_98 = 4 ;
V_9 -> V_63 = 0x0fff ;
V_9 -> V_99 = 4 ;
V_9 -> V_100 = & V_106 ;
V_9 -> V_102 = F_13 ;
V_9 -> V_107 = F_12 ;
} else {
V_9 -> type = V_108 ;
}
V_9 = & V_7 -> V_93 [ 2 ] ;
V_9 -> type = V_109 ;
V_9 -> V_95 = V_96 | V_105 ;
V_9 -> V_98 = 32 ;
V_9 -> V_63 = 1 ;
V_9 -> V_99 = 32 ;
V_9 -> V_100 = & V_110 ;
V_9 -> V_111 = F_6 ;
V_9 -> V_112 = F_3 ;
V_9 -> V_23 = 0 ;
F_32 ( V_7 -> V_53 , L_3 ,
V_7 -> V_113 -> V_114 , V_7 -> V_87 ) ;
return 0 ;
}
static void F_33 ( struct V_6 * V_7 )
{
struct V_73 * V_74 = F_19 ( V_7 ) ;
struct V_13 * V_14 = V_7 -> V_15 ;
if ( V_14 ) {
if ( V_14 -> V_31 ) {
F_22 ( V_7 ) ;
F_34 ( V_14 -> V_31 ) ;
}
if ( V_14 -> V_70 )
F_34 ( V_14 -> V_70 ) ;
}
if ( V_74 ) {
if ( V_7 -> V_91 )
F_35 ( V_74 ) ;
}
}
static int F_36 ( struct V_73 * V_7 ,
const struct V_115 * V_116 )
{
return F_37 ( V_7 , & V_117 ) ;
}
static void F_38 ( struct V_73 * V_7 )
{
F_39 ( V_7 ) ;
}
