const char * F_1 ( struct V_1 * V_2 )
{
if ( ! V_2 || ! V_2 -> V_3 -> V_4 )
return L_1 ;
return F_2 ( V_2 -> V_3 -> V_4 ) ;
}
struct V_5 *
F_3 ( struct V_1 * V_2 , unsigned int V_6 , T_1 V_7 )
{
struct V_5 * V_8 ;
if ( F_4 ( V_2 ) )
V_6 += 8 ;
V_8 = F_5 ( V_6 , V_7 ) ;
if ( ! V_8 )
return NULL ;
if ( F_4 ( V_2 ) )
F_6 ( V_8 , 8 ) ;
return V_8 ;
}
struct V_9 *
F_7 ( struct V_1 * V_2 , enum V_10 type ,
struct V_9 * V_11 )
{
struct V_9 * V_12 ;
V_12 = F_8 ( V_2 -> V_11 [ type ] ,
F_9 ( & V_2 -> V_3 -> V_13 ) ) ;
if ( V_11 && V_12 ) {
V_12 = F_10 ( - V_14 ) ;
goto V_15;
}
F_11 ( V_2 -> V_11 [ type ] , V_11 ) ;
V_15:
return V_12 ;
}
struct V_1 * F_12 ( struct V_16 * V_3 , enum V_17 V_18 )
{
struct V_1 * V_2 ;
unsigned int V_19 ;
for ( V_19 = 0 ; V_19 < F_13 ( V_20 ) ; V_19 ++ )
if ( V_20 [ V_19 ] -> V_18 == V_18 )
break;
if ( V_19 == F_13 ( V_20 ) ) {
F_14 ( V_3 -> V_21 , L_2 , V_18 ) ;
return F_10 ( - V_22 ) ;
}
if ( F_15 ( ! V_20 [ V_19 ] -> V_23 || ! V_20 [ V_19 ] -> V_24 ) )
return F_10 ( - V_22 ) ;
V_2 = F_16 ( sizeof( * V_2 ) , V_25 ) ;
if ( ! V_2 )
return F_10 ( - V_26 ) ;
V_2 -> V_3 = V_3 ;
V_2 -> V_21 = V_3 -> V_21 ;
V_2 -> V_27 = V_3 -> V_27 ;
V_2 -> type = V_20 [ V_19 ] ;
return V_2 ;
}
void F_17 ( struct V_1 * V_2 )
{
F_18 ( V_2 ) ;
}
