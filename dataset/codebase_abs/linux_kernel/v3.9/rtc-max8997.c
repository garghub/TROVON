static void F_1 ( T_1 * V_1 , struct V_2 * V_3 ,
int V_4 )
{
V_3 -> V_5 = V_1 [ V_6 ] & 0x7f ;
V_3 -> V_7 = V_1 [ V_8 ] & 0x7f ;
if ( V_4 )
V_3 -> V_9 = V_1 [ V_10 ] & 0x1f ;
else {
V_3 -> V_9 = V_1 [ V_10 ] & 0x0f ;
if ( V_1 [ V_10 ] & V_11 )
V_3 -> V_9 += 12 ;
}
V_3 -> V_12 = F_2 ( V_1 [ V_13 ] & 0x7f ) - 1 ;
V_3 -> V_14 = V_1 [ V_15 ] & 0x1f ;
V_3 -> V_16 = ( V_1 [ V_17 ] & 0x0f ) - 1 ;
V_3 -> V_18 = ( V_1 [ V_19 ] & 0x7f ) + 100 ;
V_3 -> V_20 = 0 ;
V_3 -> V_21 = 0 ;
}
static int F_3 ( struct V_2 * V_3 , T_1 * V_1 )
{
V_1 [ V_6 ] = V_3 -> V_5 ;
V_1 [ V_8 ] = V_3 -> V_7 ;
V_1 [ V_10 ] = V_3 -> V_9 ;
V_1 [ V_13 ] = 1 << V_3 -> V_12 ;
V_1 [ V_15 ] = V_3 -> V_14 ;
V_1 [ V_17 ] = V_3 -> V_16 + 1 ;
V_1 [ V_19 ] = V_3 -> V_18 > 100 ? ( V_3 -> V_18 - 100 ) : 0 ;
if ( V_3 -> V_18 < 100 ) {
F_4 ( L_1
L_2 , V_22 , 1900 + V_3 -> V_18 ) ;
return - V_23 ;
}
return 0 ;
}
static inline int F_5 ( struct V_24 * V_25 )
{
int V_26 ;
V_26 = F_6 ( V_25 -> V_27 , V_28 ,
V_29 ) ;
if ( V_26 < 0 )
F_7 ( V_25 -> V_30 , L_3 ,
V_22 , V_26 ) ;
else {
F_8 ( 20 ) ;
}
return V_26 ;
}
static int F_9 ( struct V_31 * V_30 , struct V_2 * V_3 )
{
struct V_24 * V_25 = F_10 ( V_30 ) ;
T_1 V_1 [ V_32 ] ;
int V_26 ;
F_11 ( & V_25 -> V_33 ) ;
V_26 = F_12 ( V_25 -> V_27 , V_34 , V_32 , V_1 ) ;
F_13 ( & V_25 -> V_33 ) ;
if ( V_26 < 0 ) {
F_7 ( V_25 -> V_30 , L_4 , V_22 ,
V_26 ) ;
return V_26 ;
}
F_1 ( V_1 , V_3 , V_25 -> V_4 ) ;
return F_14 ( V_3 ) ;
}
static int F_15 ( struct V_31 * V_30 , struct V_2 * V_3 )
{
struct V_24 * V_25 = F_10 ( V_30 ) ;
T_1 V_1 [ V_32 ] ;
int V_26 ;
V_26 = F_3 ( V_3 , V_1 ) ;
if ( V_26 < 0 )
return V_26 ;
F_11 ( & V_25 -> V_33 ) ;
V_26 = F_16 ( V_25 -> V_27 , V_34 , V_32 , V_1 ) ;
if ( V_26 < 0 ) {
F_7 ( V_25 -> V_30 , L_5 , V_22 ,
V_26 ) ;
goto V_35;
}
V_26 = F_5 ( V_25 ) ;
V_35:
F_13 ( & V_25 -> V_33 ) ;
return V_26 ;
}
static int F_17 ( struct V_31 * V_30 , struct V_36 * V_37 )
{
struct V_24 * V_25 = F_10 ( V_30 ) ;
T_1 V_1 [ V_32 ] ;
T_1 V_38 ;
int V_39 , V_26 ;
F_11 ( & V_25 -> V_33 ) ;
V_26 = F_12 ( V_25 -> V_27 , V_40 , V_32 ,
V_1 ) ;
if ( V_26 < 0 ) {
F_7 ( V_25 -> V_30 , L_6 ,
V_22 , __LINE__ , V_26 ) ;
goto V_35;
}
F_1 ( V_1 , & V_37 -> time , V_25 -> V_4 ) ;
V_37 -> V_41 = 0 ;
for ( V_39 = 0 ; V_39 < V_32 ; V_39 ++ ) {
if ( V_1 [ V_39 ] & V_42 ) {
V_37 -> V_41 = 1 ;
break;
}
}
V_37 -> V_43 = 0 ;
V_26 = F_18 ( V_25 -> V_44 -> V_45 , V_46 , & V_38 ) ;
if ( V_26 < 0 ) {
F_7 ( V_25 -> V_30 , L_7 ,
V_22 , __LINE__ , V_26 ) ;
goto V_35;
}
if ( V_38 & ( 1 << 4 ) )
V_37 -> V_43 = 1 ;
V_35:
F_13 ( & V_25 -> V_33 ) ;
return 0 ;
}
static int F_19 ( struct V_24 * V_25 )
{
T_1 V_1 [ V_32 ] ;
int V_26 , V_39 ;
if ( ! F_20 ( & V_25 -> V_33 ) )
F_21 ( V_25 -> V_30 , L_8 , V_22 ) ;
V_26 = F_12 ( V_25 -> V_27 , V_40 , V_32 ,
V_1 ) ;
if ( V_26 < 0 ) {
F_7 ( V_25 -> V_30 , L_9 ,
V_22 , V_26 ) ;
goto V_35;
}
for ( V_39 = 0 ; V_39 < V_32 ; V_39 ++ )
V_1 [ V_39 ] &= ~ V_42 ;
V_26 = F_16 ( V_25 -> V_27 , V_40 , V_32 ,
V_1 ) ;
if ( V_26 < 0 ) {
F_7 ( V_25 -> V_30 , L_10 ,
V_22 , V_26 ) ;
goto V_35;
}
V_26 = F_5 ( V_25 ) ;
V_35:
return V_26 ;
}
static int F_22 ( struct V_24 * V_25 )
{
T_1 V_1 [ V_32 ] ;
int V_26 ;
if ( ! F_20 ( & V_25 -> V_33 ) )
F_21 ( V_25 -> V_30 , L_8 , V_22 ) ;
V_26 = F_12 ( V_25 -> V_27 , V_40 , V_32 ,
V_1 ) ;
if ( V_26 < 0 ) {
F_7 ( V_25 -> V_30 , L_9 ,
V_22 , V_26 ) ;
goto V_35;
}
V_1 [ V_6 ] |= ( 1 << V_47 ) ;
V_1 [ V_8 ] |= ( 1 << V_47 ) ;
V_1 [ V_10 ] |= ( 1 << V_47 ) ;
V_1 [ V_13 ] &= ~ V_42 ;
if ( V_1 [ V_17 ] & 0xf )
V_1 [ V_17 ] |= ( 1 << V_47 ) ;
if ( V_1 [ V_19 ] & 0x7f )
V_1 [ V_19 ] |= ( 1 << V_47 ) ;
if ( V_1 [ V_15 ] & 0x1f )
V_1 [ V_15 ] |= ( 1 << V_47 ) ;
V_26 = F_16 ( V_25 -> V_27 , V_40 , V_32 ,
V_1 ) ;
if ( V_26 < 0 ) {
F_7 ( V_25 -> V_30 , L_10 ,
V_22 , V_26 ) ;
goto V_35;
}
V_26 = F_5 ( V_25 ) ;
V_35:
return V_26 ;
}
static int F_23 ( struct V_31 * V_30 , struct V_36 * V_37 )
{
struct V_24 * V_25 = F_10 ( V_30 ) ;
T_1 V_1 [ V_32 ] ;
int V_26 ;
V_26 = F_3 ( & V_37 -> time , V_1 ) ;
if ( V_26 < 0 )
return V_26 ;
F_24 ( V_25 -> V_30 , L_11 , V_22 ,
V_1 [ V_19 ] + 2000 , V_1 [ V_17 ] , V_1 [ V_15 ] ,
V_1 [ V_10 ] , V_1 [ V_8 ] , V_1 [ V_6 ] ) ;
F_11 ( & V_25 -> V_33 ) ;
V_26 = F_19 ( V_25 ) ;
if ( V_26 < 0 )
goto V_35;
V_26 = F_16 ( V_25 -> V_27 , V_40 , V_32 ,
V_1 ) ;
if ( V_26 < 0 ) {
F_7 ( V_25 -> V_30 , L_10 ,
V_22 , V_26 ) ;
goto V_35;
}
V_26 = F_5 ( V_25 ) ;
if ( V_26 < 0 )
goto V_35;
if ( V_37 -> V_41 )
V_26 = F_22 ( V_25 ) ;
V_35:
F_13 ( & V_25 -> V_33 ) ;
return V_26 ;
}
static int F_25 ( struct V_31 * V_30 ,
unsigned int V_41 )
{
struct V_24 * V_25 = F_10 ( V_30 ) ;
int V_26 ;
F_11 ( & V_25 -> V_33 ) ;
if ( V_41 )
V_26 = F_22 ( V_25 ) ;
else
V_26 = F_19 ( V_25 ) ;
F_13 ( & V_25 -> V_33 ) ;
return V_26 ;
}
static T_2 F_26 ( int V_48 , void * V_1 )
{
struct V_24 * V_25 = V_1 ;
F_24 ( V_25 -> V_30 , L_12 , V_22 , V_48 ) ;
F_27 ( V_25 -> V_49 , 1 , V_50 | V_51 ) ;
return V_52 ;
}
static void F_28 ( struct V_24 * V_25 , bool V_53 )
{
int V_26 ;
T_1 V_38 , V_54 ;
if ( ! V_55 )
return;
if ( V_53 )
V_38 = ( 1 << V_56 ) | ( 3 << V_57 ) ;
else
V_38 = 0 ;
V_54 = V_58 | V_59 ;
F_24 ( V_25 -> V_30 , L_13 , V_22 ,
V_53 ? L_14 : L_15 ) ;
V_26 = F_29 ( V_25 -> V_27 , V_60 , V_38 , V_54 ) ;
if ( V_26 < 0 ) {
F_7 ( V_25 -> V_30 , L_16 ,
V_22 , V_26 ) ;
return;
}
F_5 ( V_25 ) ;
}
static void F_30 ( struct V_24 * V_25 , bool V_53 )
{
int V_26 ;
T_1 V_38 , V_54 ;
if ( ! V_61 )
return;
if ( V_53 )
V_38 = ( 1 << V_62 ) | ( 0 << V_63 ) ;
else
V_38 = 0 ;
V_54 = V_64 | V_65 ;
F_24 ( V_25 -> V_30 , L_17 , V_22 ,
V_53 ? L_14 : L_15 ) ;
V_26 = F_29 ( V_25 -> V_27 , V_60 , V_38 , V_54 ) ;
if ( V_26 < 0 ) {
F_7 ( V_25 -> V_30 , L_18 ,
V_22 , V_26 ) ;
return;
}
F_5 ( V_25 ) ;
V_38 = 0 ;
F_18 ( V_25 -> V_27 , V_60 , & V_38 ) ;
F_31 ( L_19 , V_22 , V_38 ) ;
}
static int F_32 ( struct V_24 * V_25 )
{
T_1 V_1 [ 2 ] ;
int V_26 ;
V_1 [ 0 ] = ( 1 << V_66 ) | ( 1 << V_67 ) ;
V_1 [ 1 ] = ( 0 << V_66 ) | ( 1 << V_67 ) ;
V_25 -> V_4 = 1 ;
V_26 = F_16 ( V_25 -> V_27 , V_68 , 2 , V_1 ) ;
if ( V_26 < 0 ) {
F_7 ( V_25 -> V_30 , L_20 ,
V_22 , V_26 ) ;
return V_26 ;
}
V_26 = F_5 ( V_25 ) ;
return V_26 ;
}
static int F_33 ( struct V_69 * V_70 )
{
struct V_71 * V_44 = F_10 ( V_70 -> V_30 . V_72 ) ;
struct V_24 * V_25 ;
int V_26 , V_73 ;
V_25 = F_34 ( & V_70 -> V_30 , sizeof( struct V_24 ) ,
V_74 ) ;
if ( ! V_25 )
return - V_75 ;
F_35 ( & V_25 -> V_33 ) ;
V_25 -> V_30 = & V_70 -> V_30 ;
V_25 -> V_44 = V_44 ;
V_25 -> V_27 = V_44 -> V_27 ;
F_36 ( V_70 , V_25 ) ;
V_26 = F_32 ( V_25 ) ;
if ( V_26 < 0 ) {
F_7 ( & V_70 -> V_30 , L_21 , V_26 ) ;
return V_26 ;
}
F_28 ( V_25 , true ) ;
F_30 ( V_25 , true ) ;
F_37 ( & V_70 -> V_30 , 1 ) ;
V_25 -> V_49 = F_38 ( L_22 , & V_70 -> V_30 ,
& V_76 , V_77 ) ;
if ( F_39 ( V_25 -> V_49 ) ) {
V_26 = F_40 ( V_25 -> V_49 ) ;
F_7 ( & V_70 -> V_30 , L_23 , V_26 ) ;
return V_26 ;
}
V_73 = F_41 ( V_44 -> V_78 , V_79 ) ;
if ( ! V_73 ) {
F_7 ( & V_70 -> V_30 , L_24 ) ;
goto V_80;
}
V_25 -> V_73 = V_73 ;
V_26 = F_42 ( & V_70 -> V_30 , V_73 , NULL ,
F_26 , 0 ,
L_25 , V_25 ) ;
if ( V_26 < 0 ) {
F_7 ( & V_70 -> V_30 , L_26 ,
V_25 -> V_73 , V_26 ) ;
goto V_80;
}
return V_26 ;
V_80:
F_43 ( V_25 -> V_49 ) ;
return V_26 ;
}
static int F_44 ( struct V_69 * V_70 )
{
struct V_24 * V_25 = F_45 ( V_70 ) ;
if ( V_25 )
F_43 ( V_25 -> V_49 ) ;
return 0 ;
}
static void F_46 ( struct V_69 * V_70 )
{
struct V_24 * V_25 = F_45 ( V_70 ) ;
F_28 ( V_25 , false ) ;
F_30 ( V_25 , false ) ;
}
