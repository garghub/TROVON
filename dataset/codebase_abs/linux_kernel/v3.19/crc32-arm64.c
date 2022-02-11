static T_1 F_1 ( T_1 V_1 , const T_2 * V_2 , unsigned int V_3 )
{
T_3 V_4 = V_3 ;
while ( ( V_4 -= sizeof( V_5 ) ) >= 0 ) {
F_2 ( V_1 , F_3 ( V_2 ) ) ;
V_2 += sizeof( V_5 ) ;
}
if ( V_4 & sizeof( T_1 ) ) {
F_4 ( V_1 , F_5 ( V_2 ) ) ;
V_2 += sizeof( T_1 ) ;
}
if ( V_4 & sizeof( V_6 ) ) {
F_6 ( V_1 , F_7 ( V_2 ) ) ;
V_2 += sizeof( V_6 ) ;
}
if ( V_4 & sizeof( T_2 ) )
F_8 ( V_1 , * V_2 ) ;
return V_1 ;
}
static T_1 F_9 ( T_1 V_1 , const T_2 * V_2 , unsigned int V_3 )
{
T_3 V_4 = V_3 ;
while ( ( V_4 -= sizeof( V_5 ) ) >= 0 ) {
F_10 ( V_1 , F_3 ( V_2 ) ) ;
V_2 += sizeof( V_5 ) ;
}
if ( V_4 & sizeof( T_1 ) ) {
F_11 ( V_1 , F_5 ( V_2 ) ) ;
V_2 += sizeof( T_1 ) ;
}
if ( V_4 & sizeof( V_6 ) ) {
F_12 ( V_1 , F_7 ( V_2 ) ) ;
V_2 += sizeof( V_6 ) ;
}
if ( V_4 & sizeof( T_2 ) )
F_13 ( V_1 , * V_2 ) ;
return V_1 ;
}
static int F_14 ( struct V_7 * V_8 )
{
struct V_9 * V_10 = F_15 ( V_8 -> V_11 ) ;
struct V_12 * V_13 = F_16 ( V_8 ) ;
V_13 -> V_1 = V_10 -> V_14 ;
return 0 ;
}
static int F_17 ( struct V_15 * V_11 , const T_2 * V_14 ,
unsigned int V_16 )
{
struct V_9 * V_10 = F_15 ( V_11 ) ;
if ( V_16 != sizeof( V_10 -> V_14 ) ) {
F_18 ( V_11 , V_17 ) ;
return - V_18 ;
}
V_10 -> V_14 = F_5 ( V_14 ) ;
return 0 ;
}
static int F_19 ( struct V_7 * V_8 , const T_2 * V_19 ,
unsigned int V_4 )
{
struct V_12 * V_13 = F_16 ( V_8 ) ;
V_13 -> V_1 = F_1 ( V_13 -> V_1 , V_19 , V_4 ) ;
return 0 ;
}
static int F_20 ( struct V_7 * V_8 , const T_2 * V_19 ,
unsigned int V_4 )
{
struct V_12 * V_13 = F_16 ( V_8 ) ;
V_13 -> V_1 = F_9 ( V_13 -> V_1 , V_19 , V_4 ) ;
return 0 ;
}
static int F_21 ( struct V_7 * V_8 , T_2 * V_20 )
{
struct V_12 * V_13 = F_16 ( V_8 ) ;
F_22 ( ~ V_13 -> V_1 , V_20 ) ;
return 0 ;
}
static int F_23 ( T_1 V_1 , const T_2 * V_19 , unsigned int V_3 , T_2 * V_20 )
{
F_22 ( ~ F_1 ( V_1 , V_19 , V_3 ) , V_20 ) ;
return 0 ;
}
static int F_24 ( T_1 V_1 , const T_2 * V_19 , unsigned int V_3 , T_2 * V_20 )
{
F_22 ( ~ F_9 ( V_1 , V_19 , V_3 ) , V_20 ) ;
return 0 ;
}
static int F_25 ( struct V_7 * V_8 , const T_2 * V_19 ,
unsigned int V_3 , T_2 * V_20 )
{
struct V_12 * V_13 = F_16 ( V_8 ) ;
return F_23 ( V_13 -> V_1 , V_19 , V_3 , V_20 ) ;
}
static int F_26 ( struct V_7 * V_8 , const T_2 * V_19 ,
unsigned int V_3 , T_2 * V_20 )
{
struct V_12 * V_13 = F_16 ( V_8 ) ;
return F_24 ( V_13 -> V_1 , V_19 , V_3 , V_20 ) ;
}
static int F_27 ( struct V_7 * V_8 , const T_2 * V_19 ,
unsigned int V_4 , T_2 * V_20 )
{
struct V_9 * V_10 = F_15 ( V_8 -> V_11 ) ;
return F_23 ( V_10 -> V_14 , V_19 , V_4 , V_20 ) ;
}
static int F_28 ( struct V_7 * V_8 , const T_2 * V_19 ,
unsigned int V_4 , T_2 * V_20 )
{
struct V_9 * V_10 = F_15 ( V_8 -> V_11 ) ;
return F_24 ( V_10 -> V_14 , V_19 , V_4 , V_20 ) ;
}
static int F_29 ( struct V_21 * V_11 )
{
struct V_9 * V_10 = F_30 ( V_11 ) ;
V_10 -> V_14 = ~ 0 ;
return 0 ;
}
static int T_4 F_31 ( void )
{
int V_22 ;
V_22 = F_32 ( & V_23 ) ;
if ( V_22 )
return V_22 ;
V_22 = F_32 ( & V_24 ) ;
if ( V_22 ) {
F_33 ( & V_23 ) ;
return V_22 ;
}
return 0 ;
}
static void T_5 F_34 ( void )
{
F_33 ( & V_23 ) ;
F_33 ( & V_24 ) ;
}
