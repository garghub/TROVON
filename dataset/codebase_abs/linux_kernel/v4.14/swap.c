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
V_19 -> error = V_22 ;
}
static void F_23 ( struct V_23 * V_23 )
{
struct V_18 * V_19 = V_23 -> V_24 ;
struct V_25 * V_25 = V_23 -> V_26 [ 0 ] . V_27 ;
if ( V_23 -> V_28 ) {
F_24 ( V_29 L_1 ,
F_25 ( F_26 ( V_23 ) ) , F_27 ( F_26 ( V_23 ) ) ,
( unsigned long long ) V_23 -> V_30 . V_31 ) ;
}
if ( F_28 ( V_23 ) == V_32 )
F_29 ( V_25 ) ;
else if ( V_33 )
F_30 ( ( unsigned long ) F_31 ( V_25 ) ,
( unsigned long ) F_31 ( V_25 ) + V_34 ) ;
if ( V_23 -> V_28 && ! V_19 -> error )
V_19 -> error = V_23 -> V_28 ;
if ( F_32 ( & V_19 -> V_20 ) )
F_33 ( & V_19 -> V_21 ) ;
F_34 ( V_23 ) ;
}
static int F_35 ( int V_35 , int V_36 , T_2 V_37 , void * V_38 ,
struct V_18 * V_19 )
{
struct V_25 * V_25 = F_36 ( V_38 ) ;
struct V_23 * V_23 ;
int error = 0 ;
V_23 = F_37 ( V_39 | V_40 , 1 ) ;
V_23 -> V_30 . V_31 = V_37 * ( V_34 >> 9 ) ;
F_38 ( V_23 , V_41 ) ;
F_39 ( V_23 , V_35 , V_36 ) ;
if ( F_40 ( V_23 , V_25 , V_34 , 0 ) < V_34 ) {
F_24 ( V_42 L_2 ,
( unsigned long long ) V_23 -> V_30 . V_31 ) ;
F_34 ( V_23 ) ;
return - V_43 ;
}
if ( V_19 ) {
V_23 -> V_44 = F_23 ;
V_23 -> V_24 = V_19 ;
F_41 ( & V_19 -> V_20 ) ;
F_42 ( V_23 ) ;
} else {
error = F_43 ( V_23 ) ;
F_34 ( V_23 ) ;
}
return error ;
}
static T_3 F_44 ( struct V_18 * V_19 )
{
F_45 ( V_19 -> V_21 , F_46 ( & V_19 -> V_20 ) == 0 ) ;
return F_47 ( V_19 -> error ) ;
}
static int F_48 ( struct V_45 * V_46 , unsigned int V_47 )
{
int error ;
F_35 ( V_48 , 0 , V_49 ,
V_50 , NULL ) ;
if ( ! memcmp ( L_3 , V_50 -> V_51 , 10 ) ||
! memcmp ( L_4 , V_50 -> V_51 , 10 ) ) {
memcpy ( V_50 -> V_52 , V_50 -> V_51 , 10 ) ;
memcpy ( V_50 -> V_51 , V_53 , 10 ) ;
V_50 -> V_54 = V_46 -> V_55 ;
V_50 -> V_47 = V_47 ;
if ( V_47 & V_56 )
V_50 -> V_57 = V_46 -> V_57 ;
error = F_35 ( V_58 , V_59 ,
V_49 , V_50 , NULL ) ;
} else {
F_24 ( V_42 L_5 ) ;
error = - V_60 ;
}
return error ;
}
static int F_49 ( void )
{
int V_61 ;
V_61 = F_50 ( V_62 , V_49 ,
& V_41 ) ;
if ( V_61 < 0 )
return V_61 ;
V_63 = V_61 ;
V_61 = F_51 ( V_41 , V_64 , NULL ) ;
if ( V_61 )
return V_61 ;
V_61 = F_52 ( V_41 , V_34 ) ;
if ( V_61 < 0 )
F_53 ( V_41 , V_64 ) ;
V_62 = V_41 -> V_65 ;
return V_61 ;
}
static int F_54 ( void * V_66 , T_1 V_17 , struct V_18 * V_19 )
{
void * V_67 ;
int V_68 ;
if ( ! V_17 )
return - V_69 ;
if ( V_19 ) {
V_67 = ( void * ) F_55 ( V_39 | V_70 |
V_71 ) ;
if ( V_67 ) {
F_56 ( V_67 , V_66 ) ;
} else {
V_68 = F_44 ( V_19 ) ;
if ( V_68 )
return V_68 ;
V_67 = ( void * ) F_55 ( V_39 |
V_70 |
V_71 ) ;
if ( V_67 ) {
F_56 ( V_67 , V_66 ) ;
} else {
F_57 ( 1 ) ;
V_19 = NULL ;
V_67 = V_66 ;
}
}
} else {
V_67 = V_66 ;
}
return F_35 ( V_58 , V_59 , V_17 , V_67 , V_19 ) ;
}
static void F_58 ( struct V_45 * V_46 )
{
if ( V_46 -> V_72 )
F_59 ( ( unsigned long ) V_46 -> V_72 ) ;
V_46 -> V_72 = NULL ;
}
static int F_60 ( struct V_45 * V_46 )
{
int V_68 ;
V_68 = F_49 () ;
if ( V_68 ) {
if ( V_68 != - V_69 )
F_24 ( V_42 L_6
L_7 ) ;
return V_68 ;
}
V_46 -> V_72 = (struct V_73 * ) F_61 ( V_14 ) ;
if ( ! V_46 -> V_72 ) {
V_68 = - V_15 ;
goto V_74;
}
V_46 -> V_75 = F_10 ( V_63 ) ;
if ( ! V_46 -> V_75 ) {
V_68 = - V_69 ;
goto V_76;
}
V_46 -> V_77 = 0 ;
V_46 -> F_4 = F_4 () ;
V_46 -> V_55 = V_46 -> V_75 ;
return 0 ;
V_76:
F_58 ( V_46 ) ;
V_74:
F_62 ( V_64 ) ;
return V_68 ;
}
static int F_63 ( struct V_45 * V_46 , void * V_66 ,
struct V_18 * V_19 )
{
int error = 0 ;
T_1 V_17 ;
if ( ! V_46 -> V_72 )
return - V_13 ;
V_17 = F_10 ( V_63 ) ;
error = F_54 ( V_66 , V_17 , V_19 ) ;
if ( error )
return error ;
V_46 -> V_72 -> V_78 [ V_46 -> V_77 ++ ] = V_17 ;
if ( V_46 -> V_77 >= V_79 ) {
V_17 = F_10 ( V_63 ) ;
if ( ! V_17 )
return - V_69 ;
V_46 -> V_72 -> V_80 = V_17 ;
error = F_54 ( V_46 -> V_72 , V_46 -> V_75 , V_19 ) ;
if ( error )
goto V_81;
F_64 ( V_46 -> V_72 ) ;
V_46 -> V_75 = V_17 ;
V_46 -> V_77 = 0 ;
if ( V_19 && F_1 () <= V_46 -> F_4 ) {
error = F_44 ( V_19 ) ;
if ( error )
goto V_81;
V_46 -> F_4 = F_4 () ;
}
}
V_81:
return error ;
}
static int F_65 ( struct V_45 * V_46 )
{
if ( V_46 -> V_72 && V_46 -> V_75 )
return F_54 ( V_46 -> V_72 , V_46 -> V_75 , NULL ) ;
else
return - V_13 ;
}
static int F_66 ( struct V_45 * V_46 ,
unsigned int V_47 , int error )
{
if ( ! error ) {
F_65 ( V_46 ) ;
F_24 ( V_82 L_8 ) ;
error = F_48 ( V_46 , V_47 ) ;
F_24 ( L_9 ) ;
}
if ( error )
F_16 ( V_63 ) ;
F_58 ( V_46 ) ;
F_62 ( V_64 ) ;
return error ;
}
static int F_67 ( struct V_45 * V_46 ,
struct V_83 * V_84 ,
unsigned int V_85 )
{
unsigned int V_86 ;
int V_68 ;
int V_87 ;
int V_88 ;
struct V_18 V_19 ;
T_4 V_9 ;
T_4 V_89 ;
F_20 ( & V_19 ) ;
F_24 ( V_82 L_10 ,
V_85 ) ;
V_86 = V_85 / 10 ;
if ( ! V_86 )
V_86 = 1 ;
V_87 = 0 ;
V_9 = F_68 () ;
while ( 1 ) {
V_68 = F_69 ( V_84 ) ;
if ( V_68 <= 0 )
break;
V_68 = F_63 ( V_46 , F_70 ( * V_84 ) , & V_19 ) ;
if ( V_68 )
break;
if ( ! ( V_87 % V_86 ) )
F_24 ( V_82 L_11 ,
V_87 / V_86 * 10 ) ;
V_87 ++ ;
}
V_88 = F_44 ( & V_19 ) ;
V_89 = F_68 () ;
if ( ! V_68 )
V_68 = V_88 ;
if ( ! V_68 )
F_24 ( V_82 L_12 ) ;
F_71 ( V_9 , V_89 , V_85 , L_13 ) ;
return V_68 ;
}
static int F_72 ( void * V_90 )
{
struct V_91 * V_92 = V_90 ;
unsigned V_93 ;
while ( 1 ) {
F_45 ( V_92 -> V_94 , F_46 ( & V_92 -> V_95 ) ||
F_73 () ) ;
if ( F_73 () ) {
V_92 -> V_96 = NULL ;
F_21 ( & V_92 -> V_89 , 1 ) ;
F_33 ( & V_92 -> V_97 ) ;
break;
}
F_21 ( & V_92 -> V_95 , 0 ) ;
for ( V_93 = 0 ; V_93 < V_92 -> V_98 ; V_93 ++ )
* V_92 -> V_57 = F_74 ( * V_92 -> V_57 ,
V_92 -> V_99 [ V_93 ] , * V_92 -> V_100 [ V_93 ] ) ;
F_21 ( & V_92 -> V_89 , 1 ) ;
F_33 ( & V_92 -> V_97 ) ;
}
return 0 ;
}
static int F_75 ( void * V_90 )
{
struct V_101 * V_92 = V_90 ;
while ( 1 ) {
F_45 ( V_92 -> V_94 , F_46 ( & V_92 -> V_95 ) ||
F_73 () ) ;
if ( F_73 () ) {
V_92 -> V_96 = NULL ;
V_92 -> V_68 = - 1 ;
F_21 ( & V_92 -> V_89 , 1 ) ;
F_33 ( & V_92 -> V_97 ) ;
break;
}
F_21 ( & V_92 -> V_95 , 0 ) ;
V_92 -> V_68 = F_76 ( V_92 -> V_99 , V_92 -> V_100 ,
V_92 -> V_102 + V_103 , & V_92 -> V_104 ,
V_92 -> V_105 ) ;
F_21 ( & V_92 -> V_89 , 1 ) ;
F_33 ( & V_92 -> V_97 ) ;
}
return 0 ;
}
static int F_77 ( struct V_45 * V_46 ,
struct V_83 * V_84 ,
unsigned int V_85 )
{
unsigned int V_86 ;
int V_68 = 0 ;
int V_87 ;
int V_88 ;
struct V_18 V_19 ;
T_4 V_9 ;
T_4 V_89 ;
T_5 V_106 ;
unsigned V_96 , V_98 , V_107 ;
unsigned char * V_25 = NULL ;
struct V_101 * V_90 = NULL ;
struct V_91 * V_108 = NULL ;
F_20 ( & V_19 ) ;
V_107 = F_78 () - 1 ;
V_107 = F_79 ( V_107 , 1 , V_109 ) ;
V_25 = ( void * ) F_55 ( V_39 | V_40 ) ;
if ( ! V_25 ) {
F_24 ( V_42 L_14 ) ;
V_68 = - V_15 ;
goto V_110;
}
V_90 = F_80 ( sizeof( * V_90 ) * V_107 ) ;
if ( ! V_90 ) {
F_24 ( V_42 L_15 ) ;
V_68 = - V_15 ;
goto V_110;
}
for ( V_96 = 0 ; V_96 < V_107 ; V_96 ++ )
memset ( & V_90 [ V_96 ] , 0 , F_81 ( struct V_101 , V_94 ) ) ;
V_108 = F_82 ( sizeof( * V_108 ) , V_14 ) ;
if ( ! V_108 ) {
F_24 ( V_42 L_16 ) ;
V_68 = - V_15 ;
goto V_110;
}
memset ( V_108 , 0 , F_81 ( struct V_91 , V_94 ) ) ;
for ( V_96 = 0 ; V_96 < V_107 ; V_96 ++ ) {
F_22 ( & V_90 [ V_96 ] . V_94 ) ;
F_22 ( & V_90 [ V_96 ] . V_97 ) ;
V_90 [ V_96 ] . V_96 = F_83 ( F_75 ,
& V_90 [ V_96 ] ,
L_17 , V_96 ) ;
if ( F_84 ( V_90 [ V_96 ] . V_96 ) ) {
V_90 [ V_96 ] . V_96 = NULL ;
F_24 ( V_42
L_18 ) ;
V_68 = - V_15 ;
goto V_110;
}
}
F_22 ( & V_108 -> V_94 ) ;
F_22 ( & V_108 -> V_97 ) ;
V_46 -> V_57 = 0 ;
V_108 -> V_57 = & V_46 -> V_57 ;
for ( V_96 = 0 ; V_96 < V_107 ; V_96 ++ ) {
V_108 -> V_99 [ V_96 ] = V_90 [ V_96 ] . V_99 ;
V_108 -> V_100 [ V_96 ] = & V_90 [ V_96 ] . V_100 ;
}
V_108 -> V_96 = F_83 ( F_72 , V_108 , L_19 ) ;
if ( F_84 ( V_108 -> V_96 ) ) {
V_108 -> V_96 = NULL ;
F_24 ( V_42 L_20 ) ;
V_68 = - V_15 ;
goto V_110;
}
V_46 -> F_4 = F_4 () ;
F_24 ( V_82
L_21
L_22 ,
V_107 , V_85 ) ;
V_86 = V_85 / 10 ;
if ( ! V_86 )
V_86 = 1 ;
V_87 = 0 ;
V_9 = F_68 () ;
for (; ; ) {
for ( V_96 = 0 ; V_96 < V_107 ; V_96 ++ ) {
for ( V_106 = 0 ; V_106 < V_111 ; V_106 += V_34 ) {
V_68 = F_69 ( V_84 ) ;
if ( V_68 < 0 )
goto V_112;
if ( ! V_68 )
break;
memcpy ( V_90 [ V_96 ] . V_99 + V_106 ,
F_70 ( * V_84 ) , V_34 ) ;
if ( ! ( V_87 % V_86 ) )
F_24 ( V_82
L_23
L_24 ,
V_87 / V_86 * 10 ) ;
V_87 ++ ;
}
if ( ! V_106 )
break;
V_90 [ V_96 ] . V_100 = V_106 ;
F_21 ( & V_90 [ V_96 ] . V_95 , 1 ) ;
F_33 ( & V_90 [ V_96 ] . V_94 ) ;
}
if ( ! V_96 )
break;
V_108 -> V_98 = V_96 ;
F_21 ( & V_108 -> V_95 , 1 ) ;
F_33 ( & V_108 -> V_94 ) ;
for ( V_98 = V_96 , V_96 = 0 ; V_96 < V_98 ; V_96 ++ ) {
F_45 ( V_90 [ V_96 ] . V_97 ,
F_46 ( & V_90 [ V_96 ] . V_89 ) ) ;
F_21 ( & V_90 [ V_96 ] . V_89 , 0 ) ;
V_68 = V_90 [ V_96 ] . V_68 ;
if ( V_68 < 0 ) {
F_24 ( V_42 L_25 ) ;
goto V_112;
}
if ( F_85 ( ! V_90 [ V_96 ] . V_104 ||
V_90 [ V_96 ] . V_104 >
F_86 ( V_90 [ V_96 ] . V_100 ) ) ) {
F_24 ( V_42
L_26 ) ;
V_68 = - 1 ;
goto V_112;
}
* ( T_5 * ) V_90 [ V_96 ] . V_102 = V_90 [ V_96 ] . V_104 ;
for ( V_106 = 0 ;
V_106 < V_103 + V_90 [ V_96 ] . V_104 ;
V_106 += V_34 ) {
memcpy ( V_25 , V_90 [ V_96 ] . V_102 + V_106 , V_34 ) ;
V_68 = F_63 ( V_46 , V_25 , & V_19 ) ;
if ( V_68 )
goto V_112;
}
}
F_45 ( V_108 -> V_97 , F_46 ( & V_108 -> V_89 ) ) ;
F_21 ( & V_108 -> V_89 , 0 ) ;
}
V_112:
V_88 = F_44 ( & V_19 ) ;
V_89 = F_68 () ;
if ( ! V_68 )
V_68 = V_88 ;
if ( ! V_68 )
F_24 ( V_82 L_12 ) ;
F_71 ( V_9 , V_89 , V_85 , L_13 ) ;
V_110:
if ( V_108 ) {
if ( V_108 -> V_96 )
F_87 ( V_108 -> V_96 ) ;
F_18 ( V_108 ) ;
}
if ( V_90 ) {
for ( V_96 = 0 ; V_96 < V_107 ; V_96 ++ )
if ( V_90 [ V_96 ] . V_96 )
F_87 ( V_90 [ V_96 ] . V_96 ) ;
F_88 ( V_90 ) ;
}
if ( V_25 ) F_59 ( ( unsigned long ) V_25 ) ;
return V_68 ;
}
static int F_89 ( unsigned int V_87 , unsigned int V_47 )
{
unsigned int V_113 = F_90 ( V_63 , 1 ) ;
unsigned int V_114 ;
F_91 ( L_27 , V_113 ) ;
V_114 = V_115 + V_87 ;
return V_113 > V_114 ;
}
int F_92 ( unsigned int V_47 )
{
struct V_45 V_46 ;
struct V_83 V_84 ;
struct V_116 * V_117 ;
unsigned long V_118 ;
int error ;
V_118 = F_93 () ;
error = F_60 ( & V_46 ) ;
if ( error ) {
F_24 ( V_42 L_28 ) ;
return error ;
}
if ( V_47 & V_119 ) {
if ( ! F_89 ( V_118 , V_47 ) ) {
F_24 ( V_42 L_29 ) ;
error = - V_69 ;
goto V_112;
}
}
memset ( & V_84 , 0 , sizeof( struct V_83 ) ) ;
error = F_69 ( & V_84 ) ;
if ( error < V_34 ) {
if ( error >= 0 )
error = - V_43 ;
goto V_112;
}
V_117 = (struct V_116 * ) F_70 ( V_84 ) ;
error = F_63 ( & V_46 , V_117 , NULL ) ;
if ( ! error ) {
error = ( V_47 & V_119 ) ?
F_67 ( & V_46 , & V_84 , V_118 - 1 ) :
F_77 ( & V_46 , & V_84 , V_118 - 1 ) ;
}
V_112:
error = F_66 ( & V_46 , V_47 , error ) ;
return error ;
}
static void F_94 ( struct V_45 * V_46 )
{
struct V_120 * V_121 ;
while ( V_46 -> V_122 ) {
if ( V_46 -> V_122 -> V_123 )
F_59 ( ( unsigned long ) V_46 -> V_122 -> V_123 ) ;
V_121 = V_46 -> V_122 ;
V_46 -> V_122 = V_46 -> V_122 -> V_124 ;
F_18 ( V_121 ) ;
}
V_46 -> V_72 = NULL ;
}
static int F_95 ( struct V_45 * V_46 ,
unsigned int * V_125 )
{
int error ;
struct V_120 * V_121 , * V_126 ;
T_1 V_17 ;
* V_125 = V_50 -> V_47 ;
if ( ! V_50 -> V_54 )
return - V_13 ;
V_46 -> V_72 = NULL ;
V_126 = V_46 -> V_122 = NULL ;
V_17 = V_50 -> V_54 ;
while ( V_17 ) {
V_121 = F_82 ( sizeof( * V_46 -> V_122 ) , V_14 ) ;
if ( ! V_121 ) {
F_94 ( V_46 ) ;
return - V_15 ;
}
memset ( V_121 , 0 , sizeof( * V_121 ) ) ;
if ( ! V_46 -> V_122 )
V_46 -> V_122 = V_121 ;
if ( V_126 )
V_126 -> V_124 = V_121 ;
V_126 = V_121 ;
V_121 -> V_123 = (struct V_73 * )
F_55 ( V_39 | V_40 ) ;
if ( ! V_121 -> V_123 ) {
F_94 ( V_46 ) ;
return - V_15 ;
}
error = F_35 ( V_48 , 0 , V_17 , V_121 -> V_123 , NULL ) ;
if ( error ) {
F_94 ( V_46 ) ;
return error ;
}
V_17 = V_121 -> V_123 -> V_80 ;
}
V_46 -> V_77 = 0 ;
V_46 -> V_72 = V_46 -> V_122 -> V_123 ;
return 0 ;
}
static int F_96 ( struct V_45 * V_46 , void * V_66 ,
struct V_18 * V_19 )
{
T_1 V_17 ;
int error ;
struct V_120 * V_121 ;
if ( ! V_46 -> V_72 )
return - V_13 ;
V_17 = V_46 -> V_72 -> V_78 [ V_46 -> V_77 ] ;
if ( ! V_17 )
return - V_43 ;
error = F_35 ( V_48 , 0 , V_17 , V_66 , V_19 ) ;
if ( error )
return error ;
if ( ++ V_46 -> V_77 >= V_79 ) {
V_46 -> V_77 = 0 ;
F_59 ( ( unsigned long ) V_46 -> V_122 -> V_123 ) ;
V_121 = V_46 -> V_122 ;
V_46 -> V_122 = V_46 -> V_122 -> V_124 ;
F_18 ( V_121 ) ;
if ( ! V_46 -> V_122 )
F_94 ( V_46 ) ;
else
V_46 -> V_72 = V_46 -> V_122 -> V_123 ;
}
return error ;
}
static int F_97 ( struct V_45 * V_46 )
{
F_94 ( V_46 ) ;
return 0 ;
}
static int F_98 ( struct V_45 * V_46 ,
struct V_83 * V_84 ,
unsigned int V_127 )
{
unsigned int V_86 ;
int V_68 = 0 ;
T_4 V_9 ;
T_4 V_89 ;
struct V_18 V_19 ;
int V_88 ;
unsigned V_87 ;
F_20 ( & V_19 ) ;
V_33 = true ;
F_24 ( V_82 L_30 ,
V_127 ) ;
V_86 = V_127 / 10 ;
if ( ! V_86 )
V_86 = 1 ;
V_87 = 0 ;
V_9 = F_68 () ;
for ( ; ; ) {
V_68 = F_99 ( V_84 ) ;
if ( V_68 <= 0 )
break;
V_68 = F_96 ( V_46 , F_70 ( * V_84 ) , & V_19 ) ;
if ( V_68 )
break;
if ( V_84 -> V_128 )
V_68 = F_44 ( & V_19 ) ;
if ( V_68 )
break;
if ( ! ( V_87 % V_86 ) )
F_24 ( V_82 L_31 ,
V_87 / V_86 * 10 ) ;
V_87 ++ ;
}
V_88 = F_44 ( & V_19 ) ;
V_89 = F_68 () ;
if ( ! V_68 )
V_68 = V_88 ;
if ( ! V_68 ) {
F_24 ( V_82 L_32 ) ;
F_100 ( V_84 ) ;
if ( ! F_101 ( V_84 ) )
V_68 = - V_129 ;
}
F_71 ( V_9 , V_89 , V_127 , L_33 ) ;
return V_68 ;
}
static int F_102 ( void * V_90 )
{
struct V_130 * V_92 = V_90 ;
while ( 1 ) {
F_45 ( V_92 -> V_94 , F_46 ( & V_92 -> V_95 ) ||
F_73 () ) ;
if ( F_73 () ) {
V_92 -> V_96 = NULL ;
V_92 -> V_68 = - 1 ;
F_21 ( & V_92 -> V_89 , 1 ) ;
F_33 ( & V_92 -> V_97 ) ;
break;
}
F_21 ( & V_92 -> V_95 , 0 ) ;
V_92 -> V_100 = V_111 ;
V_92 -> V_68 = F_103 ( V_92 -> V_102 + V_103 , V_92 -> V_104 ,
V_92 -> V_99 , & V_92 -> V_100 ) ;
if ( V_131 )
F_30 ( ( unsigned long ) V_92 -> V_99 ,
( unsigned long ) V_92 -> V_99 + V_92 -> V_100 ) ;
F_21 ( & V_92 -> V_89 , 1 ) ;
F_33 ( & V_92 -> V_97 ) ;
}
return 0 ;
}
static int F_104 ( struct V_45 * V_46 ,
struct V_83 * V_84 ,
unsigned int V_127 )
{
unsigned int V_86 ;
int V_68 = 0 ;
int V_132 = 0 ;
struct V_18 V_19 ;
T_4 V_9 ;
T_4 V_89 ;
unsigned V_87 ;
T_5 V_106 ;
unsigned V_93 , V_96 , V_98 , V_107 ;
unsigned V_133 = 0 , V_134 = 0 , V_135 = 0 ,
V_136 = 0 , V_137 , V_138 , V_139 = 0 ;
unsigned long V_140 = 0 ;
unsigned char * * V_25 = NULL ;
struct V_130 * V_90 = NULL ;
struct V_91 * V_108 = NULL ;
F_20 ( & V_19 ) ;
V_107 = F_78 () - 1 ;
V_107 = F_79 ( V_107 , 1 , V_109 ) ;
V_25 = F_80 ( sizeof( * V_25 ) * V_141 ) ;
if ( ! V_25 ) {
F_24 ( V_42 L_14 ) ;
V_68 = - V_15 ;
goto V_110;
}
V_90 = F_80 ( sizeof( * V_90 ) * V_107 ) ;
if ( ! V_90 ) {
F_24 ( V_42 L_15 ) ;
V_68 = - V_15 ;
goto V_110;
}
for ( V_96 = 0 ; V_96 < V_107 ; V_96 ++ )
memset ( & V_90 [ V_96 ] , 0 , F_81 ( struct V_130 , V_94 ) ) ;
V_108 = F_82 ( sizeof( * V_108 ) , V_14 ) ;
if ( ! V_108 ) {
F_24 ( V_42 L_16 ) ;
V_68 = - V_15 ;
goto V_110;
}
memset ( V_108 , 0 , F_81 ( struct V_91 , V_94 ) ) ;
V_131 = true ;
for ( V_96 = 0 ; V_96 < V_107 ; V_96 ++ ) {
F_22 ( & V_90 [ V_96 ] . V_94 ) ;
F_22 ( & V_90 [ V_96 ] . V_97 ) ;
V_90 [ V_96 ] . V_96 = F_83 ( F_102 ,
& V_90 [ V_96 ] ,
L_34 , V_96 ) ;
if ( F_84 ( V_90 [ V_96 ] . V_96 ) ) {
V_90 [ V_96 ] . V_96 = NULL ;
F_24 ( V_42
L_35 ) ;
V_68 = - V_15 ;
goto V_110;
}
}
F_22 ( & V_108 -> V_94 ) ;
F_22 ( & V_108 -> V_97 ) ;
V_46 -> V_57 = 0 ;
V_108 -> V_57 = & V_46 -> V_57 ;
for ( V_96 = 0 ; V_96 < V_107 ; V_96 ++ ) {
V_108 -> V_99 [ V_96 ] = V_90 [ V_96 ] . V_99 ;
V_108 -> V_100 [ V_96 ] = & V_90 [ V_96 ] . V_100 ;
}
V_108 -> V_96 = F_83 ( F_72 , V_108 , L_19 ) ;
if ( F_84 ( V_108 -> V_96 ) ) {
V_108 -> V_96 = NULL ;
F_24 ( V_42 L_20 ) ;
V_68 = - V_15 ;
goto V_110;
}
if ( F_1 () > F_93 () )
V_140 = ( F_1 () - F_93 () ) / 2 ;
V_140 = F_79 ( V_140 , V_142 , V_141 ) ;
for ( V_93 = 0 ; V_93 < V_140 ; V_93 ++ ) {
V_25 [ V_93 ] = ( void * ) F_55 ( V_93 < V_143 ?
V_39 | V_40 :
V_39 | V_70 |
V_71 ) ;
if ( ! V_25 [ V_93 ] ) {
if ( V_93 < V_143 ) {
V_135 = V_93 ;
F_24 ( V_42
L_36 ) ;
V_68 = - V_15 ;
goto V_110;
} else {
break;
}
}
}
V_137 = V_135 = V_93 ;
F_24 ( V_82
L_37
L_38 ,
V_107 , V_127 ) ;
V_86 = V_127 / 10 ;
if ( ! V_86 )
V_86 = 1 ;
V_87 = 0 ;
V_9 = F_68 () ;
V_68 = F_99 ( V_84 ) ;
if ( V_68 <= 0 )
goto V_112;
for(; ; ) {
for ( V_93 = 0 ; ! V_132 && V_93 < V_137 ; V_93 ++ ) {
V_68 = F_96 ( V_46 , V_25 [ V_133 ] , & V_19 ) ;
if ( V_68 ) {
if ( V_46 -> V_72 &&
V_46 -> V_72 -> V_78 [ V_46 -> V_77 ] ) {
goto V_112;
} else {
V_132 = 1 ;
break;
}
}
if ( ++ V_133 >= V_135 )
V_133 = 0 ;
}
V_139 += V_93 ;
V_137 -= V_93 ;
if ( ! V_136 ) {
if ( ! V_139 )
break;
V_68 = F_44 ( & V_19 ) ;
if ( V_68 )
goto V_112;
V_136 += V_139 ;
V_139 = 0 ;
if ( V_132 )
V_132 = 2 ;
}
if ( V_108 -> V_98 ) {
F_45 ( V_108 -> V_97 , F_46 ( & V_108 -> V_89 ) ) ;
F_21 ( & V_108 -> V_89 , 0 ) ;
V_108 -> V_98 = 0 ;
}
for ( V_96 = 0 ; V_136 && V_96 < V_107 ; V_96 ++ ) {
V_90 [ V_96 ] . V_104 = * ( T_5 * ) V_25 [ V_134 ] ;
if ( F_85 ( ! V_90 [ V_96 ] . V_104 ||
V_90 [ V_96 ] . V_104 >
F_86 ( V_111 ) ) ) {
F_24 ( V_42
L_26 ) ;
V_68 = - 1 ;
goto V_112;
}
V_138 = F_105 ( V_90 [ V_96 ] . V_104 + V_103 ,
V_34 ) ;
if ( V_138 > V_136 ) {
if ( V_132 > 1 ) {
V_68 = - 1 ;
goto V_112;
}
break;
}
for ( V_106 = 0 ;
V_106 < V_103 + V_90 [ V_96 ] . V_104 ;
V_106 += V_34 ) {
memcpy ( V_90 [ V_96 ] . V_102 + V_106 ,
V_25 [ V_134 ] , V_34 ) ;
V_136 -- ;
V_137 ++ ;
if ( ++ V_134 >= V_135 )
V_134 = 0 ;
}
F_21 ( & V_90 [ V_96 ] . V_95 , 1 ) ;
F_33 ( & V_90 [ V_96 ] . V_94 ) ;
}
if ( V_136 < V_143 && V_139 ) {
V_68 = F_44 ( & V_19 ) ;
if ( V_68 )
goto V_112;
V_136 += V_139 ;
V_139 = 0 ;
if ( V_132 )
V_132 = 2 ;
}
for ( V_98 = V_96 , V_96 = 0 ; V_96 < V_98 ; V_96 ++ ) {
F_45 ( V_90 [ V_96 ] . V_97 ,
F_46 ( & V_90 [ V_96 ] . V_89 ) ) ;
F_21 ( & V_90 [ V_96 ] . V_89 , 0 ) ;
V_68 = V_90 [ V_96 ] . V_68 ;
if ( V_68 < 0 ) {
F_24 ( V_42
L_39 ) ;
goto V_112;
}
if ( F_85 ( ! V_90 [ V_96 ] . V_100 ||
V_90 [ V_96 ] . V_100 > V_111 ||
V_90 [ V_96 ] . V_100 & ( V_34 - 1 ) ) ) {
F_24 ( V_42
L_40 ) ;
V_68 = - 1 ;
goto V_112;
}
for ( V_106 = 0 ;
V_106 < V_90 [ V_96 ] . V_100 ; V_106 += V_34 ) {
memcpy ( F_70 ( * V_84 ) ,
V_90 [ V_96 ] . V_99 + V_106 , V_34 ) ;
if ( ! ( V_87 % V_86 ) )
F_24 ( V_82
L_41
L_24 ,
V_87 / V_86 * 10 ) ;
V_87 ++ ;
V_68 = F_99 ( V_84 ) ;
if ( V_68 <= 0 ) {
V_108 -> V_98 = V_96 + 1 ;
F_21 ( & V_108 -> V_95 , 1 ) ;
F_33 ( & V_108 -> V_94 ) ;
goto V_112;
}
}
}
V_108 -> V_98 = V_96 ;
F_21 ( & V_108 -> V_95 , 1 ) ;
F_33 ( & V_108 -> V_94 ) ;
}
V_112:
if ( V_108 -> V_98 ) {
F_45 ( V_108 -> V_97 , F_46 ( & V_108 -> V_89 ) ) ;
F_21 ( & V_108 -> V_89 , 0 ) ;
}
V_89 = F_68 () ;
if ( ! V_68 ) {
F_24 ( V_82 L_32 ) ;
F_100 ( V_84 ) ;
if ( ! F_101 ( V_84 ) )
V_68 = - V_129 ;
if ( ! V_68 ) {
if ( V_50 -> V_47 & V_56 ) {
if( V_46 -> V_57 != V_50 -> V_57 ) {
F_24 ( V_42
L_42 ) ;
V_68 = - V_129 ;
}
}
}
}
F_71 ( V_9 , V_89 , V_127 , L_33 ) ;
V_110:
for ( V_93 = 0 ; V_93 < V_135 ; V_93 ++ )
F_59 ( ( unsigned long ) V_25 [ V_93 ] ) ;
if ( V_108 ) {
if ( V_108 -> V_96 )
F_87 ( V_108 -> V_96 ) ;
F_18 ( V_108 ) ;
}
if ( V_90 ) {
for ( V_96 = 0 ; V_96 < V_107 ; V_96 ++ )
if ( V_90 [ V_96 ] . V_96 )
F_87 ( V_90 [ V_96 ] . V_96 ) ;
F_88 ( V_90 ) ;
}
F_88 ( V_25 ) ;
return V_68 ;
}
int F_106 ( unsigned int * V_125 )
{
int error ;
struct V_45 V_46 ;
struct V_83 V_84 ;
struct V_116 * V_117 ;
memset ( & V_84 , 0 , sizeof( struct V_83 ) ) ;
error = F_99 ( & V_84 ) ;
if ( error < V_34 )
return error < 0 ? error : - V_43 ;
V_117 = (struct V_116 * ) F_70 ( V_84 ) ;
error = F_95 ( & V_46 , V_125 ) ;
if ( error )
goto V_11;
if ( ! error )
error = F_96 ( & V_46 , V_117 , NULL ) ;
if ( ! error ) {
error = ( * V_125 & V_119 ) ?
F_98 ( & V_46 , & V_84 , V_117 -> V_118 - 1 ) :
F_104 ( & V_46 , & V_84 , V_117 -> V_118 - 1 ) ;
}
F_97 ( & V_46 ) ;
V_11:
if ( ! error )
F_91 ( L_43 ) ;
else
F_91 ( L_44 , error ) ;
return error ;
}
int F_107 ( void )
{
int error ;
V_41 = F_108 ( V_62 ,
V_144 , NULL ) ;
if ( ! F_84 ( V_41 ) ) {
F_52 ( V_41 , V_34 ) ;
F_64 ( V_50 ) ;
error = F_35 ( V_48 , 0 ,
V_49 ,
V_50 , NULL ) ;
if ( error )
goto V_145;
if ( ! memcmp ( V_53 , V_50 -> V_51 , 10 ) ) {
memcpy ( V_50 -> V_51 , V_50 -> V_52 , 10 ) ;
error = F_35 ( V_58 , V_59 ,
V_49 ,
V_50 , NULL ) ;
} else {
error = - V_13 ;
}
V_145:
if ( error )
F_53 ( V_41 , V_144 ) ;
else
F_91 ( L_45 ) ;
} else {
error = F_109 ( V_41 ) ;
}
if ( error )
F_91 ( L_46 , error ) ;
return error ;
}
void F_62 ( T_6 V_146 )
{
if ( F_84 ( V_41 ) ) {
F_91 ( L_47 ) ;
return;
}
F_53 ( V_41 , V_146 ) ;
}
int F_110 ( void )
{
int error ;
F_35 ( V_48 , 0 , V_49 ,
V_50 , NULL ) ;
if ( ! memcmp ( V_53 , V_50 -> V_51 , 10 ) ) {
memcpy ( V_50 -> V_51 , V_50 -> V_52 , 10 ) ;
error = F_35 ( V_58 , V_59 ,
V_49 ,
V_50 , NULL ) ;
} else {
F_24 ( V_42 L_48 ) ;
error = - V_60 ;
}
F_16 ( V_63 ) ;
return error ;
}
static int F_111 ( void )
{
V_50 = (struct V_50 * ) F_55 ( V_14 ) ;
if ( ! V_50 )
F_112 ( L_49 ) ;
return 0 ;
}
