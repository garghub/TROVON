static T_1
F_1 ( struct V_1 * V_2 , int type ,
struct V_3 * * V_4 )
{
struct V_3 * V_5 ;
int V_6 ;
T_2 V_7 = sizeof( * V_5 ) ;
int V_8 ;
V_5 = F_2 ( V_7 , V_9 ) ;
if ( ! V_5 ) {
F_3 ( L_1 ) ;
return 0 ;
}
V_5 -> type = type ;
V_5 -> V_10 = 0 ;
V_5 -> V_11 = 0 ;
F_4 ( & V_5 -> V_12 ) ;
F_5 ( V_9 ) ;
F_6 ( & V_2 -> V_13 ) ;
V_8 = F_7 ( & V_2 -> V_14 , V_5 , 1 , 0 , V_15 ) ;
F_8 ( & V_2 -> V_13 ) ;
F_9 () ;
V_6 = V_8 ;
if ( V_8 < 0 )
goto V_16;
* V_4 = V_5 ;
F_10 ( V_2 , L_2 , V_6 ) ;
V_5 -> V_17 = V_6 ;
V_16:
return V_6 ;
}
void
F_11 ( struct V_1 * V_2 ,
struct V_3 * V_5 )
{
struct V_18 * V_19 , * V_20 ;
F_10 ( V_2 , L_3 , V_5 -> V_17 ,
V_5 -> type ) ;
if ( V_5 -> V_11 )
F_12 ( V_2 , V_5 -> V_11 ) ;
F_13 (entry, tmp, &release->bos, tv.head) {
struct V_21 * V_22 = F_14 ( V_19 -> V_23 . V_22 ) ;
F_10 ( V_2 , L_4 ,
F_15 ( & V_19 -> V_23 . V_22 -> V_24 )
- V_25 ) ;
F_16 ( & V_22 -> V_26 , V_5 -> V_17 ) ;
F_17 ( & V_22 ) ;
}
F_6 ( & V_2 -> V_13 ) ;
F_18 ( & V_2 -> V_14 , V_5 -> V_17 ) ;
F_8 ( & V_2 -> V_13 ) ;
F_19 ( V_5 ) ;
}
static int F_20 ( struct V_1 * V_2 ,
struct V_21 * * V_22 )
{
int V_4 ;
V_4 = F_21 ( V_2 , V_27 , false , true ,
V_28 , NULL ,
V_22 ) ;
return V_4 ;
}
int F_22 ( struct V_3 * V_5 , struct V_21 * V_22 )
{
struct V_18 * V_19 ;
F_23 (entry, &release->bos, tv.head) {
if ( V_19 -> V_23 . V_22 == & V_22 -> V_29 )
return 0 ;
}
V_19 = F_2 ( sizeof( struct V_18 ) , V_9 ) ;
if ( ! V_19 )
return - V_30 ;
F_24 ( V_22 ) ;
V_19 -> V_23 . V_22 = & V_22 -> V_29 ;
F_25 ( & V_19 -> V_23 . V_31 , & V_5 -> V_12 ) ;
return 0 ;
}
static int F_26 ( struct V_21 * V_22 )
{
int V_4 ;
if ( ! V_22 -> V_32 ) {
F_27 ( V_22 , V_22 -> type , false ) ;
V_4 = F_28 ( & V_22 -> V_29 , & V_22 -> V_33 ,
true , false ) ;
if ( V_4 )
return V_4 ;
}
V_4 = F_29 ( V_22 -> V_34 . V_35 -> V_36 , V_22 ) ;
if ( V_4 )
return V_4 ;
return 0 ;
}
int F_30 ( struct V_3 * V_5 , bool V_37 )
{
int V_4 ;
struct V_18 * V_19 ;
if ( F_31 ( & V_5 -> V_12 ) )
return 0 ;
V_4 = F_32 ( & V_5 -> V_38 , & V_5 -> V_12 ) ;
if ( V_4 )
return V_4 ;
F_23 (entry, &release->bos, tv.head) {
struct V_21 * V_22 = F_14 ( V_19 -> V_23 . V_22 ) ;
V_4 = F_26 ( V_22 ) ;
if ( V_4 ) {
F_33 ( & V_5 -> V_38 , & V_5 -> V_12 ) ;
return V_4 ;
}
}
return 0 ;
}
void F_34 ( struct V_3 * V_5 )
{
if ( F_31 ( & V_5 -> V_12 ) )
return;
F_33 ( & V_5 -> V_38 , & V_5 -> V_12 ) ;
}
int F_35 ( struct V_1 * V_2 ,
enum V_39 V_40 ,
struct V_3 * V_41 ,
struct V_3 * * V_5 )
{
if ( V_40 == V_42 && V_41 ) {
int V_8 ;
struct V_18 * V_19 = F_36 ( & V_41 -> V_12 , struct V_18 , V_23 . V_31 ) ;
struct V_21 * V_22 ;
union V_43 * V_44 ;
V_8 = F_1 ( V_2 , V_45 , V_5 ) ;
V_22 = F_24 ( F_14 ( V_19 -> V_23 . V_22 ) ) ;
( * V_5 ) -> V_10 = V_41 -> V_10 + 64 ;
F_22 ( * V_5 , V_22 ) ;
V_44 = F_37 ( V_2 , * V_5 ) ;
V_44 -> V_17 = V_8 ;
F_38 ( V_2 , * V_5 , V_44 ) ;
F_17 ( & V_22 ) ;
return 0 ;
}
return F_39 ( V_2 , sizeof( struct V_46 ) ,
V_45 , V_5 , NULL ) ;
}
int F_39 ( struct V_1 * V_2 , unsigned long V_7 ,
int type , struct V_3 * * V_5 ,
struct V_21 * * V_47 )
{
struct V_21 * V_22 ;
int V_8 ;
int V_4 = 0 ;
union V_43 * V_44 ;
int V_48 ;
if ( type == V_49 )
V_48 = 0 ;
else if ( type == V_45 )
V_48 = 1 ;
else if ( type == V_50 )
V_48 = 2 ;
else {
F_3 ( L_5 , type ) ;
return - V_51 ;
}
V_8 = F_1 ( V_2 , type , V_5 ) ;
F_40 ( & V_2 -> V_52 ) ;
if ( V_2 -> V_53 [ V_48 ] + 1 >= V_54 [ V_48 ] ) {
F_17 ( & V_2 -> V_55 [ V_48 ] ) ;
V_2 -> V_53 [ V_48 ] = 0 ;
V_2 -> V_55 [ V_48 ] = NULL ;
}
if ( ! V_2 -> V_55 [ V_48 ] ) {
V_4 = F_20 ( V_2 , & V_2 -> V_55 [ V_48 ] ) ;
if ( V_4 ) {
F_41 ( & V_2 -> V_52 ) ;
return V_4 ;
}
}
V_22 = F_24 ( V_2 -> V_55 [ V_48 ] ) ;
( * V_5 ) -> V_10 = V_2 -> V_53 [ V_48 ] * V_56 [ V_48 ] ;
V_2 -> V_53 [ V_48 ] ++ ;
if ( V_47 )
* V_47 = V_22 ;
F_41 ( & V_2 -> V_52 ) ;
F_22 ( * V_5 , V_22 ) ;
V_44 = F_37 ( V_2 , * V_5 ) ;
V_44 -> V_17 = V_8 ;
F_38 ( V_2 , * V_5 , V_44 ) ;
F_17 ( & V_22 ) ;
return V_4 ;
}
struct V_3 * F_42 ( struct V_1 * V_2 ,
T_1 V_17 )
{
struct V_3 * V_5 ;
F_6 ( & V_2 -> V_13 ) ;
V_5 = F_43 ( & V_2 -> V_14 , V_17 ) ;
F_8 ( & V_2 -> V_13 ) ;
if ( ! V_5 ) {
F_3 ( L_6 ) ;
return NULL ;
}
return V_5 ;
}
union V_43 * F_37 ( struct V_1 * V_2 ,
struct V_3 * V_5 )
{
void * V_57 ;
union V_43 * V_44 ;
struct V_18 * V_19 = F_36 ( & V_5 -> V_12 , struct V_18 , V_23 . V_31 ) ;
struct V_21 * V_22 = F_14 ( V_19 -> V_23 . V_22 ) ;
V_57 = F_44 ( V_2 , V_22 , V_5 -> V_10 & V_27 ) ;
if ( ! V_57 )
return NULL ;
V_44 = V_57 + ( V_5 -> V_10 & ~ V_27 ) ;
return V_44 ;
}
void F_38 ( struct V_1 * V_2 ,
struct V_3 * V_5 ,
union V_43 * V_44 )
{
struct V_18 * V_19 = F_36 ( & V_5 -> V_12 , struct V_18 , V_23 . V_31 ) ;
struct V_21 * V_22 = F_14 ( V_19 -> V_23 . V_22 ) ;
void * V_57 ;
V_57 = ( ( void * ) V_44 ) - ( V_5 -> V_10 & ~ V_27 ) ;
F_45 ( V_2 , V_22 , V_57 ) ;
}
void F_46 ( struct V_3 * V_5 )
{
struct V_58 * V_19 ;
struct V_59 * V_22 ;
struct V_60 * V_61 ;
struct V_62 * V_63 ;
struct V_64 * V_65 ;
struct V_21 * V_66 ;
if ( F_31 ( & V_5 -> V_12 ) )
return;
V_22 = F_36 ( & V_5 -> V_12 , struct V_58 , V_31 ) -> V_22 ;
V_63 = V_22 -> V_63 ;
V_65 = V_63 -> V_65 ;
V_61 = V_22 -> V_61 ;
F_6 ( & V_61 -> V_67 ) ;
F_6 ( & V_63 -> V_68 ) ;
F_23 (entry, &release->bos, head) {
V_22 = V_19 -> V_22 ;
V_66 = F_14 ( V_22 ) ;
if ( ! V_19 -> V_22 -> V_69 )
V_19 -> V_22 -> V_69 = & V_66 -> V_26 ;
F_47 ( & V_66 -> V_26 , V_5 -> V_17 ) ;
F_48 ( V_22 ) ;
F_49 ( & V_22 -> V_70 -> V_71 ) ;
V_19 -> V_72 = false ;
}
F_8 ( & V_63 -> V_68 ) ;
F_8 ( & V_61 -> V_67 ) ;
F_50 ( & V_5 -> V_38 ) ;
}
