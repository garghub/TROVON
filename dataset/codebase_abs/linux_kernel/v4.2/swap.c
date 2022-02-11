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
V_7 = F_17 ( V_8 , struct V_6 , V_8 ) ;
F_18 ( V_8 , & V_4 ) ;
for ( V_17 = V_7 -> V_9 ; V_17 <= V_7 -> V_11 ; V_17 ++ )
F_13 ( F_14 ( V_16 , V_17 ) ) ;
F_19 ( V_7 ) ;
}
}
int F_20 ( void )
{
return ( V_4 . V_2 != NULL ) ;
}
static void F_21 ( struct V_18 * V_19 )
{
F_22 ( & V_19 -> V_20 , 0 ) ;
F_23 ( & V_19 -> V_21 ) ;
V_19 -> error = 0 ;
}
static void F_24 ( struct V_22 * V_22 , int error )
{
struct V_18 * V_19 = V_22 -> V_23 ;
const int V_24 = F_25 ( V_25 , & V_22 -> V_26 ) ;
struct V_27 * V_27 = V_22 -> V_28 [ 0 ] . V_29 ;
if ( ! V_24 || error ) {
F_26 ( V_30 L_1 ,
F_27 ( V_22 -> V_31 -> V_32 ) ,
F_28 ( V_22 -> V_31 -> V_32 ) ,
( unsigned long long ) V_22 -> V_33 . V_34 ) ;
if ( ! error )
error = - V_35 ;
}
if ( F_29 ( V_22 ) == V_36 )
F_30 ( V_27 ) ;
if ( error && ! V_19 -> error )
V_19 -> error = error ;
if ( F_31 ( & V_19 -> V_20 ) )
F_32 ( & V_19 -> V_21 ) ;
F_33 ( V_22 ) ;
}
static int F_34 ( int V_37 , T_2 V_38 , void * V_39 ,
struct V_18 * V_19 )
{
struct V_27 * V_27 = F_35 ( V_39 ) ;
struct V_22 * V_22 ;
int error = 0 ;
V_22 = F_36 ( V_40 | V_41 , 1 ) ;
V_22 -> V_33 . V_34 = V_38 * ( V_42 >> 9 ) ;
V_22 -> V_31 = V_43 ;
if ( F_37 ( V_22 , V_27 , V_42 , 0 ) < V_42 ) {
F_26 ( V_44 L_2 ,
( unsigned long long ) V_22 -> V_33 . V_34 ) ;
F_33 ( V_22 ) ;
return - V_45 ;
}
if ( V_19 ) {
V_22 -> V_46 = F_24 ;
V_22 -> V_23 = V_19 ;
F_38 ( & V_19 -> V_20 ) ;
F_39 ( V_37 , V_22 ) ;
} else {
error = F_40 ( V_37 , V_22 ) ;
F_33 ( V_22 ) ;
}
return error ;
}
static int F_41 ( struct V_18 * V_19 )
{
F_42 ( V_19 -> V_21 , F_43 ( & V_19 -> V_20 ) == 0 ) ;
return V_19 -> error ;
}
static int F_44 ( struct V_47 * V_48 , unsigned int V_49 )
{
int error ;
F_34 ( V_50 , V_51 , V_52 , NULL ) ;
if ( ! memcmp ( L_3 , V_52 -> V_53 , 10 ) ||
! memcmp ( L_4 , V_52 -> V_53 , 10 ) ) {
memcpy ( V_52 -> V_54 , V_52 -> V_53 , 10 ) ;
memcpy ( V_52 -> V_53 , V_55 , 10 ) ;
V_52 -> V_56 = V_48 -> V_57 ;
V_52 -> V_49 = V_49 ;
if ( V_49 & V_58 )
V_52 -> V_59 = V_48 -> V_59 ;
error = F_34 ( V_60 , V_51 ,
V_52 , NULL ) ;
} else {
F_26 ( V_44 L_5 ) ;
error = - V_61 ;
}
return error ;
}
static int F_45 ( void )
{
int V_62 ;
V_62 = F_46 ( V_63 , V_51 ,
& V_43 ) ;
if ( V_62 < 0 )
return V_62 ;
V_64 = V_62 ;
V_62 = F_47 ( V_43 , V_65 , NULL ) ;
if ( V_62 )
return V_62 ;
V_62 = F_48 ( V_43 , V_42 ) ;
if ( V_62 < 0 )
F_49 ( V_43 , V_65 ) ;
return V_62 ;
}
static int F_50 ( void * V_66 , T_1 V_17 , struct V_18 * V_19 )
{
void * V_67 ;
int V_68 ;
if ( ! V_17 )
return - V_69 ;
if ( V_19 ) {
V_67 = ( void * ) F_51 ( V_40 | V_70 |
V_71 ) ;
if ( V_67 ) {
F_52 ( V_67 , V_66 ) ;
} else {
V_68 = F_41 ( V_19 ) ;
if ( V_68 )
return V_68 ;
V_67 = ( void * ) F_51 ( V_40 |
V_70 |
V_71 ) ;
if ( V_67 ) {
F_52 ( V_67 , V_66 ) ;
} else {
F_53 ( 1 ) ;
V_19 = NULL ;
V_67 = V_66 ;
}
}
} else {
V_67 = V_66 ;
}
return F_34 ( V_60 , V_17 , V_67 , V_19 ) ;
}
static void F_54 ( struct V_47 * V_48 )
{
if ( V_48 -> V_72 )
F_55 ( ( unsigned long ) V_48 -> V_72 ) ;
V_48 -> V_72 = NULL ;
}
static int F_56 ( struct V_47 * V_48 )
{
int V_68 ;
V_68 = F_45 () ;
if ( V_68 ) {
if ( V_68 != - V_69 )
F_26 ( V_44 L_6
L_7 ) ;
return V_68 ;
}
V_48 -> V_72 = (struct V_73 * ) F_57 ( V_14 ) ;
if ( ! V_48 -> V_72 ) {
V_68 = - V_15 ;
goto V_74;
}
V_48 -> V_75 = F_10 ( V_64 ) ;
if ( ! V_48 -> V_75 ) {
V_68 = - V_69 ;
goto V_76;
}
V_48 -> V_77 = 0 ;
V_48 -> F_4 = F_4 () ;
V_48 -> V_57 = V_48 -> V_75 ;
return 0 ;
V_76:
F_54 ( V_48 ) ;
V_74:
F_58 ( V_65 ) ;
return V_68 ;
}
static int F_59 ( struct V_47 * V_48 , void * V_66 ,
struct V_18 * V_19 )
{
int error = 0 ;
T_1 V_17 ;
if ( ! V_48 -> V_72 )
return - V_13 ;
V_17 = F_10 ( V_64 ) ;
error = F_50 ( V_66 , V_17 , V_19 ) ;
if ( error )
return error ;
V_48 -> V_72 -> V_78 [ V_48 -> V_77 ++ ] = V_17 ;
if ( V_48 -> V_77 >= V_79 ) {
V_17 = F_10 ( V_64 ) ;
if ( ! V_17 )
return - V_69 ;
V_48 -> V_72 -> V_80 = V_17 ;
error = F_50 ( V_48 -> V_72 , V_48 -> V_75 , V_19 ) ;
if ( error )
goto V_81;
F_60 ( V_48 -> V_72 ) ;
V_48 -> V_75 = V_17 ;
V_48 -> V_77 = 0 ;
if ( V_19 && F_1 () <= V_48 -> F_4 ) {
error = F_41 ( V_19 ) ;
if ( error )
goto V_81;
V_48 -> F_4 = F_4 () ;
}
}
V_81:
return error ;
}
static int F_61 ( struct V_47 * V_48 )
{
if ( V_48 -> V_72 && V_48 -> V_75 )
return F_50 ( V_48 -> V_72 , V_48 -> V_75 , NULL ) ;
else
return - V_13 ;
}
static int F_62 ( struct V_47 * V_48 ,
unsigned int V_49 , int error )
{
if ( ! error ) {
F_61 ( V_48 ) ;
F_26 ( V_82 L_8 ) ;
error = F_44 ( V_48 , V_49 ) ;
F_26 ( L_9 ) ;
}
if ( error )
F_16 ( V_64 ) ;
F_54 ( V_48 ) ;
F_58 ( V_65 ) ;
return error ;
}
static int F_63 ( struct V_47 * V_48 ,
struct V_83 * V_84 ,
unsigned int V_85 )
{
unsigned int V_86 ;
int V_68 ;
int V_87 ;
int V_88 ;
struct V_18 V_19 ;
T_3 V_9 ;
T_3 V_89 ;
F_21 ( & V_19 ) ;
F_26 ( V_82 L_10 ,
V_85 ) ;
V_86 = V_85 / 10 ;
if ( ! V_86 )
V_86 = 1 ;
V_87 = 0 ;
V_9 = F_64 () ;
while ( 1 ) {
V_68 = F_65 ( V_84 ) ;
if ( V_68 <= 0 )
break;
V_68 = F_59 ( V_48 , F_66 ( * V_84 ) , & V_19 ) ;
if ( V_68 )
break;
if ( ! ( V_87 % V_86 ) )
F_26 ( V_82 L_11 ,
V_87 / V_86 * 10 ) ;
V_87 ++ ;
}
V_88 = F_41 ( & V_19 ) ;
V_89 = F_64 () ;
if ( ! V_68 )
V_68 = V_88 ;
if ( ! V_68 )
F_26 ( V_82 L_12 ) ;
F_67 ( V_9 , V_89 , V_85 , L_13 ) ;
return V_68 ;
}
static int F_68 ( void * V_90 )
{
struct V_91 * V_92 = V_90 ;
unsigned V_93 ;
while ( 1 ) {
F_42 ( V_92 -> V_94 , F_43 ( & V_92 -> V_95 ) ||
F_69 () ) ;
if ( F_69 () ) {
V_92 -> V_96 = NULL ;
F_22 ( & V_92 -> V_89 , 1 ) ;
F_32 ( & V_92 -> V_97 ) ;
break;
}
F_22 ( & V_92 -> V_95 , 0 ) ;
for ( V_93 = 0 ; V_93 < V_92 -> V_98 ; V_93 ++ )
* V_92 -> V_59 = F_70 ( * V_92 -> V_59 ,
V_92 -> V_99 [ V_93 ] , * V_92 -> V_100 [ V_93 ] ) ;
F_22 ( & V_92 -> V_89 , 1 ) ;
F_32 ( & V_92 -> V_97 ) ;
}
return 0 ;
}
static int F_71 ( void * V_90 )
{
struct V_101 * V_92 = V_90 ;
while ( 1 ) {
F_42 ( V_92 -> V_94 , F_43 ( & V_92 -> V_95 ) ||
F_69 () ) ;
if ( F_69 () ) {
V_92 -> V_96 = NULL ;
V_92 -> V_68 = - 1 ;
F_22 ( & V_92 -> V_89 , 1 ) ;
F_32 ( & V_92 -> V_97 ) ;
break;
}
F_22 ( & V_92 -> V_95 , 0 ) ;
V_92 -> V_68 = F_72 ( V_92 -> V_99 , V_92 -> V_100 ,
V_92 -> V_102 + V_103 , & V_92 -> V_104 ,
V_92 -> V_105 ) ;
F_22 ( & V_92 -> V_89 , 1 ) ;
F_32 ( & V_92 -> V_97 ) ;
}
return 0 ;
}
static int F_73 ( struct V_47 * V_48 ,
struct V_83 * V_84 ,
unsigned int V_85 )
{
unsigned int V_86 ;
int V_68 = 0 ;
int V_87 ;
int V_88 ;
struct V_18 V_19 ;
T_3 V_9 ;
T_3 V_89 ;
T_4 V_106 ;
unsigned V_96 , V_98 , V_107 ;
unsigned char * V_27 = NULL ;
struct V_101 * V_90 = NULL ;
struct V_91 * V_108 = NULL ;
F_21 ( & V_19 ) ;
V_107 = F_74 () - 1 ;
V_107 = F_75 ( V_107 , 1 , V_109 ) ;
V_27 = ( void * ) F_51 ( V_40 | V_41 ) ;
if ( ! V_27 ) {
F_26 ( V_44 L_14 ) ;
V_68 = - V_15 ;
goto V_110;
}
V_90 = F_76 ( sizeof( * V_90 ) * V_107 ) ;
if ( ! V_90 ) {
F_26 ( V_44 L_15 ) ;
V_68 = - V_15 ;
goto V_110;
}
for ( V_96 = 0 ; V_96 < V_107 ; V_96 ++ )
memset ( & V_90 [ V_96 ] , 0 , F_77 ( struct V_101 , V_94 ) ) ;
V_108 = F_78 ( sizeof( * V_108 ) , V_14 ) ;
if ( ! V_108 ) {
F_26 ( V_44 L_16 ) ;
V_68 = - V_15 ;
goto V_110;
}
memset ( V_108 , 0 , F_77 ( struct V_91 , V_94 ) ) ;
for ( V_96 = 0 ; V_96 < V_107 ; V_96 ++ ) {
F_23 ( & V_90 [ V_96 ] . V_94 ) ;
F_23 ( & V_90 [ V_96 ] . V_97 ) ;
V_90 [ V_96 ] . V_96 = F_79 ( F_71 ,
& V_90 [ V_96 ] ,
L_17 , V_96 ) ;
if ( F_80 ( V_90 [ V_96 ] . V_96 ) ) {
V_90 [ V_96 ] . V_96 = NULL ;
F_26 ( V_44
L_18 ) ;
V_68 = - V_15 ;
goto V_110;
}
}
F_23 ( & V_108 -> V_94 ) ;
F_23 ( & V_108 -> V_97 ) ;
V_48 -> V_59 = 0 ;
V_108 -> V_59 = & V_48 -> V_59 ;
for ( V_96 = 0 ; V_96 < V_107 ; V_96 ++ ) {
V_108 -> V_99 [ V_96 ] = V_90 [ V_96 ] . V_99 ;
V_108 -> V_100 [ V_96 ] = & V_90 [ V_96 ] . V_100 ;
}
V_108 -> V_96 = F_79 ( F_68 , V_108 , L_19 ) ;
if ( F_80 ( V_108 -> V_96 ) ) {
V_108 -> V_96 = NULL ;
F_26 ( V_44 L_20 ) ;
V_68 = - V_15 ;
goto V_110;
}
V_48 -> F_4 = F_4 () ;
F_26 ( V_82
L_21
L_22 ,
V_107 , V_85 ) ;
V_86 = V_85 / 10 ;
if ( ! V_86 )
V_86 = 1 ;
V_87 = 0 ;
V_9 = F_64 () ;
for (; ; ) {
for ( V_96 = 0 ; V_96 < V_107 ; V_96 ++ ) {
for ( V_106 = 0 ; V_106 < V_111 ; V_106 += V_42 ) {
V_68 = F_65 ( V_84 ) ;
if ( V_68 < 0 )
goto V_112;
if ( ! V_68 )
break;
memcpy ( V_90 [ V_96 ] . V_99 + V_106 ,
F_66 ( * V_84 ) , V_42 ) ;
if ( ! ( V_87 % V_86 ) )
F_26 ( V_82
L_23
L_24 ,
V_87 / V_86 * 10 ) ;
V_87 ++ ;
}
if ( ! V_106 )
break;
V_90 [ V_96 ] . V_100 = V_106 ;
F_22 ( & V_90 [ V_96 ] . V_95 , 1 ) ;
F_32 ( & V_90 [ V_96 ] . V_94 ) ;
}
if ( ! V_96 )
break;
V_108 -> V_98 = V_96 ;
F_22 ( & V_108 -> V_95 , 1 ) ;
F_32 ( & V_108 -> V_94 ) ;
for ( V_98 = V_96 , V_96 = 0 ; V_96 < V_98 ; V_96 ++ ) {
F_42 ( V_90 [ V_96 ] . V_97 ,
F_43 ( & V_90 [ V_96 ] . V_89 ) ) ;
F_22 ( & V_90 [ V_96 ] . V_89 , 0 ) ;
V_68 = V_90 [ V_96 ] . V_68 ;
if ( V_68 < 0 ) {
F_26 ( V_44 L_25 ) ;
goto V_112;
}
if ( F_81 ( ! V_90 [ V_96 ] . V_104 ||
V_90 [ V_96 ] . V_104 >
F_82 ( V_90 [ V_96 ] . V_100 ) ) ) {
F_26 ( V_44
L_26 ) ;
V_68 = - 1 ;
goto V_112;
}
* ( T_4 * ) V_90 [ V_96 ] . V_102 = V_90 [ V_96 ] . V_104 ;
for ( V_106 = 0 ;
V_106 < V_103 + V_90 [ V_96 ] . V_104 ;
V_106 += V_42 ) {
memcpy ( V_27 , V_90 [ V_96 ] . V_102 + V_106 , V_42 ) ;
V_68 = F_59 ( V_48 , V_27 , & V_19 ) ;
if ( V_68 )
goto V_112;
}
}
F_42 ( V_108 -> V_97 , F_43 ( & V_108 -> V_89 ) ) ;
F_22 ( & V_108 -> V_89 , 0 ) ;
}
V_112:
V_88 = F_41 ( & V_19 ) ;
V_89 = F_64 () ;
if ( ! V_68 )
V_68 = V_88 ;
if ( ! V_68 )
F_26 ( V_82 L_12 ) ;
F_67 ( V_9 , V_89 , V_85 , L_13 ) ;
V_110:
if ( V_108 ) {
if ( V_108 -> V_96 )
F_83 ( V_108 -> V_96 ) ;
F_19 ( V_108 ) ;
}
if ( V_90 ) {
for ( V_96 = 0 ; V_96 < V_107 ; V_96 ++ )
if ( V_90 [ V_96 ] . V_96 )
F_83 ( V_90 [ V_96 ] . V_96 ) ;
F_84 ( V_90 ) ;
}
if ( V_27 ) F_55 ( ( unsigned long ) V_27 ) ;
return V_68 ;
}
static int F_85 ( unsigned int V_87 , unsigned int V_49 )
{
unsigned int V_113 = F_86 ( V_64 , 1 ) ;
unsigned int V_114 ;
F_87 ( L_27 , V_113 ) ;
V_114 = V_115 + V_87 ;
return V_113 > V_114 ;
}
int F_88 ( unsigned int V_49 )
{
struct V_47 V_48 ;
struct V_83 V_84 ;
struct V_116 * V_117 ;
unsigned long V_118 ;
int error ;
V_118 = F_89 () ;
error = F_56 ( & V_48 ) ;
if ( error ) {
F_26 ( V_44 L_28 ) ;
return error ;
}
if ( V_49 & V_119 ) {
if ( ! F_85 ( V_118 , V_49 ) ) {
F_26 ( V_44 L_29 ) ;
error = - V_69 ;
goto V_112;
}
}
memset ( & V_84 , 0 , sizeof( struct V_83 ) ) ;
error = F_65 ( & V_84 ) ;
if ( error < V_42 ) {
if ( error >= 0 )
error = - V_45 ;
goto V_112;
}
V_117 = (struct V_116 * ) F_66 ( V_84 ) ;
error = F_59 ( & V_48 , V_117 , NULL ) ;
if ( ! error ) {
error = ( V_49 & V_119 ) ?
F_63 ( & V_48 , & V_84 , V_118 - 1 ) :
F_73 ( & V_48 , & V_84 , V_118 - 1 ) ;
}
V_112:
error = F_62 ( & V_48 , V_49 , error ) ;
return error ;
}
static void F_90 ( struct V_47 * V_48 )
{
struct V_120 * V_121 ;
while ( V_48 -> V_122 ) {
if ( V_48 -> V_122 -> V_123 )
F_55 ( ( unsigned long ) V_48 -> V_122 -> V_123 ) ;
V_121 = V_48 -> V_122 ;
V_48 -> V_122 = V_48 -> V_122 -> V_124 ;
F_19 ( V_121 ) ;
}
V_48 -> V_72 = NULL ;
}
static int F_91 ( struct V_47 * V_48 ,
unsigned int * V_125 )
{
int error ;
struct V_120 * V_121 , * V_126 ;
T_1 V_17 ;
* V_125 = V_52 -> V_49 ;
if ( ! V_52 -> V_56 )
return - V_13 ;
V_48 -> V_72 = NULL ;
V_126 = V_48 -> V_122 = NULL ;
V_17 = V_52 -> V_56 ;
while ( V_17 ) {
V_121 = F_78 ( sizeof( * V_48 -> V_122 ) , V_14 ) ;
if ( ! V_121 ) {
F_90 ( V_48 ) ;
return - V_15 ;
}
memset ( V_121 , 0 , sizeof( * V_121 ) ) ;
if ( ! V_48 -> V_122 )
V_48 -> V_122 = V_121 ;
if ( V_126 )
V_126 -> V_124 = V_121 ;
V_126 = V_121 ;
V_121 -> V_123 = (struct V_73 * )
F_51 ( V_40 | V_41 ) ;
if ( ! V_121 -> V_123 ) {
F_90 ( V_48 ) ;
return - V_15 ;
}
error = F_34 ( V_50 , V_17 , V_121 -> V_123 , NULL ) ;
if ( error ) {
F_90 ( V_48 ) ;
return error ;
}
V_17 = V_121 -> V_123 -> V_80 ;
}
V_48 -> V_77 = 0 ;
V_48 -> V_72 = V_48 -> V_122 -> V_123 ;
return 0 ;
}
static int F_92 ( struct V_47 * V_48 , void * V_66 ,
struct V_18 * V_19 )
{
T_1 V_17 ;
int error ;
struct V_120 * V_121 ;
if ( ! V_48 -> V_72 )
return - V_13 ;
V_17 = V_48 -> V_72 -> V_78 [ V_48 -> V_77 ] ;
if ( ! V_17 )
return - V_45 ;
error = F_34 ( V_50 , V_17 , V_66 , V_19 ) ;
if ( error )
return error ;
if ( ++ V_48 -> V_77 >= V_79 ) {
V_48 -> V_77 = 0 ;
F_55 ( ( unsigned long ) V_48 -> V_122 -> V_123 ) ;
V_121 = V_48 -> V_122 ;
V_48 -> V_122 = V_48 -> V_122 -> V_124 ;
F_19 ( V_121 ) ;
if ( ! V_48 -> V_122 )
F_90 ( V_48 ) ;
else
V_48 -> V_72 = V_48 -> V_122 -> V_123 ;
}
return error ;
}
static int F_93 ( struct V_47 * V_48 )
{
F_90 ( V_48 ) ;
return 0 ;
}
static int F_94 ( struct V_47 * V_48 ,
struct V_83 * V_84 ,
unsigned int V_127 )
{
unsigned int V_86 ;
int V_68 = 0 ;
T_3 V_9 ;
T_3 V_89 ;
struct V_18 V_19 ;
int V_88 ;
unsigned V_87 ;
F_21 ( & V_19 ) ;
F_26 ( V_82 L_30 ,
V_127 ) ;
V_86 = V_127 / 10 ;
if ( ! V_86 )
V_86 = 1 ;
V_87 = 0 ;
V_9 = F_64 () ;
for ( ; ; ) {
V_68 = F_95 ( V_84 ) ;
if ( V_68 <= 0 )
break;
V_68 = F_92 ( V_48 , F_66 ( * V_84 ) , & V_19 ) ;
if ( V_68 )
break;
if ( V_84 -> V_128 )
V_68 = F_41 ( & V_19 ) ;
if ( V_68 )
break;
if ( ! ( V_87 % V_86 ) )
F_26 ( V_82 L_31 ,
V_87 / V_86 * 10 ) ;
V_87 ++ ;
}
V_88 = F_41 ( & V_19 ) ;
V_89 = F_64 () ;
if ( ! V_68 )
V_68 = V_88 ;
if ( ! V_68 ) {
F_26 ( V_82 L_32 ) ;
F_96 ( V_84 ) ;
if ( ! F_97 ( V_84 ) )
V_68 = - V_129 ;
}
F_67 ( V_9 , V_89 , V_127 , L_33 ) ;
return V_68 ;
}
static int F_98 ( void * V_90 )
{
struct V_130 * V_92 = V_90 ;
while ( 1 ) {
F_42 ( V_92 -> V_94 , F_43 ( & V_92 -> V_95 ) ||
F_69 () ) ;
if ( F_69 () ) {
V_92 -> V_96 = NULL ;
V_92 -> V_68 = - 1 ;
F_22 ( & V_92 -> V_89 , 1 ) ;
F_32 ( & V_92 -> V_97 ) ;
break;
}
F_22 ( & V_92 -> V_95 , 0 ) ;
V_92 -> V_100 = V_111 ;
V_92 -> V_68 = F_99 ( V_92 -> V_102 + V_103 , V_92 -> V_104 ,
V_92 -> V_99 , & V_92 -> V_100 ) ;
F_22 ( & V_92 -> V_89 , 1 ) ;
F_32 ( & V_92 -> V_97 ) ;
}
return 0 ;
}
static int F_100 ( struct V_47 * V_48 ,
struct V_83 * V_84 ,
unsigned int V_127 )
{
unsigned int V_86 ;
int V_68 = 0 ;
int V_131 = 0 ;
struct V_18 V_19 ;
T_3 V_9 ;
T_3 V_89 ;
unsigned V_87 ;
T_4 V_106 ;
unsigned V_93 , V_96 , V_98 , V_107 ;
unsigned V_132 = 0 , V_133 = 0 , V_134 = 0 ,
V_135 = 0 , V_136 , V_137 , V_138 = 0 ;
unsigned long V_139 = 0 ;
unsigned char * * V_27 = NULL ;
struct V_130 * V_90 = NULL ;
struct V_91 * V_108 = NULL ;
F_21 ( & V_19 ) ;
V_107 = F_74 () - 1 ;
V_107 = F_75 ( V_107 , 1 , V_109 ) ;
V_27 = F_76 ( sizeof( * V_27 ) * V_140 ) ;
if ( ! V_27 ) {
F_26 ( V_44 L_14 ) ;
V_68 = - V_15 ;
goto V_110;
}
V_90 = F_76 ( sizeof( * V_90 ) * V_107 ) ;
if ( ! V_90 ) {
F_26 ( V_44 L_15 ) ;
V_68 = - V_15 ;
goto V_110;
}
for ( V_96 = 0 ; V_96 < V_107 ; V_96 ++ )
memset ( & V_90 [ V_96 ] , 0 , F_77 ( struct V_130 , V_94 ) ) ;
V_108 = F_78 ( sizeof( * V_108 ) , V_14 ) ;
if ( ! V_108 ) {
F_26 ( V_44 L_16 ) ;
V_68 = - V_15 ;
goto V_110;
}
memset ( V_108 , 0 , F_77 ( struct V_91 , V_94 ) ) ;
for ( V_96 = 0 ; V_96 < V_107 ; V_96 ++ ) {
F_23 ( & V_90 [ V_96 ] . V_94 ) ;
F_23 ( & V_90 [ V_96 ] . V_97 ) ;
V_90 [ V_96 ] . V_96 = F_79 ( F_98 ,
& V_90 [ V_96 ] ,
L_34 , V_96 ) ;
if ( F_80 ( V_90 [ V_96 ] . V_96 ) ) {
V_90 [ V_96 ] . V_96 = NULL ;
F_26 ( V_44
L_35 ) ;
V_68 = - V_15 ;
goto V_110;
}
}
F_23 ( & V_108 -> V_94 ) ;
F_23 ( & V_108 -> V_97 ) ;
V_48 -> V_59 = 0 ;
V_108 -> V_59 = & V_48 -> V_59 ;
for ( V_96 = 0 ; V_96 < V_107 ; V_96 ++ ) {
V_108 -> V_99 [ V_96 ] = V_90 [ V_96 ] . V_99 ;
V_108 -> V_100 [ V_96 ] = & V_90 [ V_96 ] . V_100 ;
}
V_108 -> V_96 = F_79 ( F_68 , V_108 , L_19 ) ;
if ( F_80 ( V_108 -> V_96 ) ) {
V_108 -> V_96 = NULL ;
F_26 ( V_44 L_20 ) ;
V_68 = - V_15 ;
goto V_110;
}
if ( F_1 () > F_89 () )
V_139 = ( F_1 () - F_89 () ) / 2 ;
V_139 = F_75 ( V_139 , V_141 , V_140 ) ;
for ( V_93 = 0 ; V_93 < V_139 ; V_93 ++ ) {
V_27 [ V_93 ] = ( void * ) F_51 ( V_93 < V_142 ?
V_40 | V_41 :
V_40 | V_70 |
V_71 ) ;
if ( ! V_27 [ V_93 ] ) {
if ( V_93 < V_142 ) {
V_134 = V_93 ;
F_26 ( V_44
L_36 ) ;
V_68 = - V_15 ;
goto V_110;
} else {
break;
}
}
}
V_136 = V_134 = V_93 ;
F_26 ( V_82
L_37
L_38 ,
V_107 , V_127 ) ;
V_86 = V_127 / 10 ;
if ( ! V_86 )
V_86 = 1 ;
V_87 = 0 ;
V_9 = F_64 () ;
V_68 = F_95 ( V_84 ) ;
if ( V_68 <= 0 )
goto V_112;
for(; ; ) {
for ( V_93 = 0 ; ! V_131 && V_93 < V_136 ; V_93 ++ ) {
V_68 = F_92 ( V_48 , V_27 [ V_132 ] , & V_19 ) ;
if ( V_68 ) {
if ( V_48 -> V_72 &&
V_48 -> V_72 -> V_78 [ V_48 -> V_77 ] ) {
goto V_112;
} else {
V_131 = 1 ;
break;
}
}
if ( ++ V_132 >= V_134 )
V_132 = 0 ;
}
V_138 += V_93 ;
V_136 -= V_93 ;
if ( ! V_135 ) {
if ( ! V_138 )
break;
V_68 = F_41 ( & V_19 ) ;
if ( V_68 )
goto V_112;
V_135 += V_138 ;
V_138 = 0 ;
if ( V_131 )
V_131 = 2 ;
}
if ( V_108 -> V_98 ) {
F_42 ( V_108 -> V_97 , F_43 ( & V_108 -> V_89 ) ) ;
F_22 ( & V_108 -> V_89 , 0 ) ;
V_108 -> V_98 = 0 ;
}
for ( V_96 = 0 ; V_135 && V_96 < V_107 ; V_96 ++ ) {
V_90 [ V_96 ] . V_104 = * ( T_4 * ) V_27 [ V_133 ] ;
if ( F_81 ( ! V_90 [ V_96 ] . V_104 ||
V_90 [ V_96 ] . V_104 >
F_82 ( V_111 ) ) ) {
F_26 ( V_44
L_26 ) ;
V_68 = - 1 ;
goto V_112;
}
V_137 = F_101 ( V_90 [ V_96 ] . V_104 + V_103 ,
V_42 ) ;
if ( V_137 > V_135 ) {
if ( V_131 > 1 ) {
V_68 = - 1 ;
goto V_112;
}
break;
}
for ( V_106 = 0 ;
V_106 < V_103 + V_90 [ V_96 ] . V_104 ;
V_106 += V_42 ) {
memcpy ( V_90 [ V_96 ] . V_102 + V_106 ,
V_27 [ V_133 ] , V_42 ) ;
V_135 -- ;
V_136 ++ ;
if ( ++ V_133 >= V_134 )
V_133 = 0 ;
}
F_22 ( & V_90 [ V_96 ] . V_95 , 1 ) ;
F_32 ( & V_90 [ V_96 ] . V_94 ) ;
}
if ( V_135 < V_142 && V_138 ) {
V_68 = F_41 ( & V_19 ) ;
if ( V_68 )
goto V_112;
V_135 += V_138 ;
V_138 = 0 ;
if ( V_131 )
V_131 = 2 ;
}
for ( V_98 = V_96 , V_96 = 0 ; V_96 < V_98 ; V_96 ++ ) {
F_42 ( V_90 [ V_96 ] . V_97 ,
F_43 ( & V_90 [ V_96 ] . V_89 ) ) ;
F_22 ( & V_90 [ V_96 ] . V_89 , 0 ) ;
V_68 = V_90 [ V_96 ] . V_68 ;
if ( V_68 < 0 ) {
F_26 ( V_44
L_39 ) ;
goto V_112;
}
if ( F_81 ( ! V_90 [ V_96 ] . V_100 ||
V_90 [ V_96 ] . V_100 > V_111 ||
V_90 [ V_96 ] . V_100 & ( V_42 - 1 ) ) ) {
F_26 ( V_44
L_40 ) ;
V_68 = - 1 ;
goto V_112;
}
for ( V_106 = 0 ;
V_106 < V_90 [ V_96 ] . V_100 ; V_106 += V_42 ) {
memcpy ( F_66 ( * V_84 ) ,
V_90 [ V_96 ] . V_99 + V_106 , V_42 ) ;
if ( ! ( V_87 % V_86 ) )
F_26 ( V_82
L_41
L_24 ,
V_87 / V_86 * 10 ) ;
V_87 ++ ;
V_68 = F_95 ( V_84 ) ;
if ( V_68 <= 0 ) {
V_108 -> V_98 = V_96 + 1 ;
F_22 ( & V_108 -> V_95 , 1 ) ;
F_32 ( & V_108 -> V_94 ) ;
goto V_112;
}
}
}
V_108 -> V_98 = V_96 ;
F_22 ( & V_108 -> V_95 , 1 ) ;
F_32 ( & V_108 -> V_94 ) ;
}
V_112:
if ( V_108 -> V_98 ) {
F_42 ( V_108 -> V_97 , F_43 ( & V_108 -> V_89 ) ) ;
F_22 ( & V_108 -> V_89 , 0 ) ;
}
V_89 = F_64 () ;
if ( ! V_68 ) {
F_26 ( V_82 L_32 ) ;
F_96 ( V_84 ) ;
if ( ! F_97 ( V_84 ) )
V_68 = - V_129 ;
if ( ! V_68 ) {
if ( V_52 -> V_49 & V_58 ) {
if( V_48 -> V_59 != V_52 -> V_59 ) {
F_26 ( V_44
L_42 ) ;
V_68 = - V_129 ;
}
}
}
}
F_67 ( V_9 , V_89 , V_127 , L_33 ) ;
V_110:
for ( V_93 = 0 ; V_93 < V_134 ; V_93 ++ )
F_55 ( ( unsigned long ) V_27 [ V_93 ] ) ;
if ( V_108 ) {
if ( V_108 -> V_96 )
F_83 ( V_108 -> V_96 ) ;
F_19 ( V_108 ) ;
}
if ( V_90 ) {
for ( V_96 = 0 ; V_96 < V_107 ; V_96 ++ )
if ( V_90 [ V_96 ] . V_96 )
F_83 ( V_90 [ V_96 ] . V_96 ) ;
F_84 ( V_90 ) ;
}
F_84 ( V_27 ) ;
return V_68 ;
}
int F_102 ( unsigned int * V_125 )
{
int error ;
struct V_47 V_48 ;
struct V_83 V_84 ;
struct V_116 * V_117 ;
memset ( & V_84 , 0 , sizeof( struct V_83 ) ) ;
error = F_95 ( & V_84 ) ;
if ( error < V_42 )
return error < 0 ? error : - V_45 ;
V_117 = (struct V_116 * ) F_66 ( V_84 ) ;
error = F_91 ( & V_48 , V_125 ) ;
if ( error )
goto V_11;
if ( ! error )
error = F_92 ( & V_48 , V_117 , NULL ) ;
if ( ! error ) {
error = ( * V_125 & V_119 ) ?
F_94 ( & V_48 , & V_84 , V_117 -> V_118 - 1 ) :
F_100 ( & V_48 , & V_84 , V_117 -> V_118 - 1 ) ;
}
F_93 ( & V_48 ) ;
V_11:
if ( ! error )
F_87 ( L_43 ) ;
else
F_87 ( L_44 , error ) ;
return error ;
}
int F_103 ( void )
{
int error ;
V_43 = F_104 ( V_63 ,
V_143 , NULL ) ;
if ( ! F_80 ( V_43 ) ) {
F_48 ( V_43 , V_42 ) ;
F_60 ( V_52 ) ;
error = F_34 ( V_50 , V_51 ,
V_52 , NULL ) ;
if ( error )
goto V_144;
if ( ! memcmp ( V_55 , V_52 -> V_53 , 10 ) ) {
memcpy ( V_52 -> V_53 , V_52 -> V_54 , 10 ) ;
error = F_34 ( V_60 , V_51 ,
V_52 , NULL ) ;
} else {
error = - V_13 ;
}
V_144:
if ( error )
F_49 ( V_43 , V_143 ) ;
else
F_87 ( L_45 ) ;
} else {
error = F_105 ( V_43 ) ;
}
if ( error )
F_87 ( L_46 , error ) ;
return error ;
}
void F_58 ( T_5 V_145 )
{
if ( F_80 ( V_43 ) ) {
F_87 ( L_47 ) ;
return;
}
F_49 ( V_43 , V_145 ) ;
}
int F_106 ( void )
{
int error ;
F_34 ( V_50 , V_51 , V_52 , NULL ) ;
if ( ! memcmp ( V_55 , V_52 -> V_53 , 10 ) ) {
memcpy ( V_52 -> V_53 , V_52 -> V_54 , 10 ) ;
error = F_34 ( V_60 , V_51 ,
V_52 , NULL ) ;
} else {
F_26 ( V_44 L_48 ) ;
error = - V_61 ;
}
F_16 ( V_64 ) ;
return error ;
}
static int F_107 ( void )
{
V_52 = (struct V_52 * ) F_51 ( V_14 ) ;
if ( ! V_52 )
F_108 ( L_49 ) ;
return 0 ;
}
