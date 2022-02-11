static void T_1 F_1 ( void )
{
unsigned int V_1 ;
unsigned long V_2 ;
#ifdef F_2
V_2 = 0 ;
#else
V_2 = sizeof( struct V_3 ) ;
#endif
for ( V_1 = 0 ; V_1 < F_3 () ; ++ V_1 ) {
F_4 ( V_4 , V_1 ) . V_5 =
F_5 ( V_6 , V_7 ) ;
if ( ! F_4 ( V_4 , V_1 ) . V_5 ) {
F_6 ( V_8 L_1 ) ;
return;
}
F_4 ( V_4 , V_1 ) . V_5 -> V_9 = ( void * ) F_7 ( V_1 ) + V_2 ;
F_4 ( V_4 , V_1 ) . V_5 -> V_10 = V_11 - V_2 ;
F_4 ( V_4 , V_1 ) . V_5 -> V_12 = 0 ;
F_4 ( V_4 , V_1 ) . V_5 -> V_5 = NULL ;
F_4 ( V_13 , V_1 ) . V_5 = NULL ;
F_8 ( & F_4 ( V_14 , V_1 ) ) ;
F_6 ( V_8 L_2 ,
V_11 >> 10 ) ;
}
}
static void T_1 F_9 ( void )
{
#if V_15 != 0 || V_16 != 0
unsigned int V_1 ;
#endif
#if V_15 != 0
for ( V_1 = 0 ; V_1 < F_3 () ; ++ V_1 ) {
F_4 ( V_17 , V_1 ) . V_5 =
F_5 ( V_6 , V_7 ) ;
if ( ! F_4 ( V_17 , V_1 ) . V_5 ) {
F_6 ( V_8 L_3 ) ;
return;
}
F_4 ( V_17 , V_1 ) . V_5 -> V_9 =
( void * ) F_10 ( V_1 ) + ( V_18 - V_19 ) ;
F_4 ( V_17 , V_1 ) . V_5 -> V_10 =
V_15 - ( V_18 - V_19 ) ;
F_4 ( V_17 , V_1 ) . V_5 -> V_12 = 0 ;
F_4 ( V_17 , V_1 ) . V_5 -> V_5 = NULL ;
F_4 ( V_20 , V_1 ) . V_5 = NULL ;
F_6 ( V_8 L_4 ,
V_15 >> 10 ,
F_4 ( V_17 , V_1 ) . V_5 -> V_10 >> 10 ) ;
}
#endif
#if V_16 != 0
for ( V_1 = 0 ; V_1 < F_3 () ; ++ V_1 ) {
F_4 ( V_21 , V_1 ) . V_5 =
F_5 ( V_6 , V_7 ) ;
if ( ! F_4 ( V_21 , V_1 ) . V_5 ) {
F_6 ( V_8 L_5 ) ;
return;
}
F_4 ( V_21 , V_1 ) . V_5 -> V_9 =
( void * ) F_11 ( V_1 ) + ( V_22 - V_23 ) ;
F_4 ( V_21 , V_1 ) . V_5 -> V_10 =
V_16 - ( V_22 - V_23 ) ;
F_4 ( V_21 , V_1 ) . V_5 -> V_12 = 0 ;
F_4 ( V_21 , V_1 ) . V_5 -> V_5 = NULL ;
F_4 ( V_24 , V_1 ) . V_5 = NULL ;
F_6 ( V_8 L_6 ,
V_16 >> 10 ,
F_4 ( V_21 , V_1 ) . V_5 -> V_10 >> 10 ) ;
}
#endif
#if V_15 != 0 || V_16 != 0
for ( V_1 = 0 ; V_1 < F_3 () ; ++ V_1 )
F_8 ( & F_4 ( V_25 , V_1 ) ) ;
#endif
}
static void T_1 F_12 ( void )
{
#if V_26 != 0
unsigned int V_1 ;
for ( V_1 = 0 ; V_1 < F_3 () ; ++ V_1 ) {
F_4 ( V_27 , V_1 ) . V_5 =
F_5 ( V_6 , V_7 ) ;
if ( ! F_4 ( V_27 , V_1 ) . V_5 ) {
F_6 ( V_8 L_7 ) ;
return;
}
F_4 ( V_27 , V_1 ) . V_5 -> V_9 =
( void * ) F_13 ( V_1 ) + ( V_28 - V_29 ) ;
F_4 ( V_27 , V_1 ) . V_5 -> V_10 =
V_26 - ( V_28 - V_29 ) ;
F_4 ( V_27 , V_1 ) . V_5 -> V_12 = 0 ;
F_4 ( V_27 , V_1 ) . V_5 -> V_5 = NULL ;
F_4 ( V_30 , V_1 ) . V_5 = NULL ;
F_6 ( V_8 L_8 ,
V_26 >> 10 ,
F_4 ( V_27 , V_1 ) . V_5 -> V_10 >> 10 ) ;
F_8 ( & F_4 ( V_31 , V_1 ) ) ;
}
#endif
}
static T_2 F_14 ( int V_32 , void * V_33 )
{
int V_34 ;
F_6 ( V_35 L_9 ) ;
V_34 = F_15 ( V_36 ) ;
if ( V_34 & 0x1 )
F_6 ( V_35 L_10 ,
F_15 ( V_37 ) , F_15 ( V_38 ) ) ;
if ( V_34 & 0x2 )
F_6 ( V_35 L_11 ,
F_15 ( V_39 ) , F_15 ( V_40 ) ) ;
V_34 = V_34 >> 8 ;
if ( V_34 )
F_6 ( V_35 L_12 ,
V_34 , F_15 ( V_41 + V_34 ) ) ;
F_16 ( L_13 ) ;
return V_42 ;
}
static void T_1 F_17 ( void )
{
#if V_43 != 0
#ifdef F_18
int V_44 ;
V_44 = F_19 ( V_45 , F_14 , 0 , L_14 ,
NULL ) ;
if ( F_20 ( V_44 < 0 ) ) {
F_6 ( V_8 L_15 ) ;
return;
}
#endif
V_46 . V_5 =
F_5 ( V_6 , V_7 ) ;
if ( ! V_46 . V_5 ) {
F_6 ( V_8 L_16 ) ;
return;
}
V_46 . V_5 -> V_9 =
( void * ) V_47 + ( V_48 - V_49 ) ;
V_46 . V_5 -> V_10 =
V_43 - ( V_48 - V_49 ) ;
V_46 . V_5 -> V_12 = 0 ;
V_46 . V_5 -> V_5 = NULL ;
V_50 . V_5 = NULL ;
F_6 ( V_8 L_17 ,
V_43 >> 10 ,
V_46 . V_5 -> V_10 >> 10 ) ;
F_8 ( & V_51 ) ;
#endif
}
static int T_1 F_21 ( void )
{
V_6 = F_22 ( L_18 ,
sizeof( struct V_52 ) ,
0 , V_53 , NULL ) ;
F_1 () ;
F_9 () ;
F_12 () ;
F_17 () ;
return 0 ;
}
static void * F_23 ( T_3 V_10 , struct V_52 * V_54 ,
struct V_52 * V_55 )
{
struct V_52 * V_56 , * V_57 , * V_58 ;
if ( V_10 <= 0 || ! V_54 || ! V_55 )
return NULL ;
V_10 = ( V_10 + 3 ) & ~ 3 ;
V_56 = V_54 -> V_5 ;
V_57 = V_54 ;
while ( V_56 != NULL && V_10 > V_56 -> V_10 ) {
V_57 = V_56 ;
V_56 = V_56 -> V_5 ;
}
if ( ! V_56 )
return NULL ;
if ( V_56 -> V_10 == V_10 ) {
V_57 -> V_5 = V_56 -> V_5 ;
V_58 = V_56 ;
} else {
V_58 = F_5 ( V_6 , V_59 ) ;
if ( ! V_58 )
return NULL ;
V_58 -> V_9 = V_56 -> V_9 ;
V_58 -> V_10 = V_10 ;
V_56 -> V_9 += V_10 ;
V_56 -> V_10 -= V_10 ;
}
V_58 -> V_12 = V_60 -> V_12 ;
V_56 = V_55 -> V_5 ;
V_57 = V_55 ;
while ( V_56 != NULL && V_58 -> V_9 < V_56 -> V_9 ) {
V_57 = V_56 ;
V_56 = V_56 -> V_5 ;
}
V_58 -> V_5 = V_56 ;
V_57 -> V_5 = V_58 ;
return V_58 -> V_9 ;
}
static void * F_24 ( struct V_52 * V_54 ,
struct V_52 * V_55 ,
unsigned long * V_61 )
{
struct V_52 * V_56 , * V_62 ;
if ( ! V_54 || ! V_55 )
return NULL ;
V_62 = V_56 = V_54 -> V_5 ;
while ( V_56 != NULL ) {
if ( V_56 -> V_10 > V_62 -> V_10 )
V_62 = V_56 ;
V_56 = V_56 -> V_5 ;
}
if ( ! V_62 )
return NULL ;
* V_61 = V_62 -> V_10 ;
return F_23 ( * V_61 , V_54 , V_55 ) ;
}
static int F_25 ( const void * V_63 ,
struct V_52 * V_54 ,
struct V_52 * V_55 )
{
struct V_52 * V_56 , * V_57 , * V_58 ;
if ( ! V_54 || ! V_55 )
return - 1 ;
V_56 = V_55 -> V_5 ;
V_57 = V_55 ;
while ( V_56 != NULL && V_56 -> V_9 != V_63 ) {
V_57 = V_56 ;
V_56 = V_56 -> V_5 ;
}
if ( ! V_56 )
return - 1 ;
V_57 -> V_5 = V_56 -> V_5 ;
V_58 = V_56 ;
V_58 -> V_12 = 0 ;
V_56 = V_54 -> V_5 ;
V_57 = V_54 ;
while ( V_56 != NULL && V_63 > V_56 -> V_9 ) {
V_57 = V_56 ;
V_56 = V_56 -> V_5 ;
}
if ( V_57 != V_54 && V_57 -> V_9 + V_57 -> V_10 == V_58 -> V_9 ) {
V_57 -> V_10 += V_58 -> V_10 ;
F_26 ( V_6 , V_58 ) ;
} else {
V_58 -> V_5 = V_57 -> V_5 ;
V_57 -> V_5 = V_58 ;
V_57 = V_58 ;
}
if ( V_56 && V_57 -> V_9 + V_57 -> V_10 == V_56 -> V_9 ) {
V_57 -> V_10 += V_56 -> V_10 ;
V_57 -> V_5 = V_56 -> V_5 ;
F_26 ( V_6 , V_56 ) ;
}
return 0 ;
}
int F_27 ( const void * V_63 )
{
#if V_26 != 0
if ( V_63 >= ( void * ) F_28 ()
&& V_63 < ( void * ) ( F_28 () + V_26 ) )
return F_29 ( V_63 ) ;
else
#endif
#if V_15 != 0
if ( V_63 >= ( void * ) F_30 ()
&& V_63 < ( void * ) ( F_30 () + V_15 ) )
return F_31 ( V_63 ) ;
else
#endif
#if V_16 != 0
if ( V_63 >= ( void * ) F_32 ()
&& V_63 < ( void * ) ( F_32 () + V_16 ) )
return F_33 ( V_63 ) ;
else
#endif
#if V_43 != 0
if ( V_63 >= ( void * ) V_47
&& V_63 < ( void * ) ( V_47 + V_43 ) )
return F_34 ( V_63 ) ;
else
#endif
return - 1 ;
}
void * F_35 ( T_3 V_10 )
{
#if V_15 != 0
unsigned long V_64 ;
void * V_63 ;
unsigned int V_1 ;
V_1 = F_36 () ;
F_37 ( & F_4 ( V_25 , V_1 ) , V_64 ) ;
V_63 = F_23 ( V_10 , & F_4 ( V_17 , V_1 ) ,
& F_4 ( V_20 , V_1 ) ) ;
F_38 ( & F_4 ( V_25 , V_1 ) , V_64 ) ;
F_39 ( L_19 ,
( long unsigned int ) V_63 , V_10 ) ;
return V_63 ;
#else
return NULL ;
#endif
}
int F_31 ( const void * V_63 )
{
#if V_15 != 0
unsigned long V_64 ;
int V_44 ;
unsigned int V_1 ;
V_1 = F_36 () ;
F_37 ( & F_4 ( V_25 , V_1 ) , V_64 ) ;
V_44 = F_25 ( V_63 , & F_4 ( V_17 , V_1 ) ,
& F_4 ( V_20 , V_1 ) ) ;
F_38 ( & F_4 ( V_25 , V_1 ) , V_64 ) ;
return V_44 ;
#else
return - 1 ;
#endif
}
void * F_40 ( T_3 V_10 )
{
#if V_16 != 0
unsigned long V_64 ;
void * V_63 ;
unsigned int V_1 ;
V_1 = F_36 () ;
F_37 ( & F_4 ( V_25 , V_1 ) , V_64 ) ;
V_63 = F_23 ( V_10 , & F_4 ( V_21 , V_1 ) ,
& F_4 ( V_24 , V_1 ) ) ;
F_38 ( & F_4 ( V_25 , V_1 ) , V_64 ) ;
F_39 ( L_20 ,
( long unsigned int ) V_63 , V_10 ) ;
return V_63 ;
#else
return NULL ;
#endif
}
int F_33 ( const void * V_63 )
{
#if V_16 != 0
unsigned long V_64 ;
int V_44 ;
unsigned int V_1 ;
V_1 = F_36 () ;
F_37 ( & F_4 ( V_25 , V_1 ) , V_64 ) ;
V_44 = F_25 ( V_63 , & F_4 ( V_21 , V_1 ) ,
& F_4 ( V_24 , V_1 ) ) ;
F_38 ( & F_4 ( V_25 , V_1 ) , V_64 ) ;
return V_44 ;
#else
return - 1 ;
#endif
}
void * F_41 ( T_3 V_10 )
{
void * V_63 = F_35 ( V_10 ) ;
if ( ! V_63 )
V_63 = F_40 ( V_10 ) ;
return V_63 ;
}
void * F_42 ( T_3 V_10 )
{
void * V_63 = F_41 ( V_10 ) ;
if ( V_63 )
memset ( V_63 , 0x00 , V_10 ) ;
return V_63 ;
}
int F_43 ( const void * V_63 )
{
int V_44 ;
V_44 = F_31 ( V_63 ) ;
if ( V_44 == - 1 )
V_44 = F_33 ( V_63 ) ;
return V_44 ;
}
void * F_44 ( T_3 V_10 )
{
#if V_26 != 0
unsigned long V_64 ;
void * V_63 ;
unsigned int V_1 ;
V_1 = F_36 () ;
F_37 ( & F_4 ( V_31 , V_1 ) , V_64 ) ;
V_63 = F_23 ( V_10 , & F_4 ( V_27 , V_1 ) ,
& F_4 ( V_30 , V_1 ) ) ;
F_38 ( & F_4 ( V_31 , V_1 ) , V_64 ) ;
F_39 ( L_21 ,
( long unsigned int ) V_63 , V_10 ) ;
return V_63 ;
#else
return NULL ;
#endif
}
int F_29 ( const void * V_63 )
{
#if V_26 != 0
unsigned long V_64 ;
int V_44 ;
unsigned int V_1 ;
V_1 = F_36 () ;
F_37 ( & F_4 ( V_31 , V_1 ) , V_64 ) ;
V_44 = F_25 ( V_63 , & F_4 ( V_27 , V_1 ) ,
& F_4 ( V_30 , V_1 ) ) ;
F_38 ( & F_4 ( V_31 , V_1 ) , V_64 ) ;
return V_44 ;
#else
return - 1 ;
#endif
}
void * F_45 ( T_3 V_10 )
{
unsigned long V_64 ;
void * V_63 ;
unsigned int V_1 ;
V_1 = F_36 () ;
F_37 ( & F_4 ( V_14 , V_1 ) , V_64 ) ;
V_63 = F_23 ( V_10 , & F_4 ( V_4 , V_1 ) ,
& F_4 ( V_13 , V_1 ) ) ;
F_38 ( & F_4 ( V_14 , V_1 ) , V_64 ) ;
return V_63 ;
}
void * F_46 ( T_3 * V_61 )
{
unsigned long V_64 ;
void * V_63 ;
unsigned int V_1 ;
V_1 = F_36 () ;
F_37 ( & F_4 ( V_14 , V_1 ) , V_64 ) ;
V_63 = F_24 ( & F_4 ( V_4 , V_1 ) ,
& F_4 ( V_13 , V_1 ) , V_61 ) ;
F_38 ( & F_4 ( V_14 , V_1 ) , V_64 ) ;
return V_63 ;
}
int F_47 ( const void * V_63 )
{
unsigned long V_64 ;
int V_44 ;
unsigned int V_1 ;
V_1 = F_36 () ;
F_37 ( & F_4 ( V_14 , V_1 ) , V_64 ) ;
V_44 = F_25 ( V_63 , & F_4 ( V_4 , V_1 ) ,
& F_4 ( V_13 , V_1 ) ) ;
F_38 ( & F_4 ( V_14 , V_1 ) , V_64 ) ;
return V_44 ;
}
void * F_48 ( T_3 V_10 )
{
#if V_43 != 0
unsigned long V_64 ;
void * V_63 ;
F_37 ( & V_51 , V_64 ) ;
V_63 = F_23 ( V_10 , & V_46 ,
& V_50 ) ;
F_38 ( & V_51 , V_64 ) ;
F_39 ( L_22 ,
( long unsigned int ) V_63 , V_10 ) ;
return V_63 ;
#else
return NULL ;
#endif
}
void * F_49 ( T_3 V_10 )
{
void * V_63 = F_48 ( V_10 ) ;
if ( V_63 )
memset ( V_63 , 0x00 , V_10 ) ;
return V_63 ;
}
int F_34 ( const void * V_63 )
{
#if V_43 != 0
unsigned long V_64 ;
int V_44 ;
F_37 ( & V_51 , V_64 ) ;
V_44 = F_25 ( V_63 , & V_46 ,
& V_50 ) ;
F_38 ( & V_51 , V_64 ) ;
return V_44 ;
#else
return - 1 ;
#endif
}
int F_50 ( const void * V_63 )
{
struct V_65 * V_66 , * * V_67 ;
struct V_68 * V_69 = V_60 -> V_69 ;
int V_44 = - 1 ;
for ( V_67 = & V_69 -> V_70 . V_71 ; * V_67 ; V_67 = & ( * V_67 ) -> V_5 )
if ( ( * V_67 ) -> V_63 == V_63 ) {
V_66 = * V_67 ;
V_44 = F_27 ( V_63 ) ;
* V_67 = V_66 -> V_5 ;
F_51 ( V_66 ) ;
break;
}
return V_44 ;
}
void * F_52 ( T_3 V_10 , unsigned long V_64 )
{
void * V_63 = NULL ;
struct V_65 * V_66 = NULL ;
struct V_68 * V_69 = V_60 -> V_69 ;
V_66 = F_53 ( sizeof( struct V_65 ) , V_7 ) ;
if ( ! V_66 )
return NULL ;
if ( V_64 & V_72 )
V_63 = F_44 ( V_10 ) ;
if ( V_63 == NULL && ( V_64 & V_73 ) )
V_63 = F_35 ( V_10 ) ;
if ( V_63 == NULL && ( V_64 & V_74 ) )
V_63 = F_40 ( V_10 ) ;
if ( V_63 == NULL && ( V_64 & V_75 ) )
V_63 = F_48 ( V_10 ) ;
if ( V_63 == NULL ) {
F_51 ( V_66 ) ;
return NULL ;
}
V_66 -> V_63 = V_63 ;
V_66 -> V_76 = V_10 ;
V_66 -> V_5 = V_69 -> V_70 . V_71 ;
V_69 -> V_70 . V_71 = V_66 ;
return V_63 ;
}
static int F_54 ( struct V_77 * V_78 , const char * V_79 ,
struct V_52 * V_54 ,
struct V_52 * V_55 )
{
struct V_52 * V_56 ;
if ( ! V_54 || ! V_55 )
return - 1 ;
F_55 ( V_78 , L_23 , V_79 ) ;
V_56 = V_55 -> V_5 ;
while ( V_56 != NULL ) {
F_55 ( V_78 , L_24 ,
V_56 -> V_9 , V_56 -> V_9 + V_56 -> V_10 ,
V_56 -> V_10 , V_56 -> V_12 , L_25 ) ;
V_56 = V_56 -> V_5 ;
}
V_56 = V_54 -> V_5 ;
while ( V_56 != NULL ) {
F_55 ( V_78 , L_24 ,
V_56 -> V_9 , V_56 -> V_9 + V_56 -> V_10 ,
V_56 -> V_10 , V_56 -> V_12 , L_26 ) ;
V_56 = V_56 -> V_5 ;
}
return 0 ;
}
static int F_56 ( struct V_77 * V_78 , void * V_80 )
{
unsigned int V_1 ;
for ( V_1 = 0 ; V_1 < F_3 () ; ++ V_1 ) {
if ( F_54 ( V_78 , L_27 ,
& F_4 ( V_4 , V_1 ) , & F_4 ( V_13 , V_1 ) ) )
goto V_81;
#if V_15 != 0
if ( F_54 ( V_78 , L_28 ,
& F_4 ( V_17 , V_1 ) ,
& F_4 ( V_20 , V_1 ) ) )
goto V_81;
#endif
#if V_16 != 0
if ( F_54 ( V_78 , L_29 ,
& F_4 ( V_21 , V_1 ) ,
& F_4 ( V_24 , V_1 ) ) )
goto V_81;
#endif
#if V_26 != 0
if ( F_54 ( V_78 , L_30 ,
& F_4 ( V_27 , V_1 ) ,
& F_4 ( V_30 , V_1 ) ) )
goto V_81;
#endif
}
#if V_43 != 0
if ( F_54 ( V_78 , L_31 , & V_46 , & V_50 ) )
goto V_81;
#endif
V_81:
return 0 ;
}
static int F_57 ( struct V_82 * V_82 , struct V_83 * V_83 )
{
return F_58 ( V_83 , F_56 , NULL ) ;
}
static int T_1 F_59 ( void )
{
struct V_84 * V_85 ;
V_85 = F_60 ( L_32 , V_86 , NULL , & V_87 ) ;
if ( ! V_85 ) {
F_6 ( V_88 L_33 ) ;
return - 1 ;
}
return 0 ;
}
