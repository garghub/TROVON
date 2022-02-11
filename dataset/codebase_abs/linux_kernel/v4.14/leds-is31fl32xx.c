static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
int V_5 ;
F_2 ( & V_2 -> V_6 -> V_7 , L_1 , V_3 , V_4 ) ;
V_5 = F_3 ( V_2 -> V_6 , V_3 , V_4 ) ;
if ( V_5 ) {
F_4 ( & V_2 -> V_6 -> V_7 ,
L_2 ,
V_3 , V_5 ) ;
}
return V_5 ;
}
static int F_5 ( struct V_1 * V_2 )
{
unsigned int V_8 ;
int V_5 ;
V_5 = F_1 ( V_2 , V_9 ,
V_10 ) ;
if ( V_5 )
return V_5 ;
for ( V_8 = 0 ; V_8 < V_2 -> V_11 -> V_12 ; V_8 ++ ) {
V_5 = F_1 ( V_2 , V_2 -> V_11 -> V_13 + V_8 ,
0x00 ) ;
if ( V_5 )
return V_5 ;
}
V_5 = F_1 ( V_2 , V_2 -> V_11 -> V_14 , 0 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_1 ( V_2 , V_15 , 0x00 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_1 ( V_2 , V_16 , 0x00 ) ;
if ( V_5 )
return V_5 ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 ,
bool V_17 )
{
T_1 V_18 = V_17 ? V_10 :
V_19 ;
return F_1 ( V_2 , V_9 , V_18 ) ;
}
static int F_7 ( struct V_20 * V_21 ,
enum V_22 V_23 )
{
const struct V_24 * V_25 =
F_8 ( V_21 , struct V_24 , V_26 ) ;
const struct V_27 * V_11 = V_25 -> V_2 -> V_11 ;
T_1 V_28 ;
int V_5 ;
F_2 ( V_21 -> V_7 , L_3 , V_29 , V_23 ) ;
if ( V_11 -> V_30 )
V_28 = V_11 -> V_12 - V_25 -> V_31 ;
else
V_28 = V_25 -> V_31 - 1 ;
V_5 = F_1 ( V_25 -> V_2 ,
V_11 -> V_13 + V_28 ,
V_23 ) ;
if ( V_5 )
return V_5 ;
return F_1 ( V_25 -> V_2 , V_11 -> V_14 , 0 ) ;
}
static int F_9 ( struct V_1 * V_2 )
{
const struct V_27 * V_11 = V_2 -> V_11 ;
int V_5 ;
if ( V_11 -> V_32 != V_33 ) {
V_5 = F_1 ( V_2 , V_11 -> V_32 , 0 ) ;
if ( V_5 )
return V_5 ;
}
if ( V_11 -> V_34 )
return V_11 -> V_34 ( V_2 ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 ,
bool V_17 )
{
const struct V_27 * V_11 = V_2 -> V_11 ;
int V_5 ;
if ( V_11 -> V_35 != V_33 ) {
T_1 V_18 = V_17 ? V_36 :
V_37 ;
V_5 = F_1 ( V_2 , V_11 -> V_35 , V_18 ) ;
if ( V_5 )
return V_5 ;
}
if ( V_11 -> V_38 )
return V_11 -> V_38 ( V_2 , V_17 ) ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 )
{
const struct V_27 * V_11 = V_2 -> V_11 ;
int V_5 ;
V_5 = F_9 ( V_2 ) ;
if ( V_5 )
return V_5 ;
if ( V_11 -> V_39 != V_33 ) {
T_1 V_18 =
F_12 ( V_11 -> V_40 - 1 , 0 ) ;
T_1 V_41 = V_11 -> V_12 /
V_11 -> V_40 ;
int V_8 ;
for ( V_8 = 0 ; V_8 < V_41 ; V_8 ++ ) {
V_5 = F_1 ( V_2 ,
V_11 -> V_39 + V_8 ,
V_18 ) ;
if ( V_5 )
return V_5 ;
}
}
V_5 = F_10 ( V_2 , false ) ;
if ( V_5 )
return V_5 ;
if ( V_11 -> V_42 != V_33 ) {
V_5 = F_1 ( V_2 , V_11 -> V_42 , 0x00 ) ;
if ( V_5 )
return V_5 ;
}
return 0 ;
}
static inline T_2 F_13 ( int V_43 )
{
return sizeof( struct V_1 ) +
( sizeof( struct V_24 ) * V_43 ) ;
}
static int F_14 ( const struct V_44 * V_7 ,
const struct V_45 * V_46 ,
struct V_24 * V_25 )
{
struct V_20 * V_26 = & V_25 -> V_26 ;
int V_5 = 0 ;
T_3 V_3 ;
if ( F_15 ( V_46 , L_4 , & V_26 -> V_47 ) )
V_26 -> V_47 = V_46 -> V_47 ;
V_5 = F_16 ( V_46 , L_5 , & V_3 ) ;
if ( V_5 || V_3 < 1 || V_3 > V_25 -> V_2 -> V_11 -> V_12 ) {
F_4 ( V_7 ,
L_6 ,
V_46 ) ;
return - V_48 ;
}
V_25 -> V_31 = V_3 ;
F_15 ( V_46 , L_7 ,
& V_26 -> V_49 ) ;
V_26 -> V_50 = F_7 ;
return 0 ;
}
static struct V_24 * F_17 (
struct V_1 * V_2 ,
T_1 V_31 )
{
T_2 V_8 ;
for ( V_8 = 0 ; V_8 < V_2 -> V_43 ; V_8 ++ ) {
if ( V_2 -> V_51 [ V_8 ] . V_31 == V_31 )
return & V_2 -> V_51 [ V_8 ] ;
}
return NULL ;
}
static int F_18 ( struct V_44 * V_7 ,
struct V_1 * V_2 )
{
struct V_45 * V_46 ;
int V_5 = 0 ;
F_19 (dev->of_node, child) {
struct V_24 * V_25 =
& V_2 -> V_51 [ V_2 -> V_43 ] ;
const struct V_24 * V_52 ;
V_25 -> V_2 = V_2 ;
V_5 = F_14 ( V_7 , V_46 , V_25 ) ;
if ( V_5 )
goto V_53;
V_52 = F_17 ( V_2 ,
V_25 -> V_31 ) ;
if ( V_52 ) {
F_4 ( V_7 ,
L_8 ,
V_25 -> V_26 . V_47 ,
V_52 -> V_26 . V_47 ,
V_25 -> V_31 ) ;
goto V_53;
}
V_5 = F_20 ( V_7 , & V_25 -> V_26 ) ;
if ( V_5 ) {
F_4 ( V_7 , L_9 ,
V_25 -> V_26 . V_47 , V_5 ) ;
goto V_53;
}
V_2 -> V_43 ++ ;
}
return 0 ;
V_53:
F_21 ( V_46 ) ;
return V_5 ;
}
static int F_22 ( struct V_54 * V_6 ,
const struct V_55 * V_56 )
{
const struct V_27 * V_11 ;
const struct V_57 * V_58 ;
struct V_44 * V_7 = & V_6 -> V_7 ;
struct V_1 * V_2 ;
int V_59 ;
int V_5 = 0 ;
V_58 = F_23 ( V_60 , V_7 ) ;
if ( ! V_58 )
return - V_48 ;
V_11 = V_58 -> V_61 ;
V_59 = F_24 ( V_7 -> V_62 ) ;
if ( ! V_59 )
return - V_48 ;
V_2 = F_25 ( V_7 , F_13 ( V_59 ) ,
V_63 ) ;
if ( ! V_2 )
return - V_64 ;
V_2 -> V_6 = V_6 ;
V_2 -> V_11 = V_11 ;
F_26 ( V_6 , V_2 ) ;
V_5 = F_11 ( V_2 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_18 ( V_7 , V_2 ) ;
if ( V_5 )
return V_5 ;
return 0 ;
}
static int F_27 ( struct V_54 * V_6 )
{
struct V_1 * V_2 = F_28 ( V_6 ) ;
return F_9 ( V_2 ) ;
}
