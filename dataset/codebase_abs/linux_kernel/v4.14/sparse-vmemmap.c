static void * T_1 F_1 ( int V_1 ,
unsigned long V_2 ,
unsigned long V_3 ,
unsigned long V_4 )
{
return F_2 ( V_2 , V_3 , V_4 ,
V_5 , V_1 ) ;
}
void * T_2 F_3 ( unsigned long V_2 , int V_1 )
{
if ( F_4 () ) {
struct V_6 * V_6 ;
V_6 = F_5 ( V_1 ,
V_7 | V_8 | V_9 ,
F_6 ( V_2 ) ) ;
if ( V_6 )
return F_7 ( V_6 ) ;
return NULL ;
} else
return F_1 ( V_1 , V_2 , V_2 ,
F_8 ( V_10 ) ) ;
}
static void * T_2 F_9 ( unsigned long V_2 , int V_1 )
{
void * V_11 ;
if ( ! V_12 )
return F_3 ( V_2 , V_1 ) ;
V_11 = ( void * ) F_10 ( ( unsigned long ) V_12 , V_2 ) ;
if ( V_11 + V_2 > V_13 )
return F_3 ( V_2 , V_1 ) ;
V_12 = V_11 + V_2 ;
return V_11 ;
}
static unsigned long T_2 F_11 ( struct V_14 * V_15 )
{
return V_15 -> V_16 + V_15 -> V_17 + V_15 -> V_18
+ V_15 -> V_3 ;
}
static unsigned long T_2 F_12 ( struct V_14 * V_15 )
{
unsigned long V_19 = V_15 -> V_18 + V_15 -> V_3 ;
if ( V_15 -> free > V_19 )
return V_15 -> free - V_19 ;
return 0 ;
}
static unsigned long T_2 F_13 ( struct V_14 * V_15 ,
unsigned long V_20 )
{
unsigned long V_21 = F_11 ( V_15 ) ;
unsigned long V_22 ;
V_22 = 1UL << F_14 ( & V_20 , V_23 ) ;
V_22 = F_10 ( V_21 , V_22 ) - V_21 ;
if ( V_20 + V_22 > F_12 ( V_15 ) )
return V_24 ;
V_15 -> V_18 += V_20 ;
V_15 -> V_3 += V_22 ;
return V_21 + V_22 ;
}
static void * T_2 F_15 ( unsigned long V_2 ,
struct V_14 * V_15 )
{
unsigned long V_21 , V_20 ;
void * V_11 ;
if ( V_2 & ~ V_25 ) {
F_16 ( L_1 ,
V_26 , V_2 ) ;
return NULL ;
}
V_20 = V_2 >> V_27 ;
V_21 = F_13 ( V_15 , V_20 ) ;
if ( V_21 < V_24 )
V_11 = F_17 ( F_18 ( V_21 ) ) ;
else
V_11 = NULL ;
F_19 ( L_2 ,
V_26 , V_21 , V_15 -> V_18 , V_15 -> V_3 , V_20 ) ;
return V_11 ;
}
void * T_2 F_20 ( unsigned long V_2 , int V_1 ,
struct V_14 * V_15 )
{
if ( V_15 )
return F_15 ( V_2 , V_15 ) ;
return F_9 ( V_2 , V_1 ) ;
}
void T_2 F_21 ( T_3 * V_28 , int V_1 ,
unsigned long V_29 , unsigned long V_30 )
{
unsigned long V_21 = F_22 ( * V_28 ) ;
int V_31 = F_23 ( V_21 ) ;
if ( F_24 ( V_31 , V_1 ) > V_32 )
F_25 ( L_3 ,
V_29 , V_30 - 1 ) ;
}
T_3 * T_2 F_26 ( T_4 * V_33 , unsigned long V_34 , int V_1 )
{
T_3 * V_28 = F_27 ( V_33 , V_34 ) ;
if ( F_28 ( * V_28 ) ) {
T_3 V_35 ;
void * V_36 = F_9 ( V_37 , V_1 ) ;
if ( ! V_36 )
return NULL ;
V_35 = F_29 ( F_8 ( V_36 ) >> V_27 , V_38 ) ;
F_30 ( & V_39 , V_34 , V_28 , V_35 ) ;
}
return V_28 ;
}
T_4 * T_2 F_31 ( T_5 * V_40 , unsigned long V_34 , int V_1 )
{
T_4 * V_33 = F_32 ( V_40 , V_34 ) ;
if ( F_33 ( * V_33 ) ) {
void * V_36 = F_3 ( V_37 , V_1 ) ;
if ( ! V_36 )
return NULL ;
F_34 ( & V_39 , V_33 , V_36 ) ;
}
return V_33 ;
}
T_5 * T_2 F_35 ( T_6 * V_41 , unsigned long V_34 , int V_1 )
{
T_5 * V_40 = F_36 ( V_41 , V_34 ) ;
if ( F_37 ( * V_40 ) ) {
void * V_36 = F_3 ( V_37 , V_1 ) ;
if ( ! V_36 )
return NULL ;
F_38 ( & V_39 , V_40 , V_36 ) ;
}
return V_40 ;
}
T_6 * T_2 F_39 ( T_7 * V_42 , unsigned long V_34 , int V_1 )
{
T_6 * V_41 = F_40 ( V_42 , V_34 ) ;
if ( F_41 ( * V_41 ) ) {
void * V_36 = F_3 ( V_37 , V_1 ) ;
if ( ! V_36 )
return NULL ;
F_42 ( & V_39 , V_41 , V_36 ) ;
}
return V_41 ;
}
T_7 * T_2 F_43 ( unsigned long V_34 , int V_1 )
{
T_7 * V_42 = F_44 ( V_34 ) ;
if ( F_45 ( * V_42 ) ) {
void * V_36 = F_3 ( V_37 , V_1 ) ;
if ( ! V_36 )
return NULL ;
F_46 ( & V_39 , V_42 , V_36 ) ;
}
return V_42 ;
}
int T_2 F_47 ( unsigned long V_29 ,
unsigned long V_30 , int V_1 )
{
unsigned long V_34 = V_29 ;
T_7 * V_42 ;
T_6 * V_41 ;
T_5 * V_40 ;
T_4 * V_33 ;
T_3 * V_28 ;
for (; V_34 < V_30 ; V_34 += V_37 ) {
V_42 = F_43 ( V_34 , V_1 ) ;
if ( ! V_42 )
return - V_43 ;
V_41 = F_39 ( V_42 , V_34 , V_1 ) ;
if ( ! V_41 )
return - V_43 ;
V_40 = F_35 ( V_41 , V_34 , V_1 ) ;
if ( ! V_40 )
return - V_43 ;
V_33 = F_31 ( V_40 , V_34 , V_1 ) ;
if ( ! V_33 )
return - V_43 ;
V_28 = F_26 ( V_33 , V_34 , V_1 ) ;
if ( ! V_28 )
return - V_43 ;
F_21 ( V_28 , V_1 , V_34 , V_34 + V_37 ) ;
}
return 0 ;
}
struct V_6 * T_2 F_48 ( unsigned long V_44 , int V_45 )
{
unsigned long V_29 ;
unsigned long V_30 ;
struct V_6 * V_46 ;
V_46 = F_49 ( V_44 * V_47 ) ;
V_29 = ( unsigned long ) V_46 ;
V_30 = ( unsigned long ) ( V_46 + V_47 ) ;
if ( F_50 ( V_29 , V_30 , V_45 ) )
return NULL ;
return V_46 ;
}
void T_8 F_51 ( struct V_6 * * V_48 ,
unsigned long V_49 ,
unsigned long V_50 ,
unsigned long V_51 , int V_52 )
{
unsigned long V_44 ;
unsigned long V_2 = sizeof( struct V_6 ) * V_47 ;
void * V_53 ;
V_2 = F_10 ( V_2 , V_54 ) ;
V_53 = F_1 ( V_52 , V_2 * V_51 ,
V_54 , F_8 ( V_10 ) ) ;
if ( V_53 ) {
V_12 = V_53 ;
V_13 = V_53 + V_2 * V_51 ;
}
for ( V_44 = V_49 ; V_44 < V_50 ; V_44 ++ ) {
struct V_55 * V_56 ;
if ( ! F_52 ( V_44 ) )
continue;
V_48 [ V_44 ] = F_48 ( V_44 , V_52 ) ;
if ( V_48 [ V_44 ] )
continue;
V_56 = F_53 ( V_44 ) ;
F_54 ( L_4 ,
V_26 ) ;
V_56 -> V_57 = 0 ;
}
if ( V_53 ) {
F_55 ( F_8 ( V_12 ) ,
V_13 - V_12 ) ;
V_12 = NULL ;
V_13 = NULL ;
}
}
