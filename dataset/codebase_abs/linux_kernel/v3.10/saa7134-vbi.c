static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
int V_5 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
F_2 ( F_3 ( V_5 ) , V_7 -> V_9 & 0xff ) ;
F_2 ( F_4 ( V_5 ) , V_7 -> V_9 >> 8 ) ;
F_2 ( F_5 ( V_5 ) , V_7 -> V_10 & 0xff ) ;
F_2 ( F_6 ( V_5 ) , V_7 -> V_10 >> 8 ) ;
F_2 ( F_7 ( V_5 ) , V_7 -> V_11 & 0xff ) ;
F_2 ( F_8 ( V_5 ) , V_7 -> V_11 >> 8 ) ;
F_2 ( F_9 ( V_5 ) , V_7 -> V_12 & 0xff ) ;
F_2 ( F_10 ( V_5 ) , V_7 -> V_12 >> 8 ) ;
F_2 ( F_11 ( V_5 ) , V_13 & 0xff ) ;
F_2 ( F_12 ( V_5 ) , V_13 >> 8 ) ;
F_2 ( F_13 ( V_5 ) , 0x00 ) ;
F_2 ( F_14 ( V_5 ) , 0x00 ) ;
F_2 ( F_15 ( V_5 ) , V_4 -> V_14 . V_15 & 0xff ) ;
F_2 ( F_16 ( V_5 ) , V_4 -> V_14 . V_15 >> 8 ) ;
F_2 ( F_17 ( V_5 ) , V_4 -> V_14 . V_16 & 0xff ) ;
F_2 ( F_18 ( V_5 ) , V_4 -> V_14 . V_16 >> 8 ) ;
F_19 ( F_20 ( V_5 ) , 0xc0 , 0x00 ) ;
}
static int F_21 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_3 * V_17 )
{
unsigned long V_18 , V_19 ;
F_22 ( L_1 , V_4 ) ;
V_4 -> V_14 . V_20 = V_21 ;
V_4 -> V_22 = 0 ;
F_1 ( V_2 , V_4 , V_23 ) ;
F_1 ( V_2 , V_4 , V_24 ) ;
F_2 ( V_25 , 0x06 ) ;
F_2 ( V_26 , 0x06 ) ;
V_19 = F_23 ( V_4 ) ;
V_18 = V_27 |
V_28 |
( V_4 -> V_29 -> V_30 >> 12 ) ;
F_24 ( F_25 ( 2 ) , V_19 ) ;
F_24 ( F_26 ( 2 ) , V_19 + V_4 -> V_14 . V_31 / 2 ) ;
F_24 ( F_27 ( 2 ) , V_4 -> V_14 . V_15 ) ;
F_24 ( F_28 ( 2 ) , V_18 ) ;
F_24 ( F_25 ( 3 ) , V_19 ) ;
F_24 ( F_26 ( 3 ) , V_19 + V_4 -> V_14 . V_31 / 2 ) ;
F_24 ( F_27 ( 3 ) , V_4 -> V_14 . V_15 ) ;
F_24 ( F_28 ( 3 ) , V_18 ) ;
F_29 ( V_2 ) ;
F_30 ( & V_2 -> V_32 . V_33 , V_34 + V_35 ) ;
return 0 ;
}
static int F_31 ( struct V_36 * V_37 ,
struct V_38 * V_14 ,
enum V_39 V_40 )
{
struct V_41 * V_42 = V_37 -> V_43 ;
struct V_1 * V_2 = V_42 -> V_2 ;
struct V_3 * V_4 = F_32 ( V_14 , struct V_3 , V_14 ) ;
struct V_6 * V_7 = V_2 -> V_8 ;
unsigned int V_44 , V_45 , V_31 ;
int V_46 ;
V_44 = V_7 -> V_12 - V_7 -> V_11 + 1 ;
if ( V_44 > V_47 )
V_44 = V_47 ;
V_45 = V_48 ;
V_31 = V_44 * V_45 * 2 ;
if ( 0 != V_4 -> V_14 . V_49 && V_4 -> V_14 . V_50 < V_31 )
return - V_51 ;
if ( V_4 -> V_14 . V_31 != V_31 )
F_33 ( V_37 , V_4 ) ;
if ( V_52 == V_4 -> V_14 . V_20 ) {
struct V_53 * V_30 = F_34 ( & V_4 -> V_14 ) ;
V_4 -> V_14 . V_15 = V_45 ;
V_4 -> V_14 . V_16 = V_44 ;
V_4 -> V_14 . V_31 = V_31 ;
V_4 -> V_29 = & V_42 -> V_54 ;
V_46 = F_35 ( V_37 , & V_4 -> V_14 , NULL ) ;
if ( V_46 )
goto V_55;
V_46 = F_36 ( V_2 -> V_56 , V_4 -> V_29 ,
V_30 -> V_57 ,
V_30 -> V_58 ,
F_37 ( V_4 ) ) ;
if ( V_46 )
goto V_55;
}
V_4 -> V_14 . V_20 = V_59 ;
V_4 -> V_60 = F_21 ;
V_4 -> V_14 . V_40 = V_40 ;
return 0 ;
V_55:
F_33 ( V_37 , V_4 ) ;
return V_46 ;
}
static int
F_38 ( struct V_36 * V_37 , unsigned int * V_61 , unsigned int * V_31 )
{
struct V_41 * V_42 = V_37 -> V_43 ;
struct V_1 * V_2 = V_42 -> V_2 ;
int V_45 , V_44 ;
V_44 = V_2 -> V_8 -> V_12 - V_2 -> V_8 -> V_11 + 1 ;
V_45 = V_48 ;
* V_31 = V_44 * V_45 * 2 ;
if ( 0 == * V_61 )
* V_61 = V_62 ;
* V_61 = F_39 ( * V_31 , * V_61 ) ;
return 0 ;
}
static void F_40 ( struct V_36 * V_37 , struct V_38 * V_14 )
{
struct V_41 * V_42 = V_37 -> V_43 ;
struct V_1 * V_2 = V_42 -> V_2 ;
struct V_3 * V_4 = F_32 ( V_14 , struct V_3 , V_14 ) ;
F_41 ( V_2 , & V_2 -> V_32 , V_4 ) ;
}
static void F_42 ( struct V_36 * V_37 , struct V_38 * V_14 )
{
struct V_3 * V_4 = F_32 ( V_14 , struct V_3 , V_14 ) ;
F_33 ( V_37 , V_4 ) ;
}
int F_43 ( struct V_1 * V_2 )
{
F_44 ( & V_2 -> V_32 . V_63 ) ;
F_45 ( & V_2 -> V_32 . V_33 ) ;
V_2 -> V_32 . V_33 . V_64 = V_65 ;
V_2 -> V_32 . V_33 . V_66 = ( unsigned long ) ( & V_2 -> V_32 ) ;
V_2 -> V_32 . V_2 = V_2 ;
if ( V_62 < 2 )
V_62 = 2 ;
if ( V_62 > V_67 )
V_62 = V_67 ;
return 0 ;
}
int F_46 ( struct V_1 * V_2 )
{
return 0 ;
}
void F_47 ( struct V_1 * V_2 , unsigned long V_68 )
{
F_48 ( & V_2 -> V_69 ) ;
if ( V_2 -> V_32 . V_70 ) {
V_2 -> V_71 ++ ;
if ( ( V_68 & 0x10 ) == 0x00 ) {
V_2 -> V_32 . V_70 -> V_22 = 1 ;
goto V_72;
}
if ( ! V_2 -> V_32 . V_70 -> V_22 )
goto V_72;
V_2 -> V_32 . V_70 -> V_14 . V_73 = V_2 -> V_71 ;
F_49 ( V_2 , & V_2 -> V_32 , V_74 ) ;
}
F_50 ( V_2 , & V_2 -> V_32 ) ;
V_72:
F_51 ( & V_2 -> V_69 ) ;
}
