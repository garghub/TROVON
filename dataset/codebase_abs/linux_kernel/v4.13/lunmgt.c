static struct V_1 * F_1 ( struct V_2 * V_3 , T_1 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_3 -> V_7 ) ;
struct V_8 * V_9 = & V_6 -> V_9 -> V_9 ;
struct V_1 * V_10 = NULL ;
V_10 = F_3 ( sizeof( * V_10 ) , V_11 ) ;
if ( F_4 ( ! V_10 ) ) {
F_5 ( V_9 , L_1 , V_12 ) ;
goto V_13;
}
V_10 -> V_3 = V_3 ;
V_10 -> V_14 = V_3 -> V_7 -> V_14 ;
V_10 -> V_15 = false ;
memcpy ( V_10 -> V_4 , V_4 , V_16 ) ;
V_13:
return V_10 ;
}
static struct V_17 * F_6 ( struct V_2 * V_3 , T_1 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_3 -> V_7 ) ;
struct V_8 * V_9 = & V_6 -> V_9 -> V_9 ;
struct V_17 * V_18 = NULL ;
V_18 = F_3 ( sizeof( * V_18 ) , V_11 ) ;
if ( F_4 ( ! V_18 ) ) {
F_5 ( V_9 , L_2 , V_12 ) ;
goto V_13;
}
F_7 ( & V_18 -> V_19 ) ;
memcpy ( V_18 -> V_4 , V_4 , V_16 ) ;
V_13:
return V_18 ;
}
static struct V_1 * F_8 ( struct V_5 * V_6 , T_1 * V_4 )
{
struct V_1 * V_10 , * V_20 ;
F_9 (lli, temp, &cfg->lluns, list)
if ( ! memcmp ( V_10 -> V_4 , V_4 , V_16 ) )
return V_10 ;
return NULL ;
}
static struct V_17 * F_10 ( T_1 * V_4 )
{
struct V_17 * V_18 , * V_20 ;
F_9 (gli, temp, &global.gluns, list)
if ( ! memcmp ( V_18 -> V_4 , V_4 , V_16 ) )
return V_18 ;
return NULL ;
}
static struct V_1 * F_11 ( struct V_2 * V_3 , T_1 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_3 -> V_7 ) ;
struct V_8 * V_9 = & V_6 -> V_9 -> V_9 ;
struct V_1 * V_10 = NULL ;
struct V_17 * V_18 = NULL ;
if ( F_4 ( ! V_4 ) )
goto V_13;
V_10 = F_8 ( V_6 , V_4 ) ;
if ( V_10 )
goto V_13;
V_10 = F_1 ( V_3 , V_4 ) ;
if ( F_4 ( ! V_10 ) )
goto V_13;
V_18 = F_10 ( V_4 ) ;
if ( V_18 ) {
V_10 -> V_21 = V_18 ;
F_12 ( & V_10 -> V_22 , & V_6 -> V_23 ) ;
goto V_13;
}
V_18 = F_6 ( V_3 , V_4 ) ;
if ( F_4 ( ! V_18 ) ) {
F_13 ( V_10 ) ;
V_10 = NULL ;
goto V_13;
}
V_10 -> V_21 = V_18 ;
F_12 ( & V_10 -> V_22 , & V_6 -> V_23 ) ;
F_12 ( & V_18 -> V_22 , & V_24 . V_25 ) ;
V_13:
F_14 ( V_9 , L_3 , V_12 , V_10 , V_18 ) ;
return V_10 ;
}
void F_15 ( struct V_5 * V_6 )
{
struct V_1 * V_10 , * V_20 ;
F_16 ( & V_24 . V_19 ) ;
F_9 (lli, temp, &cfg->lluns, list) {
F_17 ( & V_10 -> V_22 ) ;
F_13 ( V_10 ) ;
}
F_18 ( & V_24 . V_19 ) ;
}
void F_19 ( void )
{
F_20 ( & V_24 . V_25 ) ;
F_7 ( & V_24 . V_19 ) ;
V_24 . V_26 = NULL ;
}
void F_21 ( void )
{
struct V_17 * V_18 , * V_20 ;
F_16 ( & V_24 . V_19 ) ;
F_9 (gli, temp, &global.gluns, list) {
F_17 ( & V_18 -> V_22 ) ;
F_22 ( & V_18 -> V_27 . V_28 ) ;
F_13 ( V_18 ) ;
}
F_18 ( & V_24 . V_19 ) ;
}
int F_23 ( struct V_2 * V_3 ,
struct V_29 * V_30 )
{
struct V_5 * V_6 = F_2 ( V_3 -> V_7 ) ;
struct V_8 * V_9 = & V_6 -> V_9 -> V_9 ;
struct V_1 * V_10 = NULL ;
int V_31 = 0 ;
T_2 V_32 = V_30 -> V_33 . V_32 ;
T_3 V_34 = V_3 -> V_35 ;
F_16 ( & V_24 . V_19 ) ;
V_10 = F_11 ( V_3 , V_30 -> V_4 ) ;
F_14 ( V_9 , L_4 ,
V_12 , F_24 ( & V_30 -> V_4 [ 0 ] ) ,
F_24 ( & V_30 -> V_4 [ 8 ] ) , V_30 -> V_33 . V_32 , V_10 ) ;
if ( F_4 ( ! V_10 ) ) {
V_31 = - V_36 ;
goto V_13;
}
if ( V_32 & V_37 ) {
V_10 -> V_38 |= F_25 ( V_34 ) ;
V_10 -> V_39 [ V_34 ] = F_26 ( V_3 -> V_40 ) ;
V_3 -> V_41 = V_10 ;
} else if ( V_32 & V_42 ) {
if ( V_10 -> V_21 -> V_43 != V_44 )
V_31 = - V_45 ;
else {
V_3 -> V_41 = NULL ;
V_10 -> V_38 &= ~ F_25 ( V_34 ) ;
if ( V_10 -> V_38 == 0U )
V_10 -> V_15 = false ;
}
}
F_14 ( V_9 , L_5 ,
V_12 , V_10 -> V_38 , V_34 , V_10 -> V_39 [ V_34 ] ) ;
V_13:
F_18 ( & V_24 . V_19 ) ;
F_14 ( V_9 , L_6 , V_12 , V_31 ) ;
return V_31 ;
}
