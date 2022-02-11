bool F_1 ( int V_1 )
{
if ( V_2 . V_3 != V_4 ||
V_2 . V_5 != 6 )
return false ;
switch ( V_2 . V_6 ) {
case 30 :
case 26 :
case 46 :
case 37 :
case 44 :
case 47 :
if ( V_1 == V_7 ||
V_1 == V_8 )
return true ;
break;
case 42 :
case 45 :
case 58 :
case 62 :
case 60 :
case 63 :
case 69 :
case 70 :
case 61 :
case 86 :
case 71 :
case 79 :
case 78 :
case 94 :
if ( V_1 == V_7 ||
V_1 == V_8 ||
V_1 == V_9 )
return true ;
break;
case 55 :
case 77 :
case 76 :
if ( V_1 == V_10 ||
V_1 == V_8 )
return true ;
break;
}
return false ;
}
bool F_2 ( int V_1 )
{
if ( V_2 . V_3 != V_4 ||
V_2 . V_5 != 6 )
return false ;
switch ( V_2 . V_6 ) {
case 30 :
case 26 :
case 46 :
case 37 :
case 44 :
case 47 :
if ( V_1 == V_7 ||
V_1 == V_8 ||
V_1 == V_9 )
return true ;
break;
case 42 :
case 45 :
case 58 :
case 62 :
case 60 :
case 63 :
case 70 :
case 61 :
case 86 :
case 71 :
case 79 :
case 78 :
case 94 :
if ( V_1 == V_11 ||
V_1 == V_12 ||
V_1 == V_13 ||
V_1 == V_14 )
return true ;
break;
case 55 :
case 77 :
case 76 :
if ( V_1 == V_8 )
return true ;
break;
case 69 :
if ( V_1 == V_11 ||
V_1 == V_12 ||
V_1 == V_13 ||
V_1 == V_14 ||
V_1 == V_15 ||
V_1 == V_16 ||
V_1 == V_17 )
return true ;
break;
}
return false ;
}
static T_1 F_3 ( struct V_18 * V_19 ,
struct V_20 * V_21 ,
char * V_22 )
{
struct V_23 * V_23 = F_4 ( V_19 ) ;
if ( V_23 == & V_24 )
return F_5 ( true , V_22 , & V_25 ) ;
else if ( V_23 == & V_26 )
return F_5 ( true , V_22 , & V_27 ) ;
else
return 0 ;
}
static int F_6 ( struct V_28 * V_29 )
{
T_2 V_30 = V_29 -> V_21 . V_31 ;
int V_32 = 0 ;
if ( V_29 -> V_21 . type != V_29 -> V_23 -> type )
return - V_33 ;
if ( V_29 -> V_21 . V_34 ||
V_29 -> V_21 . V_35 ||
V_29 -> V_21 . V_36 ||
V_29 -> V_21 . V_37 ||
V_29 -> V_21 . V_38 ||
V_29 -> V_21 . V_39 ||
V_29 -> V_21 . V_40 )
return - V_41 ;
if ( V_29 -> V_23 == & V_24 ) {
if ( V_30 >= V_42 )
return - V_41 ;
if ( ! V_43 [ V_30 ] . V_21 )
return - V_41 ;
V_29 -> V_44 . V_45 = V_43 [ V_30 ] . V_46 ;
} else if ( V_29 -> V_23 == & V_26 ) {
if ( V_30 >= V_47 )
return - V_41 ;
if ( ! V_48 [ V_30 ] . V_21 )
return - V_41 ;
V_29 -> V_44 . V_45 = V_48 [ V_30 ] . V_46 ;
} else
return - V_33 ;
V_29 -> V_44 . V_31 = V_30 ;
V_29 -> V_44 . V_1 = - 1 ;
return V_32 ;
}
static inline T_2 F_7 ( struct V_28 * V_29 )
{
T_2 V_49 ;
F_8 ( V_29 -> V_44 . V_45 , V_49 ) ;
return V_49 ;
}
static void F_9 ( struct V_28 * V_29 )
{
struct V_50 * V_51 = & V_29 -> V_44 ;
T_2 V_52 , V_53 ;
V_54:
V_52 = F_10 ( & V_51 -> V_55 ) ;
V_53 = F_7 ( V_29 ) ;
if ( F_11 ( & V_51 -> V_55 , V_52 ,
V_53 ) != V_52 )
goto V_54;
F_12 ( V_53 - V_52 , & V_29 -> V_56 ) ;
}
static void F_13 ( struct V_28 * V_29 , int V_57 )
{
F_14 ( & V_29 -> V_44 . V_55 , F_7 ( V_29 ) ) ;
}
static void F_15 ( struct V_28 * V_29 , int V_57 )
{
F_9 ( V_29 ) ;
}
static void F_16 ( struct V_28 * V_29 , int V_57 )
{
F_15 ( V_29 , V_58 ) ;
}
static int F_17 ( struct V_28 * V_29 , int V_57 )
{
if ( V_57 & V_59 )
F_13 ( V_29 , V_57 ) ;
return 0 ;
}
static void F_18 ( int V_60 )
{
int V_61 , V_62 , V_63 ;
if ( V_64 ) {
V_62 = F_19 ( V_60 ) ;
V_63 = - 1 ;
F_20 (i) {
if ( V_61 == V_60 )
continue;
if ( V_62 == F_19 ( V_61 ) ) {
V_63 = V_61 ;
break;
}
}
if ( F_21 ( V_60 , & V_25 ) && V_63 >= 0 )
F_22 ( V_63 , & V_25 ) ;
F_23 ( F_24 ( & V_25 ) ) ;
if ( V_63 >= 0 )
F_25 ( & V_24 , V_60 , V_63 ) ;
}
if ( V_65 ) {
V_62 = F_26 ( V_60 ) ;
V_63 = - 1 ;
F_20 (i) {
if ( V_61 == V_60 )
continue;
if ( V_62 == F_26 ( V_61 ) ) {
V_63 = V_61 ;
break;
}
}
if ( F_21 ( V_60 , & V_27 ) && V_63 >= 0 )
F_22 ( V_63 , & V_27 ) ;
F_23 ( F_24 ( & V_27 ) ) ;
if ( V_63 >= 0 )
F_25 ( & V_26 , V_60 , V_63 ) ;
}
}
static void F_27 ( int V_60 )
{
int V_61 , V_62 ;
if ( V_64 ) {
V_62 = F_19 ( V_60 ) ;
F_28 (i, &cstate_core_cpu_mask) {
if ( V_62 == F_19 ( V_61 ) )
break;
}
if ( V_61 >= V_66 )
F_22 ( V_60 , & V_25 ) ;
}
if ( V_65 ) {
V_62 = F_26 ( V_60 ) ;
F_28 (i, &cstate_pkg_cpu_mask) {
if ( V_62 == F_26 ( V_61 ) )
break;
}
if ( V_61 >= V_66 )
F_22 ( V_60 , & V_27 ) ;
}
}
static int F_29 ( struct V_67 * V_68 ,
unsigned long V_69 , void * V_70 )
{
unsigned int V_60 = ( long ) V_70 ;
switch ( V_69 & ~ V_71 ) {
case V_72 :
break;
case V_73 :
F_27 ( V_60 ) ;
break;
case V_74 :
case V_75 :
break;
case V_76 :
case V_77 :
break;
case V_78 :
F_18 ( V_60 ) ;
break;
default:
break;
}
return V_79 ;
}
static bool F_30 ( struct V_80 * V_46 ,
struct V_81 * * V_82 ,
int V_83 )
{
int V_61 , V_84 = 0 ;
T_2 V_49 ;
for ( V_61 = 0 ; V_61 < V_83 ; V_61 ++ ) {
if ( ! V_46 [ V_61 ] . F_31 ( V_61 ) || F_32 ( V_46 [ V_61 ] . V_46 , & V_49 ) )
V_46 [ V_61 ] . V_21 = NULL ;
}
for ( V_61 = 0 ; V_61 < V_83 ; V_61 ++ ) {
if ( V_46 [ V_61 ] . V_21 )
V_82 [ V_84 ++ ] = & V_46 [ V_61 ] . V_21 -> V_21 . V_21 ;
}
V_82 [ V_84 ] = NULL ;
return ( V_84 > 0 ) ? true : false ;
}
static int T_3 F_33 ( void )
{
switch ( V_2 . V_6 ) {
case 55 :
case 76 :
case 77 :
V_48 [ V_13 ] . V_46 = V_85 ;
}
if ( F_30 ( V_43 , V_86 , V_42 ) )
V_64 = true ;
if ( F_30 ( V_48 , V_87 , V_47 ) )
V_65 = true ;
return ( V_64 || V_65 ) ? 0 : - V_88 ;
}
static void T_3 F_34 ( void )
{
int V_60 ;
F_35 () ;
F_20 (cpu)
F_27 ( V_60 ) ;
F_36 ( F_29 ) ;
F_37 () ;
}
static void T_3 F_38 ( void )
{
int V_89 ;
if ( V_64 ) {
V_89 = F_39 ( & V_24 , V_24 . V_90 , - 1 ) ;
if ( F_23 ( V_89 ) )
F_40 ( L_1 ,
V_24 . V_90 , V_89 ) ;
}
if ( V_65 ) {
V_89 = F_39 ( & V_26 , V_26 . V_90 , - 1 ) ;
if ( F_23 ( V_89 ) )
F_40 ( L_1 ,
V_26 . V_90 , V_89 ) ;
}
}
static int T_3 F_41 ( void )
{
int V_89 ;
if ( V_91 )
return - V_88 ;
V_89 = F_33 () ;
if ( V_89 )
return V_89 ;
F_34 () ;
F_38 () ;
return 0 ;
}
