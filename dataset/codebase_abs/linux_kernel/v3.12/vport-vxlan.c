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
F_7 ( & V_9 , V_12 , V_13 , V_14 ) ;
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
V_4 = F_23 ( V_23 , F_24 ( V_15 ) , F_3 , V_2 , true , false ) ;
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
struct V_35 V_36 ;
T_3 V_37 ;
int V_38 ;
int V_39 ;
T_3 V_40 ;
int V_28 ;
if ( F_28 ( ! F_29 ( V_6 ) -> V_9 ) ) {
V_28 = - V_29 ;
goto error;
}
memset ( & V_36 , 0 , sizeof( V_36 ) ) ;
V_36 . V_41 = F_29 ( V_6 ) -> V_9 -> V_42 ;
V_36 . V_43 = F_29 ( V_6 ) -> V_9 -> V_44 ;
V_36 . V_45 = F_30 ( F_29 ( V_6 ) -> V_9 -> V_46 ) ;
V_36 . V_47 = V_6 -> V_48 ;
V_36 . V_49 = V_50 ;
V_34 = F_31 ( V_23 , & V_36 ) ;
if ( F_22 ( V_34 ) ) {
V_28 = F_32 ( V_34 ) ;
goto error;
}
V_40 = F_29 ( V_6 ) -> V_9 -> V_51 & V_52 ?
F_24 ( V_53 ) : 0 ;
V_6 -> V_54 = 1 ;
F_33 ( & V_38 , & V_39 ) ;
V_37 = F_34 ( V_38 , V_39 , V_6 ) ;
V_28 = F_35 ( V_1 -> V_4 , V_34 , V_6 ,
V_36 . V_43 , F_29 ( V_6 ) -> V_9 -> V_42 ,
F_29 ( V_6 ) -> V_9 -> V_46 ,
F_29 ( V_6 ) -> V_9 -> V_55 , V_40 ,
V_37 , V_15 ,
F_36 ( F_37 ( F_29 ( V_6 ) -> V_9 -> V_56 ) << 8 ) ) ;
if ( V_28 < 0 )
F_38 ( V_34 ) ;
error:
return V_28 ;
}
static const char * F_39 ( const struct V_2 * V_2 )
{
struct V_1 * V_1 = F_1 ( V_2 ) ;
return V_1 -> V_31 ;
}
