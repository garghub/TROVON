int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
int V_4 ;
int V_5 ;
F_2 ( & V_2 -> V_6 ) ;
V_4 = F_3 ( V_2 -> V_7 , V_3 , & V_5 ) ;
F_4 ( & V_2 -> V_6 ) ;
return V_4 ? V_4 : V_5 ;
}
int F_5 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_8 )
{
int V_4 ;
F_2 ( & V_2 -> V_6 ) ;
V_4 = F_6 ( V_2 -> V_7 , V_3 , V_8 ) ;
F_4 ( & V_2 -> V_6 ) ;
return V_4 ;
}
static void F_7 ( void )
{
struct V_1 * V_2 = V_9 ;
int V_3 ;
F_2 ( & V_9 -> V_6 ) ;
F_3 ( V_2 -> V_7 , V_10 , & V_3 ) ;
F_6 ( V_2 -> V_7 , V_10 , V_3 | 2 ) ;
F_6 ( V_2 -> V_7 , V_11 , 0 ) ;
for (; ; )
F_8 () ;
F_4 ( & V_9 -> V_6 ) ;
}
static int F_9 ( void * V_12 , const void * V_3 , T_3 V_13 ,
void * V_14 , T_3 V_15 )
{
int V_4 ;
struct V_16 * V_17 = V_12 ;
struct V_18 * V_19 = F_10 ( V_17 ) ;
F_11 ( V_13 != 1 || V_15 != 2 ) ;
V_4 = F_12 ( V_19 , * ( T_1 const * ) V_3 ) ;
if ( V_4 < 0 )
return V_4 ;
* ( T_2 * ) V_14 = V_4 ;
return 0 ;
}
static int F_13 ( void * V_12 , const void * V_8 , T_3 V_20 )
{
T_1 V_3 ;
T_2 V_14 ;
struct V_16 * V_17 = V_12 ;
struct V_18 * V_19 = F_10 ( V_17 ) ;
F_11 ( V_20 != sizeof( V_3 ) + sizeof( V_14 ) ) ;
memcpy ( & V_3 , V_8 , sizeof( V_3 ) ) ;
memcpy ( & V_14 , V_8 + sizeof( V_3 ) , sizeof( V_14 ) ) ;
return F_14 ( V_19 , V_3 , V_14 ) ;
}
static int F_15 ( struct V_18 * V_19 , const struct V_21 * V_22 )
{
struct V_1 * V_2 ;
int V_4 ;
V_2 = F_16 ( & V_19 -> V_17 , sizeof( * V_2 ) , V_23 ) ;
if ( V_2 == NULL )
return - V_24 ;
F_17 ( V_19 , V_2 ) ;
V_2 -> V_17 = & V_19 -> V_17 ;
F_18 ( & V_2 -> V_6 ) ;
V_2 -> V_7 = F_19 ( & V_19 -> V_17 , & V_25 , & V_19 -> V_17 ,
& V_26 ) ;
if ( F_20 ( V_2 -> V_7 ) )
return F_21 ( V_2 -> V_7 ) ;
V_4 = F_1 ( V_2 , V_27 ) ;
if ( V_4 < 0 ) {
F_22 ( V_2 -> V_17 , L_1 , V_4 ) ;
return V_4 ;
}
F_23 ( V_2 -> V_17 , L_2 ,
( V_4 & V_28 ) ? L_3 : L_4 ,
( V_4 >> 4 ) & 0x7 , V_4 & 0xf ) ;
V_4 = F_5 ( V_2 , V_29 , 0xffff ) ;
if ( V_4 < 0 )
return V_4 ;
V_4 = F_24 ( V_2 -> V_7 , V_19 -> V_30 , V_31 , - 1 ,
& V_32 , & V_2 -> V_33 ) ;
if ( V_4 < 0 )
return V_4 ;
V_4 = F_25 ( V_2 -> V_17 , - 1 , V_34 , F_26 ( V_34 ) ,
NULL , F_27 ( V_2 -> V_33 ) ,
NULL ) ;
if ( V_4 < 0 ) {
F_28 ( V_19 -> V_30 , V_2 -> V_33 ) ;
return V_4 ;
}
if ( ! V_35 ) {
V_9 = V_2 ;
V_35 = F_7 ;
}
return 0 ;
}
static int F_29 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = F_30 ( V_19 ) ;
if ( V_9 == V_2 ) {
V_35 = NULL ;
V_9 = NULL ;
}
F_31 ( V_2 -> V_17 ) ;
F_28 ( V_19 -> V_30 , V_2 -> V_33 ) ;
return 0 ;
}
