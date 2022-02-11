static int F_1 ( const struct V_1 * V_1 )
{
F_2 ( V_2 , L_1 ,
V_1 , V_1 ) ;
if ( F_3 ( V_1 ) )
return 1 ;
return 0 ;
}
static void F_4 ( struct V_1 * V_1 )
{
struct V_3 * V_4 , * V_5 ;
F_2 ( V_2 , L_1 ,
V_1 , V_1 ) ;
F_5 (p, n, (struct hlist_head *)&dentry->d_fsdata)
F_6 ( F_7 ( V_4 , struct V_6 , V_7 ) ) ;
V_1 -> V_8 = NULL ;
}
static int F_8 ( struct V_1 * V_1 , unsigned int V_9 )
{
struct V_6 * V_10 ;
struct V_11 * V_11 ;
struct V_12 * V_13 ;
if ( V_9 & V_14 )
return - V_15 ;
V_11 = F_9 ( V_1 ) ;
if ( ! V_11 )
goto V_16;
V_13 = F_10 ( V_11 ) ;
if ( V_13 -> V_17 & V_18 ) {
int V_19 ;
struct V_20 * V_21 ;
V_10 = F_11 ( V_1 ) ;
if ( F_12 ( V_10 ) )
return F_13 ( V_10 ) ;
V_21 = F_14 ( V_11 ) ;
if ( F_15 ( V_21 ) )
V_19 = F_16 ( V_10 , V_11 ) ;
else
V_19 = F_17 ( V_10 , V_11 ) ;
if ( V_19 == - V_22 )
return 0 ;
if ( V_19 < 0 )
return V_19 ;
}
V_16:
return 1 ;
}
