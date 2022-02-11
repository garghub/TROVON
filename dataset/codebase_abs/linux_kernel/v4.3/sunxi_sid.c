static T_1 F_1 ( const struct V_1 * V_2 ,
const unsigned int V_3 )
{
T_2 V_4 ;
V_4 = F_2 ( V_2 -> V_5 + F_3 ( V_3 , 4 ) ) ;
V_4 >>= ( V_3 % 4 ) * 8 ;
return V_4 ;
}
static int F_4 ( void * V_6 ,
const void * V_7 , T_3 V_8 ,
void * V_9 , T_3 V_10 )
{
struct V_1 * V_2 = V_6 ;
unsigned int V_3 = * ( T_2 * ) V_7 ;
T_1 * V_11 = V_9 ;
while ( V_10 ) {
* V_11 ++ = F_1 ( V_2 , V_3 ) ;
V_10 -- ;
V_3 ++ ;
}
return 0 ;
}
static int F_5 ( void * V_6 , const void * V_12 , T_3 V_13 )
{
return 0 ;
}
static bool F_6 ( struct V_14 * V_15 , unsigned int V_7 )
{
return false ;
}
static int F_7 ( struct V_16 * V_17 )
{
struct V_14 * V_15 = & V_17 -> V_15 ;
struct V_18 * V_19 ;
struct V_20 * V_21 ;
struct V_22 * V_22 ;
struct V_1 * V_2 ;
int V_23 , V_24 , V_25 ;
char * V_26 ;
V_2 = F_8 ( V_15 , sizeof( * V_2 ) , V_27 ) ;
if ( ! V_2 )
return - V_28 ;
V_19 = F_9 ( V_17 , V_29 , 0 ) ;
V_2 -> V_5 = F_10 ( V_15 , V_19 ) ;
if ( F_11 ( V_2 -> V_5 ) )
return F_12 ( V_2 -> V_5 ) ;
V_25 = F_13 ( V_19 ) - 1 ;
V_30 . V_31 = V_25 ;
V_22 = F_14 ( V_15 , & V_32 , V_2 ,
& V_30 ) ;
if ( F_11 ( V_22 ) ) {
F_15 ( V_15 , L_1 ) ;
return F_12 ( V_22 ) ;
}
V_33 . V_15 = V_15 ;
V_21 = F_16 ( & V_33 ) ;
if ( F_11 ( V_21 ) )
return F_12 ( V_21 ) ;
V_26 = F_17 ( sizeof( T_1 ) * V_25 , V_27 ) ;
if ( ! V_26 ) {
V_23 = - V_34 ;
goto V_35;
}
for ( V_24 = 0 ; V_24 < V_25 ; V_24 ++ )
V_26 [ V_24 ] = F_1 ( V_2 , V_24 ) ;
F_18 ( V_26 , V_25 ) ;
F_19 ( V_26 ) ;
F_20 ( V_17 , V_21 ) ;
return 0 ;
V_35:
F_21 ( V_21 ) ;
return V_23 ;
}
static int F_22 ( struct V_16 * V_17 )
{
struct V_20 * V_21 = F_23 ( V_17 ) ;
return F_21 ( V_21 ) ;
}
