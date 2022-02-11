static void F_1 ( T_1 V_1 )
{
struct V_2 * V_3 ;
if ( ! V_1 )
return;
V_3 = F_2 ( V_1 ) ;
if ( V_4 )
printf ( L_1 , V_3 -> V_5 , V_1 ) ;
else
printf ( L_2 , V_3 -> V_5 ) ;
}
static void F_3 ( struct V_6 * V_7 , T_1 V_8 )
{
T_1 V_9 [ V_10 ] = {} ;
static bool V_11 ;
int V_12 ;
printf ( L_2 , V_7 -> V_13 ) ;
if ( F_4 ( V_14 [ 3 ] , & V_7 -> V_15 , V_9 ) != 0 ) {
printf ( L_3 ) ;
} else {
for ( V_12 = V_10 - 1 ; V_12 >= 0 ; V_12 -- )
F_1 ( V_9 [ V_12 ] ) ;
}
printf ( L_4 ) ;
if ( F_4 ( V_14 [ 3 ] , & V_7 -> V_16 , V_9 ) != 0 ) {
printf ( L_3 ) ;
} else {
for ( V_12 = 0 ; V_12 < V_10 ; V_12 ++ )
F_1 ( V_9 [ V_12 ] ) ;
}
printf ( L_5 , V_7 -> V_17 , V_8 ) ;
if ( ( V_7 -> V_15 == - V_18 || V_7 -> V_16 == - V_18 ) && ! V_11 ) {
printf ( L_6 ) ;
V_11 = true ;
} else if ( ( ( int ) ( V_7 -> V_15 ) < 0 || ( int ) ( V_7 -> V_16 ) < 0 ) ) {
printf ( L_7 , V_7 -> V_15 , V_7 -> V_16 ) ;
}
}
static void F_5 ( int V_19 )
{
struct V_6 V_7 = {} , V_20 ;
T_1 V_21 ;
while ( F_6 ( V_19 , & V_7 , & V_20 ) == 0 ) {
F_4 ( V_19 , & V_20 , & V_21 ) ;
F_3 ( & V_20 , V_21 ) ;
V_7 = V_20 ;
}
}
static void F_7 ( int V_22 )
{
F_5 ( V_14 [ 0 ] ) ;
exit ( 0 ) ;
}
int main ( int V_23 , char * * V_24 )
{
struct V_25 V_26 = { V_27 , V_27 } ;
char V_28 [ 256 ] ;
int V_29 = 1 ;
snprintf ( V_28 , sizeof( V_28 ) , L_8 , V_24 [ 0 ] ) ;
F_8 ( V_30 , & V_26 ) ;
signal ( V_31 , F_7 ) ;
signal ( V_32 , F_7 ) ;
if ( F_9 () ) {
printf ( L_9 ) ;
return 2 ;
}
if ( F_10 ( V_28 ) ) {
printf ( L_10 , V_33 ) ;
return 1 ;
}
if ( V_23 > 1 )
V_29 = atoi ( V_24 [ 1 ] ) ;
F_11 ( V_29 ) ;
F_5 ( V_14 [ 0 ] ) ;
return 0 ;
}
