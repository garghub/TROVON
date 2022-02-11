int
F_1 (
struct V_1 * V_2 ,
int V_3 )
{
int V_4 = F_2 ( V_2 , V_2 -> V_5 . V_6 ) ;
return ( V_3 + V_4 - 1 ) / V_4 ;
}
int
F_3 (
struct V_1 * V_2 ,
T_1 V_7 ,
T_2 V_8 ,
T_2 V_9 ,
struct V_10 * V_11 )
{
struct V_12 * V_13 = V_11 -> V_14 ;
if ( ! F_4 ( & V_2 -> V_5 ) )
return 0 ;
V_13 -> V_15 = F_5 ( V_16 ) ;
V_13 -> V_17 = F_5 ( V_8 ) ;
V_13 -> V_18 = F_5 ( V_9 ) ;
F_6 ( & V_13 -> V_19 , & V_2 -> V_5 . V_20 ) ;
V_13 -> V_21 = F_7 ( V_7 ) ;
V_13 -> V_22 = F_7 ( V_11 -> V_23 ) ;
V_11 -> V_24 = & V_25 ;
return sizeof( struct V_12 ) ;
}
bool
F_8 (
struct V_1 * V_2 ,
T_1 V_7 ,
T_2 V_8 ,
T_2 V_9 ,
struct V_10 * V_11 )
{
struct V_12 * V_13 = V_11 -> V_14 ;
if ( V_8 != F_9 ( V_13 -> V_17 ) )
return false ;
if ( V_9 != F_9 ( V_13 -> V_18 ) )
return false ;
if ( V_7 != F_10 ( V_13 -> V_21 ) )
return false ;
return true ;
}
static bool
F_11 (
struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_26 -> V_27 ;
struct V_12 * V_13 = V_11 -> V_14 ;
if ( ! F_4 ( & V_2 -> V_5 ) )
return false ;
if ( V_13 -> V_15 != F_5 ( V_16 ) )
return false ;
if ( ! F_12 ( & V_13 -> V_19 , & V_2 -> V_5 . V_20 ) )
return false ;
if ( V_11 -> V_23 != F_10 ( V_13 -> V_22 ) )
return false ;
if ( F_9 ( V_13 -> V_17 ) +
F_9 ( V_13 -> V_18 ) >= V_28 )
return false ;
if ( V_13 -> V_21 == 0 )
return false ;
return true ;
}
static void
F_13 (
struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_26 -> V_27 ;
if ( ! F_4 ( & V_2 -> V_5 ) )
return;
if ( ! F_14 ( V_11 -> V_14 , F_15 ( V_11 -> V_29 ) ,
F_16 ( struct V_12 , V_30 ) ) ||
! F_11 ( V_11 ) ) {
F_17 ( V_31 , V_32 , V_2 , V_11 -> V_14 ) ;
F_18 ( V_11 , V_33 ) ;
}
}
static void
F_19 (
struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_26 -> V_27 ;
struct V_34 * V_35 = V_11 -> V_36 ;
if ( ! F_4 ( & V_2 -> V_5 ) )
return;
if ( ! F_11 ( V_11 ) ) {
F_17 ( V_31 , V_32 , V_2 , V_11 -> V_14 ) ;
F_18 ( V_11 , V_33 ) ;
return;
}
if ( V_35 ) {
struct V_12 * V_13 = V_11 -> V_14 ;
V_13 -> V_37 = F_7 ( V_35 -> V_38 . V_39 ) ;
}
F_20 ( V_11 -> V_14 , F_15 ( V_11 -> V_29 ) ,
F_16 ( struct V_12 , V_30 ) ) ;
}
void
F_21 (
struct V_40 * V_41 ,
struct V_10 * V_11 ,
struct V_42 * V_43 ,
struct V_44 * V_45 )
{
struct V_1 * V_2 = V_43 -> V_46 ;
char * V_47 ;
if ( ! F_4 ( & V_2 -> V_5 ) ) {
V_11 -> V_24 = NULL ;
memcpy ( V_11 -> V_14 , V_45 -> V_48 . V_49 , V_45 -> V_50 ) ;
return;
}
ASSERT ( F_15 ( V_11 -> V_29 ) >=
V_45 -> V_50 + sizeof( struct V_12 ) ) ;
V_11 -> V_24 = & V_25 ;
V_47 = V_11 -> V_14 ;
V_47 += F_3 ( V_2 , V_43 -> V_51 , 0 , V_45 -> V_50 , V_11 ) ;
memcpy ( V_47 , V_45 -> V_48 . V_49 , V_45 -> V_50 ) ;
}
