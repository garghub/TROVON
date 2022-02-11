static inline int F_1 ( struct V_1 * V_2 )
{
return V_3 - 1 + V_2 -> V_4 ;
}
static inline struct V_1 * F_2 ( struct V_5 * V_5 ,
int V_6 )
{
return & V_7 [ V_6 - V_5 -> V_8 ] ;
}
static void F_3 ( struct V_2 * V_9 )
{
struct V_5 * V_5 = F_4 ( V_9 ) ;
F_5 ( & V_5 -> V_10 ) ;
}
static void F_6 ( struct V_2 * V_9 )
{
struct V_5 * V_5 = F_4 ( V_9 ) ;
int V_11 ;
for ( V_11 = 0 ; V_11 < F_7 ( V_5 -> V_12 ) ; V_11 ++ ) {
if ( V_5 -> V_12 [ V_11 ] ) {
F_8 ( V_5 , V_13 + V_11 ,
V_14 | V_15 ,
V_5 -> V_12 [ V_11 ] ) ;
V_5 -> V_12 [ V_11 ] = 0 ;
}
}
for ( V_11 = 0 ; V_11 < F_7 ( V_5 -> V_16 ) ; V_11 ++ ) {
if ( V_5 -> V_16 [ V_11 ] != V_5 -> V_17 [ V_11 ] ) {
F_9 ( V_5 -> V_18 , L_1 ,
V_19 + V_11 ,
V_5 -> V_16 [ V_11 ] ) ;
V_5 -> V_17 [ V_11 ] = V_5 -> V_16 [ V_11 ] ;
F_10 ( V_5 ,
V_19 + V_11 ,
V_5 -> V_16 [ V_11 ] ) ;
}
}
F_11 ( & V_5 -> V_10 ) ;
}
static void F_12 ( struct V_2 * V_9 )
{
struct V_5 * V_5 = F_4 ( V_9 ) ;
struct V_1 * V_2 = F_2 ( V_5 ,
V_9 -> V_6 ) ;
V_5 -> V_16 [ V_2 -> V_4 - 1 ] &= ~ V_2 -> V_20 ;
}
static void F_13 ( struct V_2 * V_9 )
{
struct V_5 * V_5 = F_4 ( V_9 ) ;
struct V_1 * V_2 = F_2 ( V_5 ,
V_9 -> V_6 ) ;
V_5 -> V_16 [ V_2 -> V_4 - 1 ] |= V_2 -> V_20 ;
}
static int F_14 ( struct V_2 * V_9 , unsigned int type )
{
struct V_5 * V_5 = F_4 ( V_9 ) ;
int V_6 ;
V_6 = V_9 -> V_6 - V_5 -> V_8 ;
if ( V_6 < V_21 || V_6 > V_22 ) {
if ( V_6 >= 0 && V_6 < V_23 )
return 0 ;
else
return - V_24 ;
}
V_6 -= V_21 ;
switch ( type ) {
case V_25 :
V_5 -> V_12 [ V_6 ] = 0x10000 | V_14 ;
V_5 -> V_26 [ V_6 ] = false ;
break;
case V_27 :
V_5 -> V_12 [ V_6 ] = 0x10000 | V_15 ;
V_5 -> V_26 [ V_6 ] = false ;
break;
case V_28 :
V_5 -> V_12 [ V_6 ] = 0x10000 ;
V_5 -> V_26 [ V_6 ] = false ;
break;
case V_29 :
V_5 -> V_12 [ V_6 ] = 0x10000 | V_15 ;
V_5 -> V_26 [ V_6 ] = true ;
break;
default:
return - V_24 ;
}
return 0 ;
}
static T_1 F_15 ( int V_6 , void * V_9 )
{
struct V_5 * V_5 = V_9 ;
unsigned int V_11 ;
int V_30 , V_31 , V_32 ;
int V_33 [ V_34 ] = { 0 } ;
int V_35 [ V_34 ] = { 0 } ;
int * V_36 ;
V_30 = F_16 ( V_5 , V_37 ) ;
if ( V_30 < 0 ) {
F_17 ( V_5 -> V_18 , L_2 ,
V_30 ) ;
goto V_38;
}
if ( V_30 & V_39 )
F_18 ( V_5 -> V_8 + V_40 ) ;
if ( V_30 & V_41 )
F_18 ( V_5 -> V_8 + V_42 ) ;
V_30 &= ~ ( V_43 | V_44 ) ;
for ( V_11 = 0 ; V_11 < F_7 ( V_7 ) ; V_11 ++ ) {
int V_45 = V_7 [ V_11 ] . V_4 - 1 ;
if ( ! ( V_30 & V_7 [ V_11 ] . V_30 ) )
continue;
V_36 = & V_33 [ V_45 ] ;
if ( ! V_35 [ V_45 ] ) {
V_31 = F_1 ( & V_7 [ V_11 ] ) ;
* V_36 = F_16 ( V_5 , V_31 ) ;
if ( * V_36 < 0 ) {
F_17 ( V_5 -> V_18 ,
L_3 ,
* V_36 ) ;
goto V_38;
}
V_35 [ V_45 ] = 1 ;
* V_36 &= ~ V_5 -> V_16 [ V_45 ] ;
F_10 ( V_5 , V_31 , * V_36 ) ;
}
if ( * V_36 & V_7 [ V_11 ] . V_20 )
F_18 ( V_5 -> V_8 + V_11 ) ;
if ( V_30 == V_46 &&
V_5 -> V_26 [ V_11 - V_21 ] ) {
V_32 = F_16 ( V_5 , V_47 ) ;
while ( V_32 & 1 << ( V_11 - V_21 ) ) {
F_18 ( V_5 -> V_8 + V_11 ) ;
V_32 = F_16 ( V_5 ,
V_47 ) ;
}
}
}
V_38:
return V_48 ;
}
int F_19 ( struct V_5 * V_5 , int V_6 )
{
struct V_49 * V_50 = V_5 -> V_18 -> V_51 ;
int V_11 , V_52 , V_32 ;
F_20 ( & V_5 -> V_10 ) ;
for ( V_11 = 0 ; V_11 < F_7 ( V_5 -> V_16 ) ; V_11 ++ ) {
V_5 -> V_16 [ V_11 ] = 0xffff ;
V_5 -> V_17 [ V_11 ] = 0xffff ;
F_10 ( V_5 , V_19 + V_11 ,
0xffff ) ;
}
if ( ! V_50 || ! V_50 -> V_8 )
V_5 -> V_8 = - 1 ;
else
V_5 -> V_8 = V_50 -> V_8 ;
V_5 -> V_8 = F_21 ( V_5 -> V_8 , 0 ,
V_23 , 0 ) ;
if ( V_5 -> V_8 < 0 ) {
F_22 ( V_5 -> V_18 , L_4 ,
V_5 -> V_8 ) ;
V_5 -> V_8 = 0 ;
return 0 ;
}
if ( V_50 && V_50 -> V_53 )
V_11 = 0 ;
else
V_11 = V_54 ;
F_8 ( V_5 , V_55 ,
V_54 , V_11 ) ;
V_32 = F_23 ( V_6 ) ;
if ( V_32 != 0 ) {
F_22 ( V_5 -> V_18 , L_5 ,
V_32 ) ;
}
V_5 -> V_6 = V_6 ;
for ( V_52 = V_5 -> V_8 ;
V_52 < F_7 ( V_7 ) + V_5 -> V_8 ;
V_52 ++ ) {
F_24 ( V_52 , V_5 ) ;
F_25 ( V_52 , & V_56 ,
V_57 ) ;
F_26 ( V_52 , 1 ) ;
#ifdef F_27
F_28 ( V_52 , V_58 ) ;
#else
F_29 ( V_52 ) ;
#endif
}
if ( V_6 ) {
V_32 = F_30 ( V_6 , NULL , F_15 ,
V_59 | V_60 ,
L_6 , V_5 ) ;
if ( V_32 != 0 ) {
F_17 ( V_5 -> V_18 , L_7 ,
V_6 , V_32 ) ;
return V_32 ;
}
} else {
F_22 ( V_5 -> V_18 ,
L_8 ) ;
}
F_10 ( V_5 , V_61 , 0 ) ;
return 0 ;
}
void F_31 ( struct V_5 * V_5 )
{
if ( V_5 -> V_6 )
F_32 ( V_5 -> V_6 , V_5 ) ;
}
