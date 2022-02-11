static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( V_4 -> V_5 ) ;
F_4 ( V_2 ) ;
F_5 ( V_2 ) ;
}
int F_6 ( struct V_6 * V_7 ,
struct V_3 * V_8 ,
const struct V_9 * V_10 ,
struct V_11 * V_5 )
{
int V_12 ;
F_7 ( & V_8 -> V_13 , V_10 ) ;
V_8 -> V_5 = V_5 ;
V_12 = F_8 ( V_7 , & V_8 -> V_13 , & V_14 ) ;
if ( V_12 ) {
F_9 ( L_1 , V_12 ) ;
return V_12 ;
}
return 0 ;
}
static struct V_1 *
F_10 ( struct V_6 * V_7 ,
struct V_15 * V_16 ,
const struct V_9 * V_10 )
{
struct V_17 * V_18 = V_7 -> V_19 ;
struct V_11 * V_5 ;
struct V_3 * V_4 ;
T_1 V_20 ;
int V_12 ;
V_20 = F_11 ( V_10 -> V_21 , 0 ) * 8 ;
if ( ! F_12 ( V_18 , V_10 -> V_22 , V_10 -> V_23 ,
V_20 , V_10 -> V_24 [ 0 ] ) )
return F_13 ( - V_25 ) ;
V_5 = F_14 ( V_16 , V_10 -> V_26 [ 0 ] ) ;
if ( V_5 == NULL )
return F_13 ( - V_27 ) ;
V_4 = F_15 ( sizeof( * V_4 ) , V_28 ) ;
if ( ! V_4 ) {
F_3 ( V_5 ) ;
return F_13 ( - V_29 ) ;
}
V_12 = F_6 ( V_7 , V_4 , V_10 , V_5 ) ;
if ( V_12 ) {
F_3 ( V_5 ) ;
F_5 ( V_4 ) ;
return F_13 ( V_12 ) ;
}
return & V_4 -> V_13 ;
}
static void F_16 ( struct V_17 * V_18 )
{
F_17 ( V_18 -> V_30 ) ;
V_18 -> V_30 = NULL ;
if ( V_18 -> V_31 . V_32 )
F_18 ( V_18 -> V_31 . V_32 , V_18 -> V_31 . V_33 ) ;
}
static int F_19 ( struct V_17 * V_18 )
{
V_18 -> V_31 . V_32 = F_20 ( V_18 -> V_7 -> V_34 , 0 ) ;
V_18 -> V_31 . V_33 = F_21 ( V_18 -> V_7 -> V_34 , 0 ) ;
if ( ! F_22 ( V_18 -> V_31 . V_32 , V_18 -> V_31 . V_33 ,
L_2 ) ) {
F_9 ( L_3 ) ;
return - V_35 ;
}
return 0 ;
}
int F_23 ( struct V_17 * V_18 ,
struct V_6 * V_36 ,
struct V_37 * V_34 , T_2 V_38 )
{
int V_12 ;
V_18 -> V_7 = V_36 ;
V_18 -> V_38 = V_38 ;
V_18 -> V_39 = 1 ;
V_18 -> V_40 = F_20 ( V_18 -> V_7 -> V_34 , 1 ) ;
V_18 -> V_41 = F_21 ( V_18 -> V_7 -> V_34 , 1 ) ;
if ( ! F_22 ( V_18 -> V_40 , V_18 -> V_41 ,
L_4 ) ) {
F_9 ( L_5 ) ;
return - V_29 ;
}
V_18 -> V_30 = F_24 ( V_18 -> V_40 , V_18 -> V_41 ) ;
if ( V_18 -> V_30 == NULL )
return - V_29 ;
V_12 = F_19 ( V_18 ) ;
if ( V_12 ) {
F_18 ( V_18 -> V_40 , V_18 -> V_41 ) ;
return V_12 ;
}
return 0 ;
}
void F_25 ( struct V_17 * V_18 )
{
F_18 ( V_18 -> V_40 , V_18 -> V_41 ) ;
F_16 ( V_18 ) ;
}
int F_26 ( struct V_6 * V_7 , unsigned long V_38 )
{
struct V_17 * V_18 ;
int V_42 ;
V_18 = F_15 ( sizeof( struct V_17 ) , V_28 ) ;
if ( V_18 == NULL )
return - V_29 ;
V_7 -> V_19 = ( void * ) V_18 ;
V_42 = F_23 ( V_18 , V_7 , V_7 -> V_34 , V_38 ) ;
if ( V_42 ) {
F_27 ( & V_7 -> V_34 -> V_7 , L_6 , V_42 ) ;
goto V_43;
}
V_42 = F_28 ( V_18 ) ;
if ( V_42 ) {
F_27 ( & V_7 -> V_34 -> V_7 , L_7 ) ;
goto V_43;
}
V_7 -> V_44 . V_45 = & V_46 ;
V_42 = F_29 ( V_18 ) ;
if ( V_42 ) {
F_27 ( & V_7 -> V_34 -> V_7 , L_8 , V_42 ) ;
goto V_43;
}
return 0 ;
V_43:
F_30 ( V_7 ) ;
return V_42 ;
}
int F_30 ( struct V_6 * V_7 )
{
struct V_17 * V_18 = V_7 -> V_19 ;
if ( V_18 == NULL )
return 0 ;
F_31 ( V_18 ) ;
F_32 ( V_18 ) ;
F_25 ( V_18 ) ;
F_5 ( V_18 ) ;
V_7 -> V_19 = NULL ;
return 0 ;
}
int F_33 ( struct V_6 * V_7 ,
T_1 V_47 , bool V_48 ,
struct V_11 * * V_5 )
{
struct V_49 * V_50 ;
int V_12 ;
* V_5 = NULL ;
V_47 = F_34 ( V_47 , V_51 ) ;
if ( V_47 == 0 )
return - V_25 ;
V_12 = F_35 ( V_7 , V_47 , 0 , 0 , & V_50 ) ;
if ( V_12 ) {
if ( V_12 != - V_52 )
F_9 ( L_9 ) ;
return V_12 ;
}
* V_5 = & V_50 -> V_53 ;
return 0 ;
}
int F_36 ( struct V_15 * V_54 ,
struct V_6 * V_7 ,
struct V_55 * args )
{
int V_12 ;
struct V_11 * V_56 ;
T_1 V_57 ;
args -> V_58 = args -> V_22 * ( ( args -> V_20 + 7 ) / 8 ) ;
args -> V_47 = args -> V_58 * args -> V_23 ;
V_12 = F_33 ( V_7 , args -> V_47 , false ,
& V_56 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_37 ( V_54 , V_56 , & V_57 ) ;
F_3 ( V_56 ) ;
if ( V_12 )
return V_12 ;
args -> V_57 = V_57 ;
return 0 ;
}
static void F_38 ( struct V_49 * * V_59 )
{
struct V_60 * V_61 ;
if ( ( * V_59 ) == NULL )
return;
V_61 = & ( ( * V_59 ) -> V_59 ) ;
F_39 ( & V_61 ) ;
* V_59 = NULL ;
}
void F_40 ( struct V_11 * V_5 )
{
struct V_49 * V_49 = F_41 ( V_5 ) ;
F_38 ( & V_49 ) ;
}
static inline T_3 F_42 ( struct V_49 * V_59 )
{
return F_43 ( & V_59 -> V_59 . V_62 ) ;
}
int
F_44 ( struct V_15 * V_54 ,
struct V_6 * V_7 ,
T_2 V_57 ,
T_4 * V_63 )
{
struct V_11 * V_5 ;
struct V_49 * V_59 ;
V_5 = F_14 ( V_54 , V_57 ) ;
if ( V_5 == NULL )
return - V_27 ;
V_59 = F_41 ( V_5 ) ;
* V_63 = F_42 ( V_59 ) ;
F_3 ( V_5 ) ;
return 0 ;
}
bool F_12 ( struct V_17 * V_18 , int V_22 , int V_23 ,
int V_20 , int V_58 )
{
const int V_64 = 0x1FF << 3 ;
const int V_65 = V_18 -> V_31 . V_33 ;
if ( V_20 > V_66 )
return false ;
if ( V_20 > 32 )
return false ;
if ( V_58 > V_64 )
return false ;
if ( V_58 * V_23 > V_65 )
return false ;
return true ;
}
