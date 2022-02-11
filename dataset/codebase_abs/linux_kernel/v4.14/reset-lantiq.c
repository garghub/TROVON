static struct V_1 * F_1 (
struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static int F_3 ( struct V_2 * V_3 ,
unsigned long V_4 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
unsigned int V_6 = ( V_4 >> 8 ) & 0x1f ;
T_1 V_7 ;
int V_8 ;
V_8 = F_4 ( V_5 -> V_9 , V_5 -> V_10 , & V_7 ) ;
if ( V_8 )
return V_8 ;
return ! ! ( V_7 & F_5 ( V_6 ) ) ;
}
static int F_6 ( struct V_2 * V_3 ,
unsigned long V_4 , bool assert )
{
int V_8 ;
int V_11 = V_12 ;
do {
V_8 = F_3 ( V_3 , V_4 ) ;
if ( V_8 < 0 )
return V_8 ;
if ( V_8 == assert )
return 0 ;
F_7 ( 20 , 40 ) ;
} while ( -- V_11 );
return - V_13 ;
}
static int F_8 ( struct V_2 * V_3 ,
unsigned long V_4 , bool assert )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
unsigned int V_14 = V_4 & 0x1f ;
T_1 V_7 = assert ? F_5 ( V_14 ) : 0 ;
int V_8 ;
V_8 = F_9 ( V_5 -> V_9 , V_5 -> V_15 , F_5 ( V_14 ) ,
V_7 ) ;
if ( V_8 ) {
F_10 ( V_5 -> V_16 , L_1 , V_14 ) ;
return V_8 ;
}
V_8 = F_6 ( V_3 , V_4 , assert ) ;
if ( V_8 )
F_10 ( V_5 -> V_16 , L_2 ,
assert ? L_3 : L_4 , V_14 ) ;
return V_8 ;
}
static int F_11 ( struct V_2 * V_3 ,
unsigned long V_4 )
{
return F_8 ( V_3 , V_4 , true ) ;
}
static int F_12 ( struct V_2 * V_3 ,
unsigned long V_4 )
{
return F_8 ( V_3 , V_4 , false ) ;
}
static int F_13 ( struct V_2 * V_3 ,
unsigned long V_4 )
{
int V_8 ;
V_8 = F_11 ( V_3 , V_4 ) ;
if ( V_8 )
return V_8 ;
return F_12 ( V_3 , V_4 ) ;
}
static int F_14 ( struct V_17 * V_18 ,
struct V_1 * V_5 )
{
struct V_19 * V_16 = & V_18 -> V_16 ;
const T_2 * V_20 ;
V_5 -> V_9 = F_15 ( V_16 -> V_21 -> V_22 ) ;
if ( F_16 ( V_5 -> V_9 ) ) {
F_10 ( & V_18 -> V_16 , L_5 ) ;
return F_17 ( V_5 -> V_9 ) ;
}
V_20 = F_18 ( V_16 -> V_21 , 0 , NULL , NULL ) ;
if ( ! V_20 ) {
F_10 ( & V_18 -> V_16 , L_6 ) ;
return - V_23 ;
}
V_5 -> V_15 = F_19 ( * V_20 ) ;
V_20 = F_18 ( V_16 -> V_21 , 1 , NULL , NULL ) ;
if ( ! V_20 ) {
F_10 ( & V_18 -> V_16 , L_7 ) ;
return - V_23 ;
}
V_5 -> V_10 = F_19 ( * V_20 ) ;
return 0 ;
}
static int F_20 ( struct V_2 * V_3 ,
const struct V_24 * V_25 )
{
unsigned int V_6 , V_14 ;
V_14 = V_25 -> args [ 0 ] ;
V_6 = V_25 -> args [ 1 ] ;
if ( V_14 >= V_3 -> V_26 || V_6 >= V_3 -> V_26 )
return - V_27 ;
return ( V_6 << 8 ) | V_14 ;
}
static int F_21 ( struct V_17 * V_18 )
{
struct V_1 * V_5 ;
int V_28 ;
V_5 = F_22 ( & V_18 -> V_16 , sizeof( * V_5 ) , V_29 ) ;
if ( ! V_5 )
return - V_30 ;
V_5 -> V_16 = & V_18 -> V_16 ;
F_23 ( V_18 , V_5 ) ;
V_28 = F_14 ( V_18 , V_5 ) ;
if ( V_28 )
return V_28 ;
V_5 -> V_3 . V_31 = & V_32 ;
V_5 -> V_3 . V_33 = V_34 ;
V_5 -> V_3 . V_21 = V_18 -> V_16 . V_21 ;
V_5 -> V_3 . V_26 = 32 ;
V_5 -> V_3 . V_35 = F_20 ;
V_5 -> V_3 . V_36 = 2 ;
return F_24 ( & V_5 -> V_3 ) ;
}
