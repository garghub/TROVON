static void F_1 ( void * V_1 )
{
struct V_2 * V_3 = (struct V_2 * ) V_1 ;
F_2 ( V_3 ) ;
}
static void F_3 ( unsigned int V_4 )
{
F_4 ( V_5 , & V_6 , V_4 ) ;
F_5 ( V_5 , & V_6 , 1 ) ;
}
static void F_6 ( void )
{
F_5 ( V_5 , & V_6 , 0 ) ;
}
int F_7 ( struct V_2 * V_3 , struct V_7 * V_8 )
{
V_6 . V_9 = V_3 ;
V_6 . V_10 = F_1 ;
V_5 = F_8 ( V_11 ) ;
if ( V_5 == NULL ) {
F_9 ( L_1 ) ;
return - V_12 ;
}
F_10 ( V_5 , & V_6 ) ;
if ( ( F_4 ( V_5 , & V_6 , V_8 -> V_13 ) < 0 ) ) {
F_9 ( L_2 ) ;
F_11 ( V_5 , & V_6 ) ;
F_12 ( V_5 ) ;
return - 1 ;
}
F_13 ( V_11 , V_8 -> V_13 ) ;
V_8 -> V_14 = F_3 ;
V_8 -> V_15 = F_6 ;
return 0 ;
}
int F_14 ( void )
{
F_5 ( V_5 , & V_6 , 0 ) ;
F_11 ( V_5 , & V_6 ) ;
F_12 ( V_5 ) ;
return 0 ;
}
static void F_15 ( unsigned int V_4 )
{
F_16 ( V_16 , V_4 ) ;
F_17 ( V_16 ) ;
}
static void F_18 ( void )
{
F_19 ( V_16 ) ;
}
int F_7 ( struct V_2 * V_3 , struct V_7 * V_8 )
{
V_16 = F_20 ( NULL , V_17 ) ;
if ( V_16 == NULL )
return - 1 ;
if ( F_21 ( F_1 , ( void * ) V_3 ) < 0 ) {
V_16 = NULL ;
return - 1 ;
}
F_13 ( L_3 , V_8 -> V_13 ) ;
V_8 -> V_14 = F_15 ;
V_8 -> V_15 = F_18 ;
return 0 ;
}
int F_14 ( void )
{
F_19 ( V_16 ) ;
F_22 () ;
F_23 ( V_16 ) ;
return 0 ;
}
