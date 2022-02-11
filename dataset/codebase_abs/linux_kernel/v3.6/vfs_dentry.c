static int F_1 ( const struct V_1 * V_1 )
{
F_2 ( V_2 , L_1 ,
V_1 -> V_3 . V_4 , V_1 ) ;
return 1 ;
}
static int F_3 ( const struct V_1 * V_1 )
{
F_2 ( V_2 , L_1 ,
V_1 -> V_3 . V_4 , V_1 ) ;
if ( ! V_1 -> V_5 )
return 1 ;
return 0 ;
}
static void F_4 ( struct V_1 * V_1 )
{
struct V_6 * V_7 ;
struct V_8 * V_9 , * V_10 ;
F_2 ( V_2 , L_1 ,
V_1 -> V_3 . V_4 , V_1 ) ;
V_7 = V_1 -> V_11 ;
if ( V_7 ) {
F_5 (current_fid, temp, &dent->fidlist,
dlist) {
F_6 ( V_10 ) ;
}
F_7 ( V_7 ) ;
V_1 -> V_11 = NULL ;
}
}
static int F_8 ( struct V_1 * V_1 , unsigned int V_12 )
{
struct V_8 * V_13 ;
struct V_14 * V_14 ;
struct V_15 * V_16 ;
if ( V_12 & V_17 )
return - V_18 ;
V_14 = V_1 -> V_5 ;
if ( ! V_14 )
goto V_19;
V_16 = F_9 ( V_14 ) ;
if ( V_16 -> V_20 & V_21 ) {
int V_22 ;
struct V_23 * V_24 ;
V_13 = F_10 ( V_1 ) ;
if ( F_11 ( V_13 ) )
return F_12 ( V_13 ) ;
V_24 = F_13 ( V_14 ) ;
if ( F_14 ( V_24 ) )
V_22 = F_15 ( V_13 , V_14 ) ;
else
V_22 = F_16 ( V_13 , V_14 ) ;
if ( V_22 == - V_25 )
return 0 ;
if ( V_22 < 0 )
return V_22 ;
}
V_19:
return 1 ;
}
