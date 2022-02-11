static inline int F_1 ( long V_1 , int V_2 , int div )
{
if ( V_1 < 0 )
return ( V_1 * V_2 - div / 2 ) / div ;
else
return ( V_1 * V_2 + div / 2 ) / div ;
}
static inline unsigned int F_2 ( T_1 V_3 , int V_4 )
{
return F_1 ( V_3 , V_5 [ V_4 ] , 192 ) ;
}
static inline T_1 F_3 ( unsigned long V_1 , int V_4 )
{
return F_4 ( F_1 ( V_1 , 192 , V_5 [ V_4 ] ) , 0 , 255 ) ;
}
static inline T_2 F_5 ( long V_1 )
{
return F_4 ( F_1 ( V_1 , 1 , 1000 ) , - 40 , 127 ) ;
}
static inline unsigned int F_6 ( T_1 V_3 , T_1 div )
{
if ( ! V_3 )
return - 1 ;
if ( V_3 == 255 )
return 0 ;
return F_1 ( 1350000 , 1 , V_3 * div ) ;
}
static inline T_1 F_7 ( unsigned long V_1 )
{
return F_4 ( F_1 ( V_1 , 255 , 1250 ) , 0 , 255 ) ;
}
static inline unsigned int F_8 ( T_1 V_3 )
{
return F_1 ( V_3 , 1250 , 255 ) ;
}
static T_3 F_9 ( struct V_6 * V_7 , struct V_8 * V_9 ,
char * V_10 )
{
struct V_11 * V_12 = F_10 ( V_7 ) ;
return sprintf ( V_10 , L_1 , V_12 -> V_13 * 500 ) ;
}
static T_3 F_11 ( struct V_6 * V_7 , struct V_8 * V_14 ,
char * V_10 )
{
struct V_15 * V_16 = F_12 ( V_14 ) ;
struct V_11 * V_12 = F_10 ( V_7 ) ;
return sprintf ( V_10 , L_1 , V_12 -> V_17 [ V_16 -> V_18 ] * 1000 ) ;
}
static T_3 F_13 ( struct V_6 * V_7 , struct V_8 * V_14 ,
const char * V_10 , T_4 V_19 )
{
struct V_15 * V_16 = F_12 ( V_14 ) ;
struct V_20 * V_21 = F_14 ( V_7 ) ;
struct V_11 * V_12 = F_15 ( V_21 ) ;
long V_1 ;
int V_22 ;
V_22 = F_16 ( V_10 , 10 , & V_1 ) ;
if ( V_22 )
return V_22 ;
F_17 ( & V_12 -> V_23 ) ;
V_12 -> V_17 [ V_16 -> V_18 ] = F_5 ( V_1 ) ;
F_18 ( V_21 , F_19 ( V_16 -> V_18 ) ,
V_12 -> V_17 [ V_16 -> V_18 ] ) ;
F_20 ( & V_12 -> V_23 ) ;
return V_19 ;
}
static T_3 F_21 ( struct V_6 * V_7 , struct V_8 * V_14 ,
char * V_10 )
{
struct V_15 * V_16 = F_12 ( V_14 ) ;
struct V_11 * V_12 = F_10 ( V_7 ) ;
return sprintf ( V_10 , L_1 , F_2 ( V_12 -> V_24 [ V_16 -> V_18 ] ,
V_16 -> V_18 ) ) ;
}
static T_3 F_22 ( struct V_6 * V_7 ,
struct V_8 * V_14 , char * V_10 )
{
struct V_15 * V_16 = F_12 ( V_14 ) ;
struct V_11 * V_12 = F_10 ( V_7 ) ;
return sprintf ( V_10 , L_1 , F_2 ( V_12 -> V_25 [ V_16 -> V_18 ] ,
V_16 -> V_18 ) ) ;
}
static T_3 F_23 ( struct V_6 * V_7 ,
struct V_8 * V_14 , char * V_10 )
{
struct V_15 * V_16 = F_12 ( V_14 ) ;
struct V_11 * V_12 = F_10 ( V_7 ) ;
return sprintf ( V_10 , L_1 , F_2 ( V_12 -> V_26 [ V_16 -> V_18 ] ,
V_16 -> V_18 ) ) ;
}
static T_3 F_24 ( struct V_6 * V_7 ,
struct V_8 * V_14 ,
const char * V_10 , T_4 V_19 )
{
struct V_15 * V_16 = F_12 ( V_14 ) ;
struct V_20 * V_21 = F_14 ( V_7 ) ;
struct V_11 * V_12 = F_15 ( V_21 ) ;
unsigned long V_1 ;
int V_22 ;
V_22 = F_25 ( V_10 , 10 , & V_1 ) ;
if ( V_22 )
return V_22 ;
F_17 ( & V_12 -> V_23 ) ;
V_12 -> V_25 [ V_16 -> V_18 ] = F_3 ( V_1 , V_16 -> V_18 ) ;
F_18 ( V_21 , F_26 ( V_16 -> V_18 ) ,
V_12 -> V_25 [ V_16 -> V_18 ] ) ;
F_20 ( & V_12 -> V_23 ) ;
return V_19 ;
}
static T_3 F_27 ( struct V_6 * V_7 ,
struct V_8 * V_14 ,
const char * V_10 , T_4 V_19 )
{
struct V_15 * V_16 = F_12 ( V_14 ) ;
struct V_20 * V_21 = F_14 ( V_7 ) ;
struct V_11 * V_12 = F_15 ( V_21 ) ;
unsigned long V_1 ;
int V_22 ;
V_22 = F_25 ( V_10 , 10 , & V_1 ) ;
if ( V_22 )
return V_22 ;
F_17 ( & V_12 -> V_23 ) ;
V_12 -> V_26 [ V_16 -> V_18 ] = F_3 ( V_1 , V_16 -> V_18 ) ;
F_18 ( V_21 , F_28 ( V_16 -> V_18 ) ,
V_12 -> V_26 [ V_16 -> V_18 ] ) ;
F_20 ( & V_12 -> V_23 ) ;
return V_19 ;
}
static T_3 F_29 ( struct V_6 * V_7 ,
struct V_8 * V_14 , char * V_10 )
{
struct V_15 * V_16 = F_12 ( V_14 ) ;
struct V_11 * V_12 = F_10 ( V_7 ) ;
return sprintf ( V_10 , L_1 , F_6 ( V_12 -> V_27 [ V_16 -> V_18 ] ,
1 << V_12 -> V_28 [ V_16 -> V_18 ] ) ) ;
}
static T_3 F_30 ( struct V_6 * V_7 ,
struct V_8 * V_14 , char * V_10 )
{
struct V_15 * V_16 = F_12 ( V_14 ) ;
struct V_11 * V_12 = F_10 ( V_7 ) ;
return sprintf ( V_10 , L_1 , F_6 ( V_12 -> V_29 [ V_16 -> V_18 ] ,
1 << V_12 -> V_28 [ V_16 -> V_18 ] ) ) ;
}
static T_3 F_31 ( struct V_6 * V_7 ,
struct V_8 * V_14 , char * V_10 )
{
struct V_15 * V_16 = F_12 ( V_14 ) ;
struct V_11 * V_12 = F_10 ( V_7 ) ;
return sprintf ( V_10 , L_1 , 1 << V_12 -> V_28 [ V_16 -> V_18 ] ) ;
}
static void F_32 ( struct V_20 * V_21 , int V_30 ,
T_1 V_28 )
{
T_1 V_3 , V_31 , V_32 = ( V_30 + 2 ) * 2 ;
V_3 = F_33 ( V_21 , V_33 ) ;
V_31 = ( V_3 >> V_32 ) & 3 ;
V_3 &= ~ ( 3 << V_32 ) ;
V_3 |= ( V_28 << V_32 ) ;
F_18 ( V_21 , V_33 , V_3 ) ;
F_34 ( & V_21 -> V_7 ,
L_2 ,
V_30 + 1 , 1 << V_31 , 1 << V_28 ) ;
}
static T_3 F_35 ( struct V_6 * V_7 ,
struct V_8 * V_14 ,
const char * V_10 , T_4 V_19 )
{
struct V_15 * V_16 = F_12 ( V_14 ) ;
struct V_20 * V_21 = F_14 ( V_7 ) ;
struct V_11 * V_12 = F_15 ( V_21 ) ;
int V_30 = V_16 -> V_18 ;
T_1 V_34 ;
unsigned long V_1 ;
int V_22 ;
V_22 = F_25 ( V_10 , 10 , & V_1 ) ;
if ( V_22 )
return V_22 ;
F_17 ( & V_12 -> V_23 ) ;
if ( ! V_1 ) {
V_12 -> V_29 [ V_30 ] = 255 ;
V_34 = V_12 -> V_28 [ V_30 ] ;
F_34 ( & V_21 -> V_7 , L_3 ,
V_30 + 1 ) ;
} else if ( V_1 < 1350000 / ( 8 * 254 ) ) {
V_34 = 3 ;
V_12 -> V_29 [ V_30 ] = 254 ;
F_34 ( & V_21 -> V_7 , L_4 ,
V_30 + 1 , F_6 ( 254 , 1 << V_34 ) ) ;
} else {
unsigned int V_35 = 1350000 / V_1 ;
V_34 = 0 ;
while ( V_35 > 192 && V_34 < 3 ) {
V_34 ++ ;
V_35 /= 2 ;
}
if ( ! V_35 )
V_35 ++ ;
V_12 -> V_29 [ V_30 ] = V_35 ;
F_34 ( & V_21 -> V_7 , L_5 ,
V_30 + 1 , F_6 ( V_35 , 1 << V_34 ) ) ;
}
if ( V_34 != V_12 -> V_28 [ V_30 ] ) {
V_12 -> V_28 [ V_30 ] = V_34 ;
F_32 ( V_21 , V_30 , V_34 ) ;
}
F_18 ( V_21 , F_36 ( V_30 ) ,
V_12 -> V_29 [ V_30 ] ) ;
F_20 ( & V_12 -> V_23 ) ;
return V_19 ;
}
static T_3 F_37 ( struct V_6 * V_7 ,
struct V_8 * V_16 , char * V_10 )
{
struct V_11 * V_12 = F_10 ( V_7 ) ;
return sprintf ( V_10 , L_6 , V_12 -> V_36 ) ;
}
static T_3 F_38 ( struct V_6 * V_7 ,
struct V_8 * V_16 , char * V_10 )
{
int V_37 = F_12 ( V_16 ) -> V_18 ;
struct V_11 * V_12 = F_10 ( V_7 ) ;
return sprintf ( V_10 , L_6 , ( V_12 -> V_36 >> V_37 ) & 1 ) ;
}
static T_3 F_39 ( struct V_6 * V_7 ,
struct V_8 * V_16 , char * V_10 )
{
struct V_11 * V_12 = F_10 ( V_7 ) ;
return sprintf ( V_10 , L_1 , F_40 ( V_12 -> V_38 , V_12 -> V_39 ) ) ;
}
static T_3 F_41 ( struct V_6 * V_7 ,
struct V_8 * V_16 , char * V_10 )
{
struct V_11 * V_12 = F_10 ( V_7 ) ;
return sprintf ( V_10 , L_1 , F_8 ( V_12 -> V_40 ) ) ;
}
static T_3 F_42 ( struct V_6 * V_7 ,
struct V_8 * V_16 ,
const char * V_10 , T_4 V_19 )
{
struct V_20 * V_21 = F_14 ( V_7 ) ;
struct V_11 * V_12 = F_15 ( V_21 ) ;
long V_1 ;
int V_22 ;
V_22 = F_16 ( V_10 , 10 , & V_1 ) ;
if ( V_22 )
return V_22 ;
F_17 ( & V_12 -> V_23 ) ;
V_12 -> V_40 = F_7 ( V_1 ) ;
F_18 ( V_21 , V_41 , V_12 -> V_40 ) ;
F_20 ( & V_12 -> V_23 ) ;
return V_19 ;
}
static T_3 F_43 ( struct V_6 * V_7 ,
struct V_8 * V_16 ,
const char * V_10 , T_4 V_19 )
{
struct V_20 * V_21 = F_14 ( V_7 ) ;
struct V_11 * V_12 = F_15 ( V_21 ) ;
unsigned long V_1 ;
if ( F_25 ( V_10 , 10 , & V_1 ) || V_1 != 0 )
return - V_42 ;
F_17 ( & V_12 -> V_23 ) ;
F_18 ( V_21 , V_43 , 0x80 ) ;
V_12 -> V_44 = 0 ;
F_20 ( & V_12 -> V_23 ) ;
F_34 ( & V_21 -> V_7 , L_7 ) ;
return V_19 ;
}
static int F_44 ( struct V_20 * V_45 ,
struct V_46 * V_47 )
{
struct V_48 * V_49 = V_45 -> V_49 ;
const char * V_50 = L_8 ;
int V_51 = V_45 -> V_52 ;
T_1 V_53 , V_54 ;
if ( ! F_45 ( V_49 , V_55 ) )
return - V_56 ;
if ( F_33 ( V_45 , V_57 )
!= V_51 ) {
F_46 ( & V_49 -> V_7 , L_9 ,
V_51 ) ;
return - V_56 ;
}
V_53 = F_33 ( V_45 , V_58 ) ;
if ( V_53 == 0x23 ) {
V_50 = L_10 ;
} else if ( V_53 == 0xda ) {
V_50 = L_11 ;
} else if ( V_53 == 0x01 ) {
V_50 = L_12 ;
} else {
F_46 ( & V_49 -> V_7 , L_13 ,
V_53 ) ;
return - V_56 ;
}
V_54 = F_33 ( V_45 , V_59 ) ;
F_47 ( & V_49 -> V_7 , L_14 ,
V_53 == 0x23 ? L_15 :
V_53 == 0xda ? L_16 : L_17 , V_54 ) ;
F_48 ( V_47 -> type , V_50 , V_60 ) ;
return 0 ;
}
static int F_49 ( struct V_20 * V_45 ,
const struct V_61 * V_62 )
{
struct V_11 * V_12 ;
int V_22 ;
V_12 = F_50 ( & V_45 -> V_7 , sizeof( * V_12 ) , V_63 ) ;
if ( ! V_12 )
return - V_64 ;
F_51 ( V_45 , V_12 ) ;
F_52 ( & V_12 -> V_23 ) ;
F_53 ( V_45 ) ;
V_22 = F_54 ( & V_45 -> V_7 . V_65 , & V_66 ) ;
if ( V_22 )
return V_22 ;
V_12 -> V_67 = F_55 ( & V_45 -> V_7 ) ;
if ( F_56 ( V_12 -> V_67 ) ) {
V_22 = F_57 ( V_12 -> V_67 ) ;
goto V_68;
}
return 0 ;
V_68:
F_58 ( & V_45 -> V_7 . V_65 , & V_66 ) ;
return V_22 ;
}
static int F_59 ( struct V_20 * V_21 )
{
struct V_11 * V_12 = F_15 ( V_21 ) ;
F_60 ( V_12 -> V_67 ) ;
F_58 ( & V_21 -> V_7 . V_65 , & V_66 ) ;
return 0 ;
}
static void F_53 ( struct V_20 * V_21 )
{
struct V_11 * V_12 = F_15 ( V_21 ) ;
T_1 V_69 = F_33 ( V_21 , V_70 ) ;
T_1 V_71 = F_33 ( V_21 , V_72 ) & 3 ;
V_12 -> V_39 = F_61 () ;
F_47 ( & V_21 -> V_7 , L_18 , V_12 -> V_39 / 10 ,
V_12 -> V_39 % 10 ) ;
if ( V_69 & 1 ) {
F_47 ( & V_21 -> V_7 , L_19 ,
V_69 , V_71 ) ;
} else {
int V_73 ;
for ( V_73 = 0 ; V_73 < 6 ; V_73 ++ ) {
F_18 ( V_21 ,
F_26 ( V_73 ) , 0 ) ;
F_18 ( V_21 ,
F_28 ( V_73 ) , 255 ) ;
}
F_18 ( V_21 ,
F_36 ( 0 ) , 255 ) ;
F_18 ( V_21 ,
F_36 ( 1 ) , 255 ) ;
F_18 ( V_21 ,
F_19 ( 0 ) , 127 ) ;
F_18 ( V_21 ,
F_19 ( 1 ) , 127 ) ;
F_18 ( V_21 , V_70 , 1 ) ;
F_47 ( & V_21 -> V_7 ,
L_20 , V_69 , V_71 ) ;
}
}
static struct V_11 * F_10 ( struct V_6 * V_7 )
{
struct V_20 * V_21 = F_14 ( V_7 ) ;
struct V_11 * V_12 = F_15 ( V_21 ) ;
int V_73 ;
F_17 ( & V_12 -> V_23 ) ;
if ( F_62 ( V_74 , V_12 -> V_75 + ( V_76 * 7 / 4 ) )
|| ! V_12 -> V_44 ) {
for ( V_73 = 0 ; V_73 < 6 ; V_73 ++ ) {
V_12 -> V_24 [ V_73 ] = F_33 ( V_21 ,
F_63 ( V_73 ) ) ;
}
V_12 -> V_36 = F_33 ( V_21 ,
F_64 ( 0 ) ) |
F_33 ( V_21 ,
F_64 ( 1 ) ) << 8 ;
V_12 -> V_13 = ( ( F_33 ( V_21 ,
V_77 ) << 8 ) |
F_33 ( V_21 ,
V_72 ) ) / 128 ;
for ( V_73 = 0 ; V_73 < 2 ; V_73 ++ ) {
V_12 -> V_27 [ V_73 ] = F_33 ( V_21 ,
F_65 ( V_73 ) ) ;
if ( V_12 -> V_44 && V_12 -> V_27 [ V_73 ] == 255 &&
V_12 -> V_28 [ V_73 ] < 3 ) {
F_32 ( V_21 , V_73 ,
++ V_12 -> V_28 [ V_73 ] ) ;
if ( V_12 -> V_29 [ V_73 ] < 255 &&
V_12 -> V_29 [ V_73 ] >= 2 )
V_12 -> V_29 [ V_73 ] /= 2 ;
}
}
V_12 -> V_75 = V_74 ;
}
if ( F_62 ( V_74 , V_12 -> V_78 + ( V_76 * 300 ) )
|| ! V_12 -> V_44 ) {
for ( V_73 = 0 ; V_73 < 6 ; V_73 ++ ) {
V_12 -> V_25 [ V_73 ] = F_33 ( V_21 ,
F_26 ( V_73 ) ) ;
V_12 -> V_26 [ V_73 ] = F_33 ( V_21 ,
F_28 ( V_73 ) ) ;
}
for ( V_73 = 0 ; V_73 < 2 ; V_73 ++ ) {
V_12 -> V_29 [ V_73 ] = F_33 ( V_21 ,
F_36 ( V_73 ) ) ;
}
V_12 -> V_17 [ 0 ] = F_33 ( V_21 ,
F_19 ( 0 ) ) ;
V_12 -> V_17 [ 1 ] = F_33 ( V_21 ,
F_19 ( 1 ) ) ;
V_73 = F_33 ( V_21 , V_33 ) ;
V_12 -> V_28 [ 0 ] = ( V_73 >> 4 ) & 3 ;
V_12 -> V_28 [ 1 ] = ( V_73 >> 6 ) & 3 ;
V_12 -> V_38 = V_73 & 0x0f ;
V_12 -> V_38 |= ( F_33 ( V_21 ,
V_79 ) & 1 ) << 4 ;
V_12 -> V_40 = F_33 ( V_21 ,
V_41 ) ;
V_12 -> V_78 = V_74 ;
V_12 -> V_44 = 1 ;
}
F_20 ( & V_12 -> V_23 ) ;
return V_12 ;
}
