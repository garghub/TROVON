static inline struct V_1 *
F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 . V_3 ) ;
}
void F_3 ( struct V_1 * V_5 ,
struct V_6 * V_7 )
{
struct V_1 * V_8 ;
if ( V_5 -> V_9 -> V_10 == 0 )
return;
V_8 = F_1 ( V_5 -> V_8 ) ;
F_4 ( V_7 , V_5 -> V_9 -> V_10 ,
V_8 -> V_9 -> V_11 [ V_5 -> V_12 ] ) ;
}
struct V_13 *
F_5 ( struct V_1 * V_3 ,
struct V_13 * V_14 ,
enum V_15 V_16 )
{
switch ( V_16 ) {
case V_17 :
return V_3 -> V_18 ;
case V_19 :
default:
return V_14 ;
}
}
struct V_20 *
F_6 ( struct V_1 * V_3 ,
struct V_13 * V_14 ,
unsigned int V_21 )
{
return F_7 ( & V_3 -> V_4 , V_14 , V_21 ) ;
}
struct V_22 *
F_8 ( struct V_1 * V_3 ,
struct V_13 * V_14 ,
unsigned int V_21 , unsigned int V_23 )
{
switch ( V_23 ) {
case V_24 :
return F_9 ( & V_3 -> V_4 , V_14 , V_21 ) ;
case V_25 :
return F_10 ( & V_3 -> V_4 , V_14 , V_21 ) ;
default:
return NULL ;
}
}
int F_11 ( struct V_26 * V_4 ,
struct V_13 * V_14 )
{
struct V_27 V_28 ;
unsigned int V_21 ;
for ( V_21 = 0 ; V_21 < V_4 -> V_3 . V_29 - 1 ; ++ V_21 ) {
memset ( & V_28 , 0 , sizeof( V_28 ) ) ;
V_28 . V_21 = V_21 ;
V_28 . V_16 = V_14 ? V_19
: V_17 ;
F_12 ( V_4 , V_21 , V_30 , V_14 , & V_28 ) ;
}
return 0 ;
}
int F_13 ( struct V_26 * V_4 ,
struct V_13 * V_14 ,
struct V_27 * V_31 )
{
struct V_1 * V_3 = F_14 ( V_4 ) ;
struct V_13 * V_18 ;
V_18 = F_5 ( V_3 , V_14 , V_31 -> V_16 ) ;
if ( ! V_18 )
return - V_32 ;
V_31 -> V_28 = * F_6 ( V_3 , V_18 , V_31 -> V_21 ) ;
return 0 ;
}
int F_15 ( struct V_26 * V_4 ,
struct V_13 * V_14 ,
struct V_33 * V_34 ,
const unsigned int * V_35 , unsigned int V_36 )
{
struct V_1 * V_3 = F_14 ( V_4 ) ;
if ( V_34 -> V_21 == 0 ) {
if ( V_34 -> V_37 >= V_36 )
return - V_32 ;
V_34 -> V_34 = V_35 [ V_34 -> V_37 ] ;
} else {
struct V_13 * V_18 ;
struct V_20 * V_28 ;
if ( V_34 -> V_37 )
return - V_32 ;
V_18 = F_5 ( V_3 , V_14 , V_34 -> V_16 ) ;
if ( ! V_18 )
return - V_32 ;
V_28 = F_6 ( V_3 , V_18 , 0 ) ;
V_34 -> V_34 = V_28 -> V_34 ;
}
return 0 ;
}
int F_16 ( struct V_26 * V_4 ,
struct V_13 * V_14 ,
struct V_38 * V_39 ,
unsigned int V_40 , unsigned int V_41 ,
unsigned int V_42 , unsigned int V_43 )
{
struct V_1 * V_3 = F_14 ( V_4 ) ;
struct V_13 * V_18 ;
struct V_20 * V_28 ;
V_18 = F_5 ( V_3 , V_14 , V_39 -> V_16 ) ;
if ( ! V_18 )
return - V_32 ;
V_28 = F_6 ( V_3 , V_18 , V_39 -> V_21 ) ;
if ( V_39 -> V_37 || V_39 -> V_34 != V_28 -> V_34 )
return - V_32 ;
if ( V_39 -> V_21 == 0 ) {
V_39 -> V_40 = V_40 ;
V_39 -> V_42 = V_42 ;
V_39 -> V_41 = V_41 ;
V_39 -> V_43 = V_43 ;
} else {
V_39 -> V_40 = V_28 -> V_44 ;
V_39 -> V_42 = V_28 -> V_44 ;
V_39 -> V_41 = V_28 -> V_45 ;
V_39 -> V_43 = V_28 -> V_45 ;
}
return 0 ;
}
int F_17 ( struct V_2 * V_3 ,
const struct V_46 * V_47 ,
const struct V_46 * V_48 , T_1 V_49 )
{
struct V_1 * V_5 ;
if ( ! ( V_47 -> V_49 & V_50 ) )
return 0 ;
V_5 = F_1 ( V_47 -> V_3 ) ;
if ( ! V_5 -> V_9 )
return 0 ;
if ( V_49 & V_51 ) {
if ( V_5 -> V_8 )
return - V_52 ;
V_5 -> V_8 = V_48 -> V_3 ;
V_5 -> V_12 = V_48 -> V_37 ;
} else {
V_5 -> V_8 = NULL ;
V_5 -> V_12 = 0 ;
}
return 0 ;
}
int F_18 ( struct V_53 * V_54 , struct V_1 * V_3 ,
const char * V_55 , unsigned int V_29 ,
const struct V_56 * V_57 , T_1 V_58 )
{
struct V_26 * V_4 ;
unsigned int V_59 ;
int V_60 ;
for ( V_59 = 0 ; V_59 < F_19 ( V_61 ) ; ++ V_59 ) {
if ( V_61 [ V_59 ] . type == V_3 -> type &&
V_61 [ V_59 ] . V_37 == V_3 -> V_37 ) {
V_3 -> V_9 = & V_61 [ V_59 ] ;
break;
}
}
if ( V_59 == F_19 ( V_61 ) )
return - V_32 ;
V_3 -> V_54 = V_54 ;
V_3 -> V_62 = V_29 - 1 ;
V_3 -> V_63 = F_20 ( V_54 -> V_64 , V_29 * sizeof( * V_3 -> V_63 ) ,
V_65 ) ;
if ( V_3 -> V_63 == NULL )
return - V_66 ;
for ( V_59 = 0 ; V_59 < V_29 - 1 ; ++ V_59 )
V_3 -> V_63 [ V_59 ] . V_49 = V_67 ;
V_3 -> V_63 [ V_29 - 1 ] . V_49 = V_50 ;
V_60 = F_21 ( & V_3 -> V_4 . V_3 , V_29 ,
V_3 -> V_63 ) ;
if ( V_60 < 0 )
return V_60 ;
V_4 = & V_3 -> V_4 ;
F_22 ( V_4 , V_57 ) ;
V_4 -> V_3 . V_58 = V_58 ;
V_4 -> V_3 . V_57 = & V_54 -> V_68 ;
V_4 -> V_49 |= V_69 ;
snprintf ( V_4 -> V_55 , sizeof( V_4 -> V_55 ) , L_1 ,
F_23 ( V_54 -> V_64 ) , V_55 ) ;
F_11 ( V_4 , NULL ) ;
V_3 -> V_18 = F_24 ( & V_3 -> V_4 ) ;
if ( V_3 -> V_18 == NULL ) {
F_25 ( & V_3 -> V_4 . V_3 ) ;
return - V_66 ;
}
return 0 ;
}
void F_26 ( struct V_1 * V_3 )
{
if ( V_3 -> V_57 && V_3 -> V_57 -> V_70 )
V_3 -> V_57 -> V_70 ( V_3 ) ;
if ( V_3 -> V_4 . V_71 )
F_27 ( V_3 -> V_4 . V_71 ) ;
F_28 ( V_3 -> V_18 ) ;
F_25 ( & V_3 -> V_4 . V_3 ) ;
}
