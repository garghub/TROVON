static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> V_5 ;
}
static const char * F_3 ( struct V_1 * V_2 ,
unsigned int V_6 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> V_7 [ V_6 ] . V_8 ;
}
static int F_4 ( struct V_1 * V_2 ,
unsigned int V_6 , const unsigned int * * V_9 ,
unsigned int * V_10 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
* V_9 = V_4 -> V_7 [ V_6 ] . V_9 ;
* V_10 = V_4 -> V_7 [ V_6 ] . V_10 ;
return 0 ;
}
static void F_5 ( struct V_1 * V_2 ,
struct V_11 * V_12 , unsigned int V_13 )
{
F_6 ( V_12 , L_1 , F_7 ( V_2 -> V_14 ) ) ;
}
static int F_8 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> V_15 ;
}
static const char * F_9 ( struct V_1 * V_2 ,
unsigned int V_6 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> V_16 [ V_6 ] . V_8 ;
}
static int F_10 ( struct V_1 * V_2 ,
unsigned int V_6 ,
const char * const * * V_7 ,
unsigned int * const V_5 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
* V_7 = V_4 -> V_16 [ V_6 ] . V_7 ;
* V_5 = V_4 -> V_16 [ V_6 ] . V_5 ;
return 0 ;
}
static int F_11 ( struct V_3 * V_4 ,
const struct V_17 * V_18 ,
const struct V_19 * V_20 ,
struct V_21 * V_22 )
{
const struct V_23 * V_24 = & V_20 -> V_24 ;
int V_25 ;
T_1 V_26 , V_27 ;
unsigned long V_28 ;
void T_2 * V_29 ;
for ( V_25 = 0 ; V_25 < V_30 ; V_25 ++ ) {
if ( ( V_24 -> V_31 != V_22 [ V_25 ] . V_24 . V_31 ) ||
( V_24 -> V_32 != V_22 [ V_25 ] . V_24 . V_32 ) ||
( V_24 -> V_13 != V_22 [ V_25 ] . V_24 . V_13 ) )
continue;
if ( ! V_22 [ V_25 ] . V_33 )
break;
if ( V_22 [ V_25 ] . V_24 . V_34 != V_24 -> V_34 ) {
F_12 ( V_4 -> V_14 ,
L_2 ) ;
F_12 ( V_4 -> V_14 , L_3 ,
V_18 -> V_8 , V_20 -> V_8 ) ;
return - V_35 ;
}
return 0 ;
}
if ( V_25 == V_30 )
return - V_35 ;
V_27 = V_24 -> V_27 ;
V_22 [ V_25 ] . V_24 . V_34 = V_24 -> V_34 ;
V_22 [ V_25 ] . V_33 = true ;
switch ( V_24 -> V_32 ) {
case V_36 :
V_29 = V_4 -> V_37 ;
break;
case V_38 :
V_29 = V_4 -> V_39 ;
break;
default:
return - V_35 ;
}
F_13 ( & V_4 -> V_40 , V_28 ) ;
V_26 = F_14 ( V_29 + V_20 -> V_24 . V_13 ) ;
V_26 &= ~ ( V_27 << V_20 -> V_24 . V_31 ) ;
V_26 |= V_20 -> V_24 . V_34 << V_20 -> V_24 . V_31 ;
F_15 ( V_26 , ( V_29 + V_20 -> V_24 . V_13 ) ) ;
F_16 ( & V_4 -> V_40 , V_28 ) ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 ,
unsigned int V_41 , unsigned int V_42 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
const struct V_17 * V_18 ;
const struct V_19 * V_20 ;
if ( V_42 > V_4 -> V_5 ||
V_41 > V_4 -> V_15 )
return - V_35 ;
V_18 = & V_4 -> V_16 [ V_41 ] ;
V_20 = & V_4 -> V_7 [ V_42 ] ;
F_18 ( V_2 -> V_14 , L_4 ,
V_41 , V_18 -> V_8 , V_42 , V_20 -> V_8 ) ;
F_18 ( V_2 -> V_14 , L_5 ,
V_20 -> V_24 . V_13 , V_20 -> V_24 . V_31 , V_20 -> V_24 . V_34 ) ;
return F_11 ( V_4 , V_18 , V_20 , V_4 -> V_22 ) ;
}
static int F_19 ( struct V_1 * V_43 , unsigned int V_44 ,
T_3 V_45 )
{
struct V_3 * V_4 = F_2 ( V_43 ) ;
struct V_46 * V_47 = V_43 -> V_48 -> V_9 [ V_44 ] . V_49 ;
unsigned long V_28 ;
T_1 V_26 ;
void T_2 * V_29 ;
V_29 = V_4 -> V_50 ;
F_13 ( & V_4 -> V_40 , V_28 ) ;
V_26 = F_14 ( V_29 + V_47 -> V_51 . V_13 ) ;
V_26 &= ~ ( V_52 << V_47 -> V_51 . V_53 ) ;
if ( ! V_45 )
V_26 |= V_54 << V_47 -> V_51 . V_53 ;
F_15 ( V_26 , ( V_29 + V_47 -> V_51 . V_13 ) ) ;
F_16 ( & V_4 -> V_40 , V_28 ) ;
F_18 ( V_43 -> V_14 , L_6 , V_44 , V_45 ) ;
return 0 ;
}
static int F_20 ( struct V_1 * V_43 , unsigned int V_44 )
{
struct V_3 * V_4 = F_2 ( V_43 ) ;
struct V_46 * V_47 = V_43 -> V_48 -> V_9 [ V_44 ] . V_49 ;
unsigned long V_28 ;
int V_45 ;
F_13 ( & V_4 -> V_40 , V_28 ) ;
V_45 = F_14 ( V_4 -> V_50 + V_47 -> V_51 . V_13 ) ;
V_45 = ( V_45 >> V_47 -> V_51 . V_53 ) &
V_54 ;
F_16 ( & V_4 -> V_40 , V_28 ) ;
if ( ! V_45 )
V_45 = V_54 ;
else
V_45 = 0 ;
F_18 ( V_43 -> V_14 , L_7 , V_44 , V_45 ) ;
return V_45 ;
}
static int F_21 ( struct V_1 * V_43 , unsigned int V_44 ,
T_1 V_55 )
{
struct V_3 * V_4 = F_2 ( V_43 ) ;
struct V_46 * V_47 = V_43 -> V_48 -> V_9 [ V_44 ] . V_49 ;
unsigned long V_28 ;
T_1 V_26 ;
void T_2 * V_29 ;
V_29 = V_4 -> V_50 ;
F_13 ( & V_4 -> V_40 , V_28 ) ;
V_26 = F_14 ( V_29 + V_47 -> V_51 . V_13 ) ;
V_26 &= ~ ( V_52 << V_47 -> V_51 . V_56 ) ;
if ( V_55 )
V_26 |= V_52 << V_47 -> V_51 . V_56 ;
F_15 ( V_26 , ( V_29 + V_47 -> V_51 . V_13 ) ) ;
F_16 ( & V_4 -> V_40 , V_28 ) ;
F_18 ( V_43 -> V_14 , L_8 , V_44 , V_55 ) ;
return 0 ;
}
static int F_22 ( struct V_1 * V_43 , unsigned int V_44 ,
T_3 * V_55 )
{
struct V_3 * V_4 = F_2 ( V_43 ) ;
struct V_46 * V_47 = V_43 -> V_48 -> V_9 [ V_44 ] . V_49 ;
unsigned long V_28 ;
T_1 V_26 ;
F_13 ( & V_4 -> V_40 , V_28 ) ;
V_26 = F_14 ( V_4 -> V_50 + V_47 -> V_51 . V_13 ) ;
* V_55 = ( V_26 >> V_47 -> V_51 . V_56 ) & V_52 ;
F_16 ( & V_4 -> V_40 , V_28 ) ;
F_18 ( V_43 -> V_14 , L_9 , V_44 , * V_55 ) ;
return 0 ;
}
static int F_23 ( struct V_1 * V_43 , unsigned int V_44 ,
bool V_57 , bool V_58 )
{
struct V_3 * V_4 = F_2 ( V_43 ) ;
struct V_46 * V_47 = V_43 -> V_48 -> V_9 [ V_44 ] . V_49 ;
unsigned long V_28 ;
T_1 V_26 ;
void T_2 * V_29 ;
V_29 = V_4 -> V_50 ;
F_13 ( & V_4 -> V_40 , V_28 ) ;
V_26 = F_14 ( V_29 + V_47 -> V_51 . V_13 ) ;
V_26 &= ~ ( V_59 << V_47 -> V_51 . V_60 ) ;
if ( V_57 == true )
V_26 |= V_61 << V_47 -> V_51 . V_60 ;
if ( V_58 == true )
V_26 |= V_62 << V_47 -> V_51 . V_60 ;
F_15 ( V_26 , ( V_29 + V_47 -> V_51 . V_13 ) ) ;
F_16 ( & V_4 -> V_40 , V_28 ) ;
F_18 ( V_43 -> V_14 , L_10 ,
V_44 , V_57 , V_58 ) ;
return 0 ;
}
static void F_24 ( struct V_1 * V_43 ,
unsigned int V_44 , bool * V_57 ,
bool * V_58 )
{
struct V_3 * V_4 = F_2 ( V_43 ) ;
struct V_46 * V_47 = V_43 -> V_48 -> V_9 [ V_44 ] . V_49 ;
unsigned long V_28 ;
T_1 V_26 ;
F_13 ( & V_4 -> V_40 , V_28 ) ;
V_26 = F_14 ( V_4 -> V_50 + V_47 -> V_51 . V_13 ) ;
V_26 = ( V_26 >> V_47 -> V_51 . V_60 ) & V_59 ;
* V_57 = false ;
* V_58 = false ;
if ( V_26 == V_61 )
* V_57 = true ;
if ( V_26 == V_62 )
* V_58 = true ;
F_16 ( & V_4 -> V_40 , V_28 ) ;
}
static int F_25 ( struct V_1 * V_43 , unsigned int V_44 ,
T_1 V_63 )
{
struct V_3 * V_4 = F_2 ( V_43 ) ;
struct V_46 * V_47 = V_43 -> V_48 -> V_9 [ V_44 ] . V_49 ;
T_1 V_26 ;
unsigned long V_28 ;
void T_2 * V_29 ;
if ( V_63 < 2 || V_63 > 16 || ( V_63 % 2 ) )
return - V_64 ;
V_29 = V_4 -> V_50 ;
F_13 ( & V_4 -> V_40 , V_28 ) ;
V_26 = F_14 ( V_29 + V_47 -> V_51 . V_13 ) ;
V_26 &= ~ ( V_65 << V_47 -> V_51 . V_66 ) ;
V_26 |= ( ( V_63 / 2 ) - 1 ) << V_47 -> V_51 . V_66 ;
F_15 ( V_26 , ( V_29 + V_47 -> V_51 . V_13 ) ) ;
F_16 ( & V_4 -> V_40 , V_28 ) ;
F_18 ( V_43 -> V_14 , L_11 ,
V_44 , V_63 ) ;
return 0 ;
}
static int F_26 ( struct V_1 * V_43 , unsigned int V_44 ,
T_3 * V_63 )
{
struct V_3 * V_4 = F_2 ( V_43 ) ;
struct V_46 * V_47 = V_43 -> V_48 -> V_9 [ V_44 ] . V_49 ;
T_1 V_26 ;
unsigned long V_28 ;
F_13 ( & V_4 -> V_40 , V_28 ) ;
V_26 = F_14 ( V_4 -> V_50 + V_47 -> V_51 . V_13 ) ;
* V_63 = ( V_26 >> V_47 -> V_51 . V_66 ) &
V_65 ;
* V_63 = ( * V_63 + 1 ) * 2 ;
F_16 ( & V_4 -> V_40 , V_28 ) ;
F_18 ( V_43 -> V_14 , L_12 ,
V_44 , * V_63 ) ;
return 0 ;
}
static int F_27 ( struct V_1 * V_67 , unsigned int V_44 ,
unsigned long * V_68 )
{
struct V_46 * V_47 = V_67 -> V_48 -> V_9 [ V_44 ] . V_49 ;
enum V_69 V_70 = F_28 ( * V_68 ) ;
bool V_57 , V_58 ;
T_3 V_71 = 0 ;
int V_72 ;
if ( V_47 -> V_51 . V_32 == - 1 )
return - V_64 ;
switch ( V_70 ) {
case V_73 :
F_24 ( V_67 , V_44 , & V_57 , & V_58 ) ;
if ( ( V_57 == false ) && ( V_58 == false ) )
return 0 ;
else
return - V_35 ;
case V_74 :
F_24 ( V_67 , V_44 , & V_57 , & V_58 ) ;
if ( V_57 )
return 0 ;
else
return - V_35 ;
case V_75 :
F_24 ( V_67 , V_44 , & V_57 , & V_58 ) ;
if ( V_58 )
return 0 ;
else
return - V_35 ;
case V_76 :
V_72 = F_26 ( V_67 , V_44 , & V_71 ) ;
if ( V_72 )
return V_72 ;
* V_68 = F_29 ( V_70 , V_71 ) ;
return 0 ;
case V_77 :
V_72 = F_22 ( V_67 , V_44 , & V_71 ) ;
if ( V_72 )
return V_72 ;
* V_68 = F_29 ( V_70 , V_71 ) ;
return 0 ;
case V_78 :
V_72 = F_20 ( V_67 , V_44 ) ;
if ( V_72 )
return 0 ;
else
return - V_35 ;
default:
return - V_64 ;
}
}
static int F_30 ( struct V_1 * V_43 , unsigned int V_44 ,
unsigned long * V_79 , unsigned int V_80 )
{
struct V_46 * V_47 = V_43 -> V_48 -> V_9 [ V_44 ] . V_49 ;
enum V_69 V_70 ;
unsigned int V_25 ;
T_1 V_71 ;
int V_72 = - V_64 ;
if ( V_47 -> V_51 . V_32 == - 1 )
return - V_64 ;
for ( V_25 = 0 ; V_25 < V_80 ; V_25 ++ ) {
V_70 = F_28 ( V_79 [ V_25 ] ) ;
V_71 = F_31 ( V_79 [ V_25 ] ) ;
switch ( V_70 ) {
case V_73 :
V_72 = F_23 ( V_43 , V_44 , false , false ) ;
if ( V_72 < 0 )
goto V_81;
break;
case V_74 :
V_72 = F_23 ( V_43 , V_44 , true , false ) ;
if ( V_72 < 0 )
goto V_81;
break;
case V_75 :
V_72 = F_23 ( V_43 , V_44 , false , true ) ;
if ( V_72 < 0 )
goto V_81;
break;
case V_76 :
V_72 = F_25 ( V_43 , V_44 , V_71 ) ;
if ( V_72 < 0 )
goto V_81;
break;
case V_77 :
V_72 = F_21 ( V_43 , V_44 , V_71 ) ;
if ( V_72 < 0 )
goto V_81;
break;
case V_78 :
V_72 = F_19 ( V_43 , V_44 , V_71 ) ;
if ( V_72 < 0 )
goto V_81;
break;
default:
F_12 ( V_43 -> V_14 , L_13 ) ;
return - V_64 ;
}
}
V_81:
return V_72 ;
}
static int F_32 ( struct V_3 * V_4 )
{
struct V_21 * log ;
unsigned int V_25 ;
V_4 -> V_22 = F_33 ( V_4 -> V_14 , V_30 ,
sizeof( struct V_21 ) ,
V_82 ) ;
if ( ! V_4 -> V_22 )
return - V_83 ;
for ( V_25 = 0 ; V_25 < V_30 ; V_25 ++ )
V_4 -> V_22 [ V_25 ] . V_33 = false ;
log = & V_4 -> V_22 [ 0 ] ;
log -> V_24 . V_32 = V_36 ;
log -> V_24 . V_13 = 0 ;
log -> V_24 . V_31 = 31 ;
log -> V_24 . V_34 = 0 ;
for ( V_25 = 1 ; V_25 < ( V_30 - V_84 ) ; V_25 ++ ) {
log = & V_4 -> V_22 [ V_25 ] ;
log -> V_24 . V_32 = V_36 ;
log -> V_24 . V_13 = V_85 ;
log -> V_24 . V_31 = 32 - ( V_25 * 2 ) ;
log -> V_24 . V_34 = 0 ;
}
for ( V_25 = 0 ; V_25 < V_84 ; V_25 ++ ) {
log = & V_4 -> V_22 [ ( V_30 - V_84 ) + V_25 ] ;
log -> V_24 . V_32 = V_38 ;
log -> V_24 . V_13 = 0 ;
log -> V_24 . V_31 = V_25 ;
log -> V_24 . V_34 = 0 ;
}
return 0 ;
}
static int F_34 ( struct V_86 * V_87 )
{
struct V_3 * V_4 ;
struct V_88 * V_89 ;
int V_25 , V_72 ;
struct V_90 * V_9 ;
unsigned int V_10 = F_35 ( V_91 ) ;
V_4 = F_36 ( & V_87 -> V_14 , sizeof( * V_4 ) , V_82 ) ;
if ( ! V_4 )
return - V_83 ;
V_4 -> V_14 = & V_87 -> V_14 ;
F_37 ( V_87 , V_4 ) ;
F_38 ( & V_4 -> V_40 ) ;
V_89 = F_39 ( V_87 , V_92 , 0 ) ;
V_4 -> V_37 = F_40 ( & V_87 -> V_14 , V_89 ) ;
if ( F_41 ( V_4 -> V_37 ) )
return F_42 ( V_4 -> V_37 ) ;
V_89 = F_39 ( V_87 , V_92 , 1 ) ;
V_4 -> V_39 = F_43 ( & V_87 -> V_14 , V_89 -> V_93 ,
F_44 ( V_89 ) ) ;
if ( ! V_4 -> V_39 ) {
F_12 ( & V_87 -> V_14 , L_14 ) ;
return - V_83 ;
}
V_89 = F_39 ( V_87 , V_92 , 2 ) ;
V_4 -> V_50 = F_40 ( & V_87 -> V_14 , V_89 ) ;
if ( F_41 ( V_4 -> V_50 ) )
return F_42 ( V_4 -> V_50 ) ;
V_72 = F_32 ( V_4 ) ;
if ( V_72 ) {
F_12 ( & V_87 -> V_14 , L_15 ) ;
return V_72 ;
}
V_9 = F_33 ( & V_87 -> V_14 , V_10 , sizeof( * V_9 ) , V_82 ) ;
if ( ! V_9 )
return - V_83 ;
for ( V_25 = 0 ; V_25 < V_10 ; V_25 ++ ) {
V_9 [ V_25 ] . V_94 = V_91 [ V_25 ] . V_44 ;
V_9 [ V_25 ] . V_8 = V_91 [ V_25 ] . V_8 ;
V_9 [ V_25 ] . V_49 = & V_91 [ V_25 ] ;
}
V_4 -> V_7 = V_95 ;
V_4 -> V_5 = F_35 ( V_95 ) ;
V_4 -> V_16 = V_96 ;
V_4 -> V_15 = F_35 ( V_96 ) ;
V_97 . V_9 = V_9 ;
V_97 . V_98 = V_10 ;
V_4 -> V_99 = F_45 ( & V_97 , & V_87 -> V_14 ,
V_4 ) ;
if ( F_41 ( V_4 -> V_99 ) ) {
F_12 ( & V_87 -> V_14 , L_16 ) ;
return F_42 ( V_4 -> V_99 ) ;
}
return 0 ;
}
static int T_4 F_46 ( void )
{
return F_47 ( & V_100 ) ;
}
