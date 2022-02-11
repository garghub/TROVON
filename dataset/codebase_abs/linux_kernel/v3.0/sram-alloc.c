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
static void T_1 F_14 ( void )
{
#if V_32 != 0
V_33 . V_5 =
F_5 ( V_6 , V_7 ) ;
if ( ! V_33 . V_5 ) {
F_6 ( V_8 L_9 ) ;
return;
}
V_33 . V_5 -> V_9 =
( void * ) V_34 + ( V_35 - V_36 ) ;
V_33 . V_5 -> V_10 =
V_32 - ( V_35 - V_36 ) ;
V_33 . V_5 -> V_12 = 0 ;
V_33 . V_5 -> V_5 = NULL ;
V_37 . V_5 = NULL ;
F_6 ( V_8 L_10 ,
V_32 >> 10 ,
V_33 . V_5 -> V_10 >> 10 ) ;
F_8 ( & V_38 ) ;
#endif
}
static int T_1 F_15 ( void )
{
V_6 = F_16 ( L_11 ,
sizeof( struct V_39 ) ,
0 , V_40 , NULL ) ;
F_1 () ;
F_9 () ;
F_12 () ;
F_14 () ;
return 0 ;
}
static void * F_17 ( T_2 V_10 , struct V_39 * V_41 ,
struct V_39 * V_42 )
{
struct V_39 * V_43 , * V_44 , * V_45 ;
if ( V_10 <= 0 || ! V_41 || ! V_42 )
return NULL ;
V_10 = ( V_10 + 3 ) & ~ 3 ;
V_43 = V_41 -> V_5 ;
V_44 = V_41 ;
while ( V_43 != NULL && V_10 > V_43 -> V_10 ) {
V_44 = V_43 ;
V_43 = V_43 -> V_5 ;
}
if ( ! V_43 )
return NULL ;
if ( V_43 -> V_10 == V_10 ) {
V_44 -> V_5 = V_43 -> V_5 ;
V_45 = V_43 ;
} else {
V_45 = F_5 ( V_6 , V_46 ) ;
if ( ! V_45 )
return NULL ;
V_45 -> V_9 = V_43 -> V_9 ;
V_45 -> V_10 = V_10 ;
V_43 -> V_9 += V_10 ;
V_43 -> V_10 -= V_10 ;
}
V_45 -> V_12 = V_47 -> V_12 ;
V_43 = V_42 -> V_5 ;
V_44 = V_42 ;
while ( V_43 != NULL && V_45 -> V_9 < V_43 -> V_9 ) {
V_44 = V_43 ;
V_43 = V_43 -> V_5 ;
}
V_45 -> V_5 = V_43 ;
V_44 -> V_5 = V_45 ;
return V_45 -> V_9 ;
}
static void * F_18 ( struct V_39 * V_41 ,
struct V_39 * V_42 ,
unsigned long * V_48 )
{
struct V_39 * V_43 , * V_49 ;
if ( ! V_41 || ! V_42 )
return NULL ;
V_49 = V_43 = V_41 -> V_5 ;
while ( V_43 != NULL ) {
if ( V_43 -> V_10 > V_49 -> V_10 )
V_49 = V_43 ;
V_43 = V_43 -> V_5 ;
}
if ( ! V_49 )
return NULL ;
* V_48 = V_49 -> V_10 ;
return F_17 ( * V_48 , V_41 , V_42 ) ;
}
static int F_19 ( const void * V_50 ,
struct V_39 * V_41 ,
struct V_39 * V_42 )
{
struct V_39 * V_43 , * V_44 , * V_45 ;
if ( ! V_41 || ! V_42 )
return - 1 ;
V_43 = V_42 -> V_5 ;
V_44 = V_42 ;
while ( V_43 != NULL && V_43 -> V_9 != V_50 ) {
V_44 = V_43 ;
V_43 = V_43 -> V_5 ;
}
if ( ! V_43 )
return - 1 ;
V_44 -> V_5 = V_43 -> V_5 ;
V_45 = V_43 ;
V_45 -> V_12 = 0 ;
V_43 = V_41 -> V_5 ;
V_44 = V_41 ;
while ( V_43 != NULL && V_50 > V_43 -> V_9 ) {
V_44 = V_43 ;
V_43 = V_43 -> V_5 ;
}
if ( V_44 != V_41 && V_44 -> V_9 + V_44 -> V_10 == V_45 -> V_9 ) {
V_44 -> V_10 += V_45 -> V_10 ;
F_20 ( V_6 , V_45 ) ;
} else {
V_45 -> V_5 = V_44 -> V_5 ;
V_44 -> V_5 = V_45 ;
V_44 = V_45 ;
}
if ( V_43 && V_44 -> V_9 + V_44 -> V_10 == V_43 -> V_9 ) {
V_44 -> V_10 += V_43 -> V_10 ;
V_44 -> V_5 = V_43 -> V_5 ;
F_20 ( V_6 , V_43 ) ;
}
return 0 ;
}
int F_21 ( const void * V_50 )
{
#if V_26 != 0
if ( V_50 >= ( void * ) F_22 ()
&& V_50 < ( void * ) ( F_22 () + V_26 ) )
return F_23 ( V_50 ) ;
else
#endif
#if V_15 != 0
if ( V_50 >= ( void * ) F_24 ()
&& V_50 < ( void * ) ( F_24 () + V_15 ) )
return F_25 ( V_50 ) ;
else
#endif
#if V_16 != 0
if ( V_50 >= ( void * ) F_26 ()
&& V_50 < ( void * ) ( F_26 () + V_16 ) )
return F_27 ( V_50 ) ;
else
#endif
#if V_32 != 0
if ( V_50 >= ( void * ) V_34
&& V_50 < ( void * ) ( V_34 + V_32 ) )
return F_28 ( V_50 ) ;
else
#endif
return - 1 ;
}
void * F_29 ( T_2 V_10 )
{
#if V_15 != 0
unsigned long V_51 ;
void * V_50 ;
unsigned int V_1 ;
V_1 = F_30 () ;
F_31 ( & F_4 ( V_25 , V_1 ) , V_51 ) ;
V_50 = F_17 ( V_10 , & F_4 ( V_17 , V_1 ) ,
& F_4 ( V_20 , V_1 ) ) ;
F_32 ( & F_4 ( V_25 , V_1 ) , V_51 ) ;
F_33 ( L_12 ,
( long unsigned int ) V_50 , V_10 ) ;
return V_50 ;
#else
return NULL ;
#endif
}
int F_25 ( const void * V_50 )
{
#if V_15 != 0
unsigned long V_51 ;
int V_52 ;
unsigned int V_1 ;
V_1 = F_30 () ;
F_31 ( & F_4 ( V_25 , V_1 ) , V_51 ) ;
V_52 = F_19 ( V_50 , & F_4 ( V_17 , V_1 ) ,
& F_4 ( V_20 , V_1 ) ) ;
F_32 ( & F_4 ( V_25 , V_1 ) , V_51 ) ;
return V_52 ;
#else
return - 1 ;
#endif
}
void * F_34 ( T_2 V_10 )
{
#if V_16 != 0
unsigned long V_51 ;
void * V_50 ;
unsigned int V_1 ;
V_1 = F_30 () ;
F_31 ( & F_4 ( V_25 , V_1 ) , V_51 ) ;
V_50 = F_17 ( V_10 , & F_4 ( V_21 , V_1 ) ,
& F_4 ( V_24 , V_1 ) ) ;
F_32 ( & F_4 ( V_25 , V_1 ) , V_51 ) ;
F_33 ( L_13 ,
( long unsigned int ) V_50 , V_10 ) ;
return V_50 ;
#else
return NULL ;
#endif
}
int F_27 ( const void * V_50 )
{
#if V_16 != 0
unsigned long V_51 ;
int V_52 ;
unsigned int V_1 ;
V_1 = F_30 () ;
F_31 ( & F_4 ( V_25 , V_1 ) , V_51 ) ;
V_52 = F_19 ( V_50 , & F_4 ( V_21 , V_1 ) ,
& F_4 ( V_24 , V_1 ) ) ;
F_32 ( & F_4 ( V_25 , V_1 ) , V_51 ) ;
return V_52 ;
#else
return - 1 ;
#endif
}
void * F_35 ( T_2 V_10 )
{
void * V_50 = F_29 ( V_10 ) ;
if ( ! V_50 )
V_50 = F_34 ( V_10 ) ;
return V_50 ;
}
void * F_36 ( T_2 V_10 )
{
void * V_50 = F_35 ( V_10 ) ;
if ( V_50 )
memset ( V_50 , 0x00 , V_10 ) ;
return V_50 ;
}
int F_37 ( const void * V_50 )
{
int V_52 ;
V_52 = F_25 ( V_50 ) ;
if ( V_52 == - 1 )
V_52 = F_27 ( V_50 ) ;
return V_52 ;
}
void * F_38 ( T_2 V_10 )
{
#if V_26 != 0
unsigned long V_51 ;
void * V_50 ;
unsigned int V_1 ;
V_1 = F_30 () ;
F_31 ( & F_4 ( V_31 , V_1 ) , V_51 ) ;
V_50 = F_17 ( V_10 , & F_4 ( V_27 , V_1 ) ,
& F_4 ( V_30 , V_1 ) ) ;
F_32 ( & F_4 ( V_31 , V_1 ) , V_51 ) ;
F_33 ( L_14 ,
( long unsigned int ) V_50 , V_10 ) ;
return V_50 ;
#else
return NULL ;
#endif
}
int F_23 ( const void * V_50 )
{
#if V_26 != 0
unsigned long V_51 ;
int V_52 ;
unsigned int V_1 ;
V_1 = F_30 () ;
F_31 ( & F_4 ( V_31 , V_1 ) , V_51 ) ;
V_52 = F_19 ( V_50 , & F_4 ( V_27 , V_1 ) ,
& F_4 ( V_30 , V_1 ) ) ;
F_32 ( & F_4 ( V_31 , V_1 ) , V_51 ) ;
return V_52 ;
#else
return - 1 ;
#endif
}
void * F_39 ( T_2 V_10 )
{
unsigned long V_51 ;
void * V_50 ;
unsigned int V_1 ;
V_1 = F_30 () ;
F_31 ( & F_4 ( V_14 , V_1 ) , V_51 ) ;
V_50 = F_17 ( V_10 , & F_4 ( V_4 , V_1 ) ,
& F_4 ( V_13 , V_1 ) ) ;
F_32 ( & F_4 ( V_14 , V_1 ) , V_51 ) ;
return V_50 ;
}
void * F_40 ( T_2 * V_48 )
{
unsigned long V_51 ;
void * V_50 ;
unsigned int V_1 ;
V_1 = F_30 () ;
F_31 ( & F_4 ( V_14 , V_1 ) , V_51 ) ;
V_50 = F_18 ( & F_4 ( V_4 , V_1 ) ,
& F_4 ( V_13 , V_1 ) , V_48 ) ;
F_32 ( & F_4 ( V_14 , V_1 ) , V_51 ) ;
return V_50 ;
}
int F_41 ( const void * V_50 )
{
unsigned long V_51 ;
int V_52 ;
unsigned int V_1 ;
V_1 = F_30 () ;
F_31 ( & F_4 ( V_14 , V_1 ) , V_51 ) ;
V_52 = F_19 ( V_50 , & F_4 ( V_4 , V_1 ) ,
& F_4 ( V_13 , V_1 ) ) ;
F_32 ( & F_4 ( V_14 , V_1 ) , V_51 ) ;
return V_52 ;
}
void * F_42 ( T_2 V_10 )
{
#if V_32 != 0
unsigned long V_51 ;
void * V_50 ;
F_31 ( & V_38 , V_51 ) ;
V_50 = F_17 ( V_10 , & V_33 ,
& V_37 ) ;
F_32 ( & V_38 , V_51 ) ;
F_33 ( L_15 ,
( long unsigned int ) V_50 , V_10 ) ;
return V_50 ;
#else
return NULL ;
#endif
}
void * F_43 ( T_2 V_10 )
{
void * V_50 = F_42 ( V_10 ) ;
if ( V_50 )
memset ( V_50 , 0x00 , V_10 ) ;
return V_50 ;
}
int F_28 ( const void * V_50 )
{
#if V_32 != 0
unsigned long V_51 ;
int V_52 ;
F_31 ( & V_38 , V_51 ) ;
V_52 = F_19 ( V_50 , & V_33 ,
& V_37 ) ;
F_32 ( & V_38 , V_51 ) ;
return V_52 ;
#else
return - 1 ;
#endif
}
int F_44 ( const void * V_50 )
{
struct V_53 * V_54 , * * V_55 ;
struct V_56 * V_57 = V_47 -> V_57 ;
int V_52 = - 1 ;
for ( V_55 = & V_57 -> V_58 . V_59 ; * V_55 ; V_55 = & ( * V_55 ) -> V_5 )
if ( ( * V_55 ) -> V_50 == V_50 ) {
V_54 = * V_55 ;
V_52 = F_21 ( V_50 ) ;
* V_55 = V_54 -> V_5 ;
F_45 ( V_54 ) ;
break;
}
return V_52 ;
}
void * F_46 ( T_2 V_10 , unsigned long V_51 )
{
void * V_50 = NULL ;
struct V_53 * V_54 = NULL ;
struct V_56 * V_57 = V_47 -> V_57 ;
V_54 = F_47 ( sizeof( struct V_53 ) , V_7 ) ;
if ( ! V_54 )
return NULL ;
if ( V_51 & V_60 )
V_50 = F_38 ( V_10 ) ;
if ( V_50 == NULL && ( V_51 & V_61 ) )
V_50 = F_29 ( V_10 ) ;
if ( V_50 == NULL && ( V_51 & V_62 ) )
V_50 = F_34 ( V_10 ) ;
if ( V_50 == NULL && ( V_51 & V_63 ) )
V_50 = F_42 ( V_10 ) ;
if ( V_50 == NULL ) {
F_45 ( V_54 ) ;
return NULL ;
}
V_54 -> V_50 = V_50 ;
V_54 -> V_64 = V_10 ;
V_54 -> V_5 = V_57 -> V_58 . V_59 ;
V_57 -> V_58 . V_59 = V_54 ;
return V_50 ;
}
static int F_48 ( struct V_65 * V_66 , const char * V_67 ,
struct V_39 * V_41 ,
struct V_39 * V_42 )
{
struct V_39 * V_43 ;
if ( ! V_41 || ! V_42 )
return - 1 ;
F_49 ( V_66 , L_16 , V_67 ) ;
V_43 = V_42 -> V_5 ;
while ( V_43 != NULL ) {
F_49 ( V_66 , L_17 ,
V_43 -> V_9 , V_43 -> V_9 + V_43 -> V_10 ,
V_43 -> V_10 , V_43 -> V_12 , L_18 ) ;
V_43 = V_43 -> V_5 ;
}
V_43 = V_41 -> V_5 ;
while ( V_43 != NULL ) {
F_49 ( V_66 , L_17 ,
V_43 -> V_9 , V_43 -> V_9 + V_43 -> V_10 ,
V_43 -> V_10 , V_43 -> V_12 , L_19 ) ;
V_43 = V_43 -> V_5 ;
}
return 0 ;
}
static int F_50 ( struct V_65 * V_66 , void * V_68 )
{
unsigned int V_1 ;
for ( V_1 = 0 ; V_1 < F_3 () ; ++ V_1 ) {
if ( F_48 ( V_66 , L_20 ,
& F_4 ( V_4 , V_1 ) , & F_4 ( V_13 , V_1 ) ) )
goto V_69;
#if V_15 != 0
if ( F_48 ( V_66 , L_21 ,
& F_4 ( V_17 , V_1 ) ,
& F_4 ( V_20 , V_1 ) ) )
goto V_69;
#endif
#if V_16 != 0
if ( F_48 ( V_66 , L_22 ,
& F_4 ( V_21 , V_1 ) ,
& F_4 ( V_24 , V_1 ) ) )
goto V_69;
#endif
#if V_26 != 0
if ( F_48 ( V_66 , L_23 ,
& F_4 ( V_27 , V_1 ) ,
& F_4 ( V_30 , V_1 ) ) )
goto V_69;
#endif
}
#if V_32 != 0
if ( F_48 ( V_66 , L_24 , & V_33 , & V_37 ) )
goto V_69;
#endif
V_69:
return 0 ;
}
static int F_51 ( struct V_70 * V_70 , struct V_71 * V_71 )
{
return F_52 ( V_71 , F_50 , NULL ) ;
}
static int T_1 F_53 ( void )
{
struct V_72 * V_73 ;
V_73 = F_54 ( L_25 , V_74 , NULL , & V_75 ) ;
if ( ! V_73 ) {
F_6 ( V_76 L_26 ) ;
return - 1 ;
}
return 0 ;
}
