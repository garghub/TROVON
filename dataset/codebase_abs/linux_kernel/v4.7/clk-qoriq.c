static void F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 T_2 * V_4 )
{
if ( V_2 -> V_5 . V_6 & V_7 )
F_2 ( V_3 , V_4 ) ;
else
F_3 ( V_3 , V_4 ) ;
}
static T_1 F_4 ( struct V_1 * V_2 , T_1 T_2 * V_4 )
{
T_1 V_3 ;
if ( V_2 -> V_5 . V_6 & V_7 )
V_3 = F_5 ( V_4 ) ;
else
V_3 = F_6 ( V_4 ) ;
return V_3 ;
}
static void T_3 F_7 ( struct V_1 * V_2 )
{
T_1 V_4 ;
V_4 = F_6 ( & V_2 -> V_8 -> V_9 [ 7 ] ) ;
if ( V_4 & V_10 )
V_2 -> V_11 [ 0 ] = V_2 -> V_12 [ V_13 ] . div [ V_14 ] . V_15 ;
else
V_2 -> V_11 [ 0 ] = V_2 -> V_12 [ V_16 ] . div [ V_14 ] . V_15 ;
}
static void T_3 F_8 ( struct V_1 * V_2 )
{
T_1 V_4 ;
V_4 = F_6 ( & V_2 -> V_8 -> V_9 [ 7 ] ) ;
if ( V_4 & V_10 )
V_2 -> V_11 [ 0 ] = V_2 -> V_12 [ V_17 ] . div [ V_14 ] . V_15 ;
else
V_2 -> V_11 [ 0 ] = V_2 -> V_12 [ V_16 ] . div [ V_14 ] . V_15 ;
if ( V_4 & V_18 )
V_2 -> V_11 [ 1 ] = V_2 -> V_12 [ V_17 ] . div [ V_14 ] . V_15 ;
else
V_2 -> V_11 [ 1 ] = V_2 -> V_12 [ V_16 ] . div [ V_14 ] . V_15 ;
}
static void T_3 F_9 ( struct V_1 * V_2 )
{
T_1 V_4 ;
int div = V_14 ;
V_4 = F_6 ( & V_2 -> V_8 -> V_9 [ 7 ] ) ;
if ( V_4 & V_19 )
div = V_20 ;
if ( V_4 & V_10 )
V_2 -> V_11 [ 0 ] = V_2 -> V_12 [ V_13 ] . div [ div ] . V_15 ;
else
V_2 -> V_11 [ 0 ] = V_2 -> V_12 [ V_16 ] . div [ V_14 ] . V_15 ;
}
static void T_3 F_10 ( struct V_1 * V_2 )
{
T_1 V_4 ;
int div = V_14 ;
V_4 = F_6 ( & V_2 -> V_8 -> V_9 [ 7 ] ) ;
if ( V_4 & V_19 )
div = V_20 ;
if ( V_4 & V_10 )
V_2 -> V_11 [ 0 ] = V_2 -> V_12 [ V_17 ] . div [ div ] . V_15 ;
else
V_2 -> V_11 [ 0 ] = V_2 -> V_12 [ V_16 ] . div [ V_14 ] . V_15 ;
if ( V_4 & V_18 )
V_2 -> V_11 [ 1 ] = V_2 -> V_12 [ V_17 ] . div [ div ] . V_15 ;
else
V_2 -> V_11 [ 1 ] = V_2 -> V_12 [ V_16 ] . div [ V_14 ] . V_15 ;
}
static void T_3 F_11 ( struct V_1 * V_2 )
{
V_2 -> V_11 [ 0 ] = V_2 -> V_21 [ 1 ] ;
}
static void T_3 F_12 ( struct V_1 * V_2 )
{
V_2 -> V_11 [ 0 ] = V_2 -> V_12 [ V_16 ] . div [ V_22 ] . V_15 ;
}
static void T_3 F_13 ( struct V_1 * V_2 )
{
V_2 -> V_11 [ 0 ] = V_2 -> V_21 [ 0 ] ;
}
static void T_3 F_14 ( struct V_1 * V_2 )
{
V_2 -> V_11 [ 0 ] = V_2 -> V_21 [ 3 ] ;
V_2 -> V_11 [ 1 ] = V_2 -> V_21 [ 4 ] ;
}
static int F_15 ( struct V_23 * V_24 , T_4 V_25 )
{
struct V_26 * V_27 = F_16 ( V_24 ) ;
T_1 V_28 ;
if ( V_25 >= V_27 -> V_29 )
return - V_30 ;
V_28 = V_27 -> V_31 [ V_25 ] ;
F_1 ( V_27 -> V_2 , ( V_28 << V_32 ) & V_33 , V_27 -> V_4 ) ;
return 0 ;
}
static T_4 F_17 ( struct V_23 * V_24 )
{
struct V_26 * V_27 = F_16 ( V_24 ) ;
T_1 V_28 ;
T_5 V_34 ;
V_28 = ( F_4 ( V_27 -> V_2 , V_27 -> V_4 ) & V_33 ) >> V_32 ;
V_34 = V_27 -> V_35 [ V_28 ] ;
if ( V_34 < 0 ) {
F_18 ( L_1 , V_36 , V_27 -> V_4 ) ;
return 0 ;
}
return V_34 ;
}
static const struct V_37 * F_19 ( struct V_1 * V_2 ,
struct V_26 * V_27 ,
int V_25 )
{
int V_12 , div ;
if ( ! ( V_27 -> V_5 -> V_28 [ V_25 ] . V_6 & V_38 ) )
return NULL ;
V_12 = V_27 -> V_5 -> V_28 [ V_25 ] . V_12 ;
div = V_27 -> V_5 -> V_28 [ V_25 ] . div ;
return & V_2 -> V_12 [ V_12 ] . div [ div ] ;
}
static struct V_15 * T_3 F_20 ( struct V_1 * V_2 ,
struct V_26 * V_27 ,
const struct V_39 * V_40 ,
unsigned long V_41 ,
unsigned long V_42 ,
const char * V_43 , int V_25 )
{
struct V_44 V_45 = {} ;
struct V_15 * V_15 ;
const struct V_37 * div ;
const char * V_46 [ V_47 ] ;
char V_48 [ 32 ] ;
int V_49 , V_50 ;
snprintf ( V_48 , sizeof( V_48 ) , V_43 , V_25 ) ;
for ( V_49 = 0 , V_50 = 0 ; V_49 < V_47 ; V_49 ++ ) {
unsigned long V_51 ;
V_27 -> V_35 [ V_49 ] = - 1 ;
div = F_19 ( V_2 , V_27 , V_49 ) ;
if ( ! div )
continue;
V_51 = F_21 ( div -> V_15 ) ;
if ( V_27 -> V_5 -> V_28 [ V_49 ] . V_6 & V_52 &&
V_51 > V_42 )
continue;
if ( V_51 < V_41 )
continue;
V_46 [ V_50 ] = div -> V_48 ;
V_27 -> V_31 [ V_50 ] = V_49 ;
V_27 -> V_35 [ V_49 ] = V_50 ;
V_50 ++ ;
}
V_45 . V_48 = V_48 ;
V_45 . V_40 = V_40 ;
V_45 . V_46 = V_46 ;
V_45 . V_29 = V_27 -> V_29 = V_50 ;
V_45 . V_6 = 0 ;
V_27 -> V_24 . V_45 = & V_45 ;
V_27 -> V_2 = V_2 ;
V_15 = F_22 ( NULL , & V_27 -> V_24 ) ;
if ( F_23 ( V_15 ) ) {
F_18 ( L_2 , V_36 , V_48 ,
F_24 ( V_15 ) ) ;
F_25 ( V_27 ) ;
return NULL ;
}
return V_15 ;
}
static struct V_15 * T_3 F_26 ( struct V_1 * V_2 , int V_25 )
{
struct V_26 * V_27 ;
const struct V_37 * div ;
unsigned long V_53 , V_41 ;
T_6 V_42 ;
T_1 V_28 ;
V_27 = F_27 ( sizeof( * V_27 ) , V_54 ) ;
if ( ! V_27 )
return NULL ;
V_27 -> V_4 = V_2 -> V_55 + 0x20 * V_25 ;
V_27 -> V_5 = V_2 -> V_5 . V_56 [ V_2 -> V_5 . V_57 [ V_25 ] ] ;
V_28 = ( F_4 ( V_2 , V_27 -> V_4 ) & V_33 ) >> V_32 ;
div = F_19 ( V_2 , V_27 , V_28 ) ;
if ( ! div ) {
F_25 ( V_27 ) ;
return NULL ;
}
V_42 = F_21 ( div -> V_15 ) ;
V_42 *= 8 ;
F_28 ( V_42 , 10 ) ;
V_53 = F_21 ( V_2 -> V_12 [ V_16 ] . div [ V_22 ] . V_15 ) ;
if ( V_2 -> V_5 . V_6 & V_58 )
V_41 = V_53 ;
else
V_41 = V_53 / 2 ;
return F_20 ( V_2 , V_27 , & V_59 , V_41 ,
V_42 , L_3 , V_25 ) ;
}
static struct V_15 * T_3 F_29 ( struct V_1 * V_2 , int V_25 )
{
struct V_26 * V_27 ;
V_27 = F_27 ( sizeof( * V_27 ) , V_54 ) ;
if ( ! V_27 )
return NULL ;
V_27 -> V_4 = V_2 -> V_55 + 0x20 * V_25 + 0x10 ;
V_27 -> V_5 = V_2 -> V_5 . V_21 [ V_25 ] ;
return F_20 ( V_2 , V_27 , & V_60 , 0 , 0 ,
L_4 , V_25 ) ;
}
static void T_3 F_30 ( struct V_1 * V_2 )
{
int V_49 ;
for ( V_49 = 0 ; V_49 < F_31 ( V_2 -> V_61 ) ; V_49 ++ ) {
if ( V_2 -> V_5 . V_57 [ V_49 ] < 0 )
break;
if ( V_2 -> V_5 . V_57 [ V_49 ] >=
F_31 ( V_2 -> V_5 . V_56 ) ) {
F_32 ( 1 ) ;
continue;
}
V_2 -> V_61 [ V_49 ] = F_26 ( V_2 , V_49 ) ;
}
for ( V_49 = 0 ; V_49 < F_31 ( V_2 -> V_21 ) ; V_49 ++ ) {
if ( ! V_2 -> V_5 . V_21 [ V_49 ] )
continue;
V_2 -> V_21 [ V_49 ] = F_29 ( V_2 , V_49 ) ;
}
}
static void T_3 F_33 ( struct V_62 * V_63 )
{
if ( ! V_1 . V_64 )
F_34 ( F_35 ( V_63 ) ) ;
}
static void T_3 F_36 ( struct V_62 * V_63 )
{
struct V_15 * V_15 ;
struct V_65 V_66 ;
int V_25 , V_67 ;
F_33 ( V_63 ) ;
if ( F_37 ( V_63 , 0 , & V_66 ) )
return;
V_25 = ( V_66 . V_68 & 0xf0 ) >> 5 ;
V_15 = V_1 . V_61 [ V_25 ] ;
V_67 = F_38 ( V_63 , V_69 , V_15 ) ;
if ( V_67 ) {
F_18 ( L_5 ,
V_36 , V_63 -> V_48 , V_67 ) ;
return;
}
}
static struct V_15 T_3
* F_39 ( struct V_62 * V_64 , const char * V_48 )
{
T_1 V_51 ;
if ( F_40 ( V_64 , L_6 , & V_51 ) )
return F_41 ( - V_70 ) ;
return F_42 ( NULL , V_48 , NULL , 0 , V_51 ) ;
}
static struct V_15 * F_43 ( const char * V_48 )
{
struct V_15 * V_15 ;
const char * V_71 ;
V_15 = F_44 ( V_1 . V_64 , 0 ) ;
if ( F_23 ( V_15 ) )
return V_15 ;
V_71 = F_45 ( V_15 ) ;
V_15 = F_46 ( NULL , V_48 , V_71 ,
0 , 1 , 1 ) ;
if ( F_23 ( V_15 ) )
F_18 ( L_2 , V_36 , V_48 ,
F_24 ( V_15 ) ) ;
return V_15 ;
}
static struct V_15 * T_3 F_47 ( const char * V_48 )
{
struct V_62 * V_72 ;
struct V_15 * V_15 ;
V_15 = F_39 ( V_1 . V_64 , V_48 ) ;
if ( ! F_23 ( V_15 ) )
return V_15 ;
V_15 = F_43 ( V_48 ) ;
if ( ! F_23 ( V_15 ) )
return V_15 ;
V_72 = F_48 ( V_1 . V_64 , L_7 ) ;
if ( V_72 ) {
V_15 = F_39 ( V_72 , V_48 ) ;
if ( ! F_23 ( V_15 ) )
return V_15 ;
}
F_18 ( L_8 , V_36 ) ;
return NULL ;
}
static void T_3 F_49 ( struct V_62 * V_64 )
{
struct V_15 * V_15 ;
F_33 ( V_64 ) ;
V_15 = V_1 . V_72 ;
if ( V_15 )
F_38 ( V_64 , V_69 , V_15 ) ;
}
static void T_3 F_50 ( struct V_1 * V_2 , int V_25 )
{
T_1 T_2 * V_4 ;
T_1 V_73 ;
struct V_74 * V_12 = & V_2 -> V_12 [ V_25 ] ;
int V_49 ;
if ( ! ( V_2 -> V_5 . V_75 & ( 1 << V_25 ) ) )
return;
if ( V_2 -> V_5 . V_6 & V_76 ) {
switch ( V_25 ) {
case V_16 :
V_4 = V_2 -> V_55 + 0x60080 ;
break;
case V_77 :
V_4 = V_2 -> V_55 + 0x80 ;
break;
case V_13 :
V_4 = V_2 -> V_55 + 0xa0 ;
break;
case V_78 :
V_4 = V_2 -> V_55 + 0x10080 ;
break;
case V_79 :
V_4 = V_2 -> V_55 + 0x100a0 ;
break;
default:
F_51 ( 1 , L_9 , V_25 ) ;
return;
}
} else {
if ( V_25 == V_16 )
V_4 = V_2 -> V_55 + 0xc00 ;
else
V_4 = V_2 -> V_55 + 0x800 + 0x20 * ( V_25 - 1 ) ;
}
V_73 = F_4 ( V_2 , V_4 ) ;
if ( V_73 & V_80 ) {
F_52 ( L_10 , V_36 , V_4 ) ;
return;
}
if ( ( V_2 -> V_5 . V_6 & V_76 ) ||
( ( V_2 -> V_5 . V_6 & V_81 ) && V_25 != V_16 ) )
V_73 = ( V_73 & F_53 ( 8 , 1 ) ) >> 1 ;
else
V_73 = ( V_73 & F_53 ( 6 , 1 ) ) >> 1 ;
for ( V_49 = 0 ; V_49 < F_31 ( V_12 -> div ) ; V_49 ++ ) {
struct V_15 * V_15 ;
snprintf ( V_12 -> div [ V_49 ] . V_48 , sizeof( V_12 -> div [ V_49 ] . V_48 ) ,
L_11 , V_25 , V_49 + 1 ) ;
V_15 = F_46 ( NULL ,
V_12 -> div [ V_49 ] . V_48 , L_12 , 0 , V_73 , V_49 + 1 ) ;
if ( F_23 ( V_15 ) ) {
F_18 ( L_13 ,
V_36 , V_12 -> div [ V_49 ] . V_48 , F_24 ( V_15 ) ) ;
continue;
}
V_12 -> div [ V_49 ] . V_15 = V_15 ;
}
}
static void T_3 F_54 ( struct V_1 * V_2 )
{
int V_49 ;
for ( V_49 = 0 ; V_49 < F_31 ( V_2 -> V_12 ) ; V_49 ++ )
F_50 ( V_2 , V_49 ) ;
}
static void T_3 F_55 ( struct V_62 * V_63 , int V_25 )
{
struct V_74 * V_12 ;
struct V_82 * V_83 ;
struct V_15 * * V_84 ;
int V_85 , V_67 ;
F_33 ( V_63 ) ;
V_12 = & V_1 . V_12 [ V_25 ] ;
V_85 = F_56 ( V_63 , L_14 ) ;
F_57 ( F_31 ( V_12 -> div ) < 4 ) ;
V_84 = F_58 ( 4 , sizeof( struct V_15 * ) , V_54 ) ;
if ( ! V_84 )
return;
V_83 = F_59 ( sizeof( * V_83 ) , V_54 ) ;
if ( ! V_83 )
goto V_86;
if ( V_85 <= 3 ) {
V_84 [ 0 ] = V_12 -> div [ 0 ] . V_15 ;
V_84 [ 1 ] = V_12 -> div [ 1 ] . V_15 ;
V_84 [ 2 ] = V_12 -> div [ 3 ] . V_15 ;
} else {
V_84 [ 0 ] = V_12 -> div [ 0 ] . V_15 ;
V_84 [ 1 ] = V_12 -> div [ 1 ] . V_15 ;
V_84 [ 2 ] = V_12 -> div [ 2 ] . V_15 ;
V_84 [ 3 ] = V_12 -> div [ 3 ] . V_15 ;
}
V_83 -> V_87 = V_84 ;
V_83 -> V_88 = V_85 ;
V_67 = F_38 ( V_63 , V_89 , V_83 ) ;
if ( V_67 ) {
F_18 ( L_5 ,
V_36 , V_63 -> V_48 , V_67 ) ;
goto V_90;
}
return;
V_90:
F_25 ( V_83 ) ;
V_86:
F_25 ( V_84 ) ;
}
static void T_3 F_60 ( struct V_62 * V_63 )
{
F_55 ( V_63 , V_16 ) ;
}
static void T_3 F_61 ( struct V_62 * V_63 )
{
struct V_65 V_66 ;
int V_25 ;
if ( F_37 ( V_63 , 0 , & V_66 ) )
return;
if ( ( V_66 . V_68 & 0xfff ) == 0xc00 ) {
F_60 ( V_63 ) ;
} else {
V_25 = ( V_66 . V_68 & 0xf0 ) >> 5 ;
F_55 ( V_63 , V_77 + V_25 ) ;
}
}
static struct V_15 * F_62 ( struct V_91 * V_92 , void * V_93 )
{
struct V_1 * V_2 = V_93 ;
struct V_15 * V_15 ;
struct V_74 * V_12 ;
T_1 type , V_25 ;
if ( V_92 -> V_94 < 2 ) {
F_18 ( L_15 , V_36 ) ;
return F_41 ( - V_30 ) ;
}
type = V_92 -> args [ 0 ] ;
V_25 = V_92 -> args [ 1 ] ;
switch ( type ) {
case 0 :
if ( V_25 != 0 )
goto V_95;
V_15 = V_2 -> V_72 ;
break;
case 1 :
if ( V_25 >= F_31 ( V_2 -> V_61 ) )
goto V_95;
V_15 = V_2 -> V_61 [ V_25 ] ;
break;
case 2 :
if ( V_25 >= F_31 ( V_2 -> V_21 ) )
goto V_95;
V_15 = V_2 -> V_21 [ V_25 ] ;
break;
case 3 :
if ( V_25 >= F_31 ( V_2 -> V_11 ) )
goto V_95;
V_15 = V_2 -> V_11 [ V_25 ] ;
break;
case 4 :
V_12 = & V_2 -> V_12 [ V_16 ] ;
if ( V_25 >= F_31 ( V_12 -> div ) )
goto V_95;
V_15 = V_12 -> div [ V_25 ] . V_15 ;
break;
default:
goto V_95;
}
if ( ! V_15 )
return F_41 ( - V_96 ) ;
return V_15 ;
V_95:
F_18 ( L_16 , V_36 , type , V_25 ) ;
return F_41 ( - V_30 ) ;
}
static bool T_3 F_63 ( void )
{
T_1 V_97 = F_64 ( V_98 ) ;
int V_49 ;
V_97 &= ~ V_99 ;
for ( V_49 = 0 ; V_49 < F_31 ( V_100 ) ; V_49 ++ ) {
if ( V_97 == V_100 [ V_49 ] )
return true ;
}
return false ;
}
static bool T_3 F_63 ( void )
{
return false ;
}
static void T_3 F_34 ( struct V_62 * V_63 )
{
int V_49 , V_34 ;
bool V_101 = false ;
if ( V_1 . V_64 )
return;
V_1 . V_64 = V_63 ;
V_1 . V_55 = F_65 ( V_63 , 0 ) ;
if ( ! V_1 . V_55 &&
F_66 ( V_102 , L_17 ) ) {
V_1 . V_55 = F_67 ( 0x1ee1000 , 0x1000 ) ;
V_101 = true ;
}
if ( ! V_1 . V_55 ) {
F_18 ( L_18 , V_36 , V_63 -> V_48 ) ;
return;
}
for ( V_49 = 0 ; V_49 < F_31 ( V_103 ) ; V_49 ++ ) {
if ( F_66 ( V_63 , V_103 [ V_49 ] . V_104 ) )
break;
if ( V_101 &&
! strcmp ( V_103 [ V_49 ] . V_104 , L_19 ) )
break;
}
if ( V_49 == F_31 ( V_103 ) ) {
F_18 ( L_20 , V_36 ,
V_63 -> V_105 ) ;
goto V_106;
}
V_1 . V_5 = V_103 [ V_49 ] ;
if ( V_1 . V_5 . V_107 ) {
struct V_62 * V_8 ;
V_8 = F_68 ( NULL , NULL ,
V_1 . V_5 . V_107 ) ;
if ( V_8 ) {
V_1 . V_8 = F_65 ( V_8 , 0 ) ;
if ( ! V_1 . V_8 ) {
F_18 ( L_21 , V_36 ,
V_8 -> V_105 ) ;
}
}
}
if ( F_63 () )
V_1 . V_5 . V_6 |= V_58 ;
V_1 . V_72 = F_47 ( L_12 ) ;
F_54 ( & V_1 ) ;
F_30 ( & V_1 ) ;
if ( V_1 . V_5 . V_108 )
V_1 . V_5 . V_108 ( & V_1 ) ;
V_34 = F_38 ( V_63 , F_62 , & V_1 ) ;
if ( V_34 ) {
F_18 ( L_5 ,
V_36 , V_63 -> V_48 , V_34 ) ;
}
return;
V_106:
F_69 ( V_1 . V_55 ) ;
V_1 . V_55 = NULL ;
}
