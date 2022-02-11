static void F_1 ( void )
{
if ( V_1 || F_2 () )
F_3 ( 0 ) ;
}
static void T_1 F_4 ( void )
{
V_2 . V_3 = F_1 ;
}
static T_1 int F_5 ( char * V_4 )
{
V_5 = 1 ;
return 0 ;
}
static T_1 int F_6 ( char * V_4 )
{
if ( ! V_4 )
return - V_6 ;
while ( * V_4 ) {
if ( ! strncmp ( V_4 , L_1 , 2 ) ) {
V_5 = 0 ;
V_7 = 0 ;
} else if ( ! strncmp ( V_4 , L_2 , 3 ) ) {
V_5 = 1 ;
V_7 = 1 ;
} else if ( ! strncmp ( V_4 , L_3 , 5 ) )
V_8 = 1 ;
else if ( ! strncmp ( V_4 , L_4 , 16 ) )
V_9 = 1 ;
else if ( ! strncmp ( V_4 , L_5 , 6 ) )
V_7 = 1 ;
V_4 += strcspn ( V_4 , L_6 ) ;
while ( * V_4 == ',' )
V_4 ++ ;
}
return 0 ;
}
void F_7 ( void )
{
V_10 = 1 ;
}
bool F_8 ( enum V_11 V_12 )
{
if ( ! V_13 || V_7 )
return false ;
return ( V_13 -> V_14 & ( 1 << V_12 ) ) ;
}
int T_1 F_9 ( void )
{
if ( V_5 )
return - V_15 ;
if ( V_16 . V_17 () == 0 )
V_13 = & V_16 ;
else if ( F_10 ( V_18 ) &&
V_19 . V_17 () == 0 )
V_13 = & V_19 ;
else
return - V_15 ;
return 0 ;
}
int T_1 F_11 ( void )
{
int V_20 ;
if ( ! V_13 -> V_21 )
return - V_22 ;
V_20 = V_13 -> V_21 () ;
if ( V_23 )
F_4 () ;
return V_20 ;
}
void F_12 ( void )
{
if ( V_23 && V_13 -> V_3 )
V_13 -> V_3 () ;
}
int F_13 ( int V_24 )
{
if ( V_23 && V_13 -> V_25 )
return V_13 -> V_25 ( V_24 ) ;
return 0 ;
}
int T_1 F_14 ( void )
{
if ( ! V_23 )
return 0 ;
if ( ! V_13 -> V_26 )
return - V_22 ;
return V_13 -> V_26 () ;
}
void F_15 ( const char * V_27 )
{
if ( V_23 )
F_16 ( V_27 ) ;
}
void F_17 ( struct V_28 * V_29 )
{
F_18 () ;
}
struct V_30 *
F_19 ( struct V_31 * V_32 )
{
if ( ! V_13 || ! V_13 -> V_33 )
return NULL ;
return V_13 -> V_33 ( V_32 ) ;
}
struct V_30 *
F_20 ( struct V_31 * V_32 )
{
if ( ! V_13 || ! V_13 -> V_34 )
return NULL ;
return V_13 -> V_34 ( V_32 ) ;
}
