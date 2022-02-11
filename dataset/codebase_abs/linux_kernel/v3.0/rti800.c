static int T_1 F_1 ( void )
{
return F_2 ( & V_1 ) ;
}
static void T_2 F_3 ( void )
{
F_4 ( & V_1 ) ;
}
static T_3 F_5 ( int V_2 , void * V_3 )
{
return V_4 ;
}
static int F_6 ( struct V_5 * V_3 ,
struct V_6 * V_7 ,
struct V_8 * V_9 , unsigned int * V_10 )
{
int V_11 , V_12 ;
int V_13 ;
int V_14 = F_7 ( V_9 -> V_15 ) ;
unsigned V_16 = F_8 ( V_9 -> V_15 ) ;
unsigned V_17 ;
F_9 ( V_3 -> V_18 + V_19 ) ;
F_10 ( 0 , V_3 -> V_18 + V_20 ) ;
V_17 = V_14 | ( V_16 << 5 ) ;
if ( V_17 != V_21 -> V_17 ) {
V_21 -> V_17 = V_17 ;
F_10 ( V_21 -> V_17 , V_3 -> V_18 + V_22 ) ;
if ( V_9 -> V_23 > 0 ) {
F_11 ( V_16 >= F_12 ( V_24 ) ) ;
F_13 ( V_24 [ V_16 ] ) ;
}
}
for ( V_11 = 0 ; V_11 < V_9 -> V_23 ; V_11 ++ ) {
F_10 ( 0 , V_3 -> V_18 + V_25 ) ;
for ( V_12 = V_26 ; V_12 ; V_12 -- ) {
V_13 = F_9 ( V_3 -> V_18 + V_27 ) ;
if ( V_13 & V_28 ) {
F_14 ( V_29 L_1 ) ;
F_10 ( 0 , V_3 -> V_18 + V_20 ) ;
return - V_30 ;
}
if ( V_13 & V_31 )
break;
F_13 ( 1 ) ;
}
if ( V_12 == 0 ) {
F_14 ( V_29 L_2 ) ;
return - V_32 ;
}
V_10 [ V_11 ] = F_9 ( V_3 -> V_18 + V_33 ) ;
V_10 [ V_11 ] |= ( 0xf & F_9 ( V_3 -> V_18 + V_19 ) ) << 8 ;
if ( V_21 -> V_34 == V_35 )
V_10 [ V_11 ] ^= 0x800 ;
}
return V_11 ;
}
static int F_15 ( struct V_5 * V_3 ,
struct V_6 * V_7 ,
struct V_8 * V_9 , unsigned int * V_10 )
{
int V_11 ;
int V_14 = F_7 ( V_9 -> V_15 ) ;
for ( V_11 = 0 ; V_11 < V_9 -> V_23 ; V_11 ++ )
V_10 [ V_11 ] = V_21 -> V_36 [ V_14 ] ;
return V_11 ;
}
static int F_16 ( struct V_5 * V_3 ,
struct V_6 * V_7 ,
struct V_8 * V_9 , unsigned int * V_10 )
{
int V_14 = F_7 ( V_9 -> V_15 ) ;
int V_37 ;
int V_11 ;
for ( V_11 = 0 ; V_11 < V_9 -> V_23 ; V_11 ++ ) {
V_21 -> V_36 [ V_14 ] = V_37 = V_10 [ V_11 ] ;
if ( V_21 -> V_38 == V_39 )
V_37 ^= 0x800 ;
F_10 ( V_37 & 0xff ,
V_3 -> V_18 + ( V_14 ? V_40 : V_41 ) ) ;
F_10 ( V_37 >> 8 ,
V_3 -> V_18 + ( V_14 ? V_42 : V_43 ) ) ;
}
return V_11 ;
}
static int F_17 ( struct V_5 * V_3 ,
struct V_6 * V_7 ,
struct V_8 * V_9 , unsigned int * V_10 )
{
if ( V_9 -> V_23 != 2 )
return - V_44 ;
V_10 [ 1 ] = F_9 ( V_3 -> V_18 + V_45 ) ;
return 2 ;
}
static int F_18 ( struct V_5 * V_3 ,
struct V_6 * V_7 ,
struct V_8 * V_9 , unsigned int * V_10 )
{
if ( V_9 -> V_23 != 2 )
return - V_44 ;
if ( V_10 [ 0 ] ) {
V_7 -> V_46 &= ~ V_10 [ 0 ] ;
V_7 -> V_46 |= V_10 [ 0 ] & V_10 [ 1 ] ;
F_10 ( V_7 -> V_46 ^ 0xff , V_3 -> V_18 + V_47 ) ;
}
V_10 [ 1 ] = V_7 -> V_46 ;
return 2 ;
}
static int F_19 ( struct V_5 * V_3 , struct V_48 * V_49 )
{
unsigned int V_2 ;
unsigned long V_18 ;
int V_50 ;
struct V_6 * V_7 ;
V_18 = V_49 -> V_51 [ 0 ] ;
F_14 ( V_52 L_3 , V_3 -> V_53 , V_18 ) ;
if ( ! F_20 ( V_18 , V_54 , L_4 ) ) {
F_14 ( V_29 L_5 ) ;
return - V_30 ;
}
V_3 -> V_18 = V_18 ;
#ifdef F_21
F_14 ( V_55 L_6 ,
F_9 ( V_3 -> V_18 + 0 ) ,
F_9 ( V_3 -> V_18 + 1 ) ,
F_9 ( V_3 -> V_18 + 2 ) ,
F_9 ( V_3 -> V_18 + 3 ) , F_9 ( V_3 -> V_18 + 4 ) ) ;
#endif
F_10 ( 0 , V_3 -> V_18 + V_27 ) ;
F_9 ( V_3 -> V_18 + V_19 ) ;
F_10 ( 0 , V_3 -> V_18 + V_20 ) ;
V_2 = V_49 -> V_51 [ 1 ] ;
if ( V_2 ) {
F_14 ( V_52 L_7 , V_2 ) ;
V_50 = F_22 ( V_2 , F_5 , 0 , L_4 , V_3 ) ;
if ( V_50 < 0 ) {
F_14 ( V_29 L_8 ) ;
return V_50 ;
}
V_3 -> V_2 = V_2 ;
} else {
F_14 ( V_52 L_9 ) ;
}
V_3 -> V_56 = V_57 -> V_58 ;
V_50 = F_23 ( V_3 , 4 ) ;
if ( V_50 < 0 )
return V_50 ;
V_50 = F_24 ( V_3 , sizeof( struct V_59 ) ) ;
if ( V_50 < 0 )
return V_50 ;
V_21 -> V_60 = V_49 -> V_51 [ 2 ] ;
V_21 -> V_61 = V_49 -> V_51 [ 3 ] ;
V_21 -> V_34 = V_49 -> V_51 [ 4 ] ;
V_21 -> V_62 = V_49 -> V_51 [ 5 ] ;
V_21 -> V_38 = V_49 -> V_51 [ 6 ] ;
V_21 -> V_63 = V_49 -> V_51 [ 7 ] ;
V_21 -> V_64 = V_49 -> V_51 [ 8 ] ;
V_21 -> V_17 = - 1 ;
V_7 = V_3 -> V_65 + 0 ;
V_7 -> type = V_66 ;
V_7 -> V_67 = V_68 | V_69 ;
V_7 -> V_70 = ( V_21 -> V_60 ? 16 : 8 ) ;
V_7 -> V_71 = F_6 ;
V_7 -> V_72 = 0xfff ;
switch ( V_21 -> V_61 ) {
case V_73 :
V_7 -> V_74 = & V_75 ;
break;
case V_76 :
V_7 -> V_74 = & V_77 ;
break;
case V_78 :
V_7 -> V_74 = & V_79 ;
break;
}
V_7 ++ ;
if ( V_57 -> V_80 ) {
V_7 -> type = V_81 ;
V_7 -> V_67 = V_82 ;
V_7 -> V_70 = 2 ;
V_7 -> V_71 = F_15 ;
V_7 -> V_83 = F_16 ;
V_7 -> V_72 = 0xfff ;
V_7 -> V_84 = V_21 -> V_85 ;
switch ( V_21 -> V_62 ) {
case V_86 :
V_21 -> V_85 [ 0 ] = & V_87 ;
break;
case V_88 :
V_21 -> V_85 [ 0 ] = & V_89 ;
break;
}
switch ( V_21 -> V_63 ) {
case V_86 :
V_21 -> V_85 [ 1 ] = & V_87 ;
break;
case V_88 :
V_21 -> V_85 [ 1 ] = & V_89 ;
break;
}
} else {
V_7 -> type = V_90 ;
}
V_7 ++ ;
V_7 -> type = V_91 ;
V_7 -> V_67 = V_68 ;
V_7 -> V_70 = 8 ;
V_7 -> V_92 = F_17 ;
V_7 -> V_72 = 1 ;
V_7 -> V_74 = & V_93 ;
V_7 ++ ;
V_7 -> type = V_94 ;
V_7 -> V_67 = V_82 ;
V_7 -> V_70 = 8 ;
V_7 -> V_92 = F_18 ;
V_7 -> V_72 = 1 ;
V_7 -> V_74 = & V_93 ;
#if 0
s++;
s->type = COMEDI_SUBD_TIMER;
#endif
return 0 ;
}
static int F_25 ( struct V_5 * V_3 )
{
F_14 ( V_52 L_10 , V_3 -> V_53 ) ;
if ( V_3 -> V_18 )
F_26 ( V_3 -> V_18 , V_54 ) ;
if ( V_3 -> V_2 )
F_27 ( V_3 -> V_2 , V_3 ) ;
return 0 ;
}
