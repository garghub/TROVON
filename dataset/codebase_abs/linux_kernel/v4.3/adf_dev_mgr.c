static int F_1 ( struct V_1 * V_2 )
{
return ( ( 7 * ( F_2 ( F_3 ( V_2 ) -> V_3 ) - 1 ) ) +
F_4 ( F_3 ( V_2 ) -> V_3 ) +
( F_2 ( F_3 ( V_2 ) -> V_3 ) - 1 ) ) ;
}
static int F_5 ( struct V_1 * V_2 )
{
return ( F_3 ( V_2 ) -> V_4 -> V_5 << 8 ) | F_1 ( V_2 ) ;
}
static struct V_6 * F_6 ( T_1 V_7 )
{
struct V_8 * V_9 ;
F_7 (itr, &vfs_table) {
struct V_6 * V_10 =
F_8 ( V_9 , struct V_6 , V_11 ) ;
if ( V_10 -> V_7 == V_7 )
return V_10 ;
}
return NULL ;
}
static int F_9 ( T_1 V_12 )
{
struct V_8 * V_9 ;
F_7 (itr, &vfs_table) {
struct V_6 * V_10 =
F_8 ( V_9 , struct V_6 , V_11 ) ;
if ( V_10 -> V_13 == V_12 )
return V_10 -> V_14 ;
}
return - 1 ;
}
void F_10 ( bool V_2 )
{
struct V_6 * V_15 ;
struct V_8 * V_10 , * V_16 ;
F_11 ( & V_17 ) ;
F_12 (ptr, tmp, &vfs_table) {
V_15 = F_8 ( V_10 , struct V_6 , V_11 ) ;
if ( V_15 -> V_7 != - 1 )
V_18 -- ;
if ( V_2 && V_15 -> V_7 == - 1 )
continue;
F_13 ( V_10 ) ;
F_14 ( V_15 ) ;
}
F_15 ( & V_17 ) ;
}
void F_16 ( struct V_19 * V_20 )
{
struct V_21 * V_22 = V_20 -> V_23 ;
struct V_8 * V_9 ;
int V_24 = 0 ;
F_7 (itr, &accel_table) {
struct V_1 * V_10 =
F_8 ( V_9 , struct V_1 , V_11 ) ;
if ( V_10 -> V_25 -> V_23 == V_22 )
V_10 -> V_25 -> V_26 = V_24 ++ ;
if ( V_24 == V_22 -> V_27 )
break;
}
}
int F_17 ( struct V_1 * V_28 ,
struct V_1 * V_29 )
{
struct V_8 * V_9 ;
int V_30 = 0 ;
if ( V_18 == V_31 ) {
F_18 ( & F_19 ( V_28 ) , L_1 ,
V_31 ) ;
return - V_32 ;
}
F_11 ( & V_17 ) ;
F_20 ( & V_28 -> V_33 , 0 ) ;
if ( ! V_28 -> V_34 || ( V_28 -> V_34 && ! V_29 ) ) {
struct V_6 * V_15 ;
F_7 (itr, &accel_table) {
struct V_1 * V_10 =
F_8 ( V_9 , struct V_1 , V_11 ) ;
if ( V_10 == V_28 ) {
V_30 = - V_35 ;
goto V_36;
}
}
F_21 ( & V_28 -> V_11 , & V_37 ) ;
V_28 -> V_38 = V_18 ++ ;
V_15 = F_22 ( sizeof( * V_15 ) , V_39 ) ;
if ( ! V_15 ) {
V_30 = - V_40 ;
goto V_36;
}
V_15 -> V_7 = ~ 0 ;
V_15 -> V_14 = V_28 -> V_38 ;
V_15 -> V_13 = V_15 -> V_14 ;
V_15 -> V_41 = true ;
F_21 ( & V_15 -> V_11 , & V_42 ) ;
} else if ( V_28 -> V_34 && V_29 ) {
struct V_43 * V_44 ;
struct V_6 * V_15 ;
V_44 = V_29 -> V_29 . V_44 + F_1 ( V_28 ) ;
V_15 = F_6 ( F_5 ( V_28 ) ) ;
if ( V_15 ) {
struct V_6 * V_45 ;
V_28 -> V_38 = V_15 -> V_14 ;
F_21 ( & V_28 -> V_11 , & V_37 ) ;
V_15 -> V_13 ++ ;
V_15 -> V_41 = true ;
V_45 = F_23 ( V_15 , V_11 ) ;
while ( V_45 && & V_45 -> V_11 != & V_42 ) {
V_45 -> V_13 ++ ;
V_45 = F_23 ( V_45 , V_11 ) ;
}
V_30 = 0 ;
goto V_36;
}
V_15 = F_22 ( sizeof( * V_15 ) , V_39 ) ;
if ( ! V_15 ) {
V_30 = - V_40 ;
goto V_36;
}
V_28 -> V_38 = V_18 ++ ;
F_21 ( & V_28 -> V_11 , & V_37 ) ;
V_15 -> V_7 = F_5 ( V_28 ) ;
V_15 -> V_14 = V_28 -> V_38 ;
V_15 -> V_13 = V_15 -> V_14 ;
V_15 -> V_41 = true ;
F_21 ( & V_15 -> V_11 , & V_42 ) ;
}
V_36:
F_15 ( & V_17 ) ;
return V_30 ;
}
struct V_8 * F_24 ( void )
{
return & V_37 ;
}
void F_25 ( struct V_1 * V_28 ,
struct V_1 * V_29 )
{
F_11 ( & V_17 ) ;
if ( ! V_28 -> V_34 || ( V_28 -> V_34 && ! V_29 ) ) {
V_18 -- ;
} else if ( V_28 -> V_34 && V_29 ) {
struct V_6 * V_15 , * V_45 ;
V_15 = F_6 ( F_5 ( V_28 ) ) ;
if ( ! V_15 ) {
F_18 ( & F_19 ( V_28 ) , L_2 ) ;
goto V_36;
}
V_15 -> V_13 -- ;
V_15 -> V_41 = false ;
V_45 = F_23 ( V_15 , V_11 ) ;
while ( V_45 && & V_45 -> V_11 != & V_42 ) {
V_45 -> V_13 -- ;
V_45 = F_23 ( V_45 , V_11 ) ;
}
}
V_36:
F_13 ( & V_28 -> V_11 ) ;
F_15 ( & V_17 ) ;
}
struct V_1 * F_26 ( void )
{
struct V_1 * V_46 = NULL ;
if ( ! F_27 ( & V_37 ) )
V_46 = F_28 ( & V_37 , struct V_1 ,
V_11 ) ;
return V_46 ;
}
struct V_1 * F_29 ( struct V_47 * V_47 )
{
struct V_8 * V_9 ;
F_11 ( & V_17 ) ;
F_7 (itr, &accel_table) {
struct V_1 * V_10 =
F_8 ( V_9 , struct V_1 , V_11 ) ;
if ( V_10 -> V_48 . V_47 == V_47 ) {
F_15 ( & V_17 ) ;
return V_10 ;
}
}
F_15 ( & V_17 ) ;
return NULL ;
}
struct V_1 * F_30 ( T_2 V_14 )
{
struct V_8 * V_9 ;
int V_49 ;
F_11 ( & V_17 ) ;
V_49 = F_9 ( V_14 ) ;
if ( V_49 < 0 )
goto V_36;
V_14 = V_49 ;
F_7 (itr, &accel_table) {
struct V_1 * V_10 =
F_8 ( V_9 , struct V_1 , V_11 ) ;
if ( V_10 -> V_38 == V_14 ) {
F_15 ( & V_17 ) ;
return V_10 ;
}
}
V_36:
F_15 ( & V_17 ) ;
return NULL ;
}
int F_31 ( T_2 V_14 )
{
if ( V_14 == V_50 )
return 0 ;
if ( F_30 ( V_14 ) )
return 0 ;
return - V_51 ;
}
static int F_32 ( void )
{
struct V_8 * V_9 ;
int V_52 = 0 ;
F_11 ( & V_17 ) ;
F_7 (itr, &vfs_table) {
struct V_6 * V_10 =
F_8 ( V_9 , struct V_6 , V_11 ) ;
if ( V_10 -> V_7 != ~ 0 && ! V_10 -> V_41 )
V_52 ++ ;
}
F_15 ( & V_17 ) ;
return V_52 ;
}
void F_33 ( T_2 * V_53 )
{
* V_53 = V_18 - F_32 () ;
}
int F_34 ( struct V_1 * V_28 )
{
return F_35 ( & V_28 -> V_33 ) != 0 ;
}
int F_36 ( struct V_1 * V_28 )
{
if ( F_37 ( 1 , & V_28 -> V_33 ) == 1 )
if ( ! F_38 ( V_28 -> V_54 ) )
return - V_32 ;
return 0 ;
}
void F_39 ( struct V_1 * V_28 )
{
if ( F_40 ( 1 , & V_28 -> V_33 ) == 0 )
F_41 ( V_28 -> V_54 ) ;
}
int F_42 ( struct V_1 * V_28 )
{
return F_43 ( V_55 , & V_28 -> V_56 ) ;
}
int F_44 ( struct V_1 * V_28 )
{
return F_43 ( V_57 , & V_28 -> V_56 ) ;
}
