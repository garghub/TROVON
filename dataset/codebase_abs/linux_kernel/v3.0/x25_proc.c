static void * F_1 ( struct V_1 * V_2 , T_1 * V_3 )
__acquires( T_2 )
{
F_2 ( & T_2 ) ;
return F_3 ( & V_4 , * V_3 ) ;
}
static void * F_4 ( struct V_1 * V_2 , void * V_5 , T_1 * V_3 )
{
return F_5 ( V_5 , & V_4 , V_3 ) ;
}
static void F_6 ( struct V_1 * V_2 , void * V_5 )
__releases( T_2 )
{
F_7 ( & T_2 ) ;
}
static int F_8 ( struct V_1 * V_2 , void * V_5 )
{
struct V_6 * V_7 = F_9 ( V_5 , struct V_6 , V_8 ) ;
if ( V_5 == & V_4 ) {
F_10 ( V_2 , L_1 ) ;
goto V_9;
}
V_7 = V_5 ;
F_11 ( V_2 , L_2 ,
V_7 -> V_10 . V_11 , V_7 -> V_12 ,
V_7 -> V_13 ? V_7 -> V_13 -> V_14 : L_3 ) ;
V_9:
return 0 ;
}
static void * F_12 ( struct V_1 * V_2 , T_1 * V_3 )
__acquires( T_3 )
{
F_2 ( & T_3 ) ;
return F_13 ( & V_15 , * V_3 ) ;
}
static void * F_14 ( struct V_1 * V_2 , void * V_5 , T_1 * V_3 )
{
return F_15 ( V_5 , & V_15 , V_3 ) ;
}
static void F_16 ( struct V_1 * V_2 , void * V_5 )
__releases( T_3 )
{
F_7 ( & T_3 ) ;
}
static int F_17 ( struct V_1 * V_2 , void * V_5 )
{
struct V_16 * V_17 ;
struct V_18 * V_19 ;
struct V_20 * V_13 ;
const char * V_21 ;
if ( V_5 == V_22 ) {
F_11 ( V_2 , L_4
L_5 ) ;
goto V_9;
}
V_17 = F_18 ( V_5 ) ;
V_19 = F_19 ( V_17 ) ;
if ( ! V_19 -> V_23 || ( V_13 = V_19 -> V_23 -> V_13 ) == NULL )
V_21 = L_3 ;
else
V_21 = V_19 -> V_23 -> V_13 -> V_14 ;
F_11 ( V_2 , L_6
L_7 ,
! V_19 -> V_24 . V_11 [ 0 ] ? L_8 : V_19 -> V_24 . V_11 ,
! V_19 -> V_25 . V_11 [ 0 ] ? L_8 : V_19 -> V_25 . V_11 ,
V_21 , V_19 -> V_26 & 0x0FFF , V_19 -> V_27 , V_19 -> V_28 , V_19 -> V_29 ,
V_19 -> V_30 , F_20 ( V_17 ) / V_31 , V_19 -> V_32 / V_31 ,
V_19 -> V_33 / V_31 , V_19 -> V_34 / V_31 , V_19 -> V_35 / V_31 ,
F_21 ( V_17 ) ,
F_22 ( V_17 ) ,
V_17 -> V_36 ? F_23 ( V_17 -> V_36 ) -> V_37 : 0L ) ;
V_9:
return 0 ;
}
static void * F_24 ( struct V_1 * V_2 , T_1 * V_3 )
__acquires( T_4 )
{
F_2 ( & T_4 ) ;
return F_3 ( & V_38 , * V_3 ) ;
}
static void * F_25 ( struct V_1 * V_2 , void * V_5 , T_1 * V_3 )
{
return F_5 ( V_5 , & V_38 , V_3 ) ;
}
static void F_26 ( struct V_1 * V_2 , void * V_5 )
__releases( T_4 )
{
F_7 ( & T_4 ) ;
}
static int F_27 ( struct V_1 * V_2 , void * V_5 )
{
struct V_39 * V_40 = F_9 ( V_5 , struct V_39 , V_8 ) ;
if ( V_5 == & V_38 ) {
F_11 ( V_2 , L_9 ) ;
goto V_9;
}
V_40 = V_5 ;
F_11 ( V_2 , L_10 ,
V_40 -> V_26 , V_40 -> V_41 -> V_14 , V_40 -> V_42 -> V_14 ) ;
V_9:
return 0 ;
}
static int F_28 ( struct V_43 * V_43 , struct V_44 * V_44 )
{
return F_29 ( V_44 , & V_45 ) ;
}
static int F_30 ( struct V_43 * V_43 , struct V_44 * V_44 )
{
return F_29 ( V_44 , & V_46 ) ;
}
static int F_31 ( struct V_43 * V_43 , struct V_44 * V_44 )
{
return F_29 ( V_44 , & V_47 ) ;
}
int T_5 F_32 ( void )
{
struct V_48 * V_49 ;
int V_50 = - V_51 ;
V_52 = F_33 ( L_11 , V_53 . V_54 ) ;
if ( ! V_52 )
goto V_9;
V_49 = F_34 ( L_12 , V_55 , V_52 , & V_56 ) ;
if ( ! V_49 )
goto V_57;
V_49 = F_34 ( L_13 , V_55 , V_52 , & V_58 ) ;
if ( ! V_49 )
goto V_59;
V_49 = F_34 ( L_14 , V_55 , V_52 ,
& V_60 ) ;
if ( ! V_49 )
goto V_61;
V_50 = 0 ;
V_9:
return V_50 ;
V_61:
F_35 ( L_13 , V_52 ) ;
V_59:
F_35 ( L_12 , V_52 ) ;
V_57:
F_35 ( L_11 , V_53 . V_54 ) ;
goto V_9;
}
void T_6 F_36 ( void )
{
F_35 ( L_14 , V_52 ) ;
F_35 ( L_12 , V_52 ) ;
F_35 ( L_13 , V_52 ) ;
F_35 ( L_11 , V_53 . V_54 ) ;
}
int T_5 F_32 ( void )
{
return 0 ;
}
void T_6 F_36 ( void )
{
}
