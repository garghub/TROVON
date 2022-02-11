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
int F_9 ( struct V_22 * V_23 , T_1 V_2 ,
struct V_24 * V_25 , unsigned int V_26 ,
const void * V_27 , struct V_11 * * V_13 )
{
const struct V_15 * V_16 ;
int V_21 = - V_28 ;
if ( V_2 == V_9 ||
V_2 > V_18 )
return V_21 ;
V_21 = - V_29 ;
F_10 () ;
V_16 = F_11 ( V_20 [ V_2 ] ) ;
if ( F_12 ( V_16 && V_16 -> V_30 && F_13 ( V_16 -> V_31 ) ) ) {
V_21 = V_16 -> V_30 ( V_23 , V_25 , V_26 , V_27 , V_13 ) ;
if ( V_21 )
F_14 ( V_16 -> V_31 ) ;
}
F_15 () ;
return V_21 ;
}
int F_16 ( T_1 V_2 )
{
const struct V_15 * V_16 ;
int V_21 = - V_28 ;
if ( V_2 == V_9 ||
V_2 > V_18 )
return V_21 ;
F_10 () ;
V_16 = F_11 ( V_20 [ V_2 ] ) ;
F_15 () ;
#ifdef F_17
if ( ! V_16 ) {
const char * V_32 = F_1 ( V_2 ) ;
if ( V_32 ) {
F_18 () ;
F_19 ( L_5 , V_32 ) ;
F_20 () ;
F_10 () ;
V_16 = F_11 ( V_20 [ V_2 ] ) ;
F_15 () ;
}
}
#endif
return V_16 ? 0 : - V_29 ;
}
int F_21 ( struct V_24 * V_33 , int V_34 )
{
struct V_35 * V_36 = (struct V_35 * ) V_33 ;
struct V_24 * V_37 ;
struct V_24 * V_38 ;
struct V_24 * V_39 ;
T_1 V_2 ;
int V_40 ;
while ( F_22 ( V_36 , V_34 ) ) {
V_40 = F_23 ( V_36 ) ;
if ( V_40 > 0 ) {
V_38 = F_24 ( V_36 ) ;
V_39 = F_25 ( V_38 , V_40 , V_41 ) ;
V_37 = F_25 ( V_38 , V_40 , V_42 ) ;
if ( V_37 ) {
V_2 = F_26 ( V_37 ) ;
if ( F_16 ( V_2 ) != 0 )
return - V_29 ;
}
}
V_36 = F_27 ( V_36 , & V_34 ) ;
}
return 0 ;
}
void F_28 ( struct V_11 * V_13 )
{
const struct V_15 * V_16 = V_20 [ V_13 -> type ] ;
if ( V_16 -> V_43 ) {
V_16 -> V_43 ( V_13 ) ;
F_29 ( V_13 , V_44 ) ;
} else {
F_30 ( V_13 ) ;
}
F_14 ( V_16 -> V_31 ) ;
}
int F_31 ( struct V_45 * V_46 , struct V_11 * V_47 )
{
const struct V_15 * V_16 ;
struct V_24 * V_48 ;
int V_21 = - V_28 ;
if ( ! V_47 )
return 0 ;
if ( V_47 -> type == V_9 ||
V_47 -> type > V_18 )
return 0 ;
V_21 = - V_29 ;
V_48 = F_32 ( V_46 , V_41 ) ;
F_10 () ;
V_16 = F_11 ( V_20 [ V_47 -> type ] ) ;
if ( F_12 ( V_16 && V_16 -> V_49 ) )
V_21 = V_16 -> V_49 ( V_46 , V_47 ) ;
F_15 () ;
if ( V_21 )
goto V_50;
F_33 ( V_46 , V_48 ) ;
V_21 = F_34 ( V_46 , V_42 , V_47 -> type ) ;
if ( V_21 )
goto V_50;
return 0 ;
V_50:
F_35 ( V_46 , V_48 ) ;
return ( V_21 == - V_29 ? 0 : V_21 ) ;
}
int F_36 ( struct V_11 * V_47 )
{
const struct V_15 * V_16 ;
int V_21 = 0 ;
if ( ! V_47 )
return 0 ;
if ( V_47 -> type == V_9 ||
V_47 -> type > V_18 )
return 0 ;
F_10 () ;
V_16 = F_11 ( V_20 [ V_47 -> type ] ) ;
if ( F_12 ( V_16 && V_16 -> V_51 ) )
V_21 = F_37 ( V_16 -> V_51 ( V_47 ) ) ;
F_15 () ;
return V_21 ;
}
int F_38 ( struct V_11 * V_52 , struct V_11 * V_53 )
{
const struct V_15 * V_16 ;
int V_21 = 0 ;
if ( ! V_52 && ! V_53 )
return 0 ;
if ( ! V_52 || ! V_53 )
return 1 ;
if ( V_52 -> type != V_53 -> type )
return 1 ;
if ( V_52 -> type == V_9 ||
V_52 -> type > V_18 )
return 0 ;
F_10 () ;
V_16 = F_11 ( V_20 [ V_52 -> type ] ) ;
if ( F_12 ( V_16 && V_16 -> V_54 ) )
V_21 = V_16 -> V_54 ( V_52 , V_53 ) ;
F_15 () ;
return V_21 ;
}
int F_39 ( struct V_55 * V_55 , struct V_56 * V_57 , struct V_45 * V_46 )
{
struct V_58 * V_59 = F_40 ( V_46 ) ;
const struct V_15 * V_16 ;
struct V_11 * V_47 ;
int V_21 = - V_28 ;
if ( ! V_59 )
goto V_60;
V_47 = V_59 -> V_47 ;
if ( V_47 -> type == V_9 ||
V_47 -> type > V_18 )
return 0 ;
V_21 = - V_29 ;
F_10 () ;
V_16 = F_11 ( V_20 [ V_47 -> type ] ) ;
if ( F_12 ( V_16 && V_16 -> V_61 ) )
V_21 = V_16 -> V_61 ( V_55 , V_57 , V_46 ) ;
F_15 () ;
if ( V_21 == - V_29 )
goto V_60;
return V_21 ;
V_60:
F_41 ( V_46 ) ;
return V_21 ;
}
int F_42 ( struct V_45 * V_46 )
{
struct V_58 * V_59 = F_40 ( V_46 ) ;
const struct V_15 * V_16 ;
struct V_11 * V_47 ;
int V_21 = - V_28 ;
if ( ! V_59 )
goto V_60;
V_47 = V_59 -> V_47 ;
if ( V_47 -> type == V_9 ||
V_47 -> type > V_18 )
return 0 ;
V_21 = - V_29 ;
F_10 () ;
V_16 = F_11 ( V_20 [ V_47 -> type ] ) ;
if ( F_12 ( V_16 && V_16 -> V_62 ) )
V_21 = V_16 -> V_62 ( V_46 ) ;
F_15 () ;
if ( V_21 == - V_29 )
goto V_60;
return V_21 ;
V_60:
F_41 ( V_46 ) ;
return V_21 ;
}
int F_43 ( struct V_45 * V_46 )
{
struct V_58 * V_59 = F_40 ( V_46 ) ;
const struct V_15 * V_16 ;
struct V_11 * V_47 ;
int V_21 = - V_28 ;
if ( ! V_59 )
goto V_60;
V_47 = V_59 -> V_47 ;
if ( V_47 -> type == V_9 ||
V_47 -> type > V_18 )
return 0 ;
V_21 = - V_29 ;
F_10 () ;
V_16 = F_11 ( V_20 [ V_47 -> type ] ) ;
if ( F_12 ( V_16 && V_16 -> V_63 ) )
V_21 = V_16 -> V_63 ( V_46 ) ;
F_15 () ;
if ( V_21 == - V_29 )
goto V_60;
return V_21 ;
V_60:
F_41 ( V_46 ) ;
return V_21 ;
}
