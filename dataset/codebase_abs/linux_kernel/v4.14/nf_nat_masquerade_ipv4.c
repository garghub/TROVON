unsigned int
F_1 ( struct V_1 * V_2 , unsigned int V_3 ,
const struct V_4 * V_5 ,
const struct V_6 * V_7 )
{
struct V_8 * V_9 ;
struct V_10 * V_11 ;
enum V_12 V_13 ;
struct V_4 V_14 ;
const struct V_15 * V_16 ;
T_1 V_17 , V_18 ;
F_2 ( V_3 != V_19 ) ;
V_9 = F_3 ( V_2 , & V_13 ) ;
F_2 ( ! ( V_9 && ( V_13 == V_20 || V_13 == V_21 ||
V_13 == V_22 ) ) ) ;
if ( V_9 -> V_23 [ V_24 ] . V_25 . V_26 . V_27 . V_28 == 0 )
return V_29 ;
V_16 = F_4 ( V_2 ) ;
V_18 = F_5 ( V_16 , F_6 ( V_2 ) -> V_30 ) ;
V_17 = F_7 ( V_7 , V_18 , V_31 ) ;
if ( ! V_17 ) {
F_8 ( L_1 , V_7 -> V_32 ) ;
return V_33 ;
}
V_11 = F_9 ( V_9 ) ;
if ( V_11 )
V_11 -> V_34 = V_7 -> V_35 ;
memset ( & V_14 . V_36 , 0 , sizeof( V_14 . V_36 ) ) ;
memset ( & V_14 . V_37 , 0 , sizeof( V_14 . V_37 ) ) ;
V_14 . V_38 = V_5 -> V_38 | V_39 ;
V_14 . V_36 . V_28 = V_17 ;
V_14 . V_37 . V_28 = V_17 ;
V_14 . V_40 = V_5 -> V_40 ;
V_14 . V_41 = V_5 -> V_41 ;
return F_10 ( V_9 , & V_14 , V_42 ) ;
}
static int F_11 ( struct V_8 * V_43 , void * V_35 )
{
const struct V_10 * V_11 = F_12 ( V_43 ) ;
if ( ! V_11 )
return 0 ;
if ( F_13 ( V_43 ) != V_44 )
return 0 ;
return V_11 -> V_34 == ( int ) ( long ) V_35 ;
}
static int F_14 ( struct V_45 * V_46 ,
unsigned long V_47 ,
void * V_48 )
{
const struct V_6 * V_49 = F_15 ( V_48 ) ;
struct V_50 * V_50 = F_16 ( V_49 ) ;
if ( V_47 == V_51 ) {
F_2 ( V_49 -> V_35 == 0 ) ;
F_17 ( V_50 , F_11 ,
( void * ) ( long ) V_49 -> V_35 , 0 , 0 ) ;
}
return V_52 ;
}
static int F_18 ( struct V_45 * V_46 ,
unsigned long V_47 ,
void * V_48 )
{
struct V_53 * V_54 = ( (struct V_55 * ) V_48 ) -> V_56 ;
struct V_57 V_58 ;
if ( V_54 -> V_59 )
return V_52 ;
F_19 ( & V_58 , V_54 -> V_49 ) ;
return F_14 ( V_46 , V_47 , & V_58 ) ;
}
void F_20 ( void )
{
if ( F_21 ( & V_60 ) > 1 )
return;
F_22 ( & V_61 ) ;
F_23 ( & V_62 ) ;
}
void F_24 ( void )
{
if ( F_25 ( & V_60 ) > 0 )
return;
F_26 ( & V_61 ) ;
F_27 ( & V_62 ) ;
}
