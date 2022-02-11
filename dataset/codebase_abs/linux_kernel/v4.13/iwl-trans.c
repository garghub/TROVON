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
F_7 ( ! V_8 -> V_19 && ! V_8 -> V_20 ) ;
return V_9 ;
}
void F_8 ( struct V_1 * V_9 )
{
F_9 ( V_9 -> V_16 ) ;
}
int F_10 ( struct V_1 * V_9 , struct V_21 * V_22 )
{
int V_23 ;
if ( F_11 ( ! ( V_22 -> V_24 & V_25 ) &&
F_12 ( V_26 , & V_9 -> V_27 ) ) )
return - V_28 ;
if ( F_11 ( F_12 ( V_29 , & V_9 -> V_27 ) ) )
return - V_30 ;
if ( F_11 ( V_9 -> V_31 != V_32 ) ) {
F_13 ( V_9 , L_3 , V_33 , V_9 -> V_31 ) ;
return - V_30 ;
}
if ( F_7 ( ( V_22 -> V_24 & V_34 ) &&
! ( V_22 -> V_24 & V_35 ) ) )
return - V_36 ;
if ( ! ( V_22 -> V_24 & V_35 ) )
F_14 ( & V_9 -> V_13 ) ;
if ( V_9 -> V_37 && ! F_15 ( V_22 -> V_38 ) )
V_22 -> V_38 = F_16 ( V_22 -> V_38 ) ;
V_23 = V_9 -> V_8 -> V_39 ( V_9 , V_22 ) ;
if ( ! ( V_22 -> V_24 & V_35 ) )
F_17 ( & V_9 -> V_13 ) ;
if ( F_7 ( ( V_22 -> V_24 & V_40 ) && ! V_23 && ! V_22 -> V_41 ) )
return - V_30 ;
return V_23 ;
}
static int F_18 ( const void * V_42 , const void * V_43 )
{
const struct V_44 * V_45 = V_43 ;
T_1 V_46 = * ( T_1 * ) V_42 ;
T_1 V_47 = V_45 -> V_48 ;
return ( V_46 - V_47 ) ;
}
const char * F_19 ( struct V_1 * V_9 , T_2 V_38 )
{
T_1 V_49 , V_22 ;
struct V_44 * V_23 ;
const struct V_50 * V_51 ;
T_3 V_52 = sizeof( struct V_44 ) ;
V_49 = F_15 ( V_38 ) ;
V_22 = F_20 ( V_38 ) ;
if ( ! V_9 -> V_53 || V_49 >= V_9 -> V_54 ||
! V_9 -> V_53 [ V_49 ] . V_51 )
return L_4 ;
V_51 = & V_9 -> V_53 [ V_49 ] ;
V_23 = bsearch ( & V_22 , V_51 -> V_51 , V_51 -> V_52 , V_52 , F_18 ) ;
if ( ! V_23 )
return L_4 ;
return V_23 -> V_55 ;
}
int F_21 ( const struct V_56 * V_9 )
{
int V_57 , V_58 ;
const struct V_50 * V_51 ;
for ( V_57 = 0 ; V_57 < V_9 -> V_54 ; V_57 ++ ) {
V_51 = & V_9 -> V_53 [ V_57 ] ;
if ( ! V_51 -> V_51 )
continue;
for ( V_58 = 0 ; V_58 < V_51 -> V_52 - 1 ; V_58 ++ )
if ( V_51 -> V_51 [ V_58 ] . V_48 > V_51 -> V_51 [ V_58 + 1 ] . V_48 )
return - 1 ;
}
return 0 ;
}
