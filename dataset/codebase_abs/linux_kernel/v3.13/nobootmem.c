static void * T_1 F_1 ( int V_1 , T_2 V_2 , T_2 V_3 ,
T_2 V_4 , T_2 V_5 )
{
void * V_6 ;
T_2 V_7 ;
if ( V_5 > V_8 . V_9 )
V_5 = V_8 . V_9 ;
V_7 = F_2 ( V_4 , V_5 , V_2 , V_3 , V_1 ) ;
if ( ! V_7 )
return NULL ;
F_3 ( V_7 , V_2 ) ;
V_6 = F_4 ( V_7 ) ;
memset ( V_6 , 0 , V_2 ) ;
F_5 ( V_6 , V_2 , 0 , 0 ) ;
return V_6 ;
}
void T_1 F_6 ( unsigned long V_7 , unsigned long V_2 )
{
unsigned long V_10 , V_11 ;
F_7 ( F_8 ( V_7 ) , V_2 ) ;
V_10 = F_9 ( V_7 ) ;
V_11 = F_10 ( V_7 + V_2 ) ;
for (; V_10 < V_11 ; V_10 ++ ) {
F_11 ( F_12 ( V_10 ) , 0 ) ;
V_12 ++ ;
}
}
static void T_1 F_13 ( unsigned long V_13 , unsigned long V_11 )
{
int V_14 ;
while ( V_13 < V_11 ) {
V_14 = F_14 ( V_15 - 1UL , F_15 ( V_13 ) ) ;
while ( V_13 + ( 1UL << V_14 ) > V_11 )
V_14 -- ;
F_11 ( F_12 ( V_13 ) , V_14 ) ;
V_13 += ( 1UL << V_14 ) ;
}
}
static unsigned long T_1 F_16 ( T_3 V_13 ,
T_3 V_11 )
{
unsigned long V_16 = F_9 ( V_13 ) ;
unsigned long V_17 = F_17 (unsigned long,
PFN_DOWN(end), max_low_pfn) ;
if ( V_16 > V_17 )
return 0 ;
F_13 ( V_16 , V_17 ) ;
return V_17 - V_16 ;
}
static unsigned long T_1 F_18 ( void )
{
unsigned long V_18 = 0 ;
T_3 V_13 , V_11 , V_2 ;
T_2 V_19 ;
F_19 (i, MAX_NUMNODES, &start, &end, NULL)
V_18 += F_16 ( V_13 , V_11 ) ;
V_2 = F_20 ( & V_13 ) ;
if ( V_2 )
V_18 += F_16 ( V_13 , V_13 + V_2 ) ;
return V_18 ;
}
static inline void T_1 F_21 ( T_4 * V_20 )
{
struct V_21 * V_22 ;
if ( V_23 )
return;
for ( V_22 = V_20 -> V_24 ; V_22 < V_20 -> V_24 + V_25 ; V_22 ++ )
V_22 -> V_26 = 0 ;
}
void T_1 F_22 ( void )
{
struct V_27 * V_20 ;
F_23 (pgdat)
F_21 ( V_20 ) ;
V_23 = 1 ;
}
unsigned long T_1 F_24 ( void )
{
unsigned long V_28 ;
F_22 () ;
V_28 = F_18 () ;
V_12 += V_28 ;
return V_28 ;
}
void T_1 F_25 ( T_4 * V_20 , unsigned long V_29 ,
unsigned long V_2 )
{
F_7 ( F_8 ( V_29 ) , V_2 ) ;
F_26 ( V_29 , V_2 ) ;
}
void T_1 F_27 ( unsigned long V_7 , unsigned long V_2 )
{
F_7 ( F_8 ( V_7 ) , V_2 ) ;
F_26 ( V_7 , V_2 ) ;
}
static void * T_1 F_28 ( unsigned long V_2 ,
unsigned long V_3 ,
unsigned long V_4 ,
unsigned long V_5 )
{
void * V_6 ;
if ( F_29 ( F_30 () ) )
return F_31 ( V_2 , V_30 ) ;
V_31:
V_6 = F_1 ( V_32 , V_2 , V_3 , V_4 , V_5 ) ;
if ( V_6 )
return V_6 ;
if ( V_4 != 0 ) {
V_4 = 0 ;
goto V_31;
}
return NULL ;
}
void * T_1 F_32 ( unsigned long V_2 , unsigned long V_3 ,
unsigned long V_4 )
{
unsigned long V_5 = - 1UL ;
return F_28 ( V_2 , V_3 , V_4 , V_5 ) ;
}
static void * T_1 F_33 ( unsigned long V_2 , unsigned long V_3 ,
unsigned long V_4 , unsigned long V_5 )
{
void * V_33 = F_28 ( V_2 , V_3 , V_4 , V_5 ) ;
if ( V_33 )
return V_33 ;
F_34 ( V_34 L_1 , V_2 ) ;
F_35 ( L_2 ) ;
return NULL ;
}
void * T_1 F_36 ( unsigned long V_2 , unsigned long V_3 ,
unsigned long V_4 )
{
unsigned long V_5 = - 1UL ;
return F_33 ( V_2 , V_3 , V_4 , V_5 ) ;
}
void * T_1 F_37 ( T_4 * V_20 ,
unsigned long V_2 ,
unsigned long V_3 ,
unsigned long V_4 ,
unsigned long V_5 )
{
void * V_6 ;
V_35:
V_6 = F_1 ( V_20 -> V_36 , V_2 , V_3 ,
V_4 , V_5 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_1 ( V_32 , V_2 , V_3 ,
V_4 , V_5 ) ;
if ( V_6 )
return V_6 ;
if ( V_4 ) {
V_4 = 0 ;
goto V_35;
}
return NULL ;
}
void * T_1 F_38 ( T_4 * V_20 , unsigned long V_2 ,
unsigned long V_3 , unsigned long V_4 )
{
if ( F_29 ( F_30 () ) )
return F_39 ( V_2 , V_30 , V_20 -> V_36 ) ;
return F_37 ( V_20 , V_2 , V_3 , V_4 , 0 ) ;
}
void * T_1 F_40 ( T_4 * V_20 , unsigned long V_2 ,
unsigned long V_3 , unsigned long V_4 ,
unsigned long V_5 )
{
void * V_6 ;
V_6 = F_37 ( V_20 , V_2 , V_3 , V_4 , V_5 ) ;
if ( V_6 )
return V_6 ;
F_34 ( V_34 L_1 , V_2 ) ;
F_35 ( L_2 ) ;
return NULL ;
}
void * T_1 F_41 ( T_4 * V_20 , unsigned long V_2 ,
unsigned long V_3 , unsigned long V_4 )
{
if ( F_29 ( F_30 () ) )
return F_39 ( V_2 , V_30 , V_20 -> V_36 ) ;
return F_40 ( V_20 , V_2 , V_3 , V_4 , 0 ) ;
}
void * T_1 F_42 ( T_4 * V_20 , unsigned long V_2 ,
unsigned long V_3 , unsigned long V_4 )
{
return F_41 ( V_20 , V_2 , V_3 , V_4 ) ;
}
void * T_1 F_43 ( unsigned long V_2 , unsigned long V_3 ,
unsigned long V_4 )
{
return F_33 ( V_2 , V_3 , V_4 , V_37 ) ;
}
void * T_1 F_44 ( unsigned long V_2 ,
unsigned long V_3 ,
unsigned long V_4 )
{
return F_28 ( V_2 , V_3 , V_4 ,
V_37 ) ;
}
void * T_1 F_45 ( T_4 * V_20 , unsigned long V_2 ,
unsigned long V_3 , unsigned long V_4 )
{
if ( F_29 ( F_30 () ) )
return F_39 ( V_2 , V_30 , V_20 -> V_36 ) ;
return F_40 ( V_20 , V_2 , V_3 , V_4 ,
V_37 ) ;
}
