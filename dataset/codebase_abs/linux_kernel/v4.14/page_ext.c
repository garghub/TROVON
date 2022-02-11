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
#if F_11 ( V_17 )
if ( F_12 ( ! V_10 ) )
return NULL ;
#endif
V_11 = V_16 - F_13 ( F_14 ( F_10 ( V_15 ) ) ,
V_18 ) ;
return F_5 ( V_10 , V_11 ) ;
}
static int T_1 F_15 ( int V_19 )
{
struct V_6 * V_10 ;
unsigned long V_20 ;
unsigned long V_21 ;
V_21 = F_9 ( V_19 ) -> V_22 ;
if ( ! V_21 )
return 0 ;
if ( ! F_16 ( F_14 ( V_19 ) , V_18 ) ||
! F_16 ( F_17 ( V_19 ) , V_18 ) )
V_21 += V_18 ;
V_20 = F_4 () * V_21 ;
V_10 = F_18 (
V_20 , V_23 , F_19 ( V_24 ) ,
V_25 , V_19 ) ;
if ( ! V_10 )
return - V_26 ;
F_9 ( V_19 ) -> V_14 = V_10 ;
V_27 += V_20 ;
return 0 ;
}
void T_1 F_20 ( void )
{
int V_19 , V_28 ;
if ( ! F_1 () )
return;
F_21 (nid) {
V_28 = F_15 ( V_19 ) ;
if ( V_28 )
goto V_28;
}
F_22 ( L_1 , V_27 ) ;
F_3 () ;
return;
V_28:
F_23 ( L_2 ) ;
F_24 ( L_3 ) ;
}
struct V_6 * F_7 ( struct V_15 * V_15 )
{
unsigned long V_16 = F_8 ( V_15 ) ;
struct V_29 * V_30 = F_25 ( V_16 ) ;
#if F_11 ( V_17 )
if ( ! V_30 -> V_6 )
return NULL ;
#endif
return F_5 ( V_30 -> V_6 , V_16 ) ;
}
static void * T_2 F_26 ( T_3 V_8 , int V_19 )
{
T_4 V_31 = V_32 | V_33 | V_34 ;
void * V_35 = NULL ;
V_35 = F_27 ( V_19 , V_8 , V_31 ) ;
if ( V_35 ) {
F_28 ( V_35 , V_8 , 1 , V_31 ) ;
return V_35 ;
}
V_35 = F_29 ( V_8 , V_19 ) ;
return V_35 ;
}
static int T_2 F_30 ( unsigned long V_16 , int V_19 )
{
struct V_29 * V_30 ;
struct V_6 * V_10 ;
unsigned long V_20 ;
V_30 = F_25 ( V_16 ) ;
if ( V_30 -> V_6 )
return 0 ;
V_20 = F_4 () * V_36 ;
V_10 = F_26 ( V_20 , V_19 ) ;
F_31 ( V_10 ) ;
if ( ! V_10 ) {
F_32 ( L_4 ) ;
return - V_26 ;
}
V_16 &= V_37 ;
V_30 -> V_6 = ( void * ) V_10 - F_4 () * V_16 ;
V_27 += V_20 ;
return 0 ;
}
static void F_33 ( void * V_35 )
{
if ( F_34 ( V_35 ) ) {
F_35 ( V_35 ) ;
} else {
struct V_15 * V_15 = F_36 ( V_35 ) ;
T_3 V_20 ;
V_20 = F_4 () * V_36 ;
F_37 ( F_38 ( V_15 ) ) ;
F_39 ( V_35 , V_20 ) ;
}
}
static void F_40 ( unsigned long V_16 )
{
struct V_29 * V_38 ;
struct V_6 * V_10 ;
V_38 = F_25 ( V_16 ) ;
if ( ! V_38 || ! V_38 -> V_6 )
return;
V_10 = F_5 ( V_38 -> V_6 , V_16 ) ;
F_33 ( V_10 ) ;
V_38 -> V_6 = NULL ;
}
static int T_2 F_41 ( unsigned long V_39 ,
unsigned long V_21 ,
int V_19 )
{
unsigned long V_40 , V_41 , V_16 ;
int V_28 = 0 ;
V_40 = F_42 ( V_39 ) ;
V_41 = F_43 ( V_39 + V_21 ) ;
if ( V_19 == - 1 ) {
V_19 = F_44 ( V_39 ) ;
F_45 ( ! F_46 ( V_19 , V_42 ) ) ;
}
for ( V_16 = V_40 ; ! V_28 && V_16 < V_41 ; V_16 += V_36 ) {
if ( ! F_47 ( V_16 ) )
continue;
V_28 = F_30 ( V_16 , V_19 ) ;
}
if ( ! V_28 )
return 0 ;
for ( V_16 = V_40 ; V_16 < V_41 ; V_16 += V_36 )
F_40 ( V_16 ) ;
return - V_26 ;
}
static int T_2 F_48 ( unsigned long V_39 ,
unsigned long V_21 , int V_19 )
{
unsigned long V_40 , V_41 , V_16 ;
V_40 = F_42 ( V_39 ) ;
V_41 = F_43 ( V_39 + V_21 ) ;
for ( V_16 = V_40 ; V_16 < V_41 ; V_16 += V_36 )
F_40 ( V_16 ) ;
return 0 ;
}
static int T_2 F_49 ( struct V_43 * V_44 ,
unsigned long V_45 , void * V_46 )
{
struct V_47 * V_48 = V_46 ;
int V_49 = 0 ;
switch ( V_45 ) {
case V_50 :
V_49 = F_41 ( V_48 -> V_39 ,
V_48 -> V_21 , V_48 -> V_51 ) ;
break;
case V_52 :
F_48 ( V_48 -> V_39 ,
V_48 -> V_21 , V_48 -> V_51 ) ;
break;
case V_53 :
F_48 ( V_48 -> V_39 ,
V_48 -> V_21 , V_48 -> V_51 ) ;
break;
case V_54 :
break;
case V_55 :
case V_56 :
break;
}
return F_50 ( V_49 ) ;
}
void T_1 F_51 ( void )
{
unsigned long V_16 ;
int V_19 ;
if ( ! F_1 () )
return;
F_52 (nid, N_MEMORY) {
unsigned long V_39 , V_57 ;
V_39 = F_14 ( V_19 ) ;
V_57 = F_17 ( V_19 ) ;
for ( V_16 = V_39 ; V_16 < V_57 ;
V_16 = F_53 ( V_16 + 1 , V_36 ) ) {
if ( ! F_54 ( V_16 ) )
continue;
if ( F_55 ( V_16 ) != V_19 )
continue;
if ( F_30 ( V_16 , V_19 ) )
goto V_58;
F_56 () ;
}
}
F_57 ( F_49 , 0 ) ;
F_22 ( L_1 , V_27 ) ;
F_3 () ;
return;
V_58:
F_24 ( L_3 ) ;
}
void T_2 F_6 ( struct V_12 * V_13 )
{
}
