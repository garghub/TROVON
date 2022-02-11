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
F_11 ( V_44 , 3 ) ;
V_35 -> V_21 = 0 ;
F_12 ( V_6 , 0x01 ) ;
F_13 ( V_45 , 0x000022 ) ;
F_13 ( V_46 , ( 1 << 5 ) ) ;
F_13 ( V_47 , 0x22 ) ;
return 0 ;
}
static int F_14 ( struct V_48 * V_35 , const struct V_3 * V_7 ,
unsigned int * V_49 , unsigned int * V_50 ,
unsigned int V_51 [] , void * V_52 [] )
{
struct V_5 * V_6 = V_35 -> V_53 ;
unsigned V_54 = V_26 ;
if ( V_6 -> V_16 & V_17 )
V_54 = V_22 ;
* V_50 = 1 ;
V_51 [ 0 ] = V_54 * V_11 * 2 ;
V_52 [ 0 ] = V_6 -> V_55 ;
return 0 ;
}
static int F_15 ( struct V_56 * V_57 )
{
struct V_5 * V_6 = V_57 -> V_48 -> V_53 ;
struct V_36 * V_37 = F_16 ( V_57 ,
struct V_36 , V_57 ) ;
struct V_58 * V_59 = F_17 ( V_57 , 0 ) ;
unsigned V_54 = V_26 ;
if ( V_6 -> V_16 & V_17 )
V_54 = V_22 ;
if ( F_18 ( V_57 , 0 ) < V_54 * V_11 * 2 )
return - V_60 ;
F_19 ( V_57 , 0 , V_54 * V_11 * 2 ) ;
F_20 ( V_6 -> V_61 , & V_37 -> V_40 ,
V_59 -> V_62 ,
0 , V_11 * V_54 ,
V_11 , 0 ,
V_54 ) ;
return 0 ;
}
static void F_21 ( struct V_56 * V_57 )
{
struct V_36 * V_37 = F_16 ( V_57 ,
struct V_36 , V_57 ) ;
F_22 ( V_57 -> V_48 -> V_53 , V_37 ) ;
}
static void F_23 ( struct V_56 * V_57 )
{
struct V_5 * V_6 = V_57 -> V_48 -> V_53 ;
struct V_36 * V_37 = F_16 ( V_57 , struct V_36 , V_57 ) ;
struct V_36 * V_63 ;
struct V_34 * V_35 = & V_6 -> V_33 ;
unsigned long V_15 ;
V_37 -> V_40 . V_64 [ 1 ] = F_24 ( V_37 -> V_40 . V_41 + 12 ) ;
V_37 -> V_40 . V_65 [ 0 ] = F_24 ( V_66 | V_67 ) ;
V_37 -> V_40 . V_65 [ 1 ] = F_24 ( V_37 -> V_40 . V_41 + 12 ) ;
V_37 -> V_40 . V_65 [ 2 ] = F_24 ( 0 ) ;
if ( F_25 ( & V_35 -> V_68 ) ) {
F_26 ( & V_6 -> V_31 , V_15 ) ;
F_27 ( & V_37 -> V_69 , & V_35 -> V_68 ) ;
F_28 ( & V_6 -> V_31 , V_15 ) ;
F_4 ( 2 , L_3 ,
V_37 , V_37 -> V_57 . V_70 . V_71 ) ;
} else {
V_37 -> V_40 . V_64 [ 0 ] |= F_24 ( V_72 ) ;
V_63 = F_29 ( V_35 -> V_68 . V_63 , struct V_36 ,
V_69 ) ;
F_26 ( & V_6 -> V_31 , V_15 ) ;
F_27 ( & V_37 -> V_69 , & V_35 -> V_68 ) ;
F_28 ( & V_6 -> V_31 , V_15 ) ;
V_63 -> V_40 . V_65 [ 1 ] = F_24 ( V_37 -> V_40 . V_41 ) ;
F_4 ( 2 , L_4 ,
V_37 , V_37 -> V_57 . V_70 . V_71 ) ;
}
}
static int F_30 ( struct V_48 * V_35 , unsigned int V_21 )
{
struct V_5 * V_6 = V_35 -> V_53 ;
struct V_34 * V_73 = & V_6 -> V_33 ;
struct V_36 * V_37 = F_29 ( V_73 -> V_68 . V_74 ,
struct V_36 , V_69 ) ;
F_9 ( V_6 , V_73 , V_37 ) ;
return 0 ;
}
static void F_31 ( struct V_48 * V_35 )
{
struct V_5 * V_6 = V_35 -> V_53 ;
struct V_34 * V_73 = & V_6 -> V_33 ;
unsigned long V_15 ;
F_32 ( V_47 , 0x22 ) ;
F_26 ( & V_6 -> V_31 , V_15 ) ;
while ( ! F_25 ( & V_73 -> V_68 ) ) {
struct V_36 * V_37 = F_29 ( V_73 -> V_68 . V_74 ,
struct V_36 , V_69 ) ;
F_33 ( & V_37 -> V_69 ) ;
F_34 ( & V_37 -> V_57 , V_75 ) ;
}
F_28 ( & V_6 -> V_31 , V_15 ) ;
}
