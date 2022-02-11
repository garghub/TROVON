static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_4 -> V_5 )
F_3 ( V_4 -> V_5 ) ;
F_4 ( V_2 ) ;
F_5 ( V_2 ) ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_6 * V_7 ,
unsigned int * V_8 )
{
return 0 ;
}
int F_7 ( struct V_9 * V_10 ,
struct V_3 * V_11 ,
struct V_12 * V_13 ,
struct V_14 * V_5 )
{
int V_15 ;
V_15 = F_8 ( V_10 , & V_11 -> V_16 , & V_17 ) ;
if ( V_15 ) {
F_9 ( L_1 , V_15 ) ;
return V_15 ;
}
F_10 ( & V_11 -> V_16 , V_13 ) ;
V_11 -> V_5 = V_5 ;
return 0 ;
}
static struct V_1 *
F_11 ( struct V_9 * V_10 ,
struct V_6 * V_18 ,
struct V_12 * V_13 )
{
struct V_14 * V_5 ;
struct V_3 * V_4 ;
int V_15 ;
T_1 V_19 , V_20 ;
F_12 ( V_13 -> V_21 , & V_20 , & V_19 ) ;
if ( V_19 > 24 )
return F_13 ( - V_22 ) ;
V_5 = F_14 ( V_10 , V_18 , V_13 -> V_23 [ 0 ] ) ;
if ( V_5 == NULL )
return F_13 ( - V_24 ) ;
V_4 = F_15 ( sizeof( * V_4 ) , V_25 ) ;
if ( ! V_4 ) {
F_3 ( V_5 ) ;
return F_13 ( - V_26 ) ;
}
V_15 = F_7 ( V_10 , V_4 , V_13 , V_5 ) ;
if ( V_15 ) {
F_3 ( V_5 ) ;
F_5 ( V_4 ) ;
return F_13 ( V_15 ) ;
}
return & V_4 -> V_16 ;
}
static void F_16 ( struct V_27 * V_28 )
{
F_17 ( V_28 -> V_29 ) ;
V_28 -> V_29 = NULL ;
if ( V_28 -> V_30 . V_31 )
F_18 ( V_28 -> V_30 . V_31 , V_28 -> V_30 . V_32 ) ;
}
static int F_19 ( struct V_27 * V_28 )
{
V_28 -> V_30 . V_31 = F_20 ( V_28 -> V_10 -> V_33 , 0 ) ;
V_28 -> V_30 . V_32 = 4 * 1024 * 1024 ;
if ( ! F_21 ( V_28 -> V_30 . V_31 , V_28 -> V_30 . V_32 ,
L_2 ) ) {
F_9 ( L_3 ) ;
return - V_34 ;
}
return 0 ;
}
int F_22 ( struct V_27 * V_28 ,
struct V_9 * V_35 ,
struct V_36 * V_33 , T_2 V_37 )
{
int V_15 ;
V_28 -> V_10 = V_35 ;
V_28 -> V_37 = V_37 ;
V_28 -> V_38 = 1 ;
V_28 -> V_39 = F_20 ( V_28 -> V_10 -> V_33 , 1 ) ;
V_28 -> V_40 = F_23 ( V_28 -> V_10 -> V_33 , 1 ) ;
if ( ! F_21 ( V_28 -> V_39 , V_28 -> V_40 ,
L_4 ) ) {
F_9 ( L_5 ) ;
return - V_26 ;
}
V_28 -> V_29 = F_24 ( V_28 -> V_39 , V_28 -> V_40 ) ;
if ( V_28 -> V_29 == NULL )
return - V_26 ;
V_15 = F_19 ( V_28 ) ;
if ( V_15 ) {
F_18 ( V_28 -> V_39 , V_28 -> V_40 ) ;
return V_15 ;
}
return 0 ;
}
void F_25 ( struct V_27 * V_28 )
{
F_18 ( V_28 -> V_39 , V_28 -> V_40 ) ;
F_16 ( V_28 ) ;
}
int F_26 ( struct V_9 * V_10 , unsigned long V_37 )
{
struct V_27 * V_28 ;
int V_41 ;
V_28 = F_15 ( sizeof( struct V_27 ) , V_25 ) ;
if ( V_28 == NULL )
return - V_26 ;
V_10 -> V_42 = ( void * ) V_28 ;
V_41 = F_22 ( V_28 , V_10 , V_10 -> V_33 , V_37 ) ;
if ( V_41 ) {
F_27 ( & V_10 -> V_33 -> V_10 , L_6 , V_41 ) ;
goto V_43;
}
V_41 = F_28 ( V_28 ) ;
if ( V_41 )
F_27 ( & V_10 -> V_33 -> V_10 , L_7 ) ;
V_41 = F_29 ( V_28 ) ;
if ( V_41 )
F_27 ( & V_10 -> V_33 -> V_10 , L_8 , V_41 ) ;
V_10 -> V_44 . V_45 = ( void * ) & V_46 ;
V_43:
if ( V_41 )
F_30 ( V_10 ) ;
return V_41 ;
}
int F_30 ( struct V_9 * V_10 )
{
struct V_27 * V_28 = V_10 -> V_42 ;
if ( V_28 == NULL )
return 0 ;
F_31 ( V_28 ) ;
F_32 ( V_28 ) ;
F_25 ( V_28 ) ;
F_5 ( V_28 ) ;
V_10 -> V_42 = NULL ;
return 0 ;
}
int F_33 ( struct V_9 * V_10 ,
T_1 V_47 , bool V_48 ,
struct V_14 * * V_5 )
{
struct V_49 * V_50 ;
int V_15 ;
* V_5 = NULL ;
V_47 = F_34 ( V_47 , V_51 ) ;
if ( V_47 == 0 )
return - V_22 ;
V_15 = F_35 ( V_10 , V_47 , 0 , 0 , & V_50 ) ;
if ( V_15 ) {
if ( V_15 != - V_52 )
F_9 ( L_9 ) ;
return V_15 ;
}
* V_5 = & V_50 -> V_53 ;
return 0 ;
}
int F_36 ( struct V_6 * V_54 ,
struct V_9 * V_10 ,
struct V_55 * args )
{
int V_15 ;
struct V_14 * V_56 ;
T_1 V_8 ;
args -> V_57 = args -> V_58 * ( ( args -> V_19 + 7 ) / 8 ) ;
args -> V_47 = args -> V_57 * args -> V_59 ;
V_15 = F_33 ( V_10 , args -> V_47 , false ,
& V_56 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_37 ( V_54 , V_56 , & V_8 ) ;
F_3 ( V_56 ) ;
if ( V_15 )
return V_15 ;
args -> V_8 = V_8 ;
return 0 ;
}
int F_38 ( struct V_6 * V_54 ,
struct V_9 * V_10 ,
T_2 V_8 )
{
return F_39 ( V_54 , V_8 ) ;
}
int F_40 ( struct V_14 * V_5 )
{
F_41 () ;
return 0 ;
}
void F_42 ( struct V_49 * * V_60 )
{
struct V_61 * V_62 ;
if ( ( * V_60 ) == NULL )
return;
V_62 = & ( ( * V_60 ) -> V_60 ) ;
F_43 ( & V_62 ) ;
if ( V_62 == NULL )
* V_60 = NULL ;
}
void F_44 ( struct V_14 * V_5 )
{
struct V_49 * V_49 = F_45 ( V_5 ) ;
if ( ! V_49 )
return;
F_42 ( & V_49 ) ;
}
static inline T_3 F_46 ( struct V_49 * V_60 )
{
return V_60 -> V_60 . V_63 ;
}
int
F_47 ( struct V_6 * V_54 ,
struct V_9 * V_10 ,
T_2 V_8 ,
T_4 * V_64 )
{
struct V_14 * V_5 ;
int V_15 ;
struct V_49 * V_60 ;
F_48 ( & V_10 -> V_65 ) ;
V_5 = F_14 ( V_10 , V_54 , V_8 ) ;
if ( V_5 == NULL ) {
V_15 = - V_24 ;
goto V_66;
}
V_60 = F_45 ( V_5 ) ;
* V_64 = F_46 ( V_60 ) ;
F_49 ( V_5 ) ;
V_15 = 0 ;
V_66:
F_50 ( & V_10 -> V_65 ) ;
return V_15 ;
}
