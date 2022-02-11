int F_1 ( struct V_1 * V_1 , void * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_1 ) ;
V_4 -> V_7 . V_8 . V_9 = V_10 ;
V_4 -> V_7 . V_8 . V_11 = V_12 ;
V_4 -> V_7 . V_8 . V_13 = 244 ;
if ( V_6 -> V_14 -> V_15 & V_16 ) {
V_4 -> V_7 . V_8 . V_17 = 28636363 ;
V_4 -> V_7 . V_8 . V_18 [ 0 ] = 10 ;
V_4 -> V_7 . V_8 . V_18 [ 1 ] = 273 ;
V_4 -> V_7 . V_8 . V_19 [ 0 ] = V_20 ;
V_4 -> V_7 . V_8 . V_19 [ 1 ] = V_20 ;
} else if ( V_6 -> V_14 -> V_15 & V_21 ) {
V_4 -> V_7 . V_8 . V_17 = 35468950 ;
V_4 -> V_7 . V_8 . V_18 [ 0 ] = V_22 + 5 ;
V_4 -> V_7 . V_8 . V_18 [ 1 ] = V_23 + 5 ;
V_4 -> V_7 . V_8 . V_19 [ 0 ] = V_24 ;
V_4 -> V_7 . V_8 . V_19 [ 1 ] = V_24 ;
}
return 0 ;
}
static int F_3 ( struct V_5 * V_6 ,
struct V_25 * V_26 ,
struct V_27 * V_28 )
{
struct V_29 * V_14 = V_6 -> V_14 ;
F_4 ( V_6 -> V_14 , & V_30 [ V_31 ] ,
V_10 , V_28 -> V_32 . V_33 ) ;
F_5 ( V_34 , ( ( 1 << 18 ) |
( 1 << 15 ) |
( 1 << 11 ) ) ) ;
F_5 ( V_35 , V_36 ) ;
V_26 -> V_19 = 0 ;
F_6 ( V_37 , V_14 -> V_38 | V_39 ) ;
F_6 ( V_40 , 0x0f0088 ) ;
F_6 ( V_41 , 0x18 ) ;
F_6 ( V_42 , ( 1 << 5 ) ) ;
F_6 ( V_43 , 0x88 ) ;
return 0 ;
}
void F_7 ( struct V_5 * V_6 )
{
struct V_29 * V_14 = V_6 -> V_14 ;
F_8 ( V_43 , 0x88 ) ;
F_8 ( V_41 , 0x18 ) ;
F_8 ( V_37 , V_39 ) ;
F_8 ( V_40 , 0x0f0088 ) ;
}
int F_9 ( struct V_5 * V_6 ,
struct V_25 * V_26 )
{
struct V_27 * V_28 ;
if ( F_10 ( & V_26 -> V_44 ) )
return 0 ;
V_28 = F_11 ( V_26 -> V_44 . V_45 , struct V_27 , V_46 ) ;
F_12 ( 2 , L_1 ,
V_28 , V_28 -> V_47 . V_48 . V_49 ) ;
F_3 ( V_6 , V_26 , V_28 ) ;
return 0 ;
}
static int F_13 ( struct V_50 * V_26 ,
unsigned int * V_51 , unsigned int * V_52 ,
unsigned int V_53 [] , struct V_54 * V_55 [] )
{
struct V_5 * V_6 = V_26 -> V_56 ;
* V_52 = 1 ;
if ( V_6 -> V_14 -> V_15 & V_16 )
V_53 [ 0 ] = V_20 * V_10 * 2 ;
else
V_53 [ 0 ] = V_24 * V_10 * 2 ;
return 0 ;
}
static int F_14 ( struct V_57 * V_47 )
{
struct V_58 * V_59 = F_15 ( V_47 ) ;
struct V_5 * V_6 = V_47 -> V_50 -> V_56 ;
struct V_27 * V_28 = F_16 ( V_59 , struct V_27 , V_47 ) ;
struct V_60 * V_61 = F_17 ( V_47 , 0 ) ;
unsigned int V_62 ;
unsigned int V_63 ;
if ( V_6 -> V_14 -> V_15 & V_16 )
V_62 = V_20 ;
else
V_62 = V_24 ;
V_63 = V_62 * V_10 * 2 ;
if ( F_18 ( V_47 , 0 ) < V_63 )
return - V_64 ;
F_19 ( V_47 , 0 , V_63 ) ;
F_20 ( V_6 -> V_65 , & V_28 -> V_32 , V_61 -> V_66 ,
0 , V_10 * V_62 ,
V_10 , 0 ,
V_62 ) ;
return 0 ;
}
static void F_21 ( struct V_57 * V_47 )
{
struct V_58 * V_59 = F_15 ( V_47 ) ;
struct V_5 * V_6 = V_47 -> V_50 -> V_56 ;
struct V_27 * V_28 = F_16 ( V_59 , struct V_27 , V_47 ) ;
struct V_67 * V_32 = & V_28 -> V_32 ;
if ( V_32 -> V_68 )
F_22 ( V_6 -> V_65 , V_32 -> V_63 , V_32 -> V_68 , V_32 -> V_33 ) ;
memset ( V_32 , 0 , sizeof( * V_32 ) ) ;
}
static void F_23 ( struct V_57 * V_47 )
{
struct V_58 * V_59 = F_15 ( V_47 ) ;
struct V_5 * V_6 = V_47 -> V_50 -> V_56 ;
struct V_27 * V_28 = F_16 ( V_59 , struct V_27 , V_47 ) ;
struct V_27 * V_69 ;
struct V_25 * V_26 = & V_6 -> V_70 ;
V_28 -> V_32 . V_68 [ 1 ] = F_24 ( V_28 -> V_32 . V_33 + 8 ) ;
V_28 -> V_32 . V_71 [ 0 ] = F_24 ( V_72 | V_73 ) ;
V_28 -> V_32 . V_71 [ 1 ] = F_24 ( V_28 -> V_32 . V_33 + 8 ) ;
if ( F_10 ( & V_26 -> V_44 ) ) {
F_25 ( & V_28 -> V_46 , & V_26 -> V_44 ) ;
F_3 ( V_6 , V_26 , V_28 ) ;
F_12 ( 2 , L_2 ,
V_28 , V_28 -> V_47 . V_48 . V_49 ) ;
} else {
V_28 -> V_32 . V_68 [ 0 ] |= F_24 ( V_74 ) ;
V_69 = F_11 ( V_26 -> V_44 . V_69 , struct V_27 , V_46 ) ;
F_25 ( & V_28 -> V_46 , & V_26 -> V_44 ) ;
V_69 -> V_32 . V_71 [ 1 ] = F_24 ( V_28 -> V_32 . V_33 ) ;
F_12 ( 2 , L_3 ,
V_28 , V_28 -> V_47 . V_48 . V_49 ) ;
}
}
static int F_26 ( struct V_50 * V_26 , unsigned int V_19 )
{
struct V_5 * V_6 = V_26 -> V_56 ;
struct V_25 * V_75 = & V_6 -> V_70 ;
struct V_27 * V_28 = F_11 ( V_75 -> V_44 . V_45 ,
struct V_27 , V_46 ) ;
F_3 ( V_6 , V_75 , V_28 ) ;
return 0 ;
}
static void F_27 ( struct V_50 * V_26 )
{
struct V_5 * V_6 = V_26 -> V_56 ;
struct V_29 * V_14 = V_6 -> V_14 ;
struct V_25 * V_75 = & V_6 -> V_70 ;
unsigned long V_76 ;
F_8 ( V_43 , 0x11 ) ;
F_8 ( V_41 , 0x06 ) ;
F_7 ( V_6 ) ;
F_28 ( & V_6 -> V_77 , V_76 ) ;
while ( ! F_10 ( & V_75 -> V_44 ) ) {
struct V_27 * V_28 = F_11 ( V_75 -> V_44 . V_45 ,
struct V_27 , V_46 ) ;
F_29 ( & V_28 -> V_46 ) ;
F_30 ( & V_28 -> V_47 . V_48 , V_78 ) ;
}
F_31 ( & V_6 -> V_77 , V_76 ) ;
}
