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
static void F_7 ( struct T_1 * V_4 , T_5 * V_19 , T_5 * V_20 )
{
T_5 * V_11 = V_4 -> V_11 ;
unsigned int V_21 ;
do {
V_21 = F_8 ( & V_2 . V_3 ) ;
* V_19 = V_11 [ 0 ] ;
* V_20 = V_11 [ 1 ] ;
} while ( F_9 ( & V_2 . V_3 , V_21 ) );
}
static void F_10 ( struct T_1 * V_4 , T_5 V_1 [ 2 ] )
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
static int F_23 ( T_1 * V_24 , int V_5 ,
void T_2 * V_6 , T_3 * V_7 ,
T_4 * V_8 )
{
int V_9 ;
unsigned long V_31 [ 3 ] ;
struct V_32 * V_32 = V_33 -> V_34 -> V_35 ;
#ifdef F_24
struct V_36 * V_37 ;
#endif
T_1 V_10 = {
. V_11 = & V_31 ,
. V_12 = sizeof( V_31 ) ,
. V_13 = V_24 -> V_13 ,
} ;
if ( ! V_5 ) {
V_24 -> V_11 = & V_32 -> V_38 . V_39 ;
return F_25 ( V_24 , V_5 , V_6 , V_7 , V_8 ) ;
}
V_9 = F_25 ( & V_10 , V_5 , V_6 , V_7 , V_8 ) ;
if ( V_9 )
return V_9 ;
#ifdef F_24
F_26 () ;
V_37 = F_27 ( V_33 ) ;
F_28 ( V_37 , V_31 [ 0 ] , 0 ) ;
F_28 ( V_37 , V_31 [ 1 ] , 1 ) ;
F_28 ( V_37 , V_31 [ 2 ] , 2 ) ;
F_29 () ;
#endif
V_32 -> V_38 . V_39 [ 0 ] = V_31 [ 0 ] ;
V_32 -> V_38 . V_39 [ 1 ] = V_31 [ 1 ] ;
V_32 -> V_38 . V_39 [ 2 ] = V_31 [ 2 ] ;
return 0 ;
}
static T_6 int F_30 ( struct V_32 * V_32 )
{
struct T_1 * V_4 ;
V_4 = V_40 ;
if ( ! F_31 ( V_32 , & V_41 ) ) {
V_4 = F_32 ( V_4 , sizeof( V_40 ) , V_42 ) ;
if ( V_4 == NULL )
goto V_43;
V_4 [ 0 ] . V_11 =
& V_32 -> V_38 . V_44 ;
V_4 [ 1 ] . V_11 =
& V_32 -> V_38 . V_45 ;
V_4 [ 2 ] . V_11 =
& V_32 -> V_38 . V_46 ;
V_4 [ 3 ] . V_11 =
& V_32 -> V_38 . V_47 ;
V_4 [ 4 ] . V_11 =
& V_32 -> V_38 . V_48 ;
V_4 [ 5 ] . V_11 =
& V_32 -> V_38 . V_49 ;
V_4 [ 6 ] . V_11 =
& V_32 -> V_38 . V_50 ;
V_4 [ 7 ] . V_11 =
& V_32 -> V_38 . V_51 ;
}
V_32 -> V_38 . V_51 [ 0 ] = 1 ;
V_32 -> V_38 . V_51 [ 1 ] = 0 ;
V_32 -> V_38 . V_50 = 4 ;
F_33 ( V_32 ) ;
V_32 -> V_38 . V_52 = F_34 ( V_32 , L_1 , V_4 ) ;
if ( V_32 -> V_38 . V_52 == NULL )
goto V_53;
return 0 ;
V_53:
if ( ! F_31 ( V_32 , & V_41 ) )
F_19 ( V_4 ) ;
V_43:
return - V_30 ;
}
static T_7 void F_35 ( struct V_32 * V_32 )
{
struct T_1 * V_4 ;
V_4 = V_32 -> V_38 . V_52 -> V_54 ;
F_36 ( V_32 -> V_38 . V_52 ) ;
F_19 ( V_4 ) ;
}
static T_8 int F_37 ( void )
{
struct V_55 * V_56 ;
struct T_1 * V_57 ;
for ( V_57 = V_58 ; V_57 -> V_59 ; V_57 ++ ) {
if ( strcmp ( V_57 -> V_59 , L_2 ) == 0 ) {
V_57 -> V_11 = V_60 ;
break;
}
}
if ( ! V_57 -> V_59 )
return - V_18 ;
V_56 = F_34 ( & V_41 , L_1 , V_58 ) ;
if ( V_56 == NULL )
return - V_30 ;
if ( F_38 ( & V_61 ) ) {
F_36 ( V_56 ) ;
return - V_30 ;
}
return 0 ;
}
