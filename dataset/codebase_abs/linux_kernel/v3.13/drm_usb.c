int F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_7 * V_8 ;
int V_9 ;
F_2 ( L_1 ) ;
V_8 = F_3 ( V_6 , & V_2 -> V_8 ) ;
if ( ! V_8 )
return - V_10 ;
V_8 -> V_11 = F_4 ( V_2 ) ;
F_5 ( V_2 , V_8 ) ;
V_9 = F_6 ( V_8 , 0 ) ;
if ( V_9 )
goto V_12;
F_7 ( L_2 ,
V_6 -> V_13 , V_6 -> V_14 , V_6 -> V_15 , V_6 -> V_16 ,
V_6 -> V_17 , V_8 -> V_18 -> V_19 ) ;
return 0 ;
V_12:
F_8 ( V_8 ) ;
return V_9 ;
}
static int F_9 ( struct V_7 * V_8 )
{
return 0 ;
}
static const char * F_10 ( struct V_7 * V_8 )
{
return L_3 ;
}
static int F_11 ( struct V_7 * V_8 ,
struct V_20 * V_21 )
{
return 0 ;
}
int F_12 ( struct V_5 * V_6 , struct V_22 * V_23 )
{
int V_24 ;
F_2 ( L_1 ) ;
F_13 ( & V_6 -> V_25 ) ;
V_6 -> V_26 . V_27 = V_23 ;
V_6 -> V_28 = & V_29 ;
V_24 = F_14 ( V_23 ) ;
return V_24 ;
}
void F_15 ( struct V_5 * V_6 ,
struct V_22 * V_23 )
{
F_16 ( V_23 ) ;
}
