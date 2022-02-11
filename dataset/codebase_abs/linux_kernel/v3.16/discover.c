static void F_1 ( struct V_1 * V_2 , T_1 type ,
struct V_3 * V_4 )
{
struct V_5 * V_6 ;
T_1 V_7 = V_4 -> V_8 ;
V_6 = F_2 ( V_2 ) ;
F_3 ( V_6 , V_9 , type , V_10 , V_7 ) ;
F_4 ( V_6 , 1 ) ;
F_5 ( V_6 , V_11 ) ;
F_6 ( V_6 , V_7 ) ;
F_7 ( V_6 , V_12 ) ;
V_4 -> V_13 -> V_14 ( F_8 ( V_6 ) , & V_4 -> V_15 ) ;
}
static void F_9 ( struct V_3 * V_4 , T_1 V_16 ,
struct V_17 * V_18 )
{
char V_19 [ 16 ] ;
char V_20 [ 64 ] ;
F_10 ( V_19 , V_16 ) ;
F_11 ( V_20 , sizeof( V_20 ) ,
V_18 ) ;
F_12 ( L_1 , V_19 ,
V_20 , V_4 -> V_21 ) ;
}
void F_13 ( struct V_1 * V_2 , struct V_3 * V_22 )
{
struct V_23 * V_24 ;
struct V_25 * V_26 ;
struct V_17 V_27 ;
struct V_1 * V_28 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_29 = F_14 ( V_6 ) ;
T_1 V_30 = F_15 ( V_6 ) ;
T_1 V_31 = F_16 ( V_6 ) ;
T_1 V_32 = F_17 ( V_6 ) ;
T_1 V_33 = F_18 ( V_6 ) ;
bool V_34 = false ;
bool V_35 = false ;
bool V_36 = false ;
bool V_37 = false ;
bool V_38 = false ;
bool V_39 = false ;
V_22 -> V_13 -> V_40 ( V_22 , & V_27 , F_8 ( V_6 ) ) ;
F_19 ( V_2 ) ;
if ( V_31 != V_12 )
return;
if ( V_27 . V_41 )
return;
if ( ! F_20 ( V_29 ) )
return;
if ( ! F_21 ( V_30 ) )
return;
if ( F_22 ( V_30 ) ) {
if ( memcmp ( & V_27 , & V_22 -> V_15 , sizeof( V_27 ) ) )
F_9 ( V_22 , V_42 , & V_27 ) ;
return;
}
if ( ! F_23 ( V_29 , V_42 ) )
return;
if ( ! F_23 ( V_22 -> V_8 , V_30 ) )
return;
V_24 = F_24 ( V_30 ) ;
if ( ! V_24 )
V_24 = F_25 ( V_30 ) ;
if ( ! V_24 )
return;
F_26 ( V_24 ) ;
V_26 = V_24 -> V_43 [ V_22 -> V_44 ] ;
V_35 = ( V_33 == V_24 -> V_33 ) ;
V_34 = V_26 && ! memcmp ( & V_26 -> V_18 , & V_27 , sizeof( V_27 ) ) ;
V_36 = V_26 && F_27 ( V_26 ) ;
if ( V_35 && V_34 && V_36 ) {
} else if ( V_35 && V_34 && ! V_36 ) {
V_39 = true ;
} else if ( V_35 && ! V_34 && V_36 ) {
F_9 ( V_22 , V_30 , & V_27 ) ;
} else if ( V_35 && ! V_34 && ! V_36 ) {
V_37 = true ;
V_39 = true ;
} else if ( ! V_35 && V_34 && V_36 ) {
V_38 = true ;
} else if ( ! V_35 && V_34 && ! V_36 ) {
V_38 = true ;
V_39 = true ;
} else if ( ! V_35 && ! V_34 && V_36 ) {
F_9 ( V_22 , V_30 , & V_27 ) ;
} else if ( ! V_35 && ! V_34 && ! V_36 ) {
V_38 = true ;
V_37 = true ;
V_39 = true ;
}
if ( V_38 )
V_24 -> V_33 = V_33 ;
if ( V_37 ) {
if ( ! V_26 )
V_26 = F_28 ( V_24 , V_22 , & V_27 ) ;
if ( V_26 ) {
memcpy ( & V_26 -> V_18 , & V_27 , sizeof( V_27 ) ) ;
F_29 ( V_26 ) ;
} else {
V_39 = false ;
}
}
if ( V_39 && ( V_32 == V_45 ) ) {
V_28 = F_30 ( V_10 ) ;
if ( V_28 ) {
F_1 ( V_28 , V_46 , V_22 ) ;
F_31 ( V_22 -> V_44 , V_28 , & V_27 ) ;
F_19 ( V_28 ) ;
}
}
F_32 ( V_24 ) ;
}
static void F_33 ( struct V_47 * V_48 )
{
if ( ! V_48 -> V_49 ) {
if ( ( V_48 -> V_50 == V_51 ) ||
( V_48 -> V_50 > V_52 ) ) {
V_48 -> V_50 = V_53 ;
F_34 ( & V_48 -> V_54 , V_48 -> V_50 ) ;
}
}
}
void F_35 ( struct V_47 * V_48 )
{
F_36 ( & V_48 -> V_55 ) ;
V_48 -> V_49 ++ ;
F_37 ( & V_48 -> V_55 ) ;
}
void F_38 ( struct V_47 * V_48 )
{
F_36 ( & V_48 -> V_55 ) ;
V_48 -> V_49 -- ;
F_33 ( V_48 ) ;
F_37 ( & V_48 -> V_55 ) ;
}
static void F_39 ( struct V_47 * V_48 )
{
int V_56 ;
F_36 ( & V_48 -> V_55 ) ;
if ( V_23 ( V_48 -> V_8 ) && V_48 -> V_49 ) {
V_48 -> V_50 = V_51 ;
goto exit;
}
F_31 ( V_48 -> V_57 , V_48 -> V_2 , & V_48 -> V_58 ) ;
V_48 -> V_50 *= 2 ;
if ( V_48 -> V_49 )
V_56 = V_59 ;
else
V_56 = V_52 ;
if ( V_48 -> V_50 > V_56 )
V_48 -> V_50 = V_56 ;
F_34 ( & V_48 -> V_54 , V_48 -> V_50 ) ;
exit:
F_37 ( & V_48 -> V_55 ) ;
}
int F_40 ( struct V_3 * V_4 , struct V_17 * V_58 )
{
struct V_47 * V_48 ;
V_48 = F_41 ( sizeof( * V_48 ) , V_60 ) ;
if ( ! V_48 )
return - V_61 ;
V_48 -> V_2 = F_30 ( V_10 ) ;
if ( ! V_48 -> V_2 ) {
F_42 ( V_48 ) ;
return - V_61 ;
}
F_1 ( V_48 -> V_2 , V_45 , V_4 ) ;
memcpy ( & V_48 -> V_58 , V_58 , sizeof( * V_58 ) ) ;
V_48 -> V_57 = V_4 -> V_44 ;
V_48 -> V_8 = V_4 -> V_8 ;
V_48 -> V_49 = 0 ;
V_48 -> V_50 = V_53 ;
F_43 ( & V_48 -> V_55 ) ;
F_44 ( & V_48 -> V_54 , ( V_62 ) F_39 , ( unsigned long ) V_48 ) ;
F_34 ( & V_48 -> V_54 , V_48 -> V_50 ) ;
V_4 -> V_63 = V_48 ;
F_31 ( V_48 -> V_57 , V_48 -> V_2 , & V_48 -> V_58 ) ;
return 0 ;
}
void F_45 ( struct V_47 * V_48 )
{
F_46 ( & V_48 -> V_54 ) ;
F_47 ( & V_48 -> V_54 ) ;
F_19 ( V_48 -> V_2 ) ;
F_42 ( V_48 ) ;
}
void F_48 ( struct V_3 * V_4 )
{
struct V_47 * V_48 = V_4 -> V_63 ;
F_36 ( & V_48 -> V_55 ) ;
F_1 ( V_48 -> V_2 , V_45 , V_4 ) ;
V_48 -> V_57 = V_4 -> V_44 ;
V_48 -> V_8 = V_4 -> V_8 ;
V_48 -> V_49 = 0 ;
V_48 -> V_50 = V_53 ;
F_34 ( & V_48 -> V_54 , V_48 -> V_50 ) ;
F_31 ( V_48 -> V_57 , V_48 -> V_2 , & V_48 -> V_58 ) ;
F_37 ( & V_48 -> V_55 ) ;
}
