static int F_1 ( struct V_1 * V_2 , bool V_3 )
{
struct V_4 * clock = F_2 ( V_2 ) ;
struct V_5 * V_6 = clock -> V_6 ;
unsigned int V_7 = clock -> V_8 / 32 ;
unsigned int V_9 = clock -> V_8 % 32 ;
struct V_10 * V_11 = V_6 -> V_11 ;
T_1 V_12 = F_3 ( V_9 ) ;
unsigned long V_13 ;
unsigned int V_14 ;
T_1 V_15 ;
F_4 ( V_11 , L_1 , V_7 , V_9 , V_2 -> V_16 ,
V_3 ? L_2 : L_3 ) ;
F_5 ( & V_6 -> V_17 , V_13 ) ;
V_15 = F_6 ( V_6 -> V_18 + F_7 ( V_7 ) ) ;
if ( V_3 )
V_15 &= ~ V_12 ;
else
V_15 |= V_12 ;
F_8 ( V_15 , V_6 -> V_18 + F_7 ( V_7 ) ) ;
F_9 ( & V_6 -> V_17 , V_13 ) ;
if ( ! V_3 )
return 0 ;
for ( V_14 = 1000 ; V_14 > 0 ; -- V_14 ) {
if ( ! ( F_6 ( V_6 -> V_18 + F_10 ( V_7 ) ) & V_12 ) )
break;
F_11 () ;
}
if ( ! V_14 ) {
F_12 ( V_11 , L_4 ,
V_6 -> V_18 + F_7 ( V_7 ) , V_9 ) ;
return - V_19 ;
}
return 0 ;
}
static int F_13 ( struct V_1 * V_2 )
{
return F_1 ( V_2 , true ) ;
}
static void F_14 ( struct V_1 * V_2 )
{
F_1 ( V_2 , false ) ;
}
static int F_15 ( struct V_1 * V_2 )
{
struct V_4 * clock = F_2 ( V_2 ) ;
struct V_5 * V_6 = clock -> V_6 ;
T_1 V_15 ;
V_15 = F_6 ( V_6 -> V_18 + F_10 ( clock -> V_8 / 32 ) ) ;
return ! ( V_15 & F_3 ( clock -> V_8 % 32 ) ) ;
}
static
struct V_16 * F_16 ( struct V_20 * V_21 ,
void * V_22 )
{
unsigned int V_23 = V_21 -> args [ 1 ] ;
struct V_5 * V_6 = V_22 ;
struct V_10 * V_11 = V_6 -> V_11 ;
unsigned int V_24 ;
const char * type ;
struct V_16 * V_16 ;
switch ( V_21 -> args [ 0 ] ) {
case V_25 :
type = L_5 ;
if ( V_23 > V_6 -> V_26 ) {
F_12 ( V_11 , L_6 , type ,
V_23 ) ;
return F_17 ( - V_27 ) ;
}
V_16 = V_6 -> V_28 [ V_23 ] ;
break;
case V_29 :
type = L_7 ;
V_24 = F_18 ( V_23 ) ;
if ( V_23 % 100 > 31 || V_24 >= V_6 -> V_30 ) {
F_12 ( V_11 , L_6 , type ,
V_23 ) ;
return F_17 ( - V_27 ) ;
}
V_16 = V_6 -> V_28 [ V_6 -> V_31 + V_24 ] ;
break;
default:
F_12 ( V_11 , L_8 , V_21 -> args [ 0 ] ) ;
return F_17 ( - V_27 ) ;
}
if ( F_19 ( V_16 ) )
F_12 ( V_11 , L_9 , type , V_23 ,
F_20 ( V_16 ) ) ;
else
F_4 ( V_11 , L_10 ,
V_21 -> args [ 0 ] , V_21 -> args [ 1 ] , V_16 , V_16 ) ;
return V_16 ;
}
static void T_2 F_21 ( const struct V_32 * V_33 ,
const struct V_34 * V_35 ,
struct V_5 * V_6 )
{
struct V_16 * V_16 = NULL , * V_36 ;
struct V_10 * V_11 = V_6 -> V_11 ;
unsigned int V_37 = V_33 -> V_37 , div = V_33 -> div ;
const char * V_38 ;
F_22 ( V_37 >= V_6 -> V_31 ) ;
F_22 ( F_20 ( V_6 -> V_28 [ V_37 ] ) != - V_39 ) ;
switch ( V_33 -> type ) {
case V_40 :
V_16 = F_23 ( V_6 -> V_11 -> V_41 , V_33 -> V_42 ) ;
break;
case V_43 :
case V_44 :
case V_45 :
F_22 ( V_33 -> V_36 >= V_6 -> V_31 ) ;
V_36 = V_6 -> V_28 [ V_33 -> V_36 ] ;
if ( F_19 ( V_36 ) ) {
V_16 = V_36 ;
goto V_46;
}
V_38 = F_24 ( V_36 ) ;
if ( V_33 -> type == V_45 )
div *= ( F_6 ( V_6 -> V_18 + V_33 -> V_47 ) & 0x3f ) + 1 ;
if ( V_33 -> type == V_44 ) {
V_16 = F_25 ( V_33 -> V_42 , 1 , & V_38 ,
V_6 -> V_18 + V_33 -> V_47 ) ;
} else {
V_16 = F_26 ( NULL , V_33 -> V_42 ,
V_38 , 0 ,
V_33 -> V_48 , div ) ;
}
break;
default:
if ( V_35 -> V_49 )
V_16 = V_35 -> V_49 ( V_11 , V_33 , V_35 ,
V_6 -> V_28 , V_6 -> V_18 ) ;
else
F_12 ( V_11 , L_11 ,
V_33 -> V_42 , V_33 -> type ) ;
break;
}
if ( F_27 ( V_16 ) )
goto V_46;
F_4 ( V_11 , L_12 , V_16 , V_16 ) ;
V_6 -> V_28 [ V_37 ] = V_16 ;
return;
V_46:
F_12 ( V_11 , L_13 , L_5 ,
V_33 -> V_42 , F_20 ( V_16 ) ) ;
}
static void T_2 F_28 ( const struct V_50 * V_51 ,
const struct V_34 * V_35 ,
struct V_5 * V_6 )
{
struct V_4 * clock = NULL ;
struct V_10 * V_11 = V_6 -> V_11 ;
unsigned int V_37 = V_51 -> V_37 ;
struct V_52 V_53 ;
struct V_16 * V_36 , * V_16 ;
const char * V_38 ;
unsigned int V_14 ;
F_22 ( V_37 < V_6 -> V_31 ) ;
F_22 ( V_37 >= V_6 -> V_31 + V_6 -> V_30 ) ;
F_22 ( V_51 -> V_36 >= V_6 -> V_31 + V_6 -> V_30 ) ;
F_22 ( F_20 ( V_6 -> V_28 [ V_37 ] ) != - V_39 ) ;
V_36 = V_6 -> V_28 [ V_51 -> V_36 ] ;
if ( F_19 ( V_36 ) ) {
V_16 = V_36 ;
goto V_46;
}
clock = F_29 ( sizeof( * clock ) , V_54 ) ;
if ( ! clock ) {
V_16 = F_17 ( - V_55 ) ;
goto V_46;
}
V_53 . V_42 = V_51 -> V_42 ;
V_53 . V_56 = & V_57 ;
V_53 . V_13 = V_58 | V_59 ;
for ( V_14 = 0 ; V_14 < V_35 -> V_60 ; V_14 ++ )
if ( V_37 == V_35 -> V_61 [ V_14 ] ) {
F_4 ( V_11 , L_14 ,
V_51 -> V_42 ) ;
V_53 . V_13 |= V_62 ;
break;
}
V_38 = F_24 ( V_36 ) ;
V_53 . V_63 = & V_38 ;
V_53 . V_64 = 1 ;
clock -> V_8 = V_37 - V_6 -> V_31 ;
clock -> V_6 = V_6 ;
clock -> V_2 . V_53 = & V_53 ;
V_16 = F_30 ( NULL , & clock -> V_2 ) ;
if ( F_19 ( V_16 ) )
goto V_46;
F_4 ( V_11 , L_15 , V_16 , V_16 ) ;
V_6 -> V_28 [ V_37 ] = V_16 ;
return;
V_46:
F_12 ( V_11 , L_13 , L_7 ,
V_51 -> V_42 , F_20 ( V_16 ) ) ;
F_31 ( clock ) ;
}
static bool F_32 ( const struct V_20 * V_21 ,
struct V_65 * V_66 )
{
unsigned int V_14 ;
if ( V_21 -> V_67 != V_66 -> V_67 || V_21 -> V_68 != 2 )
return false ;
switch ( V_21 -> args [ 0 ] ) {
case V_25 :
for ( V_14 = 0 ; V_14 < V_66 -> V_69 ; V_14 ++ )
if ( V_21 -> args [ 1 ] == V_66 -> V_70 [ V_14 ] )
return true ;
return false ;
case V_29 :
return true ;
default:
return false ;
}
}
int F_33 ( struct V_71 * V_72 , struct V_10 * V_11 )
{
struct V_65 * V_66 = V_65 ;
struct V_73 * V_67 = V_11 -> V_41 ;
struct V_20 V_21 ;
struct V_16 * V_16 ;
int V_14 = 0 ;
int error ;
if ( ! V_66 ) {
F_4 ( V_11 , L_16 ) ;
return - V_74 ;
}
while ( ! F_34 ( V_67 , L_17 , L_18 , V_14 ,
& V_21 ) ) {
if ( F_32 ( & V_21 , V_66 ) )
goto V_75;
F_35 ( V_21 . V_67 ) ;
V_14 ++ ;
}
return 0 ;
V_75:
V_16 = F_36 ( & V_21 ) ;
F_35 ( V_21 . V_67 ) ;
if ( F_19 ( V_16 ) )
return F_20 ( V_16 ) ;
error = F_37 ( V_11 ) ;
if ( error ) {
F_12 ( V_11 , L_19 , error ) ;
goto V_76;
}
error = F_38 ( V_11 , V_16 ) ;
if ( error ) {
F_12 ( V_11 , L_20 , V_16 , error ) ;
goto V_77;
}
return 0 ;
V_77:
F_39 ( V_11 ) ;
V_76:
F_40 ( V_16 ) ;
return error ;
}
void F_41 ( struct V_71 * V_72 , struct V_10 * V_11 )
{
if ( ! F_42 ( & V_11 -> V_78 . V_79 -> V_80 ) )
F_39 ( V_11 ) ;
}
static int T_2 F_43 ( struct V_10 * V_11 ,
const unsigned int * V_70 ,
unsigned int V_69 )
{
struct V_73 * V_67 = V_11 -> V_41 ;
struct V_71 * V_81 ;
struct V_65 * V_66 ;
T_3 V_82 = V_69 * sizeof( V_70 [ 0 ] ) ;
V_66 = F_44 ( V_11 , sizeof( * V_66 ) + V_82 , V_54 ) ;
if ( ! V_66 )
return - V_55 ;
V_66 -> V_67 = V_67 ;
V_66 -> V_69 = V_69 ;
memcpy ( V_66 -> V_70 , V_70 , V_82 ) ;
V_81 = & V_66 -> V_81 ;
V_81 -> V_42 = V_67 -> V_42 ;
V_81 -> V_13 = V_83 ;
V_81 -> V_84 = F_33 ;
V_81 -> V_85 = F_41 ;
F_45 ( V_81 , & V_86 , false ) ;
V_65 = V_66 ;
F_46 ( V_67 , V_81 ) ;
return 0 ;
}
static int F_47 ( struct V_87 * V_88 ,
unsigned long V_37 )
{
struct V_5 * V_6 = F_48 ( V_88 ) ;
unsigned int V_7 = V_37 / 32 ;
unsigned int V_9 = V_37 % 32 ;
T_1 V_12 = F_3 ( V_9 ) ;
unsigned long V_13 ;
T_1 V_15 ;
F_4 ( V_6 -> V_11 , L_21 , V_7 , V_9 ) ;
F_5 ( & V_6 -> V_17 , V_13 ) ;
V_15 = F_6 ( V_6 -> V_18 + F_49 ( V_7 ) ) ;
V_15 |= V_12 ;
F_8 ( V_15 , V_6 -> V_18 + F_49 ( V_7 ) ) ;
F_9 ( & V_6 -> V_17 , V_13 ) ;
F_50 ( 35 ) ;
F_8 ( V_12 , V_6 -> V_18 + F_51 ( V_7 ) ) ;
return 0 ;
}
static int F_52 ( struct V_87 * V_88 , unsigned long V_37 )
{
struct V_5 * V_6 = F_48 ( V_88 ) ;
unsigned int V_7 = V_37 / 32 ;
unsigned int V_9 = V_37 % 32 ;
T_1 V_12 = F_3 ( V_9 ) ;
unsigned long V_13 ;
T_1 V_15 ;
F_4 ( V_6 -> V_11 , L_22 , V_7 , V_9 ) ;
F_5 ( & V_6 -> V_17 , V_13 ) ;
V_15 = F_6 ( V_6 -> V_18 + F_49 ( V_7 ) ) ;
V_15 |= V_12 ;
F_8 ( V_15 , V_6 -> V_18 + F_49 ( V_7 ) ) ;
F_9 ( & V_6 -> V_17 , V_13 ) ;
return 0 ;
}
static int F_53 ( struct V_87 * V_88 ,
unsigned long V_37 )
{
struct V_5 * V_6 = F_48 ( V_88 ) ;
unsigned int V_7 = V_37 / 32 ;
unsigned int V_9 = V_37 % 32 ;
T_1 V_12 = F_3 ( V_9 ) ;
F_4 ( V_6 -> V_11 , L_23 , V_7 , V_9 ) ;
F_8 ( V_12 , V_6 -> V_18 + F_51 ( V_7 ) ) ;
return 0 ;
}
static int F_54 ( struct V_87 * V_88 ,
unsigned long V_37 )
{
struct V_5 * V_6 = F_48 ( V_88 ) ;
unsigned int V_7 = V_37 / 32 ;
unsigned int V_9 = V_37 % 32 ;
T_1 V_12 = F_3 ( V_9 ) ;
return ! ! ( F_6 ( V_6 -> V_18 + F_49 ( V_7 ) ) & V_12 ) ;
}
static int F_55 ( struct V_87 * V_88 ,
const struct V_20 * V_89 )
{
struct V_5 * V_6 = F_48 ( V_88 ) ;
unsigned int V_90 = V_89 -> args [ 0 ] ;
unsigned int V_24 = F_18 ( V_90 ) ;
if ( V_90 % 100 > 31 || V_24 >= V_88 -> V_91 ) {
F_12 ( V_6 -> V_11 , L_24 , V_90 ) ;
return - V_27 ;
}
return V_24 ;
}
static int F_56 ( struct V_5 * V_6 )
{
V_6 -> V_88 . V_56 = & V_92 ;
V_6 -> V_88 . V_41 = V_6 -> V_11 -> V_41 ;
V_6 -> V_88 . V_93 = 1 ;
V_6 -> V_88 . V_94 = F_55 ;
V_6 -> V_88 . V_91 = V_6 -> V_30 ;
return F_57 ( V_6 -> V_11 , & V_6 -> V_88 ) ;
}
static inline int F_56 ( struct V_5 * V_6 )
{
return 0 ;
}
static void F_58 ( void * V_22 )
{
F_59 ( V_22 ) ;
}
static int T_2 F_60 ( struct V_95 * V_96 )
{
struct V_10 * V_11 = & V_96 -> V_11 ;
struct V_73 * V_67 = V_11 -> V_41 ;
const struct V_34 * V_35 ;
struct V_5 * V_6 ;
unsigned int V_97 , V_14 ;
struct V_98 * V_99 ;
struct V_16 * * V_28 ;
int error ;
V_35 = F_61 ( V_100 , V_67 ) -> V_22 ;
if ( V_35 -> V_53 ) {
error = V_35 -> V_53 ( V_11 ) ;
if ( error )
return error ;
}
V_6 = F_44 ( V_11 , sizeof( * V_6 ) , V_54 ) ;
if ( ! V_6 )
return - V_55 ;
V_6 -> V_11 = V_11 ;
F_62 ( & V_6 -> V_17 ) ;
V_99 = F_63 ( V_96 , V_101 , 0 ) ;
V_6 -> V_18 = F_64 ( V_11 , V_99 ) ;
if ( F_19 ( V_6 -> V_18 ) )
return F_20 ( V_6 -> V_18 ) ;
V_97 = V_35 -> V_102 + V_35 -> V_103 ;
V_28 = F_65 ( V_11 , V_97 , sizeof( * V_28 ) , V_54 ) ;
if ( ! V_28 )
return - V_55 ;
V_6 -> V_28 = V_28 ;
V_6 -> V_31 = V_35 -> V_102 ;
V_6 -> V_30 = V_35 -> V_103 ;
V_6 -> V_26 = V_35 -> V_26 ;
for ( V_14 = 0 ; V_14 < V_97 ; V_14 ++ )
V_28 [ V_14 ] = F_17 ( - V_39 ) ;
for ( V_14 = 0 ; V_14 < V_35 -> V_31 ; V_14 ++ )
F_21 ( & V_35 -> V_104 [ V_14 ] , V_35 , V_6 ) ;
for ( V_14 = 0 ; V_14 < V_35 -> V_30 ; V_14 ++ )
F_28 ( & V_35 -> V_105 [ V_14 ] , V_35 , V_6 ) ;
error = F_66 ( V_67 , F_16 , V_6 ) ;
if ( error )
return error ;
error = F_67 ( V_11 ,
F_58 ,
V_67 ) ;
if ( error )
return error ;
error = F_43 ( V_11 , V_35 -> V_70 ,
V_35 -> V_69 ) ;
if ( error )
return error ;
error = F_56 ( V_6 ) ;
if ( error )
return error ;
return 0 ;
}
static int T_2 F_68 ( void )
{
return F_69 ( & V_106 , F_60 ) ;
}
