struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_1 ;
T_1 V_4 = ( ( V_3 ? V_3 -> V_5 : V_6 ) *
sizeof( struct V_7 ) ) ;
V_1 = F_2 ( sizeof( struct V_1 ) + V_4 ) ;
if ( ! V_1 )
return NULL ;
V_1 -> V_8 = - 1 ;
if ( V_3 )
memcpy ( V_1 -> V_9 , V_3 -> V_9 , V_4 ) ;
return V_1 ;
}
void F_3 ( struct V_1 * V_1 )
{
free ( V_1 ) ;
}
int F_4 ( struct V_10 * V_11 )
{
char V_12 [ V_13 ] ;
char V_14 [ V_13 ] ;
char * V_15 = NULL ;
char * V_16 = NULL ;
struct V_17 V_18 ;
struct V_17 V_19 ;
T_2 * V_20 = NULL ;
T_3 V_21 = 0 ;
int V_22 = - 1 ;
if ( snprintf ( V_12 , V_13 , L_1 ) >= V_13 )
return V_22 ;
if ( F_5 ( & V_15 , L_2 , V_11 -> V_23 ) == - 1 )
return V_22 ;
if ( V_17 ( V_12 , & V_18 ) < 0 )
goto V_24;
if ( V_17 ( V_15 , & V_19 ) < 0 )
goto V_24;
if ( V_18 . V_25 != V_19 . V_25 ) {
V_11 -> V_26 = true ;
V_11 -> V_27 = V_15 ;
V_15 = NULL ;
}
if ( snprintf ( V_14 , V_13 , L_3 , V_11 -> V_23 ) >= V_13 )
goto V_24;
V_20 = fopen ( V_14 , L_4 ) ;
if ( V_20 == NULL )
goto V_24;
while ( F_6 ( & V_16 , & V_21 , V_20 ) != - 1 ) {
if ( strstr ( V_16 , L_5 ) != NULL ) {
V_11 -> V_28 = ( V_29 ) strtol ( strrchr ( V_16 , '\t' ) ,
NULL , 10 ) ;
V_11 -> V_30 = V_11 -> V_28 ;
}
if ( strstr ( V_16 , L_6 ) != NULL ) {
V_11 -> V_30 = ( V_29 ) strtol ( strrchr ( V_16 , '\t' ) ,
NULL , 10 ) ;
break;
}
}
V_22 = 0 ;
V_24:
if ( V_20 != NULL )
( void ) fclose ( V_20 ) ;
free ( V_16 ) ;
free ( V_15 ) ;
return V_22 ;
}
struct V_10 * F_7 ( V_29 V_23 )
{
struct V_10 * V_11 ;
if ( V_23 == 0 )
return NULL ;
V_11 = calloc ( 1 , sizeof( * V_11 ) ) ;
if ( V_11 != NULL ) {
V_11 -> V_23 = V_23 ;
V_11 -> V_28 = V_23 ;
V_11 -> V_30 = V_23 ;
V_11 -> V_26 = false ;
if ( F_4 ( V_11 ) == - 1 )
V_11 -> V_26 = false ;
F_8 ( & V_11 -> V_31 , 1 ) ;
}
return V_11 ;
}
struct V_10 * F_9 ( struct V_10 * V_11 )
{
struct V_10 * V_32 ;
V_32 = calloc ( 1 , sizeof( * V_32 ) ) ;
if ( V_32 != NULL ) {
V_32 -> V_23 = V_11 -> V_23 ;
V_32 -> V_28 = V_11 -> V_28 ;
V_32 -> V_30 = V_11 -> V_30 ;
V_32 -> V_26 = V_11 -> V_26 ;
if ( V_11 -> V_27 ) {
V_32 -> V_27 = F_10 ( V_11 -> V_27 ) ;
if ( ! V_32 -> V_27 ) {
free ( V_32 ) ;
return NULL ;
}
}
F_8 ( & V_32 -> V_31 , 1 ) ;
}
return V_32 ;
}
void F_11 ( struct V_10 * V_11 )
{
F_12 ( & V_11 -> V_27 ) ;
free ( V_11 ) ;
}
struct V_10 * F_13 ( struct V_10 * V_11 )
{
if ( V_11 )
F_14 ( & V_11 -> V_31 ) ;
return V_11 ;
}
void F_15 ( struct V_10 * V_11 )
{
if ( V_11 && F_16 ( & V_11 -> V_31 ) )
F_11 ( V_11 ) ;
}
void F_17 ( struct V_10 * V_11 ,
struct V_33 * V_34 )
{
char V_35 [ V_13 ] ;
int V_12 = - 1 ;
int V_15 = - 1 ;
if ( V_34 == NULL )
return;
V_34 -> V_12 = - 1 ;
V_34 -> V_15 = - 1 ;
if ( ! V_11 || ! V_11 -> V_26 )
return;
if ( snprintf ( V_35 , V_13 , L_1 ) >= V_13 )
return;
V_12 = F_18 ( V_35 , V_36 ) ;
if ( V_12 < 0 )
return;
V_15 = F_18 ( V_11 -> V_27 , V_36 ) ;
if ( V_15 < 0 )
goto V_37;
if ( F_19 ( V_15 , V_38 ) < 0 )
goto V_37;
V_34 -> V_12 = V_12 ;
V_34 -> V_15 = V_15 ;
return;
V_37:
if ( V_12 > - 1 )
F_20 ( V_12 ) ;
if ( V_15 > - 1 )
F_20 ( V_15 ) ;
}
void F_21 ( struct V_33 * V_34 )
{
if ( V_34 == NULL || V_34 -> V_12 == - 1 || V_34 -> V_15 == - 1 )
return;
F_19 ( V_34 -> V_12 , V_38 ) ;
if ( V_34 -> V_12 > - 1 ) {
F_20 ( V_34 -> V_12 ) ;
V_34 -> V_12 = - 1 ;
}
if ( V_34 -> V_15 > - 1 ) {
F_20 ( V_34 -> V_15 ) ;
V_34 -> V_15 = - 1 ;
}
}
char * F_22 ( const char * V_39 , struct V_10 * V_11 )
{
char * V_40 ;
struct V_33 V_41 ;
F_17 ( V_11 , & V_41 ) ;
V_40 = F_23 ( V_39 , NULL ) ;
F_21 ( & V_41 ) ;
return V_40 ;
}
