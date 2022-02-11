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
V_14 = F_6 ( V_6 -> V_15 . V_16 , struct V_13 , V_17 ) ;
V_12 = F_7 ( V_7 , F_8 ( & V_6 -> V_6 ) ) ;
if ( V_12 == 0 )
return - V_18 ;
V_10 = F_9 ( V_7 ) ;
for ( V_9 = 0 ; V_9 < V_7 ; V_9 ++ ) {
if ( ! V_9 ) {
V_11 = F_10 ( V_6 , V_12 , V_10 ) ;
if ( V_11 < 0 ) {
V_8 = V_11 ;
goto error;
}
} else {
V_8 = F_11 ( V_6 , V_12 + V_9 ,
V_11 , V_9 ) ;
if ( V_8 < 0 )
goto error;
}
V_8 = F_12 ( V_6 , V_14 , V_12 , V_9 ) ;
if ( V_8 < 0 )
goto error;
}
return 0 ;
error:
F_13 ( V_12 , V_7 ) ;
V_14 -> V_12 = 0 ;
return V_8 ;
}
static int F_14 ( struct V_5 * V_6 , int V_7 )
{
int V_19 , V_8 , V_9 , V_11 = 0 ;
struct V_13 * V_14 ;
unsigned int V_12 ;
V_19 = F_8 ( & V_6 -> V_6 ) ;
V_9 = 0 ;
F_15 (msidesc, &dev->msi_list, list) {
V_12 = F_16 ( V_19 ) ;
if ( V_12 == 0 )
return - 1 ;
if ( V_9 == 0 )
V_8 = V_11 = F_10 ( V_6 , V_12 , V_7 ) ;
else
V_8 = F_11 ( V_6 , V_12 , V_11 , V_9 ) ;
if ( V_8 < 0 )
goto error;
V_8 = F_12 ( V_6 , V_14 , V_12 , 0 ) ;
if ( V_8 < 0 )
goto error;
V_9 += 1 ;
V_12 += 1 ;
}
return 0 ;
error:
F_17 ( V_12 ) ;
return V_8 ;
}
static int F_18 ( struct V_5 * V_6 ,
int V_7 , int type )
{
if ( type == V_20 )
return F_5 ( V_6 , V_7 ) ;
else
return F_14 ( V_6 , V_7 ) ;
}
static void F_19 ( int V_21 , int V_22 , int V_23 )
{
F_20 ( V_21 , V_22 ) ;
}
static void T_1 F_21 ( void )
{
V_24 . V_25 = F_2 ;
V_24 . V_26 = V_27 ;
V_24 . V_28 = V_29 ;
V_24 . V_30 = F_19 ;
V_31 . V_32 = F_18 ;
V_31 . V_33 = V_34 ;
V_31 . V_35 = V_36 ;
}
static T_1 int F_22 ( char * V_37 )
{
V_38 = 1 ;
return 0 ;
}
static T_1 int F_23 ( char * V_37 )
{
if ( ! V_37 )
return - V_39 ;
while ( * V_37 ) {
if ( ! strncmp ( V_37 , L_1 , 2 ) )
V_38 = 0 ;
else if ( ! strncmp ( V_37 , L_2 , 3 ) )
V_38 = 1 ;
else if ( ! strncmp ( V_37 , L_3 , 5 ) )
V_40 = 1 ;
else if ( ! strncmp ( V_37 , L_4 , 16 ) )
V_41 = 1 ;
V_37 += strcspn ( V_37 , L_5 ) ;
while ( * V_37 == ',' )
V_37 ++ ;
}
return 0 ;
}
void T_1 F_24 ( void )
{
V_42 = & V_43 ;
#ifdef F_25
if ( V_44 . V_45 () == 0 )
V_42 = & V_44 ;
#endif
}
void F_26 ( void )
{
V_46 = 1 ;
}
int F_27 ( void )
{
if ( V_38 )
return 0 ;
if ( ! V_42 || ! V_42 -> V_47 )
return 0 ;
return V_42 -> V_47 () ;
}
int T_1 F_28 ( void )
{
if ( ! V_42 || ! V_42 -> V_45 )
return - V_48 ;
return V_42 -> V_45 () ;
}
int T_1 F_29 ( void )
{
int V_8 ;
if ( ! V_42 || ! V_42 -> V_49 )
return - V_48 ;
V_8 = V_42 -> V_49 () ;
if ( V_50 )
F_21 () ;
return V_8 ;
}
void F_30 ( void )
{
if ( ! V_50 ||
! V_42 ||
! V_42 -> V_25 )
return;
V_42 -> V_25 () ;
}
int F_31 ( int V_51 )
{
if ( ! V_50 ||
! V_42 ||
! V_42 -> V_52 )
return 0 ;
return V_42 -> V_52 ( V_51 ) ;
}
int T_1 F_32 ( void )
{
if ( ! V_50 )
return 0 ;
if ( ! V_42 || ! V_42 -> V_53 )
return - V_48 ;
return V_42 -> V_53 () ;
}
int V_29 ( int V_12 ,
struct V_54 * V_55 ,
unsigned int V_56 , int V_23 ,
struct V_57 * V_58 )
{
if ( ! V_42 || ! V_42 -> V_59 )
return - V_48 ;
return V_42 -> V_59 ( V_12 , V_55 , V_56 ,
V_23 , V_58 ) ;
}
static int V_27 ( struct V_60 * V_61 ,
const struct V_62 * V_63 , bool V_64 )
{
if ( ! F_33 ( V_65 ) || ! V_42 ||
! V_42 -> V_26 )
return 0 ;
return V_42 -> V_26 ( V_61 , V_63 , V_64 ) ;
}
void F_34 ( int V_12 )
{
struct V_1 * V_2 = V_1 ( V_12 ) ;
if ( ! V_42 || ! V_42 -> V_66 )
return;
if ( F_1 ( V_2 ) )
V_42 -> V_66 ( V_12 ) ;
}
void V_36 ( struct V_5 * V_67 ,
unsigned int V_12 , unsigned int V_68 ,
struct V_69 * V_70 , T_2 V_71 )
{
struct V_1 * V_2 = V_1 ( V_12 ) ;
if ( ! F_1 ( V_2 ) )
F_35 ( V_67 , V_12 , V_68 , V_70 , V_71 ) ;
else if ( V_42 && V_42 -> V_35 )
V_42 -> V_35 ( V_67 , V_12 , V_68 , V_70 , V_71 ) ;
}
static int F_10 ( struct V_5 * V_67 , int V_12 , int V_7 )
{
if ( ! V_42 || ! V_42 -> V_72 )
return - V_48 ;
return V_42 -> V_72 ( V_67 , V_12 , V_7 ) ;
}
static int F_11 ( struct V_5 * V_67 , unsigned int V_12 ,
int V_11 , int V_9 )
{
if ( ! V_42 || ! V_42 -> V_73 )
return - V_48 ;
return V_42 -> V_73 ( V_67 , V_12 , V_11 , V_9 ) ;
}
int V_34 ( unsigned int V_12 , unsigned int V_74 )
{
int V_8 ;
if ( ! V_42 || ! V_42 -> V_75 )
return - V_48 ;
V_8 = V_42 -> V_75 ( V_12 , V_74 ) ;
if ( V_8 )
return - V_39 ;
return F_36 ( V_12 , V_74 ) ;
}
void F_37 ( const char * V_70 )
{
if ( V_50 )
F_38 ( V_70 ) ;
}
static void F_39 ( struct V_60 * V_61 )
{
F_40 () ;
}
static void F_41 ( struct V_60 * V_61 )
{
F_40 () ;
F_42 ( V_61 -> V_12 , F_43 ( V_61 ) ) ;
}
static void F_44 ( struct V_60 * V_61 , struct V_76 * V_77 )
{
F_45 ( V_77 , L_6 , V_61 -> V_78 -> V_79 ) ;
}
void F_46 ( struct V_80 * V_78 )
{
V_78 -> V_81 = F_44 ;
V_78 -> V_82 = F_39 ;
V_78 -> V_83 = F_41 ;
V_78 -> V_84 = V_24 . V_26 ;
}
bool F_47 ( int V_12 , struct V_1 * V_2 , struct V_80 * V_78 )
{
if ( ! F_1 ( V_2 ) )
return false ;
F_48 ( V_12 , V_85 ) ;
F_46 ( V_78 ) ;
return true ;
}
