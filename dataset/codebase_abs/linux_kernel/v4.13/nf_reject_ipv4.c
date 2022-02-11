const struct V_1 * F_1 ( struct V_2 * V_3 ,
struct V_1 * V_4 , int V_5 )
{
const struct V_1 * V_6 ;
if ( F_2 ( V_3 ) -> V_7 & F_3 ( V_8 ) )
return NULL ;
if ( F_2 ( V_3 ) -> V_9 != V_10 )
return NULL ;
V_6 = F_4 ( V_3 , F_5 ( V_3 ) ,
sizeof( struct V_1 ) , V_4 ) ;
if ( V_6 == NULL )
return NULL ;
if ( V_6 -> V_11 )
return NULL ;
if ( F_6 ( V_3 , V_5 , F_5 ( V_3 ) , V_10 ) )
return NULL ;
return V_6 ;
}
struct V_12 * F_7 ( struct V_2 * V_13 ,
const struct V_2 * V_3 ,
T_1 V_9 , int V_14 )
{
struct V_12 * V_15 , * V_16 = F_2 ( V_3 ) ;
F_8 ( V_13 ) ;
V_15 = F_9 ( V_13 , sizeof( struct V_12 ) ) ;
V_15 -> V_17 = 4 ;
V_15 -> V_18 = sizeof( struct V_12 ) / 4 ;
V_15 -> V_19 = 0 ;
V_15 -> V_20 = 0 ;
V_15 -> V_7 = F_3 ( V_21 ) ;
V_15 -> V_9 = V_9 ;
V_15 -> V_22 = 0 ;
V_15 -> V_23 = V_16 -> V_24 ;
V_15 -> V_24 = V_16 -> V_23 ;
V_15 -> V_14 = V_14 ;
V_13 -> V_9 = F_3 ( V_25 ) ;
return V_15 ;
}
void F_10 ( struct V_2 * V_13 , const struct V_2 * V_3 ,
const struct V_1 * V_6 )
{
struct V_12 * V_15 = F_2 ( V_13 ) ;
struct V_1 * V_26 ;
F_11 ( V_13 ) ;
V_26 = F_12 ( V_13 , sizeof( struct V_1 ) ) ;
V_26 -> V_27 = V_6 -> V_28 ;
V_26 -> V_28 = V_6 -> V_27 ;
V_26 -> V_29 = sizeof( struct V_1 ) / 4 ;
if ( V_6 -> V_30 ) {
V_26 -> V_31 = V_6 -> V_32 ;
} else {
V_26 -> V_32 = F_13 ( F_14 ( V_6 -> V_31 ) + V_6 -> V_33 + V_6 -> V_34 +
V_3 -> V_35 - F_5 ( V_3 ) -
( V_6 -> V_29 << 2 ) ) ;
V_26 -> V_30 = 1 ;
}
V_26 -> V_11 = 1 ;
V_26 -> V_22 = ~ F_15 ( sizeof( struct V_1 ) , V_15 -> V_23 ,
V_15 -> V_24 , 0 ) ;
V_13 -> V_36 = V_37 ;
V_13 -> V_38 = ( unsigned char * ) V_26 - V_13 -> V_39 ;
V_13 -> V_40 = F_16 ( struct V_1 , V_22 ) ;
}
void F_17 ( struct V_41 * V_41 , struct V_2 * V_3 , int V_5 )
{
struct V_2 * V_13 ;
struct V_12 * V_15 ;
const struct V_1 * V_6 ;
struct V_1 V_4 ;
V_6 = F_1 ( V_3 , & V_4 , V_5 ) ;
if ( ! V_6 )
return;
if ( F_18 ( V_3 ) -> V_42 & ( V_43 | V_44 ) )
return;
V_13 = F_19 ( sizeof( struct V_12 ) + sizeof( struct V_1 ) +
V_45 , V_46 ) ;
if ( ! V_13 )
return;
F_20 ( V_13 , F_21 ( V_3 ) ) ;
V_13 -> V_47 = F_22 ( V_41 , V_3 -> V_47 ) ;
F_23 ( V_13 , V_45 ) ;
V_15 = F_7 ( V_13 , V_3 , V_10 ,
F_24 ( F_21 ( V_13 ) ) ) ;
F_10 ( V_13 , V_3 , V_6 ) ;
if ( F_25 ( V_41 , V_13 , V_48 ) )
goto V_49;
if ( V_13 -> V_35 > F_26 ( F_21 ( V_13 ) ) )
goto V_49;
F_27 ( V_13 , V_3 ) ;
#if F_28 ( V_50 )
if ( V_3 -> V_51 ) {
struct V_52 * V_53 = F_29 ( V_3 ) ;
V_13 -> V_54 = F_30 ( V_3 ) ;
V_15 -> V_55 = F_3 ( V_13 -> V_35 ) ;
F_31 ( V_15 ) ;
if ( F_32 ( V_13 , V_13 -> V_54 , F_33 ( V_13 -> V_9 ) ,
V_53 -> V_56 , V_53 -> V_57 , V_13 -> V_35 ) < 0 )
goto V_49;
F_34 ( V_13 ) ;
} else
#endif
F_35 ( V_41 , V_13 -> V_58 , V_13 ) ;
return;
V_49:
F_36 ( V_13 ) ;
}
void F_37 ( struct V_2 * V_59 , int V_60 , int V_5 )
{
struct V_12 * V_61 = F_2 ( V_59 ) ;
T_2 V_62 ;
if ( V_61 -> V_7 & F_3 ( V_8 ) )
return;
if ( F_38 ( V_59 ) ) {
F_39 ( V_59 , V_63 , V_60 , 0 ) ;
return;
}
if ( V_61 -> V_9 == V_10 || V_61 -> V_9 == V_64 )
V_62 = V_61 -> V_9 ;
else
V_62 = 0 ;
if ( F_6 ( V_59 , V_5 , F_5 ( V_59 ) , V_62 ) == 0 )
F_39 ( V_59 , V_63 , V_60 , 0 ) ;
}
