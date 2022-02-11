static struct V_1 *
F_1 ( struct V_2 * V_3 )
{
return & F_2 () -> V_4 ;
}
static int F_3 ( struct V_1 * V_4 )
{
return & F_2 () -> V_4 == V_4 ;
}
static int F_4 ( struct V_5 * V_6 ,
struct V_7 * V_8 )
{
struct V_9 * V_10 =
F_5 ( V_6 -> V_4 , struct V_9 , V_4 ) ;
int V_11 ;
if ( F_6 ( V_10 , V_12 ) )
V_11 = ( V_8 -> V_11 & V_13 ) >> 6 ;
else
V_11 = V_8 -> V_11 & V_14 ;
return ( V_11 << 6 ) | ( V_11 << 3 ) | V_11 ;
}
bool F_7 ( struct V_9 * V_15 )
{
#ifdef F_8
struct V_7 * V_16 ;
F_9 ( & V_15 -> V_4 , & V_17 , F_3 ) ;
V_16 = F_10 ( V_18 , sizeof( V_18 ) , V_19 ) ;
if ( V_16 ) {
int V_20 ;
for ( V_20 = 0 ; V_20 < V_21 ; V_20 ++ ) {
V_16 [ V_20 ] . V_22 = & V_15 -> V_23 [ V_20 ] ;
}
V_15 -> V_24 = F_11 ( & V_15 -> V_4 , L_1 , V_16 ) ;
}
if ( ! V_15 -> V_24 ) {
F_12 ( V_16 ) ;
F_13 ( & V_15 -> V_4 ) ;
return false ;
}
#endif
return true ;
}
void F_14 ( struct V_9 * V_15 )
{
#ifdef F_8
struct V_7 * V_16 ;
V_16 = V_15 -> V_24 -> V_25 ;
F_15 ( V_15 -> V_24 ) ;
F_13 ( & V_15 -> V_4 ) ;
F_12 ( V_16 ) ;
#endif
}
static struct V_26 * F_16 ( struct V_9 * V_15 , T_1 V_27 , struct V_28 * V_29 )
{
struct V_26 * V_26 ;
F_17 (ucounts, hashent, node) {
if ( F_18 ( V_26 -> V_27 , V_27 ) && ( V_26 -> V_15 == V_15 ) )
return V_26 ;
}
return NULL ;
}
static struct V_26 * F_19 ( struct V_9 * V_15 , T_1 V_27 )
{
struct V_28 * V_29 = F_20 ( V_15 , V_27 ) ;
struct V_26 * V_26 , * V_30 ;
F_21 ( & V_31 ) ;
V_26 = F_16 ( V_15 , V_27 , V_29 ) ;
if ( ! V_26 ) {
F_22 ( & V_31 ) ;
V_30 = F_23 ( sizeof( * V_30 ) , V_19 ) ;
if ( ! V_30 )
return NULL ;
V_30 -> V_15 = V_15 ;
V_30 -> V_27 = V_27 ;
F_24 ( & V_30 -> V_32 , 0 ) ;
F_21 ( & V_31 ) ;
V_26 = F_16 ( V_15 , V_27 , V_29 ) ;
if ( V_26 ) {
F_12 ( V_30 ) ;
} else {
F_25 ( & V_30 -> V_33 , V_29 ) ;
V_26 = V_30 ;
}
}
if ( ! F_26 ( & V_26 -> V_32 , 1 , V_34 ) )
V_26 = NULL ;
F_22 ( & V_31 ) ;
return V_26 ;
}
static void F_27 ( struct V_26 * V_26 )
{
unsigned long V_35 ;
if ( F_28 ( & V_26 -> V_32 ) ) {
F_29 ( & V_31 , V_35 ) ;
F_30 ( & V_26 -> V_33 ) ;
F_31 ( & V_31 , V_35 ) ;
F_12 ( V_26 ) ;
}
}
static inline bool F_32 ( T_2 * V_36 , int V_37 )
{
int V_38 , V_39 ;
V_38 = F_33 ( V_36 ) ;
for (; ; ) {
if ( F_34 ( V_38 >= V_37 ) )
return false ;
V_39 = F_35 ( V_36 , V_38 , V_38 + 1 ) ;
if ( F_36 ( V_39 == V_38 ) )
return true ;
V_38 = V_39 ;
}
}
struct V_26 * F_37 ( struct V_9 * V_15 , T_1 V_27 ,
enum V_40 type )
{
struct V_26 * V_26 , * V_41 , * V_42 ;
struct V_9 * V_43 ;
V_26 = F_19 ( V_15 , V_27 ) ;
for ( V_41 = V_26 ; V_41 ; V_41 = V_43 -> V_26 ) {
int V_44 ;
V_43 = V_41 -> V_15 ;
V_44 = F_38 ( V_43 -> V_23 [ type ] ) ;
if ( ! F_32 ( & V_41 -> V_45 [ type ] , V_44 ) )
goto V_46;
}
return V_26 ;
V_46:
V_42 = V_41 ;
for ( V_41 = V_26 ; V_41 != V_42 ; V_41 = V_41 -> V_15 -> V_26 )
F_39 ( & V_41 -> V_45 [ type ] ) ;
F_27 ( V_26 ) ;
return NULL ;
}
void F_40 ( struct V_26 * V_26 , enum V_40 type )
{
struct V_26 * V_41 ;
for ( V_41 = V_26 ; V_41 ; V_41 = V_41 -> V_15 -> V_26 ) {
int V_47 = F_41 ( & V_41 -> V_45 [ type ] ) ;
F_42 ( V_47 < 0 ) ;
}
F_27 ( V_26 ) ;
}
static T_3 int F_43 ( void )
{
#ifdef F_8
static struct V_5 * V_48 ;
static struct V_7 V_49 [ 1 ] ;
V_48 = F_44 ( L_1 , V_49 ) ;
F_45 ( V_48 ) ;
F_46 ( ! V_48 ) ;
F_46 ( ! F_7 ( & V_50 ) ) ;
#endif
return 0 ;
}
