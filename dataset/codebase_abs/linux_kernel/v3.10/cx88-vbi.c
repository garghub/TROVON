int F_1 ( struct V_1 * V_1 , void * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 ;
struct V_7 * V_8 = V_6 -> V_8 ;
V_4 -> V_9 . V_10 . V_11 = V_12 ;
V_4 -> V_9 . V_10 . V_13 = V_14 ;
V_4 -> V_9 . V_10 . V_15 = 244 ;
V_4 -> V_9 . V_10 . V_16 [ 0 ] = V_17 ;
V_4 -> V_9 . V_10 . V_16 [ 1 ] = V_17 ;
if ( V_8 -> V_18 -> V_19 & V_20 ) {
V_4 -> V_9 . V_10 . V_21 = 28636363 ;
V_4 -> V_9 . V_10 . V_22 [ 0 ] = 10 ;
V_4 -> V_9 . V_10 . V_22 [ 1 ] = 273 ;
} else if ( V_8 -> V_18 -> V_19 & V_23 ) {
V_4 -> V_9 . V_10 . V_21 = 35468950 ;
V_4 -> V_9 . V_10 . V_22 [ 0 ] = 7 - 1 ;
V_4 -> V_9 . V_10 . V_22 [ 1 ] = 319 - 1 ;
}
return 0 ;
}
static int F_2 ( struct V_7 * V_8 ,
struct V_24 * V_25 ,
struct V_26 * V_27 )
{
struct V_28 * V_18 = V_8 -> V_18 ;
F_3 ( V_8 -> V_18 , & V_29 [ V_30 ] ,
V_27 -> V_31 . V_32 , V_27 -> V_33 . V_34 ) ;
F_4 ( V_35 , ( ( 1 << 18 ) |
( 1 << 15 ) |
( 1 << 11 ) ) ) ;
F_4 ( V_36 , V_37 ) ;
V_25 -> V_16 = 1 ;
F_5 ( V_38 , V_18 -> V_39 | V_40 ) ;
F_5 ( V_41 , 0x0f0088 ) ;
F_5 ( V_42 , 0x18 ) ;
F_5 ( V_43 , ( 1 << 5 ) ) ;
F_5 ( V_44 , 0x88 ) ;
return 0 ;
}
int F_6 ( struct V_7 * V_8 )
{
struct V_28 * V_18 = V_8 -> V_18 ;
F_7 ( V_44 , 0x88 ) ;
F_7 ( V_42 , 0x18 ) ;
F_7 ( V_38 , V_40 ) ;
F_7 ( V_41 , 0x0f0088 ) ;
return 0 ;
}
int F_8 ( struct V_7 * V_8 ,
struct V_24 * V_25 )
{
struct V_26 * V_27 ;
if ( F_9 ( & V_25 -> V_45 ) )
return 0 ;
V_27 = F_10 ( V_25 -> V_45 . V_46 , struct V_26 , V_31 . V_47 ) ;
F_11 ( 2 , L_1 ,
V_27 , V_27 -> V_31 . V_48 ) ;
F_2 ( V_8 , V_25 , V_27 ) ;
F_12 (buf, &q->active, vb.queue)
V_27 -> V_16 = V_25 -> V_16 ++ ;
F_13 ( & V_25 -> V_49 , V_50 + V_51 ) ;
return 0 ;
}
void F_14 ( unsigned long V_52 )
{
struct V_7 * V_8 = (struct V_7 * ) V_52 ;
struct V_28 * V_18 = V_8 -> V_18 ;
struct V_24 * V_25 = & V_8 -> V_53 ;
struct V_26 * V_27 ;
unsigned long V_54 ;
F_15 ( V_8 -> V_18 , & V_29 [ V_30 ] ) ;
F_7 ( V_44 , 0x88 ) ;
F_7 ( V_42 , 0x18 ) ;
F_16 ( & V_8 -> V_55 , V_54 ) ;
while ( ! F_9 ( & V_25 -> V_45 ) ) {
V_27 = F_10 ( V_25 -> V_45 . V_46 , struct V_26 , V_31 . V_47 ) ;
F_17 ( & V_27 -> V_31 . V_47 ) ;
V_27 -> V_31 . V_56 = V_57 ;
F_18 ( & V_27 -> V_31 . V_58 ) ;
F_19 ( L_2 , V_8 -> V_18 -> V_59 ,
V_27 , V_27 -> V_31 . V_48 , ( unsigned long ) V_27 -> V_33 . V_34 ) ;
}
F_8 ( V_8 , V_25 ) ;
F_20 ( & V_8 -> V_55 , V_54 ) ;
}
static int
F_21 ( struct V_60 * V_25 , unsigned int * V_16 , unsigned int * V_61 )
{
* V_61 = V_17 * V_12 * 2 ;
if ( 0 == * V_16 )
* V_16 = V_62 ;
if ( * V_16 < 2 )
* V_16 = 2 ;
if ( * V_16 > 32 )
* V_16 = 32 ;
return 0 ;
}
static int
F_22 ( struct V_60 * V_25 , struct V_63 * V_31 ,
enum V_64 V_65 )
{
struct V_5 * V_6 = V_25 -> V_66 ;
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_26 * V_27 = F_23 ( V_31 , struct V_26 , V_31 ) ;
unsigned int V_61 ;
int V_67 ;
V_61 = V_17 * V_12 * 2 ;
if ( 0 != V_27 -> V_31 . V_68 && V_27 -> V_31 . V_69 < V_61 )
return - V_70 ;
if ( V_71 == V_27 -> V_31 . V_56 ) {
struct V_72 * V_34 = F_24 ( & V_27 -> V_31 ) ;
V_27 -> V_31 . V_32 = V_12 ;
V_27 -> V_31 . V_73 = V_17 ;
V_27 -> V_31 . V_61 = V_61 ;
V_27 -> V_31 . V_65 = V_74 ;
if ( 0 != ( V_67 = F_25 ( V_25 , & V_27 -> V_31 , NULL ) ) )
goto V_75;
F_26 ( V_8 -> V_76 , & V_27 -> V_33 ,
V_34 -> V_77 ,
0 , V_27 -> V_31 . V_32 * V_27 -> V_31 . V_73 ,
V_27 -> V_31 . V_32 , 0 ,
V_27 -> V_31 . V_73 ) ;
}
V_27 -> V_31 . V_56 = V_78 ;
return 0 ;
V_75:
F_27 ( V_25 , V_27 ) ;
return V_67 ;
}
static void
F_28 ( struct V_60 * V_79 , struct V_63 * V_31 )
{
struct V_26 * V_27 = F_23 ( V_31 , struct V_26 , V_31 ) ;
struct V_26 * V_80 ;
struct V_5 * V_6 = V_79 -> V_66 ;
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_24 * V_25 = & V_8 -> V_53 ;
V_27 -> V_33 . V_81 [ 0 ] = F_29 ( V_82 | V_83 | V_84 ) ;
V_27 -> V_33 . V_81 [ 1 ] = F_29 ( V_25 -> V_85 . V_34 ) ;
if ( F_9 ( & V_25 -> V_45 ) ) {
F_30 ( & V_27 -> V_31 . V_47 , & V_25 -> V_45 ) ;
F_2 ( V_8 , V_25 , V_27 ) ;
V_27 -> V_31 . V_56 = V_86 ;
V_27 -> V_16 = V_25 -> V_16 ++ ;
F_13 ( & V_25 -> V_49 , V_50 + V_51 ) ;
F_11 ( 2 , L_3 ,
V_27 , V_27 -> V_31 . V_48 ) ;
} else {
V_80 = F_10 ( V_25 -> V_45 . V_80 , struct V_26 , V_31 . V_47 ) ;
F_30 ( & V_27 -> V_31 . V_47 , & V_25 -> V_45 ) ;
V_27 -> V_31 . V_56 = V_86 ;
V_27 -> V_16 = V_25 -> V_16 ++ ;
V_80 -> V_33 . V_81 [ 1 ] = F_29 ( V_27 -> V_33 . V_34 ) ;
F_11 ( 2 , L_4 ,
V_27 , V_27 -> V_31 . V_48 ) ;
}
}
static void F_31 ( struct V_60 * V_25 , struct V_63 * V_31 )
{
struct V_26 * V_27 = F_23 ( V_31 , struct V_26 , V_31 ) ;
F_27 ( V_25 , V_27 ) ;
}
