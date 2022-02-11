static int F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
const struct V_5 * V_6 = (struct V_5 * ) ( V_4 -> V_7 ) ;
struct V_8 * V_8 ;
struct V_9 * V_10 ;
int V_11 ;
V_8 = F_2 ( V_2 , V_4 , V_6 ) ;
if ( V_8 == NULL )
return - V_12 ;
F_3 ( V_2 , V_8 ) ;
V_10 = F_4 ( V_8 ) ;
V_10 -> V_13 = F_5 ( V_8 , V_6 ) ;
if ( F_6 ( V_10 -> V_13 ) ) {
V_11 = F_7 ( V_10 -> V_13 ) ;
goto V_14;
}
V_11 = F_8 ( V_8 , V_8 -> V_15 ) ;
if ( V_11 )
goto V_16;
return 0 ;
V_16:
F_9 ( V_10 -> V_13 ) ;
V_14:
F_10 ( V_8 ) ;
F_3 ( V_2 , NULL ) ;
return V_11 ;
}
static void F_11 ( struct V_1 * V_2 )
{
struct V_8 * V_17 = F_12 ( V_2 ) ;
struct V_9 * V_10 = F_4 ( V_17 ) ;
F_9 ( V_10 -> V_13 ) ;
F_10 ( V_17 ) ;
F_3 ( V_2 , NULL ) ;
}
static int F_13 ( struct V_18 * V_18 )
{
struct V_1 * V_2 = F_14 ( V_18 ) ;
struct V_8 * V_8 = F_12 ( V_2 ) ;
return F_15 ( V_8 ) ;
}
static int F_16 ( struct V_18 * V_18 )
{
struct V_1 * V_2 = F_14 ( V_18 ) ;
struct V_8 * V_8 = F_12 ( V_2 ) ;
F_17 ( V_2 , V_19 , 0x00 ) ;
return F_18 ( V_8 ) ;
}
int T_1 F_19 ( void )
{
int V_11 ;
V_11 = F_20 ( & V_20 ) ;
if ( V_11 )
F_21 ( L_1 ) ;
return V_11 ;
}
void F_22 ( void )
{
F_23 ( & V_20 ) ;
}
