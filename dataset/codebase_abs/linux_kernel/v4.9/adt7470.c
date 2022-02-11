static inline int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
T_2 V_4 ;
V_4 = F_2 ( V_2 , V_3 ) ;
V_4 |= ( ( T_2 ) F_2 ( V_2 , V_3 + 1 ) << 8 ) ;
return V_4 ;
}
static inline int F_3 ( struct V_1 * V_2 , T_1 V_3 ,
T_2 V_5 )
{
return F_4 ( V_2 , V_3 , V_5 & 0xFF )
|| F_4 ( V_2 , V_3 + 1 , V_5 >> 8 ) ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_6 * V_7 )
{
unsigned long V_8 ;
int V_9 ;
T_1 V_10 , V_11 [ 4 ] , V_12 [ 2 ] ;
V_12 [ 0 ] = F_2 ( V_2 , F_6 ( 0 ) ) ;
V_12 [ 1 ] = F_2 ( V_2 , F_6 ( 2 ) ) ;
for ( V_9 = 0 ; V_9 < V_13 ; V_9 ++ )
V_11 [ V_9 ] = F_2 ( V_2 , F_7 ( V_9 ) ) ;
F_4 ( V_2 , F_6 ( 0 ) ,
V_12 [ 0 ] & ~ ( V_14 ) ) ;
F_4 ( V_2 , F_6 ( 2 ) ,
V_12 [ 1 ] & ~ ( V_14 ) ) ;
for ( V_9 = 0 ; V_9 < V_13 ; V_9 ++ )
F_4 ( V_2 , F_7 ( V_9 ) , V_11 [ V_9 ] ) ;
V_10 = F_2 ( V_2 , V_15 ) ;
V_10 |= 0x80 ;
F_4 ( V_2 , V_15 , V_10 ) ;
V_8 = F_8 ( ( V_7 -> V_16 >= 0 ?
V_7 -> V_16 * 200 :
V_17 ) ) ;
V_10 = F_2 ( V_2 , V_15 ) ;
V_10 &= ~ 0x80 ;
F_4 ( V_2 , V_15 , V_10 ) ;
F_4 ( V_2 , F_6 ( 0 ) , V_12 [ 0 ] ) ;
F_4 ( V_2 , F_6 ( 2 ) , V_12 [ 1 ] ) ;
if ( V_8 ) {
F_9 ( L_1 ) ;
return - V_18 ;
}
if ( V_7 -> V_16 >= 0 )
return 0 ;
for ( V_9 = 0 ; V_9 < V_19 ; V_9 ++ ) {
V_7 -> V_20 [ V_9 ] = F_2 ( V_2 ,
F_10 ( V_9 ) ) ;
if ( V_7 -> V_20 [ V_9 ] )
V_7 -> V_16 = V_9 + 1 ;
}
V_7 -> V_21 = 1 ;
return 0 ;
}
static int F_11 ( void * V_22 )
{
struct V_1 * V_2 = V_22 ;
struct V_6 * V_7 = F_12 ( V_2 ) ;
while ( ! F_13 () ) {
F_14 ( & V_7 -> V_23 ) ;
F_5 ( V_2 , V_7 ) ;
F_15 ( & V_7 -> V_23 ) ;
F_16 ( V_24 ) ;
if ( F_13 () )
break;
F_17 ( F_18 ( V_7 -> V_25 ) ) ;
}
return 0 ;
}
static struct V_6 * F_19 ( struct V_26 * V_27 )
{
struct V_6 * V_7 = F_20 ( V_27 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
unsigned long V_28 = V_29 ;
T_1 V_10 ;
int V_9 ;
int V_30 = 1 ;
int V_31 = 1 ;
if ( F_21 ( V_28 , V_7 -> V_32 +
V_33 ) &&
V_7 -> V_34 )
V_30 = 0 ;
if ( F_21 ( V_28 , V_7 -> V_35 +
V_36 ) &&
V_7 -> V_37 )
V_31 = 0 ;
if ( ! V_30 && ! V_31 )
return V_7 ;
F_14 ( & V_7 -> V_23 ) ;
if ( ! V_30 )
goto V_38;
if ( ! V_7 -> V_21 )
F_5 ( V_2 , V_7 ) ;
else
for ( V_9 = 0 ; V_9 < V_19 ; V_9 ++ )
V_7 -> V_20 [ V_9 ] = F_2 ( V_2 ,
F_10 ( V_9 ) ) ;
for ( V_9 = 0 ; V_9 < V_13 ; V_9 ++ )
V_7 -> V_39 [ V_9 ] = F_1 ( V_2 ,
F_22 ( V_9 ) ) ;
for ( V_9 = 0 ; V_9 < V_40 ; V_9 ++ ) {
int V_3 ;
int V_41 ;
V_7 -> V_11 [ V_9 ] = F_2 ( V_2 ,
F_7 ( V_9 ) ) ;
if ( V_9 % 2 )
V_41 = V_42 ;
else
V_41 = V_43 ;
V_3 = F_6 ( V_9 ) ;
if ( F_2 ( V_2 , V_3 ) & V_41 )
V_7 -> V_44 [ V_9 ] = 1 ;
else
V_7 -> V_44 [ V_9 ] = 0 ;
V_3 = F_23 ( V_9 ) ;
V_10 = F_2 ( V_2 , V_3 ) ;
if ( ! ( V_9 % 2 ) )
V_7 -> V_45 [ V_9 ] = V_10 >> 4 ;
else
V_7 -> V_45 [ V_9 ] = V_10 & 0xF ;
}
if ( F_2 ( V_2 , V_15 ) &
V_46 )
V_7 -> V_47 = 1 ;
else
V_7 -> V_47 = 0 ;
V_7 -> V_48 = F_2 ( V_2 , V_49 ) ;
if ( V_7 -> V_48 & V_50 )
V_7 -> V_48 |= F_24 ( F_2 ( V_2 ,
V_51 ) ) ;
V_7 -> V_52 = F_1 ( V_2 ,
V_53 ) ;
V_7 -> V_32 = V_28 ;
V_7 -> V_34 = 1 ;
V_38:
if ( ! V_31 )
goto V_54;
for ( V_9 = 0 ; V_9 < V_19 ; V_9 ++ ) {
V_7 -> V_55 [ V_9 ] = F_2 ( V_2 ,
F_25 ( V_9 ) ) ;
V_7 -> V_56 [ V_9 ] = F_2 ( V_2 ,
F_26 ( V_9 ) ) ;
}
for ( V_9 = 0 ; V_9 < V_13 ; V_9 ++ ) {
V_7 -> V_57 [ V_9 ] = F_1 ( V_2 ,
F_27 ( V_9 ) ) ;
V_7 -> V_58 [ V_9 ] = F_1 ( V_2 ,
F_28 ( V_9 ) ) ;
}
for ( V_9 = 0 ; V_9 < V_40 ; V_9 ++ ) {
V_7 -> V_59 [ V_9 ] = F_2 ( V_2 ,
F_29 ( V_9 ) ) ;
V_7 -> V_60 [ V_9 ] = F_2 ( V_2 ,
F_30 ( V_9 ) ) ;
V_7 -> V_61 [ V_9 ] = F_2 ( V_2 ,
F_31 ( V_9 ) ) ;
}
V_7 -> V_35 = V_28 ;
V_7 -> V_37 = 1 ;
V_54:
F_15 ( & V_7 -> V_23 ) ;
return V_7 ;
}
static T_3 F_32 ( struct V_26 * V_27 ,
struct V_62 * V_63 ,
char * V_64 )
{
struct V_6 * V_7 = F_19 ( V_27 ) ;
return sprintf ( V_64 , L_2 , V_7 -> V_25 ) ;
}
static T_3 F_33 ( struct V_26 * V_27 ,
struct V_62 * V_63 ,
const char * V_64 ,
T_4 V_65 )
{
struct V_6 * V_7 = F_20 ( V_27 ) ;
long V_20 ;
if ( F_34 ( V_64 , 10 , & V_20 ) )
return - V_66 ;
V_20 = F_35 ( V_20 , 0 , 60000 ) ;
F_14 ( & V_7 -> V_23 ) ;
V_7 -> V_25 = V_20 ;
F_15 ( & V_7 -> V_23 ) ;
return V_65 ;
}
static T_3 F_36 ( struct V_26 * V_27 ,
struct V_62 * V_63 ,
char * V_64 )
{
struct V_6 * V_7 = F_19 ( V_27 ) ;
return sprintf ( V_64 , L_2 , V_7 -> V_16 ) ;
}
static T_3 F_37 ( struct V_26 * V_27 ,
struct V_62 * V_63 ,
const char * V_64 ,
T_4 V_65 )
{
struct V_6 * V_7 = F_20 ( V_27 ) ;
long V_20 ;
if ( F_34 ( V_64 , 10 , & V_20 ) )
return - V_66 ;
V_20 = F_35 ( V_20 , - 1 , 10 ) ;
F_14 ( & V_7 -> V_23 ) ;
V_7 -> V_16 = V_20 ;
if ( V_20 < 0 )
V_7 -> V_21 = 0 ;
F_15 ( & V_7 -> V_23 ) ;
return V_65 ;
}
static T_3 F_38 ( struct V_26 * V_27 ,
struct V_62 * V_63 ,
char * V_64 )
{
struct V_67 * V_68 = F_39 ( V_63 ) ;
struct V_6 * V_7 = F_19 ( V_27 ) ;
return sprintf ( V_64 , L_2 , 1000 * V_7 -> V_55 [ V_68 -> V_69 ] ) ;
}
static T_3 F_40 ( struct V_26 * V_27 ,
struct V_62 * V_63 ,
const char * V_64 ,
T_4 V_65 )
{
struct V_67 * V_68 = F_39 ( V_63 ) ;
struct V_6 * V_7 = F_20 ( V_27 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
long V_20 ;
if ( F_34 ( V_64 , 10 , & V_20 ) )
return - V_66 ;
V_20 = F_41 ( V_20 , 1000 ) ;
V_20 = F_35 ( V_20 , - 128 , 127 ) ;
F_14 ( & V_7 -> V_23 ) ;
V_7 -> V_55 [ V_68 -> V_69 ] = V_20 ;
F_4 ( V_2 , F_25 ( V_68 -> V_69 ) ,
V_20 ) ;
F_15 ( & V_7 -> V_23 ) ;
return V_65 ;
}
static T_3 F_42 ( struct V_26 * V_27 ,
struct V_62 * V_63 ,
char * V_64 )
{
struct V_67 * V_68 = F_39 ( V_63 ) ;
struct V_6 * V_7 = F_19 ( V_27 ) ;
return sprintf ( V_64 , L_2 , 1000 * V_7 -> V_56 [ V_68 -> V_69 ] ) ;
}
static T_3 F_43 ( struct V_26 * V_27 ,
struct V_62 * V_63 ,
const char * V_64 ,
T_4 V_65 )
{
struct V_67 * V_68 = F_39 ( V_63 ) ;
struct V_6 * V_7 = F_20 ( V_27 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
long V_20 ;
if ( F_34 ( V_64 , 10 , & V_20 ) )
return - V_66 ;
V_20 = F_41 ( V_20 , 1000 ) ;
V_20 = F_35 ( V_20 , - 128 , 127 ) ;
F_14 ( & V_7 -> V_23 ) ;
V_7 -> V_56 [ V_68 -> V_69 ] = V_20 ;
F_4 ( V_2 , F_26 ( V_68 -> V_69 ) ,
V_20 ) ;
F_15 ( & V_7 -> V_23 ) ;
return V_65 ;
}
static T_3 F_44 ( struct V_26 * V_27 , struct V_62 * V_63 ,
char * V_64 )
{
struct V_67 * V_68 = F_39 ( V_63 ) ;
struct V_6 * V_7 = F_19 ( V_27 ) ;
return sprintf ( V_64 , L_2 , 1000 * V_7 -> V_20 [ V_68 -> V_69 ] ) ;
}
static T_3 F_45 ( struct V_26 * V_27 ,
struct V_62 * V_63 ,
char * V_64 )
{
struct V_6 * V_7 = F_19 ( V_27 ) ;
return sprintf ( V_64 , L_3 , V_7 -> V_52 ) ;
}
static T_3 F_46 ( struct V_26 * V_27 ,
struct V_62 * V_63 ,
const char * V_64 ,
T_4 V_65 )
{
struct V_6 * V_7 = F_20 ( V_27 ) ;
long V_70 ;
if ( F_47 ( V_64 , 0 , & V_70 ) )
return - V_66 ;
if ( V_70 & ~ 0xffff )
return - V_66 ;
F_14 ( & V_7 -> V_23 ) ;
V_7 -> V_52 = V_70 ;
F_3 ( V_7 -> V_2 , V_53 , V_70 ) ;
F_15 ( & V_7 -> V_23 ) ;
return V_65 ;
}
static T_3 F_48 ( struct V_26 * V_27 ,
struct V_62 * V_63 ,
char * V_64 )
{
struct V_67 * V_68 = F_39 ( V_63 ) ;
struct V_6 * V_7 = F_19 ( V_27 ) ;
if ( F_49 ( V_7 -> V_58 [ V_68 -> V_69 ] ) )
return sprintf ( V_64 , L_2 ,
F_50 ( V_7 -> V_58 [ V_68 -> V_69 ] ) ) ;
else
return sprintf ( V_64 , L_4 ) ;
}
static T_3 F_51 ( struct V_26 * V_27 ,
struct V_62 * V_63 ,
const char * V_64 , T_4 V_65 )
{
struct V_67 * V_68 = F_39 ( V_63 ) ;
struct V_6 * V_7 = F_20 ( V_27 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
long V_20 ;
if ( F_34 ( V_64 , 10 , & V_20 ) || ! V_20 )
return - V_66 ;
V_20 = F_52 ( V_20 ) ;
V_20 = F_35 ( V_20 , 1 , 65534 ) ;
F_14 ( & V_7 -> V_23 ) ;
V_7 -> V_58 [ V_68 -> V_69 ] = V_20 ;
F_3 ( V_2 , F_28 ( V_68 -> V_69 ) , V_20 ) ;
F_15 ( & V_7 -> V_23 ) ;
return V_65 ;
}
static T_3 F_53 ( struct V_26 * V_27 ,
struct V_62 * V_63 ,
char * V_64 )
{
struct V_67 * V_68 = F_39 ( V_63 ) ;
struct V_6 * V_7 = F_19 ( V_27 ) ;
if ( F_49 ( V_7 -> V_57 [ V_68 -> V_69 ] ) )
return sprintf ( V_64 , L_2 ,
F_50 ( V_7 -> V_57 [ V_68 -> V_69 ] ) ) ;
else
return sprintf ( V_64 , L_4 ) ;
}
static T_3 F_54 ( struct V_26 * V_27 ,
struct V_62 * V_63 ,
const char * V_64 , T_4 V_65 )
{
struct V_67 * V_68 = F_39 ( V_63 ) ;
struct V_6 * V_7 = F_20 ( V_27 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
long V_20 ;
if ( F_34 ( V_64 , 10 , & V_20 ) || ! V_20 )
return - V_66 ;
V_20 = F_52 ( V_20 ) ;
V_20 = F_35 ( V_20 , 1 , 65534 ) ;
F_14 ( & V_7 -> V_23 ) ;
V_7 -> V_57 [ V_68 -> V_69 ] = V_20 ;
F_3 ( V_2 , F_27 ( V_68 -> V_69 ) , V_20 ) ;
F_15 ( & V_7 -> V_23 ) ;
return V_65 ;
}
static T_3 F_55 ( struct V_26 * V_27 , struct V_62 * V_63 ,
char * V_64 )
{
struct V_67 * V_68 = F_39 ( V_63 ) ;
struct V_6 * V_7 = F_19 ( V_27 ) ;
if ( F_49 ( V_7 -> V_39 [ V_68 -> V_69 ] ) )
return sprintf ( V_64 , L_2 ,
F_50 ( V_7 -> V_39 [ V_68 -> V_69 ] ) ) ;
else
return sprintf ( V_64 , L_4 ) ;
}
static T_3 F_56 ( struct V_26 * V_27 ,
struct V_62 * V_63 ,
char * V_64 )
{
struct V_6 * V_7 = F_19 ( V_27 ) ;
return sprintf ( V_64 , L_2 , V_7 -> V_47 ) ;
}
static T_3 F_57 ( struct V_26 * V_27 ,
struct V_62 * V_63 ,
const char * V_64 ,
T_4 V_65 )
{
struct V_6 * V_7 = F_20 ( V_27 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
long V_20 ;
T_1 V_3 ;
if ( F_34 ( V_64 , 10 , & V_20 ) )
return - V_66 ;
F_14 ( & V_7 -> V_23 ) ;
V_7 -> V_47 = V_20 ;
V_3 = F_2 ( V_2 , V_15 ) ;
if ( V_20 )
V_3 |= V_46 ;
else
V_3 &= ~ V_46 ;
F_4 ( V_2 , V_15 , V_3 ) ;
F_15 ( & V_7 -> V_23 ) ;
return V_65 ;
}
static T_3 F_58 ( struct V_26 * V_27 , struct V_62 * V_63 ,
char * V_64 )
{
struct V_67 * V_68 = F_39 ( V_63 ) ;
struct V_6 * V_7 = F_19 ( V_27 ) ;
return sprintf ( V_64 , L_2 , V_7 -> V_11 [ V_68 -> V_69 ] ) ;
}
static T_3 F_59 ( struct V_26 * V_27 , struct V_62 * V_63 ,
const char * V_64 , T_4 V_65 )
{
struct V_67 * V_68 = F_39 ( V_63 ) ;
struct V_6 * V_7 = F_20 ( V_27 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
long V_20 ;
if ( F_34 ( V_64 , 10 , & V_20 ) )
return - V_66 ;
V_20 = F_35 ( V_20 , 0 , 255 ) ;
F_14 ( & V_7 -> V_23 ) ;
V_7 -> V_11 [ V_68 -> V_69 ] = V_20 ;
F_4 ( V_2 , F_7 ( V_68 -> V_69 ) , V_20 ) ;
F_15 ( & V_7 -> V_23 ) ;
return V_65 ;
}
static T_3 F_60 ( struct V_26 * V_27 ,
struct V_62 * V_63 , char * V_64 )
{
struct V_6 * V_7 = F_19 ( V_27 ) ;
unsigned char V_71 ;
unsigned char V_72 ;
int V_69 ;
F_14 ( & V_7 -> V_23 ) ;
V_71 = F_2 ( V_7 -> V_2 , V_15 ) ;
V_72 = F_2 ( V_7 -> V_2 , V_73 ) ;
F_15 ( & V_7 -> V_23 ) ;
V_69 = ( V_72 & V_74 ) >> V_75 ;
if ( ! ( V_71 & V_76 ) )
V_69 += 8 ;
if ( V_69 >= F_61 ( V_77 ) )
V_69 = F_61 ( V_77 ) - 1 ;
return F_62 ( V_64 , V_78 , L_2 , V_77 [ V_69 ] ) ;
}
static T_3 F_63 ( struct V_26 * V_27 ,
struct V_62 * V_63 ,
const char * V_64 , T_4 V_65 )
{
struct V_6 * V_7 = F_20 ( V_27 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
long V_79 ;
int V_69 ;
int V_80 = V_76 ;
unsigned char V_81 ;
if ( F_34 ( V_64 , 10 , & V_79 ) )
return - V_66 ;
V_69 = F_64 ( V_79 , V_77 ,
F_61 ( V_77 ) ) ;
if ( V_69 >= 8 ) {
V_69 -= 8 ;
V_80 = 0 ;
}
F_14 ( & V_7 -> V_23 ) ;
V_81 = F_2 ( V_2 , V_15 ) ;
F_4 ( V_2 , V_15 ,
( V_81 & ~ V_76 ) | V_80 ) ;
V_81 = F_2 ( V_2 , V_73 ) ;
F_4 ( V_2 , V_73 ,
( V_81 & ~ V_74 ) | ( V_69 << V_75 ) ) ;
F_15 ( & V_7 -> V_23 ) ;
return V_65 ;
}
static T_3 F_65 ( struct V_26 * V_27 ,
struct V_62 * V_63 ,
char * V_64 )
{
struct V_67 * V_68 = F_39 ( V_63 ) ;
struct V_6 * V_7 = F_19 ( V_27 ) ;
return sprintf ( V_64 , L_2 , V_7 -> V_59 [ V_68 -> V_69 ] ) ;
}
static T_3 F_66 ( struct V_26 * V_27 ,
struct V_62 * V_63 ,
const char * V_64 ,
T_4 V_65 )
{
struct V_67 * V_68 = F_39 ( V_63 ) ;
struct V_6 * V_7 = F_20 ( V_27 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
long V_20 ;
if ( F_34 ( V_64 , 10 , & V_20 ) )
return - V_66 ;
V_20 = F_35 ( V_20 , 0 , 255 ) ;
F_14 ( & V_7 -> V_23 ) ;
V_7 -> V_59 [ V_68 -> V_69 ] = V_20 ;
F_4 ( V_2 , F_29 ( V_68 -> V_69 ) ,
V_20 ) ;
F_15 ( & V_7 -> V_23 ) ;
return V_65 ;
}
static T_3 F_67 ( struct V_26 * V_27 ,
struct V_62 * V_63 ,
char * V_64 )
{
struct V_67 * V_68 = F_39 ( V_63 ) ;
struct V_6 * V_7 = F_19 ( V_27 ) ;
return sprintf ( V_64 , L_2 , V_7 -> V_60 [ V_68 -> V_69 ] ) ;
}
static T_3 F_68 ( struct V_26 * V_27 ,
struct V_62 * V_63 ,
const char * V_64 ,
T_4 V_65 )
{
struct V_67 * V_68 = F_39 ( V_63 ) ;
struct V_6 * V_7 = F_20 ( V_27 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
long V_20 ;
if ( F_34 ( V_64 , 10 , & V_20 ) )
return - V_66 ;
V_20 = F_35 ( V_20 , 0 , 255 ) ;
F_14 ( & V_7 -> V_23 ) ;
V_7 -> V_60 [ V_68 -> V_69 ] = V_20 ;
F_4 ( V_2 , F_30 ( V_68 -> V_69 ) ,
V_20 ) ;
F_15 ( & V_7 -> V_23 ) ;
return V_65 ;
}
static T_3 F_69 ( struct V_26 * V_27 ,
struct V_62 * V_63 ,
char * V_64 )
{
struct V_67 * V_68 = F_39 ( V_63 ) ;
struct V_6 * V_7 = F_19 ( V_27 ) ;
return sprintf ( V_64 , L_2 , 1000 * ( 20 + V_7 -> V_61 [ V_68 -> V_69 ] ) ) ;
}
static T_3 F_70 ( struct V_26 * V_27 ,
struct V_62 * V_63 ,
char * V_64 )
{
struct V_67 * V_68 = F_39 ( V_63 ) ;
struct V_6 * V_7 = F_19 ( V_27 ) ;
return sprintf ( V_64 , L_2 , 1000 * V_7 -> V_61 [ V_68 -> V_69 ] ) ;
}
static T_3 F_71 ( struct V_26 * V_27 ,
struct V_62 * V_63 ,
const char * V_64 ,
T_4 V_65 )
{
struct V_67 * V_68 = F_39 ( V_63 ) ;
struct V_6 * V_7 = F_20 ( V_27 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
long V_20 ;
if ( F_34 ( V_64 , 10 , & V_20 ) )
return - V_66 ;
V_20 = F_41 ( V_20 , 1000 ) ;
V_20 = F_35 ( V_20 , - 128 , 127 ) ;
F_14 ( & V_7 -> V_23 ) ;
V_7 -> V_61 [ V_68 -> V_69 ] = V_20 ;
F_4 ( V_2 , F_31 ( V_68 -> V_69 ) ,
V_20 ) ;
F_15 ( & V_7 -> V_23 ) ;
return V_65 ;
}
static T_3 F_72 ( struct V_26 * V_27 ,
struct V_62 * V_63 ,
char * V_64 )
{
struct V_67 * V_68 = F_39 ( V_63 ) ;
struct V_6 * V_7 = F_19 ( V_27 ) ;
return sprintf ( V_64 , L_2 , 1 + V_7 -> V_44 [ V_68 -> V_69 ] ) ;
}
static T_3 F_73 ( struct V_26 * V_27 ,
struct V_62 * V_63 ,
const char * V_64 ,
T_4 V_65 )
{
struct V_67 * V_68 = F_39 ( V_63 ) ;
struct V_6 * V_7 = F_20 ( V_27 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
int V_82 = F_6 ( V_68 -> V_69 ) ;
int V_83 ;
long V_20 ;
T_1 V_3 ;
if ( F_34 ( V_64 , 10 , & V_20 ) )
return - V_66 ;
if ( V_68 -> V_69 % 2 )
V_83 = V_42 ;
else
V_83 = V_43 ;
if ( V_20 != 2 && V_20 != 1 )
return - V_66 ;
V_20 -- ;
F_14 ( & V_7 -> V_23 ) ;
V_7 -> V_44 [ V_68 -> V_69 ] = V_20 ;
V_3 = F_2 ( V_2 , V_82 ) ;
if ( V_20 )
V_3 |= V_83 ;
else
V_3 &= ~ V_83 ;
F_4 ( V_2 , V_82 , V_3 ) ;
F_15 ( & V_7 -> V_23 ) ;
return V_65 ;
}
static T_3 F_74 ( struct V_26 * V_27 ,
struct V_62 * V_63 ,
char * V_64 )
{
struct V_67 * V_68 = F_39 ( V_63 ) ;
struct V_6 * V_7 = F_19 ( V_27 ) ;
T_1 V_84 = V_7 -> V_45 [ V_68 -> V_69 ] ;
if ( V_84 )
return sprintf ( V_64 , L_2 , 1 << ( V_84 - 1 ) ) ;
else
return sprintf ( V_64 , L_2 , V_85 ) ;
}
static int F_75 ( int V_86 )
{
if ( V_86 == V_85 )
return 0 ;
if ( V_86 < 1 || ! F_76 ( V_86 ) )
return - V_66 ;
return F_77 ( V_86 ) + 1 ;
}
static T_3 F_78 ( struct V_26 * V_27 ,
struct V_62 * V_63 ,
const char * V_64 ,
T_4 V_65 )
{
struct V_67 * V_68 = F_39 ( V_63 ) ;
struct V_6 * V_7 = F_20 ( V_27 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
int V_82 = F_23 ( V_68 -> V_69 ) ;
long V_20 ;
T_1 V_3 ;
if ( F_34 ( V_64 , 10 , & V_20 ) )
return - V_66 ;
V_20 = F_75 ( V_20 ) ;
if ( V_20 < 0 )
return V_20 ;
F_14 ( & V_7 -> V_23 ) ;
V_7 -> V_44 [ V_68 -> V_69 ] = V_20 ;
V_3 = F_2 ( V_2 , V_82 ) ;
if ( ! ( V_68 -> V_69 % 2 ) ) {
V_3 &= 0xF ;
V_3 |= ( V_20 << 4 ) & 0xF0 ;
} else {
V_3 &= 0xF0 ;
V_3 |= V_20 & 0xF ;
}
F_4 ( V_2 , V_82 , V_3 ) ;
F_15 ( & V_7 -> V_23 ) ;
return V_65 ;
}
static T_3 F_79 ( struct V_26 * V_27 ,
struct V_62 * V_63 ,
char * V_64 )
{
struct V_67 * V_68 = F_39 ( V_63 ) ;
struct V_6 * V_7 = F_19 ( V_27 ) ;
if ( V_7 -> V_48 & V_68 -> V_69 )
return sprintf ( V_64 , L_5 ) ;
else
return sprintf ( V_64 , L_4 ) ;
}
static int F_80 ( struct V_1 * V_2 ,
struct V_87 * V_88 )
{
struct V_89 * V_90 = V_2 -> V_90 ;
int V_91 , V_26 , V_92 ;
if ( ! F_81 ( V_90 , V_93 ) )
return - V_94 ;
V_91 = F_2 ( V_2 , V_95 ) ;
if ( V_91 != V_96 )
return - V_94 ;
V_26 = F_2 ( V_2 , V_97 ) ;
if ( V_26 != V_98 )
return - V_94 ;
V_92 = F_2 ( V_2 , V_99 ) ;
if ( V_92 != V_100 )
return - V_94 ;
F_82 ( V_88 -> type , L_6 , V_101 ) ;
return 0 ;
}
static void F_83 ( struct V_1 * V_2 )
{
int V_3 = F_2 ( V_2 , V_15 ) ;
if ( V_3 < 0 ) {
F_84 ( & V_2 -> V_27 , L_7 ) ;
} else {
F_4 ( V_2 , V_15 , V_3 | 3 ) ;
}
}
static int F_85 ( struct V_1 * V_2 ,
const struct V_102 * V_103 )
{
struct V_26 * V_27 = & V_2 -> V_27 ;
struct V_6 * V_7 ;
struct V_26 * V_104 ;
V_7 = F_86 ( V_27 , sizeof( struct V_6 ) , V_105 ) ;
if ( ! V_7 )
return - V_106 ;
V_7 -> V_16 = - 1 ;
V_7 -> V_25 = V_107 ;
F_87 ( V_2 , V_7 ) ;
V_7 -> V_2 = V_2 ;
F_88 ( & V_7 -> V_23 ) ;
F_89 ( & V_2 -> V_27 , L_8 , V_2 -> V_108 ) ;
F_83 ( V_2 ) ;
V_104 = F_90 ( V_27 , V_2 -> V_108 ,
V_7 ,
V_109 ) ;
if ( F_91 ( V_104 ) )
return F_92 ( V_104 ) ;
V_7 -> V_110 = F_93 ( F_11 , V_2 , L_9 ,
F_94 ( V_104 ) ) ;
if ( F_91 ( V_7 -> V_110 ) ) {
return F_92 ( V_7 -> V_110 ) ;
}
return 0 ;
}
static int F_95 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_12 ( V_2 ) ;
F_96 ( V_7 -> V_110 ) ;
return 0 ;
}
