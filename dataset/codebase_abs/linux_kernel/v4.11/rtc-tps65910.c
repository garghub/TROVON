static int F_1 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_6 ) ;
T_1 V_7 = 0 ;
if ( V_3 )
V_7 = V_8 ;
return F_3 ( V_5 -> V_9 , V_10 , V_7 ) ;
}
static int F_4 ( struct V_1 * V_2 , struct V_11 * V_12 )
{
unsigned char V_13 [ V_14 ] ;
struct V_4 * V_5 = F_2 ( V_2 -> V_6 ) ;
int V_15 ;
V_15 = F_5 ( V_5 -> V_9 , V_16 ,
V_17 , V_17 ) ;
if ( V_15 < 0 ) {
F_6 ( V_2 , L_1 , V_15 ) ;
return V_15 ;
}
V_15 = F_7 ( V_5 -> V_9 , V_18 , V_13 ,
V_14 ) ;
if ( V_15 < 0 ) {
F_6 ( V_2 , L_2 , V_15 ) ;
return V_15 ;
}
V_12 -> V_19 = F_8 ( V_13 [ 0 ] ) ;
V_12 -> V_20 = F_8 ( V_13 [ 1 ] ) ;
V_12 -> V_21 = F_8 ( V_13 [ 2 ] ) ;
V_12 -> V_22 = F_8 ( V_13 [ 3 ] ) ;
V_12 -> V_23 = F_8 ( V_13 [ 4 ] ) - 1 ;
V_12 -> V_24 = F_8 ( V_13 [ 5 ] ) + 100 ;
return V_15 ;
}
static int F_9 ( struct V_1 * V_2 , struct V_11 * V_12 )
{
unsigned char V_13 [ V_14 ] ;
struct V_4 * V_5 = F_2 ( V_2 -> V_6 ) ;
int V_15 ;
V_13 [ 0 ] = F_10 ( V_12 -> V_19 ) ;
V_13 [ 1 ] = F_10 ( V_12 -> V_20 ) ;
V_13 [ 2 ] = F_10 ( V_12 -> V_21 ) ;
V_13 [ 3 ] = F_10 ( V_12 -> V_22 ) ;
V_13 [ 4 ] = F_10 ( V_12 -> V_23 + 1 ) ;
V_13 [ 5 ] = F_10 ( V_12 -> V_24 - 100 ) ;
V_15 = F_5 ( V_5 -> V_9 , V_16 ,
V_25 , 0 ) ;
if ( V_15 < 0 ) {
F_6 ( V_2 , L_3 , V_15 ) ;
return V_15 ;
}
V_15 = F_11 ( V_5 -> V_9 , V_18 , V_13 ,
V_14 ) ;
if ( V_15 < 0 ) {
F_6 ( V_2 , L_4 , V_15 ) ;
return V_15 ;
}
V_15 = F_5 ( V_5 -> V_9 , V_16 ,
V_25 , 1 ) ;
if ( V_15 < 0 )
F_6 ( V_2 , L_5 , V_15 ) ;
return V_15 ;
}
static int F_12 ( struct V_1 * V_2 , struct V_26 * V_27 )
{
unsigned char V_28 [ V_14 ] ;
T_2 V_29 ;
struct V_4 * V_5 = F_2 ( V_2 -> V_6 ) ;
int V_15 ;
V_15 = F_7 ( V_5 -> V_9 , V_18 , V_28 ,
V_14 ) ;
if ( V_15 < 0 ) {
F_6 ( V_2 , L_6 , V_15 ) ;
return V_15 ;
}
V_27 -> time . V_19 = F_8 ( V_28 [ 0 ] ) ;
V_27 -> time . V_20 = F_8 ( V_28 [ 1 ] ) ;
V_27 -> time . V_21 = F_8 ( V_28 [ 2 ] ) ;
V_27 -> time . V_22 = F_8 ( V_28 [ 3 ] ) ;
V_27 -> time . V_23 = F_8 ( V_28 [ 4 ] ) - 1 ;
V_27 -> time . V_24 = F_8 ( V_28 [ 5 ] ) + 100 ;
V_15 = F_13 ( V_5 -> V_9 , V_10 , & V_29 ) ;
if ( V_15 < 0 )
return V_15 ;
if ( V_29 & V_8 )
V_27 -> V_3 = 1 ;
return V_15 ;
}
static int F_14 ( struct V_1 * V_2 , struct V_26 * V_27 )
{
unsigned char V_28 [ V_14 ] ;
struct V_4 * V_5 = F_2 ( V_2 -> V_6 ) ;
int V_15 ;
V_15 = F_1 ( V_2 , 0 ) ;
if ( V_15 )
return V_15 ;
V_28 [ 0 ] = F_10 ( V_27 -> time . V_19 ) ;
V_28 [ 1 ] = F_10 ( V_27 -> time . V_20 ) ;
V_28 [ 2 ] = F_10 ( V_27 -> time . V_21 ) ;
V_28 [ 3 ] = F_10 ( V_27 -> time . V_22 ) ;
V_28 [ 4 ] = F_10 ( V_27 -> time . V_23 + 1 ) ;
V_28 [ 5 ] = F_10 ( V_27 -> time . V_24 - 100 ) ;
V_15 = F_11 ( V_5 -> V_9 , V_30 ,
V_28 , V_14 ) ;
if ( V_15 ) {
F_6 ( V_2 , L_7 , V_15 ) ;
return V_15 ;
}
if ( V_27 -> V_3 )
V_15 = F_1 ( V_2 , 1 ) ;
return V_15 ;
}
static int F_15 ( struct V_1 * V_2 , int V_31 )
{
unsigned char V_32 [ V_33 ] ;
struct V_4 * V_5 = F_2 ( V_2 -> V_6 ) ;
T_3 V_34 ;
int V_15 ;
if ( ( V_31 < - 32768 ) || ( V_31 > 32766 ) ) {
F_6 ( V_2 , L_8 ,
V_31 ) ;
return - V_35 ;
}
V_34 = ( T_3 ) V_31 ;
V_32 [ 0 ] = ( V_36 ) V_34 & 0xFF ;
V_32 [ 1 ] = ( ( V_36 ) V_34 >> 8 ) & 0xFF ;
V_15 = F_11 ( V_5 -> V_9 , V_37 ,
V_32 , V_33 ) ;
if ( V_15 < 0 ) {
F_6 ( V_2 , L_9 , V_15 ) ;
return V_15 ;
}
V_15 = F_5 ( V_5 -> V_9 , V_16 ,
V_38 , V_38 ) ;
if ( V_15 < 0 )
F_6 ( V_2 , L_10 , V_15 ) ;
return V_15 ;
}
static int F_16 ( struct V_1 * V_2 , int * V_31 )
{
unsigned char V_32 [ V_33 ] ;
struct V_4 * V_5 = F_2 ( V_2 -> V_6 ) ;
unsigned int V_39 ;
V_36 V_34 ;
int V_15 ;
V_15 = F_13 ( V_5 -> V_9 , V_16 , & V_39 ) ;
if ( V_15 < 0 )
return V_15 ;
if ( ! ( V_39 & V_38 ) ) {
* V_31 = 0 ;
return 0 ;
}
V_15 = F_7 ( V_5 -> V_9 , V_37 , V_32 ,
V_33 ) ;
if ( V_15 < 0 ) {
F_6 ( V_2 , L_11 , V_15 ) ;
return V_15 ;
}
V_34 = ( V_36 ) V_32 [ 0 ] | ( ( V_36 ) V_32 [ 1 ] << 8 ) ;
* V_31 = ( T_3 ) V_34 ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 , long * V_40 )
{
int V_31 ;
T_4 V_41 ;
int V_15 ;
V_15 = F_16 ( V_2 , & V_31 ) ;
if ( V_15 < 0 )
return V_15 ;
V_41 = V_31 * ( T_4 ) V_42 ;
if ( V_41 < 0 )
V_41 -= V_43 / 2LL ;
else
V_41 += V_43 / 2LL ;
V_41 = F_18 ( V_41 , V_43 ) ;
* V_40 = ( long ) - V_41 ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 , long V_40 )
{
int V_31 ;
T_4 V_41 ;
int V_15 ;
if ( V_40 < V_44 || V_40 > V_45 )
return - V_46 ;
V_41 = V_40 * ( T_4 ) V_43 ;
if ( V_41 < 0 )
V_41 -= V_42 / 2LL ;
else
V_41 += V_42 / 2LL ;
V_41 = F_18 ( V_41 , V_42 ) ;
V_31 = ( int ) - V_41 ;
V_15 = F_15 ( V_2 , V_31 ) ;
return V_15 ;
}
static T_5 F_20 ( int V_47 , void * V_48 )
{
struct V_1 * V_2 = V_48 ;
unsigned long V_49 = 0 ;
struct V_4 * V_5 = F_2 ( V_2 -> V_6 ) ;
struct V_50 * V_51 = F_2 ( V_2 ) ;
int V_15 ;
T_2 V_52 ;
V_15 = F_13 ( V_5 -> V_9 , V_53 , & V_52 ) ;
if ( V_15 )
return V_54 ;
if ( V_52 & V_55 )
V_49 = V_56 | V_57 ;
V_15 = F_3 ( V_5 -> V_9 , V_53 , V_52 ) ;
if ( V_15 )
return V_54 ;
F_21 ( V_51 -> V_48 , 1 , V_49 ) ;
return V_58 ;
}
static int F_22 ( struct V_59 * V_60 )
{
struct V_4 * V_4 = NULL ;
struct V_50 * V_51 = NULL ;
int V_15 ;
int V_47 ;
T_2 V_52 ;
V_4 = F_2 ( V_60 -> V_2 . V_6 ) ;
V_51 = F_23 ( & V_60 -> V_2 , sizeof( struct V_50 ) ,
V_61 ) ;
if ( ! V_51 )
return - V_62 ;
V_15 = F_13 ( V_4 -> V_9 , V_53 , & V_52 ) ;
if ( V_15 < 0 )
return V_15 ;
V_15 = F_3 ( V_4 -> V_9 , V_53 , V_52 ) ;
if ( V_15 < 0 )
return V_15 ;
F_24 ( & V_60 -> V_2 , L_12 ) ;
V_15 = F_5 ( V_4 -> V_9 , V_63 ,
V_64 , 0 << V_65 ) ;
if ( V_15 < 0 )
return V_15 ;
V_52 = V_25 ;
V_15 = F_3 ( V_4 -> V_9 , V_16 , V_52 ) ;
if ( V_15 < 0 )
return V_15 ;
F_25 ( V_60 , V_51 ) ;
V_47 = F_26 ( V_60 , 0 ) ;
if ( V_47 <= 0 ) {
F_27 ( & V_60 -> V_2 , L_13 ,
V_47 ) ;
return - V_66 ;
}
V_15 = F_28 ( & V_60 -> V_2 , V_47 , NULL ,
F_20 , V_67 ,
F_29 ( & V_60 -> V_2 ) , & V_60 -> V_2 ) ;
if ( V_15 < 0 ) {
F_6 ( & V_60 -> V_2 , L_14 ) ;
return V_15 ;
}
V_51 -> V_47 = V_47 ;
F_30 ( & V_60 -> V_2 , 1 ) ;
V_51 -> V_48 = F_31 ( & V_60 -> V_2 , V_60 -> V_68 ,
& V_69 , V_70 ) ;
if ( F_32 ( V_51 -> V_48 ) ) {
V_15 = F_33 ( V_51 -> V_48 ) ;
F_6 ( & V_60 -> V_2 , L_15 , V_15 ) ;
return V_15 ;
}
return 0 ;
}
static int F_34 ( struct V_59 * V_60 )
{
F_1 ( & V_60 -> V_2 , 0 ) ;
return 0 ;
}
static int F_35 ( struct V_1 * V_2 )
{
struct V_50 * V_51 = F_2 ( V_2 ) ;
if ( F_36 ( V_2 ) )
F_37 ( V_51 -> V_47 ) ;
return 0 ;
}
static int F_38 ( struct V_1 * V_2 )
{
struct V_50 * V_51 = F_2 ( V_2 ) ;
if ( F_36 ( V_2 ) )
F_39 ( V_51 -> V_47 ) ;
return 0 ;
}
