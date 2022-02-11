static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 =
(struct V_3 * ) V_2 ;
F_2 ( F_3 ( V_4 -> V_5 ) ) ;
F_4 ( & V_4 -> V_6 ) ;
return V_7 ;
}
static void F_5 ( struct V_8 * V_9 ,
struct V_3 * V_4 ,
int V_10 )
{
long V_11 = 0 ;
struct V_12 * V_13 = F_3 ( V_4 -> V_5 ) ;
F_6 ( V_13 -> V_1 , ( void * ) V_4 ) ;
F_7 ( & V_4 -> V_6 ) ;
do {
if ( V_11 )
F_8 ( 100 ) ;
V_11 = F_9 ( V_14 , V_13 -> V_15 ) ;
} while ( ( V_11 == V_16 ) || ( F_10 ( V_11 ) ) );
F_11 ( V_4 -> V_5 ,
V_9 -> V_17 ,
V_9 -> V_18 * sizeof( * V_9 -> V_19 ) , V_20 ) ;
F_12 ( ( unsigned long ) V_9 -> V_19 ) ;
}
static struct V_21 * F_13 ( struct V_8 * V_9 )
{
struct V_21 * V_22 ;
unsigned long V_23 ;
F_14 ( & V_9 -> V_24 , V_23 ) ;
V_22 = & V_9 -> V_19 [ V_9 -> V_25 ] ;
if ( V_22 -> V_26 & 0x80 ) {
if ( ++ V_9 -> V_25 == V_9 -> V_18 )
V_9 -> V_25 = 0 ;
} else
V_22 = NULL ;
F_15 ( & V_9 -> V_24 , V_23 ) ;
return V_22 ;
}
static int F_16 ( struct V_3 * V_4 ,
T_2 V_27 , T_2 V_28 )
{
struct V_12 * V_13 = F_3 ( V_4 -> V_5 ) ;
return F_9 ( V_29 , V_13 -> V_15 , V_27 , V_28 ) ;
}
static void F_17 ( void * V_30 )
{
struct V_3 * V_4 = (struct V_3 * ) V_30 ;
struct V_12 * V_13 = F_3 ( V_4 -> V_5 ) ;
struct V_21 * V_22 ;
int V_31 = 0 ;
while ( ! V_31 ) {
while ( ( V_22 = F_13 ( & V_4 -> V_9 ) ) != NULL ) {
F_18 ( V_22 , V_4 ) ;
V_22 -> V_26 = 0x00 ;
}
F_19 ( V_13 ) ;
if ( ( V_22 = F_13 ( & V_4 -> V_9 ) ) != NULL ) {
F_2 ( V_13 ) ;
F_18 ( V_22 , V_4 ) ;
V_22 -> V_26 = 0x00 ;
} else {
V_31 = 1 ;
}
}
}
static void F_20 ( void )
{
struct V_32 * V_33 ;
const char * V_34 ;
const unsigned int * V_35 ;
V_33 = F_21 ( L_1 ) ;
if ( ! V_33 ) {
return;
}
V_34 = F_22 ( V_33 , L_2 , NULL ) ;
if ( V_34 )
strncpy ( V_36 , V_34 ,
sizeof( V_36 ) ) ;
V_35 = F_22 ( V_33 , L_3 , NULL ) ;
if ( V_35 )
V_37 = * V_35 ;
F_23 ( V_33 ) ;
}
static void F_24 ( struct V_3 * V_4 )
{
memset ( & V_4 -> V_38 , 0x00 ,
sizeof( V_4 -> V_38 ) ) ;
F_25 ( V_4 -> V_5 , L_4 , V_39 ) ;
strcpy ( V_4 -> V_38 . V_40 , V_39 ) ;
strncpy ( V_4 -> V_38 . V_36 , V_36 ,
sizeof( V_4 -> V_38 . V_36 ) ) ;
V_4 -> V_38 . V_37 = V_37 ;
V_4 -> V_38 . V_41 = 1 ;
V_4 -> V_38 . V_42 = 2 ;
}
static int F_26 ( struct V_8 * V_9 ,
struct V_3 * V_4 )
{
int V_11 = 0 ;
struct V_12 * V_13 = F_3 ( V_4 -> V_5 ) ;
do {
if ( V_11 )
F_8 ( 100 ) ;
V_11 = F_9 ( V_14 , V_13 -> V_15 ) ;
} while ( ( V_11 == V_16 ) || ( F_10 ( V_11 ) ) );
memset ( V_9 -> V_19 , 0x00 , V_43 ) ;
V_9 -> V_25 = 0 ;
F_24 ( V_4 ) ;
V_11 = F_9 ( V_44 ,
V_13 -> V_15 ,
V_9 -> V_17 , V_43 ) ;
if ( V_11 == 2 ) {
F_27 ( V_4 -> V_5 , L_5 ) ;
} else if ( V_11 != 0 ) {
F_27 ( V_4 -> V_5 , L_6 , V_11 ) ;
}
return V_11 ;
}
static int F_28 ( struct V_8 * V_9 ,
struct V_3 * V_4 ,
int V_10 )
{
int V_11 ;
int V_45 ;
struct V_12 * V_13 = F_3 ( V_4 -> V_5 ) ;
V_9 -> V_19 = (struct V_21 * ) F_29 ( V_46 ) ;
if ( ! V_9 -> V_19 )
goto V_47;
V_9 -> V_18 = V_43 / sizeof( * V_9 -> V_19 ) ;
V_9 -> V_17 = F_30 ( V_4 -> V_5 , V_9 -> V_19 ,
V_9 -> V_18 * sizeof( * V_9 -> V_19 ) ,
V_20 ) ;
if ( F_31 ( V_4 -> V_5 , V_9 -> V_17 ) )
goto V_48;
F_20 () ;
F_24 ( V_4 ) ;
V_45 = V_11 = F_9 ( V_44 ,
V_13 -> V_15 ,
V_9 -> V_17 , V_43 ) ;
if ( V_11 == V_49 )
V_11 = F_26 ( V_9 ,
V_4 ) ;
if ( V_11 == 2 ) {
F_27 ( V_4 -> V_5 , L_5 ) ;
V_45 = 0 ;
} else if ( V_11 != 0 ) {
F_27 ( V_4 -> V_5 , L_7 , V_11 ) ;
goto V_50;
}
V_9 -> V_25 = 0 ;
F_32 ( & V_9 -> V_24 ) ;
F_33 ( & V_4 -> V_6 , ( void * ) F_17 ,
( unsigned long ) V_4 ) ;
if ( F_34 ( V_13 -> V_1 ,
F_1 ,
0 , L_8 , ( void * ) V_4 ) != 0 ) {
F_35 ( V_4 -> V_5 , L_9 ,
V_13 -> V_1 ) ;
goto V_51;
}
V_11 = F_19 ( V_13 ) ;
if ( V_11 != 0 ) {
F_35 ( V_4 -> V_5 , L_10 , V_11 ) ;
goto V_51;
}
return V_45 ;
V_51:
F_7 ( & V_4 -> V_6 ) ;
V_11 = 0 ;
do {
if ( V_11 )
F_8 ( 100 ) ;
V_11 = F_9 ( V_14 , V_13 -> V_15 ) ;
} while ( ( V_11 == V_16 ) || ( F_10 ( V_11 ) ) );
V_50:
F_11 ( V_4 -> V_5 ,
V_9 -> V_17 ,
V_9 -> V_18 * sizeof( * V_9 -> V_19 ) , V_20 ) ;
V_48:
F_12 ( ( unsigned long ) V_9 -> V_19 ) ;
V_47:
return - 1 ;
}
static int F_36 ( struct V_8 * V_9 ,
struct V_3 * V_4 )
{
int V_11 = 0 ;
struct V_12 * V_13 = F_3 ( V_4 -> V_5 ) ;
do {
if ( V_11 )
F_8 ( 100 ) ;
V_11 = F_9 ( V_52 , V_13 -> V_15 ) ;
} while ( ( V_11 == V_53 ) || ( V_11 == V_16 ) || ( F_10 ( V_11 ) ) );
if ( V_11 )
F_35 ( V_4 -> V_5 , L_11 , V_11 ) ;
return V_11 ;
}
static int F_37 ( struct V_3 * V_4 )
{
F_2 ( F_3 ( V_4 -> V_5 ) ) ;
F_4 ( & V_4 -> V_6 ) ;
return 0 ;
}
