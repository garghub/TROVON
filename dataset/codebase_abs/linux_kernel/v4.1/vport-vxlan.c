static inline struct V_1 * F_1 ( const struct V_2 * V_2 )
{
return F_2 ( V_2 ) ;
}
static void F_3 ( struct V_3 * V_4 , struct V_5 * V_6 ,
struct V_7 * V_8 )
{
struct V_9 V_10 ;
struct V_1 * V_1 ;
struct V_2 * V_2 = V_4 -> V_11 ;
struct V_12 * V_13 ;
struct V_14 V_15 = {
. V_16 = V_8 -> V_16 ,
} ;
T_1 V_17 ;
T_2 V_18 ;
V_18 = V_19 | ( F_4 ( V_6 ) -> V_20 != 0 ? V_21 : 0 ) ;
V_1 = F_1 ( V_2 ) ;
if ( V_1 -> V_22 & V_23 && V_8 -> V_16 )
V_18 |= V_24 ;
V_13 = F_5 ( V_6 ) ;
V_17 = F_6 ( F_7 ( V_8 -> V_25 ) >> 8 ) ;
F_8 ( & V_10 , V_13 ,
F_4 ( V_6 ) -> V_26 , F_4 ( V_6 ) -> V_27 ,
V_17 , V_18 , & V_15 , sizeof( V_15 ) ) ;
F_9 ( V_2 , V_6 , & V_10 ) ;
}
static int F_10 ( const struct V_2 * V_2 , struct V_5 * V_6 )
{
struct V_1 * V_1 = F_1 ( V_2 ) ;
T_2 V_28 = F_11 ( V_1 -> V_4 -> V_29 -> V_30 ) -> V_31 ;
if ( F_12 ( V_6 , V_32 , F_13 ( V_28 ) ) )
return - V_33 ;
if ( V_1 -> V_22 ) {
struct V_34 * V_22 ;
V_22 = F_14 ( V_6 , V_35 ) ;
if ( ! V_22 )
return - V_33 ;
if ( V_1 -> V_22 & V_23 &&
F_15 ( V_6 , V_36 ) )
return - V_33 ;
F_16 ( V_6 , V_22 ) ;
}
return 0 ;
}
static void F_17 ( struct V_2 * V_2 )
{
struct V_1 * V_1 = F_1 ( V_2 ) ;
F_18 ( V_1 -> V_4 ) ;
F_19 ( V_2 ) ;
}
static int F_20 ( struct V_2 * V_2 , struct V_34 * V_37 )
{
struct V_34 * V_22 [ V_38 + 1 ] ;
struct V_1 * V_1 ;
int V_39 ;
if ( F_21 ( V_37 ) < sizeof( struct V_34 ) )
return - V_40 ;
V_39 = F_22 ( V_22 , V_38 , V_37 , V_41 ) ;
if ( V_39 < 0 )
return V_39 ;
V_1 = F_1 ( V_2 ) ;
if ( V_22 [ V_36 ] )
V_1 -> V_22 |= V_23 ;
return 0 ;
}
static struct V_2 * F_23 ( const struct V_42 * V_43 )
{
struct V_44 * V_44 = F_24 ( V_43 -> V_45 ) ;
struct V_34 * V_46 = V_43 -> V_46 ;
struct V_1 * V_1 ;
struct V_3 * V_4 ;
struct V_2 * V_2 ;
struct V_34 * V_47 ;
T_3 V_28 ;
int V_39 ;
if ( ! V_46 ) {
V_39 = - V_40 ;
goto error;
}
V_47 = F_25 ( V_46 , V_32 ) ;
if ( V_47 && F_21 ( V_47 ) == sizeof( T_3 ) ) {
V_28 = F_26 ( V_47 ) ;
} else {
V_39 = - V_40 ;
goto error;
}
V_2 = F_27 ( sizeof( struct V_1 ) ,
& V_48 , V_43 ) ;
if ( F_28 ( V_2 ) )
return V_2 ;
V_1 = F_1 ( V_2 ) ;
strncpy ( V_1 -> V_49 , V_43 -> V_49 , V_50 ) ;
V_47 = F_25 ( V_46 , V_35 ) ;
if ( V_47 ) {
V_39 = F_20 ( V_2 , V_47 ) ;
if ( V_39 ) {
F_29 ( V_2 ) ;
goto error;
}
}
V_4 = F_30 ( V_44 , F_31 ( V_28 ) , F_3 , V_2 , true ,
V_1 -> V_22 ) ;
if ( F_28 ( V_4 ) ) {
F_29 ( V_2 ) ;
return ( void * ) V_4 ;
}
V_1 -> V_4 = V_4 ;
return V_2 ;
error:
return F_32 ( V_39 ) ;
}
static int F_33 ( struct V_5 * V_6 )
{
const struct V_9 * V_10 ;
const struct V_14 * V_15 ;
V_10 = F_34 ( V_6 ) -> V_51 ;
V_15 = V_10 -> V_46 ;
if ( V_10 -> V_52 . V_53 & V_24 &&
V_10 -> V_54 >= sizeof( * V_15 ) )
return V_15 -> V_16 ;
else
return 0 ;
}
static int F_35 ( struct V_2 * V_2 , struct V_5 * V_6 )
{
struct V_44 * V_44 = F_24 ( V_2 -> V_45 ) ;
struct V_1 * V_1 = F_1 ( V_2 ) ;
struct V_29 * V_30 = V_1 -> V_4 -> V_29 -> V_30 ;
T_2 V_28 = F_11 ( V_30 ) -> V_31 ;
const struct V_55 * V_56 ;
struct V_7 V_8 = { 0 } ;
struct V_57 * V_58 ;
struct V_59 V_60 ;
T_2 V_61 ;
T_2 V_62 ;
int V_39 ;
T_4 V_63 ;
if ( F_36 ( ! F_34 ( V_6 ) -> V_51 ) ) {
V_39 = - V_40 ;
goto error;
}
V_56 = & F_34 ( V_6 ) -> V_51 -> V_52 ;
V_58 = F_37 ( V_44 , V_56 , V_6 -> V_64 , & V_60 , V_65 ) ;
if ( F_28 ( V_58 ) ) {
V_39 = F_38 ( V_58 ) ;
goto error;
}
V_62 = V_56 -> V_53 & V_66 ?
F_31 ( V_67 ) : 0 ;
V_6 -> V_68 = 1 ;
V_61 = F_39 ( V_44 , V_6 , 0 , 0 , true ) ;
V_8 . V_25 = F_40 ( F_41 ( V_56 -> V_69 ) << 8 ) ;
V_8 . V_16 = F_33 ( V_6 ) ;
V_63 = V_1 -> V_22 |
( V_56 -> V_53 & V_21 ? V_70 : 0 ) ;
V_39 = F_42 ( V_58 , V_30 , V_6 , V_60 . V_71 , V_56 -> V_72 ,
V_56 -> V_73 , V_56 -> V_74 , V_62 ,
V_61 , V_28 ,
& V_8 , false , V_63 ) ;
if ( V_39 < 0 )
F_43 ( V_58 ) ;
return V_39 ;
error:
F_44 ( V_6 ) ;
return V_39 ;
}
static int F_45 ( struct V_2 * V_2 , struct V_5 * V_6 ,
struct V_9 * V_51 )
{
struct V_44 * V_44 = F_24 ( V_2 -> V_45 ) ;
struct V_1 * V_1 = F_1 ( V_2 ) ;
T_2 V_28 = F_11 ( V_1 -> V_4 -> V_29 -> V_30 ) -> V_31 ;
T_2 V_61 ;
int V_75 ;
int V_76 ;
F_46 ( V_44 , & V_75 , & V_76 ) ;
V_61 = F_39 ( V_44 , V_6 , 0 , 0 , true ) ;
return F_47 ( V_51 , V_44 ,
F_34 ( V_6 ) -> V_51 ,
V_65 , V_6 -> V_64 ,
V_61 , V_28 ) ;
}
static const char * F_48 ( const struct V_2 * V_2 )
{
struct V_1 * V_1 = F_1 ( V_2 ) ;
return V_1 -> V_49 ;
}
static int T_5 F_49 ( void )
{
return F_50 ( & V_48 ) ;
}
static void T_6 F_51 ( void )
{
F_52 ( & V_48 ) ;
}
