static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned int V_5 , unsigned int V_6 ,
unsigned int V_7 )
{
struct V_8 * V_9 = & V_4 -> V_10 . V_11 [ V_6 ] ;
int V_12 = sizeof( struct V_13 ) +
F_2 ( V_4 -> V_14 . V_15 . V_16 ) ;
if ( V_4 -> V_14 . V_15 . V_17 & V_18 ) {
F_3 ( V_2 -> V_19 , ~ ( V_20 ) 0 ) ;
V_12 = F_4 ( int , V_12 , V_9 -> V_21 - V_2 -> V_22 ) ;
goto V_23;
}
F_5 ( V_5 || V_6 || V_7 ) ;
F_6 ( & V_4 -> V_14 , V_2 , V_2 -> V_24 ) ;
F_7 ( V_4 ) ;
F_8 ( V_2 , V_2 -> V_24 , V_2 -> V_25 , & V_4 -> V_14 ,
V_26 ) ;
F_9 ( V_2 , F_10 ( V_4 -> V_14 . V_15 . V_27 ) ,
NULL ) ;
F_11 ( & V_4 -> V_14 ) ;
V_23:
return V_12 ;
}
static void F_12 ( struct V_28 * V_29 )
{
struct V_3 * V_4 = F_13 ( V_29 , struct V_3 , V_14 ) ;
F_14 ( V_4 ) ;
}
static int F_15 ( struct V_30 * V_31 )
{
return 0 ;
}
static int F_16 ( struct V_1 * V_2 , T_1 V_32 )
{
struct V_33 * V_34 ;
unsigned long V_35 ;
V_34 = F_17 ( sizeof( struct V_33 ) , V_32 ) ;
if ( ! V_34 )
return - V_36 ;
F_18 ( & V_34 -> V_37 ) ;
V_34 -> V_2 = V_2 ;
V_2 -> V_38 = V_34 ;
F_19 ( & V_39 , V_35 ) ;
F_20 ( & V_34 -> V_37 , & V_40 ) ;
F_21 ( & V_39 , V_35 ) ;
return 0 ;
}
static void F_22 ( void * V_41 )
{
struct V_33 * V_34 = V_41 ;
unsigned long V_35 ;
F_23 ( L_1 , V_34 ) ;
F_19 ( & V_39 , V_35 ) ;
F_24 ( & V_34 -> V_37 ) ;
F_21 ( & V_39 , V_35 ) ;
F_25 ( V_34 ) ;
}
static int F_26 ( struct V_30 * V_31 )
{
F_27 ( V_31 -> V_42 ) ;
return 0 ;
}
static void F_28 ( struct V_30 * V_31 )
{
}
void F_29 ( void )
{
struct V_33 * V_34 , * V_43 ;
F_30 ( V_44 ) ;
F_31 ( & V_39 ) ;
F_32 ( & V_40 , & V_44 ) ;
F_18 ( & V_40 ) ;
F_33 ( & V_39 ) ;
F_34 (lc, _lc, &tmp_list, loop_node) {
F_35 ( V_34 -> V_2 -> V_45 ) ;
F_36 ( V_34 -> V_2 ) ;
}
}
