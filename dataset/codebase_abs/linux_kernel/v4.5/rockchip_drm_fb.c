struct V_1 * F_1 ( struct V_2 * V_3 ,
unsigned int V_4 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
if ( V_4 >= V_7 )
return NULL ;
return V_6 -> V_8 [ V_4 ] ;
}
static void F_3 ( struct V_2 * V_3 )
{
struct V_5 * V_9 = F_2 ( V_3 ) ;
struct V_1 * V_8 ;
int V_10 ;
for ( V_10 = 0 ; V_10 < V_7 ; V_10 ++ ) {
V_8 = V_9 -> V_8 [ V_10 ] ;
if ( V_8 )
F_4 ( V_8 ) ;
}
F_5 ( V_3 ) ;
F_6 ( V_9 ) ;
}
static int F_7 ( struct V_2 * V_3 ,
struct V_11 * V_12 ,
unsigned int * V_13 )
{
struct V_5 * V_9 = F_2 ( V_3 ) ;
return F_8 ( V_12 ,
V_9 -> V_8 [ 0 ] , V_13 ) ;
}
static struct V_5 *
F_9 ( struct V_14 * V_15 , const struct V_16 * V_17 ,
struct V_1 * * V_8 , unsigned int V_18 )
{
struct V_5 * V_9 ;
int V_19 ;
int V_10 ;
V_9 = F_10 ( sizeof( * V_9 ) , V_20 ) ;
if ( ! V_9 )
return F_11 ( - V_21 ) ;
F_12 ( & V_9 -> V_3 , V_17 ) ;
for ( V_10 = 0 ; V_10 < V_18 ; V_10 ++ )
V_9 -> V_8 [ V_10 ] = V_8 [ V_10 ] ;
V_19 = F_13 ( V_15 , & V_9 -> V_3 ,
& V_22 ) ;
if ( V_19 ) {
F_14 ( V_15 -> V_15 , L_1 ,
V_19 ) ;
F_6 ( V_9 ) ;
return F_11 ( V_19 ) ;
}
return V_9 ;
}
static struct V_2 *
F_15 ( struct V_14 * V_15 , struct V_11 * V_12 ,
const struct V_16 * V_17 )
{
struct V_5 * V_9 ;
struct V_1 * V_23 [ V_7 ] ;
struct V_1 * V_8 ;
unsigned int V_24 ;
unsigned int V_25 ;
int V_18 ;
int V_19 ;
int V_10 ;
V_24 = F_16 ( V_17 -> V_26 ) ;
V_25 = F_17 ( V_17 -> V_26 ) ;
V_18 = F_18 ( F_19 ( V_17 -> V_26 ) ,
V_7 ) ;
for ( V_10 = 0 ; V_10 < V_18 ; V_10 ++ ) {
unsigned int V_27 = V_17 -> V_27 / ( V_10 ? V_24 : 1 ) ;
unsigned int V_28 = V_17 -> V_28 / ( V_10 ? V_25 : 1 ) ;
unsigned int V_29 ;
V_8 = F_20 ( V_15 , V_12 ,
V_17 -> V_30 [ V_10 ] ) ;
if ( ! V_8 ) {
F_14 ( V_15 -> V_15 , L_2 ) ;
V_19 = - V_31 ;
goto V_32;
}
V_29 = ( V_28 - 1 ) * V_17 -> V_33 [ V_10 ] +
V_17 -> V_34 [ V_10 ] +
V_27 * F_21 ( V_17 -> V_26 , V_10 ) ;
if ( V_8 -> V_35 < V_29 ) {
F_4 ( V_8 ) ;
V_19 = - V_36 ;
goto V_32;
}
V_23 [ V_10 ] = V_8 ;
}
V_9 = F_9 ( V_15 , V_17 , V_23 , V_10 ) ;
if ( F_22 ( V_9 ) ) {
V_19 = F_23 ( V_9 ) ;
goto V_32;
}
return & V_9 -> V_3 ;
V_32:
for ( V_10 -- ; V_10 >= 0 ; V_10 -- )
F_4 ( V_23 [ V_10 ] ) ;
return F_11 ( V_19 ) ;
}
static void F_24 ( struct V_14 * V_15 )
{
struct V_37 * V_38 = V_15 -> V_39 ;
struct V_40 * V_41 = & V_38 -> V_42 ;
if ( V_41 )
F_25 ( V_41 ) ;
}
static void F_26 ( struct V_43 * V_44 )
{
struct V_37 * V_45 = V_44 -> V_15 -> V_39 ;
int V_46 = F_27 ( V_44 ) ;
const struct V_47 * V_48 = V_45 -> V_48 [ V_46 ] ;
if ( V_48 && V_48 -> V_49 )
V_48 -> V_49 ( V_44 ) ;
}
static void
F_28 ( struct V_14 * V_15 , struct V_50 * V_51 )
{
struct V_52 * V_53 ;
struct V_43 * V_44 ;
int V_10 , V_19 ;
F_29 (old_state, crtc, old_crtc_state, i) {
V_53 -> V_54 = false ;
if ( ! V_44 -> V_55 -> V_56 )
continue;
if ( ! F_30 ( V_15 ,
V_51 , V_44 ) )
continue;
V_19 = F_31 ( V_44 ) ;
if ( V_19 != 0 )
continue;
V_53 -> V_54 = true ;
}
F_29 (old_state, crtc, old_crtc_state, i) {
if ( ! V_53 -> V_54 )
continue;
F_26 ( V_44 ) ;
F_32 ( V_44 ) ;
}
}
static void
F_33 ( struct V_57 * V_58 )
{
struct V_50 * V_55 = V_58 -> V_55 ;
struct V_14 * V_15 = V_58 -> V_15 ;
F_34 ( V_15 , V_55 ) ;
F_35 ( V_15 , V_55 ) ;
F_36 ( V_15 , V_55 , true ) ;
F_28 ( V_15 , V_55 ) ;
F_37 ( V_15 , V_55 ) ;
F_38 ( V_55 ) ;
}
void F_39 ( struct V_59 * V_60 )
{
struct V_57 * V_58 = F_40 ( V_60 ,
struct V_57 , V_60 ) ;
F_33 ( V_58 ) ;
}
int F_41 ( struct V_14 * V_15 ,
struct V_50 * V_55 ,
bool V_61 )
{
struct V_37 * V_38 = V_15 -> V_39 ;
struct V_57 * V_58 = & V_38 -> V_58 ;
int V_19 ;
V_19 = F_42 ( V_15 , V_55 ) ;
if ( V_19 )
return V_19 ;
F_43 ( & V_58 -> V_62 ) ;
F_44 ( & V_58 -> V_60 ) ;
F_45 ( V_15 , V_55 ) ;
V_58 -> V_15 = V_15 ;
V_58 -> V_55 = V_55 ;
if ( V_61 )
F_46 ( & V_58 -> V_60 ) ;
else
F_33 ( V_58 ) ;
F_47 ( & V_58 -> V_62 ) ;
return 0 ;
}
struct V_2 *
F_48 ( struct V_14 * V_15 ,
const struct V_16 * V_17 ,
struct V_1 * V_8 )
{
struct V_5 * V_9 ;
V_9 = F_9 ( V_15 , V_17 , & V_8 , 1 ) ;
if ( F_22 ( V_9 ) )
return NULL ;
return & V_9 -> V_3 ;
}
void F_49 ( struct V_14 * V_15 )
{
V_15 -> V_63 . V_64 = 0 ;
V_15 -> V_63 . V_65 = 0 ;
V_15 -> V_63 . V_66 = 4096 ;
V_15 -> V_63 . V_67 = 4096 ;
V_15 -> V_63 . V_68 = & V_69 ;
}
