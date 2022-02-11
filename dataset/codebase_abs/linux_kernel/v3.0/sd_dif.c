static T_1 F_1 ( void * V_1 , unsigned int V_2 )
{
return F_2 ( F_3 ( V_1 , V_2 ) ) ;
}
static T_1 F_4 ( void * V_1 , unsigned int V_2 )
{
return F_5 ( V_1 , V_2 ) ;
}
static void F_6 ( struct V_3 * V_4 , T_2 * V_5 )
{
void * V_6 = V_4 -> V_7 ;
struct V_8 * V_9 = V_4 -> V_10 ;
T_3 V_11 = V_4 -> V_11 ;
unsigned int V_12 ;
for ( V_12 = 0 ; V_12 < V_4 -> V_13 ; V_12 += V_4 -> V_14 , V_9 ++ ) {
V_9 -> V_15 = V_5 ( V_6 , V_4 -> V_14 ) ;
V_9 -> V_16 = F_7 ( V_11 & 0xffffffff ) ;
V_9 -> V_17 = 0 ;
V_6 += V_4 -> V_14 ;
V_11 ++ ;
}
}
static void F_8 ( struct V_3 * V_4 )
{
F_6 ( V_4 , F_1 ) ;
}
static void F_9 ( struct V_3 * V_4 )
{
F_6 ( V_4 , F_4 ) ;
}
static int F_10 ( struct V_3 * V_4 , T_2 * V_5 )
{
void * V_6 = V_4 -> V_7 ;
struct V_8 * V_9 = V_4 -> V_10 ;
T_3 V_11 = V_4 -> V_11 ;
unsigned int V_12 ;
T_1 V_18 ;
for ( V_12 = 0 ; V_12 < V_4 -> V_13 ; V_12 += V_4 -> V_14 , V_9 ++ ) {
if ( V_9 -> V_17 == 0xffff )
return 0 ;
if ( V_9 -> V_16 == 0xffffffff ) {
F_11 ( V_19
L_1 ,
V_4 -> V_20 , ( unsigned long ) V_11 ) ;
return - V_21 ;
}
if ( F_12 ( V_9 -> V_16 ) != ( V_11 & 0xffffffff ) ) {
F_11 ( V_19
L_2 ,
V_4 -> V_20 , ( unsigned long ) V_11 ,
F_12 ( V_9 -> V_16 ) ) ;
return - V_21 ;
}
V_18 = V_5 ( V_6 , V_4 -> V_14 ) ;
if ( V_9 -> V_15 != V_18 ) {
F_11 ( V_19 L_3 \
L_4 , V_4 -> V_20 ,
( unsigned long ) V_11 ,
F_13 ( V_9 -> V_15 ) , F_13 ( V_18 ) ) ;
return - V_21 ;
}
V_6 += V_4 -> V_14 ;
V_11 ++ ;
}
return 0 ;
}
static int F_14 ( struct V_3 * V_4 )
{
return F_10 ( V_4 , F_1 ) ;
}
static int F_15 ( struct V_3 * V_4 )
{
return F_10 ( V_4 , F_4 ) ;
}
static void F_16 ( void * V_22 , void * V_23 , unsigned int V_24 )
{
struct V_8 * V_9 = V_22 ;
T_4 * V_25 = V_23 ;
unsigned int V_12 , V_26 ;
for ( V_12 = 0 , V_26 = 0 ; V_12 < V_24 ; V_12 ++ , V_26 += 2 , V_9 ++ ) {
V_9 -> V_17 = V_25 [ V_26 ] << 8 | V_25 [ V_26 + 1 ] ;
F_17 ( V_9 -> V_17 == 0xffff ) ;
}
}
static void F_18 ( void * V_22 , void * V_23 , unsigned int V_24 )
{
struct V_8 * V_9 = V_22 ;
T_4 * V_25 = V_23 ;
unsigned int V_12 , V_26 ;
for ( V_12 = 0 , V_26 = 0 ; V_12 < V_24 ; V_12 ++ , V_26 += 2 , V_9 ++ ) {
V_25 [ V_26 ] = ( V_9 -> V_17 & 0xff00 ) >> 8 ;
V_25 [ V_26 + 1 ] = V_9 -> V_17 & 0xff ;
}
}
static void F_19 ( struct V_3 * V_4 , T_2 * V_5 )
{
void * V_6 = V_4 -> V_7 ;
struct V_8 * V_9 = V_4 -> V_10 ;
unsigned int V_12 ;
for ( V_12 = 0 ; V_12 < V_4 -> V_13 ; V_12 += V_4 -> V_14 , V_9 ++ ) {
V_9 -> V_15 = V_5 ( V_6 , V_4 -> V_14 ) ;
V_9 -> V_16 = 0 ;
V_9 -> V_17 = 0 ;
V_6 += V_4 -> V_14 ;
}
}
static void F_20 ( struct V_3 * V_4 )
{
F_19 ( V_4 , F_1 ) ;
}
static void F_21 ( struct V_3 * V_4 )
{
F_19 ( V_4 , F_4 ) ;
}
static int F_22 ( struct V_3 * V_4 , T_2 * V_5 )
{
void * V_6 = V_4 -> V_7 ;
struct V_8 * V_9 = V_4 -> V_10 ;
T_3 V_11 = V_4 -> V_11 ;
unsigned int V_12 ;
T_1 V_18 ;
for ( V_12 = 0 ; V_12 < V_4 -> V_13 ; V_12 += V_4 -> V_14 , V_9 ++ ) {
if ( V_9 -> V_17 == 0xffff && V_9 -> V_16 == 0xffffffff )
return 0 ;
V_18 = V_5 ( V_6 , V_4 -> V_14 ) ;
if ( V_9 -> V_15 != V_18 ) {
F_11 ( V_19 L_3 \
L_4 , V_4 -> V_20 ,
( unsigned long ) V_11 ,
F_13 ( V_9 -> V_15 ) , F_13 ( V_18 ) ) ;
return - V_21 ;
}
V_6 += V_4 -> V_14 ;
V_11 ++ ;
}
return 0 ;
}
static int F_23 ( struct V_3 * V_4 )
{
return F_22 ( V_4 , F_1 ) ;
}
static int F_24 ( struct V_3 * V_4 )
{
return F_22 ( V_4 , F_4 ) ;
}
static void F_25 ( void * V_22 , void * V_23 , unsigned int V_24 )
{
struct V_8 * V_9 = V_22 ;
T_4 * V_25 = V_23 ;
unsigned int V_12 , V_26 ;
for ( V_12 = 0 , V_26 = 0 ; V_12 < V_24 ; V_12 ++ , V_26 += 6 , V_9 ++ ) {
V_9 -> V_17 = V_25 [ V_26 ] << 8 | V_25 [ V_26 + 1 ] ;
V_9 -> V_16 = V_25 [ V_26 + 2 ] << 24 | V_25 [ V_26 + 3 ] << 16 |
V_25 [ V_26 + 4 ] << 8 | V_25 [ V_26 + 5 ] ;
}
}
static void F_26 ( void * V_22 , void * V_23 , unsigned int V_24 )
{
struct V_8 * V_9 = V_22 ;
T_4 * V_25 = V_23 ;
unsigned int V_12 , V_26 ;
for ( V_12 = 0 , V_26 = 0 ; V_12 < V_24 ; V_12 ++ , V_26 += 2 , V_9 ++ ) {
V_25 [ V_26 ] = ( V_9 -> V_17 & 0xff00 ) >> 8 ;
V_25 [ V_26 + 1 ] = V_9 -> V_17 & 0xff ;
V_25 [ V_26 + 2 ] = ( V_9 -> V_16 & 0xff000000 ) >> 24 ;
V_25 [ V_26 + 3 ] = ( V_9 -> V_16 & 0xff0000 ) >> 16 ;
V_25 [ V_26 + 4 ] = ( V_9 -> V_16 & 0xff00 ) >> 8 ;
V_25 [ V_26 + 5 ] = V_9 -> V_16 & 0xff ;
F_17 ( V_9 -> V_17 == 0xffff || V_9 -> V_16 == 0xffffffff ) ;
}
}
void F_27 ( struct V_27 * V_28 )
{
struct V_29 * V_30 = V_28 -> V_31 ;
struct V_32 * V_33 = V_28 -> V_33 ;
T_4 type = V_28 -> V_34 ;
int V_35 , V_36 ;
V_35 = F_28 ( V_30 -> V_37 , type ) ;
V_36 = F_29 ( V_30 -> V_37 , type ) ;
if ( ! V_36 && F_29 ( V_30 -> V_37 , 0 ) ) {
V_35 = 0 ; V_36 = 1 ;
}
if ( ! V_36 )
return;
if ( F_30 ( V_28 -> V_31 -> V_37 ) & V_38 )
if ( type == V_39 )
F_31 ( V_33 , & V_40 ) ;
else
F_31 ( V_33 , & V_41 ) ;
else
if ( type == V_39 )
F_31 ( V_33 , & V_42 ) ;
else
F_31 ( V_33 , & V_43 ) ;
F_32 ( V_44 , V_28 ,
L_5 , V_33 -> V_45 -> V_46 ) ;
if ( V_35 && type && V_28 -> V_47 ) {
if ( type == V_39 )
V_33 -> V_45 -> V_48 = sizeof( V_49 ) + sizeof( V_50 ) ;
else
V_33 -> V_45 -> V_48 = sizeof( V_49 ) ;
F_32 ( V_44 , V_28 , L_6 ,
V_33 -> V_45 -> V_48 ) ;
}
}
int F_33 ( struct V_51 * V_52 , T_3 V_53 , unsigned int V_54 )
{
const int V_55 = sizeof( struct V_8 ) ;
struct V_56 * V_56 ;
struct V_27 * V_28 ;
struct V_8 * V_9 ;
unsigned int V_12 , V_26 ;
V_50 V_57 , V_58 ;
V_28 = V_52 -> V_56 -> V_59 -> V_60 -> V_61 ;
if ( V_28 -> V_34 == V_39 )
return 0 ;
V_57 = V_53 & 0xffffffff ;
F_34 (bio, rq) {
struct V_62 * V_63 ;
if ( F_35 ( V_56 , V_64 ) )
break;
V_58 = V_56 -> V_65 -> V_66 & 0xffffffff ;
F_36 (iv, bio->bi_integrity, i) {
V_9 = F_37 ( V_63 -> V_67 , V_68 )
+ V_63 -> V_69 ;
for ( V_26 = 0 ; V_26 < V_63 -> V_70 ; V_26 += V_55 , V_9 ++ ) {
if ( F_12 ( V_9 -> V_16 ) != V_58 )
goto error;
V_9 -> V_16 = F_7 ( V_57 ) ;
V_58 ++ ;
V_57 ++ ;
}
F_38 ( V_9 , V_68 ) ;
}
V_56 -> V_71 |= V_64 ;
}
return 0 ;
error:
F_38 ( V_9 , V_68 ) ;
F_32 ( V_19 , V_28 , L_7 ,
V_72 , V_58 , V_57 , F_12 ( V_9 -> V_16 ) ,
F_13 ( V_9 -> V_17 ) ) ;
return - V_73 ;
}
void F_39 ( struct V_74 * V_75 , unsigned int V_76 )
{
const int V_55 = sizeof( struct V_8 ) ;
struct V_27 * V_28 ;
struct V_56 * V_56 ;
struct V_8 * V_9 ;
unsigned int V_12 , V_26 , V_24 , V_54 ;
V_50 V_57 , V_58 ;
V_28 = V_27 ( V_75 -> V_51 -> V_77 ) ;
if ( V_28 -> V_34 == V_39 || V_76 == 0 )
return;
V_54 = V_75 -> V_31 -> V_14 ;
V_24 = V_76 / V_54 ;
V_57 = F_40 ( V_75 -> V_51 ) & 0xffffffff ;
if ( V_54 == 4096 )
V_57 >>= 3 ;
F_34 (bio, scmd->request) {
struct V_62 * V_63 ;
V_58 = V_56 -> V_65 -> V_66 & 0xffffffff ;
F_36 (iv, bio->bi_integrity, i) {
V_9 = F_37 ( V_63 -> V_67 , V_68 )
+ V_63 -> V_69 ;
for ( V_26 = 0 ; V_26 < V_63 -> V_70 ; V_26 += V_55 , V_9 ++ ) {
if ( V_24 == 0 ) {
F_38 ( V_9 , V_68 ) ;
return;
}
if ( F_12 ( V_9 -> V_16 ) != V_57 &&
V_9 -> V_17 != 0xffff )
V_9 -> V_16 = 0xffffffff ;
else
V_9 -> V_16 = F_7 ( V_58 ) ;
V_58 ++ ;
V_57 ++ ;
V_24 -- ;
}
F_38 ( V_9 , V_68 ) ;
}
}
}
