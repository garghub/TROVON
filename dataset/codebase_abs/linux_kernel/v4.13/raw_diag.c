static struct V_1 *
F_1 ( const struct V_2 * V_3 )
{
if ( V_3 -> V_4 == V_5 ) {
return & V_6 ;
#if F_2 ( V_7 )
} else if ( V_3 -> V_4 == V_8 ) {
return & V_9 ;
#endif
} else {
F_3 ( L_1 ,
V_3 -> V_4 ) ;
F_4 ( 1 ) ;
return F_5 ( - V_10 ) ;
}
}
static struct V_11 * F_6 ( struct V_12 * V_12 , struct V_11 * V_13 ,
const struct V_2 * V_14 )
{
struct V_15 * V_3 = ( void * ) V_14 ;
struct V_11 * V_16 = NULL ;
if ( V_3 -> V_4 == V_5 )
V_16 = F_7 ( V_12 , V_13 , V_3 -> V_17 ,
V_3 -> V_18 . V_19 [ 0 ] ,
V_3 -> V_18 . V_20 [ 0 ] ,
V_3 -> V_18 . V_21 ) ;
#if F_2 ( V_7 )
else
V_16 = F_8 ( V_12 , V_13 , V_3 -> V_17 ,
( const struct V_22 * ) V_3 -> V_18 . V_20 ,
( const struct V_22 * ) V_3 -> V_18 . V_19 ,
V_3 -> V_18 . V_21 ) ;
#endif
return V_16 ;
}
static struct V_11 * F_9 ( struct V_12 * V_12 , const struct V_2 * V_3 )
{
struct V_1 * V_23 = F_1 ( V_3 ) ;
struct V_11 * V_16 = NULL , * V_24 ;
int V_25 ;
if ( F_10 ( V_23 ) )
return F_11 ( V_23 ) ;
F_12 ( & V_23 -> V_26 ) ;
for ( V_25 = 0 ; V_25 < V_27 ; V_25 ++ ) {
F_13 (s, &hashinfo->ht[slot]) {
V_16 = F_6 ( V_12 , V_24 , V_3 ) ;
if ( V_16 ) {
F_14 ( V_16 ) ;
goto V_28;
}
}
}
V_28:
F_15 ( & V_23 -> V_26 ) ;
return V_16 ? V_16 : F_5 ( - V_29 ) ;
}
static int F_16 ( struct V_30 * V_31 ,
const struct V_32 * V_33 ,
const struct V_2 * V_3 )
{
struct V_12 * V_12 = F_17 ( V_31 -> V_16 ) ;
struct V_30 * V_34 ;
struct V_11 * V_16 ;
int V_35 ;
V_16 = F_9 ( V_12 , V_3 ) ;
if ( F_10 ( V_16 ) )
return F_18 ( V_16 ) ;
V_34 = F_19 ( sizeof( struct V_36 ) +
sizeof( struct V_37 ) + 64 ,
V_38 ) ;
if ( ! V_34 ) {
F_20 ( V_16 ) ;
return - V_39 ;
}
V_35 = F_21 ( V_16 , NULL , V_34 , V_3 ,
F_22 ( F_23 ( V_31 ) . V_16 ) ,
F_23 ( V_31 ) . V_40 ,
V_33 -> V_41 , 0 , V_33 ,
F_24 ( V_31 , V_42 ) ) ;
F_20 ( V_16 ) ;
if ( V_35 < 0 ) {
F_25 ( V_34 ) ;
return V_35 ;
}
V_35 = F_26 ( V_12 -> V_43 , V_34 ,
F_23 ( V_31 ) . V_40 ,
V_44 ) ;
if ( V_35 > 0 )
V_35 = 0 ;
return V_35 ;
}
static int F_27 ( struct V_11 * V_16 , struct V_30 * V_45 ,
struct V_46 * V_47 ,
const struct V_2 * V_3 ,
struct V_48 * V_49 , bool V_50 )
{
if ( ! F_28 ( V_49 , V_16 ) )
return 0 ;
return F_21 ( V_16 , NULL , V_45 , V_3 ,
F_22 ( F_23 ( V_47 -> V_45 ) . V_16 ) ,
F_23 ( V_47 -> V_45 ) . V_40 ,
V_47 -> V_33 -> V_41 , V_51 ,
V_47 -> V_33 , V_50 ) ;
}
static void F_29 ( struct V_30 * V_45 , struct V_46 * V_47 ,
const struct V_2 * V_3 , struct V_48 * V_49 )
{
bool V_50 = F_24 ( V_47 -> V_45 , V_42 ) ;
struct V_1 * V_23 = F_1 ( V_3 ) ;
struct V_12 * V_12 = F_17 ( V_45 -> V_16 ) ;
int V_52 , V_53 , V_25 , V_54 ;
struct V_11 * V_16 = NULL ;
if ( F_10 ( V_23 ) )
return;
V_54 = V_47 -> args [ 0 ] ;
V_52 = V_53 = V_47 -> args [ 1 ] ;
F_12 ( & V_23 -> V_26 ) ;
for ( V_25 = V_54 ; V_25 < V_27 ; V_53 = 0 , V_25 ++ ) {
V_52 = 0 ;
F_13 (sk, &hashinfo->ht[slot]) {
struct V_55 * V_56 = F_30 ( V_16 ) ;
if ( ! F_31 ( F_17 ( V_16 ) , V_12 ) )
continue;
if ( V_52 < V_53 )
goto V_57;
if ( V_16 -> V_58 != V_3 -> V_4 )
goto V_57;
if ( V_3 -> V_18 . V_59 != V_56 -> V_60 &&
V_3 -> V_18 . V_59 )
goto V_57;
if ( V_3 -> V_18 . V_61 != V_56 -> V_62 &&
V_3 -> V_18 . V_61 )
goto V_57;
if ( F_27 ( V_16 , V_45 , V_47 , V_3 , V_49 , V_50 ) < 0 )
goto V_28;
V_57:
V_52 ++ ;
}
}
V_28:
F_15 ( & V_23 -> V_26 ) ;
V_47 -> args [ 0 ] = V_25 ;
V_47 -> args [ 1 ] = V_52 ;
}
static void F_32 ( struct V_11 * V_16 , struct V_36 * V_3 ,
void * V_63 )
{
V_3 -> V_64 = F_33 ( V_16 ) ;
V_3 -> V_65 = F_34 ( V_16 ) ;
}
static int F_35 ( struct V_30 * V_31 ,
const struct V_2 * V_3 )
{
struct V_12 * V_12 = F_17 ( V_31 -> V_16 ) ;
struct V_11 * V_16 ;
int V_35 ;
V_16 = F_9 ( V_12 , V_3 ) ;
if ( F_10 ( V_16 ) )
return F_18 ( V_16 ) ;
V_35 = F_36 ( V_16 , V_66 ) ;
F_20 ( V_16 ) ;
return V_35 ;
}
static void T_1 F_37 ( void )
{
#define F_38 ( T_2 , T_3 ) \
(offsetof(struct inet_diag_req_v2, m1) != \
offsetof(struct inet_diag_req_raw, m2))
F_39 ( sizeof( struct V_2 ) !=
sizeof( struct V_15 ) ) ;
F_39 ( F_38 ( V_4 , V_4 ) ) ;
F_39 ( F_38 ( V_67 , V_67 ) ) ;
F_39 ( F_38 ( V_68 , V_68 ) ) ;
F_39 ( F_38 ( V_69 , V_17 ) ) ;
F_39 ( F_38 ( V_70 , V_70 ) ) ;
F_39 ( F_38 ( V_18 , V_18 ) ) ;
#undef F_38
}
static int T_4 F_40 ( void )
{
return F_41 ( & V_71 ) ;
}
static void T_5 F_42 ( void )
{
F_43 ( & V_71 ) ;
}
