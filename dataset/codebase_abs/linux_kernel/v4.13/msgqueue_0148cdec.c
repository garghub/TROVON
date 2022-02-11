static struct V_1 *
F_1 ( struct V_2 * V_3 ,
enum V_4 V_5 )
{
struct V_6 * V_7 = V_6 ( V_3 ) ;
return & V_7 -> V_3 [ V_8 ] ;
}
static void
F_2 ( struct V_2 * V_3 )
{
struct V_6 * V_7 = V_6 ( V_3 ) ;
struct V_1 * V_9 =
& V_7 -> V_3 [ V_10 ] ;
F_3 ( & V_7 -> V_11 , V_9 ) ;
}
static void
F_4 ( struct V_2 * V_3 , void * V_12 )
{
struct {
T_1 V_13 ;
T_1 V_14 ;
T_1 V_15 ;
T_1 V_16 ;
bool V_17 ;
} * args = V_12 ;
args -> V_17 = false ;
}
static int
F_5 ( struct V_2 * V_18 , struct V_19 * V_20 )
{
struct V_6 * V_7 = V_6 ( V_18 ) ;
struct {
struct V_21 V_11 ;
T_2 V_22 ;
T_3 V_23 ;
struct {
T_1 V_24 ;
T_3 V_25 ;
T_2 V_26 ;
T_2 V_27 ;
} V_28 [ V_29 ] ;
T_3 V_30 ;
T_3 V_31 ;
} * V_32 = ( void * ) V_20 ;
const struct V_33 * V_34 = V_18 -> V_35 -> V_36 ;
int V_37 ;
if ( V_32 -> V_11 . V_20 . V_38 != V_39 ) {
F_6 ( V_34 , L_1 ) ;
return - V_40 ;
}
if ( V_32 -> V_11 . V_41 != V_42 ) {
F_6 ( V_34 , L_2 ) ;
return - V_40 ;
}
for ( V_37 = 0 ; V_37 < V_29 ; V_37 ++ ) {
T_2 V_27 = V_32 -> V_28 [ V_37 ] . V_27 ;
struct V_1 * V_3 = & V_7 -> V_3 [ V_27 ] ;
F_7 ( & V_3 -> V_43 ) ;
V_3 -> V_26 = V_32 -> V_28 [ V_37 ] . V_26 ;
V_3 -> V_24 = V_32 -> V_28 [ V_37 ] . V_24 ;
V_3 -> V_25 = V_32 -> V_28 [ V_37 ] . V_25 ;
if ( V_27 == V_10 ) {
V_3 -> V_44 = 0xa30 + ( V_3 -> V_26 * 8 ) ;
V_3 -> V_45 = 0xa34 + ( V_3 -> V_26 * 8 ) ;
} else {
V_3 -> V_44 = 0xa00 + ( V_3 -> V_26 * 8 ) ;
V_3 -> V_45 = 0xa04 + ( V_3 -> V_26 * 8 ) ;
}
F_8 ( V_34 ,
L_3 ,
V_27 , V_3 -> V_26 , V_3 -> V_24 , V_3 -> V_25 ) ;
}
F_9 ( & V_18 -> V_46 ) ;
return 0 ;
}
static void
F_10 ( struct V_2 * V_7 ,
struct V_19 * V_20 )
{
struct V_47 {
struct V_21 V_11 ;
T_1 V_48 ;
T_1 V_49 ;
} * V_50 = ( void * ) V_20 ;
const struct V_33 * V_34 = V_7 -> V_35 -> V_36 ;
T_1 V_49 = V_50 -> V_49 ;
if ( V_50 -> V_48 ) {
F_6 ( V_34 , L_4 ) ;
F_6 ( V_34 , L_5 ,
V_50 -> V_48 ) ;
return;
}
if ( V_49 >= V_51 ) {
F_6 ( V_34 , L_4 ) ;
F_6 ( V_34 , L_6 , V_49 ) ;
return;
}
F_8 ( V_34 , L_7 , V_52 [ V_49 ] ) ;
}
static int
F_11 ( struct V_2 * V_7 , enum V_53 V_35 )
{
F_12 ( V_54 ) ;
struct {
struct V_19 V_20 ;
T_2 V_55 ;
T_1 V_56 ;
T_1 V_49 ;
} V_57 ;
memset ( & V_57 , 0 , sizeof( V_57 ) ) ;
V_57 . V_20 . V_38 = V_58 ;
V_57 . V_20 . V_25 = sizeof( V_57 ) ;
V_57 . V_55 = V_59 ;
V_57 . V_56 = V_60 ;
V_57 . V_49 = V_35 ;
F_13 ( V_7 , V_61 , & V_57 . V_20 ,
F_10 , & V_54 , true ) ;
if ( ! F_14 ( & V_54 , F_15 ( 1000 ) ) )
return - V_62 ;
return 0 ;
}
static void
F_16 ( struct V_2 * V_3 )
{
F_17 ( V_6 ( V_3 ) ) ;
}
int
F_18 ( struct V_63 * V_35 , const struct V_64 * V_65 ,
struct V_2 * * V_3 )
{
struct V_6 * V_66 ;
V_66 = F_19 ( sizeof( * V_66 ) , V_67 ) ;
if ( ! V_66 )
return - V_68 ;
* V_3 = & V_66 -> V_11 ;
F_20 ( & V_69 , V_35 , & V_66 -> V_11 ) ;
return 0 ;
}
