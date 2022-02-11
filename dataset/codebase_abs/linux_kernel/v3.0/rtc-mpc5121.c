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
static int F_11 ( struct V_12 * V_13 , struct V_20 * V_21 )
{
struct V_14 * V_15 = F_4 ( V_13 ) ;
struct V_1 T_1 * V_2 = V_15 -> V_2 ;
* V_21 = V_15 -> V_22 ;
V_21 -> V_23 = F_12 ( & V_2 -> V_24 ) ;
return 0 ;
}
static int F_13 ( struct V_12 * V_13 , struct V_20 * V_21 )
{
struct V_14 * V_15 = F_4 ( V_13 ) ;
struct V_1 T_1 * V_2 = V_15 -> V_2 ;
if ( V_21 -> time . V_6 ) {
V_21 -> time . V_6 = 0 ;
V_21 -> time . V_8 ++ ;
if ( V_21 -> time . V_8 >= 60 ) {
V_21 -> time . V_8 = 0 ;
V_21 -> time . V_10 ++ ;
if ( V_21 -> time . V_10 >= 24 )
V_21 -> time . V_10 = 0 ;
}
}
V_21 -> time . V_25 = - 1 ;
V_21 -> time . V_26 = - 1 ;
V_21 -> time . V_27 = - 1 ;
F_2 ( & V_2 -> V_28 , V_21 -> time . V_8 ) ;
F_2 ( & V_2 -> V_29 , V_21 -> time . V_10 ) ;
F_2 ( & V_2 -> V_30 , V_21 -> V_31 ) ;
V_15 -> V_22 = * V_21 ;
return 0 ;
}
static T_2 F_14 ( int V_32 , void * V_13 )
{
struct V_14 * V_15 = F_4 ( (struct V_12 * ) V_13 ) ;
struct V_1 T_1 * V_2 = V_15 -> V_2 ;
if ( F_12 ( & V_2 -> V_33 ) ) {
F_2 ( & V_2 -> V_33 , 1 ) ;
F_2 ( & V_2 -> V_24 , 1 ) ;
F_15 ( V_15 -> V_15 , 1 , V_34 | V_35 ) ;
return V_36 ;
}
return V_37 ;
}
static T_2 F_16 ( int V_32 , void * V_13 )
{
struct V_14 * V_15 = F_4 ( (struct V_12 * ) V_13 ) ;
struct V_1 T_1 * V_2 = V_15 -> V_2 ;
if ( F_12 ( & V_2 -> V_38 ) && ( F_12 ( & V_2 -> V_39 ) & 0x1 ) ) {
F_2 ( & V_2 -> V_38 , 1 ) ;
F_15 ( V_15 -> V_15 , 1 , V_34 | V_40 ) ;
return V_36 ;
}
return V_37 ;
}
static int F_17 ( struct V_12 * V_13 ,
unsigned int V_31 )
{
struct V_14 * V_15 = F_4 ( V_13 ) ;
struct V_1 T_1 * V_2 = V_15 -> V_2 ;
int V_41 ;
if ( V_31 )
V_41 = 1 ;
else
V_41 = 0 ;
F_2 ( & V_2 -> V_30 , V_41 ) ;
V_15 -> V_22 . V_31 = V_41 ;
return 0 ;
}
static int T_3 F_18 ( struct V_42 * V_43 )
{
struct V_14 * V_15 ;
int V_44 = 0 ;
T_4 V_45 ;
V_15 = F_19 ( sizeof( * V_15 ) , V_46 ) ;
if ( ! V_15 )
return - V_47 ;
V_15 -> V_2 = F_20 ( V_43 -> V_13 . V_48 , 0 ) ;
if ( ! V_15 -> V_2 ) {
F_21 ( & V_43 -> V_13 , L_1 , V_49 ) ;
V_44 = - V_50 ;
goto V_51;
}
F_22 ( & V_43 -> V_13 , 1 ) ;
F_23 ( & V_43 -> V_13 , V_15 ) ;
V_15 -> V_32 = F_24 ( V_43 -> V_13 . V_48 , 1 ) ;
V_44 = F_25 ( V_15 -> V_32 , F_14 , V_52 ,
L_2 , & V_43 -> V_13 ) ;
if ( V_44 ) {
F_21 ( & V_43 -> V_13 , L_3 ,
V_49 , V_15 -> V_32 ) ;
goto V_53;
}
V_15 -> V_54 = F_24 ( V_43 -> V_13 . V_48 , 0 ) ;
V_44 = F_25 ( V_15 -> V_54 , F_16 ,
V_52 , L_4 , & V_43 -> V_13 ) ;
if ( V_44 ) {
F_21 ( & V_43 -> V_13 , L_3 ,
V_49 , V_15 -> V_54 ) ;
goto V_55;
}
V_45 = F_5 ( & V_15 -> V_2 -> V_56 ) ;
if ( V_45 & 0x02 ) {
F_26 ( & V_43 -> V_13 ,
L_5 ) ;
F_10 ( & V_15 -> V_2 -> V_56 , V_45 ) ;
}
V_15 -> V_15 = F_27 ( L_2 , & V_43 -> V_13 ,
& V_57 , V_58 ) ;
if ( F_28 ( V_15 -> V_15 ) ) {
V_44 = F_29 ( V_15 -> V_15 ) ;
goto V_59;
}
return 0 ;
V_59:
F_30 ( V_15 -> V_54 , & V_43 -> V_13 ) ;
V_55:
F_31 ( V_15 -> V_54 ) ;
F_30 ( V_15 -> V_32 , & V_43 -> V_13 ) ;
V_53:
F_31 ( V_15 -> V_32 ) ;
F_32 ( V_15 -> V_2 ) ;
V_51:
F_33 ( V_15 ) ;
return V_44 ;
}
static int T_5 F_34 ( struct V_42 * V_43 )
{
struct V_14 * V_15 = F_4 ( & V_43 -> V_13 ) ;
struct V_1 T_1 * V_2 = V_15 -> V_2 ;
F_2 ( & V_2 -> V_30 , 0 ) ;
F_2 ( & V_2 -> V_39 , F_12 ( & V_2 -> V_39 ) & ~ 0x1 ) ;
F_35 ( V_15 -> V_15 ) ;
F_32 ( V_15 -> V_2 ) ;
F_30 ( V_15 -> V_32 , & V_43 -> V_13 ) ;
F_30 ( V_15 -> V_54 , & V_43 -> V_13 ) ;
F_31 ( V_15 -> V_32 ) ;
F_31 ( V_15 -> V_54 ) ;
F_23 ( & V_43 -> V_13 , NULL ) ;
F_33 ( V_15 ) ;
return 0 ;
}
static int T_6 F_36 ( void )
{
return F_37 ( & V_60 ) ;
}
static void T_7 F_38 ( void )
{
F_39 ( & V_60 ) ;
}
