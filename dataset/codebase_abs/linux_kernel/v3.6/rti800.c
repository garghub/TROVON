static T_1 F_1 ( int V_1 , void * V_2 )
{
return V_3 ;
}
static int F_2 ( struct V_4 * V_2 ,
struct V_5 * V_6 ,
struct V_7 * V_8 , unsigned int * V_9 )
{
int V_10 , V_11 ;
int V_12 ;
int V_13 = F_3 ( V_8 -> V_14 ) ;
unsigned V_15 = F_4 ( V_8 -> V_14 ) ;
unsigned V_16 ;
F_5 ( V_2 -> V_17 + V_18 ) ;
F_6 ( 0 , V_2 -> V_17 + V_19 ) ;
V_16 = V_13 | ( V_15 << 5 ) ;
if ( V_16 != V_20 -> V_16 ) {
V_20 -> V_16 = V_16 ;
F_6 ( V_20 -> V_16 , V_2 -> V_17 + V_21 ) ;
if ( V_8 -> V_22 > 0 ) {
F_7 ( V_15 >= F_8 ( V_23 ) ) ;
F_9 ( V_23 [ V_15 ] ) ;
}
}
for ( V_10 = 0 ; V_10 < V_8 -> V_22 ; V_10 ++ ) {
F_6 ( 0 , V_2 -> V_17 + V_24 ) ;
for ( V_11 = V_25 ; V_11 ; V_11 -- ) {
V_12 = F_5 ( V_2 -> V_17 + V_26 ) ;
if ( V_12 & V_27 ) {
F_10 ( V_28 L_1 ) ;
F_6 ( 0 , V_2 -> V_17 + V_19 ) ;
return - V_29 ;
}
if ( V_12 & V_30 )
break;
F_9 ( 1 ) ;
}
if ( V_11 == 0 ) {
F_10 ( V_28 L_2 ) ;
return - V_31 ;
}
V_9 [ V_10 ] = F_5 ( V_2 -> V_17 + V_32 ) ;
V_9 [ V_10 ] |= ( 0xf & F_5 ( V_2 -> V_17 + V_18 ) ) << 8 ;
if ( V_20 -> V_33 == V_34 )
V_9 [ V_10 ] ^= 0x800 ;
}
return V_10 ;
}
static int F_11 ( struct V_4 * V_2 ,
struct V_5 * V_6 ,
struct V_7 * V_8 , unsigned int * V_9 )
{
int V_10 ;
int V_13 = F_3 ( V_8 -> V_14 ) ;
for ( V_10 = 0 ; V_10 < V_8 -> V_22 ; V_10 ++ )
V_9 [ V_10 ] = V_20 -> V_35 [ V_13 ] ;
return V_10 ;
}
static int F_12 ( struct V_4 * V_2 ,
struct V_5 * V_6 ,
struct V_7 * V_8 , unsigned int * V_9 )
{
int V_13 = F_3 ( V_8 -> V_14 ) ;
int V_36 ;
int V_10 ;
for ( V_10 = 0 ; V_10 < V_8 -> V_22 ; V_10 ++ ) {
V_20 -> V_35 [ V_13 ] = V_36 = V_9 [ V_10 ] ;
if ( V_20 -> V_37 == V_38 )
V_36 ^= 0x800 ;
F_6 ( V_36 & 0xff ,
V_2 -> V_17 + ( V_13 ? V_39 : V_40 ) ) ;
F_6 ( V_36 >> 8 ,
V_2 -> V_17 + ( V_13 ? V_41 : V_42 ) ) ;
}
return V_10 ;
}
static int F_13 ( struct V_4 * V_2 ,
struct V_5 * V_6 ,
struct V_7 * V_8 , unsigned int * V_9 )
{
V_9 [ 1 ] = F_5 ( V_2 -> V_17 + V_43 ) ;
return V_8 -> V_22 ;
}
static int F_14 ( struct V_4 * V_2 ,
struct V_5 * V_6 ,
struct V_7 * V_8 , unsigned int * V_9 )
{
if ( V_9 [ 0 ] ) {
V_6 -> V_44 &= ~ V_9 [ 0 ] ;
V_6 -> V_44 |= V_9 [ 0 ] & V_9 [ 1 ] ;
F_6 ( V_6 -> V_44 ^ 0xff , V_2 -> V_17 + V_45 ) ;
}
V_9 [ 1 ] = V_6 -> V_44 ;
return V_8 -> V_22 ;
}
static int F_15 ( struct V_4 * V_2 , struct V_46 * V_47 )
{
const struct V_48 * V_49 = F_16 ( V_2 ) ;
unsigned int V_1 ;
unsigned long V_17 ;
int V_50 ;
struct V_5 * V_6 ;
V_17 = V_47 -> V_51 [ 0 ] ;
F_10 ( V_52 L_3 , V_2 -> V_53 , V_17 ) ;
if ( ! F_17 ( V_17 , V_54 , L_4 ) ) {
F_10 ( V_28 L_5 ) ;
return - V_29 ;
}
V_2 -> V_17 = V_17 ;
#ifdef F_18
F_10 ( V_55 L_6 ,
F_5 ( V_2 -> V_17 + 0 ) ,
F_5 ( V_2 -> V_17 + 1 ) ,
F_5 ( V_2 -> V_17 + 2 ) ,
F_5 ( V_2 -> V_17 + 3 ) , F_5 ( V_2 -> V_17 + 4 ) ) ;
#endif
F_6 ( 0 , V_2 -> V_17 + V_26 ) ;
F_5 ( V_2 -> V_17 + V_18 ) ;
F_6 ( 0 , V_2 -> V_17 + V_19 ) ;
V_1 = V_47 -> V_51 [ 1 ] ;
if ( V_1 ) {
F_10 ( V_52 L_7 , V_1 ) ;
V_50 = F_19 ( V_1 , F_1 , 0 , L_4 , V_2 ) ;
if ( V_50 < 0 ) {
F_10 ( V_28 L_8 ) ;
return V_50 ;
}
V_2 -> V_1 = V_1 ;
} else {
F_10 ( V_52 L_9 ) ;
}
V_2 -> V_56 = V_49 -> V_57 ;
V_50 = F_20 ( V_2 , 4 ) ;
if ( V_50 )
return V_50 ;
V_50 = F_21 ( V_2 , sizeof( struct V_58 ) ) ;
if ( V_50 < 0 )
return V_50 ;
V_20 -> V_59 = V_47 -> V_51 [ 2 ] ;
V_20 -> V_60 = V_47 -> V_51 [ 3 ] ;
V_20 -> V_33 = V_47 -> V_51 [ 4 ] ;
V_20 -> V_61 = V_47 -> V_51 [ 5 ] ;
V_20 -> V_37 = V_47 -> V_51 [ 6 ] ;
V_20 -> V_62 = V_47 -> V_51 [ 7 ] ;
V_20 -> V_63 = V_47 -> V_51 [ 8 ] ;
V_20 -> V_16 = - 1 ;
V_6 = V_2 -> V_64 + 0 ;
V_6 -> type = V_65 ;
V_6 -> V_66 = V_67 | V_68 ;
V_6 -> V_69 = ( V_20 -> V_59 ? 16 : 8 ) ;
V_6 -> V_70 = F_2 ;
V_6 -> V_71 = 0xfff ;
switch ( V_20 -> V_60 ) {
case V_72 :
V_6 -> V_73 = & V_74 ;
break;
case V_75 :
V_6 -> V_73 = & V_76 ;
break;
case V_77 :
V_6 -> V_73 = & V_78 ;
break;
}
V_6 ++ ;
if ( V_49 -> V_79 ) {
V_6 -> type = V_80 ;
V_6 -> V_66 = V_81 ;
V_6 -> V_69 = 2 ;
V_6 -> V_70 = F_11 ;
V_6 -> V_82 = F_12 ;
V_6 -> V_71 = 0xfff ;
V_6 -> V_83 = V_20 -> V_84 ;
switch ( V_20 -> V_61 ) {
case V_85 :
V_20 -> V_84 [ 0 ] = & V_86 ;
break;
case V_87 :
V_20 -> V_84 [ 0 ] = & V_88 ;
break;
}
switch ( V_20 -> V_62 ) {
case V_85 :
V_20 -> V_84 [ 1 ] = & V_86 ;
break;
case V_87 :
V_20 -> V_84 [ 1 ] = & V_88 ;
break;
}
} else {
V_6 -> type = V_89 ;
}
V_6 ++ ;
V_6 -> type = V_90 ;
V_6 -> V_66 = V_67 ;
V_6 -> V_69 = 8 ;
V_6 -> V_91 = F_13 ;
V_6 -> V_71 = 1 ;
V_6 -> V_73 = & V_92 ;
V_6 ++ ;
V_6 -> type = V_93 ;
V_6 -> V_66 = V_81 ;
V_6 -> V_69 = 8 ;
V_6 -> V_91 = F_14 ;
V_6 -> V_71 = 1 ;
V_6 -> V_73 = & V_92 ;
#if 0
s++;
s->type = COMEDI_SUBD_TIMER;
#endif
return 0 ;
}
static void F_22 ( struct V_4 * V_2 )
{
if ( V_2 -> V_17 )
F_23 ( V_2 -> V_17 , V_54 ) ;
if ( V_2 -> V_1 )
F_24 ( V_2 -> V_1 , V_2 ) ;
}
