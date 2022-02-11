int F_1 ( T_1 * V_1 )
{
int V_2 ;
for ( V_2 = 0 ; V_2 < V_3 ; ++ V_2 )
if ( V_4 [ V_2 ] == NULL )
break;
if ( V_2 == V_3 )
return - V_5 ;
V_4 [ V_2 ] = V_1 ;
++ V_6 ;
return 0 ;
}
void F_2 ( T_1 * V_1 )
{
int V_2 ;
for ( V_2 = 0 ; V_2 < V_3 ; ++ V_2 )
if ( V_4 [ V_2 ] == V_1 )
break;
if ( V_2 == V_3 ) {
F_3 (KERN_WARNING LOGNAME L_1 ) ;
return;
}
V_4 [ V_2 ] = NULL ;
-- V_6 ;
}
void F_4 ( void T_2 * V_7 , int V_8 , int V_9 )
{
F_5 ( F_6 ( V_8 ) , V_7 + V_10 ) ;
F_5 ( F_7 ( V_9 ) - 1 , V_7 + V_11 ) ;
F_5 ( 0 , V_7 + V_12 ) ;
F_5 ( 0 , V_7 + V_13 ) ;
}
void F_8 ( T_3 * V_14 )
{
V_14 -> V_15 = NULL ;
}
void F_9 ( T_3 * V_14 )
{
F_10 ( V_14 -> V_15 ) ;
V_14 -> V_15 = NULL ;
}
int F_11 ( T_3 * V_14 , T_4 V_16 )
{
F_9 ( V_14 ) ;
V_14 -> V_15 = F_12 ( V_16 ) ;
V_14 -> V_16 = V_16 ;
V_14 -> V_17 = 0 ;
V_14 -> V_18 = 0 ;
V_14 -> V_19 = 0 ;
if ( ! V_14 -> V_15 )
return - V_5 ;
return 0 ;
}
void F_13 ( T_3 * V_14 )
{
V_14 -> V_19 = V_14 -> V_17 = V_14 -> V_18 = 0 ;
}
int F_14 ( T_3 * V_14 , char T_2 * V_20 , T_4 V_19 )
{
int V_21 = 0 ;
while ( ( V_21 < V_19 ) && ( V_14 -> V_19 != V_14 -> V_16 ) ) {
int V_22 ;
if ( V_14 -> V_18 <= V_14 -> V_17 ) {
V_22 = V_19 - V_21 ;
if ( V_22 > V_14 -> V_16 - V_14 -> V_17 )
V_22 = V_14 -> V_16 - V_14 -> V_17 ;
}
else {
V_22 = V_14 -> V_18 - V_14 -> V_17 ;
if ( V_22 > V_19 - V_21 )
V_22 = V_19 - V_21 ;
}
F_15 ( V_14 -> V_15 + V_14 -> V_17 , V_20 , V_22 ) ;
V_21 += V_22 ;
V_20 += V_22 ;
V_14 -> V_19 += V_22 ;
V_14 -> V_17 += V_22 ;
V_14 -> V_17 %= V_14 -> V_16 ;
}
return V_21 ;
}
int F_16 ( T_3 * V_14 , const char * V_20 , T_4 V_19 )
{
int V_21 = 0 ;
while ( ( V_21 < V_19 ) && ( V_14 -> V_19 != V_14 -> V_16 ) ) {
int V_22 ;
if ( V_14 -> V_18 <= V_14 -> V_17 ) {
V_22 = V_19 - V_21 ;
if ( V_22 > V_14 -> V_16 - V_14 -> V_17 )
V_22 = V_14 -> V_16 - V_14 -> V_17 ;
}
else {
V_22 = V_14 -> V_18 - V_14 -> V_17 ;
if ( V_22 > V_19 - V_21 )
V_22 = V_19 - V_21 ;
}
memcpy ( V_14 -> V_15 + V_14 -> V_17 , V_20 , V_22 ) ;
V_21 += V_22 ;
V_20 += V_22 ;
V_14 -> V_19 += V_22 ;
V_14 -> V_17 += V_22 ;
V_14 -> V_17 %= V_14 -> V_16 ;
}
return V_21 ;
}
int F_17 ( T_3 * V_14 , char T_2 * V_20 , T_4 V_19 )
{
int V_21 = 0 ;
while ( ( V_21 < V_19 ) && ( V_14 -> V_19 > 0 ) ) {
int V_23 ;
if ( V_14 -> V_17 <= V_14 -> V_18 ) {
V_23 = V_19 - V_21 ;
if ( V_23 > V_14 -> V_16 - V_14 -> V_18 )
V_23 = V_14 -> V_16 - V_14 -> V_18 ;
}
else {
V_23 = V_14 -> V_17 - V_14 -> V_18 ;
if ( V_23 > V_19 - V_21 )
V_23 = V_19 - V_21 ;
}
F_18 ( V_20 , V_14 -> V_15 + V_14 -> V_18 , V_23 ) ;
V_21 += V_23 ;
V_20 += V_23 ;
V_14 -> V_19 -= V_23 ;
V_14 -> V_18 += V_23 ;
V_14 -> V_18 %= V_14 -> V_16 ;
}
return V_21 ;
}
int F_19 ( T_3 * V_14 , char * V_20 , T_4 V_19 )
{
int V_21 = 0 ;
while ( ( V_21 < V_19 ) && ( V_14 -> V_19 > 0 ) ) {
int V_23 ;
if ( V_14 -> V_17 <= V_14 -> V_18 ) {
V_23 = V_19 - V_21 ;
if ( V_23 > V_14 -> V_16 - V_14 -> V_18 )
V_23 = V_14 -> V_16 - V_14 -> V_18 ;
}
else {
V_23 = V_14 -> V_17 - V_14 -> V_18 ;
if ( V_23 > V_19 - V_21 )
V_23 = V_19 - V_21 ;
}
memcpy ( V_20 , V_14 -> V_15 + V_14 -> V_18 , V_23 ) ;
V_21 += V_23 ;
V_20 += V_23 ;
V_14 -> V_19 -= V_23 ;
V_14 -> V_18 += V_23 ;
V_14 -> V_18 %= V_14 -> V_16 ;
}
return V_21 ;
}
static int F_20 ( T_1 * V_1 )
{
register unsigned int V_24 = V_1 -> V_24 ;
register int V_25 = 1000 ;
while( V_25 -- > 0 )
if ( F_21 ( V_24 + V_26 ) & V_27 )
return 0 ;
return - V_28 ;
}
static int F_22 ( T_1 * V_1 )
{
register unsigned int V_24 = V_1 -> V_24 ;
register int V_25 = 1000 ;
while( V_25 -- > 0 )
if ( ! ( F_21 ( V_24 + V_29 ) & V_30 ) )
return 0 ;
return - V_28 ;
}
int F_23 ( T_1 * V_1 , T_5 V_31 )
{
unsigned long V_32 ;
F_24 ( & V_1 -> V_33 , V_32 ) ;
if ( F_22 ( V_1 ) == 0 ) {
F_25 ( V_31 , V_1 -> V_24 + V_29 ) ;
F_26 ( & V_1 -> V_33 , V_32 ) ;
return 0 ;
}
F_26 ( & V_1 -> V_33 , V_32 ) ;
F_3 (KERN_DEBUG LOGNAME L_2 ) ;
return - V_28 ;
}
int F_27 ( T_1 * V_1 , unsigned char V_34 ,
unsigned char V_35 , unsigned char V_36 )
{
register unsigned int V_24 = V_1 -> V_24 ;
if ( F_20 ( V_1 ) == 0 ) {
F_25 ( V_34 , V_24 + V_37 ) ;
F_25 ( V_35 , V_24 + V_38 ) ;
F_25 ( V_36 , V_24 + V_39 ) ;
return 0 ;
}
F_3 (KERN_DEBUG LOGNAME L_3 ) ;
return - V_28 ;
}
int F_28 ( T_1 * V_1 , char * V_40 , int V_19 )
{
int V_2 ;
if ( V_19 % 3 != 0 ) {
F_3 (KERN_WARNING LOGNAME L_4 ) ;
return - V_41 ;
}
for ( V_2 = 0 ; V_2 < V_19 ; V_2 += 3 )
if ( F_27 ( V_1 , V_40 [ V_2 ] , V_40 [ V_2 + 1 ] , V_40 [ V_2 + 2 ] ) != 0 )
return - V_28 ;
F_21 ( V_1 -> V_24 + V_42 ) ;
F_21 ( V_1 -> V_24 + V_29 ) ;
return 0 ;
}
int F_29 ( T_1 * V_1 )
{
unsigned long V_32 ;
if ( V_1 -> V_43 ++ )
return 0 ;
F_3 (KERN_DEBUG LOGNAME L_5 ) ;
F_24 ( & V_1 -> V_33 , V_32 ) ;
if ( F_20 ( V_1 ) == 0 ) {
F_25 ( F_21 ( V_1 -> V_24 + V_44 ) | V_45 , V_1 -> V_24 + V_44 ) ;
if ( V_1 -> type == V_46 )
F_25 ( V_1 -> V_47 , V_1 -> V_24 + V_48 ) ;
F_25 ( F_21 ( V_1 -> V_24 + V_44 ) & ~ V_45 , V_1 -> V_24 + V_44 ) ;
F_25 ( F_21 ( V_1 -> V_24 + V_44 ) | V_49 , V_1 -> V_24 + V_44 ) ;
F_30 ( V_1 -> V_50 ) ;
F_4 ( V_1 -> V_51 , V_1 -> V_52 , V_1 -> V_53 ) ;
F_26 ( & V_1 -> V_33 , V_32 ) ;
return 0 ;
}
F_26 ( & V_1 -> V_33 , V_32 ) ;
F_3 (KERN_DEBUG LOGNAME L_6 ) ;
return - V_28 ;
}
int F_31 ( T_1 * V_1 )
{
unsigned long V_32 ;
if ( -- V_1 -> V_43 > 0 )
return 0 ;
if ( V_1 -> V_43 < 0 )
F_3 (KERN_DEBUG LOGNAME L_7 , dev->irq_ref) ;
F_3 (KERN_DEBUG LOGNAME L_8 ) ;
F_24 ( & V_1 -> V_33 , V_32 ) ;
if ( F_20 ( V_1 ) == 0 ) {
F_25 ( F_21 ( V_1 -> V_24 + V_44 ) & ~ V_49 , V_1 -> V_24 + V_44 ) ;
if ( V_1 -> type == V_46 )
F_25 ( V_54 , V_1 -> V_24 + V_48 ) ;
F_32 ( V_1 -> V_50 ) ;
F_26 ( & V_1 -> V_33 , V_32 ) ;
return 0 ;
}
F_26 ( & V_1 -> V_33 , V_32 ) ;
F_3 (KERN_DEBUG LOGNAME L_9 ) ;
return - V_28 ;
}
int F_33 ( void )
{
return 0 ;
}
void F_34 ( void )
{
}
