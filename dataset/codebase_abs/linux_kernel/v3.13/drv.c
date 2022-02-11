static int F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
const struct V_5 * V_6 = (struct V_5 * ) ( V_4 -> V_7 ) ;
struct V_8 * V_8 ;
struct V_9 * V_10 ;
int V_11 ;
V_8 = F_2 ( V_2 , V_4 , V_6 ) ;
if ( F_3 ( V_8 ) )
return F_4 ( V_8 ) ;
F_5 ( V_2 , V_8 ) ;
V_10 = F_6 ( V_8 ) ;
V_10 -> V_12 = F_7 ( V_8 , V_6 ) ;
if ( F_3 ( V_10 -> V_12 ) ) {
V_11 = F_4 ( V_10 -> V_12 ) ;
goto V_13;
}
V_11 = F_8 ( V_8 , V_8 -> V_14 ) ;
if ( V_11 )
goto V_15;
return 0 ;
V_15:
F_9 ( V_10 -> V_12 ) ;
V_13:
F_10 ( V_8 ) ;
return V_11 ;
}
static void F_11 ( struct V_1 * V_2 )
{
struct V_8 * V_16 = F_12 ( V_2 ) ;
struct V_9 * V_10 = F_6 ( V_16 ) ;
F_9 ( V_10 -> V_12 ) ;
F_10 ( V_16 ) ;
}
static int F_13 ( struct V_17 * V_17 )
{
return 0 ;
}
static int F_14 ( struct V_17 * V_17 )
{
struct V_1 * V_2 = F_15 ( V_17 ) ;
struct V_8 * V_16 = F_12 ( V_2 ) ;
bool V_18 ;
F_16 ( V_2 , V_19 , 0x00 ) ;
if ( ! V_16 -> V_20 )
return 0 ;
F_17 ( V_16 ) ;
V_18 = F_18 ( V_16 ) ;
F_19 ( V_16 -> V_20 , V_18 ) ;
return 0 ;
}
int T_1 F_20 ( void )
{
int V_11 ;
V_11 = F_21 ( & V_21 ) ;
if ( V_11 )
F_22 ( L_1 ) ;
return V_11 ;
}
void F_23 ( void )
{
F_24 ( & V_21 ) ;
}
