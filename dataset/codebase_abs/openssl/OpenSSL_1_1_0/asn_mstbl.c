static int F_1 ( T_1 * V_1 , const T_2 * V_2 )
{
int V_3 ;
const char * V_4 ;
F_2 ( V_5 ) * V_6 ;
V_5 * V_7 ;
V_4 = F_3 ( V_1 ) ;
if ( ( V_6 = F_4 ( V_2 , V_4 ) ) == NULL ) {
F_5 ( V_8 , V_9 ) ;
return 0 ;
}
for ( V_3 = 0 ; V_3 < F_6 ( V_6 ) ; V_3 ++ ) {
V_7 = F_7 ( V_6 , V_3 ) ;
if ( ! F_8 ( V_7 -> V_10 , V_7 -> V_11 ) ) {
F_5 ( V_8 , V_12 ) ;
return 0 ;
}
}
return 1 ;
}
static void F_9 ( T_1 * V_1 )
{
F_10 () ;
}
void F_11 ( void )
{
F_12 ( L_1 , F_1 , F_9 ) ;
}
static int F_8 ( const char * V_10 , const char * V_11 )
{
char * V_13 ;
int V_14 , V_3 , V_15 = 0 ;
long V_16 = - 1 , V_17 = - 1 ;
unsigned long V_18 = 0 , V_19 = 0 ;
F_2 ( V_5 ) * V_20 = NULL ;
V_5 * V_2 = NULL ;
V_14 = F_13 ( V_11 ) ;
if ( V_14 == V_21 )
V_14 = F_14 ( V_11 ) ;
if ( V_14 == V_21 )
goto V_22;
V_20 = F_15 ( V_10 ) ;
if ( ! V_20 )
goto V_22;
for ( V_3 = 0 ; V_3 < F_6 ( V_20 ) ; V_3 ++ ) {
V_2 = F_7 ( V_20 , V_3 ) ;
if ( strcmp ( V_2 -> V_11 , L_2 ) == 0 ) {
V_16 = strtoul ( V_2 -> V_10 , & V_13 , 0 ) ;
if ( * V_13 )
goto V_22;
} else if ( strcmp ( V_2 -> V_11 , L_3 ) == 0 ) {
V_17 = strtoul ( V_2 -> V_10 , & V_13 , 0 ) ;
if ( * V_13 )
goto V_22;
} else if ( strcmp ( V_2 -> V_11 , L_4 ) == 0 ) {
if ( ! F_16 ( V_2 -> V_10 , & V_18 ) || ! V_18 )
goto V_22;
} else if ( strcmp ( V_2 -> V_11 , L_5 ) == 0 ) {
if ( strcmp ( V_2 -> V_10 , L_6 ) == 0 )
V_19 = V_23 ;
else if ( strcmp ( V_2 -> V_10 , L_7 ) == 0 )
V_19 = V_24 ;
else
goto V_22;
} else
goto V_22;
}
V_15 = 1 ;
V_22:
if ( V_15 == 0 ) {
F_5 ( V_25 , V_26 ) ;
if ( V_2 )
F_17 ( 4 , L_8 , V_2 -> V_11 ,
L_9 , V_2 -> V_10 ) ;
else
F_17 ( 4 , L_10 , V_11 , L_9 , V_10 ) ;
} else {
V_15 = F_18 ( V_14 , V_16 , V_17 ,
V_18 , V_19 ) ;
if ( ! V_15 )
F_5 ( V_25 , V_27 ) ;
}
F_19 ( V_20 , V_28 ) ;
return V_15 ;
}
