static inline int F_1 ( T_1 V_1 )
{
int V_2 = - 1 ;
while ( V_1 ) {
V_1 >>= 1 ;
V_2 ++ ;
}
return V_2 ;
}
static void F_2 ( T_1 * V_3 , struct V_4 * V_5 ,
int V_6 )
{
V_5 -> V_7 = V_3 [ V_8 ] & 0x7f ;
V_5 -> V_9 = V_3 [ V_10 ] & 0x7f ;
if ( V_6 )
V_5 -> V_11 = V_3 [ V_12 ] & 0x1f ;
else {
V_5 -> V_11 = V_3 [ V_12 ] & 0x0f ;
if ( V_3 [ V_12 ] & V_13 )
V_5 -> V_11 += 12 ;
}
V_5 -> V_14 = F_1 ( V_3 [ V_15 ] & 0x7f ) ;
V_5 -> V_16 = V_3 [ V_17 ] & 0x1f ;
V_5 -> V_18 = ( V_3 [ V_19 ] & 0x0f ) - 1 ;
V_5 -> V_20 = ( V_3 [ V_21 ] & 0x7f ) + 100 ;
V_5 -> V_22 = 0 ;
V_5 -> V_23 = 0 ;
}
static int F_3 ( struct V_4 * V_5 , T_1 * V_3 )
{
V_3 [ V_8 ] = V_5 -> V_7 ;
V_3 [ V_10 ] = V_5 -> V_9 ;
V_3 [ V_12 ] = V_5 -> V_11 ;
V_3 [ V_15 ] = 1 << V_5 -> V_14 ;
V_3 [ V_17 ] = V_5 -> V_16 ;
V_3 [ V_19 ] = V_5 -> V_18 + 1 ;
V_3 [ V_21 ] = V_5 -> V_20 > 100 ? ( V_5 -> V_20 - 100 ) : 0 ;
if ( V_5 -> V_20 < 100 ) {
F_4 ( L_1
L_2 , V_24 , 1900 + V_5 -> V_20 ) ;
return - V_25 ;
}
return 0 ;
}
static int F_5 ( struct V_26 * V_27 ,
enum V_28 V_29 )
{
int V_30 ;
unsigned int V_3 ;
if ( V_29 == V_31 )
V_3 = 1 << V_32 ;
else
V_3 = 1 << V_33 ;
V_30 = F_6 ( V_27 -> V_34 -> V_35 ,
V_36 , V_3 , V_3 ) ;
if ( V_30 < 0 )
F_7 ( V_27 -> V_37 , L_3 ,
V_24 , V_30 , V_3 ) ;
else {
F_8 ( V_38 ) ;
}
return V_30 ;
}
static int F_9 ( struct V_39 * V_37 , struct V_4 * V_5 )
{
struct V_26 * V_27 = F_10 ( V_37 ) ;
T_1 V_3 [ V_40 ] ;
int V_30 ;
F_11 ( & V_27 -> V_41 ) ;
V_30 = F_5 ( V_27 , V_42 ) ;
if ( V_30 < 0 )
goto V_43;
V_30 = F_12 ( V_27 -> V_34 -> V_35 ,
V_44 , V_3 , V_40 ) ;
if ( V_30 < 0 ) {
F_7 ( V_27 -> V_37 , L_4 , V_24 , V_30 ) ;
goto V_43;
}
F_2 ( V_3 , V_5 , V_27 -> V_6 ) ;
V_30 = F_13 ( V_5 ) ;
V_43:
F_14 ( & V_27 -> V_41 ) ;
return V_30 ;
}
static int F_15 ( struct V_39 * V_37 , struct V_4 * V_5 )
{
struct V_26 * V_27 = F_10 ( V_37 ) ;
T_1 V_3 [ V_40 ] ;
int V_30 ;
V_30 = F_3 ( V_5 , V_3 ) ;
if ( V_30 < 0 )
return V_30 ;
F_11 ( & V_27 -> V_41 ) ;
V_30 = F_16 ( V_27 -> V_34 -> V_35 ,
V_44 , V_3 , V_40 ) ;
if ( V_30 < 0 ) {
F_7 ( V_27 -> V_37 , L_5 , V_24 ,
V_30 ) ;
goto V_43;
}
V_30 = F_5 ( V_27 , V_31 ) ;
V_43:
F_14 ( & V_27 -> V_41 ) ;
return V_30 ;
}
static int F_17 ( struct V_39 * V_37 , struct V_45 * V_46 )
{
struct V_26 * V_27 = F_10 ( V_37 ) ;
T_1 V_3 [ V_40 ] ;
unsigned int V_47 ;
int V_48 , V_30 ;
F_11 ( & V_27 -> V_41 ) ;
V_30 = F_5 ( V_27 , V_42 ) ;
if ( V_30 < 0 )
goto V_43;
V_30 = F_12 ( V_27 -> V_34 -> V_35 ,
V_49 , V_3 , V_40 ) ;
if ( V_30 < 0 ) {
F_7 ( V_27 -> V_37 , L_6 ,
V_24 , __LINE__ , V_30 ) ;
goto V_43;
}
F_2 ( V_3 , & V_46 -> time , V_27 -> V_6 ) ;
V_46 -> V_50 = 0 ;
for ( V_48 = 0 ; V_48 < V_40 ; V_48 ++ ) {
if ( V_3 [ V_48 ] & V_51 ) {
V_46 -> V_50 = 1 ;
break;
}
}
V_46 -> V_52 = 0 ;
V_30 = F_18 ( V_27 -> V_34 -> V_53 , V_54 , & V_47 ) ;
if ( V_30 < 0 ) {
F_7 ( V_27 -> V_37 , L_7 ,
V_24 , __LINE__ , V_30 ) ;
goto V_43;
}
if ( V_47 & ( 1 << 4 ) )
V_46 -> V_52 = 1 ;
V_43:
F_14 ( & V_27 -> V_41 ) ;
return 0 ;
}
static int F_19 ( struct V_26 * V_27 )
{
T_1 V_3 [ V_40 ] ;
int V_30 , V_48 ;
struct V_4 V_5 ;
if ( ! F_20 ( & V_27 -> V_41 ) )
F_21 ( V_27 -> V_37 , L_8 , V_24 ) ;
V_30 = F_5 ( V_27 , V_42 ) ;
if ( V_30 < 0 )
goto V_43;
V_30 = F_12 ( V_27 -> V_34 -> V_35 ,
V_49 , V_3 , V_40 ) ;
if ( V_30 < 0 ) {
F_7 ( V_27 -> V_37 , L_9 ,
V_24 , V_30 ) ;
goto V_43;
}
F_2 ( V_3 , & V_5 , V_27 -> V_6 ) ;
for ( V_48 = 0 ; V_48 < V_40 ; V_48 ++ )
V_3 [ V_48 ] &= ~ V_51 ;
V_30 = F_16 ( V_27 -> V_34 -> V_35 ,
V_49 , V_3 , V_40 ) ;
if ( V_30 < 0 ) {
F_7 ( V_27 -> V_37 , L_10 ,
V_24 , V_30 ) ;
goto V_43;
}
V_30 = F_5 ( V_27 , V_31 ) ;
V_43:
return V_30 ;
}
static int F_22 ( struct V_26 * V_27 )
{
T_1 V_3 [ V_40 ] ;
int V_30 ;
struct V_4 V_5 ;
if ( ! F_20 ( & V_27 -> V_41 ) )
F_21 ( V_27 -> V_37 , L_8 , V_24 ) ;
V_30 = F_5 ( V_27 , V_42 ) ;
if ( V_30 < 0 )
goto V_43;
V_30 = F_12 ( V_27 -> V_34 -> V_35 ,
V_49 , V_3 , V_40 ) ;
if ( V_30 < 0 ) {
F_7 ( V_27 -> V_37 , L_9 ,
V_24 , V_30 ) ;
goto V_43;
}
F_2 ( V_3 , & V_5 , V_27 -> V_6 ) ;
V_3 [ V_8 ] |= ( 1 << V_55 ) ;
V_3 [ V_10 ] |= ( 1 << V_55 ) ;
V_3 [ V_12 ] |= ( 1 << V_55 ) ;
V_3 [ V_15 ] &= ~ V_51 ;
if ( V_3 [ V_19 ] & 0xf )
V_3 [ V_19 ] |= ( 1 << V_55 ) ;
if ( V_3 [ V_21 ] & 0x7f )
V_3 [ V_21 ] |= ( 1 << V_55 ) ;
if ( V_3 [ V_17 ] & 0x1f )
V_3 [ V_17 ] |= ( 1 << V_55 ) ;
V_30 = F_16 ( V_27 -> V_34 -> V_35 ,
V_49 , V_3 , V_40 ) ;
if ( V_30 < 0 ) {
F_7 ( V_27 -> V_37 , L_10 ,
V_24 , V_30 ) ;
goto V_43;
}
V_30 = F_5 ( V_27 , V_31 ) ;
V_43:
return V_30 ;
}
static int F_23 ( struct V_39 * V_37 , struct V_45 * V_46 )
{
struct V_26 * V_27 = F_10 ( V_37 ) ;
T_1 V_3 [ V_40 ] ;
int V_30 ;
V_30 = F_3 ( & V_46 -> time , V_3 ) ;
if ( V_30 < 0 )
return V_30 ;
F_11 ( & V_27 -> V_41 ) ;
V_30 = F_19 ( V_27 ) ;
if ( V_30 < 0 )
goto V_43;
V_30 = F_16 ( V_27 -> V_34 -> V_35 ,
V_49 , V_3 , V_40 ) ;
if ( V_30 < 0 ) {
F_7 ( V_27 -> V_37 , L_10 ,
V_24 , V_30 ) ;
goto V_43;
}
V_30 = F_5 ( V_27 , V_31 ) ;
if ( V_30 < 0 )
goto V_43;
if ( V_46 -> V_50 )
V_30 = F_22 ( V_27 ) ;
V_43:
F_14 ( & V_27 -> V_41 ) ;
return V_30 ;
}
static int F_24 ( struct V_39 * V_37 ,
unsigned int V_50 )
{
struct V_26 * V_27 = F_10 ( V_37 ) ;
int V_30 ;
F_11 ( & V_27 -> V_41 ) ;
if ( V_50 )
V_30 = F_22 ( V_27 ) ;
else
V_30 = F_19 ( V_27 ) ;
F_14 ( & V_27 -> V_41 ) ;
return V_30 ;
}
static T_2 F_25 ( int V_56 , void * V_3 )
{
struct V_26 * V_27 = V_3 ;
F_26 ( V_27 -> V_37 , L_11 , V_24 , V_56 ) ;
F_27 ( V_27 -> V_57 , 1 , V_58 | V_59 ) ;
return V_60 ;
}
static void F_28 ( struct V_26 * V_27 , bool V_61 )
{
int V_30 ;
unsigned int V_47 , V_62 ;
if ( V_61 )
V_47 = ( 1 << V_63 ) | ( 3 << V_64 ) ;
else
V_47 = 0 ;
V_62 = V_65 | V_66 ;
F_26 ( V_27 -> V_37 , L_12 , V_24 ,
V_61 ? L_13 : L_14 ) ;
V_30 = F_6 ( V_27 -> V_34 -> V_35 ,
V_67 , V_62 , V_47 ) ;
if ( V_30 < 0 ) {
F_7 ( V_27 -> V_37 , L_15 ,
V_24 , V_30 ) ;
return;
}
F_5 ( V_27 , V_31 ) ;
}
static void F_29 ( struct V_26 * V_27 , bool V_61 )
{
int V_30 ;
unsigned int V_47 , V_62 ;
if ( V_61 )
V_47 = ( 1 << V_68 ) | ( 0 << V_69 ) ;
else
V_47 = 0 ;
V_62 = V_70 | V_71 ;
F_26 ( V_27 -> V_37 , L_16 , V_24 ,
V_61 ? L_13 : L_14 ) ;
V_30 = F_6 ( V_27 -> V_34 -> V_35 ,
V_67 , V_62 , V_47 ) ;
if ( V_30 < 0 ) {
F_7 ( V_27 -> V_37 , L_17 ,
V_24 , V_30 ) ;
return;
}
F_5 ( V_27 , V_31 ) ;
V_47 = 0 ;
F_18 ( V_27 -> V_34 -> V_35 , V_67 , & V_47 ) ;
F_26 ( V_27 -> V_37 , L_18 , V_24 , V_47 ) ;
}
static int F_30 ( struct V_26 * V_27 )
{
T_1 V_3 [ 2 ] ;
int V_30 ;
V_3 [ 0 ] = ( 1 << V_72 ) | ( 1 << V_73 ) ;
V_3 [ 1 ] = ( 0 << V_72 ) | ( 1 << V_73 ) ;
V_27 -> V_6 = 1 ;
V_30 = F_16 ( V_27 -> V_34 -> V_35 , V_74 , V_3 , 2 ) ;
if ( V_30 < 0 ) {
F_7 ( V_27 -> V_37 , L_19 ,
V_24 , V_30 ) ;
return V_30 ;
}
V_30 = F_5 ( V_27 , V_31 ) ;
return V_30 ;
}
static int F_31 ( struct V_75 * V_76 )
{
struct V_77 * V_34 = F_10 ( V_76 -> V_37 . V_78 ) ;
struct V_26 * V_27 ;
int V_30 ;
F_26 ( & V_76 -> V_37 , L_20 , V_24 ) ;
V_27 = F_32 ( & V_76 -> V_37 , sizeof( struct V_26 ) ,
V_79 ) ;
if ( ! V_27 )
return - V_80 ;
F_33 ( & V_27 -> V_41 ) ;
V_27 -> V_37 = & V_76 -> V_37 ;
V_27 -> V_34 = V_34 ;
V_27 -> V_81 = V_34 -> V_81 ;
F_34 ( V_76 , V_27 ) ;
V_30 = F_30 ( V_27 ) ;
if ( V_30 < 0 ) {
F_7 ( & V_76 -> V_37 , L_21 , V_30 ) ;
goto V_82;
}
#ifdef F_35
F_28 ( V_27 , true ) ;
F_29 ( V_27 , true ) ;
#endif
F_36 ( & V_76 -> V_37 , 1 ) ;
V_27 -> V_57 = F_37 ( & V_76 -> V_37 , L_22 ,
& V_83 , V_84 ) ;
if ( F_38 ( V_27 -> V_57 ) ) {
F_26 ( & V_76 -> V_37 , L_23 , V_24 ) ;
V_30 = F_39 ( V_27 -> V_57 ) ;
F_7 ( & V_76 -> V_37 , L_24 , V_30 ) ;
if ( V_30 == 0 )
V_30 = - V_25 ;
goto V_82;
}
V_27 -> V_85 = F_40 ( V_34 -> V_86 ,
V_87 ) ;
if ( ! V_27 -> V_85 ) {
V_30 = - V_88 ;
goto V_82;
}
V_30 = F_41 ( & V_76 -> V_37 , V_27 -> V_85 , NULL ,
F_25 , 0 , L_25 , V_27 ) ;
if ( V_30 < 0 )
F_7 ( & V_76 -> V_37 , L_26 ,
V_27 -> V_85 , V_30 ) ;
V_82:
return V_30 ;
}
static void F_42 ( struct V_75 * V_76 )
{
#ifdef F_35
struct V_26 * V_27 = F_43 ( V_76 ) ;
int V_48 ;
T_1 V_47 = 0 ;
for ( V_48 = 0 ; V_48 < 3 ; V_48 ++ ) {
F_28 ( V_27 , false ) ;
F_18 ( V_27 -> V_34 -> V_35 , V_67 , & V_47 ) ;
F_26 ( V_27 -> V_37 , L_27 , V_24 ,
V_47 ) ;
if ( V_47 & V_65 ) {
F_44 ( V_27 -> V_37 , L_28 ,
V_24 ) ;
} else {
F_26 ( V_27 -> V_37 , L_29 ,
V_24 ) ;
break;
}
}
F_29 ( V_27 , false ) ;
#endif
}
