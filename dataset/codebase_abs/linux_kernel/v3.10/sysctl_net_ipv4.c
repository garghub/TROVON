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
static void F_10 ( struct T_1 * V_4 , T_5 V_19 , T_5 V_20 )
{
T_5 * V_11 = V_4 -> V_11 ;
F_2 ( & V_2 . V_3 ) ;
V_11 [ 0 ] = V_19 ;
V_11 [ 1 ] = V_20 ;
F_3 ( & V_2 . V_3 ) ;
}
static int F_11 ( T_1 * V_4 , int V_5 ,
void T_2 * V_6 ,
T_3 * V_7 , T_4 * V_8 )
{
struct V_22 * V_23 = F_12 () ;
int V_9 ;
T_6 V_24 [ 2 ] ;
T_5 V_19 , V_20 ;
T_1 V_10 = {
. V_11 = & V_24 ,
. V_12 = sizeof( V_24 ) ,
. V_13 = V_4 -> V_13 ,
. V_14 = & V_25 ,
. V_16 = & V_26 ,
} ;
F_7 ( V_4 , & V_19 , & V_20 ) ;
V_24 [ 0 ] = F_13 ( V_23 , V_19 ) ;
V_24 [ 1 ] = F_13 ( V_23 , V_20 ) ;
V_9 = F_6 ( & V_10 , V_5 , V_6 , V_7 , V_8 ) ;
if ( V_5 && V_9 == 0 ) {
V_19 = F_14 ( V_23 , V_24 [ 0 ] ) ;
V_20 = F_14 ( V_23 , V_24 [ 1 ] ) ;
if ( ! F_15 ( V_19 ) || ! F_15 ( V_20 ) ||
( V_24 [ 1 ] < V_24 [ 0 ] ) || F_16 ( V_20 , V_19 ) ) {
V_19 = F_14 ( & V_27 , 1 ) ;
V_20 = F_14 ( & V_27 , 0 ) ;
}
F_10 ( V_4 , V_19 , V_20 ) ;
}
return V_9 ;
}
static int F_17 ( T_1 * V_28 , int V_5 ,
void T_2 * V_6 , T_3 * V_7 , T_4 * V_8 )
{
char V_29 [ V_30 ] ;
T_1 V_31 = {
. V_11 = V_29 ,
. V_12 = V_30 ,
} ;
int V_9 ;
F_18 ( V_29 ) ;
V_9 = F_19 ( & V_31 , V_5 , V_6 , V_7 , V_8 ) ;
if ( V_5 && V_9 == 0 )
V_9 = F_20 ( V_29 ) ;
return V_9 ;
}
static int F_21 ( T_1 * V_28 ,
int V_5 ,
void T_2 * V_6 , T_3 * V_7 ,
T_4 * V_8 )
{
T_1 V_31 = { . V_12 = V_32 , } ;
int V_9 ;
V_31 . V_11 = F_22 ( V_31 . V_12 , V_33 ) ;
if ( ! V_31 . V_11 )
return - V_34 ;
F_23 ( V_31 . V_11 , V_32 ) ;
V_9 = F_19 ( & V_31 , V_5 , V_6 , V_7 , V_8 ) ;
F_24 ( V_31 . V_11 ) ;
return V_9 ;
}
static int F_25 ( T_1 * V_28 ,
int V_5 ,
void T_2 * V_6 , T_3 * V_7 ,
T_4 * V_8 )
{
T_1 V_31 = { . V_12 = V_32 } ;
int V_9 ;
V_31 . V_11 = F_22 ( V_31 . V_12 , V_33 ) ;
if ( ! V_31 . V_11 )
return - V_34 ;
F_26 ( V_31 . V_11 , V_31 . V_12 ) ;
V_9 = F_19 ( & V_31 , V_5 , V_6 , V_7 , V_8 ) ;
if ( V_5 && V_9 == 0 )
V_9 = F_27 ( V_31 . V_11 ) ;
F_24 ( V_31 . V_11 ) ;
return V_9 ;
}
static int F_28 ( T_1 * V_28 , int V_5 ,
void T_2 * V_6 , T_3 * V_7 ,
T_4 * V_8 )
{
int V_9 ;
unsigned long V_35 [ 3 ] ;
struct V_36 * V_36 = V_37 -> V_38 -> V_39 ;
#ifdef F_29
struct V_40 * V_41 ;
#endif
T_1 V_10 = {
. V_11 = & V_35 ,
. V_12 = sizeof( V_35 ) ,
. V_13 = V_28 -> V_13 ,
} ;
if ( ! V_5 ) {
V_28 -> V_11 = & V_36 -> V_42 . V_43 ;
return F_30 ( V_28 , V_5 , V_6 , V_7 , V_8 ) ;
}
V_9 = F_30 ( & V_10 , V_5 , V_6 , V_7 , V_8 ) ;
if ( V_9 )
return V_9 ;
#ifdef F_29
F_31 () ;
V_41 = F_32 ( V_37 ) ;
F_33 ( V_41 , V_35 [ 0 ] , 0 ) ;
F_33 ( V_41 , V_35 [ 1 ] , 1 ) ;
F_33 ( V_41 , V_35 [ 2 ] , 2 ) ;
F_34 () ;
#endif
V_36 -> V_42 . V_43 [ 0 ] = V_35 [ 0 ] ;
V_36 -> V_42 . V_43 [ 1 ] = V_35 [ 1 ] ;
V_36 -> V_42 . V_43 [ 2 ] = V_35 [ 2 ] ;
return 0 ;
}
static int F_35 ( T_1 * V_28 , int V_5 , void T_2 * V_6 ,
T_3 * V_7 , T_4 * V_8 )
{
T_1 V_31 = { . V_12 = ( V_44 * 2 + 10 ) } ;
struct V_45 * V_46 ;
int V_9 ;
T_7 V_47 [ 4 ] ;
V_31 . V_11 = F_22 ( V_31 . V_12 , V_48 ) ;
if ( ! V_31 . V_11 )
return - V_34 ;
F_31 () ;
V_46 = F_36 ( V_49 ) ;
if ( V_46 )
memcpy ( V_47 , V_46 -> V_50 , V_44 ) ;
else
memset ( V_47 , 0 , sizeof( V_47 ) ) ;
F_34 () ;
snprintf ( V_31 . V_11 , V_31 . V_12 , L_1 ,
V_47 [ 0 ] , V_47 [ 1 ] , V_47 [ 2 ] , V_47 [ 3 ] ) ;
V_9 = F_19 ( & V_31 , V_5 , V_6 , V_7 , V_8 ) ;
if ( V_5 && V_9 == 0 ) {
if ( sscanf ( V_31 . V_11 , L_2 , V_47 , V_47 + 1 ,
V_47 + 2 , V_47 + 3 ) != 4 ) {
V_9 = - V_18 ;
goto V_51;
}
F_37 ( V_47 , V_44 ) ;
}
V_51:
F_38 ( L_3 ,
V_47 [ 0 ] , V_47 [ 1 ] , V_47 [ 2 ] , V_47 [ 3 ] ,
( char * ) V_31 . V_11 , V_9 ) ;
F_24 ( V_31 . V_11 ) ;
return V_9 ;
}
static T_8 int F_39 ( struct V_36 * V_36 )
{
struct T_1 * V_4 ;
V_4 = V_52 ;
if ( ! F_40 ( V_36 , & V_53 ) ) {
V_4 = F_41 ( V_4 , sizeof( V_52 ) , V_48 ) ;
if ( V_4 == NULL )
goto V_54;
V_4 [ 0 ] . V_11 =
& V_36 -> V_42 . V_55 ;
V_4 [ 1 ] . V_11 =
& V_36 -> V_42 . V_56 ;
V_4 [ 2 ] . V_11 =
& V_36 -> V_42 . V_57 ;
V_4 [ 3 ] . V_11 =
& V_36 -> V_42 . V_58 ;
V_4 [ 4 ] . V_11 =
& V_36 -> V_42 . V_59 ;
V_4 [ 5 ] . V_11 =
& V_36 -> V_42 . V_60 ;
V_4 [ 6 ] . V_11 =
& V_36 -> V_42 . V_61 ;
V_4 [ 7 ] . V_11 =
& V_36 -> V_42 . V_62 ;
if ( V_36 -> V_23 != & V_27 )
V_4 [ 0 ] . V_63 = NULL ;
}
V_36 -> V_42 . V_61 [ 0 ] = F_14 ( & V_27 , 1 ) ;
V_36 -> V_42 . V_61 [ 1 ] = F_14 ( & V_27 , 0 ) ;
F_42 ( V_36 ) ;
V_36 -> V_42 . V_64 = F_43 ( V_36 , L_4 , V_4 ) ;
if ( V_36 -> V_42 . V_64 == NULL )
goto V_65;
return 0 ;
V_65:
if ( ! F_40 ( V_36 , & V_53 ) )
F_24 ( V_4 ) ;
V_54:
return - V_34 ;
}
static T_9 void F_44 ( struct V_36 * V_36 )
{
struct T_1 * V_4 ;
V_4 = V_36 -> V_42 . V_64 -> V_66 ;
F_45 ( V_36 -> V_42 . V_64 ) ;
F_24 ( V_4 ) ;
}
static T_10 int F_46 ( void )
{
struct V_67 * V_68 ;
struct T_1 * V_69 ;
for ( V_69 = V_70 ; V_69 -> V_63 ; V_69 ++ ) {
if ( strcmp ( V_69 -> V_63 , L_5 ) == 0 ) {
V_69 -> V_11 = V_71 ;
break;
}
}
if ( ! V_69 -> V_63 )
return - V_18 ;
V_68 = F_43 ( & V_53 , L_4 , V_70 ) ;
if ( V_68 == NULL )
return - V_34 ;
if ( F_47 ( & V_72 ) ) {
F_45 ( V_68 ) ;
return - V_34 ;
}
return 0 ;
}
