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
F_7 ( & V_9 , V_12 , V_13 , V_14 , NULL , 0 ) ;
F_8 ( V_2 , V_6 , & V_9 ) ;
}
static int F_9 ( const struct V_2 * V_2 , struct V_5 * V_6 )
{
struct V_1 * V_1 = F_1 ( V_2 ) ;
T_3 V_15 = F_10 ( V_1 -> V_4 -> V_16 -> V_17 ) -> V_18 ;
if ( F_11 ( V_6 , V_19 , F_12 ( V_15 ) ) )
return - V_20 ;
return 0 ;
}
static void F_13 ( struct V_2 * V_2 )
{
struct V_1 * V_1 = F_1 ( V_2 ) ;
F_14 ( V_1 -> V_4 ) ;
F_15 ( V_2 ) ;
}
static struct V_2 * F_16 ( const struct V_21 * V_22 )
{
struct V_23 * V_23 = F_17 ( V_22 -> V_24 ) ;
struct V_25 * V_26 = V_22 -> V_26 ;
struct V_1 * V_1 ;
struct V_3 * V_4 ;
struct V_2 * V_2 ;
struct V_25 * V_27 ;
T_4 V_15 ;
int V_28 ;
if ( ! V_26 ) {
V_28 = - V_29 ;
goto error;
}
V_27 = F_18 ( V_26 , V_19 ) ;
if ( V_27 && F_19 ( V_27 ) == sizeof( T_4 ) ) {
V_15 = F_20 ( V_27 ) ;
} else {
V_28 = - V_29 ;
goto error;
}
V_2 = F_21 ( sizeof( struct V_1 ) ,
& V_30 , V_22 ) ;
if ( F_22 ( V_2 ) )
return V_2 ;
V_1 = F_1 ( V_2 ) ;
strncpy ( V_1 -> V_31 , V_22 -> V_31 , V_32 ) ;
V_4 = F_23 ( V_23 , F_24 ( V_15 ) , F_3 , V_2 , true , 0 ) ;
if ( F_22 ( V_4 ) ) {
F_25 ( V_2 ) ;
return ( void * ) V_4 ;
}
V_1 -> V_4 = V_4 ;
return V_2 ;
error:
return F_26 ( V_28 ) ;
}
static int F_27 ( struct V_2 * V_2 , struct V_5 * V_6 )
{
struct V_23 * V_23 = F_17 ( V_2 -> V_24 ) ;
struct V_1 * V_1 = F_1 ( V_2 ) ;
T_3 V_15 = F_10 ( V_1 -> V_4 -> V_16 -> V_17 ) -> V_18 ;
struct V_33 * V_34 ;
struct V_35 * V_36 ;
struct V_37 V_38 ;
T_3 V_39 ;
T_3 V_40 ;
int V_28 ;
if ( F_28 ( ! F_29 ( V_6 ) -> V_41 ) ) {
V_28 = - V_29 ;
goto error;
}
V_34 = & F_29 ( V_6 ) -> V_41 -> V_42 ;
memset ( & V_38 , 0 , sizeof( V_38 ) ) ;
V_38 . V_43 = V_34 -> V_44 ;
V_38 . V_45 = V_34 -> V_46 ;
V_38 . V_47 = F_30 ( V_34 -> V_48 ) ;
V_38 . V_49 = V_6 -> V_50 ;
V_38 . V_51 = V_52 ;
V_36 = F_31 ( V_23 , & V_38 ) ;
if ( F_22 ( V_36 ) ) {
V_28 = F_32 ( V_36 ) ;
goto error;
}
V_40 = V_34 -> V_53 & V_54 ?
F_24 ( V_55 ) : 0 ;
V_6 -> V_56 = 1 ;
V_39 = F_33 ( V_23 , V_6 , 0 , 0 , true ) ;
V_28 = F_34 ( V_1 -> V_4 , V_36 , V_6 ,
V_38 . V_45 , V_34 -> V_44 ,
V_34 -> V_48 , V_34 -> V_57 , V_40 ,
V_39 , V_15 ,
F_35 ( F_36 ( V_34 -> V_58 ) << 8 ) ,
false ) ;
if ( V_28 < 0 )
F_37 ( V_36 ) ;
error:
return V_28 ;
}
static const char * F_38 ( const struct V_2 * V_2 )
{
struct V_1 * V_1 = F_1 ( V_2 ) ;
return V_1 -> V_31 ;
}
