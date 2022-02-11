static struct V_1 * F_1 ( struct V_2 * V_3 ,
enum V_4 V_5 )
{
switch ( V_5 ) {
case V_6 ... V_7 :
return V_3 -> V_1 ;
case V_8 ... V_9 :
return V_3 -> V_10 ;
default:
return F_2 ( - V_11 ) ;
}
}
static void F_3 ( struct V_12 * V_13 )
{
struct V_2 * V_3 = F_4 ( V_13 -> V_14 ) ;
F_5 ( & V_3 -> V_15 ) ;
}
static void F_6 ( struct V_12 * V_13 )
{
struct V_2 * V_3 = F_4 ( V_13 -> V_14 ) ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_17 ; V_16 ++ ) {
T_1 V_18 = V_19 [ V_16 ] ;
struct V_1 * V_20 = F_1 ( V_3 , V_16 ) ;
if ( V_18 == V_21 ||
F_7 ( V_20 ) )
continue;
V_3 -> V_22 [ V_16 ] = V_3 -> V_23 [ V_16 ] ;
F_8 ( V_20 , V_19 [ V_16 ] ,
V_3 -> V_23 [ V_16 ] ) ;
}
F_9 ( & V_3 -> V_15 ) ;
}
static const inline struct V_24 *
F_10 ( struct V_2 * V_3 , int V_14 )
{
return & V_25 [ V_14 ] ;
}
static void F_11 ( struct V_12 * V_13 )
{
struct V_2 * V_3 = F_4 ( V_13 -> V_14 ) ;
const struct V_24 * V_12 =
F_10 ( V_3 , V_13 -> V_14 ) ;
if ( V_12 -> V_26 >= V_17 )
return;
if ( V_12 -> V_26 >= V_8 && V_12 -> V_26 <= V_9 )
V_3 -> V_23 [ V_12 -> V_26 ] &= ~ V_12 -> V_27 ;
else
V_3 -> V_23 [ V_12 -> V_26 ] |= V_12 -> V_27 ;
}
static void F_12 ( struct V_12 * V_13 )
{
struct V_2 * V_3 = F_4 ( V_13 -> V_14 ) ;
const struct V_24 * V_12 =
F_10 ( V_3 , V_13 -> V_14 ) ;
if ( V_12 -> V_26 >= V_17 )
return;
if ( V_12 -> V_26 >= V_8 && V_12 -> V_26 <= V_9 )
V_3 -> V_23 [ V_12 -> V_26 ] |= V_12 -> V_27 ;
else
V_3 -> V_23 [ V_12 -> V_26 ] &= ~ V_12 -> V_27 ;
}
static T_2 F_13 ( int V_14 , void * V_13 )
{
struct V_2 * V_3 = V_13 ;
T_1 V_28 [ V_17 ] = {} ;
T_1 V_29 ;
int V_30 ;
int V_16 , V_31 ;
V_30 = F_14 ( V_3 -> V_1 , V_32 ,
& V_29 ) ;
if ( V_30 < 0 ) {
F_15 ( V_3 -> V_33 , L_1 ,
V_30 ) ;
return V_34 ;
}
if ( V_29 & V_35 )
V_30 = F_14 ( V_3 -> V_1 , V_36 ,
& V_28 [ V_7 ] ) ;
if ( V_29 & V_37 )
V_30 = F_14 ( V_3 -> V_1 ,
V_38 , & V_28 [ V_39 ] ) ;
if ( V_29 & V_40 )
V_30 = F_14 ( V_3 -> V_1 ,
V_41 , & V_28 [ V_6 ] ) ;
if ( V_29 & V_42 )
F_16 ( V_3 -> V_10 , V_43 ,
V_44 , & V_28 [ V_8 ] ) ;
for ( V_16 = 0 ; V_16 < V_17 ; V_16 ++ ) {
if ( V_16 >= V_8 && V_16 <= V_9 )
V_28 [ V_16 ] &= V_3 -> V_23 [ V_16 ] ;
else
V_28 [ V_16 ] &= ~ V_3 -> V_23 [ V_16 ] ;
}
for ( V_16 = 0 ; V_16 < V_45 ; V_16 ++ ) {
if ( V_28 [ V_25 [ V_16 ] . V_26 ] & V_25 [ V_16 ] . V_27 ) {
V_31 = F_17 ( V_3 -> V_46 , V_16 ) ;
if ( V_31 )
F_18 ( V_31 ) ;
}
}
return V_47 ;
}
int F_19 ( struct V_2 * V_3 )
{
if ( V_3 -> V_14 )
F_13 ( 0 , V_3 ) ;
return 0 ;
}
static int F_20 ( struct V_46 * V_48 , unsigned int V_14 ,
T_3 V_49 )
{
struct V_2 * V_3 = V_48 -> V_50 ;
F_21 ( V_14 , V_3 ) ;
F_22 ( V_14 , & V_51 , V_52 ) ;
F_23 ( V_14 , 1 ) ;
#ifdef F_24
F_25 ( V_14 , V_53 ) ;
#else
F_26 ( V_14 ) ;
#endif
return 0 ;
}
int F_27 ( struct V_2 * V_3 )
{
struct V_46 * V_54 ;
int V_16 ;
int V_30 = 0 ;
T_1 V_55 ;
F_28 ( & V_3 -> V_15 ) ;
for ( V_16 = 0 ; V_16 < V_17 ; V_16 ++ ) {
struct V_1 * V_20 ;
if ( V_16 >= V_8 && V_16 <= V_9 ) {
V_3 -> V_23 [ V_16 ] = 0x00 ;
V_3 -> V_22 [ V_16 ] = 0x00 ;
} else {
V_3 -> V_23 [ V_16 ] = 0xff ;
V_3 -> V_22 [ V_16 ] = 0xff ;
}
V_20 = F_1 ( V_3 , V_16 ) ;
if ( F_7 ( V_20 ) )
continue;
if ( V_19 [ V_16 ] == V_21 )
continue;
if ( V_16 >= V_8 && V_16 <= V_9 )
F_8 ( V_20 , V_19 [ V_16 ] , 0x00 ) ;
else
F_8 ( V_20 , V_19 [ V_16 ] , 0xff ) ;
}
V_54 = F_29 ( NULL , V_45 ,
& V_56 , V_3 ) ;
if ( ! V_54 ) {
F_15 ( V_3 -> V_33 , L_2 ) ;
V_30 = - V_57 ;
goto V_58;
}
V_3 -> V_46 = V_54 ;
V_30 = F_14 ( V_3 -> V_1 ,
V_59 , & V_55 ) ;
if ( V_30 < 0 ) {
F_15 ( V_3 -> V_33 , L_3 ) ;
goto V_58;
}
V_55 &= ~ ( V_35 ) ;
V_55 &= ~ ( V_40 ) ;
V_55 &= ~ ( V_42 ) ;
V_30 = F_8 ( V_3 -> V_1 ,
V_59 , V_55 ) ;
if ( V_30 < 0 ) {
F_15 ( V_3 -> V_33 , L_4 ) ;
goto V_58;
}
V_30 = F_30 ( V_3 -> V_14 , NULL , F_13 ,
V_60 | V_61 ,
L_5 , V_3 ) ;
if ( V_30 )
F_15 ( V_3 -> V_33 , L_6 ,
V_3 -> V_14 , V_30 ) ;
V_58:
return V_30 ;
}
void F_31 ( struct V_2 * V_3 )
{
if ( V_3 -> V_14 )
F_32 ( V_3 -> V_14 , V_3 ) ;
}
