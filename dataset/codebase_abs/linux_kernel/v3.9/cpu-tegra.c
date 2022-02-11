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
int V_8 ;
F_6 ( V_9 ) ;
V_8 = F_7 ( V_7 , V_10 ) ;
if ( V_8 ) {
F_8 ( L_1 ) ;
goto V_11;
}
if ( V_5 == F_4 ( V_10 ) )
goto V_11;
V_8 = F_9 ( V_9 , V_5 ) ;
if ( V_8 ) {
F_8 ( L_2 , V_5 ) ;
goto V_11;
}
V_8 = F_7 ( V_7 , V_9 ) ;
if ( V_8 ) {
F_8 ( L_3 ) ;
goto V_11;
}
V_11:
F_10 ( V_9 ) ;
return V_8 ;
}
static int F_11 ( unsigned long V_5 )
{
int V_8 = 0 ;
struct V_12 V_13 ;
V_13 . V_14 = F_3 ( 0 ) ;
V_13 . V_15 = V_5 ;
if ( V_13 . V_14 == V_13 . V_15 )
return V_8 ;
if ( V_5 >= 816000 )
F_9 ( V_16 , 600000000 ) ;
else if ( V_5 >= 456000 )
F_9 ( V_16 , 300000000 ) ;
else
F_9 ( V_16 , 100000000 ) ;
F_12 (freqs.cpu)
F_13 ( & V_13 , V_17 ) ;
#ifdef F_14
F_15 ( V_18 L_4 ,
V_13 . V_14 , V_13 . V_15 ) ;
#endif
V_8 = F_5 ( V_13 . V_15 * 1000 ) ;
if ( V_8 ) {
F_8 ( L_5 ,
V_13 . V_15 ) ;
return V_8 ;
}
F_12 (freqs.cpu)
F_13 ( & V_13 , V_19 ) ;
return 0 ;
}
static unsigned long F_16 ( void )
{
unsigned long V_5 = 0 ;
int V_20 ;
F_12 (i)
V_5 = F_17 ( V_5 , V_21 [ V_20 ] ) ;
return V_5 ;
}
static int F_18 ( struct V_1 * V_2 ,
unsigned int V_22 ,
unsigned int V_23 )
{
unsigned int V_24 ;
unsigned int V_25 ;
int V_8 = 0 ;
F_19 ( & V_26 ) ;
if ( V_27 ) {
V_8 = - V_28 ;
goto V_11;
}
F_20 ( V_2 , V_3 , V_22 ,
V_23 , & V_24 ) ;
V_25 = V_3 [ V_24 ] . V_29 ;
V_21 [ V_2 -> V_4 ] = V_25 ;
V_8 = F_11 ( F_16 () ) ;
V_11:
F_21 ( & V_26 ) ;
return V_8 ;
}
static int F_22 ( struct V_30 * V_31 , unsigned long V_32 ,
void * V_33 )
{
F_19 ( & V_26 ) ;
if ( V_32 == V_34 ) {
V_27 = true ;
F_23 ( L_6 ,
V_3 [ 0 ] . V_29 ) ;
F_11 ( V_3 [ 0 ] . V_29 ) ;
} else if ( V_32 == V_35 ) {
V_27 = false ;
}
F_21 ( & V_26 ) ;
return V_36 ;
}
static int F_24 ( struct V_1 * V_2 )
{
if ( V_2 -> V_4 >= V_6 )
return - V_37 ;
F_6 ( V_16 ) ;
F_6 ( V_7 ) ;
F_25 ( V_2 , V_3 ) ;
F_26 ( V_3 , V_2 -> V_4 ) ;
V_2 -> V_38 = F_3 ( V_2 -> V_4 ) ;
V_21 [ V_2 -> V_4 ] = V_2 -> V_38 ;
V_2 -> V_39 . V_40 = 300 * 1000 ;
F_27 ( V_2 -> V_41 , V_42 ) ;
if ( V_2 -> V_4 == 0 )
F_28 ( & V_43 ) ;
return 0 ;
}
static int F_29 ( struct V_1 * V_2 )
{
F_25 ( V_2 , V_3 ) ;
F_10 ( V_16 ) ;
return 0 ;
}
static int T_1 F_30 ( void )
{
V_7 = F_31 ( NULL , L_7 ) ;
if ( F_32 ( V_7 ) )
return F_33 ( V_7 ) ;
V_9 = F_31 ( NULL , L_8 ) ;
if ( F_32 ( V_9 ) )
return F_33 ( V_9 ) ;
V_10 = F_31 ( NULL , L_9 ) ;
if ( F_32 ( V_10 ) )
return F_33 ( V_10 ) ;
V_16 = F_31 ( L_7 , L_10 ) ;
if ( F_32 ( V_16 ) ) {
F_34 ( V_7 ) ;
return F_33 ( V_16 ) ;
}
return F_35 ( & V_44 ) ;
}
static void T_2 F_36 ( void )
{
F_37 ( & V_44 ) ;
F_34 ( V_16 ) ;
F_34 ( V_7 ) ;
}
