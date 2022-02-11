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
F_4 ( L_1 ,
1900 + V_3 -> V_18 ) ;
return - V_22 ;
}
return 0 ;
}
static int F_5 ( struct V_23 * V_24 ,
enum V_25 V_26 )
{
int V_27 ;
unsigned int V_1 ;
if ( V_26 == V_28 )
V_1 = 1 << V_29 ;
else
V_1 = 1 << V_30 ;
V_27 = F_6 ( V_24 -> V_31 -> V_32 ,
V_33 , V_1 , V_1 ) ;
if ( V_27 < 0 )
F_7 ( V_24 -> V_34 , L_2 ,
V_35 , V_27 , V_1 ) ;
else {
F_8 ( V_36 ) ;
}
return V_27 ;
}
static int F_9 ( struct V_37 * V_34 , struct V_2 * V_3 )
{
struct V_23 * V_24 = F_10 ( V_34 ) ;
T_1 V_1 [ V_38 ] ;
int V_27 ;
F_11 ( & V_24 -> V_39 ) ;
V_27 = F_5 ( V_24 , V_40 ) ;
if ( V_27 < 0 )
goto V_41;
V_27 = F_12 ( V_24 -> V_31 -> V_32 ,
V_42 , V_1 , V_38 ) ;
if ( V_27 < 0 ) {
F_7 ( V_24 -> V_34 , L_3 , V_35 , V_27 ) ;
goto V_41;
}
F_1 ( V_1 , V_3 , V_24 -> V_4 ) ;
V_27 = F_13 ( V_3 ) ;
V_41:
F_14 ( & V_24 -> V_39 ) ;
return V_27 ;
}
static int F_15 ( struct V_37 * V_34 , struct V_2 * V_3 )
{
struct V_23 * V_24 = F_10 ( V_34 ) ;
T_1 V_1 [ V_38 ] ;
int V_27 ;
V_27 = F_3 ( V_3 , V_1 ) ;
if ( V_27 < 0 )
return V_27 ;
F_11 ( & V_24 -> V_39 ) ;
V_27 = F_16 ( V_24 -> V_31 -> V_32 ,
V_42 , V_1 , V_38 ) ;
if ( V_27 < 0 ) {
F_7 ( V_24 -> V_34 , L_4 , V_35 ,
V_27 ) ;
goto V_41;
}
V_27 = F_5 ( V_24 , V_28 ) ;
V_41:
F_14 ( & V_24 -> V_39 ) ;
return V_27 ;
}
static int F_17 ( struct V_37 * V_34 , struct V_43 * V_44 )
{
struct V_23 * V_24 = F_10 ( V_34 ) ;
T_1 V_1 [ V_38 ] ;
unsigned int V_45 ;
int V_46 , V_27 ;
F_11 ( & V_24 -> V_39 ) ;
V_27 = F_5 ( V_24 , V_40 ) ;
if ( V_27 < 0 )
goto V_41;
V_27 = F_12 ( V_24 -> V_31 -> V_32 ,
V_47 , V_1 , V_38 ) ;
if ( V_27 < 0 ) {
F_7 ( V_24 -> V_34 , L_5 ,
V_35 , __LINE__ , V_27 ) ;
goto V_41;
}
F_1 ( V_1 , & V_44 -> time , V_24 -> V_4 ) ;
V_44 -> V_48 = 0 ;
for ( V_46 = 0 ; V_46 < V_38 ; V_46 ++ ) {
if ( V_1 [ V_46 ] & V_49 ) {
V_44 -> V_48 = 1 ;
break;
}
}
V_44 -> V_50 = 0 ;
V_27 = F_18 ( V_24 -> V_31 -> V_51 , V_52 , & V_45 ) ;
if ( V_27 < 0 ) {
F_7 ( V_24 -> V_34 , L_6 ,
V_35 , __LINE__ , V_27 ) ;
goto V_41;
}
if ( V_45 & ( 1 << 4 ) )
V_44 -> V_50 = 1 ;
V_41:
F_14 ( & V_24 -> V_39 ) ;
return 0 ;
}
static int F_19 ( struct V_23 * V_24 )
{
T_1 V_1 [ V_38 ] ;
int V_27 , V_46 ;
struct V_2 V_3 ;
if ( ! F_20 ( & V_24 -> V_39 ) )
F_21 ( V_24 -> V_34 , L_7 , V_35 ) ;
V_27 = F_5 ( V_24 , V_40 ) ;
if ( V_27 < 0 )
goto V_41;
V_27 = F_12 ( V_24 -> V_31 -> V_32 ,
V_47 , V_1 , V_38 ) ;
if ( V_27 < 0 ) {
F_7 ( V_24 -> V_34 , L_8 ,
V_35 , V_27 ) ;
goto V_41;
}
F_1 ( V_1 , & V_3 , V_24 -> V_4 ) ;
for ( V_46 = 0 ; V_46 < V_38 ; V_46 ++ )
V_1 [ V_46 ] &= ~ V_49 ;
V_27 = F_16 ( V_24 -> V_31 -> V_32 ,
V_47 , V_1 , V_38 ) ;
if ( V_27 < 0 ) {
F_7 ( V_24 -> V_34 , L_9 ,
V_35 , V_27 ) ;
goto V_41;
}
V_27 = F_5 ( V_24 , V_28 ) ;
V_41:
return V_27 ;
}
static int F_22 ( struct V_23 * V_24 )
{
T_1 V_1 [ V_38 ] ;
int V_27 ;
struct V_2 V_3 ;
if ( ! F_20 ( & V_24 -> V_39 ) )
F_21 ( V_24 -> V_34 , L_7 , V_35 ) ;
V_27 = F_5 ( V_24 , V_40 ) ;
if ( V_27 < 0 )
goto V_41;
V_27 = F_12 ( V_24 -> V_31 -> V_32 ,
V_47 , V_1 , V_38 ) ;
if ( V_27 < 0 ) {
F_7 ( V_24 -> V_34 , L_8 ,
V_35 , V_27 ) ;
goto V_41;
}
F_1 ( V_1 , & V_3 , V_24 -> V_4 ) ;
V_1 [ V_6 ] |= ( 1 << V_53 ) ;
V_1 [ V_8 ] |= ( 1 << V_53 ) ;
V_1 [ V_10 ] |= ( 1 << V_53 ) ;
V_1 [ V_13 ] &= ~ V_49 ;
if ( V_1 [ V_17 ] & 0xf )
V_1 [ V_17 ] |= ( 1 << V_53 ) ;
if ( V_1 [ V_19 ] & 0x7f )
V_1 [ V_19 ] |= ( 1 << V_53 ) ;
if ( V_1 [ V_15 ] & 0x1f )
V_1 [ V_15 ] |= ( 1 << V_53 ) ;
V_27 = F_16 ( V_24 -> V_31 -> V_32 ,
V_47 , V_1 , V_38 ) ;
if ( V_27 < 0 ) {
F_7 ( V_24 -> V_34 , L_9 ,
V_35 , V_27 ) ;
goto V_41;
}
V_27 = F_5 ( V_24 , V_28 ) ;
V_41:
return V_27 ;
}
static int F_23 ( struct V_37 * V_34 , struct V_43 * V_44 )
{
struct V_23 * V_24 = F_10 ( V_34 ) ;
T_1 V_1 [ V_38 ] ;
int V_27 ;
V_27 = F_3 ( & V_44 -> time , V_1 ) ;
if ( V_27 < 0 )
return V_27 ;
F_11 ( & V_24 -> V_39 ) ;
V_27 = F_19 ( V_24 ) ;
if ( V_27 < 0 )
goto V_41;
V_27 = F_16 ( V_24 -> V_31 -> V_32 ,
V_47 , V_1 , V_38 ) ;
if ( V_27 < 0 ) {
F_7 ( V_24 -> V_34 , L_9 ,
V_35 , V_27 ) ;
goto V_41;
}
V_27 = F_5 ( V_24 , V_28 ) ;
if ( V_27 < 0 )
goto V_41;
if ( V_44 -> V_48 )
V_27 = F_22 ( V_24 ) ;
V_41:
F_14 ( & V_24 -> V_39 ) ;
return V_27 ;
}
static int F_24 ( struct V_37 * V_34 ,
unsigned int V_48 )
{
struct V_23 * V_24 = F_10 ( V_34 ) ;
int V_27 ;
F_11 ( & V_24 -> V_39 ) ;
if ( V_48 )
V_27 = F_22 ( V_24 ) ;
else
V_27 = F_19 ( V_24 ) ;
F_14 ( & V_24 -> V_39 ) ;
return V_27 ;
}
static T_2 F_25 ( int V_54 , void * V_1 )
{
struct V_23 * V_24 = V_1 ;
F_26 ( V_24 -> V_34 , L_10 , V_35 , V_54 ) ;
F_27 ( V_24 -> V_55 , 1 , V_56 | V_57 ) ;
return V_58 ;
}
static int F_28 ( struct V_23 * V_24 )
{
T_1 V_1 [ 2 ] ;
int V_27 ;
V_1 [ 0 ] = ( 1 << V_59 ) | ( 1 << V_60 ) ;
V_1 [ 1 ] = ( 0 << V_59 ) | ( 1 << V_60 ) ;
V_24 -> V_4 = 1 ;
V_27 = F_16 ( V_24 -> V_31 -> V_32 , V_61 , V_1 , 2 ) ;
if ( V_27 < 0 ) {
F_7 ( V_24 -> V_34 , L_11 ,
V_35 , V_27 ) ;
return V_27 ;
}
V_27 = F_5 ( V_24 , V_28 ) ;
return V_27 ;
}
static int F_29 ( struct V_62 * V_63 )
{
struct V_64 * V_31 = F_10 ( V_63 -> V_34 . V_65 ) ;
struct V_23 * V_24 ;
int V_27 ;
F_26 ( & V_63 -> V_34 , L_12 , V_35 ) ;
V_24 = F_30 ( & V_63 -> V_34 , sizeof( struct V_23 ) ,
V_66 ) ;
if ( ! V_24 )
return - V_67 ;
F_31 ( & V_24 -> V_39 ) ;
V_24 -> V_34 = & V_63 -> V_34 ;
V_24 -> V_31 = V_31 ;
V_24 -> V_68 = V_31 -> V_68 ;
F_32 ( V_63 , V_24 ) ;
V_27 = F_28 ( V_24 ) ;
if ( V_27 < 0 ) {
F_7 ( & V_63 -> V_34 , L_13 , V_27 ) ;
goto V_69;
}
F_33 ( & V_63 -> V_34 , 1 ) ;
V_24 -> V_55 = F_34 ( & V_63 -> V_34 , L_14 ,
& V_70 , V_71 ) ;
if ( F_35 ( V_24 -> V_55 ) ) {
V_27 = F_36 ( V_24 -> V_55 ) ;
F_7 ( & V_63 -> V_34 , L_15 , V_27 ) ;
if ( V_27 == 0 )
V_27 = - V_22 ;
goto V_69;
}
if ( ! V_31 -> V_72 ) {
V_27 = - V_22 ;
F_7 ( & V_63 -> V_34 , L_16 , V_35 ) ;
goto V_69;
}
V_24 -> V_73 = F_37 ( V_31 -> V_72 ,
V_74 ) ;
if ( ! V_24 -> V_73 ) {
V_27 = - V_75 ;
goto V_69;
}
V_27 = F_38 ( & V_63 -> V_34 , V_24 -> V_73 , NULL ,
F_25 , 0 , L_17 , V_24 ) ;
if ( V_27 < 0 )
F_7 ( & V_63 -> V_34 , L_18 ,
V_24 -> V_73 , V_27 ) ;
V_69:
return V_27 ;
}
static int F_39 ( struct V_37 * V_34 )
{
if ( F_40 ( V_34 ) ) {
struct V_23 * V_24 = F_10 ( V_34 ) ;
return F_41 ( V_24 -> V_73 ) ;
}
return 0 ;
}
static int F_42 ( struct V_37 * V_34 )
{
if ( F_40 ( V_34 ) ) {
struct V_23 * V_24 = F_10 ( V_34 ) ;
return F_43 ( V_24 -> V_73 ) ;
}
return 0 ;
}
