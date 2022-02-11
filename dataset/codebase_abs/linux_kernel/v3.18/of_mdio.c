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
if ( ! V_15 || F_7 ( V_15 ) )
return 1 ;
V_17 = F_8 ( V_12 , 0 ) ;
if ( V_17 > 0 ) {
V_15 -> V_18 = V_17 ;
if ( V_11 -> V_18 )
V_11 -> V_18 [ V_13 ] = V_17 ;
} else {
if ( V_11 -> V_18 )
V_15 -> V_18 = V_11 -> V_18 [ V_13 ] ;
}
F_9 ( V_12 ) ;
V_15 -> V_19 . V_20 = V_12 ;
V_17 = F_10 ( V_15 ) ;
if ( V_17 ) {
F_11 ( V_15 ) ;
F_12 ( V_12 ) ;
return 1 ;
}
F_13 ( & V_11 -> V_19 , L_4 ,
V_12 -> V_21 , V_13 ) ;
return 0 ;
}
static int F_14 ( struct V_2 * V_19 , const struct V_1 * V_22 )
{
T_1 V_13 ;
int V_23 ;
V_23 = F_15 ( V_22 , L_5 , & V_13 ) ;
if ( V_23 < 0 ) {
F_16 ( V_19 , L_6 , V_22 -> V_24 ) ;
return V_23 ;
}
if ( V_13 >= V_25 ) {
F_16 ( V_19 , L_7 ,
V_22 -> V_24 , V_13 ) ;
return - V_9 ;
}
return V_13 ;
}
int F_17 ( struct V_10 * V_11 , struct V_1 * V_22 )
{
struct V_1 * V_12 ;
const T_2 * V_26 ;
bool V_27 = false ;
int V_13 , V_17 , V_28 ;
V_11 -> V_29 = ~ 0 ;
if ( V_11 -> V_18 )
for ( V_28 = 0 ; V_28 < V_25 ; V_28 ++ )
V_11 -> V_18 [ V_28 ] = V_30 ;
V_11 -> V_19 . V_20 = V_22 ;
V_17 = F_18 ( V_11 ) ;
if ( V_17 )
return V_17 ;
F_19 (np, child) {
V_13 = F_14 ( & V_11 -> V_19 , V_12 ) ;
if ( V_13 < 0 ) {
V_27 = true ;
continue;
}
V_17 = F_3 ( V_11 , V_12 , V_13 ) ;
if ( V_17 )
continue;
}
if ( ! V_27 )
return 0 ;
F_19 (np, child) {
V_26 = F_20 ( V_12 , L_5 , NULL ) ;
if ( V_26 )
continue;
for ( V_13 = 0 ; V_13 < V_25 ; V_13 ++ ) {
if ( V_11 -> V_31 [ V_13 ] )
continue;
F_21 ( & V_11 -> V_19 , L_8 ,
V_12 -> V_21 , V_13 ) ;
V_17 = F_3 ( V_11 , V_12 , V_13 ) ;
if ( V_17 )
continue;
}
}
return 0 ;
}
static int F_22 ( struct V_2 * V_19 , void * V_32 )
{
return V_19 -> V_20 == V_32 ;
}
struct V_14 * F_23 ( struct V_1 * V_32 )
{
struct V_2 * V_33 ;
if ( ! V_32 )
return NULL ;
V_33 = F_24 ( & V_34 , NULL , V_32 , F_22 ) ;
return V_33 ? F_25 ( V_33 ) : NULL ;
}
struct V_14 * F_26 ( struct V_35 * V_19 ,
struct V_1 * V_32 ,
void (* F_27)( struct V_35 * ) , T_1 V_36 ,
T_3 V_37 )
{
struct V_14 * V_15 = F_23 ( V_32 ) ;
if ( ! V_15 )
return NULL ;
V_15 -> V_38 = V_36 ;
return F_28 ( V_19 , V_15 , F_27 , V_37 ) ? NULL : V_15 ;
}
struct V_14 * F_29 ( struct V_35 * V_19 ,
struct V_1 * V_32 , T_1 V_36 ,
T_3 V_37 )
{
struct V_14 * V_15 = F_23 ( V_32 ) ;
if ( ! V_15 )
return NULL ;
return F_30 ( V_19 , V_15 , V_36 , V_37 ) ? NULL : V_15 ;
}
bool F_31 ( struct V_1 * V_22 )
{
struct V_1 * V_39 ;
int V_40 ;
V_39 = F_32 ( V_22 , L_9 ) ;
if ( V_39 ) {
F_12 ( V_39 ) ;
return true ;
}
if ( F_20 ( V_22 , L_9 , & V_40 ) &&
V_40 == ( 5 * sizeof( T_2 ) ) )
return true ;
return false ;
}
int F_33 ( struct V_1 * V_22 )
{
struct V_41 V_42 = {} ;
struct V_1 * V_43 ;
const T_2 * V_44 ;
int V_40 ;
struct V_14 * V_15 ;
V_43 = F_32 ( V_22 , L_9 ) ;
if ( V_43 ) {
V_42 . V_45 = 1 ;
V_42 . V_46 = F_34 ( V_43 ,
L_10 ) ;
if ( F_15 ( V_43 , L_11 , & V_42 . V_47 ) )
return - V_9 ;
V_42 . V_48 = F_34 ( V_43 , L_12 ) ;
V_42 . V_49 = F_34 ( V_43 ,
L_13 ) ;
F_12 ( V_43 ) ;
V_15 = F_35 ( V_30 , & V_42 , V_22 ) ;
return F_7 ( V_15 ) ? F_36 ( V_15 ) : 0 ;
}
V_44 = F_20 ( V_22 , L_9 , & V_40 ) ;
if ( V_44 && V_40 == ( 5 * sizeof( T_2 ) ) ) {
V_42 . V_45 = 1 ;
V_42 . V_46 = F_37 ( V_44 [ 1 ] ) ;
V_42 . V_47 = F_37 ( V_44 [ 2 ] ) ;
V_42 . V_48 = F_37 ( V_44 [ 3 ] ) ;
V_42 . V_49 = F_37 ( V_44 [ 4 ] ) ;
V_15 = F_35 ( V_30 , & V_42 , V_22 ) ;
return F_7 ( V_15 ) ? F_36 ( V_15 ) : 0 ;
}
return - V_50 ;
}
