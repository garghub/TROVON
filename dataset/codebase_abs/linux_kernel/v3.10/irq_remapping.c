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
int V_8 , V_9 , V_10 , V_11 = 0 ;
unsigned int V_12 ;
struct V_13 * V_14 ;
V_7 = F_6 ( V_7 ) ;
F_7 ( ! F_8 ( & V_6 -> V_15 ) ) ;
V_14 = F_9 ( V_6 -> V_15 . V_16 , struct V_13 , V_17 ) ;
F_7 ( V_14 -> V_12 ) ;
F_7 ( V_14 -> V_18 . V_19 ) ;
V_8 = F_10 ( & V_6 -> V_6 ) ;
V_12 = F_11 ( F_12 () , V_7 , V_8 ) ;
if ( V_12 == 0 )
return - V_20 ;
V_14 -> V_18 . V_19 = F_13 ( V_7 ) ;
for ( V_10 = 0 ; V_10 < V_7 ; V_10 ++ ) {
if ( ! V_10 ) {
V_11 = F_14 ( V_6 , V_12 , V_7 ) ;
if ( V_11 < 0 ) {
V_9 = V_11 ;
goto error;
}
} else {
V_9 = F_15 ( V_6 , V_12 + V_10 ,
V_11 , V_10 ) ;
if ( V_9 < 0 )
goto error;
}
V_9 = F_16 ( V_6 , V_14 , V_12 , V_10 ) ;
if ( V_9 < 0 )
goto error;
}
return 0 ;
error:
F_17 ( V_12 , V_7 ) ;
V_14 -> V_12 = 0 ;
V_14 -> V_18 . V_19 = 0 ;
return V_9 ;
}
static int F_18 ( struct V_5 * V_6 , int V_7 )
{
int V_8 , V_9 , V_10 , V_11 = 0 ;
struct V_13 * V_14 ;
unsigned int V_12 ;
V_8 = F_10 ( & V_6 -> V_6 ) ;
V_12 = F_12 () ;
V_10 = 0 ;
F_19 (msidesc, &dev->msi_list, list) {
V_12 = F_20 ( V_12 , V_8 ) ;
if ( V_12 == 0 )
return - 1 ;
if ( V_10 == 0 )
V_9 = V_11 = F_14 ( V_6 , V_12 , V_7 ) ;
else
V_9 = F_15 ( V_6 , V_12 , V_11 , V_10 ) ;
if ( V_9 < 0 )
goto error;
V_9 = F_16 ( V_6 , V_14 , V_12 , 0 ) ;
if ( V_9 < 0 )
goto error;
V_10 += 1 ;
V_12 += 1 ;
}
return 0 ;
error:
F_21 ( V_12 ) ;
return V_9 ;
}
static int F_22 ( struct V_5 * V_6 ,
int V_7 , int type )
{
if ( type == V_21 )
return F_5 ( V_6 , V_7 ) ;
else
return F_18 ( V_6 , V_7 ) ;
}
void F_23 ( int V_22 , int V_23 , int V_24 )
{
F_24 ( V_22 , V_23 ) ;
}
static void T_1 F_25 ( void )
{
V_25 . V_26 = F_2 ;
V_25 . V_27 = V_28 ;
V_25 . V_29 = V_30 ;
V_25 . V_31 = F_23 ;
V_32 . V_33 = F_22 ;
V_32 . V_34 = V_35 ;
V_32 . V_36 = V_37 ;
}
static T_1 int F_26 ( char * V_38 )
{
V_39 = 1 ;
return 0 ;
}
static T_1 int F_27 ( char * V_38 )
{
if ( ! V_38 )
return - V_40 ;
while ( * V_38 ) {
if ( ! strncmp ( V_38 , L_1 , 2 ) )
V_39 = 0 ;
else if ( ! strncmp ( V_38 , L_2 , 3 ) )
V_39 = 1 ;
else if ( ! strncmp ( V_38 , L_3 , 5 ) )
V_41 = 1 ;
else if ( ! strncmp ( V_38 , L_4 , 16 ) )
V_42 = 1 ;
V_38 += strcspn ( V_38 , L_5 ) ;
while ( * V_38 == ',' )
V_38 ++ ;
}
return 0 ;
}
void T_1 F_28 ( void )
{
V_43 = & V_44 ;
#ifdef F_29
if ( V_45 . V_46 () == 0 )
V_43 = & V_45 ;
#endif
}
void F_30 ( void )
{
V_47 = 1 ;
}
int F_31 ( void )
{
if ( V_39 )
return 0 ;
if ( ! V_43 || ! V_43 -> V_48 )
return 0 ;
return V_43 -> V_48 () ;
}
int T_1 F_32 ( void )
{
if ( ! V_43 || ! V_43 -> V_46 )
return - V_49 ;
return V_43 -> V_46 () ;
}
int T_1 F_33 ( void )
{
int V_9 ;
if ( ! V_43 || ! V_43 -> V_50 )
return - V_49 ;
V_9 = V_43 -> V_50 () ;
if ( V_51 )
F_25 () ;
return V_9 ;
}
void F_34 ( void )
{
if ( ! V_51 ||
! V_43 ||
! V_43 -> V_26 )
return;
V_43 -> V_26 () ;
}
int F_35 ( int V_52 )
{
if ( ! V_51 ||
! V_43 ||
! V_43 -> V_53 )
return 0 ;
return V_43 -> V_53 ( V_52 ) ;
}
int T_1 F_36 ( void )
{
if ( ! V_51 )
return 0 ;
if ( ! V_43 || ! V_43 -> V_54 )
return - V_49 ;
return V_43 -> V_54 () ;
}
int V_30 ( int V_12 ,
struct V_55 * V_56 ,
unsigned int V_57 , int V_24 ,
struct V_58 * V_59 )
{
if ( ! V_43 || ! V_43 -> V_60 )
return - V_49 ;
return V_43 -> V_60 ( V_12 , V_56 , V_57 ,
V_24 , V_59 ) ;
}
int V_28 ( struct V_61 * V_62 , const struct V_63 * V_64 ,
bool V_65 )
{
if ( ! F_37 ( V_66 ) || ! V_43 ||
! V_43 -> V_27 )
return 0 ;
return V_43 -> V_27 ( V_62 , V_64 , V_65 ) ;
}
void F_38 ( int V_12 )
{
struct V_1 * V_2 = F_39 ( V_12 ) ;
if ( ! V_43 || ! V_43 -> V_67 )
return;
if ( F_1 ( V_2 ) )
V_43 -> V_67 ( V_12 ) ;
}
void V_37 ( struct V_5 * V_68 ,
unsigned int V_12 , unsigned int V_69 ,
struct V_70 * V_71 , T_2 V_72 )
{
struct V_1 * V_2 = F_39 ( V_12 ) ;
if ( ! F_1 ( V_2 ) )
F_40 ( V_68 , V_12 , V_69 , V_71 , V_72 ) ;
else if ( V_43 && V_43 -> V_36 )
V_43 -> V_36 ( V_68 , V_12 , V_69 , V_71 , V_72 ) ;
}
static int F_14 ( struct V_5 * V_68 , int V_12 , int V_7 )
{
if ( ! V_43 || ! V_43 -> V_73 )
return - V_49 ;
return V_43 -> V_73 ( V_68 , V_12 , V_7 ) ;
}
static int F_15 ( struct V_5 * V_68 , unsigned int V_12 ,
int V_11 , int V_10 )
{
if ( ! V_43 || ! V_43 -> V_74 )
return - V_49 ;
return V_43 -> V_74 ( V_68 , V_12 , V_11 , V_10 ) ;
}
int V_35 ( unsigned int V_12 , unsigned int V_75 )
{
if ( ! V_43 || ! V_43 -> V_34 )
return - V_49 ;
return V_43 -> V_34 ( V_12 , V_75 ) ;
}
void F_41 ( const char * V_71 )
{
if ( V_51 )
F_42 ( V_71 ) ;
}
static void F_43 ( struct V_61 * V_62 )
{
F_44 () ;
}
static void F_45 ( struct V_61 * V_62 )
{
F_44 () ;
F_46 ( V_62 -> V_12 , V_62 -> V_76 ) ;
}
static void F_47 ( struct V_61 * V_62 , struct V_77 * V_78 )
{
F_48 ( V_78 , L_6 , V_62 -> V_79 -> V_80 ) ;
}
void F_49 ( struct V_81 * V_79 )
{
V_79 -> V_82 = F_47 ;
V_79 -> V_83 = F_43 ;
V_79 -> V_84 = F_45 ;
V_79 -> V_85 = V_25 . V_27 ;
}
bool F_50 ( int V_12 , struct V_1 * V_2 , struct V_81 * V_79 )
{
if ( ! F_1 ( V_2 ) )
return false ;
F_51 ( V_12 , V_86 ) ;
F_49 ( V_79 ) ;
return true ;
}
