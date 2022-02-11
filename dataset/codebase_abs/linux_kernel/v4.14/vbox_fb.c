static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * * V_6 )
{
struct V_7 * V_8 = V_2 -> V_9 . V_8 ;
T_1 V_10 ;
struct V_5 * V_11 ;
T_1 V_12 = V_4 -> V_13 [ 0 ] ;
int V_14 ;
V_10 = V_12 * V_4 -> V_15 ;
V_14 = F_2 ( V_8 , V_10 , true , & V_11 ) ;
if ( V_14 )
return V_14 ;
* V_6 = V_11 ;
return 0 ;
}
static int F_3 ( struct V_16 * V_9 ,
struct V_17 * V_18 )
{
struct V_1 * V_2 =
F_4 ( V_9 , struct V_1 , V_9 ) ;
struct V_7 * V_8 = V_2 -> V_9 . V_8 ;
struct V_3 V_4 ;
struct V_19 * V_20 ;
struct V_21 * V_22 ;
struct V_5 * V_11 ;
struct V_23 * V_24 ;
int V_10 , V_14 ;
T_1 V_12 ;
V_4 . V_25 = V_18 -> V_26 ;
V_4 . V_15 = V_18 -> V_27 ;
V_12 = V_4 . V_25 * ( ( V_18 -> V_28 + 7 ) / 8 ) ;
V_4 . V_29 = F_5 ( V_18 -> V_28 ,
V_18 -> V_30 ) ;
V_4 . V_13 [ 0 ] = V_12 ;
V_10 = V_12 * V_4 . V_15 ;
V_14 = F_1 ( V_2 , & V_4 , & V_11 ) ;
if ( V_14 ) {
F_6 ( L_1 , V_14 ) ;
return V_14 ;
}
V_14 = F_7 ( V_8 , & V_2 -> V_31 , & V_4 , V_11 ) ;
if ( V_14 )
return V_14 ;
V_24 = F_8 ( V_11 ) ;
V_14 = F_9 ( V_24 , false ) ;
if ( V_14 )
return V_14 ;
V_14 = F_10 ( V_24 , V_32 , NULL ) ;
if ( V_14 ) {
F_11 ( V_24 ) ;
return V_14 ;
}
V_14 = F_12 ( & V_24 -> V_24 , 0 , V_24 -> V_24 . V_33 , & V_24 -> V_34 ) ;
F_11 ( V_24 ) ;
if ( V_14 ) {
F_6 ( L_2 ) ;
return V_14 ;
}
V_22 = F_13 ( V_9 ) ;
if ( F_14 ( V_22 ) )
return - F_15 ( V_22 ) ;
V_22 -> V_35 = V_2 ;
V_2 -> V_10 = V_10 ;
V_20 = & V_2 -> V_31 . V_36 ;
V_2 -> V_9 . V_20 = V_20 ;
strcpy ( V_22 -> V_37 . V_38 , L_3 ) ;
V_22 -> V_39 = V_40 | V_41 |
V_42 ;
V_22 -> V_43 = & V_44 ;
V_22 -> V_45 -> V_46 [ 0 ] . V_36 = F_16 ( V_8 -> V_47 , 0 ) ;
V_22 -> V_45 -> V_46 [ 0 ] . V_10 = F_17 ( V_8 -> V_47 , 0 ) ;
F_18 ( V_22 , V_20 -> V_13 [ 0 ] , V_20 -> V_48 -> V_49 ) ;
F_19 ( V_22 , & V_2 -> V_9 , V_18 -> V_50 ,
V_18 -> V_51 ) ;
V_22 -> V_52 = V_24 -> V_34 . V_53 ;
V_22 -> V_54 = V_10 ;
#ifdef F_20
V_22 -> V_55 = & V_56 ;
F_21 ( V_22 ) ;
#endif
V_22 -> V_57 . V_39 = V_58 ;
F_22 ( L_4 , V_20 -> V_25 , V_20 -> V_15 ) ;
return 0 ;
}
void F_23 ( struct V_7 * V_8 )
{
struct V_59 * V_60 = V_8 -> V_61 ;
struct V_1 * V_2 = V_60 -> V_2 ;
struct V_62 * V_31 = & V_2 -> V_31 ;
#ifdef F_20
if ( V_2 -> V_9 . V_2 && V_2 -> V_9 . V_2 -> V_55 )
F_24 ( V_2 -> V_9 . V_2 ) ;
#endif
F_25 ( & V_2 -> V_9 ) ;
if ( V_31 -> V_63 ) {
struct V_23 * V_24 = F_8 ( V_31 -> V_63 ) ;
if ( ! F_9 ( V_24 , false ) ) {
if ( V_24 -> V_34 . V_53 )
F_26 ( & V_24 -> V_34 ) ;
if ( V_24 -> V_64 )
F_27 ( V_24 ) ;
F_11 ( V_24 ) ;
}
F_28 ( V_31 -> V_63 ) ;
V_31 -> V_63 = NULL ;
}
F_29 ( & V_2 -> V_9 ) ;
F_30 ( & V_31 -> V_36 ) ;
F_31 ( & V_31 -> V_36 ) ;
}
int F_32 ( struct V_7 * V_8 )
{
struct V_59 * V_60 = V_8 -> V_61 ;
struct V_1 * V_2 ;
int V_14 ;
V_2 = F_33 ( V_8 -> V_8 , sizeof( * V_2 ) , V_65 ) ;
if ( ! V_2 )
return - V_66 ;
V_60 -> V_2 = V_2 ;
F_34 ( & V_2 -> V_67 ) ;
F_35 ( V_8 , & V_2 -> V_9 , & V_68 ) ;
V_14 = F_36 ( V_8 , & V_2 -> V_9 , V_60 -> V_69 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_37 ( & V_2 -> V_9 ) ;
if ( V_14 )
goto V_70;
F_38 ( V_8 ) ;
V_14 = F_39 ( & V_2 -> V_9 , 32 ) ;
if ( V_14 )
goto V_70;
return 0 ;
V_70:
F_29 ( & V_2 -> V_9 ) ;
return V_14 ;
}
void F_40 ( struct V_59 * V_60 , unsigned long V_71 )
{
struct V_21 * V_2 = V_60 -> V_2 -> V_9 . V_2 ;
V_2 -> V_37 . V_72 = V_2 -> V_45 -> V_46 [ 0 ] . V_36 + V_71 ;
V_2 -> V_37 . V_73 = V_60 -> V_74 - V_71 ;
}
