static int F_1 ( const struct V_1 * V_1 )
{
F_2 ( V_2 , L_1 ,
V_1 , V_1 ) ;
if ( ! V_1 -> V_3 )
return 1 ;
return 0 ;
}
static void F_3 ( struct V_1 * V_1 )
{
struct V_4 * V_5 , * V_6 ;
F_2 ( V_2 , L_1 ,
V_1 , V_1 ) ;
F_4 (p, n, (struct hlist_head *)&dentry->d_fsdata)
F_5 ( F_6 ( V_5 , struct V_7 , V_8 ) ) ;
V_1 -> V_9 = NULL ;
}
static int F_7 ( struct V_1 * V_1 , unsigned int V_10 )
{
struct V_7 * V_11 ;
struct V_12 * V_12 ;
struct V_13 * V_14 ;
if ( V_10 & V_15 )
return - V_16 ;
V_12 = V_1 -> V_3 ;
if ( ! V_12 )
goto V_17;
V_14 = F_8 ( V_12 ) ;
if ( V_14 -> V_18 & V_19 ) {
int V_20 ;
struct V_21 * V_22 ;
V_11 = F_9 ( V_1 ) ;
if ( F_10 ( V_11 ) )
return F_11 ( V_11 ) ;
V_22 = F_12 ( V_12 ) ;
if ( F_13 ( V_22 ) )
V_20 = F_14 ( V_11 , V_12 ) ;
else
V_20 = F_15 ( V_11 , V_12 ) ;
if ( V_20 == - V_23 )
return 0 ;
if ( V_20 < 0 )
return V_20 ;
}
V_17:
return 1 ;
}
