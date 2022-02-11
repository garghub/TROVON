static void F_1 ( struct V_1 * V_2 , unsigned long V_3 )
{
unsigned long V_4 ;
F_2 ( & V_2 -> V_5 , V_4 ) ;
V_2 -> V_3 |= V_3 ;
F_3 ( & V_2 -> V_5 , V_4 ) ;
}
static void F_4 ( struct V_1 * V_2 , unsigned long V_3 )
{
unsigned long V_4 ;
F_2 ( & V_2 -> V_5 , V_4 ) ;
V_2 -> V_3 &= ~ V_3 ;
F_3 ( & V_2 -> V_5 , V_4 ) ;
}
static struct V_1 * F_5 ( void )
{
struct V_6 * V_7 = NULL ;
struct V_1 * V_2 = NULL ;
unsigned long V_4 ;
F_2 ( & V_8 , V_4 ) ;
if ( ! F_6 ( & V_9 ) ) {
V_7 = F_7 ( & V_9 , struct V_6 , V_10 ) ;
F_8 ( & V_7 -> V_10 ) ;
}
F_3 ( & V_8 , V_4 ) ;
if ( V_7 ) {
V_2 = V_7 -> V_2 ;
F_9 ( V_7 ) ;
}
return V_2 ;
}
static void F_10 ( struct V_11 * V_12 )
{
struct V_1 * V_2 ;
if ( V_13 == NULL ) {
V_13 = V_14 ;
}
while ( ( V_2 = F_5 () ) != NULL ) {
F_11 ( L_1 , V_2 -> V_3 ) ;
if ( V_2 -> V_3 & V_15 ) {
V_2 -> V_16 . V_17 ( V_2 ) ;
F_4 ( V_2 , V_15 ) ;
}
if ( V_2 -> V_3 & V_18 ) {
V_2 -> V_16 . V_19 ( V_2 ) ;
F_4 ( V_2 , V_18 ) ;
}
if ( V_2 -> V_3 & V_20 ) {
V_2 -> V_16 . V_21 ( V_2 ) ;
F_4 ( V_2 , V_20 ) ;
}
if ( V_2 -> V_3 & V_22 )
F_11 ( L_2 , V_2 ) ;
F_12 ( & V_2 -> V_23 ) ;
}
}
int F_13 ( struct V_1 * V_2 )
{
F_14 ( & V_2 -> V_23 ) ;
V_2 -> V_3 = 0 ;
return 0 ;
}
void F_15 ( struct V_1 * V_2 )
{
unsigned long V_24 = V_2 -> V_3 & ~ V_22 ;
if ( ! ( V_2 -> V_3 & V_22 ) )
F_11 ( L_3 ) ;
if ( V_24 )
F_11 ( L_4 , V_24 ) ;
F_16 ( V_2 -> V_23 , ! ( V_2 -> V_3 & ~ V_22 ) ) ;
F_11 ( L_5 ) ;
}
int F_17 ( void )
{
V_25 = F_18 ( V_26 ) ;
if ( V_25 == NULL ) {
F_19 ( L_6 ) ;
return - V_27 ;
}
return 0 ;
}
void F_20 ( void )
{
F_21 ( V_25 ) ;
F_22 ( V_25 ) ;
V_25 = NULL ;
}
void F_23 ( struct V_1 * V_2 , unsigned long V_3 )
{
struct V_6 * V_7 ;
unsigned long V_4 ;
if ( V_2 -> V_3 & V_22 )
return;
F_1 ( V_2 , V_3 ) ;
F_2 ( & V_8 , V_4 ) ;
F_24 (ue, &event_list, node) {
if ( V_7 -> V_2 == V_2 )
goto V_28;
}
V_7 = F_25 ( sizeof( struct V_6 ) , V_29 ) ;
if ( V_7 == NULL )
goto V_28;
V_7 -> V_2 = V_2 ;
F_26 ( & V_7 -> V_10 , & V_9 ) ;
F_27 ( V_25 , & V_30 ) ;
V_28:
F_3 ( & V_8 , V_4 ) ;
}
int F_28 ( struct V_1 * V_2 )
{
int V_31 = 0 ;
unsigned long V_4 ;
F_2 ( & V_2 -> V_5 , V_4 ) ;
if ( V_2 -> V_3 != 0 )
V_31 = 1 ;
F_3 ( & V_2 -> V_5 , V_4 ) ;
return V_31 ;
}
int F_29 ( struct V_32 * V_33 )
{
if ( V_33 == V_13 )
return 1 ;
return 0 ;
}
