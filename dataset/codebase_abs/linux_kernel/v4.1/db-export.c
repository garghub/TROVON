static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_5 ;
while ( ! F_2 ( & V_2 -> V_6 ) ) {
V_4 = F_3 ( V_2 -> V_6 . V_7 , struct V_3 ,
V_8 ) ;
V_5 = V_2 -> V_9 ( V_2 , V_4 -> V_10 ) ;
F_4 ( & V_4 -> V_8 ) ;
free ( V_4 ) ;
if ( V_5 )
return V_5 ;
}
return 0 ;
}
static void F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
while ( ! F_2 ( & V_2 -> V_6 ) ) {
V_4 = F_3 ( V_2 -> V_6 . V_7 , struct V_3 ,
V_8 ) ;
F_4 ( & V_4 -> V_8 ) ;
free ( V_4 ) ;
}
}
static int F_6 ( struct V_1 * V_2 , struct V_10 * V_10 )
{
struct V_3 * V_4 ;
V_4 = F_7 ( sizeof( struct V_3 ) ) ;
if ( ! V_4 )
return - V_11 ;
V_4 -> V_10 = V_10 ;
F_8 ( & V_4 -> V_8 , & V_2 -> V_6 ) ;
return 0 ;
}
int F_9 ( struct V_1 * V_2 )
{
memset ( V_2 , 0 , sizeof( struct V_1 ) ) ;
F_10 ( & V_2 -> V_6 ) ;
return 0 ;
}
int F_11 ( struct V_1 * V_2 )
{
return F_1 ( V_2 ) ;
}
void F_12 ( struct V_1 * V_2 )
{
F_5 ( V_2 ) ;
F_13 ( V_2 -> V_12 ) ;
V_2 -> V_12 = NULL ;
}
int F_14 ( struct V_1 * V_2 , struct V_13 * V_14 )
{
if ( V_14 -> V_15 )
return 0 ;
V_14 -> V_15 = ++ V_2 -> V_16 ;
if ( V_2 -> V_17 )
return V_2 -> V_17 ( V_2 , V_14 ) ;
return 0 ;
}
int F_15 ( struct V_1 * V_2 , struct V_18 * V_18 )
{
if ( V_18 -> V_15 )
return 0 ;
V_18 -> V_15 = ++ V_2 -> V_19 ;
if ( V_2 -> V_20 )
return V_2 -> V_20 ( V_2 , V_18 ) ;
return 0 ;
}
int F_16 ( struct V_1 * V_2 , struct V_21 * V_21 ,
struct V_18 * V_18 , struct V_10 * V_10 )
{
T_1 V_22 = 0 ;
int V_5 ;
if ( V_21 -> V_15 )
return 0 ;
V_21 -> V_15 = ++ V_2 -> V_23 ;
if ( V_21 -> V_24 != - 1 ) {
struct V_21 * V_25 ;
if ( V_21 -> V_24 == V_21 -> V_26 ) {
V_25 = V_21 ;
} else {
V_25 = F_17 ( V_18 ,
V_21 -> V_24 ,
V_21 -> V_24 ) ;
if ( ! V_25 )
return - V_11 ;
V_5 = F_16 ( V_2 , V_25 , V_18 ,
V_10 ) ;
if ( V_5 )
return V_5 ;
if ( V_10 ) {
V_5 = F_18 ( V_2 , V_10 , V_21 ) ;
if ( V_5 )
return V_5 ;
}
}
V_22 = V_25 -> V_15 ;
}
if ( V_2 -> V_27 )
return V_2 -> V_27 ( V_2 , V_21 , V_22 ,
V_18 ) ;
return 0 ;
}
int F_19 ( struct V_1 * V_2 , struct V_10 * V_10 ,
struct V_21 * V_25 )
{
int V_5 ;
if ( V_10 -> V_15 )
return 0 ;
V_10 -> V_15 = ++ V_2 -> V_28 ;
if ( V_2 -> V_9 ) {
if ( V_25 -> V_29 )
V_5 = V_2 -> V_9 ( V_2 , V_10 ) ;
else
V_5 = F_6 ( V_2 , V_10 ) ;
if ( V_5 )
return V_5 ;
}
return F_18 ( V_2 , V_10 , V_25 ) ;
}
int F_18 ( struct V_1 * V_2 , struct V_10 * V_10 ,
struct V_21 * V_21 )
{
T_1 V_15 ;
V_15 = ++ V_2 -> V_30 ;
if ( V_2 -> V_31 )
return V_2 -> V_31 ( V_2 , V_15 , V_10 , V_21 ) ;
return 0 ;
}
int F_20 ( struct V_1 * V_2 , struct V_32 * V_32 ,
struct V_18 * V_18 )
{
if ( V_32 -> V_15 )
return 0 ;
V_32 -> V_15 = ++ V_2 -> V_33 ;
if ( V_2 -> V_34 )
return V_2 -> V_34 ( V_2 , V_32 , V_18 ) ;
return 0 ;
}
int F_21 ( struct V_1 * V_2 , struct V_35 * V_36 ,
struct V_32 * V_32 )
{
T_1 * V_37 = F_22 ( V_36 ) ;
if ( * V_37 )
return 0 ;
* V_37 = ++ V_2 -> V_38 ;
if ( V_2 -> V_39 )
return V_2 -> V_39 ( V_2 , V_36 , V_32 ) ;
return 0 ;
}
static struct V_21 * F_23 ( struct V_18 * V_18 , struct V_21 * V_21 )
{
if ( V_21 -> V_24 == V_21 -> V_26 )
return V_21 ;
if ( V_21 -> V_24 == - 1 )
return NULL ;
return F_24 ( V_18 , V_21 -> V_24 , V_21 -> V_24 ) ;
}
static int F_25 ( struct V_1 * V_2 , struct V_40 * V_41 ,
T_1 * V_42 , T_1 * V_37 , T_1 * V_43 )
{
int V_5 ;
if ( V_41 -> V_44 ) {
struct V_32 * V_32 = V_41 -> V_44 -> V_32 ;
V_5 = F_20 ( V_2 , V_32 , V_41 -> V_18 ) ;
if ( V_5 )
return V_5 ;
* V_42 = V_32 -> V_15 ;
if ( ! V_41 -> V_36 ) {
V_41 -> V_36 = F_26 ( V_41 -> V_45 , 0 , 0 , L_1 ) ;
if ( V_41 -> V_36 )
F_27 ( & V_32 -> V_46 [ V_41 -> V_44 -> type ] ,
V_41 -> V_36 ) ;
}
if ( V_41 -> V_36 ) {
T_1 * V_15 = F_22 ( V_41 -> V_36 ) ;
V_5 = F_21 ( V_2 , V_41 -> V_36 , V_32 ) ;
if ( V_5 )
return V_5 ;
* V_37 = * V_15 ;
* V_43 = V_41 -> V_45 - V_41 -> V_36 -> V_47 ;
}
}
return 0 ;
}
int F_28 ( struct V_1 * V_2 , T_2 V_48 ,
const char * V_49 )
{
if ( V_2 -> V_50 )
return V_2 -> V_50 ( V_2 , V_48 , V_49 ) ;
return 0 ;
}
int F_29 ( struct V_1 * V_2 , union V_51 * V_52 ,
struct V_53 * V_54 , struct V_13 * V_14 ,
struct V_40 * V_41 )
{
struct V_21 * V_21 = V_41 -> V_21 ;
struct V_55 V_56 = {
. V_52 = V_52 ,
. V_54 = V_54 ,
. V_14 = V_14 ,
. V_41 = V_41 ,
} ;
struct V_21 * V_25 ;
struct V_10 * V_10 = NULL ;
int V_5 ;
V_5 = F_14 ( V_2 , V_14 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_15 ( V_2 , V_41 -> V_18 ) ;
if ( V_5 )
return V_5 ;
V_25 = F_23 ( V_41 -> V_18 , V_21 ) ;
if ( V_25 )
V_10 = F_30 ( V_41 -> V_18 , V_25 ) ;
V_5 = F_16 ( V_2 , V_21 , V_41 -> V_18 , V_10 ) ;
if ( V_5 )
return V_5 ;
if ( V_10 ) {
V_5 = F_19 ( V_2 , V_10 , V_25 ) ;
if ( V_5 )
return V_5 ;
V_56 . V_57 = V_10 -> V_15 ;
}
V_56 . V_15 = ++ V_2 -> V_58 ;
V_5 = F_25 ( V_2 , V_41 , & V_56 . V_42 , & V_56 . V_37 , & V_56 . V_43 ) ;
if ( V_5 )
return V_5 ;
if ( ( V_14 -> V_59 . V_60 & V_61 ) &&
F_31 ( & V_14 -> V_59 ) ) {
struct V_40 V_62 ;
F_32 ( V_52 , V_54 , V_21 , & V_62 ) ;
V_5 = F_25 ( V_2 , & V_62 , & V_56 . V_63 ,
& V_56 . V_64 , & V_56 . V_65 ) ;
if ( V_5 )
return V_5 ;
if ( V_2 -> V_12 ) {
V_5 = F_33 ( V_21 , V_10 , V_54 , V_41 ,
& V_62 , V_56 . V_15 ,
V_2 -> V_12 ) ;
if ( V_5 )
return V_5 ;
}
}
if ( V_2 -> V_55 )
return V_2 -> V_55 ( V_2 , & V_56 ) ;
return 0 ;
}
int F_34 ( struct V_1 * V_2 )
{
int V_66 , V_5 = 0 ;
for ( V_66 = 0 ; V_67 [ V_66 ] . V_49 ; V_66 ++ ) {
V_5 = F_28 ( V_2 , V_67 [ V_66 ] . V_48 ,
V_67 [ V_66 ] . V_49 ) ;
if ( V_5 )
break;
}
return V_5 ;
}
int F_35 ( struct V_1 * V_2 , struct V_68 * V_69 )
{
int V_5 ;
if ( V_69 -> V_15 )
return 0 ;
if ( V_69 -> V_70 ) {
V_5 = F_35 ( V_2 , V_69 -> V_70 ) ;
if ( V_5 )
return V_5 ;
}
V_69 -> V_15 = ++ V_2 -> V_71 ;
if ( V_2 -> V_72 )
return V_2 -> V_72 ( V_2 , V_69 ) ;
return 0 ;
}
int F_36 ( struct V_1 * V_2 , struct V_73 * V_74 )
{
int V_5 ;
if ( V_74 -> V_15 )
return 0 ;
V_5 = F_35 ( V_2 , V_74 -> V_69 ) ;
if ( V_5 )
return V_5 ;
V_74 -> V_15 = ++ V_2 -> V_75 ;
if ( V_2 -> V_76 )
return V_2 -> V_76 ( V_2 , V_74 ) ;
return 0 ;
}
