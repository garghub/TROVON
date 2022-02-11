static int F_1 ( void )
{
return V_1 ;
}
static int F_2 ( struct V_2 * V_3 )
{
V_3 -> V_4 = F_3 ( V_5 , V_6 ) ;
if ( ! V_3 -> V_4 )
return - V_7 ;
return 0 ;
}
static int F_4 ( struct V_2 * V_3 )
{
T_1 V_8 ;
int V_9 ;
V_9 = F_5 ( V_3 -> V_10 , V_3 -> V_11 ,
V_3 -> V_12 , & V_8 , V_3 -> V_4 ) ;
if ( V_9 != V_13 || V_8 > V_3 -> V_14 )
return - V_15 ;
V_3 -> V_14 = V_8 ;
return 0 ;
}
static int F_6 ( struct V_2 * V_3 )
{
T_1 V_14 ;
int V_9 ;
V_14 = V_3 -> V_14 ;
V_9 = F_7 ( V_3 -> V_10 , V_3 -> V_11 ,
V_3 -> V_12 , & V_14 ) ;
if ( V_9 != V_13 || V_14 != V_3 -> V_14 )
return - V_15 ;
return 0 ;
}
static int F_8 ( struct V_16 * V_17 ,
struct V_2 * V_3 )
{
int V_9 ;
V_3 -> V_14 = F_9 ( V_18 ) ;
V_3 -> V_12 = F_3 ( V_3 -> V_14 , V_6 ) ;
if ( ! V_3 -> V_12 ) {
V_3 -> V_14 = 0 ;
return - V_7 ;
}
V_9 = F_4 ( V_3 ) ;
if ( V_9 < 0 )
return V_9 ;
return 0 ;
}
static int F_10 ( struct V_16 * V_17 ,
struct V_2 * V_3 )
{
int V_9 ;
V_3 -> V_14 = V_3 -> V_19 ;
V_3 -> V_12 = F_3 ( V_3 -> V_14 , V_6 ) ;
if ( ! V_3 -> V_12 ) {
V_3 -> V_14 = 0 ;
return - V_7 ;
}
V_9 = F_6 ( V_3 ) ;
if ( V_9 < 0 )
return V_9 ;
return 0 ;
}
static inline int F_11 ( struct V_16 * V_17 ,
unsigned int V_20 )
{
return ( V_20 * V_17 -> V_21 ) /
F_12 ( V_17 -> V_22 , F_1 () ) ;
}
static inline int F_13 ( struct V_16 * V_17 ,
unsigned int V_20 )
{
return V_20 % ( F_12 ( V_17 -> V_22 , F_1 () ) /
V_17 -> V_21 ) ;
}
static inline int F_14 ( struct V_16 * V_17 )
{
return F_12 ( V_17 -> V_22 , F_1 () ) ;
}
static int F_15 ( struct V_16 * V_17 )
{
struct V_2 * * V_23 ;
T_1 V_24 ;
int V_9 , V_25 , V_26 , V_27 ;
const char * V_28 , * V_29 ;
unsigned long * V_30 ;
V_9 = 0 ;
V_27 = F_1 () ;
V_17 -> V_31 = F_16 ( V_27 * sizeof *V_23 ,
V_6 ) ;
if ( ! V_17 -> V_31 )
return - V_7 ;
V_23 = V_17 -> V_31 ;
V_24 = V_17 -> V_32 ;
V_30 = F_3 ( F_17 ( V_24 ) * sizeof( long ) ,
V_6 ) ;
if ( ! V_30 ) {
V_9 = - V_7 ;
goto V_33;
}
F_18 ( V_30 , V_24 ) ;
for ( V_25 = 0 ; V_25 < V_27 ; V_25 ++ ) {
V_23 [ V_25 ] = F_16 ( sizeof ** V_23 ,
V_6 ) ;
if ( ! V_23 [ V_25 ] ) {
F_19 ( V_30 ) ;
V_9 = - V_7 ;
goto V_33;
}
V_23 [ V_25 ] -> V_30 = V_30 ;
V_23 [ V_25 ] -> V_34 = V_24 ;
V_9 = F_2 ( V_23 [ V_25 ] ) ;
if ( V_9 < 0 )
goto V_33;
}
V_26 = F_14 ( V_17 ) ;
V_28 = V_17 -> V_35 ;
V_29 = V_17 -> V_35 + V_17 -> V_22 ;
for ( V_25 = 0 ; V_25 < V_27 ; V_25 ++ , V_28 += V_26 ) {
V_23 [ V_25 ] -> V_10 = V_28 ;
if ( V_28 + V_26 > V_29 )
V_23 [ V_25 ] -> V_11 = V_29 - V_28 ;
else
V_23 [ V_25 ] -> V_11 = V_26 ;
V_9 = F_8 ( V_17 ,
V_23 [ V_25 ] ) ;
if ( V_9 < 0 )
goto V_33;
V_23 [ V_25 ] -> V_19 =
V_23 [ V_25 ] -> V_11 ;
}
return 0 ;
V_33:
F_20 ( V_17 ) ;
return V_9 ;
}
static int F_21 ( struct V_16 * V_17 )
{
struct V_2 * * V_23 ;
int V_25 , V_27 ;
V_23 = V_17 -> V_31 ;
if ( ! V_23 )
return 0 ;
V_27 = F_1 () ;
if ( V_23 [ 0 ] )
F_19 ( V_23 [ 0 ] -> V_30 ) ;
for ( V_25 = 0 ; V_25 < V_27 ; V_25 ++ ) {
if ( V_23 [ V_25 ] ) {
F_19 ( V_23 [ V_25 ] -> V_4 ) ;
F_19 ( V_23 [ V_25 ] -> V_12 ) ;
}
F_19 ( V_23 [ V_25 ] ) ;
}
F_19 ( V_23 ) ;
V_17 -> V_31 = NULL ;
return 0 ;
}
static int F_22 ( struct V_16 * V_17 ,
unsigned int V_20 , unsigned int * V_36 )
{
struct V_2 * V_37 , * * V_23 ;
int V_9 , V_38 , V_39 ;
T_1 V_26 , V_40 ;
void * V_41 ;
V_38 = F_11 ( V_17 , V_20 ) ;
V_39 = F_13 ( V_17 , V_20 ) ;
V_26 = F_14 ( V_17 ) ;
V_23 = V_17 -> V_31 ;
V_37 = V_23 [ V_38 ] ;
V_41 = V_37 -> V_12 ;
V_40 = V_37 -> V_14 ;
V_37 -> V_10 = V_37 -> V_12 ;
V_37 -> V_11 = V_37 -> V_14 ;
V_9 = F_10 ( V_17 , V_37 ) ;
if ( V_9 >= 0 )
* V_36 = F_23 ( V_37 -> V_12 , V_39 ,
V_17 -> V_21 ) ;
F_19 ( V_37 -> V_12 ) ;
V_37 -> V_12 = V_41 ;
V_37 -> V_14 = V_40 ;
return V_9 ;
}
static int F_24 ( struct V_16 * V_17 ,
unsigned int V_20 , unsigned int V_36 )
{
struct V_2 * V_37 , * * V_23 ;
int V_9 , V_38 , V_39 ;
T_1 V_26 , V_40 ;
void * V_41 ;
V_38 = F_11 ( V_17 , V_20 ) ;
V_39 = F_13 ( V_17 , V_20 ) ;
V_26 = F_14 ( V_17 ) ;
V_23 = V_17 -> V_31 ;
V_37 = V_23 [ V_38 ] ;
V_41 = V_37 -> V_12 ;
V_40 = V_37 -> V_14 ;
V_37 -> V_10 = V_37 -> V_12 ;
V_37 -> V_11 = V_37 -> V_14 ;
V_9 = F_10 ( V_17 , V_37 ) ;
if ( V_9 < 0 ) {
F_19 ( V_37 -> V_12 ) ;
goto V_42;
}
if ( F_25 ( V_37 -> V_12 , V_39 , V_36 ,
V_17 -> V_21 ) ) {
F_19 ( V_37 -> V_12 ) ;
goto V_42;
}
V_37 -> V_10 = V_37 -> V_12 ;
V_37 -> V_11 = V_37 -> V_14 ;
V_9 = F_8 ( V_17 , V_37 ) ;
if ( V_9 < 0 ) {
F_19 ( V_37 -> V_12 ) ;
F_19 ( V_37 -> V_10 ) ;
goto V_42;
}
F_26 ( V_20 , V_37 -> V_30 ) ;
F_19 ( V_41 ) ;
F_19 ( V_37 -> V_10 ) ;
return 0 ;
V_42:
V_37 -> V_12 = V_41 ;
V_37 -> V_14 = V_40 ;
return V_9 ;
}
static int F_27 ( struct V_16 * V_17 )
{
struct V_2 * * V_23 ;
unsigned int V_43 ;
int V_25 ;
int V_9 ;
V_23 = V_17 -> V_31 ;
F_28 (i, lzo_blocks[0]->sync_bmp, lzo_blocks[0]->sync_bmp_nbits) {
V_9 = F_29 ( V_17 , V_25 , & V_43 ) ;
if ( V_9 )
return V_9 ;
V_17 -> V_44 = 1 ;
V_9 = F_30 ( V_17 , V_25 , V_43 ) ;
V_17 -> V_44 = 0 ;
if ( V_9 )
return V_9 ;
F_31 ( V_17 -> V_45 , L_1 ,
V_25 , V_43 ) ;
}
return 0 ;
}
