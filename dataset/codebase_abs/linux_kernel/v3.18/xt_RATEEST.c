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
unsigned int V_6 ;
V_6 = F_1 ( V_1 ) ;
F_7 ( & V_9 ) ;
F_8 (est, &rateest_hash[h], list) {
if ( strcmp ( V_5 -> V_1 , V_1 ) == 0 ) {
V_5 -> V_10 ++ ;
F_9 ( & V_9 ) ;
return V_5 ;
}
}
F_9 ( & V_9 ) ;
return NULL ;
}
void F_10 ( struct V_2 * V_5 )
{
F_7 ( & V_9 ) ;
if ( -- V_5 -> V_10 == 0 ) {
F_11 ( & V_5 -> V_7 ) ;
F_12 ( & V_5 -> V_11 , & V_5 -> V_12 ) ;
F_13 ( V_5 , V_13 ) ;
}
F_9 ( & V_9 ) ;
}
static unsigned int
F_14 ( struct V_14 * V_15 , const struct V_16 * V_17 )
{
const struct V_18 * V_19 = V_17 -> V_20 ;
struct V_21 * V_22 = & V_19 -> V_5 -> V_11 ;
F_15 ( & V_19 -> V_5 -> V_23 ) ;
V_22 -> V_24 += V_15 -> V_25 ;
V_22 -> V_26 ++ ;
F_16 ( & V_19 -> V_5 -> V_23 ) ;
return V_27 ;
}
static int F_17 ( const struct V_28 * V_17 )
{
struct V_18 * V_19 = V_17 -> V_20 ;
struct V_2 * V_5 ;
struct {
struct V_29 V_30 ;
struct V_31 V_5 ;
} V_32 ;
int V_33 ;
if ( F_18 ( ! V_34 ) ) {
F_19 ( & V_3 , sizeof( V_3 ) ) ;
V_34 = true ;
}
V_5 = F_6 ( V_19 -> V_1 ) ;
if ( V_5 ) {
if ( ( ! V_19 -> V_35 && ! V_19 -> V_36 ) ||
( V_19 -> V_35 != V_5 -> V_37 . V_35 ||
V_19 -> V_36 != V_5 -> V_37 . V_36 ) ) {
F_10 ( V_5 ) ;
return - V_38 ;
}
V_19 -> V_5 = V_5 ;
return 0 ;
}
V_33 = - V_39 ;
V_5 = F_20 ( sizeof( * V_5 ) , V_40 ) ;
if ( ! V_5 )
goto V_41;
F_21 ( V_5 -> V_1 , V_19 -> V_1 , sizeof( V_5 -> V_1 ) ) ;
F_22 ( & V_5 -> V_23 ) ;
V_5 -> V_10 = 1 ;
V_5 -> V_37 . V_35 = V_19 -> V_35 ;
V_5 -> V_37 . V_36 = V_19 -> V_36 ;
V_32 . V_30 . V_42 = F_23 ( sizeof( V_32 . V_5 ) ) ;
V_32 . V_30 . V_43 = V_44 ;
V_32 . V_5 . V_35 = V_19 -> V_35 ;
V_32 . V_5 . V_36 = V_19 -> V_36 ;
V_33 = F_24 ( & V_5 -> V_11 , NULL , & V_5 -> V_12 ,
& V_5 -> V_23 , & V_32 . V_30 ) ;
if ( V_33 < 0 )
goto V_45;
V_19 -> V_5 = V_5 ;
F_4 ( V_5 ) ;
return 0 ;
V_45:
F_25 ( V_5 ) ;
V_41:
return V_33 ;
}
static void F_26 ( const struct V_46 * V_17 )
{
struct V_18 * V_19 = V_17 -> V_20 ;
F_10 ( V_19 -> V_5 ) ;
}
static int T_1 F_27 ( void )
{
unsigned int V_47 ;
for ( V_47 = 0 ; V_47 < F_28 ( V_8 ) ; V_47 ++ )
F_29 ( & V_8 [ V_47 ] ) ;
return F_30 ( & V_48 ) ;
}
static void T_2 F_31 ( void )
{
F_32 ( & V_48 ) ;
}
