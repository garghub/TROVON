static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return V_3 -> V_4 ? V_3 -> V_4 -> V_5 : NULL ;
}
static int F_2 ( struct V_2 * V_3 )
{
unsigned long V_6 = F_3 ( 500 ) ;
struct V_1 * V_7 = V_3 -> V_8 ( V_3 ) ;
T_1 V_9 ;
int V_10 ;
V_10 = F_4 () ;
if ( V_10 )
return V_10 ;
if ( V_7 -> type == V_11 )
V_9 = V_12 ;
else if ( V_7 -> type == V_13 )
V_9 = V_14 ;
else
V_9 = F_5 ( V_3 -> V_15 ) ;
V_10 = F_6 ( V_9 , V_6 ) ;
F_7 () ;
return V_10 ;
}
int F_8 ( struct V_16 * V_17 )
{
int V_18 , V_10 ;
V_19 = F_9 () ;
V_20 = F_10 ( sizeof( struct V_2 ) * V_19 ,
V_21 ) ;
F_11 ( V_20 == NULL ) ;
for ( V_18 = 0 ; V_18 < V_19 ; ++ V_18 ) {
struct V_2 * V_3 = & V_20 [ V_18 ] ;
switch ( V_18 ) {
case 0 :
V_3 -> V_22 = L_1 ;
V_3 -> V_15 = V_23 ;
break;
case 1 :
V_3 -> V_22 = L_2 ;
V_3 -> V_15 = V_24 ;
break;
case 2 :
V_3 -> V_22 = L_3 ;
V_3 -> V_15 = V_25 ;
break;
case 3 :
V_3 -> V_22 = L_4 ;
V_3 -> V_15 = V_26 ;
break;
}
V_3 -> V_27 = & V_28 ;
V_3 -> V_29 = & V_30 ;
V_3 -> V_31 = & V_32 ;
V_3 -> V_33 = & V_34 ;
V_3 -> V_35 = & V_36 ;
V_3 -> V_37 = & V_38 ;
V_3 -> V_39 = & F_2 ;
V_3 -> V_8 = & F_1 ;
V_3 -> V_40 = 0 ;
V_3 -> V_41 =
F_12 ( V_3 -> V_15 ) ;
V_3 -> V_42 =
F_13 ( V_3 -> V_15 ) ;
F_14 ( & V_3 -> V_43 ) ;
V_10 = F_15 ( V_3 , V_17 ) ;
if ( V_10 )
F_16 ( L_5 ) ;
}
return 0 ;
}
void F_17 ( struct V_16 * V_17 )
{
int V_18 ;
for ( V_18 = 0 ; V_18 < V_19 ; ++ V_18 ) {
struct V_2 * V_3 = & V_20 [ V_18 ] ;
F_18 ( V_3 ) ;
}
F_19 ( V_20 ) ;
V_20 = NULL ;
V_19 = 0 ;
}
int F_20 ( void )
{
return V_19 ;
}
struct V_2 * F_21 ( int V_44 )
{
if ( V_44 >= V_19 )
return NULL ;
return & V_20 [ V_44 ] ;
}
int F_22 ( struct V_2 * V_3 ,
const struct V_45 * V_46 )
{
if ( F_23 ( V_47 ) ) {
if ( V_46 -> V_48 && V_46 -> V_49
&& V_46 -> V_50 != V_51 ) {
F_16 ( L_6 ) ;
return - V_52 ;
}
}
return 0 ;
}
static int F_24 ( struct V_2 * V_3 ,
struct V_53 * * V_54 )
{
struct V_55 * V_56 , * V_57 ;
struct V_53 * V_58 , * V_59 ;
F_25 (ovl1, &mgr->overlays, list) {
V_58 = V_54 [ V_56 -> V_15 ] ;
if ( V_58 == NULL )
continue;
F_25 (ovl2, &mgr->overlays, list) {
if ( V_56 == V_57 )
continue;
V_59 = V_54 [ V_57 -> V_15 ] ;
if ( V_59 == NULL )
continue;
if ( V_58 -> V_60 == V_59 -> V_60 ) {
F_16 ( L_7
L_8 ,
V_56 -> V_15 , V_57 -> V_15 , V_58 -> V_60 ) ;
return - V_52 ;
}
}
}
return 0 ;
}
int F_26 ( struct V_2 * V_3 ,
const struct V_61 * V_62 )
{
if ( ! F_27 ( V_3 -> V_15 , V_62 ) ) {
F_16 ( L_9 ) ;
return - V_52 ;
}
return 0 ;
}
static int F_28 ( struct V_2 * V_3 ,
const struct V_63 * V_64 )
{
struct V_65 V_66 = V_64 -> V_67 ;
int V_68 = V_64 -> V_69 ;
bool V_70 = V_64 -> V_70 ;
bool V_71 = V_64 -> V_71 ;
if ( V_66 . V_72 < 1 || V_66 . V_72 > 255 )
return - V_52 ;
if ( V_66 . V_73 < 1 || V_66 . V_73 > 255 )
return - V_52 ;
if ( V_68 != 12 && V_68 != 16 && V_68 != 18 && V_68 != 24 )
return - V_52 ;
if ( V_70 == false && V_71 == true )
return - V_52 ;
return 0 ;
}
int F_29 ( struct V_2 * V_3 ,
struct V_45 * V_46 ,
const struct V_61 * V_74 ,
const struct V_63 * V_75 ,
struct V_53 * * V_54 )
{
struct V_55 * V_76 ;
int V_10 ;
if ( F_23 ( V_77 ) ) {
V_10 = F_24 ( V_3 , V_54 ) ;
if ( V_10 )
return V_10 ;
}
V_10 = F_26 ( V_3 , V_74 ) ;
if ( V_10 )
return V_10 ;
V_10 = F_28 ( V_3 , V_75 ) ;
if ( V_10 )
return V_10 ;
F_25 (ovl, &mgr->overlays, list) {
struct V_53 * V_78 ;
int V_10 ;
V_78 = V_54 [ V_76 -> V_15 ] ;
if ( V_78 == NULL )
continue;
V_10 = F_30 ( V_76 , V_78 , V_74 ) ;
if ( V_10 )
return V_10 ;
}
return 0 ;
}
