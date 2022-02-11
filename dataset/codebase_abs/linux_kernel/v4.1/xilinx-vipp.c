static struct V_1 *
F_1 ( struct V_2 * V_3 ,
const struct V_4 * V_5 )
{
struct V_1 * V_6 ;
F_2 (entity, &xdev->entities, list) {
if ( V_6 -> V_5 == V_5 )
return V_6 ;
}
return NULL ;
}
static int F_3 ( struct V_2 * V_3 ,
struct V_1 * V_6 )
{
T_1 V_7 = V_8 ;
struct V_9 * V_10 = V_6 -> V_6 ;
struct V_9 * V_11 ;
struct V_12 * V_13 ;
struct V_12 * V_14 ;
struct V_1 * V_15 ;
struct V_16 V_17 ;
struct V_4 * V_18 = NULL ;
struct V_4 * V_19 ;
int V_20 = 0 ;
F_4 ( V_3 -> V_21 , L_1 , V_10 -> V_22 ) ;
while ( 1 ) {
V_19 = F_5 ( V_6 -> V_5 , V_18 ) ;
if ( V_19 == NULL )
break;
F_6 ( V_18 ) ;
V_18 = V_19 ;
F_4 ( V_3 -> V_21 , L_2 , V_18 -> V_23 ) ;
V_20 = F_7 ( V_18 , & V_17 ) ;
if ( V_20 < 0 ) {
F_8 ( V_3 -> V_21 , L_3 ,
V_18 -> V_23 ) ;
continue;
}
if ( V_17 . V_24 >= V_10 -> V_25 ) {
F_8 ( V_3 -> V_21 , L_4 ,
V_17 . V_24 , V_17 . V_26 -> V_23 ) ;
F_9 ( & V_17 ) ;
V_20 = - V_27 ;
break;
}
V_13 = & V_10 -> V_28 [ V_17 . V_24 ] ;
if ( V_13 -> V_29 & V_30 ) {
F_4 ( V_3 -> V_21 , L_5 ,
V_17 . V_26 -> V_23 , V_17 . V_24 ) ;
F_9 ( & V_17 ) ;
continue;
}
if ( V_17 . V_31 == V_3 -> V_21 -> V_32 ) {
F_4 ( V_3 -> V_21 , L_6 ,
V_17 . V_26 -> V_23 , V_17 . V_24 ) ;
F_9 ( & V_17 ) ;
continue;
}
V_15 = F_1 ( V_3 , V_17 . V_31 ) ;
if ( V_15 == NULL ) {
F_8 ( V_3 -> V_21 , L_7 ,
V_17 . V_31 -> V_23 ) ;
F_9 ( & V_17 ) ;
V_20 = - V_33 ;
break;
}
V_11 = V_15 -> V_6 ;
if ( V_17 . V_34 >= V_11 -> V_25 ) {
F_8 ( V_3 -> V_21 , L_4 ,
V_17 . V_34 , V_17 . V_31 -> V_23 ) ;
F_9 ( & V_17 ) ;
V_20 = - V_27 ;
break;
}
V_14 = & V_11 -> V_28 [ V_17 . V_34 ] ;
F_9 ( & V_17 ) ;
F_4 ( V_3 -> V_21 , L_8 ,
V_10 -> V_22 , V_13 -> V_35 ,
V_11 -> V_22 , V_14 -> V_35 ) ;
V_20 = F_10 ( V_10 , V_13 -> V_35 ,
V_11 , V_14 -> V_35 ,
V_7 ) ;
if ( V_20 < 0 ) {
F_8 ( V_3 -> V_21 ,
L_9 ,
V_10 -> V_22 , V_13 -> V_35 ,
V_11 -> V_22 , V_14 -> V_35 ) ;
break;
}
}
F_6 ( V_18 ) ;
return V_20 ;
}
static struct V_36 *
F_11 ( struct V_2 * V_3 , unsigned int V_37 )
{
struct V_36 * V_38 ;
F_2 (dma, &xdev->dmas, list) {
if ( V_38 -> V_37 == V_37 )
return V_38 ;
}
return NULL ;
}
static int F_12 ( struct V_2 * V_3 )
{
T_1 V_7 = V_8 ;
struct V_4 * V_5 = V_3 -> V_21 -> V_32 ;
struct V_9 * V_39 ;
struct V_9 * V_40 ;
struct V_12 * V_41 ;
struct V_12 * V_42 ;
struct V_1 * V_15 ;
struct V_16 V_17 ;
struct V_4 * V_18 = NULL ;
struct V_4 * V_19 ;
struct V_36 * V_38 ;
int V_20 = 0 ;
F_4 ( V_3 -> V_21 , L_10 ) ;
while ( 1 ) {
V_19 = F_5 ( V_5 , V_18 ) ;
if ( V_19 == NULL )
break;
F_6 ( V_18 ) ;
V_18 = V_19 ;
F_4 ( V_3 -> V_21 , L_2 , V_18 -> V_23 ) ;
V_20 = F_7 ( V_18 , & V_17 ) ;
if ( V_20 < 0 ) {
F_8 ( V_3 -> V_21 , L_3 ,
V_18 -> V_23 ) ;
continue;
}
V_38 = F_11 ( V_3 , V_17 . V_24 ) ;
if ( V_38 == NULL ) {
F_8 ( V_3 -> V_21 , L_11 ,
V_17 . V_24 ) ;
F_9 ( & V_17 ) ;
V_20 = - V_27 ;
break;
}
F_4 ( V_3 -> V_21 , L_12 ,
V_38 -> V_43 . V_22 ) ;
V_15 = F_1 ( V_3 , V_17 . V_31 ) ;
if ( V_15 == NULL ) {
F_8 ( V_3 -> V_21 , L_7 ,
V_17 . V_31 -> V_23 ) ;
F_9 ( & V_17 ) ;
V_20 = - V_33 ;
break;
}
if ( V_17 . V_34 >= V_15 -> V_6 -> V_25 ) {
F_8 ( V_3 -> V_21 , L_4 ,
V_17 . V_34 , V_17 . V_31 -> V_23 ) ;
F_9 ( & V_17 ) ;
V_20 = - V_27 ;
break;
}
if ( V_38 -> V_44 . V_29 & V_45 ) {
V_39 = & V_38 -> V_43 . V_6 ;
V_41 = & V_38 -> V_44 ;
V_40 = V_15 -> V_6 ;
V_42 = & V_40 -> V_28 [ V_17 . V_34 ] ;
} else {
V_39 = V_15 -> V_6 ;
V_41 = & V_39 -> V_28 [ V_17 . V_34 ] ;
V_40 = & V_38 -> V_43 . V_6 ;
V_42 = & V_38 -> V_44 ;
}
F_9 ( & V_17 ) ;
F_4 ( V_3 -> V_21 , L_8 ,
V_39 -> V_22 , V_41 -> V_35 ,
V_40 -> V_22 , V_42 -> V_35 ) ;
V_20 = F_10 ( V_39 , V_41 -> V_35 ,
V_40 , V_42 -> V_35 ,
V_7 ) ;
if ( V_20 < 0 ) {
F_8 ( V_3 -> V_21 ,
L_9 ,
V_39 -> V_22 , V_41 -> V_35 ,
V_40 -> V_22 , V_42 -> V_35 ) ;
break;
}
}
F_6 ( V_18 ) ;
return V_20 ;
}
static int F_13 ( struct V_46 * V_47 )
{
struct V_2 * V_3 =
F_14 ( V_47 , struct V_2 , V_47 ) ;
struct V_1 * V_6 ;
int V_20 ;
F_4 ( V_3 -> V_21 , L_13 ) ;
F_2 (entity, &xdev->entities, list) {
V_20 = F_3 ( V_3 , V_6 ) ;
if ( V_20 < 0 )
return V_20 ;
}
V_20 = F_12 ( V_3 ) ;
if ( V_20 < 0 )
return V_20 ;
V_20 = F_15 ( & V_3 -> V_48 ) ;
if ( V_20 < 0 )
F_8 ( V_3 -> V_21 , L_14 ) ;
return V_20 ;
}
static int F_16 ( struct V_46 * V_47 ,
struct V_49 * V_50 ,
struct V_51 * V_52 )
{
struct V_2 * V_3 =
F_14 ( V_47 , struct V_2 , V_47 ) ;
struct V_1 * V_6 ;
F_2 (entity, &xdev->entities, list) {
if ( V_6 -> V_5 != V_50 -> V_21 -> V_32 )
continue;
if ( V_6 -> V_50 ) {
F_8 ( V_3 -> V_21 , L_15 ,
V_6 -> V_5 -> V_23 ) ;
return - V_27 ;
}
F_4 ( V_3 -> V_21 , L_16 , V_50 -> V_22 ) ;
V_6 -> V_6 = & V_50 -> V_6 ;
V_6 -> V_50 = V_50 ;
return 0 ;
}
F_8 ( V_3 -> V_21 , L_17 , V_50 -> V_22 ) ;
return - V_27 ;
}
static int F_17 ( struct V_2 * V_3 ,
struct V_4 * V_5 )
{
struct V_1 * V_6 ;
struct V_4 * V_11 ;
struct V_4 * V_18 = NULL ;
struct V_4 * V_19 ;
int V_20 = 0 ;
F_4 ( V_3 -> V_21 , L_18 , V_5 -> V_23 ) ;
while ( 1 ) {
V_19 = F_5 ( V_5 , V_18 ) ;
if ( V_19 == NULL )
break;
F_6 ( V_18 ) ;
V_18 = V_19 ;
F_4 ( V_3 -> V_21 , L_19 , V_18 -> V_23 ) ;
V_11 = F_18 ( V_18 ) ;
if ( V_11 == NULL ) {
V_20 = - V_27 ;
break;
}
if ( V_11 == V_3 -> V_21 -> V_32 ||
F_1 ( V_3 , V_11 ) ) {
F_6 ( V_11 ) ;
continue;
}
V_6 = F_19 ( V_3 -> V_21 , sizeof( * V_6 ) , V_53 ) ;
if ( V_6 == NULL ) {
F_6 ( V_11 ) ;
V_20 = - V_54 ;
break;
}
V_6 -> V_5 = V_11 ;
V_6 -> V_52 . V_55 = V_56 ;
V_6 -> V_52 . V_57 . V_58 . V_5 = V_11 ;
F_20 ( & V_6 -> V_59 , & V_3 -> V_60 ) ;
V_3 -> V_61 ++ ;
}
F_6 ( V_18 ) ;
return V_20 ;
}
static int F_21 ( struct V_2 * V_3 )
{
struct V_1 * V_6 ;
int V_20 ;
V_20 = F_17 ( V_3 , V_3 -> V_21 -> V_32 ) ;
if ( V_20 < 0 )
return 0 ;
F_2 (entity, &xdev->entities, list) {
V_20 = F_17 ( V_3 , V_6 -> V_5 ) ;
if ( V_20 < 0 )
break;
}
return V_20 ;
}
static int F_22 ( struct V_2 * V_3 ,
struct V_4 * V_5 )
{
struct V_36 * V_38 ;
enum V_62 type ;
const char * V_63 ;
unsigned int V_35 ;
int V_20 ;
V_20 = F_23 ( V_5 , L_20 , & V_63 ) ;
if ( V_20 < 0 )
return V_20 ;
if ( strcmp ( V_63 , L_21 ) == 0 )
type = V_64 ;
else if ( strcmp ( V_63 , L_22 ) == 0 )
type = V_65 ;
else
return - V_27 ;
F_24 ( V_5 , L_23 , & V_35 ) ;
V_38 = F_19 ( V_3 -> V_21 , sizeof( * V_38 ) , V_53 ) ;
if ( V_38 == NULL )
return - V_54 ;
V_20 = F_25 ( V_3 , V_38 , type , V_35 ) ;
if ( V_20 < 0 ) {
F_8 ( V_3 -> V_21 , L_24 ,
V_5 -> V_23 ) ;
return V_20 ;
}
F_20 ( & V_38 -> V_59 , & V_3 -> V_66 ) ;
V_3 -> V_67 |= type == V_64
? V_68 : V_69 ;
return 0 ;
}
static int F_26 ( struct V_2 * V_3 )
{
struct V_4 * V_70 ;
struct V_4 * V_37 ;
int V_20 ;
V_70 = F_27 ( V_3 -> V_21 -> V_32 , L_25 ) ;
if ( V_70 == NULL ) {
F_8 ( V_3 -> V_21 , L_26 ) ;
return - V_27 ;
}
F_28 (ports, port) {
V_20 = F_22 ( V_3 , V_37 ) ;
if ( V_20 < 0 )
return V_20 ;
}
return 0 ;
}
static void F_29 ( struct V_2 * V_3 )
{
struct V_1 * V_71 ;
struct V_1 * V_6 ;
struct V_36 * V_72 ;
struct V_36 * V_38 ;
F_30 ( & V_3 -> V_47 ) ;
F_31 (entity, entityp, &xdev->entities, list) {
F_6 ( V_6 -> V_5 ) ;
F_32 ( & V_6 -> V_59 ) ;
}
F_31 (dma, dmap, &xdev->dmas, list) {
F_33 ( V_38 ) ;
F_32 ( & V_38 -> V_59 ) ;
}
}
static int F_34 ( struct V_2 * V_3 )
{
struct V_1 * V_6 ;
struct V_51 * * V_73 = NULL ;
unsigned int V_61 ;
unsigned int V_74 ;
int V_20 ;
V_20 = F_26 ( V_3 ) ;
if ( V_20 < 0 ) {
F_8 ( V_3 -> V_21 , L_27 ) ;
goto V_75;
}
V_20 = F_21 ( V_3 ) ;
if ( V_20 < 0 ) {
F_8 ( V_3 -> V_21 , L_28 ) ;
goto V_75;
}
if ( ! V_3 -> V_61 ) {
F_8 ( V_3 -> V_21 , L_29 ) ;
goto V_75;
}
V_61 = V_3 -> V_61 ;
V_73 = F_19 ( V_3 -> V_21 , sizeof( * V_73 ) * V_61 ,
V_53 ) ;
if ( V_73 == NULL ) {
V_20 = - V_54 ;
goto V_75;
}
V_74 = 0 ;
F_2 (entity, &xdev->entities, list)
V_73 [ V_74 ++ ] = & V_6 -> V_52 ;
V_3 -> V_47 . V_73 = V_73 ;
V_3 -> V_47 . V_61 = V_61 ;
V_3 -> V_47 . V_76 = F_16 ;
V_3 -> V_47 . V_77 = F_13 ;
V_20 = F_35 ( & V_3 -> V_48 , & V_3 -> V_47 ) ;
if ( V_20 < 0 ) {
F_8 ( V_3 -> V_21 , L_30 ) ;
goto V_75;
}
V_20 = 0 ;
V_75:
if ( V_20 < 0 )
F_29 ( V_3 ) ;
return V_20 ;
}
static void F_36 ( struct V_2 * V_3 )
{
F_37 ( & V_3 -> V_48 ) ;
F_38 ( & V_3 -> V_78 ) ;
}
static int F_39 ( struct V_2 * V_3 )
{
int V_20 ;
V_3 -> V_78 . V_21 = V_3 -> V_21 ;
F_40 ( V_3 -> V_78 . V_79 , L_31 ,
sizeof( V_3 -> V_78 . V_79 ) ) ;
V_3 -> V_78 . V_80 = 0 ;
V_20 = F_41 ( & V_3 -> V_78 ) ;
if ( V_20 < 0 ) {
F_8 ( V_3 -> V_21 , L_32 ,
V_20 ) ;
return V_20 ;
}
V_3 -> V_48 . V_81 = & V_3 -> V_78 ;
V_20 = F_42 ( V_3 -> V_21 , & V_3 -> V_48 ) ;
if ( V_20 < 0 ) {
F_8 ( V_3 -> V_21 , L_33 ,
V_20 ) ;
F_38 ( & V_3 -> V_78 ) ;
return V_20 ;
}
return 0 ;
}
static int F_43 ( struct V_82 * V_83 )
{
struct V_2 * V_3 ;
int V_20 ;
V_3 = F_19 ( & V_83 -> V_21 , sizeof( * V_3 ) , V_53 ) ;
if ( ! V_3 )
return - V_54 ;
V_3 -> V_21 = & V_83 -> V_21 ;
F_44 ( & V_3 -> V_60 ) ;
F_44 ( & V_3 -> V_66 ) ;
V_20 = F_39 ( V_3 ) ;
if ( V_20 < 0 )
return V_20 ;
V_20 = F_34 ( V_3 ) ;
if ( V_20 < 0 )
goto error;
F_45 ( V_83 , V_3 ) ;
F_46 ( V_3 -> V_21 , L_34 ) ;
return 0 ;
error:
F_36 ( V_3 ) ;
return V_20 ;
}
static int F_47 ( struct V_82 * V_83 )
{
struct V_2 * V_3 = F_48 ( V_83 ) ;
F_29 ( V_3 ) ;
F_36 ( V_3 ) ;
return 0 ;
}
