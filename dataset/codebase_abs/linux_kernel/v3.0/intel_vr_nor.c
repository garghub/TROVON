static void T_1 F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 ) ;
}
static int T_2 F_3 ( struct V_1 * V_2 )
{
struct V_4 * V_5 ;
static const char * V_6 [] = { L_1 , NULL } ;
V_2 -> V_7 = F_4 ( V_2 -> V_3 , V_6 , & V_5 , 0 ) ;
return F_5 ( V_2 -> V_3 , V_5 , V_2 -> V_7 ) ;
}
static void T_1 F_6 ( struct V_1 * V_2 )
{
F_7 ( V_2 -> V_3 ) ;
}
static int T_2 F_8 ( struct V_1 * V_2 )
{
static const char * V_8 [] =
{ L_2 , L_3 , NULL } ;
const char * * type ;
for ( type = V_8 ; ! V_2 -> V_3 && * type ; type ++ )
V_2 -> V_3 = F_9 ( * type , & V_2 -> V_9 ) ;
if ( ! V_2 -> V_3 )
return - V_10 ;
V_2 -> V_3 -> V_11 = V_12 ;
return 0 ;
}
static void T_1 F_10 ( struct V_1 * V_2 )
{
unsigned int V_13 ;
V_13 = F_11 ( V_2 -> V_14 + V_15 ) ;
V_13 &= ~ V_16 ;
F_12 ( V_13 , V_2 -> V_14 + V_15 ) ;
F_13 ( V_2 -> V_9 . V_17 ) ;
F_13 ( V_2 -> V_14 ) ;
}
static int T_2 F_14 ( struct V_1 * V_2 )
{
unsigned long V_18 , V_19 ;
unsigned long V_20 , V_21 ;
unsigned int V_13 ;
int V_22 ;
V_18 = F_15 ( V_2 -> V_23 , V_24 ) ;
V_19 = F_16 ( V_2 -> V_23 , V_24 ) ;
V_20 = F_15 ( V_2 -> V_23 , V_25 ) ;
V_21 = F_16 ( V_2 -> V_23 , V_25 ) ;
if ( ! V_18 || ! V_19 || ! V_20 || ! V_21 )
return - V_10 ;
if ( V_21 < ( V_26 + V_27 ) )
return - V_28 ;
V_2 -> V_14 = F_17 ( V_18 , V_19 ) ;
if ( ! V_2 -> V_14 )
return - V_29 ;
V_13 = F_11 ( V_2 -> V_14 + V_15 ) ;
if ( ! ( V_13 & V_30 ) ) {
F_18 ( & V_2 -> V_23 -> V_23 , L_4
L_5 ) ;
V_22 = - V_10 ;
goto V_31;
}
if ( ( V_13 & V_32 ) == V_32 ) {
F_18 ( & V_2 -> V_23 -> V_23 , L_4
L_6 ) ;
}
V_2 -> V_9 . V_33 = V_34 ;
V_2 -> V_9 . V_35 = ( V_13 & V_36 ) ? 1 : 2 ;
V_2 -> V_9 . V_37 = V_20 + V_26 ;
V_2 -> V_9 . V_38 = V_27 ;
V_2 -> V_9 . V_17 = F_17 ( V_2 -> V_9 . V_37 , V_2 -> V_9 . V_38 ) ;
if ( ! V_2 -> V_9 . V_17 ) {
V_22 = - V_29 ;
goto V_31;
}
F_19 ( & V_2 -> V_9 ) ;
V_13 |= V_39 | V_16 ;
F_12 ( V_13 , V_2 -> V_14 + V_15 ) ;
return 0 ;
V_31:
F_13 ( V_2 -> V_14 ) ;
return V_22 ;
}
static void T_1 F_20 ( struct V_40 * V_23 )
{
struct V_1 * V_2 = F_21 ( V_23 ) ;
F_22 ( V_23 , NULL ) ;
F_1 ( V_2 ) ;
F_6 ( V_2 ) ;
F_10 ( V_2 ) ;
F_23 ( V_2 ) ;
F_24 ( V_23 ) ;
F_25 ( V_23 ) ;
}
static int T_2
F_26 ( struct V_40 * V_23 , const struct V_41 * V_42 )
{
struct V_1 * V_2 = NULL ;
unsigned int V_13 ;
int V_22 ;
V_22 = F_27 ( V_23 ) ;
if ( V_22 )
goto V_43;
V_22 = F_28 ( V_23 , V_34 ) ;
if ( V_22 )
goto V_44;
V_2 = F_29 ( sizeof( * V_2 ) , V_45 ) ;
V_22 = - V_29 ;
if ( ! V_2 )
goto V_31;
V_2 -> V_23 = V_23 ;
V_22 = F_14 ( V_2 ) ;
if ( V_22 )
goto V_31;
V_22 = F_8 ( V_2 ) ;
if ( V_22 )
goto V_46;
V_22 = F_3 ( V_2 ) ;
if ( V_22 )
goto V_47;
F_22 ( V_23 , V_2 ) ;
return 0 ;
V_47:
F_7 ( V_2 -> V_3 ) ;
V_46:
V_13 = F_11 ( V_2 -> V_14 + V_15 ) ;
V_13 &= ~ V_16 ;
F_12 ( V_13 , V_2 -> V_14 + V_15 ) ;
F_13 ( V_2 -> V_9 . V_17 ) ;
F_13 ( V_2 -> V_14 ) ;
V_31:
F_23 ( V_2 ) ;
F_24 ( V_23 ) ;
V_44:
F_25 ( V_23 ) ;
V_43:
return V_22 ;
}
static int T_3 F_30 ( void )
{
return F_31 ( & V_48 ) ;
}
static void T_4 F_32 ( void )
{
F_33 ( & V_48 ) ;
}
