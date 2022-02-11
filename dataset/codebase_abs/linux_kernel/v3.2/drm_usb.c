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
V_8 -> V_8 = & V_10 -> V_8 ;
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
V_11 = F_9 ( V_8 , & V_8 -> V_19 , V_20 ) ;
if ( V_11 )
goto V_21;
if ( V_8 -> V_6 -> V_22 ) {
V_11 = V_8 -> V_6 -> V_22 ( V_8 , 0 ) ;
if ( V_11 )
goto V_23;
}
V_11 = F_10 ( V_8 ,
& V_8 -> V_19 -> V_24 ) ;
if ( V_11 )
goto V_23;
F_11 ( & V_8 -> V_25 , & V_6 -> V_26 ) ;
F_12 ( & V_14 ) ;
F_13 ( L_3 ,
V_6 -> V_27 , V_6 -> V_28 , V_6 -> V_29 , V_6 -> V_30 ,
V_6 -> V_31 , V_8 -> V_19 -> V_32 ) ;
return 0 ;
V_23:
F_14 ( & V_8 -> V_19 ) ;
V_21:
F_14 ( & V_8 -> V_17 ) ;
V_16:
F_15 ( V_8 ) ;
F_12 ( & V_14 ) ;
return V_11 ;
}
static int F_16 ( struct V_7 * V_8 )
{
return 0 ;
}
static const char * F_17 ( struct V_7 * V_8 )
{
return L_4 ;
}
static int F_18 ( struct V_7 * V_8 ,
struct V_33 * V_34 )
{
return 0 ;
}
int F_19 ( struct V_5 * V_6 , struct V_35 * V_36 )
{
int V_37 ;
F_2 ( L_1 ) ;
F_20 ( & V_6 -> V_26 ) ;
V_6 -> V_38 . V_39 = V_36 ;
V_6 -> V_40 = & V_41 ;
V_37 = F_21 ( V_36 ) ;
return V_37 ;
}
void F_22 ( struct V_5 * V_6 ,
struct V_35 * V_36 )
{
F_23 ( V_36 ) ;
}
