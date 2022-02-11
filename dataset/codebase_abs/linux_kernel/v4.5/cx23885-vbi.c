int F_1 ( struct V_1 * V_1 , void * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_1 ) ;
V_4 -> V_7 . V_8 . V_9 = 27000000 ;
V_4 -> V_7 . V_8 . V_10 = V_11 ;
V_4 -> V_7 . V_8 . V_12 = V_13 ;
V_4 -> V_7 . V_8 . V_14 = 0 ;
V_4 -> V_7 . V_8 . V_15 = 0 ;
if ( V_6 -> V_16 & V_17 ) {
V_4 -> V_7 . V_8 . V_18 [ 0 ] = V_19 + 9 ;
V_4 -> V_7 . V_8 . V_18 [ 1 ] = V_20 + 9 ;
V_4 -> V_7 . V_8 . V_21 [ 0 ] = V_22 ;
V_4 -> V_7 . V_8 . V_21 [ 1 ] = V_22 ;
} else if ( V_6 -> V_16 & V_23 ) {
V_4 -> V_7 . V_8 . V_18 [ 0 ] = V_24 + 5 ;
V_4 -> V_7 . V_8 . V_18 [ 1 ] = V_25 + 5 ;
V_4 -> V_7 . V_8 . V_21 [ 0 ] = V_26 ;
V_4 -> V_7 . V_8 . V_21 [ 1 ] = V_26 ;
}
return 0 ;
}
int F_3 ( struct V_5 * V_6 , T_1 V_27 )
{
T_1 V_21 ;
int V_28 = 0 ;
if ( V_27 & V_29 ) {
F_4 ( 1 , L_1 , V_30 ) ;
F_5 ( & V_6 -> V_31 ) ;
V_21 = F_6 ( V_32 ) ;
F_7 ( V_6 , & V_6 -> V_33 , V_21 ) ;
F_8 ( & V_6 -> V_31 ) ;
V_28 ++ ;
}
return V_28 ;
}
static int F_9 ( struct V_5 * V_6 ,
struct V_34 * V_35 ,
struct V_36 * V_37 )
{
F_4 ( 1 , L_2 , V_30 ) ;
F_10 ( V_6 , & V_6 -> V_38 [ V_39 ] ,
V_11 , V_37 -> V_40 . V_41 ) ;
F_11 ( V_42 , 3 ) ;
F_11 ( V_43 , 3 ) ;
V_35 -> V_21 = 0 ;
F_12 ( V_6 , 0x01 ) ;
F_13 ( V_44 , 0x000022 ) ;
F_13 ( V_45 , ( 1 << 5 ) ) ;
F_13 ( V_46 , 0x22 ) ;
return 0 ;
}
static int F_14 ( struct V_47 * V_35 ,
unsigned int * V_48 , unsigned int * V_49 ,
unsigned int V_50 [] , void * V_51 [] )
{
struct V_5 * V_6 = V_35 -> V_52 ;
unsigned V_53 = V_26 ;
if ( V_6 -> V_16 & V_17 )
V_53 = V_22 ;
* V_49 = 1 ;
V_50 [ 0 ] = V_53 * V_11 * 2 ;
V_51 [ 0 ] = V_6 -> V_54 ;
return 0 ;
}
static int F_15 ( struct V_55 * V_56 )
{
struct V_57 * V_58 = F_16 ( V_56 ) ;
struct V_5 * V_6 = V_56 -> V_47 -> V_52 ;
struct V_36 * V_37 = F_17 ( V_58 ,
struct V_36 , V_56 ) ;
struct V_59 * V_60 = F_18 ( V_56 , 0 ) ;
unsigned V_53 = V_26 ;
if ( V_6 -> V_16 & V_17 )
V_53 = V_22 ;
if ( F_19 ( V_56 , 0 ) < V_53 * V_11 * 2 )
return - V_61 ;
F_20 ( V_56 , 0 , V_53 * V_11 * 2 ) ;
F_21 ( V_6 -> V_62 , & V_37 -> V_40 ,
V_60 -> V_63 ,
0 , V_11 * V_53 ,
V_11 , 0 ,
V_53 ) ;
return 0 ;
}
static void F_22 ( struct V_55 * V_56 )
{
struct V_57 * V_58 = F_16 ( V_56 ) ;
struct V_36 * V_37 = F_17 ( V_58 ,
struct V_36 , V_56 ) ;
F_23 ( V_56 -> V_47 -> V_52 , V_37 ) ;
}
static void F_24 ( struct V_55 * V_56 )
{
struct V_57 * V_58 = F_16 ( V_56 ) ;
struct V_5 * V_6 = V_56 -> V_47 -> V_52 ;
struct V_36 * V_37 = F_17 ( V_58 ,
struct V_36 , V_56 ) ;
struct V_36 * V_64 ;
struct V_34 * V_35 = & V_6 -> V_33 ;
unsigned long V_15 ;
V_37 -> V_40 . V_65 [ 1 ] = F_25 ( V_37 -> V_40 . V_41 + 12 ) ;
V_37 -> V_40 . V_66 [ 0 ] = F_25 ( V_67 | V_68 ) ;
V_37 -> V_40 . V_66 [ 1 ] = F_25 ( V_37 -> V_40 . V_41 + 12 ) ;
V_37 -> V_40 . V_66 [ 2 ] = F_25 ( 0 ) ;
if ( F_26 ( & V_35 -> V_69 ) ) {
F_27 ( & V_6 -> V_31 , V_15 ) ;
F_28 ( & V_37 -> V_70 , & V_35 -> V_69 ) ;
F_29 ( & V_6 -> V_31 , V_15 ) ;
F_4 ( 2 , L_3 ,
V_37 , V_37 -> V_56 . V_71 . V_72 ) ;
} else {
V_37 -> V_40 . V_65 [ 0 ] |= F_25 ( V_73 ) ;
V_64 = F_30 ( V_35 -> V_69 . V_64 , struct V_36 ,
V_70 ) ;
F_27 ( & V_6 -> V_31 , V_15 ) ;
F_28 ( & V_37 -> V_70 , & V_35 -> V_69 ) ;
F_29 ( & V_6 -> V_31 , V_15 ) ;
V_64 -> V_40 . V_66 [ 1 ] = F_25 ( V_37 -> V_40 . V_41 ) ;
F_4 ( 2 , L_4 ,
V_37 , V_37 -> V_56 . V_71 . V_72 ) ;
}
}
static int F_31 ( struct V_47 * V_35 , unsigned int V_21 )
{
struct V_5 * V_6 = V_35 -> V_52 ;
struct V_34 * V_74 = & V_6 -> V_33 ;
struct V_36 * V_37 = F_30 ( V_74 -> V_69 . V_75 ,
struct V_36 , V_70 ) ;
F_9 ( V_6 , V_74 , V_37 ) ;
return 0 ;
}
static void F_32 ( struct V_47 * V_35 )
{
struct V_5 * V_6 = V_35 -> V_52 ;
struct V_34 * V_74 = & V_6 -> V_33 ;
unsigned long V_15 ;
F_33 ( V_46 , 0x22 ) ;
F_27 ( & V_6 -> V_31 , V_15 ) ;
while ( ! F_26 ( & V_74 -> V_69 ) ) {
struct V_36 * V_37 = F_30 ( V_74 -> V_69 . V_75 ,
struct V_36 , V_70 ) ;
F_34 ( & V_37 -> V_70 ) ;
F_35 ( & V_37 -> V_56 . V_71 , V_76 ) ;
}
F_29 ( & V_6 -> V_31 , V_15 ) ;
}
