static void F_1 ( struct V_1 * V_2 )
{
if ( F_2 ( & V_2 -> V_3 ) ) {
F_3 () ;
if ( F_4 ( & V_2 -> V_4 ) )
F_5 ( & V_2 -> V_4 ) ;
}
}
static void F_6 ( struct V_1 * V_2 )
{
if ( F_2 ( & V_2 -> V_5 ) ) {
F_3 () ;
if ( F_4 ( & V_2 -> V_4 ) )
F_5 ( & V_2 -> V_4 ) ;
}
}
static void F_7 ( struct V_6 * V_6 , int V_7 )
{
struct V_1 * V_2 = V_6 -> V_8 ;
struct V_9 * V_10 ;
int V_11 ;
if ( V_7 ) {
unsigned long V_12 ;
F_8 ( L_1 , V_7 ) ;
F_9 ( & V_2 -> V_13 , V_12 ) ;
V_2 -> V_14 = false ;
F_10 ( & V_2 -> V_13 , V_12 ) ;
}
F_11 (bvec, bio, i)
F_12 ( V_10 -> V_15 ) ;
F_6 ( V_2 ) ;
F_13 ( V_6 ) ;
}
static void F_14 ( struct V_1 * V_2 ,
struct V_16 * V_17 )
{
int V_11 ;
for ( V_11 = 0 ; V_11 < V_17 -> V_18 ; V_11 ++ ) {
if ( V_17 -> V_19 [ V_11 ] . V_15 )
F_12 ( V_17 -> V_19 [ V_11 ] . V_15 ) ;
}
F_15 ( V_17 -> V_20 ) ;
F_15 ( V_17 ) ;
F_1 ( V_2 ) ;
}
static int F_16 ( struct V_1 * V_2 , void * V_21 ,
T_1 V_22 , void * V_20 , T_1 V_23 ,
T_2 V_24 )
{
struct V_6 * V_6 ;
struct V_25 * V_25 ;
void * V_26 ;
T_1 V_27 ;
V_6 = F_17 ( V_28 , 1 ) ;
if ( ! V_6 ) {
F_8 ( L_2 ) ;
goto error;
}
V_6 -> V_29 . V_30 = 0 ;
V_6 -> V_29 . V_31 = V_24 ;
V_6 -> V_32 = V_2 -> V_33 -> V_34 ;
V_6 -> V_35 = F_7 ;
V_6 -> V_8 = V_2 ;
F_18 ( V_36 , & V_6 -> V_37 ) ;
V_25 = F_19 ( V_28 ) ;
if ( ! V_25 ) {
F_8 ( L_3 ) ;
F_13 ( V_6 ) ;
goto error;
}
V_26 = F_20 ( V_25 ) ;
memcpy ( V_26 , V_21 , V_22 ) ;
if ( V_23 )
memcpy ( V_26 + V_22 , V_20 , V_23 ) ;
memset ( V_26 + V_22 + V_23 , 0 ,
V_2 -> V_38 - V_22 - V_23 ) ;
F_21 ( V_26 ) ;
V_27 = F_22 ( V_6 , V_25 , V_2 -> V_38 , 0 ) ;
if ( V_27 != V_2 -> V_38 ) {
F_8 ( L_4 ) ;
goto V_39;
}
F_23 ( V_40 , V_6 ) ;
return 0 ;
V_39:
F_13 ( V_6 ) ;
F_12 ( V_25 ) ;
error:
F_6 ( V_2 ) ;
return - 1 ;
}
static int F_24 ( struct V_1 * V_2 ,
struct V_16 * V_17 , T_2 V_24 )
{
struct V_6 * V_6 ;
struct V_41 V_21 ;
T_1 V_27 ;
int V_11 ;
V_21 . V_24 = F_25 ( V_17 -> V_24 ) ;
V_21 . V_42 = F_25 ( V_17 -> V_42 ) ;
V_21 . V_12 = F_25 ( V_17 -> V_12 ) ;
V_21 . V_43 = F_25 ( V_17 -> V_23 ) ;
if ( F_16 ( V_2 , & V_21 , sizeof( V_21 ) , V_17 -> V_20 ,
V_17 -> V_23 , V_24 ) ) {
F_14 ( V_2 , V_17 ) ;
return - 1 ;
}
if ( ! V_17 -> V_18 )
goto V_44;
V_24 ++ ;
V_6 = F_17 ( V_28 , V_17 -> V_18 ) ;
if ( ! V_6 ) {
F_8 ( L_2 ) ;
goto error;
}
F_26 ( & V_2 -> V_5 ) ;
V_6 -> V_29 . V_30 = 0 ;
V_6 -> V_29 . V_31 = V_24 ;
V_6 -> V_32 = V_2 -> V_33 -> V_34 ;
V_6 -> V_35 = F_7 ;
V_6 -> V_8 = V_2 ;
F_18 ( V_36 , & V_6 -> V_37 ) ;
for ( V_11 = 0 ; V_11 < V_17 -> V_18 ; V_11 ++ ) {
V_27 = F_22 ( V_6 , V_17 -> V_19 [ V_11 ] . V_15 ,
V_17 -> V_19 [ V_11 ] . V_45 , 0 ) ;
if ( V_27 != V_17 -> V_19 [ V_11 ] . V_45 ) {
F_26 ( & V_2 -> V_5 ) ;
F_23 ( V_40 , V_6 ) ;
V_6 = F_17 ( V_28 , V_17 -> V_18 - V_11 ) ;
if ( ! V_6 ) {
F_8 ( L_2 ) ;
goto error;
}
V_6 -> V_29 . V_30 = 0 ;
V_6 -> V_29 . V_31 = V_24 ;
V_6 -> V_32 = V_2 -> V_33 -> V_34 ;
V_6 -> V_35 = F_7 ;
V_6 -> V_8 = V_2 ;
F_18 ( V_36 , & V_6 -> V_37 ) ;
V_27 = F_22 ( V_6 , V_17 -> V_19 [ V_11 ] . V_15 ,
V_17 -> V_19 [ V_11 ] . V_45 , 0 ) ;
if ( V_27 != V_17 -> V_19 [ V_11 ] . V_45 ) {
F_8 ( L_5 ) ;
F_13 ( V_6 ) ;
goto error;
}
}
V_24 += V_17 -> V_19 [ V_11 ] . V_45 >> V_46 ;
}
F_23 ( V_40 , V_6 ) ;
V_44:
F_15 ( V_17 -> V_20 ) ;
F_15 ( V_17 ) ;
F_1 ( V_2 ) ;
return 0 ;
error:
F_14 ( V_2 , V_17 ) ;
F_6 ( V_2 ) ;
return - 1 ;
}
static int F_27 ( struct V_1 * V_2 )
{
struct V_47 V_48 ;
V_48 . V_49 = F_25 ( V_50 ) ;
V_48 . V_51 = F_25 ( V_52 ) ;
V_48 . V_53 = F_25 ( V_2 -> V_54 ) ;
V_48 . V_38 = F_28 ( V_2 -> V_38 ) ;
if ( F_16 ( V_2 , & V_48 , sizeof( V_48 ) , NULL , 0 , 0 ) ) {
F_8 ( L_6 ) ;
return - 1 ;
}
return 0 ;
}
static inline T_2 F_29 ( struct V_1 * V_2 )
{
return F_30 ( V_2 -> V_33 -> V_34 -> V_55 ) >> V_46 ;
}
static int F_31 ( void * V_56 )
{
struct V_1 * V_2 = (struct V_1 * ) V_56 ;
T_2 V_24 = 0 ;
while ( ! F_32 () ) {
bool V_48 = false ;
bool V_14 ;
struct V_16 * V_17 = NULL ;
int V_27 ;
F_33 ( & V_2 -> V_13 ) ;
if ( ! F_34 ( & V_2 -> V_57 ) ) {
V_17 = F_35 ( & V_2 -> V_57 ,
struct V_16 , V_58 ) ;
F_36 ( & V_17 -> V_58 ) ;
if ( ! V_2 -> V_14 )
goto V_59;
V_24 = V_2 -> V_60 ;
if ( V_17 -> V_12 & V_61 )
V_2 -> V_60 ++ ;
else
V_2 -> V_60 += V_17 -> V_42 + 1 ;
if ( ! V_2 -> V_62 )
V_2 -> V_62 = F_29 ( V_2 ) ;
if ( V_2 -> V_62 &&
V_2 -> V_60 >= V_2 -> V_62 ) {
F_8 ( L_7 ) ;
V_2 -> V_14 = false ;
goto V_59;
}
V_2 -> V_54 ++ ;
F_26 ( & V_2 -> V_5 ) ;
V_48 = ( V_17 -> V_12 & ( V_63 | V_64 ) ) ;
if ( V_48 )
F_26 ( & V_2 -> V_5 ) ;
}
V_59:
V_14 = V_2 -> V_14 ;
F_37 ( & V_2 -> V_13 ) ;
if ( V_17 ) {
if ( V_14 ) {
V_27 = F_24 ( V_2 , V_17 , V_24 ) ;
if ( ! V_27 && V_48 )
V_27 = F_27 ( V_2 ) ;
if ( V_27 ) {
F_33 ( & V_2 -> V_13 ) ;
V_2 -> V_14 = false ;
F_37 ( & V_2 -> V_13 ) ;
}
} else
F_14 ( V_2 , V_17 ) ;
continue;
}
if ( ! F_38 () ) {
F_39 ( V_65 ) ;
if ( ! F_32 () &&
! F_40 ( & V_2 -> V_3 ) )
F_41 () ;
F_42 ( V_66 ) ;
}
}
return 0 ;
}
static int F_43 ( struct V_67 * V_68 , unsigned int V_69 , char * * V_70 )
{
struct V_1 * V_2 ;
struct V_71 V_72 ;
const char * V_73 , * V_74 ;
V_72 . V_69 = V_69 ;
V_72 . V_70 = V_70 ;
if ( V_69 < 2 ) {
V_68 -> error = L_8 ;
return - V_75 ;
}
V_2 = F_44 ( sizeof( struct V_1 ) , V_28 ) ;
if ( ! V_2 ) {
V_68 -> error = L_9 ;
return - V_76 ;
}
F_45 ( & V_2 -> V_13 ) ;
F_46 ( & V_2 -> V_77 ) ;
F_46 ( & V_2 -> V_57 ) ;
F_47 ( & V_2 -> V_4 ) ;
V_2 -> V_38 = 1 << V_46 ;
F_48 ( & V_2 -> V_5 , 0 ) ;
F_48 ( & V_2 -> V_3 , 0 ) ;
V_73 = F_49 ( & V_72 ) ;
if ( F_50 ( V_68 , V_73 , F_51 ( V_68 -> V_78 ) , & V_2 -> V_79 ) ) {
V_68 -> error = L_10 ;
goto V_80;
}
V_74 = F_49 ( & V_72 ) ;
if ( F_50 ( V_68 , V_74 , F_51 ( V_68 -> V_78 ) , & V_2 -> V_33 ) ) {
V_68 -> error = L_11 ;
F_52 ( V_68 , V_2 -> V_79 ) ;
goto V_80;
}
V_2 -> V_81 = F_53 ( F_31 , V_2 , L_12 ) ;
if ( ! V_2 -> V_81 ) {
V_68 -> error = L_13 ;
F_52 ( V_68 , V_2 -> V_79 ) ;
F_52 ( V_68 , V_2 -> V_33 ) ;
goto V_80;
}
V_2 -> V_60 = 1 ;
V_2 -> V_14 = true ;
V_2 -> V_62 = F_29 ( V_2 ) ;
V_2 -> V_82 = true ;
V_68 -> V_83 = 1 ;
V_68 -> V_84 = true ;
V_68 -> V_85 = 1 ;
V_68 -> V_86 = true ;
V_68 -> V_87 = sizeof( struct V_88 ) ;
V_68 -> V_89 = V_2 ;
return 0 ;
V_80:
F_15 ( V_2 ) ;
return - V_75 ;
}
static int F_54 ( struct V_1 * V_2 , char * V_20 )
{
struct V_16 * V_17 ;
T_1 V_90 = V_2 -> V_38 - sizeof( struct V_41 ) ;
V_17 = F_44 ( sizeof( struct V_16 ) , V_28 ) ;
if ( ! V_17 ) {
F_8 ( L_14 ) ;
return - V_76 ;
}
V_17 -> V_20 = F_55 ( V_20 , V_90 , V_28 ) ;
if ( ! V_17 -> V_20 ) {
F_8 ( L_15 ) ;
F_15 ( V_17 ) ;
return - V_76 ;
}
F_26 ( & V_2 -> V_3 ) ;
V_17 -> V_23 = strlen ( V_17 -> V_20 ) ;
V_17 -> V_12 |= V_64 ;
F_33 ( & V_2 -> V_13 ) ;
F_56 ( & V_17 -> V_58 , & V_2 -> V_57 ) ;
F_37 ( & V_2 -> V_13 ) ;
F_57 ( V_2 -> V_81 ) ;
return 0 ;
}
static void F_58 ( struct V_67 * V_68 )
{
struct V_1 * V_2 = V_68 -> V_89 ;
F_33 ( & V_2 -> V_13 ) ;
F_59 ( & V_2 -> V_77 , & V_2 -> V_57 ) ;
F_37 ( & V_2 -> V_13 ) ;
F_54 ( V_2 , L_16 ) ;
F_57 ( V_2 -> V_81 ) ;
F_60 ( V_2 -> V_4 , ! F_40 ( & V_2 -> V_5 ) &&
! F_40 ( & V_2 -> V_3 ) ) ;
F_61 ( V_2 -> V_81 ) ;
F_62 ( ! F_34 ( & V_2 -> V_57 ) ) ;
F_62 ( ! F_34 ( & V_2 -> V_77 ) ) ;
F_52 ( V_68 , V_2 -> V_79 ) ;
F_52 ( V_68 , V_2 -> V_33 ) ;
F_15 ( V_2 ) ;
}
static void F_63 ( struct V_67 * V_68 , struct V_6 * V_6 )
{
struct V_1 * V_2 = V_68 -> V_89 ;
V_6 -> V_32 = V_2 -> V_79 -> V_34 ;
}
static int F_64 ( struct V_67 * V_68 , struct V_6 * V_6 )
{
struct V_1 * V_2 = V_68 -> V_89 ;
struct V_88 * V_91 = F_65 ( V_6 , sizeof( struct V_88 ) ) ;
struct V_16 * V_17 ;
struct V_92 V_93 ;
struct V_9 V_94 ;
T_1 V_95 ;
int V_11 = 0 ;
bool V_96 = ( V_6 -> V_97 & V_98 ) ;
bool V_99 = ( V_6 -> V_97 & V_100 ) ;
bool V_101 = ( V_6 -> V_97 & V_102 ) ;
V_91 -> V_17 = NULL ;
if ( ! V_2 -> V_14 )
goto V_103;
if ( F_66 ( V_6 ) == V_104 )
goto V_103;
if ( ! F_67 ( V_6 ) && ! V_96 )
goto V_103;
if ( V_101 )
V_95 = sizeof( struct V_16 ) ;
else
V_95 = sizeof( struct V_16 ) + sizeof( struct V_9 ) * F_68 ( V_6 ) ;
V_17 = F_44 ( V_95 , V_105 ) ;
if ( ! V_17 ) {
F_8 ( L_14 ) ;
F_33 ( & V_2 -> V_13 ) ;
V_2 -> V_14 = false ;
F_37 ( & V_2 -> V_13 ) ;
return - V_76 ;
}
F_46 ( & V_17 -> V_58 ) ;
V_91 -> V_17 = V_17 ;
F_26 ( & V_2 -> V_3 ) ;
if ( V_96 )
V_17 -> V_12 |= V_106 ;
if ( V_99 )
V_17 -> V_12 |= V_63 ;
if ( V_101 )
V_17 -> V_12 |= V_61 ;
V_17 -> V_24 = V_6 -> V_29 . V_31 ;
V_17 -> V_42 = F_67 ( V_6 ) ;
if ( V_101 ) {
F_62 ( V_96 || V_99 ) ;
if ( V_2 -> V_82 )
goto V_103;
F_69 ( V_6 , 0 ) ;
return V_107 ;
}
if ( V_96 && ! F_67 ( V_6 ) ) {
F_33 ( & V_2 -> V_13 ) ;
F_59 ( & V_2 -> V_77 , & V_17 -> V_58 ) ;
F_37 ( & V_2 -> V_13 ) ;
goto V_103;
}
F_70 (bv, bio, iter) {
struct V_25 * V_25 ;
void * V_108 , * V_109 ;
V_25 = F_19 ( V_105 ) ;
if ( ! V_25 ) {
F_8 ( L_17 ) ;
F_14 ( V_2 , V_17 ) ;
F_33 ( & V_2 -> V_13 ) ;
V_2 -> V_14 = false ;
F_37 ( & V_2 -> V_13 ) ;
return - V_76 ;
}
V_108 = F_20 ( V_94 . V_15 ) ;
V_109 = F_20 ( V_25 ) ;
memcpy ( V_109 , V_108 + V_94 . V_110 , V_94 . V_45 ) ;
F_21 ( V_109 ) ;
F_21 ( V_108 ) ;
V_17 -> V_19 [ V_11 ] . V_15 = V_25 ;
V_17 -> V_19 [ V_11 ] . V_45 = V_94 . V_45 ;
V_17 -> V_18 ++ ;
V_11 ++ ;
}
if ( V_96 ) {
F_33 ( & V_2 -> V_13 ) ;
F_59 ( & V_2 -> V_77 , & V_17 -> V_58 ) ;
F_37 ( & V_2 -> V_13 ) ;
}
V_103:
F_63 ( V_68 , V_6 ) ;
return V_111 ;
}
static int F_71 ( struct V_67 * V_68 , struct V_6 * V_6 , int error )
{
struct V_1 * V_2 = V_68 -> V_89 ;
struct V_88 * V_91 = F_65 ( V_6 , sizeof( struct V_88 ) ) ;
if ( F_66 ( V_6 ) == V_40 && V_91 -> V_17 ) {
struct V_16 * V_17 = V_91 -> V_17 ;
unsigned long V_12 ;
F_9 ( & V_2 -> V_13 , V_12 ) ;
if ( V_17 -> V_12 & V_106 ) {
F_72 ( & V_17 -> V_58 , & V_2 -> V_57 ) ;
F_56 ( & V_17 -> V_58 , & V_2 -> V_57 ) ;
F_57 ( V_2 -> V_81 ) ;
} else if ( V_17 -> V_12 & V_63 ) {
F_56 ( & V_17 -> V_58 , & V_2 -> V_57 ) ;
F_57 ( V_2 -> V_81 ) ;
} else
F_56 ( & V_17 -> V_58 , & V_2 -> V_77 ) ;
F_10 ( & V_2 -> V_13 , V_12 ) ;
}
return error ;
}
static void F_73 ( struct V_67 * V_68 , T_3 type ,
unsigned V_112 , char * V_113 ,
unsigned V_114 )
{
unsigned V_115 = 0 ;
struct V_1 * V_2 = V_68 -> V_89 ;
switch ( type ) {
case V_116 :
F_74 ( L_18 , V_2 -> V_54 ,
( unsigned long long ) V_2 -> V_60 - 1 ) ;
if ( ! V_2 -> V_14 )
F_74 ( L_19 ) ;
break;
case V_117 :
F_74 ( L_20 , V_2 -> V_79 -> V_118 , V_2 -> V_33 -> V_118 ) ;
break;
}
}
static int F_75 ( struct V_67 * V_68 , unsigned int V_119 ,
unsigned long V_56 )
{
struct V_1 * V_2 = V_68 -> V_89 ;
struct V_120 * V_79 = V_2 -> V_79 ;
int V_121 = 0 ;
if ( V_68 -> V_122 != F_30 ( V_79 -> V_34 -> V_55 ) >> V_46 )
V_121 = F_76 ( NULL , V_119 ) ;
return V_121 ? : F_77 ( V_79 -> V_34 , V_79 -> V_123 , V_119 , V_56 ) ;
}
static int F_78 ( struct V_67 * V_68 , struct V_124 * V_125 ,
struct V_9 * V_126 , int V_127 )
{
struct V_1 * V_2 = V_68 -> V_89 ;
struct V_128 * V_129 = F_79 ( V_2 -> V_79 -> V_34 ) ;
if ( ! V_129 -> V_130 )
return V_127 ;
V_125 -> V_32 = V_2 -> V_79 -> V_34 ;
V_125 -> V_31 = F_80 ( V_68 , V_125 -> V_31 ) ;
return F_81 ( V_127 , V_129 -> V_130 ( V_129 , V_125 , V_126 ) ) ;
}
static int F_82 ( struct V_67 * V_68 ,
T_4 V_131 ,
void * V_20 )
{
struct V_1 * V_2 = V_68 -> V_89 ;
return V_131 ( V_68 , V_2 -> V_79 , 0 , V_68 -> V_122 , V_20 ) ;
}
static int F_83 ( struct V_67 * V_68 , unsigned V_69 , char * * V_70 )
{
int V_121 = - V_75 ;
struct V_1 * V_2 = V_68 -> V_89 ;
if ( V_69 != 2 ) {
F_84 ( L_21 , V_69 ) ;
return V_121 ;
}
if ( ! strcasecmp ( V_70 [ 0 ] , L_22 ) )
V_121 = F_54 ( V_2 , V_70 [ 1 ] ) ;
else
F_84 ( L_23 , V_70 [ 0 ] ) ;
return V_121 ;
}
static void F_85 ( struct V_67 * V_68 , struct V_132 * V_133 )
{
struct V_1 * V_2 = V_68 -> V_89 ;
struct V_128 * V_129 = F_79 ( V_2 -> V_79 -> V_34 ) ;
if ( ! V_129 || ! F_86 ( V_129 ) ) {
V_2 -> V_82 = false ;
V_133 -> V_134 = 1 << V_46 ;
V_133 -> V_135 = ( V_136 >> V_46 ) ;
}
}
static int T_5 F_87 ( void )
{
int V_121 = F_88 ( & V_137 ) ;
if ( V_121 < 0 )
F_8 ( L_24 , V_121 ) ;
return V_121 ;
}
static void T_6 F_89 ( void )
{
F_90 ( & V_137 ) ;
}
