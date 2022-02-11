unsigned int
F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 ,
const struct V_5 * V_6 )
{
enum V_7 V_8 ;
struct V_9 * V_10 ;
struct V_11 V_12 ;
struct V_13 * V_14 ;
struct V_3 V_15 ;
V_14 = F_2 ( V_2 , & V_8 ) ;
F_3 ( ! ( V_14 && ( V_8 == V_16 || V_8 == V_17 ||
V_8 == V_18 ) ) ) ;
if ( F_4 ( F_5 ( V_14 ) , V_6 ,
& F_6 ( V_2 ) -> V_19 , 0 , & V_12 ) < 0 )
return V_20 ;
V_10 = F_7 ( V_14 ) ;
if ( V_10 )
V_10 -> V_21 = V_6 -> V_22 ;
V_15 . V_23 = V_4 -> V_23 | V_24 ;
V_15 . V_25 . V_26 = V_12 ;
V_15 . V_27 . V_26 = V_12 ;
V_15 . V_28 = V_4 -> V_28 ;
V_15 . V_29 = V_4 -> V_29 ;
return F_8 ( V_14 , & V_15 , V_30 ) ;
}
static int F_9 ( struct V_13 * V_14 , void * V_22 )
{
const struct V_9 * V_10 = F_10 ( V_14 ) ;
if ( ! V_10 )
return 0 ;
if ( F_11 ( V_14 ) != V_31 )
return 0 ;
return V_10 -> V_21 == ( int ) ( long ) V_22 ;
}
static int F_12 ( struct V_32 * V_33 ,
unsigned long V_34 , void * V_35 )
{
const struct V_5 * V_36 = F_13 ( V_35 ) ;
struct V_37 * V_37 = F_14 ( V_36 ) ;
if ( V_34 == V_38 )
F_15 ( V_37 , F_9 ,
( void * ) ( long ) V_36 -> V_22 , 0 , 0 ) ;
return V_39 ;
}
static void F_16 ( struct V_40 * V_41 )
{
struct V_42 * V_43 ;
long V_44 ;
V_43 = F_17 ( V_41 , struct V_42 , V_41 ) ;
V_44 = V_43 -> V_22 ;
F_15 ( V_43 -> V_37 , F_9 , ( void * ) V_44 , 0 , 0 ) ;
F_18 ( V_43 -> V_37 ) ;
F_19 ( V_43 ) ;
F_20 ( & V_45 ) ;
F_21 ( V_46 ) ;
}
static int F_22 ( struct V_32 * V_33 ,
unsigned long V_34 , void * V_35 )
{
struct V_47 * V_48 = V_35 ;
const struct V_5 * V_36 ;
struct V_42 * V_43 ;
struct V_37 * V_37 ;
if ( V_34 != V_38 ||
F_23 ( & V_45 ) >= V_49 )
return V_39 ;
V_36 = V_48 -> V_50 -> V_36 ;
V_37 = F_24 ( F_14 ( V_36 ) ) ;
if ( ! V_37 )
return V_39 ;
if ( ! F_25 ( V_46 ) )
goto V_51;
V_43 = F_26 ( sizeof( * V_43 ) , V_52 ) ;
if ( V_43 ) {
F_27 ( & V_45 ) ;
F_28 ( & V_43 -> V_41 , F_16 ) ;
V_43 -> V_22 = V_36 -> V_22 ;
V_43 -> V_37 = V_37 ;
F_29 ( & V_43 -> V_41 ) ;
return V_39 ;
}
F_21 ( V_46 ) ;
V_51:
F_18 ( V_37 ) ;
return V_39 ;
}
void F_30 ( void )
{
if ( F_31 ( & V_53 ) > 1 )
return;
F_32 ( & V_54 ) ;
F_33 ( & V_55 ) ;
}
void F_34 ( void )
{
if ( F_35 ( & V_53 ) > 0 )
return;
F_36 ( & V_55 ) ;
F_37 ( & V_54 ) ;
}
