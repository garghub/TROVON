int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
T_1 V_5 ;
const char * type ;
T_2 V_6 ;
int V_7 ;
F_2 ( ! V_2 -> V_8 -> V_8 . V_9 ) ;
V_7 = F_3 ( V_2 -> V_8 -> V_8 . V_9 , L_1 , & type ) ;
if ( V_7 ) {
F_4 ( L_2 ) ;
return V_7 ;
}
if ( ! strcmp ( type , L_3 ) ) {
V_4 = & V_10 ;
} else if ( ! strcmp ( type , L_4 ) ) {
V_4 = & V_11 ;
} else {
F_4 ( L_5 , type ) ;
return - V_12 ;
}
V_5 = ( ( V_4 -> V_13 . V_14 * V_4 -> V_13 . V_15 ) * V_4 -> V_16 ) / 8 ;
V_5 = F_5 ( V_5 , V_17 ) ;
V_2 -> V_2 . V_18 = F_6 ( & V_2 -> V_8 -> V_8 , V_5 , & V_6 ,
V_19 ) ;
if ( ! V_2 -> V_2 . V_18 ) {
F_4 ( L_6 ) ;
return - V_20 ;
}
V_2 -> V_2 . V_21 . V_22 = V_6 ;
V_2 -> V_2 . V_21 . V_23 = V_5 ;
V_2 -> V_4 = V_4 ;
return 0 ;
}
int F_7 ( struct V_1 * V_2 , struct V_24 * V_25 )
{
return F_8 ( & V_2 -> V_8 -> V_8 , V_25 , V_2 -> V_2 . V_18 ,
V_2 -> V_2 . V_21 . V_22 , V_2 -> V_2 . V_21 . V_23 ) ;
}
void F_9 ( struct V_1 * V_2 )
{
F_10 ( & V_2 -> V_8 -> V_8 , V_2 -> V_2 . V_21 . V_23 , V_2 -> V_2 . V_18 ,
V_2 -> V_2 . V_21 . V_22 ) ;
}
