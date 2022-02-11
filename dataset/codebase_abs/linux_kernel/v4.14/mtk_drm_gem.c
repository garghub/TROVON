static struct V_1 * F_1 ( struct V_2 * V_3 ,
unsigned long V_4 )
{
struct V_1 * V_5 ;
int V_6 ;
V_4 = F_2 ( V_4 , V_7 ) ;
V_5 = F_3 ( sizeof( * V_5 ) , V_8 ) ;
if ( ! V_5 )
return F_4 ( - V_9 ) ;
V_6 = F_5 ( V_3 , & V_5 -> V_10 , V_4 ) ;
if ( V_6 < 0 ) {
F_6 ( L_1 ) ;
F_7 ( V_5 ) ;
return F_4 ( V_6 ) ;
}
return V_5 ;
}
struct V_1 * F_8 ( struct V_2 * V_3 ,
T_1 V_4 , bool V_11 )
{
struct V_12 * V_13 = V_3 -> V_14 ;
struct V_1 * V_15 ;
struct V_16 * V_17 ;
int V_6 ;
V_15 = F_1 ( V_3 , V_4 ) ;
if ( F_9 ( V_15 ) )
return F_10 ( V_15 ) ;
V_17 = & V_15 -> V_10 ;
V_15 -> V_18 = V_19 ;
if ( ! V_11 )
V_15 -> V_18 |= V_20 ;
V_15 -> V_21 = F_11 ( V_13 -> V_22 , V_17 -> V_4 ,
& V_15 -> V_23 , V_8 ,
V_15 -> V_18 ) ;
if ( ! V_15 -> V_21 ) {
F_6 ( L_2 , V_17 -> V_4 ) ;
V_6 = - V_9 ;
goto V_24;
}
if ( V_11 )
V_15 -> V_25 = V_15 -> V_21 ;
F_12 ( L_3 ,
V_15 -> V_21 , & V_15 -> V_23 ,
V_4 ) ;
return V_15 ;
V_24:
F_13 ( V_17 ) ;
F_7 ( V_15 ) ;
return F_4 ( V_6 ) ;
}
void F_14 ( struct V_16 * V_17 )
{
struct V_1 * V_15 = F_15 ( V_17 ) ;
struct V_12 * V_13 = V_17 -> V_3 -> V_14 ;
if ( V_15 -> V_26 )
F_16 ( V_17 , V_15 -> V_26 ) ;
else
F_17 ( V_13 -> V_22 , V_17 -> V_4 , V_15 -> V_21 ,
V_15 -> V_23 , V_15 -> V_18 ) ;
F_13 ( V_17 ) ;
F_7 ( V_15 ) ;
}
int F_18 ( struct V_27 * V_28 , struct V_2 * V_3 ,
struct V_29 * args )
{
struct V_1 * V_15 ;
int V_6 ;
args -> V_30 = F_19 ( args -> V_31 * args -> V_32 , 8 ) ;
args -> V_4 = args -> V_30 * args -> V_33 ;
V_15 = F_8 ( V_3 , args -> V_4 , false ) ;
if ( F_9 ( V_15 ) )
return F_20 ( V_15 ) ;
V_6 = F_21 ( V_28 , & V_15 -> V_10 , & args -> V_34 ) ;
if ( V_6 )
goto V_35;
F_22 ( & V_15 -> V_10 ) ;
return 0 ;
V_35:
F_14 ( & V_15 -> V_10 ) ;
return V_6 ;
}
static int F_23 ( struct V_16 * V_17 ,
struct V_36 * V_37 )
{
int V_6 ;
struct V_1 * V_15 = F_15 ( V_17 ) ;
struct V_12 * V_13 = V_17 -> V_3 -> V_14 ;
V_37 -> V_38 &= ~ V_39 ;
V_37 -> V_40 = 0 ;
V_6 = F_24 ( V_13 -> V_22 , V_37 , V_15 -> V_21 ,
V_15 -> V_23 , V_17 -> V_4 , V_15 -> V_18 ) ;
if ( V_6 )
F_25 ( V_37 ) ;
return V_6 ;
}
int F_26 ( struct V_16 * V_17 , struct V_36 * V_37 )
{
int V_6 ;
V_6 = F_27 ( V_17 , V_17 -> V_4 , V_37 ) ;
if ( V_6 )
return V_6 ;
return F_23 ( V_17 , V_37 ) ;
}
int F_28 ( struct V_41 * V_42 , struct V_36 * V_37 )
{
struct V_16 * V_17 ;
int V_6 ;
V_6 = F_29 ( V_42 , V_37 ) ;
if ( V_6 )
return V_6 ;
V_17 = V_37 -> V_43 ;
return F_23 ( V_17 , V_37 ) ;
}
struct V_44 * F_30 ( struct V_16 * V_17 )
{
struct V_1 * V_15 = F_15 ( V_17 ) ;
struct V_12 * V_13 = V_17 -> V_3 -> V_14 ;
struct V_44 * V_45 ;
int V_6 ;
V_45 = F_3 ( sizeof( * V_45 ) , V_8 ) ;
if ( ! V_45 )
return F_4 ( - V_9 ) ;
V_6 = F_31 ( V_13 -> V_22 , V_45 , V_15 -> V_21 ,
V_15 -> V_23 , V_17 -> V_4 ,
V_15 -> V_18 ) ;
if ( V_6 ) {
F_6 ( L_4 , V_6 ) ;
F_7 ( V_45 ) ;
return F_4 ( V_6 ) ;
}
return V_45 ;
}
struct V_16 * F_32 ( struct V_2 * V_3 ,
struct V_46 * V_47 , struct V_44 * V_26 )
{
struct V_1 * V_15 ;
int V_6 ;
struct V_48 * V_49 ;
unsigned int V_50 ;
T_2 V_51 ;
V_15 = F_1 ( V_3 , V_47 -> V_52 -> V_4 ) ;
if ( F_9 ( V_15 ) )
return F_4 ( F_20 ( V_15 ) ) ;
V_51 = F_33 ( V_26 -> V_53 ) ;
F_34 (sg->sgl, s, sg->nents, i) {
if ( F_33 ( V_49 ) != V_51 ) {
F_6 ( L_5 ) ;
V_6 = - V_54 ;
goto V_24;
}
V_51 = F_33 ( V_49 ) + F_35 ( V_49 ) ;
}
V_15 -> V_23 = F_33 ( V_26 -> V_53 ) ;
V_15 -> V_26 = V_26 ;
return & V_15 -> V_10 ;
V_24:
F_7 ( V_15 ) ;
return F_4 ( V_6 ) ;
}
