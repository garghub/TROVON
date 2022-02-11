static int F_1 ( struct V_1 * V_2 )
{
return 6 + V_2 -> V_3 / 4 ;
}
static int F_2 ( struct V_4 * V_5 , const T_1 * V_6 ,
unsigned int V_7 )
{
struct V_1 * V_2 = F_3 ( V_5 ) ;
int V_8 ;
V_8 = F_4 ( V_2 , V_6 , V_7 ) ;
if ( ! V_8 )
return 0 ;
V_5 -> V_9 . V_10 |= V_11 ;
return - V_12 ;
}
static int F_5 ( struct V_4 * V_5 , unsigned int V_13 )
{
if ( ( V_13 & 1 ) || V_13 < 4 )
return - V_12 ;
return 0 ;
}
static int F_6 ( struct V_14 * V_15 , T_1 V_16 [] , T_2 V_17 )
{
struct V_4 * V_18 = F_7 ( V_15 ) ;
T_3 * V_19 = ( T_3 * ) & V_16 [ V_20 - 8 ] ;
T_2 V_21 = V_15 -> V_22 [ 0 ] + 1 ;
if ( V_21 < 2 || V_21 > 8 )
return - V_12 ;
if ( V_21 < 4 && V_17 > > ( 8 * V_21 ) )
return - V_23 ;
V_19 [ 0 ] = 0 ;
V_19 [ 1 ] = F_8 ( V_17 ) ;
memcpy ( V_16 , V_15 -> V_22 , V_20 - V_21 ) ;
V_16 [ 0 ] |= ( F_9 ( V_18 ) - 2 ) << 2 ;
if ( V_15 -> V_24 )
V_16 [ 0 ] |= 0x40 ;
memset ( & V_15 -> V_22 [ V_20 - V_21 ] , 0 , V_21 ) ;
return 0 ;
}
static void F_10 ( struct V_1 * V_25 , T_1 V_26 [] , T_1 const V_27 [] ,
T_2 V_28 , T_2 * V_29 , bool V_30 )
{
if ( F_11 ( V_30 ) ) {
F_12 ( V_26 , V_27 , V_28 , V_29 , V_25 -> V_31 ,
F_1 ( V_25 ) ) ;
} else {
if ( * V_29 > 0 && * V_29 < V_20 ) {
int V_32 = F_13 ( V_28 , V_20 - * V_29 ) ;
F_14 ( & V_26 [ * V_29 ] , V_27 , V_32 ) ;
* V_29 += V_32 ;
V_27 += V_32 ;
V_28 -= V_32 ;
}
while ( V_28 > V_20 ) {
F_15 ( V_25 -> V_31 , V_26 , V_26 ,
F_1 ( V_25 ) ) ;
F_14 ( V_26 , V_27 , V_20 ) ;
V_27 += V_20 ;
V_28 -= V_20 ;
}
if ( V_28 > 0 ) {
F_15 ( V_25 -> V_31 , V_26 , V_26 ,
F_1 ( V_25 ) ) ;
F_14 ( V_26 , V_27 , V_28 ) ;
* V_29 = V_28 ;
} else {
* V_29 = 0 ;
}
}
}
static void F_16 ( struct V_14 * V_15 , T_1 V_26 [] ,
bool V_30 )
{
struct V_4 * V_18 = F_7 ( V_15 ) ;
struct V_1 * V_2 = F_3 ( V_18 ) ;
struct V_33 { T_4 V_21 ; T_3 V_34 ; T_5 V_35 ; } V_36 ;
struct V_37 V_38 ;
T_2 V_35 = V_15 -> V_24 ;
T_2 V_29 = 0 ;
if ( V_35 < 0xff00 ) {
V_36 . V_21 = F_17 ( V_35 ) ;
V_36 . V_35 = 2 ;
} else {
V_36 . V_21 = F_17 ( 0xfffe ) ;
F_18 ( V_35 , & V_36 . V_34 ) ;
V_36 . V_35 = 6 ;
}
F_10 ( V_2 , V_26 , ( T_1 * ) & V_36 , V_36 . V_35 , & V_29 , V_30 ) ;
F_19 ( & V_38 , V_15 -> V_39 ) ;
do {
T_2 V_19 = F_20 ( & V_38 , V_35 ) ;
T_1 * V_40 ;
if ( ! V_19 ) {
F_19 ( & V_38 , F_21 ( V_38 . V_41 ) ) ;
V_19 = F_20 ( & V_38 , V_35 ) ;
}
V_40 = F_22 ( & V_38 ) ;
F_10 ( V_2 , V_26 , V_40 , V_19 , & V_29 , V_30 ) ;
V_35 -= V_19 ;
F_23 ( V_40 ) ;
F_24 ( & V_38 , V_19 ) ;
F_25 ( & V_38 , 0 , V_35 ) ;
} while ( V_35 );
}
static int F_26 ( struct V_42 * V_38 , T_1 V_26 [] , T_1 V_43 [] ,
struct V_1 * V_2 , bool V_44 )
{
T_1 V_45 [ V_20 ] ;
int V_46 = 0 ;
while ( V_38 -> V_47 ) {
int V_48 = V_38 -> V_47 / V_20 ;
T_2 V_49 = V_38 -> V_47 % V_20 ;
T_1 * V_50 = V_38 -> V_50 . V_51 . V_52 ;
T_1 * V_39 = V_38 -> V_39 . V_51 . V_52 ;
T_2 V_47 = V_38 -> V_47 ;
if ( V_47 == V_38 -> V_53 && V_49 > 0 ) {
V_48 ++ ;
V_49 = 0 ;
}
do {
T_2 V_54 = V_20 ;
if ( V_47 < V_20 )
V_54 = V_47 ;
F_27 ( V_38 -> V_22 , V_20 ) ;
F_15 ( V_2 -> V_31 , V_45 , V_38 -> V_22 ,
F_1 ( V_2 ) ) ;
F_15 ( V_2 -> V_31 , V_26 , V_26 ,
F_1 ( V_2 ) ) ;
if ( V_44 )
F_14 ( V_26 , V_39 , V_54 ) ;
F_28 ( V_50 , V_39 , V_45 , V_54 ) ;
if ( ! V_44 )
F_14 ( V_26 , V_50 , V_54 ) ;
V_50 += V_54 ;
V_39 += V_54 ;
V_47 -= V_54 ;
} while ( -- V_48 );
V_46 = F_29 ( V_38 , V_49 ) ;
}
if ( ! V_46 ) {
F_15 ( V_2 -> V_31 , V_45 , V_43 , F_1 ( V_2 ) ) ;
F_15 ( V_2 -> V_31 , V_26 , V_26 , F_1 ( V_2 ) ) ;
F_14 ( V_26 , V_45 , V_20 ) ;
}
return V_46 ;
}
static int F_30 ( struct V_14 * V_15 )
{
struct V_4 * V_18 = F_7 ( V_15 ) ;
struct V_1 * V_2 = F_3 ( V_18 ) ;
struct V_42 V_38 ;
T_1 V_55 ( 8 ) V_26 [ V_20 ] ;
T_1 V_45 [ V_20 ] ;
T_2 V_35 = V_15 -> V_56 ;
bool V_30 = F_31 () ;
int V_46 ;
V_46 = F_6 ( V_15 , V_26 , V_35 ) ;
if ( V_46 )
return V_46 ;
if ( F_11 ( V_30 ) )
F_32 () ;
if ( V_15 -> V_24 )
F_16 ( V_15 , V_26 , V_30 ) ;
memcpy ( V_45 , V_15 -> V_22 , V_20 ) ;
V_46 = F_33 ( & V_38 , V_15 , true ) ;
if ( F_11 ( V_30 ) ) {
while ( V_38 . V_47 ) {
T_2 V_49 = V_38 . V_47 % V_20 ;
if ( V_38 . V_47 == V_38 . V_53 )
V_49 = 0 ;
F_34 ( V_38 . V_50 . V_51 . V_52 ,
V_38 . V_39 . V_51 . V_52 ,
V_38 . V_47 - V_49 , V_2 -> V_31 ,
F_1 ( V_2 ) , V_26 , V_38 . V_22 ) ;
V_46 = F_29 ( & V_38 , V_49 ) ;
}
if ( ! V_46 )
F_35 ( V_26 , V_45 , V_2 -> V_31 ,
F_1 ( V_2 ) ) ;
F_36 () ;
} else {
V_46 = F_26 ( & V_38 , V_26 , V_45 , V_2 , true ) ;
}
if ( V_46 )
return V_46 ;
F_37 ( V_26 , V_15 -> V_50 , V_15 -> V_24 + V_15 -> V_56 ,
F_9 ( V_18 ) , 1 ) ;
return 0 ;
}
static int F_38 ( struct V_14 * V_15 )
{
struct V_4 * V_18 = F_7 ( V_15 ) ;
struct V_1 * V_2 = F_3 ( V_18 ) ;
unsigned int V_13 = F_9 ( V_18 ) ;
struct V_42 V_38 ;
T_1 V_55 ( 8 ) V_26 [ V_20 ] ;
T_1 V_45 [ V_20 ] ;
T_2 V_35 = V_15 -> V_56 - V_13 ;
bool V_30 = F_31 () ;
int V_46 ;
V_46 = F_6 ( V_15 , V_26 , V_35 ) ;
if ( V_46 )
return V_46 ;
if ( F_11 ( V_30 ) )
F_32 () ;
if ( V_15 -> V_24 )
F_16 ( V_15 , V_26 , V_30 ) ;
memcpy ( V_45 , V_15 -> V_22 , V_20 ) ;
V_46 = F_39 ( & V_38 , V_15 , true ) ;
if ( F_11 ( V_30 ) ) {
while ( V_38 . V_47 ) {
T_2 V_49 = V_38 . V_47 % V_20 ;
if ( V_38 . V_47 == V_38 . V_53 )
V_49 = 0 ;
F_40 ( V_38 . V_50 . V_51 . V_52 ,
V_38 . V_39 . V_51 . V_52 ,
V_38 . V_47 - V_49 , V_2 -> V_31 ,
F_1 ( V_2 ) , V_26 , V_38 . V_22 ) ;
V_46 = F_29 ( & V_38 , V_49 ) ;
}
if ( ! V_46 )
F_35 ( V_26 , V_45 , V_2 -> V_31 ,
F_1 ( V_2 ) ) ;
F_36 () ;
} else {
V_46 = F_26 ( & V_38 , V_26 , V_45 , V_2 , false ) ;
}
if ( V_46 )
return V_46 ;
F_37 ( V_45 , V_15 -> V_39 ,
V_15 -> V_24 + V_15 -> V_56 - V_13 ,
V_13 , 0 ) ;
if ( F_41 ( V_26 , V_45 , V_13 ) )
return - V_57 ;
return 0 ;
}
static int T_6 F_42 ( void )
{
if ( ! ( V_58 & V_59 ) )
return - V_60 ;
return F_43 ( & V_61 ) ;
}
static void T_7 F_44 ( void )
{
F_45 ( & V_61 ) ;
}
