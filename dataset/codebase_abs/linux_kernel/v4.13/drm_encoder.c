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
if ( V_4 -> V_25 ) {
struct V_26 * V_25 = V_4 -> V_25 ;
struct V_26 * V_27 ;
while ( V_25 ) {
V_27 = V_25 -> V_27 ;
F_11 ( V_25 ) ;
V_25 = V_27 ;
}
}
F_9 ( V_2 , & V_4 -> V_12 ) ;
F_12 ( V_4 -> V_11 ) ;
F_13 ( & V_4 -> V_20 ) ;
V_2 -> V_21 . V_24 -- ;
memset ( V_4 , 0 , sizeof( * V_4 ) ) ;
}
static struct V_28 * F_14 ( struct V_3 * V_4 )
{
struct V_29 * V_30 ;
struct V_1 * V_2 = V_4 -> V_2 ;
bool V_31 = false ;
struct V_32 V_33 ;
F_15 ( V_2 , & V_33 ) ;
F_16 (connector, &conn_iter) {
if ( ! V_30 -> V_34 )
continue;
V_31 = true ;
if ( V_30 -> V_34 -> V_35 != V_4 )
continue;
F_17 ( & V_33 ) ;
return V_30 -> V_34 -> V_36 ;
}
F_17 ( & V_33 ) ;
if ( V_31 )
return NULL ;
return V_4 -> V_36 ;
}
int F_18 ( struct V_1 * V_2 , void * V_37 ,
struct V_38 * V_39 )
{
struct V_40 * V_41 = V_37 ;
struct V_3 * V_4 ;
struct V_28 * V_36 ;
if ( ! F_19 ( V_2 , V_42 ) )
return - V_43 ;
V_4 = F_20 ( V_2 , V_41 -> V_44 ) ;
if ( ! V_4 )
return - V_45 ;
F_21 ( & V_2 -> V_21 . V_46 , NULL ) ;
V_36 = F_14 ( V_4 ) ;
if ( V_36 )
V_41 -> V_47 = V_36 -> V_12 . V_17 ;
else
V_41 -> V_47 = 0 ;
F_22 ( & V_2 -> V_21 . V_46 ) ;
V_41 -> V_10 = V_4 -> V_10 ;
V_41 -> V_44 = V_4 -> V_12 . V_17 ;
V_41 -> V_48 = V_4 -> V_48 ;
V_41 -> V_49 = V_4 -> V_49 ;
return 0 ;
}
