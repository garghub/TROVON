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
T_4 V_22 ;
if ( V_17 > V_19 )
V_17 = V_19 ;
V_22 = V_17 ;
if ( F_10 ( & V_8 , V_16 , V_17 ) )
return - V_23 ;
V_8 [ V_17 - 1 ] = 0 ;
V_21 = F_11 ( V_8 ) ;
V_5 = F_6 ( V_21 ) ;
if ( V_5 ) {
F_3 ( L_4 , V_7 , V_21 ) ;
return V_5 ;
}
* V_18 += V_22 ;
return V_22 ;
}
static int F_12 ( void * V_24 , T_6 V_25 )
{
struct V_26 * V_27 = (struct V_26 * ) V_24 ;
if ( V_25 >= V_28 || ! F_13 ( V_25 ) ) {
F_3 ( L_5 , V_7 , V_25 ) ;
return - V_13 ;
}
V_27 -> V_29 = V_25 ;
return 0 ;
}
static void F_14 ( void * V_30 )
{
asm volatile("int $18");
}
static void F_15 ( void )
{
T_6 V_31 = 0 ;
unsigned int V_1 = V_32 . V_29 ;
T_7 V_33 = V_32 . V_34 ;
if ( V_32 . V_35 )
V_32 . V_36 |= V_37 ;
if ( V_12 == V_38 ) {
F_16 ( & V_32 ) ;
return;
}
V_31 = V_39 | V_40 ;
if ( ! ( V_32 . V_36 & V_41 ) )
V_31 |= V_42 ;
F_17 () ;
if ( ! F_13 ( V_1 ) )
goto V_5;
F_1 ( V_1 , true ) ;
F_5 ( V_1 , V_43 ,
( T_1 ) V_31 , ( T_1 ) ( V_31 >> 32 ) ) ;
F_5 ( V_1 , F_18 ( V_33 ) ,
( T_1 ) V_32 . V_36 , ( T_1 ) ( V_32 . V_36 >> 32 ) ) ;
F_5 ( V_1 , F_19 ( V_33 ) ,
( T_1 ) V_32 . V_44 , ( T_1 ) ( V_32 . V_44 >> 32 ) ) ;
F_5 ( V_1 , F_20 ( V_33 ) ,
( T_1 ) V_32 . V_35 , ( T_1 ) ( V_32 . V_35 >> 32 ) ) ;
F_1 ( V_1 , false ) ;
F_21 ( V_1 , F_14 , NULL , 0 ) ;
V_5:
F_22 () ;
}
static int F_23 ( void * V_24 , T_6 V_25 )
{
struct V_26 * V_27 = (struct V_26 * ) V_24 ;
if ( V_25 >= V_45 ) {
F_3 ( L_6 , V_25 ) ;
return - V_13 ;
}
V_27 -> V_34 = V_25 ;
F_15 () ;
return 0 ;
}
static T_2
F_24 ( struct V_14 * V_15 , char T_3 * V_16 ,
T_4 V_17 , T_5 * V_18 )
{
return F_8 ( V_16 , V_17 , V_18 ,
V_46 , strlen ( V_46 ) ) ;
}
static int T_8 F_25 ( void )
{
int V_9 ;
T_6 V_47 ;
F_26 ( V_48 , V_47 ) ;
V_45 = V_47 & V_49 ;
V_50 = F_27 ( L_7 , NULL ) ;
if ( ! V_50 )
return - V_13 ;
for ( V_9 = 0 ; V_9 < F_28 ( V_51 ) ; V_9 ++ ) {
V_51 [ V_9 ] . V_52 = F_29 ( V_51 [ V_9 ] . V_53 ,
V_51 [ V_9 ] . V_54 ,
V_50 ,
& V_32 ,
V_51 [ V_9 ] . V_55 ) ;
if ( ! V_51 [ V_9 ] . V_52 )
goto V_56;
}
return 0 ;
V_56:
while ( -- V_9 >= 0 )
F_30 ( V_51 [ V_9 ] . V_52 ) ;
F_30 ( V_50 ) ;
V_50 = NULL ;
return - V_57 ;
}
static void T_9 F_31 ( void )
{
int V_9 ;
for ( V_9 = 0 ; V_9 < F_28 ( V_51 ) ; V_9 ++ )
F_30 ( V_51 [ V_9 ] . V_52 ) ;
memset ( & V_51 , 0 , sizeof( V_51 ) ) ;
F_30 ( V_50 ) ;
V_50 = NULL ;
}
