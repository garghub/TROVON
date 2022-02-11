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
V_2 -> V_16 , F_2 ( V_7 + V_26 ) , V_20 ) ;
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
bool F_14 ( struct V_1 * V_2 )
{
unsigned int V_29 ;
V_29 = F_2 ( V_7 + V_2 -> V_12 + V_30 ) ;
if ( V_29 & ( 1 << V_2 -> V_11 ) )
return true ;
return false ;
}
void T_1 * F_15 ( T_2 V_31 )
{
V_7 = F_16 ( V_31 , V_32 ) ;
if ( ! V_7 )
F_17 ( L_2 ) ;
return V_7 ;
}
