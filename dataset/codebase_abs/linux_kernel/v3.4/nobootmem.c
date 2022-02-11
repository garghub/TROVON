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
V_6 = F_3 ( V_7 ) ;
memset ( V_6 , 0 , V_2 ) ;
F_4 ( V_7 , V_2 ) ;
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
unsigned long V_14 , V_15 , V_16 ;
int V_17 = F_14 ( V_18 ) ;
V_15 = ( V_13 + ( V_18 - 1 ) ) & ~ ( V_18 - 1 ) ;
V_16 = V_11 & ~ ( V_18 - 1 ) ;
if ( V_16 <= V_15 ) {
for ( V_14 = V_13 ; V_14 < V_11 ; V_14 ++ )
F_11 ( F_12 ( V_14 ) , 0 ) ;
return;
}
for ( V_14 = V_13 ; V_14 < V_15 ; V_14 ++ )
F_11 ( F_12 ( V_14 ) , 0 ) ;
for ( V_14 = V_15 ; V_14 < V_16 ; V_14 += V_18 )
F_11 ( F_12 ( V_14 ) , V_17 ) ;
for ( V_14 = V_16 ; V_14 < V_11 ; V_14 ++ )
F_11 ( F_12 ( V_14 ) , 0 ) ;
}
unsigned long T_1 F_15 ( int V_19 )
{
unsigned long V_20 = 0 ;
T_3 V_13 , V_11 ;
T_2 V_14 ;
F_16 () ;
F_17 (i, MAX_NUMNODES, &start, &end, NULL) {
unsigned long V_21 = F_9 ( V_13 ) ;
unsigned long V_22 = F_18 (unsigned long,
PFN_DOWN(end), max_low_pfn) ;
if ( V_21 < V_22 ) {
F_13 ( V_21 , V_22 ) ;
V_20 += V_22 - V_21 ;
}
}
F_19 () ;
return V_20 ;
}
unsigned long T_1 F_20 ( T_4 * V_23 )
{
F_21 ( V_23 ) ;
return 0 ;
}
unsigned long T_1 F_22 ( void )
{
return F_15 ( V_24 ) ;
}
void T_1 F_23 ( T_4 * V_23 , unsigned long V_25 ,
unsigned long V_2 )
{
F_7 ( F_8 ( V_25 ) , V_2 ) ;
F_24 ( V_25 , V_2 ) ;
}
void T_1 F_25 ( unsigned long V_7 , unsigned long V_2 )
{
F_7 ( F_8 ( V_7 ) , V_2 ) ;
F_24 ( V_7 , V_2 ) ;
}
static void * T_1 F_26 ( unsigned long V_2 ,
unsigned long V_3 ,
unsigned long V_4 ,
unsigned long V_5 )
{
void * V_6 ;
if ( F_27 ( F_28 () ) )
return F_29 ( V_2 , V_26 ) ;
V_27:
V_6 = F_1 ( V_24 , V_2 , V_3 , V_4 , V_5 ) ;
if ( V_6 )
return V_6 ;
if ( V_4 != 0 ) {
V_4 = 0 ;
goto V_27;
}
return NULL ;
}
void * T_1 F_30 ( unsigned long V_2 , unsigned long V_3 ,
unsigned long V_4 )
{
unsigned long V_5 = - 1UL ;
return F_26 ( V_2 , V_3 , V_4 , V_5 ) ;
}
static void * T_1 F_31 ( unsigned long V_2 , unsigned long V_3 ,
unsigned long V_4 , unsigned long V_5 )
{
void * V_28 = F_26 ( V_2 , V_3 , V_4 , V_5 ) ;
if ( V_28 )
return V_28 ;
F_32 ( V_29 L_1 , V_2 ) ;
F_33 ( L_2 ) ;
return NULL ;
}
void * T_1 F_34 ( unsigned long V_2 , unsigned long V_3 ,
unsigned long V_4 )
{
unsigned long V_5 = - 1UL ;
return F_31 ( V_2 , V_3 , V_4 , V_5 ) ;
}
void * T_1 F_35 ( T_4 * V_23 , unsigned long V_2 ,
unsigned long V_3 , unsigned long V_4 )
{
void * V_6 ;
if ( F_27 ( F_28 () ) )
return F_36 ( V_2 , V_26 , V_23 -> V_30 ) ;
V_31:
V_6 = F_1 ( V_23 -> V_30 , V_2 , V_3 ,
V_4 , - 1ULL ) ;
if ( V_6 )
return V_6 ;
V_6 = F_1 ( V_24 , V_2 , V_3 ,
V_4 , - 1ULL ) ;
if ( ! V_6 && V_4 ) {
V_4 = 0 ;
goto V_31;
}
return V_6 ;
}
void * T_1 F_37 ( T_4 * V_23 , unsigned long V_2 ,
unsigned long V_3 , unsigned long V_4 )
{
return F_35 ( V_23 , V_2 , V_3 , V_4 ) ;
}
void * T_1 F_38 ( unsigned long V_2 ,
unsigned long V_32 )
{
unsigned long V_33 , V_4 , V_5 ;
V_33 = F_39 ( V_32 ) ;
V_4 = V_33 << V_34 ;
V_5 = F_39 ( V_32 + 1 ) << V_34 ;
return F_1 ( F_40 ( V_33 ) , V_2 ,
V_35 , V_4 , V_5 ) ;
}
void * T_1 F_41 ( T_4 * V_23 , unsigned long V_2 ,
unsigned long V_3 , unsigned long V_4 )
{
void * V_6 ;
if ( F_27 ( F_28 () ) )
return F_36 ( V_2 , V_26 , V_23 -> V_30 ) ;
V_6 = F_1 ( V_23 -> V_30 , V_2 , V_3 ,
V_4 , - 1ULL ) ;
if ( V_6 )
return V_6 ;
return F_30 ( V_2 , V_3 , V_4 ) ;
}
void * T_1 F_42 ( unsigned long V_2 , unsigned long V_3 ,
unsigned long V_4 )
{
return F_31 ( V_2 , V_3 , V_4 , V_36 ) ;
}
void * T_1 F_43 ( T_4 * V_23 , unsigned long V_2 ,
unsigned long V_3 , unsigned long V_4 )
{
void * V_6 ;
if ( F_27 ( F_28 () ) )
return F_36 ( V_2 , V_26 , V_23 -> V_30 ) ;
V_6 = F_1 ( V_23 -> V_30 , V_2 , V_3 ,
V_4 , V_36 ) ;
if ( V_6 )
return V_6 ;
return F_1 ( V_24 , V_2 , V_3 ,
V_4 , V_36 ) ;
}
