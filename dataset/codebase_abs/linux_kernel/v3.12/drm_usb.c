int F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_7 * V_8 ;
struct V_9 * V_10 ;
int V_11 ;
F_2 ( L_1 ) ;
V_8 = F_3 ( sizeof( * V_8 ) , V_12 ) ;
if ( ! V_8 )
return - V_13 ;
V_10 = F_4 ( V_2 ) ;
V_8 -> V_10 = V_10 ;
V_8 -> V_8 = & V_2 -> V_8 ;
F_5 ( & V_14 ) ;
V_11 = F_6 ( V_8 , NULL , V_6 ) ;
if ( V_11 ) {
F_7 ( V_15 L_2 ) ;
goto V_16;
}
F_8 ( V_2 , V_8 ) ;
V_11 = F_9 ( V_8 , & V_8 -> V_17 , V_18 ) ;
if ( V_11 )
goto V_16;
if ( F_10 ( V_8 , V_19 ) && V_20 ) {
V_11 = F_9 ( V_8 , & V_8 -> V_21 , V_22 ) ;
if ( V_11 )
goto V_23;
}
V_11 = F_9 ( V_8 , & V_8 -> V_24 , V_25 ) ;
if ( V_11 )
goto V_26;
if ( V_8 -> V_6 -> V_27 ) {
V_11 = V_8 -> V_6 -> V_27 ( V_8 , 0 ) ;
if ( V_11 )
goto V_28;
}
V_11 = F_11 ( V_8 ,
& V_8 -> V_24 -> V_29 ) ;
if ( V_11 )
goto V_28;
F_12 ( & V_8 -> V_30 , & V_6 -> V_31 ) ;
F_13 ( & V_14 ) ;
F_14 ( L_3 ,
V_6 -> V_32 , V_6 -> V_33 , V_6 -> V_34 , V_6 -> V_35 ,
V_6 -> V_36 , V_8 -> V_24 -> V_37 ) ;
return 0 ;
V_28:
F_15 ( & V_8 -> V_24 ) ;
V_26:
if ( V_8 -> V_21 )
F_15 ( & V_8 -> V_21 ) ;
V_23:
F_15 ( & V_8 -> V_17 ) ;
V_16:
F_16 ( V_8 ) ;
F_13 ( & V_14 ) ;
return V_11 ;
}
static int F_17 ( struct V_7 * V_8 )
{
return 0 ;
}
static const char * F_18 ( struct V_7 * V_8 )
{
return L_4 ;
}
static int F_19 ( struct V_7 * V_8 ,
struct V_38 * V_39 )
{
return 0 ;
}
int F_20 ( struct V_5 * V_6 , struct V_40 * V_41 )
{
int V_42 ;
F_2 ( L_1 ) ;
F_21 ( & V_6 -> V_31 ) ;
V_6 -> V_43 . V_44 = V_41 ;
V_6 -> V_45 = & V_46 ;
V_42 = F_22 ( V_41 ) ;
return V_42 ;
}
void F_23 ( struct V_5 * V_6 ,
struct V_40 * V_41 )
{
F_24 ( V_41 ) ;
}
