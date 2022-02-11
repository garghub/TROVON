static int F_1 ( struct V_1 * V_2 , T_1 * V_3 )
{
struct V_4 * V_5 ;
const char * V_6 ;
unsigned int V_7 , V_8 ;
F_2 (device, L_1 , prop, cp) {
if ( sscanf ( V_6 , L_2 , & V_7 , & V_8 ) == 2 ) {
* V_3 = ( ( V_7 & 0xFFFF ) << 16 ) | ( V_8 & 0xFFFF ) ;
return 0 ;
}
}
return - V_9 ;
}
static void F_3 ( struct V_10 * V_11 ,
struct V_1 * V_12 , T_1 V_13 )
{
struct V_14 * V_15 ;
bool V_16 ;
int V_17 ;
T_1 V_3 ;
V_16 = F_4 ( V_12 ,
L_3 ) ;
if ( ! V_16 && ! F_1 ( V_12 , & V_3 ) )
V_15 = F_5 ( V_11 , V_13 , V_3 , 0 , NULL ) ;
else
V_15 = F_6 ( V_11 , V_13 , V_16 ) ;
if ( F_7 ( V_15 ) )
return;
V_17 = F_8 ( V_12 , 0 ) ;
if ( V_17 > 0 ) {
V_15 -> V_18 = V_17 ;
V_11 -> V_18 [ V_13 ] = V_17 ;
} else {
V_15 -> V_18 = V_11 -> V_18 [ V_13 ] ;
}
if ( F_9 ( V_12 , L_4 ) )
V_11 -> V_19 |= 1 << V_13 ;
F_10 ( V_12 ) ;
V_15 -> V_11 . V_20 . V_21 = V_12 ;
V_17 = F_11 ( V_15 ) ;
if ( V_17 ) {
F_12 ( V_15 ) ;
F_13 ( V_12 ) ;
return;
}
F_14 ( & V_11 -> V_20 , L_5 ,
V_12 -> V_22 , V_13 ) ;
}
static void F_15 ( struct V_10 * V_11 ,
struct V_1 * V_12 , T_1 V_13 )
{
struct V_23 * V_24 ;
int V_17 ;
V_24 = F_16 ( V_11 , V_13 ) ;
if ( F_7 ( V_24 ) )
return;
F_10 ( V_12 ) ;
V_24 -> V_20 . V_21 = V_12 ;
V_17 = F_17 ( V_24 ) ;
if ( V_17 ) {
F_18 ( V_24 ) ;
F_13 ( V_12 ) ;
return;
}
F_14 ( & V_11 -> V_20 , L_6 ,
V_12 -> V_22 , V_13 ) ;
}
static bool F_19 ( struct V_1 * V_12 )
{
T_1 V_3 ;
if ( F_1 ( V_12 , & V_3 ) != - V_9 )
return true ;
if ( F_4 ( V_12 , L_3 ) )
return true ;
if ( F_4 ( V_12 , L_7 ) )
return true ;
if ( F_20 ( V_25 , V_12 ) ) {
F_21 ( V_26
L_8 ,
V_12 -> V_27 ) ;
return true ;
}
if ( ! F_22 ( V_12 , L_1 , NULL ) )
return true ;
return false ;
}
int F_23 ( struct V_10 * V_11 , struct V_1 * V_28 )
{
struct V_1 * V_12 ;
bool V_29 = false ;
int V_13 , V_17 ;
if ( ! F_24 ( V_28 ) )
return - V_30 ;
V_11 -> V_31 = ~ 0 ;
V_11 -> V_20 . V_21 = V_28 ;
V_11 -> V_32 = V_33 ;
F_25 ( V_28 , L_9 , & V_11 -> V_32 ) ;
V_17 = F_26 ( V_11 ) ;
if ( V_17 )
return V_17 ;
F_27 (np, child) {
V_13 = F_28 ( & V_11 -> V_20 , V_12 ) ;
if ( V_13 < 0 ) {
V_29 = true ;
continue;
}
if ( F_19 ( V_12 ) )
F_3 ( V_11 , V_12 , V_13 ) ;
else
F_15 ( V_11 , V_12 , V_13 ) ;
}
if ( ! V_29 )
return 0 ;
F_27 (np, child) {
if ( F_22 ( V_12 , L_10 , NULL ) )
continue;
for ( V_13 = 0 ; V_13 < V_34 ; V_13 ++ ) {
if ( F_29 ( V_11 , V_13 ) )
continue;
F_30 ( & V_11 -> V_20 , L_11 ,
V_12 -> V_22 , V_13 ) ;
if ( F_19 ( V_12 ) )
F_3 ( V_11 , V_12 , V_13 ) ;
}
}
return 0 ;
}
static int F_31 ( struct V_2 * V_20 , void * V_35 )
{
return V_20 -> V_21 == V_35 ;
}
struct V_14 * F_32 ( struct V_1 * V_35 )
{
struct V_2 * V_36 ;
struct V_23 * V_24 ;
if ( ! V_35 )
return NULL ;
V_36 = F_33 ( & V_37 , NULL , V_35 , F_31 ) ;
if ( V_36 ) {
V_24 = F_34 ( V_36 ) ;
if ( V_24 -> V_38 & V_39 )
return F_35 ( V_36 ) ;
F_36 ( V_36 ) ;
}
return NULL ;
}
struct V_14 * F_37 ( struct V_40 * V_20 ,
struct V_1 * V_35 ,
void (* F_38)( struct V_40 * ) , T_1 V_38 ,
T_2 V_41 )
{
struct V_14 * V_15 = F_32 ( V_35 ) ;
int V_42 ;
if ( ! V_15 )
return NULL ;
V_15 -> V_43 = V_38 ;
V_42 = F_39 ( V_20 , V_15 , F_38 , V_41 ) ;
F_36 ( & V_15 -> V_11 . V_20 ) ;
return V_42 ? NULL : V_15 ;
}
struct V_14 * F_40 ( struct V_40 * V_20 ,
struct V_1 * V_28 ,
void (* F_38)( struct V_40 * ) )
{
T_2 V_41 ;
struct V_1 * V_35 ;
struct V_14 * V_15 ;
V_41 = F_41 ( V_28 ) ;
if ( V_41 < 0 )
return NULL ;
V_35 = F_42 ( V_28 , L_12 , 0 ) ;
if ( ! V_35 )
return NULL ;
V_15 = F_37 ( V_20 , V_35 , F_38 , 0 , V_41 ) ;
F_13 ( V_35 ) ;
return V_15 ;
}
struct V_14 * F_43 ( struct V_40 * V_20 ,
struct V_1 * V_35 , T_1 V_38 ,
T_2 V_41 )
{
struct V_14 * V_15 = F_32 ( V_35 ) ;
int V_42 ;
if ( ! V_15 )
return NULL ;
V_42 = F_44 ( V_20 , V_15 , V_38 , V_41 ) ;
F_36 ( & V_15 -> V_11 . V_20 ) ;
return V_42 ? NULL : V_15 ;
}
bool F_45 ( struct V_1 * V_28 )
{
struct V_1 * V_44 ;
int V_45 , V_46 ;
const char * V_47 ;
V_44 = F_46 ( V_28 , L_13 ) ;
if ( V_44 ) {
F_13 ( V_44 ) ;
return true ;
}
V_46 = F_47 ( V_28 , L_14 , & V_47 ) ;
if ( V_46 == 0 && strcmp ( V_47 , L_15 ) != 0 )
return true ;
if ( F_48 ( V_28 , L_13 , & V_45 ) &&
V_45 == ( 5 * sizeof( V_48 ) ) )
return true ;
return false ;
}
int F_49 ( struct V_1 * V_28 )
{
struct V_49 V_50 = {} ;
struct V_1 * V_51 ;
const V_48 * V_52 ;
int V_53 ;
int V_45 , V_46 ;
struct V_14 * V_15 ;
const char * V_47 ;
V_46 = F_47 ( V_28 , L_14 , & V_47 ) ;
if ( V_46 == 0 ) {
if ( strcmp ( V_47 , L_16 ) == 0 ) {
V_15 = F_50 ( V_54 , & V_50 , - 1 , V_28 ) ;
return F_51 ( V_15 ) ;
}
}
V_51 = F_46 ( V_28 , L_13 ) ;
if ( V_51 ) {
V_50 . V_55 = 1 ;
V_50 . V_56 = F_9 ( V_51 ,
L_17 ) ;
if ( F_25 ( V_51 , L_18 ,
& V_50 . V_57 ) ) {
F_13 ( V_51 ) ;
return - V_9 ;
}
V_50 . V_58 = F_9 ( V_51 , L_19 ) ;
V_50 . V_59 = F_9 ( V_51 ,
L_20 ) ;
V_53 = F_52 ( V_51 ,
L_21 , 0 , NULL ) ;
F_13 ( V_51 ) ;
if ( V_53 == - V_60 )
return - V_60 ;
V_15 = F_50 ( V_54 , & V_50 , V_53 , V_28 ) ;
return F_51 ( V_15 ) ;
}
V_52 = F_48 ( V_28 , L_13 , & V_45 ) ;
if ( V_52 && V_45 == ( 5 * sizeof( V_48 ) ) ) {
V_50 . V_55 = 1 ;
V_50 . V_56 = F_53 ( V_52 [ 1 ] ) ;
V_50 . V_57 = F_53 ( V_52 [ 2 ] ) ;
V_50 . V_58 = F_53 ( V_52 [ 3 ] ) ;
V_50 . V_59 = F_53 ( V_52 [ 4 ] ) ;
V_15 = F_50 ( V_54 , & V_50 , - 1 , V_28 ) ;
return F_51 ( V_15 ) ;
}
return - V_30 ;
}
void F_54 ( struct V_1 * V_28 )
{
struct V_14 * V_61 ;
V_61 = F_32 ( V_28 ) ;
if ( ! V_61 )
return;
F_55 ( V_61 ) ;
F_36 ( & V_61 -> V_11 . V_20 ) ;
F_12 ( V_61 ) ;
}
