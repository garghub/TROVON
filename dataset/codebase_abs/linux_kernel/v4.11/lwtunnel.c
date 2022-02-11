static const char * F_1 ( enum V_1 V_2 )
{
switch ( V_2 ) {
case V_3 :
return L_1 ;
case V_4 :
return L_2 ;
case V_5 :
return L_3 ;
case V_6 :
return L_4 ;
case V_7 :
case V_8 :
case V_9 :
case V_10 :
F_2 ( 1 ) ;
break;
}
return NULL ;
}
struct V_11 * F_3 ( int V_12 )
{
struct V_11 * V_13 ;
V_13 = F_4 ( sizeof( * V_13 ) + V_12 , V_14 ) ;
return V_13 ;
}
int F_5 ( const struct V_15 * V_16 ,
unsigned int V_17 )
{
if ( V_17 > V_18 )
return - V_19 ;
return ! F_6 ( ( const struct V_15 * * )
& V_20 [ V_17 ] ,
NULL , V_16 ) ? 0 : - 1 ;
}
int F_7 ( const struct V_15 * V_16 ,
unsigned int V_2 )
{
int V_21 ;
if ( V_2 == V_9 ||
V_2 > V_18 )
return - V_19 ;
V_21 = ( F_6 ( ( const struct V_15 * * )
& V_20 [ V_2 ] ,
V_16 , NULL ) == V_16 ) ? 0 : - 1 ;
F_8 () ;
return V_21 ;
}
int F_9 ( T_1 V_2 ,
struct V_22 * V_23 , unsigned int V_24 ,
const void * V_25 , struct V_11 * * V_13 )
{
const struct V_15 * V_16 ;
int V_21 = - V_26 ;
if ( V_2 == V_9 ||
V_2 > V_18 )
return V_21 ;
V_21 = - V_27 ;
F_10 () ;
V_16 = F_11 ( V_20 [ V_2 ] ) ;
if ( F_12 ( V_16 && V_16 -> V_28 && F_13 ( V_16 -> V_29 ) ) ) {
V_21 = V_16 -> V_28 ( V_23 , V_24 , V_25 , V_13 ) ;
if ( V_21 )
F_14 ( V_16 -> V_29 ) ;
}
F_15 () ;
return V_21 ;
}
int F_16 ( T_1 V_2 )
{
const struct V_15 * V_16 ;
int V_21 = - V_26 ;
if ( V_2 == V_9 ||
V_2 > V_18 )
return V_21 ;
F_10 () ;
V_16 = F_11 ( V_20 [ V_2 ] ) ;
F_15 () ;
#ifdef F_17
if ( ! V_16 ) {
const char * V_30 = F_1 ( V_2 ) ;
if ( V_30 ) {
F_18 () ;
F_19 ( L_5 , V_30 ) ;
F_20 () ;
F_10 () ;
V_16 = F_11 ( V_20 [ V_2 ] ) ;
F_15 () ;
}
}
#endif
return V_16 ? 0 : - V_27 ;
}
int F_21 ( struct V_22 * V_31 , int V_32 )
{
struct V_33 * V_34 = (struct V_33 * ) V_31 ;
struct V_22 * V_35 ;
struct V_22 * V_36 ;
struct V_22 * V_37 ;
T_1 V_2 ;
int V_38 ;
while ( F_22 ( V_34 , V_32 ) ) {
V_38 = F_23 ( V_34 ) ;
if ( V_38 > 0 ) {
V_36 = F_24 ( V_34 ) ;
V_37 = F_25 ( V_36 , V_38 , V_39 ) ;
V_35 = F_25 ( V_36 , V_38 , V_40 ) ;
if ( V_35 ) {
V_2 = F_26 ( V_35 ) ;
if ( F_16 ( V_2 ) != 0 )
return - V_27 ;
}
}
V_34 = F_27 ( V_34 , & V_32 ) ;
}
return 0 ;
}
void F_28 ( struct V_11 * V_13 )
{
const struct V_15 * V_16 = V_20 [ V_13 -> type ] ;
if ( V_16 -> V_41 ) {
V_16 -> V_41 ( V_13 ) ;
F_29 ( V_13 , V_42 ) ;
} else {
F_30 ( V_13 ) ;
}
F_14 ( V_16 -> V_29 ) ;
}
int F_31 ( struct V_43 * V_44 , struct V_11 * V_45 )
{
const struct V_15 * V_16 ;
struct V_22 * V_46 ;
int V_21 = - V_26 ;
if ( ! V_45 )
return 0 ;
if ( V_45 -> type == V_9 ||
V_45 -> type > V_18 )
return 0 ;
V_21 = - V_27 ;
V_46 = F_32 ( V_44 , V_39 ) ;
F_10 () ;
V_16 = F_11 ( V_20 [ V_45 -> type ] ) ;
if ( F_12 ( V_16 && V_16 -> V_47 ) )
V_21 = V_16 -> V_47 ( V_44 , V_45 ) ;
F_15 () ;
if ( V_21 )
goto V_48;
F_33 ( V_44 , V_46 ) ;
V_21 = F_34 ( V_44 , V_40 , V_45 -> type ) ;
if ( V_21 )
goto V_48;
return 0 ;
V_48:
F_35 ( V_44 , V_46 ) ;
return ( V_21 == - V_27 ? 0 : V_21 ) ;
}
int F_36 ( struct V_11 * V_45 )
{
const struct V_15 * V_16 ;
int V_21 = 0 ;
if ( ! V_45 )
return 0 ;
if ( V_45 -> type == V_9 ||
V_45 -> type > V_18 )
return 0 ;
F_10 () ;
V_16 = F_11 ( V_20 [ V_45 -> type ] ) ;
if ( F_12 ( V_16 && V_16 -> V_49 ) )
V_21 = F_37 ( V_16 -> V_49 ( V_45 ) ) ;
F_15 () ;
return V_21 ;
}
int F_38 ( struct V_11 * V_50 , struct V_11 * V_51 )
{
const struct V_15 * V_16 ;
int V_21 = 0 ;
if ( ! V_50 && ! V_51 )
return 0 ;
if ( ! V_50 || ! V_51 )
return 1 ;
if ( V_50 -> type != V_51 -> type )
return 1 ;
if ( V_50 -> type == V_9 ||
V_50 -> type > V_18 )
return 0 ;
F_10 () ;
V_16 = F_11 ( V_20 [ V_50 -> type ] ) ;
if ( F_12 ( V_16 && V_16 -> V_52 ) )
V_21 = V_16 -> V_52 ( V_50 , V_51 ) ;
F_15 () ;
return V_21 ;
}
int F_39 ( struct V_53 * V_53 , struct V_54 * V_55 , struct V_43 * V_44 )
{
struct V_56 * V_57 = F_40 ( V_44 ) ;
const struct V_15 * V_16 ;
struct V_11 * V_45 ;
int V_21 = - V_26 ;
if ( ! V_57 )
goto V_58;
V_45 = V_57 -> V_45 ;
if ( V_45 -> type == V_9 ||
V_45 -> type > V_18 )
return 0 ;
V_21 = - V_27 ;
F_10 () ;
V_16 = F_11 ( V_20 [ V_45 -> type ] ) ;
if ( F_12 ( V_16 && V_16 -> V_59 ) )
V_21 = V_16 -> V_59 ( V_53 , V_55 , V_44 ) ;
F_15 () ;
if ( V_21 == - V_27 )
goto V_58;
return V_21 ;
V_58:
F_41 ( V_44 ) ;
return V_21 ;
}
int F_42 ( struct V_43 * V_44 )
{
struct V_56 * V_57 = F_40 ( V_44 ) ;
const struct V_15 * V_16 ;
struct V_11 * V_45 ;
int V_21 = - V_26 ;
if ( ! V_57 )
goto V_58;
V_45 = V_57 -> V_45 ;
if ( V_45 -> type == V_9 ||
V_45 -> type > V_18 )
return 0 ;
V_21 = - V_27 ;
F_10 () ;
V_16 = F_11 ( V_20 [ V_45 -> type ] ) ;
if ( F_12 ( V_16 && V_16 -> V_60 ) )
V_21 = V_16 -> V_60 ( V_44 ) ;
F_15 () ;
if ( V_21 == - V_27 )
goto V_58;
return V_21 ;
V_58:
F_41 ( V_44 ) ;
return V_21 ;
}
int F_43 ( struct V_43 * V_44 )
{
struct V_56 * V_57 = F_40 ( V_44 ) ;
const struct V_15 * V_16 ;
struct V_11 * V_45 ;
int V_21 = - V_26 ;
if ( ! V_57 )
goto V_58;
V_45 = V_57 -> V_45 ;
if ( V_45 -> type == V_9 ||
V_45 -> type > V_18 )
return 0 ;
V_21 = - V_27 ;
F_10 () ;
V_16 = F_11 ( V_20 [ V_45 -> type ] ) ;
if ( F_12 ( V_16 && V_16 -> V_61 ) )
V_21 = V_16 -> V_61 ( V_44 ) ;
F_15 () ;
if ( V_21 == - V_27 )
goto V_58;
return V_21 ;
V_58:
F_41 ( V_44 ) ;
return V_21 ;
}
