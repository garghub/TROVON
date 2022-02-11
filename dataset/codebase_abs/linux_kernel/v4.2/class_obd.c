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
F_7 ( L_5 ,
F_8 () ,
F_9 () << V_17 ,
F_9 () ,
F_10 ( & V_18 ) ) ;
return 1 ;
}
return 0 ;
}
static inline void F_11 ( struct V_19 * V_20 ,
struct V_21 * V_22 )
{
memset ( V_20 , 0 , sizeof( * V_20 ) ) ;
V_20 -> V_23 = V_22 -> V_24 ;
}
static inline void F_12 ( struct V_21 * V_22 ,
struct V_19 * V_20 )
{
V_22 -> V_24 = V_20 -> V_23 ;
}
int F_13 ( T_2 V_25 , const char * V_11 )
{
int V_26 ;
int V_27 ;
if ( ! V_25 || ! V_11 ) {
F_7 ( L_6 ) ;
V_26 = - V_28 ;
goto V_29;
}
if ( V_11 [ V_25 - 1 ] != 0 ) {
F_7 ( L_7 ) ;
V_26 = - V_28 ;
goto V_29;
}
F_14 ( V_30 , L_8 , V_11 ) ;
V_27 = F_15 ( V_11 ) ;
if ( V_27 == - 1 ) {
F_14 ( V_30 , L_9 , V_11 ) ;
V_26 = - V_28 ;
goto V_29;
}
F_14 ( V_30 , L_10 , V_11 , V_27 ) ;
V_26 = V_27 ;
V_29:
return V_26 ;
}
int F_16 ( unsigned int V_31 , unsigned long V_32 )
{
char * V_33 = NULL ;
struct V_21 * V_22 ;
struct V_34 * V_35 ;
struct V_36 * V_37 = NULL ;
int V_38 = 0 , V_25 = 0 ;
if ( V_31 == V_39 ) {
V_35 = (struct V_34 * ) V_32 ;
V_40 = V_35 -> V_41 ;
V_42 = V_35 -> V_43 ;
return 0 ;
}
F_14 ( V_30 , L_11 , V_31 ) ;
if ( F_17 ( & V_33 , & V_25 , ( void * ) V_32 ) ) {
F_7 ( L_12 ) ;
return - V_28 ;
}
V_22 = (struct V_21 * ) V_33 ;
switch ( V_31 ) {
case V_44 : {
struct V_45 * V_46 ;
if ( ! V_22 -> V_47 || ! V_22 -> V_48 ) {
F_7 ( L_13 ) ;
V_38 = - V_28 ;
goto V_29;
}
V_46 = F_18 ( V_22 -> V_47 , V_49 ) ;
if ( V_46 == NULL ) {
V_38 = - V_50 ;
goto V_29;
}
V_38 = F_19 ( V_46 , V_22 -> V_48 ,
V_22 -> V_47 ) ;
if ( ! V_38 )
V_38 = F_20 ( V_46 , V_22 -> V_47 ) ;
if ( ! V_38 )
V_38 = F_21 ( V_46 ) ;
F_22 ( V_46 ) ;
goto V_29;
}
case V_51 :
if ( ! V_22 -> V_52 ) {
F_7 ( L_14 ) ;
V_38 = - V_28 ;
goto V_29;
}
if ( strlen ( V_53 ) + 1 > V_22 -> V_54 ) {
F_7 ( L_15 ) ;
V_38 = - V_28 ;
goto V_29;
}
memcpy ( V_22 -> V_55 , V_53 ,
strlen ( V_53 ) + 1 ) ;
V_38 = F_23 ( ( void * ) V_32 , V_22 , V_25 ) ;
if ( V_38 )
V_38 = - V_56 ;
goto V_29;
case V_57 : {
int V_27 ;
V_27 = F_13 ( V_22 -> V_54 ,
V_22 -> V_52 ) ;
V_22 -> V_58 = V_27 ;
if ( V_27 < 0 ) {
V_38 = - V_28 ;
goto V_29;
}
V_38 = F_23 ( ( void * ) V_32 , V_22 , sizeof( * V_22 ) ) ;
if ( V_38 )
V_38 = - V_56 ;
goto V_29;
}
case V_59 : {
int V_27 ;
struct V_60 V_61 ;
if ( ! V_22 -> V_54 || ! V_22 -> V_52 ) {
F_7 ( L_16 ) ;
V_38 = - V_28 ;
goto V_29;
}
if ( V_22 -> V_52 [ V_22 -> V_54 - 1 ] != 0 ) {
F_7 ( L_17 ) ;
V_38 = - V_28 ;
goto V_29;
}
F_14 ( V_30 , L_8 , V_22 -> V_52 ) ;
F_24 ( & V_61 , V_22 -> V_52 ) ;
V_27 = F_25 ( & V_61 ) ;
V_22 -> V_58 = V_27 ;
if ( V_27 == - 1 ) {
F_14 ( V_30 , L_18 ,
V_22 -> V_52 ) ;
V_38 = - V_28 ;
goto V_29;
}
F_14 ( V_30 , L_10 , V_22 -> V_52 ,
V_27 ) ;
V_38 = F_23 ( ( void * ) V_32 , V_22 , sizeof( * V_22 ) ) ;
if ( V_38 )
V_38 = - V_56 ;
goto V_29;
}
case V_62 : {
F_14 ( V_30 , L_19 ,
V_22 -> V_52 ) ;
V_38 = 0 ;
goto V_29;
}
case V_63 : {
int V_64 = V_22 -> V_65 ;
char * V_66 , * V_67 ;
if ( ! V_22 -> V_52 ) {
F_7 ( L_14 ) ;
V_38 = - V_28 ;
goto V_29;
}
if ( V_22 -> V_54 < 128 ) {
F_7 ( L_15 ) ;
V_38 = - V_28 ;
goto V_29;
}
V_37 = F_26 ( V_64 ) ;
if ( ! V_37 ) {
V_38 = - V_9 ;
goto V_29;
}
if ( V_37 -> V_68 )
V_66 = L_20 ;
else if ( V_37 -> V_69 )
V_66 = L_21 ;
else if ( V_37 -> V_70 )
V_66 = L_22 ;
else
V_66 = L_23 ;
V_67 = ( char * ) V_22 -> V_55 ;
snprintf ( V_67 , V_25 - sizeof( * V_22 ) , L_24 ,
( int ) V_64 , V_66 , V_37 -> V_71 -> V_72 ,
V_37 -> V_73 , V_37 -> V_60 . V_61 ,
F_10 ( & V_37 -> V_74 ) ) ;
V_38 = F_23 ( ( void * ) V_32 , V_22 , V_25 ) ;
V_38 = 0 ;
goto V_29;
}
}
if ( V_22 -> V_58 == V_75 ) {
if ( V_22 -> V_76 <= 0 || V_22 -> V_77 == NULL ) {
V_38 = - V_28 ;
goto V_29;
}
if ( F_27 ( V_22 -> V_77 , V_78 ) >= V_78 ) {
V_38 = - V_28 ;
goto V_29;
}
V_37 = F_28 ( V_22 -> V_77 ) ;
} else if ( V_22 -> V_58 < F_29 () ) {
V_37 = F_26 ( V_22 -> V_58 ) ;
} else {
F_7 ( L_25 ) ;
V_38 = - V_28 ;
goto V_29;
}
if ( V_37 == NULL ) {
F_7 ( L_26 , V_22 -> V_58 ) ;
V_38 = - V_28 ;
goto V_29;
}
F_30 ( V_37 -> V_79 == V_80 ) ;
if ( ! V_37 -> V_69 || V_37 -> V_68 ) {
F_7 ( L_27 , V_22 -> V_58 ) ;
V_38 = - V_28 ;
goto V_29;
}
switch ( V_31 ) {
case V_81 : {
if ( ! V_37 -> V_70 ) {
F_7 ( L_28 , V_37 -> V_82 ) ;
V_38 = - V_83 ;
goto V_29;
}
F_14 ( V_84 , L_29 ,
V_37 -> V_73 ) ;
V_37 -> V_85 = 1 ;
V_38 = 0 ;
goto V_29;
}
default: {
V_38 = F_31 ( V_31 , V_37 -> V_86 , V_25 , V_22 , NULL ) ;
if ( V_38 )
goto V_29;
V_38 = F_23 ( ( void * ) V_32 , V_22 , V_25 ) ;
if ( V_38 )
V_38 = - V_56 ;
goto V_29;
}
}
V_29:
if ( V_33 )
F_32 ( V_33 , V_25 ) ;
return V_38 ;
}
int F_33 ( void )
{
V_16 V_87 , V_88 ;
char V_33 [ 64 ] ;
int V_25 , V_89 = 0 ;
F_14 ( V_90 , L_30 , L_31 , L_32 , L_33 ) ;
F_14 ( V_90 , L_34 , ( V_16 ) V_91 ) ;
V_87 = V_91 ;
F_14 ( V_90 , L_35 , V_87 ) ;
if ( V_87 != V_91 ) {
F_7 ( L_36 ,
V_87 , ( int ) sizeof( V_87 ) ) ;
V_89 = - V_28 ;
}
V_25 = snprintf ( V_33 , sizeof( V_33 ) , L_33 , V_87 ) ;
if ( V_25 != 18 ) {
F_34 ( L_37 , V_33 , V_25 ) ;
V_89 = - V_28 ;
}
V_88 = V_91 ;
F_14 ( V_90 , L_35 , V_87 ) ;
if ( V_87 != V_91 ) {
F_7 ( L_36 ,
V_87 , ( int ) sizeof( V_87 ) ) ;
V_89 = - V_92 ;
}
if ( V_87 >> 8 != V_91 >> 8 ) {
F_7 ( L_36 ,
V_87 , ( int ) sizeof( V_87 ) ) ;
return - V_92 ;
}
if ( F_35 ( V_88 , 256 ) != ( V_87 & 255 ) ) {
F_7 ( L_38 , V_87 , V_87 & 255 ) ;
return - V_92 ;
}
if ( V_87 >> 8 != V_88 ) {
F_7 ( L_39 ,
V_87 , V_88 , V_87 >> 8 ) ;
return - V_92 ;
}
V_25 = snprintf ( V_33 , sizeof( V_33 ) , L_33 , V_87 ) ;
if ( V_25 != 18 ) {
F_34 ( L_37 , V_33 , V_25 ) ;
V_89 = - V_28 ;
}
V_25 = snprintf ( V_33 , sizeof( V_33 ) , L_31 , V_87 ) ;
if ( V_25 != 20 ) {
F_34 ( L_40 , V_33 , V_25 ) ;
V_89 = - V_28 ;
}
V_25 = snprintf ( V_33 , sizeof( V_33 ) , L_32 , V_87 ) ;
if ( V_25 != 2 ) {
F_34 ( L_41 , V_33 , V_25 ) ;
V_89 = - V_28 ;
}
if ( ( V_87 & ~ V_93 ) >= V_94 ) {
F_34 ( L_42 , V_87 ,
( V_16 ) V_94 ) ;
V_89 = - V_28 ;
}
return V_89 ;
}
static int T_3 F_36 ( void )
{
int V_95 , V_38 ;
int V_96 ( void ) ;
for ( V_95 = V_97 ; V_95 < V_98 ; V_95 ++ )
F_37 ( & V_99 [ V_95 ] ) ;
F_38 ( L_43 V_53 L_44 ) ;
F_39 ( & V_100 ) ;
F_40 () ;
V_101 = F_41 ( V_102 ,
V_103 |
V_104 ) ;
if ( V_101 == NULL ) {
F_7 ( L_45 ) ;
return - V_50 ;
}
F_42 ( V_101 , V_105 ,
V_106 ,
L_46 , L_47 ) ;
F_42 ( V_101 , V_107 ,
V_106 ,
L_48 , L_49 ) ;
V_38 = F_33 () ;
if ( V_38 == - V_92 )
return V_38 ;
F_43 () ;
V_38 = F_44 () ;
if ( V_38 )
return V_38 ;
F_37 ( & V_108 ) ;
V_38 = F_45 ( & V_109 ) ;
if ( V_38 ) {
F_7 ( L_50 , V_110 , V_38 ) ;
return V_38 ;
}
for ( V_95 = 0 ; V_95 < F_29 () ; V_95 ++ )
V_111 [ V_95 ] = NULL ;
if ( V_112 <= 512 << ( 20 - V_17 ) )
V_113 = V_112 / 4 ;
else
V_113 = V_112 / 2 ;
V_38 = F_46 () ;
if ( V_38 )
return V_38 ;
F_47 () ;
V_38 = F_48 () ;
if ( V_38 )
return V_38 ;
V_38 = F_49 () ;
if ( V_38 )
return V_38 ;
V_38 = F_50 () ;
if ( V_38 != 0 )
return V_38 ;
V_38 = F_51 () ;
if ( V_38 )
return V_38 ;
V_38 = V_96 () ;
return V_38 ;
}
void F_52 ( void )
{
V_16 V_114 , V_115 ;
V_114 = F_9 () ;
V_115 = F_8 () ;
F_53 ( & V_116 ) ;
if ( V_114 > V_117 )
V_117 = V_114 ;
if ( V_115 > V_118 )
V_118 = V_115 ;
F_54 ( & V_116 ) ;
}
V_16 F_55 ( void )
{
V_16 V_89 ;
F_53 ( & V_116 ) ;
V_89 = V_118 ;
F_54 ( & V_116 ) ;
return V_89 ;
}
V_16 F_56 ( void )
{
V_16 V_89 ;
F_53 ( & V_116 ) ;
V_89 = V_117 ;
F_54 ( & V_116 ) ;
return V_89 ;
}
static void F_57 ( void )
{
int V_95 ;
int V_119 ( void ) ;
V_16 V_120 , V_121 ;
V_16 V_122 , V_123 ;
V_119 () ;
F_58 ( & V_109 ) ;
for ( V_95 = 0 ; V_95 < F_29 () ; V_95 ++ ) {
struct V_36 * V_37 = F_26 ( V_95 ) ;
if ( V_37 && V_37 -> V_69 &&
F_59 ( V_37 ) && F_60 ( V_37 , V_124 ) ) {
F_30 ( V_37 -> V_79 == V_80 ) ;
F_60 ( V_37 , V_124 ) ( V_37 ) ;
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
F_69 () ;
V_120 = F_8 () ;
V_121 = F_9 () ;
V_122 = F_55 () ;
V_123 = F_56 () ;
F_70 ( & V_101 ) ;
F_14 ( ( V_120 ) ? V_125 : V_90 ,
L_51 ,
V_122 , V_120 ) ;
F_14 ( ( V_121 ) ? V_125 : V_90 ,
L_52 ,
V_123 , V_121 ) ;
}
