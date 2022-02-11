static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned long V_7 )
{
unsigned int V_8 ;
V_8 = F_2 ( V_2 -> V_9 + V_10 ) ;
if ( ( V_8 & V_11 ) == 0 )
return 0 ;
return - V_12 ;
}
static int F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_13 )
{
const struct V_14 * V_15 = V_2 -> V_16 ;
struct V_17 * V_18 = V_2 -> V_19 ;
int V_20 ;
int V_21 ;
int V_22 ;
int V_23 , V_24 ;
int V_25 ;
V_21 = F_4 ( V_6 -> V_26 ) ;
V_22 = F_5 ( V_6 -> V_26 ) ;
F_2 ( V_2 -> V_9 + V_27 ) ;
F_2 ( V_2 -> V_9 + V_28 ) ;
F_6 ( & V_2 -> V_29 ) ;
V_18 -> V_30 &= ~ V_31 ;
V_18 -> V_30 |= F_7 ( V_21 ) ;
F_8 ( V_18 -> V_30 , V_2 -> V_9 + V_32 ) ;
F_9 ( & V_2 -> V_29 ) ;
if ( V_18 -> V_33 ) {
V_22 = F_5 ( V_6 -> V_26 ) ;
F_8 ( V_18 -> V_33 [ V_22 ] ,
V_2 -> V_9 + V_34 ) ;
}
for ( V_20 = 0 ; V_20 < V_6 -> V_20 ; V_20 ++ ) {
if ( V_15 -> V_35 == 16 )
if ( F_2 ( V_2 -> V_9 + V_28 ) & 0x80 )
F_10 ( V_2 -> V_36 , L_1 ) ;
F_11 ( 0 , V_2 -> V_9 + V_37 ) ;
V_25 = F_12 ( V_2 , V_4 , V_6 , F_1 , 0 ) ;
if ( V_25 )
return V_25 ;
V_24 = F_2 ( V_2 -> V_9 + V_28 ) ;
V_23 = F_2 ( V_2 -> V_9 + V_27 ) ;
if ( V_15 -> V_38 == V_39 ) {
V_13 [ V_20 ] = ( V_23 >> 4 ) | ( V_24 << 4 ) ;
} else if ( V_15 -> V_38 == V_40 ) {
V_13 [ V_20 ] = ( V_24 << 8 ) + V_23 ;
} else if ( V_15 -> V_38 == V_41 ) {
unsigned int V_42 = V_23 | ( ( V_24 & 0x7f ) << 8 ) ;
if ( V_24 & 0x80 )
V_13 [ V_20 ] = ( 1 << 15 ) + V_42 ;
else
V_13 [ V_20 ] = ( 1 << 15 ) - V_42 ;
} else {
F_13 ( V_2 -> V_36 , L_2 ) ;
return - 1 ;
}
}
return V_20 ;
}
static int F_14 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_13 )
{
V_13 [ 0 ] = 0 ;
V_13 [ 1 ] = F_15 ( F_2 ( V_2 -> V_9 + V_10 ) ) ;
return V_6 -> V_20 ;
}
static int F_16 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_13 )
{
struct V_17 * V_18 = V_2 -> V_19 ;
if ( F_17 ( V_4 , V_13 ) ) {
F_6 ( & V_2 -> V_29 ) ;
V_18 -> V_30 &= ~ V_43 ;
V_18 -> V_30 |= F_18 ( V_4 -> V_44 ) ;
F_8 ( V_18 -> V_30 , V_2 -> V_9 + V_32 ) ;
F_9 ( & V_2 -> V_29 ) ;
}
V_13 [ 1 ] = V_4 -> V_44 ;
return V_6 -> V_20 ;
}
static int F_19 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_13 )
{
V_13 [ 0 ] = 0 ;
V_13 [ 1 ] = F_2 ( V_2 -> V_9 + V_45 ) ;
return V_6 -> V_20 ;
}
static int F_20 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_13 )
{
if ( F_17 ( V_4 , V_13 ) )
F_8 ( V_4 -> V_44 , V_2 -> V_9 + V_46 ) ;
V_13 [ 1 ] = V_4 -> V_44 ;
return V_6 -> V_20 ;
}
static void F_21 ( struct V_1 * V_2 ,
unsigned int V_21 , unsigned int V_13 )
{
const struct V_14 * V_15 = V_2 -> V_16 ;
unsigned char V_23 ;
unsigned char V_24 ;
V_23 = V_13 & 0xff ;
V_24 = ( V_13 >> 8 ) & 0xff ;
if ( V_15 -> V_47 ) {
F_8 ( V_23 , V_2 -> V_9 + F_22 ( V_21 ) ) ;
F_8 ( V_24 , V_2 -> V_9 + F_23 ( V_21 ) ) ;
F_2 ( V_2 -> V_9 + V_48 ) ;
} else {
F_8 ( V_23 , V_2 -> V_9 + F_24 ( V_21 ) ) ;
F_8 ( V_24 , V_2 -> V_9 + F_25 ( V_21 ) ) ;
F_2 ( V_2 -> V_9 + V_49 ) ;
}
}
static int F_26 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_13 )
{
unsigned int V_21 = F_4 ( V_6 -> V_26 ) ;
unsigned int V_50 = V_4 -> V_51 [ V_21 ] ;
int V_52 ;
for ( V_52 = 0 ; V_52 < V_6 -> V_20 ; V_52 ++ ) {
V_50 = V_13 [ V_52 ] ;
F_21 ( V_2 , V_21 , V_50 ) ;
}
V_4 -> V_51 [ V_21 ] = V_50 ;
return V_6 -> V_20 ;
}
int F_27 ( struct V_1 * V_2 , unsigned long V_9 )
{
const struct V_14 * V_15 = V_2 -> V_16 ;
struct V_17 * V_18 = V_2 -> V_19 ;
struct V_3 * V_4 ;
int V_25 ;
int V_52 ;
V_2 -> V_9 = V_9 ;
V_2 -> V_53 = V_15 -> V_54 ;
V_25 = F_28 ( V_2 , 6 ) ;
if ( V_25 )
return V_25 ;
V_4 = & V_2 -> V_55 [ 0 ] ;
if ( V_15 -> V_35 ) {
V_4 -> type = V_56 ;
V_4 -> V_57 = V_58 | V_59 ;
V_4 -> V_60 = 8 ;
V_4 -> V_61 = ( 1 << V_15 -> V_35 ) - 1 ;
V_4 -> V_62 = V_63 [ V_15 -> V_64 ] ;
V_4 -> V_65 = F_3 ;
V_18 -> V_33 = V_66 [ V_15 -> V_64 ] ;
} else {
V_4 -> type = V_67 ;
}
V_4 = & V_2 -> V_55 [ 1 ] ;
if ( V_15 -> V_68 ) {
V_4 -> type = V_69 ;
V_4 -> V_57 = V_70 ;
V_4 -> V_60 = 2 ;
V_4 -> V_61 = ( 1 << V_15 -> V_68 ) - 1 ;
V_4 -> V_62 = & V_71 ;
V_4 -> V_72 = F_26 ;
V_25 = F_29 ( V_4 ) ;
if ( V_25 )
return V_25 ;
for ( V_52 = 0 ; V_52 < V_4 -> V_60 ; V_52 ++ ) {
V_4 -> V_51 [ V_52 ] = V_4 -> V_61 / 2 ;
F_21 ( V_2 , V_52 , V_4 -> V_51 [ V_52 ] ) ;
}
} else {
V_4 -> type = V_67 ;
}
V_4 = & V_2 -> V_55 [ 2 ] ;
if ( V_15 -> V_73 ) {
V_4 -> type = V_74 ;
V_4 -> V_57 = V_58 ;
V_4 -> V_60 = V_15 -> V_73 ;
V_4 -> V_61 = 1 ;
V_4 -> V_62 = & V_75 ;
V_4 -> V_76 = V_15 -> V_47 ? F_19 :
F_14 ;
} else {
V_4 -> type = V_67 ;
}
V_4 = & V_2 -> V_55 [ 3 ] ;
if ( V_15 -> V_77 ) {
V_4 -> type = V_78 ;
V_4 -> V_57 = V_70 ;
V_4 -> V_60 = V_15 -> V_77 ;
V_4 -> V_61 = 1 ;
V_4 -> V_62 = & V_75 ;
V_4 -> V_76 = V_15 -> V_47 ? F_20 :
F_16 ;
} else {
V_4 -> type = V_67 ;
}
V_4 = & V_2 -> V_55 [ 4 ] ;
if ( V_15 -> V_79 != 0 ) {
V_25 = F_30 ( V_2 , V_4 , NULL , V_15 -> V_79 ) ;
if ( V_25 )
return V_25 ;
} else {
V_4 -> type = V_67 ;
}
V_4 = & V_2 -> V_55 [ 5 ] ;
if ( V_15 -> V_80 ) {
V_2 -> V_81 = F_31 ( V_2 -> V_9 + V_15 -> V_80 ,
0 , V_82 , 0 ) ;
if ( ! V_2 -> V_81 )
return - V_83 ;
F_32 ( V_4 , V_2 -> V_81 ) ;
} else {
V_4 -> type = V_67 ;
}
return 0 ;
}
static int T_1 F_33 ( void )
{
return 0 ;
}
static void T_2 F_34 ( void )
{
}
