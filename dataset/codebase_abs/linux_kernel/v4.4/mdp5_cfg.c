const struct V_1 * F_1 ( struct V_2 * V_3 )
{
return V_3 -> V_4 . V_5 ;
}
struct V_6 * F_2 ( struct V_2 * V_3 )
{
return & V_3 -> V_4 ;
}
int F_3 ( struct V_2 * V_3 )
{
return V_3 -> V_7 ;
}
void F_4 ( struct V_2 * V_3 )
{
F_5 ( V_3 ) ;
}
struct V_2 * F_6 ( struct V_8 * V_8 ,
T_1 V_9 , T_1 V_10 )
{
struct V_11 * V_12 = V_8 -> V_12 ;
struct V_13 * V_14 = V_12 -> V_15 ;
struct V_2 * V_3 ;
struct V_16 * V_17 ;
int V_18 , V_19 = 0 ;
V_3 = F_7 ( sizeof( * V_3 ) , V_20 ) ;
if ( F_8 ( ! V_3 ) ) {
V_19 = - V_21 ;
goto V_22;
}
if ( V_9 != 1 ) {
F_9 ( V_12 -> V_12 , L_1 ,
V_9 , V_10 ) ;
V_19 = - V_23 ;
goto V_22;
}
for ( V_18 = 0 ; V_18 < F_10 ( V_24 ) ; V_18 ++ ) {
if ( V_24 [ V_18 ] . V_7 != V_10 )
continue;
V_6 = V_24 [ V_18 ] . V_4 . V_5 ;
break;
}
if ( F_8 ( ! V_6 ) ) {
F_9 ( V_12 -> V_12 , L_2 ,
V_9 , V_10 ) ;
V_19 = - V_23 ;
goto V_22;
}
V_3 -> V_7 = V_10 ;
V_3 -> V_4 . V_5 = V_6 ;
V_17 = F_11 ( V_14 ) ;
memcpy ( & V_3 -> V_4 . V_25 , V_17 , sizeof( * V_17 ) ) ;
F_12 ( L_3 , V_6 -> V_26 ) ;
return V_3 ;
V_22:
if ( V_3 )
F_4 ( V_3 ) ;
return NULL ;
}
static struct V_16 * F_11 ( struct V_13 * V_12 )
{
static struct V_16 V_4 = {} ;
#ifdef F_13
#endif
V_4 . V_27 = F_14 ( & V_28 ) ;
return & V_4 ;
}
