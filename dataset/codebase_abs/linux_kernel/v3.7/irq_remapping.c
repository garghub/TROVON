static T_1 int F_1 ( char * V_1 )
{
V_2 = 1 ;
return 0 ;
}
static T_1 int F_2 ( char * V_1 )
{
if ( ! V_1 )
return - V_3 ;
while ( * V_1 ) {
if ( ! strncmp ( V_1 , L_1 , 2 ) )
V_2 = 0 ;
else if ( ! strncmp ( V_1 , L_2 , 3 ) )
V_2 = 1 ;
else if ( ! strncmp ( V_1 , L_3 , 5 ) )
V_4 = 1 ;
else if ( ! strncmp ( V_1 , L_4 , 16 ) )
V_5 = 1 ;
V_1 += strcspn ( V_1 , L_5 ) ;
while ( * V_1 == ',' )
V_1 ++ ;
}
return 0 ;
}
void T_1 F_3 ( void )
{
V_6 = & V_7 ;
#ifdef F_4
if ( V_8 . V_9 () == 0 )
V_6 = & V_8 ;
#endif
}
int F_5 ( void )
{
if ( V_2 )
return 0 ;
if ( ! V_6 || ! V_6 -> V_10 )
return 0 ;
return V_6 -> V_10 () ;
}
int T_1 F_6 ( void )
{
if ( ! V_6 || ! V_6 -> V_9 )
return - V_11 ;
return V_6 -> V_9 () ;
}
int T_1 F_7 ( void )
{
if ( ! V_6 || ! V_6 -> V_12 )
return - V_11 ;
return V_6 -> V_12 () ;
}
void F_8 ( void )
{
if ( ! V_6 || ! V_6 -> V_13 )
return;
V_6 -> V_13 () ;
}
int F_9 ( int V_14 )
{
if ( ! V_6 || ! V_6 -> V_15 )
return 0 ;
return V_6 -> V_15 ( V_14 ) ;
}
int T_1 F_10 ( void )
{
if ( ! V_6 || ! V_6 -> V_16 )
return - V_11 ;
return V_6 -> V_16 () ;
}
int F_11 ( int V_17 ,
struct V_18 * V_19 ,
unsigned int V_20 , int V_21 ,
struct V_22 * V_23 )
{
if ( ! V_6 || ! V_6 -> V_24 )
return - V_11 ;
return V_6 -> V_24 ( V_17 , V_19 , V_20 ,
V_21 , V_23 ) ;
}
int F_12 ( struct V_25 * V_26 , const struct V_27 * V_28 ,
bool V_29 )
{
if ( ! F_13 ( V_30 ) || ! V_6 ||
! V_6 -> V_31 )
return 0 ;
return V_6 -> V_31 ( V_26 , V_28 , V_29 ) ;
}
void F_14 ( int V_17 )
{
if ( ! V_6 || ! V_6 -> V_32 )
return;
V_6 -> V_32 ( V_17 ) ;
}
void F_15 ( struct V_33 * V_34 ,
unsigned int V_17 , unsigned int V_35 ,
struct V_36 * V_37 , T_2 V_38 )
{
if ( ! V_6 || ! V_6 -> V_39 )
return;
V_6 -> V_39 ( V_34 , V_17 , V_35 , V_37 , V_38 ) ;
}
int F_16 ( struct V_33 * V_34 , int V_17 , int V_40 )
{
if ( ! V_6 || ! V_6 -> V_41 )
return - V_11 ;
return V_6 -> V_41 ( V_34 , V_17 , V_40 ) ;
}
int F_17 ( struct V_33 * V_34 , unsigned int V_17 ,
int V_42 , int V_43 )
{
if ( ! V_6 || ! V_6 -> V_44 )
return - V_11 ;
return V_6 -> V_44 ( V_34 , V_17 , V_42 , V_43 ) ;
}
int F_18 ( unsigned int V_17 , unsigned int V_45 )
{
if ( ! V_6 || ! V_6 -> V_46 )
return - V_11 ;
return V_6 -> V_46 ( V_17 , V_45 ) ;
}
