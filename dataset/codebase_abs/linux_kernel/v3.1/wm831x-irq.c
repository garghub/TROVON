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
if ( V_6 -> V_13 [ V_12 ] ) {
F_9 ( V_6 , V_14 + V_12 ,
V_15 | V_16 ,
V_6 -> V_13 [ V_12 ] ) ;
V_6 -> V_13 [ V_12 ] = 0 ;
}
}
for ( V_12 = 0 ; V_12 < F_8 ( V_6 -> V_17 ) ; V_12 ++ ) {
if ( V_6 -> V_17 [ V_12 ] != V_6 -> V_18 [ V_12 ] ) {
F_10 ( V_6 -> V_19 , L_1 ,
V_5 + V_12 ,
V_6 -> V_17 [ V_12 ] ) ;
V_6 -> V_18 [ V_12 ] = V_6 -> V_17 [ V_12 ] ;
F_11 ( V_6 ,
V_5 + V_12 ,
V_6 -> V_17 [ V_12 ] ) ;
}
}
F_12 ( & V_6 -> V_11 ) ;
}
static void F_13 ( struct V_2 * V_10 )
{
struct V_6 * V_6 = F_5 ( V_10 ) ;
struct V_1 * V_2 = F_3 ( V_6 ,
V_10 -> V_7 ) ;
V_6 -> V_17 [ V_2 -> V_4 - 1 ] &= ~ V_2 -> V_20 ;
}
static void F_14 ( struct V_2 * V_10 )
{
struct V_6 * V_6 = F_5 ( V_10 ) ;
struct V_1 * V_2 = F_3 ( V_6 ,
V_10 -> V_7 ) ;
V_6 -> V_17 [ V_2 -> V_4 - 1 ] |= V_2 -> V_20 ;
}
static int F_15 ( struct V_2 * V_10 , unsigned int type )
{
struct V_6 * V_6 = F_5 ( V_10 ) ;
int V_7 ;
V_7 = V_10 -> V_7 - V_6 -> V_9 ;
if ( V_7 < V_21 || V_7 > V_22 ) {
if ( V_7 >= 0 && V_7 < V_23 )
return 0 ;
else
return - V_24 ;
}
V_7 -= V_21 ;
switch ( type ) {
case V_25 :
V_6 -> V_13 [ V_7 ] = 0x10000 | V_15 ;
break;
case V_26 :
V_6 -> V_13 [ V_7 ] = 0x10000 | V_16 ;
break;
case V_27 :
V_6 -> V_13 [ V_7 ] = 0x10000 ;
break;
default:
return - V_24 ;
}
return 0 ;
}
static T_1 F_16 ( int V_7 , void * V_10 )
{
struct V_6 * V_6 = V_10 ;
unsigned int V_12 ;
int V_28 , V_29 ;
int V_30 [ V_31 ] = { 0 } ;
int V_32 [ V_31 ] = { 0 } ;
int * V_33 ;
V_28 = F_17 ( V_6 , V_34 ) ;
if ( V_28 < 0 ) {
F_18 ( V_6 -> V_19 , L_2 ,
V_28 ) ;
goto V_35;
}
if ( V_28 & V_36 )
F_19 ( V_6 -> V_9 + V_37 ) ;
if ( V_28 & V_38 )
F_19 ( V_6 -> V_9 + V_39 ) ;
if ( V_28 & ( V_40 | V_41 ) )
goto V_35;
for ( V_12 = 0 ; V_12 < F_8 ( V_8 ) ; V_12 ++ ) {
int V_42 = V_8 [ V_12 ] . V_4 - 1 ;
if ( ! ( V_28 & V_8 [ V_12 ] . V_28 ) )
continue;
V_33 = & V_30 [ V_42 ] ;
if ( ! V_32 [ V_42 ] ) {
V_29 = F_1 ( & V_8 [ V_12 ] ) ;
* V_33 = F_17 ( V_6 , V_29 ) ;
if ( * V_33 < 0 ) {
F_18 ( V_6 -> V_19 ,
L_3 ,
* V_33 ) ;
goto V_35;
}
V_32 [ V_42 ] = 1 ;
* V_33 &= ~ V_6 -> V_17 [ V_42 ] ;
F_11 ( V_6 , V_29 , * V_33 ) ;
}
if ( * V_33 & V_8 [ V_12 ] . V_20 )
F_19 ( V_6 -> V_9 + V_12 ) ;
}
V_35:
return V_43 ;
}
int F_20 ( struct V_6 * V_6 , int V_7 )
{
struct V_44 * V_45 = V_6 -> V_19 -> V_46 ;
int V_12 , V_47 , V_48 ;
F_21 ( & V_6 -> V_11 ) ;
for ( V_12 = 0 ; V_12 < F_8 ( V_6 -> V_17 ) ; V_12 ++ ) {
V_6 -> V_17 [ V_12 ] = 0xffff ;
V_6 -> V_18 [ V_12 ] = 0xffff ;
F_11 ( V_6 , V_5 + V_12 ,
0xffff ) ;
}
if ( ! V_45 || ! V_45 -> V_9 )
V_6 -> V_9 = - 1 ;
else
V_6 -> V_9 = V_45 -> V_9 ;
V_6 -> V_9 = F_22 ( V_6 -> V_9 , 0 ,
V_23 , 0 ) ;
if ( V_6 -> V_9 < 0 ) {
F_23 ( V_6 -> V_19 , L_4 ,
V_6 -> V_9 ) ;
V_6 -> V_9 = 0 ;
return 0 ;
}
if ( V_45 && V_45 -> V_49 )
V_12 = 0 ;
else
V_12 = V_50 ;
F_9 ( V_6 , V_51 ,
V_50 , V_12 ) ;
V_48 = F_24 ( V_7 ) ;
if ( V_48 != 0 ) {
F_23 ( V_6 -> V_19 , L_5 ,
V_48 ) ;
}
V_6 -> V_7 = V_7 ;
for ( V_47 = V_6 -> V_9 ;
V_47 < F_8 ( V_8 ) + V_6 -> V_9 ;
V_47 ++ ) {
F_25 ( V_47 , V_6 ) ;
F_26 ( V_47 , & V_52 ,
V_53 ) ;
F_27 ( V_47 , 1 ) ;
#ifdef F_28
F_29 ( V_47 , V_54 ) ;
#else
F_30 ( V_47 ) ;
#endif
}
if ( V_7 ) {
V_48 = F_31 ( V_7 , NULL , F_16 ,
V_55 | V_56 ,
L_6 , V_6 ) ;
if ( V_48 != 0 ) {
F_18 ( V_6 -> V_19 , L_7 ,
V_7 , V_48 ) ;
return V_48 ;
}
} else {
F_23 ( V_6 -> V_19 ,
L_8 ) ;
}
F_11 ( V_6 , V_57 , 0 ) ;
return 0 ;
}
void F_32 ( struct V_6 * V_6 )
{
if ( V_6 -> V_7 )
F_33 ( V_6 -> V_7 , V_6 ) ;
}
