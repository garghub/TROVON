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
if ( F_13 () )
break;
F_8 ( V_7 -> V_24 ) ;
}
F_16 ( & V_7 -> V_25 ) ;
return 0 ;
}
static struct V_6 * F_17 ( struct V_26 * V_27 )
{
struct V_6 * V_7 = F_18 ( V_27 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
unsigned long V_28 = V_29 ;
T_1 V_10 ;
int V_9 ;
int V_30 = 1 ;
int V_31 = 1 ;
if ( F_19 ( V_28 , V_7 -> V_32 +
V_33 ) &&
V_7 -> V_34 )
V_30 = 0 ;
if ( F_19 ( V_28 , V_7 -> V_35 +
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
F_20 ( V_9 ) ) ;
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
V_3 = F_21 ( V_9 ) ;
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
V_7 -> V_48 |= F_22 ( F_2 ( V_2 ,
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
F_23 ( V_9 ) ) ;
V_7 -> V_56 [ V_9 ] = F_2 ( V_2 ,
F_24 ( V_9 ) ) ;
}
for ( V_9 = 0 ; V_9 < V_13 ; V_9 ++ ) {
V_7 -> V_57 [ V_9 ] = F_1 ( V_2 ,
F_25 ( V_9 ) ) ;
V_7 -> V_58 [ V_9 ] = F_1 ( V_2 ,
F_26 ( V_9 ) ) ;
}
for ( V_9 = 0 ; V_9 < V_40 ; V_9 ++ ) {
V_7 -> V_59 [ V_9 ] = F_2 ( V_2 ,
F_27 ( V_9 ) ) ;
V_7 -> V_60 [ V_9 ] = F_2 ( V_2 ,
F_28 ( V_9 ) ) ;
V_7 -> V_61 [ V_9 ] = F_2 ( V_2 ,
F_29 ( V_9 ) ) ;
}
V_7 -> V_35 = V_28 ;
V_7 -> V_37 = 1 ;
V_54:
F_15 ( & V_7 -> V_23 ) ;
return V_7 ;
}
static T_3 F_30 ( struct V_26 * V_27 ,
struct V_62 * V_63 ,
char * V_64 )
{
struct V_6 * V_7 = F_17 ( V_27 ) ;
return sprintf ( V_64 , L_2 , V_7 -> V_24 ) ;
}
static T_3 F_31 ( struct V_26 * V_27 ,
struct V_62 * V_63 ,
const char * V_64 ,
T_4 V_65 )
{
struct V_6 * V_7 = F_18 ( V_27 ) ;
long V_20 ;
if ( F_32 ( V_64 , 10 , & V_20 ) )
return - V_66 ;
V_20 = F_33 ( V_20 , 0 , 60000 ) ;
F_14 ( & V_7 -> V_23 ) ;
V_7 -> V_24 = V_20 ;
F_15 ( & V_7 -> V_23 ) ;
return V_65 ;
}
static T_3 F_34 ( struct V_26 * V_27 ,
struct V_62 * V_63 ,
char * V_64 )
{
struct V_6 * V_7 = F_17 ( V_27 ) ;
return sprintf ( V_64 , L_2 , V_7 -> V_16 ) ;
}
static T_3 F_35 ( struct V_26 * V_27 ,
struct V_62 * V_63 ,
const char * V_64 ,
T_4 V_65 )
{
struct V_6 * V_7 = F_18 ( V_27 ) ;
long V_20 ;
if ( F_32 ( V_64 , 10 , & V_20 ) )
return - V_66 ;
V_20 = F_33 ( V_20 , - 1 , 10 ) ;
F_14 ( & V_7 -> V_23 ) ;
V_7 -> V_16 = V_20 ;
if ( V_20 < 0 )
V_7 -> V_21 = 0 ;
F_15 ( & V_7 -> V_23 ) ;
return V_65 ;
}
static T_3 F_36 ( struct V_26 * V_27 ,
struct V_62 * V_63 ,
char * V_64 )
{
struct V_67 * V_68 = F_37 ( V_63 ) ;
struct V_6 * V_7 = F_17 ( V_27 ) ;
return sprintf ( V_64 , L_2 , 1000 * V_7 -> V_55 [ V_68 -> V_69 ] ) ;
}
static T_3 F_38 ( struct V_26 * V_27 ,
struct V_62 * V_63 ,
const char * V_64 ,
T_4 V_65 )
{
struct V_67 * V_68 = F_37 ( V_63 ) ;
struct V_6 * V_7 = F_18 ( V_27 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
long V_20 ;
if ( F_32 ( V_64 , 10 , & V_20 ) )
return - V_66 ;
V_20 = F_39 ( V_20 , 1000 ) ;
V_20 = F_33 ( V_20 , - 128 , 127 ) ;
F_14 ( & V_7 -> V_23 ) ;
V_7 -> V_55 [ V_68 -> V_69 ] = V_20 ;
F_4 ( V_2 , F_23 ( V_68 -> V_69 ) ,
V_20 ) ;
F_15 ( & V_7 -> V_23 ) ;
return V_65 ;
}
static T_3 F_40 ( struct V_26 * V_27 ,
struct V_62 * V_63 ,
char * V_64 )
{
struct V_67 * V_68 = F_37 ( V_63 ) ;
struct V_6 * V_7 = F_17 ( V_27 ) ;
return sprintf ( V_64 , L_2 , 1000 * V_7 -> V_56 [ V_68 -> V_69 ] ) ;
}
static T_3 F_41 ( struct V_26 * V_27 ,
struct V_62 * V_63 ,
const char * V_64 ,
T_4 V_65 )
{
struct V_67 * V_68 = F_37 ( V_63 ) ;
struct V_6 * V_7 = F_18 ( V_27 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
long V_20 ;
if ( F_32 ( V_64 , 10 , & V_20 ) )
return - V_66 ;
V_20 = F_39 ( V_20 , 1000 ) ;
V_20 = F_33 ( V_20 , - 128 , 127 ) ;
F_14 ( & V_7 -> V_23 ) ;
V_7 -> V_56 [ V_68 -> V_69 ] = V_20 ;
F_4 ( V_2 , F_24 ( V_68 -> V_69 ) ,
V_20 ) ;
F_15 ( & V_7 -> V_23 ) ;
return V_65 ;
}
static T_3 F_42 ( struct V_26 * V_27 , struct V_62 * V_63 ,
char * V_64 )
{
struct V_67 * V_68 = F_37 ( V_63 ) ;
struct V_6 * V_7 = F_17 ( V_27 ) ;
return sprintf ( V_64 , L_2 , 1000 * V_7 -> V_20 [ V_68 -> V_69 ] ) ;
}
static T_3 F_43 ( struct V_26 * V_27 ,
struct V_62 * V_63 ,
char * V_64 )
{
struct V_6 * V_7 = F_17 ( V_27 ) ;
return sprintf ( V_64 , L_3 , V_7 -> V_52 ) ;
}
static T_3 F_44 ( struct V_26 * V_27 ,
struct V_62 * V_63 ,
char * V_64 )
{
struct V_67 * V_68 = F_37 ( V_63 ) ;
struct V_6 * V_7 = F_17 ( V_27 ) ;
if ( F_45 ( V_7 -> V_58 [ V_68 -> V_69 ] ) )
return sprintf ( V_64 , L_2 ,
F_46 ( V_7 -> V_58 [ V_68 -> V_69 ] ) ) ;
else
return sprintf ( V_64 , L_4 ) ;
}
static T_3 F_47 ( struct V_26 * V_27 ,
struct V_62 * V_63 ,
const char * V_64 , T_4 V_65 )
{
struct V_67 * V_68 = F_37 ( V_63 ) ;
struct V_6 * V_7 = F_18 ( V_27 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
long V_20 ;
if ( F_32 ( V_64 , 10 , & V_20 ) || ! V_20 )
return - V_66 ;
V_20 = F_48 ( V_20 ) ;
V_20 = F_33 ( V_20 , 1 , 65534 ) ;
F_14 ( & V_7 -> V_23 ) ;
V_7 -> V_58 [ V_68 -> V_69 ] = V_20 ;
F_3 ( V_2 , F_26 ( V_68 -> V_69 ) , V_20 ) ;
F_15 ( & V_7 -> V_23 ) ;
return V_65 ;
}
static T_3 F_49 ( struct V_26 * V_27 ,
struct V_62 * V_63 ,
char * V_64 )
{
struct V_67 * V_68 = F_37 ( V_63 ) ;
struct V_6 * V_7 = F_17 ( V_27 ) ;
if ( F_45 ( V_7 -> V_57 [ V_68 -> V_69 ] ) )
return sprintf ( V_64 , L_2 ,
F_46 ( V_7 -> V_57 [ V_68 -> V_69 ] ) ) ;
else
return sprintf ( V_64 , L_4 ) ;
}
static T_3 F_50 ( struct V_26 * V_27 ,
struct V_62 * V_63 ,
const char * V_64 , T_4 V_65 )
{
struct V_67 * V_68 = F_37 ( V_63 ) ;
struct V_6 * V_7 = F_18 ( V_27 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
long V_20 ;
if ( F_32 ( V_64 , 10 , & V_20 ) || ! V_20 )
return - V_66 ;
V_20 = F_48 ( V_20 ) ;
V_20 = F_33 ( V_20 , 1 , 65534 ) ;
F_14 ( & V_7 -> V_23 ) ;
V_7 -> V_57 [ V_68 -> V_69 ] = V_20 ;
F_3 ( V_2 , F_25 ( V_68 -> V_69 ) , V_20 ) ;
F_15 ( & V_7 -> V_23 ) ;
return V_65 ;
}
static T_3 F_51 ( struct V_26 * V_27 , struct V_62 * V_63 ,
char * V_64 )
{
struct V_67 * V_68 = F_37 ( V_63 ) ;
struct V_6 * V_7 = F_17 ( V_27 ) ;
if ( F_45 ( V_7 -> V_39 [ V_68 -> V_69 ] ) )
return sprintf ( V_64 , L_2 ,
F_46 ( V_7 -> V_39 [ V_68 -> V_69 ] ) ) ;
else
return sprintf ( V_64 , L_4 ) ;
}
static T_3 F_52 ( struct V_26 * V_27 ,
struct V_62 * V_63 ,
char * V_64 )
{
struct V_6 * V_7 = F_17 ( V_27 ) ;
return sprintf ( V_64 , L_2 , V_7 -> V_47 ) ;
}
static T_3 F_53 ( struct V_26 * V_27 ,
struct V_62 * V_63 ,
const char * V_64 ,
T_4 V_65 )
{
struct V_6 * V_7 = F_18 ( V_27 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
long V_20 ;
T_1 V_3 ;
if ( F_32 ( V_64 , 10 , & V_20 ) )
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
static T_3 F_54 ( struct V_26 * V_27 , struct V_62 * V_63 ,
char * V_64 )
{
struct V_67 * V_68 = F_37 ( V_63 ) ;
struct V_6 * V_7 = F_17 ( V_27 ) ;
return sprintf ( V_64 , L_2 , V_7 -> V_11 [ V_68 -> V_69 ] ) ;
}
static T_3 F_55 ( struct V_26 * V_27 , struct V_62 * V_63 ,
const char * V_64 , T_4 V_65 )
{
struct V_67 * V_68 = F_37 ( V_63 ) ;
struct V_6 * V_7 = F_18 ( V_27 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
long V_20 ;
if ( F_32 ( V_64 , 10 , & V_20 ) )
return - V_66 ;
V_20 = F_33 ( V_20 , 0 , 255 ) ;
F_14 ( & V_7 -> V_23 ) ;
V_7 -> V_11 [ V_68 -> V_69 ] = V_20 ;
F_4 ( V_2 , F_7 ( V_68 -> V_69 ) , V_20 ) ;
F_15 ( & V_7 -> V_23 ) ;
return V_65 ;
}
static T_3 F_56 ( struct V_26 * V_27 ,
struct V_62 * V_63 ,
char * V_64 )
{
struct V_67 * V_68 = F_37 ( V_63 ) ;
struct V_6 * V_7 = F_17 ( V_27 ) ;
return sprintf ( V_64 , L_2 , V_7 -> V_59 [ V_68 -> V_69 ] ) ;
}
static T_3 F_57 ( struct V_26 * V_27 ,
struct V_62 * V_63 ,
const char * V_64 ,
T_4 V_65 )
{
struct V_67 * V_68 = F_37 ( V_63 ) ;
struct V_6 * V_7 = F_18 ( V_27 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
long V_20 ;
if ( F_32 ( V_64 , 10 , & V_20 ) )
return - V_66 ;
V_20 = F_33 ( V_20 , 0 , 255 ) ;
F_14 ( & V_7 -> V_23 ) ;
V_7 -> V_59 [ V_68 -> V_69 ] = V_20 ;
F_4 ( V_2 , F_27 ( V_68 -> V_69 ) ,
V_20 ) ;
F_15 ( & V_7 -> V_23 ) ;
return V_65 ;
}
static T_3 F_58 ( struct V_26 * V_27 ,
struct V_62 * V_63 ,
char * V_64 )
{
struct V_67 * V_68 = F_37 ( V_63 ) ;
struct V_6 * V_7 = F_17 ( V_27 ) ;
return sprintf ( V_64 , L_2 , V_7 -> V_60 [ V_68 -> V_69 ] ) ;
}
static T_3 F_59 ( struct V_26 * V_27 ,
struct V_62 * V_63 ,
const char * V_64 ,
T_4 V_65 )
{
struct V_67 * V_68 = F_37 ( V_63 ) ;
struct V_6 * V_7 = F_18 ( V_27 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
long V_20 ;
if ( F_32 ( V_64 , 10 , & V_20 ) )
return - V_66 ;
V_20 = F_33 ( V_20 , 0 , 255 ) ;
F_14 ( & V_7 -> V_23 ) ;
V_7 -> V_60 [ V_68 -> V_69 ] = V_20 ;
F_4 ( V_2 , F_28 ( V_68 -> V_69 ) ,
V_20 ) ;
F_15 ( & V_7 -> V_23 ) ;
return V_65 ;
}
static T_3 F_60 ( struct V_26 * V_27 ,
struct V_62 * V_63 ,
char * V_64 )
{
struct V_67 * V_68 = F_37 ( V_63 ) ;
struct V_6 * V_7 = F_17 ( V_27 ) ;
return sprintf ( V_64 , L_2 , 1000 * ( 20 + V_7 -> V_61 [ V_68 -> V_69 ] ) ) ;
}
static T_3 F_61 ( struct V_26 * V_27 ,
struct V_62 * V_63 ,
char * V_64 )
{
struct V_67 * V_68 = F_37 ( V_63 ) ;
struct V_6 * V_7 = F_17 ( V_27 ) ;
return sprintf ( V_64 , L_2 , 1000 * V_7 -> V_61 [ V_68 -> V_69 ] ) ;
}
static T_3 F_62 ( struct V_26 * V_27 ,
struct V_62 * V_63 ,
const char * V_64 ,
T_4 V_65 )
{
struct V_67 * V_68 = F_37 ( V_63 ) ;
struct V_6 * V_7 = F_18 ( V_27 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
long V_20 ;
if ( F_32 ( V_64 , 10 , & V_20 ) )
return - V_66 ;
V_20 = F_39 ( V_20 , 1000 ) ;
V_20 = F_33 ( V_20 , - 128 , 127 ) ;
F_14 ( & V_7 -> V_23 ) ;
V_7 -> V_61 [ V_68 -> V_69 ] = V_20 ;
F_4 ( V_2 , F_29 ( V_68 -> V_69 ) ,
V_20 ) ;
F_15 ( & V_7 -> V_23 ) ;
return V_65 ;
}
static T_3 F_63 ( struct V_26 * V_27 ,
struct V_62 * V_63 ,
char * V_64 )
{
struct V_67 * V_68 = F_37 ( V_63 ) ;
struct V_6 * V_7 = F_17 ( V_27 ) ;
return sprintf ( V_64 , L_2 , 1 + V_7 -> V_44 [ V_68 -> V_69 ] ) ;
}
static T_3 F_64 ( struct V_26 * V_27 ,
struct V_62 * V_63 ,
const char * V_64 ,
T_4 V_65 )
{
struct V_67 * V_68 = F_37 ( V_63 ) ;
struct V_6 * V_7 = F_18 ( V_27 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
int V_70 = F_6 ( V_68 -> V_69 ) ;
int V_71 ;
long V_20 ;
T_1 V_3 ;
if ( F_32 ( V_64 , 10 , & V_20 ) )
return - V_66 ;
if ( V_68 -> V_69 % 2 )
V_71 = V_42 ;
else
V_71 = V_43 ;
if ( V_20 != 2 && V_20 != 1 )
return - V_66 ;
V_20 -- ;
F_14 ( & V_7 -> V_23 ) ;
V_7 -> V_44 [ V_68 -> V_69 ] = V_20 ;
V_3 = F_2 ( V_2 , V_70 ) ;
if ( V_20 )
V_3 |= V_71 ;
else
V_3 &= ~ V_71 ;
F_4 ( V_2 , V_70 , V_3 ) ;
F_15 ( & V_7 -> V_23 ) ;
return V_65 ;
}
static T_3 F_65 ( struct V_26 * V_27 ,
struct V_62 * V_63 ,
char * V_64 )
{
struct V_67 * V_68 = F_37 ( V_63 ) ;
struct V_6 * V_7 = F_17 ( V_27 ) ;
T_1 V_72 = V_7 -> V_45 [ V_68 -> V_69 ] ;
if ( V_72 )
return sprintf ( V_64 , L_2 , 1 << ( V_72 - 1 ) ) ;
else
return sprintf ( V_64 , L_2 , V_73 ) ;
}
static int F_66 ( int V_74 )
{
if ( V_74 == V_73 )
return 0 ;
if ( V_74 < 1 || ! F_67 ( V_74 ) )
return - V_66 ;
return F_68 ( V_74 ) + 1 ;
}
static T_3 F_69 ( struct V_26 * V_27 ,
struct V_62 * V_63 ,
const char * V_64 ,
T_4 V_65 )
{
struct V_67 * V_68 = F_37 ( V_63 ) ;
struct V_6 * V_7 = F_18 ( V_27 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
int V_70 = F_21 ( V_68 -> V_69 ) ;
long V_20 ;
T_1 V_3 ;
if ( F_32 ( V_64 , 10 , & V_20 ) )
return - V_66 ;
V_20 = F_66 ( V_20 ) ;
if ( V_20 < 0 )
return V_20 ;
F_14 ( & V_7 -> V_23 ) ;
V_7 -> V_44 [ V_68 -> V_69 ] = V_20 ;
V_3 = F_2 ( V_2 , V_70 ) ;
if ( ! ( V_68 -> V_69 % 2 ) ) {
V_3 &= 0xF ;
V_3 |= ( V_20 << 4 ) & 0xF0 ;
} else {
V_3 &= 0xF0 ;
V_3 |= V_20 & 0xF ;
}
F_4 ( V_2 , V_70 , V_3 ) ;
F_15 ( & V_7 -> V_23 ) ;
return V_65 ;
}
static T_3 F_70 ( struct V_26 * V_27 ,
struct V_62 * V_63 ,
char * V_64 )
{
struct V_67 * V_68 = F_37 ( V_63 ) ;
struct V_6 * V_7 = F_17 ( V_27 ) ;
if ( V_7 -> V_48 & V_68 -> V_69 )
return sprintf ( V_64 , L_5 ) ;
else
return sprintf ( V_64 , L_4 ) ;
}
static int F_71 ( struct V_1 * V_2 ,
struct V_75 * V_76 )
{
struct V_77 * V_78 = V_2 -> V_78 ;
int V_79 , V_26 , V_80 ;
if ( ! F_72 ( V_78 , V_81 ) )
return - V_82 ;
V_79 = F_2 ( V_2 , V_83 ) ;
if ( V_79 != V_84 )
return - V_82 ;
V_26 = F_2 ( V_2 , V_85 ) ;
if ( V_26 != V_86 )
return - V_82 ;
V_80 = F_2 ( V_2 , V_87 ) ;
if ( V_80 != V_88 )
return - V_82 ;
F_73 ( V_76 -> type , L_6 , V_89 ) ;
return 0 ;
}
static void F_74 ( struct V_1 * V_2 )
{
int V_3 = F_2 ( V_2 , V_15 ) ;
if ( V_3 < 0 ) {
F_75 ( & V_2 -> V_27 , L_7 ) ;
} else {
F_4 ( V_2 , V_15 , V_3 | 3 ) ;
}
}
static int F_76 ( struct V_1 * V_2 ,
const struct V_90 * V_91 )
{
struct V_26 * V_27 = & V_2 -> V_27 ;
struct V_6 * V_7 ;
struct V_26 * V_92 ;
V_7 = F_77 ( V_27 , sizeof( struct V_6 ) , V_93 ) ;
if ( ! V_7 )
return - V_94 ;
V_7 -> V_16 = - 1 ;
V_7 -> V_24 = V_95 ;
F_78 ( V_2 , V_7 ) ;
V_7 -> V_2 = V_2 ;
F_79 ( & V_7 -> V_23 ) ;
F_80 ( & V_2 -> V_27 , L_8 , V_2 -> V_96 ) ;
F_74 ( V_2 ) ;
V_92 = F_81 ( V_27 , V_2 -> V_96 ,
V_7 ,
V_97 ) ;
if ( F_82 ( V_92 ) )
return F_83 ( V_92 ) ;
F_84 ( & V_7 -> V_25 ) ;
V_7 -> V_98 = F_85 ( F_11 , V_2 , L_9 ,
F_86 ( V_92 ) ) ;
if ( F_82 ( V_7 -> V_98 ) ) {
return F_83 ( V_7 -> V_98 ) ;
}
return 0 ;
}
static int F_87 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_12 ( V_2 ) ;
F_88 ( V_7 -> V_98 ) ;
F_89 ( & V_7 -> V_25 ) ;
return 0 ;
}
