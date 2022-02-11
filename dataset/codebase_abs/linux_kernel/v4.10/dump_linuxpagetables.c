static void F_1 ( struct V_1 * V_2 , const struct V_3
* V_4 , T_1 V_5 , int V_6 )
{
unsigned int V_7 ;
for ( V_7 = 0 ; V_7 < V_6 ; V_7 ++ , V_4 ++ ) {
const char * V_8 = NULL ;
T_1 V_9 ;
if ( V_4 -> V_10 == 0 )
continue;
if ( V_4 -> V_11 ) {
V_9 = V_5 & V_4 -> V_9 ;
if ( V_4 -> V_12 )
V_9 = V_9 >> V_4 -> V_12 ;
F_2 ( V_2 -> V_13 , L_1 , V_4 -> V_14 , V_9 ) ;
} else {
if ( ( V_5 & V_4 -> V_10 ) == V_4 -> V_9 )
V_8 = V_4 -> V_14 ;
else
V_8 = V_4 -> V_15 ;
if ( V_8 )
F_2 ( V_2 -> V_13 , L_2 , V_8 ) ;
}
V_2 -> V_16 &= ~ V_4 -> V_10 ;
}
if ( V_2 -> V_16 != 0 )
F_2 ( V_2 -> V_13 , L_3 , V_2 -> V_16 ) ;
}
static void F_3 ( struct V_1 * V_2 , unsigned long V_17 )
{
static const char V_18 [] = L_4 ;
const char * V_19 = V_18 ;
unsigned long V_20 ;
F_2 ( V_2 -> V_13 , L_5 , V_2 -> V_21 , V_17 - 1 ) ;
V_20 = ( V_17 - V_2 -> V_21 ) >> 10 ;
while ( ! ( V_20 & 1023 ) && V_19 [ 1 ] ) {
V_20 >>= 10 ;
V_19 ++ ;
}
F_2 ( V_2 -> V_13 , L_6 , V_20 , * V_19 ) ;
}
static void F_4 ( struct V_1 * V_2 , unsigned long V_17 ,
unsigned int V_22 , T_1 V_9 )
{
T_1 V_4 = V_9 & V_23 [ V_22 ] . V_10 ;
if ( ! V_2 -> V_22 ) {
V_2 -> V_22 = V_22 ;
V_2 -> V_16 = V_4 ;
V_2 -> V_21 = V_17 ;
F_2 ( V_2 -> V_13 , L_7 , V_2 -> V_24 -> V_25 ) ;
} else if ( V_4 != V_2 -> V_16 || V_22 != V_2 -> V_22 ||
V_17 >= V_2 -> V_24 [ 1 ] . V_21 ) {
if ( V_2 -> V_16 ) {
F_3 ( V_2 , V_17 ) ;
if ( V_23 [ V_2 -> V_22 ] . V_4 )
F_1 ( V_2 , V_23 [ V_2 -> V_22 ] . V_4 ,
V_2 -> V_16 ,
V_23 [ V_2 -> V_22 ] . V_6 ) ;
F_5 ( V_2 -> V_13 , L_8 ) ;
}
while ( V_17 >= V_2 -> V_24 [ 1 ] . V_21 ) {
V_2 -> V_24 ++ ;
F_2 ( V_2 -> V_13 , L_7 , V_2 -> V_24 -> V_25 ) ;
}
V_2 -> V_21 = V_17 ;
V_2 -> V_16 = V_4 ;
V_2 -> V_22 = V_22 ;
}
}
static void F_6 ( struct V_1 * V_2 , T_2 * V_26 , unsigned long V_27 )
{
T_3 * V_5 = F_7 ( V_26 , 0 ) ;
unsigned long V_17 ;
unsigned int V_7 ;
for ( V_7 = 0 ; V_7 < V_28 ; V_7 ++ , V_5 ++ ) {
V_17 = V_27 + V_7 * V_29 ;
F_4 ( V_2 , V_17 , 4 , F_8 ( * V_5 ) ) ;
}
}
static void F_9 ( struct V_1 * V_2 , T_4 * V_30 , unsigned long V_27 )
{
T_2 * V_26 = F_10 ( V_30 , 0 ) ;
unsigned long V_17 ;
unsigned int V_7 ;
for ( V_7 = 0 ; V_7 < V_31 ; V_7 ++ , V_26 ++ ) {
V_17 = V_27 + V_7 * V_32 ;
if ( ! F_11 ( * V_26 ) )
F_6 ( V_2 , V_26 , V_17 ) ;
else
F_4 ( V_2 , V_17 , 3 , F_12 ( * V_26 ) ) ;
}
}
static void F_13 ( struct V_1 * V_2 , T_5 * V_33 , unsigned long V_27 )
{
T_4 * V_30 = F_14 ( V_33 , 0 ) ;
unsigned long V_17 ;
unsigned int V_7 ;
for ( V_7 = 0 ; V_7 < V_34 ; V_7 ++ , V_30 ++ ) {
V_17 = V_27 + V_7 * V_35 ;
if ( ! F_15 ( * V_30 ) )
F_9 ( V_2 , V_30 , V_17 ) ;
else
F_4 ( V_2 , V_17 , 2 , F_16 ( * V_30 ) ) ;
}
}
static void F_17 ( struct V_1 * V_2 )
{
T_5 * V_33 = F_18 ( 0UL ) ;
unsigned int V_7 ;
unsigned long V_17 ;
for ( V_7 = 0 ; V_7 < V_36 ; V_7 ++ , V_33 ++ ) {
V_17 = V_37 + V_7 * V_38 ;
if ( ! F_19 ( * V_33 ) )
F_13 ( V_2 , V_33 , V_17 ) ;
else
F_4 ( V_2 , V_17 , 1 , F_20 ( * V_33 ) ) ;
}
}
static void F_21 ( void )
{
V_39 [ 0 ] . V_21 = V_40 ;
V_39 [ 1 ] . V_21 = V_41 ;
V_39 [ 2 ] . V_21 = V_42 ;
V_39 [ 3 ] . V_21 = V_43 ;
V_39 [ 4 ] . V_21 = V_44 ;
V_39 [ 5 ] . V_21 = V_45 ;
V_39 [ 6 ] . V_21 = V_46 ;
V_39 [ 7 ] . V_21 = V_47 ;
V_39 [ 8 ] . V_21 = V_48 ;
#ifdef F_22
V_39 [ 9 ] . V_21 = V_49 ;
#else
V_39 [ 9 ] . V_21 = V_50 ;
#endif
}
static int F_23 ( struct V_51 * V_52 , void * V_53 )
{
struct V_1 V_2 = {
. V_13 = V_52 ,
. V_21 = V_37 ,
. V_24 = V_39 ,
} ;
F_17 ( & V_2 ) ;
F_4 ( & V_2 , 0 , 0 , 0 ) ;
return 0 ;
}
static int F_24 ( struct V_54 * V_54 , struct V_55 * V_55 )
{
return F_25 ( V_55 , F_23 , NULL ) ;
}
static void F_26 ( void )
{
unsigned int V_7 , V_56 ;
for ( V_7 = 0 ; V_7 < F_27 ( V_23 ) ; V_7 ++ )
if ( V_23 [ V_7 ] . V_4 )
for ( V_56 = 0 ; V_56 < V_23 [ V_7 ] . V_6 ; V_56 ++ )
V_23 [ V_7 ] . V_10 |= V_23 [ V_7 ] . V_4 [ V_56 ] . V_10 ;
}
static int F_28 ( void )
{
struct V_57 * V_58 ;
F_21 () ;
F_26 () ;
V_58 = F_29 ( L_9 , 0400 , NULL ,
NULL , & V_59 ) ;
return V_58 ? 0 : - V_60 ;
}
