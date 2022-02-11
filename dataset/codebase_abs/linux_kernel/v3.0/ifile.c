static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return (struct V_1 * ) F_2 ( V_3 ) ;
}
int F_3 ( struct V_2 * V_3 , T_1 * V_4 ,
struct V_5 * * V_6 )
{
struct V_7 V_8 ;
int V_9 ;
V_8 . V_10 = 0 ;
V_8 . V_11 = NULL ;
V_9 = F_4 ( V_3 , & V_8 ) ;
if ( ! V_9 ) {
V_9 = F_5 ( V_3 , V_8 . V_10 , 1 ,
& V_8 . V_11 ) ;
if ( V_9 < 0 )
F_6 ( V_3 , & V_8 ) ;
}
if ( V_9 < 0 ) {
F_7 ( V_8 . V_11 ) ;
return V_9 ;
}
F_8 ( V_3 , & V_8 ) ;
F_9 ( V_8 . V_11 ) ;
F_10 ( V_3 ) ;
* V_4 = ( T_1 ) V_8 . V_10 ;
* V_6 = V_8 . V_11 ;
return 0 ;
}
int F_11 ( struct V_2 * V_3 , T_1 V_12 )
{
struct V_7 V_8 = {
. V_10 = V_12 , . V_11 = NULL
} ;
struct V_13 * V_14 ;
void * V_15 ;
int V_9 ;
V_9 = F_12 ( V_3 , & V_8 ) ;
if ( ! V_9 ) {
V_9 = F_5 ( V_3 , V_8 . V_10 , 0 ,
& V_8 . V_11 ) ;
if ( V_9 < 0 )
F_13 ( V_3 , & V_8 ) ;
}
if ( V_9 < 0 ) {
F_7 ( V_8 . V_11 ) ;
return V_9 ;
}
V_15 = F_14 ( V_8 . V_11 -> V_16 , V_17 ) ;
V_14 = F_15 ( V_3 , V_8 . V_10 ,
V_8 . V_11 , V_15 ) ;
V_14 -> V_18 = 0 ;
F_16 ( V_15 , V_17 ) ;
F_9 ( V_8 . V_11 ) ;
F_7 ( V_8 . V_11 ) ;
F_17 ( V_3 , & V_8 ) ;
return 0 ;
}
int F_18 ( struct V_2 * V_3 , T_1 V_12 ,
struct V_5 * * V_6 )
{
struct V_19 * V_20 = V_3 -> V_21 ;
int V_22 ;
if ( F_19 ( ! F_20 ( V_20 , V_12 ) ) ) {
F_21 ( V_20 , V_23 , L_1 ,
( unsigned long ) V_12 ) ;
return - V_24 ;
}
V_22 = F_5 ( V_3 , V_12 , 0 , V_6 ) ;
if ( F_19 ( V_22 ) )
F_22 ( V_20 , V_23 , L_2 ,
( unsigned long ) V_12 ) ;
return V_22 ;
}
int F_23 ( struct V_19 * V_20 , struct V_25 * V_26 ,
T_2 V_27 , struct V_13 * V_14 ,
struct V_2 * * V_28 )
{
struct V_2 * V_3 ;
int V_22 ;
V_3 = F_24 ( V_20 , V_26 , V_29 ) ;
if ( F_19 ( ! V_3 ) )
return - V_30 ;
if ( ! ( V_3 -> V_31 & V_32 ) )
goto V_33;
V_22 = F_25 ( V_3 , V_34 ,
sizeof( struct V_1 ) ) ;
if ( V_22 )
goto V_35;
V_22 = F_26 ( V_3 , V_27 ) ;
if ( V_22 )
goto V_35;
F_27 ( V_3 , & F_1 ( V_3 ) -> V_36 ) ;
V_22 = F_28 ( V_3 , V_14 ) ;
if ( V_22 )
goto V_35;
F_29 ( V_3 ) ;
V_33:
* V_28 = V_3 ;
return 0 ;
V_35:
F_30 ( V_3 ) ;
return V_22 ;
}
