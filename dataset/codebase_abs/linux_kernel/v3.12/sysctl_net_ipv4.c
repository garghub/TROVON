static void F_1 ( int V_1 [ 2 ] )
{
F_2 ( & V_2 . V_3 ) ;
V_2 . V_1 [ 0 ] = V_1 [ 0 ] ;
V_2 . V_1 [ 1 ] = V_1 [ 1 ] ;
F_3 ( & V_2 . V_3 ) ;
}
static int F_4 ( struct V_4 * V_5 , int V_6 ,
void T_1 * V_7 ,
T_2 * V_8 , T_3 * V_9 )
{
int V_10 ;
int V_1 [ 2 ] ;
struct V_4 V_11 = {
. V_12 = & V_1 ,
. V_13 = sizeof( V_1 ) ,
. V_14 = V_5 -> V_14 ,
. V_15 = & V_16 ,
. V_17 = & V_18 ,
} ;
F_5 ( V_1 , V_1 + 1 ) ;
V_10 = F_6 ( & V_11 , V_6 , V_7 , V_8 , V_9 ) ;
if ( V_6 && V_10 == 0 ) {
if ( V_1 [ 1 ] < V_1 [ 0 ] )
V_10 = - V_19 ;
else
F_1 ( V_1 ) ;
}
return V_10 ;
}
static void F_7 ( struct V_4 * V_5 , T_4 * V_20 , T_4 * V_21 )
{
T_4 * V_12 = V_5 -> V_12 ;
unsigned int V_22 ;
do {
V_22 = F_8 ( & V_2 . V_3 ) ;
* V_20 = V_12 [ 0 ] ;
* V_21 = V_12 [ 1 ] ;
} while ( F_9 ( & V_2 . V_3 , V_22 ) );
}
static void F_10 ( struct V_4 * V_5 , T_4 V_20 , T_4 V_21 )
{
T_4 * V_12 = V_5 -> V_12 ;
F_2 ( & V_2 . V_3 ) ;
V_12 [ 0 ] = V_20 ;
V_12 [ 1 ] = V_21 ;
F_3 ( & V_2 . V_3 ) ;
}
static int F_11 ( struct V_4 * V_5 , int V_6 ,
void T_1 * V_7 ,
T_2 * V_8 , T_3 * V_9 )
{
struct V_23 * V_24 = F_12 () ;
int V_10 ;
T_5 V_25 [ 2 ] ;
T_4 V_20 , V_21 ;
struct V_4 V_11 = {
. V_12 = & V_25 ,
. V_13 = sizeof( V_25 ) ,
. V_14 = V_5 -> V_14 ,
. V_15 = & V_26 ,
. V_17 = & V_27 ,
} ;
F_7 ( V_5 , & V_20 , & V_21 ) ;
V_25 [ 0 ] = F_13 ( V_24 , V_20 ) ;
V_25 [ 1 ] = F_13 ( V_24 , V_21 ) ;
V_10 = F_6 ( & V_11 , V_6 , V_7 , V_8 , V_9 ) ;
if ( V_6 && V_10 == 0 ) {
V_20 = F_14 ( V_24 , V_25 [ 0 ] ) ;
V_21 = F_14 ( V_24 , V_25 [ 1 ] ) ;
if ( ! F_15 ( V_20 ) || ! F_15 ( V_21 ) ||
( V_25 [ 1 ] < V_25 [ 0 ] ) || F_16 ( V_21 , V_20 ) ) {
V_20 = F_14 ( & V_28 , 1 ) ;
V_21 = F_14 ( & V_28 , 0 ) ;
}
F_10 ( V_5 , V_20 , V_21 ) ;
}
return V_10 ;
}
static int F_17 ( struct V_4 * V_29 , int V_6 ,
void T_1 * V_7 , T_2 * V_8 , T_3 * V_9 )
{
char V_30 [ V_31 ] ;
struct V_4 V_32 = {
. V_12 = V_30 ,
. V_13 = V_31 ,
} ;
int V_10 ;
F_18 ( V_30 ) ;
V_10 = F_19 ( & V_32 , V_6 , V_7 , V_8 , V_9 ) ;
if ( V_6 && V_10 == 0 )
V_10 = F_20 ( V_30 ) ;
return V_10 ;
}
static int F_21 ( struct V_4 * V_29 ,
int V_6 ,
void T_1 * V_7 , T_2 * V_8 ,
T_3 * V_9 )
{
struct V_4 V_32 = { . V_13 = V_33 , } ;
int V_10 ;
V_32 . V_12 = F_22 ( V_32 . V_13 , V_34 ) ;
if ( ! V_32 . V_12 )
return - V_35 ;
F_23 ( V_32 . V_12 , V_33 ) ;
V_10 = F_19 ( & V_32 , V_6 , V_7 , V_8 , V_9 ) ;
F_24 ( V_32 . V_12 ) ;
return V_10 ;
}
static int F_25 ( struct V_4 * V_29 ,
int V_6 ,
void T_1 * V_7 , T_2 * V_8 ,
T_3 * V_9 )
{
struct V_4 V_32 = { . V_13 = V_33 } ;
int V_10 ;
V_32 . V_12 = F_22 ( V_32 . V_13 , V_34 ) ;
if ( ! V_32 . V_12 )
return - V_35 ;
F_26 ( V_32 . V_12 , V_32 . V_13 ) ;
V_10 = F_19 ( & V_32 , V_6 , V_7 , V_8 , V_9 ) ;
if ( V_6 && V_10 == 0 )
V_10 = F_27 ( V_32 . V_12 ) ;
F_24 ( V_32 . V_12 ) ;
return V_10 ;
}
static int F_28 ( struct V_4 * V_29 , int V_6 ,
void T_1 * V_7 , T_2 * V_8 ,
T_3 * V_9 )
{
int V_10 ;
unsigned long V_36 [ 3 ] ;
struct V_37 * V_37 = V_38 -> V_39 -> V_40 ;
#ifdef F_29
struct V_41 * V_42 ;
#endif
struct V_4 V_11 = {
. V_12 = & V_36 ,
. V_13 = sizeof( V_36 ) ,
. V_14 = V_29 -> V_14 ,
} ;
if ( ! V_6 ) {
V_29 -> V_12 = & V_37 -> V_43 . V_44 ;
return F_30 ( V_29 , V_6 , V_7 , V_8 , V_9 ) ;
}
V_10 = F_30 ( & V_11 , V_6 , V_7 , V_8 , V_9 ) ;
if ( V_10 )
return V_10 ;
#ifdef F_29
F_31 () ;
V_42 = F_32 ( V_38 ) ;
F_33 ( V_42 , V_36 [ 0 ] , 0 ) ;
F_33 ( V_42 , V_36 [ 1 ] , 1 ) ;
F_33 ( V_42 , V_36 [ 2 ] , 2 ) ;
F_34 () ;
#endif
V_37 -> V_43 . V_44 [ 0 ] = V_36 [ 0 ] ;
V_37 -> V_43 . V_44 [ 1 ] = V_36 [ 1 ] ;
V_37 -> V_43 . V_44 [ 2 ] = V_36 [ 2 ] ;
return 0 ;
}
static int F_35 ( struct V_4 * V_29 , int V_6 ,
void T_1 * V_7 , T_2 * V_8 ,
T_3 * V_9 )
{
struct V_4 V_32 = { . V_13 = ( V_45 * 2 + 10 ) } ;
struct V_46 * V_47 ;
int V_10 ;
T_6 V_48 [ 4 ] ;
V_32 . V_12 = F_22 ( V_32 . V_13 , V_49 ) ;
if ( ! V_32 . V_12 )
return - V_35 ;
F_31 () ;
V_47 = F_36 ( V_50 ) ;
if ( V_47 )
memcpy ( V_48 , V_47 -> V_51 , V_45 ) ;
else
memset ( V_48 , 0 , sizeof( V_48 ) ) ;
F_34 () ;
snprintf ( V_32 . V_12 , V_32 . V_13 , L_1 ,
V_48 [ 0 ] , V_48 [ 1 ] , V_48 [ 2 ] , V_48 [ 3 ] ) ;
V_10 = F_19 ( & V_32 , V_6 , V_7 , V_8 , V_9 ) ;
if ( V_6 && V_10 == 0 ) {
if ( sscanf ( V_32 . V_12 , L_2 , V_48 , V_48 + 1 ,
V_48 + 2 , V_48 + 3 ) != 4 ) {
V_10 = - V_19 ;
goto V_52;
}
F_37 ( V_48 , V_45 ) ;
}
V_52:
F_38 ( L_3 ,
V_48 [ 0 ] , V_48 [ 1 ] , V_48 [ 2 ] , V_48 [ 3 ] ,
( char * ) V_32 . V_12 , V_10 ) ;
F_24 ( V_32 . V_12 ) ;
return V_10 ;
}
static T_7 int F_39 ( struct V_37 * V_37 )
{
struct V_4 * V_5 ;
V_5 = V_53 ;
if ( ! F_40 ( V_37 , & V_54 ) ) {
V_5 = F_41 ( V_5 , sizeof( V_53 ) , V_49 ) ;
if ( V_5 == NULL )
goto V_55;
V_5 [ 0 ] . V_12 =
& V_37 -> V_43 . V_56 ;
V_5 [ 1 ] . V_12 =
& V_37 -> V_43 . V_57 ;
V_5 [ 2 ] . V_12 =
& V_37 -> V_43 . V_58 ;
V_5 [ 3 ] . V_12 =
& V_37 -> V_43 . V_59 ;
V_5 [ 4 ] . V_12 =
& V_37 -> V_43 . V_60 ;
V_5 [ 5 ] . V_12 =
& V_37 -> V_43 . V_61 ;
V_5 [ 6 ] . V_12 =
& V_37 -> V_43 . V_62 ;
V_5 [ 7 ] . V_12 =
& V_37 -> V_43 . V_63 ;
if ( V_37 -> V_24 != & V_28 )
V_5 [ 0 ] . V_64 = NULL ;
}
V_37 -> V_43 . V_62 [ 0 ] = F_14 ( & V_28 , 1 ) ;
V_37 -> V_43 . V_62 [ 1 ] = F_14 ( & V_28 , 0 ) ;
F_42 ( V_37 ) ;
V_37 -> V_43 . V_65 = F_43 ( V_37 , L_4 , V_5 ) ;
if ( V_37 -> V_43 . V_65 == NULL )
goto V_66;
return 0 ;
V_66:
if ( ! F_40 ( V_37 , & V_54 ) )
F_24 ( V_5 ) ;
V_55:
return - V_35 ;
}
static T_8 void F_44 ( struct V_37 * V_37 )
{
struct V_4 * V_5 ;
V_5 = V_37 -> V_43 . V_65 -> V_67 ;
F_45 ( V_37 -> V_43 . V_65 ) ;
F_24 ( V_5 ) ;
}
static T_9 int F_46 ( void )
{
struct V_68 * V_69 ;
struct V_4 * V_70 ;
for ( V_70 = V_71 ; V_70 -> V_64 ; V_70 ++ ) {
if ( strcmp ( V_70 -> V_64 , L_5 ) == 0 ) {
V_70 -> V_12 = V_72 ;
break;
}
}
if ( ! V_70 -> V_64 )
return - V_19 ;
V_69 = F_43 ( & V_54 , L_4 , V_71 ) ;
if ( V_69 == NULL )
return - V_35 ;
if ( F_47 ( & V_73 ) ) {
F_45 ( V_69 ) ;
return - V_35 ;
}
return 0 ;
}
