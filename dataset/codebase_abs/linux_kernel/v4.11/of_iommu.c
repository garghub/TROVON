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
static int F_7 ( struct V_20 * V_21 , T_5 V_22 , void * V_23 )
{
struct V_24 * V_25 = V_23 ;
V_25 -> args [ 0 ] = V_22 ;
return V_25 -> V_26 == V_21 -> V_27 -> V_28 . V_29 ;
}
static const struct V_30
* F_8 ( struct V_20 * V_21 , struct V_1 * V_31 )
{
const struct V_30 * V_32 ;
struct V_24 V_25 ;
V_25 . V_33 = 1 ;
V_25 . V_26 = V_31 ;
F_9 ( V_21 , F_7 , & V_25 ) ;
V_25 . V_26 = NULL ;
if ( F_10 ( V_31 , V_25 . args [ 0 ] , L_6 ,
L_7 , & V_25 . V_26 , V_25 . args ) )
return NULL ;
V_32 = F_11 ( & V_25 . V_26 -> V_34 ) ;
if ( ! V_32 || ! V_32 -> V_35 ||
F_12 ( & V_21 -> V_28 , & V_25 . V_26 -> V_34 , V_32 ) ||
V_32 -> V_35 ( & V_21 -> V_28 , & V_25 ) )
V_32 = NULL ;
F_13 ( V_25 . V_26 ) ;
return V_32 ;
}
const struct V_30 * F_14 ( struct V_36 * V_28 ,
struct V_1 * V_37 )
{
struct V_24 V_25 ;
struct V_1 * V_26 ;
const struct V_30 * V_32 = NULL ;
int V_38 = 0 ;
if ( F_15 ( V_28 ) )
return F_8 ( F_16 ( V_28 ) , V_37 ) ;
while ( ! F_17 ( V_37 , L_8 ,
L_9 , V_38 ,
& V_25 ) ) {
V_26 = V_25 . V_26 ;
V_32 = F_11 ( & V_26 -> V_34 ) ;
if ( ! V_32 || ! V_32 -> V_35 ||
F_12 ( V_28 , & V_26 -> V_34 , V_32 ) ||
V_32 -> V_35 ( V_28 , & V_25 ) )
goto V_39;
F_13 ( V_26 ) ;
V_38 ++ ;
}
return V_32 ;
V_39:
F_13 ( V_26 ) ;
return NULL ;
}
static int T_6 F_18 ( void )
{
struct V_1 * V_26 ;
const struct V_40 * V_41 , * V_42 = & V_43 ;
F_19 (np, matches, &match) {
const T_7 V_44 = V_41 -> V_23 ;
if ( V_44 ( V_26 ) )
F_20 ( L_10 ,
F_21 ( V_26 ) ) ;
}
return 0 ;
}
