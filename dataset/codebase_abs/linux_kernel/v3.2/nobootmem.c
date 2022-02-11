static void * T_1 F_1 ( int V_1 , T_2 V_2 , T_2 V_3 ,
T_2 V_4 , T_2 V_5 )
{
void * V_6 ;
T_2 V_7 ;
if ( V_5 > V_8 . V_9 )
V_5 = V_8 . V_9 ;
V_7 = F_2 ( V_1 , V_2 , V_3 , V_4 , V_5 ) ;
if ( V_7 == V_10 )
return NULL ;
V_6 = F_3 ( V_7 ) ;
memset ( V_6 , 0 , V_2 ) ;
F_4 ( V_7 , V_7 + V_2 , L_1 ) ;
F_5 ( V_6 , V_2 , 0 , 0 ) ;
return V_6 ;
}
void T_1 F_6 ( unsigned long V_7 , unsigned long V_2 )
{
unsigned long V_11 , V_12 ;
F_7 ( F_8 ( V_7 ) , V_2 ) ;
V_11 = F_9 ( V_7 ) ;
V_12 = F_10 ( V_7 + V_2 ) ;
for (; V_11 < V_12 ; V_11 ++ ) {
F_11 ( F_12 ( V_11 ) , 0 ) ;
V_13 ++ ;
}
}
static void T_1 F_13 ( unsigned long V_14 , unsigned long V_12 )
{
int V_15 ;
unsigned long V_16 , V_17 ;
int V_18 = F_14 ( V_19 ) ;
V_16 = ( V_14 + ( V_19 - 1 ) ) & ~ ( V_19 - 1 ) ;
V_17 = V_12 & ~ ( V_19 - 1 ) ;
if ( V_17 <= V_16 ) {
for ( V_15 = V_14 ; V_15 < V_12 ; V_15 ++ )
F_11 ( F_12 ( V_15 ) , 0 ) ;
return;
}
for ( V_15 = V_14 ; V_15 < V_16 ; V_15 ++ )
F_11 ( F_12 ( V_15 ) , 0 ) ;
for ( V_15 = V_16 ; V_15 < V_17 ; V_15 += V_19 )
F_11 ( F_12 ( V_15 ) , V_18 ) ;
for ( V_15 = V_17 ; V_15 < V_12 ; V_15 ++ )
F_11 ( F_12 ( V_15 ) , 0 ) ;
}
unsigned long T_1 F_15 ( int V_20 )
{
int V_15 ;
T_2 V_14 , V_12 ;
unsigned long V_21 = 0 ;
struct V_22 * V_22 = NULL ;
int V_23 ;
V_23 = F_16 ( & V_22 , V_20 ) ;
for ( V_15 = 0 ; V_15 < V_23 ; V_15 ++ ) {
V_14 = V_22 [ V_15 ] . V_14 ;
V_12 = V_22 [ V_15 ] . V_12 ;
V_21 += V_12 - V_14 ;
F_13 ( V_14 , V_12 ) ;
}
return V_21 ;
}
unsigned long T_1 F_17 ( T_3 * V_24 )
{
F_18 ( V_24 ) ;
return 0 ;
}
unsigned long T_1 F_19 ( void )
{
return F_15 ( V_25 ) ;
}
void T_1 F_20 ( T_3 * V_24 , unsigned long V_26 ,
unsigned long V_2 )
{
F_7 ( F_8 ( V_26 ) , V_2 ) ;
F_21 ( V_26 , V_26 + V_2 ) ;
}
void T_1 F_22 ( unsigned long V_7 , unsigned long V_2 )
{
F_7 ( F_8 ( V_7 ) , V_2 ) ;
F_21 ( V_7 , V_7 + V_2 ) ;
}
static void * T_1 F_23 ( unsigned long V_2 ,
unsigned long V_3 ,
unsigned long V_4 ,
unsigned long V_5 )
{
void * V_6 ;
if ( F_24 ( F_25 () ) )
return F_26 ( V_2 , V_27 ) ;
V_28:
V_6 = F_1 ( V_25 , V_2 , V_3 , V_4 , V_5 ) ;
if ( V_6 )
return V_6 ;
if ( V_4 != 0 ) {
V_4 = 0 ;
goto V_28;
}
return NULL ;
}
void * T_1 F_27 ( unsigned long V_2 , unsigned long V_3 ,
unsigned long V_4 )
{
unsigned long V_5 = - 1UL ;
return F_23 ( V_2 , V_3 , V_4 , V_5 ) ;
}
static void * T_1 F_28 ( unsigned long V_2 , unsigned long V_3 ,
unsigned long V_4 , unsigned long V_5 )
{
void * V_29 = F_23 ( V_2 , V_3 , V_4 , V_5 ) ;
if ( V_29 )
return V_29 ;
F_29 ( V_30 L_2 , V_2 ) ;
F_30 ( L_3 ) ;
return NULL ;
}
void * T_1 F_31 ( unsigned long V_2 , unsigned long V_3 ,
unsigned long V_4 )
{
unsigned long V_5 = - 1UL ;
return F_28 ( V_2 , V_3 , V_4 , V_5 ) ;
}
void * T_1 F_32 ( T_3 * V_24 , unsigned long V_2 ,
unsigned long V_3 , unsigned long V_4 )
{
void * V_6 ;
if ( F_24 ( F_25 () ) )
return F_33 ( V_2 , V_27 , V_24 -> V_31 ) ;
V_6 = F_1 ( V_24 -> V_31 , V_2 , V_3 ,
V_4 , - 1ULL ) ;
if ( V_6 )
return V_6 ;
return F_1 ( V_25 , V_2 , V_3 ,
V_4 , - 1ULL ) ;
}
void * T_1 F_34 ( T_3 * V_24 , unsigned long V_2 ,
unsigned long V_3 , unsigned long V_4 )
{
return F_32 ( V_24 , V_2 , V_3 , V_4 ) ;
}
void * T_1 F_35 ( unsigned long V_2 ,
unsigned long V_32 )
{
unsigned long V_33 , V_4 , V_5 ;
V_33 = F_36 ( V_32 ) ;
V_4 = V_33 << V_34 ;
V_5 = F_36 ( V_32 + 1 ) << V_34 ;
return F_1 ( F_37 ( V_33 ) , V_2 ,
V_35 , V_4 , V_5 ) ;
}
void * T_1 F_38 ( T_3 * V_24 , unsigned long V_2 ,
unsigned long V_3 , unsigned long V_4 )
{
void * V_6 ;
if ( F_24 ( F_25 () ) )
return F_33 ( V_2 , V_27 , V_24 -> V_31 ) ;
V_6 = F_1 ( V_24 -> V_31 , V_2 , V_3 ,
V_4 , - 1ULL ) ;
if ( V_6 )
return V_6 ;
return F_27 ( V_2 , V_3 , V_4 ) ;
}
void * T_1 F_39 ( unsigned long V_2 , unsigned long V_3 ,
unsigned long V_4 )
{
return F_28 ( V_2 , V_3 , V_4 , V_36 ) ;
}
void * T_1 F_40 ( T_3 * V_24 , unsigned long V_2 ,
unsigned long V_3 , unsigned long V_4 )
{
void * V_6 ;
if ( F_24 ( F_25 () ) )
return F_33 ( V_2 , V_27 , V_24 -> V_31 ) ;
V_6 = F_1 ( V_24 -> V_31 , V_2 , V_3 ,
V_4 , V_36 ) ;
if ( V_6 )
return V_6 ;
return F_1 ( V_25 , V_2 , V_3 ,
V_4 , V_36 ) ;
}
