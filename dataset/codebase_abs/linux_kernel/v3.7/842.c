static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_5 ;
V_5 = F_3 ( int , F_4 () , V_6 ) ;
V_4 -> V_7 = F_5 ( V_5 , V_8 ) ;
if ( ! V_4 -> V_7 )
return - V_9 ;
return 0 ;
}
static void F_6 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_7 ( V_4 -> V_7 ) ;
}
static void F_8 ( unsigned long V_10 )
{
V_11 = 0 ;
}
static int F_9 ( struct V_1 * V_2 , const T_1 * V_12 ,
unsigned int V_13 , T_1 * V_14 , unsigned int * V_15 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_16 * V_17 ;
unsigned int V_18 = * V_15 ;
T_2 V_19 ;
int V_20 ;
* V_15 = 0 ;
V_17 = (struct V_16 * ) V_14 ;
V_17 -> V_21 = V_22 ;
V_14 += sizeof( struct V_16 ) ;
V_18 -= sizeof( struct V_16 ) ;
V_19 = V_18 ;
if ( F_10 ( ! V_11 ) ) {
V_20 = F_11 ( V_12 , V_13 , V_14 , & V_18 , V_4 -> V_7 ) ;
if ( F_10 ( ! V_20 ) ) {
V_17 -> type = V_23 ;
* V_15 = V_18 + sizeof( struct V_16 ) ;
return 0 ;
}
V_11 = 1 ;
F_12 ( & V_24 , V_25 + F_13 ( 1000 ) ) ;
}
V_20 = F_14 ( V_12 , V_13 , V_14 , & V_19 , V_4 -> V_7 ) ;
if ( V_20 != V_26 )
return - V_27 ;
V_17 -> type = V_28 ;
* V_15 = V_19 + sizeof( struct V_16 ) ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 , const T_1 * V_12 ,
unsigned int V_13 , T_1 * V_14 , unsigned int * V_15 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_16 * V_17 ;
unsigned int V_18 = * V_15 ;
T_2 V_19 ;
int V_20 ;
* V_15 = 0 ;
V_17 = (struct V_16 * ) V_12 ;
if ( F_16 ( V_17 -> V_21 != V_22 ) )
return - V_27 ;
V_12 += sizeof( struct V_16 ) ;
V_13 -= sizeof( struct V_16 ) ;
if ( F_10 ( V_17 -> type == V_23 ) ) {
V_20 = F_17 ( V_12 , V_13 , V_14 , & V_18 ,
V_4 -> V_7 ) ;
if ( V_20 )
return - V_27 ;
* V_15 = V_18 ;
} else if ( V_17 -> type == V_28 ) {
V_19 = V_18 ;
V_20 = F_18 ( V_12 , V_13 , V_14 , & V_19 ) ;
if ( V_20 != V_26 )
return - V_27 ;
* V_15 = V_19 ;
} else
return - V_27 ;
return 0 ;
}
static int T_3 F_19 ( void )
{
F_20 ( & V_24 ) ;
return F_21 ( & V_29 ) ;
}
static void T_4 F_22 ( void )
{
F_23 ( & V_29 ) ;
}
