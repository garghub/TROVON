static inline int F_1 ( struct V_1 * V_2 )
{
return ( V_2 &&
( V_2 -> V_3 == V_4 ) &&
( V_2 -> V_5 == V_6 ) ) ;
}
static inline int F_2 ( struct V_7 * V_8 )
{
return F_1 ( V_8 -> V_9 ) ;
}
int F_3 ( struct V_1 * V_2 , T_1 V_10 , T_2 V_11 )
{
int V_12 ;
T_1 V_13 ;
if ( V_2 ) {
if ( ! F_1 ( V_2 ) )
return - V_14 ;
V_13 = V_2 -> V_15 ;
} else
return 0 ;
V_12 = F_4 ( V_10 , V_13 , V_16 ,
V_17 ,
NULL ) ;
if ( V_12 == - V_18 )
return - V_19 ;
return V_12 ;
}
int F_5 ( struct V_7 * V_8 , struct V_20 * V_21 ,
const struct V_22 * V_23 )
{
T_1 V_24 ;
int V_12 ;
if ( ! V_21 -> V_9 )
if ( V_8 -> V_9 )
return 0 ;
else
return 1 ;
else
if ( ! V_8 -> V_9 )
return 0 ;
else
if ( ! F_2 ( V_8 ) )
return 0 ;
V_24 = V_8 -> V_9 -> V_15 ;
if ( V_23 -> V_25 != V_24 )
return 0 ;
V_12 = F_4 ( V_23 -> V_25 , V_24 , V_16 ,
V_26 ,
NULL ) ? 0 : 1 ;
return V_12 ;
}
int F_6 ( struct V_27 * V_28 , T_1 * V_29 , int V_30 )
{
struct V_31 * V_32 ;
* V_29 = V_33 ;
if ( V_28 == NULL )
return 0 ;
V_32 = V_28 -> V_32 ;
if ( V_32 ) {
int V_34 , V_35 = 0 ;
for ( V_34 = V_32 -> V_36 - 1 ; V_34 >= 0 ; V_34 -- ) {
struct V_7 * V_8 = V_32 -> V_37 [ V_34 ] ;
if ( F_2 ( V_8 ) ) {
struct V_1 * V_2 = V_8 -> V_9 ;
if ( ! V_35 ) {
* V_29 = V_2 -> V_15 ;
V_35 = 1 ;
if ( ! V_30 )
break;
} else if ( * V_29 != V_2 -> V_15 )
return - V_14 ;
}
}
}
return 0 ;
}
static int F_7 ( struct V_1 * * V_38 ,
struct V_39 * V_40 , T_1 V_29 )
{
int V_12 = 0 ;
const struct V_41 * V_42 = F_8 () ;
struct V_1 * V_2 = NULL ;
char * V_43 = NULL ;
T_1 V_44 ;
F_9 ( V_40 && V_29 ) ;
if ( ! V_40 )
goto V_45;
if ( V_40 -> V_5 != V_6 )
return - V_14 ;
V_44 = V_40 -> V_46 ;
if ( V_44 >= V_47 )
return - V_48 ;
* V_38 = V_2 = F_10 ( sizeof( * V_2 ) +
V_44 + 1 ,
V_49 ) ;
if ( ! V_2 )
return - V_48 ;
V_2 -> V_3 = V_40 -> V_3 ;
V_2 -> V_46 = V_44 ;
V_2 -> V_5 = V_40 -> V_5 ;
memcpy ( V_2 -> V_43 ,
V_40 + 1 ,
V_44 ) ;
V_2 -> V_43 [ V_44 ] = 0 ;
V_12 = F_11 ( V_2 -> V_43 ,
V_44 ,
& V_2 -> V_15 ) ;
if ( V_12 )
goto V_50;
V_12 = F_4 ( V_42 -> V_29 , V_2 -> V_15 ,
V_16 ,
V_51 , NULL ) ;
if ( V_12 )
goto V_50;
return V_12 ;
V_45:
V_12 = F_12 ( V_29 , & V_43 , & V_44 ) ;
if ( V_12 )
goto V_50;
* V_38 = V_2 = F_10 ( sizeof( * V_2 ) +
V_44 ,
V_52 ) ;
if ( ! V_2 ) {
V_12 = - V_48 ;
goto V_50;
}
V_2 -> V_3 = V_4 ;
V_2 -> V_5 = V_6 ;
V_2 -> V_15 = V_29 ;
V_2 -> V_46 = V_44 ;
memcpy ( V_2 -> V_43 ,
V_43 ,
V_44 ) ;
goto V_53;
V_50:
* V_38 = NULL ;
F_13 ( V_2 ) ;
V_53:
F_13 ( V_43 ) ;
return V_12 ;
}
int F_14 ( struct V_1 * * V_38 ,
struct V_39 * V_40 )
{
int V_54 ;
F_9 ( ! V_40 ) ;
V_54 = F_7 ( V_38 , V_40 , 0 ) ;
if ( V_54 == 0 )
F_15 ( & V_55 ) ;
return V_54 ;
}
int F_16 ( struct V_1 * V_56 ,
struct V_1 * * V_57 )
{
struct V_1 * V_58 ;
if ( V_56 ) {
V_58 = F_10 ( sizeof( * V_56 ) + V_56 -> V_46 ,
V_52 ) ;
if ( ! V_58 )
return - V_48 ;
memcpy ( V_58 , V_56 , sizeof( * V_58 ) ) ;
memcpy ( V_58 -> V_43 , V_56 -> V_43 , V_58 -> V_46 ) ;
* V_57 = V_58 ;
}
return 0 ;
}
void F_17 ( struct V_1 * V_2 )
{
F_13 ( V_2 ) ;
}
int F_18 ( struct V_1 * V_2 )
{
const struct V_41 * V_42 = F_8 () ;
int V_12 = 0 ;
if ( V_2 ) {
V_12 = F_4 ( V_42 -> V_29 , V_2 -> V_15 ,
V_16 ,
V_51 , NULL ) ;
if ( V_12 == 0 )
F_19 ( & V_55 ) ;
}
return V_12 ;
}
int F_20 ( struct V_7 * V_8 , struct V_39 * V_40 ,
T_1 V_59 )
{
int V_54 ;
F_9 ( ! V_8 ) ;
V_54 = F_7 ( & V_8 -> V_9 , V_40 , V_59 ) ;
if ( V_54 == 0 )
F_15 ( & V_55 ) ;
return V_54 ;
}
void F_21 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_9 ;
F_13 ( V_2 ) ;
}
int F_22 ( struct V_7 * V_8 )
{
const struct V_41 * V_42 = F_8 () ;
struct V_1 * V_2 = V_8 -> V_9 ;
int V_12 = 0 ;
if ( V_2 ) {
V_12 = F_4 ( V_42 -> V_29 , V_2 -> V_15 ,
V_16 ,
V_51 , NULL ) ;
if ( V_12 == 0 )
F_19 ( & V_55 ) ;
}
return V_12 ;
}
int F_23 ( T_1 V_60 , struct V_27 * V_28 ,
struct V_61 * V_62 )
{
int V_34 , V_12 = 0 ;
struct V_31 * V_32 ;
T_1 V_13 = V_63 ;
V_32 = V_28 -> V_32 ;
if ( V_32 ) {
for ( V_34 = 0 ; V_34 < V_32 -> V_36 ; V_34 ++ ) {
struct V_7 * V_8 = V_32 -> V_37 [ V_34 ] ;
if ( V_8 && F_2 ( V_8 ) ) {
struct V_1 * V_2 = V_8 -> V_9 ;
V_13 = V_2 -> V_15 ;
break;
}
}
}
V_12 = F_4 ( V_60 , V_13 , V_16 ,
V_64 , V_62 ) ;
return V_12 ;
}
int F_24 ( T_1 V_60 , struct V_27 * V_28 ,
struct V_61 * V_62 , T_2 V_65 )
{
struct V_66 * V_67 ;
int V_12 = 0 ;
V_67 = F_25 ( V_28 ) ;
if ( V_67 ) {
struct V_66 * V_68 ;
for ( V_68 = V_67 ; V_68 != NULL ;
V_68 = V_68 -> V_69 ) {
struct V_7 * V_8 = V_68 -> V_70 ;
if ( V_8 && F_2 ( V_8 ) )
goto V_50;
}
}
switch ( V_65 ) {
case V_71 :
case V_72 :
case V_73 :
goto V_50;
default:
break;
}
V_12 = F_4 ( V_60 , V_63 , V_16 ,
V_26 , V_62 ) ;
V_50:
return V_12 ;
}
