static int T_1 F_1 ( char * V_1 )
{
if ( strncmp ( V_1 , L_1 , 3 ) == 0 )
V_2 = L_1 ;
return 1 ;
}
static void F_2 ( struct V_3 * V_3 )
{
struct V_4 * V_4 = V_3 -> V_5 . V_4 ;
struct V_6 * V_6 = V_4 -> V_7 ;
T_2 V_8 = V_3 -> V_9 ;
int V_10 ;
bool V_11 = false , V_12 = false ;
if ( ! F_3 ( V_6 -> V_13 ) || ! V_14 )
return;
F_4 ( & V_6 -> V_15 ) ;
if ( V_8 & V_16 ) {
if ( F_5 ( & V_6 -> V_17 ) && F_6 ( V_6 ) )
V_11 = true ;
goto V_18;
}
V_10 = F_7 ( V_6 , V_19 , V_20 ) ;
if ( V_10 < 0 )
goto V_18;
if ( F_5 ( & V_6 -> V_21 ) > 0 )
V_12 = true ;
V_18:
F_8 ( & V_6 -> V_15 ) ;
if ( V_11 )
F_9 ( V_6 , V_4 -> V_22 . V_23 , L_2 ,
L_3 ) ;
if ( V_12 )
F_9 ( V_6 , V_4 -> V_22 . V_23 , L_2 ,
L_4 ) ;
}
static void F_10 ( struct V_24 * V_25 ,
struct V_6 * V_6 ,
struct V_3 * V_3 )
{
T_3 V_8 = V_3 -> V_9 ;
F_4 ( & V_25 -> V_26 ) ;
if ( V_8 & V_16 &&
F_5 ( & V_6 -> V_21 ) == 1 &&
V_25 -> V_27 != V_6 -> V_28 )
V_25 -> V_29 &= ~ V_30 ;
F_8 ( & V_25 -> V_26 ) ;
}
void F_11 ( struct V_3 * V_3 )
{
struct V_6 * V_6 = V_3 -> V_31 -> V_7 ;
struct V_24 * V_25 ;
if ( ! V_32 || ! F_3 ( V_6 -> V_13 ) )
return;
V_25 = F_12 ( V_6 ) ;
if ( ! V_25 )
return;
F_10 ( V_25 , V_6 , V_3 ) ;
}
static int F_13 ( struct V_3 * V_3 , const unsigned char * V_33 ,
int V_34 , int V_35 )
{
struct V_6 * V_6 = V_3 -> V_31 -> V_7 ;
struct V_24 * V_25 ;
int V_10 = 0 ;
if ( ! V_14 || ! F_3 ( V_6 -> V_13 ) )
return 0 ;
V_10 = F_7 ( V_6 , V_34 , V_35 ) ;
if ( V_10 != 0 )
return V_10 ;
V_36:
V_25 = F_12 ( V_6 ) ;
if ( ! V_25 ) {
V_10 = F_14 ( V_6 ) ;
if ( ! V_10 || V_10 == - V_37 )
goto V_36;
return V_10 ;
}
F_4 ( & V_25 -> V_26 ) ;
V_10 = V_25 -> V_29 & V_30 ? 1 : 0 ;
if ( V_10 != 0 )
goto V_18;
V_10 = F_15 ( V_25 , V_3 ) ;
if ( ! V_10 )
F_16 ( V_25 , V_3 , V_33 ) ;
V_18:
F_8 ( & V_25 -> V_26 ) ;
return V_10 ;
}
int F_17 ( struct V_3 * V_3 , unsigned long V_38 )
{
int V_10 ;
if ( ! V_3 )
return 0 ;
if ( V_38 & V_39 )
V_10 = F_13 ( V_3 , V_3 -> V_31 -> V_22 . V_23 ,
V_40 , V_41 ) ;
return 0 ;
}
int F_18 ( struct V_42 * V_43 )
{
int V_10 ;
V_10 = F_13 ( V_43 -> V_3 , V_43 -> V_33 ,
V_40 , V_44 ) ;
return 0 ;
}
int F_19 ( struct V_3 * V_3 , int V_34 )
{
int V_10 ;
F_2 ( V_3 ) ;
V_10 = F_13 ( V_3 , V_3 -> V_31 -> V_22 . V_23 ,
V_34 & ( V_19 | V_45 | V_40 ) ,
V_20 ) ;
return 0 ;
}
static int T_1 F_20 ( void )
{
int error ;
error = F_21 () ;
V_14 = 1 ;
return error ;
}
static void T_4 F_22 ( void )
{
F_23 () ;
}
