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
int F_15 ( unsigned long V_22 )
{
if ( F_16 ( V_22 , V_23 | V_24 ) )
return - 1 ;
return 0 ;
}
T_5 F_17 ( T_1 V_25 , T_1 * V_16 , T_1 * V_26 , T_1 * V_27 )
{
T_1 V_28 [ 2 ] ;
T_6 V_29 ;
V_29 = F_18 ( V_25 , V_16 , ( V_30 * ) V_28 ) ;
if ( V_29 == 0 ) {
* V_26 = V_28 [ 0 ] ;
* V_27 = V_28 [ 1 ] ;
}
return V_29 ;
}
T_5 F_19 ( T_1 V_25 , T_1 V_16 , T_1 V_26 , T_1 V_27 )
{
T_1 V_28 [ 2 ] ;
V_28 [ 0 ] = V_26 ;
V_28 [ 1 ] = V_27 ;
return F_20 ( V_25 , V_16 , ( V_30 * ) V_28 ) ;
}
void F_21 ( void )
{
F_22 ( 0 ) ;
}
void F_23 ( int V_31 , int V_32 )
{
F_24 () ;
}
static T_7 F_25 ( int V_33 , void * V_34 )
{
F_26 ( V_35 L_1 ) ;
V_2 = 1 ;
F_27 () ;
return V_36 ;
}
static T_7 F_28 ( int V_33 , void * V_34 )
{
F_26 ( V_35 L_2 ) ;
V_2 = 0 ;
F_27 () ;
return V_36 ;
}
static int T_8 F_29 ( void )
{
T_1 V_37 [ 4 ] , V_38 [ 2 ] ;
int V_39 , V_15 ;
unsigned int V_33 ;
for ( V_15 = 0 ; V_15 < F_30 ( V_40 ) ; V_15 ++ ) {
struct V_40 * V_41 = & V_40 [ V_15 ] ;
if ( F_31 ( V_38 ) != 0 ) {
F_26 ( V_42 L_3
L_4 ,
V_41 -> V_43 ) ;
return - V_44 ;
}
V_33 = F_32 ( NULL , V_38 [ 0 ] ) ;
if ( V_33 == V_45 ) {
F_26 ( V_42 L_5
L_6 ,
V_41 -> V_43 ) ;
F_33 ( V_38 [ 0 ] ) ;
return - V_21 ;
}
V_41 -> V_33 = V_33 ;
V_39 = F_34 ( V_33 , V_41 -> V_46 , 0 ,
V_41 -> V_43 , NULL ) ;
if ( V_39 != 0 ) {
F_26 ( V_42 L_7
L_6 ,
V_41 -> V_43 ) ;
F_33 ( V_38 [ 0 ] ) ;
return V_39 ;
}
V_37 [ 0 ] = 0x1000000065780000ul ;
V_37 [ 1 ] = 0x627574746f6e0000ul ;
V_37 [ 2 ] = 0 ;
strncpy ( ( char * ) & V_37 [ 2 ] , V_41 -> V_43 , 8 ) ;
V_37 [ 3 ] = 0 ;
V_38 [ 1 ] = 0 ;
F_35 ( V_37 , V_38 ) ;
}
return 0 ;
}
static int T_8 F_36 ( void )
{
if ( ! F_37 ( V_47 ) )
return - V_44 ;
V_2 = 0 ;
return F_29 () ;
}
