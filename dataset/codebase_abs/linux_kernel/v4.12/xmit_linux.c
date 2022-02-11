T_1 F_1 ( struct V_1 * V_2 )
{
return V_2 -> V_3 - ( ( V_4 ) ( V_2 -> V_5 ) -
( V_4 ) ( V_2 -> V_6 ) ) ;
}
void F_2 ( struct V_7 * V_8 , struct V_1 * V_2 )
{
V_2 -> V_9 = V_8 ;
V_2 -> V_5 = V_8 -> V_10 ;
V_2 -> V_6 = V_8 -> V_10 ;
V_2 -> V_11 = V_8 -> V_12 ;
V_2 -> V_3 = V_8 -> V_12 ;
V_2 -> V_13 = V_2 -> V_6 ;
}
T_1 F_3 ( struct V_1 * V_2 , T_2 * V_14 , T_1 V_15 )
{
T_1 V_12 = 0 ;
V_12 = F_1 ( V_2 ) ;
V_12 = F_4 ( V_15 , V_12 ) ;
if ( V_14 )
F_5 ( V_2 -> V_9 , V_2 -> V_3 - V_2 -> V_11 , V_14 , V_12 ) ;
V_2 -> V_5 += V_12 ;
V_2 -> V_11 -= V_12 ;
return V_12 ;
}
int F_6 ( struct V_16 * V_17 , struct V_18 * V_19 , T_3 V_20 )
{
int V_21 ;
V_19 -> V_22 = F_7 ( V_20 , V_23 ) ;
if ( V_19 -> V_22 == NULL )
return V_24 ;
V_19 -> V_25 = F_8 ( V_19 -> V_22 , V_26 ) ;
V_19 -> V_27 = 0 ;
for ( V_21 = 0 ; V_21 < 8 ; V_21 ++ ) {
V_19 -> V_28 [ V_21 ] = F_9 ( 0 , V_23 ) ;
if ( ! V_19 -> V_28 [ V_21 ] ) {
F_10 ( L_1 ) ;
return V_24 ;
}
}
return V_29 ;
}
void F_11 ( struct V_18 * V_19 )
{
int V_21 ;
for ( V_21 = 0 ; V_21 < 8 ; V_21 ++ )
F_12 ( V_19 -> V_28 [ V_21 ] ) ;
F_13 ( V_19 -> V_22 ) ;
}
void F_14 ( struct V_16 * V_17 , struct V_7 * V_9 )
{
T_4 V_30 ;
struct V_31 * V_32 = & V_17 -> V_33 ;
V_30 = F_15 ( V_9 ) ;
if ( V_17 -> V_34 . V_35 ) {
if ( F_16 ( V_17 -> V_36 , V_30 ) &&
( V_32 -> V_37 [ V_30 ] . V_38 < V_39 ) )
F_17 ( V_17 -> V_36 , V_30 ) ;
} else {
if ( F_16 ( V_17 -> V_36 , V_30 ) )
F_17 ( V_17 -> V_36 , V_30 ) ;
}
F_18 ( V_9 ) ;
}
void F_19 ( struct V_16 * V_17 , struct V_40 * V_41 )
{
if ( V_41 -> V_9 )
F_14 ( V_17 , V_41 -> V_9 ) ;
V_41 -> V_9 = NULL ;
}
void F_20 ( struct V_16 * V_17 )
{
struct V_31 * V_32 ;
if ( ! V_17 )
return;
V_32 = & V_17 -> V_33 ;
F_21 ( & V_32 -> V_42 ) ;
if ( F_22 ( V_17 ) )
F_23 ( & V_32 -> V_43 ) ;
F_24 ( & V_32 -> V_42 ) ;
}
static void F_25 ( struct V_16 * V_17 , struct V_7 * V_9 )
{
struct V_31 * V_32 = & V_17 -> V_33 ;
T_4 V_30 ;
V_30 = F_15 ( V_9 ) ;
if ( V_17 -> V_34 . V_35 ) {
if ( V_32 -> V_37 [ V_30 ] . V_38 > V_39 )
F_26 ( V_17 -> V_36 , V_30 ) ;
} else {
if ( V_32 -> V_44 <= 4 ) {
if ( ! F_27 ( F_28 ( V_17 -> V_36 , V_30 ) ) )
F_26 ( V_17 -> V_36 , V_30 ) ;
}
}
}
static int F_29 ( struct V_16 * V_17 , struct V_7 * V_45 )
{
struct V_46 * V_47 = & V_17 -> V_48 ;
struct V_31 * V_32 = & V_17 -> V_33 ;
struct V_49 * V_50 , * V_51 ;
struct V_7 * V_52 ;
struct V_53 * V_54 = NULL ;
T_5 V_55 ;
F_21 ( & V_47 -> V_56 ) ;
V_50 = & V_47 -> V_57 ;
V_51 = V_50 -> V_58 ;
while ( V_50 != V_51 ) {
V_54 = F_30 ( V_51 , struct V_53 , V_57 ) ;
V_51 = V_51 -> V_58 ;
if ( ! memcmp ( V_54 -> V_59 , & V_45 -> V_10 [ 6 ] , 6 ) )
continue;
V_52 = F_31 ( V_45 , V_60 ) ;
if ( V_52 ) {
memcpy ( V_52 -> V_10 , V_54 -> V_59 , 6 ) ;
V_55 = F_32 ( V_17 , & V_52 ) ;
if ( V_55 < 0 ) {
F_10 ( L_2 , V_61 , __LINE__ ) ;
V_32 -> V_62 ++ ;
F_18 ( V_52 ) ;
} else {
V_32 -> V_63 ++ ;
}
} else {
F_10 ( L_3 , V_61 , __LINE__ ) ;
V_32 -> V_62 ++ ;
F_24 ( & V_47 -> V_56 ) ;
return false ;
}
}
F_24 ( & V_47 -> V_56 ) ;
F_18 ( V_45 ) ;
return true ;
}
int F_33 ( struct V_7 * V_9 , struct V_64 * V_36 )
{
struct V_16 * V_17 = (struct V_16 * ) F_34 ( V_36 ) ;
struct V_31 * V_32 = & V_17 -> V_33 ;
struct V_65 * V_66 = & V_17 -> V_67 ;
T_5 V_55 = 0 ;
F_35 ( V_68 , V_69 , ( L_4 ) ) ;
if ( F_36 ( V_17 ) == false ) {
F_35 ( V_70 , V_71 , ( L_5 ) ) ;
goto V_72;
}
F_25 ( V_17 , V_9 ) ;
if ( ! V_73 && F_37 ( V_66 , V_74 ) &&
( F_38 ( V_9 -> V_10 ) || F_39 ( V_9 -> V_10 ) ) &&
( V_17 -> V_34 . V_35 == 0 ) ) {
if ( V_32 -> V_44 > ( V_75 / 4 ) ) {
V_55 = F_29 ( V_17 , V_9 ) ;
if ( V_55 )
goto exit;
}
}
V_55 = F_32 ( V_17 , & V_9 ) ;
if ( V_55 < 0 )
goto V_72;
V_32 -> V_63 ++ ;
F_35 ( V_70 , V_69 , ( L_6 , ( T_3 ) V_32 -> V_63 ) ) ;
goto exit;
V_72:
V_32 -> V_62 ++ ;
F_18 ( V_9 ) ;
F_35 ( V_70 , V_76 , ( L_7 , ( T_3 ) V_32 -> V_62 ) ) ;
exit:
return 0 ;
}
