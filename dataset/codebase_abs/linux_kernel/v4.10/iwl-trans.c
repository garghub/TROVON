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
V_10 = F_3 ( V_4 , sizeof( * V_10 ) + V_2 , V_13 ) ;
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
return NULL ;
return V_10 ;
}
void F_7 ( struct V_1 * V_10 )
{
F_8 ( V_10 -> V_17 ) ;
}
int F_9 ( struct V_1 * V_10 , struct V_20 * V_21 )
{
int V_22 ;
if ( F_10 ( ! ( V_21 -> V_23 & V_24 ) &&
F_11 ( V_25 , & V_10 -> V_26 ) ) )
return - V_27 ;
if ( F_10 ( F_11 ( V_28 , & V_10 -> V_26 ) ) )
return - V_29 ;
if ( F_10 ( V_10 -> V_30 != V_31 ) ) {
F_12 ( V_10 , L_3 , V_32 , V_10 -> V_30 ) ;
return - V_29 ;
}
if ( F_13 ( ( V_21 -> V_23 & V_33 ) &&
! ( V_21 -> V_23 & V_34 ) ) )
return - V_35 ;
if ( ! ( V_21 -> V_23 & V_34 ) )
F_14 ( & V_10 -> V_14 ) ;
if ( V_10 -> V_36 && ! F_15 ( V_21 -> V_37 ) )
V_21 -> V_37 = F_16 ( V_21 -> V_37 ) ;
V_22 = V_10 -> V_8 -> V_38 ( V_10 , V_21 ) ;
if ( ! ( V_21 -> V_23 & V_34 ) )
F_17 ( & V_10 -> V_14 ) ;
return V_22 ;
}
static int F_18 ( const void * V_39 , const void * V_40 )
{
const struct V_41 * V_42 = V_40 ;
T_2 V_43 = * ( T_2 * ) V_39 ;
T_2 V_44 = V_42 -> V_45 ;
return ( V_43 - V_44 ) ;
}
const char * F_19 ( struct V_1 * V_10 , T_3 V_37 )
{
T_2 V_46 , V_21 ;
struct V_41 * V_22 ;
const struct V_47 * V_48 ;
T_1 V_49 = sizeof( struct V_41 ) ;
V_46 = F_15 ( V_37 ) ;
V_21 = F_20 ( V_37 ) ;
if ( ! V_10 -> V_50 || V_46 >= V_10 -> V_51 ||
! V_10 -> V_50 [ V_46 ] . V_48 )
return L_4 ;
V_48 = & V_10 -> V_50 [ V_46 ] ;
V_22 = bsearch ( & V_21 , V_48 -> V_48 , V_48 -> V_49 , V_49 , F_18 ) ;
if ( ! V_22 )
return L_4 ;
return V_22 -> V_52 ;
}
int F_21 ( const struct V_53 * V_10 )
{
int V_54 , V_55 ;
const struct V_47 * V_48 ;
for ( V_54 = 0 ; V_54 < V_10 -> V_51 ; V_54 ++ ) {
V_48 = & V_10 -> V_50 [ V_54 ] ;
if ( ! V_48 -> V_48 )
continue;
for ( V_55 = 0 ; V_55 < V_48 -> V_49 - 1 ; V_55 ++ )
if ( V_48 -> V_48 [ V_55 ] . V_45 > V_48 -> V_48 [ V_55 + 1 ] . V_45 )
return - 1 ;
}
return 0 ;
}
