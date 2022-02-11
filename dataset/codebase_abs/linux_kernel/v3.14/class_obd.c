int F_1 ( char * V_1 )
{
int V_2 = V_3 ;
int V_4 = 0 ;
memset ( V_1 , 0 , V_3 ) ;
if ( strcmp ( V_5 , V_6 ) == 0 )
return 0 ;
if ( strcmp ( V_5 , V_7 ) == 0 ) {
snprintf ( V_1 , V_3 , L_1 ,
F_2 () ,
F_3 ( & V_8 , F_4 () ) ) ;
return 0 ;
}
V_4 = F_5 ( V_5 , V_1 , & V_2 ) ;
if ( V_4 ) {
if ( V_4 == - V_9 ) {
static bool V_10 ;
if ( F_6 ( ! V_10 ) ) {
F_7 ( 0x16b , L_2
L_3 ,
V_5 , V_2 ) ;
V_10 = true ;
}
} else {
F_8 ( ( V_4 == - V_11 || V_4 == - V_12 ||
V_4 == - V_13 ) ? V_14 : V_15 ,
L_4 ,
V_5 , V_4 ) ;
}
}
return V_4 ;
}
int F_9 ( const void * V_16 , const char * V_17 , const char * type ,
T_1 V_18 , const char * V_19 , int line )
{
if ( V_16 == NULL ||
( F_10 () & V_20 ) < V_21 ) {
F_11 ( L_5 V_22 L_6 ,
V_16 ? L_7 : L_8 , type , V_17 , ( V_23 ) V_18 , V_19 ,
line ) ;
F_11 ( V_22 L_9 V_22 L_10
L_11 V_22 L_12
L_13 ,
F_12 () ,
F_13 () << V_24 ,
F_13 () ,
F_14 ( & V_25 ) ) ;
return 1 ;
}
return 0 ;
}
static inline void F_15 ( struct V_26 * V_27 ,
struct V_28 * V_29 )
{
memset ( V_27 , 0 , sizeof( * V_27 ) ) ;
V_27 -> V_30 = V_29 -> V_31 ;
}
static inline void F_16 ( struct V_28 * V_29 ,
struct V_26 * V_27 )
{
V_29 -> V_31 = V_27 -> V_30 ;
}
int F_17 ( T_2 V_32 , const char * V_17 )
{
int V_4 ;
int V_33 ;
if ( ! V_32 || ! V_17 ) {
F_11 ( L_14 ) ;
GOTO ( V_34 , V_4 = - V_12 ) ;
}
if ( V_17 [ V_32 - 1 ] != 0 ) {
F_11 ( L_15 ) ;
GOTO ( V_34 , V_4 = - V_12 ) ;
}
F_8 ( V_35 , L_16 , V_17 ) ;
V_33 = F_18 ( V_17 ) ;
if ( V_33 == - 1 ) {
F_8 ( V_35 , L_17 , V_17 ) ;
GOTO ( V_34 , V_4 = - V_12 ) ;
}
F_8 ( V_35 , L_18 , V_17 , V_33 ) ;
V_4 = V_33 ;
V_34:
return V_4 ;
}
int F_19 ( unsigned int V_36 , unsigned long V_37 )
{
char * V_38 = NULL ;
struct V_28 * V_29 ;
struct V_39 * V_40 ;
struct V_41 * V_42 = NULL ;
int V_43 = 0 , V_32 = 0 ;
if ( V_36 == V_44 ) {
V_40 = (struct V_39 * ) V_37 ;
V_45 = V_40 -> V_46 ;
V_47 = V_40 -> V_48 ;
return 0 ;
}
F_8 ( V_35 , L_19 , V_36 ) ;
if ( F_20 ( & V_38 , & V_32 , ( void * ) V_37 ) ) {
F_11 ( L_20 ) ;
return - V_12 ;
}
V_29 = (struct V_28 * ) V_38 ;
switch ( V_36 ) {
case V_49 : {
struct V_50 * V_51 ;
if ( ! V_29 -> V_52 || ! V_29 -> V_53 ) {
F_11 ( L_21 ) ;
GOTO ( V_34 , V_43 = - V_12 ) ;
}
F_21 ( V_51 , V_29 -> V_52 ) ;
if ( V_51 == NULL )
GOTO ( V_34 , V_43 = - V_54 ) ;
V_43 = F_22 ( V_51 , V_29 -> V_53 ,
V_29 -> V_52 ) ;
if ( ! V_43 )
V_43 = F_23 ( V_51 , V_29 -> V_52 ) ;
if ( ! V_43 )
V_43 = F_24 ( V_51 ) ;
F_25 ( V_51 , V_29 -> V_52 ) ;
GOTO ( V_34 , V_43 ) ;
}
case V_55 :
if ( ! V_29 -> V_56 ) {
F_11 ( L_22 ) ;
GOTO ( V_34 , V_43 = - V_12 ) ;
}
if ( strlen ( V_57 ) + 1 > V_29 -> V_58 ) {
F_11 ( L_23 ) ;
GOTO ( V_34 , V_43 = - V_12 ) ;
}
memcpy ( V_29 -> V_59 , V_57 ,
strlen ( V_57 ) + 1 ) ;
V_43 = F_26 ( ( void * ) V_37 , V_29 , V_32 ) ;
if ( V_43 )
V_43 = - V_60 ;
GOTO ( V_34 , V_43 ) ;
case V_61 : {
int V_33 ;
V_33 = F_17 ( V_29 -> V_58 ,
V_29 -> V_56 ) ;
V_29 -> V_62 = V_33 ;
if ( V_33 < 0 )
GOTO ( V_34 , V_43 = - V_12 ) ;
V_43 = F_26 ( ( void * ) V_37 , V_29 , sizeof( * V_29 ) ) ;
if ( V_43 )
V_43 = - V_60 ;
GOTO ( V_34 , V_43 ) ;
}
case V_63 : {
int V_33 ;
struct V_64 V_65 ;
if ( ! V_29 -> V_58 || ! V_29 -> V_56 ) {
F_11 ( L_24 ) ;
GOTO ( V_34 , V_43 = - V_12 ) ;
}
if ( V_29 -> V_56 [ V_29 -> V_58 - 1 ] != 0 ) {
F_11 ( L_25 ) ;
GOTO ( V_34 , V_43 = - V_12 ) ;
}
F_8 ( V_35 , L_16 , V_29 -> V_56 ) ;
F_27 ( & V_65 , V_29 -> V_56 ) ;
V_33 = F_28 ( & V_65 ) ;
V_29 -> V_62 = V_33 ;
if ( V_33 == - 1 ) {
F_8 ( V_35 , L_26 ,
V_29 -> V_56 ) ;
GOTO ( V_34 , V_43 = - V_12 ) ;
}
F_8 ( V_35 , L_18 , V_29 -> V_56 ,
V_33 ) ;
V_43 = F_26 ( ( void * ) V_37 , V_29 , sizeof( * V_29 ) ) ;
if ( V_43 )
V_43 = - V_60 ;
GOTO ( V_34 , V_43 ) ;
}
case V_66 : {
F_8 ( V_35 , L_27 ,
V_29 -> V_56 ) ;
GOTO ( V_34 , V_43 = 0 ) ;
}
case V_67 : {
int V_68 = V_29 -> V_69 ;
char * V_70 , * V_71 ;
if ( ! V_29 -> V_56 ) {
F_11 ( L_22 ) ;
GOTO ( V_34 , V_43 = - V_12 ) ;
}
if ( V_29 -> V_58 < 128 ) {
F_11 ( L_23 ) ;
GOTO ( V_34 , V_43 = - V_12 ) ;
}
V_42 = F_29 ( V_68 ) ;
if ( ! V_42 )
GOTO ( V_34 , V_43 = - V_11 ) ;
if ( V_42 -> V_72 )
V_70 = L_28 ;
else if ( V_42 -> V_73 )
V_70 = L_29 ;
else if ( V_42 -> V_74 )
V_70 = L_30 ;
else
V_70 = L_31 ;
V_71 = ( char * ) V_29 -> V_59 ;
snprintf ( V_71 , V_32 - sizeof( * V_29 ) , L_32 ,
( int ) V_68 , V_70 , V_42 -> V_75 -> V_76 ,
V_42 -> V_77 , V_42 -> V_64 . V_65 ,
F_14 ( & V_42 -> V_78 ) ) ;
V_43 = F_26 ( ( void * ) V_37 , V_29 , V_32 ) ;
GOTO ( V_34 , V_43 = 0 ) ;
}
}
if ( V_29 -> V_62 == V_79 ) {
if ( V_29 -> V_80 <= 0 || V_29 -> V_81 == NULL )
GOTO ( V_34 , V_43 = - V_12 ) ;
if ( F_30 ( V_29 -> V_81 , V_82 ) >= V_82 )
GOTO ( V_34 , V_43 = - V_12 ) ;
V_42 = F_31 ( V_29 -> V_81 ) ;
} else if ( V_29 -> V_62 < F_32 () ) {
V_42 = F_29 ( V_29 -> V_62 ) ;
} else {
F_11 ( L_33 ) ;
GOTO ( V_34 , V_43 = - V_12 ) ;
}
if ( V_42 == NULL ) {
F_11 ( L_34 , V_29 -> V_62 ) ;
GOTO ( V_34 , V_43 = - V_12 ) ;
}
F_33 ( V_42 -> V_83 == V_84 ) ;
if ( ! V_42 -> V_73 || V_42 -> V_72 ) {
F_11 ( L_35 , V_29 -> V_62 ) ;
GOTO ( V_34 , V_43 = - V_12 ) ;
}
switch( V_36 ) {
case V_85 : {
if ( ! V_42 -> V_74 ) {
F_11 ( L_36 , V_42 -> V_86 ) ;
GOTO ( V_34 , V_43 = - V_87 ) ;
}
F_8 ( V_88 , L_37 ,
V_42 -> V_77 ) ;
V_42 -> V_89 = 1 ;
GOTO ( V_34 , V_43 = 0 ) ;
}
default: {
V_43 = F_34 ( V_36 , V_42 -> V_90 , V_32 , V_29 , NULL ) ;
if ( V_43 )
GOTO ( V_34 , V_43 ) ;
V_43 = F_26 ( ( void * ) V_37 , V_29 , V_32 ) ;
if ( V_43 )
V_43 = - V_60 ;
GOTO ( V_34 , V_43 ) ;
}
}
V_34:
if ( V_38 )
F_35 ( V_38 , V_32 ) ;
return V_43 ;
}
int F_36 ( void )
{
V_23 V_91 , V_92 ;
char V_38 [ 64 ] ;
int V_32 , V_93 = 0 ;
F_8 ( V_14 , L_38 , V_22 , V_94 , V_95 ) ;
F_8 ( V_14 , L_39 V_95 L_40 , ( V_23 ) V_96 ) ;
V_91 = V_96 ;
F_8 ( V_14 , L_41 V_95 L_40 , V_91 ) ;
if ( V_91 != V_96 ) {
F_11 ( L_42 V_95 L_43 ,
V_91 , ( int ) sizeof( V_91 ) ) ;
V_93 = - V_12 ;
}
V_32 = snprintf ( V_38 , sizeof( V_38 ) , V_95 , V_91 ) ;
if ( V_32 != 18 ) {
F_37 ( L_44 , V_38 , V_32 ) ;
V_93 = - V_12 ;
}
V_92 = V_96 ;
F_8 ( V_14 , L_41 V_95 L_40 , V_91 ) ;
if ( V_91 != V_96 ) {
F_11 ( L_42 V_95 L_43 ,
V_91 , ( int ) sizeof( V_91 ) ) ;
V_93 = - V_9 ;
}
if ( V_91 >> 8 != V_96 >> 8 ) {
F_11 ( L_42 V_95 L_43 ,
V_91 , ( int ) sizeof( V_91 ) ) ;
return - V_9 ;
}
if ( F_38 ( V_92 , 256 ) != ( V_91 & 255 ) ) {
F_11 ( L_45 V_95 L_46 V_22 L_40 , V_91 , V_91 & 255 ) ;
return - V_9 ;
}
if ( V_91 >> 8 != V_92 ) {
F_11 ( L_45 V_95 L_47 V_22 L_48 V_22 L_40 ,
V_91 , V_92 , V_91 >> 8 ) ;
return - V_9 ;
}
V_32 = snprintf ( V_38 , sizeof( V_38 ) , V_95 , V_91 ) ;
if ( V_32 != 18 ) {
F_37 ( L_44 , V_38 , V_32 ) ;
V_93 = - V_12 ;
}
V_32 = snprintf ( V_38 , sizeof( V_38 ) , V_22 , V_91 ) ;
if ( V_32 != 20 ) {
F_37 ( L_49 , V_38 , V_32 ) ;
V_93 = - V_12 ;
}
V_32 = snprintf ( V_38 , sizeof( V_38 ) , V_94 , V_91 ) ;
if ( V_32 != 2 ) {
F_37 ( L_50 , V_38 , V_32 ) ;
V_93 = - V_12 ;
}
if ( ( V_91 & ~ V_97 ) >= V_98 ) {
F_37 ( L_51 V_22 L_52 V_22 L_40 , V_91 ,
( V_23 ) V_98 ) ;
V_93 = - V_12 ;
}
return V_93 ;
}
static inline int F_39 ( void )
{ return 0 ; }
static inline int F_40 ( void )
{ return 0 ; }
static int T_3 F_41 ( void )
{
int V_99 , V_43 ;
int V_100 ( void ) ;
for ( V_99 = V_101 ; V_99 < V_102 ; V_99 ++ )
F_42 ( & V_103 [ V_99 ] ) ;
F_43 ( L_53 V_57 L_40 ) ;
F_44 ( & V_104 ) ;
F_45 () ;
V_105 = F_46 ( V_106 ,
V_107 |
V_108 ) ;
if ( V_105 == NULL ) {
F_11 ( L_54 ) ;
return - V_54 ;
}
F_47 ( V_105 , V_109 ,
V_110 ,
L_55 , L_56 ) ;
F_47 ( V_105 , V_111 ,
V_110 ,
L_57 , L_58 ) ;
V_43 = F_36 () ;
if ( V_43 == - V_9 )
return V_43 ;
F_48 () ;
V_43 = F_49 () ;
if ( V_43 )
return V_43 ;
F_42 ( & V_112 ) ;
V_43 = F_50 ( & V_113 ) ;
if ( V_43 ) {
F_11 ( L_59 , V_114 , V_43 ) ;
return V_43 ;
}
for ( V_99 = 0 ; V_99 < F_32 () ; V_99 ++ )
V_115 [ V_99 ] = NULL ;
if ( V_116 <= 512 << ( 20 - V_24 ) )
V_117 = V_116 / 4 ;
else
V_117 = V_116 / 2 ;
V_43 = F_51 () ;
if ( V_43 )
return V_43 ;
F_52 () ;
V_43 = F_39 () ;
if ( V_43 )
return V_43 ;
V_43 = F_53 () ;
if ( V_43 )
return V_43 ;
V_43 = F_54 () ;
if ( V_43 != 0 )
return V_43 ;
V_43 = F_55 () ;
if ( V_43 )
return V_43 ;
V_43 = V_100 () ;
return V_43 ;
}
void F_56 ( void )
{
V_23 V_118 , V_119 ;
V_118 = F_13 () ;
V_119 = F_12 () ;
F_57 ( & V_120 ) ;
if ( V_118 > V_121 )
V_121 = V_118 ;
if ( V_119 > V_122 )
V_122 = V_119 ;
F_58 ( & V_120 ) ;
}
V_23 F_59 ( void )
{
V_23 V_93 ;
F_57 ( & V_120 ) ;
V_93 = V_122 ;
F_58 ( & V_120 ) ;
return V_93 ;
}
V_23 F_60 ( void )
{
V_23 V_93 ;
F_57 ( & V_120 ) ;
V_93 = V_121 ;
F_58 ( & V_120 ) ;
return V_93 ;
}
static void F_61 ( void )
{
int V_99 ;
int V_123 ( void ) ;
V_23 V_124 , V_125 ;
V_23 V_126 , V_127 ;
V_123 () ;
F_62 ( & V_113 ) ;
for ( V_99 = 0 ; V_99 < F_32 () ; V_99 ++ ) {
struct V_41 * V_42 = F_29 ( V_99 ) ;
if ( V_42 && V_42 -> V_73 &&
F_63 ( V_42 ) && F_64 ( V_42 , V_128 ) ) {
F_33 ( V_42 -> V_83 == V_84 ) ;
F_64 ( V_42 , V_128 ) ( V_42 ) ;
}
}
F_65 () ;
F_66 () ;
F_67 () ;
F_68 () ;
F_69 () ;
F_40 () ;
F_70 () ;
F_71 () ;
F_72 () ;
V_124 = F_12 () ;
V_125 = F_13 () ;
V_126 = F_59 () ;
V_127 = F_60 () ;
F_73 ( & V_105 ) ;
F_8 ( ( V_124 ) ? V_15 : V_14 ,
L_60 V_22 L_61 V_22 L_40 ,
V_126 , V_124 ) ;
F_8 ( ( V_125 ) ? V_15 : V_14 ,
L_62 V_22 L_61 V_22 L_40 ,
V_127 , V_125 ) ;
}
