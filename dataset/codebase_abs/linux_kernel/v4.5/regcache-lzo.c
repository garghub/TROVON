static int F_1 ( struct V_1 * V_2 )
{
return V_3 ;
}
static int F_2 ( struct V_4 * V_5 )
{
V_5 -> V_6 = F_3 ( V_7 , V_8 ) ;
if ( ! V_5 -> V_6 )
return - V_9 ;
return 0 ;
}
static int F_4 ( struct V_4 * V_5 )
{
T_1 V_10 ;
int V_11 ;
V_11 = F_5 ( V_5 -> V_12 , V_5 -> V_13 ,
V_5 -> V_14 , & V_10 , V_5 -> V_6 ) ;
if ( V_11 != V_15 || V_10 > V_5 -> V_16 )
return - V_17 ;
V_5 -> V_16 = V_10 ;
return 0 ;
}
static int F_6 ( struct V_4 * V_5 )
{
T_1 V_16 ;
int V_11 ;
V_16 = V_5 -> V_16 ;
V_11 = F_7 ( V_5 -> V_12 , V_5 -> V_13 ,
V_5 -> V_14 , & V_16 ) ;
if ( V_11 != V_15 || V_16 != V_5 -> V_16 )
return - V_17 ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_4 * V_5 )
{
int V_11 ;
V_5 -> V_16 = F_9 ( V_18 ) ;
V_5 -> V_14 = F_3 ( V_5 -> V_16 , V_8 ) ;
if ( ! V_5 -> V_14 ) {
V_5 -> V_16 = 0 ;
return - V_9 ;
}
V_11 = F_4 ( V_5 ) ;
if ( V_11 < 0 )
return V_11 ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 ,
struct V_4 * V_5 )
{
int V_11 ;
V_5 -> V_16 = V_5 -> V_19 ;
V_5 -> V_14 = F_3 ( V_5 -> V_16 , V_8 ) ;
if ( ! V_5 -> V_14 ) {
V_5 -> V_16 = 0 ;
return - V_9 ;
}
V_11 = F_6 ( V_5 ) ;
if ( V_11 < 0 )
return V_11 ;
return 0 ;
}
static inline int F_11 ( struct V_1 * V_2 ,
unsigned int V_20 )
{
return ( ( V_20 / V_2 -> V_21 ) * V_2 -> V_22 ) /
F_12 ( V_2 -> V_23 ,
F_1 ( V_2 ) ) ;
}
static inline int F_13 ( struct V_1 * V_2 ,
unsigned int V_20 )
{
return ( V_20 / V_2 -> V_21 ) %
( F_12 ( V_2 -> V_23 ,
F_1 ( V_2 ) ) /
V_2 -> V_22 ) ;
}
static inline int F_14 ( struct V_1 * V_2 )
{
return F_12 ( V_2 -> V_23 ,
F_1 ( V_2 ) ) ;
}
static int F_15 ( struct V_1 * V_2 )
{
struct V_4 * * V_24 ;
T_1 V_25 ;
int V_11 , V_26 , V_27 , V_28 ;
const char * V_29 , * V_30 ;
unsigned long * V_31 ;
V_11 = 0 ;
V_28 = F_1 ( V_2 ) ;
V_2 -> V_32 = F_16 ( V_28 , sizeof( * V_24 ) ,
V_8 ) ;
if ( ! V_2 -> V_32 )
return - V_9 ;
V_24 = V_2 -> V_32 ;
V_25 = V_2 -> V_33 ;
V_31 = F_17 ( F_18 ( V_25 ) , sizeof( long ) ,
V_8 ) ;
if ( ! V_31 ) {
V_11 = - V_9 ;
goto V_34;
}
F_19 ( V_31 , V_25 ) ;
for ( V_26 = 0 ; V_26 < V_28 ; V_26 ++ ) {
V_24 [ V_26 ] = F_20 ( sizeof ** V_24 ,
V_8 ) ;
if ( ! V_24 [ V_26 ] ) {
F_21 ( V_31 ) ;
V_11 = - V_9 ;
goto V_34;
}
V_24 [ V_26 ] -> V_31 = V_31 ;
V_24 [ V_26 ] -> V_35 = V_25 ;
V_11 = F_2 ( V_24 [ V_26 ] ) ;
if ( V_11 < 0 )
goto V_34;
}
V_27 = F_14 ( V_2 ) ;
V_29 = V_2 -> V_36 ;
V_30 = V_2 -> V_36 + V_2 -> V_23 ;
for ( V_26 = 0 ; V_26 < V_28 ; V_26 ++ , V_29 += V_27 ) {
V_24 [ V_26 ] -> V_12 = V_29 ;
if ( V_29 + V_27 > V_30 )
V_24 [ V_26 ] -> V_13 = V_30 - V_29 ;
else
V_24 [ V_26 ] -> V_13 = V_27 ;
V_11 = F_8 ( V_2 ,
V_24 [ V_26 ] ) ;
if ( V_11 < 0 )
goto V_34;
V_24 [ V_26 ] -> V_19 =
V_24 [ V_26 ] -> V_13 ;
}
return 0 ;
V_34:
F_22 ( V_2 ) ;
return V_11 ;
}
static int F_22 ( struct V_1 * V_2 )
{
struct V_4 * * V_24 ;
int V_26 , V_28 ;
V_24 = V_2 -> V_32 ;
if ( ! V_24 )
return 0 ;
V_28 = F_1 ( V_2 ) ;
if ( V_24 [ 0 ] )
F_21 ( V_24 [ 0 ] -> V_31 ) ;
for ( V_26 = 0 ; V_26 < V_28 ; V_26 ++ ) {
if ( V_24 [ V_26 ] ) {
F_21 ( V_24 [ V_26 ] -> V_6 ) ;
F_21 ( V_24 [ V_26 ] -> V_14 ) ;
}
F_21 ( V_24 [ V_26 ] ) ;
}
F_21 ( V_24 ) ;
V_2 -> V_32 = NULL ;
return 0 ;
}
static int F_23 ( struct V_1 * V_2 ,
unsigned int V_20 , unsigned int * V_37 )
{
struct V_4 * V_38 , * * V_24 ;
int V_11 , V_39 , V_40 ;
T_1 V_27 , V_41 ;
void * V_42 ;
V_39 = F_11 ( V_2 , V_20 ) ;
V_40 = F_13 ( V_2 , V_20 ) ;
V_27 = F_14 ( V_2 ) ;
V_24 = V_2 -> V_32 ;
V_38 = V_24 [ V_39 ] ;
V_42 = V_38 -> V_14 ;
V_41 = V_38 -> V_16 ;
V_38 -> V_12 = V_38 -> V_14 ;
V_38 -> V_13 = V_38 -> V_16 ;
V_11 = F_10 ( V_2 , V_38 ) ;
if ( V_11 >= 0 )
* V_37 = F_24 ( V_2 , V_38 -> V_14 , V_40 ) ;
F_21 ( V_38 -> V_14 ) ;
V_38 -> V_14 = V_42 ;
V_38 -> V_16 = V_41 ;
return V_11 ;
}
static int F_25 ( struct V_1 * V_2 ,
unsigned int V_20 , unsigned int V_37 )
{
struct V_4 * V_38 , * * V_24 ;
int V_11 , V_39 , V_40 ;
T_1 V_27 , V_41 ;
void * V_42 ;
V_39 = F_11 ( V_2 , V_20 ) ;
V_40 = F_13 ( V_2 , V_20 ) ;
V_27 = F_14 ( V_2 ) ;
V_24 = V_2 -> V_32 ;
V_38 = V_24 [ V_39 ] ;
V_42 = V_38 -> V_14 ;
V_41 = V_38 -> V_16 ;
V_38 -> V_12 = V_38 -> V_14 ;
V_38 -> V_13 = V_38 -> V_16 ;
V_11 = F_10 ( V_2 , V_38 ) ;
if ( V_11 < 0 ) {
F_21 ( V_38 -> V_14 ) ;
goto V_43;
}
if ( F_26 ( V_2 , V_38 -> V_14 , V_40 , V_37 ) ) {
F_21 ( V_38 -> V_14 ) ;
goto V_43;
}
V_38 -> V_12 = V_38 -> V_14 ;
V_38 -> V_13 = V_38 -> V_16 ;
V_11 = F_8 ( V_2 , V_38 ) ;
if ( V_11 < 0 ) {
F_21 ( V_38 -> V_14 ) ;
F_21 ( V_38 -> V_12 ) ;
goto V_43;
}
F_27 ( V_20 / V_2 -> V_21 , V_38 -> V_31 ) ;
F_21 ( V_42 ) ;
F_21 ( V_38 -> V_12 ) ;
return 0 ;
V_43:
V_38 -> V_14 = V_42 ;
V_38 -> V_16 = V_41 ;
return V_11 ;
}
static int F_28 ( struct V_1 * V_2 , unsigned int V_44 ,
unsigned int V_45 )
{
struct V_4 * * V_24 ;
unsigned int V_46 ;
int V_26 ;
int V_11 ;
V_24 = V_2 -> V_32 ;
V_26 = V_44 ;
F_29 (i, lzo_blocks[0]->sync_bmp,
lzo_blocks[0]->sync_bmp_nbits) {
if ( V_26 > V_45 )
continue;
V_11 = F_30 ( V_2 , V_26 , & V_46 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_31 ( V_2 , V_26 ) ;
if ( V_11 > 0 && V_46 == V_2 -> V_47 [ V_11 ] . V_48 )
continue;
V_2 -> V_49 = true ;
V_11 = F_32 ( V_2 , V_26 , V_46 ) ;
V_2 -> V_49 = false ;
if ( V_11 )
return V_11 ;
F_33 ( V_2 -> V_50 , L_1 ,
V_26 , V_46 ) ;
}
return 0 ;
}
