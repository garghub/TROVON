static inline T_1 F_1 ( struct V_1 * V_2 , int V_3 )
{
F_2 ( V_4 ) ;
return F_3 ( V_2 -> V_5 . V_6 + V_3 * V_2 -> V_5 . V_7 ) ;
}
static inline void F_4 ( struct V_1 * V_2 , int V_3 , T_1 V_8 )
{
F_2 ( V_4 ) ;
F_5 ( V_8 , V_2 -> V_5 . V_6 + V_3 * V_2 -> V_5 . V_7 ) ;
}
static inline T_1 F_6 ( struct V_1 * V_2 , T_1 V_3 )
{
F_4 ( V_2 , V_9 , V_3 ) ;
return F_1 ( V_2 , V_10 ) ;
}
static T_1 F_7 ( struct V_1 * V_2 , T_1 V_3 )
{
T_1 V_8 ;
unsigned long V_11 ;
F_8 ( & V_2 -> V_5 . V_12 , V_11 ) ;
V_8 = F_6 ( V_2 , V_3 ) ;
F_9 ( & V_2 -> V_5 . V_12 , V_11 ) ;
return V_8 ;
}
static void F_10 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_8 )
{
F_4 ( V_2 , V_9 , V_3 ) ;
F_4 ( V_2 , V_10 , V_8 ) ;
}
static void F_11 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_8 )
{
unsigned long V_11 ;
F_8 ( & V_2 -> V_5 . V_12 , V_11 ) ;
F_10 ( V_2 , V_3 , V_8 ) ;
F_9 ( & V_2 -> V_5 . V_12 , V_11 ) ;
}
static void F_12 ( struct V_1 * V_2 , T_1 V_13 ,
T_2 * V_14 , T_1 V_15 )
{
unsigned long V_11 ;
int V_16 ;
F_8 ( & V_2 -> V_5 . V_12 , V_11 ) ;
F_4 ( V_2 , V_9 , V_13 ) ;
for ( V_16 = 0 ; V_16 < V_15 ; V_16 ++ )
F_4 ( V_2 , V_10 , F_13 ( * V_14 ++ ) ) ;
F_9 ( & V_2 -> V_5 . V_12 , V_11 ) ;
}
static void F_14 ( struct V_1 * V_2 , T_1 V_13 ,
T_2 * V_14 , T_1 V_15 )
{
unsigned long V_11 ;
int V_16 ;
F_8 ( & V_2 -> V_5 . V_12 , V_11 ) ;
F_4 ( V_2 , V_9 , V_13 ) ;
for ( V_16 = 0 ; V_16 < V_15 ; V_16 ++ )
* V_14 ++ = F_15 ( F_1 ( V_2 , V_10 ) ) ;
F_9 ( & V_2 -> V_5 . V_12 , V_11 ) ;
}
static void F_16 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_17 )
{
T_1 V_8 ;
unsigned long V_11 ;
F_8 ( & V_2 -> V_5 . V_12 , V_11 ) ;
V_8 = F_6 ( V_2 , V_3 ) ;
F_10 ( V_2 , V_3 , V_8 | V_17 ) ;
F_9 ( & V_2 -> V_5 . V_12 , V_11 ) ;
}
static void F_17 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_17 )
{
T_1 V_8 ;
unsigned long V_11 ;
F_8 ( & V_2 -> V_5 . V_12 , V_11 ) ;
V_8 = F_6 ( V_2 , V_3 ) ;
F_10 ( V_2 , V_3 , V_8 & ~ V_17 ) ;
F_9 ( & V_2 -> V_5 . V_12 , V_11 ) ;
}
static T_1 F_18 ( struct V_1 * V_2 )
{
T_1 V_8 ;
unsigned long V_11 ;
F_8 ( & V_2 -> V_5 . V_12 , V_11 ) ;
V_8 = F_1 ( V_2 , V_18 ) ;
F_9 ( & V_2 -> V_5 . V_12 , V_11 ) ;
return V_8 ;
}
static T_1 F_19 ( struct V_1 * V_2 , T_1 V_8 )
{
unsigned long V_11 ;
F_8 ( & V_2 -> V_5 . V_12 , V_11 ) ;
F_4 ( V_2 , V_18 , V_8 ) ;
F_9 ( & V_2 -> V_5 . V_12 , V_11 ) ;
return V_8 ;
}
T_1 F_20 ( struct V_1 * V_2 )
{
T_1 V_8 ;
unsigned long V_11 ;
F_8 ( & V_2 -> V_5 . V_12 , V_11 ) ;
V_8 = F_1 ( V_2 , V_19 ) ;
F_9 ( & V_2 -> V_5 . V_12 , V_11 ) ;
return V_8 ;
}
void F_21 ( struct V_1 * V_2 )
{
int V_16 ;
F_18 ( V_2 ) ;
F_20 ( V_2 ) ;
F_11 ( V_2 , V_20 , 0 ) ;
for ( V_16 = 0 ; V_16 < V_21 ; V_16 ++ ) {
F_11 ( V_2 , F_22 ( V_16 ) , 0 ) ;
F_7 ( V_2 , F_22 ( V_16 ) ) ;
}
}
void F_23 ( struct V_22 * V_23 )
{
F_16 ( V_23 -> V_2 , V_20 ,
F_24 ( V_23 -> V_24 ) ) ;
}
void F_25 ( struct V_22 * V_23 )
{
F_17 ( V_23 -> V_2 , V_20 ,
F_24 ( V_23 -> V_24 ) ) ;
}
static inline int F_26 ( struct V_1 * V_2 )
{
T_1 V_25 ;
V_25 = F_27 ( & V_2 -> V_5 . V_26 . V_27 , 5 * V_28 ) ;
F_28 ( ! V_25 ) ;
return ( V_25 == 0 ) ? - V_29 : 0 ;
}
T_1 F_29 ( struct V_1 * V_2 , int V_24 )
{
T_1 V_30 ;
V_30 = F_7 ( V_2 , F_22 ( V_24 ) ) ;
F_11 ( V_2 , F_22 ( V_24 ) , 0 ) ;
return V_30 ;
}
T_1 F_30 ( struct V_22 * V_23 )
{
return F_7 ( V_23 -> V_2 , F_31 ( V_23 -> V_24 ) ) ;
}
void F_32 ( struct V_22 * V_23 , T_1 V_31 )
{
F_11 ( V_23 -> V_2 , F_33 ( V_23 -> V_24 ) , V_31 ) ;
}
T_1 F_34 ( struct V_22 * V_23 )
{
return F_7 ( V_23 -> V_2 , F_33 ( V_23 -> V_24 ) ) ;
}
static int F_35 ( struct V_1 * V_2 , T_1 V_32 ,
struct V_33 * V_14 )
{
int V_16 , V_34 ;
F_36 ( & V_2 -> V_5 . V_26 . V_35 ) ;
F_11 ( V_2 , V_36 , V_32 ) ;
for ( V_16 = 0 ; V_16 < V_37 ; V_16 ++ )
F_11 ( V_2 , F_37 ( V_16 ) , V_14 -> V_38 [ V_16 ] ) ;
F_19 ( V_2 , V_39 ) ;
V_34 = F_26 ( V_2 ) ;
F_38 ( & V_2 -> V_5 . V_26 . V_35 ) ;
return V_34 ;
}
void F_39 ( struct V_1 * V_2 , T_1 V_8 )
{
F_36 ( & V_2 -> V_5 . V_26 . V_35 ) ;
F_11 ( V_2 , V_40 , V_8 ) ;
F_38 ( & V_2 -> V_5 . V_26 . V_35 ) ;
}
static inline void F_40 ( struct V_22 * V_23 )
{
struct V_1 * V_2 = V_23 -> V_2 ;
struct V_33 V_14 ;
int V_34 ;
V_34 = F_35 ( V_2 , F_41 ( V_23 -> V_24 ) , & V_14 ) ;
F_42 ( V_34 ) ;
}
void F_43 ( struct V_22 * V_23 , int V_41 )
{
struct V_1 * V_2 = V_23 -> V_2 ;
struct V_33 V_14 ;
int V_34 ;
V_14 . V_38 [ 0 ] = 50 ;
V_14 . V_38 [ 1 ] = V_41 | ( V_23 -> V_24 << 1 ) ;
V_34 = F_35 ( V_2 , V_42 , & V_14 ) ;
F_42 ( V_34 ) ;
}
void F_44 ( struct V_22 * V_23 , T_1 V_13 )
{
F_11 ( V_23 -> V_2 , F_45 ( V_23 -> V_24 ) , V_13 ) ;
}
T_1 F_46 ( struct V_22 * V_23 )
{
return F_7 ( V_23 -> V_2 , F_45 ( V_23 -> V_24 ) ) ;
}
T_1 F_47 ( struct V_22 * V_23 )
{
return F_7 ( V_23 -> V_2 , F_48 ( V_23 -> V_24 ) ) ;
}
void F_49 ( struct V_22 * V_23 )
{
F_16 ( V_23 -> V_2 , F_31 ( V_23 -> V_24 ) , V_43 ) ;
F_40 ( V_23 ) ;
F_32 ( V_23 , V_44 ) ;
if ( ! ( F_7 ( V_23 -> V_2 , F_31 ( V_23 -> V_24 ) ) & V_43 ) )
F_50 ( F_51 ( V_23 ) ,
L_1 , V_23 -> V_24 ) ;
}
void F_52 ( struct V_22 * V_23 , int V_41 )
{
F_32 ( V_23 , F_53 ( V_41 ) ) ;
F_16 ( V_23 -> V_2 , V_20 ,
F_54 ( V_23 -> V_24 ) ) ;
F_16 ( V_23 -> V_2 , F_55 ( V_23 -> V_24 ) ,
V_45 | V_46 ) ;
F_16 ( V_23 -> V_2 , F_31 ( V_23 -> V_24 ) , F_56 ( V_41 ) ) ;
}
void F_57 ( struct V_1 * V_2 , T_1 V_47 )
{
if ( ( V_47 & V_48 ) == 0 )
return;
V_2 -> V_5 . V_26 . V_49 = F_18 ( V_2 ) ;
F_58 ( & V_2 -> V_5 . V_26 . V_27 ) ;
}
int F_59 ( struct V_1 * V_2 )
{
int V_34 ;
F_36 ( & V_2 -> V_5 . V_26 . V_35 ) ;
F_19 ( V_2 , V_50 ) ;
V_34 = F_26 ( V_2 ) ;
F_38 ( & V_2 -> V_5 . V_26 . V_35 ) ;
return V_34 ;
}
void F_60 ( struct V_1 * V_2 , T_1 V_13 ,
void * V_14 , int V_51 )
{
T_3 * V_52 = V_14 ;
if ( V_13 + V_51 > 0xffff ) {
F_61 ( & V_2 -> V_53 -> V_2 ,
L_2 ) ;
return;
}
if ( V_13 & 0x01 ) {
T_1 V_54 ;
V_54 = F_7 ( V_2 , V_13 - 1 ) ;
V_54 = ( V_54 & 0x00ff ) | ( * V_52 ++ << 8 ) ;
F_11 ( V_2 , V_13 - 1 , V_54 ) ;
V_13 ++ ;
V_51 -- ;
}
F_12 ( V_2 , V_13 , ( T_2 * ) V_52 , V_51 / 2 ) ;
V_52 += V_51 & ~ 0x01 ;
V_13 += V_51 & ~ 0x01 ;
V_51 &= 0x01 ;
if ( V_51 ) {
T_1 V_54 ;
V_54 = F_7 ( V_2 , V_13 ) ;
V_54 = ( V_54 & 0xff00 ) | * V_52 ;
F_11 ( V_2 , V_13 , V_54 ) ;
}
}
void F_62 ( struct V_1 * V_2 , T_1 V_13 ,
void * V_14 , int V_51 )
{
T_3 * V_52 = V_14 ;
if ( V_13 & 0x01 ) {
T_1 V_54 ;
V_54 = F_7 ( V_2 , V_13 - 1 ) ;
* V_52 ++ = ( V_54 >> 8 ) & 0x00ff ;
V_13 ++ ;
V_51 -- ;
}
F_14 ( V_2 , V_13 , ( T_2 * ) V_52 , V_51 / 2 ) ;
V_52 += V_51 & ~ 0x01 ;
V_13 += V_51 & ~ 0x01 ;
V_51 &= 0x01 ;
if ( V_51 ) {
T_1 V_54 ;
V_54 = F_7 ( V_2 , V_13 ) ;
* V_52 = V_54 & 0x00ff ;
}
}
void F_63 ( struct V_1 * V_2 )
{
F_64 ( & V_2 -> V_5 . V_26 . V_35 ) ;
F_65 ( & V_2 -> V_5 . V_26 . V_27 ) ;
}
void F_66 ( struct V_1 * V_2 )
{
}
