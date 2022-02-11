static int
F_1 ( struct V_1 * V_2 )
{
int V_3 ;
V_3 = F_2 ( & V_4 ) ;
if ( V_3 < 0 )
return V_3 ;
V_2 -> V_5 = & V_4 ;
return 0 ;
}
static int
F_3 ( struct V_1 * V_2 )
{
T_1 * V_6 = V_2 -> V_5 ;
if ( V_6 ) {
F_4 ( V_6 ) ;
F_5 ( & V_7 ) ;
V_2 -> V_5 = NULL ;
}
return 0 ;
}
static int
F_6 ( struct V_1 * V_8 )
{
T_1 * V_6 = V_8 -> V_5 ;
if ( F_7 ( ! V_6 ) )
return - V_9 ;
F_8 ( V_6 , V_10 , V_11 ) ;
F_8 ( V_6 , V_12 , 0 ) ;
return 0 ;
}
static int
F_9 ( struct V_1 * V_8 )
{
T_1 * V_6 = V_8 -> V_5 ;
if ( F_7 ( ! V_6 ) )
return - V_9 ;
F_8 ( V_6 , V_13 , 0 ) ;
return 0 ;
}
static void F_10 ( unsigned long V_14 )
{
F_11 ( (struct V_1 * ) V_14 , 1 ) ;
}
static void F_12 ( void * V_5 )
{
F_13 ( V_5 ) ;
}
static int T_2 F_14 ( void )
{
int V_3 ;
struct V_1 * V_8 ;
if ( V_11 < 2 || V_11 > 8192 ||
! F_15 ( V_11 ) ) {
F_16 ( L_1 , V_11 ) ;
return - V_9 ;
}
V_3 = F_17 ( L_2 , V_15 , & V_8 ) ;
if ( V_3 < 0 )
return V_3 ;
V_8 -> V_16 = V_17 ;
strcpy ( V_8 -> V_18 , L_3 ) ;
V_8 -> V_19 = V_20 ;
V_8 -> V_19 . V_21 = V_22 / V_11 ;
F_18 ( & V_7 , F_10 , ( unsigned long ) V_8 ) ;
V_4 . V_23 = F_12 ;
V_4 . V_5 = & V_7 ;
V_3 = F_19 ( V_8 ) ;
if ( V_3 < 0 ) {
F_20 ( V_8 ) ;
return V_3 ;
}
V_24 = V_8 ;
return 0 ;
}
static void T_3 F_21 ( void )
{
if ( V_24 ) {
F_20 ( V_24 ) ;
V_24 = NULL ;
}
}
