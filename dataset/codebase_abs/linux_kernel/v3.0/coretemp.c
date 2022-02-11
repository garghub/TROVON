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
F_18 ( V_2 , L_10 ) ;
} else {
V_44 = ( V_18 >> 16 ) & 0xff ;
if ( V_44 ) {
F_20 ( V_2 , L_11 , V_44 ) ;
return V_44 * 1000 ;
}
}
return F_13 ( V_32 , V_33 , V_2 ) ;
}
static void T_4 F_21 ( void * V_19 )
{
T_2 V_18 ;
F_22 ( V_46 , 0 , 0 ) ;
F_23 () ;
F_24 ( V_46 , V_18 , * ( T_2 * ) V_19 ) ;
}
static int F_25 ( unsigned int V_20 , struct V_1 * V_2 )
{
int V_36 ;
T_2 V_18 , V_19 , V_44 ;
V_36 = F_17 ( V_20 , V_45 , & V_18 , & V_19 ) ;
if ( ! V_36 ) {
V_44 = ( V_18 >> 16 ) & 0xff ;
if ( V_44 )
return V_44 * 1000 ;
}
F_18 ( V_2 , L_12 , V_20 ) ;
return 100000 ;
}
static int F_26 ( struct V_9 * V_10 , struct V_1 * V_2 )
{
F_27 ( & V_10 -> V_47 . V_8 ) ;
V_10 -> V_47 . V_8 . V_48 = L_13 ;
V_10 -> V_47 . V_8 . V_49 = V_50 ;
V_10 -> V_47 . V_51 = F_1 ;
return F_28 ( V_2 , & V_10 -> V_47 ) ;
}
static int F_29 ( struct V_11 * V_12 , struct V_1 * V_2 ,
int V_52 )
{
int V_36 , V_53 ;
static T_1 (* F_30 [ V_54 ]) ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 ) = {
F_2 , show_crit_alarm, show_ttarget,
show_temp, show_tjmax }
void F_31 ( T_5 V_55 , struct V_11 * V_12 ,
struct V_1 * V_2 )
{
int V_36 ;
T_2 V_18 , V_19 ;
V_12 -> V_23 = V_12 -> V_22 - 20000 ;
if ( V_55 > 0xe && V_55 != 0x1c ) {
V_36 = F_17 ( V_12 -> V_20 ,
V_45 , & V_18 , & V_19 ) ;
if ( V_36 ) {
F_18 ( V_2 ,
L_14 ) ;
} else {
V_12 -> V_23 = V_12 -> V_22 -
( ( V_18 >> 8 ) & 0xff ) * 1000 ;
}
}
}
static int T_4 F_32 ( struct V_56 * V_57 )
{
struct V_31 * V_32 = & F_33 ( V_57 -> V_33 ) ;
int V_36 ;
T_2 V_19 ;
if ( V_32 -> V_39 == 0xe && V_32 -> V_40 < 0xc ) {
V_36 = F_34 ( V_57 -> V_33 , F_21 ,
& V_19 , 1 ) ;
if ( V_36 ) {
F_35 ( & V_57 -> V_2 ,
L_15
L_16 , V_57 -> V_33 , V_36 ) ;
return - V_58 ;
} else if ( V_19 < 0x39 ) {
F_35 ( & V_57 -> V_2 ,
L_17
L_18 ) ;
return - V_58 ;
}
}
return 0 ;
}
static struct V_56 * F_36 ( unsigned int V_20 )
{
T_6 V_16 = F_37 ( V_20 ) ;
struct V_59 * V_60 ;
F_10 ( & V_61 ) ;
F_38 (p, &pdev_list, list)
if ( V_60 -> V_16 == V_16 ) {
F_12 ( & V_61 ) ;
return V_60 -> V_57 ;
}
F_12 ( & V_61 ) ;
return NULL ;
}
static struct V_11 * F_39 ( unsigned int V_20 , int V_62 )
{
struct V_11 * V_12 ;
V_12 = F_40 ( sizeof( struct V_11 ) , V_63 ) ;
if ( ! V_12 )
return NULL ;
V_12 -> V_21 = V_62 ? V_64 :
V_65 ;
V_12 -> V_15 = V_62 ;
V_12 -> V_20 = V_20 ;
V_12 -> V_17 = F_41 ( V_20 ) ;
F_42 ( & V_12 -> V_24 ) ;
return V_12 ;
}
static int F_43 ( struct V_9 * V_10 ,
struct V_56 * V_57 ,
unsigned int V_20 , int V_62 )
{
struct V_11 * V_12 ;
struct V_31 * V_32 = & F_33 ( V_20 ) ;
T_2 V_18 , V_19 ;
int V_36 , V_52 ;
V_52 = V_62 ? 1 : F_44 ( V_20 ) ;
if ( V_52 > V_66 - 1 )
return - V_67 ;
if ( V_10 -> V_13 [ V_52 ] != NULL )
return 0 ;
V_12 = F_39 ( V_20 , V_62 ) ;
if ( ! V_12 )
return - V_68 ;
V_36 = F_17 ( V_20 , V_12 -> V_21 , & V_18 , & V_19 ) ;
if ( V_36 )
goto V_69;
if ( V_62 )
V_12 -> V_22 = F_25 ( V_57 -> V_33 , & V_57 -> V_2 ) ;
else
V_12 -> V_22 = F_19 ( V_32 , V_20 , & V_57 -> V_2 ) ;
F_31 ( V_32 -> V_39 , V_12 , & V_57 -> V_2 ) ;
V_10 -> V_13 [ V_52 ] = V_12 ;
V_36 = F_29 ( V_12 , & V_57 -> V_2 , V_52 ) ;
if ( V_36 )
goto V_69;
return 0 ;
V_69:
F_45 ( V_12 ) ;
return V_36 ;
}
static void F_46 ( unsigned int V_20 , int V_62 )
{
struct V_9 * V_10 ;
struct V_56 * V_57 = F_36 ( V_20 ) ;
int V_36 ;
if ( ! V_57 )
return;
V_10 = F_47 ( V_57 ) ;
V_36 = F_43 ( V_10 , V_57 , V_20 , V_62 ) ;
if ( V_36 )
F_35 ( & V_57 -> V_2 , L_19 , V_20 ) ;
}
static void F_48 ( struct V_9 * V_10 ,
struct V_1 * V_2 , int V_70 )
{
int V_53 ;
struct V_11 * V_12 = V_10 -> V_13 [ V_70 ] ;
for ( V_53 = 0 ; V_53 < V_54 ; V_53 ++ )
F_49 ( V_2 , & V_12 -> V_71 [ V_53 ] . V_72 ) ;
F_45 ( V_10 -> V_13 [ V_70 ] ) ;
V_10 -> V_13 [ V_70 ] = NULL ;
}
static int T_4 F_50 ( struct V_56 * V_57 )
{
struct V_9 * V_10 ;
int V_36 ;
V_36 = F_32 ( V_57 ) ;
if ( V_36 )
return V_36 ;
V_10 = F_40 ( sizeof( struct V_9 ) , V_63 ) ;
if ( ! V_10 )
return - V_68 ;
V_36 = F_26 ( V_10 , & V_57 -> V_2 ) ;
if ( V_36 )
goto V_69;
V_10 -> V_16 = F_37 ( V_57 -> V_33 ) ;
F_51 ( V_57 , V_10 ) ;
V_10 -> V_73 = F_52 ( & V_57 -> V_2 ) ;
if ( F_53 ( V_10 -> V_73 ) ) {
V_36 = F_54 ( V_10 -> V_73 ) ;
F_35 ( & V_57 -> V_2 , L_20 , V_36 ) ;
goto V_74;
}
return 0 ;
V_74:
F_49 ( & V_57 -> V_2 , & V_10 -> V_47 ) ;
F_51 ( V_57 , NULL ) ;
V_69:
F_45 ( V_10 ) ;
return V_36 ;
}
static int T_7 F_55 ( struct V_56 * V_57 )
{
struct V_9 * V_10 = F_47 ( V_57 ) ;
int V_53 ;
for ( V_53 = V_66 - 1 ; V_53 >= 0 ; -- V_53 )
if ( V_10 -> V_13 [ V_53 ] )
F_48 ( V_10 , & V_57 -> V_2 , V_53 ) ;
F_49 ( & V_57 -> V_2 , & V_10 -> V_47 ) ;
F_56 ( V_10 -> V_73 ) ;
F_51 ( V_57 , NULL ) ;
F_45 ( V_10 ) ;
return 0 ;
}
static int T_8 F_57 ( unsigned int V_20 )
{
int V_36 ;
struct V_56 * V_57 ;
struct V_59 * V_59 ;
F_10 ( & V_61 ) ;
V_57 = F_58 ( V_6 , V_20 ) ;
if ( ! V_57 ) {
V_36 = - V_68 ;
F_59 ( L_21 ) ;
goto exit;
}
V_59 = F_40 ( sizeof( struct V_59 ) , V_63 ) ;
if ( ! V_59 ) {
V_36 = - V_68 ;
goto V_75;
}
V_36 = F_60 ( V_57 ) ;
if ( V_36 ) {
F_59 ( L_22 , V_36 ) ;
goto V_76;
}
V_59 -> V_57 = V_57 ;
V_59 -> V_16 = F_37 ( V_20 ) ;
F_61 ( & V_59 -> V_77 , & V_78 ) ;
F_12 ( & V_61 ) ;
return 0 ;
V_76:
F_45 ( V_59 ) ;
V_75:
F_62 ( V_57 ) ;
exit:
F_12 ( & V_61 ) ;
return V_36 ;
}
static void F_63 ( unsigned int V_20 )
{
struct V_59 * V_60 , * V_79 ;
T_6 V_16 = F_37 ( V_20 ) ;
F_10 ( & V_61 ) ;
F_64 (p, n, &pdev_list, list) {
if ( V_60 -> V_16 != V_16 )
continue;
F_65 ( V_60 -> V_57 ) ;
F_66 ( & V_60 -> V_77 ) ;
F_45 ( V_60 ) ;
}
F_12 ( & V_61 ) ;
}
static bool F_67 ( struct V_9 * V_10 )
{
int V_53 ;
for ( V_53 = V_66 - 1 ; V_53 >= 0 ; -- V_53 ) {
if ( V_10 -> V_13 [ V_53 ] &&
! V_10 -> V_13 [ V_53 ] -> V_15 ) {
return true ;
}
}
return false ;
}
static void T_8 F_68 ( unsigned int V_20 )
{
struct V_31 * V_32 = & F_33 ( V_20 ) ;
struct V_56 * V_57 = F_36 ( V_20 ) ;
int V_36 ;
if ( ! F_69 ( V_32 , V_80 ) )
return;
if ( ! V_57 ) {
V_36 = F_57 ( V_20 ) ;
if ( V_36 )
return;
if ( F_69 ( V_32 , V_81 ) )
F_46 ( V_20 , 1 ) ;
}
F_46 ( V_20 , 0 ) ;
}
static void T_8 F_70 ( unsigned int V_20 )
{
int V_53 , V_70 ;
struct V_9 * V_10 ;
struct V_56 * V_57 = F_36 ( V_20 ) ;
if ( ! V_57 )
return;
V_10 = F_47 ( V_57 ) ;
V_70 = F_44 ( V_20 ) ;
if ( V_10 -> V_13 [ V_70 ] && V_10 -> V_13 [ V_70 ] -> V_20 == V_20 )
F_48 ( V_10 , & V_57 -> V_2 , V_70 ) ;
F_71 (i, cpu) {
if ( V_53 != V_20 ) {
F_68 ( V_53 ) ;
break;
}
}
if ( ! F_67 ( V_10 ) )
F_63 ( V_20 ) ;
}
static int T_8 F_72 ( struct V_82 * V_83 ,
unsigned long V_84 , void * V_85 )
{
unsigned int V_20 = ( unsigned long ) V_85 ;
switch ( V_84 ) {
case V_86 :
case V_87 :
F_68 ( V_20 ) ;
break;
case V_88 :
F_70 ( V_20 ) ;
break;
}
return V_89 ;
}
static int T_9 F_73 ( void )
{
int V_53 , V_36 = - V_58 ;
if ( F_33 ( 0 ) . V_90 != V_91 )
goto exit;
V_36 = F_74 ( & V_92 ) ;
if ( V_36 )
goto exit;
F_75 (i)
F_68 ( V_53 ) ;
#ifndef F_76
if ( F_77 ( & V_78 ) ) {
V_36 = - V_58 ;
goto V_93;
}
#endif
F_78 ( & V_94 ) ;
return 0 ;
#ifndef F_76
V_93:
F_79 ( & V_92 ) ;
#endif
exit:
return V_36 ;
}
static void T_10 F_80 ( void )
{
struct V_59 * V_60 , * V_79 ;
F_81 ( & V_94 ) ;
F_10 ( & V_61 ) ;
F_64 (p, n, &pdev_list, list) {
F_65 ( V_60 -> V_57 ) ;
F_66 ( & V_60 -> V_77 ) ;
F_45 ( V_60 ) ;
}
F_12 ( & V_61 ) ;
F_79 ( & V_92 ) ;
}
