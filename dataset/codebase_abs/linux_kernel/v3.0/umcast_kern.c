static void F_1 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 ;
struct V_6 * V_7 ;
struct F_1 * V_8 = V_3 ;
V_5 = F_2 ( V_2 ) ;
V_7 = (struct V_6 * ) V_5 -> V_9 ;
V_7 -> V_10 = V_8 -> V_10 ;
V_7 -> V_11 = V_8 -> V_11 ;
V_7 -> V_12 = V_8 -> V_12 ;
V_7 -> V_13 = V_8 -> V_13 ;
V_7 -> V_14 = V_8 -> V_14 ;
V_7 -> V_2 = V_2 ;
if ( V_7 -> V_13 ) {
F_3 ( V_15 L_1
L_2 , V_7 -> V_10 , V_7 -> V_12 , V_7 -> V_11 ) ;
} else {
F_3 ( V_15 L_3
L_4 , V_7 -> V_10 , V_7 -> V_11 , V_7 -> V_14 ) ;
}
}
static int F_4 ( int V_16 , struct V_17 * V_18 , struct V_4 * V_19 )
{
return F_5 ( V_16 , F_6 ( V_18 ) ,
V_18 -> V_2 -> V_20 + V_21 ) ;
}
static int F_7 ( int V_16 , struct V_17 * V_18 , struct V_4 * V_19 )
{
return F_8 ( V_16 , V_18 -> V_3 , V_18 -> V_22 ,
(struct V_6 * ) & V_19 -> V_9 ) ;
}
static int F_9 ( char * V_23 , char * * V_24 , void * V_3 )
{
struct F_1 * V_8 = V_3 ;
char * V_25 = NULL , * V_26 = NULL , * V_27 ;
char * V_28 ;
* V_8 = ( (struct F_1 )
{ . V_10 = L_5 ,
. V_11 = 1102 ,
. V_14 = 1 } ) ;
V_27 = F_10 ( V_23 , V_24 , & V_8 -> V_10 , & V_25 , & V_26 ,
NULL ) ;
if ( V_27 != NULL ) {
F_3 ( V_29 L_6
L_7 , V_27 ) ;
return 0 ;
}
if ( V_25 != NULL ) {
V_8 -> V_11 = F_11 ( V_25 , & V_28 , 10 ) ;
if ( ( * V_28 != '\0' ) || ( V_28 == V_25 ) ) {
F_3 ( V_29 L_8 ,
V_25 ) ;
return 0 ;
}
}
if ( V_26 != NULL ) {
V_8 -> V_14 = F_11 ( V_26 , & V_28 , 10 ) ;
if ( ( * V_28 != '\0' ) || ( V_28 == V_26 ) ) {
F_3 ( V_29 L_9 ,
V_26 ) ;
return 0 ;
}
}
V_8 -> V_13 = false ;
V_8 -> V_12 = V_8 -> V_11 ;
F_3 ( V_15 L_10 , V_8 -> V_10 ,
V_8 -> V_11 , V_8 -> V_14 ) ;
return 1 ;
}
static int F_12 ( char * V_23 , char * * V_24 , void * V_3 )
{
struct F_1 * V_8 = V_3 ;
char * V_30 = NULL , * V_31 = NULL , * V_27 ;
char * V_28 ;
* V_8 = ( (struct F_1 )
{ . V_10 = L_11 ,
. V_11 = 1102 ,
. V_12 = 1102 } ) ;
V_27 = F_10 ( V_23 , V_24 , & V_8 -> V_10 ,
& V_30 , & V_31 , NULL ) ;
if ( V_27 != NULL ) {
F_3 ( V_29 L_12
L_7 , V_27 ) ;
return 0 ;
}
if ( V_30 != NULL ) {
V_8 -> V_11 = F_11 ( V_30 , & V_28 , 10 ) ;
if ( ( * V_28 != '\0' ) || ( V_28 == V_30 ) ) {
F_3 ( V_29 L_13
L_14 , V_30 ) ;
return 0 ;
}
}
if ( V_31 != NULL ) {
V_8 -> V_12 = F_11 ( V_31 , & V_28 , 10 ) ;
if ( ( * V_28 != '\0' ) || ( V_28 == V_31 ) ) {
F_3 ( V_29 L_15
L_14 , V_31 ) ;
return 0 ;
}
}
V_8 -> V_13 = true ;
F_3 ( V_15 L_16 ,
V_8 -> V_11 , V_8 -> V_10 , V_8 -> V_12 ) ;
return 1 ;
}
static int F_13 ( void )
{
F_14 ( & V_32 ) ;
F_14 ( & V_33 ) ;
return 0 ;
}
