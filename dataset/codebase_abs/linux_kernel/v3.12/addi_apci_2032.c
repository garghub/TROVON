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
V_7 [ 1 ] = F_2 ( V_2 -> V_11 + V_14 ) & 3 ;
return V_6 -> V_13 ;
}
static void F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_15 * V_16 = V_4 -> V_17 ;
V_16 -> V_18 = false ;
V_16 -> V_19 = 0 ;
F_3 ( 0x0 , V_2 -> V_11 + V_20 ) ;
}
static bool F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
unsigned char V_19 )
{
struct V_15 * V_16 = V_4 -> V_17 ;
struct V_21 * V_22 = & V_4 -> V_23 -> V_22 ;
bool V_24 ;
V_16 -> V_19 = V_19 ;
V_16 -> V_25 = V_22 -> V_26 ;
if ( V_22 -> V_27 == V_28 && V_16 -> V_25 == 0 ) {
V_4 -> V_23 -> V_29 |= V_30 ;
V_16 -> V_18 = false ;
V_24 = true ;
} else {
V_16 -> V_18 = true ;
F_3 ( V_19 , V_2 -> V_11 + V_20 ) ;
V_24 = false ;
}
return V_24 ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_21 * V_22 )
{
int V_31 = 0 ;
V_31 |= F_8 ( & V_22 -> V_32 , V_33 ) ;
V_31 |= F_8 ( & V_22 -> V_34 , V_35 ) ;
V_31 |= F_8 ( & V_22 -> V_36 , V_33 ) ;
V_31 |= F_8 ( & V_22 -> V_37 , V_28 ) ;
V_31 |= F_8 ( & V_22 -> V_27 , V_28 | V_38 ) ;
if ( V_31 )
return 1 ;
V_31 |= F_9 ( V_22 -> V_27 ) ;
if ( V_31 )
return 2 ;
V_31 |= F_10 ( & V_22 -> V_39 , 0 ) ;
V_31 |= F_10 ( & V_22 -> V_40 , 0 ) ;
V_31 |= F_10 ( & V_22 -> V_41 , 0 ) ;
V_31 |= F_10 ( & V_22 -> V_42 , V_22 -> V_43 ) ;
if ( V_22 -> V_27 == V_38 )
V_31 |= F_10 ( & V_22 -> V_26 , 0 ) ;
if ( V_31 )
return 3 ;
if ( V_31 )
return 4 ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_21 * V_22 = & V_4 -> V_23 -> V_22 ;
struct V_15 * V_16 = V_4 -> V_17 ;
unsigned char V_19 ;
unsigned int V_13 ;
unsigned long V_44 ;
bool V_24 ;
V_19 = 0 ;
for ( V_13 = 0 ; V_13 < V_22 -> V_43 ; V_13 ++ )
V_19 |= 1 << F_12 ( V_22 -> V_45 [ V_13 ] ) ;
F_13 ( & V_16 -> V_46 , V_44 ) ;
V_24 = F_6 ( V_2 , V_4 , V_19 ) ;
F_14 ( & V_16 -> V_46 , V_44 ) ;
if ( V_24 )
F_15 ( V_2 , V_4 ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_15 * V_16 = V_4 -> V_17 ;
unsigned long V_44 ;
F_13 ( & V_16 -> V_46 , V_44 ) ;
if ( V_16 -> V_18 )
F_5 ( V_2 , V_4 ) ;
F_14 ( & V_16 -> V_46 , V_44 ) ;
return 0 ;
}
static T_1 F_17 ( int V_47 , void * V_48 )
{
struct V_1 * V_2 = V_48 ;
struct V_3 * V_4 = V_2 -> V_49 ;
struct V_15 * V_16 ;
unsigned int V_50 ;
bool V_24 = false ;
if ( ! V_2 -> V_51 )
return V_52 ;
V_50 = F_2 ( V_2 -> V_11 + V_53 ) & V_54 ;
if ( ! V_50 )
return V_52 ;
V_16 = V_4 -> V_17 ;
F_18 ( & V_16 -> V_46 ) ;
V_50 = F_2 ( V_2 -> V_11 + V_14 ) & 3 ;
F_3 ( ~ V_50 & 3 , V_2 -> V_11 + V_20 ) ;
if ( V_16 -> V_18 && ( V_50 & V_16 -> V_19 ) != 0 ) {
unsigned short V_9 ;
unsigned int V_13 , V_55 ;
unsigned int * V_45 ;
V_9 = 0 ;
V_55 = V_4 -> V_23 -> V_22 . V_43 ;
V_45 = & V_4 -> V_23 -> V_22 . V_45 [ 0 ] ;
for ( V_13 = 0 ; V_13 < V_55 ; V_13 ++ )
if ( ( V_50 & ( 1U << F_12 ( V_45 [ V_13 ] ) ) ) != 0 )
V_9 |= 1U << V_13 ;
if ( F_19 ( V_4 -> V_23 , V_9 ) ) {
V_4 -> V_23 -> V_29 |= V_56 | V_57 ;
if ( V_4 -> V_23 -> V_22 . V_27 == V_28 &&
V_16 -> V_25 > 0 ) {
V_16 -> V_25 -- ;
if ( V_16 -> V_25 == 0 ) {
V_4 -> V_23 -> V_29 |= V_30 ;
F_5 ( V_2 , V_4 ) ;
}
}
} else {
F_5 ( V_2 , V_4 ) ;
V_4 -> V_23 -> V_29 |= V_58 ;
}
V_24 = true ;
}
F_20 ( & V_16 -> V_46 ) ;
if ( V_24 )
F_15 ( V_2 , V_4 ) ;
return V_59 ;
}
static int F_21 ( struct V_1 * V_2 )
{
F_3 ( 0x0 , V_2 -> V_11 + V_12 ) ;
F_3 ( 0x0 , V_2 -> V_11 + V_20 ) ;
F_22 ( V_2 -> V_11 + V_60 ) ;
return 0 ;
}
static int F_23 ( struct V_1 * V_2 ,
unsigned long V_61 )
{
struct V_62 * V_63 = F_24 ( V_2 ) ;
struct V_3 * V_4 ;
int V_64 ;
V_64 = F_25 ( V_2 ) ;
if ( V_64 )
return V_64 ;
V_2 -> V_11 = F_26 ( V_63 , 1 ) ;
F_21 ( V_2 ) ;
if ( V_63 -> V_47 > 0 ) {
V_64 = F_27 ( V_63 -> V_47 , F_17 ,
V_65 , V_2 -> V_66 , V_2 ) ;
if ( V_64 == 0 )
V_2 -> V_47 = V_63 -> V_47 ;
}
V_64 = F_28 ( V_2 , 3 ) ;
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
V_64 = F_29 ( V_4 , V_2 -> V_11 + V_60 ) ;
if ( V_64 )
return V_64 ;
V_4 = & V_2 -> V_67 [ 2 ] ;
V_4 -> type = V_76 ;
V_4 -> V_69 = V_77 ;
V_4 -> V_71 = 2 ;
V_4 -> V_72 = 1 ;
V_4 -> V_73 = & V_74 ;
V_4 -> V_75 = F_4 ;
if ( V_2 -> V_47 ) {
struct V_15 * V_16 ;
V_2 -> V_49 = V_4 ;
V_16 = F_30 ( sizeof( * V_16 ) , V_78 ) ;
if ( ! V_16 )
return - V_79 ;
F_31 ( & V_16 -> V_46 ) ;
V_4 -> V_17 = V_16 ;
V_4 -> V_69 = V_77 | V_80 ;
V_4 -> V_81 = 2 ;
V_4 -> V_82 = F_7 ;
V_4 -> V_83 = F_11 ;
V_4 -> V_84 = F_16 ;
}
return 0 ;
}
static void F_32 ( struct V_1 * V_2 )
{
if ( V_2 -> V_11 )
F_21 ( V_2 ) ;
if ( V_2 -> V_47 )
F_33 ( V_2 -> V_47 , V_2 ) ;
if ( V_2 -> V_49 )
F_34 ( V_2 -> V_49 -> V_17 ) ;
F_35 ( V_2 ) ;
}
static int F_36 ( struct V_62 * V_2 ,
const struct V_85 * V_86 )
{
return F_37 ( V_2 , & V_87 , V_86 -> V_88 ) ;
}
