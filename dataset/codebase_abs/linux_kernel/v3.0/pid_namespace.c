static struct V_1 * F_1 ( int V_2 )
{
struct V_3 * V_4 ;
struct V_1 * V_5 ;
F_2 ( & V_6 ) ;
F_3 (pcache, &pid_caches_lh, list)
if ( V_4 -> V_2 == V_2 )
goto V_7;
V_4 = F_4 ( sizeof( struct V_3 ) , V_8 ) ;
if ( V_4 == NULL )
goto V_9;
snprintf ( V_4 -> V_10 , sizeof( V_4 -> V_10 ) , L_1 , V_2 ) ;
V_5 = F_5 ( V_4 -> V_10 ,
sizeof( struct V_11 ) + ( V_2 - 1 ) * sizeof( struct V_12 ) ,
0 , V_13 , NULL ) ;
if ( V_5 == NULL )
goto V_14;
V_4 -> V_2 = V_2 ;
V_4 -> V_5 = V_5 ;
F_6 ( & V_4 -> V_15 , & V_16 ) ;
V_7:
F_7 ( & V_6 ) ;
return V_4 -> V_5 ;
V_14:
F_8 ( V_4 ) ;
V_9:
F_7 ( & V_6 ) ;
return NULL ;
}
static struct V_17 * F_9 ( struct V_17 * V_18 )
{
struct V_17 * V_19 ;
unsigned int V_20 = V_18 -> V_20 + 1 ;
int V_21 , V_22 = - V_23 ;
V_19 = F_10 ( V_24 , V_8 ) ;
if ( V_19 == NULL )
goto V_7;
V_19 -> V_25 [ 0 ] . V_26 = F_11 ( V_27 , V_8 ) ;
if ( ! V_19 -> V_25 [ 0 ] . V_26 )
goto V_28;
V_19 -> V_29 = F_1 ( V_20 + 1 ) ;
if ( V_19 -> V_29 == NULL )
goto V_30;
F_12 ( & V_19 -> V_31 ) ;
V_19 -> V_20 = V_20 ;
V_19 -> V_32 = F_13 ( V_18 ) ;
F_14 ( 0 , V_19 -> V_25 [ 0 ] . V_26 ) ;
F_15 ( & V_19 -> V_25 [ 0 ] . V_33 , V_34 - 1 ) ;
for ( V_21 = 1 ; V_21 < V_35 ; V_21 ++ )
F_15 ( & V_19 -> V_25 [ V_21 ] . V_33 , V_34 ) ;
V_22 = F_16 ( V_19 ) ;
if ( V_22 )
goto V_36;
return V_19 ;
V_36:
F_17 ( V_18 ) ;
V_30:
F_8 ( V_19 -> V_25 [ 0 ] . V_26 ) ;
V_28:
F_18 ( V_24 , V_19 ) ;
V_7:
return F_19 ( V_22 ) ;
}
static void F_20 ( struct V_17 * V_19 )
{
int V_21 ;
for ( V_21 = 0 ; V_21 < V_35 ; V_21 ++ )
F_8 ( V_19 -> V_25 [ V_21 ] . V_26 ) ;
F_18 ( V_24 , V_19 ) ;
}
struct V_17 * F_21 ( unsigned long V_37 , struct V_17 * V_38 )
{
if ( ! ( V_37 & V_39 ) )
return F_13 ( V_38 ) ;
if ( V_37 & ( V_40 | V_41 ) )
return F_19 ( - V_42 ) ;
return F_9 ( V_38 ) ;
}
void F_22 ( struct V_31 * V_31 )
{
struct V_17 * V_19 , * V_32 ;
V_19 = F_23 ( V_31 , struct V_17 , V_31 ) ;
V_32 = V_19 -> V_32 ;
F_20 ( V_19 ) ;
if ( V_32 != NULL )
F_17 ( V_32 ) ;
}
void F_24 ( struct V_17 * V_43 )
{
int V_44 ;
int V_45 ;
struct V_46 * V_47 ;
F_25 ( & V_48 ) ;
V_44 = F_26 ( V_43 , 1 ) ;
while ( V_44 > 0 ) {
F_27 () ;
V_47 = F_28 ( F_29 ( V_44 ) , V_49 ) ;
if ( V_47 )
F_30 ( V_50 , V_51 , V_47 ) ;
F_31 () ;
V_44 = F_26 ( V_43 , V_44 ) ;
}
F_32 ( & V_48 ) ;
do {
F_33 ( V_52 ) ;
V_45 = F_34 ( - 1 , NULL , V_53 , NULL ) ;
} while ( V_45 != - V_54 );
F_35 ( V_43 ) ;
return;
}
static T_1 int F_36 ( void )
{
V_24 = F_37 ( V_17 , V_55 ) ;
return 0 ;
}
