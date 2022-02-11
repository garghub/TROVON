static inline struct V_1 * V_1 ( void )
{
if ( V_2 == ~ 0ul )
return F_1 ( V_3 -> V_4 . V_5 . V_6 ) ;
else
return F_2 ( V_2 << V_7 ) ;
}
static inline void F_3 ( void )
{
F_4 ( V_3 -> V_4 . V_5 . V_8 ) ;
}
static int F_5 ( const char * V_9 , int V_10 )
{
struct V_1 * V_11 = V_1 () ;
T_1 V_12 , V_13 ;
int V_14 = 0 ;
V_12 = V_11 -> V_15 ;
V_13 = V_11 -> V_16 ;
F_6 () ;
F_7 ( ( V_13 - V_12 ) > sizeof( V_11 -> V_17 ) ) ;
while ( ( V_14 < V_10 ) && ( ( V_13 - V_12 ) < sizeof( V_11 -> V_17 ) ) )
V_11 -> V_17 [ F_8 ( V_13 ++ , V_11 -> V_17 ) ] = V_9 [ V_14 ++ ] ;
F_9 () ;
V_11 -> V_16 = V_13 ;
if ( V_14 )
F_3 () ;
return V_14 ;
}
static int F_10 ( T_2 V_18 , const char * V_9 , int V_10 )
{
int V_19 = V_10 ;
while ( V_10 ) {
int V_14 = F_5 ( V_9 , V_10 ) ;
V_9 += V_14 ;
V_10 -= V_14 ;
if ( F_11 ( V_10 ) )
F_12 ( V_20 , NULL ) ;
}
return V_19 ;
}
static int F_13 ( T_2 V_18 , char * V_21 , int V_10 )
{
struct V_1 * V_11 = V_1 () ;
T_1 V_12 , V_13 ;
int V_22 = 0 ;
V_12 = V_11 -> V_23 ;
V_13 = V_11 -> V_24 ;
F_6 () ;
F_7 ( ( V_13 - V_12 ) > sizeof( V_11 -> V_25 ) ) ;
while ( V_12 != V_13 && V_22 < V_10 )
V_21 [ V_22 ++ ] = V_11 -> V_25 [ F_8 ( V_12 ++ , V_11 -> V_25 ) ] ;
F_6 () ;
V_11 -> V_23 = V_12 ;
F_3 () ;
return V_22 ;
}
static int F_14 ( T_2 V_18 , char * V_21 , int V_10 )
{
return F_15 ( V_26 , V_10 , V_21 ) ;
}
static int F_16 ( T_2 V_18 , const char * V_27 , int V_10 )
{
int V_28 = F_15 ( V_29 , V_10 , ( char * ) V_27 ) ;
if ( V_28 < 0 )
return 0 ;
return V_10 ;
}
static int T_3 F_17 ( void )
{
struct V_30 * V_31 ;
struct V_32 * V_33 ;
if ( ! F_18 () )
return - V_34 ;
if ( F_19 () ) {
V_33 = & V_35 ;
V_36 = F_20 ( V_37 , 0 ) ;
} else {
if ( ! V_3 -> V_4 . V_5 . V_8 )
return - V_34 ;
V_33 = & V_38 ;
V_36 = F_21 ( V_3 -> V_4 . V_5 . V_8 ) ;
}
if ( V_36 < 0 )
V_36 = 0 ;
else
F_22 ( V_36 ) ;
V_31 = F_23 ( V_39 , V_36 , V_33 , 256 ) ;
if ( F_24 ( V_31 ) )
return F_25 ( V_31 ) ;
V_40 = V_31 ;
V_2 = F_26 ( V_3 -> V_4 . V_5 . V_6 ) ;
return 0 ;
}
void F_27 ( void )
{
if ( V_36 )
F_28 ( V_3 -> V_4 . V_5 . V_8 , V_36 ) ;
}
static void T_4 F_29 ( void )
{
if ( V_40 )
F_30 ( V_40 ) ;
}
static int F_31 ( void )
{
struct V_32 * V_33 ;
if ( ! F_18 () )
return 0 ;
if ( F_19 () )
V_33 = & V_35 ;
else
V_33 = & V_38 ;
F_32 ( V_39 , 0 , V_33 ) ;
return 0 ;
}
static void F_33 ( struct V_4 * V_4 , const char * string ,
unsigned V_10 )
{
unsigned int V_41 , V_42 = 0 ;
const char * V_43 ;
F_16 ( 0 , string , V_10 ) ;
if ( F_19 () )
return;
F_10 ( 0 , L_1 , 8 ) ;
while ( V_42 < V_10 && NULL != ( V_43 = strchr ( string + V_42 , '\n' ) ) ) {
V_41 = V_43 - string + V_42 ;
if ( V_42 + V_41 > V_10 )
break;
F_10 ( 0 , string + V_42 , V_41 ) ;
F_10 ( 0 , L_2 , 2 ) ;
V_42 += V_41 + 1 ;
}
if ( V_42 < V_10 )
F_10 ( 0 , string + V_42 , V_10 - V_42 ) ;
}
void F_34 ( const char * V_27 )
{
F_16 ( 0 , V_27 , strlen ( V_27 ) ) ;
}
void F_35 ( const char * V_44 , ... )
{
static char V_21 [ 512 ] ;
T_5 V_45 ;
va_start ( V_45 , V_44 ) ;
vsnprintf ( V_21 , sizeof( V_21 ) , V_44 , V_45 ) ;
va_end ( V_45 ) ;
F_34 ( V_21 ) ;
}
