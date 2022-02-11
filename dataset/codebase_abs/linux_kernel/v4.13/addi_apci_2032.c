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
V_21 |= F_10 ( & V_20 -> V_34 ,
V_20 -> V_35 ) ;
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
static T_1 F_17 ( int V_41 , void * V_42 )
{
struct V_1 * V_2 = V_42 ;
struct V_3 * V_4 = V_2 -> V_43 ;
struct V_19 * V_20 = & V_4 -> V_37 -> V_20 ;
struct V_13 * V_14 ;
unsigned int V_44 ;
if ( ! V_2 -> V_45 )
return V_46 ;
V_44 = F_2 ( V_2 -> V_9 + V_47 ) & V_48 ;
if ( ! V_44 )
return V_46 ;
V_14 = V_4 -> V_15 ;
F_18 ( & V_14 -> V_40 ) ;
V_44 = F_2 ( V_2 -> V_9 + V_12 ) & 3 ;
F_4 ( ~ V_44 & 3 , V_2 -> V_9 + V_18 ) ;
if ( V_14 -> V_16 && ( V_44 & V_14 -> V_17 ) != 0 ) {
unsigned short V_49 = 0 ;
int V_50 ;
for ( V_50 = 0 ; V_50 < V_20 -> V_35 ; V_50 ++ ) {
unsigned int V_51 = F_13 ( V_20 -> V_39 [ V_50 ] ) ;
if ( V_44 & ( 1 << V_51 ) )
V_49 |= ( 1 << V_50 ) ;
}
F_19 ( V_4 , & V_49 , 1 ) ;
if ( V_20 -> V_29 == V_28 &&
V_4 -> V_37 -> V_52 >= V_20 -> V_36 )
V_4 -> V_37 -> V_53 |= V_54 ;
}
F_20 ( & V_14 -> V_40 ) ;
F_21 ( V_2 , V_4 ) ;
return V_55 ;
}
static int F_22 ( struct V_1 * V_2 )
{
F_4 ( 0x0 , V_2 -> V_9 + V_10 ) ;
F_4 ( 0x0 , V_2 -> V_9 + V_18 ) ;
F_23 ( V_2 -> V_9 + V_56 ) ;
return 0 ;
}
static int F_24 ( struct V_1 * V_2 ,
unsigned long V_57 )
{
struct V_58 * V_59 = F_25 ( V_2 ) ;
struct V_3 * V_4 ;
int V_60 ;
V_60 = F_26 ( V_2 ) ;
if ( V_60 )
return V_60 ;
V_2 -> V_9 = F_27 ( V_59 , 1 ) ;
F_22 ( V_2 ) ;
if ( V_59 -> V_41 > 0 ) {
V_60 = F_28 ( V_59 -> V_41 , F_17 ,
V_61 , V_2 -> V_62 , V_2 ) ;
if ( V_60 == 0 )
V_2 -> V_41 = V_59 -> V_41 ;
}
V_60 = F_29 ( V_2 , 3 ) ;
if ( V_60 )
return V_60 ;
V_4 = & V_2 -> V_63 [ 0 ] ;
V_4 -> type = V_64 ;
V_4 -> V_65 = V_66 ;
V_4 -> V_67 = 32 ;
V_4 -> V_68 = 1 ;
V_4 -> V_69 = & V_70 ;
V_4 -> V_71 = F_1 ;
V_4 = & V_2 -> V_63 [ 1 ] ;
V_60 = F_30 ( V_4 , V_2 -> V_9 + V_56 ) ;
if ( V_60 )
return V_60 ;
V_4 = & V_2 -> V_63 [ 2 ] ;
V_4 -> type = V_72 ;
V_4 -> V_65 = V_73 ;
V_4 -> V_67 = 2 ;
V_4 -> V_68 = 1 ;
V_4 -> V_69 = & V_70 ;
V_4 -> V_71 = F_5 ;
if ( V_2 -> V_41 ) {
struct V_13 * V_14 ;
V_2 -> V_43 = V_4 ;
V_14 = F_31 ( sizeof( * V_14 ) , V_74 ) ;
if ( ! V_14 )
return - V_75 ;
F_32 ( & V_14 -> V_40 ) ;
V_4 -> V_15 = V_14 ;
V_4 -> V_65 = V_73 | V_76 | V_77 ;
V_4 -> V_78 = 2 ;
V_4 -> V_79 = F_7 ;
V_4 -> V_80 = F_12 ;
V_4 -> V_81 = F_16 ;
}
return 0 ;
}
static void F_33 ( struct V_1 * V_2 )
{
if ( V_2 -> V_9 )
F_22 ( V_2 ) ;
F_34 ( V_2 ) ;
if ( V_2 -> V_43 )
F_35 ( V_2 -> V_43 -> V_15 ) ;
}
static int F_36 ( struct V_58 * V_2 ,
const struct V_82 * V_83 )
{
return F_37 ( V_2 , & V_84 , V_83 -> V_85 ) ;
}
