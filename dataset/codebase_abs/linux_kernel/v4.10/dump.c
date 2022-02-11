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
static void F_3 ( struct V_1 * V_2 , unsigned long V_14 )
{
if ( ! V_2 -> V_15 )
return;
if ( ( V_2 -> V_8 & V_16 ) == V_16 )
return;
F_4 ( 1 , L_2 ,
( void * ) V_2 -> V_17 , ( void * ) V_2 -> V_17 ) ;
V_2 -> V_18 += ( V_14 - V_2 -> V_17 ) / V_19 ;
}
static void F_5 ( struct V_1 * V_2 , unsigned long V_14 )
{
if ( ! V_2 -> V_15 )
return;
if ( ( V_2 -> V_8 & V_20 ) == V_20 )
return;
if ( ( V_2 -> V_8 & V_21 ) == V_21 )
return;
F_4 ( 1 , L_3 ,
( void * ) V_2 -> V_17 , ( void * ) V_2 -> V_17 ) ;
V_2 -> V_22 += ( V_14 - V_2 -> V_17 ) / V_19 ;
}
static void F_6 ( struct V_1 * V_2 , unsigned long V_14 , unsigned V_23 ,
T_2 V_10 )
{
static const char V_24 [] = L_4 ;
T_2 V_25 = V_10 & V_26 [ V_23 ] . V_9 ;
if ( ! V_2 -> V_23 ) {
V_2 -> V_23 = V_23 ;
V_2 -> V_8 = V_25 ;
V_2 -> V_17 = V_14 ;
F_2 ( V_2 -> V_13 , L_5 , V_2 -> V_27 -> V_28 ) ;
} else if ( V_25 != V_2 -> V_8 || V_23 != V_2 -> V_23 ||
V_14 >= V_2 -> V_27 [ 1 ] . V_17 ) {
const char * V_29 = V_24 ;
unsigned long V_30 ;
if ( V_2 -> V_8 ) {
F_3 ( V_2 , V_14 ) ;
F_5 ( V_2 , V_14 ) ;
F_2 ( V_2 -> V_13 , L_6 ,
V_2 -> V_17 , V_14 ) ;
V_30 = ( V_14 - V_2 -> V_17 ) >> 10 ;
while ( ! ( V_30 & 1023 ) && V_29 [ 1 ] ) {
V_30 >>= 10 ;
V_29 ++ ;
}
F_2 ( V_2 -> V_13 , L_7 , V_30 , * V_29 ,
V_26 [ V_2 -> V_23 ] . V_28 ) ;
if ( V_26 [ V_2 -> V_23 ] . V_4 )
F_1 ( V_2 , V_26 [ V_2 -> V_23 ] . V_4 ,
V_26 [ V_2 -> V_23 ] . V_5 ) ;
F_7 ( V_2 -> V_13 , L_8 ) ;
}
if ( V_14 >= V_2 -> V_27 [ 1 ] . V_17 ) {
V_2 -> V_27 ++ ;
F_2 ( V_2 -> V_13 , L_5 , V_2 -> V_27 -> V_28 ) ;
}
V_2 -> V_17 = V_14 ;
V_2 -> V_8 = V_25 ;
V_2 -> V_23 = V_23 ;
}
if ( V_14 >= V_2 -> V_27 [ 1 ] . V_17 ) {
V_2 -> V_27 ++ ;
F_2 ( V_2 -> V_13 , L_5 , V_2 -> V_27 -> V_28 ) ;
}
}
static void F_8 ( struct V_1 * V_2 , T_3 * V_31 , unsigned long V_32 )
{
T_4 * V_33 = F_9 ( V_31 , 0UL ) ;
unsigned long V_14 ;
unsigned V_6 ;
for ( V_6 = 0 ; V_6 < V_34 ; V_6 ++ , V_33 ++ ) {
V_14 = V_32 + V_6 * V_19 ;
F_6 ( V_2 , V_14 , 4 , F_10 ( * V_33 ) ) ;
}
}
static void F_11 ( struct V_1 * V_2 , T_5 * V_35 , unsigned long V_32 )
{
T_3 * V_31 = F_12 ( V_35 , 0UL ) ;
unsigned long V_14 ;
unsigned V_6 ;
for ( V_6 = 0 ; V_6 < V_36 ; V_6 ++ , V_31 ++ ) {
V_14 = V_32 + V_6 * V_37 ;
if ( F_13 ( * V_31 ) || F_14 ( * V_31 ) ) {
F_6 ( V_2 , V_14 , 3 , F_15 ( * V_31 ) ) ;
} else {
F_16 ( F_17 ( * V_31 ) ) ;
F_8 ( V_2 , V_31 , V_14 ) ;
}
}
}
static void F_18 ( struct V_1 * V_2 , T_6 * V_38 , unsigned long V_32 )
{
T_5 * V_35 = F_19 ( V_38 , 0UL ) ;
unsigned long V_14 ;
unsigned V_6 ;
for ( V_6 = 0 ; V_6 < V_39 ; V_6 ++ , V_35 ++ ) {
V_14 = V_32 + V_6 * V_40 ;
if ( F_20 ( * V_35 ) || F_21 ( * V_35 ) ) {
F_6 ( V_2 , V_14 , 2 , F_22 ( * V_35 ) ) ;
} else {
F_16 ( F_23 ( * V_35 ) ) ;
F_11 ( V_2 , V_35 , V_14 ) ;
}
}
}
static void F_24 ( struct V_1 * V_2 , struct V_41 * V_42 ,
unsigned long V_32 )
{
T_6 * V_38 = F_25 ( V_42 , 0UL ) ;
unsigned V_6 ;
unsigned long V_14 ;
for ( V_6 = 0 ; V_6 < V_43 ; V_6 ++ , V_38 ++ ) {
V_14 = V_32 + V_6 * V_44 ;
if ( F_26 ( * V_38 ) ) {
F_6 ( V_2 , V_14 , 1 , F_27 ( * V_38 ) ) ;
} else {
F_16 ( F_28 ( * V_38 ) ) ;
F_18 ( V_2 , V_38 , V_14 ) ;
}
}
}
void F_29 ( struct V_45 * V_46 , struct V_47 * V_48 )
{
struct V_1 V_2 = {
. V_13 = V_46 ,
. V_27 = V_48 -> V_49 ,
} ;
F_24 ( & V_2 , V_48 -> V_42 , V_48 -> V_50 ) ;
F_6 ( & V_2 , 0 , 0 , 0 ) ;
}
static void F_30 ( void )
{
unsigned V_6 , V_51 ;
for ( V_6 = 0 ; V_6 < F_31 ( V_26 ) ; V_6 ++ )
if ( V_26 [ V_6 ] . V_4 )
for ( V_51 = 0 ; V_51 < V_26 [ V_6 ] . V_5 ; V_51 ++ )
V_26 [ V_6 ] . V_9 |= V_26 [ V_6 ] . V_4 [ V_51 ] . V_9 ;
}
void F_32 ( void )
{
struct V_1 V_2 = {
. V_13 = NULL ,
. V_27 = (struct V_52 [] ) {
{ 0 , NULL } ,
{ - 1 , NULL } ,
} ,
. V_15 = true ,
} ;
F_24 ( & V_2 , & V_53 , 0 ) ;
F_6 ( & V_2 , 0 , 0 , 0 ) ;
if ( V_2 . V_22 || V_2 . V_18 )
F_33 ( L_9 ,
V_2 . V_22 , V_2 . V_18 ) ;
else
F_34 ( L_10 ) ;
}
static int F_35 ( void )
{
F_30 () ;
return F_36 ( & V_54 ,
L_11 ) ;
}
