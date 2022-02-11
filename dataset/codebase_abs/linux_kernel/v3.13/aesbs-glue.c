static int F_1 ( struct V_1 * V_2 , const T_1 * V_3 ,
unsigned int V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_7 = V_4 * 8 ;
if ( F_3 ( V_3 , V_7 , & V_6 -> V_8 ) ) {
V_2 -> V_9 |= V_10 ;
return - V_11 ;
}
V_6 -> V_12 . V_13 = V_6 -> V_8 ;
F_4 ( V_3 , V_7 , & V_6 -> V_12 . V_13 ) ;
V_6 -> V_12 . V_14 = 0 ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 , const T_1 * V_3 ,
unsigned int V_4 )
{
struct V_15 * V_6 = F_2 ( V_2 ) ;
int V_7 = V_4 * 8 ;
if ( F_3 ( V_3 , V_7 , & V_6 -> V_8 . V_13 ) ) {
V_2 -> V_9 |= V_10 ;
return - V_11 ;
}
V_6 -> V_8 . V_14 = 0 ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 , const T_1 * V_3 ,
unsigned int V_4 )
{
struct V_16 * V_6 = F_2 ( V_2 ) ;
int V_7 = V_4 * 4 ;
if ( F_3 ( V_3 , V_7 , & V_6 -> V_8 . V_13 ) ) {
V_2 -> V_9 |= V_10 ;
return - V_11 ;
}
V_6 -> V_12 . V_13 = V_6 -> V_8 . V_13 ;
F_4 ( V_3 , V_7 , & V_6 -> V_12 . V_13 ) ;
F_3 ( V_3 + V_4 / 2 , V_7 , & V_6 -> V_17 ) ;
V_6 -> V_8 . V_14 = V_6 -> V_12 . V_14 = 0 ;
return 0 ;
}
static int F_7 ( struct V_18 * V_19 ,
struct V_20 * V_21 ,
struct V_20 * V_22 , unsigned int V_23 )
{
struct V_5 * V_6 = F_8 ( V_19 -> V_2 ) ;
struct V_24 V_25 ;
int V_26 ;
F_9 ( & V_25 , V_21 , V_22 , V_23 ) ;
V_26 = F_10 ( V_19 , & V_25 ) ;
while ( V_25 . V_23 ) {
T_2 V_27 = V_25 . V_23 / V_28 ;
T_1 * V_22 = V_25 . V_22 . V_29 . V_30 ;
if ( V_25 . V_21 . V_29 . V_30 == V_25 . V_22 . V_29 . V_30 ) {
T_1 * V_31 = V_25 . V_31 ;
do {
F_11 ( V_22 , V_31 , V_28 ) ;
F_12 ( V_22 , V_22 , & V_6 -> V_8 ) ;
V_31 = V_22 ;
V_22 += V_28 ;
} while ( -- V_27 );
memcpy ( V_25 . V_31 , V_31 , V_28 ) ;
} else {
T_1 * V_21 = V_25 . V_21 . V_29 . V_30 ;
do {
F_11 ( V_25 . V_31 , V_22 , V_28 ) ;
F_12 ( V_25 . V_31 , V_21 , & V_6 -> V_8 ) ;
memcpy ( V_25 . V_31 , V_21 , V_28 ) ;
V_22 += V_28 ;
V_21 += V_28 ;
} while ( -- V_27 );
}
V_26 = F_13 ( V_19 , & V_25 , 0 ) ;
}
return V_26 ;
}
static int F_14 ( struct V_18 * V_19 ,
struct V_20 * V_21 ,
struct V_20 * V_22 , unsigned int V_23 )
{
struct V_5 * V_6 = F_8 ( V_19 -> V_2 ) ;
struct V_24 V_25 ;
int V_26 ;
F_9 ( & V_25 , V_21 , V_22 , V_23 ) ;
V_26 = F_15 ( V_19 , & V_25 , 8 * V_28 ) ;
while ( ( V_25 . V_23 / V_28 ) >= 8 ) {
F_16 () ;
F_17 ( V_25 . V_22 . V_29 . V_30 , V_25 . V_21 . V_29 . V_30 ,
V_25 . V_23 , & V_6 -> V_12 , V_25 . V_31 ) ;
F_18 () ;
V_26 = F_13 ( V_19 , & V_25 , 0 ) ;
}
while ( V_25 . V_23 ) {
T_2 V_27 = V_25 . V_23 / V_28 ;
T_1 * V_21 = V_25 . V_21 . V_29 . V_30 ;
T_1 * V_22 = V_25 . V_22 . V_29 . V_30 ;
T_1 V_32 [ 2 ] [ V_28 ] ;
T_1 * V_31 = V_25 . V_31 ;
do {
if ( V_25 . V_21 . V_29 . V_30 == V_25 . V_22 . V_29 . V_30 )
memcpy ( V_32 [ V_27 & 1 ] , V_22 , V_28 ) ;
F_19 ( V_22 , V_21 , & V_6 -> V_12 . V_13 ) ;
F_11 ( V_21 , V_31 , V_28 ) ;
if ( V_25 . V_21 . V_29 . V_30 == V_25 . V_22 . V_29 . V_30 )
V_31 = V_32 [ V_27 & 1 ] ;
else
V_31 = V_22 ;
V_21 += V_28 ;
V_22 += V_28 ;
} while ( -- V_27 );
V_26 = F_13 ( V_19 , & V_25 , 0 ) ;
}
return V_26 ;
}
static void F_20 ( T_3 V_33 [] , T_2 V_34 )
{
int V_35 ;
for ( V_35 = 3 ; V_35 >= 0 ; V_35 -- , V_34 = 1 ) {
T_2 V_36 = F_21 ( V_33 [ V_35 ] ) + V_34 ;
V_33 [ V_35 ] = F_22 ( V_36 ) ;
if ( V_36 >= V_34 )
break;
}
}
static int F_23 ( struct V_18 * V_19 ,
struct V_20 * V_21 , struct V_20 * V_22 ,
unsigned int V_23 )
{
struct V_15 * V_6 = F_8 ( V_19 -> V_2 ) ;
struct V_24 V_25 ;
T_2 V_27 ;
int V_26 ;
F_9 ( & V_25 , V_21 , V_22 , V_23 ) ;
V_26 = F_15 ( V_19 , & V_25 , 8 * V_28 ) ;
while ( ( V_27 = V_25 . V_23 / V_28 ) ) {
T_2 V_37 = V_25 . V_23 % V_28 ;
T_3 * V_33 = ( T_3 * ) V_25 . V_31 ;
T_2 V_38 = V_39 - F_21 ( V_33 [ 3 ] ) ;
if ( F_24 ( V_38 < V_27 ) ) {
V_27 = V_38 + 1 ;
V_37 = V_25 . V_23 - V_27 * V_28 ;
}
F_16 () ;
F_25 ( V_25 . V_22 . V_29 . V_30 ,
V_25 . V_21 . V_29 . V_30 , V_27 ,
& V_6 -> V_8 , V_25 . V_31 ) ;
F_18 () ;
F_20 ( V_33 , V_27 ) ;
V_23 -= V_27 * V_28 ;
if ( V_23 && V_23 == V_37 && V_23 <= V_28 )
break;
V_26 = F_13 ( V_19 , & V_25 , V_37 ) ;
}
if ( V_25 . V_23 ) {
T_1 * V_40 = V_25 . V_21 . V_29 . V_30 + V_27 * V_28 ;
T_1 * V_41 = V_25 . V_22 . V_29 . V_30 + V_27 * V_28 ;
T_1 V_42 [ V_28 ] ;
F_12 ( V_25 . V_31 , V_42 , & V_6 -> V_8 . V_13 ) ;
if ( V_40 != V_41 )
memcpy ( V_40 , V_41 , V_23 ) ;
F_11 ( V_40 , V_42 , V_23 ) ;
V_26 = F_13 ( V_19 , & V_25 , 0 ) ;
}
return V_26 ;
}
static int F_26 ( struct V_18 * V_19 ,
struct V_20 * V_21 ,
struct V_20 * V_22 , unsigned int V_23 )
{
struct V_16 * V_6 = F_8 ( V_19 -> V_2 ) ;
struct V_24 V_25 ;
int V_26 ;
F_9 ( & V_25 , V_21 , V_22 , V_23 ) ;
V_26 = F_15 ( V_19 , & V_25 , 8 * V_28 ) ;
F_12 ( V_25 . V_31 , V_25 . V_31 , & V_6 -> V_17 ) ;
while ( V_25 . V_23 ) {
F_16 () ;
F_27 ( V_25 . V_22 . V_29 . V_30 , V_25 . V_21 . V_29 . V_30 ,
V_25 . V_23 , & V_6 -> V_8 , V_25 . V_31 ) ;
F_18 () ;
V_26 = F_13 ( V_19 , & V_25 , 0 ) ;
}
return V_26 ;
}
static int F_28 ( struct V_18 * V_19 ,
struct V_20 * V_21 ,
struct V_20 * V_22 , unsigned int V_23 )
{
struct V_16 * V_6 = F_8 ( V_19 -> V_2 ) ;
struct V_24 V_25 ;
int V_26 ;
F_9 ( & V_25 , V_21 , V_22 , V_23 ) ;
V_26 = F_15 ( V_19 , & V_25 , 8 * V_28 ) ;
F_12 ( V_25 . V_31 , V_25 . V_31 , & V_6 -> V_17 ) ;
while ( V_25 . V_23 ) {
F_16 () ;
F_29 ( V_25 . V_22 . V_29 . V_30 , V_25 . V_21 . V_29 . V_30 ,
V_25 . V_23 , & V_6 -> V_12 , V_25 . V_31 ) ;
F_18 () ;
V_26 = F_13 ( V_19 , & V_25 , 0 ) ;
}
return V_26 ;
}
static int T_4 F_30 ( void )
{
if ( ! F_31 () )
return - V_43 ;
return F_32 ( V_44 , F_33 ( V_44 ) ) ;
}
static void T_5 F_34 ( void )
{
F_35 ( V_44 , F_33 ( V_44 ) ) ;
}
