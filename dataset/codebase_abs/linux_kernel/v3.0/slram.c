static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
T_1 * V_5 = V_2 -> V_5 ;
if ( V_4 -> V_6 + V_4 -> V_7 > V_2 -> V_8 ) {
return ( - V_9 ) ;
}
memset ( V_5 -> V_10 + V_4 -> V_6 , 0xff , V_4 -> V_7 ) ;
V_4 -> V_11 = V_12 ;
F_2 ( V_4 ) ;
return ( 0 ) ;
}
static int F_3 ( struct V_1 * V_2 , T_2 V_13 , T_3 V_7 ,
T_3 * V_14 , void * * V_15 , T_4 * V_16 )
{
T_1 * V_5 = V_2 -> V_5 ;
if ( V_16 )
return - V_9 ;
if ( V_13 + V_7 > V_2 -> V_8 )
return - V_9 ;
* V_15 = V_5 -> V_10 + V_13 ;
* V_14 = V_7 ;
return ( 0 ) ;
}
static void F_4 ( struct V_1 * V_2 , T_2 V_13 , T_3 V_7 )
{
}
static int F_5 ( struct V_1 * V_2 , T_2 V_13 , T_3 V_7 ,
T_3 * V_14 , T_5 * V_17 )
{
T_1 * V_5 = V_2 -> V_5 ;
if ( V_13 > V_2 -> V_8 )
return - V_9 ;
if ( V_13 + V_7 > V_2 -> V_8 )
V_7 = V_2 -> V_8 - V_13 ;
memcpy ( V_17 , V_5 -> V_10 + V_13 , V_7 ) ;
* V_14 = V_7 ;
return ( 0 ) ;
}
static int F_6 ( struct V_1 * V_2 , T_2 V_18 , T_3 V_7 ,
T_3 * V_14 , const T_5 * V_17 )
{
T_1 * V_5 = V_2 -> V_5 ;
if ( V_18 + V_7 > V_2 -> V_8 )
return - V_9 ;
memcpy ( V_5 -> V_10 + V_18 , V_17 , V_7 ) ;
* V_14 = V_7 ;
return ( 0 ) ;
}
static int F_7 ( char * V_19 , unsigned long V_10 , unsigned long V_20 )
{
T_6 * * V_21 ;
V_21 = & V_22 ;
while ( * V_21 ) {
V_21 = & ( * V_21 ) -> V_23 ;
}
* V_21 = F_8 ( sizeof( T_6 ) , V_24 ) ;
if ( ! ( * V_21 ) ) {
F_9 ( L_1 ) ;
return ( - V_25 ) ;
}
( * V_21 ) -> V_26 = F_10 ( sizeof( struct V_1 ) , V_24 ) ;
( * V_21 ) -> V_23 = NULL ;
if ( ( * V_21 ) -> V_26 ) {
( * V_21 ) -> V_26 -> V_5 =
F_10 ( sizeof( T_1 ) , V_24 ) ;
if ( ! ( * V_21 ) -> V_26 -> V_5 ) {
F_11 ( ( * V_21 ) -> V_26 ) ;
( * V_21 ) -> V_26 = NULL ;
}
}
if ( ! ( * V_21 ) -> V_26 ) {
F_9 ( L_1 ) ;
return ( - V_25 ) ;
}
if ( ! ( ( ( T_1 * ) ( * V_21 ) -> V_26 -> V_5 ) -> V_10 =
F_12 ( V_10 , V_20 ) ) ) {
F_9 ( L_2 ) ;
return - V_27 ;
}
( ( T_1 * ) ( * V_21 ) -> V_26 -> V_5 ) -> V_28 =
( ( T_1 * ) ( * V_21 ) -> V_26 -> V_5 ) -> V_10 + V_20 ;
( * V_21 ) -> V_26 -> V_19 = V_19 ;
( * V_21 ) -> V_26 -> V_8 = V_20 ;
( * V_21 ) -> V_26 -> V_29 = V_30 ;
( * V_21 ) -> V_26 -> V_31 = F_1 ;
( * V_21 ) -> V_26 -> V_32 = F_3 ;
( * V_21 ) -> V_26 -> V_33 = F_4 ;
( * V_21 ) -> V_26 -> V_34 = F_5 ;
( * V_21 ) -> V_26 -> V_35 = F_6 ;
( * V_21 ) -> V_26 -> V_36 = V_37 ;
( * V_21 ) -> V_26 -> type = V_38 ;
( * V_21 ) -> V_26 -> V_39 = V_40 ;
( * V_21 ) -> V_26 -> V_41 = 1 ;
if ( F_13 ( ( * V_21 ) -> V_26 , NULL , 0 ) ) {
F_9 ( L_3 ) ;
F_14 ( ( ( T_1 * ) ( * V_21 ) -> V_26 -> V_5 ) -> V_10 ) ;
F_11 ( ( * V_21 ) -> V_26 -> V_5 ) ;
F_11 ( ( * V_21 ) -> V_26 ) ;
return ( - V_42 ) ;
}
F_15 ( L_4 , V_19 ,
( V_10 / 1024 ) , ( ( V_10 + V_20 ) / 1024 ) ) ;
F_15 ( L_5 ,
( ( T_1 * ) ( * V_21 ) -> V_26 -> V_5 ) -> V_10 ,
( ( T_1 * ) ( * V_21 ) -> V_26 -> V_5 ) -> V_28 ) ;
return ( 0 ) ;
}
static void F_16 ( void )
{
T_6 * V_43 ;
while ( V_22 ) {
V_43 = V_22 -> V_23 ;
F_17 ( V_22 -> V_26 ) ;
F_14 ( ( ( T_1 * ) V_22 -> V_26 -> V_5 ) -> V_10 ) ;
F_11 ( V_22 -> V_26 -> V_5 ) ;
F_11 ( V_22 -> V_26 ) ;
F_11 ( V_22 ) ;
V_22 = V_43 ;
}
}
static unsigned long F_18 ( unsigned long V_44 , char * V_45 )
{
if ( ( * V_45 == 'M' ) || ( * V_45 == 'm' ) ) {
return ( V_44 * 1024 * 1024 ) ;
} else if ( ( * V_45 == 'K' ) || ( * V_45 == 'k' ) ) {
return ( V_44 * 1024 ) ;
}
return ( V_44 ) ;
}
static int F_19 ( char * V_46 , char * V_47 , char * V_48 )
{
char * V_49 ;
unsigned long V_50 ;
unsigned long V_51 ;
if ( ( ! V_46 ) || ( ! V_47 ) || ( ! V_48 ) ) {
F_16 () ;
return ( - V_9 ) ;
}
V_50 = F_20 ( V_47 , & V_49 , 0 ) ;
V_50 = F_18 ( V_50 , V_49 ) ;
if ( * ( V_48 ) != '+' ) {
V_51 = F_20 ( V_48 , & V_49 , 0 ) ;
V_51 = F_18 ( V_51 , V_49 ) - V_50 ;
if ( V_51 < V_50 )
goto V_52;
V_51 -= V_50 ;
} else {
V_51 = F_20 ( V_48 + 1 , & V_49 , 0 ) ;
V_51 = F_18 ( V_51 , V_49 ) ;
}
F_15 ( L_6 ,
V_46 , V_50 , V_51 ) ;
if ( V_51 % V_40 != 0 )
goto V_52;
if ( ( V_50 = F_7 ( V_46 , V_50 , V_51 ) ) ) {
F_16 () ;
return ( ( int ) V_50 ) ;
}
return ( 0 ) ;
V_52:
F_9 ( L_7 ) ;
return ( - V_9 ) ;
}
static int T_7 F_21 ( char * V_53 )
{
V_54 = V_53 ;
return ( 1 ) ;
}
static int T_7 F_22 ( void )
{
char * V_46 ;
int V_55 ;
#ifndef F_23
char * V_50 ;
char * V_51 ;
V_55 = 0 ;
if ( ! V_54 ) {
F_9 ( L_8 ) ;
return ( - V_9 ) ;
}
while ( V_54 ) {
V_46 = V_50 = V_51 = NULL ;
if ( ! ( V_46 = F_24 ( & V_54 , L_9 ) ) ) {
F_9 ( L_10 ) ;
break;
}
F_15 ( L_11 , V_46 ) ;
if ( ( ! V_54 ) || ( ! ( V_50 = F_24 ( & V_54 , L_9 ) ) ) ) {
F_9 ( L_12 ) ;
}
F_15 ( L_13 , V_50 ) ;
if ( ( ! V_54 ) || ( ! ( V_51 = F_24 ( & V_54 , L_9 ) ) ) ) {
F_9 ( L_14 ) ;
}
F_15 ( L_15 , V_51 ) ;
if ( F_19 ( V_46 , V_50 , V_51 ) != 0 ) {
return ( - V_9 ) ;
}
}
#else
int V_56 ;
for ( V_56 = 0 ; V_56 < V_57 && V_54 [ V_56 ] ;
V_56 ++ ) {
}
if ( ( V_56 % 3 != 0 ) || ( V_56 == 0 ) ) {
F_9 ( L_8 ) ;
return ( - V_9 ) ;
}
for ( V_55 = 0 ; V_55 < ( V_56 / 3 ) ; V_55 ++ ) {
V_46 = V_54 [ V_55 * 3 ] ;
if ( F_19 ( V_46 , V_54 [ V_55 * 3 + 1 ] , V_54 [ V_55 * 3 + 2 ] ) != 0 ) {
return ( - V_9 ) ;
}
}
#endif
return ( 0 ) ;
}
static void T_8 F_25 ( void )
{
F_16 () ;
}
