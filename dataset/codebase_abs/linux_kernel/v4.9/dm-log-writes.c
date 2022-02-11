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
static void F_7 ( struct V_6 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_7 ;
if ( V_6 -> V_8 ) {
unsigned long V_9 ;
F_8 ( L_1 , V_6 -> V_8 ) ;
F_9 ( & V_2 -> V_10 , V_9 ) ;
V_2 -> V_11 = false ;
F_10 ( & V_2 -> V_10 , V_9 ) ;
}
F_11 ( V_6 ) ;
F_6 ( V_2 ) ;
F_12 ( V_6 ) ;
}
static void F_13 ( struct V_1 * V_2 ,
struct V_12 * V_13 )
{
int V_14 ;
for ( V_14 = 0 ; V_14 < V_13 -> V_15 ; V_14 ++ ) {
if ( V_13 -> V_16 [ V_14 ] . V_17 )
F_14 ( V_13 -> V_16 [ V_14 ] . V_17 ) ;
}
F_15 ( V_13 -> V_18 ) ;
F_15 ( V_13 ) ;
F_1 ( V_2 ) ;
}
static int F_16 ( struct V_1 * V_2 , void * V_19 ,
T_1 V_20 , void * V_18 , T_1 V_21 ,
T_2 V_22 )
{
struct V_6 * V_6 ;
struct V_23 * V_23 ;
void * V_24 ;
T_1 V_25 ;
V_6 = F_17 ( V_26 , 1 ) ;
if ( ! V_6 ) {
F_8 ( L_2 ) ;
goto error;
}
V_6 -> V_27 . V_28 = 0 ;
V_6 -> V_27 . V_29 = V_22 ;
V_6 -> V_30 = V_2 -> V_31 -> V_32 ;
V_6 -> V_33 = F_7 ;
V_6 -> V_7 = V_2 ;
F_18 ( V_6 , V_34 , 0 ) ;
V_23 = F_19 ( V_26 ) ;
if ( ! V_23 ) {
F_8 ( L_3 ) ;
F_12 ( V_6 ) ;
goto error;
}
V_24 = F_20 ( V_23 ) ;
memcpy ( V_24 , V_19 , V_20 ) ;
if ( V_21 )
memcpy ( V_24 + V_20 , V_18 , V_21 ) ;
memset ( V_24 + V_20 + V_21 , 0 ,
V_2 -> V_35 - V_20 - V_21 ) ;
F_21 ( V_24 ) ;
V_25 = F_22 ( V_6 , V_23 , V_2 -> V_35 , 0 ) ;
if ( V_25 != V_2 -> V_35 ) {
F_8 ( L_4 ) ;
goto V_36;
}
F_23 ( V_6 ) ;
return 0 ;
V_36:
F_12 ( V_6 ) ;
F_14 ( V_23 ) ;
error:
F_6 ( V_2 ) ;
return - 1 ;
}
static int F_24 ( struct V_1 * V_2 ,
struct V_12 * V_13 , T_2 V_22 )
{
struct V_6 * V_6 ;
struct V_37 V_19 ;
T_1 V_25 ;
int V_14 ;
V_19 . V_22 = F_25 ( V_13 -> V_22 ) ;
V_19 . V_38 = F_25 ( V_13 -> V_38 ) ;
V_19 . V_9 = F_25 ( V_13 -> V_9 ) ;
V_19 . V_39 = F_25 ( V_13 -> V_21 ) ;
if ( F_16 ( V_2 , & V_19 , sizeof( V_19 ) , V_13 -> V_18 ,
V_13 -> V_21 , V_22 ) ) {
F_13 ( V_2 , V_13 ) ;
return - 1 ;
}
if ( ! V_13 -> V_15 )
goto V_40;
V_22 ++ ;
F_26 ( & V_2 -> V_5 ) ;
V_6 = F_17 ( V_26 , F_27 ( V_13 -> V_15 , V_41 ) ) ;
if ( ! V_6 ) {
F_8 ( L_2 ) ;
goto error;
}
V_6 -> V_27 . V_28 = 0 ;
V_6 -> V_27 . V_29 = V_22 ;
V_6 -> V_30 = V_2 -> V_31 -> V_32 ;
V_6 -> V_33 = F_7 ;
V_6 -> V_7 = V_2 ;
F_18 ( V_6 , V_34 , 0 ) ;
for ( V_14 = 0 ; V_14 < V_13 -> V_15 ; V_14 ++ ) {
V_25 = F_22 ( V_6 , V_13 -> V_16 [ V_14 ] . V_17 ,
V_13 -> V_16 [ V_14 ] . V_42 , 0 ) ;
if ( V_25 != V_13 -> V_16 [ V_14 ] . V_42 ) {
F_26 ( & V_2 -> V_5 ) ;
F_23 ( V_6 ) ;
V_6 = F_17 ( V_26 , F_27 ( V_13 -> V_15 - V_14 , V_41 ) ) ;
if ( ! V_6 ) {
F_8 ( L_2 ) ;
goto error;
}
V_6 -> V_27 . V_28 = 0 ;
V_6 -> V_27 . V_29 = V_22 ;
V_6 -> V_30 = V_2 -> V_31 -> V_32 ;
V_6 -> V_33 = F_7 ;
V_6 -> V_7 = V_2 ;
F_18 ( V_6 , V_34 , 0 ) ;
V_25 = F_22 ( V_6 , V_13 -> V_16 [ V_14 ] . V_17 ,
V_13 -> V_16 [ V_14 ] . V_42 , 0 ) ;
if ( V_25 != V_13 -> V_16 [ V_14 ] . V_42 ) {
F_8 ( L_5 ) ;
F_12 ( V_6 ) ;
goto error;
}
}
V_22 += V_13 -> V_16 [ V_14 ] . V_42 >> V_43 ;
}
F_23 ( V_6 ) ;
V_40:
F_15 ( V_13 -> V_18 ) ;
F_15 ( V_13 ) ;
F_1 ( V_2 ) ;
return 0 ;
error:
F_13 ( V_2 , V_13 ) ;
F_6 ( V_2 ) ;
return - 1 ;
}
static int F_28 ( struct V_1 * V_2 )
{
struct V_44 V_45 ;
V_45 . V_46 = F_25 ( V_47 ) ;
V_45 . V_48 = F_25 ( V_49 ) ;
V_45 . V_50 = F_25 ( V_2 -> V_51 ) ;
V_45 . V_35 = F_29 ( V_2 -> V_35 ) ;
if ( F_16 ( V_2 , & V_45 , sizeof( V_45 ) , NULL , 0 , 0 ) ) {
F_8 ( L_6 ) ;
return - 1 ;
}
return 0 ;
}
static inline T_2 F_30 ( struct V_1 * V_2 )
{
return F_31 ( V_2 -> V_31 -> V_32 -> V_52 ) >> V_43 ;
}
static int F_32 ( void * V_53 )
{
struct V_1 * V_2 = (struct V_1 * ) V_53 ;
T_2 V_22 = 0 ;
while ( ! F_33 () ) {
bool V_45 = false ;
bool V_11 ;
struct V_12 * V_13 = NULL ;
int V_25 ;
F_34 ( & V_2 -> V_10 ) ;
if ( ! F_35 ( & V_2 -> V_54 ) ) {
V_13 = F_36 ( & V_2 -> V_54 ,
struct V_12 , V_55 ) ;
F_37 ( & V_13 -> V_55 ) ;
if ( ! V_2 -> V_11 )
goto V_56;
V_22 = V_2 -> V_57 ;
if ( V_13 -> V_9 & V_58 )
V_2 -> V_57 ++ ;
else
V_2 -> V_57 += V_13 -> V_38 + 1 ;
if ( ! V_2 -> V_59 )
V_2 -> V_59 = F_30 ( V_2 ) ;
if ( V_2 -> V_59 &&
V_2 -> V_57 >= V_2 -> V_59 ) {
F_8 ( L_7 ) ;
V_2 -> V_11 = false ;
goto V_56;
}
V_2 -> V_51 ++ ;
F_26 ( & V_2 -> V_5 ) ;
V_45 = ( V_13 -> V_9 & ( V_60 | V_61 ) ) ;
if ( V_45 )
F_26 ( & V_2 -> V_5 ) ;
}
V_56:
V_11 = V_2 -> V_11 ;
F_38 ( & V_2 -> V_10 ) ;
if ( V_13 ) {
if ( V_11 ) {
V_25 = F_24 ( V_2 , V_13 , V_22 ) ;
if ( ! V_25 && V_45 )
V_25 = F_28 ( V_2 ) ;
if ( V_25 ) {
F_34 ( & V_2 -> V_10 ) ;
V_2 -> V_11 = false ;
F_38 ( & V_2 -> V_10 ) ;
}
} else
F_13 ( V_2 , V_13 ) ;
continue;
}
if ( ! F_39 () ) {
F_40 ( V_62 ) ;
if ( ! F_33 () &&
! F_41 ( & V_2 -> V_3 ) )
F_42 () ;
F_43 ( V_63 ) ;
}
}
return 0 ;
}
static int F_44 ( struct V_64 * V_65 , unsigned int V_66 , char * * V_67 )
{
struct V_1 * V_2 ;
struct V_68 V_69 ;
const char * V_70 , * V_71 ;
int V_25 ;
V_69 . V_66 = V_66 ;
V_69 . V_67 = V_67 ;
if ( V_66 < 2 ) {
V_65 -> error = L_8 ;
return - V_72 ;
}
V_2 = F_45 ( sizeof( struct V_1 ) , V_26 ) ;
if ( ! V_2 ) {
V_65 -> error = L_9 ;
return - V_73 ;
}
F_46 ( & V_2 -> V_10 ) ;
F_47 ( & V_2 -> V_74 ) ;
F_47 ( & V_2 -> V_54 ) ;
F_48 ( & V_2 -> V_4 ) ;
V_2 -> V_35 = 1 << V_43 ;
F_49 ( & V_2 -> V_5 , 0 ) ;
F_49 ( & V_2 -> V_3 , 0 ) ;
V_70 = F_50 ( & V_69 ) ;
V_25 = F_51 ( V_65 , V_70 , F_52 ( V_65 -> V_75 ) , & V_2 -> V_76 ) ;
if ( V_25 ) {
V_65 -> error = L_10 ;
goto V_77;
}
V_71 = F_50 ( & V_69 ) ;
V_25 = F_51 ( V_65 , V_71 , F_52 ( V_65 -> V_75 ) ,
& V_2 -> V_31 ) ;
if ( V_25 ) {
V_65 -> error = L_11 ;
F_53 ( V_65 , V_2 -> V_76 ) ;
goto V_77;
}
V_2 -> V_78 = F_54 ( F_32 , V_2 , L_12 ) ;
if ( F_55 ( V_2 -> V_78 ) ) {
V_25 = F_56 ( V_2 -> V_78 ) ;
V_65 -> error = L_13 ;
F_53 ( V_65 , V_2 -> V_76 ) ;
F_53 ( V_65 , V_2 -> V_31 ) ;
goto V_77;
}
V_2 -> V_57 = 1 ;
V_2 -> V_11 = true ;
V_2 -> V_59 = F_30 ( V_2 ) ;
V_2 -> V_79 = true ;
V_65 -> V_80 = 1 ;
V_65 -> V_81 = true ;
V_65 -> V_82 = 1 ;
V_65 -> V_83 = true ;
V_65 -> V_84 = sizeof( struct V_85 ) ;
V_65 -> V_86 = V_2 ;
return 0 ;
V_77:
F_15 ( V_2 ) ;
return V_25 ;
}
static int F_57 ( struct V_1 * V_2 , char * V_18 )
{
struct V_12 * V_13 ;
T_1 V_87 = V_2 -> V_35 - sizeof( struct V_37 ) ;
V_13 = F_45 ( sizeof( struct V_12 ) , V_26 ) ;
if ( ! V_13 ) {
F_8 ( L_14 ) ;
return - V_73 ;
}
V_13 -> V_18 = F_58 ( V_18 , V_87 , V_26 ) ;
if ( ! V_13 -> V_18 ) {
F_8 ( L_15 ) ;
F_15 ( V_13 ) ;
return - V_73 ;
}
F_26 ( & V_2 -> V_3 ) ;
V_13 -> V_21 = strlen ( V_13 -> V_18 ) ;
V_13 -> V_9 |= V_61 ;
F_34 ( & V_2 -> V_10 ) ;
F_59 ( & V_13 -> V_55 , & V_2 -> V_54 ) ;
F_38 ( & V_2 -> V_10 ) ;
F_60 ( V_2 -> V_78 ) ;
return 0 ;
}
static void F_61 ( struct V_64 * V_65 )
{
struct V_1 * V_2 = V_65 -> V_86 ;
F_34 ( & V_2 -> V_10 ) ;
F_62 ( & V_2 -> V_74 , & V_2 -> V_54 ) ;
F_38 ( & V_2 -> V_10 ) ;
F_57 ( V_2 , L_16 ) ;
F_60 ( V_2 -> V_78 ) ;
F_63 ( V_2 -> V_4 , ! F_41 ( & V_2 -> V_5 ) &&
! F_41 ( & V_2 -> V_3 ) ) ;
F_64 ( V_2 -> V_78 ) ;
F_65 ( ! F_35 ( & V_2 -> V_54 ) ) ;
F_65 ( ! F_35 ( & V_2 -> V_74 ) ) ;
F_53 ( V_65 , V_2 -> V_76 ) ;
F_53 ( V_65 , V_2 -> V_31 ) ;
F_15 ( V_2 ) ;
}
static void F_66 ( struct V_64 * V_65 , struct V_6 * V_6 )
{
struct V_1 * V_2 = V_65 -> V_86 ;
V_6 -> V_30 = V_2 -> V_76 -> V_32 ;
}
static int F_67 ( struct V_64 * V_65 , struct V_6 * V_6 )
{
struct V_1 * V_2 = V_65 -> V_86 ;
struct V_85 * V_88 = F_68 ( V_6 , sizeof( struct V_85 ) ) ;
struct V_12 * V_13 ;
struct V_89 V_90 ;
struct V_91 V_92 ;
T_1 V_93 ;
int V_14 = 0 ;
bool V_94 = ( V_6 -> V_95 & V_96 ) ;
bool V_97 = ( V_6 -> V_95 & V_98 ) ;
bool V_99 = ( F_69 ( V_6 ) == V_100 ) ;
V_88 -> V_13 = NULL ;
if ( ! V_2 -> V_11 )
goto V_101;
if ( F_70 ( V_6 ) == V_102 )
goto V_101;
if ( ! F_71 ( V_6 ) && ! V_94 )
goto V_101;
if ( V_99 )
V_93 = sizeof( struct V_12 ) ;
else
V_93 = sizeof( struct V_12 ) + sizeof( struct V_91 ) * F_72 ( V_6 ) ;
V_13 = F_45 ( V_93 , V_103 ) ;
if ( ! V_13 ) {
F_8 ( L_14 ) ;
F_34 ( & V_2 -> V_10 ) ;
V_2 -> V_11 = false ;
F_38 ( & V_2 -> V_10 ) ;
return - V_73 ;
}
F_47 ( & V_13 -> V_55 ) ;
V_88 -> V_13 = V_13 ;
F_26 ( & V_2 -> V_3 ) ;
if ( V_94 )
V_13 -> V_9 |= V_104 ;
if ( V_97 )
V_13 -> V_9 |= V_60 ;
if ( V_99 )
V_13 -> V_9 |= V_58 ;
V_13 -> V_22 = V_6 -> V_27 . V_29 ;
V_13 -> V_38 = F_71 ( V_6 ) ;
if ( V_99 ) {
F_65 ( V_94 || V_97 ) ;
if ( V_2 -> V_79 )
goto V_101;
F_73 ( V_6 ) ;
return V_105 ;
}
if ( V_94 && ! F_71 ( V_6 ) ) {
F_34 ( & V_2 -> V_10 ) ;
F_62 ( & V_2 -> V_74 , & V_13 -> V_55 ) ;
F_38 ( & V_2 -> V_10 ) ;
goto V_101;
}
F_74 (bv, bio, iter) {
struct V_23 * V_23 ;
void * V_106 , * V_107 ;
V_23 = F_19 ( V_103 ) ;
if ( ! V_23 ) {
F_8 ( L_17 ) ;
F_13 ( V_2 , V_13 ) ;
F_34 ( & V_2 -> V_10 ) ;
V_2 -> V_11 = false ;
F_38 ( & V_2 -> V_10 ) ;
return - V_73 ;
}
V_106 = F_20 ( V_92 . V_17 ) ;
V_107 = F_20 ( V_23 ) ;
memcpy ( V_107 , V_106 + V_92 . V_108 , V_92 . V_42 ) ;
F_21 ( V_107 ) ;
F_21 ( V_106 ) ;
V_13 -> V_16 [ V_14 ] . V_17 = V_23 ;
V_13 -> V_16 [ V_14 ] . V_42 = V_92 . V_42 ;
V_13 -> V_15 ++ ;
V_14 ++ ;
}
if ( V_94 ) {
F_34 ( & V_2 -> V_10 ) ;
F_62 ( & V_2 -> V_74 , & V_13 -> V_55 ) ;
F_38 ( & V_2 -> V_10 ) ;
}
V_101:
F_66 ( V_65 , V_6 ) ;
return V_109 ;
}
static int F_75 ( struct V_64 * V_65 , struct V_6 * V_6 , int error )
{
struct V_1 * V_2 = V_65 -> V_86 ;
struct V_85 * V_88 = F_68 ( V_6 , sizeof( struct V_85 ) ) ;
if ( F_70 ( V_6 ) == V_110 && V_88 -> V_13 ) {
struct V_12 * V_13 = V_88 -> V_13 ;
unsigned long V_9 ;
F_9 ( & V_2 -> V_10 , V_9 ) ;
if ( V_13 -> V_9 & V_104 ) {
F_76 ( & V_13 -> V_55 , & V_2 -> V_54 ) ;
F_59 ( & V_13 -> V_55 , & V_2 -> V_54 ) ;
F_60 ( V_2 -> V_78 ) ;
} else if ( V_13 -> V_9 & V_60 ) {
F_59 ( & V_13 -> V_55 , & V_2 -> V_54 ) ;
F_60 ( V_2 -> V_78 ) ;
} else
F_59 ( & V_13 -> V_55 , & V_2 -> V_74 ) ;
F_10 ( & V_2 -> V_10 , V_9 ) ;
}
return error ;
}
static void F_77 ( struct V_64 * V_65 , T_3 type ,
unsigned V_111 , char * V_112 ,
unsigned V_113 )
{
unsigned V_114 = 0 ;
struct V_1 * V_2 = V_65 -> V_86 ;
switch ( type ) {
case V_115 :
F_78 ( L_18 , V_2 -> V_51 ,
( unsigned long long ) V_2 -> V_57 - 1 ) ;
if ( ! V_2 -> V_11 )
F_78 ( L_19 ) ;
break;
case V_116 :
F_78 ( L_20 , V_2 -> V_76 -> V_117 , V_2 -> V_31 -> V_117 ) ;
break;
}
}
static int F_79 ( struct V_64 * V_65 ,
struct V_118 * * V_32 , T_4 * V_119 )
{
struct V_1 * V_2 = V_65 -> V_86 ;
struct V_120 * V_76 = V_2 -> V_76 ;
* V_32 = V_76 -> V_32 ;
if ( V_65 -> V_121 != F_31 ( V_76 -> V_32 -> V_52 ) >> V_43 )
return 1 ;
return 0 ;
}
static int F_80 ( struct V_64 * V_65 ,
T_5 V_122 ,
void * V_18 )
{
struct V_1 * V_2 = V_65 -> V_86 ;
return V_122 ( V_65 , V_2 -> V_76 , 0 , V_65 -> V_121 , V_18 ) ;
}
static int F_81 ( struct V_64 * V_65 , unsigned V_66 , char * * V_67 )
{
int V_123 = - V_72 ;
struct V_1 * V_2 = V_65 -> V_86 ;
if ( V_66 != 2 ) {
F_82 ( L_21 , V_66 ) ;
return V_123 ;
}
if ( ! strcasecmp ( V_67 [ 0 ] , L_22 ) )
V_123 = F_57 ( V_2 , V_67 [ 1 ] ) ;
else
F_82 ( L_23 , V_67 [ 0 ] ) ;
return V_123 ;
}
static void F_83 ( struct V_64 * V_65 , struct V_124 * V_125 )
{
struct V_1 * V_2 = V_65 -> V_86 ;
struct V_126 * V_127 = F_84 ( V_2 -> V_76 -> V_32 ) ;
if ( ! V_127 || ! F_85 ( V_127 ) ) {
V_2 -> V_79 = false ;
V_125 -> V_128 = 1 << V_43 ;
V_125 -> V_129 = ( V_130 >> V_43 ) ;
}
}
static int T_6 F_86 ( void )
{
int V_123 = F_87 ( & V_131 ) ;
if ( V_123 < 0 )
F_8 ( L_24 , V_123 ) ;
return V_123 ;
}
static void T_7 F_88 ( void )
{
F_89 ( & V_131 ) ;
}
