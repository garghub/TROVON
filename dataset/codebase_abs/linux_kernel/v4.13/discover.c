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
F_7 ( V_10 , V_17 ) ;
F_8 ( V_10 , V_11 ) ;
F_9 ( V_10 , V_7 -> V_18 ) ;
V_5 -> V_19 -> V_20 ( F_10 ( V_10 ) , & V_5 -> V_21 ) ;
}
static void F_11 ( struct V_4 * V_5 , T_1 V_22 ,
struct V_23 * V_24 )
{
char V_25 [ 16 ] ;
char V_26 [ 64 ] ;
F_12 ( V_25 , V_22 ) ;
F_13 ( V_26 , sizeof( V_26 ) ,
V_24 ) ;
F_14 ( L_1 , V_25 ,
V_26 , V_5 -> V_27 ) ;
}
void F_15 ( struct V_1 * V_1 , struct V_2 * V_28 ,
struct V_4 * V_29 )
{
struct V_6 * V_7 = F_2 ( V_1 , V_8 ) ;
struct V_23 V_30 ;
struct V_2 * V_31 ;
struct V_9 * V_32 = F_3 ( V_28 ) ;
T_1 V_33 = F_16 ( V_32 ) ;
T_1 V_34 = F_17 ( V_32 ) ;
T_1 V_18 = F_18 ( V_32 ) ;
T_1 V_35 = F_19 ( V_32 ) ;
T_1 V_36 = F_20 ( V_32 ) ;
T_2 V_37 = F_21 ( V_32 ) ;
bool V_38 = false ;
bool V_39 = false ;
int V_40 ;
V_40 = V_29 -> V_19 -> V_41 ( V_29 , & V_30 , F_10 ( V_32 ) ) ;
F_22 ( V_28 ) ;
if ( V_40 )
return;
if ( V_18 != V_7 -> V_18 )
return;
if ( V_30 . V_42 )
return;
if ( ! F_23 ( V_33 ) )
return;
if ( ! F_24 ( V_34 ) )
return;
if ( F_25 ( V_1 , V_34 ) ) {
if ( memcmp ( & V_30 , & V_29 -> V_21 , sizeof( V_30 ) ) )
F_11 ( V_29 , V_7 -> V_13 , & V_30 ) ;
return;
}
if ( ! F_26 ( V_33 , V_7 -> V_13 ) )
return;
if ( ! F_26 ( V_29 -> V_12 , V_34 ) )
return;
F_27 ( V_1 , V_34 , V_29 , V_37 , V_36 ,
& V_30 , & V_38 , & V_39 ) ;
if ( V_39 )
F_11 ( V_29 , V_34 , & V_30 ) ;
if ( V_38 && ( V_35 == V_43 ) ) {
V_31 = F_28 ( V_15 , V_44 ) ;
if ( ! V_31 )
return;
F_1 ( V_1 , V_31 , V_45 , V_29 ) ;
F_29 ( V_1 , V_29 -> V_46 , V_31 , & V_30 ) ;
}
}
static void F_30 ( struct V_47 * V_48 )
{
if ( ! V_48 -> V_49 ) {
if ( ( V_48 -> V_50 == V_51 ) ||
( V_48 -> V_50 > V_52 ) ) {
V_48 -> V_50 = V_53 ;
F_31 ( & V_48 -> V_54 , V_55 + V_48 -> V_50 ) ;
}
}
}
void F_32 ( struct V_47 * V_48 )
{
F_33 ( & V_48 -> V_56 ) ;
V_48 -> V_49 ++ ;
F_34 ( & V_48 -> V_56 ) ;
}
void F_35 ( struct V_47 * V_48 )
{
F_33 ( & V_48 -> V_56 ) ;
V_48 -> V_49 -- ;
F_30 ( V_48 ) ;
F_34 ( & V_48 -> V_56 ) ;
}
static void F_36 ( unsigned long V_57 )
{
struct V_47 * V_48 = (struct V_47 * ) V_57 ;
struct V_2 * V_28 ;
int V_58 ;
F_33 ( & V_48 -> V_56 ) ;
if ( F_37 ( V_48 -> V_12 ) && V_48 -> V_49 ) {
V_48 -> V_50 = V_51 ;
goto exit;
}
V_28 = F_38 ( V_48 -> V_3 , V_44 ) ;
if ( V_28 )
F_29 ( V_48 -> V_1 , V_48 -> V_59 , V_28 , & V_48 -> V_60 ) ;
V_48 -> V_50 *= 2 ;
if ( V_48 -> V_49 )
V_58 = V_61 ;
else
V_58 = V_52 ;
if ( V_48 -> V_50 > V_58 )
V_48 -> V_50 = V_58 ;
F_31 ( & V_48 -> V_54 , V_55 + V_48 -> V_50 ) ;
exit:
F_34 ( & V_48 -> V_56 ) ;
}
int F_39 ( struct V_1 * V_1 , struct V_4 * V_5 ,
struct V_23 * V_60 , struct V_2 * * V_28 )
{
struct V_47 * V_48 ;
V_48 = F_40 ( sizeof( * V_48 ) , V_44 ) ;
if ( ! V_48 )
return - V_62 ;
V_48 -> V_3 = F_28 ( V_15 , V_44 ) ;
if ( ! V_48 -> V_3 ) {
F_41 ( V_48 ) ;
return - V_62 ;
}
F_1 ( V_1 , V_48 -> V_3 , V_43 , V_5 ) ;
memcpy ( & V_48 -> V_60 , V_60 , sizeof( * V_60 ) ) ;
V_48 -> V_1 = V_1 ;
V_48 -> V_59 = V_5 -> V_46 ;
V_48 -> V_12 = V_5 -> V_12 ;
V_48 -> V_49 = 0 ;
V_48 -> V_50 = V_53 ;
F_42 ( & V_48 -> V_56 ) ;
F_43 ( & V_48 -> V_54 , F_36 , ( unsigned long ) V_48 ) ;
F_31 ( & V_48 -> V_54 , V_55 + V_48 -> V_50 ) ;
V_5 -> V_63 = V_48 ;
* V_28 = F_38 ( V_48 -> V_3 , V_44 ) ;
return 0 ;
}
void F_44 ( struct V_47 * V_48 )
{
F_45 ( & V_48 -> V_54 ) ;
F_22 ( V_48 -> V_3 ) ;
F_41 ( V_48 ) ;
}
void F_46 ( struct V_1 * V_1 , struct V_4 * V_5 )
{
struct V_47 * V_48 = V_5 -> V_63 ;
struct V_2 * V_28 ;
F_33 ( & V_48 -> V_56 ) ;
F_1 ( V_1 , V_48 -> V_3 , V_43 , V_5 ) ;
V_48 -> V_1 = V_1 ;
V_48 -> V_59 = V_5 -> V_46 ;
V_48 -> V_12 = V_5 -> V_12 ;
V_48 -> V_49 = 0 ;
V_48 -> V_50 = V_53 ;
F_31 ( & V_48 -> V_54 , V_55 + V_48 -> V_50 ) ;
V_28 = F_38 ( V_48 -> V_3 , V_44 ) ;
if ( V_28 )
F_29 ( V_1 , V_48 -> V_59 , V_28 , & V_48 -> V_60 ) ;
F_34 ( & V_48 -> V_56 ) ;
}
