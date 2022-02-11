void F_1 ( unsigned long V_1 )
{
V_2 = V_1 ;
}
unsigned long F_2 ( void )
{
return V_2 ;
}
int F_3 ( const char * V_3 )
{
unsigned long V_1 ;
char * V_4 ;
if ( strncmp ( V_3 , L_1 , 5 ) == 0 ) {
if ( ! V_3 [ 5 ] )
return 0 ;
V_1 = strtoul ( V_3 + 5 , & V_4 , 0 ) ;
if ( * V_4 )
return 0 ;
} else if ( strcmp ( V_3 , L_2 ) == 0 )
V_1 = ~ ( ( unsigned long ) ( V_5 | V_6 ) ) ;
else if ( strcmp ( V_3 , L_3 ) == 0 )
V_1 = ~ ( ( unsigned long ) V_7 ) ;
else if ( strcmp ( V_3 , L_4 ) == 0 )
V_1 = V_6 ;
else if ( strcmp ( V_3 , L_5 ) == 0 )
V_1 = 0xFFFFFFFFL ;
else
return 0 ;
F_1 ( V_1 ) ;
return 1 ;
}
T_1 * F_4 ( T_1 * * V_8 ,
const unsigned char * V_9 , int V_10 ,
int V_11 , int V_12 )
{
T_2 * V_13 ;
T_1 * V_14 = NULL ;
unsigned long V_1 ;
int V_15 ;
if ( ! V_8 )
V_8 = & V_14 ;
V_13 = F_5 ( V_12 ) ;
if ( V_13 ) {
V_1 = V_13 -> V_1 ;
if ( ! ( V_13 -> V_16 & V_17 ) )
V_1 &= V_2 ;
V_15 = F_6 ( V_8 , V_9 , V_10 , V_11 , V_1 ,
V_13 -> V_18 , V_13 -> V_19 ) ;
} else
V_15 =
F_7 ( V_8 , V_9 , V_10 , V_11 ,
V_20 & V_2 ) ;
if ( V_15 <= 0 )
return NULL ;
return * V_8 ;
}
static int F_8 ( const T_2 * const * V_21 ,
const T_2 * const * V_22 )
{
return ( * V_21 ) -> V_12 - ( * V_22 ) -> V_12 ;
}
static int F_9 ( const T_2 * V_21 , const T_2 * V_22 )
{
return V_21 -> V_12 - V_22 -> V_12 ;
}
T_2 * F_5 ( int V_12 )
{
int V_23 ;
T_2 V_24 ;
V_24 . V_12 = V_12 ;
if ( V_25 ) {
V_23 = F_10 ( V_25 , & V_24 ) ;
if ( V_23 >= 0 )
return F_11 ( V_25 , V_23 ) ;
}
return F_12 ( & V_24 , V_26 , F_13 ( V_26 ) ) ;
}
static T_2 * F_14 ( int V_12 )
{
T_2 * V_27 , * V_28 ;
if ( V_25 == NULL ) {
V_25 = F_15 ( F_8 ) ;
if ( V_25 == NULL )
return NULL ;
}
V_27 = F_5 ( V_12 ) ;
if ( V_27 && V_27 -> V_16 & V_29 )
return V_27 ;
V_28 = F_16 ( sizeof( * V_28 ) ) ;
if ( V_28 == NULL )
return NULL ;
if ( ! F_17 ( V_25 , V_28 ) ) {
F_18 ( V_28 ) ;
return NULL ;
}
if ( V_27 ) {
V_28 -> V_12 = V_27 -> V_12 ;
V_28 -> V_18 = V_27 -> V_18 ;
V_28 -> V_19 = V_27 -> V_19 ;
V_28 -> V_1 = V_27 -> V_1 ;
V_28 -> V_16 = V_27 -> V_16 | V_29 ;
} else {
V_28 -> V_18 = - 1 ;
V_28 -> V_19 = - 1 ;
V_28 -> V_16 = V_29 ;
}
return V_28 ;
}
int F_19 ( int V_12 ,
long V_18 , long V_19 , unsigned long V_1 ,
unsigned long V_16 )
{
T_2 * V_27 ;
V_27 = F_14 ( V_12 ) ;
if ( ! V_27 ) {
F_20 ( V_30 , V_31 ) ;
return 0 ;
}
if ( V_18 >= 0 )
V_27 -> V_18 = V_18 ;
if ( V_19 >= 0 )
V_27 -> V_19 = V_19 ;
if ( V_1 )
V_27 -> V_1 = V_1 ;
if ( V_16 )
V_27 -> V_16 = V_29 | V_16 ;
return 1 ;
}
void F_21 ( void )
{
F_22 ( T_2 ) * V_27 ;
V_27 = V_25 ;
if ( ! V_27 )
return;
V_25 = NULL ;
F_23 ( V_27 , V_32 ) ;
}
static void V_32 ( T_2 * V_13 )
{
if ( V_13 -> V_16 & V_29 )
F_18 ( V_13 ) ;
}
main ()
{
T_2 * V_27 ;
int V_33 , V_34 = - 1 ;
for ( V_27 = V_26 , V_33 = 0 ; V_33 < F_13 ( V_26 ) ; V_33 ++ , V_27 ++ ) {
if ( V_27 -> V_12 < V_34 ) {
V_34 = 0 ;
break;
}
V_34 = V_27 -> V_12 ;
}
if ( V_34 != 0 ) {
printf ( L_6 ) ;
exit ( 0 ) ;
}
for ( V_27 = V_26 , V_33 = 0 ; V_33 < F_13 ( V_26 ) ; V_33 ++ , V_27 ++ )
printf ( L_7 , V_33 , V_27 -> V_12 ,
F_24 ( V_27 -> V_12 ) ) ;
}
