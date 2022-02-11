static const struct V_1
* F_1 ( unsigned int V_2 , unsigned int V_3 )
{
const struct V_1 * V_4 ;
for ( V_4 = V_5 ; V_4 -> V_2 ; ++ V_4 ) {
if ( ( V_4 -> V_2 == V_2 ) && ( V_4 -> V_3 == V_3 ) )
return V_4 ;
}
return NULL ;
}
static int F_2 ( struct V_6 * V_7 , int V_8 )
{
struct V_9 * V_10 = F_3 ( V_7 -> V_11 . V_12 ) ;
F_4 ( & V_7 -> V_11 , L_1 , V_8 ? 0 : 0x20 ) ;
return F_5 ( V_10 , 2 , V_8 ? 0 : 0x20 ) ;
}
static int F_6 ( struct V_6 * V_7 , int V_8 )
{
struct V_9 * V_10 = F_3 ( V_7 -> V_11 . V_12 ) ;
F_4 ( & V_7 -> V_11 , L_2 , V_8 ? 0x60 : 0 ) ;
return F_5 ( V_10 , 0 , V_8 ? 0x60 : 0 ) ;
}
static int F_7 ( struct V_9 * V_10 , void * V_13 )
{
struct V_1 * V_14 = V_13 ;
struct V_15 * V_16 ;
int V_17 = 0 ;
F_8 ( ! V_14 ) ;
V_16 = V_10 -> V_15 [ V_18 ] ;
if ( F_9 ( V_16 ) < 0x1000 )
return - V_19 ;
V_16 -> V_20 |= V_21 | V_22 ;
if ( V_14 -> V_23 < 2 ) {
V_16 -> V_20 |= V_24 | V_25 ;
V_17 = 3 ;
} else {
V_16 -> V_20 |= V_26 ;
}
return F_10 ( V_10 , V_16 , V_17 ) ;
}
static void F_11 ( struct V_9 * V_10 )
{
struct V_6 * V_7 = V_10 -> V_27 ;
F_12 ( V_7 ) ;
F_13 ( V_10 ) ;
}
static void F_14 ( struct V_28 * V_11 )
{
struct V_6 * V_7 = F_15 ( V_11 ) ;
F_16 ( V_7 ) ;
}
static int F_17 ( struct V_9 * V_10 )
{
int V_29 ;
struct V_6 * V_7 ;
const struct V_1 * V_14 ;
struct V_15 * V_16 ;
struct V_11 {
struct V_6 V_7 ;
struct V_15 V_30 [ 2 ] ;
} * V_11 ;
V_14 = F_1 ( V_10 -> V_31 , V_10 -> V_32 ) ;
if ( ! V_14 )
return - V_33 ;
V_10 -> V_34 |= V_35 | V_36 |
V_37 | V_38 ;
V_29 = F_18 ( V_10 , F_7 , ( void * ) V_14 ) ;
if ( V_29 )
goto V_39;
V_29 = F_19 ( V_10 ) ;
if ( V_29 < 0 )
goto V_39;
V_16 = V_10 -> V_15 [ V_18 ] ;
if ( ! V_16 ) {
V_29 = - V_40 ;
goto V_41;
}
V_11 = F_20 ( sizeof( * V_11 ) , V_42 ) ;
if ( ! V_11 ) {
V_29 = - V_43 ;
goto V_44;
}
V_11 -> V_7 . V_15 = V_11 -> V_30 ;
V_11 -> V_7 . V_45 = F_21 ( V_11 -> V_30 ) ;
V_11 -> V_7 . V_11 . V_46 = F_14 ;
V_7 = & V_11 -> V_7 ;
V_7 -> V_11 . V_47 = ( void * ) V_14 ;
V_7 -> V_11 . V_12 = & V_10 -> V_11 ;
V_10 -> V_27 = V_7 ;
V_7 -> V_15 [ 0 ] . V_20 = V_48 ;
V_7 -> V_15 [ 0 ] . V_49 = V_16 -> V_49 ;
V_7 -> V_15 [ 0 ] . V_50 = V_16 -> V_50 ;
V_7 -> V_15 [ 1 ] . V_20 = V_51 ;
V_7 -> V_15 [ 1 ] . V_49 = V_10 -> V_52 ;
V_7 -> V_15 [ 1 ] . V_50 = V_7 -> V_15 [ 1 ] . V_49 ;
F_22 ( & V_53 ) ;
V_7 -> V_54 = V_55 ++ ;
F_23 ( & V_53 ) ;
V_7 -> V_56 = L_3 ;
F_24 ( & V_7 -> V_11 , L_4 , V_7 -> V_54 ) ;
V_29 = F_25 ( V_7 ) ;
if ( V_29 < 0 )
goto V_57;
F_26 ( & V_10 -> V_11 , L_5 , F_27 ( & V_7 -> V_11 ) ) ;
return 0 ;
V_57:
F_16 ( V_11 ) ;
V_44:
V_41:
V_39:
F_13 ( V_10 ) ;
V_10 -> V_27 = NULL ;
return V_29 ;
}
