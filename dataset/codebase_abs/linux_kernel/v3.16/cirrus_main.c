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
struct V_11 * V_5 ;
struct V_3 * V_4 ;
int V_12 ;
T_1 V_17 , V_18 ;
F_11 ( V_10 -> V_19 , & V_18 , & V_17 ) ;
if ( V_17 > 24 )
return F_12 ( - V_20 ) ;
V_5 = F_13 ( V_7 , V_16 , V_10 -> V_21 [ 0 ] ) ;
if ( V_5 == NULL )
return F_12 ( - V_22 ) ;
V_4 = F_14 ( sizeof( * V_4 ) , V_23 ) ;
if ( ! V_4 ) {
F_3 ( V_5 ) ;
return F_12 ( - V_24 ) ;
}
V_12 = F_6 ( V_7 , V_4 , V_10 , V_5 ) ;
if ( V_12 ) {
F_3 ( V_5 ) ;
F_5 ( V_4 ) ;
return F_12 ( V_12 ) ;
}
return & V_4 -> V_13 ;
}
static void F_15 ( struct V_25 * V_26 )
{
F_16 ( V_26 -> V_27 ) ;
V_26 -> V_27 = NULL ;
if ( V_26 -> V_28 . V_29 )
F_17 ( V_26 -> V_28 . V_29 , V_26 -> V_28 . V_30 ) ;
}
static int F_18 ( struct V_25 * V_26 )
{
V_26 -> V_28 . V_29 = F_19 ( V_26 -> V_7 -> V_31 , 0 ) ;
V_26 -> V_28 . V_30 = 4 * 1024 * 1024 ;
if ( ! F_20 ( V_26 -> V_28 . V_29 , V_26 -> V_28 . V_30 ,
L_2 ) ) {
F_9 ( L_3 ) ;
return - V_32 ;
}
return 0 ;
}
int F_21 ( struct V_25 * V_26 ,
struct V_6 * V_33 ,
struct V_34 * V_31 , T_2 V_35 )
{
int V_12 ;
V_26 -> V_7 = V_33 ;
V_26 -> V_35 = V_35 ;
V_26 -> V_36 = 1 ;
V_26 -> V_37 = F_19 ( V_26 -> V_7 -> V_31 , 1 ) ;
V_26 -> V_38 = F_22 ( V_26 -> V_7 -> V_31 , 1 ) ;
if ( ! F_20 ( V_26 -> V_37 , V_26 -> V_38 ,
L_4 ) ) {
F_9 ( L_5 ) ;
return - V_24 ;
}
V_26 -> V_27 = F_23 ( V_26 -> V_37 , V_26 -> V_38 ) ;
if ( V_26 -> V_27 == NULL )
return - V_24 ;
V_12 = F_18 ( V_26 ) ;
if ( V_12 ) {
F_17 ( V_26 -> V_37 , V_26 -> V_38 ) ;
return V_12 ;
}
return 0 ;
}
void F_24 ( struct V_25 * V_26 )
{
F_17 ( V_26 -> V_37 , V_26 -> V_38 ) ;
F_15 ( V_26 ) ;
}
int F_25 ( struct V_6 * V_7 , unsigned long V_35 )
{
struct V_25 * V_26 ;
int V_39 ;
V_26 = F_14 ( sizeof( struct V_25 ) , V_23 ) ;
if ( V_26 == NULL )
return - V_24 ;
V_7 -> V_40 = ( void * ) V_26 ;
V_39 = F_21 ( V_26 , V_7 , V_7 -> V_31 , V_35 ) ;
if ( V_39 ) {
F_26 ( & V_7 -> V_31 -> V_7 , L_6 , V_39 ) ;
goto V_41;
}
V_39 = F_27 ( V_26 ) ;
if ( V_39 )
F_26 ( & V_7 -> V_31 -> V_7 , L_7 ) ;
V_39 = F_28 ( V_26 ) ;
if ( V_39 )
F_26 ( & V_7 -> V_31 -> V_7 , L_8 , V_39 ) ;
V_7 -> V_42 . V_43 = ( void * ) & V_44 ;
V_41:
if ( V_39 )
F_29 ( V_7 ) ;
return V_39 ;
}
int F_29 ( struct V_6 * V_7 )
{
struct V_25 * V_26 = V_7 -> V_40 ;
if ( V_26 == NULL )
return 0 ;
F_30 ( V_26 ) ;
F_31 ( V_26 ) ;
F_24 ( V_26 ) ;
F_5 ( V_26 ) ;
V_7 -> V_40 = NULL ;
return 0 ;
}
int F_32 ( struct V_6 * V_7 ,
T_1 V_45 , bool V_46 ,
struct V_11 * * V_5 )
{
struct V_47 * V_48 ;
int V_12 ;
* V_5 = NULL ;
V_45 = F_33 ( V_45 , V_49 ) ;
if ( V_45 == 0 )
return - V_20 ;
V_12 = F_34 ( V_7 , V_45 , 0 , 0 , & V_48 ) ;
if ( V_12 ) {
if ( V_12 != - V_50 )
F_9 ( L_9 ) ;
return V_12 ;
}
* V_5 = & V_48 -> V_51 ;
return 0 ;
}
int F_35 ( struct V_15 * V_52 ,
struct V_6 * V_7 ,
struct V_53 * args )
{
int V_12 ;
struct V_11 * V_54 ;
T_1 V_55 ;
args -> V_56 = args -> V_57 * ( ( args -> V_17 + 7 ) / 8 ) ;
args -> V_45 = args -> V_56 * args -> V_58 ;
V_12 = F_32 ( V_7 , args -> V_45 , false ,
& V_54 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_36 ( V_52 , V_54 , & V_55 ) ;
F_3 ( V_54 ) ;
if ( V_12 )
return V_12 ;
args -> V_55 = V_55 ;
return 0 ;
}
static void F_37 ( struct V_47 * * V_59 )
{
struct V_60 * V_61 ;
if ( ( * V_59 ) == NULL )
return;
V_61 = & ( ( * V_59 ) -> V_59 ) ;
F_38 ( & V_61 ) ;
* V_59 = NULL ;
}
void F_39 ( struct V_11 * V_5 )
{
struct V_47 * V_47 = F_40 ( V_5 ) ;
F_37 ( & V_47 ) ;
}
static inline T_3 F_41 ( struct V_47 * V_59 )
{
return F_42 ( & V_59 -> V_59 . V_62 ) ;
}
int
F_43 ( struct V_15 * V_52 ,
struct V_6 * V_7 ,
T_2 V_55 ,
T_4 * V_63 )
{
struct V_11 * V_5 ;
int V_12 ;
struct V_47 * V_59 ;
F_44 ( & V_7 -> V_64 ) ;
V_5 = F_13 ( V_7 , V_52 , V_55 ) ;
if ( V_5 == NULL ) {
V_12 = - V_22 ;
goto V_65;
}
V_59 = F_40 ( V_5 ) ;
* V_63 = F_41 ( V_59 ) ;
F_45 ( V_5 ) ;
V_12 = 0 ;
V_65:
F_46 ( & V_7 -> V_64 ) ;
return V_12 ;
}
