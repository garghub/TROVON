static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
V_4 -> V_5 = 0 ;
V_4 -> V_6 = 0 ;
return F_2 ( V_2 , L_1 , V_4 , sizeof( * V_4 ) ) ;
}
static int F_3 ( struct V_1 * V_2 , T_1 V_7 ,
T_1 V_8 , T_1 V_9 )
{
struct V_10 V_11 ;
T_2 V_6 ;
T_1 V_12 ;
T_3 V_13 ;
memset ( & V_11 , 0 , sizeof( V_11 ) ) ;
V_11 . V_14 = F_4 ( V_15 ) ;
V_6 = F_5 ( V_16 ) |
F_5 ( V_17 ) |
F_5 ( V_18 ) ;
V_11 . V_19 = V_20 ;
V_11 . exp = V_21 ;
if ( V_7 < V_22 ) {
F_6 ( V_23 , L_2 ) ;
V_7 = V_22 ;
}
V_11 . V_7 = F_4 ( V_7 ) ;
if ( V_8 ) {
V_12 = V_9 ;
V_13 = F_7 ( V_2 , L_3 , V_12 ) ;
if ( V_13 < 0 ) {
F_8 ( L_4 ) ;
goto exit;
}
V_13 = F_9 ( V_2 , L_3 , & V_12 ) ;
if ( V_13 < 0 ) {
F_8 ( L_5 ) ;
goto exit;
}
V_8 = F_10 ( T_1 , V_8 , V_12 ) ;
V_11 . V_8 = V_8 ;
V_11 . V_9 = V_9 ;
V_6 |= F_5 ( V_24 ) ;
F_6 ( V_25 , L_6 , V_8 , V_9 ) ;
}
V_11 . V_6 = F_11 ( V_6 ) ;
V_13 = F_2 ( V_2 , L_7 , & V_11 ,
sizeof( V_11 ) ) ;
if ( V_13 )
F_8 ( L_8 , V_13 ) ;
exit:
return V_13 ;
}
static int F_12 ( struct V_1 * V_2 , T_4 * V_26 ,
T_4 * V_27 )
{
struct V_28 V_29 ;
int V_13 , V_30 ;
V_29 . V_14 = V_31 ;
V_29 . V_6 = V_32 | V_33 ;
memcpy ( V_29 . V_34 , V_26 , V_35 ) ;
for ( V_30 = 0 ; V_30 < V_35 ; V_30 ++ ) {
V_29 . V_34 [ V_30 ] &= V_27 [ V_30 ] ;
V_29 . V_34 [ V_30 ] |= F_13 () & ~ ( V_27 [ V_30 ] ) ;
}
V_29 . V_34 [ 0 ] &= 0xFE ;
V_29 . V_34 [ 0 ] |= 0x02 ;
V_13 = F_2 ( V_2 , L_9 , & V_29 ,
sizeof( V_29 ) ) ;
if ( V_13 )
F_8 ( L_10 , V_13 ) ;
return V_13 ;
}
static int F_14 ( struct V_1 * V_2 , struct V_36 * V_37 ,
bool V_38 )
{
struct V_39 V_40 ;
V_40 . V_41 = F_4 ( V_42 ) ;
V_40 . V_43 = F_4 ( V_44 ) ;
V_40 . V_45 = F_4 ( 0 ) ;
V_40 . V_46 = F_4 ( 1 ) ;
V_40 . V_6 = 0 ;
if ( V_38 )
V_40 . V_6 = F_4 ( 1 << V_47 ) ;
V_40 . V_37 . V_48 = F_4 ( V_37 -> V_49 ) ;
memcpy ( V_40 . V_37 . V_50 , V_37 -> V_37 , V_37 -> V_49 ) ;
return F_2 ( V_2 , L_11 , & V_40 , sizeof( V_40 ) ) ;
}
static bool F_15 ( struct V_36 * V_37 ,
struct V_51 * V_52 )
{
int V_30 ;
if ( ! V_37 || ! V_52 -> V_53 || ! V_52 -> V_54 )
return false ;
for ( V_30 = 0 ; V_30 < V_52 -> V_54 ; V_30 ++ ) {
if ( V_37 -> V_49 == V_52 -> V_53 [ V_30 ] . V_49 ) {
if ( ! strncmp ( V_37 -> V_37 , V_52 -> V_53 [ V_30 ] . V_37 ,
V_37 -> V_49 ) )
return true ;
}
}
return false ;
}
int F_16 ( struct V_1 * V_2 )
{
int V_55 ;
V_55 = F_7 ( V_2 , L_12 , 0 ) ;
if ( V_55 == 0 ) {
V_55 = F_2 ( V_2 , L_13 , NULL , 0 ) ;
}
if ( V_55 < 0 )
F_8 ( L_14 , V_55 ) ;
return V_55 ;
}
int F_17 ( struct V_1 * V_2 ,
struct V_51 * V_52 )
{
struct V_3 V_56 ;
struct V_36 * V_37 ;
T_2 V_57 ;
int V_30 , V_55 ;
V_55 = F_16 ( V_2 ) ;
if ( V_55 < 0 ) {
F_8 ( L_15 , V_55 ) ;
return V_55 ;
}
V_55 = F_3 ( V_2 , V_52 -> V_58 [ 0 ] . V_59 , 0 , 0 ) ;
if ( V_55 < 0 )
return V_55 ;
if ( V_52 -> V_6 & V_60 ) {
V_55 = F_12 ( V_2 , V_52 -> V_26 ,
V_52 -> V_61 ) ;
if ( V_55 < 0 )
return V_55 ;
}
for ( V_30 = 0 ; V_30 < V_52 -> V_62 ; V_30 ++ ) {
V_57 = V_52 -> V_63 [ V_30 ] -> V_64 ;
V_56 . V_65 [ V_30 ] = F_11 ( V_57 ) ;
}
if ( V_52 -> V_62 ) {
V_56 . V_66 = F_4 ( V_52 -> V_62 ) ;
F_1 ( V_2 , & V_56 ) ;
}
for ( V_30 = 0 ; V_30 < V_52 -> V_67 ; V_30 ++ ) {
V_37 = & V_52 -> V_68 [ V_30 ] . V_37 ;
if ( ! V_37 -> V_49 ) {
F_8 ( L_16 ) ;
continue;
}
V_55 = F_14 ( V_2 , V_37 ,
F_15 ( V_37 , V_52 ) ) ;
if ( V_55 < 0 )
F_6 ( V_23 , L_17 ,
V_55 == 0 ? L_18 : L_19 , V_37 -> V_37 ) ;
}
V_55 = F_7 ( V_2 , L_12 , 1 ) ;
if ( V_55 < 0 )
F_8 ( L_20 , V_55 ) ;
return V_55 ;
}
