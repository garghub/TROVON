static int T_1 F_1 ( void )
{
return F_2 ( & V_1 ) ;
}
static void T_2 F_3 ( void )
{
F_4 ( & V_1 ) ;
}
static int F_5 ( struct V_2 * V_3 ,
struct V_4 * V_5 ,
struct V_6 * V_7 , unsigned int * V_8 )
{
int V_9 , V_10 ;
int V_11 ;
unsigned int V_12 , V_13 ;
V_11 = F_6 ( V_7 -> V_14 ) ;
F_7 ( V_15 | V_16 | ( V_11 << 3 ) ,
V_3 -> V_17 + V_18 ) ;
for ( V_9 = 0 ; V_9 < V_19 ; V_9 ++ ) {
if ( F_8 ( V_3 -> V_17 + V_20 ) & V_21 )
break;
}
if ( V_9 == V_19 )
return - V_22 ;
for ( V_10 = 0 ; V_10 < V_7 -> V_10 ; V_10 ++ ) {
F_7 ( 0 , V_3 -> V_17 + V_23 ) ;
for ( V_9 = 0 ; V_9 < V_19 ; V_9 ++ ) {
if ( F_8 ( V_3 -> V_17 +
V_20 ) & V_24 )
break;
}
if ( V_9 == V_19 )
return - V_22 ;
V_12 = F_9 ( V_3 -> V_17 + V_23 ) ;
V_13 = F_9 ( V_3 -> V_17 + V_23 ) ;
V_8 [ V_10 ] = ( ( ( V_12 << 8 ) | V_13 ) + 0x1000 ) & 0x1fff ;
}
return V_10 ;
}
static int F_10 ( struct V_2 * V_3 ,
struct V_4 * V_5 ,
struct V_6 * V_7 , unsigned int * V_8 )
{
int V_9 ;
int V_11 = F_6 ( V_7 -> V_14 ) ;
for ( V_9 = 0 ; V_9 < V_7 -> V_10 ; V_9 ++ )
V_8 [ V_9 ] = V_25 -> V_26 [ V_11 ] ;
return V_9 ;
}
static int F_11 ( struct V_2 * V_3 ,
struct V_4 * V_5 ,
struct V_6 * V_7 , unsigned int * V_8 )
{
int V_9 ;
int V_11 = F_6 ( V_7 -> V_14 ) ;
for ( V_9 = 0 ; V_9 < V_7 -> V_10 ; V_9 ++ ) {
F_7 ( V_15 | V_27 | V_11 ,
V_3 -> V_17 + V_18 ) ;
F_7 ( V_8 [ V_9 ] , V_3 -> V_17 + V_28 ) ;
F_7 ( V_15 , V_3 -> V_17 + V_18 ) ;
V_25 -> V_26 [ V_11 ] = V_8 [ V_9 ] ;
}
return V_9 ;
}
static int F_12 ( struct V_2 * V_3 ,
struct V_4 * V_5 ,
struct V_6 * V_7 , unsigned int * V_8 )
{
if ( V_7 -> V_10 != 2 )
return - V_29 ;
V_8 [ 1 ] = F_8 ( V_3 -> V_17 + V_30 ) ;
return 2 ;
}
static int F_13 ( struct V_2 * V_3 ,
struct V_4 * V_5 ,
struct V_6 * V_7 , unsigned int * V_8 )
{
if ( V_7 -> V_10 != 2 )
return - V_29 ;
V_5 -> V_31 &= ~ V_8 [ 0 ] ;
V_5 -> V_31 |= ( V_8 [ 0 ] & V_8 [ 1 ] ) ;
F_7 ( V_5 -> V_31 , V_3 -> V_17 + V_32 ) ;
V_8 [ 1 ] = V_5 -> V_31 ;
return 2 ;
}
static int F_14 ( struct V_2 * V_3 ,
struct V_4 * V_5 ,
struct V_6 * V_7 ,
unsigned int * V_8 )
{
int V_10 ;
int V_11 = F_6 ( V_7 -> V_14 ) ;
int V_33 = V_15 | V_16 | ( V_11 << 3 ) ;
for ( V_10 = 0 ; V_10 < V_7 -> V_10 ; V_10 ++ ) {
int V_34 ;
F_7 ( V_33 , V_3 -> V_17 + V_18 ) ;
F_15 ( V_35 , V_3 -> V_17 + V_36 ) ;
F_15 ( V_37 , V_3 -> V_17 + V_36 ) ;
V_34 = F_9 ( V_3 -> V_17 + V_38 ) ;
V_34 |= ( F_9 ( V_3 -> V_17 + V_38 ) << 8 ) ;
V_34 |= ( F_9 ( V_3 -> V_17 + V_38 ) << 16 ) ;
V_8 [ V_10 ] = ( V_34 + 0x800000 ) & 0xffffff ;
}
return V_10 ;
}
static void F_16 ( struct V_2 * V_3 )
{
int V_11 ;
for ( V_11 = 0 ; V_11 < V_3 -> V_39 [ 4 ] . V_40 ; V_11 ++ ) {
int V_33 =
V_15 | V_16 | ( V_11 << 3 ) ;
F_7 ( V_33 , V_3 -> V_17 + V_18 ) ;
F_15 ( V_41 , V_3 -> V_17 + V_36 ) ;
F_15 ( V_35 , V_3 -> V_17 + V_36 ) ;
F_15 ( V_42 , V_3 -> V_17 + V_38 ) ;
F_15 ( V_43 , V_3 -> V_17 + V_36 ) ;
F_15 ( V_44 , V_3 -> V_17 + V_36 ) ;
F_15 ( V_45 , V_3 -> V_17 + V_36 ) ;
F_15 ( V_46 , V_3 -> V_17 + V_36 ) ;
}
}
static int F_17 ( struct V_2 * V_3 ,
struct V_47 * V_48 )
{
int V_49 = 0 ;
unsigned long V_17 ;
unsigned int V_50 ;
struct V_4 * V_5 ;
V_17 = V_48 -> V_51 [ 0 ] ;
F_18 ( V_52 L_1 , V_3 -> V_53 , V_17 ) ;
if ( ! F_19 ( V_17 , V_54 , L_2 ) ) {
F_18 ( V_55 L_3 , V_3 -> V_53 ) ;
return - V_56 ;
}
V_3 -> V_17 = V_17 ;
V_50 = V_48 -> V_51 [ 1 ] ;
if ( V_50 )
F_18 ( V_57 L_4 ,
V_3 -> V_53 , V_50 ) ;
else
F_18 ( V_57 L_5 , V_3 -> V_53 ) ;
V_3 -> V_58 = L_2 ;
V_49 = F_20 ( V_3 , 5 ) ;
if ( V_49 < 0 )
return V_49 ;
V_49 = F_21 ( V_3 , sizeof( struct V_59 ) ) ;
if ( V_49 < 0 )
return V_49 ;
V_5 = V_3 -> V_39 + 0 ;
V_5 -> type = V_60 ;
V_5 -> V_61 = V_62 | V_63 ;
V_5 -> V_40 = 8 ;
V_5 -> V_64 = F_5 ;
V_5 -> V_65 = 0x1fff ;
V_5 -> V_66 = & V_67 ;
V_5 = V_3 -> V_39 + 1 ;
V_5 -> type = V_68 ;
V_5 -> V_61 = V_69 ;
V_5 -> V_40 = 8 ;
V_5 -> V_64 = F_10 ;
V_5 -> V_70 = F_11 ;
V_5 -> V_65 = 0xfff ;
V_5 -> V_66 = & V_67 ;
V_5 = V_3 -> V_39 + 2 ;
V_5 -> type = V_71 ;
V_5 -> V_61 = V_62 ;
V_5 -> V_40 = 16 ;
V_5 -> V_72 = F_12 ;
V_5 -> V_65 = 1 ;
V_5 -> V_66 = & V_73 ;
V_5 = V_3 -> V_39 + 3 ;
V_5 -> type = V_74 ;
V_5 -> V_61 = V_69 ;
V_5 -> V_40 = 16 ;
V_5 -> V_72 = F_13 ;
V_5 -> V_65 = 1 ;
V_5 -> V_66 = & V_73 ;
V_5 -> V_31 = 0 ;
V_5 = V_3 -> V_39 + 4 ;
V_5 -> type = V_75 ;
V_5 -> V_61 = V_62 | V_76 ;
V_5 -> V_40 = V_48 -> V_51 [ 2 ] * 2 ;
V_5 -> V_64 = F_14 ;
V_5 -> V_65 = 0xffffff ;
V_5 -> V_66 = & V_77 ;
F_16 ( V_3 ) ;
return 0 ;
}
static int F_22 ( struct V_2 * V_3 )
{
F_18 ( V_52 L_6 , V_3 -> V_53 ) ;
if ( V_3 -> V_17 )
F_23 ( V_3 -> V_17 , V_54 ) ;
if ( V_3 -> V_50 )
F_24 ( V_3 -> V_50 , V_3 ) ;
return 0 ;
}
