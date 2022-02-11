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
if ( ! V_55 ) {
F_51 ( V_58 L_2 ) ;
return NULL ;
}
V_55 -> V_49 = V_49 ;
V_55 -> V_50 = V_50 ;
V_55 -> V_51 = V_51 ;
V_55 -> V_59 = V_55 -> V_60 = V_55 -> V_61 = - 1 ;
V_55 -> V_62 = 0 ;
F_52 ( & V_55 -> V_38 ) ;
V_55 -> V_63 = V_55 -> V_64 = NULL ;
V_55 -> V_65 = 0 ;
V_55 -> V_53 = V_53 ;
V_55 -> V_66 = V_55 ;
memset ( V_55 -> V_42 , 0 , 5 * sizeof ( struct V_67 ) ) ;
F_53 ( & V_55 -> V_68 ) ;
F_54 ( & V_55 -> V_69 ) ;
F_54 ( & V_55 -> V_70 ) ;
V_55 -> V_71 . V_72 = V_73 ;
V_55 -> V_71 . V_74 = V_75 ;
F_55 ( & V_55 -> V_71 . V_50 , 0 ) ;
V_55 -> V_76 = V_77 ;
F_56 ( & V_55 -> V_78 , 1 ) ;
F_52 ( & V_55 -> V_41 ) ;
V_20 = F_57 ( 15 , V_57 ) ;
if ( ! V_20 ) {
F_51 ( V_79 L_2 ) ;
F_42 ( V_55 ) ;
return NULL ;
}
F_39 ( & V_40 ) ;
for ( V_9 = V_80 . V_81 , V_56 = 0 ; V_9 != & V_80 ; V_9 = V_9 -> V_81 , V_56 ++ ) {
struct V_1 * V_2 = F_58 ( V_9 , struct V_1 , V_41 ) ;
if ( V_2 -> V_82 != V_56 )
break;
}
V_55 -> V_83 = V_55 -> V_82 = V_56 ;
F_59 ( & V_55 -> V_41 , V_9 ) ;
F_41 ( & V_40 ) ;
sprintf ( V_20 , L_3 , V_55 -> V_83 = V_55 -> V_82 ) ;
V_55 -> V_20 = V_20 ;
V_55 -> V_48 . V_36 = & V_21 ;
V_55 -> V_48 . V_84 = F_38 ;
F_60 ( & V_55 -> V_48 , V_20 ) ;
V_55 -> V_48 . type = & V_13 ;
for ( V_11 = 0 ; V_11 < 5 ; V_11 ++ )
V_55 -> V_42 [ V_11 ] . V_85 = V_86 ;
V_55 -> V_87 = V_55 -> V_88 = NULL ;
V_35 = F_61 ( & V_55 -> V_48 ) ;
if ( V_35 ) {
F_48 ( & V_55 -> V_48 ) ;
return NULL ;
}
return V_55 ;
}
void F_62 ( struct V_1 * V_25 )
{
int V_89 ;
#ifdef F_63
F_64 ( V_25 ) ;
#endif
if ( ! V_25 -> V_12 )
F_51 ( V_58 L_4
L_5 ,
V_25 -> V_20 ) ;
F_65 ( V_25 ) ;
F_30 ( & V_37 ) ;
F_66 ( & V_90 ) ;
F_59 ( & V_25 -> V_38 , & V_33 ) ;
for ( V_89 = 1 ; V_89 < 3 ; V_89 ++ ) {
struct V_1 * V_91 = V_25 -> V_92 [ V_89 - 1 ] ;
if ( V_91 )
F_59 ( & V_91 -> V_38 , & V_33 ) ;
}
F_67 ( & V_90 ) ;
F_18 ( V_25 ) ;
for ( V_89 = 1 ; V_89 < 3 ; V_89 ++ ) {
struct V_1 * V_91 = V_25 -> V_92 [ V_89 - 1 ] ;
if ( V_91 )
F_18 ( V_91 ) ;
}
F_32 ( & V_37 ) ;
}
void F_68 ( struct V_1 * V_25 )
{
int V_89 ;
F_30 ( & V_37 ) ;
F_22 ( V_25 ) ;
#ifdef F_63
F_69 ( V_25 ) ;
for ( V_89 = 1 ; V_89 < 3 ; V_89 ++ ) {
struct V_1 * V_91 = V_25 -> V_92 [ V_89 - 1 ] ;
if ( ! V_91 )
continue;
F_22 ( V_91 ) ;
F_69 ( V_91 ) ;
}
#endif
V_25 -> V_53 = & V_93 ;
F_39 ( & V_90 ) ;
F_37 ( & V_25 -> V_38 ) ;
for ( V_89 = 1 ; V_89 < 3 ; V_89 ++ ) {
struct V_1 * V_91 = V_25 -> V_92 [ V_89 - 1 ] ;
if ( V_91 )
F_37 ( & V_91 -> V_38 ) ;
}
F_41 ( & V_90 ) ;
F_32 ( & V_37 ) ;
F_70 ( V_25 ) ;
for ( V_89 = 1 ; V_89 < 3 ; V_89 ++ ) {
struct V_1 * V_91 = V_25 -> V_92 [ V_89 - 1 ] ;
if ( V_91 )
F_47 ( V_91 ) ;
}
}
struct V_5 *
F_71 ( struct V_1 * V_25 , const char * V_20 ,
int (* F_72)( void * ) , void (* F_73)( void * ) ,
void (* F_74)( void * ) ,
int V_65 , void * V_94 )
{
struct V_5 * V_55 ;
if ( V_25 -> V_66 -> V_65 & V_95 ) {
F_51 ( V_96 L_6 ,
V_25 -> V_20 ) ;
return NULL ;
}
if ( V_65 & V_97 ) {
if ( ! F_72 || ! F_73 ) {
F_51 ( V_98 L_7 , V_25 -> V_20 , V_20 ) ;
return NULL ;
}
}
if ( V_65 & V_99 ) {
if ( V_25 -> V_66 -> V_63 ) {
F_75 ( L_8 ,
V_25 -> V_20 , V_20 ) ;
return NULL ;
}
}
if ( ! F_76 ( V_25 -> V_53 -> V_31 ) ) {
return NULL ;
}
F_43 ( V_25 ) ;
V_55 = F_57 ( sizeof( struct V_5 ) , V_57 ) ;
if ( V_55 == NULL ) {
F_51 ( V_58 L_9 , V_25 -> V_20 , V_20 ) ;
goto V_100;
}
V_55 -> V_101 = F_57 ( sizeof( struct V_7 ) , V_57 ) ;
if ( V_55 -> V_101 == NULL ) {
F_51 ( V_58 L_9 , V_25 -> V_20 , V_20 ) ;
goto V_102;
}
V_55 -> V_20 = V_20 ;
V_55 -> V_25 = V_25 ;
V_55 -> V_60 = - 1 ;
V_55 -> V_103 = F_72 ;
V_55 -> V_104 = F_73 ;
V_55 -> V_105 = V_94 ;
V_55 -> V_65 = V_65 ;
V_55 -> F_74 = F_74 ;
V_55 -> V_106 = 0 ;
V_55 -> V_107 = 5 * V_108 ;
V_55 -> V_34 = false ;
V_55 -> V_109 = NULL ;
F_39 ( & V_25 -> V_66 -> V_70 ) ;
if ( V_65 & V_99 ) {
if ( V_25 -> V_66 -> V_63 ) {
F_41 ( & V_25 -> V_66 -> V_70 ) ;
F_51 ( V_96
L_10
L_11 , V_25 -> V_20 , V_20 ) ;
goto V_110;
}
V_25 -> V_65 |= V_95 ;
}
V_55 -> V_81 = V_25 -> V_66 -> V_63 ;
F_77 () ;
if ( V_25 -> V_66 -> V_63 )
V_25 -> V_66 -> V_63 -> V_109 = V_55 ;
V_25 -> V_66 -> V_63 = V_55 ;
F_41 ( & V_25 -> V_66 -> V_70 ) ;
F_78 ( & V_55 -> V_111 ) ;
V_55 -> V_112 = V_113 ;
V_55 -> V_114 = V_55 -> V_115 = NULL ;
V_25 -> V_53 -> V_116 ( V_55 , V_55 -> V_101 ) ;
if ( ! F_79 ( V_117 , & V_25 -> V_118 ) ) {
V_25 -> V_119 = V_55 ;
F_80 ( V_55 ) ;
}
return V_55 ;
V_110:
F_42 ( V_55 -> V_101 ) ;
V_102:
F_42 ( V_55 ) ;
V_100:
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
const struct V_120 * V_121 , int V_122 )
{
struct V_5 * V_19 ;
int V_35 ;
char * V_123 ;
if ( V_25 -> V_66 -> V_65 & V_95 ) {
F_75 ( L_6 , V_25 -> V_20 ) ;
return NULL ;
}
if ( V_121 -> V_65 & V_97 ) {
if ( ! V_121 -> V_103 || ! V_121 -> V_104 ) {
F_84 ( L_7 ,
V_25 -> V_20 , V_20 ) ;
return NULL ;
}
}
if ( V_121 -> V_65 & V_99 ) {
if ( V_25 -> V_66 -> V_63 ) {
F_75 ( L_8 ,
V_25 -> V_20 , V_20 ) ;
return NULL ;
}
}
if ( ! F_76 ( V_25 -> V_53 -> V_31 ) )
return NULL ;
F_43 ( V_25 ) ;
V_19 = F_50 ( sizeof( * V_19 ) , V_57 ) ;
if ( ! V_19 )
goto V_124;
V_19 -> V_101 = F_50 ( sizeof( * V_19 -> V_101 ) , V_57 ) ;
if ( ! V_19 -> V_101 )
goto V_125;
V_123 = F_85 ( V_20 , V_57 ) ;
if ( ! V_123 )
goto V_126;
V_19 -> V_20 = V_123 ;
V_19 -> V_25 = V_25 ;
V_19 -> V_60 = - 1 ;
V_19 -> V_103 = V_121 -> V_103 ;
V_19 -> V_104 = V_121 -> V_104 ;
V_19 -> V_105 = V_121 -> V_105 ;
V_19 -> V_65 = V_121 -> V_65 ;
V_19 -> F_74 = V_121 -> F_74 ;
V_19 -> V_106 = 0 ;
V_19 -> V_107 = 5 * V_108 ;
V_19 -> V_12 . V_127 = & V_25 -> V_48 ;
V_19 -> V_12 . V_36 = & V_21 ;
V_35 = F_60 ( & V_19 -> V_12 , L_12 , V_123 , V_122 ) ;
if ( V_35 )
goto V_128;
V_19 -> V_12 . V_84 = F_82 ;
V_19 -> V_34 = true ;
V_35 = F_61 ( & V_19 -> V_12 ) ;
if ( V_35 ) {
F_48 ( & V_19 -> V_12 ) ;
goto V_124;
}
V_19 -> V_109 = NULL ;
F_39 ( & V_25 -> V_66 -> V_70 ) ;
if ( V_121 -> V_65 & V_99 ) {
if ( V_25 -> V_66 -> V_63 ) {
F_41 ( & V_25 -> V_66 -> V_70 ) ;
F_86 ( L_8 ,
V_25 -> V_20 , V_20 ) ;
F_46 ( & V_19 -> V_12 ) ;
goto V_124;
}
V_25 -> V_65 |= V_95 ;
}
V_19 -> V_81 = V_25 -> V_66 -> V_63 ;
F_77 () ;
if ( V_25 -> V_66 -> V_63 )
V_25 -> V_66 -> V_63 -> V_109 = V_19 ;
V_25 -> V_66 -> V_63 = V_19 ;
F_41 ( & V_25 -> V_66 -> V_70 ) ;
F_78 ( & V_19 -> V_111 ) ;
V_19 -> V_112 = V_113 ;
V_19 -> V_114 = NULL ;
V_19 -> V_115 = NULL ;
V_25 -> V_53 -> V_116 ( V_19 , V_19 -> V_101 ) ;
V_25 -> V_119 = V_19 ;
F_80 ( V_19 ) ;
return V_19 ;
V_128:
F_42 ( V_123 ) ;
V_126:
F_42 ( V_19 -> V_101 ) ;
V_125:
if ( ! V_19 -> V_34 )
F_42 ( V_19 ) ;
V_124:
F_47 ( V_25 ) ;
F_81 ( V_25 -> V_53 -> V_31 ) ;
return NULL ;
}
void F_87 ( struct V_5 * V_12 )
{
struct V_1 * V_25 ;
#ifdef F_88
if ( V_12 == NULL ) {
F_51 ( V_79 L_13 ) ;
return;
}
#endif
V_25 = V_12 -> V_25 -> V_66 ;
if ( V_25 -> V_119 == V_12 ) {
V_25 -> V_119 = NULL ;
F_89 ( V_117 , & V_25 -> V_118 ) ;
F_90 ( V_12 ) ;
}
if ( V_25 -> V_64 == V_12 ) {
F_51 ( V_96 L_14 ,
V_25 -> V_20 , V_12 -> V_20 ) ;
F_91 ( V_12 ) ;
}
F_39 ( & V_25 -> V_70 ) ;
if ( V_12 -> V_81 )
V_12 -> V_81 -> V_109 = V_12 -> V_109 ;
if ( V_12 -> V_109 )
V_12 -> V_109 -> V_81 = V_12 -> V_81 ;
else
V_25 -> V_63 = V_12 -> V_81 ;
if ( V_12 -> V_65 & V_99 )
V_25 -> V_65 &= ~ V_95 ;
F_41 ( & V_25 -> V_70 ) ;
F_66 ( & V_25 -> V_69 ) ;
if ( V_12 -> V_115 || V_12 -> V_114 || V_25 -> V_87 == V_12 ) {
if ( V_12 -> V_115 )
V_12 -> V_115 -> V_114 = V_12 -> V_114 ;
else
V_25 -> V_87 = V_12 -> V_114 ;
if ( V_12 -> V_114 )
V_12 -> V_114 -> V_115 = V_12 -> V_115 ;
else
V_25 -> V_88 = V_12 -> V_115 ;
}
F_67 ( & V_25 -> V_69 ) ;
F_42 ( V_12 -> V_101 ) ;
if ( V_12 -> V_34 )
F_46 ( & V_12 -> V_12 ) ;
else
F_42 ( V_12 ) ;
F_81 ( V_25 -> V_53 -> V_31 ) ;
F_47 ( V_25 ) ;
}
struct V_1 * F_92 ( int V_82 )
{
struct V_1 * V_25 , * V_129 = NULL ;
if ( F_28 ( & V_33 ) )
F_23 () ;
F_39 ( & V_90 ) ;
F_19 (port, &portlist, list) {
if ( V_25 -> V_82 == V_82 ) {
V_129 = F_43 ( V_25 ) ;
break;
}
}
F_41 ( & V_90 ) ;
return V_129 ;
}
struct V_1 * F_93 ( unsigned long V_49 )
{
struct V_1 * V_25 , * V_129 = NULL ;
if ( F_28 ( & V_33 ) )
F_23 () ;
F_39 ( & V_90 ) ;
F_19 (port, &portlist, list) {
if ( V_25 -> V_49 == V_49 ) {
V_129 = F_43 ( V_25 ) ;
break;
}
}
F_41 ( & V_90 ) ;
return V_129 ;
}
int F_94 ( struct V_5 * V_12 )
{
struct V_5 * V_130 ;
struct V_1 * V_25 = V_12 -> V_25 -> V_66 ;
unsigned long V_65 ;
if ( V_25 -> V_64 == V_12 ) {
F_51 ( V_98 L_15 ,
V_12 -> V_25 -> V_20 , V_12 -> V_20 ) ;
return 0 ;
}
F_95 ( & V_25 -> V_68 , V_65 ) ;
if ( ( V_130 = V_25 -> V_64 ) != NULL ) {
if ( V_130 -> V_103 ) {
if ( V_130 -> V_103 ( V_130 -> V_105 ) )
goto V_131;
V_25 -> V_53 -> V_132 ( V_25 , V_12 -> V_101 ) ;
} else
goto V_131;
if ( V_25 -> V_64 != V_130 ) {
F_51 ( V_58
L_16 ,
V_25 -> V_20 , V_130 -> V_20 ) ;
if ( V_25 -> V_64 )
goto V_131;
}
}
if ( V_12 -> V_106 & 1 ) {
V_12 -> V_106 = 0 ;
F_66 ( & V_25 -> V_69 ) ;
if ( V_12 -> V_115 )
V_12 -> V_115 -> V_114 = V_12 -> V_114 ;
else
V_25 -> V_87 = V_12 -> V_114 ;
if ( V_12 -> V_114 )
V_12 -> V_114 -> V_115 = V_12 -> V_115 ;
else
V_25 -> V_88 = V_12 -> V_115 ;
F_67 ( & V_25 -> V_69 ) ;
V_12 -> V_115 = V_12 -> V_114 = NULL ;
}
V_25 -> V_64 = V_12 ;
#ifdef F_63
if ( V_12 -> V_25 -> V_59 >= 0 ) {
V_25 -> V_61 = V_12 -> V_25 -> V_59 ;
}
if ( V_12 -> V_60 >= 0 ) {
if ( ! F_96 ( V_25 , V_12 -> V_60 ,
V_73 ) )
V_25 -> V_60 = V_12 -> V_60 ;
}
#endif
V_25 -> V_53 -> V_133 ( V_25 , V_12 -> V_101 ) ;
F_97 ( & V_25 -> V_68 , V_65 ) ;
V_12 -> time = V_134 ;
return 0 ;
V_131:
if ( V_12 -> V_106 & 2 || V_12 -> V_104 ) {
F_39 ( & V_25 -> V_69 ) ;
if ( F_79 ( 0 , & V_12 -> V_106 ) == 0 ) {
V_12 -> V_114 = NULL ;
V_12 -> V_115 = V_25 -> V_88 ;
if ( V_25 -> V_88 ) {
V_25 -> V_88 -> V_114 = V_12 ;
V_25 -> V_88 = V_12 ;
} else
V_25 -> V_87 = V_25 -> V_88 = V_12 ;
}
F_41 ( & V_25 -> V_69 ) ;
}
F_97 ( & V_25 -> V_68 , V_65 ) ;
return - V_135 ;
}
int F_98 ( struct V_5 * V_12 )
{
int V_136 ;
V_12 -> V_106 = 2 ;
V_136 = F_94 ( V_12 ) ;
if ( V_136 == - V_135 ) {
#ifdef F_99
F_51 ( V_96 L_17 , V_12 -> V_20 ) ;
#endif
if ( V_12 -> V_106 ) {
F_100 ( V_12 -> V_111 ,
! V_12 -> V_106 ) ;
if ( F_101 ( V_137 ) ) {
return - V_138 ;
}
V_136 = 1 ;
} else {
V_136 = 0 ;
#ifdef F_99
F_51 ( V_96 L_18 ,
V_12 -> V_20 ) ;
#endif
}
#ifdef F_99
if ( V_12 -> V_25 -> V_66 -> V_64 != V_12 )
F_51 ( V_96 L_19
L_20 , V_12 -> V_20 ,
V_12 -> V_25 -> V_66 -> V_64 ?
V_12 -> V_25 -> V_66 -> V_64 -> V_20 : L_21 ) ;
#endif
}
V_12 -> V_106 = 0 ;
return V_136 ;
}
void F_91 ( struct V_5 * V_12 )
{
struct V_1 * V_25 = V_12 -> V_25 -> V_66 ;
struct V_5 * V_139 ;
unsigned long V_65 ;
F_95 ( & V_25 -> V_68 , V_65 ) ;
if ( V_25 -> V_64 != V_12 ) {
F_97 ( & V_25 -> V_68 , V_65 ) ;
F_51 ( V_58 L_22
L_23 , V_25 -> V_20 , V_12 -> V_20 ) ;
return;
}
#ifdef F_63
if ( V_12 -> V_25 -> V_59 >= 0 ) {
V_25 -> V_61 = - 1 ;
}
if ( V_12 -> V_60 >= 0 ) {
F_102 ( V_25 ) ;
V_25 -> V_60 = - 1 ;
}
#endif
V_25 -> V_64 = NULL ;
F_97 ( & V_25 -> V_68 , V_65 ) ;
V_25 -> V_53 -> V_132 ( V_25 , V_12 -> V_101 ) ;
for ( V_139 = V_25 -> V_87 ; V_139 ; V_139 = V_139 -> V_114 ) {
if ( V_139 -> V_106 & 2 ) {
F_94 ( V_139 ) ;
if ( F_103 ( & V_139 -> V_111 ) )
F_104 ( & V_139 -> V_111 ) ;
return;
} else if ( V_139 -> V_104 ) {
V_139 -> V_104 ( V_139 -> V_105 ) ;
if ( V_12 -> V_25 -> V_64 )
return;
} else {
F_51 ( V_79 L_24 , V_25 -> V_20 , V_139 -> V_20 ) ;
}
}
for ( V_139 = V_25 -> V_63 ; ( V_25 -> V_64 == NULL ) && V_139 ; V_139 = V_139 -> V_81 ) {
if ( V_139 -> V_104 && V_139 != V_12 )
V_139 -> V_104 ( V_139 -> V_105 ) ;
}
}
T_2 F_105 ( int V_50 , void * V_140 )
{
struct V_1 * V_25 = V_140 ;
F_106 ( V_25 ) ;
return V_141 ;
}
