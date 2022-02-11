static inline int F_1 ( struct V_1 * V_2 ,
const struct V_3 T_1 * V_4 )
{
if ( ! F_2 ( V_5 , V_4 , sizeof *V_4 ) )
return - V_6 ;
return F_3 ( V_2 -> V_7 , & V_4 -> V_7 )
| F_3 ( V_2 -> V_8 , & V_4 -> V_8 )
| F_3 ( V_2 -> V_9 , & V_4 -> V_9 )
| F_3 ( V_2 -> V_10 , & V_4 -> V_10 ) ;
}
static inline int F_4 ( const struct V_1 * V_2 ,
struct V_3 T_1 * V_4 )
{
if ( F_5 ( V_4 , sizeof *V_4 ) )
return - V_6 ;
return F_6 ( V_2 -> V_7 , & V_4 -> V_7 )
| F_6 ( V_2 -> V_8 , & V_4 -> V_8 )
| F_6 ( V_2 -> V_9 , & V_4 -> V_9 )
| F_6 ( V_2 -> V_10 , & V_4 -> V_10 ) ;
}
T_2 long F_7 ( const char T_1 * V_11 ,
int V_12 , T_3 V_13 ,
struct V_3 T_1 * V_14 )
{
void T_1 * V_15 = NULL ;
if ( V_14 && V_12 & V_16 ) {
struct V_1 V_2 ;
memset ( & V_2 , 0 , sizeof( V_2 ) ) ;
V_15 = F_8 ( sizeof( V_2 ) ) ;
if ( F_1 ( & V_2 , V_14 ) ||
F_9 ( V_15 , & V_2 , sizeof( V_2 ) ) )
return - V_6 ;
}
return F_10 ( V_11 , V_12 , V_13 , V_15 ) ;
}
static int F_11 ( struct V_17 T_1 * * V_15 ,
const struct V_18 T_1 * V_19 )
{
struct V_17 V_20 ;
if ( ! V_19 ) {
* V_15 = NULL ;
return 0 ;
}
* V_15 = F_8 ( sizeof( V_20 ) ) ;
if ( F_12 ( & V_20 , V_19 ) || F_9 ( * V_15 , & V_20 , sizeof( V_20 ) ) )
return - V_6 ;
return 0 ;
}
T_2 long F_13 ( T_4 V_21 ,
const char T_1 * V_22 ,
T_5 V_23 , unsigned int V_24 ,
const struct V_18 T_1 * V_25 )
{
struct V_17 T_1 * V_26 ;
if ( F_11 ( & V_26 , V_25 ) )
return - V_6 ;
return F_14 ( V_21 , V_22 , V_23 ,
V_24 , V_26 ) ;
}
T_2 T_6 F_15 ( T_4 V_21 ,
char T_1 * V_22 ,
T_5 V_23 , unsigned int T_1 * V_27 ,
const struct V_18 T_1 * V_25 )
{
struct V_17 T_1 * V_26 ;
if ( F_11 ( & V_26 , V_25 ) )
return - V_6 ;
return F_16 ( V_21 , V_22 , V_23 ,
V_27 , V_26 ) ;
}
T_2 long F_17 ( T_4 V_21 ,
const struct V_28 T_1 * V_29 )
{
struct V_30 T_1 * V_15 = NULL ;
if ( V_29 ) {
struct V_30 V_31 ;
V_15 = F_8 ( sizeof( * V_15 ) ) ;
if ( F_18 ( & V_31 , V_29 ) )
return - V_6 ;
if ( V_31 . V_32 == V_33 )
V_31 . V_34 . V_35 = F_19 ( V_31 . V_34 . V_36 ) ;
if ( F_9 ( V_15 , & V_31 , sizeof( * V_15 ) ) )
return - V_6 ;
}
return F_20 ( V_21 , V_15 ) ;
}
T_2 long F_21 ( T_4 V_21 ,
const struct V_3 T_1 * V_37 ,
struct V_3 T_1 * V_38 )
{
struct V_1 V_39 ;
struct V_1 T_1 * V_15 = F_8 ( 2 * sizeof( * V_15 ) ) ;
long V_40 ;
memset ( & V_39 , 0 , sizeof( V_39 ) ) ;
if ( V_37 ) {
if ( F_1 ( & V_39 , V_37 ) ||
F_9 ( V_15 , & V_39 , sizeof( V_39 ) ) )
return - V_6 ;
}
V_40 = F_22 ( V_21 ,
V_37 ? V_15 : NULL ,
V_38 ? V_15 + 1 : NULL ) ;
if ( V_40 )
return V_40 ;
if ( V_38 ) {
if ( F_23 ( & V_39 , V_15 + 1 , sizeof( V_39 ) ) ||
F_4 ( & V_39 , V_38 ) )
return - V_6 ;
}
return 0 ;
}
