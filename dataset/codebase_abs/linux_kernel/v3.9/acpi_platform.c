static int F_1 ( struct V_1 * V_2 )
{
static struct V_3 * V_4 ;
if ( ! V_4 && ! strncmp ( F_2 ( V_2 ) , L_1 , 6 ) ) {
V_4 = F_3 ( L_2 , - 1 , NULL , 0 ) ;
if ( F_4 ( V_4 ) )
return F_5 ( V_4 ) ;
}
return 0 ;
}
static int F_6 ( struct V_1 * V_2 ,
const struct V_5 * V_6 )
{
unsigned long V_7 = V_6 -> V_8 ;
struct V_3 * V_4 = NULL ;
struct V_1 * V_9 ;
struct V_10 V_11 ;
struct V_12 * V_13 ;
struct V_14 V_15 ;
struct V_16 * V_17 ;
int V_18 ;
if ( V_7 & V_19 ) {
int V_20 = F_1 ( V_2 ) ;
if ( V_20 ) {
F_7 ( & V_2 -> V_21 , L_3 ) ;
return V_20 ;
}
}
if ( V_2 -> V_22 )
return 0 ;
F_8 ( & V_15 ) ;
V_18 = F_9 ( V_2 , & V_15 , NULL , NULL ) ;
if ( V_18 <= 0 )
return 0 ;
V_17 = F_10 ( V_18 * sizeof( struct V_16 ) , V_23 ) ;
if ( ! V_17 ) {
F_7 ( & V_2 -> V_21 , L_4 ) ;
F_11 ( & V_15 ) ;
return - V_24 ;
}
V_18 = 0 ;
F_12 (rentry, &resource_list, node)
V_17 [ V_18 ++ ] = V_13 -> V_25 ;
F_11 ( & V_15 ) ;
memset ( & V_11 , 0 , sizeof( V_11 ) ) ;
V_11 . V_26 = NULL ;
V_9 = V_2 -> V_26 ;
if ( V_9 ) {
struct V_27 * V_28 ;
struct V_14 * V_29 ;
F_13 ( & V_9 -> V_30 ) ;
V_29 = & V_9 -> V_31 ;
if ( ! F_14 ( V_29 ) ) {
V_28 = F_15 ( V_29 ,
struct V_27 ,
V_32 ) ;
V_11 . V_26 = V_28 -> V_21 ;
}
F_16 ( & V_9 -> V_30 ) ;
}
V_11 . V_33 = F_17 ( & V_2 -> V_21 ) ;
V_11 . V_6 = - 1 ;
V_11 . V_25 = V_17 ;
V_11 . V_34 = V_18 ;
V_11 . V_35 . V_36 = V_2 -> V_36 ;
V_4 = F_18 ( & V_11 ) ;
if ( F_4 ( V_4 ) ) {
F_7 ( & V_2 -> V_21 , L_5 ,
F_5 ( V_4 ) ) ;
V_4 = NULL ;
} else {
F_19 ( & V_2 -> V_21 , L_6 ,
F_17 ( & V_4 -> V_21 ) ) ;
}
F_20 ( V_17 ) ;
return 1 ;
}
void T_1 F_21 ( void )
{
F_22 ( & V_37 ) ;
}
