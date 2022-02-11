static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
const struct V_6 * V_7 ;
int V_8 ;
if ( ! V_5 ) {
V_2 -> V_9 &= ~ V_10 ;
V_2 -> V_9 |= V_11 ;
return 0 ;
}
F_2 ( & V_2 -> V_12 , L_1 , V_5 ) ;
V_8 = F_3 ( & V_7 , V_5 , & V_2 -> V_12 ) ;
if ( V_8 < 0 ) {
F_4 ( & V_2 -> V_12 , L_2 ,
V_5 , V_8 ) ;
goto V_13;
}
V_2 -> V_9 &= ~ V_11 ;
V_2 -> V_9 |= V_10 ;
V_13:
F_5 ( V_7 ) ;
return V_8 ;
}
static int F_6 ( struct V_1 * V_2 , T_1 V_14 ,
char * V_15 , int V_9 )
{
return - V_16 ;
}
static void F_7 ( struct V_17 * V_18 )
{
struct V_19 * V_20 = V_21 ;
int V_8 ;
F_8 ( V_20 -> V_2 , V_22 ) ;
F_9 ( & V_20 -> V_12 ) ;
V_21 = NULL ;
V_20 = F_10 () ;
if ( F_11 ( V_20 ) ) {
F_12 ( L_3 , V_23 ) ;
return;
}
V_8 = F_13 ( V_20 -> V_2 , V_22 ) ;
if ( V_8 < 0 ) {
F_4 ( & V_20 -> V_12 , L_4 ) ;
F_9 ( & V_20 -> V_12 ) ;
return;
}
V_21 = V_20 ;
}
static int F_14 ( struct V_1 * V_2 , T_2 V_24 ,
void * V_25 , T_3 V_26 )
{
if ( V_24 > V_27 )
return - V_28 ;
if ( V_24 + V_26 > V_27 )
V_26 = V_27 - V_24 ;
memcpy ( V_25 , V_2 -> V_29 + V_24 , V_26 ) ;
return V_26 ;
}
static int F_15 ( struct V_1 * V_2 , T_2 V_24 ,
const void * V_25 , T_3 V_26 )
{
if ( V_24 > V_27 )
return - V_28 ;
if ( V_24 + V_26 > V_27 )
V_26 = V_27 - V_24 ;
F_2 ( & V_2 -> V_12 , L_5 ,
( int ) V_24 , V_26 ) ;
memcpy ( V_2 -> V_29 + V_24 , V_25 , V_26 ) ;
F_16 ( & V_30 , V_31 * 2 ) ;
return V_26 ;
}
static int F_17 ( struct V_1 * V_2 , int V_32 , void * V_33 , int V_34 )
{
if ( ! ( V_2 -> V_9 & V_11 ) )
return - V_16 ;
return F_14 ( V_2 , V_32 , V_33 , V_34 ) ;
}
static int F_18 ( struct V_1 * V_2 , int V_32 ,
const void * V_33 , int V_34 )
{
if ( ! ( V_2 -> V_9 & V_11 ) )
return - V_16 ;
return F_15 ( V_2 , V_32 , V_33 , V_34 ) ;
}
static T_2 F_19 ( struct V_1 * V_2 , int V_24 )
{
return 0 ;
}
static void F_20 ( struct V_1 * V_2 , T_2 V_35 , int V_24 )
{
return;
}
static int F_21 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_36 ;
if ( ! V_4 -> V_37 )
return 0 ;
for ( V_36 = 0 ; V_36 < V_4 -> V_37 ; V_36 ++ )
if ( V_4 -> V_38 [ V_36 ] == V_2 -> V_39 )
return V_36 ;
return - V_40 ;
}
static void F_22 ( struct V_41 * V_12 )
{
struct V_19 * V_20 = F_23 ( V_12 , struct V_19 , V_12 ) ;
F_24 ( V_20 ) ;
}
static struct V_19 * F_10 ( void )
{
struct V_19 * V_20 ;
struct V_1 * V_2 ;
int V_36 , V_8 ;
V_20 = F_25 ( sizeof( * V_20 ) , V_42 ) ;
if ( ! V_20 )
return F_26 ( - V_43 ) ;
F_27 ( & V_20 -> V_12 , L_6 ) ;
V_20 -> V_12 . V_44 = F_22 ;
V_8 = F_28 ( & V_20 -> V_12 ) ;
if ( V_8 < 0 ) {
F_29 ( & V_20 -> V_12 ) ;
return F_26 ( V_8 ) ;
}
for ( V_36 = 0 ; V_36 < V_22 ; V_36 ++ ) {
V_2 = F_30 ( & V_45 , sizeof( V_45 ) ,
V_42 ) ;
V_2 -> V_46 = & V_20 -> V_12 ;
V_2 -> V_47 = V_20 ;
V_2 -> V_48 = V_22 ;
V_2 -> V_29 = V_49 [ V_36 ] ;
V_2 -> V_50 = 0x50 + 2 * V_36 ;
V_2 -> V_51 = V_36 ;
V_20 -> V_2 [ V_36 ] = V_2 ;
V_45 . V_39 ++ ;
}
return V_20 ;
}
static int F_31 ( void )
{
struct V_19 * V_20 ;
const struct V_6 * V_7 ;
int V_36 , V_34 , V_8 = 0 ;
for ( V_36 = 1 ; V_36 < V_52 ; V_36 ++ )
memcpy ( V_49 [ V_36 ] , V_49 [ 0 ] , sizeof( V_49 [ 0 ] ) ) ;
if ( V_53 > V_22 )
V_22 = V_53 ;
V_20 = F_10 () ;
if ( F_11 ( V_20 ) )
return F_32 ( V_20 ) ;
for ( V_36 = 0 ; V_36 < V_53 ; V_36 ++ ) {
if ( ! strlen ( V_54 [ V_36 ] ) )
continue;
V_8 = F_3 ( & V_7 , V_54 [ V_36 ] , & V_20 -> V_12 ) ;
if ( V_8 < 0 ) {
F_33 ( & V_20 -> V_12 , L_7
L_8 , V_36 , V_54 [ V_36 ] , - V_8 ) ;
} else {
V_34 = F_34 ( T_3 , V_7 -> V_26 , ( T_3 ) V_27 ) ;
memcpy ( V_49 [ V_36 ] , V_7 -> V_33 , V_34 ) ;
F_5 ( V_7 ) ;
F_2 ( & V_20 -> V_12 , L_9 , V_36 ,
V_54 [ V_36 ] ) ;
}
}
V_8 = F_13 ( V_20 -> V_2 , V_22 ) ;
if ( V_8 ) {
F_9 ( & V_20 -> V_12 ) ;
return V_8 ;
}
V_21 = V_20 ;
return V_8 ;
}
static void F_35 ( void )
{
if ( V_21 ) {
F_8 ( V_21 -> V_2 , V_22 ) ;
F_9 ( & V_21 -> V_12 ) ;
}
F_36 ( & V_30 ) ;
}
