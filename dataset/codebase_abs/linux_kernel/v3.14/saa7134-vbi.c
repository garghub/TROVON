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
struct V_1 * V_2 = V_37 -> V_41 ;
struct V_3 * V_4 = F_32 ( V_14 , struct V_3 , V_14 ) ;
struct V_6 * V_7 = V_2 -> V_8 ;
unsigned int V_42 , V_43 , V_31 ;
int V_44 ;
V_42 = V_7 -> V_12 - V_7 -> V_11 + 1 ;
if ( V_42 > V_45 )
V_42 = V_45 ;
V_43 = V_46 ;
V_31 = V_42 * V_43 * 2 ;
if ( 0 != V_4 -> V_14 . V_47 && V_4 -> V_14 . V_48 < V_31 )
return - V_49 ;
if ( V_4 -> V_14 . V_31 != V_31 )
F_33 ( V_37 , V_4 ) ;
if ( V_50 == V_4 -> V_14 . V_20 ) {
struct V_51 * V_30 = F_34 ( & V_4 -> V_14 ) ;
V_4 -> V_14 . V_15 = V_43 ;
V_4 -> V_14 . V_16 = V_42 ;
V_4 -> V_14 . V_31 = V_31 ;
V_4 -> V_29 = & V_2 -> V_52 ;
V_44 = F_35 ( V_37 , & V_4 -> V_14 , NULL ) ;
if ( V_44 )
goto V_53;
V_44 = F_36 ( V_2 -> V_54 , V_4 -> V_29 ,
V_30 -> V_55 ,
V_30 -> V_56 ,
F_37 ( V_4 ) ) ;
if ( V_44 )
goto V_53;
}
V_4 -> V_14 . V_20 = V_57 ;
V_4 -> V_58 = F_21 ;
V_4 -> V_14 . V_40 = V_40 ;
return 0 ;
V_53:
F_33 ( V_37 , V_4 ) ;
return V_44 ;
}
static int
F_38 ( struct V_36 * V_37 , unsigned int * V_59 , unsigned int * V_31 )
{
struct V_1 * V_2 = V_37 -> V_41 ;
int V_43 , V_42 ;
V_42 = V_2 -> V_8 -> V_12 - V_2 -> V_8 -> V_11 + 1 ;
V_43 = V_46 ;
* V_31 = V_42 * V_43 * 2 ;
if ( 0 == * V_59 )
* V_59 = V_60 ;
* V_59 = F_39 ( * V_31 , * V_59 ) ;
return 0 ;
}
static void F_40 ( struct V_36 * V_37 , struct V_38 * V_14 )
{
struct V_1 * V_2 = V_37 -> V_41 ;
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
F_44 ( & V_2 -> V_32 . V_61 ) ;
F_45 ( & V_2 -> V_32 . V_33 ) ;
V_2 -> V_32 . V_33 . V_62 = V_63 ;
V_2 -> V_32 . V_33 . V_64 = ( unsigned long ) ( & V_2 -> V_32 ) ;
V_2 -> V_32 . V_2 = V_2 ;
if ( V_60 < 2 )
V_60 = 2 ;
if ( V_60 > V_65 )
V_60 = V_65 ;
return 0 ;
}
int F_46 ( struct V_1 * V_2 )
{
return 0 ;
}
void F_47 ( struct V_1 * V_2 , unsigned long V_66 )
{
F_48 ( & V_2 -> V_67 ) ;
if ( V_2 -> V_32 . V_68 ) {
V_2 -> V_69 ++ ;
if ( ( V_66 & 0x10 ) == 0x00 ) {
V_2 -> V_32 . V_68 -> V_22 = 1 ;
goto V_70;
}
if ( ! V_2 -> V_32 . V_68 -> V_22 )
goto V_70;
V_2 -> V_32 . V_68 -> V_14 . V_71 = V_2 -> V_69 ;
F_49 ( V_2 , & V_2 -> V_32 , V_72 ) ;
}
F_50 ( V_2 , & V_2 -> V_32 ) ;
V_70:
F_51 ( & V_2 -> V_67 ) ;
}
