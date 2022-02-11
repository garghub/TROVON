static int F_1 ( unsigned int V_1 )
{
struct V_2 * V_3 = & F_2 ( V_1 ) ;
return F_3 ( V_3 , V_4 ) ;
}
static unsigned F_4 ( T_1 V_5 , struct V_6 * V_7 )
{
struct V_8 * V_9 ;
int V_10 ;
V_9 = V_7 -> V_11 ;
for ( V_10 = 0 ; V_10 < V_9 -> V_12 ; V_10 ++ ) {
if ( V_5 == V_9 -> V_13 [ V_10 ] . V_14 )
return V_7 -> V_15 [ V_10 ] . V_16 ;
}
return 0 ;
}
static unsigned F_5 ( T_1 V_17 , struct V_6 * V_7 )
{
int V_10 ;
struct V_8 * V_9 ;
V_17 &= V_18 ;
V_9 = V_7 -> V_11 ;
for ( V_10 = 0 ; V_7 -> V_15 [ V_10 ] . V_16 != V_19 ; V_10 ++ ) {
if ( V_17 == V_9 -> V_13 [ V_7 -> V_15 [ V_10 ] . V_20 ] . V_14 )
return V_7 -> V_15 [ V_10 ] . V_16 ;
}
return V_7 -> V_15 [ 0 ] . V_16 ;
}
static unsigned F_6 ( T_1 V_21 , struct V_6 * V_7 )
{
switch ( V_7 -> V_22 ) {
case V_23 :
return F_5 ( V_21 , V_7 ) ;
case V_24 :
return F_4 ( V_21 , V_7 ) ;
default:
return 0 ;
}
}
static void F_7 ( void * V_25 )
{
struct V_26 * V_27 = V_25 ;
T_1 V_28 ;
switch ( V_27 -> type ) {
case V_23 :
F_8 ( V_27 -> V_29 . V_17 . V_30 , V_27 -> V_21 , V_28 ) ;
break;
case V_24 :
F_9 ( ( V_31 ) V_27 -> V_29 . V_32 . V_33 ,
& V_27 -> V_21 ,
( T_1 ) V_27 -> V_29 . V_32 . V_34 ) ;
break;
default:
break;
}
}
static void F_10 ( void * V_25 )
{
struct V_26 * V_27 = V_25 ;
T_1 V_35 , V_36 ;
switch ( V_27 -> type ) {
case V_23 :
F_8 ( V_27 -> V_29 . V_17 . V_30 , V_35 , V_36 ) ;
V_35 = ( V_35 & ~ V_18 ) | ( V_27 -> V_21 & V_18 ) ;
F_11 ( V_27 -> V_29 . V_17 . V_30 , V_35 , V_36 ) ;
break;
case V_24 :
F_12 ( ( V_31 ) V_27 -> V_29 . V_32 . V_33 ,
V_27 -> V_21 ,
( T_1 ) V_27 -> V_29 . V_32 . V_34 ) ;
break;
default:
break;
}
}
static void F_13 ( struct V_26 * V_27 )
{
int V_37 ;
V_27 -> V_21 = 0 ;
V_37 = F_14 ( V_27 -> V_38 , F_7 , V_27 , 1 ) ;
F_15 ( V_37 ) ;
}
static void F_16 ( struct V_26 * V_27 )
{
int V_39 ;
V_39 = F_17 () ;
if ( F_18 ( V_39 , V_27 -> V_38 ) )
F_10 ( V_27 ) ;
F_19 ( V_27 -> V_38 , F_10 , V_27 , 1 ) ;
F_20 () ;
}
static T_1 F_21 ( const struct V_40 * V_38 )
{
struct V_8 * V_9 ;
struct V_26 V_27 ;
if ( F_22 ( F_23 ( V_38 ) ) )
return 0 ;
switch ( F_24 ( V_41 , F_25 ( V_38 ) ) -> V_22 ) {
case V_23 :
V_27 . type = V_23 ;
V_27 . V_29 . V_17 . V_30 = V_42 ;
break;
case V_24 :
V_27 . type = V_24 ;
V_9 = F_24 ( V_41 , F_25 ( V_38 ) ) -> V_11 ;
V_27 . V_29 . V_32 . V_33 = V_9 -> V_43 . V_44 ;
V_27 . V_29 . V_32 . V_34 = V_9 -> V_43 . V_34 ;
break;
default:
return 0 ;
}
V_27 . V_38 = V_38 ;
F_13 ( & V_27 ) ;
F_26 ( L_1 , V_27 . V_21 ) ;
return V_27 . V_21 ;
}
static unsigned int F_27 ( unsigned int V_3 )
{
struct V_6 * V_7 = F_24 ( V_41 , V_3 ) ;
unsigned int V_45 ;
unsigned int V_46 ;
F_26 ( L_2 , V_3 ) ;
if ( F_22 ( V_7 == NULL ||
V_7 -> V_11 == NULL || V_7 -> V_15 == NULL ) ) {
return 0 ;
}
V_46 = V_7 -> V_15 [ V_7 -> V_11 -> V_47 ] . V_16 ;
V_45 = F_6 ( F_21 ( F_28 ( V_3 ) ) , V_7 ) ;
if ( V_45 != V_46 ) {
V_7 -> V_48 = 1 ;
}
F_26 ( L_3 , V_45 ) ;
return V_45 ;
}
static unsigned int F_29 ( const struct V_40 * V_38 , unsigned int V_45 ,
struct V_6 * V_7 )
{
unsigned int V_49 ;
unsigned int V_10 ;
for ( V_10 = 0 ; V_10 < 100 ; V_10 ++ ) {
V_49 = F_6 ( F_21 ( V_38 ) , V_7 ) ;
if ( V_49 == V_45 )
return 1 ;
F_30 ( 10 ) ;
}
return 0 ;
}
static int F_31 ( struct V_50 * V_51 ,
unsigned int V_52 , unsigned int V_53 )
{
struct V_6 * V_7 = F_24 ( V_41 , V_51 -> V_3 ) ;
struct V_8 * V_9 ;
struct V_54 V_55 ;
struct V_26 V_27 ;
unsigned int V_56 = 0 ;
unsigned int V_57 = 0 ;
unsigned int V_10 ;
int V_58 = 0 ;
F_26 ( L_4 , V_52 , V_51 -> V_3 ) ;
if ( F_22 ( V_7 == NULL ||
V_7 -> V_11 == NULL || V_7 -> V_15 == NULL ) ) {
return - V_59 ;
}
V_9 = V_7 -> V_11 ;
V_58 = F_32 ( V_51 ,
V_7 -> V_15 ,
V_52 ,
V_53 , & V_56 ) ;
if ( F_22 ( V_58 ) ) {
V_58 = - V_59 ;
goto V_60;
}
V_57 = V_7 -> V_15 [ V_56 ] . V_20 ;
if ( V_9 -> V_47 == V_57 ) {
if ( F_22 ( V_7 -> V_48 ) ) {
F_26 ( L_5 ,
V_57 ) ;
V_7 -> V_48 = 0 ;
} else {
F_26 ( L_6 ,
V_57 ) ;
goto V_60;
}
}
switch ( V_7 -> V_22 ) {
case V_23 :
V_27 . type = V_23 ;
V_27 . V_29 . V_17 . V_30 = V_61 ;
V_27 . V_21 = ( T_1 ) V_9 -> V_13 [ V_57 ] . V_62 ;
break;
case V_24 :
V_27 . type = V_24 ;
V_27 . V_29 . V_32 . V_33 = V_9 -> V_43 . V_44 ;
V_27 . V_29 . V_32 . V_34 = V_9 -> V_43 . V_34 ;
V_27 . V_21 = ( T_1 ) V_9 -> V_13 [ V_57 ] . V_62 ;
break;
default:
V_58 = - V_59 ;
goto V_60;
}
if ( V_51 -> V_63 != V_64 )
V_27 . V_38 = V_51 -> V_65 ;
else
V_27 . V_38 = F_28 ( V_51 -> V_3 ) ;
V_55 . V_66 = V_9 -> V_13 [ V_9 -> V_47 ] . V_67 * 1000 ;
V_55 . V_68 = V_7 -> V_15 [ V_56 ] . V_16 ;
F_33 (i, policy->cpus) {
V_55 . V_3 = V_10 ;
F_34 ( & V_55 , V_69 ) ;
}
F_16 ( & V_27 ) ;
if ( V_70 ) {
if ( ! F_29 ( V_27 . V_38 , V_55 . V_68 , V_7 ) ) {
F_26 ( L_7 ,
V_51 -> V_3 ) ;
V_58 = - V_71 ;
goto V_60;
}
}
F_33 (i, policy->cpus) {
V_55 . V_3 = V_10 ;
F_34 ( & V_55 , V_72 ) ;
}
V_9 -> V_47 = V_57 ;
V_60:
return V_58 ;
}
static int F_35 ( struct V_50 * V_51 )
{
struct V_6 * V_7 = F_24 ( V_41 , V_51 -> V_3 ) ;
F_26 ( L_8 ) ;
return F_36 ( V_51 , V_7 -> V_15 ) ;
}
static unsigned long
F_37 ( struct V_6 * V_7 , unsigned int V_3 )
{
struct V_8 * V_9 = V_7 -> V_11 ;
if ( V_73 ) {
unsigned int V_10 ;
unsigned long V_45 ;
unsigned long V_74 = V_9 -> V_13 [ 0 ] . V_67 * 1000 ;
for ( V_10 = 0 ; V_10 < ( V_9 -> V_12 - 1 ) ; V_10 ++ ) {
V_45 = V_74 ;
V_74 = V_9 -> V_13 [ V_10 + 1 ] . V_67 * 1000 ;
if ( ( 2 * V_73 ) > ( V_74 + V_45 ) ) {
V_9 -> V_47 = V_10 ;
return V_45 ;
}
}
V_9 -> V_47 = V_9 -> V_12 - 1 ;
return V_74 ;
} else {
V_9 -> V_47 = 0 ;
return V_9 -> V_13 [ 0 ] . V_67 * 1000 ;
}
}
static void F_38 ( void )
{
unsigned int V_10 ;
F_39 (i)
F_40 ( F_41 ( V_75 , V_10 )
-> V_76 ) ;
F_42 ( V_75 ) ;
}
static int T_2 F_43 ( void )
{
unsigned int V_10 ;
F_26 ( L_9 ) ;
V_75 = F_44 ( struct V_8 ) ;
if ( ! V_75 ) {
F_26 ( L_10 ) ;
return - V_77 ;
}
F_39 (i) {
if ( ! F_45 (
& F_41 ( V_75 , V_10 ) -> V_76 ,
V_78 , F_46 ( V_10 ) ) ) {
F_38 () ;
return - V_77 ;
}
}
F_47 ( V_75 ) ;
return 0 ;
}
static int F_48 ( const struct V_79 * V_80 )
{
V_81 = 1 ;
return 0 ;
}
static int F_49 ( struct V_2 * V_82 )
{
if ( V_82 -> V_83 == V_84 ) {
if ( ( V_82 -> V_85 == 15 ) &&
( V_82 -> V_86 == 6 ) &&
( V_82 -> V_87 == 8 ) ) {
F_50 ( V_88 L_11
L_12
L_13
L_14 ) ;
return - V_59 ;
}
}
return 0 ;
}
static int F_51 ( struct V_50 * V_51 )
{
unsigned int V_10 ;
unsigned int V_89 = 0 ;
unsigned int V_3 = V_51 -> V_3 ;
struct V_6 * V_7 ;
unsigned int V_58 = 0 ;
struct V_2 * V_82 = & F_2 ( V_51 -> V_3 ) ;
struct V_8 * V_9 ;
#ifdef F_52
static int V_90 ;
#endif
F_26 ( L_15 ) ;
#ifdef F_52
if ( V_90 )
return V_90 ;
V_90 = F_49 ( V_82 ) ;
if ( V_90 )
return V_90 ;
#endif
V_7 = F_53 ( sizeof( struct V_6 ) , V_78 ) ;
if ( ! V_7 )
return - V_77 ;
V_7 -> V_11 = F_41 ( V_75 , V_3 ) ;
F_24 ( V_41 , V_3 ) = V_7 ;
if ( F_3 ( V_82 , V_91 ) )
V_92 . V_93 |= V_94 ;
V_58 = F_54 ( V_7 -> V_11 , V_3 ) ;
if ( V_58 )
goto V_95;
V_9 = V_7 -> V_11 ;
V_51 -> V_63 = V_9 -> V_63 ;
if ( V_51 -> V_63 == V_96 ||
V_51 -> V_63 == V_64 ) {
F_55 ( V_51 -> V_65 , V_9 -> V_76 ) ;
}
F_55 ( V_51 -> V_97 , V_9 -> V_76 ) ;
#ifdef F_52
F_56 ( V_98 ) ;
if ( V_81 && F_57 ( V_51 -> V_65 ) == 1 ) {
V_51 -> V_63 = V_96 ;
F_55 ( V_51 -> V_65 , F_58 ( V_3 ) ) ;
}
#endif
if ( V_9 -> V_12 <= 1 ) {
F_26 ( L_16 ) ;
V_58 = - V_59 ;
goto V_99;
}
if ( V_9 -> V_43 . V_100 != V_9 -> V_101 . V_100 ) {
V_58 = - V_59 ;
goto V_99;
}
switch ( V_9 -> V_43 . V_100 ) {
case V_102 :
F_26 ( L_17 ) ;
V_7 -> V_22 = V_24 ;
break;
case V_103 :
F_26 ( L_18 ) ;
if ( ! F_1 ( V_3 ) ) {
V_58 = - V_59 ;
goto V_99;
}
V_7 -> V_22 = V_23 ;
break;
default:
F_26 ( L_19 ,
( T_1 ) ( V_9 -> V_43 . V_100 ) ) ;
V_58 = - V_59 ;
goto V_99;
}
V_7 -> V_15 = F_59 ( sizeof( struct V_104 ) *
( V_9 -> V_12 + 1 ) , V_78 ) ;
if ( ! V_7 -> V_15 ) {
V_58 = - V_77 ;
goto V_99;
}
V_51 -> V_105 . V_106 = 0 ;
for ( V_10 = 0 ; V_10 < V_9 -> V_12 ; V_10 ++ ) {
if ( ( V_9 -> V_13 [ V_10 ] . V_106 * 1000 ) >
V_51 -> V_105 . V_106 )
V_51 -> V_105 . V_106 =
V_9 -> V_13 [ V_10 ] . V_106 * 1000 ;
}
if ( V_9 -> V_43 . V_100 == V_103 &&
V_51 -> V_105 . V_106 > 20 * 1000 ) {
V_51 -> V_105 . V_106 = 20 * 1000 ;
F_60 ( V_88
L_20 ) ;
}
for ( V_10 = 0 ; V_10 < V_9 -> V_12 ; V_10 ++ ) {
if ( V_10 > 0 && V_9 -> V_13 [ V_10 ] . V_67 >=
V_7 -> V_15 [ V_89 - 1 ] . V_16 / 1000 )
continue;
V_7 -> V_15 [ V_89 ] . V_20 = V_10 ;
V_7 -> V_15 [ V_89 ] . V_16 =
V_9 -> V_13 [ V_10 ] . V_67 * 1000 ;
V_89 ++ ;
}
V_7 -> V_15 [ V_89 ] . V_16 = V_19 ;
V_9 -> V_47 = 0 ;
V_58 = F_61 ( V_51 , V_7 -> V_15 ) ;
if ( V_58 )
goto V_107;
if ( V_9 -> V_13 [ 0 ] . V_67 * 1000 != V_51 -> V_105 . V_108 )
F_50 (KERN_WARNING FW_WARN L_21 ) ;
switch ( V_9 -> V_43 . V_100 ) {
case V_102 :
V_51 -> V_109 = F_37 ( V_7 , V_51 -> V_3 ) ;
break;
case V_103 :
V_92 . V_110 = F_27 ;
V_51 -> V_109 = F_27 ( V_3 ) ;
break;
default:
break;
}
F_62 ( V_111 ) ;
if ( F_63 ( V_112 ) )
V_92 . V_113 = V_114 ;
F_26 ( L_22 , V_3 ) ;
for ( V_10 = 0 ; V_10 < V_9 -> V_12 ; V_10 ++ )
F_26 ( L_23 ,
( V_10 == V_9 -> V_47 ? '*' : ' ' ) , V_10 ,
( T_1 ) V_9 -> V_13 [ V_10 ] . V_67 ,
( T_1 ) V_9 -> V_13 [ V_10 ] . V_115 ,
( T_1 ) V_9 -> V_13 [ V_10 ] . V_106 ) ;
F_64 ( V_7 -> V_15 , V_51 -> V_3 ) ;
V_7 -> V_48 = 1 ;
return V_58 ;
V_107:
F_65 ( V_7 -> V_15 ) ;
V_99:
F_66 ( V_9 , V_3 ) ;
V_95:
F_65 ( V_7 ) ;
F_24 ( V_41 , V_3 ) = NULL ;
return V_58 ;
}
static int F_67 ( struct V_50 * V_51 )
{
struct V_6 * V_7 = F_24 ( V_41 , V_51 -> V_3 ) ;
F_26 ( L_24 ) ;
if ( V_7 ) {
F_68 ( V_51 -> V_3 ) ;
F_24 ( V_41 , V_51 -> V_3 ) = NULL ;
F_66 ( V_7 -> V_11 ,
V_51 -> V_3 ) ;
F_65 ( V_7 -> V_15 ) ;
F_65 ( V_7 ) ;
}
return 0 ;
}
static int F_69 ( struct V_50 * V_51 )
{
struct V_6 * V_7 = F_24 ( V_41 , V_51 -> V_3 ) ;
F_26 ( L_25 ) ;
V_7 -> V_48 = 1 ;
return 0 ;
}
static int T_2 F_70 ( void )
{
int V_116 ;
if ( V_117 )
return 0 ;
F_26 ( L_26 ) ;
V_116 = F_43 () ;
if ( V_116 )
return V_116 ;
V_116 = F_71 ( & V_92 ) ;
if ( V_116 )
F_38 () ;
return V_116 ;
}
static void T_3 F_72 ( void )
{
F_26 ( L_27 ) ;
F_73 ( & V_92 ) ;
F_38 () ;
}
