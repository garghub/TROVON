static inline int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
T_2 V_4 ;
V_4 = F_2 ( V_2 , V_3 ) ;
V_4 |= ( ( T_2 ) F_2 ( V_2 , V_3 + 1 ) << 8 ) ;
return V_4 ;
}
static int F_3 ( int V_5 )
{
if ( V_5 < 4 )
return V_6 + ( 2 * V_5 ) ;
return V_7 + ( 2 * ( V_5 - 4 ) ) ;
}
static int F_4 ( struct V_8 * V_9 , int V_10 )
{
switch ( V_10 ) {
case 0 :
if ( ! ( V_9 -> V_11 [ 0 ] & V_12 ) )
return 0x7C ;
break;
case 1 :
return 0x69 ;
case 2 :
if ( ! ( V_9 -> V_11 [ 1 ] & V_13 ) )
return 0x7F ;
break;
case 3 :
if ( ! ( V_9 -> V_11 [ 1 ] & V_14 ) )
return 0x7E ;
break;
case 4 :
if ( ! ( V_9 -> V_11 [ 0 ] & V_15 ) )
return 0x4B ;
break;
case 5 :
if ( ! ( V_9 -> V_11 [ 0 ] & V_16 ) )
return 0x49 ;
break;
case 6 :
if ( ! ( V_9 -> V_11 [ 1 ] & V_17 ) )
return 0x68 ;
break;
case 7 :
if ( ! ( V_9 -> V_11 [ 1 ] & V_18 ) )
return 0x7D ;
break;
case 8 :
if ( ! ( V_9 -> V_11 [ 2 ] & V_19 ) )
return 0x6C ;
break;
case 9 :
if ( ! ( V_9 -> V_11 [ 2 ] & V_20 ) )
return 0x6B ;
break;
case 10 :
return 0x6A ;
case 11 :
if ( V_9 -> V_11 [ 3 ] >> V_21 ==
V_22 &&
! ( V_9 -> V_11 [ 0 ] & V_23 ) )
return 0x50 ;
break;
case 12 :
if ( V_9 -> V_11 [ 3 ] >> V_21 ==
V_22 &&
! ( V_9 -> V_11 [ 0 ] & V_23 ) )
return 0x4C ;
break;
}
return - V_24 ;
}
static int F_5 ( struct V_8 * V_9 , int V_10 )
{
switch ( V_10 ) {
case 0 :
if ( ! ( V_9 -> V_11 [ 0 ] & V_12 ) )
return 0x6D ;
break;
case 1 :
return 0x72 ;
case 2 :
if ( ! ( V_9 -> V_11 [ 1 ] & V_13 ) )
return 0x6F ;
break;
case 3 :
if ( ! ( V_9 -> V_11 [ 1 ] & V_14 ) )
return 0x71 ;
break;
case 4 :
if ( ! ( V_9 -> V_11 [ 0 ] & V_15 ) )
return 0x47 ;
break;
case 5 :
if ( ! ( V_9 -> V_11 [ 0 ] & V_16 ) )
return 0x45 ;
break;
case 6 :
if ( ! ( V_9 -> V_11 [ 1 ] & V_17 ) )
return 0x70 ;
break;
case 7 :
if ( ! ( V_9 -> V_11 [ 1 ] & V_18 ) )
return 0x6E ;
break;
case 8 :
if ( ! ( V_9 -> V_11 [ 2 ] & V_19 ) )
return 0x75 ;
break;
case 9 :
if ( ! ( V_9 -> V_11 [ 2 ] & V_20 ) )
return 0x74 ;
break;
case 10 :
return 0x73 ;
case 11 :
if ( V_9 -> V_11 [ 3 ] >> V_21 ==
V_22 &&
! ( V_9 -> V_11 [ 0 ] & V_23 ) )
return 0x76 ;
break;
case 12 :
if ( V_9 -> V_11 [ 3 ] >> V_21 ==
V_22 &&
! ( V_9 -> V_11 [ 0 ] & V_23 ) )
return 0x77 ;
break;
}
return - V_24 ;
}
static int F_6 ( struct V_8 * V_9 , int V_10 )
{
switch ( V_10 ) {
case 0 :
if ( ! ( V_9 -> V_11 [ 0 ] & V_12 ) )
return 0xA3 ;
break;
case 1 :
return 0x90 ;
case 2 :
if ( ! ( V_9 -> V_11 [ 1 ] & V_13 ) )
return 0xA9 ;
break;
case 3 :
if ( ! ( V_9 -> V_11 [ 1 ] & V_14 ) )
return 0xA7 ;
break;
case 4 :
if ( ! ( V_9 -> V_11 [ 0 ] & V_15 ) )
return 0x8F ;
break;
case 5 :
if ( ! ( V_9 -> V_11 [ 0 ] & V_16 ) )
return 0x8B ;
break;
case 6 :
if ( ! ( V_9 -> V_11 [ 1 ] & V_17 ) )
return 0x96 ;
break;
case 7 :
if ( ! ( V_9 -> V_11 [ 1 ] & V_18 ) )
return 0xA5 ;
break;
case 8 :
if ( ! ( V_9 -> V_11 [ 2 ] & V_19 ) )
return 0x93 ;
break;
case 9 :
if ( ! ( V_9 -> V_11 [ 2 ] & V_20 ) )
return 0x92 ;
break;
case 10 :
return 0x91 ;
case 11 :
if ( V_9 -> V_11 [ 3 ] >> V_21 ==
V_22 &&
! ( V_9 -> V_11 [ 0 ] & V_23 ) )
return 0x94 ;
break;
case 12 :
if ( V_9 -> V_11 [ 3 ] >> V_21 ==
V_22 &&
! ( V_9 -> V_11 [ 0 ] & V_23 ) )
return 0x95 ;
break;
}
return - V_24 ;
}
static const char * F_7 ( struct V_8 * V_9 , int V_10 )
{
switch ( V_10 ) {
case 0 :
if ( ! ( V_9 -> V_11 [ 0 ] & V_12 ) )
return L_1 ;
break;
case 1 :
switch ( F_8 ( V_9 -> V_11 [ 1 ] , V_25 ) ) {
case 0 :
return L_2 ;
case 1 :
return L_3 ;
case 2 :
return L_4 ;
case 3 :
return L_5 ;
}
case 2 :
if ( ! ( V_9 -> V_11 [ 1 ] & V_13 ) )
return L_6 ;
break;
case 3 :
if ( ! ( V_9 -> V_11 [ 1 ] & V_14 ) )
return L_7 ;
break;
case 4 :
if ( ! ( V_9 -> V_11 [ 0 ] & V_15 ) ) {
if ( V_9 -> V_11 [ 1 ] & V_26 )
return L_8 ;
return L_9 ;
}
break;
case 5 :
if ( ! ( V_9 -> V_11 [ 0 ] & V_16 ) ) {
if ( V_9 -> V_11 [ 1 ] & V_26 )
return L_4 ;
return L_3 ;
}
break;
case 6 :
if ( ! ( V_9 -> V_11 [ 1 ] & V_17 ) )
return L_10 ;
break;
case 7 :
if ( ! ( V_9 -> V_11 [ 1 ] & V_18 ) )
return L_11 ;
break;
case 8 :
switch ( F_8 ( V_9 -> V_11 [ 2 ] , V_27 ) ) {
case 0 :
return L_12 ;
case 1 :
return L_13 ;
}
break;
case 9 :
switch ( F_8 ( V_9 -> V_11 [ 2 ] , V_28 ) ) {
case 0 :
return L_10 ;
case 1 :
return L_14 ;
}
break;
case 10 :
switch ( F_8 ( V_9 -> V_11 [ 2 ] , V_29 ) ) {
case 0 :
return L_15 ;
case 1 :
return L_3 ;
case 2 :
return L_4 ;
case 3 :
return L_16 ;
}
case 11 :
if ( V_9 -> V_11 [ 3 ] >> V_21 ==
V_22 &&
! ( V_9 -> V_11 [ 0 ] & V_23 ) )
return L_17 ;
break;
case 12 :
if ( V_9 -> V_11 [ 3 ] >> V_21 ==
V_22 &&
! ( V_9 -> V_11 [ 0 ] & V_23 ) )
return L_18 ;
break;
}
return L_19 ;
}
static int F_9 ( struct V_8 * V_9 , int V_10 )
{
switch ( V_10 ) {
case 0 :
if ( ! ( V_9 -> V_11 [ 0 ] & V_12 ) )
return 62500 ;
break;
case 1 :
switch ( F_8 ( V_9 -> V_11 [ 1 ] , V_25 ) ) {
case 0 :
if ( V_9 -> V_11 [ 0 ] & V_23 )
return 12500 ;
return 6250 ;
case 1 :
return 13000 ;
case 2 :
return 9400 ;
case 3 :
return 7800 ;
}
case 2 :
if ( ! ( V_9 -> V_11 [ 1 ] & V_13 ) )
return 62500 ;
break;
case 3 :
if ( ! ( V_9 -> V_11 [ 1 ] & V_14 ) )
return 26000 ;
break;
case 4 :
if ( ! ( V_9 -> V_11 [ 0 ] & V_15 ) ) {
if ( V_9 -> V_11 [ 1 ] & V_26 )
return 4690 ;
return 6500 ;
}
break;
case 5 :
if ( ! ( V_9 -> V_11 [ 0 ] & V_16 ) ) {
if ( V_9 -> V_11 [ 1 ] & V_30 )
return 9400 ;
return 13000 ;
}
break;
case 6 :
if ( ! ( V_9 -> V_11 [ 1 ] & V_17 ) )
return 17200 ;
break;
case 7 :
if ( ! ( V_9 -> V_11 [ 1 ] & V_18 ) )
return 62500 ;
break;
case 8 :
switch ( F_8 ( V_9 -> V_11 [ 2 ] , V_27 ) ) {
case 0 :
return 15600 ;
case 1 :
return 6250 ;
}
break;
case 9 :
switch ( F_8 ( V_9 -> V_11 [ 2 ] , V_28 ) ) {
case 0 :
return 17200 ;
case 1 :
return 6250 ;
}
break;
case 10 :
switch ( F_8 ( V_9 -> V_11 [ 2 ] , V_29 ) ) {
case 0 :
return 6250 ;
case 1 :
return 13000 ;
case 2 :
return 9400 ;
case 3 :
return 7800 ;
}
case 11 :
case 12 :
if ( V_9 -> V_11 [ 3 ] >> V_21 ==
V_22 &&
! ( V_9 -> V_11 [ 0 ] & V_23 ) )
return 7800 ;
}
return 0 ;
}
static int F_10 ( struct V_8 * V_9 , int V_10 )
{
switch ( V_10 ) {
case 0 :
case 2 :
return 1 ;
case 1 :
if ( V_9 -> V_11 [ 0 ] & V_16 )
return 1 ;
break;
case 3 :
if ( V_9 -> V_11 [ 0 ] & V_15 )
return 1 ;
break;
}
return 0 ;
}
static const char * F_11 ( struct V_8 * V_9 , int V_10 )
{
switch ( V_10 ) {
case 0 :
return L_20 ;
case 1 :
if ( V_9 -> V_11 [ 0 ] & V_16 )
return L_21 ;
break;
case 2 :
return L_22 ;
case 3 :
if ( V_9 -> V_11 [ 0 ] & V_15 )
return L_23 ;
break;
}
return L_19 ;
}
static int F_12 ( int V_31 )
{
int V_32 ;
for ( V_32 = 0 ; V_32 < V_33 ; V_32 ++ )
if ( V_34 [ V_32 ] == V_31 )
return V_32 ;
return - V_24 ;
}
static struct V_8 * F_13 ( struct V_35 * V_36 )
{
struct V_1 * V_2 = F_14 ( V_36 ) ;
struct V_8 * V_9 = F_15 ( V_2 ) ;
unsigned long V_37 = V_38 ;
int V_32 ;
F_16 ( & V_9 -> V_39 ) ;
if ( F_17 ( V_37 , V_9 -> V_40 +
V_41 )
&& V_9 -> V_42 )
goto V_43;
for ( V_32 = 0 ; V_32 < V_44 ; V_32 ++ ) {
V_9 -> V_45 [ V_32 ] = F_2 ( V_2 ,
F_18 ( V_32 ) ) ;
V_9 -> V_46 [ V_32 ] = F_2 ( V_2 ,
F_18 ( V_32 ) + 1 ) ;
}
for ( V_32 = 0 ; V_32 < V_47 ; V_32 ++ )
V_9 -> V_5 [ V_32 ] = F_1 ( V_2 ,
F_3 ( V_32 ) ) ;
V_9 -> V_48 = F_2 ( V_2 ,
V_49 ) ;
for ( V_32 = 0 ; V_32 < V_50 ; V_32 ++ )
V_9 -> V_51 [ V_32 ] = F_2 ( V_2 ,
F_19 ( V_32 ) ) ;
for ( V_32 = 0 ; V_32 < V_52 ; V_32 ++ )
V_9 -> V_11 [ V_32 ] = F_2 ( V_2 ,
F_20 ( V_32 ) ) ;
for ( V_32 = 0 ; V_32 < V_53 ; V_32 ++ ) {
int V_3 = F_6 ( V_9 , V_32 ) ;
if ( ! V_3 )
V_9 -> V_54 [ V_32 ] = 0 ;
else
V_9 -> V_54 [ V_32 ] = F_2 ( V_2 ,
V_3 ) ;
}
V_9 -> V_55 [ 0 ] = F_2 ( V_2 , V_56 ) ;
V_9 -> V_55 [ 1 ] = F_2 ( V_2 , V_57 ) ;
V_9 -> V_55 [ 2 ] = F_2 ( V_2 , V_58 ) ;
V_9 -> V_55 [ 3 ] = F_2 ( V_2 , V_59 ) ;
V_9 -> V_40 = V_37 ;
V_9 -> V_42 = 1 ;
V_43:
if ( F_17 ( V_37 , V_9 -> V_60 +
V_61 )
&& V_9 -> V_62 )
goto V_63;
for ( V_32 = 0 ; V_32 < V_44 ; V_32 ++ ) {
V_9 -> V_64 [ V_32 ] = F_2 ( V_2 ,
F_21 ( V_32 ) ) ;
V_9 -> V_65 [ V_32 ] = F_2 ( V_2 ,
F_22 ( V_32 ) ) ;
}
for ( V_32 = 0 ; V_32 < V_47 ; V_32 ++ )
V_9 -> V_66 [ V_32 ] = F_2 ( V_2 ,
F_23 ( V_32 ) ) ;
for ( V_32 = 0 ; V_32 < V_53 ; V_32 ++ ) {
int V_3 = F_4 ( V_9 , V_32 ) ;
V_9 -> V_67 [ V_32 ] =
( V_3 ? F_2 ( V_2 , V_3 ) : 0 ) ;
V_3 = F_5 ( V_9 , V_32 ) ;
V_9 -> V_68 [ V_32 ] =
( V_3 ? F_2 ( V_2 , V_3 ) : 0 ) ;
}
for ( V_32 = 0 ; V_32 < V_50 ; V_32 ++ ) {
V_9 -> V_69 [ V_32 ] = F_2 ( V_2 ,
F_24 ( V_32 ) ) ;
V_9 -> V_70 [ V_32 ] = F_2 ( V_2 ,
F_25 ( V_32 ) ) ;
V_9 -> V_71 [ V_32 ] = F_2 ( V_2 ,
F_26 ( V_32 ) ) ;
V_9 -> V_72 [ V_32 ] = F_2 ( V_2 ,
F_27 ( V_32 ) ) ;
}
V_9 -> V_73 = F_2 ( V_2 , V_74 ) ;
V_9 -> V_75 = F_2 ( V_2 , V_76 ) ;
V_9 -> V_60 = V_37 ;
V_9 -> V_62 = 1 ;
V_63:
F_28 ( & V_9 -> V_39 ) ;
return V_9 ;
}
static T_3 F_29 ( struct V_35 * V_36 ,
struct V_77 * V_78 ,
char * V_79 )
{
struct V_80 * V_81 = F_30 ( V_78 ) ;
struct V_8 * V_9 = F_13 ( V_36 ) ;
if ( ! F_10 ( V_9 , V_81 -> V_82 ) )
return sprintf ( V_79 , L_24 ) ;
return sprintf ( V_79 , L_25 , 1000 * ( V_9 -> V_64 [ V_81 -> V_82 ] - 64 ) ) ;
}
static T_3 F_31 ( struct V_35 * V_36 ,
struct V_77 * V_78 ,
const char * V_79 ,
T_4 V_83 )
{
struct V_80 * V_81 = F_30 ( V_78 ) ;
struct V_1 * V_2 = F_14 ( V_36 ) ;
struct V_8 * V_9 = F_15 ( V_2 ) ;
long V_46 ;
if ( F_32 ( V_79 , 10 , & V_46 ) || ! F_10 ( V_9 , V_81 -> V_82 ) )
return - V_84 ;
V_46 = F_33 ( V_46 , 1000 ) + 64 ;
V_46 = F_34 ( V_46 , 0 , 255 ) ;
F_16 ( & V_9 -> V_39 ) ;
V_9 -> V_64 [ V_81 -> V_82 ] = V_46 ;
F_35 ( V_2 , F_21 ( V_81 -> V_82 ) ,
V_46 ) ;
F_28 ( & V_9 -> V_39 ) ;
return V_83 ;
}
static T_3 F_36 ( struct V_35 * V_36 ,
struct V_77 * V_78 ,
char * V_79 )
{
struct V_80 * V_81 = F_30 ( V_78 ) ;
struct V_8 * V_9 = F_13 ( V_36 ) ;
if ( ! F_10 ( V_9 , V_81 -> V_82 ) )
return sprintf ( V_79 , L_24 ) ;
return sprintf ( V_79 , L_25 , 1000 * ( V_9 -> V_65 [ V_81 -> V_82 ] - 64 ) ) ;
}
static T_3 F_37 ( struct V_35 * V_36 ,
struct V_77 * V_78 ,
const char * V_79 ,
T_4 V_83 )
{
struct V_80 * V_81 = F_30 ( V_78 ) ;
struct V_1 * V_2 = F_14 ( V_36 ) ;
struct V_8 * V_9 = F_15 ( V_2 ) ;
long V_46 ;
if ( F_32 ( V_79 , 10 , & V_46 ) || ! F_10 ( V_9 , V_81 -> V_82 ) )
return - V_84 ;
V_46 = F_33 ( V_46 , 1000 ) + 64 ;
V_46 = F_34 ( V_46 , 0 , 255 ) ;
F_16 ( & V_9 -> V_39 ) ;
V_9 -> V_65 [ V_81 -> V_82 ] = V_46 ;
F_35 ( V_2 , F_22 ( V_81 -> V_82 ) ,
V_46 ) ;
F_28 ( & V_9 -> V_39 ) ;
return V_83 ;
}
static T_3 F_38 ( struct V_35 * V_36 , struct V_77 * V_78 ,
char * V_79 )
{
struct V_80 * V_81 = F_30 ( V_78 ) ;
struct V_8 * V_9 = F_13 ( V_36 ) ;
T_1 V_85 = V_9 -> V_45 [ V_81 -> V_82 ] >> V_86 ;
if ( ! F_10 ( V_9 , V_81 -> V_82 ) )
return sprintf ( V_79 , L_24 ) ;
return sprintf ( V_79 , L_25 , 1000 * ( V_9 -> V_46 [ V_81 -> V_82 ] - 64 ) +
250 * V_85 ) ;
}
static T_3 F_39 ( struct V_35 * V_36 ,
struct V_77 * V_78 ,
char * V_79 )
{
struct V_80 * V_81 = F_30 ( V_78 ) ;
struct V_8 * V_9 = F_13 ( V_36 ) ;
return sprintf ( V_79 , L_26 , F_11 ( V_9 , V_81 -> V_82 ) ) ;
}
static T_3 F_40 ( struct V_35 * V_36 ,
struct V_77 * V_78 ,
char * V_79 )
{
struct V_80 * V_81 = F_30 ( V_78 ) ;
struct V_8 * V_9 = F_13 ( V_36 ) ;
int V_87 = F_9 ( V_9 , V_81 -> V_82 ) ;
V_87 *= V_9 -> V_67 [ V_81 -> V_82 ] ;
V_87 /= 1000 ;
return sprintf ( V_79 , L_25 , V_87 ) ;
}
static T_3 F_41 ( struct V_35 * V_36 ,
struct V_77 * V_78 ,
const char * V_79 ,
T_4 V_83 )
{
struct V_80 * V_81 = F_30 ( V_78 ) ;
struct V_1 * V_2 = F_14 ( V_36 ) ;
struct V_8 * V_9 = F_15 ( V_2 ) ;
int V_87 = F_9 ( V_9 , V_81 -> V_82 ) ;
long V_46 ;
if ( F_32 ( V_79 , 10 , & V_46 ) || ! V_87 )
return - V_84 ;
V_46 *= 1000 ;
V_46 = F_33 ( V_46 , V_87 ) ;
V_46 = F_34 ( V_46 , 0 , 255 ) ;
F_16 ( & V_9 -> V_39 ) ;
V_9 -> V_67 [ V_81 -> V_82 ] = V_46 ;
F_35 ( V_2 ,
F_4 ( V_9 , V_81 -> V_82 ) ,
V_46 ) ;
F_28 ( & V_9 -> V_39 ) ;
return V_83 ;
}
static T_3 F_42 ( struct V_35 * V_36 ,
struct V_77 * V_78 ,
char * V_79 )
{
struct V_80 * V_81 = F_30 ( V_78 ) ;
struct V_8 * V_9 = F_13 ( V_36 ) ;
int V_87 = F_9 ( V_9 , V_81 -> V_82 ) ;
V_87 *= V_9 -> V_68 [ V_81 -> V_82 ] ;
V_87 /= 1000 ;
return sprintf ( V_79 , L_25 , V_87 ) ;
}
static T_3 F_43 ( struct V_35 * V_36 ,
struct V_77 * V_78 ,
const char * V_79 ,
T_4 V_83 )
{
struct V_80 * V_81 = F_30 ( V_78 ) ;
struct V_1 * V_2 = F_14 ( V_36 ) ;
struct V_8 * V_9 = F_15 ( V_2 ) ;
int V_87 = F_9 ( V_9 , V_81 -> V_82 ) ;
long V_46 ;
if ( F_32 ( V_79 , 10 , & V_46 ) || ! V_87 )
return - V_84 ;
V_46 *= 1000 ;
V_46 = F_33 ( V_46 , V_87 ) ;
V_46 = F_34 ( V_46 , 0 , 255 ) ;
F_16 ( & V_9 -> V_39 ) ;
V_9 -> V_68 [ V_81 -> V_82 ] = V_46 ;
F_35 ( V_2 ,
F_5 ( V_9 , V_81 -> V_82 ) ,
V_46 ) ;
F_28 ( & V_9 -> V_39 ) ;
return V_83 ;
}
static T_3 F_44 ( struct V_35 * V_36 ,
struct V_77 * V_78 ,
char * V_79 )
{
struct V_80 * V_81 = F_30 ( V_78 ) ;
struct V_8 * V_9 = F_13 ( V_36 ) ;
int V_87 = F_9 ( V_9 , V_81 -> V_82 ) ;
V_87 *= V_9 -> V_54 [ V_81 -> V_82 ] ;
V_87 /= 1000 ;
return sprintf ( V_79 , L_25 , V_87 ) ;
}
static T_3 F_45 ( struct V_35 * V_36 ,
struct V_77 * V_78 ,
char * V_79 )
{
struct V_80 * V_81 = F_30 ( V_78 ) ;
struct V_8 * V_9 = F_13 ( V_36 ) ;
return sprintf ( V_79 , L_26 , F_7 ( V_9 , V_81 -> V_82 ) ) ;
}
static T_3 F_46 ( struct V_35 * V_36 ,
struct V_77 * V_78 ,
char * V_79 )
{
struct V_80 * V_81 = F_30 ( V_78 ) ;
struct V_8 * V_9 = F_13 ( V_36 ) ;
int V_3 = V_81 -> V_82 >> V_88 ;
int V_89 = V_81 -> V_82 & V_90 ;
if ( V_9 -> V_55 [ V_3 ] & V_89 )
return sprintf ( V_79 , L_27 ) ;
else
return sprintf ( V_79 , L_24 ) ;
}
static int V_48 ( struct V_8 * V_9 , int V_5 )
{
return V_9 -> V_48 & ( 1 << V_5 ) ;
}
static T_3 F_47 ( struct V_35 * V_36 ,
struct V_77 * V_78 ,
char * V_79 )
{
struct V_80 * V_81 = F_30 ( V_78 ) ;
struct V_8 * V_9 = F_13 ( V_36 ) ;
T_2 V_46 ;
V_46 = V_9 -> V_66 [ V_81 -> V_82 ] ;
V_46 <<= 8 ;
if ( ! V_48 ( V_9 , V_81 -> V_82 ) ||
! F_48 ( V_46 ) )
return sprintf ( V_79 , L_24 ) ;
return sprintf ( V_79 , L_25 , F_49 ( V_46 ) ) ;
}
static T_3 F_50 ( struct V_35 * V_36 ,
struct V_77 * V_78 ,
const char * V_79 , T_4 V_83 )
{
struct V_80 * V_81 = F_30 ( V_78 ) ;
struct V_1 * V_2 = F_14 ( V_36 ) ;
struct V_8 * V_9 = F_15 ( V_2 ) ;
long V_46 ;
if ( F_32 ( V_79 , 10 , & V_46 ) || ! V_46 ||
! V_48 ( V_9 , V_81 -> V_82 ) )
return - V_84 ;
V_46 = F_51 ( V_46 ) ;
V_46 >>= 8 ;
V_46 = F_34 ( V_46 , 1 , 255 ) ;
F_16 ( & V_9 -> V_39 ) ;
V_9 -> V_66 [ V_81 -> V_82 ] = V_46 ;
F_35 ( V_2 , F_23 ( V_81 -> V_82 ) ,
V_46 ) ;
F_28 ( & V_9 -> V_39 ) ;
return V_83 ;
}
static T_3 F_52 ( struct V_35 * V_36 , struct V_77 * V_78 ,
char * V_79 )
{
struct V_80 * V_81 = F_30 ( V_78 ) ;
struct V_8 * V_9 = F_13 ( V_36 ) ;
if ( ! V_48 ( V_9 , V_81 -> V_82 ) ||
! F_48 ( V_9 -> V_5 [ V_81 -> V_82 ] ) )
return sprintf ( V_79 , L_24 ) ;
return sprintf ( V_79 , L_25 ,
F_49 ( V_9 -> V_5 [ V_81 -> V_82 ] ) ) ;
}
static T_3 F_53 ( struct V_35 * V_36 ,
struct V_77 * V_78 ,
char * V_79 )
{
struct V_8 * V_9 = F_13 ( V_36 ) ;
return sprintf ( V_79 , L_25 , ( V_9 -> V_75 & V_91 ? 1 : 0 ) ) ;
}
static T_3 F_54 ( struct V_35 * V_36 ,
struct V_77 * V_78 ,
const char * V_79 ,
T_4 V_83 )
{
struct V_1 * V_2 = F_14 ( V_36 ) ;
struct V_8 * V_9 = F_15 ( V_2 ) ;
long V_46 ;
T_1 V_3 ;
if ( F_32 ( V_79 , 10 , & V_46 ) )
return - V_84 ;
F_16 ( & V_9 -> V_39 ) ;
V_3 = F_2 ( V_2 , V_76 ) ;
if ( V_46 )
V_3 |= V_91 ;
else
V_3 &= ~ V_91 ;
V_9 -> V_75 = V_3 ;
F_35 ( V_2 , V_76 , V_3 ) ;
F_28 ( & V_9 -> V_39 ) ;
return V_83 ;
}
static T_3 F_55 ( struct V_35 * V_36 , struct V_77 * V_78 ,
char * V_79 )
{
struct V_80 * V_81 = F_30 ( V_78 ) ;
struct V_8 * V_9 = F_13 ( V_36 ) ;
return sprintf ( V_79 , L_25 , V_9 -> V_51 [ V_81 -> V_82 ] ) ;
}
static T_3 F_56 ( struct V_35 * V_36 , struct V_77 * V_78 ,
const char * V_79 , T_4 V_83 )
{
struct V_80 * V_81 = F_30 ( V_78 ) ;
struct V_1 * V_2 = F_14 ( V_36 ) ;
struct V_8 * V_9 = F_15 ( V_2 ) ;
long V_46 ;
if ( F_32 ( V_79 , 10 , & V_46 ) )
return - V_84 ;
V_46 = F_34 ( V_46 , 0 , 255 ) ;
F_16 ( & V_9 -> V_39 ) ;
V_9 -> V_51 [ V_81 -> V_82 ] = V_46 ;
F_35 ( V_2 , F_19 ( V_81 -> V_82 ) , V_46 ) ;
F_28 ( & V_9 -> V_39 ) ;
return V_83 ;
}
static T_3 F_57 ( struct V_35 * V_36 ,
struct V_77 * V_78 ,
char * V_79 )
{
struct V_8 * V_9 = F_13 ( V_36 ) ;
return sprintf ( V_79 , L_25 , V_9 -> V_73 ) ;
}
static T_3 F_58 ( struct V_35 * V_36 ,
struct V_77 * V_78 ,
const char * V_79 ,
T_4 V_83 )
{
struct V_1 * V_2 = F_14 ( V_36 ) ;
struct V_8 * V_9 = F_15 ( V_2 ) ;
long V_46 ;
if ( F_32 ( V_79 , 10 , & V_46 ) )
return - V_84 ;
V_46 = F_34 ( V_46 , 0 , 255 ) ;
F_16 ( & V_9 -> V_39 ) ;
V_9 -> V_73 = V_46 ;
F_35 ( V_2 , V_74 , V_46 ) ;
F_28 ( & V_9 -> V_39 ) ;
return V_83 ;
}
static T_3 F_59 ( struct V_35 * V_36 ,
struct V_77 * V_78 ,
char * V_79 )
{
struct V_80 * V_81 = F_30 ( V_78 ) ;
struct V_8 * V_9 = F_13 ( V_36 ) ;
return sprintf ( V_79 , L_25 , V_9 -> V_69 [ V_81 -> V_82 ] ) ;
}
static T_3 F_60 ( struct V_35 * V_36 ,
struct V_77 * V_78 ,
const char * V_79 ,
T_4 V_83 )
{
struct V_80 * V_81 = F_30 ( V_78 ) ;
struct V_1 * V_2 = F_14 ( V_36 ) ;
struct V_8 * V_9 = F_15 ( V_2 ) ;
long V_46 ;
if ( F_32 ( V_79 , 10 , & V_46 ) )
return - V_84 ;
V_46 = F_34 ( V_46 , 0 , 255 ) ;
F_16 ( & V_9 -> V_39 ) ;
V_9 -> V_69 [ V_81 -> V_82 ] = V_46 ;
F_35 ( V_2 , F_24 ( V_81 -> V_82 ) ,
V_46 ) ;
F_28 ( & V_9 -> V_39 ) ;
return V_83 ;
}
static T_3 F_61 ( struct V_35 * V_36 ,
struct V_77 * V_78 ,
char * V_79 )
{
struct V_80 * V_81 = F_30 ( V_78 ) ;
struct V_8 * V_9 = F_13 ( V_36 ) ;
return sprintf ( V_79 , L_25 , 1000 *
( V_9 -> V_71 [ V_81 -> V_82 ] & V_92 ) ) ;
}
static T_3 F_62 ( struct V_35 * V_36 ,
struct V_77 * V_78 ,
const char * V_79 ,
T_4 V_83 )
{
struct V_80 * V_81 = F_30 ( V_78 ) ;
struct V_1 * V_2 = F_14 ( V_36 ) ;
struct V_8 * V_9 = F_15 ( V_2 ) ;
long V_46 ;
if ( F_32 ( V_79 , 10 , & V_46 ) )
return - V_84 ;
V_46 = F_33 ( V_46 , 1000 ) ;
V_46 = F_34 ( V_46 , 0 , 15 ) ;
V_46 &= V_92 ;
V_46 |= V_9 -> V_71 [ V_81 -> V_82 ] & V_93 ;
F_16 ( & V_9 -> V_39 ) ;
V_9 -> V_71 [ V_81 -> V_82 ] = V_46 ;
F_35 ( V_2 , F_26 ( V_81 -> V_82 ) ,
V_46 ) ;
F_28 ( & V_9 -> V_39 ) ;
return V_83 ;
}
static T_3 F_63 ( struct V_35 * V_36 ,
struct V_77 * V_78 ,
char * V_79 )
{
struct V_80 * V_81 = F_30 ( V_78 ) ;
struct V_8 * V_9 = F_13 ( V_36 ) ;
int V_31 = V_34 [ V_9 -> V_71 [ V_81 -> V_82 ] >>
V_94 ] ;
int V_95 = ( V_9 -> V_70 [ V_81 -> V_82 ] - 64 ) * 1000 ;
return sprintf ( V_79 , L_25 , V_95 + V_31 ) ;
}
static T_3 F_64 ( struct V_35 * V_36 ,
struct V_77 * V_78 ,
const char * V_79 ,
T_4 V_83 )
{
int V_46 ;
struct V_80 * V_81 = F_30 ( V_78 ) ;
struct V_1 * V_2 = F_14 ( V_36 ) ;
struct V_8 * V_9 = F_15 ( V_2 ) ;
int V_95 , V_96 ;
long V_31 ;
if ( F_32 ( V_79 , 10 , & V_31 ) )
return - V_84 ;
V_95 = ( V_9 -> V_70 [ V_81 -> V_82 ] - 64 ) * 1000 ;
V_96 = F_12 ( V_31 - V_95 ) ;
if ( V_96 < 0 )
return - V_84 ;
V_46 = V_96 << V_94 ;
V_46 |= V_9 -> V_71 [ V_81 -> V_82 ] & V_92 ;
F_16 ( & V_9 -> V_39 ) ;
V_9 -> V_71 [ V_81 -> V_82 ] = V_46 ;
F_35 ( V_2 , F_26 ( V_81 -> V_82 ) ,
V_46 ) ;
F_28 ( & V_9 -> V_39 ) ;
return V_83 ;
}
static T_3 F_65 ( struct V_35 * V_36 ,
struct V_77 * V_78 ,
char * V_79 )
{
struct V_80 * V_81 = F_30 ( V_78 ) ;
struct V_8 * V_9 = F_13 ( V_36 ) ;
return sprintf ( V_79 , L_25 , 1000 * ( V_9 -> V_70 [ V_81 -> V_82 ] - 64 ) ) ;
}
static T_3 F_66 ( struct V_35 * V_36 ,
struct V_77 * V_78 ,
const char * V_79 ,
T_4 V_83 )
{
struct V_80 * V_81 = F_30 ( V_78 ) ;
struct V_1 * V_2 = F_14 ( V_36 ) ;
struct V_8 * V_9 = F_15 ( V_2 ) ;
long V_46 ;
if ( F_32 ( V_79 , 10 , & V_46 ) )
return - V_84 ;
V_46 = F_33 ( V_46 , 1000 ) + 64 ;
V_46 = F_34 ( V_46 , 0 , 255 ) ;
F_16 ( & V_9 -> V_39 ) ;
V_9 -> V_70 [ V_81 -> V_82 ] = V_46 ;
F_35 ( V_2 , F_25 ( V_81 -> V_82 ) ,
V_46 ) ;
F_28 ( & V_9 -> V_39 ) ;
return V_83 ;
}
static T_3 F_67 ( struct V_35 * V_36 ,
struct V_77 * V_78 ,
char * V_79 )
{
struct V_80 * V_81 = F_30 ( V_78 ) ;
struct V_8 * V_9 = F_13 ( V_36 ) ;
int V_97 = V_9 -> V_72 [ V_81 -> V_82 ] >> V_98 ;
switch ( V_97 ) {
case 4 :
return sprintf ( V_79 , L_24 ) ;
case 7 :
return sprintf ( V_79 , L_27 ) ;
default:
return sprintf ( V_79 , L_28 ) ;
}
}
static void F_68 ( struct V_1 * V_2 ,
struct V_8 * V_9 ,
int V_10 ,
int V_99 )
{
int V_46 = V_9 -> V_72 [ V_10 ] & ~ V_100 ;
V_46 |= V_99 << V_98 ;
F_16 ( & V_9 -> V_39 ) ;
V_9 -> V_72 [ V_10 ] = V_46 ;
F_35 ( V_2 , F_27 ( V_10 ) , V_46 ) ;
F_28 ( & V_9 -> V_39 ) ;
}
static T_3 F_69 ( struct V_35 * V_36 ,
struct V_77 * V_78 ,
const char * V_79 ,
T_4 V_83 )
{
struct V_80 * V_81 = F_30 ( V_78 ) ;
struct V_1 * V_2 = F_14 ( V_36 ) ;
struct V_8 * V_9 = F_15 ( V_2 ) ;
long V_46 ;
if ( F_32 ( V_79 , 10 , & V_46 ) )
return - V_84 ;
switch ( V_46 ) {
case 0 :
F_68 ( V_2 , V_9 , V_81 -> V_82 , 4 ) ;
return V_83 ;
case 1 :
F_68 ( V_2 , V_9 , V_81 -> V_82 , 7 ) ;
return V_83 ;
default:
return - V_84 ;
}
}
static T_3 F_70 ( struct V_35 * V_36 ,
struct V_77 * V_78 ,
char * V_79 )
{
struct V_80 * V_81 = F_30 ( V_78 ) ;
struct V_8 * V_9 = F_13 ( V_36 ) ;
int V_101 = V_9 -> V_72 [ V_81 -> V_82 ] >> V_98 ;
switch ( V_101 ) {
case 0 :
case 1 :
case 2 :
case 3 :
return sprintf ( V_79 , L_25 , ( 1 << V_101 ) ) ;
case 5 :
return sprintf ( V_79 , L_29 ) ;
case 6 :
return sprintf ( V_79 , L_30 ) ;
default:
return sprintf ( V_79 , L_24 ) ;
}
}
static int F_71 ( int V_102 )
{
if ( V_102 == 0xF )
return 6 ;
if ( V_102 == 0x9 )
return 5 ;
if ( V_102 < 1 || ! F_72 ( V_102 ) )
return - V_84 ;
return F_73 ( V_102 ) ;
}
static T_3 F_74 ( struct V_35 * V_36 ,
struct V_77 * V_78 ,
const char * V_79 ,
T_4 V_83 )
{
struct V_80 * V_81 = F_30 ( V_78 ) ;
struct V_1 * V_2 = F_14 ( V_36 ) ;
struct V_8 * V_9 = F_15 ( V_2 ) ;
long V_46 ;
if ( F_32 ( V_79 , 10 , & V_46 ) )
return - V_84 ;
V_46 = F_71 ( V_46 ) ;
if ( V_46 < 0 )
return V_46 ;
F_68 ( V_2 , V_9 , V_81 -> V_82 , V_46 ) ;
return V_83 ;
}
static int F_75 ( struct V_1 * V_2 ,
struct V_103 * V_104 )
{
struct V_105 * V_106 = V_2 -> V_106 ;
int V_107 , V_35 , V_108 ;
if ( ! F_76 ( V_106 , V_109 ) )
return - V_24 ;
V_107 = F_2 ( V_2 , V_110 ) ;
if ( V_107 != V_111 )
return - V_24 ;
V_35 = F_2 ( V_2 , V_112 ) ;
if ( V_35 != V_113 )
return - V_24 ;
V_108 = F_2 ( V_2 , V_114 ) ;
if ( V_108 != V_115 )
return - V_24 ;
F_77 ( V_104 -> type , L_31 , V_116 ) ;
return 0 ;
}
static int F_78 ( struct V_1 * V_2 ,
const struct V_117 * V_118 )
{
struct V_8 * V_9 ;
int V_119 ;
V_9 = F_79 ( sizeof( struct V_8 ) , V_120 ) ;
if ( ! V_9 ) {
V_119 = - V_121 ;
goto exit;
}
F_80 ( V_2 , V_9 ) ;
F_81 ( & V_9 -> V_39 ) ;
F_82 ( & V_2 -> V_36 , L_32 , V_2 -> V_122 ) ;
V_9 -> V_123 . V_123 = V_124 ;
V_119 = F_83 ( & V_2 -> V_36 . V_125 , & V_9 -> V_123 ) ;
if ( V_119 )
goto V_126;
V_9 -> V_127 = F_84 ( & V_2 -> V_36 ) ;
if ( F_85 ( V_9 -> V_127 ) ) {
V_119 = F_86 ( V_9 -> V_127 ) ;
goto V_128;
}
return 0 ;
V_128:
F_87 ( & V_2 -> V_36 . V_125 , & V_9 -> V_123 ) ;
V_126:
F_88 ( V_9 ) ;
exit:
return V_119 ;
}
static int F_89 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_15 ( V_2 ) ;
F_90 ( V_9 -> V_127 ) ;
F_87 ( & V_2 -> V_36 . V_125 , & V_9 -> V_123 ) ;
F_88 ( V_9 ) ;
return 0 ;
}
