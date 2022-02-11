int F_1 ( struct V_1 * V_2 , const char * V_3 , int V_4 ,
unsigned long * V_5 , T_1 * V_6 , T_2 * V_7 )
{
const T_3 * V_8 , * V_9 ;
int V_10 , V_11 = 0 ;
char V_12 [ V_13 ] , V_14 [ V_13 ] , V_15 [ V_13 ] ;
if ( ! V_2 || ! V_6 || ! V_7 )
return - V_16 ;
if ( ! V_3 )
V_3 = L_1 ;
snprintf ( V_12 , sizeof( V_12 ) , L_2 , V_3 ) ;
snprintf ( V_14 , sizeof( V_14 ) , L_3 , V_3 ) ;
snprintf ( V_15 , sizeof( V_15 ) , L_4 , V_3 ) ;
V_8 = F_2 ( V_2 , V_12 , & V_10 ) ;
if ( ! V_8 )
return - V_17 ;
V_9 = V_8 + V_10 / sizeof( * V_8 ) ;
while ( V_8 < V_9 ) {
T_4 V_18 ;
const void * V_19 ;
if ( V_5 )
* V_5 = F_3 ( V_8 ++ ) ;
V_19 = F_2 ( V_2 , V_14 , NULL ) ;
if ( ! V_19 )
V_19 = F_2 ( V_2 , L_5 , NULL ) ;
V_18 = V_19 ? F_3 ( V_19 ) : F_4 ( V_2 ) ;
if ( ! V_18 )
return - V_16 ;
* V_6 = F_5 ( V_8 , V_18 ) ;
V_8 += V_18 ;
V_19 = F_2 ( V_2 , V_15 , NULL ) ;
V_18 = V_19 ? F_3 ( V_19 ) : F_6 ( V_2 ) ;
if ( ! V_18 )
return - V_16 ;
* V_7 = F_5 ( V_8 , V_18 ) ;
V_8 += V_18 ;
if ( V_11 ++ == V_4 )
break;
}
return 0 ;
}
static bool F_7 ( struct V_1 * V_20 )
{
if ( V_21 > V_22 )
return false ;
return F_8 ( & V_23 , V_20 ) ;
}
static const struct V_24
* F_9 ( struct V_25 * V_26 , struct V_27 * V_28 )
{
const struct V_24 * V_29 ;
struct V_30 * V_31 = & V_28 -> V_20 -> V_31 ;
int V_32 ;
V_29 = F_10 ( V_31 ) ;
if ( ( V_29 && ! V_29 -> V_33 ) ||
! F_11 ( V_28 -> V_20 ) ||
( ! V_29 && ! F_7 ( V_28 -> V_20 ) ) )
return NULL ;
V_32 = F_12 ( V_26 , & V_28 -> V_20 -> V_31 , V_29 ) ;
if ( V_32 )
return F_13 ( V_32 ) ;
if ( ! V_29 )
return F_13 ( - V_34 ) ;
V_32 = V_29 -> V_33 ( V_26 , V_28 ) ;
if ( V_32 )
return F_13 ( V_32 ) ;
return V_29 ;
}
static int F_14 ( struct V_35 * V_36 , T_5 V_37 , void * V_38 )
{
struct V_27 * V_28 = V_38 ;
V_28 -> args [ 0 ] = V_37 ;
return V_28 -> V_20 == V_36 -> V_39 -> V_26 . V_40 ;
}
static const struct V_24
* F_15 ( struct V_35 * V_36 , struct V_1 * V_41 )
{
const struct V_24 * V_29 ;
struct V_27 V_28 ;
int V_32 ;
V_28 . V_42 = 1 ;
V_28 . V_20 = V_41 ;
F_16 ( V_36 , F_14 , & V_28 ) ;
V_28 . V_20 = NULL ;
V_32 = F_17 ( V_41 , V_28 . args [ 0 ] , L_6 ,
L_7 , & V_28 . V_20 ,
V_28 . args ) ;
if ( V_32 )
return V_32 == - V_17 ? NULL : F_13 ( V_32 ) ;
V_29 = F_9 ( & V_36 -> V_26 , & V_28 ) ;
F_18 ( V_28 . V_20 ) ;
return V_29 ;
}
static const struct V_24
* F_19 ( struct V_25 * V_26 , struct V_1 * V_20 )
{
struct V_27 V_28 ;
const struct V_24 * V_29 = NULL ;
int V_43 = 0 ;
while ( ! F_20 ( V_20 , L_8 , L_9 ,
V_43 , & V_28 ) ) {
V_29 = F_9 ( V_26 , & V_28 ) ;
F_18 ( V_28 . V_20 ) ;
V_43 ++ ;
if ( F_21 ( V_29 ) )
break;
}
return V_29 ;
}
const struct V_24 * F_22 ( struct V_25 * V_26 ,
struct V_1 * V_44 )
{
const struct V_24 * V_29 ;
struct V_45 * V_46 = V_26 -> V_45 ;
if ( ! V_44 )
return NULL ;
if ( V_46 ) {
if ( V_46 -> V_29 )
return V_46 -> V_29 ;
F_23 ( V_26 ) ;
}
if ( F_24 ( V_26 ) )
V_29 = F_15 ( F_25 ( V_26 ) , V_44 ) ;
else
V_29 = F_19 ( V_26 , V_44 ) ;
if ( ! F_21 ( V_29 ) && V_29 -> V_47 &&
V_26 -> V_39 && ! V_26 -> V_48 ) {
int V_32 = V_29 -> V_47 ( V_26 ) ;
if ( V_32 )
V_29 = F_13 ( V_32 ) ;
}
if ( F_26 ( V_29 ) && ( F_27 ( V_29 ) != - V_34 ) ) {
F_28 ( V_26 , L_10 , F_27 ( V_29 ) ) ;
V_29 = NULL ;
}
return V_29 ;
}
static int T_6 F_29 ( void )
{
struct V_1 * V_20 ;
const struct V_49 * V_50 , * V_51 = & V_23 ;
F_30 (np, matches, &match) {
const T_7 V_52 = V_50 -> V_38 ;
if ( V_52 && V_52 ( V_20 ) )
F_31 ( L_11 ,
F_32 ( V_20 ) ) ;
}
return 0 ;
}
