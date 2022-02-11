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
V_26 , V_27 ) ;
F_9 ( V_2 , F_10 ( V_4 -> V_14 . V_15 . V_28 ) ,
NULL ) ;
F_11 ( & V_4 -> V_14 ) ;
V_23:
return V_12 ;
}
static void F_12 ( struct V_29 * V_30 )
{
struct V_3 * V_4 = F_13 ( V_30 , struct V_3 , V_14 ) ;
F_14 ( V_4 ) ;
}
static int F_15 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_16 ( struct V_1 * V_2 , T_1 V_31 )
{
struct V_32 * V_33 ;
unsigned long V_34 ;
V_33 = F_17 ( sizeof( struct V_32 ) , V_26 ) ;
if ( ! V_33 )
return - V_35 ;
F_18 ( & V_33 -> V_36 ) ;
V_33 -> V_2 = V_2 ;
V_2 -> V_37 = V_33 ;
F_19 ( & V_38 , V_34 ) ;
F_20 ( & V_33 -> V_36 , & V_39 ) ;
F_21 ( & V_38 , V_34 ) ;
return 0 ;
}
static void F_22 ( void * V_40 )
{
struct V_32 * V_33 = V_40 ;
unsigned long V_34 ;
F_23 ( L_1 , V_33 ) ;
F_19 ( & V_38 , V_34 ) ;
F_24 ( & V_33 -> V_36 ) ;
F_21 ( & V_38 , V_34 ) ;
F_25 ( V_33 ) ;
}
static int F_26 ( struct V_1 * V_2 )
{
F_27 ( V_2 ) ;
return 0 ;
}
static void F_28 ( struct V_1 * V_2 )
{
}
void F_29 ( void )
{
struct V_32 * V_33 , * V_41 ;
F_30 ( V_42 ) ;
F_31 ( & V_38 ) ;
F_32 ( & V_39 , & V_42 ) ;
F_18 ( & V_39 ) ;
F_33 ( & V_38 ) ;
F_34 (lc, _lc, &tmp_list, loop_node) {
F_35 ( V_33 -> V_2 -> V_43 ) ;
F_36 ( V_33 -> V_2 ) ;
}
}
