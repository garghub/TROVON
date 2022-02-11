static int F_1 ( struct V_1 * V_2 )
{
int V_3 , V_4 ;
static unsigned long V_5 ;
struct V_6 * V_7 ;
struct V_8 * V_8 = F_2 ( V_2 ) ;
if ( V_8 -> V_9 > F_3 ()
&& V_8 -> V_9 < F_4 ()
&& ! F_5 ( 0 , & V_5 ) ) {
F_6 ( V_2 , L_1 ,
F_3 () , V_8 -> V_9 ,
F_4 () ) ;
F_6 ( V_2 , L_2 ,
V_8 -> V_9 ) ;
}
V_4 = F_7 ( V_8 ) ;
if ( V_4 )
return V_4 ;
V_4 = F_8 ( V_8 ) ;
if ( V_4 )
return V_4 ;
V_4 = F_9 ( V_8 , & V_3 ) ;
if ( V_4 < 0 )
return V_4 ;
V_7 = F_10 ( V_2 ) ;
V_7 -> V_10 = V_4 ;
V_7 -> V_11 = V_4 + V_3 ;
if ( V_4 && V_3 && V_4 == V_3 )
return - V_12 ;
if ( F_11 ( & V_8 -> V_2 ) ) {
struct V_13 V_14 ;
if ( F_12 ( V_2 , & V_8 -> V_15 ) )
return - V_12 ;
V_14 . V_16 = V_8 -> V_17 ;
V_14 . V_18 = V_8 -> V_17 + V_8 -> V_19 - 1 ;
F_13 ( V_8 ,
& V_8 -> V_15 , & V_14 ) ;
}
V_8 -> V_20 = F_14 ( V_8 ) ;
V_8 -> V_21 = F_15 ( V_8 ) ;
V_8 -> V_22 = F_16 ( V_8 ) ;
if ( V_3 == 0 )
return 0 ;
F_17 ( V_2 , L_3 ,
V_3 , V_3 == 1 ? L_4 : L_5 ) ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 , void * V_23 )
{
F_19 ( V_2 , V_24 ) ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 )
{
struct V_8 * V_8 = F_2 ( V_2 ) ;
F_21 ( V_2 , NULL , F_18 ) ;
F_22 ( V_2 ) ;
V_8 -> V_25 = NULL ;
V_8 -> V_20 = NULL ;
V_8 -> V_21 = NULL ;
V_8 -> V_22 = NULL ;
F_23 ( V_2 , NULL ) ;
F_24 ( V_2 ) ;
return 0 ;
}
static int F_25 ( struct V_1 * V_2 , void * V_23 )
{
F_26 ( V_2 , * (enum V_26 * ) V_23 ) ;
return 0 ;
}
static void F_27 ( struct V_1 * V_2 , enum V_26 V_27 )
{
if ( V_27 == V_28 ) {
struct V_8 * V_8 = F_2 ( V_2 ) ;
struct V_13 V_29 ;
if ( F_11 ( & V_8 -> V_2 ) ) {
V_29 . V_16 = V_8 -> V_17 ;
V_29 . V_18 = V_8 -> V_17 +
V_8 -> V_19 - 1 ;
F_13 ( V_8 ,
& V_8 -> V_15 , & V_29 ) ;
}
}
F_21 ( V_2 , & V_27 , F_25 ) ;
}
int T_1 F_28 ( void )
{
return F_29 ( & V_30 ) ;
}
void F_30 ( void )
{
F_31 ( & V_30 . V_31 ) ;
}
