static int F_1 ( const char * V_1 , unsigned short * V_2 )
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
struct V_11 * V_12 = V_9 -> V_12 ;
int V_5 ;
V_5 = V_12 -> V_13 ( V_9 , V_14 ) ;
V_5 = F_4 ( V_10 , V_15 , L_1 , V_5 ) ;
return V_5 ;
}
static T_1 F_5 ( struct V_8 * V_9 , const char * V_10 ,
T_2 V_16 )
{
struct V_11 * V_12 = V_9 -> V_12 ;
int V_5 ;
T_3 V_3 ;
V_5 = F_1 ( V_10 , & V_3 ) ;
if ( V_5 >= 0 )
V_5 = V_12 -> V_17 ( V_9 , V_14 , V_3 ) ;
if ( V_5 < 0 )
F_6 ( V_12 , L_2 ) ;
return V_5 < 0 ? V_5 : V_16 ;
}
static T_1 F_7 ( struct V_8 * V_9 , const char * V_10 ,
T_2 V_16 )
{
struct V_11 * V_12 = V_9 -> V_12 ;
int V_5 = V_16 , V_18 ;
V_18 = V_12 -> V_19 ( V_9 , V_10 ) ;
if ( V_18 < 0 )
V_5 = V_18 ;
return V_5 ;
}
static T_1 F_8 ( struct V_8 * V_9 , const char * V_10 ,
T_2 V_16 )
{
struct V_11 * V_12 = V_9 -> V_12 ;
int V_5 ;
T_3 V_3 ;
V_5 = F_1 ( V_10 , & V_3 ) ;
if ( V_5 > 0 )
F_9 ( V_9 , V_3 ) ;
else
F_6 ( V_12 , L_3 ) ;
return V_5 < 0 ? V_5 : V_16 ;
}
static T_1 F_10 ( struct V_8 * V_9 , char * V_10 )
{
T_1 V_5 ;
if ( ! V_9 -> V_20 )
V_5 = - V_6 ;
else
V_5 = F_4 ( V_10 , V_15 , L_4 ,
( unsigned long long ) * ( V_9 -> V_20 ) ) ;
return V_5 ;
}
static T_1 F_11 ( struct V_8 * V_9 , char * V_10 )
{
int V_21 , V_22 ;
T_4 V_23 ;
T_1 V_5 ;
if ( ! V_9 -> V_20 ) {
V_5 = - V_6 ;
goto V_7;
}
V_23 = * ( V_9 -> V_20 ) ;
* V_10 = '\0' ;
for ( V_22 = V_21 = 0 ; V_23 && V_24 [ V_21 ] ; V_21 ++ ) {
if ( V_23 & 1 ) {
if ( V_22 && F_12 ( V_10 , L_5 , V_15 ) >= V_15 )
break;
if ( F_12 ( V_10 , V_24 [ V_21 ] , V_15 ) >=
V_15 )
break;
V_22 = 1 ;
}
V_23 >>= 1 ;
}
if ( V_22 )
F_12 ( V_10 , L_6 , V_15 ) ;
V_5 = strlen ( V_10 ) ;
V_7:
return V_5 ;
}
static T_1 F_13 ( struct V_25 * V_26 ,
struct V_27 * V_28 , char * V_10 )
{
struct V_29 * V_30 =
F_14 ( V_28 , struct V_29 , V_28 ) ;
struct V_8 * V_9 =
F_14 ( V_26 , struct V_8 , V_31 ) ;
return V_30 -> V_32 ( V_9 , V_10 ) ;
}
static T_1 F_15 ( struct V_25 * V_26 ,
struct V_27 * V_28 , const char * V_10 , T_2 V_33 )
{
struct V_29 * V_30 =
F_14 ( V_28 , struct V_29 , V_28 ) ;
struct V_8 * V_9 =
F_14 ( V_26 , struct V_8 , V_31 ) ;
return V_30 -> V_34 ( V_9 , V_10 , V_33 ) ;
}
static void F_16 ( struct V_25 * V_26 )
{
}
static T_1 F_17 ( struct V_25 * V_26 , struct V_27 * V_28 ,
char * V_10 )
{
struct V_35 * V_36 =
F_14 ( V_28 , struct V_35 , V_28 ) ;
struct V_8 * V_9 =
F_14 ( V_26 , struct V_8 , V_37 ) ;
struct V_38 * V_39 = & V_9 -> V_40 ;
return sprintf ( V_10 , L_7 , V_39 -> V_41 [ V_36 -> V_42 ] ) ;
}
static T_1 F_18 ( struct V_25 * V_26 , struct V_27 * V_28 ,
char * V_10 )
{
struct V_43 * V_44 =
F_14 ( V_28 , struct V_43 , V_28 ) ;
struct V_8 * V_9 =
F_14 ( V_26 , struct V_8 , V_45 ) ;
struct V_38 * V_39 = & V_9 -> V_40 ;
return sprintf ( V_10 , L_7 , * ( V_46 * ) ( ( char * ) V_39 + V_44 -> V_47 ) ) ;
}
static T_1 F_19 ( struct V_25 * V_26 , struct V_27 * V_28 ,
const char * V_10 , T_2 V_48 )
{
struct V_43 * V_44 =
F_14 ( V_28 , struct V_43 , V_28 ) ;
struct V_8 * V_9 =
F_14 ( V_26 , struct V_8 , V_45 ) ;
struct V_38 * V_39 = & V_9 -> V_40 ;
char * V_49 ;
long V_3 = F_20 ( V_10 , & V_49 , 0 ) ;
if ( V_3 < 0 || V_49 == V_10 )
return - V_6 ;
* ( V_46 * ) ( ( char * ) V_39 + V_44 -> V_47 ) = V_3 ;
return V_48 ;
}
static T_1 F_21 ( struct V_50 * V_50 , struct V_51 * V_28 ,
char * V_10 )
{
struct V_52 * V_53 =
F_14 ( V_50 , struct V_52 , V_54 . V_53 ) ;
return sprintf ( V_10 , L_8 , F_22 ( V_53 ) -> V_55 ) ;
}
static T_1 F_23 ( struct V_50 * V_50 , struct V_51 * V_28 ,
char * V_10 )
{
struct V_52 * V_53 =
F_14 ( V_50 , struct V_52 , V_54 . V_53 ) ;
struct V_11 * V_12 = F_22 ( V_53 ) ;
int V_5 ;
if ( ! V_12 -> V_56 )
V_5 = - V_6 ;
else
V_5 = F_4 ( V_10 , V_15 , L_9 , V_12 -> V_56 ) ;
return V_5 ;
}
static T_1 F_24 ( struct V_50 * V_50 ,
struct V_51 * V_28 , char * V_10 )
{
return F_4 ( V_10 , V_15 , L_10 , ( char * ) V_57 ) ;
}
static T_1 F_25 ( struct V_50 * V_50 ,
struct V_51 * V_28 , char * V_10 )
{
struct V_52 * V_53 =
F_14 ( V_50 , struct V_52 , V_54 . V_53 ) ;
struct V_11 * V_12 = F_22 ( V_53 ) ;
return F_4 ( V_10 , V_15 , L_10 , V_12 -> V_58 ) ;
}
static T_1 F_26 ( struct V_50 * V_50 ,
struct V_51 * V_28 , char * V_10 )
{
struct V_52 * V_53 =
F_14 ( V_50 , struct V_52 , V_54 . V_53 ) ;
struct V_11 * V_12 = F_22 ( V_53 ) ;
return F_4 ( V_10 , V_15 , L_10 , V_12 -> V_59 ) ;
}
static T_1 F_27 ( struct V_50 * V_50 ,
struct V_51 * V_28 , char * V_10 )
{
struct V_52 * V_53 =
F_14 ( V_50 , struct V_52 , V_54 . V_53 ) ;
struct V_11 * V_12 = F_22 ( V_53 ) ;
return F_4 ( V_10 , V_15 , L_7 , V_12 -> V_60 -
V_12 -> V_61 ) ;
}
static T_1 F_28 ( struct V_50 * V_50 ,
struct V_51 * V_28 , char * V_10 )
{
struct V_52 * V_53 =
F_14 ( V_50 , struct V_52 , V_54 . V_53 ) ;
struct V_11 * V_12 = F_22 ( V_53 ) ;
return F_4 ( V_10 , V_15 , L_7 , V_12 -> V_62 ) ;
}
static T_1 F_29 ( struct V_50 * V_50 ,
struct V_51 * V_28 , char * V_10 )
{
struct V_52 * V_53 =
F_14 ( V_50 , struct V_52 , V_54 . V_53 ) ;
struct V_11 * V_12 = F_22 ( V_53 ) ;
V_10 [ sizeof V_12 -> V_63 ] = '\0' ;
memcpy ( V_10 , V_12 -> V_63 , sizeof V_12 -> V_63 ) ;
strcat ( V_10 , L_6 ) ;
return strlen ( V_10 ) ;
}
static T_1 F_30 ( struct V_50 * V_50 ,
struct V_51 * V_28 , const char * V_10 ,
T_2 V_16 )
{
struct V_52 * V_53 =
F_14 ( V_50 , struct V_52 , V_54 . V_53 ) ;
struct V_11 * V_12 = F_22 ( V_53 ) ;
int V_5 ;
if ( V_16 < 5 || memcmp ( V_10 , L_11 , 5 ) || ! V_12 -> V_64 ) {
V_5 = - V_6 ;
goto V_7;
}
V_5 = F_31 ( V_12 -> V_65 ) ;
V_7:
return V_5 < 0 ? V_5 : V_16 ;
}
static T_1 F_32 ( struct V_50 * V_50 ,
struct V_51 * V_28 , char * V_10 )
{
struct V_52 * V_53 =
F_14 ( V_50 , struct V_52 , V_54 . V_53 ) ;
struct V_11 * V_12 = F_22 ( V_53 ) ;
int V_66 , V_16 ;
if ( F_33 ( V_12 ) != 0 )
return - V_67 ;
V_16 = 0 ;
for ( V_66 = 0 ; V_66 < V_68 ; ++ V_66 ) {
V_16 += F_4 ( V_10 + V_16 , V_15 - V_16 , L_12 ,
V_12 -> V_69 [ V_66 ] ,
V_66 == ( V_68 - 1 ) ? '\n' : ' ' ) ;
}
return V_16 ;
}
static T_1 F_34 ( struct V_50 * V_50 ,
struct V_51 * V_28 , char * V_10 )
{
struct V_52 * V_53 =
F_14 ( V_50 , struct V_52 , V_54 . V_53 ) ;
struct V_11 * V_12 = F_22 ( V_53 ) ;
int V_5 ;
int V_66 ;
T_5 V_70 [ 8 ] ;
V_5 = - V_67 ;
for ( V_66 = 0 ; V_66 < 8 ; ++ V_66 ) {
if ( V_66 == 6 )
continue;
V_5 = V_12 -> V_71 ( V_12 , V_66 ) ;
if ( V_5 < 0 )
break;
V_70 [ V_66 ] = V_5 ;
}
if ( V_66 == 8 )
V_5 = F_4 ( V_10 , V_15 , L_13 ,
* ( signed char * ) ( V_70 ) ,
* ( signed char * ) ( V_70 + 1 ) ,
V_70 [ 2 ] , V_70 [ 3 ] ,
* ( signed char * ) ( V_70 + 5 ) ,
* ( signed char * ) ( V_70 + 7 ) ) ;
return V_5 ;
}
int F_35 ( struct V_72 * V_54 , T_5 V_73 ,
struct V_25 * V_26 )
{
struct V_8 * V_9 ;
struct V_11 * V_12 = F_36 ( V_54 ) ;
int V_5 ;
if ( ! V_73 || V_73 > V_12 -> V_74 ) {
F_6 ( V_12 , L_14
L_15 , V_73 ) ;
V_5 = - V_75 ;
goto V_7;
}
V_9 = & V_12 -> V_76 [ V_73 - 1 ] ;
V_5 = F_37 ( & V_9 -> V_31 , & V_77 , V_26 ,
L_16 ) ;
if ( V_5 ) {
F_6 ( V_12 , L_17
L_18 , V_5 , V_73 ) ;
goto V_7;
}
F_38 ( & V_9 -> V_31 , V_78 ) ;
V_5 = F_37 ( & V_9 -> V_37 , & V_79 , V_26 ,
L_19 ) ;
if ( V_5 ) {
F_6 ( V_12 , L_20
L_18 , V_5 , V_73 ) ;
goto V_80;
}
F_38 ( & V_9 -> V_37 , V_78 ) ;
V_5 = F_37 ( & V_9 -> V_45 , & V_81 , V_26 ,
L_21 ) ;
if ( V_5 ) {
F_6 ( V_12 , L_22
L_18 , V_5 , V_73 ) ;
goto V_82;
}
F_38 ( & V_9 -> V_45 , V_78 ) ;
return 0 ;
V_82:
F_39 ( & V_9 -> V_37 ) ;
V_80:
F_39 ( & V_9 -> V_31 ) ;
V_7:
return V_5 ;
}
int F_40 ( struct V_11 * V_12 )
{
struct V_72 * V_53 = & V_12 -> V_83 . V_54 ;
int V_21 , V_5 ;
for ( V_21 = 0 ; V_21 < F_41 ( V_84 ) ; ++ V_21 ) {
V_5 = F_42 ( & V_53 -> V_53 , V_84 [ V_21 ] ) ;
if ( V_5 )
return V_5 ;
}
return 0 ;
}
void F_43 ( struct V_11 * V_12 )
{
struct V_8 * V_9 ;
int V_21 ;
for ( V_21 = 0 ; V_21 < V_12 -> V_74 ; V_21 ++ ) {
V_9 = & V_12 -> V_76 [ V_21 ] ;
F_39 ( & V_9 -> V_31 ) ;
F_39 ( & V_9 -> V_37 ) ;
}
}
