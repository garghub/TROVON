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
if ( F_5 ( V_1 , V_7 ) )
V_6 = F_6 (
V_1 , V_8 | V_9 | V_10 ,
F_7 ( V_2 ) ) ;
else
V_6 = F_8 (
V_8 | V_9 | V_10 ,
F_7 ( V_2 ) ) ;
if ( V_6 )
return F_9 ( V_6 ) ;
return NULL ;
} else
return F_1 ( V_1 , V_2 , V_2 ,
F_10 ( V_11 ) ) ;
}
static void * T_2 F_11 ( unsigned long V_2 , int V_1 )
{
void * V_12 ;
if ( ! V_13 )
return F_3 ( V_2 , V_1 ) ;
V_12 = ( void * ) F_12 ( ( unsigned long ) V_13 , V_2 ) ;
if ( V_12 + V_2 > V_14 )
return F_3 ( V_2 , V_1 ) ;
V_13 = V_12 + V_2 ;
return V_12 ;
}
static unsigned long T_2 F_13 ( struct V_15 * V_16 )
{
return V_16 -> V_17 + V_16 -> V_18 + V_16 -> V_19
+ V_16 -> V_3 ;
}
static unsigned long T_2 F_14 ( struct V_15 * V_16 )
{
unsigned long V_20 = V_16 -> V_19 + V_16 -> V_3 ;
if ( V_16 -> free > V_20 )
return V_16 -> free - V_20 ;
return 0 ;
}
static unsigned long T_2 F_15 ( struct V_15 * V_16 ,
unsigned long V_21 )
{
unsigned long V_22 = F_13 ( V_16 ) ;
unsigned long V_23 ;
V_23 = 1UL << F_16 ( & V_21 , V_24 ) ;
V_23 = F_12 ( V_22 , V_23 ) - V_22 ;
if ( V_21 + V_23 > F_14 ( V_16 ) )
return V_25 ;
V_16 -> V_19 += V_21 ;
V_16 -> V_3 += V_23 ;
return V_22 + V_23 ;
}
static void * T_2 F_17 ( unsigned long V_2 ,
struct V_15 * V_16 )
{
unsigned long V_22 , V_21 ;
void * V_12 ;
if ( V_2 & ~ V_26 ) {
F_18 ( L_1 ,
V_27 , V_2 ) ;
return NULL ;
}
V_21 = V_2 >> V_28 ;
V_22 = F_15 ( V_16 , V_21 ) ;
if ( V_22 < V_25 )
V_12 = F_19 ( F_20 ( V_22 ) ) ;
else
V_12 = NULL ;
F_21 ( L_2 ,
V_27 , V_22 , V_16 -> V_19 , V_16 -> V_3 , V_21 ) ;
return V_12 ;
}
void * T_2 F_22 ( unsigned long V_2 , int V_1 ,
struct V_15 * V_16 )
{
if ( V_16 )
return F_17 ( V_2 , V_16 ) ;
return F_11 ( V_2 , V_1 ) ;
}
void T_2 F_23 ( T_3 * V_29 , int V_1 ,
unsigned long V_30 , unsigned long V_31 )
{
unsigned long V_22 = F_24 ( * V_29 ) ;
int V_32 = F_25 ( V_22 ) ;
if ( F_26 ( V_32 , V_1 ) > V_33 )
F_27 ( V_34 L_3
L_4 , V_30 , V_31 - 1 ) ;
}
T_3 * T_2 F_28 ( T_4 * V_35 , unsigned long V_36 , int V_1 )
{
T_3 * V_29 = F_29 ( V_35 , V_36 ) ;
if ( F_30 ( * V_29 ) ) {
T_3 V_37 ;
void * V_38 = F_11 ( V_39 , V_1 ) ;
if ( ! V_38 )
return NULL ;
V_37 = F_31 ( F_10 ( V_38 ) >> V_28 , V_40 ) ;
F_32 ( & V_41 , V_36 , V_29 , V_37 ) ;
}
return V_29 ;
}
T_4 * T_2 F_33 ( T_5 * V_42 , unsigned long V_36 , int V_1 )
{
T_4 * V_35 = F_34 ( V_42 , V_36 ) ;
if ( F_35 ( * V_35 ) ) {
void * V_38 = F_3 ( V_39 , V_1 ) ;
if ( ! V_38 )
return NULL ;
F_36 ( & V_41 , V_35 , V_38 ) ;
}
return V_35 ;
}
T_5 * T_2 F_37 ( T_6 * V_43 , unsigned long V_36 , int V_1 )
{
T_5 * V_42 = F_38 ( V_43 , V_36 ) ;
if ( F_39 ( * V_42 ) ) {
void * V_38 = F_3 ( V_39 , V_1 ) ;
if ( ! V_38 )
return NULL ;
F_40 ( & V_41 , V_42 , V_38 ) ;
}
return V_42 ;
}
T_6 * T_2 F_41 ( unsigned long V_36 , int V_1 )
{
T_6 * V_43 = F_42 ( V_36 ) ;
if ( F_43 ( * V_43 ) ) {
void * V_38 = F_3 ( V_39 , V_1 ) ;
if ( ! V_38 )
return NULL ;
F_44 ( & V_41 , V_43 , V_38 ) ;
}
return V_43 ;
}
int T_2 F_45 ( unsigned long V_30 ,
unsigned long V_31 , int V_1 )
{
unsigned long V_36 = V_30 ;
T_6 * V_43 ;
T_5 * V_42 ;
T_4 * V_35 ;
T_3 * V_29 ;
for (; V_36 < V_31 ; V_36 += V_39 ) {
V_43 = F_41 ( V_36 , V_1 ) ;
if ( ! V_43 )
return - V_44 ;
V_42 = F_37 ( V_43 , V_36 , V_1 ) ;
if ( ! V_42 )
return - V_44 ;
V_35 = F_33 ( V_42 , V_36 , V_1 ) ;
if ( ! V_35 )
return - V_44 ;
V_29 = F_28 ( V_35 , V_36 , V_1 ) ;
if ( ! V_29 )
return - V_44 ;
F_23 ( V_29 , V_1 , V_36 , V_36 + V_39 ) ;
}
return 0 ;
}
struct V_6 * T_2 F_46 ( unsigned long V_45 , int V_46 )
{
unsigned long V_30 ;
unsigned long V_31 ;
struct V_6 * V_47 ;
V_47 = F_47 ( V_45 * V_48 ) ;
V_30 = ( unsigned long ) V_47 ;
V_31 = ( unsigned long ) ( V_47 + V_48 ) ;
if ( F_48 ( V_30 , V_31 , V_46 ) )
return NULL ;
return V_47 ;
}
void T_7 F_49 ( struct V_6 * * V_49 ,
unsigned long V_50 ,
unsigned long V_51 ,
unsigned long V_52 , int V_53 )
{
unsigned long V_45 ;
unsigned long V_2 = sizeof( struct V_6 ) * V_48 ;
void * V_54 ;
V_2 = F_12 ( V_2 , V_55 ) ;
V_54 = F_1 ( V_53 , V_2 * V_52 ,
V_55 , F_10 ( V_11 ) ) ;
if ( V_54 ) {
V_13 = V_54 ;
V_14 = V_54 + V_2 * V_52 ;
}
for ( V_45 = V_50 ; V_45 < V_51 ; V_45 ++ ) {
struct V_56 * V_57 ;
if ( ! F_50 ( V_45 ) )
continue;
V_49 [ V_45 ] = F_46 ( V_45 , V_53 ) ;
if ( V_49 [ V_45 ] )
continue;
V_57 = F_51 ( V_45 ) ;
F_27 ( V_58 L_5
L_6 , V_27 ) ;
V_57 -> V_59 = 0 ;
}
if ( V_54 ) {
F_52 ( F_10 ( V_13 ) ,
V_14 - V_13 ) ;
V_13 = NULL ;
V_14 = NULL ;
}
}
