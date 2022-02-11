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
unsigned long V_17 ;
F_10 ( V_17 ) ;
V_4 -> V_6 -> V_9 ( V_4 -> V_6 -> V_8 , 0 ) ;
F_1 ( 6 ) ;
V_4 -> V_6 -> V_9 ( V_4 -> V_6 -> V_8 , 1 ) ;
F_1 ( 9 ) ;
V_16 = V_4 -> V_6 -> V_18 ( V_4 -> V_6 -> V_8 ) ;
F_11 ( V_17 ) ;
F_1 ( 55 ) ;
return V_16 & 0x1 ;
}
T_1 F_12 ( struct V_3 * V_4 , int V_19 )
{
if ( V_4 -> V_6 -> V_20 )
return V_4 -> V_6 -> V_20 ( V_4 -> V_6 -> V_8 , V_19 ) ;
else {
T_1 V_21 = F_3 ( V_4 , 1 ) ;
T_1 V_22 = F_3 ( V_4 , 1 ) ;
T_1 V_23 ;
if ( V_21 && V_22 )
return 0x03 ;
if ( ! V_21 && ! V_22 ) {
V_23 = V_19 ? 0x04 : 0 ;
} else {
V_19 = V_21 ;
V_23 = V_21 ? 0x05 : 0x02 ;
}
if ( V_4 -> V_6 -> V_7 )
F_3 ( V_4 , V_19 ) ;
else
F_5 ( V_4 , V_19 ) ;
return V_23 ;
}
}
T_1 F_13 ( struct V_3 * V_4 )
{
int V_14 ;
T_1 V_24 = 0 ;
if ( V_4 -> V_6 -> V_25 )
V_24 = V_4 -> V_6 -> V_25 ( V_4 -> V_6 -> V_8 ) ;
else
for ( V_14 = 0 ; V_14 < 8 ; ++ V_14 )
V_24 |= ( F_3 ( V_4 , 1 ) << V_14 ) ;
return V_24 ;
}
void F_14 ( struct V_3 * V_4 , const T_1 * V_26 , int V_27 )
{
int V_14 ;
if ( V_4 -> V_6 -> V_28 ) {
F_6 ( V_4 ) ;
V_4 -> V_6 -> V_28 ( V_4 -> V_6 -> V_8 , V_26 , V_27 ) ;
}
else
for ( V_14 = 0 ; V_14 < V_27 ; ++ V_14 )
F_9 ( V_4 , V_26 [ V_14 ] ) ;
F_7 ( V_4 ) ;
}
void F_15 ( struct V_3 * V_4 , T_1 * V_26 , int V_27 )
{
int V_14 , V_29 ;
T_1 V_30 ;
for ( V_14 = 0 ; V_14 < V_27 ; ++ V_14 ) {
V_30 = 0 ;
for ( V_29 = 0 ; V_29 < 8 ; ++ V_29 ) {
if ( V_29 == 7 )
F_6 ( V_4 ) ;
V_30 |= F_3 ( V_4 , ( V_26 [ V_14 ] >> V_29 ) & 0x1 ) << V_29 ;
}
V_26 [ V_14 ] = V_30 ;
}
}
T_1 F_16 ( struct V_3 * V_4 , T_1 * V_26 , int V_27 )
{
int V_14 ;
T_1 V_31 ;
if ( V_4 -> V_6 -> V_32 )
V_31 = V_4 -> V_6 -> V_32 ( V_4 -> V_6 -> V_8 , V_26 , V_27 ) ;
else {
for ( V_14 = 0 ; V_14 < V_27 ; ++ V_14 )
V_26 [ V_14 ] = F_13 ( V_4 ) ;
V_31 = V_27 ;
}
return V_31 ;
}
int F_17 ( struct V_3 * V_4 )
{
int V_16 ;
if ( V_4 -> V_6 -> V_33 )
V_16 = V_4 -> V_6 -> V_33 ( V_4 -> V_6 -> V_8 ) & 0x1 ;
else {
V_4 -> V_6 -> V_9 ( V_4 -> V_6 -> V_8 , 0 ) ;
F_1 ( 480 ) ;
V_4 -> V_6 -> V_9 ( V_4 -> V_6 -> V_8 , 1 ) ;
F_1 ( 70 ) ;
V_16 = V_4 -> V_6 -> V_18 ( V_4 -> V_6 -> V_8 ) & 0x1 ;
F_8 ( 1 ) ;
}
return V_16 ;
}
T_1 F_18 ( T_1 * V_8 , int V_27 )
{
T_1 V_34 = 0 ;
while ( V_27 -- )
V_34 = V_35 [ V_34 ^ * V_8 ++ ] ;
return V_34 ;
}
void F_19 ( struct V_3 * V_4 , T_1 V_36 , T_2 V_37 )
{
V_4 -> V_38 ++ ;
if ( V_4 -> V_6 -> V_39 )
V_4 -> V_6 -> V_39 ( V_4 -> V_6 -> V_8 , V_4 ,
V_36 , V_37 ) ;
else
F_20 ( V_4 , V_36 , V_37 ) ;
}
int F_21 ( struct V_40 * V_41 )
{
if ( F_17 ( V_41 -> V_42 ) )
return - 1 ;
if ( V_41 -> V_42 -> V_43 == 1 )
F_9 ( V_41 -> V_42 , V_44 ) ;
else {
T_1 V_45 [ 9 ] = { V_46 , } ;
T_3 V_47 = F_22 ( * ( ( T_3 * ) & V_41 -> V_48 ) ) ;
memcpy ( & V_45 [ 1 ] , & V_47 , 8 ) ;
F_14 ( V_41 -> V_42 , V_45 , 9 ) ;
}
return 0 ;
}
int F_23 ( struct V_3 * V_4 )
{
if ( F_17 ( V_4 ) )
return - 1 ;
F_9 ( V_4 , V_49 ) ;
return 0 ;
}
void F_24 ( struct V_3 * V_4 , int V_50 )
{
V_4 -> V_10 = V_50 ;
}
