static bool F_1 ( struct V_1 * V_2 )
{
int V_3 ;
char V_4 [ V_5 ] ;
V_3 = F_2 ( V_4 , V_5 , L_1 , V_2 -> V_6 ) ;
if ( V_3 > V_5 )
return false ;
return ! strncmp ( V_4 , V_7 , V_5 ) ;
}
static bool F_1 ( struct V_1 * V_2 )
{
return ( V_2 -> V_6 == 0 ) ;
}
static int F_3 ( struct V_8 * V_9 , void * V_10 )
{
int V_11 ;
struct V_1 * V_2 = V_9 -> V_12 ;
const struct V_13 * V_14 = V_2 -> V_14 ;
struct V_15 V_16 ;
struct V_17 V_18 ;
V_11 = F_4 ( V_2 , & V_18 ) ;
if ( V_11 == 0 ) {
F_5 ( V_9 ,
L_2
L_3 ,
V_18 . V_19 , V_18 . V_20 , V_18 . V_21 ,
V_18 . V_22 + 1900 , V_18 . V_23 + 1 , V_18 . V_24 ) ;
}
V_11 = F_6 ( V_2 , & V_16 ) ;
if ( V_11 == 0 ) {
F_5 ( V_9 , L_4 ) ;
if ( ( unsigned int ) V_16 . time . V_19 <= 24 )
F_5 ( V_9 , L_5 , V_16 . time . V_19 ) ;
else
F_5 ( V_9 , L_6 ) ;
if ( ( unsigned int ) V_16 . time . V_20 <= 59 )
F_5 ( V_9 , L_5 , V_16 . time . V_20 ) ;
else
F_5 ( V_9 , L_6 ) ;
if ( ( unsigned int ) V_16 . time . V_21 <= 59 )
F_5 ( V_9 , L_7 , V_16 . time . V_21 ) ;
else
F_5 ( V_9 , L_8 ) ;
F_5 ( V_9 , L_9 ) ;
if ( ( unsigned int ) V_16 . time . V_22 <= 200 )
F_5 ( V_9 , L_10 , V_16 . time . V_22 + 1900 ) ;
else
F_5 ( V_9 , L_11 ) ;
if ( ( unsigned int ) V_16 . time . V_23 <= 11 )
F_5 ( V_9 , L_12 , V_16 . time . V_23 + 1 ) ;
else
F_5 ( V_9 , L_13 ) ;
if ( V_16 . time . V_24 && ( unsigned int ) V_16 . time . V_24 <= 31 )
F_5 ( V_9 , L_7 , V_16 . time . V_24 ) ;
else
F_5 ( V_9 , L_8 ) ;
F_5 ( V_9 , L_14 ,
V_16 . V_25 ? L_15 : L_16 ) ;
F_5 ( V_9 , L_17 ,
V_16 . V_26 ? L_15 : L_16 ) ;
F_5 ( V_9 , L_18 ,
( V_2 -> V_27 . V_25 ) ? L_15 : L_16 ) ;
F_5 ( V_9 , L_19 ,
( V_2 -> V_28 ) ? L_15 : L_16 ) ;
F_5 ( V_9 , L_20 ,
V_2 -> V_29 ) ;
F_5 ( V_9 , L_21 ,
V_2 -> V_30 ) ;
}
F_5 ( V_9 , L_22 ) ;
if ( V_14 -> V_31 )
V_14 -> V_31 ( V_2 -> V_32 . V_33 , V_9 ) ;
return 0 ;
}
static int F_7 ( struct V_34 * V_34 , struct V_35 * V_35 )
{
int V_36 ;
struct V_1 * V_2 = F_8 ( V_34 ) ;
if ( ! F_9 ( V_2 -> V_37 ) )
return - V_38 ;
V_36 = F_10 ( V_35 , F_3 , V_2 ) ;
if ( V_36 )
F_11 ( V_2 -> V_37 ) ;
return V_36 ;
}
static int F_12 ( struct V_34 * V_34 , struct V_35 * V_35 )
{
int V_39 = F_13 ( V_34 , V_35 ) ;
struct V_1 * V_2 = F_8 ( V_34 ) ;
F_11 ( V_2 -> V_37 ) ;
return V_39 ;
}
void F_14 ( struct V_1 * V_2 )
{
if ( F_1 ( V_2 ) )
F_15 ( L_23 , 0 , NULL , & V_40 , V_2 ) ;
}
void F_16 ( struct V_1 * V_2 )
{
if ( F_1 ( V_2 ) )
F_17 ( L_23 , NULL ) ;
}
