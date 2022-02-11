static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
const T_1 V_5 = V_6 | V_7 ;
struct V_8 * V_9 ;
unsigned int V_10 ;
int V_11 ;
V_9 = ( F_2 ( V_4 ) == V_12 )
? ( V_4 -> V_13 ? & V_4 -> V_13 -> V_4 : NULL )
: & V_4 -> V_14 . V_4 ;
if ( V_9 == NULL )
return 0 ;
for ( V_10 = 0 ; V_10 < V_4 -> V_15 ; ++ V_10 ) {
struct V_8 * V_16 ;
struct V_3 * V_17 ;
T_2 V_18 ;
if ( ! ( V_4 -> V_19 [ V_10 ] . V_5 & V_20 ) )
continue;
V_17 = F_3 ( V_2 -> V_21 , V_4 -> V_22 [ V_10 ] ) ;
if ( V_17 == NULL )
return - V_23 ;
V_16 = ( F_2 ( V_17 ) == V_12 )
? ( V_17 -> V_13 ? & V_17 -> V_13 -> V_4 : NULL )
: & V_17 -> V_14 . V_4 ;
if ( V_16 == NULL )
continue;
V_18 = V_17 -> V_15 - 1 ;
V_11 = F_4 ( V_16 , V_18 ,
V_9 , V_10 , V_5 ) ;
if ( V_11 < 0 )
return V_11 ;
}
return 0 ;
}
void F_5 ( struct V_3 * V_4 )
{
if ( F_2 ( V_4 ) != V_12 )
F_6 ( & V_4 -> V_14 . V_4 ) ;
else if ( V_4 -> V_13 != NULL )
F_6 ( & V_4 -> V_13 -> V_4 ) ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_11 ;
if ( F_2 ( V_4 ) != V_12 ) {
F_8 ( & V_4 -> V_14 , & V_24 ) ;
F_9 ( V_4 -> V_14 . V_25 , V_4 -> V_25 ,
sizeof( V_4 -> V_14 . V_25 ) ) ;
V_11 = F_10 ( & V_4 -> V_14 . V_4 ,
V_4 -> V_15 , V_4 -> V_19 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_11 ( & V_2 -> V_21 -> V_13 ,
& V_4 -> V_14 ) ;
} else if ( V_4 -> V_13 != NULL ) {
V_11 = F_10 ( & V_4 -> V_13 -> V_4 ,
V_4 -> V_15 , V_4 -> V_19 ) ;
if ( V_4 -> V_5 & V_26 )
V_4 -> V_13 -> V_4 . V_5 |= V_27 ;
} else
V_11 = 0 ;
return V_11 ;
}
int F_12 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_11 ;
F_13 (entity, &chain->entities, chain) {
V_11 = F_7 ( V_2 , V_4 ) ;
if ( V_11 < 0 ) {
F_14 ( V_28 , L_1
L_2 , V_4 -> V_29 ) ;
return V_11 ;
}
}
F_13 (entity, &chain->entities, chain) {
V_11 = F_1 ( V_2 , V_4 ) ;
if ( V_11 < 0 ) {
F_14 ( V_28 , L_3
L_2 , V_4 -> V_29 ) ;
return V_11 ;
}
}
return 0 ;
}
