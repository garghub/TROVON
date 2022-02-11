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
error = F_18 ( V_21 ,
V_22 , NULL ) ;
} else {
F_19 ( V_28 L_3 ) ;
error = - V_29 ;
}
return error ;
}
static int F_20 ( void )
{
int V_30 ;
V_30 = F_21 ( V_31 , V_21 ,
& V_32 ) ;
if ( V_30 < 0 )
return V_30 ;
V_33 = V_30 ;
V_30 = F_22 ( V_32 , V_34 , NULL ) ;
if ( V_30 )
return V_30 ;
V_30 = F_23 ( V_32 , V_35 ) ;
if ( V_30 < 0 )
F_24 ( V_32 , V_34 ) ;
return V_30 ;
}
static int F_25 ( void * V_36 , T_1 V_17 , struct V_37 * * V_38 )
{
void * V_39 ;
if ( ! V_17 )
return - V_40 ;
if ( V_38 ) {
V_39 = ( void * ) F_26 ( V_41 | V_42 ) ;
if ( V_39 ) {
F_27 ( V_39 , V_36 ) ;
} else {
F_28 ( 1 ) ;
V_38 = NULL ;
V_39 = V_36 ;
}
} else {
V_39 = V_36 ;
}
return F_18 ( V_17 , V_39 , V_38 ) ;
}
static void F_29 ( struct V_18 * V_19 )
{
if ( V_19 -> V_43 )
F_30 ( ( unsigned long ) V_19 -> V_43 ) ;
V_19 -> V_43 = NULL ;
}
static int F_31 ( struct V_18 * V_19 )
{
int V_44 ;
V_44 = F_20 () ;
if ( V_44 ) {
if ( V_44 != - V_40 )
F_19 ( V_28 L_4
L_5 ) ;
return V_44 ;
}
V_19 -> V_43 = (struct V_45 * ) F_32 ( V_14 ) ;
if ( ! V_19 -> V_43 ) {
V_44 = - V_15 ;
goto V_46;
}
V_19 -> V_47 = F_6 ( V_33 ) ;
if ( ! V_19 -> V_47 ) {
V_44 = - V_40 ;
goto V_48;
}
V_19 -> V_49 = 0 ;
V_19 -> V_27 = V_19 -> V_47 ;
return 0 ;
V_48:
F_29 ( V_19 ) ;
V_46:
F_33 ( V_34 ) ;
return V_44 ;
}
static int F_34 ( struct V_18 * V_19 , void * V_36 ,
struct V_37 * * V_38 )
{
int error = 0 ;
T_1 V_17 ;
if ( ! V_19 -> V_43 )
return - V_13 ;
V_17 = F_6 ( V_33 ) ;
error = F_25 ( V_36 , V_17 , V_38 ) ;
if ( error )
return error ;
V_19 -> V_43 -> V_50 [ V_19 -> V_49 ++ ] = V_17 ;
if ( V_19 -> V_49 >= V_51 ) {
error = F_35 ( V_38 ) ;
if ( error )
goto V_52;
V_17 = F_6 ( V_33 ) ;
if ( ! V_17 )
return - V_40 ;
V_19 -> V_43 -> V_53 = V_17 ;
error = F_25 ( V_19 -> V_43 , V_19 -> V_47 , NULL ) ;
if ( error )
goto V_52;
F_36 ( V_19 -> V_43 ) ;
V_19 -> V_47 = V_17 ;
V_19 -> V_49 = 0 ;
}
V_52:
return error ;
}
static int F_37 ( struct V_18 * V_19 )
{
if ( V_19 -> V_43 && V_19 -> V_47 )
return F_25 ( V_19 -> V_43 , V_19 -> V_47 , NULL ) ;
else
return - V_13 ;
}
static int F_38 ( struct V_18 * V_19 ,
unsigned int V_20 , int error )
{
if ( ! error ) {
F_37 ( V_19 ) ;
F_19 ( V_54 L_6 ) ;
error = F_16 ( V_19 , V_20 ) ;
F_19 ( L_7 ) ;
}
if ( error )
F_12 ( V_33 ) ;
F_29 ( V_19 ) ;
F_33 ( V_34 ) ;
return error ;
}
static int F_39 ( struct V_18 * V_19 ,
struct V_55 * V_56 ,
unsigned int V_57 )
{
unsigned int V_58 ;
int V_44 ;
int V_59 ;
int V_60 ;
struct V_37 * V_37 ;
struct V_61 V_9 ;
struct V_61 V_62 ;
F_19 ( V_54 L_8 ,
V_57 ) ;
V_58 = V_57 / 100 ;
if ( ! V_58 )
V_58 = 1 ;
V_59 = 0 ;
V_37 = NULL ;
F_40 ( & V_9 ) ;
while ( 1 ) {
V_44 = F_41 ( V_56 ) ;
if ( V_44 <= 0 )
break;
V_44 = F_34 ( V_19 , F_42 ( * V_56 ) , & V_37 ) ;
if ( V_44 )
break;
if ( ! ( V_59 % V_58 ) )
F_19 ( V_63 L_9 , V_59 / V_58 ) ;
V_59 ++ ;
}
V_60 = F_35 ( & V_37 ) ;
F_40 ( & V_62 ) ;
if ( ! V_44 )
V_44 = V_60 ;
if ( ! V_44 )
F_19 ( V_63 L_10 ) ;
else
F_19 ( V_63 L_11 ) ;
F_43 ( & V_9 , & V_62 , V_57 , L_12 ) ;
return V_44 ;
}
static int F_44 ( struct V_18 * V_19 ,
struct V_55 * V_56 ,
unsigned int V_57 )
{
unsigned int V_58 ;
int V_44 = 0 ;
int V_59 ;
int V_60 ;
struct V_37 * V_37 ;
struct V_61 V_9 ;
struct V_61 V_62 ;
T_2 V_64 , V_65 , V_66 ;
unsigned char * V_67 , * V_68 , * V_69 , * V_70 ;
V_70 = ( void * ) F_26 ( V_41 | V_42 ) ;
if ( ! V_70 ) {
F_19 ( V_28 L_13 ) ;
return - V_15 ;
}
V_69 = F_45 ( V_71 ) ;
if ( ! V_69 ) {
F_19 ( V_28 L_14 ) ;
F_30 ( ( unsigned long ) V_70 ) ;
return - V_15 ;
}
V_67 = F_45 ( V_72 ) ;
if ( ! V_67 ) {
F_19 ( V_28 L_15 ) ;
F_46 ( V_69 ) ;
F_30 ( ( unsigned long ) V_70 ) ;
return - V_15 ;
}
V_68 = F_45 ( V_73 ) ;
if ( ! V_68 ) {
F_19 ( V_28 L_16 ) ;
F_46 ( V_67 ) ;
F_46 ( V_69 ) ;
F_30 ( ( unsigned long ) V_70 ) ;
return - V_15 ;
}
F_19 ( V_54
L_17 ,
V_57 ) ;
V_58 = V_57 / 100 ;
if ( ! V_58 )
V_58 = 1 ;
V_59 = 0 ;
V_37 = NULL ;
F_40 ( & V_9 ) ;
for (; ; ) {
for ( V_64 = 0 ; V_64 < V_72 ; V_64 += V_35 ) {
V_44 = F_41 ( V_56 ) ;
if ( V_44 < 0 )
goto V_74;
if ( ! V_44 )
break;
memcpy ( V_67 + V_64 , F_42 ( * V_56 ) , V_35 ) ;
if ( ! ( V_59 % V_58 ) )
F_19 ( V_63 L_9 , V_59 / V_58 ) ;
V_59 ++ ;
}
if ( ! V_64 )
break;
V_65 = V_64 ;
V_44 = F_47 ( V_67 , V_65 ,
V_68 + V_75 , & V_66 , V_69 ) ;
if ( V_44 < 0 ) {
F_19 ( V_28 L_18 ) ;
break;
}
if ( F_48 ( ! V_66 ||
V_66 > F_49 ( V_65 ) ) ) {
F_19 ( V_28 L_19 ) ;
V_44 = - 1 ;
break;
}
* ( T_2 * ) V_68 = V_66 ;
for ( V_64 = 0 ; V_64 < V_75 + V_66 ; V_64 += V_35 ) {
memcpy ( V_70 , V_68 + V_64 , V_35 ) ;
V_44 = F_34 ( V_19 , V_70 , & V_37 ) ;
if ( V_44 )
goto V_74;
}
}
V_74:
V_60 = F_35 ( & V_37 ) ;
F_40 ( & V_62 ) ;
if ( ! V_44 )
V_44 = V_60 ;
if ( ! V_44 )
F_19 ( V_63 L_10 ) ;
else
F_19 ( V_63 L_11 ) ;
F_43 ( & V_9 , & V_62 , V_57 , L_12 ) ;
F_46 ( V_68 ) ;
F_46 ( V_67 ) ;
F_46 ( V_69 ) ;
F_30 ( ( unsigned long ) V_70 ) ;
return V_44 ;
}
static int F_50 ( unsigned int V_59 , unsigned int V_20 )
{
unsigned int V_76 = F_51 ( V_33 , 1 ) ;
unsigned int V_77 ;
F_52 ( L_20 , V_76 ) ;
V_77 = V_78 + ( ( V_20 & V_79 ) ?
V_59 : ( V_59 * V_80 ) / V_81 + 1 ) ;
return V_76 > V_77 ;
}
int F_53 ( unsigned int V_20 )
{
struct V_18 V_19 ;
struct V_55 V_56 ;
struct V_82 * V_83 ;
unsigned long V_84 ;
int error ;
V_84 = F_54 () ;
error = F_31 ( & V_19 ) ;
if ( error ) {
F_19 ( V_28 L_21 ) ;
return error ;
}
if ( ! F_50 ( V_84 , V_20 ) ) {
F_19 ( V_28 L_22 ) ;
error = - V_40 ;
goto V_74;
}
memset ( & V_56 , 0 , sizeof( struct V_55 ) ) ;
error = F_41 ( & V_56 ) ;
if ( error < V_35 ) {
if ( error >= 0 )
error = - V_85 ;
goto V_74;
}
V_83 = (struct V_82 * ) F_42 ( V_56 ) ;
error = F_34 ( & V_19 , V_83 , NULL ) ;
if ( ! error ) {
error = ( V_20 & V_79 ) ?
F_39 ( & V_19 , & V_56 , V_84 - 1 ) :
F_44 ( & V_19 , & V_56 , V_84 - 1 ) ;
}
V_74:
error = F_38 ( & V_19 , V_20 , error ) ;
return error ;
}
static void F_55 ( struct V_18 * V_19 )
{
if ( V_19 -> V_43 )
F_30 ( ( unsigned long ) V_19 -> V_43 ) ;
V_19 -> V_43 = NULL ;
}
static int F_56 ( struct V_18 * V_19 ,
unsigned int * V_86 )
{
int error ;
* V_86 = V_22 -> V_20 ;
if ( ! V_22 -> V_26 )
return - V_13 ;
V_19 -> V_43 = (struct V_45 * ) F_32 ( V_41 | V_42 ) ;
if ( ! V_19 -> V_43 )
return - V_15 ;
error = F_17 ( V_22 -> V_26 , V_19 -> V_43 , NULL ) ;
if ( error ) {
F_55 ( V_19 ) ;
return error ;
}
V_19 -> V_49 = 0 ;
return 0 ;
}
static int F_57 ( struct V_18 * V_19 , void * V_36 ,
struct V_37 * * V_38 )
{
T_1 V_17 ;
int error ;
if ( ! V_19 -> V_43 )
return - V_13 ;
V_17 = V_19 -> V_43 -> V_50 [ V_19 -> V_49 ] ;
if ( ! V_17 )
return - V_85 ;
error = F_17 ( V_17 , V_36 , V_38 ) ;
if ( error )
return error ;
if ( ++ V_19 -> V_49 >= V_51 ) {
error = F_35 ( V_38 ) ;
V_19 -> V_49 = 0 ;
V_17 = V_19 -> V_43 -> V_53 ;
if ( ! V_17 )
F_55 ( V_19 ) ;
else if ( ! error )
error = F_17 ( V_17 , V_19 -> V_43 , NULL ) ;
}
return error ;
}
static int F_58 ( struct V_18 * V_19 )
{
F_55 ( V_19 ) ;
return 0 ;
}
static int F_59 ( struct V_18 * V_19 ,
struct V_55 * V_56 ,
unsigned int V_87 )
{
unsigned int V_58 ;
int error = 0 ;
struct V_61 V_9 ;
struct V_61 V_62 ;
struct V_37 * V_37 ;
int V_60 ;
unsigned V_59 ;
F_19 ( V_54 L_23 ,
V_87 ) ;
V_58 = V_87 / 100 ;
if ( ! V_58 )
V_58 = 1 ;
V_59 = 0 ;
V_37 = NULL ;
F_40 ( & V_9 ) ;
for ( ; ; ) {
error = F_60 ( V_56 ) ;
if ( error <= 0 )
break;
error = F_57 ( V_19 , F_42 ( * V_56 ) , & V_37 ) ;
if ( error )
break;
if ( V_56 -> V_88 )
error = F_35 ( & V_37 ) ;
if ( error )
break;
if ( ! ( V_59 % V_58 ) )
F_19 ( L_9 , V_59 / V_58 ) ;
V_59 ++ ;
}
V_60 = F_35 ( & V_37 ) ;
F_40 ( & V_62 ) ;
if ( ! error )
error = V_60 ;
if ( ! error ) {
F_19 ( L_10 ) ;
F_61 ( V_56 ) ;
if ( ! F_62 ( V_56 ) )
error = - V_89 ;
} else
F_19 ( L_11 ) ;
F_43 ( & V_9 , & V_62 , V_87 , L_24 ) ;
return error ;
}
static int F_63 ( struct V_18 * V_19 ,
struct V_55 * V_56 ,
unsigned int V_87 )
{
unsigned int V_58 ;
int error = 0 ;
struct V_37 * V_37 ;
struct V_61 V_9 ;
struct V_61 V_62 ;
unsigned V_59 ;
T_2 V_90 , V_64 , V_65 , V_66 ;
unsigned char * V_67 , * V_68 , * V_70 [ V_80 ] ;
for ( V_90 = 0 ; V_90 < V_80 ; V_90 ++ ) {
V_70 [ V_90 ] = ( void * ) F_26 ( V_41 | V_42 ) ;
if ( ! V_70 [ V_90 ] ) {
F_19 ( V_28 L_13 ) ;
while ( V_90 )
F_30 ( ( unsigned long ) V_70 [ -- V_90 ] ) ;
return - V_15 ;
}
}
V_67 = F_45 ( V_72 ) ;
if ( ! V_67 ) {
F_19 ( V_28 L_15 ) ;
for ( V_90 = 0 ; V_90 < V_80 ; V_90 ++ )
F_30 ( ( unsigned long ) V_70 [ V_90 ] ) ;
return - V_15 ;
}
V_68 = F_45 ( V_73 ) ;
if ( ! V_68 ) {
F_19 ( V_28 L_16 ) ;
F_46 ( V_67 ) ;
for ( V_90 = 0 ; V_90 < V_80 ; V_90 ++ )
F_30 ( ( unsigned long ) V_70 [ V_90 ] ) ;
return - V_15 ;
}
F_19 ( V_54
L_25 ,
V_87 ) ;
V_58 = V_87 / 100 ;
if ( ! V_58 )
V_58 = 1 ;
V_59 = 0 ;
V_37 = NULL ;
F_40 ( & V_9 ) ;
error = F_60 ( V_56 ) ;
if ( error <= 0 )
goto V_74;
for (; ; ) {
error = F_57 ( V_19 , V_70 [ 0 ] , NULL ) ;
if ( error )
break;
V_66 = * ( T_2 * ) V_70 [ 0 ] ;
if ( F_48 ( ! V_66 ||
V_66 > F_49 ( V_72 ) ) ) {
F_19 ( V_28 L_19 ) ;
error = - 1 ;
break;
}
for ( V_64 = V_35 , V_90 = 1 ;
V_64 < V_75 + V_66 ; V_64 += V_35 , V_90 ++ ) {
error = F_57 ( V_19 , V_70 [ V_90 ] , & V_37 ) ;
if ( error )
goto V_74;
}
error = F_35 ( & V_37 ) ;
if ( error )
goto V_74;
for ( V_64 = 0 , V_90 = 0 ;
V_64 < V_75 + V_66 ; V_64 += V_35 , V_90 ++ ) {
memcpy ( V_68 + V_64 , V_70 [ V_90 ] , V_35 ) ;
}
V_65 = V_72 ;
error = F_64 ( V_68 + V_75 , V_66 ,
V_67 , & V_65 ) ;
if ( error < 0 ) {
F_19 ( V_28 L_26 ) ;
break;
}
if ( F_48 ( ! V_65 ||
V_65 > V_72 ||
V_65 & ( V_35 - 1 ) ) ) {
F_19 ( V_28 L_27 ) ;
error = - 1 ;
break;
}
for ( V_64 = 0 ; V_64 < V_65 ; V_64 += V_35 ) {
memcpy ( F_42 ( * V_56 ) , V_67 + V_64 , V_35 ) ;
if ( ! ( V_59 % V_58 ) )
F_19 ( L_9 , V_59 / V_58 ) ;
V_59 ++ ;
error = F_60 ( V_56 ) ;
if ( error <= 0 )
goto V_74;
}
}
V_74:
F_40 ( & V_62 ) ;
if ( ! error ) {
F_19 ( L_10 ) ;
F_61 ( V_56 ) ;
if ( ! F_62 ( V_56 ) )
error = - V_89 ;
} else
F_19 ( L_11 ) ;
F_43 ( & V_9 , & V_62 , V_87 , L_24 ) ;
F_46 ( V_68 ) ;
F_46 ( V_67 ) ;
for ( V_90 = 0 ; V_90 < V_80 ; V_90 ++ )
F_30 ( ( unsigned long ) V_70 [ V_90 ] ) ;
return error ;
}
int F_65 ( unsigned int * V_86 )
{
int error ;
struct V_18 V_19 ;
struct V_55 V_56 ;
struct V_82 * V_83 ;
memset ( & V_56 , 0 , sizeof( struct V_55 ) ) ;
error = F_60 ( & V_56 ) ;
if ( error < V_35 )
return error < 0 ? error : - V_85 ;
V_83 = (struct V_82 * ) F_42 ( V_56 ) ;
error = F_56 ( & V_19 , V_86 ) ;
if ( error )
goto V_11;
if ( ! error )
error = F_57 ( & V_19 , V_83 , NULL ) ;
if ( ! error ) {
error = ( * V_86 & V_79 ) ?
F_59 ( & V_19 , & V_56 , V_83 -> V_84 - 1 ) :
F_63 ( & V_19 , & V_56 , V_83 -> V_84 - 1 ) ;
}
F_58 ( & V_19 ) ;
V_11:
if ( ! error )
F_52 ( L_28 ) ;
else
F_52 ( L_29 , error ) ;
return error ;
}
int F_66 ( void )
{
int error ;
V_32 = F_67 ( V_31 ,
V_91 , NULL ) ;
if ( ! F_68 ( V_32 ) ) {
F_23 ( V_32 , V_35 ) ;
F_36 ( V_22 ) ;
error = F_17 ( V_21 ,
V_22 , NULL ) ;
if ( error )
goto V_92;
if ( ! memcmp ( V_25 , V_22 -> V_23 , 10 ) ) {
memcpy ( V_22 -> V_23 , V_22 -> V_24 , 10 ) ;
error = F_18 ( V_21 ,
V_22 , NULL ) ;
} else {
error = - V_13 ;
}
V_92:
if ( error )
F_24 ( V_32 , V_91 ) ;
else
F_52 ( L_30 ) ;
} else {
error = F_69 ( V_32 ) ;
}
if ( error )
F_52 ( L_31 , error ) ;
return error ;
}
void F_33 ( T_3 V_93 )
{
if ( F_68 ( V_32 ) ) {
F_52 ( L_32 ) ;
return;
}
F_24 ( V_32 , V_93 ) ;
}
static int F_70 ( void )
{
V_22 = (struct V_22 * ) F_26 ( V_14 ) ;
if ( ! V_22 )
F_71 ( L_33 ) ;
return 0 ;
}
