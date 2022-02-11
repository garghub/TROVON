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
V_25 = F_18 ( V_28 ) ;
if ( ! V_25 ) {
F_8 ( L_3 ) ;
F_13 ( V_6 ) ;
goto error;
}
V_26 = F_19 ( V_25 ) ;
memcpy ( V_26 , V_21 , V_22 ) ;
if ( V_23 )
memcpy ( V_26 + V_22 , V_20 , V_23 ) ;
memset ( V_26 + V_22 + V_23 , 0 ,
V_2 -> V_36 - V_22 - V_23 ) ;
F_20 ( V_26 ) ;
V_27 = F_21 ( V_6 , V_25 , V_2 -> V_36 , 0 ) ;
if ( V_27 != V_2 -> V_36 ) {
F_8 ( L_4 ) ;
goto V_37;
}
F_22 ( V_38 , V_6 ) ;
return 0 ;
V_37:
F_13 ( V_6 ) ;
F_12 ( V_25 ) ;
error:
F_6 ( V_2 ) ;
return - 1 ;
}
static int F_23 ( struct V_1 * V_2 ,
struct V_16 * V_17 , T_2 V_24 )
{
struct V_6 * V_6 ;
struct V_39 V_21 ;
T_1 V_27 ;
int V_10 ;
V_21 . V_24 = F_24 ( V_17 -> V_24 ) ;
V_21 . V_40 = F_24 ( V_17 -> V_40 ) ;
V_21 . V_12 = F_24 ( V_17 -> V_12 ) ;
V_21 . V_41 = F_24 ( V_17 -> V_23 ) ;
if ( F_16 ( V_2 , & V_21 , sizeof( V_21 ) , V_17 -> V_20 ,
V_17 -> V_23 , V_24 ) ) {
F_14 ( V_2 , V_17 ) ;
return - 1 ;
}
if ( ! V_17 -> V_18 )
goto V_42;
V_24 ++ ;
V_6 = F_17 ( V_28 , V_17 -> V_18 ) ;
if ( ! V_6 ) {
F_8 ( L_2 ) ;
goto error;
}
F_25 ( & V_2 -> V_5 ) ;
V_6 -> V_29 . V_30 = 0 ;
V_6 -> V_29 . V_31 = V_24 ;
V_6 -> V_32 = V_2 -> V_33 -> V_34 ;
V_6 -> V_35 = F_7 ;
V_6 -> V_7 = V_2 ;
for ( V_10 = 0 ; V_10 < V_17 -> V_18 ; V_10 ++ ) {
V_27 = F_21 ( V_6 , V_17 -> V_19 [ V_10 ] . V_15 ,
V_17 -> V_19 [ V_10 ] . V_43 , 0 ) ;
if ( V_27 != V_17 -> V_19 [ V_10 ] . V_43 ) {
F_25 ( & V_2 -> V_5 ) ;
F_22 ( V_38 , V_6 ) ;
V_6 = F_17 ( V_28 , V_17 -> V_18 - V_10 ) ;
if ( ! V_6 ) {
F_8 ( L_2 ) ;
goto error;
}
V_6 -> V_29 . V_30 = 0 ;
V_6 -> V_29 . V_31 = V_24 ;
V_6 -> V_32 = V_2 -> V_33 -> V_34 ;
V_6 -> V_35 = F_7 ;
V_6 -> V_7 = V_2 ;
V_27 = F_21 ( V_6 , V_17 -> V_19 [ V_10 ] . V_15 ,
V_17 -> V_19 [ V_10 ] . V_43 , 0 ) ;
if ( V_27 != V_17 -> V_19 [ V_10 ] . V_43 ) {
F_8 ( L_5 ) ;
F_13 ( V_6 ) ;
goto error;
}
}
V_24 += V_17 -> V_19 [ V_10 ] . V_43 >> V_44 ;
}
F_22 ( V_38 , V_6 ) ;
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
static int F_26 ( struct V_1 * V_2 )
{
struct V_45 V_46 ;
V_46 . V_47 = F_24 ( V_48 ) ;
V_46 . V_49 = F_24 ( V_50 ) ;
V_46 . V_51 = F_24 ( V_2 -> V_52 ) ;
V_46 . V_36 = F_27 ( V_2 -> V_36 ) ;
if ( F_16 ( V_2 , & V_46 , sizeof( V_46 ) , NULL , 0 , 0 ) ) {
F_8 ( L_6 ) ;
return - 1 ;
}
return 0 ;
}
static inline T_2 F_28 ( struct V_1 * V_2 )
{
return F_29 ( V_2 -> V_33 -> V_34 -> V_53 ) >> V_44 ;
}
static int F_30 ( void * V_54 )
{
struct V_1 * V_2 = (struct V_1 * ) V_54 ;
T_2 V_24 = 0 ;
while ( ! F_31 () ) {
bool V_46 = false ;
bool V_14 ;
struct V_16 * V_17 = NULL ;
int V_27 ;
F_32 ( & V_2 -> V_13 ) ;
if ( ! F_33 ( & V_2 -> V_55 ) ) {
V_17 = F_34 ( & V_2 -> V_55 ,
struct V_16 , V_56 ) ;
F_35 ( & V_17 -> V_56 ) ;
if ( ! V_2 -> V_14 )
goto V_57;
V_24 = V_2 -> V_58 ;
if ( V_17 -> V_12 & V_59 )
V_2 -> V_58 ++ ;
else
V_2 -> V_58 += V_17 -> V_40 + 1 ;
if ( ! V_2 -> V_60 )
V_2 -> V_60 = F_28 ( V_2 ) ;
if ( V_2 -> V_60 &&
V_2 -> V_58 >= V_2 -> V_60 ) {
F_8 ( L_7 ) ;
V_2 -> V_14 = false ;
goto V_57;
}
V_2 -> V_52 ++ ;
F_25 ( & V_2 -> V_5 ) ;
V_46 = ( V_17 -> V_12 & ( V_61 | V_62 ) ) ;
if ( V_46 )
F_25 ( & V_2 -> V_5 ) ;
}
V_57:
V_14 = V_2 -> V_14 ;
F_36 ( & V_2 -> V_13 ) ;
if ( V_17 ) {
if ( V_14 ) {
V_27 = F_23 ( V_2 , V_17 , V_24 ) ;
if ( ! V_27 && V_46 )
V_27 = F_26 ( V_2 ) ;
if ( V_27 ) {
F_32 ( & V_2 -> V_13 ) ;
V_2 -> V_14 = false ;
F_36 ( & V_2 -> V_13 ) ;
}
} else
F_14 ( V_2 , V_17 ) ;
continue;
}
if ( ! F_37 () ) {
F_38 ( V_63 ) ;
if ( ! F_31 () &&
! F_39 ( & V_2 -> V_3 ) )
F_40 () ;
F_41 ( V_64 ) ;
}
}
return 0 ;
}
static int F_42 ( struct V_65 * V_66 , unsigned int V_67 , char * * V_68 )
{
struct V_1 * V_2 ;
struct V_69 V_70 ;
const char * V_71 , * V_72 ;
int V_27 ;
V_70 . V_67 = V_67 ;
V_70 . V_68 = V_68 ;
if ( V_67 < 2 ) {
V_66 -> error = L_8 ;
return - V_73 ;
}
V_2 = F_43 ( sizeof( struct V_1 ) , V_28 ) ;
if ( ! V_2 ) {
V_66 -> error = L_9 ;
return - V_74 ;
}
F_44 ( & V_2 -> V_13 ) ;
F_45 ( & V_2 -> V_75 ) ;
F_45 ( & V_2 -> V_55 ) ;
F_46 ( & V_2 -> V_4 ) ;
V_2 -> V_36 = 1 << V_44 ;
F_47 ( & V_2 -> V_5 , 0 ) ;
F_47 ( & V_2 -> V_3 , 0 ) ;
V_71 = F_48 ( & V_70 ) ;
V_27 = F_49 ( V_66 , V_71 , F_50 ( V_66 -> V_76 ) , & V_2 -> V_77 ) ;
if ( V_27 ) {
V_66 -> error = L_10 ;
goto V_78;
}
V_72 = F_48 ( & V_70 ) ;
V_27 = F_49 ( V_66 , V_72 , F_50 ( V_66 -> V_76 ) ,
& V_2 -> V_33 ) ;
if ( V_27 ) {
V_66 -> error = L_11 ;
F_51 ( V_66 , V_2 -> V_77 ) ;
goto V_78;
}
V_27 = - V_73 ;
V_2 -> V_79 = F_52 ( F_30 , V_2 , L_12 ) ;
if ( ! V_2 -> V_79 ) {
V_66 -> error = L_13 ;
F_51 ( V_66 , V_2 -> V_77 ) ;
F_51 ( V_66 , V_2 -> V_33 ) ;
goto V_78;
}
V_2 -> V_58 = 1 ;
V_2 -> V_14 = true ;
V_2 -> V_60 = F_28 ( V_2 ) ;
V_2 -> V_80 = true ;
V_66 -> V_81 = 1 ;
V_66 -> V_82 = true ;
V_66 -> V_83 = 1 ;
V_66 -> V_84 = true ;
V_66 -> V_85 = sizeof( struct V_86 ) ;
V_66 -> V_87 = V_2 ;
return 0 ;
V_78:
F_15 ( V_2 ) ;
return V_27 ;
}
static int F_53 ( struct V_1 * V_2 , char * V_20 )
{
struct V_16 * V_17 ;
T_1 V_88 = V_2 -> V_36 - sizeof( struct V_39 ) ;
V_17 = F_43 ( sizeof( struct V_16 ) , V_28 ) ;
if ( ! V_17 ) {
F_8 ( L_14 ) ;
return - V_74 ;
}
V_17 -> V_20 = F_54 ( V_20 , V_88 , V_28 ) ;
if ( ! V_17 -> V_20 ) {
F_8 ( L_15 ) ;
F_15 ( V_17 ) ;
return - V_74 ;
}
F_25 ( & V_2 -> V_3 ) ;
V_17 -> V_23 = strlen ( V_17 -> V_20 ) ;
V_17 -> V_12 |= V_62 ;
F_32 ( & V_2 -> V_13 ) ;
F_55 ( & V_17 -> V_56 , & V_2 -> V_55 ) ;
F_36 ( & V_2 -> V_13 ) ;
F_56 ( V_2 -> V_79 ) ;
return 0 ;
}
static void F_57 ( struct V_65 * V_66 )
{
struct V_1 * V_2 = V_66 -> V_87 ;
F_32 ( & V_2 -> V_13 ) ;
F_58 ( & V_2 -> V_75 , & V_2 -> V_55 ) ;
F_36 ( & V_2 -> V_13 ) ;
F_53 ( V_2 , L_16 ) ;
F_56 ( V_2 -> V_79 ) ;
F_59 ( V_2 -> V_4 , ! F_39 ( & V_2 -> V_5 ) &&
! F_39 ( & V_2 -> V_3 ) ) ;
F_60 ( V_2 -> V_79 ) ;
F_61 ( ! F_33 ( & V_2 -> V_55 ) ) ;
F_61 ( ! F_33 ( & V_2 -> V_75 ) ) ;
F_51 ( V_66 , V_2 -> V_77 ) ;
F_51 ( V_66 , V_2 -> V_33 ) ;
F_15 ( V_2 ) ;
}
static void F_62 ( struct V_65 * V_66 , struct V_6 * V_6 )
{
struct V_1 * V_2 = V_66 -> V_87 ;
V_6 -> V_32 = V_2 -> V_77 -> V_34 ;
}
static int F_63 ( struct V_65 * V_66 , struct V_6 * V_6 )
{
struct V_1 * V_2 = V_66 -> V_87 ;
struct V_86 * V_89 = F_64 ( V_6 , sizeof( struct V_86 ) ) ;
struct V_16 * V_17 ;
struct V_90 V_91 ;
struct V_8 V_92 ;
T_1 V_93 ;
int V_10 = 0 ;
bool V_94 = ( V_6 -> V_95 & V_96 ) ;
bool V_97 = ( V_6 -> V_95 & V_98 ) ;
bool V_99 = ( V_6 -> V_95 & V_100 ) ;
V_89 -> V_17 = NULL ;
if ( ! V_2 -> V_14 )
goto V_101;
if ( F_65 ( V_6 ) == V_102 )
goto V_101;
if ( ! F_66 ( V_6 ) && ! V_94 )
goto V_101;
if ( V_99 )
V_93 = sizeof( struct V_16 ) ;
else
V_93 = sizeof( struct V_16 ) + sizeof( struct V_8 ) * F_67 ( V_6 ) ;
V_17 = F_43 ( V_93 , V_103 ) ;
if ( ! V_17 ) {
F_8 ( L_14 ) ;
F_32 ( & V_2 -> V_13 ) ;
V_2 -> V_14 = false ;
F_36 ( & V_2 -> V_13 ) ;
return - V_74 ;
}
F_45 ( & V_17 -> V_56 ) ;
V_89 -> V_17 = V_17 ;
F_25 ( & V_2 -> V_3 ) ;
if ( V_94 )
V_17 -> V_12 |= V_104 ;
if ( V_97 )
V_17 -> V_12 |= V_61 ;
if ( V_99 )
V_17 -> V_12 |= V_59 ;
V_17 -> V_24 = V_6 -> V_29 . V_31 ;
V_17 -> V_40 = F_66 ( V_6 ) ;
if ( V_99 ) {
F_61 ( V_94 || V_97 ) ;
if ( V_2 -> V_80 )
goto V_101;
F_68 ( V_6 ) ;
return V_105 ;
}
if ( V_94 && ! F_66 ( V_6 ) ) {
F_32 ( & V_2 -> V_13 ) ;
F_58 ( & V_2 -> V_75 , & V_17 -> V_56 ) ;
F_36 ( & V_2 -> V_13 ) ;
goto V_101;
}
F_69 (bv, bio, iter) {
struct V_25 * V_25 ;
void * V_106 , * V_107 ;
V_25 = F_18 ( V_103 ) ;
if ( ! V_25 ) {
F_8 ( L_17 ) ;
F_14 ( V_2 , V_17 ) ;
F_32 ( & V_2 -> V_13 ) ;
V_2 -> V_14 = false ;
F_36 ( & V_2 -> V_13 ) ;
return - V_74 ;
}
V_106 = F_19 ( V_92 . V_15 ) ;
V_107 = F_19 ( V_25 ) ;
memcpy ( V_107 , V_106 + V_92 . V_108 , V_92 . V_43 ) ;
F_20 ( V_107 ) ;
F_20 ( V_106 ) ;
V_17 -> V_19 [ V_10 ] . V_15 = V_25 ;
V_17 -> V_19 [ V_10 ] . V_43 = V_92 . V_43 ;
V_17 -> V_18 ++ ;
V_10 ++ ;
}
if ( V_94 ) {
F_32 ( & V_2 -> V_13 ) ;
F_58 ( & V_2 -> V_75 , & V_17 -> V_56 ) ;
F_36 ( & V_2 -> V_13 ) ;
}
V_101:
F_62 ( V_66 , V_6 ) ;
return V_109 ;
}
static int F_70 ( struct V_65 * V_66 , struct V_6 * V_6 , int error )
{
struct V_1 * V_2 = V_66 -> V_87 ;
struct V_86 * V_89 = F_64 ( V_6 , sizeof( struct V_86 ) ) ;
if ( F_65 ( V_6 ) == V_38 && V_89 -> V_17 ) {
struct V_16 * V_17 = V_89 -> V_17 ;
unsigned long V_12 ;
F_9 ( & V_2 -> V_13 , V_12 ) ;
if ( V_17 -> V_12 & V_104 ) {
F_71 ( & V_17 -> V_56 , & V_2 -> V_55 ) ;
F_55 ( & V_17 -> V_56 , & V_2 -> V_55 ) ;
F_56 ( V_2 -> V_79 ) ;
} else if ( V_17 -> V_12 & V_61 ) {
F_55 ( & V_17 -> V_56 , & V_2 -> V_55 ) ;
F_56 ( V_2 -> V_79 ) ;
} else
F_55 ( & V_17 -> V_56 , & V_2 -> V_75 ) ;
F_10 ( & V_2 -> V_13 , V_12 ) ;
}
return error ;
}
static void F_72 ( struct V_65 * V_66 , T_3 type ,
unsigned V_110 , char * V_111 ,
unsigned V_112 )
{
unsigned V_113 = 0 ;
struct V_1 * V_2 = V_66 -> V_87 ;
switch ( type ) {
case V_114 :
F_73 ( L_18 , V_2 -> V_52 ,
( unsigned long long ) V_2 -> V_58 - 1 ) ;
if ( ! V_2 -> V_14 )
F_73 ( L_19 ) ;
break;
case V_115 :
F_73 ( L_20 , V_2 -> V_77 -> V_116 , V_2 -> V_33 -> V_116 ) ;
break;
}
}
static int F_74 ( struct V_65 * V_66 , unsigned int V_117 ,
unsigned long V_54 )
{
struct V_1 * V_2 = V_66 -> V_87 ;
struct V_118 * V_77 = V_2 -> V_77 ;
int V_119 = 0 ;
if ( V_66 -> V_120 != F_29 ( V_77 -> V_34 -> V_53 ) >> V_44 )
V_119 = F_75 ( NULL , V_117 ) ;
return V_119 ? : F_76 ( V_77 -> V_34 , V_77 -> V_121 , V_117 , V_54 ) ;
}
static int F_77 ( struct V_65 * V_66 ,
T_4 V_122 ,
void * V_20 )
{
struct V_1 * V_2 = V_66 -> V_87 ;
return V_122 ( V_66 , V_2 -> V_77 , 0 , V_66 -> V_120 , V_20 ) ;
}
static int F_78 ( struct V_65 * V_66 , unsigned V_67 , char * * V_68 )
{
int V_119 = - V_73 ;
struct V_1 * V_2 = V_66 -> V_87 ;
if ( V_67 != 2 ) {
F_79 ( L_21 , V_67 ) ;
return V_119 ;
}
if ( ! strcasecmp ( V_68 [ 0 ] , L_22 ) )
V_119 = F_53 ( V_2 , V_68 [ 1 ] ) ;
else
F_79 ( L_23 , V_68 [ 0 ] ) ;
return V_119 ;
}
static void F_80 ( struct V_65 * V_66 , struct V_123 * V_124 )
{
struct V_1 * V_2 = V_66 -> V_87 ;
struct V_125 * V_126 = F_81 ( V_2 -> V_77 -> V_34 ) ;
if ( ! V_126 || ! F_82 ( V_126 ) ) {
V_2 -> V_80 = false ;
V_124 -> V_127 = 1 << V_44 ;
V_124 -> V_128 = ( V_129 >> V_44 ) ;
}
}
static int T_5 F_83 ( void )
{
int V_119 = F_84 ( & V_130 ) ;
if ( V_119 < 0 )
F_8 ( L_24 , V_119 ) ;
return V_119 ;
}
static void T_6 F_85 ( void )
{
F_86 ( & V_130 ) ;
}
