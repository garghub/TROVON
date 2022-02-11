static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
struct V_8 * V_9 = F_3 ( V_2 ) ;
struct V_10 * V_11 = V_9 -> V_12 [ V_7 -> V_13 ] ;
if ( V_11 -> V_14 )
return sprintf ( V_5 , L_1 , V_9 -> V_15 ) ;
return sprintf ( V_5 , L_2 , V_11 -> V_16 ) ;
}
static T_1 F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
T_2 V_17 , V_18 ;
struct V_6 * V_7 = F_2 ( V_4 ) ;
struct V_8 * V_9 = F_3 ( V_2 ) ;
struct V_10 * V_11 = V_9 -> V_12 [ V_7 -> V_13 ] ;
F_5 ( V_11 -> V_19 , V_11 -> V_20 , & V_17 , & V_18 ) ;
return sprintf ( V_5 , L_3 , ( V_17 >> 5 ) & 1 ) ;
}
static T_1 F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
struct V_8 * V_9 = F_3 ( V_2 ) ;
return sprintf ( V_5 , L_3 , V_9 -> V_12 [ V_7 -> V_13 ] -> V_21 ) ;
}
static T_1 F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
struct V_8 * V_9 = F_3 ( V_2 ) ;
return sprintf ( V_5 , L_3 , V_9 -> V_12 [ V_7 -> V_13 ] -> V_22 ) ;
}
static T_1 F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
T_2 V_17 , V_18 ;
struct V_6 * V_7 = F_2 ( V_4 ) ;
struct V_8 * V_9 = F_3 ( V_2 ) ;
struct V_10 * V_11 = V_9 -> V_12 [ V_7 -> V_13 ] ;
F_9 ( & V_11 -> V_23 ) ;
if ( ! V_11 -> V_24 || F_10 ( V_25 , V_11 -> V_26 + V_27 ) ) {
F_5 ( V_11 -> V_19 , V_11 -> V_20 , & V_17 , & V_18 ) ;
V_11 -> V_28 = V_11 -> V_21 - ( ( V_17 >> 16 ) & 0x7f ) * 1000 ;
V_11 -> V_24 = 1 ;
V_11 -> V_26 = V_25 ;
}
F_11 ( & V_11 -> V_23 ) ;
return sprintf ( V_5 , L_3 , V_11 -> V_28 ) ;
}
static int F_12 ( struct V_29 * V_30 , T_2 V_31 , struct V_1 * V_2 )
{
int V_21 = 100000 ;
int V_32 = 85000 ;
int V_33 = 1 ;
int V_34 ;
T_2 V_17 , V_18 ;
int V_35 ;
struct V_36 * V_37 = F_13 ( 0 , F_14 ( 0 , 0 ) ) ;
if ( V_37 && V_37 -> V_38 == V_39 ) {
for ( V_35 = 0 ; V_35 < F_15 ( V_40 ) ; V_35 ++ ) {
if ( V_37 -> V_1 == V_40 [ V_35 ] . V_1 )
return V_40 [ V_35 ] . V_21 ;
}
}
for ( V_35 = 0 ; V_35 < F_15 ( V_41 ) ; V_35 ++ ) {
if ( strstr ( V_30 -> V_42 , V_41 [ V_35 ] . V_31 ) )
return V_41 [ V_35 ] . V_21 ;
}
for ( V_35 = 0 ; V_35 < F_15 ( V_43 ) ; V_35 ++ ) {
const struct V_44 * V_45 = & V_43 [ V_35 ] ;
if ( V_30 -> V_46 == V_45 -> V_47 &&
( V_45 -> V_48 == V_49 || V_30 -> V_50 == V_45 -> V_48 ) )
return V_45 -> V_21 ;
}
if ( V_30 -> V_46 == 0xf && V_30 -> V_50 < 4 )
V_33 = 0 ;
if ( V_30 -> V_46 > 0xe && V_33 ) {
T_3 V_51 ;
V_34 = F_16 ( V_31 , 0x17 , & V_17 , & V_18 ) ;
if ( V_34 ) {
F_17 ( V_2 ,
L_4
L_5 ) ;
V_33 = 0 ;
} else if ( V_30 -> V_46 < 0x17 && ! ( V_17 & 0x10000000 ) ) {
V_33 = 0 ;
} else {
V_51 = ( V_18 >> 18 ) & 0x7 ;
if ( V_30 -> V_46 == 0x17 &&
( V_51 == 5 || V_51 == 7 ) ) {
V_32 = 90000 ;
V_21 = 105000 ;
}
}
}
if ( V_33 ) {
V_34 = F_16 ( V_31 , 0xee , & V_17 , & V_18 ) ;
if ( V_34 ) {
F_17 ( V_2 ,
L_6
L_7 ) ;
} else if ( V_17 & 0x40000000 ) {
V_21 = V_32 ;
}
} else if ( V_21 == 100000 ) {
F_17 ( V_2 , L_8 ) ;
}
return V_21 ;
}
static bool F_18 ( struct V_29 * V_30 )
{
T_3 V_47 = V_30 -> V_46 ;
return V_47 > 0xe &&
V_47 != 0x1c &&
V_47 != 0x26 &&
V_47 != 0x27 &&
V_47 != 0x35 &&
V_47 != 0x36 ;
}
static int F_19 ( struct V_29 * V_30 , T_2 V_31 , struct V_1 * V_2 )
{
int V_34 ;
T_2 V_17 , V_18 ;
T_2 V_52 ;
V_34 = F_16 ( V_31 , V_53 , & V_17 , & V_18 ) ;
if ( V_34 ) {
if ( F_18 ( V_30 ) )
F_17 ( V_2 , L_9 , V_31 ) ;
} else {
V_52 = ( V_17 >> 16 ) & 0xff ;
if ( V_52 ) {
F_20 ( V_2 , L_10 , V_52 ) ;
return V_52 * 1000 ;
}
}
if ( V_54 ) {
F_21 ( V_2 , L_11 ,
V_54 ) ;
return V_54 * 1000 ;
}
return F_12 ( V_30 , V_31 , V_2 ) ;
}
static int F_22 ( struct V_10 * V_11 , struct V_1 * V_2 ,
int V_55 )
{
int V_35 ;
static T_1 ( * const V_56 [ V_57 ] ) ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 ) = {
F_1 , F_4 , F_8 , F_6 ,
F_7 } ;
static const char * const V_58 [ V_57 ] = {
L_12 , L_13 , L_14 , L_15 , L_16
} ;
for ( V_35 = 0 ; V_35 < V_11 -> V_59 ; V_35 ++ ) {
snprintf ( V_11 -> V_60 [ V_35 ] , V_61 ,
L_17 , V_55 , V_58 [ V_35 ] ) ;
F_23 ( & V_11 -> V_62 [ V_35 ] . V_63 . V_7 ) ;
V_11 -> V_62 [ V_35 ] . V_63 . V_7 . V_64 = V_11 -> V_60 [ V_35 ] ;
V_11 -> V_62 [ V_35 ] . V_63 . V_7 . V_65 = V_66 ;
V_11 -> V_62 [ V_35 ] . V_63 . V_67 = V_56 [ V_35 ] ;
V_11 -> V_62 [ V_35 ] . V_13 = V_55 ;
V_11 -> V_68 [ V_35 ] = & V_11 -> V_62 [ V_35 ] . V_63 . V_7 ;
}
V_11 -> V_69 . V_68 = V_11 -> V_68 ;
return F_24 ( & V_2 -> V_70 , & V_11 -> V_69 ) ;
}
static int F_25 ( unsigned int V_19 )
{
struct V_29 * V_30 = & F_26 ( V_19 ) ;
if ( V_30 -> V_46 == 0xe && V_30 -> V_50 < 0xc && V_30 -> V_71 < 0x39 ) {
F_27 ( L_18 ) ;
return - V_72 ;
}
return 0 ;
}
static struct V_73 * F_28 ( unsigned int V_19 )
{
T_4 V_15 = F_29 ( V_19 ) ;
struct V_74 * V_75 ;
F_9 ( & V_76 ) ;
F_30 (p, &pdev_list, list)
if ( V_75 -> V_15 == V_15 ) {
F_11 ( & V_76 ) ;
return V_75 -> V_77 ;
}
F_11 ( & V_76 ) ;
return NULL ;
}
static struct V_10 * F_31 ( unsigned int V_19 , int V_78 )
{
struct V_10 * V_11 ;
V_11 = F_32 ( sizeof( struct V_10 ) , V_79 ) ;
if ( ! V_11 )
return NULL ;
V_11 -> V_20 = V_78 ? V_80 :
V_81 ;
V_11 -> V_14 = V_78 ;
V_11 -> V_19 = V_19 ;
V_11 -> V_16 = F_33 ( V_19 ) ;
V_11 -> V_59 = V_82 ;
F_34 ( & V_11 -> V_23 ) ;
return V_11 ;
}
static int F_35 ( struct V_73 * V_77 , unsigned int V_19 ,
int V_78 )
{
struct V_10 * V_11 ;
struct V_8 * V_9 = F_36 ( V_77 ) ;
struct V_29 * V_30 = & F_26 ( V_19 ) ;
T_2 V_17 , V_18 ;
int V_34 , V_55 ;
V_55 = V_78 ? 1 : F_37 ( V_19 ) ;
if ( V_55 > V_83 - 1 )
return - V_84 ;
if ( V_9 -> V_12 [ V_55 ] != NULL )
return 0 ;
V_11 = F_31 ( V_19 , V_78 ) ;
if ( ! V_11 )
return - V_85 ;
V_34 = F_16 ( V_19 , V_11 -> V_20 , & V_17 , & V_18 ) ;
if ( V_34 )
goto V_86;
V_11 -> V_21 = F_19 ( V_30 , V_19 , & V_77 -> V_2 ) ;
if ( V_30 -> V_46 > 0xe && V_30 -> V_46 != 0x1c ) {
V_34 = F_16 ( V_19 , V_53 ,
& V_17 , & V_18 ) ;
if ( ! V_34 ) {
V_11 -> V_22
= V_11 -> V_21 - ( ( V_17 >> 8 ) & 0xff ) * 1000 ;
V_11 -> V_59 ++ ;
}
}
V_9 -> V_12 [ V_55 ] = V_11 ;
V_34 = F_22 ( V_11 , V_9 -> V_87 , V_55 ) ;
if ( V_34 )
goto V_86;
return 0 ;
V_86:
V_9 -> V_12 [ V_55 ] = NULL ;
F_38 ( V_11 ) ;
return V_34 ;
}
static void F_39 ( unsigned int V_19 , int V_78 )
{
struct V_73 * V_77 = F_28 ( V_19 ) ;
int V_34 ;
if ( ! V_77 )
return;
V_34 = F_35 ( V_77 , V_19 , V_78 ) ;
if ( V_34 )
F_40 ( & V_77 -> V_2 , L_19 , V_19 ) ;
}
static void F_41 ( struct V_8 * V_9 ,
int V_88 )
{
struct V_10 * V_11 = V_9 -> V_12 [ V_88 ] ;
F_42 ( & V_9 -> V_87 -> V_70 , & V_11 -> V_69 ) ;
F_38 ( V_9 -> V_12 [ V_88 ] ) ;
V_9 -> V_12 [ V_88 ] = NULL ;
}
static int F_43 ( struct V_73 * V_77 )
{
struct V_1 * V_2 = & V_77 -> V_2 ;
struct V_8 * V_9 ;
V_9 = F_44 ( V_2 , sizeof( struct V_8 ) , V_79 ) ;
if ( ! V_9 )
return - V_85 ;
V_9 -> V_15 = V_77 -> V_31 ;
F_45 ( V_77 , V_9 ) ;
V_9 -> V_87 = F_46 ( V_2 , V_89 ,
V_9 , NULL ) ;
return F_47 ( V_9 -> V_87 ) ;
}
static int F_48 ( struct V_73 * V_77 )
{
struct V_8 * V_9 = F_36 ( V_77 ) ;
int V_35 ;
for ( V_35 = V_83 - 1 ; V_35 >= 0 ; -- V_35 )
if ( V_9 -> V_12 [ V_35 ] )
F_41 ( V_9 , V_35 ) ;
return 0 ;
}
static int F_49 ( unsigned int V_19 )
{
int V_34 ;
struct V_73 * V_77 ;
struct V_74 * V_74 ;
F_9 ( & V_76 ) ;
V_77 = F_50 ( V_89 , F_29 ( V_19 ) ) ;
if ( ! V_77 ) {
V_34 = - V_85 ;
F_27 ( L_20 ) ;
goto exit;
}
V_74 = F_32 ( sizeof( struct V_74 ) , V_79 ) ;
if ( ! V_74 ) {
V_34 = - V_85 ;
goto V_90;
}
V_34 = F_51 ( V_77 ) ;
if ( V_34 ) {
F_27 ( L_21 , V_34 ) ;
goto V_91;
}
V_74 -> V_77 = V_77 ;
V_74 -> V_15 = V_77 -> V_31 ;
F_52 ( & V_74 -> V_92 , & V_93 ) ;
F_11 ( & V_76 ) ;
return 0 ;
V_91:
F_38 ( V_74 ) ;
V_90:
F_53 ( V_77 ) ;
exit:
F_11 ( & V_76 ) ;
return V_34 ;
}
static void F_54 ( unsigned int V_19 )
{
struct V_74 * V_75 , * V_94 ;
T_4 V_15 = F_29 ( V_19 ) ;
F_9 ( & V_76 ) ;
F_55 (p, n, &pdev_list, list) {
if ( V_75 -> V_15 != V_15 )
continue;
F_56 ( V_75 -> V_77 ) ;
F_57 ( & V_75 -> V_92 ) ;
F_38 ( V_75 ) ;
}
F_11 ( & V_76 ) ;
}
static bool F_58 ( struct V_8 * V_9 )
{
int V_35 ;
for ( V_35 = V_83 - 1 ; V_35 >= 0 ; -- V_35 ) {
if ( V_9 -> V_12 [ V_35 ] &&
! V_9 -> V_12 [ V_35 ] -> V_14 ) {
return true ;
}
}
return false ;
}
static void F_59 ( unsigned int V_19 )
{
struct V_29 * V_30 = & F_26 ( V_19 ) ;
struct V_73 * V_77 = F_28 ( V_19 ) ;
int V_34 ;
if ( ! F_60 ( V_30 , V_95 ) )
return;
if ( ! V_77 ) {
if ( F_25 ( V_19 ) )
return;
V_34 = F_49 ( V_19 ) ;
if ( V_34 )
return;
if ( F_60 ( V_30 , V_96 ) )
F_39 ( V_19 , 1 ) ;
}
F_39 ( V_19 , 0 ) ;
}
static void F_61 ( unsigned int V_19 )
{
int V_35 , V_88 ;
struct V_8 * V_9 ;
struct V_73 * V_77 = F_28 ( V_19 ) ;
if ( ! V_77 )
return;
V_9 = F_36 ( V_77 ) ;
V_88 = F_37 ( V_19 ) ;
if ( V_88 > V_83 - 1 )
return;
if ( V_9 -> V_12 [ V_88 ] && V_9 -> V_12 [ V_88 ] -> V_19 == V_19 )
F_41 ( V_9 , V_88 ) ;
F_62 (i, cpu) {
if ( V_35 != V_19 ) {
F_59 ( V_35 ) ;
break;
}
}
if ( ! F_58 ( V_9 ) )
F_54 ( V_19 ) ;
}
static int F_63 ( struct V_97 * V_98 ,
unsigned long V_99 , void * V_100 )
{
unsigned int V_19 = ( unsigned long ) V_100 ;
switch ( V_99 ) {
case V_101 :
case V_102 :
F_59 ( V_19 ) ;
break;
case V_103 :
F_61 ( V_19 ) ;
break;
}
return V_104 ;
}
static int T_5 F_64 ( void )
{
int V_35 , V_34 ;
if ( ! F_65 ( V_105 ) )
return - V_72 ;
V_34 = F_66 ( & V_106 ) ;
if ( V_34 )
goto exit;
F_67 () ;
F_68 (i)
F_59 ( V_35 ) ;
#ifndef F_69
if ( F_70 ( & V_93 ) ) {
F_71 () ;
V_34 = - V_72 ;
goto V_107;
}
#endif
F_72 ( & V_108 ) ;
F_71 () ;
return 0 ;
#ifndef F_69
V_107:
F_73 ( & V_106 ) ;
#endif
exit:
return V_34 ;
}
static void T_6 F_74 ( void )
{
struct V_74 * V_75 , * V_94 ;
F_67 () ;
F_75 ( & V_108 ) ;
F_9 ( & V_76 ) ;
F_55 (p, n, &pdev_list, list) {
F_56 ( V_75 -> V_77 ) ;
F_57 ( & V_75 -> V_92 ) ;
F_38 ( V_75 ) ;
}
F_11 ( & V_76 ) ;
F_71 () ;
F_73 ( & V_106 ) ;
}
