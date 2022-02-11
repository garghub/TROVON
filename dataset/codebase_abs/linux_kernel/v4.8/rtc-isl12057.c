static void F_1 ( struct V_1 * V_2 , T_1 * V_3 )
{
V_2 -> V_4 = F_2 ( V_3 [ V_5 ] ) ;
V_2 -> V_6 = F_2 ( V_3 [ V_7 ] ) ;
if ( V_3 [ V_8 ] & V_9 ) {
V_2 -> V_10 = F_2 ( V_3 [ V_8 ] & 0x1f ) ;
if ( V_3 [ V_8 ] & V_11 )
V_2 -> V_10 += 12 ;
} else {
V_2 -> V_10 = F_2 ( V_3 [ V_8 ] & 0x3f ) ;
}
V_2 -> V_12 = F_2 ( V_3 [ V_13 ] ) ;
V_2 -> V_14 = F_2 ( V_3 [ V_15 ] ) - 1 ;
V_2 -> V_16 = F_2 ( V_3 [ V_17 ] & 0x1f ) - 1 ;
V_2 -> V_18 = F_2 ( V_3 [ V_19 ] ) + 100 ;
if ( V_3 [ V_17 ] & V_20 )
V_2 -> V_18 += 100 ;
}
static int F_3 ( T_1 * V_3 , struct V_1 * V_2 )
{
T_1 V_21 ;
if ( V_2 -> V_18 < 100 || V_2 -> V_18 > 299 )
return - V_22 ;
V_21 = ( V_2 -> V_18 > 199 ) ? V_20 : 0 ;
V_3 [ V_5 ] = F_4 ( V_2 -> V_4 ) ;
V_3 [ V_7 ] = F_4 ( V_2 -> V_6 ) ;
V_3 [ V_8 ] = F_4 ( V_2 -> V_10 ) ;
V_3 [ V_13 ] = F_4 ( V_2 -> V_12 ) ;
V_3 [ V_17 ] = F_4 ( V_2 -> V_16 + 1 ) | V_21 ;
V_3 [ V_19 ] = F_4 ( V_2 -> V_18 % 100 ) ;
V_3 [ V_15 ] = F_4 ( V_2 -> V_14 + 1 ) ;
return 0 ;
}
static int F_5 ( struct V_23 * V_23 )
{
T_1 V_3 [ V_24 ] ;
static const T_1 V_25 [ V_24 ] = { 0x80 , 0x80 , 0x80 , 0xf8 ,
0xc0 , 0x60 , 0x00 , 0x00 ,
0x00 , 0x00 , 0x00 , 0x00 ,
0x00 , 0x00 , 0x60 , 0x7c } ;
int V_26 , V_27 ;
V_26 = F_6 ( V_23 , 0 , V_3 , V_24 ) ;
if ( V_26 )
return V_26 ;
for ( V_27 = 0 ; V_27 < V_24 ; ++ V_27 ) {
if ( V_3 [ V_27 ] & V_25 [ V_27 ] )
return - V_28 ;
}
return 0 ;
}
static int F_7 ( struct V_29 * V_30 )
{
struct V_31 * V_32 = F_8 ( V_30 ) ;
int V_26 ;
V_26 = F_9 ( V_32 -> V_23 , V_33 ,
V_34 , 0 ) ;
if ( V_26 )
F_10 ( V_30 , L_1 , V_35 , V_26 ) ;
return V_26 ;
}
static int F_11 ( struct V_29 * V_30 , int V_36 )
{
struct V_31 * V_32 = F_8 ( V_30 ) ;
int V_26 ;
V_26 = F_9 ( V_32 -> V_23 , V_37 ,
V_38 ,
V_36 ? V_38 : 0 ) ;
if ( V_26 )
F_10 ( V_30 , L_2 ,
V_35 , V_26 ) ;
return V_26 ;
}
static int F_12 ( struct V_29 * V_30 , struct V_1 * V_2 )
{
struct V_31 * V_32 = F_8 ( V_30 ) ;
T_1 V_3 [ V_39 ] ;
unsigned int V_40 ;
int V_26 ;
V_26 = F_13 ( V_32 -> V_23 , V_33 , & V_40 ) ;
if ( V_26 ) {
F_10 ( V_30 , L_3 ,
V_35 , V_26 ) ;
goto V_41;
} else {
if ( V_40 & V_42 ) {
V_26 = - V_43 ;
goto V_41;
}
}
V_26 = F_6 ( V_32 -> V_23 , V_5 , V_3 ,
V_39 ) ;
if ( V_26 )
F_10 ( V_30 , L_4 ,
V_35 , V_26 ) ;
V_41:
if ( V_26 )
return V_26 ;
F_1 ( V_2 , V_3 ) ;
return F_14 ( V_2 ) ;
}
static int F_15 ( struct V_29 * V_30 , int V_36 )
{
struct V_31 * V_32 = F_8 ( V_30 ) ;
int V_26 ;
F_16 ( & V_32 -> V_44 ) ;
V_26 = F_11 ( V_30 , V_36 ) ;
F_17 ( & V_32 -> V_44 ) ;
return V_26 ;
}
static int F_18 ( struct V_29 * V_30 , struct V_45 * V_46 )
{
struct V_31 * V_32 = F_8 ( V_30 ) ;
struct V_1 * V_47 = & V_46 -> time ;
T_1 V_3 [ V_48 ] ;
unsigned int V_49 ;
int V_26 ;
F_16 ( & V_32 -> V_44 ) ;
V_26 = F_6 ( V_32 -> V_23 , V_50 , V_3 ,
V_48 ) ;
if ( V_26 ) {
F_10 ( V_30 , L_5 ,
V_35 , V_26 ) ;
goto V_51;
}
V_47 -> V_4 = F_2 ( V_3 [ 0 ] & 0x7f ) ;
V_47 -> V_6 = F_2 ( V_3 [ 1 ] & 0x7f ) ;
V_47 -> V_10 = F_2 ( V_3 [ 2 ] & 0x3f ) ;
V_47 -> V_12 = F_2 ( V_3 [ 3 ] & 0x3f ) ;
V_26 = F_13 ( V_32 -> V_23 , V_37 , & V_49 ) ;
if ( V_26 ) {
F_10 ( V_30 , L_6 ,
V_35 , V_26 ) ;
goto V_51;
}
V_46 -> V_52 = ! ! ( V_49 & V_38 ) ;
V_51:
F_17 ( & V_32 -> V_44 ) ;
return V_26 ;
}
static int F_19 ( struct V_29 * V_30 , struct V_45 * V_46 )
{
struct V_31 * V_32 = F_8 ( V_30 ) ;
struct V_1 * V_47 = & V_46 -> time ;
unsigned long V_53 , V_54 ;
T_1 V_3 [ V_48 ] ;
struct V_1 V_55 ;
int V_26 , V_36 = 1 ;
F_16 ( & V_32 -> V_44 ) ;
V_26 = F_12 ( V_30 , & V_55 ) ;
if ( V_26 )
goto V_51;
V_26 = F_20 ( & V_55 , & V_53 ) ;
if ( V_26 )
goto V_51;
V_26 = F_20 ( V_47 , & V_54 ) ;
if ( V_26 )
goto V_51;
if ( ! V_46 -> V_52 || V_54 <= V_53 ) {
V_36 = 0 ;
} else {
if ( V_55 . V_16 == 11 ) {
V_55 . V_16 = 0 ;
V_55 . V_18 += 1 ;
} else {
V_55 . V_16 += 1 ;
}
V_26 = F_20 ( & V_55 , & V_53 ) ;
if ( V_26 )
goto V_51;
if ( V_54 > V_53 ) {
F_10 ( V_30 , L_7 ,
V_35 , V_26 ) ;
V_26 = - V_22 ;
goto V_51;
}
}
V_26 = F_11 ( V_30 , 0 ) ;
if ( V_26 < 0 ) {
F_10 ( V_30 , L_8 ,
V_35 , V_26 ) ;
goto V_51;
}
V_3 [ 0 ] = F_4 ( V_47 -> V_4 ) & 0x7f ;
V_3 [ 1 ] = F_4 ( V_47 -> V_6 ) & 0x7f ;
V_3 [ 2 ] = F_4 ( V_47 -> V_10 ) & 0x3f ;
V_3 [ 3 ] = F_4 ( V_47 -> V_12 ) & 0x3f ;
V_26 = F_21 ( V_32 -> V_23 , V_50 , V_3 ,
V_48 ) ;
if ( V_26 < 0 ) {
F_10 ( V_30 , L_9 ,
V_35 , V_26 ) ;
goto V_51;
}
V_26 = F_11 ( V_30 , V_36 ) ;
V_51:
F_17 ( & V_32 -> V_44 ) ;
return V_26 ;
}
static int F_22 ( struct V_29 * V_30 , struct V_1 * V_2 )
{
struct V_31 * V_32 = F_8 ( V_30 ) ;
T_1 V_3 [ V_39 ] ;
int V_26 ;
V_26 = F_3 ( V_3 , V_2 ) ;
if ( V_26 )
return V_26 ;
F_16 ( & V_32 -> V_44 ) ;
V_26 = F_21 ( V_32 -> V_23 , V_5 , V_3 ,
V_39 ) ;
if ( V_26 ) {
F_10 ( V_30 , L_10 ,
V_35 , V_26 ) ;
goto V_41;
}
V_26 = F_9 ( V_32 -> V_23 , V_33 ,
V_42 , 0 ) ;
if ( V_26 < 0 )
F_10 ( V_30 , L_11 ,
V_35 , V_26 ) ;
V_41:
F_17 ( & V_32 -> V_44 ) ;
return V_26 ;
}
static int F_23 ( struct V_29 * V_30 , struct V_23 * V_23 )
{
int V_26 ;
V_26 = F_9 ( V_23 , V_37 ,
V_56 , 0 ) ;
if ( V_26 < 0 ) {
F_10 ( V_30 , L_12 ,
V_35 , V_26 ) ;
return V_26 ;
}
V_26 = F_9 ( V_23 , V_33 ,
V_34 , 0 ) ;
if ( V_26 < 0 ) {
F_10 ( V_30 , L_13 ,
V_35 , V_26 ) ;
return V_26 ;
}
return 0 ;
}
static bool F_24 ( struct V_29 * V_30 )
{
struct V_31 * V_32 = F_8 ( V_30 ) ;
return V_32 -> V_57 || F_25 ( V_30 -> V_58 , L_14 )
|| F_25 ( V_30 -> V_58 ,
L_15 ) ;
}
static bool F_24 ( struct V_29 * V_30 )
{
struct V_31 * V_32 = F_8 ( V_30 ) ;
return ! ! V_32 -> V_57 ;
}
static int F_26 ( struct V_29 * V_30 ,
unsigned int V_36 )
{
struct V_31 * V_59 = F_8 ( V_30 ) ;
int V_26 = - V_60 ;
if ( V_59 -> V_57 )
V_26 = F_15 ( V_30 , V_36 ) ;
return V_26 ;
}
static T_2 F_27 ( int V_57 , void * V_32 )
{
struct V_61 * V_62 = V_32 ;
struct V_31 * V_59 = F_8 ( & V_62 -> V_30 ) ;
struct V_63 * V_64 = V_59 -> V_64 ;
int V_26 , V_65 = V_66 ;
unsigned int V_40 ;
V_26 = F_13 ( V_59 -> V_23 , V_33 , & V_40 ) ;
if ( ! V_26 && ( V_40 & V_34 ) ) {
F_28 ( & V_62 -> V_30 , L_16 ) ;
F_29 ( V_64 , 1 , V_67 | V_68 ) ;
F_7 ( & V_62 -> V_30 ) ;
F_11 ( & V_62 -> V_30 , 0 ) ;
V_65 = V_69 ;
}
return V_65 ;
}
static int F_30 ( struct V_61 * V_62 ,
const struct V_70 * V_71 )
{
struct V_29 * V_30 = & V_62 -> V_30 ;
struct V_31 * V_32 ;
struct V_23 * V_23 ;
int V_26 ;
if ( ! F_31 ( V_62 -> V_72 , V_73 |
V_74 |
V_75 ) )
return - V_28 ;
V_23 = F_32 ( V_62 , & V_76 ) ;
if ( F_33 ( V_23 ) ) {
V_26 = F_34 ( V_23 ) ;
F_10 ( V_30 , L_17 ,
V_35 , V_26 ) ;
return V_26 ;
}
V_26 = F_5 ( V_23 ) ;
if ( V_26 )
return V_26 ;
V_26 = F_23 ( V_30 , V_23 ) ;
if ( V_26 )
return V_26 ;
V_32 = F_35 ( V_30 , sizeof( * V_32 ) , V_77 ) ;
if ( ! V_32 )
return - V_78 ;
F_36 ( & V_32 -> V_44 ) ;
V_32 -> V_23 = V_23 ;
F_37 ( V_30 , V_32 ) ;
if ( V_62 -> V_57 > 0 ) {
V_26 = F_38 ( V_30 , V_62 -> V_57 , NULL ,
F_27 ,
V_79 | V_80 ,
V_81 , V_62 ) ;
if ( ! V_26 )
V_32 -> V_57 = V_62 -> V_57 ;
else
F_10 ( V_30 , L_18 , V_35 ,
V_62 -> V_57 , V_26 ) ;
}
if ( F_24 ( V_30 ) )
F_39 ( V_30 , true ) ;
V_32 -> V_64 = F_40 ( V_30 , V_81 , & V_82 ,
V_83 ) ;
V_26 = F_41 ( V_32 -> V_64 ) ;
if ( V_26 ) {
F_10 ( V_30 , L_19 ,
V_35 , V_26 ) ;
goto V_84;
}
if ( ! V_32 -> V_57 )
V_32 -> V_64 -> V_85 = 1 ;
V_84:
return V_26 ;
}
static int F_42 ( struct V_61 * V_62 )
{
if ( F_24 ( & V_62 -> V_30 ) )
F_39 ( & V_62 -> V_30 , false ) ;
return 0 ;
}
static int F_43 ( struct V_29 * V_30 )
{
struct V_31 * V_59 = F_8 ( V_30 ) ;
if ( V_59 -> V_57 && F_44 ( V_30 ) )
return F_45 ( V_59 -> V_57 ) ;
return 0 ;
}
static int F_46 ( struct V_29 * V_30 )
{
struct V_31 * V_59 = F_8 ( V_30 ) ;
if ( V_59 -> V_57 && F_44 ( V_30 ) )
return F_47 ( V_59 -> V_57 ) ;
return 0 ;
}
