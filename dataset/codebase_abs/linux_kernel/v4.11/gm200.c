int
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = V_5 ( V_2 ) ;
struct V_7 * V_8 = & V_6 -> V_9 . V_8 ;
struct V_10 * V_11 = V_6 -> V_9 . V_12 ;
struct V_13 V_14 ;
int V_15 ;
V_15 = F_2 ( V_11 , V_8 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_3 ( V_4 , V_6 -> V_16 , V_17 , & V_14 ) ;
if ( V_15 ) {
F_4 ( V_11 , V_8 ) ;
return V_15 ;
}
V_15 = F_5 ( V_11 ) ;
if ( V_15 )
goto V_18;
F_6 ( V_11 , V_6 -> V_19 ) ;
V_15 = V_2 -> V_20 -> V_21 -> V_22 ( V_2 -> V_20 , & V_6 -> V_9 , V_4 , V_14 . V_23 ) ;
if ( V_15 )
goto V_18;
F_7 ( V_2 -> V_8 . V_24 , V_11 -> V_25 -> V_26 , false ) ;
F_8 ( V_11 , 0x040 , 0xdeada5a5 ) ;
F_9 ( V_11 , V_2 -> V_20 -> V_27 ) ;
F_10 ( V_11 ) ;
V_15 = F_11 ( V_11 , 100 ) ;
if ( V_15 )
goto V_18;
V_15 = F_12 ( V_11 , 0x040 ) ;
if ( V_15 ) {
F_13 ( V_8 , L_1 , V_15 ) ;
V_15 = - V_28 ;
goto V_18;
}
V_18:
F_7 ( V_2 -> V_8 . V_24 , V_11 -> V_25 -> V_26 , true ) ;
F_14 ( & V_14 ) ;
F_4 ( V_11 , V_8 ) ;
return V_15 ;
}
int
F_15 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_5 ( V_2 ) ;
struct V_29 * V_24 = V_2 -> V_8 . V_24 ;
struct V_30 * V_16 ;
const T_1 V_31 = 600 * 1024 ;
int V_15 ;
V_15 = F_16 ( V_24 , 0x1000 , 0 , true , NULL , & V_6 -> V_19 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_16 ( V_24 , 0x8000 , 0 , true , NULL , & V_6 -> V_32 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_17 ( V_24 , 0 , V_31 , 0 , NULL , & V_16 ) ;
if ( V_15 )
return V_15 ;
F_18 ( & V_16 -> V_33 [ V_34 ] ) ;
V_15 = F_19 ( V_16 , & V_6 -> V_16 , V_6 -> V_32 ) ;
F_19 ( NULL , & V_16 , NULL ) ;
if ( V_15 )
return V_15 ;
F_20 ( V_6 -> V_19 ) ;
F_21 ( V_6 -> V_19 , 0x200 , F_22 ( V_6 -> V_32 -> V_35 ) ) ;
F_21 ( V_6 -> V_19 , 0x204 , F_23 ( V_6 -> V_32 -> V_35 ) ) ;
F_21 ( V_6 -> V_19 , 0x208 , F_22 ( V_31 - 1 ) ) ;
F_21 ( V_6 -> V_19 , 0x20c , F_23 ( V_31 - 1 ) ) ;
F_24 ( V_6 -> V_19 ) ;
if ( V_2 -> V_20 -> V_21 -> V_36 ) {
V_15 = V_2 -> V_20 -> V_21 -> V_36 ( V_2 -> V_20 , V_2 ) ;
if ( V_15 )
return V_15 ;
}
return 0 ;
}
int
F_25 ( struct V_1 * V_2 , bool V_37 )
{
int V_15 = 0 ;
if ( V_2 -> V_20 -> V_21 -> V_38 )
V_15 = V_2 -> V_20 -> V_21 -> V_38 ( V_2 -> V_20 , V_2 , V_37 ) ;
return V_15 ;
}
void *
F_26 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_5 ( V_2 ) ;
V_2 -> V_20 -> V_21 -> V_39 ( V_2 -> V_20 ) ;
F_19 ( NULL , & V_6 -> V_16 , V_6 -> V_32 ) ;
F_27 ( & V_6 -> V_32 ) ;
F_27 ( & V_6 -> V_19 ) ;
return V_6 ;
}
int
F_28 ( struct V_29 * V_24 , int V_26 ,
struct V_1 * * V_40 )
{
int V_15 ;
struct V_5 * V_6 ;
struct V_41 * V_20 ;
V_20 = F_29 ( F_30 ( V_42 ) |
F_30 ( V_43 ) ) ;
if ( F_31 ( V_20 ) )
return F_32 ( V_20 ) ;
V_6 = F_33 ( sizeof( * V_6 ) , V_44 ) ;
if ( ! V_6 ) {
V_40 = NULL ;
return - V_45 ;
}
* V_40 = & V_6 -> V_9 ;
V_15 = F_34 ( & V_5 , V_20 , V_24 , V_26 , & V_6 -> V_9 ) ;
if ( V_15 )
return V_15 ;
return 0 ;
}
