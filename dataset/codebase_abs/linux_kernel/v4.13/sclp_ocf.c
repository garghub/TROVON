static void F_1 ( struct V_1 * V_2 )
{
F_2 ( & V_3 -> V_4 , V_5 ) ;
}
static void F_3 ( struct V_6 * V_7 )
{
struct V_8 * V_9 ;
struct V_10 * V_11 , * V_12 , * V_13 ;
T_1 V_14 ;
V_9 = F_4 ( V_7 + 1 , ( void * ) V_7 + V_7 -> V_15 ,
0x9f00 ) ;
if ( ! V_9 )
return;
V_9 = F_4 ( V_9 + 1 , ( void * ) V_9 + V_9 -> V_15 , 0x9f22 ) ;
if ( ! V_9 )
return;
V_11 = F_5 ( V_9 + 1 , ( void * ) V_9 + V_9 -> V_15 , 0x81 ) ;
if ( ! V_11 )
return;
V_12 = F_5 ( V_11 + 1 , ( void * ) V_11 + V_11 -> V_15 , 1 ) ;
V_13 = F_5 ( V_11 + 1 , ( void * ) V_11 + V_11 -> V_15 , 2 ) ;
F_6 ( & V_16 ) ;
if ( V_12 ) {
V_14 = F_7 ( V_17 , ( T_1 ) V_12 -> V_15 ) ;
memcpy ( V_18 , V_12 + 1 , V_14 ) ;
F_8 ( V_18 , V_14 ) ;
V_18 [ V_14 ] = 0 ;
}
if ( V_13 ) {
V_14 = F_7 ( V_19 , ( T_1 ) V_13 -> V_15 ) ;
memset ( V_20 , 0 , V_19 ) ;
memcpy ( V_20 , V_13 + 1 , V_14 ) ;
}
F_9 ( & V_16 ) ;
F_10 ( & V_21 ) ;
}
void F_11 ( char * V_22 )
{
F_12 ( & V_16 ) ;
memcpy ( V_22 , V_20 , V_19 ) ;
F_13 ( & V_16 ) ;
}
static T_2 F_14 ( struct V_23 * V_4 ,
struct V_24 * V_25 , char * V_26 )
{
char V_27 [ V_19 + 1 ] ;
F_11 ( V_27 ) ;
V_27 [ V_19 ] = 0 ;
F_8 ( V_27 , V_19 ) ;
return snprintf ( V_26 , V_28 , L_1 , V_27 ) ;
}
static T_2 F_15 ( struct V_23 * V_4 ,
struct V_24 * V_25 , char * V_26 )
{
int V_29 ;
F_12 ( & V_16 ) ;
V_29 = snprintf ( V_26 , V_28 , L_1 , V_18 ) ;
F_13 ( & V_16 ) ;
return V_29 ;
}
static int T_3 F_16 ( void )
{
int V_29 ;
F_17 ( & V_21 , F_1 ) ;
V_3 = F_18 ( L_2 , NULL , V_30 ) ;
if ( ! V_3 )
return - V_31 ;
V_29 = F_19 ( & V_3 -> V_4 , & V_32 ) ;
if ( V_29 ) {
F_20 ( V_3 ) ;
return V_29 ;
}
return F_21 ( & V_33 ) ;
}
