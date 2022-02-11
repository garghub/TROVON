int T_1 F_1 ( struct V_1 * V_2 , char * V_3 )
{
unsigned long V_4 ;
unsigned long V_5 ;
int V_6 ;
int V_7 ;
if ( sscanf ( V_3 , L_1 ,
& V_5 , & V_4 , & V_7 , & V_6 ) < 4 ) {
F_2 ( V_8
L_2 ) ;
return 0 ;
}
V_2 -> V_4 = V_4 ;
V_2 -> V_5 = V_5 ;
F_3 ( & V_2 -> V_6 , V_6 ) ;
F_3 ( & V_2 -> V_7 , V_7 ) ;
return 1 ;
}
static void F_4 ( struct V_1 * V_2 )
{
if ( V_2 -> V_9 > 0 )
F_2 ( V_10 L_3 ) ;
if ( V_2 -> V_9 > 1 )
F_5 () ;
}
static bool F_6 ( struct V_1 * V_2 , struct V_11 * V_12 )
{
return ! F_7 () && V_12 -> V_13 ;
}
static bool F_8 ( struct V_1 * V_2 )
{
struct V_14 V_15 ;
int V_16 = V_2 -> V_17 ;
unsigned long V_18 [ V_19 ] ;
int V_20 ;
bool V_21 = ( V_2 -> V_22 == 0 && V_2 -> V_23 == V_24 ) ;
if ( V_16 == 0 )
return V_21 ;
V_15 . V_25 = 0 ;
V_15 . V_18 = V_18 ;
V_15 . V_26 = V_16 ;
V_15 . V_27 = 1 ;
F_9 ( & V_15 ) ;
for ( V_20 = 0 ; V_20 < V_15 . V_25 ; V_20 ++ ) {
if ( V_2 -> V_28 <= V_18 [ V_20 ] &&
V_18 [ V_20 ] < V_2 -> V_29 )
return false ;
if ( V_2 -> V_22 <= V_18 [ V_20 ] &&
V_18 [ V_20 ] < V_2 -> V_23 )
V_21 = true ;
}
return V_21 ;
}
static inline bool F_8 ( struct V_1 * V_2 )
{
return true ;
}
bool F_10 ( struct V_1 * V_2 , T_2 V_30 )
{
if ( V_2 -> V_31 && ! F_6 ( V_2 , V_32 ) )
return false ;
if ( F_11 ( & V_2 -> V_6 ) == 0 )
return false ;
if ( F_11 ( & V_2 -> V_7 ) > V_30 ) {
F_12 ( V_30 , & V_2 -> V_7 ) ;
return false ;
}
if ( V_2 -> V_5 > 1 ) {
V_2 -> V_33 ++ ;
if ( V_2 -> V_33 % V_2 -> V_5 )
return false ;
}
if ( V_2 -> V_4 <= F_13 () % 100 )
return false ;
if ( ! F_8 ( V_2 ) )
return false ;
F_4 ( V_2 ) ;
if ( F_11 ( & V_2 -> V_6 ) != - 1 )
F_14 ( & V_2 -> V_6 ) ;
return true ;
}
static int F_15 ( void * V_34 , T_3 V_35 )
{
* ( unsigned long * ) V_34 = V_35 ;
return 0 ;
}
static int F_16 ( void * V_34 , T_3 V_35 )
{
* ( unsigned long * ) V_34 =
V_35 < V_19 ?
V_35 : V_19 ;
return 0 ;
}
static int F_17 ( void * V_34 , T_3 * V_35 )
{
* V_35 = * ( unsigned long * ) V_34 ;
return 0 ;
}
static struct V_36 * F_18 ( const char * V_37 , T_4 V_38 ,
struct V_36 * V_39 , unsigned long * V_40 )
{
return F_19 ( V_37 , V_38 , V_39 , V_40 , & V_41 ) ;
}
static struct V_36 * F_20 (
const char * V_37 , T_4 V_38 ,
struct V_36 * V_39 , unsigned long * V_40 )
{
return F_19 ( V_37 , V_38 , V_39 , V_40 ,
& V_42 ) ;
}
static int F_21 ( void * V_34 , T_3 V_35 )
{
F_3 ( ( V_43 * ) V_34 , V_35 ) ;
return 0 ;
}
static int F_22 ( void * V_34 , T_3 * V_35 )
{
* V_35 = F_11 ( ( V_43 * ) V_34 ) ;
return 0 ;
}
static struct V_36 * F_23 ( const char * V_37 , T_4 V_38 ,
struct V_36 * V_39 , V_43 * V_40 )
{
return F_19 ( V_37 , V_38 , V_39 , V_40 , & V_44 ) ;
}
void F_24 ( struct V_1 * V_2 )
{
F_25 ( V_2 -> V_45 . V_46 ) ;
V_2 -> V_45 . V_46 = NULL ;
F_25 ( V_2 -> V_45 . V_47 ) ;
V_2 -> V_45 . V_47 = NULL ;
F_25 ( V_2 -> V_45 . V_48 ) ;
V_2 -> V_45 . V_48 = NULL ;
F_25 ( V_2 -> V_45 . V_49 ) ;
V_2 -> V_45 . V_49 = NULL ;
F_25 ( V_2 -> V_45 . V_50 ) ;
V_2 -> V_45 . V_50 = NULL ;
F_25 ( V_2 -> V_45 . V_51 ) ;
V_2 -> V_45 . V_51 = NULL ;
#ifdef F_26
F_25 ( V_2 -> V_45 . V_52 ) ;
V_2 -> V_45 . V_52 = NULL ;
F_25 ( V_2 -> V_45 . V_53 ) ;
V_2 -> V_45 . V_53 = NULL ;
F_25 ( V_2 -> V_45 . V_54 ) ;
V_2 -> V_45 . V_54 = NULL ;
F_25 ( V_2 -> V_45 . V_55 ) ;
V_2 -> V_45 . V_55 = NULL ;
F_25 ( V_2 -> V_45 . V_56 ) ;
V_2 -> V_45 . V_56 = NULL ;
#endif
if ( V_2 -> V_45 . V_57 )
F_27 ( ! F_28 ( V_2 -> V_45 . V_57 ) ) ;
F_25 ( V_2 -> V_45 . V_57 ) ;
V_2 -> V_45 . V_57 = NULL ;
}
int F_29 ( struct V_1 * V_2 , const char * V_37 )
{
T_4 V_38 = V_58 | V_59 | V_60 ;
struct V_36 * V_57 ;
memset ( & V_2 -> V_45 , 0 , sizeof( V_2 -> V_45 ) ) ;
V_57 = F_30 ( V_37 , NULL ) ;
if ( ! V_57 )
goto V_61;
V_2 -> V_45 . V_57 = V_57 ;
V_2 -> V_45 . V_46 =
F_18 ( L_4 , V_38 , V_57 , & V_2 -> V_4 ) ;
V_2 -> V_45 . V_47 =
F_18 ( L_5 , V_38 , V_57 , & V_2 -> V_5 ) ;
V_2 -> V_45 . V_48 =
F_23 ( L_6 , V_38 , V_57 , & V_2 -> V_6 ) ;
V_2 -> V_45 . V_49 =
F_23 ( L_7 , V_38 , V_57 , & V_2 -> V_7 ) ;
V_2 -> V_45 . V_50 =
F_18 ( L_8 , V_38 , V_57 , & V_2 -> V_9 ) ;
V_2 -> V_45 . V_51 = F_31 ( L_9 ,
V_38 , V_57 , & V_2 -> V_31 ) ;
if ( ! V_2 -> V_45 . V_46 || ! V_2 -> V_45 . V_47 ||
! V_2 -> V_45 . V_48 || ! V_2 -> V_45 . V_49 ||
! V_2 -> V_45 . V_50 || ! V_2 -> V_45 . V_51 )
goto V_61;
#ifdef F_26
V_2 -> V_45 . V_52 =
F_20 (
L_10 , V_38 , V_57 , & V_2 -> V_17 ) ;
V_2 -> V_45 . V_53 =
F_18 ( L_11 , V_38 , V_57 , & V_2 -> V_22 ) ;
V_2 -> V_45 . V_54 =
F_18 ( L_12 , V_38 , V_57 , & V_2 -> V_23 ) ;
V_2 -> V_45 . V_55 =
F_18 ( L_13 , V_38 , V_57 , & V_2 -> V_28 ) ;
V_2 -> V_45 . V_56 =
F_18 ( L_14 , V_38 , V_57 , & V_2 -> V_29 ) ;
if ( ! V_2 -> V_45 . V_52 ||
! V_2 -> V_45 . V_53 ||
! V_2 -> V_45 . V_54 ||
! V_2 -> V_45 . V_55 ||
! V_2 -> V_45 . V_56 )
goto V_61;
#endif
return 0 ;
V_61:
F_24 ( V_2 ) ;
return - V_62 ;
}
