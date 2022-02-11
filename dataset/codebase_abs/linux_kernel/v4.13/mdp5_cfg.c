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
struct V_13 * V_14 = F_7 ( V_12 -> V_12 ) ;
struct V_2 * V_3 ;
struct V_15 * V_16 ;
int V_17 , V_18 = 0 ;
V_3 = F_8 ( sizeof( * V_3 ) , V_19 ) ;
if ( F_9 ( ! V_3 ) ) {
V_18 = - V_20 ;
goto V_21;
}
if ( V_9 != 1 ) {
F_10 ( V_12 -> V_12 , L_1 ,
V_9 , V_10 ) ;
V_18 = - V_22 ;
goto V_21;
}
for ( V_17 = 0 ; V_17 < F_11 ( V_23 ) ; V_17 ++ ) {
if ( V_23 [ V_17 ] . V_7 != V_10 )
continue;
V_6 = V_23 [ V_17 ] . V_4 . V_5 ;
break;
}
if ( F_9 ( ! V_6 ) ) {
F_10 ( V_12 -> V_12 , L_2 ,
V_9 , V_10 ) ;
V_18 = - V_22 ;
goto V_21;
}
V_3 -> V_7 = V_10 ;
V_3 -> V_4 . V_5 = V_6 ;
V_16 = F_12 ( V_14 ) ;
memcpy ( & V_3 -> V_4 . V_24 , V_16 , sizeof( * V_16 ) ) ;
F_13 ( L_3 , V_6 -> V_25 ) ;
return V_3 ;
V_21:
if ( V_3 )
F_4 ( V_3 ) ;
return NULL ;
}
static struct V_15 * F_12 ( struct V_13 * V_12 )
{
static struct V_15 V_4 = {} ;
V_4 . V_26 = F_14 ( & V_27 ) ;
if ( V_4 . V_26 ) {
V_4 . V_26 -> V_28 . V_29 = 0x1000 ;
V_4 . V_26 -> V_28 . V_30 = 0xffffffff ;
}
return & V_4 ;
}
