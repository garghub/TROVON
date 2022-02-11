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
const struct V_11 * V_12 = V_4 -> V_13 ;
struct V_14 * V_15 , * V_16 ;
struct V_14 * V_17 ;
V_15 = F_13 ( V_2 -> V_18 . V_15 ) ;
if ( ! V_15 )
return;
V_17 = V_15 ;
if ( V_12 ) {
if ( V_12 -> V_19 ) {
struct V_20 V_21 [ 2 ] = {} ;
F_14 ( V_21 [ 0 ] . V_22 , V_12 -> V_19 , sizeof( V_21 [ 0 ] . V_22 ) ) ;
F_15 (child, &parent->children, node) {
if ( ! F_16 ( V_16 , V_21 ) ) {
V_17 = V_16 ;
break;
}
}
} else {
unsigned long long V_23 ;
T_2 V_24 ;
F_15 (child, &parent->children, node) {
V_24 = F_17 ( V_16 -> V_25 ,
L_1 , NULL ,
& V_23 ) ;
if ( F_18 ( V_24 ) && V_12 -> V_23 == V_23 ) {
V_17 = V_16 ;
break;
}
}
}
}
F_19 ( & V_2 -> V_18 , V_17 ) ;
}
static inline void F_12 ( const struct V_3 * V_4 ,
struct V_1 * V_2 )
{
}
static int F_20 ( struct V_26 * V_15 , int V_22 ,
const struct V_3 * V_4 , T_1 * V_6 ,
struct V_27 * V_28 ,
int V_29 , struct V_30 * V_31 )
{
struct V_27 * V_32 ;
struct V_1 * V_2 ;
struct V_33 * V_34 = NULL ;
int V_35 = - V_10 ;
int V_36 ;
int V_37 ;
if ( V_22 == V_38 )
V_36 = V_22 ;
else
V_36 = V_22 + V_4 -> V_22 ;
V_2 = F_21 ( V_4 -> V_39 , V_36 ) ;
if ( ! V_2 )
goto V_40;
V_32 = F_22 ( sizeof( * V_32 ) * V_4 -> V_41 , V_9 ) ;
if ( ! V_32 )
goto V_42;
V_2 -> V_18 . V_15 = V_15 ;
V_2 -> V_18 . type = & V_43 ;
V_2 -> V_18 . V_44 = V_15 -> V_44 ;
V_2 -> V_18 . V_45 = V_15 -> V_45 ;
V_2 -> V_18 . V_46 = V_15 -> V_46 ;
V_35 = F_23 (
& V_2 -> V_18 , V_4 -> V_47 ,
V_15 , V_4 -> V_47 ,
V_4 -> V_48 ) ;
if ( V_35 < 0 )
goto V_49;
if ( V_15 -> V_50 && V_4 -> V_51 ) {
F_24 (parent->of_node, np) {
if ( F_25 ( V_34 , V_4 -> V_51 ) ) {
V_2 -> V_18 . V_50 = V_34 ;
break;
}
}
}
F_12 ( V_4 , V_2 ) ;
if ( V_4 -> V_52 ) {
V_35 = F_26 ( V_2 ,
V_4 -> V_53 , V_4 -> V_52 ) ;
if ( V_35 )
goto V_54;
}
if ( V_4 -> V_55 ) {
V_35 = F_27 ( V_2 , V_4 -> V_55 ) ;
if ( V_35 )
goto V_54;
}
V_35 = F_10 ( V_2 , V_4 , V_6 ) ;
if ( V_35 )
goto V_54;
for ( V_37 = 0 ; V_37 < V_4 -> V_41 ; V_37 ++ ) {
V_32 [ V_37 ] . V_39 = V_4 -> V_56 [ V_37 ] . V_39 ;
V_32 [ V_37 ] . V_57 = V_4 -> V_56 [ V_37 ] . V_57 ;
if ( ( V_4 -> V_56 [ V_37 ] . V_57 & V_58 ) && V_28 ) {
V_32 [ V_37 ] . V_15 = V_28 ;
V_32 [ V_37 ] . V_59 = V_28 -> V_59 +
V_4 -> V_56 [ V_37 ] . V_59 ;
V_32 [ V_37 ] . V_60 = V_28 -> V_59 +
V_4 -> V_56 [ V_37 ] . V_60 ;
} else if ( V_4 -> V_56 [ V_37 ] . V_57 & V_61 ) {
if ( V_31 ) {
F_8 ( V_4 -> V_56 [ V_37 ] . V_59 !=
V_4 -> V_56 [ V_37 ] . V_60 ) ;
V_32 [ V_37 ] . V_59 = V_32 [ V_37 ] . V_60 = F_28 (
V_31 , V_4 -> V_56 [ V_37 ] . V_59 ) ;
} else {
V_32 [ V_37 ] . V_59 = V_29 +
V_4 -> V_56 [ V_37 ] . V_59 ;
V_32 [ V_37 ] . V_60 = V_29 +
V_4 -> V_56 [ V_37 ] . V_60 ;
}
} else {
V_32 [ V_37 ] . V_15 = V_4 -> V_56 [ V_37 ] . V_15 ;
V_32 [ V_37 ] . V_59 = V_4 -> V_56 [ V_37 ] . V_59 ;
V_32 [ V_37 ] . V_60 = V_4 -> V_56 [ V_37 ] . V_60 ;
}
if ( ! V_4 -> V_62 ) {
if ( F_29 ( & V_2 -> V_18 ) ) {
V_35 = F_30 ( & V_32 [ V_37 ] ) ;
if ( V_35 )
goto V_54;
}
}
}
V_35 = F_31 ( V_2 , V_32 , V_4 -> V_41 ) ;
if ( V_35 )
goto V_54;
V_35 = F_32 ( V_2 ) ;
if ( V_35 )
goto V_54;
if ( V_4 -> V_63 )
V_63 ( & V_2 -> V_18 ) ;
F_33 ( V_32 ) ;
return 0 ;
V_54:
F_34 ( & V_2 -> V_18 ,
V_4 -> V_47 ,
V_4 -> V_48 ) ;
V_49:
F_33 ( V_32 ) ;
V_42:
F_35 ( V_2 ) ;
V_40:
return V_35 ;
}
int F_36 ( struct V_26 * V_15 , int V_22 ,
const struct V_3 * V_64 , int V_65 ,
struct V_27 * V_28 ,
int V_29 , struct V_30 * V_31 )
{
int V_66 ;
int V_35 ;
T_1 * V_67 ;
V_67 = F_37 ( V_65 , sizeof( * V_67 ) , V_9 ) ;
if ( ! V_67 )
return - V_10 ;
for ( V_66 = 0 ; V_66 < V_65 ; V_66 ++ ) {
F_38 ( & V_67 [ V_66 ] , 0 ) ;
V_35 = F_20 ( V_15 , V_22 , V_64 + V_66 , V_67 + V_66 , V_28 ,
V_29 , V_31 ) ;
if ( V_35 )
goto V_68;
}
return 0 ;
V_68:
if ( V_66 )
F_39 ( V_15 ) ;
else
F_33 ( V_67 ) ;
return V_35 ;
}
static int F_40 ( struct V_26 * V_18 , void * V_69 )
{
struct V_1 * V_2 ;
const struct V_3 * V_4 ;
T_1 * * V_6 = V_69 ;
if ( V_18 -> type != & V_43 )
return 0 ;
V_2 = F_41 ( V_18 ) ;
V_4 = F_2 ( V_2 ) ;
F_34 ( V_18 , V_4 -> V_47 ,
V_4 -> V_48 ) ;
if ( ! * V_6 || ( V_4 -> V_6 < * V_6 ) )
* V_6 = V_4 -> V_6 ;
F_42 ( V_2 ) ;
return 0 ;
}
void F_39 ( struct V_26 * V_15 )
{
T_1 * V_67 = NULL ;
F_43 ( V_15 , & V_67 , F_40 ) ;
F_33 ( V_67 ) ;
}
static void F_44 ( struct V_26 * V_18 , void * V_32 )
{
F_39 ( V_18 ) ;
}
int F_45 ( struct V_26 * V_18 , int V_22 ,
const struct V_3 * V_64 , int V_65 ,
struct V_27 * V_28 ,
int V_29 , struct V_30 * V_31 )
{
struct V_26 * * V_70 ;
int V_35 ;
V_70 = F_46 ( F_44 , sizeof( * V_70 ) , V_9 ) ;
if ( ! V_70 )
return - V_10 ;
V_35 = F_36 ( V_18 , V_22 , V_64 , V_65 , V_28 ,
V_29 , V_31 ) ;
if ( V_35 < 0 ) {
F_47 ( V_70 ) ;
return V_35 ;
}
* V_70 = V_18 ;
F_48 ( V_18 , V_70 ) ;
return V_35 ;
}
int F_49 ( const char * V_4 , const char * * V_71 , T_3 V_72 )
{
struct V_3 V_73 ;
struct V_26 * V_18 ;
struct V_1 * V_2 ;
int V_66 ;
V_18 = F_50 ( & V_74 , NULL , V_4 ) ;
if ( ! V_18 ) {
F_51 ( V_75 L_2 , V_4 ) ;
return - V_76 ;
}
V_2 = F_41 ( V_18 ) ;
memcpy ( & V_73 , F_2 ( V_2 ) , sizeof( V_73 ) ) ;
F_8 ( ! V_73 . V_7 ) ;
for ( V_66 = 0 ; V_66 < V_72 ; V_66 ++ ) {
V_73 . V_39 = V_71 [ V_66 ] ;
if ( F_20 ( V_2 -> V_18 . V_15 , - 1 , & V_73 ,
V_73 . V_6 , NULL , 0 , NULL ) )
F_52 ( V_18 , L_3 ,
V_71 [ V_66 ] ) ;
}
return 0 ;
}
