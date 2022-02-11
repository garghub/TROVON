static long T_1 F_1 ( struct V_1 * V_1 )
{
long V_2 ;
int V_3 ;
V_3 = F_2 ( V_1 ) ;
if ( V_3 ) {
F_3 ( L_1 , V_3 ) ;
F_4 ( V_1 ) ;
return V_3 ;
}
V_3 = F_5 ( V_1 ) ;
if ( V_3 ) {
F_3 ( L_2 , V_3 ) ;
F_6 ( V_1 ) ;
F_4 ( V_1 ) ;
return V_3 ;
}
V_2 = F_7 ( V_1 ) ;
if ( V_2 < 0 ) {
F_3 ( L_3 , V_2 ) ;
F_8 ( V_1 ) ;
F_6 ( V_1 ) ;
F_4 ( V_1 ) ;
}
return V_2 ;
}
static T_2 T_3 F_9 ( void )
{
return ~ F_10 ( V_4 + V_5 ) ;
}
void T_1 F_11 ( void T_4 * V_6 )
{
F_12 ( 0 , V_6 + V_7 ) ;
}
int T_1 F_13 ( void T_4 * V_6 ,
const char * V_8 ,
struct V_1 * V_1 ,
int V_9 )
{
long V_2 ;
if ( ! V_1 ) {
V_1 = F_14 ( L_4 , V_8 ) ;
if ( F_15 ( V_1 ) ) {
F_3 ( L_5 ,
( int ) F_16 ( V_1 ) ) ;
return F_16 ( V_1 ) ;
}
}
V_2 = F_1 ( V_1 ) ;
if ( V_2 < 0 )
return - V_10 ;
F_12 ( 0 , V_6 + V_7 ) ;
F_12 ( 0xffffffff , V_6 + V_11 ) ;
F_12 ( 0xffffffff , V_6 + V_5 ) ;
F_12 ( V_12 | V_13 | V_14 ,
V_6 + V_7 ) ;
F_17 ( V_6 + V_5 , V_8 ,
V_2 , 200 , 32 , V_15 ) ;
if ( V_9 ) {
V_4 = V_6 ;
F_18 ( F_9 , 32 , V_2 ) ;
}
return 0 ;
}
static T_5 F_19 ( int V_16 , void * V_17 )
{
struct V_18 * V_19 = V_17 ;
F_12 ( 1 , V_20 + V_21 ) ;
V_19 -> V_22 ( V_19 ) ;
return V_23 ;
}
static inline void F_20 ( struct V_18 * V_19 )
{
F_12 ( 0 , V_20 + V_7 ) ;
}
static int F_21 ( struct V_18 * V_19 )
{
F_20 ( V_19 ) ;
return 0 ;
}
static int F_22 ( struct V_18 * V_19 )
{
unsigned long V_24 = V_12 | V_25 |
V_14 | V_13 ;
F_20 ( V_19 ) ;
F_12 ( V_26 , V_20 + V_11 ) ;
F_12 ( V_24 , V_20 + V_7 ) ;
return 0 ;
}
static int F_23 ( unsigned long V_27 ,
struct V_18 * V_19 )
{
unsigned long V_24 = V_12 | V_25 |
V_28 | V_13 ;
F_12 ( V_27 , V_20 + V_11 ) ;
F_12 ( V_24 , V_20 + V_7 ) ;
return 0 ;
}
int T_1 F_24 ( void T_4 * V_6 , unsigned int V_16 , struct V_1 * V_1 , const char * V_8 )
{
struct V_18 * V_19 = & V_29 ;
long V_2 ;
if ( ! V_1 )
V_1 = F_14 ( L_4 , V_8 ) ;
if ( F_15 ( V_1 ) ) {
F_3 ( L_6 , V_8 ,
( int ) F_16 ( V_1 ) ) ;
return F_16 ( V_1 ) ;
}
V_2 = F_1 ( V_1 ) ;
if ( V_2 < 0 )
return - V_10 ;
V_20 = V_6 ;
V_26 = F_25 ( V_2 , V_30 ) ;
V_19 -> V_8 = V_8 ;
V_19 -> V_16 = V_16 ;
V_19 -> V_31 = V_32 ;
F_12 ( 0 , V_6 + V_7 ) ;
F_26 ( V_16 , & V_33 ) ;
F_27 ( V_19 , V_2 , 0xf , 0xffffffff ) ;
return 0 ;
}
static int T_1 F_28 ( struct V_34 * V_35 )
{
static bool V_36 = false ;
void T_4 * V_6 ;
int V_16 , V_37 = - V_10 ;
T_6 V_38 = 0 ;
struct V_1 * V_39 , * V_40 ;
const char * V_8 = F_29 ( V_35 , L_7 , NULL ) ;
V_6 = F_30 ( V_35 , 0 ) ;
if ( ! V_6 )
return - V_41 ;
F_12 ( 0 , V_6 + V_7 ) ;
F_12 ( 0 , V_6 + V_42 + V_7 ) ;
if ( V_36 || ! F_31 ( V_35 ) ) {
V_37 = - V_10 ;
goto V_3;
}
V_39 = F_32 ( V_35 , 0 ) ;
if ( F_15 ( V_39 ) )
V_39 = NULL ;
if ( F_33 ( V_35 , L_8 , L_9 ) == 3 ) {
V_40 = F_32 ( V_35 , 1 ) ;
if ( F_15 ( V_40 ) ) {
F_3 ( L_6 , V_35 -> V_8 ,
( int ) F_16 ( V_40 ) ) ;
V_40 = NULL ;
}
} else
V_40 = V_39 ;
V_16 = F_34 ( V_35 , 0 ) ;
if ( V_16 <= 0 )
goto V_3;
F_35 ( V_35 , L_10 , & V_38 ) ;
if ( V_38 == 2 ) {
V_37 = F_24 ( V_6 + V_42 , V_16 , V_40 , V_8 ) ;
if ( V_37 )
goto V_3;
V_37 = F_13 ( V_6 , V_8 , V_39 , 1 ) ;
if ( V_37 )
goto V_3;
} else {
V_37 = F_24 ( V_6 , V_16 , V_39 , V_8 ) ;
if ( V_37 )
goto V_3;
V_37 = F_13 ( V_6 + V_42 ,
V_8 , V_40 , 1 ) ;
if ( V_37 )
goto V_3;
}
V_36 = true ;
return 0 ;
V_3:
F_36 ( V_6 ) ;
return V_37 ;
}
static int T_1 F_37 ( struct V_34 * V_35 )
{
static int V_43 = 0 ;
void T_4 * V_6 ;
int V_16 , V_37 = - V_10 ;
const char * V_8 = F_29 ( V_35 , L_7 , NULL ) ;
struct V_1 * V_1 ;
V_6 = F_30 ( V_35 , 0 ) ;
if ( ! V_6 ) {
F_3 ( L_11 ) ;
return - V_41 ;
}
V_1 = F_32 ( V_35 , 0 ) ;
if ( F_15 ( V_1 ) ) {
F_3 ( L_12 ) ;
return F_16 ( V_1 ) ;
}
F_12 ( 0 , V_6 + V_7 ) ;
if ( V_43 == 2 || ! F_31 ( V_35 ) )
goto V_3;
if ( ! V_43 ) {
V_37 = F_13 ( V_6 , V_8 , V_1 , 0 ) ;
if ( V_37 )
goto V_3;
} else {
V_16 = F_34 ( V_35 , 0 ) ;
if ( V_16 <= 0 )
goto V_3;
V_37 = F_24 ( V_6 , V_16 , V_1 , V_8 ) ;
if ( V_37 )
goto V_3;
}
V_43 ++ ;
return 0 ;
V_3:
F_36 ( V_6 ) ;
return V_37 ;
}
