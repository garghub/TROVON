void F_1 ( T_1 V_1 )
{
struct V_2 * V_2 ;
V_2 = F_2 () ;
if ( V_2 ) {
F_3 ( V_2 -> V_3 , V_1 ) ;
F_4 ( V_2 ) ;
}
}
void F_5 ( T_1 V_1 )
{
struct V_2 * V_2 ;
V_2 = F_2 () ;
if ( V_2 ) {
F_6 ( V_2 -> V_3 , V_1 ) ;
F_4 ( V_2 ) ;
}
}
int F_7 ( T_1 V_1 )
{
return F_8 ( F_9 () , V_1 ) ;
}
void F_10 ( T_2 V_4 , T_1 * V_1 )
{
* V_1 = V_4 . V_1 [ 0 ] ;
}
void F_11 ( T_2 * V_4 , T_1 V_1 )
{
V_4 -> V_1 [ 0 ] = V_1 ;
}
T_1 F_12 ( void )
{
T_1 V_1 ;
F_10 ( F_9 () , & V_1 ) ;
return V_1 ;
}
static int F_13 ( struct V_5 * V_6 , unsigned long V_7 ,
void * V_8 , int V_9 , int V_10 )
{
struct V_11 * V_12 ;
struct V_13 * V_14 ;
struct V_15 * V_15 ;
void * V_16 = V_8 ;
V_12 = F_14 ( V_6 ) ;
if ( ! V_12 )
return 0 ;
F_15 ( & V_12 -> V_17 ) ;
while ( V_9 ) {
int V_18 , V_19 , V_20 ;
void * V_21 ;
V_19 = F_16 ( V_6 , V_12 , V_7 , 1 ,
V_10 , 1 , & V_15 , & V_14 ) ;
if ( V_19 <= 0 )
break;
V_18 = V_9 ;
V_20 = V_7 & ( V_22 - 1 ) ;
if ( V_18 > V_22 - V_20 )
V_18 = V_22 - V_20 ;
V_21 = F_17 ( V_15 ) ;
if ( V_10 ) {
F_18 ( V_14 , V_15 , V_7 ,
V_21 + V_20 , V_8 , V_18 ) ;
F_19 ( V_15 ) ;
} else {
F_20 ( V_14 , V_15 , V_7 ,
V_8 , V_21 + V_20 , V_18 ) ;
}
F_21 ( V_15 ) ;
F_22 ( V_15 ) ;
V_9 -= V_18 ;
V_8 += V_18 ;
V_7 += V_18 ;
}
F_23 ( & V_12 -> V_17 ) ;
F_24 ( V_12 ) ;
return V_8 - V_16 ;
}
int F_25 ( const char * V_23 , char * V_24 , int * V_25 )
{
struct V_11 * V_12 ;
char * V_26 , * V_27 = NULL ;
int V_28 = V_29 ;
int V_30 = strlen ( V_23 ) ;
unsigned long V_7 ;
int V_19 ;
V_26 = F_26 ( V_28 , V_31 ) ;
if ( ! V_26 )
return - V_32 ;
V_12 = F_14 ( V_33 ) ;
if ( ! V_12 ) {
F_27 ( V_26 ) ;
return - V_34 ;
}
if ( F_28 ( & V_12 -> V_17 ) == 0 ) {
F_27 ( V_26 ) ;
return - V_35 ;
}
F_23 ( & V_12 -> V_17 ) ;
V_7 = V_12 -> V_36 ;
while ( V_7 < V_12 -> V_37 ) {
int V_38 , V_39 , V_40 ;
char * V_36 , * V_37 ;
memset ( V_26 , 0 , V_28 ) ;
V_38 = F_29 ( int , V_12 -> V_37 - V_7 , V_28 ) ;
V_39 = F_13 ( V_33 , V_7 , V_26 ,
V_38 , 0 ) ;
if ( V_39 != V_38 )
break;
V_7 += V_39 ;
V_36 = V_26 ;
V_40 = V_38 ;
while ( V_40 ) {
char * V_41 ;
int V_42 ;
V_37 = F_30 ( V_36 , '\0' , V_40 ) ;
F_31 ( V_37 >= V_36 &&
V_37 <= V_36 + V_40 ) ;
if ( F_32 ( V_37 - V_36 == V_40 ) ) {
if ( F_32 ( V_40 == V_38 ) ) {
F_33 ( L_1 ) ;
GOTO ( V_43 , V_19 = - V_34 ) ;
}
V_7 -= V_40 ;
break;
}
V_41 = V_36 ;
V_42 = V_37 - V_36 ;
if ( V_42 > V_30 + 1 &&
! memcmp ( V_41 , V_23 , V_30 ) ) {
V_41 += V_30 + 1 ;
V_42 -= V_30 + 1 ;
if ( V_42 >= * V_25 )
GOTO ( V_43 , V_19 = - V_44 ) ;
memcpy ( V_24 , V_41 , V_42 ) ;
* V_25 = V_42 ;
GOTO ( V_43 , V_19 = 0 ) ;
}
V_40 -= ( V_37 - V_36 + 1 ) ;
V_36 = V_37 + 1 ;
}
}
GOTO ( V_43 , V_19 = - V_45 ) ;
V_43:
F_24 ( V_12 ) ;
F_27 ( ( void * ) V_26 ) ;
if ( V_27 )
F_27 ( ( void * ) V_27 ) ;
return V_19 ;
}
