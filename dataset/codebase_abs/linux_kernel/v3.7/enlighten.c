int F_1 ( struct V_1 * V_2 ,
unsigned long V_3 ,
unsigned long V_4 , int V_5 ,
T_1 V_6 , unsigned V_7 )
{
return - V_8 ;
}
static int T_2 F_2 ( void )
{
struct V_9 V_10 ;
static struct V_11 * V_12 = 0 ;
struct V_13 * V_14 ;
int V_15 ;
const char * V_16 = NULL ;
const char * V_17 = NULL ;
const char * V_18 = L_1 ;
struct V_19 V_20 ;
V_14 = F_3 ( NULL , NULL , L_2 ) ;
if ( ! V_14 ) {
F_4 ( L_3 ) ;
return 0 ;
}
V_16 = F_5 ( V_14 , L_4 , & V_15 ) ;
if ( strlen ( V_18 ) + 3 < V_15 &&
! strncmp ( V_18 , V_16 , strlen ( V_18 ) ) )
V_17 = V_16 + strlen ( V_18 ) ;
if ( V_17 == NULL ) {
F_4 ( L_5 ) ;
return 0 ;
}
if ( F_6 ( V_14 , V_21 , & V_20 ) )
return 0 ;
V_22 = V_20 . V_23 >> V_24 ;
V_25 = F_7 ( V_14 , 0 ) ;
F_8 ( L_6 ,
V_17 , V_25 , V_22 ) ;
V_26 = V_27 ;
F_9 () ;
if ( F_10 ( V_28 ) )
V_29 -> V_30 |= V_31 | V_32 ;
else
V_29 -> V_30 &= ~ ( V_31 | V_32 ) ;
if ( ! V_12 )
V_12 = (struct V_11 * )
F_11 ( V_33 ) ;
if ( ! V_12 ) {
F_12 ( L_7 ) ;
return - V_34 ;
}
V_10 . V_7 = V_35 ;
V_10 . V_36 = 0 ;
V_10 . V_37 = V_38 ;
V_10 . V_39 = F_13 ( V_12 ) >> V_24 ;
if ( F_14 ( V_40 , & V_10 ) )
F_15 () ;
V_41 = (struct V_11 * ) V_12 ;
F_16 ( V_42 , 0 ) = & V_41 -> V_43 [ 0 ] ;
F_17 () ;
if ( ! F_18 () )
F_19 ( NULL ) ;
return 0 ;
}
static T_3 F_20 ( int V_44 , void * V_45 )
{
F_21 () ;
return V_46 ;
}
static int T_2 F_22 ( void )
{
if ( ! F_23 () || V_25 < 0 )
return - V_47 ;
F_24 () ;
if ( F_25 ( V_25 , F_20 ,
L_8 , V_42 ) ) {
F_12 ( L_9 , V_25 ) ;
return - V_48 ;
}
F_26 ( V_25 , 0 ) ;
return 0 ;
}
int F_27 ( int V_49 , struct V_50 * * V_51 , bool V_52 )
{
* V_51 = F_28 ( V_52 ? V_53 : V_33 ,
F_29 ( V_49 ) ) ;
if ( * V_51 == NULL )
return - V_34 ;
return 0 ;
}
void F_30 ( int V_49 , struct V_50 * * V_51 )
{
F_31 ( * V_51 ) ;
* V_51 = NULL ;
}
