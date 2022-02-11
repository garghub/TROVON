static void F_1 ( struct V_1 * V_1 , struct V_2 * V_3 , T_1 type ,
struct V_4 * V_5 )
{
struct V_6 * V_7 = F_2 ( V_1 , V_8 ) ;
struct V_9 * V_10 ;
T_1 V_11 = V_5 -> V_12 ;
V_10 = F_3 ( V_3 ) ;
F_4 ( V_7 -> V_13 , V_10 , V_14 , type ,
V_15 , V_11 ) ;
F_5 ( V_10 , 1 ) ;
F_6 ( V_10 , V_7 -> V_16 ) ;
F_7 ( V_10 , 0 ) ;
F_8 ( V_10 , V_11 ) ;
F_9 ( V_10 , V_7 -> V_17 ) ;
V_5 -> V_18 -> V_19 ( F_10 ( V_10 ) , & V_5 -> V_20 ) ;
}
static void F_11 ( struct V_4 * V_5 , T_1 V_21 ,
struct V_22 * V_23 )
{
char V_24 [ 16 ] ;
char V_25 [ 64 ] ;
F_12 ( V_24 , V_21 ) ;
F_13 ( V_25 , sizeof( V_25 ) ,
V_23 ) ;
F_14 ( L_1 , V_24 ,
V_25 , V_5 -> V_26 ) ;
}
void F_15 ( struct V_1 * V_1 , struct V_2 * V_27 ,
struct V_4 * V_28 )
{
struct V_6 * V_7 = F_2 ( V_1 , V_8 ) ;
struct V_22 V_29 ;
struct V_2 * V_30 ;
struct V_9 * V_31 = F_3 ( V_27 ) ;
T_1 V_32 = F_16 ( V_31 ) ;
T_1 V_33 = F_17 ( V_31 ) ;
T_1 V_17 = F_18 ( V_31 ) ;
T_1 V_34 = F_19 ( V_31 ) ;
T_1 V_35 = F_20 ( V_31 ) ;
T_2 V_36 = F_21 ( V_31 ) ;
bool V_37 = false ;
bool V_38 = false ;
V_28 -> V_18 -> V_39 ( V_28 , & V_29 , F_10 ( V_31 ) ) ;
F_22 ( V_27 ) ;
if ( V_17 != V_7 -> V_17 )
return;
if ( V_29 . V_40 )
return;
if ( ! F_23 ( V_32 ) )
return;
if ( ! F_24 ( V_33 ) )
return;
if ( F_25 ( V_1 , V_33 ) ) {
if ( memcmp ( & V_29 , & V_28 -> V_20 , sizeof( V_29 ) ) )
F_11 ( V_28 , V_7 -> V_13 , & V_29 ) ;
return;
}
if ( ! F_26 ( V_32 , V_7 -> V_13 ) )
return;
if ( ! F_26 ( V_28 -> V_12 , V_33 ) )
return;
F_27 ( V_1 , V_33 , V_28 , V_36 , V_35 ,
& V_29 , & V_37 , & V_38 ) ;
if ( V_38 )
F_11 ( V_28 , V_33 , & V_29 ) ;
if ( V_37 && ( V_34 == V_41 ) ) {
V_30 = F_28 ( V_15 ) ;
if ( V_30 ) {
F_1 ( V_1 , V_30 , V_42 , V_28 ) ;
F_29 ( V_1 , V_28 -> V_43 , V_30 , & V_29 ) ;
F_22 ( V_30 ) ;
}
}
}
static void F_30 ( struct V_44 * V_45 )
{
if ( ! V_45 -> V_46 ) {
if ( ( V_45 -> V_47 == V_48 ) ||
( V_45 -> V_47 > V_49 ) ) {
V_45 -> V_47 = V_50 ;
F_31 ( & V_45 -> V_51 , V_52 + V_45 -> V_47 ) ;
}
}
}
void F_32 ( struct V_44 * V_45 )
{
F_33 ( & V_45 -> V_53 ) ;
V_45 -> V_46 ++ ;
F_34 ( & V_45 -> V_53 ) ;
}
void F_35 ( struct V_44 * V_45 )
{
F_33 ( & V_45 -> V_53 ) ;
V_45 -> V_46 -- ;
F_30 ( V_45 ) ;
F_34 ( & V_45 -> V_53 ) ;
}
static void F_36 ( unsigned long V_54 )
{
struct V_44 * V_45 = (struct V_44 * ) V_54 ;
int V_55 ;
F_33 ( & V_45 -> V_53 ) ;
if ( F_37 ( V_45 -> V_12 ) && V_45 -> V_46 ) {
V_45 -> V_47 = V_48 ;
goto exit;
}
F_29 ( V_45 -> V_1 , V_45 -> V_56 , V_45 -> V_3 , & V_45 -> V_57 ) ;
V_45 -> V_47 *= 2 ;
if ( V_45 -> V_46 )
V_55 = V_58 ;
else
V_55 = V_49 ;
if ( V_45 -> V_47 > V_55 )
V_45 -> V_47 = V_55 ;
F_31 ( & V_45 -> V_51 , V_52 + V_45 -> V_47 ) ;
exit:
F_34 ( & V_45 -> V_53 ) ;
}
int F_38 ( struct V_1 * V_1 , struct V_4 * V_5 ,
struct V_22 * V_57 )
{
struct V_44 * V_45 ;
V_45 = F_39 ( sizeof( * V_45 ) , V_59 ) ;
if ( ! V_45 )
return - V_60 ;
V_45 -> V_3 = F_28 ( V_15 ) ;
if ( ! V_45 -> V_3 ) {
F_40 ( V_45 ) ;
return - V_60 ;
}
F_1 ( V_1 , V_45 -> V_3 , V_41 , V_5 ) ;
memcpy ( & V_45 -> V_57 , V_57 , sizeof( * V_57 ) ) ;
V_45 -> V_1 = V_1 ;
V_45 -> V_56 = V_5 -> V_43 ;
V_45 -> V_12 = V_5 -> V_12 ;
V_45 -> V_46 = 0 ;
V_45 -> V_47 = V_50 ;
F_41 ( & V_45 -> V_53 ) ;
F_42 ( & V_45 -> V_51 , F_36 , ( unsigned long ) V_45 ) ;
F_31 ( & V_45 -> V_51 , V_52 + V_45 -> V_47 ) ;
V_5 -> V_61 = V_45 ;
F_29 ( V_1 , V_45 -> V_56 , V_45 -> V_3 , & V_45 -> V_57 ) ;
return 0 ;
}
void F_43 ( struct V_44 * V_45 )
{
F_44 ( & V_45 -> V_51 ) ;
F_22 ( V_45 -> V_3 ) ;
F_40 ( V_45 ) ;
}
void F_45 ( struct V_1 * V_1 , struct V_4 * V_5 )
{
struct V_44 * V_45 = V_5 -> V_61 ;
F_33 ( & V_45 -> V_53 ) ;
F_1 ( V_1 , V_45 -> V_3 , V_41 , V_5 ) ;
V_45 -> V_1 = V_1 ;
V_45 -> V_56 = V_5 -> V_43 ;
V_45 -> V_12 = V_5 -> V_12 ;
V_45 -> V_46 = 0 ;
V_45 -> V_47 = V_50 ;
F_31 ( & V_45 -> V_51 , V_52 + V_45 -> V_47 ) ;
F_29 ( V_1 , V_45 -> V_56 , V_45 -> V_3 , & V_45 -> V_57 ) ;
F_34 ( & V_45 -> V_53 ) ;
}
