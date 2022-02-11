int F_1 ( const char * V_1 , unsigned short * V_2 )
{
unsigned long V_3 ;
char * V_4 ;
int V_5 ;
if ( ! isdigit ( V_1 [ 0 ] ) ) {
V_5 = - V_6 ;
goto V_7;
}
V_3 = F_2 ( V_1 , & V_4 , 0 ) ;
if ( V_3 > 0xffff ) {
V_5 = - V_6 ;
goto V_7;
}
* V_2 = V_3 ;
V_5 = V_4 + 1 - V_1 ;
if ( V_5 == 0 )
V_5 = - V_6 ;
V_7:
return V_5 ;
}
static T_1 F_3 ( struct V_8 * V_9 , char * V_10 )
{
return F_4 ( V_10 , V_11 , L_1 , V_12 ) ;
}
static T_1 F_5 ( struct V_8 * V_9 , char * V_10 )
{
return F_4 ( V_10 , V_11 , L_2 ,
F_6 ( NULL , NULL , NULL ) ) ;
}
static T_1 F_7 ( struct V_13 * V_9 ,
struct V_14 * V_15 ,
char * V_10 )
{
struct V_16 * V_17 = F_8 ( V_9 ) ;
T_1 V_5 ;
if ( ! V_17 -> V_18 ) {
V_5 = - V_6 ;
goto V_7;
}
V_5 = F_4 ( V_10 , V_11 , L_3 ,
( unsigned long long ) * ( V_17 -> V_18 ) ) ;
V_7:
return V_5 ;
}
static T_1 F_9 ( struct V_13 * V_9 ,
struct V_14 * V_15 ,
char * V_10 )
{
struct V_16 * V_17 = F_8 ( V_9 ) ;
int V_19 , V_20 ;
T_2 V_21 ;
T_1 V_5 ;
if ( ! V_17 -> V_18 ) {
V_5 = - V_6 ;
goto V_7;
}
V_21 = * ( V_17 -> V_18 ) ;
* V_10 = '\0' ;
for ( V_20 = V_19 = 0 ; V_21 && V_22 [ V_19 ] ; V_19 ++ ) {
if ( V_21 & 1 ) {
if ( V_20 && F_10 ( V_10 , L_4 , V_11 ) >=
V_11 )
break;
if ( F_10 ( V_10 , V_22 [ V_19 ] ,
V_11 ) >= V_11 )
break;
V_20 = 1 ;
}
V_21 >>= 1 ;
}
if ( V_20 )
F_10 ( V_10 , L_5 , V_11 ) ;
V_5 = strlen ( V_10 ) ;
V_7:
return V_5 ;
}
static T_1 F_11 ( struct V_13 * V_9 ,
struct V_14 * V_15 ,
char * V_10 )
{
struct V_16 * V_17 = F_8 ( V_9 ) ;
return F_4 ( V_10 , V_11 , L_1 , V_17 -> V_23 ) ;
}
static T_1 F_12 ( struct V_13 * V_9 ,
struct V_14 * V_15 ,
char * V_10 )
{
struct V_16 * V_17 = F_8 ( V_9 ) ;
return F_4 ( V_10 , V_11 , L_1 , V_17 -> V_24 ) ;
}
static T_1 F_13 ( struct V_13 * V_9 ,
struct V_14 * V_15 ,
char * V_10 )
{
struct V_16 * V_17 = F_8 ( V_9 ) ;
return F_4 ( V_10 , V_11 , L_6 , V_17 -> V_25 ) ;
}
static T_1 F_14 ( struct V_13 * V_9 ,
struct V_14 * V_15 ,
const char * V_10 ,
T_3 V_26 )
{
struct V_16 * V_17 = F_8 ( V_9 ) ;
T_4 V_27 = 0 ;
int V_5 ;
V_5 = F_1 ( V_10 , & V_27 ) ;
if ( V_5 < 0 )
goto V_28;
if ( V_27 > 7 ) {
V_5 = - V_6 ;
goto V_28;
}
F_15 ( V_17 , V_17 -> V_29 , V_27 ) ;
goto V_7;
V_28:
F_16 ( V_17 , L_7 , V_27 ) ;
V_7:
return V_5 ;
}
static T_1 F_17 ( struct V_13 * V_9 ,
struct V_14 * V_15 ,
char * V_10 )
{
struct V_16 * V_17 = F_8 ( V_9 ) ;
return F_4 ( V_10 , V_11 , L_8 , V_17 -> V_29 ) ;
}
static T_1 F_18 ( struct V_13 * V_9 ,
struct V_14 * V_15 ,
const char * V_10 ,
T_3 V_26 )
{
struct V_16 * V_17 = F_8 ( V_9 ) ;
T_4 V_30 = 0 ;
int V_5 ;
V_5 = F_1 ( V_10 , & V_30 ) ;
if ( V_5 < 0 )
goto V_28;
if ( V_30 == 0 || V_30 >= V_31 ) {
V_5 = - V_6 ;
goto V_28;
}
F_15 ( V_17 , V_30 , V_17 -> V_25 ) ;
goto V_7;
V_28:
F_16 ( V_17 , L_9 , V_30 ) ;
V_7:
return V_5 ;
}
static T_1 F_19 ( struct V_13 * V_9 ,
struct V_14 * V_15 ,
char * V_10 )
{
struct V_16 * V_17 = F_8 ( V_9 ) ;
return F_4 ( V_10 , V_11 , L_8 , V_17 -> V_32 ) ;
}
static T_1 F_20 ( struct V_13 * V_9 ,
struct V_14 * V_15 ,
const char * V_10 ,
T_3 V_26 )
{
struct V_16 * V_17 = F_8 ( V_9 ) ;
T_4 V_33 ;
int V_5 ;
V_5 = F_1 ( V_10 , & V_33 ) ;
if ( V_5 < 0 || V_33 < V_31 )
goto V_28;
V_17 -> V_32 = V_33 ;
goto V_7;
V_28:
F_16 ( V_17 , L_10 ) ;
V_7:
return V_5 ;
}
static T_1 F_21 ( struct V_13 * V_9 ,
struct V_14 * V_15 ,
char * V_10 )
{
struct V_16 * V_17 = F_8 ( V_9 ) ;
T_5 * V_34 ;
V_34 = ( T_5 * ) & ( V_17 -> V_35 ) ;
return F_4 ( V_10 , V_11 ,
L_11 ,
V_34 [ 0 ] , V_34 [ 1 ] , V_34 [ 2 ] , V_34 [ 3 ] ,
V_34 [ 4 ] , V_34 [ 5 ] , V_34 [ 6 ] , V_34 [ 7 ] ) ;
}
static T_1 F_22 ( struct V_13 * V_9 ,
struct V_14 * V_15 ,
const char * V_10 ,
T_3 V_26 )
{
struct V_16 * V_17 = F_8 ( V_9 ) ;
T_1 V_5 ;
unsigned short V_34 [ 8 ] ;
T_6 V_36 ;
T_5 * V_37 ;
int V_19 ;
if ( sscanf ( V_10 , L_12 ,
& V_34 [ 0 ] , & V_34 [ 1 ] , & V_34 [ 2 ] , & V_34 [ 3 ] ,
& V_34 [ 4 ] , & V_34 [ 5 ] , & V_34 [ 6 ] , & V_34 [ 7 ] ) != 8 )
goto V_28;
V_37 = ( T_5 * ) & V_36 ;
for ( V_19 = 0 ; V_19 < 8 ; V_19 ++ ) {
if ( V_34 [ V_19 ] > 0xff )
goto V_28;
V_37 [ V_19 ] = V_34 [ V_19 ] ;
}
if ( V_36 == 0 )
goto V_28;
V_17 -> V_35 = V_36 ;
V_17 -> V_38 = 1 ;
if ( V_17 -> V_39 )
V_17 -> V_39 -> V_40 . V_41 = V_36 ;
V_5 = strlen ( V_10 ) ;
goto V_7;
V_28:
F_16 ( V_17 , L_13 ) ;
V_5 = - V_6 ;
V_7:
return V_5 ;
}
static T_1 F_23 ( struct V_13 * V_9 ,
struct V_14 * V_15 ,
char * V_10 )
{
struct V_16 * V_17 = F_8 ( V_9 ) ;
return F_4 ( V_10 , V_11 , L_6 , V_17 -> V_38 ) ;
}
static T_1 F_24 ( struct V_13 * V_9 ,
struct V_14 * V_15 ,
char * V_10 )
{
struct V_16 * V_17 = F_8 ( V_9 ) ;
return F_4 ( V_10 , V_11 , L_6 , V_17 -> V_42 - 1 ) ;
}
static T_1 F_25 ( struct V_13 * V_9 ,
struct V_14 * V_15 ,
char * V_10 )
{
struct V_16 * V_17 = F_8 ( V_9 ) ;
V_10 [ sizeof V_17 -> V_43 ] = '\0' ;
memcpy ( V_10 , V_17 -> V_43 , sizeof V_17 -> V_43 ) ;
strcat ( V_10 , L_5 ) ;
return strlen ( V_10 ) ;
}
static T_1 F_26 ( struct V_13 * V_9 ,
struct V_14 * V_15 ,
char * V_10 )
{
struct V_16 * V_17 = F_8 ( V_9 ) ;
return F_4 ( V_10 , V_11 , L_6 , V_17 -> V_44 ) ;
}
static T_1 F_27 ( struct V_13 * V_9 ,
struct V_14 * V_15 ,
char * V_10 )
{
struct V_16 * V_17 = F_8 ( V_9 ) ;
return F_4 ( V_10 , V_11 , L_14 , V_17 -> V_45 ) ;
}
static T_1 F_28 ( struct V_13 * V_9 ,
struct V_14 * V_15 ,
const char * V_10 ,
T_3 V_26 )
{
struct V_16 * V_17 = F_8 ( V_9 ) ;
T_4 V_46 = 0 ;
int V_5 ;
V_5 = F_1 ( V_10 , & V_46 ) ;
if ( V_5 < 0 )
F_16 ( V_17 , L_15 ) ;
else
V_17 -> V_47 ( V_17 , V_17 -> V_48 , V_46 ) ;
return V_5 ;
}
static T_1 F_29 ( struct V_13 * V_9 ,
struct V_14 * V_15 ,
char * V_10 )
{
struct V_16 * V_17 = F_8 ( V_9 ) ;
return F_4 ( V_10 , V_11 , L_14 , V_17 -> V_48 ) ;
}
static T_1 F_30 ( struct V_13 * V_9 ,
struct V_14 * V_15 ,
const char * V_10 ,
T_3 V_26 )
{
struct V_16 * V_17 = F_8 ( V_9 ) ;
T_4 V_46 = 0 ;
int V_5 ;
V_5 = F_1 ( V_10 , & V_46 ) ;
if ( V_5 < 0 )
F_16 ( V_17 , L_16 ) ;
else
V_17 -> V_47 ( V_17 , V_46 , V_17 -> V_45 ) ;
return V_5 ;
}
static T_1 F_31 ( struct V_13 * V_9 ,
struct V_14 * V_15 ,
const char * V_10 ,
T_3 V_26 )
{
struct V_16 * V_17 = F_8 ( V_9 ) ;
int V_5 ;
if ( V_26 < 5 || memcmp ( V_10 , L_17 , 5 ) ) {
V_5 = - V_6 ;
goto V_7;
}
if ( V_17 -> V_49 & V_50 ) {
F_32 ( V_9 , L_18 ,
V_17 -> V_44 ) ;
V_5 = - V_6 ;
goto V_7;
}
V_5 = F_33 ( V_17 -> V_44 ) ;
V_7:
return V_5 < 0 ? V_5 : V_26 ;
}
static T_1 F_34 ( struct V_13 * V_9 ,
struct V_14 * V_15 ,
const char * V_10 ,
T_3 V_26 )
{
struct V_16 * V_17 = F_8 ( V_9 ) ;
int V_5 , V_51 ;
T_4 V_52 ;
V_5 = F_1 ( V_10 , & V_52 ) ;
if ( V_5 < 0 )
goto V_28;
V_51 = F_35 ( V_17 , V_52 ) ;
if ( V_51 < 0 ) {
V_5 = V_51 ;
goto V_7;
}
goto V_7;
V_28:
F_16 ( V_17 , L_19 ) ;
V_7:
return V_5 ;
}
static T_1 F_36 ( struct V_13 * V_9 ,
struct V_14 * V_15 ,
char * V_10 )
{
struct V_16 * V_17 = F_8 ( V_9 ) ;
return F_4 ( V_10 , V_11 , L_6 , V_17 -> V_53 ) ;
}
static T_1 F_37 ( struct V_13 * V_9 ,
struct V_14 * V_15 ,
const char * V_10 ,
T_3 V_26 )
{
struct V_16 * V_17 = F_8 ( V_9 ) ;
T_1 V_5 ;
T_4 V_54 = 0 ;
int V_51 ;
V_5 = F_1 ( V_10 , & V_54 ) ;
if ( V_5 < 0 )
goto V_28;
V_51 = F_38 ( V_17 , V_54 ) ;
if ( V_51 < 0 )
V_5 = V_51 ;
goto V_7;
V_28:
F_16 ( V_17 , L_20 ) ;
V_7:
return V_5 ;
}
static T_1 F_39 ( struct V_13 * V_9 ,
struct V_14 * V_15 ,
char * V_10 )
{
struct V_16 * V_17 = F_8 ( V_9 ) ;
return F_4 ( V_10 , V_11 , L_6 ,
( V_17 -> V_49 & V_50 ) ? 0 : 1 ) ;
}
static T_1 F_40 ( struct V_13 * V_9 ,
struct V_14 * V_15 ,
const char * V_10 ,
T_3 V_26 )
{
struct V_16 * V_17 = F_8 ( V_9 ) ;
T_1 V_5 ;
T_4 V_55 = 0 ;
V_5 = F_1 ( V_10 , & V_55 ) ;
if ( V_5 < 0 ) {
F_16 ( V_17 , L_21 ) ;
goto V_7;
}
if ( V_55 ) {
if ( ! ( V_17 -> V_49 & V_50 ) )
goto V_7;
F_32 ( V_9 , L_22 , V_17 -> V_44 ) ;
V_5 = F_41 ( V_17 , 1 ) ;
if ( V_5 )
F_16 ( V_17 , L_23 ,
V_17 -> V_44 ) ;
else {
V_17 -> V_49 &= ~ V_50 ;
* V_17 -> V_18 &= ~ V_56 ;
}
}
else if ( ! ( V_17 -> V_49 & V_50 ) ) {
F_32 ( V_9 , L_24 , V_17 -> V_44 ) ;
F_42 ( V_17 ) ;
V_17 -> V_49 |= V_50 ;
* V_17 -> V_18 |= V_56 ;
}
V_7:
return V_5 ;
}
static T_1 F_43 ( struct V_13 * V_9 ,
struct V_14 * V_15 ,
const char * V_10 ,
T_3 V_26 )
{
struct V_16 * V_17 = F_8 ( V_9 ) ;
int V_5 , V_51 ;
T_4 V_3 ;
V_5 = F_1 ( V_10 , & V_3 ) ;
if ( V_5 < 0 )
goto V_28;
V_51 = F_44 ( V_17 , V_3 ) ;
if ( V_51 < 0 ) {
V_5 = V_51 ;
goto V_7;
}
goto V_7;
V_28:
F_16 ( V_17 , L_25 ) ;
V_7:
return V_5 ;
}
static T_1 F_45 ( struct V_13 * V_9 ,
struct V_14 * V_15 ,
const char * V_10 ,
T_3 V_26 )
{
struct V_16 * V_17 = F_8 ( V_9 ) ;
int V_5 ;
T_4 V_3 ;
V_5 = F_1 ( V_10 , & V_3 ) ;
if ( V_5 > 0 )
F_46 ( V_17 , V_3 ) ;
else
F_16 ( V_17 , L_26 ) ;
return V_5 ;
}
static T_1 F_47 ( struct V_13 * V_9 ,
struct V_14 * V_15 ,
char * V_10 )
{
struct V_16 * V_17 = F_8 ( V_9 ) ;
int V_57 , V_26 ;
if ( F_48 ( V_17 ) != 0 )
return - V_58 ;
V_26 = 0 ;
for ( V_57 = 0 ; V_57 < V_59 ; ++ V_57 ) {
V_26 += F_4 ( V_10 + V_26 , V_11 - V_26 , L_27 ,
V_17 -> V_60 [ V_57 ] ,
V_57 == ( V_59 - 1 ) ? '\n' : ' ' ) ;
}
return V_26 ;
}
static T_1 F_49 ( struct V_13 * V_9 ,
struct V_14 * V_15 ,
char * V_10 )
{
struct V_16 * V_17 = F_8 ( V_9 ) ;
int V_5 ;
V_5 = V_17 -> V_61 ( V_17 , V_62 ) ;
if ( V_5 >= 0 )
V_5 = F_4 ( V_10 , V_11 , L_2 , V_5 ) ;
return V_5 ;
}
static T_1 F_50 ( struct V_13 * V_9 ,
struct V_14 * V_15 ,
const char * V_10 ,
T_3 V_26 )
{
struct V_16 * V_17 = F_8 ( V_9 ) ;
int V_5 , V_51 ;
T_4 V_3 ;
V_5 = F_1 ( V_10 , & V_3 ) ;
if ( V_5 >= 0 && V_3 > 3 )
V_5 = - V_6 ;
if ( V_5 < 0 ) {
F_16 ( V_17 , L_28 ) ;
goto V_7;
}
V_51 = V_17 -> V_63 ( V_17 , V_62 , V_3 ) ;
if ( V_51 < 0 )
V_5 = V_51 ;
else if ( V_3 == V_64 )
V_17 -> V_49 |= V_65 ;
else
V_17 -> V_49 &= ~ V_65 ;
V_7:
return V_5 ;
}
static T_1 F_51 ( struct V_13 * V_9 ,
struct V_14 * V_15 ,
char * V_10 )
{
struct V_16 * V_17 = F_8 ( V_9 ) ;
int V_5 ;
V_5 = V_17 -> V_61 ( V_17 , V_66 ) ;
if ( V_5 >= 0 )
V_5 = F_4 ( V_10 , V_11 , L_2 , V_5 ) ;
return V_5 ;
}
static T_1 F_52 ( struct V_13 * V_9 ,
struct V_14 * V_15 ,
const char * V_10 ,
T_3 V_26 )
{
struct V_16 * V_17 = F_8 ( V_9 ) ;
int V_5 , V_51 ;
T_4 V_3 ;
V_5 = F_1 ( V_10 , & V_3 ) ;
if ( V_5 >= 0 && ( V_3 == 0 || V_3 > 3 ) )
V_5 = - V_6 ;
if ( V_5 < 0 ) {
F_16 ( V_17 ,
L_29 ) ;
goto V_7;
}
V_51 = V_17 -> V_63 ( V_17 , V_66 , V_3 ) ;
if ( V_51 < 0 )
V_5 = V_51 ;
V_7:
return V_5 ;
}
static T_1 F_53 ( struct V_13 * V_9 ,
struct V_14 * V_15 ,
char * V_10 )
{
struct V_16 * V_17 = F_8 ( V_9 ) ;
int V_5 ;
V_5 = V_17 -> V_61 ( V_17 , V_67 ) ;
if ( V_5 >= 0 )
V_5 = F_4 ( V_10 , V_11 , L_2 , V_5 ) ;
return V_5 ;
}
static T_1 F_54 ( struct V_13 * V_9 ,
struct V_14 * V_15 ,
char * V_10 )
{
struct V_16 * V_17 = F_8 ( V_9 ) ;
int V_5 ;
V_5 = V_17 -> V_61 ( V_17 , V_68 ) ;
if ( V_5 >= 0 )
V_5 = F_4 ( V_10 , V_11 , L_2 , V_5 ) ;
return V_5 ;
}
static T_1 F_55 ( struct V_13 * V_9 ,
struct V_14 * V_15 ,
const char * V_10 ,
T_3 V_26 )
{
struct V_16 * V_17 = F_8 ( V_9 ) ;
int V_5 , V_51 ;
T_4 V_3 ;
V_5 = F_1 ( V_10 , & V_3 ) ;
if ( V_5 >= 0 && ( V_3 == 0 || V_3 > ( V_69 | V_70 ) ) )
V_5 = - V_6 ;
if ( V_5 < 0 ) {
F_16 ( V_17 ,
L_30 ) ;
goto V_7;
}
V_51 = V_17 -> V_63 ( V_17 , V_68 , V_3 ) ;
if ( V_51 < 0 )
V_5 = V_51 ;
V_7:
return V_5 ;
}
static T_1 F_56 ( struct V_13 * V_9 ,
struct V_14 * V_15 ,
char * V_10 )
{
struct V_16 * V_17 = F_8 ( V_9 ) ;
int V_5 ;
V_5 = V_17 -> V_61 ( V_17 , V_71 ) ;
if ( V_5 >= 0 )
V_5 = F_4 ( V_10 , V_11 , L_2 , V_5 ) ;
return V_5 ;
}
static T_1 F_57 ( struct V_13 * V_9 ,
struct V_14 * V_15 ,
char * V_10 )
{
struct V_16 * V_17 = F_8 ( V_9 ) ;
int V_5 ;
V_5 = V_17 -> V_61 ( V_17 , V_72 ) ;
if ( V_5 >= 0 )
V_5 = F_4 ( V_10 , V_11 , L_2 , V_5 ) ;
return V_5 ;
}
static T_1 F_58 ( struct V_13 * V_9 ,
struct V_14 * V_15 ,
const char * V_10 ,
T_3 V_26 )
{
struct V_16 * V_17 = F_8 ( V_9 ) ;
int V_5 , V_51 ;
T_4 V_3 ;
V_5 = F_1 ( V_10 , & V_3 ) ;
if ( V_5 >= 0 && V_3 > 1 ) {
F_16 ( V_17 ,
L_31 ) ;
V_5 = - V_6 ;
goto V_7;
}
V_51 = V_17 -> V_63 ( V_17 , V_72 , V_3 ) ;
if ( V_51 < 0 )
V_5 = V_51 ;
V_7:
return V_5 ;
}
static T_1 F_59 ( struct V_13 * V_9 ,
struct V_14 * V_15 ,
char * V_10 )
{
struct V_16 * V_17 = F_8 ( V_9 ) ;
int V_5 ;
V_5 = V_17 -> V_61 ( V_17 , V_73 ) ;
if ( V_5 >= 0 )
V_5 = F_4 ( V_10 , V_11 , L_2 , V_5 ) ;
return V_5 ;
}
static T_1 F_60 ( struct V_13 * V_9 ,
struct V_14 * V_15 ,
const char * V_10 ,
T_3 V_26 )
{
struct V_16 * V_17 = F_8 ( V_9 ) ;
int V_5 , V_51 ;
T_4 V_3 ;
V_5 = F_1 ( V_10 , & V_3 ) ;
if ( V_5 >= 0 && V_3 > 1 ) {
V_5 = - V_6 ;
F_16 ( V_17 ,
L_32 ) ;
goto V_7;
}
V_51 = V_17 -> V_63 ( V_17 , V_73 , V_3 ) ;
if ( V_51 < 0 )
V_5 = V_51 ;
V_7:
return V_5 ;
}
static T_1 F_61 ( struct V_13 * V_9 ,
struct V_14 * V_15 ,
const char * V_10 ,
T_3 V_26 )
{
struct V_16 * V_17 = F_8 ( V_9 ) ;
int V_5 , V_74 ;
T_4 V_3 ;
V_5 = F_1 ( V_10 , & V_3 ) ;
if ( V_5 <= 0 ) {
F_16 ( V_17 , L_33 ) ;
goto V_7;
}
V_74 = F_62 ( V_17 , 9 , ( V_3 == 0x7f7f ) ? 0x80 : 0 ) ;
if ( V_74 ) {
F_16 ( V_17 , L_34 ) ;
V_5 = - 1 ;
goto V_7;
}
V_74 = F_62 ( V_17 , 0xB , ( T_5 ) ( V_3 & 0xFF ) ) ;
if ( V_74 ) {
F_16 ( V_17 , L_35 ) ;
V_5 = - 1 ;
goto V_7;
}
V_74 = F_62 ( V_17 , 0xD , ( T_5 ) ( V_3 >> 8 ) ) ;
if ( V_74 ) {
F_16 ( V_17 , L_36 ) ;
V_5 = - 1 ;
goto V_7;
}
V_7:
return V_5 ;
}
static T_1 F_63 ( struct V_13 * V_9 ,
struct V_14 * V_15 ,
char * V_10 )
{
struct V_16 * V_17 = F_8 ( V_9 ) ;
int V_5 ;
int V_57 ;
T_5 V_75 [ 8 ] ;
V_5 = - V_58 ;
for ( V_57 = 0 ; V_57 < 8 ; ++ V_57 ) {
if ( V_57 == 6 )
continue;
V_5 = F_64 ( V_17 , V_57 ) ;
if ( V_5 < 0 )
break;
V_75 [ V_57 ] = V_5 ;
}
if ( V_57 == 8 )
V_5 = F_4 ( V_10 , V_11 , L_37 ,
* ( signed char * ) ( V_75 ) ,
* ( signed char * ) ( V_75 + 1 ) ,
V_75 [ 2 ] , V_75 [ 3 ] ,
* ( signed char * ) ( V_75 + 5 ) ,
* ( signed char * ) ( V_75 + 7 ) ) ;
return V_5 ;
}
int F_65 ( struct V_13 * V_9 )
{
static int V_76 ;
int V_5 ;
if ( ! V_76 ) {
V_5 = F_66 ( V_9 , & V_77 ) ;
V_76 = 1 ;
}
else
V_5 = 0 ;
return V_5 ;
}
int F_67 ( struct V_13 * V_9 , struct V_16 * V_17 )
{
int V_5 ;
V_5 = F_68 ( & V_9 -> V_78 , & V_79 ) ;
if ( V_5 )
goto V_7;
V_5 = F_68 ( & V_9 -> V_78 , & V_80 ) ;
if ( V_5 )
goto V_81;
if ( V_17 -> V_49 & V_82 ) {
V_5 = F_66 ( V_9 , & V_83 ) ;
if ( V_5 )
goto V_84;
V_5 = F_66 ( V_9 , & V_85 ) ;
if ( V_5 )
goto V_86;
V_5 = F_68 ( & V_9 -> V_78 , & V_87 ) ;
if ( V_5 )
goto V_88;
}
return 0 ;
V_88:
F_69 ( V_9 , & V_85 ) ;
V_86:
F_69 ( V_9 , & V_83 ) ;
V_84:
F_70 ( & V_9 -> V_78 , & V_80 ) ;
V_81:
F_70 ( & V_9 -> V_78 , & V_79 ) ;
V_7:
return V_5 ;
}
void F_71 ( struct V_13 * V_9 , struct V_16 * V_17 )
{
F_70 ( & V_9 -> V_78 , & V_80 ) ;
if ( V_17 -> V_49 & V_82 ) {
F_70 ( & V_9 -> V_78 , & V_87 ) ;
F_69 ( V_9 , & V_83 ) ;
F_69 ( V_9 , & V_85 ) ;
}
F_70 ( & V_9 -> V_78 , & V_79 ) ;
F_69 ( V_9 , & V_77 ) ;
}
