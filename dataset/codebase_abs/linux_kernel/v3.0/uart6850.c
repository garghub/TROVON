static int F_1 ( void )
{
return F_2 ( V_1 ) ;
}
static void F_3 ( unsigned char V_2 )
{
F_4 ( V_2 , V_3 ) ;
}
static int F_5 ( void )
{
return F_2 ( V_4 ) ;
}
static void F_6 ( unsigned char V_5 )
{
F_4 ( V_5 , V_4 ) ;
}
static void F_7 ( void )
{
int V_6 = 10 ;
while ( V_6 )
{
if ( F_8 () )
{
unsigned char V_7 = F_5 () ;
V_6 = 100 ;
if ( V_8 & V_9 )
F_9 ( V_10 , V_7 ) ;
}
else
{
while ( ! F_8 () && V_6 )
V_6 -- ;
}
}
}
static T_1 F_10 ( int V_11 , void * V_12 )
{
if ( F_8 () )
F_7 () ;
return V_13 ;
}
static void F_11 ( unsigned long V_14 )
{
unsigned long V_15 ;
if ( ! ( V_8 & V_9 ) )
return;
F_12 ( & V_16 , V_15 ) ;
if ( F_8 () )
F_7 () ;
V_17 . V_18 = 1 + V_19 ;
F_13 ( & V_17 ) ;
F_14 ( & V_16 , V_15 ) ;
}
static int F_15 ( int V_20 , int V_21 ,
void (* F_16) ( int V_20 , unsigned char V_22 ) ,
void (* F_17) ( int V_20 )
)
{
if ( V_8 )
{
return - V_23 ;
} ;
F_3 ( V_24 ) ;
F_7 () ;
F_9 = F_16 ;
V_8 = V_21 ;
F_11 ( 0 ) ;
return 0 ;
}
static void F_18 ( int V_20 )
{
F_3 ( V_25 ) ;
F_19 ( & V_17 ) ;
V_8 = 0 ;
}
static int F_20 ( int V_20 , unsigned char V_26 )
{
int V_27 ;
unsigned long V_15 ;
F_12 ( & V_16 , V_15 ) ;
if ( F_8 () )
F_7 () ;
F_14 ( & V_16 , V_15 ) ;
for ( V_27 = 30000 ; V_27 > 0 && ! F_21 () ; V_27 -- ) ;
if ( ! F_21 () )
{
F_22 ( V_28 L_1 ) ;
return 0 ;
}
F_6 ( V_26 ) ;
return 1 ;
}
static inline int F_23 ( int V_20 , unsigned char * V_26 )
{
return 1 ;
}
static inline int F_24 ( int V_20 )
{
return 0 ;
}
static inline int F_25 ( int V_20 )
{
return 0 ;
}
static inline void F_26 ( int V_20 )
{
}
static inline int F_27 ( int V_20 )
{
return 0 ;
}
static void T_2 F_28 ( struct V_29 * V_30 )
{
int V_31 , V_27 ;
unsigned long V_15 ;
if ( ! V_32 )
return;
if ( ( V_10 = F_29 () ) == - 1 )
{
F_22 ( V_33 L_2 ) ;
return;
}
V_34 = V_30 -> V_35 ;
V_36 = V_30 -> V_37 ;
V_38 = V_30 -> V_11 ;
F_12 ( & V_16 , V_15 ) ;
for ( V_27 = 30000 ; V_27 > 0 && ! F_21 () ; V_27 -- ) ;
F_3 ( V_25 ) ;
V_31 = 1 ;
F_14 ( & V_16 , V_15 ) ;
F_30 ( L_3 , V_30 ) ;
V_39 . V_40 = V_10 ;
V_30 -> V_41 [ 4 ] = V_10 ;
V_42 [ V_10 ] = & V_43 ;
F_31 () ;
}
static inline int F_32 ( void )
{
F_5 () ;
return 1 ;
}
static int T_2 F_33 ( struct V_29 * V_30 )
{
int V_31 ;
V_36 = V_30 -> V_37 ;
V_34 = V_30 -> V_35 ;
V_38 = V_30 -> V_11 ;
if ( F_34 ( V_38 , F_10 , 0 , L_4 , NULL ) < 0 )
return 0 ;
V_31 = F_32 () ;
V_32 = V_31 ;
return V_31 ;
}
static void T_3 F_35 ( struct V_29 * V_30 )
{
F_36 ( V_30 -> V_11 , NULL ) ;
F_37 ( V_30 -> V_41 [ 4 ] ) ;
}
static int T_2 F_38 ( void )
{
V_44 . V_35 = V_45 ;
V_44 . V_11 = V_11 ;
if ( V_44 . V_35 == - 1 || V_44 . V_11 == - 1 ) {
F_22 ( V_33 L_5 ) ;
return - V_46 ;
}
if ( F_33 ( & V_44 ) )
return - V_47 ;
F_28 ( & V_44 ) ;
return 0 ;
}
static void T_3 F_39 ( void )
{
F_35 ( & V_44 ) ;
}
static int T_2 F_40 ( char * V_48 )
{
int V_49 [ 3 ] ;
V_48 = F_41 ( V_48 , F_42 ( V_49 ) , V_49 ) ;
V_45 = V_49 [ 1 ] ;
V_11 = V_49 [ 2 ] ;
return 1 ;
}
