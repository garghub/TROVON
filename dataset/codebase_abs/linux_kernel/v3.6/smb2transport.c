static inline void
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
V_4 -> V_5 = F_2 ( V_2 ) ;
}
static struct V_6 *
F_3 ( const struct V_3 * V_7 ,
struct V_1 * V_2 )
{
struct V_6 * V_8 ;
if ( V_2 == NULL ) {
F_4 ( 1 , L_1 ) ;
return NULL ;
}
V_8 = F_5 ( V_9 , V_10 ) ;
if ( V_8 == NULL )
return V_8 ;
else {
memset ( V_8 , 0 , sizeof( struct V_6 ) ) ;
V_8 -> V_11 = V_7 -> V_5 ;
V_8 -> V_12 = V_13 -> V_12 ;
V_8 -> V_14 = V_7 -> V_15 ;
V_8 -> V_16 = V_17 ;
V_8 -> V_2 = V_2 ;
V_8 -> V_18 = V_19 ;
V_8 -> V_20 = V_13 ;
}
F_6 ( & V_21 ) ;
V_8 -> V_22 = V_23 ;
return V_8 ;
}
static int
F_7 ( struct V_24 * V_25 , struct V_3 * V_26 ,
struct V_6 * * V_11 )
{
if ( V_25 -> V_2 -> V_27 == V_28 )
return - V_29 ;
if ( V_25 -> V_2 -> V_27 == V_30 ) {
F_8 ( 1 , L_2 ) ;
return - V_31 ;
}
if ( V_25 -> V_32 != V_33 ) {
if ( ( V_26 -> V_15 != V_34 ) &&
( V_26 -> V_15 != V_35 ) )
return - V_31 ;
}
* V_11 = F_3 ( V_26 , V_25 -> V_2 ) ;
if ( * V_11 == NULL )
return - V_36 ;
F_9 ( & V_37 ) ;
F_10 ( & ( * V_11 ) -> V_38 , & V_25 -> V_2 -> V_39 ) ;
F_11 ( & V_37 ) ;
return 0 ;
}
int
F_12 ( struct V_6 * V_11 , struct V_1 * V_2 ,
bool V_40 )
{
unsigned int V_41 = F_13 ( V_11 -> V_42 ) ;
F_14 ( V_11 -> V_42 , F_15 ( V_43 , 80 , V_41 ) ) ;
return F_16 ( V_11 -> V_42 , V_40 ) ;
}
int
F_17 ( struct V_24 * V_25 , struct V_44 * V_45 ,
unsigned int V_46 , struct V_6 * * V_47 )
{
int V_48 ;
struct V_3 * V_4 = (struct V_3 * ) V_45 [ 0 ] . V_49 ;
struct V_6 * V_11 ;
F_1 ( V_25 -> V_2 , V_4 ) ;
V_48 = F_7 ( V_25 , V_4 , & V_11 ) ;
if ( V_48 )
return V_48 ;
* V_47 = V_11 ;
return V_48 ;
}
int
F_18 ( struct V_1 * V_2 , struct V_44 * V_45 ,
unsigned int V_46 , struct V_6 * * V_47 )
{
int V_48 = 0 ;
struct V_3 * V_4 = (struct V_3 * ) V_45 [ 0 ] . V_49 ;
struct V_6 * V_11 ;
F_1 ( V_2 , V_4 ) ;
V_11 = F_3 ( V_4 , V_2 ) ;
if ( V_11 == NULL )
return - V_36 ;
* V_47 = V_11 ;
return V_48 ;
}
