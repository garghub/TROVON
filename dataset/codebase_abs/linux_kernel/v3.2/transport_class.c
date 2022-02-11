int F_1 ( struct V_1 * V_2 )
{
return F_2 ( & V_2 -> V_3 ) ;
}
void F_3 ( struct V_1 * V_2 )
{
F_4 ( & V_2 -> V_3 ) ;
}
static int F_5 ( struct V_4 * V_5 ,
struct V_6 * V_7 ,
struct V_6 * V_8 )
{
return 0 ;
}
int F_6 ( struct V_9 * V_10 )
{
int error ;
V_10 -> V_11 . V_3 = & V_10 -> V_2 . V_3 ;
F_7 ( & V_10 -> V_11 ) ;
error = F_8 ( & V_10 -> V_11 ) ;
if ( error )
return error ;
V_10 -> V_2 . V_12 = F_5 ;
V_10 -> V_2 . remove = F_5 ;
return 0 ;
}
void F_9 ( struct V_9 * V_10 )
{
if ( F_10 ( F_11 ( & V_10 -> V_11 ) ) )
F_12 () ;
}
static int F_13 ( struct V_13 * V_14 ,
struct V_6 * V_7 ,
struct V_6 * V_15 )
{
struct V_1 * V_2 = F_14 ( V_14 -> V_3 ) ;
struct V_4 * V_16 = F_15 ( V_14 ) ;
if ( V_2 -> V_12 )
V_2 -> V_12 ( V_16 , V_7 , V_15 ) ;
return 0 ;
}
void F_16 ( struct V_6 * V_7 )
{
F_17 ( V_7 , F_13 ) ;
}
static int F_18 ( struct V_13 * V_14 ,
struct V_6 * V_7 ,
struct V_6 * V_15 )
{
int error = F_19 ( V_15 ) ;
struct V_4 * V_16 =
F_15 ( V_14 ) ;
if ( ! error && V_16 -> V_17 )
error = F_20 ( & V_15 -> V_18 , V_16 -> V_17 ) ;
return error ;
}
void F_21 ( struct V_6 * V_7 )
{
F_22 ( V_7 , F_18 ) ;
}
static int F_23 ( struct V_13 * V_14 ,
struct V_6 * V_7 ,
struct V_6 * V_8 )
{
struct V_1 * V_2 = F_14 ( V_14 -> V_3 ) ;
struct V_4 * V_16 = F_15 ( V_14 ) ;
if ( V_2 -> V_19 )
V_2 -> V_19 ( V_16 , V_7 , V_8 ) ;
return 0 ;
}
void F_24 ( struct V_6 * V_7 )
{
F_22 ( V_7 , F_23 ) ;
}
static int F_25 ( struct V_13 * V_14 ,
struct V_6 * V_7 ,
struct V_6 * V_15 )
{
struct V_4 * V_16 =
F_15 ( V_14 ) ;
struct V_1 * V_2 = F_14 ( V_14 -> V_3 ) ;
if ( V_2 -> remove )
V_2 -> remove ( V_16 , V_7 , V_15 ) ;
if ( V_2 -> remove != F_5 ) {
if ( V_16 -> V_17 )
F_26 ( & V_15 -> V_18 , V_16 -> V_17 ) ;
F_27 ( V_15 ) ;
}
return 0 ;
}
void F_28 ( struct V_6 * V_7 )
{
F_22 ( V_7 , F_25 ) ;
}
static void F_29 ( struct V_13 * V_14 ,
struct V_6 * V_7 ,
struct V_6 * V_15 )
{
struct V_1 * V_2 = F_14 ( V_14 -> V_3 ) ;
if ( V_2 -> remove != F_5 )
F_30 ( V_15 ) ;
}
void F_31 ( struct V_6 * V_7 )
{
F_32 ( V_7 , F_29 ) ;
}
