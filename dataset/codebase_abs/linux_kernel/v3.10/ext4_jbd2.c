static T_1 * F_1 ( void )
{
T_1 * V_1 = V_2 -> V_3 ;
unsigned long V_4 = ( unsigned long ) V_1 ;
F_2 ( V_4 >= V_5 ) ;
V_4 ++ ;
V_1 = ( T_1 * ) V_4 ;
V_2 -> V_3 = V_1 ;
return V_1 ;
}
static void F_3 ( T_1 * V_1 )
{
unsigned long V_4 = ( unsigned long ) V_1 ;
F_2 ( V_4 == 0 ) ;
V_4 -- ;
V_1 = ( T_1 * ) V_4 ;
V_2 -> V_3 = V_1 ;
}
T_1 * F_4 ( struct V_6 * V_7 , unsigned int line ,
int type , int V_8 )
{
T_2 * V_9 ;
F_5 () ;
F_6 ( V_7 , V_8 , V_10 ) ;
if ( V_7 -> V_11 & V_12 )
return F_7 ( - V_13 ) ;
F_8 ( V_7 -> V_14 . V_15 == V_16 ) ;
V_9 = F_9 ( V_7 ) -> V_17 ;
if ( ! V_9 )
return F_1 () ;
if ( F_10 ( V_9 ) ) {
F_11 ( V_7 , L_1 ) ;
return F_7 ( - V_13 ) ;
}
return F_12 ( V_9 , V_8 , V_18 , type , line ) ;
}
int F_13 ( const char * V_19 , unsigned int line , T_1 * V_1 )
{
struct V_6 * V_7 ;
int V_20 ;
int V_21 ;
if ( ! F_14 ( V_1 ) ) {
F_3 ( V_1 ) ;
return 0 ;
}
V_7 = V_1 -> V_22 -> V_23 -> V_24 ;
V_20 = V_1 -> V_25 ;
V_21 = F_15 ( V_1 ) ;
if ( ! V_20 )
V_20 = V_21 ;
if ( V_20 )
F_16 ( V_7 , V_19 , line , V_20 ) ;
return V_20 ;
}
void F_17 ( const char * V_26 , unsigned int line ,
const char * V_27 , struct V_28 * V_29 ,
T_1 * V_1 , int V_20 )
{
char V_30 [ 16 ] ;
const char * V_31 = F_18 ( NULL , V_20 , V_30 ) ;
F_2 ( ! F_14 ( V_1 ) ) ;
if ( V_29 )
F_19 ( V_29 , L_2 ) ;
if ( ! V_1 -> V_25 )
V_1 -> V_25 = V_20 ;
if ( F_20 ( V_1 ) )
return;
F_21 ( V_32 L_3 ,
V_26 , line , V_31 , V_27 ) ;
F_22 ( V_1 ) ;
}
int F_23 ( const char * V_19 , unsigned int line ,
T_1 * V_1 , struct V_28 * V_29 )
{
int V_20 = 0 ;
F_5 () ;
if ( F_14 ( V_1 ) ) {
V_20 = F_24 ( V_1 , V_29 ) ;
if ( V_20 )
F_17 ( V_19 , line , V_33 , V_29 ,
V_1 , V_20 ) ;
}
return V_20 ;
}
int F_25 ( const char * V_19 , unsigned int line , T_1 * V_1 ,
int V_34 , struct V_35 * V_35 ,
struct V_28 * V_29 , T_3 V_36 )
{
int V_20 ;
F_5 () ;
F_26 ( V_35 , V_34 , V_36 ) ;
F_19 ( V_29 , L_4 ) ;
F_27 ( 4 , L_5
L_6 ,
V_29 , V_34 , V_35 -> V_37 ,
F_28 ( V_35 -> V_38 , V_39 ) ) ;
if ( ! F_14 ( V_1 ) ) {
F_29 ( V_29 ) ;
return 0 ;
}
if ( F_28 ( V_35 -> V_38 , V_39 ) == V_40 ||
( ! V_34 && ! F_30 ( V_35 ) ) ) {
if ( V_29 ) {
F_19 ( V_29 , L_7 ) ;
V_20 = F_31 ( V_1 , V_29 ) ;
if ( V_20 )
F_17 ( V_19 , line , V_33 ,
V_29 , V_1 , V_20 ) ;
return V_20 ;
}
return 0 ;
}
F_19 ( V_29 , L_8 ) ;
V_20 = F_32 ( V_1 , V_36 , V_29 ) ;
if ( V_20 ) {
F_17 ( V_19 , line , V_33 ,
V_29 , V_1 , V_20 ) ;
F_33 ( V_35 -> V_38 , V_19 , line ,
L_9 , V_20 ) ;
}
F_19 ( V_29 , L_10 ) ;
return V_20 ;
}
int F_34 ( const char * V_19 , unsigned int line ,
T_1 * V_1 , struct V_28 * V_29 )
{
int V_20 = 0 ;
if ( F_14 ( V_1 ) ) {
V_20 = F_35 ( V_1 , V_29 ) ;
if ( V_20 )
F_17 ( V_19 , line , V_33 ,
V_29 , V_1 , V_20 ) ;
}
return V_20 ;
}
int F_36 ( const char * V_19 , unsigned int line ,
T_1 * V_1 , struct V_35 * V_35 ,
struct V_28 * V_29 )
{
int V_20 = 0 ;
F_5 () ;
F_37 ( V_29 ) ;
F_38 ( V_29 ) ;
if ( F_14 ( V_1 ) ) {
V_20 = F_39 ( V_1 , V_29 ) ;
if ( V_20 ) {
V_1 -> V_25 = V_20 ;
F_13 ( V_19 , line , V_1 ) ;
}
} else {
if ( V_35 )
F_40 ( V_29 , V_35 ) ;
else
F_41 ( V_29 ) ;
if ( V_35 && F_42 ( V_35 ) ) {
F_43 ( V_29 ) ;
if ( F_44 ( V_29 ) && ! F_45 ( V_29 ) ) {
struct V_41 * V_42 ;
V_42 = F_9 ( V_35 -> V_38 ) -> V_43 ;
V_42 -> V_44 =
F_46 ( V_29 -> V_45 ) ;
F_47 ( V_35 , V_19 , line ,
V_29 -> V_45 ,
L_11 ) ;
V_20 = - V_46 ;
}
}
}
return V_20 ;
}
int F_48 ( const char * V_19 , unsigned int line ,
T_1 * V_1 , struct V_6 * V_7 )
{
struct V_28 * V_29 = F_9 ( V_7 ) -> V_47 ;
int V_20 = 0 ;
F_49 ( V_7 ) ;
if ( F_14 ( V_1 ) ) {
V_20 = F_39 ( V_1 , V_29 ) ;
if ( V_20 )
F_17 ( V_19 , line , V_33 ,
V_29 , V_1 , V_20 ) ;
} else
F_41 ( V_29 ) ;
return V_20 ;
}
