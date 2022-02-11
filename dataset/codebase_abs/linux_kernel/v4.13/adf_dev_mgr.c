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
if ( V_15 -> V_7 != - 1 ) {
V_18 [ V_15 -> V_14 ] = 0 ;
V_19 -- ;
}
if ( V_2 && V_15 -> V_7 == - 1 )
continue;
F_13 ( V_10 ) ;
F_14 ( V_15 ) ;
}
F_15 ( & V_17 ) ;
}
void F_16 ( struct V_20 * V_21 )
{
struct V_22 * V_23 = V_21 -> V_24 ;
struct V_8 * V_9 ;
int V_25 = 0 ;
F_7 (itr, &accel_table) {
struct V_1 * V_10 =
F_8 ( V_9 , struct V_1 , V_11 ) ;
if ( V_10 -> V_26 -> V_24 == V_23 )
V_10 -> V_26 -> V_27 = V_25 ++ ;
if ( V_25 == V_23 -> V_28 )
break;
}
}
static unsigned int F_17 ( void )
{
unsigned int V_25 ;
for ( V_25 = 0 ; V_25 < V_29 ; V_25 ++ ) {
if ( ! V_18 [ V_25 ] ) {
V_18 [ V_25 ] = 1 ;
return V_25 ;
}
}
return V_29 + 1 ;
}
int F_18 ( struct V_1 * V_30 ,
struct V_1 * V_31 )
{
struct V_8 * V_9 ;
int V_32 = 0 ;
if ( V_19 == V_29 ) {
F_19 ( & F_20 ( V_30 ) , L_1 ,
V_29 ) ;
return - V_33 ;
}
F_11 ( & V_17 ) ;
F_21 ( & V_30 -> V_34 , 0 ) ;
if ( ! V_30 -> V_35 || ( V_30 -> V_35 && ! V_31 ) ) {
struct V_6 * V_15 ;
F_7 (itr, &accel_table) {
struct V_1 * V_10 =
F_8 ( V_9 , struct V_1 , V_11 ) ;
if ( V_10 == V_30 ) {
V_32 = - V_36 ;
goto V_37;
}
}
F_22 ( & V_30 -> V_11 , & V_38 ) ;
V_30 -> V_39 = F_17 () ;
if ( V_30 -> V_39 > V_29 ) {
V_32 = - V_33 ;
goto V_37;
}
V_19 ++ ;
V_15 = F_23 ( sizeof( * V_15 ) , V_40 ) ;
if ( ! V_15 ) {
V_32 = - V_41 ;
goto V_37;
}
V_15 -> V_7 = ~ 0 ;
V_15 -> V_14 = V_30 -> V_39 ;
V_15 -> V_13 = V_15 -> V_14 ;
V_15 -> V_42 = true ;
F_22 ( & V_15 -> V_11 , & V_43 ) ;
} else if ( V_30 -> V_35 && V_31 ) {
struct V_44 * V_45 ;
struct V_6 * V_15 ;
V_45 = V_31 -> V_31 . V_45 + F_1 ( V_30 ) ;
V_15 = F_6 ( F_5 ( V_30 ) ) ;
if ( V_15 ) {
struct V_6 * V_46 ;
V_30 -> V_39 = V_15 -> V_14 ;
F_22 ( & V_30 -> V_11 , & V_38 ) ;
V_15 -> V_13 ++ ;
V_15 -> V_42 = true ;
V_46 = F_24 ( V_15 , V_11 ) ;
while ( V_46 && & V_46 -> V_11 != & V_43 ) {
V_46 -> V_13 ++ ;
V_46 = F_24 ( V_46 , V_11 ) ;
}
V_32 = 0 ;
goto V_37;
}
V_15 = F_23 ( sizeof( * V_15 ) , V_40 ) ;
if ( ! V_15 ) {
V_32 = - V_41 ;
goto V_37;
}
V_30 -> V_39 = F_17 () ;
if ( V_30 -> V_39 > V_29 ) {
F_14 ( V_15 ) ;
V_32 = - V_33 ;
goto V_37;
}
V_19 ++ ;
F_22 ( & V_30 -> V_11 , & V_38 ) ;
V_15 -> V_7 = F_5 ( V_30 ) ;
V_15 -> V_14 = V_30 -> V_39 ;
V_15 -> V_13 = V_15 -> V_14 ;
V_15 -> V_42 = true ;
F_22 ( & V_15 -> V_11 , & V_43 ) ;
}
V_37:
F_15 ( & V_17 ) ;
return V_32 ;
}
struct V_8 * F_25 ( void )
{
return & V_38 ;
}
void F_26 ( struct V_1 * V_30 ,
struct V_1 * V_31 )
{
F_11 ( & V_17 ) ;
if ( ! V_30 -> V_35 || ( V_30 -> V_35 && ! V_31 ) ) {
V_18 [ V_30 -> V_39 ] = 0 ;
V_19 -- ;
} else if ( V_30 -> V_35 && V_31 ) {
struct V_6 * V_15 , * V_46 ;
V_15 = F_6 ( F_5 ( V_30 ) ) ;
if ( ! V_15 ) {
F_19 ( & F_20 ( V_30 ) , L_2 ) ;
goto V_37;
}
V_15 -> V_13 -- ;
V_15 -> V_42 = false ;
V_46 = F_24 ( V_15 , V_11 ) ;
while ( V_46 && & V_46 -> V_11 != & V_43 ) {
V_46 -> V_13 -- ;
V_46 = F_24 ( V_46 , V_11 ) ;
}
}
V_37:
F_13 ( & V_30 -> V_11 ) ;
F_15 ( & V_17 ) ;
}
struct V_1 * F_27 ( void )
{
struct V_1 * V_47 = NULL ;
if ( ! F_28 ( & V_38 ) )
V_47 = F_29 ( & V_38 , struct V_1 ,
V_11 ) ;
return V_47 ;
}
struct V_1 * F_30 ( struct V_48 * V_48 )
{
struct V_8 * V_9 ;
F_11 ( & V_17 ) ;
F_7 (itr, &accel_table) {
struct V_1 * V_10 =
F_8 ( V_9 , struct V_1 , V_11 ) ;
if ( V_10 -> V_49 . V_48 == V_48 ) {
F_15 ( & V_17 ) ;
return V_10 ;
}
}
F_15 ( & V_17 ) ;
return NULL ;
}
struct V_1 * F_31 ( T_2 V_14 )
{
struct V_8 * V_9 ;
int V_50 ;
F_11 ( & V_17 ) ;
V_50 = F_9 ( V_14 ) ;
if ( V_50 < 0 )
goto V_37;
V_14 = V_50 ;
F_7 (itr, &accel_table) {
struct V_1 * V_10 =
F_8 ( V_9 , struct V_1 , V_11 ) ;
if ( V_10 -> V_39 == V_14 ) {
F_15 ( & V_17 ) ;
return V_10 ;
}
}
V_37:
F_15 ( & V_17 ) ;
return NULL ;
}
int F_32 ( T_2 V_14 )
{
if ( V_14 == V_51 )
return 0 ;
if ( F_31 ( V_14 ) )
return 0 ;
return - V_52 ;
}
static int F_33 ( void )
{
struct V_8 * V_9 ;
int V_53 = 0 ;
F_11 ( & V_17 ) ;
F_7 (itr, &vfs_table) {
struct V_6 * V_10 =
F_8 ( V_9 , struct V_6 , V_11 ) ;
if ( V_10 -> V_7 != ~ 0 && ! V_10 -> V_42 )
V_53 ++ ;
}
F_15 ( & V_17 ) ;
return V_53 ;
}
void F_34 ( T_2 * V_54 )
{
* V_54 = V_19 - F_33 () ;
}
int F_35 ( struct V_1 * V_30 )
{
return F_36 ( & V_30 -> V_34 ) != 0 ;
}
int F_37 ( struct V_1 * V_30 )
{
if ( F_38 ( 1 , & V_30 -> V_34 ) == 1 )
if ( ! F_39 ( V_30 -> V_55 ) )
return - V_33 ;
return 0 ;
}
void F_40 ( struct V_1 * V_30 )
{
if ( F_41 ( 1 , & V_30 -> V_34 ) == 0 )
F_42 ( V_30 -> V_55 ) ;
}
int F_43 ( struct V_1 * V_30 )
{
return F_44 ( V_56 , & V_30 -> V_57 ) ;
}
int F_45 ( struct V_1 * V_30 )
{
return F_44 ( V_58 , & V_30 -> V_57 ) ;
}
