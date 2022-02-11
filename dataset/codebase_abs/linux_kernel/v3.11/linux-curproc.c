int F_1 ( void )
{
int V_1 ;
F_2 ( V_2 ) ;
V_1 = F_3 () -> V_3 -> V_4 ;
F_4 ( V_2 ) ;
return V_1 ;
}
void F_5 ( T_1 * V_5 , int V_6 )
{
F_2 ( V_2 ) ;
V_6 = F_6 ( int , V_6 , F_3 () -> V_3 -> V_4 ) ;
memcpy ( V_5 , F_3 () -> V_3 -> V_7 [ 0 ] , V_6 * sizeof( V_8 ) ) ;
F_4 ( V_2 ) ;
}
int F_7 ( T_1 V_9 )
{
return F_8 ( V_9 ) ;
}
void F_9 ( T_2 V_10 )
{
struct V_11 * V_11 ;
if ( ( V_11 = F_10 () ) ) {
F_11 ( V_11 -> V_12 , F_12 ( V_10 ) ) ;
F_13 ( V_11 ) ;
}
}
void F_14 ( T_2 V_10 )
{
struct V_11 * V_11 ;
if ( ( V_11 = F_10 () ) ) {
F_15 ( V_11 -> V_12 , F_12 ( V_10 ) ) ;
F_13 ( V_11 ) ;
}
}
int F_16 ( T_2 V_10 )
{
return F_17 ( F_18 () , F_12 ( V_10 ) ) ;
}
void F_19 ( T_3 V_13 , T_2 * V_10 )
{
#if F_20 ( V_14 ) && V_14 == 0x19980330
* V_10 = F_21 ( V_13 ) ;
#elif F_20 ( V_14 ) && V_14 == 0x20071026
* V_10 = F_21 ( V_13 [ 0 ] ) ;
#elif F_20 ( V_15 ) && V_15 == 0x20080522
* V_10 = F_21 ( V_13 . V_10 [ 0 ] ) ;
#else
#error "need correct _KERNEL_CAPABILITY_VERSION "
#endif
}
void F_22 ( T_3 * V_13 , T_2 V_10 )
{
#if F_20 ( V_14 ) && V_14 == 0x19980330
* V_13 = F_12 ( V_10 ) ;
#elif F_20 ( V_14 ) && V_14 == 0x20071026
( * V_13 ) [ 0 ] = F_12 ( V_10 ) ;
#elif F_20 ( V_15 ) && V_15 == 0x20080522
V_13 -> V_10 [ 0 ] = F_12 ( V_10 ) ;
#else
#error "need correct _KERNEL_CAPABILITY_VERSION "
#endif
}
T_2 F_23 ( void )
{
T_2 V_10 ;
F_19 ( F_18 () , & V_10 ) ;
return V_10 ;
}
void F_24 ( T_2 V_10 )
{
struct V_11 * V_11 ;
if ( ( V_11 = F_10 () ) ) {
F_22 ( & V_11 -> V_12 , V_10 ) ;
F_13 ( V_11 ) ;
}
}
int F_25 ( T_2 V_10 )
{
return F_26 ( F_12 ( V_10 ) ) ;
}
int F_27 ( void )
{
return F_28 () ;
}
static int F_29 ( struct V_16 * V_17 , unsigned long V_18 ,
void * V_19 , int V_20 , int V_21 )
{
struct V_22 * V_23 ;
struct V_24 * V_25 ;
struct V_26 * V_26 ;
void * V_27 = V_19 ;
V_23 = F_30 ( V_17 ) ;
if ( ! V_23 )
return 0 ;
F_31 ( & V_23 -> V_28 ) ;
while ( V_20 ) {
int V_29 , V_30 , V_31 ;
void * V_32 ;
V_30 = F_32 ( V_17 , V_23 , V_18 , 1 ,
V_21 , 1 , & V_26 , & V_25 ) ;
if ( V_30 <= 0 )
break;
V_29 = V_20 ;
V_31 = V_18 & ( V_33 - 1 ) ;
if ( V_29 > V_33 - V_31 )
V_29 = V_33 - V_31 ;
V_32 = F_33 ( V_26 ) ;
if ( V_21 ) {
F_34 ( V_25 , V_26 , V_18 ,
V_32 + V_31 , V_19 , V_29 ) ;
F_35 ( V_26 ) ;
} else {
F_36 ( V_25 , V_26 , V_18 ,
V_19 , V_32 + V_31 , V_29 ) ;
}
F_37 ( V_26 ) ;
F_38 ( V_26 ) ;
V_20 -= V_29 ;
V_19 += V_29 ;
V_18 += V_29 ;
}
F_39 ( & V_23 -> V_28 ) ;
F_40 ( V_23 ) ;
return V_19 - V_27 ;
}
int F_41 ( const char * V_34 , char * V_35 , int * V_36 )
{
struct V_22 * V_23 ;
char * V_37 , * V_38 = NULL ;
int V_39 = V_40 ;
int V_41 = strlen ( V_34 ) ;
unsigned long V_18 ;
int V_30 ;
V_42 ;
V_37 = F_42 ( V_39 , V_43 ) ;
if ( ! V_37 )
RETURN ( - V_44 ) ;
V_23 = F_30 ( V_2 ) ;
if ( ! V_23 ) {
F_43 ( V_37 ) ;
RETURN ( - V_45 ) ;
}
if ( F_44 ( & V_23 -> V_28 ) == 0 )
return - V_46 ;
F_39 ( & V_23 -> V_28 ) ;
V_18 = V_23 -> V_47 ;
while ( V_18 < V_23 -> V_48 ) {
int V_49 , V_50 , V_51 ;
char * V_47 , * V_48 ;
memset ( V_37 , 0 , V_39 ) ;
V_49 = F_6 ( int , V_23 -> V_48 - V_18 , V_39 ) ;
V_50 = F_29 ( V_2 , V_18 , V_37 ,
V_49 , 0 ) ;
if ( V_50 != V_49 )
break;
V_18 += V_50 ;
V_47 = V_37 ;
V_51 = V_49 ;
while ( V_51 ) {
char * V_52 ;
int V_53 ;
V_48 = F_45 ( V_47 , '\0' , V_51 ) ;
F_46 ( V_48 >= V_47 &&
V_48 <= V_47 + V_51 ) ;
if ( F_47 ( V_48 - V_47 == V_51 ) ) {
if ( F_47 ( V_51 == V_49 ) ) {
F_48 ( L_1 ) ;
GOTO ( V_54 , V_30 = - V_45 ) ;
}
V_18 -= V_51 ;
break;
}
V_52 = V_47 ;
V_53 = V_48 - V_47 ;
if ( V_53 > V_41 + 1 &&
! memcmp ( V_52 , V_34 , V_41 ) ) {
V_52 += V_41 + 1 ;
V_53 -= V_41 + 1 ;
if ( V_53 >= * V_36 )
GOTO ( V_54 , V_30 = - V_55 ) ;
memcpy ( V_35 , V_52 , V_53 ) ;
* V_36 = V_53 ;
GOTO ( V_54 , V_30 = 0 ) ;
}
V_51 -= ( V_48 - V_47 + 1 ) ;
V_47 = V_48 + 1 ;
}
}
GOTO ( V_54 , V_30 = - V_56 ) ;
V_54:
F_40 ( V_23 ) ;
F_43 ( ( void * ) V_37 ) ;
if ( V_38 )
F_43 ( ( void * ) V_38 ) ;
return V_30 ;
}
