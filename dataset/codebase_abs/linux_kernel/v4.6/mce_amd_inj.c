static int F_1 ( unsigned int V_1 , bool V_2 )
{
T_1 V_3 , V_4 ;
int V_5 ;
V_5 = F_2 ( V_1 , V_6 , & V_3 , & V_4 ) ;
if ( V_5 ) {
F_3 ( L_1 , V_7 ) ;
return V_5 ;
}
V_2 ? ( V_3 |= F_4 ( 18 ) ) : ( V_3 &= ~ F_4 ( 18 ) ) ;
V_5 = F_5 ( V_1 , V_6 , V_3 , V_4 ) ;
if ( V_5 )
F_3 ( L_2 , V_7 ) ;
return V_5 ;
}
static int F_6 ( const char * V_8 )
{
int V_9 ;
for ( V_9 = 0 ; V_9 < V_10 ; V_9 ++ ) {
if ( ! strncmp ( V_11 [ V_9 ] , V_8 , strlen ( V_11 [ V_9 ] ) ) ) {
V_12 = V_9 ;
return 0 ;
}
}
return - V_13 ;
}
static T_2 F_7 ( struct V_14 * V_15 , char T_3 * V_16 ,
T_4 V_17 , T_5 * V_18 )
{
char V_8 [ V_19 ] ;
int V_20 ;
V_20 = sprintf ( V_8 , L_3 , V_11 [ V_12 ] ) ;
return F_8 ( V_16 , V_17 , V_18 , V_8 , V_20 ) ;
}
static T_2 F_9 ( struct V_14 * V_15 , const char T_3 * V_16 ,
T_4 V_17 , T_5 * V_18 )
{
char V_8 [ V_19 ] , * V_21 ;
int V_5 ;
if ( V_17 > V_19 )
return - V_13 ;
if ( F_10 ( & V_8 , V_16 , V_17 ) )
return - V_22 ;
V_8 [ V_17 - 1 ] = 0 ;
V_21 = F_11 ( V_8 ) ;
V_5 = F_6 ( V_21 ) ;
if ( V_5 ) {
F_3 ( L_4 , V_7 , V_21 ) ;
return V_5 ;
}
* V_18 += V_17 ;
return V_17 ;
}
static int F_12 ( void * V_23 , T_6 V_24 )
{
struct V_25 * V_26 = (struct V_25 * ) V_23 ;
if ( V_24 >= V_27 || ! F_13 ( V_24 ) ) {
F_3 ( L_5 , V_7 , V_24 ) ;
return - V_13 ;
}
V_26 -> V_28 = V_24 ;
return 0 ;
}
static void F_14 ( void * V_29 )
{
asm volatile("int $18");
}
static void F_15 ( void * V_29 )
{
asm volatile("int %0" :: "i" (DEFERRED_ERROR_VECTOR));
}
static void F_16 ( void * V_29 )
{
asm volatile("int %0" :: "i" (THRESHOLD_APIC_VECTOR));
}
static T_1 F_17 ( int V_30 )
{
struct V_31 * V_32 = & V_33 ;
T_1 V_34 ;
V_34 = ( V_32 -> V_35 * V_36 ) / F_18 () ;
return V_34 * V_30 ;
}
static void F_19 ( T_7 V_37 )
{
struct V_38 * V_39 = F_20 ( V_37 ) -> V_40 ;
T_1 V_24 ;
int V_5 ;
if ( ! V_39 )
return;
V_5 = F_21 ( V_39 , V_41 , & V_24 ) ;
if ( V_5 ) {
F_3 ( L_6 ,
V_7 , F_22 ( V_39 -> V_42 ) , V_41 ) ;
return;
}
if ( V_24 & F_4 ( 27 ) )
return;
F_3 ( L_7 ,
V_7 ) ;
V_24 |= F_4 ( 27 ) ;
V_5 = F_23 ( V_39 , V_41 , V_24 ) ;
if ( V_5 )
F_3 ( L_8 ,
V_7 , F_22 ( V_39 -> V_42 ) , V_41 ) ;
}
static void F_24 ( void )
{
T_6 V_43 = 0 ;
unsigned int V_1 = V_44 . V_28 ;
T_8 V_45 = V_44 . V_46 ;
if ( V_44 . V_40 )
V_44 . V_47 |= V_48 ;
if ( V_12 == V_49 ) {
F_25 ( & V_44 ) ;
return;
}
V_43 = V_50 | V_51 ;
if ( ! ( V_44 . V_47 & V_52 ) )
V_43 |= V_53 ;
if ( V_12 == V_54 ) {
V_44 . V_47 |= V_55 ;
V_44 . V_47 |= ( V_44 . V_47 & ~ V_56 ) ;
}
if ( F_26 ( V_57 ) && V_45 == 4 ) {
F_19 ( F_27 ( V_1 ) ) ;
V_1 = F_17 ( F_27 ( V_1 ) ) ;
}
F_28 () ;
if ( ! F_13 ( V_1 ) )
goto V_5;
F_1 ( V_1 , true ) ;
F_5 ( V_1 , V_58 ,
( T_1 ) V_43 , ( T_1 ) ( V_43 >> 32 ) ) ;
F_5 ( V_1 , F_29 ( V_45 ) ,
( T_1 ) V_44 . V_47 , ( T_1 ) ( V_44 . V_47 >> 32 ) ) ;
F_5 ( V_1 , F_30 ( V_45 ) ,
( T_1 ) V_44 . V_59 , ( T_1 ) ( V_44 . V_59 >> 32 ) ) ;
F_5 ( V_1 , F_31 ( V_45 ) ,
( T_1 ) V_44 . V_40 , ( T_1 ) ( V_44 . V_40 >> 32 ) ) ;
F_1 ( V_1 , false ) ;
switch ( V_12 ) {
case V_54 :
F_32 ( V_1 , F_15 , NULL , 0 ) ;
break;
case V_60 :
F_32 ( V_1 , F_16 , NULL , 0 ) ;
break;
default:
F_32 ( V_1 , F_14 , NULL , 0 ) ;
}
V_5:
F_33 () ;
}
static int F_34 ( void * V_23 , T_6 V_24 )
{
struct V_25 * V_26 = (struct V_25 * ) V_23 ;
if ( V_24 >= V_61 ) {
F_3 ( L_9 , V_24 ) ;
return - V_13 ;
}
V_26 -> V_46 = V_24 ;
F_24 () ;
return 0 ;
}
static T_2
F_35 ( struct V_14 * V_15 , char T_3 * V_16 ,
T_4 V_17 , T_5 * V_18 )
{
return F_8 ( V_16 , V_17 , V_18 ,
V_62 , strlen ( V_62 ) ) ;
}
static int T_9 F_36 ( void )
{
int V_9 ;
T_6 V_63 ;
F_37 ( V_64 , V_63 ) ;
V_61 = V_63 & V_65 ;
V_66 = F_38 ( L_10 , NULL ) ;
if ( ! V_66 )
return - V_13 ;
for ( V_9 = 0 ; V_9 < F_39 ( V_67 ) ; V_9 ++ ) {
V_67 [ V_9 ] . V_68 = F_40 ( V_67 [ V_9 ] . V_69 ,
V_67 [ V_9 ] . V_70 ,
V_66 ,
& V_44 ,
V_67 [ V_9 ] . V_71 ) ;
if ( ! V_67 [ V_9 ] . V_68 )
goto V_72;
}
return 0 ;
V_72:
while ( -- V_9 >= 0 )
F_41 ( V_67 [ V_9 ] . V_68 ) ;
F_41 ( V_66 ) ;
V_66 = NULL ;
return - V_73 ;
}
static void T_10 F_42 ( void )
{
int V_9 ;
for ( V_9 = 0 ; V_9 < F_39 ( V_67 ) ; V_9 ++ )
F_41 ( V_67 [ V_9 ] . V_68 ) ;
memset ( & V_67 , 0 , sizeof( V_67 ) ) ;
F_41 ( V_66 ) ;
V_66 = NULL ;
}
