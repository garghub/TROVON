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
int F_6 ( struct V_1 * V_2 )
{
return V_2 -> V_11 == 0 ;
}
int F_7 ( struct V_16 * V_17 , struct V_18 * V_19 , T_3 V_20 )
{
int V_21 ;
V_19 -> V_22 = F_8 ( V_20 , V_23 ) ;
if ( V_19 -> V_22 == NULL )
return V_24 ;
V_19 -> V_25 = ( T_2 * ) F_9 ( ( V_4 ) ( V_19 -> V_22 ) , V_26 ) ;
V_19 -> V_27 = 0 ;
for ( V_21 = 0 ; V_21 < 8 ; V_21 ++ ) {
V_19 -> V_28 [ V_21 ] = F_10 ( 0 , V_23 ) ;
if ( V_19 -> V_28 [ V_21 ] == NULL ) {
F_11 ( L_1 ) ;
return V_24 ;
}
}
return V_29 ;
}
void F_12 ( struct V_16 * V_17 ,
struct V_18 * V_19 , T_3 V_30 )
{
int V_21 ;
for ( V_21 = 0 ; V_21 < 8 ; V_21 ++ )
F_13 ( V_19 -> V_28 [ V_21 ] ) ;
F_14 ( V_19 -> V_22 ) ;
}
void F_15 ( struct V_16 * V_17 , struct V_7 * V_9 )
{
T_4 V_31 ;
struct V_32 * V_33 = & V_17 -> V_34 ;
V_31 = F_16 ( V_9 ) ;
if ( V_17 -> V_35 . V_36 ) {
if ( F_17 ( V_17 -> V_37 , V_31 ) &&
( V_33 -> V_38 [ V_31 ] . V_39 < V_40 ) )
F_18 ( V_17 -> V_37 , V_31 ) ;
} else {
if ( F_17 ( V_17 -> V_37 , V_31 ) )
F_18 ( V_17 -> V_37 , V_31 ) ;
}
F_19 ( V_9 ) ;
}
void F_20 ( struct V_16 * V_17 , struct V_41 * V_42 )
{
if ( V_42 -> V_9 )
F_15 ( V_17 , V_42 -> V_9 ) ;
V_42 -> V_9 = NULL ;
}
void F_21 ( struct V_16 * V_17 )
{
struct V_32 * V_33 ;
if ( ! V_17 )
return;
V_33 = & V_17 -> V_34 ;
F_22 ( & V_33 -> V_43 ) ;
if ( F_23 ( V_17 ) )
F_24 ( & V_33 -> V_44 ) ;
F_25 ( & V_33 -> V_43 ) ;
}
static void F_26 ( struct V_16 * V_17 , struct V_7 * V_9 )
{
struct V_32 * V_33 = & V_17 -> V_34 ;
T_4 V_31 ;
V_31 = F_16 ( V_9 ) ;
if ( V_17 -> V_35 . V_36 ) {
if ( V_33 -> V_38 [ V_31 ] . V_39 > V_40 )
F_27 ( V_17 -> V_37 , V_31 ) ;
} else {
if ( V_33 -> V_45 <= 4 ) {
if ( ! F_28 ( F_29 ( V_17 -> V_37 , V_31 ) ) )
F_27 ( V_17 -> V_37 , V_31 ) ;
}
}
}
static int F_30 ( struct V_16 * V_17 , struct V_7 * V_46 )
{
struct V_47 * V_48 = & V_17 -> V_49 ;
struct V_32 * V_33 = & V_17 -> V_34 ;
struct V_50 * V_51 , * V_52 ;
struct V_7 * V_53 ;
struct V_54 * V_55 = NULL ;
T_5 V_56 ;
F_22 ( & V_48 -> V_57 ) ;
V_51 = & V_48 -> V_58 ;
V_52 = V_51 -> V_59 ;
while ( V_51 != V_52 ) {
V_55 = F_31 ( V_52 , struct V_54 , V_58 ) ;
V_52 = V_52 -> V_59 ;
if ( ! memcmp ( V_55 -> V_60 , & V_46 -> V_10 [ 6 ] , 6 ) )
continue;
V_53 = F_32 ( V_46 , V_61 ) ;
if ( V_53 ) {
memcpy ( V_53 -> V_10 , V_55 -> V_60 , 6 ) ;
V_56 = F_33 ( V_17 , & V_53 ) ;
if ( V_56 < 0 ) {
F_11 ( L_2 , V_62 , __LINE__ ) ;
V_33 -> V_63 ++ ;
F_19 ( V_53 ) ;
} else {
V_33 -> V_64 ++ ;
}
} else {
F_11 ( L_3 , V_62 , __LINE__ ) ;
V_33 -> V_63 ++ ;
F_25 ( & V_48 -> V_57 ) ;
return false ;
}
}
F_25 ( & V_48 -> V_57 ) ;
F_19 ( V_46 ) ;
return true ;
}
int F_34 ( struct V_7 * V_9 , struct V_65 * V_37 )
{
struct V_16 * V_17 = (struct V_16 * ) F_35 ( V_37 ) ;
struct V_32 * V_33 = & V_17 -> V_34 ;
struct V_66 * V_67 = & V_17 -> V_68 ;
T_5 V_56 = 0 ;
F_36 ( V_69 , V_70 , ( L_4 ) ) ;
if ( F_37 ( V_17 ) == false ) {
F_36 ( V_71 , V_72 , ( L_5 ) ) ;
goto V_73;
}
F_26 ( V_17 , V_9 ) ;
if ( ! V_74 && F_38 ( V_67 , V_75 ) &&
( F_39 ( V_9 -> V_10 ) || F_40 ( V_9 -> V_10 ) ) &&
( V_17 -> V_35 . V_36 == 0 ) ) {
if ( V_33 -> V_45 > ( V_76 / 4 ) ) {
V_56 = F_30 ( V_17 , V_9 ) ;
if ( V_56 )
goto exit;
}
}
V_56 = F_33 ( V_17 , & V_9 ) ;
if ( V_56 < 0 )
goto V_73;
V_33 -> V_64 ++ ;
F_36 ( V_71 , V_70 , ( L_6 , ( T_3 ) V_33 -> V_64 ) ) ;
goto exit;
V_73:
V_33 -> V_63 ++ ;
F_19 ( V_9 ) ;
F_36 ( V_71 , V_77 , ( L_7 , ( T_3 ) V_33 -> V_63 ) ) ;
exit:
return 0 ;
}
