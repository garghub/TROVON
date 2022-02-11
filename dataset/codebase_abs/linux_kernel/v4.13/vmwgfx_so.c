static struct V_1 * V_1 ( struct V_2 * V_3 )
{
return F_1 ( V_3 , struct V_1 , V_3 ) ;
}
static void F_2 ( struct V_2 * V_3 ,
enum V_4 V_5 )
{
struct V_1 * V_6 = V_1 ( V_3 ) ;
struct V_7 * V_8 = V_3 -> V_8 ;
F_3 ( & V_8 -> V_9 ) ;
if ( V_5 == V_10 ) {
struct V_11 * V_12 = F_4 ( V_6 -> V_12 ) ;
F_5 ( & V_6 -> V_13 , & V_12 -> V_14 ) ;
F_6 ( V_6 -> V_15 , & V_6 -> V_16 ) ;
V_6 -> V_17 = true ;
V_3 -> V_18 = V_6 -> V_19 ;
} else {
F_7 ( & V_6 -> V_16 ) ;
F_7 ( & V_6 -> V_13 ) ;
V_6 -> V_17 = false ;
V_3 -> V_18 = - 1 ;
}
F_8 ( & V_8 -> V_9 ) ;
}
static int F_9 ( struct V_2 * V_3 )
{
struct V_1 * V_6 = V_1 ( V_3 ) ;
struct V_11 * V_12 = F_4 ( V_6 -> V_12 ) ;
struct V_7 * V_8 = V_3 -> V_8 ;
struct {
T_1 V_20 ;
struct V_21 V_22 ;
} * V_23 ;
F_3 ( & V_8 -> V_9 ) ;
if ( ! V_6 -> V_17 ) {
F_8 ( & V_8 -> V_9 ) ;
return 0 ;
}
V_23 = F_10 ( V_3 -> V_8 , V_6 -> V_24 ,
V_6 -> V_25 -> V_18 ) ;
if ( ! V_23 ) {
F_11 ( L_1 ) ;
F_8 ( & V_8 -> V_9 ) ;
return - V_26 ;
}
memcpy ( V_23 , & V_6 -> V_23 , V_6 -> V_24 ) ;
F_12 ( V_23 -> V_22 . V_19 != V_6 -> V_19 ) ;
F_12 ( V_6 -> V_12 -> V_18 == V_27 ) ;
V_23 -> V_22 . V_28 = V_6 -> V_12 -> V_18 ;
F_13 ( V_3 -> V_8 , V_6 -> V_24 ) ;
V_3 -> V_18 = V_6 -> V_19 ;
F_5 ( & V_6 -> V_13 , & V_12 -> V_14 ) ;
F_6 ( V_6 -> V_15 , & V_6 -> V_16 ) ;
F_8 ( & V_8 -> V_9 ) ;
return 0 ;
}
static int F_14 ( struct V_2 * V_3 )
{
struct V_7 * V_8 = V_3 -> V_8 ;
struct V_1 * V_6 = V_1 ( V_3 ) ;
struct {
T_1 V_20 ;
union F_14 V_22 ;
} * V_23 ;
F_15 ( ! F_16 ( & V_8 -> V_9 ) ) ;
F_17 ( & V_3 -> V_29 ) ;
if ( ! V_6 -> V_17 || V_3 -> V_18 == - 1 )
return 0 ;
V_23 = F_10 ( V_8 , sizeof( * V_23 ) , V_6 -> V_25 -> V_18 ) ;
if ( ! V_23 ) {
F_11 ( L_2
L_3 ) ;
return - V_26 ;
}
V_23 -> V_20 . V_18 = V_30 [ V_6 -> V_31 ] ;
V_23 -> V_20 . V_32 = sizeof( V_23 -> V_22 ) ;
V_23 -> V_22 . V_19 = V_6 -> V_19 ;
F_13 ( V_8 , sizeof( * V_23 ) ) ;
V_3 -> V_18 = - 1 ;
F_7 ( & V_6 -> V_16 ) ;
F_7 ( & V_6 -> V_13 ) ;
return 0 ;
}
static void F_18 ( struct V_2 * V_3 )
{
struct V_7 * V_8 = V_3 -> V_8 ;
F_3 ( & V_8 -> V_9 ) ;
F_12 ( F_14 ( V_3 ) ) ;
V_3 -> V_18 = - 1 ;
F_8 ( & V_8 -> V_9 ) ;
}
static T_2 F_19 ( T_2 V_33 , enum V_34 V_31 )
{
return V_33 | ( V_31 << 20 ) ;
}
static bool F_20 ( T_2 V_33 , enum V_34 V_31 )
{
return ( V_33 < V_35 &&
V_31 < V_36 ) ;
}
static void F_21 ( struct V_2 * V_3 )
{
struct V_1 * V_6 = V_1 ( V_3 ) ;
T_3 V_32 = F_22 ( struct V_1 , V_23 ) + V_6 -> V_24 ;
struct V_7 * V_8 = V_3 -> V_8 ;
F_23 ( & V_6 -> V_15 ) ;
F_23 ( & V_6 -> V_12 ) ;
F_24 ( V_6 , V_37 ) ;
F_25 ( F_26 ( V_8 ) , V_32 ) ;
}
int F_27 ( struct V_38 * V_39 ,
struct V_2 * V_25 ,
struct V_2 * V_12 ,
enum V_34 V_31 ,
T_2 V_33 ,
const void * V_23 ,
T_3 V_24 ,
struct V_40 * V_41 )
{
static const T_3 V_42 [] = {
[ V_43 ] = sizeof( V_44 ) ,
[ V_45 ] = sizeof( V_46 ) ,
[ V_47 ] = sizeof( V_48 )
} ;
struct V_7 * V_8 = V_25 -> V_8 ;
struct V_2 * V_3 ;
struct V_1 * V_6 ;
T_3 V_32 ;
int V_49 ;
if ( V_24 != V_42 [ V_31 ] +
sizeof( T_1 ) ) {
F_11 ( L_4 ) ;
return - V_50 ;
}
if ( ! F_20 ( V_33 , V_31 ) ) {
F_11 ( L_5 ) ;
return - V_50 ;
}
V_32 = F_22 ( struct V_1 , V_23 ) + V_24 ;
V_49 = F_28 ( F_26 ( V_8 ) , V_32 , false , true ) ;
if ( V_49 ) {
if ( V_49 != - V_51 )
F_11 ( L_6
L_7 ) ;
return V_49 ;
}
V_6 = F_29 ( V_32 , V_52 ) ;
if ( ! V_6 ) {
F_25 ( F_26 ( V_8 ) , V_32 ) ;
return - V_26 ;
}
V_3 = & V_6 -> V_3 ;
V_6 -> V_25 = V_25 ;
V_6 -> V_12 = F_30 ( V_12 ) ;
V_6 -> V_15 = F_31 ( V_25 , V_53 [ V_31 ] ) ;
V_6 -> V_31 = V_31 ;
V_6 -> V_19 = V_33 ;
V_6 -> V_24 = V_24 ;
V_6 -> V_17 = false ;
F_32 ( & V_6 -> V_13 ) ;
F_32 ( & V_6 -> V_16 ) ;
memcpy ( & V_6 -> V_23 , V_23 , V_24 ) ;
V_49 = F_33 ( V_8 , V_3 , true ,
F_21 , & V_54 ) ;
if ( V_49 )
goto V_55;
V_49 = F_34 ( V_39 , V_56 ,
F_19 ( V_33 , V_31 ) ,
V_3 , V_41 ) ;
if ( V_49 )
goto V_55;
V_3 -> V_18 = V_6 -> V_19 ;
F_35 ( V_3 , F_18 ) ;
V_55:
F_23 ( & V_3 ) ;
return V_49 ;
}
int F_36 ( struct V_38 * V_39 ,
T_2 V_33 , enum V_34 V_31 ,
struct V_40 * V_41 ,
struct V_2 * * V_57 )
{
if ( ! F_20 ( V_33 , V_31 ) ) {
F_11 ( L_8 ) ;
return - V_50 ;
}
return F_37 ( V_39 , V_56 ,
F_19 ( V_33 , V_31 ) ,
V_41 , V_57 ) ;
}
void F_38 ( struct V_7 * V_8 ,
struct V_40 * V_41 ,
bool V_58 )
{
struct V_1 * V_59 , * V_60 ;
F_15 ( ! F_16 ( & V_8 -> V_9 ) ) ;
F_39 (entry, next, list, cotable_head)
F_12 ( F_14 ( & V_59 -> V_3 ) ) ;
}
void F_40 ( struct V_7 * V_8 ,
struct V_40 * V_41 )
{
struct V_1 * V_59 , * V_60 ;
F_15 ( ! F_16 ( & V_8 -> V_9 ) ) ;
F_39 (entry, next, list, srf_head)
F_12 ( F_14 ( & V_59 -> V_3 ) ) ;
}
struct V_2 * F_41 ( struct V_2 * V_3 )
{
return V_1 ( V_3 ) -> V_12 ;
}
struct V_2 * F_42 ( struct V_38 * V_39 ,
enum V_34 V_31 ,
T_2 V_33 )
{
return F_43 ( V_39 , V_56 ,
F_19 ( V_33 , V_31 ) ) ;
}
static void F_44 ( void )
{
F_45 ( V_61 !=
V_62 + 1 ) ;
F_45 ( V_63 !=
V_62 + 2 ) ;
F_45 ( V_64 !=
V_62 + 3 ) ;
F_45 ( V_65 !=
V_62 + 4 ) ;
F_45 ( V_66 !=
V_62 + 5 ) ;
F_45 ( sizeof( union F_14 ) != sizeof( T_2 ) ) ;
F_45 ( V_35 >= ( ( 1 << 20 ) - 1 ) ) ;
F_45 ( F_22 ( struct V_21 , V_28 ) !=
F_22 ( V_44 , V_28 ) ) ;
F_45 ( F_22 ( struct V_21 , V_28 ) !=
F_22 ( V_46 , V_28 ) ) ;
F_45 ( F_22 ( struct V_21 , V_28 ) !=
F_22 ( V_48 , V_28 ) ) ;
}
