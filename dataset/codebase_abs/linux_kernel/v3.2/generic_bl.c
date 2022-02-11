static int F_1 ( struct V_1 * V_2 )
{
int V_3 = V_2 -> V_4 . V_5 ;
if ( V_2 -> V_4 . V_6 != V_7 )
V_3 = 0 ;
if ( V_2 -> V_4 . V_8 & V_9 )
V_3 = 0 ;
if ( V_2 -> V_4 . V_8 & V_10 )
V_3 = 0 ;
if ( V_2 -> V_4 . V_8 & V_11 )
V_3 &= V_12 -> V_13 ;
V_12 -> V_14 ( V_3 ) ;
V_15 = V_3 ;
if ( V_12 -> V_16 )
V_12 -> V_16 () ;
return 0 ;
}
static int F_2 ( struct V_1 * V_2 )
{
return V_15 ;
}
void F_3 ( int V_17 )
{
struct V_1 * V_2 = V_18 ;
F_4 ( & V_2 -> V_19 ) ;
if ( V_17 )
V_2 -> V_4 . V_8 |= V_11 ;
else
V_2 -> V_4 . V_8 &= ~ V_11 ;
F_5 ( V_18 ) ;
F_6 ( & V_2 -> V_19 ) ;
}
static int F_7 ( struct V_20 * V_21 )
{
struct V_22 V_4 ;
struct V_23 * V_24 = V_21 -> V_25 . V_26 ;
const char * V_27 = L_1 ;
struct V_1 * V_2 ;
V_12 = V_24 ;
if ( ! V_24 -> V_13 )
V_24 -> V_13 = - 1 ;
if ( V_24 -> V_27 )
V_27 = V_24 -> V_27 ;
memset ( & V_4 , 0 , sizeof( struct V_22 ) ) ;
V_4 . type = V_28 ;
V_4 . V_29 = V_24 -> V_30 ;
V_2 = F_8 ( V_27 , & V_21 -> V_25 , NULL , & V_31 ,
& V_4 ) ;
if ( F_9 ( V_2 ) )
return F_10 ( V_2 ) ;
F_11 ( V_21 , V_2 ) ;
V_2 -> V_4 . V_6 = V_7 ;
V_2 -> V_4 . V_5 = V_24 -> V_32 ;
F_5 ( V_2 ) ;
V_18 = V_2 ;
F_12 ( L_2 ) ;
return 0 ;
}
static int F_13 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = F_14 ( V_21 ) ;
V_2 -> V_4 . V_6 = 0 ;
V_2 -> V_4 . V_5 = 0 ;
F_5 ( V_2 ) ;
F_15 ( V_2 ) ;
F_12 ( L_3 ) ;
return 0 ;
}
static int T_1 F_16 ( void )
{
return F_17 ( & V_33 ) ;
}
static void T_2 F_18 ( void )
{
F_19 ( & V_33 ) ;
}
