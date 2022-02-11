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
&& F_4 ( V_2 , V_3 + 1 , V_5 >> 8 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
int V_3 = F_2 ( V_2 , V_6 ) ;
if ( V_3 < 0 ) {
F_6 ( & V_2 -> V_7 , L_1 ) ;
} else {
F_4 ( V_2 , V_6 , V_3 | 3 ) ;
}
}
static int F_7 ( struct V_1 * V_2 ,
struct V_8 * V_9 )
{
unsigned long V_10 ;
int V_11 ;
T_1 V_12 , V_13 [ 4 ] , V_14 [ 2 ] ;
V_14 [ 0 ] = F_2 ( V_2 , F_8 ( 0 ) ) ;
V_14 [ 1 ] = F_2 ( V_2 , F_8 ( 2 ) ) ;
for ( V_11 = 0 ; V_11 < V_15 ; V_11 ++ )
V_13 [ V_11 ] = F_2 ( V_2 , F_9 ( V_11 ) ) ;
F_4 ( V_2 , F_8 ( 0 ) ,
V_14 [ 0 ] & ~ ( V_16 ) ) ;
F_4 ( V_2 , F_8 ( 2 ) ,
V_14 [ 1 ] & ~ ( V_16 ) ) ;
for ( V_11 = 0 ; V_11 < V_15 ; V_11 ++ )
F_4 ( V_2 , F_9 ( V_11 ) , V_13 [ V_11 ] ) ;
V_12 = F_2 ( V_2 , V_6 ) ;
V_12 |= 0x80 ;
F_4 ( V_2 , V_6 , V_12 ) ;
V_10 = F_10 ( ( V_9 -> V_17 >= 0 ?
V_9 -> V_17 * 200 :
V_18 ) ) ;
V_12 = F_2 ( V_2 , V_6 ) ;
V_12 &= ~ 0x80 ;
F_4 ( V_2 , V_6 , V_12 ) ;
F_4 ( V_2 , F_8 ( 0 ) , V_14 [ 0 ] ) ;
F_4 ( V_2 , F_8 ( 2 ) , V_14 [ 1 ] ) ;
if ( V_10 ) {
F_11 ( L_2 ) ;
return - V_19 ;
}
if ( V_9 -> V_17 >= 0 )
return 0 ;
for ( V_11 = 0 ; V_11 < V_20 ; V_11 ++ ) {
V_9 -> V_21 [ V_11 ] = F_2 ( V_2 ,
F_12 ( V_11 ) ) ;
if ( V_9 -> V_21 [ V_11 ] )
V_9 -> V_17 = V_11 + 1 ;
}
V_9 -> V_22 = 1 ;
return 0 ;
}
static int F_13 ( void * V_23 )
{
struct V_1 * V_2 = V_23 ;
struct V_8 * V_9 = F_14 ( V_2 ) ;
while ( ! F_15 () ) {
F_16 ( & V_9 -> V_24 ) ;
F_7 ( V_2 , V_9 ) ;
F_17 ( & V_9 -> V_24 ) ;
if ( F_15 () )
break;
F_10 ( V_9 -> V_25 ) ;
}
F_18 ( & V_9 -> V_26 ) ;
return 0 ;
}
static struct V_8 * F_19 ( struct V_27 * V_7 )
{
struct V_1 * V_2 = F_20 ( V_7 ) ;
struct V_8 * V_9 = F_14 ( V_2 ) ;
unsigned long V_28 = V_29 ;
T_1 V_12 ;
int V_11 ;
int V_30 = 1 ;
int V_31 = 1 ;
if ( F_21 ( V_28 , V_9 -> V_32 +
V_33 ) &&
V_9 -> V_34 )
V_30 = 0 ;
if ( F_21 ( V_28 , V_9 -> V_35 +
V_36 ) &&
V_9 -> V_37 )
V_31 = 0 ;
if ( ! V_30 && ! V_31 )
return V_9 ;
F_16 ( & V_9 -> V_24 ) ;
if ( ! V_30 )
goto V_38;
if ( ! V_9 -> V_22 )
F_7 ( V_2 , V_9 ) ;
else
for ( V_11 = 0 ; V_11 < V_20 ; V_11 ++ )
V_9 -> V_21 [ V_11 ] = F_2 ( V_2 ,
F_12 ( V_11 ) ) ;
for ( V_11 = 0 ; V_11 < V_15 ; V_11 ++ )
V_9 -> V_39 [ V_11 ] = F_1 ( V_2 ,
F_22 ( V_11 ) ) ;
for ( V_11 = 0 ; V_11 < V_40 ; V_11 ++ ) {
int V_3 ;
int V_41 ;
V_9 -> V_13 [ V_11 ] = F_2 ( V_2 ,
F_9 ( V_11 ) ) ;
if ( V_11 % 2 )
V_41 = V_42 ;
else
V_41 = V_43 ;
V_3 = F_8 ( V_11 ) ;
if ( F_2 ( V_2 , V_3 ) & V_41 )
V_9 -> V_44 [ V_11 ] = 1 ;
else
V_9 -> V_44 [ V_11 ] = 0 ;
V_3 = F_23 ( V_11 ) ;
V_12 = F_2 ( V_2 , V_3 ) ;
if ( ! ( V_11 % 2 ) )
V_9 -> V_45 [ V_11 ] = V_12 >> 4 ;
else
V_9 -> V_45 [ V_11 ] = V_12 & 0xF ;
}
if ( F_2 ( V_2 , V_6 ) &
V_46 )
V_9 -> V_47 = 1 ;
else
V_9 -> V_47 = 0 ;
V_9 -> V_48 = F_2 ( V_2 , V_49 ) ;
if ( V_9 -> V_48 & V_50 )
V_9 -> V_48 |= F_24 ( F_2 ( V_2 ,
V_51 ) ) ;
V_9 -> V_52 = F_1 ( V_2 ,
V_53 ) ;
V_9 -> V_32 = V_28 ;
V_9 -> V_34 = 1 ;
V_38:
if ( ! V_31 )
goto V_54;
for ( V_11 = 0 ; V_11 < V_20 ; V_11 ++ ) {
V_9 -> V_55 [ V_11 ] = F_2 ( V_2 ,
F_25 ( V_11 ) ) ;
V_9 -> V_56 [ V_11 ] = F_2 ( V_2 ,
F_26 ( V_11 ) ) ;
}
for ( V_11 = 0 ; V_11 < V_15 ; V_11 ++ ) {
V_9 -> V_57 [ V_11 ] = F_1 ( V_2 ,
F_27 ( V_11 ) ) ;
V_9 -> V_58 [ V_11 ] = F_1 ( V_2 ,
F_28 ( V_11 ) ) ;
}
for ( V_11 = 0 ; V_11 < V_40 ; V_11 ++ ) {
V_9 -> V_59 [ V_11 ] = F_2 ( V_2 ,
F_29 ( V_11 ) ) ;
V_9 -> V_60 [ V_11 ] = F_2 ( V_2 ,
F_30 ( V_11 ) ) ;
V_9 -> V_61 [ V_11 ] = F_2 ( V_2 ,
F_31 ( V_11 ) ) ;
}
V_9 -> V_35 = V_28 ;
V_9 -> V_37 = 1 ;
V_54:
F_17 ( & V_9 -> V_24 ) ;
return V_9 ;
}
static T_3 F_32 ( struct V_27 * V_7 ,
struct V_62 * V_63 ,
char * V_64 )
{
struct V_8 * V_9 = F_19 ( V_7 ) ;
return sprintf ( V_64 , L_3 , V_9 -> V_25 ) ;
}
static T_3 F_33 ( struct V_27 * V_7 ,
struct V_62 * V_63 ,
const char * V_64 ,
T_4 V_65 )
{
struct V_1 * V_2 = F_20 ( V_7 ) ;
struct V_8 * V_9 = F_14 ( V_2 ) ;
long V_21 ;
if ( F_34 ( V_64 , 10 , & V_21 ) )
return - V_66 ;
V_21 = F_35 ( V_21 , 0 , 60000 ) ;
F_16 ( & V_9 -> V_24 ) ;
V_9 -> V_25 = V_21 ;
F_17 ( & V_9 -> V_24 ) ;
return V_65 ;
}
static T_3 F_36 ( struct V_27 * V_7 ,
struct V_62 * V_63 ,
char * V_64 )
{
struct V_8 * V_9 = F_19 ( V_7 ) ;
return sprintf ( V_64 , L_3 , V_9 -> V_17 ) ;
}
static T_3 F_37 ( struct V_27 * V_7 ,
struct V_62 * V_63 ,
const char * V_64 ,
T_4 V_65 )
{
struct V_1 * V_2 = F_20 ( V_7 ) ;
struct V_8 * V_9 = F_14 ( V_2 ) ;
long V_21 ;
if ( F_34 ( V_64 , 10 , & V_21 ) )
return - V_66 ;
V_21 = F_35 ( V_21 , - 1 , 10 ) ;
F_16 ( & V_9 -> V_24 ) ;
V_9 -> V_17 = V_21 ;
if ( V_21 < 0 )
V_9 -> V_22 = 0 ;
F_17 ( & V_9 -> V_24 ) ;
return V_65 ;
}
static T_3 F_38 ( struct V_27 * V_7 ,
struct V_62 * V_63 ,
char * V_64 )
{
struct V_67 * V_68 = F_39 ( V_63 ) ;
struct V_8 * V_9 = F_19 ( V_7 ) ;
return sprintf ( V_64 , L_3 , 1000 * V_9 -> V_55 [ V_68 -> V_69 ] ) ;
}
static T_3 F_40 ( struct V_27 * V_7 ,
struct V_62 * V_63 ,
const char * V_64 ,
T_4 V_65 )
{
struct V_67 * V_68 = F_39 ( V_63 ) ;
struct V_1 * V_2 = F_20 ( V_7 ) ;
struct V_8 * V_9 = F_14 ( V_2 ) ;
long V_21 ;
if ( F_34 ( V_64 , 10 , & V_21 ) )
return - V_66 ;
V_21 = F_41 ( V_21 , 1000 ) ;
V_21 = F_35 ( V_21 , 0 , 255 ) ;
F_16 ( & V_9 -> V_24 ) ;
V_9 -> V_55 [ V_68 -> V_69 ] = V_21 ;
F_4 ( V_2 , F_25 ( V_68 -> V_69 ) ,
V_21 ) ;
F_17 ( & V_9 -> V_24 ) ;
return V_65 ;
}
static T_3 F_42 ( struct V_27 * V_7 ,
struct V_62 * V_63 ,
char * V_64 )
{
struct V_67 * V_68 = F_39 ( V_63 ) ;
struct V_8 * V_9 = F_19 ( V_7 ) ;
return sprintf ( V_64 , L_3 , 1000 * V_9 -> V_56 [ V_68 -> V_69 ] ) ;
}
static T_3 F_43 ( struct V_27 * V_7 ,
struct V_62 * V_63 ,
const char * V_64 ,
T_4 V_65 )
{
struct V_67 * V_68 = F_39 ( V_63 ) ;
struct V_1 * V_2 = F_20 ( V_7 ) ;
struct V_8 * V_9 = F_14 ( V_2 ) ;
long V_21 ;
if ( F_34 ( V_64 , 10 , & V_21 ) )
return - V_66 ;
V_21 = F_41 ( V_21 , 1000 ) ;
V_21 = F_35 ( V_21 , 0 , 255 ) ;
F_16 ( & V_9 -> V_24 ) ;
V_9 -> V_56 [ V_68 -> V_69 ] = V_21 ;
F_4 ( V_2 , F_26 ( V_68 -> V_69 ) ,
V_21 ) ;
F_17 ( & V_9 -> V_24 ) ;
return V_65 ;
}
static T_3 F_44 ( struct V_27 * V_7 , struct V_62 * V_63 ,
char * V_64 )
{
struct V_67 * V_68 = F_39 ( V_63 ) ;
struct V_8 * V_9 = F_19 ( V_7 ) ;
return sprintf ( V_64 , L_3 , 1000 * V_9 -> V_21 [ V_68 -> V_69 ] ) ;
}
static T_3 F_45 ( struct V_27 * V_7 ,
struct V_62 * V_63 ,
char * V_64 )
{
struct V_8 * V_9 = F_19 ( V_7 ) ;
return sprintf ( V_64 , L_4 , V_9 -> V_52 ) ;
}
static T_3 F_46 ( struct V_27 * V_7 ,
struct V_62 * V_63 ,
char * V_64 )
{
struct V_67 * V_68 = F_39 ( V_63 ) ;
struct V_8 * V_9 = F_19 ( V_7 ) ;
if ( F_47 ( V_9 -> V_58 [ V_68 -> V_69 ] ) )
return sprintf ( V_64 , L_3 ,
F_48 ( V_9 -> V_58 [ V_68 -> V_69 ] ) ) ;
else
return sprintf ( V_64 , L_5 ) ;
}
static T_3 F_49 ( struct V_27 * V_7 ,
struct V_62 * V_63 ,
const char * V_64 , T_4 V_65 )
{
struct V_67 * V_68 = F_39 ( V_63 ) ;
struct V_1 * V_2 = F_20 ( V_7 ) ;
struct V_8 * V_9 = F_14 ( V_2 ) ;
long V_21 ;
if ( F_34 ( V_64 , 10 , & V_21 ) || ! V_21 )
return - V_66 ;
V_21 = F_50 ( V_21 ) ;
V_21 = F_35 ( V_21 , 1 , 65534 ) ;
F_16 ( & V_9 -> V_24 ) ;
V_9 -> V_58 [ V_68 -> V_69 ] = V_21 ;
F_3 ( V_2 , F_28 ( V_68 -> V_69 ) , V_21 ) ;
F_17 ( & V_9 -> V_24 ) ;
return V_65 ;
}
static T_3 F_51 ( struct V_27 * V_7 ,
struct V_62 * V_63 ,
char * V_64 )
{
struct V_67 * V_68 = F_39 ( V_63 ) ;
struct V_8 * V_9 = F_19 ( V_7 ) ;
if ( F_47 ( V_9 -> V_57 [ V_68 -> V_69 ] ) )
return sprintf ( V_64 , L_3 ,
F_48 ( V_9 -> V_57 [ V_68 -> V_69 ] ) ) ;
else
return sprintf ( V_64 , L_5 ) ;
}
static T_3 F_52 ( struct V_27 * V_7 ,
struct V_62 * V_63 ,
const char * V_64 , T_4 V_65 )
{
struct V_67 * V_68 = F_39 ( V_63 ) ;
struct V_1 * V_2 = F_20 ( V_7 ) ;
struct V_8 * V_9 = F_14 ( V_2 ) ;
long V_21 ;
if ( F_34 ( V_64 , 10 , & V_21 ) || ! V_21 )
return - V_66 ;
V_21 = F_50 ( V_21 ) ;
V_21 = F_35 ( V_21 , 1 , 65534 ) ;
F_16 ( & V_9 -> V_24 ) ;
V_9 -> V_57 [ V_68 -> V_69 ] = V_21 ;
F_3 ( V_2 , F_27 ( V_68 -> V_69 ) , V_21 ) ;
F_17 ( & V_9 -> V_24 ) ;
return V_65 ;
}
static T_3 F_53 ( struct V_27 * V_7 , struct V_62 * V_63 ,
char * V_64 )
{
struct V_67 * V_68 = F_39 ( V_63 ) ;
struct V_8 * V_9 = F_19 ( V_7 ) ;
if ( F_47 ( V_9 -> V_39 [ V_68 -> V_69 ] ) )
return sprintf ( V_64 , L_3 ,
F_48 ( V_9 -> V_39 [ V_68 -> V_69 ] ) ) ;
else
return sprintf ( V_64 , L_5 ) ;
}
static T_3 F_54 ( struct V_27 * V_7 ,
struct V_62 * V_63 ,
char * V_64 )
{
struct V_8 * V_9 = F_19 ( V_7 ) ;
return sprintf ( V_64 , L_3 , V_9 -> V_47 ) ;
}
static T_3 F_55 ( struct V_27 * V_7 ,
struct V_62 * V_63 ,
const char * V_64 ,
T_4 V_65 )
{
struct V_1 * V_2 = F_20 ( V_7 ) ;
struct V_8 * V_9 = F_14 ( V_2 ) ;
long V_21 ;
T_1 V_3 ;
if ( F_34 ( V_64 , 10 , & V_21 ) )
return - V_66 ;
F_16 ( & V_9 -> V_24 ) ;
V_9 -> V_47 = V_21 ;
V_3 = F_2 ( V_2 , V_6 ) ;
if ( V_21 )
V_3 |= V_46 ;
else
V_3 &= ~ V_46 ;
F_4 ( V_2 , V_6 , V_3 ) ;
F_17 ( & V_9 -> V_24 ) ;
return V_65 ;
}
static T_3 F_56 ( struct V_27 * V_7 , struct V_62 * V_63 ,
char * V_64 )
{
struct V_67 * V_68 = F_39 ( V_63 ) ;
struct V_8 * V_9 = F_19 ( V_7 ) ;
return sprintf ( V_64 , L_3 , V_9 -> V_13 [ V_68 -> V_69 ] ) ;
}
static T_3 F_57 ( struct V_27 * V_7 , struct V_62 * V_63 ,
const char * V_64 , T_4 V_65 )
{
struct V_67 * V_68 = F_39 ( V_63 ) ;
struct V_1 * V_2 = F_20 ( V_7 ) ;
struct V_8 * V_9 = F_14 ( V_2 ) ;
long V_21 ;
if ( F_34 ( V_64 , 10 , & V_21 ) )
return - V_66 ;
V_21 = F_35 ( V_21 , 0 , 255 ) ;
F_16 ( & V_9 -> V_24 ) ;
V_9 -> V_13 [ V_68 -> V_69 ] = V_21 ;
F_4 ( V_2 , F_9 ( V_68 -> V_69 ) , V_21 ) ;
F_17 ( & V_9 -> V_24 ) ;
return V_65 ;
}
static T_3 F_58 ( struct V_27 * V_7 ,
struct V_62 * V_63 ,
char * V_64 )
{
struct V_67 * V_68 = F_39 ( V_63 ) ;
struct V_8 * V_9 = F_19 ( V_7 ) ;
return sprintf ( V_64 , L_3 , V_9 -> V_59 [ V_68 -> V_69 ] ) ;
}
static T_3 F_59 ( struct V_27 * V_7 ,
struct V_62 * V_63 ,
const char * V_64 ,
T_4 V_65 )
{
struct V_67 * V_68 = F_39 ( V_63 ) ;
struct V_1 * V_2 = F_20 ( V_7 ) ;
struct V_8 * V_9 = F_14 ( V_2 ) ;
long V_21 ;
if ( F_34 ( V_64 , 10 , & V_21 ) )
return - V_66 ;
V_21 = F_35 ( V_21 , 0 , 255 ) ;
F_16 ( & V_9 -> V_24 ) ;
V_9 -> V_59 [ V_68 -> V_69 ] = V_21 ;
F_4 ( V_2 , F_29 ( V_68 -> V_69 ) ,
V_21 ) ;
F_17 ( & V_9 -> V_24 ) ;
return V_65 ;
}
static T_3 F_60 ( struct V_27 * V_7 ,
struct V_62 * V_63 ,
char * V_64 )
{
struct V_67 * V_68 = F_39 ( V_63 ) ;
struct V_8 * V_9 = F_19 ( V_7 ) ;
return sprintf ( V_64 , L_3 , V_9 -> V_60 [ V_68 -> V_69 ] ) ;
}
static T_3 F_61 ( struct V_27 * V_7 ,
struct V_62 * V_63 ,
const char * V_64 ,
T_4 V_65 )
{
struct V_67 * V_68 = F_39 ( V_63 ) ;
struct V_1 * V_2 = F_20 ( V_7 ) ;
struct V_8 * V_9 = F_14 ( V_2 ) ;
long V_21 ;
if ( F_34 ( V_64 , 10 , & V_21 ) )
return - V_66 ;
V_21 = F_35 ( V_21 , 0 , 255 ) ;
F_16 ( & V_9 -> V_24 ) ;
V_9 -> V_60 [ V_68 -> V_69 ] = V_21 ;
F_4 ( V_2 , F_30 ( V_68 -> V_69 ) ,
V_21 ) ;
F_17 ( & V_9 -> V_24 ) ;
return V_65 ;
}
static T_3 F_62 ( struct V_27 * V_7 ,
struct V_62 * V_63 ,
char * V_64 )
{
struct V_67 * V_68 = F_39 ( V_63 ) ;
struct V_8 * V_9 = F_19 ( V_7 ) ;
return sprintf ( V_64 , L_3 , 1000 * ( 20 + V_9 -> V_61 [ V_68 -> V_69 ] ) ) ;
}
static T_3 F_63 ( struct V_27 * V_7 ,
struct V_62 * V_63 ,
char * V_64 )
{
struct V_67 * V_68 = F_39 ( V_63 ) ;
struct V_8 * V_9 = F_19 ( V_7 ) ;
return sprintf ( V_64 , L_3 , 1000 * V_9 -> V_61 [ V_68 -> V_69 ] ) ;
}
static T_3 F_64 ( struct V_27 * V_7 ,
struct V_62 * V_63 ,
const char * V_64 ,
T_4 V_65 )
{
struct V_67 * V_68 = F_39 ( V_63 ) ;
struct V_1 * V_2 = F_20 ( V_7 ) ;
struct V_8 * V_9 = F_14 ( V_2 ) ;
long V_21 ;
if ( F_34 ( V_64 , 10 , & V_21 ) )
return - V_66 ;
V_21 = F_41 ( V_21 , 1000 ) ;
V_21 = F_35 ( V_21 , 0 , 255 ) ;
F_16 ( & V_9 -> V_24 ) ;
V_9 -> V_61 [ V_68 -> V_69 ] = V_21 ;
F_4 ( V_2 , F_31 ( V_68 -> V_69 ) ,
V_21 ) ;
F_17 ( & V_9 -> V_24 ) ;
return V_65 ;
}
static T_3 F_65 ( struct V_27 * V_7 ,
struct V_62 * V_63 ,
char * V_64 )
{
struct V_67 * V_68 = F_39 ( V_63 ) ;
struct V_8 * V_9 = F_19 ( V_7 ) ;
return sprintf ( V_64 , L_3 , 1 + V_9 -> V_44 [ V_68 -> V_69 ] ) ;
}
static T_3 F_66 ( struct V_27 * V_7 ,
struct V_62 * V_63 ,
const char * V_64 ,
T_4 V_65 )
{
struct V_67 * V_68 = F_39 ( V_63 ) ;
struct V_1 * V_2 = F_20 ( V_7 ) ;
struct V_8 * V_9 = F_14 ( V_2 ) ;
int V_70 = F_8 ( V_68 -> V_69 ) ;
int V_71 ;
long V_21 ;
T_1 V_3 ;
if ( F_34 ( V_64 , 10 , & V_21 ) )
return - V_66 ;
if ( V_68 -> V_69 % 2 )
V_71 = V_42 ;
else
V_71 = V_43 ;
if ( V_21 != 2 && V_21 != 1 )
return - V_66 ;
V_21 -- ;
F_16 ( & V_9 -> V_24 ) ;
V_9 -> V_44 [ V_68 -> V_69 ] = V_21 ;
V_3 = F_2 ( V_2 , V_70 ) ;
if ( V_21 )
V_3 |= V_71 ;
else
V_3 &= ~ V_71 ;
F_4 ( V_2 , V_70 , V_3 ) ;
F_17 ( & V_9 -> V_24 ) ;
return V_65 ;
}
static T_3 F_67 ( struct V_27 * V_7 ,
struct V_62 * V_63 ,
char * V_64 )
{
struct V_67 * V_68 = F_39 ( V_63 ) ;
struct V_8 * V_9 = F_19 ( V_7 ) ;
T_1 V_72 = V_9 -> V_45 [ V_68 -> V_69 ] ;
if ( V_72 )
return sprintf ( V_64 , L_3 , 1 << ( V_72 - 1 ) ) ;
else
return sprintf ( V_64 , L_3 , V_73 ) ;
}
static int F_68 ( int V_74 )
{
if ( V_74 == V_73 )
return 0 ;
if ( V_74 < 1 || ! F_69 ( V_74 ) )
return - V_66 ;
return F_70 ( V_74 ) + 1 ;
}
static T_3 F_71 ( struct V_27 * V_7 ,
struct V_62 * V_63 ,
const char * V_64 ,
T_4 V_65 )
{
struct V_67 * V_68 = F_39 ( V_63 ) ;
struct V_1 * V_2 = F_20 ( V_7 ) ;
struct V_8 * V_9 = F_14 ( V_2 ) ;
int V_70 = F_23 ( V_68 -> V_69 ) ;
long V_21 ;
T_1 V_3 ;
if ( F_34 ( V_64 , 10 , & V_21 ) )
return - V_66 ;
V_21 = F_68 ( V_21 ) ;
if ( V_21 < 0 )
return V_21 ;
F_16 ( & V_9 -> V_24 ) ;
V_9 -> V_44 [ V_68 -> V_69 ] = V_21 ;
V_3 = F_2 ( V_2 , V_70 ) ;
if ( ! ( V_68 -> V_69 % 2 ) ) {
V_3 &= 0xF ;
V_3 |= ( V_21 << 4 ) & 0xF0 ;
} else {
V_3 &= 0xF0 ;
V_3 |= V_21 & 0xF ;
}
F_4 ( V_2 , V_70 , V_3 ) ;
F_17 ( & V_9 -> V_24 ) ;
return V_65 ;
}
static T_3 F_72 ( struct V_27 * V_7 ,
struct V_62 * V_63 ,
char * V_64 )
{
struct V_67 * V_68 = F_39 ( V_63 ) ;
struct V_8 * V_9 = F_19 ( V_7 ) ;
if ( V_9 -> V_48 & V_68 -> V_69 )
return sprintf ( V_64 , L_6 ) ;
else
return sprintf ( V_64 , L_5 ) ;
}
static int F_73 ( struct V_1 * V_2 ,
struct V_75 * V_76 )
{
struct V_77 * V_78 = V_2 -> V_78 ;
int V_79 , V_27 , V_80 ;
if ( ! F_74 ( V_78 , V_81 ) )
return - V_82 ;
V_79 = F_2 ( V_2 , V_83 ) ;
if ( V_79 != V_84 )
return - V_82 ;
V_27 = F_2 ( V_2 , V_85 ) ;
if ( V_27 != V_86 )
return - V_82 ;
V_80 = F_2 ( V_2 , V_87 ) ;
if ( V_80 != V_88 )
return - V_82 ;
F_75 ( V_76 -> type , L_7 , V_89 ) ;
return 0 ;
}
static int F_76 ( struct V_1 * V_2 ,
const struct V_90 * V_91 )
{
struct V_8 * V_9 ;
int V_92 ;
V_9 = F_77 ( & V_2 -> V_7 , sizeof( struct V_8 ) ,
V_93 ) ;
if ( ! V_9 )
return - V_94 ;
V_9 -> V_17 = - 1 ;
V_9 -> V_25 = V_95 ;
F_78 ( V_2 , V_9 ) ;
F_79 ( & V_9 -> V_24 ) ;
F_80 ( & V_2 -> V_7 , L_8 , V_2 -> V_96 ) ;
F_5 ( V_2 ) ;
V_9 -> V_97 . V_97 = V_98 ;
V_92 = F_81 ( & V_2 -> V_7 . V_99 , & V_9 -> V_97 ) ;
if ( V_92 )
return V_92 ;
V_9 -> V_100 = F_82 ( & V_2 -> V_7 ) ;
if ( F_83 ( V_9 -> V_100 ) ) {
V_92 = F_84 ( V_9 -> V_100 ) ;
goto V_101;
}
F_85 ( & V_9 -> V_26 ) ;
V_9 -> V_102 = F_86 ( F_13 , V_2 ,
F_87 ( V_9 -> V_100 ) ) ;
if ( F_83 ( V_9 -> V_102 ) ) {
V_92 = F_84 ( V_9 -> V_102 ) ;
goto V_103;
}
return 0 ;
V_103:
F_88 ( V_9 -> V_100 ) ;
V_101:
F_89 ( & V_2 -> V_7 . V_99 , & V_9 -> V_97 ) ;
return V_92 ;
}
static int F_90 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_14 ( V_2 ) ;
F_91 ( V_9 -> V_102 ) ;
F_92 ( & V_9 -> V_26 ) ;
F_88 ( V_9 -> V_100 ) ;
F_89 ( & V_2 -> V_7 . V_99 , & V_9 -> V_97 ) ;
return 0 ;
}
