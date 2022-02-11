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
unsigned long V_43 ,
const char * V_44 , int V_25 )
{
struct V_45 V_46 = {} ;
struct V_15 * V_15 ;
const struct V_37 * div ;
const char * V_47 [ V_48 ] ;
char V_49 [ 32 ] ;
int V_50 , V_51 ;
snprintf ( V_49 , sizeof( V_49 ) , V_44 , V_25 ) ;
for ( V_50 = 0 , V_51 = 0 ; V_50 < V_48 ; V_50 ++ ) {
unsigned long V_52 ;
V_27 -> V_35 [ V_50 ] = - 1 ;
div = F_19 ( V_2 , V_27 , V_50 ) ;
if ( ! div )
continue;
V_52 = F_21 ( div -> V_15 ) ;
if ( V_27 -> V_5 -> V_28 [ V_50 ] . V_6 & V_53 &&
V_52 > V_43 )
continue;
if ( V_52 < V_41 )
continue;
if ( V_52 > V_42 )
continue;
V_47 [ V_51 ] = div -> V_49 ;
V_27 -> V_31 [ V_51 ] = V_50 ;
V_27 -> V_35 [ V_50 ] = V_51 ;
V_51 ++ ;
}
V_46 . V_49 = V_49 ;
V_46 . V_40 = V_40 ;
V_46 . V_47 = V_47 ;
V_46 . V_29 = V_27 -> V_29 = V_51 ;
V_46 . V_6 = 0 ;
V_27 -> V_24 . V_46 = & V_46 ;
V_27 -> V_2 = V_2 ;
V_15 = F_22 ( NULL , & V_27 -> V_24 ) ;
if ( F_23 ( V_15 ) ) {
F_18 ( L_2 , V_36 , V_49 ,
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
unsigned long V_54 , V_41 ;
T_6 V_42 , V_43 ;
T_1 V_28 ;
V_27 = F_27 ( sizeof( * V_27 ) , V_55 ) ;
if ( ! V_27 )
return NULL ;
if ( V_2 -> V_5 . V_6 & V_56 )
V_27 -> V_4 = V_2 -> V_57 + 0x70000 + 0x20 * V_25 ;
else
V_27 -> V_4 = V_2 -> V_57 + 0x20 * V_25 ;
V_27 -> V_5 = V_2 -> V_5 . V_58 [ V_2 -> V_5 . V_59 [ V_25 ] ] ;
V_28 = ( F_4 ( V_2 , V_27 -> V_4 ) & V_33 ) >> V_32 ;
div = F_19 ( V_2 , V_27 , V_28 ) ;
if ( ! div ) {
F_25 ( V_27 ) ;
return NULL ;
}
V_42 = F_21 ( div -> V_15 ) ;
V_43 = V_42 * 8 ;
F_28 ( V_43 , 10 ) ;
V_54 = F_21 ( V_2 -> V_12 [ V_16 ] . div [ V_22 ] . V_15 ) ;
if ( V_2 -> V_5 . V_6 & V_60 )
V_41 = V_54 ;
else
V_41 = V_54 / 2 ;
return F_20 ( V_2 , V_27 , & V_61 , V_41 , V_42 ,
V_43 , L_3 , V_25 ) ;
}
static struct V_15 * T_3 F_29 ( struct V_1 * V_2 , int V_25 )
{
struct V_26 * V_27 ;
V_27 = F_27 ( sizeof( * V_27 ) , V_55 ) ;
if ( ! V_27 )
return NULL ;
V_27 -> V_4 = V_2 -> V_57 + 0x20 * V_25 + 0x10 ;
V_27 -> V_5 = V_2 -> V_5 . V_21 [ V_25 ] ;
return F_20 ( V_2 , V_27 , & V_62 , 0 , V_63 , 0 ,
L_4 , V_25 ) ;
}
static void T_3 F_30 ( struct V_1 * V_2 )
{
int V_50 ;
for ( V_50 = 0 ; V_50 < F_31 ( V_2 -> V_64 ) ; V_50 ++ ) {
if ( V_2 -> V_5 . V_59 [ V_50 ] < 0 )
break;
if ( V_2 -> V_5 . V_59 [ V_50 ] >=
F_31 ( V_2 -> V_5 . V_58 ) ) {
F_32 ( 1 ) ;
continue;
}
V_2 -> V_64 [ V_50 ] = F_26 ( V_2 , V_50 ) ;
}
for ( V_50 = 0 ; V_50 < F_31 ( V_2 -> V_21 ) ; V_50 ++ ) {
if ( ! V_2 -> V_5 . V_21 [ V_50 ] )
continue;
V_2 -> V_21 [ V_50 ] = F_29 ( V_2 , V_50 ) ;
}
}
static void T_3 F_33 ( struct V_65 * V_66 )
{
if ( ! V_1 . V_67 )
F_34 ( F_35 ( V_66 ) ) ;
}
static void T_3 F_36 ( struct V_65 * V_66 )
{
struct V_15 * V_15 ;
struct V_68 V_69 ;
int V_25 , V_70 ;
F_33 ( V_66 ) ;
if ( F_37 ( V_66 , 0 , & V_69 ) )
return;
V_25 = ( V_69 . V_71 & 0xf0 ) >> 5 ;
V_15 = V_1 . V_64 [ V_25 ] ;
V_70 = F_38 ( V_66 , V_72 , V_15 ) ;
if ( V_70 ) {
F_18 ( L_5 ,
V_36 , V_66 -> V_49 , V_70 ) ;
return;
}
}
static struct V_15 T_3
* F_39 ( struct V_65 * V_67 , const char * V_49 )
{
T_1 V_52 ;
if ( F_40 ( V_67 , L_6 , & V_52 ) )
return F_41 ( - V_73 ) ;
return F_42 ( NULL , V_49 , NULL , 0 , V_52 ) ;
}
static struct V_15 * F_43 ( const char * V_49 )
{
struct V_15 * V_15 ;
const char * V_74 ;
V_15 = F_44 ( V_1 . V_67 , 0 ) ;
if ( F_23 ( V_15 ) )
return V_15 ;
V_74 = F_45 ( V_15 ) ;
V_15 = F_46 ( NULL , V_49 , V_74 ,
0 , 1 , 1 ) ;
if ( F_23 ( V_15 ) )
F_18 ( L_2 , V_36 , V_49 ,
F_24 ( V_15 ) ) ;
return V_15 ;
}
static struct V_15 * T_3 F_47 ( const char * V_49 )
{
struct V_65 * V_75 ;
struct V_15 * V_15 ;
V_15 = F_39 ( V_1 . V_67 , V_49 ) ;
if ( ! F_23 ( V_15 ) )
return V_15 ;
V_15 = F_43 ( V_49 ) ;
if ( ! F_23 ( V_15 ) )
return V_15 ;
V_75 = F_48 ( V_1 . V_67 , L_7 ) ;
if ( V_75 ) {
V_15 = F_39 ( V_75 , V_49 ) ;
if ( ! F_23 ( V_15 ) )
return V_15 ;
}
F_18 ( L_8 , V_36 ) ;
return NULL ;
}
static void T_3 F_49 ( struct V_65 * V_67 )
{
struct V_15 * V_15 ;
F_33 ( V_67 ) ;
V_15 = V_1 . V_75 ;
if ( V_15 )
F_38 ( V_67 , V_72 , V_15 ) ;
}
static void T_3 F_50 ( struct V_1 * V_2 , int V_25 )
{
T_1 T_2 * V_4 ;
T_1 V_76 ;
struct V_77 * V_12 = & V_2 -> V_12 [ V_25 ] ;
int V_50 ;
if ( ! ( V_2 -> V_5 . V_78 & ( 1 << V_25 ) ) )
return;
if ( V_2 -> V_5 . V_6 & V_56 ) {
switch ( V_25 ) {
case V_16 :
V_4 = V_2 -> V_57 + 0x60080 ;
break;
case V_79 :
V_4 = V_2 -> V_57 + 0x80 ;
break;
case V_13 :
V_4 = V_2 -> V_57 + 0xa0 ;
break;
case V_80 :
V_4 = V_2 -> V_57 + 0x10080 ;
break;
case V_81 :
V_4 = V_2 -> V_57 + 0x100a0 ;
break;
default:
F_51 ( 1 , L_9 , V_25 ) ;
return;
}
} else {
if ( V_25 == V_16 )
V_4 = V_2 -> V_57 + 0xc00 ;
else
V_4 = V_2 -> V_57 + 0x800 + 0x20 * ( V_25 - 1 ) ;
}
V_76 = F_4 ( V_2 , V_4 ) ;
if ( V_76 & V_82 ) {
F_52 ( L_10 , V_36 , V_4 ) ;
return;
}
if ( ( V_2 -> V_5 . V_6 & V_56 ) ||
( ( V_2 -> V_5 . V_6 & V_83 ) && V_25 != V_16 ) )
V_76 = ( V_76 & F_53 ( 8 , 1 ) ) >> 1 ;
else
V_76 = ( V_76 & F_53 ( 6 , 1 ) ) >> 1 ;
for ( V_50 = 0 ; V_50 < F_31 ( V_12 -> div ) ; V_50 ++ ) {
struct V_15 * V_15 ;
snprintf ( V_12 -> div [ V_50 ] . V_49 , sizeof( V_12 -> div [ V_50 ] . V_49 ) ,
L_11 , V_25 , V_50 + 1 ) ;
V_15 = F_46 ( NULL ,
V_12 -> div [ V_50 ] . V_49 , L_12 , 0 , V_76 , V_50 + 1 ) ;
if ( F_23 ( V_15 ) ) {
F_18 ( L_13 ,
V_36 , V_12 -> div [ V_50 ] . V_49 , F_24 ( V_15 ) ) ;
continue;
}
V_12 -> div [ V_50 ] . V_15 = V_15 ;
}
}
static void T_3 F_54 ( struct V_1 * V_2 )
{
int V_50 ;
for ( V_50 = 0 ; V_50 < F_31 ( V_2 -> V_12 ) ; V_50 ++ )
F_50 ( V_2 , V_50 ) ;
}
static void T_3 F_55 ( struct V_65 * V_66 , int V_25 )
{
struct V_77 * V_12 ;
struct V_84 * V_85 ;
struct V_15 * * V_86 ;
int V_87 , V_70 ;
F_33 ( V_66 ) ;
V_12 = & V_1 . V_12 [ V_25 ] ;
V_87 = F_56 ( V_66 , L_14 ) ;
F_57 ( F_31 ( V_12 -> div ) < 4 ) ;
V_86 = F_58 ( 4 , sizeof( struct V_15 * ) , V_55 ) ;
if ( ! V_86 )
return;
V_85 = F_59 ( sizeof( * V_85 ) , V_55 ) ;
if ( ! V_85 )
goto V_88;
if ( V_87 <= 3 ) {
V_86 [ 0 ] = V_12 -> div [ 0 ] . V_15 ;
V_86 [ 1 ] = V_12 -> div [ 1 ] . V_15 ;
V_86 [ 2 ] = V_12 -> div [ 3 ] . V_15 ;
} else {
V_86 [ 0 ] = V_12 -> div [ 0 ] . V_15 ;
V_86 [ 1 ] = V_12 -> div [ 1 ] . V_15 ;
V_86 [ 2 ] = V_12 -> div [ 2 ] . V_15 ;
V_86 [ 3 ] = V_12 -> div [ 3 ] . V_15 ;
}
V_85 -> V_89 = V_86 ;
V_85 -> V_90 = V_87 ;
V_70 = F_38 ( V_66 , V_91 , V_85 ) ;
if ( V_70 ) {
F_18 ( L_5 ,
V_36 , V_66 -> V_49 , V_70 ) ;
goto V_92;
}
return;
V_92:
F_25 ( V_85 ) ;
V_88:
F_25 ( V_86 ) ;
}
static void T_3 F_60 ( struct V_65 * V_66 )
{
F_55 ( V_66 , V_16 ) ;
}
static void T_3 F_61 ( struct V_65 * V_66 )
{
struct V_68 V_69 ;
int V_25 ;
if ( F_37 ( V_66 , 0 , & V_69 ) )
return;
if ( ( V_69 . V_71 & 0xfff ) == 0xc00 ) {
F_60 ( V_66 ) ;
} else {
V_25 = ( V_69 . V_71 & 0xf0 ) >> 5 ;
F_55 ( V_66 , V_79 + V_25 ) ;
}
}
static struct V_15 * F_62 ( struct V_93 * V_94 , void * V_95 )
{
struct V_1 * V_2 = V_95 ;
struct V_15 * V_15 ;
struct V_77 * V_12 ;
T_1 type , V_25 ;
if ( V_94 -> V_96 < 2 ) {
F_18 ( L_15 , V_36 ) ;
return F_41 ( - V_30 ) ;
}
type = V_94 -> args [ 0 ] ;
V_25 = V_94 -> args [ 1 ] ;
switch ( type ) {
case 0 :
if ( V_25 != 0 )
goto V_97;
V_15 = V_2 -> V_75 ;
break;
case 1 :
if ( V_25 >= F_31 ( V_2 -> V_64 ) )
goto V_97;
V_15 = V_2 -> V_64 [ V_25 ] ;
break;
case 2 :
if ( V_25 >= F_31 ( V_2 -> V_21 ) )
goto V_97;
V_15 = V_2 -> V_21 [ V_25 ] ;
break;
case 3 :
if ( V_25 >= F_31 ( V_2 -> V_11 ) )
goto V_97;
V_15 = V_2 -> V_11 [ V_25 ] ;
break;
case 4 :
V_12 = & V_2 -> V_12 [ V_16 ] ;
if ( V_25 >= F_31 ( V_12 -> div ) )
goto V_97;
V_15 = V_12 -> div [ V_25 ] . V_15 ;
break;
default:
goto V_97;
}
if ( ! V_15 )
return F_41 ( - V_98 ) ;
return V_15 ;
V_97:
F_18 ( L_16 , V_36 , type , V_25 ) ;
return F_41 ( - V_30 ) ;
}
static bool T_3 F_63 ( void )
{
T_1 V_99 = F_64 ( V_100 ) ;
int V_50 ;
V_99 &= ~ V_101 ;
for ( V_50 = 0 ; V_50 < F_31 ( V_102 ) ; V_50 ++ ) {
if ( V_99 == V_102 [ V_50 ] )
return true ;
}
return false ;
}
static bool T_3 F_63 ( void )
{
return false ;
}
static void T_3 F_34 ( struct V_65 * V_66 )
{
int V_50 , V_34 ;
bool V_103 = false ;
if ( V_1 . V_67 )
return;
V_1 . V_67 = V_66 ;
V_1 . V_57 = F_65 ( V_66 , 0 ) ;
if ( ! V_1 . V_57 &&
F_66 ( V_104 , L_17 ) ) {
V_1 . V_57 = F_67 ( 0x1ee1000 , 0x1000 ) ;
V_103 = true ;
}
if ( ! V_1 . V_57 ) {
F_18 ( L_18 , V_36 , V_66 -> V_49 ) ;
return;
}
for ( V_50 = 0 ; V_50 < F_31 ( V_105 ) ; V_50 ++ ) {
if ( F_66 ( V_66 , V_105 [ V_50 ] . V_106 ) )
break;
if ( V_103 &&
! strcmp ( V_105 [ V_50 ] . V_106 , L_19 ) )
break;
}
if ( V_50 == F_31 ( V_105 ) ) {
F_18 ( L_20 , V_36 ,
V_66 -> V_107 ) ;
goto V_108;
}
V_1 . V_5 = V_105 [ V_50 ] ;
if ( V_1 . V_5 . V_109 ) {
struct V_65 * V_8 ;
V_8 = F_68 ( NULL , NULL ,
V_1 . V_5 . V_109 ) ;
if ( V_8 ) {
V_1 . V_8 = F_65 ( V_8 , 0 ) ;
if ( ! V_1 . V_8 ) {
F_18 ( L_21 , V_36 ,
V_8 -> V_107 ) ;
}
}
}
if ( F_63 () )
V_1 . V_5 . V_6 |= V_60 ;
V_1 . V_75 = F_47 ( L_12 ) ;
F_54 ( & V_1 ) ;
F_30 ( & V_1 ) ;
if ( V_1 . V_5 . V_110 )
V_1 . V_5 . V_110 ( & V_1 ) ;
V_34 = F_38 ( V_66 , F_62 , & V_1 ) ;
if ( V_34 ) {
F_18 ( L_5 ,
V_36 , V_66 -> V_49 , V_34 ) ;
}
return;
V_108:
F_69 ( V_1 . V_57 ) ;
V_1 . V_57 = NULL ;
}
