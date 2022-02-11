static enum V_1 F_1 ( struct V_2 * V_3 )
{
F_2 ( V_4 ) ;
if ( V_5 ) {
F_3 ( L_1 ) ;
} else if ( V_6 ) {
F_3 ( L_2 ) ;
F_4 ( L_3 ) ;
} else {
F_3 ( L_4 ) ;
F_5 () ;
F_3 ( L_5 ) ;
}
return V_7 ;
}
static enum V_1 F_6 ( struct V_2 * V_3 )
{
F_7 ( & V_8 ) ;
return V_7 ;
}
static int F_8 ( struct V_9 * V_10 )
{
if ( ! F_9 ( & V_11 ) )
F_10 ( V_4 ) ;
F_11 ( & V_11 , F_12 ( V_10 -> V_12 , 0 ) ,
V_13 ) ;
if ( F_13 ( V_14 ) ) {
if ( V_10 -> V_15 )
F_11 ( & V_16 ,
F_12 ( V_10 -> V_12 - V_10 -> V_15 , 0 ) ,
V_13 ) ;
else
F_14 ( & V_16 ) ;
}
return 0 ;
}
static int F_15 ( struct V_9 * V_10 )
{
if ( F_14 ( & V_11 ) )
F_2 ( V_4 ) ;
if ( F_13 ( V_14 ) )
F_14 ( & V_16 ) ;
return 0 ;
}
static int T_1 F_16 ( void )
{
int V_17 ;
F_17 ( & V_8 , V_18 , NULL ) ;
F_18 ( & V_8 , V_19 ) ;
F_19 ( & V_8 ) ;
F_20 ( & V_11 , V_20 , V_13 ) ;
V_11 . V_21 = F_1 ;
if ( F_13 ( V_14 ) ) {
V_22 . V_23 |= V_24 ;
F_20 ( & V_16 , V_20 ,
V_13 ) ;
V_16 . V_21 = F_6 ;
}
V_17 = F_21 ( & V_8 ) ;
if ( V_17 )
return V_17 ;
F_22 ( L_6 ,
V_5 , V_8 . V_12 , V_6 , V_19 ) ;
return 0 ;
}
static void T_2 F_23 ( void )
{
F_24 ( & V_8 ) ;
}
