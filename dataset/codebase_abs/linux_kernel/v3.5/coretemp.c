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
static int T_3 F_13 ( struct V_31 * V_32 , T_2 V_33 ,
struct V_1 * V_2 )
{
int V_22 = 100000 ;
int V_34 = 85000 ;
int V_35 = 1 ;
int V_36 ;
T_2 V_18 , V_19 ;
struct V_37 * V_38 ;
int V_39 ;
for ( V_39 = 0 ; V_39 < F_14 ( V_40 ) ; V_39 ++ ) {
if ( strstr ( V_32 -> V_41 , V_40 [ V_39 ] . V_33 ) )
return V_40 [ V_39 ] . V_22 ;
}
if ( V_32 -> V_42 == 0xf && V_32 -> V_43 < 4 )
V_35 = 0 ;
if ( V_32 -> V_42 == 0x1c || V_32 -> V_42 == 0x26
|| V_32 -> V_42 == 0x27 ) {
V_35 = 0 ;
V_38 = F_15 ( 0 , F_16 ( 0 , 0 ) ) ;
if ( V_38 && V_38 -> V_44 == V_45
&& ( V_38 -> V_1 == 0xa000
|| V_38 -> V_1 == 0xa010 ) )
V_22 = 100000 ;
else
V_22 = 90000 ;
F_17 ( V_38 ) ;
} else if ( V_32 -> V_42 == 0x36 ) {
V_35 = 0 ;
V_22 = 100000 ;
}
if ( V_32 -> V_42 > 0xe && V_35 ) {
T_4 V_46 ;
V_36 = F_18 ( V_33 , 0x17 , & V_18 , & V_19 ) ;
if ( V_36 ) {
F_19 ( V_2 ,
L_5
L_6 ) ;
V_35 = 0 ;
} else if ( V_32 -> V_42 < 0x17 && ! ( V_18 & 0x10000000 ) ) {
V_35 = 0 ;
} else {
V_46 = ( V_19 >> 18 ) & 0x7 ;
if ( V_32 -> V_42 == 0x17 &&
( V_46 == 5 || V_46 == 7 ) ) {
V_34 = 90000 ;
V_22 = 105000 ;
}
}
}
if ( V_35 ) {
V_36 = F_18 ( V_33 , 0xee , & V_18 , & V_19 ) ;
if ( V_36 ) {
F_19 ( V_2 ,
L_7
L_8 ) ;
} else if ( V_18 & 0x40000000 ) {
V_22 = V_34 ;
}
} else if ( V_22 == 100000 ) {
F_19 ( V_2 , L_9 ) ;
}
return V_22 ;
}
static int T_3 F_20 ( struct V_31 * V_32 , T_2 V_33 ,
struct V_1 * V_2 )
{
int V_36 ;
T_2 V_18 , V_19 ;
T_2 V_47 ;
V_36 = F_18 ( V_33 , V_48 , & V_18 , & V_19 ) ;
if ( V_36 ) {
if ( V_32 -> V_42 > 0xe && V_32 -> V_42 != 0x1c )
F_19 ( V_2 , L_10 , V_33 ) ;
} else {
V_47 = ( V_18 >> 16 ) & 0xff ;
if ( V_47 ) {
F_21 ( V_2 , L_11 , V_47 ) ;
return V_47 * 1000 ;
}
}
if ( V_49 ) {
F_22 ( V_2 , L_12 ,
V_49 ) ;
return V_49 * 1000 ;
}
return F_13 ( V_32 , V_33 , V_2 ) ;
}
static int T_5 F_23 ( struct V_9 * V_10 ,
struct V_1 * V_2 )
{
F_24 ( & V_10 -> V_50 . V_8 ) ;
V_10 -> V_50 . V_8 . V_51 = L_13 ;
V_10 -> V_50 . V_8 . V_52 = V_53 ;
V_10 -> V_50 . V_54 = F_1 ;
return F_25 ( V_2 , & V_10 -> V_50 ) ;
}
static int T_3 F_26 ( struct V_11 * V_12 ,
struct V_1 * V_2 , int V_55 )
{
int V_36 , V_39 ;
static T_1 ( * const V_56 [ V_57 ] ) ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 ) = {
F_2 , F_5 , F_9 , F_7 ,
F_8 } ;
static const char * const V_58 [ V_57 ] = {
L_14 , L_15 ,
L_16 , L_17 ,
L_18 } ;
for ( V_39 = 0 ; V_39 < V_12 -> V_59 ; V_39 ++ ) {
snprintf ( V_12 -> V_60 [ V_39 ] , V_61 , V_58 [ V_39 ] ,
V_55 ) ;
F_24 ( & V_12 -> V_62 [ V_39 ] . V_63 . V_8 ) ;
V_12 -> V_62 [ V_39 ] . V_63 . V_8 . V_51 = V_12 -> V_60 [ V_39 ] ;
V_12 -> V_62 [ V_39 ] . V_63 . V_8 . V_52 = V_53 ;
V_12 -> V_62 [ V_39 ] . V_63 . V_54 = V_56 [ V_39 ] ;
V_12 -> V_62 [ V_39 ] . V_14 = V_55 ;
V_36 = F_25 ( V_2 , & V_12 -> V_62 [ V_39 ] . V_63 ) ;
if ( V_36 )
goto V_64;
}
return 0 ;
V_64:
while ( -- V_39 >= 0 )
F_27 ( V_2 , & V_12 -> V_62 [ V_39 ] . V_63 ) ;
return V_36 ;
}
static int T_3 F_28 ( unsigned int V_20 )
{
struct V_31 * V_32 = & F_29 ( V_20 ) ;
if ( V_32 -> V_42 == 0xe && V_32 -> V_43 < 0xc && V_32 -> V_65 < 0x39 ) {
F_30 ( L_19
L_20 ) ;
return - V_66 ;
}
return 0 ;
}
static struct V_67 T_3 * F_31 ( unsigned int V_20 )
{
T_6 V_16 = F_32 ( V_20 ) ;
struct V_68 * V_69 ;
F_10 ( & V_70 ) ;
F_33 (p, &pdev_list, list)
if ( V_69 -> V_16 == V_16 ) {
F_12 ( & V_70 ) ;
return V_69 -> V_71 ;
}
F_12 ( & V_70 ) ;
return NULL ;
}
static struct V_11 T_3 * F_34 ( unsigned int V_20 ,
int V_72 )
{
struct V_11 * V_12 ;
V_12 = F_35 ( sizeof( struct V_11 ) , V_73 ) ;
if ( ! V_12 )
return NULL ;
V_12 -> V_21 = V_72 ? V_74 :
V_75 ;
V_12 -> V_15 = V_72 ;
V_12 -> V_20 = V_20 ;
V_12 -> V_17 = F_36 ( V_20 ) ;
V_12 -> V_59 = V_76 ;
F_37 ( & V_12 -> V_24 ) ;
return V_12 ;
}
static int T_3 F_38 ( struct V_67 * V_71 ,
unsigned int V_20 , int V_72 )
{
struct V_11 * V_12 ;
struct V_9 * V_10 = F_39 ( V_71 ) ;
struct V_31 * V_32 = & F_29 ( V_20 ) ;
T_2 V_18 , V_19 ;
int V_36 , V_55 ;
V_55 = V_72 ? 1 : F_40 ( V_20 ) ;
if ( V_55 > V_77 - 1 )
return - V_78 ;
if ( V_10 -> V_13 [ V_55 ] != NULL )
return 0 ;
V_12 = F_34 ( V_20 , V_72 ) ;
if ( ! V_12 )
return - V_79 ;
V_36 = F_18 ( V_20 , V_12 -> V_21 , & V_18 , & V_19 ) ;
if ( V_36 )
goto V_64;
V_12 -> V_22 = F_20 ( V_32 , V_20 , & V_71 -> V_2 ) ;
if ( V_32 -> V_42 > 0xe && V_32 -> V_42 != 0x1c ) {
V_36 = F_18 ( V_20 , V_48 ,
& V_18 , & V_19 ) ;
if ( ! V_36 ) {
V_12 -> V_23
= V_12 -> V_22 - ( ( V_18 >> 8 ) & 0xff ) * 1000 ;
V_12 -> V_59 ++ ;
}
}
V_10 -> V_13 [ V_55 ] = V_12 ;
V_36 = F_26 ( V_12 , & V_71 -> V_2 , V_55 ) ;
if ( V_36 )
goto V_64;
return 0 ;
V_64:
V_10 -> V_13 [ V_55 ] = NULL ;
F_41 ( V_12 ) ;
return V_36 ;
}
static void T_3 F_42 ( unsigned int V_20 , int V_72 )
{
struct V_67 * V_71 = F_31 ( V_20 ) ;
int V_36 ;
if ( ! V_71 )
return;
V_36 = F_38 ( V_71 , V_20 , V_72 ) ;
if ( V_36 )
F_43 ( & V_71 -> V_2 , L_21 , V_20 ) ;
}
static void F_44 ( struct V_9 * V_10 ,
struct V_1 * V_2 , int V_80 )
{
int V_39 ;
struct V_11 * V_12 = V_10 -> V_13 [ V_80 ] ;
for ( V_39 = 0 ; V_39 < V_12 -> V_59 ; V_39 ++ )
F_27 ( V_2 , & V_12 -> V_62 [ V_39 ] . V_63 ) ;
F_41 ( V_10 -> V_13 [ V_80 ] ) ;
V_10 -> V_13 [ V_80 ] = NULL ;
}
static int T_5 F_45 ( struct V_67 * V_71 )
{
struct V_9 * V_10 ;
int V_36 ;
V_10 = F_35 ( sizeof( struct V_9 ) , V_73 ) ;
if ( ! V_10 )
return - V_79 ;
V_36 = F_23 ( V_10 , & V_71 -> V_2 ) ;
if ( V_36 )
goto V_64;
V_10 -> V_16 = V_71 -> V_33 ;
F_46 ( V_71 , V_10 ) ;
V_10 -> V_81 = F_47 ( & V_71 -> V_2 ) ;
if ( F_48 ( V_10 -> V_81 ) ) {
V_36 = F_49 ( V_10 -> V_81 ) ;
F_43 ( & V_71 -> V_2 , L_22 , V_36 ) ;
goto V_82;
}
return 0 ;
V_82:
F_27 ( & V_71 -> V_2 , & V_10 -> V_50 ) ;
F_46 ( V_71 , NULL ) ;
V_64:
F_41 ( V_10 ) ;
return V_36 ;
}
static int T_7 F_50 ( struct V_67 * V_71 )
{
struct V_9 * V_10 = F_39 ( V_71 ) ;
int V_39 ;
for ( V_39 = V_77 - 1 ; V_39 >= 0 ; -- V_39 )
if ( V_10 -> V_13 [ V_39 ] )
F_44 ( V_10 , & V_71 -> V_2 , V_39 ) ;
F_27 ( & V_71 -> V_2 , & V_10 -> V_50 ) ;
F_51 ( V_10 -> V_81 ) ;
F_46 ( V_71 , NULL ) ;
F_41 ( V_10 ) ;
return 0 ;
}
static int T_3 F_52 ( unsigned int V_20 )
{
int V_36 ;
struct V_67 * V_71 ;
struct V_68 * V_68 ;
F_10 ( & V_70 ) ;
V_71 = F_53 ( V_6 , F_32 ( V_20 ) ) ;
if ( ! V_71 ) {
V_36 = - V_79 ;
F_30 ( L_23 ) ;
goto exit;
}
V_68 = F_35 ( sizeof( struct V_68 ) , V_73 ) ;
if ( ! V_68 ) {
V_36 = - V_79 ;
goto V_83;
}
V_36 = F_54 ( V_71 ) ;
if ( V_36 ) {
F_30 ( L_24 , V_36 ) ;
goto V_84;
}
V_68 -> V_71 = V_71 ;
V_68 -> V_16 = V_71 -> V_33 ;
F_55 ( & V_68 -> V_85 , & V_86 ) ;
F_12 ( & V_70 ) ;
return 0 ;
V_84:
F_41 ( V_68 ) ;
V_83:
F_56 ( V_71 ) ;
exit:
F_12 ( & V_70 ) ;
return V_36 ;
}
static void T_3 F_57 ( unsigned int V_20 )
{
struct V_68 * V_69 , * V_87 ;
T_6 V_16 = F_32 ( V_20 ) ;
F_10 ( & V_70 ) ;
F_58 (p, n, &pdev_list, list) {
if ( V_69 -> V_16 != V_16 )
continue;
F_59 ( V_69 -> V_71 ) ;
F_60 ( & V_69 -> V_85 ) ;
F_41 ( V_69 ) ;
}
F_12 ( & V_70 ) ;
}
static bool T_3 F_61 ( struct V_9 * V_10 )
{
int V_39 ;
for ( V_39 = V_77 - 1 ; V_39 >= 0 ; -- V_39 ) {
if ( V_10 -> V_13 [ V_39 ] &&
! V_10 -> V_13 [ V_39 ] -> V_15 ) {
return true ;
}
}
return false ;
}
static void T_3 F_62 ( unsigned int V_20 )
{
struct V_31 * V_32 = & F_29 ( V_20 ) ;
struct V_67 * V_71 = F_31 ( V_20 ) ;
int V_36 ;
if ( ! F_63 ( V_32 , V_88 ) )
return;
if ( ! V_71 ) {
if ( F_28 ( V_20 ) )
return;
V_36 = F_52 ( V_20 ) ;
if ( V_36 )
return;
if ( F_63 ( V_32 , V_89 ) )
F_42 ( V_20 , 1 ) ;
}
F_42 ( V_20 , 0 ) ;
}
static void T_3 F_64 ( unsigned int V_20 )
{
int V_39 , V_80 ;
struct V_9 * V_10 ;
struct V_67 * V_71 = F_31 ( V_20 ) ;
if ( ! V_71 )
return;
V_10 = F_39 ( V_71 ) ;
V_80 = F_40 ( V_20 ) ;
if ( V_80 > V_77 - 1 )
return;
if ( V_10 -> V_13 [ V_80 ] && V_10 -> V_13 [ V_80 ] -> V_20 == V_20 )
F_44 ( V_10 , & V_71 -> V_2 , V_80 ) ;
F_65 (i, cpu) {
if ( V_39 != V_20 ) {
F_62 ( V_39 ) ;
break;
}
}
if ( ! F_61 ( V_10 ) )
F_57 ( V_20 ) ;
}
static int T_3 F_66 ( struct V_90 * V_91 ,
unsigned long V_92 , void * V_93 )
{
unsigned int V_20 = ( unsigned long ) V_93 ;
switch ( V_92 ) {
case V_94 :
case V_95 :
F_62 ( V_20 ) ;
break;
case V_96 :
F_64 ( V_20 ) ;
break;
}
return V_97 ;
}
static int T_8 F_67 ( void )
{
int V_39 , V_36 ;
if ( ! F_68 ( V_98 ) )
return - V_66 ;
V_36 = F_69 ( & V_99 ) ;
if ( V_36 )
goto exit;
F_70 (i)
F_62 ( V_39 ) ;
#ifndef F_71
if ( F_72 ( & V_86 ) ) {
V_36 = - V_66 ;
goto V_100;
}
#endif
F_73 ( & V_101 ) ;
return 0 ;
#ifndef F_71
V_100:
F_74 ( & V_99 ) ;
#endif
exit:
return V_36 ;
}
static void T_9 F_75 ( void )
{
struct V_68 * V_69 , * V_87 ;
F_76 ( & V_101 ) ;
F_10 ( & V_70 ) ;
F_58 (p, n, &pdev_list, list) {
F_59 ( V_69 -> V_71 ) ;
F_60 ( & V_69 -> V_85 ) ;
F_41 ( V_69 ) ;
}
F_12 ( & V_70 ) ;
F_74 ( & V_99 ) ;
}
