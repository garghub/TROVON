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
F_2 ( F_15 ( V_5 ) , V_2 -> V_14 & 0xff ) ;
F_2 ( F_16 ( V_5 ) , V_2 -> V_14 >> 8 ) ;
F_2 ( F_17 ( V_5 ) , V_2 -> V_15 & 0xff ) ;
F_2 ( F_18 ( V_5 ) , V_2 -> V_15 >> 8 ) ;
F_19 ( F_20 ( V_5 ) , 0xc0 , 0x00 ) ;
}
static int F_21 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_3 * V_16 )
{
struct V_17 * V_18 = V_4 -> V_19 . V_20 . V_21 -> V_22 ;
unsigned long V_23 , V_24 ;
F_22 ( L_1 , V_4 ) ;
V_4 -> V_25 = 0 ;
F_1 ( V_2 , V_4 , V_26 ) ;
F_1 ( V_2 , V_4 , V_27 ) ;
F_2 ( V_28 , 0x06 ) ;
F_2 ( V_29 , 0x06 ) ;
V_24 = F_23 ( V_4 ) ;
V_23 = V_30 |
V_31 |
( V_18 -> V_32 . V_33 >> 12 ) ;
F_24 ( F_25 ( 2 ) , V_24 ) ;
F_24 ( F_26 ( 2 ) , V_24 + V_2 -> V_14 * V_2 -> V_15 ) ;
F_24 ( F_27 ( 2 ) , V_2 -> V_14 ) ;
F_24 ( F_28 ( 2 ) , V_23 ) ;
F_24 ( F_25 ( 3 ) , V_24 ) ;
F_24 ( F_26 ( 3 ) , V_24 + V_2 -> V_14 * V_2 -> V_15 ) ;
F_24 ( F_27 ( 3 ) , V_2 -> V_14 ) ;
F_24 ( F_28 ( 3 ) , V_23 ) ;
F_29 ( V_2 ) ;
F_30 ( & V_18 -> V_34 , V_35 + V_36 ) ;
return 0 ;
}
static int F_31 ( struct V_37 * V_19 )
{
struct V_17 * V_18 = V_19 -> V_21 -> V_22 ;
struct V_1 * V_2 = V_18 -> V_2 ;
struct V_38 * V_39 = F_32 ( V_19 ) ;
struct V_3 * V_4 = F_33 ( V_39 , struct V_3 , V_19 ) ;
struct V_40 * V_33 = F_34 ( V_19 , 0 ) ;
unsigned int V_41 ;
if ( V_33 -> V_42 -> V_43 ) {
F_35 ( L_2 ) ;
return - V_44 ;
}
V_41 = V_2 -> V_14 * V_2 -> V_15 * 2 ;
if ( F_36 ( V_19 , 0 ) < V_41 )
return - V_44 ;
F_37 ( V_19 , 0 , V_41 ) ;
return F_38 ( V_2 -> V_45 , & V_18 -> V_32 , V_33 -> V_42 , V_33 -> V_46 ,
F_39 ( V_4 ) ) ;
}
static int F_40 ( struct V_21 * V_47 ,
unsigned int * V_48 , unsigned int * V_49 ,
unsigned int V_50 [] , void * V_51 [] )
{
struct V_17 * V_18 = V_47 -> V_22 ;
struct V_1 * V_2 = V_18 -> V_2 ;
unsigned int V_41 ;
V_2 -> V_15 = V_2 -> V_8 -> V_12 - V_2 -> V_8 -> V_11 + 1 ;
if ( V_2 -> V_15 > V_52 )
V_2 -> V_15 = V_52 ;
V_2 -> V_14 = V_53 ;
V_41 = V_2 -> V_14 * V_2 -> V_15 * 2 ;
* V_48 = F_41 ( V_41 , * V_48 ) ;
* V_49 = 1 ;
V_50 [ 0 ] = V_41 ;
V_51 [ 0 ] = V_2 -> V_54 ;
return 0 ;
}
static int F_42 ( struct V_37 * V_19 )
{
struct V_17 * V_18 = V_19 -> V_21 -> V_22 ;
struct V_38 * V_39 = F_32 ( V_19 ) ;
struct V_3 * V_4 = F_33 ( V_39 , struct V_3 , V_19 ) ;
V_18 -> V_55 = NULL ;
V_4 -> V_56 = F_21 ;
return 0 ;
}
int F_43 ( struct V_1 * V_2 )
{
F_44 ( & V_2 -> V_57 . V_58 ) ;
F_45 ( & V_2 -> V_57 . V_34 ) ;
V_2 -> V_57 . V_34 . V_59 = V_60 ;
V_2 -> V_57 . V_34 . V_61 = ( unsigned long ) ( & V_2 -> V_57 ) ;
V_2 -> V_57 . V_2 = V_2 ;
if ( V_62 < 2 )
V_62 = 2 ;
if ( V_62 > V_63 )
V_62 = V_63 ;
return 0 ;
}
int F_46 ( struct V_1 * V_2 )
{
return 0 ;
}
void F_47 ( struct V_1 * V_2 , unsigned long V_64 )
{
F_48 ( & V_2 -> V_65 ) ;
if ( V_2 -> V_57 . V_55 ) {
if ( ( V_64 & 0x10 ) == 0x00 ) {
V_2 -> V_57 . V_55 -> V_25 = 1 ;
goto V_66;
}
if ( ! V_2 -> V_57 . V_55 -> V_25 )
goto V_66;
F_49 ( V_2 , & V_2 -> V_57 , V_67 ) ;
}
F_50 ( V_2 , & V_2 -> V_57 ) ;
V_66:
F_51 ( & V_2 -> V_65 ) ;
}
