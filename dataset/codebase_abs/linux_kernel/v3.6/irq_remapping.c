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
}
int F_4 ( void )
{
if ( V_2 )
return 0 ;
if ( ! V_6 || ! V_6 -> V_8 )
return 0 ;
return V_6 -> V_8 () ;
}
int T_1 F_5 ( void )
{
if ( ! V_6 || ! V_6 -> V_9 )
return - V_10 ;
return V_6 -> V_9 () ;
}
int T_1 F_6 ( void )
{
if ( ! V_6 || ! V_6 -> V_11 )
return - V_10 ;
return V_6 -> V_11 () ;
}
void F_7 ( void )
{
if ( ! V_6 || ! V_6 -> V_12 )
return;
V_6 -> V_12 () ;
}
int F_8 ( int V_13 )
{
if ( ! V_6 || ! V_6 -> V_14 )
return 0 ;
return V_6 -> V_14 ( V_13 ) ;
}
int T_1 F_9 ( void )
{
if ( ! V_6 || ! V_6 -> V_15 )
return - V_10 ;
return V_6 -> V_15 () ;
}
int F_10 ( int V_16 ,
struct V_17 * V_18 ,
unsigned int V_19 , int V_20 ,
struct V_21 * V_22 )
{
if ( ! V_6 || ! V_6 -> V_23 )
return - V_10 ;
return V_6 -> V_23 ( V_16 , V_18 , V_19 ,
V_20 , V_22 ) ;
}
int F_11 ( struct V_24 * V_25 , const struct V_26 * V_27 ,
bool V_28 )
{
if ( ! F_12 ( V_29 ) || ! V_6 ||
! V_6 -> V_30 )
return 0 ;
return V_6 -> V_30 ( V_25 , V_27 , V_28 ) ;
}
void F_13 ( int V_16 )
{
if ( ! V_6 || ! V_6 -> V_31 )
return;
V_6 -> V_31 ( V_16 ) ;
}
void F_14 ( struct V_32 * V_33 ,
unsigned int V_16 , unsigned int V_34 ,
struct V_35 * V_36 , T_2 V_37 )
{
if ( ! V_6 || ! V_6 -> V_38 )
return;
V_6 -> V_38 ( V_33 , V_16 , V_34 , V_36 , V_37 ) ;
}
int F_15 ( struct V_32 * V_33 , int V_16 , int V_39 )
{
if ( ! V_6 || ! V_6 -> V_40 )
return - V_10 ;
return V_6 -> V_40 ( V_33 , V_16 , V_39 ) ;
}
int F_16 ( struct V_32 * V_33 , unsigned int V_16 ,
int V_41 , int V_42 )
{
if ( ! V_6 || ! V_6 -> V_43 )
return - V_10 ;
return V_6 -> V_43 ( V_33 , V_16 , V_41 , V_42 ) ;
}
int F_17 ( unsigned int V_16 , unsigned int V_44 )
{
if ( ! V_6 || ! V_6 -> V_45 )
return - V_10 ;
return V_6 -> V_45 ( V_16 , V_44 ) ;
}
