T_1 F_1 ( struct V_1 * V_2 )
{
return V_2 -> V_3 - ( ( V_4 ) ( V_2 -> V_5 ) -
( V_4 ) ( V_2 -> V_6 ) ) ;
}
void F_2 ( struct V_7 * V_8 , struct V_1 * V_2 )
{
V_9 ;
V_2 -> V_10 = V_8 ;
V_2 -> V_5 = V_8 -> V_11 ;
V_2 -> V_6 = V_8 -> V_11 ;
V_2 -> V_12 = V_8 -> V_13 ;
V_2 -> V_3 = V_8 -> V_13 ;
V_2 -> V_14 = V_2 -> V_6 ;
V_15 ;
}
T_1 F_3 ( struct V_1 * V_2 , T_2 * V_16 , T_1 V_17 )
{
T_1 V_13 = 0 ;
V_9 ;
V_13 = F_1 ( V_2 ) ;
V_13 = ( V_17 > V_13 ) ? V_13 : V_17 ;
if ( V_16 )
F_4 ( V_2 -> V_10 , V_2 -> V_3 - V_2 -> V_12 , V_16 , V_13 ) ;
V_2 -> V_5 += V_13 ;
V_2 -> V_12 -= V_13 ;
V_15 ;
return V_13 ;
}
int F_5 ( struct V_1 * V_2 )
{
V_9 ;
if ( V_2 -> V_12 == 0 ) {
V_15 ;
return true ;
}
V_15 ;
return false ;
}
void F_6 ( struct V_7 * V_10 , struct V_18 * V_19 )
{
}
int F_7 ( struct V_20 * V_21 , struct V_22 * V_23 , T_3 V_24 )
{
int V_25 ;
V_23 -> V_26 = F_8 ( V_24 ) ;
if ( V_23 -> V_26 == NULL )
return V_27 ;
V_23 -> V_28 = ( T_2 * ) F_9 ( ( V_4 ) ( V_23 -> V_26 ) , V_29 ) ;
V_23 -> V_30 = 0 ;
for ( V_25 = 0 ; V_25 < 8 ; V_25 ++ ) {
V_23 -> V_31 [ V_25 ] = F_10 ( 0 , V_32 ) ;
if ( V_23 -> V_31 [ V_25 ] == NULL ) {
F_11 ( L_1 ) ;
return V_27 ;
}
}
return V_33 ;
}
void F_12 ( struct V_20 * V_21 ,
struct V_22 * V_23 , T_3 V_34 )
{
int V_25 ;
for ( V_25 = 0 ; V_25 < 8 ; V_25 ++ )
F_13 ( V_23 -> V_31 [ V_25 ] ) ;
F_14 ( V_23 -> V_26 ) ;
}
void F_15 ( struct V_20 * V_21 , struct V_7 * V_10 )
{
#if ( V_35 >= F_16 ( 2 , 6 , 35 ) )
T_4 V_36 ;
struct V_37 * V_38 = & V_21 -> V_39 ;
V_36 = F_17 ( V_10 ) ;
if ( V_21 -> V_40 . V_41 ) {
if ( F_18 ( V_21 -> V_42 , V_36 ) &&
( V_38 -> V_43 [ V_36 ] . V_44 < V_45 ) )
F_19 ( V_21 -> V_42 , V_36 ) ;
} else {
if ( F_18 ( V_21 -> V_42 , V_36 ) )
F_19 ( V_21 -> V_42 , V_36 ) ;
}
#else
if ( F_20 ( V_21 -> V_42 ) )
F_21 ( V_21 -> V_42 ) ;
#endif
F_22 ( V_10 ) ;
}
void F_23 ( struct V_20 * V_21 , struct V_46 * V_47 )
{
if ( V_47 -> V_10 )
F_15 ( V_21 , V_47 -> V_10 ) ;
V_47 -> V_10 = NULL ;
}
void F_24 ( struct V_20 * V_21 )
{
struct V_37 * V_38 ;
if ( ! V_21 )
return;
V_38 = & V_21 -> V_39 ;
F_25 ( & V_38 -> V_48 ) ;
if ( F_26 ( V_21 ) )
F_27 ( & V_38 -> V_49 ) ;
F_28 ( & V_38 -> V_48 ) ;
}
static void F_29 ( struct V_20 * V_21 , struct V_7 * V_10 )
{
struct V_37 * V_38 = & V_21 -> V_39 ;
T_4 V_36 ;
V_36 = F_17 ( V_10 ) ;
if ( V_21 -> V_40 . V_41 ) {
if ( V_38 -> V_43 [ V_36 ] . V_44 > V_45 )
F_30 ( V_21 -> V_42 , V_36 ) ;
} else {
if ( V_38 -> V_50 <= 4 ) {
if ( ! F_31 ( F_32 ( V_21 -> V_42 , V_36 ) ) )
F_30 ( V_21 -> V_42 , V_36 ) ;
}
}
}
static int F_33 ( struct V_20 * V_21 , struct V_7 * V_51 )
{
struct V_52 * V_53 = & V_21 -> V_54 ;
struct V_37 * V_38 = & V_21 -> V_39 ;
struct V_55 * V_56 , * V_57 ;
struct V_7 * V_58 ;
struct V_59 * V_60 = NULL ;
T_5 V_61 ;
F_25 ( & V_53 -> V_62 ) ;
V_56 = & V_53 -> V_63 ;
V_57 = F_34 ( V_56 ) ;
while ( ! F_35 ( V_56 , V_57 ) ) {
V_60 = F_36 ( V_57 , struct V_59 , V_63 ) ;
V_57 = F_34 ( V_57 ) ;
if ( ! memcmp ( V_60 -> V_64 , & V_51 -> V_11 [ 6 ] , 6 ) )
continue;
V_58 = F_37 ( V_51 , V_65 ) ;
if ( V_58 ) {
memcpy ( V_58 -> V_11 , V_60 -> V_64 , 6 ) ;
V_61 = F_38 ( V_21 , & V_58 ) ;
if ( V_61 < 0 ) {
F_11 ( L_2 , V_66 , __LINE__ ) ;
V_38 -> V_67 ++ ;
F_22 ( V_58 ) ;
} else {
V_38 -> V_68 ++ ;
}
} else {
F_11 ( L_3 , V_66 , __LINE__ ) ;
V_38 -> V_67 ++ ;
F_28 ( & V_53 -> V_62 ) ;
return false ;
}
}
F_28 ( & V_53 -> V_62 ) ;
F_22 ( V_51 ) ;
return true ;
}
int F_39 ( struct V_7 * V_10 , struct V_69 * V_42 )
{
struct V_20 * V_21 = (struct V_20 * ) F_40 ( V_42 ) ;
struct V_37 * V_38 = & V_21 -> V_39 ;
struct V_70 * V_71 = & V_21 -> V_72 ;
T_5 V_61 = 0 ;
V_9 ;
F_41 ( V_73 , V_74 , ( L_4 ) ) ;
if ( F_42 ( V_21 ) == false ) {
F_41 ( V_75 , V_76 , ( L_5 ) ) ;
goto V_77;
}
F_29 ( V_21 , V_10 ) ;
if ( ! V_78 && F_43 ( V_71 , V_79 ) &&
( F_44 ( V_10 -> V_11 ) || F_45 ( V_10 -> V_11 ) ) &&
( V_21 -> V_40 . V_41 == 0 ) ) {
if ( V_38 -> V_50 > ( V_80 / 4 ) ) {
V_61 = F_33 ( V_21 , V_10 ) ;
if ( V_61 )
goto exit;
}
}
V_61 = F_38 ( V_21 , & V_10 ) ;
if ( V_61 < 0 )
goto V_77;
V_38 -> V_68 ++ ;
F_41 ( V_75 , V_74 , ( L_6 , ( T_3 ) V_38 -> V_68 ) ) ;
goto exit;
V_77:
V_38 -> V_67 ++ ;
F_22 ( V_10 ) ;
F_41 ( V_75 , V_81 , ( L_7 , ( T_3 ) V_38 -> V_67 ) ) ;
exit:
V_15 ;
return 0 ;
}
