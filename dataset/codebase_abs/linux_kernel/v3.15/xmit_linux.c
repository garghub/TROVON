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
void F_6 ( struct V_7 * V_9 , struct V_16 * V_17 )
{
}
int F_7 ( struct V_18 * V_19 , struct V_20 * V_21 , T_3 V_22 )
{
int V_23 ;
V_21 -> V_24 = F_8 ( V_22 ) ;
if ( V_21 -> V_24 == NULL )
return V_25 ;
V_21 -> V_26 = ( T_2 * ) F_9 ( ( V_4 ) ( V_21 -> V_24 ) , V_27 ) ;
V_21 -> V_28 = 0 ;
for ( V_23 = 0 ; V_23 < 8 ; V_23 ++ ) {
V_21 -> V_29 [ V_23 ] = F_10 ( 0 , V_30 ) ;
if ( V_21 -> V_29 [ V_23 ] == NULL ) {
F_11 ( L_1 ) ;
return V_25 ;
}
}
return V_31 ;
}
void F_12 ( struct V_18 * V_19 ,
struct V_20 * V_21 , T_3 V_32 )
{
int V_23 ;
for ( V_23 = 0 ; V_23 < 8 ; V_23 ++ )
F_13 ( V_21 -> V_29 [ V_23 ] ) ;
F_14 ( V_21 -> V_24 ) ;
}
void F_15 ( struct V_18 * V_19 , struct V_7 * V_9 )
{
#if ( V_33 >= F_16 ( 2 , 6 , 35 ) )
T_4 V_34 ;
struct V_35 * V_36 = & V_19 -> V_37 ;
V_34 = F_17 ( V_9 ) ;
if ( V_19 -> V_38 . V_39 ) {
if ( F_18 ( V_19 -> V_40 , V_34 ) &&
( V_36 -> V_41 [ V_34 ] . V_42 < V_43 ) )
F_19 ( V_19 -> V_40 , V_34 ) ;
} else {
if ( F_18 ( V_19 -> V_40 , V_34 ) )
F_19 ( V_19 -> V_40 , V_34 ) ;
}
#else
if ( F_20 ( V_19 -> V_40 ) )
F_21 ( V_19 -> V_40 ) ;
#endif
F_22 ( V_9 ) ;
}
void F_23 ( struct V_18 * V_19 , struct V_44 * V_45 )
{
if ( V_45 -> V_9 )
F_15 ( V_19 , V_45 -> V_9 ) ;
V_45 -> V_9 = NULL ;
}
void F_24 ( struct V_18 * V_19 )
{
struct V_35 * V_36 ;
if ( ! V_19 )
return;
V_36 = & V_19 -> V_37 ;
F_25 ( & V_36 -> V_46 ) ;
if ( F_26 ( V_19 ) )
F_27 ( & V_36 -> V_47 ) ;
F_28 ( & V_36 -> V_46 ) ;
}
static void F_29 ( struct V_18 * V_19 , struct V_7 * V_9 )
{
struct V_35 * V_36 = & V_19 -> V_37 ;
T_4 V_34 ;
V_34 = F_17 ( V_9 ) ;
if ( V_19 -> V_38 . V_39 ) {
if ( V_36 -> V_41 [ V_34 ] . V_42 > V_43 )
F_30 ( V_19 -> V_40 , V_34 ) ;
} else {
if ( V_36 -> V_48 <= 4 ) {
if ( ! F_31 ( F_32 ( V_19 -> V_40 , V_34 ) ) )
F_30 ( V_19 -> V_40 , V_34 ) ;
}
}
}
static int F_33 ( struct V_18 * V_19 , struct V_7 * V_49 )
{
struct V_50 * V_51 = & V_19 -> V_52 ;
struct V_35 * V_36 = & V_19 -> V_37 ;
struct V_53 * V_54 , * V_55 ;
struct V_7 * V_56 ;
struct V_57 * V_58 = NULL ;
T_5 V_59 ;
F_25 ( & V_51 -> V_60 ) ;
V_54 = & V_51 -> V_61 ;
V_55 = V_54 -> V_62 ;
while ( ! F_34 ( V_54 , V_55 ) ) {
V_58 = F_35 ( V_55 , struct V_57 , V_61 ) ;
V_55 = V_55 -> V_62 ;
if ( ! memcmp ( V_58 -> V_63 , & V_49 -> V_10 [ 6 ] , 6 ) )
continue;
V_56 = F_36 ( V_49 , V_64 ) ;
if ( V_56 ) {
memcpy ( V_56 -> V_10 , V_58 -> V_63 , 6 ) ;
V_59 = F_37 ( V_19 , & V_56 ) ;
if ( V_59 < 0 ) {
F_11 ( L_2 , V_65 , __LINE__ ) ;
V_36 -> V_66 ++ ;
F_22 ( V_56 ) ;
} else {
V_36 -> V_67 ++ ;
}
} else {
F_11 ( L_3 , V_65 , __LINE__ ) ;
V_36 -> V_66 ++ ;
F_28 ( & V_51 -> V_60 ) ;
return false ;
}
}
F_28 ( & V_51 -> V_60 ) ;
F_22 ( V_49 ) ;
return true ;
}
int F_38 ( struct V_7 * V_9 , struct V_68 * V_40 )
{
struct V_18 * V_19 = (struct V_18 * ) F_39 ( V_40 ) ;
struct V_35 * V_36 = & V_19 -> V_37 ;
struct V_69 * V_70 = & V_19 -> V_71 ;
T_5 V_59 = 0 ;
F_40 ( V_72 , V_73 , ( L_4 ) ) ;
if ( F_41 ( V_19 ) == false ) {
F_40 ( V_74 , V_75 , ( L_5 ) ) ;
goto V_76;
}
F_29 ( V_19 , V_9 ) ;
if ( ! V_77 && F_42 ( V_70 , V_78 ) &&
( F_43 ( V_9 -> V_10 ) || F_44 ( V_9 -> V_10 ) ) &&
( V_19 -> V_38 . V_39 == 0 ) ) {
if ( V_36 -> V_48 > ( V_79 / 4 ) ) {
V_59 = F_33 ( V_19 , V_9 ) ;
if ( V_59 )
goto exit;
}
}
V_59 = F_37 ( V_19 , & V_9 ) ;
if ( V_59 < 0 )
goto V_76;
V_36 -> V_67 ++ ;
F_40 ( V_74 , V_73 , ( L_6 , ( T_3 ) V_36 -> V_67 ) ) ;
goto exit;
V_76:
V_36 -> V_66 ++ ;
F_22 ( V_9 ) ;
F_40 ( V_74 , V_80 , ( L_7 , ( T_3 ) V_36 -> V_66 ) ) ;
exit:
return 0 ;
}
