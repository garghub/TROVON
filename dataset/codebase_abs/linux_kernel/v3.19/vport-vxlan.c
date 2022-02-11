static inline struct V_1 * F_1 ( const struct V_2 * V_2 )
{
return F_2 ( V_2 ) ;
}
static void F_3 ( struct V_3 * V_4 , struct V_5 * V_6 , T_1 V_7 )
{
struct V_8 V_9 ;
struct V_2 * V_2 = V_4 -> V_10 ;
struct V_11 * V_12 ;
T_2 V_13 ;
V_12 = F_4 ( V_6 ) ;
V_13 = F_5 ( F_6 ( V_7 ) >> 8 ) ;
F_7 ( & V_9 , V_12 ,
F_8 ( V_6 ) -> V_14 , F_8 ( V_6 ) -> V_15 ,
V_13 , V_16 , NULL , 0 ) ;
F_9 ( V_2 , V_6 , & V_9 ) ;
}
static int F_10 ( const struct V_2 * V_2 , struct V_5 * V_6 )
{
struct V_1 * V_1 = F_1 ( V_2 ) ;
T_3 V_17 = F_11 ( V_1 -> V_4 -> V_18 -> V_19 ) -> V_20 ;
if ( F_12 ( V_6 , V_21 , F_13 ( V_17 ) ) )
return - V_22 ;
return 0 ;
}
static void F_14 ( struct V_2 * V_2 )
{
struct V_1 * V_1 = F_1 ( V_2 ) ;
F_15 ( V_1 -> V_4 ) ;
F_16 ( V_2 ) ;
}
static struct V_2 * F_17 ( const struct V_23 * V_24 )
{
struct V_25 * V_25 = F_18 ( V_24 -> V_26 ) ;
struct V_27 * V_28 = V_24 -> V_28 ;
struct V_1 * V_1 ;
struct V_3 * V_4 ;
struct V_2 * V_2 ;
struct V_27 * V_29 ;
T_4 V_17 ;
int V_30 ;
if ( ! V_28 ) {
V_30 = - V_31 ;
goto error;
}
V_29 = F_19 ( V_28 , V_21 ) ;
if ( V_29 && F_20 ( V_29 ) == sizeof( T_4 ) ) {
V_17 = F_21 ( V_29 ) ;
} else {
V_30 = - V_31 ;
goto error;
}
V_2 = F_22 ( sizeof( struct V_1 ) ,
& V_32 , V_24 ) ;
if ( F_23 ( V_2 ) )
return V_2 ;
V_1 = F_1 ( V_2 ) ;
strncpy ( V_1 -> V_33 , V_24 -> V_33 , V_34 ) ;
V_4 = F_24 ( V_25 , F_25 ( V_17 ) , F_3 , V_2 , true , 0 ) ;
if ( F_23 ( V_4 ) ) {
F_26 ( V_2 ) ;
return ( void * ) V_4 ;
}
V_1 -> V_4 = V_4 ;
return V_2 ;
error:
return F_27 ( V_30 ) ;
}
static int F_28 ( struct V_2 * V_2 , struct V_5 * V_6 )
{
struct V_25 * V_25 = F_18 ( V_2 -> V_26 ) ;
struct V_1 * V_1 = F_1 ( V_2 ) ;
T_3 V_17 = F_11 ( V_1 -> V_4 -> V_18 -> V_19 ) -> V_20 ;
struct V_35 * V_36 ;
struct V_37 * V_38 ;
struct V_39 V_40 ;
T_3 V_41 ;
T_3 V_42 ;
int V_30 ;
if ( F_29 ( ! F_30 ( V_6 ) -> V_43 ) ) {
V_30 = - V_31 ;
goto error;
}
V_36 = & F_30 ( V_6 ) -> V_43 -> V_44 ;
memset ( & V_40 , 0 , sizeof( V_40 ) ) ;
V_40 . V_45 = V_36 -> V_46 ;
V_40 . V_47 = V_36 -> V_48 ;
V_40 . V_49 = F_31 ( V_36 -> V_50 ) ;
V_40 . V_51 = V_6 -> V_52 ;
V_40 . V_53 = V_54 ;
V_38 = F_32 ( V_25 , & V_40 ) ;
if ( F_23 ( V_38 ) ) {
V_30 = F_33 ( V_38 ) ;
goto error;
}
V_42 = V_36 -> V_55 & V_56 ?
F_25 ( V_57 ) : 0 ;
V_6 -> V_58 = 1 ;
V_41 = F_34 ( V_25 , V_6 , 0 , 0 , true ) ;
V_30 = F_35 ( V_1 -> V_4 , V_38 , V_6 ,
V_40 . V_47 , V_36 -> V_46 ,
V_36 -> V_50 , V_36 -> V_59 , V_42 ,
V_41 , V_17 ,
F_36 ( F_37 ( V_36 -> V_60 ) << 8 ) ,
false ) ;
if ( V_30 < 0 )
F_38 ( V_38 ) ;
return V_30 ;
error:
F_39 ( V_6 ) ;
return V_30 ;
}
static int F_40 ( struct V_2 * V_2 , struct V_5 * V_6 ,
struct V_8 * V_43 )
{
struct V_25 * V_25 = F_18 ( V_2 -> V_26 ) ;
struct V_1 * V_1 = F_1 ( V_2 ) ;
T_3 V_17 = F_11 ( V_1 -> V_4 -> V_18 -> V_19 ) -> V_20 ;
T_3 V_41 ;
int V_61 ;
int V_62 ;
F_41 ( V_25 , & V_61 , & V_62 ) ;
V_41 = F_34 ( V_25 , V_6 , 0 , 0 , true ) ;
return F_42 ( V_43 , V_25 ,
F_30 ( V_6 ) -> V_43 ,
V_54 , V_6 -> V_52 ,
V_41 , V_17 ) ;
}
static const char * F_43 ( const struct V_2 * V_2 )
{
struct V_1 * V_1 = F_1 ( V_2 ) ;
return V_1 -> V_33 ;
}
static int T_5 F_44 ( void )
{
return F_45 ( & V_32 ) ;
}
static void T_6 F_46 ( void )
{
F_47 ( & V_32 ) ;
}
