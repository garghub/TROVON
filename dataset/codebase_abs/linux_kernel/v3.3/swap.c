static int F_1 ( unsigned long V_1 )
{
struct V_2 * * V_3 = & ( V_4 . V_2 ) ;
struct V_2 * V_5 = NULL ;
struct V_6 * V_7 ;
while ( * V_3 ) {
V_7 = F_2 ( * V_3 , struct V_6 , V_8 ) ;
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
V_7 = F_3 ( sizeof( struct V_6 ) , V_14 ) ;
if ( ! V_7 )
return - V_15 ;
V_7 -> V_9 = V_1 ;
V_7 -> V_11 = V_1 ;
F_4 ( & V_7 -> V_8 , V_5 , V_3 ) ;
F_5 ( & V_7 -> V_8 , & V_4 ) ;
return 0 ;
}
T_1 F_6 ( int V_16 )
{
unsigned long V_17 ;
V_17 = F_7 ( F_8 ( V_16 ) ) ;
if ( V_17 ) {
if ( F_1 ( V_17 ) )
F_9 ( F_10 ( V_16 , V_17 ) ) ;
else
return F_11 ( V_16 , V_17 ) ;
}
return 0 ;
}
void F_12 ( int V_16 )
{
struct V_2 * V_8 ;
while ( ( V_8 = V_4 . V_2 ) ) {
struct V_6 * V_7 ;
unsigned long V_17 ;
V_7 = F_2 ( V_8 , struct V_6 , V_8 ) ;
F_13 ( V_8 , & V_4 ) ;
for ( V_17 = V_7 -> V_9 ; V_17 <= V_7 -> V_11 ; V_17 ++ )
F_9 ( F_10 ( V_16 , V_17 ) ) ;
F_14 ( V_7 ) ;
}
}
int F_15 ( void )
{
return ( V_4 . V_2 != NULL ) ;
}
static int F_16 ( struct V_18 * V_19 , unsigned int V_20 )
{
int error ;
F_17 ( V_21 , V_22 , NULL ) ;
if ( ! memcmp ( L_1 , V_22 -> V_23 , 10 ) ||
! memcmp ( L_2 , V_22 -> V_23 , 10 ) ) {
memcpy ( V_22 -> V_24 , V_22 -> V_23 , 10 ) ;
memcpy ( V_22 -> V_23 , V_25 , 10 ) ;
V_22 -> V_26 = V_19 -> V_27 ;
V_22 -> V_20 = V_20 ;
if ( V_20 & V_28 )
V_22 -> V_29 = V_19 -> V_29 ;
error = F_18 ( V_21 ,
V_22 , NULL ) ;
} else {
F_19 ( V_30 L_3 ) ;
error = - V_31 ;
}
return error ;
}
static int F_20 ( void )
{
int V_32 ;
V_32 = F_21 ( V_33 , V_21 ,
& V_34 ) ;
if ( V_32 < 0 )
return V_32 ;
V_35 = V_32 ;
V_32 = F_22 ( V_34 , V_36 , NULL ) ;
if ( V_32 )
return V_32 ;
V_32 = F_23 ( V_34 , V_37 ) ;
if ( V_32 < 0 )
F_24 ( V_34 , V_36 ) ;
return V_32 ;
}
static int F_25 ( void * V_38 , T_1 V_17 , struct V_39 * * V_40 )
{
void * V_41 ;
int V_42 ;
if ( ! V_17 )
return - V_43 ;
if ( V_40 ) {
V_41 = ( void * ) F_26 ( V_44 | V_45 ) ;
if ( V_41 ) {
F_27 ( V_41 , V_38 ) ;
} else {
V_42 = F_28 ( V_40 ) ;
if ( V_42 )
return V_42 ;
V_41 = ( void * ) F_26 ( V_44 | V_45 ) ;
if ( V_41 ) {
F_27 ( V_41 , V_38 ) ;
} else {
F_29 ( 1 ) ;
V_40 = NULL ;
V_41 = V_38 ;
}
}
} else {
V_41 = V_38 ;
}
return F_18 ( V_17 , V_41 , V_40 ) ;
}
static void F_30 ( struct V_18 * V_19 )
{
if ( V_19 -> V_46 )
F_31 ( ( unsigned long ) V_19 -> V_46 ) ;
V_19 -> V_46 = NULL ;
}
static int F_32 ( struct V_18 * V_19 )
{
int V_42 ;
V_42 = F_20 () ;
if ( V_42 ) {
if ( V_42 != - V_43 )
F_19 ( V_30 L_4
L_5 ) ;
return V_42 ;
}
V_19 -> V_46 = (struct V_47 * ) F_33 ( V_14 ) ;
if ( ! V_19 -> V_46 ) {
V_42 = - V_15 ;
goto V_48;
}
V_19 -> V_49 = F_6 ( V_35 ) ;
if ( ! V_19 -> V_49 ) {
V_42 = - V_43 ;
goto V_50;
}
V_19 -> V_51 = 0 ;
V_19 -> V_52 = V_52 () >> 1 ;
V_19 -> V_53 = 0 ;
V_19 -> V_27 = V_19 -> V_49 ;
return 0 ;
V_50:
F_30 ( V_19 ) ;
V_48:
F_34 ( V_36 ) ;
return V_42 ;
}
static int F_35 ( struct V_18 * V_19 , void * V_38 ,
struct V_39 * * V_40 )
{
int error = 0 ;
T_1 V_17 ;
if ( ! V_19 -> V_46 )
return - V_13 ;
V_17 = F_6 ( V_35 ) ;
error = F_25 ( V_38 , V_17 , V_40 ) ;
if ( error )
return error ;
V_19 -> V_46 -> V_54 [ V_19 -> V_51 ++ ] = V_17 ;
if ( V_19 -> V_51 >= V_55 ) {
V_17 = F_6 ( V_35 ) ;
if ( ! V_17 )
return - V_43 ;
V_19 -> V_46 -> V_56 = V_17 ;
error = F_25 ( V_19 -> V_46 , V_19 -> V_49 , V_40 ) ;
if ( error )
goto V_57;
F_36 ( V_19 -> V_46 ) ;
V_19 -> V_49 = V_17 ;
V_19 -> V_51 = 0 ;
}
if ( V_40 && ++ V_19 -> V_53 > V_19 -> V_52 ) {
error = F_28 ( V_40 ) ;
if ( error )
goto V_57;
V_19 -> V_53 = 0 ;
}
V_57:
return error ;
}
static int F_37 ( struct V_18 * V_19 )
{
if ( V_19 -> V_46 && V_19 -> V_49 )
return F_25 ( V_19 -> V_46 , V_19 -> V_49 , NULL ) ;
else
return - V_13 ;
}
static int F_38 ( struct V_18 * V_19 ,
unsigned int V_20 , int error )
{
if ( ! error ) {
F_37 ( V_19 ) ;
F_19 ( V_58 L_6 ) ;
error = F_16 ( V_19 , V_20 ) ;
F_19 ( L_7 ) ;
}
if ( error )
F_12 ( V_35 ) ;
F_30 ( V_19 ) ;
F_34 ( V_36 ) ;
return error ;
}
static int F_39 ( struct V_18 * V_19 ,
struct V_59 * V_60 ,
unsigned int V_61 )
{
unsigned int V_62 ;
int V_42 ;
int V_63 ;
int V_64 ;
struct V_39 * V_39 ;
struct V_65 V_9 ;
struct V_65 V_66 ;
F_19 ( V_58 L_8 ,
V_61 ) ;
V_62 = V_61 / 100 ;
if ( ! V_62 )
V_62 = 1 ;
V_63 = 0 ;
V_39 = NULL ;
F_40 ( & V_9 ) ;
while ( 1 ) {
V_42 = F_41 ( V_60 ) ;
if ( V_42 <= 0 )
break;
V_42 = F_35 ( V_19 , F_42 ( * V_60 ) , & V_39 ) ;
if ( V_42 )
break;
if ( ! ( V_63 % V_62 ) )
F_19 ( V_67 L_9 , V_63 / V_62 ) ;
V_63 ++ ;
}
V_64 = F_28 ( & V_39 ) ;
F_40 ( & V_66 ) ;
if ( ! V_42 )
V_42 = V_64 ;
if ( ! V_42 )
F_19 ( V_67 L_10 ) ;
else
F_19 ( V_67 L_11 ) ;
F_43 ( & V_9 , & V_66 , V_61 , L_12 ) ;
return V_42 ;
}
static int F_44 ( void * V_68 )
{
struct V_69 * V_70 = V_68 ;
unsigned V_71 ;
while ( 1 ) {
F_45 ( V_70 -> V_72 , F_46 ( & V_70 -> V_73 ) ||
F_47 () ) ;
if ( F_47 () ) {
V_70 -> V_74 = NULL ;
F_48 ( & V_70 -> V_66 , 1 ) ;
F_49 ( & V_70 -> V_75 ) ;
break;
}
F_48 ( & V_70 -> V_73 , 0 ) ;
for ( V_71 = 0 ; V_71 < V_70 -> V_76 ; V_71 ++ )
* V_70 -> V_29 = F_50 ( * V_70 -> V_29 ,
V_70 -> V_77 [ V_71 ] , * V_70 -> V_78 [ V_71 ] ) ;
F_48 ( & V_70 -> V_66 , 1 ) ;
F_49 ( & V_70 -> V_75 ) ;
}
return 0 ;
}
static int F_51 ( void * V_68 )
{
struct V_79 * V_70 = V_68 ;
while ( 1 ) {
F_45 ( V_70 -> V_72 , F_46 ( & V_70 -> V_73 ) ||
F_47 () ) ;
if ( F_47 () ) {
V_70 -> V_74 = NULL ;
V_70 -> V_42 = - 1 ;
F_48 ( & V_70 -> V_66 , 1 ) ;
F_49 ( & V_70 -> V_75 ) ;
break;
}
F_48 ( & V_70 -> V_73 , 0 ) ;
V_70 -> V_42 = F_52 ( V_70 -> V_77 , V_70 -> V_78 ,
V_70 -> V_80 + V_81 , & V_70 -> V_82 ,
V_70 -> V_83 ) ;
F_48 ( & V_70 -> V_66 , 1 ) ;
F_49 ( & V_70 -> V_75 ) ;
}
return 0 ;
}
static int F_53 ( struct V_18 * V_19 ,
struct V_59 * V_60 ,
unsigned int V_61 )
{
unsigned int V_62 ;
int V_42 = 0 ;
int V_63 ;
int V_64 ;
struct V_39 * V_39 ;
struct V_65 V_9 ;
struct V_65 V_66 ;
T_2 V_84 ;
unsigned V_74 , V_76 , V_85 ;
unsigned char * V_86 = NULL ;
struct V_79 * V_68 = NULL ;
struct V_69 * V_87 = NULL ;
V_85 = F_54 () - 1 ;
V_85 = F_55 ( V_85 , 1 , V_88 ) ;
V_86 = ( void * ) F_26 ( V_44 | V_45 ) ;
if ( ! V_86 ) {
F_19 ( V_30 L_13 ) ;
V_42 = - V_15 ;
goto V_89;
}
V_68 = F_56 ( sizeof( * V_68 ) * V_85 ) ;
if ( ! V_68 ) {
F_19 ( V_30 L_14 ) ;
V_42 = - V_15 ;
goto V_89;
}
for ( V_74 = 0 ; V_74 < V_85 ; V_74 ++ )
memset ( & V_68 [ V_74 ] , 0 , F_57 ( struct V_79 , V_72 ) ) ;
V_87 = F_58 ( sizeof( * V_87 ) , V_14 ) ;
if ( ! V_87 ) {
F_19 ( V_30 L_15 ) ;
V_42 = - V_15 ;
goto V_89;
}
memset ( V_87 , 0 , F_57 ( struct V_69 , V_72 ) ) ;
for ( V_74 = 0 ; V_74 < V_85 ; V_74 ++ ) {
F_59 ( & V_68 [ V_74 ] . V_72 ) ;
F_59 ( & V_68 [ V_74 ] . V_75 ) ;
V_68 [ V_74 ] . V_74 = F_60 ( F_51 ,
& V_68 [ V_74 ] ,
L_16 , V_74 ) ;
if ( F_61 ( V_68 [ V_74 ] . V_74 ) ) {
V_68 [ V_74 ] . V_74 = NULL ;
F_19 ( V_30
L_17 ) ;
V_42 = - V_15 ;
goto V_89;
}
}
V_19 -> V_52 = V_52 () >> 1 ;
F_59 ( & V_87 -> V_72 ) ;
F_59 ( & V_87 -> V_75 ) ;
V_19 -> V_29 = 0 ;
V_87 -> V_29 = & V_19 -> V_29 ;
for ( V_74 = 0 ; V_74 < V_85 ; V_74 ++ ) {
V_87 -> V_77 [ V_74 ] = V_68 [ V_74 ] . V_77 ;
V_87 -> V_78 [ V_74 ] = & V_68 [ V_74 ] . V_78 ;
}
V_87 -> V_74 = F_60 ( F_44 , V_87 , L_18 ) ;
if ( F_61 ( V_87 -> V_74 ) ) {
V_87 -> V_74 = NULL ;
F_19 ( V_30 L_19 ) ;
V_42 = - V_15 ;
goto V_89;
}
F_19 ( V_58
L_20
L_21 ,
V_85 , V_61 ) ;
V_62 = V_61 / 100 ;
if ( ! V_62 )
V_62 = 1 ;
V_63 = 0 ;
V_39 = NULL ;
F_40 ( & V_9 ) ;
for (; ; ) {
for ( V_74 = 0 ; V_74 < V_85 ; V_74 ++ ) {
for ( V_84 = 0 ; V_84 < V_90 ; V_84 += V_37 ) {
V_42 = F_41 ( V_60 ) ;
if ( V_42 < 0 )
goto V_91;
if ( ! V_42 )
break;
memcpy ( V_68 [ V_74 ] . V_77 + V_84 ,
F_42 ( * V_60 ) , V_37 ) ;
if ( ! ( V_63 % V_62 ) )
F_19 ( V_67 L_9 ,
V_63 / V_62 ) ;
V_63 ++ ;
}
if ( ! V_84 )
break;
V_68 [ V_74 ] . V_78 = V_84 ;
F_48 ( & V_68 [ V_74 ] . V_73 , 1 ) ;
F_49 ( & V_68 [ V_74 ] . V_72 ) ;
}
if ( ! V_74 )
break;
V_87 -> V_76 = V_74 ;
F_48 ( & V_87 -> V_73 , 1 ) ;
F_49 ( & V_87 -> V_72 ) ;
for ( V_76 = V_74 , V_74 = 0 ; V_74 < V_76 ; V_74 ++ ) {
F_45 ( V_68 [ V_74 ] . V_75 ,
F_46 ( & V_68 [ V_74 ] . V_66 ) ) ;
F_48 ( & V_68 [ V_74 ] . V_66 , 0 ) ;
V_42 = V_68 [ V_74 ] . V_42 ;
if ( V_42 < 0 ) {
F_19 ( V_30 L_22 ) ;
goto V_91;
}
if ( F_62 ( ! V_68 [ V_74 ] . V_82 ||
V_68 [ V_74 ] . V_82 >
F_63 ( V_68 [ V_74 ] . V_78 ) ) ) {
F_19 ( V_30
L_23 ) ;
V_42 = - 1 ;
goto V_91;
}
* ( T_2 * ) V_68 [ V_74 ] . V_80 = V_68 [ V_74 ] . V_82 ;
for ( V_84 = 0 ;
V_84 < V_81 + V_68 [ V_74 ] . V_82 ;
V_84 += V_37 ) {
memcpy ( V_86 , V_68 [ V_74 ] . V_80 + V_84 , V_37 ) ;
V_42 = F_35 ( V_19 , V_86 , & V_39 ) ;
if ( V_42 )
goto V_91;
}
}
F_45 ( V_87 -> V_75 , F_46 ( & V_87 -> V_66 ) ) ;
F_48 ( & V_87 -> V_66 , 0 ) ;
}
V_91:
V_64 = F_28 ( & V_39 ) ;
F_40 ( & V_66 ) ;
if ( ! V_42 )
V_42 = V_64 ;
if ( ! V_42 ) {
F_19 ( V_67 L_10 ) ;
} else {
F_19 ( V_67 L_11 ) ;
}
F_43 ( & V_9 , & V_66 , V_61 , L_12 ) ;
V_89:
if ( V_87 ) {
if ( V_87 -> V_74 )
F_64 ( V_87 -> V_74 ) ;
F_14 ( V_87 ) ;
}
if ( V_68 ) {
for ( V_74 = 0 ; V_74 < V_85 ; V_74 ++ )
if ( V_68 [ V_74 ] . V_74 )
F_64 ( V_68 [ V_74 ] . V_74 ) ;
F_65 ( V_68 ) ;
}
if ( V_86 ) F_31 ( ( unsigned long ) V_86 ) ;
return V_42 ;
}
static int F_66 ( unsigned int V_63 , unsigned int V_20 )
{
unsigned int V_92 = F_67 ( V_35 , 1 ) ;
unsigned int V_93 ;
F_68 ( L_24 , V_92 ) ;
V_93 = V_94 + V_63 ;
return V_92 > V_93 ;
}
int F_69 ( unsigned int V_20 )
{
struct V_18 V_19 ;
struct V_59 V_60 ;
struct V_95 * V_96 ;
unsigned long V_97 ;
int error ;
V_97 = F_70 () ;
error = F_32 ( & V_19 ) ;
if ( error ) {
F_19 ( V_30 L_25 ) ;
return error ;
}
if ( V_20 & V_98 ) {
if ( ! F_66 ( V_97 , V_20 ) ) {
F_19 ( V_30 L_26 ) ;
error = - V_43 ;
goto V_91;
}
}
memset ( & V_60 , 0 , sizeof( struct V_59 ) ) ;
error = F_41 ( & V_60 ) ;
if ( error < V_37 ) {
if ( error >= 0 )
error = - V_99 ;
goto V_91;
}
V_96 = (struct V_95 * ) F_42 ( V_60 ) ;
error = F_35 ( & V_19 , V_96 , NULL ) ;
if ( ! error ) {
error = ( V_20 & V_98 ) ?
F_39 ( & V_19 , & V_60 , V_97 - 1 ) :
F_53 ( & V_19 , & V_60 , V_97 - 1 ) ;
}
V_91:
error = F_38 ( & V_19 , V_20 , error ) ;
return error ;
}
static void F_71 ( struct V_18 * V_19 )
{
struct V_100 * V_101 ;
while ( V_19 -> V_102 ) {
if ( V_19 -> V_102 -> V_103 )
F_31 ( ( unsigned long ) V_19 -> V_102 -> V_103 ) ;
V_101 = V_19 -> V_102 ;
V_19 -> V_102 = V_19 -> V_102 -> V_104 ;
F_14 ( V_101 ) ;
}
V_19 -> V_46 = NULL ;
}
static int F_72 ( struct V_18 * V_19 ,
unsigned int * V_105 )
{
int error ;
struct V_100 * V_101 , * V_106 ;
T_1 V_17 ;
* V_105 = V_22 -> V_20 ;
if ( ! V_22 -> V_26 )
return - V_13 ;
V_19 -> V_46 = NULL ;
V_106 = V_19 -> V_102 = NULL ;
V_17 = V_22 -> V_26 ;
while ( V_17 ) {
V_101 = F_58 ( sizeof( * V_19 -> V_102 ) , V_14 ) ;
if ( ! V_101 ) {
F_71 ( V_19 ) ;
return - V_15 ;
}
memset ( V_101 , 0 , sizeof( * V_101 ) ) ;
if ( ! V_19 -> V_102 )
V_19 -> V_102 = V_101 ;
if ( V_106 )
V_106 -> V_104 = V_101 ;
V_106 = V_101 ;
V_101 -> V_103 = (struct V_47 * )
F_26 ( V_44 | V_45 ) ;
if ( ! V_101 -> V_103 ) {
F_71 ( V_19 ) ;
return - V_15 ;
}
error = F_17 ( V_17 , V_101 -> V_103 , NULL ) ;
if ( error ) {
F_71 ( V_19 ) ;
return error ;
}
V_17 = V_101 -> V_103 -> V_56 ;
}
V_19 -> V_51 = 0 ;
V_19 -> V_46 = V_19 -> V_102 -> V_103 ;
return 0 ;
}
static int F_73 ( struct V_18 * V_19 , void * V_38 ,
struct V_39 * * V_40 )
{
T_1 V_17 ;
int error ;
struct V_100 * V_101 ;
if ( ! V_19 -> V_46 )
return - V_13 ;
V_17 = V_19 -> V_46 -> V_54 [ V_19 -> V_51 ] ;
if ( ! V_17 )
return - V_99 ;
error = F_17 ( V_17 , V_38 , V_40 ) ;
if ( error )
return error ;
if ( ++ V_19 -> V_51 >= V_55 ) {
V_19 -> V_51 = 0 ;
F_31 ( ( unsigned long ) V_19 -> V_102 -> V_103 ) ;
V_101 = V_19 -> V_102 ;
V_19 -> V_102 = V_19 -> V_102 -> V_104 ;
F_14 ( V_101 ) ;
if ( ! V_19 -> V_102 )
F_71 ( V_19 ) ;
else
V_19 -> V_46 = V_19 -> V_102 -> V_103 ;
}
return error ;
}
static int F_74 ( struct V_18 * V_19 )
{
F_71 ( V_19 ) ;
return 0 ;
}
static int F_75 ( struct V_18 * V_19 ,
struct V_59 * V_60 ,
unsigned int V_107 )
{
unsigned int V_62 ;
int V_42 = 0 ;
struct V_65 V_9 ;
struct V_65 V_66 ;
struct V_39 * V_39 ;
int V_64 ;
unsigned V_63 ;
F_19 ( V_58 L_27 ,
V_107 ) ;
V_62 = V_107 / 100 ;
if ( ! V_62 )
V_62 = 1 ;
V_63 = 0 ;
V_39 = NULL ;
F_40 ( & V_9 ) ;
for ( ; ; ) {
V_42 = F_76 ( V_60 ) ;
if ( V_42 <= 0 )
break;
V_42 = F_73 ( V_19 , F_42 ( * V_60 ) , & V_39 ) ;
if ( V_42 )
break;
if ( V_60 -> V_108 )
V_42 = F_28 ( & V_39 ) ;
if ( V_42 )
break;
if ( ! ( V_63 % V_62 ) )
F_19 ( L_9 , V_63 / V_62 ) ;
V_63 ++ ;
}
V_64 = F_28 ( & V_39 ) ;
F_40 ( & V_66 ) ;
if ( ! V_42 )
V_42 = V_64 ;
if ( ! V_42 ) {
F_19 ( L_10 ) ;
F_77 ( V_60 ) ;
if ( ! F_78 ( V_60 ) )
V_42 = - V_109 ;
} else
F_19 ( L_11 ) ;
F_43 ( & V_9 , & V_66 , V_107 , L_28 ) ;
return V_42 ;
}
static int F_79 ( void * V_68 )
{
struct V_110 * V_70 = V_68 ;
while ( 1 ) {
F_45 ( V_70 -> V_72 , F_46 ( & V_70 -> V_73 ) ||
F_47 () ) ;
if ( F_47 () ) {
V_70 -> V_74 = NULL ;
V_70 -> V_42 = - 1 ;
F_48 ( & V_70 -> V_66 , 1 ) ;
F_49 ( & V_70 -> V_75 ) ;
break;
}
F_48 ( & V_70 -> V_73 , 0 ) ;
V_70 -> V_78 = V_90 ;
V_70 -> V_42 = F_80 ( V_70 -> V_80 + V_81 , V_70 -> V_82 ,
V_70 -> V_77 , & V_70 -> V_78 ) ;
F_48 ( & V_70 -> V_66 , 1 ) ;
F_49 ( & V_70 -> V_75 ) ;
}
return 0 ;
}
static int F_81 ( struct V_18 * V_19 ,
struct V_59 * V_60 ,
unsigned int V_107 )
{
unsigned int V_62 ;
int V_42 = 0 ;
int V_111 = 0 ;
struct V_39 * V_39 ;
struct V_65 V_9 ;
struct V_65 V_66 ;
unsigned V_63 ;
T_2 V_84 ;
unsigned V_71 , V_74 , V_76 , V_85 ;
unsigned V_112 = 0 , V_113 = 0 , V_114 = 0 ,
V_115 = 0 , V_116 , V_117 , V_118 = 0 ;
unsigned long V_119 ;
unsigned char * * V_86 = NULL ;
struct V_110 * V_68 = NULL ;
struct V_69 * V_87 = NULL ;
V_85 = F_54 () - 1 ;
V_85 = F_55 ( V_85 , 1 , V_88 ) ;
V_86 = F_56 ( sizeof( * V_86 ) * V_120 ) ;
if ( ! V_86 ) {
F_19 ( V_30 L_13 ) ;
V_42 = - V_15 ;
goto V_89;
}
V_68 = F_56 ( sizeof( * V_68 ) * V_85 ) ;
if ( ! V_68 ) {
F_19 ( V_30 L_14 ) ;
V_42 = - V_15 ;
goto V_89;
}
for ( V_74 = 0 ; V_74 < V_85 ; V_74 ++ )
memset ( & V_68 [ V_74 ] , 0 , F_57 ( struct V_110 , V_72 ) ) ;
V_87 = F_58 ( sizeof( * V_87 ) , V_14 ) ;
if ( ! V_87 ) {
F_19 ( V_30 L_15 ) ;
V_42 = - V_15 ;
goto V_89;
}
memset ( V_87 , 0 , F_57 ( struct V_69 , V_72 ) ) ;
for ( V_74 = 0 ; V_74 < V_85 ; V_74 ++ ) {
F_59 ( & V_68 [ V_74 ] . V_72 ) ;
F_59 ( & V_68 [ V_74 ] . V_75 ) ;
V_68 [ V_74 ] . V_74 = F_60 ( F_79 ,
& V_68 [ V_74 ] ,
L_29 , V_74 ) ;
if ( F_61 ( V_68 [ V_74 ] . V_74 ) ) {
V_68 [ V_74 ] . V_74 = NULL ;
F_19 ( V_30
L_30 ) ;
V_42 = - V_15 ;
goto V_89;
}
}
F_59 ( & V_87 -> V_72 ) ;
F_59 ( & V_87 -> V_75 ) ;
V_19 -> V_29 = 0 ;
V_87 -> V_29 = & V_19 -> V_29 ;
for ( V_74 = 0 ; V_74 < V_85 ; V_74 ++ ) {
V_87 -> V_77 [ V_74 ] = V_68 [ V_74 ] . V_77 ;
V_87 -> V_78 [ V_74 ] = & V_68 [ V_74 ] . V_78 ;
}
V_87 -> V_74 = F_60 ( F_44 , V_87 , L_18 ) ;
if ( F_61 ( V_87 -> V_74 ) ) {
V_87 -> V_74 = NULL ;
F_19 ( V_30 L_19 ) ;
V_42 = - V_15 ;
goto V_89;
}
V_119 = ( V_52 () - F_70 () ) >> 1 ;
V_119 = F_55 ( V_119 , V_121 , V_120 ) ;
for ( V_71 = 0 ; V_71 < V_119 ; V_71 ++ ) {
V_86 [ V_71 ] = ( void * ) F_26 ( V_71 < V_121 ?
V_44 | V_45 :
V_44 ) ;
if ( ! V_86 [ V_71 ] ) {
if ( V_71 < V_121 ) {
V_114 = V_71 ;
F_19 ( V_30
L_31 ) ;
V_42 = - V_15 ;
goto V_89;
} else {
break;
}
}
}
V_116 = V_114 = V_71 ;
F_19 ( V_58
L_32
L_33 ,
V_85 , V_107 ) ;
V_62 = V_107 / 100 ;
if ( ! V_62 )
V_62 = 1 ;
V_63 = 0 ;
V_39 = NULL ;
F_40 ( & V_9 ) ;
V_42 = F_76 ( V_60 ) ;
if ( V_42 <= 0 )
goto V_91;
for(; ; ) {
for ( V_71 = 0 ; ! V_111 && V_71 < V_116 ; V_71 ++ ) {
V_42 = F_73 ( V_19 , V_86 [ V_112 ] , & V_39 ) ;
if ( V_42 ) {
if ( V_19 -> V_46 &&
V_19 -> V_46 -> V_54 [ V_19 -> V_51 ] ) {
goto V_91;
} else {
V_111 = 1 ;
break;
}
}
if ( ++ V_112 >= V_114 )
V_112 = 0 ;
}
V_118 += V_71 ;
V_116 -= V_71 ;
if ( ! V_115 ) {
if ( ! V_118 )
break;
V_42 = F_28 ( & V_39 ) ;
if ( V_42 )
goto V_91;
V_115 += V_118 ;
V_118 = 0 ;
if ( V_111 )
V_111 = 2 ;
}
if ( V_87 -> V_76 ) {
F_45 ( V_87 -> V_75 , F_46 ( & V_87 -> V_66 ) ) ;
F_48 ( & V_87 -> V_66 , 0 ) ;
V_87 -> V_76 = 0 ;
}
for ( V_74 = 0 ; V_115 && V_74 < V_85 ; V_74 ++ ) {
V_68 [ V_74 ] . V_82 = * ( T_2 * ) V_86 [ V_113 ] ;
if ( F_62 ( ! V_68 [ V_74 ] . V_82 ||
V_68 [ V_74 ] . V_82 >
F_63 ( V_90 ) ) ) {
F_19 ( V_30
L_23 ) ;
V_42 = - 1 ;
goto V_91;
}
V_117 = F_82 ( V_68 [ V_74 ] . V_82 + V_81 ,
V_37 ) ;
if ( V_117 > V_115 ) {
if ( V_111 > 1 ) {
V_42 = - 1 ;
goto V_91;
}
break;
}
for ( V_84 = 0 ;
V_84 < V_81 + V_68 [ V_74 ] . V_82 ;
V_84 += V_37 ) {
memcpy ( V_68 [ V_74 ] . V_80 + V_84 ,
V_86 [ V_113 ] , V_37 ) ;
V_115 -- ;
V_116 ++ ;
if ( ++ V_113 >= V_114 )
V_113 = 0 ;
}
F_48 ( & V_68 [ V_74 ] . V_73 , 1 ) ;
F_49 ( & V_68 [ V_74 ] . V_72 ) ;
}
if ( V_115 < V_121 && V_118 ) {
V_42 = F_28 ( & V_39 ) ;
if ( V_42 )
goto V_91;
V_115 += V_118 ;
V_118 = 0 ;
if ( V_111 )
V_111 = 2 ;
}
for ( V_76 = V_74 , V_74 = 0 ; V_74 < V_76 ; V_74 ++ ) {
F_45 ( V_68 [ V_74 ] . V_75 ,
F_46 ( & V_68 [ V_74 ] . V_66 ) ) ;
F_48 ( & V_68 [ V_74 ] . V_66 , 0 ) ;
V_42 = V_68 [ V_74 ] . V_42 ;
if ( V_42 < 0 ) {
F_19 ( V_30
L_34 ) ;
goto V_91;
}
if ( F_62 ( ! V_68 [ V_74 ] . V_78 ||
V_68 [ V_74 ] . V_78 > V_90 ||
V_68 [ V_74 ] . V_78 & ( V_37 - 1 ) ) ) {
F_19 ( V_30
L_35 ) ;
V_42 = - 1 ;
goto V_91;
}
for ( V_84 = 0 ;
V_84 < V_68 [ V_74 ] . V_78 ; V_84 += V_37 ) {
memcpy ( F_42 ( * V_60 ) ,
V_68 [ V_74 ] . V_77 + V_84 , V_37 ) ;
if ( ! ( V_63 % V_62 ) )
F_19 ( L_9 , V_63 / V_62 ) ;
V_63 ++ ;
V_42 = F_76 ( V_60 ) ;
if ( V_42 <= 0 ) {
V_87 -> V_76 = V_74 + 1 ;
F_48 ( & V_87 -> V_73 , 1 ) ;
F_49 ( & V_87 -> V_72 ) ;
goto V_91;
}
}
}
V_87 -> V_76 = V_74 ;
F_48 ( & V_87 -> V_73 , 1 ) ;
F_49 ( & V_87 -> V_72 ) ;
}
V_91:
if ( V_87 -> V_76 ) {
F_45 ( V_87 -> V_75 , F_46 ( & V_87 -> V_66 ) ) ;
F_48 ( & V_87 -> V_66 , 0 ) ;
}
F_40 ( & V_66 ) ;
if ( ! V_42 ) {
F_19 ( L_10 ) ;
F_77 ( V_60 ) ;
if ( ! F_78 ( V_60 ) )
V_42 = - V_109 ;
if ( ! V_42 ) {
if ( V_22 -> V_20 & V_28 ) {
if( V_19 -> V_29 != V_22 -> V_29 ) {
F_19 ( V_30
L_36 ) ;
V_42 = - V_109 ;
}
}
}
} else
F_19 ( L_11 ) ;
F_43 ( & V_9 , & V_66 , V_107 , L_28 ) ;
V_89:
for ( V_71 = 0 ; V_71 < V_114 ; V_71 ++ )
F_31 ( ( unsigned long ) V_86 [ V_71 ] ) ;
if ( V_87 ) {
if ( V_87 -> V_74 )
F_64 ( V_87 -> V_74 ) ;
F_14 ( V_87 ) ;
}
if ( V_68 ) {
for ( V_74 = 0 ; V_74 < V_85 ; V_74 ++ )
if ( V_68 [ V_74 ] . V_74 )
F_64 ( V_68 [ V_74 ] . V_74 ) ;
F_65 ( V_68 ) ;
}
if ( V_86 ) F_65 ( V_86 ) ;
return V_42 ;
}
int F_83 ( unsigned int * V_105 )
{
int error ;
struct V_18 V_19 ;
struct V_59 V_60 ;
struct V_95 * V_96 ;
memset ( & V_60 , 0 , sizeof( struct V_59 ) ) ;
error = F_76 ( & V_60 ) ;
if ( error < V_37 )
return error < 0 ? error : - V_99 ;
V_96 = (struct V_95 * ) F_42 ( V_60 ) ;
error = F_72 ( & V_19 , V_105 ) ;
if ( error )
goto V_11;
if ( ! error )
error = F_73 ( & V_19 , V_96 , NULL ) ;
if ( ! error ) {
error = ( * V_105 & V_98 ) ?
F_75 ( & V_19 , & V_60 , V_96 -> V_97 - 1 ) :
F_81 ( & V_19 , & V_60 , V_96 -> V_97 - 1 ) ;
}
F_74 ( & V_19 ) ;
V_11:
if ( ! error )
F_68 ( L_37 ) ;
else
F_68 ( L_38 , error ) ;
return error ;
}
int F_84 ( void )
{
int error ;
V_34 = F_85 ( V_33 ,
V_122 , NULL ) ;
if ( ! F_61 ( V_34 ) ) {
F_23 ( V_34 , V_37 ) ;
F_36 ( V_22 ) ;
error = F_17 ( V_21 ,
V_22 , NULL ) ;
if ( error )
goto V_123;
if ( ! memcmp ( V_25 , V_22 -> V_23 , 10 ) ) {
memcpy ( V_22 -> V_23 , V_22 -> V_24 , 10 ) ;
error = F_18 ( V_21 ,
V_22 , NULL ) ;
} else {
error = - V_13 ;
}
V_123:
if ( error )
F_24 ( V_34 , V_122 ) ;
else
F_68 ( L_39 ) ;
} else {
error = F_86 ( V_34 ) ;
}
if ( error )
F_68 ( L_40 , error ) ;
return error ;
}
void F_34 ( T_3 V_124 )
{
if ( F_61 ( V_34 ) ) {
F_68 ( L_41 ) ;
return;
}
F_24 ( V_34 , V_124 ) ;
}
static int F_87 ( void )
{
V_22 = (struct V_22 * ) F_26 ( V_14 ) ;
if ( ! V_22 )
F_88 ( L_42 ) ;
return 0 ;
}
