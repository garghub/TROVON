static void * F_1 ( T_1 V_1 , int V_2 )
{
int V_3 = 0 ;
int V_4 = ( 1 << V_5 ) ;
int V_6 ;
void * V_7 ;
T_2 V_8 = V_1 -> V_8 ;
if ( V_2 > V_9 )
return NULL ;
while ( V_2 > V_4 ) {
V_4 <<= 1 ;
++ V_3 ;
}
V_6 = V_3 ;
while ( ! V_8 [ V_6 ] . V_10 ) {
if ( V_4 == V_9 ) {
V_8 [ V_6 ] . V_10 = ( T_2 ) F_2 () ;
if ( V_8 [ V_6 ] . V_10 )
V_8 [ V_6 ] . V_10 -> V_10 = NULL ;
break;
}
++ V_6 ;
V_4 <<= 1 ;
}
V_7 = V_8 [ V_6 ] . V_10 ;
if ( V_7 ) {
V_8 [ V_6 ] . V_10 = V_8 [ V_6 ] . V_10 -> V_10 ;
while ( V_6 > V_3 ) {
V_6 -= 1 ;
V_4 >>= 1 ;
V_8 [ V_6 ] . V_10 = ( T_2 ) ( V_7 + V_4 ) ;
V_8 [ V_6 ] . V_10 -> V_10 = NULL ;
}
}
#ifdef F_3
printf ( L_1 , V_2 , ( void * ) V_7 ) ;
#endif
return V_7 ;
}
static void F_4 ( T_1 V_1 , void * V_11 , int V_2 )
{
int V_3 = 0 ;
int V_4 = ( 1 << V_5 ) ;
T_2 V_12 ;
unsigned long V_7 , V_13 ;
T_2 V_8 = V_1 -> V_8 ;
#ifdef F_3
printf ( L_2 , V_11 , V_2 ) ;
#endif
if ( V_2 > V_9 )
return;
while ( V_2 > V_4 ) {
V_4 <<= 1 ;
++ V_3 ;
}
V_7 = ( unsigned long ) V_11 ;
while ( 1 ) {
if ( V_4 == V_9 ) {
#ifdef F_5
F_6 ( ( void * ) V_7 ) ;
#else
( ( T_2 ) V_7 ) -> V_10 = V_8 [ V_3 ] . V_10 ;
V_8 [ V_3 ] . V_10 = ( T_2 ) V_7 ;
#endif
break;
}
V_13 = V_7 ^ V_4 ;
V_12 = & V_8 [ V_3 ] ;
while ( V_12 -> V_10 && V_12 -> V_10 != ( T_2 ) V_13 ) {
V_12 = V_12 -> V_10 ;
}
if ( ! V_12 -> V_10 ) {
( ( T_2 ) V_7 ) -> V_10 = V_8 [ V_3 ] . V_10 ;
V_8 [ V_3 ] . V_10 = ( T_2 ) V_7 ;
break;
}
V_12 -> V_10 = V_12 -> V_10 -> V_10 ;
V_7 = V_7 & V_13 ;
V_4 <<= 1 ;
++ V_3 ;
}
}
static void * F_7 ( T_1 V_1 , int V_2 , char * V_14 , int V_15 )
{
void * V_16 ;
V_16 = F_1 ( V_1 , V_2 ) ;
if ( V_17 & V_18 ) {
printf ( L_3 , V_14 , V_2 , V_16 ) ;
}
if ( V_16 )
memset ( V_16 , 0 , V_2 ) ;
else if ( V_15 & V_19 )
printf ( L_4 , V_14 , V_2 ) ;
return V_16 ;
}
static void F_8 ( T_1 V_1 , void * V_11 , int V_2 , char * V_14 )
{
if ( V_17 & V_18 )
printf ( L_5 , V_14 , V_2 , V_11 ) ;
F_4 ( V_1 , V_11 , V_2 ) ;
}
static void * F_9 ( T_1 V_1 )
{
void * V_20 = F_10 () ;
if ( V_20 )
++ V_1 -> V_21 ;
return V_20 ;
}
static void F_11 ( T_1 V_1 , void * V_20 )
{
F_12 ( V_20 ) ;
-- V_1 -> V_21 ;
}
static void * F_13 ( T_1 V_1 )
{
T_3 V_22 ;
void * V_23 ;
V_22 = F_14 ( & V_24 , sizeof( * V_22 ) , L_6 ) ;
if ( ! V_22 )
goto V_25;
V_23 = F_15 ( V_1 , V_22 ) ;
if ( V_23 ) {
int V_26 = F_16 ( V_23 ) ;
V_22 -> V_10 = V_1 -> V_27 [ V_26 ] ;
V_1 -> V_27 [ V_26 ] = V_22 ;
++ V_1 -> V_21 ;
}
return V_23 ;
V_25:
return NULL ;
}
static void F_17 ( T_1 V_1 , void * V_20 )
{
T_3 * V_28 , V_22 ;
int V_26 = F_16 ( V_20 ) ;
V_28 = & V_1 -> V_27 [ V_26 ] ;
while ( * V_28 && ( * V_28 ) -> V_23 != V_20 )
V_28 = & ( * V_28 ) -> V_10 ;
if ( * V_28 ) {
V_22 = * V_28 ;
* V_28 = ( * V_28 ) -> V_10 ;
F_18 ( V_1 , V_22 ) ;
F_8 ( & V_24 , V_22 , sizeof( * V_22 ) , L_6 ) ;
-- V_1 -> V_21 ;
}
}
static inline T_1 F_19 ( T_4 V_29 )
{
T_1 V_1 ;
for ( V_1 = V_24 . V_10 ;
V_1 && ! F_20 ( V_1 -> V_29 , V_29 ) ;
V_1 = V_1 -> V_10 ) ;
return V_1 ;
}
static T_1 F_21 ( T_4 V_29 )
{
T_1 V_1 = F_14 ( & V_24 , sizeof( * V_1 ) , L_7 ) ;
if ( V_1 ) {
V_1 -> V_29 = V_29 ;
V_1 -> V_30 = F_13 ;
#ifdef F_5
V_1 -> V_31 = F_17 ;
#endif
V_1 -> V_10 = V_24 . V_10 ;
V_24 . V_10 = V_1 ;
return V_1 ;
}
return NULL ;
}
static void F_22 ( T_1 V_16 )
{
T_1 * V_32 = & V_24 . V_10 ;
while ( * V_32 && * V_32 != V_16 )
V_32 = & ( * V_32 ) -> V_10 ;
if ( * V_32 ) {
* V_32 = ( * V_32 ) -> V_10 ;
F_8 ( & V_24 , V_16 , sizeof( * V_16 ) , L_7 ) ;
}
}
void * F_23 ( T_4 V_29 , int V_2 , char * V_14 )
{
unsigned long V_33 ;
T_1 V_1 ;
void * V_20 = NULL ;
F_24 ( & V_34 , V_33 ) ;
V_1 = F_19 ( V_29 ) ;
if ( ! V_1 )
V_1 = F_21 ( V_29 ) ;
if ( ! V_1 )
goto V_35;
V_20 = F_14 ( V_1 , V_2 , V_14 ) ;
#ifdef F_5
if ( ! V_1 -> V_21 )
F_22 ( V_1 ) ;
#endif
V_35:
F_25 ( & V_34 , V_33 ) ;
return V_20 ;
}
void F_26 ( T_4 V_29 , void * V_20 , int V_2 , char * V_14 )
{
unsigned long V_33 ;
T_1 V_1 ;
F_24 ( & V_34 , V_33 ) ;
V_1 = F_19 ( V_29 ) ;
if ( ! V_1 )
goto V_35;
F_8 ( V_1 , V_20 , V_2 , V_14 ) ;
#ifdef F_5
if ( ! V_1 -> V_21 )
F_22 ( V_1 ) ;
#endif
V_35:
F_25 ( & V_34 , V_33 ) ;
}
T_5 F_27 ( T_4 V_29 , void * V_20 )
{
unsigned long V_33 ;
T_1 V_1 ;
int V_26 = F_16 ( V_20 ) ;
T_3 V_36 = NULL ;
void * V_7 = ( void * ) ( ( unsigned long ) V_20 & ~ V_37 ) ;
T_5 V_13 ;
F_24 ( & V_34 , V_33 ) ;
V_1 = F_19 ( V_29 ) ;
if ( V_1 ) {
V_36 = V_1 -> V_27 [ V_26 ] ;
while ( V_36 && V_36 -> V_23 != V_7 )
V_36 = V_36 -> V_10 ;
}
if ( ! V_36 )
F_28 ( L_8 ) ;
V_13 = V_36 -> V_38 + ( V_20 - V_7 ) ;
F_25 ( & V_34 , V_33 ) ;
return V_13 ;
}
