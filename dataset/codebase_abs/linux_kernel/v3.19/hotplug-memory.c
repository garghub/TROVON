unsigned long F_1 ( void )
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
static int F_9 ( unsigned long V_11 , unsigned int V_3 )
{
unsigned long V_12 , V_13 ;
int V_14 ;
int V_15 , V_16 ;
V_13 = V_11 >> V_17 ;
F_10 () ;
if ( ! F_11 ( V_13 ) )
goto V_18;
V_12 = F_1 () ;
V_14 = V_12 / V_4 ;
V_16 = F_12 ( V_11 ) ;
for ( V_15 = 0 ; V_15 < V_14 ; V_15 ++ ) {
F_13 ( V_16 , V_11 , V_4 ) ;
V_11 += V_4 ;
}
V_18:
F_14 ( V_11 , V_3 ) ;
F_15 () ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 )
{
const char * type ;
const T_2 * V_19 ;
unsigned long V_11 ;
unsigned int V_20 ;
int V_21 = - V_22 ;
type = F_3 ( V_2 , L_5 , NULL ) ;
if ( type == NULL || strcmp ( type , L_6 ) != 0 )
return 0 ;
V_19 = F_3 ( V_2 , L_7 , NULL ) ;
if ( ! V_19 )
return V_21 ;
V_11 = F_17 ( * ( unsigned long * ) V_19 ) ;
V_20 = F_18 ( V_19 [ 3 ] ) ;
F_9 ( V_11 , V_20 ) ;
return 0 ;
}
static inline int F_9 ( unsigned long V_11 ,
unsigned int V_3 )
{
return - V_23 ;
}
static inline int F_16 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_19 ( struct V_1 * V_2 )
{
const char * type ;
const T_2 * V_19 ;
unsigned long V_11 ;
unsigned int V_20 ;
int V_21 = - V_22 ;
type = F_3 ( V_2 , L_5 , NULL ) ;
if ( type == NULL || strcmp ( type , L_6 ) != 0 )
return 0 ;
V_19 = F_3 ( V_2 , L_7 , NULL ) ;
if ( ! V_19 )
return V_21 ;
V_11 = F_17 ( * ( unsigned long * ) V_19 ) ;
V_20 = F_18 ( V_19 [ 3 ] ) ;
V_21 = F_20 ( V_11 , V_20 ) ;
return ( V_21 < 0 ) ? - V_22 : 0 ;
}
static int F_21 ( struct V_24 * V_25 )
{
struct V_26 * V_27 , * V_28 ;
unsigned long V_3 ;
T_3 V_29 ;
T_2 * V_30 ;
int V_15 , V_31 = - V_22 ;
V_3 = F_1 () ;
if ( ! V_3 )
return - V_22 ;
V_30 = ( T_2 * ) V_25 -> V_32 -> V_33 ;
if ( ! V_30 )
return - V_22 ;
V_29 = F_18 ( * V_30 ++ ) ;
V_28 = (struct V_26 * ) V_30 ;
V_30 = ( T_2 * ) V_25 -> V_34 -> V_33 ;
V_30 ++ ;
V_27 = (struct V_26 * ) V_30 ;
for ( V_15 = 0 ; V_15 < V_29 ; V_15 ++ ) {
if ( ( F_18 ( V_28 [ V_15 ] . V_35 ) & V_36 ) &&
( ! ( F_18 ( V_27 [ V_15 ] . V_35 ) & V_36 ) ) ) {
V_31 = F_9 (
F_17 ( V_28 [ V_15 ] . V_37 ) ,
V_3 ) ;
break;
} else if ( ( ! ( F_18 ( V_28 [ V_15 ] . V_35 ) &
V_36 ) ) &&
( F_18 ( V_27 [ V_15 ] . V_35 ) &
V_36 ) ) {
V_31 = F_20 ( F_17 ( V_28 [ V_15 ] . V_37 ) ,
V_3 ) ;
V_31 = ( V_31 < 0 ) ? - V_22 : 0 ;
break;
}
}
return V_31 ;
}
static int F_22 ( struct V_38 * V_39 ,
unsigned long V_40 , void * V_41 )
{
struct V_24 * V_42 = V_41 ;
int V_43 = 0 ;
switch ( V_40 ) {
case V_44 :
V_43 = F_19 ( V_42 -> V_45 ) ;
break;
case V_46 :
V_43 = F_16 ( V_42 -> V_45 ) ;
break;
case V_47 :
if ( ! strcmp ( V_42 -> V_34 -> V_48 , L_8 ) )
V_43 = F_21 ( V_42 ) ;
break;
}
return F_23 ( V_43 ) ;
}
static int T_4 F_24 ( void )
{
if ( F_25 ( V_49 ) )
F_26 ( & V_50 ) ;
return 0 ;
}
