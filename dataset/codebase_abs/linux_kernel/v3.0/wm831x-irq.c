static inline int F_1 ( struct V_1 * V_2 )
{
return V_3 - 1 + V_2 -> V_4 ;
}
static inline int F_2 ( struct V_1 * V_2 )
{
return V_5 - 1 + V_2 -> V_4 ;
}
static inline struct V_1 * F_3 ( struct V_6 * V_6 ,
int V_7 )
{
return & V_8 [ V_7 - V_6 -> V_9 ] ;
}
static void F_4 ( struct V_2 * V_10 )
{
struct V_6 * V_6 = F_5 ( V_10 ) ;
F_6 ( & V_6 -> V_11 ) ;
}
static void F_7 ( struct V_2 * V_10 )
{
struct V_6 * V_6 = F_5 ( V_10 ) ;
int V_12 ;
for ( V_12 = 0 ; V_12 < F_8 ( V_6 -> V_13 ) ; V_12 ++ ) {
if ( V_6 -> V_13 [ V_12 ] != V_6 -> V_14 [ V_12 ] ) {
F_9 ( V_6 -> V_15 , L_1 ,
V_5 + V_12 ,
V_6 -> V_13 [ V_12 ] ) ;
V_6 -> V_14 [ V_12 ] = V_6 -> V_13 [ V_12 ] ;
F_10 ( V_6 ,
V_5 + V_12 ,
V_6 -> V_13 [ V_12 ] ) ;
}
}
F_11 ( & V_6 -> V_11 ) ;
}
static void F_12 ( struct V_2 * V_10 )
{
struct V_6 * V_6 = F_5 ( V_10 ) ;
struct V_1 * V_2 = F_3 ( V_6 ,
V_10 -> V_7 ) ;
V_6 -> V_13 [ V_2 -> V_4 - 1 ] &= ~ V_2 -> V_16 ;
}
static void F_13 ( struct V_2 * V_10 )
{
struct V_6 * V_6 = F_5 ( V_10 ) ;
struct V_1 * V_2 = F_3 ( V_6 ,
V_10 -> V_7 ) ;
V_6 -> V_13 [ V_2 -> V_4 - 1 ] |= V_2 -> V_16 ;
}
static int F_14 ( struct V_2 * V_10 , unsigned int type )
{
struct V_6 * V_6 = F_5 ( V_10 ) ;
int V_17 , V_7 ;
V_7 = V_10 -> V_7 - V_6 -> V_9 ;
if ( V_7 < V_18 || V_7 > V_19 ) {
if ( V_7 >= 0 && V_7 < V_20 )
return 0 ;
else
return - V_21 ;
}
switch ( type ) {
case V_22 :
V_17 = V_23 ;
break;
case V_24 :
V_17 = V_25 ;
break;
case V_26 :
V_17 = 0 ;
break;
default:
return - V_21 ;
}
return F_15 ( V_6 , V_27 + V_7 ,
V_23 | V_25 , V_17 ) ;
}
static T_1 F_16 ( int V_7 , void * V_10 )
{
struct V_6 * V_6 = V_10 ;
unsigned int V_12 ;
int V_28 ;
int V_29 [ V_30 ] = { 0 } ;
int V_31 [ V_30 ] = { 0 } ;
int * V_32 ;
V_28 = F_17 ( V_6 , V_33 ) ;
if ( V_28 < 0 ) {
F_18 ( V_6 -> V_15 , L_2 ,
V_28 ) ;
goto V_34;
}
if ( V_28 & V_35 )
F_19 ( V_6 -> V_9 + V_36 ) ;
if ( V_28 & V_37 )
F_19 ( V_6 -> V_9 + V_38 ) ;
if ( V_28 & ( V_39 | V_40 ) )
goto V_34;
for ( V_12 = 0 ; V_12 < F_8 ( V_8 ) ; V_12 ++ ) {
int V_41 = V_8 [ V_12 ] . V_4 - 1 ;
if ( ! ( V_28 & V_8 [ V_12 ] . V_28 ) )
continue;
V_32 = & V_29 [ V_41 ] ;
if ( ! V_31 [ V_41 ] ) {
* V_32 = F_17 ( V_6 ,
F_1 ( & V_8 [ V_12 ] ) ) ;
if ( * V_32 < 0 ) {
F_18 ( V_6 -> V_15 ,
L_3 ,
* V_32 ) ;
goto V_34;
}
V_31 [ V_41 ] = 1 ;
}
if ( ( * V_32 & ~ V_6 -> V_13 [ V_41 ] )
& V_8 [ V_12 ] . V_16 )
F_19 ( V_6 -> V_9 + V_12 ) ;
else
* V_32 &= ~ V_8 [ V_12 ] . V_16 ;
}
V_34:
V_29 [ 0 ] &= ~ ( V_39 | V_40 ) ;
for ( V_12 = 0 ; V_12 < F_8 ( V_29 ) ; V_12 ++ ) {
if ( V_29 [ V_12 ] )
F_10 ( V_6 , V_3 + V_12 ,
V_29 [ V_12 ] ) ;
}
return V_42 ;
}
int F_20 ( struct V_6 * V_6 , int V_7 )
{
struct V_43 * V_44 = V_6 -> V_15 -> V_45 ;
int V_12 , V_46 , V_47 ;
F_21 ( & V_6 -> V_11 ) ;
for ( V_12 = 0 ; V_12 < F_8 ( V_6 -> V_13 ) ; V_12 ++ ) {
V_6 -> V_13 [ V_12 ] = 0xffff ;
V_6 -> V_14 [ V_12 ] = 0xffff ;
F_10 ( V_6 , V_5 + V_12 ,
0xffff ) ;
}
if ( ! V_44 || ! V_44 -> V_9 ) {
F_18 ( V_6 -> V_15 ,
L_4 ) ;
return 0 ;
}
if ( V_44 -> V_48 )
V_12 = 0 ;
else
V_12 = V_49 ;
F_15 ( V_6 , V_50 ,
V_49 , V_12 ) ;
V_47 = F_22 ( V_7 ) ;
if ( V_47 != 0 ) {
F_23 ( V_6 -> V_15 , L_5 ,
V_47 ) ;
}
V_6 -> V_7 = V_7 ;
V_6 -> V_9 = V_44 -> V_9 ;
for ( V_46 = V_6 -> V_9 ;
V_46 < F_8 ( V_8 ) + V_6 -> V_9 ;
V_46 ++ ) {
F_24 ( V_46 , V_6 ) ;
F_25 ( V_46 , & V_51 ,
V_52 ) ;
F_26 ( V_46 , 1 ) ;
#ifdef F_27
F_28 ( V_46 , V_53 ) ;
#else
F_29 ( V_46 ) ;
#endif
}
if ( V_7 ) {
V_47 = F_30 ( V_7 , NULL , F_16 ,
V_54 | V_55 ,
L_6 , V_6 ) ;
if ( V_47 != 0 ) {
F_18 ( V_6 -> V_15 , L_7 ,
V_7 , V_47 ) ;
return V_47 ;
}
} else {
F_23 ( V_6 -> V_15 ,
L_8 ) ;
}
F_10 ( V_6 , V_56 , 0 ) ;
return 0 ;
}
void F_31 ( struct V_6 * V_6 )
{
if ( V_6 -> V_7 )
F_32 ( V_6 -> V_7 , V_6 ) ;
}
