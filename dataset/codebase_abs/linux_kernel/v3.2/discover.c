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
F_8 ( V_8 , & V_4 -> V_11 ) ;
}
return V_5 ;
}
static void F_9 ( struct V_3 * V_4 , T_1 V_12 ,
struct V_13 * V_14 )
{
char V_15 [ 16 ] ;
char V_16 [ 64 ] ;
struct V_17 V_18 ;
F_10 ( V_15 , V_12 ) ;
F_11 ( & V_18 , V_16 , sizeof( V_16 ) ) ;
F_12 ( & V_18 , V_14 ) ;
F_13 ( & V_18 ) ;
F_14 ( L_1 ,
V_15 , V_16 , V_4 -> V_19 ) ;
}
void F_15 ( struct V_1 * V_5 , struct V_3 * V_4 )
{
struct V_20 * V_21 ;
struct V_22 * V_22 ;
struct V_13 V_14 , * V_11 ;
struct V_1 * V_23 ;
struct V_7 * V_8 = F_3 ( V_5 ) ;
T_1 V_24 = F_16 ( V_8 ) ;
T_1 V_25 = F_17 ( V_8 ) ;
T_1 V_26 = F_18 ( V_8 ) ;
T_1 type = F_19 ( V_8 ) ;
int V_27 ;
F_20 ( V_8 , & V_14 ) ;
F_21 ( V_5 ) ;
if ( V_26 != V_10 )
return;
if ( ! F_22 ( V_24 ) )
return;
if ( ! F_23 ( V_25 ) )
return;
if ( V_25 == V_28 ) {
if ( memcmp ( & V_14 , & V_4 -> V_11 , sizeof( V_14 ) ) )
F_9 ( V_4 , V_28 , & V_14 ) ;
return;
}
if ( ! F_24 ( V_24 , V_28 ) )
return;
if ( ! F_24 ( V_4 -> V_29 -> V_30 , V_25 ) )
return;
V_21 = F_25 ( V_25 ) ;
if ( ! V_21 ) {
V_21 = F_26 ( V_25 ) ;
if ( ! V_21 )
return;
}
F_27 ( V_21 ) ;
V_22 = V_21 -> V_31 [ V_4 -> V_32 ] ;
if ( ! V_22 ) {
V_22 = F_28 ( V_21 , V_4 , & V_14 ) ;
if ( ! V_22 ) {
F_29 ( V_21 ) ;
return;
}
}
V_11 = & V_22 -> V_14 ;
if ( memcmp ( V_11 , & V_14 , sizeof( * V_11 ) ) ) {
if ( F_30 ( V_22 ) || ( ! V_22 -> V_33 ) ) {
F_9 ( V_4 , V_25 , & V_14 ) ;
F_29 ( V_21 ) ;
return;
}
F_14 ( L_2 ,
V_22 -> V_19 ) ;
memcpy ( V_11 , & V_14 , sizeof( * V_11 ) ) ;
F_31 ( V_22 ) ;
}
V_27 = F_32 ( V_22 ) ;
if ( ( type == V_34 ) && ! V_27 && ! V_4 -> V_35 ) {
V_23 = F_1 ( V_36 , V_25 , V_4 ) ;
if ( V_23 ) {
V_4 -> V_37 -> V_38 ( V_23 , V_4 , & V_14 ) ;
F_21 ( V_23 ) ;
}
}
F_29 ( V_21 ) ;
}
static void F_33 ( struct V_29 * V_39 )
{
if ( ! V_39 -> V_40 ) {
if ( ( V_39 -> V_41 == V_42 ) ||
( V_39 -> V_41 > V_43 ) ) {
V_39 -> V_41 = V_44 ;
F_34 ( & V_39 -> V_45 , V_39 -> V_41 ) ;
}
}
}
void F_35 ( struct V_29 * V_39 )
{
V_39 -> V_40 ++ ;
}
void F_36 ( struct V_29 * V_39 )
{
V_39 -> V_40 -- ;
F_33 ( V_39 ) ;
}
static void F_37 ( struct V_29 * V_39 )
{
if ( ! V_39 -> V_46 -> V_35 )
F_38 ( V_39 -> V_46 , V_39 -> V_5 , & V_39 -> V_24 ) ;
}
static void F_39 ( struct V_29 * V_39 )
{
int V_47 ;
F_40 ( & V_39 -> V_46 -> V_48 ) ;
if ( V_20 ( V_39 -> V_30 ) && V_39 -> V_40 ) {
V_39 -> V_41 = V_42 ;
goto exit;
}
F_37 ( V_39 ) ;
V_39 -> V_41 *= 2 ;
if ( V_39 -> V_40 )
V_47 = V_49 ;
else
V_47 = V_43 ;
if ( V_39 -> V_41 > V_47 )
V_39 -> V_41 = V_47 ;
F_34 ( & V_39 -> V_45 , V_39 -> V_41 ) ;
exit:
F_41 ( & V_39 -> V_46 -> V_48 ) ;
}
int F_42 ( struct V_3 * V_4 ,
struct V_13 * V_24 , T_1 V_2 )
{
struct V_29 * V_39 ;
V_39 = F_43 ( sizeof( * V_39 ) , V_50 ) ;
if ( ! V_39 )
return - V_51 ;
V_39 -> V_5 = F_1 ( V_34 , V_2 , V_4 ) ;
if ( ! V_39 -> V_5 ) {
F_44 ( V_39 ) ;
return - V_52 ;
}
memcpy ( & V_39 -> V_24 , V_24 , sizeof( * V_24 ) ) ;
V_39 -> V_46 = V_4 ;
V_39 -> V_30 = V_2 ;
V_39 -> V_40 = 0 ;
V_39 -> V_41 = V_44 ;
F_45 ( & V_39 -> V_45 , ( V_53 ) F_39 , ( unsigned long ) V_39 ) ;
F_34 ( & V_39 -> V_45 , V_39 -> V_41 ) ;
V_4 -> V_29 = V_39 ;
F_37 ( V_39 ) ;
return 0 ;
}
void F_46 ( struct V_29 * V_39 )
{
F_47 ( & V_39 -> V_45 ) ;
F_48 ( & V_39 -> V_45 ) ;
F_21 ( V_39 -> V_5 ) ;
F_44 ( V_39 ) ;
}
