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
if ( ! F_14 ( V_11 , V_29 ) )
F_15 ( V_11 , V_30 ) ;
else if ( ! F_11 ( V_11 ) )
F_15 ( V_11 , V_31 ) ;
if ( V_11 -> V_32 )
F_16 ( V_11 ) ;
}
static void
F_17 (
struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_26 -> V_27 ;
struct V_33 * V_34 = V_11 -> V_35 ;
if ( ! F_4 ( & V_2 -> V_5 ) )
return;
if ( ! F_11 ( V_11 ) ) {
F_15 ( V_11 , V_31 ) ;
F_16 ( V_11 ) ;
return;
}
if ( V_34 ) {
struct V_12 * V_13 = V_11 -> V_14 ;
V_13 -> V_36 = F_7 ( V_34 -> V_37 . V_38 ) ;
}
F_18 ( V_11 , V_29 ) ;
}
void
F_19 (
struct V_39 * V_40 ,
struct V_10 * V_11 ,
struct V_41 * V_42 ,
struct V_43 * V_44 )
{
struct V_1 * V_2 = V_42 -> V_45 ;
char * V_46 ;
if ( ! F_4 ( & V_2 -> V_5 ) ) {
V_11 -> V_24 = NULL ;
memcpy ( V_11 -> V_14 , V_44 -> V_47 . V_48 , V_44 -> V_49 ) ;
return;
}
ASSERT ( F_20 ( V_11 -> V_50 ) >=
V_44 -> V_49 + sizeof( struct V_12 ) ) ;
V_11 -> V_24 = & V_25 ;
V_46 = V_11 -> V_14 ;
V_46 += F_3 ( V_2 , V_42 -> V_51 , 0 , V_44 -> V_49 , V_11 ) ;
memcpy ( V_46 , V_44 -> V_47 . V_48 , V_44 -> V_49 ) ;
}
