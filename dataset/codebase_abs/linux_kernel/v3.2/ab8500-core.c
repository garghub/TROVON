static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_3 ;
if ( ! V_2 )
return - V_4 ;
V_3 = F_2 ( V_2 -> V_5 ) ;
return V_3 ? ( int ) V_3 -> V_6 : - V_4 ;
}
static int F_3 ( struct V_3 * V_3 , T_1 V_7 ,
T_1 V_8 , T_1 V_9 )
{
int V_10 ;
T_2 V_11 = ( ( T_2 ) V_7 ) << 8 | V_8 ;
F_4 ( V_3 -> V_2 , L_1 , V_11 , V_9 ) ;
V_10 = F_5 ( & V_3 -> V_12 ) ;
if ( V_10 )
return V_10 ;
V_10 = V_3 -> V_13 ( V_3 , V_11 , V_9 ) ;
if ( V_10 < 0 )
F_6 ( V_3 -> V_2 , L_2 ,
V_11 , V_10 ) ;
F_7 ( & V_3 -> V_12 ) ;
return V_10 ;
}
static int F_8 ( struct V_1 * V_2 , T_1 V_7 ,
T_1 V_8 , T_1 V_14 )
{
struct V_3 * V_3 = F_2 ( V_2 -> V_5 ) ;
return F_3 ( V_3 , V_7 , V_8 , V_14 ) ;
}
static int F_9 ( struct V_3 * V_3 , T_1 V_7 ,
T_1 V_8 , T_1 * V_14 )
{
int V_10 ;
T_2 V_11 = ( ( T_2 ) V_7 ) << 8 | V_8 ;
V_10 = F_5 ( & V_3 -> V_12 ) ;
if ( V_10 )
return V_10 ;
V_10 = V_3 -> V_15 ( V_3 , V_11 ) ;
if ( V_10 < 0 )
F_6 ( V_3 -> V_2 , L_3 ,
V_11 , V_10 ) ;
else
* V_14 = V_10 ;
F_7 ( & V_3 -> V_12 ) ;
F_4 ( V_3 -> V_2 , L_4 , V_11 , V_10 ) ;
return V_10 ;
}
static int F_10 ( struct V_1 * V_2 , T_1 V_7 ,
T_1 V_8 , T_1 * V_14 )
{
struct V_3 * V_3 = F_2 ( V_2 -> V_5 ) ;
return F_9 ( V_3 , V_7 , V_8 , V_14 ) ;
}
static int F_11 ( struct V_3 * V_3 , T_1 V_7 ,
T_1 V_8 , T_1 V_16 , T_1 V_17 )
{
int V_10 ;
T_1 V_9 ;
T_2 V_11 = ( ( T_2 ) V_7 ) << 8 | V_8 ;
V_10 = F_5 ( & V_3 -> V_12 ) ;
if ( V_10 )
return V_10 ;
V_10 = V_3 -> V_15 ( V_3 , V_11 ) ;
if ( V_10 < 0 ) {
F_6 ( V_3 -> V_2 , L_3 ,
V_11 , V_10 ) ;
goto V_18;
}
V_9 = ( T_1 ) V_10 ;
V_9 = ( ~ V_16 & V_9 ) | ( V_16 & V_17 ) ;
V_10 = V_3 -> V_13 ( V_3 , V_11 , V_9 ) ;
if ( V_10 < 0 )
F_6 ( V_3 -> V_2 , L_2 ,
V_11 , V_10 ) ;
F_4 ( V_3 -> V_2 , L_5 , V_11 , V_9 ) ;
V_18:
F_7 ( & V_3 -> V_12 ) ;
return V_10 ;
}
static int F_12 ( struct V_1 * V_2 ,
T_1 V_7 , T_1 V_8 , T_1 V_16 , T_1 V_17 )
{
struct V_3 * V_3 = F_2 ( V_2 -> V_5 ) ;
return F_11 ( V_3 , V_7 , V_8 ,
V_16 , V_17 ) ;
}
static void F_13 ( struct V_19 * V_9 )
{
struct V_3 * V_3 = F_14 ( V_9 ) ;
F_15 ( & V_3 -> V_20 ) ;
}
static void F_16 ( struct V_19 * V_9 )
{
struct V_3 * V_3 = F_14 ( V_9 ) ;
int V_21 ;
for ( V_21 = 0 ; V_21 < V_22 ; V_21 ++ ) {
T_1 V_23 = V_3 -> V_24 [ V_21 ] ;
T_1 V_25 = V_3 -> V_26 [ V_21 ] ;
int V_8 ;
if ( V_25 == V_23 )
continue;
if ( V_27 [ V_21 ] == 11 &&
V_3 -> V_6 < V_28 )
continue;
V_3 -> V_24 [ V_21 ] = V_25 ;
V_8 = V_29 + V_27 [ V_21 ] ;
F_3 ( V_3 , V_30 , V_8 , V_25 ) ;
}
F_7 ( & V_3 -> V_20 ) ;
}
static void F_17 ( struct V_19 * V_9 )
{
struct V_3 * V_3 = F_14 ( V_9 ) ;
int V_31 = V_9 -> V_32 - V_3 -> V_33 ;
int V_34 = V_31 / 8 ;
int V_26 = 1 << ( V_31 % 8 ) ;
V_3 -> V_26 [ V_34 ] |= V_26 ;
}
static void F_18 ( struct V_19 * V_9 )
{
struct V_3 * V_3 = F_14 ( V_9 ) ;
int V_31 = V_9 -> V_32 - V_3 -> V_33 ;
int V_34 = V_31 / 8 ;
int V_26 = 1 << ( V_31 % 8 ) ;
V_3 -> V_26 [ V_34 ] &= ~ V_26 ;
}
static T_3 F_19 ( int V_32 , void * V_2 )
{
struct V_3 * V_3 = V_2 ;
int V_21 ;
F_4 ( V_3 -> V_2 , L_6 ) ;
for ( V_21 = 0 ; V_21 < V_22 ; V_21 ++ ) {
int V_35 = V_27 [ V_21 ] ;
int V_36 ;
T_1 V_14 ;
if ( V_35 == 11 && V_3 -> V_6 < V_28 )
continue;
V_36 = F_9 ( V_3 , V_30 ,
V_37 + V_35 , & V_14 ) ;
if ( V_36 < 0 || V_14 == 0 )
continue;
do {
int V_38 = F_20 ( V_14 ) ;
int line = V_21 * 8 + V_38 ;
F_21 ( V_3 -> V_33 + line ) ;
V_14 &= ~ ( 1 << V_38 ) ;
} while ( V_14 );
}
return V_39 ;
}
static int F_22 ( struct V_3 * V_3 )
{
int V_40 = V_3 -> V_33 ;
int V_32 ;
for ( V_32 = V_40 ; V_32 < V_40 + V_41 ; V_32 ++ ) {
F_23 ( V_32 , V_3 ) ;
F_24 ( V_32 , & V_42 ,
V_43 ) ;
F_25 ( V_32 , 1 ) ;
#ifdef F_26
F_27 ( V_32 , V_44 ) ;
#else
F_28 ( V_32 ) ;
#endif
}
return 0 ;
}
static void F_29 ( struct V_3 * V_3 )
{
int V_40 = V_3 -> V_33 ;
int V_32 ;
for ( V_32 = V_40 ; V_32 < V_40 + V_41 ; V_32 ++ ) {
#ifdef F_26
F_27 ( V_32 , 0 ) ;
#endif
F_24 ( V_32 , NULL , NULL ) ;
F_23 ( V_32 , NULL ) ;
}
}
static T_4 F_30 ( struct V_1 * V_2 ,
struct V_45 * V_46 , char * V_47 )
{
struct V_3 * V_3 ;
V_3 = F_2 ( V_2 ) ;
return sprintf ( V_47 , L_7 , V_3 ? V_3 -> V_6 : - V_4 ) ;
}
static T_4 F_31 ( struct V_1 * V_2 ,
struct V_45 * V_46 , char * V_47 )
{
int V_10 ;
T_1 V_14 ;
struct V_3 * V_3 ;
V_3 = F_2 ( V_2 ) ;
V_10 = F_9 ( V_3 , V_48 ,
V_49 , & V_14 ) ;
if ( V_10 < 0 )
return V_10 ;
return sprintf ( V_47 , L_7 , V_14 ) ;
}
static T_4 F_32 ( struct V_1 * V_2 ,
struct V_45 * V_46 , char * V_47 )
{
int V_10 ;
T_1 V_14 ;
struct V_3 * V_3 ;
V_3 = F_2 ( V_2 ) ;
V_10 = F_9 ( V_3 , V_50 ,
V_51 , & V_14 ) ;
if ( V_10 < 0 )
return V_10 ;
return sprintf ( V_47 , L_7 , V_14 ) ;
}
int T_5 F_33 ( struct V_3 * V_3 )
{
struct V_52 * V_53 = F_34 ( V_3 -> V_2 ) ;
int V_10 ;
int V_21 ;
T_1 V_14 ;
if ( V_53 )
V_3 -> V_33 = V_53 -> V_33 ;
F_35 ( & V_3 -> V_12 ) ;
F_35 ( & V_3 -> V_20 ) ;
V_10 = F_9 ( V_3 , V_54 ,
V_55 , & V_14 ) ;
if ( V_10 < 0 )
return V_10 ;
switch ( V_14 ) {
case V_56 :
case V_57 :
case V_28 :
case V_58 :
case V_59 :
F_36 ( V_3 -> V_2 , L_8 , V_14 ) ;
break;
default:
F_6 ( V_3 -> V_2 , L_9 , V_14 ) ;
return - V_4 ;
}
V_3 -> V_6 = V_14 ;
V_10 = F_9 ( V_3 , V_48 ,
V_49 , & V_14 ) ;
if ( V_10 < 0 )
return V_10 ;
F_36 ( V_3 -> V_2 , L_10 , V_14 ) ;
if ( V_53 && V_53 -> V_60 )
V_53 -> V_60 ( V_3 ) ;
for ( V_21 = 0 ; V_21 < V_22 ; V_21 ++ ) {
if ( V_27 [ V_21 ] == 11 &&
V_3 -> V_6 < V_28 )
continue;
F_9 ( V_3 , V_30 ,
V_37 + V_27 [ V_21 ] ,
& V_14 ) ;
F_3 ( V_3 , V_30 ,
V_29 + V_27 [ V_21 ] , 0xff ) ;
}
V_10 = F_37 ( V_3 -> V_2 , & V_61 ) ;
if ( V_10 )
return V_10 ;
for ( V_21 = 0 ; V_21 < V_22 ; V_21 ++ )
V_3 -> V_26 [ V_21 ] = V_3 -> V_24 [ V_21 ] = 0xff ;
if ( V_3 -> V_33 ) {
V_10 = F_22 ( V_3 ) ;
if ( V_10 )
return V_10 ;
V_10 = F_38 ( V_3 -> V_32 , NULL , F_19 ,
V_62 | V_63 ,
L_11 , V_3 ) ;
if ( V_10 )
goto V_64;
}
V_10 = F_39 ( V_3 -> V_2 , 0 , V_65 ,
F_40 ( V_65 ) , NULL ,
V_3 -> V_33 ) ;
if ( V_10 )
goto V_66;
V_10 = F_41 ( & V_3 -> V_2 -> V_67 , & V_68 ) ;
if ( V_10 )
F_6 ( V_3 -> V_2 , L_12 ) ;
return V_10 ;
V_66:
if ( V_3 -> V_33 ) {
F_42 ( V_3 -> V_32 , V_3 ) ;
V_64:
F_29 ( V_3 ) ;
}
return V_10 ;
}
int T_6 F_43 ( struct V_3 * V_3 )
{
F_44 ( & V_3 -> V_2 -> V_67 , & V_68 ) ;
F_45 ( V_3 -> V_2 ) ;
if ( V_3 -> V_33 ) {
F_42 ( V_3 -> V_32 , V_3 ) ;
F_29 ( V_3 ) ;
}
return 0 ;
}
