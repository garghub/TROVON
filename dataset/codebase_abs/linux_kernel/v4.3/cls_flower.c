static unsigned short int F_1 ( const struct V_1 * V_2 )
{
return V_2 -> V_3 . V_4 - V_2 -> V_3 . V_5 ;
}
static void F_2 ( struct V_1 * V_2 )
{
const T_1 * V_6 = ( const T_1 * ) & V_2 -> V_7 ;
T_2 V_8 = sizeof( V_2 -> V_7 ) ;
T_2 V_9 , V_10 = 0 , V_11 = V_8 - 1 ;
for ( V_9 = 0 ; V_9 < sizeof( V_2 -> V_7 ) ; V_9 ++ ) {
if ( V_6 [ V_9 ] ) {
if ( ! V_10 && V_9 )
V_10 = V_9 ;
V_11 = V_9 ;
}
}
V_2 -> V_3 . V_5 = F_3 ( V_10 , sizeof( long ) ) ;
V_2 -> V_3 . V_4 = F_4 ( V_11 + 1 , sizeof( long ) ) ;
}
static void * F_5 ( struct V_12 * V_7 ,
const struct V_1 * V_2 )
{
return ( T_1 * ) V_7 + V_2 -> V_3 . V_5 ;
}
static void F_6 ( struct V_12 * V_13 , struct V_12 * V_7 ,
struct V_1 * V_2 )
{
const long * V_14 = F_5 ( V_7 , V_2 ) ;
const long * V_15 = F_5 ( & V_2 -> V_7 , V_2 ) ;
long * V_16 = F_5 ( V_13 , V_2 ) ;
int V_9 ;
for ( V_9 = 0 ; V_9 < F_1 ( V_2 ) ; V_9 += sizeof( long ) )
* V_16 ++ = * V_14 ++ & * V_15 ++ ;
}
static void F_7 ( struct V_12 * V_7 ,
struct V_1 * V_2 )
{
memset ( F_5 ( V_7 , V_2 ) , 0 , F_1 ( V_2 ) ) ;
}
static int F_8 ( struct V_17 * V_18 , const struct V_19 * V_20 ,
struct V_21 * V_22 )
{
struct V_23 * V_24 = F_9 ( V_20 -> V_25 ) ;
struct V_26 * V_27 ;
struct V_12 V_28 ;
struct V_12 V_29 ;
F_7 ( & V_28 , & V_24 -> V_2 ) ;
V_28 . V_30 = V_18 -> V_31 ;
V_28 . V_32 . V_33 = V_18 -> V_34 ;
F_10 ( V_18 , & V_24 -> V_35 , & V_28 , 0 ) ;
F_6 ( & V_29 , & V_28 , & V_24 -> V_2 ) ;
V_27 = F_11 ( & V_24 -> V_36 ,
F_5 ( & V_29 , & V_24 -> V_2 ) ,
V_24 -> V_37 ) ;
if ( V_27 ) {
* V_22 = V_27 -> V_22 ;
return F_12 ( V_18 , & V_27 -> V_38 , V_22 ) ;
}
return - 1 ;
}
static int F_13 ( struct V_19 * V_20 )
{
struct V_23 * V_24 ;
V_24 = F_14 ( sizeof( * V_24 ) , V_39 ) ;
if ( ! V_24 )
return - V_40 ;
F_15 ( & V_24 -> V_41 ) ;
F_16 ( V_20 -> V_25 , V_24 ) ;
return 0 ;
}
static void F_17 ( struct V_42 * V_24 )
{
struct V_26 * V_27 = F_18 ( V_24 , struct V_26 , V_43 ) ;
F_19 ( & V_27 -> V_38 ) ;
F_20 ( V_27 ) ;
}
static bool F_21 ( struct V_19 * V_20 , bool V_44 )
{
struct V_23 * V_24 = F_22 ( V_20 -> V_25 ) ;
struct V_26 * V_27 , * V_45 ;
if ( ! V_44 && ! F_23 ( & V_24 -> V_41 ) )
return false ;
F_24 (f, next, &head->filters, list) {
F_25 ( & V_27 -> V_46 ) ;
F_26 ( & V_27 -> V_43 , F_17 ) ;
}
F_27 ( V_20 -> V_25 , NULL ) ;
if ( V_24 -> V_47 )
F_28 ( & V_24 -> V_36 ) ;
F_29 ( V_24 , V_43 ) ;
return true ;
}
static unsigned long F_30 ( struct V_19 * V_20 , T_3 V_48 )
{
struct V_23 * V_24 = F_22 ( V_20 -> V_25 ) ;
struct V_26 * V_27 ;
F_31 (f, &head->filters, list)
if ( V_27 -> V_48 == V_48 )
return ( unsigned long ) V_27 ;
return 0 ;
}
static void F_32 ( struct V_49 * * V_50 ,
void * V_51 , int V_52 ,
void * V_2 , int V_53 , int V_54 )
{
if ( ! V_50 [ V_52 ] )
return;
memcpy ( V_51 , F_33 ( V_50 [ V_52 ] ) , V_54 ) ;
if ( V_53 == V_55 || ! V_50 [ V_53 ] )
memset ( V_2 , 0xff , V_54 ) ;
else
memcpy ( V_2 , F_33 ( V_50 [ V_53 ] ) , V_54 ) ;
}
static int F_34 ( struct V_56 * V_56 , struct V_49 * * V_50 ,
struct V_12 * V_7 , struct V_12 * V_2 )
{
#ifdef F_35
if ( V_50 [ V_57 ] ) {
int V_58 = F_36 ( V_56 , V_50 [ V_57 ] ) ;
if ( V_58 < 0 )
return V_58 ;
V_7 -> V_30 = V_58 ;
V_2 -> V_30 = 0xffffffff ;
}
#endif
F_32 ( V_50 , V_7 -> V_59 . V_60 , V_61 ,
V_2 -> V_59 . V_60 , V_62 ,
sizeof( V_7 -> V_59 . V_60 ) ) ;
F_32 ( V_50 , V_7 -> V_59 . V_63 , V_64 ,
V_2 -> V_59 . V_63 , V_65 ,
sizeof( V_7 -> V_59 . V_63 ) ) ;
F_32 ( V_50 , & V_7 -> V_32 . V_33 , V_66 ,
& V_2 -> V_32 . V_33 , V_55 ,
sizeof( V_7 -> V_32 . V_33 ) ) ;
if ( V_7 -> V_32 . V_33 == F_37 ( V_67 ) ||
V_7 -> V_32 . V_33 == F_37 ( V_68 ) ) {
F_32 ( V_50 , & V_7 -> V_32 . V_69 , V_70 ,
& V_2 -> V_32 . V_69 , V_55 ,
sizeof( V_7 -> V_32 . V_69 ) ) ;
}
if ( V_7 -> V_71 . V_72 == V_73 ) {
F_32 ( V_50 , & V_7 -> V_74 . V_63 , V_75 ,
& V_2 -> V_74 . V_63 , V_76 ,
sizeof( V_7 -> V_74 . V_63 ) ) ;
F_32 ( V_50 , & V_7 -> V_74 . V_60 , V_77 ,
& V_2 -> V_74 . V_60 , V_78 ,
sizeof( V_7 -> V_74 . V_60 ) ) ;
} else if ( V_7 -> V_71 . V_72 == V_79 ) {
F_32 ( V_50 , & V_7 -> V_80 . V_63 , V_81 ,
& V_2 -> V_80 . V_63 , V_82 ,
sizeof( V_7 -> V_80 . V_63 ) ) ;
F_32 ( V_50 , & V_7 -> V_80 . V_60 , V_83 ,
& V_2 -> V_80 . V_60 , V_84 ,
sizeof( V_7 -> V_80 . V_60 ) ) ;
}
if ( V_7 -> V_32 . V_69 == V_85 ) {
F_32 ( V_50 , & V_7 -> V_20 . V_63 , V_86 ,
& V_2 -> V_20 . V_63 , V_55 ,
sizeof( V_7 -> V_20 . V_63 ) ) ;
F_32 ( V_50 , & V_7 -> V_20 . V_60 , V_87 ,
& V_2 -> V_20 . V_60 , V_55 ,
sizeof( V_7 -> V_20 . V_60 ) ) ;
} else if ( V_7 -> V_32 . V_69 == V_88 ) {
F_32 ( V_50 , & V_7 -> V_20 . V_63 , V_89 ,
& V_2 -> V_20 . V_63 , V_55 ,
sizeof( V_7 -> V_20 . V_63 ) ) ;
F_32 ( V_50 , & V_7 -> V_20 . V_60 , V_90 ,
& V_2 -> V_20 . V_60 , V_55 ,
sizeof( V_7 -> V_20 . V_60 ) ) ;
}
return 0 ;
}
static bool F_38 ( struct V_1 * V_91 ,
struct V_1 * V_92 )
{
const long * V_93 = F_5 ( & V_91 -> V_7 , V_91 ) ;
const long * V_94 = F_5 ( & V_92 -> V_7 , V_92 ) ;
return ! memcmp ( & V_91 -> V_3 , & V_92 -> V_3 , sizeof( V_91 -> V_3 ) ) &&
! memcmp ( V_93 , V_94 , F_1 ( V_91 ) ) ;
}
static int F_39 ( struct V_23 * V_24 ,
struct V_1 * V_2 )
{
V_24 -> V_37 = V_95 ;
V_24 -> V_37 . V_96 = F_1 ( V_2 ) ;
V_24 -> V_37 . V_97 += V_2 -> V_3 . V_5 ;
return F_40 ( & V_24 -> V_36 , & V_24 -> V_37 ) ;
}
static void F_41 ( struct V_23 * V_24 ,
struct V_1 * V_2 )
{
struct V_98 V_99 [ V_100 ] ;
T_2 V_101 = 0 ;
F_42 ( V_99 , V_101 , V_102 , V_71 ) ;
F_42 ( V_99 , V_101 , V_103 , V_32 ) ;
F_43 ( V_2 , V_99 , V_101 ,
V_104 , V_59 ) ;
F_43 ( V_2 , V_99 , V_101 ,
V_73 , V_74 ) ;
F_43 ( V_2 , V_99 , V_101 ,
V_79 , V_80 ) ;
F_43 ( V_2 , V_99 , V_101 ,
V_105 , V_20 ) ;
F_44 ( & V_24 -> V_35 , V_99 , V_101 ) ;
}
static int F_45 ( struct V_23 * V_24 ,
struct V_1 * V_2 )
{
int V_58 ;
if ( V_24 -> V_47 ) {
if ( ! F_38 ( & V_24 -> V_2 , V_2 ) )
return - V_106 ;
else
return 0 ;
}
V_58 = F_39 ( V_24 , V_2 ) ;
if ( V_58 )
return V_58 ;
memcpy ( & V_24 -> V_2 , V_2 , sizeof( V_24 -> V_2 ) ) ;
V_24 -> V_47 = true ;
F_41 ( V_24 , V_2 ) ;
return 0 ;
}
static int F_46 ( struct V_56 * V_56 , struct V_19 * V_20 ,
struct V_26 * V_27 , struct V_1 * V_2 ,
unsigned long V_107 , struct V_49 * * V_50 ,
struct V_49 * V_108 , bool V_109 )
{
struct V_110 V_111 ;
int V_58 ;
F_47 ( & V_111 , V_112 , 0 ) ;
V_58 = F_48 ( V_56 , V_20 , V_50 , V_108 , & V_111 , V_109 ) ;
if ( V_58 < 0 )
return V_58 ;
if ( V_50 [ V_113 ] ) {
V_27 -> V_22 . V_114 = F_49 ( V_50 [ V_113 ] ) ;
F_50 ( V_20 , & V_27 -> V_22 , V_107 ) ;
}
V_58 = F_34 ( V_56 , V_50 , & V_27 -> V_7 , & V_2 -> V_7 ) ;
if ( V_58 )
goto V_115;
F_2 ( V_2 ) ;
F_6 ( & V_27 -> V_13 , & V_27 -> V_7 , V_2 ) ;
F_51 ( V_20 , & V_27 -> V_38 , & V_111 ) ;
return 0 ;
V_115:
F_19 ( & V_111 ) ;
return V_58 ;
}
static T_3 F_52 ( struct V_19 * V_20 ,
struct V_23 * V_24 )
{
unsigned int V_9 = 0x80000000 ;
T_3 V_48 ;
do {
if ( ++ V_24 -> V_116 == 0x7FFFFFFF )
V_24 -> V_116 = 1 ;
} while ( -- V_9 > 0 && F_30 ( V_20 , V_24 -> V_116 ) );
if ( F_53 ( V_9 == 0 ) ) {
F_54 ( L_1 ) ;
V_48 = 0 ;
} else {
V_48 = V_24 -> V_116 ;
}
return V_48 ;
}
static int F_55 ( struct V_56 * V_56 , struct V_17 * V_117 ,
struct V_19 * V_20 , unsigned long V_107 ,
T_3 V_48 , struct V_49 * * V_118 ,
unsigned long * V_119 , bool V_109 )
{
struct V_23 * V_24 = F_22 ( V_20 -> V_25 ) ;
struct V_26 * V_120 = (struct V_26 * ) * V_119 ;
struct V_26 * V_121 ;
struct V_49 * V_50 [ V_122 + 1 ] ;
struct V_1 V_2 = {} ;
int V_58 ;
if ( ! V_118 [ V_123 ] )
return - V_106 ;
V_58 = F_56 ( V_50 , V_122 , V_118 [ V_123 ] , V_124 ) ;
if ( V_58 < 0 )
return V_58 ;
if ( V_120 && V_48 && V_120 -> V_48 != V_48 )
return - V_106 ;
V_121 = F_14 ( sizeof( * V_121 ) , V_39 ) ;
if ( ! V_121 )
return - V_40 ;
F_47 ( & V_121 -> V_38 , V_112 , 0 ) ;
if ( ! V_48 ) {
V_48 = F_52 ( V_20 , V_24 ) ;
if ( ! V_48 ) {
V_58 = - V_106 ;
goto V_115;
}
}
V_121 -> V_48 = V_48 ;
V_58 = F_46 ( V_56 , V_20 , V_121 , & V_2 , V_107 , V_50 , V_118 [ V_125 ] , V_109 ) ;
if ( V_58 )
goto V_115;
V_58 = F_45 ( V_24 , & V_2 ) ;
if ( V_58 )
goto V_115;
V_58 = F_57 ( & V_24 -> V_36 , & V_121 -> V_126 ,
V_24 -> V_37 ) ;
if ( V_58 )
goto V_115;
if ( V_120 )
F_58 ( & V_24 -> V_36 , & V_120 -> V_126 ,
V_24 -> V_37 ) ;
* V_119 = ( unsigned long ) V_121 ;
if ( V_120 ) {
F_59 ( & V_120 -> V_46 , & V_121 -> V_46 ) ;
F_60 ( V_20 , & V_120 -> V_22 ) ;
F_26 ( & V_120 -> V_43 , F_17 ) ;
} else {
F_61 ( & V_121 -> V_46 , & V_24 -> V_41 ) ;
}
return 0 ;
V_115:
F_20 ( V_121 ) ;
return V_58 ;
}
static int F_62 ( struct V_19 * V_20 , unsigned long V_119 )
{
struct V_23 * V_24 = F_22 ( V_20 -> V_25 ) ;
struct V_26 * V_27 = (struct V_26 * ) V_119 ;
F_58 ( & V_24 -> V_36 , & V_27 -> V_126 ,
V_24 -> V_37 ) ;
F_25 ( & V_27 -> V_46 ) ;
F_60 ( V_20 , & V_27 -> V_22 ) ;
F_26 ( & V_27 -> V_43 , F_17 ) ;
return 0 ;
}
static void F_63 ( struct V_19 * V_20 , struct V_127 * V_119 )
{
struct V_23 * V_24 = F_22 ( V_20 -> V_25 ) ;
struct V_26 * V_27 ;
F_64 (f, &head->filters, list) {
if ( V_119 -> V_128 < V_119 -> V_129 )
goto V_129;
if ( V_119 -> V_130 ( V_20 , ( unsigned long ) V_27 , V_119 ) < 0 ) {
V_119 -> V_131 = 1 ;
break;
}
V_129:
V_119 -> V_128 ++ ;
}
}
static int F_65 ( struct V_17 * V_18 ,
void * V_51 , int V_52 ,
void * V_2 , int V_53 , int V_54 )
{
int V_58 ;
if ( ! F_66 ( V_2 , 0 , V_54 ) )
return 0 ;
V_58 = F_67 ( V_18 , V_52 , V_54 , V_51 ) ;
if ( V_58 )
return V_58 ;
if ( V_53 != V_55 ) {
V_58 = F_67 ( V_18 , V_53 , V_54 , V_2 ) ;
if ( V_58 )
return V_58 ;
}
return 0 ;
}
static int F_68 ( struct V_56 * V_56 , struct V_19 * V_20 , unsigned long V_132 ,
struct V_17 * V_18 , struct V_133 * V_134 )
{
struct V_23 * V_24 = F_22 ( V_20 -> V_25 ) ;
struct V_26 * V_27 = (struct V_26 * ) V_132 ;
struct V_49 * V_135 ;
struct V_12 * V_7 , * V_2 ;
if ( ! V_27 )
return V_18 -> V_54 ;
V_134 -> V_136 = V_27 -> V_48 ;
V_135 = F_69 ( V_18 , V_123 ) ;
if ( ! V_135 )
goto V_137;
if ( V_27 -> V_22 . V_114 &&
F_70 ( V_18 , V_113 , V_27 -> V_22 . V_114 ) )
goto V_137;
V_7 = & V_27 -> V_7 ;
V_2 = & V_24 -> V_2 . V_7 ;
if ( V_2 -> V_30 ) {
struct V_138 * V_139 ;
V_139 = F_71 ( V_56 , V_7 -> V_30 ) ;
if ( V_139 && F_72 ( V_18 , V_57 , V_139 -> V_140 ) )
goto V_137;
}
if ( F_65 ( V_18 , V_7 -> V_59 . V_60 , V_61 ,
V_2 -> V_59 . V_60 , V_62 ,
sizeof( V_7 -> V_59 . V_60 ) ) ||
F_65 ( V_18 , V_7 -> V_59 . V_63 , V_64 ,
V_2 -> V_59 . V_63 , V_65 ,
sizeof( V_7 -> V_59 . V_63 ) ) ||
F_65 ( V_18 , & V_7 -> V_32 . V_33 , V_66 ,
& V_2 -> V_32 . V_33 , V_55 ,
sizeof( V_7 -> V_32 . V_33 ) ) )
goto V_137;
if ( ( V_7 -> V_32 . V_33 == F_37 ( V_67 ) ||
V_7 -> V_32 . V_33 == F_37 ( V_68 ) ) &&
F_65 ( V_18 , & V_7 -> V_32 . V_69 , V_70 ,
& V_2 -> V_32 . V_69 , V_55 ,
sizeof( V_7 -> V_32 . V_69 ) ) )
goto V_137;
if ( V_7 -> V_71 . V_72 == V_73 &&
( F_65 ( V_18 , & V_7 -> V_74 . V_63 , V_75 ,
& V_2 -> V_74 . V_63 , V_76 ,
sizeof( V_7 -> V_74 . V_63 ) ) ||
F_65 ( V_18 , & V_7 -> V_74 . V_60 , V_77 ,
& V_2 -> V_74 . V_60 , V_78 ,
sizeof( V_7 -> V_74 . V_60 ) ) ) )
goto V_137;
else if ( V_7 -> V_71 . V_72 == V_79 &&
( F_65 ( V_18 , & V_7 -> V_80 . V_63 , V_81 ,
& V_2 -> V_80 . V_63 , V_82 ,
sizeof( V_7 -> V_80 . V_63 ) ) ||
F_65 ( V_18 , & V_7 -> V_80 . V_60 , V_83 ,
& V_2 -> V_80 . V_60 , V_84 ,
sizeof( V_7 -> V_80 . V_60 ) ) ) )
goto V_137;
if ( V_7 -> V_32 . V_69 == V_85 &&
( F_65 ( V_18 , & V_7 -> V_20 . V_63 , V_86 ,
& V_2 -> V_20 . V_63 , V_55 ,
sizeof( V_7 -> V_20 . V_63 ) ) ||
F_65 ( V_18 , & V_7 -> V_20 . V_60 , V_87 ,
& V_2 -> V_20 . V_60 , V_55 ,
sizeof( V_7 -> V_20 . V_60 ) ) ) )
goto V_137;
else if ( V_7 -> V_32 . V_69 == V_88 &&
( F_65 ( V_18 , & V_7 -> V_20 . V_63 , V_89 ,
& V_2 -> V_20 . V_63 , V_55 ,
sizeof( V_7 -> V_20 . V_63 ) ) ||
F_65 ( V_18 , & V_7 -> V_20 . V_60 , V_90 ,
& V_2 -> V_20 . V_60 , V_55 ,
sizeof( V_7 -> V_20 . V_60 ) ) ) )
goto V_137;
if ( F_73 ( V_18 , & V_27 -> V_38 ) )
goto V_137;
F_74 ( V_18 , V_135 ) ;
if ( F_75 ( V_18 , & V_27 -> V_38 ) < 0 )
goto V_137;
return V_18 -> V_54 ;
V_137:
F_76 ( V_18 , V_135 ) ;
return - 1 ;
}
static int T_4 F_77 ( void )
{
return F_78 ( & V_141 ) ;
}
static void T_5 F_79 ( void )
{
F_80 ( & V_141 ) ;
}
