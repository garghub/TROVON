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
F_7 ( L_2 ,
V_10 ? L_3 : L_4 , type , V_11 , ( V_16 ) V_12 , V_13 ,
line ) ;
F_7 ( L_5
L_6 ,
F_8 () ,
F_9 () << V_17 ,
F_9 () ) ;
return 1 ;
}
return 0 ;
}
static inline void F_10 ( struct V_18 * V_19 ,
struct V_20 * V_21 )
{
memset ( V_19 , 0 , sizeof( * V_19 ) ) ;
V_19 -> V_22 = V_21 -> V_23 ;
}
static inline void F_11 ( struct V_20 * V_21 ,
struct V_18 * V_19 )
{
V_21 -> V_23 = V_19 -> V_22 ;
}
int F_12 ( T_2 V_24 , const char * V_11 )
{
int V_25 ;
int V_26 ;
if ( ! V_24 || ! V_11 ) {
F_7 ( L_7 ) ;
V_25 = - V_27 ;
goto V_28;
}
if ( V_11 [ V_24 - 1 ] != 0 ) {
F_7 ( L_8 ) ;
V_25 = - V_27 ;
goto V_28;
}
F_13 ( V_29 , L_9 , V_11 ) ;
V_26 = F_14 ( V_11 ) ;
if ( V_26 == - 1 ) {
F_13 ( V_29 , L_10 , V_11 ) ;
V_25 = - V_27 ;
goto V_28;
}
F_13 ( V_29 , L_11 , V_11 , V_26 ) ;
V_25 = V_26 ;
V_28:
return V_25 ;
}
int F_15 ( unsigned int V_30 , unsigned long V_31 )
{
char * V_32 = NULL ;
struct V_20 * V_21 ;
struct V_33 * V_34 ;
struct V_35 * V_36 = NULL ;
int V_37 = 0 , V_24 = 0 ;
if ( V_30 == V_38 ) {
V_34 = (struct V_33 * ) V_31 ;
V_39 = V_34 -> V_40 ;
V_41 = V_34 -> V_42 ;
return 0 ;
}
F_13 ( V_29 , L_12 , V_30 ) ;
if ( F_16 ( & V_32 , & V_24 , ( void * ) V_31 ) ) {
F_7 ( L_13 ) ;
return - V_27 ;
}
V_21 = (struct V_20 * ) V_32 ;
switch ( V_30 ) {
case V_43 : {
struct V_44 * V_45 ;
if ( ! V_21 -> V_46 || ! V_21 -> V_47 ) {
F_7 ( L_14 ) ;
V_37 = - V_27 ;
goto V_28;
}
V_45 = F_17 ( V_21 -> V_46 , V_48 ) ;
if ( ! V_45 ) {
V_37 = - V_49 ;
goto V_28;
}
V_37 = F_18 ( V_45 , V_21 -> V_47 ,
V_21 -> V_46 ) ;
if ( ! V_37 )
V_37 = F_19 ( V_45 , V_21 -> V_46 ) ;
if ( ! V_37 )
V_37 = F_20 ( V_45 ) ;
F_21 ( V_45 ) ;
goto V_28;
}
case V_50 :
if ( ! V_21 -> V_51 ) {
F_7 ( L_15 ) ;
V_37 = - V_27 ;
goto V_28;
}
if ( strlen ( V_52 ) + 1 > V_21 -> V_53 ) {
F_7 ( L_16 ) ;
V_37 = - V_27 ;
goto V_28;
}
memcpy ( V_21 -> V_54 , V_52 ,
strlen ( V_52 ) + 1 ) ;
V_37 = F_22 ( ( void * ) V_31 , V_21 , V_24 ) ;
if ( V_37 )
V_37 = - V_55 ;
goto V_28;
case V_56 : {
int V_26 ;
V_26 = F_12 ( V_21 -> V_53 ,
V_21 -> V_51 ) ;
V_21 -> V_57 = V_26 ;
if ( V_26 < 0 ) {
V_37 = - V_27 ;
goto V_28;
}
V_37 = F_22 ( ( void * ) V_31 , V_21 , sizeof( * V_21 ) ) ;
if ( V_37 )
V_37 = - V_55 ;
goto V_28;
}
case V_58 : {
int V_26 ;
struct V_59 V_60 ;
if ( ! V_21 -> V_53 || ! V_21 -> V_51 ) {
F_7 ( L_17 ) ;
V_37 = - V_27 ;
goto V_28;
}
if ( V_21 -> V_51 [ V_21 -> V_53 - 1 ] != 0 ) {
F_7 ( L_18 ) ;
V_37 = - V_27 ;
goto V_28;
}
F_13 ( V_29 , L_9 , V_21 -> V_51 ) ;
F_23 ( & V_60 , V_21 -> V_51 ) ;
V_26 = F_24 ( & V_60 ) ;
V_21 -> V_57 = V_26 ;
if ( V_26 == - 1 ) {
F_13 ( V_29 , L_19 ,
V_21 -> V_51 ) ;
V_37 = - V_27 ;
goto V_28;
}
F_13 ( V_29 , L_11 , V_21 -> V_51 ,
V_26 ) ;
V_37 = F_22 ( ( void * ) V_31 , V_21 , sizeof( * V_21 ) ) ;
if ( V_37 )
V_37 = - V_55 ;
goto V_28;
}
case V_61 : {
F_13 ( V_29 , L_20 ,
V_21 -> V_51 ) ;
V_37 = 0 ;
goto V_28;
}
case V_62 : {
int V_63 = V_21 -> V_64 ;
char * V_65 , * V_66 ;
if ( ! V_21 -> V_51 ) {
F_7 ( L_15 ) ;
V_37 = - V_27 ;
goto V_28;
}
if ( V_21 -> V_53 < 128 ) {
F_7 ( L_16 ) ;
V_37 = - V_27 ;
goto V_28;
}
V_36 = F_25 ( V_63 ) ;
if ( ! V_36 ) {
V_37 = - V_9 ;
goto V_28;
}
if ( V_36 -> V_67 )
V_65 = L_21 ;
else if ( V_36 -> V_68 )
V_65 = L_22 ;
else if ( V_36 -> V_69 )
V_65 = L_23 ;
else
V_65 = L_24 ;
V_66 = ( char * ) V_21 -> V_54 ;
snprintf ( V_66 , V_24 - sizeof( * V_21 ) , L_25 ,
( int ) V_63 , V_65 , V_36 -> V_70 -> V_71 ,
V_36 -> V_72 , V_36 -> V_59 . V_60 ,
F_26 ( & V_36 -> V_73 ) ) ;
V_37 = F_22 ( ( void * ) V_31 , V_21 , V_24 ) ;
V_37 = 0 ;
goto V_28;
}
}
if ( V_21 -> V_57 == V_74 ) {
if ( V_21 -> V_75 <= 0 || V_21 -> V_76 == NULL ) {
V_37 = - V_27 ;
goto V_28;
}
if ( F_27 ( V_21 -> V_76 , V_77 ) >= V_77 ) {
V_37 = - V_27 ;
goto V_28;
}
V_36 = F_28 ( V_21 -> V_76 ) ;
} else if ( V_21 -> V_57 < F_29 () ) {
V_36 = F_25 ( V_21 -> V_57 ) ;
} else {
F_7 ( L_26 ) ;
V_37 = - V_27 ;
goto V_28;
}
if ( V_36 == NULL ) {
F_7 ( L_27 , V_21 -> V_57 ) ;
V_37 = - V_27 ;
goto V_28;
}
F_30 ( V_36 -> V_78 == V_79 ) ;
if ( ! V_36 -> V_68 || V_36 -> V_67 ) {
F_7 ( L_28 , V_21 -> V_57 ) ;
V_37 = - V_27 ;
goto V_28;
}
switch ( V_30 ) {
case V_80 : {
if ( ! V_36 -> V_69 ) {
F_7 ( L_29 , V_36 -> V_81 ) ;
V_37 = - V_82 ;
goto V_28;
}
F_13 ( V_83 , L_30 ,
V_36 -> V_72 ) ;
V_36 -> V_84 = 1 ;
V_37 = 0 ;
goto V_28;
}
default: {
V_37 = F_31 ( V_30 , V_36 -> V_85 , V_24 , V_21 , NULL ) ;
if ( V_37 )
goto V_28;
V_37 = F_22 ( ( void * ) V_31 , V_21 , V_24 ) ;
if ( V_37 )
V_37 = - V_55 ;
goto V_28;
}
}
V_28:
if ( V_32 )
F_32 ( V_32 , V_24 ) ;
return V_37 ;
}
int F_33 ( void )
{
V_16 V_86 , V_87 ;
char V_32 [ 64 ] ;
int V_24 , V_88 = 0 ;
F_13 ( V_89 , L_31 , L_32 , L_33 , L_34 ) ;
F_13 ( V_89 , L_35 , ( V_16 ) V_90 ) ;
V_86 = V_90 ;
F_13 ( V_89 , L_36 , V_86 ) ;
if ( V_86 != V_90 ) {
F_7 ( L_37 ,
V_86 , ( int ) sizeof( V_86 ) ) ;
V_88 = - V_27 ;
}
V_24 = snprintf ( V_32 , sizeof( V_32 ) , L_34 , V_86 ) ;
if ( V_24 != 18 ) {
F_34 ( L_38 , V_32 , V_24 ) ;
V_88 = - V_27 ;
}
V_87 = V_90 ;
F_13 ( V_89 , L_36 , V_86 ) ;
if ( V_86 != V_90 ) {
F_7 ( L_37 ,
V_86 , ( int ) sizeof( V_86 ) ) ;
V_88 = - V_91 ;
}
if ( V_86 >> 8 != V_90 >> 8 ) {
F_7 ( L_37 ,
V_86 , ( int ) sizeof( V_86 ) ) ;
return - V_91 ;
}
if ( F_35 ( V_87 , 256 ) != ( V_86 & 255 ) ) {
F_7 ( L_39 , V_86 , V_86 & 255 ) ;
return - V_91 ;
}
if ( V_86 >> 8 != V_87 ) {
F_7 ( L_40 ,
V_86 , V_87 , V_86 >> 8 ) ;
return - V_91 ;
}
V_24 = snprintf ( V_32 , sizeof( V_32 ) , L_34 , V_86 ) ;
if ( V_24 != 18 ) {
F_34 ( L_38 , V_32 , V_24 ) ;
V_88 = - V_27 ;
}
V_24 = snprintf ( V_32 , sizeof( V_32 ) , L_32 , V_86 ) ;
if ( V_24 != 20 ) {
F_34 ( L_41 , V_32 , V_24 ) ;
V_88 = - V_27 ;
}
V_24 = snprintf ( V_32 , sizeof( V_32 ) , L_33 , V_86 ) ;
if ( V_24 != 2 ) {
F_34 ( L_42 , V_32 , V_24 ) ;
V_88 = - V_27 ;
}
if ( ( V_86 & ~ V_92 ) >= V_93 ) {
F_34 ( L_43 , V_86 ,
( V_16 ) V_93 ) ;
V_88 = - V_27 ;
}
return V_88 ;
}
static int T_3 F_36 ( void )
{
int V_94 , V_37 ;
int V_95 ( void ) ;
for ( V_94 = V_96 ; V_94 < V_97 ; V_94 ++ )
F_37 ( & V_98 [ V_94 ] ) ;
F_38 ( L_44 V_52 L_45 ) ;
F_39 ( & V_99 ) ;
F_40 () ;
V_100 = F_41 ( V_101 ,
V_102 |
V_103 ) ;
if ( V_100 == NULL ) {
F_7 ( L_46 ) ;
return - V_49 ;
}
F_42 ( V_100 , V_104 ,
V_105 ,
L_47 , L_48 ) ;
F_42 ( V_100 , V_106 ,
V_105 ,
L_49 , L_50 ) ;
V_37 = F_33 () ;
if ( V_37 == - V_91 )
return V_37 ;
F_43 () ;
V_37 = F_44 () ;
if ( V_37 )
return V_37 ;
F_37 ( & V_107 ) ;
V_37 = F_45 ( & V_108 ) ;
if ( V_37 ) {
F_7 ( L_51 , V_109 , V_37 ) ;
return V_37 ;
}
for ( V_94 = 0 ; V_94 < F_29 () ; V_94 ++ )
V_110 [ V_94 ] = NULL ;
if ( V_111 <= 512 << ( 20 - V_17 ) )
V_112 = V_111 / 4 ;
else
V_112 = V_111 / 2 ;
V_37 = F_46 () ;
if ( V_37 )
return V_37 ;
V_37 = F_47 () ;
if ( V_37 )
return V_37 ;
V_37 = F_48 () ;
if ( V_37 )
return V_37 ;
V_37 = F_49 () ;
if ( V_37 )
return V_37 ;
V_37 = F_50 () ;
if ( V_37 != 0 )
return V_37 ;
V_37 = F_51 () ;
if ( V_37 )
return V_37 ;
V_37 = V_95 () ;
return V_37 ;
}
void F_52 ( void )
{
V_16 V_113 , V_114 ;
V_113 = F_9 () ;
V_114 = F_8 () ;
F_53 ( & V_115 ) ;
if ( V_113 > V_116 )
V_116 = V_113 ;
if ( V_114 > V_117 )
V_117 = V_114 ;
F_54 ( & V_115 ) ;
}
V_16 F_55 ( void )
{
V_16 V_88 ;
F_53 ( & V_115 ) ;
V_88 = V_117 ;
F_54 ( & V_115 ) ;
return V_88 ;
}
V_16 F_56 ( void )
{
V_16 V_88 ;
F_53 ( & V_115 ) ;
V_88 = V_116 ;
F_54 ( & V_115 ) ;
return V_88 ;
}
static void F_57 ( void )
{
int V_94 ;
int V_118 ( void ) ;
V_16 V_119 , V_120 ;
V_16 V_121 , V_122 ;
V_118 () ;
F_58 ( & V_108 ) ;
for ( V_94 = 0 ; V_94 < F_29 () ; V_94 ++ ) {
struct V_35 * V_36 = F_25 ( V_94 ) ;
if ( V_36 && V_36 -> V_68 &&
F_59 ( V_36 ) && F_60 ( V_36 , V_123 ) ) {
F_30 ( V_36 -> V_78 == V_79 ) ;
F_60 ( V_36 , V_123 ) ( V_36 ) ;
}
}
F_61 () ;
F_62 () ;
F_63 () ;
F_64 () ;
F_65 () ;
F_66 () ;
F_67 () ;
F_68 () ;
V_119 = F_8 () ;
V_120 = F_9 () ;
V_121 = F_55 () ;
V_122 = F_56 () ;
F_69 ( & V_100 ) ;
F_13 ( ( V_119 ) ? V_124 : V_89 ,
L_52 ,
V_121 , V_119 ) ;
F_13 ( ( V_120 ) ? V_124 : V_89 ,
L_53 ,
V_122 , V_120 ) ;
}
