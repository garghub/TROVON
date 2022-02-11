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
static int F_21 ( struct V_18 * V_19 , unsigned int V_20 )
{
int error ;
F_22 ( V_21 , V_22 , NULL ) ;
if ( ! memcmp ( L_1 , V_22 -> V_23 , 10 ) ||
! memcmp ( L_2 , V_22 -> V_23 , 10 ) ) {
memcpy ( V_22 -> V_24 , V_22 -> V_23 , 10 ) ;
memcpy ( V_22 -> V_23 , V_25 , 10 ) ;
V_22 -> V_26 = V_19 -> V_27 ;
V_22 -> V_20 = V_20 ;
if ( V_20 & V_28 )
V_22 -> V_29 = V_19 -> V_29 ;
error = F_23 ( V_21 ,
V_22 , NULL ) ;
} else {
F_24 ( V_30 L_3 ) ;
error = - V_31 ;
}
return error ;
}
static int F_25 ( void )
{
int V_32 ;
V_32 = F_26 ( V_33 , V_21 ,
& V_34 ) ;
if ( V_32 < 0 )
return V_32 ;
V_35 = V_32 ;
V_32 = F_27 ( V_34 , V_36 , NULL ) ;
if ( V_32 )
return V_32 ;
V_32 = F_28 ( V_34 , V_37 ) ;
if ( V_32 < 0 )
F_29 ( V_34 , V_36 ) ;
return V_32 ;
}
static int F_30 ( void * V_38 , T_1 V_17 , struct V_39 * * V_40 )
{
void * V_41 ;
int V_42 ;
if ( ! V_17 )
return - V_43 ;
if ( V_40 ) {
V_41 = ( void * ) F_31 ( V_44 | V_45 |
V_46 ) ;
if ( V_41 ) {
F_32 ( V_41 , V_38 ) ;
} else {
V_42 = F_33 ( V_40 ) ;
if ( V_42 )
return V_42 ;
V_41 = ( void * ) F_31 ( V_44 |
V_45 |
V_46 ) ;
if ( V_41 ) {
F_32 ( V_41 , V_38 ) ;
} else {
F_34 ( 1 ) ;
V_40 = NULL ;
V_41 = V_38 ;
}
}
} else {
V_41 = V_38 ;
}
return F_23 ( V_17 , V_41 , V_40 ) ;
}
static void F_35 ( struct V_18 * V_19 )
{
if ( V_19 -> V_47 )
F_36 ( ( unsigned long ) V_19 -> V_47 ) ;
V_19 -> V_47 = NULL ;
}
static int F_37 ( struct V_18 * V_19 )
{
int V_42 ;
V_42 = F_25 () ;
if ( V_42 ) {
if ( V_42 != - V_43 )
F_24 ( V_30 L_4
L_5 ) ;
return V_42 ;
}
V_19 -> V_47 = (struct V_48 * ) F_38 ( V_14 ) ;
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
F_35 ( V_19 ) ;
V_49:
F_39 ( V_36 ) ;
return V_42 ;
}
static int F_40 ( struct V_18 * V_19 , void * V_38 ,
struct V_39 * * V_40 )
{
int error = 0 ;
T_1 V_17 ;
if ( ! V_19 -> V_47 )
return - V_13 ;
V_17 = F_10 ( V_35 ) ;
error = F_30 ( V_38 , V_17 , V_40 ) ;
if ( error )
return error ;
V_19 -> V_47 -> V_53 [ V_19 -> V_52 ++ ] = V_17 ;
if ( V_19 -> V_52 >= V_54 ) {
V_17 = F_10 ( V_35 ) ;
if ( ! V_17 )
return - V_43 ;
V_19 -> V_47 -> V_55 = V_17 ;
error = F_30 ( V_19 -> V_47 , V_19 -> V_50 , V_40 ) ;
if ( error )
goto V_56;
F_41 ( V_19 -> V_47 ) ;
V_19 -> V_50 = V_17 ;
V_19 -> V_52 = 0 ;
if ( V_40 && F_1 () <= V_19 -> F_4 ) {
error = F_33 ( V_40 ) ;
if ( error )
goto V_56;
V_19 -> F_4 = F_4 () ;
}
}
V_56:
return error ;
}
static int F_42 ( struct V_18 * V_19 )
{
if ( V_19 -> V_47 && V_19 -> V_50 )
return F_30 ( V_19 -> V_47 , V_19 -> V_50 , NULL ) ;
else
return - V_13 ;
}
static int F_43 ( struct V_18 * V_19 ,
unsigned int V_20 , int error )
{
if ( ! error ) {
F_42 ( V_19 ) ;
F_24 ( V_57 L_6 ) ;
error = F_21 ( V_19 , V_20 ) ;
F_24 ( L_7 ) ;
}
if ( error )
F_16 ( V_35 ) ;
F_35 ( V_19 ) ;
F_39 ( V_36 ) ;
return error ;
}
static int F_44 ( struct V_18 * V_19 ,
struct V_58 * V_59 ,
unsigned int V_60 )
{
unsigned int V_61 ;
int V_42 ;
int V_62 ;
int V_63 ;
struct V_39 * V_39 ;
T_2 V_9 ;
T_2 V_64 ;
F_24 ( V_57 L_8 ,
V_60 ) ;
V_61 = V_60 / 10 ;
if ( ! V_61 )
V_61 = 1 ;
V_62 = 0 ;
V_39 = NULL ;
V_9 = F_45 () ;
while ( 1 ) {
V_42 = F_46 ( V_59 ) ;
if ( V_42 <= 0 )
break;
V_42 = F_40 ( V_19 , F_47 ( * V_59 ) , & V_39 ) ;
if ( V_42 )
break;
if ( ! ( V_62 % V_61 ) )
F_24 ( V_57 L_9 ,
V_62 / V_61 * 10 ) ;
V_62 ++ ;
}
V_63 = F_33 ( & V_39 ) ;
V_64 = F_45 () ;
if ( ! V_42 )
V_42 = V_63 ;
if ( ! V_42 )
F_24 ( V_57 L_10 ) ;
F_48 ( V_9 , V_64 , V_60 , L_11 ) ;
return V_42 ;
}
static int F_49 ( void * V_65 )
{
struct V_66 * V_67 = V_65 ;
unsigned V_68 ;
while ( 1 ) {
F_50 ( V_67 -> V_69 , F_51 ( & V_67 -> V_70 ) ||
F_52 () ) ;
if ( F_52 () ) {
V_67 -> V_71 = NULL ;
F_53 ( & V_67 -> V_64 , 1 ) ;
F_54 ( & V_67 -> V_72 ) ;
break;
}
F_53 ( & V_67 -> V_70 , 0 ) ;
for ( V_68 = 0 ; V_68 < V_67 -> V_73 ; V_68 ++ )
* V_67 -> V_29 = F_55 ( * V_67 -> V_29 ,
V_67 -> V_74 [ V_68 ] , * V_67 -> V_75 [ V_68 ] ) ;
F_53 ( & V_67 -> V_64 , 1 ) ;
F_54 ( & V_67 -> V_72 ) ;
}
return 0 ;
}
static int F_56 ( void * V_65 )
{
struct V_76 * V_67 = V_65 ;
while ( 1 ) {
F_50 ( V_67 -> V_69 , F_51 ( & V_67 -> V_70 ) ||
F_52 () ) ;
if ( F_52 () ) {
V_67 -> V_71 = NULL ;
V_67 -> V_42 = - 1 ;
F_53 ( & V_67 -> V_64 , 1 ) ;
F_54 ( & V_67 -> V_72 ) ;
break;
}
F_53 ( & V_67 -> V_70 , 0 ) ;
V_67 -> V_42 = F_57 ( V_67 -> V_74 , V_67 -> V_75 ,
V_67 -> V_77 + V_78 , & V_67 -> V_79 ,
V_67 -> V_80 ) ;
F_53 ( & V_67 -> V_64 , 1 ) ;
F_54 ( & V_67 -> V_72 ) ;
}
return 0 ;
}
static int F_58 ( struct V_18 * V_19 ,
struct V_58 * V_59 ,
unsigned int V_60 )
{
unsigned int V_61 ;
int V_42 = 0 ;
int V_62 ;
int V_63 ;
struct V_39 * V_39 ;
T_2 V_9 ;
T_2 V_64 ;
T_3 V_81 ;
unsigned V_71 , V_73 , V_82 ;
unsigned char * V_83 = NULL ;
struct V_76 * V_65 = NULL ;
struct V_66 * V_84 = NULL ;
V_82 = F_59 () - 1 ;
V_82 = F_60 ( V_82 , 1 , V_85 ) ;
V_83 = ( void * ) F_31 ( V_44 | V_86 ) ;
if ( ! V_83 ) {
F_24 ( V_30 L_12 ) ;
V_42 = - V_15 ;
goto V_87;
}
V_65 = F_61 ( sizeof( * V_65 ) * V_82 ) ;
if ( ! V_65 ) {
F_24 ( V_30 L_13 ) ;
V_42 = - V_15 ;
goto V_87;
}
for ( V_71 = 0 ; V_71 < V_82 ; V_71 ++ )
memset ( & V_65 [ V_71 ] , 0 , F_62 ( struct V_76 , V_69 ) ) ;
V_84 = F_63 ( sizeof( * V_84 ) , V_14 ) ;
if ( ! V_84 ) {
F_24 ( V_30 L_14 ) ;
V_42 = - V_15 ;
goto V_87;
}
memset ( V_84 , 0 , F_62 ( struct V_66 , V_69 ) ) ;
for ( V_71 = 0 ; V_71 < V_82 ; V_71 ++ ) {
F_64 ( & V_65 [ V_71 ] . V_69 ) ;
F_64 ( & V_65 [ V_71 ] . V_72 ) ;
V_65 [ V_71 ] . V_71 = F_65 ( F_56 ,
& V_65 [ V_71 ] ,
L_15 , V_71 ) ;
if ( F_66 ( V_65 [ V_71 ] . V_71 ) ) {
V_65 [ V_71 ] . V_71 = NULL ;
F_24 ( V_30
L_16 ) ;
V_42 = - V_15 ;
goto V_87;
}
}
F_64 ( & V_84 -> V_69 ) ;
F_64 ( & V_84 -> V_72 ) ;
V_19 -> V_29 = 0 ;
V_84 -> V_29 = & V_19 -> V_29 ;
for ( V_71 = 0 ; V_71 < V_82 ; V_71 ++ ) {
V_84 -> V_74 [ V_71 ] = V_65 [ V_71 ] . V_74 ;
V_84 -> V_75 [ V_71 ] = & V_65 [ V_71 ] . V_75 ;
}
V_84 -> V_71 = F_65 ( F_49 , V_84 , L_17 ) ;
if ( F_66 ( V_84 -> V_71 ) ) {
V_84 -> V_71 = NULL ;
F_24 ( V_30 L_18 ) ;
V_42 = - V_15 ;
goto V_87;
}
V_19 -> F_4 = F_4 () ;
F_24 ( V_57
L_19
L_20 ,
V_82 , V_60 ) ;
V_61 = V_60 / 10 ;
if ( ! V_61 )
V_61 = 1 ;
V_62 = 0 ;
V_39 = NULL ;
V_9 = F_45 () ;
for (; ; ) {
for ( V_71 = 0 ; V_71 < V_82 ; V_71 ++ ) {
for ( V_81 = 0 ; V_81 < V_88 ; V_81 += V_37 ) {
V_42 = F_46 ( V_59 ) ;
if ( V_42 < 0 )
goto V_89;
if ( ! V_42 )
break;
memcpy ( V_65 [ V_71 ] . V_74 + V_81 ,
F_47 ( * V_59 ) , V_37 ) ;
if ( ! ( V_62 % V_61 ) )
F_24 ( V_57
L_21
L_22 ,
V_62 / V_61 * 10 ) ;
V_62 ++ ;
}
if ( ! V_81 )
break;
V_65 [ V_71 ] . V_75 = V_81 ;
F_53 ( & V_65 [ V_71 ] . V_70 , 1 ) ;
F_54 ( & V_65 [ V_71 ] . V_69 ) ;
}
if ( ! V_71 )
break;
V_84 -> V_73 = V_71 ;
F_53 ( & V_84 -> V_70 , 1 ) ;
F_54 ( & V_84 -> V_69 ) ;
for ( V_73 = V_71 , V_71 = 0 ; V_71 < V_73 ; V_71 ++ ) {
F_50 ( V_65 [ V_71 ] . V_72 ,
F_51 ( & V_65 [ V_71 ] . V_64 ) ) ;
F_53 ( & V_65 [ V_71 ] . V_64 , 0 ) ;
V_42 = V_65 [ V_71 ] . V_42 ;
if ( V_42 < 0 ) {
F_24 ( V_30 L_23 ) ;
goto V_89;
}
if ( F_67 ( ! V_65 [ V_71 ] . V_79 ||
V_65 [ V_71 ] . V_79 >
F_68 ( V_65 [ V_71 ] . V_75 ) ) ) {
F_24 ( V_30
L_24 ) ;
V_42 = - 1 ;
goto V_89;
}
* ( T_3 * ) V_65 [ V_71 ] . V_77 = V_65 [ V_71 ] . V_79 ;
for ( V_81 = 0 ;
V_81 < V_78 + V_65 [ V_71 ] . V_79 ;
V_81 += V_37 ) {
memcpy ( V_83 , V_65 [ V_71 ] . V_77 + V_81 , V_37 ) ;
V_42 = F_40 ( V_19 , V_83 , & V_39 ) ;
if ( V_42 )
goto V_89;
}
}
F_50 ( V_84 -> V_72 , F_51 ( & V_84 -> V_64 ) ) ;
F_53 ( & V_84 -> V_64 , 0 ) ;
}
V_89:
V_63 = F_33 ( & V_39 ) ;
V_64 = F_45 () ;
if ( ! V_42 )
V_42 = V_63 ;
if ( ! V_42 )
F_24 ( V_57 L_10 ) ;
F_48 ( V_9 , V_64 , V_60 , L_11 ) ;
V_87:
if ( V_84 ) {
if ( V_84 -> V_71 )
F_69 ( V_84 -> V_71 ) ;
F_19 ( V_84 ) ;
}
if ( V_65 ) {
for ( V_71 = 0 ; V_71 < V_82 ; V_71 ++ )
if ( V_65 [ V_71 ] . V_71 )
F_69 ( V_65 [ V_71 ] . V_71 ) ;
F_70 ( V_65 ) ;
}
if ( V_83 ) F_36 ( ( unsigned long ) V_83 ) ;
return V_42 ;
}
static int F_71 ( unsigned int V_62 , unsigned int V_20 )
{
unsigned int V_90 = F_72 ( V_35 , 1 ) ;
unsigned int V_91 ;
F_73 ( L_25 , V_90 ) ;
V_91 = V_92 + V_62 ;
return V_90 > V_91 ;
}
int F_74 ( unsigned int V_20 )
{
struct V_18 V_19 ;
struct V_58 V_59 ;
struct V_93 * V_94 ;
unsigned long V_95 ;
int error ;
V_95 = F_75 () ;
error = F_37 ( & V_19 ) ;
if ( error ) {
F_24 ( V_30 L_26 ) ;
return error ;
}
if ( V_20 & V_96 ) {
if ( ! F_71 ( V_95 , V_20 ) ) {
F_24 ( V_30 L_27 ) ;
error = - V_43 ;
goto V_89;
}
}
memset ( & V_59 , 0 , sizeof( struct V_58 ) ) ;
error = F_46 ( & V_59 ) ;
if ( error < V_37 ) {
if ( error >= 0 )
error = - V_97 ;
goto V_89;
}
V_94 = (struct V_93 * ) F_47 ( V_59 ) ;
error = F_40 ( & V_19 , V_94 , NULL ) ;
if ( ! error ) {
error = ( V_20 & V_96 ) ?
F_44 ( & V_19 , & V_59 , V_95 - 1 ) :
F_58 ( & V_19 , & V_59 , V_95 - 1 ) ;
}
V_89:
error = F_43 ( & V_19 , V_20 , error ) ;
return error ;
}
static void F_76 ( struct V_18 * V_19 )
{
struct V_98 * V_99 ;
while ( V_19 -> V_100 ) {
if ( V_19 -> V_100 -> V_101 )
F_36 ( ( unsigned long ) V_19 -> V_100 -> V_101 ) ;
V_99 = V_19 -> V_100 ;
V_19 -> V_100 = V_19 -> V_100 -> V_102 ;
F_19 ( V_99 ) ;
}
V_19 -> V_47 = NULL ;
}
static int F_77 ( struct V_18 * V_19 ,
unsigned int * V_103 )
{
int error ;
struct V_98 * V_99 , * V_104 ;
T_1 V_17 ;
* V_103 = V_22 -> V_20 ;
if ( ! V_22 -> V_26 )
return - V_13 ;
V_19 -> V_47 = NULL ;
V_104 = V_19 -> V_100 = NULL ;
V_17 = V_22 -> V_26 ;
while ( V_17 ) {
V_99 = F_63 ( sizeof( * V_19 -> V_100 ) , V_14 ) ;
if ( ! V_99 ) {
F_76 ( V_19 ) ;
return - V_15 ;
}
memset ( V_99 , 0 , sizeof( * V_99 ) ) ;
if ( ! V_19 -> V_100 )
V_19 -> V_100 = V_99 ;
if ( V_104 )
V_104 -> V_102 = V_99 ;
V_104 = V_99 ;
V_99 -> V_101 = (struct V_48 * )
F_31 ( V_44 | V_86 ) ;
if ( ! V_99 -> V_101 ) {
F_76 ( V_19 ) ;
return - V_15 ;
}
error = F_22 ( V_17 , V_99 -> V_101 , NULL ) ;
if ( error ) {
F_76 ( V_19 ) ;
return error ;
}
V_17 = V_99 -> V_101 -> V_55 ;
}
V_19 -> V_52 = 0 ;
V_19 -> V_47 = V_19 -> V_100 -> V_101 ;
return 0 ;
}
static int F_78 ( struct V_18 * V_19 , void * V_38 ,
struct V_39 * * V_40 )
{
T_1 V_17 ;
int error ;
struct V_98 * V_99 ;
if ( ! V_19 -> V_47 )
return - V_13 ;
V_17 = V_19 -> V_47 -> V_53 [ V_19 -> V_52 ] ;
if ( ! V_17 )
return - V_97 ;
error = F_22 ( V_17 , V_38 , V_40 ) ;
if ( error )
return error ;
if ( ++ V_19 -> V_52 >= V_54 ) {
V_19 -> V_52 = 0 ;
F_36 ( ( unsigned long ) V_19 -> V_100 -> V_101 ) ;
V_99 = V_19 -> V_100 ;
V_19 -> V_100 = V_19 -> V_100 -> V_102 ;
F_19 ( V_99 ) ;
if ( ! V_19 -> V_100 )
F_76 ( V_19 ) ;
else
V_19 -> V_47 = V_19 -> V_100 -> V_101 ;
}
return error ;
}
static int F_79 ( struct V_18 * V_19 )
{
F_76 ( V_19 ) ;
return 0 ;
}
static int F_80 ( struct V_18 * V_19 ,
struct V_58 * V_59 ,
unsigned int V_105 )
{
unsigned int V_61 ;
int V_42 = 0 ;
T_2 V_9 ;
T_2 V_64 ;
struct V_39 * V_39 ;
int V_63 ;
unsigned V_62 ;
F_24 ( V_57 L_28 ,
V_105 ) ;
V_61 = V_105 / 10 ;
if ( ! V_61 )
V_61 = 1 ;
V_62 = 0 ;
V_39 = NULL ;
V_9 = F_45 () ;
for ( ; ; ) {
V_42 = F_81 ( V_59 ) ;
if ( V_42 <= 0 )
break;
V_42 = F_78 ( V_19 , F_47 ( * V_59 ) , & V_39 ) ;
if ( V_42 )
break;
if ( V_59 -> V_106 )
V_42 = F_33 ( & V_39 ) ;
if ( V_42 )
break;
if ( ! ( V_62 % V_61 ) )
F_24 ( V_57 L_29 ,
V_62 / V_61 * 10 ) ;
V_62 ++ ;
}
V_63 = F_33 ( & V_39 ) ;
V_64 = F_45 () ;
if ( ! V_42 )
V_42 = V_63 ;
if ( ! V_42 ) {
F_24 ( V_57 L_30 ) ;
F_82 ( V_59 ) ;
if ( ! F_83 ( V_59 ) )
V_42 = - V_107 ;
}
F_48 ( V_9 , V_64 , V_105 , L_31 ) ;
return V_42 ;
}
static int F_84 ( void * V_65 )
{
struct V_108 * V_67 = V_65 ;
while ( 1 ) {
F_50 ( V_67 -> V_69 , F_51 ( & V_67 -> V_70 ) ||
F_52 () ) ;
if ( F_52 () ) {
V_67 -> V_71 = NULL ;
V_67 -> V_42 = - 1 ;
F_53 ( & V_67 -> V_64 , 1 ) ;
F_54 ( & V_67 -> V_72 ) ;
break;
}
F_53 ( & V_67 -> V_70 , 0 ) ;
V_67 -> V_75 = V_88 ;
V_67 -> V_42 = F_85 ( V_67 -> V_77 + V_78 , V_67 -> V_79 ,
V_67 -> V_74 , & V_67 -> V_75 ) ;
F_53 ( & V_67 -> V_64 , 1 ) ;
F_54 ( & V_67 -> V_72 ) ;
}
return 0 ;
}
static int F_86 ( struct V_18 * V_19 ,
struct V_58 * V_59 ,
unsigned int V_105 )
{
unsigned int V_61 ;
int V_42 = 0 ;
int V_109 = 0 ;
struct V_39 * V_39 ;
T_2 V_9 ;
T_2 V_64 ;
unsigned V_62 ;
T_3 V_81 ;
unsigned V_68 , V_71 , V_73 , V_82 ;
unsigned V_110 = 0 , V_111 = 0 , V_112 = 0 ,
V_113 = 0 , V_114 , V_115 , V_116 = 0 ;
unsigned long V_117 = 0 ;
unsigned char * * V_83 = NULL ;
struct V_108 * V_65 = NULL ;
struct V_66 * V_84 = NULL ;
V_82 = F_59 () - 1 ;
V_82 = F_60 ( V_82 , 1 , V_85 ) ;
V_83 = F_61 ( sizeof( * V_83 ) * V_118 ) ;
if ( ! V_83 ) {
F_24 ( V_30 L_12 ) ;
V_42 = - V_15 ;
goto V_87;
}
V_65 = F_61 ( sizeof( * V_65 ) * V_82 ) ;
if ( ! V_65 ) {
F_24 ( V_30 L_13 ) ;
V_42 = - V_15 ;
goto V_87;
}
for ( V_71 = 0 ; V_71 < V_82 ; V_71 ++ )
memset ( & V_65 [ V_71 ] , 0 , F_62 ( struct V_108 , V_69 ) ) ;
V_84 = F_63 ( sizeof( * V_84 ) , V_14 ) ;
if ( ! V_84 ) {
F_24 ( V_30 L_14 ) ;
V_42 = - V_15 ;
goto V_87;
}
memset ( V_84 , 0 , F_62 ( struct V_66 , V_69 ) ) ;
for ( V_71 = 0 ; V_71 < V_82 ; V_71 ++ ) {
F_64 ( & V_65 [ V_71 ] . V_69 ) ;
F_64 ( & V_65 [ V_71 ] . V_72 ) ;
V_65 [ V_71 ] . V_71 = F_65 ( F_84 ,
& V_65 [ V_71 ] ,
L_32 , V_71 ) ;
if ( F_66 ( V_65 [ V_71 ] . V_71 ) ) {
V_65 [ V_71 ] . V_71 = NULL ;
F_24 ( V_30
L_33 ) ;
V_42 = - V_15 ;
goto V_87;
}
}
F_64 ( & V_84 -> V_69 ) ;
F_64 ( & V_84 -> V_72 ) ;
V_19 -> V_29 = 0 ;
V_84 -> V_29 = & V_19 -> V_29 ;
for ( V_71 = 0 ; V_71 < V_82 ; V_71 ++ ) {
V_84 -> V_74 [ V_71 ] = V_65 [ V_71 ] . V_74 ;
V_84 -> V_75 [ V_71 ] = & V_65 [ V_71 ] . V_75 ;
}
V_84 -> V_71 = F_65 ( F_49 , V_84 , L_17 ) ;
if ( F_66 ( V_84 -> V_71 ) ) {
V_84 -> V_71 = NULL ;
F_24 ( V_30 L_18 ) ;
V_42 = - V_15 ;
goto V_87;
}
if ( F_1 () > F_75 () )
V_117 = ( F_1 () - F_75 () ) / 2 ;
V_117 = F_60 ( V_117 , V_119 , V_118 ) ;
for ( V_68 = 0 ; V_68 < V_117 ; V_68 ++ ) {
V_83 [ V_68 ] = ( void * ) F_31 ( V_68 < V_120 ?
V_44 | V_86 :
V_44 | V_45 |
V_46 ) ;
if ( ! V_83 [ V_68 ] ) {
if ( V_68 < V_120 ) {
V_112 = V_68 ;
F_24 ( V_30
L_34 ) ;
V_42 = - V_15 ;
goto V_87;
} else {
break;
}
}
}
V_114 = V_112 = V_68 ;
F_24 ( V_57
L_35
L_36 ,
V_82 , V_105 ) ;
V_61 = V_105 / 10 ;
if ( ! V_61 )
V_61 = 1 ;
V_62 = 0 ;
V_39 = NULL ;
V_9 = F_45 () ;
V_42 = F_81 ( V_59 ) ;
if ( V_42 <= 0 )
goto V_89;
for(; ; ) {
for ( V_68 = 0 ; ! V_109 && V_68 < V_114 ; V_68 ++ ) {
V_42 = F_78 ( V_19 , V_83 [ V_110 ] , & V_39 ) ;
if ( V_42 ) {
if ( V_19 -> V_47 &&
V_19 -> V_47 -> V_53 [ V_19 -> V_52 ] ) {
goto V_89;
} else {
V_109 = 1 ;
break;
}
}
if ( ++ V_110 >= V_112 )
V_110 = 0 ;
}
V_116 += V_68 ;
V_114 -= V_68 ;
if ( ! V_113 ) {
if ( ! V_116 )
break;
V_42 = F_33 ( & V_39 ) ;
if ( V_42 )
goto V_89;
V_113 += V_116 ;
V_116 = 0 ;
if ( V_109 )
V_109 = 2 ;
}
if ( V_84 -> V_73 ) {
F_50 ( V_84 -> V_72 , F_51 ( & V_84 -> V_64 ) ) ;
F_53 ( & V_84 -> V_64 , 0 ) ;
V_84 -> V_73 = 0 ;
}
for ( V_71 = 0 ; V_113 && V_71 < V_82 ; V_71 ++ ) {
V_65 [ V_71 ] . V_79 = * ( T_3 * ) V_83 [ V_111 ] ;
if ( F_67 ( ! V_65 [ V_71 ] . V_79 ||
V_65 [ V_71 ] . V_79 >
F_68 ( V_88 ) ) ) {
F_24 ( V_30
L_24 ) ;
V_42 = - 1 ;
goto V_89;
}
V_115 = F_87 ( V_65 [ V_71 ] . V_79 + V_78 ,
V_37 ) ;
if ( V_115 > V_113 ) {
if ( V_109 > 1 ) {
V_42 = - 1 ;
goto V_89;
}
break;
}
for ( V_81 = 0 ;
V_81 < V_78 + V_65 [ V_71 ] . V_79 ;
V_81 += V_37 ) {
memcpy ( V_65 [ V_71 ] . V_77 + V_81 ,
V_83 [ V_111 ] , V_37 ) ;
V_113 -- ;
V_114 ++ ;
if ( ++ V_111 >= V_112 )
V_111 = 0 ;
}
F_53 ( & V_65 [ V_71 ] . V_70 , 1 ) ;
F_54 ( & V_65 [ V_71 ] . V_69 ) ;
}
if ( V_113 < V_120 && V_116 ) {
V_42 = F_33 ( & V_39 ) ;
if ( V_42 )
goto V_89;
V_113 += V_116 ;
V_116 = 0 ;
if ( V_109 )
V_109 = 2 ;
}
for ( V_73 = V_71 , V_71 = 0 ; V_71 < V_73 ; V_71 ++ ) {
F_50 ( V_65 [ V_71 ] . V_72 ,
F_51 ( & V_65 [ V_71 ] . V_64 ) ) ;
F_53 ( & V_65 [ V_71 ] . V_64 , 0 ) ;
V_42 = V_65 [ V_71 ] . V_42 ;
if ( V_42 < 0 ) {
F_24 ( V_30
L_37 ) ;
goto V_89;
}
if ( F_67 ( ! V_65 [ V_71 ] . V_75 ||
V_65 [ V_71 ] . V_75 > V_88 ||
V_65 [ V_71 ] . V_75 & ( V_37 - 1 ) ) ) {
F_24 ( V_30
L_38 ) ;
V_42 = - 1 ;
goto V_89;
}
for ( V_81 = 0 ;
V_81 < V_65 [ V_71 ] . V_75 ; V_81 += V_37 ) {
memcpy ( F_47 ( * V_59 ) ,
V_65 [ V_71 ] . V_74 + V_81 , V_37 ) ;
if ( ! ( V_62 % V_61 ) )
F_24 ( V_57
L_39
L_22 ,
V_62 / V_61 * 10 ) ;
V_62 ++ ;
V_42 = F_81 ( V_59 ) ;
if ( V_42 <= 0 ) {
V_84 -> V_73 = V_71 + 1 ;
F_53 ( & V_84 -> V_70 , 1 ) ;
F_54 ( & V_84 -> V_69 ) ;
goto V_89;
}
}
}
V_84 -> V_73 = V_71 ;
F_53 ( & V_84 -> V_70 , 1 ) ;
F_54 ( & V_84 -> V_69 ) ;
}
V_89:
if ( V_84 -> V_73 ) {
F_50 ( V_84 -> V_72 , F_51 ( & V_84 -> V_64 ) ) ;
F_53 ( & V_84 -> V_64 , 0 ) ;
}
V_64 = F_45 () ;
if ( ! V_42 ) {
F_24 ( V_57 L_30 ) ;
F_82 ( V_59 ) ;
if ( ! F_83 ( V_59 ) )
V_42 = - V_107 ;
if ( ! V_42 ) {
if ( V_22 -> V_20 & V_28 ) {
if( V_19 -> V_29 != V_22 -> V_29 ) {
F_24 ( V_30
L_40 ) ;
V_42 = - V_107 ;
}
}
}
}
F_48 ( V_9 , V_64 , V_105 , L_31 ) ;
V_87:
for ( V_68 = 0 ; V_68 < V_112 ; V_68 ++ )
F_36 ( ( unsigned long ) V_83 [ V_68 ] ) ;
if ( V_84 ) {
if ( V_84 -> V_71 )
F_69 ( V_84 -> V_71 ) ;
F_19 ( V_84 ) ;
}
if ( V_65 ) {
for ( V_71 = 0 ; V_71 < V_82 ; V_71 ++ )
if ( V_65 [ V_71 ] . V_71 )
F_69 ( V_65 [ V_71 ] . V_71 ) ;
F_70 ( V_65 ) ;
}
F_70 ( V_83 ) ;
return V_42 ;
}
int F_88 ( unsigned int * V_103 )
{
int error ;
struct V_18 V_19 ;
struct V_58 V_59 ;
struct V_93 * V_94 ;
memset ( & V_59 , 0 , sizeof( struct V_58 ) ) ;
error = F_81 ( & V_59 ) ;
if ( error < V_37 )
return error < 0 ? error : - V_97 ;
V_94 = (struct V_93 * ) F_47 ( V_59 ) ;
error = F_77 ( & V_19 , V_103 ) ;
if ( error )
goto V_11;
if ( ! error )
error = F_78 ( & V_19 , V_94 , NULL ) ;
if ( ! error ) {
error = ( * V_103 & V_96 ) ?
F_80 ( & V_19 , & V_59 , V_94 -> V_95 - 1 ) :
F_86 ( & V_19 , & V_59 , V_94 -> V_95 - 1 ) ;
}
F_79 ( & V_19 ) ;
V_11:
if ( ! error )
F_73 ( L_41 ) ;
else
F_73 ( L_42 , error ) ;
return error ;
}
int F_89 ( void )
{
int error ;
V_34 = F_90 ( V_33 ,
V_121 , NULL ) ;
if ( ! F_66 ( V_34 ) ) {
F_28 ( V_34 , V_37 ) ;
F_41 ( V_22 ) ;
error = F_22 ( V_21 ,
V_22 , NULL ) ;
if ( error )
goto V_122;
if ( ! memcmp ( V_25 , V_22 -> V_23 , 10 ) ) {
memcpy ( V_22 -> V_23 , V_22 -> V_24 , 10 ) ;
error = F_23 ( V_21 ,
V_22 , NULL ) ;
} else {
error = - V_13 ;
}
V_122:
if ( error )
F_29 ( V_34 , V_121 ) ;
else
F_73 ( L_43 ) ;
} else {
error = F_91 ( V_34 ) ;
}
if ( error )
F_73 ( L_44 , error ) ;
return error ;
}
void F_39 ( T_4 V_123 )
{
if ( F_66 ( V_34 ) ) {
F_73 ( L_45 ) ;
return;
}
F_29 ( V_34 , V_123 ) ;
}
int F_92 ( void )
{
int error ;
F_22 ( V_21 , V_22 , NULL ) ;
if ( ! memcmp ( V_25 , V_22 -> V_23 , 10 ) ) {
memcpy ( V_22 -> V_23 , V_22 -> V_24 , 10 ) ;
error = F_23 ( V_21 ,
V_22 , NULL ) ;
} else {
F_24 ( V_30 L_46 ) ;
error = - V_31 ;
}
F_16 ( V_35 ) ;
return error ;
}
static int F_93 ( void )
{
V_22 = (struct V_22 * ) F_31 ( V_14 ) ;
if ( ! V_22 )
F_94 ( L_47 ) ;
return 0 ;
}
