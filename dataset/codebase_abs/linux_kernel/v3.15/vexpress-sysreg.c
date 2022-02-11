void F_1 ( T_1 V_1 )
{
F_2 ( ~ 0 , V_2 + V_3 ) ;
F_2 ( V_1 , V_2 + V_4 ) ;
}
T_1 F_3 ( int V_5 )
{
if ( V_5 == V_6 )
V_5 = V_7 ;
return F_4 ( V_2 + ( V_5 == V_8 ?
V_9 : V_10 ) ) ;
}
T_1 F_5 ( int V_5 )
{
T_1 V_11 ;
switch ( V_5 ) {
case V_12 :
V_11 = F_4 ( V_2 + V_13 ) ;
return ( V_11 >> V_14 ) & V_15 ;
case V_6 :
case V_8 :
case V_16 :
V_11 = F_3 ( V_5 ) ;
return ( V_11 >> V_17 ) & V_15 ;
}
return ~ 0 ;
}
void T_2 * F_6 ( void )
{
return V_2 + V_18 ;
}
static void F_7 ( struct V_19 * V_20 ,
const char * V_21 , T_1 * V_22 )
{
F_8 ( V_20 ) ;
while ( V_20 ) {
if ( F_9 ( V_20 , V_21 , V_22 ) == 0 ) {
F_10 ( V_20 ) ;
return;
}
V_20 = F_11 ( V_20 ) ;
}
}
unsigned F_12 ( struct V_23 * V_24 , struct V_19 * V_20 )
{
T_1 V_5 = 0 ;
F_13 ( V_24 && V_20 && V_24 -> V_25 != V_20 ) ;
if ( V_24 && ! V_20 )
V_20 = V_24 -> V_25 ;
if ( V_20 ) {
F_7 ( V_20 , L_1 , & V_5 ) ;
} else if ( V_24 && V_24 -> V_26 == & V_27 ) {
struct V_28 * V_29 = F_14 ( V_24 ) ;
if ( V_29 -> V_30 == 1 &&
V_29 -> V_31 [ 0 ] . V_32 == V_33 )
V_5 = V_29 -> V_31 [ 0 ] . V_34 ;
} else if ( V_24 && strncmp ( F_15 ( V_24 ) , L_2 , 3 ) == 0 ) {
V_5 = V_6 ;
}
if ( V_5 == V_6 )
V_5 = V_7 ;
return V_5 ;
}
static void * F_16 ( struct V_23 * V_24 ,
struct V_19 * V_20 )
{
struct V_35 * V_36 ;
T_1 V_5 = 0 ;
T_1 V_37 = 0 ;
T_1 V_38 = 0 ;
T_1 V_39 [ 2 ] ;
int V_40 = - V_41 ;
if ( V_20 ) {
F_8 ( V_20 ) ;
F_7 ( V_20 , L_1 , & V_5 ) ;
F_7 ( V_20 , L_3 ,
& V_37 ) ;
F_7 ( V_20 , L_4 , & V_38 ) ;
V_40 = F_17 ( V_20 ,
L_5 , V_39 ,
F_18 ( V_39 ) ) ;
F_10 ( V_20 ) ;
} else if ( V_24 && V_24 -> V_26 == & V_27 ) {
struct V_28 * V_29 = F_14 ( V_24 ) ;
if ( V_29 -> V_30 == 1 &&
V_29 -> V_31 [ 0 ] . V_32 == V_33 ) {
V_5 = V_29 -> V_31 [ 0 ] . V_34 ;
V_39 [ 0 ] = V_29 -> V_31 [ 0 ] . V_42 ;
V_39 [ 1 ] = V_29 -> V_11 ;
V_40 = 0 ;
}
}
if ( V_40 )
return NULL ;
V_36 = F_19 ( sizeof( * V_36 ) , V_43 ) ;
if ( ! V_36 )
return NULL ;
V_36 -> V_44 = F_20 ( V_38 ) ;
V_36 -> V_44 |= F_21 ( V_39 [ 0 ] ) ;
V_36 -> V_44 |= F_22 ( V_5 == V_6 ?
V_7 : V_5 ) ;
V_36 -> V_44 |= F_23 ( V_37 ) ;
V_36 -> V_23 |= V_39 [ 1 ] ;
F_24 ( V_45 , L_6 , V_36 ,
V_36 -> V_44 , V_36 -> V_23 ) ;
return V_36 ;
}
static void F_25 ( void * V_46 )
{
F_26 ( V_46 ) ;
}
static int F_27 ( void * V_46 , int V_47 ,
bool V_48 , T_1 * V_1 )
{
int V_49 ;
struct V_35 * V_36 = V_46 ;
T_1 V_50 ;
if ( F_13 ( ! V_2 ) )
return - V_51 ;
V_50 = F_4 ( V_2 + V_52 ) ;
if ( F_13 ( V_50 & V_53 ) )
return - V_54 ;
V_50 = V_53 ;
V_50 |= V_48 ? V_55 : 0 ;
V_50 |= V_36 -> V_44 ;
V_50 |= F_28 ( V_36 -> V_23 + V_47 ) ;
if ( ! V_48 )
* V_1 = 0xdeadbeef ;
F_24 ( V_45 , L_7 ,
V_50 , * V_1 ) ;
F_2 ( * V_1 , V_2 + V_56 ) ;
F_2 ( 0 , V_2 + V_57 ) ;
F_2 ( V_50 , V_2 + V_52 ) ;
F_29 () ;
if ( V_45 ) {
if ( ! V_48 )
V_58 = V_1 ;
V_59 = 100 ;
F_30 ( & V_60 ,
V_61 + F_31 ( 100 ) ) ;
V_49 = V_62 ;
} else {
T_1 V_63 ;
do {
F_32 () ;
V_63 = F_4 ( V_2 + V_57 ) ;
} while ( ! V_63 );
if ( ! V_48 && ( V_63 & V_64 ) )
* V_1 = F_4 ( V_2 + V_56 ) ;
V_49 = V_65 ;
if ( V_63 & V_66 )
V_49 = - V_67 ;
}
return V_49 ;
}
static void F_33 ( unsigned long V_1 )
{
int V_49 = V_65 ;
T_1 V_63 = F_4 ( V_2 + V_57 ) ;
if ( V_63 & V_66 )
V_49 = - V_67 ;
if ( ! V_59 -- )
V_49 = - V_68 ;
if ( V_49 < 0 ) {
F_34 ( V_45 , L_8 , V_49 ) ;
} else if ( ! ( V_63 & V_64 ) ) {
F_30 ( & V_60 ,
V_61 + F_31 ( 50 ) ) ;
return;
}
if ( V_58 ) {
* V_58 = F_4 ( V_2 +
V_56 ) ;
F_24 ( V_45 , L_9 ,
* V_58 ) ;
V_58 = NULL ;
}
F_35 ( V_69 , V_49 ) ;
}
void F_36 ( struct V_19 * V_20 )
{
if ( F_13 ( ! V_2 ) )
return;
if ( F_4 ( V_2 + V_70 ) & V_71 )
V_7 = V_16 ;
else
V_7 = V_8 ;
V_69 = F_37 (
V_20 , & V_72 ) ;
F_13 ( ! V_69 ) ;
}
void T_3 F_38 ( void T_2 * V_73 )
{
V_2 = V_73 ;
F_36 ( NULL ) ;
}
void T_3 F_39 ( void )
{
struct V_19 * V_20 ;
if ( V_2 )
return;
V_20 = F_40 ( NULL , NULL , L_10 ) ;
if ( V_20 ) {
V_2 = F_41 ( V_20 , 0 ) ;
F_36 ( V_20 ) ;
}
}
static int F_42 ( struct V_74 * V_75 ,
unsigned V_47 )
{
return 0 ;
}
static int F_43 ( struct V_74 * V_75 ,
unsigned V_47 )
{
struct V_76 * V_77 = & V_78 [ V_47 ] ;
T_1 V_79 = F_4 ( V_2 + V_77 -> V_80 ) ;
return ! ! ( V_79 & V_77 -> V_81 ) ;
}
static void F_44 ( struct V_74 * V_75 ,
unsigned V_47 , int V_81 )
{
struct V_76 * V_77 = & V_78 [ V_47 ] ;
T_1 V_79 = F_4 ( V_2 + V_77 -> V_80 ) ;
if ( V_81 )
V_79 |= V_77 -> V_81 ;
else
V_79 &= ~ V_77 -> V_81 ;
F_2 ( V_79 , V_2 + V_77 -> V_80 ) ;
}
static int F_45 ( struct V_74 * V_75 ,
unsigned V_47 , int V_81 )
{
F_44 ( V_75 , V_47 , V_81 ) ;
return 0 ;
}
static T_4 F_46 ( struct V_23 * V_24 ,
struct V_82 * V_83 , char * V_84 )
{
return sprintf ( V_84 , L_11 , F_4 ( V_2 + V_13 ) ) ;
}
static int F_47 ( struct V_28 * V_29 )
{
int V_40 ;
struct V_31 * V_85 = F_48 ( V_29 ,
V_86 , 0 ) ;
if ( ! F_49 ( & V_29 -> V_24 , V_85 -> V_34 ,
F_50 ( V_85 ) , V_29 -> V_21 ) ) {
F_34 ( & V_29 -> V_24 , L_12 ) ;
return - V_54 ;
}
if ( ! V_2 ) {
V_2 = F_51 ( & V_29 -> V_24 , V_85 -> V_34 ,
F_50 ( V_85 ) ) ;
F_36 ( V_29 -> V_24 . V_25 ) ;
}
if ( ! V_2 ) {
F_34 ( & V_29 -> V_24 , L_13 ) ;
return - V_41 ;
}
F_52 ( & V_60 ,
F_33 , 0 ) ;
V_45 = & V_29 -> V_24 ;
#ifdef F_53
V_87 . V_24 = & V_29 -> V_24 ;
V_40 = F_54 ( & V_87 ) ;
if ( V_40 ) {
F_55 (
V_69 ) ;
F_34 ( & V_29 -> V_24 , L_14 ,
V_40 ) ;
return V_40 ;
}
F_56 ( V_45 , L_15 ,
V_88 , & V_89 ,
sizeof( V_89 ) ) ;
#endif
F_57 ( V_45 , & V_90 ) ;
return 0 ;
}
static int T_3 F_58 ( void )
{
F_39 () ;
return F_59 ( & V_91 ) ;
}
