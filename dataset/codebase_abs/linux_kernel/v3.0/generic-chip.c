static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return & F_2 ( V_3 -> V_4 , struct V_5 , V_4 ) -> V_6 ;
}
void F_3 ( struct V_2 * V_3 )
{
}
void F_4 ( struct V_2 * V_3 )
{
struct V_7 * V_8 = F_5 ( V_3 ) ;
T_1 V_9 = 1 << ( V_3 -> V_10 - V_8 -> V_11 ) ;
F_6 ( V_8 ) ;
F_7 ( V_9 , V_8 -> V_12 + F_1 ( V_3 ) -> V_13 ) ;
V_8 -> V_14 &= ~ V_9 ;
F_8 ( V_8 ) ;
}
void F_9 ( struct V_2 * V_3 )
{
struct V_7 * V_8 = F_5 ( V_3 ) ;
T_1 V_9 = 1 << ( V_3 -> V_10 - V_8 -> V_11 ) ;
F_6 ( V_8 ) ;
V_8 -> V_14 |= V_9 ;
F_7 ( V_8 -> V_14 , V_8 -> V_12 + F_1 ( V_3 ) -> V_9 ) ;
F_8 ( V_8 ) ;
}
void F_10 ( struct V_2 * V_3 )
{
struct V_7 * V_8 = F_5 ( V_3 ) ;
T_1 V_9 = 1 << ( V_3 -> V_10 - V_8 -> V_11 ) ;
F_6 ( V_8 ) ;
V_8 -> V_14 &= ~ V_9 ;
F_7 ( V_8 -> V_14 , V_8 -> V_12 + F_1 ( V_3 ) -> V_9 ) ;
F_8 ( V_8 ) ;
}
void F_11 ( struct V_2 * V_3 )
{
struct V_7 * V_8 = F_5 ( V_3 ) ;
T_1 V_9 = 1 << ( V_3 -> V_10 - V_8 -> V_11 ) ;
F_6 ( V_8 ) ;
F_7 ( V_9 , V_8 -> V_12 + F_1 ( V_3 ) -> V_15 ) ;
V_8 -> V_14 |= V_9 ;
F_8 ( V_8 ) ;
}
void F_12 ( struct V_2 * V_3 )
{
struct V_7 * V_8 = F_5 ( V_3 ) ;
T_1 V_9 = 1 << ( V_3 -> V_10 - V_8 -> V_11 ) ;
F_6 ( V_8 ) ;
F_7 ( V_9 , V_8 -> V_12 + F_1 ( V_3 ) -> V_16 ) ;
F_8 ( V_8 ) ;
}
void F_13 ( struct V_2 * V_3 )
{
struct V_7 * V_8 = F_5 ( V_3 ) ;
T_1 V_9 = ~ ( 1 << ( V_3 -> V_10 - V_8 -> V_11 ) ) ;
F_6 ( V_8 ) ;
F_7 ( V_9 , V_8 -> V_12 + F_1 ( V_3 ) -> V_16 ) ;
F_8 ( V_8 ) ;
}
void F_14 ( struct V_2 * V_3 )
{
struct V_7 * V_8 = F_5 ( V_3 ) ;
T_1 V_9 = 1 << ( V_3 -> V_10 - V_8 -> V_11 ) ;
F_6 ( V_8 ) ;
F_7 ( V_9 , V_8 -> V_12 + F_1 ( V_3 ) -> V_9 ) ;
F_7 ( V_9 , V_8 -> V_12 + F_1 ( V_3 ) -> V_16 ) ;
F_8 ( V_8 ) ;
}
void F_15 ( struct V_2 * V_3 )
{
struct V_7 * V_8 = F_5 ( V_3 ) ;
T_1 V_9 = 1 << ( V_3 -> V_10 - V_8 -> V_11 ) ;
F_6 ( V_8 ) ;
F_7 ( V_9 , V_8 -> V_12 + F_1 ( V_3 ) -> V_17 ) ;
F_8 ( V_8 ) ;
}
int F_16 ( struct V_2 * V_3 , unsigned int V_18 )
{
struct V_7 * V_8 = F_5 ( V_3 ) ;
T_1 V_9 = 1 << ( V_3 -> V_10 - V_8 -> V_11 ) ;
if ( ! ( V_9 & V_8 -> V_19 ) )
return - V_20 ;
F_6 ( V_8 ) ;
if ( V_18 )
V_8 -> V_21 |= V_9 ;
else
V_8 -> V_21 &= ~ V_9 ;
F_8 ( V_8 ) ;
return 0 ;
}
struct V_7 *
F_17 ( const char * V_22 , int V_23 , unsigned int V_11 ,
void T_2 * V_12 , T_3 V_24 )
{
struct V_7 * V_8 ;
unsigned long V_25 = sizeof( * V_8 ) + V_23 * sizeof( struct V_5 ) ;
V_8 = F_18 ( V_25 , V_26 ) ;
if ( V_8 ) {
F_19 ( & V_8 -> V_27 ) ;
V_8 -> V_23 = V_23 ;
V_8 -> V_11 = V_11 ;
V_8 -> V_12 = V_12 ;
V_8 -> V_28 -> V_4 . V_22 = V_22 ;
V_8 -> V_28 -> V_24 = V_24 ;
}
return V_8 ;
}
void F_20 ( struct V_7 * V_8 , T_1 V_29 ,
enum V_30 V_31 , unsigned int V_32 ,
unsigned int V_33 )
{
struct V_5 * V_34 = V_8 -> V_28 ;
unsigned int V_35 ;
F_21 ( & V_36 ) ;
F_22 ( & V_8 -> V_37 , & V_38 ) ;
F_23 ( & V_36 ) ;
if ( V_31 & V_39 )
V_8 -> V_14 = F_24 ( V_8 -> V_12 + V_34 -> V_6 . V_9 ) ;
for ( V_35 = V_8 -> V_11 ; V_29 ; V_29 >>= 1 , V_35 ++ ) {
if ( ! V_29 & 0x01 )
continue;
if ( V_31 & V_40 )
F_25 ( V_35 , & V_41 ) ;
F_26 ( V_35 , & V_34 -> V_4 , V_34 -> V_24 ) ;
F_27 ( V_35 , V_8 ) ;
F_28 ( V_35 , V_32 , V_33 ) ;
}
V_8 -> V_42 = V_35 - V_8 -> V_11 ;
}
int F_29 ( struct V_2 * V_3 , unsigned int type )
{
struct V_7 * V_8 = F_5 ( V_3 ) ;
struct V_5 * V_34 = V_8 -> V_28 ;
unsigned int V_35 ;
for ( V_35 = 0 ; V_35 < V_8 -> V_23 ; V_35 ++ , V_34 ++ ) {
if ( V_34 -> type & type ) {
V_3 -> V_4 = & V_34 -> V_4 ;
F_30 ( V_3 ) -> V_43 = V_34 -> V_24 ;
return 0 ;
}
}
return - V_20 ;
}
void F_31 ( struct V_7 * V_8 , T_1 V_29 ,
unsigned int V_32 , unsigned int V_33 )
{
unsigned int V_35 = V_8 -> V_11 ;
F_21 ( & V_36 ) ;
F_32 ( & V_8 -> V_37 ) ;
F_23 ( & V_36 ) ;
for (; V_29 ; V_29 >>= 1 , V_35 ++ ) {
if ( ! V_29 & 0x01 )
continue;
F_33 ( V_35 , NULL ) ;
F_34 ( V_35 , & V_44 ) ;
F_27 ( V_35 , NULL ) ;
F_28 ( V_35 , V_32 , V_33 ) ;
}
}
static int F_35 ( void )
{
struct V_7 * V_8 ;
F_36 (gc, &gc_list, list) {
struct V_5 * V_34 = V_8 -> V_28 ;
if ( V_34 -> V_4 . V_45 )
V_34 -> V_4 . V_45 ( F_37 ( V_8 -> V_11 ) ) ;
}
return 0 ;
}
static void F_38 ( void )
{
struct V_7 * V_8 ;
F_36 (gc, &gc_list, list) {
struct V_5 * V_34 = V_8 -> V_28 ;
if ( V_34 -> V_4 . V_46 )
V_34 -> V_4 . V_46 ( F_37 ( V_8 -> V_11 ) ) ;
}
}
static void F_39 ( void )
{
struct V_7 * V_8 ;
F_36 (gc, &gc_list, list) {
struct V_5 * V_34 = V_8 -> V_28 ;
if ( V_34 -> V_4 . V_47 )
V_34 -> V_4 . V_47 ( F_37 ( V_8 -> V_11 ) ) ;
}
}
static int T_4 F_40 ( void )
{
F_41 ( & V_48 ) ;
return 0 ;
}
