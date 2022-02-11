int
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_7 * V_8 = V_7 ( V_2 ) ;
struct V_9 * V_10 = & V_8 -> V_11 . V_10 ;
struct V_12 V_13 ;
T_1 V_14 ;
int V_15 ;
V_15 = F_2 ( V_6 , V_10 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_3 ( V_4 , V_8 -> V_16 , V_17 , & V_13 ) ;
if ( V_15 ) {
F_4 ( V_6 , V_10 ) ;
return V_15 ;
}
V_15 = F_5 ( V_6 ) ;
if ( V_15 )
goto V_18;
F_6 ( V_6 , V_8 -> V_19 ) ;
V_15 = V_2 -> V_20 -> V_21 -> V_22 ( V_2 -> V_20 , V_6 , V_4 , V_13 . V_23 ) ;
if ( V_15 < 0 )
goto V_18;
V_14 = V_15 ;
F_7 ( V_2 -> V_10 . V_24 , V_6 -> V_25 -> V_26 , false ) ;
F_8 ( V_6 , 0x040 , 0xdeada5a5 ) ;
F_9 ( V_6 , V_14 ) ;
F_10 ( V_6 ) ;
V_15 = F_11 ( V_6 , 100 ) ;
if ( V_15 )
goto V_18;
V_15 = F_12 ( V_6 , 0x040 ) ;
V_18:
F_7 ( V_2 -> V_10 . V_24 , V_6 -> V_25 -> V_26 , true ) ;
F_13 ( & V_13 ) ;
F_4 ( V_6 , V_10 ) ;
return V_15 ;
}
int
F_14 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_7 ( V_2 ) ;
struct V_27 * V_24 = V_2 -> V_10 . V_24 ;
struct V_28 * V_16 ;
const T_2 V_29 = 600 * 1024 ;
int V_15 ;
V_15 = F_15 ( V_24 , 0x1000 , 0 , true , NULL , & V_8 -> V_19 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_15 ( V_24 , 0x8000 , 0 , true , NULL , & V_8 -> V_30 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_16 ( V_24 , 0 , V_29 , 0 , NULL , & V_16 ) ;
if ( V_15 )
return V_15 ;
F_17 ( & V_16 -> V_31 [ V_32 ] ) ;
V_15 = F_18 ( V_16 , & V_8 -> V_16 , V_8 -> V_30 ) ;
F_18 ( NULL , & V_16 , NULL ) ;
if ( V_15 )
return V_15 ;
F_19 ( V_8 -> V_19 ) ;
F_20 ( V_8 -> V_19 , 0x200 , F_21 ( V_8 -> V_30 -> V_33 ) ) ;
F_20 ( V_8 -> V_19 , 0x204 , F_22 ( V_8 -> V_30 -> V_33 ) ) ;
F_20 ( V_8 -> V_19 , 0x208 , F_21 ( V_29 - 1 ) ) ;
F_20 ( V_8 -> V_19 , 0x20c , F_22 ( V_29 - 1 ) ) ;
F_23 ( V_8 -> V_19 ) ;
if ( V_2 -> V_20 -> V_21 -> V_34 ) {
V_15 = V_2 -> V_20 -> V_21 -> V_34 ( V_2 -> V_20 , V_2 ) ;
if ( V_15 )
return V_15 ;
}
return 0 ;
}
int
F_24 ( struct V_1 * V_2 , bool V_35 )
{
int V_15 = 0 ;
if ( V_2 -> V_20 -> V_21 -> V_36 )
V_15 = V_2 -> V_20 -> V_21 -> V_36 ( V_2 -> V_20 , V_2 , V_35 ) ;
return V_15 ;
}
void *
F_25 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_7 ( V_2 ) ;
V_2 -> V_20 -> V_21 -> V_37 ( V_2 -> V_20 ) ;
F_18 ( NULL , & V_8 -> V_16 , V_8 -> V_30 ) ;
F_26 ( & V_8 -> V_30 ) ;
F_26 ( & V_8 -> V_19 ) ;
return V_8 ;
}
int
F_27 ( struct V_27 * V_24 , int V_26 ,
struct V_1 * * V_38 )
{
int V_15 ;
struct V_7 * V_8 ;
struct V_39 * V_20 ;
V_20 = F_28 ( F_29 ( V_40 ) |
F_29 ( V_41 ) ) ;
if ( F_30 ( V_20 ) )
return F_31 ( V_20 ) ;
V_8 = F_32 ( sizeof( * V_8 ) , V_42 ) ;
if ( ! V_8 ) {
V_38 = NULL ;
return - V_43 ;
}
* V_38 = & V_8 -> V_11 ;
V_15 = F_33 ( & V_7 , V_20 , V_24 , V_26 , & V_8 -> V_11 ) ;
if ( V_15 )
return V_15 ;
return 0 ;
}
