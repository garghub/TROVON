static T_1 F_1 ( const unsigned int V_1 )
{
T_2 V_2 ;
V_2 = F_2 ( F_3 ( V_1 , 4 ) ) ;
V_2 >>= ( V_1 % 4 ) * 8 ;
V_2 &= 0xff ;
return V_2 ;
}
static T_3 F_4 ( struct V_3 * V_4 , struct V_5 * V_6 ,
struct V_7 * V_8 , char * V_9 ,
T_4 V_10 , T_5 V_11 )
{
int V_12 ;
if ( V_10 < 0 || V_10 >= V_13 )
return 0 ;
if ( V_11 > V_13 - V_10 )
V_11 = V_13 - V_10 ;
for ( V_12 = 0 ; V_12 < V_11 ; V_12 ++ )
V_9 [ V_12 ] = F_1 ( V_10 + V_12 ) ;
return V_12 ;
}
static void F_5 ( void T_6 * V_14 )
{
T_2 V_15 ;
V_15 = F_6 ( V_14 + 0x48 ) ;
V_15 |= 1 << 28 ;
F_7 ( V_15 , V_14 + 0x48 ) ;
V_15 = F_8 ( V_14 + 0x14 ) ;
V_15 |= 1 << 7 ;
F_7 ( V_15 , V_14 + 0x14 ) ;
}
int F_9 ( unsigned long V_1 , T_2 * V_16 )
{
if ( ! F_2 )
return - V_17 ;
* V_16 = F_2 ( V_1 ) ;
return 0 ;
}
int F_10 ( struct V_18 * V_19 , int V_11 ,
T_2 (* F_8)( const unsigned int V_1 ) )
{
if ( V_13 )
return - V_20 ;
V_21 . V_11 = V_11 ;
V_21 . V_22 = F_4 ;
V_13 = V_11 ;
F_2 = F_8 ;
return F_11 ( V_19 , & V_21 ) ;
}
static int T_7 F_12 ( void )
{
struct V_23 * V_24 ;
void T_6 * V_25 ;
if ( ! F_13 () )
return 0 ;
F_14 () ;
V_24 = F_15 ( NULL , V_26 ) ;
V_25 = F_16 ( V_24 , 0 ) ;
if ( V_25 ) {
F_5 ( V_25 ) ;
F_17 ( V_25 ) ;
} else {
F_18 ( L_1 ) ;
return - V_27 ;
}
if ( F_19 () == V_28 )
F_20 () ;
else
F_21 () ;
F_22 ( L_2 ,
V_29 [ V_30 . V_31 ] ,
V_30 . V_32 , V_30 . V_33 ,
V_30 . V_34 ) ;
F_23 ( L_3 ,
V_30 . V_35 , V_30 . V_36 ) ;
return 0 ;
}
