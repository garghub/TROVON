static T_1 F_1 ( const char * V_1 ,
struct V_2 * * V_2 )
{
struct V_3 * V_4 ;
T_1 V_5 = NULL ;
F_2 ( & V_6 ) ;
F_3 (iter, &reset_list, link) {
if ( ! strcmp ( V_4 -> V_1 , V_1 ) &&
F_4 ( V_4 -> V_7 ) ) {
* V_2 = V_4 -> V_7 ;
V_5 = V_4 -> V_8 ;
break;
}
}
F_5 ( & V_6 ) ;
return V_5 ;
}
static int F_6 ( struct V_9 * V_10 ,
struct V_11 * V_12 )
{
struct V_13 * V_14 ;
if ( V_15 )
return - V_16 ;
V_14 = F_7 ( V_12 ) ;
if ( ! V_14 ) {
F_8 ( L_1 ,
V_10 -> V_17 ) ;
return - V_18 ;
}
#ifdef F_9
V_10 -> V_19 = F_10 ( V_14 ) ;
#endif
return F_11 ( ! V_10 -> V_19 ) ? - V_20 : 0 ;
}
static int F_12 ( struct V_9 * V_10 ,
const char * * V_21 )
{
#ifdef F_9
struct V_22 V_23 = { V_24 , NULL } ;
struct V_11 * V_12 = V_10 -> V_11 ;
T_2 V_25 = F_13 ( V_12 ) ;
T_3 V_26 ;
V_26 = F_14 ( V_25 , L_2 , NULL , & V_23 ) ;
if ( F_15 ( V_26 ) ) {
if ( V_21 )
* V_21 = F_16 ( V_26 ) ;
return - V_20 ;
}
return 0 ;
#else
return - V_16 ;
#endif
}
static bool F_17 ( struct V_9 * V_10 )
{
#ifdef F_9
struct V_11 * V_12 = V_10 -> V_11 ;
T_2 V_25 = F_13 ( V_12 ) ;
return F_18 ( V_25 , L_2 ) ;
#else
return false ;
#endif
}
static bool F_19 ( struct V_9 * V_10 )
{
if ( F_20 ( V_10 ) )
return F_17 ( V_10 ) ;
return V_10 -> V_8 ? true : false ;
}
static int F_21 ( struct V_9 * V_10 )
{
if ( F_20 ( V_10 ) )
return F_17 ( V_10 ) ? 0 : - V_16 ;
V_10 -> V_8 = F_1 ( V_10 -> V_1 ,
& V_10 -> V_27 ) ;
if ( ! V_10 -> V_8 ) {
F_22 ( L_3 , V_10 -> V_1 ) ;
V_10 -> V_8 = F_1 ( V_10 -> V_1 ,
& V_10 -> V_27 ) ;
}
return V_10 -> V_8 ? 0 : - V_16 ;
}
static void F_23 ( struct V_9 * V_10 )
{
if ( F_20 ( V_10 ) )
return;
if ( V_10 -> V_8 )
F_24 ( V_10 -> V_27 ) ;
}
static int F_25 ( struct V_9 * V_10 )
{
int V_28 = 0 , V_29 ;
while ( V_10 -> V_30 ( V_10 , V_28 ) )
V_28 ++ ;
V_10 -> V_31 = F_26 ( V_28 , sizeof( struct V_32 ) ,
V_33 ) ;
if ( ! V_10 -> V_31 )
return - V_34 ;
for ( V_29 = 0 ; V_29 < V_28 ; V_29 ++ ) {
struct V_35 * V_36 =
V_10 -> V_30 ( V_10 , V_29 ) ;
if ( ! V_36 )
goto V_37;
V_10 -> V_31 [ V_29 ] . V_38 = V_36 -> V_39 ;
V_10 -> V_31 [ V_29 ] . V_40 = F_27 ( V_36 ) ;
V_10 -> V_31 [ V_29 ] . V_41 = 0 ;
switch ( F_28 ( V_36 ) ) {
case V_42 :
V_10 -> V_31 [ V_29 ] . type = V_43 ;
V_10 -> V_31 [ V_29 ] . V_41 |= V_44 ;
if ( ! ( V_36 -> V_41 & V_45 ) )
V_10 -> V_31 [ V_29 ] . V_41 |=
V_46 ;
if ( ! ( V_10 -> V_31 [ V_29 ] . V_38 & ~ V_47 ) &&
! ( V_10 -> V_31 [ V_29 ] . V_40 & ~ V_47 ) )
V_10 -> V_31 [ V_29 ] . V_41 |=
V_48 ;
break;
case V_49 :
V_10 -> V_31 [ V_29 ] . type = V_50 ;
break;
default:
goto V_37;
}
}
V_10 -> V_51 = V_28 ;
return 0 ;
V_37:
F_29 ( V_10 -> V_31 ) ;
return - V_20 ;
}
static void F_30 ( struct V_9 * V_10 )
{
int V_29 ;
for ( V_29 = 0 ; V_29 < V_10 -> V_51 ; V_29 ++ )
F_31 ( V_10 -> V_31 [ V_29 ] . V_52 ) ;
V_10 -> V_51 = 0 ;
F_29 ( V_10 -> V_31 ) ;
}
static int F_32 ( struct V_9 * V_10 ,
const char * * V_21 )
{
if ( F_20 ( V_10 ) ) {
F_33 ( V_10 -> V_11 , L_4 ) ;
return F_12 ( V_10 , V_21 ) ;
} else if ( V_10 -> V_8 ) {
F_33 ( V_10 -> V_11 , L_4 ) ;
return V_10 -> V_8 ( V_10 ) ;
}
F_34 ( V_10 -> V_11 , L_5 ) ;
return - V_20 ;
}
static void F_35 ( void * V_53 )
{
struct V_9 * V_10 = V_53 ;
F_2 ( & V_6 ) ;
if ( ! ( -- V_10 -> V_54 ) ) {
const char * V_21 = NULL ;
int V_55 ;
V_55 = F_32 ( V_10 , & V_21 ) ;
if ( V_55 && V_10 -> V_56 ) {
F_34 ( V_10 -> V_11 , L_6 ,
V_55 , V_21 ? V_21 : L_7 ) ;
F_11 ( 1 ) ;
}
F_30 ( V_10 ) ;
F_36 ( V_10 ) ;
}
F_5 ( & V_6 ) ;
F_24 ( V_10 -> V_57 ) ;
}
static int F_37 ( void * V_53 )
{
struct V_9 * V_10 = V_53 ;
int V_55 ;
if ( ! F_4 ( V_10 -> V_57 ) )
return - V_18 ;
F_2 ( & V_6 ) ;
if ( ! V_10 -> V_54 ) {
const char * V_21 = NULL ;
V_55 = F_25 ( V_10 ) ;
if ( V_55 )
goto V_58;
V_55 = F_38 ( V_10 ) ;
if ( V_55 )
goto V_59;
V_55 = F_32 ( V_10 , & V_21 ) ;
if ( V_55 && V_10 -> V_56 ) {
F_34 ( V_10 -> V_11 , L_8 ,
V_55 , V_21 ? V_21 : L_7 ) ;
goto V_60;
}
}
V_10 -> V_54 ++ ;
F_5 ( & V_6 ) ;
return 0 ;
V_60:
F_36 ( V_10 ) ;
V_59:
F_30 ( V_10 ) ;
V_58:
F_5 ( & V_6 ) ;
F_24 ( V_61 ) ;
return V_55 ;
}
static long F_39 ( void * V_53 ,
unsigned int V_62 , unsigned long V_63 )
{
struct V_9 * V_10 = V_53 ;
unsigned long V_64 ;
if ( V_62 == V_65 ) {
struct V_66 V_67 ;
V_64 = F_40 ( struct V_66 , V_68 ) ;
if ( F_41 ( & V_67 , ( void V_69 * ) V_63 , V_64 ) )
return - V_70 ;
if ( V_67 . V_71 < V_64 )
return - V_20 ;
if ( F_19 ( V_10 ) )
V_10 -> V_41 |= V_72 ;
V_67 . V_41 = V_10 -> V_41 ;
V_67 . V_51 = V_10 -> V_51 ;
V_67 . V_68 = V_10 -> V_68 ;
return F_42 ( ( void V_69 * ) V_63 , & V_67 , V_64 ) ?
- V_70 : 0 ;
} else if ( V_62 == V_73 ) {
struct V_74 V_67 ;
V_64 = F_40 ( struct V_74 , V_75 ) ;
if ( F_41 ( & V_67 , ( void V_69 * ) V_63 , V_64 ) )
return - V_70 ;
if ( V_67 . V_71 < V_64 )
return - V_20 ;
if ( V_67 . V_76 >= V_10 -> V_51 )
return - V_20 ;
V_67 . V_75 = F_43 ( V_67 . V_76 ) ;
V_67 . V_40 = V_10 -> V_31 [ V_67 . V_76 ] . V_40 ;
V_67 . V_41 = V_10 -> V_31 [ V_67 . V_76 ] . V_41 ;
return F_42 ( ( void V_69 * ) V_63 , & V_67 , V_64 ) ?
- V_70 : 0 ;
} else if ( V_62 == V_77 ) {
struct V_78 V_67 ;
V_64 = F_40 ( struct V_78 , V_79 ) ;
if ( F_41 ( & V_67 , ( void V_69 * ) V_63 , V_64 ) )
return - V_70 ;
if ( V_67 . V_71 < V_64 )
return - V_20 ;
if ( V_67 . V_76 >= V_10 -> V_68 )
return - V_20 ;
V_67 . V_41 = V_10 -> V_80 [ V_67 . V_76 ] . V_41 ;
V_67 . V_79 = V_10 -> V_80 [ V_67 . V_76 ] . V_79 ;
return F_42 ( ( void V_69 * ) V_63 , & V_67 , V_64 ) ?
- V_70 : 0 ;
} else if ( V_62 == V_81 ) {
struct V_82 V_83 ;
T_4 * V_84 = NULL ;
int V_55 = 0 ;
T_5 V_85 = 0 ;
V_64 = F_40 ( struct V_82 , V_79 ) ;
if ( F_41 ( & V_83 , ( void V_69 * ) V_63 , V_64 ) )
return - V_70 ;
V_55 = F_44 ( & V_83 , V_10 -> V_68 ,
V_10 -> V_68 , & V_85 ) ;
if ( V_55 )
return V_55 ;
if ( V_85 ) {
V_84 = F_45 ( ( void V_69 * ) ( V_63 + V_64 ) ,
V_85 ) ;
if ( F_46 ( V_84 ) )
return F_47 ( V_84 ) ;
}
F_2 ( & V_10 -> V_86 ) ;
V_55 = F_48 ( V_10 , V_83 . V_41 , V_83 . V_76 ,
V_83 . V_39 , V_83 . V_79 , V_84 ) ;
F_5 ( & V_10 -> V_86 ) ;
F_29 ( V_84 ) ;
return V_55 ;
} else if ( V_62 == V_87 ) {
return F_32 ( V_10 , NULL ) ;
}
return - V_88 ;
}
static T_6 F_49 ( struct V_32 * V_89 ,
char V_69 * V_90 , T_5 V_79 ,
T_7 V_91 )
{
unsigned int V_92 = 0 ;
if ( ! V_89 -> V_52 ) {
V_89 -> V_52 =
F_50 ( V_89 -> V_38 , V_89 -> V_40 ) ;
if ( ! V_89 -> V_52 )
return - V_34 ;
}
while ( V_79 ) {
T_5 V_93 ;
if ( V_79 >= 4 && ! ( V_91 % 4 ) ) {
T_8 V_94 ;
V_94 = F_51 ( V_89 -> V_52 + V_91 ) ;
if ( F_42 ( V_90 , & V_94 , 4 ) )
goto V_37;
V_93 = 4 ;
} else if ( V_79 >= 2 && ! ( V_91 % 2 ) ) {
T_9 V_94 ;
V_94 = F_52 ( V_89 -> V_52 + V_91 ) ;
if ( F_42 ( V_90 , & V_94 , 2 ) )
goto V_37;
V_93 = 2 ;
} else {
T_4 V_94 ;
V_94 = F_53 ( V_89 -> V_52 + V_91 ) ;
if ( F_42 ( V_90 , & V_94 , 1 ) )
goto V_37;
V_93 = 1 ;
}
V_79 -= V_93 ;
V_92 += V_93 ;
V_91 += V_93 ;
V_90 += V_93 ;
}
return V_92 ;
V_37:
return - V_70 ;
}
static T_6 F_54 ( void * V_53 , char V_69 * V_90 ,
T_5 V_79 , T_7 * V_95 )
{
struct V_9 * V_10 = V_53 ;
unsigned int V_76 = F_55 ( * V_95 ) ;
T_7 V_91 = * V_95 & V_96 ;
if ( V_76 >= V_10 -> V_51 )
return - V_20 ;
if ( ! ( V_10 -> V_31 [ V_76 ] . V_41 & V_44 ) )
return - V_20 ;
if ( V_10 -> V_31 [ V_76 ] . type & V_43 )
return F_49 ( & V_10 -> V_31 [ V_76 ] ,
V_90 , V_79 , V_91 ) ;
else if ( V_10 -> V_31 [ V_76 ] . type & V_50 )
return - V_20 ;
return - V_20 ;
}
static T_6 F_56 ( struct V_32 * V_89 ,
const char V_69 * V_90 , T_5 V_79 ,
T_7 V_91 )
{
unsigned int V_92 = 0 ;
if ( ! V_89 -> V_52 ) {
V_89 -> V_52 =
F_50 ( V_89 -> V_38 , V_89 -> V_40 ) ;
if ( ! V_89 -> V_52 )
return - V_34 ;
}
while ( V_79 ) {
T_5 V_93 ;
if ( V_79 >= 4 && ! ( V_91 % 4 ) ) {
T_8 V_94 ;
if ( F_41 ( & V_94 , V_90 , 4 ) )
goto V_37;
F_57 ( V_94 , V_89 -> V_52 + V_91 ) ;
V_93 = 4 ;
} else if ( V_79 >= 2 && ! ( V_91 % 2 ) ) {
T_9 V_94 ;
if ( F_41 ( & V_94 , V_90 , 2 ) )
goto V_37;
F_58 ( V_94 , V_89 -> V_52 + V_91 ) ;
V_93 = 2 ;
} else {
T_4 V_94 ;
if ( F_41 ( & V_94 , V_90 , 1 ) )
goto V_37;
F_59 ( V_94 , V_89 -> V_52 + V_91 ) ;
V_93 = 1 ;
}
V_79 -= V_93 ;
V_92 += V_93 ;
V_91 += V_93 ;
V_90 += V_93 ;
}
return V_92 ;
V_37:
return - V_70 ;
}
static T_6 F_60 ( void * V_53 , const char V_69 * V_90 ,
T_5 V_79 , T_7 * V_95 )
{
struct V_9 * V_10 = V_53 ;
unsigned int V_76 = F_55 ( * V_95 ) ;
T_7 V_91 = * V_95 & V_96 ;
if ( V_76 >= V_10 -> V_51 )
return - V_20 ;
if ( ! ( V_10 -> V_31 [ V_76 ] . V_41 & V_46 ) )
return - V_20 ;
if ( V_10 -> V_31 [ V_76 ] . type & V_43 )
return F_56 ( & V_10 -> V_31 [ V_76 ] ,
V_90 , V_79 , V_91 ) ;
else if ( V_10 -> V_31 [ V_76 ] . type & V_50 )
return - V_20 ;
return - V_20 ;
}
static int F_61 ( struct V_32 V_97 ,
struct V_98 * V_99 )
{
T_10 V_100 , V_101 , V_102 ;
V_100 = V_99 -> V_103 - V_99 -> V_104 ;
V_101 = V_99 -> V_105 &
( ( 1U << ( V_106 - V_107 ) ) - 1 ) ;
V_102 = V_101 << V_107 ;
if ( V_97 . V_40 < V_108 || V_102 + V_100 > V_97 . V_40 )
return - V_20 ;
V_99 -> V_109 = F_62 ( V_99 -> V_109 ) ;
V_99 -> V_105 = ( V_97 . V_38 >> V_107 ) + V_101 ;
return F_63 ( V_99 , V_99 -> V_104 , V_99 -> V_105 ,
V_100 , V_99 -> V_109 ) ;
}
static int F_64 ( void * V_53 , struct V_98 * V_99 )
{
struct V_9 * V_10 = V_53 ;
unsigned int V_76 ;
V_76 = V_99 -> V_105 >> ( V_106 - V_107 ) ;
if ( V_99 -> V_103 < V_99 -> V_104 )
return - V_20 ;
if ( ! ( V_99 -> V_110 & V_111 ) )
return - V_20 ;
if ( V_76 >= V_10 -> V_51 )
return - V_20 ;
if ( V_99 -> V_104 & ~ V_47 )
return - V_20 ;
if ( V_99 -> V_103 & ~ V_47 )
return - V_20 ;
if ( ! ( V_10 -> V_31 [ V_76 ] . V_41 & V_48 ) )
return - V_20 ;
if ( ! ( V_10 -> V_31 [ V_76 ] . V_41 & V_44 )
&& ( V_99 -> V_110 & V_112 ) )
return - V_20 ;
if ( ! ( V_10 -> V_31 [ V_76 ] . V_41 & V_46 )
&& ( V_99 -> V_110 & V_113 ) )
return - V_20 ;
V_99 -> V_114 = V_10 ;
if ( V_10 -> V_31 [ V_76 ] . type & V_43 )
return F_61 ( V_10 -> V_31 [ V_76 ] , V_99 ) ;
else if ( V_10 -> V_31 [ V_76 ] . type & V_50 )
return - V_20 ;
return - V_20 ;
}
static int F_65 ( struct V_9 * V_10 ,
struct V_11 * V_12 )
{
int V_55 ;
V_55 = F_66 ( V_12 , L_9 ,
& V_10 -> V_1 ) ;
if ( V_55 )
F_8 ( L_10 ,
V_10 -> V_17 ) ;
return V_55 ;
}
int F_67 ( struct V_9 * V_10 ,
struct V_11 * V_12 )
{
struct V_115 * V_116 ;
int V_55 ;
if ( ! V_10 )
return - V_20 ;
V_55 = F_6 ( V_10 , V_12 ) ;
if ( V_55 )
V_55 = F_65 ( V_10 , V_12 ) ;
if ( V_55 )
return V_55 ;
V_10 -> V_11 = V_12 ;
V_55 = F_21 ( V_10 ) ;
if ( V_55 && V_10 -> V_56 ) {
F_8 ( L_11 ,
V_10 -> V_17 ) ;
return V_55 ;
}
V_116 = F_68 ( V_12 ) ;
if ( ! V_116 ) {
F_8 ( L_12 , V_10 -> V_17 ) ;
return - V_20 ;
}
V_55 = F_69 ( V_12 , & V_117 , V_10 ) ;
if ( V_55 ) {
F_70 ( V_116 , V_12 ) ;
return V_55 ;
}
F_71 ( & V_10 -> V_86 ) ;
return 0 ;
}
struct V_9 * F_72 ( struct V_11 * V_12 )
{
struct V_9 * V_10 ;
V_10 = F_73 ( V_12 ) ;
if ( V_10 ) {
F_23 ( V_10 ) ;
F_70 ( V_12 -> V_115 , V_12 ) ;
}
return V_10 ;
}
void F_74 ( struct V_3 * V_118 )
{
F_2 ( & V_6 ) ;
F_75 ( & V_118 -> V_119 , & V_120 ) ;
F_5 ( & V_6 ) ;
}
void F_76 ( const char * V_1 ,
T_1 V_121 )
{
struct V_3 * V_4 , * V_122 ;
F_2 ( & V_6 ) ;
F_77 (iter, temp, &reset_list, link) {
if ( ! strcmp ( V_4 -> V_1 , V_1 ) && ( V_4 -> V_8 == V_121 ) ) {
F_78 ( & V_4 -> V_119 ) ;
break;
}
}
F_5 ( & V_6 ) ;
}
