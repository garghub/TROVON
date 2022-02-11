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
long V_1 = F_16 ( V_10 , NULL , 10 ) ;
F_17 ( & V_12 -> V_22 ) ;
V_12 -> V_17 [ V_16 -> V_18 ] = F_5 ( V_1 ) ;
F_18 ( V_21 , F_19 ( V_16 -> V_18 ) ,
V_12 -> V_17 [ V_16 -> V_18 ] ) ;
F_20 ( & V_12 -> V_22 ) ;
return V_19 ;
}
static T_3 F_21 ( struct V_6 * V_7 , struct V_8 * V_14 ,
char * V_10 )
{
struct V_15 * V_16 = F_12 ( V_14 ) ;
struct V_11 * V_12 = F_10 ( V_7 ) ;
return sprintf ( V_10 , L_1 , F_2 ( V_12 -> V_23 [ V_16 -> V_18 ] ,
V_16 -> V_18 ) ) ;
}
static T_3 F_22 ( struct V_6 * V_7 ,
struct V_8 * V_14 , char * V_10 )
{
struct V_15 * V_16 = F_12 ( V_14 ) ;
struct V_11 * V_12 = F_10 ( V_7 ) ;
return sprintf ( V_10 , L_1 , F_2 ( V_12 -> V_24 [ V_16 -> V_18 ] ,
V_16 -> V_18 ) ) ;
}
static T_3 F_23 ( struct V_6 * V_7 ,
struct V_8 * V_14 , char * V_10 )
{
struct V_15 * V_16 = F_12 ( V_14 ) ;
struct V_11 * V_12 = F_10 ( V_7 ) ;
return sprintf ( V_10 , L_1 , F_2 ( V_12 -> V_25 [ V_16 -> V_18 ] ,
V_16 -> V_18 ) ) ;
}
static T_3 F_24 ( struct V_6 * V_7 ,
struct V_8 * V_14 ,
const char * V_10 , T_4 V_19 )
{
struct V_15 * V_16 = F_12 ( V_14 ) ;
struct V_20 * V_21 = F_14 ( V_7 ) ;
struct V_11 * V_12 = F_15 ( V_21 ) ;
unsigned long V_1 = F_25 ( V_10 , NULL , 10 ) ;
F_17 ( & V_12 -> V_22 ) ;
V_12 -> V_24 [ V_16 -> V_18 ] = F_3 ( V_1 , V_16 -> V_18 ) ;
F_18 ( V_21 , F_26 ( V_16 -> V_18 ) ,
V_12 -> V_24 [ V_16 -> V_18 ] ) ;
F_20 ( & V_12 -> V_22 ) ;
return V_19 ;
}
static T_3 F_27 ( struct V_6 * V_7 ,
struct V_8 * V_14 ,
const char * V_10 , T_4 V_19 )
{
struct V_15 * V_16 = F_12 ( V_14 ) ;
struct V_20 * V_21 = F_14 ( V_7 ) ;
struct V_11 * V_12 = F_15 ( V_21 ) ;
unsigned long V_1 = F_25 ( V_10 , NULL , 10 ) ;
F_17 ( & V_12 -> V_22 ) ;
V_12 -> V_25 [ V_16 -> V_18 ] = F_3 ( V_1 , V_16 -> V_18 ) ;
F_18 ( V_21 , F_28 ( V_16 -> V_18 ) ,
V_12 -> V_25 [ V_16 -> V_18 ] ) ;
F_20 ( & V_12 -> V_22 ) ;
return V_19 ;
}
static T_3 F_29 ( struct V_6 * V_7 ,
struct V_8 * V_14 , char * V_10 )
{
struct V_15 * V_16 = F_12 ( V_14 ) ;
struct V_11 * V_12 = F_10 ( V_7 ) ;
return sprintf ( V_10 , L_1 , F_6 ( V_12 -> V_26 [ V_16 -> V_18 ] ,
1 << V_12 -> V_27 [ V_16 -> V_18 ] ) ) ;
}
static T_3 F_30 ( struct V_6 * V_7 ,
struct V_8 * V_14 , char * V_10 )
{
struct V_15 * V_16 = F_12 ( V_14 ) ;
struct V_11 * V_12 = F_10 ( V_7 ) ;
return sprintf ( V_10 , L_1 , F_6 ( V_12 -> V_28 [ V_16 -> V_18 ] ,
1 << V_12 -> V_27 [ V_16 -> V_18 ] ) ) ;
}
static T_3 F_31 ( struct V_6 * V_7 ,
struct V_8 * V_14 , char * V_10 )
{
struct V_15 * V_16 = F_12 ( V_14 ) ;
struct V_11 * V_12 = F_10 ( V_7 ) ;
return sprintf ( V_10 , L_1 , 1 << V_12 -> V_27 [ V_16 -> V_18 ] ) ;
}
static void F_32 ( struct V_20 * V_21 , int V_29 ,
T_1 V_27 )
{
T_1 V_3 , V_30 , V_31 = ( V_29 + 2 ) * 2 ;
V_3 = F_33 ( V_21 , V_32 ) ;
V_30 = ( V_3 >> V_31 ) & 3 ;
V_3 &= ~ ( 3 << V_31 ) ;
V_3 |= ( V_27 << V_31 ) ;
F_18 ( V_21 , V_32 , V_3 ) ;
F_34 ( & V_21 -> V_7 , L_2
L_3 , V_29 + 1 , 1 << V_30 , 1 << V_27 ) ;
}
static T_3 F_35 ( struct V_6 * V_7 ,
struct V_8 * V_14 ,
const char * V_10 , T_4 V_19 )
{
struct V_15 * V_16 = F_12 ( V_14 ) ;
struct V_20 * V_21 = F_14 ( V_7 ) ;
struct V_11 * V_12 = F_15 ( V_21 ) ;
unsigned long V_1 = F_25 ( V_10 , NULL , 10 ) ;
int V_29 = V_16 -> V_18 ;
T_1 V_33 ;
F_17 ( & V_12 -> V_22 ) ;
if ( ! V_1 ) {
V_12 -> V_28 [ V_29 ] = 255 ;
V_33 = V_12 -> V_27 [ V_29 ] ;
F_34 ( & V_21 -> V_7 , L_4 ,
V_29 + 1 ) ;
} else if ( V_1 < 1350000 / ( 8 * 254 ) ) {
V_33 = 3 ;
V_12 -> V_28 [ V_29 ] = 254 ;
F_34 ( & V_21 -> V_7 , L_5 ,
V_29 + 1 , F_6 ( 254 , 1 << V_33 ) ) ;
} else {
unsigned int V_34 = 1350000 / V_1 ;
V_33 = 0 ;
while ( V_34 > 192 && V_33 < 3 ) {
V_33 ++ ;
V_34 /= 2 ;
}
if ( ! V_34 )
V_34 ++ ;
V_12 -> V_28 [ V_29 ] = V_34 ;
F_34 ( & V_21 -> V_7 , L_6 ,
V_29 + 1 , F_6 ( V_34 , 1 << V_33 ) ) ;
}
if ( V_33 != V_12 -> V_27 [ V_29 ] ) {
V_12 -> V_27 [ V_29 ] = V_33 ;
F_32 ( V_21 , V_29 , V_33 ) ;
}
F_18 ( V_21 , F_36 ( V_29 ) ,
V_12 -> V_28 [ V_29 ] ) ;
F_20 ( & V_12 -> V_22 ) ;
return V_19 ;
}
static T_3 F_37 ( struct V_6 * V_7 ,
struct V_8 * V_16 , char * V_10 )
{
struct V_11 * V_12 = F_10 ( V_7 ) ;
return sprintf ( V_10 , L_7 , V_12 -> V_35 ) ;
}
static T_3 F_38 ( struct V_6 * V_7 ,
struct V_8 * V_16 , char * V_10 )
{
int V_36 = F_12 ( V_16 ) -> V_18 ;
struct V_11 * V_12 = F_10 ( V_7 ) ;
return sprintf ( V_10 , L_7 , ( V_12 -> V_35 >> V_36 ) & 1 ) ;
}
static T_3 F_39 ( struct V_6 * V_7 ,
struct V_8 * V_16 , char * V_10 )
{
struct V_11 * V_12 = F_10 ( V_7 ) ;
return sprintf ( V_10 , L_1 , F_40 ( V_12 -> V_37 , V_12 -> V_38 ) ) ;
}
static T_3 F_41 ( struct V_6 * V_7 ,
struct V_8 * V_16 , char * V_10 )
{
struct V_11 * V_12 = F_10 ( V_7 ) ;
return sprintf ( V_10 , L_1 , F_8 ( V_12 -> V_39 ) ) ;
}
static T_3 F_42 ( struct V_6 * V_7 ,
struct V_8 * V_16 ,
const char * V_10 , T_4 V_19 )
{
struct V_20 * V_21 = F_14 ( V_7 ) ;
struct V_11 * V_12 = F_15 ( V_21 ) ;
unsigned long V_1 = F_16 ( V_10 , NULL , 10 ) ;
F_17 ( & V_12 -> V_22 ) ;
V_12 -> V_39 = F_7 ( V_1 ) ;
F_18 ( V_21 , V_40 , V_12 -> V_39 ) ;
F_20 ( & V_12 -> V_22 ) ;
return V_19 ;
}
static T_3 F_43 ( struct V_6 * V_7 ,
struct V_8 * V_16 ,
const char * V_10 , T_4 V_19 )
{
struct V_20 * V_21 = F_14 ( V_7 ) ;
unsigned long V_1 = F_16 ( V_10 , NULL , 10 ) ;
F_44 ( V_7 , L_8
L_9 ) ;
if ( V_1 == 1 ) {
F_18 ( V_21 ,
V_41 , 0x80 ) ;
F_34 ( & V_21 -> V_7 , L_10 ) ;
}
return V_19 ;
}
static T_3 F_45 ( struct V_6 * V_7 ,
struct V_8 * V_16 ,
const char * V_10 , T_4 V_19 )
{
struct V_20 * V_21 = F_14 ( V_7 ) ;
struct V_11 * V_12 = F_15 ( V_21 ) ;
unsigned long V_1 ;
if ( F_46 ( V_10 , 10 , & V_1 ) || V_1 != 0 )
return - V_42 ;
F_17 ( & V_12 -> V_22 ) ;
F_18 ( V_21 , V_41 , 0x80 ) ;
V_12 -> V_43 = 0 ;
F_20 ( & V_12 -> V_22 ) ;
F_34 ( & V_21 -> V_7 , L_10 ) ;
return V_19 ;
}
static int F_47 ( struct V_20 * V_44 ,
struct V_45 * V_46 )
{
struct V_47 * V_48 = V_44 -> V_48 ;
const char * V_49 = L_11 ;
int V_50 = V_44 -> V_51 ;
T_1 V_52 , V_53 ;
if ( ! F_48 ( V_48 , V_54 ) )
return - V_55 ;
if ( F_33 ( V_44 , V_56 )
!= V_50 ) {
F_49 ( & V_48 -> V_7 , L_12 ,
V_50 ) ;
return - V_55 ;
}
V_52 = F_33 ( V_44 , V_57 ) ;
if ( V_52 == 0x23 ) {
V_49 = L_13 ;
} else if ( V_52 == 0xda ) {
V_49 = L_14 ;
} else if ( V_52 == 0x01 ) {
V_49 = L_15 ;
} else {
F_49 ( & V_48 -> V_7 , L_16 ,
V_52 ) ;
return - V_55 ;
}
V_53 = F_33 ( V_44 , V_58 ) ;
F_50 ( & V_48 -> V_7 , L_17 ,
V_52 == 0x23 ? L_18 :
V_52 == 0xda ? L_19 : L_20 , V_53 ) ;
F_51 ( V_46 -> type , V_49 , V_59 ) ;
return 0 ;
}
static int F_52 ( struct V_20 * V_44 ,
const struct V_60 * V_61 )
{
struct V_11 * V_12 ;
int V_62 ;
V_12 = F_53 ( sizeof( * V_12 ) , V_63 ) ;
if ( ! V_12 ) {
V_62 = - V_64 ;
goto exit;
}
F_54 ( V_44 , V_12 ) ;
F_55 ( & V_12 -> V_22 ) ;
F_56 ( V_44 ) ;
if ( ( V_62 = F_57 ( & V_44 -> V_7 . V_65 , & V_66 ) ) )
goto V_67;
V_12 -> V_68 = F_58 ( & V_44 -> V_7 ) ;
if ( F_59 ( V_12 -> V_68 ) ) {
V_62 = F_60 ( V_12 -> V_68 ) ;
goto V_69;
}
return 0 ;
V_69:
F_61 ( & V_44 -> V_7 . V_65 , & V_66 ) ;
V_67:
F_62 ( V_12 ) ;
exit:
return V_62 ;
}
static int F_63 ( struct V_20 * V_21 )
{
struct V_11 * V_12 = F_15 ( V_21 ) ;
F_64 ( V_12 -> V_68 ) ;
F_61 ( & V_21 -> V_7 . V_65 , & V_66 ) ;
F_62 ( V_12 ) ;
return 0 ;
}
static void F_56 ( struct V_20 * V_21 )
{
struct V_11 * V_12 = F_15 ( V_21 ) ;
T_1 V_70 = F_33 ( V_21 , V_71 ) ;
T_1 V_72 = F_33 ( V_21 , V_73 ) & 3 ;
V_12 -> V_38 = F_65 () ;
F_50 ( & V_21 -> V_7 , L_21 , V_12 -> V_38 / 10 ,
V_12 -> V_38 % 10 ) ;
if ( V_70 & 1 ) {
F_50 ( & V_21 -> V_7 , L_22 ,
V_70 , V_72 ) ;
} else {
int V_74 ;
for ( V_74 = 0 ; V_74 < 6 ; V_74 ++ )
{
F_18 ( V_21 ,
F_26 ( V_74 ) , 0 ) ;
F_18 ( V_21 ,
F_28 ( V_74 ) , 255 ) ;
}
F_18 ( V_21 ,
F_36 ( 0 ) , 255 ) ;
F_18 ( V_21 ,
F_36 ( 1 ) , 255 ) ;
F_18 ( V_21 ,
F_19 ( 0 ) , 127 ) ;
F_18 ( V_21 ,
F_19 ( 1 ) , 127 ) ;
F_18 ( V_21 , V_71 , 1 ) ;
F_50 ( & V_21 -> V_7 , L_23
L_24 , V_70 , V_72 ) ;
}
}
static struct V_11 * F_10 ( struct V_6 * V_7 )
{
struct V_20 * V_21 = F_14 ( V_7 ) ;
struct V_11 * V_12 = F_15 ( V_21 ) ;
int V_74 ;
F_17 ( & V_12 -> V_22 ) ;
if ( F_66 ( V_75 , V_12 -> V_76 + ( V_77 * 7 / 4 ) )
|| ! V_12 -> V_43 ) {
for ( V_74 = 0 ; V_74 < 6 ; V_74 ++ )
{
V_12 -> V_23 [ V_74 ] = F_33 ( V_21 ,
F_67 ( V_74 ) ) ;
}
V_12 -> V_35 = F_33 ( V_21 ,
F_68 ( 0 ) ) |
F_33 ( V_21 ,
F_68 ( 1 ) ) << 8 ;
V_12 -> V_13 = ( ( F_33 ( V_21 ,
V_78 ) << 8 ) |
F_33 ( V_21 ,
V_73 ) ) / 128 ;
for ( V_74 = 0 ; V_74 < 2 ; V_74 ++ )
{
V_12 -> V_26 [ V_74 ] = F_33 ( V_21 ,
F_69 ( V_74 ) ) ;
if ( V_12 -> V_43 && V_12 -> V_26 [ V_74 ] == 255 &&
V_12 -> V_27 [ V_74 ] < 3 ) {
F_32 ( V_21 , V_74 ,
++ V_12 -> V_27 [ V_74 ] ) ;
if ( V_12 -> V_28 [ V_74 ] < 255 &&
V_12 -> V_28 [ V_74 ] >= 2 )
V_12 -> V_28 [ V_74 ] /= 2 ;
}
}
V_12 -> V_76 = V_75 ;
}
if ( F_66 ( V_75 , V_12 -> V_79 + ( V_77 * 300 ) )
|| ! V_12 -> V_43 ) {
for ( V_74 = 0 ; V_74 < 6 ; V_74 ++ )
{
V_12 -> V_24 [ V_74 ] = F_33 ( V_21 ,
F_26 ( V_74 ) ) ;
V_12 -> V_25 [ V_74 ] = F_33 ( V_21 ,
F_28 ( V_74 ) ) ;
}
for ( V_74 = 0 ; V_74 < 2 ; V_74 ++ )
{
V_12 -> V_28 [ V_74 ] = F_33 ( V_21 ,
F_36 ( V_74 ) ) ;
}
V_12 -> V_17 [ 0 ] = F_33 ( V_21 ,
F_19 ( 0 ) ) ;
V_12 -> V_17 [ 1 ] = F_33 ( V_21 ,
F_19 ( 1 ) ) ;
V_74 = F_33 ( V_21 , V_32 ) ;
V_12 -> V_27 [ 0 ] = ( V_74 >> 4 ) & 3 ;
V_12 -> V_27 [ 1 ] = ( V_74 >> 6 ) & 3 ;
V_12 -> V_37 = V_74 & 0x0f ;
V_12 -> V_37 |= ( F_33 ( V_21 ,
V_80 ) & 1 ) << 4 ;
V_12 -> V_39 = F_33 ( V_21 ,
V_40 ) ;
V_12 -> V_79 = V_75 ;
V_12 -> V_43 = 1 ;
}
F_20 ( & V_12 -> V_22 ) ;
return V_12 ;
}
static int T_5 F_70 ( void )
{
return F_71 ( & V_81 ) ;
}
static void T_6 F_72 ( void )
{
F_73 ( & V_81 ) ;
}
