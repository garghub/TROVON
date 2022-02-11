int
main ( int V_1 , const char * * V_2 )
{
unsigned int V_3 ;
V_1 -- ;
V_2 ++ ;
if ( ! V_1 ) {
fprintf ( V_4 , L_1 ) ;
return - 1 ;
}
for ( V_3 = 0 ; V_3 < ( sizeof ( V_5 ) / sizeof ( V_5 [ 0 ] ) ) ; V_3 ++ )
if ( ! strcmp ( V_2 [ 0 ] , V_5 [ V_3 ] . V_6 ) ) {
V_1 -- ;
V_2 ++ ;
fprintf ( V_4 , L_2 ,
V_5 [ V_3 ] . V_6 ) ;
V_5 [ V_3 ] . F_1 ( V_1 , V_2 ) ;
return 0 ;
}
fprintf ( V_4 , L_3 , V_2 [ 0 ] ) ;
return - 1 ;
}
void
F_2 ( int V_1 , const char * * V_2 )
{
int V_7 ;
if ( V_1 != 1 ) {
fprintf ( V_4 , L_4 ) ;
return;
}
V_7 = F_3 ( V_2 [ 0 ] , V_8 ) ;
if ( V_7 < 0 )
fprintf ( V_4 , L_5 ) ;
else
F_4 ( V_7 ) ;
return;
}
void
F_5 ( int V_1 , const char * * V_2 )
{
struct F_5 V_9 ;
int V_7 ;
if ( V_1 != 1 ) {
fprintf ( V_4 , L_6 ) ;
return;
}
V_7 = F_3 ( V_2 [ 0 ] , V_8 ) ;
if ( V_7 < 0 ) {
fprintf ( V_4 , L_7 , V_2 [ 0 ] ) ;
return;
}
if ( F_6 ( V_7 , V_10 , & V_9 ) < 0 ) {
fprintf ( V_4 , L_8 ) ;
goto V_11;
}
fprintf ( V_4 , L_9 ,
V_9 . V_12 , V_9 . V_13 ) ;
fprintf ( V_4 , L_10 ,
V_9 . V_14 , V_9 . V_15 ) ;
V_11:
F_4 ( V_7 ) ;
return;
}
void
F_7 ( int V_1 , const char * * V_2 )
{
unsigned long V_16 ;
int V_17 , V_3 , V_7 ;
struct V_18 V_19 ;
struct F_5 V_9 ;
struct V_20 V_21 , V_22 ;
struct V_23 V_24 ;
long V_25 ;
if ( V_1 != 3 ) {
fprintf ( V_4 , L_11 ) ;
return;
}
V_16 = atoi ( V_2 [ 1 ] ) ;
V_17 = atoi ( V_2 [ 2 ] ) ;
V_7 = F_3 ( V_2 [ 0 ] , V_8 ) ;
if ( V_7 < 0 ) {
fprintf ( V_4 , L_12 , V_2 [ 0 ] ) ;
return;
}
if ( F_6 ( V_7 , V_26 , V_16 ) < 0 ) {
fprintf ( V_4 , L_13 ) ;
goto V_11;
}
if ( F_6 ( V_7 , V_10 , & V_9 ) < 0 ) {
fprintf ( V_4 , L_14 ) ;
goto V_11;
}
fprintf ( V_4 , L_15 , V_9 . V_13 ) ;
if ( V_9 . V_13 && ( F_6 ( V_7 , V_27 , 0 ) < 0 ) ) {
fprintf ( V_4 , L_16 ) ;
goto V_11;
}
if ( F_6 ( V_7 , V_28 , 0 ) < 0 ) {
fprintf ( V_4 , L_17 ) ;
goto V_11;
}
V_19 . V_7 = V_7 ;
V_19 . V_29 = V_30 ;
for ( V_3 = 0 ; V_3 < V_17 ; V_3 ++ ) {
V_19 . V_31 = 0 ;
F_8 ( & V_21 , & V_24 ) ;
if ( F_9 ( & V_19 , 1 , - 1 ) < 0 )
fprintf ( V_4 , L_18 ) ;
else {
long V_32 ;
F_8 ( & V_22 , & V_24 ) ;
V_25 = V_21 . V_33 * 1000000 + V_21 . V_34 ;
V_25 = ( V_22 . V_33 * 1000000 + V_22 . V_34 ) - V_25 ;
fprintf ( V_4 ,
L_19 , V_25 ) ;
fprintf ( V_4 , L_20 ,
V_19 . V_31 ) ;
if ( F_10 ( V_7 , & V_32 , sizeof( V_32 ) ) != sizeof( V_32 ) ) {
fprintf ( V_4 , L_21 ) ;
}
else
fprintf ( V_4 , L_22 ,
V_32 ) ;
}
}
V_11:
F_4 ( V_7 ) ;
return;
}
static void
F_11 ( int V_35 )
{
fprintf ( V_4 , L_23 ) ;
V_36 ++ ;
}
void
F_12 ( int V_1 , const char * * V_2 )
{
unsigned long V_16 ;
int V_17 , V_3 , V_7 , V_37 ;
T_1 V_38 ;
struct F_5 V_9 ;
V_36 = 0 ;
V_7 = - 1 ;
if ( ( V_38 = signal ( V_39 , F_11 ) ) == V_40 ) {
fprintf ( V_4 , L_24 ) ;
return;
}
if ( V_1 != 3 ) {
fprintf ( V_4 , L_25 ) ;
goto V_11;
}
V_7 = F_3 ( V_2 [ 0 ] , V_8 ) ;
if ( V_7 < 0 ) {
fprintf ( V_4 , L_26 , V_2 [ 0 ] ) ;
return;
}
if ( ( F_13 ( V_7 , V_41 , F_14 () ) == 1 ) ||
( ( V_37 = F_13 ( V_7 , V_42 ) ) == 1 ) ||
( F_13 ( V_7 , V_43 , V_37 | V_44 ) == 1 ) ) {
fprintf ( V_4 , L_27 ) ;
goto V_11;
}
V_16 = atoi ( V_2 [ 1 ] ) ;
V_17 = atoi ( V_2 [ 2 ] ) ;
if ( F_6 ( V_7 , V_26 , V_16 ) < 0 ) {
fprintf ( V_4 , L_28 ) ;
goto V_11;
}
if ( F_6 ( V_7 , V_10 , & V_9 ) < 0 ) {
fprintf ( V_4 , L_29 ) ;
goto V_11;
}
fprintf ( V_4 , L_30 , V_9 . V_13 ) ;
if ( V_9 . V_13 && ( F_6 ( V_7 , V_27 , 0 ) < 0 ) ) {
fprintf ( V_4 , L_31 ) ;
goto V_11;
}
if ( F_6 ( V_7 , V_28 , 0 ) < 0 ) {
fprintf ( V_4 , L_32 ) ;
goto V_11;
}
for ( V_3 = 0 ; V_3 < V_17 ; V_3 ++ ) {
( void ) F_15 () ;
fprintf ( V_4 , L_33 , V_36 ) ;
}
V_11:
signal ( V_39 , V_38 ) ;
if ( V_7 >= 0 )
F_4 ( V_7 ) ;
return;
}
