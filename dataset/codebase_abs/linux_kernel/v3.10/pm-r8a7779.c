static int F_1 ( struct V_1 * V_2 ,
int V_3 , int V_4 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < V_6 ; V_5 ++ ) {
if ( F_2 ( V_7 + V_8 ) & ( 1 << V_3 ) )
break;
F_3 ( V_9 ) ;
}
if ( V_5 == V_6 )
return - V_10 ;
F_4 ( 1 << V_2 -> V_11 ,
V_7 + V_2 -> V_12 + V_4 ) ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 )
{
return F_1 ( V_2 , 0 , V_13 ) ;
}
static int F_6 ( struct V_1 * V_2 )
{
return F_1 ( V_2 , 1 , V_14 ) ;
}
static int F_7 ( struct V_1 * V_2 ,
int (* F_8)( struct V_1 * ) )
{
unsigned int V_15 = 1 << V_2 -> V_16 ;
unsigned int V_17 = 1 << V_2 -> V_11 ;
unsigned int V_18 ;
unsigned long V_19 ;
int V_20 = 0 ;
int V_5 ;
F_9 ( & V_21 , V_19 ) ;
F_4 ( V_15 , V_7 + V_22 ) ;
do {
V_20 = F_8 ( V_2 ) ;
if ( V_20 )
goto V_23;
V_18 = F_2 ( V_7 +
V_2 -> V_12 + V_24 ) ;
} while ( V_18 & V_17 );
for ( V_5 = 0 ; V_5 < V_25 ; V_5 ++ ) {
if ( F_2 ( V_7 + V_26 ) & V_15 )
break;
F_3 ( V_27 ) ;
}
if ( V_5 == V_25 )
V_20 = - V_28 ;
F_4 ( V_15 , V_7 + V_22 ) ;
V_23:
F_10 ( & V_21 , V_19 ) ;
F_11 ( L_1 ,
V_2 -> V_16 , F_2 ( V_7 + V_29 ) ,
F_2 ( V_7 + V_30 ) ,
F_2 ( V_7 + V_31 ) ,
F_2 ( V_7 + V_32 ) ,
F_2 ( V_7 + V_33 ) , V_20 ) ;
return V_20 ;
}
int F_12 ( struct V_1 * V_2 )
{
return F_7 ( V_2 , F_5 ) ;
}
int F_13 ( struct V_1 * V_2 )
{
return F_7 ( V_2 , F_6 ) ;
}
static void T_1 F_14 ( void )
{
V_7 = F_15 ( 0xffd85000 , V_34 ) ;
if ( ! V_7 )
F_16 ( L_2 ) ;
F_4 ( 0x0131000e , V_7 + V_35 ) ;
F_4 ( 0 , V_7 + V_36 ) ;
}
static inline void F_14 ( void ) {}
static int F_17 ( struct V_37 * V_38 )
{
return F_12 ( F_18 ( V_38 ) ) ;
}
static int F_19 ( struct V_37 * V_38 )
{
return F_13 ( F_18 ( V_38 ) ) ;
}
static bool F_20 ( struct V_37 * V_38 )
{
struct V_1 * V_2 = F_18 ( V_38 ) ;
unsigned int V_39 ;
V_39 = F_2 ( V_7 + V_2 -> V_12 + V_40 ) ;
if ( V_39 & ( 1 << V_2 -> V_11 ) )
return true ;
return false ;
}
static bool F_21 ( struct V_41 * V_42 )
{
return true ;
}
static void F_22 ( struct V_43 * V_44 )
{
struct V_37 * V_38 = & V_44 -> V_38 ;
F_23 ( V_38 , NULL , false ) ;
V_38 -> V_45 . V_46 = V_47 ;
V_38 -> V_45 . V_48 = V_49 ;
V_38 -> V_45 . V_50 = F_21 ;
V_38 -> V_51 = true ;
V_38 -> V_52 = F_17 ;
V_38 -> V_53 = F_19 ;
if ( F_20 ( & V_44 -> V_38 ) )
F_19 ( & V_44 -> V_38 ) ;
}
void T_1 F_24 ( void )
{
int V_54 ;
for ( V_54 = 0 ; V_54 < F_25 ( V_55 ) ; V_54 ++ )
F_22 ( & V_55 [ V_54 ] ) ;
}
void T_1 F_26 ( void )
{
static int V_56 ;
if ( ! V_56 ++ )
F_14 () ;
}
