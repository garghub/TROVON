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
static int F_35 ( int V_36 , T_2 V_37 , void * V_38 ,
struct V_18 * V_19 )
{
struct V_24 * V_24 = F_36 ( V_38 ) ;
struct V_22 * V_22 ;
int error = 0 ;
V_22 = F_37 ( V_39 | V_40 , 1 ) ;
V_22 -> V_31 . V_32 = V_37 * ( V_35 >> 9 ) ;
V_22 -> V_29 = V_41 ;
if ( F_38 ( V_22 , V_24 , V_35 , 0 ) < V_35 ) {
F_25 ( V_42 L_2 ,
( unsigned long long ) V_22 -> V_31 . V_32 ) ;
F_34 ( V_22 ) ;
return - V_43 ;
}
if ( V_19 ) {
V_22 -> V_44 = F_24 ;
V_22 -> V_23 = V_19 ;
F_39 ( & V_19 -> V_20 ) ;
F_40 ( V_36 , V_22 ) ;
} else {
error = F_41 ( V_36 , V_22 ) ;
F_34 ( V_22 ) ;
}
return error ;
}
static int F_42 ( struct V_18 * V_19 )
{
F_43 ( V_19 -> V_21 , F_44 ( & V_19 -> V_20 ) == 0 ) ;
return V_19 -> error ;
}
static int F_45 ( struct V_45 * V_46 , unsigned int V_47 )
{
int error ;
F_35 ( V_48 , V_49 , V_50 , NULL ) ;
if ( ! memcmp ( L_3 , V_50 -> V_51 , 10 ) ||
! memcmp ( L_4 , V_50 -> V_51 , 10 ) ) {
memcpy ( V_50 -> V_52 , V_50 -> V_51 , 10 ) ;
memcpy ( V_50 -> V_51 , V_53 , 10 ) ;
V_50 -> V_54 = V_46 -> V_55 ;
V_50 -> V_47 = V_47 ;
if ( V_47 & V_56 )
V_50 -> V_57 = V_46 -> V_57 ;
error = F_35 ( V_58 , V_49 ,
V_50 , NULL ) ;
} else {
F_25 ( V_42 L_5 ) ;
error = - V_59 ;
}
return error ;
}
static int F_46 ( void )
{
int V_60 ;
V_60 = F_47 ( V_61 , V_49 ,
& V_41 ) ;
if ( V_60 < 0 )
return V_60 ;
V_62 = V_60 ;
V_60 = F_48 ( V_41 , V_63 , NULL ) ;
if ( V_60 )
return V_60 ;
V_60 = F_49 ( V_41 , V_35 ) ;
if ( V_60 < 0 )
F_50 ( V_41 , V_63 ) ;
return V_60 ;
}
static int F_51 ( void * V_64 , T_1 V_17 , struct V_18 * V_19 )
{
void * V_65 ;
int V_66 ;
if ( ! V_17 )
return - V_67 ;
if ( V_19 ) {
V_65 = ( void * ) F_52 ( V_39 | V_68 |
V_69 ) ;
if ( V_65 ) {
F_53 ( V_65 , V_64 ) ;
} else {
V_66 = F_42 ( V_19 ) ;
if ( V_66 )
return V_66 ;
V_65 = ( void * ) F_52 ( V_39 |
V_68 |
V_69 ) ;
if ( V_65 ) {
F_53 ( V_65 , V_64 ) ;
} else {
F_54 ( 1 ) ;
V_19 = NULL ;
V_65 = V_64 ;
}
}
} else {
V_65 = V_64 ;
}
return F_35 ( V_58 , V_17 , V_65 , V_19 ) ;
}
static void F_55 ( struct V_45 * V_46 )
{
if ( V_46 -> V_70 )
F_56 ( ( unsigned long ) V_46 -> V_70 ) ;
V_46 -> V_70 = NULL ;
}
static int F_57 ( struct V_45 * V_46 )
{
int V_66 ;
V_66 = F_46 () ;
if ( V_66 ) {
if ( V_66 != - V_67 )
F_25 ( V_42 L_6
L_7 ) ;
return V_66 ;
}
V_46 -> V_70 = (struct V_71 * ) F_58 ( V_14 ) ;
if ( ! V_46 -> V_70 ) {
V_66 = - V_15 ;
goto V_72;
}
V_46 -> V_73 = F_10 ( V_62 ) ;
if ( ! V_46 -> V_73 ) {
V_66 = - V_67 ;
goto V_74;
}
V_46 -> V_75 = 0 ;
V_46 -> F_4 = F_4 () ;
V_46 -> V_55 = V_46 -> V_73 ;
return 0 ;
V_74:
F_55 ( V_46 ) ;
V_72:
F_59 ( V_63 ) ;
return V_66 ;
}
static int F_60 ( struct V_45 * V_46 , void * V_64 ,
struct V_18 * V_19 )
{
int error = 0 ;
T_1 V_17 ;
if ( ! V_46 -> V_70 )
return - V_13 ;
V_17 = F_10 ( V_62 ) ;
error = F_51 ( V_64 , V_17 , V_19 ) ;
if ( error )
return error ;
V_46 -> V_70 -> V_76 [ V_46 -> V_75 ++ ] = V_17 ;
if ( V_46 -> V_75 >= V_77 ) {
V_17 = F_10 ( V_62 ) ;
if ( ! V_17 )
return - V_67 ;
V_46 -> V_70 -> V_78 = V_17 ;
error = F_51 ( V_46 -> V_70 , V_46 -> V_73 , V_19 ) ;
if ( error )
goto V_79;
F_61 ( V_46 -> V_70 ) ;
V_46 -> V_73 = V_17 ;
V_46 -> V_75 = 0 ;
if ( V_19 && F_1 () <= V_46 -> F_4 ) {
error = F_42 ( V_19 ) ;
if ( error )
goto V_79;
V_46 -> F_4 = F_4 () ;
}
}
V_79:
return error ;
}
static int F_62 ( struct V_45 * V_46 )
{
if ( V_46 -> V_70 && V_46 -> V_73 )
return F_51 ( V_46 -> V_70 , V_46 -> V_73 , NULL ) ;
else
return - V_13 ;
}
static int F_63 ( struct V_45 * V_46 ,
unsigned int V_47 , int error )
{
if ( ! error ) {
F_62 ( V_46 ) ;
F_25 ( V_80 L_8 ) ;
error = F_45 ( V_46 , V_47 ) ;
F_25 ( L_9 ) ;
}
if ( error )
F_16 ( V_62 ) ;
F_55 ( V_46 ) ;
F_59 ( V_63 ) ;
return error ;
}
static int F_64 ( struct V_45 * V_46 ,
struct V_81 * V_82 ,
unsigned int V_83 )
{
unsigned int V_84 ;
int V_66 ;
int V_85 ;
int V_86 ;
struct V_18 V_19 ;
T_3 V_9 ;
T_3 V_87 ;
F_21 ( & V_19 ) ;
F_25 ( V_80 L_10 ,
V_83 ) ;
V_84 = V_83 / 10 ;
if ( ! V_84 )
V_84 = 1 ;
V_85 = 0 ;
V_9 = F_65 () ;
while ( 1 ) {
V_66 = F_66 ( V_82 ) ;
if ( V_66 <= 0 )
break;
V_66 = F_60 ( V_46 , F_67 ( * V_82 ) , & V_19 ) ;
if ( V_66 )
break;
if ( ! ( V_85 % V_84 ) )
F_25 ( V_80 L_11 ,
V_85 / V_84 * 10 ) ;
V_85 ++ ;
}
V_86 = F_42 ( & V_19 ) ;
V_87 = F_65 () ;
if ( ! V_66 )
V_66 = V_86 ;
if ( ! V_66 )
F_25 ( V_80 L_12 ) ;
F_68 ( V_9 , V_87 , V_83 , L_13 ) ;
return V_66 ;
}
static int F_69 ( void * V_88 )
{
struct V_89 * V_90 = V_88 ;
unsigned V_91 ;
while ( 1 ) {
F_43 ( V_90 -> V_92 , F_44 ( & V_90 -> V_93 ) ||
F_70 () ) ;
if ( F_70 () ) {
V_90 -> V_94 = NULL ;
F_22 ( & V_90 -> V_87 , 1 ) ;
F_33 ( & V_90 -> V_95 ) ;
break;
}
F_22 ( & V_90 -> V_93 , 0 ) ;
for ( V_91 = 0 ; V_91 < V_90 -> V_96 ; V_91 ++ )
* V_90 -> V_57 = F_71 ( * V_90 -> V_57 ,
V_90 -> V_97 [ V_91 ] , * V_90 -> V_98 [ V_91 ] ) ;
F_22 ( & V_90 -> V_87 , 1 ) ;
F_33 ( & V_90 -> V_95 ) ;
}
return 0 ;
}
static int F_72 ( void * V_88 )
{
struct V_99 * V_90 = V_88 ;
while ( 1 ) {
F_43 ( V_90 -> V_92 , F_44 ( & V_90 -> V_93 ) ||
F_70 () ) ;
if ( F_70 () ) {
V_90 -> V_94 = NULL ;
V_90 -> V_66 = - 1 ;
F_22 ( & V_90 -> V_87 , 1 ) ;
F_33 ( & V_90 -> V_95 ) ;
break;
}
F_22 ( & V_90 -> V_93 , 0 ) ;
V_90 -> V_66 = F_73 ( V_90 -> V_97 , V_90 -> V_98 ,
V_90 -> V_100 + V_101 , & V_90 -> V_102 ,
V_90 -> V_103 ) ;
F_22 ( & V_90 -> V_87 , 1 ) ;
F_33 ( & V_90 -> V_95 ) ;
}
return 0 ;
}
static int F_74 ( struct V_45 * V_46 ,
struct V_81 * V_82 ,
unsigned int V_83 )
{
unsigned int V_84 ;
int V_66 = 0 ;
int V_85 ;
int V_86 ;
struct V_18 V_19 ;
T_3 V_9 ;
T_3 V_87 ;
T_4 V_104 ;
unsigned V_94 , V_96 , V_105 ;
unsigned char * V_24 = NULL ;
struct V_99 * V_88 = NULL ;
struct V_89 * V_106 = NULL ;
F_21 ( & V_19 ) ;
V_105 = F_75 () - 1 ;
V_105 = F_76 ( V_105 , 1 , V_107 ) ;
V_24 = ( void * ) F_52 ( V_39 | V_40 ) ;
if ( ! V_24 ) {
F_25 ( V_42 L_14 ) ;
V_66 = - V_15 ;
goto V_108;
}
V_88 = F_77 ( sizeof( * V_88 ) * V_105 ) ;
if ( ! V_88 ) {
F_25 ( V_42 L_15 ) ;
V_66 = - V_15 ;
goto V_108;
}
for ( V_94 = 0 ; V_94 < V_105 ; V_94 ++ )
memset ( & V_88 [ V_94 ] , 0 , F_78 ( struct V_99 , V_92 ) ) ;
V_106 = F_79 ( sizeof( * V_106 ) , V_14 ) ;
if ( ! V_106 ) {
F_25 ( V_42 L_16 ) ;
V_66 = - V_15 ;
goto V_108;
}
memset ( V_106 , 0 , F_78 ( struct V_89 , V_92 ) ) ;
for ( V_94 = 0 ; V_94 < V_105 ; V_94 ++ ) {
F_23 ( & V_88 [ V_94 ] . V_92 ) ;
F_23 ( & V_88 [ V_94 ] . V_95 ) ;
V_88 [ V_94 ] . V_94 = F_80 ( F_72 ,
& V_88 [ V_94 ] ,
L_17 , V_94 ) ;
if ( F_81 ( V_88 [ V_94 ] . V_94 ) ) {
V_88 [ V_94 ] . V_94 = NULL ;
F_25 ( V_42
L_18 ) ;
V_66 = - V_15 ;
goto V_108;
}
}
F_23 ( & V_106 -> V_92 ) ;
F_23 ( & V_106 -> V_95 ) ;
V_46 -> V_57 = 0 ;
V_106 -> V_57 = & V_46 -> V_57 ;
for ( V_94 = 0 ; V_94 < V_105 ; V_94 ++ ) {
V_106 -> V_97 [ V_94 ] = V_88 [ V_94 ] . V_97 ;
V_106 -> V_98 [ V_94 ] = & V_88 [ V_94 ] . V_98 ;
}
V_106 -> V_94 = F_80 ( F_69 , V_106 , L_19 ) ;
if ( F_81 ( V_106 -> V_94 ) ) {
V_106 -> V_94 = NULL ;
F_25 ( V_42 L_20 ) ;
V_66 = - V_15 ;
goto V_108;
}
V_46 -> F_4 = F_4 () ;
F_25 ( V_80
L_21
L_22 ,
V_105 , V_83 ) ;
V_84 = V_83 / 10 ;
if ( ! V_84 )
V_84 = 1 ;
V_85 = 0 ;
V_9 = F_65 () ;
for (; ; ) {
for ( V_94 = 0 ; V_94 < V_105 ; V_94 ++ ) {
for ( V_104 = 0 ; V_104 < V_109 ; V_104 += V_35 ) {
V_66 = F_66 ( V_82 ) ;
if ( V_66 < 0 )
goto V_110;
if ( ! V_66 )
break;
memcpy ( V_88 [ V_94 ] . V_97 + V_104 ,
F_67 ( * V_82 ) , V_35 ) ;
if ( ! ( V_85 % V_84 ) )
F_25 ( V_80
L_23
L_24 ,
V_85 / V_84 * 10 ) ;
V_85 ++ ;
}
if ( ! V_104 )
break;
V_88 [ V_94 ] . V_98 = V_104 ;
F_22 ( & V_88 [ V_94 ] . V_93 , 1 ) ;
F_33 ( & V_88 [ V_94 ] . V_92 ) ;
}
if ( ! V_94 )
break;
V_106 -> V_96 = V_94 ;
F_22 ( & V_106 -> V_93 , 1 ) ;
F_33 ( & V_106 -> V_92 ) ;
for ( V_96 = V_94 , V_94 = 0 ; V_94 < V_96 ; V_94 ++ ) {
F_43 ( V_88 [ V_94 ] . V_95 ,
F_44 ( & V_88 [ V_94 ] . V_87 ) ) ;
F_22 ( & V_88 [ V_94 ] . V_87 , 0 ) ;
V_66 = V_88 [ V_94 ] . V_66 ;
if ( V_66 < 0 ) {
F_25 ( V_42 L_25 ) ;
goto V_110;
}
if ( F_82 ( ! V_88 [ V_94 ] . V_102 ||
V_88 [ V_94 ] . V_102 >
F_83 ( V_88 [ V_94 ] . V_98 ) ) ) {
F_25 ( V_42
L_26 ) ;
V_66 = - 1 ;
goto V_110;
}
* ( T_4 * ) V_88 [ V_94 ] . V_100 = V_88 [ V_94 ] . V_102 ;
for ( V_104 = 0 ;
V_104 < V_101 + V_88 [ V_94 ] . V_102 ;
V_104 += V_35 ) {
memcpy ( V_24 , V_88 [ V_94 ] . V_100 + V_104 , V_35 ) ;
V_66 = F_60 ( V_46 , V_24 , & V_19 ) ;
if ( V_66 )
goto V_110;
}
}
F_43 ( V_106 -> V_95 , F_44 ( & V_106 -> V_87 ) ) ;
F_22 ( & V_106 -> V_87 , 0 ) ;
}
V_110:
V_86 = F_42 ( & V_19 ) ;
V_87 = F_65 () ;
if ( ! V_66 )
V_66 = V_86 ;
if ( ! V_66 )
F_25 ( V_80 L_12 ) ;
F_68 ( V_9 , V_87 , V_83 , L_13 ) ;
V_108:
if ( V_106 ) {
if ( V_106 -> V_94 )
F_84 ( V_106 -> V_94 ) ;
F_19 ( V_106 ) ;
}
if ( V_88 ) {
for ( V_94 = 0 ; V_94 < V_105 ; V_94 ++ )
if ( V_88 [ V_94 ] . V_94 )
F_84 ( V_88 [ V_94 ] . V_94 ) ;
F_85 ( V_88 ) ;
}
if ( V_24 ) F_56 ( ( unsigned long ) V_24 ) ;
return V_66 ;
}
static int F_86 ( unsigned int V_85 , unsigned int V_47 )
{
unsigned int V_111 = F_87 ( V_62 , 1 ) ;
unsigned int V_112 ;
F_88 ( L_27 , V_111 ) ;
V_112 = V_113 + V_85 ;
return V_111 > V_112 ;
}
int F_89 ( unsigned int V_47 )
{
struct V_45 V_46 ;
struct V_81 V_82 ;
struct V_114 * V_115 ;
unsigned long V_116 ;
int error ;
V_116 = F_90 () ;
error = F_57 ( & V_46 ) ;
if ( error ) {
F_25 ( V_42 L_28 ) ;
return error ;
}
if ( V_47 & V_117 ) {
if ( ! F_86 ( V_116 , V_47 ) ) {
F_25 ( V_42 L_29 ) ;
error = - V_67 ;
goto V_110;
}
}
memset ( & V_82 , 0 , sizeof( struct V_81 ) ) ;
error = F_66 ( & V_82 ) ;
if ( error < V_35 ) {
if ( error >= 0 )
error = - V_43 ;
goto V_110;
}
V_115 = (struct V_114 * ) F_67 ( V_82 ) ;
error = F_60 ( & V_46 , V_115 , NULL ) ;
if ( ! error ) {
error = ( V_47 & V_117 ) ?
F_64 ( & V_46 , & V_82 , V_116 - 1 ) :
F_74 ( & V_46 , & V_82 , V_116 - 1 ) ;
}
V_110:
error = F_63 ( & V_46 , V_47 , error ) ;
return error ;
}
static void F_91 ( struct V_45 * V_46 )
{
struct V_118 * V_119 ;
while ( V_46 -> V_120 ) {
if ( V_46 -> V_120 -> V_121 )
F_56 ( ( unsigned long ) V_46 -> V_120 -> V_121 ) ;
V_119 = V_46 -> V_120 ;
V_46 -> V_120 = V_46 -> V_120 -> V_122 ;
F_19 ( V_119 ) ;
}
V_46 -> V_70 = NULL ;
}
static int F_92 ( struct V_45 * V_46 ,
unsigned int * V_123 )
{
int error ;
struct V_118 * V_119 , * V_124 ;
T_1 V_17 ;
* V_123 = V_50 -> V_47 ;
if ( ! V_50 -> V_54 )
return - V_13 ;
V_46 -> V_70 = NULL ;
V_124 = V_46 -> V_120 = NULL ;
V_17 = V_50 -> V_54 ;
while ( V_17 ) {
V_119 = F_79 ( sizeof( * V_46 -> V_120 ) , V_14 ) ;
if ( ! V_119 ) {
F_91 ( V_46 ) ;
return - V_15 ;
}
memset ( V_119 , 0 , sizeof( * V_119 ) ) ;
if ( ! V_46 -> V_120 )
V_46 -> V_120 = V_119 ;
if ( V_124 )
V_124 -> V_122 = V_119 ;
V_124 = V_119 ;
V_119 -> V_121 = (struct V_71 * )
F_52 ( V_39 | V_40 ) ;
if ( ! V_119 -> V_121 ) {
F_91 ( V_46 ) ;
return - V_15 ;
}
error = F_35 ( V_48 , V_17 , V_119 -> V_121 , NULL ) ;
if ( error ) {
F_91 ( V_46 ) ;
return error ;
}
V_17 = V_119 -> V_121 -> V_78 ;
}
V_46 -> V_75 = 0 ;
V_46 -> V_70 = V_46 -> V_120 -> V_121 ;
return 0 ;
}
static int F_93 ( struct V_45 * V_46 , void * V_64 ,
struct V_18 * V_19 )
{
T_1 V_17 ;
int error ;
struct V_118 * V_119 ;
if ( ! V_46 -> V_70 )
return - V_13 ;
V_17 = V_46 -> V_70 -> V_76 [ V_46 -> V_75 ] ;
if ( ! V_17 )
return - V_43 ;
error = F_35 ( V_48 , V_17 , V_64 , V_19 ) ;
if ( error )
return error ;
if ( ++ V_46 -> V_75 >= V_77 ) {
V_46 -> V_75 = 0 ;
F_56 ( ( unsigned long ) V_46 -> V_120 -> V_121 ) ;
V_119 = V_46 -> V_120 ;
V_46 -> V_120 = V_46 -> V_120 -> V_122 ;
F_19 ( V_119 ) ;
if ( ! V_46 -> V_120 )
F_91 ( V_46 ) ;
else
V_46 -> V_70 = V_46 -> V_120 -> V_121 ;
}
return error ;
}
static int F_94 ( struct V_45 * V_46 )
{
F_91 ( V_46 ) ;
return 0 ;
}
static int F_95 ( struct V_45 * V_46 ,
struct V_81 * V_82 ,
unsigned int V_125 )
{
unsigned int V_84 ;
int V_66 = 0 ;
T_3 V_9 ;
T_3 V_87 ;
struct V_18 V_19 ;
int V_86 ;
unsigned V_85 ;
F_21 ( & V_19 ) ;
V_34 = true ;
F_25 ( V_80 L_30 ,
V_125 ) ;
V_84 = V_125 / 10 ;
if ( ! V_84 )
V_84 = 1 ;
V_85 = 0 ;
V_9 = F_65 () ;
for ( ; ; ) {
V_66 = F_96 ( V_82 ) ;
if ( V_66 <= 0 )
break;
V_66 = F_93 ( V_46 , F_67 ( * V_82 ) , & V_19 ) ;
if ( V_66 )
break;
if ( V_82 -> V_126 )
V_66 = F_42 ( & V_19 ) ;
if ( V_66 )
break;
if ( ! ( V_85 % V_84 ) )
F_25 ( V_80 L_31 ,
V_85 / V_84 * 10 ) ;
V_85 ++ ;
}
V_86 = F_42 ( & V_19 ) ;
V_87 = F_65 () ;
if ( ! V_66 )
V_66 = V_86 ;
if ( ! V_66 ) {
F_25 ( V_80 L_32 ) ;
F_97 ( V_82 ) ;
if ( ! F_98 ( V_82 ) )
V_66 = - V_127 ;
}
F_68 ( V_9 , V_87 , V_125 , L_33 ) ;
return V_66 ;
}
static int F_99 ( void * V_88 )
{
struct V_128 * V_90 = V_88 ;
while ( 1 ) {
F_43 ( V_90 -> V_92 , F_44 ( & V_90 -> V_93 ) ||
F_70 () ) ;
if ( F_70 () ) {
V_90 -> V_94 = NULL ;
V_90 -> V_66 = - 1 ;
F_22 ( & V_90 -> V_87 , 1 ) ;
F_33 ( & V_90 -> V_95 ) ;
break;
}
F_22 ( & V_90 -> V_93 , 0 ) ;
V_90 -> V_98 = V_109 ;
V_90 -> V_66 = F_100 ( V_90 -> V_100 + V_101 , V_90 -> V_102 ,
V_90 -> V_97 , & V_90 -> V_98 ) ;
if ( V_129 )
F_30 ( ( unsigned long ) V_90 -> V_97 ,
( unsigned long ) V_90 -> V_97 + V_90 -> V_98 ) ;
F_22 ( & V_90 -> V_87 , 1 ) ;
F_33 ( & V_90 -> V_95 ) ;
}
return 0 ;
}
static int F_101 ( struct V_45 * V_46 ,
struct V_81 * V_82 ,
unsigned int V_125 )
{
unsigned int V_84 ;
int V_66 = 0 ;
int V_130 = 0 ;
struct V_18 V_19 ;
T_3 V_9 ;
T_3 V_87 ;
unsigned V_85 ;
T_4 V_104 ;
unsigned V_91 , V_94 , V_96 , V_105 ;
unsigned V_131 = 0 , V_132 = 0 , V_133 = 0 ,
V_134 = 0 , V_135 , V_136 , V_137 = 0 ;
unsigned long V_138 = 0 ;
unsigned char * * V_24 = NULL ;
struct V_128 * V_88 = NULL ;
struct V_89 * V_106 = NULL ;
F_21 ( & V_19 ) ;
V_105 = F_75 () - 1 ;
V_105 = F_76 ( V_105 , 1 , V_107 ) ;
V_24 = F_77 ( sizeof( * V_24 ) * V_139 ) ;
if ( ! V_24 ) {
F_25 ( V_42 L_14 ) ;
V_66 = - V_15 ;
goto V_108;
}
V_88 = F_77 ( sizeof( * V_88 ) * V_105 ) ;
if ( ! V_88 ) {
F_25 ( V_42 L_15 ) ;
V_66 = - V_15 ;
goto V_108;
}
for ( V_94 = 0 ; V_94 < V_105 ; V_94 ++ )
memset ( & V_88 [ V_94 ] , 0 , F_78 ( struct V_128 , V_92 ) ) ;
V_106 = F_79 ( sizeof( * V_106 ) , V_14 ) ;
if ( ! V_106 ) {
F_25 ( V_42 L_16 ) ;
V_66 = - V_15 ;
goto V_108;
}
memset ( V_106 , 0 , F_78 ( struct V_89 , V_92 ) ) ;
V_129 = true ;
for ( V_94 = 0 ; V_94 < V_105 ; V_94 ++ ) {
F_23 ( & V_88 [ V_94 ] . V_92 ) ;
F_23 ( & V_88 [ V_94 ] . V_95 ) ;
V_88 [ V_94 ] . V_94 = F_80 ( F_99 ,
& V_88 [ V_94 ] ,
L_34 , V_94 ) ;
if ( F_81 ( V_88 [ V_94 ] . V_94 ) ) {
V_88 [ V_94 ] . V_94 = NULL ;
F_25 ( V_42
L_35 ) ;
V_66 = - V_15 ;
goto V_108;
}
}
F_23 ( & V_106 -> V_92 ) ;
F_23 ( & V_106 -> V_95 ) ;
V_46 -> V_57 = 0 ;
V_106 -> V_57 = & V_46 -> V_57 ;
for ( V_94 = 0 ; V_94 < V_105 ; V_94 ++ ) {
V_106 -> V_97 [ V_94 ] = V_88 [ V_94 ] . V_97 ;
V_106 -> V_98 [ V_94 ] = & V_88 [ V_94 ] . V_98 ;
}
V_106 -> V_94 = F_80 ( F_69 , V_106 , L_19 ) ;
if ( F_81 ( V_106 -> V_94 ) ) {
V_106 -> V_94 = NULL ;
F_25 ( V_42 L_20 ) ;
V_66 = - V_15 ;
goto V_108;
}
if ( F_1 () > F_90 () )
V_138 = ( F_1 () - F_90 () ) / 2 ;
V_138 = F_76 ( V_138 , V_140 , V_139 ) ;
for ( V_91 = 0 ; V_91 < V_138 ; V_91 ++ ) {
V_24 [ V_91 ] = ( void * ) F_52 ( V_91 < V_141 ?
V_39 | V_40 :
V_39 | V_68 |
V_69 ) ;
if ( ! V_24 [ V_91 ] ) {
if ( V_91 < V_141 ) {
V_133 = V_91 ;
F_25 ( V_42
L_36 ) ;
V_66 = - V_15 ;
goto V_108;
} else {
break;
}
}
}
V_135 = V_133 = V_91 ;
F_25 ( V_80
L_37
L_38 ,
V_105 , V_125 ) ;
V_84 = V_125 / 10 ;
if ( ! V_84 )
V_84 = 1 ;
V_85 = 0 ;
V_9 = F_65 () ;
V_66 = F_96 ( V_82 ) ;
if ( V_66 <= 0 )
goto V_110;
for(; ; ) {
for ( V_91 = 0 ; ! V_130 && V_91 < V_135 ; V_91 ++ ) {
V_66 = F_93 ( V_46 , V_24 [ V_131 ] , & V_19 ) ;
if ( V_66 ) {
if ( V_46 -> V_70 &&
V_46 -> V_70 -> V_76 [ V_46 -> V_75 ] ) {
goto V_110;
} else {
V_130 = 1 ;
break;
}
}
if ( ++ V_131 >= V_133 )
V_131 = 0 ;
}
V_137 += V_91 ;
V_135 -= V_91 ;
if ( ! V_134 ) {
if ( ! V_137 )
break;
V_66 = F_42 ( & V_19 ) ;
if ( V_66 )
goto V_110;
V_134 += V_137 ;
V_137 = 0 ;
if ( V_130 )
V_130 = 2 ;
}
if ( V_106 -> V_96 ) {
F_43 ( V_106 -> V_95 , F_44 ( & V_106 -> V_87 ) ) ;
F_22 ( & V_106 -> V_87 , 0 ) ;
V_106 -> V_96 = 0 ;
}
for ( V_94 = 0 ; V_134 && V_94 < V_105 ; V_94 ++ ) {
V_88 [ V_94 ] . V_102 = * ( T_4 * ) V_24 [ V_132 ] ;
if ( F_82 ( ! V_88 [ V_94 ] . V_102 ||
V_88 [ V_94 ] . V_102 >
F_83 ( V_109 ) ) ) {
F_25 ( V_42
L_26 ) ;
V_66 = - 1 ;
goto V_110;
}
V_136 = F_102 ( V_88 [ V_94 ] . V_102 + V_101 ,
V_35 ) ;
if ( V_136 > V_134 ) {
if ( V_130 > 1 ) {
V_66 = - 1 ;
goto V_110;
}
break;
}
for ( V_104 = 0 ;
V_104 < V_101 + V_88 [ V_94 ] . V_102 ;
V_104 += V_35 ) {
memcpy ( V_88 [ V_94 ] . V_100 + V_104 ,
V_24 [ V_132 ] , V_35 ) ;
V_134 -- ;
V_135 ++ ;
if ( ++ V_132 >= V_133 )
V_132 = 0 ;
}
F_22 ( & V_88 [ V_94 ] . V_93 , 1 ) ;
F_33 ( & V_88 [ V_94 ] . V_92 ) ;
}
if ( V_134 < V_141 && V_137 ) {
V_66 = F_42 ( & V_19 ) ;
if ( V_66 )
goto V_110;
V_134 += V_137 ;
V_137 = 0 ;
if ( V_130 )
V_130 = 2 ;
}
for ( V_96 = V_94 , V_94 = 0 ; V_94 < V_96 ; V_94 ++ ) {
F_43 ( V_88 [ V_94 ] . V_95 ,
F_44 ( & V_88 [ V_94 ] . V_87 ) ) ;
F_22 ( & V_88 [ V_94 ] . V_87 , 0 ) ;
V_66 = V_88 [ V_94 ] . V_66 ;
if ( V_66 < 0 ) {
F_25 ( V_42
L_39 ) ;
goto V_110;
}
if ( F_82 ( ! V_88 [ V_94 ] . V_98 ||
V_88 [ V_94 ] . V_98 > V_109 ||
V_88 [ V_94 ] . V_98 & ( V_35 - 1 ) ) ) {
F_25 ( V_42
L_40 ) ;
V_66 = - 1 ;
goto V_110;
}
for ( V_104 = 0 ;
V_104 < V_88 [ V_94 ] . V_98 ; V_104 += V_35 ) {
memcpy ( F_67 ( * V_82 ) ,
V_88 [ V_94 ] . V_97 + V_104 , V_35 ) ;
if ( ! ( V_85 % V_84 ) )
F_25 ( V_80
L_41
L_24 ,
V_85 / V_84 * 10 ) ;
V_85 ++ ;
V_66 = F_96 ( V_82 ) ;
if ( V_66 <= 0 ) {
V_106 -> V_96 = V_94 + 1 ;
F_22 ( & V_106 -> V_93 , 1 ) ;
F_33 ( & V_106 -> V_92 ) ;
goto V_110;
}
}
}
V_106 -> V_96 = V_94 ;
F_22 ( & V_106 -> V_93 , 1 ) ;
F_33 ( & V_106 -> V_92 ) ;
}
V_110:
if ( V_106 -> V_96 ) {
F_43 ( V_106 -> V_95 , F_44 ( & V_106 -> V_87 ) ) ;
F_22 ( & V_106 -> V_87 , 0 ) ;
}
V_87 = F_65 () ;
if ( ! V_66 ) {
F_25 ( V_80 L_32 ) ;
F_97 ( V_82 ) ;
if ( ! F_98 ( V_82 ) )
V_66 = - V_127 ;
if ( ! V_66 ) {
if ( V_50 -> V_47 & V_56 ) {
if( V_46 -> V_57 != V_50 -> V_57 ) {
F_25 ( V_42
L_42 ) ;
V_66 = - V_127 ;
}
}
}
}
F_68 ( V_9 , V_87 , V_125 , L_33 ) ;
V_108:
for ( V_91 = 0 ; V_91 < V_133 ; V_91 ++ )
F_56 ( ( unsigned long ) V_24 [ V_91 ] ) ;
if ( V_106 ) {
if ( V_106 -> V_94 )
F_84 ( V_106 -> V_94 ) ;
F_19 ( V_106 ) ;
}
if ( V_88 ) {
for ( V_94 = 0 ; V_94 < V_105 ; V_94 ++ )
if ( V_88 [ V_94 ] . V_94 )
F_84 ( V_88 [ V_94 ] . V_94 ) ;
F_85 ( V_88 ) ;
}
F_85 ( V_24 ) ;
return V_66 ;
}
int F_103 ( unsigned int * V_123 )
{
int error ;
struct V_45 V_46 ;
struct V_81 V_82 ;
struct V_114 * V_115 ;
memset ( & V_82 , 0 , sizeof( struct V_81 ) ) ;
error = F_96 ( & V_82 ) ;
if ( error < V_35 )
return error < 0 ? error : - V_43 ;
V_115 = (struct V_114 * ) F_67 ( V_82 ) ;
error = F_92 ( & V_46 , V_123 ) ;
if ( error )
goto V_11;
if ( ! error )
error = F_93 ( & V_46 , V_115 , NULL ) ;
if ( ! error ) {
error = ( * V_123 & V_117 ) ?
F_95 ( & V_46 , & V_82 , V_115 -> V_116 - 1 ) :
F_101 ( & V_46 , & V_82 , V_115 -> V_116 - 1 ) ;
}
F_94 ( & V_46 ) ;
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
V_41 = F_105 ( V_61 ,
V_142 , NULL ) ;
if ( ! F_81 ( V_41 ) ) {
F_49 ( V_41 , V_35 ) ;
F_61 ( V_50 ) ;
error = F_35 ( V_48 , V_49 ,
V_50 , NULL ) ;
if ( error )
goto V_143;
if ( ! memcmp ( V_53 , V_50 -> V_51 , 10 ) ) {
memcpy ( V_50 -> V_51 , V_50 -> V_52 , 10 ) ;
error = F_35 ( V_58 , V_49 ,
V_50 , NULL ) ;
} else {
error = - V_13 ;
}
V_143:
if ( error )
F_50 ( V_41 , V_142 ) ;
else
F_88 ( L_45 ) ;
} else {
error = F_106 ( V_41 ) ;
}
if ( error )
F_88 ( L_46 , error ) ;
return error ;
}
void F_59 ( T_5 V_144 )
{
if ( F_81 ( V_41 ) ) {
F_88 ( L_47 ) ;
return;
}
F_50 ( V_41 , V_144 ) ;
}
int F_107 ( void )
{
int error ;
F_35 ( V_48 , V_49 , V_50 , NULL ) ;
if ( ! memcmp ( V_53 , V_50 -> V_51 , 10 ) ) {
memcpy ( V_50 -> V_51 , V_50 -> V_52 , 10 ) ;
error = F_35 ( V_58 , V_49 ,
V_50 , NULL ) ;
} else {
F_25 ( V_42 L_48 ) ;
error = - V_59 ;
}
F_16 ( V_62 ) ;
return error ;
}
static int F_108 ( void )
{
V_50 = (struct V_50 * ) F_52 ( V_14 ) ;
if ( ! V_50 )
F_109 ( L_49 ) ;
return 0 ;
}
