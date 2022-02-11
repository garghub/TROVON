static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 =
F_2 ( V_3 , struct V_4 , V_3 ) ;
return & V_5 -> V_6 ;
}
static enum V_7 F_3 ( struct V_2 * V_3 )
{
enum V_7 V_8 = V_9 ;
struct V_10 * V_11 = & F_1 ( V_3 ) -> V_12 . V_13 ;
if ( F_4 ( V_11 , & V_8 ) )
F_5 ( L_1 ) ;
else
F_6 ( L_2 ,
V_8 == V_14 ? L_3 : L_4 ) ;
return V_8 ;
}
static int F_7 ( struct V_2 * V_3 ,
enum V_7 V_15 , bool V_16 )
{
int V_17 ;
enum V_7 V_8 ;
struct V_10 * V_11 = & F_1 ( V_3 ) -> V_12 . V_13 ;
V_17 = F_4 ( V_11 , & V_8 ) ;
if ( V_17 ) {
F_5 ( L_1 ) ;
return V_17 ;
}
if ( V_8 == V_15 ) {
F_6 ( L_5 ) ;
return 0 ;
}
V_17 = F_8 ( V_11 , V_15 ) ;
if ( V_17 < 0 ) {
F_5 ( L_6 ) ;
return V_17 ;
}
V_3 -> V_15 = V_15 ;
F_6 ( L_7 ) ;
return 0 ;
}
static bool F_9 ( struct V_2 * V_3 )
{
enum V_18 V_19 ;
struct V_10 * V_11 = & F_1 ( V_3 ) -> V_12 . V_13 ;
V_19 = F_10 ( V_11 ) ;
if ( V_19 != V_20 ) {
F_6 ( L_8 ,
F_11 ( V_19 ) ) ;
return false ;
}
F_6 ( L_9 ) ;
V_3 -> V_15 = F_3 ( V_3 ) ;
V_3 -> V_21 = true ;
return true ;
}
static void F_12 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
unsigned long V_22 = V_23 ;
if ( ! V_3 -> V_24 )
return;
while ( 1 ) {
struct V_25 V_26 ;
if ( ! F_13 ( V_1 , & V_26 ) )
return;
if ( ! memcmp ( & V_1 -> V_26 , & V_26 , sizeof( V_26 ) ) ) {
F_6 ( L_10 ,
F_14 ( V_23 - V_22 ) ) ;
return;
}
if ( F_15 ( V_23 , V_22 + F_16 ( 1000 ) ) )
break;
F_17 ( 10000 , 15000 ) ;
}
F_6 ( L_11 ) ;
}
void F_18 ( struct V_2 * V_3 )
{
F_12 ( V_3 ) ;
if ( F_7 ( V_3 , V_14 , true ) )
F_5 ( L_12 ) ;
else
F_6 ( L_13 ) ;
}
bool F_19 ( struct V_4 * V_27 )
{
struct V_1 * V_6 = & V_27 -> V_6 ;
struct V_2 * V_3 = & V_27 -> V_3 ;
struct V_28 * V_29 = V_27 -> V_30 . V_30 . V_29 ;
struct V_31 * V_32 = F_20 ( V_29 ) ;
if ( ! F_21 ( V_32 ) ) {
F_5 ( L_14 ) ;
return false ;
}
V_3 -> V_21 = false ;
V_3 -> V_15 = V_9 ;
if ( ! F_9 ( V_3 ) ) {
F_5 ( L_15 ) ;
return false ;
}
if ( V_3 -> V_21 && V_3 -> V_15 != V_14 ) {
if ( F_7 ( V_3 , V_14 ,
true ) < 0 ) {
F_5 ( L_16 ) ;
return false ;
}
}
if ( ! F_22 ( V_6 ) ) {
F_5 ( L_17 ) ;
return false ;
}
V_3 -> V_24 = F_23 ( V_6 ) ;
F_6 ( L_18 ) ;
return true ;
}
