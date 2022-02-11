static int F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 = 0 ;
F_2 ( & V_2 -> V_4 ) ;
V_2 -> V_5 = F_3 ( struct V_6 ) ;
return V_2 -> V_5 ? 0 : - V_7 ;
}
int F_4 ( struct V_1 * V_2 , const char * V_8 ,
struct V_9 * V_10 )
{
F_5 ( ( void * ) V_2 , sizeof( * V_2 ) ) ;
F_6 ( & V_2 -> V_11 , V_8 , V_10 , 0 ) ;
return F_1 ( V_2 ) ;
}
int F_7 ( struct V_1 * V_2 )
{
return F_1 ( V_2 ) ;
}
static int F_8 ( struct V_1 * V_2 , int V_12 )
{
int V_13 ;
int V_14 ;
V_14 = 0 ;
F_9 (cpu)
V_14 += F_10 ( V_2 -> V_5 , V_13 ) -> V_15 [ V_12 ] ;
return V_14 ;
}
static int F_11 ( struct V_1 * V_2 )
{
return F_8 ( V_2 , 0 ) + F_8 ( V_2 , 1 ) ;
}
void F_12 ( struct V_1 * V_2 )
{
int V_14 ;
V_14 = F_11 ( V_2 ) ;
F_13 ( V_14 ) ;
if ( V_14 != 0 )
return;
F_14 ( V_2 -> V_5 ) ;
V_2 -> V_5 = NULL ;
}
int F_15 ( struct V_1 * V_2 )
{
int V_12 ;
F_16 () ;
V_12 = V_2 -> V_3 & 0x1 ;
F_17 () ;
F_10 ( V_2 -> V_5 , F_18 () ) -> V_15 [ V_12 ] ++ ;
F_19 () ;
F_20 () ;
return V_12 ;
}
void F_21 ( struct V_1 * V_2 , int V_12 )
{
F_16 () ;
F_19 () ;
F_10 ( V_2 -> V_5 , F_18 () ) -> V_15 [ V_12 ] -- ;
F_20 () ;
}
static void F_22 ( struct V_1 * V_2 , void (* F_23)( void ) )
{
int V_12 ;
V_12 = V_2 -> V_3 ;
F_24 ( & V_2 -> V_4 ) ;
if ( ( V_2 -> V_3 - V_12 ) >= 2 ) {
F_25 ( & V_2 -> V_4 ) ;
return;
}
F_23 () ;
V_12 = V_2 -> V_3 & 0x1 ;
V_2 -> V_3 ++ ;
F_23 () ;
if ( F_8 ( V_2 , V_12 ) )
F_26 ( V_16 ) ;
while ( F_8 ( V_2 , V_12 ) )
F_27 ( 1 ) ;
F_23 () ;
F_25 ( & V_2 -> V_4 ) ;
}
void F_28 ( struct V_1 * V_2 )
{
F_22 ( V_2 , V_17 ) ;
}
void F_29 ( struct V_1 * V_2 )
{
F_22 ( V_2 , V_18 ) ;
}
long F_30 ( struct V_1 * V_2 )
{
return V_2 -> V_3 ;
}
