void F_1 ( struct V_1 * V_2 , int V_3 )
{
T_1 V_4 ;
if ( ! V_5 )
return ;
V_4 = F_2 () ;
V_2 -> V_6 [ V_3 ] += V_4 - V_2 -> V_7 ;
V_2 -> V_7 = V_4 ;
}
static int F_3 ( struct V_8 * V_9 , void * V_10 )
{
struct V_11 * V_12 = (struct V_11 * ) V_10 ;
if ( strcmp ( V_9 -> V_13 , L_1 ) == 0 ||
strcmp ( V_9 -> V_13 , L_2 ) == 0 ||
strncmp ( V_9 -> V_13 , L_3 , 4 ) == 0 )
return 0 ;
F_4 ( V_12 , L_4 , V_9 -> V_13 ,
V_9 -> V_2 . V_14 -> V_13 ,
F_5 ( & V_9 -> V_15 ) ) ;
F_4 ( V_12 , L_5 ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 , void * V_10 )
{
struct V_11 * V_12 = (struct V_11 * ) V_10 ;
int V_16 ;
if ( strcmp ( V_2 -> V_13 , L_6 ) == 0 ||
strcmp ( V_2 -> V_13 , L_7 ) == 0 ||
strncmp ( V_2 -> V_13 , L_3 , 4 ) == 0 )
return 0 ;
if ( V_2 -> V_17 != F_7 ( V_2 ) )
F_8 ( V_18 L_8 ,
V_2 -> V_13 , V_2 -> V_17 , F_7 ( V_2 ) ) ;
F_4 ( V_12 , L_9 , V_2 -> V_13 ,
V_19 [ V_2 -> V_17 ] ) ;
for ( V_16 = 0 ; V_16 < V_20 ; V_16 ++ )
F_4 ( V_12 , L_10 , V_19 [ V_16 ] ,
V_2 -> V_21 [ V_16 ] ) ;
F_4 ( V_12 , L_11 , V_2 -> V_22 ) ;
for ( V_16 = 0 ; V_16 < V_2 -> V_23 ; V_16 ++ )
F_4 ( V_12 , L_12 , V_16 + 1 ,
V_2 -> V_24 [ V_16 ] ) ;
F_4 ( V_12 , L_5 ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 , void * V_10 )
{
struct V_11 * V_12 = (struct V_11 * ) V_10 ;
int V_16 ;
if ( strcmp ( V_2 -> V_13 , L_6 ) == 0 ||
strcmp ( V_2 -> V_13 , L_7 ) == 0 ||
strncmp ( V_2 -> V_13 , L_3 , 4 ) == 0 )
return 0 ;
F_10 ( V_2 ) ;
F_4 ( V_12 , L_9 , V_2 -> V_13 ,
V_19 [ V_2 -> V_17 ] ) ;
for ( V_16 = 0 ; V_16 < 4 ; V_16 ++ )
F_4 ( V_12 , L_13 , V_19 [ V_16 ] ,
V_2 -> V_6 [ V_16 ] ) ;
F_4 ( V_12 , L_5 ) ;
return 0 ;
}
static int F_11 ( struct V_11 * V_12 , void * V_25 )
{
F_12 ( F_6 , V_12 ) ;
F_13 ( F_3 , V_12 ) ;
return 0 ;
}
static int F_14 ( struct V_11 * V_12 , void * V_25 )
{
F_12 ( F_9 , V_12 ) ;
return 0 ;
}
static int F_15 ( struct V_26 * V_26 , struct V_27 * V_27 )
{
switch ( ( int ) V_26 -> V_28 ) {
case V_29 :
return F_16 ( V_27 , F_11 ,
& V_26 -> V_28 ) ;
case V_30 :
default:
return F_16 ( V_27 , F_14 ,
& V_26 -> V_28 ) ;
} ;
}
static int F_17 ( void * V_31 , T_2 * V_32 )
{
int V_33 = - V_34 ;
if ( F_18 () )
V_33 = F_19 ( (struct V_1 * ) V_31 ) ;
* V_32 = V_33 ;
if ( V_33 >= 0 )
return 0 ;
return * V_32 ;
}
static int F_20 ( void * V_31 , T_2 V_32 )
{
if ( F_18 () )
return F_21 (
(struct V_1 * ) V_31 , ( int ) V_32 ) ;
return - V_34 ;
}
static int T_3 F_22 ( struct V_1 * V_2 , void * V_35 )
{
int V_16 ;
T_1 V_4 ;
struct V_36 * V_37 ;
V_4 = F_2 () ;
for ( V_16 = 0 ; V_16 < 4 ; V_16 ++ )
V_2 -> V_6 [ V_16 ] = 0 ;
V_2 -> V_7 = V_4 ;
if ( strncmp ( V_2 -> V_13 , L_3 , 4 ) == 0 )
return 0 ;
V_37 = F_23 ( V_2 -> V_13 , (struct V_36 * ) V_35 ) ;
( void ) F_24 ( L_14 , V_38 | V_39 , V_37 ,
( void * ) V_2 , & V_40 ) ;
return 0 ;
}
static int F_25 ( void * V_31 , T_2 * V_32 )
{
T_4 * V_41 = V_31 ;
* V_32 = * V_41 ;
return 0 ;
}
static int F_26 ( void * V_31 , T_2 V_32 )
{
T_4 * V_41 = V_31 ;
* V_41 = V_32 ;
if ( V_41 == & V_42 ) {
if ( V_32 )
F_27 () ;
else
F_28 () ;
if ( F_18 () )
F_29 ( V_32 ) ;
}
return 0 ;
}
static int T_3 F_30 ( void )
{
struct V_36 * V_37 ;
if ( V_5 )
return 0 ;
V_37 = F_23 ( L_15 , NULL ) ;
if ( F_31 ( V_37 ) )
return F_32 ( V_37 ) ;
( void ) F_24 ( L_16 , V_38 ,
V_37 , ( void * ) V_29 , & V_43 ) ;
( void ) F_24 ( L_17 , V_38 ,
V_37 , ( void * ) V_30 , & V_43 ) ;
F_12 ( F_22 , ( void * ) V_37 ) ;
( void ) F_24 ( L_18 , V_38 | V_39 , V_37 ,
& V_42 , & V_44 ) ;
V_5 = 1 ;
return 0 ;
}
