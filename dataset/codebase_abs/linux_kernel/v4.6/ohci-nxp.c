static void F_1 ( void )
{
F_2 ( V_1 ,
( V_2 | V_3 ) ,
V_4 ) ;
F_2 ( V_1 ,
( V_2 | V_3 ) ,
~ V_5 ) ;
F_2 ( V_1 ,
V_2 , V_5 ) ;
F_2 ( V_1 ,
( V_6 | V_3 ) ,
~ 0 ) ;
F_2 ( V_1 ,
V_6 ,
( V_7 | V_8 | V_9 ) ) ;
F_2 ( V_1 ,
( V_10 | V_3 ) , ~ 0 ) ;
F_2 ( V_1 ,
V_2 , V_11 ) ;
F_2 ( V_1 ,
V_10 ,
( V_12 | V_13 ) ) ;
F_2 ( V_1 ,
( V_10 | V_3 ) ,
( V_14 | V_15 ) ) ;
F_2 ( V_1 ,
V_16 | V_3 , ~ 0 ) ;
F_2 ( V_1 ,
V_17 | V_3 ,
~ 0 ) ;
F_2 ( V_1 ,
V_18 | V_3 , ~ 0 ) ;
F_3 ( V_19 L_1 ,
F_4 ( V_1 , 0x00 ) ) ;
F_3 ( V_19 L_2 ,
F_4 ( V_1 , 0x02 ) ) ;
F_3 ( V_19 L_3 ,
F_4 ( V_1 , 0x14 ) ) ;
}
static void F_5 ( void )
{
F_1 () ;
}
static inline void F_6 ( void )
{
F_2 ( V_1 , V_10 ,
V_20 ) ;
}
static inline void F_7 ( void )
{
F_2 ( V_1 ,
V_10 | V_3 ,
V_20 ) ;
}
static void F_8 ( void )
{
unsigned long V_21 = F_9 ( V_22 ) | V_23 ;
F_10 ( V_21 , V_22 ) ;
F_6 () ;
}
static void F_11 ( void )
{
unsigned long V_21 ;
F_7 () ;
V_21 = F_9 ( V_22 ) & ~ V_23 ;
F_10 ( V_21 , V_22 ) ;
}
static int F_12 ( struct V_24 * V_25 )
{
struct V_26 * V_27 = 0 ;
const struct V_28 * V_29 = & V_30 ;
struct V_31 * V_32 ;
int V_33 = 0 , V_34 ;
struct V_35 * V_36 ;
if ( V_25 -> V_37 . V_38 ) {
V_36 = F_13 ( V_25 -> V_37 . V_38 ,
L_4 , 0 ) ;
} else {
V_36 = NULL ;
}
V_1 = F_14 ( V_36 ) ;
if ( ! V_1 ) {
return - V_39 ;
}
V_33 = F_15 ( & V_25 -> V_37 , F_16 ( 32 ) ) ;
if ( V_33 )
goto V_40;
F_17 ( & V_25 -> V_37 , L_5 V_41 L_6 , V_42 ) ;
if ( F_18 () ) {
F_19 ( & V_25 -> V_37 , L_7 ) ;
V_33 = - V_43 ;
goto V_40;
}
V_44 = F_20 ( & V_25 -> V_37 , NULL ) ;
if ( F_21 ( V_44 ) ) {
F_19 ( & V_25 -> V_37 , L_8 ) ;
V_33 = F_22 ( V_44 ) ;
goto V_40;
}
V_33 = F_23 ( V_44 ) ;
if ( V_33 < 0 ) {
F_19 ( & V_25 -> V_37 , L_9 ) ;
goto V_40;
}
F_5 () ;
V_27 = F_24 ( V_29 , & V_25 -> V_37 , F_25 ( & V_25 -> V_37 ) ) ;
if ( ! V_27 ) {
F_19 ( & V_25 -> V_37 , L_10 ) ;
V_33 = - V_45 ;
goto V_46;
}
V_32 = F_26 ( V_25 , V_47 , 0 ) ;
V_27 -> V_48 = F_27 ( & V_25 -> V_37 , V_32 ) ;
if ( F_21 ( V_27 -> V_48 ) ) {
V_33 = F_22 ( V_27 -> V_48 ) ;
goto V_49;
}
V_27 -> V_50 = V_32 -> V_51 ;
V_27 -> V_52 = F_28 ( V_32 ) ;
V_34 = F_29 ( V_25 , 0 ) ;
if ( V_34 < 0 ) {
V_33 = - V_53 ;
goto V_49;
}
F_8 () ;
F_30 ( V_25 , V_27 ) ;
F_31 ( & V_25 -> V_37 , L_11 , V_27 -> V_48 , V_27 -> V_34 ) ;
V_33 = F_32 ( V_27 , V_34 , 0 ) ;
if ( V_33 == 0 ) {
F_33 ( V_27 -> V_54 . V_55 ) ;
return V_33 ;
}
F_11 () ;
V_49:
F_34 ( V_27 ) ;
V_46:
F_35 ( V_44 ) ;
V_40:
V_1 = NULL ;
return V_33 ;
}
static int F_36 ( struct V_24 * V_25 )
{
struct V_26 * V_27 = F_37 ( V_25 ) ;
F_38 ( V_27 ) ;
F_11 () ;
F_34 ( V_27 ) ;
F_35 ( V_44 ) ;
V_1 = NULL ;
return 0 ;
}
static int T_1 F_39 ( void )
{
if ( F_18 () )
return - V_43 ;
F_40 ( L_5 V_41 L_12 , V_42 ) ;
F_41 ( & V_30 , NULL ) ;
return F_42 ( & V_56 ) ;
}
static void T_2 F_43 ( void )
{
F_44 ( & V_56 ) ;
}
