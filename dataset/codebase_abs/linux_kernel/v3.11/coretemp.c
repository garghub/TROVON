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
V_12 -> V_25 = 0 ;
if ( V_18 & 0x80000000 ) {
V_12 -> V_29 = V_12 -> V_22 -
( ( V_18 >> 16 ) & 0x7f ) * 1000 ;
V_12 -> V_25 = 1 ;
}
V_12 -> V_27 = V_26 ;
}
F_12 ( & V_12 -> V_24 ) ;
return V_12 -> V_25 ? sprintf ( V_5 , L_4 , V_12 -> V_29 ) : - V_30 ;
}
static int F_13 ( struct V_31 * V_32 , T_2 V_33 , struct V_1 * V_2 )
{
int V_22 = 100000 ;
int V_34 = 85000 ;
int V_35 = 1 ;
int V_36 ;
T_2 V_18 , V_19 ;
int V_37 ;
for ( V_37 = 0 ; V_37 < F_14 ( V_38 ) ; V_37 ++ ) {
if ( strstr ( V_32 -> V_39 , V_38 [ V_37 ] . V_33 ) )
return V_38 [ V_37 ] . V_22 ;
}
for ( V_37 = 0 ; V_37 < F_14 ( V_40 ) ; V_37 ++ ) {
const struct V_41 * V_42 = & V_40 [ V_37 ] ;
if ( V_32 -> V_43 == V_42 -> V_44 &&
( V_42 -> V_45 == V_46 || V_32 -> V_47 == V_42 -> V_45 ) )
return V_42 -> V_22 ;
}
if ( V_32 -> V_43 == 0xf && V_32 -> V_47 < 4 )
V_35 = 0 ;
if ( V_32 -> V_43 > 0xe && V_35 ) {
T_3 V_48 ;
V_36 = F_15 ( V_33 , 0x17 , & V_18 , & V_19 ) ;
if ( V_36 ) {
F_16 ( V_2 ,
L_5
L_6 ) ;
V_35 = 0 ;
} else if ( V_32 -> V_43 < 0x17 && ! ( V_18 & 0x10000000 ) ) {
V_35 = 0 ;
} else {
V_48 = ( V_19 >> 18 ) & 0x7 ;
if ( V_32 -> V_43 == 0x17 &&
( V_48 == 5 || V_48 == 7 ) ) {
V_34 = 90000 ;
V_22 = 105000 ;
}
}
}
if ( V_35 ) {
V_36 = F_15 ( V_33 , 0xee , & V_18 , & V_19 ) ;
if ( V_36 ) {
F_16 ( V_2 ,
L_7
L_8 ) ;
} else if ( V_18 & 0x40000000 ) {
V_22 = V_34 ;
}
} else if ( V_22 == 100000 ) {
F_16 ( V_2 , L_9 ) ;
}
return V_22 ;
}
static int F_17 ( struct V_31 * V_32 , T_2 V_33 , struct V_1 * V_2 )
{
int V_36 ;
T_2 V_18 , V_19 ;
T_2 V_49 ;
V_36 = F_15 ( V_33 , V_50 , & V_18 , & V_19 ) ;
if ( V_36 ) {
if ( V_32 -> V_43 > 0xe && V_32 -> V_43 != 0x1c )
F_16 ( V_2 , L_10 , V_33 ) ;
} else {
V_49 = ( V_18 >> 16 ) & 0xff ;
if ( V_49 ) {
F_18 ( V_2 , L_11 , V_49 ) ;
return V_49 * 1000 ;
}
}
if ( V_51 ) {
F_19 ( V_2 , L_12 ,
V_51 ) ;
return V_51 * 1000 ;
}
return F_13 ( V_32 , V_33 , V_2 ) ;
}
static int F_20 ( struct V_9 * V_10 ,
struct V_1 * V_2 )
{
F_21 ( & V_10 -> V_52 . V_8 ) ;
V_10 -> V_52 . V_8 . V_53 = L_13 ;
V_10 -> V_52 . V_8 . V_54 = V_55 ;
V_10 -> V_52 . V_56 = F_1 ;
return F_22 ( V_2 , & V_10 -> V_52 ) ;
}
static int F_23 ( struct V_11 * V_12 , struct V_1 * V_2 ,
int V_57 )
{
int V_36 , V_37 ;
static T_1 ( * const V_58 [ V_59 ] ) ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 ) = {
F_2 , F_5 , F_9 , F_7 ,
F_8 } ;
static const char * const V_60 [ V_59 ] = {
L_14 , L_15 ,
L_16 , L_17 ,
L_18 } ;
for ( V_37 = 0 ; V_37 < V_12 -> V_61 ; V_37 ++ ) {
snprintf ( V_12 -> V_62 [ V_37 ] , V_63 , V_60 [ V_37 ] ,
V_57 ) ;
F_21 ( & V_12 -> V_64 [ V_37 ] . V_65 . V_8 ) ;
V_12 -> V_64 [ V_37 ] . V_65 . V_8 . V_53 = V_12 -> V_62 [ V_37 ] ;
V_12 -> V_64 [ V_37 ] . V_65 . V_8 . V_54 = V_55 ;
V_12 -> V_64 [ V_37 ] . V_65 . V_56 = V_58 [ V_37 ] ;
V_12 -> V_64 [ V_37 ] . V_14 = V_57 ;
V_36 = F_22 ( V_2 , & V_12 -> V_64 [ V_37 ] . V_65 ) ;
if ( V_36 )
goto V_66;
}
return 0 ;
V_66:
while ( -- V_37 >= 0 )
F_24 ( V_2 , & V_12 -> V_64 [ V_37 ] . V_65 ) ;
return V_36 ;
}
static int F_25 ( unsigned int V_20 )
{
struct V_31 * V_32 = & F_26 ( V_20 ) ;
if ( V_32 -> V_43 == 0xe && V_32 -> V_47 < 0xc && V_32 -> V_67 < 0x39 ) {
F_27 ( L_19 ) ;
return - V_68 ;
}
return 0 ;
}
static struct V_69 * F_28 ( unsigned int V_20 )
{
T_4 V_16 = F_29 ( V_20 ) ;
struct V_70 * V_71 ;
F_10 ( & V_72 ) ;
F_30 (p, &pdev_list, list)
if ( V_71 -> V_16 == V_16 ) {
F_12 ( & V_72 ) ;
return V_71 -> V_73 ;
}
F_12 ( & V_72 ) ;
return NULL ;
}
static struct V_11 * F_31 ( unsigned int V_20 , int V_74 )
{
struct V_11 * V_12 ;
V_12 = F_32 ( sizeof( struct V_11 ) , V_75 ) ;
if ( ! V_12 )
return NULL ;
V_12 -> V_21 = V_74 ? V_76 :
V_77 ;
V_12 -> V_15 = V_74 ;
V_12 -> V_20 = V_20 ;
V_12 -> V_17 = F_33 ( V_20 ) ;
V_12 -> V_61 = V_78 ;
F_34 ( & V_12 -> V_24 ) ;
return V_12 ;
}
static int F_35 ( struct V_69 * V_73 , unsigned int V_20 ,
int V_74 )
{
struct V_11 * V_12 ;
struct V_9 * V_10 = F_36 ( V_73 ) ;
struct V_31 * V_32 = & F_26 ( V_20 ) ;
T_2 V_18 , V_19 ;
int V_36 , V_57 ;
V_57 = V_74 ? 1 : F_37 ( V_20 ) ;
if ( V_57 > V_79 - 1 )
return - V_80 ;
if ( V_10 -> V_13 [ V_57 ] != NULL )
return 0 ;
V_12 = F_31 ( V_20 , V_74 ) ;
if ( ! V_12 )
return - V_81 ;
V_36 = F_15 ( V_20 , V_12 -> V_21 , & V_18 , & V_19 ) ;
if ( V_36 )
goto V_66;
V_12 -> V_22 = F_17 ( V_32 , V_20 , & V_73 -> V_2 ) ;
if ( V_32 -> V_43 > 0xe && V_32 -> V_43 != 0x1c ) {
V_36 = F_15 ( V_20 , V_50 ,
& V_18 , & V_19 ) ;
if ( ! V_36 ) {
V_12 -> V_23
= V_12 -> V_22 - ( ( V_18 >> 8 ) & 0xff ) * 1000 ;
V_12 -> V_61 ++ ;
}
}
V_10 -> V_13 [ V_57 ] = V_12 ;
V_36 = F_23 ( V_12 , & V_73 -> V_2 , V_57 ) ;
if ( V_36 )
goto V_66;
return 0 ;
V_66:
V_10 -> V_13 [ V_57 ] = NULL ;
F_38 ( V_12 ) ;
return V_36 ;
}
static void F_39 ( unsigned int V_20 , int V_74 )
{
struct V_69 * V_73 = F_28 ( V_20 ) ;
int V_36 ;
if ( ! V_73 )
return;
V_36 = F_35 ( V_73 , V_20 , V_74 ) ;
if ( V_36 )
F_40 ( & V_73 -> V_2 , L_20 , V_20 ) ;
}
static void F_41 ( struct V_9 * V_10 ,
struct V_1 * V_2 , int V_82 )
{
int V_37 ;
struct V_11 * V_12 = V_10 -> V_13 [ V_82 ] ;
for ( V_37 = 0 ; V_37 < V_12 -> V_61 ; V_37 ++ )
F_24 ( V_2 , & V_12 -> V_64 [ V_37 ] . V_65 ) ;
F_38 ( V_10 -> V_13 [ V_82 ] ) ;
V_10 -> V_13 [ V_82 ] = NULL ;
}
static int F_42 ( struct V_69 * V_73 )
{
struct V_9 * V_10 ;
int V_36 ;
V_10 = F_32 ( sizeof( struct V_9 ) , V_75 ) ;
if ( ! V_10 )
return - V_81 ;
V_36 = F_20 ( V_10 , & V_73 -> V_2 ) ;
if ( V_36 )
goto V_66;
V_10 -> V_16 = V_73 -> V_33 ;
F_43 ( V_73 , V_10 ) ;
V_10 -> V_83 = F_44 ( & V_73 -> V_2 ) ;
if ( F_45 ( V_10 -> V_83 ) ) {
V_36 = F_46 ( V_10 -> V_83 ) ;
F_40 ( & V_73 -> V_2 , L_21 , V_36 ) ;
goto V_84;
}
return 0 ;
V_84:
F_24 ( & V_73 -> V_2 , & V_10 -> V_52 ) ;
V_66:
F_38 ( V_10 ) ;
return V_36 ;
}
static int F_47 ( struct V_69 * V_73 )
{
struct V_9 * V_10 = F_36 ( V_73 ) ;
int V_37 ;
for ( V_37 = V_79 - 1 ; V_37 >= 0 ; -- V_37 )
if ( V_10 -> V_13 [ V_37 ] )
F_41 ( V_10 , & V_73 -> V_2 , V_37 ) ;
F_24 ( & V_73 -> V_2 , & V_10 -> V_52 ) ;
F_48 ( V_10 -> V_83 ) ;
F_38 ( V_10 ) ;
return 0 ;
}
static int F_49 ( unsigned int V_20 )
{
int V_36 ;
struct V_69 * V_73 ;
struct V_70 * V_70 ;
F_10 ( & V_72 ) ;
V_73 = F_50 ( V_6 , F_29 ( V_20 ) ) ;
if ( ! V_73 ) {
V_36 = - V_81 ;
F_27 ( L_22 ) ;
goto exit;
}
V_70 = F_32 ( sizeof( struct V_70 ) , V_75 ) ;
if ( ! V_70 ) {
V_36 = - V_81 ;
goto V_85;
}
V_36 = F_51 ( V_73 ) ;
if ( V_36 ) {
F_27 ( L_23 , V_36 ) ;
goto V_86;
}
V_70 -> V_73 = V_73 ;
V_70 -> V_16 = V_73 -> V_33 ;
F_52 ( & V_70 -> V_87 , & V_88 ) ;
F_12 ( & V_72 ) ;
return 0 ;
V_86:
F_38 ( V_70 ) ;
V_85:
F_53 ( V_73 ) ;
exit:
F_12 ( & V_72 ) ;
return V_36 ;
}
static void F_54 ( unsigned int V_20 )
{
struct V_70 * V_71 , * V_89 ;
T_4 V_16 = F_29 ( V_20 ) ;
F_10 ( & V_72 ) ;
F_55 (p, n, &pdev_list, list) {
if ( V_71 -> V_16 != V_16 )
continue;
F_56 ( V_71 -> V_73 ) ;
F_57 ( & V_71 -> V_87 ) ;
F_38 ( V_71 ) ;
}
F_12 ( & V_72 ) ;
}
static bool F_58 ( struct V_9 * V_10 )
{
int V_37 ;
for ( V_37 = V_79 - 1 ; V_37 >= 0 ; -- V_37 ) {
if ( V_10 -> V_13 [ V_37 ] &&
! V_10 -> V_13 [ V_37 ] -> V_15 ) {
return true ;
}
}
return false ;
}
static void F_59 ( unsigned int V_20 )
{
struct V_31 * V_32 = & F_26 ( V_20 ) ;
struct V_69 * V_73 = F_28 ( V_20 ) ;
int V_36 ;
if ( ! F_60 ( V_32 , V_90 ) )
return;
if ( ! V_73 ) {
if ( F_25 ( V_20 ) )
return;
V_36 = F_49 ( V_20 ) ;
if ( V_36 )
return;
if ( F_60 ( V_32 , V_91 ) )
F_39 ( V_20 , 1 ) ;
}
F_39 ( V_20 , 0 ) ;
}
static void F_61 ( unsigned int V_20 )
{
int V_37 , V_82 ;
struct V_9 * V_10 ;
struct V_69 * V_73 = F_28 ( V_20 ) ;
if ( ! V_73 )
return;
V_10 = F_36 ( V_73 ) ;
V_82 = F_37 ( V_20 ) ;
if ( V_82 > V_79 - 1 )
return;
if ( V_10 -> V_13 [ V_82 ] && V_10 -> V_13 [ V_82 ] -> V_20 == V_20 )
F_41 ( V_10 , & V_73 -> V_2 , V_82 ) ;
F_62 (i, cpu) {
if ( V_37 != V_20 ) {
F_59 ( V_37 ) ;
break;
}
}
if ( ! F_58 ( V_10 ) )
F_54 ( V_20 ) ;
}
static int F_63 ( struct V_92 * V_93 ,
unsigned long V_94 , void * V_95 )
{
unsigned int V_20 = ( unsigned long ) V_95 ;
switch ( V_94 ) {
case V_96 :
case V_97 :
F_59 ( V_20 ) ;
break;
case V_98 :
F_61 ( V_20 ) ;
break;
}
return V_99 ;
}
static int T_5 F_64 ( void )
{
int V_37 , V_36 ;
if ( ! F_65 ( V_100 ) )
return - V_68 ;
V_36 = F_66 ( & V_101 ) ;
if ( V_36 )
goto exit;
F_67 () ;
F_68 (i)
F_59 ( V_37 ) ;
#ifndef F_69
if ( F_70 ( & V_88 ) ) {
F_71 () ;
V_36 = - V_68 ;
goto V_102;
}
#endif
F_72 ( & V_103 ) ;
F_71 () ;
return 0 ;
#ifndef F_69
V_102:
F_73 ( & V_101 ) ;
#endif
exit:
return V_36 ;
}
static void T_6 F_74 ( void )
{
struct V_70 * V_71 , * V_89 ;
F_67 () ;
F_75 ( & V_103 ) ;
F_10 ( & V_72 ) ;
F_55 (p, n, &pdev_list, list) {
F_56 ( V_71 -> V_73 ) ;
F_57 ( & V_71 -> V_87 ) ;
F_38 ( V_71 ) ;
}
F_12 ( & V_72 ) ;
F_71 () ;
F_73 ( & V_101 ) ;
}
