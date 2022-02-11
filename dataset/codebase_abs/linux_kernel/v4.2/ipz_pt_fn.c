void * F_1 ( struct V_1 * V_2 )
{
void * V_3 = F_2 ( V_2 ) ;
V_2 -> V_4 += V_2 -> V_5 ;
if ( V_2 -> V_4 > V_2 -> V_6 ) {
V_2 -> V_4 -= V_2 -> V_5 ;
V_3 = NULL ;
}
if ( ( ( V_7 ) V_3 ) % V_2 -> V_5 ) {
F_3 ( L_1 ) ;
return NULL ;
}
return V_3 ;
}
void * F_4 ( struct V_1 * V_2 )
{
void * V_3 = F_2 ( V_2 ) ;
V_7 V_8 = V_2 -> V_6 - V_2 -> V_9 ;
V_2 -> V_4 += V_2 -> V_9 ;
if ( V_2 -> V_4 > V_8 ) {
V_2 -> V_4 = 0 ;
V_2 -> V_10 = ( ~ V_2 -> V_10 ) & 1 ;
}
return V_3 ;
}
int F_5 ( struct V_1 * V_2 , V_7 V_11 , V_7 * V_12 )
{
int V_13 ;
for ( V_13 = 0 ; V_13 < V_2 -> V_6 / V_2 -> V_5 ; V_13 ++ ) {
V_7 V_14 = F_6 ( V_2 -> V_15 [ V_13 ] ) ;
if ( V_11 >= V_14 && V_11 < V_14 + V_2 -> V_5 ) {
* V_12 = V_11 - V_14 + V_13 * V_2 -> V_5 ;
return 0 ;
}
}
return - V_16 ;
}
static int F_7 ( struct V_1 * V_2 , const T_1 V_17 )
{
int V_18 , V_19 = 0 ;
T_2 * V_20 ;
while ( V_19 < V_17 ) {
V_20 = ( T_2 * ) F_8 ( V_21 ) ;
if ( ! V_20 )
goto V_22;
for ( V_18 = 0 ; V_18 < V_23 && V_19 < V_17 ; V_18 ++ ) {
V_2 -> V_15 [ V_19 ] = (struct V_24 * ) V_20 ;
V_20 += V_25 ;
V_19 ++ ;
}
}
return 1 ;
V_22:
for ( V_19 = 0 ; V_19 < V_17 && V_2 -> V_15 [ V_19 ] ;
V_19 += V_23 )
F_9 ( ( unsigned long ) ( V_2 -> V_15 ) [ V_19 ] ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 , struct V_26 * V_27 )
{
int V_28 = F_11 ( V_2 -> V_5 ) - 9 ;
struct V_29 * V_14 ;
unsigned long V_30 ;
F_12 ( & V_27 -> V_31 ) ;
if ( ! F_13 ( & V_27 -> free [ V_28 ] ) )
V_14 = F_14 ( V_27 -> free [ V_28 ] . V_32 ,
struct V_29 , V_33 ) ;
else {
V_14 = F_15 ( V_34 , V_21 ) ;
if ( ! V_14 )
goto V_22;
V_14 -> V_14 = F_8 ( V_21 ) ;
if ( ! V_14 -> V_14 ) {
F_16 ( V_34 , V_14 ) ;
goto V_22;
}
F_17 ( & V_14 -> V_33 , & V_27 -> free [ V_28 ] ) ;
}
V_30 = F_18 ( V_14 -> V_35 , V_36 >> V_28 ) ;
F_19 ( V_30 , V_14 -> V_35 ) ;
V_14 -> V_37 ++ ;
if ( V_14 -> V_37 == V_36 >> V_28 )
F_20 ( & V_14 -> V_33 , & V_27 -> V_38 [ V_28 ] ) ;
F_21 ( & V_27 -> V_31 ) ;
V_2 -> V_15 [ 0 ] = ( void * ) ( V_14 -> V_14 | ( V_30 << ( V_28 + 9 ) ) ) ;
V_2 -> V_39 = V_14 ;
V_2 -> V_40 = V_30 << ( V_28 + 9 ) ;
return 1 ;
V_22:
F_22 ( V_27 -> V_41 . V_42 , L_2 ) ;
F_21 ( & V_27 -> V_31 ) ;
return 0 ;
}
static void F_23 ( struct V_1 * V_2 , struct V_26 * V_27 )
{
int V_28 = F_11 ( V_2 -> V_5 ) - 9 ;
struct V_29 * V_14 = V_2 -> V_39 ;
unsigned long V_30 ;
int F_9 = 0 ;
V_30 = ( ( unsigned long ) V_2 -> V_15 [ 0 ] & ~ V_43 )
>> ( V_28 + 9 ) ;
F_12 ( & V_27 -> V_31 ) ;
F_24 ( V_30 , V_14 -> V_35 ) ;
V_14 -> V_37 -- ;
if ( V_14 -> V_37 == 0 ) {
F_25 ( & V_14 -> V_33 ) ;
F_9 = 1 ;
}
if ( V_14 -> V_37 == ( V_36 >> V_28 ) - 1 )
F_26 ( & V_14 -> V_33 , & V_27 -> free [ V_28 ] ) ;
F_21 ( & V_27 -> V_31 ) ;
if ( F_9 ) {
F_9 ( V_14 -> V_14 ) ;
F_16 ( V_34 , V_14 ) ;
}
}
int F_27 ( struct V_26 * V_27 , struct V_1 * V_2 ,
const T_1 V_17 , const T_1 V_5 ,
const T_1 V_9 , const T_1 V_44 ,
int V_45 )
{
if ( V_5 > V_46 ) {
F_3 ( L_3
L_4 , V_5 ) ;
return 0 ;
}
V_2 -> V_6 = V_17 * V_5 ;
V_2 -> V_5 = V_5 ;
V_2 -> V_9 = V_9 ;
V_2 -> V_47 = V_44 ;
V_2 -> V_4 = 0 ;
V_2 -> V_10 = 1 ;
V_2 -> V_39 = NULL ;
V_2 -> V_15 = F_28 ( V_17 * sizeof( void * ) ,
V_21 | V_48 ) ;
if ( ! V_2 -> V_15 ) {
V_2 -> V_15 = F_29 ( V_17 * sizeof( void * ) ) ;
if ( ! V_2 -> V_15 ) {
F_3 ( L_5 ) ;
return 0 ;
}
}
if ( V_45 ) {
if ( ! F_10 ( V_2 , V_27 ) )
goto V_49;
} else
if ( ! F_7 ( V_2 , V_17 ) )
goto V_49;
return 1 ;
V_49:
F_3 ( L_6
L_7 , V_2 , V_17 ) ;
F_30 ( V_2 -> V_15 ) ;
return 0 ;
}
int F_31 ( struct V_26 * V_27 , struct V_1 * V_2 )
{
int V_13 , V_50 ;
if ( ! V_2 || ! V_2 -> V_15 ) {
F_32 ( L_8 ) ;
return 0 ;
}
if ( V_2 -> V_39 )
F_23 ( V_2 , V_27 ) ;
else {
V_50 = V_2 -> V_6 / V_2 -> V_5 ;
for ( V_13 = 0 ; V_13 < V_50 ; V_13 += V_23 )
F_9 ( ( unsigned long ) V_2 -> V_15 [ V_13 ] ) ;
}
F_30 ( V_2 -> V_15 ) ;
return 1 ;
}
int F_33 ( void )
{
V_34 = F_34 ( L_9 ,
sizeof( struct V_29 ) ,
0 , V_51 , NULL ) ;
if ( ! V_34 )
return - V_52 ;
return 0 ;
}
void F_35 ( void )
{
F_36 ( V_34 ) ;
}
