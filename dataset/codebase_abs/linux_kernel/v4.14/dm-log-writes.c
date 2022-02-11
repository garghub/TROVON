static inline T_1 F_1 ( struct V_1 * V_2 ,
T_1 V_3 )
{
return V_3 >> ( V_2 -> V_4 - V_5 ) ;
}
static inline T_1 F_2 ( struct V_1 * V_2 ,
T_1 V_3 )
{
return V_3 << ( V_2 -> V_4 - V_5 ) ;
}
static void F_3 ( struct V_1 * V_2 )
{
if ( F_4 ( & V_2 -> V_6 ) ) {
F_5 () ;
if ( F_6 ( & V_2 -> V_7 ) )
F_7 ( & V_2 -> V_7 ) ;
}
}
static void F_8 ( struct V_1 * V_2 )
{
if ( F_4 ( & V_2 -> V_8 ) ) {
F_5 () ;
if ( F_6 ( & V_2 -> V_7 ) )
F_7 ( & V_2 -> V_7 ) ;
}
}
static void F_9 ( struct V_9 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_10 ;
if ( V_9 -> V_11 ) {
unsigned long V_12 ;
F_10 ( L_1 , V_9 -> V_11 ) ;
F_11 ( & V_2 -> V_13 , V_12 ) ;
V_2 -> V_14 = false ;
F_12 ( & V_2 -> V_13 , V_12 ) ;
}
F_13 ( V_9 ) ;
F_8 ( V_2 ) ;
F_14 ( V_9 ) ;
}
static void F_15 ( struct V_1 * V_2 ,
struct V_15 * V_16 )
{
int V_17 ;
for ( V_17 = 0 ; V_17 < V_16 -> V_18 ; V_17 ++ ) {
if ( V_16 -> V_19 [ V_17 ] . V_20 )
F_16 ( V_16 -> V_19 [ V_17 ] . V_20 ) ;
}
F_17 ( V_16 -> V_21 ) ;
F_17 ( V_16 ) ;
F_3 ( V_2 ) ;
}
static int F_18 ( struct V_1 * V_2 , void * V_22 ,
T_2 V_23 , void * V_21 , T_2 V_24 ,
T_1 V_25 )
{
struct V_9 * V_9 ;
struct V_26 * V_26 ;
void * V_27 ;
T_2 V_28 ;
V_9 = F_19 ( V_29 , 1 ) ;
if ( ! V_9 ) {
F_10 ( L_2 ) ;
goto error;
}
V_9 -> V_30 . V_31 = 0 ;
V_9 -> V_30 . V_32 = V_25 ;
F_20 ( V_9 , V_2 -> V_33 -> V_34 ) ;
V_9 -> V_35 = F_9 ;
V_9 -> V_10 = V_2 ;
F_21 ( V_9 , V_36 , 0 ) ;
V_26 = F_22 ( V_29 ) ;
if ( ! V_26 ) {
F_10 ( L_3 ) ;
F_14 ( V_9 ) ;
goto error;
}
V_27 = F_23 ( V_26 ) ;
memcpy ( V_27 , V_22 , V_23 ) ;
if ( V_24 )
memcpy ( V_27 + V_23 , V_21 , V_24 ) ;
memset ( V_27 + V_23 + V_24 , 0 ,
V_2 -> V_37 - V_23 - V_24 ) ;
F_24 ( V_27 ) ;
V_28 = F_25 ( V_9 , V_26 , V_2 -> V_37 , 0 ) ;
if ( V_28 != V_2 -> V_37 ) {
F_10 ( L_4 ) ;
goto V_38;
}
F_26 ( V_9 ) ;
return 0 ;
V_38:
F_14 ( V_9 ) ;
F_16 ( V_26 ) ;
error:
F_8 ( V_2 ) ;
return - 1 ;
}
static int F_27 ( struct V_1 * V_2 ,
struct V_15 * V_16 , T_1 V_25 )
{
struct V_9 * V_9 ;
struct V_39 V_22 ;
T_2 V_28 ;
int V_17 ;
V_22 . V_25 = F_28 ( V_16 -> V_25 ) ;
V_22 . V_40 = F_28 ( V_16 -> V_40 ) ;
V_22 . V_12 = F_28 ( V_16 -> V_12 ) ;
V_22 . V_41 = F_28 ( V_16 -> V_24 ) ;
if ( F_18 ( V_2 , & V_22 , sizeof( V_22 ) , V_16 -> V_21 ,
V_16 -> V_24 , V_25 ) ) {
F_15 ( V_2 , V_16 ) ;
return - 1 ;
}
if ( ! V_16 -> V_18 )
goto V_42;
V_25 += F_2 ( V_2 , 1 ) ;
F_29 ( & V_2 -> V_8 ) ;
V_9 = F_19 ( V_29 , F_30 ( V_16 -> V_18 , V_43 ) ) ;
if ( ! V_9 ) {
F_10 ( L_2 ) ;
goto error;
}
V_9 -> V_30 . V_31 = 0 ;
V_9 -> V_30 . V_32 = V_25 ;
F_20 ( V_9 , V_2 -> V_33 -> V_34 ) ;
V_9 -> V_35 = F_9 ;
V_9 -> V_10 = V_2 ;
F_21 ( V_9 , V_36 , 0 ) ;
for ( V_17 = 0 ; V_17 < V_16 -> V_18 ; V_17 ++ ) {
V_28 = F_25 ( V_9 , V_16 -> V_19 [ V_17 ] . V_20 ,
V_16 -> V_19 [ V_17 ] . V_44 , 0 ) ;
if ( V_28 != V_16 -> V_19 [ V_17 ] . V_44 ) {
F_29 ( & V_2 -> V_8 ) ;
F_26 ( V_9 ) ;
V_9 = F_19 ( V_29 , F_30 ( V_16 -> V_18 - V_17 , V_43 ) ) ;
if ( ! V_9 ) {
F_10 ( L_2 ) ;
goto error;
}
V_9 -> V_30 . V_31 = 0 ;
V_9 -> V_30 . V_32 = V_25 ;
F_20 ( V_9 , V_2 -> V_33 -> V_34 ) ;
V_9 -> V_35 = F_9 ;
V_9 -> V_10 = V_2 ;
F_21 ( V_9 , V_36 , 0 ) ;
V_28 = F_25 ( V_9 , V_16 -> V_19 [ V_17 ] . V_20 ,
V_16 -> V_19 [ V_17 ] . V_44 , 0 ) ;
if ( V_28 != V_16 -> V_19 [ V_17 ] . V_44 ) {
F_10 ( L_5 ) ;
F_14 ( V_9 ) ;
goto error;
}
}
V_25 += V_16 -> V_19 [ V_17 ] . V_44 >> V_5 ;
}
F_26 ( V_9 ) ;
V_42:
F_17 ( V_16 -> V_21 ) ;
F_17 ( V_16 ) ;
F_3 ( V_2 ) ;
return 0 ;
error:
F_15 ( V_2 , V_16 ) ;
F_8 ( V_2 ) ;
return - 1 ;
}
static int F_31 ( struct V_1 * V_2 )
{
struct V_45 V_46 ;
V_46 . V_47 = F_28 ( V_48 ) ;
V_46 . V_49 = F_28 ( V_50 ) ;
V_46 . V_51 = F_28 ( V_2 -> V_52 ) ;
V_46 . V_37 = F_32 ( V_2 -> V_37 ) ;
if ( F_18 ( V_2 , & V_46 , sizeof( V_46 ) , NULL , 0 , 0 ) ) {
F_10 ( L_6 ) ;
return - 1 ;
}
return 0 ;
}
static inline T_1 F_33 ( struct V_1 * V_2 )
{
return F_34 ( V_2 -> V_33 -> V_34 -> V_53 ) >> V_5 ;
}
static int F_35 ( void * V_54 )
{
struct V_1 * V_2 = (struct V_1 * ) V_54 ;
T_1 V_25 = 0 ;
while ( ! F_36 () ) {
bool V_46 = false ;
bool V_14 ;
struct V_15 * V_16 = NULL ;
int V_28 ;
F_37 ( & V_2 -> V_13 ) ;
if ( ! F_38 ( & V_2 -> V_55 ) ) {
V_16 = F_39 ( & V_2 -> V_55 ,
struct V_15 , V_56 ) ;
F_40 ( & V_16 -> V_56 ) ;
if ( ! V_2 -> V_14 )
goto V_57;
V_25 = V_2 -> V_58 ;
if ( ! ( V_16 -> V_12 & V_59 ) )
V_2 -> V_58 += F_2 ( V_2 , V_16 -> V_40 ) ;
V_2 -> V_58 += F_2 ( V_2 , 1 ) ;
if ( ! V_2 -> V_60 )
V_2 -> V_60 = F_33 ( V_2 ) ;
if ( V_2 -> V_60 &&
V_2 -> V_58 >= V_2 -> V_60 ) {
F_10 ( L_7 ) ;
V_2 -> V_14 = false ;
goto V_57;
}
V_2 -> V_52 ++ ;
F_29 ( & V_2 -> V_8 ) ;
V_46 = ( V_16 -> V_12 & ( V_61 | V_62 ) ) ;
if ( V_46 )
F_29 ( & V_2 -> V_8 ) ;
}
V_57:
V_14 = V_2 -> V_14 ;
F_41 ( & V_2 -> V_13 ) ;
if ( V_16 ) {
if ( V_14 ) {
V_28 = F_27 ( V_2 , V_16 , V_25 ) ;
if ( ! V_28 && V_46 )
V_28 = F_31 ( V_2 ) ;
if ( V_28 ) {
F_37 ( & V_2 -> V_13 ) ;
V_2 -> V_14 = false ;
F_41 ( & V_2 -> V_13 ) ;
}
} else
F_15 ( V_2 , V_16 ) ;
continue;
}
if ( ! F_42 () ) {
F_43 ( V_63 ) ;
if ( ! F_36 () &&
F_38 ( & V_2 -> V_55 ) )
F_44 () ;
F_45 ( V_64 ) ;
}
}
return 0 ;
}
static int F_46 ( struct V_65 * V_66 , unsigned int V_67 , char * * V_68 )
{
struct V_1 * V_2 ;
struct V_69 V_70 ;
const char * V_71 , * V_72 ;
int V_28 ;
V_70 . V_67 = V_67 ;
V_70 . V_68 = V_68 ;
if ( V_67 < 2 ) {
V_66 -> error = L_8 ;
return - V_73 ;
}
V_2 = F_47 ( sizeof( struct V_1 ) , V_29 ) ;
if ( ! V_2 ) {
V_66 -> error = L_9 ;
return - V_74 ;
}
F_48 ( & V_2 -> V_13 ) ;
F_49 ( & V_2 -> V_75 ) ;
F_49 ( & V_2 -> V_55 ) ;
F_50 ( & V_2 -> V_7 ) ;
F_51 ( & V_2 -> V_8 , 0 ) ;
F_51 ( & V_2 -> V_6 , 0 ) ;
V_71 = F_52 ( & V_70 ) ;
V_28 = F_53 ( V_66 , V_71 , F_54 ( V_66 -> V_76 ) , & V_2 -> V_77 ) ;
if ( V_28 ) {
V_66 -> error = L_10 ;
goto V_78;
}
V_72 = F_52 ( & V_70 ) ;
V_28 = F_53 ( V_66 , V_72 , F_54 ( V_66 -> V_76 ) ,
& V_2 -> V_33 ) ;
if ( V_28 ) {
V_66 -> error = L_11 ;
F_55 ( V_66 , V_2 -> V_77 ) ;
goto V_78;
}
V_2 -> V_37 = F_56 ( V_2 -> V_77 -> V_34 ) ;
V_2 -> V_4 = F_57 ( V_2 -> V_37 ) ;
V_2 -> V_79 = F_58 ( F_35 , V_2 , L_12 ) ;
if ( F_59 ( V_2 -> V_79 ) ) {
V_28 = F_60 ( V_2 -> V_79 ) ;
V_66 -> error = L_13 ;
F_55 ( V_66 , V_2 -> V_77 ) ;
F_55 ( V_66 , V_2 -> V_33 ) ;
goto V_78;
}
V_2 -> V_58 = V_2 -> V_37 >> V_5 ;
V_2 -> V_14 = true ;
V_2 -> V_60 = F_33 ( V_2 ) ;
V_2 -> V_80 = true ;
V_66 -> V_81 = 1 ;
V_66 -> V_82 = true ;
V_66 -> V_83 = 1 ;
V_66 -> V_84 = true ;
V_66 -> V_85 = sizeof( struct V_86 ) ;
V_66 -> V_87 = V_2 ;
return 0 ;
V_78:
F_17 ( V_2 ) ;
return V_28 ;
}
static int F_61 ( struct V_1 * V_2 , char * V_21 )
{
struct V_15 * V_16 ;
T_2 V_88 = V_2 -> V_37 - sizeof( struct V_39 ) ;
V_16 = F_47 ( sizeof( struct V_15 ) , V_29 ) ;
if ( ! V_16 ) {
F_10 ( L_14 ) ;
return - V_74 ;
}
V_16 -> V_21 = F_62 ( V_21 , V_88 , V_29 ) ;
if ( ! V_16 -> V_21 ) {
F_10 ( L_15 ) ;
F_17 ( V_16 ) ;
return - V_74 ;
}
F_29 ( & V_2 -> V_6 ) ;
V_16 -> V_24 = strlen ( V_16 -> V_21 ) ;
V_16 -> V_12 |= V_62 ;
F_37 ( & V_2 -> V_13 ) ;
F_63 ( & V_16 -> V_56 , & V_2 -> V_55 ) ;
F_41 ( & V_2 -> V_13 ) ;
F_64 ( V_2 -> V_79 ) ;
return 0 ;
}
static void F_65 ( struct V_65 * V_66 )
{
struct V_1 * V_2 = V_66 -> V_87 ;
F_37 ( & V_2 -> V_13 ) ;
F_66 ( & V_2 -> V_75 , & V_2 -> V_55 ) ;
F_41 ( & V_2 -> V_13 ) ;
F_61 ( V_2 , L_16 ) ;
F_64 ( V_2 -> V_79 ) ;
F_67 ( V_2 -> V_7 , ! F_68 ( & V_2 -> V_8 ) &&
! F_68 ( & V_2 -> V_6 ) ) ;
F_69 ( V_2 -> V_79 ) ;
F_70 ( ! F_38 ( & V_2 -> V_55 ) ) ;
F_70 ( ! F_38 ( & V_2 -> V_75 ) ) ;
F_55 ( V_66 , V_2 -> V_77 ) ;
F_55 ( V_66 , V_2 -> V_33 ) ;
F_17 ( V_2 ) ;
}
static void F_71 ( struct V_65 * V_66 , struct V_9 * V_9 )
{
struct V_1 * V_2 = V_66 -> V_87 ;
F_20 ( V_9 , V_2 -> V_77 -> V_34 ) ;
}
static int F_72 ( struct V_65 * V_66 , struct V_9 * V_9 )
{
struct V_1 * V_2 = V_66 -> V_87 ;
struct V_86 * V_89 = F_73 ( V_9 , sizeof( struct V_86 ) ) ;
struct V_15 * V_16 ;
struct V_90 V_91 ;
struct V_92 V_93 ;
T_2 V_94 ;
int V_17 = 0 ;
bool V_95 = ( V_9 -> V_96 & V_97 ) ;
bool V_98 = ( V_9 -> V_96 & V_99 ) ;
bool V_100 = ( F_74 ( V_9 ) == V_101 ) ;
V_89 -> V_16 = NULL ;
if ( ! V_2 -> V_14 )
goto V_102;
if ( F_75 ( V_9 ) == V_103 )
goto V_102;
if ( ! F_76 ( V_9 ) && ! V_95 )
goto V_102;
if ( V_100 )
V_94 = sizeof( struct V_15 ) ;
else
V_94 = sizeof( struct V_15 ) + sizeof( struct V_92 ) * F_77 ( V_9 ) ;
V_16 = F_47 ( V_94 , V_104 ) ;
if ( ! V_16 ) {
F_10 ( L_14 ) ;
F_37 ( & V_2 -> V_13 ) ;
V_2 -> V_14 = false ;
F_41 ( & V_2 -> V_13 ) ;
return V_105 ;
}
F_49 ( & V_16 -> V_56 ) ;
V_89 -> V_16 = V_16 ;
F_29 ( & V_2 -> V_6 ) ;
if ( V_95 )
V_16 -> V_12 |= V_106 ;
if ( V_98 )
V_16 -> V_12 |= V_61 ;
if ( V_100 )
V_16 -> V_12 |= V_59 ;
V_16 -> V_25 = F_1 ( V_2 , V_9 -> V_30 . V_32 ) ;
V_16 -> V_40 = F_1 ( V_2 , F_76 ( V_9 ) ) ;
if ( V_100 ) {
F_70 ( V_95 || V_98 ) ;
if ( V_2 -> V_80 )
goto V_102;
F_78 ( V_9 ) ;
return V_107 ;
}
if ( V_95 && ! F_76 ( V_9 ) ) {
F_37 ( & V_2 -> V_13 ) ;
F_66 ( & V_2 -> V_75 , & V_16 -> V_56 ) ;
F_41 ( & V_2 -> V_13 ) ;
goto V_102;
}
F_79 (bv, bio, iter) {
struct V_26 * V_26 ;
void * V_108 , * V_109 ;
V_26 = F_22 ( V_104 ) ;
if ( ! V_26 ) {
F_10 ( L_17 ) ;
F_15 ( V_2 , V_16 ) ;
F_37 ( & V_2 -> V_13 ) ;
V_2 -> V_14 = false ;
F_41 ( & V_2 -> V_13 ) ;
return V_105 ;
}
V_108 = F_23 ( V_93 . V_20 ) ;
V_109 = F_23 ( V_26 ) ;
memcpy ( V_109 , V_108 + V_93 . V_110 , V_93 . V_44 ) ;
F_24 ( V_109 ) ;
F_24 ( V_108 ) ;
V_16 -> V_19 [ V_17 ] . V_20 = V_26 ;
V_16 -> V_19 [ V_17 ] . V_44 = V_93 . V_44 ;
V_16 -> V_18 ++ ;
V_17 ++ ;
}
if ( V_95 ) {
F_37 ( & V_2 -> V_13 ) ;
F_66 ( & V_2 -> V_75 , & V_16 -> V_56 ) ;
F_41 ( & V_2 -> V_13 ) ;
}
V_102:
F_71 ( V_66 , V_9 ) ;
return V_111 ;
}
static int F_80 ( struct V_65 * V_66 , struct V_9 * V_9 ,
T_3 * error )
{
struct V_1 * V_2 = V_66 -> V_87 ;
struct V_86 * V_89 = F_73 ( V_9 , sizeof( struct V_86 ) ) ;
if ( F_75 ( V_9 ) == V_112 && V_89 -> V_16 ) {
struct V_15 * V_16 = V_89 -> V_16 ;
unsigned long V_12 ;
F_11 ( & V_2 -> V_13 , V_12 ) ;
if ( V_16 -> V_12 & V_106 ) {
F_81 ( & V_16 -> V_56 , & V_2 -> V_55 ) ;
F_63 ( & V_16 -> V_56 , & V_2 -> V_55 ) ;
F_64 ( V_2 -> V_79 ) ;
} else if ( V_16 -> V_12 & V_61 ) {
F_63 ( & V_16 -> V_56 , & V_2 -> V_55 ) ;
F_64 ( V_2 -> V_79 ) ;
} else
F_63 ( & V_16 -> V_56 , & V_2 -> V_75 ) ;
F_12 ( & V_2 -> V_13 , V_12 ) ;
}
return V_113 ;
}
static void F_82 ( struct V_65 * V_66 , T_4 type ,
unsigned V_114 , char * V_115 ,
unsigned V_116 )
{
unsigned V_117 = 0 ;
struct V_1 * V_2 = V_66 -> V_87 ;
switch ( type ) {
case V_118 :
F_83 ( L_18 , V_2 -> V_52 ,
( unsigned long long ) V_2 -> V_58 - 1 ) ;
if ( ! V_2 -> V_14 )
F_83 ( L_19 ) ;
break;
case V_119 :
F_83 ( L_20 , V_2 -> V_77 -> V_120 , V_2 -> V_33 -> V_120 ) ;
break;
}
}
static int F_84 ( struct V_65 * V_66 ,
struct V_121 * * V_34 , T_5 * V_122 )
{
struct V_1 * V_2 = V_66 -> V_87 ;
struct V_123 * V_77 = V_2 -> V_77 ;
* V_34 = V_77 -> V_34 ;
if ( V_66 -> V_124 != F_34 ( V_77 -> V_34 -> V_53 ) >> V_5 )
return 1 ;
return 0 ;
}
static int F_85 ( struct V_65 * V_66 ,
T_6 V_125 ,
void * V_21 )
{
struct V_1 * V_2 = V_66 -> V_87 ;
return V_125 ( V_66 , V_2 -> V_77 , 0 , V_66 -> V_124 , V_21 ) ;
}
static int F_86 ( struct V_65 * V_66 , unsigned V_67 , char * * V_68 )
{
int V_126 = - V_73 ;
struct V_1 * V_2 = V_66 -> V_87 ;
if ( V_67 != 2 ) {
F_87 ( L_21 , V_67 ) ;
return V_126 ;
}
if ( ! strcasecmp ( V_68 [ 0 ] , L_22 ) )
V_126 = F_61 ( V_2 , V_68 [ 1 ] ) ;
else
F_87 ( L_23 , V_68 [ 0 ] ) ;
return V_126 ;
}
static void F_88 ( struct V_65 * V_66 , struct V_127 * V_128 )
{
struct V_1 * V_2 = V_66 -> V_87 ;
struct V_129 * V_130 = F_89 ( V_2 -> V_77 -> V_34 ) ;
if ( ! V_130 || ! F_90 ( V_130 ) ) {
V_2 -> V_80 = false ;
V_128 -> V_131 = V_2 -> V_37 ;
V_128 -> V_132 = ( V_133 >> V_5 ) ;
}
V_128 -> V_134 = F_56 ( V_2 -> V_77 -> V_34 ) ;
V_128 -> V_135 = F_91 ( V_2 -> V_77 -> V_34 ) ;
V_128 -> V_136 = V_128 -> V_135 ;
}
static int T_7 F_92 ( void )
{
int V_126 = F_93 ( & V_137 ) ;
if ( V_126 < 0 )
F_10 ( L_24 , V_126 ) ;
return V_126 ;
}
static void T_8 F_94 ( void )
{
F_95 ( & V_137 ) ;
}
