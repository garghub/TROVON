static void F_1 ( struct V_1 * V_2 , unsigned char V_3 ) {}
static unsigned char F_2 ( struct V_1 * V_2 ) { return 0 ; }
static unsigned char F_3 ( struct V_1 * V_2 , unsigned char V_3 ,
unsigned char V_4 ) { return 0 ; }
static void F_4 ( struct V_1 * V_2 ) {}
static void F_5 ( struct V_5 * V_6 , struct V_7 * V_8 ) { }
static void F_6 ( struct V_1 * V_2 , struct V_7 * V_8 ) { }
static T_1 F_7 ( struct V_1 * V_2 , const void * V_3 , T_1 V_9 , int V_10 )
{ return 0 ; }
static T_1 F_8 ( struct V_1 * V_2 , void * V_3 , T_1 V_9 , int V_10 )
{ return 0 ; }
static int F_9 ( struct V_11 * V_12 )
{
return V_12 -> type == & V_13 ;
}
static int F_10 ( struct V_11 * V_12 )
{
struct V_14 * V_15 ;
if ( F_9 ( V_12 ) )
return - V_16 ;
V_15 = F_11 ( V_12 -> V_17 ) ;
if ( ! V_15 -> V_18 ) {
struct V_5 * V_19 = F_12 ( V_12 ) ;
if ( strcmp ( V_19 -> V_20 , V_15 -> V_20 ) )
return - V_16 ;
return 0 ;
}
return V_15 -> V_18 ( F_12 ( V_12 ) ) ;
}
int F_13 ( void )
{
return F_14 ( & V_21 ) ;
}
void F_15 ( void )
{
F_16 ( & V_21 ) ;
}
static int F_17 ( struct V_22 * V_23 , void * V_24 )
{
struct V_1 * V_25 = V_24 ;
struct V_14 * V_15 = F_11 ( V_23 ) ;
if ( V_15 -> V_26 )
V_15 -> V_26 ( V_25 ) ;
return 0 ;
}
static void F_18 ( struct V_1 * V_25 )
{
struct V_14 * V_15 ;
F_19 (drv, &drivers, list)
V_15 -> V_27 ( V_25 ) ;
F_20 ( & V_21 , NULL , V_25 , F_17 ) ;
}
static int F_21 ( struct V_22 * V_28 , void * V_24 )
{
struct V_1 * V_25 = V_24 ;
struct V_14 * V_15 = F_11 ( V_28 ) ;
if ( V_15 -> V_29 )
V_15 -> V_29 ( V_25 ) ;
return 0 ;
}
static void F_22 ( struct V_1 * V_25 )
{
struct V_14 * V_15 ;
F_19 (drv, &drivers, list)
V_15 -> V_29 ( V_25 ) ;
F_20 ( & V_21 , NULL , V_25 , F_21 ) ;
}
static void F_23 ( void )
{
F_24 ( L_1 ) ;
}
static int F_25 ( struct V_11 * V_12 , void * V_23 )
{
struct V_14 * V_15 = V_23 ;
if ( F_9 ( V_12 ) )
V_15 -> V_26 ( F_26 ( V_12 ) ) ;
return 0 ;
}
int F_27 ( struct V_14 * V_15 , struct V_30 * V_31 ,
const char * V_32 )
{
if ( F_28 ( & V_33 ) )
F_23 () ;
if ( V_15 -> V_34 ) {
int V_35 ;
V_15 -> V_17 . V_20 = V_15 -> V_20 ;
V_15 -> V_17 . V_36 = & V_21 ;
V_15 -> V_17 . V_31 = V_31 ;
V_15 -> V_17 . V_32 = V_32 ;
V_35 = F_29 ( & V_15 -> V_17 ) ;
if ( V_35 )
return V_35 ;
F_30 ( & V_37 ) ;
if ( V_15 -> V_26 )
F_31 ( & V_21 , NULL , V_15 ,
F_25 ) ;
F_32 ( & V_37 ) ;
} else {
struct V_1 * V_25 ;
V_15 -> V_34 = false ;
F_30 ( & V_37 ) ;
F_19 (port, &portlist, list)
V_15 -> V_27 ( V_25 ) ;
F_33 ( & V_15 -> V_38 , & V_39 ) ;
F_32 ( & V_37 ) ;
}
return 0 ;
}
static int F_34 ( struct V_11 * V_12 , void * V_28 )
{
struct V_14 * V_15 = V_28 ;
if ( F_9 ( V_12 ) && V_15 -> V_29 )
V_15 -> V_29 ( F_26 ( V_12 ) ) ;
return 0 ;
}
void F_35 ( struct V_14 * V_15 )
{
struct V_1 * V_25 ;
F_30 ( & V_37 ) ;
if ( V_15 -> V_34 ) {
F_31 ( & V_21 , NULL , V_15 , F_34 ) ;
F_36 ( & V_15 -> V_17 ) ;
} else {
F_37 ( & V_15 -> V_38 ) ;
F_19 (port, &portlist, list)
V_15 -> V_29 ( V_25 ) ;
}
F_32 ( & V_37 ) ;
}
static void F_38 ( struct V_11 * V_12 )
{
int V_6 ;
struct V_1 * V_25 = F_26 ( V_12 ) ;
F_39 ( & V_40 ) ;
F_40 ( & V_25 -> V_41 ) ;
F_41 ( & V_40 ) ;
for ( V_6 = 0 ; V_6 < 5 ; V_6 ++ ) {
F_42 ( V_25 -> V_42 [ V_6 ] . V_43 ) ;
F_42 ( V_25 -> V_42 [ V_6 ] . V_44 ) ;
F_42 ( V_25 -> V_42 [ V_6 ] . V_45 ) ;
F_42 ( V_25 -> V_42 [ V_6 ] . V_46 ) ;
F_42 ( V_25 -> V_42 [ V_6 ] . V_47 ) ;
}
F_42 ( V_25 -> V_20 ) ;
F_42 ( V_25 ) ;
}
struct V_1 * F_43 ( struct V_1 * V_25 )
{
struct V_11 * V_12 = F_44 ( & V_25 -> V_48 ) ;
return F_26 ( V_12 ) ;
}
void F_45 ( struct V_1 * V_25 )
{
F_46 ( & V_25 -> V_48 ) ;
}
void F_47 ( struct V_1 * V_25 )
{
F_48 ( & V_25 -> V_48 ) ;
}
struct V_1 * F_49 ( unsigned long V_49 , int V_50 , int V_51 ,
struct V_52 * V_53 )
{
struct V_54 * V_9 ;
struct V_1 * V_55 ;
int V_56 ;
int V_11 ;
char * V_20 ;
int V_35 ;
V_55 = F_50 ( sizeof( struct V_1 ) , V_57 ) ;
if ( ! V_55 )
return NULL ;
V_55 -> V_49 = V_49 ;
V_55 -> V_50 = V_50 ;
V_55 -> V_51 = V_51 ;
V_55 -> V_58 = V_55 -> V_59 = V_55 -> V_60 = - 1 ;
V_55 -> V_61 = 0 ;
F_51 ( & V_55 -> V_38 ) ;
V_55 -> V_62 = V_55 -> V_63 = NULL ;
V_55 -> V_64 = 0 ;
V_55 -> V_53 = V_53 ;
V_55 -> V_65 = V_55 ;
memset ( V_55 -> V_42 , 0 , 5 * sizeof( struct V_66 ) ) ;
F_52 ( & V_55 -> V_67 ) ;
F_53 ( & V_55 -> V_68 ) ;
F_53 ( & V_55 -> V_69 ) ;
V_55 -> V_70 . V_71 = V_72 ;
V_55 -> V_70 . V_73 = V_74 ;
F_54 ( & V_55 -> V_70 . V_50 , 0 ) ;
V_55 -> V_75 = V_76 ;
F_55 ( & V_55 -> V_77 , 1 ) ;
F_51 ( & V_55 -> V_41 ) ;
V_20 = F_56 ( 15 , V_57 ) ;
if ( ! V_20 ) {
F_42 ( V_55 ) ;
return NULL ;
}
F_39 ( & V_40 ) ;
for ( V_9 = V_78 . V_79 , V_56 = 0 ; V_9 != & V_78 ; V_9 = V_9 -> V_79 , V_56 ++ ) {
struct V_1 * V_2 = F_57 ( V_9 , struct V_1 , V_41 ) ;
if ( V_2 -> V_80 != V_56 )
break;
}
V_55 -> V_81 = V_55 -> V_80 = V_56 ;
F_58 ( & V_55 -> V_41 , V_9 ) ;
F_41 ( & V_40 ) ;
sprintf ( V_20 , L_2 , V_55 -> V_81 = V_55 -> V_80 ) ;
V_55 -> V_20 = V_20 ;
V_55 -> V_48 . V_36 = & V_21 ;
V_55 -> V_48 . V_82 = F_38 ;
F_59 ( & V_55 -> V_48 , V_20 ) ;
V_55 -> V_48 . type = & V_13 ;
for ( V_11 = 0 ; V_11 < 5 ; V_11 ++ )
V_55 -> V_42 [ V_11 ] . V_83 = V_84 ;
V_55 -> V_85 = V_55 -> V_86 = NULL ;
V_35 = F_60 ( & V_55 -> V_48 ) ;
if ( V_35 ) {
F_48 ( & V_55 -> V_48 ) ;
return NULL ;
}
return V_55 ;
}
void F_61 ( struct V_1 * V_25 )
{
int V_87 ;
#ifdef F_62
F_63 ( V_25 ) ;
#endif
if ( ! V_25 -> V_12 )
F_64 ( V_88 L_3 ,
V_25 -> V_20 ) ;
F_65 ( V_25 ) ;
F_30 ( & V_37 ) ;
F_66 ( & V_89 ) ;
F_58 ( & V_25 -> V_38 , & V_33 ) ;
for ( V_87 = 1 ; V_87 < 3 ; V_87 ++ ) {
struct V_1 * V_90 = V_25 -> V_91 [ V_87 - 1 ] ;
if ( V_90 )
F_58 ( & V_90 -> V_38 , & V_33 ) ;
}
F_67 ( & V_89 ) ;
F_18 ( V_25 ) ;
for ( V_87 = 1 ; V_87 < 3 ; V_87 ++ ) {
struct V_1 * V_90 = V_25 -> V_91 [ V_87 - 1 ] ;
if ( V_90 )
F_18 ( V_90 ) ;
}
F_32 ( & V_37 ) ;
}
void F_68 ( struct V_1 * V_25 )
{
int V_87 ;
F_30 ( & V_37 ) ;
F_22 ( V_25 ) ;
#ifdef F_62
F_69 ( V_25 ) ;
for ( V_87 = 1 ; V_87 < 3 ; V_87 ++ ) {
struct V_1 * V_90 = V_25 -> V_91 [ V_87 - 1 ] ;
if ( ! V_90 )
continue;
F_22 ( V_90 ) ;
F_69 ( V_90 ) ;
}
#endif
V_25 -> V_53 = & V_92 ;
F_39 ( & V_89 ) ;
F_37 ( & V_25 -> V_38 ) ;
for ( V_87 = 1 ; V_87 < 3 ; V_87 ++ ) {
struct V_1 * V_90 = V_25 -> V_91 [ V_87 - 1 ] ;
if ( V_90 )
F_37 ( & V_90 -> V_38 ) ;
}
F_41 ( & V_89 ) ;
F_32 ( & V_37 ) ;
F_70 ( V_25 ) ;
for ( V_87 = 1 ; V_87 < 3 ; V_87 ++ ) {
struct V_1 * V_90 = V_25 -> V_91 [ V_87 - 1 ] ;
if ( V_90 )
F_47 ( V_90 ) ;
}
}
struct V_5 *
F_71 ( struct V_1 * V_25 , const char * V_20 ,
int (* F_72)( void * ) , void (* F_73)( void * ) ,
void (* F_74)( void * ) ,
int V_64 , void * V_93 )
{
struct V_5 * V_55 ;
if ( V_25 -> V_65 -> V_64 & V_94 ) {
F_64 ( V_95 L_4 ,
V_25 -> V_20 ) ;
return NULL ;
}
if ( V_64 & V_96 ) {
if ( ! F_72 || ! F_73 ) {
F_64 ( V_97 L_5 , V_25 -> V_20 , V_20 ) ;
return NULL ;
}
}
if ( V_64 & V_98 ) {
if ( V_25 -> V_65 -> V_62 ) {
F_75 ( L_6 ,
V_25 -> V_20 , V_20 ) ;
return NULL ;
}
}
if ( ! F_76 ( V_25 -> V_53 -> V_31 ) )
return NULL ;
F_43 ( V_25 ) ;
V_55 = F_56 ( sizeof( struct V_5 ) , V_57 ) ;
if ( ! V_55 )
goto V_99;
V_55 -> V_100 = F_56 ( sizeof( struct V_7 ) , V_57 ) ;
if ( ! V_55 -> V_100 )
goto V_101;
V_55 -> V_20 = V_20 ;
V_55 -> V_25 = V_25 ;
V_55 -> V_59 = - 1 ;
V_55 -> V_102 = F_72 ;
V_55 -> V_103 = F_73 ;
V_55 -> V_104 = V_93 ;
V_55 -> V_64 = V_64 ;
V_55 -> F_74 = F_74 ;
V_55 -> V_105 = 0 ;
V_55 -> V_106 = 5 * V_107 ;
V_55 -> V_34 = false ;
V_55 -> V_108 = NULL ;
F_39 ( & V_25 -> V_65 -> V_69 ) ;
if ( V_64 & V_98 ) {
if ( V_25 -> V_65 -> V_62 ) {
F_41 ( & V_25 -> V_65 -> V_69 ) ;
F_64 ( V_95
L_6 ,
V_25 -> V_20 , V_20 ) ;
goto V_109;
}
V_25 -> V_64 |= V_94 ;
}
V_55 -> V_79 = V_25 -> V_65 -> V_62 ;
F_77 () ;
if ( V_25 -> V_65 -> V_62 )
V_25 -> V_65 -> V_62 -> V_108 = V_55 ;
V_25 -> V_65 -> V_62 = V_55 ;
F_41 ( & V_25 -> V_65 -> V_69 ) ;
F_78 ( & V_55 -> V_110 ) ;
V_55 -> V_111 = V_112 ;
V_55 -> V_113 = V_55 -> V_114 = NULL ;
V_25 -> V_53 -> V_115 ( V_55 , V_55 -> V_100 ) ;
if ( ! F_79 ( V_116 , & V_25 -> V_117 ) ) {
V_25 -> V_118 = V_55 ;
F_80 ( V_55 ) ;
}
return V_55 ;
V_109:
F_42 ( V_55 -> V_100 ) ;
V_101:
F_42 ( V_55 ) ;
V_99:
F_47 ( V_25 ) ;
F_81 ( V_25 -> V_53 -> V_31 ) ;
return NULL ;
}
static void F_82 ( struct V_11 * V_12 )
{
struct V_5 * V_19 = F_12 ( V_12 ) ;
F_42 ( V_19 -> V_20 ) ;
F_42 ( V_19 ) ;
}
struct V_5 *
F_83 ( struct V_1 * V_25 , const char * V_20 ,
const struct V_119 * V_120 , int V_121 )
{
struct V_5 * V_19 ;
int V_35 ;
char * V_122 ;
if ( V_25 -> V_65 -> V_64 & V_94 ) {
F_75 ( L_4 , V_25 -> V_20 ) ;
return NULL ;
}
if ( V_120 -> V_64 & V_96 ) {
if ( ! V_120 -> V_102 || ! V_120 -> V_103 ) {
F_84 ( L_5 ,
V_25 -> V_20 , V_20 ) ;
return NULL ;
}
}
if ( V_120 -> V_64 & V_98 ) {
if ( V_25 -> V_65 -> V_62 ) {
F_75 ( L_6 ,
V_25 -> V_20 , V_20 ) ;
return NULL ;
}
}
if ( ! F_76 ( V_25 -> V_53 -> V_31 ) )
return NULL ;
F_43 ( V_25 ) ;
V_19 = F_50 ( sizeof( * V_19 ) , V_57 ) ;
if ( ! V_19 )
goto V_123;
V_19 -> V_100 = F_50 ( sizeof( * V_19 -> V_100 ) , V_57 ) ;
if ( ! V_19 -> V_100 )
goto V_124;
V_122 = F_85 ( V_20 , V_57 ) ;
if ( ! V_122 )
goto V_125;
V_19 -> V_20 = V_122 ;
V_19 -> V_25 = V_25 ;
V_19 -> V_59 = - 1 ;
V_19 -> V_102 = V_120 -> V_102 ;
V_19 -> V_103 = V_120 -> V_103 ;
V_19 -> V_104 = V_120 -> V_104 ;
V_19 -> V_64 = V_120 -> V_64 ;
V_19 -> F_74 = V_120 -> F_74 ;
V_19 -> V_105 = 0 ;
V_19 -> V_106 = 5 * V_107 ;
V_19 -> V_12 . V_126 = & V_25 -> V_48 ;
V_19 -> V_12 . V_36 = & V_21 ;
V_35 = F_59 ( & V_19 -> V_12 , L_7 , V_122 , V_121 ) ;
if ( V_35 )
goto V_127;
V_19 -> V_12 . V_82 = F_82 ;
V_19 -> V_34 = true ;
V_35 = F_60 ( & V_19 -> V_12 ) ;
if ( V_35 ) {
F_48 ( & V_19 -> V_12 ) ;
goto V_123;
}
V_19 -> V_108 = NULL ;
F_39 ( & V_25 -> V_65 -> V_69 ) ;
if ( V_120 -> V_64 & V_98 ) {
if ( V_25 -> V_65 -> V_62 ) {
F_41 ( & V_25 -> V_65 -> V_69 ) ;
F_86 ( L_6 ,
V_25 -> V_20 , V_20 ) ;
F_46 ( & V_19 -> V_12 ) ;
goto V_123;
}
V_25 -> V_64 |= V_94 ;
}
V_19 -> V_79 = V_25 -> V_65 -> V_62 ;
F_77 () ;
if ( V_25 -> V_65 -> V_62 )
V_25 -> V_65 -> V_62 -> V_108 = V_19 ;
V_25 -> V_65 -> V_62 = V_19 ;
F_41 ( & V_25 -> V_65 -> V_69 ) ;
F_78 ( & V_19 -> V_110 ) ;
V_19 -> V_111 = V_112 ;
V_19 -> V_113 = NULL ;
V_19 -> V_114 = NULL ;
V_25 -> V_53 -> V_115 ( V_19 , V_19 -> V_100 ) ;
V_25 -> V_118 = V_19 ;
F_80 ( V_19 ) ;
return V_19 ;
V_127:
F_42 ( V_122 ) ;
V_125:
F_42 ( V_19 -> V_100 ) ;
V_124:
if ( ! V_19 -> V_34 )
F_42 ( V_19 ) ;
V_123:
F_47 ( V_25 ) ;
F_81 ( V_25 -> V_53 -> V_31 ) ;
return NULL ;
}
void F_87 ( struct V_5 * V_12 )
{
struct V_1 * V_25 ;
#ifdef F_88
if ( ! V_12 ) {
F_64 ( V_128 L_8 ) ;
return;
}
#endif
V_25 = V_12 -> V_25 -> V_65 ;
if ( V_25 -> V_118 == V_12 ) {
V_25 -> V_118 = NULL ;
F_89 ( V_116 , & V_25 -> V_117 ) ;
F_90 ( V_12 ) ;
}
if ( V_25 -> V_63 == V_12 ) {
F_64 ( V_95 L_9 ,
V_25 -> V_20 , V_12 -> V_20 ) ;
F_91 ( V_12 ) ;
}
F_39 ( & V_25 -> V_69 ) ;
if ( V_12 -> V_79 )
V_12 -> V_79 -> V_108 = V_12 -> V_108 ;
if ( V_12 -> V_108 )
V_12 -> V_108 -> V_79 = V_12 -> V_79 ;
else
V_25 -> V_62 = V_12 -> V_79 ;
if ( V_12 -> V_64 & V_98 )
V_25 -> V_64 &= ~ V_94 ;
F_41 ( & V_25 -> V_69 ) ;
F_66 ( & V_25 -> V_68 ) ;
if ( V_12 -> V_114 || V_12 -> V_113 || V_25 -> V_85 == V_12 ) {
if ( V_12 -> V_114 )
V_12 -> V_114 -> V_113 = V_12 -> V_113 ;
else
V_25 -> V_85 = V_12 -> V_113 ;
if ( V_12 -> V_113 )
V_12 -> V_113 -> V_114 = V_12 -> V_114 ;
else
V_25 -> V_86 = V_12 -> V_114 ;
}
F_67 ( & V_25 -> V_68 ) ;
F_42 ( V_12 -> V_100 ) ;
if ( V_12 -> V_34 )
F_46 ( & V_12 -> V_12 ) ;
else
F_42 ( V_12 ) ;
F_81 ( V_25 -> V_53 -> V_31 ) ;
F_47 ( V_25 ) ;
}
struct V_1 * F_92 ( int V_80 )
{
struct V_1 * V_25 , * V_129 = NULL ;
if ( F_28 ( & V_33 ) )
F_23 () ;
F_39 ( & V_89 ) ;
F_19 (port, &portlist, list) {
if ( V_25 -> V_80 == V_80 ) {
V_129 = F_43 ( V_25 ) ;
break;
}
}
F_41 ( & V_89 ) ;
return V_129 ;
}
struct V_1 * F_93 ( unsigned long V_49 )
{
struct V_1 * V_25 , * V_129 = NULL ;
if ( F_28 ( & V_33 ) )
F_23 () ;
F_39 ( & V_89 ) ;
F_19 (port, &portlist, list) {
if ( V_25 -> V_49 == V_49 ) {
V_129 = F_43 ( V_25 ) ;
break;
}
}
F_41 ( & V_89 ) ;
return V_129 ;
}
int F_94 ( struct V_5 * V_12 )
{
struct V_5 * V_130 ;
struct V_1 * V_25 = V_12 -> V_25 -> V_65 ;
unsigned long V_64 ;
if ( V_25 -> V_63 == V_12 ) {
F_64 ( V_97 L_10 ,
V_12 -> V_25 -> V_20 , V_12 -> V_20 ) ;
return 0 ;
}
F_95 ( & V_25 -> V_67 , V_64 ) ;
V_130 = V_25 -> V_63 ;
if ( V_130 ) {
if ( V_130 -> V_102 ) {
if ( V_130 -> V_102 ( V_130 -> V_104 ) )
goto V_131;
V_25 -> V_53 -> V_132 ( V_25 , V_12 -> V_100 ) ;
} else
goto V_131;
if ( V_25 -> V_63 != V_130 ) {
F_64 ( V_88
L_11 ,
V_25 -> V_20 , V_130 -> V_20 ) ;
if ( V_25 -> V_63 )
goto V_131;
}
}
if ( V_12 -> V_105 & 1 ) {
V_12 -> V_105 = 0 ;
F_66 ( & V_25 -> V_68 ) ;
if ( V_12 -> V_114 )
V_12 -> V_114 -> V_113 = V_12 -> V_113 ;
else
V_25 -> V_85 = V_12 -> V_113 ;
if ( V_12 -> V_113 )
V_12 -> V_113 -> V_114 = V_12 -> V_114 ;
else
V_25 -> V_86 = V_12 -> V_114 ;
F_67 ( & V_25 -> V_68 ) ;
V_12 -> V_114 = V_12 -> V_113 = NULL ;
}
V_25 -> V_63 = V_12 ;
#ifdef F_62
if ( V_12 -> V_25 -> V_58 >= 0 ) {
V_25 -> V_60 = V_12 -> V_25 -> V_58 ;
}
if ( V_12 -> V_59 >= 0 ) {
if ( ! F_96 ( V_25 , V_12 -> V_59 ,
V_72 ) )
V_25 -> V_59 = V_12 -> V_59 ;
}
#endif
V_25 -> V_53 -> V_133 ( V_25 , V_12 -> V_100 ) ;
F_97 ( & V_25 -> V_67 , V_64 ) ;
V_12 -> time = V_134 ;
return 0 ;
V_131:
if ( V_12 -> V_105 & 2 || V_12 -> V_103 ) {
F_39 ( & V_25 -> V_68 ) ;
if ( F_79 ( 0 , & V_12 -> V_105 ) == 0 ) {
V_12 -> V_113 = NULL ;
V_12 -> V_114 = V_25 -> V_86 ;
if ( V_25 -> V_86 ) {
V_25 -> V_86 -> V_113 = V_12 ;
V_25 -> V_86 = V_12 ;
} else
V_25 -> V_85 = V_25 -> V_86 = V_12 ;
}
F_41 ( & V_25 -> V_68 ) ;
}
F_97 ( & V_25 -> V_67 , V_64 ) ;
return - V_135 ;
}
int F_98 ( struct V_5 * V_12 )
{
int V_136 ;
V_12 -> V_105 = 2 ;
V_136 = F_94 ( V_12 ) ;
if ( V_136 == - V_135 ) {
#ifdef F_99
F_64 ( V_95 L_12 , V_12 -> V_20 ) ;
#endif
if ( V_12 -> V_105 ) {
F_100 ( V_12 -> V_110 ,
! V_12 -> V_105 ) ;
if ( F_101 ( V_137 ) )
return - V_138 ;
V_136 = 1 ;
} else {
V_136 = 0 ;
#ifdef F_99
F_64 ( V_95 L_13 ,
V_12 -> V_20 ) ;
#endif
}
#ifdef F_99
if ( V_12 -> V_25 -> V_65 -> V_63 != V_12 )
F_64 ( V_95 L_14 ,
V_12 -> V_20 , V_12 -> V_25 -> V_65 -> V_63 ?
V_12 -> V_25 -> V_65 -> V_63 -> V_20 : L_15 ) ;
#endif
}
V_12 -> V_105 = 0 ;
return V_136 ;
}
void F_91 ( struct V_5 * V_12 )
{
struct V_1 * V_25 = V_12 -> V_25 -> V_65 ;
struct V_5 * V_139 ;
unsigned long V_64 ;
F_95 ( & V_25 -> V_67 , V_64 ) ;
if ( V_25 -> V_63 != V_12 ) {
F_97 ( & V_25 -> V_67 , V_64 ) ;
F_64 ( V_88 L_16 ,
V_25 -> V_20 , V_12 -> V_20 ) ;
return;
}
#ifdef F_62
if ( V_12 -> V_25 -> V_58 >= 0 ) {
V_25 -> V_60 = - 1 ;
}
if ( V_12 -> V_59 >= 0 ) {
F_102 ( V_25 ) ;
V_25 -> V_59 = - 1 ;
}
#endif
V_25 -> V_63 = NULL ;
F_97 ( & V_25 -> V_67 , V_64 ) ;
V_25 -> V_53 -> V_132 ( V_25 , V_12 -> V_100 ) ;
for ( V_139 = V_25 -> V_85 ; V_139 ; V_139 = V_139 -> V_113 ) {
if ( V_139 -> V_105 & 2 ) {
F_94 ( V_139 ) ;
if ( F_103 ( & V_139 -> V_110 ) )
F_104 ( & V_139 -> V_110 ) ;
return;
} else if ( V_139 -> V_103 ) {
V_139 -> V_103 ( V_139 -> V_104 ) ;
if ( V_12 -> V_25 -> V_63 )
return;
} else {
F_64 ( V_128 L_17 , V_25 -> V_20 , V_139 -> V_20 ) ;
}
}
for ( V_139 = V_25 -> V_62 ; ! V_25 -> V_63 && V_139 ; V_139 = V_139 -> V_79 ) {
if ( V_139 -> V_103 && V_139 != V_12 )
V_139 -> V_103 ( V_139 -> V_104 ) ;
}
}
T_2 F_105 ( int V_50 , void * V_140 )
{
struct V_1 * V_25 = V_140 ;
F_106 ( V_25 ) ;
return V_141 ;
}
