static void F_1 ( struct V_1 * V_2 , void T_1 * V_3 ,
void T_1 * V_4 ,
struct V_5 * V_6 , int V_7 )
{
unsigned long V_8 = ( unsigned long ) V_3 ;
int V_9 ;
V_2 -> V_10 . V_11 = V_8 ;
V_8 += ( 1 << V_6 -> V_12 ) ;
for ( V_9 = 1 ; V_9 <= 7 ;
V_9 ++ , V_8 += ( 1 << V_6 -> V_12 ) )
V_2 -> V_13 [ V_9 ] = V_8 ;
V_2 -> V_10 . V_14 = ( unsigned long ) V_4 ;
V_2 -> V_7 = V_7 ;
}
static int F_2 ( struct V_15 * V_16 )
{
struct V_17 * V_18 , * V_19 , * V_20 ;
void T_1 * V_3 , * V_21 ;
struct V_5 * V_6 ;
struct V_22 * V_23 ;
int V_24 = 0 , V_25 = 0 ;
struct V_1 V_2 , * V_26 [] = { & V_2 } ;
struct V_27 V_28 = V_29 ;
V_6 = V_16 -> V_30 . V_31 ;
V_18 = F_3 ( V_16 , V_32 , 0 ) ;
V_19 = F_3 ( V_16 , V_32 , 1 ) ;
if ( ! V_18 || ! V_19 ) {
V_18 = F_3 ( V_16 , V_33 , 0 ) ;
V_19 = F_3 ( V_16 , V_33 , 1 ) ;
if ( ! V_18 || ! V_19 ) {
V_24 = - V_34 ;
goto V_35;
}
V_25 = 1 ;
}
V_20 = F_3 ( V_16 , V_36 , 0 ) ;
if ( ! V_20 ) {
V_24 = - V_37 ;
goto V_35;
}
if ( V_25 ) {
V_3 = F_4 ( & V_16 -> V_30 ,
V_18 -> V_38 , F_5 ( V_18 ) ) ;
V_21 = F_4 ( & V_16 -> V_30 ,
V_19 -> V_38 , F_5 ( V_19 ) ) ;
} else {
V_3 = F_6 ( & V_16 -> V_30 ,
V_18 -> V_38 , F_5 ( V_18 ) ) ;
V_21 = F_6 ( & V_16 -> V_30 ,
V_19 -> V_38 , F_5 ( V_19 ) ) ;
}
memset ( & V_2 , 0 , sizeof( V_2 ) ) ;
F_1 ( & V_2 , V_3 , V_21 , V_6 , V_20 -> V_38 ) ;
V_2 . V_30 = & V_16 -> V_30 ;
V_28 . V_39 = V_20 -> V_40 & V_41 ;
if ( V_20 -> V_40 & V_42 )
V_28 . V_39 |= V_43 ;
if ( V_25 )
V_28 . V_44 |= V_45 ;
V_24 = F_7 ( & V_28 , V_26 , 1 , & V_23 ) ;
if ( V_24 )
goto V_35;
F_8 ( V_16 , V_23 ) ;
return 0 ;
V_35:
return V_24 ;
}
static int F_9 ( struct V_15 * V_16 )
{
struct V_22 * V_23 = F_10 ( & V_16 -> V_30 ) ;
F_11 ( V_23 ) ;
return 0 ;
}
static int T_2 F_12 ( void )
{
return F_13 ( & V_46 ) ;
}
static void T_3 F_14 ( void )
{
F_15 ( & V_46 ) ;
}
