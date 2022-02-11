static bool F_1 ( struct V_1 * V_2 )
{
return ( V_2 -> V_3 == 1 ) ;
}
static void F_2 ( void )
{
if ( V_4 || F_3 () )
F_4 ( 0 ) ;
}
static int F_5 ( struct V_5 * V_6 , int V_7 )
{
int V_8 , V_9 , V_10 , V_11 , V_12 = 0 ;
unsigned int V_13 ;
struct V_14 * V_15 ;
F_6 ( ! F_7 ( & V_6 -> V_16 ) ) ;
V_15 = F_8 ( V_6 -> V_16 . V_17 , struct V_14 , V_18 ) ;
F_6 ( V_15 -> V_13 ) ;
F_6 ( V_15 -> V_19 . V_20 ) ;
F_6 ( V_15 -> V_21 ) ;
V_8 = F_9 ( & V_6 -> V_6 ) ;
V_13 = F_10 ( F_11 () , V_7 , V_8 ) ;
if ( V_13 == 0 )
return - V_22 ;
V_11 = F_12 ( V_7 ) ;
V_15 -> V_21 = V_7 ;
V_15 -> V_19 . V_20 = F_13 ( V_11 ) ;
for ( V_10 = 0 ; V_10 < V_7 ; V_10 ++ ) {
if ( ! V_10 ) {
V_12 = F_14 ( V_6 , V_13 , V_11 ) ;
if ( V_12 < 0 ) {
V_9 = V_12 ;
goto error;
}
} else {
V_9 = F_15 ( V_6 , V_13 + V_10 ,
V_12 , V_10 ) ;
if ( V_9 < 0 )
goto error;
}
V_9 = F_16 ( V_6 , V_15 , V_13 , V_10 ) ;
if ( V_9 < 0 )
goto error;
}
return 0 ;
error:
F_17 ( V_13 , V_7 ) ;
V_15 -> V_13 = 0 ;
V_15 -> V_21 = 0 ;
V_15 -> V_19 . V_20 = 0 ;
return V_9 ;
}
static int F_18 ( struct V_5 * V_6 , int V_7 )
{
int V_8 , V_9 , V_10 , V_12 = 0 ;
struct V_14 * V_15 ;
unsigned int V_13 ;
V_8 = F_9 ( & V_6 -> V_6 ) ;
V_13 = F_11 () ;
V_10 = 0 ;
F_19 (msidesc, &dev->msi_list, list) {
V_13 = F_20 ( V_13 , V_8 ) ;
if ( V_13 == 0 )
return - 1 ;
if ( V_10 == 0 )
V_9 = V_12 = F_14 ( V_6 , V_13 , V_7 ) ;
else
V_9 = F_15 ( V_6 , V_13 , V_12 , V_10 ) ;
if ( V_9 < 0 )
goto error;
V_9 = F_16 ( V_6 , V_15 , V_13 , 0 ) ;
if ( V_9 < 0 )
goto error;
V_10 += 1 ;
V_13 += 1 ;
}
return 0 ;
error:
F_21 ( V_13 ) ;
return V_9 ;
}
static int F_22 ( struct V_5 * V_6 ,
int V_7 , int type )
{
if ( type == V_23 )
return F_5 ( V_6 , V_7 ) ;
else
return F_18 ( V_6 , V_7 ) ;
}
static void F_23 ( int V_24 , int V_25 , int V_26 )
{
F_24 ( V_24 , V_25 ) ;
}
static void T_1 F_25 ( void )
{
V_27 . V_28 = F_2 ;
V_27 . V_29 = V_30 ;
V_27 . V_31 = V_32 ;
V_27 . V_33 = F_23 ;
V_34 . V_35 = F_22 ;
V_34 . V_36 = V_37 ;
V_34 . V_38 = V_39 ;
}
static T_1 int F_26 ( char * V_40 )
{
V_41 = 1 ;
return 0 ;
}
static T_1 int F_27 ( char * V_40 )
{
if ( ! V_40 )
return - V_42 ;
while ( * V_40 ) {
if ( ! strncmp ( V_40 , L_1 , 2 ) )
V_41 = 0 ;
else if ( ! strncmp ( V_40 , L_2 , 3 ) )
V_41 = 1 ;
else if ( ! strncmp ( V_40 , L_3 , 5 ) )
V_43 = 1 ;
else if ( ! strncmp ( V_40 , L_4 , 16 ) )
V_44 = 1 ;
V_40 += strcspn ( V_40 , L_5 ) ;
while ( * V_40 == ',' )
V_40 ++ ;
}
return 0 ;
}
void T_1 F_28 ( void )
{
V_45 = & V_46 ;
#ifdef F_29
if ( V_47 . V_48 () == 0 )
V_45 = & V_47 ;
#endif
}
void F_30 ( void )
{
V_49 = 1 ;
}
int F_31 ( void )
{
if ( V_41 )
return 0 ;
if ( ! V_45 || ! V_45 -> V_50 )
return 0 ;
return V_45 -> V_50 () ;
}
int T_1 F_32 ( void )
{
if ( ! V_45 || ! V_45 -> V_48 )
return - V_51 ;
return V_45 -> V_48 () ;
}
int T_1 F_33 ( void )
{
int V_9 ;
if ( ! V_45 || ! V_45 -> V_52 )
return - V_51 ;
V_9 = V_45 -> V_52 () ;
if ( V_53 )
F_25 () ;
return V_9 ;
}
void F_34 ( void )
{
if ( ! V_53 ||
! V_45 ||
! V_45 -> V_28 )
return;
V_45 -> V_28 () ;
}
int F_35 ( int V_54 )
{
if ( ! V_53 ||
! V_45 ||
! V_45 -> V_55 )
return 0 ;
return V_45 -> V_55 ( V_54 ) ;
}
int T_1 F_36 ( void )
{
if ( ! V_53 )
return 0 ;
if ( ! V_45 || ! V_45 -> V_56 )
return - V_51 ;
return V_45 -> V_56 () ;
}
int V_32 ( int V_13 ,
struct V_57 * V_58 ,
unsigned int V_59 , int V_26 ,
struct V_60 * V_61 )
{
if ( ! V_45 || ! V_45 -> V_62 )
return - V_51 ;
return V_45 -> V_62 ( V_13 , V_58 , V_59 ,
V_26 , V_61 ) ;
}
static int V_30 ( struct V_63 * V_64 ,
const struct V_65 * V_66 , bool V_67 )
{
if ( ! F_37 ( V_68 ) || ! V_45 ||
! V_45 -> V_29 )
return 0 ;
return V_45 -> V_29 ( V_64 , V_66 , V_67 ) ;
}
void F_38 ( int V_13 )
{
struct V_1 * V_2 = F_39 ( V_13 ) ;
if ( ! V_45 || ! V_45 -> V_69 )
return;
if ( F_1 ( V_2 ) )
V_45 -> V_69 ( V_13 ) ;
}
void V_39 ( struct V_5 * V_70 ,
unsigned int V_13 , unsigned int V_71 ,
struct V_72 * V_73 , T_2 V_74 )
{
struct V_1 * V_2 = F_39 ( V_13 ) ;
if ( ! F_1 ( V_2 ) )
F_40 ( V_70 , V_13 , V_71 , V_73 , V_74 ) ;
else if ( V_45 && V_45 -> V_38 )
V_45 -> V_38 ( V_70 , V_13 , V_71 , V_73 , V_74 ) ;
}
static int F_14 ( struct V_5 * V_70 , int V_13 , int V_7 )
{
if ( ! V_45 || ! V_45 -> V_75 )
return - V_51 ;
return V_45 -> V_75 ( V_70 , V_13 , V_7 ) ;
}
static int F_15 ( struct V_5 * V_70 , unsigned int V_13 ,
int V_12 , int V_10 )
{
if ( ! V_45 || ! V_45 -> V_76 )
return - V_51 ;
return V_45 -> V_76 ( V_70 , V_13 , V_12 , V_10 ) ;
}
int V_37 ( unsigned int V_13 , unsigned int V_77 )
{
if ( ! V_45 || ! V_45 -> V_36 )
return - V_51 ;
return V_45 -> V_36 ( V_13 , V_77 ) ;
}
void F_41 ( const char * V_73 )
{
if ( V_53 )
F_42 ( V_73 ) ;
}
static void F_43 ( struct V_63 * V_64 )
{
F_44 () ;
}
static void F_45 ( struct V_63 * V_64 )
{
F_44 () ;
F_46 ( V_64 -> V_13 , V_64 -> V_78 ) ;
}
static void F_47 ( struct V_63 * V_64 , struct V_79 * V_80 )
{
F_48 ( V_80 , L_6 , V_64 -> V_81 -> V_82 ) ;
}
void F_49 ( struct V_83 * V_81 )
{
V_81 -> V_84 = F_47 ;
V_81 -> V_85 = F_43 ;
V_81 -> V_86 = F_45 ;
V_81 -> V_87 = V_27 . V_29 ;
}
bool F_50 ( int V_13 , struct V_1 * V_2 , struct V_83 * V_81 )
{
if ( ! F_1 ( V_2 ) )
return false ;
F_51 ( V_13 , V_88 ) ;
F_49 ( V_81 ) ;
return true ;
}
