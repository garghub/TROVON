void F_1 ( struct V_1 * V_2 )
{
F_2 ( & V_2 -> V_3 ) ;
}
int F_3 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_6 ;
if ( V_2 -> V_7 ) {
V_6 = F_4 ( & V_2 -> V_7 -> V_8 ,
& V_5 -> V_9 . V_10 . V_8 , L_1 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_4 ( & V_5 -> V_9 . V_10 . V_8 ,
& V_2 -> V_7 -> V_8 , V_2 -> V_11 ) ;
if ( V_6 < 0 ) {
F_5 ( & V_2 -> V_7 -> V_8 , L_1 ) ;
return V_6 ;
}
}
V_2 -> V_12 = F_6 ( V_2 ) ;
F_7 ( & V_5 -> V_9 . V_13 ) ;
F_8 ( & V_2 -> V_3 , & V_5 -> V_14 ) ;
F_9 ( & V_5 -> V_9 . V_13 ) ;
return 0 ;
}
static int F_10 ( struct V_7 * V_10 , const void * V_15 )
{
const struct V_4 * V_16 = V_15 ;
struct V_4 * V_5 = F_11 ( V_10 ) ;
if ( V_5 == NULL ) {
F_12 ( 1 ) ;
return 0 ;
}
if ( V_5 == V_16 ) {
if ( V_5 -> V_17 == 0 )
return 0 ;
else
return 1 ;
}
return 0 ;
}
static bool F_13 ( struct V_4 * V_16 )
{
struct V_7 * V_10 ;
V_10 = F_14 ( & V_18 , NULL , V_16 , F_10 ) ;
F_15 ( V_10 ) ;
return ( V_10 != NULL ) ;
}
void F_16 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
F_17 ( V_2 ) ;
F_7 ( & V_5 -> V_9 . V_13 ) ;
F_18 ( & V_2 -> V_3 ) ;
F_9 ( & V_5 -> V_9 . V_13 ) ;
F_19 ( V_2 -> V_12 ) ;
if ( V_2 -> V_7 ) {
if ( F_13 ( V_5 ) )
F_5 ( & V_5 -> V_9 . V_10 . V_8 , V_2 -> V_11 ) ;
F_5 ( & V_2 -> V_7 -> V_8 , L_1 ) ;
}
}
void F_20 ( struct V_4 * V_5 )
{
F_2 ( & V_5 -> V_14 ) ;
}
