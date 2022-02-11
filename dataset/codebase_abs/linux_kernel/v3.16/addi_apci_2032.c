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
static bool F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
unsigned char V_17 )
{
struct V_13 * V_14 = V_4 -> V_15 ;
struct V_19 * V_20 = & V_4 -> V_21 -> V_20 ;
bool V_22 ;
V_14 -> V_17 = V_17 ;
V_14 -> V_23 = V_20 -> V_24 ;
if ( V_20 -> V_25 == V_26 && V_14 -> V_23 == 0 ) {
V_4 -> V_21 -> V_27 |= V_28 ;
V_14 -> V_16 = false ;
V_22 = true ;
} else {
V_14 -> V_16 = true ;
F_4 ( V_17 , V_2 -> V_9 + V_18 ) ;
V_22 = false ;
}
return V_22 ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_19 * V_20 )
{
int V_29 = 0 ;
V_29 |= F_9 ( & V_20 -> V_30 , V_31 ) ;
V_29 |= F_9 ( & V_20 -> V_32 , V_33 ) ;
V_29 |= F_9 ( & V_20 -> V_34 , V_31 ) ;
V_29 |= F_9 ( & V_20 -> V_35 , V_26 ) ;
V_29 |= F_9 ( & V_20 -> V_25 , V_26 | V_36 ) ;
if ( V_29 )
return 1 ;
V_29 |= F_10 ( V_20 -> V_25 ) ;
if ( V_29 )
return 2 ;
V_29 |= F_11 ( & V_20 -> V_37 , 0 ) ;
V_29 |= F_11 ( & V_20 -> V_38 , 0 ) ;
V_29 |= F_11 ( & V_20 -> V_39 , 0 ) ;
V_29 |= F_11 ( & V_20 -> V_40 , V_20 -> V_41 ) ;
if ( V_20 -> V_25 == V_36 )
V_29 |= F_11 ( & V_20 -> V_24 , 0 ) ;
if ( V_29 )
return 3 ;
if ( V_29 )
return 4 ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_19 * V_20 = & V_4 -> V_21 -> V_20 ;
struct V_13 * V_14 = V_4 -> V_15 ;
unsigned char V_17 ;
unsigned int V_11 ;
unsigned long V_42 ;
bool V_22 ;
V_17 = 0 ;
for ( V_11 = 0 ; V_11 < V_20 -> V_41 ; V_11 ++ )
V_17 |= 1 << F_13 ( V_20 -> V_43 [ V_11 ] ) ;
F_14 ( & V_14 -> V_44 , V_42 ) ;
V_22 = F_7 ( V_2 , V_4 , V_17 ) ;
F_15 ( & V_14 -> V_44 , V_42 ) ;
if ( V_22 )
F_16 ( V_2 , V_4 ) ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_13 * V_14 = V_4 -> V_15 ;
unsigned long V_42 ;
F_14 ( & V_14 -> V_44 , V_42 ) ;
if ( V_14 -> V_16 )
F_6 ( V_2 , V_4 ) ;
F_15 ( & V_14 -> V_44 , V_42 ) ;
return 0 ;
}
static T_1 F_18 ( int V_45 , void * V_46 )
{
struct V_1 * V_2 = V_46 ;
struct V_3 * V_4 = V_2 -> V_47 ;
struct V_19 * V_20 = & V_4 -> V_21 -> V_20 ;
struct V_13 * V_14 ;
unsigned int V_48 ;
bool V_22 = false ;
if ( ! V_2 -> V_49 )
return V_50 ;
V_48 = F_2 ( V_2 -> V_9 + V_51 ) & V_52 ;
if ( ! V_48 )
return V_50 ;
V_14 = V_4 -> V_15 ;
F_19 ( & V_14 -> V_44 ) ;
V_48 = F_2 ( V_2 -> V_9 + V_12 ) & 3 ;
F_4 ( ~ V_48 & 3 , V_2 -> V_9 + V_18 ) ;
if ( V_14 -> V_16 && ( V_48 & V_14 -> V_17 ) != 0 ) {
unsigned short V_53 = 0 ;
int V_54 ;
for ( V_54 = 0 ; V_54 < V_20 -> V_41 ; V_54 ++ ) {
unsigned int V_55 = F_13 ( V_20 -> V_43 [ V_54 ] ) ;
if ( V_48 & ( 1 << V_55 ) )
V_53 |= ( 1 << V_54 ) ;
}
if ( F_20 ( V_4 , V_53 ) ) {
V_4 -> V_21 -> V_27 |= V_56 | V_57 ;
if ( V_20 -> V_25 == V_26 &&
V_14 -> V_23 > 0 ) {
V_14 -> V_23 -- ;
if ( V_14 -> V_23 == 0 ) {
V_4 -> V_21 -> V_27 |= V_28 ;
F_6 ( V_2 , V_4 ) ;
}
}
} else {
F_6 ( V_2 , V_4 ) ;
V_4 -> V_21 -> V_27 |= V_58 ;
}
V_22 = true ;
}
F_21 ( & V_14 -> V_44 ) ;
if ( V_22 )
F_16 ( V_2 , V_4 ) ;
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
if ( V_63 -> V_45 > 0 ) {
V_64 = F_28 ( V_63 -> V_45 , F_18 ,
V_65 , V_2 -> V_66 , V_2 ) ;
if ( V_64 == 0 )
V_2 -> V_45 = V_63 -> V_45 ;
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
if ( V_2 -> V_45 ) {
struct V_13 * V_14 ;
V_2 -> V_47 = V_4 ;
V_14 = F_31 ( sizeof( * V_14 ) , V_78 ) ;
if ( ! V_14 )
return - V_79 ;
F_32 ( & V_14 -> V_44 ) ;
V_4 -> V_15 = V_14 ;
V_4 -> V_69 = V_77 | V_80 ;
V_4 -> V_81 = 2 ;
V_4 -> V_82 = F_8 ;
V_4 -> V_83 = F_12 ;
V_4 -> V_84 = F_17 ;
}
return 0 ;
}
static void F_33 ( struct V_1 * V_2 )
{
if ( V_2 -> V_9 )
F_22 ( V_2 ) ;
if ( V_2 -> V_45 )
F_34 ( V_2 -> V_45 , V_2 ) ;
if ( V_2 -> V_47 )
F_35 ( V_2 -> V_47 -> V_15 ) ;
F_36 ( V_2 ) ;
}
static int F_37 ( struct V_62 * V_2 ,
const struct V_85 * V_86 )
{
return F_38 ( V_2 , & V_87 , V_86 -> V_88 ) ;
}
