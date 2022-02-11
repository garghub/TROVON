int F_1 ( void )
{
int V_1 ;
F_2 ( V_2 ) ;
V_1 = F_3 () -> V_3 -> V_4 ;
F_4 ( V_2 ) ;
return V_1 ;
}
void F_5 ( T_1 V_5 )
{
struct V_6 * V_6 ;
if ( ( V_6 = F_6 () ) ) {
F_7 ( V_6 -> V_7 , F_8 ( V_5 ) ) ;
F_9 ( V_6 ) ;
}
}
void F_10 ( T_1 V_5 )
{
struct V_6 * V_6 ;
if ( ( V_6 = F_6 () ) ) {
F_11 ( V_6 -> V_7 , F_8 ( V_5 ) ) ;
F_9 ( V_6 ) ;
}
}
int F_12 ( T_1 V_5 )
{
return F_13 ( F_14 () , F_8 ( V_5 ) ) ;
}
void F_15 ( T_2 V_8 , T_1 * V_5 )
{
#if F_16 ( V_9 ) && V_9 == 0x19980330
* V_5 = F_17 ( V_8 ) ;
#elif F_16 ( V_9 ) && V_9 == 0x20071026
* V_5 = F_17 ( V_8 [ 0 ] ) ;
#elif F_16 ( V_10 ) && V_10 == 0x20080522
* V_5 = F_17 ( V_8 . V_5 [ 0 ] ) ;
#else
#error "need correct _KERNEL_CAPABILITY_VERSION "
#endif
}
void F_18 ( T_2 * V_8 , T_1 V_5 )
{
#if F_16 ( V_9 ) && V_9 == 0x19980330
* V_8 = F_8 ( V_5 ) ;
#elif F_16 ( V_9 ) && V_9 == 0x20071026
( * V_8 ) [ 0 ] = F_8 ( V_5 ) ;
#elif F_16 ( V_10 ) && V_10 == 0x20080522
V_8 -> V_5 [ 0 ] = F_8 ( V_5 ) ;
#else
#error "need correct _KERNEL_CAPABILITY_VERSION "
#endif
}
T_1 F_19 ( void )
{
T_1 V_5 ;
F_15 ( F_14 () , & V_5 ) ;
return V_5 ;
}
void F_20 ( T_1 V_5 )
{
struct V_6 * V_6 ;
if ( ( V_6 = F_6 () ) ) {
F_18 ( & V_6 -> V_7 , V_5 ) ;
F_9 ( V_6 ) ;
}
}
int F_21 ( T_1 V_5 )
{
return F_22 ( F_8 ( V_5 ) ) ;
}
int F_23 ( void )
{
return F_24 () ;
}
static int F_25 ( struct V_11 * V_12 , unsigned long V_13 ,
void * V_14 , int V_15 , int V_16 )
{
struct V_17 * V_18 ;
struct V_19 * V_20 ;
struct V_21 * V_21 ;
void * V_22 = V_14 ;
V_18 = F_26 ( V_12 ) ;
if ( ! V_18 )
return 0 ;
F_27 ( & V_18 -> V_23 ) ;
while ( V_15 ) {
int V_24 , V_25 , V_26 ;
void * V_27 ;
V_25 = F_28 ( V_12 , V_18 , V_13 , 1 ,
V_16 , 1 , & V_21 , & V_20 ) ;
if ( V_25 <= 0 )
break;
V_24 = V_15 ;
V_26 = V_13 & ( V_28 - 1 ) ;
if ( V_24 > V_28 - V_26 )
V_24 = V_28 - V_26 ;
V_27 = F_29 ( V_21 ) ;
if ( V_16 ) {
F_30 ( V_20 , V_21 , V_13 ,
V_27 + V_26 , V_14 , V_24 ) ;
F_31 ( V_21 ) ;
} else {
F_32 ( V_20 , V_21 , V_13 ,
V_14 , V_27 + V_26 , V_24 ) ;
}
F_33 ( V_21 ) ;
F_34 ( V_21 ) ;
V_15 -= V_24 ;
V_14 += V_24 ;
V_13 += V_24 ;
}
F_35 ( & V_18 -> V_23 ) ;
F_36 ( V_18 ) ;
return V_14 - V_22 ;
}
int F_37 ( const char * V_29 , char * V_30 , int * V_31 )
{
struct V_17 * V_18 ;
char * V_32 , * V_33 = NULL ;
int V_34 = V_35 ;
int V_36 = strlen ( V_29 ) ;
unsigned long V_13 ;
int V_25 ;
V_32 = F_38 ( V_34 , V_37 ) ;
if ( ! V_32 )
return - V_38 ;
V_18 = F_26 ( V_2 ) ;
if ( ! V_18 ) {
F_39 ( V_32 ) ;
return - V_39 ;
}
if ( F_40 ( & V_18 -> V_23 ) == 0 )
return - V_40 ;
F_35 ( & V_18 -> V_23 ) ;
V_13 = V_18 -> V_41 ;
while ( V_13 < V_18 -> V_42 ) {
int V_43 , V_44 , V_45 ;
char * V_41 , * V_42 ;
memset ( V_32 , 0 , V_34 ) ;
V_43 = F_41 ( int , V_18 -> V_42 - V_13 , V_34 ) ;
V_44 = F_25 ( V_2 , V_13 , V_32 ,
V_43 , 0 ) ;
if ( V_44 != V_43 )
break;
V_13 += V_44 ;
V_41 = V_32 ;
V_45 = V_43 ;
while ( V_45 ) {
char * V_46 ;
int V_47 ;
V_42 = F_42 ( V_41 , '\0' , V_45 ) ;
F_43 ( V_42 >= V_41 &&
V_42 <= V_41 + V_45 ) ;
if ( F_44 ( V_42 - V_41 == V_45 ) ) {
if ( F_44 ( V_45 == V_43 ) ) {
F_45 ( L_1 ) ;
GOTO ( V_48 , V_25 = - V_39 ) ;
}
V_13 -= V_45 ;
break;
}
V_46 = V_41 ;
V_47 = V_42 - V_41 ;
if ( V_47 > V_36 + 1 &&
! memcmp ( V_46 , V_29 , V_36 ) ) {
V_46 += V_36 + 1 ;
V_47 -= V_36 + 1 ;
if ( V_47 >= * V_31 )
GOTO ( V_48 , V_25 = - V_49 ) ;
memcpy ( V_30 , V_46 , V_47 ) ;
* V_31 = V_47 ;
GOTO ( V_48 , V_25 = 0 ) ;
}
V_45 -= ( V_42 - V_41 + 1 ) ;
V_41 = V_42 + 1 ;
}
}
GOTO ( V_48 , V_25 = - V_50 ) ;
V_48:
F_36 ( V_18 ) ;
F_39 ( ( void * ) V_32 ) ;
if ( V_33 )
F_39 ( ( void * ) V_33 ) ;
return V_25 ;
}
