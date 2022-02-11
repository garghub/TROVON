static void F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 ,
T_1 V_5 )
{
unsigned V_6 ;
for ( V_6 = 0 ; V_6 < V_5 ; V_6 ++ , V_4 ++ ) {
const char * V_7 ;
if ( ( V_2 -> V_8 & V_4 -> V_9 ) == V_4 -> V_10 )
V_7 = V_4 -> V_11 ;
else
V_7 = V_4 -> V_12 ;
if ( V_7 )
F_2 ( V_2 -> V_13 , L_1 , V_7 ) ;
}
}
static void F_3 ( struct V_1 * V_2 , unsigned long V_14 , unsigned V_15 ,
T_2 V_10 )
{
static const char V_16 [] = L_2 ;
T_2 V_17 = V_10 & V_18 [ V_15 ] . V_9 ;
if ( ! V_2 -> V_15 ) {
V_2 -> V_15 = V_15 ;
V_2 -> V_8 = V_17 ;
V_2 -> V_19 = V_14 ;
F_2 ( V_2 -> V_13 , L_3 , V_2 -> V_20 -> V_21 ) ;
} else if ( V_17 != V_2 -> V_8 || V_15 != V_2 -> V_15 ||
V_14 >= V_2 -> V_20 [ 1 ] . V_19 ) {
const char * V_22 = V_16 ;
unsigned long V_23 ;
if ( V_2 -> V_8 ) {
F_2 ( V_2 -> V_13 , L_4 ,
V_2 -> V_19 , V_14 ) ;
V_23 = ( V_14 - V_2 -> V_19 ) >> 10 ;
while ( ! ( V_23 & 1023 ) && V_22 [ 1 ] ) {
V_23 >>= 10 ;
V_22 ++ ;
}
F_2 ( V_2 -> V_13 , L_5 , V_23 , * V_22 ) ;
if ( V_18 [ V_2 -> V_15 ] . V_4 )
F_1 ( V_2 , V_18 [ V_2 -> V_15 ] . V_4 ,
V_18 [ V_2 -> V_15 ] . V_5 ) ;
F_4 ( V_2 -> V_13 , L_6 ) ;
}
if ( V_14 >= V_2 -> V_20 [ 1 ] . V_19 ) {
V_2 -> V_20 ++ ;
F_2 ( V_2 -> V_13 , L_3 , V_2 -> V_20 -> V_21 ) ;
}
V_2 -> V_19 = V_14 ;
V_2 -> V_8 = V_17 ;
V_2 -> V_15 = V_15 ;
}
if ( V_14 >= V_2 -> V_20 [ 1 ] . V_19 ) {
V_2 -> V_20 ++ ;
F_2 ( V_2 -> V_13 , L_3 , V_2 -> V_20 -> V_21 ) ;
}
}
static void F_5 ( struct V_1 * V_2 , T_3 * V_24 , unsigned long V_25 )
{
T_4 * V_26 = F_6 ( V_24 , 0 ) ;
unsigned long V_14 ;
unsigned V_6 ;
for ( V_6 = 0 ; V_6 < V_27 ; V_6 ++ , V_26 ++ ) {
V_14 = V_25 + V_6 * V_28 ;
F_3 ( V_2 , V_14 , 4 , F_7 ( * V_26 ) ) ;
}
}
static void F_8 ( struct V_1 * V_2 , T_5 * V_29 , unsigned long V_25 )
{
T_3 * V_24 = F_9 ( V_29 , 0 ) ;
unsigned long V_14 ;
unsigned V_6 ;
for ( V_6 = 0 ; V_6 < V_30 ; V_6 ++ , V_24 ++ ) {
V_14 = V_25 + V_6 * V_31 ;
if ( F_10 ( * V_24 ) || F_11 ( * V_24 ) ) {
F_3 ( V_2 , V_14 , 3 , F_12 ( * V_24 ) ) ;
} else {
F_13 ( F_14 ( * V_24 ) ) ;
F_5 ( V_2 , V_24 , V_14 ) ;
}
}
}
static void F_15 ( struct V_1 * V_2 , T_6 * V_32 , unsigned long V_25 )
{
T_5 * V_29 = F_16 ( V_32 , 0 ) ;
unsigned long V_14 ;
unsigned V_6 ;
for ( V_6 = 0 ; V_6 < V_33 ; V_6 ++ , V_29 ++ ) {
V_14 = V_25 + V_6 * V_34 ;
if ( F_17 ( * V_29 ) || F_18 ( * V_29 ) ) {
F_3 ( V_2 , V_14 , 2 , F_19 ( * V_29 ) ) ;
} else {
F_13 ( F_20 ( * V_29 ) ) ;
F_8 ( V_2 , V_29 , V_14 ) ;
}
}
}
static void F_21 ( struct V_1 * V_2 , struct V_35 * V_36 , unsigned long V_25 )
{
T_6 * V_32 = F_22 ( V_36 , 0UL ) ;
unsigned V_6 ;
unsigned long V_14 ;
for ( V_6 = 0 ; V_6 < V_37 ; V_6 ++ , V_32 ++ ) {
V_14 = V_25 + V_6 * V_38 ;
if ( F_23 ( * V_32 ) ) {
F_3 ( V_2 , V_14 , 1 , F_24 ( * V_32 ) ) ;
} else {
F_13 ( F_25 ( * V_32 ) ) ;
F_15 ( V_2 , V_32 , V_14 ) ;
}
}
}
static int F_26 ( struct V_39 * V_40 , void * V_41 )
{
struct V_1 V_2 = {
. V_13 = V_40 ,
. V_20 = V_42 ,
} ;
F_21 ( & V_2 , & V_43 , VA_START ) ;
F_3 ( & V_2 , 0 , 0 , 0 ) ;
return 0 ;
}
static int F_27 ( struct V_44 * V_44 , struct V_45 * V_45 )
{
return F_28 ( V_45 , F_26 , NULL ) ;
}
static int F_29 ( void )
{
struct V_46 * V_47 ;
unsigned V_6 , V_48 ;
for ( V_6 = 0 ; V_6 < F_30 ( V_18 ) ; V_6 ++ )
if ( V_18 [ V_6 ] . V_4 )
for ( V_48 = 0 ; V_48 < V_18 [ V_6 ] . V_5 ; V_48 ++ )
V_18 [ V_6 ] . V_9 |= V_18 [ V_6 ] . V_4 [ V_48 ] . V_9 ;
#ifdef F_31
V_42 [ V_49 ] . V_19 =
( unsigned long ) F_32 ( V_50 ) ;
V_42 [ V_51 ] . V_19 =
( unsigned long ) F_32 ( V_52 ) ;
#endif
V_47 = F_33 ( L_7 , 0400 , NULL , NULL ,
& V_53 ) ;
return V_47 ? 0 : - V_54 ;
}
