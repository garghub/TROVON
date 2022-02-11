static struct V_1 * F_1 ( struct V_2 * V_3 , T_1 * V_4 )
{
struct V_1 * V_5 = NULL ;
V_5 = F_2 ( sizeof( * V_5 ) , V_6 ) ;
if ( F_3 ( ! V_5 ) ) {
F_4 ( L_1 , V_7 ) ;
goto V_8;
}
V_5 -> V_3 = V_3 ;
V_5 -> V_9 = V_3 -> V_10 -> V_9 ;
V_5 -> V_11 = false ;
memcpy ( V_5 -> V_4 , V_4 , V_12 ) ;
V_8:
return V_5 ;
}
static struct V_13 * F_5 ( struct V_2 * V_3 , T_1 * V_4 )
{
struct V_13 * V_14 = NULL ;
V_14 = F_2 ( sizeof( * V_14 ) , V_6 ) ;
if ( F_3 ( ! V_14 ) ) {
F_4 ( L_2 , V_7 ) ;
goto V_8;
}
F_6 ( & V_14 -> V_15 ) ;
memcpy ( V_14 -> V_4 , V_4 , V_12 ) ;
V_8:
return V_14 ;
}
static struct V_1 * F_7 ( struct V_16 * V_17 , T_1 * V_4 )
{
struct V_1 * V_5 , * V_18 ;
F_8 (lli, temp, &cfg->lluns, list)
if ( ! memcmp ( V_5 -> V_4 , V_4 , V_12 ) )
return V_5 ;
return NULL ;
}
static struct V_13 * F_9 ( T_1 * V_4 )
{
struct V_13 * V_14 , * V_18 ;
F_8 (gli, temp, &global.gluns, list)
if ( ! memcmp ( V_14 -> V_4 , V_4 , V_12 ) )
return V_14 ;
return NULL ;
}
static struct V_1 * F_10 ( struct V_2 * V_3 , T_1 * V_4 )
{
struct V_1 * V_5 = NULL ;
struct V_13 * V_14 = NULL ;
struct V_19 * V_20 = V_3 -> V_10 ;
struct V_16 * V_17 = F_11 ( V_20 ) ;
if ( F_3 ( ! V_4 ) )
goto V_8;
V_5 = F_7 ( V_17 , V_4 ) ;
if ( V_5 )
goto V_8;
V_5 = F_1 ( V_3 , V_4 ) ;
if ( F_3 ( ! V_5 ) )
goto V_8;
V_14 = F_9 ( V_4 ) ;
if ( V_14 ) {
V_5 -> V_21 = V_14 ;
F_12 ( & V_5 -> V_22 , & V_17 -> V_23 ) ;
goto V_8;
}
V_14 = F_5 ( V_3 , V_4 ) ;
if ( F_3 ( ! V_14 ) ) {
F_13 ( V_5 ) ;
V_5 = NULL ;
goto V_8;
}
V_5 -> V_21 = V_14 ;
F_12 ( & V_5 -> V_22 , & V_17 -> V_23 ) ;
F_12 ( & V_14 -> V_22 , & V_24 . V_25 ) ;
V_8:
F_14 ( L_3 , V_7 , V_5 ) ;
return V_5 ;
}
void F_15 ( struct V_16 * V_17 )
{
struct V_1 * V_5 , * V_18 ;
F_16 ( & V_24 . V_15 ) ;
F_8 (lli, temp, &cfg->lluns, list) {
F_17 ( & V_5 -> V_22 ) ;
F_13 ( V_5 ) ;
}
F_18 ( & V_24 . V_15 ) ;
}
void F_19 ( void )
{
F_20 ( & V_24 . V_25 ) ;
F_6 ( & V_24 . V_15 ) ;
V_24 . V_26 = NULL ;
}
void F_21 ( void )
{
struct V_13 * V_14 , * V_18 ;
F_16 ( & V_24 . V_15 ) ;
F_8 (gli, temp, &global.gluns, list) {
F_17 ( & V_14 -> V_22 ) ;
F_22 ( & V_14 -> V_27 . V_28 ) ;
F_13 ( V_14 ) ;
}
F_18 ( & V_24 . V_15 ) ;
}
int F_23 ( struct V_2 * V_3 ,
struct V_29 * V_30 )
{
int V_31 = 0 ;
struct V_1 * V_5 = NULL ;
T_2 V_32 = V_30 -> V_33 . V_32 ;
T_3 V_34 = V_3 -> V_35 ;
F_16 ( & V_24 . V_15 ) ;
V_5 = F_10 ( V_3 , V_30 -> V_4 ) ;
F_14 ( L_4 ,
V_7 , F_24 ( & V_30 -> V_4 [ 0 ] ) ,
F_24 ( & V_30 -> V_4 [ 8 ] ) ,
V_30 -> V_33 . V_32 , V_5 ) ;
if ( F_3 ( ! V_5 ) ) {
V_31 = - V_36 ;
goto V_8;
}
if ( V_32 & V_37 ) {
V_5 -> V_38 |= F_25 ( V_34 ) ;
V_5 -> V_39 [ V_34 ] = F_26 ( V_3 -> V_40 ) ;
V_3 -> V_41 = V_5 ;
} else if ( V_32 & V_42 ) {
if ( V_5 -> V_21 -> V_43 != V_44 )
V_31 = - V_45 ;
else {
V_3 -> V_41 = NULL ;
V_5 -> V_38 &= ~ F_25 ( V_34 ) ;
if ( V_5 -> V_38 == 0U )
V_5 -> V_11 = false ;
}
}
F_14 ( L_5 , V_7 ,
V_5 -> V_38 , V_34 , V_5 -> V_39 [ V_34 ] ) ;
V_8:
F_18 ( & V_24 . V_15 ) ;
F_14 ( L_6 , V_7 , V_31 ) ;
return V_31 ;
}
