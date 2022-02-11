static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
if ( ! ( V_4 & V_5 ) )
return 0 ;
F_2 () ;
V_3 = F_3 ( V_6 ) ;
if ( F_3 ( V_6 ) != V_7 ) {
F_4 ( & V_2 -> V_8 , L_1 ) ;
F_5 () ;
return - V_9 ;
}
V_3 = F_3 ( V_7 ) ;
F_5 () ;
return V_10 - V_3 ;
}
static int F_6 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
F_2 () ;
if ( ( V_2 -> V_11 . V_12 != V_13 ) || ( V_2 -> V_11 . V_14 != V_13 ) ) {
V_3 = F_3 ( V_15 ) ;
if ( V_3 != V_7 ) {
F_7 ( & V_2 -> V_8 , L_2 ) ;
V_4 &= ~ V_5 ;
V_16 |= V_5 ;
V_3 = - V_9 ;
}
} else
V_4 |= V_5 ;
if ( F_3 ( V_17 ) != V_7 ) {
F_7 ( & V_2 -> V_8 , L_3 ) ;
V_3 = - V_9 ;
goto V_18;
}
if ( F_3 ( V_10 - V_2 -> V_11 . V_19 )
!= V_7 ) {
F_4 ( & V_2 -> V_8 , L_4 ) ;
V_3 = - V_9 ;
}
V_18:
F_5 () ;
return V_3 ;
}
static int F_8 ( struct V_20 * V_21 )
{
struct V_22 V_11 ;
int V_3 ;
struct V_1 * V_2 ;
memset ( & V_11 , 0 , sizeof( struct V_22 ) ) ;
V_11 . type = V_23 ;
V_11 . V_24 = V_10 ;
V_2 = F_9 ( & V_21 -> V_8 , V_25 ,
& V_21 -> V_8 , NULL , & V_26 ,
& V_11 ) ;
if ( F_10 ( V_2 ) ) {
V_3 = F_11 ( V_2 ) ;
F_4 ( & V_21 -> V_8 , L_5 , V_3 ) ;
return V_3 ;
}
V_2 -> V_11 . V_12 = V_13 ;
V_2 -> V_11 . V_19 = V_27 ;
F_6 ( V_2 ) ;
F_12 ( V_21 , V_2 ) ;
F_7 ( & V_21 -> V_8 , L_6 ) ;
return 0 ;
}
