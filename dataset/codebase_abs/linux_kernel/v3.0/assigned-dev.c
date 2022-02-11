static struct V_1 * F_1 ( struct V_2 * V_3 ,
int V_4 )
{
struct V_2 * V_5 ;
struct V_1 * V_6 ;
F_2 (ptr, head) {
V_6 = F_3 ( V_5 , struct V_1 , V_7 ) ;
if ( V_6 -> V_4 == V_4 )
return V_6 ;
}
return NULL ;
}
static int F_4 ( struct V_1
* V_8 , int V_9 )
{
int V_10 , V_11 ;
struct V_12 * V_13 ;
V_13 = V_8 -> V_13 ;
V_11 = - 1 ;
for ( V_10 = 0 ; V_10 < V_8 -> V_14 ; V_10 ++ )
if ( V_9 == V_13 [ V_10 ] . V_15 ) {
V_11 = V_10 ;
break;
}
if ( V_11 < 0 ) {
F_5 ( V_16 L_1 ) ;
return 0 ;
}
return V_11 ;
}
static T_1 F_6 ( int V_9 , void * V_17 )
{
struct V_1 * V_8 = V_17 ;
T_2 V_15 ;
int V_11 ;
if ( V_8 -> V_18 & V_19 ) {
F_7 ( & V_8 -> V_20 ) ;
F_8 ( V_9 ) ;
V_8 -> V_21 = true ;
F_9 ( & V_8 -> V_20 ) ;
}
if ( V_8 -> V_18 & V_22 ) {
V_11 = F_4 ( V_8 , V_9 ) ;
if ( V_11 >= 0 ) {
V_15 = V_8 ->
V_23 [ V_11 ] . V_15 ;
F_10 ( V_8 -> V_24 ,
V_8 -> V_25 , V_15 , 1 ) ;
}
} else
F_10 ( V_8 -> V_24 , V_8 -> V_25 ,
V_8 -> V_26 , 1 ) ;
return V_27 ;
}
static void F_11 ( struct V_28 * V_29 )
{
struct V_1 * V_30 ;
if ( V_29 -> V_31 == - 1 )
return;
V_30 = F_12 ( V_29 , struct V_1 ,
V_32 ) ;
F_10 ( V_30 -> V_24 , V_30 -> V_25 , V_30 -> V_26 , 0 ) ;
F_7 ( & V_30 -> V_20 ) ;
if ( V_30 -> V_21 ) {
F_13 ( V_30 -> V_33 ) ;
V_30 -> V_21 = false ;
}
F_9 ( & V_30 -> V_20 ) ;
}
static void F_14 ( struct V_24 * V_24 ,
struct V_1 * V_8 )
{
F_15 ( V_24 , & V_8 -> V_32 ) ;
V_8 -> V_32 . V_31 = - 1 ;
F_10 ( V_8 -> V_24 , V_8 -> V_25 ,
V_8 -> V_26 , 0 ) ;
if ( V_8 -> V_25 != - 1 )
F_16 ( V_24 , V_8 -> V_25 ) ;
V_8 -> V_25 = - 1 ;
V_8 -> V_18 &= ~ ( V_34 ) ;
}
static void F_17 ( struct V_24 * V_24 ,
struct V_1 * V_8 )
{
if ( V_8 -> V_18 & V_22 ) {
int V_10 ;
for ( V_10 = 0 ; V_10 < V_8 -> V_14 ; V_10 ++ )
F_18 ( V_8 -> V_13 [ V_10 ] . V_15 ) ;
for ( V_10 = 0 ; V_10 < V_8 -> V_14 ; V_10 ++ )
F_19 ( V_8 -> V_13 [ V_10 ] . V_15 ,
( void * ) V_8 ) ;
V_8 -> V_14 = 0 ;
F_20 ( V_8 -> V_13 ) ;
F_20 ( V_8 -> V_23 ) ;
F_21 ( V_8 -> V_30 ) ;
} else {
F_18 ( V_8 -> V_33 ) ;
F_19 ( V_8 -> V_33 , ( void * ) V_8 ) ;
if ( V_8 -> V_18 & V_35 )
F_22 ( V_8 -> V_30 ) ;
}
V_8 -> V_18 &= ~ ( V_36 ) ;
}
static int F_23 ( struct V_24 * V_24 ,
struct V_1 * V_8 ,
unsigned long V_18 )
{
unsigned long V_37 , V_38 ;
if ( ! F_24 ( V_24 ) )
return - V_39 ;
if ( ! V_8 -> V_18 )
return - V_40 ;
V_38 = V_18 & V_36 ;
V_37 = V_18 & V_34 ;
if ( V_38 )
F_17 ( V_24 , V_8 ) ;
if ( V_37 )
F_14 ( V_24 , V_8 ) ;
return 0 ;
}
static void F_25 ( struct V_24 * V_24 ,
struct V_1 * V_8 )
{
F_23 ( V_24 , V_8 , V_8 -> V_18 ) ;
}
static void F_26 ( struct V_24 * V_24 ,
struct V_1
* V_8 )
{
F_25 ( V_24 , V_8 ) ;
F_27 ( V_8 -> V_30 ) ;
if ( F_28 ( V_8 -> V_30 ,
& V_8 -> V_41 ) )
F_5 ( V_42 L_2 ,
V_43 , F_29 ( & V_8 -> V_30 -> V_30 ) ) ;
else
F_30 ( V_8 -> V_30 ) ;
F_31 ( V_8 -> V_30 ) ;
F_32 ( V_8 -> V_30 ) ;
F_33 ( V_8 -> V_30 ) ;
F_34 ( & V_8 -> V_7 ) ;
F_20 ( V_8 ) ;
}
void F_35 ( struct V_24 * V_24 )
{
struct V_2 * V_5 , * V_44 ;
struct V_1 * V_8 ;
F_36 (ptr, ptr2, &kvm->arch.assigned_dev_head) {
V_8 = F_3 ( V_5 ,
struct V_1 ,
V_7 ) ;
F_26 ( V_24 , V_8 ) ;
}
}
static int F_37 ( struct V_24 * V_24 ,
struct V_1 * V_30 )
{
V_30 -> V_33 = V_30 -> V_30 -> V_9 ;
if ( F_38 ( V_30 -> V_33 , NULL , F_6 ,
V_45 , V_30 -> V_46 , ( void * ) V_30 ) )
return - V_47 ;
return 0 ;
}
static int F_39 ( struct V_24 * V_24 ,
struct V_1 * V_30 )
{
int V_48 ;
if ( ! V_30 -> V_30 -> V_49 ) {
V_48 = F_40 ( V_30 -> V_30 ) ;
if ( V_48 )
return V_48 ;
}
V_30 -> V_33 = V_30 -> V_30 -> V_9 ;
if ( F_38 ( V_30 -> V_33 , NULL , F_6 ,
0 , V_30 -> V_46 , ( void * ) V_30 ) ) {
F_22 ( V_30 -> V_30 ) ;
return - V_47 ;
}
return 0 ;
}
static int F_41 ( struct V_24 * V_24 ,
struct V_1 * V_30 )
{
int V_10 , V_48 = - V_39 ;
if ( V_30 -> V_14 == 0 )
return V_48 ;
V_48 = F_42 ( V_30 -> V_30 , V_30 -> V_13 , V_30 -> V_14 ) ;
if ( V_48 )
return V_48 ;
for ( V_10 = 0 ; V_10 < V_30 -> V_14 ; V_10 ++ ) {
V_48 = F_38 ( V_30 -> V_13 [ V_10 ] . V_15 ,
NULL , F_6 ,
0 , V_30 -> V_46 , ( void * ) V_30 ) ;
if ( V_48 )
goto V_50;
}
return 0 ;
V_50:
for ( V_10 -= 1 ; V_10 >= 0 ; V_10 -- )
F_19 ( V_30 -> V_13 [ V_10 ] . V_15 , ( void * ) V_30 ) ;
F_21 ( V_30 -> V_30 ) ;
return V_48 ;
}
static int F_43 ( struct V_24 * V_24 ,
struct V_1 * V_30 ,
struct V_51 * V_9 )
{
V_30 -> V_26 = V_9 -> V_26 ;
V_30 -> V_32 . V_31 = V_9 -> V_26 ;
return 0 ;
}
static int F_44 ( struct V_24 * V_24 ,
struct V_1 * V_30 ,
struct V_51 * V_9 )
{
V_30 -> V_26 = V_9 -> V_26 ;
V_30 -> V_32 . V_31 = - 1 ;
V_30 -> V_21 = false ;
return 0 ;
}
static int F_45 ( struct V_24 * V_24 ,
struct V_1 * V_30 ,
struct V_51 * V_9 )
{
V_30 -> V_26 = V_9 -> V_26 ;
V_30 -> V_32 . V_31 = - 1 ;
V_30 -> V_21 = false ;
return 0 ;
}
static int F_46 ( struct V_24 * V_24 ,
struct V_1 * V_30 ,
T_3 V_38 )
{
int V_48 = - V_52 ;
if ( V_30 -> V_18 & V_36 )
return V_48 ;
snprintf ( V_30 -> V_46 , sizeof( V_30 -> V_46 ) , L_3 ,
F_47 ( V_30 -> V_30 ) ) ;
switch ( V_38 ) {
case V_19 :
V_48 = F_37 ( V_24 , V_30 ) ;
break;
#ifdef F_48
case V_35 :
V_48 = F_39 ( V_24 , V_30 ) ;
break;
#endif
#ifdef F_49
case V_22 :
V_48 = F_41 ( V_24 , V_30 ) ;
break;
#endif
default:
V_48 = - V_39 ;
}
if ( ! V_48 )
V_30 -> V_18 |= V_38 ;
return V_48 ;
}
static int F_50 ( struct V_24 * V_24 ,
struct V_1 * V_30 ,
struct V_51 * V_9 ,
unsigned long V_37 )
{
int V_53 ;
int V_48 = - V_52 ;
if ( V_30 -> V_18 & V_34 )
return V_48 ;
V_53 = F_51 ( V_24 ) ;
if ( V_53 < 0 )
return V_53 ;
V_30 -> V_25 = V_53 ;
switch ( V_37 ) {
case V_54 :
V_48 = F_43 ( V_24 , V_30 , V_9 ) ;
break;
#ifdef F_48
case V_55 :
V_48 = F_44 ( V_24 , V_30 , V_9 ) ;
break;
#endif
#ifdef F_49
case V_56 :
V_48 = F_45 ( V_24 , V_30 , V_9 ) ;
break;
#endif
default:
V_48 = - V_39 ;
}
if ( ! V_48 ) {
V_30 -> V_18 |= V_37 ;
F_52 ( V_24 , & V_30 -> V_32 ) ;
} else
F_16 ( V_24 , V_30 -> V_25 ) ;
return V_48 ;
}
static int F_53 ( struct V_24 * V_24 ,
struct V_51 * V_57 )
{
int V_48 = - V_39 ;
struct V_1 * V_6 ;
unsigned long V_38 , V_37 ;
if ( ! F_24 ( V_24 ) )
return V_48 ;
F_54 ( & V_24 -> V_58 ) ;
V_48 = - V_59 ;
V_6 = F_1 ( & V_24 -> V_60 . V_61 ,
V_57 -> V_4 ) ;
if ( ! V_6 )
goto V_62;
V_38 = ( V_57 -> V_63 & V_36 ) ;
V_37 = ( V_57 -> V_63 & V_34 ) ;
V_48 = - V_39 ;
if ( F_55 ( V_38 ) > 1 )
goto V_62;
if ( F_55 ( V_37 ) > 1 )
goto V_62;
if ( V_38 == 0 && V_37 == 0 )
goto V_62;
V_48 = 0 ;
if ( V_38 )
V_48 = F_46 ( V_24 , V_6 , V_38 ) ;
if ( V_48 )
goto V_62;
if ( V_37 )
V_48 = F_50 ( V_24 , V_6 , V_57 , V_37 ) ;
V_62:
F_56 ( & V_24 -> V_58 ) ;
return V_48 ;
}
static int F_57 ( struct V_24 * V_24 ,
struct V_51
* V_57 )
{
int V_48 = - V_59 ;
struct V_1 * V_6 ;
F_54 ( & V_24 -> V_58 ) ;
V_6 = F_1 ( & V_24 -> V_60 . V_61 ,
V_57 -> V_4 ) ;
if ( ! V_6 )
goto V_62;
V_48 = F_23 ( V_24 , V_6 , V_57 -> V_63 ) ;
V_62:
F_56 ( & V_24 -> V_58 ) ;
return V_48 ;
}
static int F_58 ( struct V_24 * V_24 ,
struct V_64 * V_8 )
{
int V_48 = 0 , V_65 ;
struct V_1 * V_6 ;
struct V_66 * V_30 ;
F_54 ( & V_24 -> V_58 ) ;
V_65 = F_59 ( & V_24 -> V_67 ) ;
V_6 = F_1 ( & V_24 -> V_60 . V_61 ,
V_8 -> V_4 ) ;
if ( V_6 ) {
V_48 = - V_52 ;
goto V_62;
}
V_6 = F_60 ( sizeof( struct V_1 ) , V_68 ) ;
if ( V_6 == NULL ) {
F_5 ( V_42 L_4 ,
V_43 ) ;
V_48 = - V_69 ;
goto V_62;
}
V_30 = F_61 ( V_8 -> V_70 ,
V_8 -> V_71 ,
V_8 -> V_72 ) ;
if ( ! V_30 ) {
F_5 ( V_42 L_5 , V_43 ) ;
V_48 = - V_39 ;
goto V_73;
}
if ( F_62 ( V_30 ) ) {
F_5 ( V_42 L_6 , V_43 ) ;
V_48 = - V_74 ;
goto V_75;
}
V_48 = F_63 ( V_30 , L_7 ) ;
if ( V_48 ) {
F_5 ( V_42 L_8 ,
V_43 ) ;
goto V_76;
}
F_27 ( V_30 ) ;
F_64 ( V_30 ) ;
V_6 -> V_41 = F_65 ( V_30 ) ;
if ( ! V_6 -> V_41 )
F_5 ( V_77 L_9 ,
V_43 , F_29 ( & V_30 -> V_30 ) ) ;
V_6 -> V_4 = V_8 -> V_4 ;
V_6 -> V_78 = V_8 -> V_70 ;
V_6 -> V_79 = V_8 -> V_71 ;
V_6 -> V_80 = V_8 -> V_72 ;
V_6 -> V_63 = V_8 -> V_63 ;
V_6 -> V_30 = V_30 ;
F_66 ( & V_6 -> V_20 ) ;
V_6 -> V_25 = - 1 ;
V_6 -> V_24 = V_24 ;
V_6 -> V_32 . V_81 = F_11 ;
F_67 ( & V_6 -> V_7 , & V_24 -> V_60 . V_61 ) ;
if ( V_8 -> V_63 & V_82 ) {
if ( ! V_24 -> V_60 . V_83 ) {
V_48 = F_68 ( V_24 ) ;
if ( V_48 )
goto V_84;
}
V_48 = F_69 ( V_24 , V_6 ) ;
if ( V_48 )
goto V_84;
}
V_62:
F_70 ( & V_24 -> V_67 , V_65 ) ;
F_56 ( & V_24 -> V_58 ) ;
return V_48 ;
V_84:
if ( F_28 ( V_30 , & V_6 -> V_41 ) )
F_5 ( V_42 L_2 ,
V_43 , F_29 ( & V_30 -> V_30 ) ) ;
F_34 ( & V_6 -> V_7 ) ;
F_31 ( V_30 ) ;
V_76:
F_32 ( V_30 ) ;
V_75:
F_33 ( V_30 ) ;
V_73:
F_20 ( V_6 ) ;
F_70 ( & V_24 -> V_67 , V_65 ) ;
F_56 ( & V_24 -> V_58 ) ;
return V_48 ;
}
static int F_71 ( struct V_24 * V_24 ,
struct V_64 * V_8 )
{
int V_48 = 0 ;
struct V_1 * V_6 ;
F_54 ( & V_24 -> V_58 ) ;
V_6 = F_1 ( & V_24 -> V_60 . V_61 ,
V_8 -> V_4 ) ;
if ( ! V_6 ) {
F_5 ( V_42 L_10
L_11 , V_43 ) ;
V_48 = - V_39 ;
goto V_62;
}
if ( V_6 -> V_63 & V_82 )
F_72 ( V_24 , V_6 ) ;
F_26 ( V_24 , V_6 ) ;
V_62:
F_56 ( & V_24 -> V_58 ) ;
return V_48 ;
}
static int F_73 ( struct V_24 * V_24 ,
struct V_85 * V_86 )
{
int V_48 = 0 ;
struct V_1 * V_87 ;
F_54 ( & V_24 -> V_58 ) ;
V_87 = F_1 ( & V_24 -> V_60 . V_61 ,
V_86 -> V_4 ) ;
if ( ! V_87 ) {
V_48 = - V_39 ;
goto V_88;
}
if ( V_87 -> V_14 == 0 ) {
V_87 -> V_14 = V_86 -> V_86 ;
if ( V_87 -> V_14 == 0 ||
V_87 -> V_14 >= V_89 ) {
V_48 = - V_39 ;
goto V_88;
}
V_87 -> V_13 = F_60 ( sizeof( struct V_12 ) *
V_86 -> V_86 ,
V_68 ) ;
if ( ! V_87 -> V_13 ) {
V_48 = - V_69 ;
goto V_88;
}
V_87 -> V_23 =
F_60 ( sizeof( struct V_12 ) * V_86 -> V_86 ,
V_68 ) ;
if ( ! V_87 -> V_23 ) {
F_20 ( V_87 -> V_13 ) ;
V_48 = - V_69 ;
goto V_88;
}
} else
V_48 = - V_39 ;
V_88:
F_56 ( & V_24 -> V_58 ) ;
return V_48 ;
}
static int F_74 ( struct V_24 * V_24 ,
struct V_90 * V_91 )
{
int V_48 = 0 , V_10 ;
struct V_1 * V_87 ;
F_54 ( & V_24 -> V_58 ) ;
V_87 = F_1 ( & V_24 -> V_60 . V_61 ,
V_91 -> V_4 ) ;
if ( ! V_87 ) {
V_48 = - V_39 ;
goto V_92;
}
for ( V_10 = 0 ; V_10 < V_87 -> V_14 ; V_10 ++ )
if ( V_87 -> V_23 [ V_10 ] . V_15 == 0 ||
V_87 -> V_23 [ V_10 ] . V_91 == V_91 -> V_91 ) {
V_87 -> V_23 [ V_10 ] . V_91 = V_91 -> V_91 ;
V_87 -> V_23 [ V_10 ] . V_15 = V_91 -> V_31 ;
V_87 -> V_13 [ V_10 ] . V_91 = V_91 -> V_91 ;
break;
}
if ( V_10 == V_87 -> V_14 ) {
V_48 = - V_93 ;
goto V_92;
}
V_92:
F_56 ( & V_24 -> V_58 ) ;
return V_48 ;
}
long F_75 ( struct V_24 * V_24 , unsigned V_94 ,
unsigned long V_95 )
{
void T_4 * V_96 = ( void T_4 * ) V_95 ;
int V_48 ;
switch ( V_94 ) {
case V_97 : {
struct V_64 V_8 ;
V_48 = - V_98 ;
if ( F_76 ( & V_8 , V_96 , sizeof V_8 ) )
goto V_62;
V_48 = F_58 ( V_24 , & V_8 ) ;
if ( V_48 )
goto V_62;
break;
}
case V_99 : {
V_48 = - V_100 ;
break;
}
case V_101 : {
struct V_51 V_57 ;
V_48 = - V_98 ;
if ( F_76 ( & V_57 , V_96 , sizeof V_57 ) )
goto V_62;
V_48 = F_53 ( V_24 , & V_57 ) ;
if ( V_48 )
goto V_62;
break;
}
case V_102 : {
struct V_51 V_57 ;
V_48 = - V_98 ;
if ( F_76 ( & V_57 , V_96 , sizeof V_57 ) )
goto V_62;
V_48 = F_57 ( V_24 , & V_57 ) ;
if ( V_48 )
goto V_62;
break;
}
case V_103 : {
struct V_64 V_8 ;
V_48 = - V_98 ;
if ( F_76 ( & V_8 , V_96 , sizeof V_8 ) )
goto V_62;
V_48 = F_71 ( V_24 , & V_8 ) ;
if ( V_48 )
goto V_62;
break;
}
#ifdef F_77
case V_104 : {
struct V_105 V_106 ;
struct V_105 T_4 * V_107 ;
struct V_108 * V_109 ;
V_48 = - V_98 ;
if ( F_76 ( & V_106 , V_96 , sizeof( V_106 ) ) )
goto V_62;
V_48 = - V_39 ;
if ( V_106 . V_110 >= V_111 )
goto V_62;
if ( V_106 . V_63 )
goto V_62;
V_48 = - V_69 ;
V_109 = F_78 ( V_106 . V_110 * sizeof( * V_109 ) ) ;
if ( ! V_109 )
goto V_62;
V_48 = - V_98 ;
V_107 = V_96 ;
if ( F_76 ( V_109 , V_107 -> V_109 ,
V_106 . V_110 * sizeof( * V_109 ) ) )
goto V_112;
V_48 = F_79 ( V_24 , V_109 , V_106 . V_110 ,
V_106 . V_63 ) ;
V_112:
F_80 ( V_109 ) ;
break;
}
#endif
#ifdef F_49
case V_113 : {
struct V_85 V_86 ;
V_48 = - V_98 ;
if ( F_76 ( & V_86 , V_96 , sizeof V_86 ) )
goto V_62;
V_48 = F_73 ( V_24 , & V_86 ) ;
if ( V_48 )
goto V_62;
break;
}
case V_114 : {
struct V_90 V_91 ;
V_48 = - V_98 ;
if ( F_76 ( & V_91 , V_96 , sizeof V_91 ) )
goto V_62;
V_48 = F_74 ( V_24 , & V_91 ) ;
if ( V_48 )
goto V_62;
break;
}
#endif
default:
V_48 = - V_115 ;
break;
}
V_62:
return V_48 ;
}
