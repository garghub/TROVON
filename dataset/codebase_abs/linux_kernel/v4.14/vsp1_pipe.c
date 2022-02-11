const struct V_1 * F_1 ( struct V_2 * V_3 ,
T_1 V_4 )
{
unsigned int V_5 ;
if ( V_3 -> V_6 -> V_7 != 2 ) {
switch ( V_4 ) {
case V_8 :
case V_9 :
case V_10 :
return NULL ;
}
}
for ( V_5 = 0 ; V_5 < F_2 ( V_11 ) ; ++ V_5 ) {
const struct V_1 * V_6 = & V_11 [ V_5 ] ;
if ( V_6 -> V_4 == V_4 )
return V_6 ;
}
return NULL ;
}
void F_3 ( struct V_12 * V_13 )
{
unsigned int V_5 ;
if ( V_13 -> V_14 ) {
struct V_15 * V_14 = F_4 ( & V_13 -> V_14 -> V_16 ) ;
for ( V_5 = 0 ; V_5 < F_2 ( V_14 -> V_17 ) ; ++ V_5 )
V_14 -> V_17 [ V_5 ] . V_18 = NULL ;
}
for ( V_5 = 0 ; V_5 < F_2 ( V_13 -> V_17 ) ; ++ V_5 ) {
if ( V_13 -> V_17 [ V_5 ] ) {
V_13 -> V_17 [ V_5 ] -> V_13 = NULL ;
V_13 -> V_17 [ V_5 ] = NULL ;
}
}
if ( V_13 -> V_19 ) {
V_13 -> V_19 -> V_13 = NULL ;
V_13 -> V_19 = NULL ;
}
if ( V_13 -> V_20 ) {
struct V_21 * V_20 = F_5 ( & V_13 -> V_20 -> V_16 ) ;
V_20 -> V_22 . V_13 = NULL ;
}
if ( V_13 -> V_23 ) {
struct V_24 * V_23 = F_6 ( & V_13 -> V_23 -> V_16 ) ;
V_23 -> V_22 . V_13 = NULL ;
}
F_7 ( & V_13 -> V_25 ) ;
V_13 -> V_26 = V_27 ;
V_13 -> V_28 = 0 ;
V_13 -> V_29 = 0 ;
V_13 -> V_14 = NULL ;
V_13 -> V_20 = NULL ;
V_13 -> V_23 = NULL ;
V_13 -> V_30 = NULL ;
V_13 -> V_31 = NULL ;
}
void F_8 ( struct V_12 * V_13 )
{
F_9 ( & V_13 -> V_32 ) ;
F_10 ( & V_13 -> V_33 ) ;
F_11 ( & V_13 -> V_34 ) ;
F_12 ( & V_13 -> V_35 ) ;
F_7 ( & V_13 -> V_25 ) ;
V_13 -> V_26 = V_27 ;
}
void F_13 ( struct V_12 * V_13 )
{
struct V_2 * V_3 = V_13 -> V_19 -> V_36 . V_3 ;
if ( V_13 -> V_26 == V_27 ) {
F_14 ( V_3 , F_15 ( V_13 -> V_19 -> V_36 . V_37 ) ,
V_38 ) ;
V_13 -> V_26 = V_39 ;
}
V_13 -> V_28 = 0 ;
}
bool F_16 ( struct V_12 * V_13 )
{
unsigned long V_40 ;
bool V_41 ;
F_17 ( & V_13 -> V_33 , V_40 ) ;
V_41 = V_13 -> V_26 == V_27 ;
F_18 ( & V_13 -> V_33 , V_40 ) ;
return V_41 ;
}
int F_19 ( struct V_12 * V_13 )
{
struct V_2 * V_3 = V_13 -> V_19 -> V_36 . V_3 ;
struct V_42 * V_36 ;
unsigned long V_40 ;
int V_43 ;
if ( V_13 -> V_30 ) {
V_43 = F_20 ( V_3 , V_13 -> V_19 -> V_36 . V_37 ) ;
if ( V_43 == 0 ) {
F_17 ( & V_13 -> V_33 , V_40 ) ;
V_13 -> V_26 = V_27 ;
F_18 ( & V_13 -> V_33 , V_40 ) ;
}
} else {
F_17 ( & V_13 -> V_33 , V_40 ) ;
if ( V_13 -> V_26 == V_39 )
V_13 -> V_26 = V_44 ;
F_18 ( & V_13 -> V_33 , V_40 ) ;
V_43 = F_21 ( V_13 -> V_34 , F_16 ( V_13 ) ,
F_22 ( 500 ) ) ;
V_43 = V_43 == 0 ? - V_45 : 0 ;
}
F_23 (entity, &pipe->entities, list_pipe) {
if ( V_36 -> V_46 && V_36 -> V_46 -> V_47 )
F_14 ( V_3 , V_36 -> V_46 -> V_47 ,
V_48 ) ;
}
if ( V_13 -> V_20 )
F_14 ( V_3 , V_49 ,
( 7 << V_50 ) |
( V_48 << V_51 ) ) ;
if ( V_13 -> V_23 )
F_14 ( V_3 , V_52 ,
( 7 << V_50 ) |
( V_48 << V_51 ) ) ;
F_24 ( & V_13 -> V_19 -> V_36 . V_16 , V_53 , V_54 , 0 ) ;
return V_43 ;
}
bool F_25 ( struct V_12 * V_13 )
{
unsigned int V_55 ;
V_55 = ( ( 1 << V_13 -> V_29 ) - 1 ) << 1 ;
if ( ! V_13 -> V_30 )
V_55 |= 1 << 0 ;
return V_13 -> V_28 == V_55 ;
}
void F_26 ( struct V_12 * V_13 )
{
bool V_56 ;
if ( V_13 == NULL )
return;
V_56 = F_27 ( V_13 -> V_19 -> V_57 ) ;
if ( V_13 -> V_20 )
F_28 ( V_13 -> V_20 ) ;
if ( V_13 -> V_23 )
F_29 ( V_13 -> V_23 ) ;
if ( V_13 -> V_58 )
V_13 -> V_58 ( V_13 , V_56 ) ;
V_13 -> V_59 ++ ;
}
void F_30 ( struct V_12 * V_13 ,
struct V_60 * V_61 , unsigned int V_62 )
{
if ( ! V_13 -> V_31 )
return;
if ( V_13 -> V_63 -> type == V_64 ||
V_13 -> V_63 -> type == V_65 )
V_62 = 255 ;
F_31 ( V_13 -> V_31 , V_61 , V_62 ) ;
}
void F_32 ( struct V_12 * V_13 ,
struct V_66 * V_67 ,
unsigned int V_37 ,
struct V_68 * V_69 )
{
struct V_42 * V_36 ;
F_33 (entity, &pipe->entities, list_pipe) {
if ( V_36 -> V_70 -> V_67 )
V_36 -> V_70 -> V_67 ( V_36 , V_13 , V_67 , V_37 ,
V_69 ) ;
}
}
void F_34 ( struct V_2 * V_3 )
{
unsigned long V_40 ;
unsigned int V_5 ;
int V_43 ;
for ( V_5 = 0 ; V_5 < V_3 -> V_6 -> V_71 ; ++ V_5 ) {
struct V_72 * V_73 = V_3 -> V_73 [ V_5 ] ;
struct V_12 * V_13 ;
if ( V_73 == NULL )
continue;
V_13 = V_73 -> V_13 ;
if ( V_13 == NULL )
continue;
F_17 ( & V_13 -> V_33 , V_40 ) ;
if ( V_13 -> V_26 == V_39 )
V_13 -> V_26 = V_44 ;
F_18 ( & V_13 -> V_33 , V_40 ) ;
}
for ( V_5 = 0 ; V_5 < V_3 -> V_6 -> V_71 ; ++ V_5 ) {
struct V_72 * V_73 = V_3 -> V_73 [ V_5 ] ;
struct V_12 * V_13 ;
if ( V_73 == NULL )
continue;
V_13 = V_73 -> V_13 ;
if ( V_13 == NULL )
continue;
V_43 = F_21 ( V_13 -> V_34 , F_16 ( V_13 ) ,
F_22 ( 500 ) ) ;
if ( V_43 == 0 )
F_35 ( V_3 -> V_74 , L_1 ,
V_73 -> V_36 . V_37 ) ;
}
}
void F_36 ( struct V_2 * V_3 )
{
unsigned long V_40 ;
unsigned int V_5 ;
for ( V_5 = 0 ; V_5 < V_3 -> V_6 -> V_71 ; ++ V_5 ) {
struct V_72 * V_73 = V_3 -> V_73 [ V_5 ] ;
struct V_12 * V_13 ;
if ( V_73 == NULL )
continue;
V_13 = V_73 -> V_13 ;
if ( V_13 == NULL )
continue;
F_17 ( & V_13 -> V_33 , V_40 ) ;
if ( F_25 ( V_13 ) )
F_13 ( V_13 ) ;
F_18 ( & V_13 -> V_33 , V_40 ) ;
}
}
