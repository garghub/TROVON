static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_8 ;
V_8 = F_2 ( V_6 -> V_9 , V_4 ) ;
if ( V_8 < 0 )
return V_8 ;
return 0 ;
}
static int F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_8 ;
V_8 = F_2 ( V_6 -> V_10 , V_4 ) ;
if ( V_8 < 0 )
return V_8 ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_8 ;
V_8 = F_2 ( V_6 -> V_11 [ 0 ] , V_4 ) ;
if ( V_8 < 0 )
return V_8 ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_8 ;
V_8 = F_2 ( V_6 -> V_11 [ 1 ] , V_4 ) ;
if ( V_8 < 0 )
return V_8 ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_8 ;
V_8 = F_2 ( V_6 -> V_12 , V_4 ) ;
if ( V_8 < 0 )
return V_8 ;
return 0 ;
}
static void F_7 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
static const int V_13 = 0x400 ;
static const unsigned V_14 = 10 ;
static const int V_15 = 0x4 ;
static const int V_16 = 0x4 ;
unsigned V_17 ;
unsigned V_18 ;
unsigned V_19 ;
int V_20 ;
V_17 = F_8 ( V_6 -> V_21 -> V_22 + V_23 ) ;
V_18 = F_8 ( V_6 -> V_21 -> V_22 + V_24 ) ;
V_19 = F_8 ( V_6 -> V_21 -> V_22 + V_25 ) ;
F_9 ( 0x0 , V_6 -> V_21 -> V_22 + V_23 ) ;
F_9 ( ( ( 0x80 | V_14 ) | V_6 -> V_21 -> V_26 ) ,
V_6 -> V_21 -> V_22 + V_24 ) ;
F_9 ( 0x1 | V_19 ,
V_6 -> V_21 -> V_22 + V_25 ) ;
F_9 ( 0xf , V_6 -> V_21 -> V_22 + 0x30 ) ;
F_10 ( V_16 > sizeof( V_6 -> V_27 ) ) ;
for ( V_20 = 0 ; V_20 < V_16 ; ++ V_20 ) {
char * V_28 = ( char * ) & V_6 -> V_27 + V_20 ;
* V_28 = F_11 ( V_2 , V_15 + V_20 ) ;
}
V_6 -> V_27 = F_12 ( V_6 -> V_27 ) ;
for ( V_20 = 0 ; V_20 < V_29 ; ++ V_20 )
V_6 -> V_30 [ V_20 ] = F_11 ( V_2 , V_13 + V_20 ) ;
F_9 ( V_18 , V_6 -> V_21 -> V_22 + V_24 ) ;
F_9 ( V_17 , V_6 -> V_21 -> V_22 + V_23 ) ;
F_9 ( V_19 , V_6 -> V_21 -> V_22 + V_25 ) ;
F_9 ( 0x0 , V_6 -> V_21 -> V_22 + 0x30 ) ;
}
static void F_13 ( struct V_1 * V_2 )
{
const struct V_31 * V_32 = V_2 -> V_33 ;
struct V_5 * V_6 = V_2 -> V_7 ;
F_14 ( V_2 , 0 , V_34 ) ;
F_15 ( V_2 , 0x00 , V_35 ) ;
F_15 ( V_2 , 0x80 , V_36 ) ;
F_15 ( V_2 , 0x00 , V_37 ) ;
F_16 ( V_2 , V_32 -> V_38 / 2 , V_39 ) ;
V_6 -> V_40 = 0 ;
F_17 ( V_2 , V_6 -> V_41 |
V_42 ,
V_43 ) ;
F_17 ( V_2 , V_6 -> V_41 , V_43 ) ;
}
static void F_18 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
F_19 ( V_2 ) ;
if ( V_2 -> V_44 )
F_20 ( V_2 -> V_44 , V_2 ) ;
if ( V_6 ) {
F_21 ( V_6 -> V_9 ) ;
F_21 ( V_6 -> V_10 ) ;
F_21 ( V_6 -> V_12 ) ;
F_21 ( V_6 -> V_11 [ 0 ] ) ;
F_21 ( V_6 -> V_11 [ 1 ] ) ;
F_22 ( V_6 -> V_21 ) ;
}
if ( V_2 -> V_45 )
F_23 ( V_2 -> V_45 ) ;
F_24 ( V_2 ) ;
}
static int F_25 ( struct V_1 * V_2 ,
unsigned long V_46 )
{
struct V_47 * V_48 = F_26 ( V_2 ) ;
const struct V_31 * V_32 = NULL ;
struct V_5 * V_6 ;
unsigned int V_44 ;
int V_8 ;
if ( V_46 < F_27 ( V_49 ) )
V_32 = & V_49 [ V_46 ] ;
if ( ! V_32 )
return - V_50 ;
V_2 -> V_33 = V_32 ;
V_2 -> V_51 = V_32 -> V_52 ;
V_8 = F_28 ( V_2 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_29 ( V_2 ) ;
if ( V_8 )
return V_8 ;
V_6 = V_2 -> V_7 ;
V_6 -> V_21 = F_30 ( V_48 ) ;
if ( ! V_6 -> V_21 )
return - V_53 ;
if ( V_32 -> V_54 & V_55 )
V_6 -> V_56 = 1 ;
if ( V_32 -> V_54 & V_57 )
V_6 -> V_58 = 1 ;
if ( V_32 -> V_54 == V_59 )
V_6 -> V_60 = 1 ;
if ( V_32 -> V_54 == V_61 )
V_6 -> V_62 = 1 ;
if ( V_32 -> V_54 == V_63 )
V_6 -> V_64 = 1 ;
if ( V_32 -> V_54 == V_65 )
V_6 -> V_66 = 1 ;
if ( V_32 -> V_54 == V_67 )
V_6 -> V_68 = 1 ;
if ( V_32 -> V_54 & V_69 )
V_6 -> V_70 = 1 ;
if ( V_32 -> V_54 == V_71 )
V_6 -> V_72 = 1 ;
if ( V_32 -> V_54 == V_73 )
V_6 -> V_74 = 1 ;
V_8 = F_31 ( V_2 , V_6 -> V_21 ) ;
if ( V_8 < 0 )
return V_8 ;
V_6 -> V_9 = F_32 ( V_6 -> V_21 ) ;
if ( V_6 -> V_9 == NULL )
return - V_53 ;
V_6 -> V_10 = F_32 ( V_6 -> V_21 ) ;
if ( V_6 -> V_10 == NULL )
return - V_53 ;
V_6 -> V_12 = F_32 ( V_6 -> V_21 ) ;
if ( V_6 -> V_12 == NULL )
return - V_53 ;
V_6 -> V_11 [ 0 ] = F_32 ( V_6 -> V_21 ) ;
if ( V_6 -> V_11 [ 0 ] == NULL )
return - V_53 ;
V_6 -> V_11 [ 1 ] = F_32 ( V_6 -> V_21 ) ;
if ( V_6 -> V_11 [ 1 ] == NULL )
return - V_53 ;
if ( V_6 -> V_56 )
F_7 ( V_2 ) ;
if ( V_6 -> V_62 )
F_13 ( V_2 ) ;
V_44 = V_48 -> V_44 ;
if ( V_44 ) {
V_8 = F_33 ( V_44 , V_75 , V_76 ,
V_2 -> V_51 , V_2 ) ;
if ( V_8 == 0 )
V_2 -> V_44 = V_44 ;
}
V_8 = F_34 ( V_2 , 0 , 1 ) ;
if ( V_8 < 0 )
return V_8 ;
V_2 -> V_77 [ V_78 ] . V_79 = & F_1 ;
V_2 -> V_77 [ V_80 ] . V_79 = & F_3 ;
V_2 -> V_77 [ F_35 ( 0 ) ] . V_79 = & F_4 ;
V_2 -> V_77 [ F_35 ( 1 ) ] . V_79 = & F_5 ;
V_2 -> V_77 [ V_81 ] . V_79 = & F_6 ;
return 0 ;
}
static int F_36 ( struct V_47 * V_2 ,
const struct V_82 * V_83 )
{
return F_37 ( V_2 , & V_84 , V_83 -> V_85 ) ;
}
