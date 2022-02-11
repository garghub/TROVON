const struct V_1 * F_1 ( struct V_2 * V_3 ,
struct V_1 * V_4 , int V_5 )
{
const struct V_1 * V_6 ;
if ( F_2 ( V_3 ) -> V_7 & F_3 ( V_8 ) )
return NULL ;
V_6 = F_4 ( V_3 , F_5 ( V_3 ) ,
sizeof( struct V_1 ) , V_4 ) ;
if ( V_6 == NULL )
return NULL ;
if ( V_6 -> V_9 )
return NULL ;
if ( F_6 ( V_3 , V_5 , F_5 ( V_3 ) , V_10 ) )
return NULL ;
return V_6 ;
}
struct V_11 * F_7 ( struct V_2 * V_12 ,
const struct V_2 * V_3 ,
T_1 V_13 , int V_14 )
{
struct V_11 * V_15 , * V_16 = F_2 ( V_3 ) ;
F_8 ( V_12 ) ;
V_15 = (struct V_11 * ) F_9 ( V_12 , sizeof( struct V_11 ) ) ;
V_15 -> V_17 = 4 ;
V_15 -> V_18 = sizeof( struct V_11 ) / 4 ;
V_15 -> V_19 = 0 ;
V_15 -> V_20 = 0 ;
V_15 -> V_7 = F_3 ( V_21 ) ;
V_15 -> V_13 = V_13 ;
V_15 -> V_22 = 0 ;
V_15 -> V_23 = V_16 -> V_24 ;
V_15 -> V_24 = V_16 -> V_23 ;
V_15 -> V_14 = V_14 ;
V_12 -> V_13 = F_3 ( V_25 ) ;
return V_15 ;
}
void F_10 ( struct V_2 * V_12 , const struct V_2 * V_3 ,
const struct V_1 * V_6 )
{
struct V_11 * V_15 = F_2 ( V_12 ) ;
struct V_1 * V_26 ;
F_11 ( V_12 ) ;
V_26 = (struct V_1 * ) F_9 ( V_12 , sizeof( struct V_1 ) ) ;
memset ( V_26 , 0 , sizeof( * V_26 ) ) ;
V_26 -> V_27 = V_6 -> V_28 ;
V_26 -> V_28 = V_6 -> V_27 ;
V_26 -> V_29 = sizeof( struct V_1 ) / 4 ;
if ( V_6 -> V_30 ) {
V_26 -> V_31 = V_6 -> V_32 ;
} else {
V_26 -> V_32 = F_12 ( F_13 ( V_6 -> V_31 ) + V_6 -> V_33 + V_6 -> V_34 +
V_3 -> V_35 - F_5 ( V_3 ) -
( V_6 -> V_29 << 2 ) ) ;
V_26 -> V_30 = 1 ;
}
V_26 -> V_9 = 1 ;
V_26 -> V_22 = ~ F_14 ( sizeof( struct V_1 ) , V_15 -> V_23 ,
V_15 -> V_24 , 0 ) ;
V_12 -> V_36 = V_37 ;
V_12 -> V_38 = ( unsigned char * ) V_26 - V_12 -> V_39 ;
V_12 -> V_40 = F_15 ( struct V_1 , V_22 ) ;
}
void F_16 ( struct V_2 * V_3 , int V_5 )
{
struct V_2 * V_12 ;
const struct V_11 * V_16 ;
struct V_11 * V_15 ;
const struct V_1 * V_6 ;
struct V_1 V_4 ;
V_6 = F_1 ( V_3 , & V_4 , V_5 ) ;
if ( ! V_6 )
return;
if ( F_17 ( V_3 ) -> V_41 & ( V_42 | V_43 ) )
return;
V_16 = F_2 ( V_3 ) ;
V_12 = F_18 ( sizeof( struct V_11 ) + sizeof( struct V_1 ) +
V_44 , V_45 ) ;
if ( ! V_12 )
return;
F_19 ( V_12 , F_20 ( V_3 ) ) ;
F_21 ( V_12 , V_44 ) ;
V_15 = F_7 ( V_12 , V_3 , V_10 ,
F_22 ( F_20 ( V_12 ) ) ) ;
F_10 ( V_12 , V_3 , V_6 ) ;
if ( F_23 ( V_12 , V_46 ) )
goto V_47;
if ( V_12 -> V_35 > F_24 ( F_20 ( V_12 ) ) )
goto V_47;
F_25 ( V_12 , V_3 ) ;
#if F_26 ( V_48 )
if ( V_3 -> V_49 ) {
struct V_50 * V_51 = F_27 ( V_3 ) ;
V_12 -> V_52 = F_28 ( V_3 ) ;
V_15 -> V_53 = F_3 ( V_12 -> V_35 ) ;
F_29 ( V_15 ) ;
if ( F_30 ( V_12 , V_12 -> V_52 , F_31 ( V_12 -> V_13 ) ,
V_51 -> V_54 , V_51 -> V_55 , V_12 -> V_35 ) < 0 )
goto V_47;
F_32 ( V_12 ) ;
} else
#endif
F_33 ( V_12 ) ;
return;
V_47:
F_34 ( V_12 ) ;
}
void F_35 ( struct V_2 * V_56 , int V_57 , int V_5 )
{
struct V_11 * V_58 = F_2 ( V_56 ) ;
T_2 V_59 ;
if ( V_56 -> V_60 || V_58 -> V_7 & F_3 ( V_8 ) )
return;
if ( F_36 ( V_56 ) ) {
F_37 ( V_56 , V_61 , V_57 , 0 ) ;
return;
}
if ( V_58 -> V_13 == V_10 || V_58 -> V_13 == V_62 )
V_59 = V_58 -> V_13 ;
else
V_59 = 0 ;
if ( F_6 ( V_56 , V_5 , F_5 ( V_56 ) , V_59 ) == 0 )
F_37 ( V_56 , V_61 , V_57 , 0 ) ;
}
