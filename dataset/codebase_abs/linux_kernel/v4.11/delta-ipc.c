static inline T_1 F_1 ( struct V_1 * V_2 , void * V_3 )
{
return ( V_2 -> V_4 -> V_5 + ( V_3 - V_2 -> V_4 -> V_3 ) ) ;
}
static inline bool F_2 ( struct V_1 * V_2 ,
void * V_6 , T_2 V_7 )
{
return ( ( V_6 >= V_2 -> V_4 -> V_3 ) &&
( ( V_6 + V_7 ) <= ( V_2 -> V_4 -> V_3 + V_2 -> V_4 -> V_7 ) ) ) ;
}
static void F_3 ( struct V_1 * V_2 ,
enum V_8 V_9 ,
struct V_10 * V_11 )
{
V_11 -> V_12 = V_13 ;
V_11 -> V_14 = F_4 ( V_2 ) ;
V_11 -> V_15 = V_2 -> V_15 ;
V_11 -> V_9 = V_9 ;
}
int F_5 ( struct V_16 * V_17 , const char * V_18 ,
struct V_19 * V_20 , T_2 V_21 ,
struct V_22 * * V_4 , void * * V_23 )
{
struct V_24 * V_25 = V_17 -> V_26 ;
struct V_27 * V_27 = V_25 -> V_27 ;
struct V_1 * V_2 = & V_17 -> V_28 ;
struct V_29 V_30 ;
struct V_22 * V_31 = & V_2 -> V_32 ;
int V_33 ;
if ( ! V_27 ) {
F_6 ( V_25 -> V_26 ,
L_1 ,
V_17 -> V_18 ) ;
V_17 -> V_34 ++ ;
return - V_35 ;
}
if ( ! V_18 ) {
F_6 ( V_25 -> V_26 ,
L_2 ,
V_17 -> V_18 ) ;
return - V_35 ;
}
if ( ! V_20 || ! V_20 -> V_6 || ! V_20 -> V_7 ) {
F_6 ( V_25 -> V_26 ,
L_3 ,
V_17 -> V_18 ) ;
return - V_35 ;
}
if ( ! V_21 ) {
F_6 ( V_25 -> V_26 ,
L_4 ,
V_17 -> V_18 ) ;
return - V_35 ;
}
if ( V_20 -> V_7 > V_21 ) {
F_6 ( V_25 -> V_26 ,
L_5 ,
V_17 -> V_18 ,
V_20 -> V_7 , V_2 -> V_4 -> V_7 ) ;
return - V_35 ;
}
F_7 ( & V_2 -> V_36 ) ;
V_33 = F_8 ( V_17 , V_21 ,
L_6 , V_31 ) ;
if ( V_33 )
return V_33 ;
V_2 -> V_4 = V_31 ;
F_3 ( V_2 , V_37 , & V_30 . V_11 ) ;
V_30 . V_21 = V_21 ;
V_30 . V_38 = V_2 -> V_4 -> V_5 ;
memcpy ( V_30 . V_18 , V_18 , sizeof( V_30 . V_18 ) ) ;
V_30 . V_18 [ sizeof( V_30 . V_18 ) - 1 ] = 0 ;
V_30 . V_39 = V_20 -> V_7 ;
memcpy ( V_2 -> V_4 -> V_3 , V_20 -> V_6 , V_30 . V_39 ) ;
V_30 . V_40 = V_2 -> V_4 -> V_5 ;
V_33 = F_9 ( V_27 -> V_41 , & V_30 , sizeof( V_30 ) ) ;
if ( V_33 ) {
F_6 ( V_25 -> V_26 ,
L_7 ,
V_17 -> V_18 ,
V_33 , V_18 , V_20 -> V_7 , V_20 -> V_6 ) ;
goto V_42;
}
if ( ! F_10
( & V_2 -> V_36 , F_11 ( V_43 ) ) ) {
F_6 ( V_25 -> V_26 ,
L_8 ,
V_17 -> V_18 ,
V_18 , V_20 -> V_7 , V_20 -> V_6 ) ;
V_33 = - V_44 ;
goto V_42;
}
if ( V_2 -> V_45 ) {
F_6 ( V_25 -> V_26 ,
L_9 ,
V_17 -> V_18 ,
V_2 -> V_45 , V_18 , V_20 -> V_7 , V_20 -> V_6 ) ;
V_33 = - V_46 ;
goto V_42;
}
* V_4 = V_2 -> V_4 ;
* V_23 = ( void * ) V_2 ;
return 0 ;
V_42:
V_17 -> V_34 ++ ;
if ( V_2 -> V_4 ) {
F_12 ( V_17 , V_2 -> V_4 ) ;
V_2 -> V_4 = NULL ;
}
return V_33 ;
}
int F_13 ( void * V_23 , struct V_19 * V_20 )
{
struct V_1 * V_2 = F_14 ( V_23 ) ;
struct V_16 * V_17 = F_15 ( V_2 ) ;
struct V_24 * V_25 = V_17 -> V_26 ;
struct V_27 * V_27 = V_25 -> V_27 ;
struct V_47 V_30 ;
int V_33 ;
if ( ! V_23 ) {
F_6 ( V_25 -> V_26 ,
L_10 ,
V_17 -> V_18 ) ;
return - V_35 ;
}
if ( ! V_27 ) {
F_6 ( V_25 -> V_26 ,
L_11 ,
V_17 -> V_18 ) ;
return - V_35 ;
}
if ( ! V_20 || ! V_20 -> V_6 || ! V_20 -> V_7 ) {
F_6 ( V_25 -> V_26 ,
L_12 ,
V_17 -> V_18 ) ;
return - V_35 ;
}
if ( V_20 -> V_7 > V_2 -> V_4 -> V_7 ) {
F_6 ( V_25 -> V_26 ,
L_13 ,
V_17 -> V_18 ,
V_20 -> V_7 , V_2 -> V_4 -> V_7 ) ;
return - V_35 ;
}
if ( ! F_2 ( V_2 , V_20 -> V_6 , V_20 -> V_7 ) ) {
F_6 ( V_25 -> V_26 ,
L_14 ,
V_17 -> V_18 ,
V_20 -> V_7 ,
V_20 -> V_6 ,
V_2 -> V_4 -> V_3 ,
V_2 -> V_4 -> V_3 + V_2 -> V_4 -> V_7 - 1 ) ;
return - V_35 ;
}
F_3 ( V_2 , V_48 , & V_30 . V_11 ) ;
V_30 . V_39 = V_20 -> V_7 ;
V_30 . V_40 = F_1 ( V_2 , V_20 -> V_6 ) ;
V_33 = F_9 ( V_27 -> V_41 , & V_30 , sizeof( V_30 ) ) ;
if ( V_33 ) {
F_6 ( V_25 -> V_26 ,
L_15 ,
V_17 -> V_18 ,
V_33 , V_20 -> V_7 , V_20 -> V_6 ) ;
V_17 -> V_34 ++ ;
return V_33 ;
}
if ( ! F_10
( & V_2 -> V_36 , F_11 ( V_43 ) ) ) {
F_6 ( V_25 -> V_26 ,
L_16 ,
V_17 -> V_18 ,
V_20 -> V_7 , V_20 -> V_6 ) ;
V_17 -> V_34 ++ ;
return - V_44 ;
}
if ( V_2 -> V_45 ) {
F_6 ( V_25 -> V_26 ,
L_17 ,
V_17 -> V_18 ,
V_2 -> V_45 , V_20 -> V_7 , V_20 -> V_6 ) ;
V_17 -> V_34 ++ ;
return - V_46 ;
}
return 0 ;
}
int F_16 ( void * V_23 , struct V_19 * V_20 ,
struct V_19 * V_49 )
{
struct V_1 * V_2 = F_14 ( V_23 ) ;
struct V_16 * V_17 = F_15 ( V_2 ) ;
struct V_24 * V_25 = V_17 -> V_26 ;
struct V_27 * V_27 = V_25 -> V_27 ;
struct V_50 V_30 ;
int V_33 ;
if ( ! V_23 ) {
F_6 ( V_25 -> V_26 ,
L_18 ,
V_17 -> V_18 ) ;
return - V_35 ;
}
if ( ! V_27 ) {
F_6 ( V_25 -> V_26 ,
L_19 ,
V_17 -> V_18 ) ;
return - V_35 ;
}
if ( ! V_20 || ! V_20 -> V_6 || ! V_20 -> V_7 ) {
F_6 ( V_25 -> V_26 ,
L_20 ,
V_17 -> V_18 ) ;
return - V_35 ;
}
if ( ! V_49 || ! V_49 -> V_6 || ! V_49 -> V_7 ) {
F_6 ( V_25 -> V_26 ,
L_21 ,
V_17 -> V_18 ) ;
return - V_35 ;
}
if ( V_20 -> V_7 + V_49 -> V_7 > V_2 -> V_4 -> V_7 ) {
F_6 ( V_25 -> V_26 ,
L_22 ,
V_17 -> V_18 ,
V_20 -> V_7 ,
V_49 -> V_7 ,
V_2 -> V_4 -> V_7 ) ;
return - V_35 ;
}
if ( ! F_2 ( V_2 , V_20 -> V_6 , V_20 -> V_7 ) ) {
F_6 ( V_25 -> V_26 ,
L_23 ,
V_17 -> V_18 ,
V_20 -> V_7 ,
V_20 -> V_6 ,
V_2 -> V_4 -> V_3 ,
V_2 -> V_4 -> V_3 + V_2 -> V_4 -> V_7 - 1 ) ;
return - V_35 ;
}
if ( ! F_2 ( V_2 , V_49 -> V_6 , V_49 -> V_7 ) ) {
F_6 ( V_25 -> V_26 ,
L_24 ,
V_17 -> V_18 ,
V_49 -> V_7 ,
V_49 -> V_6 ,
V_2 -> V_4 -> V_3 ,
V_2 -> V_4 -> V_3 + V_2 -> V_4 -> V_7 - 1 ) ;
return - V_35 ;
}
F_3 ( V_2 , V_51 , & V_30 . V_11 ) ;
V_30 . V_39 = V_20 -> V_7 ;
V_30 . V_40 = F_1 ( V_2 , V_20 -> V_6 ) ;
V_30 . V_52 = V_49 -> V_7 ;
V_30 . V_53 = F_1 ( V_2 , V_49 -> V_6 ) ;
V_33 = F_9 ( V_27 -> V_41 , & V_30 , sizeof( V_30 ) ) ;
if ( V_33 ) {
F_6 ( V_25 -> V_26 ,
L_25 ,
V_17 -> V_18 ,
V_33 , V_20 -> V_7 , V_20 -> V_6 ) ;
V_17 -> V_34 ++ ;
return V_33 ;
}
if ( ! F_10
( & V_2 -> V_36 , F_11 ( V_43 ) ) ) {
F_6 ( V_25 -> V_26 ,
L_26 ,
V_17 -> V_18 ,
V_20 -> V_7 , V_20 -> V_6 ) ;
V_17 -> V_34 ++ ;
return - V_44 ;
}
if ( V_2 -> V_45 ) {
F_6 ( V_25 -> V_26 ,
L_27 ,
V_17 -> V_18 ,
V_2 -> V_45 , V_20 -> V_7 , V_20 -> V_6 ) ;
V_17 -> V_34 ++ ;
return - V_46 ;
}
return 0 ;
}
void F_17 ( void * V_23 )
{
struct V_1 * V_2 = F_14 ( V_23 ) ;
struct V_16 * V_17 = F_15 ( V_2 ) ;
struct V_24 * V_25 = V_17 -> V_26 ;
struct V_27 * V_27 = V_25 -> V_27 ;
struct V_54 V_30 ;
int V_33 ;
if ( ! V_23 ) {
F_6 ( V_25 -> V_26 ,
L_28 ,
V_17 -> V_18 ) ;
return;
}
if ( V_2 -> V_4 ) {
F_12 ( V_17 , V_2 -> V_4 ) ;
V_2 -> V_4 = NULL ;
}
if ( ! V_27 ) {
F_6 ( V_25 -> V_26 ,
L_29 ,
V_17 -> V_18 ) ;
return;
}
F_3 ( V_2 , V_55 , & V_30 . V_11 ) ;
V_33 = F_9 ( V_27 -> V_41 , & V_30 , sizeof( V_30 ) ) ;
if ( V_33 ) {
F_6 ( V_25 -> V_26 ,
L_30 ,
V_17 -> V_18 , V_33 ) ;
V_17 -> V_34 ++ ;
return;
}
if ( ! F_10
( & V_2 -> V_36 , F_11 ( V_43 ) ) ) {
F_6 ( V_25 -> V_26 ,
L_31 ,
V_17 -> V_18 ) ;
V_17 -> V_34 ++ ;
return;
}
if ( V_2 -> V_45 ) {
F_6 ( V_25 -> V_26 ,
L_32 ,
V_17 -> V_18 , V_2 -> V_45 ) ;
V_17 -> V_34 ++ ;
}
}
static int F_18 ( struct V_27 * V_56 , void * V_6 ,
int V_57 , void * V_58 , T_2 V_59 )
{
struct V_1 * V_2 ;
struct V_60 * V_30 ;
if ( ! V_56 ) {
F_6 ( NULL , L_33 ) ;
return - V_35 ;
}
if ( ! V_6 || ! V_57 ) {
F_6 ( & V_56 -> V_26 ,
L_34 , V_59 ) ;
return - V_35 ;
}
if ( V_57 != sizeof( * V_30 ) ) {
F_6 ( & V_56 -> V_26 ,
L_35 ,
V_57 , V_59 , sizeof( * V_30 ) ) ;
return - V_35 ;
}
V_30 = (struct V_60 * ) V_6 ;
if ( V_30 -> V_11 . V_12 != V_13 ) {
F_6 ( & V_56 -> V_26 ,
L_36 ,
V_59 , V_30 -> V_11 . V_12 , V_13 ) ;
return - V_35 ;
}
V_2 = F_19 ( V_30 ) ;
if ( ! V_2 ) {
F_6 ( & V_56 -> V_26 ,
L_37 ,
V_59 ) ;
return - V_35 ;
}
if ( ! V_2 -> V_15 )
V_2 -> V_15 = F_20 ( V_30 ) ;
V_2 -> V_45 = V_30 -> V_42 ;
F_21 ( & V_2 -> V_36 ) ;
return 0 ;
}
static int F_22 ( struct V_27 * V_27 )
{
struct V_61 * V_62 = F_23 ( V_27 -> V_26 . V_63 ) ;
struct V_24 * V_25 = F_24 ( V_62 ) ;
V_25 -> V_27 = V_27 ;
return 0 ;
}
static void F_25 ( struct V_27 * V_27 )
{
struct V_61 * V_62 = F_23 ( V_27 -> V_26 . V_63 ) ;
struct V_24 * V_25 = F_24 ( V_62 ) ;
V_25 -> V_27 = NULL ;
}
int F_26 ( struct V_24 * V_25 )
{
V_25 -> V_61 = V_64 ;
return F_27 ( & V_25 -> V_61 ) ;
}
void F_28 ( struct V_24 * V_25 )
{
F_29 ( & V_25 -> V_61 ) ;
}
