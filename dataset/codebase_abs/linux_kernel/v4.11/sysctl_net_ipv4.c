static void F_1 ( struct V_1 * V_1 , int V_2 [ 2 ] )
{
bool V_3 = ! ( ( V_2 [ 0 ] ^ V_2 [ 1 ] ) & 1 ) ;
F_2 ( & V_1 -> V_4 . V_5 . V_6 ) ;
if ( V_3 && ! V_1 -> V_4 . V_5 . V_7 ) {
V_1 -> V_4 . V_5 . V_7 = true ;
F_3 ( L_1 ) ;
}
V_1 -> V_4 . V_5 . V_2 [ 0 ] = V_2 [ 0 ] ;
V_1 -> V_4 . V_5 . V_2 [ 1 ] = V_2 [ 1 ] ;
F_4 ( & V_1 -> V_4 . V_5 . V_6 ) ;
}
static int F_5 ( struct V_8 * V_9 , int V_10 ,
void T_1 * V_11 ,
T_2 * V_12 , T_3 * V_13 )
{
struct V_1 * V_1 =
F_6 ( V_9 -> V_14 , struct V_1 , V_4 . V_5 . V_2 ) ;
int V_15 ;
int V_2 [ 2 ] ;
struct V_8 V_16 = {
. V_14 = & V_2 ,
. V_17 = sizeof( V_2 ) ,
. V_18 = V_9 -> V_18 ,
. V_19 = & V_20 ,
. V_21 = & V_22 ,
} ;
F_7 ( V_1 , & V_2 [ 0 ] , & V_2 [ 1 ] ) ;
V_15 = F_8 ( & V_16 , V_10 , V_11 , V_12 , V_13 ) ;
if ( V_10 && V_15 == 0 ) {
if ( ( V_2 [ 1 ] < V_2 [ 0 ] ) ||
( V_2 [ 0 ] < V_1 -> V_4 . V_23 ) )
V_15 = - V_24 ;
else
F_1 ( V_1 , V_2 ) ;
}
return V_15 ;
}
static int F_9 ( struct V_8 * V_9 , int V_10 ,
void T_1 * V_11 , T_2 * V_12 , T_3 * V_13 )
{
struct V_1 * V_1 = F_6 ( V_9 -> V_14 , struct V_1 ,
V_4 . V_23 ) ;
int V_15 ;
int V_25 ;
int V_2 [ 2 ] ;
struct V_8 V_16 = {
. V_14 = & V_25 ,
. V_17 = sizeof( V_25 ) ,
. V_18 = V_9 -> V_18 ,
. V_19 = & V_26 ,
. V_21 = & V_27 ,
} ;
V_25 = V_1 -> V_4 . V_23 ;
V_15 = F_8 ( & V_16 , V_10 , V_11 , V_12 , V_13 ) ;
if ( V_10 && V_15 == 0 ) {
F_7 ( V_1 , & V_2 [ 0 ] , & V_2 [ 1 ] ) ;
if ( V_2 [ 0 ] < V_25 )
V_15 = - V_24 ;
else
V_1 -> V_4 . V_23 = V_25 ;
}
return V_15 ;
}
static void F_10 ( struct V_8 * V_9 , T_4 * V_28 , T_4 * V_29 )
{
T_4 * V_14 = V_9 -> V_14 ;
struct V_1 * V_1 =
F_6 ( V_9 -> V_14 , struct V_1 , V_4 . V_30 . V_2 ) ;
unsigned int V_31 ;
do {
V_31 = F_11 ( & V_1 -> V_4 . V_30 . V_6 ) ;
* V_28 = V_14 [ 0 ] ;
* V_29 = V_14 [ 1 ] ;
} while ( F_12 ( & V_1 -> V_4 . V_30 . V_6 , V_31 ) );
}
static void F_13 ( struct V_8 * V_9 , T_4 V_28 , T_4 V_29 )
{
T_4 * V_14 = V_9 -> V_14 ;
struct V_1 * V_1 =
F_6 ( V_9 -> V_14 , struct V_1 , V_4 . V_30 . V_2 ) ;
F_14 ( & V_1 -> V_4 . V_30 . V_6 ) ;
V_14 [ 0 ] = V_28 ;
V_14 [ 1 ] = V_29 ;
F_15 ( & V_1 -> V_4 . V_30 . V_6 ) ;
}
static int F_16 ( struct V_8 * V_9 , int V_10 ,
void T_1 * V_11 ,
T_2 * V_12 , T_3 * V_13 )
{
struct V_32 * V_33 = F_17 () ;
int V_15 ;
T_5 V_34 [ 2 ] ;
T_4 V_28 , V_29 ;
struct V_8 V_16 = {
. V_14 = & V_34 ,
. V_17 = sizeof( V_34 ) ,
. V_18 = V_9 -> V_18 ,
. V_19 = & V_35 ,
. V_21 = & V_36 ,
} ;
F_10 ( V_9 , & V_28 , & V_29 ) ;
V_34 [ 0 ] = F_18 ( V_33 , V_28 ) ;
V_34 [ 1 ] = F_18 ( V_33 , V_29 ) ;
V_15 = F_8 ( & V_16 , V_10 , V_11 , V_12 , V_13 ) ;
if ( V_10 && V_15 == 0 ) {
V_28 = F_19 ( V_33 , V_34 [ 0 ] ) ;
V_29 = F_19 ( V_33 , V_34 [ 1 ] ) ;
if ( ! F_20 ( V_28 ) || ! F_20 ( V_29 ) ||
( V_34 [ 1 ] < V_34 [ 0 ] ) || F_21 ( V_29 , V_28 ) ) {
V_28 = F_19 ( & V_37 , 1 ) ;
V_29 = F_19 ( & V_37 , 0 ) ;
}
F_13 ( V_9 , V_28 , V_29 ) ;
}
return V_15 ;
}
static int F_22 ( struct V_8 * V_38 , int V_10 ,
void T_1 * V_11 , T_2 * V_12 , T_3 * V_13 )
{
char V_39 [ V_40 ] ;
struct V_8 V_41 = {
. V_14 = V_39 ,
. V_17 = V_40 ,
} ;
int V_15 ;
F_23 ( V_39 ) ;
V_15 = F_24 ( & V_41 , V_10 , V_11 , V_12 , V_13 ) ;
if ( V_10 && V_15 == 0 )
V_15 = F_25 ( V_39 ) ;
return V_15 ;
}
static int F_26 ( struct V_8 * V_38 ,
int V_10 ,
void T_1 * V_11 , T_2 * V_12 ,
T_3 * V_13 )
{
struct V_8 V_41 = { . V_17 = V_42 , } ;
int V_15 ;
V_41 . V_14 = F_27 ( V_41 . V_17 , V_43 ) ;
if ( ! V_41 . V_14 )
return - V_44 ;
F_28 ( V_41 . V_14 , V_42 ) ;
V_15 = F_24 ( & V_41 , V_10 , V_11 , V_12 , V_13 ) ;
F_29 ( V_41 . V_14 ) ;
return V_15 ;
}
static int F_30 ( struct V_8 * V_38 ,
int V_10 ,
void T_1 * V_11 , T_2 * V_12 ,
T_3 * V_13 )
{
struct V_8 V_41 = { . V_17 = V_42 } ;
int V_15 ;
V_41 . V_14 = F_27 ( V_41 . V_17 , V_43 ) ;
if ( ! V_41 . V_14 )
return - V_44 ;
F_31 ( V_41 . V_14 , V_41 . V_17 ) ;
V_15 = F_24 ( & V_41 , V_10 , V_11 , V_12 , V_13 ) ;
if ( V_10 && V_15 == 0 )
V_15 = F_32 ( V_41 . V_14 ) ;
F_29 ( V_41 . V_14 ) ;
return V_15 ;
}
static int F_33 ( struct V_8 * V_38 , int V_10 ,
void T_1 * V_11 , T_2 * V_12 ,
T_3 * V_13 )
{
struct V_8 V_41 = { . V_17 = ( V_45 * 2 + 10 ) } ;
struct V_46 * V_47 ;
int V_15 ;
T_6 V_48 [ 4 ] ;
V_41 . V_14 = F_27 ( V_41 . V_17 , V_49 ) ;
if ( ! V_41 . V_14 )
return - V_44 ;
F_34 () ;
V_47 = F_35 ( V_50 ) ;
if ( V_47 )
memcpy ( V_48 , V_47 -> V_51 , V_45 ) ;
else
memset ( V_48 , 0 , sizeof( V_48 ) ) ;
F_36 () ;
snprintf ( V_41 . V_14 , V_41 . V_17 , L_2 ,
V_48 [ 0 ] , V_48 [ 1 ] , V_48 [ 2 ] , V_48 [ 3 ] ) ;
V_15 = F_24 ( & V_41 , V_10 , V_11 , V_12 , V_13 ) ;
if ( V_10 && V_15 == 0 ) {
if ( sscanf ( V_41 . V_14 , L_3 , V_48 , V_48 + 1 ,
V_48 + 2 , V_48 + 3 ) != 4 ) {
V_15 = - V_24 ;
goto V_52;
}
F_37 ( false ) ;
F_38 ( V_48 , V_45 ) ;
}
V_52:
F_39 ( L_4 ,
V_48 [ 0 ] , V_48 [ 1 ] , V_48 [ 2 ] , V_48 [ 3 ] ,
( char * ) V_41 . V_14 , V_15 ) ;
F_29 ( V_41 . V_14 ) ;
return V_15 ;
}
static T_7 int F_40 ( struct V_1 * V_1 )
{
struct V_8 * V_9 ;
V_9 = V_53 ;
if ( ! F_41 ( V_1 , & V_54 ) ) {
int V_55 ;
V_9 = F_42 ( V_9 , sizeof( V_53 ) , V_49 ) ;
if ( ! V_9 )
goto V_56;
for ( V_55 = 0 ; V_55 < F_43 ( V_53 ) - 1 ; V_55 ++ )
V_9 [ V_55 ] . V_14 += ( void * ) V_1 - ( void * ) & V_54 ;
}
V_1 -> V_4 . V_57 = F_44 ( V_1 , L_5 , V_9 ) ;
if ( ! V_1 -> V_4 . V_57 )
goto V_58;
V_1 -> V_4 . V_59 = F_45 ( 65536 / 8 , V_49 ) ;
if ( ! V_1 -> V_4 . V_59 )
goto V_60;
return 0 ;
V_60:
F_46 ( V_1 -> V_4 . V_57 ) ;
V_58:
if ( ! F_41 ( V_1 , & V_54 ) )
F_29 ( V_9 ) ;
V_56:
return - V_44 ;
}
static T_8 void F_47 ( struct V_1 * V_1 )
{
struct V_8 * V_9 ;
F_29 ( V_1 -> V_4 . V_59 ) ;
V_9 = V_1 -> V_4 . V_57 -> V_61 ;
F_46 ( V_1 -> V_4 . V_57 ) ;
F_29 ( V_9 ) ;
}
static T_9 int F_48 ( void )
{
struct V_62 * V_63 ;
V_63 = F_44 ( & V_54 , L_5 , V_64 ) ;
if ( ! V_63 )
return - V_44 ;
if ( F_49 ( & V_65 ) ) {
F_46 ( V_63 ) ;
return - V_44 ;
}
return 0 ;
}
