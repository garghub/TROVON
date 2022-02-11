static int F_1 ( int V_1 , int V_2 , int V_3 , unsigned long V_4 )
{
if ( V_1 ) {
F_2 ( V_3 , V_4 + V_2 ) ;
return 0 ;
} else {
return F_3 ( V_4 + V_2 ) ;
}
}
void F_4 ( struct V_5 * V_6 ,
struct V_7 * V_8 )
{
struct V_9 * V_10 = V_8 -> V_11 ;
unsigned long V_4 = V_10 -> V_4 ;
short V_12 ;
V_12 = V_10 -> V_13 ( 0 , V_14 , 0 , V_4 ) ;
V_12 |= ( V_10 -> V_13 ( 0 , V_14 + 1 , 0 , V_4 ) << 8 ) ;
F_5 ( V_8 -> V_15 , V_12 ) ;
V_8 -> V_15 -> V_16 |= V_17 ;
F_6 ( V_6 , V_8 ) ;
}
static int F_7 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
struct V_18 * V_19 , unsigned int * V_3 )
{
struct V_9 * V_10 = V_8 -> V_11 ;
unsigned long V_4 = V_10 -> V_4 ;
unsigned int V_20 ;
unsigned int V_21 ;
unsigned int V_22 ;
V_20 = V_3 [ 0 ] ;
V_21 = V_3 [ 1 ] ;
if ( V_20 ) {
V_22 = V_8 -> V_23 ;
V_22 &= ~ V_20 ;
V_22 |= ( V_21 & V_20 ) ;
if ( V_20 & 0xff )
V_10 -> V_13 ( 1 , V_14 , V_22 & 0xff , V_4 ) ;
if ( V_20 & 0xff00 )
V_10 -> V_13 ( 1 , V_14 + 1 , ( V_22 >> 8 ) & 0xff , V_4 ) ;
if ( V_20 & 0xff0000 )
V_10 -> V_13 ( 1 , V_14 + 2 , ( V_22 >> 16 ) & 0xff , V_4 ) ;
V_8 -> V_23 = V_22 ;
}
V_22 = V_10 -> V_13 ( 0 , V_14 , 0 , V_4 ) ;
V_22 |= ( V_10 -> V_13 ( 0 , V_14 + 1 , 0 , V_4 ) << 8 ) ;
V_22 |= ( V_10 -> V_13 ( 0 , V_14 + 2 , 0 , V_4 ) << 16 ) ;
V_3 [ 1 ] = V_22 ;
return V_19 -> V_24 ;
}
static void F_8 ( struct V_5 * V_6 ,
struct V_7 * V_8 )
{
struct V_9 * V_10 = V_8 -> V_11 ;
unsigned long V_4 = V_10 -> V_4 ;
int V_25 ;
V_25 = V_26 ;
if ( ! ( V_8 -> V_27 & 0x0000ff ) )
V_25 |= V_28 ;
if ( ! ( V_8 -> V_27 & 0x00ff00 ) )
V_25 |= V_29 ;
if ( ! ( V_8 -> V_27 & 0x0f0000 ) )
V_25 |= V_30 ;
if ( ! ( V_8 -> V_27 & 0xf00000 ) )
V_25 |= V_31 ;
V_10 -> V_13 ( 1 , V_32 , V_25 , V_4 ) ;
}
static int F_9 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
struct V_18 * V_19 ,
unsigned int * V_3 )
{
unsigned int V_33 = F_10 ( V_19 -> V_34 ) ;
unsigned int V_20 ;
int V_35 ;
if ( V_33 < 8 )
V_20 = 0x0000ff ;
else if ( V_33 < 16 )
V_20 = 0x00ff00 ;
else if ( V_33 < 20 )
V_20 = 0x0f0000 ;
else
V_20 = 0xf00000 ;
V_35 = F_11 ( V_6 , V_8 , V_19 , V_3 , V_20 ) ;
if ( V_35 )
return V_35 ;
F_8 ( V_6 , V_8 ) ;
return V_19 -> V_24 ;
}
static int F_12 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
struct V_36 * V_37 )
{
int V_38 = 0 ;
V_38 |= F_13 ( & V_37 -> V_39 , V_40 ) ;
V_38 |= F_13 ( & V_37 -> V_41 , V_42 ) ;
V_38 |= F_13 ( & V_37 -> V_43 , V_44 ) ;
V_38 |= F_13 ( & V_37 -> V_45 , V_46 ) ;
V_38 |= F_13 ( & V_37 -> V_47 , V_48 ) ;
if ( V_38 )
return 1 ;
if ( V_38 )
return 2 ;
V_38 |= F_14 ( & V_37 -> V_49 , 0 ) ;
V_38 |= F_14 ( & V_37 -> V_50 , 0 ) ;
V_38 |= F_14 ( & V_37 -> V_51 , 0 ) ;
V_38 |= F_14 ( & V_37 -> V_52 , 1 ) ;
V_38 |= F_14 ( & V_37 -> V_53 , 0 ) ;
if ( V_38 )
return 3 ;
if ( V_38 )
return 4 ;
return 0 ;
}
static int F_15 ( struct V_5 * V_6 ,
struct V_7 * V_8 )
{
return 0 ;
}
static int F_16 ( struct V_5 * V_6 ,
struct V_7 * V_8 )
{
return 0 ;
}
int F_17 ( struct V_5 * V_6 , struct V_7 * V_8 ,
int (* V_13) ( int , int , int , unsigned long ) ,
unsigned long V_4 )
{
struct V_9 * V_10 ;
V_10 = F_18 ( V_8 , sizeof( * V_10 ) ) ;
if ( ! V_10 )
return - V_54 ;
V_10 -> V_4 = V_4 ;
V_10 -> V_13 = V_13 ? V_13 : F_1 ;
V_8 -> type = V_55 ;
V_8 -> V_56 = V_57 | V_58 ;
V_8 -> V_59 = 24 ;
V_8 -> V_60 = & V_61 ;
V_8 -> V_62 = 1 ;
V_8 -> V_63 = F_7 ;
V_8 -> V_64 = F_9 ;
V_8 -> V_23 = 0 ;
V_8 -> V_27 = 0 ;
F_8 ( V_6 , V_8 ) ;
return 0 ;
}
int F_19 ( struct V_5 * V_6 , struct V_7 * V_8 ,
int (* V_13) ( int , int , int , unsigned long ) ,
unsigned long V_4 )
{
int V_35 ;
V_35 = F_17 ( V_6 , V_8 , V_13 , V_4 ) ;
if ( V_35 )
return V_35 ;
V_8 -> V_65 = F_12 ;
V_8 -> V_66 = F_15 ;
V_8 -> V_67 = F_16 ;
return 0 ;
}
static int F_20 ( struct V_5 * V_6 ,
struct V_68 * V_69 )
{
struct V_7 * V_8 ;
int V_35 ;
unsigned long V_4 ;
int V_70 ;
for ( V_70 = 0 ; V_70 < V_71 ; V_70 ++ ) {
V_4 = V_69 -> V_72 [ V_70 ] ;
if ( ! V_4 )
break;
}
if ( V_70 == 0 ) {
F_21 ( V_6 -> V_73 , L_1 ) ;
return - V_74 ;
}
V_35 = F_22 ( V_6 , V_70 ) ;
if ( V_35 )
return V_35 ;
for ( V_70 = 0 ; V_70 < V_6 -> V_75 ; V_70 ++ ) {
V_8 = & V_6 -> V_76 [ V_70 ] ;
V_4 = V_69 -> V_72 [ V_70 ] ;
V_35 = F_23 ( V_6 , V_4 , V_77 ) ;
if ( V_35 ) {
V_8 -> type = V_78 ;
} else {
V_35 = F_17 ( V_6 , V_8 , NULL , V_4 ) ;
if ( V_35 )
return V_35 ;
}
}
return 0 ;
}
static void F_24 ( struct V_5 * V_6 )
{
struct V_7 * V_8 ;
struct V_9 * V_10 ;
int V_70 ;
for ( V_70 = 0 ; V_70 < V_6 -> V_75 ; V_70 ++ ) {
V_8 = & V_6 -> V_76 [ V_70 ] ;
if ( V_8 -> type != V_78 ) {
V_10 = V_8 -> V_11 ;
F_25 ( V_10 -> V_4 , V_77 ) ;
}
}
}
