const struct V_1 * F_1 ( T_1 V_2 )
{
unsigned int V_3 ;
for ( V_3 = 0 ; V_3 < F_2 ( V_4 ) ; ++ V_3 ) {
const struct V_1 * V_5 = & V_4 [ V_3 ] ;
if ( V_5 -> V_2 == V_2 )
return V_5 ;
}
return NULL ;
}
void F_3 ( struct V_6 * V_7 )
{
unsigned int V_3 ;
if ( V_7 -> V_8 ) {
struct V_9 * V_8 = F_4 ( & V_7 -> V_8 -> V_10 ) ;
for ( V_3 = 0 ; V_3 < F_2 ( V_8 -> V_11 ) ; ++ V_3 )
V_8 -> V_11 [ V_3 ] . V_12 = NULL ;
}
for ( V_3 = 0 ; V_3 < F_2 ( V_7 -> V_11 ) ; ++ V_3 )
V_7 -> V_11 [ V_3 ] = NULL ;
F_5 ( & V_7 -> V_13 ) ;
V_7 -> V_14 = V_15 ;
V_7 -> V_16 = 0 ;
V_7 -> V_17 = 0 ;
V_7 -> V_18 = NULL ;
V_7 -> V_8 = NULL ;
V_7 -> V_19 = NULL ;
V_7 -> V_20 = NULL ;
}
void F_6 ( struct V_6 * V_7 )
{
F_7 ( & V_7 -> V_21 ) ;
F_8 ( & V_7 -> V_22 ) ;
F_9 ( & V_7 -> V_23 ) ;
F_5 ( & V_7 -> V_13 ) ;
V_7 -> V_14 = V_15 ;
}
void F_10 ( struct V_6 * V_7 )
{
struct V_24 * V_25 = V_7 -> V_18 -> V_26 . V_25 ;
if ( V_7 -> V_14 == V_15 ) {
F_11 ( V_25 , F_12 ( V_7 -> V_18 -> V_26 . V_27 ) ,
V_28 ) ;
V_7 -> V_14 = V_29 ;
}
V_7 -> V_16 = 0 ;
}
bool F_13 ( struct V_6 * V_7 )
{
unsigned long V_30 ;
bool V_31 ;
F_14 ( & V_7 -> V_22 , V_30 ) ;
V_31 = V_7 -> V_14 == V_15 ;
F_15 ( & V_7 -> V_22 , V_30 ) ;
return V_31 ;
}
int F_16 ( struct V_6 * V_7 )
{
struct V_32 * V_26 ;
unsigned long V_30 ;
int V_33 ;
if ( V_7 -> V_34 ) {
V_33 = F_17 ( V_7 -> V_18 -> V_26 . V_25 ,
V_7 -> V_18 -> V_26 . V_27 ) ;
if ( V_33 == 0 ) {
F_14 ( & V_7 -> V_22 , V_30 ) ;
V_7 -> V_14 = V_15 ;
F_15 ( & V_7 -> V_22 , V_30 ) ;
}
} else {
F_14 ( & V_7 -> V_22 , V_30 ) ;
if ( V_7 -> V_14 == V_29 )
V_7 -> V_14 = V_35 ;
F_15 ( & V_7 -> V_22 , V_30 ) ;
V_33 = F_18 ( V_7 -> V_23 , F_13 ( V_7 ) ,
F_19 ( 500 ) ) ;
V_33 = V_33 == 0 ? - V_36 : 0 ;
}
F_20 (entity, &pipe->entities, list_pipe) {
if ( V_26 -> V_37 && V_26 -> V_37 -> V_38 )
F_11 ( V_26 -> V_25 , V_26 -> V_37 -> V_38 ,
V_39 ) ;
F_21 ( & V_26 -> V_10 , V_40 , V_41 , 0 ) ;
}
return V_33 ;
}
bool F_22 ( struct V_6 * V_7 )
{
unsigned int V_42 ;
V_42 = ( ( 1 << V_7 -> V_17 ) - 1 ) << 1 ;
if ( ! V_7 -> V_19 )
V_42 |= 1 << 0 ;
return V_7 -> V_16 == V_42 ;
}
void F_23 ( struct V_6 * V_7 )
{
if ( V_7 -> V_34 )
F_24 ( V_7 -> V_34 ) ;
}
void F_25 ( struct V_6 * V_7 )
{
enum V_43 V_14 ;
unsigned long V_30 ;
if ( V_7 == NULL )
return;
if ( V_7 -> V_34 )
F_26 ( V_7 -> V_34 ) ;
V_7 -> V_44 ( V_7 ) ;
F_14 ( & V_7 -> V_22 , V_30 ) ;
V_14 = V_7 -> V_14 ;
if ( ! V_7 -> V_34 )
V_7 -> V_14 = V_15 ;
if ( V_14 == V_35 ) {
F_27 ( & V_7 -> V_23 ) ;
goto V_45;
}
if ( F_22 ( V_7 ) )
F_10 ( V_7 ) ;
V_45:
F_15 ( & V_7 -> V_22 , V_30 ) ;
}
void F_28 ( struct V_6 * V_7 ,
struct V_32 * V_46 ,
unsigned int V_47 )
{
struct V_32 * V_26 ;
struct V_48 * V_49 ;
V_49 = F_29 ( & V_46 -> V_50 [ V_51 ] ) ;
while ( V_49 ) {
if ( ! F_30 ( V_49 -> V_26 ) )
break;
V_26 = F_31 ( F_32 ( V_49 -> V_26 ) ) ;
if ( V_26 -> type == V_52 )
V_47 = 255 ;
if ( V_26 -> type == V_53 ) {
struct V_54 * V_20 = F_33 ( & V_26 -> V_10 ) ;
F_34 ( V_20 , V_47 ) ;
break;
}
V_49 = & V_26 -> V_50 [ V_26 -> V_55 ] ;
V_49 = F_29 ( V_49 ) ;
}
}
void F_35 ( struct V_24 * V_25 )
{
unsigned long V_30 ;
unsigned int V_3 ;
int V_33 ;
for ( V_3 = 0 ; V_3 < V_25 -> V_5 -> V_56 ; ++ V_3 ) {
struct V_57 * V_58 = V_25 -> V_58 [ V_3 ] ;
struct V_6 * V_7 ;
if ( V_58 == NULL )
continue;
V_7 = F_36 ( & V_58 -> V_26 . V_10 . V_26 ) ;
if ( V_7 == NULL )
continue;
F_14 ( & V_7 -> V_22 , V_30 ) ;
if ( V_7 -> V_14 == V_29 )
V_7 -> V_14 = V_35 ;
F_15 ( & V_7 -> V_22 , V_30 ) ;
}
for ( V_3 = 0 ; V_3 < V_25 -> V_5 -> V_56 ; ++ V_3 ) {
struct V_57 * V_58 = V_25 -> V_58 [ V_3 ] ;
struct V_6 * V_7 ;
if ( V_58 == NULL )
continue;
V_7 = F_36 ( & V_58 -> V_26 . V_10 . V_26 ) ;
if ( V_7 == NULL )
continue;
V_33 = F_18 ( V_7 -> V_23 , F_13 ( V_7 ) ,
F_19 ( 500 ) ) ;
if ( V_33 == 0 )
F_37 ( V_25 -> V_59 , L_1 ,
V_58 -> V_26 . V_27 ) ;
}
}
void F_38 ( struct V_24 * V_25 )
{
unsigned int V_3 ;
for ( V_3 = 0 ; V_3 < V_25 -> V_5 -> V_56 ; ++ V_3 ) {
struct V_57 * V_58 = V_25 -> V_58 [ V_3 ] ;
struct V_6 * V_7 ;
if ( V_58 == NULL )
continue;
V_7 = F_36 ( & V_58 -> V_26 . V_10 . V_26 ) ;
if ( V_7 == NULL )
continue;
if ( F_22 ( V_7 ) )
F_10 ( V_7 ) ;
}
}
