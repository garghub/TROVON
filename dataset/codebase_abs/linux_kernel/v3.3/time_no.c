static inline int F_1 ( unsigned long V_1 )
{
if ( V_2 )
return V_2 ( V_1 ) ;
return - 1 ;
}
T_1 F_2 ( int V_3 , void * V_4 )
{
if ( V_5 -> V_6 )
F_3 ( V_7 ) ;
F_4 ( 1 ) ;
F_5 ( F_6 ( F_7 () ) ) ;
return ( V_8 ) ;
}
static unsigned long F_8 ( void )
{
unsigned int V_9 , V_10 , V_11 , V_12 , V_13 , V_14 ;
if ( V_15 ) {
V_15 ( & V_9 , & V_10 , & V_11 , & V_12 , & V_13 , & V_14 ) ;
if ( ( V_9 += 1900 ) < 1970 )
V_9 += 100 ;
} else {
V_9 = 1970 ;
V_10 = V_11 = 1 ;
V_12 = V_13 = V_14 = 0 ;
}
return mktime ( V_9 , V_10 , V_11 , V_12 , V_13 , V_14 ) ;
}
void F_9 ( struct V_16 * V_17 )
{
V_17 -> V_18 = F_8 () ;
V_17 -> V_19 = 0 ;
}
int F_10 ( struct V_16 V_20 )
{
return F_1 ( V_20 . V_18 ) ;
}
void F_11 ( void )
{
F_12 () ;
}
