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
V_3 += V_2 -> V_10 ;
while ( V_8 -- )
* V_9 ++ = F_1 ( V_2 , V_3 ++ ) ;
return 0 ;
}
static int F_5 ( const struct V_1 * V_2 ,
const unsigned int V_11 )
{
T_2 V_12 ;
int V_13 ;
V_12 = ( V_11 & V_14 )
<< V_15 ;
V_12 |= V_16 | V_17 ;
F_6 ( V_12 , V_2 -> V_5 + V_18 ) ;
V_13 = F_7 ( V_2 -> V_5 + V_18 , V_12 ,
! ( V_12 & V_17 ) , 100 , 250000 ) ;
if ( V_13 )
return V_13 ;
F_6 ( 0 , V_2 -> V_5 + V_18 ) ;
return 0 ;
}
static int F_8 ( struct V_19 * V_20 )
{
struct V_21 * V_22 = & V_20 -> V_22 ;
struct V_23 * V_24 ;
struct V_25 * V_26 ;
struct V_1 * V_2 ;
int V_13 , V_27 , V_28 ;
char * V_29 ;
const struct V_30 * V_31 ;
V_2 = F_9 ( V_22 , sizeof( * V_2 ) , V_32 ) ;
if ( ! V_2 )
return - V_33 ;
V_31 = F_10 ( V_22 ) ;
if ( ! V_31 )
return - V_34 ;
V_2 -> V_10 = V_31 -> V_10 ;
V_24 = F_11 ( V_20 , V_35 , 0 ) ;
V_2 -> V_5 = F_12 ( V_22 , V_24 ) ;
if ( F_13 ( V_2 -> V_5 ) )
return F_14 ( V_2 -> V_5 ) ;
V_28 = V_31 -> V_28 ;
if ( V_31 -> V_36 ) {
for ( V_27 = 0 ; V_27 < ( V_28 >> 2 ) ; V_27 ++ ) {
V_13 = F_5 ( V_2 , V_27 ) ;
if ( V_13 )
return V_13 ;
}
}
V_37 . V_28 = V_28 ;
V_37 . V_22 = V_22 ;
V_37 . V_38 = F_4 ;
V_37 . V_39 = V_2 ;
V_26 = F_15 ( & V_37 ) ;
if ( F_13 ( V_26 ) )
return F_14 ( V_26 ) ;
V_29 = F_16 ( sizeof( T_1 ) * ( V_28 ) , V_32 ) ;
if ( ! V_29 ) {
V_13 = - V_34 ;
goto V_40;
}
for ( V_27 = 0 ; V_27 < V_28 ; V_27 ++ )
V_29 [ V_27 ] = F_1 ( V_2 , V_27 ) ;
F_17 ( V_29 , V_28 ) ;
F_18 ( V_29 ) ;
F_19 ( V_20 , V_26 ) ;
return 0 ;
V_40:
F_20 ( V_26 ) ;
return V_13 ;
}
static int F_21 ( struct V_19 * V_20 )
{
struct V_25 * V_26 = F_22 ( V_20 ) ;
return F_20 ( V_26 ) ;
}
