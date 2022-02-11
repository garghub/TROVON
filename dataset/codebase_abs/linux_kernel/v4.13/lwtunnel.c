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
const void * V_25 , struct V_11 * * V_13 ,
struct V_26 * V_27 )
{
const struct V_15 * V_16 ;
bool V_28 = false ;
int V_21 = - V_29 ;
if ( V_2 == V_9 ||
V_2 > V_18 ) {
F_10 ( V_27 , V_23 ,
L_5 ) ;
return V_21 ;
}
V_21 = - V_30 ;
F_11 () ;
V_16 = F_12 ( V_20 [ V_2 ] ) ;
if ( F_13 ( V_16 && V_16 -> V_31 && F_14 ( V_16 -> V_32 ) ) ) {
V_28 = true ;
V_21 = V_16 -> V_31 ( V_23 , V_24 , V_25 , V_13 , V_27 ) ;
if ( V_21 )
F_15 ( V_16 -> V_32 ) ;
}
F_16 () ;
if ( ! V_28 ) {
F_10 ( V_27 , V_23 ,
L_6 ) ;
}
return V_21 ;
}
int F_17 ( T_1 V_2 , struct V_26 * V_27 )
{
const struct V_15 * V_16 ;
int V_21 = - V_29 ;
if ( V_2 == V_9 ||
V_2 > V_18 ) {
F_18 ( V_27 , L_7 ) ;
return V_21 ;
}
F_11 () ;
V_16 = F_12 ( V_20 [ V_2 ] ) ;
F_16 () ;
#ifdef F_19
if ( ! V_16 ) {
const char * V_33 = F_1 ( V_2 ) ;
if ( V_33 ) {
F_20 () ;
F_21 ( L_8 , V_33 ) ;
F_22 () ;
F_11 () ;
V_16 = F_12 ( V_20 [ V_2 ] ) ;
F_16 () ;
}
}
#endif
V_21 = V_16 ? 0 : - V_30 ;
if ( V_21 < 0 )
F_18 ( V_27 , L_9 ) ;
return V_21 ;
}
int F_23 ( struct V_22 * V_34 , int V_35 ,
struct V_26 * V_27 )
{
struct V_36 * V_37 = (struct V_36 * ) V_34 ;
struct V_22 * V_38 ;
struct V_22 * V_39 ;
T_1 V_2 ;
int V_40 ;
while ( F_24 ( V_37 , V_35 ) ) {
V_40 = F_25 ( V_37 ) ;
if ( V_40 > 0 ) {
V_39 = F_26 ( V_37 ) ;
V_38 = F_27 ( V_39 , V_40 , V_41 ) ;
if ( V_38 ) {
V_2 = F_28 ( V_38 ) ;
if ( F_17 ( V_2 ,
V_27 ) != 0 )
return - V_30 ;
}
}
V_37 = F_29 ( V_37 , & V_35 ) ;
}
return 0 ;
}
void F_30 ( struct V_11 * V_13 )
{
const struct V_15 * V_16 = V_20 [ V_13 -> type ] ;
if ( V_16 -> V_42 ) {
V_16 -> V_42 ( V_13 ) ;
F_31 ( V_13 , V_43 ) ;
} else {
F_32 ( V_13 ) ;
}
F_15 ( V_16 -> V_32 ) ;
}
int F_33 ( struct V_44 * V_45 , struct V_11 * V_46 )
{
const struct V_15 * V_16 ;
struct V_22 * V_47 ;
int V_21 ;
if ( ! V_46 )
return 0 ;
if ( V_46 -> type == V_9 ||
V_46 -> type > V_18 )
return 0 ;
V_47 = F_34 ( V_45 , V_48 ) ;
if ( ! V_47 )
return - V_49 ;
V_21 = - V_30 ;
F_11 () ;
V_16 = F_12 ( V_20 [ V_46 -> type ] ) ;
if ( F_13 ( V_16 && V_16 -> V_50 ) )
V_21 = V_16 -> V_50 ( V_45 , V_46 ) ;
F_16 () ;
if ( V_21 )
goto V_51;
F_35 ( V_45 , V_47 ) ;
V_21 = F_36 ( V_45 , V_41 , V_46 -> type ) ;
if ( V_21 )
goto V_51;
return 0 ;
V_51:
F_37 ( V_45 , V_47 ) ;
return ( V_21 == - V_30 ? 0 : V_21 ) ;
}
int F_38 ( struct V_11 * V_46 )
{
const struct V_15 * V_16 ;
int V_21 = 0 ;
if ( ! V_46 )
return 0 ;
if ( V_46 -> type == V_9 ||
V_46 -> type > V_18 )
return 0 ;
F_11 () ;
V_16 = F_12 ( V_20 [ V_46 -> type ] ) ;
if ( F_13 ( V_16 && V_16 -> V_52 ) )
V_21 = F_39 ( V_16 -> V_52 ( V_46 ) ) ;
F_16 () ;
return V_21 ;
}
int F_40 ( struct V_11 * V_53 , struct V_11 * V_54 )
{
const struct V_15 * V_16 ;
int V_21 = 0 ;
if ( ! V_53 && ! V_54 )
return 0 ;
if ( ! V_53 || ! V_54 )
return 1 ;
if ( V_53 -> type != V_54 -> type )
return 1 ;
if ( V_53 -> type == V_9 ||
V_53 -> type > V_18 )
return 0 ;
F_11 () ;
V_16 = F_12 ( V_20 [ V_53 -> type ] ) ;
if ( F_13 ( V_16 && V_16 -> V_55 ) )
V_21 = V_16 -> V_55 ( V_53 , V_54 ) ;
F_16 () ;
return V_21 ;
}
int F_41 ( struct V_56 * V_56 , struct V_57 * V_58 , struct V_44 * V_45 )
{
struct V_59 * V_60 = F_42 ( V_45 ) ;
const struct V_15 * V_16 ;
struct V_11 * V_46 ;
int V_21 = - V_29 ;
if ( ! V_60 )
goto V_61;
V_46 = V_60 -> V_46 ;
if ( V_46 -> type == V_9 ||
V_46 -> type > V_18 )
return 0 ;
V_21 = - V_30 ;
F_11 () ;
V_16 = F_12 ( V_20 [ V_46 -> type ] ) ;
if ( F_13 ( V_16 && V_16 -> V_62 ) )
V_21 = V_16 -> V_62 ( V_56 , V_58 , V_45 ) ;
F_16 () ;
if ( V_21 == - V_30 )
goto V_61;
return V_21 ;
V_61:
F_43 ( V_45 ) ;
return V_21 ;
}
int F_44 ( struct V_44 * V_45 )
{
struct V_59 * V_60 = F_42 ( V_45 ) ;
const struct V_15 * V_16 ;
struct V_11 * V_46 ;
int V_21 = - V_29 ;
if ( ! V_60 )
goto V_61;
V_46 = V_60 -> V_46 ;
if ( V_46 -> type == V_9 ||
V_46 -> type > V_18 )
return 0 ;
V_21 = - V_30 ;
F_11 () ;
V_16 = F_12 ( V_20 [ V_46 -> type ] ) ;
if ( F_13 ( V_16 && V_16 -> V_63 ) )
V_21 = V_16 -> V_63 ( V_45 ) ;
F_16 () ;
if ( V_21 == - V_30 )
goto V_61;
return V_21 ;
V_61:
F_43 ( V_45 ) ;
return V_21 ;
}
int F_45 ( struct V_44 * V_45 )
{
struct V_59 * V_60 = F_42 ( V_45 ) ;
const struct V_15 * V_16 ;
struct V_11 * V_46 ;
int V_21 = - V_29 ;
if ( ! V_60 )
goto V_61;
V_46 = V_60 -> V_46 ;
if ( V_46 -> type == V_9 ||
V_46 -> type > V_18 )
return 0 ;
V_21 = - V_30 ;
F_11 () ;
V_16 = F_12 ( V_20 [ V_46 -> type ] ) ;
if ( F_13 ( V_16 && V_16 -> V_64 ) )
V_21 = V_16 -> V_64 ( V_45 ) ;
F_16 () ;
if ( V_21 == - V_30 )
goto V_61;
return V_21 ;
V_61:
F_43 ( V_45 ) ;
return V_21 ;
}
