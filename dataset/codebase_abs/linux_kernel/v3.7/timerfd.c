static enum V_1 F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 , struct V_4 , V_6 ) ;
unsigned long V_7 ;
F_3 ( & V_5 -> V_8 . V_9 , V_7 ) ;
V_5 -> V_10 = 1 ;
V_5 -> V_11 ++ ;
F_4 ( & V_5 -> V_8 ) ;
F_5 ( & V_5 -> V_8 . V_9 , V_7 ) ;
return V_12 ;
}
void F_6 ( void )
{
T_1 V_13 = F_7 () ;
struct V_4 * V_5 ;
unsigned long V_7 ;
F_8 () ;
F_9 (ctx, &cancel_list, clist) {
if ( ! V_5 -> V_14 )
continue;
F_3 ( & V_5 -> V_8 . V_9 , V_7 ) ;
if ( V_5 -> V_13 . V_15 != V_13 . V_15 ) {
V_5 -> V_13 . V_15 = V_16 ;
V_5 -> V_11 ++ ;
F_4 ( & V_5 -> V_8 ) ;
}
F_5 ( & V_5 -> V_8 . V_9 , V_7 ) ;
}
F_10 () ;
}
static void F_11 ( struct V_4 * V_5 )
{
if ( V_5 -> V_14 ) {
V_5 -> V_14 = false ;
F_12 ( & V_17 ) ;
F_13 ( & V_5 -> V_18 ) ;
F_14 ( & V_17 ) ;
}
}
static bool F_15 ( struct V_4 * V_5 )
{
if ( ! V_5 -> V_14 || V_5 -> V_13 . V_15 != V_16 )
return false ;
V_5 -> V_13 = F_7 () ;
return true ;
}
static void F_16 ( struct V_4 * V_5 , int V_7 )
{
if ( V_5 -> V_19 == V_20 && ( V_7 & V_21 ) &&
( V_7 & V_22 ) ) {
if ( ! V_5 -> V_14 ) {
V_5 -> V_14 = true ;
F_12 ( & V_17 ) ;
F_17 ( & V_5 -> V_18 , & V_23 ) ;
F_14 ( & V_17 ) ;
}
} else if ( V_5 -> V_14 ) {
F_11 ( V_5 ) ;
}
}
static T_1 F_18 ( struct V_4 * V_5 )
{
T_1 V_24 ;
V_24 = F_19 ( & V_5 -> V_6 ) ;
return V_24 . V_15 < 0 ? F_20 ( 0 , 0 ) : V_24 ;
}
static int F_21 ( struct V_4 * V_5 , int V_7 ,
const struct V_25 * V_26 )
{
enum V_27 V_28 ;
T_1 V_29 ;
int V_19 = V_5 -> V_19 ;
V_28 = ( V_7 & V_21 ) ?
V_30 : V_31 ;
V_29 = F_22 ( V_26 -> V_32 ) ;
V_5 -> V_10 = 0 ;
V_5 -> V_11 = 0 ;
V_5 -> V_33 = F_22 ( V_26 -> V_34 ) ;
F_23 ( & V_5 -> V_6 , V_19 , V_28 ) ;
F_24 ( & V_5 -> V_6 , V_29 ) ;
V_5 -> V_6 . V_35 = F_1 ;
if ( V_29 . V_15 != 0 ) {
F_25 ( & V_5 -> V_6 , V_29 , V_28 ) ;
if ( F_15 ( V_5 ) )
return - V_36 ;
}
return 0 ;
}
static int F_26 ( struct V_37 * V_37 , struct V_38 * V_38 )
{
struct V_4 * V_5 = V_38 -> V_39 ;
F_11 ( V_5 ) ;
F_27 ( & V_5 -> V_6 ) ;
F_28 ( V_5 , V_40 ) ;
return 0 ;
}
static unsigned int F_29 ( struct V_38 * V_38 , T_2 * V_41 )
{
struct V_4 * V_5 = V_38 -> V_39 ;
unsigned int V_42 = 0 ;
unsigned long V_7 ;
F_30 ( V_38 , & V_5 -> V_8 , V_41 ) ;
F_3 ( & V_5 -> V_8 . V_9 , V_7 ) ;
if ( V_5 -> V_11 )
V_42 |= V_43 ;
F_5 ( & V_5 -> V_8 . V_9 , V_7 ) ;
return V_42 ;
}
static T_3 F_31 ( struct V_38 * V_38 , char T_4 * V_44 , T_5 V_45 ,
T_6 * V_46 )
{
struct V_4 * V_5 = V_38 -> V_39 ;
T_3 V_47 ;
T_7 V_11 = 0 ;
if ( V_45 < sizeof( V_11 ) )
return - V_48 ;
F_32 ( & V_5 -> V_8 . V_9 ) ;
if ( V_38 -> V_49 & V_50 )
V_47 = - V_51 ;
else
V_47 = F_33 ( V_5 -> V_8 , V_5 -> V_11 ) ;
if ( F_15 ( V_5 ) ) {
V_5 -> V_11 = 0 ;
V_5 -> V_10 = 0 ;
V_47 = - V_36 ;
}
if ( V_5 -> V_11 ) {
V_11 = V_5 -> V_11 ;
if ( V_5 -> V_10 && V_5 -> V_33 . V_15 ) {
V_11 += F_34 ( & V_5 -> V_6 ,
V_5 -> V_33 ) - 1 ;
V_1 ( & V_5 -> V_6 ) ;
}
V_5 -> V_10 = 0 ;
V_5 -> V_11 = 0 ;
}
F_35 ( & V_5 -> V_8 . V_9 ) ;
if ( V_11 )
V_47 = F_36 ( V_11 , ( T_7 T_4 * ) V_44 ) ? - V_52 : sizeof( V_11 ) ;
return V_47 ;
}
static int F_37 ( int V_53 , struct V_53 * V_54 )
{
struct V_53 V_55 = F_38 ( V_53 ) ;
if ( ! V_55 . V_38 )
return - V_56 ;
if ( V_55 . V_38 -> V_57 != & V_58 ) {
F_39 ( V_55 ) ;
return - V_48 ;
}
* V_54 = V_55 ;
return 0 ;
}
