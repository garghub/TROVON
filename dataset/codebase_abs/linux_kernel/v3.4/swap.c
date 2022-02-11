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
V_41 = ( void * ) F_30 ( V_44 | V_45 ) ;
if ( V_41 ) {
F_31 ( V_41 , V_38 ) ;
} else {
V_42 = F_32 ( V_40 ) ;
if ( V_42 )
return V_42 ;
V_41 = ( void * ) F_30 ( V_44 | V_45 ) ;
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
if ( V_19 -> V_46 )
F_35 ( ( unsigned long ) V_19 -> V_46 ) ;
V_19 -> V_46 = NULL ;
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
V_19 -> V_46 = (struct V_47 * ) F_37 ( V_14 ) ;
if ( ! V_19 -> V_46 ) {
V_42 = - V_15 ;
goto V_48;
}
V_19 -> V_49 = F_10 ( V_35 ) ;
if ( ! V_19 -> V_49 ) {
V_42 = - V_43 ;
goto V_50;
}
V_19 -> V_51 = 0 ;
V_19 -> F_4 = F_4 () ;
V_19 -> V_27 = V_19 -> V_49 ;
return 0 ;
V_50:
F_34 ( V_19 ) ;
V_48:
F_38 ( V_36 ) ;
return V_42 ;
}
static int F_39 ( struct V_18 * V_19 , void * V_38 ,
struct V_39 * * V_40 )
{
int error = 0 ;
T_1 V_17 ;
if ( ! V_19 -> V_46 )
return - V_13 ;
V_17 = F_10 ( V_35 ) ;
error = F_29 ( V_38 , V_17 , V_40 ) ;
if ( error )
return error ;
V_19 -> V_46 -> V_52 [ V_19 -> V_51 ++ ] = V_17 ;
if ( V_19 -> V_51 >= V_53 ) {
V_17 = F_10 ( V_35 ) ;
if ( ! V_17 )
return - V_43 ;
V_19 -> V_46 -> V_54 = V_17 ;
error = F_29 ( V_19 -> V_46 , V_19 -> V_49 , V_40 ) ;
if ( error )
goto V_55;
F_40 ( V_19 -> V_46 ) ;
V_19 -> V_49 = V_17 ;
V_19 -> V_51 = 0 ;
}
if ( V_40 && F_1 () <= V_19 -> F_4 ) {
error = F_32 ( V_40 ) ;
if ( error )
goto V_55;
V_19 -> F_4 = F_4 () ;
}
V_55:
return error ;
}
static int F_41 ( struct V_18 * V_19 )
{
if ( V_19 -> V_46 && V_19 -> V_49 )
return F_29 ( V_19 -> V_46 , V_19 -> V_49 , NULL ) ;
else
return - V_13 ;
}
static int F_42 ( struct V_18 * V_19 ,
unsigned int V_20 , int error )
{
if ( ! error ) {
F_41 ( V_19 ) ;
F_23 ( V_56 L_6 ) ;
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
struct V_57 * V_58 ,
unsigned int V_59 )
{
unsigned int V_60 ;
int V_42 ;
int V_61 ;
int V_62 ;
struct V_39 * V_39 ;
struct V_63 V_9 ;
struct V_63 V_64 ;
F_23 ( V_56 L_8 ,
V_59 ) ;
V_60 = V_59 / 100 ;
if ( ! V_60 )
V_60 = 1 ;
V_61 = 0 ;
V_39 = NULL ;
F_44 ( & V_9 ) ;
while ( 1 ) {
V_42 = F_45 ( V_58 ) ;
if ( V_42 <= 0 )
break;
V_42 = F_39 ( V_19 , F_46 ( * V_58 ) , & V_39 ) ;
if ( V_42 )
break;
if ( ! ( V_61 % V_60 ) )
F_23 ( V_65 L_9 , V_61 / V_60 ) ;
V_61 ++ ;
}
V_62 = F_32 ( & V_39 ) ;
F_44 ( & V_64 ) ;
if ( ! V_42 )
V_42 = V_62 ;
if ( ! V_42 )
F_23 ( V_65 L_10 ) ;
else
F_23 ( V_65 L_11 ) ;
F_47 ( & V_9 , & V_64 , V_59 , L_12 ) ;
return V_42 ;
}
static int F_48 ( void * V_66 )
{
struct V_67 * V_68 = V_66 ;
unsigned V_69 ;
while ( 1 ) {
F_49 ( V_68 -> V_70 , F_50 ( & V_68 -> V_71 ) ||
F_51 () ) ;
if ( F_51 () ) {
V_68 -> V_72 = NULL ;
F_52 ( & V_68 -> V_64 , 1 ) ;
F_53 ( & V_68 -> V_73 ) ;
break;
}
F_52 ( & V_68 -> V_71 , 0 ) ;
for ( V_69 = 0 ; V_69 < V_68 -> V_74 ; V_69 ++ )
* V_68 -> V_29 = F_54 ( * V_68 -> V_29 ,
V_68 -> V_75 [ V_69 ] , * V_68 -> V_76 [ V_69 ] ) ;
F_52 ( & V_68 -> V_64 , 1 ) ;
F_53 ( & V_68 -> V_73 ) ;
}
return 0 ;
}
static int F_55 ( void * V_66 )
{
struct V_77 * V_68 = V_66 ;
while ( 1 ) {
F_49 ( V_68 -> V_70 , F_50 ( & V_68 -> V_71 ) ||
F_51 () ) ;
if ( F_51 () ) {
V_68 -> V_72 = NULL ;
V_68 -> V_42 = - 1 ;
F_52 ( & V_68 -> V_64 , 1 ) ;
F_53 ( & V_68 -> V_73 ) ;
break;
}
F_52 ( & V_68 -> V_71 , 0 ) ;
V_68 -> V_42 = F_56 ( V_68 -> V_75 , V_68 -> V_76 ,
V_68 -> V_78 + V_79 , & V_68 -> V_80 ,
V_68 -> V_81 ) ;
F_52 ( & V_68 -> V_64 , 1 ) ;
F_53 ( & V_68 -> V_73 ) ;
}
return 0 ;
}
static int F_57 ( struct V_18 * V_19 ,
struct V_57 * V_58 ,
unsigned int V_59 )
{
unsigned int V_60 ;
int V_42 = 0 ;
int V_61 ;
int V_62 ;
struct V_39 * V_39 ;
struct V_63 V_9 ;
struct V_63 V_64 ;
T_2 V_82 ;
unsigned V_72 , V_74 , V_83 ;
unsigned char * V_84 = NULL ;
struct V_77 * V_66 = NULL ;
struct V_67 * V_85 = NULL ;
V_83 = F_58 () - 1 ;
V_83 = F_59 ( V_83 , 1 , V_86 ) ;
V_84 = ( void * ) F_30 ( V_44 | V_45 ) ;
if ( ! V_84 ) {
F_23 ( V_30 L_13 ) ;
V_42 = - V_15 ;
goto V_87;
}
V_66 = F_60 ( sizeof( * V_66 ) * V_83 ) ;
if ( ! V_66 ) {
F_23 ( V_30 L_14 ) ;
V_42 = - V_15 ;
goto V_87;
}
for ( V_72 = 0 ; V_72 < V_83 ; V_72 ++ )
memset ( & V_66 [ V_72 ] , 0 , F_61 ( struct V_77 , V_70 ) ) ;
V_85 = F_62 ( sizeof( * V_85 ) , V_14 ) ;
if ( ! V_85 ) {
F_23 ( V_30 L_15 ) ;
V_42 = - V_15 ;
goto V_87;
}
memset ( V_85 , 0 , F_61 ( struct V_67 , V_70 ) ) ;
for ( V_72 = 0 ; V_72 < V_83 ; V_72 ++ ) {
F_63 ( & V_66 [ V_72 ] . V_70 ) ;
F_63 ( & V_66 [ V_72 ] . V_73 ) ;
V_66 [ V_72 ] . V_72 = F_64 ( F_55 ,
& V_66 [ V_72 ] ,
L_16 , V_72 ) ;
if ( F_65 ( V_66 [ V_72 ] . V_72 ) ) {
V_66 [ V_72 ] . V_72 = NULL ;
F_23 ( V_30
L_17 ) ;
V_42 = - V_15 ;
goto V_87;
}
}
V_19 -> F_4 = F_4 () ;
F_63 ( & V_85 -> V_70 ) ;
F_63 ( & V_85 -> V_73 ) ;
V_19 -> V_29 = 0 ;
V_85 -> V_29 = & V_19 -> V_29 ;
for ( V_72 = 0 ; V_72 < V_83 ; V_72 ++ ) {
V_85 -> V_75 [ V_72 ] = V_66 [ V_72 ] . V_75 ;
V_85 -> V_76 [ V_72 ] = & V_66 [ V_72 ] . V_76 ;
}
V_85 -> V_72 = F_64 ( F_48 , V_85 , L_18 ) ;
if ( F_65 ( V_85 -> V_72 ) ) {
V_85 -> V_72 = NULL ;
F_23 ( V_30 L_19 ) ;
V_42 = - V_15 ;
goto V_87;
}
F_23 ( V_56
L_20
L_21 ,
V_83 , V_59 ) ;
V_60 = V_59 / 100 ;
if ( ! V_60 )
V_60 = 1 ;
V_61 = 0 ;
V_39 = NULL ;
F_44 ( & V_9 ) ;
for (; ; ) {
for ( V_72 = 0 ; V_72 < V_83 ; V_72 ++ ) {
for ( V_82 = 0 ; V_82 < V_88 ; V_82 += V_37 ) {
V_42 = F_45 ( V_58 ) ;
if ( V_42 < 0 )
goto V_89;
if ( ! V_42 )
break;
memcpy ( V_66 [ V_72 ] . V_75 + V_82 ,
F_46 ( * V_58 ) , V_37 ) ;
if ( ! ( V_61 % V_60 ) )
F_23 ( V_65 L_9 ,
V_61 / V_60 ) ;
V_61 ++ ;
}
if ( ! V_82 )
break;
V_66 [ V_72 ] . V_76 = V_82 ;
F_52 ( & V_66 [ V_72 ] . V_71 , 1 ) ;
F_53 ( & V_66 [ V_72 ] . V_70 ) ;
}
if ( ! V_72 )
break;
V_85 -> V_74 = V_72 ;
F_52 ( & V_85 -> V_71 , 1 ) ;
F_53 ( & V_85 -> V_70 ) ;
for ( V_74 = V_72 , V_72 = 0 ; V_72 < V_74 ; V_72 ++ ) {
F_49 ( V_66 [ V_72 ] . V_73 ,
F_50 ( & V_66 [ V_72 ] . V_64 ) ) ;
F_52 ( & V_66 [ V_72 ] . V_64 , 0 ) ;
V_42 = V_66 [ V_72 ] . V_42 ;
if ( V_42 < 0 ) {
F_23 ( V_30 L_22 ) ;
goto V_89;
}
if ( F_66 ( ! V_66 [ V_72 ] . V_80 ||
V_66 [ V_72 ] . V_80 >
F_67 ( V_66 [ V_72 ] . V_76 ) ) ) {
F_23 ( V_30
L_23 ) ;
V_42 = - 1 ;
goto V_89;
}
* ( T_2 * ) V_66 [ V_72 ] . V_78 = V_66 [ V_72 ] . V_80 ;
for ( V_82 = 0 ;
V_82 < V_79 + V_66 [ V_72 ] . V_80 ;
V_82 += V_37 ) {
memcpy ( V_84 , V_66 [ V_72 ] . V_78 + V_82 , V_37 ) ;
V_42 = F_39 ( V_19 , V_84 , & V_39 ) ;
if ( V_42 )
goto V_89;
}
}
F_49 ( V_85 -> V_73 , F_50 ( & V_85 -> V_64 ) ) ;
F_52 ( & V_85 -> V_64 , 0 ) ;
}
V_89:
V_62 = F_32 ( & V_39 ) ;
F_44 ( & V_64 ) ;
if ( ! V_42 )
V_42 = V_62 ;
if ( ! V_42 ) {
F_23 ( V_65 L_10 ) ;
} else {
F_23 ( V_65 L_11 ) ;
}
F_47 ( & V_9 , & V_64 , V_59 , L_12 ) ;
V_87:
if ( V_85 ) {
if ( V_85 -> V_72 )
F_68 ( V_85 -> V_72 ) ;
F_18 ( V_85 ) ;
}
if ( V_66 ) {
for ( V_72 = 0 ; V_72 < V_83 ; V_72 ++ )
if ( V_66 [ V_72 ] . V_72 )
F_68 ( V_66 [ V_72 ] . V_72 ) ;
F_69 ( V_66 ) ;
}
if ( V_84 ) F_35 ( ( unsigned long ) V_84 ) ;
return V_42 ;
}
static int F_70 ( unsigned int V_61 , unsigned int V_20 )
{
unsigned int V_90 = F_71 ( V_35 , 1 ) ;
unsigned int V_91 ;
F_72 ( L_24 , V_90 ) ;
V_91 = V_92 + V_61 ;
return V_90 > V_91 ;
}
int F_73 ( unsigned int V_20 )
{
struct V_18 V_19 ;
struct V_57 V_58 ;
struct V_93 * V_94 ;
unsigned long V_95 ;
int error ;
V_95 = F_74 () ;
error = F_36 ( & V_19 ) ;
if ( error ) {
F_23 ( V_30 L_25 ) ;
return error ;
}
if ( V_20 & V_96 ) {
if ( ! F_70 ( V_95 , V_20 ) ) {
F_23 ( V_30 L_26 ) ;
error = - V_43 ;
goto V_89;
}
}
memset ( & V_58 , 0 , sizeof( struct V_57 ) ) ;
error = F_45 ( & V_58 ) ;
if ( error < V_37 ) {
if ( error >= 0 )
error = - V_97 ;
goto V_89;
}
V_94 = (struct V_93 * ) F_46 ( V_58 ) ;
error = F_39 ( & V_19 , V_94 , NULL ) ;
if ( ! error ) {
error = ( V_20 & V_96 ) ?
F_43 ( & V_19 , & V_58 , V_95 - 1 ) :
F_57 ( & V_19 , & V_58 , V_95 - 1 ) ;
}
V_89:
error = F_42 ( & V_19 , V_20 , error ) ;
return error ;
}
static void F_75 ( struct V_18 * V_19 )
{
struct V_98 * V_99 ;
while ( V_19 -> V_100 ) {
if ( V_19 -> V_100 -> V_101 )
F_35 ( ( unsigned long ) V_19 -> V_100 -> V_101 ) ;
V_99 = V_19 -> V_100 ;
V_19 -> V_100 = V_19 -> V_100 -> V_102 ;
F_18 ( V_99 ) ;
}
V_19 -> V_46 = NULL ;
}
static int F_76 ( struct V_18 * V_19 ,
unsigned int * V_103 )
{
int error ;
struct V_98 * V_99 , * V_104 ;
T_1 V_17 ;
* V_103 = V_22 -> V_20 ;
if ( ! V_22 -> V_26 )
return - V_13 ;
V_19 -> V_46 = NULL ;
V_104 = V_19 -> V_100 = NULL ;
V_17 = V_22 -> V_26 ;
while ( V_17 ) {
V_99 = F_62 ( sizeof( * V_19 -> V_100 ) , V_14 ) ;
if ( ! V_99 ) {
F_75 ( V_19 ) ;
return - V_15 ;
}
memset ( V_99 , 0 , sizeof( * V_99 ) ) ;
if ( ! V_19 -> V_100 )
V_19 -> V_100 = V_99 ;
if ( V_104 )
V_104 -> V_102 = V_99 ;
V_104 = V_99 ;
V_99 -> V_101 = (struct V_47 * )
F_30 ( V_44 | V_45 ) ;
if ( ! V_99 -> V_101 ) {
F_75 ( V_19 ) ;
return - V_15 ;
}
error = F_21 ( V_17 , V_99 -> V_101 , NULL ) ;
if ( error ) {
F_75 ( V_19 ) ;
return error ;
}
V_17 = V_99 -> V_101 -> V_54 ;
}
V_19 -> V_51 = 0 ;
V_19 -> V_46 = V_19 -> V_100 -> V_101 ;
return 0 ;
}
static int F_77 ( struct V_18 * V_19 , void * V_38 ,
struct V_39 * * V_40 )
{
T_1 V_17 ;
int error ;
struct V_98 * V_99 ;
if ( ! V_19 -> V_46 )
return - V_13 ;
V_17 = V_19 -> V_46 -> V_52 [ V_19 -> V_51 ] ;
if ( ! V_17 )
return - V_97 ;
error = F_21 ( V_17 , V_38 , V_40 ) ;
if ( error )
return error ;
if ( ++ V_19 -> V_51 >= V_53 ) {
V_19 -> V_51 = 0 ;
F_35 ( ( unsigned long ) V_19 -> V_100 -> V_101 ) ;
V_99 = V_19 -> V_100 ;
V_19 -> V_100 = V_19 -> V_100 -> V_102 ;
F_18 ( V_99 ) ;
if ( ! V_19 -> V_100 )
F_75 ( V_19 ) ;
else
V_19 -> V_46 = V_19 -> V_100 -> V_101 ;
}
return error ;
}
static int F_78 ( struct V_18 * V_19 )
{
F_75 ( V_19 ) ;
return 0 ;
}
static int F_79 ( struct V_18 * V_19 ,
struct V_57 * V_58 ,
unsigned int V_105 )
{
unsigned int V_60 ;
int V_42 = 0 ;
struct V_63 V_9 ;
struct V_63 V_64 ;
struct V_39 * V_39 ;
int V_62 ;
unsigned V_61 ;
F_23 ( V_56 L_27 ,
V_105 ) ;
V_60 = V_105 / 100 ;
if ( ! V_60 )
V_60 = 1 ;
V_61 = 0 ;
V_39 = NULL ;
F_44 ( & V_9 ) ;
for ( ; ; ) {
V_42 = F_80 ( V_58 ) ;
if ( V_42 <= 0 )
break;
V_42 = F_77 ( V_19 , F_46 ( * V_58 ) , & V_39 ) ;
if ( V_42 )
break;
if ( V_58 -> V_106 )
V_42 = F_32 ( & V_39 ) ;
if ( V_42 )
break;
if ( ! ( V_61 % V_60 ) )
F_23 ( L_9 , V_61 / V_60 ) ;
V_61 ++ ;
}
V_62 = F_32 ( & V_39 ) ;
F_44 ( & V_64 ) ;
if ( ! V_42 )
V_42 = V_62 ;
if ( ! V_42 ) {
F_23 ( L_10 ) ;
F_81 ( V_58 ) ;
if ( ! F_82 ( V_58 ) )
V_42 = - V_107 ;
} else
F_23 ( L_11 ) ;
F_47 ( & V_9 , & V_64 , V_105 , L_28 ) ;
return V_42 ;
}
static int F_83 ( void * V_66 )
{
struct V_108 * V_68 = V_66 ;
while ( 1 ) {
F_49 ( V_68 -> V_70 , F_50 ( & V_68 -> V_71 ) ||
F_51 () ) ;
if ( F_51 () ) {
V_68 -> V_72 = NULL ;
V_68 -> V_42 = - 1 ;
F_52 ( & V_68 -> V_64 , 1 ) ;
F_53 ( & V_68 -> V_73 ) ;
break;
}
F_52 ( & V_68 -> V_71 , 0 ) ;
V_68 -> V_76 = V_88 ;
V_68 -> V_42 = F_84 ( V_68 -> V_78 + V_79 , V_68 -> V_80 ,
V_68 -> V_75 , & V_68 -> V_76 ) ;
F_52 ( & V_68 -> V_64 , 1 ) ;
F_53 ( & V_68 -> V_73 ) ;
}
return 0 ;
}
static int F_85 ( struct V_18 * V_19 ,
struct V_57 * V_58 ,
unsigned int V_105 )
{
unsigned int V_60 ;
int V_42 = 0 ;
int V_109 = 0 ;
struct V_39 * V_39 ;
struct V_63 V_9 ;
struct V_63 V_64 ;
unsigned V_61 ;
T_2 V_82 ;
unsigned V_69 , V_72 , V_74 , V_83 ;
unsigned V_110 = 0 , V_111 = 0 , V_112 = 0 ,
V_113 = 0 , V_114 , V_115 , V_116 = 0 ;
unsigned long V_117 ;
unsigned char * * V_84 = NULL ;
struct V_108 * V_66 = NULL ;
struct V_67 * V_85 = NULL ;
V_83 = F_58 () - 1 ;
V_83 = F_59 ( V_83 , 1 , V_86 ) ;
V_84 = F_60 ( sizeof( * V_84 ) * V_118 ) ;
if ( ! V_84 ) {
F_23 ( V_30 L_13 ) ;
V_42 = - V_15 ;
goto V_87;
}
V_66 = F_60 ( sizeof( * V_66 ) * V_83 ) ;
if ( ! V_66 ) {
F_23 ( V_30 L_14 ) ;
V_42 = - V_15 ;
goto V_87;
}
for ( V_72 = 0 ; V_72 < V_83 ; V_72 ++ )
memset ( & V_66 [ V_72 ] , 0 , F_61 ( struct V_108 , V_70 ) ) ;
V_85 = F_62 ( sizeof( * V_85 ) , V_14 ) ;
if ( ! V_85 ) {
F_23 ( V_30 L_15 ) ;
V_42 = - V_15 ;
goto V_87;
}
memset ( V_85 , 0 , F_61 ( struct V_67 , V_70 ) ) ;
for ( V_72 = 0 ; V_72 < V_83 ; V_72 ++ ) {
F_63 ( & V_66 [ V_72 ] . V_70 ) ;
F_63 ( & V_66 [ V_72 ] . V_73 ) ;
V_66 [ V_72 ] . V_72 = F_64 ( F_83 ,
& V_66 [ V_72 ] ,
L_29 , V_72 ) ;
if ( F_65 ( V_66 [ V_72 ] . V_72 ) ) {
V_66 [ V_72 ] . V_72 = NULL ;
F_23 ( V_30
L_30 ) ;
V_42 = - V_15 ;
goto V_87;
}
}
F_63 ( & V_85 -> V_70 ) ;
F_63 ( & V_85 -> V_73 ) ;
V_19 -> V_29 = 0 ;
V_85 -> V_29 = & V_19 -> V_29 ;
for ( V_72 = 0 ; V_72 < V_83 ; V_72 ++ ) {
V_85 -> V_75 [ V_72 ] = V_66 [ V_72 ] . V_75 ;
V_85 -> V_76 [ V_72 ] = & V_66 [ V_72 ] . V_76 ;
}
V_85 -> V_72 = F_64 ( F_48 , V_85 , L_18 ) ;
if ( F_65 ( V_85 -> V_72 ) ) {
V_85 -> V_72 = NULL ;
F_23 ( V_30 L_19 ) ;
V_42 = - V_15 ;
goto V_87;
}
V_117 = ( F_2 () - F_74 () ) >> 1 ;
V_117 = F_59 ( V_117 , V_119 , V_118 ) ;
for ( V_69 = 0 ; V_69 < V_117 ; V_69 ++ ) {
V_84 [ V_69 ] = ( void * ) F_30 ( V_69 < V_119 ?
V_44 | V_45 :
V_44 ) ;
if ( ! V_84 [ V_69 ] ) {
if ( V_69 < V_119 ) {
V_112 = V_69 ;
F_23 ( V_30
L_31 ) ;
V_42 = - V_15 ;
goto V_87;
} else {
break;
}
}
}
V_114 = V_112 = V_69 ;
F_23 ( V_56
L_32
L_33 ,
V_83 , V_105 ) ;
V_60 = V_105 / 100 ;
if ( ! V_60 )
V_60 = 1 ;
V_61 = 0 ;
V_39 = NULL ;
F_44 ( & V_9 ) ;
V_42 = F_80 ( V_58 ) ;
if ( V_42 <= 0 )
goto V_89;
for(; ; ) {
for ( V_69 = 0 ; ! V_109 && V_69 < V_114 ; V_69 ++ ) {
V_42 = F_77 ( V_19 , V_84 [ V_110 ] , & V_39 ) ;
if ( V_42 ) {
if ( V_19 -> V_46 &&
V_19 -> V_46 -> V_52 [ V_19 -> V_51 ] ) {
goto V_89;
} else {
V_109 = 1 ;
break;
}
}
if ( ++ V_110 >= V_112 )
V_110 = 0 ;
}
V_116 += V_69 ;
V_114 -= V_69 ;
if ( ! V_113 ) {
if ( ! V_116 )
break;
V_42 = F_32 ( & V_39 ) ;
if ( V_42 )
goto V_89;
V_113 += V_116 ;
V_116 = 0 ;
if ( V_109 )
V_109 = 2 ;
}
if ( V_85 -> V_74 ) {
F_49 ( V_85 -> V_73 , F_50 ( & V_85 -> V_64 ) ) ;
F_52 ( & V_85 -> V_64 , 0 ) ;
V_85 -> V_74 = 0 ;
}
for ( V_72 = 0 ; V_113 && V_72 < V_83 ; V_72 ++ ) {
V_66 [ V_72 ] . V_80 = * ( T_2 * ) V_84 [ V_111 ] ;
if ( F_66 ( ! V_66 [ V_72 ] . V_80 ||
V_66 [ V_72 ] . V_80 >
F_67 ( V_88 ) ) ) {
F_23 ( V_30
L_23 ) ;
V_42 = - 1 ;
goto V_89;
}
V_115 = F_86 ( V_66 [ V_72 ] . V_80 + V_79 ,
V_37 ) ;
if ( V_115 > V_113 ) {
if ( V_109 > 1 ) {
V_42 = - 1 ;
goto V_89;
}
break;
}
for ( V_82 = 0 ;
V_82 < V_79 + V_66 [ V_72 ] . V_80 ;
V_82 += V_37 ) {
memcpy ( V_66 [ V_72 ] . V_78 + V_82 ,
V_84 [ V_111 ] , V_37 ) ;
V_113 -- ;
V_114 ++ ;
if ( ++ V_111 >= V_112 )
V_111 = 0 ;
}
F_52 ( & V_66 [ V_72 ] . V_71 , 1 ) ;
F_53 ( & V_66 [ V_72 ] . V_70 ) ;
}
if ( V_113 < V_119 && V_116 ) {
V_42 = F_32 ( & V_39 ) ;
if ( V_42 )
goto V_89;
V_113 += V_116 ;
V_116 = 0 ;
if ( V_109 )
V_109 = 2 ;
}
for ( V_74 = V_72 , V_72 = 0 ; V_72 < V_74 ; V_72 ++ ) {
F_49 ( V_66 [ V_72 ] . V_73 ,
F_50 ( & V_66 [ V_72 ] . V_64 ) ) ;
F_52 ( & V_66 [ V_72 ] . V_64 , 0 ) ;
V_42 = V_66 [ V_72 ] . V_42 ;
if ( V_42 < 0 ) {
F_23 ( V_30
L_34 ) ;
goto V_89;
}
if ( F_66 ( ! V_66 [ V_72 ] . V_76 ||
V_66 [ V_72 ] . V_76 > V_88 ||
V_66 [ V_72 ] . V_76 & ( V_37 - 1 ) ) ) {
F_23 ( V_30
L_35 ) ;
V_42 = - 1 ;
goto V_89;
}
for ( V_82 = 0 ;
V_82 < V_66 [ V_72 ] . V_76 ; V_82 += V_37 ) {
memcpy ( F_46 ( * V_58 ) ,
V_66 [ V_72 ] . V_75 + V_82 , V_37 ) ;
if ( ! ( V_61 % V_60 ) )
F_23 ( L_9 , V_61 / V_60 ) ;
V_61 ++ ;
V_42 = F_80 ( V_58 ) ;
if ( V_42 <= 0 ) {
V_85 -> V_74 = V_72 + 1 ;
F_52 ( & V_85 -> V_71 , 1 ) ;
F_53 ( & V_85 -> V_70 ) ;
goto V_89;
}
}
}
V_85 -> V_74 = V_72 ;
F_52 ( & V_85 -> V_71 , 1 ) ;
F_53 ( & V_85 -> V_70 ) ;
}
V_89:
if ( V_85 -> V_74 ) {
F_49 ( V_85 -> V_73 , F_50 ( & V_85 -> V_64 ) ) ;
F_52 ( & V_85 -> V_64 , 0 ) ;
}
F_44 ( & V_64 ) ;
if ( ! V_42 ) {
F_23 ( L_10 ) ;
F_81 ( V_58 ) ;
if ( ! F_82 ( V_58 ) )
V_42 = - V_107 ;
if ( ! V_42 ) {
if ( V_22 -> V_20 & V_28 ) {
if( V_19 -> V_29 != V_22 -> V_29 ) {
F_23 ( V_30
L_36 ) ;
V_42 = - V_107 ;
}
}
}
} else
F_23 ( L_11 ) ;
F_47 ( & V_9 , & V_64 , V_105 , L_28 ) ;
V_87:
for ( V_69 = 0 ; V_69 < V_112 ; V_69 ++ )
F_35 ( ( unsigned long ) V_84 [ V_69 ] ) ;
if ( V_85 ) {
if ( V_85 -> V_72 )
F_68 ( V_85 -> V_72 ) ;
F_18 ( V_85 ) ;
}
if ( V_66 ) {
for ( V_72 = 0 ; V_72 < V_83 ; V_72 ++ )
if ( V_66 [ V_72 ] . V_72 )
F_68 ( V_66 [ V_72 ] . V_72 ) ;
F_69 ( V_66 ) ;
}
if ( V_84 ) F_69 ( V_84 ) ;
return V_42 ;
}
int F_87 ( unsigned int * V_103 )
{
int error ;
struct V_18 V_19 ;
struct V_57 V_58 ;
struct V_93 * V_94 ;
memset ( & V_58 , 0 , sizeof( struct V_57 ) ) ;
error = F_80 ( & V_58 ) ;
if ( error < V_37 )
return error < 0 ? error : - V_97 ;
V_94 = (struct V_93 * ) F_46 ( V_58 ) ;
error = F_76 ( & V_19 , V_103 ) ;
if ( error )
goto V_11;
if ( ! error )
error = F_77 ( & V_19 , V_94 , NULL ) ;
if ( ! error ) {
error = ( * V_103 & V_96 ) ?
F_79 ( & V_19 , & V_58 , V_94 -> V_95 - 1 ) :
F_85 ( & V_19 , & V_58 , V_94 -> V_95 - 1 ) ;
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
V_120 , NULL ) ;
if ( ! F_65 ( V_34 ) ) {
F_27 ( V_34 , V_37 ) ;
F_40 ( V_22 ) ;
error = F_21 ( V_21 ,
V_22 , NULL ) ;
if ( error )
goto V_121;
if ( ! memcmp ( V_25 , V_22 -> V_23 , 10 ) ) {
memcpy ( V_22 -> V_23 , V_22 -> V_24 , 10 ) ;
error = F_22 ( V_21 ,
V_22 , NULL ) ;
} else {
error = - V_13 ;
}
V_121:
if ( error )
F_28 ( V_34 , V_120 ) ;
else
F_72 ( L_39 ) ;
} else {
error = F_90 ( V_34 ) ;
}
if ( error )
F_72 ( L_40 , error ) ;
return error ;
}
void F_38 ( T_3 V_122 )
{
if ( F_65 ( V_34 ) ) {
F_72 ( L_41 ) ;
return;
}
F_28 ( V_34 , V_122 ) ;
}
static int F_91 ( void )
{
V_22 = (struct V_22 * ) F_30 ( V_14 ) ;
if ( ! V_22 )
F_92 ( L_42 ) ;
return 0 ;
}
