static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( V_4 -> V_5 ) ;
F_3 ( V_4 ) ;
}
int F_4 ( unsigned long V_6 , struct V_3 * V_4 ,
struct V_7 * V_8 )
{
struct V_3 * V_2 = V_4 ;
if ( ! V_2 ) {
V_2 = F_5 ( sizeof( struct V_3 ) , V_9 ) ;
if ( ! V_2 )
return - V_10 ;
}
V_2 -> V_8 = V_8 ;
F_6 ( V_2 , V_6 , & V_2 -> V_11 ) ;
if ( ! V_2 -> V_5 ) {
V_2 -> V_5 = F_7 ( sizeof( struct V_5 ) , V_9 ) ;
if ( ! V_2 -> V_5 ) {
F_3 ( V_2 ) ;
return - V_10 ;
}
V_2 -> V_5 -> V_12 = V_2 -> V_12 ;
V_2 -> V_5 -> V_13 = V_6 ;
V_2 -> V_5 -> V_14 = V_2 -> V_5 -> V_13 + 0x01000000 ;
}
V_2 -> V_2 . V_15 = & V_16 ;
V_2 -> V_2 . V_8 = & V_17 ;
V_2 -> V_2 . V_18 = F_1 ;
V_2 -> V_19 . V_19 = V_2 -> V_11 . V_20 ;
sprintf ( V_2 -> V_12 , L_1 , V_2 -> V_19 . V_19 ) ;
F_8 ( & V_2 -> V_2 , L_2 , V_21 ) ;
V_21 ++ ;
return F_9 ( & V_2 -> V_2 ) ;
}
int F_10 ( struct V_7 * V_8 ,
struct V_3 * * V_22 ,
int V_23 )
{
int V_24 , V_25 = 0 ;
for ( V_24 = 0 ; V_24 < V_23 ; V_24 ++ ) {
struct V_3 * V_2 = V_22 [ V_24 ] ;
V_25 |= F_4 ( V_2 -> V_5 [ 0 ] . V_13 , V_2 , V_8 ) ;
}
return V_25 ;
}
static int T_1 F_11 ( void )
{
struct V_7 * V_8 ;
int V_25 ;
V_25 = F_9 ( & V_16 ) ;
if ( F_12 ( V_25 ) )
return V_25 ;
for ( V_8 = V_26 ; V_8 -> V_27 ; V_8 ++ )
V_25 |= F_13 ( V_8 ) ;
return V_25 ;
}
static const struct V_28 *
F_14 ( const struct V_28 * V_29 ,
struct V_3 * V_2 )
{
while ( V_29 -> V_19 ) {
if ( V_29 -> V_19 == V_2 -> V_19 . V_19 )
return V_29 ;
V_29 ++ ;
}
return NULL ;
}
static int F_15 ( struct V_1 * V_2 )
{
struct V_3 * V_30 = F_2 ( V_2 ) ;
struct V_31 * V_32 = F_16 ( V_2 -> V_33 ) ;
if ( V_32 && V_32 -> V_34 ) {
const struct V_28 * V_19 ;
V_19 = F_14 ( V_32 -> V_35 , V_30 ) ;
if ( V_19 )
return V_32 -> V_34 ( V_30 , V_19 ) ;
}
return - V_36 ;
}
static int F_17 ( struct V_1 * V_2 )
{
struct V_3 * V_30 = F_2 ( V_2 ) ;
struct V_31 * V_32 = F_16 ( V_2 -> V_33 ) ;
if ( V_32 && V_32 -> remove ) {
V_32 -> remove ( V_30 ) ;
return 0 ;
}
return - V_36 ;
}
int F_18 ( struct V_31 * V_37 )
{
V_37 -> V_37 . V_12 = V_37 -> V_12 ;
V_37 -> V_37 . V_8 = & V_17 ;
return F_19 ( & V_37 -> V_37 ) ;
}
void F_20 ( struct V_31 * V_37 )
{
F_21 ( & V_37 -> V_37 ) ;
}
static int F_22 ( struct V_1 * V_2 , struct V_38 * V_37 )
{
struct V_3 * V_30 = F_2 ( V_2 ) ;
struct V_31 * V_32 = F_16 ( V_37 ) ;
const struct V_28 * V_29 = V_32 -> V_35 ;
if ( ! V_29 )
return - V_39 ;
if ( F_14 ( V_29 , V_30 ) )
return 1 ;
return - V_36 ;
}
static int T_1 F_23 ( void )
{
return F_24 ( & V_17 ) ;
}
static void T_2 F_25 ( void )
{
F_26 ( & V_16 ) ;
F_27 ( & V_17 ) ;
}
