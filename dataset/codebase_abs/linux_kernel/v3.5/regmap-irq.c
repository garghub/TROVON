static inline const
struct V_1 * F_1 ( struct V_2 * V_3 ,
int V_4 )
{
return & V_3 -> V_5 -> V_6 [ V_4 ] ;
}
static void F_2 ( struct V_7 * V_3 )
{
struct V_2 * V_8 = F_3 ( V_3 ) ;
F_4 ( & V_8 -> V_9 ) ;
}
static void F_5 ( struct V_7 * V_3 )
{
struct V_2 * V_8 = F_3 ( V_3 ) ;
struct V_10 * V_11 = V_8 -> V_11 ;
int V_12 , V_13 ;
for ( V_12 = 0 ; V_12 < V_8 -> V_5 -> V_14 ; V_12 ++ ) {
V_13 = F_6 ( V_8 -> V_11 , V_8 -> V_5 -> V_15 +
( V_12 * V_11 -> V_16 *
V_8 -> V_17 ) ,
V_8 -> V_18 [ V_12 ] , V_8 -> V_19 [ V_12 ] ) ;
if ( V_13 != 0 )
F_7 ( V_8 -> V_11 -> V_20 , L_1 ,
V_8 -> V_5 -> V_15 + ( V_12 * V_11 -> V_16 ) ) ;
}
F_8 ( & V_8 -> V_9 ) ;
}
static void F_9 ( struct V_7 * V_3 )
{
struct V_2 * V_8 = F_3 ( V_3 ) ;
struct V_10 * V_11 = V_8 -> V_11 ;
const struct V_1 * V_7 = F_1 ( V_8 , V_3 -> V_21 ) ;
V_8 -> V_19 [ V_7 -> V_22 / V_11 -> V_16 ] &= ~ V_7 -> V_23 ;
}
static void F_10 ( struct V_7 * V_3 )
{
struct V_2 * V_8 = F_3 ( V_3 ) ;
struct V_10 * V_11 = V_8 -> V_11 ;
const struct V_1 * V_7 = F_1 ( V_8 , V_3 -> V_21 ) ;
V_8 -> V_19 [ V_7 -> V_22 / V_11 -> V_16 ] |= V_7 -> V_23 ;
}
static T_1 F_11 ( int V_4 , void * V_8 )
{
struct V_2 * V_3 = V_8 ;
struct V_24 * V_5 = V_3 -> V_5 ;
struct V_10 * V_11 = V_3 -> V_11 ;
int V_13 , V_12 ;
bool V_25 = false ;
for ( V_12 = 0 ; V_12 < V_3 -> V_5 -> V_14 ; V_12 ++ ) {
V_13 = F_12 ( V_11 , V_5 -> V_26 + ( V_12 * V_11 -> V_16
* V_3 -> V_17 ) ,
& V_3 -> V_27 [ V_12 ] ) ;
if ( V_13 != 0 ) {
F_7 ( V_11 -> V_20 , L_2 ,
V_13 ) ;
return V_28 ;
}
V_3 -> V_27 [ V_12 ] &= ~ V_3 -> V_19 [ V_12 ] ;
if ( V_3 -> V_27 [ V_12 ] && V_5 -> V_29 ) {
V_13 = F_13 ( V_11 , V_5 -> V_29 +
( V_12 * V_11 -> V_16 *
V_3 -> V_17 ) ,
V_3 -> V_27 [ V_12 ] ) ;
if ( V_13 != 0 )
F_7 ( V_11 -> V_20 , L_3 ,
V_5 -> V_29 + ( V_12 * V_11 -> V_16 ) ,
V_13 ) ;
}
}
for ( V_12 = 0 ; V_12 < V_5 -> V_30 ; V_12 ++ ) {
if ( V_3 -> V_27 [ V_5 -> V_6 [ V_12 ] . V_22 /
V_11 -> V_16 ] & V_5 -> V_6 [ V_12 ] . V_23 ) {
F_14 ( F_15 ( V_3 -> V_31 , V_12 ) ) ;
V_25 = true ;
}
}
if ( V_25 )
return V_32 ;
else
return V_28 ;
}
static int F_16 ( struct V_33 * V_34 , unsigned int V_35 ,
T_2 V_36 )
{
struct V_2 * V_3 = V_34 -> V_37 ;
F_17 ( V_35 , V_3 ) ;
F_18 ( V_35 , & V_24 , V_38 ) ;
F_19 ( V_35 , 1 ) ;
#ifdef F_20
F_21 ( V_35 , V_39 ) ;
#else
F_22 ( V_35 ) ;
#endif
return 0 ;
}
int F_23 ( struct V_10 * V_11 , int V_4 , int V_40 ,
int V_41 , struct V_24 * V_5 ,
struct V_2 * * V_3 )
{
struct V_2 * V_8 ;
int V_12 ;
int V_13 = - V_42 ;
for ( V_12 = 0 ; V_12 < V_5 -> V_30 ; V_12 ++ ) {
if ( V_5 -> V_6 [ V_12 ] . V_22 % V_11 -> V_16 )
return - V_43 ;
if ( V_5 -> V_6 [ V_12 ] . V_22 / V_11 -> V_16 >=
V_5 -> V_14 )
return - V_43 ;
}
if ( V_41 ) {
V_41 = F_24 ( V_41 , 0 , V_5 -> V_30 , 0 ) ;
if ( V_41 < 0 ) {
F_25 ( V_11 -> V_20 , L_4 ,
V_41 ) ;
return V_41 ;
}
}
V_8 = F_26 ( sizeof( * V_8 ) , V_44 ) ;
if ( ! V_8 )
return - V_42 ;
* V_3 = V_8 ;
V_8 -> V_27 = F_26 ( sizeof( unsigned int ) * V_5 -> V_14 ,
V_44 ) ;
if ( ! V_8 -> V_27 )
goto V_45;
V_8 -> V_19 = F_26 ( sizeof( unsigned int ) * V_5 -> V_14 ,
V_44 ) ;
if ( ! V_8 -> V_19 )
goto V_45;
V_8 -> V_18 = F_26 ( sizeof( unsigned int ) * V_5 -> V_14 ,
V_44 ) ;
if ( ! V_8 -> V_18 )
goto V_45;
V_8 -> V_11 = V_11 ;
V_8 -> V_5 = V_5 ;
V_8 -> V_41 = V_41 ;
if ( V_5 -> V_17 )
V_8 -> V_17 = V_5 -> V_17 ;
else
V_8 -> V_17 = 1 ;
F_27 ( & V_8 -> V_9 ) ;
for ( V_12 = 0 ; V_12 < V_5 -> V_30 ; V_12 ++ )
V_8 -> V_18 [ V_5 -> V_6 [ V_12 ] . V_22 / V_11 -> V_16 ]
|= V_5 -> V_6 [ V_12 ] . V_23 ;
for ( V_12 = 0 ; V_12 < V_5 -> V_14 ; V_12 ++ ) {
V_8 -> V_19 [ V_12 ] = V_8 -> V_18 [ V_12 ] ;
V_13 = F_13 ( V_11 , V_5 -> V_15 + ( V_12 * V_11 -> V_16
* V_8 -> V_17 ) ,
V_8 -> V_19 [ V_12 ] ) ;
if ( V_13 != 0 ) {
F_7 ( V_11 -> V_20 , L_5 ,
V_5 -> V_15 + ( V_12 * V_11 -> V_16 ) , V_13 ) ;
goto V_45;
}
}
if ( V_41 )
V_8 -> V_31 = F_28 ( V_11 -> V_20 -> V_46 ,
V_5 -> V_30 , V_41 , 0 ,
& V_47 , V_8 ) ;
else
V_8 -> V_31 = F_29 ( V_11 -> V_20 -> V_46 ,
V_5 -> V_30 ,
& V_47 , V_8 ) ;
if ( ! V_8 -> V_31 ) {
F_7 ( V_11 -> V_20 , L_6 ) ;
V_13 = - V_42 ;
goto V_45;
}
V_13 = F_30 ( V_4 , NULL , F_11 , V_40 ,
V_5 -> V_48 , V_8 ) ;
if ( V_13 != 0 ) {
F_7 ( V_11 -> V_20 , L_7 , V_4 , V_13 ) ;
goto V_49;
}
return 0 ;
V_49:
V_45:
F_31 ( V_8 -> V_18 ) ;
F_31 ( V_8 -> V_19 ) ;
F_31 ( V_8 -> V_27 ) ;
F_31 ( V_8 ) ;
return V_13 ;
}
void F_32 ( int V_4 , struct V_2 * V_8 )
{
if ( ! V_8 )
return;
F_33 ( V_4 , V_8 ) ;
F_31 ( V_8 -> V_18 ) ;
F_31 ( V_8 -> V_19 ) ;
F_31 ( V_8 -> V_27 ) ;
F_31 ( V_8 ) ;
}
int F_34 ( struct V_2 * V_3 )
{
F_35 ( ! V_3 -> V_41 ) ;
return V_3 -> V_41 ;
}
int F_36 ( struct V_2 * V_3 , int V_4 )
{
return F_37 ( V_3 -> V_31 , V_4 ) ;
}
