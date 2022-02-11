static inline bool F_1 ( void )
{
return V_1 . V_2 ? true : false ;
}
static inline bool F_2 ( unsigned long V_3 )
{
if ( ! ( V_1 . V_4 & V_5 ) ||
( V_1 . V_4 & V_6 ) ||
! F_1 () )
return false ;
if ( ( V_3 & V_7 ) &&
V_8 != V_1 . V_2 )
return false ;
return true ;
}
static inline bool F_3 ( struct V_9 * V_10 , unsigned long V_3 )
{
if ( ! ( V_1 . V_4 & V_3 ) && F_4 ( V_10 ) )
return true ;
return false ;
}
static inline bool F_5 ( struct V_9 * V_10 , unsigned long V_3 )
{
if ( ! ( V_1 . V_4 & V_3 ) && F_6 ( V_10 ) )
return true ;
return false ;
}
static inline bool F_7 ( void )
{
if ( V_1 . V_4 & V_11 )
return true ;
return false ;
}
static inline bool F_8 ( void )
{
if ( V_1 . V_4 & V_12 )
return true ;
return false ;
}
static inline bool F_9 ( void )
{
return V_1 . V_13 ? true : false ;
}
static inline bool F_10 ( void )
{
bool V_14 ;
F_11 ( & V_1 . V_15 ) ;
V_14 = F_1 () ;
F_12 ( & V_1 . V_15 ) ;
return V_14 ;
}
static bool F_13 ( void )
{
bool V_14 ;
F_11 ( & V_1 . V_15 ) ;
V_14 = F_7 () ;
F_12 ( & V_1 . V_15 ) ;
return V_14 ;
}
static bool F_14 ( void )
{
bool V_14 ;
F_11 ( & V_1 . V_15 ) ;
V_14 = F_9 () ;
F_12 ( & V_1 . V_15 ) ;
return V_14 ;
}
static bool F_15 ( void )
{
bool V_14 ;
F_11 ( & V_1 . V_15 ) ;
V_14 = ! F_2 ( V_16 ) ||
F_3 ( & V_1 . V_17 , V_16 ) ;
F_12 ( & V_1 . V_15 ) ;
return V_14 ;
}
static bool F_16 ( void )
{
bool V_14 ;
F_11 ( & V_1 . V_15 ) ;
V_14 = ! F_2 ( V_18 ) ||
F_5 ( & V_1 . V_19 , V_18 ) ;
F_12 ( & V_1 . V_15 ) ;
return V_14 ;
}
static bool F_17 ( void )
{
bool V_14 ;
F_11 ( & V_1 . V_15 ) ;
V_14 = ! F_2 ( V_20 ) ||
F_3 ( & V_1 . V_19 , V_20 ) ;
F_12 ( & V_1 . V_15 ) ;
return V_14 ;
}
static bool F_18 ( void )
{
bool V_14 ;
F_11 ( & V_1 . V_15 ) ;
V_14 = ! F_2 ( V_21 ) ||
F_5 ( & V_1 . V_17 , V_21 ) ;
F_12 ( & V_1 . V_15 ) ;
return V_14 ;
}
static int F_19 ( struct V_9 * V_10 , unsigned long V_3 )
{
int V_14 = 0 ;
F_11 ( & V_1 . V_15 ) ;
if ( ! F_2 ( V_3 ) ) {
V_14 = - V_22 ;
goto V_23;
}
if ( ! F_5 ( V_10 , V_3 ) ) {
V_14 = - V_24 ;
goto V_23;
}
V_1 . V_4 |= V_3 ;
V_23:
F_12 ( & V_1 . V_15 ) ;
return V_14 ;
}
static int F_20 ( struct V_9 * V_10 , unsigned long V_3 )
{
int V_14 = 0 ;
F_11 ( & V_1 . V_15 ) ;
if ( ! F_2 ( V_3 ) ) {
V_14 = - V_22 ;
goto V_23;
}
if ( ! F_3 ( V_10 , V_3 ) ) {
V_14 = - V_24 ;
goto V_23;
}
V_1 . V_4 |= V_3 ;
V_23:
F_12 ( & V_1 . V_15 ) ;
return V_14 ;
}
static void F_21 ( unsigned long V_3 , bool V_25 )
{
F_11 ( & V_1 . V_15 ) ;
V_1 . V_4 &= ~ V_3 ;
if ( V_25 )
F_22 ( & V_1 . V_26 ) ;
F_12 ( & V_1 . V_15 ) ;
}
static int F_23 ( const char * V_27 , int V_28 )
{
int V_14 ;
struct V_9 * V_29 = & V_1 . V_19 ;
int V_30 ;
char * V_31 ;
V_14 = F_19 ( V_29 , V_18 ) ;
if ( V_14 < 0 )
return V_14 ;
F_24 () ;
V_31 = & V_29 -> V_27 [ V_29 -> V_32 ] ;
V_30 = F_25 ( V_28 , F_26 ( V_29 ) ) ;
memcpy ( V_31 , V_27 , V_30 ) ;
F_27 () ;
V_29 -> V_32 = ( V_29 -> V_32 + V_30 ) & ( V_33 - 1 ) ;
F_21 ( V_18 , true ) ;
return V_30 ;
}
static int F_28 ( void )
{
int V_14 ;
struct V_9 * V_29 = & V_1 . V_17 ;
char * V_31 ;
V_14 = F_20 ( V_29 , V_16 ) ;
if ( V_14 < 0 )
return V_14 ;
F_29 () ;
V_31 = & V_29 -> V_27 [ V_29 -> V_34 ] ;
V_14 = ( int ) * V_31 ;
F_24 () ;
V_29 -> V_34 = ( V_29 -> V_34 + 1 ) & ( V_33 - 1 ) ;
F_21 ( V_16 , true ) ;
return V_14 ;
}
static T_1 F_30 ( const char * V_35 )
{
int V_14 = 0 ;
int V_36 = 0 , V_37 = 0 ;
if ( ! V_38 )
return - V_39 ;
if ( V_35 )
V_36 = strlen ( V_35 ) ;
while ( V_36 > 0 ) {
V_40:
V_14 = F_23 ( V_35 + V_37 , V_36 ) ;
if ( V_14 == - V_24 ) {
V_14 = F_31 ( V_1 . V_26 ,
F_16 () ) ;
if ( V_14 == 0 )
goto V_40;
break;
}
if ( V_14 < 0 )
break;
V_37 += V_14 ;
V_36 -= V_14 ;
}
return V_37 > 0 ? V_37 : V_14 ;
}
static T_1 F_32 ( char * V_35 , T_2 V_36 )
{
int V_14 = 0 ;
int V_37 = 0 ;
F_33 ( ! V_38 ) ;
while ( V_36 > 0 ) {
V_40:
V_14 = F_28 () ;
if ( V_14 == - V_24 ) {
V_14 = F_31 ( V_1 . V_26 ,
F_15 () ) ;
if ( V_14 == 0 )
goto V_40;
}
if ( V_14 < 0 )
break;
* ( V_35 + V_37 ) = ( char ) V_14 ;
V_37 ++ ;
V_36 -- ;
if ( V_14 == '\n' ) {
* ( V_35 + V_37 - 1 ) = '\0' ;
break;
}
}
return V_37 > 0 ? V_37 : V_14 ;
}
static int F_34 ( void * V_41 )
{
T_3 V_42 = NULL ;
void * V_43 ;
F_11 ( & V_1 . V_15 ) ;
if ( V_1 . V_42 ) {
V_1 . V_13 ++ ;
V_42 = V_1 . V_42 ;
V_43 = V_1 . V_43 ;
}
F_12 ( & V_1 . V_15 ) ;
if ( V_42 )
V_42 ( V_43 ) ;
F_11 ( & V_1 . V_15 ) ;
V_1 . V_13 -- ;
if ( ! F_9 () ) {
V_1 . V_2 = NULL ;
F_35 ( & V_1 . V_26 ) ;
}
F_12 ( & V_1 . V_15 ) ;
return 0 ;
}
static int F_36 ( T_3 V_42 , void * V_43 )
{
struct V_44 * V_45 ;
F_11 ( & V_1 . V_15 ) ;
V_1 . V_42 = V_42 ;
V_1 . V_43 = V_43 ;
F_12 ( & V_1 . V_15 ) ;
V_45 = F_37 ( F_34 , NULL , L_1 ) ;
if ( F_38 ( V_45 ) ) {
F_39 ( L_2 ) ;
return F_40 ( V_45 ) ;
}
F_11 ( & V_1 . V_15 ) ;
V_1 . V_2 = V_45 ;
F_41 ( ( V_46 ) ( unsigned long ) V_45 ) ;
F_42 ( V_45 ) ;
F_12 ( & V_1 . V_15 ) ;
return 0 ;
}
static int F_43 ( bool V_47 ,
char * V_48 , T_2 V_49 )
{
T_4 V_50 ;
if ( V_47 )
F_44 ( L_3 , V_51 ) ;
else
F_44 ( L_3 , V_52 ) ;
V_50 = F_45 ( V_48 , V_49 , NULL ) ;
if ( F_46 ( V_50 ) )
return - V_53 ;
return 0 ;
}
static int F_47 ( void )
{
return 0 ;
}
static int F_48 ( struct V_54 * V_54 , struct V_55 * V_55 )
{
int V_14 = 0 ;
T_4 V_50 ;
F_11 ( & V_1 . V_15 ) ;
if ( V_1 . V_4 & V_6 ) {
V_14 = - V_56 ;
goto V_57;
}
if ( ( V_55 -> V_58 & V_59 ) != V_60 ) {
if ( V_61 ) {
V_14 = - V_56 ;
goto V_57;
} else {
F_49 ( L_4 ) ;
V_61 = V_55 ;
}
} else {
if ( ! ( V_1 . V_4 & V_5 ) ) {
V_14 = - V_39 ;
goto V_57;
}
}
if ( V_61 == V_55 ) {
F_49 ( L_5 ) ;
F_12 ( & V_1 . V_15 ) ;
F_49 ( L_6 ) ;
V_50 = F_50 () ;
if ( F_46 ( V_50 ) ) {
F_39 ( L_7 ) ;
V_14 = - V_53 ;
goto V_62;
}
F_49 ( L_8 ) ;
F_11 ( & V_1 . V_15 ) ;
V_1 . V_4 |= V_5 ;
V_1 . V_19 . V_32 = V_1 . V_19 . V_34 = 0 ;
V_1 . V_17 . V_32 = V_1 . V_17 . V_34 = 0 ;
F_49 ( L_9 ) ;
}
V_1 . V_63 ++ ;
V_57:
if ( V_14 < 0 ) {
if ( V_61 == V_55 )
V_61 = NULL ;
}
F_12 ( & V_1 . V_15 ) ;
V_62:
return V_14 ;
}
static int F_51 ( struct V_54 * V_54 , struct V_55 * V_55 )
{
F_11 ( & V_1 . V_15 ) ;
V_1 . V_63 -- ;
if ( V_55 == V_61 ) {
F_49 ( L_10 ) ;
V_61 = NULL ;
F_49 ( L_11 ) ;
V_1 . V_4 |= V_6 ;
F_22 ( & V_1 . V_26 ) ;
F_12 ( & V_1 . V_15 ) ;
F_52 ( V_1 . V_26 , ! F_13 () ) ;
F_49 ( L_12 ) ;
F_53 () ;
F_52 ( V_1 . V_26 , ! F_14 () ) ;
F_49 ( L_13 ) ;
F_11 ( & V_1 . V_15 ) ;
V_1 . V_4 &= ~ V_5 ;
}
if ( V_1 . V_63 == 0 ) {
F_49 ( L_14 ) ;
V_1 . V_4 &= ~ V_6 ;
}
F_12 ( & V_1 . V_15 ) ;
return 0 ;
}
static int F_54 ( char T_5 * V_27 , int V_28 )
{
int V_14 ;
struct V_9 * V_29 = & V_1 . V_19 ;
int V_30 ;
char * V_31 ;
V_14 = F_20 ( V_29 , V_20 ) ;
if ( V_14 < 0 )
return V_14 ;
F_29 () ;
V_31 = & V_29 -> V_27 [ V_29 -> V_34 ] ;
V_30 = F_25 ( V_28 , F_55 ( V_29 ) ) ;
if ( F_56 ( V_27 , V_31 , V_30 ) ) {
V_14 = - V_22 ;
goto V_23;
}
F_24 () ;
V_29 -> V_34 = ( V_29 -> V_34 + V_30 ) & ( V_33 - 1 ) ;
V_14 = V_30 ;
V_23:
F_21 ( V_20 , V_14 >= 0 ) ;
return V_14 ;
}
static T_1 F_57 ( struct V_55 * V_55 , char T_5 * V_27 ,
T_2 V_36 , T_6 * V_64 )
{
int V_14 = 0 ;
int V_37 = 0 ;
if ( ! V_36 )
return 0 ;
if ( ! F_58 ( V_65 , V_27 , V_36 ) )
return - V_22 ;
while ( V_36 > 0 ) {
V_40:
V_14 = F_54 ( V_27 + V_37 , V_36 ) ;
if ( V_14 == - V_24 ) {
if ( V_55 -> V_58 & V_66 )
break;
else {
V_14 = F_31 ( V_1 . V_26 ,
F_17 () ) ;
if ( V_14 == 0 )
goto V_40;
}
}
if ( V_14 < 0 ) {
if ( ! F_10 () )
V_14 = 0 ;
break;
}
if ( V_14 ) {
V_37 += V_14 ;
V_36 -= V_14 ;
* V_64 += V_14 ;
break;
}
}
return V_37 > 0 ? V_37 : V_14 ;
}
static int F_59 ( const char T_5 * V_27 , int V_28 )
{
int V_14 ;
struct V_9 * V_29 = & V_1 . V_17 ;
int V_30 ;
char * V_31 ;
V_14 = F_19 ( V_29 , V_21 ) ;
if ( V_14 < 0 )
return V_14 ;
F_24 () ;
V_31 = & V_29 -> V_27 [ V_29 -> V_32 ] ;
V_30 = F_25 ( V_28 , F_26 ( V_29 ) ) ;
if ( F_60 ( V_31 , V_27 , V_30 ) ) {
V_14 = - V_22 ;
goto V_23;
}
F_27 () ;
V_29 -> V_32 = ( V_29 -> V_32 + V_30 ) & ( V_33 - 1 ) ;
V_14 = V_30 ;
V_23:
F_21 ( V_21 , V_14 >= 0 ) ;
return V_30 ;
}
static T_1 F_61 ( struct V_55 * V_55 , const char T_5 * V_27 ,
T_2 V_36 , T_6 * V_64 )
{
int V_14 = 0 ;
int V_37 = 0 ;
if ( ! V_36 )
return 0 ;
if ( ! F_58 ( V_67 , V_27 , V_36 ) )
return - V_22 ;
while ( V_36 > 0 ) {
V_40:
V_14 = F_59 ( V_27 + V_37 , V_36 ) ;
if ( V_14 == - V_24 ) {
if ( V_55 -> V_58 & V_66 )
break;
else {
V_14 = F_31 ( V_1 . V_26 ,
F_18 () ) ;
if ( V_14 == 0 )
goto V_40;
}
}
if ( V_14 < 0 ) {
if ( ! F_10 () )
V_14 = 0 ;
break;
}
if ( V_14 ) {
V_37 += V_14 ;
V_36 -= V_14 ;
* V_64 += V_14 ;
}
}
return V_37 > 0 ? V_37 : V_14 ;
}
static unsigned int F_62 ( struct V_55 * V_55 , T_7 * V_26 )
{
int V_68 = 0 ;
F_63 ( V_55 , & V_1 . V_26 , V_26 ) ;
if ( F_17 () )
V_68 |= V_69 | V_70 ;
if ( F_18 () )
V_68 |= V_71 | V_72 ;
return V_68 ;
}
int T_8 F_64 ( void )
{
int V_14 = 0 ;
if ( ! V_73 ) {
V_14 = - V_74 ;
goto V_62;
}
F_65 ( & V_1 . V_15 ) ;
F_66 ( & V_1 . V_26 ) ;
V_1 . V_19 . V_27 = V_1 . V_75 ;
V_1 . V_17 . V_27 = V_1 . V_76 ;
V_77 = F_67 ( L_15 ,
V_78 | V_79 | V_80 ,
V_73 , NULL ,
& V_81 ) ;
if ( V_77 == NULL ) {
V_14 = - V_39 ;
goto V_62;
}
V_14 = F_68 ( V_82 , & V_83 ) ;
if ( V_14 )
goto V_84;
V_38 = true ;
V_84:
if ( V_14 ) {
F_69 ( V_77 ) ;
V_77 = NULL ;
}
V_62:
return V_14 ;
}
void T_9 F_70 ( void )
{
if ( V_38 ) {
F_71 ( & V_83 ) ;
if ( V_77 ) {
F_69 ( V_77 ) ;
V_77 = NULL ;
}
V_38 = false ;
}
}
