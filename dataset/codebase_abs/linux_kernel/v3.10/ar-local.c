static
struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
V_4 = F_2 ( sizeof( struct V_1 ) , V_5 ) ;
if ( V_4 ) {
F_3 ( & V_4 -> V_6 , & V_7 ) ;
F_3 ( & V_4 -> V_8 , & V_9 ) ;
F_3 ( & V_4 -> V_10 , & V_11 ) ;
F_4 ( & V_4 -> V_12 ) ;
F_4 ( & V_4 -> V_13 ) ;
F_5 ( & V_4 -> V_14 ) ;
F_6 ( & V_4 -> V_15 ) ;
F_6 ( & V_4 -> V_16 ) ;
F_7 ( & V_4 -> V_17 ) ;
F_8 ( & V_4 -> V_18 ) ;
F_9 ( & V_4 -> V_19 , 1 ) ;
V_4 -> V_20 = F_10 ( & V_21 ) ;
memcpy ( & V_4 -> V_3 , V_3 , sizeof( * V_3 ) ) ;
}
F_11 ( L_1 , V_4 ) ;
return V_4 ;
}
static int F_12 ( struct V_1 * V_4 )
{
struct V_22 * V_22 ;
int V_23 , V_24 ;
F_13 ( L_2 , V_4 , V_4 -> V_3 . V_25 ) ;
V_23 = F_14 ( V_26 , V_4 -> V_3 . V_25 , V_27 ,
& V_4 -> V_28 ) ;
if ( V_23 < 0 ) {
F_11 ( L_3 , V_23 ) ;
return V_23 ;
}
if ( V_4 -> V_3 . V_29 > sizeof( V_30 ) ) {
F_15 ( L_4 ) ;
V_23 = F_16 ( V_4 -> V_28 ,
(struct V_31 * ) & V_4 -> V_3 . V_32 ,
V_4 -> V_3 . V_29 ) ;
if ( V_23 < 0 ) {
F_15 ( L_5 ) ;
goto error;
}
}
V_24 = 1 ;
V_23 = F_17 ( V_4 -> V_28 , V_33 , V_34 ,
( char * ) & V_24 , sizeof( V_24 ) ) ;
if ( V_23 < 0 ) {
F_15 ( L_6 ) ;
goto error;
}
V_24 = V_35 ;
V_23 = F_17 ( V_4 -> V_28 , V_33 , V_36 ,
( char * ) & V_24 , sizeof( V_24 ) ) ;
if ( V_23 < 0 ) {
F_15 ( L_6 ) ;
goto error;
}
F_18 ( & V_37 ) ;
F_19 ( & V_4 -> V_13 , & V_38 ) ;
F_20 ( & V_37 ) ;
V_22 = V_4 -> V_28 -> V_39 ;
V_22 -> V_40 = V_4 ;
V_22 -> V_41 = V_42 ;
V_22 -> V_43 = V_44 ;
F_11 ( L_7 ) ;
return 0 ;
error:
F_21 ( V_4 -> V_28 , V_45 ) ;
V_4 -> V_28 -> V_39 -> V_40 = NULL ;
F_22 ( V_4 -> V_28 ) ;
V_4 -> V_28 = NULL ;
F_11 ( L_8 , V_23 ) ;
return V_23 ;
}
struct V_1 * F_23 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
int V_23 ;
F_13 ( L_9 ,
V_3 -> V_25 ,
V_3 -> V_32 . V_46 ,
& V_3 -> V_32 . sin . V_47 ,
F_24 ( V_3 -> V_32 . sin . V_48 ) ) ;
F_25 ( & V_49 ) ;
F_26 ( & V_37 ) ;
F_27 (local, &rxrpc_locals, link) {
F_15 ( L_10 ,
V_4 -> V_3 . V_25 ,
V_4 -> V_3 . V_32 . V_46 ,
& V_4 -> V_3 . V_32 . sin . V_47 ,
F_24 ( V_4 -> V_3 . V_32 . sin . V_48 ) ) ;
if ( V_4 -> V_3 . V_25 != V_3 -> V_25 ||
V_4 -> V_3 . V_32 . V_46 != V_3 -> V_32 . V_46 )
continue;
switch ( V_3 -> V_32 . V_46 ) {
case V_50 :
if ( V_4 -> V_3 . V_32 . sin . V_48 !=
V_3 -> V_32 . sin . V_48 )
continue;
if ( memcmp ( & V_4 -> V_3 . V_32 . sin . V_47 ,
& V_3 -> V_32 . sin . V_47 ,
sizeof( struct V_51 ) ) != 0 )
continue;
goto V_52;
default:
F_28 () ;
}
}
F_29 ( & V_37 ) ;
V_4 = F_1 ( V_3 ) ;
if ( ! V_4 ) {
F_30 ( & V_49 ) ;
return F_31 ( - V_53 ) ;
}
V_23 = F_12 ( V_4 ) ;
if ( V_23 < 0 ) {
F_30 ( & V_49 ) ;
F_32 ( V_4 ) ;
F_11 ( L_8 , V_23 ) ;
return F_31 ( V_23 ) ;
}
F_30 ( & V_49 ) ;
F_33 ( L_11 ,
V_4 -> V_20 ,
V_4 -> V_3 . V_25 ,
V_4 -> V_3 . V_32 . V_46 ,
& V_4 -> V_3 . V_32 . sin . V_47 ,
F_24 ( V_4 -> V_3 . V_32 . sin . V_48 ) ) ;
F_11 ( L_12 , V_4 ) ;
return V_4 ;
V_52:
F_34 ( V_4 ) ;
F_29 ( & V_37 ) ;
F_30 ( & V_49 ) ;
F_33 ( L_13 ,
V_4 -> V_20 ,
V_4 -> V_3 . V_25 ,
V_4 -> V_3 . V_32 . V_46 ,
& V_4 -> V_3 . V_32 . sin . V_47 ,
F_24 ( V_4 -> V_3 . V_32 . sin . V_48 ) ) ;
F_11 ( L_14 , V_4 ) ;
return V_4 ;
}
void F_35 ( struct V_1 * V_4 )
{
F_13 ( L_15 , V_4 , F_36 ( & V_4 -> V_19 ) ) ;
F_37 ( F_36 ( & V_4 -> V_19 ) , > , 0 ) ;
F_18 ( & V_37 ) ;
if ( F_38 ( F_39 ( & V_4 -> V_19 ) ) ) {
F_15 ( L_16 ) ;
F_40 ( & V_4 -> V_6 ) ;
}
F_20 ( & V_37 ) ;
F_11 ( L_17 ) ;
}
static void V_7 ( struct V_54 * V_55 )
{
struct V_1 * V_4 =
F_41 ( V_55 , struct V_1 , V_6 ) ;
F_13 ( L_2 , V_4 , F_36 ( & V_4 -> V_19 ) ) ;
F_25 ( & V_49 ) ;
F_18 ( & V_37 ) ;
if ( F_36 ( & V_4 -> V_19 ) > 0 ) {
F_20 ( & V_37 ) ;
F_42 ( & V_49 ) ;
F_11 ( L_18 ) ;
return;
}
F_43 ( & V_4 -> V_13 ) ;
V_4 -> V_28 -> V_39 -> V_40 = NULL ;
F_20 ( & V_37 ) ;
F_44 ( & V_49 ) ;
ASSERT ( F_45 ( & V_4 -> V_12 ) ) ;
ASSERT ( ! F_46 ( & V_4 -> V_8 ) ) ;
ASSERT ( ! F_46 ( & V_4 -> V_10 ) ) ;
F_47 ( & V_4 -> V_15 ) ;
F_47 ( & V_4 -> V_16 ) ;
F_21 ( V_4 -> V_28 , V_45 ) ;
F_22 ( V_4 -> V_28 ) ;
F_42 ( & V_49 ) ;
F_33 ( L_19 , V_4 -> V_20 ) ;
F_32 ( V_4 ) ;
if ( F_45 ( & V_38 ) )
F_48 ( & V_56 ) ;
F_11 ( L_17 ) ;
}
void T_1 F_49 ( void )
{
F_50 ( V_57 , V_58 ) ;
F_13 ( L_17 ) ;
if ( ! F_45 ( & V_38 ) ) {
F_51 ( V_59 ) ;
F_52 ( & V_56 , & V_57 ) ;
while ( ! F_45 ( & V_38 ) ) {
F_53 () ;
F_51 ( V_59 ) ;
}
F_54 ( & V_56 , & V_57 ) ;
F_51 ( V_60 ) ;
}
F_11 ( L_17 ) ;
}
