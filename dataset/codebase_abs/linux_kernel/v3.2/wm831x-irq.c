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
V_6 -> V_26 [ V_7 ] = false ;
break;
case V_27 :
V_6 -> V_13 [ V_7 ] = 0x10000 | V_16 ;
V_6 -> V_26 [ V_7 ] = false ;
break;
case V_28 :
V_6 -> V_13 [ V_7 ] = 0x10000 ;
V_6 -> V_26 [ V_7 ] = false ;
break;
case V_29 :
V_6 -> V_13 [ V_7 ] = 0x10000 | V_16 ;
V_6 -> V_26 [ V_7 ] = true ;
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
int V_30 , V_31 , V_32 ;
int V_33 [ V_34 ] = { 0 } ;
int V_35 [ V_34 ] = { 0 } ;
int * V_36 ;
V_30 = F_17 ( V_6 , V_37 ) ;
if ( V_30 < 0 ) {
F_18 ( V_6 -> V_19 , L_2 ,
V_30 ) ;
goto V_38;
}
if ( V_30 & V_39 )
F_19 ( V_6 -> V_9 + V_40 ) ;
if ( V_30 & V_41 )
F_19 ( V_6 -> V_9 + V_42 ) ;
if ( V_30 & ( V_43 | V_44 ) )
goto V_38;
for ( V_12 = 0 ; V_12 < F_8 ( V_8 ) ; V_12 ++ ) {
int V_45 = V_8 [ V_12 ] . V_4 - 1 ;
if ( ! ( V_30 & V_8 [ V_12 ] . V_30 ) )
continue;
V_36 = & V_33 [ V_45 ] ;
if ( ! V_35 [ V_45 ] ) {
V_31 = F_1 ( & V_8 [ V_12 ] ) ;
* V_36 = F_17 ( V_6 , V_31 ) ;
if ( * V_36 < 0 ) {
F_18 ( V_6 -> V_19 ,
L_3 ,
* V_36 ) ;
goto V_38;
}
V_35 [ V_45 ] = 1 ;
* V_36 &= ~ V_6 -> V_17 [ V_45 ] ;
F_11 ( V_6 , V_31 , * V_36 ) ;
}
if ( * V_36 & V_8 [ V_12 ] . V_20 )
F_19 ( V_6 -> V_9 + V_12 ) ;
if ( V_30 == V_46 &&
V_6 -> V_26 [ V_12 - V_21 ] ) {
V_32 = F_17 ( V_6 , V_47 ) ;
while ( V_32 & 1 << ( V_12 - V_21 ) ) {
F_19 ( V_6 -> V_9 + V_12 ) ;
V_32 = F_17 ( V_6 ,
V_47 ) ;
}
}
}
V_38:
return V_48 ;
}
int F_20 ( struct V_6 * V_6 , int V_7 )
{
struct V_49 * V_50 = V_6 -> V_19 -> V_51 ;
int V_12 , V_52 , V_32 ;
F_21 ( & V_6 -> V_11 ) ;
for ( V_12 = 0 ; V_12 < F_8 ( V_6 -> V_17 ) ; V_12 ++ ) {
V_6 -> V_17 [ V_12 ] = 0xffff ;
V_6 -> V_18 [ V_12 ] = 0xffff ;
F_11 ( V_6 , V_5 + V_12 ,
0xffff ) ;
}
if ( ! V_50 || ! V_50 -> V_9 )
V_6 -> V_9 = - 1 ;
else
V_6 -> V_9 = V_50 -> V_9 ;
V_6 -> V_9 = F_22 ( V_6 -> V_9 , 0 ,
V_23 , 0 ) ;
if ( V_6 -> V_9 < 0 ) {
F_23 ( V_6 -> V_19 , L_4 ,
V_6 -> V_9 ) ;
V_6 -> V_9 = 0 ;
return 0 ;
}
if ( V_50 && V_50 -> V_53 )
V_12 = 0 ;
else
V_12 = V_54 ;
F_9 ( V_6 , V_55 ,
V_54 , V_12 ) ;
V_32 = F_24 ( V_7 ) ;
if ( V_32 != 0 ) {
F_23 ( V_6 -> V_19 , L_5 ,
V_32 ) ;
}
V_6 -> V_7 = V_7 ;
for ( V_52 = V_6 -> V_9 ;
V_52 < F_8 ( V_8 ) + V_6 -> V_9 ;
V_52 ++ ) {
F_25 ( V_52 , V_6 ) ;
F_26 ( V_52 , & V_56 ,
V_57 ) ;
F_27 ( V_52 , 1 ) ;
#ifdef F_28
F_29 ( V_52 , V_58 ) ;
#else
F_30 ( V_52 ) ;
#endif
}
if ( V_7 ) {
V_32 = F_31 ( V_7 , NULL , F_16 ,
V_59 | V_60 ,
L_6 , V_6 ) ;
if ( V_32 != 0 ) {
F_18 ( V_6 -> V_19 , L_7 ,
V_7 , V_32 ) ;
return V_32 ;
}
} else {
F_23 ( V_6 -> V_19 ,
L_8 ) ;
}
F_11 ( V_6 , V_61 , 0 ) ;
return 0 ;
}
void F_32 ( struct V_6 * V_6 )
{
if ( V_6 -> V_7 )
F_33 ( V_6 -> V_7 , V_6 ) ;
}
