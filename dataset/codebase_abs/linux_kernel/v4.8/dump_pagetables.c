static void F_1 ( struct V_1 * V_2 , unsigned int V_3 , int V_4 )
{
static const char * const V_5 [] =
{ L_1 , L_2 , L_3 , L_4 , L_5 } ;
F_2 ( V_2 , L_6 , V_5 [ V_4 ] ) ;
if ( V_3 & V_6 ) {
F_2 ( V_2 , L_7 ) ;
return;
}
F_2 ( V_2 , L_8 , V_3 & V_7 ? L_9 : L_10 ) ;
F_3 ( V_2 , '\n' ) ;
}
static void F_4 ( struct V_1 * V_2 , struct V_8 * V_9 ,
unsigned int V_10 , int V_4 )
{
static const char V_11 [] = L_11 ;
int V_12 = sizeof( unsigned long ) * 2 ;
const char * V_13 = V_11 ;
unsigned int V_14 , V_15 ;
unsigned long V_16 ;
V_14 = V_10 ;
V_15 = V_9 -> V_17 ;
if ( ! V_9 -> V_4 ) {
V_9 -> V_17 = V_10 ;
V_9 -> V_4 = V_4 ;
V_9 -> V_18 = V_19 ;
F_2 ( V_2 , L_12 , V_9 -> V_18 -> V_20 ) ;
} else if ( V_14 != V_15 || V_4 != V_9 -> V_4 ||
V_9 -> V_21 >= V_9 -> V_18 [ 1 ] . V_22 ) {
F_2 ( V_2 , L_13 ,
V_12 , V_9 -> V_22 ,
V_12 , V_9 -> V_21 ) ;
V_16 = ( V_9 -> V_21 - V_9 -> V_22 ) >> 10 ;
while ( ! ( V_16 & 0x3ff ) && V_13 [ 1 ] ) {
V_16 >>= 10 ;
V_13 ++ ;
}
F_2 ( V_2 , L_14 , V_16 , * V_13 ) ;
F_1 ( V_2 , V_9 -> V_17 , V_9 -> V_4 ) ;
if ( V_9 -> V_21 >= V_9 -> V_18 [ 1 ] . V_22 ) {
V_9 -> V_18 ++ ;
F_2 ( V_2 , L_12 , V_9 -> V_18 -> V_20 ) ;
}
V_9 -> V_22 = V_9 -> V_21 ;
V_9 -> V_17 = V_10 ;
V_9 -> V_4 = V_4 ;
}
}
static void F_5 ( struct V_1 * V_2 , struct V_8 * V_9 ,
T_1 * V_23 , unsigned long V_24 )
{
unsigned int V_14 ;
T_2 * V_25 ;
int V_26 ;
for ( V_26 = 0 ; V_26 < V_27 && V_24 < V_28 ; V_26 ++ ) {
V_9 -> V_21 = V_24 ;
V_25 = F_6 ( V_23 , V_24 ) ;
V_14 = F_7 ( * V_25 ) & ( V_7 | V_6 ) ;
F_4 ( V_2 , V_9 , V_14 , 4 ) ;
V_24 += V_29 ;
}
}
static void F_8 ( struct V_1 * V_2 , struct V_8 * V_9 ,
T_3 * V_30 , unsigned long V_24 )
{
unsigned int V_14 ;
T_1 * V_23 ;
int V_26 ;
for ( V_26 = 0 ; V_26 < V_31 && V_24 < V_28 ; V_26 ++ ) {
V_9 -> V_21 = V_24 ;
V_23 = F_9 ( V_30 , V_24 ) ;
if ( ! F_10 ( * V_23 ) ) {
if ( F_11 ( * V_23 ) ) {
V_14 = F_12 ( * V_23 ) & V_32 ;
F_4 ( V_2 , V_9 , V_14 , 3 ) ;
} else
F_5 ( V_2 , V_9 , V_23 , V_24 ) ;
} else
F_4 ( V_2 , V_9 , V_6 , 3 ) ;
V_24 += V_33 ;
}
}
static void F_13 ( struct V_1 * V_2 , struct V_8 * V_9 ,
T_4 * V_34 , unsigned long V_24 )
{
unsigned int V_14 ;
T_3 * V_30 ;
int V_26 ;
for ( V_26 = 0 ; V_26 < V_35 && V_24 < V_28 ; V_26 ++ ) {
V_9 -> V_21 = V_24 ;
V_30 = F_14 ( V_34 , V_24 ) ;
if ( ! F_15 ( * V_30 ) )
if ( F_16 ( * V_30 ) ) {
V_14 = F_17 ( * V_30 ) & V_36 ;
F_4 ( V_2 , V_9 , V_14 , 2 ) ;
} else
F_8 ( V_2 , V_9 , V_30 , V_24 ) ;
else
F_4 ( V_2 , V_9 , V_6 , 2 ) ;
V_24 += V_37 ;
}
}
static void F_18 ( struct V_1 * V_2 )
{
unsigned long V_24 = 0 ;
struct V_8 V_9 ;
T_4 * V_34 ;
int V_26 ;
memset ( & V_9 , 0 , sizeof( V_9 ) ) ;
for ( V_26 = 0 ; V_26 < V_38 && V_24 < V_28 ; V_26 ++ ) {
V_9 . V_21 = V_24 ;
V_34 = F_19 ( V_24 ) ;
if ( ! F_20 ( * V_34 ) )
F_13 ( V_2 , & V_9 , V_34 , V_24 ) ;
else
F_4 ( V_2 , & V_9 , V_6 , 1 ) ;
V_24 += V_39 ;
}
V_9 . V_21 = V_28 ;
F_4 ( V_2 , & V_9 , 0 , 0 ) ;
}
static int F_21 ( struct V_1 * V_2 , void * V_40 )
{
F_18 ( V_2 ) ;
return 0 ;
}
static int F_22 ( struct V_41 * V_41 , struct V_42 * V_43 )
{
return F_23 ( V_43 , F_21 , NULL ) ;
}
static int F_24 ( void )
{
V_28 = ( V_44 . V_45 & V_46 ) >> 2 ;
V_28 = 1UL << ( V_28 * 11 + 31 ) ;
V_19 [ V_47 ] . V_22 = V_48 ;
V_19 [ V_49 ] . V_22 = ( unsigned long ) V_50 ;
V_19 [ V_51 ] . V_22 = V_52 ;
F_25 ( L_15 , 0400 , NULL , NULL , & V_53 ) ;
return 0 ;
}
