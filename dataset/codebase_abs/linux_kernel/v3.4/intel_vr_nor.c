static void T_1 F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 ) ;
}
static int T_2 F_3 ( struct V_1 * V_2 )
{
return F_4 ( V_2 -> V_3 , NULL , NULL , NULL , 0 ) ;
}
static void T_1 F_5 ( struct V_1 * V_2 )
{
F_6 ( V_2 -> V_3 ) ;
}
static int T_2 F_7 ( struct V_1 * V_2 )
{
static const char * V_4 [] =
{ L_1 , L_2 , NULL } ;
const char * * type ;
for ( type = V_4 ; ! V_2 -> V_3 && * type ; type ++ )
V_2 -> V_3 = F_8 ( * type , & V_2 -> V_5 ) ;
if ( ! V_2 -> V_3 )
return - V_6 ;
V_2 -> V_3 -> V_7 = V_8 ;
return 0 ;
}
static void T_1 F_9 ( struct V_1 * V_2 )
{
unsigned int V_9 ;
V_9 = F_10 ( V_2 -> V_10 + V_11 ) ;
V_9 &= ~ V_12 ;
F_11 ( V_9 , V_2 -> V_10 + V_11 ) ;
F_12 ( V_2 -> V_5 . V_13 ) ;
F_12 ( V_2 -> V_10 ) ;
}
static int T_2 F_13 ( struct V_1 * V_2 )
{
unsigned long V_14 , V_15 ;
unsigned long V_16 , V_17 ;
unsigned int V_9 ;
int V_18 ;
V_14 = F_14 ( V_2 -> V_19 , V_20 ) ;
V_15 = F_15 ( V_2 -> V_19 , V_20 ) ;
V_16 = F_14 ( V_2 -> V_19 , V_21 ) ;
V_17 = F_15 ( V_2 -> V_19 , V_21 ) ;
if ( ! V_14 || ! V_15 || ! V_16 || ! V_17 )
return - V_6 ;
if ( V_17 < ( V_22 + V_23 ) )
return - V_24 ;
V_2 -> V_10 = F_16 ( V_14 , V_15 ) ;
if ( ! V_2 -> V_10 )
return - V_25 ;
V_9 = F_10 ( V_2 -> V_10 + V_11 ) ;
if ( ! ( V_9 & V_26 ) ) {
F_17 ( & V_2 -> V_19 -> V_19 , L_3
L_4 ) ;
V_18 = - V_6 ;
goto V_27;
}
if ( ( V_9 & V_28 ) == V_28 ) {
F_17 ( & V_2 -> V_19 -> V_19 , L_3
L_5 ) ;
}
V_2 -> V_5 . V_29 = V_30 ;
V_2 -> V_5 . V_31 = ( V_9 & V_32 ) ? 1 : 2 ;
V_2 -> V_5 . V_33 = V_16 + V_22 ;
V_2 -> V_5 . V_34 = V_23 ;
V_2 -> V_5 . V_13 = F_16 ( V_2 -> V_5 . V_33 , V_2 -> V_5 . V_34 ) ;
if ( ! V_2 -> V_5 . V_13 ) {
V_18 = - V_25 ;
goto V_27;
}
F_18 ( & V_2 -> V_5 ) ;
V_9 |= V_35 | V_12 ;
F_11 ( V_9 , V_2 -> V_10 + V_11 ) ;
return 0 ;
V_27:
F_12 ( V_2 -> V_10 ) ;
return V_18 ;
}
static void T_1 F_19 ( struct V_36 * V_19 )
{
struct V_1 * V_2 = F_20 ( V_19 ) ;
F_21 ( V_19 , NULL ) ;
F_1 ( V_2 ) ;
F_5 ( V_2 ) ;
F_9 ( V_2 ) ;
F_22 ( V_2 ) ;
F_23 ( V_19 ) ;
F_24 ( V_19 ) ;
}
static int T_2
F_25 ( struct V_36 * V_19 , const struct V_37 * V_38 )
{
struct V_1 * V_2 = NULL ;
unsigned int V_9 ;
int V_18 ;
V_18 = F_26 ( V_19 ) ;
if ( V_18 )
goto V_39;
V_18 = F_27 ( V_19 , V_30 ) ;
if ( V_18 )
goto V_40;
V_2 = F_28 ( sizeof( * V_2 ) , V_41 ) ;
V_18 = - V_25 ;
if ( ! V_2 )
goto V_27;
V_2 -> V_19 = V_19 ;
V_18 = F_13 ( V_2 ) ;
if ( V_18 )
goto V_27;
V_18 = F_7 ( V_2 ) ;
if ( V_18 )
goto V_42;
V_18 = F_3 ( V_2 ) ;
if ( V_18 )
goto V_43;
F_21 ( V_19 , V_2 ) ;
return 0 ;
V_43:
F_6 ( V_2 -> V_3 ) ;
V_42:
V_9 = F_10 ( V_2 -> V_10 + V_11 ) ;
V_9 &= ~ V_12 ;
F_11 ( V_9 , V_2 -> V_10 + V_11 ) ;
F_12 ( V_2 -> V_5 . V_13 ) ;
F_12 ( V_2 -> V_10 ) ;
V_27:
F_22 ( V_2 ) ;
F_23 ( V_19 ) ;
V_40:
F_24 ( V_19 ) ;
V_39:
return V_18 ;
}
static int T_3 F_29 ( void )
{
return F_30 ( & V_44 ) ;
}
static void T_4 F_31 ( void )
{
F_32 ( & V_44 ) ;
}
