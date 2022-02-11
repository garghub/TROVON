static unsigned int F_1 ( struct V_1 V_2 )
{
return F_2 ( V_2 . V_3 , V_4 ) ;
}
static struct V_5 * F_3 ( struct V_1 V_2 ,
enum V_6 type )
{
struct V_5 * V_7 , * V_3 = NULL ;
unsigned int V_8 = F_1 ( V_2 ) ;
F_4 () ;
F_5 (r,
&vmci_resource_table.entries[idx], node) {
T_1 V_9 = V_7 -> V_2 . V_10 ;
T_1 V_11 = V_7 -> V_2 . V_3 ;
if ( V_7 -> type == type &&
V_11 == V_2 . V_3 &&
( V_9 == V_2 . V_10 || V_9 == V_12 ) ) {
V_3 = V_7 ;
break;
}
}
F_6 () ;
return V_3 ;
}
static T_1 F_7 ( T_1 V_13 ,
enum V_6 V_14 )
{
static T_1 V_15 = V_16 + 1 ;
T_1 V_17 = V_15 ;
T_1 V_18 ;
do {
struct V_1 V_2 ;
V_18 = V_15 ;
V_15 ++ ;
if ( F_8 ( V_15 == V_12 ) ) {
V_15 = V_16 + 1 ;
}
V_2 = F_9 ( V_13 , V_18 ) ;
if ( ! F_3 ( V_2 , V_14 ) )
return V_18 ;
} while ( V_15 != V_17 );
return V_12 ;
}
int F_10 ( struct V_5 * V_3 ,
enum V_6 V_14 ,
struct V_1 V_2 )
{
unsigned int V_8 ;
int V_19 ;
F_11 ( & V_20 . V_21 ) ;
if ( V_2 . V_3 == V_12 ) {
V_2 . V_3 = F_7 ( V_2 . V_10 ,
V_14 ) ;
if ( V_2 . V_3 == V_12 ) {
V_19 = V_22 ;
goto V_23;
}
} else if ( F_3 ( V_2 , V_14 ) ) {
V_19 = V_24 ;
goto V_23;
}
V_3 -> V_2 = V_2 ;
V_3 -> type = V_14 ;
F_12 ( & V_3 -> V_25 ) ;
F_13 ( & V_3 -> V_26 ) ;
F_14 ( & V_3 -> V_27 ) ;
V_8 = F_1 ( V_3 -> V_2 ) ;
F_15 ( & V_3 -> V_25 , & V_20 . V_28 [ V_8 ] ) ;
V_19 = V_29 ;
V_23:
F_16 ( & V_20 . V_21 ) ;
return V_19 ;
}
void F_17 ( struct V_5 * V_3 )
{
struct V_1 V_2 = V_3 -> V_2 ;
unsigned int V_8 = F_1 ( V_2 ) ;
struct V_5 * V_7 ;
F_11 ( & V_20 . V_21 ) ;
F_18 (r, &vmci_resource_table.entries[idx], node) {
if ( F_19 ( V_7 -> V_2 , V_3 -> V_2 ) ) {
F_20 ( & V_7 -> V_25 ) ;
break;
}
}
F_16 ( & V_20 . V_21 ) ;
F_21 () ;
F_22 ( V_3 ) ;
F_23 ( & V_3 -> V_27 ) ;
}
struct V_5 *
F_24 ( struct V_1 V_30 ,
enum V_6 V_14 )
{
struct V_5 * V_7 , * V_3 = NULL ;
F_4 () ;
V_7 = F_3 ( V_30 , V_14 ) ;
if ( V_7 &&
( V_14 == V_7 -> type ||
V_14 == V_31 ) ) {
V_3 = F_25 ( V_7 ) ;
}
F_6 () ;
return V_3 ;
}
struct V_5 * F_25 ( struct V_5 * V_3 )
{
F_26 ( & V_3 -> V_26 ) ;
return V_3 ;
}
static void F_27 ( struct V_26 * V_26 )
{
struct V_5 * V_3 =
F_28 ( V_26 , struct V_5 , V_26 ) ;
F_29 ( ! F_30 ( & V_3 -> V_25 ) ) ;
F_31 ( & V_3 -> V_27 ) ;
}
int F_22 ( struct V_5 * V_3 )
{
return F_32 ( & V_3 -> V_26 , F_27 ) ?
V_32 : V_29 ;
}
struct V_1 F_33 ( struct V_5 * V_3 )
{
return V_3 -> V_2 ;
}
