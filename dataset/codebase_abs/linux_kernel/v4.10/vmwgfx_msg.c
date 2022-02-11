static int F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
unsigned long V_4 , V_5 , V_6 , V_7 , V_8 = 0 , V_9 = 0 ;
F_2 ( V_10 ,
( V_3 | V_11 ) , V_8 , V_9 ,
V_12 ,
V_13 ,
V_4 , V_5 , V_6 , V_7 , V_8 , V_9 ) ;
if ( ( F_3 ( V_6 ) & V_14 ) == 0 )
return - V_15 ;
V_2 -> V_16 = F_3 ( V_7 ) ;
V_2 -> V_17 = V_8 ;
V_2 -> V_18 = V_9 ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 )
{
unsigned long V_4 , V_5 , V_6 , V_7 , V_8 , V_9 ;
V_8 = V_2 -> V_17 ;
V_9 = V_2 -> V_18 ;
F_2 ( V_19 ,
0 , V_8 , V_9 ,
( V_12 | ( V_2 -> V_16 << 16 ) ) ,
V_13 ,
V_4 , V_5 , V_6 , V_7 , V_8 , V_9 ) ;
if ( ( F_3 ( V_6 ) & V_14 ) == 0 )
return - V_15 ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 , const char * V_20 )
{
unsigned long V_4 , V_5 , V_6 , V_7 , V_8 , V_9 , V_21 ;
T_1 V_22 = strlen ( V_20 ) ;
int V_23 = 0 ;
while ( V_23 < V_24 ) {
V_23 ++ ;
V_8 = V_2 -> V_17 ;
V_9 = V_2 -> V_18 ;
F_2 ( V_25 ,
V_22 , V_8 , V_9 ,
V_12 | ( V_2 -> V_16 << 16 ) ,
V_13 ,
V_4 , V_5 , V_6 , V_7 , V_8 , V_9 ) ;
if ( ( F_3 ( V_6 ) & V_14 ) == 0 ||
( F_3 ( V_6 ) & V_26 ) == 0 ) {
return - V_15 ;
}
V_8 = ( V_27 ) V_20 ;
V_9 = V_2 -> V_18 ;
V_21 = V_2 -> V_17 ;
F_6 (
( V_14 << 16 ) | V_28 ,
V_22 , V_8 , V_9 ,
V_29 | ( V_2 -> V_16 << 16 ) ,
V_13 , V_21 ,
V_4 , V_5 , V_6 , V_7 , V_8 , V_9 ) ;
if ( ( F_3 ( V_5 ) & V_14 ) != 0 ) {
return 0 ;
} else if ( ( F_3 ( V_5 ) & V_30 ) != 0 ) {
continue;
} else {
break;
}
}
return - V_15 ;
}
static int F_7 ( struct V_1 * V_2 , void * * V_20 ,
T_1 * V_22 )
{
unsigned long V_4 , V_5 , V_6 , V_7 , V_8 , V_9 , V_21 ;
char * V_31 ;
T_1 V_32 ;
int V_23 = 0 ;
* V_22 = 0 ;
* V_20 = NULL ;
while ( V_23 < V_24 ) {
V_23 ++ ;
V_8 = V_2 -> V_17 ;
V_9 = V_2 -> V_18 ;
F_2 ( V_33 ,
0 , V_8 , V_9 ,
( V_12 | ( V_2 -> V_16 << 16 ) ) ,
V_13 ,
V_4 , V_5 , V_6 , V_7 , V_8 , V_9 ) ;
if ( ( F_3 ( V_6 ) & V_14 ) == 0 ||
( F_3 ( V_6 ) & V_26 ) == 0 ) {
F_8 ( L_1 ) ;
return - V_15 ;
}
if ( ( F_3 ( V_6 ) & V_34 ) == 0 )
return 0 ;
V_32 = V_5 ;
V_31 = F_9 ( V_32 + 1 , V_35 ) ;
if ( V_31 == NULL ) {
F_8 ( L_2 ) ;
return - V_36 ;
}
V_8 = V_2 -> V_17 ;
V_9 = ( V_27 ) V_31 ;
V_21 = V_2 -> V_18 ;
F_10 (
( V_14 << 16 ) | V_28 ,
V_32 , V_8 , V_9 ,
V_29 | ( V_2 -> V_16 << 16 ) ,
V_13 , V_21 ,
V_4 , V_5 , V_6 , V_7 , V_8 , V_9 ) ;
if ( ( F_3 ( V_5 ) & V_14 ) == 0 ) {
F_11 ( V_31 ) ;
if ( ( F_3 ( V_5 ) & V_30 ) != 0 ) {
continue;
}
return - V_15 ;
}
V_31 [ V_32 ] = '\0' ;
V_8 = V_2 -> V_17 ;
V_9 = V_2 -> V_18 ;
F_2 ( V_37 ,
V_14 , V_8 , V_9 ,
( V_12 | ( V_2 -> V_16 << 16 ) ) ,
V_13 ,
V_4 , V_5 , V_6 , V_7 , V_8 , V_9 ) ;
if ( ( F_3 ( V_6 ) & V_14 ) == 0 ) {
F_11 ( V_31 ) ;
if ( ( F_3 ( V_6 ) & V_30 ) != 0 ) {
continue;
}
return - V_15 ;
}
break;
}
if ( V_23 == V_24 )
return - V_15 ;
* V_22 = V_32 ;
* V_20 = V_31 ;
return 0 ;
}
int F_12 ( const char * V_38 ,
char * V_39 , T_1 * V_40 )
{
struct V_1 V_2 ;
char * V_20 , * V_31 = NULL ;
T_1 V_22 , V_32 = 0 ;
int V_41 = 0 ;
if ( ! V_42 )
return - V_43 ;
if ( ! V_38 || ! V_40 )
return - V_15 ;
V_22 = strlen ( V_38 ) + strlen ( L_3 ) + 1 ;
V_20 = F_9 ( V_22 , V_35 ) ;
if ( V_20 == NULL ) {
F_8 ( L_4 , V_38 ) ;
return - V_36 ;
}
sprintf ( V_20 , L_5 , V_38 ) ;
if ( F_1 ( & V_2 , V_44 ) ||
F_5 ( & V_2 , V_20 ) ||
F_7 ( & V_2 , ( void * ) & V_31 , & V_32 ) ||
F_4 ( & V_2 ) ) {
F_8 ( L_6 , V_38 ) ;
V_41 = - V_15 ;
}
if ( V_39 && V_31 && V_32 > 0 ) {
V_32 = F_13 ( V_32 - 2 , ( T_1 ) 0 ) ;
V_32 = F_14 ( V_32 , * V_40 ) ;
if ( V_32 > 0 )
memcpy ( V_39 , V_31 + 2 , V_32 ) ;
}
* V_40 = V_32 ;
F_11 ( V_31 ) ;
F_11 ( V_20 ) ;
return V_41 ;
}
int F_15 ( const char * log )
{
struct V_1 V_2 ;
char * V_20 ;
int V_22 ;
int V_41 = 0 ;
if ( ! V_42 )
return - V_43 ;
if ( ! log )
return V_41 ;
V_22 = strlen ( log ) + strlen ( L_7 ) + 1 ;
V_20 = F_9 ( V_22 , V_35 ) ;
if ( V_20 == NULL ) {
F_8 ( L_8 ) ;
return - V_36 ;
}
sprintf ( V_20 , L_9 , log ) ;
if ( F_1 ( & V_2 , V_44 ) ||
F_5 ( & V_2 , V_20 ) ||
F_4 ( & V_2 ) ) {
F_8 ( L_10 ) ;
V_41 = - V_15 ;
}
F_11 ( V_20 ) ;
return V_41 ;
}
