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
if ( V_7 -> V_10 & V_11 )
return - V_12 ;
F_9 ( V_7 -> V_13 . V_14 == V_15 ) ;
V_8 = F_8 ( V_7 ) -> V_16 ;
if ( V_8 && F_10 ( V_8 ) ) {
F_11 ( V_7 , L_1 ) ;
return - V_12 ;
}
return 0 ;
}
T_1 * F_12 ( struct V_6 * V_7 , unsigned int line ,
int type , int V_17 , int V_18 )
{
T_2 * V_8 ;
int V_19 ;
F_13 ( V_7 , V_17 , V_18 , V_20 ) ;
V_19 = F_4 ( V_7 ) ;
if ( V_19 < 0 )
return F_14 ( V_19 ) ;
V_8 = F_8 ( V_7 ) -> V_16 ;
if ( ! V_8 )
return F_1 () ;
return F_15 ( V_8 , V_17 , V_18 , V_21 ,
type , line ) ;
}
int F_16 ( const char * V_22 , unsigned int line , T_1 * V_1 )
{
struct V_6 * V_7 ;
int V_19 ;
int V_23 ;
if ( ! F_17 ( V_1 ) ) {
F_3 ( V_1 ) ;
return 0 ;
}
V_19 = V_1 -> V_24 ;
if ( ! V_1 -> V_25 ) {
V_23 = F_18 ( V_1 ) ;
return V_19 ? V_19 : V_23 ;
}
V_7 = V_1 -> V_25 -> V_26 -> V_27 ;
V_23 = F_18 ( V_1 ) ;
if ( ! V_19 )
V_19 = V_23 ;
if ( V_19 )
F_19 ( V_7 , V_22 , line , V_19 ) ;
return V_19 ;
}
T_1 * F_20 ( T_1 * V_1 , unsigned int line ,
int type )
{
struct V_6 * V_7 ;
int V_19 ;
if ( ! F_17 ( V_1 ) )
return F_1 () ;
V_7 = V_1 -> V_28 -> V_27 ;
F_21 ( V_7 , V_1 -> V_29 ,
V_20 ) ;
V_19 = F_4 ( V_7 ) ;
if ( V_19 < 0 ) {
F_22 ( V_1 ) ;
return F_14 ( V_19 ) ;
}
V_19 = F_23 ( V_1 , type , line ) ;
if ( V_19 < 0 )
return F_14 ( V_19 ) ;
return V_1 ;
}
static void F_24 ( const char * V_30 , unsigned int line ,
const char * V_31 ,
struct V_32 * V_33 ,
T_1 * V_1 , int V_19 )
{
char V_34 [ 16 ] ;
const char * V_35 = F_25 ( NULL , V_19 , V_34 ) ;
F_2 ( ! F_17 ( V_1 ) ) ;
if ( V_33 )
F_26 ( V_33 , L_2 ) ;
if ( ! V_1 -> V_24 )
V_1 -> V_24 = V_19 ;
if ( F_27 ( V_1 ) )
return;
F_28 ( V_36 L_3 ,
V_30 , line , V_35 , V_31 ) ;
F_29 ( V_1 ) ;
}
int F_30 ( const char * V_22 , unsigned int line ,
T_1 * V_1 , struct V_32 * V_33 )
{
int V_19 = 0 ;
F_5 () ;
if ( F_17 ( V_1 ) ) {
struct V_6 * V_7 ;
V_7 = V_1 -> V_25 -> V_26 -> V_27 ;
if ( F_6 ( F_7 ( F_8 ( V_7 ) ) ) ) {
F_29 ( V_1 ) ;
return - V_9 ;
}
V_19 = F_31 ( V_1 , V_33 ) ;
if ( V_19 )
F_24 ( V_22 , line , V_37 , V_33 ,
V_1 , V_19 ) ;
}
return V_19 ;
}
int F_32 ( const char * V_22 , unsigned int line , T_1 * V_1 ,
int V_38 , struct V_39 * V_39 ,
struct V_32 * V_33 , T_3 V_40 )
{
int V_19 ;
F_5 () ;
F_33 ( V_39 , V_38 , V_40 ) ;
F_26 ( V_33 , L_4 ) ;
F_34 ( 4 , L_5
L_6 ,
V_33 , V_38 , V_39 -> V_41 ,
F_35 ( V_39 -> V_42 , V_43 ) ) ;
if ( ! F_17 ( V_1 ) ) {
F_36 ( V_33 ) ;
return 0 ;
}
if ( F_35 ( V_39 -> V_42 , V_43 ) == V_44 ||
( ! V_38 && ! F_37 ( V_39 ) ) ) {
if ( V_33 ) {
F_26 ( V_33 , L_7 ) ;
V_19 = F_38 ( V_1 , V_33 ) ;
if ( V_19 )
F_24 ( V_22 , line , V_37 ,
V_33 , V_1 , V_19 ) ;
return V_19 ;
}
return 0 ;
}
F_26 ( V_33 , L_8 ) ;
V_19 = F_39 ( V_1 , V_40 , V_33 ) ;
if ( V_19 ) {
F_24 ( V_22 , line , V_37 ,
V_33 , V_1 , V_19 ) ;
F_40 ( V_39 -> V_42 , V_22 , line ,
L_9 , V_19 ) ;
}
F_26 ( V_33 , L_10 ) ;
return V_19 ;
}
int F_41 ( const char * V_22 , unsigned int line ,
T_1 * V_1 , struct V_32 * V_33 )
{
int V_19 = 0 ;
if ( F_17 ( V_1 ) ) {
V_19 = F_42 ( V_1 , V_33 ) ;
if ( V_19 )
F_24 ( V_22 , line , V_37 ,
V_33 , V_1 , V_19 ) ;
}
return V_19 ;
}
int F_43 ( const char * V_22 , unsigned int line ,
T_1 * V_1 , struct V_39 * V_39 ,
struct V_32 * V_33 )
{
int V_19 = 0 ;
F_5 () ;
F_44 ( V_33 ) ;
F_45 ( V_33 ) ;
if ( F_17 ( V_1 ) ) {
V_19 = F_46 ( V_1 , V_33 ) ;
if ( ! F_27 ( V_1 ) && F_47 ( V_19 ) ) {
F_24 ( V_22 , line , V_37 , V_33 ,
V_1 , V_19 ) ;
if ( V_39 == NULL ) {
F_48 ( L_11
L_12
L_13 ,
V_1 -> V_45 ,
V_1 -> V_46 ,
V_1 -> V_47 ,
V_1 -> V_29 , V_19 ) ;
return V_19 ;
}
F_49 ( V_39 , V_22 , line ,
V_33 -> V_48 ,
L_14
L_15
L_16 ,
V_1 -> V_45 ,
V_1 -> V_46 ,
V_1 -> V_47 ,
V_1 -> V_29 , V_19 ) ;
}
} else {
if ( V_39 )
F_50 ( V_33 , V_39 ) ;
else
F_51 ( V_33 ) ;
if ( V_39 && F_52 ( V_39 ) ) {
F_53 ( V_33 ) ;
if ( F_54 ( V_33 ) && ! F_55 ( V_33 ) ) {
struct V_49 * V_50 ;
V_50 = F_8 ( V_39 -> V_42 ) -> V_51 ;
V_50 -> V_52 =
F_56 ( V_33 -> V_48 ) ;
F_49 ( V_39 , V_22 , line ,
V_33 -> V_48 ,
L_17 ) ;
V_19 = - V_9 ;
}
}
}
return V_19 ;
}
int F_57 ( const char * V_22 , unsigned int line ,
T_1 * V_1 , struct V_6 * V_7 )
{
struct V_32 * V_33 = F_8 ( V_7 ) -> V_53 ;
int V_19 = 0 ;
F_58 ( V_7 ) ;
if ( F_17 ( V_1 ) ) {
V_19 = F_46 ( V_1 , V_33 ) ;
if ( V_19 )
F_24 ( V_22 , line , V_37 ,
V_33 , V_1 , V_19 ) ;
} else
F_51 ( V_33 ) ;
return V_19 ;
}
