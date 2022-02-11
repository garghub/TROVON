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
static void F_9 ( struct V_6 * V_7 , int V_8 ,
T_1 V_9 )
{
T_1 V_3 , V_10 , V_11 = ( V_8 + 2 ) * 2 ;
V_3 = F_10 ( V_7 , V_12 ) ;
V_10 = ( V_3 >> V_11 ) & 3 ;
V_3 &= ~ ( 3 << V_11 ) ;
V_3 |= ( V_9 << V_11 ) ;
F_11 ( V_7 , V_12 , V_3 ) ;
F_12 ( & V_7 -> V_13 ,
L_1 ,
V_8 + 1 , 1 << V_10 , 1 << V_9 ) ;
}
static struct V_14 * F_13 ( struct V_15 * V_13 )
{
struct V_14 * V_16 = F_14 ( V_13 ) ;
struct V_6 * V_7 = V_16 -> V_7 ;
int V_17 ;
F_15 ( & V_16 -> V_18 ) ;
if ( F_16 ( V_19 , V_16 -> V_20 + ( V_21 * 7 / 4 ) )
|| ! V_16 -> V_22 ) {
for ( V_17 = 0 ; V_17 < 6 ; V_17 ++ ) {
V_16 -> V_23 [ V_17 ] = F_10 ( V_7 ,
F_17 ( V_17 ) ) ;
}
V_16 -> V_24 = F_10 ( V_7 ,
F_18 ( 0 ) ) |
F_10 ( V_7 ,
F_18 ( 1 ) ) << 8 ;
V_16 -> V_25 = ( F_10 ( V_7 ,
V_26 ) << 8 ) |
F_10 ( V_7 ,
V_27 ) ;
for ( V_17 = 0 ; V_17 < 2 ; V_17 ++ ) {
V_16 -> V_28 [ V_17 ] = F_10 ( V_7 ,
F_19 ( V_17 ) ) ;
if ( V_16 -> V_22 && V_16 -> V_28 [ V_17 ] == 255 &&
V_16 -> V_9 [ V_17 ] < 3 ) {
F_9 ( V_7 , V_17 ,
++ V_16 -> V_9 [ V_17 ] ) ;
if ( V_16 -> V_29 [ V_17 ] < 255 &&
V_16 -> V_29 [ V_17 ] >= 2 )
V_16 -> V_29 [ V_17 ] /= 2 ;
}
}
V_16 -> V_20 = V_19 ;
}
if ( F_16 ( V_19 , V_16 -> V_30 + ( V_21 * 300 ) )
|| ! V_16 -> V_22 ) {
for ( V_17 = 0 ; V_17 < 6 ; V_17 ++ ) {
V_16 -> V_31 [ V_17 ] = F_10 ( V_7 ,
F_20 ( V_17 ) ) ;
V_16 -> V_32 [ V_17 ] = F_10 ( V_7 ,
F_21 ( V_17 ) ) ;
}
for ( V_17 = 0 ; V_17 < 2 ; V_17 ++ ) {
V_16 -> V_29 [ V_17 ] = F_10 ( V_7 ,
F_22 ( V_17 ) ) ;
}
V_16 -> V_33 [ 0 ] = F_10 ( V_7 ,
F_23 ( 0 ) ) ;
V_16 -> V_33 [ 1 ] = F_10 ( V_7 ,
F_23 ( 1 ) ) ;
V_17 = F_10 ( V_7 , V_12 ) ;
V_16 -> V_9 [ 0 ] = ( V_17 >> 4 ) & 3 ;
V_16 -> V_9 [ 1 ] = ( V_17 >> 6 ) & 3 ;
V_16 -> V_34 = V_17 & 0x0f ;
V_16 -> V_34 |= ( F_10 ( V_7 ,
V_35 ) & 1 ) << 4 ;
V_16 -> V_36 = F_10 ( V_7 ,
V_37 ) ;
V_16 -> V_30 = V_19 ;
V_16 -> V_22 = 1 ;
}
F_24 ( & V_16 -> V_18 ) ;
return V_16 ;
}
static T_3 F_25 ( struct V_15 * V_13 , struct V_38 * V_39 ,
char * V_40 )
{
struct V_14 * V_16 = F_13 ( V_13 ) ;
return sprintf ( V_40 , L_2 , V_16 -> V_25 / 128 * 500 ) ;
}
static T_3 F_26 ( struct V_15 * V_13 , struct V_38 * V_41 ,
char * V_40 )
{
struct V_42 * V_43 = F_27 ( V_41 ) ;
struct V_14 * V_16 = F_13 ( V_13 ) ;
return sprintf ( V_40 , L_2 , V_16 -> V_33 [ V_43 -> V_44 ] * 1000 ) ;
}
static T_3 F_28 ( struct V_15 * V_13 , struct V_38 * V_41 ,
const char * V_40 , T_4 V_45 )
{
struct V_42 * V_43 = F_27 ( V_41 ) ;
struct V_14 * V_16 = F_14 ( V_13 ) ;
struct V_6 * V_7 = V_16 -> V_7 ;
long V_1 ;
int V_46 ;
V_46 = F_29 ( V_40 , 10 , & V_1 ) ;
if ( V_46 )
return V_46 ;
F_15 ( & V_16 -> V_18 ) ;
V_16 -> V_33 [ V_43 -> V_44 ] = F_5 ( V_1 ) ;
F_11 ( V_7 , F_23 ( V_43 -> V_44 ) ,
V_16 -> V_33 [ V_43 -> V_44 ] ) ;
F_24 ( & V_16 -> V_18 ) ;
return V_45 ;
}
static T_3 F_30 ( struct V_15 * V_13 , struct V_38 * V_41 ,
char * V_40 )
{
struct V_42 * V_43 = F_27 ( V_41 ) ;
struct V_14 * V_16 = F_13 ( V_13 ) ;
return sprintf ( V_40 , L_2 , F_2 ( V_16 -> V_23 [ V_43 -> V_44 ] ,
V_43 -> V_44 ) ) ;
}
static T_3 F_31 ( struct V_15 * V_13 ,
struct V_38 * V_41 , char * V_40 )
{
struct V_42 * V_43 = F_27 ( V_41 ) ;
struct V_14 * V_16 = F_13 ( V_13 ) ;
return sprintf ( V_40 , L_2 , F_2 ( V_16 -> V_31 [ V_43 -> V_44 ] ,
V_43 -> V_44 ) ) ;
}
static T_3 F_32 ( struct V_15 * V_13 ,
struct V_38 * V_41 , char * V_40 )
{
struct V_42 * V_43 = F_27 ( V_41 ) ;
struct V_14 * V_16 = F_13 ( V_13 ) ;
return sprintf ( V_40 , L_2 , F_2 ( V_16 -> V_32 [ V_43 -> V_44 ] ,
V_43 -> V_44 ) ) ;
}
static T_3 F_33 ( struct V_15 * V_13 ,
struct V_38 * V_41 ,
const char * V_40 , T_4 V_45 )
{
struct V_42 * V_43 = F_27 ( V_41 ) ;
struct V_14 * V_16 = F_14 ( V_13 ) ;
struct V_6 * V_7 = V_16 -> V_7 ;
unsigned long V_1 ;
int V_46 ;
V_46 = F_34 ( V_40 , 10 , & V_1 ) ;
if ( V_46 )
return V_46 ;
F_15 ( & V_16 -> V_18 ) ;
V_16 -> V_31 [ V_43 -> V_44 ] = F_3 ( V_1 , V_43 -> V_44 ) ;
F_11 ( V_7 , F_20 ( V_43 -> V_44 ) ,
V_16 -> V_31 [ V_43 -> V_44 ] ) ;
F_24 ( & V_16 -> V_18 ) ;
return V_45 ;
}
static T_3 F_35 ( struct V_15 * V_13 ,
struct V_38 * V_41 ,
const char * V_40 , T_4 V_45 )
{
struct V_42 * V_43 = F_27 ( V_41 ) ;
struct V_14 * V_16 = F_14 ( V_13 ) ;
struct V_6 * V_7 = V_16 -> V_7 ;
unsigned long V_1 ;
int V_46 ;
V_46 = F_34 ( V_40 , 10 , & V_1 ) ;
if ( V_46 )
return V_46 ;
F_15 ( & V_16 -> V_18 ) ;
V_16 -> V_32 [ V_43 -> V_44 ] = F_3 ( V_1 , V_43 -> V_44 ) ;
F_11 ( V_7 , F_21 ( V_43 -> V_44 ) ,
V_16 -> V_32 [ V_43 -> V_44 ] ) ;
F_24 ( & V_16 -> V_18 ) ;
return V_45 ;
}
static T_3 F_36 ( struct V_15 * V_13 ,
struct V_38 * V_41 , char * V_40 )
{
struct V_42 * V_43 = F_27 ( V_41 ) ;
struct V_14 * V_16 = F_13 ( V_13 ) ;
return sprintf ( V_40 , L_2 , F_6 ( V_16 -> V_28 [ V_43 -> V_44 ] ,
1 << V_16 -> V_9 [ V_43 -> V_44 ] ) ) ;
}
static T_3 F_37 ( struct V_15 * V_13 ,
struct V_38 * V_41 , char * V_40 )
{
struct V_42 * V_43 = F_27 ( V_41 ) ;
struct V_14 * V_16 = F_13 ( V_13 ) ;
return sprintf ( V_40 , L_2 , F_6 ( V_16 -> V_29 [ V_43 -> V_44 ] ,
1 << V_16 -> V_9 [ V_43 -> V_44 ] ) ) ;
}
static T_3 F_38 ( struct V_15 * V_13 ,
struct V_38 * V_41 , char * V_40 )
{
struct V_42 * V_43 = F_27 ( V_41 ) ;
struct V_14 * V_16 = F_13 ( V_13 ) ;
return sprintf ( V_40 , L_2 , 1 << V_16 -> V_9 [ V_43 -> V_44 ] ) ;
}
static T_3 F_39 ( struct V_15 * V_13 ,
struct V_38 * V_41 ,
const char * V_40 , T_4 V_45 )
{
struct V_42 * V_43 = F_27 ( V_41 ) ;
struct V_14 * V_16 = F_14 ( V_13 ) ;
struct V_6 * V_7 = V_16 -> V_7 ;
int V_8 = V_43 -> V_44 ;
T_1 V_47 ;
unsigned long V_1 ;
int V_46 ;
V_46 = F_34 ( V_40 , 10 , & V_1 ) ;
if ( V_46 )
return V_46 ;
F_15 ( & V_16 -> V_18 ) ;
if ( ! V_1 ) {
V_16 -> V_29 [ V_8 ] = 255 ;
V_47 = V_16 -> V_9 [ V_8 ] ;
F_12 ( & V_7 -> V_13 , L_3 ,
V_8 + 1 ) ;
} else if ( V_1 < 1350000 / ( 8 * 254 ) ) {
V_47 = 3 ;
V_16 -> V_29 [ V_8 ] = 254 ;
F_12 ( & V_7 -> V_13 , L_4 ,
V_8 + 1 , F_6 ( 254 , 1 << V_47 ) ) ;
} else {
unsigned int V_48 = 1350000 / V_1 ;
V_47 = 0 ;
while ( V_48 > 192 && V_47 < 3 ) {
V_47 ++ ;
V_48 /= 2 ;
}
if ( ! V_48 )
V_48 ++ ;
V_16 -> V_29 [ V_8 ] = V_48 ;
F_12 ( & V_7 -> V_13 , L_5 ,
V_8 + 1 , F_6 ( V_48 , 1 << V_47 ) ) ;
}
if ( V_47 != V_16 -> V_9 [ V_8 ] ) {
V_16 -> V_9 [ V_8 ] = V_47 ;
F_9 ( V_7 , V_8 , V_47 ) ;
}
F_11 ( V_7 , F_22 ( V_8 ) ,
V_16 -> V_29 [ V_8 ] ) ;
F_24 ( & V_16 -> V_18 ) ;
return V_45 ;
}
static T_3 F_40 ( struct V_15 * V_13 ,
struct V_38 * V_43 , char * V_40 )
{
struct V_14 * V_16 = F_13 ( V_13 ) ;
return sprintf ( V_40 , L_6 , V_16 -> V_24 ) ;
}
static T_3 F_41 ( struct V_15 * V_13 ,
struct V_38 * V_43 , char * V_40 )
{
int V_49 = F_27 ( V_43 ) -> V_44 ;
struct V_14 * V_16 = F_13 ( V_13 ) ;
return sprintf ( V_40 , L_6 , ( V_16 -> V_24 >> V_49 ) & 1 ) ;
}
static T_3 F_42 ( struct V_15 * V_13 ,
struct V_38 * V_43 , char * V_40 )
{
struct V_14 * V_16 = F_13 ( V_13 ) ;
return sprintf ( V_40 , L_2 , F_43 ( V_16 -> V_34 , V_16 -> V_50 ) ) ;
}
static T_3 F_44 ( struct V_15 * V_13 ,
struct V_38 * V_43 , char * V_40 )
{
struct V_14 * V_16 = F_13 ( V_13 ) ;
return sprintf ( V_40 , L_2 , F_8 ( V_16 -> V_36 ) ) ;
}
static T_3 F_45 ( struct V_15 * V_13 ,
struct V_38 * V_43 ,
const char * V_40 , T_4 V_45 )
{
struct V_14 * V_16 = F_14 ( V_13 ) ;
struct V_6 * V_7 = V_16 -> V_7 ;
long V_1 ;
int V_46 ;
V_46 = F_29 ( V_40 , 10 , & V_1 ) ;
if ( V_46 )
return V_46 ;
F_15 ( & V_16 -> V_18 ) ;
V_16 -> V_36 = F_7 ( V_1 ) ;
F_11 ( V_7 , V_37 , V_16 -> V_36 ) ;
F_24 ( & V_16 -> V_18 ) ;
return V_45 ;
}
static T_3 F_46 ( struct V_15 * V_13 ,
struct V_38 * V_43 ,
const char * V_40 , T_4 V_45 )
{
struct V_14 * V_16 = F_14 ( V_13 ) ;
struct V_6 * V_7 = V_16 -> V_7 ;
unsigned long V_1 ;
if ( F_34 ( V_40 , 10 , & V_1 ) || V_1 != 0 )
return - V_51 ;
F_15 ( & V_16 -> V_18 ) ;
F_11 ( V_7 , V_52 , 0x80 ) ;
V_16 -> V_22 = 0 ;
F_24 ( & V_16 -> V_18 ) ;
F_12 ( & V_7 -> V_13 , L_7 ) ;
return V_45 ;
}
static int F_47 ( struct V_6 * V_53 ,
struct V_54 * V_55 )
{
struct V_56 * V_57 = V_53 -> V_57 ;
const char * V_58 = L_8 ;
int V_59 = V_53 -> V_60 ;
T_1 V_61 , V_62 ;
if ( ! F_48 ( V_57 , V_63 ) )
return - V_64 ;
if ( F_10 ( V_53 , V_65 )
!= V_59 ) {
F_49 ( & V_57 -> V_13 , L_9 ,
V_59 ) ;
return - V_64 ;
}
V_61 = F_10 ( V_53 , V_66 ) ;
if ( V_61 == 0x23 ) {
V_58 = L_10 ;
} else if ( V_61 == 0xda ) {
V_58 = L_11 ;
} else if ( V_61 == 0x01 ) {
V_58 = L_12 ;
} else {
F_49 ( & V_57 -> V_13 , L_13 ,
V_61 ) ;
return - V_64 ;
}
V_62 = F_10 ( V_53 , V_67 ) ;
F_50 ( & V_57 -> V_13 , L_14 ,
V_61 == 0x23 ? L_15 :
V_61 == 0xda ? L_16 : L_17 , V_62 ) ;
F_51 ( V_55 -> type , V_58 , V_68 ) ;
return 0 ;
}
static void F_52 ( struct V_6 * V_7 )
{
struct V_14 * V_16 = F_53 ( V_7 ) ;
T_1 V_69 = F_10 ( V_7 , V_70 ) ;
T_1 V_71 = F_10 ( V_7 , V_27 ) & 3 ;
V_16 -> V_50 = F_54 () ;
F_50 ( & V_7 -> V_13 , L_18 , V_16 -> V_50 / 10 ,
V_16 -> V_50 % 10 ) ;
if ( V_69 & 1 ) {
F_50 ( & V_7 -> V_13 , L_19 ,
V_69 , V_71 ) ;
} else {
int V_17 ;
for ( V_17 = 0 ; V_17 < 6 ; V_17 ++ ) {
F_11 ( V_7 ,
F_20 ( V_17 ) , 0 ) ;
F_11 ( V_7 ,
F_21 ( V_17 ) , 255 ) ;
}
F_11 ( V_7 ,
F_22 ( 0 ) , 255 ) ;
F_11 ( V_7 ,
F_22 ( 1 ) , 255 ) ;
F_11 ( V_7 ,
F_23 ( 0 ) , 127 ) ;
F_11 ( V_7 ,
F_23 ( 1 ) , 127 ) ;
F_11 ( V_7 , V_70 , 1 ) ;
F_50 ( & V_7 -> V_13 ,
L_20 , V_69 , V_71 ) ;
}
}
static int F_55 ( struct V_6 * V_53 ,
const struct V_72 * V_73 )
{
struct V_15 * V_13 = & V_53 -> V_13 ;
struct V_15 * V_74 ;
struct V_14 * V_16 ;
V_16 = F_56 ( V_13 , sizeof( * V_16 ) , V_75 ) ;
if ( ! V_16 )
return - V_76 ;
F_57 ( V_53 , V_16 ) ;
V_16 -> V_7 = V_53 ;
F_58 ( & V_16 -> V_18 ) ;
F_52 ( V_53 ) ;
V_74 = F_59 ( V_13 ,
V_53 -> V_58 ,
V_16 ,
V_77 ) ;
return F_60 ( V_74 ) ;
}
