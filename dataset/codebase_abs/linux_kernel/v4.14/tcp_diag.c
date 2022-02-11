static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
void * V_5 )
{
struct V_6 * V_7 = V_5 ;
if ( F_2 ( V_2 ) == V_8 ) {
V_4 -> V_9 = V_2 -> V_10 ;
V_4 -> V_11 = V_2 -> V_12 ;
} else if ( V_2 -> V_13 == V_14 ) {
const struct V_15 * V_16 = F_3 ( V_2 ) ;
V_4 -> V_9 = F_4 ( int , V_16 -> V_17 - V_16 -> V_18 , 0 ) ;
V_4 -> V_11 = V_16 -> V_19 - V_16 -> V_20 ;
}
if ( V_7 )
F_5 ( V_2 , V_7 ) ;
}
static void F_6 ( struct V_21 * V_7 ,
const struct V_22 * V_23 )
{
V_7 -> V_24 = V_23 -> V_25 ;
V_7 -> V_26 = V_23 -> V_27 ;
V_7 -> V_28 = V_23 -> V_29 ;
memcpy ( V_7 -> V_30 , V_23 -> V_23 , V_23 -> V_29 ) ;
if ( V_23 -> V_25 == V_31 )
V_7 -> V_32 [ 0 ] = V_23 -> V_33 . V_34 . V_35 ;
#if F_7 ( V_36 )
else if ( V_23 -> V_25 == V_37 )
memcpy ( & V_7 -> V_32 , & V_23 -> V_33 . V_38 ,
sizeof( V_7 -> V_32 ) ) ;
#endif
}
static int F_8 ( struct V_39 * V_40 ,
const struct V_41 * V_42 )
{
const struct V_22 * V_23 ;
struct V_21 * V_7 ;
struct V_43 * V_44 ;
int V_45 = 0 ;
F_9 (key, &md5sig->head, node)
V_45 ++ ;
if ( V_45 == 0 )
return 0 ;
V_44 = F_10 ( V_40 , V_46 ,
V_45 * sizeof( struct V_21 ) ) ;
if ( ! V_44 )
return - V_47 ;
V_7 = F_11 ( V_44 ) ;
memset ( V_7 , 0 , V_45 * sizeof( struct V_21 ) ) ;
F_9 (key, &md5sig->head, node) {
F_6 ( V_7 ++ , V_23 ) ;
if ( -- V_45 == 0 )
break;
}
return 0 ;
}
static int F_12 ( struct V_1 * V_2 , bool V_48 ,
struct V_39 * V_40 )
{
#ifdef F_13
if ( V_48 ) {
struct V_41 * V_42 ;
int V_49 = 0 ;
F_14 () ;
V_42 = F_15 ( F_3 ( V_2 ) -> V_50 ) ;
if ( V_42 )
V_49 = F_8 ( V_40 , V_42 ) ;
F_16 () ;
if ( V_49 < 0 )
return V_49 ;
}
#endif
return 0 ;
}
static T_1 F_17 ( struct V_1 * V_2 , bool V_48 )
{
T_1 V_51 = 0 ;
#ifdef F_13
if ( V_48 && F_18 ( V_2 ) ) {
const struct V_41 * V_42 ;
const struct V_22 * V_23 ;
T_1 V_45 = 0 ;
F_14 () ;
V_42 = F_15 ( F_3 ( V_2 ) -> V_50 ) ;
if ( V_42 ) {
F_9 (key, &md5sig->head, node)
V_45 ++ ;
}
F_16 () ;
V_51 += F_19 ( V_45 *
sizeof( struct V_21 ) ) ;
}
#endif
return V_51 ;
}
static void F_20 ( struct V_39 * V_40 , struct V_52 * V_53 ,
const struct V_54 * V_4 , struct V_43 * V_55 )
{
F_21 ( & V_56 , V_40 , V_53 , V_4 , V_55 ) ;
}
static int F_22 ( struct V_39 * V_57 , const struct V_58 * V_59 ,
const struct V_54 * V_60 )
{
return F_23 ( & V_56 , V_57 , V_59 , V_60 ) ;
}
static int F_24 ( struct V_39 * V_57 ,
const struct V_54 * V_60 )
{
struct V_61 * V_61 = F_25 ( V_57 -> V_2 ) ;
struct V_1 * V_2 = F_26 ( V_61 , & V_56 , V_60 ) ;
int V_49 ;
if ( F_27 ( V_2 ) )
return F_28 ( V_2 ) ;
V_49 = F_29 ( V_2 , V_62 ) ;
F_30 ( V_2 ) ;
return V_49 ;
}
static int T_2 F_31 ( void )
{
return F_32 ( & V_63 ) ;
}
static void T_3 F_33 ( void )
{
F_34 ( & V_63 ) ;
}
