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
struct V_8 * V_9 ;
int V_10 ;
if ( V_6 -> V_11 ) {
unsigned long V_12 ;
F_8 ( L_1 , V_6 -> V_11 ) ;
F_9 ( & V_2 -> V_13 , V_12 ) ;
V_2 -> V_14 = false ;
F_10 ( & V_2 -> V_13 , V_12 ) ;
}
F_11 (bvec, bio, i)
F_12 ( V_9 -> V_15 ) ;
F_6 ( V_2 ) ;
F_13 ( V_6 ) ;
}
static void F_14 ( struct V_1 * V_2 ,
struct V_16 * V_17 )
{
int V_10 ;
for ( V_10 = 0 ; V_10 < V_17 -> V_18 ; V_10 ++ ) {
if ( V_17 -> V_19 [ V_10 ] . V_15 )
F_12 ( V_17 -> V_19 [ V_10 ] . V_15 ) ;
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
V_6 -> V_7 = V_2 ;
F_18 ( V_6 , V_36 , 0 ) ;
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
V_2 -> V_37 - V_22 - V_23 ) ;
F_21 ( V_26 ) ;
V_27 = F_22 ( V_6 , V_25 , V_2 -> V_37 , 0 ) ;
if ( V_27 != V_2 -> V_37 ) {
F_8 ( L_4 ) ;
goto V_38;
}
F_23 ( V_6 ) ;
return 0 ;
V_38:
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
struct V_39 V_21 ;
T_1 V_27 ;
int V_10 ;
V_21 . V_24 = F_25 ( V_17 -> V_24 ) ;
V_21 . V_40 = F_25 ( V_17 -> V_40 ) ;
V_21 . V_12 = F_25 ( V_17 -> V_12 ) ;
V_21 . V_41 = F_25 ( V_17 -> V_23 ) ;
if ( F_16 ( V_2 , & V_21 , sizeof( V_21 ) , V_17 -> V_20 ,
V_17 -> V_23 , V_24 ) ) {
F_14 ( V_2 , V_17 ) ;
return - 1 ;
}
if ( ! V_17 -> V_18 )
goto V_42;
V_24 ++ ;
F_26 ( & V_2 -> V_5 ) ;
V_6 = F_17 ( V_28 , F_27 ( V_17 -> V_18 , V_43 ) ) ;
if ( ! V_6 ) {
F_8 ( L_2 ) ;
goto error;
}
V_6 -> V_29 . V_30 = 0 ;
V_6 -> V_29 . V_31 = V_24 ;
V_6 -> V_32 = V_2 -> V_33 -> V_34 ;
V_6 -> V_35 = F_7 ;
V_6 -> V_7 = V_2 ;
F_18 ( V_6 , V_36 , 0 ) ;
for ( V_10 = 0 ; V_10 < V_17 -> V_18 ; V_10 ++ ) {
V_27 = F_22 ( V_6 , V_17 -> V_19 [ V_10 ] . V_15 ,
V_17 -> V_19 [ V_10 ] . V_44 , 0 ) ;
if ( V_27 != V_17 -> V_19 [ V_10 ] . V_44 ) {
F_26 ( & V_2 -> V_5 ) ;
F_23 ( V_6 ) ;
V_6 = F_17 ( V_28 , F_27 ( V_17 -> V_18 - V_10 , V_43 ) ) ;
if ( ! V_6 ) {
F_8 ( L_2 ) ;
goto error;
}
V_6 -> V_29 . V_30 = 0 ;
V_6 -> V_29 . V_31 = V_24 ;
V_6 -> V_32 = V_2 -> V_33 -> V_34 ;
V_6 -> V_35 = F_7 ;
V_6 -> V_7 = V_2 ;
F_18 ( V_6 , V_36 , 0 ) ;
V_27 = F_22 ( V_6 , V_17 -> V_19 [ V_10 ] . V_15 ,
V_17 -> V_19 [ V_10 ] . V_44 , 0 ) ;
if ( V_27 != V_17 -> V_19 [ V_10 ] . V_44 ) {
F_8 ( L_5 ) ;
F_13 ( V_6 ) ;
goto error;
}
}
V_24 += V_17 -> V_19 [ V_10 ] . V_44 >> V_45 ;
}
F_23 ( V_6 ) ;
V_42:
F_15 ( V_17 -> V_20 ) ;
F_15 ( V_17 ) ;
F_1 ( V_2 ) ;
return 0 ;
error:
F_14 ( V_2 , V_17 ) ;
F_6 ( V_2 ) ;
return - 1 ;
}
static int F_28 ( struct V_1 * V_2 )
{
struct V_46 V_47 ;
V_47 . V_48 = F_25 ( V_49 ) ;
V_47 . V_50 = F_25 ( V_51 ) ;
V_47 . V_52 = F_25 ( V_2 -> V_53 ) ;
V_47 . V_37 = F_29 ( V_2 -> V_37 ) ;
if ( F_16 ( V_2 , & V_47 , sizeof( V_47 ) , NULL , 0 , 0 ) ) {
F_8 ( L_6 ) ;
return - 1 ;
}
return 0 ;
}
static inline T_2 F_30 ( struct V_1 * V_2 )
{
return F_31 ( V_2 -> V_33 -> V_34 -> V_54 ) >> V_45 ;
}
static int F_32 ( void * V_55 )
{
struct V_1 * V_2 = (struct V_1 * ) V_55 ;
T_2 V_24 = 0 ;
while ( ! F_33 () ) {
bool V_47 = false ;
bool V_14 ;
struct V_16 * V_17 = NULL ;
int V_27 ;
F_34 ( & V_2 -> V_13 ) ;
if ( ! F_35 ( & V_2 -> V_56 ) ) {
V_17 = F_36 ( & V_2 -> V_56 ,
struct V_16 , V_57 ) ;
F_37 ( & V_17 -> V_57 ) ;
if ( ! V_2 -> V_14 )
goto V_58;
V_24 = V_2 -> V_59 ;
if ( V_17 -> V_12 & V_60 )
V_2 -> V_59 ++ ;
else
V_2 -> V_59 += V_17 -> V_40 + 1 ;
if ( ! V_2 -> V_61 )
V_2 -> V_61 = F_30 ( V_2 ) ;
if ( V_2 -> V_61 &&
V_2 -> V_59 >= V_2 -> V_61 ) {
F_8 ( L_7 ) ;
V_2 -> V_14 = false ;
goto V_58;
}
V_2 -> V_53 ++ ;
F_26 ( & V_2 -> V_5 ) ;
V_47 = ( V_17 -> V_12 & ( V_62 | V_63 ) ) ;
if ( V_47 )
F_26 ( & V_2 -> V_5 ) ;
}
V_58:
V_14 = V_2 -> V_14 ;
F_38 ( & V_2 -> V_13 ) ;
if ( V_17 ) {
if ( V_14 ) {
V_27 = F_24 ( V_2 , V_17 , V_24 ) ;
if ( ! V_27 && V_47 )
V_27 = F_28 ( V_2 ) ;
if ( V_27 ) {
F_34 ( & V_2 -> V_13 ) ;
V_2 -> V_14 = false ;
F_38 ( & V_2 -> V_13 ) ;
}
} else
F_14 ( V_2 , V_17 ) ;
continue;
}
if ( ! F_39 () ) {
F_40 ( V_64 ) ;
if ( ! F_33 () &&
! F_41 ( & V_2 -> V_3 ) )
F_42 () ;
F_43 ( V_65 ) ;
}
}
return 0 ;
}
static int F_44 ( struct V_66 * V_67 , unsigned int V_68 , char * * V_69 )
{
struct V_1 * V_2 ;
struct V_70 V_71 ;
const char * V_72 , * V_73 ;
int V_27 ;
V_71 . V_68 = V_68 ;
V_71 . V_69 = V_69 ;
if ( V_68 < 2 ) {
V_67 -> error = L_8 ;
return - V_74 ;
}
V_2 = F_45 ( sizeof( struct V_1 ) , V_28 ) ;
if ( ! V_2 ) {
V_67 -> error = L_9 ;
return - V_75 ;
}
F_46 ( & V_2 -> V_13 ) ;
F_47 ( & V_2 -> V_76 ) ;
F_47 ( & V_2 -> V_56 ) ;
F_48 ( & V_2 -> V_4 ) ;
V_2 -> V_37 = 1 << V_45 ;
F_49 ( & V_2 -> V_5 , 0 ) ;
F_49 ( & V_2 -> V_3 , 0 ) ;
V_72 = F_50 ( & V_71 ) ;
V_27 = F_51 ( V_67 , V_72 , F_52 ( V_67 -> V_77 ) , & V_2 -> V_78 ) ;
if ( V_27 ) {
V_67 -> error = L_10 ;
goto V_79;
}
V_73 = F_50 ( & V_71 ) ;
V_27 = F_51 ( V_67 , V_73 , F_52 ( V_67 -> V_77 ) ,
& V_2 -> V_33 ) ;
if ( V_27 ) {
V_67 -> error = L_11 ;
F_53 ( V_67 , V_2 -> V_78 ) ;
goto V_79;
}
V_2 -> V_80 = F_54 ( F_32 , V_2 , L_12 ) ;
if ( F_55 ( V_2 -> V_80 ) ) {
V_27 = F_56 ( V_2 -> V_80 ) ;
V_67 -> error = L_13 ;
F_53 ( V_67 , V_2 -> V_78 ) ;
F_53 ( V_67 , V_2 -> V_33 ) ;
goto V_79;
}
V_2 -> V_59 = 1 ;
V_2 -> V_14 = true ;
V_2 -> V_61 = F_30 ( V_2 ) ;
V_2 -> V_81 = true ;
V_67 -> V_82 = 1 ;
V_67 -> V_83 = true ;
V_67 -> V_84 = 1 ;
V_67 -> V_85 = true ;
V_67 -> V_86 = sizeof( struct V_87 ) ;
V_67 -> V_88 = V_2 ;
return 0 ;
V_79:
F_15 ( V_2 ) ;
return V_27 ;
}
static int F_57 ( struct V_1 * V_2 , char * V_20 )
{
struct V_16 * V_17 ;
T_1 V_89 = V_2 -> V_37 - sizeof( struct V_39 ) ;
V_17 = F_45 ( sizeof( struct V_16 ) , V_28 ) ;
if ( ! V_17 ) {
F_8 ( L_14 ) ;
return - V_75 ;
}
V_17 -> V_20 = F_58 ( V_20 , V_89 , V_28 ) ;
if ( ! V_17 -> V_20 ) {
F_8 ( L_15 ) ;
F_15 ( V_17 ) ;
return - V_75 ;
}
F_26 ( & V_2 -> V_3 ) ;
V_17 -> V_23 = strlen ( V_17 -> V_20 ) ;
V_17 -> V_12 |= V_63 ;
F_34 ( & V_2 -> V_13 ) ;
F_59 ( & V_17 -> V_57 , & V_2 -> V_56 ) ;
F_38 ( & V_2 -> V_13 ) ;
F_60 ( V_2 -> V_80 ) ;
return 0 ;
}
static void F_61 ( struct V_66 * V_67 )
{
struct V_1 * V_2 = V_67 -> V_88 ;
F_34 ( & V_2 -> V_13 ) ;
F_62 ( & V_2 -> V_76 , & V_2 -> V_56 ) ;
F_38 ( & V_2 -> V_13 ) ;
F_57 ( V_2 , L_16 ) ;
F_60 ( V_2 -> V_80 ) ;
F_63 ( V_2 -> V_4 , ! F_41 ( & V_2 -> V_5 ) &&
! F_41 ( & V_2 -> V_3 ) ) ;
F_64 ( V_2 -> V_80 ) ;
F_65 ( ! F_35 ( & V_2 -> V_56 ) ) ;
F_65 ( ! F_35 ( & V_2 -> V_76 ) ) ;
F_53 ( V_67 , V_2 -> V_78 ) ;
F_53 ( V_67 , V_2 -> V_33 ) ;
F_15 ( V_2 ) ;
}
static void F_66 ( struct V_66 * V_67 , struct V_6 * V_6 )
{
struct V_1 * V_2 = V_67 -> V_88 ;
V_6 -> V_32 = V_2 -> V_78 -> V_34 ;
}
static int F_67 ( struct V_66 * V_67 , struct V_6 * V_6 )
{
struct V_1 * V_2 = V_67 -> V_88 ;
struct V_87 * V_90 = F_68 ( V_6 , sizeof( struct V_87 ) ) ;
struct V_16 * V_17 ;
struct V_91 V_92 ;
struct V_8 V_93 ;
T_1 V_94 ;
int V_10 = 0 ;
bool V_95 = ( V_6 -> V_96 & V_97 ) ;
bool V_98 = ( V_6 -> V_96 & V_99 ) ;
bool V_100 = ( F_69 ( V_6 ) == V_101 ) ;
V_90 -> V_17 = NULL ;
if ( ! V_2 -> V_14 )
goto V_102;
if ( F_70 ( V_6 ) == V_103 )
goto V_102;
if ( ! F_71 ( V_6 ) && ! V_95 )
goto V_102;
if ( V_100 )
V_94 = sizeof( struct V_16 ) ;
else
V_94 = sizeof( struct V_16 ) + sizeof( struct V_8 ) * F_72 ( V_6 ) ;
V_17 = F_45 ( V_94 , V_104 ) ;
if ( ! V_17 ) {
F_8 ( L_14 ) ;
F_34 ( & V_2 -> V_13 ) ;
V_2 -> V_14 = false ;
F_38 ( & V_2 -> V_13 ) ;
return - V_75 ;
}
F_47 ( & V_17 -> V_57 ) ;
V_90 -> V_17 = V_17 ;
F_26 ( & V_2 -> V_3 ) ;
if ( V_95 )
V_17 -> V_12 |= V_105 ;
if ( V_98 )
V_17 -> V_12 |= V_62 ;
if ( V_100 )
V_17 -> V_12 |= V_60 ;
V_17 -> V_24 = V_6 -> V_29 . V_31 ;
V_17 -> V_40 = F_71 ( V_6 ) ;
if ( V_100 ) {
F_65 ( V_95 || V_98 ) ;
if ( V_2 -> V_81 )
goto V_102;
F_73 ( V_6 ) ;
return V_106 ;
}
if ( V_95 && ! F_71 ( V_6 ) ) {
F_34 ( & V_2 -> V_13 ) ;
F_62 ( & V_2 -> V_76 , & V_17 -> V_57 ) ;
F_38 ( & V_2 -> V_13 ) ;
goto V_102;
}
F_74 (bv, bio, iter) {
struct V_25 * V_25 ;
void * V_107 , * V_108 ;
V_25 = F_19 ( V_104 ) ;
if ( ! V_25 ) {
F_8 ( L_17 ) ;
F_14 ( V_2 , V_17 ) ;
F_34 ( & V_2 -> V_13 ) ;
V_2 -> V_14 = false ;
F_38 ( & V_2 -> V_13 ) ;
return - V_75 ;
}
V_107 = F_20 ( V_93 . V_15 ) ;
V_108 = F_20 ( V_25 ) ;
memcpy ( V_108 , V_107 + V_93 . V_109 , V_93 . V_44 ) ;
F_21 ( V_108 ) ;
F_21 ( V_107 ) ;
V_17 -> V_19 [ V_10 ] . V_15 = V_25 ;
V_17 -> V_19 [ V_10 ] . V_44 = V_93 . V_44 ;
V_17 -> V_18 ++ ;
V_10 ++ ;
}
if ( V_95 ) {
F_34 ( & V_2 -> V_13 ) ;
F_62 ( & V_2 -> V_76 , & V_17 -> V_57 ) ;
F_38 ( & V_2 -> V_13 ) ;
}
V_102:
F_66 ( V_67 , V_6 ) ;
return V_110 ;
}
static int F_75 ( struct V_66 * V_67 , struct V_6 * V_6 , int error )
{
struct V_1 * V_2 = V_67 -> V_88 ;
struct V_87 * V_90 = F_68 ( V_6 , sizeof( struct V_87 ) ) ;
if ( F_70 ( V_6 ) == V_111 && V_90 -> V_17 ) {
struct V_16 * V_17 = V_90 -> V_17 ;
unsigned long V_12 ;
F_9 ( & V_2 -> V_13 , V_12 ) ;
if ( V_17 -> V_12 & V_105 ) {
F_76 ( & V_17 -> V_57 , & V_2 -> V_56 ) ;
F_59 ( & V_17 -> V_57 , & V_2 -> V_56 ) ;
F_60 ( V_2 -> V_80 ) ;
} else if ( V_17 -> V_12 & V_62 ) {
F_59 ( & V_17 -> V_57 , & V_2 -> V_56 ) ;
F_60 ( V_2 -> V_80 ) ;
} else
F_59 ( & V_17 -> V_57 , & V_2 -> V_76 ) ;
F_10 ( & V_2 -> V_13 , V_12 ) ;
}
return error ;
}
static void F_77 ( struct V_66 * V_67 , T_3 type ,
unsigned V_112 , char * V_113 ,
unsigned V_114 )
{
unsigned V_115 = 0 ;
struct V_1 * V_2 = V_67 -> V_88 ;
switch ( type ) {
case V_116 :
F_78 ( L_18 , V_2 -> V_53 ,
( unsigned long long ) V_2 -> V_59 - 1 ) ;
if ( ! V_2 -> V_14 )
F_78 ( L_19 ) ;
break;
case V_117 :
F_78 ( L_20 , V_2 -> V_78 -> V_118 , V_2 -> V_33 -> V_118 ) ;
break;
}
}
static int F_79 ( struct V_66 * V_67 ,
struct V_119 * * V_34 , T_4 * V_120 )
{
struct V_1 * V_2 = V_67 -> V_88 ;
struct V_121 * V_78 = V_2 -> V_78 ;
* V_34 = V_78 -> V_34 ;
if ( V_67 -> V_122 != F_31 ( V_78 -> V_34 -> V_54 ) >> V_45 )
return 1 ;
return 0 ;
}
static int F_80 ( struct V_66 * V_67 ,
T_5 V_123 ,
void * V_20 )
{
struct V_1 * V_2 = V_67 -> V_88 ;
return V_123 ( V_67 , V_2 -> V_78 , 0 , V_67 -> V_122 , V_20 ) ;
}
static int F_81 ( struct V_66 * V_67 , unsigned V_68 , char * * V_69 )
{
int V_124 = - V_74 ;
struct V_1 * V_2 = V_67 -> V_88 ;
if ( V_68 != 2 ) {
F_82 ( L_21 , V_68 ) ;
return V_124 ;
}
if ( ! strcasecmp ( V_69 [ 0 ] , L_22 ) )
V_124 = F_57 ( V_2 , V_69 [ 1 ] ) ;
else
F_82 ( L_23 , V_69 [ 0 ] ) ;
return V_124 ;
}
static void F_83 ( struct V_66 * V_67 , struct V_125 * V_126 )
{
struct V_1 * V_2 = V_67 -> V_88 ;
struct V_127 * V_128 = F_84 ( V_2 -> V_78 -> V_34 ) ;
if ( ! V_128 || ! F_85 ( V_128 ) ) {
V_2 -> V_81 = false ;
V_126 -> V_129 = 1 << V_45 ;
V_126 -> V_130 = ( V_131 >> V_45 ) ;
}
}
static int T_6 F_86 ( void )
{
int V_124 = F_87 ( & V_132 ) ;
if ( V_124 < 0 )
F_8 ( L_24 , V_124 ) ;
return V_124 ;
}
static void T_7 F_88 ( void )
{
F_89 ( & V_132 ) ;
}
