static void F_1 ( struct V_1 * V_1 , int V_2 [ 2 ] )
{
F_2 ( & V_1 -> V_3 . V_4 . V_5 ) ;
V_1 -> V_3 . V_4 . V_2 [ 0 ] = V_2 [ 0 ] ;
V_1 -> V_3 . V_4 . V_2 [ 1 ] = V_2 [ 1 ] ;
F_3 ( & V_1 -> V_3 . V_4 . V_5 ) ;
}
static int F_4 ( struct V_6 * V_7 , int V_8 ,
void T_1 * V_9 ,
T_2 * V_10 , T_3 * V_11 )
{
struct V_1 * V_1 =
F_5 ( V_7 -> V_12 , struct V_1 , V_3 . V_4 . V_2 ) ;
int V_13 ;
int V_2 [ 2 ] ;
struct V_6 V_14 = {
. V_12 = & V_2 ,
. V_15 = sizeof( V_2 ) ,
. V_16 = V_7 -> V_16 ,
. V_17 = & V_18 ,
. V_19 = & V_20 ,
} ;
F_6 ( V_1 , & V_2 [ 0 ] , & V_2 [ 1 ] ) ;
V_13 = F_7 ( & V_14 , V_8 , V_9 , V_10 , V_11 ) ;
if ( V_8 && V_13 == 0 ) {
if ( V_2 [ 1 ] < V_2 [ 0 ] )
V_13 = - V_21 ;
else
F_1 ( V_1 , V_2 ) ;
}
return V_13 ;
}
static void F_8 ( struct V_6 * V_7 , T_4 * V_22 , T_4 * V_23 )
{
T_4 * V_12 = V_7 -> V_12 ;
struct V_1 * V_1 =
F_5 ( V_7 -> V_12 , struct V_1 , V_3 . V_24 . V_2 ) ;
unsigned int V_25 ;
do {
V_25 = F_9 ( & V_1 -> V_3 . V_4 . V_5 ) ;
* V_22 = V_12 [ 0 ] ;
* V_23 = V_12 [ 1 ] ;
} while ( F_10 ( & V_1 -> V_3 . V_4 . V_5 , V_25 ) );
}
static void F_11 ( struct V_6 * V_7 , T_4 V_22 , T_4 V_23 )
{
T_4 * V_12 = V_7 -> V_12 ;
struct V_1 * V_1 =
F_5 ( V_7 -> V_12 , struct V_1 , V_3 . V_24 . V_2 ) ;
F_2 ( & V_1 -> V_3 . V_4 . V_5 ) ;
V_12 [ 0 ] = V_22 ;
V_12 [ 1 ] = V_23 ;
F_3 ( & V_1 -> V_3 . V_4 . V_5 ) ;
}
static int F_12 ( struct V_6 * V_7 , int V_8 ,
void T_1 * V_9 ,
T_2 * V_10 , T_3 * V_11 )
{
struct V_26 * V_27 = F_13 () ;
int V_13 ;
T_5 V_28 [ 2 ] ;
T_4 V_22 , V_23 ;
struct V_6 V_14 = {
. V_12 = & V_28 ,
. V_15 = sizeof( V_28 ) ,
. V_16 = V_7 -> V_16 ,
. V_17 = & V_29 ,
. V_19 = & V_30 ,
} ;
F_8 ( V_7 , & V_22 , & V_23 ) ;
V_28 [ 0 ] = F_14 ( V_27 , V_22 ) ;
V_28 [ 1 ] = F_14 ( V_27 , V_23 ) ;
V_13 = F_7 ( & V_14 , V_8 , V_9 , V_10 , V_11 ) ;
if ( V_8 && V_13 == 0 ) {
V_22 = F_15 ( V_27 , V_28 [ 0 ] ) ;
V_23 = F_15 ( V_27 , V_28 [ 1 ] ) ;
if ( ! F_16 ( V_22 ) || ! F_16 ( V_23 ) ||
( V_28 [ 1 ] < V_28 [ 0 ] ) || F_17 ( V_23 , V_22 ) ) {
V_22 = F_15 ( & V_31 , 1 ) ;
V_23 = F_15 ( & V_31 , 0 ) ;
}
F_11 ( V_7 , V_22 , V_23 ) ;
}
return V_13 ;
}
static int F_18 ( struct V_6 * V_32 , int V_8 ,
void T_1 * V_9 , T_2 * V_10 , T_3 * V_11 )
{
char V_33 [ V_34 ] ;
struct V_6 V_35 = {
. V_12 = V_33 ,
. V_15 = V_34 ,
} ;
int V_13 ;
F_19 ( V_33 ) ;
V_13 = F_20 ( & V_35 , V_8 , V_9 , V_10 , V_11 ) ;
if ( V_8 && V_13 == 0 )
V_13 = F_21 ( V_33 ) ;
return V_13 ;
}
static int F_22 ( struct V_6 * V_32 ,
int V_8 ,
void T_1 * V_9 , T_2 * V_10 ,
T_3 * V_11 )
{
struct V_6 V_35 = { . V_15 = V_36 , } ;
int V_13 ;
V_35 . V_12 = F_23 ( V_35 . V_15 , V_37 ) ;
if ( ! V_35 . V_12 )
return - V_38 ;
F_24 ( V_35 . V_12 , V_36 ) ;
V_13 = F_20 ( & V_35 , V_8 , V_9 , V_10 , V_11 ) ;
F_25 ( V_35 . V_12 ) ;
return V_13 ;
}
static int F_26 ( struct V_6 * V_32 ,
int V_8 ,
void T_1 * V_9 , T_2 * V_10 ,
T_3 * V_11 )
{
struct V_6 V_35 = { . V_15 = V_36 } ;
int V_13 ;
V_35 . V_12 = F_23 ( V_35 . V_15 , V_37 ) ;
if ( ! V_35 . V_12 )
return - V_38 ;
F_27 ( V_35 . V_12 , V_35 . V_15 ) ;
V_13 = F_20 ( & V_35 , V_8 , V_9 , V_10 , V_11 ) ;
if ( V_8 && V_13 == 0 )
V_13 = F_28 ( V_35 . V_12 ) ;
F_25 ( V_35 . V_12 ) ;
return V_13 ;
}
static int F_29 ( struct V_6 * V_32 , int V_8 ,
void T_1 * V_9 , T_2 * V_10 ,
T_3 * V_11 )
{
struct V_6 V_35 = { . V_15 = ( V_39 * 2 + 10 ) } ;
struct V_40 * V_41 ;
int V_13 ;
T_6 V_42 [ 4 ] ;
V_35 . V_12 = F_23 ( V_35 . V_15 , V_43 ) ;
if ( ! V_35 . V_12 )
return - V_38 ;
F_30 () ;
V_41 = F_31 ( V_44 ) ;
if ( V_41 )
memcpy ( V_42 , V_41 -> V_45 , V_39 ) ;
else
memset ( V_42 , 0 , sizeof( V_42 ) ) ;
F_32 () ;
snprintf ( V_35 . V_12 , V_35 . V_15 , L_1 ,
V_42 [ 0 ] , V_42 [ 1 ] , V_42 [ 2 ] , V_42 [ 3 ] ) ;
V_13 = F_20 ( & V_35 , V_8 , V_9 , V_10 , V_11 ) ;
if ( V_8 && V_13 == 0 ) {
if ( sscanf ( V_35 . V_12 , L_2 , V_42 , V_42 + 1 ,
V_42 + 2 , V_42 + 3 ) != 4 ) {
V_13 = - V_21 ;
goto V_46;
}
F_33 ( false ) ;
F_34 ( V_42 , V_39 ) ;
}
V_46:
F_35 ( L_3 ,
V_42 [ 0 ] , V_42 [ 1 ] , V_42 [ 2 ] , V_42 [ 3 ] ,
( char * ) V_35 . V_12 , V_13 ) ;
F_25 ( V_35 . V_12 ) ;
return V_13 ;
}
static T_7 int F_36 ( struct V_1 * V_1 )
{
struct V_6 * V_7 ;
V_7 = V_47 ;
if ( ! F_37 ( V_1 , & V_48 ) ) {
int V_49 ;
V_7 = F_38 ( V_7 , sizeof( V_47 ) , V_43 ) ;
if ( V_7 == NULL )
goto V_50;
for ( V_49 = 0 ; V_49 < F_39 ( V_47 ) - 1 ; V_49 ++ )
V_7 [ V_49 ] . V_12 += ( void * ) V_1 - ( void * ) & V_48 ;
}
V_1 -> V_3 . V_51 = F_40 ( V_1 , L_4 , V_7 ) ;
if ( V_1 -> V_3 . V_51 == NULL )
goto V_52;
return 0 ;
V_52:
if ( ! F_37 ( V_1 , & V_48 ) )
F_25 ( V_7 ) ;
V_50:
return - V_38 ;
}
static T_8 void F_41 ( struct V_1 * V_1 )
{
struct V_6 * V_7 ;
V_7 = V_1 -> V_3 . V_51 -> V_53 ;
F_42 ( V_1 -> V_3 . V_51 ) ;
F_25 ( V_7 ) ;
}
static T_9 int F_43 ( void )
{
struct V_54 * V_55 ;
struct V_6 * V_49 ;
for ( V_49 = V_56 ; V_49 -> V_57 ; V_49 ++ ) {
if ( strcmp ( V_49 -> V_57 , L_5 ) == 0 ) {
V_49 -> V_12 = V_58 ;
break;
}
}
if ( ! V_49 -> V_57 )
return - V_21 ;
V_55 = F_40 ( & V_48 , L_4 , V_56 ) ;
if ( V_55 == NULL )
return - V_38 ;
if ( F_44 ( & V_59 ) ) {
F_42 ( V_55 ) ;
return - V_38 ;
}
return 0 ;
}
