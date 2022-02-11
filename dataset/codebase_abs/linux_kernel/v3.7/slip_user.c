static int F_1 ( void * V_1 , void * V_2 )
{
struct V_3 * V_4 = V_1 ;
V_4 -> V_2 = V_2 ;
return 0 ;
}
static int F_2 ( int V_5 )
{
int V_6 ;
struct V_7 V_8 ;
if ( F_3 ( V_5 , & V_8 ) < 0 ) {
F_4 ( V_9 L_1
L_2 ) ;
return - 1 ;
}
V_8 . V_10 = V_11 | V_12 | V_13 | V_14 ;
V_8 . V_15 = V_16 | V_17 ;
V_8 . V_18 = 0 ;
V_8 . V_19 = 0 ;
for ( V_6 = 0 ; V_6 < V_20 ; V_6 ++ )
V_8 . V_21 [ V_6 ] = 0 ;
V_8 . V_21 [ V_22 ] = 1 ;
V_8 . V_21 [ V_23 ] = 0 ;
F_5 ( & V_8 , V_24 ) ;
F_6 ( & V_8 , V_24 ) ;
if ( F_7 ( V_5 , V_25 , & V_8 ) < 0 ) {
F_4 ( V_9 L_3 ) ;
return - 1 ;
}
return 0 ;
}
static void F_8 ( void * V_26 )
{
struct V_27 * V_1 = V_26 ;
if ( V_1 -> V_28 >= 0 )
F_9 ( V_1 -> V_28 , 0 ) ;
F_9 ( V_1 -> stdout , 1 ) ;
if ( V_1 -> V_29 >= 0 )
F_10 ( V_1 -> V_29 ) ;
}
static int F_11 ( char * * V_30 , int V_5 )
{
struct V_27 V_31 ;
char * V_32 ;
int V_33 , V_34 [ 2 ] , V_35 , V_36 ;
V_35 = F_12 ( V_34 , 1 , 0 ) ;
if ( V_35 < 0 ) {
F_4 ( V_9 L_4 ,
- V_35 ) ;
goto V_37;
}
V_35 = 0 ;
V_31 . V_28 = V_5 ;
V_31 . stdout = V_34 [ 1 ] ;
V_31 . V_29 = V_34 [ 0 ] ;
V_35 = F_13 ( F_8 , & V_31 , V_30 ) ;
if ( V_35 < 0 )
goto V_38;
V_33 = V_35 ;
V_36 = V_39 ;
V_32 = F_14 ( V_36 , V_40 ) ;
if ( V_32 == NULL ) {
F_4 ( V_9 L_5
L_6 ) ;
F_15 ( V_33 , 1 ) ;
V_35 = - V_41 ;
goto V_38;
}
F_10 ( V_34 [ 1 ] ) ;
F_16 ( V_34 [ 0 ] , V_32 , V_36 ) ;
F_4 ( L_7 , V_32 ) ;
V_35 = F_17 ( V_33 ) ;
F_10 ( V_34 [ 0 ] ) ;
F_18 ( V_32 ) ;
return V_35 ;
V_38:
F_10 ( V_34 [ 0 ] ) ;
F_10 ( V_34 [ 1 ] ) ;
V_37:
return V_35 ;
}
static int F_19 ( void * V_1 )
{
struct V_3 * V_4 = V_1 ;
char V_42 [ sizeof( L_8 ) ] ;
char V_43 [ sizeof( L_9 ) ] ;
char * V_30 [] = { L_10 , V_42 , L_11 , L_12 , V_43 ,
NULL } ;
int V_44 , V_45 , V_35 ;
V_35 = F_20 () ;
if ( V_35 < 0 ) {
F_4 ( V_9 L_13 ,
- V_35 ) ;
goto V_37;
}
V_45 = V_35 ;
V_35 = F_21 ( F_22 ( V_45 ) , V_46 , 0 ) ;
if ( V_35 < 0 ) {
F_4 ( V_9 L_14
L_15 , - V_35 ) ;
goto V_38;
}
V_44 = V_35 ;
if ( F_2 ( V_44 ) )
goto V_47;
V_4 -> V_48 = V_44 ;
V_4 -> V_49 . V_50 = 0 ;
V_4 -> V_49 . V_51 = 0 ;
if ( V_4 -> V_52 != NULL ) {
sprintf ( V_42 , L_16 , V_53 ) ;
strcpy ( V_43 , V_4 -> V_52 ) ;
V_35 = F_11 ( V_30 , V_44 ) ;
if ( V_35 < 0 ) {
F_4 ( V_9 L_17 ,
- V_35 ) ;
goto V_47;
}
V_35 = F_23 ( V_4 -> V_48 , V_4 -> V_54 ) ;
if ( V_35 < 0 ) {
F_4 ( V_9 L_18 ,
- V_35 ) ;
goto V_47;
}
F_24 ( V_4 -> V_2 , V_55 , V_4 -> V_54 ) ;
}
else {
V_35 = F_25 ( V_44 ) ;
if ( V_35 < 0 ) {
F_4 ( V_9 L_19
L_20 , - V_35 ) ;
goto V_47;
}
}
return V_45 ;
V_47:
F_10 ( V_44 ) ;
V_38:
F_10 ( V_45 ) ;
V_37:
return V_35 ;
}
static void F_26 ( int V_5 , void * V_1 )
{
struct V_3 * V_4 = V_1 ;
char V_42 [ sizeof( L_8 ) ] ;
char * V_30 [] = { L_10 , V_42 , L_11 , L_21 , V_4 -> V_54 ,
NULL } ;
int V_35 ;
if ( V_4 -> V_52 != NULL )
F_24 ( V_4 -> V_2 , V_56 , V_4 -> V_54 ) ;
sprintf ( V_42 , L_16 , V_53 ) ;
V_35 = F_11 ( V_30 , V_4 -> V_48 ) ;
if ( V_35 != 0 )
F_4 ( V_9 L_22 , - V_35 ) ;
F_10 ( V_5 ) ;
F_10 ( V_4 -> V_48 ) ;
V_4 -> V_48 = - 1 ;
}
int F_27 ( int V_5 , void * V_57 , int V_58 , struct V_3 * V_4 )
{
return F_28 ( V_5 , V_57 , V_58 , & V_4 -> V_49 ) ;
}
int F_29 ( int V_5 , void * V_57 , int V_58 , struct V_3 * V_4 )
{
return F_30 ( V_5 , V_57 , V_58 , & V_4 -> V_49 ) ;
}
static void F_31 ( unsigned char * V_59 , unsigned char * V_60 ,
void * V_1 )
{
struct V_3 * V_4 = V_1 ;
if ( V_4 -> V_48 < 0 )
return;
V_55 ( V_59 , V_60 , V_4 -> V_54 ) ;
}
static void F_32 ( unsigned char * V_59 , unsigned char * V_60 ,
void * V_1 )
{
struct V_3 * V_4 = V_1 ;
if ( V_4 -> V_48 < 0 )
return;
V_56 ( V_59 , V_60 , V_4 -> V_54 ) ;
}
