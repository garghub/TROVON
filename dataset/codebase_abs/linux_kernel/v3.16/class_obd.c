int F_1 ( char * V_1 )
{
memset ( V_1 , 0 , V_2 ) ;
if ( strcmp ( V_3 , V_4 ) == 0 )
return 0 ;
if ( strcmp ( V_3 , V_5 ) == 0 ) {
snprintf ( V_1 , V_2 , L_1 ,
F_2 () ,
F_3 ( & V_6 , F_4 () ) ) ;
return 0 ;
}
if ( strcmp ( V_3 , V_7 ) == 0 ) {
strcpy ( V_1 , V_8 ) ;
return 0 ;
}
return - V_9 ;
}
int F_5 ( const void * V_10 , const char * V_11 , const char * type ,
T_1 V_12 , const char * V_13 , int line )
{
if ( V_10 == NULL ||
( F_6 () & V_14 ) < V_15 ) {
F_7 ( L_2 V_16 L_3 ,
V_10 ? L_4 : L_5 , type , V_11 , ( V_17 ) V_12 , V_13 ,
line ) ;
F_7 ( V_16 L_6 V_16 L_7
L_8 V_16 L_9
L_10 ,
F_8 () ,
F_9 () << V_18 ,
F_9 () ,
F_10 ( & V_19 ) ) ;
return 1 ;
}
return 0 ;
}
static inline void F_11 ( struct V_20 * V_21 ,
struct V_22 * V_23 )
{
memset ( V_21 , 0 , sizeof( * V_21 ) ) ;
V_21 -> V_24 = V_23 -> V_25 ;
}
static inline void F_12 ( struct V_22 * V_23 ,
struct V_20 * V_21 )
{
V_23 -> V_25 = V_21 -> V_24 ;
}
int F_13 ( T_2 V_26 , const char * V_11 )
{
int V_27 ;
int V_28 ;
if ( ! V_26 || ! V_11 ) {
F_7 ( L_11 ) ;
GOTO ( V_29 , V_27 = - V_30 ) ;
}
if ( V_11 [ V_26 - 1 ] != 0 ) {
F_7 ( L_12 ) ;
GOTO ( V_29 , V_27 = - V_30 ) ;
}
F_14 ( V_31 , L_13 , V_11 ) ;
V_28 = F_15 ( V_11 ) ;
if ( V_28 == - 1 ) {
F_14 ( V_31 , L_14 , V_11 ) ;
GOTO ( V_29 , V_27 = - V_30 ) ;
}
F_14 ( V_31 , L_15 , V_11 , V_28 ) ;
V_27 = V_28 ;
V_29:
return V_27 ;
}
int F_16 ( unsigned int V_32 , unsigned long V_33 )
{
char * V_34 = NULL ;
struct V_22 * V_23 ;
struct V_35 * V_36 ;
struct V_37 * V_38 = NULL ;
int V_39 = 0 , V_26 = 0 ;
if ( V_32 == V_40 ) {
V_36 = (struct V_35 * ) V_33 ;
V_41 = V_36 -> V_42 ;
V_43 = V_36 -> V_44 ;
return 0 ;
}
F_14 ( V_31 , L_16 , V_32 ) ;
if ( F_17 ( & V_34 , & V_26 , ( void * ) V_33 ) ) {
F_7 ( L_17 ) ;
return - V_30 ;
}
V_23 = (struct V_22 * ) V_34 ;
switch ( V_32 ) {
case V_45 : {
struct V_46 * V_47 ;
if ( ! V_23 -> V_48 || ! V_23 -> V_49 ) {
F_7 ( L_18 ) ;
GOTO ( V_29 , V_39 = - V_30 ) ;
}
F_18 ( V_47 , V_23 -> V_48 ) ;
if ( V_47 == NULL )
GOTO ( V_29 , V_39 = - V_50 ) ;
V_39 = F_19 ( V_47 , V_23 -> V_49 ,
V_23 -> V_48 ) ;
if ( ! V_39 )
V_39 = F_20 ( V_47 , V_23 -> V_48 ) ;
if ( ! V_39 )
V_39 = F_21 ( V_47 ) ;
F_22 ( V_47 , V_23 -> V_48 ) ;
GOTO ( V_29 , V_39 ) ;
}
case V_51 :
if ( ! V_23 -> V_52 ) {
F_7 ( L_19 ) ;
GOTO ( V_29 , V_39 = - V_30 ) ;
}
if ( strlen ( V_53 ) + 1 > V_23 -> V_54 ) {
F_7 ( L_20 ) ;
GOTO ( V_29 , V_39 = - V_30 ) ;
}
memcpy ( V_23 -> V_55 , V_53 ,
strlen ( V_53 ) + 1 ) ;
V_39 = F_23 ( ( void * ) V_33 , V_23 , V_26 ) ;
if ( V_39 )
V_39 = - V_56 ;
GOTO ( V_29 , V_39 ) ;
case V_57 : {
int V_28 ;
V_28 = F_13 ( V_23 -> V_54 ,
V_23 -> V_52 ) ;
V_23 -> V_58 = V_28 ;
if ( V_28 < 0 )
GOTO ( V_29 , V_39 = - V_30 ) ;
V_39 = F_23 ( ( void * ) V_33 , V_23 , sizeof( * V_23 ) ) ;
if ( V_39 )
V_39 = - V_56 ;
GOTO ( V_29 , V_39 ) ;
}
case V_59 : {
int V_28 ;
struct V_60 V_61 ;
if ( ! V_23 -> V_54 || ! V_23 -> V_52 ) {
F_7 ( L_21 ) ;
GOTO ( V_29 , V_39 = - V_30 ) ;
}
if ( V_23 -> V_52 [ V_23 -> V_54 - 1 ] != 0 ) {
F_7 ( L_22 ) ;
GOTO ( V_29 , V_39 = - V_30 ) ;
}
F_14 ( V_31 , L_13 , V_23 -> V_52 ) ;
F_24 ( & V_61 , V_23 -> V_52 ) ;
V_28 = F_25 ( & V_61 ) ;
V_23 -> V_58 = V_28 ;
if ( V_28 == - 1 ) {
F_14 ( V_31 , L_23 ,
V_23 -> V_52 ) ;
GOTO ( V_29 , V_39 = - V_30 ) ;
}
F_14 ( V_31 , L_15 , V_23 -> V_52 ,
V_28 ) ;
V_39 = F_23 ( ( void * ) V_33 , V_23 , sizeof( * V_23 ) ) ;
if ( V_39 )
V_39 = - V_56 ;
GOTO ( V_29 , V_39 ) ;
}
case V_62 : {
F_14 ( V_31 , L_24 ,
V_23 -> V_52 ) ;
GOTO ( V_29 , V_39 = 0 ) ;
}
case V_63 : {
int V_64 = V_23 -> V_65 ;
char * V_66 , * V_67 ;
if ( ! V_23 -> V_52 ) {
F_7 ( L_19 ) ;
GOTO ( V_29 , V_39 = - V_30 ) ;
}
if ( V_23 -> V_54 < 128 ) {
F_7 ( L_20 ) ;
GOTO ( V_29 , V_39 = - V_30 ) ;
}
V_38 = F_26 ( V_64 ) ;
if ( ! V_38 )
GOTO ( V_29 , V_39 = - V_9 ) ;
if ( V_38 -> V_68 )
V_66 = L_25 ;
else if ( V_38 -> V_69 )
V_66 = L_26 ;
else if ( V_38 -> V_70 )
V_66 = L_27 ;
else
V_66 = L_28 ;
V_67 = ( char * ) V_23 -> V_55 ;
snprintf ( V_67 , V_26 - sizeof( * V_23 ) , L_29 ,
( int ) V_64 , V_66 , V_38 -> V_71 -> V_72 ,
V_38 -> V_73 , V_38 -> V_60 . V_61 ,
F_10 ( & V_38 -> V_74 ) ) ;
V_39 = F_23 ( ( void * ) V_33 , V_23 , V_26 ) ;
GOTO ( V_29 , V_39 = 0 ) ;
}
}
if ( V_23 -> V_58 == V_75 ) {
if ( V_23 -> V_76 <= 0 || V_23 -> V_77 == NULL )
GOTO ( V_29 , V_39 = - V_30 ) ;
if ( F_27 ( V_23 -> V_77 , V_78 ) >= V_78 )
GOTO ( V_29 , V_39 = - V_30 ) ;
V_38 = F_28 ( V_23 -> V_77 ) ;
} else if ( V_23 -> V_58 < F_29 () ) {
V_38 = F_26 ( V_23 -> V_58 ) ;
} else {
F_7 ( L_30 ) ;
GOTO ( V_29 , V_39 = - V_30 ) ;
}
if ( V_38 == NULL ) {
F_7 ( L_31 , V_23 -> V_58 ) ;
GOTO ( V_29 , V_39 = - V_30 ) ;
}
F_30 ( V_38 -> V_79 == V_80 ) ;
if ( ! V_38 -> V_69 || V_38 -> V_68 ) {
F_7 ( L_32 , V_23 -> V_58 ) ;
GOTO ( V_29 , V_39 = - V_30 ) ;
}
switch( V_32 ) {
case V_81 : {
if ( ! V_38 -> V_70 ) {
F_7 ( L_33 , V_38 -> V_82 ) ;
GOTO ( V_29 , V_39 = - V_83 ) ;
}
F_14 ( V_84 , L_34 ,
V_38 -> V_73 ) ;
V_38 -> V_85 = 1 ;
GOTO ( V_29 , V_39 = 0 ) ;
}
default: {
V_39 = F_31 ( V_32 , V_38 -> V_86 , V_26 , V_23 , NULL ) ;
if ( V_39 )
GOTO ( V_29 , V_39 ) ;
V_39 = F_23 ( ( void * ) V_33 , V_23 , V_26 ) ;
if ( V_39 )
V_39 = - V_56 ;
GOTO ( V_29 , V_39 ) ;
}
}
V_29:
if ( V_34 )
F_32 ( V_34 , V_26 ) ;
return V_39 ;
}
int F_33 ( void )
{
V_17 V_87 , V_88 ;
char V_34 [ 64 ] ;
int V_26 , V_89 = 0 ;
F_14 ( V_90 , L_35 , V_16 , V_91 , V_92 ) ;
F_14 ( V_90 , L_36 V_92 L_37 , ( V_17 ) V_93 ) ;
V_87 = V_93 ;
F_14 ( V_90 , L_38 V_92 L_37 , V_87 ) ;
if ( V_87 != V_93 ) {
F_7 ( L_39 V_92 L_40 ,
V_87 , ( int ) sizeof( V_87 ) ) ;
V_89 = - V_30 ;
}
V_26 = snprintf ( V_34 , sizeof( V_34 ) , V_92 , V_87 ) ;
if ( V_26 != 18 ) {
F_34 ( L_41 , V_34 , V_26 ) ;
V_89 = - V_30 ;
}
V_88 = V_93 ;
F_14 ( V_90 , L_38 V_92 L_37 , V_87 ) ;
if ( V_87 != V_93 ) {
F_7 ( L_39 V_92 L_40 ,
V_87 , ( int ) sizeof( V_87 ) ) ;
V_89 = - V_94 ;
}
if ( V_87 >> 8 != V_93 >> 8 ) {
F_7 ( L_39 V_92 L_40 ,
V_87 , ( int ) sizeof( V_87 ) ) ;
return - V_94 ;
}
if ( F_35 ( V_88 , 256 ) != ( V_87 & 255 ) ) {
F_7 ( L_42 V_92 L_43 V_16 L_37 , V_87 , V_87 & 255 ) ;
return - V_94 ;
}
if ( V_87 >> 8 != V_88 ) {
F_7 ( L_42 V_92 L_44 V_16 L_45 V_16 L_37 ,
V_87 , V_88 , V_87 >> 8 ) ;
return - V_94 ;
}
V_26 = snprintf ( V_34 , sizeof( V_34 ) , V_92 , V_87 ) ;
if ( V_26 != 18 ) {
F_34 ( L_41 , V_34 , V_26 ) ;
V_89 = - V_30 ;
}
V_26 = snprintf ( V_34 , sizeof( V_34 ) , V_16 , V_87 ) ;
if ( V_26 != 20 ) {
F_34 ( L_46 , V_34 , V_26 ) ;
V_89 = - V_30 ;
}
V_26 = snprintf ( V_34 , sizeof( V_34 ) , V_91 , V_87 ) ;
if ( V_26 != 2 ) {
F_34 ( L_47 , V_34 , V_26 ) ;
V_89 = - V_30 ;
}
if ( ( V_87 & ~ V_95 ) >= V_96 ) {
F_34 ( L_48 V_16 L_49 V_16 L_37 , V_87 ,
( V_17 ) V_96 ) ;
V_89 = - V_30 ;
}
return V_89 ;
}
static inline int F_36 ( void )
{ return 0 ; }
static inline int F_37 ( void )
{ return 0 ; }
static int T_3 F_38 ( void )
{
int V_97 , V_39 ;
int V_98 ( void ) ;
for ( V_97 = V_99 ; V_97 < V_100 ; V_97 ++ )
F_39 ( & V_101 [ V_97 ] ) ;
F_40 ( L_50 V_53 L_37 ) ;
F_41 ( & V_102 ) ;
F_42 () ;
V_103 = F_43 ( V_104 ,
V_105 |
V_106 ) ;
if ( V_103 == NULL ) {
F_7 ( L_51 ) ;
return - V_50 ;
}
F_44 ( V_103 , V_107 ,
V_108 ,
L_52 , L_53 ) ;
F_44 ( V_103 , V_109 ,
V_108 ,
L_54 , L_55 ) ;
V_39 = F_33 () ;
if ( V_39 == - V_94 )
return V_39 ;
F_45 () ;
V_39 = F_46 () ;
if ( V_39 )
return V_39 ;
F_39 ( & V_110 ) ;
V_39 = F_47 ( & V_111 ) ;
if ( V_39 ) {
F_7 ( L_56 , V_112 , V_39 ) ;
return V_39 ;
}
for ( V_97 = 0 ; V_97 < F_29 () ; V_97 ++ )
V_113 [ V_97 ] = NULL ;
if ( V_114 <= 512 << ( 20 - V_18 ) )
V_115 = V_114 / 4 ;
else
V_115 = V_114 / 2 ;
V_39 = F_48 () ;
if ( V_39 )
return V_39 ;
F_49 () ;
V_39 = F_36 () ;
if ( V_39 )
return V_39 ;
V_39 = F_50 () ;
if ( V_39 )
return V_39 ;
V_39 = F_51 () ;
if ( V_39 != 0 )
return V_39 ;
V_39 = F_52 () ;
if ( V_39 )
return V_39 ;
V_39 = V_98 () ;
return V_39 ;
}
void F_53 ( void )
{
V_17 V_116 , V_117 ;
V_116 = F_9 () ;
V_117 = F_8 () ;
F_54 ( & V_118 ) ;
if ( V_116 > V_119 )
V_119 = V_116 ;
if ( V_117 > V_120 )
V_120 = V_117 ;
F_55 ( & V_118 ) ;
}
V_17 F_56 ( void )
{
V_17 V_89 ;
F_54 ( & V_118 ) ;
V_89 = V_120 ;
F_55 ( & V_118 ) ;
return V_89 ;
}
V_17 F_57 ( void )
{
V_17 V_89 ;
F_54 ( & V_118 ) ;
V_89 = V_119 ;
F_55 ( & V_118 ) ;
return V_89 ;
}
static void F_58 ( void )
{
int V_97 ;
int V_121 ( void ) ;
V_17 V_122 , V_123 ;
V_17 V_124 , V_125 ;
V_121 () ;
F_59 ( & V_111 ) ;
for ( V_97 = 0 ; V_97 < F_29 () ; V_97 ++ ) {
struct V_37 * V_38 = F_26 ( V_97 ) ;
if ( V_38 && V_38 -> V_69 &&
F_60 ( V_38 ) && F_61 ( V_38 , V_126 ) ) {
F_30 ( V_38 -> V_79 == V_80 ) ;
F_61 ( V_38 , V_126 ) ( V_38 ) ;
}
}
F_62 () ;
F_63 () ;
F_64 () ;
F_65 () ;
F_66 () ;
F_37 () ;
F_67 () ;
F_68 () ;
F_69 () ;
V_122 = F_8 () ;
V_123 = F_9 () ;
V_124 = F_56 () ;
V_125 = F_57 () ;
F_70 ( & V_103 ) ;
F_14 ( ( V_122 ) ? V_127 : V_90 ,
L_57 V_16 L_58 V_16 L_37 ,
V_124 , V_122 ) ;
F_14 ( ( V_123 ) ? V_127 : V_90 ,
L_59 V_16 L_58 V_16 L_37 ,
V_125 , V_123 ) ;
}
