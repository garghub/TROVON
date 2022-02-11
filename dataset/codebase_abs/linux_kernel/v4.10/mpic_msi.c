void F_1 ( struct V_1 * V_1 , T_1 V_2 )
{
if ( ! V_1 -> V_3 . V_4 )
return;
F_2 ( & V_1 -> V_3 , V_2 ) ;
}
static int F_3 ( struct V_1 * V_1 )
{
T_1 V_2 ;
const struct V_5 * V_6 = V_1 -> V_7 -> V_6 ;
struct V_8 * V_9 ;
int V_10 , V_11 , V_12 ;
struct V_13 V_14 ;
F_4 ( L_1 ) ;
for ( V_12 = 0 ; V_12 < 8 ; V_12 ++ )
F_2 ( & V_1 -> V_3 , V_12 ) ;
for ( V_12 = 42 ; V_12 < 46 ; V_12 ++ )
F_2 ( & V_1 -> V_3 , V_12 ) ;
for ( V_12 = 100 ; V_12 < 105 ; V_12 ++ )
F_2 ( & V_1 -> V_3 , V_12 ) ;
for ( V_12 = 124 ; V_12 < V_1 -> V_15 ; V_12 ++ )
F_2 ( & V_1 -> V_3 , V_12 ) ;
V_9 = NULL ;
while ( ( V_9 = F_5 ( V_9 ) ) ) {
F_4 ( L_2 , V_9 -> V_16 ) ;
V_11 = 0 ;
while ( F_6 ( V_9 , V_11 ++ , & V_14 ) == 0 ) {
V_6 -> V_17 ( V_1 -> V_7 , NULL , V_14 . args ,
V_14 . V_18 , & V_2 , & V_10 ) ;
F_2 ( & V_1 -> V_3 , V_2 ) ;
}
}
return 0 ;
}
static int F_3 ( struct V_1 * V_1 )
{
return - 1 ;
}
int F_7 ( struct V_1 * V_1 )
{
int V_19 ;
V_19 = F_8 ( & V_1 -> V_3 , V_1 -> V_15 ,
F_9 ( V_1 -> V_7 ) ) ;
if ( V_19 )
return V_19 ;
V_19 = F_10 ( & V_1 -> V_3 ) ;
if ( V_19 > 0 ) {
if ( V_1 -> V_10 & V_20 )
V_19 = F_3 ( V_1 ) ;
if ( V_19 ) {
F_11 ( & V_1 -> V_3 ) ;
return V_19 ;
}
}
return 0 ;
}
