static void F_1 ( T_1 * V_1 , const T_1 * V_2 , T_2 V_3 , bool V_4 )
{
static const unsigned V_5 [ 8 ] = { 0 , 1 , 5 , 4 , 2 , 3 , 6 , 7 } ;
unsigned V_6 = 0 ;
while ( V_3 >= ( V_4 ? 4 : 2 ) ) {
unsigned V_7 = V_5 [ V_6 ] * 4 ;
T_2 V_8 = V_2 [ V_7 + 1 ] + ( V_2 [ V_7 + 2 ] << 8 ) +
( V_2 [ V_7 + 3 ] << 16 ) ;
if ( V_4 ) {
* V_1 ++ = 0 ;
* V_1 ++ = V_8 & 0xff ;
}
* V_1 ++ = ( V_8 >> 8 ) & 0xff ;
* V_1 ++ = ( V_8 >> 16 ) & 0xff ;
V_3 -= V_4 ? 4 : 2 ;
V_6 ++ ;
}
}
static void F_2 ( struct V_9 * V_10 ,
T_1 * V_11 ,
T_3 V_12 ,
T_3 V_13 )
{
struct V_14 * V_15 ;
struct V_16 * V_17 ;
unsigned long V_18 ;
unsigned int V_19 ;
unsigned int V_20 ;
int V_21 = V_13 ;
int V_22 = 0 ;
bool V_4 ;
F_3 ( L_1 , V_10 ,
V_11 , V_13 ) ;
V_15 = V_10 -> V_23 ;
if ( V_15 == NULL ) {
F_3 ( L_2 ) ;
return;
}
V_17 = V_15 -> V_17 ;
if ( V_17 == NULL ) {
F_3 ( L_3 ) ;
return;
}
V_4 = V_17 -> V_24 == V_25 ;
V_20 = V_17 -> V_26 >> 3 ;
if ( V_20 == 0 ) {
F_3 ( L_4 ) ;
return;
}
if ( V_21 == 0 ) {
F_3 ( L_5 , V_27 ) ;
return;
}
if ( V_17 -> V_28 == NULL ) {
F_3 ( L_6 ) ;
return;
}
V_19 = V_10 -> V_29 ;
if ( V_19 + V_21 >= V_17 -> V_30 ) {
unsigned int V_31 = V_17 -> V_30 - V_19 ;
unsigned V_32 ;
for ( V_32 = 0 ; V_32 < V_31 ; V_32 ++ )
F_1 ( V_17 -> V_28 + ( V_19 + V_32 ) * V_20 ,
V_11 + V_32 * V_12 ,
V_20 , V_4 ) ;
for ( V_32 = V_31 ; V_32 < V_21 ; V_32 ++ )
F_1 ( V_17 -> V_28 + ( V_32 - V_31 ) * V_20 ,
V_11 + V_32 * V_12 , V_20 , V_4 ) ;
} else {
unsigned V_32 ;
for ( V_32 = 0 ; V_32 < V_21 ; V_32 ++ )
F_1 ( V_17 -> V_28 + ( V_19 + V_32 ) * V_20 ,
V_11 + V_32 * V_12 ,
V_20 , V_4 ) ;
}
F_4 ( V_15 , V_18 ) ;
V_10 -> V_29 += V_21 ;
if ( V_10 -> V_29 >=
V_17 -> V_30 )
V_10 -> V_29 -=
V_17 -> V_30 ;
V_10 -> V_33 += V_21 ;
if ( V_10 -> V_33 >=
V_17 -> V_34 ) {
V_10 -> V_33 -=
V_17 -> V_34 ;
V_22 = 1 ;
}
F_5 ( V_15 , V_18 ) ;
if ( V_22 )
F_6 ( V_15 ) ;
}
static int F_7 ( struct V_35 * V_36 , void * V_37 )
{
struct V_38 * V_39 = V_37 ;
unsigned char * V_40 = F_8 ( V_36 , 0 ) ;
int V_32 ;
if ( V_41 ) {
F_9 ( L_7 ) ;
for ( V_32 = 0 ; V_32 < 8 * 4 ; V_32 ++ ) {
if ( ! ( V_32 & 3 ) )
F_10 ( L_8 ) ;
F_10 ( L_9 , V_40 [ V_32 ] ) ;
}
F_10 ( L_10 ) ;
}
F_2 ( V_39 -> V_42 ,
F_8 ( V_36 , 0 ) ,
8 * 4 ,
F_11 ( V_36 , 0 ) / ( 8 * 4 ) ) ;
return 0 ;
}
static int F_12 ( struct V_14 * V_15 )
{
struct V_16 * V_17 = V_15 -> V_17 ;
struct V_9 * V_10 = F_13 ( V_15 ) ;
struct V_38 * V_39 = V_10 -> V_39 ;
V_17 -> V_43 = V_44 ;
F_14 ( V_17 , V_45 ) ;
V_10 -> V_23 = V_15 ;
V_17 -> V_46 = V_39 ;
V_10 -> V_47 ++ ;
if ( V_10 -> V_47 == 1 ) {
int V_48 ;
V_48 = F_15 ( & V_39 -> V_49 , F_7 , V_39 , V_39 -> V_50 . V_51 ) ;
if ( V_48 ) {
V_10 -> V_47 -- ;
return V_48 ;
}
}
return 0 ;
}
static int F_16 ( struct V_14 * V_15 )
{
struct V_9 * V_10 = F_13 ( V_15 ) ;
struct V_38 * V_39 = V_10 -> V_39 ;
V_10 -> V_47 -- ;
if ( V_10 -> V_47 == 0 )
F_17 ( & V_39 -> V_49 ) ;
return 0 ;
}
static int F_18 ( struct V_14 * V_15 ,
unsigned int V_52 , void * V_53 )
{
return F_19 ( V_15 , V_52 , V_53 ) ;
}
static int F_20 ( struct V_14 * V_54 ,
T_3 V_55 )
{
struct V_16 * V_17 = V_54 -> V_17 ;
F_3 ( L_11 ) ;
if ( V_17 -> V_28 ) {
if ( V_17 -> V_56 > V_55 )
return 0 ;
F_21 ( V_17 -> V_28 ) ;
}
V_17 -> V_28 = F_22 ( V_55 ) ;
if ( ! V_17 -> V_28 )
return - V_57 ;
V_17 -> V_56 = V_55 ;
return 0 ;
}
static int F_23 ( struct V_14 * V_15 ,
struct V_58 * V_59 )
{
F_3 ( L_12 , V_27 ) ;
return F_20 ( V_15 ,
F_24 ( V_59 ) ) ;
}
static int F_25 ( struct V_14 * V_15 )
{
if ( V_15 -> V_17 -> V_28 ) {
F_3 ( L_13 ) ;
F_21 ( V_15 -> V_17 -> V_28 ) ;
V_15 -> V_17 -> V_28 = NULL ;
}
return 0 ;
}
static int F_26 ( struct V_14 * V_15 )
{
struct V_9 * V_10 = F_13 ( V_15 ) ;
V_10 -> V_29 = 0 ;
V_10 -> V_33 = 0 ;
return 0 ;
}
static int F_27 ( struct V_14 * V_15 , int V_52 )
{
switch ( V_52 ) {
case V_60 :
case V_61 :
return 0 ;
default:
return - V_62 ;
}
return 0 ;
}
static
T_4 F_28 ( struct V_14 * V_15 )
{
T_4 V_63 ;
struct V_9 * V_10 = F_13 ( V_15 ) ;
V_63 = V_10 -> V_29 ;
return V_63 ;
}
static void F_29 ( T_1 * V_1 , const T_1 * V_2 , T_2 V_3 , bool V_4 )
{
static const unsigned V_5 [ 8 ] = { 0 , 1 , 5 , 4 , 2 , 3 , 6 , 7 } ;
unsigned V_6 = 0 ;
while ( V_3 >= ( V_4 ? 4 : 2 ) ) {
unsigned V_7 = V_5 [ V_6 ] * 4 ;
T_1 * V_64 = V_1 + V_7 ;
* V_64 ++ = 0 ;
if ( V_4 ) {
V_2 ++ ;
* V_64 ++ = * V_2 ++ ;
} else {
* V_64 ++ = 0 ;
}
* V_64 ++ = * V_2 ++ ;
* V_64 = * V_2 ++ ;
V_3 -= V_4 ? 4 : 2 ;
V_6 ++ ;
}
}
static void F_30 ( struct V_9 * V_10 ,
T_1 * V_11 ,
T_3 V_12 ,
T_3 V_13 )
{
struct V_14 * V_15 ;
struct V_16 * V_17 ;
unsigned long V_18 ;
unsigned int V_65 ;
unsigned int V_20 ;
bool V_4 ;
unsigned V_32 ;
F_3 ( L_14 , V_10 ,
V_11 , V_13 ) ;
V_15 = V_10 -> V_66 ;
if ( V_15 == NULL ) {
F_3 ( L_2 ) ;
return;
}
V_17 = V_15 -> V_17 ;
if ( V_17 == NULL ) {
F_3 ( L_3 ) ;
return;
}
V_4 = V_17 -> V_24 == V_25 ;
V_20 = V_17 -> V_26 >> 3 ;
if ( V_20 == 0 ) {
F_3 ( L_4 ) ;
return;
}
if ( V_13 == 0 ) {
F_3 ( L_15 , V_27 ) ;
return;
}
if ( V_17 -> V_28 == NULL ) {
F_3 ( L_6 ) ;
return;
}
V_65 = V_10 -> V_67 % V_10 -> V_68 ;
for ( V_32 = 0 ; V_32 < V_10 -> V_69 / ( 8 * 4 ) ; V_32 ++ )
F_29 ( V_11 + V_32 * V_12 ,
V_17 -> V_28 + V_65 + V_32 * V_20 ,
V_20 , V_4 ) ;
F_4 ( V_15 , V_18 ) ;
V_10 -> V_67 += V_32 * V_20 ;
F_5 ( V_15 , V_18 ) ;
if ( V_10 -> V_67 % V_10 -> V_69 == 0 )
F_6 ( V_15 ) ;
}
static int F_31 ( struct V_35 * V_36 , void * V_37 )
{
struct V_38 * V_39 = V_37 ;
if ( V_39 -> V_42 -> V_70 )
F_30 ( V_39 -> V_42 ,
F_8 ( V_36 , 0 ) ,
8 * 4 ,
F_11 ( V_36 , 0 ) / ( 8 * 4 ) ) ;
return 0 ;
}
static int F_32 ( struct V_14 * V_15 )
{
struct V_9 * V_10 = F_13 ( V_15 ) ;
struct V_16 * V_17 = V_15 -> V_17 ;
struct V_38 * V_39 = V_10 -> V_39 ;
V_17 -> V_43 = V_71 ;
F_14 ( V_17 , V_45 ) ;
V_10 -> V_66 = V_15 ;
V_17 -> V_46 = V_39 ;
V_10 -> V_72 ++ ;
if ( V_10 -> V_72 == 1 ) {
int V_48 ;
V_48 = F_15 ( & V_39 -> V_49 , F_31 , V_39 , V_39 -> V_50 . V_51 ) ;
if ( V_48 ) {
V_10 -> V_72 -- ;
return V_48 ;
}
}
return 0 ;
}
static int F_33 ( struct V_14 * V_15 )
{
struct V_9 * V_10 = F_13 ( V_15 ) ;
struct V_38 * V_39 = V_10 -> V_39 ;
V_10 -> V_72 -- ;
if ( V_10 -> V_72 == 0 )
F_17 ( & V_39 -> V_49 ) ;
return 0 ;
}
static int F_34 ( struct V_14 * V_15 )
{
struct V_9 * V_10 = F_13 ( V_15 ) ;
V_10 -> V_68 = F_35 ( V_15 ) ;
V_10 -> V_69 = F_36 ( V_15 ) ;
V_10 -> V_67 = 0 ;
return 0 ;
}
static int F_37 ( struct V_14 * V_15 ,
int V_52 )
{
struct V_9 * V_10 = F_13 ( V_15 ) ;
switch ( V_52 ) {
case V_60 :
if ( V_10 -> V_70 )
return - V_73 ;
V_10 -> V_70 = true ;
return 0 ;
case V_61 :
V_10 -> V_70 = false ;
return 0 ;
default:
return - V_62 ;
}
}
static
T_4 F_38 ( struct V_14 * V_15 )
{
struct V_9 * V_10 = F_13 ( V_15 ) ;
T_3 V_74 ;
V_74 = V_10 -> V_67 ;
return F_39 ( V_15 -> V_17 , V_74 ) %
V_15 -> V_17 -> V_30 ;
}
static struct V_75 * F_40 ( struct V_14 * V_54 ,
unsigned long V_7 )
{
void * V_76 = V_54 -> V_17 -> V_28 + V_7 ;
return F_41 ( V_76 ) ;
}
int F_42 ( struct V_9 * V_10 )
{
struct V_77 * V_78 ;
struct V_79 * V_80 = V_10 -> V_80 ;
struct V_38 * V_39 = V_10 -> V_39 ;
struct V_81 * V_81 = V_39 -> V_81 ;
int V_82 ;
V_39 -> V_49 . V_83 |= V_84 ;
if ( ! V_39 -> V_85 ) {
F_43 ( V_81 ,
F_44 ( V_39 -> V_86 ) ,
0 ) ;
F_45 ( 2 ) ;
F_43 ( V_81 ,
F_44 ( V_39 -> V_86 ) ,
1 ) ;
F_45 ( 1 ) ;
V_82 = F_46 ( V_80 , L_16 ,
0 ,
0 ,
1 ,
& V_78 ) ;
if ( V_82 ) {
F_47 ( L_17 ,
V_82 ) ;
goto V_87;
}
F_48 ( V_78 , V_88 ,
& V_89 ) ;
V_78 -> V_90 = 0 ;
V_78 -> V_46 = V_10 ;
F_49 ( V_78 -> V_51 , L_18 , sizeof( V_78 -> V_51 ) ) ;
} else {
F_43 ( V_81 ,
V_91 , 0 ) ;
F_45 ( 2 ) ;
F_43 ( V_81 ,
V_91 , 1 ) ;
F_45 ( 1 ) ;
V_82 = F_46 ( V_80 , L_19 ,
0 ,
1 ,
0 ,
& V_78 ) ;
if ( V_82 ) {
F_47 ( L_20 ,
V_82 ) ;
goto V_87;
}
F_48 ( V_78 , V_92 ,
& V_93 ) ;
V_78 -> V_90 = 0 ;
V_78 -> V_46 = V_10 ;
F_49 ( V_78 -> V_51 , L_18 , sizeof( V_78 -> V_51 ) ) ;
}
return 0 ;
V_87:
return V_82 ;
}
