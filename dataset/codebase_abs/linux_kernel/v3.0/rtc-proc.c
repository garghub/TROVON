static int F_1 ( struct V_1 * V_2 , void * V_3 )
{
int V_4 ;
struct V_5 * V_6 = V_2 -> V_7 ;
const struct V_8 * V_9 = V_6 -> V_9 ;
struct V_10 V_11 ;
struct V_12 V_13 ;
V_4 = F_2 ( V_6 , & V_13 ) ;
if ( V_4 == 0 ) {
F_3 ( V_2 ,
L_1
L_2 ,
V_13 . V_14 , V_13 . V_15 , V_13 . V_16 ,
V_13 . V_17 + 1900 , V_13 . V_18 + 1 , V_13 . V_19 ) ;
}
V_4 = F_4 ( V_6 , & V_11 ) ;
if ( V_4 == 0 ) {
F_3 ( V_2 , L_3 ) ;
if ( ( unsigned int ) V_11 . time . V_14 <= 24 )
F_3 ( V_2 , L_4 , V_11 . time . V_14 ) ;
else
F_3 ( V_2 , L_5 ) ;
if ( ( unsigned int ) V_11 . time . V_15 <= 59 )
F_3 ( V_2 , L_4 , V_11 . time . V_15 ) ;
else
F_3 ( V_2 , L_5 ) ;
if ( ( unsigned int ) V_11 . time . V_16 <= 59 )
F_3 ( V_2 , L_6 , V_11 . time . V_16 ) ;
else
F_3 ( V_2 , L_7 ) ;
F_3 ( V_2 , L_8 ) ;
if ( ( unsigned int ) V_11 . time . V_17 <= 200 )
F_3 ( V_2 , L_9 , V_11 . time . V_17 + 1900 ) ;
else
F_3 ( V_2 , L_10 ) ;
if ( ( unsigned int ) V_11 . time . V_18 <= 11 )
F_3 ( V_2 , L_11 , V_11 . time . V_18 + 1 ) ;
else
F_3 ( V_2 , L_12 ) ;
if ( V_11 . time . V_19 && ( unsigned int ) V_11 . time . V_19 <= 31 )
F_3 ( V_2 , L_6 , V_11 . time . V_19 ) ;
else
F_3 ( V_2 , L_7 ) ;
F_3 ( V_2 , L_13 ,
V_11 . V_20 ? L_14 : L_15 ) ;
F_3 ( V_2 , L_16 ,
V_11 . V_21 ? L_14 : L_15 ) ;
F_3 ( V_2 , L_17 ,
( V_6 -> V_22 . V_20 ) ? L_14 : L_15 ) ;
F_3 ( V_2 , L_18 ,
( V_6 -> V_23 ) ? L_14 : L_15 ) ;
F_3 ( V_2 , L_19 ,
V_6 -> V_24 ) ;
F_3 ( V_2 , L_20 ,
V_6 -> V_25 ) ;
}
F_3 ( V_2 , L_21 ) ;
if ( V_9 -> V_26 )
V_9 -> V_26 ( V_6 -> V_27 . V_28 , V_2 ) ;
return 0 ;
}
static int F_5 ( struct V_29 * V_29 , struct V_30 * V_30 )
{
int V_31 ;
struct V_5 * V_6 = F_6 ( V_29 ) -> V_32 ;
if ( ! F_7 ( V_33 ) )
return - V_34 ;
V_31 = F_8 ( V_30 , F_1 , V_6 ) ;
if ( V_31 )
F_9 ( V_33 ) ;
return V_31 ;
}
static int F_10 ( struct V_29 * V_29 , struct V_30 * V_30 )
{
int V_35 = F_11 ( V_29 , V_30 ) ;
F_9 ( V_33 ) ;
return V_35 ;
}
void F_12 ( struct V_5 * V_6 )
{
if ( V_6 -> V_36 == 0 )
F_13 ( L_22 , 0 , NULL , & V_37 , V_6 ) ;
}
void F_14 ( struct V_5 * V_6 )
{
if ( V_6 -> V_36 == 0 )
F_15 ( L_22 , NULL ) ;
}
