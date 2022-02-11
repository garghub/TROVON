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
static int F_3 ( struct V_10 * V_11 ,
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
return F_8 ( V_15 ) ;
V_17 = F_9 ( V_12 , 0 ) ;
if ( V_17 == - V_18 ) {
F_10 ( V_15 ) ;
return V_17 ;
}
if ( V_17 > 0 ) {
V_15 -> V_19 = V_17 ;
V_11 -> V_19 [ V_13 ] = V_17 ;
} else {
V_15 -> V_19 = V_11 -> V_19 [ V_13 ] ;
}
if ( F_11 ( V_12 , L_4 ) )
V_11 -> V_20 |= 1 << V_13 ;
F_12 ( V_12 ) ;
V_15 -> V_11 . V_21 . V_22 = V_12 ;
V_17 = F_13 ( V_15 ) ;
if ( V_17 ) {
F_10 ( V_15 ) ;
F_14 ( V_12 ) ;
return V_17 ;
}
F_15 ( & V_11 -> V_21 , L_5 ,
V_12 -> V_23 , V_13 ) ;
return 0 ;
}
static int F_16 ( struct V_10 * V_11 ,
struct V_1 * V_12 , T_1 V_13 )
{
struct V_24 * V_25 ;
int V_17 ;
V_25 = F_17 ( V_11 , V_13 ) ;
if ( F_7 ( V_25 ) )
return F_8 ( V_25 ) ;
F_12 ( V_12 ) ;
V_25 -> V_21 . V_22 = V_12 ;
V_17 = F_18 ( V_25 ) ;
if ( V_17 ) {
F_19 ( V_25 ) ;
F_14 ( V_12 ) ;
return V_17 ;
}
F_15 ( & V_11 -> V_21 , L_6 ,
V_12 -> V_23 , V_13 ) ;
return 0 ;
}
static bool F_20 ( struct V_1 * V_12 )
{
T_1 V_3 ;
if ( F_1 ( V_12 , & V_3 ) != - V_9 )
return true ;
if ( F_4 ( V_12 , L_3 ) )
return true ;
if ( F_4 ( V_12 , L_7 ) )
return true ;
if ( F_21 ( V_26 , V_12 ) ) {
F_22 ( V_27
L_8 ,
V_12 ) ;
return true ;
}
if ( ! F_23 ( V_12 , L_1 , NULL ) )
return true ;
return false ;
}
int F_24 ( struct V_10 * V_11 , struct V_1 * V_28 )
{
struct V_1 * V_12 ;
bool V_29 = false ;
int V_13 , V_17 ;
if ( ! F_25 ( V_28 ) )
return - V_30 ;
V_11 -> V_31 = ~ 0 ;
V_11 -> V_21 . V_22 = V_28 ;
V_11 -> V_32 = V_33 ;
F_26 ( V_28 , L_9 , & V_11 -> V_32 ) ;
V_17 = F_27 ( V_11 ) ;
if ( V_17 )
return V_17 ;
F_28 (np, child) {
V_13 = F_29 ( & V_11 -> V_21 , V_12 ) ;
if ( V_13 < 0 ) {
V_29 = true ;
continue;
}
if ( F_20 ( V_12 ) )
V_17 = F_3 ( V_11 , V_12 , V_13 ) ;
else
V_17 = F_16 ( V_11 , V_12 , V_13 ) ;
if ( V_17 )
goto V_34;
}
if ( ! V_29 )
return 0 ;
F_28 (np, child) {
if ( F_23 ( V_12 , L_10 , NULL ) )
continue;
for ( V_13 = 0 ; V_13 < V_35 ; V_13 ++ ) {
if ( F_30 ( V_11 , V_13 ) )
continue;
F_31 ( & V_11 -> V_21 , L_11 ,
V_12 -> V_23 , V_13 ) ;
if ( F_20 ( V_12 ) ) {
V_17 = F_3 ( V_11 , V_12 , V_13 ) ;
if ( V_17 )
goto V_34;
}
}
}
return 0 ;
V_34:
F_32 ( V_11 ) ;
return V_17 ;
}
static int F_33 ( struct V_2 * V_21 , void * V_36 )
{
return V_21 -> V_22 == V_36 ;
}
struct V_14 * F_34 ( struct V_1 * V_36 )
{
struct V_2 * V_37 ;
struct V_24 * V_25 ;
if ( ! V_36 )
return NULL ;
V_37 = F_35 ( & V_38 , NULL , V_36 , F_33 ) ;
if ( V_37 ) {
V_25 = F_36 ( V_37 ) ;
if ( V_25 -> V_39 & V_40 )
return F_37 ( V_37 ) ;
F_38 ( V_37 ) ;
}
return NULL ;
}
struct V_14 * F_39 ( struct V_41 * V_21 ,
struct V_1 * V_36 ,
void (* F_40)( struct V_41 * ) , T_1 V_39 ,
T_2 V_42 )
{
struct V_14 * V_15 = F_34 ( V_36 ) ;
int V_43 ;
if ( ! V_15 )
return NULL ;
V_15 -> V_44 = V_39 ;
V_43 = F_41 ( V_21 , V_15 , F_40 , V_42 ) ;
F_38 ( & V_15 -> V_11 . V_21 ) ;
return V_43 ? NULL : V_15 ;
}
struct V_14 * F_42 ( struct V_41 * V_21 ,
struct V_1 * V_28 ,
void (* F_40)( struct V_41 * ) )
{
T_2 V_42 ;
struct V_1 * V_36 ;
struct V_14 * V_15 ;
V_42 = F_43 ( V_28 ) ;
if ( V_42 < 0 )
return NULL ;
V_36 = F_44 ( V_28 , L_12 , 0 ) ;
if ( ! V_36 )
return NULL ;
V_15 = F_39 ( V_21 , V_36 , F_40 , 0 , V_42 ) ;
F_14 ( V_36 ) ;
return V_15 ;
}
struct V_14 * F_45 ( struct V_41 * V_21 ,
struct V_1 * V_36 , T_1 V_39 ,
T_2 V_42 )
{
struct V_14 * V_15 = F_34 ( V_36 ) ;
int V_43 ;
if ( ! V_15 )
return NULL ;
V_43 = F_46 ( V_21 , V_15 , V_39 , V_42 ) ;
F_38 ( & V_15 -> V_11 . V_21 ) ;
return V_43 ? NULL : V_15 ;
}
bool F_47 ( struct V_1 * V_28 )
{
struct V_1 * V_45 ;
int V_46 , V_47 ;
const char * V_48 ;
V_45 = F_48 ( V_28 , L_13 ) ;
if ( V_45 ) {
F_14 ( V_45 ) ;
return true ;
}
V_47 = F_49 ( V_28 , L_14 , & V_48 ) ;
if ( V_47 == 0 && strcmp ( V_48 , L_15 ) != 0 )
return true ;
if ( F_50 ( V_28 , L_13 , & V_46 ) &&
V_46 == ( 5 * sizeof( V_49 ) ) )
return true ;
return false ;
}
int F_51 ( struct V_1 * V_28 )
{
struct V_50 V_51 = {} ;
struct V_1 * V_52 ;
T_1 V_53 [ 5 ] ;
const char * V_48 ;
int V_54 = - 1 ;
if ( F_49 ( V_28 , L_14 , & V_48 ) == 0 &&
strcmp ( V_48 , L_16 ) == 0 ) {
goto V_55;
}
V_52 = F_48 ( V_28 , L_13 ) ;
if ( V_52 ) {
V_51 . V_56 = 1 ;
V_51 . V_57 = F_11 ( V_52 ,
L_17 ) ;
if ( F_26 ( V_52 , L_18 ,
& V_51 . V_58 ) ) {
F_14 ( V_52 ) ;
return - V_9 ;
}
V_51 . V_59 = F_11 ( V_52 , L_19 ) ;
V_51 . V_60 = F_11 ( V_52 ,
L_20 ) ;
V_54 = F_52 ( V_52 ,
L_21 , 0 , NULL ) ;
F_14 ( V_52 ) ;
if ( V_54 == - V_18 )
return - V_18 ;
goto V_55;
}
if ( F_53 ( V_28 , L_13 , V_53 ,
F_54 ( V_53 ) ) == 0 ) {
V_51 . V_56 = 1 ;
V_51 . V_57 = V_53 [ 1 ] ;
V_51 . V_58 = V_53 [ 2 ] ;
V_51 . V_59 = V_53 [ 3 ] ;
V_51 . V_60 = V_53 [ 4 ] ;
goto V_55;
}
return - V_30 ;
V_55:
return F_55 ( F_56 ( V_61 , & V_51 , V_54 ,
V_28 ) ) ;
}
void F_57 ( struct V_1 * V_28 )
{
struct V_14 * V_62 ;
V_62 = F_34 ( V_28 ) ;
if ( ! V_62 )
return;
F_58 ( V_62 ) ;
F_38 ( & V_62 -> V_11 . V_21 ) ;
F_10 ( V_62 ) ;
}
