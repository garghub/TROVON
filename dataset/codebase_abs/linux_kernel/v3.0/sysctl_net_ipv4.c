static void F_1 ( int V_1 [ 2 ] )
{
F_2 ( & V_2 . V_3 ) ;
V_2 . V_1 [ 0 ] = V_1 [ 0 ] ;
V_2 . V_1 [ 1 ] = V_1 [ 1 ] ;
F_3 ( & V_2 . V_3 ) ;
}
static int F_4 ( T_1 * V_4 , int V_5 ,
void T_2 * V_6 ,
T_3 * V_7 , T_4 * V_8 )
{
int V_9 ;
int V_1 [ 2 ] ;
T_1 V_10 = {
. V_11 = & V_1 ,
. V_12 = sizeof( V_1 ) ,
. V_13 = V_4 -> V_13 ,
. V_14 = & V_15 ,
. V_16 = & V_17 ,
} ;
F_5 ( V_1 , V_1 + 1 ) ;
V_9 = F_6 ( & V_10 , V_5 , V_6 , V_7 , V_8 ) ;
if ( V_5 && V_9 == 0 ) {
if ( V_1 [ 1 ] < V_1 [ 0 ] )
V_9 = - V_18 ;
else
F_1 ( V_1 ) ;
}
return V_9 ;
}
void F_7 ( struct T_1 * V_4 , T_5 * V_19 , T_5 * V_20 )
{
T_5 * V_11 = V_4 -> V_11 ;
unsigned V_21 ;
do {
V_21 = F_8 ( & V_2 . V_3 ) ;
* V_19 = V_11 [ 0 ] ;
* V_20 = V_11 [ 1 ] ;
} while ( F_9 ( & V_2 . V_3 , V_21 ) );
}
static void F_10 ( struct T_1 * V_4 , int V_1 [ 2 ] )
{
T_5 * V_11 = V_4 -> V_11 ;
F_2 ( & V_2 . V_3 ) ;
V_11 [ 0 ] = V_1 [ 0 ] ;
V_11 [ 1 ] = V_1 [ 1 ] ;
F_3 ( & V_2 . V_3 ) ;
}
static int F_11 ( T_1 * V_4 , int V_5 ,
void T_2 * V_6 ,
T_3 * V_7 , T_4 * V_8 )
{
int V_9 ;
T_5 V_1 [ 2 ] ;
T_1 V_10 = {
. V_11 = & V_1 ,
. V_12 = sizeof( V_1 ) ,
. V_13 = V_4 -> V_13 ,
. V_14 = & V_22 ,
. V_16 = & V_23 ,
} ;
F_7 ( V_4 , V_1 , V_1 + 1 ) ;
V_9 = F_6 ( & V_10 , V_5 , V_6 , V_7 , V_8 ) ;
if ( V_5 && V_9 == 0 )
F_10 ( V_4 , V_1 ) ;
return V_9 ;
}
static int F_12 ( T_1 * V_24 , int V_5 ,
void T_2 * V_6 , T_3 * V_7 , T_4 * V_8 )
{
char V_25 [ V_26 ] ;
T_1 V_27 = {
. V_11 = V_25 ,
. V_12 = V_26 ,
} ;
int V_9 ;
F_13 ( V_25 ) ;
V_9 = F_14 ( & V_27 , V_5 , V_6 , V_7 , V_8 ) ;
if ( V_5 && V_9 == 0 )
V_9 = F_15 ( V_25 ) ;
return V_9 ;
}
static int F_16 ( T_1 * V_24 ,
int V_5 ,
void T_2 * V_6 , T_3 * V_7 ,
T_4 * V_8 )
{
T_1 V_27 = { . V_12 = V_28 , } ;
int V_9 ;
V_27 . V_11 = F_17 ( V_27 . V_12 , V_29 ) ;
if ( ! V_27 . V_11 )
return - V_30 ;
F_18 ( V_27 . V_11 , V_28 ) ;
V_9 = F_14 ( & V_27 , V_5 , V_6 , V_7 , V_8 ) ;
F_19 ( V_27 . V_11 ) ;
return V_9 ;
}
static int F_20 ( T_1 * V_24 ,
int V_5 ,
void T_2 * V_6 , T_3 * V_7 ,
T_4 * V_8 )
{
T_1 V_27 = { . V_12 = V_28 } ;
int V_9 ;
V_27 . V_11 = F_17 ( V_27 . V_12 , V_29 ) ;
if ( ! V_27 . V_11 )
return - V_30 ;
F_21 ( V_27 . V_11 , V_27 . V_12 ) ;
V_9 = F_14 ( & V_27 , V_5 , V_6 , V_7 , V_8 ) ;
if ( V_5 && V_9 == 0 )
V_9 = F_22 ( V_27 . V_11 ) ;
F_19 ( V_27 . V_11 ) ;
return V_9 ;
}
static T_6 int F_23 ( struct V_31 * V_31 )
{
struct T_1 * V_4 ;
V_4 = V_32 ;
if ( ! F_24 ( V_31 , & V_33 ) ) {
V_4 = F_25 ( V_4 , sizeof( V_32 ) , V_34 ) ;
if ( V_4 == NULL )
goto V_35;
V_4 [ 0 ] . V_11 =
& V_31 -> V_36 . V_37 ;
V_4 [ 1 ] . V_11 =
& V_31 -> V_36 . V_38 ;
V_4 [ 2 ] . V_11 =
& V_31 -> V_36 . V_39 ;
V_4 [ 3 ] . V_11 =
& V_31 -> V_36 . V_40 ;
V_4 [ 4 ] . V_11 =
& V_31 -> V_36 . V_41 ;
V_4 [ 5 ] . V_11 =
& V_31 -> V_36 . V_42 ;
V_4 [ 6 ] . V_11 =
& V_31 -> V_36 . V_43 ;
V_4 [ 7 ] . V_11 =
& V_31 -> V_36 . V_44 ;
}
V_31 -> V_36 . V_44 [ 0 ] = 1 ;
V_31 -> V_36 . V_44 [ 1 ] = 0 ;
V_31 -> V_36 . V_43 = 4 ;
V_31 -> V_36 . V_45 = F_26 ( V_31 ,
V_46 , V_4 ) ;
if ( V_31 -> V_36 . V_45 == NULL )
goto V_47;
return 0 ;
V_47:
if ( ! F_24 ( V_31 , & V_33 ) )
F_19 ( V_4 ) ;
V_35:
return - V_30 ;
}
static T_7 void F_27 ( struct V_31 * V_31 )
{
struct T_1 * V_4 ;
V_4 = V_31 -> V_36 . V_45 -> V_48 ;
F_28 ( V_31 -> V_36 . V_45 ) ;
F_19 ( V_4 ) ;
}
static T_8 int F_29 ( void )
{
struct V_49 * V_50 ;
struct T_1 * V_51 ;
for ( V_51 = V_52 ; V_51 -> V_53 ; V_51 ++ ) {
if ( strcmp ( V_51 -> V_53 , L_1 ) == 0 ) {
V_51 -> V_11 = V_54 ;
break;
}
}
if ( ! V_51 -> V_53 )
return - V_18 ;
V_50 = F_30 ( V_46 , V_52 ) ;
if ( V_50 == NULL )
return - V_30 ;
if ( F_31 ( & V_55 ) ) {
F_32 ( V_50 ) ;
return - V_30 ;
}
return 0 ;
}
