static void
F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
T_1 * V_5 ;
T_2 V_6 , V_7 ;
unsigned long V_8 ;
F_2 ( V_2 , F_3 ( V_9 L_1 ,
V_2 -> V_10 , V_11 ) ) ;
V_6 = F_4 ( T_1 , V_12 ) +
sizeof( struct V_3 ) + 4 ;
V_5 = F_5 ( V_6 , V_13 ) ;
if ( ! V_5 )
goto V_14;
V_5 -> V_15 = F_6 ( V_16 ) ;
V_7 = ( sizeof( struct V_3 ) + 4 ) / 4 ;
V_5 -> V_17 = F_6 ( V_7 ) ;
memcpy ( & V_5 -> V_12 , V_4 ,
sizeof( struct V_3 ) ) ;
F_2 ( V_2 , F_3 ( V_9
L_2 ,
V_2 -> V_10 , V_11 ) ) ;
F_7 ( V_2 , V_5 ) ;
F_8 ( V_5 ) ;
V_14:
F_9 ( & V_2 -> V_18 , V_8 ) ;
F_2 ( V_2 , F_3 ( V_9
L_3 ,
V_2 -> V_10 , V_11 ) ) ;
V_2 -> V_19 = 0 ;
F_10 ( & V_2 -> V_18 , V_8 ) ;
F_2 ( V_2 , F_3 ( V_9 L_4 , V_2 -> V_10 ,
V_11 ) ) ;
}
void
F_11 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
T_3 V_20 = 0 ;
F_2 ( V_2 , F_3 ( V_9 L_1 ,
V_2 -> V_10 , V_11 ) ) ;
if ( ( V_2 -> V_21 [ V_22 ] &
V_23 ) == 0 ) {
F_2 ( V_2 , F_3 ( V_9
L_5 , V_2 -> V_10 , V_11 ) ) ;
F_12 ( V_2 , V_22 ,
& V_20 ) ;
}
F_1 ( V_2 , V_4 ) ;
F_2 ( V_2 , F_3 ( V_9 L_4 , V_2 -> V_10 ,
V_11 ) ) ;
}
void
F_13 ( struct V_1 * V_2 , T_4 V_24 )
{
struct V_3 V_4 ;
unsigned long V_8 ;
T_3 V_25 = 0 ;
F_9 ( & V_2 -> V_18 , V_8 ) ;
if ( V_24 & V_26 ||
V_24 & V_27 )
goto V_28;
if ( ( V_2 -> V_21 [ V_22 ] &
V_29 ) == 0 ) {
F_10 ( & V_2 -> V_18 , V_8 ) ;
return;
}
if ( V_2 -> V_21 [ V_22 ] &
V_23 ) {
F_10 ( & V_2 -> V_18 , V_8 ) ;
return;
}
V_28:
F_2 ( V_2 , F_3 ( V_9
L_6 ,
V_2 -> V_10 , V_11 , V_24 ) ) ;
if ( V_2 -> V_19 ) {
F_10 ( & V_2 -> V_18 , V_8 ) ;
goto V_14;
}
if ( V_2 -> V_30 . V_31 & V_24 ) {
V_25 = 1 ;
V_2 -> V_19 = 1 ;
F_2 ( V_2 , F_3 ( V_9
L_7 ,
V_2 -> V_10 , V_11 ) ) ;
}
F_10 ( & V_2 -> V_18 , V_8 ) ;
if ( ! V_25 )
goto V_14;
memset ( & V_4 , 0 , sizeof( struct V_3 ) ) ;
V_4 . V_32 = V_33 ;
V_4 . V_34 . V_35 . V_31 = V_24 ;
if ( V_24 & V_26 ||
V_24 & V_27 )
F_1 ( V_2 , & V_4 ) ;
else
F_14 ( V_2 , & V_4 ) ;
V_14:
F_2 ( V_2 , F_3 ( V_9 L_4 , V_2 -> V_10 ,
V_11 ) ) ;
}
void
F_15 ( struct V_1 * V_2 , T_2 V_36 ,
T_2 V_37 )
{
struct V_3 V_4 ;
struct V_38 * V_39 ;
int V_40 ;
unsigned long V_8 ;
T_3 V_25 ;
F_9 ( & V_2 -> V_18 , V_8 ) ;
if ( ( V_2 -> V_21 [ V_22 ] &
V_29 ) == 0 ) {
F_10 ( & V_2 -> V_18 , V_8 ) ;
return;
}
if ( V_2 -> V_21 [ V_22 ] &
V_23 ) {
F_10 ( & V_2 -> V_18 , V_8 ) ;
return;
}
F_2 ( V_2 , F_3 ( V_9
L_8 ,
V_2 -> V_10 , V_11 , V_36 , V_37 ) ) ;
if ( V_2 -> V_19 ) {
F_10 ( & V_2 -> V_18 , V_8 ) ;
goto V_14;
}
V_39 = V_2 -> V_41 . V_42 ;
for ( V_40 = 0 , V_25 = 0 ; V_40 < V_2 -> V_41 . V_43
&& ! V_25 ; V_40 ++ , V_39 ++ ) {
if ( V_39 -> V_44 != V_36 )
continue;
if ( V_36 == V_45 ) {
if ( V_39 -> V_46 ==
V_37 )
V_25 = 1 ;
continue;
}
V_25 = 1 ;
V_2 -> V_19 = 1 ;
F_2 ( V_2 , F_3 ( V_9
L_7 ,
V_2 -> V_10 , V_11 ) ) ;
}
F_10 ( & V_2 -> V_18 , V_8 ) ;
if ( ! V_25 )
goto V_14;
F_2 ( V_2 , F_3 ( V_9
L_7 ,
V_2 -> V_10 , V_11 ) ) ;
memset ( & V_4 , 0 , sizeof( struct V_3 ) ) ;
V_4 . V_32 = V_47 ;
V_4 . V_34 . V_36 . V_44 = V_36 ;
V_4 . V_34 . V_36 . V_46 = V_37 ;
F_14 ( V_2 , & V_4 ) ;
V_14:
F_2 ( V_2 , F_3 ( V_9 L_4 , V_2 -> V_10 ,
V_11 ) ) ;
}
void
F_16 ( struct V_1 * V_2 , T_3 V_48 , T_3 V_49 ,
T_3 V_50 )
{
struct V_3 V_4 ;
struct V_51 * V_52 ;
int V_40 ;
unsigned long V_8 ;
T_3 V_25 ;
F_9 ( & V_2 -> V_18 , V_8 ) ;
if ( ( V_2 -> V_21 [ V_22 ] &
V_29 ) == 0 ) {
F_10 ( & V_2 -> V_18 , V_8 ) ;
return;
}
if ( V_2 -> V_21 [ V_22 ] &
V_23 ) {
F_10 ( & V_2 -> V_18 , V_8 ) ;
return;
}
F_2 ( V_2 , F_3 ( V_9
L_9 ,
V_2 -> V_10 , V_11 , V_48 , V_49 , V_50 ) ) ;
if ( V_2 -> V_19 ) {
F_10 ( & V_2 -> V_18 , V_8 ) ;
goto V_14;
}
V_52 = V_2 -> V_53 . V_54 ;
for ( V_40 = 0 , V_25 = 0 ; V_40 < V_2 -> V_53 . V_43
&& ! V_25 ; V_40 ++ , V_52 ++ ) {
if ( V_52 -> V_55 != V_48 )
continue;
if ( ! ( V_52 -> V_56 == 0xFF || V_52 -> V_56 == V_49 ) )
continue;
if ( ! ( V_52 -> V_57 == 0xFF || V_52 -> V_57 == V_50 ) )
continue;
V_25 = 1 ;
V_2 -> V_19 = 1 ;
}
F_10 ( & V_2 -> V_18 , V_8 ) ;
if ( ! V_25 )
goto V_14;
F_2 ( V_2 , F_3 ( V_9
L_7 ,
V_2 -> V_10 , V_11 ) ) ;
memset ( & V_4 , 0 , sizeof( struct V_3 ) ) ;
V_4 . V_32 = V_58 ;
V_4 . V_34 . V_59 . V_55 = V_48 ;
V_4 . V_34 . V_59 . V_56 = V_49 ;
V_4 . V_34 . V_59 . V_57 = V_50 ;
F_14 ( V_2 , & V_4 ) ;
V_14:
F_2 ( V_2 , F_3 ( V_9 L_4 , V_2 -> V_10 ,
V_11 ) ) ;
}
void
F_17 ( struct V_1 * V_2 , T_2 V_60 , T_4 V_61 )
{
struct V_3 V_4 ;
struct V_62 * V_63 ;
int V_40 ;
unsigned long V_8 ;
T_3 V_25 ;
F_9 ( & V_2 -> V_18 , V_8 ) ;
if ( ( V_2 -> V_21 [ V_22 ] &
V_29 ) == 0 ) {
F_10 ( & V_2 -> V_18 , V_8 ) ;
return;
}
if ( V_2 -> V_21 [ V_22 ] &
V_23 ) {
F_10 ( & V_2 -> V_18 , V_8 ) ;
return;
}
F_2 ( V_2 , F_3 ( V_9
L_10 ,
V_2 -> V_10 , V_11 , V_60 , V_61 ) ) ;
if ( V_2 -> V_19 ) {
F_10 ( & V_2 -> V_18 , V_8 ) ;
goto V_14;
}
V_63 = V_2 -> V_64 . V_65 ;
for ( V_40 = 0 , V_25 = 0 ; V_40 < V_2 -> V_64 . V_43
&& ! V_25 ; V_40 ++ , V_63 ++ ) {
if ( V_63 -> V_66 != V_60 )
continue;
if ( ! ( V_63 -> V_67 == 0xFFFFFFFF ||
V_63 -> V_67 == V_61 ) )
continue;
V_25 = 1 ;
V_2 -> V_19 = 1 ;
}
F_10 ( & V_2 -> V_18 , V_8 ) ;
if ( ! V_25 )
goto V_14;
F_2 ( V_2 , F_3 ( V_9
L_7 ,
V_2 -> V_10 , V_11 ) ) ;
memset ( & V_4 , 0 , sizeof( struct V_3 ) ) ;
V_4 . V_32 = V_68 ;
V_4 . V_34 . V_69 . V_66 = V_60 ;
V_4 . V_34 . V_69 . V_67 = V_61 ;
F_14 ( V_2 , & V_4 ) ;
V_14:
F_2 ( V_2 , F_3 ( V_9 L_4 , V_2 -> V_10 ,
V_11 ) ) ;
}
