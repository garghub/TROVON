static inline bool F_1 ( const struct V_1 * V_2 )
{
return V_3 && V_2 -> V_4 == V_5 ;
}
static inline bool F_2 ( const struct V_1 * V_2 )
{
return V_6 && V_2 -> V_4 == V_7 ;
}
static int F_3 ( struct V_8 * V_9 , struct V_10 * V_11 ,
struct V_12 * V_13 , unsigned int * V_14 )
{
const struct V_1 * V_15 = F_4 ( V_9 ) ;
struct V_16 * V_17 = V_9 -> V_18 ;
int V_19 , V_20 ;
int V_21 ;
int V_22 ;
int V_23 , V_24 ;
V_21 = F_5 ( V_13 -> V_25 ) ;
V_22 = F_6 ( V_13 -> V_25 ) ;
F_7 ( V_9 -> V_26 + V_27 ) ;
F_7 ( V_9 -> V_26 + V_28 ) ;
F_8 ( & V_9 -> V_29 ) ;
V_17 -> V_30 &= ~ V_31 ;
V_17 -> V_30 |= F_9 ( V_21 ) ;
F_10 ( V_17 -> V_30 , V_9 -> V_26 + V_32 ) ;
F_11 ( & V_9 -> V_29 ) ;
if ( V_11 -> V_33 -> V_34 > 1 ) {
V_22 = F_6 ( V_13 -> V_25 ) ;
F_10 ( V_17 -> V_35 [ V_22 ] ,
V_9 -> V_26 + V_36 ) ;
}
for ( V_20 = 0 ; V_20 < V_13 -> V_20 ; V_20 ++ ) {
if ( V_15 -> V_37 == 16 )
if ( F_7 ( V_9 -> V_26 + V_28 ) & 0x80 )
F_12 ( V_9 -> V_38 , L_1 ) ;
F_13 ( 0 , V_9 -> V_26 + V_39 ) ;
for ( V_19 = 0 ; V_19 < V_40 ; V_19 ++ ) {
if ( ! ( F_7 ( V_9 -> V_26 + V_41 ) & V_42 ) )
break;
}
if ( V_19 == V_40 ) {
F_14 ( V_9 -> V_38 , L_2 ) ;
return - V_43 ;
}
V_24 = F_7 ( V_9 -> V_26 + V_28 ) ;
V_23 = F_7 ( V_9 -> V_26 + V_27 ) ;
if ( V_15 -> V_44 == V_45 ) {
V_14 [ V_20 ] = ( V_23 >> 4 ) | ( V_24 << 4 ) ;
} else if ( V_15 -> V_44 == V_46 ) {
V_14 [ V_20 ] = ( V_24 << 8 ) + V_23 ;
} else if ( V_15 -> V_44 == V_47 ) {
if ( V_24 & 0x80 )
V_14 [ V_20 ] = ( 1 << 15 ) | V_23 | ( ( V_24 & 0x7f ) << 8 ) ;
else
V_14 [ V_20 ] = ( 1 << 15 ) - ( V_23 | ( V_24 & 0x7f ) << 8 ) ;
} else {
F_15 ( V_9 , L_3 ) ;
return - 1 ;
}
}
return V_20 ;
}
static int F_16 ( struct V_8 * V_9 , struct V_10 * V_11 ,
struct V_12 * V_13 , unsigned int * V_14 )
{
V_14 [ 0 ] = 0 ;
V_14 [ 1 ] = F_17 ( F_7 ( V_9 -> V_26 + V_41 ) ) ;
return V_13 -> V_20 ;
}
static int F_18 ( struct V_8 * V_9 , struct V_10 * V_11 ,
struct V_12 * V_13 , unsigned int * V_14 )
{
struct V_16 * V_17 = V_9 -> V_18 ;
int V_48 ;
V_48 = ( V_17 -> V_30 >> 4 ) & 0xf ;
V_48 &= ~ V_14 [ 0 ] ;
V_48 |= V_14 [ 0 ] & V_14 [ 1 ] ;
F_8 ( & V_9 -> V_29 ) ;
V_17 -> V_30 &= ~ V_49 ;
V_17 -> V_30 |= F_19 ( V_48 ) ;
F_10 ( V_17 -> V_30 , V_9 -> V_26 + V_32 ) ;
F_11 ( & V_9 -> V_29 ) ;
V_14 [ 1 ] = V_48 ;
return V_13 -> V_20 ;
}
static int F_20 ( struct V_8 * V_9 ,
struct V_10 * V_11 ,
struct V_12 * V_13 , unsigned int * V_14 )
{
V_14 [ 0 ] = 0 ;
V_14 [ 1 ] = F_7 ( V_9 -> V_26 + V_50 ) ;
return V_13 -> V_20 ;
}
static int F_21 ( struct V_8 * V_9 ,
struct V_10 * V_11 ,
struct V_12 * V_13 , unsigned int * V_14 )
{
struct V_16 * V_17 = V_9 -> V_18 ;
V_17 -> V_51 &= ~ V_14 [ 0 ] ;
V_17 -> V_51 |= V_14 [ 0 ] & V_14 [ 1 ] ;
F_10 ( V_17 -> V_51 , V_9 -> V_26 + V_50 ) ;
V_14 [ 1 ] = V_17 -> V_51 ;
return V_13 -> V_20 ;
}
static void F_22 ( struct V_8 * V_9 ,
unsigned int V_21 , unsigned int V_14 )
{
const struct V_1 * V_15 = F_4 ( V_9 ) ;
struct V_16 * V_17 = V_9 -> V_18 ;
unsigned char V_23 ;
unsigned char V_24 ;
V_23 = V_14 & 0xff ;
V_24 = ( V_14 >> 8 ) & 0xff ;
if ( V_15 -> V_52 ) {
F_10 ( V_23 , V_9 -> V_26 + F_23 ( V_21 ) ) ;
F_10 ( V_24 , V_9 -> V_26 + F_24 ( V_21 ) ) ;
F_7 ( V_9 -> V_26 + V_50 ) ;
} else {
F_10 ( V_23 , V_9 -> V_26 + F_25 ( V_21 ) ) ;
F_10 ( V_24 , V_9 -> V_26 + F_26 ( V_21 ) ) ;
F_7 ( V_9 -> V_26 + V_53 ) ;
}
V_17 -> V_54 [ V_21 ] = V_14 ;
}
static void F_27 ( struct V_8 * V_9 ,
struct V_10 * V_11 )
{
int V_20 ;
unsigned int V_14 ;
V_14 = V_11 -> V_55 / 2 ;
for ( V_20 = 0 ; V_20 < V_11 -> V_56 ; V_20 ++ )
F_22 ( V_9 , V_20 , V_14 ) ;
}
static int F_28 ( struct V_8 * V_9 ,
struct V_10 * V_11 ,
struct V_12 * V_13 , unsigned int * V_14 )
{
unsigned int V_20 ;
unsigned int V_21 ;
V_21 = F_5 ( V_13 -> V_25 ) ;
for ( V_20 = 0 ; V_20 < V_13 -> V_20 ; V_20 ++ )
F_22 ( V_9 , V_21 , * V_14 ) ;
return V_20 ;
}
static int F_29 ( struct V_8 * V_9 ,
struct V_10 * V_11 ,
struct V_12 * V_13 , unsigned int * V_14 )
{
struct V_16 * V_17 = V_9 -> V_18 ;
unsigned int V_20 ;
unsigned int V_21 ;
V_21 = F_5 ( V_13 -> V_25 ) ;
for ( V_20 = 0 ; V_20 < V_13 -> V_20 ; V_20 ++ )
V_14 [ V_20 ] = V_17 -> V_54 [ V_21 ] ;
return V_20 ;
}
static void F_30 ( struct V_8 * V_9 )
{
const struct V_1 * V_15 = F_4 ( V_9 ) ;
unsigned long V_57 = V_9 -> V_26 + V_15 -> V_58 ;
unsigned int V_59 = V_60 | V_61 ;
int V_19 ;
for ( V_19 = 0 ; V_19 < 3 ; ++ V_19 )
F_31 ( V_57 , 0 , V_19 , V_59 ) ;
}
static int F_32 ( struct V_8 * V_9 ,
struct V_10 * V_11 ,
struct V_12 * V_13 , unsigned int * V_14 )
{
const struct V_1 * V_15 = F_4 ( V_9 ) ;
unsigned long V_57 = V_9 -> V_26 + V_15 -> V_58 ;
int V_21 = V_13 -> V_25 ;
V_14 [ 0 ] = F_33 ( V_57 , 0 , V_21 ) ;
return 1 ;
}
static int F_34 ( struct V_8 * V_9 ,
struct V_10 * V_11 ,
struct V_12 * V_13 , unsigned int * V_14 )
{
const struct V_1 * V_15 = F_4 ( V_9 ) ;
unsigned long V_57 = V_9 -> V_26 + V_15 -> V_58 ;
int V_21 = V_13 -> V_25 ;
F_35 ( V_57 , 0 , V_21 , V_14 [ 0 ] ) ;
return 1 ;
}
static int F_36 ( struct V_8 * V_9 ,
struct V_10 * V_11 ,
struct V_12 * V_13 , unsigned int * V_14 )
{
const struct V_1 * V_15 = F_4 ( V_9 ) ;
unsigned long V_57 = V_9 -> V_26 + V_15 -> V_58 ;
int V_21 = V_13 -> V_25 ;
switch ( V_14 [ 0 ] ) {
case V_62 :
F_31 ( V_57 , 0 , V_21 , V_14 [ 1 ] ) ;
break;
case V_63 :
V_14 [ 1 ] = F_37 ( V_57 , 0 , V_21 ) ;
break;
default:
return - V_64 ;
break;
}
return 2 ;
}
int F_38 ( struct V_8 * V_9 , unsigned long V_26 )
{
const struct V_1 * V_15 = F_4 ( V_9 ) ;
struct V_16 * V_17 = V_9 -> V_18 ;
struct V_10 * V_11 ;
int V_65 ;
V_9 -> V_26 = V_26 ;
V_9 -> V_66 = V_15 -> V_67 ;
V_65 = F_39 ( V_9 , 6 ) ;
if ( V_65 )
return V_65 ;
V_11 = & V_9 -> V_68 [ 0 ] ;
if ( V_15 -> V_37 ) {
V_11 -> type = V_69 ;
V_11 -> V_70 = V_71 | V_72 ;
V_11 -> V_56 = 8 ;
V_11 -> V_55 = ( 1 << V_15 -> V_37 ) - 1 ;
V_11 -> V_33 = V_73 [ V_15 -> V_74 ] ;
V_11 -> V_75 = F_3 ;
V_17 -> V_35 = V_76 [ V_15 -> V_74 ] ;
} else {
V_11 -> type = V_77 ;
}
V_11 = & V_9 -> V_68 [ 1 ] ;
if ( V_15 -> V_78 ) {
V_11 -> type = V_79 ;
V_11 -> V_70 = V_80 ;
V_11 -> V_56 = 2 ;
V_11 -> V_55 = ( 1 << V_15 -> V_78 ) - 1 ;
V_11 -> V_33 = & V_81 ;
V_11 -> V_82 = F_28 ;
V_11 -> V_75 = F_29 ;
F_27 ( V_9 , V_11 ) ;
} else {
V_11 -> type = V_77 ;
}
V_11 = & V_9 -> V_68 [ 2 ] ;
if ( V_15 -> V_83 ) {
V_11 -> type = V_84 ;
V_11 -> V_70 = V_71 ;
V_11 -> V_56 = V_15 -> V_83 ;
V_11 -> V_55 = 1 ;
V_11 -> V_33 = & V_85 ;
V_11 -> V_86 =
V_15 -> V_52 ? F_20 : F_16 ;
} else {
V_11 -> type = V_77 ;
}
V_11 = & V_9 -> V_68 [ 3 ] ;
if ( V_15 -> V_87 ) {
V_11 -> type = V_88 ;
V_11 -> V_70 = V_80 | V_71 ;
V_11 -> V_56 = V_15 -> V_87 ;
V_11 -> V_55 = 1 ;
V_11 -> V_33 = & V_85 ;
V_11 -> V_86 =
V_15 -> V_52 ? F_21 : F_18 ;
} else {
V_11 -> type = V_77 ;
}
V_11 = & V_9 -> V_68 [ 4 ] ;
if ( V_15 -> V_89 != 0 ) {
F_40 ( V_9 , V_11 , NULL , ( unsigned long ) ( V_9 -> V_26 +
V_15 ->
V_89 ) ) ;
} else {
V_11 -> type = V_77 ;
}
V_11 = & V_9 -> V_68 [ 5 ] ;
if ( V_15 -> V_58 != 0 ) {
V_11 -> type = V_90 ;
V_11 -> V_70 = V_80 | V_71 ;
V_11 -> V_56 = 3 ;
V_11 -> V_55 = 0xFFFF ;
V_11 -> V_75 = F_32 ;
V_11 -> V_82 = F_34 ;
V_11 -> V_91 = F_36 ;
F_30 ( V_9 ) ;
} else {
V_11 -> type = V_77 ;
}
return 0 ;
}
static const struct V_1 *
F_41 ( struct V_92 * V_93 )
{
#if V_94
unsigned int V_19 ;
for ( V_19 = 0 ; V_19 < F_42 ( V_95 ) ; V_19 ++ )
if ( F_2 ( & V_95 [ V_19 ] ) &&
V_93 -> V_96 == V_95 [ V_19 ] . V_97 )
return & V_95 [ V_19 ] ;
#endif
return NULL ;
}
static int T_1 T_2
F_43 ( struct V_8 * V_9 , struct V_92 * V_93 )
{
unsigned long V_26 ;
int V_65 ;
if ( ! V_6 )
return - V_64 ;
V_65 = F_44 ( V_9 , sizeof( struct V_16 ) ) ;
if ( V_65 < 0 )
return V_65 ;
F_12 ( V_9 -> V_38 , L_4 , F_45 ( V_93 ) ) ;
V_9 -> V_98 = F_41 ( V_93 ) ;
if ( V_9 -> V_98 == NULL ) {
F_14 ( V_9 -> V_38 , L_5 ) ;
return - V_64 ;
}
F_46 ( V_9 , & V_93 -> V_9 ) ;
if ( F_47 ( V_93 , V_9 -> V_99 -> V_100 ) ) {
F_14 ( V_9 -> V_38 ,
L_6 ) ;
return - V_101 ;
}
V_26 = F_48 ( V_93 , 2 ) ;
return F_38 ( V_9 , V_26 ) ;
}
static int T_2
F_49 ( struct V_8 * V_9 , struct V_102 * V_103 )
{
const struct V_1 * V_15 = F_4 ( V_9 ) ;
struct V_16 * V_17 ;
int V_65 ;
unsigned long V_26 ;
V_65 = F_44 ( V_9 , sizeof( struct V_16 ) ) ;
if ( V_65 < 0 )
return V_65 ;
V_17 = V_9 -> V_18 ;
F_12 ( V_9 -> V_38 , L_7 ) ;
if ( F_2 ( V_15 ) ) {
F_14 ( V_9 -> V_38 ,
L_8 ,
V_15 -> V_67 ) ;
return - V_101 ;
} else if ( F_1 ( V_15 ) ) {
V_26 = V_103 -> V_104 [ 0 ] ;
F_12 ( V_9 -> V_38 , L_9 , V_26 ) ;
if ( ! F_50 ( V_26 , V_15 -> V_105 , V_106 ) ) {
F_14 ( V_9 -> V_38 , L_10 ) ;
return - V_101 ;
}
return F_38 ( V_9 , V_26 ) ;
} else
return - V_101 ;
}
void F_51 ( struct V_8 * V_9 )
{
if ( V_9 -> V_68 )
F_52 ( V_9 , & V_9 -> V_68 [ 4 ] ) ;
}
static void T_2 F_53 ( struct V_8 * V_9 )
{
const struct V_1 * V_15 = F_4 ( V_9 ) ;
if ( ! V_15 )
return;
F_51 ( V_9 ) ;
if ( F_1 ( V_15 ) ) {
if ( V_9 -> V_26 )
F_54 ( V_9 -> V_26 , V_15 -> V_105 ) ;
} else if ( F_2 ( V_15 ) ) {
struct V_92 * V_93 = F_55 ( V_9 ) ;
if ( V_93 ) {
if ( V_9 -> V_26 )
F_56 ( V_93 ) ;
}
}
}
static int T_1 F_57 ( struct V_92 * V_9 ,
const struct V_107 * V_108 )
{
return F_58 ( V_9 , & V_109 ) ;
}
static void T_3 F_59 ( struct V_92 * V_9 )
{
F_60 ( V_9 ) ;
}
static int T_4 F_61 ( void )
{
return 0 ;
}
static void T_5 F_62 ( void )
{
}
