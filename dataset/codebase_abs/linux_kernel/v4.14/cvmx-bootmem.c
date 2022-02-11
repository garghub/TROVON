static inline T_1 F_1 ( T_1 V_1 , int V_2 ,
int V_3 )
{
V_1 = ( 1ull << 63 ) | ( V_1 + V_2 ) ;
switch ( V_3 ) {
case 4 :
return F_2 ( V_1 ) ;
case 8 :
return F_3 ( V_1 ) ;
default:
return 0 ;
}
}
static void F_4 ( T_1 V_4 , T_1 V_3 )
{
F_5 ( ( V_4 + V_5 ) | ( 1ull << 63 ) , V_3 ) ;
}
static void F_6 ( T_1 V_4 , T_1 V_6 )
{
F_5 ( ( V_4 + V_7 ) | ( 1ull << 63 ) , V_6 ) ;
}
static T_1 F_7 ( T_1 V_4 )
{
return F_3 ( ( V_4 + V_5 ) | ( 1ull << 63 ) ) ;
}
static T_1 F_8 ( T_1 V_4 )
{
return F_3 ( ( V_4 + V_7 ) | ( 1ull << 63 ) ) ;
}
void * F_9 ( T_1 V_3 , T_1 V_8 ,
T_1 V_9 , T_1 V_10 )
{
T_2 V_11 ;
V_11 =
F_10 ( V_3 , V_9 , V_10 , V_8 , 0 ) ;
if ( V_11 > 0 )
return F_11 ( V_11 ) ;
else
return NULL ;
}
void * F_12 ( T_1 V_3 , T_1 V_11 ,
T_1 V_8 )
{
return F_9 ( V_3 , V_8 , V_11 ,
V_11 + V_3 ) ;
}
void * F_13 ( T_1 V_3 , T_1 V_8 )
{
return F_9 ( V_3 , V_8 , 0 , 0 ) ;
}
void * F_14 ( T_1 V_3 , T_1 V_9 ,
T_1 V_10 , T_1 V_12 ,
char * V_13 ,
void (* F_15) ( void * ) )
{
T_2 V_4 ;
void * V_14 ;
T_1 V_15 ;
V_15 = ( T_1 )
F_16 ( V_13 ,
( V_16 ) V_17 ) ;
if ( V_15 ) {
V_4 = F_17 ( V_15 ,
V_18 ) ;
return F_11 ( V_4 ) ;
}
V_4 = F_18 ( V_3 , V_9 , V_10 ,
V_12 , V_13 ,
( V_16 ) V_17 ) ;
if ( V_4 < 0 )
return NULL ;
V_14 = F_11 ( V_4 ) ;
if ( F_15 )
F_15 ( V_14 ) ;
else
memset ( V_14 , 0 , V_3 ) ;
return V_14 ;
}
void * F_19 ( T_1 V_3 , T_1 V_9 ,
T_1 V_10 , T_1 V_12 ,
char * V_13 )
{
T_2 V_4 ;
V_4 = F_18 ( V_3 , V_9 , V_10 ,
V_12 , V_13 , 0 ) ;
if ( V_4 >= 0 )
return F_11 ( V_4 ) ;
else
return NULL ;
}
void * F_20 ( T_1 V_3 , T_1 V_11 ,
char * V_13 )
{
return F_19 ( V_3 , V_11 , V_11 + V_3 ,
0 , V_13 ) ;
}
void * F_21 ( T_1 V_3 , T_1 V_8 , char * V_13 )
{
return F_19 ( V_3 , 0 , 0 , V_8 , V_13 ) ;
}
int F_22 ( char * V_13 )
{
return F_23 ( V_13 , 0 ) ;
}
struct V_19 * F_24 ( char * V_13 )
{
return F_16 ( V_13 , 0 ) ;
}
void F_25 ( void )
{
F_26 ( ( V_20 * ) & ( V_21 -> V_22 ) ) ;
}
void F_27 ( void )
{
F_28 ( ( V_20 * ) & ( V_21 -> V_22 ) ) ;
}
int F_29 ( void * V_23 )
{
if ( ! V_21 ) {
#if F_30 ( V_24 )
V_21 = F_11 ( F_31 ( V_23 ) ) ;
#else
V_21 = (struct V_21 * ) V_23 ;
#endif
}
return 0 ;
}
T_2 F_10 ( T_1 V_25 , T_1 V_26 ,
T_1 V_27 , T_1 V_8 ,
V_16 V_28 )
{
T_1 V_29 ;
T_1 V_30 ;
T_1 V_31 = 0 ;
T_1 V_32 = 0 ;
T_1 V_33 ;
#ifdef F_32
F_33 ( L_1
L_2 ,
( unsigned long long ) V_25 ,
( unsigned long long ) V_26 ,
( unsigned long long ) V_27 ,
( unsigned long long ) V_8 ) ;
#endif
if ( V_21 -> V_34 > 3 ) {
F_33 ( L_3
L_4 ,
( int ) V_21 -> V_34 ,
( int ) V_21 -> V_35 ,
V_21 ) ;
goto V_36;
}
if ( ! V_25 )
goto V_36;
V_25 = ( V_25 + ( V_37 - 1 ) ) &
~ ( V_37 - 1 ) ;
if ( V_26 && ! V_27 )
V_27 = V_26 + V_25 ;
else if ( ! V_26 && ! V_27 )
V_27 = ~ 0ull ;
if ( V_8 < V_37 )
V_8 = V_37 ;
if ( V_8 )
V_26 = F_34 ( V_26 , V_8 ) ;
if ( V_25 > V_27 - V_26 )
goto V_36;
if ( ! ( V_28 & V_17 ) )
F_25 () ;
V_29 = V_21 -> V_29 ;
V_30 = V_29 ;
for (; V_30 ;
V_31 = V_30 ,
V_30 = F_8 ( V_30 ) ) {
T_1 V_38 , V_39 ;
T_1 V_40 = F_7 ( V_30 ) ;
if ( F_8 ( V_30 )
&& V_30 > F_8 ( V_30 ) ) {
F_33 ( L_5
L_6 ,
( unsigned long long ) V_30 ,
( unsigned long long )
F_8 ( V_30 ) ) ;
goto V_36;
}
V_38 =
F_34 ( F_35 ( V_26 , V_30 ) , V_8 ) ;
V_39 = F_36 ( V_27 , V_30 + V_40 ) ;
V_33 = V_38 ;
if ( ! ( ( V_30 + V_40 ) > V_38
&& V_30 < V_27
&& V_25 <= V_39 - V_38 ) )
continue;
if ( V_28 & V_41 ) {
V_33 = V_39 - V_25 ;
V_33 &= ~ ( V_8 - 1 ) ;
}
if ( V_33 == V_30 ) {
if ( V_25 < V_40 ) {
V_32 = V_30 + V_25 ;
F_6 ( V_32 ,
F_8 ( V_30 ) ) ;
F_4 ( V_32 ,
V_40 -
V_25 ) ;
F_6 ( V_30 ,
V_32 ) ;
}
if ( V_31 )
F_6 ( V_31 ,
F_8 ( V_30 ) ) ;
else
V_21 -> V_29 =
F_8 ( V_30 ) ;
if ( ! ( V_28 & V_17 ) )
F_27 () ;
return V_33 ;
}
V_32 = V_33 ;
F_6 ( V_32 ,
F_8
( V_30 ) ) ;
F_4 ( V_32 ,
F_7
( V_30 ) -
( V_33 -
V_30 ) ) ;
F_4 ( V_30 ,
V_33 - V_30 ) ;
F_6 ( V_30 , V_32 ) ;
}
V_36:
if ( ! ( V_28 & V_17 ) )
F_27 () ;
return - 1 ;
}
int F_37 ( T_1 V_42 , T_1 V_3 , V_16 V_28 )
{
T_1 V_43 ;
T_1 V_31 = 0 ;
int V_44 = 0 ;
#ifdef F_32
F_33 ( L_7 ,
( unsigned long long ) V_42 , ( unsigned long long ) V_3 ) ;
#endif
if ( V_21 -> V_34 > 3 ) {
F_33 ( L_3
L_4 ,
( int ) V_21 -> V_34 ,
( int ) V_21 -> V_35 ,
V_21 ) ;
return 0 ;
}
if ( ! V_3 )
return 0 ;
if ( ! ( V_28 & V_17 ) )
F_25 () ;
V_43 = V_21 -> V_29 ;
if ( V_43 == 0 || V_42 < V_43 ) {
if ( V_43 && V_42 + V_3 > V_43 )
goto V_45;
else if ( V_42 + V_3 == V_43 ) {
F_6 ( V_42 ,
F_8
( V_43 ) ) ;
F_4 ( V_42 ,
F_7
( V_43 ) + V_3 ) ;
V_21 -> V_29 = V_42 ;
} else {
F_6 ( V_42 , V_43 ) ;
F_4 ( V_42 , V_3 ) ;
V_21 -> V_29 = V_42 ;
}
V_44 = 1 ;
goto V_45;
}
while ( V_43 && V_42 > V_43 ) {
V_31 = V_43 ;
V_43 = F_8 ( V_43 ) ;
}
if ( ! V_43 ) {
if ( V_31 + F_7 ( V_31 ) ==
V_42 ) {
F_4 ( V_31 ,
F_7
( V_31 ) + V_3 ) ;
} else {
F_6 ( V_31 , V_42 ) ;
F_4 ( V_42 , V_3 ) ;
F_6 ( V_42 , 0 ) ;
}
V_44 = 1 ;
goto V_45;
} else {
if ( V_31 + F_7 ( V_31 ) ==
V_42 ) {
F_4 ( V_31 ,
F_7
( V_31 ) + V_3 ) ;
if ( V_42 + V_3 == V_43 ) {
F_4 ( V_31 ,
F_7 ( V_43 ) +
F_7 ( V_31 ) ) ;
F_6 ( V_31 ,
F_8 ( V_43 ) ) ;
}
V_44 = 1 ;
goto V_45;
} else if ( V_42 + V_3 == V_43 ) {
F_4 ( V_42 ,
F_7
( V_43 ) + V_3 ) ;
F_6 ( V_42 ,
F_8
( V_43 ) ) ;
F_6 ( V_31 , V_42 ) ;
V_44 = 1 ;
goto V_45;
}
F_4 ( V_42 , V_3 ) ;
F_6 ( V_42 , V_43 ) ;
F_6 ( V_31 , V_42 ) ;
}
V_44 = 1 ;
V_45:
if ( ! ( V_28 & V_17 ) )
F_27 () ;
return V_44 ;
}
struct V_19 *
F_16 ( char * V_13 , V_16 V_28 )
{
unsigned int V_46 ;
struct V_19 * V_47 ;
#ifdef F_32
F_33 ( L_8 , V_13 ) ;
#endif
if ( ! ( V_28 & V_17 ) )
F_25 () ;
V_47 = (struct V_19 * )
F_11 ( V_21 -> V_48 ) ;
#ifdef F_32
F_33
( L_9 ,
V_47 ) ;
#endif
if ( V_21 -> V_34 == 3 ) {
for ( V_46 = 0 ;
V_46 < V_21 -> V_49 ; V_46 ++ ) {
if ( ( V_13 && V_47 [ V_46 ] . V_3
&& ! strncmp ( V_13 , V_47 [ V_46 ] . V_13 ,
V_21 -> V_50
- 1 ) )
|| ( ! V_13 && ! V_47 [ V_46 ] . V_3 ) ) {
if ( ! ( V_28 & V_17 ) )
F_27 () ;
return & ( V_47 [ V_46 ] ) ;
}
}
} else {
F_33 ( L_3
L_4 ,
( int ) V_21 -> V_34 ,
( int ) V_21 -> V_35 ,
V_21 ) ;
}
if ( ! ( V_28 & V_17 ) )
F_27 () ;
return NULL ;
}
int F_23 ( char * V_13 , V_16 V_28 )
{
struct V_19 * V_51 ;
if ( V_21 -> V_34 != 3 ) {
F_33 ( L_10
L_11 ,
( int ) V_21 -> V_34 ,
( int ) V_21 -> V_35 ,
V_21 ) ;
return 0 ;
}
#ifdef F_32
F_33 ( L_12 , V_13 ) ;
#endif
F_25 () ;
V_51 =
F_16 ( V_13 ,
V_17 ) ;
if ( V_51 ) {
#ifdef F_32
F_33 ( L_13
L_14 ,
V_13 ,
( unsigned long long ) V_51 -> V_18 ,
( unsigned long long ) V_51 -> V_3 ) ;
#endif
F_37 ( V_51 -> V_18 ,
V_51 -> V_3 ,
V_17 ) ;
V_51 -> V_3 = 0 ;
}
F_27 () ;
return V_51 != NULL ;
}
T_2 F_18 ( T_1 V_3 , T_1 V_9 ,
T_1 V_10 ,
T_1 V_8 ,
char * V_13 ,
V_16 V_28 )
{
T_2 V_52 ;
struct V_19 * V_53 ;
#ifdef F_32
F_33 ( L_15
L_16 ,
( unsigned long long ) V_3 ,
( unsigned long long ) V_9 ,
( unsigned long long ) V_10 ,
( unsigned long long ) V_8 ,
V_13 ) ;
#endif
if ( V_21 -> V_34 != 3 ) {
F_33 ( L_10
L_11 ,
( int ) V_21 -> V_34 ,
( int ) V_21 -> V_35 ,
V_21 ) ;
return - 1 ;
}
if ( ! ( V_28 & V_17 ) )
F_26 ( ( V_20 * ) & ( V_21 -> V_22 ) ) ;
V_53 =
F_16 ( NULL ,
V_28 | V_17 ) ;
if ( F_16 ( V_13 ,
V_28 | V_17 ) || ! V_53 ) {
if ( ! ( V_28 & V_17 ) )
F_28 ( ( V_20 * ) & ( V_21 -> V_22 ) ) ;
return - 1 ;
}
V_3 = F_34 ( V_3 , V_37 ) ;
V_52 = F_10 ( V_3 , V_9 , V_10 ,
V_8 ,
V_28 | V_17 ) ;
if ( V_52 >= 0 ) {
V_53 -> V_18 = V_52 ;
V_53 -> V_3 = V_3 ;
strncpy ( V_53 -> V_13 , V_13 ,
V_21 -> V_50 ) ;
V_53 -> V_13 [ V_21 -> V_50 - 1 ] = 0 ;
}
if ( ! ( V_28 & V_17 ) )
F_28 ( ( V_20 * ) & ( V_21 -> V_22 ) ) ;
return V_52 ;
}
struct V_21 * F_38 ( void )
{
return V_21 ;
}
