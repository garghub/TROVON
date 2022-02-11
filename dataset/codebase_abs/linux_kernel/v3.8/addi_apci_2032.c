static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
unsigned int V_8 = V_7 [ 0 ] ;
unsigned int V_9 = V_7 [ 1 ] ;
V_4 -> V_10 = F_2 ( V_2 -> V_11 + V_12 ) ;
if ( V_8 ) {
V_4 -> V_10 &= ~ V_8 ;
V_4 -> V_10 |= ( V_9 & V_8 ) ;
F_3 ( V_4 -> V_10 , V_2 -> V_11 + V_12 ) ;
}
V_7 [ 1 ] = V_4 -> V_10 ;
return V_6 -> V_13 ;
}
static int F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
struct V_14 * V_15 = V_2 -> V_16 ;
unsigned int V_17 ;
switch ( V_7 [ 0 ] ) {
case V_18 :
V_15 -> V_19 = V_20 ;
V_17 = V_7 [ 1 ] & V_4 -> V_21 ;
F_5 ( V_17 , V_2 -> V_11 + V_22 ) ;
F_6 ( V_2 -> V_23 , L_1 ,
20 * V_17 + 20 ) ;
break;
case V_24 :
V_15 -> V_19 = 0 ;
break;
default:
return - V_25 ;
}
F_5 ( V_15 -> V_19 , V_2 -> V_11 + V_26 ) ;
return V_6 -> V_13 ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
struct V_14 * V_15 = V_2 -> V_16 ;
int V_27 ;
if ( V_15 -> V_19 == 0 ) {
F_8 ( V_2 -> V_23 , L_2 ) ;
return - V_25 ;
}
for ( V_27 = 0 ; V_27 < V_6 -> V_13 ; V_27 ++ ) {
F_5 ( V_15 -> V_19 | V_28 ,
V_2 -> V_11 + V_26 ) ;
}
return V_6 -> V_13 ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
int V_27 ;
for ( V_27 = 0 ; V_27 < V_6 -> V_13 ; V_27 ++ )
V_7 [ V_27 ] = F_2 ( V_2 -> V_11 + V_29 ) ;
return V_6 -> V_13 ;
}
static int F_10 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
V_7 [ 1 ] = V_4 -> V_10 ;
return V_6 -> V_13 ;
}
static int F_11 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_30 * V_31 )
{
int V_32 = 0 ;
V_32 |= F_12 ( & V_31 -> V_33 , V_34 ) ;
V_32 |= F_12 ( & V_31 -> V_35 , V_36 ) ;
V_32 |= F_12 ( & V_31 -> V_37 , V_38 ) ;
V_32 |= F_12 ( & V_31 -> V_39 , V_40 ) ;
V_32 |= F_12 ( & V_31 -> V_41 , V_42 ) ;
if ( V_32 )
return 1 ;
if ( V_32 )
return 2 ;
V_32 |= F_13 ( & V_31 -> V_43 , 0 ) ;
V_32 |= F_14 ( & V_31 -> V_44 , 3 ) ;
V_32 |= F_13 ( & V_31 -> V_45 , 0 ) ;
V_32 |= F_13 ( & V_31 -> V_46 , 1 ) ;
V_32 |= F_13 ( & V_31 -> V_47 , 0 ) ;
if ( V_32 )
return 3 ;
if ( V_32 )
return 4 ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_30 * V_31 = & V_4 -> V_48 -> V_31 ;
F_3 ( V_31 -> V_44 , V_2 -> V_11 + V_49 ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_3 ( 0x0 , V_2 -> V_11 + V_49 ) ;
return 0 ;
}
static T_1 F_17 ( int V_50 , void * V_51 )
{
struct V_1 * V_2 = V_51 ;
struct V_3 * V_4 = V_2 -> V_52 ;
unsigned int V_53 ;
V_53 = F_2 ( V_2 -> V_11 + V_54 ) & V_55 ;
if ( ! V_53 )
return V_56 ;
V_4 -> V_10 = F_2 ( V_2 -> V_11 + V_57 ) ;
F_3 ( 0x0 , V_2 -> V_11 + V_49 ) ;
F_18 ( V_4 -> V_48 , V_4 -> V_10 ) ;
V_4 -> V_48 -> V_58 |= V_59 | V_60 ;
F_19 ( V_2 , V_4 ) ;
return V_61 ;
}
static int F_20 ( struct V_1 * V_2 )
{
F_3 ( 0x0 , V_2 -> V_11 + V_12 ) ;
F_3 ( 0x0 , V_2 -> V_11 + V_49 ) ;
F_3 ( 0x0 , V_2 -> V_11 + V_26 ) ;
F_3 ( 0x0 , V_2 -> V_11 + V_22 ) ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 ,
unsigned long V_62 )
{
struct V_63 * V_64 = F_22 ( V_2 ) ;
struct V_14 * V_15 ;
struct V_3 * V_4 ;
int V_65 ;
V_2 -> V_66 = V_2 -> V_67 -> V_68 ;
V_15 = F_23 ( sizeof( * V_15 ) , V_69 ) ;
if ( ! V_15 )
return - V_70 ;
V_2 -> V_16 = V_15 ;
V_65 = F_24 ( V_64 , V_2 -> V_66 ) ;
if ( V_65 )
return V_65 ;
V_2 -> V_11 = F_25 ( V_64 , 1 ) ;
if ( V_64 -> V_50 > 0 ) {
V_65 = F_26 ( V_64 -> V_50 , F_17 ,
V_71 , V_2 -> V_66 , V_2 ) ;
if ( V_65 == 0 )
V_2 -> V_50 = V_64 -> V_50 ;
}
V_65 = F_27 ( V_2 , 3 ) ;
if ( V_65 )
return V_65 ;
V_4 = & V_2 -> V_72 [ 0 ] ;
V_4 -> type = V_73 ;
V_4 -> V_74 = V_75 ;
V_4 -> V_76 = 32 ;
V_4 -> V_21 = 1 ;
V_4 -> V_77 = & V_78 ;
V_4 -> V_79 = F_1 ;
V_4 = & V_2 -> V_72 [ 1 ] ;
V_4 -> type = V_80 ;
V_4 -> V_74 = V_75 ;
V_4 -> V_76 = 1 ;
V_4 -> V_21 = 0xff ;
V_4 -> V_81 = F_7 ;
V_4 -> V_82 = F_9 ;
V_4 -> V_83 = F_4 ;
V_4 = & V_2 -> V_72 [ 2 ] ;
if ( V_2 -> V_50 ) {
V_2 -> V_52 = V_4 ;
V_4 -> type = V_84 | V_85 ;
V_4 -> V_74 = V_86 ;
V_4 -> V_76 = 1 ;
V_4 -> V_21 = 1 ;
V_4 -> V_77 = & V_78 ;
V_4 -> V_79 = F_10 ;
V_4 -> V_87 = F_11 ;
V_4 -> V_88 = F_15 ;
V_4 -> V_89 = F_16 ;
} else {
V_4 -> type = V_90 ;
}
F_20 ( V_2 ) ;
return 0 ;
}
static void F_28 ( struct V_1 * V_2 )
{
struct V_63 * V_64 = F_22 ( V_2 ) ;
if ( V_2 -> V_11 )
F_20 ( V_2 ) ;
if ( V_2 -> V_50 )
F_29 ( V_2 -> V_50 , V_2 ) ;
if ( V_64 ) {
if ( V_2 -> V_11 )
F_30 ( V_64 ) ;
}
}
static int F_31 ( struct V_63 * V_2 ,
const struct V_91 * V_92 )
{
return F_32 ( V_2 , & V_93 ) ;
}
static void F_33 ( struct V_63 * V_2 )
{
F_34 ( V_2 ) ;
}
