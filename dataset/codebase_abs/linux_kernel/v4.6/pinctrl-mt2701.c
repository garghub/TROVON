static int F_1 ( struct V_1 * V_1 , unsigned int V_2 ,
unsigned char V_3 , bool V_4 , unsigned int V_5 )
{
return F_2 ( V_1 , V_6 ,
F_3 ( V_6 ) , V_2 , V_3 , V_4 , V_5 ) ;
}
static int F_4 ( struct V_1 * V_1 , unsigned int V_2 ,
unsigned char V_3 , int V_7 , enum V_8 V_9 )
{
if ( V_9 == V_10 )
return F_5 ( V_1 , V_11 ,
F_3 ( V_11 ) , V_2 , V_3 , V_7 ) ;
else if ( V_9 == V_12 )
return F_5 ( V_1 , V_13 ,
F_3 ( V_13 ) , V_2 , V_3 , V_7 ) ;
return - V_14 ;
}
static void F_6 ( struct V_1 * V_15 , unsigned int V_2 ,
unsigned int V_16 )
{
unsigned int V_17 , V_7 , V_18 ;
unsigned int V_19 = F_3 ( V_20 ) ;
unsigned int V_21 ;
for ( V_17 = 0 ; V_17 < V_19 ; V_17 ++ ) {
if ( V_2 == V_20 [ V_17 ] . V_2 )
break;
}
if ( V_17 == V_19 )
return;
V_21 = ( V_16 >> 3 ) ;
V_18 = F_7 ( V_20 [ V_17 ] . V_22 ) ;
if ( ! V_21 )
V_7 = V_18 ;
else
V_7 = 0 ;
F_8 ( V_15 , V_20 [ V_17 ] . V_23 , V_18 , V_7 ) ;
}
static void F_9 ( unsigned int * V_24 , unsigned int V_2 )
{
if ( V_2 > 175 )
* V_24 += 0x10 ;
}
static int F_10 ( struct V_25 * V_26 )
{
return F_11 ( V_26 , & V_27 , NULL ) ;
}
static int T_1 F_12 ( void )
{
return F_13 ( & V_28 ) ;
}
