static int F_1 ( struct V_1 * V_2 )
{
struct V_3 V_4 ;
struct V_5 V_6 ;
int V_7 ;
memset ( & V_4 , 0 , sizeof( V_4 ) ) ;
memset ( & V_6 , 0 , sizeof( V_6 ) ) ;
V_4 . V_8 . V_9 = V_10 ;
V_4 . V_8 . V_11 = V_12 ;
V_4 . V_13 = V_14 ;
V_7 = F_2 ( V_2 -> V_15 -> V_16 , & V_4 ,
& V_6 ) ;
if ( V_7 )
return V_7 ;
V_2 -> V_17 = V_6 . V_17 ;
return 0 ;
}
struct V_1 * F_3 ( struct V_18 * V_15 )
{
struct V_1 * V_2 ;
int V_19 ;
V_2 = F_4 ( sizeof( * V_2 ) , V_20 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_15 = V_15 ;
V_2 -> V_21 = 800 ;
if ( F_1 ( V_2 ) )
goto V_22;
V_19 = F_5 ( V_2 ) ;
if ( V_19 ) {
F_6 ( L_1 , V_19 ) ;
goto V_22;
}
if ( F_7 ( V_2 ) )
goto V_23;
V_2 -> V_24 =
36 +
4 +
8 +
2 ;
return V_2 ;
V_23:
F_8 ( V_2 ) ;
V_22:
F_9 ( V_2 ) ;
return NULL ;
}
static int F_10 ( struct V_1 * V_2 )
{
F_11 ( V_25 ,
L_2 ,
V_2 -> V_26 ,
V_2 -> V_27 ,
V_28 ,
V_29 ) ;
if ( V_2 -> V_26 != V_28 ) {
F_6 ( L_3 ) ;
return - V_30 ;
}
if ( V_2 -> V_27 != V_29 )
F_12 ( L_4 ) ;
return 0 ;
}
int F_13 ( struct V_1 * V_2 )
{
int V_7 ;
F_14 ( & V_2 -> V_31 ) ;
V_7 = F_15 ( V_2 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_16 ( & V_2 -> V_31 ,
V_32 ) ;
if ( V_7 <= 0 ) {
F_12 ( L_5 ) ;
return - V_33 ;
}
V_7 = F_10 ( V_2 ) ;
if ( V_7 )
return V_7 ;
return F_17 ( V_2 ) ;
}
void F_18 ( struct V_1 * V_2 )
{
F_19 ( V_2 ) ;
F_8 ( V_2 ) ;
F_9 ( V_2 ) ;
}
