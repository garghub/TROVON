static bool F_1 ( struct V_1 * V_2 ,
int V_3 , int * V_4 )
{
int V_5 ;
bool V_6 = false ;
int V_7 = V_2 -> V_8 [ 3 ] ;
int V_9 = 3 ;
for ( V_5 = 0 ; V_5 < 4 ; ++ V_5 ) {
if ( V_2 -> V_10 [ V_2 -> V_8 [ V_5 ] ] == V_3 ) {
V_7 = V_2 -> V_8 [ V_5 ] ;
V_9 = V_5 ;
V_6 = true ;
goto V_11;
}
}
V_11:
for ( V_5 = V_9 ; V_5 > 0 ; V_5 -- )
V_2 -> V_8 [ V_5 ] = V_2 -> V_8 [ V_5 - 1 ] ;
V_2 -> V_8 [ 0 ] = V_7 ;
* V_4 = V_7 ;
return V_6 ;
}
static int F_2 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_3 ( V_13 ) ;
int V_14 ;
unsigned int V_15 ;
int V_16 ;
V_16 = F_4 ( V_2 -> V_17 , V_18 + V_2 -> V_19 , & V_15 ) ;
if ( V_16 < 0 ) {
F_5 ( V_2 -> V_13 , L_1 ,
V_20 , V_18 + V_2 -> V_19 , V_16 ) ;
return V_16 ;
}
V_14 = ( int ) V_15 & V_2 -> V_21 ;
return V_14 ;
}
static int F_6 ( struct V_12 * V_13 ,
unsigned V_22 )
{
struct V_1 * V_2 = F_3 ( V_13 ) ;
int V_16 ;
bool V_6 = false ;
int V_23 = V_2 -> V_19 ;
if ( V_2 -> V_24 )
V_6 = F_1 ( V_2 , V_22 , & V_23 ) ;
if ( ! V_6 ) {
V_16 = F_7 ( V_2 -> V_17 , V_18 + V_23 ,
V_2 -> V_21 , V_22 ) ;
if ( V_16 < 0 ) {
F_5 ( V_2 -> V_13 ,
L_2 ,
V_20 , V_18 + V_23 , V_16 ) ;
return V_16 ;
}
V_2 -> V_19 = V_23 ;
V_2 -> V_10 [ V_23 ] = V_22 ;
}
if ( V_2 -> V_24 ) {
F_8 ( V_2 -> V_25 , V_23 & 0x1 ) ;
F_8 ( V_2 -> V_26 ,
( V_23 >> 1 ) & 0x1 ) ;
}
return 0 ;
}
static int F_9 ( struct V_12 * V_27 ,
unsigned int V_28 , unsigned int V_29 )
{
struct V_1 * V_2 = F_3 ( V_27 ) ;
int V_30 , V_31 ;
V_30 = F_10 ( V_27 , V_28 ) ;
if ( V_30 < 0 )
return V_30 ;
V_31 = F_10 ( V_27 , V_29 ) ;
if ( V_31 < 0 )
return V_31 ;
return F_11 ( abs ( V_30 - V_31 ) , V_2 -> V_32 ) ;
}
static int F_12 ( struct V_12 * V_27 , unsigned int V_33 )
{
struct V_1 * V_2 = F_3 ( V_27 ) ;
int V_5 ;
int V_34 ;
int V_16 ;
switch ( V_33 ) {
case V_35 :
V_34 = V_36 ;
break;
case V_37 :
V_34 = 0 ;
break;
default:
return - V_38 ;
}
if ( ! V_2 -> V_24 ) {
V_16 = F_7 ( V_2 -> V_17 ,
V_18 + V_2 -> V_19 , V_36 , V_34 ) ;
if ( V_16 < 0 )
F_5 ( V_2 -> V_13 ,
L_2 ,
V_20 , V_18 + V_2 -> V_19 , V_16 ) ;
return V_16 ;
}
for ( V_5 = 0 ; V_5 < 4 ; ++ V_5 ) {
V_16 = F_7 ( V_2 -> V_17 ,
V_18 + V_5 , V_36 , V_34 ) ;
if ( V_16 < 0 ) {
F_5 ( V_2 -> V_13 ,
L_2 ,
V_20 , V_18 + V_5 , V_16 ) ;
return V_16 ;
}
}
return V_16 ;
}
static unsigned int F_13 ( struct V_12 * V_27 )
{
struct V_1 * V_2 = F_3 ( V_27 ) ;
unsigned int V_15 ;
int V_16 ;
V_16 = F_4 ( V_2 -> V_17 , V_18 + V_2 -> V_19 , & V_15 ) ;
if ( V_16 < 0 ) {
F_5 ( V_2 -> V_13 , L_1 ,
V_20 , V_18 + V_2 -> V_19 , V_16 ) ;
return V_16 ;
}
return ( V_15 & V_36 ) ?
V_35 : V_37 ;
}
static int T_1 F_14 ( struct V_1 * V_2 ,
struct V_39 * V_40 )
{
int V_16 ;
unsigned int V_41 ;
if ( V_2 -> V_42 )
V_16 = F_15 ( V_2 -> V_17 , V_43 , 0xE0 ) ;
else
V_16 = F_15 ( V_2 -> V_17 , V_43 , 0x0 ) ;
if ( V_16 < 0 ) {
F_5 ( V_2 -> V_13 ,
L_3 ,
V_20 , V_43 , V_16 ) ;
return V_16 ;
}
V_16 = F_7 ( V_2 -> V_17 , V_44 , F_16 ( 2 ) , 0 ) ;
if ( V_16 < 0 ) {
F_5 ( V_2 -> V_13 ,
L_2 ,
V_20 , V_44 , V_16 ) ;
return V_16 ;
}
V_16 = F_4 ( V_2 -> V_17 , V_44 , & V_41 ) ;
if ( V_16 < 0 ) {
F_5 ( V_2 -> V_13 ,
L_1 ,
V_20 , V_44 , V_16 ) ;
return V_16 ;
}
V_41 = ( V_41 >> 4 ) & 0x7 ;
V_2 -> V_32 = F_11 ( 32000 , F_16 ( V_41 ) ) ;
return V_16 ;
}
static struct V_39 *
F_17 ( struct V_45 * V_13 )
{
struct V_39 * V_40 ;
struct V_46 * V_47 = V_13 -> V_48 ;
V_40 = F_18 ( V_13 , sizeof( * V_40 ) , V_49 ) ;
if ( ! V_40 ) {
F_5 ( V_13 , L_4 ) ;
return NULL ;
}
V_40 -> V_50 = F_19 ( V_13 , V_13 -> V_48 ) ;
if ( ! V_40 -> V_50 ) {
F_5 ( V_13 , L_5 ) ;
return NULL ;
}
V_40 -> V_25 = F_20 ( V_47 , L_6 , 0 ) ;
V_40 -> V_26 = F_20 ( V_47 , L_7 , 0 ) ;
if ( F_21 ( V_47 , L_8 , NULL ) )
V_40 -> V_51 = 1 ;
if ( F_21 ( V_47 , L_9 , NULL ) )
V_40 -> V_52 = 1 ;
if ( F_21 ( V_47 , L_10 , NULL ) )
V_40 -> V_42 = true ;
if ( F_21 ( V_47 , L_11 , NULL ) )
V_40 -> V_53 = true ;
return V_40 ;
}
static int T_1 F_22 ( struct V_54 * V_55 ,
const struct V_56 * V_57 )
{
struct V_58 V_59 = { } ;
struct V_39 * V_40 ;
struct V_12 * V_27 ;
struct V_1 * V_2 ;
int V_16 ;
int V_5 ;
int V_60 ;
V_40 = V_55 -> V_13 . V_61 ;
V_60 = V_57 -> V_62 ;
if ( V_55 -> V_13 . V_48 ) {
const struct V_63 * V_64 ;
V_64 = F_23 ( F_24 ( V_65 ) ,
& V_55 -> V_13 ) ;
if ( ! V_64 ) {
F_5 ( & V_55 -> V_13 , L_12 ) ;
return - V_66 ;
}
V_60 = ( int ) V_64 -> V_15 ;
if ( ! V_40 )
V_40 = F_17 ( & V_55 -> V_13 ) ;
}
if ( ! V_40 ) {
F_5 ( & V_55 -> V_13 , L_13 ,
V_20 ) ;
return - V_67 ;
}
V_2 = F_18 ( & V_55 -> V_13 , sizeof( * V_2 ) , V_49 ) ;
if ( ! V_2 ) {
F_5 ( & V_55 -> V_13 , L_14 ,
V_20 ) ;
return - V_68 ;
}
V_2 -> V_53 = V_40 -> V_53 ;
V_2 -> V_42 = V_40 -> V_42 ;
V_2 -> V_25 = V_40 -> V_25 ;
V_2 -> V_26 = V_40 -> V_26 ;
V_2 -> V_13 = & V_55 -> V_13 ;
switch ( V_60 ) {
case V_69 :
case V_70 :
V_2 -> V_71 = V_72 ;
V_2 -> V_21 = 0x3F ;
V_2 -> V_73 . V_74 = V_75 ;
break;
case V_76 :
case V_77 :
V_2 -> V_71 = V_78 ;
V_2 -> V_21 = 0x7F ;
V_2 -> V_73 . V_74 = V_79 ;
break;
default:
return - V_66 ;
}
V_2 -> V_73 . V_80 = V_57 -> V_80 ;
V_2 -> V_73 . V_57 = 0 ;
V_2 -> V_73 . V_81 = & V_82 ;
V_2 -> V_73 . type = V_83 ;
V_2 -> V_73 . V_84 = V_85 ;
V_2 -> V_73 . V_86 = V_2 -> V_71 ;
V_2 -> V_73 . V_87 = 10000 ;
V_2 -> V_17 = F_25 ( V_55 , & V_88 ) ;
if ( F_26 ( V_2 -> V_17 ) ) {
V_16 = F_27 ( V_2 -> V_17 ) ;
F_5 ( & V_55 -> V_13 ,
L_15 ,
V_20 , V_16 ) ;
return V_16 ;
}
F_28 ( V_55 , V_2 ) ;
V_2 -> V_19 = ( V_40 -> V_52 & 1 ) * 2 +
( V_40 -> V_51 & 1 ) ;
V_2 -> V_8 [ 0 ] = V_2 -> V_19 ;
V_2 -> V_24 = false ;
if ( F_29 ( V_2 -> V_25 ) && F_29 ( V_2 -> V_26 ) ) {
int V_89 ;
V_89 = ( V_40 -> V_51 ) ?
V_90 : V_91 ;
V_16 = F_30 ( V_2 -> V_25 ,
V_89 , L_16 ) ;
if ( V_16 ) {
F_5 ( & V_55 -> V_13 ,
L_17 ,
V_20 , V_2 -> V_25 , V_16 ) ;
goto V_92;
}
V_89 = ( V_40 -> V_52 ) ?
V_90 : V_91 ;
V_16 = F_30 ( V_2 -> V_26 ,
V_89 , L_18 ) ;
if ( V_16 ) {
F_5 ( & V_55 -> V_13 ,
L_19 ,
V_20 , V_2 -> V_26 , V_16 ) ;
goto V_93;
}
V_2 -> V_24 = true ;
for ( V_5 = 0 ; V_5 < 4 ; ++ V_5 )
V_2 -> V_8 [ V_5 ] = V_5 ;
V_2 -> V_8 [ 0 ] = V_2 -> V_19 ;
V_2 -> V_8 [ V_2 -> V_19 ] = 0 ;
}
V_16 = F_14 ( V_2 , V_40 ) ;
if ( V_16 < 0 ) {
F_5 ( V_2 -> V_13 , L_20 ,
V_20 , V_16 ) ;
goto V_94;
}
V_59 . V_13 = & V_55 -> V_13 ;
V_59 . V_95 = V_40 -> V_50 ;
V_59 . V_62 = V_2 ;
V_59 . V_48 = V_55 -> V_13 . V_48 ;
V_27 = F_31 ( & V_2 -> V_73 , & V_59 ) ;
if ( F_26 ( V_27 ) ) {
F_5 ( V_2 -> V_13 ,
L_21 ,
V_20 , V_57 -> V_80 ) ;
V_16 = F_27 ( V_27 ) ;
goto V_94;
}
V_2 -> V_27 = V_27 ;
return 0 ;
V_94:
if ( F_29 ( V_2 -> V_26 ) )
F_32 ( V_2 -> V_26 ) ;
V_93:
if ( F_29 ( V_2 -> V_25 ) )
F_32 ( V_2 -> V_25 ) ;
V_92:
return V_16 ;
}
static int T_2 F_33 ( struct V_54 * V_55 )
{
struct V_1 * V_2 = F_34 ( V_55 ) ;
if ( F_29 ( V_2 -> V_26 ) )
F_32 ( V_2 -> V_26 ) ;
if ( F_29 ( V_2 -> V_25 ) )
F_32 ( V_2 -> V_25 ) ;
F_35 ( V_2 -> V_27 ) ;
return 0 ;
}
static void F_36 ( struct V_54 * V_55 )
{
struct V_1 * V_2 = F_34 ( V_55 ) ;
int V_96 ;
if ( ! V_2 -> V_53 )
return;
V_96 = F_7 ( V_2 -> V_17 , V_44 , F_16 ( 2 ) , F_16 ( 2 ) ) ;
if ( V_96 < 0 )
F_5 ( V_2 -> V_13 ,
L_2 ,
V_20 , V_44 , V_96 ) ;
}
static int T_3 F_37 ( void )
{
return F_38 ( & V_97 ) ;
}
static void T_4 F_39 ( void )
{
F_40 ( & V_97 ) ;
}
