static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return F_3 ( V_4 ) &&
F_4 ( V_4 ) &&
F_5 ( V_4 ) == V_5 &&
! V_4 -> V_6 ? 0 : 1 ;
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return F_3 ( V_4 ) &&
F_4 ( V_4 ) &&
F_5 ( V_4 ) == V_7 &&
! V_4 -> V_6 ? 0 : 1 ;
}
static int F_7 ( struct V_1 * V_2 )
{
T_1 V_8 [ V_9 ] , V_6 ;
int V_10 = 1 ;
struct V_1 * V_11 = F_8 ( NULL , V_2 -> V_12 , V_13 ,
sizeof( struct V_14 ) ) ;
if ( ! V_11 )
goto V_15;
V_10 = 0 ;
F_9 ( V_2 , V_8 ) ;
F_10 ( V_2 , & V_6 ) ;
F_11 ( V_11 , V_13 , 0 , V_6 , V_16 ) ;
F_12 ( V_11 , V_17 , 127 ) ;
V_10 = F_13 ( V_11 , V_2 -> V_12 -> V_18 , V_8 ) ;
if ( F_14 ( V_10 ) )
goto free;
F_15 ( V_11 ) ;
V_15:
return V_10 ;
free:
F_16 ( V_11 ) ;
goto V_15;
}
static int F_17 ( struct V_1 * V_2 )
{
T_1 V_8 [ V_9 ] , V_6 ;
int V_10 = 1 ;
T_2 V_19 ;
struct V_1 * V_11 ;
V_19 = F_18 ( F_19 ( V_2 ) -> V_20 ) - 3 ;
V_11 = F_8 ( NULL , V_2 -> V_12 , V_13 , V_19 ) ;
if ( ! V_11 )
goto V_15;
V_10 = 0 ;
F_9 ( V_2 , V_8 ) ;
F_10 ( V_2 , & V_6 ) ;
F_11 ( V_11 , V_13 , 0 , V_6 , V_16 ) ;
F_20 ( V_11 , V_2 ) ;
V_10 = F_13 ( V_11 , V_2 -> V_12 -> V_18 , V_8 ) ;
if ( F_14 ( V_10 ) )
goto free;
F_15 ( V_11 ) ;
V_15:
return V_10 ;
free:
F_16 ( V_11 ) ;
goto V_15;
}
static void F_21 ( struct V_1 * V_2 )
{
if ( F_1 ( V_2 ) )
F_7 ( V_2 ) ;
else if ( F_6 ( V_2 ) )
F_17 ( V_2 ) ;
F_16 ( V_2 ) ;
}
void T_3 F_22 ( void )
{
F_23 ( F_21 ) ;
}
void F_24 ( void )
{
F_23 ( NULL ) ;
}
