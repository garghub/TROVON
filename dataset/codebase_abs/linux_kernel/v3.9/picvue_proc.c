static void F_1 ( unsigned long V_1 )
{
int V_2 ;
F_2 () ;
for ( V_2 = 0 ; V_2 < V_3 ; V_2 ++ )
F_3 ( V_4 [ V_2 ] , 0 , V_2 ) ;
}
static int F_4 ( struct V_5 * V_6 , void * V_7 )
{
int V_8 = * ( int * ) V_6 -> V_9 ;
if ( V_8 < 0 || V_8 > V_3 ) {
F_5 ( V_10 L_1 , V_8 ) ;
return 0 ;
}
F_6 ( & V_11 ) ;
F_7 ( V_6 , L_2 , V_4 [ V_8 ] ) ;
F_8 ( & V_11 ) ;
return 0 ;
}
static int F_9 ( struct V_12 * V_12 , struct V_13 * V_13 )
{
return F_10 ( V_13 , F_4 , F_11 ( V_12 ) -> V_1 ) ;
}
static T_1 F_12 ( struct V_13 * V_13 , const char T_2 * V_14 ,
T_3 V_15 , T_4 * V_16 )
{
int V_8 = * ( int * ) F_11 ( F_13 ( V_13 ) ) -> V_1 ;
char V_17 [ V_18 ] ;
T_3 V_19 ;
F_14 ( V_8 < 0 || V_8 > V_3 ) ;
V_19 = F_15 ( V_15 , sizeof( V_17 ) - 1 ) ;
if ( F_16 ( V_17 , V_14 , V_19 ) )
return - V_20 ;
V_17 [ V_19 ] = '\0' ;
if ( V_19 > 0 && V_17 [ V_19 - 1 ] == '\n' )
V_19 -- ;
F_6 ( & V_11 ) ;
strncpy ( V_4 [ V_8 ] , V_17 , V_19 ) ;
V_4 [ V_8 ] [ V_19 ] = '\0' ;
F_8 ( & V_11 ) ;
F_17 ( & V_21 ) ;
return V_15 ;
}
static T_1 F_18 ( struct V_13 * V_13 , const char T_2 * V_14 ,
T_3 V_15 , T_4 * V_16 )
{
char V_17 [ 42 ] ;
T_3 V_19 ;
int V_22 ;
V_19 = F_15 ( V_15 , sizeof( V_17 ) - 1 ) ;
if ( F_16 ( V_17 , V_14 , V_19 ) )
return - V_20 ;
V_17 [ V_19 ] = '\0' ;
V_22 = F_19 ( V_17 , NULL , 10 ) ;
F_6 ( & V_11 ) ;
if ( V_23 != 0 )
F_20 ( & V_24 ) ;
if ( V_22 == 0 ) {
V_25 = 0 ;
V_23 = 0 ;
} else {
if ( V_22 < 0 ) {
V_25 = - 1 ;
V_23 = - V_22 ;
} else {
V_25 = 1 ;
V_23 = V_22 ;
}
F_21 ( & V_24 ) ;
}
F_8 ( & V_11 ) ;
return V_15 ;
}
static int F_22 ( struct V_5 * V_6 , void * V_7 )
{
F_6 ( & V_11 ) ;
F_7 ( V_6 , L_3 , V_25 * V_23 ) ;
F_8 ( & V_11 ) ;
return 0 ;
}
static int F_23 ( struct V_12 * V_12 , struct V_13 * V_13 )
{
return F_10 ( V_13 , F_22 , NULL ) ;
}
void F_24 ( unsigned long V_1 )
{
if ( V_25 < 0 )
F_25 ( V_26 | V_27 ) ;
else if ( V_25 > 0 )
F_25 ( V_26 | V_28 ) ;
V_24 . V_29 = V_30 + V_23 ;
F_21 ( & V_24 ) ;
}
static void F_26 ( void )
{
int V_2 ;
for ( V_2 = 0 ; V_2 < V_3 ; V_2 ++ )
F_27 ( V_31 [ V_2 ] , V_32 ) ;
F_27 ( L_4 , V_32 ) ;
F_27 ( V_33 , NULL ) ;
F_20 ( & V_24 ) ;
}
static int T_5 F_28 ( void )
{
struct V_34 * V_35 ;
int V_2 ;
V_32 = F_29 ( V_33 , NULL ) ;
if ( V_32 == NULL )
goto error;
for ( V_2 = 0 ; V_2 < V_3 ; V_2 ++ ) {
strcpy ( V_4 [ V_2 ] , L_5 ) ;
V_36 [ V_2 ] = V_2 ;
}
for ( V_2 = 0 ; V_2 < V_3 ; V_2 ++ ) {
V_35 = F_30 ( V_31 [ V_2 ] , 0644 , V_32 ,
& V_37 , & V_36 [ V_2 ] ) ;
if ( V_35 == NULL )
goto error;
}
V_35 = F_31 ( L_4 , 0644 , V_32 ,
& V_38 ) ;
if ( V_35 == NULL )
goto error;
F_32 ( & V_24 ) ;
V_24 . V_39 = F_24 ;
return 0 ;
error:
F_26 () ;
return - V_40 ;
}
