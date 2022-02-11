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
static int F_4 ( struct V_6 * V_7 )
{
T_2 * V_8 ;
F_5 () ;
if ( F_6 ( F_7 ( F_8 ( V_7 ) ) ) )
return - V_9 ;
if ( F_9 ( V_7 ) )
return - V_10 ;
F_10 ( V_7 -> V_11 . V_12 == V_13 ) ;
V_8 = F_8 ( V_7 ) -> V_14 ;
if ( V_8 && F_11 ( V_8 ) ) {
F_12 ( V_7 , L_1 ) ;
return - V_10 ;
}
return 0 ;
}
T_1 * F_13 ( struct V_6 * V_7 , unsigned int line ,
int type , int V_15 , int V_16 )
{
T_2 * V_8 ;
int V_17 ;
F_14 ( V_7 , V_15 , V_16 , V_18 ) ;
V_17 = F_4 ( V_7 ) ;
if ( V_17 < 0 )
return F_15 ( V_17 ) ;
V_8 = F_8 ( V_7 ) -> V_14 ;
if ( ! V_8 )
return F_1 () ;
return F_16 ( V_8 , V_15 , V_16 , V_19 ,
type , line ) ;
}
int F_17 ( const char * V_20 , unsigned int line , T_1 * V_1 )
{
struct V_6 * V_7 ;
int V_17 ;
int V_21 ;
if ( ! F_18 ( V_1 ) ) {
F_3 ( V_1 ) ;
return 0 ;
}
V_17 = V_1 -> V_22 ;
if ( ! V_1 -> V_23 ) {
V_21 = F_19 ( V_1 ) ;
return V_17 ? V_17 : V_21 ;
}
V_7 = V_1 -> V_23 -> V_24 -> V_25 ;
V_21 = F_19 ( V_1 ) ;
if ( ! V_17 )
V_17 = V_21 ;
if ( V_17 )
F_20 ( V_7 , V_20 , line , V_17 ) ;
return V_17 ;
}
T_1 * F_21 ( T_1 * V_1 , unsigned int line ,
int type )
{
struct V_6 * V_7 ;
int V_17 ;
if ( ! F_18 ( V_1 ) )
return F_1 () ;
V_7 = V_1 -> V_26 -> V_25 ;
F_22 ( V_7 , V_1 -> V_27 ,
V_18 ) ;
V_17 = F_4 ( V_7 ) ;
if ( V_17 < 0 ) {
F_23 ( V_1 ) ;
return F_15 ( V_17 ) ;
}
V_17 = F_24 ( V_1 , type , line ) ;
if ( V_17 < 0 )
return F_15 ( V_17 ) ;
return V_1 ;
}
static void F_25 ( const char * V_28 , unsigned int line ,
const char * V_29 ,
struct V_30 * V_31 ,
T_1 * V_1 , int V_17 )
{
char V_32 [ 16 ] ;
const char * V_33 = F_26 ( NULL , V_17 , V_32 ) ;
F_2 ( ! F_18 ( V_1 ) ) ;
if ( V_31 )
F_27 ( V_31 , L_2 ) ;
if ( ! V_1 -> V_22 )
V_1 -> V_22 = V_17 ;
if ( F_28 ( V_1 ) )
return;
F_29 ( V_34 L_3 ,
V_28 , line , V_33 , V_29 ) ;
F_30 ( V_1 ) ;
}
int F_31 ( const char * V_20 , unsigned int line ,
T_1 * V_1 , struct V_30 * V_31 )
{
int V_17 = 0 ;
F_5 () ;
if ( F_18 ( V_1 ) ) {
struct V_6 * V_7 ;
V_7 = V_1 -> V_23 -> V_24 -> V_25 ;
if ( F_6 ( F_7 ( F_8 ( V_7 ) ) ) ) {
F_30 ( V_1 ) ;
return - V_9 ;
}
V_17 = F_32 ( V_1 , V_31 ) ;
if ( V_17 )
F_25 ( V_20 , line , V_35 , V_31 ,
V_1 , V_17 ) ;
}
return V_17 ;
}
int F_33 ( const char * V_20 , unsigned int line , T_1 * V_1 ,
int V_36 , struct V_37 * V_37 ,
struct V_30 * V_31 , T_3 V_38 )
{
int V_17 ;
F_5 () ;
F_34 ( V_37 , V_36 , V_38 ) ;
F_27 ( V_31 , L_4 ) ;
F_35 ( 4 , L_5
L_6 ,
V_31 , V_36 , V_37 -> V_39 ,
F_36 ( V_37 -> V_40 , V_41 ) ) ;
if ( ! F_18 ( V_1 ) ) {
F_37 ( V_31 ) ;
return 0 ;
}
if ( F_36 ( V_37 -> V_40 , V_41 ) == V_42 ||
( ! V_36 && ! F_38 ( V_37 ) ) ) {
if ( V_31 ) {
F_27 ( V_31 , L_7 ) ;
V_17 = F_39 ( V_1 , V_31 ) ;
if ( V_17 )
F_25 ( V_20 , line , V_35 ,
V_31 , V_1 , V_17 ) ;
return V_17 ;
}
return 0 ;
}
F_27 ( V_31 , L_8 ) ;
V_17 = F_40 ( V_1 , V_38 , V_31 ) ;
if ( V_17 ) {
F_25 ( V_20 , line , V_35 ,
V_31 , V_1 , V_17 ) ;
F_41 ( V_37 -> V_40 , V_20 , line ,
L_9 , V_17 ) ;
}
F_27 ( V_31 , L_10 ) ;
return V_17 ;
}
int F_42 ( const char * V_20 , unsigned int line ,
T_1 * V_1 , struct V_30 * V_31 )
{
int V_17 = 0 ;
if ( F_18 ( V_1 ) ) {
V_17 = F_43 ( V_1 , V_31 ) ;
if ( V_17 )
F_25 ( V_20 , line , V_35 ,
V_31 , V_1 , V_17 ) ;
}
return V_17 ;
}
int F_44 ( const char * V_20 , unsigned int line ,
T_1 * V_1 , struct V_37 * V_37 ,
struct V_30 * V_31 )
{
int V_17 = 0 ;
F_5 () ;
F_45 ( V_31 ) ;
F_46 ( V_31 ) ;
if ( F_18 ( V_1 ) ) {
V_17 = F_47 ( V_1 , V_31 ) ;
if ( ! F_28 ( V_1 ) && F_48 ( V_17 ) ) {
F_25 ( V_20 , line , V_35 , V_31 ,
V_1 , V_17 ) ;
if ( V_37 == NULL ) {
F_49 ( L_11
L_12
L_13 ,
V_1 -> V_43 ,
V_1 -> V_44 ,
V_1 -> V_45 ,
V_1 -> V_27 , V_17 ) ;
return V_17 ;
}
F_50 ( V_37 , V_20 , line ,
V_31 -> V_46 ,
L_14
L_15
L_16 ,
V_1 -> V_43 ,
V_1 -> V_44 ,
V_1 -> V_45 ,
V_1 -> V_27 , V_17 ) ;
}
} else {
if ( V_37 )
F_51 ( V_31 , V_37 ) ;
else
F_52 ( V_31 ) ;
if ( V_37 && F_53 ( V_37 ) ) {
F_54 ( V_31 ) ;
if ( F_55 ( V_31 ) && ! F_56 ( V_31 ) ) {
struct V_47 * V_48 ;
V_48 = F_8 ( V_37 -> V_40 ) -> V_49 ;
V_48 -> V_50 =
F_57 ( V_31 -> V_46 ) ;
F_50 ( V_37 , V_20 , line ,
V_31 -> V_46 ,
L_17 ) ;
V_17 = - V_9 ;
}
}
}
return V_17 ;
}
int F_58 ( const char * V_20 , unsigned int line ,
T_1 * V_1 , struct V_6 * V_7 )
{
struct V_30 * V_31 = F_8 ( V_7 ) -> V_51 ;
int V_17 = 0 ;
F_59 ( V_7 ) ;
if ( F_18 ( V_1 ) ) {
V_17 = F_47 ( V_1 , V_31 ) ;
if ( V_17 )
F_25 ( V_20 , line , V_35 ,
V_31 , V_1 , V_17 ) ;
} else
F_52 ( V_31 ) ;
return V_17 ;
}
