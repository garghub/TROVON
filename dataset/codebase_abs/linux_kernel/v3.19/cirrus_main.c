static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_4 -> V_5 )
F_3 ( V_4 -> V_5 ) ;
F_4 ( V_2 ) ;
F_5 ( V_2 ) ;
}
int F_6 ( struct V_6 * V_7 ,
struct V_3 * V_8 ,
struct V_9 * V_10 ,
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
struct V_9 * V_10 )
{
struct V_17 * V_18 = V_7 -> V_19 ;
struct V_11 * V_5 ;
struct V_3 * V_4 ;
int V_12 ;
T_1 V_20 , V_21 ;
F_11 ( V_10 -> V_22 , & V_21 , & V_20 ) ;
if ( ! F_12 ( V_18 , V_10 -> V_23 , V_10 -> V_24 ,
V_20 , V_10 -> V_25 [ 0 ] ) )
return F_13 ( - V_26 ) ;
V_5 = F_14 ( V_7 , V_16 , V_10 -> V_27 [ 0 ] ) ;
if ( V_5 == NULL )
return F_13 ( - V_28 ) ;
V_4 = F_15 ( sizeof( * V_4 ) , V_29 ) ;
if ( ! V_4 ) {
F_3 ( V_5 ) ;
return F_13 ( - V_30 ) ;
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
F_17 ( V_18 -> V_31 ) ;
V_18 -> V_31 = NULL ;
if ( V_18 -> V_32 . V_33 )
F_18 ( V_18 -> V_32 . V_33 , V_18 -> V_32 . V_34 ) ;
}
static int F_19 ( struct V_17 * V_18 )
{
V_18 -> V_32 . V_33 = F_20 ( V_18 -> V_7 -> V_35 , 0 ) ;
V_18 -> V_32 . V_34 = F_21 ( V_18 -> V_7 -> V_35 , 0 ) ;
if ( ! F_22 ( V_18 -> V_32 . V_33 , V_18 -> V_32 . V_34 ,
L_2 ) ) {
F_9 ( L_3 ) ;
return - V_36 ;
}
return 0 ;
}
int F_23 ( struct V_17 * V_18 ,
struct V_6 * V_37 ,
struct V_38 * V_35 , T_2 V_39 )
{
int V_12 ;
V_18 -> V_7 = V_37 ;
V_18 -> V_39 = V_39 ;
V_18 -> V_40 = 1 ;
V_18 -> V_41 = F_20 ( V_18 -> V_7 -> V_35 , 1 ) ;
V_18 -> V_42 = F_21 ( V_18 -> V_7 -> V_35 , 1 ) ;
if ( ! F_22 ( V_18 -> V_41 , V_18 -> V_42 ,
L_4 ) ) {
F_9 ( L_5 ) ;
return - V_30 ;
}
V_18 -> V_31 = F_24 ( V_18 -> V_41 , V_18 -> V_42 ) ;
if ( V_18 -> V_31 == NULL )
return - V_30 ;
V_12 = F_19 ( V_18 ) ;
if ( V_12 ) {
F_18 ( V_18 -> V_41 , V_18 -> V_42 ) ;
return V_12 ;
}
return 0 ;
}
void F_25 ( struct V_17 * V_18 )
{
F_18 ( V_18 -> V_41 , V_18 -> V_42 ) ;
F_16 ( V_18 ) ;
}
int F_26 ( struct V_6 * V_7 , unsigned long V_39 )
{
struct V_17 * V_18 ;
int V_43 ;
V_18 = F_15 ( sizeof( struct V_17 ) , V_29 ) ;
if ( V_18 == NULL )
return - V_30 ;
V_7 -> V_19 = ( void * ) V_18 ;
V_43 = F_23 ( V_18 , V_7 , V_7 -> V_35 , V_39 ) ;
if ( V_43 ) {
F_27 ( & V_7 -> V_35 -> V_7 , L_6 , V_43 ) ;
goto V_44;
}
V_43 = F_28 ( V_18 ) ;
if ( V_43 ) {
F_27 ( & V_7 -> V_35 -> V_7 , L_7 ) ;
goto V_44;
}
V_43 = F_29 ( V_18 ) ;
if ( V_43 ) {
F_27 ( & V_7 -> V_35 -> V_7 , L_8 , V_43 ) ;
goto V_44;
}
V_7 -> V_45 . V_46 = ( void * ) & V_47 ;
return 0 ;
V_44:
F_30 ( V_7 ) ;
return V_43 ;
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
T_1 V_48 , bool V_49 ,
struct V_11 * * V_5 )
{
struct V_50 * V_51 ;
int V_12 ;
* V_5 = NULL ;
V_48 = F_34 ( V_48 , V_52 ) ;
if ( V_48 == 0 )
return - V_26 ;
V_12 = F_35 ( V_7 , V_48 , 0 , 0 , & V_51 ) ;
if ( V_12 ) {
if ( V_12 != - V_53 )
F_9 ( L_9 ) ;
return V_12 ;
}
* V_5 = & V_51 -> V_54 ;
return 0 ;
}
int F_36 ( struct V_15 * V_55 ,
struct V_6 * V_7 ,
struct V_56 * args )
{
int V_12 ;
struct V_11 * V_57 ;
T_1 V_58 ;
args -> V_59 = args -> V_23 * ( ( args -> V_20 + 7 ) / 8 ) ;
args -> V_48 = args -> V_59 * args -> V_24 ;
V_12 = F_33 ( V_7 , args -> V_48 , false ,
& V_57 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_37 ( V_55 , V_57 , & V_58 ) ;
F_3 ( V_57 ) ;
if ( V_12 )
return V_12 ;
args -> V_58 = V_58 ;
return 0 ;
}
static void F_38 ( struct V_50 * * V_60 )
{
struct V_61 * V_62 ;
if ( ( * V_60 ) == NULL )
return;
V_62 = & ( ( * V_60 ) -> V_60 ) ;
F_39 ( & V_62 ) ;
* V_60 = NULL ;
}
void F_40 ( struct V_11 * V_5 )
{
struct V_50 * V_50 = F_41 ( V_5 ) ;
F_38 ( & V_50 ) ;
}
static inline T_3 F_42 ( struct V_50 * V_60 )
{
return F_43 ( & V_60 -> V_60 . V_63 ) ;
}
int
F_44 ( struct V_15 * V_55 ,
struct V_6 * V_7 ,
T_2 V_58 ,
T_4 * V_64 )
{
struct V_11 * V_5 ;
int V_12 ;
struct V_50 * V_60 ;
F_45 ( & V_7 -> V_65 ) ;
V_5 = F_14 ( V_7 , V_55 , V_58 ) ;
if ( V_5 == NULL ) {
V_12 = - V_28 ;
goto V_66;
}
V_60 = F_41 ( V_5 ) ;
* V_64 = F_42 ( V_60 ) ;
F_46 ( V_5 ) ;
V_12 = 0 ;
V_66:
F_47 ( & V_7 -> V_65 ) ;
return V_12 ;
}
bool F_12 ( struct V_17 * V_18 , int V_23 , int V_24 ,
int V_20 , int V_59 )
{
const int V_67 = 0x1FF << 3 ;
const int V_68 = V_18 -> V_32 . V_34 ;
if ( V_20 > V_69 )
return false ;
if ( V_20 > 32 )
return false ;
if ( V_59 > V_67 )
return false ;
if ( V_59 * V_24 > V_68 )
return false ;
return true ;
}
