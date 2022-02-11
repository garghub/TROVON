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
int V_8 = * ( int * ) F_11 ( V_13 -> V_17 . V_18 -> V_19 ) -> V_1 ;
char V_20 [ V_21 ] ;
T_3 V_22 ;
F_13 ( V_8 < 0 || V_8 > V_3 ) ;
V_22 = F_14 ( V_15 , sizeof( V_20 ) - 1 ) ;
if ( F_15 ( V_20 , V_14 , V_22 ) )
return - V_23 ;
V_20 [ V_22 ] = '\0' ;
if ( V_22 > 0 && V_20 [ V_22 - 1 ] == '\n' )
V_22 -- ;
F_6 ( & V_11 ) ;
strncpy ( V_4 [ V_8 ] , V_20 , V_22 ) ;
V_4 [ V_8 ] [ V_22 ] = '\0' ;
F_8 ( & V_11 ) ;
F_16 ( & V_24 ) ;
return V_15 ;
}
static T_1 F_17 ( struct V_13 * V_13 , const char T_2 * V_14 ,
T_3 V_15 , T_4 * V_16 )
{
char V_20 [ 42 ] ;
T_3 V_22 ;
int V_25 ;
V_22 = F_14 ( V_15 , sizeof( V_20 ) - 1 ) ;
if ( F_15 ( V_20 , V_14 , V_22 ) )
return - V_23 ;
V_20 [ V_22 ] = '\0' ;
V_25 = F_18 ( V_20 , NULL , 10 ) ;
F_6 ( & V_11 ) ;
if ( V_26 != 0 )
F_19 ( & V_27 ) ;
if ( V_25 == 0 ) {
V_28 = 0 ;
V_26 = 0 ;
} else {
if ( V_25 < 0 ) {
V_28 = - 1 ;
V_26 = - V_25 ;
} else {
V_28 = 1 ;
V_26 = V_25 ;
}
F_20 ( & V_27 ) ;
}
F_8 ( & V_11 ) ;
return V_15 ;
}
static int F_21 ( struct V_5 * V_6 , void * V_7 )
{
F_6 ( & V_11 ) ;
F_7 ( V_6 , L_3 , V_28 * V_26 ) ;
F_8 ( & V_11 ) ;
return 0 ;
}
static int F_22 ( struct V_12 * V_12 , struct V_13 * V_13 )
{
return F_10 ( V_13 , F_21 , NULL ) ;
}
void F_23 ( unsigned long V_1 )
{
if ( V_28 < 0 )
F_24 ( V_29 | V_30 ) ;
else if ( V_28 > 0 )
F_24 ( V_29 | V_31 ) ;
V_27 . V_32 = V_33 + V_26 ;
F_20 ( & V_27 ) ;
}
static void F_25 ( void )
{
int V_2 ;
for ( V_2 = 0 ; V_2 < V_3 ; V_2 ++ )
F_26 ( V_34 [ V_2 ] , V_35 ) ;
F_26 ( L_4 , V_35 ) ;
F_26 ( V_36 , NULL ) ;
F_19 ( & V_27 ) ;
}
static int T_5 F_27 ( void )
{
struct V_37 * V_38 ;
int V_2 ;
V_35 = F_28 ( V_36 , NULL ) ;
if ( V_35 == NULL )
goto error;
for ( V_2 = 0 ; V_2 < V_3 ; V_2 ++ ) {
strcpy ( V_4 [ V_2 ] , L_5 ) ;
V_39 [ V_2 ] = V_2 ;
}
for ( V_2 = 0 ; V_2 < V_3 ; V_2 ++ ) {
V_38 = F_29 ( V_34 [ V_2 ] , 0644 , V_35 ,
& V_40 , & V_39 [ V_2 ] ) ;
if ( V_38 == NULL )
goto error;
}
V_38 = F_30 ( L_4 , 0644 , V_35 ,
& V_41 ) ;
if ( V_38 == NULL )
goto error;
F_31 ( & V_27 ) ;
V_27 . V_42 = F_23 ;
return 0 ;
error:
F_25 () ;
return - V_43 ;
}
