struct V_1 * F_1 ( unsigned int V_2 ,
struct V_3 * V_4 ,
const struct V_5 * V_6 ,
const struct V_7 * V_8 ,
T_1 V_9 )
{
struct V_1 * V_10 ;
#ifdef F_2
static struct V_11 V_12 ;
#endif
V_10 = F_3 ( sizeof( * V_10 ) + V_2 , V_13 ) ;
if ( ! V_10 )
return NULL ;
#ifdef F_2
F_4 ( & V_10 -> V_14 , L_1 ,
& V_12 , 0 ) ;
#endif
V_10 -> V_4 = V_4 ;
V_10 -> V_6 = V_6 ;
V_10 -> V_8 = V_8 ;
V_10 -> V_9 = V_9 ;
V_10 -> V_15 = 1 ;
snprintf ( V_10 -> V_16 , sizeof( V_10 -> V_16 ) ,
L_2 , F_5 ( V_10 -> V_4 ) ) ;
V_10 -> V_17 =
F_6 ( V_10 -> V_16 ,
sizeof( struct V_18 )
+ V_10 -> V_9 ,
sizeof( void * ) ,
V_19 ,
NULL ) ;
if ( ! V_10 -> V_17 )
goto free;
return V_10 ;
free:
F_7 ( V_10 ) ;
return NULL ;
}
void F_8 ( struct V_1 * V_10 )
{
F_9 ( V_10 -> V_17 ) ;
F_7 ( V_10 ) ;
}
int F_10 ( struct V_1 * V_10 , struct V_20 * V_21 )
{
int V_22 ;
if ( F_11 ( ! ( V_21 -> V_23 & V_24 ) &&
F_12 ( V_25 , & V_10 -> V_26 ) ) )
return - V_27 ;
if ( F_11 ( F_12 ( V_28 , & V_10 -> V_26 ) ) )
return - V_29 ;
if ( F_11 ( V_10 -> V_30 != V_31 ) ) {
F_13 ( V_10 , L_3 , V_32 , V_10 -> V_30 ) ;
return - V_29 ;
}
if ( F_14 ( ( V_21 -> V_23 & V_33 ) &&
! ( V_21 -> V_23 & V_34 ) ) )
return - V_35 ;
if ( ! ( V_21 -> V_23 & V_34 ) )
F_15 ( & V_10 -> V_14 ) ;
V_22 = V_10 -> V_8 -> V_36 ( V_10 , V_21 ) ;
if ( ! ( V_21 -> V_23 & V_34 ) )
F_16 ( & V_10 -> V_14 ) ;
return V_22 ;
}
static int F_17 ( const void * V_37 , const void * V_38 )
{
const struct V_39 * V_40 = V_38 ;
T_2 V_41 = * ( T_2 * ) V_37 ;
T_2 V_42 = V_40 -> V_43 ;
return ( V_41 - V_42 ) ;
}
const char * F_18 ( struct V_1 * V_10 , T_3 V_44 )
{
T_2 V_45 , V_21 ;
struct V_39 * V_22 ;
const struct V_46 * V_47 ;
T_1 V_48 = sizeof( struct V_39 ) ;
V_45 = F_19 ( V_44 ) ;
V_21 = F_20 ( V_44 ) ;
if ( ! V_10 -> V_49 || V_45 >= V_10 -> V_50 ||
! V_10 -> V_49 [ V_45 ] . V_47 )
return L_4 ;
V_47 = & V_10 -> V_49 [ V_45 ] ;
V_22 = bsearch ( & V_21 , V_47 -> V_47 , V_47 -> V_48 , V_48 , F_17 ) ;
if ( ! V_22 )
return L_4 ;
return V_22 -> V_51 ;
}
int F_21 ( const struct V_52 * V_10 )
{
int V_53 , V_54 ;
const struct V_46 * V_47 ;
for ( V_53 = 0 ; V_53 < V_10 -> V_50 ; V_53 ++ ) {
V_47 = & V_10 -> V_49 [ V_53 ] ;
if ( ! V_47 -> V_47 )
continue;
for ( V_54 = 0 ; V_54 < V_47 -> V_48 - 1 ; V_54 ++ )
if ( V_47 -> V_47 [ V_54 ] . V_43 > V_47 -> V_47 [ V_54 + 1 ] . V_43 )
return - 1 ;
}
return 0 ;
}
