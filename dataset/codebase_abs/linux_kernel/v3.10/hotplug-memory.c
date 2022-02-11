static unsigned long F_1 ( void )
{
struct V_1 * V_2 ;
unsigned int V_3 = V_4 ;
struct V_5 V_6 ;
V_2 = F_2 ( L_1 ) ;
if ( V_2 ) {
const T_1 * V_7 ;
V_7 = F_3 ( V_2 , L_2 , NULL ) ;
if ( V_7 )
V_3 = F_4 ( V_7 ) ;
F_5 ( V_2 ) ;
} else if ( F_6 ( V_8 ) ) {
unsigned int V_9 = 0 ;
V_2 = F_2 ( L_3 ) ;
if ( V_2 ) {
if ( ! F_7 ( V_2 , 0 , & V_6 ) )
V_9 = F_8 ( & V_6 ) ;
F_5 ( V_2 ) ;
}
if ( V_9 ) {
char V_10 [ 64 ] ;
sprintf ( V_10 , L_4 , V_9 ) ;
V_2 = F_2 ( V_10 ) ;
if ( V_2 ) {
if ( ! F_7 ( V_2 , 0 , & V_6 ) )
V_3 = F_8 ( & V_6 ) ;
F_5 ( V_2 ) ;
}
}
}
return V_3 ;
}
unsigned long F_9 ( void )
{
return F_1 () ;
}
static int F_10 ( unsigned long V_11 , unsigned int V_3 )
{
unsigned long V_12 , V_13 ;
struct V_14 * V_14 ;
int V_15 ;
unsigned long V_16 ;
unsigned long V_17 ;
V_13 = V_11 >> V_18 ;
if ( ! F_11 ( V_13 ) ) {
F_12 ( V_11 , V_3 ) ;
return 0 ;
}
V_14 = F_13 ( F_14 ( V_13 ) ) ;
V_17 = ( V_3 >> V_18 ) / V_19 ;
for ( V_16 = 0 ; V_16 < V_17 ; V_16 ++ ) {
unsigned long V_20 = V_13 + V_16 * V_19 ;
V_15 = F_15 ( V_14 , V_20 , V_19 ) ;
if ( V_15 )
return V_15 ;
}
F_12 ( V_11 , V_3 ) ;
V_12 = ( unsigned long ) F_16 ( V_11 ) ;
V_15 = F_17 ( V_12 , V_12 + V_3 ) ;
F_18 () ;
return V_15 ;
}
static int F_19 ( struct V_1 * V_2 )
{
const char * type ;
const unsigned int * V_21 ;
unsigned long V_11 ;
unsigned int V_22 ;
int V_15 = - V_23 ;
type = F_3 ( V_2 , L_5 , NULL ) ;
if ( type == NULL || strcmp ( type , L_6 ) != 0 )
return 0 ;
V_21 = F_3 ( V_2 , L_7 , NULL ) ;
if ( ! V_21 )
return V_15 ;
V_11 = * ( unsigned long * ) V_21 ;
V_22 = V_21 [ 3 ] ;
V_15 = F_10 ( V_11 , V_22 ) ;
return V_15 ;
}
static inline int F_10 ( unsigned long V_11 ,
unsigned int V_3 )
{
return - V_24 ;
}
static inline int F_19 ( struct V_1 * V_2 )
{
return - V_24 ;
}
static int F_20 ( struct V_1 * V_2 )
{
const char * type ;
const unsigned int * V_21 ;
unsigned long V_11 ;
unsigned int V_22 ;
int V_15 = - V_23 ;
type = F_3 ( V_2 , L_5 , NULL ) ;
if ( type == NULL || strcmp ( type , L_6 ) != 0 )
return 0 ;
V_21 = F_3 ( V_2 , L_7 , NULL ) ;
if ( ! V_21 )
return V_15 ;
V_11 = * ( unsigned long * ) V_21 ;
V_22 = V_21 [ 3 ] ;
V_15 = F_21 ( V_11 , V_22 ) ;
return ( V_15 < 0 ) ? - V_23 : 0 ;
}
static int F_22 ( struct V_25 * V_26 )
{
struct V_27 * V_28 , * V_29 ;
unsigned long V_3 ;
T_2 V_30 ;
T_2 * V_31 ;
int V_32 , V_33 = - V_23 ;
V_3 = F_1 () ;
if ( ! V_3 )
return - V_23 ;
V_31 = ( T_2 * ) F_3 ( V_26 -> V_34 , L_8 , NULL ) ;
if ( ! V_31 )
return - V_23 ;
V_30 = * V_31 ++ ;
V_29 = (struct V_27 * ) V_31 ;
V_31 = ( T_2 * ) V_26 -> V_35 -> V_36 ;
V_31 ++ ;
V_28 = (struct V_27 * ) V_31 ;
for ( V_32 = 0 ; V_32 < V_30 ; V_32 ++ ) {
if ( ( V_29 [ V_32 ] . V_37 & V_38 ) &&
( ! ( V_28 [ V_32 ] . V_37 & V_38 ) ) ) {
V_33 = F_10 ( V_29 [ V_32 ] . V_39 ,
V_3 ) ;
break;
} else if ( ( ! ( V_29 [ V_32 ] . V_37 & V_38 ) ) &&
( V_28 [ V_32 ] . V_37 & V_38 ) ) {
V_33 = F_21 ( V_29 [ V_32 ] . V_39 ,
V_3 ) ;
V_33 = ( V_33 < 0 ) ? - V_23 : 0 ;
break;
}
}
return V_33 ;
}
static int F_23 ( struct V_40 * V_41 ,
unsigned long V_42 , void * V_43 )
{
struct V_25 * V_26 ;
int V_44 = 0 ;
switch ( V_42 ) {
case V_45 :
V_44 = F_20 ( V_43 ) ;
break;
case V_46 :
V_44 = F_19 ( V_43 ) ;
break;
case V_47 :
V_26 = (struct V_25 * ) V_43 ;
if ( ! strcmp ( V_26 -> V_35 -> V_48 , L_8 ) )
V_44 = F_22 ( V_26 ) ;
break;
}
return F_24 ( V_44 ) ;
}
static int T_3 F_25 ( void )
{
if ( F_26 ( V_49 ) )
F_27 ( & V_50 ) ;
return 0 ;
}
