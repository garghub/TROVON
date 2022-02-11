static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
V_4 -> V_8 = F_2 ( V_2 -> V_9 + V_10 ) ;
if ( F_3 ( V_4 , V_7 ) )
F_4 ( V_4 -> V_8 , V_2 -> V_9 + V_10 ) ;
V_7 [ 1 ] = V_4 -> V_8 ;
return V_6 -> V_11 ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
V_7 [ 1 ] = F_2 ( V_2 -> V_9 + V_12 ) & 3 ;
return V_6 -> V_11 ;
}
static void F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_13 * V_14 = V_4 -> V_15 ;
V_14 -> V_16 = false ;
V_14 -> V_17 = 0 ;
F_4 ( 0x0 , V_2 -> V_9 + V_18 ) ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_19 * V_20 )
{
int V_21 = 0 ;
V_21 |= F_8 ( & V_20 -> V_22 , V_23 ) ;
V_21 |= F_8 ( & V_20 -> V_24 , V_25 ) ;
V_21 |= F_8 ( & V_20 -> V_26 , V_23 ) ;
V_21 |= F_8 ( & V_20 -> V_27 , V_28 ) ;
V_21 |= F_8 ( & V_20 -> V_29 , V_28 | V_30 ) ;
if ( V_21 )
return 1 ;
V_21 |= F_9 ( V_20 -> V_29 ) ;
if ( V_21 )
return 2 ;
V_21 |= F_10 ( & V_20 -> V_31 , 0 ) ;
V_21 |= F_10 ( & V_20 -> V_32 , 0 ) ;
V_21 |= F_10 ( & V_20 -> V_33 , 0 ) ;
V_21 |= F_10 ( & V_20 -> V_34 , V_20 -> V_35 ) ;
if ( V_20 -> V_29 == V_28 )
V_21 |= F_11 ( & V_20 -> V_36 , 1 ) ;
else
V_21 |= F_10 ( & V_20 -> V_36 , 0 ) ;
if ( V_21 )
return 3 ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_19 * V_20 = & V_4 -> V_37 -> V_20 ;
struct V_13 * V_14 = V_4 -> V_15 ;
unsigned char V_17 ;
unsigned int V_11 ;
unsigned long V_38 ;
V_17 = 0 ;
for ( V_11 = 0 ; V_11 < V_20 -> V_35 ; V_11 ++ )
V_17 |= 1 << F_13 ( V_20 -> V_39 [ V_11 ] ) ;
F_14 ( & V_14 -> V_40 , V_38 ) ;
V_14 -> V_17 = V_17 ;
V_14 -> V_41 = V_20 -> V_36 ;
V_14 -> V_16 = true ;
F_4 ( V_17 , V_2 -> V_9 + V_18 ) ;
F_15 ( & V_14 -> V_40 , V_38 ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_13 * V_14 = V_4 -> V_15 ;
unsigned long V_38 ;
F_14 ( & V_14 -> V_40 , V_38 ) ;
if ( V_14 -> V_16 )
F_6 ( V_2 , V_4 ) ;
F_15 ( & V_14 -> V_40 , V_38 ) ;
return 0 ;
}
static T_1 F_17 ( int V_42 , void * V_43 )
{
struct V_1 * V_2 = V_43 ;
struct V_3 * V_4 = V_2 -> V_44 ;
struct V_19 * V_20 = & V_4 -> V_37 -> V_20 ;
struct V_13 * V_14 ;
unsigned int V_45 ;
bool V_46 = false ;
if ( ! V_2 -> V_47 )
return V_48 ;
V_45 = F_2 ( V_2 -> V_9 + V_49 ) & V_50 ;
if ( ! V_45 )
return V_48 ;
V_14 = V_4 -> V_15 ;
F_18 ( & V_14 -> V_40 ) ;
V_45 = F_2 ( V_2 -> V_9 + V_12 ) & 3 ;
F_4 ( ~ V_45 & 3 , V_2 -> V_9 + V_18 ) ;
if ( V_14 -> V_16 && ( V_45 & V_14 -> V_17 ) != 0 ) {
unsigned short V_51 = 0 ;
int V_52 ;
for ( V_52 = 0 ; V_52 < V_20 -> V_35 ; V_52 ++ ) {
unsigned int V_53 = F_13 ( V_20 -> V_39 [ V_52 ] ) ;
if ( V_45 & ( 1 << V_53 ) )
V_51 |= ( 1 << V_52 ) ;
}
if ( F_19 ( V_4 , V_51 ) ) {
V_4 -> V_37 -> V_54 |= V_55 | V_56 ;
if ( V_20 -> V_29 == V_28 &&
V_14 -> V_41 > 0 ) {
V_14 -> V_41 -- ;
if ( V_14 -> V_41 == 0 ) {
V_4 -> V_37 -> V_54 |= V_57 ;
F_6 ( V_2 , V_4 ) ;
}
}
} else {
F_6 ( V_2 , V_4 ) ;
V_4 -> V_37 -> V_54 |= V_58 ;
}
V_46 = true ;
}
F_20 ( & V_14 -> V_40 ) ;
if ( V_46 )
F_21 ( V_2 , V_4 ) ;
return V_59 ;
}
static int F_22 ( struct V_1 * V_2 )
{
F_4 ( 0x0 , V_2 -> V_9 + V_10 ) ;
F_4 ( 0x0 , V_2 -> V_9 + V_18 ) ;
F_23 ( V_2 -> V_9 + V_60 ) ;
return 0 ;
}
static int F_24 ( struct V_1 * V_2 ,
unsigned long V_61 )
{
struct V_62 * V_63 = F_25 ( V_2 ) ;
struct V_3 * V_4 ;
int V_64 ;
V_64 = F_26 ( V_2 ) ;
if ( V_64 )
return V_64 ;
V_2 -> V_9 = F_27 ( V_63 , 1 ) ;
F_22 ( V_2 ) ;
if ( V_63 -> V_42 > 0 ) {
V_64 = F_28 ( V_63 -> V_42 , F_17 ,
V_65 , V_2 -> V_66 , V_2 ) ;
if ( V_64 == 0 )
V_2 -> V_42 = V_63 -> V_42 ;
}
V_64 = F_29 ( V_2 , 3 ) ;
if ( V_64 )
return V_64 ;
V_4 = & V_2 -> V_67 [ 0 ] ;
V_4 -> type = V_68 ;
V_4 -> V_69 = V_70 ;
V_4 -> V_71 = 32 ;
V_4 -> V_72 = 1 ;
V_4 -> V_73 = & V_74 ;
V_4 -> V_75 = F_1 ;
V_4 = & V_2 -> V_67 [ 1 ] ;
V_64 = F_30 ( V_4 , V_2 -> V_9 + V_60 ) ;
if ( V_64 )
return V_64 ;
V_4 = & V_2 -> V_67 [ 2 ] ;
V_4 -> type = V_76 ;
V_4 -> V_69 = V_77 ;
V_4 -> V_71 = 2 ;
V_4 -> V_72 = 1 ;
V_4 -> V_73 = & V_74 ;
V_4 -> V_75 = F_5 ;
if ( V_2 -> V_42 ) {
struct V_13 * V_14 ;
V_2 -> V_44 = V_4 ;
V_14 = F_31 ( sizeof( * V_14 ) , V_78 ) ;
if ( ! V_14 )
return - V_79 ;
F_32 ( & V_14 -> V_40 ) ;
V_4 -> V_15 = V_14 ;
V_4 -> V_69 = V_77 | V_80 ;
V_4 -> V_81 = 2 ;
V_4 -> V_82 = F_7 ;
V_4 -> V_83 = F_12 ;
V_4 -> V_84 = F_16 ;
}
return 0 ;
}
static void F_33 ( struct V_1 * V_2 )
{
if ( V_2 -> V_9 )
F_22 ( V_2 ) ;
F_34 ( V_2 ) ;
if ( V_2 -> V_44 )
F_35 ( V_2 -> V_44 -> V_15 ) ;
}
static int F_36 ( struct V_62 * V_2 ,
const struct V_85 * V_86 )
{
return F_37 ( V_2 , & V_87 , V_86 -> V_88 ) ;
}
