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
static void F_24 ( struct V_22 * V_22 )
{
struct V_18 * V_19 = V_22 -> V_23 ;
struct V_24 * V_24 = V_22 -> V_25 [ 0 ] . V_26 ;
if ( V_22 -> V_27 ) {
F_25 ( V_28 L_1 ,
F_26 ( V_22 -> V_29 -> V_30 ) ,
F_27 ( V_22 -> V_29 -> V_30 ) ,
( unsigned long long ) V_22 -> V_31 . V_32 ) ;
}
if ( F_28 ( V_22 ) == V_33 )
F_29 ( V_24 ) ;
else if ( V_34 )
F_30 ( ( unsigned long ) F_31 ( V_24 ) ,
( unsigned long ) F_31 ( V_24 ) + V_35 ) ;
if ( V_22 -> V_27 && ! V_19 -> error )
V_19 -> error = V_22 -> V_27 ;
if ( F_32 ( & V_19 -> V_20 ) )
F_33 ( & V_19 -> V_21 ) ;
F_34 ( V_22 ) ;
}
static int F_35 ( int V_36 , int V_37 , T_2 V_38 , void * V_39 ,
struct V_18 * V_19 )
{
struct V_24 * V_24 = F_36 ( V_39 ) ;
struct V_22 * V_22 ;
int error = 0 ;
V_22 = F_37 ( V_40 | V_41 , 1 ) ;
V_22 -> V_31 . V_32 = V_38 * ( V_35 >> 9 ) ;
V_22 -> V_29 = V_42 ;
F_38 ( V_22 , V_36 , V_37 ) ;
if ( F_39 ( V_22 , V_24 , V_35 , 0 ) < V_35 ) {
F_25 ( V_43 L_2 ,
( unsigned long long ) V_22 -> V_31 . V_32 ) ;
F_34 ( V_22 ) ;
return - V_44 ;
}
if ( V_19 ) {
V_22 -> V_45 = F_24 ;
V_22 -> V_23 = V_19 ;
F_40 ( & V_19 -> V_20 ) ;
F_41 ( V_22 ) ;
} else {
error = F_42 ( V_22 ) ;
F_34 ( V_22 ) ;
}
return error ;
}
static int F_43 ( struct V_18 * V_19 )
{
F_44 ( V_19 -> V_21 , F_45 ( & V_19 -> V_20 ) == 0 ) ;
return V_19 -> error ;
}
static int F_46 ( struct V_46 * V_47 , unsigned int V_48 )
{
int error ;
F_35 ( V_49 , V_50 , V_51 ,
V_52 , NULL ) ;
if ( ! memcmp ( L_3 , V_52 -> V_53 , 10 ) ||
! memcmp ( L_4 , V_52 -> V_53 , 10 ) ) {
memcpy ( V_52 -> V_54 , V_52 -> V_53 , 10 ) ;
memcpy ( V_52 -> V_53 , V_55 , 10 ) ;
V_52 -> V_56 = V_47 -> V_57 ;
V_52 -> V_48 = V_48 ;
if ( V_48 & V_58 )
V_52 -> V_59 = V_47 -> V_59 ;
error = F_35 ( V_60 , V_61 ,
V_51 , V_52 , NULL ) ;
} else {
F_25 ( V_43 L_5 ) ;
error = - V_62 ;
}
return error ;
}
static int F_47 ( void )
{
int V_63 ;
V_63 = F_48 ( V_64 , V_51 ,
& V_42 ) ;
if ( V_63 < 0 )
return V_63 ;
V_65 = V_63 ;
V_63 = F_49 ( V_42 , V_66 , NULL ) ;
if ( V_63 )
return V_63 ;
V_63 = F_50 ( V_42 , V_35 ) ;
if ( V_63 < 0 )
F_51 ( V_42 , V_66 ) ;
V_64 = V_42 -> V_67 ;
return V_63 ;
}
static int F_52 ( void * V_68 , T_1 V_17 , struct V_18 * V_19 )
{
void * V_69 ;
int V_70 ;
if ( ! V_17 )
return - V_71 ;
if ( V_19 ) {
V_69 = ( void * ) F_53 ( V_40 | V_72 |
V_73 ) ;
if ( V_69 ) {
F_54 ( V_69 , V_68 ) ;
} else {
V_70 = F_43 ( V_19 ) ;
if ( V_70 )
return V_70 ;
V_69 = ( void * ) F_53 ( V_40 |
V_72 |
V_73 ) ;
if ( V_69 ) {
F_54 ( V_69 , V_68 ) ;
} else {
F_55 ( 1 ) ;
V_19 = NULL ;
V_69 = V_68 ;
}
}
} else {
V_69 = V_68 ;
}
return F_35 ( V_60 , V_61 , V_17 , V_69 , V_19 ) ;
}
static void F_56 ( struct V_46 * V_47 )
{
if ( V_47 -> V_74 )
F_57 ( ( unsigned long ) V_47 -> V_74 ) ;
V_47 -> V_74 = NULL ;
}
static int F_58 ( struct V_46 * V_47 )
{
int V_70 ;
V_70 = F_47 () ;
if ( V_70 ) {
if ( V_70 != - V_71 )
F_25 ( V_43 L_6
L_7 ) ;
return V_70 ;
}
V_47 -> V_74 = (struct V_75 * ) F_59 ( V_14 ) ;
if ( ! V_47 -> V_74 ) {
V_70 = - V_15 ;
goto V_76;
}
V_47 -> V_77 = F_10 ( V_65 ) ;
if ( ! V_47 -> V_77 ) {
V_70 = - V_71 ;
goto V_78;
}
V_47 -> V_79 = 0 ;
V_47 -> F_4 = F_4 () ;
V_47 -> V_57 = V_47 -> V_77 ;
return 0 ;
V_78:
F_56 ( V_47 ) ;
V_76:
F_60 ( V_66 ) ;
return V_70 ;
}
static int F_61 ( struct V_46 * V_47 , void * V_68 ,
struct V_18 * V_19 )
{
int error = 0 ;
T_1 V_17 ;
if ( ! V_47 -> V_74 )
return - V_13 ;
V_17 = F_10 ( V_65 ) ;
error = F_52 ( V_68 , V_17 , V_19 ) ;
if ( error )
return error ;
V_47 -> V_74 -> V_80 [ V_47 -> V_79 ++ ] = V_17 ;
if ( V_47 -> V_79 >= V_81 ) {
V_17 = F_10 ( V_65 ) ;
if ( ! V_17 )
return - V_71 ;
V_47 -> V_74 -> V_82 = V_17 ;
error = F_52 ( V_47 -> V_74 , V_47 -> V_77 , V_19 ) ;
if ( error )
goto V_83;
F_62 ( V_47 -> V_74 ) ;
V_47 -> V_77 = V_17 ;
V_47 -> V_79 = 0 ;
if ( V_19 && F_1 () <= V_47 -> F_4 ) {
error = F_43 ( V_19 ) ;
if ( error )
goto V_83;
V_47 -> F_4 = F_4 () ;
}
}
V_83:
return error ;
}
static int F_63 ( struct V_46 * V_47 )
{
if ( V_47 -> V_74 && V_47 -> V_77 )
return F_52 ( V_47 -> V_74 , V_47 -> V_77 , NULL ) ;
else
return - V_13 ;
}
static int F_64 ( struct V_46 * V_47 ,
unsigned int V_48 , int error )
{
if ( ! error ) {
F_63 ( V_47 ) ;
F_25 ( V_84 L_8 ) ;
error = F_46 ( V_47 , V_48 ) ;
F_25 ( L_9 ) ;
}
if ( error )
F_16 ( V_65 ) ;
F_56 ( V_47 ) ;
F_60 ( V_66 ) ;
return error ;
}
static int F_65 ( struct V_46 * V_47 ,
struct V_85 * V_86 ,
unsigned int V_87 )
{
unsigned int V_88 ;
int V_70 ;
int V_89 ;
int V_90 ;
struct V_18 V_19 ;
T_3 V_9 ;
T_3 V_91 ;
F_21 ( & V_19 ) ;
F_25 ( V_84 L_10 ,
V_87 ) ;
V_88 = V_87 / 10 ;
if ( ! V_88 )
V_88 = 1 ;
V_89 = 0 ;
V_9 = F_66 () ;
while ( 1 ) {
V_70 = F_67 ( V_86 ) ;
if ( V_70 <= 0 )
break;
V_70 = F_61 ( V_47 , F_68 ( * V_86 ) , & V_19 ) ;
if ( V_70 )
break;
if ( ! ( V_89 % V_88 ) )
F_25 ( V_84 L_11 ,
V_89 / V_88 * 10 ) ;
V_89 ++ ;
}
V_90 = F_43 ( & V_19 ) ;
V_91 = F_66 () ;
if ( ! V_70 )
V_70 = V_90 ;
if ( ! V_70 )
F_25 ( V_84 L_12 ) ;
F_69 ( V_9 , V_91 , V_87 , L_13 ) ;
return V_70 ;
}
static int F_70 ( void * V_92 )
{
struct V_93 * V_94 = V_92 ;
unsigned V_95 ;
while ( 1 ) {
F_44 ( V_94 -> V_96 , F_45 ( & V_94 -> V_97 ) ||
F_71 () ) ;
if ( F_71 () ) {
V_94 -> V_98 = NULL ;
F_22 ( & V_94 -> V_91 , 1 ) ;
F_33 ( & V_94 -> V_99 ) ;
break;
}
F_22 ( & V_94 -> V_97 , 0 ) ;
for ( V_95 = 0 ; V_95 < V_94 -> V_100 ; V_95 ++ )
* V_94 -> V_59 = F_72 ( * V_94 -> V_59 ,
V_94 -> V_101 [ V_95 ] , * V_94 -> V_102 [ V_95 ] ) ;
F_22 ( & V_94 -> V_91 , 1 ) ;
F_33 ( & V_94 -> V_99 ) ;
}
return 0 ;
}
static int F_73 ( void * V_92 )
{
struct V_103 * V_94 = V_92 ;
while ( 1 ) {
F_44 ( V_94 -> V_96 , F_45 ( & V_94 -> V_97 ) ||
F_71 () ) ;
if ( F_71 () ) {
V_94 -> V_98 = NULL ;
V_94 -> V_70 = - 1 ;
F_22 ( & V_94 -> V_91 , 1 ) ;
F_33 ( & V_94 -> V_99 ) ;
break;
}
F_22 ( & V_94 -> V_97 , 0 ) ;
V_94 -> V_70 = F_74 ( V_94 -> V_101 , V_94 -> V_102 ,
V_94 -> V_104 + V_105 , & V_94 -> V_106 ,
V_94 -> V_107 ) ;
F_22 ( & V_94 -> V_91 , 1 ) ;
F_33 ( & V_94 -> V_99 ) ;
}
return 0 ;
}
static int F_75 ( struct V_46 * V_47 ,
struct V_85 * V_86 ,
unsigned int V_87 )
{
unsigned int V_88 ;
int V_70 = 0 ;
int V_89 ;
int V_90 ;
struct V_18 V_19 ;
T_3 V_9 ;
T_3 V_91 ;
T_4 V_108 ;
unsigned V_98 , V_100 , V_109 ;
unsigned char * V_24 = NULL ;
struct V_103 * V_92 = NULL ;
struct V_93 * V_110 = NULL ;
F_21 ( & V_19 ) ;
V_109 = F_76 () - 1 ;
V_109 = F_77 ( V_109 , 1 , V_111 ) ;
V_24 = ( void * ) F_53 ( V_40 | V_41 ) ;
if ( ! V_24 ) {
F_25 ( V_43 L_14 ) ;
V_70 = - V_15 ;
goto V_112;
}
V_92 = F_78 ( sizeof( * V_92 ) * V_109 ) ;
if ( ! V_92 ) {
F_25 ( V_43 L_15 ) ;
V_70 = - V_15 ;
goto V_112;
}
for ( V_98 = 0 ; V_98 < V_109 ; V_98 ++ )
memset ( & V_92 [ V_98 ] , 0 , F_79 ( struct V_103 , V_96 ) ) ;
V_110 = F_80 ( sizeof( * V_110 ) , V_14 ) ;
if ( ! V_110 ) {
F_25 ( V_43 L_16 ) ;
V_70 = - V_15 ;
goto V_112;
}
memset ( V_110 , 0 , F_79 ( struct V_93 , V_96 ) ) ;
for ( V_98 = 0 ; V_98 < V_109 ; V_98 ++ ) {
F_23 ( & V_92 [ V_98 ] . V_96 ) ;
F_23 ( & V_92 [ V_98 ] . V_99 ) ;
V_92 [ V_98 ] . V_98 = F_81 ( F_73 ,
& V_92 [ V_98 ] ,
L_17 , V_98 ) ;
if ( F_82 ( V_92 [ V_98 ] . V_98 ) ) {
V_92 [ V_98 ] . V_98 = NULL ;
F_25 ( V_43
L_18 ) ;
V_70 = - V_15 ;
goto V_112;
}
}
F_23 ( & V_110 -> V_96 ) ;
F_23 ( & V_110 -> V_99 ) ;
V_47 -> V_59 = 0 ;
V_110 -> V_59 = & V_47 -> V_59 ;
for ( V_98 = 0 ; V_98 < V_109 ; V_98 ++ ) {
V_110 -> V_101 [ V_98 ] = V_92 [ V_98 ] . V_101 ;
V_110 -> V_102 [ V_98 ] = & V_92 [ V_98 ] . V_102 ;
}
V_110 -> V_98 = F_81 ( F_70 , V_110 , L_19 ) ;
if ( F_82 ( V_110 -> V_98 ) ) {
V_110 -> V_98 = NULL ;
F_25 ( V_43 L_20 ) ;
V_70 = - V_15 ;
goto V_112;
}
V_47 -> F_4 = F_4 () ;
F_25 ( V_84
L_21
L_22 ,
V_109 , V_87 ) ;
V_88 = V_87 / 10 ;
if ( ! V_88 )
V_88 = 1 ;
V_89 = 0 ;
V_9 = F_66 () ;
for (; ; ) {
for ( V_98 = 0 ; V_98 < V_109 ; V_98 ++ ) {
for ( V_108 = 0 ; V_108 < V_113 ; V_108 += V_35 ) {
V_70 = F_67 ( V_86 ) ;
if ( V_70 < 0 )
goto V_114;
if ( ! V_70 )
break;
memcpy ( V_92 [ V_98 ] . V_101 + V_108 ,
F_68 ( * V_86 ) , V_35 ) ;
if ( ! ( V_89 % V_88 ) )
F_25 ( V_84
L_23
L_24 ,
V_89 / V_88 * 10 ) ;
V_89 ++ ;
}
if ( ! V_108 )
break;
V_92 [ V_98 ] . V_102 = V_108 ;
F_22 ( & V_92 [ V_98 ] . V_97 , 1 ) ;
F_33 ( & V_92 [ V_98 ] . V_96 ) ;
}
if ( ! V_98 )
break;
V_110 -> V_100 = V_98 ;
F_22 ( & V_110 -> V_97 , 1 ) ;
F_33 ( & V_110 -> V_96 ) ;
for ( V_100 = V_98 , V_98 = 0 ; V_98 < V_100 ; V_98 ++ ) {
F_44 ( V_92 [ V_98 ] . V_99 ,
F_45 ( & V_92 [ V_98 ] . V_91 ) ) ;
F_22 ( & V_92 [ V_98 ] . V_91 , 0 ) ;
V_70 = V_92 [ V_98 ] . V_70 ;
if ( V_70 < 0 ) {
F_25 ( V_43 L_25 ) ;
goto V_114;
}
if ( F_83 ( ! V_92 [ V_98 ] . V_106 ||
V_92 [ V_98 ] . V_106 >
F_84 ( V_92 [ V_98 ] . V_102 ) ) ) {
F_25 ( V_43
L_26 ) ;
V_70 = - 1 ;
goto V_114;
}
* ( T_4 * ) V_92 [ V_98 ] . V_104 = V_92 [ V_98 ] . V_106 ;
for ( V_108 = 0 ;
V_108 < V_105 + V_92 [ V_98 ] . V_106 ;
V_108 += V_35 ) {
memcpy ( V_24 , V_92 [ V_98 ] . V_104 + V_108 , V_35 ) ;
V_70 = F_61 ( V_47 , V_24 , & V_19 ) ;
if ( V_70 )
goto V_114;
}
}
F_44 ( V_110 -> V_99 , F_45 ( & V_110 -> V_91 ) ) ;
F_22 ( & V_110 -> V_91 , 0 ) ;
}
V_114:
V_90 = F_43 ( & V_19 ) ;
V_91 = F_66 () ;
if ( ! V_70 )
V_70 = V_90 ;
if ( ! V_70 )
F_25 ( V_84 L_12 ) ;
F_69 ( V_9 , V_91 , V_87 , L_13 ) ;
V_112:
if ( V_110 ) {
if ( V_110 -> V_98 )
F_85 ( V_110 -> V_98 ) ;
F_19 ( V_110 ) ;
}
if ( V_92 ) {
for ( V_98 = 0 ; V_98 < V_109 ; V_98 ++ )
if ( V_92 [ V_98 ] . V_98 )
F_85 ( V_92 [ V_98 ] . V_98 ) ;
F_86 ( V_92 ) ;
}
if ( V_24 ) F_57 ( ( unsigned long ) V_24 ) ;
return V_70 ;
}
static int F_87 ( unsigned int V_89 , unsigned int V_48 )
{
unsigned int V_115 = F_88 ( V_65 , 1 ) ;
unsigned int V_116 ;
F_89 ( L_27 , V_115 ) ;
V_116 = V_117 + V_89 ;
return V_115 > V_116 ;
}
int F_90 ( unsigned int V_48 )
{
struct V_46 V_47 ;
struct V_85 V_86 ;
struct V_118 * V_119 ;
unsigned long V_120 ;
int error ;
V_120 = F_91 () ;
error = F_58 ( & V_47 ) ;
if ( error ) {
F_25 ( V_43 L_28 ) ;
return error ;
}
if ( V_48 & V_121 ) {
if ( ! F_87 ( V_120 , V_48 ) ) {
F_25 ( V_43 L_29 ) ;
error = - V_71 ;
goto V_114;
}
}
memset ( & V_86 , 0 , sizeof( struct V_85 ) ) ;
error = F_67 ( & V_86 ) ;
if ( error < V_35 ) {
if ( error >= 0 )
error = - V_44 ;
goto V_114;
}
V_119 = (struct V_118 * ) F_68 ( V_86 ) ;
error = F_61 ( & V_47 , V_119 , NULL ) ;
if ( ! error ) {
error = ( V_48 & V_121 ) ?
F_65 ( & V_47 , & V_86 , V_120 - 1 ) :
F_75 ( & V_47 , & V_86 , V_120 - 1 ) ;
}
V_114:
error = F_64 ( & V_47 , V_48 , error ) ;
return error ;
}
static void F_92 ( struct V_46 * V_47 )
{
struct V_122 * V_123 ;
while ( V_47 -> V_124 ) {
if ( V_47 -> V_124 -> V_125 )
F_57 ( ( unsigned long ) V_47 -> V_124 -> V_125 ) ;
V_123 = V_47 -> V_124 ;
V_47 -> V_124 = V_47 -> V_124 -> V_126 ;
F_19 ( V_123 ) ;
}
V_47 -> V_74 = NULL ;
}
static int F_93 ( struct V_46 * V_47 ,
unsigned int * V_127 )
{
int error ;
struct V_122 * V_123 , * V_128 ;
T_1 V_17 ;
* V_127 = V_52 -> V_48 ;
if ( ! V_52 -> V_56 )
return - V_13 ;
V_47 -> V_74 = NULL ;
V_128 = V_47 -> V_124 = NULL ;
V_17 = V_52 -> V_56 ;
while ( V_17 ) {
V_123 = F_80 ( sizeof( * V_47 -> V_124 ) , V_14 ) ;
if ( ! V_123 ) {
F_92 ( V_47 ) ;
return - V_15 ;
}
memset ( V_123 , 0 , sizeof( * V_123 ) ) ;
if ( ! V_47 -> V_124 )
V_47 -> V_124 = V_123 ;
if ( V_128 )
V_128 -> V_126 = V_123 ;
V_128 = V_123 ;
V_123 -> V_125 = (struct V_75 * )
F_53 ( V_40 | V_41 ) ;
if ( ! V_123 -> V_125 ) {
F_92 ( V_47 ) ;
return - V_15 ;
}
error = F_35 ( V_49 , V_50 , V_17 ,
V_123 -> V_125 , NULL ) ;
if ( error ) {
F_92 ( V_47 ) ;
return error ;
}
V_17 = V_123 -> V_125 -> V_82 ;
}
V_47 -> V_79 = 0 ;
V_47 -> V_74 = V_47 -> V_124 -> V_125 ;
return 0 ;
}
static int F_94 ( struct V_46 * V_47 , void * V_68 ,
struct V_18 * V_19 )
{
T_1 V_17 ;
int error ;
struct V_122 * V_123 ;
if ( ! V_47 -> V_74 )
return - V_13 ;
V_17 = V_47 -> V_74 -> V_80 [ V_47 -> V_79 ] ;
if ( ! V_17 )
return - V_44 ;
error = F_35 ( V_49 , V_50 , V_17 , V_68 , V_19 ) ;
if ( error )
return error ;
if ( ++ V_47 -> V_79 >= V_81 ) {
V_47 -> V_79 = 0 ;
F_57 ( ( unsigned long ) V_47 -> V_124 -> V_125 ) ;
V_123 = V_47 -> V_124 ;
V_47 -> V_124 = V_47 -> V_124 -> V_126 ;
F_19 ( V_123 ) ;
if ( ! V_47 -> V_124 )
F_92 ( V_47 ) ;
else
V_47 -> V_74 = V_47 -> V_124 -> V_125 ;
}
return error ;
}
static int F_95 ( struct V_46 * V_47 )
{
F_92 ( V_47 ) ;
return 0 ;
}
static int F_96 ( struct V_46 * V_47 ,
struct V_85 * V_86 ,
unsigned int V_129 )
{
unsigned int V_88 ;
int V_70 = 0 ;
T_3 V_9 ;
T_3 V_91 ;
struct V_18 V_19 ;
int V_90 ;
unsigned V_89 ;
F_21 ( & V_19 ) ;
V_34 = true ;
F_25 ( V_84 L_30 ,
V_129 ) ;
V_88 = V_129 / 10 ;
if ( ! V_88 )
V_88 = 1 ;
V_89 = 0 ;
V_9 = F_66 () ;
for ( ; ; ) {
V_70 = F_97 ( V_86 ) ;
if ( V_70 <= 0 )
break;
V_70 = F_94 ( V_47 , F_68 ( * V_86 ) , & V_19 ) ;
if ( V_70 )
break;
if ( V_86 -> V_130 )
V_70 = F_43 ( & V_19 ) ;
if ( V_70 )
break;
if ( ! ( V_89 % V_88 ) )
F_25 ( V_84 L_31 ,
V_89 / V_88 * 10 ) ;
V_89 ++ ;
}
V_90 = F_43 ( & V_19 ) ;
V_91 = F_66 () ;
if ( ! V_70 )
V_70 = V_90 ;
if ( ! V_70 ) {
F_25 ( V_84 L_32 ) ;
F_98 ( V_86 ) ;
if ( ! F_99 ( V_86 ) )
V_70 = - V_131 ;
}
F_69 ( V_9 , V_91 , V_129 , L_33 ) ;
return V_70 ;
}
static int F_100 ( void * V_92 )
{
struct V_132 * V_94 = V_92 ;
while ( 1 ) {
F_44 ( V_94 -> V_96 , F_45 ( & V_94 -> V_97 ) ||
F_71 () ) ;
if ( F_71 () ) {
V_94 -> V_98 = NULL ;
V_94 -> V_70 = - 1 ;
F_22 ( & V_94 -> V_91 , 1 ) ;
F_33 ( & V_94 -> V_99 ) ;
break;
}
F_22 ( & V_94 -> V_97 , 0 ) ;
V_94 -> V_102 = V_113 ;
V_94 -> V_70 = F_101 ( V_94 -> V_104 + V_105 , V_94 -> V_106 ,
V_94 -> V_101 , & V_94 -> V_102 ) ;
if ( V_133 )
F_30 ( ( unsigned long ) V_94 -> V_101 ,
( unsigned long ) V_94 -> V_101 + V_94 -> V_102 ) ;
F_22 ( & V_94 -> V_91 , 1 ) ;
F_33 ( & V_94 -> V_99 ) ;
}
return 0 ;
}
static int F_102 ( struct V_46 * V_47 ,
struct V_85 * V_86 ,
unsigned int V_129 )
{
unsigned int V_88 ;
int V_70 = 0 ;
int V_134 = 0 ;
struct V_18 V_19 ;
T_3 V_9 ;
T_3 V_91 ;
unsigned V_89 ;
T_4 V_108 ;
unsigned V_95 , V_98 , V_100 , V_109 ;
unsigned V_135 = 0 , V_136 = 0 , V_137 = 0 ,
V_138 = 0 , V_139 , V_140 , V_141 = 0 ;
unsigned long V_142 = 0 ;
unsigned char * * V_24 = NULL ;
struct V_132 * V_92 = NULL ;
struct V_93 * V_110 = NULL ;
F_21 ( & V_19 ) ;
V_109 = F_76 () - 1 ;
V_109 = F_77 ( V_109 , 1 , V_111 ) ;
V_24 = F_78 ( sizeof( * V_24 ) * V_143 ) ;
if ( ! V_24 ) {
F_25 ( V_43 L_14 ) ;
V_70 = - V_15 ;
goto V_112;
}
V_92 = F_78 ( sizeof( * V_92 ) * V_109 ) ;
if ( ! V_92 ) {
F_25 ( V_43 L_15 ) ;
V_70 = - V_15 ;
goto V_112;
}
for ( V_98 = 0 ; V_98 < V_109 ; V_98 ++ )
memset ( & V_92 [ V_98 ] , 0 , F_79 ( struct V_132 , V_96 ) ) ;
V_110 = F_80 ( sizeof( * V_110 ) , V_14 ) ;
if ( ! V_110 ) {
F_25 ( V_43 L_16 ) ;
V_70 = - V_15 ;
goto V_112;
}
memset ( V_110 , 0 , F_79 ( struct V_93 , V_96 ) ) ;
V_133 = true ;
for ( V_98 = 0 ; V_98 < V_109 ; V_98 ++ ) {
F_23 ( & V_92 [ V_98 ] . V_96 ) ;
F_23 ( & V_92 [ V_98 ] . V_99 ) ;
V_92 [ V_98 ] . V_98 = F_81 ( F_100 ,
& V_92 [ V_98 ] ,
L_34 , V_98 ) ;
if ( F_82 ( V_92 [ V_98 ] . V_98 ) ) {
V_92 [ V_98 ] . V_98 = NULL ;
F_25 ( V_43
L_35 ) ;
V_70 = - V_15 ;
goto V_112;
}
}
F_23 ( & V_110 -> V_96 ) ;
F_23 ( & V_110 -> V_99 ) ;
V_47 -> V_59 = 0 ;
V_110 -> V_59 = & V_47 -> V_59 ;
for ( V_98 = 0 ; V_98 < V_109 ; V_98 ++ ) {
V_110 -> V_101 [ V_98 ] = V_92 [ V_98 ] . V_101 ;
V_110 -> V_102 [ V_98 ] = & V_92 [ V_98 ] . V_102 ;
}
V_110 -> V_98 = F_81 ( F_70 , V_110 , L_19 ) ;
if ( F_82 ( V_110 -> V_98 ) ) {
V_110 -> V_98 = NULL ;
F_25 ( V_43 L_20 ) ;
V_70 = - V_15 ;
goto V_112;
}
if ( F_1 () > F_91 () )
V_142 = ( F_1 () - F_91 () ) / 2 ;
V_142 = F_77 ( V_142 , V_144 , V_143 ) ;
for ( V_95 = 0 ; V_95 < V_142 ; V_95 ++ ) {
V_24 [ V_95 ] = ( void * ) F_53 ( V_95 < V_145 ?
V_40 | V_41 :
V_40 | V_72 |
V_73 ) ;
if ( ! V_24 [ V_95 ] ) {
if ( V_95 < V_145 ) {
V_137 = V_95 ;
F_25 ( V_43
L_36 ) ;
V_70 = - V_15 ;
goto V_112;
} else {
break;
}
}
}
V_139 = V_137 = V_95 ;
F_25 ( V_84
L_37
L_38 ,
V_109 , V_129 ) ;
V_88 = V_129 / 10 ;
if ( ! V_88 )
V_88 = 1 ;
V_89 = 0 ;
V_9 = F_66 () ;
V_70 = F_97 ( V_86 ) ;
if ( V_70 <= 0 )
goto V_114;
for(; ; ) {
for ( V_95 = 0 ; ! V_134 && V_95 < V_139 ; V_95 ++ ) {
V_70 = F_94 ( V_47 , V_24 [ V_135 ] , & V_19 ) ;
if ( V_70 ) {
if ( V_47 -> V_74 &&
V_47 -> V_74 -> V_80 [ V_47 -> V_79 ] ) {
goto V_114;
} else {
V_134 = 1 ;
break;
}
}
if ( ++ V_135 >= V_137 )
V_135 = 0 ;
}
V_141 += V_95 ;
V_139 -= V_95 ;
if ( ! V_138 ) {
if ( ! V_141 )
break;
V_70 = F_43 ( & V_19 ) ;
if ( V_70 )
goto V_114;
V_138 += V_141 ;
V_141 = 0 ;
if ( V_134 )
V_134 = 2 ;
}
if ( V_110 -> V_100 ) {
F_44 ( V_110 -> V_99 , F_45 ( & V_110 -> V_91 ) ) ;
F_22 ( & V_110 -> V_91 , 0 ) ;
V_110 -> V_100 = 0 ;
}
for ( V_98 = 0 ; V_138 && V_98 < V_109 ; V_98 ++ ) {
V_92 [ V_98 ] . V_106 = * ( T_4 * ) V_24 [ V_136 ] ;
if ( F_83 ( ! V_92 [ V_98 ] . V_106 ||
V_92 [ V_98 ] . V_106 >
F_84 ( V_113 ) ) ) {
F_25 ( V_43
L_26 ) ;
V_70 = - 1 ;
goto V_114;
}
V_140 = F_103 ( V_92 [ V_98 ] . V_106 + V_105 ,
V_35 ) ;
if ( V_140 > V_138 ) {
if ( V_134 > 1 ) {
V_70 = - 1 ;
goto V_114;
}
break;
}
for ( V_108 = 0 ;
V_108 < V_105 + V_92 [ V_98 ] . V_106 ;
V_108 += V_35 ) {
memcpy ( V_92 [ V_98 ] . V_104 + V_108 ,
V_24 [ V_136 ] , V_35 ) ;
V_138 -- ;
V_139 ++ ;
if ( ++ V_136 >= V_137 )
V_136 = 0 ;
}
F_22 ( & V_92 [ V_98 ] . V_97 , 1 ) ;
F_33 ( & V_92 [ V_98 ] . V_96 ) ;
}
if ( V_138 < V_145 && V_141 ) {
V_70 = F_43 ( & V_19 ) ;
if ( V_70 )
goto V_114;
V_138 += V_141 ;
V_141 = 0 ;
if ( V_134 )
V_134 = 2 ;
}
for ( V_100 = V_98 , V_98 = 0 ; V_98 < V_100 ; V_98 ++ ) {
F_44 ( V_92 [ V_98 ] . V_99 ,
F_45 ( & V_92 [ V_98 ] . V_91 ) ) ;
F_22 ( & V_92 [ V_98 ] . V_91 , 0 ) ;
V_70 = V_92 [ V_98 ] . V_70 ;
if ( V_70 < 0 ) {
F_25 ( V_43
L_39 ) ;
goto V_114;
}
if ( F_83 ( ! V_92 [ V_98 ] . V_102 ||
V_92 [ V_98 ] . V_102 > V_113 ||
V_92 [ V_98 ] . V_102 & ( V_35 - 1 ) ) ) {
F_25 ( V_43
L_40 ) ;
V_70 = - 1 ;
goto V_114;
}
for ( V_108 = 0 ;
V_108 < V_92 [ V_98 ] . V_102 ; V_108 += V_35 ) {
memcpy ( F_68 ( * V_86 ) ,
V_92 [ V_98 ] . V_101 + V_108 , V_35 ) ;
if ( ! ( V_89 % V_88 ) )
F_25 ( V_84
L_41
L_24 ,
V_89 / V_88 * 10 ) ;
V_89 ++ ;
V_70 = F_97 ( V_86 ) ;
if ( V_70 <= 0 ) {
V_110 -> V_100 = V_98 + 1 ;
F_22 ( & V_110 -> V_97 , 1 ) ;
F_33 ( & V_110 -> V_96 ) ;
goto V_114;
}
}
}
V_110 -> V_100 = V_98 ;
F_22 ( & V_110 -> V_97 , 1 ) ;
F_33 ( & V_110 -> V_96 ) ;
}
V_114:
if ( V_110 -> V_100 ) {
F_44 ( V_110 -> V_99 , F_45 ( & V_110 -> V_91 ) ) ;
F_22 ( & V_110 -> V_91 , 0 ) ;
}
V_91 = F_66 () ;
if ( ! V_70 ) {
F_25 ( V_84 L_32 ) ;
F_98 ( V_86 ) ;
if ( ! F_99 ( V_86 ) )
V_70 = - V_131 ;
if ( ! V_70 ) {
if ( V_52 -> V_48 & V_58 ) {
if( V_47 -> V_59 != V_52 -> V_59 ) {
F_25 ( V_43
L_42 ) ;
V_70 = - V_131 ;
}
}
}
}
F_69 ( V_9 , V_91 , V_129 , L_33 ) ;
V_112:
for ( V_95 = 0 ; V_95 < V_137 ; V_95 ++ )
F_57 ( ( unsigned long ) V_24 [ V_95 ] ) ;
if ( V_110 ) {
if ( V_110 -> V_98 )
F_85 ( V_110 -> V_98 ) ;
F_19 ( V_110 ) ;
}
if ( V_92 ) {
for ( V_98 = 0 ; V_98 < V_109 ; V_98 ++ )
if ( V_92 [ V_98 ] . V_98 )
F_85 ( V_92 [ V_98 ] . V_98 ) ;
F_86 ( V_92 ) ;
}
F_86 ( V_24 ) ;
return V_70 ;
}
int F_104 ( unsigned int * V_127 )
{
int error ;
struct V_46 V_47 ;
struct V_85 V_86 ;
struct V_118 * V_119 ;
memset ( & V_86 , 0 , sizeof( struct V_85 ) ) ;
error = F_97 ( & V_86 ) ;
if ( error < V_35 )
return error < 0 ? error : - V_44 ;
V_119 = (struct V_118 * ) F_68 ( V_86 ) ;
error = F_93 ( & V_47 , V_127 ) ;
if ( error )
goto V_11;
if ( ! error )
error = F_94 ( & V_47 , V_119 , NULL ) ;
if ( ! error ) {
error = ( * V_127 & V_121 ) ?
F_96 ( & V_47 , & V_86 , V_119 -> V_120 - 1 ) :
F_102 ( & V_47 , & V_86 , V_119 -> V_120 - 1 ) ;
}
F_95 ( & V_47 ) ;
V_11:
if ( ! error )
F_89 ( L_43 ) ;
else
F_89 ( L_44 , error ) ;
return error ;
}
int F_105 ( void )
{
int error ;
V_42 = F_106 ( V_64 ,
V_146 , NULL ) ;
if ( ! F_82 ( V_42 ) ) {
F_50 ( V_42 , V_35 ) ;
F_62 ( V_52 ) ;
error = F_35 ( V_49 , V_50 ,
V_51 ,
V_52 , NULL ) ;
if ( error )
goto V_147;
if ( ! memcmp ( V_55 , V_52 -> V_53 , 10 ) ) {
memcpy ( V_52 -> V_53 , V_52 -> V_54 , 10 ) ;
error = F_35 ( V_60 , V_61 ,
V_51 ,
V_52 , NULL ) ;
} else {
error = - V_13 ;
}
V_147:
if ( error )
F_51 ( V_42 , V_146 ) ;
else
F_89 ( L_45 ) ;
} else {
error = F_107 ( V_42 ) ;
}
if ( error )
F_89 ( L_46 , error ) ;
return error ;
}
void F_60 ( T_5 V_148 )
{
if ( F_82 ( V_42 ) ) {
F_89 ( L_47 ) ;
return;
}
F_51 ( V_42 , V_148 ) ;
}
int F_108 ( void )
{
int error ;
F_35 ( V_49 , V_50 , V_51 ,
V_52 , NULL ) ;
if ( ! memcmp ( V_55 , V_52 -> V_53 , 10 ) ) {
memcpy ( V_52 -> V_53 , V_52 -> V_54 , 10 ) ;
error = F_35 ( V_60 , V_61 ,
V_51 ,
V_52 , NULL ) ;
} else {
F_25 ( V_43 L_48 ) ;
error = - V_62 ;
}
F_16 ( V_65 ) ;
return error ;
}
static int F_109 ( void )
{
V_52 = (struct V_52 * ) F_53 ( V_14 ) ;
if ( ! V_52 )
F_110 ( L_49 ) ;
return 0 ;
}
