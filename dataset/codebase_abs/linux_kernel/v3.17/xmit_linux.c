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
V_12 = ( V_15 > V_12 ) ? V_12 : V_15 ;
if ( V_14 )
F_4 ( V_2 -> V_9 , V_2 -> V_3 - V_2 -> V_11 , V_14 , V_12 ) ;
V_2 -> V_5 += V_12 ;
V_2 -> V_11 -= V_12 ;
return V_12 ;
}
int F_5 ( struct V_1 * V_2 )
{
if ( V_2 -> V_11 == 0 ) {
return true ;
}
return false ;
}
int F_6 ( struct V_16 * V_17 , struct V_18 * V_19 , T_3 V_20 )
{
int V_21 ;
V_19 -> V_22 = F_7 ( V_20 , V_23 ) ;
if ( V_19 -> V_22 == NULL )
return V_24 ;
V_19 -> V_25 = ( T_2 * ) F_8 ( ( V_4 ) ( V_19 -> V_22 ) , V_26 ) ;
V_19 -> V_27 = 0 ;
for ( V_21 = 0 ; V_21 < 8 ; V_21 ++ ) {
V_19 -> V_28 [ V_21 ] = F_9 ( 0 , V_23 ) ;
if ( V_19 -> V_28 [ V_21 ] == NULL ) {
F_10 ( L_1 ) ;
return V_24 ;
}
}
return V_29 ;
}
void F_11 ( struct V_16 * V_17 ,
struct V_18 * V_19 , T_3 V_30 )
{
int V_21 ;
for ( V_21 = 0 ; V_21 < 8 ; V_21 ++ )
F_12 ( V_19 -> V_28 [ V_21 ] ) ;
F_13 ( V_19 -> V_22 ) ;
}
void F_14 ( struct V_16 * V_17 , struct V_7 * V_9 )
{
T_4 V_31 ;
struct V_32 * V_33 = & V_17 -> V_34 ;
V_31 = F_15 ( V_9 ) ;
if ( V_17 -> V_35 . V_36 ) {
if ( F_16 ( V_17 -> V_37 , V_31 ) &&
( V_33 -> V_38 [ V_31 ] . V_39 < V_40 ) )
F_17 ( V_17 -> V_37 , V_31 ) ;
} else {
if ( F_16 ( V_17 -> V_37 , V_31 ) )
F_17 ( V_17 -> V_37 , V_31 ) ;
}
F_18 ( V_9 ) ;
}
void F_19 ( struct V_16 * V_17 , struct V_41 * V_42 )
{
if ( V_42 -> V_9 )
F_14 ( V_17 , V_42 -> V_9 ) ;
V_42 -> V_9 = NULL ;
}
void F_20 ( struct V_16 * V_17 )
{
struct V_32 * V_33 ;
if ( ! V_17 )
return;
V_33 = & V_17 -> V_34 ;
F_21 ( & V_33 -> V_43 ) ;
if ( F_22 ( V_17 ) )
F_23 ( & V_33 -> V_44 ) ;
F_24 ( & V_33 -> V_43 ) ;
}
static void F_25 ( struct V_16 * V_17 , struct V_7 * V_9 )
{
struct V_32 * V_33 = & V_17 -> V_34 ;
T_4 V_31 ;
V_31 = F_15 ( V_9 ) ;
if ( V_17 -> V_35 . V_36 ) {
if ( V_33 -> V_38 [ V_31 ] . V_39 > V_40 )
F_26 ( V_17 -> V_37 , V_31 ) ;
} else {
if ( V_33 -> V_45 <= 4 ) {
if ( ! F_27 ( F_28 ( V_17 -> V_37 , V_31 ) ) )
F_26 ( V_17 -> V_37 , V_31 ) ;
}
}
}
static int F_29 ( struct V_16 * V_17 , struct V_7 * V_46 )
{
struct V_47 * V_48 = & V_17 -> V_49 ;
struct V_32 * V_33 = & V_17 -> V_34 ;
struct V_50 * V_51 , * V_52 ;
struct V_7 * V_53 ;
struct V_54 * V_55 = NULL ;
T_5 V_56 ;
F_21 ( & V_48 -> V_57 ) ;
V_51 = & V_48 -> V_58 ;
V_52 = V_51 -> V_59 ;
while ( V_51 != V_52 ) {
V_55 = F_30 ( V_52 , struct V_54 , V_58 ) ;
V_52 = V_52 -> V_59 ;
if ( ! memcmp ( V_55 -> V_60 , & V_46 -> V_10 [ 6 ] , 6 ) )
continue;
V_53 = F_31 ( V_46 , V_61 ) ;
if ( V_53 ) {
memcpy ( V_53 -> V_10 , V_55 -> V_60 , 6 ) ;
V_56 = F_32 ( V_17 , & V_53 ) ;
if ( V_56 < 0 ) {
F_10 ( L_2 , V_62 , __LINE__ ) ;
V_33 -> V_63 ++ ;
F_18 ( V_53 ) ;
} else {
V_33 -> V_64 ++ ;
}
} else {
F_10 ( L_3 , V_62 , __LINE__ ) ;
V_33 -> V_63 ++ ;
F_24 ( & V_48 -> V_57 ) ;
return false ;
}
}
F_24 ( & V_48 -> V_57 ) ;
F_18 ( V_46 ) ;
return true ;
}
int F_33 ( struct V_7 * V_9 , struct V_65 * V_37 )
{
struct V_16 * V_17 = (struct V_16 * ) F_34 ( V_37 ) ;
struct V_32 * V_33 = & V_17 -> V_34 ;
struct V_66 * V_67 = & V_17 -> V_68 ;
T_5 V_56 = 0 ;
F_35 ( V_69 , V_70 , ( L_4 ) ) ;
if ( F_36 ( V_17 ) == false ) {
F_35 ( V_71 , V_72 , ( L_5 ) ) ;
goto V_73;
}
F_25 ( V_17 , V_9 ) ;
if ( ! V_74 && F_37 ( V_67 , V_75 ) &&
( F_38 ( V_9 -> V_10 ) || F_39 ( V_9 -> V_10 ) ) &&
( V_17 -> V_35 . V_36 == 0 ) ) {
if ( V_33 -> V_45 > ( V_76 / 4 ) ) {
V_56 = F_29 ( V_17 , V_9 ) ;
if ( V_56 )
goto exit;
}
}
V_56 = F_32 ( V_17 , & V_9 ) ;
if ( V_56 < 0 )
goto V_73;
V_33 -> V_64 ++ ;
F_35 ( V_71 , V_70 , ( L_6 , ( T_3 ) V_33 -> V_64 ) ) ;
goto exit;
V_73:
V_33 -> V_63 ++ ;
F_18 ( V_9 ) ;
F_35 ( V_71 , V_77 , ( L_7 , ( T_3 ) V_33 -> V_63 ) ) ;
exit:
return 0 ;
}
