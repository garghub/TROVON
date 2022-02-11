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
return ( V_20 * V_2 -> V_21 ) /
F_12 ( V_2 -> V_22 ,
F_1 ( V_2 ) ) ;
}
static inline int F_13 ( struct V_1 * V_2 ,
unsigned int V_20 )
{
return V_20 % ( F_12 ( V_2 -> V_22 ,
F_1 ( V_2 ) ) /
V_2 -> V_21 ) ;
}
static inline int F_14 ( struct V_1 * V_2 )
{
return F_12 ( V_2 -> V_22 ,
F_1 ( V_2 ) ) ;
}
static int F_15 ( struct V_1 * V_2 )
{
struct V_4 * * V_23 ;
T_1 V_24 ;
int V_11 , V_25 , V_26 , V_27 ;
const char * V_28 , * V_29 ;
unsigned long * V_30 ;
V_11 = 0 ;
V_27 = F_1 ( V_2 ) ;
V_2 -> V_31 = F_16 ( V_27 * sizeof *V_23 ,
V_8 ) ;
if ( ! V_2 -> V_31 )
return - V_9 ;
V_23 = V_2 -> V_31 ;
V_24 = V_2 -> V_32 ;
V_30 = F_3 ( F_17 ( V_24 ) * sizeof( long ) ,
V_8 ) ;
if ( ! V_30 ) {
V_11 = - V_9 ;
goto V_33;
}
F_18 ( V_30 , V_24 ) ;
for ( V_25 = 0 ; V_25 < V_27 ; V_25 ++ ) {
V_23 [ V_25 ] = F_16 ( sizeof ** V_23 ,
V_8 ) ;
if ( ! V_23 [ V_25 ] ) {
F_19 ( V_30 ) ;
V_11 = - V_9 ;
goto V_33;
}
V_23 [ V_25 ] -> V_30 = V_30 ;
V_23 [ V_25 ] -> V_34 = V_24 ;
V_11 = F_2 ( V_23 [ V_25 ] ) ;
if ( V_11 < 0 )
goto V_33;
}
V_26 = F_14 ( V_2 ) ;
V_28 = V_2 -> V_35 ;
V_29 = V_2 -> V_35 + V_2 -> V_22 ;
for ( V_25 = 0 ; V_25 < V_27 ; V_25 ++ , V_28 += V_26 ) {
V_23 [ V_25 ] -> V_12 = V_28 ;
if ( V_28 + V_26 > V_29 )
V_23 [ V_25 ] -> V_13 = V_29 - V_28 ;
else
V_23 [ V_25 ] -> V_13 = V_26 ;
V_11 = F_8 ( V_2 ,
V_23 [ V_25 ] ) ;
if ( V_11 < 0 )
goto V_33;
V_23 [ V_25 ] -> V_19 =
V_23 [ V_25 ] -> V_13 ;
}
return 0 ;
V_33:
F_20 ( V_2 ) ;
return V_11 ;
}
static int F_20 ( struct V_1 * V_2 )
{
struct V_4 * * V_23 ;
int V_25 , V_27 ;
V_23 = V_2 -> V_31 ;
if ( ! V_23 )
return 0 ;
V_27 = F_1 ( V_2 ) ;
if ( V_23 [ 0 ] )
F_19 ( V_23 [ 0 ] -> V_30 ) ;
for ( V_25 = 0 ; V_25 < V_27 ; V_25 ++ ) {
if ( V_23 [ V_25 ] ) {
F_19 ( V_23 [ V_25 ] -> V_6 ) ;
F_19 ( V_23 [ V_25 ] -> V_14 ) ;
}
F_19 ( V_23 [ V_25 ] ) ;
}
F_19 ( V_23 ) ;
V_2 -> V_31 = NULL ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 ,
unsigned int V_20 , unsigned int * V_36 )
{
struct V_4 * V_37 , * * V_23 ;
int V_11 , V_38 , V_39 ;
T_1 V_26 , V_40 ;
void * V_41 ;
V_38 = F_11 ( V_2 , V_20 ) ;
V_39 = F_13 ( V_2 , V_20 ) ;
V_26 = F_14 ( V_2 ) ;
V_23 = V_2 -> V_31 ;
V_37 = V_23 [ V_38 ] ;
V_41 = V_37 -> V_14 ;
V_40 = V_37 -> V_16 ;
V_37 -> V_12 = V_37 -> V_14 ;
V_37 -> V_13 = V_37 -> V_16 ;
V_11 = F_10 ( V_2 , V_37 ) ;
if ( V_11 >= 0 )
* V_36 = F_22 ( V_37 -> V_14 , V_39 ,
V_2 -> V_21 ) ;
F_19 ( V_37 -> V_14 ) ;
V_37 -> V_14 = V_41 ;
V_37 -> V_16 = V_40 ;
return V_11 ;
}
static int F_23 ( struct V_1 * V_2 ,
unsigned int V_20 , unsigned int V_36 )
{
struct V_4 * V_37 , * * V_23 ;
int V_11 , V_38 , V_39 ;
T_1 V_26 , V_40 ;
void * V_41 ;
V_38 = F_11 ( V_2 , V_20 ) ;
V_39 = F_13 ( V_2 , V_20 ) ;
V_26 = F_14 ( V_2 ) ;
V_23 = V_2 -> V_31 ;
V_37 = V_23 [ V_38 ] ;
V_41 = V_37 -> V_14 ;
V_40 = V_37 -> V_16 ;
V_37 -> V_12 = V_37 -> V_14 ;
V_37 -> V_13 = V_37 -> V_16 ;
V_11 = F_10 ( V_2 , V_37 ) ;
if ( V_11 < 0 ) {
F_19 ( V_37 -> V_14 ) ;
goto V_42;
}
if ( F_24 ( V_37 -> V_14 , V_39 , V_36 ,
V_2 -> V_21 ) ) {
F_19 ( V_37 -> V_14 ) ;
goto V_42;
}
V_37 -> V_12 = V_37 -> V_14 ;
V_37 -> V_13 = V_37 -> V_16 ;
V_11 = F_8 ( V_2 , V_37 ) ;
if ( V_11 < 0 ) {
F_19 ( V_37 -> V_14 ) ;
F_19 ( V_37 -> V_12 ) ;
goto V_42;
}
F_25 ( V_20 , V_37 -> V_30 ) ;
F_19 ( V_41 ) ;
F_19 ( V_37 -> V_12 ) ;
return 0 ;
V_42:
V_37 -> V_14 = V_41 ;
V_37 -> V_16 = V_40 ;
return V_11 ;
}
static int F_26 ( struct V_1 * V_2 )
{
struct V_4 * * V_23 ;
unsigned int V_43 ;
int V_25 ;
int V_11 ;
V_23 = V_2 -> V_31 ;
F_27 (i, lzo_blocks[0]->sync_bmp, lzo_blocks[0]->sync_bmp_nbits) {
V_11 = F_28 ( V_2 , V_25 , & V_43 ) ;
if ( V_11 )
return V_11 ;
V_2 -> V_44 = 1 ;
V_11 = F_29 ( V_2 , V_25 , V_43 ) ;
V_2 -> V_44 = 0 ;
if ( V_11 )
return V_11 ;
F_30 ( V_2 -> V_45 , L_1 ,
V_25 , V_43 ) ;
}
return 0 ;
}
