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
struct V_12 * V_13 = F_11 ( V_14 ) ;
return & V_25 [ V_13 -> V_26 ] ;
}
static void F_12 ( struct V_12 * V_13 )
{
struct V_2 * V_3 = F_4 ( V_13 -> V_14 ) ;
const struct V_24 * V_12 =
F_10 ( V_3 , V_13 -> V_14 ) ;
if ( V_12 -> V_27 >= V_17 )
return;
if ( V_12 -> V_27 >= V_8 && V_12 -> V_27 <= V_9 )
V_3 -> V_23 [ V_12 -> V_27 ] &= ~ V_12 -> V_28 ;
else
V_3 -> V_23 [ V_12 -> V_27 ] |= V_12 -> V_28 ;
}
static void F_13 ( struct V_12 * V_13 )
{
struct V_2 * V_3 = F_4 ( V_13 -> V_14 ) ;
const struct V_24 * V_12 =
F_10 ( V_3 , V_13 -> V_14 ) ;
if ( V_12 -> V_27 >= V_17 )
return;
if ( V_12 -> V_27 >= V_8 && V_12 -> V_27 <= V_9 )
V_3 -> V_23 [ V_12 -> V_27 ] |= V_12 -> V_28 ;
else
V_3 -> V_23 [ V_12 -> V_27 ] &= ~ V_12 -> V_28 ;
}
static T_2 F_14 ( int V_14 , void * V_13 )
{
struct V_2 * V_3 = V_13 ;
T_1 V_29 [ V_17 ] = {} ;
T_1 V_30 ;
int V_31 ;
int V_16 , V_32 ;
V_31 = F_15 ( V_3 -> V_1 , V_33 ,
& V_30 ) ;
if ( V_31 < 0 ) {
F_16 ( V_3 -> V_34 , L_1 ,
V_31 ) ;
return V_35 ;
}
if ( V_30 & V_36 )
V_31 = F_15 ( V_3 -> V_1 , V_37 ,
& V_29 [ V_7 ] ) ;
if ( V_30 & V_38 )
V_31 = F_15 ( V_3 -> V_1 ,
V_39 , & V_29 [ V_40 ] ) ;
if ( V_30 & V_41 )
V_31 = F_15 ( V_3 -> V_1 ,
V_42 , & V_29 [ V_6 ] ) ;
if ( V_30 & V_43 )
F_17 ( V_3 -> V_10 , V_44 ,
V_45 , & V_29 [ V_8 ] ) ;
for ( V_16 = 0 ; V_16 < V_17 ; V_16 ++ ) {
if ( V_16 >= V_8 && V_16 <= V_9 )
V_29 [ V_16 ] &= V_3 -> V_23 [ V_16 ] ;
else
V_29 [ V_16 ] &= ~ V_3 -> V_23 [ V_16 ] ;
}
for ( V_16 = 0 ; V_16 < V_46 ; V_16 ++ ) {
if ( V_29 [ V_25 [ V_16 ] . V_27 ] & V_25 [ V_16 ] . V_28 ) {
V_32 = F_18 ( V_3 -> V_47 , V_16 ) ;
if ( V_32 )
F_19 ( V_32 ) ;
}
}
return V_48 ;
}
int F_20 ( struct V_2 * V_3 )
{
if ( V_3 -> V_14 )
F_14 ( 0 , V_3 ) ;
return 0 ;
}
static int F_21 ( struct V_47 * V_49 , unsigned int V_14 ,
T_3 V_50 )
{
struct V_2 * V_3 = V_49 -> V_51 ;
F_22 ( V_14 , V_3 ) ;
F_23 ( V_14 , & V_52 , V_53 ) ;
F_24 ( V_14 , 1 ) ;
#ifdef F_25
F_26 ( V_14 , V_54 ) ;
#else
F_27 ( V_14 ) ;
#endif
return 0 ;
}
int F_28 ( struct V_2 * V_3 )
{
struct V_47 * V_55 ;
int V_16 ;
int V_31 = 0 ;
T_1 V_56 ;
F_29 ( & V_3 -> V_15 ) ;
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
V_55 = F_30 ( NULL , V_46 ,
& V_57 , V_3 ) ;
if ( ! V_55 ) {
F_16 ( V_3 -> V_34 , L_2 ) ;
V_31 = - V_58 ;
goto V_59;
}
V_3 -> V_47 = V_55 ;
V_31 = F_15 ( V_3 -> V_1 ,
V_60 , & V_56 ) ;
if ( V_31 < 0 ) {
F_16 ( V_3 -> V_34 , L_3 ) ;
goto V_59;
}
V_56 &= ~ ( V_36 ) ;
V_56 &= ~ ( V_41 ) ;
V_56 &= ~ ( V_43 ) ;
V_31 = F_8 ( V_3 -> V_1 ,
V_60 , V_56 ) ;
if ( V_31 < 0 ) {
F_16 ( V_3 -> V_34 , L_4 ) ;
goto V_59;
}
V_31 = F_31 ( V_3 -> V_14 , NULL , F_14 ,
V_61 | V_62 ,
L_5 , V_3 ) ;
if ( V_31 )
F_16 ( V_3 -> V_34 , L_6 ,
V_3 -> V_14 , V_31 ) ;
V_59:
return V_31 ;
}
void F_32 ( struct V_2 * V_3 )
{
if ( V_3 -> V_14 )
F_33 ( V_3 -> V_14 , V_3 ) ;
}
