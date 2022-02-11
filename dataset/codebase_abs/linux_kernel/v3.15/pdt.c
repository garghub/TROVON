static char * T_1 F_1 ( struct V_1 * V_2 )
{
int V_3 , V_4 , V_5 ;
char * V_6 ;
V_2 -> V_7 = F_2 ( V_2 ) ;
V_5 = strlen ( V_2 -> V_8 -> V_9 ) ;
V_4 = strlen ( V_2 -> V_7 ) ;
V_3 = V_4 + V_5 + 2 ;
V_6 = F_3 ( V_3 ) ;
strcpy ( V_6 , V_2 -> V_8 -> V_9 ) ;
if ( ! F_4 ( V_2 -> V_8 ) ) {
strcpy ( V_6 + V_5 , L_1 ) ;
V_5 ++ ;
}
strcpy ( V_6 + V_5 , V_2 -> V_7 ) ;
return V_6 ;
}
static inline void F_5 ( void * V_10 ) { }
static inline void F_6 ( struct V_1 * V_2 ) { }
static char * T_1 F_1 ( struct V_1 * V_2 )
{
static int V_11 = 0 ;
char * V_12 ;
int V_3 ;
if ( V_13 -> V_14 ( V_2 -> V_15 , NULL , 0 , & V_3 ) )
goto V_16;
V_12 = F_3 ( V_3 + 1 ) ;
if ( V_13 -> V_14 ( V_2 -> V_15 , V_12 , V_3 , & V_3 ) )
goto V_16;
return V_12 ;
V_16:
V_12 = F_3 ( strlen ( V_2 -> V_8 -> V_9 ) +
strlen ( V_2 -> V_17 ) + 16 ) ;
sprintf ( V_12 , L_2 ,
F_4 ( V_2 -> V_8 ) ? L_3 : V_2 -> V_8 -> V_9 ,
V_2 -> V_17 , V_11 ++ ) ;
F_7 ( L_4 , V_18 , V_12 ) ;
return V_12 ;
}
static struct V_19 * T_1 F_8 ( V_15 V_20 , char * V_21 ,
char * V_22 ,
void * V_23 ,
int V_24 )
{
static struct V_19 * V_25 = NULL ;
struct V_19 * V_10 ;
int V_26 ;
if ( V_25 ) {
V_10 = V_25 ;
memset ( V_10 , 0 , sizeof( * V_10 ) + 32 ) ;
V_25 = NULL ;
} else {
V_10 = F_3 ( sizeof( struct V_19 ) + 32 ) ;
F_5 ( V_10 ) ;
}
V_10 -> V_17 = ( char * ) ( V_10 + 1 ) ;
if ( V_22 ) {
strcpy ( V_10 -> V_17 , V_22 ) ;
V_10 -> V_27 = V_24 ;
V_10 -> V_28 = F_3 ( V_24 ) ;
memcpy ( V_10 -> V_28 , V_23 , V_24 ) ;
} else {
V_26 = V_13 -> V_29 ( V_20 , V_21 , V_10 -> V_17 ) ;
if ( V_26 ) {
V_25 = V_10 ;
return NULL ;
}
V_10 -> V_27 = V_13 -> V_30 ( V_20 , V_10 -> V_17 ) ;
if ( V_10 -> V_27 <= 0 ) {
V_10 -> V_27 = 0 ;
} else {
int V_3 ;
V_10 -> V_28 = F_3 ( V_10 -> V_27 + 1 ) ;
V_3 = V_13 -> V_31 ( V_20 , V_10 -> V_17 ,
V_10 -> V_28 , V_10 -> V_27 ) ;
if ( V_3 <= 0 )
V_10 -> V_27 = 0 ;
( ( unsigned char * ) V_10 -> V_28 ) [ V_10 -> V_27 ] = '\0' ;
}
}
return V_10 ;
}
static struct V_19 * T_1 F_9 ( V_15 V_20 )
{
struct V_19 * V_32 , * V_33 ;
V_32 = V_33 = F_8 ( V_20 , NULL ,
L_5 , & V_20 , sizeof( V_20 ) ) ;
V_33 -> V_34 = F_8 ( V_20 , NULL , NULL , NULL , 0 ) ;
V_33 = V_33 -> V_34 ;
while( V_33 ) {
V_33 -> V_34 = F_8 ( V_20 , V_33 -> V_17 ,
NULL , NULL , 0 ) ;
V_33 = V_33 -> V_34 ;
}
return V_32 ;
}
static char * T_1 F_10 ( V_15 V_20 , const char * V_17 )
{
char * V_12 = L_6 ;
int V_3 ;
V_3 = V_13 -> V_30 ( V_20 , V_17 ) ;
if ( V_3 > 0 ) {
V_12 = F_3 ( V_3 ) ;
V_3 = V_13 -> V_31 ( V_20 , V_17 , V_12 , V_3 ) ;
}
return V_12 ;
}
static struct V_1 * T_1 F_11 ( V_15 V_20 ,
struct V_1 * V_8 )
{
struct V_1 * V_2 ;
if ( ! V_20 )
return NULL ;
V_2 = F_3 ( sizeof( * V_2 ) ) ;
F_12 ( V_2 ) ;
F_5 ( V_2 ) ;
V_2 -> V_8 = V_8 ;
V_2 -> V_17 = F_10 ( V_20 , L_7 ) ;
V_2 -> type = F_10 ( V_20 , L_8 ) ;
V_2 -> V_15 = V_20 ;
V_2 -> V_35 = F_9 ( V_20 ) ;
F_6 ( V_2 ) ;
return V_2 ;
}
static struct V_1 * T_1 F_13 ( struct V_1 * V_8 ,
V_15 V_20 ,
struct V_1 * * * V_36 )
{
struct V_1 * V_37 = NULL , * V_38 = NULL ;
struct V_1 * V_2 ;
while ( 1 ) {
V_2 = F_11 ( V_20 , V_8 ) ;
if ( ! V_2 )
break;
if ( V_38 )
V_38 -> V_39 = V_2 ;
if ( ! V_37 )
V_37 = V_2 ;
V_38 = V_2 ;
* ( * V_36 ) = V_2 ;
* V_36 = & V_2 -> V_40 ;
V_2 -> V_9 = F_1 ( V_2 ) ;
V_2 -> V_41 = F_13 ( V_2 ,
V_13 -> V_42 ( V_20 ) , V_36 ) ;
if ( V_43 )
V_43 ( V_2 , V_36 ) ;
V_20 = V_13 -> V_44 ( V_20 ) ;
}
return V_37 ;
}
static void * T_1 F_14 ( T_2 V_45 , T_2 V_46 )
{
return F_3 ( V_45 ) ;
}
void T_1 F_15 ( V_15 V_47 , struct V_48 * V_49 )
{
struct V_1 * * V_36 ;
F_16 ( ! V_49 ) ;
V_13 = V_49 ;
V_50 = F_11 ( V_47 , NULL ) ;
#if F_17 ( V_51 )
V_50 -> V_7 = L_3 ;
#endif
V_50 -> V_9 = L_1 ;
V_36 = & V_50 -> V_40 ;
V_50 -> V_41 = F_13 ( V_50 ,
V_13 -> V_42 ( V_50 -> V_15 ) , & V_36 ) ;
F_18 ( F_14 ) ;
}
