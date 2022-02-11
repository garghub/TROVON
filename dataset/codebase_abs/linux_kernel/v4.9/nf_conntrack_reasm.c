static int F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 ;
struct V_4 * V_5 ;
V_3 = V_6 ;
if ( ! F_2 ( V_1 , & V_7 ) ) {
V_3 = F_3 ( V_3 , sizeof( V_6 ) ,
V_8 ) ;
if ( V_3 == NULL )
goto V_9;
V_3 [ 0 ] . V_10 = & V_1 -> V_11 . V_12 . V_13 ;
V_3 [ 1 ] . V_10 = & V_1 -> V_11 . V_12 . V_14 ;
V_3 [ 1 ] . V_15 = & V_1 -> V_11 . V_12 . V_16 ;
V_3 [ 2 ] . V_10 = & V_1 -> V_11 . V_12 . V_16 ;
V_3 [ 2 ] . V_17 = & V_1 -> V_11 . V_12 . V_14 ;
V_3 [ 2 ] . V_15 = & V_7 . V_11 . V_12 . V_16 ;
}
V_5 = F_4 ( V_1 , L_1 , V_3 ) ;
if ( V_5 == NULL )
goto V_18;
V_1 -> V_11 . V_19 . V_20 = V_5 ;
return 0 ;
V_18:
if ( ! F_2 ( V_1 , & V_7 ) )
F_5 ( V_3 ) ;
V_9:
return - V_21 ;
}
static void T_1 F_6 ( struct V_1 * V_1 )
{
struct V_2 * V_3 ;
V_3 = V_1 -> V_11 . V_19 . V_20 -> V_22 ;
F_7 ( V_1 -> V_11 . V_19 . V_20 ) ;
if ( ! F_2 ( V_1 , & V_7 ) )
F_5 ( V_3 ) ;
}
static int F_1 ( struct V_1 * V_1 )
{
return 0 ;
}
static void T_1 F_6 ( struct V_1 * V_1 )
{
}
static inline T_2 F_8 ( const struct V_23 * V_24 )
{
return 1 << ( F_9 ( V_24 ) & V_25 ) ;
}
static unsigned int F_10 ( T_3 V_26 , const struct V_27 * V_28 ,
const struct V_27 * V_29 )
{
F_11 ( & V_30 . V_31 , sizeof( V_30 . V_31 ) ) ;
return F_12 ( F_13 ( V_28 ) , F_13 ( V_29 ) ,
( V_32 V_33 ) V_26 , V_30 . V_31 ) ;
}
static unsigned int F_14 ( const struct V_34 * V_35 )
{
const struct V_36 * V_37 ;
V_37 = F_15 ( V_35 , struct V_36 , V_35 ) ;
return F_10 ( V_37 -> V_26 , & V_37 -> V_28 , & V_37 -> V_29 ) ;
}
static void F_16 ( unsigned long V_10 )
{
struct V_36 * V_38 ;
struct V_1 * V_1 ;
V_38 = F_15 ( (struct V_34 * ) V_10 , struct V_36 , V_35 ) ;
V_1 = F_15 ( V_38 -> V_35 . V_1 , struct V_1 , V_11 . V_12 ) ;
F_17 ( V_1 , V_38 , & V_30 ) ;
}
static inline struct V_36 * F_18 ( struct V_1 * V_1 , T_3 V_26 ,
V_33 V_39 , struct V_27 * V_40 ,
struct V_27 * V_41 , int V_42 , T_2 V_43 )
{
struct V_34 * V_35 ;
struct V_44 V_45 ;
unsigned int V_46 ;
V_45 . V_26 = V_26 ;
V_45 . V_39 = V_39 ;
V_45 . V_40 = V_40 ;
V_45 . V_41 = V_41 ;
V_45 . V_42 = V_42 ;
V_45 . V_43 = V_43 ;
F_19 () ;
V_46 = F_10 ( V_26 , V_40 , V_41 ) ;
V_35 = F_20 ( & V_1 -> V_11 . V_12 , & V_30 , & V_45 , V_46 ) ;
F_21 () ;
if ( F_22 ( V_35 ) ) {
F_23 ( V_35 , F_24 () ) ;
return NULL ;
}
return F_15 ( V_35 , struct V_36 , V_35 ) ;
}
static int F_25 ( struct V_36 * V_38 , struct V_47 * V_48 ,
const struct V_49 * V_50 , int V_51 )
{
struct V_47 * V_52 , * V_53 ;
unsigned int V_54 ;
int V_55 , V_56 ;
T_2 V_43 ;
if ( V_38 -> V_35 . V_57 & V_58 ) {
F_26 ( L_2 ) ;
goto V_59;
}
V_54 = F_27 ( F_28 ( V_48 ) -> V_54 ) ;
V_55 = F_27 ( V_50 -> V_60 ) & ~ 0x7 ;
V_56 = V_55 + ( V_54 -
( ( T_2 * ) ( V_50 + 1 ) - ( T_2 * ) ( F_28 ( V_48 ) + 1 ) ) ) ;
if ( ( unsigned int ) V_56 > V_61 ) {
F_26 ( L_3 ) ;
return - 1 ;
}
V_43 = F_8 ( F_28 ( V_48 ) ) ;
if ( V_48 -> V_62 == V_63 ) {
const unsigned char * V_64 = F_29 ( V_48 ) ;
V_48 -> V_65 = F_30 ( V_48 -> V_65 ,
F_31 ( V_64 , ( T_2 * ) ( V_50 + 1 ) - V_64 ,
0 ) ) ;
}
if ( ! ( V_50 -> V_60 & F_32 ( V_66 ) ) ) {
if ( V_56 < V_38 -> V_35 . V_67 ||
( ( V_38 -> V_35 . V_57 & V_68 ) && V_56 != V_38 -> V_35 . V_67 ) ) {
F_26 ( L_4 ) ;
goto V_59;
}
V_38 -> V_35 . V_57 |= V_68 ;
V_38 -> V_35 . V_67 = V_56 ;
} else {
if ( V_56 & 0x7 ) {
F_26 ( L_5 ) ;
return - 1 ;
}
if ( V_56 > V_38 -> V_35 . V_67 ) {
if ( V_38 -> V_35 . V_57 & V_68 ) {
F_26 ( L_6 ) ;
goto V_59;
}
V_38 -> V_35 . V_67 = V_56 ;
}
}
if ( V_56 == V_55 )
goto V_59;
if ( ! F_33 ( V_48 , ( T_2 * ) ( V_50 + 1 ) - V_48 -> V_10 ) ) {
F_26 ( L_7 ) ;
goto V_59;
}
if ( F_34 ( V_48 , V_56 - V_55 ) ) {
F_26 ( L_8 ) ;
goto V_59;
}
V_52 = V_38 -> V_35 . V_69 ;
if ( ! V_52 || F_35 ( V_52 ) -> V_55 < V_55 ) {
V_53 = NULL ;
goto V_70;
}
V_52 = NULL ;
for ( V_53 = V_38 -> V_35 . V_71 ; V_53 != NULL ; V_53 = V_53 -> V_53 ) {
if ( F_35 ( V_53 ) -> V_55 >= V_55 )
break;
V_52 = V_53 ;
}
V_70:
if ( V_52 &&
( F_35 ( V_52 ) -> V_55 + V_52 -> V_67 ) > V_55 )
goto V_72;
if ( V_53 && F_35 ( V_53 ) -> V_55 < V_56 )
goto V_72;
F_35 ( V_48 ) -> V_55 = V_55 ;
V_48 -> V_53 = V_53 ;
if ( ! V_53 )
V_38 -> V_35 . V_69 = V_48 ;
if ( V_52 )
V_52 -> V_53 = V_48 ;
else
V_38 -> V_35 . V_71 = V_48 ;
if ( V_48 -> V_73 ) {
V_38 -> V_42 = V_48 -> V_73 -> V_74 ;
V_48 -> V_73 = NULL ;
}
V_38 -> V_35 . V_75 = V_48 -> V_76 ;
V_38 -> V_35 . V_77 += V_48 -> V_67 ;
V_38 -> V_43 |= V_43 ;
if ( V_54 > V_38 -> V_35 . V_78 )
V_38 -> V_35 . V_78 = V_54 ;
F_36 ( V_38 -> V_35 . V_1 , V_48 -> V_79 ) ;
if ( V_55 == 0 ) {
V_38 -> V_80 = V_51 ;
V_38 -> V_35 . V_57 |= V_81 ;
}
return 0 ;
V_72:
F_37 ( & V_38 -> V_35 , & V_30 ) ;
V_59:
return - 1 ;
}
static bool
F_38 ( struct V_36 * V_38 , struct V_47 * V_52 , struct V_82 * V_73 )
{
struct V_47 * V_83 , * V_84 = V_38 -> V_35 . V_71 ;
int V_54 ;
T_2 V_43 ;
F_37 ( & V_38 -> V_35 , & V_30 ) ;
F_39 ( V_84 == NULL ) ;
F_39 ( F_35 ( V_84 ) -> V_55 != 0 ) ;
V_43 = V_85 [ V_38 -> V_43 ] ;
if ( F_40 ( V_43 == 0xff ) )
return false ;
V_54 = ( ( V_84 -> V_10 - F_29 ( V_84 ) ) -
sizeof( struct V_23 ) + V_38 -> V_35 . V_67 -
sizeof( struct V_49 ) ) ;
if ( V_54 > V_61 ) {
F_41 ( L_9 ,
V_54 ) ;
return false ;
}
if ( F_42 ( V_84 , V_86 ) )
return false ;
if ( F_43 ( V_84 ) ) {
struct V_47 * V_87 ;
int V_88 , V_89 = 0 ;
V_87 = F_44 ( 0 , V_86 ) ;
if ( V_87 == NULL )
return false ;
V_87 -> V_53 = V_84 -> V_53 ;
V_84 -> V_53 = V_87 ;
F_45 ( V_87 ) -> V_90 = F_45 ( V_84 ) -> V_90 ;
F_46 ( V_84 ) ;
for ( V_88 = 0 ; V_88 < F_45 ( V_84 ) -> V_91 ; V_88 ++ )
V_89 += F_47 ( & F_45 ( V_84 ) -> V_12 [ V_88 ] ) ;
V_87 -> V_67 = V_87 -> V_92 = V_84 -> V_92 - V_89 ;
V_84 -> V_92 -= V_87 -> V_67 ;
V_84 -> V_67 -= V_87 -> V_67 ;
V_87 -> V_65 = 0 ;
V_87 -> V_62 = V_84 -> V_62 ;
F_36 ( V_38 -> V_35 . V_1 , V_87 -> V_79 ) ;
}
if ( V_84 != V_52 ) {
struct V_47 * V_93 ;
V_83 = F_48 ( V_52 , V_86 ) ;
if ( ! V_83 )
return false ;
V_83 -> V_53 = V_52 -> V_53 ;
V_93 = V_84 ;
while ( V_93 ) {
if ( V_93 -> V_53 == V_52 ) {
V_93 -> V_53 = V_83 ;
break;
}
V_93 = V_93 -> V_53 ;
}
F_49 ( V_52 , V_84 ) ;
V_52 -> V_53 = V_84 -> V_53 ;
F_50 ( V_84 ) ;
V_84 = V_52 ;
}
F_29 ( V_84 ) [ V_38 -> V_80 ] = F_51 ( V_84 ) [ 0 ] ;
memmove ( V_84 -> V_84 + sizeof( struct V_49 ) , V_84 -> V_84 ,
( V_84 -> V_10 - V_84 -> V_84 ) - sizeof( struct V_49 ) ) ;
V_84 -> V_94 += sizeof( struct V_49 ) ;
V_84 -> V_95 += sizeof( struct V_49 ) ;
F_45 ( V_84 ) -> V_90 = V_84 -> V_53 ;
F_52 ( V_84 ) ;
F_53 ( V_84 , V_84 -> V_10 - F_29 ( V_84 ) ) ;
for ( V_83 = V_84 -> V_53 ; V_83 ; V_83 = V_83 -> V_53 ) {
V_84 -> V_92 += V_83 -> V_67 ;
V_84 -> V_67 += V_83 -> V_67 ;
if ( V_84 -> V_62 != V_83 -> V_62 )
V_84 -> V_62 = V_96 ;
else if ( V_84 -> V_62 == V_63 )
V_84 -> V_65 = F_54 ( V_84 -> V_65 , V_83 -> V_65 ) ;
V_84 -> V_79 += V_83 -> V_79 ;
}
F_55 ( V_38 -> V_35 . V_1 , V_84 -> V_79 ) ;
V_84 -> V_97 = 1 ;
V_84 -> V_53 = NULL ;
V_84 -> V_73 = V_73 ;
V_84 -> V_76 = V_38 -> V_35 . V_75 ;
F_28 ( V_84 ) -> V_54 = F_32 ( V_54 ) ;
F_56 ( F_28 ( V_84 ) , 0xff , V_43 ) ;
F_57 ( V_84 ) -> V_98 = sizeof( struct V_23 ) + V_38 -> V_35 . V_78 ;
if ( V_84 -> V_62 == V_63 )
V_84 -> V_65 = F_31 ( F_29 ( V_84 ) ,
F_58 ( V_84 ) ,
V_84 -> V_65 ) ;
V_38 -> V_35 . V_71 = NULL ;
V_38 -> V_35 . V_69 = NULL ;
return true ;
}
static int
F_59 ( struct V_47 * V_48 , T_2 * V_99 , int * V_100 , int * V_101 )
{
T_2 V_102 = F_28 ( V_48 ) -> V_102 ;
const int V_103 = F_60 ( V_48 ) ;
T_2 V_104 = V_103 + F_61 ( struct V_23 , V_102 ) ;
int V_105 = V_103 + sizeof( struct V_23 ) ;
int V_67 = V_48 -> V_67 - V_105 ;
T_2 V_106 = V_107 ;
while ( V_102 != V_108 ) {
struct V_109 V_5 ;
int V_110 ;
if ( ! F_62 ( V_102 ) ) {
return - 1 ;
}
if ( V_102 == V_111 ) {
F_26 ( L_10 ) ;
return - 1 ;
}
if ( V_67 < ( int ) sizeof( struct V_109 ) ) {
F_26 ( L_11 ) ;
return - 1 ;
}
if ( F_63 ( V_48 , V_105 , & V_5 , sizeof( V_5 ) ) )
F_64 () ;
if ( V_102 == V_112 )
V_110 = ( V_5 . V_110 + 2 ) << 2 ;
else
V_110 = F_65 ( & V_5 ) ;
V_106 = V_102 ;
V_104 = V_105 ;
V_102 = V_5 . V_102 ;
V_67 -= V_110 ;
V_105 += V_110 ;
}
if ( V_67 < 0 )
return - 1 ;
* V_99 = V_106 ;
* V_100 = V_104 ;
* V_101 = V_105 ;
return 0 ;
}
int F_66 ( struct V_1 * V_1 , struct V_47 * V_48 , V_33 V_39 )
{
struct V_82 * V_73 = V_48 -> V_73 ;
int V_101 , V_51 , V_113 ;
struct V_49 * V_50 ;
struct V_36 * V_38 ;
struct V_23 * V_5 ;
T_2 V_106 ;
if ( F_28 ( V_48 ) -> V_54 == 0 ) {
F_26 ( L_12 ) ;
return 0 ;
}
if ( F_59 ( V_48 , & V_106 , & V_51 , & V_101 ) < 0 )
return 0 ;
if ( ! F_67 ( V_48 , V_101 + sizeof( * V_50 ) ) )
return - V_21 ;
F_68 ( V_48 , V_101 ) ;
V_5 = F_28 ( V_48 ) ;
V_50 = (struct V_49 * ) F_51 ( V_48 ) ;
V_38 = F_18 ( V_1 , V_50 -> V_114 , V_39 , & V_5 -> V_28 , & V_5 -> V_29 ,
V_48 -> V_73 ? V_48 -> V_73 -> V_74 : 0 , F_8 ( V_5 ) ) ;
if ( V_38 == NULL ) {
F_26 ( L_13 ) ;
return - V_21 ;
}
F_69 ( & V_38 -> V_35 . V_115 ) ;
if ( F_25 ( V_38 , V_48 , V_50 , V_51 ) < 0 ) {
V_113 = - V_116 ;
goto V_117;
}
V_113 = - V_118 ;
if ( V_38 -> V_35 . V_57 == ( V_81 | V_68 ) &&
V_38 -> V_35 . V_77 == V_38 -> V_35 . V_67 &&
F_38 ( V_38 , V_48 , V_73 ) )
V_113 = 0 ;
V_117:
F_70 ( & V_38 -> V_35 . V_115 ) ;
F_71 ( & V_38 -> V_35 , & V_30 ) ;
return V_113 ;
}
static int F_72 ( struct V_1 * V_1 )
{
int V_119 ;
V_1 -> V_11 . V_12 . V_16 = V_120 ;
V_1 -> V_11 . V_12 . V_14 = V_121 ;
V_1 -> V_11 . V_12 . V_13 = V_122 ;
V_119 = F_73 ( & V_1 -> V_11 . V_12 ) ;
if ( V_119 )
return V_119 ;
V_119 = F_1 ( V_1 ) ;
if ( V_119 )
F_74 ( & V_1 -> V_11 . V_12 ) ;
return V_119 ;
}
static void F_75 ( struct V_1 * V_1 )
{
F_6 ( V_1 ) ;
F_76 ( & V_1 -> V_11 . V_12 , & V_30 ) ;
}
int F_77 ( void )
{
int V_113 = 0 ;
V_30 . V_123 = F_14 ;
V_30 . V_124 = V_125 ;
V_30 . V_126 = NULL ;
V_30 . V_127 = sizeof( struct V_36 ) ;
V_30 . V_128 = V_129 ;
V_30 . V_130 = F_16 ;
V_30 . V_131 = V_132 ;
V_113 = F_78 ( & V_30 ) ;
if ( V_113 )
goto V_133;
V_113 = F_79 ( & V_134 ) ;
if ( V_113 )
F_80 ( & V_30 ) ;
V_133:
return V_113 ;
}
void F_81 ( void )
{
F_82 ( & V_134 ) ;
F_80 ( & V_30 ) ;
}
