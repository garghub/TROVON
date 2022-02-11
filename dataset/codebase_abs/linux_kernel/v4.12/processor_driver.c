static void F_1 ( T_1 V_1 , T_2 V_2 , void * V_3 )
{
struct V_4 * V_5 = V_3 ;
struct V_6 * V_7 ;
int V_8 ;
if ( V_5 -> V_1 != V_1 )
return;
V_7 = F_2 ( V_5 ) ;
if ( ! V_7 )
return;
switch ( V_2 ) {
case V_9 :
V_8 = V_7 -> V_10 ;
F_3 ( V_7 , 1 ) ;
if ( V_8 == V_7 -> V_10 )
break;
F_4 ( V_5 -> V_11 . V_12 ,
F_5 ( & V_5 -> V_13 ) , V_2 ,
V_7 -> V_10 ) ;
break;
case V_14 :
F_6 ( V_7 ) ;
F_4 ( V_5 -> V_11 . V_12 ,
F_5 ( & V_5 -> V_13 ) , V_2 , 0 ) ;
break;
case V_15 :
F_7 ( V_7 ) ;
F_4 ( V_5 -> V_11 . V_12 ,
F_5 ( & V_5 -> V_13 ) , V_2 , 0 ) ;
break;
default:
F_8 ( ( V_16 ,
L_1 , V_2 ) ) ;
break;
}
return;
}
static int F_9 ( unsigned int V_17 )
{
struct V_6 * V_7 = F_10 ( V_18 , V_17 ) ;
struct V_4 * V_5 ;
if ( ! V_7 || F_11 ( V_7 -> V_1 , & V_5 ) )
return 0 ;
if ( V_7 -> V_19 . V_20 ) {
int V_21 ;
F_12 ( L_2 ,
V_7 -> V_22 ) ;
V_7 -> V_19 . V_20 = 0 ;
V_21 = F_13 ( V_5 ) ;
F_14 ( V_21 , L_3 , V_7 -> V_22 ) ;
} else {
F_3 ( V_7 , 0 ) ;
F_15 ( V_7 ) ;
F_16 ( V_7 , false ) ;
F_7 ( V_7 ) ;
}
return 0 ;
}
static int F_17 ( unsigned int V_17 )
{
struct V_6 * V_7 = F_10 ( V_18 , V_17 ) ;
struct V_4 * V_5 ;
if ( ! V_7 || F_11 ( V_7 -> V_1 , & V_5 ) )
return 0 ;
F_16 ( V_7 , true ) ;
return 0 ;
}
static int F_18 ( struct V_6 * V_7 ,
struct V_4 * V_5 )
{
int V_23 = 0 ;
F_3 ( V_7 , 0 ) ;
F_19 ( V_7 ) ;
if ( V_7 -> V_19 . V_24 )
V_7 -> V_19 . V_25 = 1 ;
V_7 -> V_26 = F_20 ( L_4 , V_5 ,
& V_27 ) ;
if ( F_21 ( V_7 -> V_26 ) ) {
V_23 = F_22 ( V_7 -> V_26 ) ;
return V_23 ;
}
F_23 ( & V_5 -> V_13 , L_5 ,
V_7 -> V_26 -> V_22 ) ;
V_23 = F_24 ( & V_5 -> V_13 . V_28 ,
& V_7 -> V_26 -> V_5 . V_28 ,
L_6 ) ;
if ( V_23 ) {
F_25 ( & V_5 -> V_13 ,
L_7 ) ;
goto V_29;
}
V_23 = F_24 ( & V_7 -> V_26 -> V_5 . V_28 ,
& V_5 -> V_13 . V_28 ,
L_8 ) ;
if ( V_23 ) {
F_25 ( & V_7 -> V_26 -> V_5 ,
L_9 ) ;
goto V_30;
}
return 0 ;
V_30:
F_26 ( & V_5 -> V_13 . V_28 , L_6 ) ;
V_29:
F_27 ( V_7 -> V_26 ) ;
return V_23 ;
}
static void F_28 ( struct V_6 * V_7 ,
struct V_4 * V_5 )
{
if ( V_7 -> V_26 ) {
F_26 ( & V_5 -> V_13 . V_28 , L_6 ) ;
F_26 ( & V_7 -> V_26 -> V_5 . V_28 , L_8 ) ;
F_27 ( V_7 -> V_26 ) ;
V_7 -> V_26 = NULL ;
}
}
static inline int F_18 ( struct V_6 * V_7 ,
struct V_4 * V_5 )
{
return 0 ;
}
static inline void F_28 ( struct V_6 * V_7 ,
struct V_4 * V_5 ) {}
static int F_13 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = F_2 ( V_5 ) ;
T_3 V_31 ;
int V_23 = 0 ;
if ( ! V_7 )
return - V_32 ;
if ( V_7 -> V_19 . V_20 )
return 0 ;
V_23 = F_29 ( V_7 ) ;
if ( V_23 && ! F_30 ( V_33 ) )
F_31 ( & V_5 -> V_13 , L_10 ) ;
if ( ! F_32 () || F_32 () == & V_34 )
F_33 ( V_7 ) ;
V_23 = F_18 ( V_7 , V_5 ) ;
if ( V_23 )
goto V_35;
V_31 = F_34 ( V_5 -> V_1 , V_36 ,
F_1 , V_5 ) ;
if ( F_35 ( V_31 ) )
return 0 ;
V_23 = - V_32 ;
F_28 ( V_7 , V_5 ) ;
V_35:
F_36 ( V_7 ) ;
return V_23 ;
}
static int F_37 ( struct V_5 * V_13 )
{
struct V_4 * V_5 = F_38 ( V_13 ) ;
int V_21 ;
if ( ! V_5 )
return - V_32 ;
F_39 () ;
V_21 = F_13 ( V_5 ) ;
F_40 () ;
return V_21 ;
}
static int F_41 ( struct V_5 * V_13 )
{
struct V_4 * V_5 = F_38 ( V_13 ) ;
struct V_6 * V_7 ;
if ( ! V_5 )
return 0 ;
F_42 ( V_5 -> V_1 , V_36 ,
F_1 ) ;
V_7 = F_2 ( V_5 ) ;
if ( ! V_7 )
return 0 ;
F_36 ( V_7 ) ;
F_28 ( V_7 , V_5 ) ;
F_43 ( V_7 ) ;
return 0 ;
}
static int T_4 F_44 ( void )
{
int V_23 = 0 ;
if ( V_37 )
return 0 ;
V_23 = F_45 ( & V_38 ) ;
if ( V_23 < 0 )
return V_23 ;
V_23 = F_46 ( V_39 ,
L_11 ,
F_9 , NULL ) ;
if ( V_23 < 0 )
goto V_40;
V_41 = V_23 ;
F_46 ( V_42 , L_12 ,
NULL , F_17 ) ;
F_47 () ;
F_48 () ;
F_49 () ;
return 0 ;
V_40:
F_50 ( & V_38 ) ;
return V_23 ;
}
static void T_5 F_51 ( void )
{
if ( V_37 )
return;
F_52 () ;
F_53 () ;
F_54 ( V_41 ) ;
F_54 ( V_42 ) ;
F_50 ( & V_38 ) ;
}
