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
if ( V_8 -> V_21 < 0 )
for ( V_12 = V_8 -> V_21 ; V_12 < 0 ; V_12 ++ )
F_8 ( V_8 -> V_4 , 0 ) ;
else if ( V_8 -> V_21 > 0 )
for ( V_12 = 0 ; V_12 < V_8 -> V_21 ; V_12 ++ )
F_8 ( V_8 -> V_4 , 1 ) ;
V_8 -> V_21 = 0 ;
F_9 ( & V_8 -> V_9 ) ;
}
static void F_10 ( struct V_7 * V_3 )
{
struct V_2 * V_8 = F_3 ( V_3 ) ;
struct V_10 * V_11 = V_8 -> V_11 ;
const struct V_1 * V_7 = F_1 ( V_8 , V_3 -> V_22 ) ;
V_8 -> V_19 [ V_7 -> V_23 / V_11 -> V_16 ] &= ~ V_7 -> V_24 ;
}
static void F_11 ( struct V_7 * V_3 )
{
struct V_2 * V_8 = F_3 ( V_3 ) ;
struct V_10 * V_11 = V_8 -> V_11 ;
const struct V_1 * V_7 = F_1 ( V_8 , V_3 -> V_22 ) ;
V_8 -> V_19 [ V_7 -> V_23 / V_11 -> V_16 ] |= V_7 -> V_24 ;
}
static int F_12 ( struct V_7 * V_3 , unsigned int V_25 )
{
struct V_2 * V_8 = F_3 ( V_3 ) ;
struct V_10 * V_11 = V_8 -> V_11 ;
const struct V_1 * V_7 = F_1 ( V_8 , V_3 -> V_22 ) ;
if ( ! V_8 -> V_5 -> V_26 )
return - V_27 ;
if ( V_25 ) {
V_8 -> V_28 [ V_7 -> V_23 / V_11 -> V_16 ]
&= ~ V_7 -> V_24 ;
V_8 -> V_21 ++ ;
} else {
V_8 -> V_28 [ V_7 -> V_23 / V_11 -> V_16 ]
|= V_7 -> V_24 ;
V_8 -> V_21 -- ;
}
return 0 ;
}
static T_1 F_13 ( int V_4 , void * V_8 )
{
struct V_2 * V_3 = V_8 ;
const struct V_29 * V_5 = V_3 -> V_5 ;
struct V_10 * V_11 = V_3 -> V_11 ;
int V_13 , V_12 ;
bool V_30 = false ;
for ( V_12 = 0 ; V_12 < V_3 -> V_5 -> V_14 ; V_12 ++ ) {
V_13 = F_14 ( V_11 , V_5 -> V_31 + ( V_12 * V_11 -> V_16
* V_3 -> V_17 ) ,
& V_3 -> V_32 [ V_12 ] ) ;
if ( V_13 != 0 ) {
F_7 ( V_11 -> V_20 , L_2 ,
V_13 ) ;
return V_33 ;
}
V_3 -> V_32 [ V_12 ] &= ~ V_3 -> V_19 [ V_12 ] ;
if ( V_3 -> V_32 [ V_12 ] && V_5 -> V_34 ) {
V_13 = F_15 ( V_11 , V_5 -> V_34 +
( V_12 * V_11 -> V_16 *
V_3 -> V_17 ) ,
V_3 -> V_32 [ V_12 ] ) ;
if ( V_13 != 0 )
F_7 ( V_11 -> V_20 , L_3 ,
V_5 -> V_34 + ( V_12 * V_11 -> V_16 ) ,
V_13 ) ;
}
}
for ( V_12 = 0 ; V_12 < V_5 -> V_35 ; V_12 ++ ) {
if ( V_3 -> V_32 [ V_5 -> V_6 [ V_12 ] . V_23 /
V_11 -> V_16 ] & V_5 -> V_6 [ V_12 ] . V_24 ) {
F_16 ( F_17 ( V_3 -> V_36 , V_12 ) ) ;
V_30 = true ;
}
}
if ( V_30 )
return V_37 ;
else
return V_33 ;
}
static int F_18 ( struct V_38 * V_39 , unsigned int V_40 ,
T_2 V_41 )
{
struct V_2 * V_3 = V_39 -> V_42 ;
F_19 ( V_40 , V_3 ) ;
F_20 ( V_40 , & V_29 , V_43 ) ;
F_21 ( V_40 , 1 ) ;
#ifdef F_22
F_23 ( V_40 , V_44 ) ;
#else
F_24 ( V_40 ) ;
#endif
return 0 ;
}
int F_25 ( struct V_10 * V_11 , int V_4 , int V_45 ,
int V_46 , const struct V_29 * V_5 ,
struct V_2 * * V_3 )
{
struct V_2 * V_8 ;
int V_12 ;
int V_13 = - V_47 ;
for ( V_12 = 0 ; V_12 < V_5 -> V_35 ; V_12 ++ ) {
if ( V_5 -> V_6 [ V_12 ] . V_23 % V_11 -> V_16 )
return - V_27 ;
if ( V_5 -> V_6 [ V_12 ] . V_23 / V_11 -> V_16 >=
V_5 -> V_14 )
return - V_27 ;
}
if ( V_46 ) {
V_46 = F_26 ( V_46 , 0 , V_5 -> V_35 , 0 ) ;
if ( V_46 < 0 ) {
F_27 ( V_11 -> V_20 , L_4 ,
V_46 ) ;
return V_46 ;
}
}
V_8 = F_28 ( sizeof( * V_8 ) , V_48 ) ;
if ( ! V_8 )
return - V_47 ;
* V_3 = V_8 ;
V_8 -> V_32 = F_28 ( sizeof( unsigned int ) * V_5 -> V_14 ,
V_48 ) ;
if ( ! V_8 -> V_32 )
goto V_49;
V_8 -> V_19 = F_28 ( sizeof( unsigned int ) * V_5 -> V_14 ,
V_48 ) ;
if ( ! V_8 -> V_19 )
goto V_49;
V_8 -> V_18 = F_28 ( sizeof( unsigned int ) * V_5 -> V_14 ,
V_48 ) ;
if ( ! V_8 -> V_18 )
goto V_49;
if ( V_5 -> V_26 ) {
V_8 -> V_28 = F_28 ( sizeof( unsigned int ) * V_5 -> V_14 ,
V_48 ) ;
if ( ! V_8 -> V_28 )
goto V_49;
}
V_8 -> V_4 = V_4 ;
V_8 -> V_11 = V_11 ;
V_8 -> V_5 = V_5 ;
V_8 -> V_46 = V_46 ;
if ( V_5 -> V_17 )
V_8 -> V_17 = V_5 -> V_17 ;
else
V_8 -> V_17 = 1 ;
F_29 ( & V_8 -> V_9 ) ;
for ( V_12 = 0 ; V_12 < V_5 -> V_35 ; V_12 ++ )
V_8 -> V_18 [ V_5 -> V_6 [ V_12 ] . V_23 / V_11 -> V_16 ]
|= V_5 -> V_6 [ V_12 ] . V_24 ;
for ( V_12 = 0 ; V_12 < V_5 -> V_14 ; V_12 ++ ) {
V_8 -> V_19 [ V_12 ] = V_8 -> V_18 [ V_12 ] ;
V_13 = F_15 ( V_11 , V_5 -> V_15 + ( V_12 * V_11 -> V_16
* V_8 -> V_17 ) ,
V_8 -> V_19 [ V_12 ] ) ;
if ( V_13 != 0 ) {
F_7 ( V_11 -> V_20 , L_5 ,
V_5 -> V_15 + ( V_12 * V_11 -> V_16 ) , V_13 ) ;
goto V_49;
}
}
if ( V_46 )
V_8 -> V_36 = F_30 ( V_11 -> V_20 -> V_50 ,
V_5 -> V_35 , V_46 , 0 ,
& V_51 , V_8 ) ;
else
V_8 -> V_36 = F_31 ( V_11 -> V_20 -> V_50 ,
V_5 -> V_35 ,
& V_51 , V_8 ) ;
if ( ! V_8 -> V_36 ) {
F_7 ( V_11 -> V_20 , L_6 ) ;
V_13 = - V_47 ;
goto V_49;
}
V_13 = F_32 ( V_4 , NULL , F_13 , V_45 ,
V_5 -> V_52 , V_8 ) ;
if ( V_13 != 0 ) {
F_7 ( V_11 -> V_20 , L_7 , V_4 , V_13 ) ;
goto V_53;
}
return 0 ;
V_53:
V_49:
F_33 ( V_8 -> V_28 ) ;
F_33 ( V_8 -> V_18 ) ;
F_33 ( V_8 -> V_19 ) ;
F_33 ( V_8 -> V_32 ) ;
F_33 ( V_8 ) ;
return V_13 ;
}
void F_34 ( int V_4 , struct V_2 * V_8 )
{
if ( ! V_8 )
return;
F_35 ( V_4 , V_8 ) ;
F_33 ( V_8 -> V_28 ) ;
F_33 ( V_8 -> V_18 ) ;
F_33 ( V_8 -> V_19 ) ;
F_33 ( V_8 -> V_32 ) ;
F_33 ( V_8 ) ;
}
int F_36 ( struct V_2 * V_3 )
{
F_37 ( ! V_3 -> V_46 ) ;
return V_3 -> V_46 ;
}
int F_38 ( struct V_2 * V_3 , int V_4 )
{
if ( ! V_3 -> V_5 -> V_6 [ V_4 ] . V_24 )
return - V_27 ;
return F_39 ( V_3 -> V_36 , V_4 ) ;
}
