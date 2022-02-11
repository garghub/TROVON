static bool T_1 F_1 ( void )
{
int V_1 ;
int V_2 = F_2 ( V_3 ) ;
for ( V_1 = 0 ; V_1 < V_2 ; V_1 ++ ) {
if ( V_3 [ V_1 ] -> V_4 && V_3 [ V_1 ] -> V_4 () )
return true ;
}
return false ;
}
static void T_1 F_3 ( void )
{
int V_1 ;
int V_2 = F_2 ( V_3 ) ;
for ( V_1 = 0 ; V_1 < V_2 ; V_1 ++ ) {
if ( V_3 [ V_1 ] -> V_5 )
V_3 [ V_1 ] -> V_5 () ;
}
}
void T_2 F_4 ( struct V_6 * V_7 )
{
V_7 -> V_8 = NULL ;
}
struct V_9 * F_5 ( struct V_10 * V_10 )
{
unsigned long V_11 = F_6 ( V_10 ) ;
unsigned long V_12 ;
struct V_9 * V_13 ;
V_13 = F_7 ( F_8 ( V_10 ) ) -> V_8 ;
#if F_9 ( V_14 ) || F_9 ( V_15 )
if ( F_10 ( ! V_13 ) )
return NULL ;
#endif
V_12 = V_11 - F_11 ( F_12 ( F_8 ( V_10 ) ) ,
V_16 ) ;
return V_13 + V_12 ;
}
static int T_1 F_13 ( int V_17 )
{
struct V_9 * V_13 ;
unsigned long V_18 ;
unsigned long V_19 ;
V_19 = F_7 ( V_17 ) -> V_20 ;
if ( ! V_19 )
return 0 ;
if ( ! F_14 ( F_12 ( V_17 ) , V_16 ) ||
! F_14 ( F_15 ( V_17 ) , V_16 ) )
V_19 += V_16 ;
V_18 = sizeof( struct V_9 ) * V_19 ;
V_13 = F_16 (
V_18 , V_21 , F_17 ( V_22 ) ,
V_23 , V_17 ) ;
if ( ! V_13 )
return - V_24 ;
F_7 ( V_17 ) -> V_8 = V_13 ;
V_25 += V_18 ;
return 0 ;
}
void T_1 F_18 ( void )
{
int V_17 , V_26 ;
if ( ! F_1 () )
return;
F_19 (nid) {
V_26 = F_13 ( V_17 ) ;
if ( V_26 )
goto V_26;
}
F_20 ( L_1 , V_25 ) ;
F_3 () ;
return;
V_26:
F_21 ( L_2 ) ;
F_22 ( L_3 ) ;
}
struct V_9 * F_5 ( struct V_10 * V_10 )
{
unsigned long V_11 = F_6 ( V_10 ) ;
struct V_27 * V_28 = F_23 ( V_11 ) ;
#if F_9 ( V_14 ) || F_9 ( V_15 )
if ( ! V_28 -> V_9 )
return NULL ;
#endif
return V_28 -> V_9 + V_11 ;
}
static void * T_2 F_24 ( T_3 V_29 , int V_17 )
{
T_4 V_30 = V_31 | V_32 | V_33 ;
void * V_34 = NULL ;
V_34 = F_25 ( V_17 , V_29 , V_30 ) ;
if ( V_34 ) {
F_26 ( V_34 , V_29 , 1 , V_30 ) ;
return V_34 ;
}
if ( F_27 ( V_17 , V_35 ) )
V_34 = F_28 ( V_29 , V_17 ) ;
else
V_34 = F_29 ( V_29 ) ;
return V_34 ;
}
static int T_2 F_30 ( unsigned long V_11 , int V_17 )
{
struct V_27 * V_28 ;
struct V_9 * V_13 ;
unsigned long V_18 ;
V_28 = F_23 ( V_11 ) ;
if ( V_28 -> V_9 )
return 0 ;
V_18 = sizeof( struct V_9 ) * V_36 ;
V_13 = F_24 ( V_18 , V_17 ) ;
F_31 ( V_13 ) ;
if ( ! V_13 ) {
F_32 ( L_4 ) ;
return - V_24 ;
}
V_11 &= V_37 ;
V_28 -> V_9 = V_13 - V_11 ;
V_25 += V_18 ;
return 0 ;
}
static void F_33 ( void * V_34 )
{
if ( F_34 ( V_34 ) ) {
F_35 ( V_34 ) ;
} else {
struct V_10 * V_10 = F_36 ( V_34 ) ;
T_3 V_18 ;
V_18 = sizeof( struct V_9 ) * V_36 ;
F_37 ( F_38 ( V_10 ) ) ;
F_39 ( V_34 , V_18 ) ;
}
}
static void F_40 ( unsigned long V_11 )
{
struct V_27 * V_38 ;
struct V_9 * V_13 ;
V_38 = F_23 ( V_11 ) ;
if ( ! V_38 || ! V_38 -> V_9 )
return;
V_13 = V_38 -> V_9 + V_11 ;
F_33 ( V_13 ) ;
V_38 -> V_9 = NULL ;
}
static int T_2 F_41 ( unsigned long V_39 ,
unsigned long V_19 ,
int V_17 )
{
unsigned long V_40 , V_41 , V_11 ;
int V_26 = 0 ;
V_40 = F_42 ( V_39 ) ;
V_41 = F_43 ( V_39 + V_19 ) ;
if ( V_17 == - 1 ) {
V_17 = F_44 ( V_39 ) ;
F_45 ( ! F_27 ( V_17 , V_42 ) ) ;
}
for ( V_11 = V_40 ; ! V_26 && V_11 < V_41 ; V_11 += V_36 ) {
if ( ! F_46 ( V_11 ) )
continue;
V_26 = F_30 ( V_11 , V_17 ) ;
}
if ( ! V_26 )
return 0 ;
for ( V_11 = V_40 ; V_11 < V_41 ; V_11 += V_36 )
F_40 ( V_11 ) ;
return - V_24 ;
}
static int T_2 F_47 ( unsigned long V_39 ,
unsigned long V_19 , int V_17 )
{
unsigned long V_40 , V_41 , V_11 ;
V_40 = F_42 ( V_39 ) ;
V_41 = F_43 ( V_39 + V_19 ) ;
for ( V_11 = V_40 ; V_11 < V_41 ; V_11 += V_36 )
F_40 ( V_11 ) ;
return 0 ;
}
static int T_2 F_48 ( struct V_43 * V_44 ,
unsigned long V_45 , void * V_46 )
{
struct V_47 * V_48 = V_46 ;
int V_49 = 0 ;
switch ( V_45 ) {
case V_50 :
V_49 = F_41 ( V_48 -> V_39 ,
V_48 -> V_19 , V_48 -> V_51 ) ;
break;
case V_52 :
F_47 ( V_48 -> V_39 ,
V_48 -> V_19 , V_48 -> V_51 ) ;
break;
case V_53 :
F_47 ( V_48 -> V_39 ,
V_48 -> V_19 , V_48 -> V_51 ) ;
break;
case V_54 :
break;
case V_55 :
case V_56 :
break;
}
return F_49 ( V_49 ) ;
}
void T_1 F_50 ( void )
{
unsigned long V_11 ;
int V_17 ;
if ( ! F_1 () )
return;
F_51 (nid, N_MEMORY) {
unsigned long V_39 , V_57 ;
V_39 = F_12 ( V_17 ) ;
V_57 = F_15 ( V_17 ) ;
for ( V_11 = V_39 ; V_11 < V_57 ;
V_11 = F_52 ( V_11 + 1 , V_36 ) ) {
if ( ! F_53 ( V_11 ) )
continue;
if ( F_54 ( V_11 ) != V_17 )
continue;
if ( F_30 ( V_11 , V_17 ) )
goto V_58;
}
}
F_55 ( F_48 , 0 ) ;
F_20 ( L_1 , V_25 ) ;
F_3 () ;
return;
V_58:
F_22 ( L_3 ) ;
}
void T_2 F_4 ( struct V_6 * V_7 )
{
}
