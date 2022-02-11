static unsigned int F_1 ( const char * V_1 )
{
return F_2 ( V_1 , F_3 ( struct V_2 , V_1 ) , V_3 ) &
( V_4 - 1 ) ;
}
static void F_4 ( struct V_2 * V_5 )
{
unsigned int V_6 ;
V_6 = F_1 ( V_5 -> V_1 ) ;
F_5 ( & V_5 -> V_7 , & V_8 [ V_6 ] ) ;
}
struct V_2 * F_6 ( const char * V_1 )
{
struct V_2 * V_5 ;
struct V_9 * V_10 ;
unsigned int V_6 ;
V_6 = F_1 ( V_1 ) ;
F_7 ( & V_11 ) ;
F_8 (est, n, &rateest_hash[h], list) {
if ( strcmp ( V_5 -> V_1 , V_1 ) == 0 ) {
V_5 -> V_12 ++ ;
F_9 ( & V_11 ) ;
return V_5 ;
}
}
F_9 ( & V_11 ) ;
return NULL ;
}
static void F_10 ( struct V_13 * V_14 )
{
F_11 ( F_12 ( V_14 , struct V_2 , V_15 ) ) ;
}
void F_13 ( struct V_2 * V_5 )
{
F_7 ( & V_11 ) ;
if ( -- V_5 -> V_12 == 0 ) {
F_14 ( & V_5 -> V_7 ) ;
F_15 ( & V_5 -> V_16 , & V_5 -> V_17 ) ;
F_16 ( & V_5 -> V_15 , F_10 ) ;
}
F_9 ( & V_11 ) ;
}
static unsigned int
F_17 ( struct V_18 * V_19 , const struct V_20 * V_21 )
{
const struct V_22 * V_23 = V_21 -> V_24 ;
struct V_25 * V_26 = & V_23 -> V_5 -> V_16 ;
F_18 ( & V_23 -> V_5 -> V_27 ) ;
V_26 -> V_28 += V_19 -> V_29 ;
V_26 -> V_30 ++ ;
F_19 ( & V_23 -> V_5 -> V_27 ) ;
return V_31 ;
}
static int F_20 ( const struct V_32 * V_21 )
{
struct V_22 * V_23 = V_21 -> V_24 ;
struct V_2 * V_5 ;
struct {
struct V_33 V_34 ;
struct V_35 V_5 ;
} V_36 ;
int V_37 ;
if ( F_21 ( ! V_38 ) ) {
F_22 ( & V_3 , sizeof( V_3 ) ) ;
V_38 = true ;
}
V_5 = F_6 ( V_23 -> V_1 ) ;
if ( V_5 ) {
if ( ( ! V_23 -> V_39 && ! V_23 -> V_40 ) ||
( V_23 -> V_39 != V_5 -> V_41 . V_39 ||
V_23 -> V_40 != V_5 -> V_41 . V_40 ) ) {
F_13 ( V_5 ) ;
return - V_42 ;
}
V_23 -> V_5 = V_5 ;
return 0 ;
}
V_37 = - V_43 ;
V_5 = F_23 ( sizeof( * V_5 ) , V_44 ) ;
if ( ! V_5 )
goto V_45;
F_24 ( V_5 -> V_1 , V_23 -> V_1 , sizeof( V_5 -> V_1 ) ) ;
F_25 ( & V_5 -> V_27 ) ;
V_5 -> V_12 = 1 ;
V_5 -> V_41 . V_39 = V_23 -> V_39 ;
V_5 -> V_41 . V_40 = V_23 -> V_40 ;
V_36 . V_34 . V_46 = F_26 ( sizeof( V_36 . V_5 ) ) ;
V_36 . V_34 . V_47 = V_48 ;
V_36 . V_5 . V_39 = V_23 -> V_39 ;
V_36 . V_5 . V_40 = V_23 -> V_40 ;
V_37 = F_27 ( & V_5 -> V_16 , & V_5 -> V_17 ,
& V_5 -> V_27 , & V_36 . V_34 ) ;
if ( V_37 < 0 )
goto V_49;
V_23 -> V_5 = V_5 ;
F_4 ( V_5 ) ;
return 0 ;
V_49:
F_11 ( V_5 ) ;
V_45:
return V_37 ;
}
static void F_28 ( const struct V_50 * V_21 )
{
struct V_22 * V_23 = V_21 -> V_24 ;
F_13 ( V_23 -> V_5 ) ;
}
static int T_1 F_29 ( void )
{
unsigned int V_51 ;
for ( V_51 = 0 ; V_51 < F_30 ( V_8 ) ; V_51 ++ )
F_31 ( & V_8 [ V_51 ] ) ;
return F_32 ( & V_52 ) ;
}
static void T_2 F_33 ( void )
{
F_34 ( & V_52 ) ;
F_35 () ;
}
