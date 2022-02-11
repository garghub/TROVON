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
T_1 V_14 ;
if ( V_8 -> V_5 -> V_15 ) {
V_13 = F_6 ( V_11 -> V_16 ) ;
if ( V_13 < 0 )
F_7 ( V_11 -> V_16 , L_1 ,
V_13 ) ;
}
for ( V_12 = 0 ; V_12 < V_8 -> V_5 -> V_17 ; V_12 ++ ) {
V_14 = V_8 -> V_5 -> V_18 +
( V_12 * V_11 -> V_19 * V_8 -> V_20 ) ;
if ( V_8 -> V_5 -> V_21 )
V_13 = F_8 ( V_8 -> V_11 , V_14 ,
V_8 -> V_22 [ V_12 ] , ~ V_8 -> V_23 [ V_12 ] ) ;
else
V_13 = F_8 ( V_8 -> V_11 , V_14 ,
V_8 -> V_22 [ V_12 ] , V_8 -> V_23 [ V_12 ] ) ;
if ( V_13 != 0 )
F_7 ( V_8 -> V_11 -> V_16 , L_2 ,
V_14 ) ;
}
if ( V_8 -> V_5 -> V_15 )
F_9 ( V_11 -> V_16 ) ;
if ( V_8 -> V_24 < 0 )
for ( V_12 = V_8 -> V_24 ; V_12 < 0 ; V_12 ++ )
F_10 ( V_8 -> V_4 , 0 ) ;
else if ( V_8 -> V_24 > 0 )
for ( V_12 = 0 ; V_12 < V_8 -> V_24 ; V_12 ++ )
F_10 ( V_8 -> V_4 , 1 ) ;
V_8 -> V_24 = 0 ;
F_11 ( & V_8 -> V_9 ) ;
}
static void F_12 ( struct V_7 * V_3 )
{
struct V_2 * V_8 = F_3 ( V_3 ) ;
struct V_10 * V_11 = V_8 -> V_11 ;
const struct V_1 * V_7 = F_1 ( V_8 , V_3 -> V_25 ) ;
V_8 -> V_23 [ V_7 -> V_26 / V_11 -> V_19 ] &= ~ V_7 -> V_27 ;
}
static void F_13 ( struct V_7 * V_3 )
{
struct V_2 * V_8 = F_3 ( V_3 ) ;
struct V_10 * V_11 = V_8 -> V_11 ;
const struct V_1 * V_7 = F_1 ( V_8 , V_3 -> V_25 ) ;
V_8 -> V_23 [ V_7 -> V_26 / V_11 -> V_19 ] |= V_7 -> V_27 ;
}
static int F_14 ( struct V_7 * V_3 , unsigned int V_28 )
{
struct V_2 * V_8 = F_3 ( V_3 ) ;
struct V_10 * V_11 = V_8 -> V_11 ;
const struct V_1 * V_7 = F_1 ( V_8 , V_3 -> V_25 ) ;
if ( ! V_8 -> V_5 -> V_29 )
return - V_30 ;
if ( V_28 ) {
V_8 -> V_31 [ V_7 -> V_26 / V_11 -> V_19 ]
&= ~ V_7 -> V_27 ;
V_8 -> V_24 ++ ;
} else {
V_8 -> V_31 [ V_7 -> V_26 / V_11 -> V_19 ]
|= V_7 -> V_27 ;
V_8 -> V_24 -- ;
}
return 0 ;
}
static T_2 F_15 ( int V_4 , void * V_8 )
{
struct V_2 * V_3 = V_8 ;
const struct V_32 * V_5 = V_3 -> V_5 ;
struct V_10 * V_11 = V_3 -> V_11 ;
int V_13 , V_12 ;
bool V_33 = false ;
T_1 V_14 ;
if ( V_5 -> V_15 ) {
V_13 = F_6 ( V_11 -> V_16 ) ;
if ( V_13 < 0 ) {
F_7 ( V_11 -> V_16 , L_3 ,
V_13 ) ;
return V_34 ;
}
}
for ( V_12 = 0 ; V_12 < V_3 -> V_5 -> V_17 ; V_12 ++ ) {
V_13 = F_16 ( V_11 , V_5 -> V_35 + ( V_12 * V_11 -> V_19
* V_3 -> V_20 ) ,
& V_3 -> V_36 [ V_12 ] ) ;
if ( V_13 != 0 ) {
F_7 ( V_11 -> V_16 , L_4 ,
V_13 ) ;
if ( V_5 -> V_15 )
F_9 ( V_11 -> V_16 ) ;
return V_34 ;
}
V_3 -> V_36 [ V_12 ] &= ~ V_3 -> V_23 [ V_12 ] ;
if ( V_3 -> V_36 [ V_12 ] && V_5 -> V_37 ) {
V_14 = V_5 -> V_37 +
( V_12 * V_11 -> V_19 * V_3 -> V_20 ) ;
V_13 = F_17 ( V_11 , V_14 , V_3 -> V_36 [ V_12 ] ) ;
if ( V_13 != 0 )
F_7 ( V_11 -> V_16 , L_5 ,
V_14 , V_13 ) ;
}
}
for ( V_12 = 0 ; V_12 < V_5 -> V_38 ; V_12 ++ ) {
if ( V_3 -> V_36 [ V_5 -> V_6 [ V_12 ] . V_26 /
V_11 -> V_19 ] & V_5 -> V_6 [ V_12 ] . V_27 ) {
F_18 ( F_19 ( V_3 -> V_39 , V_12 ) ) ;
V_33 = true ;
}
}
if ( V_5 -> V_15 )
F_9 ( V_11 -> V_16 ) ;
if ( V_33 )
return V_40 ;
else
return V_34 ;
}
static int F_20 ( struct V_41 * V_42 , unsigned int V_43 ,
T_3 V_44 )
{
struct V_2 * V_3 = V_42 -> V_45 ;
F_21 ( V_43 , V_3 ) ;
F_22 ( V_43 , & V_3 -> V_46 ) ;
F_23 ( V_43 , 1 ) ;
#ifdef F_24
F_25 ( V_43 , V_47 ) ;
#else
F_26 ( V_43 ) ;
#endif
return 0 ;
}
int F_27 ( struct V_10 * V_11 , int V_4 , int V_48 ,
int V_49 , const struct V_32 * V_5 ,
struct V_2 * * V_3 )
{
struct V_2 * V_8 ;
int V_12 ;
int V_13 = - V_50 ;
T_1 V_14 ;
for ( V_12 = 0 ; V_12 < V_5 -> V_38 ; V_12 ++ ) {
if ( V_5 -> V_6 [ V_12 ] . V_26 % V_11 -> V_19 )
return - V_30 ;
if ( V_5 -> V_6 [ V_12 ] . V_26 / V_11 -> V_19 >=
V_5 -> V_17 )
return - V_30 ;
}
if ( V_49 ) {
V_49 = F_28 ( V_49 , 0 , V_5 -> V_38 , 0 ) ;
if ( V_49 < 0 ) {
F_29 ( V_11 -> V_16 , L_6 ,
V_49 ) ;
return V_49 ;
}
}
V_8 = F_30 ( sizeof( * V_8 ) , V_51 ) ;
if ( ! V_8 )
return - V_50 ;
* V_3 = V_8 ;
V_8 -> V_36 = F_30 ( sizeof( unsigned int ) * V_5 -> V_17 ,
V_51 ) ;
if ( ! V_8 -> V_36 )
goto V_52;
V_8 -> V_23 = F_30 ( sizeof( unsigned int ) * V_5 -> V_17 ,
V_51 ) ;
if ( ! V_8 -> V_23 )
goto V_52;
V_8 -> V_22 = F_30 ( sizeof( unsigned int ) * V_5 -> V_17 ,
V_51 ) ;
if ( ! V_8 -> V_22 )
goto V_52;
if ( V_5 -> V_29 ) {
V_8 -> V_31 = F_30 ( sizeof( unsigned int ) * V_5 -> V_17 ,
V_51 ) ;
if ( ! V_8 -> V_31 )
goto V_52;
}
V_8 -> V_46 = V_32 ;
V_8 -> V_46 . V_53 = V_5 -> V_53 ;
if ( ! V_5 -> V_29 ) {
V_8 -> V_46 . V_54 = NULL ;
V_8 -> V_46 . V_55 |= V_56 |
V_57 ;
}
V_8 -> V_4 = V_4 ;
V_8 -> V_11 = V_11 ;
V_8 -> V_5 = V_5 ;
V_8 -> V_49 = V_49 ;
if ( V_5 -> V_20 )
V_8 -> V_20 = V_5 -> V_20 ;
else
V_8 -> V_20 = 1 ;
F_31 ( & V_8 -> V_9 ) ;
for ( V_12 = 0 ; V_12 < V_5 -> V_38 ; V_12 ++ )
V_8 -> V_22 [ V_5 -> V_6 [ V_12 ] . V_26 / V_11 -> V_19 ]
|= V_5 -> V_6 [ V_12 ] . V_27 ;
for ( V_12 = 0 ; V_12 < V_5 -> V_17 ; V_12 ++ ) {
V_8 -> V_23 [ V_12 ] = V_8 -> V_22 [ V_12 ] ;
V_14 = V_5 -> V_18 +
( V_12 * V_11 -> V_19 * V_8 -> V_20 ) ;
if ( V_5 -> V_21 )
V_13 = F_8 ( V_11 , V_14 ,
V_8 -> V_23 [ V_12 ] , ~ V_8 -> V_23 [ V_12 ] ) ;
else
V_13 = F_8 ( V_11 , V_14 ,
V_8 -> V_23 [ V_12 ] , V_8 -> V_23 [ V_12 ] ) ;
if ( V_13 != 0 ) {
F_7 ( V_11 -> V_16 , L_7 ,
V_14 , V_13 ) ;
goto V_52;
}
}
if ( V_8 -> V_31 ) {
for ( V_12 = 0 ; V_12 < V_5 -> V_17 ; V_12 ++ ) {
V_8 -> V_31 [ V_12 ] = V_8 -> V_22 [ V_12 ] ;
V_14 = V_5 -> V_29 +
( V_12 * V_11 -> V_19 * V_8 -> V_20 ) ;
V_13 = F_8 ( V_11 , V_14 , V_8 -> V_31 [ V_12 ] ,
V_8 -> V_31 [ V_12 ] ) ;
if ( V_13 != 0 ) {
F_7 ( V_11 -> V_16 , L_7 ,
V_14 , V_13 ) ;
goto V_52;
}
}
}
if ( V_49 )
V_8 -> V_39 = F_32 ( V_11 -> V_16 -> V_58 ,
V_5 -> V_38 , V_49 , 0 ,
& V_59 , V_8 ) ;
else
V_8 -> V_39 = F_33 ( V_11 -> V_16 -> V_58 ,
V_5 -> V_38 ,
& V_59 , V_8 ) ;
if ( ! V_8 -> V_39 ) {
F_7 ( V_11 -> V_16 , L_8 ) ;
V_13 = - V_50 ;
goto V_52;
}
V_13 = F_34 ( V_4 , NULL , F_15 , V_48 ,
V_5 -> V_53 , V_8 ) ;
if ( V_13 != 0 ) {
F_7 ( V_11 -> V_16 , L_9 , V_4 , V_13 ) ;
goto V_60;
}
return 0 ;
V_60:
V_52:
F_35 ( V_8 -> V_31 ) ;
F_35 ( V_8 -> V_22 ) ;
F_35 ( V_8 -> V_23 ) ;
F_35 ( V_8 -> V_36 ) ;
F_35 ( V_8 ) ;
return V_13 ;
}
void F_36 ( int V_4 , struct V_2 * V_8 )
{
if ( ! V_8 )
return;
F_37 ( V_4 , V_8 ) ;
F_35 ( V_8 -> V_31 ) ;
F_35 ( V_8 -> V_22 ) ;
F_35 ( V_8 -> V_23 ) ;
F_35 ( V_8 -> V_36 ) ;
F_35 ( V_8 ) ;
}
int F_38 ( struct V_2 * V_3 )
{
F_39 ( ! V_3 -> V_49 ) ;
return V_3 -> V_49 ;
}
int F_40 ( struct V_2 * V_3 , int V_4 )
{
if ( ! V_3 -> V_5 -> V_6 [ V_4 ] . V_27 )
return - V_30 ;
return F_41 ( V_3 -> V_39 , V_4 ) ;
}
