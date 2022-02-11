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
#ifdef F_9
if ( F_10 ( ! V_13 ) )
return NULL ;
#endif
V_12 = V_11 - F_11 ( F_12 ( F_8 ( V_10 ) ) ,
V_14 ) ;
return V_13 + V_12 ;
}
static int T_1 F_13 ( int V_15 )
{
struct V_9 * V_13 ;
unsigned long V_16 ;
unsigned long V_17 ;
V_17 = F_7 ( V_15 ) -> V_18 ;
if ( ! V_17 )
return 0 ;
if ( ! F_14 ( F_12 ( V_15 ) , V_14 ) ||
! F_14 ( F_15 ( V_15 ) , V_14 ) )
V_17 += V_14 ;
V_16 = sizeof( struct V_9 ) * V_17 ;
V_13 = F_16 (
V_16 , V_19 , F_17 ( V_20 ) ,
V_21 , V_15 ) ;
if ( ! V_13 )
return - V_22 ;
F_7 ( V_15 ) -> V_8 = V_13 ;
V_23 += V_16 ;
return 0 ;
}
void T_1 F_18 ( void )
{
int V_15 , V_24 ;
if ( ! F_1 () )
return;
F_19 (nid) {
V_24 = F_13 ( V_15 ) ;
if ( V_24 )
goto V_24;
}
F_20 ( L_1 , V_23 ) ;
F_3 () ;
return;
V_24:
F_21 ( L_2 ) ;
F_22 ( L_3 ) ;
}
struct V_9 * F_5 ( struct V_10 * V_10 )
{
unsigned long V_11 = F_6 ( V_10 ) ;
struct V_25 * V_26 = F_23 ( V_11 ) ;
#ifdef F_9
if ( ! V_26 -> V_9 )
return NULL ;
#endif
return V_26 -> V_9 + V_11 ;
}
static void * T_2 F_24 ( T_3 V_27 , int V_15 )
{
T_4 V_28 = V_29 | V_30 | V_31 ;
void * V_32 = NULL ;
V_32 = F_25 ( V_15 , V_27 , V_28 ) ;
if ( V_32 ) {
F_26 ( V_32 , V_27 , 1 , V_28 ) ;
return V_32 ;
}
if ( F_27 ( V_15 , V_33 ) )
V_32 = F_28 ( V_27 , V_15 ) ;
else
V_32 = F_29 ( V_27 ) ;
return V_32 ;
}
static int T_2 F_30 ( unsigned long V_11 , int V_15 )
{
struct V_25 * V_26 ;
struct V_9 * V_13 ;
unsigned long V_16 ;
V_26 = F_23 ( V_11 ) ;
if ( V_26 -> V_9 )
return 0 ;
V_16 = sizeof( struct V_9 ) * V_34 ;
V_13 = F_24 ( V_16 , V_15 ) ;
F_31 ( V_13 ) ;
if ( ! V_13 ) {
F_32 ( L_4 ) ;
return - V_22 ;
}
V_11 &= V_35 ;
V_26 -> V_9 = V_13 - V_11 ;
V_23 += V_16 ;
return 0 ;
}
static void F_33 ( void * V_32 )
{
if ( F_34 ( V_32 ) ) {
F_35 ( V_32 ) ;
} else {
struct V_10 * V_10 = F_36 ( V_32 ) ;
T_3 V_16 ;
V_16 = sizeof( struct V_9 ) * V_34 ;
F_37 ( F_38 ( V_10 ) ) ;
F_39 ( V_32 , V_16 ) ;
}
}
static void F_40 ( unsigned long V_11 )
{
struct V_25 * V_36 ;
struct V_9 * V_13 ;
V_36 = F_23 ( V_11 ) ;
if ( ! V_36 || ! V_36 -> V_9 )
return;
V_13 = V_36 -> V_9 + V_11 ;
F_33 ( V_13 ) ;
V_36 -> V_9 = NULL ;
}
static int T_2 F_41 ( unsigned long V_37 ,
unsigned long V_17 ,
int V_15 )
{
unsigned long V_38 , V_39 , V_11 ;
int V_24 = 0 ;
V_38 = F_42 ( V_37 ) ;
V_39 = F_43 ( V_37 + V_17 ) ;
if ( V_15 == - 1 ) {
V_15 = F_44 ( V_37 ) ;
F_45 ( ! F_27 ( V_15 , V_40 ) ) ;
}
for ( V_11 = V_38 ; ! V_24 && V_11 < V_39 ; V_11 += V_34 ) {
if ( ! F_46 ( V_11 ) )
continue;
V_24 = F_30 ( V_11 , V_15 ) ;
}
if ( ! V_24 )
return 0 ;
for ( V_11 = V_38 ; V_11 < V_39 ; V_11 += V_34 )
F_40 ( V_11 ) ;
return - V_22 ;
}
static int T_2 F_47 ( unsigned long V_37 ,
unsigned long V_17 , int V_15 )
{
unsigned long V_38 , V_39 , V_11 ;
V_38 = F_42 ( V_37 ) ;
V_39 = F_43 ( V_37 + V_17 ) ;
for ( V_11 = V_38 ; V_11 < V_39 ; V_11 += V_34 )
F_40 ( V_11 ) ;
return 0 ;
}
static int T_2 F_48 ( struct V_41 * V_42 ,
unsigned long V_43 , void * V_44 )
{
struct V_45 * V_46 = V_44 ;
int V_47 = 0 ;
switch ( V_43 ) {
case V_48 :
V_47 = F_41 ( V_46 -> V_37 ,
V_46 -> V_17 , V_46 -> V_49 ) ;
break;
case V_50 :
F_47 ( V_46 -> V_37 ,
V_46 -> V_17 , V_46 -> V_49 ) ;
break;
case V_51 :
F_47 ( V_46 -> V_37 ,
V_46 -> V_17 , V_46 -> V_49 ) ;
break;
case V_52 :
break;
case V_53 :
case V_54 :
break;
}
return F_49 ( V_47 ) ;
}
void T_1 F_50 ( void )
{
unsigned long V_11 ;
int V_15 ;
if ( ! F_1 () )
return;
F_51 (nid, N_MEMORY) {
unsigned long V_37 , V_55 ;
V_37 = F_12 ( V_15 ) ;
V_55 = F_15 ( V_15 ) ;
for ( V_11 = V_37 ; V_11 < V_55 ;
V_11 = F_52 ( V_11 + 1 , V_34 ) ) {
if ( ! F_53 ( V_11 ) )
continue;
if ( F_44 ( V_11 ) != V_15 )
continue;
if ( F_30 ( V_11 , V_15 ) )
goto V_56;
}
}
F_54 ( F_48 , 0 ) ;
F_20 ( L_1 , V_23 ) ;
F_3 () ;
return;
V_56:
F_22 ( L_3 ) ;
}
void T_2 F_4 ( struct V_6 * V_7 )
{
}
