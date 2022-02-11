static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
if ( ! ( V_4 & V_5 ) )
return 0 ;
F_2 () ;
V_3 = F_3 ( V_6 ) ;
if ( F_3 ( V_6 ) != V_7 ) {
F_4 ( L_1 ) ;
F_5 () ;
return - V_8 ;
} else
V_3 = F_3 ( V_7 ) ;
F_5 () ;
return V_9 - V_3 ;
}
static int F_6 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
F_2 () ;
if ( ( V_2 -> V_10 . V_11 != V_12 ) || ( V_2 -> V_10 . V_13 != V_12 ) ) {
V_3 = F_3 ( V_14 ) ;
if ( V_3 != V_7 ) {
F_7 ( L_2 ) ;
V_4 &= ~ V_5 ;
V_15 |= V_5 ;
V_3 = - V_8 ;
}
} else
V_4 |= V_5 ;
if ( F_3 ( V_16 ) != V_7 ) {
F_7 ( L_3 ) ;
V_3 = - V_8 ;
goto V_17;
}
if ( F_3 ( V_9 - V_2 -> V_10 . V_18 )
!= V_7 ) {
F_4 ( L_4 ) ;
V_3 = - V_8 ;
}
V_17:
F_5 () ;
return V_3 ;
}
static int F_8 ( struct V_19 * V_20 )
{
struct V_21 V_10 ;
int V_3 ;
struct V_1 * V_2 ;
memset ( & V_10 , 0 , sizeof( struct V_21 ) ) ;
V_10 . type = V_22 ;
V_10 . V_23 = V_9 ;
V_2 = F_9 ( V_24 , & V_20 -> V_25 , NULL ,
& V_26 , & V_10 ) ;
if ( F_10 ( V_2 ) ) {
V_3 = F_11 ( V_2 ) ;
F_4 ( L_5 , V_3 ) ;
return V_3 ;
}
V_2 -> V_10 . V_11 = V_12 ;
V_2 -> V_10 . V_18 = V_27 ;
F_6 ( V_2 ) ;
F_12 ( V_20 , V_2 ) ;
F_7 ( L_6 ) ;
return 0 ;
}
static int F_13 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = F_14 ( V_20 ) ;
F_15 ( V_2 ) ;
return 0 ;
}
