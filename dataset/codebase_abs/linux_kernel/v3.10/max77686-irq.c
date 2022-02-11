static struct V_1 * F_1 ( struct V_2 * V_3 ,
enum V_4 V_5 )
{
switch ( V_5 ) {
case V_6 ... V_7 :
return V_3 -> V_1 ;
case V_8 :
return V_3 -> V_9 ;
default:
return F_2 ( - V_10 ) ;
}
}
static void F_3 ( struct V_11 * V_12 )
{
struct V_2 * V_3 = F_4 ( V_12 -> V_13 ) ;
if ( V_14 & V_15 )
F_5 ( L_1 , V_16 ) ;
F_6 ( & V_3 -> V_17 ) ;
}
static void F_7 ( struct V_11 * V_12 )
{
struct V_2 * V_3 = F_4 ( V_12 -> V_13 ) ;
int V_18 ;
for ( V_18 = 0 ; V_18 < V_19 ; V_18 ++ ) {
T_1 V_20 = V_21 [ V_18 ] ;
struct V_1 * V_22 = F_1 ( V_3 , V_18 ) ;
if ( V_14 & V_15 )
F_8 ( L_2 ,
V_16 , V_18 , V_20 , V_3 -> V_23 [ V_18 ] ) ;
if ( V_20 == V_24 ||
F_9 ( V_22 ) )
continue;
V_3 -> V_25 [ V_18 ] = V_3 -> V_23 [ V_18 ] ;
F_10 ( V_22 , V_21 [ V_18 ] ,
V_3 -> V_23 [ V_18 ] ) ;
}
F_11 ( & V_3 -> V_17 ) ;
}
static const inline struct V_26 * F_12 ( int V_13 )
{
struct V_11 * V_12 = F_13 ( V_13 ) ;
return & V_27 [ V_12 -> V_28 ] ;
}
static void F_14 ( struct V_11 * V_12 )
{
struct V_2 * V_3 = F_4 ( V_12 -> V_13 ) ;
const struct V_26 * V_11 = F_12 ( V_12 -> V_13 ) ;
V_3 -> V_23 [ V_11 -> V_29 ] |= V_11 -> V_30 ;
if ( V_14 & V_15 )
F_5 ( L_3 ,
V_16 , V_11 -> V_29 ,
V_3 -> V_23 [ V_11 -> V_29 ] ) ;
}
static void F_15 ( struct V_11 * V_12 )
{
struct V_2 * V_3 = F_4 ( V_12 -> V_13 ) ;
const struct V_26 * V_11 = F_12 ( V_12 -> V_13 ) ;
V_3 -> V_23 [ V_11 -> V_29 ] &= ~ V_11 -> V_30 ;
if ( V_14 & V_15 )
F_5 ( L_3 ,
V_16 , V_11 -> V_29 ,
V_3 -> V_23 [ V_11 -> V_29 ] ) ;
}
static T_2 F_16 ( int V_13 , void * V_12 )
{
struct V_2 * V_3 = V_12 ;
unsigned int V_31 [ V_19 ] = {} ;
unsigned int V_32 ;
int V_33 ;
int V_18 , V_34 ;
V_33 = F_17 ( V_3 -> V_1 , V_35 , & V_32 ) ;
if ( V_33 < 0 ) {
F_18 ( V_3 -> V_36 , L_4 ,
V_33 ) ;
return V_37 ;
}
if ( V_14 & V_38 )
F_5 ( L_5 , V_16 , V_32 ) ;
if ( V_32 == V_39 ) {
V_33 = F_19 ( V_3 -> V_1 ,
V_40 , V_31 , 2 ) ;
if ( V_33 < 0 ) {
F_18 ( V_3 -> V_36 , L_4 ,
V_33 ) ;
return V_37 ;
}
if ( V_14 & V_38 )
F_5 ( L_6 , V_16 ,
V_31 [ V_6 ] , V_31 [ V_7 ] ) ;
}
if ( V_32 & V_41 ) {
V_33 = F_17 ( V_3 -> V_9 ,
V_42 , & V_31 [ V_8 ] ) ;
if ( V_33 < 0 ) {
F_18 ( V_3 -> V_36 , L_4 ,
V_33 ) ;
return V_37 ;
}
if ( V_14 & V_38 )
F_5 ( L_7 , V_16 ,
V_31 [ V_8 ] ) ;
}
for ( V_18 = 0 ; V_18 < V_19 ; V_18 ++ )
V_31 [ V_18 ] &= ~ V_3 -> V_23 [ V_18 ] ;
for ( V_18 = 0 ; V_18 < V_43 ; V_18 ++ ) {
if ( V_31 [ V_27 [ V_18 ] . V_29 ] & V_27 [ V_18 ] . V_30 ) {
V_34 = F_20 ( V_3 -> V_44 , V_18 ) ;
if ( V_34 )
F_21 ( V_34 ) ;
}
}
return V_45 ;
}
static int F_22 ( struct V_44 * V_46 , unsigned int V_13 ,
T_3 V_47 )
{
struct V_2 * V_3 = V_46 -> V_48 ;
F_23 ( V_13 , V_3 ) ;
F_24 ( V_13 , & V_49 , V_50 ) ;
F_25 ( V_13 , 1 ) ;
#ifdef F_26
F_27 ( V_13 , V_51 ) ;
#else
F_28 ( V_13 ) ;
#endif
return 0 ;
}
int F_29 ( struct V_2 * V_3 )
{
struct V_44 * V_52 ;
int V_18 ;
int V_33 ;
int V_53 ;
struct V_1 * V_22 ;
F_30 ( & V_3 -> V_17 ) ;
if ( V_3 -> V_54 && ! V_3 -> V_13 ) {
V_3 -> V_13 = F_31 ( V_3 -> V_54 ) ;
if ( V_14 & V_38 ) {
V_33 = F_32 ( V_3 -> V_54 , L_8 ) ;
if ( V_33 < 0 ) {
F_18 ( V_3 -> V_36 ,
L_9
L_10 , V_3 -> V_54 , V_33 ) ;
return V_37 ;
}
F_33 ( V_3 -> V_54 ) ;
V_53 = F_34 ( V_3 -> V_54 ) ;
F_35 ( V_3 -> V_54 ) ;
F_5 ( L_11 , V_16 , V_53 ) ;
}
}
if ( ! V_3 -> V_13 ) {
F_18 ( V_3 -> V_36 , L_12 ) ;
return - V_55 ;
}
for ( V_18 = 0 ; V_18 < V_19 ; V_18 ++ ) {
V_3 -> V_23 [ V_18 ] = 0xff ;
V_3 -> V_25 [ V_18 ] = 0xff ;
V_22 = F_1 ( V_3 , V_18 ) ;
if ( F_9 ( V_22 ) )
continue;
if ( V_21 [ V_18 ] == V_24 )
continue;
F_10 ( V_22 , V_21 [ V_18 ] , 0xff ) ;
}
V_52 = F_36 ( NULL , V_43 ,
& V_56 , V_3 ) ;
if ( ! V_52 ) {
F_18 ( V_3 -> V_36 , L_13 ) ;
return - V_55 ;
}
V_3 -> V_44 = V_52 ;
V_33 = F_37 ( V_3 -> V_13 , NULL , F_16 ,
V_57 | V_58 ,
L_14 , V_3 ) ;
if ( V_33 )
F_18 ( V_3 -> V_36 , L_15 ,
V_3 -> V_13 , V_33 ) ;
if ( V_14 & V_59 )
F_5 ( L_16 , V_16 ) ;
return 0 ;
}
void F_38 ( struct V_2 * V_3 )
{
if ( V_3 -> V_13 )
F_39 ( V_3 -> V_13 , V_3 ) ;
}
