struct V_1 * F_1 ( int V_2 )
{
struct V_1 * V_3 ;
V_3 = F_2 ( sizeof( * V_3 ) + V_2 , V_4 ) ;
return V_3 ;
}
int F_3 ( const struct V_5 * V_6 ,
unsigned int V_7 )
{
if ( V_7 > V_8 )
return - V_9 ;
return ! F_4 ( ( const struct V_5 * * )
& V_10 [ V_7 ] ,
NULL , V_6 ) ? 0 : - 1 ;
}
int F_5 ( const struct V_5 * V_6 ,
unsigned int V_11 )
{
int V_12 ;
if ( V_11 == V_13 ||
V_11 > V_8 )
return - V_9 ;
V_12 = ( F_4 ( ( const struct V_5 * * )
& V_10 [ V_11 ] ,
V_6 , NULL ) == V_6 ) ? 0 : - 1 ;
F_6 () ;
return V_12 ;
}
int F_7 ( struct V_14 * V_15 , T_1 V_11 ,
struct V_16 * V_17 , unsigned int V_18 ,
const void * V_19 , struct V_1 * * V_3 )
{
const struct V_5 * V_6 ;
int V_12 = - V_20 ;
if ( V_11 == V_13 ||
V_11 > V_8 )
return V_12 ;
V_12 = - V_21 ;
F_8 () ;
V_6 = F_9 ( V_10 [ V_11 ] ) ;
if ( F_10 ( V_6 && V_6 -> V_22 ) )
V_12 = V_6 -> V_22 ( V_15 , V_17 , V_18 , V_19 , V_3 ) ;
F_11 () ;
return V_12 ;
}
int F_12 ( struct V_23 * V_24 , struct V_1 * V_25 )
{
const struct V_5 * V_6 ;
struct V_16 * V_26 ;
int V_12 = - V_20 ;
if ( ! V_25 )
return 0 ;
if ( V_25 -> type == V_13 ||
V_25 -> type > V_8 )
return 0 ;
V_12 = - V_21 ;
V_26 = F_13 ( V_24 , V_27 ) ;
F_8 () ;
V_6 = F_9 ( V_10 [ V_25 -> type ] ) ;
if ( F_10 ( V_6 && V_6 -> V_28 ) )
V_12 = V_6 -> V_28 ( V_24 , V_25 ) ;
F_11 () ;
if ( V_12 )
goto V_29;
F_14 ( V_24 , V_26 ) ;
V_12 = F_15 ( V_24 , V_30 , V_25 -> type ) ;
if ( V_12 )
goto V_29;
return 0 ;
V_29:
F_16 ( V_24 , V_26 ) ;
return ( V_12 == - V_21 ? 0 : V_12 ) ;
}
int F_17 ( struct V_1 * V_25 )
{
const struct V_5 * V_6 ;
int V_12 = 0 ;
if ( ! V_25 )
return 0 ;
if ( V_25 -> type == V_13 ||
V_25 -> type > V_8 )
return 0 ;
F_8 () ;
V_6 = F_9 ( V_10 [ V_25 -> type ] ) ;
if ( F_10 ( V_6 && V_6 -> V_31 ) )
V_12 = F_18 ( V_6 -> V_31 ( V_25 ) ) ;
F_11 () ;
return V_12 ;
}
int F_19 ( struct V_1 * V_32 , struct V_1 * V_33 )
{
const struct V_5 * V_6 ;
int V_12 = 0 ;
if ( ! V_32 && ! V_33 )
return 0 ;
if ( ! V_32 || ! V_33 )
return 1 ;
if ( V_32 -> type != V_33 -> type )
return 1 ;
if ( V_32 -> type == V_13 ||
V_32 -> type > V_8 )
return 0 ;
F_8 () ;
V_6 = F_9 ( V_10 [ V_32 -> type ] ) ;
if ( F_10 ( V_6 && V_6 -> V_34 ) )
V_12 = V_6 -> V_34 ( V_32 , V_33 ) ;
F_11 () ;
return V_12 ;
}
int F_20 ( struct V_35 * V_35 , struct V_36 * V_37 , struct V_23 * V_24 )
{
struct V_38 * V_39 = F_21 ( V_24 ) ;
const struct V_5 * V_6 ;
struct V_1 * V_25 ;
int V_12 = - V_20 ;
if ( ! V_39 )
goto V_40;
V_25 = V_39 -> V_25 ;
if ( V_25 -> type == V_13 ||
V_25 -> type > V_8 )
return 0 ;
V_12 = - V_21 ;
F_8 () ;
V_6 = F_9 ( V_10 [ V_25 -> type ] ) ;
if ( F_10 ( V_6 && V_6 -> V_41 ) )
V_12 = V_6 -> V_41 ( V_35 , V_37 , V_24 ) ;
F_11 () ;
if ( V_12 == - V_21 )
goto V_40;
return V_12 ;
V_40:
F_22 ( V_24 ) ;
return V_12 ;
}
int F_23 ( struct V_23 * V_24 )
{
struct V_38 * V_39 = F_21 ( V_24 ) ;
const struct V_5 * V_6 ;
struct V_1 * V_25 ;
int V_12 = - V_20 ;
if ( ! V_39 )
goto V_40;
V_25 = V_39 -> V_25 ;
if ( V_25 -> type == V_13 ||
V_25 -> type > V_8 )
return 0 ;
V_12 = - V_21 ;
F_8 () ;
V_6 = F_9 ( V_10 [ V_25 -> type ] ) ;
if ( F_10 ( V_6 && V_6 -> V_42 ) )
V_12 = V_6 -> V_42 ( V_24 ) ;
F_11 () ;
if ( V_12 == - V_21 )
goto V_40;
return V_12 ;
V_40:
F_22 ( V_24 ) ;
return V_12 ;
}
