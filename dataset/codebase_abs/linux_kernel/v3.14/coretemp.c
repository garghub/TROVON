static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
return sprintf ( V_5 , L_1 , V_6 ) ;
}
static T_1 F_2 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_7 * V_8 = F_3 ( V_4 ) ;
struct V_9 * V_10 = F_4 ( V_2 ) ;
struct V_11 * V_12 = V_10 -> V_13 [ V_8 -> V_14 ] ;
if ( V_12 -> V_15 )
return sprintf ( V_5 , L_2 , V_10 -> V_16 ) ;
return sprintf ( V_5 , L_3 , V_12 -> V_17 ) ;
}
static T_1 F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
T_2 V_18 , V_19 ;
struct V_7 * V_8 = F_3 ( V_4 ) ;
struct V_9 * V_10 = F_4 ( V_2 ) ;
struct V_11 * V_12 = V_10 -> V_13 [ V_8 -> V_14 ] ;
F_6 ( V_12 -> V_20 , V_12 -> V_21 , & V_18 , & V_19 ) ;
return sprintf ( V_5 , L_4 , ( V_18 >> 5 ) & 1 ) ;
}
static T_1 F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_7 * V_8 = F_3 ( V_4 ) ;
struct V_9 * V_10 = F_4 ( V_2 ) ;
return sprintf ( V_5 , L_4 , V_10 -> V_13 [ V_8 -> V_14 ] -> V_22 ) ;
}
static T_1 F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_7 * V_8 = F_3 ( V_4 ) ;
struct V_9 * V_10 = F_4 ( V_2 ) ;
return sprintf ( V_5 , L_4 , V_10 -> V_13 [ V_8 -> V_14 ] -> V_23 ) ;
}
static T_1 F_9 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
T_2 V_18 , V_19 ;
struct V_7 * V_8 = F_3 ( V_4 ) ;
struct V_9 * V_10 = F_4 ( V_2 ) ;
struct V_11 * V_12 = V_10 -> V_13 [ V_8 -> V_14 ] ;
F_10 ( & V_12 -> V_24 ) ;
if ( ! V_12 -> V_25 || F_11 ( V_26 , V_12 -> V_27 + V_28 ) ) {
F_6 ( V_12 -> V_20 , V_12 -> V_21 , & V_18 , & V_19 ) ;
V_12 -> V_29 = V_12 -> V_22 - ( ( V_18 >> 16 ) & 0x7f ) * 1000 ;
V_12 -> V_25 = 1 ;
V_12 -> V_27 = V_26 ;
}
F_12 ( & V_12 -> V_24 ) ;
return sprintf ( V_5 , L_4 , V_12 -> V_29 ) ;
}
static int F_13 ( struct V_30 * V_31 , T_2 V_32 , struct V_1 * V_2 )
{
int V_22 = 100000 ;
int V_33 = 85000 ;
int V_34 = 1 ;
int V_35 ;
T_2 V_18 , V_19 ;
int V_36 ;
struct V_37 * V_38 = F_14 ( 0 , F_15 ( 0 , 0 ) ) ;
if ( V_38 && V_38 -> V_39 == V_40 ) {
for ( V_36 = 0 ; V_36 < F_16 ( V_41 ) ; V_36 ++ ) {
if ( V_38 -> V_1 == V_41 [ V_36 ] . V_1 )
return V_41 [ V_36 ] . V_22 ;
}
}
for ( V_36 = 0 ; V_36 < F_16 ( V_42 ) ; V_36 ++ ) {
if ( strstr ( V_31 -> V_43 , V_42 [ V_36 ] . V_32 ) )
return V_42 [ V_36 ] . V_22 ;
}
for ( V_36 = 0 ; V_36 < F_16 ( V_44 ) ; V_36 ++ ) {
const struct V_45 * V_46 = & V_44 [ V_36 ] ;
if ( V_31 -> V_47 == V_46 -> V_48 &&
( V_46 -> V_49 == V_50 || V_31 -> V_51 == V_46 -> V_49 ) )
return V_46 -> V_22 ;
}
if ( V_31 -> V_47 == 0xf && V_31 -> V_51 < 4 )
V_34 = 0 ;
if ( V_31 -> V_47 > 0xe && V_34 ) {
T_3 V_52 ;
V_35 = F_17 ( V_32 , 0x17 , & V_18 , & V_19 ) ;
if ( V_35 ) {
F_18 ( V_2 ,
L_5
L_6 ) ;
V_34 = 0 ;
} else if ( V_31 -> V_47 < 0x17 && ! ( V_18 & 0x10000000 ) ) {
V_34 = 0 ;
} else {
V_52 = ( V_19 >> 18 ) & 0x7 ;
if ( V_31 -> V_47 == 0x17 &&
( V_52 == 5 || V_52 == 7 ) ) {
V_33 = 90000 ;
V_22 = 105000 ;
}
}
}
if ( V_34 ) {
V_35 = F_17 ( V_32 , 0xee , & V_18 , & V_19 ) ;
if ( V_35 ) {
F_18 ( V_2 ,
L_7
L_8 ) ;
} else if ( V_18 & 0x40000000 ) {
V_22 = V_33 ;
}
} else if ( V_22 == 100000 ) {
F_18 ( V_2 , L_9 ) ;
}
return V_22 ;
}
static bool F_19 ( struct V_30 * V_31 )
{
T_3 V_48 = V_31 -> V_47 ;
return V_48 > 0xe &&
V_48 != 0x1c &&
V_48 != 0x26 &&
V_48 != 0x27 &&
V_48 != 0x35 &&
V_48 != 0x36 ;
}
static int F_20 ( struct V_30 * V_31 , T_2 V_32 , struct V_1 * V_2 )
{
int V_35 ;
T_2 V_18 , V_19 ;
T_2 V_53 ;
V_35 = F_17 ( V_32 , V_54 , & V_18 , & V_19 ) ;
if ( V_35 ) {
if ( F_19 ( V_31 ) )
F_18 ( V_2 , L_10 , V_32 ) ;
} else {
V_53 = ( V_18 >> 16 ) & 0x7f ;
if ( V_53 >= 85 ) {
F_21 ( V_2 , L_11 , V_53 ) ;
return V_53 * 1000 ;
}
}
if ( V_55 ) {
F_22 ( V_2 , L_12 ,
V_55 ) ;
return V_55 * 1000 ;
}
return F_13 ( V_31 , V_32 , V_2 ) ;
}
static int F_23 ( struct V_9 * V_10 ,
struct V_1 * V_2 )
{
F_24 ( & V_10 -> V_56 . V_8 ) ;
V_10 -> V_56 . V_8 . V_57 = L_13 ;
V_10 -> V_56 . V_8 . V_58 = V_59 ;
V_10 -> V_56 . V_60 = F_1 ;
return F_25 ( V_2 , & V_10 -> V_56 ) ;
}
static int F_26 ( struct V_11 * V_12 , struct V_1 * V_2 ,
int V_61 )
{
int V_35 , V_36 ;
static T_1 ( * const V_62 [ V_63 ] ) ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 ) = {
F_2 , F_5 , F_9 , F_7 ,
F_8 } ;
static const char * const V_64 [ V_63 ] = {
L_14 , L_15 ,
L_16 , L_17 ,
L_18 } ;
for ( V_36 = 0 ; V_36 < V_12 -> V_65 ; V_36 ++ ) {
snprintf ( V_12 -> V_66 [ V_36 ] , V_67 , V_64 [ V_36 ] ,
V_61 ) ;
F_24 ( & V_12 -> V_68 [ V_36 ] . V_69 . V_8 ) ;
V_12 -> V_68 [ V_36 ] . V_69 . V_8 . V_57 = V_12 -> V_66 [ V_36 ] ;
V_12 -> V_68 [ V_36 ] . V_69 . V_8 . V_58 = V_59 ;
V_12 -> V_68 [ V_36 ] . V_69 . V_60 = V_62 [ V_36 ] ;
V_12 -> V_68 [ V_36 ] . V_14 = V_61 ;
V_35 = F_25 ( V_2 , & V_12 -> V_68 [ V_36 ] . V_69 ) ;
if ( V_35 )
goto V_70;
}
return 0 ;
V_70:
while ( -- V_36 >= 0 )
F_27 ( V_2 , & V_12 -> V_68 [ V_36 ] . V_69 ) ;
return V_35 ;
}
static int F_28 ( unsigned int V_20 )
{
struct V_30 * V_31 = & F_29 ( V_20 ) ;
if ( V_31 -> V_47 == 0xe && V_31 -> V_51 < 0xc && V_31 -> V_71 < 0x39 ) {
F_30 ( L_19 ) ;
return - V_72 ;
}
return 0 ;
}
static struct V_73 * F_31 ( unsigned int V_20 )
{
T_4 V_16 = F_32 ( V_20 ) ;
struct V_74 * V_75 ;
F_10 ( & V_76 ) ;
F_33 (p, &pdev_list, list)
if ( V_75 -> V_16 == V_16 ) {
F_12 ( & V_76 ) ;
return V_75 -> V_77 ;
}
F_12 ( & V_76 ) ;
return NULL ;
}
static struct V_11 * F_34 ( unsigned int V_20 , int V_78 )
{
struct V_11 * V_12 ;
V_12 = F_35 ( sizeof( struct V_11 ) , V_79 ) ;
if ( ! V_12 )
return NULL ;
V_12 -> V_21 = V_78 ? V_80 :
V_81 ;
V_12 -> V_15 = V_78 ;
V_12 -> V_20 = V_20 ;
V_12 -> V_17 = F_36 ( V_20 ) ;
V_12 -> V_65 = V_82 ;
F_37 ( & V_12 -> V_24 ) ;
return V_12 ;
}
static int F_38 ( struct V_73 * V_77 , unsigned int V_20 ,
int V_78 )
{
struct V_11 * V_12 ;
struct V_9 * V_10 = F_39 ( V_77 ) ;
struct V_30 * V_31 = & F_29 ( V_20 ) ;
T_2 V_18 , V_19 ;
int V_35 , V_61 ;
V_61 = V_78 ? 1 : F_40 ( V_20 ) ;
if ( V_61 > V_83 - 1 )
return - V_84 ;
if ( V_10 -> V_13 [ V_61 ] != NULL )
return 0 ;
V_12 = F_34 ( V_20 , V_78 ) ;
if ( ! V_12 )
return - V_85 ;
V_35 = F_17 ( V_20 , V_12 -> V_21 , & V_18 , & V_19 ) ;
if ( V_35 )
goto V_70;
V_12 -> V_22 = F_20 ( V_31 , V_20 , & V_77 -> V_2 ) ;
if ( V_31 -> V_47 > 0xe && V_31 -> V_47 != 0x1c ) {
V_35 = F_17 ( V_20 , V_54 ,
& V_18 , & V_19 ) ;
if ( ! V_35 ) {
V_12 -> V_23
= V_12 -> V_22 - ( ( V_18 >> 8 ) & 0xff ) * 1000 ;
V_12 -> V_65 ++ ;
}
}
V_10 -> V_13 [ V_61 ] = V_12 ;
V_35 = F_26 ( V_12 , & V_77 -> V_2 , V_61 ) ;
if ( V_35 )
goto V_70;
return 0 ;
V_70:
V_10 -> V_13 [ V_61 ] = NULL ;
F_41 ( V_12 ) ;
return V_35 ;
}
static void F_42 ( unsigned int V_20 , int V_78 )
{
struct V_73 * V_77 = F_31 ( V_20 ) ;
int V_35 ;
if ( ! V_77 )
return;
V_35 = F_38 ( V_77 , V_20 , V_78 ) ;
if ( V_35 )
F_43 ( & V_77 -> V_2 , L_20 , V_20 ) ;
}
static void F_44 ( struct V_9 * V_10 ,
struct V_1 * V_2 , int V_86 )
{
int V_36 ;
struct V_11 * V_12 = V_10 -> V_13 [ V_86 ] ;
for ( V_36 = 0 ; V_36 < V_12 -> V_65 ; V_36 ++ )
F_27 ( V_2 , & V_12 -> V_68 [ V_36 ] . V_69 ) ;
F_41 ( V_10 -> V_13 [ V_86 ] ) ;
V_10 -> V_13 [ V_86 ] = NULL ;
}
static int F_45 ( struct V_73 * V_77 )
{
struct V_9 * V_10 ;
int V_35 ;
V_10 = F_35 ( sizeof( struct V_9 ) , V_79 ) ;
if ( ! V_10 )
return - V_85 ;
V_35 = F_23 ( V_10 , & V_77 -> V_2 ) ;
if ( V_35 )
goto V_70;
V_10 -> V_16 = V_77 -> V_32 ;
F_46 ( V_77 , V_10 ) ;
V_10 -> V_87 = F_47 ( & V_77 -> V_2 ) ;
if ( F_48 ( V_10 -> V_87 ) ) {
V_35 = F_49 ( V_10 -> V_87 ) ;
F_43 ( & V_77 -> V_2 , L_21 , V_35 ) ;
goto V_88;
}
return 0 ;
V_88:
F_27 ( & V_77 -> V_2 , & V_10 -> V_56 ) ;
V_70:
F_41 ( V_10 ) ;
return V_35 ;
}
static int F_50 ( struct V_73 * V_77 )
{
struct V_9 * V_10 = F_39 ( V_77 ) ;
int V_36 ;
for ( V_36 = V_83 - 1 ; V_36 >= 0 ; -- V_36 )
if ( V_10 -> V_13 [ V_36 ] )
F_44 ( V_10 , & V_77 -> V_2 , V_36 ) ;
F_27 ( & V_77 -> V_2 , & V_10 -> V_56 ) ;
F_51 ( V_10 -> V_87 ) ;
F_41 ( V_10 ) ;
return 0 ;
}
static int F_52 ( unsigned int V_20 )
{
int V_35 ;
struct V_73 * V_77 ;
struct V_74 * V_74 ;
F_10 ( & V_76 ) ;
V_77 = F_53 ( V_6 , F_32 ( V_20 ) ) ;
if ( ! V_77 ) {
V_35 = - V_85 ;
F_30 ( L_22 ) ;
goto exit;
}
V_74 = F_35 ( sizeof( struct V_74 ) , V_79 ) ;
if ( ! V_74 ) {
V_35 = - V_85 ;
goto V_89;
}
V_35 = F_54 ( V_77 ) ;
if ( V_35 ) {
F_30 ( L_23 , V_35 ) ;
goto V_90;
}
V_74 -> V_77 = V_77 ;
V_74 -> V_16 = V_77 -> V_32 ;
F_55 ( & V_74 -> V_91 , & V_92 ) ;
F_12 ( & V_76 ) ;
return 0 ;
V_90:
F_41 ( V_74 ) ;
V_89:
F_56 ( V_77 ) ;
exit:
F_12 ( & V_76 ) ;
return V_35 ;
}
static void F_57 ( unsigned int V_20 )
{
struct V_74 * V_75 , * V_93 ;
T_4 V_16 = F_32 ( V_20 ) ;
F_10 ( & V_76 ) ;
F_58 (p, n, &pdev_list, list) {
if ( V_75 -> V_16 != V_16 )
continue;
F_59 ( V_75 -> V_77 ) ;
F_60 ( & V_75 -> V_91 ) ;
F_41 ( V_75 ) ;
}
F_12 ( & V_76 ) ;
}
static bool F_61 ( struct V_9 * V_10 )
{
int V_36 ;
for ( V_36 = V_83 - 1 ; V_36 >= 0 ; -- V_36 ) {
if ( V_10 -> V_13 [ V_36 ] &&
! V_10 -> V_13 [ V_36 ] -> V_15 ) {
return true ;
}
}
return false ;
}
static void F_62 ( unsigned int V_20 )
{
struct V_30 * V_31 = & F_29 ( V_20 ) ;
struct V_73 * V_77 = F_31 ( V_20 ) ;
int V_35 ;
if ( ! F_63 ( V_31 , V_94 ) )
return;
if ( ! V_77 ) {
if ( F_28 ( V_20 ) )
return;
V_35 = F_52 ( V_20 ) ;
if ( V_35 )
return;
if ( F_63 ( V_31 , V_95 ) )
F_42 ( V_20 , 1 ) ;
}
F_42 ( V_20 , 0 ) ;
}
static void F_64 ( unsigned int V_20 )
{
int V_36 , V_86 ;
struct V_9 * V_10 ;
struct V_73 * V_77 = F_31 ( V_20 ) ;
if ( ! V_77 )
return;
V_10 = F_39 ( V_77 ) ;
V_86 = F_40 ( V_20 ) ;
if ( V_86 > V_83 - 1 )
return;
if ( V_10 -> V_13 [ V_86 ] && V_10 -> V_13 [ V_86 ] -> V_20 == V_20 )
F_44 ( V_10 , & V_77 -> V_2 , V_86 ) ;
F_65 (i, cpu) {
if ( V_36 != V_20 ) {
F_62 ( V_36 ) ;
break;
}
}
if ( ! F_61 ( V_10 ) )
F_57 ( V_20 ) ;
}
static int F_66 ( struct V_96 * V_97 ,
unsigned long V_98 , void * V_99 )
{
unsigned int V_20 = ( unsigned long ) V_99 ;
switch ( V_98 ) {
case V_100 :
case V_101 :
F_62 ( V_20 ) ;
break;
case V_102 :
F_64 ( V_20 ) ;
break;
}
return V_103 ;
}
static int T_5 F_67 ( void )
{
int V_36 , V_35 ;
if ( ! F_68 ( V_104 ) )
return - V_72 ;
V_35 = F_69 ( & V_105 ) ;
if ( V_35 )
goto exit;
F_70 () ;
F_71 (i)
F_62 ( V_36 ) ;
#ifndef F_72
if ( F_73 ( & V_92 ) ) {
F_74 () ;
V_35 = - V_72 ;
goto V_106;
}
#endif
F_75 ( & V_107 ) ;
F_74 () ;
return 0 ;
#ifndef F_72
V_106:
F_76 ( & V_105 ) ;
#endif
exit:
return V_35 ;
}
static void T_6 F_77 ( void )
{
struct V_74 * V_75 , * V_93 ;
F_70 () ;
F_78 ( & V_107 ) ;
F_10 ( & V_76 ) ;
F_58 (p, n, &pdev_list, list) {
F_59 ( V_75 -> V_77 ) ;
F_60 ( & V_75 -> V_91 ) ;
F_41 ( V_75 ) ;
}
F_12 ( & V_76 ) ;
F_74 () ;
F_76 ( & V_105 ) ;
}
