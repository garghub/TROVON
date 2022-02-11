int F_1 ( struct V_1 * V_2 , struct V_3 * V_3 ,
enum V_4 V_5 ,
struct V_6 * V_7 )
{
V_7 -> V_3 = V_3 ;
return V_2 -> V_8 ( V_2 , V_5 , V_7 ) ;
}
int F_2 ( struct V_3 * V_3 , enum V_4 V_5 ,
struct V_6 * V_7 )
{
V_3 -> V_9 . V_10 ++ ;
V_7 -> V_3 = V_3 ;
return F_3 ( & V_11 , V_5 , V_7 ) ;
}
static unsigned int F_4 ( void )
{
unsigned int V_10 = 0 ;
struct V_3 * V_3 ;
F_5 () ;
F_6 (net)
V_10 += V_3 -> V_9 . V_10 ;
F_7 () ;
return V_10 ;
}
static bool F_8 ( struct V_1 * V_2 ,
void (* F_9)( struct V_1 * V_2 ) ,
unsigned int V_10 )
{
F_10 ( & V_11 , V_2 ) ;
if ( V_10 == F_4 () )
return true ;
F_11 ( & V_11 , V_2 ) ;
if ( F_9 )
F_9 ( V_2 ) ;
return false ;
}
int F_12 ( struct V_1 * V_2 ,
void (* F_9)( struct V_1 * V_2 ) )
{
int V_12 = 0 ;
do {
unsigned int V_10 = F_4 () ;
struct V_3 * V_3 ;
F_13 () ;
F_14 (net) {
F_15 ( V_3 , V_2 ) ;
F_16 ( V_3 , V_2 ) ;
}
F_17 () ;
if ( F_8 ( V_2 , F_9 , V_10 ) )
return 0 ;
} while ( ++ V_12 < V_13 );
return - V_14 ;
}
int F_18 ( struct V_1 * V_2 )
{
return F_11 ( & V_11 , V_2 ) ;
}
