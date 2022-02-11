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
return L_5 ;
case V_8 :
case V_9 :
case V_10 :
case V_11 :
F_2 ( 1 ) ;
break;
}
return NULL ;
}
struct V_12 * F_3 ( int V_13 )
{
struct V_12 * V_14 ;
V_14 = F_4 ( sizeof( * V_14 ) + V_13 , V_15 ) ;
return V_14 ;
}
int F_5 ( const struct V_16 * V_17 ,
unsigned int V_18 )
{
if ( V_18 > V_19 )
return - V_20 ;
return ! F_6 ( ( const struct V_16 * * )
& V_21 [ V_18 ] ,
NULL , V_17 ) ? 0 : - 1 ;
}
int F_7 ( const struct V_16 * V_17 ,
unsigned int V_2 )
{
int V_22 ;
if ( V_2 == V_10 ||
V_2 > V_19 )
return - V_20 ;
V_22 = ( F_6 ( ( const struct V_16 * * )
& V_21 [ V_2 ] ,
V_17 , NULL ) == V_17 ) ? 0 : - 1 ;
F_8 () ;
return V_22 ;
}
int F_9 ( T_1 V_2 ,
struct V_23 * V_24 , unsigned int V_25 ,
const void * V_26 , struct V_12 * * V_14 ,
struct V_27 * V_28 )
{
const struct V_16 * V_17 ;
bool V_29 = false ;
int V_22 = - V_30 ;
if ( V_2 == V_10 ||
V_2 > V_19 ) {
F_10 ( V_28 , V_24 ,
L_6 ) ;
return V_22 ;
}
V_22 = - V_31 ;
F_11 () ;
V_17 = F_12 ( V_21 [ V_2 ] ) ;
if ( F_13 ( V_17 && V_17 -> V_32 && F_14 ( V_17 -> V_33 ) ) ) {
V_29 = true ;
V_22 = V_17 -> V_32 ( V_24 , V_25 , V_26 , V_14 , V_28 ) ;
if ( V_22 )
F_15 ( V_17 -> V_33 ) ;
}
F_16 () ;
if ( ! V_29 ) {
F_10 ( V_28 , V_24 ,
L_7 ) ;
}
return V_22 ;
}
int F_17 ( T_1 V_2 , struct V_27 * V_28 )
{
const struct V_16 * V_17 ;
int V_22 = - V_30 ;
if ( V_2 == V_10 ||
V_2 > V_19 ) {
F_18 ( V_28 , L_8 ) ;
return V_22 ;
}
F_11 () ;
V_17 = F_12 ( V_21 [ V_2 ] ) ;
F_16 () ;
#ifdef F_19
if ( ! V_17 ) {
const char * V_34 = F_1 ( V_2 ) ;
if ( V_34 ) {
F_20 () ;
F_21 ( L_9 , V_34 ) ;
F_22 () ;
F_11 () ;
V_17 = F_12 ( V_21 [ V_2 ] ) ;
F_16 () ;
}
}
#endif
V_22 = V_17 ? 0 : - V_31 ;
if ( V_22 < 0 )
F_18 ( V_28 , L_10 ) ;
return V_22 ;
}
int F_23 ( struct V_23 * V_35 , int V_36 ,
struct V_27 * V_28 )
{
struct V_37 * V_38 = (struct V_37 * ) V_35 ;
struct V_23 * V_39 ;
struct V_23 * V_40 ;
T_1 V_2 ;
int V_41 ;
while ( F_24 ( V_38 , V_36 ) ) {
V_41 = F_25 ( V_38 ) ;
if ( V_41 > 0 ) {
V_40 = F_26 ( V_38 ) ;
V_39 = F_27 ( V_40 , V_41 , V_42 ) ;
if ( V_39 ) {
V_2 = F_28 ( V_39 ) ;
if ( F_17 ( V_2 ,
V_28 ) != 0 )
return - V_31 ;
}
}
V_38 = F_29 ( V_38 , & V_36 ) ;
}
return 0 ;
}
void F_30 ( struct V_12 * V_14 )
{
const struct V_16 * V_17 = V_21 [ V_14 -> type ] ;
if ( V_17 -> V_43 ) {
V_17 -> V_43 ( V_14 ) ;
F_31 ( V_14 , V_44 ) ;
} else {
F_32 ( V_14 ) ;
}
F_15 ( V_17 -> V_33 ) ;
}
int F_33 ( struct V_45 * V_46 , struct V_12 * V_47 )
{
const struct V_16 * V_17 ;
struct V_23 * V_48 ;
int V_22 ;
if ( ! V_47 )
return 0 ;
if ( V_47 -> type == V_10 ||
V_47 -> type > V_19 )
return 0 ;
V_48 = F_34 ( V_46 , V_49 ) ;
if ( ! V_48 )
return - V_50 ;
V_22 = - V_31 ;
F_11 () ;
V_17 = F_12 ( V_21 [ V_47 -> type ] ) ;
if ( F_13 ( V_17 && V_17 -> V_51 ) )
V_22 = V_17 -> V_51 ( V_46 , V_47 ) ;
F_16 () ;
if ( V_22 )
goto V_52;
F_35 ( V_46 , V_48 ) ;
V_22 = F_36 ( V_46 , V_42 , V_47 -> type ) ;
if ( V_22 )
goto V_52;
return 0 ;
V_52:
F_37 ( V_46 , V_48 ) ;
return ( V_22 == - V_31 ? 0 : V_22 ) ;
}
int F_38 ( struct V_12 * V_47 )
{
const struct V_16 * V_17 ;
int V_22 = 0 ;
if ( ! V_47 )
return 0 ;
if ( V_47 -> type == V_10 ||
V_47 -> type > V_19 )
return 0 ;
F_11 () ;
V_17 = F_12 ( V_21 [ V_47 -> type ] ) ;
if ( F_13 ( V_17 && V_17 -> V_53 ) )
V_22 = F_39 ( V_17 -> V_53 ( V_47 ) ) ;
F_16 () ;
return V_22 ;
}
int F_40 ( struct V_12 * V_54 , struct V_12 * V_55 )
{
const struct V_16 * V_17 ;
int V_22 = 0 ;
if ( ! V_54 && ! V_55 )
return 0 ;
if ( ! V_54 || ! V_55 )
return 1 ;
if ( V_54 -> type != V_55 -> type )
return 1 ;
if ( V_54 -> type == V_10 ||
V_54 -> type > V_19 )
return 0 ;
F_11 () ;
V_17 = F_12 ( V_21 [ V_54 -> type ] ) ;
if ( F_13 ( V_17 && V_17 -> V_56 ) )
V_22 = V_17 -> V_56 ( V_54 , V_55 ) ;
F_16 () ;
return V_22 ;
}
int F_41 ( struct V_57 * V_57 , struct V_58 * V_59 , struct V_45 * V_46 )
{
struct V_60 * V_61 = F_42 ( V_46 ) ;
const struct V_16 * V_17 ;
struct V_12 * V_47 ;
int V_22 = - V_30 ;
if ( ! V_61 )
goto V_62;
V_47 = V_61 -> V_47 ;
if ( V_47 -> type == V_10 ||
V_47 -> type > V_19 )
return 0 ;
V_22 = - V_31 ;
F_11 () ;
V_17 = F_12 ( V_21 [ V_47 -> type ] ) ;
if ( F_13 ( V_17 && V_17 -> V_63 ) )
V_22 = V_17 -> V_63 ( V_57 , V_59 , V_46 ) ;
F_16 () ;
if ( V_22 == - V_31 )
goto V_62;
return V_22 ;
V_62:
F_43 ( V_46 ) ;
return V_22 ;
}
int F_44 ( struct V_45 * V_46 )
{
struct V_60 * V_61 = F_42 ( V_46 ) ;
const struct V_16 * V_17 ;
struct V_12 * V_47 ;
int V_22 = - V_30 ;
if ( ! V_61 )
goto V_62;
V_47 = V_61 -> V_47 ;
if ( V_47 -> type == V_10 ||
V_47 -> type > V_19 )
return 0 ;
V_22 = - V_31 ;
F_11 () ;
V_17 = F_12 ( V_21 [ V_47 -> type ] ) ;
if ( F_13 ( V_17 && V_17 -> V_64 ) )
V_22 = V_17 -> V_64 ( V_46 ) ;
F_16 () ;
if ( V_22 == - V_31 )
goto V_62;
return V_22 ;
V_62:
F_43 ( V_46 ) ;
return V_22 ;
}
int F_45 ( struct V_45 * V_46 )
{
struct V_60 * V_61 = F_42 ( V_46 ) ;
const struct V_16 * V_17 ;
struct V_12 * V_47 ;
int V_22 = - V_30 ;
if ( ! V_61 )
goto V_62;
V_47 = V_61 -> V_47 ;
if ( V_47 -> type == V_10 ||
V_47 -> type > V_19 )
return 0 ;
V_22 = - V_31 ;
F_11 () ;
V_17 = F_12 ( V_21 [ V_47 -> type ] ) ;
if ( F_13 ( V_17 && V_17 -> V_65 ) )
V_22 = V_17 -> V_65 ( V_46 ) ;
F_16 () ;
if ( V_22 == - V_31 )
goto V_62;
return V_22 ;
V_62:
F_43 ( V_46 ) ;
return V_22 ;
}
