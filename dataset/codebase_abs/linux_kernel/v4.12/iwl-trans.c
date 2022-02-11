struct V_1 * F_1 ( unsigned int V_2 ,
struct V_3 * V_4 ,
const struct V_5 * V_6 ,
const struct V_7 * V_8 )
{
struct V_1 * V_9 ;
#ifdef F_2
static struct V_10 V_11 ;
#endif
V_9 = F_3 ( V_4 , sizeof( * V_9 ) + V_2 , V_12 ) ;
if ( ! V_9 )
return NULL ;
#ifdef F_2
F_4 ( & V_9 -> V_13 , L_1 ,
& V_11 , 0 ) ;
#endif
V_9 -> V_4 = V_4 ;
V_9 -> V_6 = V_6 ;
V_9 -> V_8 = V_8 ;
V_9 -> V_14 = 1 ;
snprintf ( V_9 -> V_15 , sizeof( V_9 -> V_15 ) ,
L_2 , F_5 ( V_9 -> V_4 ) ) ;
V_9 -> V_16 =
F_6 ( V_9 -> V_15 ,
sizeof( struct V_17 ) ,
sizeof( void * ) ,
V_18 ,
NULL ) ;
if ( ! V_9 -> V_16 )
return NULL ;
return V_9 ;
}
void F_7 ( struct V_1 * V_9 )
{
F_8 ( V_9 -> V_16 ) ;
}
int F_9 ( struct V_1 * V_9 , struct V_19 * V_20 )
{
int V_21 ;
if ( F_10 ( ! ( V_20 -> V_22 & V_23 ) &&
F_11 ( V_24 , & V_9 -> V_25 ) ) )
return - V_26 ;
if ( F_10 ( F_11 ( V_27 , & V_9 -> V_25 ) ) )
return - V_28 ;
if ( F_10 ( V_9 -> V_29 != V_30 ) ) {
F_12 ( V_9 , L_3 , V_31 , V_9 -> V_29 ) ;
return - V_28 ;
}
if ( F_13 ( ( V_20 -> V_22 & V_32 ) &&
! ( V_20 -> V_22 & V_33 ) ) )
return - V_34 ;
if ( ! ( V_20 -> V_22 & V_33 ) )
F_14 ( & V_9 -> V_13 ) ;
if ( V_9 -> V_35 && ! F_15 ( V_20 -> V_36 ) )
V_20 -> V_36 = F_16 ( V_20 -> V_36 ) ;
V_21 = V_9 -> V_8 -> V_37 ( V_9 , V_20 ) ;
if ( ! ( V_20 -> V_22 & V_33 ) )
F_17 ( & V_9 -> V_13 ) ;
return V_21 ;
}
static int F_18 ( const void * V_38 , const void * V_39 )
{
const struct V_40 * V_41 = V_39 ;
T_1 V_42 = * ( T_1 * ) V_38 ;
T_1 V_43 = V_41 -> V_44 ;
return ( V_42 - V_43 ) ;
}
const char * F_19 ( struct V_1 * V_9 , T_2 V_36 )
{
T_1 V_45 , V_20 ;
struct V_40 * V_21 ;
const struct V_46 * V_47 ;
T_3 V_48 = sizeof( struct V_40 ) ;
V_45 = F_15 ( V_36 ) ;
V_20 = F_20 ( V_36 ) ;
if ( ! V_9 -> V_49 || V_45 >= V_9 -> V_50 ||
! V_9 -> V_49 [ V_45 ] . V_47 )
return L_4 ;
V_47 = & V_9 -> V_49 [ V_45 ] ;
V_21 = bsearch ( & V_20 , V_47 -> V_47 , V_47 -> V_48 , V_48 , F_18 ) ;
if ( ! V_21 )
return L_4 ;
return V_21 -> V_51 ;
}
int F_21 ( const struct V_52 * V_9 )
{
int V_53 , V_54 ;
const struct V_46 * V_47 ;
for ( V_53 = 0 ; V_53 < V_9 -> V_50 ; V_53 ++ ) {
V_47 = & V_9 -> V_49 [ V_53 ] ;
if ( ! V_47 -> V_47 )
continue;
for ( V_54 = 0 ; V_54 < V_47 -> V_48 - 1 ; V_54 ++ )
if ( V_47 -> V_47 [ V_54 ] . V_44 > V_47 -> V_47 [ V_54 + 1 ] . V_44 )
return - 1 ;
}
return 0 ;
}
