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
static int F_20 ( struct V_18 * V_19 , unsigned int V_20 )
{
int error ;
F_21 ( V_21 , V_22 , NULL ) ;
if ( ! memcmp ( L_1 , V_22 -> V_23 , 10 ) ||
! memcmp ( L_2 , V_22 -> V_23 , 10 ) ) {
memcpy ( V_22 -> V_24 , V_22 -> V_23 , 10 ) ;
memcpy ( V_22 -> V_23 , V_25 , 10 ) ;
V_22 -> V_26 = V_19 -> V_27 ;
V_22 -> V_20 = V_20 ;
if ( V_20 & V_28 )
V_22 -> V_29 = V_19 -> V_29 ;
error = F_22 ( V_21 ,
V_22 , NULL ) ;
} else {
F_23 ( V_30 L_3 ) ;
error = - V_31 ;
}
return error ;
}
static int F_24 ( void )
{
int V_32 ;
V_32 = F_25 ( V_33 , V_21 ,
& V_34 ) ;
if ( V_32 < 0 )
return V_32 ;
V_35 = V_32 ;
V_32 = F_26 ( V_34 , V_36 , NULL ) ;
if ( V_32 )
return V_32 ;
V_32 = F_27 ( V_34 , V_37 ) ;
if ( V_32 < 0 )
F_28 ( V_34 , V_36 ) ;
return V_32 ;
}
static int F_29 ( void * V_38 , T_1 V_17 , struct V_39 * * V_40 )
{
void * V_41 ;
int V_42 ;
if ( ! V_17 )
return - V_43 ;
if ( V_40 ) {
V_41 = ( void * ) F_30 ( V_44 | V_45 |
V_46 ) ;
if ( V_41 ) {
F_31 ( V_41 , V_38 ) ;
} else {
V_42 = F_32 ( V_40 ) ;
if ( V_42 )
return V_42 ;
V_41 = ( void * ) F_30 ( V_44 |
V_45 |
V_46 ) ;
if ( V_41 ) {
F_31 ( V_41 , V_38 ) ;
} else {
F_33 ( 1 ) ;
V_40 = NULL ;
V_41 = V_38 ;
}
}
} else {
V_41 = V_38 ;
}
return F_22 ( V_17 , V_41 , V_40 ) ;
}
static void F_34 ( struct V_18 * V_19 )
{
if ( V_19 -> V_47 )
F_35 ( ( unsigned long ) V_19 -> V_47 ) ;
V_19 -> V_47 = NULL ;
}
static int F_36 ( struct V_18 * V_19 )
{
int V_42 ;
V_42 = F_24 () ;
if ( V_42 ) {
if ( V_42 != - V_43 )
F_23 ( V_30 L_4
L_5 ) ;
return V_42 ;
}
V_19 -> V_47 = (struct V_48 * ) F_37 ( V_14 ) ;
if ( ! V_19 -> V_47 ) {
V_42 = - V_15 ;
goto V_49;
}
V_19 -> V_50 = F_10 ( V_35 ) ;
if ( ! V_19 -> V_50 ) {
V_42 = - V_43 ;
goto V_51;
}
V_19 -> V_52 = 0 ;
V_19 -> F_4 = F_4 () ;
V_19 -> V_27 = V_19 -> V_50 ;
return 0 ;
V_51:
F_34 ( V_19 ) ;
V_49:
F_38 ( V_36 ) ;
return V_42 ;
}
static int F_39 ( struct V_18 * V_19 , void * V_38 ,
struct V_39 * * V_40 )
{
int error = 0 ;
T_1 V_17 ;
if ( ! V_19 -> V_47 )
return - V_13 ;
V_17 = F_10 ( V_35 ) ;
error = F_29 ( V_38 , V_17 , V_40 ) ;
if ( error )
return error ;
V_19 -> V_47 -> V_53 [ V_19 -> V_52 ++ ] = V_17 ;
if ( V_19 -> V_52 >= V_54 ) {
V_17 = F_10 ( V_35 ) ;
if ( ! V_17 )
return - V_43 ;
V_19 -> V_47 -> V_55 = V_17 ;
error = F_29 ( V_19 -> V_47 , V_19 -> V_50 , V_40 ) ;
if ( error )
goto V_56;
F_40 ( V_19 -> V_47 ) ;
V_19 -> V_50 = V_17 ;
V_19 -> V_52 = 0 ;
if ( V_40 && F_1 () <= V_19 -> F_4 ) {
error = F_32 ( V_40 ) ;
if ( error )
goto V_56;
V_19 -> F_4 = F_4 () ;
}
}
V_56:
return error ;
}
static int F_41 ( struct V_18 * V_19 )
{
if ( V_19 -> V_47 && V_19 -> V_50 )
return F_29 ( V_19 -> V_47 , V_19 -> V_50 , NULL ) ;
else
return - V_13 ;
}
static int F_42 ( struct V_18 * V_19 ,
unsigned int V_20 , int error )
{
if ( ! error ) {
F_41 ( V_19 ) ;
F_23 ( V_57 L_6 ) ;
error = F_20 ( V_19 , V_20 ) ;
F_23 ( L_7 ) ;
}
if ( error )
F_16 ( V_35 ) ;
F_34 ( V_19 ) ;
F_38 ( V_36 ) ;
return error ;
}
static int F_43 ( struct V_18 * V_19 ,
struct V_58 * V_59 ,
unsigned int V_60 )
{
unsigned int V_61 ;
int V_42 ;
int V_62 ;
int V_63 ;
struct V_39 * V_39 ;
struct V_64 V_9 ;
struct V_64 V_65 ;
F_23 ( V_57 L_8 ,
V_60 ) ;
V_61 = V_60 / 100 ;
if ( ! V_61 )
V_61 = 1 ;
V_62 = 0 ;
V_39 = NULL ;
F_44 ( & V_9 ) ;
while ( 1 ) {
V_42 = F_45 ( V_59 ) ;
if ( V_42 <= 0 )
break;
V_42 = F_39 ( V_19 , F_46 ( * V_59 ) , & V_39 ) ;
if ( V_42 )
break;
if ( ! ( V_62 % V_61 ) )
F_23 ( V_66 L_9 , V_62 / V_61 ) ;
V_62 ++ ;
}
V_63 = F_32 ( & V_39 ) ;
F_44 ( & V_65 ) ;
if ( ! V_42 )
V_42 = V_63 ;
if ( ! V_42 )
F_23 ( V_66 L_10 ) ;
else
F_23 ( V_66 L_11 ) ;
F_47 ( & V_9 , & V_65 , V_60 , L_12 ) ;
return V_42 ;
}
static int F_48 ( void * V_67 )
{
struct V_68 * V_69 = V_67 ;
unsigned V_70 ;
while ( 1 ) {
F_49 ( V_69 -> V_71 , F_50 ( & V_69 -> V_72 ) ||
F_51 () ) ;
if ( F_51 () ) {
V_69 -> V_73 = NULL ;
F_52 ( & V_69 -> V_65 , 1 ) ;
F_53 ( & V_69 -> V_74 ) ;
break;
}
F_52 ( & V_69 -> V_72 , 0 ) ;
for ( V_70 = 0 ; V_70 < V_69 -> V_75 ; V_70 ++ )
* V_69 -> V_29 = F_54 ( * V_69 -> V_29 ,
V_69 -> V_76 [ V_70 ] , * V_69 -> V_77 [ V_70 ] ) ;
F_52 ( & V_69 -> V_65 , 1 ) ;
F_53 ( & V_69 -> V_74 ) ;
}
return 0 ;
}
static int F_55 ( void * V_67 )
{
struct V_78 * V_69 = V_67 ;
while ( 1 ) {
F_49 ( V_69 -> V_71 , F_50 ( & V_69 -> V_72 ) ||
F_51 () ) ;
if ( F_51 () ) {
V_69 -> V_73 = NULL ;
V_69 -> V_42 = - 1 ;
F_52 ( & V_69 -> V_65 , 1 ) ;
F_53 ( & V_69 -> V_74 ) ;
break;
}
F_52 ( & V_69 -> V_72 , 0 ) ;
V_69 -> V_42 = F_56 ( V_69 -> V_76 , V_69 -> V_77 ,
V_69 -> V_79 + V_80 , & V_69 -> V_81 ,
V_69 -> V_82 ) ;
F_52 ( & V_69 -> V_65 , 1 ) ;
F_53 ( & V_69 -> V_74 ) ;
}
return 0 ;
}
static int F_57 ( struct V_18 * V_19 ,
struct V_58 * V_59 ,
unsigned int V_60 )
{
unsigned int V_61 ;
int V_42 = 0 ;
int V_62 ;
int V_63 ;
struct V_39 * V_39 ;
struct V_64 V_9 ;
struct V_64 V_65 ;
T_2 V_83 ;
unsigned V_73 , V_75 , V_84 ;
unsigned char * V_85 = NULL ;
struct V_78 * V_67 = NULL ;
struct V_68 * V_86 = NULL ;
V_84 = F_58 () - 1 ;
V_84 = F_59 ( V_84 , 1 , V_87 ) ;
V_85 = ( void * ) F_30 ( V_44 | V_88 ) ;
if ( ! V_85 ) {
F_23 ( V_30 L_13 ) ;
V_42 = - V_15 ;
goto V_89;
}
V_67 = F_60 ( sizeof( * V_67 ) * V_84 ) ;
if ( ! V_67 ) {
F_23 ( V_30 L_14 ) ;
V_42 = - V_15 ;
goto V_89;
}
for ( V_73 = 0 ; V_73 < V_84 ; V_73 ++ )
memset ( & V_67 [ V_73 ] , 0 , F_61 ( struct V_78 , V_71 ) ) ;
V_86 = F_62 ( sizeof( * V_86 ) , V_14 ) ;
if ( ! V_86 ) {
F_23 ( V_30 L_15 ) ;
V_42 = - V_15 ;
goto V_89;
}
memset ( V_86 , 0 , F_61 ( struct V_68 , V_71 ) ) ;
for ( V_73 = 0 ; V_73 < V_84 ; V_73 ++ ) {
F_63 ( & V_67 [ V_73 ] . V_71 ) ;
F_63 ( & V_67 [ V_73 ] . V_74 ) ;
V_67 [ V_73 ] . V_73 = F_64 ( F_55 ,
& V_67 [ V_73 ] ,
L_16 , V_73 ) ;
if ( F_65 ( V_67 [ V_73 ] . V_73 ) ) {
V_67 [ V_73 ] . V_73 = NULL ;
F_23 ( V_30
L_17 ) ;
V_42 = - V_15 ;
goto V_89;
}
}
F_63 ( & V_86 -> V_71 ) ;
F_63 ( & V_86 -> V_74 ) ;
V_19 -> V_29 = 0 ;
V_86 -> V_29 = & V_19 -> V_29 ;
for ( V_73 = 0 ; V_73 < V_84 ; V_73 ++ ) {
V_86 -> V_76 [ V_73 ] = V_67 [ V_73 ] . V_76 ;
V_86 -> V_77 [ V_73 ] = & V_67 [ V_73 ] . V_77 ;
}
V_86 -> V_73 = F_64 ( F_48 , V_86 , L_18 ) ;
if ( F_65 ( V_86 -> V_73 ) ) {
V_86 -> V_73 = NULL ;
F_23 ( V_30 L_19 ) ;
V_42 = - V_15 ;
goto V_89;
}
V_19 -> F_4 = F_4 () ;
F_23 ( V_57
L_20
L_21 ,
V_84 , V_60 ) ;
V_61 = V_60 / 100 ;
if ( ! V_61 )
V_61 = 1 ;
V_62 = 0 ;
V_39 = NULL ;
F_44 ( & V_9 ) ;
for (; ; ) {
for ( V_73 = 0 ; V_73 < V_84 ; V_73 ++ ) {
for ( V_83 = 0 ; V_83 < V_90 ; V_83 += V_37 ) {
V_42 = F_45 ( V_59 ) ;
if ( V_42 < 0 )
goto V_91;
if ( ! V_42 )
break;
memcpy ( V_67 [ V_73 ] . V_76 + V_83 ,
F_46 ( * V_59 ) , V_37 ) ;
if ( ! ( V_62 % V_61 ) )
F_23 ( V_66 L_9 ,
V_62 / V_61 ) ;
V_62 ++ ;
}
if ( ! V_83 )
break;
V_67 [ V_73 ] . V_77 = V_83 ;
F_52 ( & V_67 [ V_73 ] . V_72 , 1 ) ;
F_53 ( & V_67 [ V_73 ] . V_71 ) ;
}
if ( ! V_73 )
break;
V_86 -> V_75 = V_73 ;
F_52 ( & V_86 -> V_72 , 1 ) ;
F_53 ( & V_86 -> V_71 ) ;
for ( V_75 = V_73 , V_73 = 0 ; V_73 < V_75 ; V_73 ++ ) {
F_49 ( V_67 [ V_73 ] . V_74 ,
F_50 ( & V_67 [ V_73 ] . V_65 ) ) ;
F_52 ( & V_67 [ V_73 ] . V_65 , 0 ) ;
V_42 = V_67 [ V_73 ] . V_42 ;
if ( V_42 < 0 ) {
F_23 ( V_30 L_22 ) ;
goto V_91;
}
if ( F_66 ( ! V_67 [ V_73 ] . V_81 ||
V_67 [ V_73 ] . V_81 >
F_67 ( V_67 [ V_73 ] . V_77 ) ) ) {
F_23 ( V_30
L_23 ) ;
V_42 = - 1 ;
goto V_91;
}
* ( T_2 * ) V_67 [ V_73 ] . V_79 = V_67 [ V_73 ] . V_81 ;
for ( V_83 = 0 ;
V_83 < V_80 + V_67 [ V_73 ] . V_81 ;
V_83 += V_37 ) {
memcpy ( V_85 , V_67 [ V_73 ] . V_79 + V_83 , V_37 ) ;
V_42 = F_39 ( V_19 , V_85 , & V_39 ) ;
if ( V_42 )
goto V_91;
}
}
F_49 ( V_86 -> V_74 , F_50 ( & V_86 -> V_65 ) ) ;
F_52 ( & V_86 -> V_65 , 0 ) ;
}
V_91:
V_63 = F_32 ( & V_39 ) ;
F_44 ( & V_65 ) ;
if ( ! V_42 )
V_42 = V_63 ;
if ( ! V_42 ) {
F_23 ( V_66 L_10 ) ;
} else {
F_23 ( V_66 L_11 ) ;
}
F_47 ( & V_9 , & V_65 , V_60 , L_12 ) ;
V_89:
if ( V_86 ) {
if ( V_86 -> V_73 )
F_68 ( V_86 -> V_73 ) ;
F_18 ( V_86 ) ;
}
if ( V_67 ) {
for ( V_73 = 0 ; V_73 < V_84 ; V_73 ++ )
if ( V_67 [ V_73 ] . V_73 )
F_68 ( V_67 [ V_73 ] . V_73 ) ;
F_69 ( V_67 ) ;
}
if ( V_85 ) F_35 ( ( unsigned long ) V_85 ) ;
return V_42 ;
}
static int F_70 ( unsigned int V_62 , unsigned int V_20 )
{
unsigned int V_92 = F_71 ( V_35 , 1 ) ;
unsigned int V_93 ;
F_72 ( L_24 , V_92 ) ;
V_93 = V_94 + V_62 ;
return V_92 > V_93 ;
}
int F_73 ( unsigned int V_20 )
{
struct V_18 V_19 ;
struct V_58 V_59 ;
struct V_95 * V_96 ;
unsigned long V_97 ;
int error ;
V_97 = F_74 () ;
error = F_36 ( & V_19 ) ;
if ( error ) {
F_23 ( V_30 L_25 ) ;
return error ;
}
if ( V_20 & V_98 ) {
if ( ! F_70 ( V_97 , V_20 ) ) {
F_23 ( V_30 L_26 ) ;
error = - V_43 ;
goto V_91;
}
}
memset ( & V_59 , 0 , sizeof( struct V_58 ) ) ;
error = F_45 ( & V_59 ) ;
if ( error < V_37 ) {
if ( error >= 0 )
error = - V_99 ;
goto V_91;
}
V_96 = (struct V_95 * ) F_46 ( V_59 ) ;
error = F_39 ( & V_19 , V_96 , NULL ) ;
if ( ! error ) {
error = ( V_20 & V_98 ) ?
F_43 ( & V_19 , & V_59 , V_97 - 1 ) :
F_57 ( & V_19 , & V_59 , V_97 - 1 ) ;
}
V_91:
error = F_42 ( & V_19 , V_20 , error ) ;
return error ;
}
static void F_75 ( struct V_18 * V_19 )
{
struct V_100 * V_101 ;
while ( V_19 -> V_102 ) {
if ( V_19 -> V_102 -> V_103 )
F_35 ( ( unsigned long ) V_19 -> V_102 -> V_103 ) ;
V_101 = V_19 -> V_102 ;
V_19 -> V_102 = V_19 -> V_102 -> V_104 ;
F_18 ( V_101 ) ;
}
V_19 -> V_47 = NULL ;
}
static int F_76 ( struct V_18 * V_19 ,
unsigned int * V_105 )
{
int error ;
struct V_100 * V_101 , * V_106 ;
T_1 V_17 ;
* V_105 = V_22 -> V_20 ;
if ( ! V_22 -> V_26 )
return - V_13 ;
V_19 -> V_47 = NULL ;
V_106 = V_19 -> V_102 = NULL ;
V_17 = V_22 -> V_26 ;
while ( V_17 ) {
V_101 = F_62 ( sizeof( * V_19 -> V_102 ) , V_14 ) ;
if ( ! V_101 ) {
F_75 ( V_19 ) ;
return - V_15 ;
}
memset ( V_101 , 0 , sizeof( * V_101 ) ) ;
if ( ! V_19 -> V_102 )
V_19 -> V_102 = V_101 ;
if ( V_106 )
V_106 -> V_104 = V_101 ;
V_106 = V_101 ;
V_101 -> V_103 = (struct V_48 * )
F_30 ( V_44 | V_88 ) ;
if ( ! V_101 -> V_103 ) {
F_75 ( V_19 ) ;
return - V_15 ;
}
error = F_21 ( V_17 , V_101 -> V_103 , NULL ) ;
if ( error ) {
F_75 ( V_19 ) ;
return error ;
}
V_17 = V_101 -> V_103 -> V_55 ;
}
V_19 -> V_52 = 0 ;
V_19 -> V_47 = V_19 -> V_102 -> V_103 ;
return 0 ;
}
static int F_77 ( struct V_18 * V_19 , void * V_38 ,
struct V_39 * * V_40 )
{
T_1 V_17 ;
int error ;
struct V_100 * V_101 ;
if ( ! V_19 -> V_47 )
return - V_13 ;
V_17 = V_19 -> V_47 -> V_53 [ V_19 -> V_52 ] ;
if ( ! V_17 )
return - V_99 ;
error = F_21 ( V_17 , V_38 , V_40 ) ;
if ( error )
return error ;
if ( ++ V_19 -> V_52 >= V_54 ) {
V_19 -> V_52 = 0 ;
F_35 ( ( unsigned long ) V_19 -> V_102 -> V_103 ) ;
V_101 = V_19 -> V_102 ;
V_19 -> V_102 = V_19 -> V_102 -> V_104 ;
F_18 ( V_101 ) ;
if ( ! V_19 -> V_102 )
F_75 ( V_19 ) ;
else
V_19 -> V_47 = V_19 -> V_102 -> V_103 ;
}
return error ;
}
static int F_78 ( struct V_18 * V_19 )
{
F_75 ( V_19 ) ;
return 0 ;
}
static int F_79 ( struct V_18 * V_19 ,
struct V_58 * V_59 ,
unsigned int V_107 )
{
unsigned int V_61 ;
int V_42 = 0 ;
struct V_64 V_9 ;
struct V_64 V_65 ;
struct V_39 * V_39 ;
int V_63 ;
unsigned V_62 ;
F_23 ( V_57 L_27 ,
V_107 ) ;
V_61 = V_107 / 100 ;
if ( ! V_61 )
V_61 = 1 ;
V_62 = 0 ;
V_39 = NULL ;
F_44 ( & V_9 ) ;
for ( ; ; ) {
V_42 = F_80 ( V_59 ) ;
if ( V_42 <= 0 )
break;
V_42 = F_77 ( V_19 , F_46 ( * V_59 ) , & V_39 ) ;
if ( V_42 )
break;
if ( V_59 -> V_108 )
V_42 = F_32 ( & V_39 ) ;
if ( V_42 )
break;
if ( ! ( V_62 % V_61 ) )
F_23 ( L_9 , V_62 / V_61 ) ;
V_62 ++ ;
}
V_63 = F_32 ( & V_39 ) ;
F_44 ( & V_65 ) ;
if ( ! V_42 )
V_42 = V_63 ;
if ( ! V_42 ) {
F_23 ( L_10 ) ;
F_81 ( V_59 ) ;
if ( ! F_82 ( V_59 ) )
V_42 = - V_109 ;
} else
F_23 ( L_11 ) ;
F_47 ( & V_9 , & V_65 , V_107 , L_28 ) ;
return V_42 ;
}
static int F_83 ( void * V_67 )
{
struct V_110 * V_69 = V_67 ;
while ( 1 ) {
F_49 ( V_69 -> V_71 , F_50 ( & V_69 -> V_72 ) ||
F_51 () ) ;
if ( F_51 () ) {
V_69 -> V_73 = NULL ;
V_69 -> V_42 = - 1 ;
F_52 ( & V_69 -> V_65 , 1 ) ;
F_53 ( & V_69 -> V_74 ) ;
break;
}
F_52 ( & V_69 -> V_72 , 0 ) ;
V_69 -> V_77 = V_90 ;
V_69 -> V_42 = F_84 ( V_69 -> V_79 + V_80 , V_69 -> V_81 ,
V_69 -> V_76 , & V_69 -> V_77 ) ;
F_52 ( & V_69 -> V_65 , 1 ) ;
F_53 ( & V_69 -> V_74 ) ;
}
return 0 ;
}
static int F_85 ( struct V_18 * V_19 ,
struct V_58 * V_59 ,
unsigned int V_107 )
{
unsigned int V_61 ;
int V_42 = 0 ;
int V_111 = 0 ;
struct V_39 * V_39 ;
struct V_64 V_9 ;
struct V_64 V_65 ;
unsigned V_62 ;
T_2 V_83 ;
unsigned V_70 , V_73 , V_75 , V_84 ;
unsigned V_112 = 0 , V_113 = 0 , V_114 = 0 ,
V_115 = 0 , V_116 , V_117 , V_118 = 0 ;
unsigned long V_119 = 0 ;
unsigned char * * V_85 = NULL ;
struct V_110 * V_67 = NULL ;
struct V_68 * V_86 = NULL ;
V_84 = F_58 () - 1 ;
V_84 = F_59 ( V_84 , 1 , V_87 ) ;
V_85 = F_60 ( sizeof( * V_85 ) * V_120 ) ;
if ( ! V_85 ) {
F_23 ( V_30 L_13 ) ;
V_42 = - V_15 ;
goto V_89;
}
V_67 = F_60 ( sizeof( * V_67 ) * V_84 ) ;
if ( ! V_67 ) {
F_23 ( V_30 L_14 ) ;
V_42 = - V_15 ;
goto V_89;
}
for ( V_73 = 0 ; V_73 < V_84 ; V_73 ++ )
memset ( & V_67 [ V_73 ] , 0 , F_61 ( struct V_110 , V_71 ) ) ;
V_86 = F_62 ( sizeof( * V_86 ) , V_14 ) ;
if ( ! V_86 ) {
F_23 ( V_30 L_15 ) ;
V_42 = - V_15 ;
goto V_89;
}
memset ( V_86 , 0 , F_61 ( struct V_68 , V_71 ) ) ;
for ( V_73 = 0 ; V_73 < V_84 ; V_73 ++ ) {
F_63 ( & V_67 [ V_73 ] . V_71 ) ;
F_63 ( & V_67 [ V_73 ] . V_74 ) ;
V_67 [ V_73 ] . V_73 = F_64 ( F_83 ,
& V_67 [ V_73 ] ,
L_29 , V_73 ) ;
if ( F_65 ( V_67 [ V_73 ] . V_73 ) ) {
V_67 [ V_73 ] . V_73 = NULL ;
F_23 ( V_30
L_30 ) ;
V_42 = - V_15 ;
goto V_89;
}
}
F_63 ( & V_86 -> V_71 ) ;
F_63 ( & V_86 -> V_74 ) ;
V_19 -> V_29 = 0 ;
V_86 -> V_29 = & V_19 -> V_29 ;
for ( V_73 = 0 ; V_73 < V_84 ; V_73 ++ ) {
V_86 -> V_76 [ V_73 ] = V_67 [ V_73 ] . V_76 ;
V_86 -> V_77 [ V_73 ] = & V_67 [ V_73 ] . V_77 ;
}
V_86 -> V_73 = F_64 ( F_48 , V_86 , L_18 ) ;
if ( F_65 ( V_86 -> V_73 ) ) {
V_86 -> V_73 = NULL ;
F_23 ( V_30 L_19 ) ;
V_42 = - V_15 ;
goto V_89;
}
if ( F_1 () > F_74 () )
V_119 = ( F_1 () - F_74 () ) / 2 ;
V_119 = F_59 ( V_119 , V_121 , V_120 ) ;
for ( V_70 = 0 ; V_70 < V_119 ; V_70 ++ ) {
V_85 [ V_70 ] = ( void * ) F_30 ( V_70 < V_122 ?
V_44 | V_88 :
V_44 | V_45 |
V_46 ) ;
if ( ! V_85 [ V_70 ] ) {
if ( V_70 < V_122 ) {
V_114 = V_70 ;
F_23 ( V_30
L_31 ) ;
V_42 = - V_15 ;
goto V_89;
} else {
break;
}
}
}
V_116 = V_114 = V_70 ;
F_23 ( V_57
L_32
L_33 ,
V_84 , V_107 ) ;
V_61 = V_107 / 100 ;
if ( ! V_61 )
V_61 = 1 ;
V_62 = 0 ;
V_39 = NULL ;
F_44 ( & V_9 ) ;
V_42 = F_80 ( V_59 ) ;
if ( V_42 <= 0 )
goto V_91;
for(; ; ) {
for ( V_70 = 0 ; ! V_111 && V_70 < V_116 ; V_70 ++ ) {
V_42 = F_77 ( V_19 , V_85 [ V_112 ] , & V_39 ) ;
if ( V_42 ) {
if ( V_19 -> V_47 &&
V_19 -> V_47 -> V_53 [ V_19 -> V_52 ] ) {
goto V_91;
} else {
V_111 = 1 ;
break;
}
}
if ( ++ V_112 >= V_114 )
V_112 = 0 ;
}
V_118 += V_70 ;
V_116 -= V_70 ;
if ( ! V_115 ) {
if ( ! V_118 )
break;
V_42 = F_32 ( & V_39 ) ;
if ( V_42 )
goto V_91;
V_115 += V_118 ;
V_118 = 0 ;
if ( V_111 )
V_111 = 2 ;
}
if ( V_86 -> V_75 ) {
F_49 ( V_86 -> V_74 , F_50 ( & V_86 -> V_65 ) ) ;
F_52 ( & V_86 -> V_65 , 0 ) ;
V_86 -> V_75 = 0 ;
}
for ( V_73 = 0 ; V_115 && V_73 < V_84 ; V_73 ++ ) {
V_67 [ V_73 ] . V_81 = * ( T_2 * ) V_85 [ V_113 ] ;
if ( F_66 ( ! V_67 [ V_73 ] . V_81 ||
V_67 [ V_73 ] . V_81 >
F_67 ( V_90 ) ) ) {
F_23 ( V_30
L_23 ) ;
V_42 = - 1 ;
goto V_91;
}
V_117 = F_86 ( V_67 [ V_73 ] . V_81 + V_80 ,
V_37 ) ;
if ( V_117 > V_115 ) {
if ( V_111 > 1 ) {
V_42 = - 1 ;
goto V_91;
}
break;
}
for ( V_83 = 0 ;
V_83 < V_80 + V_67 [ V_73 ] . V_81 ;
V_83 += V_37 ) {
memcpy ( V_67 [ V_73 ] . V_79 + V_83 ,
V_85 [ V_113 ] , V_37 ) ;
V_115 -- ;
V_116 ++ ;
if ( ++ V_113 >= V_114 )
V_113 = 0 ;
}
F_52 ( & V_67 [ V_73 ] . V_72 , 1 ) ;
F_53 ( & V_67 [ V_73 ] . V_71 ) ;
}
if ( V_115 < V_122 && V_118 ) {
V_42 = F_32 ( & V_39 ) ;
if ( V_42 )
goto V_91;
V_115 += V_118 ;
V_118 = 0 ;
if ( V_111 )
V_111 = 2 ;
}
for ( V_75 = V_73 , V_73 = 0 ; V_73 < V_75 ; V_73 ++ ) {
F_49 ( V_67 [ V_73 ] . V_74 ,
F_50 ( & V_67 [ V_73 ] . V_65 ) ) ;
F_52 ( & V_67 [ V_73 ] . V_65 , 0 ) ;
V_42 = V_67 [ V_73 ] . V_42 ;
if ( V_42 < 0 ) {
F_23 ( V_30
L_34 ) ;
goto V_91;
}
if ( F_66 ( ! V_67 [ V_73 ] . V_77 ||
V_67 [ V_73 ] . V_77 > V_90 ||
V_67 [ V_73 ] . V_77 & ( V_37 - 1 ) ) ) {
F_23 ( V_30
L_35 ) ;
V_42 = - 1 ;
goto V_91;
}
for ( V_83 = 0 ;
V_83 < V_67 [ V_73 ] . V_77 ; V_83 += V_37 ) {
memcpy ( F_46 ( * V_59 ) ,
V_67 [ V_73 ] . V_76 + V_83 , V_37 ) ;
if ( ! ( V_62 % V_61 ) )
F_23 ( L_9 , V_62 / V_61 ) ;
V_62 ++ ;
V_42 = F_80 ( V_59 ) ;
if ( V_42 <= 0 ) {
V_86 -> V_75 = V_73 + 1 ;
F_52 ( & V_86 -> V_72 , 1 ) ;
F_53 ( & V_86 -> V_71 ) ;
goto V_91;
}
}
}
V_86 -> V_75 = V_73 ;
F_52 ( & V_86 -> V_72 , 1 ) ;
F_53 ( & V_86 -> V_71 ) ;
}
V_91:
if ( V_86 -> V_75 ) {
F_49 ( V_86 -> V_74 , F_50 ( & V_86 -> V_65 ) ) ;
F_52 ( & V_86 -> V_65 , 0 ) ;
}
F_44 ( & V_65 ) ;
if ( ! V_42 ) {
F_23 ( L_10 ) ;
F_81 ( V_59 ) ;
if ( ! F_82 ( V_59 ) )
V_42 = - V_109 ;
if ( ! V_42 ) {
if ( V_22 -> V_20 & V_28 ) {
if( V_19 -> V_29 != V_22 -> V_29 ) {
F_23 ( V_30
L_36 ) ;
V_42 = - V_109 ;
}
}
}
} else
F_23 ( L_11 ) ;
F_47 ( & V_9 , & V_65 , V_107 , L_28 ) ;
V_89:
for ( V_70 = 0 ; V_70 < V_114 ; V_70 ++ )
F_35 ( ( unsigned long ) V_85 [ V_70 ] ) ;
if ( V_86 ) {
if ( V_86 -> V_73 )
F_68 ( V_86 -> V_73 ) ;
F_18 ( V_86 ) ;
}
if ( V_67 ) {
for ( V_73 = 0 ; V_73 < V_84 ; V_73 ++ )
if ( V_67 [ V_73 ] . V_73 )
F_68 ( V_67 [ V_73 ] . V_73 ) ;
F_69 ( V_67 ) ;
}
if ( V_85 ) F_69 ( V_85 ) ;
return V_42 ;
}
int F_87 ( unsigned int * V_105 )
{
int error ;
struct V_18 V_19 ;
struct V_58 V_59 ;
struct V_95 * V_96 ;
memset ( & V_59 , 0 , sizeof( struct V_58 ) ) ;
error = F_80 ( & V_59 ) ;
if ( error < V_37 )
return error < 0 ? error : - V_99 ;
V_96 = (struct V_95 * ) F_46 ( V_59 ) ;
error = F_76 ( & V_19 , V_105 ) ;
if ( error )
goto V_11;
if ( ! error )
error = F_77 ( & V_19 , V_96 , NULL ) ;
if ( ! error ) {
error = ( * V_105 & V_98 ) ?
F_79 ( & V_19 , & V_59 , V_96 -> V_97 - 1 ) :
F_85 ( & V_19 , & V_59 , V_96 -> V_97 - 1 ) ;
}
F_78 ( & V_19 ) ;
V_11:
if ( ! error )
F_72 ( L_37 ) ;
else
F_72 ( L_38 , error ) ;
return error ;
}
int F_88 ( void )
{
int error ;
V_34 = F_89 ( V_33 ,
V_123 , NULL ) ;
if ( ! F_65 ( V_34 ) ) {
F_27 ( V_34 , V_37 ) ;
F_40 ( V_22 ) ;
error = F_21 ( V_21 ,
V_22 , NULL ) ;
if ( error )
goto V_124;
if ( ! memcmp ( V_25 , V_22 -> V_23 , 10 ) ) {
memcpy ( V_22 -> V_23 , V_22 -> V_24 , 10 ) ;
error = F_22 ( V_21 ,
V_22 , NULL ) ;
} else {
error = - V_13 ;
}
V_124:
if ( error )
F_28 ( V_34 , V_123 ) ;
else
F_72 ( L_39 ) ;
} else {
error = F_90 ( V_34 ) ;
}
if ( error )
F_72 ( L_40 , error ) ;
return error ;
}
void F_38 ( T_3 V_125 )
{
if ( F_65 ( V_34 ) ) {
F_72 ( L_41 ) ;
return;
}
F_28 ( V_34 , V_125 ) ;
}
static int F_91 ( void )
{
V_22 = (struct V_22 * ) F_30 ( V_14 ) ;
if ( ! V_22 )
F_92 ( L_42 ) ;
return 0 ;
}
