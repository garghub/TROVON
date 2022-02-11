int F_1 ( struct V_1 * V_1 , void * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 ;
struct V_7 * V_8 = V_6 -> V_8 ;
if ( V_8 -> V_9 & V_10 ) {
V_4 -> V_11 . V_12 . V_13 = 28636363 ;
V_4 -> V_11 . V_12 . V_14 [ 0 ] = 10 ;
V_4 -> V_11 . V_12 . V_14 [ 1 ] = 273 ;
} else if ( V_8 -> V_9 & V_15 ) {
V_4 -> V_11 . V_12 . V_13 = 35468950 ;
V_4 -> V_11 . V_12 . V_14 [ 0 ] = 7 - 1 ;
V_4 -> V_11 . V_12 . V_14 [ 1 ] = 319 - 1 ;
}
return 0 ;
}
static int F_2 ( struct V_7 * V_8 ,
struct V_16 * V_17 ,
struct V_18 * V_19 )
{
F_3 ( V_8 , & V_8 -> V_20 [ V_21 ] ,
V_19 -> V_22 . V_23 , V_19 -> V_24 . V_25 ) ;
V_17 -> V_26 = 1 ;
F_4 ( V_8 , 0x01 ) ;
F_5 ( V_27 , 0x000022 ) ;
F_5 ( V_28 , ( 1 << 5 ) ) ;
F_5 ( V_29 , 0x00000022 ) ;
return 0 ;
}
static int F_6 ( struct V_7 * V_8 ,
struct V_16 * V_17 )
{
struct V_18 * V_19 ;
struct V_30 * V_31 ;
if ( F_7 ( & V_17 -> V_32 ) )
return 0 ;
V_19 = F_8 ( V_17 -> V_32 . V_33 , struct V_18 , V_22 . V_34 ) ;
F_9 ( 2 , L_1 ,
V_19 , V_19 -> V_22 . V_35 ) ;
F_2 ( V_8 , V_17 , V_19 ) ;
F_10 (item, &q->active) {
V_19 = F_8 ( V_31 , struct V_18 , V_22 . V_34 ) ;
V_19 -> V_26 = V_17 -> V_26 ++ ;
}
F_11 ( & V_17 -> V_36 , V_37 + V_38 ) ;
return 0 ;
}
void F_12 ( unsigned long V_39 )
{
struct V_7 * V_8 = (struct V_7 * ) V_39 ;
struct V_16 * V_17 = & V_8 -> V_40 ;
struct V_18 * V_19 ;
unsigned long V_41 ;
F_13 ( V_8 , & V_8 -> V_20 [ V_21 ] ) ;
F_14 ( V_29 , 0x22 ) ;
F_15 ( & V_8 -> V_42 , V_41 ) ;
while ( ! F_7 ( & V_17 -> V_32 ) ) {
V_19 = F_8 ( V_17 -> V_32 . V_33 , struct V_18 ,
V_22 . V_34 ) ;
F_16 ( & V_19 -> V_22 . V_34 ) ;
V_19 -> V_22 . V_43 = V_44 ;
F_17 ( & V_19 -> V_22 . V_45 ) ;
F_18 ( L_2 , V_8 -> V_46 ,
V_19 , V_19 -> V_22 . V_35 , ( unsigned long ) V_19 -> V_24 . V_25 ) ;
}
F_6 ( V_8 , V_17 ) ;
F_19 ( & V_8 -> V_42 , V_41 ) ;
}
static int
F_20 ( struct V_47 * V_17 , unsigned int * V_26 , unsigned int * V_48 )
{
* V_48 = V_49 * V_50 * 2 ;
if ( 0 == * V_26 )
* V_26 = V_51 ;
if ( * V_26 < 2 )
* V_26 = 2 ;
if ( * V_26 > 32 )
* V_26 = 32 ;
return 0 ;
}
static int
F_21 ( struct V_47 * V_17 , struct V_52 * V_22 ,
enum V_53 V_54 )
{
struct V_5 * V_6 = V_17 -> V_55 ;
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_18 * V_19 = F_22 ( V_22 ,
struct V_18 , V_22 ) ;
struct V_56 * V_25 = F_23 ( & V_19 -> V_22 ) ;
unsigned int V_48 ;
int V_57 ;
V_48 = V_49 * V_50 * 2 ;
if ( 0 != V_19 -> V_22 . V_58 && V_19 -> V_22 . V_59 < V_48 )
return - V_60 ;
if ( V_61 == V_19 -> V_22 . V_43 ) {
V_19 -> V_22 . V_23 = V_50 ;
V_19 -> V_22 . V_62 = V_49 ;
V_19 -> V_22 . V_48 = V_48 ;
V_19 -> V_22 . V_54 = V_63 ;
V_57 = F_24 ( V_17 , & V_19 -> V_22 , NULL ) ;
if ( 0 != V_57 )
goto V_64;
F_25 ( V_8 -> V_65 , & V_19 -> V_24 ,
V_25 -> V_66 ,
0 , V_19 -> V_22 . V_23 * V_19 -> V_22 . V_62 ,
V_19 -> V_22 . V_23 , 0 ,
V_19 -> V_22 . V_62 ) ;
}
V_19 -> V_22 . V_43 = V_67 ;
return 0 ;
V_64:
F_26 ( V_17 , V_19 ) ;
return V_57 ;
}
static void
F_27 ( struct V_47 * V_68 , struct V_52 * V_22 )
{
struct V_18 * V_19 =
F_22 ( V_22 , struct V_18 , V_22 ) ;
struct V_18 * V_69 ;
struct V_5 * V_6 = V_68 -> V_55 ;
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_16 * V_17 = & V_8 -> V_40 ;
V_19 -> V_24 . V_70 [ 0 ] = F_28 ( V_71 | V_72 | V_73 ) ;
V_19 -> V_24 . V_70 [ 1 ] = F_28 ( V_17 -> V_74 . V_25 ) ;
V_19 -> V_24 . V_70 [ 2 ] = F_28 ( 0 ) ;
if ( F_7 ( & V_17 -> V_32 ) ) {
F_29 ( & V_19 -> V_22 . V_34 , & V_17 -> V_32 ) ;
F_2 ( V_8 , V_17 , V_19 ) ;
V_19 -> V_22 . V_43 = V_75 ;
V_19 -> V_26 = V_17 -> V_26 ++ ;
F_11 ( & V_17 -> V_36 , V_37 + V_38 ) ;
F_9 ( 2 , L_3 ,
V_19 , V_19 -> V_22 . V_35 ) ;
} else {
V_69 = F_8 ( V_17 -> V_32 . V_69 , struct V_18 ,
V_22 . V_34 ) ;
F_29 ( & V_19 -> V_22 . V_34 , & V_17 -> V_32 ) ;
V_19 -> V_22 . V_43 = V_75 ;
V_19 -> V_26 = V_17 -> V_26 ++ ;
V_69 -> V_24 . V_70 [ 1 ] = F_28 ( V_19 -> V_24 . V_25 ) ;
V_69 -> V_24 . V_70 [ 2 ] = F_28 ( 0 ) ;
F_9 ( 2 , L_4 ,
V_19 , V_19 -> V_22 . V_35 ) ;
}
}
static void F_30 ( struct V_47 * V_17 , struct V_52 * V_22 )
{
struct V_18 * V_19 =
F_22 ( V_22 , struct V_18 , V_22 ) ;
F_26 ( V_17 , V_19 ) ;
}
