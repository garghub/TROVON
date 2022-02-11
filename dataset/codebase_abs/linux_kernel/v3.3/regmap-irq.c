static inline const
struct V_1 * F_1 ( struct V_2 * V_3 ,
int V_4 )
{
return & V_3 -> V_5 -> V_6 [ V_4 - V_3 -> V_7 ] ;
}
static void F_2 ( struct V_8 * V_3 )
{
struct V_2 * V_9 = F_3 ( V_3 ) ;
F_4 ( & V_9 -> V_10 ) ;
}
static void F_5 ( struct V_8 * V_3 )
{
struct V_2 * V_9 = F_3 ( V_3 ) ;
int V_11 , V_12 ;
for ( V_11 = 0 ; V_11 < V_9 -> V_5 -> V_13 ; V_11 ++ ) {
V_12 = F_6 ( V_9 -> V_14 , V_9 -> V_5 -> V_15 + V_11 ,
V_9 -> V_16 [ V_11 ] , V_9 -> V_17 [ V_11 ] ) ;
if ( V_12 != 0 )
F_7 ( V_9 -> V_14 -> V_18 , L_1 ,
V_9 -> V_5 -> V_15 + V_11 ) ;
}
F_8 ( & V_9 -> V_10 ) ;
}
static void F_9 ( struct V_8 * V_3 )
{
struct V_2 * V_9 = F_3 ( V_3 ) ;
const struct V_1 * V_8 = F_1 ( V_9 , V_3 -> V_4 ) ;
V_9 -> V_17 [ V_8 -> V_19 ] &= ~ V_8 -> V_20 ;
}
static void F_10 ( struct V_8 * V_3 )
{
struct V_2 * V_9 = F_3 ( V_3 ) ;
const struct V_1 * V_8 = F_1 ( V_9 , V_3 -> V_4 ) ;
V_9 -> V_17 [ V_8 -> V_19 ] |= V_8 -> V_20 ;
}
static T_1 F_11 ( int V_4 , void * V_9 )
{
struct V_2 * V_3 = V_9 ;
struct V_21 * V_5 = V_3 -> V_5 ;
struct V_22 * V_14 = V_3 -> V_14 ;
int V_12 , V_11 ;
T_2 * V_23 = V_3 -> V_24 ;
T_3 * V_25 = V_3 -> V_24 ;
T_4 * V_26 = V_3 -> V_24 ;
bool V_27 = false ;
V_12 = F_12 ( V_14 , V_5 -> V_28 , V_3 -> V_24 ,
V_5 -> V_13 ) ;
if ( V_12 != 0 ) {
F_7 ( V_14 -> V_18 , L_2 , V_12 ) ;
return V_29 ;
}
for ( V_11 = 0 ; V_11 < V_3 -> V_5 -> V_13 ; V_11 ++ ) {
switch ( V_14 -> V_30 . V_31 ) {
case 1 :
V_3 -> V_32 [ V_11 ] = V_23 [ V_11 ] ;
break;
case 2 :
V_3 -> V_32 [ V_11 ] = V_25 [ V_11 ] ;
break;
case 4 :
V_3 -> V_32 [ V_11 ] = V_26 [ V_11 ] ;
break;
default:
F_13 () ;
return V_29 ;
}
V_3 -> V_32 [ V_11 ] &= ~ V_3 -> V_17 [ V_11 ] ;
if ( V_3 -> V_32 [ V_11 ] && V_5 -> V_33 ) {
V_12 = F_14 ( V_14 , V_5 -> V_33 + V_11 ,
V_3 -> V_32 [ V_11 ] ) ;
if ( V_12 != 0 )
F_7 ( V_14 -> V_18 , L_3 ,
V_5 -> V_33 + V_11 , V_12 ) ;
}
}
for ( V_11 = 0 ; V_11 < V_5 -> V_34 ; V_11 ++ ) {
if ( V_3 -> V_32 [ V_5 -> V_6 [ V_11 ] . V_19 ] &
V_5 -> V_6 [ V_11 ] . V_20 ) {
F_15 ( V_3 -> V_7 + V_11 ) ;
V_27 = true ;
}
}
if ( V_27 )
return V_35 ;
else
return V_29 ;
}
int F_16 ( struct V_22 * V_14 , int V_4 , int V_36 ,
int V_7 , struct V_21 * V_5 ,
struct V_2 * * V_3 )
{
struct V_2 * V_9 ;
int V_37 , V_11 ;
int V_12 = - V_38 ;
V_7 = F_17 ( V_7 , 0 , V_5 -> V_34 , 0 ) ;
if ( V_7 < 0 ) {
F_18 ( V_14 -> V_18 , L_4 ,
V_7 ) ;
return V_7 ;
}
V_9 = F_19 ( sizeof( * V_9 ) , V_39 ) ;
if ( ! V_9 )
return - V_38 ;
V_9 -> V_32 = F_19 ( sizeof( unsigned int ) * V_5 -> V_13 ,
V_39 ) ;
if ( ! V_9 -> V_32 )
goto V_40;
V_9 -> V_24 = F_19 ( V_14 -> V_30 . V_31 * V_5 -> V_13 ,
V_39 ) ;
if ( ! V_9 -> V_24 )
goto V_40;
V_9 -> V_17 = F_19 ( sizeof( unsigned int ) * V_5 -> V_13 ,
V_39 ) ;
if ( ! V_9 -> V_17 )
goto V_40;
V_9 -> V_16 = F_19 ( sizeof( unsigned int ) * V_5 -> V_13 ,
V_39 ) ;
if ( ! V_9 -> V_16 )
goto V_40;
V_9 -> V_14 = V_14 ;
V_9 -> V_5 = V_5 ;
V_9 -> V_7 = V_7 ;
F_20 ( & V_9 -> V_10 ) ;
for ( V_11 = 0 ; V_11 < V_5 -> V_34 ; V_11 ++ )
V_9 -> V_16 [ V_5 -> V_6 [ V_11 ] . V_19 ]
|= V_5 -> V_6 [ V_11 ] . V_20 ;
for ( V_11 = 0 ; V_11 < V_5 -> V_13 ; V_11 ++ ) {
V_9 -> V_17 [ V_11 ] = V_9 -> V_16 [ V_11 ] ;
V_12 = F_14 ( V_14 , V_5 -> V_15 + V_11 , V_9 -> V_17 [ V_11 ] ) ;
if ( V_12 != 0 ) {
F_7 ( V_14 -> V_18 , L_5 ,
V_5 -> V_15 + V_11 , V_12 ) ;
goto V_40;
}
}
for ( V_37 = V_7 ;
V_37 < V_5 -> V_34 + V_7 ;
V_37 ++ ) {
F_21 ( V_37 , V_9 ) ;
F_22 ( V_37 , & V_21 ,
V_41 ) ;
F_23 ( V_37 , 1 ) ;
#ifdef F_24
F_25 ( V_37 , V_42 ) ;
#else
F_26 ( V_37 ) ;
#endif
}
V_12 = F_27 ( V_4 , NULL , F_11 , V_36 ,
V_5 -> V_43 , V_9 ) ;
if ( V_12 != 0 ) {
F_7 ( V_14 -> V_18 , L_6 , V_4 , V_12 ) ;
goto V_40;
}
return 0 ;
V_40:
F_28 ( V_9 -> V_16 ) ;
F_28 ( V_9 -> V_17 ) ;
F_28 ( V_9 -> V_24 ) ;
F_28 ( V_9 -> V_32 ) ;
F_28 ( V_9 ) ;
return V_12 ;
}
void F_29 ( int V_4 , struct V_2 * V_9 )
{
if ( ! V_9 )
return;
F_30 ( V_4 , V_9 ) ;
F_28 ( V_9 -> V_16 ) ;
F_28 ( V_9 -> V_17 ) ;
F_28 ( V_9 -> V_24 ) ;
F_28 ( V_9 -> V_32 ) ;
F_28 ( V_9 ) ;
}
int F_31 ( struct V_2 * V_3 )
{
return V_3 -> V_7 ;
}
