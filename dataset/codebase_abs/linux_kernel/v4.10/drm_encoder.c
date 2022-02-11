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
V_5 = F_5 ( V_2 , & V_4 -> V_12 , V_13 ) ;
if ( V_5 )
return V_5 ;
V_4 -> V_2 = V_2 ;
V_4 -> V_10 = V_10 ;
V_4 -> V_6 = V_6 ;
if ( V_11 ) {
T_1 V_14 ;
va_start ( V_14 , V_11 ) ;
V_4 -> V_11 = F_6 ( V_15 , V_11 , V_14 ) ;
va_end ( V_14 ) ;
} else {
V_4 -> V_11 = F_7 ( V_15 , L_1 ,
V_16 [ V_10 ] . V_11 ,
V_4 -> V_12 . V_17 ) ;
}
if ( ! V_4 -> V_11 ) {
V_5 = - V_18 ;
goto V_19;
}
F_8 ( & V_4 -> V_20 , & V_2 -> V_21 . V_22 ) ;
V_4 -> V_23 = V_2 -> V_21 . V_24 ++ ;
V_19:
if ( V_5 )
F_9 ( V_2 , & V_4 -> V_12 ) ;
return V_5 ;
}
void F_10 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
F_9 ( V_2 , & V_4 -> V_12 ) ;
F_11 ( V_4 -> V_11 ) ;
F_12 ( & V_4 -> V_20 ) ;
V_2 -> V_21 . V_24 -- ;
memset ( V_4 , 0 , sizeof( * V_4 ) ) ;
}
static struct V_25 * F_13 ( struct V_3 * V_4 )
{
struct V_26 * V_27 ;
struct V_1 * V_2 = V_4 -> V_2 ;
bool V_28 = false ;
F_14 (connector, dev) {
if ( ! V_27 -> V_29 )
continue;
V_28 = true ;
if ( V_27 -> V_29 -> V_30 != V_4 )
continue;
return V_27 -> V_29 -> V_31 ;
}
if ( V_28 )
return NULL ;
return V_4 -> V_31 ;
}
int F_15 ( struct V_1 * V_2 , void * V_32 ,
struct V_33 * V_34 )
{
struct V_35 * V_36 = V_32 ;
struct V_3 * V_4 ;
struct V_25 * V_31 ;
if ( ! F_16 ( V_2 , V_37 ) )
return - V_38 ;
V_4 = F_17 ( V_2 , V_36 -> V_39 ) ;
if ( ! V_4 )
return - V_40 ;
F_18 ( & V_2 -> V_21 . V_41 , NULL ) ;
V_31 = F_13 ( V_4 ) ;
if ( V_31 )
V_36 -> V_42 = V_31 -> V_12 . V_17 ;
else
V_36 -> V_42 = 0 ;
F_19 ( & V_2 -> V_21 . V_41 ) ;
V_36 -> V_10 = V_4 -> V_10 ;
V_36 -> V_39 = V_4 -> V_12 . V_17 ;
V_36 -> V_43 = V_4 -> V_43 ;
V_36 -> V_44 = V_4 -> V_44 ;
return 0 ;
}
