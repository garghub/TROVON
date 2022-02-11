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
if ( V_22 -> V_27 && ! V_19 -> error )
V_19 -> error = V_22 -> V_27 ;
if ( F_30 ( & V_19 -> V_20 ) )
F_31 ( & V_19 -> V_21 ) ;
F_32 ( V_22 ) ;
}
static int F_33 ( int V_34 , T_2 V_35 , void * V_36 ,
struct V_18 * V_19 )
{
struct V_24 * V_24 = F_34 ( V_36 ) ;
struct V_22 * V_22 ;
int error = 0 ;
V_22 = F_35 ( V_37 | V_38 , 1 ) ;
V_22 -> V_31 . V_32 = V_35 * ( V_39 >> 9 ) ;
V_22 -> V_29 = V_40 ;
if ( F_36 ( V_22 , V_24 , V_39 , 0 ) < V_39 ) {
F_25 ( V_41 L_2 ,
( unsigned long long ) V_22 -> V_31 . V_32 ) ;
F_32 ( V_22 ) ;
return - V_42 ;
}
if ( V_19 ) {
V_22 -> V_43 = F_24 ;
V_22 -> V_23 = V_19 ;
F_37 ( & V_19 -> V_20 ) ;
F_38 ( V_34 , V_22 ) ;
} else {
error = F_39 ( V_34 , V_22 ) ;
F_32 ( V_22 ) ;
}
return error ;
}
static int F_40 ( struct V_18 * V_19 )
{
F_41 ( V_19 -> V_21 , F_42 ( & V_19 -> V_20 ) == 0 ) ;
return V_19 -> error ;
}
static int F_43 ( struct V_44 * V_45 , unsigned int V_46 )
{
int error ;
F_33 ( V_47 , V_48 , V_49 , NULL ) ;
if ( ! memcmp ( L_3 , V_49 -> V_50 , 10 ) ||
! memcmp ( L_4 , V_49 -> V_50 , 10 ) ) {
memcpy ( V_49 -> V_51 , V_49 -> V_50 , 10 ) ;
memcpy ( V_49 -> V_50 , V_52 , 10 ) ;
V_49 -> V_53 = V_45 -> V_54 ;
V_49 -> V_46 = V_46 ;
if ( V_46 & V_55 )
V_49 -> V_56 = V_45 -> V_56 ;
error = F_33 ( V_57 , V_48 ,
V_49 , NULL ) ;
} else {
F_25 ( V_41 L_5 ) ;
error = - V_58 ;
}
return error ;
}
static int F_44 ( void )
{
int V_59 ;
V_59 = F_45 ( V_60 , V_48 ,
& V_40 ) ;
if ( V_59 < 0 )
return V_59 ;
V_61 = V_59 ;
V_59 = F_46 ( V_40 , V_62 , NULL ) ;
if ( V_59 )
return V_59 ;
V_59 = F_47 ( V_40 , V_39 ) ;
if ( V_59 < 0 )
F_48 ( V_40 , V_62 ) ;
return V_59 ;
}
static int F_49 ( void * V_63 , T_1 V_17 , struct V_18 * V_19 )
{
void * V_64 ;
int V_65 ;
if ( ! V_17 )
return - V_66 ;
if ( V_19 ) {
V_64 = ( void * ) F_50 ( V_37 | V_67 |
V_68 ) ;
if ( V_64 ) {
F_51 ( V_64 , V_63 ) ;
} else {
V_65 = F_40 ( V_19 ) ;
if ( V_65 )
return V_65 ;
V_64 = ( void * ) F_50 ( V_37 |
V_67 |
V_68 ) ;
if ( V_64 ) {
F_51 ( V_64 , V_63 ) ;
} else {
F_52 ( 1 ) ;
V_19 = NULL ;
V_64 = V_63 ;
}
}
} else {
V_64 = V_63 ;
}
return F_33 ( V_57 , V_17 , V_64 , V_19 ) ;
}
static void F_53 ( struct V_44 * V_45 )
{
if ( V_45 -> V_69 )
F_54 ( ( unsigned long ) V_45 -> V_69 ) ;
V_45 -> V_69 = NULL ;
}
static int F_55 ( struct V_44 * V_45 )
{
int V_65 ;
V_65 = F_44 () ;
if ( V_65 ) {
if ( V_65 != - V_66 )
F_25 ( V_41 L_6
L_7 ) ;
return V_65 ;
}
V_45 -> V_69 = (struct V_70 * ) F_56 ( V_14 ) ;
if ( ! V_45 -> V_69 ) {
V_65 = - V_15 ;
goto V_71;
}
V_45 -> V_72 = F_10 ( V_61 ) ;
if ( ! V_45 -> V_72 ) {
V_65 = - V_66 ;
goto V_73;
}
V_45 -> V_74 = 0 ;
V_45 -> F_4 = F_4 () ;
V_45 -> V_54 = V_45 -> V_72 ;
return 0 ;
V_73:
F_53 ( V_45 ) ;
V_71:
F_57 ( V_62 ) ;
return V_65 ;
}
static int F_58 ( struct V_44 * V_45 , void * V_63 ,
struct V_18 * V_19 )
{
int error = 0 ;
T_1 V_17 ;
if ( ! V_45 -> V_69 )
return - V_13 ;
V_17 = F_10 ( V_61 ) ;
error = F_49 ( V_63 , V_17 , V_19 ) ;
if ( error )
return error ;
V_45 -> V_69 -> V_75 [ V_45 -> V_74 ++ ] = V_17 ;
if ( V_45 -> V_74 >= V_76 ) {
V_17 = F_10 ( V_61 ) ;
if ( ! V_17 )
return - V_66 ;
V_45 -> V_69 -> V_77 = V_17 ;
error = F_49 ( V_45 -> V_69 , V_45 -> V_72 , V_19 ) ;
if ( error )
goto V_78;
F_59 ( V_45 -> V_69 ) ;
V_45 -> V_72 = V_17 ;
V_45 -> V_74 = 0 ;
if ( V_19 && F_1 () <= V_45 -> F_4 ) {
error = F_40 ( V_19 ) ;
if ( error )
goto V_78;
V_45 -> F_4 = F_4 () ;
}
}
V_78:
return error ;
}
static int F_60 ( struct V_44 * V_45 )
{
if ( V_45 -> V_69 && V_45 -> V_72 )
return F_49 ( V_45 -> V_69 , V_45 -> V_72 , NULL ) ;
else
return - V_13 ;
}
static int F_61 ( struct V_44 * V_45 ,
unsigned int V_46 , int error )
{
if ( ! error ) {
F_60 ( V_45 ) ;
F_25 ( V_79 L_8 ) ;
error = F_43 ( V_45 , V_46 ) ;
F_25 ( L_9 ) ;
}
if ( error )
F_16 ( V_61 ) ;
F_53 ( V_45 ) ;
F_57 ( V_62 ) ;
return error ;
}
static int F_62 ( struct V_44 * V_45 ,
struct V_80 * V_81 ,
unsigned int V_82 )
{
unsigned int V_83 ;
int V_65 ;
int V_84 ;
int V_85 ;
struct V_18 V_19 ;
T_3 V_9 ;
T_3 V_86 ;
F_21 ( & V_19 ) ;
F_25 ( V_79 L_10 ,
V_82 ) ;
V_83 = V_82 / 10 ;
if ( ! V_83 )
V_83 = 1 ;
V_84 = 0 ;
V_9 = F_63 () ;
while ( 1 ) {
V_65 = F_64 ( V_81 ) ;
if ( V_65 <= 0 )
break;
V_65 = F_58 ( V_45 , F_65 ( * V_81 ) , & V_19 ) ;
if ( V_65 )
break;
if ( ! ( V_84 % V_83 ) )
F_25 ( V_79 L_11 ,
V_84 / V_83 * 10 ) ;
V_84 ++ ;
}
V_85 = F_40 ( & V_19 ) ;
V_86 = F_63 () ;
if ( ! V_65 )
V_65 = V_85 ;
if ( ! V_65 )
F_25 ( V_79 L_12 ) ;
F_66 ( V_9 , V_86 , V_82 , L_13 ) ;
return V_65 ;
}
static int F_67 ( void * V_87 )
{
struct V_88 * V_89 = V_87 ;
unsigned V_90 ;
while ( 1 ) {
F_41 ( V_89 -> V_91 , F_42 ( & V_89 -> V_92 ) ||
F_68 () ) ;
if ( F_68 () ) {
V_89 -> V_93 = NULL ;
F_22 ( & V_89 -> V_86 , 1 ) ;
F_31 ( & V_89 -> V_94 ) ;
break;
}
F_22 ( & V_89 -> V_92 , 0 ) ;
for ( V_90 = 0 ; V_90 < V_89 -> V_95 ; V_90 ++ )
* V_89 -> V_56 = F_69 ( * V_89 -> V_56 ,
V_89 -> V_96 [ V_90 ] , * V_89 -> V_97 [ V_90 ] ) ;
F_22 ( & V_89 -> V_86 , 1 ) ;
F_31 ( & V_89 -> V_94 ) ;
}
return 0 ;
}
static int F_70 ( void * V_87 )
{
struct V_98 * V_89 = V_87 ;
while ( 1 ) {
F_41 ( V_89 -> V_91 , F_42 ( & V_89 -> V_92 ) ||
F_68 () ) ;
if ( F_68 () ) {
V_89 -> V_93 = NULL ;
V_89 -> V_65 = - 1 ;
F_22 ( & V_89 -> V_86 , 1 ) ;
F_31 ( & V_89 -> V_94 ) ;
break;
}
F_22 ( & V_89 -> V_92 , 0 ) ;
V_89 -> V_65 = F_71 ( V_89 -> V_96 , V_89 -> V_97 ,
V_89 -> V_99 + V_100 , & V_89 -> V_101 ,
V_89 -> V_102 ) ;
F_22 ( & V_89 -> V_86 , 1 ) ;
F_31 ( & V_89 -> V_94 ) ;
}
return 0 ;
}
static int F_72 ( struct V_44 * V_45 ,
struct V_80 * V_81 ,
unsigned int V_82 )
{
unsigned int V_83 ;
int V_65 = 0 ;
int V_84 ;
int V_85 ;
struct V_18 V_19 ;
T_3 V_9 ;
T_3 V_86 ;
T_4 V_103 ;
unsigned V_93 , V_95 , V_104 ;
unsigned char * V_24 = NULL ;
struct V_98 * V_87 = NULL ;
struct V_88 * V_105 = NULL ;
F_21 ( & V_19 ) ;
V_104 = F_73 () - 1 ;
V_104 = F_74 ( V_104 , 1 , V_106 ) ;
V_24 = ( void * ) F_50 ( V_37 | V_38 ) ;
if ( ! V_24 ) {
F_25 ( V_41 L_14 ) ;
V_65 = - V_15 ;
goto V_107;
}
V_87 = F_75 ( sizeof( * V_87 ) * V_104 ) ;
if ( ! V_87 ) {
F_25 ( V_41 L_15 ) ;
V_65 = - V_15 ;
goto V_107;
}
for ( V_93 = 0 ; V_93 < V_104 ; V_93 ++ )
memset ( & V_87 [ V_93 ] , 0 , F_76 ( struct V_98 , V_91 ) ) ;
V_105 = F_77 ( sizeof( * V_105 ) , V_14 ) ;
if ( ! V_105 ) {
F_25 ( V_41 L_16 ) ;
V_65 = - V_15 ;
goto V_107;
}
memset ( V_105 , 0 , F_76 ( struct V_88 , V_91 ) ) ;
for ( V_93 = 0 ; V_93 < V_104 ; V_93 ++ ) {
F_23 ( & V_87 [ V_93 ] . V_91 ) ;
F_23 ( & V_87 [ V_93 ] . V_94 ) ;
V_87 [ V_93 ] . V_93 = F_78 ( F_70 ,
& V_87 [ V_93 ] ,
L_17 , V_93 ) ;
if ( F_79 ( V_87 [ V_93 ] . V_93 ) ) {
V_87 [ V_93 ] . V_93 = NULL ;
F_25 ( V_41
L_18 ) ;
V_65 = - V_15 ;
goto V_107;
}
}
F_23 ( & V_105 -> V_91 ) ;
F_23 ( & V_105 -> V_94 ) ;
V_45 -> V_56 = 0 ;
V_105 -> V_56 = & V_45 -> V_56 ;
for ( V_93 = 0 ; V_93 < V_104 ; V_93 ++ ) {
V_105 -> V_96 [ V_93 ] = V_87 [ V_93 ] . V_96 ;
V_105 -> V_97 [ V_93 ] = & V_87 [ V_93 ] . V_97 ;
}
V_105 -> V_93 = F_78 ( F_67 , V_105 , L_19 ) ;
if ( F_79 ( V_105 -> V_93 ) ) {
V_105 -> V_93 = NULL ;
F_25 ( V_41 L_20 ) ;
V_65 = - V_15 ;
goto V_107;
}
V_45 -> F_4 = F_4 () ;
F_25 ( V_79
L_21
L_22 ,
V_104 , V_82 ) ;
V_83 = V_82 / 10 ;
if ( ! V_83 )
V_83 = 1 ;
V_84 = 0 ;
V_9 = F_63 () ;
for (; ; ) {
for ( V_93 = 0 ; V_93 < V_104 ; V_93 ++ ) {
for ( V_103 = 0 ; V_103 < V_108 ; V_103 += V_39 ) {
V_65 = F_64 ( V_81 ) ;
if ( V_65 < 0 )
goto V_109;
if ( ! V_65 )
break;
memcpy ( V_87 [ V_93 ] . V_96 + V_103 ,
F_65 ( * V_81 ) , V_39 ) ;
if ( ! ( V_84 % V_83 ) )
F_25 ( V_79
L_23
L_24 ,
V_84 / V_83 * 10 ) ;
V_84 ++ ;
}
if ( ! V_103 )
break;
V_87 [ V_93 ] . V_97 = V_103 ;
F_22 ( & V_87 [ V_93 ] . V_92 , 1 ) ;
F_31 ( & V_87 [ V_93 ] . V_91 ) ;
}
if ( ! V_93 )
break;
V_105 -> V_95 = V_93 ;
F_22 ( & V_105 -> V_92 , 1 ) ;
F_31 ( & V_105 -> V_91 ) ;
for ( V_95 = V_93 , V_93 = 0 ; V_93 < V_95 ; V_93 ++ ) {
F_41 ( V_87 [ V_93 ] . V_94 ,
F_42 ( & V_87 [ V_93 ] . V_86 ) ) ;
F_22 ( & V_87 [ V_93 ] . V_86 , 0 ) ;
V_65 = V_87 [ V_93 ] . V_65 ;
if ( V_65 < 0 ) {
F_25 ( V_41 L_25 ) ;
goto V_109;
}
if ( F_80 ( ! V_87 [ V_93 ] . V_101 ||
V_87 [ V_93 ] . V_101 >
F_81 ( V_87 [ V_93 ] . V_97 ) ) ) {
F_25 ( V_41
L_26 ) ;
V_65 = - 1 ;
goto V_109;
}
* ( T_4 * ) V_87 [ V_93 ] . V_99 = V_87 [ V_93 ] . V_101 ;
for ( V_103 = 0 ;
V_103 < V_100 + V_87 [ V_93 ] . V_101 ;
V_103 += V_39 ) {
memcpy ( V_24 , V_87 [ V_93 ] . V_99 + V_103 , V_39 ) ;
V_65 = F_58 ( V_45 , V_24 , & V_19 ) ;
if ( V_65 )
goto V_109;
}
}
F_41 ( V_105 -> V_94 , F_42 ( & V_105 -> V_86 ) ) ;
F_22 ( & V_105 -> V_86 , 0 ) ;
}
V_109:
V_85 = F_40 ( & V_19 ) ;
V_86 = F_63 () ;
if ( ! V_65 )
V_65 = V_85 ;
if ( ! V_65 )
F_25 ( V_79 L_12 ) ;
F_66 ( V_9 , V_86 , V_82 , L_13 ) ;
V_107:
if ( V_105 ) {
if ( V_105 -> V_93 )
F_82 ( V_105 -> V_93 ) ;
F_19 ( V_105 ) ;
}
if ( V_87 ) {
for ( V_93 = 0 ; V_93 < V_104 ; V_93 ++ )
if ( V_87 [ V_93 ] . V_93 )
F_82 ( V_87 [ V_93 ] . V_93 ) ;
F_83 ( V_87 ) ;
}
if ( V_24 ) F_54 ( ( unsigned long ) V_24 ) ;
return V_65 ;
}
static int F_84 ( unsigned int V_84 , unsigned int V_46 )
{
unsigned int V_110 = F_85 ( V_61 , 1 ) ;
unsigned int V_111 ;
F_86 ( L_27 , V_110 ) ;
V_111 = V_112 + V_84 ;
return V_110 > V_111 ;
}
int F_87 ( unsigned int V_46 )
{
struct V_44 V_45 ;
struct V_80 V_81 ;
struct V_113 * V_114 ;
unsigned long V_115 ;
int error ;
V_115 = F_88 () ;
error = F_55 ( & V_45 ) ;
if ( error ) {
F_25 ( V_41 L_28 ) ;
return error ;
}
if ( V_46 & V_116 ) {
if ( ! F_84 ( V_115 , V_46 ) ) {
F_25 ( V_41 L_29 ) ;
error = - V_66 ;
goto V_109;
}
}
memset ( & V_81 , 0 , sizeof( struct V_80 ) ) ;
error = F_64 ( & V_81 ) ;
if ( error < V_39 ) {
if ( error >= 0 )
error = - V_42 ;
goto V_109;
}
V_114 = (struct V_113 * ) F_65 ( V_81 ) ;
error = F_58 ( & V_45 , V_114 , NULL ) ;
if ( ! error ) {
error = ( V_46 & V_116 ) ?
F_62 ( & V_45 , & V_81 , V_115 - 1 ) :
F_72 ( & V_45 , & V_81 , V_115 - 1 ) ;
}
V_109:
error = F_61 ( & V_45 , V_46 , error ) ;
return error ;
}
static void F_89 ( struct V_44 * V_45 )
{
struct V_117 * V_118 ;
while ( V_45 -> V_119 ) {
if ( V_45 -> V_119 -> V_120 )
F_54 ( ( unsigned long ) V_45 -> V_119 -> V_120 ) ;
V_118 = V_45 -> V_119 ;
V_45 -> V_119 = V_45 -> V_119 -> V_121 ;
F_19 ( V_118 ) ;
}
V_45 -> V_69 = NULL ;
}
static int F_90 ( struct V_44 * V_45 ,
unsigned int * V_122 )
{
int error ;
struct V_117 * V_118 , * V_123 ;
T_1 V_17 ;
* V_122 = V_49 -> V_46 ;
if ( ! V_49 -> V_53 )
return - V_13 ;
V_45 -> V_69 = NULL ;
V_123 = V_45 -> V_119 = NULL ;
V_17 = V_49 -> V_53 ;
while ( V_17 ) {
V_118 = F_77 ( sizeof( * V_45 -> V_119 ) , V_14 ) ;
if ( ! V_118 ) {
F_89 ( V_45 ) ;
return - V_15 ;
}
memset ( V_118 , 0 , sizeof( * V_118 ) ) ;
if ( ! V_45 -> V_119 )
V_45 -> V_119 = V_118 ;
if ( V_123 )
V_123 -> V_121 = V_118 ;
V_123 = V_118 ;
V_118 -> V_120 = (struct V_70 * )
F_50 ( V_37 | V_38 ) ;
if ( ! V_118 -> V_120 ) {
F_89 ( V_45 ) ;
return - V_15 ;
}
error = F_33 ( V_47 , V_17 , V_118 -> V_120 , NULL ) ;
if ( error ) {
F_89 ( V_45 ) ;
return error ;
}
V_17 = V_118 -> V_120 -> V_77 ;
}
V_45 -> V_74 = 0 ;
V_45 -> V_69 = V_45 -> V_119 -> V_120 ;
return 0 ;
}
static int F_91 ( struct V_44 * V_45 , void * V_63 ,
struct V_18 * V_19 )
{
T_1 V_17 ;
int error ;
struct V_117 * V_118 ;
if ( ! V_45 -> V_69 )
return - V_13 ;
V_17 = V_45 -> V_69 -> V_75 [ V_45 -> V_74 ] ;
if ( ! V_17 )
return - V_42 ;
error = F_33 ( V_47 , V_17 , V_63 , V_19 ) ;
if ( error )
return error ;
if ( ++ V_45 -> V_74 >= V_76 ) {
V_45 -> V_74 = 0 ;
F_54 ( ( unsigned long ) V_45 -> V_119 -> V_120 ) ;
V_118 = V_45 -> V_119 ;
V_45 -> V_119 = V_45 -> V_119 -> V_121 ;
F_19 ( V_118 ) ;
if ( ! V_45 -> V_119 )
F_89 ( V_45 ) ;
else
V_45 -> V_69 = V_45 -> V_119 -> V_120 ;
}
return error ;
}
static int F_92 ( struct V_44 * V_45 )
{
F_89 ( V_45 ) ;
return 0 ;
}
static int F_93 ( struct V_44 * V_45 ,
struct V_80 * V_81 ,
unsigned int V_124 )
{
unsigned int V_83 ;
int V_65 = 0 ;
T_3 V_9 ;
T_3 V_86 ;
struct V_18 V_19 ;
int V_85 ;
unsigned V_84 ;
F_21 ( & V_19 ) ;
F_25 ( V_79 L_30 ,
V_124 ) ;
V_83 = V_124 / 10 ;
if ( ! V_83 )
V_83 = 1 ;
V_84 = 0 ;
V_9 = F_63 () ;
for ( ; ; ) {
V_65 = F_94 ( V_81 ) ;
if ( V_65 <= 0 )
break;
V_65 = F_91 ( V_45 , F_65 ( * V_81 ) , & V_19 ) ;
if ( V_65 )
break;
if ( V_81 -> V_125 )
V_65 = F_40 ( & V_19 ) ;
if ( V_65 )
break;
if ( ! ( V_84 % V_83 ) )
F_25 ( V_79 L_31 ,
V_84 / V_83 * 10 ) ;
V_84 ++ ;
}
V_85 = F_40 ( & V_19 ) ;
V_86 = F_63 () ;
if ( ! V_65 )
V_65 = V_85 ;
if ( ! V_65 ) {
F_25 ( V_79 L_32 ) ;
F_95 ( V_81 ) ;
if ( ! F_96 ( V_81 ) )
V_65 = - V_126 ;
}
F_66 ( V_9 , V_86 , V_124 , L_33 ) ;
return V_65 ;
}
static int F_97 ( void * V_87 )
{
struct V_127 * V_89 = V_87 ;
while ( 1 ) {
F_41 ( V_89 -> V_91 , F_42 ( & V_89 -> V_92 ) ||
F_68 () ) ;
if ( F_68 () ) {
V_89 -> V_93 = NULL ;
V_89 -> V_65 = - 1 ;
F_22 ( & V_89 -> V_86 , 1 ) ;
F_31 ( & V_89 -> V_94 ) ;
break;
}
F_22 ( & V_89 -> V_92 , 0 ) ;
V_89 -> V_97 = V_108 ;
V_89 -> V_65 = F_98 ( V_89 -> V_99 + V_100 , V_89 -> V_101 ,
V_89 -> V_96 , & V_89 -> V_97 ) ;
F_22 ( & V_89 -> V_86 , 1 ) ;
F_31 ( & V_89 -> V_94 ) ;
}
return 0 ;
}
static int F_99 ( struct V_44 * V_45 ,
struct V_80 * V_81 ,
unsigned int V_124 )
{
unsigned int V_83 ;
int V_65 = 0 ;
int V_128 = 0 ;
struct V_18 V_19 ;
T_3 V_9 ;
T_3 V_86 ;
unsigned V_84 ;
T_4 V_103 ;
unsigned V_90 , V_93 , V_95 , V_104 ;
unsigned V_129 = 0 , V_130 = 0 , V_131 = 0 ,
V_132 = 0 , V_133 , V_134 , V_135 = 0 ;
unsigned long V_136 = 0 ;
unsigned char * * V_24 = NULL ;
struct V_127 * V_87 = NULL ;
struct V_88 * V_105 = NULL ;
F_21 ( & V_19 ) ;
V_104 = F_73 () - 1 ;
V_104 = F_74 ( V_104 , 1 , V_106 ) ;
V_24 = F_75 ( sizeof( * V_24 ) * V_137 ) ;
if ( ! V_24 ) {
F_25 ( V_41 L_14 ) ;
V_65 = - V_15 ;
goto V_107;
}
V_87 = F_75 ( sizeof( * V_87 ) * V_104 ) ;
if ( ! V_87 ) {
F_25 ( V_41 L_15 ) ;
V_65 = - V_15 ;
goto V_107;
}
for ( V_93 = 0 ; V_93 < V_104 ; V_93 ++ )
memset ( & V_87 [ V_93 ] , 0 , F_76 ( struct V_127 , V_91 ) ) ;
V_105 = F_77 ( sizeof( * V_105 ) , V_14 ) ;
if ( ! V_105 ) {
F_25 ( V_41 L_16 ) ;
V_65 = - V_15 ;
goto V_107;
}
memset ( V_105 , 0 , F_76 ( struct V_88 , V_91 ) ) ;
for ( V_93 = 0 ; V_93 < V_104 ; V_93 ++ ) {
F_23 ( & V_87 [ V_93 ] . V_91 ) ;
F_23 ( & V_87 [ V_93 ] . V_94 ) ;
V_87 [ V_93 ] . V_93 = F_78 ( F_97 ,
& V_87 [ V_93 ] ,
L_34 , V_93 ) ;
if ( F_79 ( V_87 [ V_93 ] . V_93 ) ) {
V_87 [ V_93 ] . V_93 = NULL ;
F_25 ( V_41
L_35 ) ;
V_65 = - V_15 ;
goto V_107;
}
}
F_23 ( & V_105 -> V_91 ) ;
F_23 ( & V_105 -> V_94 ) ;
V_45 -> V_56 = 0 ;
V_105 -> V_56 = & V_45 -> V_56 ;
for ( V_93 = 0 ; V_93 < V_104 ; V_93 ++ ) {
V_105 -> V_96 [ V_93 ] = V_87 [ V_93 ] . V_96 ;
V_105 -> V_97 [ V_93 ] = & V_87 [ V_93 ] . V_97 ;
}
V_105 -> V_93 = F_78 ( F_67 , V_105 , L_19 ) ;
if ( F_79 ( V_105 -> V_93 ) ) {
V_105 -> V_93 = NULL ;
F_25 ( V_41 L_20 ) ;
V_65 = - V_15 ;
goto V_107;
}
if ( F_1 () > F_88 () )
V_136 = ( F_1 () - F_88 () ) / 2 ;
V_136 = F_74 ( V_136 , V_138 , V_137 ) ;
for ( V_90 = 0 ; V_90 < V_136 ; V_90 ++ ) {
V_24 [ V_90 ] = ( void * ) F_50 ( V_90 < V_139 ?
V_37 | V_38 :
V_37 | V_67 |
V_68 ) ;
if ( ! V_24 [ V_90 ] ) {
if ( V_90 < V_139 ) {
V_131 = V_90 ;
F_25 ( V_41
L_36 ) ;
V_65 = - V_15 ;
goto V_107;
} else {
break;
}
}
}
V_133 = V_131 = V_90 ;
F_25 ( V_79
L_37
L_38 ,
V_104 , V_124 ) ;
V_83 = V_124 / 10 ;
if ( ! V_83 )
V_83 = 1 ;
V_84 = 0 ;
V_9 = F_63 () ;
V_65 = F_94 ( V_81 ) ;
if ( V_65 <= 0 )
goto V_109;
for(; ; ) {
for ( V_90 = 0 ; ! V_128 && V_90 < V_133 ; V_90 ++ ) {
V_65 = F_91 ( V_45 , V_24 [ V_129 ] , & V_19 ) ;
if ( V_65 ) {
if ( V_45 -> V_69 &&
V_45 -> V_69 -> V_75 [ V_45 -> V_74 ] ) {
goto V_109;
} else {
V_128 = 1 ;
break;
}
}
if ( ++ V_129 >= V_131 )
V_129 = 0 ;
}
V_135 += V_90 ;
V_133 -= V_90 ;
if ( ! V_132 ) {
if ( ! V_135 )
break;
V_65 = F_40 ( & V_19 ) ;
if ( V_65 )
goto V_109;
V_132 += V_135 ;
V_135 = 0 ;
if ( V_128 )
V_128 = 2 ;
}
if ( V_105 -> V_95 ) {
F_41 ( V_105 -> V_94 , F_42 ( & V_105 -> V_86 ) ) ;
F_22 ( & V_105 -> V_86 , 0 ) ;
V_105 -> V_95 = 0 ;
}
for ( V_93 = 0 ; V_132 && V_93 < V_104 ; V_93 ++ ) {
V_87 [ V_93 ] . V_101 = * ( T_4 * ) V_24 [ V_130 ] ;
if ( F_80 ( ! V_87 [ V_93 ] . V_101 ||
V_87 [ V_93 ] . V_101 >
F_81 ( V_108 ) ) ) {
F_25 ( V_41
L_26 ) ;
V_65 = - 1 ;
goto V_109;
}
V_134 = F_100 ( V_87 [ V_93 ] . V_101 + V_100 ,
V_39 ) ;
if ( V_134 > V_132 ) {
if ( V_128 > 1 ) {
V_65 = - 1 ;
goto V_109;
}
break;
}
for ( V_103 = 0 ;
V_103 < V_100 + V_87 [ V_93 ] . V_101 ;
V_103 += V_39 ) {
memcpy ( V_87 [ V_93 ] . V_99 + V_103 ,
V_24 [ V_130 ] , V_39 ) ;
V_132 -- ;
V_133 ++ ;
if ( ++ V_130 >= V_131 )
V_130 = 0 ;
}
F_22 ( & V_87 [ V_93 ] . V_92 , 1 ) ;
F_31 ( & V_87 [ V_93 ] . V_91 ) ;
}
if ( V_132 < V_139 && V_135 ) {
V_65 = F_40 ( & V_19 ) ;
if ( V_65 )
goto V_109;
V_132 += V_135 ;
V_135 = 0 ;
if ( V_128 )
V_128 = 2 ;
}
for ( V_95 = V_93 , V_93 = 0 ; V_93 < V_95 ; V_93 ++ ) {
F_41 ( V_87 [ V_93 ] . V_94 ,
F_42 ( & V_87 [ V_93 ] . V_86 ) ) ;
F_22 ( & V_87 [ V_93 ] . V_86 , 0 ) ;
V_65 = V_87 [ V_93 ] . V_65 ;
if ( V_65 < 0 ) {
F_25 ( V_41
L_39 ) ;
goto V_109;
}
if ( F_80 ( ! V_87 [ V_93 ] . V_97 ||
V_87 [ V_93 ] . V_97 > V_108 ||
V_87 [ V_93 ] . V_97 & ( V_39 - 1 ) ) ) {
F_25 ( V_41
L_40 ) ;
V_65 = - 1 ;
goto V_109;
}
for ( V_103 = 0 ;
V_103 < V_87 [ V_93 ] . V_97 ; V_103 += V_39 ) {
memcpy ( F_65 ( * V_81 ) ,
V_87 [ V_93 ] . V_96 + V_103 , V_39 ) ;
if ( ! ( V_84 % V_83 ) )
F_25 ( V_79
L_41
L_24 ,
V_84 / V_83 * 10 ) ;
V_84 ++ ;
V_65 = F_94 ( V_81 ) ;
if ( V_65 <= 0 ) {
V_105 -> V_95 = V_93 + 1 ;
F_22 ( & V_105 -> V_92 , 1 ) ;
F_31 ( & V_105 -> V_91 ) ;
goto V_109;
}
}
}
V_105 -> V_95 = V_93 ;
F_22 ( & V_105 -> V_92 , 1 ) ;
F_31 ( & V_105 -> V_91 ) ;
}
V_109:
if ( V_105 -> V_95 ) {
F_41 ( V_105 -> V_94 , F_42 ( & V_105 -> V_86 ) ) ;
F_22 ( & V_105 -> V_86 , 0 ) ;
}
V_86 = F_63 () ;
if ( ! V_65 ) {
F_25 ( V_79 L_32 ) ;
F_95 ( V_81 ) ;
if ( ! F_96 ( V_81 ) )
V_65 = - V_126 ;
if ( ! V_65 ) {
if ( V_49 -> V_46 & V_55 ) {
if( V_45 -> V_56 != V_49 -> V_56 ) {
F_25 ( V_41
L_42 ) ;
V_65 = - V_126 ;
}
}
}
}
F_66 ( V_9 , V_86 , V_124 , L_33 ) ;
V_107:
for ( V_90 = 0 ; V_90 < V_131 ; V_90 ++ )
F_54 ( ( unsigned long ) V_24 [ V_90 ] ) ;
if ( V_105 ) {
if ( V_105 -> V_93 )
F_82 ( V_105 -> V_93 ) ;
F_19 ( V_105 ) ;
}
if ( V_87 ) {
for ( V_93 = 0 ; V_93 < V_104 ; V_93 ++ )
if ( V_87 [ V_93 ] . V_93 )
F_82 ( V_87 [ V_93 ] . V_93 ) ;
F_83 ( V_87 ) ;
}
F_83 ( V_24 ) ;
return V_65 ;
}
int F_101 ( unsigned int * V_122 )
{
int error ;
struct V_44 V_45 ;
struct V_80 V_81 ;
struct V_113 * V_114 ;
memset ( & V_81 , 0 , sizeof( struct V_80 ) ) ;
error = F_94 ( & V_81 ) ;
if ( error < V_39 )
return error < 0 ? error : - V_42 ;
V_114 = (struct V_113 * ) F_65 ( V_81 ) ;
error = F_90 ( & V_45 , V_122 ) ;
if ( error )
goto V_11;
if ( ! error )
error = F_91 ( & V_45 , V_114 , NULL ) ;
if ( ! error ) {
error = ( * V_122 & V_116 ) ?
F_93 ( & V_45 , & V_81 , V_114 -> V_115 - 1 ) :
F_99 ( & V_45 , & V_81 , V_114 -> V_115 - 1 ) ;
}
F_92 ( & V_45 ) ;
V_11:
if ( ! error )
F_86 ( L_43 ) ;
else
F_86 ( L_44 , error ) ;
return error ;
}
int F_102 ( void )
{
int error ;
V_40 = F_103 ( V_60 ,
V_140 , NULL ) ;
if ( ! F_79 ( V_40 ) ) {
F_47 ( V_40 , V_39 ) ;
F_59 ( V_49 ) ;
error = F_33 ( V_47 , V_48 ,
V_49 , NULL ) ;
if ( error )
goto V_141;
if ( ! memcmp ( V_52 , V_49 -> V_50 , 10 ) ) {
memcpy ( V_49 -> V_50 , V_49 -> V_51 , 10 ) ;
error = F_33 ( V_57 , V_48 ,
V_49 , NULL ) ;
} else {
error = - V_13 ;
}
V_141:
if ( error )
F_48 ( V_40 , V_140 ) ;
else
F_86 ( L_45 ) ;
} else {
error = F_104 ( V_40 ) ;
}
if ( error )
F_86 ( L_46 , error ) ;
return error ;
}
void F_57 ( T_5 V_142 )
{
if ( F_79 ( V_40 ) ) {
F_86 ( L_47 ) ;
return;
}
F_48 ( V_40 , V_142 ) ;
}
int F_105 ( void )
{
int error ;
F_33 ( V_47 , V_48 , V_49 , NULL ) ;
if ( ! memcmp ( V_52 , V_49 -> V_50 , 10 ) ) {
memcpy ( V_49 -> V_50 , V_49 -> V_51 , 10 ) ;
error = F_33 ( V_57 , V_48 ,
V_49 , NULL ) ;
} else {
F_25 ( V_41 L_48 ) ;
error = - V_58 ;
}
F_16 ( V_61 ) ;
return error ;
}
static int F_106 ( void )
{
V_49 = (struct V_49 * ) F_50 ( V_14 ) ;
if ( ! V_49 )
F_107 ( L_49 ) ;
return 0 ;
}
