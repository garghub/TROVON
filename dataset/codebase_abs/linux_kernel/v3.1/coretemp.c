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
struct V_37 * V_38 ;
if ( V_32 -> V_39 == 0xf && V_32 -> V_40 < 4 )
V_35 = 0 ;
if ( V_32 -> V_39 == 0x1c ) {
V_35 = 0 ;
V_38 = F_14 ( 0 , F_15 ( 0 , 0 ) ) ;
if ( V_38 && V_38 -> V_41 == V_42
&& ( V_38 -> V_1 == 0xa000
|| V_38 -> V_1 == 0xa010 ) )
V_22 = 100000 ;
else
V_22 = 90000 ;
F_16 ( V_38 ) ;
}
if ( V_32 -> V_39 > 0xe && V_35 ) {
T_3 V_43 ;
V_36 = F_17 ( V_33 , 0x17 , & V_18 , & V_19 ) ;
if ( V_36 ) {
F_18 ( V_2 ,
L_5
L_6 ) ;
V_35 = 0 ;
} else if ( V_32 -> V_39 < 0x17 && ! ( V_18 & 0x10000000 ) ) {
V_35 = 0 ;
} else {
V_43 = ( V_19 >> 18 ) & 0x7 ;
if ( V_32 -> V_39 == 0x17 &&
( V_43 == 5 || V_43 == 7 ) ) {
V_34 = 90000 ;
V_22 = 105000 ;
}
}
}
if ( V_35 ) {
V_36 = F_17 ( V_33 , 0xee , & V_18 , & V_19 ) ;
if ( V_36 ) {
F_18 ( V_2 ,
L_7
L_8 ) ;
} else if ( V_18 & 0x40000000 ) {
V_22 = V_34 ;
}
} else if ( V_22 == 100000 ) {
F_18 ( V_2 , L_9 ) ;
}
return V_22 ;
}
static int F_19 ( struct V_31 * V_32 , T_2 V_33 , struct V_1 * V_2 )
{
int V_36 ;
T_2 V_18 , V_19 ;
T_2 V_44 ;
V_36 = F_17 ( V_33 , V_45 , & V_18 , & V_19 ) ;
if ( V_36 ) {
if ( V_32 -> V_39 > 0xe && V_32 -> V_39 != 0x1c )
F_18 ( V_2 , L_10 , V_33 ) ;
} else {
V_44 = ( V_18 >> 16 ) & 0xff ;
if ( V_44 ) {
F_20 ( V_2 , L_11 , V_44 ) ;
return V_44 * 1000 ;
}
}
if ( V_46 ) {
F_21 ( V_2 , L_12 ,
V_46 ) ;
return V_46 * 1000 ;
}
return F_13 ( V_32 , V_33 , V_2 ) ;
}
static void T_4 F_22 ( void * V_19 )
{
T_2 V_18 ;
F_23 ( V_47 , 0 , 0 ) ;
F_24 () ;
F_25 ( V_47 , V_18 , * ( T_2 * ) V_19 ) ;
}
static int F_26 ( struct V_9 * V_10 , struct V_1 * V_2 )
{
F_27 ( & V_10 -> V_48 . V_8 ) ;
V_10 -> V_48 . V_8 . V_49 = L_13 ;
V_10 -> V_48 . V_8 . V_50 = V_51 ;
V_10 -> V_48 . V_52 = F_1 ;
return F_28 ( V_2 , & V_10 -> V_48 ) ;
}
static int F_29 ( struct V_11 * V_12 , struct V_1 * V_2 ,
int V_53 )
{
int V_36 , V_54 ;
static T_1 ( * const V_55 [ V_56 ] ) ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 ) = {
F_2 , F_5 , F_9 , F_7 ,
F_8 } ;
static const char * const V_57 [ V_56 ] = {
L_14 , L_15 ,
L_16 , L_17 ,
L_18 } ;
for ( V_54 = 0 ; V_54 < V_12 -> V_58 ; V_54 ++ ) {
snprintf ( V_12 -> V_59 [ V_54 ] , V_60 , V_57 [ V_54 ] ,
V_53 ) ;
F_27 ( & V_12 -> V_61 [ V_54 ] . V_62 . V_8 ) ;
V_12 -> V_61 [ V_54 ] . V_62 . V_8 . V_49 = V_12 -> V_59 [ V_54 ] ;
V_12 -> V_61 [ V_54 ] . V_62 . V_8 . V_50 = V_51 ;
V_12 -> V_61 [ V_54 ] . V_62 . V_52 = V_55 [ V_54 ] ;
V_12 -> V_61 [ V_54 ] . V_14 = V_53 ;
V_36 = F_28 ( V_2 , & V_12 -> V_61 [ V_54 ] . V_62 ) ;
if ( V_36 )
goto V_63;
}
return 0 ;
V_63:
while ( -- V_54 >= 0 )
F_30 ( V_2 , & V_12 -> V_61 [ V_54 ] . V_62 ) ;
return V_36 ;
}
static int T_5 F_31 ( unsigned int V_20 )
{
struct V_31 * V_32 = & F_32 ( V_20 ) ;
int V_36 ;
T_2 V_19 ;
if ( V_32 -> V_39 == 0xe && V_32 -> V_40 < 0xc ) {
V_36 = F_33 ( V_20 , F_22 ,
& V_19 , 1 ) ;
if ( V_36 ) {
F_34 ( L_19
L_20 , V_20 , V_36 ) ;
return - V_64 ;
} else if ( V_19 < 0x39 ) {
F_34 ( L_21
L_22 ) ;
return - V_64 ;
}
}
return 0 ;
}
static struct V_65 * F_35 ( unsigned int V_20 )
{
T_6 V_16 = F_36 ( V_20 ) ;
struct V_66 * V_67 ;
F_10 ( & V_68 ) ;
F_37 (p, &pdev_list, list)
if ( V_67 -> V_16 == V_16 ) {
F_12 ( & V_68 ) ;
return V_67 -> V_69 ;
}
F_12 ( & V_68 ) ;
return NULL ;
}
static struct V_11 * F_38 ( unsigned int V_20 , int V_70 )
{
struct V_11 * V_12 ;
V_12 = F_39 ( sizeof( struct V_11 ) , V_71 ) ;
if ( ! V_12 )
return NULL ;
V_12 -> V_21 = V_70 ? V_72 :
V_73 ;
V_12 -> V_15 = V_70 ;
V_12 -> V_20 = V_20 ;
V_12 -> V_17 = F_40 ( V_20 ) ;
V_12 -> V_58 = V_74 ;
F_41 ( & V_12 -> V_24 ) ;
return V_12 ;
}
static int F_42 ( struct V_65 * V_69 ,
unsigned int V_20 , int V_70 )
{
struct V_11 * V_12 ;
struct V_9 * V_10 = F_43 ( V_69 ) ;
struct V_31 * V_32 = & F_32 ( V_20 ) ;
T_2 V_18 , V_19 ;
int V_36 , V_53 ;
V_53 = V_70 ? 1 : F_44 ( V_20 ) ;
if ( V_53 > V_75 - 1 )
return - V_76 ;
if ( V_10 -> V_13 [ V_53 ] != NULL )
return 0 ;
V_12 = F_38 ( V_20 , V_70 ) ;
if ( ! V_12 )
return - V_77 ;
V_36 = F_17 ( V_20 , V_12 -> V_21 , & V_18 , & V_19 ) ;
if ( V_36 )
goto V_63;
V_12 -> V_22 = F_19 ( V_32 , V_20 , & V_69 -> V_2 ) ;
if ( V_32 -> V_39 > 0xe && V_32 -> V_39 != 0x1c ) {
V_36 = F_17 ( V_20 , V_45 ,
& V_18 , & V_19 ) ;
if ( ! V_36 ) {
V_12 -> V_23
= V_12 -> V_22 - ( ( V_18 >> 8 ) & 0xff ) * 1000 ;
V_12 -> V_58 ++ ;
}
}
V_10 -> V_13 [ V_53 ] = V_12 ;
V_36 = F_29 ( V_12 , & V_69 -> V_2 , V_53 ) ;
if ( V_36 )
goto V_63;
return 0 ;
V_63:
V_10 -> V_13 [ V_53 ] = NULL ;
F_45 ( V_12 ) ;
return V_36 ;
}
static void F_46 ( unsigned int V_20 , int V_70 )
{
struct V_65 * V_69 = F_35 ( V_20 ) ;
int V_36 ;
if ( ! V_69 )
return;
V_36 = F_42 ( V_69 , V_20 , V_70 ) ;
if ( V_36 )
F_47 ( & V_69 -> V_2 , L_23 , V_20 ) ;
}
static void F_48 ( struct V_9 * V_10 ,
struct V_1 * V_2 , int V_78 )
{
int V_54 ;
struct V_11 * V_12 = V_10 -> V_13 [ V_78 ] ;
for ( V_54 = 0 ; V_54 < V_12 -> V_58 ; V_54 ++ )
F_30 ( V_2 , & V_12 -> V_61 [ V_54 ] . V_62 ) ;
F_45 ( V_10 -> V_13 [ V_78 ] ) ;
V_10 -> V_13 [ V_78 ] = NULL ;
}
static int T_4 F_49 ( struct V_65 * V_69 )
{
struct V_9 * V_10 ;
int V_36 ;
V_10 = F_39 ( sizeof( struct V_9 ) , V_71 ) ;
if ( ! V_10 )
return - V_77 ;
V_36 = F_26 ( V_10 , & V_69 -> V_2 ) ;
if ( V_36 )
goto V_63;
V_10 -> V_16 = V_69 -> V_33 ;
F_50 ( V_69 , V_10 ) ;
V_10 -> V_79 = F_51 ( & V_69 -> V_2 ) ;
if ( F_52 ( V_10 -> V_79 ) ) {
V_36 = F_53 ( V_10 -> V_79 ) ;
F_47 ( & V_69 -> V_2 , L_24 , V_36 ) ;
goto V_80;
}
return 0 ;
V_80:
F_30 ( & V_69 -> V_2 , & V_10 -> V_48 ) ;
F_50 ( V_69 , NULL ) ;
V_63:
F_45 ( V_10 ) ;
return V_36 ;
}
static int T_7 F_54 ( struct V_65 * V_69 )
{
struct V_9 * V_10 = F_43 ( V_69 ) ;
int V_54 ;
for ( V_54 = V_75 - 1 ; V_54 >= 0 ; -- V_54 )
if ( V_10 -> V_13 [ V_54 ] )
F_48 ( V_10 , & V_69 -> V_2 , V_54 ) ;
F_30 ( & V_69 -> V_2 , & V_10 -> V_48 ) ;
F_55 ( V_10 -> V_79 ) ;
F_50 ( V_69 , NULL ) ;
F_45 ( V_10 ) ;
return 0 ;
}
static int T_5 F_56 ( unsigned int V_20 )
{
int V_36 ;
struct V_65 * V_69 ;
struct V_66 * V_66 ;
F_10 ( & V_68 ) ;
V_69 = F_57 ( V_6 , F_36 ( V_20 ) ) ;
if ( ! V_69 ) {
V_36 = - V_77 ;
F_34 ( L_25 ) ;
goto exit;
}
V_66 = F_39 ( sizeof( struct V_66 ) , V_71 ) ;
if ( ! V_66 ) {
V_36 = - V_77 ;
goto V_81;
}
V_36 = F_58 ( V_69 ) ;
if ( V_36 ) {
F_34 ( L_26 , V_36 ) ;
goto V_82;
}
V_66 -> V_69 = V_69 ;
V_66 -> V_16 = V_69 -> V_33 ;
F_59 ( & V_66 -> V_83 , & V_84 ) ;
F_12 ( & V_68 ) ;
return 0 ;
V_82:
F_45 ( V_66 ) ;
V_81:
F_60 ( V_69 ) ;
exit:
F_12 ( & V_68 ) ;
return V_36 ;
}
static void F_61 ( unsigned int V_20 )
{
struct V_66 * V_67 , * V_85 ;
T_6 V_16 = F_36 ( V_20 ) ;
F_10 ( & V_68 ) ;
F_62 (p, n, &pdev_list, list) {
if ( V_67 -> V_16 != V_16 )
continue;
F_63 ( V_67 -> V_69 ) ;
F_64 ( & V_67 -> V_83 ) ;
F_45 ( V_67 ) ;
}
F_12 ( & V_68 ) ;
}
static bool F_65 ( struct V_9 * V_10 )
{
int V_54 ;
for ( V_54 = V_75 - 1 ; V_54 >= 0 ; -- V_54 ) {
if ( V_10 -> V_13 [ V_54 ] &&
! V_10 -> V_13 [ V_54 ] -> V_15 ) {
return true ;
}
}
return false ;
}
static void T_5 F_66 ( unsigned int V_20 )
{
struct V_31 * V_32 = & F_32 ( V_20 ) ;
struct V_65 * V_69 = F_35 ( V_20 ) ;
int V_36 ;
if ( ! F_67 ( V_32 , V_86 ) )
return;
if ( ! V_69 ) {
if ( F_31 ( V_20 ) )
return;
V_36 = F_56 ( V_20 ) ;
if ( V_36 )
return;
if ( F_67 ( V_32 , V_87 ) )
F_46 ( V_20 , 1 ) ;
}
F_46 ( V_20 , 0 ) ;
}
static void T_5 F_68 ( unsigned int V_20 )
{
int V_54 , V_78 ;
struct V_9 * V_10 ;
struct V_65 * V_69 = F_35 ( V_20 ) ;
if ( ! V_69 )
return;
V_10 = F_43 ( V_69 ) ;
V_78 = F_44 ( V_20 ) ;
if ( V_10 -> V_13 [ V_78 ] && V_10 -> V_13 [ V_78 ] -> V_20 == V_20 )
F_48 ( V_10 , & V_69 -> V_2 , V_78 ) ;
F_69 (i, cpu) {
if ( V_54 != V_20 ) {
F_66 ( V_54 ) ;
break;
}
}
if ( ! F_65 ( V_10 ) )
F_61 ( V_20 ) ;
}
static int T_5 F_70 ( struct V_88 * V_89 ,
unsigned long V_90 , void * V_91 )
{
unsigned int V_20 = ( unsigned long ) V_91 ;
switch ( V_90 ) {
case V_92 :
case V_93 :
F_66 ( V_20 ) ;
break;
case V_94 :
F_68 ( V_20 ) ;
break;
}
return V_95 ;
}
static int T_8 F_71 ( void )
{
int V_54 , V_36 = - V_64 ;
if ( F_32 ( 0 ) . V_96 != V_97 )
goto exit;
V_36 = F_72 ( & V_98 ) ;
if ( V_36 )
goto exit;
F_73 (i)
F_66 ( V_54 ) ;
#ifndef F_74
if ( F_75 ( & V_84 ) ) {
V_36 = - V_64 ;
goto V_99;
}
#endif
F_76 ( & V_100 ) ;
return 0 ;
#ifndef F_74
V_99:
F_77 ( & V_98 ) ;
#endif
exit:
return V_36 ;
}
static void T_9 F_78 ( void )
{
struct V_66 * V_67 , * V_85 ;
F_79 ( & V_100 ) ;
F_10 ( & V_68 ) ;
F_62 (p, n, &pdev_list, list) {
F_63 ( V_67 -> V_69 ) ;
F_64 ( & V_67 -> V_83 ) ;
F_45 ( V_67 ) ;
}
F_12 ( & V_68 ) ;
F_77 ( & V_98 ) ;
}
