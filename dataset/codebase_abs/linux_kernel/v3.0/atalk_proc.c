void * F_1 ( struct V_1 * V_2 , T_1 * V_3 )
__acquires( T_2 )
{
T_1 V_4 = * V_3 ;
F_2 ( & T_2 ) ;
return V_4 ? F_3 ( -- V_4 ) : V_5 ;
}
static void * F_4 ( struct V_1 * V_2 , void * V_6 , T_1 * V_3 )
{
struct V_7 * V_8 ;
++ * V_3 ;
if ( V_6 == V_5 ) {
V_8 = NULL ;
if ( V_9 )
V_8 = V_9 ;
goto V_10;
}
V_8 = V_6 ;
V_8 = V_8 -> V_11 ;
V_10:
return V_8 ;
}
static void F_5 ( struct V_1 * V_2 , void * V_6 )
__releases( T_2 )
{
F_6 ( & T_2 ) ;
}
static int F_7 ( struct V_1 * V_2 , void * V_6 )
{
struct V_7 * V_12 ;
if ( V_6 == V_5 ) {
F_8 ( V_2 , L_1
L_2 ) ;
goto V_10;
}
V_12 = V_6 ;
F_9 ( V_2 , L_3 ,
V_12 -> V_13 -> V_14 , F_10 ( V_12 -> V_15 . V_16 ) ,
V_12 -> V_15 . V_17 , F_10 ( V_12 -> V_18 . V_19 ) ,
F_10 ( V_12 -> V_18 . V_20 ) , V_12 -> V_21 ) ;
V_10:
return 0 ;
}
void * F_11 ( struct V_1 * V_2 , T_1 * V_3 )
__acquires( T_3 )
{
T_1 V_4 = * V_3 ;
F_2 ( & T_3 ) ;
return V_4 ? F_12 ( -- V_4 ) : V_5 ;
}
static void * F_13 ( struct V_1 * V_2 , void * V_6 , T_1 * V_3 )
{
struct V_22 * V_23 ;
++ * V_3 ;
if ( V_6 == V_5 ) {
V_23 = NULL ;
if ( V_24 )
V_23 = V_24 ;
goto V_10;
}
V_23 = V_6 ;
V_23 = V_23 -> V_11 ;
V_10:
return V_23 ;
}
static void F_14 ( struct V_1 * V_2 , void * V_6 )
__releases( T_3 )
{
F_6 ( & T_3 ) ;
}
static int F_15 ( struct V_1 * V_2 , void * V_6 )
{
struct V_22 * V_25 ;
if ( V_6 == V_5 ) {
F_8 ( V_2 , L_4 ) ;
goto V_10;
}
if ( V_26 . V_13 ) {
V_25 = & V_26 ;
F_9 ( V_2 , L_5 ,
F_10 ( V_25 -> V_27 . V_16 ) , V_25 -> V_27 . V_17 ,
V_25 -> V_28 , V_25 -> V_13 -> V_14 ) ;
}
V_25 = V_6 ;
F_9 ( V_2 , L_6 ,
F_10 ( V_25 -> V_29 . V_16 ) , V_25 -> V_29 . V_17 ,
F_10 ( V_25 -> V_27 . V_16 ) , V_25 -> V_27 . V_17 ,
V_25 -> V_28 , V_25 -> V_13 -> V_14 ) ;
V_10:
return 0 ;
}
static void * F_16 ( struct V_1 * V_2 , T_1 * V_3 )
__acquires( T_4 )
{
F_2 ( & T_4 ) ;
return F_17 ( & V_30 , * V_3 ) ;
}
static void * F_18 ( struct V_1 * V_2 , void * V_6 , T_1 * V_3 )
{
return F_19 ( V_6 , & V_30 , V_3 ) ;
}
static void F_20 ( struct V_1 * V_2 , void * V_6 )
__releases( T_4 )
{
F_6 ( & T_4 ) ;
}
static int F_21 ( struct V_1 * V_2 , void * V_6 )
{
struct V_31 * V_32 ;
struct V_33 * V_34 ;
if ( V_6 == V_5 ) {
F_9 ( V_2 , L_7
L_8 ) ;
goto V_10;
}
V_32 = F_22 ( V_6 ) ;
V_34 = F_23 ( V_32 ) ;
F_9 ( V_2 , L_9
L_10 ,
V_32 -> V_35 , F_10 ( V_34 -> V_36 ) , V_34 -> V_37 , V_34 -> V_38 ,
F_10 ( V_34 -> V_39 ) , V_34 -> V_40 , V_34 -> V_41 ,
F_24 ( V_32 ) ,
F_25 ( V_32 ) ,
V_32 -> V_42 , F_26 ( V_32 -> V_43 ) -> V_44 ) ;
V_10:
return 0 ;
}
static int F_27 ( struct V_45 * V_45 , struct V_46 * V_46 )
{
return F_28 ( V_46 , & V_47 ) ;
}
static int F_29 ( struct V_45 * V_45 , struct V_46 * V_46 )
{
return F_28 ( V_46 , & V_48 ) ;
}
static int F_30 ( struct V_45 * V_45 , struct V_46 * V_46 )
{
return F_28 ( V_46 , & V_49 ) ;
}
int T_5 F_31 ( void )
{
struct V_50 * V_51 ;
int V_52 = - V_53 ;
V_54 = F_32 ( L_11 , V_55 . V_56 ) ;
if ( ! V_54 )
goto V_10;
V_51 = F_33 ( L_12 , V_57 , V_54 ,
& V_58 ) ;
if ( ! V_51 )
goto V_59;
V_51 = F_33 ( L_13 , V_57 , V_54 ,
& V_60 ) ;
if ( ! V_51 )
goto V_61;
V_51 = F_33 ( L_14 , V_57 , V_54 ,
& V_62 ) ;
if ( ! V_51 )
goto V_63;
V_51 = F_33 ( L_15 , V_57 , V_54 , & V_64 ) ;
if ( ! V_51 )
goto V_65;
V_52 = 0 ;
V_10:
return V_52 ;
V_65:
F_34 ( L_14 , V_54 ) ;
V_63:
F_34 ( L_13 , V_54 ) ;
V_61:
F_34 ( L_12 , V_54 ) ;
V_59:
F_34 ( L_11 , V_55 . V_56 ) ;
goto V_10;
}
void T_6 F_35 ( void )
{
F_34 ( L_12 , V_54 ) ;
F_34 ( L_13 , V_54 ) ;
F_34 ( L_14 , V_54 ) ;
F_34 ( L_15 , V_54 ) ;
F_34 ( L_11 , V_55 . V_56 ) ;
}
