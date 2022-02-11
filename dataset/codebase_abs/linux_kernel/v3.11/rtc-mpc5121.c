static void F_1 ( struct V_1 T_1 * V_2 ,
struct V_3 * V_4 )
{
F_2 ( & V_2 -> V_5 , V_4 -> V_6 ) ;
F_2 ( & V_2 -> V_7 , V_4 -> V_8 ) ;
F_2 ( & V_2 -> V_9 , V_4 -> V_10 ) ;
F_2 ( & V_2 -> V_11 , 0x1 ) ;
F_2 ( & V_2 -> V_11 , 0x3 ) ;
F_2 ( & V_2 -> V_11 , 0x1 ) ;
F_2 ( & V_2 -> V_11 , 0x0 ) ;
}
static int F_3 ( struct V_12 * V_13 , struct V_3 * V_4 )
{
struct V_14 * V_15 = F_4 ( V_13 ) ;
struct V_1 T_1 * V_2 = V_15 -> V_2 ;
unsigned long V_16 ;
V_16 = F_5 ( & V_2 -> V_17 ) + F_5 ( & V_2 -> V_18 ) ;
F_6 ( V_16 , V_4 ) ;
F_1 ( V_2 , V_4 ) ;
return F_7 ( V_4 ) ;
}
static int F_8 ( struct V_12 * V_13 , struct V_3 * V_4 )
{
struct V_14 * V_15 = F_4 ( V_13 ) ;
struct V_1 T_1 * V_2 = V_15 -> V_2 ;
int V_19 ;
unsigned long V_16 ;
V_19 = F_9 ( V_4 , & V_16 ) ;
if ( V_19 == 0 )
F_10 ( & V_2 -> V_18 , V_16 - F_5 ( & V_2 -> V_17 ) ) ;
F_1 ( V_2 , V_4 ) ;
return 0 ;
}
static int F_11 ( struct V_12 * V_13 , struct V_3 * V_4 )
{
struct V_14 * V_15 = F_4 ( V_13 ) ;
struct V_1 T_1 * V_2 = V_15 -> V_2 ;
int V_20 ;
V_4 -> V_6 = F_12 ( & V_2 -> V_21 ) ;
V_4 -> V_8 = F_12 ( & V_2 -> V_22 ) ;
if ( F_12 ( & V_2 -> V_23 ) & 0x20 )
V_4 -> V_10 = ( F_12 ( & V_2 -> V_23 ) >> 1 ) +
( F_12 ( & V_2 -> V_23 ) & 1 ? 12 : 0 ) ;
else
V_4 -> V_10 = F_12 ( & V_2 -> V_23 ) ;
V_20 = F_12 ( & V_2 -> V_24 ) ;
V_4 -> V_25 = V_20 & 0x1f ;
V_4 -> V_26 = F_12 ( & V_2 -> V_27 ) - 1 ;
V_4 -> V_28 = F_13 ( & V_2 -> V_29 ) - 1900 ;
V_4 -> V_30 = ( V_20 >> 5 ) % 7 ;
V_4 -> V_31 = F_14 ( V_4 -> V_25 , V_4 -> V_26 , V_4 -> V_28 ) ;
V_4 -> V_32 = 0 ;
return 0 ;
}
static int F_15 ( struct V_12 * V_13 , struct V_3 * V_4 )
{
struct V_14 * V_15 = F_4 ( V_13 ) ;
struct V_1 T_1 * V_2 = V_15 -> V_2 ;
F_1 ( V_2 , V_4 ) ;
F_2 ( & V_2 -> V_33 , V_4 -> V_26 + 1 ) ;
F_2 ( & V_2 -> V_34 , V_4 -> V_30 ? V_4 -> V_30 : 7 ) ;
F_2 ( & V_2 -> V_35 , V_4 -> V_25 ) ;
F_16 ( & V_2 -> V_36 , V_4 -> V_28 + 1900 ) ;
F_2 ( & V_2 -> V_37 , 0x1 ) ;
F_2 ( & V_2 -> V_37 , 0x3 ) ;
F_2 ( & V_2 -> V_37 , 0x1 ) ;
F_2 ( & V_2 -> V_37 , 0x0 ) ;
return 0 ;
}
static int F_17 ( struct V_12 * V_13 , struct V_38 * V_39 )
{
struct V_14 * V_15 = F_4 ( V_13 ) ;
struct V_1 T_1 * V_2 = V_15 -> V_2 ;
* V_39 = V_15 -> V_40 ;
V_39 -> V_41 = F_12 ( & V_2 -> V_42 ) ;
return 0 ;
}
static int F_18 ( struct V_12 * V_13 , struct V_38 * V_39 )
{
struct V_14 * V_15 = F_4 ( V_13 ) ;
struct V_1 T_1 * V_2 = V_15 -> V_2 ;
if ( V_39 -> time . V_6 ) {
V_39 -> time . V_6 = 0 ;
V_39 -> time . V_8 ++ ;
if ( V_39 -> time . V_8 >= 60 ) {
V_39 -> time . V_8 = 0 ;
V_39 -> time . V_10 ++ ;
if ( V_39 -> time . V_10 >= 24 )
V_39 -> time . V_10 = 0 ;
}
}
V_39 -> time . V_25 = - 1 ;
V_39 -> time . V_26 = - 1 ;
V_39 -> time . V_28 = - 1 ;
F_2 ( & V_2 -> V_43 , V_39 -> time . V_8 ) ;
F_2 ( & V_2 -> V_44 , V_39 -> time . V_10 ) ;
F_2 ( & V_2 -> V_45 , V_39 -> V_46 ) ;
V_15 -> V_40 = * V_39 ;
return 0 ;
}
static T_2 F_19 ( int V_47 , void * V_13 )
{
struct V_14 * V_15 = F_4 ( (struct V_12 * ) V_13 ) ;
struct V_1 T_1 * V_2 = V_15 -> V_2 ;
if ( F_12 ( & V_2 -> V_48 ) ) {
F_2 ( & V_2 -> V_48 , 1 ) ;
F_2 ( & V_2 -> V_42 , 1 ) ;
F_20 ( V_15 -> V_15 , 1 , V_49 | V_50 ) ;
return V_51 ;
}
return V_52 ;
}
static T_2 F_21 ( int V_47 , void * V_13 )
{
struct V_14 * V_15 = F_4 ( (struct V_12 * ) V_13 ) ;
struct V_1 T_1 * V_2 = V_15 -> V_2 ;
if ( F_12 ( & V_2 -> V_53 ) && ( F_12 ( & V_2 -> V_54 ) & 0x1 ) ) {
F_2 ( & V_2 -> V_53 , 1 ) ;
F_20 ( V_15 -> V_15 , 1 , V_49 | V_55 ) ;
return V_51 ;
}
return V_52 ;
}
static int F_22 ( struct V_12 * V_13 ,
unsigned int V_46 )
{
struct V_14 * V_15 = F_4 ( V_13 ) ;
struct V_1 T_1 * V_2 = V_15 -> V_2 ;
int V_56 ;
if ( V_46 )
V_56 = 1 ;
else
V_56 = 0 ;
F_2 ( & V_2 -> V_45 , V_56 ) ;
V_15 -> V_40 . V_46 = V_56 ;
return 0 ;
}
static int F_23 ( struct V_57 * V_58 )
{
struct V_14 * V_15 ;
int V_59 = 0 ;
V_15 = F_24 ( & V_58 -> V_13 , sizeof( * V_15 ) , V_60 ) ;
if ( ! V_15 )
return - V_61 ;
V_15 -> V_2 = F_25 ( V_58 -> V_13 . V_62 , 0 ) ;
if ( ! V_15 -> V_2 ) {
F_26 ( & V_58 -> V_13 , L_1 , V_63 ) ;
return - V_64 ;
}
F_27 ( & V_58 -> V_13 , 1 ) ;
F_28 ( V_58 , V_15 ) ;
V_15 -> V_47 = F_29 ( V_58 -> V_13 . V_62 , 1 ) ;
V_59 = F_30 ( V_15 -> V_47 , F_19 , 0 ,
L_2 , & V_58 -> V_13 ) ;
if ( V_59 ) {
F_26 ( & V_58 -> V_13 , L_3 ,
V_63 , V_15 -> V_47 ) ;
goto V_65;
}
V_15 -> V_66 = F_29 ( V_58 -> V_13 . V_62 , 0 ) ;
V_59 = F_30 ( V_15 -> V_66 , F_21 ,
0 , L_4 , & V_58 -> V_13 ) ;
if ( V_59 ) {
F_26 ( & V_58 -> V_13 , L_3 ,
V_63 , V_15 -> V_66 ) ;
goto V_67;
}
if ( F_31 ( V_58 -> V_13 . V_62 , L_5 ) ) {
T_3 V_68 ;
V_68 = F_5 ( & V_15 -> V_2 -> V_69 ) ;
if ( V_68 & 0x02 ) {
F_32 ( & V_58 -> V_13 ,
L_6 ) ;
F_10 ( & V_15 -> V_2 -> V_69 , V_68 ) ;
}
V_15 -> V_15 = F_33 ( & V_58 -> V_13 , L_2 ,
& V_70 , V_71 ) ;
} else {
V_15 -> V_15 = F_33 ( & V_58 -> V_13 , L_7 ,
& V_72 , V_71 ) ;
}
if ( F_34 ( V_15 -> V_15 ) ) {
V_59 = F_35 ( V_15 -> V_15 ) ;
goto V_73;
}
V_15 -> V_15 -> V_74 = 1 ;
return 0 ;
V_73:
F_36 ( V_15 -> V_66 , & V_58 -> V_13 ) ;
V_67:
F_37 ( V_15 -> V_66 ) ;
F_36 ( V_15 -> V_47 , & V_58 -> V_13 ) ;
V_65:
F_37 ( V_15 -> V_47 ) ;
F_38 ( V_15 -> V_2 ) ;
return V_59 ;
}
static int F_39 ( struct V_57 * V_58 )
{
struct V_14 * V_15 = F_40 ( V_58 ) ;
struct V_1 T_1 * V_2 = V_15 -> V_2 ;
F_2 ( & V_2 -> V_45 , 0 ) ;
F_2 ( & V_2 -> V_54 , F_12 ( & V_2 -> V_54 ) & ~ 0x1 ) ;
F_38 ( V_15 -> V_2 ) ;
F_36 ( V_15 -> V_47 , & V_58 -> V_13 ) ;
F_36 ( V_15 -> V_66 , & V_58 -> V_13 ) ;
F_37 ( V_15 -> V_47 ) ;
F_37 ( V_15 -> V_66 ) ;
return 0 ;
}
