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
int V_17 ;
V_17 = F_7 ( V_2 , V_3 , V_4 ) ;
if ( V_17 )
return V_17 ;
if ( F_3 ( V_3 , V_7 , & V_6 -> V_8 . V_13 ) ) {
V_2 -> V_9 |= V_10 ;
return - V_11 ;
}
V_6 -> V_12 . V_13 = V_6 -> V_8 . V_13 ;
F_4 ( V_3 , V_7 , & V_6 -> V_12 . V_13 ) ;
F_3 ( V_3 + V_4 / 2 , V_7 , & V_6 -> V_18 ) ;
V_6 -> V_8 . V_14 = V_6 -> V_12 . V_14 = 0 ;
return 0 ;
}
static int F_8 ( struct V_19 * V_20 ,
struct V_21 * V_22 ,
struct V_21 * V_23 , unsigned int V_24 )
{
struct V_5 * V_6 = F_9 ( V_20 -> V_2 ) ;
struct V_25 V_26 ;
int V_17 ;
F_10 ( & V_26 , V_22 , V_23 , V_24 ) ;
V_17 = F_11 ( V_20 , & V_26 ) ;
while ( V_26 . V_24 ) {
T_2 V_27 = V_26 . V_24 / V_28 ;
T_1 * V_23 = V_26 . V_23 . V_29 . V_30 ;
if ( V_26 . V_22 . V_29 . V_30 == V_26 . V_23 . V_29 . V_30 ) {
T_1 * V_31 = V_26 . V_31 ;
do {
F_12 ( V_23 , V_31 , V_28 ) ;
F_13 ( V_23 , V_23 , & V_6 -> V_8 ) ;
V_31 = V_23 ;
V_23 += V_28 ;
} while ( -- V_27 );
memcpy ( V_26 . V_31 , V_31 , V_28 ) ;
} else {
T_1 * V_22 = V_26 . V_22 . V_29 . V_30 ;
do {
F_12 ( V_26 . V_31 , V_23 , V_28 ) ;
F_13 ( V_26 . V_31 , V_22 , & V_6 -> V_8 ) ;
memcpy ( V_26 . V_31 , V_22 , V_28 ) ;
V_23 += V_28 ;
V_22 += V_28 ;
} while ( -- V_27 );
}
V_17 = F_14 ( V_20 , & V_26 , V_26 . V_24 % V_28 ) ;
}
return V_17 ;
}
static int F_15 ( struct V_19 * V_20 ,
struct V_21 * V_22 ,
struct V_21 * V_23 , unsigned int V_24 )
{
struct V_5 * V_6 = F_9 ( V_20 -> V_2 ) ;
struct V_25 V_26 ;
int V_17 ;
F_10 ( & V_26 , V_22 , V_23 , V_24 ) ;
V_17 = F_16 ( V_20 , & V_26 , 8 * V_28 ) ;
while ( ( V_26 . V_24 / V_28 ) >= 8 ) {
F_17 () ;
F_18 ( V_26 . V_23 . V_29 . V_30 , V_26 . V_22 . V_29 . V_30 ,
V_26 . V_24 , & V_6 -> V_12 , V_26 . V_31 ) ;
F_19 () ;
V_17 = F_14 ( V_20 , & V_26 , V_26 . V_24 % V_28 ) ;
}
while ( V_26 . V_24 ) {
T_2 V_27 = V_26 . V_24 / V_28 ;
T_1 * V_22 = V_26 . V_22 . V_29 . V_30 ;
T_1 * V_23 = V_26 . V_23 . V_29 . V_30 ;
T_1 V_32 [ 2 ] [ V_28 ] ;
T_1 * V_31 = V_26 . V_31 ;
do {
if ( V_26 . V_22 . V_29 . V_30 == V_26 . V_23 . V_29 . V_30 )
memcpy ( V_32 [ V_27 & 1 ] , V_23 , V_28 ) ;
F_20 ( V_23 , V_22 , & V_6 -> V_12 . V_13 ) ;
F_12 ( V_22 , V_31 , V_28 ) ;
if ( V_26 . V_22 . V_29 . V_30 == V_26 . V_23 . V_29 . V_30 )
V_31 = V_32 [ V_27 & 1 ] ;
else
V_31 = V_23 ;
V_22 += V_28 ;
V_23 += V_28 ;
} while ( -- V_27 );
V_17 = F_14 ( V_20 , & V_26 , V_26 . V_24 % V_28 ) ;
}
return V_17 ;
}
static void F_21 ( T_3 V_33 [] , T_2 V_34 )
{
int V_35 ;
for ( V_35 = 3 ; V_35 >= 0 ; V_35 -- , V_34 = 1 ) {
T_2 V_36 = F_22 ( V_33 [ V_35 ] ) + V_34 ;
V_33 [ V_35 ] = F_23 ( V_36 ) ;
if ( V_36 >= V_34 )
break;
}
}
static int F_24 ( struct V_19 * V_20 ,
struct V_21 * V_22 , struct V_21 * V_23 ,
unsigned int V_24 )
{
struct V_15 * V_6 = F_9 ( V_20 -> V_2 ) ;
struct V_25 V_26 ;
T_2 V_27 ;
int V_17 ;
F_10 ( & V_26 , V_22 , V_23 , V_24 ) ;
V_17 = F_16 ( V_20 , & V_26 , 8 * V_28 ) ;
while ( ( V_27 = V_26 . V_24 / V_28 ) ) {
T_2 V_37 = V_26 . V_24 % V_28 ;
T_3 * V_33 = ( T_3 * ) V_26 . V_31 ;
T_2 V_38 = V_39 - F_22 ( V_33 [ 3 ] ) ;
if ( F_25 ( V_38 < V_27 ) ) {
V_27 = V_38 + 1 ;
V_37 = V_26 . V_24 - V_27 * V_28 ;
}
F_17 () ;
F_26 ( V_26 . V_23 . V_29 . V_30 ,
V_26 . V_22 . V_29 . V_30 , V_27 ,
& V_6 -> V_8 , V_26 . V_31 ) ;
F_19 () ;
F_21 ( V_33 , V_27 ) ;
V_24 -= V_27 * V_28 ;
if ( V_24 && V_24 == V_37 && V_24 <= V_28 )
break;
V_17 = F_14 ( V_20 , & V_26 , V_37 ) ;
}
if ( V_26 . V_24 ) {
T_1 * V_40 = V_26 . V_22 . V_29 . V_30 + V_27 * V_28 ;
T_1 * V_41 = V_26 . V_23 . V_29 . V_30 + V_27 * V_28 ;
T_1 V_42 [ V_28 ] ;
F_13 ( V_26 . V_31 , V_42 , & V_6 -> V_8 . V_13 ) ;
if ( V_40 != V_41 )
memcpy ( V_40 , V_41 , V_24 ) ;
F_12 ( V_40 , V_42 , V_24 ) ;
V_17 = F_14 ( V_20 , & V_26 , 0 ) ;
}
return V_17 ;
}
static int F_27 ( struct V_19 * V_20 ,
struct V_21 * V_22 ,
struct V_21 * V_23 , unsigned int V_24 )
{
struct V_16 * V_6 = F_9 ( V_20 -> V_2 ) ;
struct V_25 V_26 ;
int V_17 ;
F_10 ( & V_26 , V_22 , V_23 , V_24 ) ;
V_17 = F_16 ( V_20 , & V_26 , 8 * V_28 ) ;
F_13 ( V_26 . V_31 , V_26 . V_31 , & V_6 -> V_18 ) ;
while ( V_26 . V_24 ) {
F_17 () ;
F_28 ( V_26 . V_23 . V_29 . V_30 , V_26 . V_22 . V_29 . V_30 ,
V_26 . V_24 , & V_6 -> V_8 , V_26 . V_31 ) ;
F_19 () ;
V_17 = F_14 ( V_20 , & V_26 , V_26 . V_24 % V_28 ) ;
}
return V_17 ;
}
static int F_29 ( struct V_19 * V_20 ,
struct V_21 * V_22 ,
struct V_21 * V_23 , unsigned int V_24 )
{
struct V_16 * V_6 = F_9 ( V_20 -> V_2 ) ;
struct V_25 V_26 ;
int V_17 ;
F_10 ( & V_26 , V_22 , V_23 , V_24 ) ;
V_17 = F_16 ( V_20 , & V_26 , 8 * V_28 ) ;
F_13 ( V_26 . V_31 , V_26 . V_31 , & V_6 -> V_18 ) ;
while ( V_26 . V_24 ) {
F_17 () ;
F_30 ( V_26 . V_23 . V_29 . V_30 , V_26 . V_22 . V_29 . V_30 ,
V_26 . V_24 , & V_6 -> V_12 , V_26 . V_31 ) ;
F_19 () ;
V_17 = F_14 ( V_20 , & V_26 , V_26 . V_24 % V_28 ) ;
}
return V_17 ;
}
static int T_4 F_31 ( void )
{
if ( ! F_32 () )
return - V_43 ;
return F_33 ( V_44 , F_34 ( V_44 ) ) ;
}
static void T_5 F_35 ( void )
{
F_36 ( V_44 , F_34 ( V_44 ) ) ;
}
