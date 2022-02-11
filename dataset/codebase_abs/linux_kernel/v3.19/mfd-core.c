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
if ( V_20 < 0 )
V_31 = V_20 ;
else
V_31 = V_20 + V_4 -> V_20 ;
V_2 = F_19 ( V_4 -> V_33 , V_31 ) ;
if ( ! V_2 )
goto V_34;
V_27 = F_20 ( sizeof( * V_27 ) * V_4 -> V_35 , V_9 ) ;
if ( ! V_27 )
goto V_36;
V_2 -> V_14 . V_15 = V_15 ;
V_2 -> V_14 . type = & V_37 ;
V_2 -> V_14 . V_38 = V_15 -> V_38 ;
V_2 -> V_14 . V_39 = V_15 -> V_39 ;
V_2 -> V_14 . V_40 = V_15 -> V_40 ;
V_30 = F_21 (
& V_2 -> V_14 , V_4 -> V_41 ,
V_15 , V_4 -> V_41 ,
V_4 -> V_42 ) ;
if ( V_30 < 0 )
goto V_43;
if ( V_15 -> V_44 && V_4 -> V_45 ) {
F_22 (parent->of_node, np) {
if ( F_23 ( V_29 , V_4 -> V_45 ) ) {
V_2 -> V_14 . V_44 = V_29 ;
break;
}
}
}
F_12 ( V_4 , V_2 ) ;
if ( V_4 -> V_46 ) {
V_30 = F_24 ( V_2 ,
V_4 -> V_47 , V_4 -> V_46 ) ;
if ( V_30 )
goto V_48;
}
V_30 = F_10 ( V_2 , V_4 , V_6 ) ;
if ( V_30 )
goto V_48;
for ( V_32 = 0 ; V_32 < V_4 -> V_35 ; V_32 ++ ) {
V_27 [ V_32 ] . V_33 = V_4 -> V_49 [ V_32 ] . V_33 ;
V_27 [ V_32 ] . V_50 = V_4 -> V_49 [ V_32 ] . V_50 ;
if ( ( V_4 -> V_49 [ V_32 ] . V_50 & V_51 ) && V_23 ) {
V_27 [ V_32 ] . V_15 = V_23 ;
V_27 [ V_32 ] . V_52 = V_23 -> V_52 +
V_4 -> V_49 [ V_32 ] . V_52 ;
V_27 [ V_32 ] . V_53 = V_23 -> V_52 +
V_4 -> V_49 [ V_32 ] . V_53 ;
} else if ( V_4 -> V_49 [ V_32 ] . V_50 & V_54 ) {
if ( V_26 ) {
F_8 ( V_4 -> V_49 [ V_32 ] . V_52 !=
V_4 -> V_49 [ V_32 ] . V_53 ) ;
V_27 [ V_32 ] . V_52 = V_27 [ V_32 ] . V_53 = F_25 (
V_26 , V_4 -> V_49 [ V_32 ] . V_52 ) ;
} else {
V_27 [ V_32 ] . V_52 = V_24 +
V_4 -> V_49 [ V_32 ] . V_52 ;
V_27 [ V_32 ] . V_53 = V_24 +
V_4 -> V_49 [ V_32 ] . V_53 ;
}
} else {
V_27 [ V_32 ] . V_15 = V_4 -> V_49 [ V_32 ] . V_15 ;
V_27 [ V_32 ] . V_52 = V_4 -> V_49 [ V_32 ] . V_52 ;
V_27 [ V_32 ] . V_53 = V_4 -> V_49 [ V_32 ] . V_53 ;
}
if ( ! V_4 -> V_55 ) {
V_30 = F_26 ( & V_27 [ V_32 ] ) ;
if ( V_30 )
goto V_48;
}
}
V_30 = F_27 ( V_2 , V_27 , V_4 -> V_35 ) ;
if ( V_30 )
goto V_48;
V_30 = F_28 ( V_2 ) ;
if ( V_30 )
goto V_48;
if ( V_4 -> V_56 )
V_56 ( & V_2 -> V_14 ) ;
F_29 ( V_27 ) ;
return 0 ;
V_48:
F_30 ( & V_2 -> V_14 ,
V_4 -> V_41 ,
V_4 -> V_42 ) ;
V_43:
F_29 ( V_27 ) ;
V_36:
F_31 ( V_2 ) ;
V_34:
return V_30 ;
}
int F_32 ( struct V_21 * V_15 , int V_20 ,
const struct V_3 * V_57 , int V_58 ,
struct V_22 * V_23 ,
int V_24 , struct V_25 * V_26 )
{
int V_59 ;
int V_30 ;
T_1 * V_60 ;
V_60 = F_33 ( V_58 , sizeof( * V_60 ) , V_9 ) ;
if ( ! V_60 )
return - V_10 ;
for ( V_59 = 0 ; V_59 < V_58 ; V_59 ++ ) {
F_34 ( & V_60 [ V_59 ] , 0 ) ;
V_30 = F_18 ( V_15 , V_20 , V_57 + V_59 , V_60 + V_59 , V_23 ,
V_24 , V_26 ) ;
if ( V_30 )
goto V_61;
}
return 0 ;
V_61:
if ( V_59 )
F_35 ( V_15 ) ;
else
F_29 ( V_60 ) ;
return V_30 ;
}
static int F_36 ( struct V_21 * V_14 , void * V_62 )
{
struct V_1 * V_2 ;
const struct V_3 * V_4 ;
T_1 * * V_6 = V_62 ;
if ( V_14 -> type != & V_37 )
return 0 ;
V_2 = F_37 ( V_14 ) ;
V_4 = F_2 ( V_2 ) ;
F_30 ( V_14 , V_4 -> V_41 ,
V_4 -> V_42 ) ;
if ( ! * V_6 || ( V_4 -> V_6 < * V_6 ) )
* V_6 = V_4 -> V_6 ;
F_38 ( V_2 ) ;
return 0 ;
}
void F_35 ( struct V_21 * V_15 )
{
T_1 * V_60 = NULL ;
F_39 ( V_15 , & V_60 , F_36 ) ;
F_29 ( V_60 ) ;
}
int F_40 ( const char * V_4 , const char * * V_63 , T_2 V_64 )
{
struct V_3 V_65 ;
struct V_21 * V_14 ;
struct V_1 * V_2 ;
int V_59 ;
V_14 = F_41 ( & V_66 , NULL , V_4 ) ;
if ( ! V_14 ) {
F_42 ( V_67 L_1 , V_4 ) ;
return - V_68 ;
}
V_2 = F_37 ( V_14 ) ;
memcpy ( & V_65 , F_2 ( V_2 ) , sizeof( V_65 ) ) ;
F_8 ( ! V_65 . V_7 ) ;
for ( V_59 = 0 ; V_59 < V_64 ; V_59 ++ ) {
V_65 . V_33 = V_63 [ V_59 ] ;
if ( F_18 ( V_2 -> V_14 . V_15 , - 1 , & V_65 ,
V_65 . V_6 , NULL , 0 , NULL ) )
F_43 ( V_14 , L_2 ,
V_63 [ V_59 ] ) ;
}
return 0 ;
}
