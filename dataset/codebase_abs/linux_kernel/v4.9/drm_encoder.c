int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_5 = 0 ;
F_2 (encoder, dev) {
if ( V_4 -> V_6 -> V_7 )
V_5 = V_4 -> V_6 -> V_7 ( V_4 ) ;
if ( V_5 )
return V_5 ;
}
return 0 ;
}
void F_3 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
F_2 (encoder, dev) {
if ( V_4 -> V_6 -> V_8 )
V_4 -> V_6 -> V_8 ( V_4 ) ;
}
}
int F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_9 * V_6 ,
int V_10 , const char * V_11 , ... )
{
int V_5 ;
F_5 ( V_2 ) ;
V_5 = F_6 ( V_2 , & V_4 -> V_12 , V_13 ) ;
if ( V_5 )
goto V_14;
V_4 -> V_2 = V_2 ;
V_4 -> V_10 = V_10 ;
V_4 -> V_6 = V_6 ;
if ( V_11 ) {
T_1 V_15 ;
va_start ( V_15 , V_11 ) ;
V_4 -> V_11 = F_7 ( V_16 , V_11 , V_15 ) ;
va_end ( V_15 ) ;
} else {
V_4 -> V_11 = F_8 ( V_16 , L_1 ,
V_17 [ V_10 ] . V_11 ,
V_4 -> V_12 . V_18 ) ;
}
if ( ! V_4 -> V_11 ) {
V_5 = - V_19 ;
goto V_20;
}
F_9 ( & V_4 -> V_21 , & V_2 -> V_22 . V_23 ) ;
V_4 -> V_24 = V_2 -> V_22 . V_25 ++ ;
V_20:
if ( V_5 )
F_10 ( V_2 , & V_4 -> V_12 ) ;
V_14:
F_11 ( V_2 ) ;
return V_5 ;
}
void F_12 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
F_5 ( V_2 ) ;
F_10 ( V_2 , & V_4 -> V_12 ) ;
F_13 ( V_4 -> V_11 ) ;
F_14 ( & V_4 -> V_21 ) ;
V_2 -> V_22 . V_25 -- ;
F_11 ( V_2 ) ;
memset ( V_4 , 0 , sizeof( * V_4 ) ) ;
}
static struct V_26 * F_15 ( struct V_3 * V_4 )
{
struct V_27 * V_28 ;
struct V_1 * V_2 = V_4 -> V_2 ;
bool V_29 = false ;
F_16 (connector, dev) {
if ( ! V_28 -> V_30 )
continue;
V_29 = true ;
if ( V_28 -> V_30 -> V_31 != V_4 )
continue;
return V_28 -> V_30 -> V_32 ;
}
if ( V_29 )
return NULL ;
return V_4 -> V_32 ;
}
int F_17 ( struct V_1 * V_2 , void * V_33 ,
struct V_34 * V_35 )
{
struct V_36 * V_37 = V_33 ;
struct V_3 * V_4 ;
struct V_26 * V_32 ;
if ( ! F_18 ( V_2 , V_38 ) )
return - V_39 ;
V_4 = F_19 ( V_2 , V_37 -> V_40 ) ;
if ( ! V_4 )
return - V_41 ;
F_20 ( & V_2 -> V_22 . V_42 , NULL ) ;
V_32 = F_15 ( V_4 ) ;
if ( V_32 )
V_37 -> V_43 = V_32 -> V_12 . V_18 ;
else
V_37 -> V_43 = 0 ;
F_21 ( & V_2 -> V_22 . V_42 ) ;
V_37 -> V_10 = V_4 -> V_10 ;
V_37 -> V_40 = V_4 -> V_12 . V_18 ;
V_37 -> V_44 = V_4 -> V_44 ;
V_37 -> V_45 = V_4 -> V_45 ;
return 0 ;
}
