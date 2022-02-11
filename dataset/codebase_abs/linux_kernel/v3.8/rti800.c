static T_1 F_1 ( int V_1 , void * V_2 )
{
return V_3 ;
}
static int F_2 ( struct V_4 * V_2 ,
struct V_5 * V_6 ,
struct V_7 * V_8 , unsigned int * V_9 )
{
struct V_10 * V_11 = V_2 -> V_12 ;
int V_13 , V_14 ;
int V_15 ;
int V_16 = F_3 ( V_8 -> V_17 ) ;
unsigned V_18 = F_4 ( V_8 -> V_17 ) ;
unsigned V_19 ;
F_5 ( V_2 -> V_20 + V_21 ) ;
F_6 ( 0 , V_2 -> V_20 + V_22 ) ;
V_19 = V_16 | ( V_18 << 5 ) ;
if ( V_19 != V_11 -> V_19 ) {
V_11 -> V_19 = V_19 ;
F_6 ( V_11 -> V_19 , V_2 -> V_20 + V_23 ) ;
if ( V_8 -> V_24 > 0 ) {
F_7 ( V_18 >= F_8 ( V_25 ) ) ;
F_9 ( V_25 [ V_18 ] ) ;
}
}
for ( V_13 = 0 ; V_13 < V_8 -> V_24 ; V_13 ++ ) {
F_6 ( 0 , V_2 -> V_20 + V_26 ) ;
for ( V_14 = V_27 ; V_14 ; V_14 -- ) {
V_15 = F_5 ( V_2 -> V_20 + V_28 ) ;
if ( V_15 & V_29 ) {
F_10 ( V_30 L_1 ) ;
F_6 ( 0 , V_2 -> V_20 + V_22 ) ;
return - V_31 ;
}
if ( V_15 & V_32 )
break;
F_9 ( 1 ) ;
}
if ( V_14 == 0 ) {
F_10 ( V_30 L_2 ) ;
return - V_33 ;
}
V_9 [ V_13 ] = F_5 ( V_2 -> V_20 + V_34 ) ;
V_9 [ V_13 ] |= ( 0xf & F_5 ( V_2 -> V_20 + V_21 ) ) << 8 ;
if ( V_11 -> V_35 == V_36 )
V_9 [ V_13 ] ^= 0x800 ;
}
return V_13 ;
}
static int F_11 ( struct V_4 * V_2 ,
struct V_5 * V_6 ,
struct V_7 * V_8 , unsigned int * V_9 )
{
struct V_10 * V_11 = V_2 -> V_12 ;
int V_13 ;
int V_16 = F_3 ( V_8 -> V_17 ) ;
for ( V_13 = 0 ; V_13 < V_8 -> V_24 ; V_13 ++ )
V_9 [ V_13 ] = V_11 -> V_37 [ V_16 ] ;
return V_13 ;
}
static int F_12 ( struct V_4 * V_2 ,
struct V_5 * V_6 ,
struct V_7 * V_8 , unsigned int * V_9 )
{
struct V_10 * V_11 = V_2 -> V_12 ;
int V_16 = F_3 ( V_8 -> V_17 ) ;
int V_38 ;
int V_13 ;
for ( V_13 = 0 ; V_13 < V_8 -> V_24 ; V_13 ++ ) {
V_11 -> V_37 [ V_16 ] = V_38 = V_9 [ V_13 ] ;
if ( V_11 -> V_39 == V_40 )
V_38 ^= 0x800 ;
F_6 ( V_38 & 0xff ,
V_2 -> V_20 + ( V_16 ? V_41 : V_42 ) ) ;
F_6 ( V_38 >> 8 ,
V_2 -> V_20 + ( V_16 ? V_43 : V_44 ) ) ;
}
return V_13 ;
}
static int F_13 ( struct V_4 * V_2 ,
struct V_5 * V_6 ,
struct V_7 * V_8 , unsigned int * V_9 )
{
V_9 [ 1 ] = F_5 ( V_2 -> V_20 + V_45 ) ;
return V_8 -> V_24 ;
}
static int F_14 ( struct V_4 * V_2 ,
struct V_5 * V_6 ,
struct V_7 * V_8 , unsigned int * V_9 )
{
if ( V_9 [ 0 ] ) {
V_6 -> V_46 &= ~ V_9 [ 0 ] ;
V_6 -> V_46 |= V_9 [ 0 ] & V_9 [ 1 ] ;
F_6 ( V_6 -> V_46 ^ 0xff , V_2 -> V_20 + V_47 ) ;
}
V_9 [ 1 ] = V_6 -> V_46 ;
return V_8 -> V_24 ;
}
static int F_15 ( struct V_4 * V_2 , struct V_48 * V_49 )
{
const struct V_50 * V_51 = F_16 ( V_2 ) ;
struct V_10 * V_11 ;
unsigned int V_1 ;
unsigned long V_20 ;
int V_52 ;
struct V_5 * V_6 ;
V_20 = V_49 -> V_53 [ 0 ] ;
F_10 ( V_54 L_3 , V_2 -> V_55 , V_20 ) ;
if ( ! F_17 ( V_20 , V_56 , L_4 ) ) {
F_10 ( V_30 L_5 ) ;
return - V_31 ;
}
V_2 -> V_20 = V_20 ;
#ifdef F_18
F_10 ( V_57 L_6 ,
F_5 ( V_2 -> V_20 + 0 ) ,
F_5 ( V_2 -> V_20 + 1 ) ,
F_5 ( V_2 -> V_20 + 2 ) ,
F_5 ( V_2 -> V_20 + 3 ) , F_5 ( V_2 -> V_20 + 4 ) ) ;
#endif
F_6 ( 0 , V_2 -> V_20 + V_28 ) ;
F_5 ( V_2 -> V_20 + V_21 ) ;
F_6 ( 0 , V_2 -> V_20 + V_22 ) ;
V_1 = V_49 -> V_53 [ 1 ] ;
if ( V_1 ) {
F_10 ( V_54 L_7 , V_1 ) ;
V_52 = F_19 ( V_1 , F_1 , 0 , L_4 , V_2 ) ;
if ( V_52 < 0 ) {
F_10 ( V_30 L_8 ) ;
return V_52 ;
}
V_2 -> V_1 = V_1 ;
} else {
F_10 ( V_54 L_9 ) ;
}
V_2 -> V_58 = V_51 -> V_59 ;
V_52 = F_20 ( V_2 , 4 ) ;
if ( V_52 )
return V_52 ;
V_11 = F_21 ( sizeof( * V_11 ) , V_60 ) ;
if ( ! V_11 )
return - V_61 ;
V_2 -> V_12 = V_11 ;
V_11 -> V_62 = V_49 -> V_53 [ 2 ] ;
V_11 -> V_63 = V_49 -> V_53 [ 3 ] ;
V_11 -> V_35 = V_49 -> V_53 [ 4 ] ;
V_11 -> V_64 = V_49 -> V_53 [ 5 ] ;
V_11 -> V_39 = V_49 -> V_53 [ 6 ] ;
V_11 -> V_65 = V_49 -> V_53 [ 7 ] ;
V_11 -> V_66 = V_49 -> V_53 [ 8 ] ;
V_11 -> V_19 = - 1 ;
V_6 = & V_2 -> V_67 [ 0 ] ;
V_6 -> type = V_68 ;
V_6 -> V_69 = V_70 | V_71 ;
V_6 -> V_72 = ( V_11 -> V_62 ? 16 : 8 ) ;
V_6 -> V_73 = F_2 ;
V_6 -> V_74 = 0xfff ;
switch ( V_11 -> V_63 ) {
case V_75 :
V_6 -> V_76 = & V_77 ;
break;
case V_78 :
V_6 -> V_76 = & V_79 ;
break;
case V_80 :
V_6 -> V_76 = & V_81 ;
break;
}
V_6 = & V_2 -> V_67 [ 1 ] ;
if ( V_51 -> V_82 ) {
V_6 -> type = V_83 ;
V_6 -> V_69 = V_84 ;
V_6 -> V_72 = 2 ;
V_6 -> V_73 = F_11 ;
V_6 -> V_85 = F_12 ;
V_6 -> V_74 = 0xfff ;
V_6 -> V_86 = V_11 -> V_87 ;
switch ( V_11 -> V_64 ) {
case V_88 :
V_11 -> V_87 [ 0 ] = & V_89 ;
break;
case V_90 :
V_11 -> V_87 [ 0 ] = & V_91 ;
break;
}
switch ( V_11 -> V_65 ) {
case V_88 :
V_11 -> V_87 [ 1 ] = & V_89 ;
break;
case V_90 :
V_11 -> V_87 [ 1 ] = & V_91 ;
break;
}
} else {
V_6 -> type = V_92 ;
}
V_6 = & V_2 -> V_67 [ 2 ] ;
V_6 -> type = V_93 ;
V_6 -> V_69 = V_70 ;
V_6 -> V_72 = 8 ;
V_6 -> V_94 = F_13 ;
V_6 -> V_74 = 1 ;
V_6 -> V_76 = & V_95 ;
V_6 = & V_2 -> V_67 [ 3 ] ;
V_6 -> type = V_96 ;
V_6 -> V_69 = V_84 ;
V_6 -> V_72 = 8 ;
V_6 -> V_94 = F_14 ;
V_6 -> V_74 = 1 ;
V_6 -> V_76 = & V_95 ;
#if 0
s = &dev->subdevices[4];
s->type = COMEDI_SUBD_TIMER;
#endif
return 0 ;
}
static void F_22 ( struct V_4 * V_2 )
{
if ( V_2 -> V_20 )
F_23 ( V_2 -> V_20 , V_56 ) ;
if ( V_2 -> V_1 )
F_24 ( V_2 -> V_1 , V_2 ) ;
}
