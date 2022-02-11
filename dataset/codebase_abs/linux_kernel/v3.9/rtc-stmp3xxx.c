static void F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( V_3 ) {
F_3 ( V_3 , V_5 -> V_6 + V_7 ) ;
F_3 ( V_8 ,
V_5 -> V_6 + V_9 + V_10 ) ;
F_3 ( V_11 ,
V_5 -> V_6 + V_12 + V_10 ) ;
} else {
F_3 ( V_8 ,
V_5 -> V_6 + V_9 + V_13 ) ;
F_3 ( V_11 ,
V_5 -> V_6 + V_12 + V_13 ) ;
}
}
static void F_4 ( struct V_14 * V_15 )
{
struct V_14 * V_16 =
F_5 ( L_1 , V_15 -> V_17 ) ;
if ( V_16 ) {
V_16 -> V_2 . V_18 = & V_15 -> V_2 ;
V_16 -> V_2 . V_19 = & V_20 ;
F_6 ( V_16 ) ;
}
}
static void F_4 ( struct V_14 * V_15 )
{
}
static void F_7 ( struct V_4 * V_5 )
{
while ( F_8 ( V_5 -> V_6 + V_21 ) &
( 0x80 << V_22 ) )
F_9 () ;
}
static int F_10 ( struct V_1 * V_2 , struct V_23 * V_24 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_7 ( V_5 ) ;
F_11 ( F_8 ( V_5 -> V_6 + V_25 ) , V_24 ) ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 , unsigned long V_26 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_3 ( V_26 , V_5 -> V_6 + V_25 ) ;
F_7 ( V_5 ) ;
return 0 ;
}
static T_2 F_13 ( int V_27 , void * V_28 )
{
struct V_4 * V_5 = F_2 ( V_28 ) ;
T_1 V_29 = F_8 ( V_5 -> V_6 + V_9 ) ;
if ( V_29 & V_30 ) {
F_3 ( V_30 ,
V_5 -> V_6 + V_31 ) ;
F_14 ( V_5 -> V_32 , 1 , V_33 | V_34 ) ;
return V_35 ;
}
return V_36 ;
}
static int F_15 ( struct V_1 * V_2 , unsigned int V_37 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( V_37 ) {
F_3 ( V_38 |
V_39 ,
V_5 -> V_6 + V_40 ) ;
F_3 ( V_41 ,
V_5 -> V_6 + V_42 ) ;
} else {
F_3 ( V_38 |
V_39 ,
V_5 -> V_6 + V_43 ) ;
F_3 ( V_41 ,
V_5 -> V_6 + V_31 ) ;
}
return 0 ;
}
static int F_16 ( struct V_1 * V_2 , struct V_44 * V_45 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_11 ( F_8 ( V_5 -> V_6 + V_46 ) , & V_45 -> time ) ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 , struct V_44 * V_45 )
{
unsigned long V_26 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_18 ( & V_45 -> time , & V_26 ) ;
F_3 ( V_26 , V_5 -> V_6 + V_46 ) ;
F_15 ( V_2 , V_45 -> V_37 ) ;
return 0 ;
}
static int F_19 ( struct V_14 * V_47 )
{
struct V_4 * V_5 = F_20 ( V_47 ) ;
if ( ! V_5 )
return 0 ;
F_3 ( V_41 ,
V_5 -> V_6 + V_31 ) ;
F_21 ( V_5 -> V_48 , & V_47 -> V_2 ) ;
F_22 ( V_5 -> V_32 ) ;
F_23 ( V_47 , NULL ) ;
F_24 ( V_5 -> V_6 ) ;
F_25 ( V_5 ) ;
return 0 ;
}
static int F_26 ( struct V_14 * V_47 )
{
struct V_4 * V_5 ;
struct V_49 * V_50 ;
int V_51 ;
V_5 = F_27 ( sizeof *V_5 , V_52 ) ;
if ( ! V_5 )
return - V_53 ;
V_50 = F_28 ( V_47 , V_54 , 0 ) ;
if ( ! V_50 ) {
F_29 ( & V_47 -> V_2 , L_2 ) ;
V_51 = - V_55 ;
goto V_56;
}
V_5 -> V_6 = F_30 ( V_50 -> V_57 , F_31 ( V_50 ) ) ;
if ( ! V_5 -> V_6 ) {
F_29 ( & V_47 -> V_2 , L_3 ) ;
V_51 = - V_58 ;
goto V_56;
}
V_5 -> V_48 = F_32 ( V_47 , 0 ) ;
if ( ! ( F_8 ( V_21 + V_5 -> V_6 ) &
V_59 ) ) {
F_29 ( & V_47 -> V_2 , L_4 ) ;
V_51 = - V_60 ;
goto V_61;
}
F_23 ( V_47 , V_5 ) ;
F_33 ( V_5 -> V_6 ) ;
F_3 ( V_38 |
V_39 |
V_62 ,
V_5 -> V_6 + V_43 ) ;
F_3 ( V_63 |
V_41 ,
V_5 -> V_6 + V_31 ) ;
V_5 -> V_32 = F_34 ( V_47 -> V_64 , & V_47 -> V_2 ,
& V_65 , V_66 ) ;
if ( F_35 ( V_5 -> V_32 ) ) {
V_51 = F_36 ( V_5 -> V_32 ) ;
goto V_61;
}
V_51 = F_37 ( V_5 -> V_48 , F_13 , 0 ,
L_5 , & V_47 -> V_2 ) ;
if ( V_51 ) {
F_29 ( & V_47 -> V_2 , L_6 ,
V_5 -> V_48 ) ;
goto V_67;
}
F_4 ( V_47 ) ;
return 0 ;
V_67:
F_22 ( V_5 -> V_32 ) ;
V_61:
F_23 ( V_47 , NULL ) ;
F_24 ( V_5 -> V_6 ) ;
V_56:
F_25 ( V_5 ) ;
return V_51 ;
}
static int F_38 ( struct V_14 * V_2 , T_3 V_68 )
{
return 0 ;
}
static int F_39 ( struct V_14 * V_2 )
{
struct V_4 * V_5 = F_20 ( V_2 ) ;
F_33 ( V_5 -> V_6 ) ;
F_3 ( V_38 |
V_39 |
V_62 ,
V_5 -> V_6 + V_43 ) ;
return 0 ;
}
