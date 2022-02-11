int F_1 ( struct V_1 * V_2 )
{
const struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_5 = 0 ;
if ( F_3 ( V_4 -> V_6 ) == 1 )
V_5 = V_4 -> V_7 ( V_2 ) ;
if ( V_5 )
F_4 ( V_4 -> V_6 ) ;
return V_5 ;
}
int F_5 ( struct V_1 * V_2 )
{
const struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_5 = 0 ;
if ( F_6 ( V_4 -> V_6 ) == 0 )
V_5 = V_4 -> V_8 ( V_2 ) ;
if ( V_5 )
F_7 ( V_4 -> V_6 ) ;
F_8 ( F_9 ( V_4 -> V_6 ) < 0 ) ;
return V_5 ;
}
static int F_10 ( struct V_1 * V_2 ,
const struct V_3 * V_4 ,
T_1 * V_6 )
{
if ( ! V_4 )
return 0 ;
V_2 -> V_3 = F_11 ( V_4 , sizeof( * V_4 ) , V_9 ) ;
if ( ! V_2 -> V_3 )
return - V_10 ;
V_2 -> V_3 -> V_6 = V_6 ;
return 0 ;
}
static void F_12 ( const struct V_3 * V_4 ,
struct V_1 * V_2 )
{
struct V_11 * V_12 ;
struct V_11 * V_13 ;
V_12 = F_13 ( V_2 -> V_14 . V_15 ) ;
if ( ! V_12 )
return;
V_13 = V_12 ;
if ( V_4 -> V_16 ) {
struct V_17 V_18 [ 2 ] = {} ;
struct V_11 * V_19 ;
F_14 ( V_18 [ 0 ] . V_20 , V_4 -> V_16 , sizeof( V_18 [ 0 ] . V_20 ) ) ;
F_15 (child_adev, &parent_adev->children, node)
if ( F_16 ( V_19 , V_18 ) ) {
V_13 = V_19 ;
break;
}
}
F_17 ( & V_2 -> V_14 , V_13 ) ;
}
static inline void F_12 ( const struct V_3 * V_4 ,
struct V_1 * V_2 )
{
}
static int F_18 ( struct V_21 * V_15 , int V_20 ,
const struct V_3 * V_4 , T_1 * V_6 ,
struct V_22 * V_23 ,
int V_24 , struct V_25 * V_26 )
{
struct V_22 * V_27 ;
struct V_1 * V_2 ;
struct V_28 * V_29 = NULL ;
int V_30 = - V_10 ;
int V_31 ;
int V_32 ;
if ( V_20 == V_33 )
V_31 = V_20 ;
else
V_31 = V_20 + V_4 -> V_20 ;
V_2 = F_19 ( V_4 -> V_34 , V_31 ) ;
if ( ! V_2 )
goto V_35;
V_27 = F_20 ( sizeof( * V_27 ) * V_4 -> V_36 , V_9 ) ;
if ( ! V_27 )
goto V_37;
V_2 -> V_14 . V_15 = V_15 ;
V_2 -> V_14 . type = & V_38 ;
V_2 -> V_14 . V_39 = V_15 -> V_39 ;
V_2 -> V_14 . V_40 = V_15 -> V_40 ;
V_2 -> V_14 . V_41 = V_15 -> V_41 ;
V_30 = F_21 (
& V_2 -> V_14 , V_4 -> V_42 ,
V_15 , V_4 -> V_42 ,
V_4 -> V_43 ) ;
if ( V_30 < 0 )
goto V_44;
if ( V_15 -> V_45 && V_4 -> V_46 ) {
F_22 (parent->of_node, np) {
if ( F_23 ( V_29 , V_4 -> V_46 ) ) {
V_2 -> V_14 . V_45 = V_29 ;
break;
}
}
}
F_12 ( V_4 , V_2 ) ;
if ( V_4 -> V_47 ) {
V_30 = F_24 ( V_2 ,
V_4 -> V_48 , V_4 -> V_47 ) ;
if ( V_30 )
goto V_49;
}
V_30 = F_10 ( V_2 , V_4 , V_6 ) ;
if ( V_30 )
goto V_49;
for ( V_32 = 0 ; V_32 < V_4 -> V_36 ; V_32 ++ ) {
V_27 [ V_32 ] . V_34 = V_4 -> V_50 [ V_32 ] . V_34 ;
V_27 [ V_32 ] . V_51 = V_4 -> V_50 [ V_32 ] . V_51 ;
if ( ( V_4 -> V_50 [ V_32 ] . V_51 & V_52 ) && V_23 ) {
V_27 [ V_32 ] . V_15 = V_23 ;
V_27 [ V_32 ] . V_53 = V_23 -> V_53 +
V_4 -> V_50 [ V_32 ] . V_53 ;
V_27 [ V_32 ] . V_54 = V_23 -> V_53 +
V_4 -> V_50 [ V_32 ] . V_54 ;
} else if ( V_4 -> V_50 [ V_32 ] . V_51 & V_55 ) {
if ( V_26 ) {
F_8 ( V_4 -> V_50 [ V_32 ] . V_53 !=
V_4 -> V_50 [ V_32 ] . V_54 ) ;
V_27 [ V_32 ] . V_53 = V_27 [ V_32 ] . V_54 = F_25 (
V_26 , V_4 -> V_50 [ V_32 ] . V_53 ) ;
} else {
V_27 [ V_32 ] . V_53 = V_24 +
V_4 -> V_50 [ V_32 ] . V_53 ;
V_27 [ V_32 ] . V_54 = V_24 +
V_4 -> V_50 [ V_32 ] . V_54 ;
}
} else {
V_27 [ V_32 ] . V_15 = V_4 -> V_50 [ V_32 ] . V_15 ;
V_27 [ V_32 ] . V_53 = V_4 -> V_50 [ V_32 ] . V_53 ;
V_27 [ V_32 ] . V_54 = V_4 -> V_50 [ V_32 ] . V_54 ;
}
if ( ! V_4 -> V_56 ) {
if ( F_26 ( & V_2 -> V_14 ) ) {
V_30 = F_27 ( & V_27 [ V_32 ] ) ;
if ( V_30 )
goto V_49;
}
}
}
V_30 = F_28 ( V_2 , V_27 , V_4 -> V_36 ) ;
if ( V_30 )
goto V_49;
V_30 = F_29 ( V_2 ) ;
if ( V_30 )
goto V_49;
if ( V_4 -> V_57 )
V_57 ( & V_2 -> V_14 ) ;
F_30 ( V_27 ) ;
return 0 ;
V_49:
F_31 ( & V_2 -> V_14 ,
V_4 -> V_42 ,
V_4 -> V_43 ) ;
V_44:
F_30 ( V_27 ) ;
V_37:
F_32 ( V_2 ) ;
V_35:
return V_30 ;
}
int F_33 ( struct V_21 * V_15 , int V_20 ,
const struct V_3 * V_58 , int V_59 ,
struct V_22 * V_23 ,
int V_24 , struct V_25 * V_26 )
{
int V_60 ;
int V_30 ;
T_1 * V_61 ;
V_61 = F_34 ( V_59 , sizeof( * V_61 ) , V_9 ) ;
if ( ! V_61 )
return - V_10 ;
for ( V_60 = 0 ; V_60 < V_59 ; V_60 ++ ) {
F_35 ( & V_61 [ V_60 ] , 0 ) ;
V_30 = F_18 ( V_15 , V_20 , V_58 + V_60 , V_61 + V_60 , V_23 ,
V_24 , V_26 ) ;
if ( V_30 )
goto V_62;
}
return 0 ;
V_62:
if ( V_60 )
F_36 ( V_15 ) ;
else
F_30 ( V_61 ) ;
return V_30 ;
}
static int F_37 ( struct V_21 * V_14 , void * V_63 )
{
struct V_1 * V_2 ;
const struct V_3 * V_4 ;
T_1 * * V_6 = V_63 ;
if ( V_14 -> type != & V_38 )
return 0 ;
V_2 = F_38 ( V_14 ) ;
V_4 = F_2 ( V_2 ) ;
F_31 ( V_14 , V_4 -> V_42 ,
V_4 -> V_43 ) ;
if ( ! * V_6 || ( V_4 -> V_6 < * V_6 ) )
* V_6 = V_4 -> V_6 ;
F_39 ( V_2 ) ;
return 0 ;
}
void F_36 ( struct V_21 * V_15 )
{
T_1 * V_61 = NULL ;
F_40 ( V_15 , & V_61 , F_37 ) ;
F_30 ( V_61 ) ;
}
int F_41 ( const char * V_4 , const char * * V_64 , T_2 V_65 )
{
struct V_3 V_66 ;
struct V_21 * V_14 ;
struct V_1 * V_2 ;
int V_60 ;
V_14 = F_42 ( & V_67 , NULL , V_4 ) ;
if ( ! V_14 ) {
F_43 ( V_68 L_1 , V_4 ) ;
return - V_69 ;
}
V_2 = F_38 ( V_14 ) ;
memcpy ( & V_66 , F_2 ( V_2 ) , sizeof( V_66 ) ) ;
F_8 ( ! V_66 . V_7 ) ;
for ( V_60 = 0 ; V_60 < V_65 ; V_60 ++ ) {
V_66 . V_34 = V_64 [ V_60 ] ;
if ( F_18 ( V_2 -> V_14 . V_15 , - 1 , & V_66 ,
V_66 . V_6 , NULL , 0 , NULL ) )
F_44 ( V_14 , L_2 ,
V_64 [ V_60 ] ) ;
}
return 0 ;
}
