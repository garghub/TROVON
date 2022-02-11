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
F_5 ( & V_3 -> V_12 ) ;
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
F_5 ( & V_3 -> V_12 ) ;
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
T_2 V_11 = ( ( T_2 ) V_7 ) << 8 | V_8 ;
F_5 ( & V_3 -> V_12 ) ;
if ( V_3 -> V_18 == NULL ) {
T_1 V_9 ;
V_10 = V_3 -> V_15 ( V_3 , V_11 ) ;
if ( V_10 < 0 ) {
F_6 ( V_3 -> V_2 , L_3 ,
V_11 , V_10 ) ;
goto V_19;
}
V_9 = ( T_1 ) V_10 ;
V_9 = ( ~ V_16 & V_9 ) | ( V_16 & V_17 ) ;
V_10 = V_3 -> V_13 ( V_3 , V_11 , V_9 ) ;
if ( V_10 < 0 )
F_6 ( V_3 -> V_2 , L_2 ,
V_11 , V_10 ) ;
F_4 ( V_3 -> V_2 , L_5 , V_11 ,
V_9 ) ;
goto V_19;
}
V_10 = V_3 -> V_18 ( V_3 , V_11 , V_16 , V_17 ) ;
if ( V_10 < 0 )
F_6 ( V_3 -> V_2 , L_6 , V_11 ,
V_10 ) ;
V_19:
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
static void F_13 ( struct V_20 * V_9 )
{
struct V_3 * V_3 = F_14 ( V_9 ) ;
F_5 ( & V_3 -> V_21 ) ;
}
static void F_15 ( struct V_20 * V_9 )
{
struct V_3 * V_3 = F_14 ( V_9 ) ;
int V_22 ;
for ( V_22 = 0 ; V_22 < V_3 -> V_23 ; V_22 ++ ) {
T_1 V_24 = V_3 -> V_25 [ V_22 ] ;
T_1 V_26 = V_3 -> V_27 [ V_22 ] ;
int V_8 ;
if ( V_26 == V_24 )
continue;
if ( V_3 -> V_28 [ V_22 ] == 11 &&
F_16 ( V_3 ) )
continue;
V_3 -> V_25 [ V_22 ] = V_26 ;
V_8 = V_29 + V_3 -> V_28 [ V_22 ] ;
F_3 ( V_3 , V_30 , V_8 , V_26 ) ;
}
F_7 ( & V_3 -> V_21 ) ;
}
static void F_17 ( struct V_20 * V_9 )
{
struct V_3 * V_3 = F_14 ( V_9 ) ;
int V_31 = V_9 -> V_32 - V_3 -> V_33 ;
int V_34 = V_31 / 8 ;
int V_27 = 1 << ( V_31 % 8 ) ;
V_3 -> V_27 [ V_34 ] |= V_27 ;
}
static void F_18 ( struct V_20 * V_9 )
{
struct V_3 * V_3 = F_14 ( V_9 ) ;
int V_31 = V_9 -> V_32 - V_3 -> V_33 ;
int V_34 = V_31 / 8 ;
int V_27 = 1 << ( V_31 % 8 ) ;
V_3 -> V_27 [ V_34 ] &= ~ V_27 ;
}
static T_3 F_19 ( int V_32 , void * V_2 )
{
struct V_3 * V_3 = V_2 ;
int V_22 ;
F_4 ( V_3 -> V_2 , L_7 ) ;
for ( V_22 = 0 ; V_22 < V_3 -> V_23 ; V_22 ++ ) {
int V_35 = V_3 -> V_28 [ V_22 ] ;
int V_36 ;
T_1 V_14 ;
if ( V_35 == 11 && F_16 ( V_3 ) )
continue;
V_36 = F_9 ( V_3 , V_30 ,
V_37 + V_35 , & V_14 ) ;
if ( V_36 < 0 || V_14 == 0 )
continue;
do {
int V_38 = F_20 ( V_14 ) ;
int line = V_22 * 8 + V_38 ;
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
int V_41 ;
if ( F_23 ( V_3 ) )
V_41 = V_42 ;
else if ( F_24 ( V_3 ) )
V_41 = V_43 ;
else
V_41 = V_44 ;
for ( V_32 = V_40 ; V_32 < V_40 + V_41 ; V_32 ++ ) {
F_25 ( V_32 , V_3 ) ;
F_26 ( V_32 , & V_45 ,
V_46 ) ;
F_27 ( V_32 , 1 ) ;
#ifdef F_28
F_29 ( V_32 , V_47 ) ;
#else
F_30 ( V_32 ) ;
#endif
}
return 0 ;
}
static void F_31 ( struct V_3 * V_3 )
{
int V_40 = V_3 -> V_33 ;
int V_32 ;
int V_41 ;
if ( F_23 ( V_3 ) )
V_41 = V_42 ;
else if ( F_24 ( V_3 ) )
V_41 = V_43 ;
else
V_41 = V_44 ;
for ( V_32 = V_40 ; V_32 < V_40 + V_41 ; V_32 ++ ) {
#ifdef F_28
F_29 ( V_32 , 0 ) ;
#endif
F_26 ( V_32 , NULL , NULL ) ;
F_25 ( V_32 , NULL ) ;
}
}
static T_4 F_32 ( struct V_1 * V_2 ,
struct V_48 * V_49 , char * V_50 )
{
struct V_3 * V_3 ;
V_3 = F_2 ( V_2 ) ;
return sprintf ( V_50 , L_8 , V_3 ? V_3 -> V_6 : - V_4 ) ;
}
static T_4 F_33 ( struct V_1 * V_2 ,
struct V_48 * V_49 , char * V_50 )
{
int V_10 ;
T_1 V_14 ;
struct V_3 * V_3 ;
V_3 = F_2 ( V_2 ) ;
V_10 = F_9 ( V_3 , V_51 ,
V_52 , & V_14 ) ;
if ( V_10 < 0 )
return V_10 ;
return sprintf ( V_50 , L_8 , V_14 ) ;
}
static T_4 F_34 ( struct V_1 * V_2 ,
struct V_48 * V_49 , char * V_50 )
{
int V_10 ;
T_1 V_14 ;
struct V_3 * V_3 ;
V_3 = F_2 ( V_2 ) ;
V_10 = F_9 ( V_3 , V_53 ,
V_54 , & V_14 ) ;
if ( V_10 < 0 )
return V_10 ;
return sprintf ( V_50 , L_8 , V_14 ) ;
}
static T_4 F_35 ( struct V_1 * V_2 ,
struct V_48 * V_49 , char * V_50 )
{
struct V_3 * V_3 ;
int V_10 ;
T_1 V_14 ;
V_3 = F_2 ( V_2 ) ;
V_10 = F_9 ( V_3 , V_55 ,
V_56 , & V_14 ) ;
if ( V_10 < 0 )
return V_10 ;
return sprintf ( V_50 , L_9 ,
( V_14 & V_57 ) ? 1 : 0 ) ;
}
static T_4 F_36 ( struct V_1 * V_2 ,
struct V_48 * V_49 , const char * V_50 , T_5 V_58 )
{
struct V_3 * V_3 ;
int V_10 = V_58 ;
int V_59 ;
T_1 V_17 ;
V_3 = F_2 ( V_2 ) ;
if ( V_58 > 0 ) {
switch ( V_50 [ 0 ] ) {
case '0' :
V_17 = 0 ;
break;
case '1' :
V_17 = V_57 ;
break;
default:
goto exit;
}
V_59 = F_11 ( V_3 ,
V_55 , V_56 ,
V_57 , V_17 ) ;
if ( V_59 )
F_37 ( V_3 -> V_2 ,
L_10 ,
V_50 [ 0 ] , V_59 ) ;
}
exit:
return V_10 ;
}
int T_6 F_38 ( struct V_3 * V_3 , enum V_60 V_61 )
{
struct V_62 * V_63 = F_39 ( V_3 -> V_2 ) ;
int V_10 ;
int V_22 ;
T_1 V_14 ;
if ( V_63 )
V_3 -> V_33 = V_63 -> V_33 ;
F_40 ( & V_3 -> V_12 ) ;
F_40 ( & V_3 -> V_21 ) ;
if ( V_61 != V_64 )
V_3 -> V_61 = V_61 ;
else {
V_10 = F_9 ( V_3 , V_65 ,
V_66 , & V_14 ) ;
if ( V_10 < 0 )
return V_10 ;
V_3 -> V_61 = V_14 ;
}
V_10 = F_9 ( V_3 , V_65 ,
V_67 , & V_14 ) ;
if ( V_10 < 0 )
return V_10 ;
V_3 -> V_6 = V_14 ;
F_37 ( V_3 -> V_2 , L_11 ,
V_68 [ V_3 -> V_61 ] ,
V_3 -> V_6 >> 4 ,
V_3 -> V_6 & 0x0F ) ;
if ( F_23 ( V_3 ) || F_24 ( V_3 ) ) {
V_3 -> V_23 = V_69 ;
V_3 -> V_28 = V_70 ;
} else {
V_3 -> V_23 = V_71 ;
V_3 -> V_28 = V_72 ;
}
V_3 -> V_27 = F_41 ( V_3 -> V_23 , V_73 ) ;
if ( ! V_3 -> V_27 )
return - V_74 ;
V_3 -> V_25 = F_41 ( V_3 -> V_23 , V_73 ) ;
if ( ! V_3 -> V_25 ) {
V_10 = - V_74 ;
goto V_75;
}
V_10 = F_9 ( V_3 , V_51 ,
V_52 , & V_14 ) ;
if ( V_10 < 0 )
return V_10 ;
F_37 ( V_3 -> V_2 , L_12 , V_14 ) ;
if ( V_63 && V_63 -> V_76 )
V_63 -> V_76 ( V_3 ) ;
for ( V_22 = 0 ; V_22 < V_3 -> V_23 ; V_22 ++ ) {
if ( V_3 -> V_28 [ V_22 ] == 11 &&
F_16 ( V_3 ) )
continue;
F_9 ( V_3 , V_30 ,
V_37 + V_3 -> V_28 [ V_22 ] ,
& V_14 ) ;
F_3 ( V_3 , V_30 ,
V_29 + V_3 -> V_28 [ V_22 ] , 0xff ) ;
}
V_10 = F_42 ( V_3 -> V_2 , & V_77 ) ;
if ( V_10 )
goto V_78;
for ( V_22 = 0 ; V_22 < V_3 -> V_23 ; V_22 ++ )
V_3 -> V_27 [ V_22 ] = V_3 -> V_25 [ V_22 ] = 0xff ;
if ( V_3 -> V_33 ) {
V_10 = F_22 ( V_3 ) ;
if ( V_10 )
goto V_78;
V_10 = F_43 ( V_3 -> V_32 , NULL , F_19 ,
V_79 | V_80 ,
L_13 , V_3 ) ;
if ( V_10 )
goto V_81;
}
V_10 = F_44 ( V_3 -> V_2 , 0 , V_82 ,
F_45 ( V_82 ) , NULL ,
V_3 -> V_33 ) ;
if ( V_10 )
goto V_83;
if ( F_23 ( V_3 ) )
V_10 = F_44 ( V_3 -> V_2 , 0 , V_84 ,
F_45 ( V_84 ) , NULL ,
V_3 -> V_33 ) ;
else
V_10 = F_44 ( V_3 -> V_2 , 0 , V_85 ,
F_45 ( V_84 ) , NULL ,
V_3 -> V_33 ) ;
if ( V_10 )
goto V_83;
if ( F_23 ( V_3 ) )
V_10 = F_46 ( & V_3 -> V_2 -> V_86 ,
& V_87 ) ;
else
V_10 = F_46 ( & V_3 -> V_2 -> V_86 ,
& V_88 ) ;
if ( V_10 )
F_6 ( V_3 -> V_2 , L_14 ) ;
else
return V_10 ;
V_83:
if ( V_3 -> V_33 )
F_47 ( V_3 -> V_32 , V_3 ) ;
V_81:
if ( V_3 -> V_33 )
F_31 ( V_3 ) ;
V_78:
F_48 ( V_3 -> V_25 ) ;
V_75:
F_48 ( V_3 -> V_27 ) ;
return V_10 ;
}
int T_7 F_49 ( struct V_3 * V_3 )
{
if ( F_23 ( V_3 ) )
F_50 ( & V_3 -> V_2 -> V_86 , & V_87 ) ;
else
F_50 ( & V_3 -> V_2 -> V_86 , & V_88 ) ;
F_51 ( V_3 -> V_2 ) ;
if ( V_3 -> V_33 ) {
F_47 ( V_3 -> V_32 , V_3 ) ;
F_31 ( V_3 ) ;
}
F_48 ( V_3 -> V_25 ) ;
F_48 ( V_3 -> V_27 ) ;
return 0 ;
}
