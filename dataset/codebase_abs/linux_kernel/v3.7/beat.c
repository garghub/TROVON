void F_1 ( char * V_1 )
{
F_2 ( ! V_2 ) ;
}
void F_3 ( void )
{
F_2 ( 0 ) ;
}
void F_4 ( void )
{
F_2 ( V_3 ) ;
}
int F_5 ( struct V_4 * V_4 )
{
T_1 V_5 ;
V_5 = mktime ( V_4 -> V_6 + 1900 ,
V_4 -> V_7 + 1 , V_4 -> V_8 ,
V_4 -> V_9 , V_4 -> V_10 , V_4 -> V_11 ) ;
if ( F_6 ( V_5 ) )
return - 1 ;
return 0 ;
}
void F_7 ( struct V_4 * V_4 )
{
T_1 V_5 ;
if ( F_8 ( & V_5 ) )
V_5 = 0 ;
F_9 ( V_5 , V_4 ) ;
V_4 -> V_6 -= 1900 ;
V_4 -> V_7 -= 1 ;
}
T_2 F_10 ( char * V_12 , T_3 V_13 , T_4 * V_14 )
{
unsigned int V_15 ;
unsigned long V_16 ;
char * V_17 = V_12 ;
if ( * V_14 >= V_18 )
return - V_19 ;
V_15 = * V_14 ;
if ( V_15 + V_13 > V_18 )
V_13 = V_18 - V_15 ;
for (; V_13 != 0 ; V_13 -= V_16 ) {
V_16 = V_13 ;
if ( V_16 > V_20 )
V_16 = V_20 ;
if ( F_11 ( V_15 , V_16 , V_17 ) )
return - V_21 ;
V_17 += V_16 ;
V_15 += V_16 ;
}
* V_14 = V_15 ;
return V_17 - V_12 ;
}
T_2 F_12 ( char * V_12 , T_3 V_13 , T_4 * V_14 )
{
unsigned int V_15 ;
unsigned long V_16 ;
char * V_17 = V_12 ;
if ( * V_14 >= V_18 )
return - V_19 ;
V_15 = * V_14 ;
if ( V_15 + V_13 > V_18 )
V_13 = V_18 - V_15 ;
for (; V_13 != 0 ; V_13 -= V_16 ) {
V_16 = V_13 ;
if ( V_16 > V_20 )
V_16 = V_20 ;
if ( F_13 ( V_15 , V_16 , V_17 ) )
return - V_21 ;
V_17 += V_16 ;
V_15 += V_16 ;
}
* V_14 = V_15 ;
return V_17 - V_12 ;
}
T_2 F_14 ( void )
{
return V_18 ;
}
int F_15 ( unsigned long V_22 , unsigned long V_23 )
{
if ( F_16 ( V_22 , V_23 ) )
return - 1 ;
return 0 ;
}
T_5 F_17 ( T_1 V_24 , T_1 * V_16 , T_1 * V_25 , T_1 * V_26 )
{
T_1 V_27 [ 2 ] ;
T_6 V_28 ;
V_28 = F_18 ( V_24 , V_16 , ( V_29 * ) V_27 ) ;
if ( V_28 == 0 ) {
* V_25 = V_27 [ 0 ] ;
* V_26 = V_27 [ 1 ] ;
}
return V_28 ;
}
T_5 F_19 ( T_1 V_24 , T_1 V_16 , T_1 V_25 , T_1 V_26 )
{
T_1 V_27 [ 2 ] ;
V_27 [ 0 ] = V_25 ;
V_27 [ 1 ] = V_26 ;
return F_20 ( V_24 , V_16 , ( V_29 * ) V_27 ) ;
}
void F_21 ( void )
{
F_22 ( 0 ) ;
}
void F_23 ( int V_30 , int V_31 )
{
F_24 () ;
}
static T_7 F_25 ( int V_32 , void * V_33 )
{
F_26 ( V_34 L_1 ) ;
V_2 = 1 ;
F_27 () ;
return V_35 ;
}
static T_7 F_28 ( int V_32 , void * V_33 )
{
F_26 ( V_34 L_2 ) ;
V_2 = 0 ;
F_27 () ;
return V_35 ;
}
static int T_8 F_29 ( void )
{
T_1 V_36 [ 4 ] , V_37 [ 2 ] ;
int V_38 , V_15 ;
unsigned int V_32 ;
for ( V_15 = 0 ; V_15 < F_30 ( V_39 ) ; V_15 ++ ) {
struct V_39 * V_40 = & V_39 [ V_15 ] ;
if ( F_31 ( V_37 ) != 0 ) {
F_26 ( V_41 L_3
L_4 ,
V_40 -> V_42 ) ;
return - V_43 ;
}
V_32 = F_32 ( NULL , V_37 [ 0 ] ) ;
if ( V_32 == V_44 ) {
F_26 ( V_41 L_5
L_6 ,
V_40 -> V_42 ) ;
F_33 ( V_37 [ 0 ] ) ;
return - V_21 ;
}
V_40 -> V_32 = V_32 ;
V_38 = F_34 ( V_32 , V_40 -> V_45 , 0 ,
V_40 -> V_42 , NULL ) ;
if ( V_38 != 0 ) {
F_26 ( V_41 L_7
L_6 ,
V_40 -> V_42 ) ;
F_33 ( V_37 [ 0 ] ) ;
return V_38 ;
}
V_36 [ 0 ] = 0x1000000065780000ul ;
V_36 [ 1 ] = 0x627574746f6e0000ul ;
V_36 [ 2 ] = 0 ;
strncpy ( ( char * ) & V_36 [ 2 ] , V_40 -> V_42 , 8 ) ;
V_36 [ 3 ] = 0 ;
V_37 [ 1 ] = 0 ;
F_35 ( V_36 , V_37 ) ;
}
return 0 ;
}
static int T_8 F_36 ( void )
{
if ( ! F_37 ( V_46 ) )
return - V_43 ;
V_2 = 0 ;
return F_29 () ;
}
