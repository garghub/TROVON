static int F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_2 , V_3 ) ;
}
static unsigned int F_3 ( unsigned int V_4 )
{
unsigned long V_5 ;
if ( V_4 >= V_6 )
return 0 ;
V_5 = F_4 ( V_7 ) / 1000 ;
return V_5 ;
}
static int F_5 ( unsigned long V_5 )
{
int V_8 = 0 ;
struct V_9 V_10 ;
V_10 . V_11 = F_3 ( 0 ) ;
V_10 . V_12 = V_5 ;
if ( V_10 . V_11 == V_10 . V_12 )
return V_8 ;
if ( V_5 >= 816000 )
F_6 ( V_13 , 600000000 ) ;
else if ( V_5 >= 456000 )
F_6 ( V_13 , 300000000 ) ;
else
F_6 ( V_13 , 100000000 ) ;
F_7 (freqs.cpu)
F_8 ( & V_10 , V_14 ) ;
#ifdef F_9
F_10 ( V_15 L_1 ,
V_10 . V_11 , V_10 . V_12 ) ;
#endif
V_8 = F_6 ( V_7 , V_10 . V_12 * 1000 ) ;
if ( V_8 ) {
F_11 ( L_2 ,
V_10 . V_12 ) ;
return V_8 ;
}
F_7 (freqs.cpu)
F_8 ( & V_10 , V_16 ) ;
return 0 ;
}
static unsigned long F_12 ( void )
{
unsigned long V_5 = 0 ;
int V_17 ;
F_7 (i)
V_5 = F_13 ( V_5 , V_18 [ V_17 ] ) ;
return V_5 ;
}
static int F_14 ( struct V_1 * V_2 ,
unsigned int V_19 ,
unsigned int V_20 )
{
unsigned int V_21 ;
unsigned int V_22 ;
int V_8 = 0 ;
F_15 ( & V_23 ) ;
if ( V_24 ) {
V_8 = - V_25 ;
goto V_26;
}
F_16 ( V_2 , V_3 , V_19 ,
V_20 , & V_21 ) ;
V_22 = V_3 [ V_21 ] . V_27 ;
V_18 [ V_2 -> V_4 ] = V_22 ;
V_8 = F_5 ( F_12 () ) ;
V_26:
F_17 ( & V_23 ) ;
return V_8 ;
}
static int F_18 ( struct V_28 * V_29 , unsigned long V_30 ,
void * V_31 )
{
F_15 ( & V_23 ) ;
if ( V_30 == V_32 ) {
V_24 = true ;
F_19 ( L_3 ,
V_3 [ 0 ] . V_27 ) ;
F_5 ( V_3 [ 0 ] . V_27 ) ;
} else if ( V_30 == V_33 ) {
V_24 = false ;
}
F_17 ( & V_23 ) ;
return V_34 ;
}
static int F_20 ( struct V_1 * V_2 )
{
if ( V_2 -> V_4 >= V_6 )
return - V_35 ;
V_7 = F_21 ( NULL , L_4 ) ;
if ( F_22 ( V_7 ) )
return F_23 ( V_7 ) ;
V_13 = F_21 ( L_4 , L_5 ) ;
if ( F_22 ( V_13 ) ) {
F_24 ( V_7 ) ;
return F_23 ( V_13 ) ;
}
F_25 ( V_13 ) ;
F_25 ( V_7 ) ;
F_26 ( V_2 , V_3 ) ;
F_27 ( V_3 , V_2 -> V_4 ) ;
V_2 -> V_36 = F_3 ( V_2 -> V_4 ) ;
V_18 [ V_2 -> V_4 ] = V_2 -> V_36 ;
V_2 -> V_37 . V_38 = 300 * 1000 ;
V_2 -> V_39 = V_40 ;
F_28 ( V_2 -> V_41 , V_42 ) ;
if ( V_2 -> V_4 == 0 )
F_29 ( & V_43 ) ;
return 0 ;
}
static int F_30 ( struct V_1 * V_2 )
{
F_26 ( V_2 , V_3 ) ;
F_31 ( V_13 ) ;
F_24 ( V_13 ) ;
F_24 ( V_7 ) ;
return 0 ;
}
static int T_1 F_32 ( void )
{
return F_33 ( & V_44 ) ;
}
static void T_2 F_34 ( void )
{
F_35 ( & V_44 ) ;
}
