static T_1 F_1 ( int V_1 , void * V_2 )
{
if ( F_2 ( V_3 == 0 ) ) {
V_3 = 1 ;
F_3 ( & V_4 ) ;
}
F_4 ( & V_5 ) ;
return V_6 ;
}
static int F_5 ( T_2 V_7 , T_2 V_8 )
{
return ( ( V_8 - V_7 ) <= V_9 ) ;
}
static void * F_6 ( T_2 V_7 ,
T_2 V_8 ,
char * V_10 , T_3 * V_11 )
{
* V_11 = V_9 - F_7 ( V_8 ) ;
if ( ( V_9 - ( V_8 - V_7 ) ) < * V_11 )
* V_11 = V_9 - ( V_8 - V_7 ) ;
return V_10 + F_7 ( V_8 ) ;
}
static const void * F_8 ( T_2 V_7 ,
T_2 V_8 ,
const char * V_10 , T_3 * V_11 )
{
* V_11 = V_9 - F_7 ( V_7 ) ;
if ( ( V_8 - V_7 ) < * V_11 )
* V_11 = V_8 - V_7 ;
return V_10 + F_7 ( V_7 ) ;
}
int F_9 ( const void * V_12 , unsigned V_11 )
{
struct V_13 * V_14 = V_15 ;
T_2 V_7 , V_8 ;
int V_16 ;
while ( V_11 != 0 ) {
void * V_17 ;
unsigned int V_18 ;
V_16 = F_10 (
V_5 ,
( V_14 -> V_19 - V_14 -> V_20 ) !=
V_9 ) ;
if ( V_16 < 0 )
return V_16 ;
V_7 = V_14 -> V_20 ;
V_8 = V_14 -> V_19 ;
if ( ! F_5 ( V_7 , V_8 ) ) {
V_14 -> V_20 = V_14 -> V_19 = 0 ;
return - V_21 ;
}
V_17 = F_6 ( V_7 , V_8 , V_14 -> V_22 , & V_18 ) ;
if ( V_18 == 0 )
continue;
if ( V_18 > V_11 )
V_18 = V_11 ;
F_11 () ;
memcpy ( V_17 , V_12 , V_18 ) ;
V_12 += V_18 ;
V_11 -= V_18 ;
F_12 () ;
V_14 -> V_19 += V_18 ;
F_13 ( V_23 ) ;
}
return 0 ;
}
int F_14 ( void )
{
struct V_13 * V_14 = V_15 ;
return ( V_14 -> V_24 != V_14 -> V_25 ) ;
}
int F_15 ( void )
{
return F_10 ( V_5 , F_14 () ) ;
}
int F_16 ( void * V_12 , unsigned V_11 )
{
struct V_13 * V_14 = V_15 ;
T_2 V_7 , V_8 ;
int V_16 ;
while ( V_11 != 0 ) {
unsigned int V_18 ;
const char * V_26 ;
V_16 = F_15 () ;
if ( V_16 < 0 )
return V_16 ;
V_7 = V_14 -> V_24 ;
V_8 = V_14 -> V_25 ;
if ( ! F_5 ( V_7 , V_8 ) ) {
V_14 -> V_24 = V_14 -> V_25 = 0 ;
return - V_21 ;
}
V_26 = F_8 ( V_7 , V_8 , V_14 -> V_27 , & V_18 ) ;
if ( V_18 == 0 )
continue;
if ( V_18 > V_11 )
V_18 = V_11 ;
F_17 () ;
memcpy ( V_12 , V_26 , V_18 ) ;
V_12 += V_18 ;
V_11 -= V_18 ;
F_11 () ;
V_14 -> V_24 += V_18 ;
F_18 ( L_1 , V_18 , V_11 ) ;
F_13 ( V_23 ) ;
}
return 0 ;
}
int F_19 ( void )
{
struct V_13 * V_14 = V_15 ;
if ( V_14 -> V_19 != V_14 -> V_20 )
F_20 ( V_28 L_2
L_3 , V_14 -> V_20 , V_14 -> V_19 ) ;
if ( V_14 -> V_25 != V_14 -> V_24 ) {
F_20 ( V_29 L_4
L_5 ,
V_14 -> V_24 , V_14 -> V_25 ) ;
if ( ! V_30 )
V_14 -> V_24 = V_14 -> V_25 ;
}
if ( V_31 ) {
F_21 ( V_23 , V_31 ) ;
} else {
int V_32 ;
V_32 = F_22 ( V_23 , F_1 ,
0 , L_6 , & V_5 ) ;
if ( V_32 <= 0 ) {
F_20 ( V_28 L_7 , V_32 ) ;
return V_32 ;
}
V_31 = V_32 ;
}
return 0 ;
}
void F_23 ( void )
{
F_24 ( V_31 , & V_5 ) ;
V_31 = 0 ;
}
