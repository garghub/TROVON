static void * T_1 F_1 ( int V_1 , T_2 V_2 , T_2 V_3 ,
T_2 V_4 , T_2 V_5 )
{
void * V_6 ;
T_2 V_7 ;
T_3 V_8 = F_2 () ;
if ( V_5 > V_9 . V_10 )
V_5 = V_9 . V_10 ;
V_11:
V_7 = F_3 ( V_2 , V_3 , V_4 , V_5 , V_1 ,
V_8 ) ;
if ( ! V_7 && ( V_8 & V_12 ) ) {
V_8 &= ~ V_12 ;
F_4 ( L_1 ,
& V_2 ) ;
goto V_11;
}
if ( ! V_7 )
return NULL ;
if ( F_5 ( V_7 , V_2 ) )
return NULL ;
V_6 = F_6 ( V_7 ) ;
memset ( V_6 , 0 , V_2 ) ;
F_7 ( V_6 , V_2 , 0 , 0 ) ;
return V_6 ;
}
void T_1 F_8 ( unsigned long V_7 , unsigned long V_2 )
{
unsigned long V_13 , V_14 ;
F_9 ( F_10 ( V_7 ) , V_2 ) ;
V_13 = F_11 ( V_7 ) ;
V_14 = F_12 ( V_7 + V_2 ) ;
for (; V_13 < V_14 ; V_13 ++ ) {
F_13 ( F_14 ( V_13 ) , V_13 , 0 ) ;
V_15 ++ ;
}
}
static void T_1 F_15 ( unsigned long V_16 , unsigned long V_14 )
{
int V_17 ;
while ( V_16 < V_14 ) {
V_17 = F_16 ( V_18 - 1UL , F_17 ( V_16 ) ) ;
while ( V_16 + ( 1UL << V_17 ) > V_14 )
V_17 -- ;
F_13 ( F_14 ( V_16 ) , V_16 , V_17 ) ;
V_16 += ( 1UL << V_17 ) ;
}
}
static unsigned long T_1 F_18 ( T_4 V_16 ,
T_4 V_14 )
{
unsigned long V_19 = F_11 ( V_16 ) ;
unsigned long V_20 = F_19 (unsigned long,
PFN_DOWN(end), max_low_pfn) ;
if ( V_19 > V_20 )
return 0 ;
F_15 ( V_19 , V_20 ) ;
return V_20 - V_19 ;
}
static unsigned long T_1 F_20 ( void )
{
unsigned long V_21 = 0 ;
T_4 V_16 , V_14 ;
T_2 V_22 ;
F_21 ( 0 , - 1 ) ;
F_22 (i, &start, &end)
F_23 ( V_16 , V_14 ) ;
F_24 (i, NUMA_NO_NODE, MEMBLOCK_NONE, &start, &end,
NULL)
V_21 += F_18 ( V_16 , V_14 ) ;
#ifdef F_25
{
T_4 V_2 ;
V_2 = F_26 ( & V_16 ) ;
if ( V_2 )
V_21 += F_18 ( V_16 , V_16 + V_2 ) ;
V_2 = F_27 ( & V_16 ) ;
if ( V_2 )
V_21 += F_18 ( V_16 , V_16 + V_2 ) ;
}
#endif
return V_21 ;
}
void F_28 ( T_5 * V_23 )
{
struct V_24 * V_25 ;
for ( V_25 = V_23 -> V_26 ; V_25 < V_23 -> V_26 + V_27 ; V_25 ++ )
V_25 -> V_28 = 0 ;
}
void T_1 F_29 ( void )
{
struct V_29 * V_23 ;
if ( V_30 )
return;
F_30 (pgdat)
F_28 ( V_23 ) ;
V_30 = 1 ;
}
unsigned long T_1 F_31 ( void )
{
unsigned long V_31 ;
F_29 () ;
V_31 = F_20 () ;
V_15 += V_31 ;
return V_31 ;
}
void T_1 F_32 ( T_5 * V_23 , unsigned long V_32 ,
unsigned long V_2 )
{
F_33 ( V_32 , V_2 ) ;
}
void T_1 F_34 ( unsigned long V_7 , unsigned long V_2 )
{
F_33 ( V_7 , V_2 ) ;
}
static void * T_1 F_35 ( unsigned long V_2 ,
unsigned long V_3 ,
unsigned long V_4 ,
unsigned long V_5 )
{
void * V_6 ;
if ( F_36 ( F_37 () ) )
return F_38 ( V_2 , V_33 ) ;
V_34:
V_6 = F_1 ( V_35 , V_2 , V_3 , V_4 , V_5 ) ;
if ( V_6 )
return V_6 ;
if ( V_4 != 0 ) {
V_4 = 0 ;
goto V_34;
}
return NULL ;
}
void * T_1 F_39 ( unsigned long V_2 , unsigned long V_3 ,
unsigned long V_4 )
{
unsigned long V_5 = - 1UL ;
return F_35 ( V_2 , V_3 , V_4 , V_5 ) ;
}
static void * T_1 F_40 ( unsigned long V_2 , unsigned long V_3 ,
unsigned long V_4 , unsigned long V_5 )
{
void * V_36 = F_35 ( V_2 , V_3 , V_4 , V_5 ) ;
if ( V_36 )
return V_36 ;
F_41 ( L_2 , V_2 ) ;
F_42 ( L_3 ) ;
return NULL ;
}
void * T_1 F_43 ( unsigned long V_2 , unsigned long V_3 ,
unsigned long V_4 )
{
unsigned long V_5 = - 1UL ;
return F_40 ( V_2 , V_3 , V_4 , V_5 ) ;
}
void * T_1 F_44 ( T_5 * V_23 ,
unsigned long V_2 ,
unsigned long V_3 ,
unsigned long V_4 ,
unsigned long V_5 )
{
void * V_6 ;
V_11:
V_6 = F_1 ( V_23 -> V_37 , V_2 , V_3 ,
V_4 , V_5 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_1 ( V_35 , V_2 , V_3 ,
V_4 , V_5 ) ;
if ( V_6 )
return V_6 ;
if ( V_4 ) {
V_4 = 0 ;
goto V_11;
}
return NULL ;
}
void * T_1 F_45 ( T_5 * V_23 , unsigned long V_2 ,
unsigned long V_3 , unsigned long V_4 )
{
if ( F_36 ( F_37 () ) )
return F_46 ( V_2 , V_33 , V_23 -> V_37 ) ;
return F_44 ( V_23 , V_2 , V_3 , V_4 , 0 ) ;
}
static void * T_1 F_47 ( T_5 * V_23 , unsigned long V_2 ,
unsigned long V_3 , unsigned long V_4 ,
unsigned long V_5 )
{
void * V_6 ;
V_6 = F_44 ( V_23 , V_2 , V_3 , V_4 , V_5 ) ;
if ( V_6 )
return V_6 ;
F_41 ( L_2 , V_2 ) ;
F_42 ( L_3 ) ;
return NULL ;
}
void * T_1 F_48 ( T_5 * V_23 , unsigned long V_2 ,
unsigned long V_3 , unsigned long V_4 )
{
if ( F_36 ( F_37 () ) )
return F_46 ( V_2 , V_33 , V_23 -> V_37 ) ;
return F_47 ( V_23 , V_2 , V_3 , V_4 , 0 ) ;
}
void * T_1 F_49 ( T_5 * V_23 , unsigned long V_2 ,
unsigned long V_3 , unsigned long V_4 )
{
return F_48 ( V_23 , V_2 , V_3 , V_4 ) ;
}
void * T_1 F_50 ( unsigned long V_2 , unsigned long V_3 ,
unsigned long V_4 )
{
return F_40 ( V_2 , V_3 , V_4 , V_38 ) ;
}
void * T_1 F_51 ( unsigned long V_2 ,
unsigned long V_3 ,
unsigned long V_4 )
{
return F_35 ( V_2 , V_3 , V_4 ,
V_38 ) ;
}
void * T_1 F_52 ( T_5 * V_23 , unsigned long V_2 ,
unsigned long V_3 , unsigned long V_4 )
{
if ( F_36 ( F_37 () ) )
return F_46 ( V_2 , V_33 , V_23 -> V_37 ) ;
return F_47 ( V_23 , V_2 , V_3 , V_4 ,
V_38 ) ;
}
