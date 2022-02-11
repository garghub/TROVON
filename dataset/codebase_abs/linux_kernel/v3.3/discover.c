static struct V_1 * F_1 ( T_1 type ,
T_1 V_2 ,
struct V_3 * V_4 )
{
struct V_1 * V_5 = F_2 ( V_6 ) ;
struct V_7 * V_8 ;
if ( V_5 ) {
V_8 = F_3 ( V_5 ) ;
F_4 ( V_8 , V_9 , type , V_6 , V_2 ) ;
F_5 ( V_8 , 1 ) ;
F_6 ( V_8 , V_2 ) ;
F_7 ( V_8 , V_10 ) ;
V_4 -> V_11 -> V_12 ( & V_4 -> V_13 , F_8 ( V_8 ) ) ;
}
return V_5 ;
}
static void F_9 ( struct V_3 * V_4 , T_1 V_14 ,
struct V_15 * V_16 )
{
char V_17 [ 16 ] ;
char V_18 [ 64 ] ;
struct V_19 V_20 ;
F_10 ( V_17 , V_14 ) ;
F_11 ( & V_20 , V_18 , sizeof( V_18 ) ) ;
F_12 ( & V_20 , V_16 ) ;
F_13 ( & V_20 ) ;
F_14 ( L_1 ,
V_17 , V_18 , V_4 -> V_21 ) ;
}
void F_15 ( struct V_1 * V_5 , struct V_3 * V_4 )
{
struct V_22 * V_23 ;
struct V_24 * V_25 ;
struct V_15 V_16 , * V_13 ;
struct V_1 * V_26 ;
struct V_7 * V_8 = F_3 ( V_5 ) ;
T_1 V_27 = F_16 ( V_8 ) ;
T_1 V_28 = F_17 ( V_8 ) ;
T_1 V_29 = F_18 ( V_8 ) ;
T_1 type = F_19 ( V_8 ) ;
int V_30 ;
V_16 . V_31 = 1 ;
V_4 -> V_11 -> V_32 ( & V_16 , F_8 ( V_8 ) ) ;
F_20 ( V_5 ) ;
if ( V_29 != V_10 )
return;
if ( V_16 . V_31 )
return;
if ( ! F_21 ( V_27 ) )
return;
if ( ! F_22 ( V_28 ) )
return;
if ( V_28 == V_33 ) {
if ( memcmp ( & V_16 , & V_4 -> V_13 , sizeof( V_16 ) ) )
F_9 ( V_4 , V_33 , & V_16 ) ;
return;
}
if ( ! F_23 ( V_27 , V_33 ) )
return;
if ( ! F_23 ( V_4 -> V_34 -> V_35 , V_28 ) )
return;
V_23 = F_24 ( V_28 ) ;
if ( ! V_23 ) {
V_23 = F_25 ( V_28 ) ;
if ( ! V_23 )
return;
}
F_26 ( V_23 ) ;
V_25 = V_23 -> V_36 [ V_4 -> V_37 ] ;
if ( ! V_25 ) {
V_25 = F_27 ( V_23 , V_4 , & V_16 ) ;
if ( ! V_25 ) {
F_28 ( V_23 ) ;
return;
}
}
V_13 = & V_25 -> V_16 ;
if ( memcmp ( V_13 , & V_16 , sizeof( * V_13 ) ) ) {
if ( F_29 ( V_25 ) || ( ! V_25 -> V_38 ) ) {
F_9 ( V_4 , V_28 , & V_16 ) ;
F_28 ( V_23 ) ;
return;
}
F_14 ( L_2 ,
V_25 -> V_21 ) ;
memcpy ( V_13 , & V_16 , sizeof( * V_13 ) ) ;
F_30 ( V_25 ) ;
}
V_30 = F_31 ( V_25 ) ;
if ( ( type == V_39 ) && ! V_30 && ! V_4 -> V_40 ) {
V_26 = F_1 ( V_41 , V_28 , V_4 ) ;
if ( V_26 ) {
V_4 -> V_11 -> V_42 ( V_26 , V_4 , & V_16 ) ;
F_20 ( V_26 ) ;
}
}
F_28 ( V_23 ) ;
}
static void F_32 ( struct V_43 * V_44 )
{
if ( ! V_44 -> V_45 ) {
if ( ( V_44 -> V_46 == V_47 ) ||
( V_44 -> V_46 > V_48 ) ) {
V_44 -> V_46 = V_49 ;
F_33 ( & V_44 -> V_50 , V_44 -> V_46 ) ;
}
}
}
void F_34 ( struct V_43 * V_44 )
{
V_44 -> V_45 ++ ;
}
void F_35 ( struct V_43 * V_44 )
{
V_44 -> V_45 -- ;
F_32 ( V_44 ) ;
}
static void F_36 ( struct V_43 * V_44 )
{
if ( ! V_44 -> V_51 -> V_40 )
F_37 ( V_44 -> V_51 , V_44 -> V_5 , & V_44 -> V_27 ) ;
}
static void F_38 ( struct V_43 * V_44 )
{
int V_52 ;
F_39 ( & V_44 -> V_51 -> V_53 ) ;
if ( V_22 ( V_44 -> V_35 ) && V_44 -> V_45 ) {
V_44 -> V_46 = V_47 ;
goto exit;
}
F_36 ( V_44 ) ;
V_44 -> V_46 *= 2 ;
if ( V_44 -> V_45 )
V_52 = V_54 ;
else
V_52 = V_48 ;
if ( V_44 -> V_46 > V_52 )
V_44 -> V_46 = V_52 ;
F_33 ( & V_44 -> V_50 , V_44 -> V_46 ) ;
exit:
F_40 ( & V_44 -> V_51 -> V_53 ) ;
}
int F_41 ( struct V_3 * V_4 ,
struct V_15 * V_27 , T_1 V_2 )
{
struct V_43 * V_44 ;
V_44 = F_42 ( sizeof( * V_44 ) , V_55 ) ;
if ( ! V_44 )
return - V_56 ;
V_44 -> V_5 = F_1 ( V_39 , V_2 , V_4 ) ;
if ( ! V_44 -> V_5 ) {
F_43 ( V_44 ) ;
return - V_57 ;
}
memcpy ( & V_44 -> V_27 , V_27 , sizeof( * V_27 ) ) ;
V_44 -> V_51 = V_4 ;
V_44 -> V_35 = V_2 ;
V_44 -> V_45 = 0 ;
V_44 -> V_46 = V_49 ;
F_44 ( & V_44 -> V_50 , ( V_58 ) F_38 , ( unsigned long ) V_44 ) ;
F_33 ( & V_44 -> V_50 , V_44 -> V_46 ) ;
V_4 -> V_34 = V_44 ;
F_36 ( V_44 ) ;
return 0 ;
}
void F_45 ( struct V_43 * V_44 )
{
F_46 ( & V_44 -> V_50 ) ;
F_47 ( & V_44 -> V_50 ) ;
F_20 ( V_44 -> V_5 ) ;
F_43 ( V_44 ) ;
}
