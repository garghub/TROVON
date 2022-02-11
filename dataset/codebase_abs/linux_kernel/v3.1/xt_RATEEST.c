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
void F_10 ( struct V_2 * V_5 )
{
F_7 ( & V_11 ) ;
if ( -- V_5 -> V_12 == 0 ) {
F_11 ( & V_5 -> V_7 ) ;
F_12 ( & V_5 -> V_13 , & V_5 -> V_14 ) ;
F_13 ( V_5 , V_15 ) ;
}
F_9 ( & V_11 ) ;
}
static unsigned int
F_14 ( struct V_16 * V_17 , const struct V_18 * V_19 )
{
const struct V_20 * V_21 = V_19 -> V_22 ;
struct V_23 * V_24 = & V_21 -> V_5 -> V_13 ;
F_15 ( & V_21 -> V_5 -> V_25 ) ;
V_24 -> V_26 += V_17 -> V_27 ;
V_24 -> V_28 ++ ;
F_16 ( & V_21 -> V_5 -> V_25 ) ;
return V_29 ;
}
static int F_17 ( const struct V_30 * V_19 )
{
struct V_20 * V_21 = V_19 -> V_22 ;
struct V_2 * V_5 ;
struct {
struct V_31 V_32 ;
struct V_33 V_5 ;
} V_34 ;
int V_35 ;
if ( F_18 ( ! V_36 ) ) {
F_19 ( & V_3 , sizeof( V_3 ) ) ;
V_36 = true ;
}
V_5 = F_6 ( V_21 -> V_1 ) ;
if ( V_5 ) {
if ( ( ! V_21 -> V_37 && ! V_21 -> V_38 ) ||
( V_21 -> V_37 != V_5 -> V_39 . V_37 ||
V_21 -> V_38 != V_5 -> V_39 . V_38 ) ) {
F_10 ( V_5 ) ;
return - V_40 ;
}
V_21 -> V_5 = V_5 ;
return 0 ;
}
V_35 = - V_41 ;
V_5 = F_20 ( sizeof( * V_5 ) , V_42 ) ;
if ( ! V_5 )
goto V_43;
F_21 ( V_5 -> V_1 , V_21 -> V_1 , sizeof( V_5 -> V_1 ) ) ;
F_22 ( & V_5 -> V_25 ) ;
V_5 -> V_12 = 1 ;
V_5 -> V_39 . V_37 = V_21 -> V_37 ;
V_5 -> V_39 . V_38 = V_21 -> V_38 ;
V_34 . V_32 . V_44 = F_23 ( sizeof( V_34 . V_5 ) ) ;
V_34 . V_32 . V_45 = V_46 ;
V_34 . V_5 . V_37 = V_21 -> V_37 ;
V_34 . V_5 . V_38 = V_21 -> V_38 ;
V_35 = F_24 ( & V_5 -> V_13 , & V_5 -> V_14 ,
& V_5 -> V_25 , & V_34 . V_32 ) ;
if ( V_35 < 0 )
goto V_47;
V_21 -> V_5 = V_5 ;
F_4 ( V_5 ) ;
return 0 ;
V_47:
F_25 ( V_5 ) ;
V_43:
return V_35 ;
}
static void F_26 ( const struct V_48 * V_19 )
{
struct V_20 * V_21 = V_19 -> V_22 ;
F_10 ( V_21 -> V_5 ) ;
}
static int T_1 F_27 ( void )
{
unsigned int V_49 ;
for ( V_49 = 0 ; V_49 < F_28 ( V_8 ) ; V_49 ++ )
F_29 ( & V_8 [ V_49 ] ) ;
return F_30 ( & V_50 ) ;
}
static void T_2 F_31 ( void )
{
F_32 ( & V_50 ) ;
}
