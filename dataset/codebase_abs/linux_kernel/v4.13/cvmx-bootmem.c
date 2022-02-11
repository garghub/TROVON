static void F_1 ( T_1 V_1 , T_1 V_2 )
{
F_2 ( ( V_1 + V_3 ) | ( 1ull << 63 ) , V_2 ) ;
}
static void F_3 ( T_1 V_1 , T_1 V_4 )
{
F_2 ( ( V_1 + V_5 ) | ( 1ull << 63 ) , V_4 ) ;
}
static T_1 F_4 ( T_1 V_1 )
{
return F_5 ( ( V_1 + V_3 ) | ( 1ull << 63 ) ) ;
}
static T_1 F_6 ( T_1 V_1 )
{
return F_5 ( ( V_1 + V_5 ) | ( 1ull << 63 ) ) ;
}
void * F_7 ( T_1 V_2 , T_1 V_6 ,
T_1 V_7 , T_1 V_8 )
{
T_2 V_9 ;
V_9 =
F_8 ( V_2 , V_7 , V_8 , V_6 , 0 ) ;
if ( V_9 > 0 )
return F_9 ( V_9 ) ;
else
return NULL ;
}
void * F_10 ( T_1 V_2 , T_1 V_9 ,
T_1 V_6 )
{
return F_7 ( V_2 , V_6 , V_9 ,
V_9 + V_2 ) ;
}
void * F_11 ( T_1 V_2 , T_1 V_6 )
{
return F_7 ( V_2 , V_6 , 0 , 0 ) ;
}
void * F_12 ( T_1 V_2 , T_1 V_7 ,
T_1 V_8 , T_1 V_10 ,
char * V_11 )
{
T_2 V_1 ;
V_1 = F_13 ( V_2 , V_7 , V_8 ,
V_10 , V_11 , 0 ) ;
if ( V_1 >= 0 )
return F_9 ( V_1 ) ;
else
return NULL ;
}
void * F_14 ( T_1 V_2 , T_1 V_9 ,
char * V_11 )
{
return F_12 ( V_2 , V_9 , V_9 + V_2 ,
0 , V_11 ) ;
}
void * F_15 ( T_1 V_2 , T_1 V_6 , char * V_11 )
{
return F_12 ( V_2 , 0 , 0 , V_6 , V_11 ) ;
}
int F_16 ( char * V_11 )
{
return F_17 ( V_11 , 0 ) ;
}
struct V_12 * F_18 ( char * V_11 )
{
return F_19 ( V_11 , 0 ) ;
}
void F_20 ( void )
{
F_21 ( ( V_13 * ) & ( V_14 -> V_15 ) ) ;
}
void F_22 ( void )
{
F_23 ( ( V_13 * ) & ( V_14 -> V_15 ) ) ;
}
int F_24 ( void * V_16 )
{
if ( ! V_14 ) {
#if F_25 ( V_17 )
V_14 = F_9 ( F_26 ( V_16 ) ) ;
#else
V_14 = (struct V_14 * ) V_16 ;
#endif
}
return 0 ;
}
T_2 F_8 ( T_1 V_18 , T_1 V_19 ,
T_1 V_20 , T_1 V_6 ,
T_3 V_21 )
{
T_1 V_22 ;
T_1 V_23 ;
T_1 V_24 = 0 ;
T_1 V_25 = 0 ;
T_1 V_26 ;
#ifdef F_27
F_28 ( L_1
L_2 ,
( unsigned long long ) V_18 ,
( unsigned long long ) V_19 ,
( unsigned long long ) V_20 ,
( unsigned long long ) V_6 ) ;
#endif
if ( V_14 -> V_27 > 3 ) {
F_28 ( L_3
L_4 ,
( int ) V_14 -> V_27 ,
( int ) V_14 -> V_28 ,
V_14 ) ;
goto V_29;
}
if ( ! V_18 )
goto V_29;
V_18 = ( V_18 + ( V_30 - 1 ) ) &
~ ( V_30 - 1 ) ;
if ( V_19 && ! V_20 )
V_20 = V_19 + V_18 ;
else if ( ! V_19 && ! V_20 )
V_20 = ~ 0ull ;
if ( V_6 < V_30 )
V_6 = V_30 ;
if ( V_6 )
V_19 = F_29 ( V_19 , V_6 ) ;
if ( V_18 > V_20 - V_19 )
goto V_29;
if ( ! ( V_21 & V_31 ) )
F_20 () ;
V_22 = V_14 -> V_22 ;
V_23 = V_22 ;
for (; V_23 ;
V_24 = V_23 ,
V_23 = F_6 ( V_23 ) ) {
T_1 V_32 , V_33 ;
T_1 V_34 = F_4 ( V_23 ) ;
if ( F_6 ( V_23 )
&& V_23 > F_6 ( V_23 ) ) {
F_28 ( L_5
L_6 ,
( unsigned long long ) V_23 ,
( unsigned long long )
F_6 ( V_23 ) ) ;
goto V_29;
}
V_32 =
F_29 ( F_30 ( V_19 , V_23 ) , V_6 ) ;
V_33 = F_31 ( V_20 , V_23 + V_34 ) ;
V_26 = V_32 ;
if ( ! ( ( V_23 + V_34 ) > V_32
&& V_23 < V_20
&& V_18 <= V_33 - V_32 ) )
continue;
if ( V_21 & V_35 ) {
V_26 = V_33 - V_18 ;
V_26 &= ~ ( V_6 - 1 ) ;
}
if ( V_26 == V_23 ) {
if ( V_18 < V_34 ) {
V_25 = V_23 + V_18 ;
F_3 ( V_25 ,
F_6 ( V_23 ) ) ;
F_1 ( V_25 ,
V_34 -
V_18 ) ;
F_3 ( V_23 ,
V_25 ) ;
}
if ( V_24 )
F_3 ( V_24 ,
F_6 ( V_23 ) ) ;
else
V_14 -> V_22 =
F_6 ( V_23 ) ;
if ( ! ( V_21 & V_31 ) )
F_22 () ;
return V_26 ;
}
V_25 = V_26 ;
F_3 ( V_25 ,
F_6
( V_23 ) ) ;
F_1 ( V_25 ,
F_4
( V_23 ) -
( V_26 -
V_23 ) ) ;
F_1 ( V_23 ,
V_26 - V_23 ) ;
F_3 ( V_23 , V_25 ) ;
}
V_29:
if ( ! ( V_21 & V_31 ) )
F_22 () ;
return - 1 ;
}
int F_32 ( T_1 V_36 , T_1 V_2 , T_3 V_21 )
{
T_1 V_37 ;
T_1 V_24 = 0 ;
int V_38 = 0 ;
#ifdef F_27
F_28 ( L_7 ,
( unsigned long long ) V_36 , ( unsigned long long ) V_2 ) ;
#endif
if ( V_14 -> V_27 > 3 ) {
F_28 ( L_3
L_4 ,
( int ) V_14 -> V_27 ,
( int ) V_14 -> V_28 ,
V_14 ) ;
return 0 ;
}
if ( ! V_2 )
return 0 ;
if ( ! ( V_21 & V_31 ) )
F_20 () ;
V_37 = V_14 -> V_22 ;
if ( V_37 == 0 || V_36 < V_37 ) {
if ( V_37 && V_36 + V_2 > V_37 )
goto V_39;
else if ( V_36 + V_2 == V_37 ) {
F_3 ( V_36 ,
F_6
( V_37 ) ) ;
F_1 ( V_36 ,
F_4
( V_37 ) + V_2 ) ;
V_14 -> V_22 = V_36 ;
} else {
F_3 ( V_36 , V_37 ) ;
F_1 ( V_36 , V_2 ) ;
V_14 -> V_22 = V_36 ;
}
V_38 = 1 ;
goto V_39;
}
while ( V_37 && V_36 > V_37 ) {
V_24 = V_37 ;
V_37 = F_6 ( V_37 ) ;
}
if ( ! V_37 ) {
if ( V_24 + F_4 ( V_24 ) ==
V_36 ) {
F_1 ( V_24 ,
F_4
( V_24 ) + V_2 ) ;
} else {
F_3 ( V_24 , V_36 ) ;
F_1 ( V_36 , V_2 ) ;
F_3 ( V_36 , 0 ) ;
}
V_38 = 1 ;
goto V_39;
} else {
if ( V_24 + F_4 ( V_24 ) ==
V_36 ) {
F_1 ( V_24 ,
F_4
( V_24 ) + V_2 ) ;
if ( V_36 + V_2 == V_37 ) {
F_1 ( V_24 ,
F_4 ( V_37 ) +
F_4 ( V_24 ) ) ;
F_3 ( V_24 ,
F_6 ( V_37 ) ) ;
}
V_38 = 1 ;
goto V_39;
} else if ( V_36 + V_2 == V_37 ) {
F_1 ( V_36 ,
F_4
( V_37 ) + V_2 ) ;
F_3 ( V_36 ,
F_6
( V_37 ) ) ;
F_3 ( V_24 , V_36 ) ;
V_38 = 1 ;
goto V_39;
}
F_1 ( V_36 , V_2 ) ;
F_3 ( V_36 , V_37 ) ;
F_3 ( V_24 , V_36 ) ;
}
V_38 = 1 ;
V_39:
if ( ! ( V_21 & V_31 ) )
F_22 () ;
return V_38 ;
}
struct V_12 *
F_19 ( char * V_11 , T_3 V_21 )
{
unsigned int V_40 ;
struct V_12 * V_41 ;
#ifdef F_27
F_28 ( L_8 , V_11 ) ;
#endif
if ( ! ( V_21 & V_31 ) )
F_20 () ;
V_41 = (struct V_12 * )
F_9 ( V_14 -> V_42 ) ;
#ifdef F_27
F_28
( L_9 ,
V_41 ) ;
#endif
if ( V_14 -> V_27 == 3 ) {
for ( V_40 = 0 ;
V_40 < V_14 -> V_43 ; V_40 ++ ) {
if ( ( V_11 && V_41 [ V_40 ] . V_2
&& ! strncmp ( V_11 , V_41 [ V_40 ] . V_11 ,
V_14 -> V_44
- 1 ) )
|| ( ! V_11 && ! V_41 [ V_40 ] . V_2 ) ) {
if ( ! ( V_21 & V_31 ) )
F_22 () ;
return & ( V_41 [ V_40 ] ) ;
}
}
} else {
F_28 ( L_3
L_4 ,
( int ) V_14 -> V_27 ,
( int ) V_14 -> V_28 ,
V_14 ) ;
}
if ( ! ( V_21 & V_31 ) )
F_22 () ;
return NULL ;
}
int F_17 ( char * V_11 , T_3 V_21 )
{
struct V_12 * V_45 ;
if ( V_14 -> V_27 != 3 ) {
F_28 ( L_10
L_11 ,
( int ) V_14 -> V_27 ,
( int ) V_14 -> V_28 ,
V_14 ) ;
return 0 ;
}
#ifdef F_27
F_28 ( L_12 , V_11 ) ;
#endif
F_20 () ;
V_45 =
F_19 ( V_11 ,
V_31 ) ;
if ( V_45 ) {
#ifdef F_27
F_28 ( L_13
L_14 ,
V_11 ,
( unsigned long long ) V_45 -> V_46 ,
( unsigned long long ) V_45 -> V_2 ) ;
#endif
F_32 ( V_45 -> V_46 ,
V_45 -> V_2 ,
V_31 ) ;
V_45 -> V_2 = 0 ;
}
F_22 () ;
return V_45 != NULL ;
}
T_2 F_13 ( T_1 V_2 , T_1 V_7 ,
T_1 V_8 ,
T_1 V_6 ,
char * V_11 ,
T_3 V_21 )
{
T_2 V_47 ;
struct V_12 * V_48 ;
#ifdef F_27
F_28 ( L_15
L_16 ,
( unsigned long long ) V_2 ,
( unsigned long long ) V_7 ,
( unsigned long long ) V_8 ,
( unsigned long long ) V_6 ,
V_11 ) ;
#endif
if ( V_14 -> V_27 != 3 ) {
F_28 ( L_10
L_11 ,
( int ) V_14 -> V_27 ,
( int ) V_14 -> V_28 ,
V_14 ) ;
return - 1 ;
}
if ( ! ( V_21 & V_31 ) )
F_21 ( ( V_13 * ) & ( V_14 -> V_15 ) ) ;
V_48 =
F_19 ( NULL ,
V_21 | V_31 ) ;
if ( F_19 ( V_11 ,
V_21 | V_31 ) || ! V_48 ) {
if ( ! ( V_21 & V_31 ) )
F_23 ( ( V_13 * ) & ( V_14 -> V_15 ) ) ;
return - 1 ;
}
V_2 = F_29 ( V_2 , V_30 ) ;
V_47 = F_8 ( V_2 , V_7 , V_8 ,
V_6 ,
V_21 | V_31 ) ;
if ( V_47 >= 0 ) {
V_48 -> V_46 = V_47 ;
V_48 -> V_2 = V_2 ;
strncpy ( V_48 -> V_11 , V_11 ,
V_14 -> V_44 ) ;
V_48 -> V_11 [ V_14 -> V_44 - 1 ] = 0 ;
}
if ( ! ( V_21 & V_31 ) )
F_23 ( ( V_13 * ) & ( V_14 -> V_15 ) ) ;
return V_47 ;
}
struct V_14 * F_33 ( void )
{
return V_14 ;
}
