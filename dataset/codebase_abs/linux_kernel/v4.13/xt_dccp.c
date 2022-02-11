static inline bool
F_1 ( T_1 V_1 ,
const struct V_2 * V_3 ,
unsigned int V_4 ,
const struct V_5 * V_6 ,
bool * V_7 )
{
const unsigned char * V_8 ;
unsigned int V_9 = F_2 ( V_6 ) ;
unsigned int V_10 = V_6 -> V_11 * 4 - F_2 ( V_6 ) ;
unsigned int V_12 ;
if ( V_6 -> V_11 * 4 < F_2 ( V_6 ) )
goto V_13;
if ( ! V_10 )
return false ;
F_3 ( & V_14 ) ;
V_8 = F_4 ( V_3 , V_4 + V_9 , V_10 , V_15 ) ;
if ( V_8 == NULL ) {
goto V_16;
}
for ( V_12 = 0 ; V_12 < V_10 ; ) {
if ( V_8 [ V_12 ] == V_1 ) {
F_5 ( & V_14 ) ;
return true ;
}
if ( V_8 [ V_12 ] < 2 )
V_12 ++ ;
else
V_12 += V_8 [ V_12 + 1 ] ? : 1 ;
}
F_5 ( & V_14 ) ;
return false ;
V_16:
F_5 ( & V_14 ) ;
V_13:
* V_7 = true ;
return false ;
}
static inline bool
F_6 ( const struct V_5 * V_6 , T_2 V_17 )
{
return V_17 & ( 1 << V_6 -> V_18 ) ;
}
static inline bool
F_7 ( T_1 V_1 , const struct V_2 * V_3 , unsigned int V_4 ,
const struct V_5 * V_6 , bool * V_7 )
{
return F_1 ( V_1 , V_3 , V_4 , V_6 , V_7 ) ;
}
static bool
F_8 ( const struct V_2 * V_3 , struct V_19 * V_20 )
{
const struct V_21 * V_22 = V_20 -> V_23 ;
const struct V_5 * V_6 ;
struct V_5 V_24 ;
if ( V_20 -> V_25 != 0 )
return false ;
V_6 = F_4 ( V_3 , V_20 -> V_26 , sizeof( V_24 ) , & V_24 ) ;
if ( V_6 == NULL ) {
V_20 -> V_7 = true ;
return false ;
}
return F_9 ( F_10 ( V_6 -> V_27 ) >= V_22 -> V_28 [ 0 ]
&& F_10 ( V_6 -> V_27 ) <= V_22 -> V_28 [ 1 ] ,
V_29 , V_22 -> V_30 , V_22 -> V_31 )
&& F_9 ( F_10 ( V_6 -> V_32 ) >= V_22 -> V_33 [ 0 ]
&& F_10 ( V_6 -> V_32 ) <= V_22 -> V_33 [ 1 ] ,
V_34 , V_22 -> V_30 , V_22 -> V_31 )
&& F_9 ( F_6 ( V_6 , V_22 -> V_17 ) ,
V_35 , V_22 -> V_30 , V_22 -> V_31 )
&& F_9 ( F_7 ( V_22 -> V_1 , V_3 , V_20 -> V_26 , V_6 ,
& V_20 -> V_7 ) ,
V_36 , V_22 -> V_30 , V_22 -> V_31 ) ;
}
static int F_11 ( const struct V_37 * V_20 )
{
const struct V_21 * V_22 = V_20 -> V_23 ;
if ( V_22 -> V_30 & ~ V_38 )
return - V_39 ;
if ( V_22 -> V_31 & ~ V_38 )
return - V_39 ;
if ( V_22 -> V_31 & ~ V_22 -> V_30 )
return - V_39 ;
return 0 ;
}
static int T_3 F_12 ( void )
{
int V_40 ;
V_15 = F_13 ( 256 * 4 , V_41 ) ;
if ( ! V_15 )
return - V_42 ;
V_40 = F_14 ( V_43 , F_15 ( V_43 ) ) ;
if ( V_40 )
goto V_44;
return V_40 ;
V_44:
F_16 ( V_15 ) ;
return V_40 ;
}
static void T_4 F_17 ( void )
{
F_18 ( V_43 , F_15 ( V_43 ) ) ;
F_16 ( V_15 ) ;
}
