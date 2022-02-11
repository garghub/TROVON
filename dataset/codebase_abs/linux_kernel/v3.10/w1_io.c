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
unsigned long V_9 = 0 ;
if( V_10 ) F_6 ( V_9 ) ;
if ( V_5 ) {
V_4 -> V_6 -> V_11 ( V_4 -> V_6 -> V_8 , 0 ) ;
F_1 ( 6 ) ;
V_4 -> V_6 -> V_11 ( V_4 -> V_6 -> V_8 , 1 ) ;
F_1 ( 64 ) ;
} else {
V_4 -> V_6 -> V_11 ( V_4 -> V_6 -> V_8 , 0 ) ;
F_1 ( 60 ) ;
V_4 -> V_6 -> V_11 ( V_4 -> V_6 -> V_8 , 1 ) ;
F_1 ( 10 ) ;
}
if( V_10 ) F_7 ( V_9 ) ;
}
static void F_8 ( struct V_3 * V_4 )
{
if ( V_4 -> V_12 &&
V_4 -> V_13 && V_4 -> V_6 -> V_14 ) {
V_4 -> V_6 -> V_14 ( V_4 -> V_6 -> V_8 ,
V_4 -> V_12 ) ;
}
}
static void F_9 ( struct V_3 * V_4 )
{
if ( V_4 -> V_12 ) {
if ( V_4 -> V_13 && V_4 -> V_6 -> V_14 )
V_4 -> V_6 -> V_14 ( V_4 -> V_6 -> V_8 , 0 ) ;
else
F_10 ( V_4 -> V_12 ) ;
V_4 -> V_12 = 0 ;
}
}
void F_11 ( struct V_3 * V_4 , T_1 V_15 )
{
int V_16 ;
if ( V_4 -> V_6 -> V_17 ) {
F_8 ( V_4 ) ;
V_4 -> V_6 -> V_17 ( V_4 -> V_6 -> V_8 , V_15 ) ;
}
else
for ( V_16 = 0 ; V_16 < 8 ; ++ V_16 ) {
if ( V_16 == 7 )
F_8 ( V_4 ) ;
F_3 ( V_4 , ( V_15 >> V_16 ) & 0x1 ) ;
}
F_9 ( V_4 ) ;
}
static T_1 F_4 ( struct V_3 * V_4 )
{
int V_18 ;
unsigned long V_9 = 0 ;
F_6 ( V_9 ) ;
V_4 -> V_6 -> V_11 ( V_4 -> V_6 -> V_8 , 0 ) ;
F_1 ( 6 ) ;
V_4 -> V_6 -> V_11 ( V_4 -> V_6 -> V_8 , 1 ) ;
F_1 ( 9 ) ;
V_18 = V_4 -> V_6 -> V_19 ( V_4 -> V_6 -> V_8 ) ;
F_7 ( V_9 ) ;
F_1 ( 55 ) ;
return V_18 & 0x1 ;
}
T_1 F_12 ( struct V_3 * V_4 , int V_20 )
{
if ( V_4 -> V_6 -> V_21 )
return V_4 -> V_6 -> V_21 ( V_4 -> V_6 -> V_8 , V_20 ) ;
else {
T_1 V_22 = F_3 ( V_4 , 1 ) ;
T_1 V_23 = F_3 ( V_4 , 1 ) ;
T_1 V_24 ;
if ( V_22 && V_23 )
return 0x03 ;
if ( ! V_22 && ! V_23 ) {
V_24 = V_20 ? 0x04 : 0 ;
} else {
V_20 = V_22 ;
V_24 = V_22 ? 0x05 : 0x02 ;
}
if ( V_4 -> V_6 -> V_7 )
F_3 ( V_4 , V_20 ) ;
else
F_5 ( V_4 , V_20 ) ;
return V_24 ;
}
}
T_1 F_13 ( struct V_3 * V_4 )
{
int V_16 ;
T_1 V_25 = 0 ;
if ( V_4 -> V_6 -> V_26 )
V_25 = V_4 -> V_6 -> V_26 ( V_4 -> V_6 -> V_8 ) ;
else
for ( V_16 = 0 ; V_16 < 8 ; ++ V_16 )
V_25 |= ( F_3 ( V_4 , 1 ) << V_16 ) ;
return V_25 ;
}
void F_14 ( struct V_3 * V_4 , const T_1 * V_27 , int V_28 )
{
int V_16 ;
if ( V_4 -> V_6 -> V_29 ) {
F_8 ( V_4 ) ;
V_4 -> V_6 -> V_29 ( V_4 -> V_6 -> V_8 , V_27 , V_28 ) ;
}
else
for ( V_16 = 0 ; V_16 < V_28 ; ++ V_16 )
F_11 ( V_4 , V_27 [ V_16 ] ) ;
F_9 ( V_4 ) ;
}
void F_15 ( struct V_3 * V_4 , T_1 * V_27 , int V_28 )
{
int V_16 , V_30 ;
T_1 V_31 ;
for ( V_16 = 0 ; V_16 < V_28 ; ++ V_16 ) {
V_31 = 0 ;
for ( V_30 = 0 ; V_30 < 8 ; ++ V_30 ) {
if ( V_30 == 7 )
F_8 ( V_4 ) ;
V_31 |= F_3 ( V_4 , ( V_27 [ V_16 ] >> V_30 ) & 0x1 ) << V_30 ;
}
V_27 [ V_16 ] = V_31 ;
}
}
T_1 F_16 ( struct V_3 * V_4 , T_1 * V_27 , int V_28 )
{
int V_16 ;
T_1 V_32 ;
if ( V_4 -> V_6 -> V_33 )
V_32 = V_4 -> V_6 -> V_33 ( V_4 -> V_6 -> V_8 , V_27 , V_28 ) ;
else {
for ( V_16 = 0 ; V_16 < V_28 ; ++ V_16 )
V_27 [ V_16 ] = F_13 ( V_4 ) ;
V_32 = V_28 ;
}
return V_32 ;
}
int F_17 ( struct V_3 * V_4 )
{
int V_18 ;
unsigned long V_9 = 0 ;
if( V_10 ) F_6 ( V_9 ) ;
if ( V_4 -> V_6 -> V_34 )
V_18 = V_4 -> V_6 -> V_34 ( V_4 -> V_6 -> V_8 ) & 0x1 ;
else {
V_4 -> V_6 -> V_11 ( V_4 -> V_6 -> V_8 , 0 ) ;
F_1 ( 500 ) ;
V_4 -> V_6 -> V_11 ( V_4 -> V_6 -> V_8 , 1 ) ;
F_1 ( 70 ) ;
V_18 = V_4 -> V_6 -> V_19 ( V_4 -> V_6 -> V_8 ) & 0x1 ;
F_10 ( 1 ) ;
}
if( V_10 ) F_7 ( V_9 ) ;
return V_18 ;
}
T_1 F_18 ( T_1 * V_8 , int V_28 )
{
T_1 V_35 = 0 ;
while ( V_28 -- )
V_35 = V_36 [ V_35 ^ * V_8 ++ ] ;
return V_35 ;
}
void F_19 ( struct V_3 * V_4 , T_1 V_37 , T_2 V_38 )
{
V_4 -> V_39 ++ ;
if ( V_4 -> V_6 -> V_40 )
V_4 -> V_6 -> V_40 ( V_4 -> V_6 -> V_8 , V_4 ,
V_37 , V_38 ) ;
else
F_20 ( V_4 , V_37 , V_38 ) ;
}
int F_21 ( struct V_41 * V_42 )
{
if ( F_17 ( V_42 -> V_43 ) )
return - 1 ;
if ( V_42 -> V_43 -> V_44 == 1 )
F_11 ( V_42 -> V_43 , V_45 ) ;
else {
T_1 V_46 [ 9 ] = { V_47 , } ;
T_3 V_48 = F_22 ( * ( ( T_3 * ) & V_42 -> V_49 ) ) ;
memcpy ( & V_46 [ 1 ] , & V_48 , 8 ) ;
F_14 ( V_42 -> V_43 , V_46 , 9 ) ;
}
return 0 ;
}
int F_23 ( struct V_3 * V_4 )
{
if ( F_17 ( V_4 ) )
return - 1 ;
F_11 ( V_4 , V_50 ) ;
return 0 ;
}
void F_24 ( struct V_3 * V_4 , int V_51 )
{
V_4 -> V_12 = V_51 ;
}
