struct V_1 * F_1 ( struct V_2 * V_3 )
{
if ( F_2 ( V_3 ) ) {
struct V_4 * V_5 = F_3 ( V_3 ) ;
return V_5 -> V_6 ;
}
if ( F_4 ( V_3 ) ) {
struct V_7 * V_8 = F_3 ( V_3 ) ;
return V_8 -> V_6 ;
}
F_5 ( 1 , L_1 ) ;
return NULL ;
}
const char * F_6 ( struct V_1 * V_6 )
{
if ( ! V_6 || ! V_6 -> V_9 -> V_10 )
return L_2 ;
return F_7 ( V_6 -> V_9 -> V_10 ) ;
}
struct V_11 *
F_8 ( struct V_1 * V_6 , unsigned int V_12 , T_1 V_13 )
{
struct V_11 * V_14 ;
if ( F_9 ( V_6 ) )
V_12 += 8 ;
V_14 = F_10 ( V_12 , V_13 ) ;
if ( ! V_14 )
return NULL ;
if ( F_9 ( V_6 ) )
F_11 ( V_14 , 8 ) ;
return V_14 ;
}
struct V_15 *
F_12 ( struct V_1 * V_6 , enum V_16 type ,
struct V_15 * V_17 )
{
struct V_15 * V_18 ;
V_18 = F_13 ( V_6 -> V_17 [ type ] ,
F_14 ( & V_6 -> V_9 -> V_19 ) ) ;
if ( V_17 && V_18 ) {
V_18 = F_15 ( - V_20 ) ;
goto V_21;
}
F_16 ( V_6 -> V_17 [ type ] , V_17 ) ;
V_21:
return V_18 ;
}
struct V_1 * F_17 ( struct V_22 * V_9 , enum V_23 V_24 )
{
struct V_1 * V_6 ;
unsigned int V_25 ;
for ( V_25 = 0 ; V_25 < F_18 ( V_26 ) ; V_25 ++ )
if ( V_26 [ V_25 ] -> V_24 == V_24 )
break;
if ( V_25 == F_18 ( V_26 ) ) {
F_19 ( V_9 -> V_27 , L_3 , V_24 ) ;
return F_15 ( - V_28 ) ;
}
if ( F_20 ( ! V_26 [ V_25 ] -> V_29 || ! V_26 [ V_25 ] -> V_30 ) )
return F_15 ( - V_28 ) ;
V_6 = F_21 ( sizeof( * V_6 ) , V_31 ) ;
if ( ! V_6 )
return F_15 ( - V_32 ) ;
V_6 -> V_9 = V_9 ;
V_6 -> V_27 = V_9 -> V_27 ;
V_6 -> V_33 = V_9 -> V_33 ;
V_6 -> type = V_26 [ V_25 ] ;
return V_6 ;
}
void F_22 ( struct V_1 * V_6 )
{
F_23 ( V_6 ) ;
}
