static void F_1 ( bool V_1 )
{
unsigned V_2 = 0 , V_3 = 0 ;
if ( ! V_1 ) {
V_3 = V_4 | V_5 ;
V_2 = V_6 ;
}
V_7 = V_1 ;
V_3 |= V_8 | V_9 ;
V_2 |= V_10 | V_11 ;
F_2 ( V_2 ) ;
F_3 ( V_3 ) ;
}
static bool F_4 ( struct V_12 * V_13 )
{
return V_13 -> V_14 == V_13 -> V_15 ;
}
static int F_5 ( struct V_16 * V_17 ,
unsigned long V_18 , void * V_19 )
{
struct V_20 * V_21 = V_19 ;
struct V_22 * V_23 = F_6 ( V_21 ) ;
bool V_24 = F_4 ( & V_23 -> V_25 ) ;
bool V_26 = F_4 ( & V_23 -> V_27 ) ;
int V_28 = 0 ;
if ( ! V_7 )
return 0 ;
F_7 ( V_29 L_1 , V_30 ,
V_23 -> V_25 . V_14 , V_23 -> V_25 . V_15 ,
V_23 -> V_27 . V_14 , V_23 -> V_27 . V_15 ) ;
switch ( V_18 ) {
case V_31 :
if ( V_24 & ! V_26 ||
V_32 & ! V_26 ) {
F_8 ( L_2 , V_30 ) ;
V_32 = false ;
F_9 ( V_33 , 1 ) ;
}
break;
case V_34 :
if ( ! V_24 & V_26 ||
! V_32 & V_26 ) {
F_8 ( L_3 ) ;
V_32 = true ;
F_9 ( V_33 , 0 ) ;
}
break;
}
return V_28 ;
}
static int T_1 F_10 ( struct V_35 * V_36 )
{
int V_28 ;
F_11 ( & V_36 -> V_37 , L_4 ) ;
V_28 = F_12 ( V_33 , L_5 ) ;
if ( V_28 ) {
F_13 ( & V_36 -> V_37 , L_6 ) ;
goto V_38;
}
F_14 ( V_33 , 1 ) ;
V_28 = F_15 ( & V_39 ,
V_40 ) ;
if ( V_28 ) {
F_13 ( & V_36 -> V_37 , L_7 ) ;
goto V_41;
}
F_1 ( true ) ;
return 0 ;
V_41:
F_16 ( V_33 ) ;
V_38:
return V_28 ;
}
static int T_2 F_17 ( struct V_35 * V_36 )
{
F_11 ( & V_36 -> V_37 , L_8 ) ;
F_9 ( V_33 , 1 ) ;
F_1 ( false ) ;
F_18 ( & V_39 ,
V_40 ) ;
F_16 ( V_33 ) ;
return 0 ;
}
static int F_19 ( struct V_42 * V_37 )
{
F_9 ( V_33 , 1 ) ;
F_1 ( false ) ;
V_32 = false ;
return 0 ;
}
static int F_20 ( struct V_42 * V_37 )
{
F_1 ( true ) ;
return 0 ;
}
static int T_3 F_21 ( void )
{
return F_22 ( & V_43 ) ;
}
static void T_4 F_23 ( void )
{
F_24 ( & V_43 ) ;
}
