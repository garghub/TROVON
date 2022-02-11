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
if ( V_2 [ 1 ] < V_2 [ 0 ] )
V_15 = - V_23 ;
else
F_1 ( V_1 , V_2 ) ;
}
return V_15 ;
}
static void F_9 ( struct V_8 * V_9 , T_4 * V_24 , T_4 * V_25 )
{
T_4 * V_14 = V_9 -> V_14 ;
struct V_1 * V_1 =
F_6 ( V_9 -> V_14 , struct V_1 , V_4 . V_26 . V_2 ) ;
unsigned int V_27 ;
do {
V_27 = F_10 ( & V_1 -> V_4 . V_26 . V_6 ) ;
* V_24 = V_14 [ 0 ] ;
* V_25 = V_14 [ 1 ] ;
} while ( F_11 ( & V_1 -> V_4 . V_26 . V_6 , V_27 ) );
}
static void F_12 ( struct V_8 * V_9 , T_4 V_24 , T_4 V_25 )
{
T_4 * V_14 = V_9 -> V_14 ;
struct V_1 * V_1 =
F_6 ( V_9 -> V_14 , struct V_1 , V_4 . V_26 . V_2 ) ;
F_13 ( & V_1 -> V_4 . V_26 . V_6 ) ;
V_14 [ 0 ] = V_24 ;
V_14 [ 1 ] = V_25 ;
F_14 ( & V_1 -> V_4 . V_26 . V_6 ) ;
}
static int F_15 ( struct V_8 * V_9 , int V_10 ,
void T_1 * V_11 ,
T_2 * V_12 , T_3 * V_13 )
{
struct V_28 * V_29 = F_16 () ;
int V_15 ;
T_5 V_30 [ 2 ] ;
T_4 V_24 , V_25 ;
struct V_8 V_16 = {
. V_14 = & V_30 ,
. V_17 = sizeof( V_30 ) ,
. V_18 = V_9 -> V_18 ,
. V_19 = & V_31 ,
. V_21 = & V_32 ,
} ;
F_9 ( V_9 , & V_24 , & V_25 ) ;
V_30 [ 0 ] = F_17 ( V_29 , V_24 ) ;
V_30 [ 1 ] = F_17 ( V_29 , V_25 ) ;
V_15 = F_8 ( & V_16 , V_10 , V_11 , V_12 , V_13 ) ;
if ( V_10 && V_15 == 0 ) {
V_24 = F_18 ( V_29 , V_30 [ 0 ] ) ;
V_25 = F_18 ( V_29 , V_30 [ 1 ] ) ;
if ( ! F_19 ( V_24 ) || ! F_19 ( V_25 ) ||
( V_30 [ 1 ] < V_30 [ 0 ] ) || F_20 ( V_25 , V_24 ) ) {
V_24 = F_18 ( & V_33 , 1 ) ;
V_25 = F_18 ( & V_33 , 0 ) ;
}
F_12 ( V_9 , V_24 , V_25 ) ;
}
return V_15 ;
}
static int F_21 ( struct V_8 * V_34 , int V_10 ,
void T_1 * V_11 , T_2 * V_12 , T_3 * V_13 )
{
char V_35 [ V_36 ] ;
struct V_8 V_37 = {
. V_14 = V_35 ,
. V_17 = V_36 ,
} ;
int V_15 ;
F_22 ( V_35 ) ;
V_15 = F_23 ( & V_37 , V_10 , V_11 , V_12 , V_13 ) ;
if ( V_10 && V_15 == 0 )
V_15 = F_24 ( V_35 ) ;
return V_15 ;
}
static int F_25 ( struct V_8 * V_34 ,
int V_10 ,
void T_1 * V_11 , T_2 * V_12 ,
T_3 * V_13 )
{
struct V_8 V_37 = { . V_17 = V_38 , } ;
int V_15 ;
V_37 . V_14 = F_26 ( V_37 . V_17 , V_39 ) ;
if ( ! V_37 . V_14 )
return - V_40 ;
F_27 ( V_37 . V_14 , V_38 ) ;
V_15 = F_23 ( & V_37 , V_10 , V_11 , V_12 , V_13 ) ;
F_28 ( V_37 . V_14 ) ;
return V_15 ;
}
static int F_29 ( struct V_8 * V_34 ,
int V_10 ,
void T_1 * V_11 , T_2 * V_12 ,
T_3 * V_13 )
{
struct V_8 V_37 = { . V_17 = V_38 } ;
int V_15 ;
V_37 . V_14 = F_26 ( V_37 . V_17 , V_39 ) ;
if ( ! V_37 . V_14 )
return - V_40 ;
F_30 ( V_37 . V_14 , V_37 . V_17 ) ;
V_15 = F_23 ( & V_37 , V_10 , V_11 , V_12 , V_13 ) ;
if ( V_10 && V_15 == 0 )
V_15 = F_31 ( V_37 . V_14 ) ;
F_28 ( V_37 . V_14 ) ;
return V_15 ;
}
static int F_32 ( struct V_8 * V_34 , int V_10 ,
void T_1 * V_11 , T_2 * V_12 ,
T_3 * V_13 )
{
struct V_8 V_37 = { . V_17 = ( V_41 * 2 + 10 ) } ;
struct V_42 * V_43 ;
int V_15 ;
T_6 V_44 [ 4 ] ;
V_37 . V_14 = F_26 ( V_37 . V_17 , V_45 ) ;
if ( ! V_37 . V_14 )
return - V_40 ;
F_33 () ;
V_43 = F_34 ( V_46 ) ;
if ( V_43 )
memcpy ( V_44 , V_43 -> V_47 , V_41 ) ;
else
memset ( V_44 , 0 , sizeof( V_44 ) ) ;
F_35 () ;
snprintf ( V_37 . V_14 , V_37 . V_17 , L_2 ,
V_44 [ 0 ] , V_44 [ 1 ] , V_44 [ 2 ] , V_44 [ 3 ] ) ;
V_15 = F_23 ( & V_37 , V_10 , V_11 , V_12 , V_13 ) ;
if ( V_10 && V_15 == 0 ) {
if ( sscanf ( V_37 . V_14 , L_3 , V_44 , V_44 + 1 ,
V_44 + 2 , V_44 + 3 ) != 4 ) {
V_15 = - V_23 ;
goto V_48;
}
F_36 ( false ) ;
F_37 ( V_44 , V_41 ) ;
}
V_48:
F_38 ( L_4 ,
V_44 [ 0 ] , V_44 [ 1 ] , V_44 [ 2 ] , V_44 [ 3 ] ,
( char * ) V_37 . V_14 , V_15 ) ;
F_28 ( V_37 . V_14 ) ;
return V_15 ;
}
static T_7 int F_39 ( struct V_1 * V_1 )
{
struct V_8 * V_9 ;
V_9 = V_49 ;
if ( ! F_40 ( V_1 , & V_50 ) ) {
int V_51 ;
V_9 = F_41 ( V_9 , sizeof( V_49 ) , V_45 ) ;
if ( ! V_9 )
goto V_52;
for ( V_51 = 0 ; V_51 < F_42 ( V_49 ) - 1 ; V_51 ++ )
V_9 [ V_51 ] . V_14 += ( void * ) V_1 - ( void * ) & V_50 ;
}
V_1 -> V_4 . V_53 = F_43 ( V_1 , L_5 , V_9 ) ;
if ( ! V_1 -> V_4 . V_53 )
goto V_54;
V_1 -> V_4 . V_55 = F_44 ( 65536 / 8 , V_45 ) ;
if ( ! V_1 -> V_4 . V_55 )
goto V_56;
return 0 ;
V_56:
F_45 ( V_1 -> V_4 . V_53 ) ;
V_54:
if ( ! F_40 ( V_1 , & V_50 ) )
F_28 ( V_9 ) ;
V_52:
return - V_40 ;
}
static T_8 void F_46 ( struct V_1 * V_1 )
{
struct V_8 * V_9 ;
F_28 ( V_1 -> V_4 . V_55 ) ;
V_9 = V_1 -> V_4 . V_53 -> V_57 ;
F_45 ( V_1 -> V_4 . V_53 ) ;
F_28 ( V_9 ) ;
}
static T_9 int F_47 ( void )
{
struct V_58 * V_59 ;
V_59 = F_43 ( & V_50 , L_5 , V_60 ) ;
if ( ! V_59 )
return - V_40 ;
if ( F_48 ( & V_61 ) ) {
F_45 ( V_59 ) ;
return - V_40 ;
}
return 0 ;
}
