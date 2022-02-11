static T_1 F_1 ( unsigned long V_1 )
{
T_1 V_2 = F_2 ( V_1 ) ;
return V_2 ;
}
static void F_3 ( unsigned long V_1 , T_1 V_3 )
{
F_4 ( V_3 , V_1 ) ;
}
static void F_5 ( unsigned long V_4 )
{
int V_5 = 0 ;
F_3 ( V_4 , 0x70 ) ;
while ( ( ( F_1 ( V_4 + 1 ) & 0x80 ) == 0 )
&& ( V_5 < V_6 ) ) {
V_5 ++ ;
}
F_3 ( V_4 , 0x74 ) ;
V_5 = 0 ;
while ( ( ( F_1 ( V_4 + 1 ) & 0x80 ) == 0x80 )
&& ( V_5 < V_6 ) ) {
V_5 ++ ;
}
F_3 ( V_4 , 0x70 ) ;
V_5 = 0 ;
while ( ( ( F_1 ( V_4 + 1 ) & 0x80 ) == 0x0 )
&& ( V_5 < V_6 ) ) {
V_5 ++ ;
}
F_3 ( V_4 , 0x0 ) ;
V_5 = 0 ;
while ( ( ( F_1 ( V_4 + 1 ) & 0x80 ) == 0x80 )
&& ( V_5 < V_6 ) ) {
V_5 ++ ;
}
}
static void F_6 ( unsigned long V_4 , unsigned V_7 , int V_8 )
{
unsigned V_9 ;
union V_10 V_11 ;
int V_5 = 0 ;
unsigned V_12 ;
V_11 . V_13 = V_8 ;
if ( V_11 . V_13 > 498 )
V_11 . V_13 = 498 ;
if ( V_11 . V_13 < 2 )
V_11 . V_13 = 2 ;
if ( V_7 == 0 ) {
V_9 = 0x28 ;
} else {
V_9 = 0x30 ;
}
F_3 ( V_4 , V_9 + V_11 . V_14 . V_15 ) ;
V_12 = F_1 ( V_4 + 1 ) ;
while ( ( ( V_12 & 0x80 ) == 0 ) && ( V_5 < V_6 ) ) {
V_12 = F_1 ( V_4 + 1 ) ;
V_5 ++ ;
}
F_3 ( V_4 , V_9 + V_11 . V_14 . V_16 + 0x4 ) ;
V_5 = 0 ;
V_12 = F_1 ( V_4 + 1 ) ;
while ( ( ( V_12 & 0x80 ) == 0x80 ) && ( V_5 < V_6 ) ) {
V_12 = F_1 ( V_4 + 1 ) ;
V_5 ++ ;
}
F_3 ( V_4 , V_9 + V_11 . V_14 . V_17 ) ;
V_12 = F_1 ( V_4 + 1 ) ;
while ( ( ( V_12 & 0x80 ) == 0 ) && ( V_5 < V_6 ) ) {
V_12 = F_1 ( V_4 + 1 ) ;
V_5 ++ ;
}
F_3 ( V_4 , V_9 + V_11 . V_14 . V_18 + 0x4 ) ;
V_5 = 0 ;
V_12 = F_1 ( V_4 + 1 ) ;
while ( ( ( V_12 & 0x80 ) == 0x80 ) && ( V_5 < V_6 ) ) {
V_12 = F_1 ( V_4 + 1 ) ;
V_5 ++ ;
}
F_3 ( V_4 , V_9 + V_11 . V_14 . V_19 ) ;
V_12 = F_1 ( V_4 + 1 ) ;
while ( ( ( V_12 & 0x80 ) == 0 ) && ( V_5 < V_6 ) ) {
V_12 = F_1 ( V_4 + 1 ) ;
V_5 ++ ;
}
F_3 ( V_4 , 0x0 ) ;
V_5 = 0 ;
V_12 = F_1 ( V_4 + 1 ) ;
while ( ( ( V_12 & 0x80 ) == 0x80 ) && ( V_5 < V_6 ) ) {
V_12 = F_1 ( V_4 + 1 ) ;
V_5 ++ ;
}
}
static int F_7 ( unsigned long V_4 , unsigned V_7 )
{
unsigned V_9 ;
union V_20 V_21 ;
int V_5 = 0 ;
int V_12 ;
V_21 . V_8 = 0 ;
if ( V_7 == 0 )
V_9 = 0x48 ;
else
V_9 = 0x50 ;
F_3 ( V_4 , V_9 ) ;
V_12 = F_1 ( V_4 + 1 ) ;
while ( ( ( V_12 & 0x80 ) == 0 ) && ( V_5 < V_6 ) ) {
V_12 = F_1 ( V_4 + 1 ) ;
V_5 ++ ;
}
V_21 . V_14 . V_15 = ( ( F_1 ( V_4 + 1 ) >> 3 ) & 0x7 ) ;
F_3 ( V_4 , V_9 + 0x4 ) ;
V_5 = 0 ;
V_12 = F_1 ( V_4 + 1 ) ;
while ( ( ( V_12 & 0x80 ) == 0x80 ) && ( V_5 < V_6 ) ) {
V_12 = F_1 ( V_4 + 1 ) ;
V_5 ++ ;
}
V_21 . V_14 . V_16 = ( ( F_1 ( V_4 + 1 ) >> 3 ) & 0x7 ) ;
F_3 ( V_4 , V_9 ) ;
V_5 = 0 ;
V_12 = F_1 ( V_4 + 1 ) ;
while ( ( ( V_12 & 0x80 ) == 0 ) && ( V_5 < V_6 ) ) {
V_12 = F_1 ( V_4 + 1 ) ;
V_5 ++ ;
}
V_21 . V_14 . V_17 = ( ( F_1 ( V_4 + 1 ) >> 3 ) & 0x7 ) ;
F_3 ( V_4 , V_9 + 0x4 ) ;
V_5 = 0 ;
V_12 = F_1 ( V_4 + 1 ) ;
while ( ( ( V_12 & 0x80 ) == 0x80 ) && ( V_5 < V_6 ) ) {
V_12 = F_1 ( V_4 + 1 ) ;
V_5 ++ ;
}
V_21 . V_14 . V_18 = ( ( F_1 ( V_4 + 1 ) >> 3 ) & 0x7 ) ;
F_3 ( V_4 , V_9 ) ;
V_5 = 0 ;
V_12 = F_1 ( V_4 + 1 ) ;
while ( ( ( V_12 & 0x80 ) == 0 ) && ( V_5 < V_6 ) ) {
V_12 = F_1 ( V_4 + 1 ) ;
V_5 ++ ;
}
V_21 . V_14 . V_19 = ( ( F_1 ( V_4 + 1 ) >> 3 ) & 0x7 ) ;
F_3 ( V_4 , V_9 + 0x4 ) ;
V_5 = 0 ;
V_12 = F_1 ( V_4 + 1 ) ;
while ( ( ( V_12 & 0x80 ) == 0x80 ) && ( V_5 < V_6 ) ) {
V_12 = F_1 ( V_4 + 1 ) ;
V_5 ++ ;
}
V_21 . V_14 . V_22 = ( ( F_1 ( V_4 + 1 ) >> 3 ) & 0x7 ) ;
F_3 ( V_4 , V_9 ) ;
V_5 = 0 ;
V_12 = F_1 ( V_4 + 1 ) ;
while ( ( ( V_12 & 0x80 ) == 0x0 ) && ( V_5 < V_6 ) ) {
V_12 = F_1 ( V_4 + 1 ) ;
V_5 ++ ;
}
V_21 . V_14 . V_23 = ( ( F_1 ( V_4 + 1 ) >> 3 ) & 0x7 ) ;
F_3 ( V_4 , V_9 + 0x4 ) ;
V_5 = 0 ;
V_12 = F_1 ( V_4 + 1 ) ;
while ( ( ( V_12 & 0x80 ) == 0x80 ) && ( V_5 < V_6 ) ) {
V_12 = F_1 ( V_4 + 1 ) ;
V_5 ++ ;
}
V_21 . V_14 . V_24 = ( ( F_1 ( V_4 + 1 ) >> 3 ) & 0x7 ) ;
F_3 ( V_4 , V_9 ) ;
V_5 = 0 ;
V_12 = F_1 ( V_4 + 1 ) ;
while ( ( ( V_12 & 0x80 ) == 0x0 ) && ( V_5 < V_6 ) ) {
V_12 = F_1 ( V_4 + 1 ) ;
V_5 ++ ;
}
F_3 ( V_4 , 0x0 ) ;
V_5 = 0 ;
V_12 = F_1 ( V_4 + 1 ) ;
while ( ( ( V_12 & 0x80 ) == 0x80 ) && ( V_5 < V_6 ) ) {
V_12 = F_1 ( V_4 + 1 ) ;
V_5 ++ ;
}
return V_21 . V_8 ^ 0x800000 ;
}
static void F_8 ( unsigned long V_4 )
{
unsigned V_5 = 0 ;
F_3 ( V_4 , 0x68 ) ;
while ( ( ( F_1 ( V_4 + 1 ) & 0x80 ) == 0 )
&& ( V_5 < V_6 ) ) {
V_5 ++ ;
}
F_3 ( V_4 , 0x6C ) ;
V_5 = 0 ;
while ( ( ( F_1 ( V_4 + 1 ) & 0x80 ) == 0x80 )
&& ( V_5 < V_6 ) ) {
V_5 ++ ;
}
F_3 ( V_4 , 0x68 ) ;
V_5 = 0 ;
while ( ( ( F_1 ( V_4 + 1 ) & 0x80 ) == 0x0 )
&& ( V_5 < V_6 ) ) {
V_5 ++ ;
}
F_3 ( V_4 , 0x0 ) ;
V_5 = 0 ;
while ( ( ( F_1 ( V_4 + 1 ) & 0x80 ) == 0x80 )
&& ( V_5 < V_6 ) ) {
V_5 ++ ;
}
}
static int F_9 ( struct V_25 * V_26 ,
struct V_27 * V_28 ,
struct V_29 * V_30 , unsigned int * V_31 )
{
F_10 ( V_32 L_1 , V_30 -> V_33 ) ;
return V_30 -> V_33 ;
}
static int F_11 ( struct V_25 * V_26 ,
struct V_27 * V_28 ,
struct V_29 * V_30 ,
unsigned int * V_31 )
{
int V_34 ;
int V_35 = F_12 ( V_30 -> V_36 ) ;
for ( V_34 = 0 ; V_34 < V_30 -> V_33 ; V_34 ++ ) {
F_6 ( V_26 -> V_37 , V_35 , V_31 [ V_34 ] ) ;
}
return V_34 ;
}
static int F_13 ( struct V_25 * V_26 ,
struct V_27 * V_28 ,
struct V_29 * V_30 , unsigned int * V_31 )
{
int V_33 ;
int V_35 = F_12 ( V_30 -> V_36 ) ;
for ( V_33 = 0 ; V_33 < V_30 -> V_33 ; V_33 ++ )
V_31 [ V_33 ] = ( F_7 ( V_26 -> V_37 , V_35 ) & 0xffffff ) ;
return V_33 ;
}
static void F_14 ( struct V_25 * V_26 )
{
F_5 ( V_26 -> V_37 ) ;
F_8 ( V_26 -> V_37 ) ;
}
static int F_15 ( struct V_25 * V_26 ,
struct V_38 * V_39 )
{
int V_2 = 0 ;
unsigned long V_37 ;
unsigned int V_40 ;
struct V_27 * V_28 ;
V_37 = V_39 -> V_41 [ 0 ] ;
F_10 ( V_32 L_2 , V_26 -> V_42 , V_37 ) ;
if ( ! F_16 ( V_37 , V_43 , L_3 ) ) {
F_10 ( V_44 L_4 , V_26 -> V_42 ) ;
return - V_45 ;
}
V_26 -> V_37 = V_37 ;
V_26 -> V_46 = L_3 ;
V_2 = F_17 ( V_26 , 2 ) ;
if ( V_2 < 0 )
return V_2 ;
F_18 ( & V_47 ) ;
V_40 = V_39 -> V_41 [ 1 ] ;
if ( V_40 > 0 )
F_10 ( V_32 L_5 ,
V_26 -> V_42 , V_40 ) ;
else if ( V_40 == 0 )
F_10 ( V_32 L_6 , V_26 -> V_42 ) ;
V_28 = V_26 -> V_48 + 0 ;
V_28 -> type = V_49 ;
V_28 -> V_50 = V_51 ;
V_28 -> V_52 = 2 ;
V_28 -> V_53 = F_9 ;
V_28 -> V_54 = F_11 ;
V_28 -> V_55 = 500 ;
V_28 -> V_56 = & V_57 ;
V_28 = V_26 -> V_48 + 1 ;
V_28 -> type = V_58 ;
V_28 -> V_50 = V_59 | V_60 ;
V_28 -> V_52 = 2 ;
V_28 -> V_53 = F_13 ;
V_28 -> V_55 = 0xffffff ;
V_28 -> V_56 = & V_61 ;
F_14 ( V_26 ) ;
return 0 ;
}
static int F_19 ( struct V_25 * V_26 )
{
F_10 ( V_32 L_7 , V_26 -> V_42 ) ;
if ( V_26 -> V_37 )
F_20 ( V_26 -> V_37 , V_43 ) ;
if ( V_26 -> V_40 )
F_21 ( V_26 -> V_40 , V_26 ) ;
F_22 ( & V_47 ) ;
return 0 ;
}
static int T_2 F_23 ( void )
{
return F_24 ( & V_62 ) ;
}
static void T_3 F_25 ( void )
{
F_26 ( & V_62 ) ;
}
