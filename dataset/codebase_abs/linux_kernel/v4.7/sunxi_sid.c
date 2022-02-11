static T_1 F_1 ( const struct V_1 * V_2 ,
const unsigned int V_3 )
{
T_2 V_4 ;
V_4 = F_2 ( V_2 -> V_5 + F_3 ( V_3 , 4 ) ) ;
V_4 >>= ( V_3 % 4 ) * 8 ;
return V_4 ;
}
static int F_4 ( void * V_6 , unsigned int V_3 ,
void * V_7 , T_3 V_8 )
{
struct V_1 * V_2 = V_6 ;
T_1 * V_9 = V_7 ;
while ( V_8 -- )
* V_9 ++ = F_1 ( V_2 , V_3 ++ ) ;
return 0 ;
}
static int F_5 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = & V_11 -> V_13 ;
struct V_14 * V_15 ;
struct V_16 * V_17 ;
struct V_1 * V_2 ;
int V_18 , V_19 , V_20 ;
char * V_21 ;
V_2 = F_6 ( V_13 , sizeof( * V_2 ) , V_22 ) ;
if ( ! V_2 )
return - V_23 ;
V_15 = F_7 ( V_11 , V_24 , 0 ) ;
V_2 -> V_5 = F_8 ( V_13 , V_15 ) ;
if ( F_9 ( V_2 -> V_5 ) )
return F_10 ( V_2 -> V_5 ) ;
V_20 = F_11 ( V_15 ) - 1 ;
V_25 . V_20 = F_11 ( V_15 ) ;
V_25 . V_13 = V_13 ;
V_25 . V_26 = F_4 ;
V_25 . V_27 = V_2 ;
V_17 = F_12 ( & V_25 ) ;
if ( F_9 ( V_17 ) )
return F_10 ( V_17 ) ;
V_21 = F_13 ( sizeof( T_1 ) * ( V_20 ) , V_22 ) ;
if ( ! V_21 ) {
V_18 = - V_28 ;
goto V_29;
}
for ( V_19 = 0 ; V_19 < V_20 ; V_19 ++ )
V_21 [ V_19 ] = F_1 ( V_2 , V_19 ) ;
F_14 ( V_21 , V_20 ) ;
F_15 ( V_21 ) ;
F_16 ( V_11 , V_17 ) ;
return 0 ;
V_29:
F_17 ( V_17 ) ;
return V_18 ;
}
static int F_18 ( struct V_10 * V_11 )
{
struct V_16 * V_17 = F_19 ( V_11 ) ;
return F_17 ( V_17 ) ;
}
