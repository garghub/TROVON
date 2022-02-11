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
void T_1 F_13 ( void T_4 * V_6 ,
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
return;
}
}
V_2 = F_1 ( V_1 ) ;
if ( V_2 < 0 )
return;
F_12 ( 0 , V_6 + V_7 ) ;
F_12 ( 0xffffffff , V_6 + V_10 ) ;
F_12 ( 0xffffffff , V_6 + V_5 ) ;
F_12 ( V_11 | V_12 | V_13 ,
V_6 + V_7 ) ;
F_17 ( V_6 + V_5 , V_8 ,
V_2 , 200 , 32 , V_14 ) ;
if ( V_9 ) {
V_4 = V_6 ;
F_18 ( F_9 , 32 , V_2 ) ;
}
}
static T_5 F_19 ( int V_15 , void * V_16 )
{
struct V_17 * V_18 = V_16 ;
F_12 ( 1 , V_19 + V_20 ) ;
V_18 -> V_21 ( V_18 ) ;
return V_22 ;
}
static inline void F_20 ( struct V_17 * V_18 )
{
F_12 ( 0 , V_19 + V_7 ) ;
}
static int F_21 ( struct V_17 * V_18 )
{
F_20 ( V_18 ) ;
return 0 ;
}
static int F_22 ( struct V_17 * V_18 )
{
unsigned long V_23 = V_11 | V_24 |
V_13 | V_12 ;
F_20 ( V_18 ) ;
F_12 ( V_25 , V_19 + V_10 ) ;
F_12 ( V_23 , V_19 + V_7 ) ;
return 0 ;
}
static int F_23 ( unsigned long V_26 ,
struct V_17 * V_18 )
{
unsigned long V_23 = V_11 | V_24 |
V_27 | V_12 ;
F_12 ( V_26 , V_19 + V_10 ) ;
F_12 ( V_23 , V_19 + V_7 ) ;
return 0 ;
}
void T_1 F_24 ( void T_4 * V_6 , unsigned int V_15 , struct V_1 * V_1 , const char * V_8 )
{
struct V_17 * V_18 = & V_28 ;
long V_2 ;
if ( ! V_1 )
V_1 = F_14 ( L_4 , V_8 ) ;
if ( F_15 ( V_1 ) ) {
F_3 ( L_6 , V_8 ,
( int ) F_16 ( V_1 ) ) ;
return;
}
V_2 = F_1 ( V_1 ) ;
if ( V_2 < 0 )
return;
V_19 = V_6 ;
V_25 = F_25 ( V_2 , V_29 ) ;
V_18 -> V_8 = V_8 ;
V_18 -> V_15 = V_15 ;
V_18 -> V_30 = V_31 ;
F_12 ( 0 , V_6 + V_7 ) ;
F_26 ( V_15 , & V_32 ) ;
F_27 ( V_18 , V_2 , 0xf , 0xffffffff ) ;
}
static void T_1 F_28 ( struct V_33 * V_34 )
{
static bool V_35 = false ;
void T_4 * V_6 ;
int V_15 ;
T_6 V_36 = 0 ;
struct V_1 * V_37 , * V_38 ;
const char * V_8 = F_29 ( V_34 , L_7 , NULL ) ;
V_6 = F_30 ( V_34 , 0 ) ;
if ( F_31 ( ! V_6 ) )
return;
F_12 ( 0 , V_6 + V_7 ) ;
F_12 ( 0 , V_6 + V_39 + V_7 ) ;
if ( V_35 || ! F_32 ( V_34 ) )
goto V_3;
V_37 = F_33 ( V_34 , 0 ) ;
if ( F_15 ( V_37 ) )
V_37 = NULL ;
if ( F_34 ( V_34 , L_8 , L_9 ) == 3 ) {
V_38 = F_33 ( V_34 , 1 ) ;
if ( F_15 ( V_38 ) ) {
F_3 ( L_6 , V_34 -> V_8 ,
( int ) F_16 ( V_38 ) ) ;
V_38 = NULL ;
}
} else
V_38 = V_37 ;
V_15 = F_35 ( V_34 , 0 ) ;
if ( V_15 <= 0 )
goto V_3;
F_36 ( V_34 , L_10 , & V_36 ) ;
if ( V_36 == 2 ) {
F_24 ( V_6 + V_39 , V_15 , V_38 , V_8 ) ;
F_13 ( V_6 , V_8 , V_37 , 1 ) ;
} else {
F_24 ( V_6 , V_15 , V_37 , V_8 ) ;
F_13 ( V_6 + V_39 ,
V_8 , V_38 , 1 ) ;
}
V_35 = true ;
return;
V_3:
F_37 ( V_6 ) ;
}
static void T_1 F_38 ( struct V_33 * V_34 )
{
static int V_40 = 0 ;
void T_4 * V_6 ;
int V_15 ;
const char * V_8 = F_29 ( V_34 , L_7 , NULL ) ;
struct V_1 * V_1 ;
V_6 = F_30 ( V_34 , 0 ) ;
if ( F_31 ( ! V_6 ) )
return;
V_1 = F_33 ( V_34 , 0 ) ;
if ( F_31 ( F_15 ( V_1 ) ) )
return;
F_12 ( 0 , V_6 + V_7 ) ;
if ( V_40 == 2 || ! F_32 ( V_34 ) )
goto V_3;
if ( ! V_40 )
F_13 ( V_6 , V_8 , V_1 , 0 ) ;
else {
V_15 = F_35 ( V_34 , 0 ) ;
if ( V_15 <= 0 )
goto V_3;
F_24 ( V_6 , V_15 , V_1 , V_8 ) ;
}
V_40 ++ ;
return;
V_3:
F_37 ( V_6 ) ;
}
