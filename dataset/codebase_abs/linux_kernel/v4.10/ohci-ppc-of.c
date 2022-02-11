static int
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_5 ;
if ( ( V_5 = F_3 ( V_4 ) ) < 0 )
return V_5 ;
if ( ( V_5 = F_4 ( V_4 ) ) < 0 ) {
F_5 ( V_2 -> V_6 . V_7 , L_1 ,
V_2 -> V_6 . V_8 ) ;
F_6 ( V_2 ) ;
return V_5 ;
}
return 0 ;
}
static int F_7 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 . V_14 ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
struct V_15 V_16 ;
int V_17 ;
int V_18 ;
int V_19 ;
struct V_11 * V_20 ;
if ( F_8 () )
return - V_21 ;
V_19 =
F_9 ( V_12 , L_2 ) ||
F_9 ( V_12 , L_3 ) ;
F_10 ( & V_10 -> V_13 , L_4 ) ;
V_18 = F_11 ( V_12 , 0 , & V_16 ) ;
if ( V_18 )
return V_18 ;
V_2 = F_12 ( & V_22 , & V_10 -> V_13 , L_5 ) ;
if ( ! V_2 )
return - V_23 ;
V_2 -> V_24 = V_16 . V_25 ;
V_2 -> V_26 = F_13 ( & V_16 ) ;
V_2 -> V_27 = F_14 ( & V_10 -> V_13 , & V_16 ) ;
if ( F_15 ( V_2 -> V_27 ) ) {
V_18 = F_16 ( V_2 -> V_27 ) ;
goto V_28;
}
V_17 = F_17 ( V_12 , 0 ) ;
if ( V_17 == V_29 ) {
F_5 ( & V_10 -> V_13 , L_6 ,
__FILE__ ) ;
V_18 = - V_30 ;
goto V_28;
}
V_4 = F_2 ( V_2 ) ;
if ( V_19 ) {
V_4 -> V_31 |= V_32 | V_33 ;
if ( F_9 ( V_12 , L_7 ) )
V_4 -> V_31 |= V_34 ;
if ( F_9 ( V_12 , L_8 ) )
V_4 -> V_31 |= V_34 ;
}
F_18 ( V_4 ) ;
V_18 = F_19 ( V_2 , V_17 , 0 ) ;
if ( V_18 == 0 ) {
F_20 ( V_2 -> V_6 . V_7 ) ;
return 0 ;
}
V_20 = F_21 ( NULL , NULL , L_9 ) ;
if ( V_20 != NULL ) {
if ( ! F_11 ( V_20 , 0 , & V_16 ) ) {
if ( ! F_22 ( V_16 . V_25 , 0x4 , V_35 ) ) {
F_23 ( ( F_24 ( & V_4 -> V_27 -> V_36 ) |
V_37 ) , & V_4 -> V_27 -> V_36 ) ;
( void ) F_24 ( & V_4 -> V_27 -> V_36 ) ;
} else
F_25 ( V_16 . V_25 , 0x4 ) ;
} else
F_26 ( L_10 , __FILE__ ) ;
}
F_27 ( V_17 ) ;
V_28:
F_28 ( V_2 ) ;
return V_18 ;
}
static int F_29 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = F_30 ( V_10 ) ;
F_10 ( & V_10 -> V_13 , L_11 ) ;
F_31 ( V_2 ) ;
F_27 ( V_2 -> V_17 ) ;
F_28 ( V_2 ) ;
return 0 ;
}
