static void F_1 ( unsigned long V_1 )
{
F_2 ( V_1 * V_2 ) ;
}
static T_1 F_3 ( struct V_3 * V_4 , int V_5 )
{
if ( V_4 -> V_6 -> V_7 )
return V_4 -> V_6 -> V_7 ( V_4 -> V_6 -> V_8 , V_5 ) ;
else if ( V_5 )
return F_4 ( V_4 ) ;
else {
F_5 ( V_4 , 0 ) ;
return 0 ;
}
}
static void F_5 ( struct V_3 * V_4 , int V_5 )
{
if ( V_5 ) {
V_4 -> V_6 -> V_9 ( V_4 -> V_6 -> V_8 , 0 ) ;
F_1 ( 6 ) ;
V_4 -> V_6 -> V_9 ( V_4 -> V_6 -> V_8 , 1 ) ;
F_1 ( 64 ) ;
} else {
V_4 -> V_6 -> V_9 ( V_4 -> V_6 -> V_8 , 0 ) ;
F_1 ( 60 ) ;
V_4 -> V_6 -> V_9 ( V_4 -> V_6 -> V_8 , 1 ) ;
F_1 ( 10 ) ;
}
}
static void F_6 ( struct V_3 * V_4 )
{
if ( V_4 -> V_10 &&
V_4 -> V_11 && V_4 -> V_6 -> V_12 ) {
V_4 -> V_6 -> V_12 ( V_4 -> V_6 -> V_8 ,
V_4 -> V_10 ) ;
}
}
static void F_7 ( struct V_3 * V_4 )
{
if ( V_4 -> V_10 ) {
if ( V_4 -> V_11 && V_4 -> V_6 -> V_12 )
V_4 -> V_6 -> V_12 ( V_4 -> V_6 -> V_8 , 0 ) ;
else
F_8 ( V_4 -> V_10 ) ;
V_4 -> V_10 = 0 ;
}
}
void F_9 ( struct V_3 * V_4 , T_1 V_13 )
{
int V_14 ;
if ( V_4 -> V_6 -> V_15 ) {
F_6 ( V_4 ) ;
V_4 -> V_6 -> V_15 ( V_4 -> V_6 -> V_8 , V_13 ) ;
}
else
for ( V_14 = 0 ; V_14 < 8 ; ++ V_14 ) {
if ( V_14 == 7 )
F_6 ( V_4 ) ;
F_3 ( V_4 , ( V_13 >> V_14 ) & 0x1 ) ;
}
F_7 ( V_4 ) ;
}
static T_1 F_4 ( struct V_3 * V_4 )
{
int V_16 ;
V_4 -> V_6 -> V_9 ( V_4 -> V_6 -> V_8 , 0 ) ;
F_1 ( 6 ) ;
V_4 -> V_6 -> V_9 ( V_4 -> V_6 -> V_8 , 1 ) ;
F_1 ( 9 ) ;
V_16 = V_4 -> V_6 -> V_17 ( V_4 -> V_6 -> V_8 ) ;
F_1 ( 55 ) ;
return V_16 & 0x1 ;
}
T_1 F_10 ( struct V_3 * V_4 , int V_18 )
{
if ( V_4 -> V_6 -> V_19 )
return V_4 -> V_6 -> V_19 ( V_4 -> V_6 -> V_8 , V_18 ) ;
else {
T_1 V_20 = F_3 ( V_4 , 1 ) ;
T_1 V_21 = F_3 ( V_4 , 1 ) ;
T_1 V_22 ;
if ( V_20 && V_21 )
return 0x03 ;
if ( ! V_20 && ! V_21 ) {
V_22 = V_18 ? 0x04 : 0 ;
} else {
V_18 = V_20 ;
V_22 = V_20 ? 0x05 : 0x02 ;
}
if ( V_4 -> V_6 -> V_7 )
F_3 ( V_4 , V_18 ) ;
else
F_5 ( V_4 , V_18 ) ;
return V_22 ;
}
}
T_1 F_11 ( struct V_3 * V_4 )
{
int V_14 ;
T_1 V_23 = 0 ;
if ( V_4 -> V_6 -> V_24 )
V_23 = V_4 -> V_6 -> V_24 ( V_4 -> V_6 -> V_8 ) ;
else
for ( V_14 = 0 ; V_14 < 8 ; ++ V_14 )
V_23 |= ( F_3 ( V_4 , 1 ) << V_14 ) ;
return V_23 ;
}
void F_12 ( struct V_3 * V_4 , const T_1 * V_25 , int V_26 )
{
int V_14 ;
if ( V_4 -> V_6 -> V_27 ) {
F_6 ( V_4 ) ;
V_4 -> V_6 -> V_27 ( V_4 -> V_6 -> V_8 , V_25 , V_26 ) ;
}
else
for ( V_14 = 0 ; V_14 < V_26 ; ++ V_14 )
F_9 ( V_4 , V_25 [ V_14 ] ) ;
F_7 ( V_4 ) ;
}
void F_13 ( struct V_3 * V_4 , T_1 * V_25 , int V_26 )
{
int V_14 , V_28 ;
T_1 V_29 ;
for ( V_14 = 0 ; V_14 < V_26 ; ++ V_14 ) {
V_29 = 0 ;
for ( V_28 = 0 ; V_28 < 8 ; ++ V_28 ) {
if ( V_28 == 7 )
F_6 ( V_4 ) ;
V_29 |= F_3 ( V_4 , ( V_25 [ V_14 ] >> V_28 ) & 0x1 ) << V_28 ;
}
V_25 [ V_14 ] = V_29 ;
}
}
T_1 F_14 ( struct V_3 * V_4 , T_1 * V_25 , int V_26 )
{
int V_14 ;
T_1 V_30 ;
if ( V_4 -> V_6 -> V_31 )
V_30 = V_4 -> V_6 -> V_31 ( V_4 -> V_6 -> V_8 , V_25 , V_26 ) ;
else {
for ( V_14 = 0 ; V_14 < V_26 ; ++ V_14 )
V_25 [ V_14 ] = F_11 ( V_4 ) ;
V_30 = V_26 ;
}
return V_30 ;
}
int F_15 ( struct V_3 * V_4 )
{
int V_16 ;
if ( V_4 -> V_6 -> V_32 )
V_16 = V_4 -> V_6 -> V_32 ( V_4 -> V_6 -> V_8 ) & 0x1 ;
else {
V_4 -> V_6 -> V_9 ( V_4 -> V_6 -> V_8 , 0 ) ;
F_1 ( 480 ) ;
V_4 -> V_6 -> V_9 ( V_4 -> V_6 -> V_8 , 1 ) ;
F_1 ( 70 ) ;
V_16 = V_4 -> V_6 -> V_17 ( V_4 -> V_6 -> V_8 ) & 0x1 ;
F_8 ( 1 ) ;
}
return V_16 ;
}
T_1 F_16 ( T_1 * V_8 , int V_26 )
{
T_1 V_33 = 0 ;
while ( V_26 -- )
V_33 = V_34 [ V_33 ^ * V_8 ++ ] ;
return V_33 ;
}
void F_17 ( struct V_3 * V_4 , T_1 V_35 , T_2 V_36 )
{
V_4 -> V_37 ++ ;
if ( V_4 -> V_6 -> V_38 )
V_4 -> V_6 -> V_38 ( V_4 -> V_6 -> V_8 , V_4 ,
V_35 , V_36 ) ;
else
F_18 ( V_4 , V_35 , V_36 ) ;
}
int F_19 ( struct V_39 * V_40 )
{
if ( F_15 ( V_40 -> V_41 ) )
return - 1 ;
if ( V_40 -> V_41 -> V_42 == 1 )
F_9 ( V_40 -> V_41 , V_43 ) ;
else {
T_1 V_44 [ 9 ] = { V_45 , } ;
T_3 V_46 = F_20 ( * ( ( T_3 * ) & V_40 -> V_47 ) ) ;
memcpy ( & V_44 [ 1 ] , & V_46 , 8 ) ;
F_12 ( V_40 -> V_41 , V_44 , 9 ) ;
}
return 0 ;
}
int F_21 ( struct V_3 * V_4 )
{
if ( F_15 ( V_4 ) )
return - 1 ;
F_9 ( V_4 , V_48 ) ;
return 0 ;
}
void F_22 ( struct V_3 * V_4 , int V_49 )
{
V_4 -> V_10 = V_49 ;
}
