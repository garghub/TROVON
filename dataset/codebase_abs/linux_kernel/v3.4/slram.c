static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
T_1 * V_5 = V_2 -> V_5 ;
memset ( V_5 -> V_6 + V_4 -> V_7 , 0xff , V_4 -> V_8 ) ;
V_4 -> V_9 = V_10 ;
F_2 ( V_4 ) ;
return ( 0 ) ;
}
static int F_3 ( struct V_1 * V_2 , T_2 V_11 , T_3 V_8 ,
T_3 * V_12 , void * * V_13 , T_4 * V_14 )
{
T_1 * V_5 = V_2 -> V_5 ;
* V_13 = V_5 -> V_6 + V_11 ;
* V_12 = V_8 ;
return ( 0 ) ;
}
static int F_4 ( struct V_1 * V_2 , T_2 V_11 , T_3 V_8 )
{
return 0 ;
}
static int F_5 ( struct V_1 * V_2 , T_2 V_11 , T_3 V_8 ,
T_3 * V_12 , T_5 * V_15 )
{
T_1 * V_5 = V_2 -> V_5 ;
memcpy ( V_15 , V_5 -> V_6 + V_11 , V_8 ) ;
* V_12 = V_8 ;
return ( 0 ) ;
}
static int F_6 ( struct V_1 * V_2 , T_2 V_16 , T_3 V_8 ,
T_3 * V_12 , const T_5 * V_15 )
{
T_1 * V_5 = V_2 -> V_5 ;
memcpy ( V_5 -> V_6 + V_16 , V_15 , V_8 ) ;
* V_12 = V_8 ;
return ( 0 ) ;
}
static int F_7 ( char * V_17 , unsigned long V_6 , unsigned long V_18 )
{
T_6 * * V_19 ;
V_19 = & V_20 ;
while ( * V_19 ) {
V_19 = & ( * V_19 ) -> V_21 ;
}
* V_19 = F_8 ( sizeof( T_6 ) , V_22 ) ;
if ( ! ( * V_19 ) ) {
F_9 ( L_1 ) ;
return ( - V_23 ) ;
}
( * V_19 ) -> V_24 = F_10 ( sizeof( struct V_1 ) , V_22 ) ;
( * V_19 ) -> V_21 = NULL ;
if ( ( * V_19 ) -> V_24 ) {
( * V_19 ) -> V_24 -> V_5 =
F_10 ( sizeof( T_1 ) , V_22 ) ;
if ( ! ( * V_19 ) -> V_24 -> V_5 ) {
F_11 ( ( * V_19 ) -> V_24 ) ;
( * V_19 ) -> V_24 = NULL ;
}
}
if ( ! ( * V_19 ) -> V_24 ) {
F_9 ( L_1 ) ;
return ( - V_23 ) ;
}
if ( ! ( ( ( T_1 * ) ( * V_19 ) -> V_24 -> V_5 ) -> V_6 =
F_12 ( V_6 , V_18 ) ) ) {
F_9 ( L_2 ) ;
return - V_25 ;
}
( ( T_1 * ) ( * V_19 ) -> V_24 -> V_5 ) -> V_26 =
( ( T_1 * ) ( * V_19 ) -> V_24 -> V_5 ) -> V_6 + V_18 ;
( * V_19 ) -> V_24 -> V_17 = V_17 ;
( * V_19 ) -> V_24 -> V_27 = V_18 ;
( * V_19 ) -> V_24 -> V_28 = V_29 ;
( * V_19 ) -> V_24 -> V_30 = F_1 ;
( * V_19 ) -> V_24 -> V_31 = F_3 ;
( * V_19 ) -> V_24 -> V_32 = F_4 ;
( * V_19 ) -> V_24 -> V_33 = F_5 ;
( * V_19 ) -> V_24 -> V_34 = F_6 ;
( * V_19 ) -> V_24 -> V_35 = V_36 ;
( * V_19 ) -> V_24 -> type = V_37 ;
( * V_19 ) -> V_24 -> V_38 = V_39 ;
( * V_19 ) -> V_24 -> V_40 = 1 ;
if ( F_13 ( ( * V_19 ) -> V_24 , NULL , 0 ) ) {
F_9 ( L_3 ) ;
F_14 ( ( ( T_1 * ) ( * V_19 ) -> V_24 -> V_5 ) -> V_6 ) ;
F_11 ( ( * V_19 ) -> V_24 -> V_5 ) ;
F_11 ( ( * V_19 ) -> V_24 ) ;
return ( - V_41 ) ;
}
F_15 ( L_4 , V_17 ,
( V_6 / 1024 ) , ( ( V_6 + V_18 ) / 1024 ) ) ;
F_15 ( L_5 ,
( ( T_1 * ) ( * V_19 ) -> V_24 -> V_5 ) -> V_6 ,
( ( T_1 * ) ( * V_19 ) -> V_24 -> V_5 ) -> V_26 ) ;
return ( 0 ) ;
}
static void F_16 ( void )
{
T_6 * V_42 ;
while ( V_20 ) {
V_42 = V_20 -> V_21 ;
F_17 ( V_20 -> V_24 ) ;
F_14 ( ( ( T_1 * ) V_20 -> V_24 -> V_5 ) -> V_6 ) ;
F_11 ( V_20 -> V_24 -> V_5 ) ;
F_11 ( V_20 -> V_24 ) ;
F_11 ( V_20 ) ;
V_20 = V_42 ;
}
}
static unsigned long F_18 ( unsigned long V_43 , char * V_44 )
{
if ( ( * V_44 == 'M' ) || ( * V_44 == 'm' ) ) {
return ( V_43 * 1024 * 1024 ) ;
} else if ( ( * V_44 == 'K' ) || ( * V_44 == 'k' ) ) {
return ( V_43 * 1024 ) ;
}
return ( V_43 ) ;
}
static int F_19 ( char * V_45 , char * V_46 , char * V_47 )
{
char * V_48 ;
unsigned long V_49 ;
unsigned long V_50 ;
if ( ( ! V_45 ) || ( ! V_46 ) || ( ! V_47 ) ) {
F_16 () ;
return ( - V_51 ) ;
}
V_49 = F_20 ( V_46 , & V_48 , 0 ) ;
V_49 = F_18 ( V_49 , V_48 ) ;
if ( * ( V_47 ) != '+' ) {
V_50 = F_20 ( V_47 , & V_48 , 0 ) ;
V_50 = F_18 ( V_50 , V_48 ) - V_49 ;
if ( V_50 < V_49 )
goto V_52;
V_50 -= V_49 ;
} else {
V_50 = F_20 ( V_47 + 1 , & V_48 , 0 ) ;
V_50 = F_18 ( V_50 , V_48 ) ;
}
F_15 ( L_6 ,
V_45 , V_49 , V_50 ) ;
if ( V_50 % V_39 != 0 )
goto V_52;
if ( ( V_49 = F_7 ( V_45 , V_49 , V_50 ) ) ) {
F_16 () ;
return ( ( int ) V_49 ) ;
}
return ( 0 ) ;
V_52:
F_9 ( L_7 ) ;
return ( - V_51 ) ;
}
static int T_7 F_21 ( char * V_53 )
{
V_54 = V_53 ;
return ( 1 ) ;
}
static int T_7 F_22 ( void )
{
char * V_45 ;
int V_55 ;
#ifndef F_23
char * V_49 ;
char * V_50 ;
V_55 = 0 ;
if ( ! V_54 ) {
F_9 ( L_8 ) ;
return ( - V_51 ) ;
}
while ( V_54 ) {
V_45 = V_49 = V_50 = NULL ;
if ( ! ( V_45 = F_24 ( & V_54 , L_9 ) ) ) {
F_9 ( L_10 ) ;
break;
}
F_15 ( L_11 , V_45 ) ;
if ( ( ! V_54 ) || ( ! ( V_49 = F_24 ( & V_54 , L_9 ) ) ) ) {
F_9 ( L_12 ) ;
}
F_15 ( L_13 , V_49 ) ;
if ( ( ! V_54 ) || ( ! ( V_50 = F_24 ( & V_54 , L_9 ) ) ) ) {
F_9 ( L_14 ) ;
}
F_15 ( L_15 , V_50 ) ;
if ( F_19 ( V_45 , V_49 , V_50 ) != 0 ) {
return ( - V_51 ) ;
}
}
#else
int V_56 ;
for ( V_56 = 0 ; V_56 < V_57 && V_54 [ V_56 ] ;
V_56 ++ ) {
}
if ( ( V_56 % 3 != 0 ) || ( V_56 == 0 ) ) {
F_9 ( L_8 ) ;
return ( - V_51 ) ;
}
for ( V_55 = 0 ; V_55 < ( V_56 / 3 ) ; V_55 ++ ) {
V_45 = V_54 [ V_55 * 3 ] ;
if ( F_19 ( V_45 , V_54 [ V_55 * 3 + 1 ] , V_54 [ V_55 * 3 + 2 ] ) != 0 ) {
return ( - V_51 ) ;
}
}
#endif
return ( 0 ) ;
}
static void T_8 F_25 ( void )
{
F_16 () ;
}
