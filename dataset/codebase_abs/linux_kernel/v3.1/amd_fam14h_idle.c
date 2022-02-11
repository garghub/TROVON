static int F_1 ( struct V_1 * V_2 ,
unsigned int * V_3 ,
unsigned int * V_4 ,
unsigned int V_5 )
{
switch ( V_2 -> V_6 ) {
case V_7 :
* V_4 = V_8 ;
* V_3 = V_9 ;
break;
case V_10 :
* V_4 = V_11 ;
* V_3 = V_12 ;
break;
case V_13 :
* V_4 = V_14 ;
* V_3 = V_15 ;
break;
case V_16 :
* V_4 = V_17 ;
* V_3 = V_18 ;
break;
default:
return - 1 ;
} ;
return 0 ;
}
static int F_2 ( T_1 * V_2 , unsigned int V_5 )
{
int V_4 , V_3 , V_19 ;
T_2 V_20 ;
V_19 = F_1 ( V_2 , & V_3 , & V_4 , V_5 ) ;
if ( V_19 )
return V_19 ;
if ( V_2 -> V_6 == V_16 ) {
V_20 = F_3 ( V_21 , V_3 ) ;
V_20 |= 1 << V_4 ;
V_20 = F_4 ( V_21 , V_3 , V_20 ) ;
return V_19 ;
}
V_20 = F_3 ( V_21 , V_22 ) ;
F_5 ( L_1 , V_2 -> V_23 ,
V_22 , ( unsigned int ) V_20 ) ;
V_20 |= 1 << V_4 ;
F_4 ( V_21 , V_22 , V_20 ) ;
F_5 ( L_2 ,
V_2 -> V_23 , V_22 , V_4 ,
( unsigned int ) V_20 , V_5 ) ;
F_4 ( V_21 , V_3 , 0 ) ;
V_24 [ V_2 -> V_6 ] [ V_5 ] = 0 ;
return 0 ;
}
static int F_6 ( T_1 * V_2 , unsigned int V_5 )
{
int V_4 , V_3 , V_19 ;
T_2 V_20 ;
V_19 = F_1 ( V_2 , & V_3 , & V_4 , V_5 ) ;
if ( V_19 )
return V_19 ;
V_20 = F_3 ( V_21 , V_3 ) ;
F_5 ( L_3 , V_2 -> V_23 , V_3 , V_20 ) ;
if ( V_2 -> V_6 == V_16 ) {
V_25 = ( V_20 & ( 1 << V_26 ) ) |
( V_20 & ( 1 << V_17 ) ) ;
F_5 ( L_4
L_5 ,
V_25 ? L_6 : L_7 ,
V_20 , V_4 , V_3 ) ;
return V_19 ;
}
V_27 [ V_2 -> V_6 ] [ V_5 ] = V_20 ;
F_5 ( L_8 , V_2 -> V_23 ,
V_27 [ V_2 -> V_6 ] [ V_5 ] , V_5 ) ;
F_5 ( L_9 , V_2 -> V_23 ,
V_24 [ V_2 -> V_6 ] [ V_5 ] , V_5 ) ;
V_20 = F_3 ( V_21 , V_22 ) ;
V_20 &= ~ ( 1 << V_4 ) ;
F_4 ( V_21 , V_22 , V_20 ) ;
return 0 ;
}
static int F_7 ( unsigned int V_6 , unsigned long long * V_28 ,
unsigned int V_5 )
{
if ( V_6 == V_16 ) {
if ( V_25 )
* V_28 = 1 ;
else
* V_28 = 0 ;
return 0 ;
}
return - 1 ;
}
static int F_8 ( unsigned int V_6 , double * V_29 ,
unsigned int V_5 )
{
unsigned long V_30 ;
if ( V_6 >= V_31 )
return - 1 ;
V_30 = V_27 [ V_6 ] [ V_5 ] - V_24 [ V_6 ] [ V_5 ] ;
if ( V_32 == 0 )
* V_29 = 0.0 ;
else
* V_29 = 100.0 * V_30 / V_32 / 12.5 ;
F_5 ( L_10 ,
V_32 , V_30 * 10 / 125 , * V_29 ) ;
return 0 ;
}
static int F_9 ( void )
{
int V_33 , V_5 ;
F_10 ( V_34 , & V_35 ) ;
for ( V_33 = 0 ; V_33 < V_31 ; V_33 ++ ) {
for ( V_5 = 0 ; V_5 < V_36 ; V_5 ++ )
F_2 ( & V_37 [ V_33 ] , V_5 ) ;
}
#ifdef F_11
F_10 ( V_34 , & V_38 ) ;
V_39 = F_12 ( V_35 , V_38 ) ;
F_5 ( L_11 ,
V_39 ) ;
#endif
return 0 ;
}
static int F_13 ( void )
{
int V_33 , V_5 ;
struct V_40 V_41 ;
F_10 ( V_34 , & V_41 ) ;
for ( V_33 = 0 ; V_33 < V_31 ; V_33 ++ ) {
for ( V_5 = 0 ; V_5 < V_36 ; V_5 ++ )
F_6 ( & V_37 [ V_33 ] , V_5 ) ;
}
#ifdef F_11
F_10 ( V_34 , & V_38 ) ;
V_39 = F_12 ( V_41 , V_38 ) ;
F_5 ( L_12 , V_39 ) ;
#endif
V_32 = F_12 ( V_35 , V_41 ) ;
if ( V_32 / 1000 > V_42 )
F_14 ( ( unsigned int ) V_32 / 1000000 ,
V_42 / 1000 ) ;
return 0 ;
}
static int F_15 ( void )
{
T_2 V_20 ;
V_20 = F_3 ( V_21 , V_43 ) ;
return V_20 & ( 1 << 31 ) ;
}
struct V_44 * F_16 ( void )
{
int V_33 ;
if ( V_45 . V_46 != V_47 )
return NULL ;
if ( V_45 . V_48 == 0x14 ) {
if ( V_36 <= 0 || V_36 > 2 ) {
fprintf ( V_49 , L_13 ,
V_36 ) ;
return NULL ;
}
} else
return NULL ;
for ( V_33 = 0 ; V_33 < V_31 - 1 ; V_33 ++ ) {
V_24 [ V_33 ] = calloc ( V_36 ,
sizeof( unsigned long long ) ) ;
V_27 [ V_33 ] = calloc ( V_36 ,
sizeof( unsigned long long ) ) ;
}
V_21 = F_17 ( & V_50 , V_51 , V_52 ) ;
if ( V_21 == NULL || V_50 == NULL )
return NULL ;
if ( ! F_15 () )
V_53 . V_54 = V_31 - 1 ;
V_53 . V_55 = strlen ( V_53 . V_23 ) ;
return & V_53 ;
}
static void F_18 ( void )
{
int V_33 ;
for ( V_33 = 0 ; V_33 < V_31 - 1 ; V_33 ++ ) {
free ( V_24 [ V_33 ] ) ;
free ( V_27 [ V_33 ] ) ;
}
F_19 ( V_50 ) ;
}
