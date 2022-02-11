static void F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 [ 0 ] = F_2 ( V_2 -> V_4 + V_5 ) ;
V_2 -> V_3 [ 1 ] = F_2 ( V_2 -> V_4 + V_6 ) ;
}
static void F_3 ( struct V_1 * V_2 )
{
void T_1 * V_4 = V_2 -> V_4 ;
T_2 V_7 = F_2 ( V_4 + V_5 ) ;
T_2 V_8 = F_2 ( V_4 + V_6 ) ;
T_2 V_9 = V_2 -> V_3 [ 0 ] ;
T_2 V_10 = V_2 -> V_3 [ 1 ] ;
T_2 V_11 ;
V_11 = V_7 | V_9 ;
F_4 ( V_11 , V_4 + V_5 ) ;
F_4 ( V_10 , V_4 + V_6 ) ;
F_4 ( V_9 , V_4 + V_5 ) ;
F_5 ( L_1 ,
V_2 -> V_2 . V_12 , V_7 , V_9 , V_8 , V_10 ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
V_2 -> V_3 [ 0 ] = F_2 ( V_2 -> V_4 + V_5 ) ;
V_2 -> V_3 [ 1 ] = F_2 ( V_2 -> V_4 + V_6 ) ;
V_2 -> V_3 [ 2 ] = F_2 ( V_2 -> V_4 + V_13 ) ;
}
static inline int F_7 ( unsigned long V_14 )
{
return V_14 >= 2 ;
}
static inline int F_8 ( unsigned long V_14 )
{
return V_14 == 0 ;
}
static inline int F_9 ( unsigned long V_14 )
{
return V_14 == 1 ;
}
static void F_10 ( struct V_1 * V_2 )
{
void T_1 * V_4 = V_2 -> V_4 ;
T_2 V_7 = F_2 ( V_4 + V_5 ) ;
T_2 V_8 = F_2 ( V_4 + V_6 ) ;
T_2 V_9 = V_2 -> V_3 [ 0 ] ;
T_2 V_10 = V_2 -> V_3 [ 1 ] ;
T_2 V_11 , V_15 , V_16 , V_17 ;
T_2 V_18 = 0x0 ;
int V_19 ;
F_4 ( V_2 -> V_3 [ 2 ] , V_4 + V_13 ) ;
for ( V_19 = 0 , V_17 = 0x03 ; V_19 < 32 ; V_19 += 2 , V_17 <<= 2 ) {
V_15 = ( V_7 & V_17 ) >> V_19 ;
V_16 = ( V_9 & V_17 ) >> V_19 ;
if ( V_15 == V_16 )
continue;
if ( F_7 ( V_15 ) && F_7 ( V_16 ) )
continue;
if ( F_8 ( V_15 ) && F_9 ( V_16 ) )
continue;
if ( F_7 ( V_15 ) && F_9 ( V_16 ) )
continue;
V_18 |= V_17 ;
}
V_11 = V_7 & ~ V_18 ;
V_11 |= V_9 & V_18 ;
F_4 ( V_11 , V_4 + V_5 ) ;
F_4 ( V_10 , V_4 + V_6 ) ;
F_4 ( V_9 , V_4 + V_5 ) ;
F_5 ( L_1 ,
V_2 -> V_2 . V_12 , V_7 , V_9 , V_8 , V_10 ) ;
}
static void F_11 ( struct V_1 * V_2 )
{
V_2 -> V_3 [ 1 ] = F_2 ( V_2 -> V_4 + V_5 ) ;
V_2 -> V_3 [ 2 ] = F_2 ( V_2 -> V_4 + V_6 ) ;
V_2 -> V_3 [ 3 ] = F_2 ( V_2 -> V_4 + V_13 ) ;
if ( V_2 -> V_2 . V_20 > 8 )
V_2 -> V_3 [ 0 ] = F_2 ( V_2 -> V_4 - 4 ) ;
}
static T_2 F_12 ( T_2 V_7 , T_2 V_9 )
{
T_2 V_15 , V_16 , V_17 ;
T_2 V_18 = 0x0 ;
int V_19 ;
for ( V_19 = 0 , V_17 = 0x0f ; V_19 < 16 ; V_19 += 4 , V_17 <<= 4 ) {
V_15 = ( V_7 & V_17 ) >> V_19 ;
V_16 = ( V_9 & V_17 ) >> V_19 ;
if ( V_15 == V_16 )
continue;
if ( F_7 ( V_15 ) && F_7 ( V_16 ) )
continue;
if ( F_8 ( V_15 ) && F_9 ( V_16 ) )
continue;
if ( F_7 ( V_15 ) && F_9 ( V_16 ) )
continue;
V_18 |= V_17 ;
}
return V_18 ;
}
static void F_13 ( struct V_1 * V_2 , int V_21 )
{
void T_1 * V_14 = V_2 -> V_4 + ( V_21 * 4 ) ;
T_2 V_7 = F_2 ( V_14 ) ;
T_2 V_9 = V_2 -> V_3 [ V_21 + 1 ] ;
T_2 V_11 , V_17 ;
V_17 = F_12 ( V_7 , V_9 ) ;
V_11 = V_7 & ~ V_17 ;
V_11 |= V_9 & V_17 ;
F_4 ( V_11 , V_14 ) ;
}
static void F_14 ( struct V_1 * V_2 )
{
void T_1 * V_4 = V_2 -> V_4 ;
T_2 V_7 [ 2 ] ;
T_2 V_8 = F_2 ( V_4 + V_6 ) ;
T_2 V_10 = V_2 -> V_3 [ 2 ] ;
V_7 [ 0 ] = 0 ;
V_7 [ 1 ] = F_2 ( V_4 + V_5 ) ;
F_13 ( V_2 , 0 ) ;
if ( V_2 -> V_2 . V_20 > 8 ) {
V_7 [ 0 ] = F_2 ( V_4 - 4 ) ;
F_13 ( V_2 , - 1 ) ;
}
F_4 ( V_2 -> V_3 [ 2 ] , V_4 + V_6 ) ;
F_4 ( V_2 -> V_3 [ 1 ] , V_4 + V_5 ) ;
if ( V_2 -> V_2 . V_20 > 8 )
F_4 ( V_2 -> V_3 [ 0 ] , V_4 - 4 ) ;
F_4 ( V_2 -> V_3 [ 2 ] , V_4 + V_6 ) ;
F_4 ( V_2 -> V_3 [ 3 ] , V_4 + V_13 ) ;
if ( V_2 -> V_2 . V_20 > 8 ) {
F_5 ( L_2 ,
V_2 -> V_2 . V_12 , V_7 [ 0 ] , V_7 [ 1 ] ,
F_2 ( V_4 - 4 ) ,
F_2 ( V_4 + V_5 ) ,
V_8 , V_10 ) ;
} else
F_5 ( L_3 ,
V_2 -> V_2 . V_12 , V_7 [ 1 ] ,
F_2 ( V_4 + V_5 ) ,
V_8 , V_10 ) ;
}
static void F_15 ( struct V_1 * V_22 )
{
struct V_23 * V_24 = V_22 -> V_24 ;
if ( V_24 == NULL || V_24 -> V_25 == NULL )
F_5 ( L_4 , V_26 , V_22 -> V_2 . V_12 ) ;
else
V_24 -> V_25 ( V_22 ) ;
}
void F_16 ( void )
{
struct V_1 * V_22 ;
unsigned int V_27 ;
for ( V_27 = 0 ; V_27 < V_28 ; ) {
V_22 = F_17 ( V_27 ) ;
if ( ! V_22 ) {
V_27 ++ ;
continue;
}
F_15 ( V_22 ) ;
F_5 ( L_5 ,
V_22 -> V_2 . V_12 ,
V_22 -> V_3 [ 0 ] ,
V_22 -> V_3 [ 1 ] ,
V_22 -> V_3 [ 2 ] ,
V_22 -> V_3 [ 3 ] ) ;
V_27 += V_22 -> V_2 . V_20 ;
V_27 += V_29 ;
}
}
static void F_18 ( struct V_1 * V_22 )
{
struct V_23 * V_24 = V_22 -> V_24 ;
if ( V_24 == NULL || V_24 -> V_30 == NULL )
F_5 ( L_4 , V_26 , V_22 -> V_2 . V_12 ) ;
else
V_24 -> V_30 ( V_22 ) ;
}
void F_19 ( void )
{
struct V_1 * V_22 ;
unsigned int V_27 ;
for ( V_27 = 0 ; V_27 < V_28 ; ) {
V_22 = F_17 ( V_27 ) ;
if ( ! V_22 ) {
V_27 ++ ;
continue;
}
F_18 ( V_22 ) ;
V_27 += V_22 -> V_2 . V_20 ;
V_27 += V_29 ;
}
}
