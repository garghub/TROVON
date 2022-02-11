unsigned int
F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 ,
const struct V_5 * V_6 )
{
enum V_7 V_8 ;
struct V_9 V_10 ;
struct V_11 * V_12 ;
struct V_3 V_13 ;
V_12 = F_2 ( V_2 , & V_8 ) ;
F_3 ( V_12 && ( V_8 == V_14 || V_8 == V_15 ||
V_8 == V_16 ) ) ;
if ( F_4 ( F_5 ( V_12 ) , V_6 ,
& F_6 ( V_2 ) -> V_17 , 0 , & V_10 ) < 0 )
return V_18 ;
F_7 ( V_12 ) -> V_19 = V_6 -> V_20 ;
V_13 . V_21 = V_4 -> V_21 | V_22 ;
V_13 . V_23 . V_24 = V_10 ;
V_13 . V_25 . V_24 = V_10 ;
V_13 . V_26 = V_4 -> V_26 ;
V_13 . V_27 = V_4 -> V_27 ;
return F_8 ( V_12 , & V_13 , V_28 ) ;
}
static int F_9 ( struct V_11 * V_12 , void * V_20 )
{
const struct V_29 * V_30 = F_7 ( V_12 ) ;
if ( ! V_30 )
return 0 ;
if ( F_10 ( V_12 ) != V_31 )
return 0 ;
return V_30 -> V_19 == ( int ) ( long ) V_20 ;
}
static int F_11 ( struct V_32 * V_33 ,
unsigned long V_34 , void * V_35 )
{
const struct V_5 * V_36 = F_12 ( V_35 ) ;
struct V_37 * V_37 = F_13 ( V_36 ) ;
if ( V_34 == V_38 )
F_14 ( V_37 , F_9 ,
( void * ) ( long ) V_36 -> V_20 , 0 , 0 ) ;
return V_39 ;
}
static void F_15 ( struct V_40 * V_41 )
{
struct V_42 * V_43 ;
long V_44 ;
V_43 = F_16 ( V_41 , struct V_42 , V_41 ) ;
V_44 = V_43 -> V_20 ;
F_14 ( V_43 -> V_37 , F_9 , ( void * ) V_44 , 0 , 0 ) ;
F_17 ( V_43 -> V_37 ) ;
F_18 ( V_43 ) ;
F_19 ( & V_45 ) ;
F_20 ( V_46 ) ;
}
static int F_21 ( struct V_32 * V_33 ,
unsigned long V_34 , void * V_35 )
{
struct V_47 * V_48 = V_35 ;
const struct V_5 * V_36 ;
struct V_42 * V_43 ;
struct V_37 * V_37 ;
if ( V_34 != V_38 ||
F_22 ( & V_45 ) >= V_49 )
return V_39 ;
V_36 = V_48 -> V_50 -> V_36 ;
V_37 = F_23 ( F_13 ( V_36 ) ) ;
if ( ! V_37 )
return V_39 ;
if ( ! F_24 ( V_46 ) )
goto V_51;
V_43 = F_25 ( sizeof( * V_43 ) , V_52 ) ;
if ( V_43 ) {
F_26 ( & V_45 ) ;
F_27 ( & V_43 -> V_41 , F_15 ) ;
V_43 -> V_20 = V_36 -> V_20 ;
V_43 -> V_37 = V_37 ;
F_28 ( & V_43 -> V_41 ) ;
return V_39 ;
}
F_20 ( V_46 ) ;
V_51:
F_17 ( V_37 ) ;
return V_39 ;
}
void F_29 ( void )
{
if ( F_30 ( & V_53 ) > 1 )
return;
F_31 ( & V_54 ) ;
F_32 ( & V_55 ) ;
}
void F_33 ( void )
{
if ( F_34 ( & V_53 ) > 0 )
return;
F_35 ( & V_55 ) ;
F_36 ( & V_54 ) ;
}
