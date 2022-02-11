void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_1 * V_5 ;
if ( V_2 -> V_6 -> V_7 == 0 )
return;
V_5 = F_2 ( V_2 -> V_5 , struct V_1 , V_8 . V_9 ) ;
F_3 ( V_4 , V_2 -> V_6 -> V_7 ,
V_5 -> V_6 -> V_10 [ V_2 -> V_11 ] ) ;
}
struct V_12 *
F_4 ( struct V_1 * V_9 ,
struct V_12 * V_13 ,
enum V_14 V_15 )
{
switch ( V_15 ) {
case V_16 :
return V_9 -> V_17 ;
case V_18 :
default:
return V_13 ;
}
}
struct V_19 *
F_5 ( struct V_1 * V_9 ,
struct V_12 * V_13 ,
unsigned int V_20 )
{
return F_6 ( & V_9 -> V_8 , V_13 , V_20 ) ;
}
struct V_21 *
F_7 ( struct V_1 * V_9 ,
struct V_12 * V_13 ,
unsigned int V_20 )
{
return F_8 ( & V_9 -> V_8 , V_13 , V_20 ) ;
}
int F_9 ( struct V_22 * V_8 ,
struct V_12 * V_13 )
{
struct V_23 V_24 ;
unsigned int V_20 ;
for ( V_20 = 0 ; V_20 < V_8 -> V_9 . V_25 - 1 ; ++ V_20 ) {
memset ( & V_24 , 0 , sizeof( V_24 ) ) ;
V_24 . V_20 = V_20 ;
V_24 . V_15 = V_13 ? V_18
: V_16 ;
F_10 ( V_8 , V_20 , V_26 , V_13 , & V_24 ) ;
}
return 0 ;
}
int F_11 ( struct V_22 * V_8 ,
struct V_12 * V_13 ,
struct V_23 * V_27 )
{
struct V_1 * V_9 = F_12 ( V_8 ) ;
struct V_12 * V_17 ;
V_17 = F_4 ( V_9 , V_13 , V_27 -> V_15 ) ;
if ( ! V_17 )
return - V_28 ;
V_27 -> V_24 = * F_5 ( V_9 , V_17 , V_27 -> V_20 ) ;
return 0 ;
}
int F_13 ( struct V_22 * V_8 ,
struct V_12 * V_13 ,
struct V_29 * V_30 ,
const unsigned int * V_31 , unsigned int V_32 )
{
struct V_1 * V_9 = F_12 ( V_8 ) ;
if ( V_30 -> V_20 == 0 ) {
if ( V_30 -> V_33 >= V_32 )
return - V_28 ;
V_30 -> V_30 = V_31 [ V_30 -> V_33 ] ;
} else {
struct V_12 * V_17 ;
struct V_19 * V_24 ;
if ( V_30 -> V_33 )
return - V_28 ;
V_17 = F_4 ( V_9 , V_13 , V_30 -> V_15 ) ;
if ( ! V_17 )
return - V_28 ;
V_24 = F_5 ( V_9 , V_17 , 0 ) ;
V_30 -> V_30 = V_24 -> V_30 ;
}
return 0 ;
}
int F_14 ( struct V_22 * V_8 ,
struct V_12 * V_13 ,
struct V_34 * V_35 ,
unsigned int V_36 , unsigned int V_37 ,
unsigned int V_38 , unsigned int V_39 )
{
struct V_1 * V_9 = F_12 ( V_8 ) ;
struct V_12 * V_17 ;
struct V_19 * V_24 ;
V_17 = F_4 ( V_9 , V_13 , V_35 -> V_15 ) ;
if ( ! V_17 )
return - V_28 ;
V_24 = F_5 ( V_9 , V_17 , V_35 -> V_20 ) ;
if ( V_35 -> V_33 || V_35 -> V_30 != V_24 -> V_30 )
return - V_28 ;
if ( V_35 -> V_20 == 0 ) {
V_35 -> V_36 = V_36 ;
V_35 -> V_38 = V_38 ;
V_35 -> V_37 = V_37 ;
V_35 -> V_39 = V_39 ;
} else {
V_35 -> V_36 = V_24 -> V_40 ;
V_35 -> V_38 = V_24 -> V_40 ;
V_35 -> V_37 = V_24 -> V_41 ;
V_35 -> V_39 = V_24 -> V_41 ;
}
return 0 ;
}
int F_15 ( struct V_42 * V_9 ,
const struct V_43 * V_44 ,
const struct V_43 * V_45 , T_1 V_46 )
{
struct V_1 * V_2 ;
if ( ! ( V_44 -> V_46 & V_47 ) )
return 0 ;
V_2 = F_2 ( V_44 -> V_9 , struct V_1 , V_8 . V_9 ) ;
if ( ! V_2 -> V_6 )
return 0 ;
if ( V_46 & V_48 ) {
if ( V_2 -> V_5 )
return - V_49 ;
V_2 -> V_5 = V_45 -> V_9 ;
V_2 -> V_11 = V_45 -> V_33 ;
} else {
V_2 -> V_5 = NULL ;
V_2 -> V_11 = 0 ;
}
return 0 ;
}
int F_16 ( struct V_50 * V_51 , struct V_1 * V_9 ,
const char * V_52 , unsigned int V_25 ,
const struct V_53 * V_54 )
{
struct V_22 * V_8 ;
unsigned int V_55 ;
int V_56 ;
for ( V_55 = 0 ; V_55 < F_17 ( V_57 ) ; ++ V_55 ) {
if ( V_57 [ V_55 ] . type == V_9 -> type &&
V_57 [ V_55 ] . V_33 == V_9 -> V_33 ) {
V_9 -> V_6 = & V_57 [ V_55 ] ;
break;
}
}
if ( V_55 == F_17 ( V_57 ) )
return - V_28 ;
V_9 -> V_51 = V_51 ;
V_9 -> V_58 = V_25 - 1 ;
V_9 -> V_59 = F_18 ( V_51 -> V_60 , V_25 * sizeof( * V_9 -> V_59 ) ,
V_61 ) ;
if ( V_9 -> V_59 == NULL )
return - V_62 ;
for ( V_55 = 0 ; V_55 < V_25 - 1 ; ++ V_55 )
V_9 -> V_59 [ V_55 ] . V_46 = V_63 ;
V_9 -> V_59 [ V_25 - 1 ] . V_46 = V_47 ;
V_56 = F_19 ( & V_9 -> V_8 . V_9 , V_25 ,
V_9 -> V_59 ) ;
if ( V_56 < 0 )
return V_56 ;
V_8 = & V_9 -> V_8 ;
F_20 ( V_8 , V_54 ) ;
V_8 -> V_9 . V_54 = & V_51 -> V_64 ;
V_8 -> V_46 |= V_65 ;
snprintf ( V_8 -> V_52 , sizeof( V_8 -> V_52 ) , L_1 ,
F_21 ( V_51 -> V_60 ) , V_52 ) ;
F_9 ( V_8 , NULL ) ;
V_9 -> V_17 = F_22 ( & V_9 -> V_8 ) ;
if ( V_9 -> V_17 == NULL ) {
F_23 ( & V_9 -> V_8 . V_9 ) ;
return - V_62 ;
}
return 0 ;
}
void F_24 ( struct V_1 * V_9 )
{
if ( V_9 -> V_54 && V_9 -> V_54 -> V_66 )
V_9 -> V_54 -> V_66 ( V_9 ) ;
if ( V_9 -> V_8 . V_67 )
F_25 ( V_9 -> V_8 . V_67 ) ;
F_26 ( V_9 -> V_17 ) ;
F_23 ( & V_9 -> V_8 . V_9 ) ;
}
