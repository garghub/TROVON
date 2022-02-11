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
F_15 ( & V_3 -> V_33 ) ;
V_31 -> V_28 = * F_6 ( V_3 , V_18 , V_31 -> V_21 ) ;
F_16 ( & V_3 -> V_33 ) ;
return 0 ;
}
int F_17 ( struct V_26 * V_4 ,
struct V_13 * V_14 ,
struct V_34 * V_35 ,
const unsigned int * V_36 , unsigned int V_37 )
{
struct V_1 * V_3 = F_14 ( V_4 ) ;
if ( V_35 -> V_21 == 0 ) {
if ( V_35 -> V_38 >= V_37 )
return - V_32 ;
V_35 -> V_35 = V_36 [ V_35 -> V_38 ] ;
} else {
struct V_13 * V_18 ;
struct V_20 * V_28 ;
if ( V_35 -> V_38 )
return - V_32 ;
V_18 = F_5 ( V_3 , V_14 , V_35 -> V_16 ) ;
if ( ! V_18 )
return - V_32 ;
F_15 ( & V_3 -> V_33 ) ;
V_28 = F_6 ( V_3 , V_18 , 0 ) ;
V_35 -> V_35 = V_28 -> V_35 ;
F_16 ( & V_3 -> V_33 ) ;
}
return 0 ;
}
int F_18 ( struct V_26 * V_4 ,
struct V_13 * V_14 ,
struct V_39 * V_40 ,
unsigned int V_41 , unsigned int V_42 ,
unsigned int V_43 , unsigned int V_44 )
{
struct V_1 * V_3 = F_14 ( V_4 ) ;
struct V_13 * V_18 ;
struct V_20 * V_28 ;
int V_45 = 0 ;
V_18 = F_5 ( V_3 , V_14 , V_40 -> V_16 ) ;
if ( ! V_18 )
return - V_32 ;
V_28 = F_6 ( V_3 , V_18 , V_40 -> V_21 ) ;
F_15 ( & V_3 -> V_33 ) ;
if ( V_40 -> V_38 || V_40 -> V_35 != V_28 -> V_35 ) {
V_45 = - V_32 ;
goto V_46;
}
if ( V_40 -> V_21 == 0 ) {
V_40 -> V_41 = V_41 ;
V_40 -> V_43 = V_43 ;
V_40 -> V_42 = V_42 ;
V_40 -> V_44 = V_44 ;
} else {
V_40 -> V_41 = V_28 -> V_47 ;
V_40 -> V_43 = V_28 -> V_47 ;
V_40 -> V_42 = V_28 -> V_48 ;
V_40 -> V_44 = V_28 -> V_48 ;
}
V_46:
F_16 ( & V_3 -> V_33 ) ;
return V_45 ;
}
int F_19 ( struct V_2 * V_3 ,
const struct V_49 * V_50 ,
const struct V_49 * V_51 , T_1 V_52 )
{
struct V_1 * V_5 ;
if ( ! ( V_50 -> V_52 & V_53 ) )
return 0 ;
V_5 = F_1 ( V_50 -> V_3 ) ;
if ( ! V_5 -> V_9 )
return 0 ;
if ( V_52 & V_54 ) {
if ( V_5 -> V_8 )
return - V_55 ;
V_5 -> V_8 = V_51 -> V_3 ;
V_5 -> V_12 = V_51 -> V_38 ;
} else {
V_5 -> V_8 = NULL ;
V_5 -> V_12 = 0 ;
}
return 0 ;
}
int F_20 ( struct V_56 * V_57 , struct V_1 * V_3 ,
const char * V_58 , unsigned int V_29 ,
const struct V_59 * V_60 , T_1 V_61 )
{
struct V_26 * V_4 ;
unsigned int V_62 ;
int V_45 ;
for ( V_62 = 0 ; V_62 < F_21 ( V_63 ) ; ++ V_62 ) {
if ( V_63 [ V_62 ] . type == V_3 -> type &&
V_63 [ V_62 ] . V_38 == V_3 -> V_38 ) {
V_3 -> V_9 = & V_63 [ V_62 ] ;
break;
}
}
if ( V_62 == F_21 ( V_63 ) )
return - V_32 ;
F_22 ( & V_3 -> V_33 ) ;
V_3 -> V_57 = V_57 ;
V_3 -> V_64 = V_29 - 1 ;
V_3 -> V_65 = F_23 ( V_57 -> V_66 , V_29 * sizeof( * V_3 -> V_65 ) ,
V_67 ) ;
if ( V_3 -> V_65 == NULL )
return - V_68 ;
for ( V_62 = 0 ; V_62 < V_29 - 1 ; ++ V_62 )
V_3 -> V_65 [ V_62 ] . V_52 = V_69 ;
V_3 -> V_65 [ V_29 - 1 ] . V_52 = V_53 ;
V_45 = F_24 ( & V_3 -> V_4 . V_3 , V_29 ,
V_3 -> V_65 ) ;
if ( V_45 < 0 )
return V_45 ;
V_4 = & V_3 -> V_4 ;
F_25 ( V_4 , V_60 ) ;
V_4 -> V_3 . V_61 = V_61 ;
V_4 -> V_3 . V_60 = & V_57 -> V_70 ;
V_4 -> V_52 |= V_71 ;
snprintf ( V_4 -> V_58 , sizeof( V_4 -> V_58 ) , L_1 ,
F_26 ( V_57 -> V_66 ) , V_58 ) ;
F_11 ( V_4 , NULL ) ;
V_3 -> V_18 = F_27 ( & V_3 -> V_4 ) ;
if ( V_3 -> V_18 == NULL ) {
F_28 ( & V_3 -> V_4 . V_3 ) ;
return - V_68 ;
}
return 0 ;
}
void F_29 ( struct V_1 * V_3 )
{
if ( V_3 -> V_60 && V_3 -> V_60 -> V_72 )
V_3 -> V_60 -> V_72 ( V_3 ) ;
if ( V_3 -> V_4 . V_73 )
F_30 ( V_3 -> V_4 . V_73 ) ;
F_31 ( V_3 -> V_18 ) ;
F_28 ( & V_3 -> V_4 . V_3 ) ;
}
