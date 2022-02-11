static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
strcpy ( V_4 -> V_5 , L_1 ) ;
strcpy ( V_4 -> V_6 , V_7 ) ;
strcpy ( V_4 -> V_8 , L_2 ) ;
}
static int F_2 ( struct V_1 * V_2 , struct V_9 * V_10 )
{
struct V_11 * V_12 = F_3 ( V_2 ) ;
if ( V_12 -> V_13 )
return F_4 ( V_12 -> V_13 , V_10 ) ;
return - V_14 ;
}
static int F_5 ( struct V_1 * V_2 , struct V_9 * V_10 )
{
struct V_11 * V_12 = F_3 ( V_2 ) ;
if ( ! F_6 ( V_15 ) )
return - V_16 ;
if ( V_12 -> V_13 )
return F_7 ( V_12 -> V_13 , V_10 ) ;
return - V_14 ;
}
static int F_8 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = F_3 ( V_2 ) ;
if ( ! F_6 ( V_15 ) )
return - V_16 ;
if ( V_12 -> V_13 )
return F_9 ( V_12 -> V_13 ) ;
return - V_14 ;
}
int F_10 ( struct V_1 * V_2 , struct V_17 * V_18 , int V_10 )
{
struct V_11 * V_12 = F_3 ( V_2 ) ;
if ( ! F_11 ( V_2 ) )
return - V_14 ;
if ( ! V_12 -> V_13 )
return - V_14 ;
return F_12 ( V_12 -> V_13 , V_18 , V_10 ) ;
}
static void F_13 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = F_3 ( V_2 ) ;
T_1 V_19 ;
if ( V_12 -> V_20 != V_12 -> V_13 -> V_21 ) {
V_12 -> V_20 = V_12 -> V_13 -> V_21 ;
V_19 . V_22 = 0 ;
V_19 . V_23 . V_24 = V_12 -> V_20 ? 1 : 0 ;
V_19 . V_23 . V_25 = V_12 -> V_13 -> V_26 ? 1 : 0 ;
V_19 . V_23 . V_27 = V_12 -> V_13 -> V_27 ;
F_14 ( V_12 -> V_28 , V_19 ) ;
if ( V_12 -> V_20 ) {
F_15 ( V_2 ) ;
if ( V_12 -> V_29 != - 1 )
F_16 ( L_3
L_4 ,
V_2 -> V_30 , V_12 -> V_13 -> V_27 ,
V_12 -> V_13 -> V_26 ?
L_5 : L_6 ,
V_12 -> V_28 , V_12 -> V_29 ) ;
else
F_16 ( L_3
L_7 ,
V_2 -> V_30 , V_12 -> V_13 -> V_27 ,
V_12 -> V_13 -> V_26 ?
L_5 : L_6 ,
V_12 -> V_28 ) ;
} else {
F_17 ( V_2 ) ;
F_16 ( L_8 , V_2 -> V_30 ) ;
}
}
}
int F_18 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = F_3 ( V_2 ) ;
struct V_31 * V_32 ;
if ( ! V_12 -> V_33 )
return 0 ;
V_32 = F_19 ( V_12 -> V_33 , L_9 , 0 ) ;
if ( ! V_32 )
return 0 ;
V_12 -> V_13 = F_20 ( V_2 , V_32 , F_13 , 0 ,
V_34 ) ;
if ( V_12 -> V_13 == NULL )
return - V_35 ;
V_12 -> V_20 = 0 ;
F_9 ( V_12 -> V_13 ) ;
return 0 ;
}
