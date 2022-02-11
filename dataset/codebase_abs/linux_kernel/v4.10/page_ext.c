static bool T_1 F_1 ( void )
{
int V_1 ;
int V_2 = F_2 ( V_3 ) ;
bool V_4 = false ;
for ( V_1 = 0 ; V_1 < V_2 ; V_1 ++ ) {
if ( V_3 [ V_1 ] -> V_4 && V_3 [ V_1 ] -> V_4 () ) {
V_3 [ V_1 ] -> V_5 = sizeof( struct V_6 ) +
V_7 ;
V_7 += V_3 [ V_1 ] -> V_8 ;
V_4 = true ;
}
}
return V_4 ;
}
static void T_1 F_3 ( void )
{
int V_1 ;
int V_2 = F_2 ( V_3 ) ;
for ( V_1 = 0 ; V_1 < V_2 ; V_1 ++ ) {
if ( V_3 [ V_1 ] -> V_9 )
V_3 [ V_1 ] -> V_9 () ;
}
}
static unsigned long F_4 ( void )
{
return sizeof( struct V_6 ) + V_7 ;
}
static inline struct V_6 * F_5 ( void * V_10 , unsigned long V_11 )
{
return V_10 + F_4 () * V_11 ;
}
void T_2 F_6 ( struct V_12 * V_13 )
{
V_13 -> V_14 = NULL ;
}
struct V_6 * F_7 ( struct V_15 * V_15 )
{
unsigned long V_16 = F_8 ( V_15 ) ;
unsigned long V_11 ;
struct V_6 * V_10 ;
V_10 = F_9 ( F_10 ( V_15 ) ) -> V_14 ;
#if F_11 ( V_17 ) || F_11 ( V_18 )
if ( F_12 ( ! V_10 ) )
return NULL ;
#endif
V_11 = V_16 - F_13 ( F_14 ( F_10 ( V_15 ) ) ,
V_19 ) ;
return F_5 ( V_10 , V_11 ) ;
}
static int T_1 F_15 ( int V_20 )
{
struct V_6 * V_10 ;
unsigned long V_21 ;
unsigned long V_22 ;
V_22 = F_9 ( V_20 ) -> V_23 ;
if ( ! V_22 )
return 0 ;
if ( ! F_16 ( F_14 ( V_20 ) , V_19 ) ||
! F_16 ( F_17 ( V_20 ) , V_19 ) )
V_22 += V_19 ;
V_21 = F_4 () * V_22 ;
V_10 = F_18 (
V_21 , V_24 , F_19 ( V_25 ) ,
V_26 , V_20 ) ;
if ( ! V_10 )
return - V_27 ;
F_9 ( V_20 ) -> V_14 = V_10 ;
V_28 += V_21 ;
return 0 ;
}
void T_1 F_20 ( void )
{
int V_20 , V_29 ;
if ( ! F_1 () )
return;
F_21 (nid) {
V_29 = F_15 ( V_20 ) ;
if ( V_29 )
goto V_29;
}
F_22 ( L_1 , V_28 ) ;
F_3 () ;
return;
V_29:
F_23 ( L_2 ) ;
F_24 ( L_3 ) ;
}
struct V_6 * F_7 ( struct V_15 * V_15 )
{
unsigned long V_16 = F_8 ( V_15 ) ;
struct V_30 * V_31 = F_25 ( V_16 ) ;
#if F_11 ( V_17 ) || F_11 ( V_18 )
if ( ! V_31 -> V_6 )
return NULL ;
#endif
return F_5 ( V_31 -> V_6 , V_16 ) ;
}
static void * T_2 F_26 ( T_3 V_8 , int V_20 )
{
T_4 V_32 = V_33 | V_34 | V_35 ;
void * V_36 = NULL ;
V_36 = F_27 ( V_20 , V_8 , V_32 ) ;
if ( V_36 ) {
F_28 ( V_36 , V_8 , 1 , V_32 ) ;
return V_36 ;
}
if ( F_29 ( V_20 , V_37 ) )
V_36 = F_30 ( V_8 , V_20 ) ;
else
V_36 = F_31 ( V_8 ) ;
return V_36 ;
}
static int T_2 F_32 ( unsigned long V_16 , int V_20 )
{
struct V_30 * V_31 ;
struct V_6 * V_10 ;
unsigned long V_21 ;
V_31 = F_25 ( V_16 ) ;
if ( V_31 -> V_6 )
return 0 ;
V_21 = F_4 () * V_38 ;
V_10 = F_26 ( V_21 , V_20 ) ;
F_33 ( V_10 ) ;
if ( ! V_10 ) {
F_34 ( L_4 ) ;
return - V_27 ;
}
V_16 &= V_39 ;
V_31 -> V_6 = ( void * ) V_10 - F_4 () * V_16 ;
V_28 += V_21 ;
return 0 ;
}
static void F_35 ( void * V_36 )
{
if ( F_36 ( V_36 ) ) {
F_37 ( V_36 ) ;
} else {
struct V_15 * V_15 = F_38 ( V_36 ) ;
T_3 V_21 ;
V_21 = F_4 () * V_38 ;
F_39 ( F_40 ( V_15 ) ) ;
F_41 ( V_36 , V_21 ) ;
}
}
static void F_42 ( unsigned long V_16 )
{
struct V_30 * V_40 ;
struct V_6 * V_10 ;
V_40 = F_25 ( V_16 ) ;
if ( ! V_40 || ! V_40 -> V_6 )
return;
V_10 = F_5 ( V_40 -> V_6 , V_16 ) ;
F_35 ( V_10 ) ;
V_40 -> V_6 = NULL ;
}
static int T_2 F_43 ( unsigned long V_41 ,
unsigned long V_22 ,
int V_20 )
{
unsigned long V_42 , V_43 , V_16 ;
int V_29 = 0 ;
V_42 = F_44 ( V_41 ) ;
V_43 = F_45 ( V_41 + V_22 ) ;
if ( V_20 == - 1 ) {
V_20 = F_46 ( V_41 ) ;
F_47 ( ! F_29 ( V_20 , V_44 ) ) ;
}
for ( V_16 = V_42 ; ! V_29 && V_16 < V_43 ; V_16 += V_38 ) {
if ( ! F_48 ( V_16 ) )
continue;
V_29 = F_32 ( V_16 , V_20 ) ;
}
if ( ! V_29 )
return 0 ;
for ( V_16 = V_42 ; V_16 < V_43 ; V_16 += V_38 )
F_42 ( V_16 ) ;
return - V_27 ;
}
static int T_2 F_49 ( unsigned long V_41 ,
unsigned long V_22 , int V_20 )
{
unsigned long V_42 , V_43 , V_16 ;
V_42 = F_44 ( V_41 ) ;
V_43 = F_45 ( V_41 + V_22 ) ;
for ( V_16 = V_42 ; V_16 < V_43 ; V_16 += V_38 )
F_42 ( V_16 ) ;
return 0 ;
}
static int T_2 F_50 ( struct V_45 * V_46 ,
unsigned long V_47 , void * V_48 )
{
struct V_49 * V_50 = V_48 ;
int V_51 = 0 ;
switch ( V_47 ) {
case V_52 :
V_51 = F_43 ( V_50 -> V_41 ,
V_50 -> V_22 , V_50 -> V_53 ) ;
break;
case V_54 :
F_49 ( V_50 -> V_41 ,
V_50 -> V_22 , V_50 -> V_53 ) ;
break;
case V_55 :
F_49 ( V_50 -> V_41 ,
V_50 -> V_22 , V_50 -> V_53 ) ;
break;
case V_56 :
break;
case V_57 :
case V_58 :
break;
}
return F_51 ( V_51 ) ;
}
void T_1 F_52 ( void )
{
unsigned long V_16 ;
int V_20 ;
if ( ! F_1 () )
return;
F_53 (nid, N_MEMORY) {
unsigned long V_41 , V_59 ;
V_41 = F_14 ( V_20 ) ;
V_59 = F_17 ( V_20 ) ;
for ( V_16 = V_41 ; V_16 < V_59 ;
V_16 = F_54 ( V_16 + 1 , V_38 ) ) {
if ( ! F_55 ( V_16 ) )
continue;
if ( F_56 ( V_16 ) != V_20 )
continue;
if ( F_32 ( V_16 , V_20 ) )
goto V_60;
}
}
F_57 ( F_50 , 0 ) ;
F_22 ( L_1 , V_28 ) ;
F_3 () ;
return;
V_60:
F_24 ( L_3 ) ;
}
void T_2 F_6 ( struct V_12 * V_13 )
{
}
