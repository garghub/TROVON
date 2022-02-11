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
static int F_3 ( struct V_10 * V_11 , struct V_1 * V_12 ,
T_1 V_13 )
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
return 1 ;
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
return 1 ;
}
F_14 ( & V_11 -> V_20 , L_5 ,
V_12 -> V_22 , V_13 ) ;
return 0 ;
}
static int F_15 ( struct V_10 * V_11 ,
struct V_1 * V_12 ,
T_1 V_13 )
{
struct V_23 * V_24 ;
int V_17 ;
V_24 = F_16 ( V_11 , V_13 ) ;
if ( F_17 ( V_24 ) )
return 1 ;
F_10 ( V_12 ) ;
V_24 -> V_20 . V_21 = V_12 ;
V_17 = F_18 ( V_24 ) ;
if ( V_17 ) {
F_19 ( V_24 ) ;
F_13 ( V_12 ) ;
return 1 ;
}
F_14 ( & V_11 -> V_20 , L_6 ,
V_12 -> V_22 , V_13 ) ;
return 0 ;
}
int F_20 ( struct V_2 * V_20 , const struct V_1 * V_25 )
{
T_1 V_13 ;
int V_26 ;
V_26 = F_21 ( V_25 , L_7 , & V_13 ) ;
if ( V_26 < 0 ) {
F_22 ( V_20 , L_8 , V_25 -> V_27 ) ;
return V_26 ;
}
if ( V_13 >= V_28 ) {
F_22 ( V_20 , L_9 ,
V_25 -> V_27 , V_13 ) ;
return - V_9 ;
}
return V_13 ;
}
static bool F_23 ( struct V_1 * V_12 )
{
T_1 V_3 ;
if ( F_1 ( V_12 , & V_3 ) != - V_9 )
return true ;
if ( F_4 ( V_12 , L_3 ) )
return true ;
if ( F_4 ( V_12 , L_10 ) )
return true ;
if ( F_24 ( V_29 , V_12 ) ) {
F_25 ( V_30
L_11 ,
V_12 -> V_27 ) ;
return true ;
}
if ( ! F_26 ( V_12 , L_1 , NULL ) )
return true ;
return false ;
}
int F_27 ( struct V_10 * V_11 , struct V_1 * V_25 )
{
struct V_1 * V_12 ;
bool V_31 = false ;
int V_13 , V_17 ;
V_11 -> V_32 = ~ 0 ;
V_11 -> V_20 . V_21 = V_25 ;
V_17 = F_28 ( V_11 ) ;
if ( V_17 )
return V_17 ;
F_29 (np, child) {
V_13 = F_20 ( & V_11 -> V_20 , V_12 ) ;
if ( V_13 < 0 ) {
V_31 = true ;
continue;
}
if ( F_23 ( V_12 ) )
F_3 ( V_11 , V_12 , V_13 ) ;
else
F_15 ( V_11 , V_12 , V_13 ) ;
}
if ( ! V_31 )
return 0 ;
F_29 (np, child) {
if ( F_26 ( V_12 , L_7 , NULL ) )
continue;
for ( V_13 = 0 ; V_13 < V_28 ; V_13 ++ ) {
if ( F_30 ( V_11 , V_13 ) )
continue;
F_31 ( & V_11 -> V_20 , L_12 ,
V_12 -> V_22 , V_13 ) ;
if ( F_23 ( V_12 ) )
F_3 ( V_11 , V_12 , V_13 ) ;
}
}
return 0 ;
}
static int F_32 ( struct V_2 * V_20 , void * V_33 )
{
return V_20 -> V_21 == V_33 ;
}
struct V_14 * F_33 ( struct V_1 * V_33 )
{
struct V_2 * V_34 ;
struct V_23 * V_24 ;
if ( ! V_33 )
return NULL ;
V_34 = F_34 ( & V_35 , NULL , V_33 , F_32 ) ;
if ( V_34 ) {
V_24 = F_35 ( V_34 ) ;
if ( V_24 -> V_36 & V_37 )
return F_36 ( V_34 ) ;
}
return NULL ;
}
struct V_14 * F_37 ( struct V_38 * V_20 ,
struct V_1 * V_33 ,
void (* F_38)( struct V_38 * ) , T_1 V_36 ,
T_2 V_39 )
{
struct V_14 * V_15 = F_33 ( V_33 ) ;
int V_26 ;
if ( ! V_15 )
return NULL ;
V_15 -> V_40 = V_36 ;
V_26 = F_39 ( V_20 , V_15 , F_38 , V_39 ) ;
F_40 ( & V_15 -> V_11 . V_20 ) ;
return V_26 ? NULL : V_15 ;
}
struct V_14 * F_41 ( struct V_38 * V_20 ,
struct V_1 * V_33 , T_1 V_36 ,
T_2 V_39 )
{
struct V_14 * V_15 = F_33 ( V_33 ) ;
int V_26 ;
if ( ! V_15 )
return NULL ;
V_26 = F_42 ( V_20 , V_15 , V_36 , V_39 ) ;
F_40 ( & V_15 -> V_11 . V_20 ) ;
return V_26 ? NULL : V_15 ;
}
bool F_43 ( struct V_1 * V_25 )
{
struct V_1 * V_41 ;
int V_42 , V_43 ;
const char * V_44 ;
V_41 = F_44 ( V_25 , L_13 ) ;
if ( V_41 ) {
F_13 ( V_41 ) ;
return true ;
}
V_43 = F_45 ( V_25 , L_14 , & V_44 ) ;
if ( V_43 == 0 && strcmp ( V_44 , L_15 ) != 0 )
return true ;
if ( F_46 ( V_25 , L_13 , & V_42 ) &&
V_42 == ( 5 * sizeof( V_45 ) ) )
return true ;
return false ;
}
int F_47 ( struct V_1 * V_25 )
{
struct V_46 V_47 = {} ;
struct V_1 * V_48 ;
const V_45 * V_49 ;
int V_50 ;
int V_42 , V_43 ;
struct V_14 * V_15 ;
const char * V_44 ;
V_43 = F_45 ( V_25 , L_14 , & V_44 ) ;
if ( V_43 == 0 ) {
if ( strcmp ( V_44 , L_16 ) == 0 ) {
V_15 = F_48 ( V_51 , & V_47 , - 1 , V_25 ) ;
return F_49 ( V_15 ) ;
}
}
V_48 = F_44 ( V_25 , L_13 ) ;
if ( V_48 ) {
V_47 . V_52 = 1 ;
V_47 . V_53 = F_9 ( V_48 ,
L_17 ) ;
if ( F_21 ( V_48 , L_18 , & V_47 . V_54 ) )
return - V_9 ;
V_47 . V_55 = F_9 ( V_48 , L_19 ) ;
V_47 . V_56 = F_9 ( V_48 ,
L_20 ) ;
V_50 = F_50 ( V_48 ,
L_21 , 0 , NULL ) ;
F_13 ( V_48 ) ;
if ( V_50 == - V_57 )
return - V_57 ;
V_15 = F_48 ( V_51 , & V_47 , V_50 , V_25 ) ;
return F_49 ( V_15 ) ;
}
V_49 = F_46 ( V_25 , L_13 , & V_42 ) ;
if ( V_49 && V_42 == ( 5 * sizeof( V_45 ) ) ) {
V_47 . V_52 = 1 ;
V_47 . V_53 = F_51 ( V_49 [ 1 ] ) ;
V_47 . V_54 = F_51 ( V_49 [ 2 ] ) ;
V_47 . V_55 = F_51 ( V_49 [ 3 ] ) ;
V_47 . V_56 = F_51 ( V_49 [ 4 ] ) ;
V_15 = F_48 ( V_51 , & V_47 , - 1 , V_25 ) ;
return F_49 ( V_15 ) ;
}
return - V_58 ;
}
