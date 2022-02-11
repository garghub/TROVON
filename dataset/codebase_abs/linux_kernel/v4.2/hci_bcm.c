static int F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_6 * V_7 ;
struct V_8 V_9 ;
if ( V_3 > 3000000 ) {
struct V_10 clock ;
clock . type = V_11 ;
F_2 ( L_1 , V_5 -> V_12 , clock . type ) ;
V_7 = F_3 ( V_5 , 0xfc45 , 1 , & clock , V_13 ) ;
if ( F_4 ( V_7 ) ) {
int V_14 = F_5 ( V_7 ) ;
F_6 ( L_2 ,
V_5 -> V_12 , V_14 ) ;
return V_14 ;
}
F_7 ( V_7 ) ;
}
F_2 ( L_3 , V_5 -> V_12 , V_3 ) ;
V_9 . V_15 = F_8 ( 0 ) ;
V_9 . V_16 = F_9 ( V_3 ) ;
V_7 = F_3 ( V_5 , 0xfc18 , sizeof( V_9 ) , & V_9 ,
V_13 ) ;
if ( F_4 ( V_7 ) ) {
int V_14 = F_5 ( V_7 ) ;
F_6 ( L_4 ,
V_5 -> V_12 , V_14 ) ;
return V_14 ;
}
F_7 ( V_7 ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 )
{
struct V_17 * V_18 ;
F_2 ( L_5 , V_2 ) ;
V_18 = F_11 ( sizeof( * V_18 ) , V_19 ) ;
if ( ! V_18 )
return - V_20 ;
F_12 ( & V_18 -> V_21 ) ;
V_2 -> V_22 = V_18 ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = V_2 -> V_22 ;
F_2 ( L_5 , V_2 ) ;
F_14 ( & V_18 -> V_21 ) ;
F_7 ( V_18 -> V_23 ) ;
F_15 ( V_18 ) ;
V_2 -> V_22 = NULL ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = V_2 -> V_22 ;
F_2 ( L_5 , V_2 ) ;
F_14 ( & V_18 -> V_21 ) ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 )
{
char V_24 [ 64 ] ;
const struct V_25 * V_26 ;
unsigned int V_3 ;
int V_14 ;
F_2 ( L_5 , V_2 ) ;
V_2 -> V_5 -> V_27 = V_28 ;
V_14 = F_18 ( V_2 -> V_5 , V_24 , sizeof( V_24 ) ) ;
if ( V_14 )
return V_14 ;
V_14 = F_19 ( & V_26 , V_24 , & V_2 -> V_5 -> V_29 ) ;
if ( V_14 < 0 ) {
F_20 ( L_6 , V_2 -> V_5 -> V_12 , V_24 ) ;
return 0 ;
}
V_14 = F_21 ( V_2 -> V_5 , V_26 ) ;
if ( V_14 ) {
F_20 ( L_7 , V_2 -> V_5 -> V_12 , V_14 ) ;
goto V_30;
}
if ( V_2 -> V_31 )
V_3 = V_2 -> V_31 ;
else if ( V_2 -> V_32 -> V_31 )
V_3 = V_2 -> V_32 -> V_31 ;
else
V_3 = 0 ;
if ( V_3 )
F_22 ( V_2 , V_3 ) ;
if ( V_2 -> V_33 )
V_3 = V_2 -> V_33 ;
else if ( V_2 -> V_32 -> V_33 )
V_3 = V_2 -> V_32 -> V_33 ;
else
V_3 = 0 ;
if ( V_3 ) {
V_14 = F_1 ( V_2 , V_3 ) ;
if ( ! V_14 )
F_22 ( V_2 , V_3 ) ;
}
V_30:
F_23 ( V_26 ) ;
V_14 = F_24 ( V_2 -> V_5 ) ;
return V_14 ;
}
static int F_25 ( struct V_1 * V_2 , const void * V_34 , int V_35 )
{
struct V_17 * V_18 = V_2 -> V_22 ;
if ( ! F_26 ( V_36 , & V_2 -> V_37 ) )
return - V_38 ;
V_18 -> V_23 = F_27 ( V_2 -> V_5 , V_18 -> V_23 , V_34 , V_35 ,
V_39 , F_28 ( V_39 ) ) ;
if ( F_4 ( V_18 -> V_23 ) ) {
int V_14 = F_5 ( V_18 -> V_23 ) ;
F_6 ( L_8 , V_2 -> V_5 -> V_12 , V_14 ) ;
V_18 -> V_23 = NULL ;
return V_14 ;
}
return V_35 ;
}
static int F_29 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
struct V_17 * V_18 = V_2 -> V_22 ;
F_2 ( L_9 , V_2 , V_7 ) ;
memcpy ( F_30 ( V_7 , 1 ) , & F_31 ( V_7 ) -> V_40 , 1 ) ;
F_32 ( & V_18 -> V_21 , V_7 ) ;
return 0 ;
}
static struct V_6 * F_33 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = V_2 -> V_22 ;
return F_34 ( & V_18 -> V_21 ) ;
}
int T_1 F_35 ( void )
{
return F_36 ( & V_41 ) ;
}
int T_2 F_37 ( void )
{
return F_38 ( & V_41 ) ;
}
