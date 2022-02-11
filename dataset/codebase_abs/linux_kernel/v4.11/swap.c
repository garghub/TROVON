static inline unsigned long F_1 ( void )
{
return F_2 () - F_3 () ;
}
static inline unsigned long F_4 ( void )
{
return F_1 () / 2 ;
}
static int F_5 ( unsigned long V_1 )
{
struct V_2 * * V_3 = & ( V_4 . V_2 ) ;
struct V_2 * V_5 = NULL ;
struct V_6 * V_7 ;
while ( * V_3 ) {
V_7 = F_6 ( * V_3 , struct V_6 , V_8 ) ;
V_5 = * V_3 ;
if ( V_1 < V_7 -> V_9 ) {
if ( V_1 == V_7 -> V_9 - 1 ) {
V_7 -> V_9 -- ;
return 0 ;
}
V_3 = & ( ( * V_3 ) -> V_10 ) ;
} else if ( V_1 > V_7 -> V_11 ) {
if ( V_1 == V_7 -> V_11 + 1 ) {
V_7 -> V_11 ++ ;
return 0 ;
}
V_3 = & ( ( * V_3 ) -> V_12 ) ;
} else {
return - V_13 ;
}
}
V_7 = F_7 ( sizeof( struct V_6 ) , V_14 ) ;
if ( ! V_7 )
return - V_15 ;
V_7 -> V_9 = V_1 ;
V_7 -> V_11 = V_1 ;
F_8 ( & V_7 -> V_8 , V_5 , V_3 ) ;
F_9 ( & V_7 -> V_8 , & V_4 ) ;
return 0 ;
}
T_1 F_10 ( int V_16 )
{
unsigned long V_17 ;
V_17 = F_11 ( F_12 ( V_16 ) ) ;
if ( V_17 ) {
if ( F_5 ( V_17 ) )
F_13 ( F_14 ( V_16 , V_17 ) ) ;
else
return F_15 ( V_16 , V_17 ) ;
}
return 0 ;
}
void F_16 ( int V_16 )
{
struct V_2 * V_8 ;
while ( ( V_8 = V_4 . V_2 ) ) {
struct V_6 * V_7 ;
unsigned long V_17 ;
V_7 = F_6 ( V_8 , struct V_6 , V_8 ) ;
F_17 ( V_8 , & V_4 ) ;
for ( V_17 = V_7 -> V_9 ; V_17 <= V_7 -> V_11 ; V_17 ++ )
F_13 ( F_14 ( V_16 , V_17 ) ) ;
F_18 ( V_7 ) ;
}
}
int F_19 ( void )
{
return ( V_4 . V_2 != NULL ) ;
}
static void F_20 ( struct V_18 * V_19 )
{
F_21 ( & V_19 -> V_20 , 0 ) ;
F_22 ( & V_19 -> V_21 ) ;
V_19 -> error = 0 ;
}
static void F_23 ( struct V_22 * V_22 )
{
struct V_18 * V_19 = V_22 -> V_23 ;
struct V_24 * V_24 = V_22 -> V_25 [ 0 ] . V_26 ;
if ( V_22 -> V_27 ) {
F_24 ( V_28 L_1 ,
F_25 ( V_22 -> V_29 -> V_30 ) ,
F_26 ( V_22 -> V_29 -> V_30 ) ,
( unsigned long long ) V_22 -> V_31 . V_32 ) ;
}
if ( F_27 ( V_22 ) == V_33 )
F_28 ( V_24 ) ;
else if ( V_34 )
F_29 ( ( unsigned long ) F_30 ( V_24 ) ,
( unsigned long ) F_30 ( V_24 ) + V_35 ) ;
if ( V_22 -> V_27 && ! V_19 -> error )
V_19 -> error = V_22 -> V_27 ;
if ( F_31 ( & V_19 -> V_20 ) )
F_32 ( & V_19 -> V_21 ) ;
F_33 ( V_22 ) ;
}
static int F_34 ( int V_36 , int V_37 , T_2 V_38 , void * V_39 ,
struct V_18 * V_19 )
{
struct V_24 * V_24 = F_35 ( V_39 ) ;
struct V_22 * V_22 ;
int error = 0 ;
V_22 = F_36 ( V_40 | V_41 , 1 ) ;
V_22 -> V_31 . V_32 = V_38 * ( V_35 >> 9 ) ;
V_22 -> V_29 = V_42 ;
F_37 ( V_22 , V_36 , V_37 ) ;
if ( F_38 ( V_22 , V_24 , V_35 , 0 ) < V_35 ) {
F_24 ( V_43 L_2 ,
( unsigned long long ) V_22 -> V_31 . V_32 ) ;
F_33 ( V_22 ) ;
return - V_44 ;
}
if ( V_19 ) {
V_22 -> V_45 = F_23 ;
V_22 -> V_23 = V_19 ;
F_39 ( & V_19 -> V_20 ) ;
F_40 ( V_22 ) ;
} else {
error = F_41 ( V_22 ) ;
F_33 ( V_22 ) ;
}
return error ;
}
static int F_42 ( struct V_18 * V_19 )
{
F_43 ( V_19 -> V_21 , F_44 ( & V_19 -> V_20 ) == 0 ) ;
return V_19 -> error ;
}
static int F_45 ( struct V_46 * V_47 , unsigned int V_48 )
{
int error ;
F_34 ( V_49 , 0 , V_50 ,
V_51 , NULL ) ;
if ( ! memcmp ( L_3 , V_51 -> V_52 , 10 ) ||
! memcmp ( L_4 , V_51 -> V_52 , 10 ) ) {
memcpy ( V_51 -> V_53 , V_51 -> V_52 , 10 ) ;
memcpy ( V_51 -> V_52 , V_54 , 10 ) ;
V_51 -> V_55 = V_47 -> V_56 ;
V_51 -> V_48 = V_48 ;
if ( V_48 & V_57 )
V_51 -> V_58 = V_47 -> V_58 ;
error = F_34 ( V_59 , V_60 ,
V_50 , V_51 , NULL ) ;
} else {
F_24 ( V_43 L_5 ) ;
error = - V_61 ;
}
return error ;
}
static int F_46 ( void )
{
int V_62 ;
V_62 = F_47 ( V_63 , V_50 ,
& V_42 ) ;
if ( V_62 < 0 )
return V_62 ;
V_64 = V_62 ;
V_62 = F_48 ( V_42 , V_65 , NULL ) ;
if ( V_62 )
return V_62 ;
V_62 = F_49 ( V_42 , V_35 ) ;
if ( V_62 < 0 )
F_50 ( V_42 , V_65 ) ;
V_63 = V_42 -> V_66 ;
return V_62 ;
}
static int F_51 ( void * V_67 , T_1 V_17 , struct V_18 * V_19 )
{
void * V_68 ;
int V_69 ;
if ( ! V_17 )
return - V_70 ;
if ( V_19 ) {
V_68 = ( void * ) F_52 ( V_40 | V_71 |
V_72 ) ;
if ( V_68 ) {
F_53 ( V_68 , V_67 ) ;
} else {
V_69 = F_42 ( V_19 ) ;
if ( V_69 )
return V_69 ;
V_68 = ( void * ) F_52 ( V_40 |
V_71 |
V_72 ) ;
if ( V_68 ) {
F_53 ( V_68 , V_67 ) ;
} else {
F_54 ( 1 ) ;
V_19 = NULL ;
V_68 = V_67 ;
}
}
} else {
V_68 = V_67 ;
}
return F_34 ( V_59 , V_60 , V_17 , V_68 , V_19 ) ;
}
static void F_55 ( struct V_46 * V_47 )
{
if ( V_47 -> V_73 )
F_56 ( ( unsigned long ) V_47 -> V_73 ) ;
V_47 -> V_73 = NULL ;
}
static int F_57 ( struct V_46 * V_47 )
{
int V_69 ;
V_69 = F_46 () ;
if ( V_69 ) {
if ( V_69 != - V_70 )
F_24 ( V_43 L_6
L_7 ) ;
return V_69 ;
}
V_47 -> V_73 = (struct V_74 * ) F_58 ( V_14 ) ;
if ( ! V_47 -> V_73 ) {
V_69 = - V_15 ;
goto V_75;
}
V_47 -> V_76 = F_10 ( V_64 ) ;
if ( ! V_47 -> V_76 ) {
V_69 = - V_70 ;
goto V_77;
}
V_47 -> V_78 = 0 ;
V_47 -> F_4 = F_4 () ;
V_47 -> V_56 = V_47 -> V_76 ;
return 0 ;
V_77:
F_55 ( V_47 ) ;
V_75:
F_59 ( V_65 ) ;
return V_69 ;
}
static int F_60 ( struct V_46 * V_47 , void * V_67 ,
struct V_18 * V_19 )
{
int error = 0 ;
T_1 V_17 ;
if ( ! V_47 -> V_73 )
return - V_13 ;
V_17 = F_10 ( V_64 ) ;
error = F_51 ( V_67 , V_17 , V_19 ) ;
if ( error )
return error ;
V_47 -> V_73 -> V_79 [ V_47 -> V_78 ++ ] = V_17 ;
if ( V_47 -> V_78 >= V_80 ) {
V_17 = F_10 ( V_64 ) ;
if ( ! V_17 )
return - V_70 ;
V_47 -> V_73 -> V_81 = V_17 ;
error = F_51 ( V_47 -> V_73 , V_47 -> V_76 , V_19 ) ;
if ( error )
goto V_82;
F_61 ( V_47 -> V_73 ) ;
V_47 -> V_76 = V_17 ;
V_47 -> V_78 = 0 ;
if ( V_19 && F_1 () <= V_47 -> F_4 ) {
error = F_42 ( V_19 ) ;
if ( error )
goto V_82;
V_47 -> F_4 = F_4 () ;
}
}
V_82:
return error ;
}
static int F_62 ( struct V_46 * V_47 )
{
if ( V_47 -> V_73 && V_47 -> V_76 )
return F_51 ( V_47 -> V_73 , V_47 -> V_76 , NULL ) ;
else
return - V_13 ;
}
static int F_63 ( struct V_46 * V_47 ,
unsigned int V_48 , int error )
{
if ( ! error ) {
F_62 ( V_47 ) ;
F_24 ( V_83 L_8 ) ;
error = F_45 ( V_47 , V_48 ) ;
F_24 ( L_9 ) ;
}
if ( error )
F_16 ( V_64 ) ;
F_55 ( V_47 ) ;
F_59 ( V_65 ) ;
return error ;
}
static int F_64 ( struct V_46 * V_47 ,
struct V_84 * V_85 ,
unsigned int V_86 )
{
unsigned int V_87 ;
int V_69 ;
int V_88 ;
int V_89 ;
struct V_18 V_19 ;
T_3 V_9 ;
T_3 V_90 ;
F_20 ( & V_19 ) ;
F_24 ( V_83 L_10 ,
V_86 ) ;
V_87 = V_86 / 10 ;
if ( ! V_87 )
V_87 = 1 ;
V_88 = 0 ;
V_9 = F_65 () ;
while ( 1 ) {
V_69 = F_66 ( V_85 ) ;
if ( V_69 <= 0 )
break;
V_69 = F_60 ( V_47 , F_67 ( * V_85 ) , & V_19 ) ;
if ( V_69 )
break;
if ( ! ( V_88 % V_87 ) )
F_24 ( V_83 L_11 ,
V_88 / V_87 * 10 ) ;
V_88 ++ ;
}
V_89 = F_42 ( & V_19 ) ;
V_90 = F_65 () ;
if ( ! V_69 )
V_69 = V_89 ;
if ( ! V_69 )
F_24 ( V_83 L_12 ) ;
F_68 ( V_9 , V_90 , V_86 , L_13 ) ;
return V_69 ;
}
static int F_69 ( void * V_91 )
{
struct V_92 * V_93 = V_91 ;
unsigned V_94 ;
while ( 1 ) {
F_43 ( V_93 -> V_95 , F_44 ( & V_93 -> V_96 ) ||
F_70 () ) ;
if ( F_70 () ) {
V_93 -> V_97 = NULL ;
F_21 ( & V_93 -> V_90 , 1 ) ;
F_32 ( & V_93 -> V_98 ) ;
break;
}
F_21 ( & V_93 -> V_96 , 0 ) ;
for ( V_94 = 0 ; V_94 < V_93 -> V_99 ; V_94 ++ )
* V_93 -> V_58 = F_71 ( * V_93 -> V_58 ,
V_93 -> V_100 [ V_94 ] , * V_93 -> V_101 [ V_94 ] ) ;
F_21 ( & V_93 -> V_90 , 1 ) ;
F_32 ( & V_93 -> V_98 ) ;
}
return 0 ;
}
static int F_72 ( void * V_91 )
{
struct V_102 * V_93 = V_91 ;
while ( 1 ) {
F_43 ( V_93 -> V_95 , F_44 ( & V_93 -> V_96 ) ||
F_70 () ) ;
if ( F_70 () ) {
V_93 -> V_97 = NULL ;
V_93 -> V_69 = - 1 ;
F_21 ( & V_93 -> V_90 , 1 ) ;
F_32 ( & V_93 -> V_98 ) ;
break;
}
F_21 ( & V_93 -> V_96 , 0 ) ;
V_93 -> V_69 = F_73 ( V_93 -> V_100 , V_93 -> V_101 ,
V_93 -> V_103 + V_104 , & V_93 -> V_105 ,
V_93 -> V_106 ) ;
F_21 ( & V_93 -> V_90 , 1 ) ;
F_32 ( & V_93 -> V_98 ) ;
}
return 0 ;
}
static int F_74 ( struct V_46 * V_47 ,
struct V_84 * V_85 ,
unsigned int V_86 )
{
unsigned int V_87 ;
int V_69 = 0 ;
int V_88 ;
int V_89 ;
struct V_18 V_19 ;
T_3 V_9 ;
T_3 V_90 ;
T_4 V_107 ;
unsigned V_97 , V_99 , V_108 ;
unsigned char * V_24 = NULL ;
struct V_102 * V_91 = NULL ;
struct V_92 * V_109 = NULL ;
F_20 ( & V_19 ) ;
V_108 = F_75 () - 1 ;
V_108 = F_76 ( V_108 , 1 , V_110 ) ;
V_24 = ( void * ) F_52 ( V_40 | V_41 ) ;
if ( ! V_24 ) {
F_24 ( V_43 L_14 ) ;
V_69 = - V_15 ;
goto V_111;
}
V_91 = F_77 ( sizeof( * V_91 ) * V_108 ) ;
if ( ! V_91 ) {
F_24 ( V_43 L_15 ) ;
V_69 = - V_15 ;
goto V_111;
}
for ( V_97 = 0 ; V_97 < V_108 ; V_97 ++ )
memset ( & V_91 [ V_97 ] , 0 , F_78 ( struct V_102 , V_95 ) ) ;
V_109 = F_79 ( sizeof( * V_109 ) , V_14 ) ;
if ( ! V_109 ) {
F_24 ( V_43 L_16 ) ;
V_69 = - V_15 ;
goto V_111;
}
memset ( V_109 , 0 , F_78 ( struct V_92 , V_95 ) ) ;
for ( V_97 = 0 ; V_97 < V_108 ; V_97 ++ ) {
F_22 ( & V_91 [ V_97 ] . V_95 ) ;
F_22 ( & V_91 [ V_97 ] . V_98 ) ;
V_91 [ V_97 ] . V_97 = F_80 ( F_72 ,
& V_91 [ V_97 ] ,
L_17 , V_97 ) ;
if ( F_81 ( V_91 [ V_97 ] . V_97 ) ) {
V_91 [ V_97 ] . V_97 = NULL ;
F_24 ( V_43
L_18 ) ;
V_69 = - V_15 ;
goto V_111;
}
}
F_22 ( & V_109 -> V_95 ) ;
F_22 ( & V_109 -> V_98 ) ;
V_47 -> V_58 = 0 ;
V_109 -> V_58 = & V_47 -> V_58 ;
for ( V_97 = 0 ; V_97 < V_108 ; V_97 ++ ) {
V_109 -> V_100 [ V_97 ] = V_91 [ V_97 ] . V_100 ;
V_109 -> V_101 [ V_97 ] = & V_91 [ V_97 ] . V_101 ;
}
V_109 -> V_97 = F_80 ( F_69 , V_109 , L_19 ) ;
if ( F_81 ( V_109 -> V_97 ) ) {
V_109 -> V_97 = NULL ;
F_24 ( V_43 L_20 ) ;
V_69 = - V_15 ;
goto V_111;
}
V_47 -> F_4 = F_4 () ;
F_24 ( V_83
L_21
L_22 ,
V_108 , V_86 ) ;
V_87 = V_86 / 10 ;
if ( ! V_87 )
V_87 = 1 ;
V_88 = 0 ;
V_9 = F_65 () ;
for (; ; ) {
for ( V_97 = 0 ; V_97 < V_108 ; V_97 ++ ) {
for ( V_107 = 0 ; V_107 < V_112 ; V_107 += V_35 ) {
V_69 = F_66 ( V_85 ) ;
if ( V_69 < 0 )
goto V_113;
if ( ! V_69 )
break;
memcpy ( V_91 [ V_97 ] . V_100 + V_107 ,
F_67 ( * V_85 ) , V_35 ) ;
if ( ! ( V_88 % V_87 ) )
F_24 ( V_83
L_23
L_24 ,
V_88 / V_87 * 10 ) ;
V_88 ++ ;
}
if ( ! V_107 )
break;
V_91 [ V_97 ] . V_101 = V_107 ;
F_21 ( & V_91 [ V_97 ] . V_96 , 1 ) ;
F_32 ( & V_91 [ V_97 ] . V_95 ) ;
}
if ( ! V_97 )
break;
V_109 -> V_99 = V_97 ;
F_21 ( & V_109 -> V_96 , 1 ) ;
F_32 ( & V_109 -> V_95 ) ;
for ( V_99 = V_97 , V_97 = 0 ; V_97 < V_99 ; V_97 ++ ) {
F_43 ( V_91 [ V_97 ] . V_98 ,
F_44 ( & V_91 [ V_97 ] . V_90 ) ) ;
F_21 ( & V_91 [ V_97 ] . V_90 , 0 ) ;
V_69 = V_91 [ V_97 ] . V_69 ;
if ( V_69 < 0 ) {
F_24 ( V_43 L_25 ) ;
goto V_113;
}
if ( F_82 ( ! V_91 [ V_97 ] . V_105 ||
V_91 [ V_97 ] . V_105 >
F_83 ( V_91 [ V_97 ] . V_101 ) ) ) {
F_24 ( V_43
L_26 ) ;
V_69 = - 1 ;
goto V_113;
}
* ( T_4 * ) V_91 [ V_97 ] . V_103 = V_91 [ V_97 ] . V_105 ;
for ( V_107 = 0 ;
V_107 < V_104 + V_91 [ V_97 ] . V_105 ;
V_107 += V_35 ) {
memcpy ( V_24 , V_91 [ V_97 ] . V_103 + V_107 , V_35 ) ;
V_69 = F_60 ( V_47 , V_24 , & V_19 ) ;
if ( V_69 )
goto V_113;
}
}
F_43 ( V_109 -> V_98 , F_44 ( & V_109 -> V_90 ) ) ;
F_21 ( & V_109 -> V_90 , 0 ) ;
}
V_113:
V_89 = F_42 ( & V_19 ) ;
V_90 = F_65 () ;
if ( ! V_69 )
V_69 = V_89 ;
if ( ! V_69 )
F_24 ( V_83 L_12 ) ;
F_68 ( V_9 , V_90 , V_86 , L_13 ) ;
V_111:
if ( V_109 ) {
if ( V_109 -> V_97 )
F_84 ( V_109 -> V_97 ) ;
F_18 ( V_109 ) ;
}
if ( V_91 ) {
for ( V_97 = 0 ; V_97 < V_108 ; V_97 ++ )
if ( V_91 [ V_97 ] . V_97 )
F_84 ( V_91 [ V_97 ] . V_97 ) ;
F_85 ( V_91 ) ;
}
if ( V_24 ) F_56 ( ( unsigned long ) V_24 ) ;
return V_69 ;
}
static int F_86 ( unsigned int V_88 , unsigned int V_48 )
{
unsigned int V_114 = F_87 ( V_64 , 1 ) ;
unsigned int V_115 ;
F_88 ( L_27 , V_114 ) ;
V_115 = V_116 + V_88 ;
return V_114 > V_115 ;
}
int F_89 ( unsigned int V_48 )
{
struct V_46 V_47 ;
struct V_84 V_85 ;
struct V_117 * V_118 ;
unsigned long V_119 ;
int error ;
V_119 = F_90 () ;
error = F_57 ( & V_47 ) ;
if ( error ) {
F_24 ( V_43 L_28 ) ;
return error ;
}
if ( V_48 & V_120 ) {
if ( ! F_86 ( V_119 , V_48 ) ) {
F_24 ( V_43 L_29 ) ;
error = - V_70 ;
goto V_113;
}
}
memset ( & V_85 , 0 , sizeof( struct V_84 ) ) ;
error = F_66 ( & V_85 ) ;
if ( error < V_35 ) {
if ( error >= 0 )
error = - V_44 ;
goto V_113;
}
V_118 = (struct V_117 * ) F_67 ( V_85 ) ;
error = F_60 ( & V_47 , V_118 , NULL ) ;
if ( ! error ) {
error = ( V_48 & V_120 ) ?
F_64 ( & V_47 , & V_85 , V_119 - 1 ) :
F_74 ( & V_47 , & V_85 , V_119 - 1 ) ;
}
V_113:
error = F_63 ( & V_47 , V_48 , error ) ;
return error ;
}
static void F_91 ( struct V_46 * V_47 )
{
struct V_121 * V_122 ;
while ( V_47 -> V_123 ) {
if ( V_47 -> V_123 -> V_124 )
F_56 ( ( unsigned long ) V_47 -> V_123 -> V_124 ) ;
V_122 = V_47 -> V_123 ;
V_47 -> V_123 = V_47 -> V_123 -> V_125 ;
F_18 ( V_122 ) ;
}
V_47 -> V_73 = NULL ;
}
static int F_92 ( struct V_46 * V_47 ,
unsigned int * V_126 )
{
int error ;
struct V_121 * V_122 , * V_127 ;
T_1 V_17 ;
* V_126 = V_51 -> V_48 ;
if ( ! V_51 -> V_55 )
return - V_13 ;
V_47 -> V_73 = NULL ;
V_127 = V_47 -> V_123 = NULL ;
V_17 = V_51 -> V_55 ;
while ( V_17 ) {
V_122 = F_79 ( sizeof( * V_47 -> V_123 ) , V_14 ) ;
if ( ! V_122 ) {
F_91 ( V_47 ) ;
return - V_15 ;
}
memset ( V_122 , 0 , sizeof( * V_122 ) ) ;
if ( ! V_47 -> V_123 )
V_47 -> V_123 = V_122 ;
if ( V_127 )
V_127 -> V_125 = V_122 ;
V_127 = V_122 ;
V_122 -> V_124 = (struct V_74 * )
F_52 ( V_40 | V_41 ) ;
if ( ! V_122 -> V_124 ) {
F_91 ( V_47 ) ;
return - V_15 ;
}
error = F_34 ( V_49 , 0 , V_17 , V_122 -> V_124 , NULL ) ;
if ( error ) {
F_91 ( V_47 ) ;
return error ;
}
V_17 = V_122 -> V_124 -> V_81 ;
}
V_47 -> V_78 = 0 ;
V_47 -> V_73 = V_47 -> V_123 -> V_124 ;
return 0 ;
}
static int F_93 ( struct V_46 * V_47 , void * V_67 ,
struct V_18 * V_19 )
{
T_1 V_17 ;
int error ;
struct V_121 * V_122 ;
if ( ! V_47 -> V_73 )
return - V_13 ;
V_17 = V_47 -> V_73 -> V_79 [ V_47 -> V_78 ] ;
if ( ! V_17 )
return - V_44 ;
error = F_34 ( V_49 , 0 , V_17 , V_67 , V_19 ) ;
if ( error )
return error ;
if ( ++ V_47 -> V_78 >= V_80 ) {
V_47 -> V_78 = 0 ;
F_56 ( ( unsigned long ) V_47 -> V_123 -> V_124 ) ;
V_122 = V_47 -> V_123 ;
V_47 -> V_123 = V_47 -> V_123 -> V_125 ;
F_18 ( V_122 ) ;
if ( ! V_47 -> V_123 )
F_91 ( V_47 ) ;
else
V_47 -> V_73 = V_47 -> V_123 -> V_124 ;
}
return error ;
}
static int F_94 ( struct V_46 * V_47 )
{
F_91 ( V_47 ) ;
return 0 ;
}
static int F_95 ( struct V_46 * V_47 ,
struct V_84 * V_85 ,
unsigned int V_128 )
{
unsigned int V_87 ;
int V_69 = 0 ;
T_3 V_9 ;
T_3 V_90 ;
struct V_18 V_19 ;
int V_89 ;
unsigned V_88 ;
F_20 ( & V_19 ) ;
V_34 = true ;
F_24 ( V_83 L_30 ,
V_128 ) ;
V_87 = V_128 / 10 ;
if ( ! V_87 )
V_87 = 1 ;
V_88 = 0 ;
V_9 = F_65 () ;
for ( ; ; ) {
V_69 = F_96 ( V_85 ) ;
if ( V_69 <= 0 )
break;
V_69 = F_93 ( V_47 , F_67 ( * V_85 ) , & V_19 ) ;
if ( V_69 )
break;
if ( V_85 -> V_129 )
V_69 = F_42 ( & V_19 ) ;
if ( V_69 )
break;
if ( ! ( V_88 % V_87 ) )
F_24 ( V_83 L_31 ,
V_88 / V_87 * 10 ) ;
V_88 ++ ;
}
V_89 = F_42 ( & V_19 ) ;
V_90 = F_65 () ;
if ( ! V_69 )
V_69 = V_89 ;
if ( ! V_69 ) {
F_24 ( V_83 L_32 ) ;
F_97 ( V_85 ) ;
if ( ! F_98 ( V_85 ) )
V_69 = - V_130 ;
}
F_68 ( V_9 , V_90 , V_128 , L_33 ) ;
return V_69 ;
}
static int F_99 ( void * V_91 )
{
struct V_131 * V_93 = V_91 ;
while ( 1 ) {
F_43 ( V_93 -> V_95 , F_44 ( & V_93 -> V_96 ) ||
F_70 () ) ;
if ( F_70 () ) {
V_93 -> V_97 = NULL ;
V_93 -> V_69 = - 1 ;
F_21 ( & V_93 -> V_90 , 1 ) ;
F_32 ( & V_93 -> V_98 ) ;
break;
}
F_21 ( & V_93 -> V_96 , 0 ) ;
V_93 -> V_101 = V_112 ;
V_93 -> V_69 = F_100 ( V_93 -> V_103 + V_104 , V_93 -> V_105 ,
V_93 -> V_100 , & V_93 -> V_101 ) ;
if ( V_132 )
F_29 ( ( unsigned long ) V_93 -> V_100 ,
( unsigned long ) V_93 -> V_100 + V_93 -> V_101 ) ;
F_21 ( & V_93 -> V_90 , 1 ) ;
F_32 ( & V_93 -> V_98 ) ;
}
return 0 ;
}
static int F_101 ( struct V_46 * V_47 ,
struct V_84 * V_85 ,
unsigned int V_128 )
{
unsigned int V_87 ;
int V_69 = 0 ;
int V_133 = 0 ;
struct V_18 V_19 ;
T_3 V_9 ;
T_3 V_90 ;
unsigned V_88 ;
T_4 V_107 ;
unsigned V_94 , V_97 , V_99 , V_108 ;
unsigned V_134 = 0 , V_135 = 0 , V_136 = 0 ,
V_137 = 0 , V_138 , V_139 , V_140 = 0 ;
unsigned long V_141 = 0 ;
unsigned char * * V_24 = NULL ;
struct V_131 * V_91 = NULL ;
struct V_92 * V_109 = NULL ;
F_20 ( & V_19 ) ;
V_108 = F_75 () - 1 ;
V_108 = F_76 ( V_108 , 1 , V_110 ) ;
V_24 = F_77 ( sizeof( * V_24 ) * V_142 ) ;
if ( ! V_24 ) {
F_24 ( V_43 L_14 ) ;
V_69 = - V_15 ;
goto V_111;
}
V_91 = F_77 ( sizeof( * V_91 ) * V_108 ) ;
if ( ! V_91 ) {
F_24 ( V_43 L_15 ) ;
V_69 = - V_15 ;
goto V_111;
}
for ( V_97 = 0 ; V_97 < V_108 ; V_97 ++ )
memset ( & V_91 [ V_97 ] , 0 , F_78 ( struct V_131 , V_95 ) ) ;
V_109 = F_79 ( sizeof( * V_109 ) , V_14 ) ;
if ( ! V_109 ) {
F_24 ( V_43 L_16 ) ;
V_69 = - V_15 ;
goto V_111;
}
memset ( V_109 , 0 , F_78 ( struct V_92 , V_95 ) ) ;
V_132 = true ;
for ( V_97 = 0 ; V_97 < V_108 ; V_97 ++ ) {
F_22 ( & V_91 [ V_97 ] . V_95 ) ;
F_22 ( & V_91 [ V_97 ] . V_98 ) ;
V_91 [ V_97 ] . V_97 = F_80 ( F_99 ,
& V_91 [ V_97 ] ,
L_34 , V_97 ) ;
if ( F_81 ( V_91 [ V_97 ] . V_97 ) ) {
V_91 [ V_97 ] . V_97 = NULL ;
F_24 ( V_43
L_35 ) ;
V_69 = - V_15 ;
goto V_111;
}
}
F_22 ( & V_109 -> V_95 ) ;
F_22 ( & V_109 -> V_98 ) ;
V_47 -> V_58 = 0 ;
V_109 -> V_58 = & V_47 -> V_58 ;
for ( V_97 = 0 ; V_97 < V_108 ; V_97 ++ ) {
V_109 -> V_100 [ V_97 ] = V_91 [ V_97 ] . V_100 ;
V_109 -> V_101 [ V_97 ] = & V_91 [ V_97 ] . V_101 ;
}
V_109 -> V_97 = F_80 ( F_69 , V_109 , L_19 ) ;
if ( F_81 ( V_109 -> V_97 ) ) {
V_109 -> V_97 = NULL ;
F_24 ( V_43 L_20 ) ;
V_69 = - V_15 ;
goto V_111;
}
if ( F_1 () > F_90 () )
V_141 = ( F_1 () - F_90 () ) / 2 ;
V_141 = F_76 ( V_141 , V_143 , V_142 ) ;
for ( V_94 = 0 ; V_94 < V_141 ; V_94 ++ ) {
V_24 [ V_94 ] = ( void * ) F_52 ( V_94 < V_144 ?
V_40 | V_41 :
V_40 | V_71 |
V_72 ) ;
if ( ! V_24 [ V_94 ] ) {
if ( V_94 < V_144 ) {
V_136 = V_94 ;
F_24 ( V_43
L_36 ) ;
V_69 = - V_15 ;
goto V_111;
} else {
break;
}
}
}
V_138 = V_136 = V_94 ;
F_24 ( V_83
L_37
L_38 ,
V_108 , V_128 ) ;
V_87 = V_128 / 10 ;
if ( ! V_87 )
V_87 = 1 ;
V_88 = 0 ;
V_9 = F_65 () ;
V_69 = F_96 ( V_85 ) ;
if ( V_69 <= 0 )
goto V_113;
for(; ; ) {
for ( V_94 = 0 ; ! V_133 && V_94 < V_138 ; V_94 ++ ) {
V_69 = F_93 ( V_47 , V_24 [ V_134 ] , & V_19 ) ;
if ( V_69 ) {
if ( V_47 -> V_73 &&
V_47 -> V_73 -> V_79 [ V_47 -> V_78 ] ) {
goto V_113;
} else {
V_133 = 1 ;
break;
}
}
if ( ++ V_134 >= V_136 )
V_134 = 0 ;
}
V_140 += V_94 ;
V_138 -= V_94 ;
if ( ! V_137 ) {
if ( ! V_140 )
break;
V_69 = F_42 ( & V_19 ) ;
if ( V_69 )
goto V_113;
V_137 += V_140 ;
V_140 = 0 ;
if ( V_133 )
V_133 = 2 ;
}
if ( V_109 -> V_99 ) {
F_43 ( V_109 -> V_98 , F_44 ( & V_109 -> V_90 ) ) ;
F_21 ( & V_109 -> V_90 , 0 ) ;
V_109 -> V_99 = 0 ;
}
for ( V_97 = 0 ; V_137 && V_97 < V_108 ; V_97 ++ ) {
V_91 [ V_97 ] . V_105 = * ( T_4 * ) V_24 [ V_135 ] ;
if ( F_82 ( ! V_91 [ V_97 ] . V_105 ||
V_91 [ V_97 ] . V_105 >
F_83 ( V_112 ) ) ) {
F_24 ( V_43
L_26 ) ;
V_69 = - 1 ;
goto V_113;
}
V_139 = F_102 ( V_91 [ V_97 ] . V_105 + V_104 ,
V_35 ) ;
if ( V_139 > V_137 ) {
if ( V_133 > 1 ) {
V_69 = - 1 ;
goto V_113;
}
break;
}
for ( V_107 = 0 ;
V_107 < V_104 + V_91 [ V_97 ] . V_105 ;
V_107 += V_35 ) {
memcpy ( V_91 [ V_97 ] . V_103 + V_107 ,
V_24 [ V_135 ] , V_35 ) ;
V_137 -- ;
V_138 ++ ;
if ( ++ V_135 >= V_136 )
V_135 = 0 ;
}
F_21 ( & V_91 [ V_97 ] . V_96 , 1 ) ;
F_32 ( & V_91 [ V_97 ] . V_95 ) ;
}
if ( V_137 < V_144 && V_140 ) {
V_69 = F_42 ( & V_19 ) ;
if ( V_69 )
goto V_113;
V_137 += V_140 ;
V_140 = 0 ;
if ( V_133 )
V_133 = 2 ;
}
for ( V_99 = V_97 , V_97 = 0 ; V_97 < V_99 ; V_97 ++ ) {
F_43 ( V_91 [ V_97 ] . V_98 ,
F_44 ( & V_91 [ V_97 ] . V_90 ) ) ;
F_21 ( & V_91 [ V_97 ] . V_90 , 0 ) ;
V_69 = V_91 [ V_97 ] . V_69 ;
if ( V_69 < 0 ) {
F_24 ( V_43
L_39 ) ;
goto V_113;
}
if ( F_82 ( ! V_91 [ V_97 ] . V_101 ||
V_91 [ V_97 ] . V_101 > V_112 ||
V_91 [ V_97 ] . V_101 & ( V_35 - 1 ) ) ) {
F_24 ( V_43
L_40 ) ;
V_69 = - 1 ;
goto V_113;
}
for ( V_107 = 0 ;
V_107 < V_91 [ V_97 ] . V_101 ; V_107 += V_35 ) {
memcpy ( F_67 ( * V_85 ) ,
V_91 [ V_97 ] . V_100 + V_107 , V_35 ) ;
if ( ! ( V_88 % V_87 ) )
F_24 ( V_83
L_41
L_24 ,
V_88 / V_87 * 10 ) ;
V_88 ++ ;
V_69 = F_96 ( V_85 ) ;
if ( V_69 <= 0 ) {
V_109 -> V_99 = V_97 + 1 ;
F_21 ( & V_109 -> V_96 , 1 ) ;
F_32 ( & V_109 -> V_95 ) ;
goto V_113;
}
}
}
V_109 -> V_99 = V_97 ;
F_21 ( & V_109 -> V_96 , 1 ) ;
F_32 ( & V_109 -> V_95 ) ;
}
V_113:
if ( V_109 -> V_99 ) {
F_43 ( V_109 -> V_98 , F_44 ( & V_109 -> V_90 ) ) ;
F_21 ( & V_109 -> V_90 , 0 ) ;
}
V_90 = F_65 () ;
if ( ! V_69 ) {
F_24 ( V_83 L_32 ) ;
F_97 ( V_85 ) ;
if ( ! F_98 ( V_85 ) )
V_69 = - V_130 ;
if ( ! V_69 ) {
if ( V_51 -> V_48 & V_57 ) {
if( V_47 -> V_58 != V_51 -> V_58 ) {
F_24 ( V_43
L_42 ) ;
V_69 = - V_130 ;
}
}
}
}
F_68 ( V_9 , V_90 , V_128 , L_33 ) ;
V_111:
for ( V_94 = 0 ; V_94 < V_136 ; V_94 ++ )
F_56 ( ( unsigned long ) V_24 [ V_94 ] ) ;
if ( V_109 ) {
if ( V_109 -> V_97 )
F_84 ( V_109 -> V_97 ) ;
F_18 ( V_109 ) ;
}
if ( V_91 ) {
for ( V_97 = 0 ; V_97 < V_108 ; V_97 ++ )
if ( V_91 [ V_97 ] . V_97 )
F_84 ( V_91 [ V_97 ] . V_97 ) ;
F_85 ( V_91 ) ;
}
F_85 ( V_24 ) ;
return V_69 ;
}
int F_103 ( unsigned int * V_126 )
{
int error ;
struct V_46 V_47 ;
struct V_84 V_85 ;
struct V_117 * V_118 ;
memset ( & V_85 , 0 , sizeof( struct V_84 ) ) ;
error = F_96 ( & V_85 ) ;
if ( error < V_35 )
return error < 0 ? error : - V_44 ;
V_118 = (struct V_117 * ) F_67 ( V_85 ) ;
error = F_92 ( & V_47 , V_126 ) ;
if ( error )
goto V_11;
if ( ! error )
error = F_93 ( & V_47 , V_118 , NULL ) ;
if ( ! error ) {
error = ( * V_126 & V_120 ) ?
F_95 ( & V_47 , & V_85 , V_118 -> V_119 - 1 ) :
F_101 ( & V_47 , & V_85 , V_118 -> V_119 - 1 ) ;
}
F_94 ( & V_47 ) ;
V_11:
if ( ! error )
F_88 ( L_43 ) ;
else
F_88 ( L_44 , error ) ;
return error ;
}
int F_104 ( void )
{
int error ;
V_42 = F_105 ( V_63 ,
V_145 , NULL ) ;
if ( ! F_81 ( V_42 ) ) {
F_49 ( V_42 , V_35 ) ;
F_61 ( V_51 ) ;
error = F_34 ( V_49 , 0 ,
V_50 ,
V_51 , NULL ) ;
if ( error )
goto V_146;
if ( ! memcmp ( V_54 , V_51 -> V_52 , 10 ) ) {
memcpy ( V_51 -> V_52 , V_51 -> V_53 , 10 ) ;
error = F_34 ( V_59 , V_60 ,
V_50 ,
V_51 , NULL ) ;
} else {
error = - V_13 ;
}
V_146:
if ( error )
F_50 ( V_42 , V_145 ) ;
else
F_88 ( L_45 ) ;
} else {
error = F_106 ( V_42 ) ;
}
if ( error )
F_88 ( L_46 , error ) ;
return error ;
}
void F_59 ( T_5 V_147 )
{
if ( F_81 ( V_42 ) ) {
F_88 ( L_47 ) ;
return;
}
F_50 ( V_42 , V_147 ) ;
}
int F_107 ( void )
{
int error ;
F_34 ( V_49 , 0 , V_50 ,
V_51 , NULL ) ;
if ( ! memcmp ( V_54 , V_51 -> V_52 , 10 ) ) {
memcpy ( V_51 -> V_52 , V_51 -> V_53 , 10 ) ;
error = F_34 ( V_59 , V_60 ,
V_50 ,
V_51 , NULL ) ;
} else {
F_24 ( V_43 L_48 ) ;
error = - V_61 ;
}
F_16 ( V_64 ) ;
return error ;
}
static int F_108 ( void )
{
V_51 = (struct V_51 * ) F_52 ( V_14 ) ;
if ( ! V_51 )
F_109 ( L_49 ) ;
return 0 ;
}
