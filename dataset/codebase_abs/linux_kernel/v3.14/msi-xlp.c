static inline int F_1 ( int V_1 , int V_2 )
{
return V_3 + V_1 * V_4 + V_2 ;
}
static inline int F_2 ( int V_5 )
{
return V_5 % V_4 ;
}
static inline int F_3 ( int V_5 )
{
return ( V_5 % ( V_4 * V_6 ) ) /
V_4 ;
}
static inline int F_4 ( int V_1 , int V_7 )
{
return V_8 + V_1 * V_9 + V_7 ;
}
static inline int F_5 ( int V_5 )
{
return V_5 % V_10 ;
}
static inline int F_6 ( int V_5 )
{
return F_5 ( V_5 ) / V_9 ;
}
static void F_7 ( struct V_11 * V_12 )
{
struct V_13 * V_14 = F_8 ( V_12 ) ;
unsigned long V_15 ;
int V_16 ;
V_16 = F_2 ( V_12 -> V_5 ) ;
F_9 ( & V_14 -> V_17 , V_15 ) ;
V_14 -> V_18 |= 1u << V_16 ;
F_10 ( V_14 -> V_19 , V_20 , V_14 -> V_18 ) ;
F_11 ( & V_14 -> V_17 , V_15 ) ;
}
static void F_12 ( struct V_11 * V_12 )
{
struct V_13 * V_14 = F_8 ( V_12 ) ;
unsigned long V_15 ;
int V_16 ;
V_16 = F_2 ( V_12 -> V_5 ) ;
F_9 ( & V_14 -> V_17 , V_15 ) ;
V_14 -> V_18 &= ~ ( 1u << V_16 ) ;
F_10 ( V_14 -> V_19 , V_20 , V_14 -> V_18 ) ;
F_11 ( & V_14 -> V_17 , V_15 ) ;
}
static void F_13 ( struct V_11 * V_12 )
{
struct V_13 * V_14 = F_8 ( V_12 ) ;
int V_1 , V_16 ;
V_1 = F_3 ( V_12 -> V_5 ) ;
V_16 = F_2 ( V_12 -> V_5 ) ;
F_12 ( V_12 ) ;
F_10 ( V_14 -> V_19 , V_21 , 1u << V_16 ) ;
F_14 ( F_15 ( V_1 ) ) ;
F_16 ( V_14 -> V_22 -> V_23 , F_17 ( V_1 ) ) ;
}
static void F_18 ( struct V_11 * V_12 )
{
struct V_13 * V_14 = F_8 ( V_12 ) ;
int V_1 , V_24 ;
V_24 = F_5 ( V_12 -> V_5 ) ;
V_1 = F_6 ( V_12 -> V_5 ) ;
F_19 ( V_12 ) ;
F_10 ( V_14 -> V_19 , V_25 , 1u << V_24 ) ;
F_14 ( F_20 ( V_1 ) ) ;
F_16 ( V_14 -> V_22 -> V_23 , F_21 ( V_24 ) ) ;
}
void F_22 ( unsigned int V_5 )
{
}
void F_23 ( unsigned int V_5 )
{
F_22 ( V_5 ) ;
}
static void F_24 ( T_1 V_19 , int V_26 , T_1 V_27 )
{
T_2 V_28 ;
V_28 = F_25 ( V_19 , V_29 ) ;
if ( ( V_28 & 0x200 ) == 0 ) {
V_28 |= 0x200 ;
F_10 ( V_19 , V_29 , V_28 ) ;
}
V_28 = F_25 ( V_19 , 0x1 ) ;
if ( ( V_28 & 0x0400 ) == 0 ) {
V_28 |= 0x0400 ;
F_10 ( V_19 , 0x1 , V_28 ) ;
}
V_28 = F_26 ( V_19 , 0xf ) ;
V_28 &= ~ 0x1fu ;
V_28 |= ( 1 << 8 ) | V_26 ;
F_27 ( V_19 , 0xf , V_28 ) ;
F_10 ( V_19 , V_30 , V_27 >> 32 ) ;
F_10 ( V_19 , V_31 , V_27 & 0xffffffff ) ;
V_28 = F_25 ( V_19 , V_32 ) ;
if ( ( V_28 & ( 1 << 16 ) ) == 0 ) {
V_28 |= 0xb << 16 ;
F_10 ( V_19 , V_32 , V_28 ) ;
}
}
static int F_28 ( T_1 V_19 , int V_22 , int V_1 ,
struct V_33 * V_34 )
{
struct V_13 * V_14 ;
struct V_35 V_36 ;
unsigned long V_15 ;
int V_2 , V_37 , V_26 , V_38 , V_39 ;
T_1 V_27 ;
V_26 = F_15 ( V_1 ) ;
V_38 = F_29 ( V_22 , F_1 ( V_1 , 0 ) ) ;
V_14 = F_30 ( V_38 ) ;
V_27 = F_31 ( V_22 , V_1 ) ;
F_9 ( & V_14 -> V_17 , V_15 ) ;
if ( V_14 -> V_40 == 0 ) {
F_24 ( V_19 , V_26 , V_27 ) ;
V_37 = F_17 ( V_1 ) ;
F_32 ( V_22 , V_26 , V_26 , V_37 ) ;
F_33 ( F_34 ( V_22 ) -> V_23 , V_37 , V_26 ,
V_22 * F_35 () , 1 ) ;
}
V_2 = F_36 ( V_14 -> V_40 ) ;
if ( V_2 == V_4 ) {
F_11 ( & V_14 -> V_17 , V_15 ) ;
return - V_41 ;
}
V_14 -> V_40 |= ( 1u << V_2 ) ;
F_11 ( & V_14 -> V_17 , V_15 ) ;
V_36 . V_42 = V_27 >> 32 ;
V_36 . V_43 = V_27 & 0xffffffff ;
V_36 . V_44 = 0xc00 | V_2 ;
V_38 = V_38 + V_2 ;
V_39 = F_37 ( V_38 , V_34 ) ;
if ( V_39 < 0 ) {
F_22 ( V_38 ) ;
return V_39 ;
}
F_38 ( V_38 , & V_36 ) ;
return 0 ;
}
static void F_39 ( T_1 V_19 , int V_26 , T_1 V_45 )
{
T_2 V_28 ;
V_28 = F_25 ( V_19 , 0x2C ) ;
if ( ( V_28 & 0x80000000U ) == 0 ) {
V_28 |= 0x80000000U ;
F_10 ( V_19 , 0x2C , V_28 ) ;
}
V_28 = F_25 ( V_19 , V_29 ) ;
if ( ( V_28 & 0x200 ) == 0 ) {
V_28 |= 0x200 ;
F_10 ( V_19 , V_29 , V_28 ) ;
}
V_28 = F_25 ( V_19 , 0x1 ) ;
if ( ( V_28 & 0x0400 ) == 0 ) {
V_28 |= 0x0400 ;
F_10 ( V_19 , 0x1 , V_28 ) ;
}
V_28 = F_26 ( V_19 , 0xf ) ;
V_28 &= ~ 0x1fu ;
V_28 |= ( 1 << 8 ) | V_26 ;
F_27 ( V_19 , 0xf , V_28 ) ;
F_10 ( V_19 , V_46 , V_45 >> 8 ) ;
F_10 ( V_19 , V_47 ,
( V_45 + V_48 ) >> 8 ) ;
}
static int F_40 ( T_1 V_19 , int V_22 , int V_1 ,
struct V_33 * V_34 )
{
struct V_13 * V_14 ;
struct V_35 V_36 ;
unsigned long V_15 ;
int V_49 , V_24 , V_26 , V_38 , V_39 ;
T_1 V_45 ;
V_26 = F_20 ( V_1 ) ;
V_38 = F_29 ( V_22 , F_4 ( V_1 , 0 ) ) ;
V_14 = F_30 ( V_38 ) ;
V_45 = F_41 ( V_22 , V_1 ) ;
F_9 ( & V_14 -> V_17 , V_15 ) ;
if ( V_14 -> V_50 == 0 )
F_39 ( V_19 , V_26 , V_45 ) ;
V_49 = F_36 ( V_14 -> V_50 ) ;
if ( V_49 == V_9 ) {
F_11 ( & V_14 -> V_17 , V_15 ) ;
return - V_41 ;
}
V_14 -> V_50 |= ( 1u << V_49 ) ;
F_11 ( & V_14 -> V_17 , V_15 ) ;
V_38 += V_49 ;
V_24 = F_5 ( V_38 ) ;
V_36 . V_42 = V_45 >> 32 ;
V_36 . V_43 = V_45 & 0xffffffff ;
V_36 . V_44 = 0xc00 | V_24 ;
V_39 = F_37 ( V_38 , V_34 ) ;
if ( V_39 < 0 ) {
F_22 ( V_38 ) ;
return V_39 ;
}
F_38 ( V_38 , & V_36 ) ;
return 0 ;
}
int F_42 ( struct V_51 * V_52 , struct V_33 * V_34 )
{
struct V_51 * V_53 ;
T_1 V_19 ;
int V_22 , V_1 , V_54 ;
V_53 = F_43 ( V_52 ) ;
if ( V_53 == NULL ) {
F_44 ( & V_52 -> V_52 , L_1 ) ;
return 1 ;
}
V_54 = F_45 ( V_53 -> V_55 ) ;
V_1 = F_46 ( V_53 -> V_55 ) ;
V_22 = V_54 / 8 ;
V_19 = F_47 ( V_22 , V_1 ) ;
if ( V_34 -> V_56 . V_57 )
return F_40 ( V_19 , V_22 , V_1 , V_34 ) ;
else
return F_28 ( V_19 , V_22 , V_1 , V_34 ) ;
}
void T_3 F_48 ( int V_22 , int V_1 )
{
struct V_58 * V_59 ;
struct V_13 * V_14 ;
int V_5 , V_60 , V_37 , V_24 ;
F_49 ( L_2 , V_22 , V_1 ) ;
V_59 = F_34 ( V_22 ) ;
V_14 = F_50 ( sizeof( * V_14 ) , V_61 ) ;
F_51 ( & V_14 -> V_17 ) ;
V_14 -> V_18 = 0 ;
V_14 -> V_40 = 0 ;
V_14 -> V_50 = 0 ;
V_14 -> V_22 = V_59 ;
V_14 -> V_19 = F_47 ( V_22 , V_1 ) ;
V_5 = F_29 ( V_22 , F_1 ( V_1 , 0 ) ) ;
for ( V_60 = V_5 ; V_60 < V_5 + V_4 ; V_60 ++ ) {
F_52 ( V_60 , & V_62 , V_63 ) ;
F_53 ( V_60 , V_14 ) ;
}
for ( V_60 = 0 ; V_60 < V_9 ; V_60 ++ ) {
V_24 = V_1 * V_9 + V_60 ;
V_37 = F_21 ( V_24 ) ;
F_33 ( V_59 -> V_23 , V_37 , F_20 ( V_1 ) ,
V_22 * F_35 () , 1 ) ;
V_5 = F_29 ( V_22 , F_4 ( V_1 , V_60 ) ) ;
F_52 ( V_5 , & V_64 , V_63 ) ;
F_53 ( V_5 , V_14 ) ;
}
}
void F_54 ( int V_22 , int V_26 )
{
struct V_13 * V_14 ;
int V_1 , V_60 , V_65 ;
T_2 V_66 ;
V_1 = V_26 - V_67 ;
V_65 = F_29 ( V_22 , F_1 ( V_1 , 0 ) ) ;
V_14 = F_30 ( V_65 ) ;
V_66 = F_25 ( V_14 -> V_19 , V_21 ) &
V_14 -> V_18 ;
while ( V_66 ) {
V_60 = F_55 ( V_66 ) ;
F_56 ( V_65 + V_60 ) ;
V_66 &= V_66 - 1 ;
}
}
void F_57 ( int V_22 , int V_26 )
{
struct V_13 * V_14 ;
int V_1 , V_60 , V_65 ;
T_2 V_66 ;
V_1 = V_26 - V_68 ;
V_65 = F_29 ( V_22 , F_4 ( V_1 , 0 ) ) ;
V_14 = F_30 ( V_65 ) ;
V_66 = F_25 ( V_14 -> V_19 , V_25 ) ;
V_66 = ( V_66 >> ( V_1 * V_9 ) ) &
( ( 1 << V_9 ) - 1 ) ;
while ( V_66 ) {
V_60 = F_55 ( V_66 ) ;
F_56 ( V_65 + V_60 ) ;
V_66 &= V_66 - 1 ;
}
}
