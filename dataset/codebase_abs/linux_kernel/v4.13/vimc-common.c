const struct V_1 * F_1 ( unsigned int V_2 )
{
if ( V_2 >= F_2 ( V_3 ) )
return NULL ;
return & V_3 [ V_2 ] ;
}
const struct V_1 * F_3 ( T_1 V_4 )
{
unsigned int V_2 ;
for ( V_2 = 0 ; V_2 < F_2 ( V_3 ) ; V_2 ++ ) {
if ( V_3 [ V_2 ] . V_4 == V_4 )
return & V_3 [ V_2 ] ;
}
return NULL ;
}
const struct V_1 * F_4 ( T_1 V_5 )
{
unsigned int V_2 ;
for ( V_2 = 0 ; V_2 < F_2 ( V_3 ) ; V_2 ++ ) {
if ( V_3 [ V_2 ] . V_5 == V_5 )
return & V_3 [ V_2 ] ;
}
return NULL ;
}
int F_5 ( struct V_6 * V_7 , const void * V_8 )
{
struct V_9 * V_10 ;
if ( ! ( V_7 -> V_11 & V_12 ) )
return - V_13 ;
F_6 (link, &src->entity->links, list) {
if ( V_10 -> V_14 == V_7 &&
( V_10 -> V_11 & V_15 ) ) {
struct V_16 * V_17 = NULL ;
struct V_18 * V_19 = V_10 -> V_20 -> V_19 ;
if ( F_7 ( V_19 ) ) {
struct V_21 * V_22 =
F_8 ( V_19 , struct V_21 ,
V_19 ) ;
V_17 = F_9 ( V_22 ) ;
} else if ( F_10 ( V_19 ) ) {
struct V_23 * V_24 =
F_8 ( V_19 ,
struct V_23 ,
V_19 ) ;
V_17 = F_11 ( V_24 ) ;
}
if ( V_17 && V_17 -> V_25 )
V_17 -> V_25 ( V_17 , V_10 -> V_20 , V_8 ) ;
}
}
return 0 ;
}
struct V_6 * F_12 ( T_2 V_26 , const unsigned long * V_27 )
{
struct V_6 * V_28 ;
unsigned int V_2 ;
V_28 = F_13 ( V_26 , sizeof( * V_28 ) , V_29 ) ;
if ( ! V_28 )
return F_14 ( - V_30 ) ;
for ( V_2 = 0 ; V_2 < V_26 ; V_2 ++ ) {
V_28 [ V_2 ] . V_31 = V_2 ;
V_28 [ V_2 ] . V_11 = V_27 [ V_2 ] ;
}
return V_28 ;
}
int F_15 ( struct V_18 * V_32 , int V_33 )
{
struct V_21 * V_22 ;
struct V_6 * V_34 ;
unsigned int V_2 ;
int V_35 ;
for ( V_2 = 0 ; V_2 < V_32 -> V_26 ; V_2 ++ ) {
if ( V_32 -> V_28 [ V_2 ] . V_11 & V_12 )
continue;
V_34 = F_16 ( & V_32 -> V_28 [ V_2 ] ) ;
if ( ! F_7 ( V_34 -> V_19 ) )
return - V_13 ;
V_22 = F_17 ( V_34 -> V_19 ) ;
V_35 = F_18 ( V_22 , V_36 , V_37 , V_33 ) ;
if ( V_35 && V_35 != - V_38 )
return V_35 ;
}
return 0 ;
}
static int F_19 ( struct V_6 * V_34 ,
struct V_39 * V_40 )
{
if ( F_7 ( V_34 -> V_19 ) ) {
struct V_21 * V_22 =
F_17 ( V_34 -> V_19 ) ;
int V_35 ;
V_40 -> V_41 = V_42 ;
V_40 -> V_34 = V_34 -> V_31 ;
V_35 = F_18 ( V_22 , V_34 , V_43 , NULL , V_40 ) ;
if ( V_35 )
return V_35 ;
} else if ( F_10 ( V_34 -> V_19 ) ) {
struct V_23 * V_24 = F_8 ( V_34 -> V_19 ,
struct V_23 ,
V_19 ) ;
struct V_16 * V_17 = F_11 ( V_24 ) ;
const struct V_1 * V_44 ;
struct V_45 V_46 ;
if ( ! V_17 -> V_47 )
return - V_38 ;
V_17 -> V_47 ( V_17 , & V_46 ) ;
V_44 = F_4 ( V_46 . V_5 ) ;
F_20 ( & V_40 -> V_48 , & V_46 , V_44 -> V_4 ) ;
} else {
return - V_13 ;
}
return 0 ;
}
int F_21 ( struct V_9 * V_10 )
{
struct V_39 V_49 , V_50 ;
int V_35 ;
V_35 = F_19 ( V_10 -> V_14 , & V_49 ) ;
if ( V_35 )
return V_35 ;
V_35 = F_19 ( V_10 -> V_20 , & V_50 ) ;
if ( V_35 )
return V_35 ;
F_22 ( L_1
L_2
L_3 ,
V_10 -> V_14 -> V_19 -> V_51 ,
V_49 . V_48 . V_52 , V_49 . V_48 . V_53 ,
V_49 . V_48 . V_4 , V_49 . V_48 . V_54 ,
V_49 . V_48 . V_55 , V_49 . V_48 . V_56 ,
V_49 . V_48 . V_57 ,
V_10 -> V_20 -> V_19 -> V_51 ,
V_50 . V_48 . V_52 , V_50 . V_48 . V_53 ,
V_50 . V_48 . V_4 , V_50 . V_48 . V_54 ,
V_50 . V_48 . V_55 , V_50 . V_48 . V_56 ,
V_50 . V_48 . V_57 ) ;
if ( V_49 . V_48 . V_52 != V_50 . V_48 . V_52
|| V_49 . V_48 . V_53 != V_50 . V_48 . V_53
|| V_49 . V_48 . V_4 != V_50 . V_48 . V_4 )
return - V_58 ;
if ( V_49 . V_48 . V_59 != V_50 . V_48 . V_59 &&
V_50 . V_48 . V_59 != V_60 )
return - V_58 ;
if ( V_49 . V_48 . V_54 == V_61
|| V_50 . V_48 . V_54 == V_61 )
return 0 ;
if ( V_49 . V_48 . V_54 != V_50 . V_48 . V_54 )
return - V_58 ;
if ( V_49 . V_48 . V_57 != V_62
&& V_50 . V_48 . V_57 != V_62
&& V_49 . V_48 . V_57 != V_50 . V_48 . V_57 )
return - V_58 ;
if ( V_49 . V_48 . V_55 != V_63
&& V_50 . V_48 . V_55 != V_63
&& V_49 . V_48 . V_55 != V_50 . V_48 . V_55 )
return - V_58 ;
if ( V_49 . V_48 . V_56 != V_64
&& V_50 . V_48 . V_56 != V_64
&& V_49 . V_48 . V_56 != V_50 . V_48 . V_56 )
return - V_58 ;
return 0 ;
}
int F_23 ( struct V_16 * V_17 ,
struct V_21 * V_22 ,
struct V_65 * V_66 ,
const char * const V_51 ,
T_1 V_67 ,
T_2 V_26 ,
const unsigned long * V_27 ,
const struct V_68 * V_69 )
{
int V_35 ;
V_17 -> V_28 = F_12 ( V_26 , V_27 ) ;
if ( F_24 ( V_17 -> V_28 ) )
return F_25 ( V_17 -> V_28 ) ;
V_17 -> V_32 = & V_22 -> V_19 ;
F_26 ( V_22 , V_69 ) ;
V_22 -> V_19 . V_67 = V_67 ;
V_22 -> V_19 . V_70 = & V_71 ;
V_22 -> V_72 = V_73 ;
F_27 ( V_22 -> V_51 , V_51 , sizeof( V_22 -> V_51 ) ) ;
F_28 ( V_22 , V_17 ) ;
V_22 -> V_11 = V_74 ;
V_35 = F_29 ( & V_22 -> V_19 , V_26 , V_17 -> V_28 ) ;
if ( V_35 )
goto V_75;
V_35 = F_30 ( V_66 , V_22 ) ;
if ( V_35 ) {
F_31 ( V_66 -> V_76 ,
L_4 ,
V_51 , V_35 ) ;
goto V_77;
}
return 0 ;
V_77:
F_32 ( & V_22 -> V_19 ) ;
V_75:
F_33 ( V_17 -> V_28 ) ;
return V_35 ;
}
void F_34 ( struct V_16 * V_17 , struct V_21 * V_22 )
{
F_35 ( V_22 ) ;
F_32 ( V_17 -> V_32 ) ;
F_33 ( V_17 -> V_28 ) ;
}
