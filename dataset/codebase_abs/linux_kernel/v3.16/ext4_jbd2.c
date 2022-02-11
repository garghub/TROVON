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
if ( V_7 -> V_9 & V_10 )
return - V_11 ;
F_6 ( V_7 -> V_12 . V_13 == V_14 ) ;
V_8 = F_7 ( V_7 ) -> V_15 ;
if ( V_8 && F_8 ( V_8 ) ) {
F_9 ( V_7 , L_1 ) ;
return - V_11 ;
}
return 0 ;
}
T_1 * F_10 ( struct V_6 * V_7 , unsigned int line ,
int type , int V_16 , int V_17 )
{
T_2 * V_8 ;
int V_18 ;
F_11 ( V_7 , V_16 , V_17 , V_19 ) ;
V_18 = F_4 ( V_7 ) ;
if ( V_18 < 0 )
return F_12 ( V_18 ) ;
V_8 = F_7 ( V_7 ) -> V_15 ;
if ( ! V_8 )
return F_1 () ;
return F_13 ( V_8 , V_16 , V_17 , V_20 ,
type , line ) ;
}
int F_14 ( const char * V_21 , unsigned int line , T_1 * V_1 )
{
struct V_6 * V_7 ;
int V_18 ;
int V_22 ;
if ( ! F_15 ( V_1 ) ) {
F_3 ( V_1 ) ;
return 0 ;
}
V_7 = V_1 -> V_23 -> V_24 -> V_25 ;
V_18 = V_1 -> V_26 ;
V_22 = F_16 ( V_1 ) ;
if ( ! V_18 )
V_18 = V_22 ;
if ( V_18 )
F_17 ( V_7 , V_21 , line , V_18 ) ;
return V_18 ;
}
T_1 * F_18 ( T_1 * V_1 , unsigned int line ,
int type )
{
struct V_6 * V_7 ;
int V_18 ;
if ( ! F_15 ( V_1 ) )
return F_1 () ;
V_7 = V_1 -> V_27 -> V_25 ;
F_19 ( V_7 , V_1 -> V_28 ,
V_19 ) ;
V_18 = F_4 ( V_7 ) ;
if ( V_18 < 0 ) {
F_20 ( V_1 ) ;
return F_12 ( V_18 ) ;
}
V_18 = F_21 ( V_1 , type , line ) ;
if ( V_18 < 0 )
return F_12 ( V_18 ) ;
return V_1 ;
}
static void F_22 ( const char * V_29 , unsigned int line ,
const char * V_30 ,
struct V_31 * V_32 ,
T_1 * V_1 , int V_18 )
{
char V_33 [ 16 ] ;
const char * V_34 = F_23 ( NULL , V_18 , V_33 ) ;
F_2 ( ! F_15 ( V_1 ) ) ;
if ( V_32 )
F_24 ( V_32 , L_2 ) ;
if ( ! V_1 -> V_26 )
V_1 -> V_26 = V_18 ;
if ( F_25 ( V_1 ) )
return;
F_26 ( V_35 L_3 ,
V_29 , line , V_34 , V_30 ) ;
F_27 ( V_1 ) ;
}
int F_28 ( const char * V_21 , unsigned int line ,
T_1 * V_1 , struct V_31 * V_32 )
{
int V_18 = 0 ;
F_5 () ;
if ( F_15 ( V_1 ) ) {
V_18 = F_29 ( V_1 , V_32 ) ;
if ( V_18 )
F_22 ( V_21 , line , V_36 , V_32 ,
V_1 , V_18 ) ;
}
return V_18 ;
}
int F_30 ( const char * V_21 , unsigned int line , T_1 * V_1 ,
int V_37 , struct V_38 * V_38 ,
struct V_31 * V_32 , T_3 V_39 )
{
int V_18 ;
F_5 () ;
F_31 ( V_38 , V_37 , V_39 ) ;
F_24 ( V_32 , L_4 ) ;
F_32 ( 4 , L_5
L_6 ,
V_32 , V_37 , V_38 -> V_40 ,
F_33 ( V_38 -> V_41 , V_42 ) ) ;
if ( ! F_15 ( V_1 ) ) {
F_34 ( V_32 ) ;
return 0 ;
}
if ( F_33 ( V_38 -> V_41 , V_42 ) == V_43 ||
( ! V_37 && ! F_35 ( V_38 ) ) ) {
if ( V_32 ) {
F_24 ( V_32 , L_7 ) ;
V_18 = F_36 ( V_1 , V_32 ) ;
if ( V_18 )
F_22 ( V_21 , line , V_36 ,
V_32 , V_1 , V_18 ) ;
return V_18 ;
}
return 0 ;
}
F_24 ( V_32 , L_8 ) ;
V_18 = F_37 ( V_1 , V_39 , V_32 ) ;
if ( V_18 ) {
F_22 ( V_21 , line , V_36 ,
V_32 , V_1 , V_18 ) ;
F_38 ( V_38 -> V_41 , V_21 , line ,
L_9 , V_18 ) ;
}
F_24 ( V_32 , L_10 ) ;
return V_18 ;
}
int F_39 ( const char * V_21 , unsigned int line ,
T_1 * V_1 , struct V_31 * V_32 )
{
int V_18 = 0 ;
if ( F_15 ( V_1 ) ) {
V_18 = F_40 ( V_1 , V_32 ) ;
if ( V_18 )
F_22 ( V_21 , line , V_36 ,
V_32 , V_1 , V_18 ) ;
}
return V_18 ;
}
int F_41 ( const char * V_21 , unsigned int line ,
T_1 * V_1 , struct V_38 * V_38 ,
struct V_31 * V_32 )
{
int V_18 = 0 ;
F_5 () ;
F_42 ( V_32 ) ;
F_43 ( V_32 ) ;
if ( F_15 ( V_1 ) ) {
V_18 = F_44 ( V_1 , V_32 ) ;
if ( F_45 ( V_18 ) ) {
F_22 ( V_21 , line , V_36 , V_32 ,
V_1 , V_18 ) ;
if ( V_38 == NULL ) {
F_46 ( L_11
L_12
L_13 ,
V_1 -> V_44 ,
V_1 -> V_45 ,
V_1 -> V_46 ,
V_1 -> V_28 , V_18 ) ;
return V_18 ;
}
F_47 ( V_38 , V_21 , line ,
V_32 -> V_47 ,
L_14
L_15
L_16 ,
V_1 -> V_44 ,
V_1 -> V_45 ,
V_1 -> V_46 ,
V_1 -> V_28 , V_18 ) ;
}
} else {
if ( V_38 )
F_48 ( V_32 , V_38 ) ;
else
F_49 ( V_32 ) ;
if ( V_38 && F_50 ( V_38 ) ) {
F_51 ( V_32 ) ;
if ( F_52 ( V_32 ) && ! F_53 ( V_32 ) ) {
struct V_48 * V_49 ;
V_49 = F_7 ( V_38 -> V_41 ) -> V_50 ;
V_49 -> V_51 =
F_54 ( V_32 -> V_47 ) ;
F_47 ( V_38 , V_21 , line ,
V_32 -> V_47 ,
L_17 ) ;
V_18 = - V_52 ;
}
}
}
return V_18 ;
}
int F_55 ( const char * V_21 , unsigned int line ,
T_1 * V_1 , struct V_6 * V_7 )
{
struct V_31 * V_32 = F_7 ( V_7 ) -> V_53 ;
int V_18 = 0 ;
F_56 ( V_7 ) ;
if ( F_15 ( V_1 ) ) {
V_18 = F_44 ( V_1 , V_32 ) ;
if ( V_18 )
F_22 ( V_21 , line , V_36 ,
V_32 , V_1 , V_18 ) ;
} else
F_49 ( V_32 ) ;
return V_18 ;
}
