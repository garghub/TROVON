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
static int F_9 ( struct V_12 * V_27 , unsigned int V_28 )
{
struct V_1 * V_2 = F_3 ( V_27 ) ;
int V_5 ;
int V_29 ;
int V_16 ;
switch ( V_28 ) {
case V_30 :
V_29 = V_31 ;
break;
case V_32 :
V_29 = 0 ;
break;
default:
return - V_33 ;
}
if ( ! V_2 -> V_24 ) {
V_16 = F_7 ( V_2 -> V_17 ,
V_18 + V_2 -> V_19 , V_31 , V_29 ) ;
if ( V_16 < 0 )
F_5 ( V_2 -> V_13 ,
L_2 ,
V_20 , V_18 + V_2 -> V_19 , V_16 ) ;
return V_16 ;
}
for ( V_5 = 0 ; V_5 < 4 ; ++ V_5 ) {
V_16 = F_7 ( V_2 -> V_17 ,
V_18 + V_5 , V_31 , V_29 ) ;
if ( V_16 < 0 ) {
F_5 ( V_2 -> V_13 ,
L_2 ,
V_20 , V_18 + V_5 , V_16 ) ;
return V_16 ;
}
}
return V_16 ;
}
static unsigned int F_10 ( struct V_12 * V_27 )
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
return ( V_15 & V_31 ) ?
V_30 : V_32 ;
}
static int F_11 ( struct V_1 * V_2 ,
struct V_34 * V_35 )
{
int V_16 ;
unsigned int V_36 ;
if ( V_2 -> V_37 )
V_16 = F_12 ( V_2 -> V_17 , V_38 , 0xE0 ) ;
else
V_16 = F_12 ( V_2 -> V_17 , V_38 , 0x0 ) ;
if ( V_16 < 0 ) {
F_5 ( V_2 -> V_13 ,
L_3 ,
V_20 , V_38 , V_16 ) ;
return V_16 ;
}
V_16 = F_7 ( V_2 -> V_17 , V_39 , F_13 ( 2 ) , 0 ) ;
if ( V_16 < 0 ) {
F_5 ( V_2 -> V_13 ,
L_2 ,
V_20 , V_39 , V_16 ) ;
return V_16 ;
}
V_16 = F_4 ( V_2 -> V_17 , V_39 , & V_36 ) ;
if ( V_16 < 0 ) {
F_5 ( V_2 -> V_13 ,
L_1 ,
V_20 , V_39 , V_16 ) ;
return V_16 ;
}
V_36 = ( V_36 >> 5 ) & 0x7 ;
V_2 -> V_40 . V_41 = F_14 ( 32000 , F_13 ( V_36 ) ) ;
return V_16 ;
}
static struct V_34 *
F_15 ( struct V_42 * V_13 )
{
struct V_34 * V_35 ;
struct V_43 * V_44 = V_13 -> V_45 ;
V_35 = F_16 ( V_13 , sizeof( * V_35 ) , V_46 ) ;
if ( ! V_35 )
return NULL ;
V_35 -> V_47 = F_17 ( V_13 , V_13 -> V_45 ) ;
if ( ! V_35 -> V_47 ) {
F_5 ( V_13 , L_4 ) ;
return NULL ;
}
V_35 -> V_25 = F_18 ( V_44 , L_5 , 0 ) ;
V_35 -> V_26 = F_18 ( V_44 , L_6 , 0 ) ;
if ( F_19 ( V_44 , L_7 , NULL ) )
V_35 -> V_48 = 1 ;
if ( F_19 ( V_44 , L_8 , NULL ) )
V_35 -> V_49 = 1 ;
if ( F_19 ( V_44 , L_9 , NULL ) )
V_35 -> V_37 = true ;
if ( F_19 ( V_44 , L_10 , NULL ) )
V_35 -> V_50 = true ;
return V_35 ;
}
static int F_20 ( struct V_51 * V_52 ,
const struct V_53 * V_54 )
{
struct V_55 V_56 = { } ;
struct V_34 * V_35 ;
struct V_12 * V_27 ;
struct V_1 * V_2 ;
int V_16 ;
int V_5 ;
int V_57 ;
V_35 = F_21 ( & V_52 -> V_13 ) ;
if ( V_52 -> V_13 . V_45 ) {
const struct V_58 * V_59 ;
V_59 = F_22 ( F_23 ( V_60 ) ,
& V_52 -> V_13 ) ;
if ( ! V_59 ) {
F_5 ( & V_52 -> V_13 , L_11 ) ;
return - V_61 ;
}
V_57 = ( int ) ( long ) V_59 -> V_15 ;
if ( ! V_35 )
V_35 = F_15 ( & V_52 -> V_13 ) ;
} else if ( V_54 ) {
V_57 = V_54 -> V_62 ;
} else {
F_5 ( & V_52 -> V_13 , L_12 ) ;
return - V_61 ;
}
if ( ! V_35 ) {
F_5 ( & V_52 -> V_13 , L_13 ,
V_20 ) ;
return - V_63 ;
}
V_2 = F_16 ( & V_52 -> V_13 , sizeof( * V_2 ) , V_46 ) ;
if ( ! V_2 )
return - V_64 ;
V_2 -> V_50 = V_35 -> V_50 ;
V_2 -> V_37 = V_35 -> V_37 ;
V_2 -> V_25 = V_35 -> V_25 ;
V_2 -> V_26 = V_35 -> V_26 ;
V_2 -> V_13 = & V_52 -> V_13 ;
switch ( V_57 ) {
case V_65 :
case V_66 :
V_2 -> V_40 . V_67 = V_68 ;
V_2 -> V_21 = 0x3F ;
V_2 -> V_40 . V_69 = V_70 ;
break;
case V_71 :
case V_72 :
V_2 -> V_40 . V_67 = V_73 ;
V_2 -> V_21 = 0x7F ;
V_2 -> V_40 . V_69 = V_74 ;
break;
default:
return - V_61 ;
}
V_2 -> V_40 . V_75 = V_52 -> V_75 ;
V_2 -> V_40 . V_54 = 0 ;
V_2 -> V_40 . V_76 = & V_77 ;
V_2 -> V_40 . type = V_78 ;
V_2 -> V_40 . V_79 = V_80 ;
V_2 -> V_40 . V_81 = 10000 ;
V_2 -> V_17 = F_24 ( V_52 , & V_82 ) ;
if ( F_25 ( V_2 -> V_17 ) ) {
V_16 = F_26 ( V_2 -> V_17 ) ;
F_5 ( & V_52 -> V_13 ,
L_14 ,
V_20 , V_16 ) ;
return V_16 ;
}
F_27 ( V_52 , V_2 ) ;
V_2 -> V_19 = ( V_35 -> V_49 & 1 ) * 2 +
( V_35 -> V_48 & 1 ) ;
V_2 -> V_8 [ 0 ] = V_2 -> V_19 ;
V_2 -> V_24 = false ;
if ( F_28 ( V_2 -> V_25 ) && F_28 ( V_2 -> V_26 ) ) {
int V_83 ;
V_83 = ( V_35 -> V_48 ) ?
V_84 : V_85 ;
V_16 = F_29 ( & V_52 -> V_13 , V_2 -> V_25 ,
V_83 , L_15 ) ;
if ( V_16 ) {
F_5 ( & V_52 -> V_13 ,
L_16 ,
V_20 , V_2 -> V_25 , V_16 ) ;
return V_16 ;
}
V_83 = ( V_35 -> V_49 ) ?
V_84 : V_85 ;
V_16 = F_29 ( & V_52 -> V_13 , V_2 -> V_26 ,
V_83 , L_17 ) ;
if ( V_16 ) {
F_5 ( & V_52 -> V_13 ,
L_18 ,
V_20 , V_2 -> V_26 , V_16 ) ;
return V_16 ;
}
V_2 -> V_24 = true ;
for ( V_5 = 0 ; V_5 < 4 ; ++ V_5 )
V_2 -> V_8 [ V_5 ] = V_5 ;
V_2 -> V_8 [ 0 ] = V_2 -> V_19 ;
V_2 -> V_8 [ V_2 -> V_19 ] = 0 ;
}
V_16 = F_11 ( V_2 , V_35 ) ;
if ( V_16 < 0 ) {
F_5 ( V_2 -> V_13 , L_19 ,
V_20 , V_16 ) ;
return V_16 ;
}
V_56 . V_13 = & V_52 -> V_13 ;
V_56 . V_86 = V_35 -> V_47 ;
V_56 . V_62 = V_2 ;
V_56 . V_45 = V_52 -> V_13 . V_45 ;
V_27 = F_30 ( & V_52 -> V_13 , & V_2 -> V_40 , & V_56 ) ;
if ( F_25 ( V_27 ) ) {
F_5 ( V_2 -> V_13 ,
L_20 ,
V_20 , V_54 -> V_75 ) ;
return F_26 ( V_27 ) ;
}
V_2 -> V_27 = V_27 ;
return 0 ;
}
static void F_31 ( struct V_51 * V_52 )
{
struct V_1 * V_2 = F_32 ( V_52 ) ;
int V_87 ;
if ( ! V_2 -> V_50 )
return;
V_87 = F_7 ( V_2 -> V_17 , V_39 , F_13 ( 2 ) , F_13 ( 2 ) ) ;
if ( V_87 < 0 )
F_5 ( V_2 -> V_13 ,
L_2 ,
V_20 , V_39 , V_87 ) ;
}
static int T_1 F_33 ( void )
{
return F_34 ( & V_88 ) ;
}
static void T_2 F_35 ( void )
{
F_36 ( & V_88 ) ;
}
