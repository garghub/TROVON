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
unsigned short V_12 ;
V_12 = V_10 -> V_13 ( 0 , V_14 , 0 , V_4 ) ;
V_12 |= ( V_10 -> V_13 ( 0 , V_14 + 1 , 0 , V_4 ) << 8 ) ;
F_5 ( V_8 -> V_15 , V_12 ) ;
V_8 -> V_15 -> V_16 |= V_17 ;
F_6 ( V_6 , V_8 ) ;
}
static int F_7 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
struct V_18 * V_19 ,
unsigned int * V_3 )
{
struct V_9 * V_10 = V_8 -> V_11 ;
unsigned long V_4 = V_10 -> V_4 ;
unsigned int V_20 ;
unsigned int V_21 ;
V_20 = F_8 ( V_8 , V_3 ) ;
if ( V_20 ) {
if ( V_20 & 0xff )
V_10 -> V_13 ( 1 , V_14 , V_8 -> V_22 & 0xff , V_4 ) ;
if ( V_20 & 0xff00 )
V_10 -> V_13 ( 1 , V_14 + 1 , ( V_8 -> V_22 >> 8 ) & 0xff ,
V_4 ) ;
if ( V_20 & 0xff0000 )
V_10 -> V_13 ( 1 , V_14 + 2 , ( V_8 -> V_22 >> 16 ) & 0xff ,
V_4 ) ;
}
V_21 = V_10 -> V_13 ( 0 , V_14 , 0 , V_4 ) ;
V_21 |= ( V_10 -> V_13 ( 0 , V_14 + 1 , 0 , V_4 ) << 8 ) ;
V_21 |= ( V_10 -> V_13 ( 0 , V_14 + 2 , 0 , V_4 ) << 16 ) ;
V_3 [ 1 ] = V_21 ;
return V_19 -> V_23 ;
}
static void F_9 ( struct V_5 * V_6 ,
struct V_7 * V_8 )
{
struct V_9 * V_10 = V_8 -> V_11 ;
unsigned long V_4 = V_10 -> V_4 ;
int V_24 ;
V_24 = V_25 ;
if ( ! ( V_8 -> V_26 & 0x0000ff ) )
V_24 |= V_27 ;
if ( ! ( V_8 -> V_26 & 0x00ff00 ) )
V_24 |= V_28 ;
if ( ! ( V_8 -> V_26 & 0x0f0000 ) )
V_24 |= V_29 ;
if ( ! ( V_8 -> V_26 & 0xf00000 ) )
V_24 |= V_30 ;
V_10 -> V_13 ( 1 , V_31 , V_24 , V_4 ) ;
}
static int F_10 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
struct V_18 * V_19 ,
unsigned int * V_3 )
{
unsigned int V_32 = F_11 ( V_19 -> V_33 ) ;
unsigned int V_20 ;
int V_34 ;
if ( V_32 < 8 )
V_20 = 0x0000ff ;
else if ( V_32 < 16 )
V_20 = 0x00ff00 ;
else if ( V_32 < 20 )
V_20 = 0x0f0000 ;
else
V_20 = 0xf00000 ;
V_34 = F_12 ( V_6 , V_8 , V_19 , V_3 , V_20 ) ;
if ( V_34 )
return V_34 ;
F_9 ( V_6 , V_8 ) ;
return V_19 -> V_23 ;
}
static int F_13 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
struct V_35 * V_36 )
{
int V_37 = 0 ;
V_37 |= F_14 ( & V_36 -> V_38 , V_39 ) ;
V_37 |= F_14 ( & V_36 -> V_40 , V_41 ) ;
V_37 |= F_14 ( & V_36 -> V_42 , V_43 ) ;
V_37 |= F_14 ( & V_36 -> V_44 , V_45 ) ;
V_37 |= F_14 ( & V_36 -> V_46 , V_47 ) ;
if ( V_37 )
return 1 ;
if ( V_37 )
return 2 ;
V_37 |= F_15 ( & V_36 -> V_48 , 0 ) ;
V_37 |= F_15 ( & V_36 -> V_49 , 0 ) ;
V_37 |= F_15 ( & V_36 -> V_50 , 0 ) ;
V_37 |= F_15 ( & V_36 -> V_51 , 1 ) ;
V_37 |= F_15 ( & V_36 -> V_52 , 0 ) ;
if ( V_37 )
return 3 ;
if ( V_37 )
return 4 ;
return 0 ;
}
static int F_16 ( struct V_5 * V_6 ,
struct V_7 * V_8 )
{
return 0 ;
}
static int F_17 ( struct V_5 * V_6 ,
struct V_7 * V_8 )
{
return 0 ;
}
int F_18 ( struct V_5 * V_6 , struct V_7 * V_8 ,
int (* V_13) ( int , int , int , unsigned long ) ,
unsigned long V_4 )
{
struct V_9 * V_10 ;
V_10 = F_19 ( V_8 , sizeof( * V_10 ) ) ;
if ( ! V_10 )
return - V_53 ;
V_10 -> V_4 = V_4 ;
V_10 -> V_13 = V_13 ? V_13 : F_1 ;
V_8 -> type = V_54 ;
V_8 -> V_55 = V_56 | V_57 ;
V_8 -> V_58 = 24 ;
V_8 -> V_59 = & V_60 ;
V_8 -> V_61 = 1 ;
V_8 -> V_62 = F_7 ;
V_8 -> V_63 = F_10 ;
F_9 ( V_6 , V_8 ) ;
return 0 ;
}
int F_20 ( struct V_5 * V_6 , struct V_7 * V_8 ,
int (* V_13) ( int , int , int , unsigned long ) ,
unsigned long V_4 )
{
int V_34 ;
V_34 = F_18 ( V_6 , V_8 , V_13 , V_4 ) ;
if ( V_34 )
return V_34 ;
V_8 -> V_64 = F_13 ;
V_8 -> V_65 = F_16 ;
V_8 -> V_66 = F_17 ;
return 0 ;
}
static int F_21 ( struct V_5 * V_6 ,
struct V_67 * V_68 )
{
struct V_7 * V_8 ;
int V_34 ;
unsigned long V_4 ;
int V_69 ;
for ( V_69 = 0 ; V_69 < V_70 ; V_69 ++ ) {
V_4 = V_68 -> V_71 [ V_69 ] ;
if ( ! V_4 )
break;
}
if ( V_69 == 0 ) {
F_22 ( V_6 -> V_72 , L_1 ) ;
return - V_73 ;
}
V_34 = F_23 ( V_6 , V_69 ) ;
if ( V_34 )
return V_34 ;
for ( V_69 = 0 ; V_69 < V_6 -> V_74 ; V_69 ++ ) {
V_8 = & V_6 -> V_75 [ V_69 ] ;
V_4 = V_68 -> V_71 [ V_69 ] ;
V_34 = F_24 ( V_6 , V_4 , V_76 ) ;
if ( V_34 ) {
V_8 -> type = V_77 ;
} else {
V_34 = F_18 ( V_6 , V_8 , NULL , V_4 ) ;
if ( V_34 )
return V_34 ;
}
}
return 0 ;
}
static void F_25 ( struct V_5 * V_6 )
{
struct V_7 * V_8 ;
struct V_9 * V_10 ;
int V_69 ;
for ( V_69 = 0 ; V_69 < V_6 -> V_74 ; V_69 ++ ) {
V_8 = & V_6 -> V_75 [ V_69 ] ;
if ( V_8 -> type != V_77 ) {
V_10 = V_8 -> V_11 ;
F_26 ( V_10 -> V_4 , V_76 ) ;
}
}
}
