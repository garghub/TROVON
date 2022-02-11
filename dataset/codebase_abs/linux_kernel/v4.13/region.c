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
V_8 -> V_16 = F_13 ( V_8 -> V_2 . V_17 . V_18 ,
L_3 ) ;
if ( ! V_8 -> V_16 )
F_14 ( & V_8 -> V_2 ,
L_4 ) ;
V_14 . V_19 = V_8 -> V_20 ;
V_14 . V_21 = V_8 -> V_20 + V_8 -> V_22 - 1 ;
F_15 ( V_8 , & V_8 -> V_15 , & V_14 ) ;
}
V_8 -> V_23 = F_16 ( V_8 ) ;
V_8 -> V_24 = F_17 ( V_8 ) ;
V_8 -> V_25 = F_18 ( V_8 ) ;
if ( V_3 == 0 )
return 0 ;
F_19 ( V_2 , L_5 ,
V_3 , V_3 == 1 ? L_6 : L_7 ) ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 , void * V_26 )
{
F_21 ( V_2 , V_27 ) ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 )
{
struct V_8 * V_8 = F_2 ( V_2 ) ;
F_23 ( V_2 , NULL , F_20 ) ;
F_24 ( V_2 ) ;
V_8 -> V_28 = NULL ;
V_8 -> V_23 = NULL ;
V_8 -> V_24 = NULL ;
V_8 -> V_25 = NULL ;
F_25 ( V_2 , NULL ) ;
F_26 ( V_2 ) ;
F_27 ( V_8 -> V_16 ) ;
V_8 -> V_16 = NULL ;
return 0 ;
}
static int F_28 ( struct V_1 * V_2 , void * V_26 )
{
F_29 ( V_2 , * (enum V_29 * ) V_26 ) ;
return 0 ;
}
static void F_30 ( struct V_1 * V_2 , enum V_29 V_30 )
{
if ( V_30 == V_31 ) {
struct V_8 * V_8 = F_2 ( V_2 ) ;
struct V_13 V_32 ;
if ( F_11 ( & V_8 -> V_2 ) ) {
V_32 . V_19 = V_8 -> V_20 ;
V_32 . V_21 = V_8 -> V_20 +
V_8 -> V_22 - 1 ;
F_15 ( V_8 ,
& V_8 -> V_15 , & V_32 ) ;
if ( V_8 -> V_16 )
F_31 ( V_8 -> V_16 ) ;
}
}
F_23 ( V_2 , & V_30 , F_28 ) ;
}
int T_1 F_32 ( void )
{
return F_33 ( & V_33 ) ;
}
void F_34 ( void )
{
F_35 ( & V_33 . V_34 ) ;
}
