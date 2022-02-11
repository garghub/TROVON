static int F_1 ( void * V_1 )
{
if ( F_2 ( V_1 ) != V_2 )
return - V_3 ;
return 0 ;
}
static void * F_3 ( void * V_1 , int V_4 )
{
int V_5 = F_4 ( V_1 ) ;
int V_6 ;
V_6 = F_5 ( V_1 ) - F_6 ( V_1 )
- F_7 ( V_1 ) ;
if ( ( V_5 + V_4 < V_5 ) || ( V_5 + V_4 > V_6 ) )
return NULL ;
F_8 ( V_1 , V_5 + V_4 ) ;
return F_9 ( V_1 , V_5 , V_4 ) ;
}
int F_10 ( void * V_7 , int V_8 )
{
void * V_1 = V_7 ;
if ( V_8 < sizeof( struct V_9 ) )
return - V_10 ;
memset ( V_7 , 0 , V_8 ) ;
F_11 ( V_1 , V_2 ) ;
F_12 ( V_1 , V_11 ) ;
F_13 ( V_1 , V_12 ) ;
F_14 ( V_1 , V_8 ) ;
F_15 ( V_1 , F_16 ( sizeof( struct V_9 ) ,
sizeof( struct V_13 ) ) ) ;
F_17 ( V_1 , F_18 ( V_1 ) ) ;
F_19 ( V_1 , V_8 ) ;
return 0 ;
}
int F_20 ( void * V_1 , T_1 V_14 , T_1 V_15 )
{
struct V_13 * V_16 ;
int V_5 ;
F_21 ( V_1 ) ;
if ( F_4 ( V_1 ) )
return - V_17 ;
V_5 = F_6 ( V_1 ) ;
if ( ( V_5 + sizeof( * V_16 ) ) > F_5 ( V_1 ) )
return - V_10 ;
V_16 = (struct V_13 * ) ( ( char * ) V_1 + V_5 ) ;
V_16 -> V_18 = F_22 ( V_14 ) ;
V_16 -> V_15 = F_22 ( V_15 ) ;
F_17 ( V_1 , V_5 + sizeof( * V_16 ) ) ;
return 0 ;
}
int F_23 ( void * V_1 )
{
return F_20 ( V_1 , 0 , 0 ) ;
}
int F_24 ( void * V_1 , const char * V_19 )
{
struct V_20 * V_21 ;
int V_22 = strlen ( V_19 ) + 1 ;
F_21 ( V_1 ) ;
V_21 = F_3 ( V_1 , sizeof( * V_21 ) + F_25 ( V_22 ) ) ;
if ( ! V_21 )
return - V_10 ;
V_21 -> V_23 = F_26 ( V_24 ) ;
memcpy ( V_21 -> V_19 , V_19 , V_22 ) ;
return 0 ;
}
int F_27 ( void * V_1 )
{
T_2 * V_25 ;
F_21 ( V_1 ) ;
V_25 = F_3 ( V_1 , V_26 ) ;
if ( ! V_25 )
return - V_10 ;
* V_25 = F_26 ( V_27 ) ;
return 0 ;
}
static int F_28 ( void * V_1 , const char * V_28 )
{
char * V_29 = ( char * ) V_1 + F_5 ( V_1 ) ;
const char * V_30 ;
int V_31 = F_7 ( V_1 ) ;
int V_4 = strlen ( V_28 ) + 1 ;
int V_32 , V_5 ;
V_30 = F_29 ( V_29 - V_31 , V_31 , V_28 ) ;
if ( V_30 )
return V_30 - V_29 ;
V_5 = - V_31 - V_4 ;
V_32 = F_6 ( V_1 ) + F_4 ( V_1 ) ;
if ( F_5 ( V_1 ) + V_5 < V_32 )
return 0 ;
memcpy ( V_29 + V_5 , V_28 , V_4 ) ;
F_30 ( V_1 , V_31 + V_4 ) ;
return V_5 ;
}
int F_31 ( void * V_1 , const char * V_19 , const void * V_33 , int V_4 )
{
struct F_31 * V_34 ;
int V_35 ;
F_21 ( V_1 ) ;
V_35 = F_28 ( V_1 , V_19 ) ;
if ( V_35 == 0 )
return - V_10 ;
V_34 = F_3 ( V_1 , sizeof( * V_34 ) + F_25 ( V_4 ) ) ;
if ( ! V_34 )
return - V_10 ;
V_34 -> V_23 = F_26 ( V_36 ) ;
V_34 -> V_35 = F_26 ( V_35 ) ;
V_34 -> V_4 = F_26 ( V_4 ) ;
memcpy ( V_34 -> V_37 , V_33 , V_4 ) ;
return 0 ;
}
int F_32 ( void * V_1 )
{
char * V_30 = ( char * ) V_1 ;
T_2 * V_38 ;
int V_39 , V_40 ;
T_2 V_23 ;
int V_5 , V_41 ;
F_21 ( V_1 ) ;
V_38 = F_3 ( V_1 , sizeof( * V_38 ) ) ;
if ( ! V_38 )
return - V_10 ;
* V_38 = F_26 ( V_42 ) ;
V_39 = F_5 ( V_1 ) - F_7 ( V_1 ) ;
V_40 = F_6 ( V_1 ) + F_4 ( V_1 ) ;
memmove ( V_30 + V_40 , V_30 + V_39 , F_7 ( V_1 ) ) ;
F_19 ( V_1 , V_40 ) ;
V_5 = 0 ;
while ( ( V_23 = F_33 ( V_1 , V_5 , & V_41 ) ) != V_42 ) {
if ( V_23 == V_36 ) {
struct F_31 * V_34 =
F_9 ( V_1 , V_5 , sizeof( * V_34 ) ) ;
int V_35 ;
if ( ! V_34 )
return - V_43 ;
V_35 = F_34 ( V_34 -> V_35 ) ;
V_35 += F_7 ( V_1 ) ;
V_34 -> V_35 = F_26 ( V_35 ) ;
}
V_5 = V_41 ;
}
F_14 ( V_1 , V_40 + F_7 ( V_1 ) ) ;
F_11 ( V_1 , V_44 ) ;
return 0 ;
}
