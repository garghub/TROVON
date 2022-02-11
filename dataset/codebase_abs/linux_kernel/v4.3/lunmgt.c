static struct V_1 * F_1 ( struct V_2 * V_3 , T_1 * V_4 )
{
struct V_1 * V_5 = NULL ;
V_5 = F_2 ( sizeof( * V_5 ) , V_6 ) ;
if ( F_3 ( ! V_5 ) ) {
F_4 ( L_1 , V_7 ) ;
goto V_8;
}
V_5 -> V_3 = V_3 ;
V_5 -> V_9 = true ;
V_5 -> V_10 = V_3 -> V_11 -> V_10 ;
V_5 -> V_12 = false ;
memcpy ( V_5 -> V_4 , V_4 , V_13 ) ;
V_8:
return V_5 ;
}
static struct V_14 * F_5 ( struct V_2 * V_3 , T_1 * V_4 )
{
struct V_14 * V_15 = NULL ;
V_15 = F_2 ( sizeof( * V_15 ) , V_6 ) ;
if ( F_3 ( ! V_15 ) ) {
F_4 ( L_2 , V_7 ) ;
goto V_8;
}
F_6 ( & V_15 -> V_16 ) ;
memcpy ( V_15 -> V_4 , V_4 , V_13 ) ;
V_8:
return V_15 ;
}
static struct V_1 * F_7 ( struct V_17 * V_18 , T_1 * V_4 )
{
struct V_1 * V_5 , * V_19 ;
F_8 (lli, temp, &cfg->lluns, list)
if ( ! memcmp ( V_5 -> V_4 , V_4 , V_13 ) ) {
V_5 -> V_9 = false ;
return V_5 ;
}
return NULL ;
}
static struct V_14 * F_9 ( T_1 * V_4 )
{
struct V_14 * V_15 , * V_19 ;
F_8 (gli, temp, &global.gluns, list)
if ( ! memcmp ( V_15 -> V_4 , V_4 , V_13 ) )
return V_15 ;
return NULL ;
}
static struct V_1 * F_10 ( struct V_2 * V_3 , T_1 * V_4 )
{
struct V_1 * V_5 = NULL ;
struct V_14 * V_15 = NULL ;
struct V_20 * V_21 = V_3 -> V_11 ;
struct V_17 * V_18 = F_11 ( V_21 ) ;
F_12 ( & V_22 . V_16 ) ;
if ( F_3 ( ! V_4 ) )
goto V_8;
V_5 = F_7 ( V_18 , V_4 ) ;
if ( V_5 )
goto V_8;
V_5 = F_1 ( V_3 , V_4 ) ;
if ( F_3 ( ! V_5 ) )
goto V_8;
V_15 = F_9 ( V_4 ) ;
if ( V_15 ) {
V_5 -> V_23 = V_15 ;
F_13 ( & V_5 -> V_24 , & V_18 -> V_25 ) ;
goto V_8;
}
V_15 = F_5 ( V_3 , V_4 ) ;
if ( F_3 ( ! V_15 ) ) {
F_14 ( V_5 ) ;
V_5 = NULL ;
goto V_8;
}
V_5 -> V_23 = V_15 ;
F_13 ( & V_5 -> V_24 , & V_18 -> V_25 ) ;
F_13 ( & V_15 -> V_24 , & V_22 . V_26 ) ;
V_8:
F_15 ( & V_22 . V_16 ) ;
F_16 ( L_3 , V_7 , V_5 ) ;
return V_5 ;
}
void F_17 ( struct V_17 * V_18 )
{
struct V_1 * V_5 , * V_19 ;
F_12 ( & V_22 . V_16 ) ;
F_8 (lli, temp, &cfg->lluns, list) {
F_18 ( & V_5 -> V_24 ) ;
F_14 ( V_5 ) ;
}
F_15 ( & V_22 . V_16 ) ;
}
void F_19 ( void )
{
F_20 ( & V_22 . V_26 ) ;
F_6 ( & V_22 . V_16 ) ;
V_22 . V_27 = NULL ;
}
void F_21 ( void )
{
struct V_14 * V_15 , * V_19 ;
F_12 ( & V_22 . V_16 ) ;
F_8 (gli, temp, &global.gluns, list) {
F_18 ( & V_15 -> V_24 ) ;
F_22 ( & V_15 -> V_28 . V_29 ) ;
F_14 ( V_15 ) ;
}
F_15 ( & V_22 . V_16 ) ;
}
int F_23 ( struct V_2 * V_3 ,
struct V_30 * V_31 )
{
int V_32 = 0 ;
struct V_1 * V_5 = NULL ;
T_2 V_33 = V_31 -> V_34 . V_33 ;
T_3 V_35 = V_3 -> V_36 ;
V_5 = F_10 ( V_3 , V_31 -> V_4 ) ;
F_16 ( L_4 ,
V_7 , F_24 ( & V_31 -> V_4 [ 0 ] ) ,
F_24 ( & V_31 -> V_4 [ 8 ] ) ,
V_31 -> V_34 . V_33 , V_5 ) ;
if ( F_3 ( ! V_5 ) ) {
V_32 = - V_37 ;
goto V_8;
}
if ( V_33 & V_38 ) {
if ( V_5 -> V_9 )
V_5 -> V_39 = F_25 ( V_35 ) ;
else
V_5 -> V_39 = V_40 ;
V_5 -> V_41 [ V_35 ] = F_26 ( V_3 -> V_42 ) ;
V_3 -> V_43 = V_5 ;
} else if ( V_33 & V_44 ) {
if ( V_5 -> V_23 -> V_45 != V_46 )
V_32 = - V_47 ;
else
V_3 -> V_43 = NULL ;
}
V_8:
F_16 ( L_5 , V_7 , V_32 ) ;
return V_32 ;
}
